// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/expressiontool.cpp
// Functions: 115
// ============================================================

#include "utils\hlfaceposer\expressiontool.h"

//------------------------------------------------------------------------------
// Address: 0x0044A4B0
// Name: public: int CChoreoEvent::GetGlobalID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoEvent::GetGlobalID(CChoreoEvent *this)
{
  return this->m_nGlobalID;
}

//------------------------------------------------------------------------------
// Address: 0x0044A4C0
// Name: int SortFuncByUse(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortFuncByUse(TimelineItem **elem1, TimelineItem **elem2)
{
  TimelineItem *v2; // esi
  TimelineItem *v3; // edi
  bool IsValid; // bl

  v2 = *elem2;
  v3 = *elem1;
  IsValid = TimelineItem::IsValid(this: *elem2);
  if ( TimelineItem::IsValid(this: v3) == IsValid )
    return 0;
  if ( TimelineItem::IsValid(this: v2) || !TimelineItem::IsValid(this: v3) )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0044A520
// Name: int SortFuncByName(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortFuncByName(TimelineItem **elem1, TimelineItem **elem2)
{
  TimelineItem *v2; // edi
  CFlexAnimationTrack *SafeTrack; // esi
  CFlexAnimationTrack *v4; // eax
  const char *v5; // eax
  const char *FlexControllerName; // [esp-4h] [ebp-Ch]

  v2 = *elem2;
  SafeTrack = TimelineItem::GetSafeTrack(this: *elem1);
  v4 = TimelineItem::GetSafeTrack(this: v2);
  if ( SafeTrack == nullptr )
    return v4 != nullptr;
  if ( v4 == nullptr )
    return -1;
  FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: v4);
  v5 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
  return _V_stricmp(s1: v5, s2: FlexControllerName);
}

//------------------------------------------------------------------------------
// Address: 0x0044A580
// Name: private: void CExpressionToolWorkspace::MouseToToolMouse(int __near &,int __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::MouseToToolMouse(
        CExpressionToolWorkspace *this,
        int *mx,
        int *my,
        char *reason)
{
  int v4; // eax
  HWND Handle; // eax
  mxWindow *Parent; // eax
  HWND v8; // eax
  tagPOINT pt; // [esp+Ch] [ebp-8h] BYREF

  v4 = *mx;
  pt.y = *my;
  pt.x = v4;
  Handle = (HWND)mxWidget::getHandle(this);
  ClientToScreen(hWnd: Handle, lpPoint: &pt);
  Parent = mxWidget::getParent(this);
  v8 = (HWND)mxWidget::getHandle(this: Parent);
  ScreenToClient(hWnd: v8, lpPoint: &pt);
  *(tagPOINT *)mx = pt;
}

//------------------------------------------------------------------------------
// Address: 0x0044A5E0
// Name: public: class TimelineItem __near * CExpressionToolWorkspace::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
TimelineItem *__thiscall CExpressionToolWorkspace::GetItem(CExpressionToolWorkspace *this, unsigned int number)
{
  if ( number > 0x17F )
    return nullptr;
  else
    return this->m_pItems[number];
}

//------------------------------------------------------------------------------
// Address: 0x0044A600
// Name: public: class TimelineItem __near * CExpressionToolWorkspace::GetClickedItem(void)
// Source: json
//------------------------------------------------------------------------------
TimelineItem *__thiscall CExpressionToolWorkspace::GetClickedItem(CExpressionToolWorkspace *this)
{
  unsigned int m_nFocusItem; // eax

  m_nFocusItem = this->m_nFocusItem;
  if ( m_nFocusItem > 0x17F )
    return nullptr;
  else
    return this->m_pItems[m_nFocusItem];
}

//------------------------------------------------------------------------------
// Address: 0x0044A620
// Name: public: int CExpressionToolWorkspace::ComputeVPixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionToolWorkspace::ComputeVPixelsNeeded(CExpressionToolWorkspace *this)
{
  int v1; // esi
  TimelineItem **m_pItems; // ebx
  TimelineItem *v3; // edi
  int c; // [esp+10h] [ebp-4h]

  v1 = 0;
  c = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v1 <= 0x17F )
    {
      v3 = *m_pItems;
      if ( *m_pItems != nullptr && TimelineItem::GetVisible(this: *m_pItems) )
        c += this->m_nItemGap + TimelineItem::GetHeight(this: v3);
    }
    ++v1;
    ++m_pItems;
  }
  while ( v1 < 384 );
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x0044A680
// Name: public: void CExpressionToolWorkspace::RepositionVSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::RepositionVSlider(CExpressionToolWorkspace *this)
{
  int v2; // edi
  int v3; // eax
  mxScrollbar *m_pVertScrollBar; // ecx
  int v5; // eax
  int v6; // eax
  mxScrollbar *v7; // ecx
  int v8; // eax
  int m_nScrollbarHeight; // [esp-8h] [ebp-10h]
  int v10; // [esp-4h] [ebp-Ch]

  v2 = CExpressionToolWorkspace::ComputeVPixelsNeeded(this);
  v3 = mxWidget::h2(this);
  m_pVertScrollBar = this->m_pVertScrollBar;
  if ( v2 > v3 )
  {
    mxWidget::setVisible(this: m_pVertScrollBar, b: true);
  }
  else
  {
    mxWidget::setVisible(this: m_pVertScrollBar, b: false);
    this->m_nTopOffset = 0;
  }
  v10 = mxWidget::h2(this);
  m_nScrollbarHeight = this->m_nScrollbarHeight;
  v5 = mxWidget::w2(this);
  mxWidget::setBounds(
    this: this->m_pVertScrollBar,
    x: v5 - this->m_nScrollbarHeight,
    y: 0,
    w: m_nScrollbarHeight,
    h: v10);
  v6 = this->m_nTopOffset < 0 ? 0 : this->m_nTopOffset;
  this->m_nTopOffset = v6;
  if ( v2 < v6 )
    v6 = v2;
  v7 = this->m_pVertScrollBar;
  this->m_nTopOffset = v6;
  mxScrollbar::setRange(this: v7, min: 0, max: v2);
  mxScrollbar::setValue(this: this->m_pVertScrollBar, ivalue: this->m_nTopOffset);
  v8 = mxWidget::h2(this);
  mxScrollbar::setPagesize(this: this->m_pVertScrollBar, size: v8);
  this->m_nLastVPixelsNeeded = v2;
}

