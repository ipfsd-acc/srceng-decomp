// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choreoeventwidget.cpp
// Functions: 24
// ============================================================

#include "utils\hlfaceposer\choreoeventwidget.h"

//------------------------------------------------------------------------------
// Address: 0x00490320
// Name: public: CChoreoEventWidget::CChoreoEventWidget(class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoEventWidget *__thiscall CChoreoEventWidget::CChoreoEventWidget(CChoreoEventWidget *this, CChoreoWidget *parent)
{
  CChoreoWidget::CChoreoWidget(this, parent);
  this->m_pParent = parent;
  this->m_pEvent = nullptr;
  this->m_pWaveFile = nullptr;
  this->m_nDurationRightEdge = 0;
  this->__vftable = (CChoreoEventWidget_vtbl *)&CChoreoEventWidget::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00490360
// Name: public: virtual void CChoreoEventWidget::Layout(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::Layout(CChoreoEventWidget *this, tagRECT *rc)
{
  int v2; // edx

  v2 = rc->right - rc->left;
  this->m_nDurationRightEdge = v2;
  this->setBounds(this, a2: rc->left, a3: rc->top, a4: v2, a5: rc->bottom - rc->top);
}

//------------------------------------------------------------------------------
// Address: 0x00490390
// Name: public: void CChoreoEventWidget::SetEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::SetEvent(CChoreoEventWidget *this, CChoreoEvent *event)
{
  CAudioSource *m_pWaveFile; // ecx
  IFacePoserSound_vtbl *v4; // ebx
  char *v5; // eax
  char *v6; // eax

  sound->StopAll(this: sound);
  m_pWaveFile = this->m_pWaveFile;
  if ( m_pWaveFile != nullptr )
    ((void (__thiscall *)(CAudioSource *, int))m_pWaveFile->dtr_CAudioSource)(a1: m_pWaveFile, a2: 1);
  this->m_pWaveFile = nullptr;
  this->m_pEvent = event;
  if ( CChoreoEvent::GetType(this: event) == SPEAK )
  {
    v4 = sound->__vftable;
    v5 = FacePoser_TranslateSoundName(event);
    v6 = va(fmt: "sound/%s", v5);
    this->m_pWaveFile = v4->LoadSound(this: sound, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490400
// Name: public: void CChoreoEventWidget::RecomputeWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::RecomputeWave(CChoreoEventWidget *this)
{
  CAudioSource *m_pWaveFile; // ecx
  IFacePoserSound_vtbl *v3; // edi
  char *v4; // eax
  char *v5; // eax

  if ( CChoreoEvent::GetType(this: this->m_pEvent) == SPEAK )
  {
    m_pWaveFile = this->m_pWaveFile;
    if ( m_pWaveFile != nullptr )
      ((void (__thiscall *)(CAudioSource *, int))m_pWaveFile->dtr_CAudioSource)(a1: m_pWaveFile, a2: 1);
    v3 = sound->__vftable;
    v4 = FacePoser_TranslateSoundName(event: this->m_pEvent);
    v5 = va(fmt: "sound/%s", v4);
    this->m_pWaveFile = v3->LoadSound(this: sound, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490450
// Name: public: static void CChoreoEventWidget::LoadImages(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CChoreoEventWidget::LoadImages()
{
  mxbitmapdata_t *v0; // eax

  v0 = CChoreoEventWidget::m_Bitmaps;
  do
  {
    v0->valid = false;
    ++v0;
  }
  while ( (int)v0 < (int)&CChoreoEventWidget::m_LockBodyFacingBitmap );
  CChoreoEventWidget::m_ResumeConditionBitmap.valid = false;
  CChoreoEventWidget::m_LockBodyFacingBitmap.valid = false;
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_expression.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[2]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_lookat.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[3]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_moveto.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[4]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_speak.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[5]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_gesture.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[6]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_face.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[8]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_firetrigger.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[9]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_sequence.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[7]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_flexanimation.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[10]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_subscene.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[11]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_loop.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[12]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/pause.bmp", bitmap: &CChoreoEventWidget::m_ResumeConditionBitmap);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_interrupt.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[13]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_stoppoint.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[14]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_permit_response.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[15]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_generic.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[16]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/ev_generic.bmp", bitmap: &CChoreoEventWidget::m_Bitmaps[17]);
  LoadBitmapFromFile(relative: "gfx/hlfaceposer/lock.bmp", bitmap: &CChoreoEventWidget::m_LockBodyFacingBitmap);
}

//------------------------------------------------------------------------------
// Address: 0x00490590
// Name: public: static void CChoreoEventWidget::DestroyImages(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CChoreoEventWidget::DestroyImages()
{
  void **p_image; // esi
  void *v1; // [esp-4h] [ebp-10h]

  p_image = &CChoreoEventWidget::m_Bitmaps[0].image;
  do
  {
    if ( *((_BYTE *)p_image - 4) != 0 )
    {
      v1 = *p_image;
      *((_BYTE *)p_image - 4) = 0;
      DeleteObject(ho: v1);
      *p_image = nullptr;
    }
    p_image += 4;
  }
  while ( (int)p_image < (int)&CChoreoEventWidget::m_LockBodyFacingBitmap.image );
  if ( CChoreoEventWidget::m_ResumeConditionBitmap.valid )
  {
    CChoreoEventWidget::m_ResumeConditionBitmap.valid = false;
    DeleteObject(ho: CChoreoEventWidget::m_ResumeConditionBitmap.image);
    CChoreoEventWidget::m_ResumeConditionBitmap.image = nullptr;
  }
  if ( CChoreoEventWidget::m_LockBodyFacingBitmap.valid )
  {
    CChoreoEventWidget::m_LockBodyFacingBitmap.valid = false;
    DeleteObject(ho: CChoreoEventWidget::m_LockBodyFacingBitmap.image);
    CChoreoEventWidget::m_LockBodyFacingBitmap.image = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490600
// Name: public: static struct mxbitmapdata_t __near * CChoreoEventWidget::GetImage(int)
// Source: json
//------------------------------------------------------------------------------
mxbitmapdata_t *__cdecl CChoreoEventWidget::GetImage(int type)
{
  return &CChoreoEventWidget::m_Bitmaps[type];
}

//------------------------------------------------------------------------------
// Address: 0x00490650
// Name: private: char const __near * CChoreoEventWidget::GetLabelText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoEventWidget::GetLabelText(CChoreoEventWidget *this)
{
  CChoreoEvent *m_pEvent; // esi
  const char *Parameters; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  const char *Parameters2; // [esp-4h] [ebp-8h]

  if ( CChoreoEvent::GetType(this: this->m_pEvent) == 2 )
  {
    m_pEvent = this->m_pEvent;
    Parameters2 = CChoreoEvent::GetParameters2(this: m_pEvent);
    Parameters = CChoreoEvent::GetParameters(this: m_pEvent);
    sprintf(string: label, format: "%s : %s", Parameters, Parameters2);
    return label;
  }
  else
  {
    v5 = (char *)CChoreoEvent::GetParameters(this: this->m_pEvent);
    v6 = (char *)(label - v5);
    do
    {
      v7 = *v5;
      v5[(_DWORD)v6] = *v5;
      ++v5;
    }
    while ( v7 != 0 );
    return label;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004906C0
// Name: private: void CChoreoEventWidget::DrawRelativeTags(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::DrawRelativeTags(
        CChoreoEventWidget *this,
        CChoreoWidgetDrawHelper *drawHelper,
        int rcWAV,
        float length,
        CChoreoEvent *event)
{
  int v5; // esi
  tagRECT *v6; // edi
  CEventAbsoluteTag *RelativeTag; // eax
  CEventAbsoluteTag *v8; // ebx
  int v9; // esi
  double Percentage; // st7
  int v11; // esi
  const char *Name; // eax
  int v13; // eax
  const char *v14; // eax
  tagRECT rcText; // [esp+4h] [ebp-30h] BYREF
  tagRECT rcMark; // [esp+14h] [ebp-20h] BYREF
  int left; // [esp+24h] [ebp-10h]
  int v18; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  Color clr; // [esp+30h] [ebp-4h] BYREF

  v5 = 0;
  i = 0;
  if ( CChoreoEvent::GetNumRelativeTags(this: event) > 0 )
  {
    v6 = (tagRECT *)rcWAV;
    do
    {
      RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: event, tagnum: v5);
      v8 = RelativeTag;
      if ( RelativeTag != nullptr )
      {
        left = v6->left;
        v9 = left;
        Percentage = CEventAbsoluteTag::GetPercentage(this: RelativeTag);
        v18 = v6->right - v9;
        v11 = left + (int)(Percentage * (double)v18 + 0.5);
        *(_QWORD *)&rcMark.left = *(_QWORD *)&v6->left;
        rcMark.top -= 2;
        rcMark.bottom = rcMark.top + 6;
        rcMark.left = v11 - 3;
        rcMark.right = v11 + 3;
        rcWAV = 16409600;
        CChoreoWidgetDrawHelper::DrawTriangleMarker(
          this: drawHelper,
          rc: &rcMark,
          fill: (const Color *)&rcWAV,
          inverted: false);
        rcText.left = rcMark.left;
        *(_QWORD *)&rcText.right = *(_QWORD *)&rcMark.right;
        rcText.top = rcMark.top - 12;
        Name = CEventAbsoluteTag::GetName(this: v8);
        v13 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: Name);
        rcText.bottom = rcText.top + 10;
        rcText.left = v11 - v13 / 2;
        rcText.right = rcText.left + v13 + 2;
        clr = (Color)13132800;
        v14 = CEventAbsoluteTag::GetName(this: v8);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          &clr,
          &rcText,
          fmt: v14);
        v5 = i;
      }
      i = ++v5;
    }
    while ( v5 < CChoreoEvent::GetNumRelativeTags(this: event) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490810
// Name: private: void CChoreoEventWidget::DrawAbsoluteTags(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::DrawAbsoluteTags(
        CChoreoEventWidget *this,
        CChoreoWidgetDrawHelper *drawHelper,
        int rcWAV,
        float length,
        CChoreoEvent *event)
{
  int v5; // esi
  tagRECT *v6; // edi
  CEventAbsoluteTag *AbsoluteTag; // eax
  CEventAbsoluteTag *v8; // ebx
  int v9; // esi
  double Percentage; // st7
  int v11; // esi
  const char *Name; // eax
  int v13; // eax
  const char *v14; // eax
  tagRECT rcText; // [esp+4h] [ebp-30h] BYREF
  tagRECT rcMark; // [esp+14h] [ebp-20h] BYREF
  int left; // [esp+24h] [ebp-10h]
  int v18; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  Color clr; // [esp+30h] [ebp-4h] BYREF

  v5 = 0;
  i = 0;
  if ( CChoreoEvent::GetNumAbsoluteTags(this: event, type: PLAYBACK) > 0 )
  {
    v6 = (tagRECT *)rcWAV;
    do
    {
      AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: event, type: PLAYBACK, tagnum: v5);
      v8 = AbsoluteTag;
      if ( AbsoluteTag != nullptr )
      {
        left = v6->left;
        v9 = left;
        Percentage = CEventAbsoluteTag::GetPercentage(this: AbsoluteTag);
        v18 = v6->right - v9;
        v11 = left + (int)(Percentage * (double)v18 + 0.5);
        *(_QWORD *)&rcMark.left = *(_QWORD *)&v6->left;
        rcMark.top -= 2;
        rcMark.bottom = rcMark.top + 6;
        rcMark.left = v11 - 3;
        rcMark.right = v11 + 3;
        rcWAV = 16409600;
        CChoreoWidgetDrawHelper::DrawTriangleMarker(
          this: drawHelper,
          rc: &rcMark,
          fill: (const Color *)&rcWAV,
          inverted: false);
        rcText.left = rcMark.left;
        *(_QWORD *)&rcText.right = *(_QWORD *)&rcMark.right;
        rcText.top = rcMark.top - 12;
        Name = CEventAbsoluteTag::GetName(this: v8);
        v13 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: Name);
        rcText.bottom = rcText.top + 10;
        rcText.left = v11 - v13 / 2;
        rcText.right = rcText.left + v13 + 2;
        clr = (Color)13132800;
        v14 = CEventAbsoluteTag::GetName(this: v8);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          &clr,
          &rcText,
          fmt: v14);
        v5 = i;
      }
      i = ++v5;
    }
    while ( v5 < CChoreoEvent::GetNumAbsoluteTags(this: event, type: PLAYBACK) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490960
// Name: public: virtual void CChoreoEventWidget::redrawStatus(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::redrawStatus(CChoreoEventWidget *this, HDC__ *drawHelper, int rcClient)
{
  bool (__thiscall *getVisible)(struct CChoreoEventWidget *); // edx
  CChoreoEvent *m_pEvent; // esi
  mxbitmapdata_t *v7; // ebx
  int v8; // eax
  CChoreoEvent::EVENTTYPE Type; // eax
  const char *v10; // eax
  CChoreoEvent::EVENTTYPE v11; // eax
  const char *v12; // eax
  char *LabelText; // eax
  const char *Name; // [esp-Ch] [ebp-44h]
  const char *v15; // [esp-Ch] [ebp-44h]
  tagRECT rcFixed; // [esp+4h] [ebp-34h] BYREF
  tagRECT rc; // [esp+14h] [ebp-24h]
  tagRECT rcEventLabel; // [esp+24h] [ebp-14h] BYREF
  CChoreoEventWidget *v19; // [esp+34h] [ebp-4h]
  HDC__ *dc; // [esp+40h] [ebp+8h]

  getVisible = this->getVisible;
  v19 = this;
  if ( ((unsigned __int8 (__fastcall *)(CChoreoEventWidget *))getVisible)(a1: this) != 0 )
  {
    m_pEvent = this->m_pEvent;
    if ( m_pEvent != nullptr )
    {
      dc = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)drawHelper);
      rcEventLabel = *(tagRECT *)rcClient;
      InflateRect(lprc: &rcEventLabel, dx: 0, dy: -1);
      rcEventLabel.left += 2;
      if ( &CChoreoEventWidget::m_Bitmaps[CChoreoEvent::GetType(this: m_pEvent)] != nullptr )
      {
        v7 = &CChoreoEventWidget::m_Bitmaps[CChoreoEvent::GetType(this: m_pEvent)];
        if ( v7 != nullptr )
        {
          rcFixed = rcEventLabel;
          CChoreoWidgetDrawHelper::OffsetSubRect(this: (CChoreoWidgetDrawHelper *)drawHelper, rc: &rcFixed);
          DrawBitmapToDC(hdc: dc, x: rcFixed.left, y: rcFixed.top, w: 16, h: 16, bitmap: v7);
        }
      }
      OffsetRect(lprc: &rcEventLabel, dx: 16, dy: 0);
      if ( CChoreoEvent::IsResumeCondition(this: m_pEvent) )
      {
        rc = rcEventLabel;
        OffsetRect(lprc: &rcEventLabel, dx: 16, dy: 0);
        rc.right = rc.left + 16;
        rc.bottom = rc.top + 16;
        rcFixed = rc;
        CChoreoWidgetDrawHelper::OffsetSubRect(this: (CChoreoWidgetDrawHelper *)drawHelper, rc: &rcFixed);
        DrawBitmapToDC(
          hdc: dc,
          x: rcFixed.left,
          y: rcFixed.top,
          w: rcFixed.right - rcFixed.left,
          h: rcFixed.bottom - rcFixed.top,
          bitmap: &CChoreoEventWidget::m_ResumeConditionBitmap);
      }
      if ( CChoreoEvent::IsLockBodyFacing(this: m_pEvent) )
      {
        rc = rcEventLabel;
        OffsetRect(lprc: &rcEventLabel, dx: 16, dy: 0);
        rc.right = rc.left + 16;
        rc.bottom = rc.top + 16;
        rcFixed = rc;
        CChoreoWidgetDrawHelper::OffsetSubRect(this: (CChoreoWidgetDrawHelper *)drawHelper, rc: &rcFixed);
        DrawBitmapToDC(
          hdc: dc,
          x: rcFixed.left,
          y: rcFixed.top,
          w: rcFixed.right - rcFixed.left,
          h: rcFixed.bottom - rcFixed.top,
          bitmap: &CChoreoEventWidget::m_LockBodyFacingBitmap);
      }
      OffsetRect(lprc: &rcEventLabel, dx: 2, dy: 1);
      v8 = *(_DWORD *)rcClient + 32;
      rcEventLabel.bottom = rcEventLabel.top + 11;
      rcEventLabel.left = v8;
      Name = CChoreoEvent::GetName(this: m_pEvent);
      Type = CChoreoEvent::GetType(this: m_pEvent);
      v10 = CChoreoEvent::NameForType(type: Type);
      CChoreoWidgetDrawHelper::CalcTextWidth(
        font: "Arial",
        pointsize: (HFONT__ *)9,
        weight: 400,
        fmt: "%s event \"%s\"",
        v10,
        Name);
      rcClient = 7999;
      v15 = CChoreoEvent::GetName(this: m_pEvent);
      v11 = CChoreoEvent::GetType(this: m_pEvent);
      v12 = CChoreoEvent::NameForType(type: v11);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: (CChoreoWidgetDrawHelper *)drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&rcClient,
        rcText: &rcEventLabel,
        fmt: "%s event \"%s\"",
        v12,
        v15);
      OffsetRect(lprc: &rcEventLabel, dx: 0, dy: 11);
      rcClient = 7999;
      LabelText = CChoreoEventWidget::GetLabelText(this: v19);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: (CChoreoWidgetDrawHelper *)drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&rcClient,
        rcText: &rcEventLabel,
        fmt: "parameters \"%s\"",
        LabelText);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490C00
// Name: private: class Color CChoreoEventWidget::GrayOutColor(class Color)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CChoreoEventWidget::GrayOutColor(CChoreoEventWidget *this, Color *result, Color clr)
{
  CChoreoEvent *m_pEvent; // ecx
  int v5; // eax

  m_pEvent = this->m_pEvent;
  if ( m_pEvent != nullptr )
  {
    if ( !CChoreoEvent::GetActive(this: m_pEvent) )
    {
      v5 = (unsigned __int64)(1431655766LL * (clr._color[0] + clr._color[1] + clr._color[2])) >> 32;
      clr._color[0] = (int)(float)((float)((float)(255 - v5) * 0.25) + (float)v5);
      clr._color[1] = clr._color[0];
      clr._color[2] = clr._color[0];
      clr._color[3] = 0;
    }
    *result = clr;
    return result;
  }
  else
  {
    *result = clr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490C80
// Name: private: void CChoreoEventWidget::DrawSpeakEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChoreoEventWidget::DrawSpeakEvent(
        CChoreoEventWidget *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Color drawHelper,
        tagRECT *rcEventLine)
{
  bool IsRampOnly; // al
  CChoreoWidgetDrawHelper *v7; // ebx
  HDC__ *NumChannels; // eax
  Color *v9; // eax
  HBRUSH__ *SolidBrush; // eax
  Color *v11; // eax
  HBRUSH__ *v12; // eax
  tagRECT *v13; // edi
  Color *v14; // eax
  HPEN__ *v15; // eax
  HPEN__ *v16; // eax
  int left; // [esp+1Ch] [ebp-3Ch]
  int top; // [esp+20h] [ebp-38h]
  int v19; // [esp+20h] [ebp-38h]
  int length; // [esp+24h] [ebp-34h]
  int lengtha; // [esp+24h] [ebp-34h]
  float lengthb; // [esp+24h] [ebp-34h]
  float v23; // [esp+28h] [ebp-30h]
  int bottom; // [esp+28h] [ebp-30h]
  int v25; // [esp+28h] [ebp-30h]
  CChoreoEvent *v26; // [esp+28h] [ebp-30h]
  Color v29; // [esp+38h] [ebp-20h] BYREF
  Color v30; // [esp+3Ch] [ebp-1Ch] BYREF
  Color result; // [esp+40h] [ebp-18h] BYREF
  CChoreoEvent *event; // [esp+44h] [ebp-14h]
  HBRUSH__ *brEvent; // [esp+48h] [ebp-10h]
  HBRUSH__ *brBackground; // [esp+4Ch] [ebp-Ch]
  HDC__ *dc; // [esp+50h] [ebp-8h]
  bool ramponly; // [esp+57h] [ebp-1h]

  if ( this->m_pWaveFile != nullptr )
  {
    IsRampOnly = CChoreoView::IsRampOnly(this: CChoreoWidget::m_pView);
    v7 = (CChoreoWidgetDrawHelper *)drawHelper;
    ramponly = IsRampOnly;
    event = this->m_pEvent;
    NumChannels = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: *(IterateRIFF **)&drawHelper);
    drawHelper = (Color)((char *)&g_flexedverts[204].z + 2);
    dc = NumChannels;
    v9 = CChoreoEventWidget::GrayOutColor(this, &result, clr: (Color)((char *)&g_flexedverts[204].z + 2));
    SolidBrush = CreateSolidBrush(color: v9->_color[0] | ((v9->_color[1] | (v9->_color[2] << 8)) << 8));
    drawHelper = (Color)13166310;
    brEvent = SolidBrush;
    v11 = CChoreoEventWidget::GrayOutColor(this, result: &v30, clr: (Color)13166310);
    v12 = CreateSolidBrush(color: v11->_color[0] | ((v11->_color[1] | (v11->_color[2] << 8)) << 8));
    v13 = rcEventLine;
    brBackground = v12;
    if ( !ramponly )
      FillRect(hDC: dc, lprc: rcEventLine, hbr: v12);
    if ( this->IsSelected(this) )
    {
      if ( ((unsigned __int8 (__thiscall *)(CChoreoEventWidget *, int, int))this->IsSelected)(a1: this, a2: a3, a3: a2) != 0 )
        drawHelper = (Color)9869020;
      else
        drawHelper = (Color)((char *)&g_flexedverts[204].z + 2);
      rcEventLine = (tagRECT *)sound->__vftable;
      v23 = ((double (__stdcall *)(CAudioSource *, _DWORD))this->m_pWaveFile->GetRunningLength)(
              a1: this->m_pWaveFile,
              a2: 0);
      v14 = CChoreoEventWidget::GrayOutColor(this, result: &v29, clr: drawHelper);
      ((void (__thiscall *)(IFacePoserSound *, HDC__ *, tagRECT *, Color *, _DWORD, _DWORD))rcEventLine[3].left)(
        a1: sound,
        a2: dc,
        a3: v13,
        a4: v14,
        a5: 0,
        a6: LODWORD(v23));
    }
    bottom = v13->bottom;
    length = v13->left;
    top = v13->top;
    left = v13->left;
    drawHelper = (Color)((char *)&g_flexedverts[204].z + 2);
    v15 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(
                      this,
                      result: &drawHelper,
                      clr: (Color)((char *)&g_flexedverts[204].z + 2));
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v7,
      clr: v15,
      style: 0,
      width: 3,
      x1: left,
      y1: top,
      x2: length,
      y2: bottom);
    v25 = v13->bottom;
    lengtha = v13->right;
    v19 = v13->top;
    drawHelper = (Color)((char *)&g_flexedverts[204].z + 2);
    v16 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(
                      this,
                      result: &drawHelper,
                      clr: (Color)((char *)&g_flexedverts[204].z + 2));
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v7,
      clr: v16,
      style: 0,
      width: 3,
      x1: lengtha,
      y1: v19,
      x2: lengtha,
      y2: v25);
    DeleteObject(ho: brBackground);
    DeleteObject(ho: brEvent);
    v26 = event;
    lengthb = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
    CChoreoEventWidget::DrawRelativeTags(this, drawHelper: v7, rcWAV: (int)v13, length: lengthb, event: v26);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490E50
// Name: private: void CChoreoEventWidget::DrawGestureEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::DrawGestureEvent(CChoreoEventWidget *this, int drawHelper, tagRECT *rcEventLine)
{
  bool IsRampOnly; // al
  CChoreoWidgetDrawHelper *v5; // edi
  HDC__ *NumChannels; // eax
  CChoreoEventWidget_vtbl *v7; // edx
  bool (__thiscall *IsSelected)(struct CChoreoEventWidget *); // eax
  const char *Name; // eax
  Color v10; // ecx
  HBRUSH__ *SolidBrush; // eax
  Color *v12; // eax
  HPEN__ *v13; // eax
  HPEN__ *v14; // eax
  HPEN__ *v15; // eax
  HPEN__ *v16; // eax
  Color *v17; // eax
  CChoreoEvent *v18; // ebx
  int left; // [esp-8h] [ebp-44h]
  int v20; // [esp-8h] [ebp-44h]
  int right; // [esp-8h] [ebp-44h]
  int v22; // [esp-8h] [ebp-44h]
  int bottom; // [esp-4h] [ebp-40h]
  int v24; // [esp-4h] [ebp-40h]
  int v25; // [esp-4h] [ebp-40h]
  int v26; // [esp-4h] [ebp-40h]
  int time; // [esp+0h] [ebp-3Ch]
  int timea; // [esp+0h] [ebp-3Ch]
  int timeb; // [esp+0h] [ebp-3Ch]
  int timec; // [esp+0h] [ebp-3Ch]
  float timed; // [esp+0h] [ebp-3Ch]
  float timee; // [esp+0h] [ebp-3Ch]
  float timef; // [esp+0h] [ebp-3Ch]
  float timeg; // [esp+0h] [ebp-3Ch]
  int top; // [esp+4h] [ebp-38h]
  int v36; // [esp+4h] [ebp-38h]
  int v37; // [esp+4h] [ebp-38h]
  int v38; // [esp+4h] [ebp-38h]
  tagRECT *v39; // [esp+4h] [ebp-38h]
  tagRECT rcEventLine2; // [esp+14h] [ebp-28h] BYREF
  Color clr; // [esp+24h] [ebp-18h] BYREF
  HDC__ *dc; // [esp+28h] [ebp-14h] BYREF
  CChoreoEvent *event; // [esp+2Ch] [ebp-10h]
  Color clrEvent; // [esp+30h] [ebp-Ch] BYREF
  HBRUSH__ *brEvent; // [esp+34h] [ebp-8h]
  bool ramponly; // [esp+3Bh] [ebp-1h]

  event = this->m_pEvent;
  rcEventLine2 = *rcEventLine;
  IsRampOnly = CChoreoView::IsRampOnly(this: CChoreoWidget::m_pView);
  v5 = (CChoreoWidgetDrawHelper *)drawHelper;
  ramponly = IsRampOnly;
  NumChannels = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)drawHelper);
  v7 = this->__vftable;
  dc = NumChannels;
  IsSelected = v7->IsSelected;
  HIBYTE(drawHelper) = 0;
  brEvent = (HBRUSH__ *)9869020;
  if ( !IsSelected(this) )
    brEvent = (HBRUSH__ *)((char *)&g_flexedverts[204].z + 2);
  CChoreoEventWidget::GrayOutColor(this, result: &clrEvent, clr: (Color)brEvent);
  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    v10 = clrEvent;
  }
  else
  {
    drawHelper = 7877170;
    v10 = *CChoreoEventWidget::GrayOutColor(this, result: (Color *)&drawHelper, clr: (Color)7877170);
    clrEvent = v10;
    HIBYTE(drawHelper) = 1;
  }
  SolidBrush = CreateSolidBrush(color: v10._color[0] | ((v10._color[1] | (v10._color[2] << 8)) << 8));
  brEvent = SolidBrush;
  if ( !ramponly )
  {
    FillRect(hDC: dc, lprc: &rcEventLine2, hbr: SolidBrush);
    SolidBrush = brEvent;
  }
  DeleteObject(ho: SolidBrush);
  if ( ramponly && this->IsSelected(this) )
  {
    brEvent = (HBRUSH__ *)16430230;
    v12 = CChoreoEventWidget::GrayOutColor(this, result: (Color *)&dc, clr: (Color)16430230);
    CChoreoWidgetDrawHelper::DrawOutlinedRect(this: v5, clr: v12, style: 0, width: (HBRUSH__ *)1, rc: &rcEventLine2);
  }
  else
  {
    top = rcEventLine2.top;
    time = rcEventLine2.left;
    bottom = rcEventLine2.bottom;
    left = rcEventLine2.left;
    brEvent = (HBRUSH__ *)8355711;
    v13 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: (Color *)&dc, clr: (Color)8355711);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v5,
      clr: v13,
      style: 0,
      width: 1,
      x1: left,
      y1: bottom,
      x2: time,
      y2: top);
    v36 = rcEventLine2.top;
    timea = rcEventLine2.right;
    v24 = rcEventLine2.top;
    v20 = rcEventLine2.left;
    brEvent = (HBRUSH__ *)8355711;
    v14 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: (Color *)&dc, clr: (Color)8355711);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v5,
      clr: v14,
      style: 0,
      width: 1,
      x1: v20,
      y1: v24,
      x2: timea,
      y2: v36);
    v37 = rcEventLine2.bottom;
    timeb = rcEventLine2.right;
    v25 = rcEventLine2.top;
    right = rcEventLine2.right;
    brEvent = (HBRUSH__ *)2039583;
    v15 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: (Color *)&dc, clr: (Color)2039583);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v5,
      clr: v15,
      style: 0,
      width: 1,
      x1: right,
      y1: v25,
      x2: timeb,
      y2: v37);
    v38 = rcEventLine2.bottom;
    timec = rcEventLine2.left;
    v26 = rcEventLine2.bottom;
    v22 = rcEventLine2.right;
    brEvent = nullptr;
    v16 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: (Color *)&dc, clr: 0);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v5,
      clr: v16,
      style: 0,
      width: 1,
      x1: v22,
      y1: v26,
      x2: timec,
      y2: v38);
  }
  timed = CChoreoEvent::GetStartTime(this: event);
  dc = (HDC__ *)CChoreoView::GetPixelForTimeValue(this: CChoreoWidget::m_pView, time: timed, clipped: nullptr);
  timee = CChoreoEvent::GetEndTime(this: event);
  brEvent = (HBRUSH__ *)CChoreoView::GetPixelForTimeValue(this: CChoreoWidget::m_pView, time: timee, clipped: nullptr);
  if ( HIBYTE(drawHelper) == 0 )
  {
    CChoreoWidgetDrawHelper::DrawColoredRamp(
      this: v5,
      &clr,
      style: (unsigned __int8 *)&clrEvent,
      width: 0,
      x1: 1,
      y1: (int)dc,
      x2: rcEventLine2.bottom,
      y2: rcEventLine2.left,
      rate: *(float *)&rcEventLine2.top,
      sustain: 0.0,
      sustaina: 1.0);
    CChoreoWidgetDrawHelper::DrawColoredRamp(
      this: v5,
      &clr,
      style: (unsigned __int8 *)&clrEvent,
      width: 0,
      x1: 1,
      y1: rcEventLine2.right,
      x2: rcEventLine2.top,
      y2: (int)brEvent,
      rate: *(float *)&rcEventLine2.bottom,
      sustain: 0.0,
      sustaina: 1.0);
  }
  drawHelper = 4144959;
  v39 = rcEventLine;
  v17 = CChoreoEventWidget::GrayOutColor(this, result: (Color *)&drawHelper, clr: (Color)4144959);
  v18 = event;
  RampTool::DrawSamplesSimple(
    this: g_pRampTool,
    drawHelper: v5,
    e: event,
    clearbackground: 0.0,
    sampleColor: *(float *)&v17,
    rcSamples: *(float *)&v39);
  timef = v18->GetDuration(this: v18);
  CChoreoEventWidget::DrawRelativeTags(this, drawHelper: v5, rcWAV: (int)rcEventLine, length: timef, event: v18);
  timeg = v18->GetDuration(this: v18);
  CChoreoEventWidget::DrawAbsoluteTags(this, drawHelper: v5, rcWAV: (int)rcEventLine, length: timeg, event: v18);
}

