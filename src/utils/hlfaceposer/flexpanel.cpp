// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/flexpanel.cpp
// Functions: 27
// ============================================================

#include "utils\hlfaceposer\flexpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00457F00
// Name: public: void FlexPanel::PositionControls(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::PositionControls(FlexPanel *this, int width, int height)
{
  mxWidget::setBounds(this: this->btnResetSliders, x: 3, y: height - 18, w: 80, h: 18);
  mxWidget::setBounds(this: this->btnCopyToSliders, x: 88, y: height - 18, w: 80, h: 18);
  mxWidget::setBounds(this: this->btnCopyFromSliders, x: 173, y: height - 18, w: 100, h: 18);
  mxWidget::setBounds(this: this->btnMenu, x: 278, y: height - 18, w: 100, h: 18);
}

//------------------------------------------------------------------------------
// Address: 0x00457F70
// Name: public: FlexPanel::FlexPanel(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
FlexPanel *__thiscall FlexPanel::FlexPanel(FlexPanel *this, mxWindow *parent)
{
  int v2; // ebx
  mxButton *v4; // eax
  mxButton *v5; // eax
  mxButton *v6; // eax
  mxButton *v7; // eax
  mxButton *v8; // eax
  mxButton *v9; // eax
  mxButton *v10; // eax
  mxButton *v11; // eax
  int v12; // edi
  mxExpressionSlider *v13; // eax
  mxExpressionSlider *v14; // eax
  mxScrollbar *v15; // eax
  mxScrollbar *v16; // eax
  mxExpressionSlider **parenta; // [esp+14h] [ebp+8h]

  v2 = 0;
  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "FlexPanel",
    displaynameroot: "Flex Sliders");
  this->mxWindow::mxWidget::__vftable = (FlexPanel_vtbl *)&FlexPanel::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&FlexPanel::`vftable'{for `IFacePoserToolWindow'};
  this->m_nViewableFlexControllerCount = 0;
  this->m_bNewExpressionMode = true;
  v4 = (mxButton *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxButton::mxButton(this: v4, parent: this, x: 0, y: 0, w: 100, h: 20, label: "Zero Sliders", id: 7102);
  else
    v5 = nullptr;
  this->btnResetSliders = v5;
  v6 = (mxButton *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxButton::mxButton(this: v6, parent: this, x: 0, y: 0, w: 100, h: 20, label: "Get Tracks", id: 1009);
  else
    v7 = nullptr;
  this->btnCopyToSliders = v7;
  v8 = (mxButton *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxButton::mxButton(this: v8, parent: this, x: 0, y: 0, w: 100, h: 20, label: "Make Keyframe", id: 1010);
  else
    v9 = nullptr;
  this->btnCopyFromSliders = v9;
  v10 = (mxButton *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxButton::mxButton(this: v10, parent: this, x: 0, y: 0, w: 100, h: 20, label: "Menu", id: 7803);
  else
    v11 = nullptr;
  this->btnMenu = v11;
  v12 = 5;
  parenta = this->slFlexScale;
  do
  {
    v13 = (mxExpressionSlider *)operator new(nSize: 0x4Cu);
    if ( v13 != nullptr )
      v14 = mxExpressionSlider::mxExpressionSlider(this: v13, parent: this, x: 5, y: v12, w: 220, h: 20, id: v2 + 7200);
    else
      v14 = nullptr;
    *parenta = v14;
    v12 += 20;
    ++v2;
    ++parenta;
  }
  while ( v12 < 7685 );
  v15 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxScrollbar::mxScrollbar(this: v15, parent: this, x: 0, y: 0, w: 18, h: 100, id: 7101, style: 1);
  else
    v16 = nullptr;
  this->slScrollbar = v16;
  mxScrollbar::setRange(this: v16, min: 0, max: 7680);
  mxScrollbar::setPagesize(this: this->slScrollbar, size: 100);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00458120
// Name: public: void FlexPanel::PositionSliders(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::PositionSliders(FlexPanel *this, int sboffset)
{
  FlexPanel *v2; // ebx
  int v3; // esi
  StudioModel *v4; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  CStudioHdr *v7; // edi
  int v8; // edx
  int v9; // edi
  mxWidget **slFlexScale; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // [esp-4h] [ebp-2Ch]
  int widthofslidercolumn; // [esp+Ch] [ebp-1Ch]
  int rowspercol; // [esp+10h] [ebp-18h]
  int reservedheight; // [esp+14h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-Ch]
  int x; // [esp+20h] [ebp-8h]
  int rowsneeded; // [esp+24h] [ebp-4h]

  v2 = this;
  reservedheight = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 25;
  widthofslidercolumn = mxWidget::w(this: v2->slFlexScale[0]) + 10;
  v3 = (mxWidget::w2(this: v2) - 30) / widthofslidercolumn;
  if ( v3 <= 1 )
    v3 = 1;
  rowsneeded = 384;
  v4 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v4->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v4->m_MDLHandle);
      CStudioHdr::Init(this: v4->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
      v7 = v4->m_pStudioHdr;
      if ( v7->m_pStudioHdr == nullptr )
        goto LABEL_9;
      m_pStudioHdr = v7;
    }
    if ( m_pStudioHdr != nullptr )
      rowsneeded = v2->m_nViewableFlexControllerCount;
  }
LABEL_9:
  v8 = (unsigned __int64)(1717986919LL * (mxWidget::h2(this: v2) - reservedheight)) >> 32;
  rowspercol = (v8 >> 3) + ((unsigned int)v8 >> 31);
  if ( v3 * rowspercol < rowsneeded )
  {
    rowspercol = (rowsneeded + v3 - 1) / v3;
    mxScrollbar::setPagesize(this: v2->slScrollbar, size: 20 * ((v8 >> 3) + ((unsigned int)v8 >> 31)));
    mxScrollbar::setRange(this: v2->slScrollbar, min: 0, max: 20 * rowspercol);
  }
  v9 = 0;
  i = 0;
  x = 5;
  slFlexScale = v2->slFlexScale;
  while ( 1 )
  {
    v11 = v2->GetCaptionHeight(this: &v2->IFacePoserToolWindow) + 20 * v9 - sboffset + 5;
    v13 = mxWidget::h(this: *slFlexScale);
    v12 = mxWidget::w(this: *slFlexScale);
    mxWidget::setBounds(this: *slFlexScale, x, y: v11, w: v12, h: v13);
    if ( i >= rowsneeded || v11 + 15 > mxWidget::h2(this) - reservedheight )
      mxWidget::setVisible(this: *slFlexScale, b: false);
    else
      mxWidget::setVisible(this: *slFlexScale, b: true);
    if ( ++v9 >= rowspercol )
    {
      x += widthofslidercolumn;
      v9 = 0;
    }
    ++slFlexScale;
    if ( ++i >= 384 )
      break;
    v2 = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004582C0
// Name: public: void FlexPanel::initFlexes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::initFlexes(FlexPanel *this)
{
  StudioModel *v2; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // edi
  mxExpressionSlider **slFlexScale; // edi
  int i; // ebx
  const studiohdr_t *v8; // eax
  int v9; // edi
  mxWidget **v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int min; // [esp+0h] [ebp-28h]
  int controller; // [esp+18h] [ebp-10h]
  int controllera; // [esp+18h] [ebp-10h]
  int controllerb; // [esp+18h] [ebp-10h]
  LocalFlexController_t k; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]
  CStudioHdr *hdr; // [esp+24h] [ebp-4h]

  this->m_nViewableFlexControllerCount = 0;
  memset(dst: (unsigned __int8 *)this->nFlexSliderIndex, value: 0, count: sizeof(this->nFlexSliderIndex));
  memset(dst: (unsigned __int8 *)this->nFlexSliderBarnum, value: 0, count: sizeof(this->nFlexSliderBarnum));
  v2 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v2->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = v2->m_pStudioHdr;
  }
  else
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v2->m_MDLHandle);
    CStudioHdr::Init(this: v2->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = v2->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      goto LABEL_21;
    hdr = v5;
  }
  if ( hdr != nullptr )
  {
    slFlexScale = this->slFlexScale;
    for ( i = 384; i != 0; --i )
    {
      mxWidget::setVisible(this: *slFlexScale, b: false);
      mxWidget::setLabel(this: *slFlexScale, format: defaultValue);
      mxExpressionSlider::SetMode(this: *slFlexScale, paired: false);
      slFlexScale[389] = (mxExpressionSlider *)-1;
      ++slFlexScale;
    }
    v8 = hdr->m_pStudioHdr;
    j = 0;
    k = DUMMY_NULL_FLEX_CONTROLLER;
    if ( hdr->m_pStudioHdr->numflexcontrollers > 0 )
    {
      v9 = 0;
      v10 = this->slFlexScale;
      do
      {
        controller = *(int *)((char *)&v8->checksum + v9 + v8->flexcontrollerindex);
        mxWidget::setLabel(
          this: *v10,
          format: (const char *)v8
        + v9
        + v8->flexcontrollerindex
        + *(int *)((char *)&v8->version + v9 + v8->flexcontrollerindex));
        if ( this->nFlexSliderIndex[controller] == -1 )
        {
          this->nFlexSliderIndex[controller] = j;
          this->nFlexSliderBarnum[controller] = 0;
        }
        if ( *(float *)&hdr->m_pStudioHdr->name[v9 + hdr->m_pStudioHdr->flexcontrollerindex] != *(float *)&hdr->m_pStudioHdr->name[v9 + 4 + hdr->m_pStudioHdr->flexcontrollerindex] )
          mxExpressionSlider::setRange(
            this: (mxExpressionSlider *)*v10,
            barnum: 0,
            min: *(float *)&hdr->m_pStudioHdr->name[v9 + hdr->m_pStudioHdr->flexcontrollerindex],
            max: *(float *)&hdr->m_pStudioHdr->name[v9 + 4 + hdr->m_pStudioHdr->flexcontrollerindex],
            ticks: 100);
        v11 = (int)hdr->m_pStudioHdr + v9 + hdr->m_pStudioHdr->flexcontrollerindex;
        if ( strncmp(first: "right_", last: (const char *)(v11 + *(_DWORD *)(v11 + 4)), count: 6u) == 0 )
        {
          if ( *(float *)&hdr->m_pStudioHdr->name[v9 + hdr->m_pStudioHdr->flexcontrollerindex] != *(float *)&hdr->m_pStudioHdr->name[v9 + 4 + hdr->m_pStudioHdr->flexcontrollerindex] )
            mxExpressionSlider::setRange(this: (mxExpressionSlider *)*v10, barnum: 1, min: 0.0, max: 1.0, ticks: 100);
          v12 = (int)hdr->m_pStudioHdr + v9 + hdr->m_pStudioHdr->flexcontrollerindex;
          mxWidget::setLabel(this: *v10, format: (const char *)(*(_DWORD *)(v12 + 4) + v12 + 6));
          mxExpressionSlider::SetMode(this: (mxExpressionSlider *)*v10, paired: true);
          v9 += 20;
          v13 = *(int *)((char *)&hdr->m_pStudioHdr->checksum + v9 + hdr->m_pStudioHdr->flexcontrollerindex);
          ++k;
          if ( this->nFlexSliderIndex[v13] == -1 )
          {
            this->nFlexSliderIndex[v13] = j;
            this->nFlexSliderBarnum[v13] = 1;
          }
        }
        ++this->m_nViewableFlexControllerCount;
        mxWidget::setVisible(this: *v10, b: true);
        (*v10)->__vftable[1].CanClose(this: *v10);
        v8 = hdr->m_pStudioHdr;
        ++j;
        ++v10;
        v9 += 20;
        ++k;
      }
      while ( k < hdr->m_pStudioHdr->numflexcontrollers );
    }
  }
LABEL_21:
  mxScrollbar::setRange(this: this->slScrollbar, min: 0, max: 20 * this->m_nViewableFlexControllerCount + 5);
  controllera = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  v14 = mxWidget::h2(this) - controllera;
  controllerb = mxWidget::h2(this);
  mxWidget::w2(this);
  mxWidget::setBounds(this: this->btnResetSliders, x: 3, y: controllerb - 18, w: 80, h: 18);
  mxWidget::setBounds(this: this->btnCopyToSliders, x: 88, y: controllerb - 18, w: 80, h: 18);
  mxWidget::setBounds(this: this->btnCopyFromSliders, x: 173, y: controllerb - 18, w: 100, h: 18);
  mxWidget::setBounds(this: this->btnMenu, x: 278, y: controllerb - 18, w: 100, h: 18);
  mxScrollbar::setPagesize(this: this->slScrollbar, size: v14);
  min = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  v15 = mxWidget::w2(this);
  mxWidget::setBounds(this: this->slScrollbar, x: v15 - 18, y: min, w: 18, h: v14);
  FlexPanel::PositionSliders(this, sboffset: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00458670
// Name: public: void FlexPanel::SetEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::SetEvent(FlexPanel *this, CChoreoEvent *event)
{
  CChoreoScene *SceneFPS; // edi
  CChoreoActor *Actor; // eax
  StudioModel *AssociatedModel; // esi
  bool bUpdateSliders; // [esp+8h] [ebp-4h]

  bUpdateSliders = false;
  if ( event != nullptr )
  {
    SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)event);
    Actor = CChoreoEvent::GetActor(this: event);
    AssociatedModel = FindAssociatedModel(scene: SceneFPS, a: Actor);
    bUpdateSliders = AssociatedModel == models->GetActiveStudioModel(this: models);
  }
  mxWidget::setEnabled(this: this->btnCopyToSliders, b: bUpdateSliders);
  mxWidget::setEnabled(this: this->btnCopyFromSliders, b: bUpdateSliders);
}

//------------------------------------------------------------------------------
// Address: 0x004586E0
// Name: public: bool FlexPanel::IsValidSlider(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall FlexPanel::IsValidSlider(FlexPanel *this, int iFlexController)
{
  return this->nFlexSliderIndex[iFlexController] != -1;
}

//------------------------------------------------------------------------------
// Address: 0x00458700
// Name: public: float FlexPanel::GetSlider(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall FlexPanel::GetSlider(FlexPanel *this, int iFlexController)
{
  int v2; // eax

  v2 = this->nFlexSliderIndex[iFlexController];
  if ( v2 != -1 )
    return mxExpressionSlider::getValue(this: this->slFlexScale[v2], barnum: this->nFlexSliderBarnum[iFlexController]);
  _Msg(a1: "GetSlider(%d) invalid controller index\n", iFlexController);
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00458740
// Name: public: float FlexPanel::GetSliderRawValue(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall FlexPanel::GetSliderRawValue(FlexPanel *this, int iFlexController)
{
  int v2; // eax

  v2 = this->nFlexSliderIndex[iFlexController];
  if ( v2 != -1 )
    return mxExpressionSlider::getRawValue(
             this: this->slFlexScale[v2],
             barnum: this->nFlexSliderBarnum[iFlexController]);
  _Msg(a1: "GetSliderRawValue(%d) invalid controller index\n", iFlexController);
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00458780
// Name: public: void FlexPanel::GetSliderRange(int,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::GetSliderRange(FlexPanel *this, int iFlexController, float *minvalue, float *maxvalue)
{
  int v4; // eax
  int v5; // edi
  mxExpressionSlider *v6; // esi

  v4 = this->nFlexSliderIndex[iFlexController];
  v5 = this->nFlexSliderBarnum[iFlexController];
  if ( v4 == -1 )
  {
    _Msg(a1: "GetSliderRange(%d) invalid controller index\n", iFlexController);
    *minvalue = 0.0;
    *maxvalue = 1.0;
  }
  else
  {
    v6 = this->slFlexScale[v4];
    *minvalue = mxExpressionSlider::getMinValue(this: v6, barnum: v5);
    *maxvalue = mxExpressionSlider::getMaxValue(this: v6, barnum: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004587F0
// Name: public: void FlexPanel::SetSlider(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::SetSlider(FlexPanel *this, int iFlexController, float value)
{
  int v3; // eax

  v3 = this->nFlexSliderIndex[iFlexController];
  if ( v3 == -1 )
    _Msg(a1: "SetSlider(%d) invalid controller index\n", iFlexController);
  else
    mxExpressionSlider::setValue(this: this->slFlexScale[v3], barnum: this->nFlexSliderBarnum[iFlexController], value);
}

//------------------------------------------------------------------------------
// Address: 0x00458840
// Name: public: float FlexPanel::GetInfluence(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall FlexPanel::GetInfluence(FlexPanel *this, int iFlexController)
{
  int v2; // eax

  v2 = this->nFlexSliderIndex[iFlexController];
  if ( v2 != -1 )
    return mxExpressionSlider::getInfluence(this: this->slFlexScale[v2]);
  _Msg(a1: "GetInfluence(%d) invalid controller index\n", iFlexController);
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00458880
// Name: public: void FlexPanel::SetEdited(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::SetEdited(FlexPanel *this, int iFlexController, bool isEdited)
{
  int v3; // eax

  v3 = this->nFlexSliderIndex[iFlexController];
  if ( v3 == -1 )
    _Msg(a1: "IsEdited(%d) invalid controller index\n", iFlexController);
  else
    mxExpressionSlider::setEdited(
      this: this->slFlexScale[v3],
      barnum: this->nFlexSliderBarnum[iFlexController],
      isEdited);
}

//------------------------------------------------------------------------------
// Address: 0x004588D0
// Name: public: bool FlexPanel::IsEdited(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall FlexPanel::IsEdited(FlexPanel *this, int iFlexController)
{
  int v2; // eax

  v2 = this->nFlexSliderIndex[iFlexController];
  if ( v2 != -1 )
    return mxExpressionSlider::isEdited(this: this->slFlexScale[v2], barnum: this->nFlexSliderBarnum[iFlexController]);
  _Msg(a1: "IsEdited(%d) invalid controller index\n", iFlexController);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00458910
// Name: public: void FlexPanel::SetInfluence(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::SetInfluence(FlexPanel *this, int iFlexController, float value)
{
  int v3; // eax

  v3 = this->nFlexSliderIndex[iFlexController];
  if ( v3 == -1 )
  {
    _Msg(a1: "SetInfluence(%d) invalid controller index\n", iFlexController);
  }
  else if ( this->nFlexSliderBarnum[iFlexController] == 0 )
  {
    mxExpressionSlider::setInfluence(this: this->slFlexScale[v3], value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458960
// Name: public: int FlexPanel::LookupFlex(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall FlexPanel::LookupFlex(FlexPanel *this, int iSlider, int barnum)
{
  int result; // eax
  int *i; // ecx

  result = 0;
  for ( i = this->nFlexSliderBarnum; *(i - 384) != iSlider || *i != barnum; ++i )
  {
    if ( ++result >= 384 )
    {
      Con_Printf(fmt: "lookup slider %i bar %i failed\n", iSlider, barnum);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004589A0
// Name: public: int FlexPanel::LookupPairedFlex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall FlexPanel::LookupPairedFlex(FlexPanel *this, int iFlexController)
{
  int v2; // eax
  int result; // eax
  bool v4; // zf

  v2 = this->nFlexSliderIndex[iFlexController];
  if ( v2 == -1 )
  {
    _Msg(a1: "LookupPairedFlex(%d) invalid controller index\n", iFlexController);
    return iFlexController;
  }
  else if ( this->nFlexSliderBarnum[iFlexController] == 1 )
  {
    return iFlexController - 1;
  }
  else
  {
    v4 = this->nFlexSliderIndex[iFlexController + 1] == v2;
    result = iFlexController + 1;
    if ( !v4 )
      return iFlexController;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004589F0
// Name: public: void FlexPanel::setExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::setExpression(FlexPanel *this, int index)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // eax
  LocalFlexController_t v4; // edi
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  CExpClass *v7; // eax
  CExpression *Expression; // eax
  CExpression *v9; // esi
  float *Settings; // ebx
  const studiohdr_t *v11; // eax
  int v12; // esi
  StudioModel *v13; // eax
  float value; // [esp+0h] [ebp-1Ch]
  float *weights; // [esp+10h] [ebp-Ch]
  CStudioHdr *hdr; // [esp+18h] [ebp-4h]
  int indexa; // [esp+24h] [ebp+8h]

  if ( models->GetActiveStudioModel(this: models) != nullptr )
  {
    v2 = models->GetActiveStudioModel(this: models);
    m_pStudioHdr = v2->m_pStudioHdr;
    v4 = DUMMY_NULL_FLEX_CONTROLLER;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      hdr = v2->m_pStudioHdr;
    }
    else
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v2->m_MDLHandle);
      CStudioHdr::Init(this: v2->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = v2->m_pStudioHdr;
      if ( v6->m_pStudioHdr == nullptr )
        return;
      hdr = v6;
    }
    if ( hdr != nullptr )
    {
      v7 = expressions->GetActiveClass(this: expressions);
      if ( v7 != nullptr )
      {
        Expression = CExpClass::GetExpression(this: v7, num: index);
        v9 = Expression;
        if ( Expression != nullptr )
        {
          Settings = CExpression::GetSettings(this: Expression);
          weights = CExpression::GetWeights(this: v9);
          v11 = hdr->m_pStudioHdr;
          if ( hdr->m_pStudioHdr->numflexcontrollers > 0 )
          {
            indexa = 0;
            do
            {
              v12 = *(int *)((char *)&v11->checksum + indexa + v11->flexcontrollerindex);
              if ( v12 != -1 )
              {
                FlexPanel::SetSlider(this, iFlexController: v12, value: Settings[v12]);
                FlexPanel::SetInfluence(this, iFlexController: v12, value: weights[v12]);
                value = Settings[v12] * weights[v12];
                v13 = models->GetActiveStudioModel(this: models);
                StudioModel::SetFlexController(this: v13, iFlex: v4, flValue: value);
              }
              v11 = hdr->m_pStudioHdr;
              indexa += 20;
              ++v4;
            }
            while ( v4 < hdr->m_pStudioHdr->numflexcontrollers );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458B40
// Name: public: void FlexPanel::DeleteExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::DeleteExpression(FlexPanel *this, int index)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  CExpClass *v6; // eax
  CExpClass *v7; // esi
  CExpression *Expression; // eax

  v2 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v2->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v2->m_MDLHandle);
      CStudioHdr::Init(this: v2->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = v2->m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      v6 = expressions->GetActiveClass(this: expressions);
      v7 = v6;
      if ( v6 != nullptr )
      {
        Expression = CExpClass::GetExpression(this: v6, num: index);
        if ( Expression != nullptr )
          CExpClass::DeleteExpression(this: v7, name: Expression->name);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458BC0
// Name: public: void FlexPanel::RevertExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::RevertExpression(FlexPanel *this, int index)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  CExpClass *v7; // eax
  CExpression *Expression; // eax

  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
      CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = v3->m_pStudioHdr;
      if ( v6->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v6;
    }
    if ( m_pStudioHdr != nullptr )
    {
      v7 = expressions->GetActiveClass(this: expressions);
      if ( v7 != nullptr )
      {
        Expression = CExpClass::GetExpression(this: v7, num: index);
        if ( Expression != nullptr )
        {
          CExpression::Revert(this: Expression);
          FlexPanel::setExpression(this, index);
          g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458C60
// Name: public: void FlexPanel::SaveExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::SaveExpression(FlexPanel *this, int index)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  CExpClass *v7; // eax
  CExpression *Expression; // esi
  const studiohdr_t *v9; // eax
  int v10; // edi
  int v11; // esi
  int v12; // eax
  float v13; // xmm0_4
  int v14; // eax
  float v15; // xmm0_4
  int v16; // eax
  CExpression *exp; // [esp+8h] [ebp-14h]
  float *weights; // [esp+Ch] [ebp-10h]
  float *settings; // [esp+10h] [ebp-Ch]
  float Value; // [esp+14h] [ebp-8h]
  float Influence; // [esp+14h] [ebp-8h]
  CStudioHdr *hdr; // [esp+18h] [ebp-4h]
  int indexa; // [esp+24h] [ebp+8h]

  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = v3->m_pStudioHdr;
  }
  else
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = v3->m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
      return;
    hdr = v6;
  }
  if ( hdr != nullptr )
  {
    v7 = expressions->GetActiveClass(this: expressions);
    if ( v7 != nullptr )
    {
      Expression = CExpClass::GetExpression(this: v7, num: index);
      exp = Expression;
      if ( Expression != nullptr
        && mxMessageBox(parent: this, msg: "Overwrite existing expression?", title: g_appTitle, style: 33) == 0 )
      {
        settings = CExpression::GetSettings(this: Expression);
        weights = CExpression::GetWeights(this: Expression);
        v9 = hdr->m_pStudioHdr;
        v10 = 0;
        if ( hdr->m_pStudioHdr->numflexcontrollers > 0 )
        {
          indexa = 0;
          do
          {
            v11 = *(int *)((char *)&v9->checksum + indexa + v9->flexcontrollerindex);
            v12 = this->nFlexSliderIndex[v11];
            if ( v12 == -1 )
            {
              _Msg(a1: "GetSlider(%d) invalid controller index\n", v11);
              v13 = 0.0;
            }
            else
            {
              Value = mxExpressionSlider::getValue(this: this->slFlexScale[v12], barnum: this->nFlexSliderBarnum[v11]);
              v13 = Value;
            }
            settings[v11] = v13;
            v14 = this->nFlexSliderIndex[v11];
            if ( v14 == -1 )
            {
              _Msg(a1: "GetInfluence(%d) invalid controller index\n", v11);
              v15 = 0.0;
            }
            else
            {
              Influence = mxExpressionSlider::getInfluence(this: this->slFlexScale[v14]);
              v15 = Influence;
            }
            v9 = hdr->m_pStudioHdr;
            indexa += 20;
            ++v10;
            weights[v11] = v15;
          }
          while ( v10 < v9->numflexcontrollers );
          Expression = exp;
        }
        v16 = models->GetActiveModelIndex(this: models);
        CExpression::CreateNewBitmap(this: Expression, modelindex: v16);
        CExpression::ResetUndo(this: Expression);
        CExpression::SetDirty(this: Expression, dirty: false);
        g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458E30
// Name: private: void FlexPanel::OnSetAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::OnSetAll(FlexPanel *this, int state)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  const studiohdr_t *v7; // eax
  LocalFlexController_t v8; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  float value; // xmm0_4
  int v13; // eax
  StudioModel *v14; // eax
  float setting; // [esp+10h] [ebp-10h]
  CStudioHdr *hdr; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  float influence; // [esp+1Ch] [ebp-4h]

  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = v3->m_pStudioHdr;
    v6 = hdr;
  }
  else
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = v3->m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
      return;
    hdr = v6;
  }
  if ( v6 != nullptr )
  {
    v7 = v6->m_pStudioHdr;
    v8 = DUMMY_NULL_FLEX_CONTROLLER;
    if ( v6->m_pStudioHdr->numflexcontrollers > 0 )
    {
      v17 = 0;
      do
      {
        v9 = *(int *)((char *)&v7->checksum + v17 + v7->flexcontrollerindex);
        v10 = this->nFlexSliderIndex[v9];
        if ( v10 == -1 )
        {
          _Msg(a1: "GetSlider(%d) invalid controller index\n", v9);
          setting = 0.0;
        }
        else
        {
          setting = mxExpressionSlider::getValue(this: this->slFlexScale[v10], barnum: this->nFlexSliderBarnum[v9]);
        }
        v11 = this->nFlexSliderIndex[v9];
        if ( v11 == -1 )
        {
          _Msg(a1: "GetInfluence(%d) invalid controller index\n", v9);
          value = 0.0;
          influence = 0.0;
        }
        else
        {
          influence = mxExpressionSlider::getInfluence(this: this->slFlexScale[v11]);
          value = influence;
        }
        if ( state != 0 )
        {
          if ( state == 1 )
          {
            value = 1.0;
          }
          else
          {
            if ( state != 2 )
              goto LABEL_22;
            value = 1.0 - value;
          }
        }
        else
        {
          value = 0.0;
        }
        influence = value;
LABEL_22:
        v13 = this->nFlexSliderIndex[v9];
        if ( v13 == -1 )
        {
          _Msg(a1: "SetInfluence(%d) invalid controller index\n", v9);
LABEL_26:
          value = influence;
          goto LABEL_27;
        }
        if ( this->nFlexSliderBarnum[v9] == 0 )
        {
          mxExpressionSlider::setInfluence(this: this->slFlexScale[v13], value);
          goto LABEL_26;
        }
LABEL_27:
        v14 = models->GetActiveStudioModel(this: models);
        StudioModel::SetFlexController(this: v14, iFlex: v8, flValue: value * setting);
        v7 = hdr->m_pStudioHdr;
        v17 += 20;
        ++v8;
      }
      while ( v8 < hdr->m_pStudioHdr->numflexcontrollers );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458FE0
// Name: public: void FlexPanel::ResetSliders(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::ResetSliders(FlexPanel *this, bool preserveundo, bool bDirtyClass)
{
  CExpClass *v3; // esi
  CExpression *v4; // ebx
  int SelectedExpression; // eax
  CExpression *Expression; // eax
  float *Settings; // ebx
  unsigned int v8; // edi
  float *v9; // eax
  int v10; // ecx
  StudioModel *v11; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v13; // eax
  CStudioHdr *v14; // esi
  float *v15; // edi
  float *Weights; // eax
  int v17; // ecx
  int i; // edx
  const studiohdr_t *v19; // eax
  LocalFlexController_t v20; // edi
  int v21; // ebx
  int v22; // esi
  StudioModel *v23; // eax
  CExpression zeroes; // [esp+10h] [ebp-E50h] BYREF
  FlexPanel *v25; // [esp+E54h] [ebp-Ch]
  CExpression *exp; // [esp+E58h] [ebp-8h]
  bool needredo; // [esp+E5Fh] [ebp-1h]
  CStudioHdr *hdr; // [esp+E6Ch] [ebp+Ch]

  v25 = this;
  v3 = expressions->GetActiveClass(this: expressions);
  needredo = false;
  CExpression::CExpression(this: &zeroes);
  v4 = nullptr;
  exp = nullptr;
  if ( v3 != nullptr )
  {
    SelectedExpression = CExpClass::GetSelectedExpression(this: v3);
    if ( SelectedExpression != -1 )
    {
      Expression = CExpClass::GetExpression(this: v3, num: SelectedExpression);
      exp = Expression;
      if ( Expression != nullptr )
      {
        Settings = CExpression::GetSettings(this: Expression);
        v8 = 1536;
        v9 = CExpression::GetSettings(this: &zeroes);
        v10 = (char *)Settings - (char *)v9;
        while ( *(_DWORD *)((char *)v9 + v10) == *(_DWORD *)v9 )
        {
          v8 -= 4;
          ++v9;
          if ( v8 < 4 )
          {
            v4 = exp;
            goto LABEL_14;
          }
        }
        if ( preserveundo )
        {
          CExpression::PushUndoInformation(this: exp);
          needredo = true;
        }
        if ( bDirtyClass )
          CExpClass::SetDirty(this: v3, dirty: true);
        g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
        v4 = exp;
      }
      else
      {
        v4 = nullptr;
      }
    }
  }
LABEL_14:
  v11 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v11->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = v11->m_pStudioHdr;
    v14 = hdr;
  }
  else
  {
    v13 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v11->m_MDLHandle);
    CStudioHdr::Init(this: v11->m_pStudioHdr, pStudioHdr: v13, mdlcache: nullptr);
    v14 = v11->m_pStudioHdr;
    if ( v14->m_pStudioHdr == nullptr )
      goto LABEL_29;
    hdr = v14;
  }
  if ( v14 != nullptr )
  {
    if ( v4 != nullptr )
    {
      v15 = CExpression::GetSettings(this: v4);
      Weights = CExpression::GetWeights(this: v4);
      v17 = (char *)v15 - (char *)Weights;
      for ( i = 384; i != 0; --i )
      {
        *(float *)((char *)Weights + v17) = 0.0;
        *Weights++ = 0.0;
      }
    }
    v19 = v14->m_pStudioHdr;
    v20 = DUMMY_NULL_FLEX_CONTROLLER;
    if ( v14->m_pStudioHdr->numflexcontrollers > 0 )
    {
      v21 = 0;
      do
      {
        v22 = *(int *)((char *)&v19->checksum + v21 + v19->flexcontrollerindex);
        if ( v22 != -1 )
        {
          FlexPanel::SetSlider(this: v25, iFlexController: v22, value: 0.0);
          FlexPanel::SetInfluence(this: v25, iFlexController: v22, value: 0.0);
          FlexPanel::SetEdited(this: v25, iFlexController: v22, isEdited: false);
          v23 = models->GetActiveStudioModel(this: models);
          StudioModel::SetFlexController(this: v23, iFlex: v20, flValue: 0.0);
        }
        v19 = hdr->m_pStudioHdr;
        ++v20;
        v21 += 20;
      }
      while ( v20 < hdr->m_pStudioHdr->numflexcontrollers );
      v4 = exp;
    }
  }
LABEL_29:
  if ( v4 != nullptr && needredo && preserveundo )
    CExpression::PushRedoInformation(this: v4);
  CExpression::~CExpression(this: &zeroes);
}

//------------------------------------------------------------------------------
// Address: 0x004591E0
// Name: public: void FlexPanel::EditExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::EditExpression(FlexPanel *this)
{
  StudioModel *v1; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // esi
  CExpClass *v5; // eax
  CExpClass *v6; // esi
  int SelectedExpression; // eax
  CExpression *Expression; // esi
  char *description; // eax
  char v10; // cl
  bool v11; // bl
  int v12; // eax
  char *BitmapFilename; // eax
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  CExpressionParams params; // [esp+4h] [ebp-294h] BYREF
  CExpClass *active; // [esp+290h] [ebp-8h]

  v1 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v1->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    goto LABEL_6;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v1->m_MDLHandle);
    CStudioHdr::Init(this: v1->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    v4 = v1->m_pStudioHdr;
    if ( v4->m_pStudioHdr == nullptr )
    {
LABEL_6:
      Con_ErrorPrintf(fmt: "Can't edit face pose, must load a model first!\n");
      return;
    }
    m_pStudioHdr = v4;
  }
  if ( m_pStudioHdr == nullptr )
    goto LABEL_6;
  v5 = expressions->GetActiveClass(this: expressions);
  v6 = v5;
  active = v5;
  if ( v5 != nullptr )
  {
    SelectedExpression = CExpClass::GetSelectedExpression(this: v5);
    if ( SelectedExpression == -1 )
    {
      Con_ErrorPrintf(fmt: "Can't edit face pose, must select a face from list first!\n");
    }
    else
    {
      Expression = CExpClass::GetExpression(this: v6, num: SelectedExpression);
      if ( Expression != nullptr )
      {
        memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
        strcpy(params.m_szDialogTitle, "Edit Expression");
        strcpy(params.m_szName, Expression->name);
        description = Expression->description;
        do
        {
          v10 = *description;
          description[params.m_szDescription - Expression->description] = *description;
          ++description;
        }
        while ( v10 != 0 );
        if ( ExpressionProperties(&params) != 0 )
        {
          v11 = _V_stricmp(s1: Expression->name, s2: params.m_szName) != 0;
          if ( strlen(params.m_szName) != 0 && _V_stricmp(s1: params.m_szName, s2: "unnamed") != 0 )
          {
            if ( strlen(params.m_szDescription) != 0 && _V_stricmp(s1: params.m_szDescription, s2: "description") != 0 )
            {
              if ( v11 )
              {
                v12 = models->GetActiveModelIndex(this: models);
                BitmapFilename = CExpression::GetBitmapFilename(this: Expression, modelindex: v12);
                Con_Printf(fmt: "Deleting old bitmap %s\n", BitmapFilename);
                v14 = models->GetActiveModelIndex(this: models);
                v15 = CExpression::GetBitmapFilename(this: Expression, modelindex: v14);
                _unlink(path: v15);
              }
              strcpy(Expression->name, params.m_szName);
              strcpy(Expression->description, params.m_szDescription);
              if ( v11 )
              {
                v16 = models->GetActiveModelIndex(this: models);
                CExpression::CreateNewBitmap(this: Expression, modelindex: v16);
              }
              CExpClass::SetDirty(this: active, dirty: true);
              g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
            }
            else
            {
              Con_ErrorPrintf(fmt: "You must type in a valid description\n");
            }
          }
          else
          {
            Con_ErrorPrintf(fmt: "You must type in a valid name\n");
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459460
// Name: public: void FlexPanel::NewExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::NewExpression(FlexPanel *this)
{
  StudioModel *v1; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // esi
  CExpClass *v5; // ebx
  const studiohdr_t *v6; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  float settings[384]; // [esp+4h] [ebp-E9Ch] BYREF
  float weights[384]; // [esp+604h] [ebp-89Ch] BYREF
  CExpressionParams params; // [esp+C04h] [ebp-29Ch] BYREF
  CExpClass *active; // [esp+E90h] [ebp-10h]
  FlexPanel *v14; // [esp+E98h] [ebp-8h]
  CStudioHdr *hdr; // [esp+E9Ch] [ebp-4h]

  v14 = this;
  v1 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v1->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = v1->m_pStudioHdr;
    v4 = m_pStudioHdr;
  }
  else
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v1->m_MDLHandle);
    CStudioHdr::Init(this: v1->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    v4 = v1->m_pStudioHdr;
    if ( v4->m_pStudioHdr == nullptr )
    {
LABEL_7:
      Con_ErrorPrintf(fmt: "Can't create new face pose, must load a model first!\n");
      return;
    }
    hdr = v4;
  }
  if ( v4 == nullptr )
    goto LABEL_7;
  v5 = expressions->GetActiveClass(this: expressions);
  active = v5;
  if ( v5 != nullptr )
  {
    mxExpressionTray::Deselect(this: g_pExpressionTrayTool);
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Add Expression");
    params.m_szName[0] = 0;
    params.m_szDescription[0] = 0;
    if ( ExpressionProperties(&params) != 0 )
    {
      if ( strlen(params.m_szName) != 0 && _V_stricmp(s1: params.m_szName, s2: "unnamed") != 0 )
      {
        if ( strlen(params.m_szDescription) != 0 && _V_stricmp(s1: params.m_szDescription, s2: "description") != 0 )
        {
          memset(dst: (unsigned __int8 *)settings, value: 0, count: sizeof(settings));
          memset(dst: (unsigned __int8 *)weights, value: 0, count: sizeof(weights));
          v6 = v4->m_pStudioHdr;
          v7 = 0;
          if ( v4->m_pStudioHdr->numflexcontrollers > 0 )
          {
            v8 = 0;
            do
            {
              v9 = *(int *)((char *)&v6->checksum + v8 + v6->flexcontrollerindex);
              settings[v9] = FlexPanel::GetSlider(this: v14, iFlexController: v9);
              weights[v9] = FlexPanel::GetInfluence(this: v14, iFlexController: v9);
              v6 = hdr->m_pStudioHdr;
              ++v7;
              v8 += 20;
            }
            while ( v7 < hdr->m_pStudioHdr->numflexcontrollers );
            v5 = active;
          }
          CExpClass::AddExpression(
            this: v5,
            name: params.m_szName,
            description: params.m_szDescription,
            flexsettings: settings,
            flexweights: weights,
            selectnewitem: true,
            bDirtyClass: true);
        }
        else
        {
          Con_ErrorPrintf(fmt: "You must type in a valid description\n");
        }
      }
      else
      {
        Con_ErrorPrintf(fmt: "You must type in a valid name\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004596B0
// Name: private: void FlexPanel::OnMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::OnMenu(FlexPanel *this)
{
  int v2; // eax
  mxButton *btnMenu; // ecx
  int v4; // eax
  HWND Handle; // eax
  mxPopupMenu *v6; // eax
  mxPopupMenu *v7; // edi
  tagPOINT pt; // [esp+8h] [ebp-8h] BYREF

  v2 = mxWidget::x(this: this->btnMenu);
  btnMenu = this->btnMenu;
  pt.x = v2;
  v4 = mxWidget::y(this: btnMenu);
  pt.y = -3 * mxWidget::h2(this: this->btnMenu) + v4;
  Handle = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  v6 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxPopupMenu::mxPopupMenu(this: v6);
  else
    v7 = nullptr;
  mxPopupMenu::add(this: v7, item: "Check All", id: 7801);
  mxPopupMenu::add(this: v7, item: "Uncheck All", id: 7800);
  mxPopupMenu::add(this: v7, item: "Invert Selection", id: 7802);
  mxPopupMenu::popup(this: v7, widget: this, x: pt.x, y: pt.y);
}

//------------------------------------------------------------------------------
// Address: 0x004597C0
// Name: public: virtual int FlexPanel::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall FlexPanel::handleEvent(FlexPanel *this, mxEvent *event)
{
  IFacePoserToolWindow *v4; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int action; // eax
  int v11; // eax
  CChoreoScene *v12; // eax
  CChoreoScene *Scene; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  mxExpressionSlider *widget; // ebx
  int v18; // edi
  int v19; // ebx
  CExpClass *v20; // eax
  CExpClass *v21; // esi
  int SelectedExpression; // eax
  CExpression *Expression; // eax
  CExpression *v24; // esi
  float *v25; // eax
  StudioModel *v26; // eax
  int FlexControllerIndexByName; // eax
  StudioModel *v28; // eax
  StudioModel *v29; // eax
  int v30; // eax
  StudioModel *v31; // eax
  int v32; // [esp+0h] [ebp-38h]
  float scenetime; // [esp+4h] [ebp-34h]
  float scenetimea; // [esp+4h] [ebp-34h]
  LocalFlexController_t scenetimeb; // [esp+4h] [ebp-34h]
  LocalFlexController_t scenetimec; // [esp+4h] [ebp-34h]
  int flValue; // [esp+8h] [ebp-30h]
  const char *flValuea; // [esp+8h] [ebp-30h]
  const char *flValueb; // [esp+8h] [ebp-30h]
  IFacePoserToolWindow *tool; // [esp+18h] [ebp-20h]
  float *weights; // [esp+1Ch] [ebp-1Ch]
  CExpClass *activea; // [esp+20h] [ebp-18h]
  CExpClass *active; // [esp+20h] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+24h] [ebp-14h]
  int value2a; // [esp+28h] [ebp-10h]
  float value2; // [esp+28h] [ebp-10h]
  float value; // [esp+2Ch] [ebp-Ch]
  float influ; // [esp+30h] [ebp-8h]
  int iret; // [esp+34h] [ebp-4h]
  float *settingsa; // [esp+40h] [ebp+8h]
  float *settingsb; // [esp+40h] [ebp+8h]
  float *settings; // [esp+40h] [ebp+8h]
  bool settings_3; // [esp+43h] [ebp+Bh]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v4 = &this->IFacePoserToolWindow;
  iret = 0;
  tool = &this->IFacePoserToolWindow;
  if ( this->HandleToolEvent(this: &this->IFacePoserToolWindow, a2: event) )
  {
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return 0;
  }
  v6 = event->event;
  if ( v6 == 0 )
  {
    action = event->action;
    iret = 1;
    if ( action > 7800 )
    {
      v14 = action - 7801;
      if ( v14 == 0 )
      {
        FlexPanel::OnSetAll(this, state: 1);
        goto LABEL_26;
      }
      v15 = v14 - 1;
      if ( v15 == 0 )
      {
        FlexPanel::OnSetAll(this, state: 2);
        goto LABEL_26;
      }
      if ( v15 == 1 )
      {
        FlexPanel::OnMenu(this);
        goto LABEL_26;
      }
    }
    else
    {
      if ( action == 7800 )
      {
        FlexPanel::OnSetAll(this, state: 0);
        goto LABEL_26;
      }
      if ( action > 7101 )
      {
        if ( action == 7102 )
        {
          FlexPanel::ResetSliders(this, preserveundo: true, bDirtyClass: true);
          IFacePoserToolWindow::SetActiveTool(tool: &this->IFacePoserToolWindow);
          goto LABEL_26;
        }
      }
      else
      {
        if ( action == 7101 )
        {
          if ( event->modifiers == 5 )
          {
            settingsb = (float *)event->height;
            mxScrollbar::setValue(this: this->slScrollbar, ivalue: (int)settingsb);
            FlexPanel::PositionSliders(this, sboffset: (int)settingsb);
            IFacePoserToolWindow::SetActiveTool(tool: &this->IFacePoserToolWindow);
          }
          goto LABEL_26;
        }
        v11 = action - 1009;
        if ( v11 == 0 )
        {
          Scene = CChoreoView::GetScene(this: g_pChoreoView);
          scenetimea = CChoreoScene::GetTime(this: Scene);
          ExpressionTool::OnCopyToFlex(this: g_pExpressionTool, scenetime: scenetimea, isEdited: true);
          goto LABEL_26;
        }
        if ( v11 == 1 )
        {
          v12 = CChoreoView::GetScene(this: g_pChoreoView);
          scenetime = CChoreoScene::GetTime(this: v12);
          ExpressionTool::OnCopyFromFlex(this: g_pExpressionTool, scenetime, isEdited: false);
LABEL_26:
          v16 = event->action;
          if ( v16 >= 7200 && v16 < 7584 )
          {
            widget = (mxExpressionSlider *)event->widget;
            value2a = event->height;
            iret = 1;
            activea = (CExpClass *)(v16 - 7200);
            value = mxExpressionSlider::getValue(this: widget, barnum: value2a);
            influ = mxExpressionSlider::getInfluence(this: widget);
            settings_3 = event->modifiers == 8;
            v18 = FlexPanel::LookupFlex(this, iSlider: (int)activea, barnum: value2a);
            v19 = FlexPanel::LookupPairedFlex(this, iFlexController: v18);
            value2 = FlexPanel::GetSlider(this, iFlexController: v19);
            v20 = expressions->GetActiveClass(this: expressions);
            v21 = v20;
            active = v20;
            if ( v20 != nullptr )
            {
              SelectedExpression = CExpClass::GetSelectedExpression(this: v20);
              if ( settings_3 && SelectedExpression != -1 )
              {
                Expression = CExpClass::GetExpression(this: v21, num: SelectedExpression);
                v24 = Expression;
                if ( Expression != nullptr )
                {
                  settings = CExpression::GetSettings(this: Expression);
                  v25 = CExpression::GetWeights(this: v24);
                  weights = v25;
                  if ( settings[v18] != value || settings[v19] != value2 || v25[v18] != influ )
                  {
                    CExpression::PushUndoInformation(this: v24);
                    CExpClass::SetDirty(this: active, dirty: true);
                    settings[v18] = value;
                    settings[v19] = value2;
                    weights[v18] = influ;
                    weights[v19] = influ;
                    CExpression::PushRedoInformation(this: v24);
                    g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
                  }
                }
              }
            }
            flValuea = GetGlobalFlexControllerName(index: v18);
            v26 = models->GetActiveStudioModel(this: models);
            FlexControllerIndexByName = FindFlexControllerIndexByName(model: v26, searchname: flValuea);
            if ( FlexControllerIndexByName >= 0 )
            {
              scenetimeb = FlexControllerIndexByName;
              v28 = models->GetActiveStudioModel(this: models);
              StudioModel::SetFlexController(this: v28, iFlex: scenetimeb, flValue: influ * value);
              if ( v19 != v18 )
              {
                flValueb = GetGlobalFlexControllerName(index: v19);
                v29 = models->GetActiveStudioModel(this: models);
                v30 = FindFlexControllerIndexByName(model: v29, searchname: flValueb);
                if ( v30 >= 0 )
                {
                  scenetimec = v30;
                  v31 = models->GetActiveStudioModel(this: models);
                  StudioModel::SetFlexController(this: v31, iFlex: scenetimec, flValue: value2 * influ);
                }
              }
            }
            models->SetSolveHeadTurn(this: models, a2: 1);
            IFacePoserToolWindow::SetActiveTool(tool);
          }
          goto LABEL_41;
        }
      }
    }
    iret = 0;
    goto LABEL_26;
  }
  if ( v6 == 1 )
  {
    settingsa = (float *)v4->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    v7 = mxWidget::h2(this) - (_DWORD)settingsa;
    flValue = mxWidget::h2(this);
    v8 = mxWidget::w2(this);
    FlexPanel::PositionControls(this, width: v8, height: flValue);
    mxScrollbar::setPagesize(this: this->slScrollbar, size: v7);
    v32 = v4->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    v9 = mxWidget::w2(this);
    mxWidget::setBounds(this: this->slScrollbar, x: v9 - 18, y: v32, w: 18, h: v7);
    FlexPanel::PositionSliders(this, sboffset: 0);
    iret = 1;
  }
LABEL_41:
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  return iret;
}

//------------------------------------------------------------------------------
// Address: 0x00459BB0
// Name: public: virtual void FlexPanel::OnModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlexPanel::OnModelChanged(FlexPanel *this)
{
  mxWidget **v1; // esi

  v1 = (mxWidget **)((char *)this - 12);
  FlexPanel::ResetSliders(this: (FlexPanel *)((char *)this - 12), preserveundo: true, bDirtyClass: false);
  mxWidget::setEnabled(this: v1[544], b: false);
  mxWidget::setEnabled(this: v1[545], b: false);
  ((void (__thiscall *)(mxWidget **))(*v1)[2].__vftable)(a1: v1);
}
