// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/controlpanel.cpp
// Functions: 31
// ============================================================

#include "utils\hlfaceposer\controlpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0043AFF0
// Name: public: ControlPanel::ControlPanel(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
ControlPanel *__thiscall ControlPanel::ControlPanel(ControlPanel *this, mxWindow *parent)
{
  mxTab *v3; // eax
  mxTab *v4; // eax
  mxWindow *v5; // eax
  mxWindow *v6; // edi
  mxChoice *v7; // eax
  mxChoice *v8; // eax
  mxSlider *v9; // eax
  mxSlider *v10; // eax
  mxLabel *v11; // eax
  mxCheckBox *v12; // eax
  mxCheckBox *v13; // eax
  mxCheckBox *v14; // eax
  mxCheckBox *v15; // eax
  mxCheckBox *v16; // eax
  mxCheckBox *v17; // eax
  mxCheckBox *v18; // eax
  mxCheckBox *v19; // eax
  mxCheckBox *v20; // eax
  mxCheckBox *v21; // eax
  mxCheckBox *v22; // eax
  mxCheckBox *v23; // eax
  mxWindow *v24; // eax
  mxWindow *v25; // edi
  mxChoice *v26; // eax
  mxChoice *v27; // eax
  mxSlider *v28; // eax
  mxSlider *v29; // eax
  mxLabel *v30; // eax
  mxLabel *v31; // eax
  mxWindow *v32; // eax
  mxWindow *v33; // edi
  mxChoice *v34; // eax
  mxChoice *v35; // eax
  mxChoice *v36; // eax
  mxChoice *v37; // eax
  mxChoice *v38; // eax
  mxChoice *v39; // eax
  mxSlider *v40; // eax
  mxSlider *v41; // eax
  mxLabel *v42; // eax
  mxLabel *v43; // eax
  mxLabel *v44; // eax
  mxLabel *v45; // eax
  mxChoice *v46; // eax
  mxChoice *v47; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "ControlPanel",
    displaynameroot: "Control Panel");
  this->mxWindow::mxWidget::__vftable = (ControlPanel_vtbl *)&ControlPanel::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&ControlPanel::`vftable'{for `IFacePoserToolWindow'};
  this->tab = nullptr;
  v3 = (mxTab *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxTab::mxTab(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, id: 1901);
  else
    v4 = nullptr;
  this->tab = v4;
  v5 = (mxWindow *)operator new(nSize: 0xCu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    mxWindow::mxWindow(this: v5, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
    v6->__vftable = (mxWindow_vtbl *)&CControlPanelTabWindow::`vftable';
    FacePoser_AddWindowStyle(w: v6, addbits: 100663296);
  }
  else
  {
    v6 = nullptr;
  }
  mxTab::add(this: this->tab, widget: v6, text: "Render");
  v7 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxChoice::mxChoice(this: v7, parent: v6, x: 5, y: 5, w: 100, h: 22, id: 2001);
  else
    v8 = nullptr;
  this->cRenderMode = v8;
  mxChoice::add(this: v8, item: "Wireframe");
  mxChoice::add(this: this->cRenderMode, item: "Flatshaded");
  mxChoice::add(this: this->cRenderMode, item: "Smoothshaded");
  mxChoice::add(this: this->cRenderMode, item: "Textured");
  mxChoice::select(this: this->cRenderMode, index: 3);
  mxToolTip::add(widget: this->cRenderMode, text: "Select Render Mode");
  v9 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v9 != nullptr )
    v10 = mxSlider::mxSlider(this: v9, parent: v6, x: 220, y: 5, w: 140, h: 20, id: 2011, style: 0);
  else
    v10 = nullptr;
  this->slModelGap = v10;
  mxSlider::setRange(this: v10, min: 0.0, max: 64.0, ticks: 256);
  mxSlider::setValue(this: this->slModelGap, value: 16.0);
  mxToolTip::add(widget: this->slModelGap, text: "Select Model Spacing");
  v11 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    mxLabel::mxLabel(this: v11, parent: v6, x: 220, y: 25, w: 140, h: 20, label: "Model Spacing");
  v12 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxCheckBox::mxCheckBox(
            this: v12,
            parent: v6,
            x: 220,
            y: 45,
            w: 140,
            h: 20,
            label: "All tools drive mouth",
            id: 2012);
  else
    v13 = nullptr;
  this->cbAllWindowsDriveSpeech = v13;
  mxCheckBox::setChecked(this: v13, b: g_viewerSettings.faceposerToolsDriveMouth);
  v14 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    v15 = mxCheckBox::mxCheckBox(this: v14, parent: v6, x: 110, y: 5, w: 100, h: 20, label: "Ground", id: 2003);
  else
    v15 = nullptr;
  this->cbGround = v15;
  mxWidget::setEnabled(this: v15, b: true);
  v16 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v16 != nullptr )
    v17 = mxCheckBox::mxCheckBox(this: v16, parent: v6, x: 110, y: 25, w: 100, h: 20, label: "Movement", id: 2004);
  else
    v17 = nullptr;
  this->cbMovement = v17;
  mxWidget::setEnabled(this: v17, b: false);
  v18 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    v19 = mxCheckBox::mxCheckBox(this: v18, parent: v6, x: 110, y: 45, w: 100, h: 20, label: "Background", id: 2005);
  else
    v19 = nullptr;
  this->cbBackground = v19;
  mxWidget::setEnabled(this: v19, b: false);
  v20 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v20 != nullptr )
    mxCheckBox::mxCheckBox(this: v20, parent: v6, x: 110, y: 65, w: 100, h: 20, label: "Hit Boxes", id: 2006);
  v21 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v21 != nullptr )
    mxCheckBox::mxCheckBox(this: v21, parent: v6, x: 5, y: 65, w: 100, h: 20, label: "Bones", id: 2007);
  v22 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v22 != nullptr )
    v23 = mxCheckBox::mxCheckBox(this: v22, parent: v6, x: 5, y: 45, w: 100, h: 20, label: "Attachments", id: 2008);
  else
    v23 = nullptr;
  mxWidget::setEnabled(this: v23, b: false);
  v24 = (mxWindow *)operator new(nSize: 0xCu);
  v25 = v24;
  if ( v24 != nullptr )
  {
    mxWindow::mxWindow(this: v24, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
    v25->__vftable = (mxWindow_vtbl *)&CControlPanelTabWindow::`vftable';
    FacePoser_AddWindowStyle(w: v25, addbits: 100663296);
  }
  else
  {
    v25 = nullptr;
  }
  mxTab::add(this: this->tab, widget: v25, text: "Sequence");
  v26 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v26 != nullptr )
    v27 = mxChoice::mxChoice(this: v26, parent: v25, x: 5, y: 5, w: 200, h: 22, id: 3001);
  else
    v27 = nullptr;
  this->cSequence = v27;
  mxToolTip::add(widget: v27, text: "Select Sequence");
  v28 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v28 != nullptr )
    v29 = mxSlider::mxSlider(this: v28, parent: v25, x: 5, y: 32, w: 200, h: 18, id: 3002, style: 0);
  else
    v29 = nullptr;
  this->slSpeedScale = v29;
  mxSlider::setRange(this: v29, min: 0.0, max: 5.0, ticks: 100);
  mxSlider::setValue(this: this->slSpeedScale, value: 0.0);
  mxToolTip::add(widget: this->slSpeedScale, text: "Speed Scale");
  v30 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v30 != nullptr )
    v31 = mxLabel::mxLabel(this: v30, parent: v25, x: 5, y: 50, w: 200, h: 18, label: nullptr);
  else
    v31 = nullptr;
  this->lSpeedScale = v31;
  mxWidget::setLabel(this: v31, format: "Speed scale");
  v32 = (mxWindow *)operator new(nSize: 0xCu);
  v33 = v32;
  if ( v32 != nullptr )
  {
    mxWindow::mxWindow(this: v32, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
    v33->__vftable = (mxWindow_vtbl *)&CControlPanelTabWindow::`vftable';
    FacePoser_AddWindowStyle(w: v33, addbits: 100663296);
  }
  else
  {
    v33 = nullptr;
  }
  mxTab::add(this: this->tab, widget: v33, text: "Body");
  v34 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v34 != nullptr )
    v35 = mxChoice::mxChoice(this: v34, parent: v33, x: 5, y: 5, w: 100, h: 22, id: 4001);
  else
    v35 = nullptr;
  this->cBodypart = v35;
  mxToolTip::add(widget: v35, text: "Choose a bodypart");
  v36 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v36 != nullptr )
    v37 = mxChoice::mxChoice(this: v36, parent: v33, x: 110, y: 5, w: 100, h: 22, id: 4002);
  else
    v37 = nullptr;
  this->cSubmodel = v37;
  mxToolTip::add(widget: v37, text: "Choose a submodel of current bodypart");
  v38 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v38 != nullptr )
    v39 = mxChoice::mxChoice(this: v38, parent: v33, x: 5, y: 30, w: 100, h: 22, id: 4003);
  else
    v39 = nullptr;
  this->cController = v39;
  mxToolTip::add(widget: v39, text: "Choose a bone controller");
  v40 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v40 != nullptr )
    v41 = mxSlider::mxSlider(this: v40, parent: v33, x: 105, y: 32, w: 100, h: 18, id: 4004, style: 0);
  else
    v41 = nullptr;
  this->slController = v41;
  mxSlider::setRange(this: v41, min: 0.0, max: 45.0, ticks: 100);
  mxToolTip::add(widget: this->slController, text: "Change current bone controller value");
  v42 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    v43 = mxLabel::mxLabel(this: v42, parent: v33, x: 220, y: 5, w: 120, h: 100, label: "No Model.");
  else
    v43 = nullptr;
  this->lModelInfo1 = v43;
  v44 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v44 != nullptr )
    v45 = mxLabel::mxLabel(this: v44, parent: v33, x: 340, y: 5, w: 120, h: 100, label: defaultValue);
  else
    v45 = nullptr;
  this->lModelInfo2 = v45;
  v46 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v46 != nullptr )
    v47 = mxChoice::mxChoice(this: v46, parent: v33, x: 5, y: 55, w: 100, h: 22, id: 4005);
  else
    v47 = nullptr;
  this->cSkin = v47;
  mxToolTip::add(widget: v47, text: "Choose a skin family");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043B6A0
// Name: public: void ControlPanel::setRenderMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setRenderMode(ControlPanel *this, int mode)
{
  g_viewerSettings.renderMode = mode;
  g_pMatSysWindow->redraw(this: g_pMatSysWindow);
}

//------------------------------------------------------------------------------
// Address: 0x0043B6C0
// Name: public: void ControlPanel::setShowGround(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowGround(ControlPanel *this, bool b)
{
  g_viewerSettings.showGround = b;
  mxCheckBox::setChecked(this: this->cbGround, b);
}

//------------------------------------------------------------------------------
// Address: 0x0043B6E0
// Name: public: void ControlPanel::setShowMovement(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowMovement(ControlPanel *this, bool b)
{
  g_viewerSettings.showMovement = b;
  mxCheckBox::setChecked(this: this->cbMovement, b);
}

//------------------------------------------------------------------------------
// Address: 0x0043B700
// Name: public: void ControlPanel::setShowBackground(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowBackground(ControlPanel *this, bool b)
{
  g_viewerSettings.showBackground = b;
  mxCheckBox::setChecked(this: this->cbBackground, b);
}

//------------------------------------------------------------------------------
// Address: 0x0043B720
// Name: public: void ControlPanel::initSequenceChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initSequenceChoices(ControlPanel *this)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int i; // esi
  int v7; // eax
  const studiohdr_t *v8; // ecx
  int v9; // eax
  mstudioseqdesc_t *v10; // eax

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
      mxChoice::removeAll(this: this->cSequence);
      for ( i = 0; ; ++i )
      {
        v7 = m_pStudioHdr->m_pVModel != nullptr
           ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
           : m_pStudioHdr->m_pStudioHdr->numlocalseq;
        if ( i >= v7 )
          break;
        if ( m_pStudioHdr->m_pVModel != nullptr )
        {
          v10 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i);
        }
        else
        {
          v8 = m_pStudioHdr->m_pStudioHdr;
          v9 = i;
          if ( i < 0 || i >= v8->numlocalseq )
            v9 = 0;
          v10 = (mstudioseqdesc_t *)((char *)v8 + 212 * v9 + v8->localseqindex);
        }
        mxChoice::add(this: this->cSequence, item: (const char *)v10 + v10->szlabelindex);
      }
      mxChoice::select(this: this->cSequence, index: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B800
// Name: public: void ControlPanel::setBlend(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBlend(ControlPanel *this, int index, float value)
{
  StudioModel *v3; // eax

  v3 = models->GetActiveStudioModel(this: models);
  StudioModel::SetPoseParameter(this: v3, iParameter: index, flValue: value);
}

//------------------------------------------------------------------------------
// Address: 0x0043B830
// Name: public: void ControlPanel::initBodypartChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initBodypartChoices(ControlPanel *this)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  mxChoice *cBodypart; // ecx
  mstudiobodyparts_t *v7; // esi
  const studiohdr_t *v8; // ecx
  int v9; // eax
  int v10; // esi
  char str[64]; // [esp+Ch] [ebp-48h] BYREF
  mstudiobodyparts_t *pbodyparts; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

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
      cBodypart = this->cBodypart;
      v7 = (mstudiobodyparts_t *)((char *)m_pStudioHdr->m_pStudioHdr + m_pStudioHdr->m_pStudioHdr->bodypartindex);
      pbodyparts = v7;
      mxChoice::removeAll(this: cBodypart);
      if ( m_pStudioHdr->m_pStudioHdr->numbodyparts > 0 )
      {
        i = 0;
        do
        {
          mxChoice::add(this: this->cBodypart, item: (const char *)v7 + v7->sznameindex);
          v8 = m_pStudioHdr->m_pStudioHdr;
          ++v7;
          ++i;
        }
        while ( i < v8->numbodyparts );
        mxChoice::select(this: this->cBodypart, index: 0);
        mxChoice::removeAll(this: this->cSubmodel);
        v9 = 0;
        if ( pbodyparts->nummodels > 0 )
        {
          do
          {
            v10 = v9 + 1;
            sprintf(string: str, format: "Submodel %d", v9 + 1);
            mxChoice::add(this: this->cSubmodel, item: str);
            v9 = v10;
          }
          while ( v10 < pbodyparts->nummodels );
        }
        mxChoice::select(this: this->cSubmodel, index: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B950
// Name: public: void ControlPanel::setBodypart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBodypart(ControlPanel *this, int index)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  CStudioHdr *v7; // edi
  int v8; // edi
  int v9; // eax
  bool v10; // cc
  _DWORD *v11; // edi
  int v12; // esi
  char str[64]; // [esp+Ch] [ebp-40h] BYREF

  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v7 = v3->m_pStudioHdr;
  }
  else
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = v3->m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
      return;
    v7 = v6;
  }
  if ( v7 != nullptr )
  {
    mxChoice::select(this: this->cBodypart, index);
    if ( index < v7->m_pStudioHdr->numbodyparts )
    {
      v8 = (int)v7->m_pStudioHdr + v7->m_pStudioHdr->bodypartindex;
      mxChoice::removeAll(this: this->cSubmodel);
      v9 = 0;
      v10 = *(_DWORD *)(v8 + 16 * index + 4) <= 0;
      v11 = (_DWORD *)(v8 + 16 * index + 4);
      if ( !v10 )
      {
        do
        {
          v12 = v9 + 1;
          sprintf(string: str, format: "Submodel %d", v9 + 1);
          mxChoice::add(this: this->cSubmodel, item: str);
          v9 = v12;
        }
        while ( v12 < *v11 );
      }
      mxChoice::select(this: this->cSubmodel, index: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BA30
// Name: public: void ControlPanel::setSubmodel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setSubmodel(ControlPanel *this, int index)
{
  StudioModel *v2; // eax
  int SelectedIndex; // [esp-8h] [ebp-8h]

  SelectedIndex = mxChoice::getSelectedIndex(this: this->cBodypart);
  v2 = models->GetActiveStudioModel(this: models);
  StudioModel::SetBodygroup(this: v2, iGroup: SelectedIndex, iValue: index);
}

//------------------------------------------------------------------------------
// Address: 0x0043BA60
// Name: public: void ControlPanel::initBoneControllerChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initBoneControllerChoices(ControlPanel *this)
{
  StudioModel *v2; // ebx
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // ebx
  const studiohdr_t *v6; // eax
  int v7; // ebx
  const studiohdr_t *v8; // esi
  int bonecontrollerindex; // ebx
  char str[32]; // [esp+1Ch] [ebp-24h] BYREF
  int v11; // [esp+3Ch] [ebp-4h]

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
      mxWidget::setEnabled(this: this->cController, b: m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0);
      mxWidget::setEnabled(this: this->slController, b: m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0);
      mxChoice::removeAll(this: this->cController);
      v6 = m_pStudioHdr->m_pStudioHdr;
      v7 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0 )
      {
        v11 = 0;
        do
        {
          sprintf(string: str, format: "Controller %d", *(_DWORD *)&v6->name[v11 + 8 + v6->bonecontrollerindex]);
          mxChoice::add(this: this->cController, item: str);
          v6 = m_pStudioHdr->m_pStudioHdr;
          v11 += 56;
          ++v7;
        }
        while ( v7 < v6->numbonecontrollers );
      }
      v8 = m_pStudioHdr->m_pStudioHdr;
      if ( v8->numbonecontrollers > 0 )
      {
        bonecontrollerindex = v8->bonecontrollerindex;
        mxChoice::select(this: this->cController, index: 0);
        mxSlider::setRange(
          this: this->slController,
          min: *(float *)((char *)&v8->checksum + bonecontrollerindex),
          max: *(float *)&v8->name[bonecontrollerindex],
          ticks: 100);
        mxSlider::setValue(this: this->slController, value: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BBB0
// Name: public: void ControlPanel::setBoneController(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBoneController(ControlPanel *this, int index)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  const studiohdr_t *v7; // ecx
  int v8; // eax

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
      v7 = m_pStudioHdr->m_pStudioHdr;
      v8 = m_pStudioHdr->m_pStudioHdr->bonecontrollerindex + 56 * index;
      mxSlider::setRange(
        this: this->slController,
        min: *(float *)((char *)&v7->checksum + v8),
        max: *(float *)&v7->name[v8],
        ticks: 100);
      mxSlider::setValue(this: this->slController, value: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BC60
// Name: public: void ControlPanel::setBoneControllerValue(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBoneControllerValue(ControlPanel *this, int index, float value)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  StudioModel *v7; // eax
  int v8; // [esp+0h] [ebp-Ch]

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
      v8 = *(_DWORD *)&m_pStudioHdr->m_pStudioHdr->name[56 * index + 8 + m_pStudioHdr->m_pStudioHdr->bonecontrollerindex];
      v7 = models->GetActiveStudioModel(this: models);
      StudioModel::SetController(this: v7, iController: v8, flValue: value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BCF0
// Name: public: void ControlPanel::initPoseParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initPoseParameters(ControlPanel *this)
{
  StudioModel *v1; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // esi
  int i; // esi
  StudioModel *v6; // eax

  v1 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v1->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v1->m_MDLHandle);
      CStudioHdr::Init(this: v1->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
      v4 = v1->m_pStudioHdr;
      if ( v4->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v4;
    }
    if ( m_pStudioHdr != nullptr )
    {
      for ( i = 0; i < CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr); ++i )
      {
        v6 = models->GetActiveStudioModel(this: models);
        StudioModel::SetPoseParameter(this: v6, iParameter: i, flValue: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BD80
// Name: public: void ControlPanel::initSkinChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initSkinChoices(ControlPanel *this)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v6; // eax
  int v7; // esi
  StudioModel *v8; // eax
  char str[32]; // [esp+Ch] [ebp-20h] BYREF

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
      mxWidget::setEnabled(this: this->cSkin, b: m_pStudioHdr->m_pStudioHdr->numskinfamilies > 0);
      mxChoice::removeAll(this: this->cSkin);
      v6 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numskinfamilies > 0 )
      {
        do
        {
          v7 = v6 + 1;
          sprintf(string: str, format: "Skin %d", v6 + 1);
          mxChoice::add(this: this->cSkin, item: str);
          v6 = v7;
        }
        while ( v7 < m_pStudioHdr->m_pStudioHdr->numskinfamilies );
      }
      mxChoice::select(this: this->cSkin, index: 0);
      v8 = models->GetActiveStudioModel(this: models);
      StudioModel::SetSkin(this: v8, iValue: 0);
      g_viewerSettings.skin = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BE80
// Name: public: void ControlPanel::setModelInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setModelInfo(ControlPanel *this)
{
  StudioModel *v1; // edi
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // edi
  const studiohdr_t *v5; // edx
  int v6; // edi
  int v7; // ecx
  int numhitboxsets; // ebx
  char *v9; // eax
  int NumSeq_Internal; // eax
  int numbodyparts; // edi
  int numskinfamilies; // ebx
  int NumAttachments; // eax
  int numtextures; // [esp+8h] [ebp-8h]

  v1 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v1->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v1->m_MDLHandle);
      CStudioHdr::Init(this: v1->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
      v4 = v1->m_pStudioHdr;
      if ( v4->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v4;
    }
    if ( m_pStudioHdr != nullptr )
    {
      v5 = m_pStudioHdr->m_pStudioHdr;
      v6 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numhitboxsets > 0 )
      {
        v7 = 0;
        numhitboxsets = m_pStudioHdr->m_pStudioHdr->numhitboxsets;
        do
        {
          v9 = (char *)v5 + v7 + v5->hitboxsetindex;
          if ( v9 != nullptr )
            v9 = *((char **)v9 + 1);
          v6 += (int)v9;
          v7 += 12;
          --numhitboxsets;
        }
        while ( numhitboxsets != 0 );
      }
      if ( m_pStudioHdr->m_pVModel != nullptr )
        NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
      else
        NumSeq_Internal = v5->numlocalseq;
      sprintf(
        string: str,
        format: "Bones: %d\nBone Controllers: %d\nHit Boxes: %d in %d sets\nSequences: %d\n",
        m_pStudioHdr->m_pStudioHdr->numbones,
        m_pStudioHdr->m_pStudioHdr->numbonecontrollers,
        v6,
        m_pStudioHdr->m_pStudioHdr->numhitboxsets,
        NumSeq_Internal);
      mxWidget::setLabel(this: this->lModelInfo1, format: str);
      numbodyparts = m_pStudioHdr->m_pStudioHdr->numbodyparts;
      numskinfamilies = m_pStudioHdr->m_pStudioHdr->numskinfamilies;
      numtextures = m_pStudioHdr->m_pStudioHdr->numtextures;
      NumAttachments = CStudioHdr::GetNumAttachments(this: m_pStudioHdr);
      sprintf(
        string: str,
        format: "Textures: %d\nSkin Families: %d\nBodyparts: %d\nAttachments: %d\n",
        numtextures,
        numskinfamilies,
        numbodyparts,
        NumAttachments);
      mxWidget::setLabel(this: this->lModelInfo2, format: str);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BFB0
// Name: public: float ControlPanel::GetModelGap(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ControlPanel::GetModelGap(ControlPanel *this)
{
  return mxSlider::getValue(this: this->slModelGap);
}

//------------------------------------------------------------------------------
// Address: 0x0043BFC0
// Name: public: void ControlPanel::centerView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::centerView(ControlPanel *this)
{
  StudioModel *v1; // esi
  StudioModel *v2; // eax
  float v3; // xmm1_4
  float v4; // xmm0_4
  Vector max; // [esp+4h] [ebp-18h] BYREF
  Vector min; // [esp+10h] [ebp-Ch] BYREF

  v1 = models->GetActiveStudioModel(this: models);
  if ( v1 != nullptr )
  {
    v2 = models->GetActiveStudioModel(this: models);
    StudioModel::ExtractBbox(this: v2, a2: (int)v1, mins: &min, maxs: &max);
    v3 = max.x - min.x;
    v4 = max.z - min.z;
    if ( (float)(max.y - min.y) > (float)(max.x - min.x) )
      v3 = max.y - min.y;
    if ( v4 > v3 )
      v3 = max.z - min.z;
    v1->m_origin.x = v3;
    v1->m_origin.y = 0.0;
    v1->m_origin.z = (float)(v4 * 0.5) + min.z;
    v1->m_angles.x = 0.0;
    v1->m_angles.y = 0.0;
    v1->m_angles.z = 0.0;
    g_viewerSettings.lightrot.x = 0.0;
    g_viewerSettings.lightrot.y = -180.0;
    g_viewerSettings.lightrot.z = 0.0;
    g_pMatSysWindow->redraw(this: g_pMatSysWindow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C090
// Name: public: bool ControlPanel::Close(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ControlPanel::Close(ControlPanel *this)
{
  int v1; // eax
  CExpClass *v2; // eax

  v1 = g_pExpressionClass->getSelectedIndex(this: g_pExpressionClass);
  v2 = expressions->GetClass(this: expressions, a2: v1);
  return v2 == nullptr || expressions->CloseClass(this: expressions, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0043C0D0
// Name: public: bool ControlPanel::Closeall(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ControlPanel::Closeall(ControlPanel *this)
{
  CExpClass *v1; // eax

  while ( expressions->GetNumClasses(this: expressions) > 0 )
  {
    v1 = expressions->GetClass(this: expressions, a2: 0);
    if ( v1 == nullptr )
      break;
    if ( !expressions->CloseClass(this: expressions, a2: v1) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043C120
// Name: public: void ControlPanel::UndoExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::UndoExpression(ControlPanel *this, int index)
{
  CExpClass *v2; // eax
  CExpClass *v3; // esi
  CExpression *Expression; // eax

  if ( index != -1 )
  {
    v2 = expressions->GetActiveClass(this: expressions);
    v3 = v2;
    if ( v2 != nullptr )
    {
      Expression = CExpClass::GetExpression(this: v2, num: index);
      if ( Expression != nullptr )
      {
        CExpression::Undo(this: Expression);
        CExpClass::SelectExpression(this: v3, num: index, deselect: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C170
// Name: public: void ControlPanel::RedoExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::RedoExpression(ControlPanel *this, int index)
{
  CExpClass *v2; // eax
  CExpClass *v3; // esi
  CExpression *Expression; // eax

  if ( index != -1 )
  {
    v2 = expressions->GetActiveClass(this: expressions);
    v3 = v2;
    if ( v2 != nullptr )
    {
      Expression = CExpClass::GetExpression(this: v2, num: index);
      if ( Expression != nullptr )
      {
        CExpression::Redo(this: Expression);
        CExpClass::SelectExpression(this: v3, num: index, deselect: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C1C0
// Name: public: void ControlPanel::DeleteExpression(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::DeleteExpression(ControlPanel *this, int index)
{
  CExpClass *v2; // eax
  CExpClass *v3; // edi
  CExpression *Expression; // eax

  v2 = expressions->GetActiveClass(this: expressions);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Expression = CExpClass::GetExpression(this: v2, num: index);
    if ( Expression != nullptr )
    {
      Con_Printf(fmt: "Deleting expression %s : %s\n", Expression->name, Expression->description);
      FlexPanel::DeleteExpression(this: g_pFlexPanel, index);
      CExpClass::SelectExpression(this: v3, num: index - 1 < 0 ? 0 : index - 1, deselect: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C230
// Name: public: bool ControlPanel::AllToolsDriveSpeech(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ControlPanel::AllToolsDriveSpeech(ControlPanel *this)
{
  return mxCheckBox::isChecked(this: this->cbAllWindowsDriveSpeech);
}

//------------------------------------------------------------------------------
// Address: 0x0043C2C0
// Name: public: virtual bool ControlPanel::CanClose(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ControlPanel::CanClose(ControlPanel *this)
{
  int i; // edi
  CExpClass *v2; // eax
  IWorkspaceFiles_vtbl *v3; // esi
  const char *FileName; // eax
  CExpClass *v5; // eax

  workspacefiles->StartStoringFiles(this: workspacefiles, a2: 0);
  for ( i = 0; i < expressions->GetNumClasses(this: expressions); ++i )
  {
    v2 = expressions->GetClass(this: expressions, a2: i);
    if ( v2 != nullptr )
    {
      v3 = workspacefiles->__vftable;
      FileName = CExpClass::GetFileName(this: v2);
      v3->StoreFile(this: workspacefiles, a2: 0, a3: FileName);
    }
  }
  workspacefiles->FinishStoringFiles(this: workspacefiles, a2: 0);
  while ( expressions->GetNumClasses(this: expressions) > 0 )
  {
    v5 = expressions->GetClass(this: expressions, a2: 0);
    if ( v5 == nullptr )
      break;
    if ( !expressions->CloseClass(this: expressions, a2: v5) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043C390
// Name: public: virtual void ControlPanel::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::redraw(ControlPanel *this)
{
  DWORD SysColor; // eax
  void *(__cdecl **v3)(const char *, int *); // [esp+0h] [ebp-64h]
  int v4; // [esp+4h] [ebp-60h]
  CChoreoWidgetDrawHelper helper; // [esp+8h] [ebp-5Ch] BYREF
  Color bgColor; // [esp+60h] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) )
  {
    SysColor = GetSysColor(nIndex: 15);
    *(_WORD *)bgColor._color = SysColor;
    bgColor._color[2] = BYTE2(SysColor);
    bgColor._color[3] = 0;
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &helper, widget: this, &bgColor);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &helper);
    CSteamApplication::PostShutdown(pFactoryList: v3, nFactoryCount: v4);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &helper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C400
// Name: public: void ControlPanel::setSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setSequence(ControlPanel *this, int index)
{
  StudioModel *v3; // eax

  mxChoice::select(this: this->cSequence, index);
  v3 = models->GetActiveStudioModel(this: models);
  StudioModel::SetSequence(this: v3, iSequence: index);
  ControlPanel::initPoseParameters(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043C440
// Name: public: virtual int ControlPanel::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::handleEvent(ControlPanel *this, mxEvent *event)
{
  int v4; // eax
  int width; // edi
  int v6; // eax
  int action; // eax
  int v8; // eax
  bool isChecked; // al
  bool v10; // al
  bool v11; // al
  int v12; // eax
  int v13; // eax
  int v14; // eax
  double v15; // st7
  const char *v16; // eax
  int v17; // eax
  int SelectedIndex; // eax
  int v19; // eax
  int v20; // edi
  int v21; // esi
  StudioModel *v22; // eax
  int value; // [esp+8h] [ebp-18h]
  float valuea; // [esp+8h] [ebp-18h]
  float valueb; // [esp+8h] [ebp-18h]
  float valuec; // [esp+8h] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp-8h]
  int iret; // [esp+1Ch] [ebp-4h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  iret = 0;
  if ( this->HandleToolEvent(this: &this->IFacePoserToolWindow, a2: event) )
  {
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return 0;
  }
  else
  {
    v4 = event->event;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
      {
        width = event->width;
        if ( this->tab != nullptr )
        {
          value = event->height;
          v6 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
          mxWidget::setBounds(this: this->tab, x: 0, y: v6, w: width, h: value);
        }
        iret = 1;
      }
    }
    else
    {
      action = event->action;
      iret = 1;
      if ( action > 3001 )
      {
        if ( action > 4001 )
        {
          switch ( action )
          {
            case 4002:
              SelectedIndex = mxChoice::getSelectedIndex(this: this->cSubmodel);
              if ( SelectedIndex >= 0 )
                ControlPanel::setSubmodel(this, index: SelectedIndex);
              break;
            case 4003:
              v19 = mxChoice::getSelectedIndex(this: this->cController);
              if ( v19 >= 0 )
                ControlPanel::setBoneController(this, index: v19);
              break;
            case 4004:
              v20 = mxChoice::getSelectedIndex(this: this->cController);
              if ( v20 >= 0 )
              {
                valuec = mxSlider::getValue(this: this->slController);
                ControlPanel::setBoneControllerValue(this, index: v20, value: valuec);
              }
              break;
            case 4005:
              v21 = mxChoice::getSelectedIndex(this: this->cSkin);
              if ( v21 >= 0 )
              {
                v22 = models->GetActiveStudioModel(this: models);
                StudioModel::SetSkin(this: v22, iValue: v21);
                g_viewerSettings.skin = v21;
                g_pMatSysWindow->redraw(this: g_pMatSysWindow);
              }
              break;
            default:
              goto LABEL_43;
          }
        }
        else if ( action == 4001 )
        {
          v17 = mxChoice::getSelectedIndex(this: this->cBodypart);
          if ( v17 >= 0 )
            ControlPanel::setBodypart(this, index: v17);
        }
        else
        {
          v13 = action - 3002;
          if ( v13 != 0 )
          {
            v14 = v13 - 1;
            if ( v14 != 0 )
            {
              if ( v14 == 1 )
              {
                valuea = mxSlider::getValue(this: (mxSlider *)event->widget);
                ControlPanel::setBlend(this, index: 1, value: valuea);
              }
              else
              {
LABEL_43:
                iret = 0;
              }
            }
            else
            {
              valueb = mxSlider::getValue(this: (mxSlider *)event->widget);
              ControlPanel::setBlend(this, index: 0, value: valueb);
            }
          }
          else
          {
            v15 = mxSlider::getValue(this: (mxSlider *)event->widget);
            g_viewerSettings.speedScale = v15;
            v16 = va(fmt: "Speed scale %.2f", v15);
            mxWidget::setLabel(this: this->lSpeedScale, format: v16);
          }
        }
      }
      else if ( action == 3001 )
      {
        v12 = mxChoice::getSelectedIndex(this: this->cSequence);
        if ( v12 >= 0 )
          ControlPanel::setSequence(this, index: v12);
      }
      else
      {
        switch ( action )
        {
          case 1901:
            g_viewerSettings.showTexture = mxTab::getSelectedIndex(this: this->tab) == 3;
            break;
          case 2001:
            v8 = mxChoice::getSelectedIndex(this: this->cRenderMode);
            if ( v8 >= 0 )
              ControlPanel::setRenderMode(this, mode: v8);
            break;
          case 2003:
            isChecked = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            ControlPanel::setShowGround(this, b: isChecked);
            break;
          case 2004:
            v10 = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            ControlPanel::setShowMovement(this, b: v10);
            break;
          case 2005:
            v11 = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            ControlPanel::setShowBackground(this, b: v11);
            break;
          case 2006:
            g_viewerSettings.showHitBoxes = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            break;
          case 2007:
            g_viewerSettings.showBones = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            break;
          case 2008:
            g_viewerSettings.showAttachments = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            break;
          case 2009:
            g_viewerSettings.showPhysicsModel = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            break;
          case 2012:
            g_viewerSettings.faceposerToolsDriveMouth = mxCheckBox::isChecked(this: (mxCheckBox *)event->widget);
            break;
          default:
            goto LABEL_43;
        }
      }
    }
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return iret;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C830
// Name: public: void ControlPanel::ChangeModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::ChangeModel(ControlPanel *this, const char *filename)
{
  HCURSOR CursorA; // eax
  StudioModel *v4; // eax
  int Sequence; // edi
  StudioModel *v6; // eax
  const char *v7; // eax
  CExpClass *v8; // eax
  CExpClass *v9; // edi
  int SelectedExpression; // eax
  const char *v11; // eax
  const char *v12; // eax
  HICON__ *hPrevCursor; // [esp+10h] [ebp-4h]

  CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F02);
  hPrevCursor = SetCursor(hCursor: CursorA);
  ControlPanel::initSequenceChoices(this);
  ControlPanel::initBodypartChoices(this);
  ControlPanel::initBoneControllerChoices(this);
  ControlPanel::initSkinChoices(this);
  ControlPanel::setModelInfo(this);
  SetCloseCaptionLanguageId(id: g_viewerSettings.cclanguageid, force: true);
  g_viewerSettings.m_iEditAttachment = -1;
  *(_WORD *)&g_viewerSettings.enableIK = 1;
  v4 = models->GetActiveStudioModel(this: models);
  Sequence = StudioModel::GetSequence(this: v4);
  mxChoice::select(this: this->cSequence, index: Sequence);
  v6 = models->GetActiveStudioModel(this: models);
  StudioModel::SetSequence(this: v6, iSequence: Sequence);
  ControlPanel::initPoseParameters(this);
  mxSlider::setValue(this: this->slSpeedScale, value: g_viewerSettings.speedScale);
  v7 = mx_getpath(filename);
  mx_setcwd(path: v7);
  FlexPanel::initFlexes(this: g_pFlexPanel);
  IFacePoserToolWindow::ModelChanged();
  v8 = expressions->GetActiveClass(this: expressions);
  v9 = v8;
  if ( v8 != nullptr )
  {
    SelectedExpression = CExpClass::GetSelectedExpression(this: v8);
    CExpClass::SelectExpression(this: v9, num: SelectedExpression, deselect: true);
  }
  v11 = models->GetActiveModelName(this: models);
  v12 = va(fmt: " - %s.mdl", v11);
  IFacePoserToolWindow::SetSuffix(this: &this->IFacePoserToolWindow, suffix: v12);
  this->redraw(this);
  SetCursor(hCursor: hPrevCursor);
}

//------------------------------------------------------------------------------
// Address: 0x0043C980
// Name: public: void ControlPanel::CenterOnFace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::CenterOnFace(ControlPanel *this)
{
  StudioModel *(__thiscall *GetActiveStudioModel)(IFaceposerModels *); // edx
  StudioModel *v3; // eax
  StudioModel *v4; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  StudioModel *v7; // eax
  int v8; // eax
  IFaceposerModels_vtbl *v9; // edx
  StudioModel *v10; // eax
  const char *v11; // esi
  StudioModel *v12; // eax
  CStudioHdr *v13; // ecx
  const studiohdr_t *v14; // eax
  float z; // edx
  __int64 v16; // xmm0_8
  float v17; // edx
  float v18; // eax
  int v19; // ebx
  const mstudioattachment_t *v20; // esi
  int AttachmentBone; // edi
  const matrix3x4_t *v22; // eax
  float v23; // edx
  KeyValues *v24; // eax
  KeyValues *v25; // ebx
  const char *KeyValueText; // eax
  KeyValues *Key; // eax
  double Float; // st7
  StudioModel *(__thiscall *v29)(IFaceposerModels *); // eax
  float x; // ebx
  int v31; // esi
  int (__thiscall *Count)(IFaceposerModels *); // eax
  int v33; // edi
  float *v34; // edi
  int (__thiscall *v35)(IFaceposerModels *); // eax
  int v36; // eax
  int Value; // ecx
  int v38; // ebx
  CStudioHdr *v39; // eax
  matrix3x4_t attachmentPoseToLocal; // [esp+14h] [ebp-A0h] BYREF
  matrix3x4_t boneToPose; // [esp+44h] [ebp-70h] BYREF
  Vector localSpaceEyePosition; // [esp+74h] [ebp-40h] BYREF
  __int64 v43; // [esp+80h] [ebp-34h]
  float v44; // [esp+88h] [ebp-2Ch]
  Vector size; // [esp+8Ch] [ebp-28h] BYREF
  int v46; // [esp+98h] [ebp-1Ch]
  float v47; // [esp+9Ch] [ebp-18h]
  ControlPanel *v48; // [esp+A0h] [ebp-14h]
  StudioModel *mdl; // [esp+A4h] [ebp-10h]
  CStudioHdr *hdr; // [esp+A8h] [ebp-Ch]
  int oldSeq; // [esp+ACh] [ebp-8h]
  int flEyeheight; // [esp+B0h] [ebp-4h]

  GetActiveStudioModel = models->GetActiveStudioModel;
  v48 = this;
  if ( (int)GetActiveStudioModel(this: models) != 0 )
  {
    v3 = models->GetActiveStudioModel(this: models);
    v4 = v3;
    mdl = v3;
    if ( v3 != nullptr )
    {
      m_pStudioHdr = v3->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr
        || m_pStudioHdr->m_pStudioHdr != nullptr
        || (v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v4->m_MDLHandle),
            CStudioHdr::Init(this: v4->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr),
            (m_pStudioHdr = v4->m_pStudioHdr)->m_pStudioHdr != nullptr) )
      {
        hdr = m_pStudioHdr;
        if ( m_pStudioHdr != nullptr )
        {
          g_viewerSettings.speedScale = 1.0;
          mxSlider::setValue(this: this->slSpeedScale, value: 1.0);
          v7 = models->GetActiveStudioModel(this: models);
          *(float *)&v8 = COERCE_FLOAT(StudioModel::GetSequence(this: v7));
          v9 = models->__vftable;
          oldSeq = v8;
          v10 = v9->GetActiveStudioModel(this: models);
          *(float *)&v11 = COERCE_FLOAT(StudioModel::LookupSequence(this: v10, szSequence: "idle_suble"));
          flEyeheight = (int)v11;
          if ( *(float *)&v11 == NAN )
          {
            *(float *)&flEyeheight = 0.0;
            *(float *)&v11 = 0.0;
          }
          if ( v11 != (const char *)oldSeq )
            Con_Printf(fmt: "Centering changed model sequence # to %d\n", v11);
          mxChoice::select(this: this->cSequence, index: (int)v11);
          v12 = models->GetActiveStudioModel(this: models);
          StudioModel::SetSequence(this: v12, iSequence: (int)v11);
          ControlPanel::initPoseParameters(this);
          ControlPanel::initPoseParameters(this);
          v13 = hdr;
          v14 = hdr->m_pStudioHdr;
          v4->m_angles.x = 0.0;
          v4->m_angles.y = 0.0;
          v4->m_angles.z = 0.0;
          v4->m_origin.x = 0.0;
          v4->m_origin.y = 0.0;
          v4->m_origin.z = 0.0;
          z = v14->hull_min.z;
          v43 = *(_QWORD *)&v14->hull_min.x;
          v16 = *(_QWORD *)&v14->hull_max.x;
          v44 = z;
          v17 = v14->hull_max.z;
          v18 = v14->hull_min.z;
          *(_QWORD *)&localSpaceEyePosition.x = v16;
          localSpaceEyePosition.z = v17;
          *(float *)&v16 = v17 - v44;
          v47 = v17 - v44;
          v44 = v18;
          *(float *)&oldSeq = *(float *)&v16 * 0.9 + v18;
          if ( CStudioHdr::GetNumAttachments(this: v13) > 0 )
          {
            v19 = 0;
            if ( CStudioHdr::GetNumAttachments(this: hdr) > 0 )
            {
              while ( 1 )
              {
                v20 = CStudioHdr::pAttachment(this: hdr, i: v19);
                AttachmentBone = CStudioHdr::GetAttachmentBone(this: hdr, i: v19);
                if ( _V_stricmp(s1: (const char *)v20 + v20->sznameindex, s2: "eyes") == 0 )
                {
                  v22 = (const matrix3x4_t *)((char *)hdr->m_pStudioHdr
                                            + 216 * AttachmentBone
                                            + hdr->m_pStudioHdr->boneindex);
                  if ( v22 != nullptr )
                    break;
                }
                if ( ++v19 >= CStudioHdr::GetNumAttachments(this: hdr) )
                  goto LABEL_18;
              }
              MatrixInvert(in: v22 + 2, out: &boneToPose);
              ConcatTransforms(in1: &boneToPose, in2: &v20->local, out: &attachmentPoseToLocal);
              VectorITransform(in1: &vec3_origin.x, in2: &attachmentPoseToLocal, out: &localSpaceEyePosition.x);
              v23 = hdr->m_pStudioHdr->hull_min.z;
              v43 = *(_QWORD *)&hdr->m_pStudioHdr->hull_min.x;
              v44 = v23;
              *(float *)&oldSeq = v23 - localSpaceEyePosition.z;
LABEL_18:
              v11 = (const char *)flEyeheight;
              v4 = mdl;
            }
          }
          v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v24 != nullptr )
            v25 = KeyValues::KeyValues(this: v24, setName: defaultValue);
          else
            v25 = nullptr;
          flEyeheight = (int)v4->m_pModelName;
          KeyValueText = StudioModel::GetKeyValueText(this: v4, iSequence: (int)v11);
          if ( KeyValues::LoadFromBuffer(
                 this: v25,
                 resourceName: (const char *)flEyeheight,
                 pBuffer: KeyValueText,
                 pFileSystem: nullptr,
                 pPathID: nullptr,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            Key = KeyValues::FindKey(this: v25, keyName: "faceposer", bCreate: false);
            if ( Key != nullptr )
            {
              Float = KeyValues::GetFloat(this: Key, keyName: "eye_height", defaultValue: -9999.0);
              *(float *)&flEyeheight = Float;
              if ( Float != -9999.0 )
                oldSeq = flEyeheight;
            }
          }
          KeyValues::deleteThis(this: v25);
          v4->m_origin.x = v47 * 0.64999998;
          v4->m_origin.z = *(float *)&oldSeq + v4->m_origin.z;
          v29 = models->GetActiveStudioModel;
          memset(&size, 0, sizeof(size));
          v46 = 0;
          v47 = 0.0;
          *(float *)&oldSeq = COERCE_FLOAT((int)v29(this: models));
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&size,
            num: 1);
          x = size.x;
          v31 = v46 + 1;
          v47 = size.x;
          if ( v46 > 0 )
            _V_memmove(dest: (void *)(LODWORD(size.x) + 4), src: (const void *)LODWORD(size.x), count: 4 * v46);
          if ( x != 0.0 )
            *(float *)LODWORD(x) = *(float *)&oldSeq;
          if ( models->CountVisibleModels(this: models) > 0 )
          {
            Count = models->Count;
            v31 = 0;
            v46 = 0;
            *(float *)&flEyeheight = 0.0;
            if ( Count(this: models) > 0 )
            {
              do
              {
                if ( models->IsModelShownIn3DView(this: models, a2: flEyeheight) )
                {
                  *(float *)&oldSeq = COERCE_FLOAT((int)models->GetStudioModel(this: models, a2: flEyeheight));
                  v33 = v31;
                  if ( v31 + 1 > SLODWORD(size.y) )
                  {
                    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&size,
                      num: v31 - LODWORD(size.y) + 1);
                    v31 = v46;
                    x = size.x;
                  }
                  v46 = ++v31;
                  v47 = x;
                  if ( v31 - v33 - 1 > 0 )
                    _V_memmove(
                      dest: (void *)(LODWORD(x) + 4 * v33 + 4),
                      src: (const void *)(LODWORD(x) + 4 * v33),
                      count: 4 * (v31 - v33 - 1));
                  v34 = (float *)(LODWORD(x) + 4 * v33);
                  if ( v34 != nullptr )
                    *v34 = *(float *)&oldSeq;
                  v4 = mdl;
                }
                v35 = models->Count;
                ++flEyeheight;
                v36 = v35(this: models);
              }
              while ( flEyeheight < v36 );
            }
          }
          Value = (int)mxSlider::getValue(this: v48->slModelGap);
          v38 = 0;
          if ( v31 > 0 )
          {
            oldSeq = -(Value * (v31 / -2));
            v48 = (ControlPanel *)-Value;
            do
            {
              v39 = models->GetStudioHeader(this: models, a2: v38);
              if ( v39 == hdr )
                v4->m_origin.y = (float)oldSeq;
              oldSeq += (int)v48;
              ++v38;
            }
            while ( v38 < v31 );
          }
          g_pMatSysWindow->redraw(this: g_pMatSysWindow);
          if ( size.z >= 0.0 && LODWORD(size.x) != 0 )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(size.x));
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461D20
// Name: public: virtual bool CControlPanelTabWindow::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CControlPanelTabWindow::PaintBackground(CControlPanelTabWindow *this)
{
  DWORD SysColor; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+0h] [ebp-6Ch] BYREF
  tagRECT rc; // [esp+58h] [ebp-14h] BYREF
  Color clr; // [esp+68h] [ebp-4h] BYREF

  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
  CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
  SysColor = GetSysColor(nIndex: 15);
  *(_WORD *)clr._color = SysColor;
  clr._color[2] = BYTE2(SysColor);
  clr._color[3] = 0;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: &drawHelper, &clr, &rc);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  return false;
}