//------------------------------------------------------------------------------
// Address: 0x00491150
// Name: private: void CChoreoEventWidget::DrawGenericEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::DrawGenericEvent(CChoreoEventWidget *this, Color drawHelper, tagRECT *rcEventLine)
{
  bool IsRampOnly; // al
  CChoreoEvent *m_pEvent; // esi
  CChoreoWidgetDrawHelper *v6; // ebx
  bool v7; // al
  Color v8; // eax
  CChoreoWidgetDrawHelper *SolidBrush; // eax
  tagRECT *v10; // esi
  Color *v11; // eax
  HPEN__ *v12; // eax
  HPEN__ *v13; // eax
  HPEN__ *v14; // eax
  HPEN__ *v15; // eax
  Color *v16; // eax
  int left; // [esp-8h] [ebp-28h]
  int v18; // [esp-8h] [ebp-28h]
  int right; // [esp-8h] [ebp-28h]
  int bottom; // [esp-4h] [ebp-24h]
  int v21; // [esp-4h] [ebp-24h]
  int length; // [esp+0h] [ebp-20h]
  int lengtha; // [esp+0h] [ebp-20h]
  int lengthb; // [esp+0h] [ebp-20h]
  int lengthc; // [esp+0h] [ebp-20h]
  float lengthd; // [esp+0h] [ebp-20h]
  float lengthe; // [esp+0h] [ebp-20h]
  int top; // [esp+4h] [ebp-1Ch]
  int v29; // [esp+4h] [ebp-1Ch]
  int v30; // [esp+4h] [ebp-1Ch]
  int v31; // [esp+4h] [ebp-1Ch]
  HDC__ *dc; // [esp+14h] [ebp-Ch]
  CChoreoEvent *event; // [esp+18h] [ebp-8h]
  bool ramponly; // [esp+1Fh] [ebp-1h]

  IsRampOnly = CChoreoView::IsRampOnly(this: CChoreoWidget::m_pView);
  m_pEvent = this->m_pEvent;
  v6 = (CChoreoWidgetDrawHelper *)drawHelper;
  ramponly = IsRampOnly;
  event = m_pEvent;
  dc = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: *(IterateRIFF **)&drawHelper);
  v7 = this->IsSelected(this);
  drawHelper = (Color)9869020;
  if ( !v7 )
    drawHelper = (Color)((char *)&g_flexedverts[204].z + 2);
  CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: drawHelper);
  if ( CChoreoEvent::GetType(this: m_pEvent) == SUBSCENE )
  {
    drawHelper = (Color)13153480;
    v8 = *CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: (Color)13153480);
  }
  else
  {
    v8 = drawHelper;
  }
  SolidBrush = (CChoreoWidgetDrawHelper *)CreateSolidBrush(color: v8._color[0] | ((v8._color[1] | (v8._color[2] << 8)) << 8));
  v10 = rcEventLine;
  drawHelper = (Color)SolidBrush;
  if ( !ramponly )
  {
    FillRect(hDC: dc, lprc: rcEventLine, hbr: (HBRUSH)SolidBrush);
    SolidBrush = (CChoreoWidgetDrawHelper *)drawHelper;
  }
  DeleteObject(ho: SolidBrush);
  if ( ramponly && this->IsSelected(this) )
  {
    drawHelper = (Color)16430230;
    v11 = CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: (Color)16430230);
    CChoreoWidgetDrawHelper::DrawOutlinedRect(this: v6, clr: v11, style: 0, width: (HBRUSH__ *)1, rc: v10);
  }
  else
  {
    top = v10->top;
    length = v10->left;
    bottom = v10->bottom;
    left = v10->left;
    drawHelper = (Color)8355711;
    v12 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: (Color)8355711);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v6,
      clr: v12,
      style: 0,
      width: 1,
      x1: left,
      y1: bottom,
      x2: length,
      y2: top);
    v29 = v10->top;
    lengtha = v10->right;
    v18 = v10->left;
    drawHelper = (Color)8355711;
    v13 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: (Color)8355711);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v6,
      clr: v13,
      style: 0,
      width: 1,
      x1: v18,
      y1: v29,
      x2: lengtha,
      y2: v29);
    v30 = v10->bottom;
    lengthb = v10->right;
    v21 = v10->top;
    drawHelper = (Color)2039583;
    v14 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: (Color)2039583);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v6,
      clr: v14,
      style: 0,
      width: 1,
      x1: lengthb,
      y1: v21,
      x2: lengthb,
      y2: v30);
    v31 = v10->bottom;
    lengthc = v10->left;
    right = v10->right;
    drawHelper = 0;
    v15 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: 0);
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: v6,
      clr: v15,
      style: 0,
      width: 1,
      x1: right,
      y1: v31,
      x2: lengthc,
      y2: v31);
  }
  drawHelper = (Color)4144959;
  v16 = CChoreoEventWidget::GrayOutColor(this, result: &drawHelper, clr: (Color)4144959);
  RampTool::DrawSamplesSimple(
    this: g_pRampTool,
    drawHelper: v6,
    e: event,
    clearbackground: 0.0,
    sampleColor: *(float *)&v16,
    rcSamples: *(float *)&v10);
  lengthd = ((double (*)(void))event->GetDuration)();
  CChoreoEventWidget::DrawRelativeTags(this, drawHelper: v6, rcWAV: (int)v10, length: lengthd, event);
  lengthe = ((double (*)(void))event->GetDuration)();
  CChoreoEventWidget::DrawAbsoluteTags(this, drawHelper: v6, rcWAV: (int)v10, length: lengthe, event);
}