//------------------------------------------------------------------------------
// Address: 0x0044A740
// Name: public: void CExpressionToolWorkspace::OnSnapAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::OnSnapAll(CExpressionToolWorkspace *this)
{
  int v2; // esi
  TimelineItem **m_pItems; // edi
  TimelineItem *v4; // ecx

  CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
  CChoreoView::PushUndo(this: g_pChoreoView, description: "Snap All");
  v2 = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v2 > 0x17F )
      v4 = nullptr;
    else
      v4 = *m_pItems;
    TimelineItem::SnapAll(this: v4);
    ++v2;
    ++m_pItems;
  }
  while ( v2 < 384 );
  CChoreoView::PushRedo(this: g_pChoreoView, description: "Snap All");
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044A7B0
// Name: public: int CExpressionToolWorkspace::CountSelectedSamples(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionToolWorkspace::CountSelectedSamples(CExpressionToolWorkspace *this)
{
  int v1; // edi
  TimelineItem **m_pItems; // ebx
  TimelineItem *v3; // esi
  int c; // [esp+Ch] [ebp-4h]

  v1 = 0;
  c = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v1 > 0x17F )
      v3 = nullptr;
    else
      v3 = *m_pItems;
    TimelineItem::CountSelected(this: v3);
    c += CActorBitmapButton::GetActor(this: v3);
    ++v1;
    ++m_pItems;
  }
  while ( v1 < 384 );
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x0044A800
// Name: public: void CExpressionToolWorkspace::DeleteSelectedSamples(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::DeleteSelectedSamples(CExpressionToolWorkspace *this)
{
  int v2; // esi
  TimelineItem **m_pItems; // edi
  CFlexAnimationTrack *SafeTrack; // ebx
  int i; // edi
  int j; // esi
  TimelineItem *item; // [esp+4h] [ebp-Ch]
  TimelineItem **v8; // [esp+8h] [ebp-8h]
  int controller; // [esp+Ch] [ebp-4h]

  if ( CExpressionToolWorkspace::CountSelectedSamples(this) != 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Delete points");
    v2 = 0;
    m_pItems = this->m_pItems;
    controller = 0;
    v8 = m_pItems;
    do
    {
      if ( (unsigned int)v2 <= 0x17F )
      {
        item = *m_pItems;
        if ( *m_pItems != nullptr )
        {
          SafeTrack = TimelineItem::GetSafeTrack(this: *m_pItems);
          if ( SafeTrack != nullptr )
          {
            for ( i = 0; i < 2; ++i )
            {
              for ( j = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: i) - 1; j >= 0; --j )
              {
                if ( (*((_BYTE *)CFlexAnimationTrack::GetSample(this: SafeTrack, index: j, type: i) + 8) & 1) != 0 )
                  CFlexAnimationTrack::RemoveSample(this: SafeTrack, index: j, type: i);
              }
            }
            TimelineItem::DrawSelf(this: item);
            v2 = controller;
          }
        }
      }
      ++v2;
      m_pItems = v8 + 1;
      controller = v2;
      ++v8;
    }
    while ( v2 < 384 );
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Delete points");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A8D0
// Name: public: void CExpressionToolWorkspace::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::DeselectAll(CExpressionToolWorkspace *this)
{
  int v2; // esi
  TimelineItem **m_pItems; // edi
  CFlexAnimationTrack *SafeTrack; // ebx
  int i; // edi
  int j; // esi
  CExpressionSample *Sample; // eax
  TimelineItem *item; // [esp+4h] [ebp-Ch]
  TimelineItem **v9; // [esp+8h] [ebp-8h]
  int controller; // [esp+Ch] [ebp-4h]

  if ( CExpressionToolWorkspace::CountSelectedSamples(this) != 0 )
  {
    v2 = 0;
    m_pItems = this->m_pItems;
    controller = 0;
    v9 = m_pItems;
    do
    {
      if ( (unsigned int)v2 <= 0x17F )
      {
        item = *m_pItems;
        if ( *m_pItems != nullptr )
        {
          SafeTrack = TimelineItem::GetSafeTrack(this: *m_pItems);
          if ( SafeTrack != nullptr )
          {
            for ( i = 0; i < 2; ++i )
            {
              for ( j = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: i) - 1; j >= 0; --j )
              {
                Sample = CFlexAnimationTrack::GetSample(this: SafeTrack, index: j, type: i);
                *((_WORD *)Sample + 4) &= ~1u;
              }
            }
            TimelineItem::DrawSelf(this: item);
            v2 = controller;
          }
        }
      }
      ++v2;
      m_pItems = v9 + 1;
      controller = v2;
      ++v9;
    }
    while ( v2 < 384 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A970
// Name: public: void CExpressionToolWorkspace::SelectPoints(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::SelectPoints(CExpressionToolWorkspace *this, float start, float end)
{
  int v3; // esi
  TimelineItem **m_pItems; // ecx
  TimelineItem *v5; // ecx
  CFlexAnimationTrack *SafeTrack; // ebx
  int i; // edi
  int j; // esi
  CExpressionSample *Sample; // eax
  float time; // xmm0_4
  bool v11; // cl
  TimelineItem *item; // [esp+Ch] [ebp-10h]
  TimelineItem **v13; // [esp+10h] [ebp-Ch]
  int controller; // [esp+14h] [ebp-8h]
  CFlexAnimationTrack *track; // [esp+18h] [ebp-4h]

  v3 = 0;
  m_pItems = this->m_pItems;
  controller = 0;
  v13 = m_pItems;
  do
  {
    if ( (unsigned int)v3 <= 0x17F )
    {
      v5 = *m_pItems;
      item = v5;
      if ( v5 != nullptr )
      {
        SafeTrack = TimelineItem::GetSafeTrack(this: v5);
        track = SafeTrack;
        if ( SafeTrack != nullptr )
        {
          for ( i = 0; i < 2; ++i )
          {
            for ( j = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: i) - 1;
                  j >= 0;
                  *((_WORD *)Sample + 4) = *((_WORD *)Sample + 4) & 0xFFFE | v11 )
            {
              Sample = CFlexAnimationTrack::GetSample(this: SafeTrack, index: j, type: i);
              time = Sample->time;
              v11 = time >= start && end >= time;
              SafeTrack = track;
              --j;
            }
          }
          TimelineItem::DrawSelf(this: item);
          v3 = controller;
        }
      }
    }
    ++v3;
    m_pItems = v13 + 1;
    controller = v3;
    ++v13;
  }
  while ( v3 < 384 );
}

//------------------------------------------------------------------------------
// Address: 0x0044AA30
// Name: public: virtual bool ExpressionTool::IsScrubbing(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsScrubbing(ExpressionTool *this)
{
  return LODWORD(this->m_flScrub) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044AA40
// Name: private: void ExpressionTool::GetWorkspaceLeftRight(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::GetWorkspaceLeftRight(ExpressionTool *this, int *left, int *right)
{
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  HWND Handle; // eax
  HWND v6; // eax
  int v7; // eax
  CExpressionToolWorkspace *v8; // ecx
  HWND v9; // eax
  HWND v10; // eax
  tagPOINT pt; // [esp+Ch] [ebp-8h] BYREF

  m_pWorkspace = this->m_pWorkspace;
  pt.x = 10;
  pt.y = 0;
  Handle = (HWND)mxWidget::getHandle(this: m_pWorkspace);
  ClientToScreen(hWnd: Handle, lpPoint: &pt);
  v6 = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: v6, lpPoint: &pt);
  *left = SLOWORD(pt.x);
  v7 = mxWidget::w2(this: this->m_pWorkspace);
  v8 = this->m_pWorkspace;
  pt.x = v7 - 22;
  pt.y = 0;
  v9 = (HWND)mxWidget::getHandle(this: v8);
  ClientToScreen(hWnd: v9, lpPoint: &pt);
  v10 = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: v10, lpPoint: &pt);
  *right = SLOWORD(pt.x);
}

//------------------------------------------------------------------------------
// Address: 0x0044AAE0
// Name: private: void ExpressionTool::ResampleControlPoints(class CFlexTimingTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::ResampleControlPoints(ExpressionTool *this, ConCommandBase *tag, float newposition)
{
  CChoreoEvent *Flags; // edi
  int v4; // esi
  CEventAbsoluteTag *v5; // ebx
  int v6; // ebx
  int v7; // esi
  double v8; // st7
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  int v12; // esi
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v14; // esi
  int v15; // ebx
  int j; // edi
  CExpressionSample *Sample; // eax
  float time; // xmm0_4
  float v19; // xmm0_4
  CChoreoEvent *e; // [esp+8h] [ebp-20h]
  float newpivot; // [esp+Ch] [ebp-1Ch]
  float leftedge; // [esp+14h] [ebp-14h]
  CFlexTimingTag *i; // [esp+18h] [ebp-10h]
  int ia; // [esp+18h] [ebp-10h]
  CFlexTimingTag *prev; // [esp+1Ch] [ebp-Ch]
  float rightedge; // [esp+20h] [ebp-8h]
  float newleftrange; // [esp+24h] [ebp-4h]
  float oldpivot; // [esp+30h] [ebp+8h]
  float oldrightrange; // [esp+34h] [ebp+Ch]

  Flags = (CChoreoEvent *)ConCommandBase::GetFlags(this: tag);
  v4 = 0;
  e = Flags;
  if ( Flags != nullptr )
  {
    newleftrange = Flags->GetDuration(this: Flags);
    rightedge = newleftrange;
    leftedge = 0.0;
    v5 = nullptr;
    i = nullptr;
    if ( CChoreoEvent::GetNumTimingTags(this: Flags) > 0 )
    {
      while ( CChoreoEvent::GetTimingTag(this: Flags, tagnum: v4) != (CFlexTimingTag *)tag )
      {
        if ( ++v4 >= CChoreoEvent::GetNumTimingTags(this: Flags) )
          goto LABEL_21;
      }
      if ( v4 > 0 )
      {
        v6 = v4 - 1;
        while ( 1 )
        {
          prev = CChoreoEvent::GetTimingTag(this: Flags, tagnum: v6);
          if ( CFlexTimingTag::GetLocked(this: prev) )
            break;
          if ( --v6 < 0 )
          {
            prev = nullptr;
            break;
          }
        }
        v5 = (CEventAbsoluteTag *)prev;
      }
      v7 = v4 + 1;
      if ( v7 < CChoreoEvent::GetNumTimingTags(this: Flags) )
      {
        if ( v7 >= CChoreoEvent::GetNumTimingTags(this: Flags) )
        {
LABEL_16:
          i = nullptr;
        }
        else
        {
          while ( 1 )
          {
            i = CChoreoEvent::GetTimingTag(this: Flags, tagnum: v7);
            if ( CFlexTimingTag::GetLocked(this: i) )
              break;
            if ( ++v7 >= CChoreoEvent::GetNumTimingTags(this: Flags) )
              goto LABEL_16;
          }
        }
      }
      if ( v5 != nullptr )
        leftedge = CEventAbsoluteTag::GetPercentage(this: v5) * newleftrange;
      if ( i != nullptr )
        rightedge = CEventAbsoluteTag::GetPercentage(this: (CEventAbsoluteTag *)i) * newleftrange;
    }
LABEL_21:
    v8 = CEventAbsoluteTag::GetPercentage(this: (CEventAbsoluteTag *)tag) * newleftrange;
    v9 = newleftrange * newposition;
    oldpivot = v8;
    v10 = (float)(newleftrange * newposition) - leftedge;
    oldrightrange = rightedge - v8;
    v11 = rightedge - v9;
    newpivot = v9;
    if ( (float)(oldpivot - leftedge) <= 0.0 || oldrightrange <= 0.0 || v10 <= 0.0 || v11 <= 0.0 )
    {
      Con_Printf(fmt: "Range problem!!! avoiding division by zero\n");
    }
    else
    {
      v12 = 0;
      for ( ia = 0; ia < CChoreoEvent::GetNumFlexAnimationTracks(this: Flags); v12 = ia )
      {
        FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: Flags, index: v12);
        v14 = FlexAnimationTrack;
        if ( FlexAnimationTrack != nullptr )
        {
          v15 = 0;
          if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) != -1 )
          {
            do
            {
              for ( j = 0; j < CFlexAnimationTrack::GetNumSamples(this: v14, type: v15); ++j )
              {
                Sample = CFlexAnimationTrack::GetSample(this: v14, index: j, type: v15);
                if ( Sample != nullptr )
                {
                  time = Sample->time;
                  if ( leftedge <= time && time <= rightedge )
                  {
                    if ( oldpivot < time )
                      v19 = (float)((float)((float)(time - oldpivot) / oldrightrange) * v11) + newpivot;
                    else
                      v19 = (float)((float)((float)(time - leftedge) / (float)(oldpivot - leftedge)) * v10) + leftedge;
                    Sample->time = v19;
                  }
                }
              }
              ++v15;
            }
            while ( v15 < CFlexAnimationTrack::IsComboType(this: v14) + 1 );
            Flags = e;
          }
        }
        ++ia;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AD70
// Name: enum LocalFlexController_t FindFlexControllerIndexByName(class StudioModel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFlexControllerIndexByName(StudioModel *model, const char *searchname)
{
  int v2; // edi
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v5; // eax
  const studiohdr_t *v6; // eax
  LocalFlexController_t i; // [esp+10h] [ebp+8h]

  v2 = 0;
  if ( model == nullptr )
    return -1;
  m_pStudioHdr = model->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return -1;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->m_MDLHandle);
    CStudioHdr::Init(this: model->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = model->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return -1;
  }
  if ( m_pStudioHdr == nullptr )
    return -1;
  v6 = m_pStudioHdr->m_pStudioHdr;
  i = DUMMY_NULL_FLEX_CONTROLLER;
  if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers <= 0 )
    return -1;
  while ( (const studiohdr_t *)((char *)v6
                              + v2
                              + v6->flexcontrollerindex
                              + *(int *)((char *)&v6->version + v2 + v6->flexcontrollerindex)) == nullptr
       || strcmp(
            (const char *)v6
          + v2
          + v6->flexcontrollerindex
          + *(int *)((char *)&v6->version + v2 + v6->flexcontrollerindex),
            searchname) != 0 )
  {
    v2 += 20;
    if ( ++i >= v6->numflexcontrollers )
      return -1;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0044AE40
// Name: public: void ExpressionTool::DeleteSelectedSamples(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DeleteSelectedSamples(ExpressionTool *this)
{
  CExpressionToolWorkspace::DeleteSelectedSamples(this: this->m_pWorkspace);
}

//------------------------------------------------------------------------------
// Address: 0x0044AE50
// Name: public: void ExpressionTool::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DeselectAll(ExpressionTool *this)
{
  void (__thiscall *redraw)(struct ExpressionTool *); // edx

  CExpressionToolWorkspace::DeselectAll(this: this->m_pWorkspace);
  redraw = this->redraw;
  this->m_bSelectionActive = false;
  redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044AE70
// Name: public: float ExpressionTool::GetPixelsPerSecond(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ExpressionTool::GetPixelsPerSecond(ExpressionTool *this)
{
  char *Name; // eax

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  return (double)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond * 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x0044AEB0
// Name: public: void ExpressionTool::InvalidateLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::InvalidateLayout(ExpressionTool *this)
{
  CExpressionToolWorkspace *m_pWorkspace; // ecx

  if ( !this->m_bSuppressLayout )
  {
    if ( ExpressionTool::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
      ExpressionTool::RepositionHSlider(this);
    m_pWorkspace = this->m_pWorkspace;
    this->m_bLayoutIsValid = false;
    m_pWorkspace->redraw(this: m_pWorkspace);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AEF0
// Name: public: void ExpressionTool::GetStartAndEndTime(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::GetStartAndEndTime(ExpressionTool *this, float *st, float *ed)
{
  char *Name; // eax
  int v5; // edi
  char *v6; // eax
  float v7; // xmm0_4
  int right; // [esp+Ch] [ebp-8h] BYREF
  int left; // [esp+10h] [ebp-4h] BYREF

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  *st = this->m_flLeftOffset
      / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond)
              * 0.0099999998);
  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  v5 = right;
  if ( right > left )
  {
    v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v7 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6) * this->m_flPixelsPerSecond)
       * 0.0099999998;
    *ed = (float)((float)(v5 - left) / v7) + *st;
  }
  else
  {
    *ed = *st;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AFC0
// Name: private: float ExpressionTool::GetTimeValueForMouse(int,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ExpressionTool::GetTimeValueForMouse(ExpressionTool *this, int mx, bool clip)
{
  int right; // [esp+8h] [ebp-10h] BYREF
  int left; // [esp+Ch] [ebp-Ch] BYREF
  float st; // [esp+10h] [ebp-8h] BYREF
  float ed; // [esp+14h] [ebp-4h] BYREF

  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  ExpressionTool::GetStartAndEndTime(this, &st, &ed);
  if ( !clip )
    return st + (ed - st) * ((double)(mx - left) / (double)(right - left));
  if ( mx < 0 )
    return st;
  if ( mx > mxWidget::w2(this) )
    return ed;
  else
    return st + (ed - st) * ((double)(mx - left) / (double)(right - left));
}

//------------------------------------------------------------------------------
// Address: 0x0044B050
// Name: public: bool ExpressionTool::IsFocusItem(class TimelineItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsFocusItem(ExpressionTool *this, TimelineItem *item)
{
  CExpressionToolWorkspace *m_pWorkspace; // eax
  unsigned int m_nFocusItem; // ecx

  m_pWorkspace = this->m_pWorkspace;
  m_nFocusItem = m_pWorkspace->m_nFocusItem;
  if ( m_nFocusItem > 0x17F )
    return item == nullptr;
  else
    return m_pWorkspace->m_pItems[m_nFocusItem] == item;
}

//------------------------------------------------------------------------------
// Address: 0x0044B090
// Name: private: void ExpressionTool::OnDeleteSelection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnDeleteSelection(ExpressionTool *this, bool excise_time)
{
  ExpressionTool *v2; // esi
  void (__thiscall *redraw)(struct ExpressionTool *); // edx
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  int v5; // edi
  TimelineItem *v6; // ecx
  CFlexAnimationTrack *SafeTrack; // ebx
  int i; // esi
  int j; // edi
  int k; // edi
  CExpressionSample *Sample; // eax
  float time; // xmm0_4
  void (__thiscall *v13)(struct ExpressionTool *); // eax
  TimelineItem *item; // [esp+Ch] [ebp-18h]
  float shift_left_time; // [esp+10h] [ebp-14h]
  int v16; // [esp+14h] [ebp-10h]
  float undotext; // [esp+1Ch] [ebp-8h]
  const char *undotexta; // [esp+1Ch] [ebp-8h]
  float controller; // [esp+20h] [ebp-4h]
  unsigned int controllera; // [esp+20h] [ebp-4h]

  v2 = this;
  if ( this->m_bSelectionActive )
  {
    undotext = this->m_flSelection[0];
    controller = this->m_flSelection[1];
    if ( undotext > controller )
    {
      controller = this->m_flSelection[0];
      undotext = this->m_flSelection[1];
    }
    CExpressionToolWorkspace::DeselectAll(this: this->m_pWorkspace);
    redraw = v2->redraw;
    v2->m_bSelectionActive = false;
    redraw(this: v2);
    m_pWorkspace = v2->m_pWorkspace;
    v2->m_flSelection[0] = undotext;
    v2->m_flSelection[1] = controller;
    v2->m_bSelectionActive = true;
    CExpressionToolWorkspace::SelectPoints(this: m_pWorkspace, start: undotext, end: controller);
    v2->redraw(this: v2);
    undotexta = "Excise column";
    if ( !excise_time )
      undotexta = "Delete column";
    shift_left_time = v2->m_flSelection[1] - v2->m_flSelection[0];
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: undotexta);
    v5 = 12;
    controllera = 0;
    v16 = 12;
    do
    {
      if ( controllera <= 0x17F )
      {
        v6 = *(TimelineItem **)((char *)&v2->m_pWorkspace->__vftable + v5);
        item = v6;
        if ( v6 != nullptr )
        {
          SafeTrack = TimelineItem::GetSafeTrack(this: v6);
          if ( SafeTrack != nullptr )
          {
            for ( i = 0; i < 2; ++i )
            {
              for ( j = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: i) - 1; j >= 0; --j )
              {
                if ( (*((_BYTE *)CFlexAnimationTrack::GetSample(this: SafeTrack, index: j, type: i) + 8) & 1) != 0 )
                  CFlexAnimationTrack::RemoveSample(this: SafeTrack, index: j, type: i);
              }
              if ( excise_time )
              {
                for ( k = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: i) - 1; k >= 0; --k )
                {
                  Sample = CFlexAnimationTrack::GetSample(this: SafeTrack, index: k, type: i);
                  time = Sample->time;
                  if ( this->m_flSelection[1] <= time )
                    Sample->time = time - shift_left_time;
                }
              }
            }
            TimelineItem::DrawSelf(this: item);
            v2 = this;
            v5 = v16;
          }
        }
      }
      ++controllera;
      v5 += 4;
      v16 = v5;
    }
    while ( v5 < 1548 );
    CChoreoView::PushRedo(this: g_pChoreoView, description: undotexta);
    CExpressionToolWorkspace::DeselectAll(this: v2->m_pWorkspace);
    v13 = v2->redraw;
    v2->m_bSelectionActive = false;
    v13(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B290
// Name: private: void ExpressionTool::OnEdgeProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnEdgeProperties(ExpressionTool *this)
{
  CExpressionToolWorkspace *m_pWorkspace; // eax
  unsigned int m_nFocusItem; // ecx
  TimelineItem *v4; // ecx
  CFlexAnimationTrack *SafeTrack; // edi
  CEdgePropertiesParams params; // [esp+4h] [ebp-1A0h] BYREF

  m_pWorkspace = this->m_pWorkspace;
  m_nFocusItem = m_pWorkspace->m_nFocusItem;
  if ( m_nFocusItem <= 0x17F )
  {
    v4 = m_pWorkspace->m_pItems[m_nFocusItem];
    if ( v4 != nullptr )
    {
      SafeTrack = TimelineItem::GetSafeTrack(this: v4);
      if ( SafeTrack != nullptr )
      {
        _V_memset(dest: &params, fill: 0, count: 416);
        _V_strcpy(dest: params.m_szDialogTitle, src: "Edge Properties");
        CEdgePropertiesParams::SetFromFlexTrack(this: &params, track: SafeTrack);
        if ( EdgeProperties(&params) != 0 )
        {
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Change Edge Properties");
          CEdgePropertiesParams::ApplyToTrack(this: &params, track: SafeTrack);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Change Edge Properties");
          this->m_pWorkspace->redraw(this: this->m_pWorkspace);
          this->redraw(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B3A0
// Name: private: int CExpressionToolWorkspace::GetItemUnderMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CExpressionToolWorkspace::GetItemUnderMouse(
        CExpressionToolWorkspace *this,
        unsigned int mx,
        unsigned int my)
{
  unsigned int v3; // edi
  TimelineItem **i; // ebx
  TimelineItem *v5; // esi
  tagRECT rc; // [esp+Ch] [ebp-10h] BYREF

  v3 = 0;
  for ( i = this->m_pItems; ; ++i )
  {
    if ( v3 <= 0x17F )
    {
      v5 = *i;
      if ( *i != nullptr && TimelineItem::GetVisible(this: *i) )
      {
        TimelineItem::GetBounds(this: v5, rect: &rc);
        if ( PtInRect(lprc: &rc, pt: (POINT)__PAIR64__(my, mx)) )
          break;
      }
    }
    if ( (int)++v3 >= 384 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0044B410
// Name: public: void CExpressionToolWorkspace::HideTimelines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::HideTimelines(CExpressionToolWorkspace *this)
{
  int v2; // esi
  TimelineItem **m_pItems; // edi
  TimelineItem *v4; // ecx

  v2 = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v2 > 0x17F )
      v4 = nullptr;
    else
      v4 = *m_pItems;
    TimelineItem::SetVisible(this: v4, vis: false);
    ++v2;
    ++m_pItems;
  }
  while ( v2 < 384 );
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044B450
// Name: public: void CExpressionToolWorkspace::LayoutItems(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::LayoutItems(CExpressionToolWorkspace *this, bool force)
{
  CExpressionToolWorkspace *v2; // ebx
  int m_nTopOffset; // esi
  int v4; // esi
  int v5; // eax
  TimelineItem *v6; // edi
  int Height; // ebx
  tagRECT rcBounds; // [esp+8h] [ebp-20h] BYREF
  int width; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  CExpressionToolWorkspace *v11; // [esp+20h] [ebp-8h]
  TimelineItem **m_pItems; // [esp+24h] [ebp-4h]

  v2 = this;
  m_nTopOffset = this->m_nTopOffset;
  v11 = this;
  v4 = -m_nTopOffset;
  width = -20 - this->m_nScrollbarHeight + mxWidget::w2(this);
  v5 = 0;
  i = 0;
  m_pItems = v2->m_pItems;
  do
  {
    if ( (unsigned int)v5 <= 0x17F )
    {
      v6 = *m_pItems;
      if ( *m_pItems != nullptr && TimelineItem::GetVisible(this: *m_pItems) )
      {
        Height = TimelineItem::GetHeight(this: v6);
        rcBounds.right = width + 10;
        rcBounds.left = 10;
        rcBounds.top = v4;
        rcBounds.bottom = Height + v4;
        TimelineItem::SetBounds(this: v6, rect: &rcBounds);
        v4 += Height + v11->m_nItemGap;
        v2 = v11;
      }
    }
    ++m_pItems;
    v5 = i + 1;
    i = v5;
  }
  while ( v5 < 384 );
  if ( force || CExpressionToolWorkspace::ComputeVPixelsNeeded(this: v2) != v2->m_nLastVPixelsNeeded )
    CExpressionToolWorkspace::RepositionVSlider(this: v2);
  v2->redraw(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0044B520
// Name: public: void CExpressionToolWorkspace::DisableAllExcept(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::DisableAllExcept(CExpressionToolWorkspace *this)
{
  unsigned int m_nFocusItem; // eax
  TimelineItem *v3; // ebx
  int v4; // esi
  TimelineItem **m_pItems; // edi
  TimelineItem *v6; // ecx

  m_nFocusItem = this->m_nFocusItem;
  if ( m_nFocusItem <= 0x17F )
  {
    v3 = this->m_pItems[m_nFocusItem];
    if ( v3 != nullptr )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Disable All Except");
      v4 = 0;
      m_pItems = this->m_pItems;
      do
      {
        if ( (unsigned int)v4 > 0x17F )
          v6 = nullptr;
        else
          v6 = *m_pItems;
        TimelineItem::SetActive(this: v6, state: v6 == v3);
        ++v4;
        ++m_pItems;
      }
      while ( v4 < 384 );
      CExpressionToolWorkspace::LayoutItems(this, force: false);
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Disable All Except");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B5B0
// Name: public: void CExpressionToolWorkspace::EnableValid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::EnableValid(CExpressionToolWorkspace *this)
{
  CExpressionToolWorkspace *v1; // ebx
  int v2; // edi
  TimelineItem *v3; // esi
  bool IsValid; // al
  int v5; // esi
  int v6; // ecx
  TimelineItem **v7; // eax
  TimelineItem *v8; // edi
  int Height; // ebx
  tagRECT rect; // [esp+8h] [ebp-20h] BYREF
  int v11; // [esp+18h] [ebp-10h]
  TimelineItem **v12; // [esp+1Ch] [ebp-Ch]
  CExpressionToolWorkspace *v13; // [esp+20h] [ebp-8h]
  TimelineItem **m_pItems; // [esp+24h] [ebp-4h]

  v1 = this;
  v13 = this;
  CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
  CChoreoView::PushUndo(this: g_pChoreoView, description: "Enable Valid");
  v2 = 0;
  m_pItems = v1->m_pItems;
  do
  {
    if ( (unsigned int)v2 > 0x17F )
      v3 = nullptr;
    else
      v3 = *m_pItems;
    IsValid = TimelineItem::IsValid(this: v3);
    TimelineItem::SetActive(this: v3, state: IsValid);
    ++m_pItems;
    ++v2;
  }
  while ( v2 < 384 );
  v5 = -v1->m_nTopOffset;
  v11 = -20 - v1->m_nScrollbarHeight + mxWidget::w2(this: v1);
  v6 = 0;
  v7 = v1->m_pItems;
  m_pItems = nullptr;
  v12 = v1->m_pItems;
  do
  {
    if ( (unsigned int)v6 <= 0x17F )
    {
      v8 = *v7;
      if ( *v7 != nullptr && TimelineItem::GetVisible(this: *v7) )
      {
        Height = TimelineItem::GetHeight(this: v8);
        rect.bottom = Height + v5;
        rect.left = 10;
        rect.top = v5;
        rect.right = v11 + 10;
        TimelineItem::SetBounds(this: v8, &rect);
        v5 += Height + v13->m_nItemGap;
        v1 = v13;
      }
    }
    v6 = (int)m_pItems + 1;
    v7 = v12 + 1;
    m_pItems = (TimelineItem **)v6;
    ++v12;
  }
  while ( v6 < 384 );
  if ( CExpressionToolWorkspace::ComputeVPixelsNeeded(this: v1) != v1->m_nLastVPixelsNeeded )
    CExpressionToolWorkspace::RepositionVSlider(this: v1);
  v1->redraw(this: v1);
  CChoreoView::PushRedo(this: g_pChoreoView, description: "Enable Valid");
}

//------------------------------------------------------------------------------
// Address: 0x0044B6F0
// Name: public: void CExpressionToolWorkspace::CollapseAll(class TimelineItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::CollapseAll(CExpressionToolWorkspace *this, TimelineItem *keepExpanded)
{
  CExpressionToolWorkspace *v2; // ebx
  int v3; // esi
  TimelineItem **m_pItems; // edi
  CAudioMixerWave *v5; // ecx
  int v6; // esi
  int v7; // ecx
  TimelineItem **v8; // eax
  TimelineItem *v9; // edi
  int Height; // ebx
  tagRECT rect; // [esp+Ch] [ebp-1Ch] BYREF
  int v12; // [esp+1Ch] [ebp-Ch]
  TimelineItem **v13; // [esp+20h] [ebp-8h]
  CExpressionToolWorkspace *v14; // [esp+24h] [ebp-4h]
  TimelineItem *keepExpandeda; // [esp+30h] [ebp+8h]

  v2 = this;
  v14 = this;
  v3 = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v3 > 0x17F )
      v5 = nullptr;
    else
      v5 = (CAudioMixerWave *)*m_pItems;
    TimelineItem::SetCollapsed(this: v5, active: v5 != (CAudioMixerWave *)keepExpanded);
    ++v3;
    ++m_pItems;
  }
  while ( v3 < 384 );
  v6 = -v2->m_nTopOffset;
  v12 = -20 - v2->m_nScrollbarHeight + mxWidget::w2(this: v2);
  v7 = 0;
  v8 = v2->m_pItems;
  keepExpandeda = nullptr;
  v13 = v2->m_pItems;
  do
  {
    if ( (unsigned int)v7 <= 0x17F )
    {
      v9 = *v8;
      if ( *v8 != nullptr && TimelineItem::GetVisible(this: *v8) )
      {
        Height = TimelineItem::GetHeight(this: v9);
        rect.left = 10;
        rect.top = v6;
        rect.right = v12 + 10;
        rect.bottom = Height + v6;
        TimelineItem::SetBounds(this: v9, &rect);
        v6 += Height + v14->m_nItemGap;
        v2 = v14;
      }
    }
    v7 = (int)&keepExpandeda->__vftable + 1;
    v8 = v13 + 1;
    keepExpandeda = (TimelineItem *)v7;
    ++v13;
  }
  while ( v7 < 384 );
  if ( CExpressionToolWorkspace::ComputeVPixelsNeeded(this: v2) != v2->m_nLastVPixelsNeeded )
    CExpressionToolWorkspace::RepositionVSlider(this: v2);
  v2->redraw(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0044B7F0
// Name: public: void CExpressionToolWorkspace::ExpandAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::ExpandAll(CExpressionToolWorkspace *this)
{
  CExpressionToolWorkspace *v1; // ebx
  int v2; // esi
  TimelineItem **m_pItems; // edi
  CAudioMixerWave *v4; // ecx
  int v5; // esi
  int v6; // ecx
  TimelineItem **v7; // eax
  TimelineItem *v8; // edi
  int Height; // ebx
  tagRECT rect; // [esp+Ch] [ebp-20h] BYREF
  int v11; // [esp+1Ch] [ebp-10h]
  TimelineItem **v12; // [esp+20h] [ebp-Ch]
  int v13; // [esp+24h] [ebp-8h]
  CExpressionToolWorkspace *v14; // [esp+28h] [ebp-4h]

  v1 = this;
  v14 = this;
  v2 = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v2 > 0x17F )
      v4 = nullptr;
    else
      v4 = (CAudioMixerWave *)*m_pItems;
    TimelineItem::SetCollapsed(this: v4, active: false);
    ++v2;
    ++m_pItems;
  }
  while ( v2 < 384 );
  v5 = -v1->m_nTopOffset;
  v11 = -20 - v1->m_nScrollbarHeight + mxWidget::w2(this: v1);
  v6 = 0;
  v7 = v1->m_pItems;
  v13 = 0;
  v12 = v1->m_pItems;
  do
  {
    if ( (unsigned int)v6 <= 0x17F )
    {
      v8 = *v7;
      if ( *v7 != nullptr && TimelineItem::GetVisible(this: *v7) )
      {
        Height = TimelineItem::GetHeight(this: v8);
        rect.left = 10;
        rect.top = v5;
        rect.right = v11 + 10;
        rect.bottom = Height + v5;
        TimelineItem::SetBounds(this: v8, &rect);
        v5 += Height + v14->m_nItemGap;
        v1 = v14;
      }
    }
    v6 = v13 + 1;
    v7 = v12 + 1;
    v13 = v6;
    ++v12;
  }
  while ( v6 < 384 );
  if ( CExpressionToolWorkspace::ComputeVPixelsNeeded(this: v1) != v1->m_nLastVPixelsNeeded )
    CExpressionToolWorkspace::RepositionVSlider(this: v1);
  v1->redraw(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0044B8F0
// Name: public: void CExpressionToolWorkspace::ExpandValid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::ExpandValid(CExpressionToolWorkspace *this)
{
  int v1; // edi
  TimelineItem **m_pItems; // ebx
  TimelineItem *v3; // esi
  bool IsValid; // al
  CExpressionToolWorkspace *v5; // ebx
  int v6; // esi
  int v7; // ecx
  TimelineItem **p_d_this; // eax
  TimelineItem *v9; // edi
  int Height; // ebx
  tagRECT rect; // [esp+8h] [ebp-20h] BYREF
  unsigned int v12; // [esp+18h] [ebp-10h]
  mxWidget_i **v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  mxWidget *v15; // [esp+24h] [ebp-4h]

  v15 = this;
  v1 = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v1 > 0x17F )
      v3 = nullptr;
    else
      v3 = *m_pItems;
    IsValid = TimelineItem::IsValid(this: v3);
    TimelineItem::SetCollapsed(this: (CAudioMixerWave *)v3, active: !IsValid);
    ++v1;
    ++m_pItems;
  }
  while ( v1 < 384 );
  v5 = (CExpressionToolWorkspace *)v15;
  v6 = -(int)v15[194].d_this;
  v12 = -20 - (unsigned int)v15[195].__vftable + mxWidget::w2(this: v15);
  v7 = 0;
  p_d_this = (TimelineItem **)&v15[1].d_this;
  v14 = 0;
  v13 = &v15[1].d_this;
  do
  {
    if ( (unsigned int)v7 <= 0x17F )
    {
      v9 = *p_d_this;
      if ( *p_d_this != nullptr && TimelineItem::GetVisible(this: *p_d_this) )
      {
        Height = TimelineItem::GetHeight(this: v9);
        rect.bottom = Height + v6;
        rect.left = 10;
        rect.top = v6;
        rect.right = v12 + 10;
        TimelineItem::SetBounds(this: v9, &rect);
        v6 += (int)v15[195].d_this + Height;
        v5 = (CExpressionToolWorkspace *)v15;
      }
    }
    v7 = v14 + 1;
    p_d_this = (TimelineItem **)(v13 + 1);
    v14 = v7;
    ++v13;
  }
  while ( v7 < 384 );
  if ( CExpressionToolWorkspace::ComputeVPixelsNeeded(this: v5) != v5->m_nLastVPixelsNeeded )
    CExpressionToolWorkspace::RepositionVSlider(this: v5);
  v5->redraw(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0044BA00
// Name: public: void ExpressionTool::SetEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::SetEvent(ExpressionTool *this, CChoreoEvent *event)
{
  StudioModel *v2; // eax
  int FlexControllerIndex; // eax
  int NumSamples; // eax
  int number; // [esp+0h] [ebp-24h]
  TimelineItem *item; // [esp+Ch] [ebp-18h]
  CFlexAnimationTrack *track; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  unsigned int itemCount; // [esp+18h] [ebp-Ch]
  CStudioHdr *hdr; // [esp+1Ch] [ebp-8h]
  float dur; // [esp+20h] [ebp-4h]

  if ( !this->m_bInSetEvent )
  {
    this->m_bInSetEvent = true;
    if ( event == this->m_pLastEvent )
    {
      if ( event != nullptr )
      {
        dur = event->GetDuration(this: event);
        if ( dur != this->m_flLastDuration )
        {
          this->m_flLastDuration = dur;
          this->m_nLastHPixelsNeeded = -1;
          this->m_flLeftOffset = 0.0;
          ExpressionTool::InvalidateLayout(this);
        }
        this->m_nFocusEventGlobalID = CChoreoEvent::GetGlobalID(this: event);
      }
      this->m_bInSetEvent = false;
    }
    else
    {
      this->m_pLastEvent = event;
      CExpressionToolWorkspace::HideTimelines(this: this->m_pWorkspace);
      this->m_nFocusEventGlobalID = -1;
      if ( event != nullptr )
      {
        this->m_nFocusEventGlobalID = CChoreoEvent::GetGlobalID(this: event);
        if ( models->GetActiveStudioModel(this: models) != nullptr )
        {
          v2 = models->GetActiveStudioModel(this: models);
          hdr = StudioModel::GetStudioHdr(this: v2);
          if ( hdr != nullptr )
          {
            CChoreoEvent::SetTrackLookupSet(this: event, set: false);
            SetupFlexControllerTracks(hdr, event);
            itemCount = 0;
            for ( i = 0; i < CChoreoEvent::GetNumFlexAnimationTracks(this: event); ++i )
            {
              track = CChoreoEvent::GetFlexAnimationTrack(this: event, index: i);
              if ( track != nullptr )
              {
                number = itemCount;
                item = CExpressionToolWorkspace::GetItem(this: this->m_pWorkspace, number: itemCount++);
                FlexControllerIndex = CFlexAnimationTrack::GetFlexControllerIndex(this: track, side: 0);
                TimelineItem::SetExpressionInfo(this: item, track, flexnum: FlexControllerIndex);
                NumSamples = CFlexAnimationTrack::GetNumSamples(this: track, type: 0);
                TimelineItem::SetCollapsed(this: (CAudioMixerWave *)item, active: NumSamples <= 0);
                TimelineItem::SetVisible(this: item, vis: true);
              }
            }
            CExpressionToolWorkspace::LayoutItems(this: this->m_pWorkspace, force: true);
          }
        }
      }
      ExpressionTool::DeselectAll(this);
      if ( event != nullptr )
        this->m_flLastDuration = ((double (__thiscall *)(CChoreoEvent *, int))event->GetDuration)(a1: event, a2: number);
      else
        this->m_flLastDuration = 0.0;
      this->m_flLeftOffset = 0.0;
      this->m_nLastHPixelsNeeded = -1;
      ExpressionTool::InvalidateLayout(this);
      this->m_bInSetEvent = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BC80
// Name: public: bool ExpressionTool::HasCopyData(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::HasCopyData(ExpressionTool *this)
{
  return this->m_CopyData[0].m_Size != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044BC90
// Name: public: void ExpressionTool::LayoutItems(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::LayoutItems(ExpressionTool *this, bool force)
{
  CExpressionToolWorkspace::LayoutItems(this: this->m_pWorkspace, force);
}

//------------------------------------------------------------------------------
// Address: 0x0044BCA0
// Name: private: void ExpressionTool::ApplyBounds(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::ApplyBounds(ExpressionTool *this, int *mx, int *my)
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
// Address: 0x0044BCE0
// Name: private: void ExpressionTool::FinishMoveSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::FinishMoveSelection(ExpressionTool *this, float startx, float mx)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  void (__thiscall *redraw)(struct ExpressionTool *); // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  float end; // [esp+4h] [ebp-18h]
  float st; // [esp+Ch] [ebp-10h] BYREF
  float ed; // [esp+10h] [ebp-Ch] BYREF
  int right; // [esp+14h] [ebp-8h] BYREF
  float start; // [esp+18h] [ebp-4h] BYREF

  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&start, &right);
  ExpressionTool::GetStartAndEndTime(this, &st, &ed);
  start = (float)((float)((float)(LODWORD(startx) - LODWORD(start)) / (float)(right - LODWORD(start))) * (float)(ed - st))
        + st;
  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&startx, right: (int *)&st);
  ExpressionTool::GetStartAndEndTime(this, st: (float *)&right, &ed);
  v4 = (float)((float)((float)((float)(LODWORD(mx) - LODWORD(startx)) / (float)(LODWORD(st) - LODWORD(startx)))
                     * (float)(ed - *(float *)&right))
             + *(float *)&right)
     - start;
  this->m_flSelection[0] = this->m_flSelection[0] + v4;
  this->m_flSelection[1] = this->m_flSelection[1] + v4;
  v5 = this->m_flSelection[1];
  startx = this->m_flSelection[0];
  mx = v5;
  if ( startx > v5 )
  {
    mx = startx;
    startx = v5;
  }
  CExpressionToolWorkspace::DeselectAll(this: this->m_pWorkspace);
  redraw = this->redraw;
  this->m_bSelectionActive = false;
  redraw(this);
  v7 = mx;
  v8 = startx;
  m_pWorkspace = this->m_pWorkspace;
  end = mx;
  this->m_flSelection[0] = startx;
  this->m_flSelection[1] = v7;
  this->m_bSelectionActive = true;
  CExpressionToolWorkspace::SelectPoints(this: m_pWorkspace, start: v8, end);
  this->redraw(this);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044BE60
// Name: private: void ExpressionTool::FinishMoveSelectionStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::FinishMoveSelectionStart(ExpressionTool *this, float startx, float mx)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  void (__thiscall *redraw)(struct ExpressionTool *); // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  float end; // [esp+4h] [ebp-18h]
  float st; // [esp+Ch] [ebp-10h] BYREF
  float ed; // [esp+10h] [ebp-Ch] BYREF
  int right; // [esp+14h] [ebp-8h] BYREF
  float start; // [esp+18h] [ebp-4h] BYREF

  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&start, &right);
  ExpressionTool::GetStartAndEndTime(this, &st, &ed);
  start = (float)((float)((float)(LODWORD(startx) - LODWORD(start)) / (float)(right - LODWORD(start))) * (float)(ed - st))
        + st;
  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&startx, right: (int *)&st);
  ExpressionTool::GetStartAndEndTime(this, st: (float *)&right, &ed);
  v4 = this->m_flSelection[1];
  v5 = (float)((float)((float)((float)((float)(LODWORD(mx) - LODWORD(startx)) / (float)(LODWORD(st) - LODWORD(startx)))
                             * (float)(ed - *(float *)&right))
                     + *(float *)&right)
             - start)
     + this->m_flSelection[0];
  this->m_flSelection[0] = v5;
  startx = v5;
  mx = v4;
  if ( v5 > v4 )
  {
    mx = v5;
    startx = v4;
  }
  CExpressionToolWorkspace::DeselectAll(this: this->m_pWorkspace);
  redraw = this->redraw;
  this->m_bSelectionActive = false;
  redraw(this);
  v7 = mx;
  v8 = startx;
  m_pWorkspace = this->m_pWorkspace;
  end = mx;
  this->m_flSelection[0] = startx;
  this->m_flSelection[1] = v7;
  this->m_bSelectionActive = true;
  CExpressionToolWorkspace::SelectPoints(this: m_pWorkspace, start: v8, end);
  this->redraw(this);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044BFC0
// Name: private: void ExpressionTool::FinishMoveSelectionEnd(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::FinishMoveSelectionEnd(ExpressionTool *this, float startx, float mx)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  void (__thiscall *redraw)(struct ExpressionTool *); // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  float end; // [esp+4h] [ebp-18h]
  float st; // [esp+Ch] [ebp-10h] BYREF
  float ed; // [esp+10h] [ebp-Ch] BYREF
  int right; // [esp+14h] [ebp-8h] BYREF
  float start; // [esp+18h] [ebp-4h] BYREF

  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&start, &right);
  ExpressionTool::GetStartAndEndTime(this, &st, &ed);
  start = (float)((float)((float)(LODWORD(startx) - LODWORD(start)) / (float)(right - LODWORD(start))) * (float)(ed - st))
        + st;
  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&startx, right: (int *)&st);
  ExpressionTool::GetStartAndEndTime(this, st: (float *)&right, &ed);
  v4 = this->m_flSelection[0];
  v5 = (float)((float)((float)((float)((float)(LODWORD(mx) - LODWORD(startx)) / (float)(LODWORD(st) - LODWORD(startx)))
                             * (float)(ed - *(float *)&right))
                     + *(float *)&right)
             - start)
     + this->m_flSelection[1];
  this->m_flSelection[1] = v5;
  startx = v4;
  mx = v5;
  if ( v4 > v5 )
  {
    mx = v4;
    startx = v5;
  }
  CExpressionToolWorkspace::DeselectAll(this: this->m_pWorkspace);
  redraw = this->redraw;
  this->m_bSelectionActive = false;
  redraw(this);
  v7 = mx;
  v8 = startx;
  m_pWorkspace = this->m_pWorkspace;
  end = mx;
  this->m_flSelection[0] = startx;
  this->m_flSelection[1] = v7;
  this->m_bSelectionActive = true;
  CExpressionToolWorkspace::SelectPoints(this: m_pWorkspace, start: v8, end);
  this->redraw(this);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044C120
// Name: private: void ExpressionTool::FinishSelect(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::FinishSelect(ExpressionTool *this, float startx, float mx)
{
  int v3; // ebx
  int v4; // edi
  int v6; // xmm0_4
  void (__thiscall *redraw)(struct ExpressionTool *); // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  float end; // [esp+4h] [ebp-1Ch]
  int start; // [esp+14h] [ebp-Ch]
  float st; // [esp+18h] [ebp-8h] BYREF
  float ed; // [esp+1Ch] [ebp-4h] BYREF

  v3 = LODWORD(mx);
  v4 = LODWORD(startx);
  if ( (int)abs32(LODWORD(startx) - LODWORD(mx)) >= 1 )
  {
    ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&startx, right: (int *)&mx);
    ExpressionTool::GetStartAndEndTime(this, &st, &ed);
    *(float *)&start = (float)((float)((float)(v4 - LODWORD(startx)) / (float)(LODWORD(mx) - LODWORD(startx)))
                             * (float)(ed - st))
                     + st;
    ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&startx, right: (int *)&mx);
    ExpressionTool::GetStartAndEndTime(this, st: &ed, ed: &st);
    *(float *)&v6 = (float)((float)((float)(v3 - LODWORD(startx)) / (float)(LODWORD(mx) - LODWORD(startx)))
                          * (float)(st - ed))
                  + ed;
    startx = *(float *)&start;
    mx = *(float *)&v6;
    if ( *(float *)&start > *(float *)&v6 )
    {
      mx = *(float *)&start;
      startx = *(float *)&v6;
    }
    CExpressionToolWorkspace::DeselectAll(this: this->m_pWorkspace);
    redraw = this->redraw;
    this->m_bSelectionActive = false;
    redraw(this);
    v8 = mx;
    v9 = startx;
    m_pWorkspace = this->m_pWorkspace;
    end = mx;
    this->m_flSelection[0] = startx;
    this->m_flSelection[1] = v8;
    this->m_bSelectionActive = true;
    CExpressionToolWorkspace::SelectPoints(this: m_pWorkspace, start: v9, end);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C270
// Name: private: bool ExpressionTool::IsMouseOverPoints(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsMouseOverPoints(ExpressionTool *this, int mx, int my)
{
  HWND Handle; // eax
  tagRECT rc; // [esp+8h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top = 38;
  rc.bottom = 54;
  return my <= 55 && my > this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
}

//------------------------------------------------------------------------------
// Address: 0x0044C2D0
// Name: private: bool ExpressionTool::IsMouseOverSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsMouseOverSelection(ExpressionTool *this, int mx, int my)
{
  bool result; // al
  HWND Handle; // eax
  int v6; // edi
  float v7; // xmm0_4
  tagRECT Rect; // [esp+4h] [ebp-1Ch] BYREF
  float st; // [esp+14h] [ebp-Ch] BYREF
  float ed; // [esp+18h] [ebp-8h] BYREF
  int right; // [esp+1Ch] [ebp-4h] BYREF

  if ( !this->m_bSelectionActive )
    return false;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  v6 = my;
  Rect.top = 38;
  Rect.bottom = 54;
  result = false;
  if ( my <= 55 && v6 > this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12 )
  {
    ExpressionTool::GetWorkspaceLeftRight(this, left: &my, &right);
    ExpressionTool::GetStartAndEndTime(this, &st, &ed);
    v7 = (float)((float)((float)(mx - my) / (float)(right - my)) * (float)(ed - st)) + st;
    if ( v7 >= this->m_flSelection[0] && this->m_flSelection[1] >= v7 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C3B0
// Name: private: void ExpressionTool::MoveTimeSliderToPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::MoveTimeSliderToPos(ExpressionTool *this, int x)
{
  mxScrollbar *m_pHorzScrollBar; // ecx
  HWND Handle; // eax
  CExpressionToolWorkspace *m_pWorkspace; // ecx

  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = (float)x;
  mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)(float)x);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pHorzScrollBar);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  if ( !this->m_bSuppressLayout )
  {
    if ( ExpressionTool::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
      ExpressionTool::RepositionHSlider(this);
    m_pWorkspace = this->m_pWorkspace;
    this->m_bLayoutIsValid = false;
    m_pWorkspace->redraw(this: m_pWorkspace);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C430
// Name: private: void ExpressionTool::OnChangeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnChangeScale(ExpressionTool *this)
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
      ExpressionTool::InvalidateLayout(this);
      v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v7 = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6);
      Con_Printf(fmt: "Zoom factor %i %%\n", v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C590
// Name: private: void ExpressionTool::OnResetItemSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnResetItemSize(ExpressionTool *this)
{
  CExpressionToolWorkspace *m_pWorkspace; // eax
  unsigned int m_nFocusItem; // ecx
  TimelineItem *v4; // ecx

  m_pWorkspace = this->m_pWorkspace;
  m_nFocusItem = m_pWorkspace->m_nFocusItem;
  if ( m_nFocusItem <= 0x17F )
  {
    v4 = m_pWorkspace->m_pItems[m_nFocusItem];
    if ( v4 != nullptr )
    {
      TimelineItem::ResetHeight(this: v4);
      CExpressionToolWorkspace::LayoutItems(this: this->m_pWorkspace, force: true);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C5D0
// Name: private: void ExpressionTool::OnResetAllItemSizes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnResetAllItemSizes(ExpressionTool *this)
{
  unsigned int v2; // edi
  int i; // esi
  TimelineItem *v4; // ecx
  CExpressionToolWorkspace *m_pWorkspace; // edi
  int v6; // esi
  int v7; // eax
  TimelineItem *v8; // ebx
  tagRECT rect; // [esp+Ch] [ebp-24h] BYREF
  ExpressionTool *v10; // [esp+1Ch] [ebp-14h]
  int Height; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  TimelineItem **m_pItems; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  v10 = this;
  for ( i = 12; i < 1548; i += 4 )
  {
    if ( v2 <= 0x17F )
    {
      v4 = *(TimelineItem **)((char *)&this->m_pWorkspace->__vftable + i);
      if ( v4 != nullptr )
        TimelineItem::ResetHeight(this: v4);
    }
    ++v2;
  }
  m_pWorkspace = this->m_pWorkspace;
  v6 = -m_pWorkspace->m_nTopOffset;
  v12 = -20 - m_pWorkspace->m_nScrollbarHeight + mxWidget::w2(this: m_pWorkspace);
  v7 = 0;
  v13 = 0;
  m_pItems = m_pWorkspace->m_pItems;
  do
  {
    if ( (unsigned int)v7 <= 0x17F )
    {
      v8 = *m_pItems;
      if ( *m_pItems != nullptr && TimelineItem::GetVisible(this: *m_pItems) )
      {
        Height = TimelineItem::GetHeight(this: v8);
        rect.right = v12 + 10;
        rect.left = 10;
        rect.top = v6;
        rect.bottom = v6 + Height;
        TimelineItem::SetBounds(this: v8, &rect);
        v6 += Height + m_pWorkspace->m_nItemGap;
      }
    }
    ++m_pItems;
    v7 = v13 + 1;
    v13 = v7;
  }
  while ( v7 < 384 );
  CExpressionToolWorkspace::RepositionVSlider(this: m_pWorkspace);
  m_pWorkspace->redraw(this: m_pWorkspace);
  v10->redraw(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x0044C6D0
// Name: private: void ExpressionTool::OnScaleSamples(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnScaleSamples(ExpressionTool *this)
{
  ExpressionTool *v1; // edi
  long double v2; // st7
  int v3; // esi
  TimelineItem *v4; // ecx
  CFlexAnimationTrack *SafeTrack; // ebx
  int i; // edi
  int j; // esi
  CExpressionSample *Sample; // eax
  float v9; // xmm0_4
  int v10; // xmm1_4
  CInputParams params; // [esp+Ch] [ebp-59Ch] BYREF
  ExpressionTool *v12; // [esp+598h] [ebp-10h]
  float scale_factor; // [esp+59Ch] [ebp-Ch]
  int v14; // [esp+5A0h] [ebp-8h]
  int controller; // [esp+5A4h] [ebp-4h]

  v1 = this;
  v12 = this;
  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  strcpy(params.m_szDialogTitle, "Scale selected samples");
  strcpy(params.m_szPrompt, "Factor:");
  strcpy(params.m_szInputText, "1.0");
  if ( InputProperties(&params) != 0 )
  {
    v2 = atof(nptr: params.m_szInputText);
    scale_factor = v2;
    if ( v2 <= 0.0 )
      Con_Printf(fmt: "Can't scale to %.2f\n", scale_factor);
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Scale samples");
    v3 = 12;
    controller = 0;
    v14 = 12;
    do
    {
      if ( (unsigned int)controller <= 0x17F )
      {
        v4 = *(TimelineItem **)((char *)&v1->m_pWorkspace->__vftable + v3);
        if ( v4 != nullptr )
        {
          SafeTrack = TimelineItem::GetSafeTrack(this: v4);
          if ( SafeTrack != nullptr )
          {
            for ( i = 0; i < 2; ++i )
            {
              for ( j = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: i) - 1; j >= 0; --j )
              {
                Sample = CFlexAnimationTrack::GetSample(this: SafeTrack, index: j, type: i);
                if ( (*((_BYTE *)Sample + 8) & 1) != 0 )
                {
                  v9 = Sample->value * scale_factor;
                  v10 = 0;
                  if ( v9 < 0.0 || (v10 = 1065353216, v9 > 1.0) )
                    v9 = *(float *)&v10;
                  Sample->value = v9;
                }
              }
            }
            v1 = v12;
            v3 = v14;
          }
        }
      }
      ++controller;
      v3 += 4;
      v14 = v3;
    }
    while ( v3 < 1548 );
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Scale samples");
    v1->m_pWorkspace->redraw(this: v1->m_pWorkspace);
    v1->redraw(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C8A0
// Name: public: virtual void ExpressionTool::OnModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnModelChanged(ExpressionTool *this)
{
  char *v1; // esi

  v1 = (char *)this - 12;
  ExpressionTool::SetEvent(this: (ExpressionTool *)((char *)this - 12), event: nullptr);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v1 + 16))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0044CA10
// Name: public: CExpressionToolWorkspace::CExpressionToolWorkspace(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionToolWorkspace *__thiscall CExpressionToolWorkspace::CExpressionToolWorkspace(
        CExpressionToolWorkspace *this,
        mxWindow *parent)
{
  HWND Handle; // edi
  LONG WindowLongA; // eax
  TimelineItem **m_pItems; // edi
  int i; // ebx
  TimelineItem *v7; // eax
  TimelineItem *v8; // eax
  mxScrollbar *v9; // eax
  mxScrollbar *v10; // eax
  int v11; // edi
  TimelineItem **v12; // ebx
  TimelineItem *v13; // ecx

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  this->__vftable = (CExpressionToolWorkspace_vtbl *)&CExpressionToolWorkspace::`vftable';
  Handle = (HWND)mxWidget::getHandle(this);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: WindowLongA | 0x6000000);
  m_pItems = this->m_pItems;
  for ( i = 384; i != 0; --i )
  {
    v7 = (TimelineItem *)operator new(nSize: 0xD8u);
    if ( v7 != nullptr )
      v8 = TimelineItem::TimelineItem(this: v7, workspace: this);
    else
      v8 = nullptr;
    *m_pItems++ = v8;
  }
  this->m_nItemGap = 2;
  this->m_nScrollbarHeight = 12;
  this->m_nTopOffset = 0;
  this->m_nLastVPixelsNeeded = -1;
  v9 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxScrollbar::mxScrollbar(this: v9, parent: this, x: 0, y: 0, w: 12, h: 100, id: 1000, style: 1);
  else
    v10 = nullptr;
  this->m_nFocusItem = -1;
  this->m_pVertScrollBar = v10;
  v11 = 0;
  v12 = this->m_pItems;
  do
  {
    if ( (unsigned int)v11 > 0x17F )
      v13 = nullptr;
    else
      v13 = *v12;
    TimelineItem::SetVisible(this: v13, vis: false);
    ++v11;
    ++v12;
  }
  while ( v11 < 384 );
  this->redraw(this);
  CExpressionToolWorkspace::LayoutItems(this, force: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044CB20
// Name: public: void ExpressionTool::Paste(class CFlexAnimationTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::Paste(ExpressionTool *this, CFlexAnimationTrack *destination)
{
  int v3; // edi
  int *p_m_Size; // ebx
  float *v5; // esi
  int i; // [esp+18h] [ebp-8h]
  int v7; // [esp+1Ch] [ebp-4h]

  CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
  CChoreoView::PushUndo(this: g_pChoreoView, description: "Paste");
  CFlexAnimationTrack::Clear(this: destination);
  v3 = 0;
  p_m_Size = &this->m_CopyData[0].m_Size;
  do
  {
    i = 0;
    if ( *p_m_Size > 0 )
    {
      v7 = 0;
      do
      {
        v5 = (float *)(v7 + *(p_m_Size - 3));
        if ( v3 == 0 || CFlexAnimationTrack::IsComboType(this: destination) )
          CFlexAnimationTrack::AddSample(this: destination, time: v5[1], value: *v5, type: v3);
        v7 += 10;
        ++i;
      }
      while ( i < *p_m_Size );
    }
    CFlexAnimationTrack::Resort(this: destination, type: v3++);
    p_m_Size += 5;
  }
  while ( v3 < 2 );
  CChoreoView::PushRedo(this: g_pChoreoView, description: "Paste");
}

//------------------------------------------------------------------------------
// Address: 0x0044CBF0
// Name: public: class CChoreoEvent __near * ExpressionTool::GetSafeEvent(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall ExpressionTool::GetSafeEvent(ExpressionTool *this)
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
          && CChoreoEvent::GetType(this: Event) == FLEXANIMATION
          && v5->m_nGlobalID == this->m_nFocusEventGlobalID )
        {
          break;
        }
        if ( ++v3 >= (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)v2) )
          return nullptr;
      }
      if ( models->GetActiveStudioModel(this: models) != nullptr )
        ExpressionTool::SetEvent(this, event: v5);
      return (IterateRIFF *)v5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044CCA0
// Name: public: void ExpressionTool::GetScrubHandleRect(struct tagRECT __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::GetScrubHandleRect(ExpressionTool *this, tagRECT *rcHandle, bool clipped)
{
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  float v5; // xmm0_4
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int left; // [esp+0h] [ebp-18h] BYREF
  int right; // [esp+4h] [ebp-14h] BYREF
  float ed; // [esp+8h] [ebp-10h] BYREF
  float m_flScrub; // [esp+Ch] [ebp-Ch]
  float st; // [esp+10h] [ebp-8h] BYREF
  float pixel; // [esp+14h] [ebp-4h]

  m_pWorkspace = this->m_pWorkspace;
  pixel = 0.0;
  if ( mxWidget::w2(this: m_pWorkspace) <= 0 )
  {
    v5 = pixel;
  }
  else
  {
    m_flScrub = this->m_flScrub;
    ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
    ExpressionTool::GetStartAndEndTime(this, &st, &ed);
    v5 = (float)(left + (int)(float)((float)((float)(m_flScrub - st) / (float)(ed - st)) * (float)(right - left)));
    pixel = v5;
    if ( clipped )
    {
      v6 = mxWidget::w2(this);
      v5 = pixel;
      v7 = v6 - 20;
      if ( pixel >= 20.0 )
      {
        if ( pixel > (float)v7 )
          v5 = (float)v7;
      }
      else
      {
        v5 = 20.0;
      }
    }
  }
  rcHandle->right = (int)(float)(v5 + 20.0);
  rcHandle->left = (int)(float)(v5 - 20.0);
  v8 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 2;
  rcHandle->top = v8;
  rcHandle->bottom = v8 + 10;
}

//------------------------------------------------------------------------------
// Address: 0x0044CDC0
// Name: public: void ExpressionTool::DrawScrubHandle(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawScrubHandle(ExpressionTool *this, CChoreoEvent *drawHelper, float rcHandle)
{
  HBRUSH__ *SolidBrush; // eax
  tagRECT *v5; // esi
  int v6; // eax
  int v8; // eax
  CChoreoEvent *SafeEvent; // eax
  double EndTime; // st7
  int v11; // eax
  int v12; // [esp+4h] [ebp-48h]
  int bottom; // [esp+4h] [ebp-48h]
  char sz[32]; // [esp+14h] [ebp-38h] BYREF
  tagRECT rcText; // [esp+34h] [ebp-18h] BYREF
  HBRUSH__ *br; // [esp+44h] [ebp-8h]
  Color areaBorder; // [esp+48h] [ebp-4h] BYREF
  CChoreoEvent *ev; // [esp+54h] [ebp+8h]

  SolidBrush = CreateSolidBrush(color: (COLORREF)&g_flexedverts[1250].z);
  v5 = (tagRECT *)LODWORD(rcHandle);
  br = SolidBrush;
  v12 = *(_DWORD *)(LODWORD(rcHandle) + 4);
  areaBorder = (Color)14477030;
  v6 = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: (CChoreoWidgetDrawHelper *)drawHelper,
    clr: (HPEN__ *)&areaBorder,
    style: 0,
    width: 1,
    x1: 0,
    y1: v5->top,
    x2: v6,
    y2: v12);
  bottom = v5->bottom;
  v8 = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: (CChoreoWidgetDrawHelper *)drawHelper,
    clr: (HPEN__ *)&areaBorder,
    style: 0,
    width: 1,
    x1: 0,
    y1: v5->bottom,
    x2: v8,
    y2: bottom);
  CChoreoWidgetDrawHelper::DrawFilledRect(this: (CChoreoWidgetDrawHelper *)drawHelper, br, rc: v5);
  sprintf(string: sz, format: "%.3f", this->m_flScrub);
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  ev = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    rcHandle = CChoreoEvent::GetStartTime(this: SafeEvent);
    EndTime = CChoreoEvent::GetEndTime(this: ev);
    if ( EndTime - rcHandle > 0.0 )
      sprintf(string: sz, format: "%.3f", (float)(this->m_flScrub + rcHandle));
  }
  v11 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
  rcText = *v5;
  rcText.left += (rcText.right - rcText.left - v11) / 2;
  rcHandle = 2.3509886e-38;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: (CChoreoWidgetDrawHelper *)drawHelper,
    font: "Arial",
    pointsize: 9,
    weight: 500,
    clr: (const Color *)&rcHandle,
    &rcText,
    fmt: sz);
  DeleteObject(ho: br);
}

//------------------------------------------------------------------------------
// Address: 0x0044CF30
// Name: private: bool ExpressionTool::IsMouseOverScrubHandle(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsMouseOverScrubHandle(ExpressionTool *this, mxEvent *event)
{
  POINT v3; // [esp-8h] [ebp-18h]
  tagRECT rcHandle; // [esp+0h] [ebp-10h] BYREF

  ExpressionTool::GetScrubHandleRect(this, &rcHandle, clipped: true);
  InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
  v3.y = SLOWORD(event->y);
  v3.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcHandle, pt: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0044CF80
// Name: public: virtual bool ExpressionTool::IsProcessing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsProcessing(ExpressionTool *this)
{
  return ExpressionTool::GetSafeEvent(this: (ExpressionTool *)((char *)this - 12)) != nullptr
      && *(float *)&this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_LastAlloc.index != *(float *)&this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x0044CFB0
// Name: public: void ExpressionTool::SetScrubTime(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ExpressionTool::SetScrubTime(ExpressionTool *this@<ecx>, int a2@<edi>, float t)
{
  CChoreoEvent *SafeEvent; // eax
  float realtime; // [esp+10h] [ebp+8h]

  this->m_flScrub = t;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + this->m_flScrub;
    CChoreoView::SetScrubTime(this: g_pChoreoView, t: realtime);
    CChoreoView::DrawScrubHandle(this: g_pChoreoView, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D010
// Name: public: void ExpressionTool::SetScrubTargetTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::SetScrubTargetTime(ExpressionTool *this, float t)
{
  CChoreoEvent *SafeEvent; // eax
  float realtime; // [esp+10h] [ebp+8h]

  this->m_flScrubTarget = t;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + this->m_flScrubTarget;
    CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: realtime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D060
// Name: public: void ExpressionTool::ScrubThink(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ExpressionTool::ScrubThink(ExpressionTool *this@<ecx>, int a2@<edi>, float dt, bool scrubbing)
{
  float t; // xmm2_4
  float m_flScrub; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  if ( ExpressionTool::GetSafeEvent(this) != nullptr )
  {
    t = this->m_flScrubTarget;
    m_flScrub = this->m_flScrub;
    if ( t != m_flScrub || scrubbing )
    {
      v7 = t - m_flScrub;
      if ( (float)(t - m_flScrub) <= 0.0 )
      {
        if ( dt > COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_) )
          goto LABEL_6;
        v8 = m_flScrub - dt;
      }
      else
      {
        if ( dt > v7 )
        {
LABEL_6:
          ExpressionTool::SetScrubTime(this, a2, t);
          goto LABEL_11;
        }
        v8 = m_flScrub + dt;
      }
      ExpressionTool::SetScrubTime(this, a2, t: v8);
LABEL_11:
      if ( scrubbing )
        MatSysWindow::Frame(this: g_pMatSysWindow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D0F0
// Name: private: bool ExpressionTool::GetTimingTagRect(struct tagRECT __near &,class CChoreoEvent __near *,class CFlexTimingTag __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ExpressionTool::GetTimingTagRect(
        ExpressionTool *this,
        tagRECT *rcClient,
        CChoreoEvent *event,
        CFlexTimingTag *tag,
        tagRECT *rcTag)
{
  tagRECT *v6; // esi
  CFlexTimingTag *v8; // ecx
  int v9; // eax
  int v10; // ecx
  int left; // [esp+4h] [ebp-4h] BYREF
  float rcClienta; // [esp+10h] [ebp+8h]
  float rcClientb; // [esp+10h] [ebp+8h]

  v6 = rcTag;
  *(_QWORD *)&rcTag->left = *(_QWORD *)&rcClient->left;
  v8 = tag;
  *(_QWORD *)&v6->right = *(_QWORD *)&rcClient->right;
  rcClienta = CEventRelativeTag::GetStartTime(this: v8);
  rcClientb = rcClienta - CChoreoEvent::GetStartTime(this: event);
  ExpressionTool::GetWorkspaceLeftRight(this, &left, right: (int *)&event);
  ExpressionTool::GetStartAndEndTime(this, st: (float *)&rcTag, ed: (float *)&tag);
  v9 = left
     + (int)(float)((float)((float)(rcClientb - *(float *)&rcTag) / (float)(*(float *)&tag - *(float *)&rcTag))
                  * (float)((int)event - left));
  v10 = rcClient->bottom - 6;
  v6->top = v10;
  v6->bottom = v10 + 6;
  v6->right = v9 + 3;
  v6->left = v9 - 3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044D1A0
// Name: private: class CFlexTimingTag __near * ExpressionTool::IsMouseOverTag(int,int)
// Source: json
//------------------------------------------------------------------------------
CFlexTimingTag *__thiscall ExpressionTool::IsMouseOverTag(ExpressionTool *this, unsigned int mx, unsigned int my)
{
  CFlexTimingTag *result; // eax
  CChoreoEvent *v5; // esi
  HWND Handle; // eax
  IFacePoserToolWindow_vtbl *v7; // edx
  int v8; // ebx
  CFlexTimingTag *TimingTag; // eax
  tagRECT rcTag; // [esp+8h] [ebp-28h] BYREF
  tagRECT rcClient; // [esp+18h] [ebp-18h] BYREF
  CFlexTimingTag *tag; // [esp+28h] [ebp-8h] BYREF
  int left; // [esp+2Ch] [ebp-4h] BYREF

  result = (CFlexTimingTag *)ExpressionTool::GetSafeEvent(this);
  v5 = (CChoreoEvent *)result;
  if ( result != nullptr )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rcClient);
    ExpressionTool::GetWorkspaceLeftRight(this, &left, right: (int *)&tag);
    v7 = this->IFacePoserToolWindow::__vftable;
    rcClient.right = (int)tag;
    rcClient.left = left;
    rcClient.top = v7->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    rcClient.bottom = rcClient.top + 55;
    v8 = 0;
    if ( CChoreoEvent::GetNumTimingTags(this: v5) <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        TimingTag = CChoreoEvent::GetTimingTag(this: v5, tagnum: v8);
        tag = TimingTag;
        if ( TimingTag != nullptr
          && ExpressionTool::GetTimingTagRect(this, &rcClient, event: v5, tag: TimingTag, &rcTag) != 0
          && PtInRect(lprc: &rcTag, pt: (POINT)__PAIR64__(my, mx)) )
        {
          break;
        }
        if ( ++v8 >= CChoreoEvent::GetNumTimingTags(this: v5) )
          return nullptr;
      }
      return tag;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044D270
// Name: private: void ExpressionTool::DrawRelativeTags(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawRelativeTags(ExpressionTool *this, CChoreoWidgetDrawHelper *drawHelper)
{
  CChoreoEvent *SafeEvent; // esi
  CChoreoScene *v4; // esi
  int v5; // eax
  int v6; // edi
  CChoreoActor *Actor; // eax
  CChoreoActor *v8; // esi
  CChoreoChannel *Channel; // eax
  CChoreoChannel *v10; // edi
  CChoreoEvent *v11; // eax
  CChoreoEvent *v12; // esi
  CEventRelativeTag *RelativeTag; // eax
  CEventAbsoluteTag *v14; // edi
  double v15; // st7
  ExpressionTool *v16; // esi
  float v17; // xmm0_4
  bool v18; // cl
  int v19; // esi
  __m128i v20; // xmm0
  const char *Name; // eax
  int v22; // eax
  const char *v23; // eax
  int v24; // edi
  int v25; // esi
  int v26; // edi
  CChoreoScene *v27; // esi
  CEventAbsoluteTag *TimingTag; // edi
  const char *v29; // eax
  char *v30; // eax
  char v31; // cl
  int v32; // edi
  char v33; // [esp+Bh] [ebp-179h] BYREF
  char text[256]; // [esp+Ch] [ebp-178h] BYREF
  int left; // [esp+10Ch] [ebp-78h] BYREF
  float ed; // [esp+110h] [ebp-74h] BYREF
  int right; // [esp+114h] [ebp-70h] BYREF
  float st; // [esp+118h] [ebp-6Ch] BYREF
  tagRECT rcClient; // [esp+11Ch] [ebp-68h] BYREF
  CChoreoChannel *c; // [esp+12Ch] [ebp-58h] BYREF
  CChoreoActor *a; // [esp+130h] [ebp-54h] BYREF
  ExpressionTool *v42; // [esp+134h] [ebp-50h]
  tagRECT rcMark; // [esp+138h] [ebp-4Ch] BYREF
  tagRECT rcText; // [esp+148h] [ebp-3Ch] BYREF
  float StartTime; // [esp+158h] [ebp-2Ch]
  int k; // [esp+15Ch] [ebp-28h]
  int t; // [esp+160h] [ebp-24h]
  int j; // [esp+164h] [ebp-20h]
  int i; // [esp+168h] [ebp-1Ch] BYREF
  CChoreoEvent *e; // [esp+16Ch] [ebp-18h] BYREF
  CChoreoEvent *event; // [esp+170h] [ebp-14h]
  CChoreoScene *scene; // [esp+174h] [ebp-10h]
  Color fill; // [esp+17Ch] [ebp-8h] BYREF
  Color clr; // [esp+180h] [ebp-4h] BYREF

  v42 = this;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  event = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    ExpressionTool::GetStartAndEndTime(this, st: (float *)&c, ed: (float *)&a);
    if ( ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) > 0.0 )
    {
      v4 = CChoreoView::GetScene(this: g_pChoreoView);
      scene = v4;
      if ( v4 != nullptr )
      {
        CChoreoWidgetDrawHelper::GetClientRect(this: drawHelper, rc: &rcClient);
        ExpressionTool::GetWorkspaceLeftRight(this, left: &i, right: (int *)&e);
        v5 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
        rcClient.top += v5;
        rcClient.bottom = rcClient.top + 55;
        v6 = 0;
        rcClient.left = i;
        rcClient.right = (int)e;
        i = 0;
        if ( CChoreoScene::GetNumActors(this: v4) > 0 )
        {
          while ( 1 )
          {
            Actor = CChoreoScene::GetActor(this: v4, actor: v6);
            v8 = Actor;
            a = Actor;
            if ( Actor != nullptr )
            {
              j = 0;
              if ( CChoreoActor::GetNumChannels(this: Actor) > 0 )
              {
                do
                {
                  Channel = CChoreoActor::GetChannel(this: v8, channel: j);
                  v10 = Channel;
                  c = Channel;
                  if ( Channel != nullptr )
                  {
                    k = 0;
                    if ( CChoreoChannel::GetNumEvents(this: Channel) > 0 )
                    {
                      do
                      {
                        v11 = CChoreoChannel::GetEvent(this: v10, event: k);
                        v12 = v11;
                        e = v11;
                        if ( v11 != nullptr )
                        {
                          t = 0;
                          if ( CChoreoEvent::GetNumRelativeTags(this: v11) > 0 )
                          {
                            do
                            {
                              RelativeTag = CChoreoEvent::GetRelativeTag(this: v12, tagnum: t);
                              v14 = (CEventAbsoluteTag *)RelativeTag;
                              if ( RelativeTag != nullptr )
                              {
                                StartTime = CEventRelativeTag::GetStartTime(this: RelativeTag);
                                v15 = CChoreoEvent::GetStartTime(this: event);
                                v16 = v42;
                                StartTime = StartTime - v15;
                                ExpressionTool::GetWorkspaceLeftRight(this: v42, &left, &right);
                                ExpressionTool::GetStartAndEndTime(this: v16, &st, &ed);
                                v17 = (float)(StartTime - st) / (float)(ed - st);
                                v18 = v17 < 0.0 || v17 > 1.0;
                                v19 = left + (int)(float)((float)(right - left) * v17);
                                if ( !v18 )
                                {
                                  *(_QWORD *)&rcMark.left = *(_QWORD *)&rcClient.left;
                                  v20 = _mm_loadl_epi64((const __m128i *)&rcClient.right);
                                  rcMark.top = rcClient.bottom - 6;
                                  rcMark.left = v19 - 3;
                                  rcMark.bottom = v20.m128i_i32[1];
                                  rcMark.right = v19 + 3;
                                  fill = (Color)16409600;
                                  CChoreoWidgetDrawHelper::DrawTriangleMarker(
                                    this: drawHelper,
                                    rc: &rcMark,
                                    &fill,
                                    inverted: false);
                                  rcText.left = rcMark.left;
                                  *(_QWORD *)&rcText.right = *(_QWORD *)&rcMark.right;
                                  rcText.top = rcMark.top - 10;
                                  Name = CEventAbsoluteTag::GetName(this: v14);
                                  v22 = CChoreoWidgetDrawHelper::CalcTextWidth(
                                          font: "Arial",
                                          pointsize: (HFONT__ *)9,
                                          weight: 400,
                                          fmt: Name);
                                  rcText.bottom = rcText.top + 10;
                                  rcText.left = v19 - v22 / 2;
                                  rcText.right = rcText.left + v22 + 2;
                                  clr = (Color)13132800;
                                  v23 = CEventAbsoluteTag::GetName(this: v14);
                                  CChoreoWidgetDrawHelper::DrawColoredText(
                                    this: drawHelper,
                                    font: "Arial",
                                    pointsize: 9,
                                    weight: 400,
                                    &clr,
                                    &rcText,
                                    fmt: v23);
                                }
                                v12 = e;
                              }
                              v24 = ++t;
                            }
                            while ( v24 < CChoreoEvent::GetNumRelativeTags(this: v12) );
                            v10 = c;
                          }
                        }
                        v25 = ++k;
                      }
                      while ( v25 < CChoreoChannel::GetNumEvents(this: v10) );
                      v8 = a;
                    }
                  }
                  v26 = ++j;
                }
                while ( v26 < CChoreoActor::GetNumChannels(this: v8) );
                v6 = i;
              }
            }
            i = ++v6;
            if ( v6 >= CChoreoScene::GetNumActors(this: scene) )
              break;
            v4 = scene;
          }
        }
        v27 = nullptr;
        for ( scene = nullptr; (int)v27 < CChoreoEvent::GetNumTimingTags(this: event); scene = v27 )
        {
          TimingTag = (CEventAbsoluteTag *)CChoreoEvent::GetTimingTag(this: event, tagnum: (int)v27);
          if ( TimingTag != nullptr
            && ExpressionTool::GetTimingTagRect(
                 this: v42,
                 &rcClient,
                 event,
                 tag: (CFlexTimingTag *)TimingTag,
                 rcTag: &rcMark) != 0 )
          {
            clr = (Color)25850;
            CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, fill: &clr, inverted: false);
            rcText.left = rcMark.left;
            rcText.top = rcMark.top - 20;
            *(_QWORD *)&rcText.right = *(_QWORD *)&rcMark.right;
            v29 = CEventAbsoluteTag::GetName(this: TimingTag);
            sprintf(string: text, format: "%s", v29);
            if ( CFlexTimingTag::GetLocked(this: (CFlexTimingTag *)TimingTag) )
            {
              v30 = &v33;
              do
                v31 = *++v30;
              while ( v31 != 0 );
              strcpy(v30, " - locked");
            }
            v32 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: text);
            fill = (Color)25800;
            rcText.left = (rcMark.right + rcMark.left) / 2 - v32 / 2;
            rcText.right = rcText.left + v32 + 2;
            rcText.bottom = rcText.top + 10;
            CChoreoWidgetDrawHelper::DrawColoredText(
              this: drawHelper,
              font: "Arial",
              pointsize: 9,
              weight: 400,
              clr: &fill,
              &rcText,
              fmt: text);
            v27 = scene;
          }
          v27 = (CChoreoScene *)((char *)v27 + 1);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D6E0
// Name: public: void ExpressionTool::ShowContextMenu(class mxEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::ShowContextMenu(ExpressionTool *this, mxEvent *event, bool include_track_menus)
{
  mxPopupMenu *v4; // eax
  CFlexAnimationTrack *SafeTrack; // ebx
  mxPopupMenu *v6; // esi
  CExpressionToolWorkspace *m_pWorkspace; // eax
  unsigned int m_nFocusItem; // ecx
  TimelineItem *v9; // edi
  char *UndoDescription; // eax
  const char *v11; // eax
  char *RedoDescription; // eax
  const char *v13; // eax
  mxPopupMenu *v14; // eax
  mxPopupMenu *v15; // edi
  const char *FlexControllerName; // eax
  const char *v17; // eax
  mxPopupMenu *v18; // eax
  mxPopupMenu *v19; // edi
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  TimelineItem *v25; // edi
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  mxPopupMenu *v31; // eax
  mxPopupMenu *v32; // edi
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  mxPopupMenu *v38; // eax
  mxPopupMenu *v39; // edi
  const char *v40; // eax
  const char *v41; // eax
  mxPopupMenu *v42; // eax
  CFlexTimingTag *v43; // eax
  CEventAbsoluteTag *v44; // edi
  const char *v45; // eax
  const char *v46; // eax
  bool IsMouseOverSelection; // bl
  mxPopupMenu *v48; // eax
  mxPopupMenu *v49; // edi
  mxPopupMenu *v50; // eax
  mxPopupMenu *v51; // edi
  ExpressionTool *v52; // ebx
  mxPopupMenu *v53; // eax
  mxPopupMenu *v54; // edi
  const char *v55; // eax
  mxPopupMenu *v56; // eax
  mxPopupMenu *v57; // edi
  const char *v58; // [esp-8h] [ebp-24h]
  const char *v59; // [esp-8h] [ebp-24h]
  const char *Name; // [esp-8h] [ebp-24h]
  const char *v61; // [esp-8h] [ebp-24h]
  const char *v62; // [esp-8h] [ebp-24h]
  int v63; // [esp-4h] [ebp-20h]
  int v64; // [esp-4h] [ebp-20h]
  int current; // [esp+Ch] [ebp-10h] BYREF
  int total; // [esp+10h] [ebp-Ch] BYREF
  TimelineItem *item; // [esp+14h] [ebp-8h]
  ExpressionTool *v68; // [esp+18h] [ebp-4h]
  mxPopupMenu *tagmenu; // [esp+28h] [ebp+Ch]

  v68 = this;
  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  SafeTrack = nullptr;
  if ( v4 != nullptr )
    v6 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v6 = nullptr;
  item = nullptr;
  if ( include_track_menus )
  {
    m_pWorkspace = this->m_pWorkspace;
    m_nFocusItem = m_pWorkspace->m_nFocusItem;
    v9 = m_nFocusItem > 0x17F ? nullptr : m_pWorkspace->m_pItems[m_nFocusItem];
    item = v9;
    if ( v9 != nullptr )
    {
      TimelineItem::CountSelected(this: v9);
      SafeTrack = TimelineItem::GetSafeTrack(this: v9);
    }
  }
  CChoreoView::GetUndoLevels(this: g_pChoreoView, &current, number: &total);
  if ( total > 0 )
  {
    if ( current > 0 )
    {
      UndoDescription = CChoreoView::GetUndoDescription(this: g_pChoreoView);
      v11 = va(fmt: "Undo %s", UndoDescription);
      mxPopupMenu::add(this: v6, item: v11, id: 1015);
    }
    if ( current <= total - 1 )
    {
      RedoDescription = CChoreoView::GetRedoDescription(this: g_pChoreoView);
      v13 = va(fmt: "Redo %s", RedoDescription);
      mxPopupMenu::add(this: v6, item: v13, id: 1014);
    }
    mxMenu::addSeparator(this: v6);
  }
  v14 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    v15 = mxPopupMenu::mxPopupMenu(this: v14);
  else
    v15 = nullptr;
  if ( item != nullptr && SafeTrack != nullptr && CAudioMixerWave::GetActive(this: (CAudioMixerWave *)item) )
  {
    FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
    v17 = va(fmt: "Track '%s'", FlexControllerName);
    mxPopupMenu::add(this: v15, item: v17, id: 1022);
  }
  mxPopupMenu::add(this: v15, item: "All tracks", id: 1003);
  mxPopupMenu::add(this: v15, item: "Used tracks", id: 1004);
  mxMenu::addMenu(this: v6, item: "Expand", menu: v15);
  v18 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    v19 = mxPopupMenu::mxPopupMenu(this: v18);
  else
    v19 = nullptr;
  if ( item != nullptr && SafeTrack != nullptr && !CAudioMixerWave::GetActive(this: (CAudioMixerWave *)item) )
  {
    v20 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
    v21 = va(fmt: "Track '%s'", v20);
    mxPopupMenu::add(this: v19, item: v21, id: 1021);
    v22 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
    v23 = va(fmt: "All tracks except '%s'", v22);
    mxPopupMenu::add(this: v19, item: v23, id: 1027);
  }
  mxPopupMenu::add(this: v19, item: "All tracks", id: 1002);
  mxMenu::addMenu(this: v6, item: "Collapse", menu: v19);
  mxMenu::addSeparator(this: v6);
  v24 = va(fmt: "Enable all valid");
  mxPopupMenu::add(this: v6, item: v24, id: 1029);
  v25 = item;
  if ( item != nullptr && SafeTrack != nullptr )
  {
    if ( TimelineItem::IsActive(this: item) )
    {
      v63 = 1024;
      v58 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
      v26 = va(fmt: "Disable '%s'", v58);
    }
    else
    {
      v63 = 1023;
      v59 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
      v26 = va(fmt: "Enable '%s'", v59);
    }
    mxPopupMenu::add(this: v6, item: v26, id: v63);
    v27 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
    v28 = va(fmt: "Disable all except '%s'", v27);
    mxPopupMenu::add(this: v6, item: v28, id: 1028);
    mxMenu::addSeparator(this: v6);
    mxPopupMenu::add(this: v6, item: "Copy", id: 1016);
    if ( v68->m_CopyData[0].m_Size != 0 )
      mxPopupMenu::add(this: v6, item: "Paste", id: 1017);
    mxMenu::addSeparator(this: v6);
    if ( CActorBitmapButton::GetActor(this: v25) > 0 )
    {
      v29 = va(fmt: "Delete");
      mxPopupMenu::add(this: v6, item: v29, id: 1018);
      mxPopupMenu::add(this: v6, item: "Deselect all", id: 1019);
      v30 = va(fmt: "Scale selected...");
      mxPopupMenu::add(this: v6, item: v30, id: 1042);
    }
    mxPopupMenu::add(this: v6, item: "Select all", id: 1020);
    if ( FacePoser_IsSnapping() )
    {
      v31 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v31 != nullptr )
        v32 = mxPopupMenu::mxPopupMenu(this: v31);
      else
        v32 = nullptr;
      v33 = va(fmt: "All points");
      mxPopupMenu::add(this: v32, item: v33, id: 1033);
      v34 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
      v35 = va(fmt: "All points in '%s'", v34);
      mxPopupMenu::add(this: v32, item: v35, id: 1031);
      v36 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
      v37 = va(fmt: "Selected points in '%s'", v36);
      mxPopupMenu::add(this: v32, item: v37, id: 1030);
      mxMenu::addSeparator(this: v6);
      mxMenu::addMenu(this: v6, item: "Snap", menu: v32);
      v25 = item;
    }
    if ( CFlexAnimationTrack::IsComboType(this: SafeTrack) )
    {
      mxMenu::addSeparator(this: v6);
      if ( TimelineItem::GetEditType(this: v25) != 0 )
        mxPopupMenu::add(this: v6, item: "Edit <amount>", id: 1025);
      else
        mxPopupMenu::add(this: v6, item: "Edit <left/right>", id: 1026);
    }
    mxMenu::addSeparator(this: v6);
    v38 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v38 != nullptr )
      v39 = mxPopupMenu::mxPopupMenu(this: v38);
    else
      v39 = nullptr;
    v40 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
    v41 = va(fmt: "Reset '%s'", v40);
    mxPopupMenu::add(this: v39, item: v41, id: 1040);
    mxPopupMenu::add(this: v39, item: "Reset All", id: 1041);
    mxMenu::addMenu(this: v6, item: "Height", menu: v39);
    mxMenu::addSeparator(this: v6);
    mxPopupMenu::add(this: v6, item: "Edge Properties...", id: 1053);
  }
  mxMenu::addSeparator(this: v6);
  v42 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    tagmenu = mxPopupMenu::mxPopupMenu(this: v42);
  else
    tagmenu = nullptr;
  v43 = ExpressionTool::IsMouseOverTag(this: v68, mx: SLOWORD(event->x), my: SLOWORD(event->y));
  v44 = (CEventAbsoluteTag *)v43;
  if ( v43 != nullptr )
  {
    if ( CFlexTimingTag::GetLocked(this: v43) )
    {
      v64 = 1008;
      Name = CEventAbsoluteTag::GetName(this: v44);
      v45 = va(fmt: "Unlock tag '%s'...", Name);
    }
    else
    {
      v64 = 1007;
      v61 = CEventAbsoluteTag::GetName(this: v44);
      v45 = va(fmt: "Lock tag '%s'...", v61);
    }
    mxPopupMenu::add(this: tagmenu, item: v45, id: v64);
    mxMenu::addSeparator(this: tagmenu);
    v46 = CEventAbsoluteTag::GetName(this: v44);
    v62 = va(fmt: "Delete tag '%s'...", v46);
    mxPopupMenu::add(this: tagmenu, item: v62, id: 1006);
  }
  else
  {
    mxPopupMenu::add(this: tagmenu, item: "Insert...", id: 1005);
  }
  IsMouseOverSelection = ExpressionTool::IsMouseOverSelection(this: v68, mx: SLOWORD(event->x), my: SLOWORD(event->y));
  if ( IsMouseOverSelection || v68->m_ColumnCopy.m_bActive )
  {
    v48 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v48 != nullptr )
      v49 = mxPopupMenu::mxPopupMenu(this: v48);
    else
      v49 = nullptr;
    if ( IsMouseOverSelection )
      mxPopupMenu::add(this: v49, item: "Copy samples", id: 1054);
    if ( v68->m_ColumnCopy.m_bActive )
      mxPopupMenu::add(this: v49, item: "Paste samples", id: 1055);
    if ( IsMouseOverSelection )
    {
      mxMenu::addSeparator(this: v49);
      mxPopupMenu::add(this: v49, item: "Delete samples", id: 1038);
      mxPopupMenu::add(this: v49, item: "Delete samples and shift remainder", id: 1039);
    }
    mxMenu::addMenu(this: v6, item: "Column", menu: v49);
  }
  mxMenu::addMenu(this: v6, item: "Timing Tags", menu: tagmenu);
  if ( FacePoser_IsSnapping() )
  {
    mxMenu::addSeparator(this: v6);
    mxPopupMenu::add(this: v6, item: "Delete keys by frame", id: 1032);
    mxMenu::addSeparator(this: v6);
  }
  v50 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v50 != nullptr )
    v51 = mxPopupMenu::mxPopupMenu(this: v50);
  else
    v51 = nullptr;
  mxPopupMenu::add(this: v51, item: "Copy to sliders", id: 1009);
  mxPopupMenu::add(this: v51, item: "Copy from sliders", id: 1010);
  mxMenu::addMenu(this: v6, item: "Flex", menu: v51);
  mxPopupMenu::add(this: v6, item: "Create expression...", id: 1011);
  v52 = v68;
  if ( ExpressionTool::GetSafeEvent(this: v68) != nullptr )
  {
    v53 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v53 != nullptr )
      v54 = mxPopupMenu::mxPopupMenu(this: v53);
    else
      v54 = nullptr;
    mxPopupMenu::add(this: v54, item: "Export flex animation...", id: 1012);
    mxPopupMenu::add(this: v54, item: "Import flex animation...", id: 1013);
    mxMenu::addMenu(this: v6, item: "Import/Export", menu: v54);
  }
  v55 = va(fmt: "Change scale...");
  mxPopupMenu::add(this: v6, item: v55, id: 1034);
  v56 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v56 != nullptr )
    v57 = mxPopupMenu::mxPopupMenu(this: v56);
  else
    v57 = nullptr;
  mxPopupMenu::add(this: v57, item: "Sort by name", id: 1037);
  mxPopupMenu::add(this: v57, item: "Sort by used", id: 1036);
  mxMenu::addMenu(this: v6, item: "Sort", menu: v57);
  mxPopupMenu::popup(this: v6, widget: v52, x: SLOWORD(event->x), y: SLOWORD(event->y));
}

//------------------------------------------------------------------------------
// Address: 0x0044DE30
// Name: private: void ExpressionTool::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawFocusRect(ExpressionTool *this)
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
// Address: 0x0044DEB0
// Name: public: float ExpressionTool::GetTimeForClickedPos(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ExpressionTool::GetTimeForClickedPos(ExpressionTool *this)
{
  CChoreoEvent *SafeEvent; // ebx
  int m_nClickedX; // esi
  int v5; // eax
  double StartTime; // st7
  float t; // [esp+8h] [ebp-10h] BYREF
  float ed; // [esp+Ch] [ebp-Ch] BYREF
  int right; // [esp+10h] [ebp-8h] BYREF
  int left; // [esp+14h] [ebp-4h] BYREF

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent == nullptr )
    return 0.0;
  m_nClickedX = this->m_nClickedX;
  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  ExpressionTool::GetStartAndEndTime(this, st: &t, &ed);
  v5 = left;
  left = m_nClickedX - left;
  right -= v5;
  t = t + (ed - t) * ((double)left / (double)right);
  StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
  return StartTime + t;
}

//------------------------------------------------------------------------------
// Address: 0x0044DF30
// Name: private: void ExpressionTool::AddFlexTimingTag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::AddFlexTimingTag(ExpressionTool *this, float mx)
{
  CChoreoEvent *SafeEvent; // eax
  CChoreoEvent *v4; // edi
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // eax
  double v6; // st7
  double v7; // st7
  CInputParams params; // [esp+10h] [ebp-594h] BYREF
  float minVal; // [esp+59Ch] [ebp-8h] BYREF
  float t; // [esp+5A0h] [ebp-4h] BYREF

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  v4 = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    if ( CChoreoEvent::GetType(this: SafeEvent) == FLEXANIMATION )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      strcpy(params.m_szDialogTitle, "Event Tag Name");
      strcpy(params.m_szPrompt, "Name:");
      params.m_szInputText[0] = 0;
      if ( InputProperties(&params) != 0 )
      {
        if ( strlen(params.m_szInputText) != 0 )
        {
          t = ExpressionTool::GetTimeValueForMouse(this, mx: SLODWORD(mx), clip: false);
          GetDuration = v4->GetDuration;
          mx = 0.0;
          if ( ((double (__thiscall *)(CChoreoEvent *))GetDuration)(a1: v4) != 0.0 )
          {
            v6 = ((double (__thiscall *)(CChoreoEvent *))v4->GetDuration)(a1: v4);
            v7 = t / v6;
            t = 1.0;
            minVal = 0.0;
            mx = v7;
            mx = clamp<float,float,float>(val: &mx, &minVal, maxVal: &t);
          }
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Add Timing Tag");
          CChoreoEvent::AddTimingTag(this: v4, tagname: params.m_szInputText, percentage: mx, locked: true);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Add Timing Tag");
          this->m_pWorkspace->redraw(this: this->m_pWorkspace);
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
      Con_ErrorPrintf(fmt: "Timing Tag:  Can only tag FLEXANIMATION events\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E0F0
// Name: private: void ExpressionTool::DeleteFlexTimingTag(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DeleteFlexTimingTag(ExpressionTool *this, unsigned int mx, unsigned int my)
{
  CChoreoEvent *SafeEvent; // ebx
  CFlexTimingTag *v5; // edi
  const char *Name; // eax

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v5 = ExpressionTool::IsMouseOverTag(this, mx, my);
    if ( v5 != nullptr )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Delete Timing Tag");
      Name = CEventAbsoluteTag::GetName(this: (CEventAbsoluteTag *)v5);
      CChoreoEvent::RemoveTimingTag(this: SafeEvent, tagname: Name);
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Delete Timing Tag");
      CExpressionToolWorkspace::LayoutItems(this: this->m_pWorkspace, force: true);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E180
// Name: private: void ExpressionTool::LockTimingTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::LockTimingTag(ExpressionTool *this)
{
  CFlexTimingTag *v2; // eax
  CFlexTimingTag *v3; // edi

  if ( ExpressionTool::GetSafeEvent(this) != nullptr )
  {
    v2 = ExpressionTool::IsMouseOverTag(this, mx: this->m_nClickedX, my: this->m_nClickedY);
    v3 = v2;
    if ( v2 != nullptr && !CFlexTimingTag::GetLocked(this: v2) )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Lock Timing Tag");
      CFlexTimingTag::SetLocked(this: v3, locked: true);
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Lock Timing Tag");
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E200
// Name: private: void ExpressionTool::UnlockTimingTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::UnlockTimingTag(ExpressionTool *this)
{
  CFlexTimingTag *v2; // eax
  CFlexTimingTag *v3; // edi

  if ( ExpressionTool::GetSafeEvent(this) != nullptr )
  {
    v2 = ExpressionTool::IsMouseOverTag(this, mx: this->m_nClickedX, my: this->m_nClickedY);
    v3 = v2;
    if ( v2 != nullptr && CFlexTimingTag::GetLocked(this: v2) )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Unlock Timing Tag");
      CFlexTimingTag::SetLocked(this: v3, locked: false);
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Unlock Timing Tag");
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E280
// Name: private: void ExpressionTool::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::CalcBounds(ExpressionTool *this, int movetype)
{
  unsigned int m_nStartY; // ecx
  int v4; // eax
  CFlexTimingTag *v5; // eax
  ConCommandBase *v6; // ebx
  int v7; // edi
  CChoreoEvent *Flags; // ebx
  double EndTime; // st7
  int v10; // edi
  double v11; // st7
  int v12; // ebx
  int v13; // edi
  int m_nMinX; // eax
  double v15; // st7
  int m_nMaxX; // eax
  unsigned int m_nStartX; // [esp-10h] [ebp-2Ch]
  CFlexTimingTag *frac; // [esp+4h] [ebp-18h]
  float fraca; // [esp+4h] [ebp-18h]
  float ed; // [esp+8h] [ebp-14h]
  CFlexTimingTag *next; // [esp+Ch] [ebp-10h]
  CFlexTimingTag *prev; // [esp+10h] [ebp-Ch]
  float st; // [esp+14h] [ebp-8h]
  int right; // [esp+18h] [ebp-4h] BYREF

  if ( movetype == 1 )
  {
    this->m_bUseBounds = true;
    this->m_nMinX = 0;
    this->m_nMaxX = mxWidget::w2(this);
  }
  else if ( movetype == 2 )
  {
    this->m_bUseBounds = true;
    ExpressionTool::GetWorkspaceLeftRight(this, left: &movetype, &right);
    m_nStartY = this->m_nStartY;
    v4 = right;
    this->m_nMinX = movetype;
    m_nStartX = this->m_nStartX;
    this->m_nMaxX = v4;
    v5 = ExpressionTool::IsMouseOverTag(this, mx: m_nStartX, my: m_nStartY);
    v6 = (ConCommandBase *)v5;
    v7 = 0;
    frac = v5;
    if ( v5 != nullptr && ConCommandBase::GetFlags(this: (ConCommandBase *)v5) != 0 )
    {
      Flags = (CChoreoEvent *)ConCommandBase::GetFlags(this: v6);
      st = CChoreoEvent::GetStartTime(this: Flags);
      EndTime = CChoreoEvent::GetEndTime(this: Flags);
      ed = EndTime;
      if ( EndTime > st )
      {
        prev = nullptr;
        next = nullptr;
        if ( CChoreoEvent::GetNumTimingTags(this: Flags) > 0 )
        {
          while ( CChoreoEvent::GetTimingTag(this: Flags, tagnum: v7) != frac )
          {
            if ( ++v7 >= CChoreoEvent::GetNumTimingTags(this: Flags) )
              return;
          }
          if ( v7 > 0 )
            prev = CChoreoEvent::GetTimingTag(this: Flags, tagnum: v7 - 1);
          v10 = v7 + 1;
          if ( v10 < CChoreoEvent::GetNumTimingTags(this: Flags) )
            next = CChoreoEvent::GetTimingTag(this: Flags, tagnum: v10);
          if ( prev != nullptr
            && (v11 = (CEventRelativeTag::GetStartTime(this: prev) - st) / (ed - st)) >= 0.0
            && (fraca = v11) <= 1.0 )
          {
            v12 = right;
            v13 = movetype;
            m_nMinX = movetype + (int)(float)((float)(right - movetype) * fraca) + 5;
            if ( this->m_nMinX > m_nMinX )
              m_nMinX = this->m_nMinX;
            this->m_nMinX = m_nMinX;
          }
          else
          {
            v13 = movetype;
            v12 = right;
          }
          if ( next != nullptr )
          {
            v15 = (CEventRelativeTag::GetStartTime(this: next) - st) / (ed - st);
            *(float *)&movetype = v15;
            if ( v15 >= 0.0 && *(float *)&movetype <= 1.0 )
            {
              m_nMaxX = v13 + (int)(float)((float)(v12 - v13) * *(float *)&movetype) - 5;
              if ( this->m_nMaxX < m_nMaxX )
                m_nMaxX = this->m_nMaxX;
              this->m_nMaxX = m_nMaxX;
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
// Address: 0x0044E490
// Name: public: void ExpressionTool::OnNewExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnNewExpression(ExpressionTool *this)
{
  CChoreoEvent *SafeEvent; // edi
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  int m_nClickedX; // esi
  int v8; // esi
  double StartTime; // st7
  CChoreoEvent *v10; // esi
  int v11; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v13; // ebx
  int j; // esi
  int FlexControllerIndex; // edi
  int v16; // esi
  float settings[384]; // [esp+18h] [ebp-EA4h] BYREF
  float weights[384]; // [esp+618h] [ebp-8A4h] BYREF
  CExpressionParams params; // [esp+C18h] [ebp-2A4h] BYREF
  float ed; // [esp+EA4h] [ebp-18h] BYREF
  CExpClass *active; // [esp+EA8h] [ebp-14h]
  CChoreoEvent *e; // [esp+EACh] [ebp-10h]
  float faketime; // [esp+EB0h] [ebp-Ch] BYREF
  float t; // [esp+EB4h] [ebp-8h] BYREF
  int i; // [esp+EB8h] [ebp-4h] BYREF

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  e = SafeEvent;
  if ( SafeEvent == nullptr )
    return;
  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    goto LABEL_7;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = v3->m_pStudioHdr;
    if ( v6->m_pStudioHdr != nullptr )
    {
      m_pStudioHdr = v6;
      goto LABEL_6;
    }
LABEL_7:
    Con_ErrorPrintf(fmt: "ExpressionTool::OnNewExpression:  Can't create new face pose, must load a model first!\n");
    return;
  }
LABEL_6:
  if ( m_pStudioHdr == nullptr )
    goto LABEL_7;
  active = expressions->GetActiveClass(this: expressions);
  if ( active != nullptr )
  {
    mxExpressionTray::Deselect(this: g_pExpressionTrayTool);
    m_nClickedX = this->m_nClickedX;
    ExpressionTool::GetWorkspaceLeftRight(this, left: &i, right: (int *)&faketime);
    ExpressionTool::GetStartAndEndTime(this, st: &t, &ed);
    v8 = m_nClickedX - i;
    i = LODWORD(faketime) - i;
    t = t + (ed - t) * ((double)v8 / (double)i);
    StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
    faketime = StartTime + t;
    memset(dst: (unsigned __int8 *)settings, value: 0, count: sizeof(settings));
    memset(dst: (unsigned __int8 *)weights, value: 0, count: sizeof(weights));
    v10 = e;
    v11 = 0;
    for ( i = 0; v11 < CChoreoEvent::GetNumFlexAnimationTracks(this: e); i = v11 )
    {
      FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: v10, index: v11);
      v13 = FlexAnimationTrack;
      if ( FlexAnimationTrack != nullptr && CFlexAnimationTrack::IsTrackActive(this: FlexAnimationTrack) )
      {
        if ( CFlexAnimationTrack::IsComboType(this: v13) )
        {
          for ( j = 0; j < 2; ++j )
          {
            FlexControllerIndex = CFlexAnimationTrack::GetFlexControllerIndex(this: v13, side: j);
            if ( FlexControllerIndex != -1 )
            {
              settings[FlexControllerIndex] = CFlexAnimationTrack::GetIntensity(this: v13, time: faketime, side: j);
              weights[FlexControllerIndex] = 1.0;
            }
          }
          v11 = i;
        }
        else
        {
          v16 = CFlexAnimationTrack::GetFlexControllerIndex(this: v13, side: 0);
          if ( v16 != -1 )
          {
            settings[v16] = CFlexAnimationTrack::GetIntensity(this: v13, time: faketime, side: 0);
            weights[v16] = 1.0;
          }
        }
      }
      v10 = e;
      ++v11;
    }
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Add Expression");
    params.m_szName[0] = 0;
    params.m_szDescription[0] = 0;
    if ( ExpressionProperties(&params) != 0 )
    {
      if ( strlen(params.m_szName) != 0 && _V_stricmp(s1: params.m_szName, s2: "unnamed") != 0 )
      {
        if ( strlen(params.m_szDescription) != 0 && _V_stricmp(s1: params.m_szDescription, s2: "description") != 0 )
          CExpClass::AddExpression(
            this: active,
            name: params.m_szName,
            description: params.m_szDescription,
            flexsettings: settings,
            flexweights: weights,
            selectnewitem: true,
            bDirtyClass: true);
        else
          Con_ErrorPrintf(fmt: "You must type in a valid description\n");
      }
      else
      {
        Con_ErrorPrintf(fmt: "You must type in a valid name\n");
      }
    }
  }
  else
  {
    Con_ErrorPrintf(fmt: "ExpressionTool::OnNewExpression:  Can't create new face pose, must load an expression file first!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E7C0
// Name: public: void ExpressionTool::OnCopyToFlex(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnCopyToFlex(ExpressionTool *this, float scenetime, bool isEdited)
{
  CChoreoEvent *SafeEvent; // eax
  CChoreoEvent *v4; // ebx
  int v5; // esi
  CExpClass *v6; // eax
  CExpClass *v7; // edi
  int SelectedExpression; // eax
  CExpression *Expression; // eax
  CExpression *v10; // esi
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v12; // edi
  int v13; // ebx
  int FlexControllerIndex; // esi
  LocalFlexController_t RawFlexControllerIndex; // eax
  int i; // [esp+14h] [ebp-20h]
  CChoreoEvent *e; // [esp+18h] [ebp-1Ch]
  float *weights; // [esp+1Ch] [ebp-18h]
  float *settings; // [esp+20h] [ebp-14h]
  StudioModel *model; // [esp+24h] [ebp-10h]
  CExpression *exp; // [esp+28h] [ebp-Ch]
  float flIntensity; // [esp+2Ch] [ebp-8h]
  bool needundo; // [esp+33h] [ebp-1h]

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  v4 = SafeEvent;
  v5 = 0;
  e = SafeEvent;
  if ( SafeEvent != nullptr
    && CChoreoEvent::GetStartTime(this: SafeEvent) <= (double)scenetime
    && (double)scenetime <= CChoreoEvent::GetEndTime(this: v4) )
  {
    needundo = false;
    settings = nullptr;
    weights = nullptr;
    exp = nullptr;
    v6 = expressions->GetActiveClass(this: expressions);
    v7 = v6;
    if ( v6 != nullptr )
    {
      SelectedExpression = CExpClass::GetSelectedExpression(this: v6);
      if ( SelectedExpression != -1 )
      {
        Expression = CExpClass::GetExpression(this: v7, num: SelectedExpression);
        exp = Expression;
        if ( Expression != nullptr )
        {
          v10 = Expression;
          needundo = true;
          settings = CExpression::GetSettings(this: Expression);
          weights = CExpression::GetWeights(this: v10);
          CExpression::PushUndoInformation(this: v10);
          CExpClass::SetDirty(this: v7, dirty: true);
          v5 = 0;
        }
      }
    }
    FlexPanel::ResetSliders(this: g_pFlexPanel, preserveundo: false, bDirtyClass: true);
    model = models->GetActiveStudioModel(this: models);
    i = 0;
    if ( CChoreoEvent::GetNumFlexAnimationTracks(this: v4) > 0 )
    {
      do
      {
        FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: v4, index: v5);
        v12 = FlexAnimationTrack;
        if ( FlexAnimationTrack != nullptr && CFlexAnimationTrack::IsTrackActive(this: FlexAnimationTrack) )
        {
          v13 = 0;
          if ( CFlexAnimationTrack::IsComboType(this: v12) != -1 )
          {
            do
            {
              FlexControllerIndex = CFlexAnimationTrack::GetFlexControllerIndex(this: v12, side: v13);
              if ( FlexControllerIndex != -1 )
              {
                flIntensity = CFlexAnimationTrack::GetIntensity(this: v12, time: scenetime, side: v13);
                FlexPanel::SetSlider(this: g_pFlexPanel, iFlexController: FlexControllerIndex, value: flIntensity);
                FlexPanel::SetInfluence(this: g_pFlexPanel, iFlexController: FlexControllerIndex, value: 1.0);
                FlexPanel::SetEdited(this: g_pFlexPanel, iFlexController: FlexControllerIndex, isEdited);
                if ( model != nullptr )
                {
                  RawFlexControllerIndex = CFlexAnimationTrack::GetRawFlexControllerIndex(this: v12, side: v13);
                  if ( RawFlexControllerIndex != DUMMY_INVALID_FLEX_CONTROLLER )
                    StudioModel::SetFlexController(this: model, iFlex: RawFlexControllerIndex, flValue: flIntensity);
                }
                if ( settings != nullptr && weights != nullptr )
                {
                  settings[FlexControllerIndex] = flIntensity;
                  weights[FlexControllerIndex] = 1.0;
                }
              }
              ++v13;
            }
            while ( v13 < CFlexAnimationTrack::IsComboType(this: v12) + 1 );
            v5 = i;
          }
          v4 = e;
        }
        i = ++v5;
      }
      while ( v5 < CChoreoEvent::GetNumFlexAnimationTracks(this: v4) );
    }
    if ( needundo && exp != nullptr )
      CExpression::PushRedoInformation(this: exp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E9E0
// Name: public: void ExpressionTool::OnSetSingleKeyFromFlex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnSetSingleKeyFromFlex(ExpressionTool *this, const char *sliderName)
{
  CChoreoEvent *SafeEvent; // edi
  CChoreoScene *Scene; // eax
  int v4; // ebx
  const char *Label; // eax
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v7; // esi
  int v8; // edi
  int v9; // ebx
  float time; // xmm0_4
  CExpressionSample *Sample; // eax
  int v12; // esi
  float maxvalue; // [esp+1Ch] [ebp-28h] BYREF
  float minvalue; // [esp+20h] [ebp-24h] BYREF
  float setting; // [esp+24h] [ebp-20h]
  int j; // [esp+28h] [ebp-1Ch]
  float relativetime; // [esp+2Ch] [ebp-18h]
  int nSampleCount; // [esp+30h] [ebp-14h]
  int i; // [esp+34h] [ebp-10h]
  CChoreoEvent *e; // [esp+38h] [ebp-Ch]
  float normalized; // [esp+3Ch] [ebp-8h]
  bool found; // [esp+43h] [ebp-1h]

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  e = SafeEvent;
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    normalized = CChoreoScene::GetTime(this: Scene);
    if ( CChoreoEvent::GetStartTime(this: SafeEvent) <= (double)normalized
      && (double)normalized <= CChoreoEvent::GetEndTime(this: SafeEvent) )
    {
      normalized = FacePoser_SnapTime(t: normalized);
      relativetime = normalized - CChoreoEvent::GetStartTime(this: SafeEvent);
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set Single Key");
      v4 = 0;
      j = 0;
      do
      {
        if ( FlexPanel::IsValidSlider(this: g_pFlexPanel, iFlexController: v4) )
        {
          Label = mxWidget::getLabel(this: g_pFlexPanel);
          if ( _V_stricmp(s1: Label, s2: sliderName) == 0 )
          {
            setting = FlexPanel::GetSliderRawValue(this: g_pFlexPanel, iFlexController: v4);
            FlexPanel::GetInfluence(this: g_pFlexPanel, iFlexController: v4);
            FlexPanel::GetSliderRange(this: g_pFlexPanel, iFlexController: v4, &minvalue, &maxvalue);
            found = false;
            i = 0;
            if ( CChoreoEvent::GetNumFlexAnimationTracks(this: SafeEvent) > 0 )
            {
              do
              {
                if ( found )
                  break;
                FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: SafeEvent, index: i);
                v7 = FlexAnimationTrack;
                if ( FlexAnimationTrack != nullptr )
                {
                  v8 = 0;
                  if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) != -1 )
                  {
                    while ( CFlexAnimationTrack::GetFlexControllerIndex(this: v7, side: v8) != v4 )
                    {
                      if ( ++v8 >= CFlexAnimationTrack::IsComboType(this: v7) + 1 )
                        goto LABEL_28;
                    }
                    normalized = setting;
                    if ( v8 == 0 )
                    {
                      if ( minvalue != maxvalue )
                        normalized = (float)(setting - minvalue) / (float)(maxvalue - minvalue);
                      if ( CFlexAnimationTrack::IsInverted(this: v7) )
                        normalized = 1.0 - normalized;
                    }
                    found = true;
                    v9 = 0;
                    nSampleCount = CFlexAnimationTrack::GetNumSamples(this: v7, type: v8);
                    if ( nSampleCount <= 0 )
                      goto LABEL_25;
                    while ( 1 )
                    {
                      time = CFlexAnimationTrack::GetSample(this: v7, index: v9, type: v8)->time;
                      if ( time == relativetime )
                        break;
                      if ( ++v9 >= nSampleCount )
                        goto LABEL_25;
                    }
                    if ( v9 < nSampleCount )
                    {
                      Sample = CFlexAnimationTrack::GetSample(this: v7, index: v9, type: v8);
                      Sample->value = normalized;
                    }
                    else
                    {
LABEL_25:
                      CFlexAnimationTrack::AddSample(this: v7, time: relativetime, value: normalized, type: v8);
                      CFlexAnimationTrack::Resort(this: v7, type: v8);
                    }
                    CFlexAnimationTrack::SetTrackActive(this: v7, active: true);
                    v4 = j;
                  }
LABEL_28:
                  SafeEvent = e;
                }
                v12 = ++i;
              }
              while ( v12 < CChoreoEvent::GetNumFlexAnimationTracks(this: SafeEvent) );
            }
          }
        }
        j = ++v4;
      }
      while ( v4 < 384 );
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set Single Key");
      this->m_pWorkspace->redraw(this: this->m_pWorkspace);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044ECB0
// Name: public: void ExpressionTool::OnCopyFromFlex(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnCopyFromFlex(ExpressionTool *this, float scenetime, bool isEdited)
{
  CChoreoEvent *SafeEvent; // edi
  int j; // ebx
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v6; // esi
  int v7; // edi
  float value; // xmm0_4
  int v9; // esi
  float relativetime; // [esp+1Ch] [ebp-1Ch]
  float maxvalue; // [esp+20h] [ebp-18h] BYREF
  float minvalue; // [esp+24h] [ebp-14h] BYREF
  float setting; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  CChoreoEvent *e; // [esp+30h] [ebp-8h]
  float normalized; // [esp+34h] [ebp-4h]
  float found; // [esp+40h] [ebp+8h]
  float founda; // [esp+40h] [ebp+8h]
  char found_3; // [esp+43h] [ebp+Bh]

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  e = SafeEvent;
  if ( SafeEvent != nullptr
    && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0
    && CChoreoEvent::GetStartTime(this: SafeEvent) <= (double)scenetime
    && (double)scenetime <= CChoreoEvent::GetEndTime(this: SafeEvent) )
  {
    found = FacePoser_SnapTime(t: scenetime);
    relativetime = found - CChoreoEvent::GetStartTime(this: SafeEvent);
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Copy from Flex");
    for ( j = 0; j < 384; ++j )
    {
      if ( FlexPanel::IsValidSlider(this: g_pFlexPanel, iFlexController: j) )
      {
        setting = FlexPanel::GetSliderRawValue(this: g_pFlexPanel, iFlexController: j);
        founda = FlexPanel::GetInfluence(this: g_pFlexPanel, iFlexController: j);
        FlexPanel::SetEdited(this: g_pFlexPanel, iFlexController: j, isEdited);
        FlexPanel::GetSliderRange(this: g_pFlexPanel, iFlexController: j, &minvalue, &maxvalue);
        if ( founda != 0.0 )
        {
          found_3 = 0;
          i = 0;
          if ( CChoreoEvent::GetNumFlexAnimationTracks(this: SafeEvent) > 0 )
          {
            do
            {
              if ( found_3 != 0 )
                break;
              FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: SafeEvent, index: i);
              v6 = FlexAnimationTrack;
              if ( FlexAnimationTrack != nullptr )
              {
                v7 = 0;
                if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) != -1 )
                {
                  while ( CFlexAnimationTrack::GetFlexControllerIndex(this: v6, side: v7) != j )
                  {
                    if ( ++v7 >= CFlexAnimationTrack::IsComboType(this: v6) + 1 )
                      goto LABEL_22;
                  }
                  value = setting;
                  normalized = setting;
                  if ( v7 == 0 )
                  {
                    if ( minvalue != maxvalue )
                      normalized = (float)(setting - minvalue) / (float)(maxvalue - minvalue);
                    if ( CFlexAnimationTrack::IsInverted(this: v6) )
                      value = 1.0 - normalized;
                    else
                      value = normalized;
                  }
                  found_3 = 1;
                  CFlexAnimationTrack::AddSample(this: v6, time: relativetime, value, type: v7);
                  CFlexAnimationTrack::Resort(this: v6, type: v7);
                  CFlexAnimationTrack::SetTrackActive(this: v6, active: true);
                }
LABEL_22:
                SafeEvent = e;
              }
              v9 = ++i;
            }
            while ( v9 < CChoreoEvent::GetNumFlexAnimationTracks(this: SafeEvent) );
          }
        }
      }
    }
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Copy from Flex");
    this->m_pWorkspace->redraw(this: this->m_pWorkspace);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EF20
// Name: public: bool ExpressionTool::SetFlexAnimationTrackFromExpression(int,int,class CExpClass __near *,class CExpression __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ExpressionTool::SetFlexAnimationTrackFromExpression(
        ExpressionTool *this,
        int mx,
        int my,
        CExpClass *cl,
        CExpression *exp)
{
  ExpressionTool *v5; // esi
  CChoreoEvent *SafeEvent; // edi
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // edx
  HWND Handle; // eax
  int v10; // eax
  int v11; // eax
  float *Settings; // ebx
  float *Weights; // eax
  CFlexAnimationTrack *FlexAnimationTrack; // eax
  CFlexAnimationTrack *v15; // esi
  int FlexControllerIndex; // edi
  int v17; // eax
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  int v22; // ecx
  tagPOINT pt; // [esp+18h] [ebp-14h] BYREF
  ExpressionTool *v24; // [esp+20h] [ebp-Ch]
  CChoreoEvent *e; // [esp+24h] [ebp-8h]
  float *influence; // [esp+28h] [ebp-4h]
  float relativetime; // [esp+34h] [ebp+8h]
  float ia; // [esp+38h] [ebp+Ch]
  int i; // [esp+38h] [ebp+Ch]
  float leftright; // [esp+40h] [ebp+14h]

  v5 = this;
  v24 = this;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  GetDuration = SafeEvent->GetDuration;
  e = SafeEvent;
  if ( ((double (__thiscall *)(CChoreoEvent *))GetDuration)(a1: SafeEvent) == 0.0 )
    return 0;
  if ( exp == nullptr )
    return 0;
  pt.y = my;
  pt.x = mx;
  Handle = (HWND)mxWidget::getHandle(this: v5);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  if ( pt.x < 0 )
    return 0;
  if ( pt.y < 0 )
    return 0;
  v10 = mxWidget::w2(this: v5);
  if ( pt.x > v10 )
    return 0;
  v11 = mxWidget::h2(this: v5);
  if ( pt.y > v11 )
    return 0;
  relativetime = ExpressionTool::GetTimeValueForMouse(this: v5, mx: SLOWORD(pt.x), clip: false);
  ia = CChoreoEvent::GetStartTime(this: SafeEvent) + relativetime;
  FacePoser_SnapTime(t: ia);
  Settings = CExpression::GetSettings(this: exp);
  Weights = CExpression::GetWeights(this: exp);
  influence = Weights;
  if ( Settings == nullptr || Weights == nullptr )
    return 0;
  CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
  CChoreoView::PushUndo(this: g_pChoreoView, description: "Copy from Expression");
  i = 0;
  if ( CChoreoEvent::GetNumFlexAnimationTracks(this: SafeEvent) > 0 )
  {
    do
    {
      FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: SafeEvent, index: i);
      v15 = FlexAnimationTrack;
      if ( FlexAnimationTrack != nullptr )
      {
        if ( CFlexAnimationTrack::IsComboType(this: FlexAnimationTrack) )
        {
          FlexControllerIndex = CFlexAnimationTrack::GetFlexControllerIndex(this: v15, side: 0);
          v17 = CFlexAnimationTrack::GetFlexControllerIndex(this: v15, side: 1);
          v18 = influence[FlexControllerIndex];
          v19 = Settings[FlexControllerIndex];
          v20 = Settings[v17];
          if ( v18 != 0.0 || influence[v17] != 0.0 )
          {
            if ( v20 <= v19 )
            {
              v21 = Settings[FlexControllerIndex];
              if ( v19 <= v20 )
                leftright = 0.5;
              else
                leftright = (float)(v20 / v19) * 0.5;
            }
            else
            {
              v21 = Settings[v17];
              leftright = 1.0 - (float)((float)(v19 / v20) * 0.5);
            }
            CFlexAnimationTrack::AddSample(this: v15, time: relativetime, value: v21 * v18, type: 0);
            CFlexAnimationTrack::AddSample(this: v15, time: relativetime, value: leftright, type: 1);
            CFlexAnimationTrack::Resort(this: v15, type: 0);
            CFlexAnimationTrack::Resort(this: v15, type: 1);
            CFlexAnimationTrack::SetTrackActive(this: v15, active: true);
          }
          SafeEvent = e;
        }
        else
        {
          v22 = CFlexAnimationTrack::GetFlexControllerIndex(this: v15, side: 0);
          if ( influence[v22] != 0.0 )
          {
            CFlexAnimationTrack::AddSample(this: v15, time: relativetime, value: Settings[v22], type: 0);
            CFlexAnimationTrack::Resort(this: v15, type: 0);
            CFlexAnimationTrack::SetTrackActive(this: v15, active: true);
          }
        }
      }
      ++i;
    }
    while ( i < CChoreoEvent::GetNumFlexAnimationTracks(this: SafeEvent) );
    v5 = v24;
  }
  CChoreoView::PushRedo(this: g_pChoreoView, description: "Copy from Expression");
  v5->m_pWorkspace->redraw(this: v5->m_pWorkspace);
  v5->redraw(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044F220
// Name: private: void ExpressionTool::OnImportFlexAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnImportFlexAnimation(ExpressionTool *this)
{
  CChoreoEvent *SafeEvent; // edi
  const char *v3; // eax
  char fafilename[512]; // [esp+8h] [ebp-400h] BYREF
  char fullpath[512]; // [esp+208h] [ebp-200h] BYREF

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr
    && FacePoser_ShowOpenFileNameDialog(
         relative: fafilename,
         bufsize: 0x200u,
         subdir: "flexanimations",
         wildcard: "*.vfa")
    && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: fafilename, a3: nullptr) )
  {
    filesystem->RelativePathToFullPath(
      this: filesystem,
      a2: fafilename,
      a3: "MOD",
      a4: fullpath,
      a5: 512,
      a6: (PathTypeFilter_t)0,
      a7: nullptr);
    LoadScriptFile(filename: fullpath, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
    tokenprocessor->GetToken(this: tokenprocessor, a2: true);
    v3 = (const char *)tokenprocessor->CurrentToken(this: tokenprocessor);
    if ( _V_stricmp(s1: v3, s2: "flexanimations") != 0 )
    {
      Con_Printf(fmt: "ExpressionTool::OnImportFlexAnimation:  %s, expecting \"flexanimations\"\n", fullpath);
    }
    else
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Import flex animations");
      CChoreoScene::ParseFlexAnimations(tokenizer: tokenprocessor, e: SafeEvent, removeold: true);
      this->m_pLastEvent = nullptr;
      ExpressionTool::SetEvent(this, event: SafeEvent);
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Import flex animations");
      Con_Printf(fmt: "Parsed flex animations from %s\n", fullpath);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F380
// Name: public: void ExpressionTool::DrawScrubHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawScrubHandles(ExpressionTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-78h] BYREF
  tagRECT rcHandle; // [esp+5Ch] [ebp-20h] BYREF
  tagRECT rcTray; // [esp+6Ch] [ebp-10h] BYREF

  ExpressionTool::GetScrubHandleRect(this, &rcHandle, clipped: true);
  rcTray.top = rcHandle.top;
  *(_QWORD *)&rcTray.right = *(_QWORD *)&rcHandle.right;
  rcTray.left = 0;
  rcTray.right = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcTray);
  ExpressionTool::DrawScrubHandle(this, (CChoreoEvent *)&drawHelper, rcHandle: COERCE_FLOAT(&rcHandle));
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0044F3F0
// Name: public: void ExpressionTool::DrawMouseOverPos(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawMouseOverPos(
        ExpressionTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcPos)
{
  int v4; // edi
  CChoreoEvent *SafeEvent; // eax
  double StartTime; // st7
  double v7; // st7
  int v8; // eax
  int v9; // edx
  int left; // ecx
  int v11; // edx
  const char *v12; // [esp+0h] [ebp-A8h]
  char sz[128]; // [esp+8h] [ebp-A0h] BYREF
  tagRECT rcText; // [esp+88h] [ebp-20h] BYREF
  int right; // [esp+98h] [ebp-10h] BYREF
  float st; // [esp+9Ch] [ebp-Ch] BYREF
  float ed; // [esp+A0h] [ebp-8h] BYREF
  float t; // [esp+A4h] [ebp-4h] BYREF

  v4 = this->m_nMousePos[0];
  ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&t, &right);
  ExpressionTool::GetStartAndEndTime(this, &st, &ed);
  t = (float)((float)((float)(v4 - LODWORD(t)) / (float)(right - LODWORD(t))) * (float)(ed - st)) + st;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
    t = StartTime + t;
    v7 = FacePoser_SnapTime(t);
    if ( t == v7 )
    {
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%.3f", t);
    }
    else
    {
      v12 = FacePoser_DescribeSnappedTime(t);
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s", v12);
    }
    v8 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)0xB, weight: 900, fmt: sz);
    v9 = rcPos->right;
    *(_QWORD *)&rcText.left = *(_QWORD *)&rcPos->left;
    left = rcPos->left;
    v11 = v9 - v8;
    *(_QWORD *)&rcText.right = *(_QWORD *)&rcPos->right;
    rcText.left = left;
    if ( left <= v11 )
      rcText.left = v11;
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
// Address: 0x0044F560
// Name: public: void ExpressionTool::DrawMouseOverPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawMouseOverPos(ExpressionTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-68h] BYREF
  tagRECT rcPos; // [esp+5Ch] [ebp-10h] BYREF

  rcPos.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
  rcPos.left = mxWidget::w2(this) - 200;
  rcPos.right = mxWidget::w2(this) - 5;
  rcPos.bottom = rcPos.top + 13;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcPos);
  ExpressionTool::DrawMouseOverPos(this, &drawHelper, &rcPos);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0044F5D0
// Name: private: bool ExpressionTool::IsMouseOverSelectionStartEdge(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsMouseOverSelectionStartEdge(ExpressionTool *this, mxEvent *event)
{
  int x_low; // edi
  int left; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  float ed; // [esp+10h] [ebp-8h] BYREF
  float v8; // [esp+14h] [ebp-4h]

  x_low = SLOWORD(event->x);
  if ( (event->modifiers & 1) == 0 || !ExpressionTool::IsMouseOverSelection(this, mx: x_low, my: SLOWORD(event->y)) )
    return false;
  v8 = this->m_flSelection[0];
  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  ExpressionTool::GetStartAndEndTime(this, st: (float *)&event, &ed);
  return (int)abs32(
                left
              + (int)(float)((float)((float)(v8 - *(float *)&event) / (float)(ed - *(float *)&event))
                           * (float)(right - left))
              - x_low) <= 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044F680
// Name: private: bool ExpressionTool::IsMouseOverSelectionEndEdge(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ExpressionTool::IsMouseOverSelectionEndEdge(ExpressionTool *this, mxEvent *event)
{
  int x_low; // edi
  int left; // [esp+8h] [ebp-10h] BYREF
  int right; // [esp+Ch] [ebp-Ch] BYREF
  float ed; // [esp+10h] [ebp-8h] BYREF
  float v8; // [esp+14h] [ebp-4h]

  x_low = SLOWORD(event->x);
  if ( (event->modifiers & 1) == 0 || !ExpressionTool::IsMouseOverSelection(this, mx: x_low, my: SLOWORD(event->y)) )
    return false;
  v8 = this->m_flSelection[1];
  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  ExpressionTool::GetStartAndEndTime(this, st: (float *)&event, &ed);
  return (int)abs32(
                left
              + (int)(float)((float)((float)(v8 - *(float *)&event) / (float)(ed - *(float *)&event))
                           * (float)(right - left))
              - x_low) <= 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044F730
// Name: private: int ExpressionTool::ComputeHPixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall ExpressionTool::ComputeHPixelsNeeded(ExpressionTool *this)
{
  IterateRIFF *result; // eax
  char *Name; // eax
  float maxtime; // [esp+4h] [ebp-4h]

  result = ExpressionTool::GetSafeEvent(this);
  if ( result != nullptr )
  {
    maxtime = ((double (__thiscall *)(IterateRIFF *))result->m_riff->m_io)(a1: result);
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    return (IterateRIFF *)(int)(float)((float)((float)((float)((float)CChoreoView::GetTimeZoom(
                                                                        this: g_pChoreoView,
                                                                        tool: Name)
                                                             * this->m_flPixelsPerSecond)
                                                     * 0.0099999998)
                                             * (float)(maxtime + 5.0))
                                     + 10.0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F7A0
// Name: public: void ExpressionTool::RepositionHSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::RepositionHSlider(ExpressionTool *this)
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

  SafeEvent = ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v12 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v3 = (int)(float)((float)((float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                            * this->m_flPixelsPerSecond)
                                    * 0.0099999998)
                            * (float)(v12 + 5.0))
                    + 10.0);
  }
  else
  {
    v3 = 0;
  }
  v5 = mxWidget::w2(this);
  mxWidget::setVisible(this: this->m_pHorzScrollBar, b: v3 > v5);
  m_nScrollbarHeight = this->m_nScrollbarHeight;
  v10 = mxWidget::w2(this);
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
// Address: 0x0044F8D0
// Name: public: float ExpressionTool::GetEventEndTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ExpressionTool::GetEventEndTime(ExpressionTool *this)
{
  IterateRIFF *SafeEvent; // eax

  SafeEvent = ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
    return ((float (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0044F8F0
// Name: public: void ExpressionTool::DrawEventEnd(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::DrawEventEnd(ExpressionTool *this, CChoreoWidgetDrawHelper *drawHelper)
{
  IterateRIFF *SafeEvent; // eax
  double v4; // st7
  int v5; // esi
  CChoreoWidgetDrawHelper *v6; // edi
  tagRECT rcClient; // [esp+4h] [ebp-24h] BYREF
  int left; // [esp+14h] [ebp-14h] BYREF
  int right; // [esp+18h] [ebp-10h] BYREF
  float ed; // [esp+1Ch] [ebp-Ch] BYREF
  float st; // [esp+20h] [ebp-8h] BYREF
  float duration; // [esp+24h] [ebp-4h]

  SafeEvent = ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v4 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    duration = v4;
    if ( v4 != 0.0 )
    {
      ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
      ExpressionTool::GetStartAndEndTime(this, &st, &ed);
      v5 = left + (int)(float)((float)((float)(duration - st) / (float)(ed - st)) * (float)(right - left));
      if ( v5 < mxWidget::w2(this) )
      {
        v6 = drawHelper;
        CChoreoWidgetDrawHelper::GetClientRect(this: drawHelper, rc: &rcClient);
        drawHelper = (CChoreoWidgetDrawHelper *)16711680;
        CChoreoWidgetDrawHelper::DrawColoredLine(
          this: v6,
          clr: (HPEN__ *)&drawHelper,
          style: 0,
          width: 1,
          x1: v5,
          y1: rcClient.top + 55,
          x2: v5,
          y2: rcClient.bottom);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F9C0
// Name: private: void ExpressionTool::OnSortByUsed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnSortByUsed(ExpressionTool *this)
{
  CExpressionToolWorkspace *m_pWorkspace; // esi

  m_pWorkspace = this->m_pWorkspace;
  qsort(
    base: m_pWorkspace->m_pItems,
    num: 0x180u,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))SortFuncByUse);
  CExpressionToolWorkspace::LayoutItems(this: m_pWorkspace, force: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044F9F0
// Name: private: void ExpressionTool::OnSortByName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnSortByName(ExpressionTool *this)
{
  CExpressionToolWorkspace *m_pWorkspace; // esi

  m_pWorkspace = this->m_pWorkspace;
  qsort(
    base: m_pWorkspace->m_pItems,
    num: 0x180u,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))SortFuncByName);
  CExpressionToolWorkspace::LayoutItems(this: m_pWorkspace, force: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044FA20
// Name: public: float ExpressionTool::GetScrubberSceneTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ExpressionTool::GetScrubberSceneTime(ExpressionTool *this)
{
  CChoreoEvent *SafeEvent; // eax
  float curtime; // [esp+4h] [ebp-4h]

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent == nullptr )
    return 0.0;
  curtime = this->m_flScrub;
  return CChoreoEvent::GetStartTime(this: SafeEvent) + curtime;
}

//------------------------------------------------------------------------------
// Address: 0x00450540
// Name: public: void CExpressionToolWorkspace::DrawEventEnd(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::DrawEventEnd(
        CExpressionToolWorkspace *this,
        CChoreoWidgetDrawHelper *drawHelper)
{
  IterateRIFF *SafeEvent; // eax
  double v4; // st7
  ExpressionTool *v5; // esi
  int v6; // esi
  CChoreoWidgetDrawHelper *v7; // edi
  tagRECT rcClient; // [esp+4h] [ebp-24h] BYREF
  int left; // [esp+14h] [ebp-14h] BYREF
  int right; // [esp+18h] [ebp-10h] BYREF
  float ed; // [esp+1Ch] [ebp-Ch] BYREF
  float st; // [esp+20h] [ebp-8h] BYREF
  float duration; // [esp+24h] [ebp-4h]

  if ( g_pExpressionTool != nullptr )
  {
    SafeEvent = ExpressionTool::GetSafeEvent(this: g_pExpressionTool);
    if ( SafeEvent != nullptr )
    {
      v4 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      duration = v4;
      if ( v4 != 0.0 )
      {
        v5 = g_pExpressionTool;
        ExpressionTool::GetWorkspaceLeftRight(this: g_pExpressionTool, &left, &right);
        ExpressionTool::GetStartAndEndTime(this: v5, &st, &ed);
        v6 = (int)(float)((float)((float)(duration - st) / (float)(ed - st)) * (float)(right - left)) + left - 5;
        if ( v6 < mxWidget::w2(this) )
        {
          v7 = drawHelper;
          CChoreoWidgetDrawHelper::GetClientRect(this: drawHelper, rc: &rcClient);
          drawHelper = (CChoreoWidgetDrawHelper *)16711680;
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: v7,
            clr: (HPEN__ *)&drawHelper,
            style: 0,
            width: 1,
            x1: v6,
            y1: rcClient.top,
            x2: v6,
            y2: rcClient.bottom);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450620
// Name: public: virtual int CExpressionToolWorkspace::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionToolWorkspace::handleEvent(CExpressionToolWorkspace *this, int event)
{
  IMDLCache *m_pCache; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  mxEvent *v5; // edi
  int v6; // eax
  mxWindow *Parent; // eax
  HWND v8; // ebx
  int y_low; // edx
  ExpressionTool *v10; // eax
  int v11; // ecx
  int v12; // edx
  ExpressionTool *v13; // eax
  unsigned int v14; // ebx
  unsigned int ItemUnderMouse; // eax
  TimelineItem *Item; // eax
  unsigned int v17; // eax
  TimelineItem *v18; // esi
  int left; // edx
  unsigned int v20; // eax
  TimelineItem *v21; // ebx
  int v22; // edx
  int v23; // eax
  bool v24; // zf
  int v25; // edx
  ExpressionTool *v26; // eax
  int v27; // ecx
  int x_low; // eax
  ExpressionTool *v29; // eax
  int v30; // edx
  int v31; // ecx
  ExpressionTool *v32; // eax
  int v33; // edx
  unsigned int m_nFocusItem; // eax
  TimelineItem *v35; // esi
  int top; // edx
  char *Name; // eax
  int TimeZoom; // eax
  int v39; // eax
  char *v40; // eax
  mxScrollbar *m_pVertScrollBar; // ecx
  int v43; // edi
  int MaxValue; // eax
  HWND v45; // eax
  int v46; // edi
  int MinValue; // eax
  HWND Handle; // eax
  int v49; // [esp-8h] [ebp-30h]
  tagRECT rc; // [esp+Ch] [ebp-1Ch] BYREF
  int v51; // [esp+1Ch] [ebp-Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+20h] [ebp-8h]
  int my; // [esp+24h] [ebp-4h] BYREF

  m_pCache = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  v5 = (mxEvent *)event;
  v6 = *(_DWORD *)(event + 4);
  my = 0;
  switch ( v6 )
  {
    case 0:
      v24 = *(_DWORD *)(event + 12) == 1000;
      my = 1;
      if ( v24 )
      {
        switch ( *(_DWORD *)(event + 40) )
        {
          case 0:
            v46 = mxScrollbar::getValue(this: this->m_pVertScrollBar) - 10;
            goto LABEL_47;
          case 1:
            v46 = mxScrollbar::getValue(this: this->m_pVertScrollBar) + 10;
            goto LABEL_43;
          case 2:
            v46 = mxScrollbar::getValue(this: this->m_pVertScrollBar) - 100;
LABEL_47:
            if ( v46 > mxScrollbar::getMinValue(this: this->m_pVertScrollBar) )
              goto LABEL_50;
            MinValue = mxScrollbar::getMinValue(this: this->m_pVertScrollBar);
            goto LABEL_49;
          case 3:
            v46 = mxScrollbar::getValue(this: this->m_pVertScrollBar) + 100;
LABEL_43:
            if ( v46 >= mxScrollbar::getMaxValue(this: this->m_pVertScrollBar) )
            {
              MinValue = mxScrollbar::getMaxValue(this: this->m_pVertScrollBar);
LABEL_49:
              v46 = MinValue;
            }
LABEL_50:
            mxScrollbar::setValue(this: this->m_pVertScrollBar, ivalue: v46);
            Handle = (HWND)mxWidget::getHandle(this: this->m_pVertScrollBar);
            InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
            this->m_nTopOffset = v46;
            CExpressionToolWorkspace::LayoutItems(this, force: false);
            break;
          case 5:
            v46 = *(_DWORD *)(event + 20);
            goto LABEL_50;
          default:
            goto LABEL_51;
        }
      }
      else
      {
        my = 0;
      }
      goto LABEL_51;
    case 1:
      CExpressionToolWorkspace::RepositionVSlider(this);
      goto LABEL_20;
    case 6:
      v31 = *(__int16 *)(event + 28);
      event = *(__int16 *)(event + 24);
      v51 = v31;
      CExpressionToolWorkspace::MouseToToolMouse(this, mx: &event, my: &v51, reason: "CExpressionToolWorkspace mouseup");
      v32 = g_pExpressionTool;
      v33 = v51;
      g_pExpressionTool->m_nMousePos[0] = event;
      v32->m_nMousePos[1] = v33;
      ExpressionTool::DrawMouseOverPos(this: g_pExpressionTool);
      m_nFocusItem = this->m_nFocusItem;
      if ( m_nFocusItem < 0x180 )
      {
        v35 = this->m_pItems[m_nFocusItem];
        if ( v35 != nullptr )
        {
          TimelineItem::GetBounds(this: v35, rect: &rc);
          top = rc.top;
          v5->x -= rc.left;
          v5->y -= top;
          my = v35->handleEvent(this: v35, a2: v5);
        }
      }
      goto LABEL_51;
    case 7:
      Parent = mxWidget::getParent(this);
      v8 = (HWND)mxWidget::getHandle(this: Parent);
      SetFocus(hWnd: v8);
      SetWindowPos(hWnd: v8, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
      y_low = SLOWORD(v5->y);
      event = SLOWORD(v5->x);
      my = y_low;
      CExpressionToolWorkspace::MouseToToolMouse(this, mx: &event, &my, reason: "CExpressionToolWorkspace mousedown");
      v10 = g_pExpressionTool;
      v11 = event;
      v12 = my;
      g_pExpressionTool->m_nClickedX = event;
      v10->m_nClickedY = v12;
      v13 = g_pExpressionTool;
      g_pExpressionTool->m_nMousePos[0] = v11;
      v13->m_nMousePos[1] = v12;
      ExpressionTool::DrawMouseOverPos(this: g_pExpressionTool);
      v14 = this->m_nFocusItem;
      ItemUnderMouse = CExpressionToolWorkspace::GetItemUnderMouse(this, mx: SLOWORD(v5->x), my: SLOWORD(v5->y));
      this->m_nFocusItem = ItemUnderMouse;
      if ( v14 != -1 && v14 != ItemUnderMouse )
      {
        Item = CExpressionToolWorkspace::GetItem(this, number: v14);
        if ( Item != nullptr )
          TimelineItem::DrawSelf(this: Item);
      }
      v17 = this->m_nFocusItem;
      if ( v17 < 0x180 )
      {
        v18 = this->m_pItems[v17];
        if ( v18 != nullptr )
        {
          TimelineItem::GetBounds(this: v18, rect: &rc);
          left = rc.left;
          v5->y -= rc.top;
          v5->x -= left;
          v18->handleEvent(this: v18, a2: v5);
        }
      }
      m_pCache = cacheCriticalSection.m_pCache;
      my = 1;
      goto LABEL_51;
    case 8:
    case 9:
      v20 = this->m_nFocusItem;
      if ( v20 >= 0x180 )
        goto LABEL_15;
      v21 = this->m_pItems[v20];
      if ( v21 != nullptr
        && (TimelineItem::GetBounds(this: v21, rect: &rc),
            v22 = rc.left,
            v5->y -= rc.top,
            v5->x -= v22,
            v23 = v21->handleEvent(this: v21, a2: v5),
            v24 = v5->event == 9,
            my = v23,
            v24) )
      {
        v25 = rc.top + v21->m_nLastY;
        event = rc.left + v21->m_nLastX;
        v51 = v25;
        CExpressionToolWorkspace::MouseToToolMouse(
          this,
          mx: &event,
          my: &v51,
          reason: "CExpressionToolWorkspace mousedrag");
        v26 = g_pExpressionTool;
        v27 = v51;
        g_pExpressionTool->m_nMousePos[0] = event;
        v26->m_nMousePos[1] = v27;
        ExpressionTool::DrawMouseOverPos(this: g_pExpressionTool);
        m_pCache = cacheCriticalSection.m_pCache;
      }
      else
      {
        m_pCache = cacheCriticalSection.m_pCache;
LABEL_15:
        x_low = SLOWORD(v5->x);
        v51 = SLOWORD(v5->y);
        event = x_low + 10;
        CExpressionToolWorkspace::MouseToToolMouse(
          this,
          mx: &event,
          my: &v51,
          reason: "CExpressionToolWorkspace mousemove");
        v29 = g_pExpressionTool;
        v30 = v51;
        g_pExpressionTool->m_nMousePos[0] = event;
        v29->m_nMousePos[1] = v30;
        ExpressionTool::DrawMouseOverPos(this: g_pExpressionTool);
      }
      goto LABEL_51;
    case 12:
      if ( (*(_BYTE *)(event + 40) & 2) != 0 )
      {
        if ( CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
        {
          Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&g_pExpressionTool->IFacePoserToolWindow);
          TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
          if ( v5->height <= 0 )
            v39 = TimeZoom - 2;
          else
            v39 = TimeZoom + 2;
          if ( v39 >= 1000 )
            v39 = 1000;
          v49 = v39;
          v40 = CChoreoChannel::GetName(this: (CChoreoChannel *)&g_pExpressionTool->IFacePoserToolWindow);
          CChoreoView::SetTimeZoom(this: g_pChoreoView, tool: v40, tz: v49, preserveFocus: false);
          ExpressionTool::RepositionHSlider(this: g_pExpressionTool);
        }
        this->redraw(this);
        m_pCache->EndLock(this: m_pCache);
        return 1;
      }
      m_pVertScrollBar = this->m_pVertScrollBar;
      if ( *(int *)(event + 20) >= 0 )
      {
        v43 = mxScrollbar::getValue(this: m_pVertScrollBar) - 50;
        if ( v43 > mxScrollbar::getMinValue(this: this->m_pVertScrollBar) )
          goto LABEL_36;
        MaxValue = mxScrollbar::getMinValue(this: this->m_pVertScrollBar);
      }
      else
      {
        v43 = mxScrollbar::getValue(this: m_pVertScrollBar) + 50;
        if ( v43 < mxScrollbar::getMaxValue(this: this->m_pVertScrollBar) )
          goto LABEL_36;
        MaxValue = mxScrollbar::getMaxValue(this: this->m_pVertScrollBar);
      }
      v43 = MaxValue;
LABEL_36:
      mxScrollbar::setValue(this: this->m_pVertScrollBar, ivalue: v43);
      v45 = (HWND)mxWidget::getHandle(this: this->m_pVertScrollBar);
      InvalidateRect(hWnd: v45, lpRect: nullptr, bErase: true);
      this->m_nTopOffset = v43;
LABEL_20:
      CExpressionToolWorkspace::LayoutItems(this, force: false);
      my = 1;
LABEL_51:
      m_pCache->EndLock(this: m_pCache);
      return my;
    default:
      goto LABEL_51;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450B40
// Name: public: void CExpressionToolWorkspace::OnDeleteColumn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::OnDeleteColumn(CExpressionToolWorkspace *this)
{
  int SceneFPS; // eax
  char *v3; // eax
  char *v4; // edi
  int v5; // esi
  int v6; // eax
  float v7; // xmm1_4
  float v8; // xmm1_4
  int v9; // esi
  TimelineItem **m_pItems; // edi
  TimelineItem *v11; // ecx
  CInputParams params; // [esp+14h] [ebp-598h] BYREF
  float epsilon; // [esp+5A0h] [ebp-Ch]
  float end; // [esp+5A4h] [ebp-8h]
  float start; // [esp+5A8h] [ebp-4h]

  start = ExpressionTool::GetTimeForClickedPos(this: g_pExpressionTool);
  end = FacePoser_SnapTime(t: start);
  SceneFPS = FacePoser_GetSceneFPS();
  if ( SceneFPS > 0 )
  {
    start = (float)SceneFPS;
    epsilon = 0.5 / (float)SceneFPS;
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Delete Column");
    strcpy(params.m_szPrompt, "Frame(s) to delete [e.g., 82 or 81-91 ]:");
    V_snprintf(pDest: params.m_szInputText, maxLen: 1024, pFormat: "%i", (int)(float)((float)(start * end) + 0.5));
    if ( InputProperties(&params) != 0 )
    {
      v3 = _V_strstr(s1: params.m_szInputText, search: "-");
      v4 = v3;
      if ( v3 != nullptr )
      {
        *v3 = 0;
        v5 = atoi(nptr: params.m_szInputText);
        v6 = atoi(nptr: v4 + 1);
        if ( v5 > v6 )
          v6 = v5;
      }
      else
      {
        v6 = atoi(nptr: params.m_szInputText);
        v5 = v6;
      }
      v7 = start;
      start = (float)v5 / start;
      end = (float)v6 / v7;
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: aDeleteC);
      v8 = epsilon;
      epsilon = end + epsilon;
      v9 = 0;
      end = start - v8;
      m_pItems = this->m_pItems;
      do
      {
        if ( (unsigned int)v9 > 0x17F )
          v11 = nullptr;
        else
          v11 = *m_pItems;
        TimelineItem::DeletePoints(this: v11, start: end, end: epsilon);
        ++v9;
        ++m_pItems;
      }
      while ( v9 < 384 );
      CChoreoView::PushRedo(this: g_pChoreoView, description: aDeleteC);
      this->redraw(this);
    }
  }
  else
  {
    Con_Printf(fmt: "Can't delete column, scene fps is <= 0 (%i)\n", SceneFPS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450DA0
// Name: public: void CExpressionToolWorkspace::MoveSelectedSamples(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::MoveSelectedSamples(
        CExpressionToolWorkspace *this,
        float dfdx,
        float dfdy,
        bool snap)
{
  IterateRIFF *SafeEvent; // eax
  int v6; // esi
  TimelineItem **m_pItems; // edi
  CFlexAnimationTrack *SafeTrack; // eax
  CFlexAnimationTrack *v9; // edi
  int v10; // esi
  int v11; // ebx
  CExpressionSample *Sample; // eax
  float *p_value; // esi
  float t; // xmm0_4
  int v15; // xmm1_4
  float v16; // xmm0_4
  TimelineItem *item; // [esp+10h] [ebp-14h]
  float eventduration; // [esp+14h] [ebp-10h]
  TimelineItem **v19; // [esp+18h] [ebp-Ch]
  int controller; // [esp+1Ch] [ebp-8h]
  int edittype; // [esp+20h] [ebp-4h]

  if ( CExpressionToolWorkspace::CountSelectedSamples(this) != 0 )
  {
    SafeEvent = ExpressionTool::GetSafeEvent(this: g_pExpressionTool);
    if ( SafeEvent != nullptr )
    {
      eventduration = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      v6 = 0;
      m_pItems = this->m_pItems;
      controller = 0;
      v19 = m_pItems;
      do
      {
        if ( (unsigned int)v6 <= 0x17F )
        {
          item = *m_pItems;
          if ( *m_pItems != nullptr )
          {
            SafeTrack = TimelineItem::GetSafeTrack(this: *m_pItems);
            v9 = SafeTrack;
            if ( SafeTrack != nullptr )
            {
              v10 = 0;
              edittype = 0;
              CFlexAnimationTrack::IsComboType(this: SafeTrack);
              do
              {
                v11 = 0;
                if ( CFlexAnimationTrack::GetNumSamples(this: v9, type: v10) > 0 )
                {
                  do
                  {
                    Sample = CFlexAnimationTrack::GetSample(this: v9, index: v11, type: v10);
                    p_value = &Sample->value;
                    if ( Sample != nullptr && (*((_BYTE *)Sample + 8) & 1) != 0 )
                    {
                      t = dfdx + Sample->time;
                      v15 = 0;
                      Sample->time = t;
                      if ( t >= 0.0 )
                      {
                        if ( t > eventduration )
                          t = eventduration;
                      }
                      else
                      {
                        t = 0.0;
                      }
                      Sample->time = t;
                      if ( snap )
                      {
                        Sample->time = FacePoser_SnapTime(t);
                        v15 = 0;
                      }
                      v16 = *p_value - dfdy;
                      *p_value = v16;
                      if ( v16 < 0.0 || (v15 = 1065353216, v16 > 1.0) )
                        v16 = *(float *)&v15;
                      *p_value = v16;
                    }
                    ++v11;
                    v10 = edittype;
                  }
                  while ( v11 < CFlexAnimationTrack::GetNumSamples(this: v9, type: edittype) );
                }
                edittype = ++v10;
              }
              while ( v10 <= CFlexAnimationTrack::IsComboType(this: v9) );
              CFlexAnimationTrack::Resort(this: v9, type: 0);
              TimelineItem::DrawSelf(this: item);
              v6 = controller;
            }
          }
        }
        ++v6;
        m_pItems = v19 + 1;
        controller = v6;
        ++v19;
      }
      while ( v6 < 384 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450F30
// Name: public: virtual void ExpressionTool::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ExpressionTool::Think(ExpressionTool *this@<ecx>, int a2@<edi>, float dt)
{
  char v4; // al

  if ( ExpressionTool::GetSafeEvent(this: (ExpressionTool *)((char *)this - 12)) != nullptr )
  {
    v4 = ((int (__thiscall *)(ExpressionTool *))this->redraw)(a1: this);
    ExpressionTool::ScrubThink(this: (ExpressionTool *)((char *)this - 12), a2, dt, scrubbing: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450F70
// Name: public: virtual void ExpressionTool::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::redraw(ExpressionTool *this)
{
  HWND Handle; // eax
  int v3; // eax
  int v4; // eax
  CChoreoEvent *SafeEvent; // edi
  int v6; // eax
  const char *Name; // eax
  double StartTime; // st7
  double v9; // st7
  int v10; // edi
  int v11; // edi
  int bottom; // [esp+8h] [ebp-104h]
  tagRECT rcHandle; // [esp+18h] [ebp-F4h] BYREF
  char sz[32]; // [esp+28h] [ebp-E4h] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+48h] [ebp-C4h] BYREF
  tagRECT rcUndo; // [esp+A0h] [ebp-6Ch] BYREF
  int left; // [esp+B0h] [ebp-5Ch] BYREF
  float v18; // [esp+B4h] [ebp-58h] BYREF
  float v19; // [esp+B8h] [ebp-54h]
  int v20; // [esp+BCh] [ebp-50h] BYREF
  int right; // [esp+C0h] [ebp-4Ch] BYREF
  float v22; // [esp+C4h] [ebp-48h] BYREF
  tagRECT timeRect; // [esp+C8h] [ebp-44h] BYREF
  tagRECT rcSelection; // [esp+D8h] [ebp-34h] BYREF
  int current; // [esp+E8h] [ebp-24h] BYREF
  tagRECT rcText; // [esp+ECh] [ebp-20h] BYREF
  int total; // [esp+FCh] [ebp-10h] BYREF
  float ed; // [esp+100h] [ebp-Ch] BYREF
  Color areaBorder; // [esp+104h] [ebp-8h] BYREF
  HPEN__ st; // [esp+108h] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) )
  {
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &drawHelper);
    areaBorder = (Color)14477030;
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rcSelection);
    rcSelection.top = 38;
    rcSelection.bottom = 54;
    v3 = mxWidget::w2(this);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: &drawHelper,
      clr: (HPEN__ *)&areaBorder,
      style: 0,
      width: 1,
      x1: 0,
      y1: rcSelection.top,
      x2: v3,
      y2: 38);
    bottom = rcSelection.bottom;
    v4 = mxWidget::w2(this);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: &drawHelper,
      clr: (HPEN__ *)&areaBorder,
      style: 0,
      width: 1,
      x1: 0,
      y1: rcSelection.bottom,
      x2: v4,
      y2: bottom);
    if ( this->m_bSelectionActive )
    {
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcUndo);
      ed = this->m_flSelection[0];
      ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
      ExpressionTool::GetStartAndEndTime(this, st: (float *)&total, ed: (float *)&st.unused);
      v19 = this->m_flSelection[1];
      ExpressionTool::GetWorkspaceLeftRight(this, left: &current, right: &v20);
      ExpressionTool::GetStartAndEndTime(this, st: &v18, ed: &v22);
      rcSelection.left = left
                       + (int)(float)((float)((float)(ed - *(float *)&total)
                                            / (float)(*(float *)&st.unused - *(float *)&total))
                                    * (float)(right - left));
      rcSelection.right = current
                        + (int)(float)((float)((float)(v19 - v18) / (float)(v22 - v18)) * (float)(v20 - current));
      rcSelection.bottom = 55;
      *(float *)&st.unused = 2.1201366e-38;
      CChoreoWidgetDrawHelper::DrawFilledRect(this: &drawHelper, clr: (const Color *)&st, rc: &rcSelection);
      *(float *)&st.unused = 2.3454065e-38;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: &drawHelper,
        clr: &st,
        style: 0,
        width: 3,
        x1: rcSelection.left,
        y1: rcSelection.top,
        x2: rcSelection.left,
        y2: rcSelection.bottom);
      *(float *)&st.unused = 2.3454065e-38;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: &drawHelper,
        clr: &st,
        style: 0,
        width: 3,
        x1: rcSelection.right,
        y1: rcSelection.top,
        x2: rcSelection.right,
        y2: rcSelection.bottom);
    }
    SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
    if ( SafeEvent != nullptr )
    {
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcText);
      v6 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcText.top += v6 + 1;
      rcText.bottom = rcText.top + 13;
      rcText.left += 5;
      rcText.right -= 5;
      OffsetRect(lprc: &rcText, dx: 0, dy: 12);
      CChoreoView::GetUndoLevels(this: g_pChoreoView, &current, number: &total);
      if ( total > 0 )
      {
        rcUndo = rcText;
        OffsetRect(lprc: &rcUndo, dx: 0, dy: 2);
        st.unused = 25600;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: &drawHelper,
          font: "Small Fonts",
          pointsize: 8,
          weight: 400,
          clr: (const Color *)&st,
          rcText: &rcUndo,
          fmt: "Undo:  %i/%i",
          current,
          total);
      }
      rcText.left += 60;
      *(float *)&st.unused = COERCE_FLOAT((Vector *)&g_flexedverts[1267].y);
      Name = CChoreoEvent::GetName(this: SafeEvent);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 11,
        weight: 900,
        clr: (const Color *)&st,
        &rcText,
        fmt: "Event:  %s",
        Name);
      OffsetRect(lprc: &rcText, dx: 0, dy: 30);
      rcText.left = 5;
      *(_QWORD *)&timeRect.left = *(_QWORD *)&rcText.left;
      timeRect.bottom = rcText.bottom;
      timeRect.right = 105;
      ExpressionTool::GetStartAndEndTime(this, st: (float *)&st.unused, &ed);
      StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
      *(float *)&st.unused = StartTime + *(float *)&st.unused;
      v9 = CChoreoEvent::GetStartTime(this: SafeEvent);
      ed = v9 + ed;
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", *(float *)&st.unused);
      *(float *)&st.unused = 0.0;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&st,
        rcText: &timeRect,
        fmt: sz);
      timeRect = rcText;
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", ed);
      v10 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
      timeRect.right = mxWidget::w2(this) - 10;
      timeRect.left = timeRect.right - v10;
      *(float *)&st.unused = 0.0;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&st,
        rcText: &timeRect,
        fmt: sz);
    }
    ExpressionTool::GetScrubHandleRect(this, &rcHandle, clipped: true);
    ExpressionTool::DrawScrubHandle(this, (CChoreoEvent *)&drawHelper, rcHandle: COERCE_FLOAT(&rcHandle));
    ExpressionTool::DrawRelativeTags(this, &drawHelper);
    v11 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
    timeRect.top = v11;
    timeRect.left = mxWidget::w2(this) - 200;
    timeRect.right = mxWidget::w2(this) - 5;
    timeRect.bottom = v11 + 13;
    ExpressionTool::DrawMouseOverPos(this, &drawHelper, rcPos: &timeRect);
    ExpressionTool::DrawEventEnd(this, &drawHelper);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451420
// Name: public: void ExpressionTool::OnCopyToFlex(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnCopyToFlex(ExpressionTool *this, bool isEdited)
{
  int m_nClickedX; // edi
  CChoreoEvent *SafeEvent; // eax
  double StartTime; // st7
  float scenetime; // [esp+10h] [ebp-10h] BYREF
  float ed; // [esp+14h] [ebp-Ch] BYREF
  int right; // [esp+18h] [ebp-8h] BYREF
  int left; // [esp+1Ch] [ebp-4h] BYREF

  m_nClickedX = this->m_nClickedX;
  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  ExpressionTool::GetStartAndEndTime(this, st: &scenetime, &ed);
  scenetime = (float)((float)((float)(m_nClickedX - left) / (float)(right - left)) * (float)(ed - scenetime))
            + scenetime;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
    scenetime = StartTime + scenetime;
    ExpressionTool::OnCopyToFlex(this, scenetime, isEdited);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004514C0
// Name: public: void ExpressionTool::OnCopyFromFlex(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnCopyFromFlex(ExpressionTool *this, bool isEdited)
{
  int m_nClickedX; // edi
  CChoreoEvent *SafeEvent; // eax
  double StartTime; // st7
  float scenetime; // [esp+10h] [ebp-10h] BYREF
  float ed; // [esp+14h] [ebp-Ch] BYREF
  int right; // [esp+18h] [ebp-8h] BYREF
  int left; // [esp+1Ch] [ebp-4h] BYREF

  m_nClickedX = this->m_nClickedX;
  ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
  ExpressionTool::GetStartAndEndTime(this, st: &scenetime, &ed);
  scenetime = (float)((float)((float)(m_nClickedX - left) / (float)(right - left)) * (float)(ed - scenetime))
            + scenetime;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
    scenetime = StartTime + scenetime;
    ExpressionTool::OnCopyFromFlex(this, scenetime, isEdited);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451560
// Name: public: void ExpressionTool::ForceScrubPositionFromSceneTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::ForceScrubPositionFromSceneTime(ExpressionTool *this, float scenetime)
{
  CChoreoEvent *SafeEvent; // edi
  double v4; // st7

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    v4 = scenetime - CChoreoEvent::GetStartTime(this: SafeEvent);
    this->m_flScrub = v4;
    this->m_flScrubTarget = v4;
    ExpressionTool::DrawScrubHandles(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004515B0
// Name: public: void ExpressionTool::ForceScrubPosition(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge ExpressionTool::ForceScrubPosition(ExpressionTool *this@<ecx>, int a2@<edi>, float frac)
{
  CChoreoEvent *SafeEvent; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+8h] [ebp-78h] BYREF
  tagRECT rcHandle; // [esp+60h] [ebp-20h] BYREF
  tagRECT bounds; // [esp+70h] [ebp-10h] BYREF
  float realtime; // [esp+88h] [ebp+8h]

  this->m_flScrub = frac;
  this->m_flScrubTarget = frac;
  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + frac;
    CChoreoView::SetScrubTime(this: g_pChoreoView, t: realtime);
    CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: realtime);
    CChoreoView::DrawScrubHandle(this: g_pChoreoView, a2);
  }
  ExpressionTool::GetScrubHandleRect(this, &rcHandle, clipped: true);
  bounds.top = rcHandle.top;
  *(_QWORD *)&bounds.right = *(_QWORD *)&rcHandle.right;
  bounds.left = 0;
  bounds.right = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, &bounds);
  ExpressionTool::DrawScrubHandle(this, (CChoreoEvent *)&drawHelper, rcHandle: COERCE_FLOAT(&rcHandle));
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00451680
// Name: public: void ExpressionTool::MoveSelectedSamples(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::MoveSelectedSamples(ExpressionTool *this, float dfdx, float dfdy, bool snap)
{
  CExpressionToolWorkspace::MoveSelectedSamples(this: this->m_pWorkspace, dfdx, dfdy, snap);
}

//------------------------------------------------------------------------------
// Address: 0x004516B0
// Name: public: ExpressionTool::CColumnCopier::CTrackData::~CTrackData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::CColumnCopier::CTrackData::~CTrackData(ExpressionTool::CColumnCopier::CTrackData *this)
{
  ExpressionTool::CColumnCopier::CTrackData *v1; // esi
  int i; // ebx
  CExpressionSample *m_pMemory; // eax

  v1 = this + 1;
  for ( i = 1; i >= 0; --i )
  {
    v1 = (ExpressionTool::CColumnCopier::CTrackData *)((char *)v1 - 20);
    v1->m_Samples[0].m_Size = 0;
    if ( v1->m_Samples[0].m_Memory.m_nGrowSize >= 0 )
    {
      if ( v1->m_Samples[0].m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Samples[0].m_Memory.m_pMemory);
        v1->m_Samples[0].m_Memory.m_pMemory = nullptr;
      }
      v1->m_Samples[0].m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = v1->m_Samples[0].m_Memory.m_pMemory;
    v1->m_Samples[0].m_pElements = v1->m_Samples[0].m_Memory.m_pMemory;
    if ( v1->m_Samples[0].m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v1->m_Samples[0].m_Memory.m_pMemory = nullptr;
      }
      v1->m_Samples[0].m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451EC0
// Name: public: virtual void CExpressionToolWorkspace::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionToolWorkspace::redraw(CExpressionToolWorkspace *this)
{
  int v2; // edi
  TimelineItem **m_pItems; // ebx
  TimelineItem *v4; // esi
  int v5; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+Ch] [ebp-6Ch] BYREF
  tagRECT rcBounds; // [esp+64h] [ebp-14h] BYREF
  mxWidget *v8; // [esp+74h] [ebp-4h]

  v8 = this;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
  CExpressionToolWorkspace::DrawEventEnd(this, &drawHelper);
  v2 = 0;
  m_pItems = this->m_pItems;
  do
  {
    if ( (unsigned int)v2 <= 0x17F )
    {
      v4 = *m_pItems;
      if ( *m_pItems != nullptr && TimelineItem::GetVisible(this: *m_pItems) )
      {
        TimelineItem::GetBounds(this: v4, rect: &rcBounds);
        if ( rcBounds.bottom >= 0 )
        {
          v5 = mxWidget::h2(this: v8);
          if ( rcBounds.top <= v5 )
            v4->Draw(this: v4, a2: &drawHelper);
        }
      }
    }
    ++v2;
    ++m_pItems;
  }
  while ( v2 < 384 );
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00451F50
// Name: private: void ExpressionTool::OnMouseMove(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnMouseMove(ExpressionTool *this, mxEvent *event)
{
  mxEvent *v2; // edi
  int x_low; // eax
  int y_low; // ecx
  ExpressionTool::CFocusRect *v6; // edi
  tagRECT *p_m_rcFocus; // ebx
  float v8; // xmm0_4
  int m_nStartY; // eax
  int m_nStartX; // ecx
  HWND Handle; // eax
  HCURSOR CursorA; // eax
  int m_nMinX; // eax
  POINT v14; // [esp-4h] [ebp-54h]
  tagRECT rcHandle; // [esp+10h] [ebp-40h] BYREF
  int my; // [esp+20h] [ebp-30h] BYREF
  float v17; // [esp+24h] [ebp-2Ch] BYREF
  float v18; // [esp+28h] [ebp-28h] BYREF
  float st; // [esp+2Ch] [ebp-24h]
  float v20; // [esp+30h] [ebp-20h] BYREF
  float v21; // [esp+34h] [ebp-1Ch] BYREF
  float ed; // [esp+38h] [ebp-18h] BYREF
  int right; // [esp+3Ch] [ebp-14h] BYREF
  int left; // [esp+40h] [ebp-10h] BYREF
  int i; // [esp+44h] [ebp-Ch]
  unsigned int v26; // [esp+48h] [ebp-8h]
  int mx; // [esp+4Ch] [ebp-4h]

  v2 = event;
  x_low = SLOWORD(event->x);
  y_low = SLOWORD(event->y);
  event->x = (__int16)x_low;
  mx = x_low;
  my = y_low;
  if ( this->m_nDragType != 0 )
  {
    ExpressionTool::DrawFocusRect(this);
    i = 0;
    if ( this->m_FocusRects.m_Size > 0 )
    {
      v26 = 0;
      do
      {
        v6 = &this->m_FocusRects.m_Memory.m_pMemory[v26 / 0x20];
        p_m_rcFocus = &v6->m_rcFocus;
        *(_QWORD *)&v6->m_rcFocus.left = *(_QWORD *)&v6->m_rcOrig.left;
        *(_QWORD *)&v6->m_rcFocus.right = *(_QWORD *)&v6->m_rcOrig.right;
        if ( this->m_nDragType == 3 )
        {
          ExpressionTool::GetWorkspaceLeftRight(this, &left, &right);
          ExpressionTool::GetStartAndEndTime(this, st: &v21, &ed);
          st = (float)((float)((float)(mx - left) / (float)(right - left)) * (float)(ed - v21)) + v21;
          ExpressionTool::GetWorkspaceLeftRight(this, left: &my, right: (int *)&v17);
          ExpressionTool::GetStartAndEndTime(this, st: &v20, ed: &v18);
          v8 = (float)((float)(st - v20) / (float)(v18 - v20)) * (float)(LODWORD(v17) - my);
          m_nStartY = my + (int)v8;
          m_nStartX = this->m_nStartX;
          if ( m_nStartY < m_nStartX )
            m_nStartX = my + (int)v8;
          p_m_rcFocus->left = m_nStartX;
          if ( m_nStartY <= this->m_nStartY )
            m_nStartY = this->m_nStartY;
          v6->m_rcFocus.right = m_nStartY;
          rcHandle.right = 0;
          rcHandle.bottom = 0;
          Handle = (HWND)mxWidget::getHandle(this);
          ClientToScreen(hWnd: Handle, lpPoint: (LPPOINT)&rcHandle.right);
          OffsetRect(lprc: p_m_rcFocus, dx: rcHandle.right, dy: 0);
        }
        else
        {
          OffsetRect(lprc: p_m_rcFocus, dx: SLOWORD(event->x) - this->m_nStartX, dy: 0);
        }
        v26 += 32;
        ++i;
      }
      while ( i < this->m_FocusRects.m_Size );
      v2 = event;
    }
    ExpressionTool::DrawFocusRect(this);
  }
  else
  {
    if ( this->m_hPrevCursor != nullptr )
    {
      SetCursor(hCursor: this->m_hPrevCursor);
      this->m_hPrevCursor = nullptr;
    }
    ExpressionTool::GetScrubHandleRect(this, &rcHandle, clipped: true);
    InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
    v14.y = SLOWORD(v2->y);
    v14.x = SLOWORD(v2->x);
    if ( PtInRect(lprc: &rcHandle, pt: v14) || ExpressionTool::IsMouseOverTag(this, mx, my) != nullptr )
      goto LABEL_22;
    if ( !ExpressionTool::IsMouseOverSelection(this, mx: SLOWORD(v2->x), my: SLOWORD(v2->y)) )
      goto LABEL_26;
    if ( ExpressionTool::IsMouseOverSelectionStartEdge(this, event: v2)
      || ExpressionTool::IsMouseOverSelectionEndEdge(this, event: v2) )
    {
LABEL_22:
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
    }
    else
    {
      if ( (v2->modifiers & 2) == 0 )
        goto LABEL_26;
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
    }
    this->m_hPrevCursor = SetCursor(hCursor: CursorA);
  }
LABEL_26:
  if ( this->m_nDragType == 1 )
  {
    if ( this->m_bUseBounds )
    {
      m_nMinX = this->m_nMinX;
      if ( mx >= m_nMinX )
      {
        m_nMinX = this->m_nMaxX;
        if ( mx <= m_nMinX )
          m_nMinX = mx;
      }
      mx = m_nMinX;
    }
    if ( mxWidget::w2(this) > 0 )
    {
      ExpressionTool::GetWorkspaceLeftRight(this, left: (int *)&event, right: &my);
      ExpressionTool::GetStartAndEndTime(this, st: &v18, ed: &v17);
      ExpressionTool::ForceScrubPosition(
        this,
        a2: (int)v2,
        frac: this->m_flScrubberTimeOffset
      + (float)((float)((float)((float)(mx - (int)event) / (float)(my - (int)event)) * (float)(v17 - v18)) + v18));
    }
  }
  this->m_nLastX = SLOWORD(v2->x);
  this->m_nLastY = SLOWORD(v2->y);
}

//------------------------------------------------------------------------------
// Address: 0x00452280
// Name: private: void ExpressionTool::OnExportFlexAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnExportFlexAnimation(ExpressionTool *this)
{
  CChoreoEvent *SafeEvent; // esi
  void *v2; // esi
  char fafilename[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+204h] [ebp-30h] BYREF

  SafeEvent = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    CreatePath(relative: "flexanimations/foo");
    if ( FacePoser_ShowSaveFileNameDialog(
           relative: fafilename,
           bufsize: 0x200u,
           subdir: "flexanimations",
           wildcard: "*.vfa") )
    {
      V_DefaultExtension(path: fafilename, extension: ".vfa", pathStringLength: 512);
      Con_Printf(fmt: "Exporting events to %s\n", fafilename);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
      CChoreoScene::FileSaveFlexAnimations(&buf, level: 0, e: SafeEvent);
      v2 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: fafilename, a3: "wt", a4: 0);
      if ( v2 != nullptr )
      {
        filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v2);
        filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v2);
      }
      else
      {
        Con_Printf(fmt: "Unable to write file %s!!!\n", fafilename);
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004523A0
// Name: public: void ExpressionTool::Copy(class CFlexAnimationTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::Copy(ExpressionTool *this, CFlexAnimationTrack *source)
{
  int v2; // esi
  int *p_m_Size; // edi
  CExpressionSample *Sample; // eax
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  CExpressionSample *s; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int t; // [esp+14h] [ebp-4h]

  v2 = 0;
  t = 0;
  p_m_Size = &this->m_CopyData[0].m_Size;
  do
  {
    *p_m_Size = 0;
    if ( v2 == 0 || CFlexAnimationTrack::IsComboType(this: source) )
    {
      i = 0;
      if ( CFlexAnimationTrack::GetNumSamples(this: source, type: v2) > 0 )
      {
        do
        {
          Sample = CFlexAnimationTrack::GetSample(this: source, index: i, type: v2);
          v5 = *p_m_Size;
          s = Sample;
          v6 = *(p_m_Size - 2);
          if ( *p_m_Size + 1 > v6 )
            CUtlMemory<CExpressionSample,int>::Grow(
              this: (CUtlMemory<CExpressionSample,int> *)p_m_Size - 1,
              num: v5 - v6 + 1);
          ++*p_m_Size;
          v7 = *(p_m_Size - 3);
          v8 = *p_m_Size - v5 - 1;
          p_m_Size[1] = v7;
          if ( v8 > 0 )
            _V_memmove(dest: (void *)(v7 + 10 * v5 + 10), src: (const void *)(v7 + 10 * v5), count: 10 * v8);
          v9 = *(p_m_Size - 3) + 10 * v5;
          if ( v9 != 0 )
          {
            *(_QWORD *)v9 = *(_QWORD *)&s->value;
            *(_WORD *)(v9 + 8) = *((_WORD *)s + 4);
          }
          ++i;
          v2 = t;
        }
        while ( i < CFlexAnimationTrack::GetNumSamples(this: source, type: t) );
      }
    }
    ++v2;
    p_m_Size += 5;
    t = v2;
  }
  while ( v2 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x004524A0
// Name: private: void ExpressionTool::AddFocusRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::AddFocusRect(ExpressionTool *this, tagRECT *rc)
{
  __int64 v2; // xmm0_8
  HWND Handle; // eax
  int m_Size; // [esp-Ch] [ebp-44h]
  ExpressionTool::CFocusRect fr; // [esp+0h] [ebp-38h] BYREF
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
// Address: 0x00452530
// Name: private: void ExpressionTool::StartDragging(int,int,int,struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::StartDragging(
        ExpressionTool *this,
        float dragtype,
        int startx,
        int starty,
        HICON__ *cursor)
{
  int v5; // eax
  int v6; // ebx
  HICON__ *m_hPrevCursor; // eax
  int v9; // edi
  bool v10; // sf
  HWND Handle; // eax
  int v12; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  tagRECT rc; // [esp+Ch] [ebp-34h] BYREF
  tagRECT rcScrub; // [esp+1Ch] [ebp-24h] BYREF
  tagRECT rcStart; // [esp+2Ch] [ebp-14h] BYREF
  int left; // [esp+3Ch] [ebp-4h] BYREF

  v5 = starty;
  v6 = LODWORD(dragtype);
  this->m_nStartY = starty;
  this->m_nLastY = v5;
  m_hPrevCursor = this->m_hPrevCursor;
  v9 = startx;
  this->m_nDragType = v6;
  this->m_nStartX = v9;
  this->m_nLastX = v9;
  if ( m_hPrevCursor != nullptr )
  {
    SetCursor(hCursor: m_hPrevCursor);
    this->m_hPrevCursor = nullptr;
  }
  this->m_hPrevCursor = SetCursor(hCursor: cursor);
  v10 = this->m_FocusRects.m_Memory.m_nGrowSize < 0;
  this->m_FocusRects.m_Size = 0;
  if ( !v10 )
  {
    if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
      this->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top = 38;
  rc.bottom = 54;
  rcStart.left = v9;
  rcStart.right = v9;
  switch ( v6 )
  {
    case 2:
      rcStart.top = 38;
      goto LABEL_13;
    case 3:
      dragtype = ExpressionTool::GetTimeValueForMouse(this, mx: v9, clip: false);
      ExpressionTool::GetWorkspaceLeftRight(this, &left, right: (int *)&cursor);
      ExpressionTool::GetStartAndEndTime(this, st: (float *)&startx, ed: (float *)&starty);
      v12 = left
          + (int)(float)((float)((float)(dragtype - *(float *)&startx) / (float)(*(float *)&starty - *(float *)&startx))
                       * (float)((int)cursor - left));
      rcStart.left = v12;
      rcStart.right = v12;
      this->m_nStartX = v12;
      this->m_nLastX = v12;
      goto $LN3_12;
    case 4:
      v13 = this->m_flSelection[0];
      rcStart.bottom = 54;
      rcStart.top = 38;
      *(float *)&startx = v13;
      ExpressionTool::GetWorkspaceLeftRight(this, &left, right: (int *)&cursor);
      ExpressionTool::GetStartAndEndTime(this, st: &dragtype, ed: (float *)&starty);
      v14 = this->m_flSelection[1];
      rcStart.left = left
                   + (int)(float)((float)((float)(*(float *)&startx - dragtype) / (float)(*(float *)&starty - dragtype))
                                * (float)((int)cursor - left));
      *(float *)&startx = v14;
      ExpressionTool::GetWorkspaceLeftRight(this, &left, right: (int *)&cursor);
      ExpressionTool::GetStartAndEndTime(this, st: &dragtype, ed: (float *)&starty);
      rcStart.right = left
                    + (int)(float)((float)((float)(*(float *)&startx - dragtype) / (float)(*(float *)&starty - dragtype))
                                 * (float)((int)cursor - left));
      break;
    case 5:
    case 6:
$LN3_12:
      rcStart.top = rc.top;
      rcStart.bottom = rc.bottom;
      break;
    default:
      ExpressionTool::GetScrubHandleRect(this, rcHandle: &rcScrub, clipped: true);
      rcStart.bottom = rcScrub.bottom;
      rcStart.left = (rcScrub.right + rcScrub.left) / 2;
      rcStart.right = rcStart.left;
      rcStart.top = rcScrub.bottom;
LABEL_13:
      rcStart.bottom = mxWidget::h2(this);
      break;
  }
  ExpressionTool::AddFocusRect(this, rc: &rcStart);
  ExpressionTool::DrawFocusRect(this);
}

//------------------------------------------------------------------------------
// Address: 0x004527E0
// Name: public: void ExpressionTool::GetTimelineItems(class CUtlVector<class TimelineItem __near *,class CUtlMemory<class TimelineItem __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::GetTimelineItems(
        ExpressionTool *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list)
{
  int j; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  TimelineItem **v6; // ecx
  int v7; // eax
  TimelineItem **v8; // eax
  unsigned int i; // [esp+10h] [ebp-4h]
  CUtlVector<TimelineItem *,CUtlMemory<TimelineItem *,int> > *lista; // [esp+1Ch] [ebp+8h]

  i = 0;
  for ( j = 12; j < 1548; j += 4 )
  {
    if ( i <= 0x17F )
    {
      lista = *(CUtlVector<TimelineItem *,CUtlMemory<TimelineItem *,int> > **)((char *)&this->m_pWorkspace->__vftable + j);
      if ( lista != nullptr )
      {
        m_pMemory = (int)list[1].m_pMemory;
        m_nAllocationCount = list->m_nAllocationCount;
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
          *v8 = (TimelineItem *)lista;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452890
// Name: public: int CUtlMap<char const __near *,class ExpressionTool::CColumnCopier::CTrackData,int>::Find(char const __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Find(
        CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int> *this,
        const char **key)
{
  int v2; // esi
  int *p_m_nGrowSize; // eax
  int v4; // esi
  CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t dummyNode; // [esp+4h] [ebp-2Ch] BYREF

  v2 = 1;
  p_m_nGrowSize = &dummyNode.elem.m_Samples[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v2;
  }
  while ( v2 >= 0 );
  dummyNode.key = *key;
  v4 = CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  ExpressionTool::CColumnCopier::CTrackData::~CTrackData(this: &dummyNode.elem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00452B10
// Name: private: void ExpressionTool::OnPasteColumn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnPasteColumn(ExpressionTool *this)
{
  ExpressionTool *v1; // esi
  bool v2; // zf
  void (__thiscall *redraw)(struct ExpressionTool *); // edx
  void (__thiscall *v4)(struct ExpressionTool *); // edx
  float v5; // xmm1_4
  int start; // xmm0_4
  CExpressionToolWorkspace *m_pWorkspace; // ecx
  int v8; // edi
  TimelineItem *v9; // ecx
  CFlexAnimationTrack *SafeTrack; // eax
  CFlexAnimationTrack *v11; // ebx
  int v12; // edi
  int i; // esi
  ExpressionTool::CColumnCopier::CTrackData *v14; // eax
  int v15; // esi
  int v16; // ebx
  CExpressionSample *v17; // eax
  float end; // [esp+8h] [ebp-38h]
  TimelineItem *item; // [esp+18h] [ebp-28h]
  int *v20; // [esp+1Ch] [ebp-24h]
  ExpressionTool::CColumnCopier::CTrackData *data; // [esp+20h] [ebp-20h]
  float flPasteEndTime; // [esp+24h] [ebp-1Ch]
  int flPasteEndTimea; // [esp+24h] [ebp-1Ch]
  CFlexAnimationTrack *track; // [esp+28h] [ebp-18h]
  int tIndex; // [esp+2Ch] [ebp-14h] BYREF
  int controller; // [esp+30h] [ebp-10h]
  ExpressionTool *v27; // [esp+34h] [ebp-Ch]
  float v28; // [esp+38h] [ebp-8h]
  float flPasteTime; // [esp+3Ch] [ebp-4h]

  v1 = this;
  v2 = !this->m_ColumnCopy.m_bActive;
  v27 = this;
  if ( v2 )
  {
    _Msg(a1: "Nothing to paste\n");
  }
  else
  {
    flPasteTime = ExpressionTool::GetTimeForClickedPos(this);
    flPasteEndTime = (float)(v1->m_ColumnCopy.m_flCopyTimes[1] + flPasteTime) - v1->m_ColumnCopy.m_flCopyTimes[0];
    CExpressionToolWorkspace::DeselectAll(this: v1->m_pWorkspace);
    redraw = v1->redraw;
    v1->m_bSelectionActive = false;
    redraw(this: v1);
    *(float *)&controller = flPasteTime;
    v28 = flPasteEndTime;
    if ( flPasteTime > flPasteEndTime )
    {
      v28 = flPasteTime;
      *(float *)&controller = flPasteEndTime;
    }
    CExpressionToolWorkspace::DeselectAll(this: v1->m_pWorkspace);
    v4 = v1->redraw;
    v1->m_bSelectionActive = false;
    v4(this: v1);
    v5 = v28;
    start = controller;
    m_pWorkspace = v1->m_pWorkspace;
    end = v28;
    v1->m_flSelection[0] = *(float *)&controller;
    v1->m_flSelection[1] = v5;
    v1->m_bSelectionActive = true;
    CExpressionToolWorkspace::SelectPoints(this: m_pWorkspace, start: *(float *)&start, end);
    v1->redraw(this: v1);
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Paste column");
    v8 = 12;
    *(float *)&controller = 0.0;
    flPasteEndTimea = 12;
    do
    {
      if ( (unsigned int)controller <= 0x17F )
      {
        v9 = *(TimelineItem **)((char *)&v1->m_pWorkspace->__vftable + v8);
        item = v9;
        if ( v9 != nullptr )
        {
          SafeTrack = TimelineItem::GetSafeTrack(this: v9);
          v11 = SafeTrack;
          track = SafeTrack;
          if ( SafeTrack != nullptr )
          {
            tIndex = (int)CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
            if ( tIndex != 0 )
              tIndex = CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Find(
                         this: &v1->m_ColumnCopy.m_Data.m_Elements,
                         key: (const char **)&tIndex);
            else
              tIndex = -1;
            v12 = 0;
            v28 = 0.0;
            do
            {
              for ( i = CFlexAnimationTrack::GetNumSamples(this: v11, type: v12) - 1; i >= 0; --i )
              {
                if ( (*((_BYTE *)CFlexAnimationTrack::GetSample(this: v11, index: i, type: v12) + 8) & 1) != 0 )
                  CFlexAnimationTrack::RemoveSample(this: v11, index: i, type: v12);
              }
              if ( tIndex != -1 )
              {
                v15 = 0;
                data = &v27->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Elements.m_pMemory[tIndex].m_Data.elem;
                v14 = data;
                v20 = (int *)((char *)&data->m_Samples[0].m_Size + LODWORD(v28));
                if ( *v20 > 0 )
                {
                  v16 = 0;
                  while ( 1 )
                  {
                    v17 = CFlexAnimationTrack::AddSample(
                            this: track,
                            time: (float)((*(CExpressionSample **)((char *)&v14->m_Samples[0].m_Memory.m_pMemory + LODWORD(v28)))[v16].time
                                  - v27->m_ColumnCopy.m_flCopyTimes[0])
                          + flPasteTime,
                            value: (*(CExpressionSample **)((char *)&v14->m_Samples[0].m_Memory.m_pMemory + LODWORD(v28)))[v16].value,
                            type: v12);
                    *((_WORD *)v17 + 4) |= 1u;
                    ++v15;
                    ++v16;
                    if ( v15 >= *v20 )
                      break;
                    v14 = data;
                  }
                  v11 = track;
                }
              }
              CFlexAnimationTrack::Resort(this: v11, type: v12++);
              LODWORD(v28) += 20;
            }
            while ( SLODWORD(v28) < 40 );
            TimelineItem::DrawSelf(this: item);
            v8 = flPasteEndTimea;
            v1 = v27;
          }
        }
      }
      ++controller;
      v8 += 4;
      flPasteEndTimea = v8;
    }
    while ( v8 < 1548 );
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Paste column");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452DA0
// Name: public: void CUtlDict<class ExpressionTool::CColumnCopier::CTrackData,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<ExpressionTool::CColumnCopier::CTrackData,int>::RemoveAll(
        CUtlDict<ExpressionTool::CColumnCopier::CTrackData,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00452DF0
// Name: public: virtual ExpressionTool::~ExpressionTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::~ExpressionTool(ExpressionTool *this)
{
  CExpressionToolWorkspace **p_m_pWorkspace; // esi
  CExpressionToolWorkspace *v3; // eax
  int i; // [esp+Ch] [ebp-4h]

  this->mxWindow::mxWidget::__vftable = (ExpressionTool_vtbl *)&ExpressionTool::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&ExpressionTool::`vftable'{for `IFacePoserToolWindow'};
  p_m_pWorkspace = &this->m_pWorkspace;
  for ( i = 1; i >= 0; --i )
  {
    p_m_pWorkspace -= 5;
    p_m_pWorkspace[3] = nullptr;
    if ( (int)p_m_pWorkspace[2] >= 0 )
    {
      if ( *p_m_pWorkspace != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *p_m_pWorkspace);
        *p_m_pWorkspace = nullptr;
      }
      p_m_pWorkspace[1] = nullptr;
    }
    v3 = *p_m_pWorkspace;
    p_m_pWorkspace[4] = *p_m_pWorkspace;
    if ( (int)p_m_pWorkspace[2] >= 0 )
    {
      if ( v3 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
        *p_m_pWorkspace = nullptr;
      }
      p_m_pWorkspace[1] = nullptr;
    }
  }
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FocusRects);
  CUtlDict<ExpressionTool::CColumnCopier::CTrackData,int>::RemoveAll(this: &this->m_ColumnCopy.m_Data);
  CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>(this: &this->m_ColumnCopy.m_Data.m_Elements.m_Tree);
  IFacePoserToolWindow::~IFacePoserToolWindow(this: &this->IFacePoserToolWindow);
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x00452EB0
// Name: public: ExpressionTool::ExpressionTool(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
ExpressionTool *__thiscall ExpressionTool::ExpressionTool(ExpressionTool *this, mxWindow *parent)
{
  CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *m_CopyData; // eax
  int i; // ecx
  CExpressionToolWorkspace *v5; // eax
  CExpressionToolWorkspace *v6; // eax
  mxScrollbar *v7; // eax
  mxScrollbar *v8; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "ExpressionTool",
    displaynameroot: "Flex Animation");
  this->mxWindow::mxWidget::__vftable = (ExpressionTool_vtbl *)&ExpressionTool::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&ExpressionTool::`vftable'{for `IFacePoserToolWindow'};
  this->m_ColumnCopy.m_bActive = false;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Root = -1;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_NumElements = 0;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_pElements = this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  *(_QWORD *)this->m_ColumnCopy.m_flCopyTimes = 0;
  this->m_FocusRects.m_Memory.m_pMemory = nullptr;
  this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  this->m_FocusRects.m_Memory.m_nGrowSize = 0;
  this->m_FocusRects.m_Size = 0;
  this->m_FocusRects.m_pElements = nullptr;
  m_CopyData = this->m_CopyData;
  for ( i = 1; i >= 0; --i )
  {
    m_CopyData->m_Memory.m_pMemory = nullptr;
    m_CopyData->m_Memory.m_nAllocationCount = 0;
    m_CopyData->m_Memory.m_nGrowSize = 0;
    m_CopyData->m_Size = 0;
    m_CopyData->m_pElements = nullptr;
    ++m_CopyData;
  }
  this->m_bSuppressLayout = false;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: true);
  v5 = (CExpressionToolWorkspace *)operator new(nSize: 0x624u);
  if ( v5 != nullptr )
    v6 = CExpressionToolWorkspace::CExpressionToolWorkspace(this: v5, parent: this);
  else
    v6 = nullptr;
  this->m_pWorkspace = v6;
  this->m_nFocusEventGlobalID = -1;
  this->m_flScrub = 0.0;
  this->m_flScrubTarget = 0.0;
  this->m_nDragType = 0;
  this->m_nClickedX = 0;
  this->m_nClickedY = 0;
  this->m_hPrevCursor = nullptr;
  this->m_nStartX = 0;
  this->m_nStartY = 0;
  this->m_nMinX = 0;
  this->m_nMaxX = 0;
  this->m_bUseBounds = false;
  this->m_pLastEvent = nullptr;
  this->m_nMousePos[1] = 0;
  this->m_nMousePos[0] = 0;
  *(_QWORD *)this->m_flSelection = 0;
  this->m_bSelectionActive = false;
  this->m_bLayoutIsValid = false;
  this->m_flPixelsPerSecond = 500.0;
  this->m_flLastDuration = 0.0;
  this->m_nScrollbarHeight = 12;
  this->m_flLeftOffset = 0.0;
  this->m_nLastHPixelsNeeded = -1;
  v7 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxScrollbar::mxScrollbar(this: v7, parent: this, x: 0, y: 0, w: 18, h: 100, id: 1035, style: 0);
  else
    v8 = nullptr;
  this->m_pHorzScrollBar = v8;
  mxWidget::setVisible(this: v8, b: false);
  this->m_bInSetEvent = false;
  this->m_flScrubberTimeOffset = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00453100
// Name: private: void ExpressionTool::OnCopyColumn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ExpressionTool::OnCopyColumn(ExpressionTool *this)
{
  ExpressionTool *v1; // edi
  int v2; // eax
  double v3; // st7
  TimelineItem *v4; // ecx
  CFlexAnimationTrack *SafeTrack; // esi
  int v6; // eax
  CExpressionSample *Sample; // eax
  __int64 v8; // xmm0_8
  __int16 v9; // ax
  const char *FlexControllerName; // eax
  int v11; // edx
  int *p_m_nGrowSize; // ecx
  int v13; // esi
  int v14; // eax
  const char *v15; // eax
  const char *v16; // esi
  CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int> > *p_m_Tree; // edi
  char *v18; // eax
  const char *v19; // ecx
  char *v20; // eax
  char v21; // dl
  const char *v22; // edx
  int v23; // ecx
  int *v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // edx
  int v28; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *v29; // eax
  int v30; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *v31; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *v32; // edx
  int p_m_Data; // esi
  int v34; // ecx
  _DWORD *v35; // eax
  int m_Size; // edi
  int v37; // ecx
  int j; // edx
  int v39; // edi
  int v40; // eax
  int v41; // edi
  int v42; // ecx
  int k; // edx
  int v44; // edi
  int v45; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *m_pMemory; // ecx
  int v47; // eax
  int v48; // edi
  CUtlMemory<CExpressionSample,int> *v49; // esi
  int m_nAllocationCount; // eax
  CExpressionSample *v51; // ecx
  int v52; // eax
  CExpressionSample *v53; // edx
  int v54; // ecx
  CExpressionSample *v55; // eax
  int v56; // [esp-10h] [ebp-98h]
  int v57; // [esp-10h] [ebp-98h]
  CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t search; // [esp+0h] [ebp-88h] BYREF
  CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t insert; // [esp+2Ch] [ebp-5Ch] BYREF
  CExpressionSample copy; // [esp+58h] [ebp-30h]
  int v61; // [esp+64h] [ebp-24h]
  int v62; // [esp+68h] [ebp-20h]
  CFlexAnimationTrack *track; // [esp+6Ch] [ebp-1Ch]
  int i; // [esp+70h] [ebp-18h]
  ExpressionTool *v65; // [esp+74h] [ebp-14h]
  int controller; // [esp+78h] [ebp-10h]
  int t; // [esp+7Ch] [ebp-Ch]
  int parent; // [esp+80h] [ebp-8h] BYREF
  bool leftchild; // [esp+87h] [ebp-1h] BYREF

  v1 = this;
  v65 = this;
  this->m_ColumnCopy.m_bActive = false;
  *(_QWORD *)this->m_ColumnCopy.m_flCopyTimes = 0;
  CUtlDict<ExpressionTool::CColumnCopier::CTrackData,int>::RemoveAll(this: &this->m_ColumnCopy.m_Data);
  v1->m_ColumnCopy.m_flCopyTimes[0] = v1->m_flSelection[0];
  v2 = 12;
  v3 = v1->m_flSelection[1];
  v1->m_ColumnCopy.m_bActive = true;
  v1->m_ColumnCopy.m_flCopyTimes[1] = v3;
  controller = 0;
  v62 = 12;
  do
  {
    if ( (unsigned int)controller <= 0x17F )
    {
      v4 = *(TimelineItem **)((char *)&v1->m_pWorkspace->__vftable + v2);
      if ( v4 != nullptr )
      {
        SafeTrack = TimelineItem::GetSafeTrack(this: v4);
        track = SafeTrack;
        if ( SafeTrack != nullptr )
        {
          t = 0;
          while ( 1 )
          {
            v6 = CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: t) - 1;
            i = v6;
            if ( v6 >= 0 )
              break;
LABEL_45:
            if ( ++t >= 2 )
              goto LABEL_46;
          }
          while ( 1 )
          {
            Sample = CFlexAnimationTrack::GetSample(this: SafeTrack, index: v6, type: t);
            if ( (*((_BYTE *)Sample + 8) & 1) == 0 )
              goto LABEL_44;
            v8 = *(_QWORD *)&Sample->value;
            v9 = *((_WORD *)Sample + 4) & 0xFFFE;
            *(_QWORD *)&copy.value = v8;
            *((_WORD *)&copy + 4) = v9;
            FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
            if ( FlexControllerName == nullptr )
              goto LABEL_15;
            v11 = 1;
            p_m_nGrowSize = &search.elem.m_Samples[0].m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = 0;
              *(p_m_nGrowSize - 1) = 0;
              *p_m_nGrowSize = 0;
              p_m_nGrowSize[1] = 0;
              p_m_nGrowSize[2] = 0;
              p_m_nGrowSize += 5;
              --v11;
            }
            while ( v11 >= 0 );
            search.key = FlexControllerName;
            v13 = CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::Find(
                    this: &v1->m_ColumnCopy.m_Data.m_Elements.m_Tree,
                    &search);
            ExpressionTool::CColumnCopier::CTrackData::~CTrackData(this: &search.elem);
            v14 = v13;
            if ( v13 == -1 )
              break;
LABEL_38:
            m_pMemory = v1->m_ColumnCopy.m_Data.m_Elements.m_Tree.m_Elements.m_pMemory;
            v47 = 5 * (v14 + t + 2 * v14 + 1);
            v48 = *(&m_pMemory->m_Tag + v47);
            v49 = (CUtlMemory<CExpressionSample,int> *)(&m_pMemory->m_Left + v47);
            m_nAllocationCount = v49->m_nAllocationCount;
            if ( v48 + 1 > m_nAllocationCount )
              CUtlMemory<CExpressionSample,int>::Grow(this: v49, num: v48 - m_nAllocationCount + 1);
            ++v49[1].m_pMemory;
            v51 = v49->m_pMemory;
            v52 = (int)v49[1].m_pMemory - v48 - 1;
            v49[1].m_nAllocationCount = (int)v49->m_pMemory;
            if ( v52 > 0 )
              _V_memmove(dest: &v51[v48 + 1], src: &v51[v48], count: 10 * v52);
            v53 = v49->m_pMemory;
            SafeTrack = track;
            v54 = v48;
            v1 = v65;
            v55 = &v53[v54];
            if ( v55 != nullptr )
              *v55 = copy;
LABEL_44:
            if ( --i < 0 )
              goto LABEL_45;
            v6 = i;
          }
          SafeTrack = track;
LABEL_15:
          v15 = CFlexAnimationTrack::GetFlexControllerName(this: SafeTrack);
          v16 = v15;
          p_m_Tree = &v1->m_ColumnCopy.m_Data.m_Elements.m_Tree;
          if ( v15 != nullptr
            && (v18 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v15) + 1),
                parent = (int)v18,
                v18 != nullptr) )
          {
            v19 = v16;
            v20 = (char *)(v18 - v16);
            do
            {
              v21 = *v19;
              v20[(_DWORD)v19] = *v19;
              ++v19;
            }
            while ( v21 != 0 );
            v22 = (const char *)parent;
          }
          else
          {
            v22 = nullptr;
          }
          v23 = 1;
          v24 = &insert.elem.m_Samples[0].m_Memory.m_nGrowSize;
          do
          {
            *(v24 - 2) = 0;
            *(v24 - 1) = 0;
            *v24 = 0;
            v24[1] = 0;
            v24[2] = 0;
            v24 += 5;
            --v23;
          }
          while ( v23 >= 0 );
          insert.key = v22;
          parent = -1;
          leftchild = false;
          CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::FindInsertionPosition(
            this: p_m_Tree,
            &insert,
            &parent,
            &leftchild);
          v25 = CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::NewNode(
                  this: p_m_Tree,
                  a2: (const char *)p_m_Tree);
          v26 = parent;
          v27 = v25;
          v28 = v25;
          v29 = &p_m_Tree->m_Elements.m_pMemory[v25];
          v61 = v27;
          v29->m_Parent = parent;
          v29->m_Right = -1;
          v29->m_Left = -1;
          v29->m_Tag = 0;
          if ( v26 == -1 )
          {
            p_m_Tree->m_Root = v27;
          }
          else
          {
            v30 = v26;
            v31 = p_m_Tree->m_Elements.m_pMemory;
            if ( leftchild )
              v31[v30].m_Left = v27;
            else
              v31[v30].m_Right = v27;
          }
          CUtlRBTree<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int,CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>>::InsertRebalance(
            this: p_m_Tree,
            elem: v27);
          v32 = p_m_Tree->m_Elements.m_pMemory;
          ++p_m_Tree->m_NumElements;
          p_m_Data = (int)&v32[v28].m_Data;
          if ( p_m_Data != 0 )
          {
            *(_DWORD *)p_m_Data = insert.key;
            v34 = 1;
            v35 = (_DWORD *)(p_m_Data + 12);
            do
            {
              *(v35 - 2) = 0;
              *(v35 - 1) = 0;
              *v35 = 0;
              v35[1] = 0;
              v35[2] = 0;
              v35 += 5;
              --v34;
            }
            while ( v34 >= 0 );
            m_Size = insert.elem.m_Samples[0].m_Size;
            v56 = insert.elem.m_Samples[0].m_Size;
            parent = (int)insert.elem.m_Samples[0].m_Memory.m_pMemory;
            *(_DWORD *)(p_m_Data + 16) = 0;
            CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertMultipleBefore(
              this: (CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *)(p_m_Data + 4),
              elem: 0,
              num: v56);
            if ( m_Size > 0 )
            {
              v37 = 0;
              for ( j = m_Size; j != 0; --j )
              {
                v39 = v37 + parent;
                v40 = *(_DWORD *)(p_m_Data + 4);
                *(_QWORD *)(v40 + v37) = *(_QWORD *)(v37 + parent);
                *(_WORD *)(v40 + v37 + 8) = *(_WORD *)(v39 + 8);
                v37 += 10;
              }
            }
            v41 = insert.elem.m_Samples[1].m_Size;
            v57 = insert.elem.m_Samples[1].m_Size;
            parent = (int)insert.elem.m_Samples[1].m_Memory.m_pMemory;
            *(_DWORD *)(p_m_Data + 36) = 0;
            CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertMultipleBefore(
              this: (CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *)(p_m_Data + 24),
              elem: 0,
              num: v57);
            if ( v41 > 0 )
            {
              v42 = 0;
              for ( k = v41; k != 0; --k )
              {
                v44 = v42 + parent;
                v45 = *(_DWORD *)(p_m_Data + 24);
                *(_QWORD *)(v45 + v42) = *(_QWORD *)(v42 + parent);
                *(_WORD *)(v45 + v42 + 8) = *(_WORD *)(v44 + 8);
                v42 += 10;
              }
            }
          }
          ExpressionTool::CColumnCopier::CTrackData::~CTrackData(this: &insert.elem);
          v14 = v61;
          v1 = v65;
          goto LABEL_38;
        }
      }
    }
LABEL_46:
    ++controller;
    v2 = v62 + 4;
    v62 = v2;
  }
  while ( v2 < 1548 );
}

//------------------------------------------------------------------------------
// Address: 0x004534A0
// Name: public: virtual int ExpressionTool::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ExpressionTool::handleEvent(ExpressionTool *this, int event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  mxEvent *width; // eax
  IFacePoserToolWindow_vtbl *v8; // edx
  int height; // edi
  int v10; // eax
  char *Name; // eax
  int TimeZoom; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int modifiers; // ebx
  int v17; // eax
  bool v18; // bl
  double TimeValueForMouse; // st7
  double v20; // st7
  double v21; // st7
  HCURSOR CursorA; // eax
  HCURSOR v23; // eax
  HCURSOR v24; // eax
  HCURSOR v25; // eax
  HCURSOR v26; // eax
  HCURSOR v27; // eax
  void (__thiscall *redraw)(struct ExpressionTool *); // eax
  int v29; // eax
  bool v30; // zf
  int x_low; // ebx
  int y_low; // ecx
  float v33; // xmm0_4
  CFlexTimingTag *v34; // ebx
  IterateRIFF *SafeEvent; // eax
  IterateRIFF *v36; // edi
  int v37; // eax
  TimelineItem *v38; // eax
  CExpressionToolWorkspace *v39; // ecx
  TimelineItem *v40; // eax
  TimelineItem *v41; // esi
  TimelineItem *v42; // eax
  TimelineItem *v43; // esi
  CAudioMixerWave *v44; // eax
  CAudioMixerWave *v45; // eax
  TimelineItem *v46; // esi
  TimelineItem *ClickedItem; // eax
  TimelineItem *v48; // eax
  TimelineItem *v49; // esi
  TimelineItem *v50; // eax
  TimelineItem *v51; // esi
  TimelineItem *v52; // eax
  TimelineItem *v53; // esi
  TimelineItem *v54; // eax
  TimelineItem *v55; // esi
  int MaxValue; // edi
  int MinValue; // edi
  TimelineItem *v58; // eax
  char *v59; // [esp+0h] [ebp-24h]
  int frac; // [esp+4h] [ebp-20h]
  float fraca; // [esp+4h] [ebp-20h]
  float t; // [esp+14h] [ebp-10h]
  float ta; // [esp+14h] [ebp-10h]
  float tb; // [esp+14h] [ebp-10h]
  float percent; // [esp+18h] [ebp-Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+1Ch] [ebp-8h]
  int my; // [esp+20h] [ebp-4h] BYREF

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = (mxEvent *)event;
  HandleToolEvent = this->HandleToolEvent;
  my = 0;
  if ( HandleToolEvent(this: &this->IFacePoserToolWindow, a2: (mxEvent *)event) )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  switch ( v4->event )
  {
    case 0:
      v37 = v4->action - 1002;
      my = 1;
      switch ( v37 )
      {
        case 0:
          CExpressionToolWorkspace::CollapseAll(this: this->m_pWorkspace, keepExpanded: nullptr);
          goto LABEL_137;
        case 1:
          CExpressionToolWorkspace::ExpandAll(this: this->m_pWorkspace);
          goto LABEL_137;
        case 2:
          CExpressionToolWorkspace::ExpandValid(this: this->m_pWorkspace);
          goto LABEL_137;
        case 3:
          ExpressionTool::AddFlexTimingTag(this, mx: *(float *)&this->m_nClickedX);
          goto LABEL_137;
        case 4:
          ExpressionTool::DeleteFlexTimingTag(this, mx: this->m_nClickedX, my: this->m_nClickedY);
          goto LABEL_137;
        case 5:
          ExpressionTool::LockTimingTag(this);
          goto LABEL_137;
        case 6:
          ExpressionTool::UnlockTimingTag(this);
          goto LABEL_137;
        case 7:
          ExpressionTool::OnCopyToFlex(this, isEdited: true);
          goto LABEL_137;
        case 8:
          ExpressionTool::OnCopyFromFlex(this, isEdited: false);
          goto LABEL_137;
        case 9:
          ExpressionTool::OnNewExpression(this);
          goto LABEL_137;
        case 10:
          ExpressionTool::OnExportFlexAnimation(this);
          goto LABEL_137;
        case 11:
          ExpressionTool::OnImportFlexAnimation(this);
          goto LABEL_137;
        case 12:
          CChoreoView::Redo(this: g_pChoreoView);
          goto LABEL_137;
        case 13:
          CChoreoView::Undo(this: g_pChoreoView);
          goto LABEL_137;
        case 14:
          ClickedItem = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( ClickedItem != nullptr )
            TimelineItem::Copy(this: ClickedItem);
          goto LABEL_137;
        case 15:
          v48 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          v49 = v48;
          if ( v48 != nullptr )
          {
            TimelineItem::Paste(this: v48);
            TimelineItem::DrawSelf(this: v49);
          }
          goto LABEL_137;
        case 16:
          v50 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          v51 = v50;
          if ( v50 != nullptr )
          {
            TimelineItem::Delete(this: v50);
            TimelineItem::DrawSelf(this: v51);
          }
          goto LABEL_137;
        case 17:
          v52 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          v53 = v52;
          if ( v52 != nullptr )
          {
            TimelineItem::DeselectAll(this: v52);
            TimelineItem::DrawSelf(this: v53);
          }
          goto LABEL_137;
        case 18:
          v54 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          v55 = v54;
          if ( v54 != nullptr )
          {
            TimelineItem::SelectAll(this: v54);
            TimelineItem::DrawSelf(this: v55);
          }
          goto LABEL_137;
        case 19:
          v45 = (CAudioMixerWave *)CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( v45 != nullptr )
            TimelineItem::SetCollapsed(this: v45, active: true);
          goto LABEL_90;
        case 20:
          v44 = (CAudioMixerWave *)CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( v44 != nullptr )
            TimelineItem::SetCollapsed(this: v44, active: false);
LABEL_90:
          CExpressionToolWorkspace::LayoutItems(this: this->m_pWorkspace, force: false);
          goto LABEL_137;
        case 21:
          v46 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( v46 == nullptr )
            goto LABEL_137;
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Enable item");
          TimelineItem::SetActive(this: v46, state: true);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Enable item");
          break;
        case 22:
          v46 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( v46 == nullptr )
            goto LABEL_137;
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Disable item");
          TimelineItem::SetActive(this: v46, state: false);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Disable item");
          break;
        case 23:
          v40 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          v41 = v40;
          if ( v40 != nullptr )
          {
            TimelineItem::SetEditType(this: v40, type: 0);
            TimelineItem::DrawSelf(this: v41);
          }
          goto LABEL_137;
        case 24:
          v42 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          v43 = v42;
          if ( v42 != nullptr )
          {
            TimelineItem::SetEditType(this: v42, type: 1);
            TimelineItem::DrawSelf(this: v43);
          }
          goto LABEL_137;
        case 25:
          v38 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          CExpressionToolWorkspace::CollapseAll(this: v39, keepExpanded: v38);
          goto LABEL_137;
        case 26:
          CExpressionToolWorkspace::DisableAllExcept(this: this->m_pWorkspace);
          goto LABEL_137;
        case 27:
          CExpressionToolWorkspace::EnableValid(this: this->m_pWorkspace);
          goto LABEL_137;
        case 28:
          v46 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( v46 == nullptr )
            goto LABEL_137;
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Snap Selected");
          TimelineItem::SnapSelected(this: v46);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Snap Selected");
          break;
        case 29:
          v46 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
          if ( v46 == nullptr )
            goto LABEL_137;
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Snap Item");
          TimelineItem::SnapAll(this: v46);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Snap Item");
          break;
        case 30:
          CExpressionToolWorkspace::OnDeleteColumn(this: this->m_pWorkspace);
          goto LABEL_137;
        case 31:
          CExpressionToolWorkspace::OnSnapAll(this: this->m_pWorkspace);
          goto LABEL_137;
        case 32:
          ExpressionTool::OnChangeScale(this);
          goto LABEL_137;
        case 33:
          switch ( v4->modifiers )
          {
            case 0:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 10;
              goto LABEL_120;
            case 1:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 10;
              goto LABEL_125;
            case 2:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 20;
LABEL_120:
              if ( MaxValue > mxScrollbar::getMinValue(this: this->m_pHorzScrollBar) )
                goto LABEL_127;
              MinValue = mxScrollbar::getMinValue(this: this->m_pHorzScrollBar);
              ExpressionTool::MoveTimeSliderToPos(this, x: MinValue);
              break;
            case 3:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 20;
LABEL_125:
              if ( MaxValue >= mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar) )
                MaxValue = mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar);
LABEL_127:
              ExpressionTool::MoveTimeSliderToPos(this, x: MaxValue);
              break;
            case 5:
              ExpressionTool::MoveTimeSliderToPos(this, x: v4->height);
              break;
            default:
              goto LABEL_137;
          }
          goto LABEL_137;
        case 34:
          ExpressionTool::OnSortByUsed(this);
          goto LABEL_137;
        case 35:
          ExpressionTool::OnSortByName(this);
          goto LABEL_137;
        case 36:
          ExpressionTool::OnDeleteSelection(this, excise_time: false);
          goto LABEL_137;
        case 37:
          ExpressionTool::OnDeleteSelection(this, excise_time: true);
          goto LABEL_137;
        case 38:
          ExpressionTool::OnResetItemSize(this);
          goto LABEL_137;
        case 39:
          ExpressionTool::OnResetAllItemSizes(this);
          goto LABEL_137;
        case 40:
          ExpressionTool::OnScaleSamples(this);
          goto LABEL_137;
        case 51:
          ExpressionTool::OnEdgeProperties(this);
          goto LABEL_137;
        case 52:
          ExpressionTool::OnCopyColumn(this);
          goto LABEL_137;
        case 53:
          ExpressionTool::OnPasteColumn(this);
          goto LABEL_137;
        default:
          my = 0;
          goto LABEL_137;
      }
      TimelineItem::DrawSelf(this: v46);
      goto LABEL_137;
    case 1:
      width = (mxEvent *)v4->width;
      v8 = this->IFacePoserToolWindow::__vftable;
      height = v4->height;
      event = (int)width;
      frac = height - this->m_nScrollbarHeight - v8->GetCaptionHeight(this: &this->IFacePoserToolWindow) - 60;
      v59 = (char *)(event - 10);
      v10 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      mxWidget::setBounds(this: this->m_pWorkspace, x: 5, y: v10 + 55, w: (int)v59, h: frac);
      this->m_nLastHPixelsNeeded = 0;
      ExpressionTool::InvalidateLayout(this);
      goto LABEL_136;
    case 6:
      if ( (v4->buttons & 2) != 0 )
        goto LABEL_15;
      v30 = this->m_nDragType == 0;
      x_low = SLOWORD(v4->x);
      y_low = SLOWORD(v4->y);
      event = x_low;
      my = y_low;
      if ( !v30 )
        ExpressionTool::DrawFocusRect(this);
      if ( this->m_hPrevCursor != nullptr )
      {
        SetCursor(hCursor: this->m_hPrevCursor);
        this->m_hPrevCursor = nullptr;
      }
      switch ( this->m_nDragType )
      {
        case 1:
          ExpressionTool::ApplyBounds(this, mx: &event, &my);
          if ( mxWidget::w2(this) > 0 )
          {
            ta = ExpressionTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
            v33 = this->m_flScrubberTimeOffset + ta;
            this->m_flScrubberTimeOffset = 0.0;
            ExpressionTool::ForceScrubPosition(this, a2: (int)v4, frac: v33);
          }
          goto LABEL_58;
        case 2:
          ExpressionTool::ApplyBounds(this, mx: &event, &my);
          v34 = ExpressionTool::IsMouseOverTag(this, mx: this->m_nStartX, my: this->m_nStartY);
          SafeEvent = ExpressionTool::GetSafeEvent(this);
          v36 = SafeEvent;
          if ( v34 != nullptr
            && g_pChoreoView != nullptr
            && SafeEvent != nullptr
            && ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent) != 0.0 )
          {
            tb = ExpressionTool::GetTimeValueForMouse(this, mx: event, clip: false);
            percent = tb / ((double (__thiscall *)(IterateRIFF *))v36->m_riff->m_io)(a1: v36);
            CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
            CChoreoView::PushUndo(this: g_pChoreoView, description: "Move Timing Tag");
            if ( CFlexTimingTag::GetLocked(this: v34) )
              ExpressionTool::ResampleControlPoints(this, tag: (ConCommandBase *)v34, newposition: percent);
            CEventAbsoluteTag::SetPercentage(this: (CEventAbsoluteTag *)v34, percentage: percent);
            CChoreoView::PushRedo(this: g_pChoreoView, description: "Move Timing Tag");
          }
          CExpressionToolWorkspace::LayoutItems(this: this->m_pWorkspace, force: true);
          this->redraw(this);
LABEL_58:
          x_low = event;
          break;
        case 3:
          ExpressionTool::FinishSelect(this, startx: *(float *)&this->m_nStartX, mx: *(float *)&x_low);
          break;
        case 4:
          ExpressionTool::FinishMoveSelection(this, startx: *(float *)&this->m_nStartX, mx: *(float *)&x_low);
          break;
        case 5:
          ExpressionTool::FinishMoveSelectionStart(this, startx: *(float *)&this->m_nStartX, mx: *(float *)&x_low);
          break;
        case 6:
          ExpressionTool::FinishMoveSelectionEnd(this, startx: *(float *)&this->m_nStartX, mx: *(float *)&x_low);
          break;
        default:
          break;
      }
      this->m_nMousePos[1] = my;
      this->m_nDragType = 0;
      this->m_nMousePos[0] = x_low;
      ExpressionTool::DrawMouseOverPos(this);
      goto LABEL_136;
    case 7:
      v15 = SLOWORD(v4->y);
      modifiers = v4->modifiers;
      v17 = SLOWORD(v4->x);
      this->m_nClickedY = v15;
      this->m_nMousePos[1] = v15;
      v18 = (modifiers & 2) != 0;
      my = 1;
      this->m_nClickedX = v17;
      this->m_nMousePos[0] = v17;
      ExpressionTool::DrawMouseOverPos(this);
      if ( (v4->buttons & 2) == 0 )
      {
        if ( this->m_nDragType == 0 )
        {
          if ( ExpressionTool::IsMouseOverScrubHandle(this, event: v4) )
          {
            if ( mxWidget::w2(this) > 0 )
            {
              TimeValueForMouse = ExpressionTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
              t = TimeValueForMouse;
              this->m_flScrubberTimeOffset = this->m_flScrub - TimeValueForMouse;
              v20 = 20.0 / ExpressionTool::GetPixelsPerSecond(this);
              *(float *)&event = v20;
              percent = -v20;
              v21 = clamp<float,float,float>(
                      val: &this->m_flScrubberTimeOffset,
                      minVal: &percent,
                      maxVal: (const float *)&event);
              this->m_flScrubberTimeOffset = v21;
              fraca = v21 + t;
              ExpressionTool::ForceScrubPosition(this, a2: (int)&this->m_flScrubberTimeOffset, frac: fraca);
            }
            CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
            ExpressionTool::StartDragging(
              this,
              dragtype: COERCE_FLOAT(1),
              startx: this->m_nClickedX,
              starty: this->m_nClickedY,
              cursor: CursorA);
            ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
            goto LABEL_137;
          }
          if ( ExpressionTool::IsMouseOverTag(this, mx: this->m_nClickedX, my: this->m_nClickedY) == nullptr )
          {
            if ( ExpressionTool::IsMouseOverPoints(this, mx: this->m_nClickedX, my: this->m_nClickedY) )
            {
              if ( !this->m_bSelectionActive )
              {
                v24 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
                ExpressionTool::StartDragging(
                  this,
                  dragtype: COERCE_FLOAT(3),
                  startx: this->m_nClickedX,
                  starty: this->m_nClickedY,
                  cursor: v24);
                ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
                goto LABEL_137;
              }
              if ( !ExpressionTool::IsMouseOverSelection(this, mx: this->m_nClickedX, my: this->m_nClickedY) )
              {
                redraw = this->redraw;
                this->m_bSelectionActive = false;
                redraw(this);
                cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
                return 1;
              }
              if ( ExpressionTool::IsMouseOverSelectionStartEdge(this, event: v4) )
              {
                v25 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
                ExpressionTool::StartDragging(
                  this,
                  dragtype: COERCE_FLOAT(5),
                  startx: this->m_nClickedX,
                  starty: this->m_nClickedY,
                  cursor: v25);
                ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
                goto LABEL_137;
              }
              if ( ExpressionTool::IsMouseOverSelectionEndEdge(this, event: v4) )
              {
                v26 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
                ExpressionTool::StartDragging(
                  this,
                  dragtype: COERCE_FLOAT(6),
                  startx: this->m_nClickedX,
                  starty: this->m_nClickedY,
                  cursor: v26);
                ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
                goto LABEL_137;
              }
              if ( v18 )
              {
                v27 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
                ExpressionTool::StartDragging(
                  this,
                  dragtype: COERCE_FLOAT(4),
                  startx: this->m_nClickedX,
                  starty: this->m_nClickedY,
                  cursor: v27);
                ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
                goto LABEL_137;
              }
            }
            else if ( mxWidget::w2(this) > 0 )
            {
              *(float *)&event = ExpressionTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
              ExpressionTool::SetScrubTargetTime(this, t: *(float *)&event);
            }
            ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
            goto LABEL_137;
          }
          v23 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
          ExpressionTool::StartDragging(
            this,
            dragtype: COERCE_FLOAT(2),
            startx: this->m_nClickedX,
            starty: this->m_nClickedY,
            cursor: v23);
          ExpressionTool::CalcBounds(this, movetype: this->m_nDragType);
        }
LABEL_137:
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return my;
      }
      ExpressionTool::ShowContextMenu(this, event: v4, include_track_menus: false);
LABEL_15:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return 1;
    case 8:
    case 9:
      v29 = SLOWORD(v4->y);
      this->m_nMousePos[0] = SLOWORD(v4->x);
      this->m_nMousePos[1] = v29;
      ExpressionTool::DrawMouseOverPos(this);
      ExpressionTool::OnMouseMove(this, event: v4);
      goto LABEL_136;
    case 0xA:
    case 0xB:
      v58 = CExpressionToolWorkspace::GetClickedItem(this: this->m_pWorkspace);
      if ( v58 != nullptr )
      {
        my = v58->handleEvent(this: v58, a2: v4);
        if ( my != 0 )
          goto LABEL_137;
      }
      if ( v4->key != 27 )
        goto LABEL_137;
      ExpressionTool::DeselectAll(this);
LABEL_136:
      my = 1;
      goto LABEL_137;
    case 0xC:
      if ( CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
      {
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
        v13 = (4 * ((v4->modifiers & 2) != 0)) | 1;
        if ( v4->height <= 0 )
        {
          v14 = TimeZoom - 2 * v13;
          if ( v14 <= 2 )
            v14 = 2;
        }
        else
        {
          v14 = TimeZoom + 2 * v13;
          if ( v14 >= 1000 )
            v14 = 1000;
        }
        CChoreoView::SetPreservedTimeZoom<ExpressionTool>(this: g_pChoreoView, other: this, tz: v14);
      }
      this->m_pWorkspace->redraw(this: this->m_pWorkspace);
      this->redraw(this);
      goto LABEL_136;
    default:
      goto LABEL_137;
  }
}