//------------------------------------------------------------------------------
// Address: 0x00491370
// Name: public: virtual void CChoreoEventWidget::redraw(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoEventWidget::redraw(CChoreoEventWidget *this, CChoreoWidgetDrawHelper *drawHelper)
{
  CChoreoEvent *m_pEvent; // edi
  bool IsRampOnly; // al
  CChoreoEventWidget_vtbl *v5; // edx
  int v6; // xmm1_4
  double StartTime; // st7
  double PixelsPerSecond; // st7
  bool HasEndTime; // al
  __int32 v10; // eax
  HPEN__ *v11; // eax
  const char *RelativeTagName; // eax
  int v13; // eax
  const Color *v14; // eax
  const Color *v15; // eax
  mxbitmapdata_t *v16; // eax
  const char *Name; // eax
  int v18; // eax
  const Color *v19; // eax
  int v20; // [esp-Ch] [ebp-A0h]
  int v21; // [esp-Ch] [ebp-A0h]
  int top; // [esp-8h] [ebp-9Ch]
  int v23; // [esp-8h] [ebp-9Ch]
  int v24; // [esp-4h] [ebp-98h]
  int v25; // [esp-4h] [ebp-98h]
  float endtime; // [esp+0h] [ebp-94h]
  int endtimea; // [esp+0h] [ebp-94h]
  const char *endtimeb; // [esp+0h] [ebp-94h]
  int endtimec; // [esp+0h] [ebp-94h]
  const char *endtimed; // [esp+0h] [ebp-94h]
  tagRECT dummy; // [esp+10h] [ebp-84h] BYREF
  tagRECT rcDC; // [esp+20h] [ebp-74h] BYREF
  tagRECT rcEvent; // [esp+30h] [ebp-64h] BYREF
  tagRECT rcClient; // [esp+40h] [ebp-54h] BYREF
  tagRECT rcEventLabel; // [esp+50h] [ebp-44h] BYREF
  Color clrSelection; // [esp+60h] [ebp-34h] BYREF
  tagRECT rc; // [esp+64h] [ebp-30h] BYREF
  HDC__ *dc; // [esp+74h] [ebp-20h]
  tagRECT rcFixed; // [esp+78h] [ebp-1Ch] BYREF
  bool ramponly; // [esp+8Bh] [ebp-9h]
  HBRUSH__ *brSelected; // [esp+8Ch] [ebp-8h] BYREF
  Color clrBorder; // [esp+90h] [ebp-4h] BYREF

  if ( this->getVisible(this) )
  {
    m_pEvent = this->m_pEvent;
    if ( m_pEvent != nullptr )
    {
      dc = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)drawHelper);
      rcClient = *this->getBounds(this);
      CChoreoWidgetDrawHelper::GetClientRect(this: drawHelper, rc: &rcDC);
      if ( IntersectRect(lprcDst: &dummy, lprcSrc1: &rcDC, lprcSrc2: &rcClient) )
      {
        IsRampOnly = CChoreoView::IsRampOnly(this: CChoreoWidget::m_pView);
        v5 = this->__vftable;
        ramponly = IsRampOnly;
        if ( v5->IsSelected(this) && !ramponly )
        {
          InflateRect(lprc: &rcClient, dx: 3, dy: 1);
          ++rcClient.right;
          v6 = _mm_loadl_epi64((const __m128i *)&rcClient.right).m128i_u32[0];
          *(_QWORD *)&rc.left = *(_QWORD *)&rcClient.left;
          rc.right = v6;
          clrBorder = (Color)4144896;
          rc.bottom = rcClient.top + 17;
          rcFixed.right = v6;
          *(_QWORD *)&rcFixed.left = *(_QWORD *)&rcClient.left;
          rcFixed.bottom = rcClient.top + 17;
          CChoreoEventWidget::GrayOutColor(this, result: &clrSelection, clr: (Color)4144896);
          clrBorder = (Color)16762980;
          CChoreoEventWidget::GrayOutColor(this, result: &clrBorder, clr: (Color)16762980);
          clrBorder = (Color)CreateSolidBrush(color: clrBorder._color[0] | (*(unsigned __int16 *)&clrBorder._color[1] << 8));
          *(float *)&brSelected = COERCE_FLOAT(
                                    CreateHatchBrush(
                                      iHatch: 2,
                                      color: clrSelection._color[0] | (*(unsigned __int16 *)&clrSelection._color[1] << 8)));
          for ( clrSelection = (Color)2; clrSelection != 0; --*(_DWORD *)&clrSelection )
          {
            FrameRect(hDC: dc, lprc: &rc, hbr: brSelected);
            InflateRect(lprc: &rc, dx: -1, dy: -1);
          }
          FrameRect(hDC: dc, lprc: &rcFixed, hbr: *(HBRUSH *)&clrBorder);
          FrameRect(hDC: dc, lprc: &rc, hbr: *(HBRUSH *)&clrBorder);
          DeleteObject(ho: brSelected);
          DeleteObject(ho: *(HGDIOBJ *)&clrBorder);
          --rcClient.right;
          InflateRect(lprc: &rcClient, dx: -3, dy: -1);
        }
        rcEvent = rcClient;
        InflateRect(lprc: &rcEvent, dx: 0, dy: -1);
        rcEvent.bottom = rcEvent.top + 10;
        if ( CChoreoEvent::GetType(this: m_pEvent) == SPEAK
          && this->m_pWaveFile != nullptr
          && !CChoreoEvent::CurveHasEndTime(this: m_pEvent) )
        {
          *(float *)&brSelected = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
          StartTime = CChoreoEvent::GetStartTime(this: m_pEvent);
          endtime = StartTime + *(float *)&brSelected;
          CChoreoEvent::SetEndTime(this: m_pEvent, endtime);
          *(float *)&brSelected = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
          PixelsPerSecond = CChoreoView::GetPixelsPerSecond(this: CChoreoWidget::m_pView);
          rcEvent.right = (int)(PixelsPerSecond * *(float *)&brSelected);
        }
        HasEndTime = CChoreoEvent::CurveHasEndTime(this: m_pEvent);
        rcFixed = rcEvent;
        if ( HasEndTime )
        {
          OffsetRect(lprc: &rcFixed, dx: 0, dy: 1);
          v10 = CChoreoEvent::GetType(this: m_pEvent) - 5;
          if ( v10 != 0 )
          {
            if ( v10 == 1 )
              CChoreoEventWidget::DrawGestureEvent(this, (int)drawHelper, rcEventLine: &rcFixed);
            else
              CChoreoEventWidget::DrawGenericEvent(this, (Color)drawHelper, rcEventLine: &rcFixed);
          }
          else
          {
            CChoreoEventWidget::DrawSpeakEvent(this, a2: 0, a3: (int)m_pEvent, (Color)drawHelper, rcEventLine: &rcFixed);
          }
        }
        else
        {
          OffsetRect(lprc: &rcFixed, dx: 0, dy: 1);
          endtimea = rcFixed.bottom;
          v24 = rcFixed.left - 1;
          top = rcFixed.top;
          v20 = rcFixed.left - 1;
          clrBorder = (Color)((char *)&g_flexedverts[204].z + 2);
          v11 = (HPEN__ *)CChoreoEventWidget::GrayOutColor(
                            this,
                            result: (Color *)&brSelected,
                            clr: (Color)((char *)&g_flexedverts[204].z + 2));
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: drawHelper,
            clr: v11,
            style: 0,
            width: 3,
            x1: v20,
            y1: top,
            x2: v24,
            y2: endtimea);
        }
        if ( CChoreoEvent::IsUsingRelativeTag(this: m_pEvent) )
        {
          rc = rcClient;
          RelativeTagName = CChoreoEvent::GetRelativeTagName(this: m_pEvent);
          v13 = CChoreoWidgetDrawHelper::CalcTextWidth(
                  font: "Arial",
                  pointsize: (HFONT__ *)9,
                  weight: 400,
                  fmt: RelativeTagName);
          rc.right = rc.left;
          rc.top += 3;
          rc.left += -4 - v13;
          rc.bottom = rc.top + 10;
          clrBorder = (Color)13132800;
          endtimeb = CChoreoEvent::GetRelativeTagName(this: m_pEvent);
          v14 = CChoreoEventWidget::GrayOutColor(this, result: (Color *)&brSelected, clr: clrBorder);
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: drawHelper,
            font: "Arial",
            pointsize: 9,
            weight: 400,
            clr: v14,
            rcText: &rc,
            fmt: endtimeb);
          endtimec = rc.bottom + 2;
          v25 = rc.right + 2;
          v23 = rc.top - 2;
          v21 = rc.right - 1;
          clrBorder = (Color)16409600;
          v15 = CChoreoEventWidget::GrayOutColor(this, result: (Color *)&brSelected, clr: (Color)16409600);
          CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, clr: v15, x1: v21, y1: v23, x2: v25, y2: endtimec);
        }
        rcEventLabel = rcClient;
        InflateRect(lprc: &rcEventLabel, dx: 0, dy: -1);
        ++rcEventLabel.left;
        rcEventLabel.top += 15;
        rcEventLabel.bottom = rcEventLabel.top + 11;
        if ( &CChoreoEventWidget::m_Bitmaps[CChoreoEvent::GetType(this: m_pEvent)] != nullptr )
        {
          v16 = &CChoreoEventWidget::m_Bitmaps[CChoreoEvent::GetType(this: m_pEvent)];
          if ( v16 != nullptr )
            DrawBitmapToDC(hdc: dc, x: rcEventLabel.left, y: rcEventLabel.top, w: 16, h: 16, bitmap: v16);
        }
        OffsetRect(lprc: &rcEventLabel, dx: 16, dy: 1);
        if ( CChoreoEvent::IsResumeCondition(this: m_pEvent) )
        {
          rcFixed = rcEventLabel;
          OffsetRect(lprc: &rcEventLabel, dx: 16, dy: 0);
          DrawBitmapToDC(
            hdc: dc,
            x: rcFixed.left,
            y: rcFixed.top,
            w: 16,
            h: 16,
            bitmap: &CChoreoEventWidget::m_ResumeConditionBitmap);
        }
        if ( CChoreoEvent::IsLockBodyFacing(this: m_pEvent) )
        {
          rc = rcEventLabel;
          OffsetRect(lprc: &rcEventLabel, dx: 16, dy: 0);
          rc.right = rc.left + 16;
          rc.bottom = rc.top + 16;
          rcFixed = rc;
          CChoreoWidgetDrawHelper::OffsetSubRect(this: drawHelper, rc: &rcFixed);
          DrawBitmapToDC(
            hdc: dc,
            x: rcFixed.left,
            y: rcFixed.top,
            w: rcFixed.right - rcFixed.left,
            h: rcFixed.bottom - rcFixed.top,
            bitmap: &CChoreoEventWidget::m_LockBodyFacingBitmap);
        }
        OffsetRect(lprc: &rcEventLabel, dx: 2, dy: 1);
        Name = CChoreoEvent::GetName(this: m_pEvent);
        v18 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: Name);
        rcEventLabel.right = v18 + rcEventLabel.left + 2;
        clrBorder = (Color)7864320;
        endtimed = CChoreoEvent::GetName(this: m_pEvent);
        v19 = CChoreoEventWidget::GrayOutColor(this, result: (Color *)&brSelected, clr: clrBorder);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: v19,
          rcText: &rcEventLabel,
          fmt: endtimed);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EB870
// Name: _dynamic_initializer_for__CChoreoEventWidget::m_Bitmaps__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int *dynamic_initializer_for__CChoreoEventWidget::m_Bitmaps__()
{
  int v0; // edx
  int *result; // eax

  v0 = 19;
  result = &CChoreoEventWidget::m_Bitmaps[0].width;
  do
  {
    *((_BYTE *)result - 8) = 0;
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    result += 4;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EB8A0
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004EB8D0
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004EB900
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004EB930
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB970
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB9A0
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB9D0
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}
