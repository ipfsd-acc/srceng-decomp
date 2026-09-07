// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choreoactorwidget.cpp
// Functions: 12
// ============================================================

#include "utils\hlfaceposer\choreoactorwidget.h"

//------------------------------------------------------------------------------
// Address: 0x0048C750
// Name: public: bool CChoreoActorWidget::GetShowChannels(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoActorWidget::GetShowChannels(CChoreoActorWidget *this)
{
  return this->m_bShowChannels;
}

//------------------------------------------------------------------------------
// Address: 0x0048C760
// Name: public: void CChoreoActorWidget::ShowChannels(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActorWidget::ShowChannels(CChoreoActorWidget *this, bool show)
{
  this->m_bShowChannels = show;
  mxWidget::setVisible(this: this->m_btnOpen, b: !show);
  mxWidget::setVisible(this: this->m_btnClose, b: this->m_bShowChannels);
  CChoreoView::InvalidateLayout(this: CChoreoWidget::m_pView);
}

//------------------------------------------------------------------------------
// Address: 0x0048C7A0
// Name: public: float __near * CChoreoActorWidget::GetSettings(void)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CChoreoActorWidget::GetSettings(CChoreoActorWidget *this)
{
  return this->m_rgCurrentSetting;
}

//------------------------------------------------------------------------------
// Address: 0x0048C7B0
// Name: public: void CChoreoActorWidget::ResetSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActorWidget::ResetSettings(CChoreoActorWidget *this)
{
  memset(dst: (unsigned __int8 *)this->m_rgCurrentSetting, value: 0, count: sizeof(this->m_rgCurrentSetting));
}

//------------------------------------------------------------------------------
// Address: 0x0048C810
// Name: public: virtual void CChoreoActorWidget::Layout(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActorWidget::Layout(CChoreoActorWidget *this, tagRECT *rc)
{
  int v3; // ebx
  int v4; // ebx
  CChoreoChannelWidget *v5; // esi
  int v6; // eax
  int v7; // eax
  tagRECT rcChannels; // [esp+Ch] [ebp-10h] BYREF

  this->setBounds(this, a2: rc->left, a3: rc->top, a4: rc->right - rc->left, a5: rc->bottom - rc->top);
  v3 = rc->top + 5;
  mxWidget::setBounds(this: this->m_btnOpen, x: rc->left + 2, y: v3, w: 16, h: 16);
  mxWidget::setBounds(this: this->m_btnClose, x: rc->left + 2, y: v3, w: 16, h: 16);
  if ( v3 > CChoreoView::GetStartRow(this: CChoreoWidget::m_pView)
    && v3 + 16 < CChoreoView::GetEndRow(this: CChoreoWidget::m_pView) )
  {
    mxWidget::setVisible(this: this->m_btnOpen, b: !this->m_bShowChannels);
    mxWidget::setVisible(this: this->m_btnClose, b: this->m_bShowChannels);
  }
  else
  {
    mxWidget::setVisible(this: this->m_btnOpen, b: false);
    mxWidget::setVisible(this: this->m_btnClose, b: false);
  }
  *(_QWORD *)&rcChannels.left = *(_QWORD *)&rc->left;
  rcChannels.top += 26;
  v4 = 0;
  for ( *(_QWORD *)&rcChannels.right = *(_QWORD *)&rc->right; v4 < this->m_Channels.m_Size; ++v4 )
  {
    v5 = this->m_Channels.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v6 = v5->GetItemHeight(this: v5);
      rcChannels.bottom = rcChannels.top + v6;
      v5->Layout(this: v5, a2: &rcChannels);
      v7 = v5->GetItemHeight(this: v5);
      OffsetRect(lprc: &rcChannels, dx: 0, dy: v7);
      v5->setVisible(this: v5, a2: this->m_bShowChannels);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C930
// Name: public: virtual int CChoreoActorWidget::GetItemHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoActorWidget::GetItemHeight(CChoreoActorWidget *this)
{
  int v2; // ebx
  int i; // esi
  CChoreoChannelWidget *v4; // ecx

  v2 = 28;
  if ( !this->m_bShowChannels )
    return 28;
  for ( i = 0; i < this->m_Channels.m_Size; v2 += v4->GetItemHeight(this: v4) )
    v4 = this->m_Channels.m_Memory.m_pMemory[i++];
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0048C970
// Name: public: class CChoreoChannelWidget __near * CChoreoActorWidget::GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannelWidget *__thiscall CChoreoActorWidget::GetChannel(CChoreoActorWidget *this, int num)
{
  return this->m_Channels.m_Memory.m_pMemory[num];
}

//------------------------------------------------------------------------------
// Address: 0x0048C980
// Name: public: virtual void CChoreoActorWidget::redraw(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActorWidget::redraw(CChoreoActorWidget *this, int drawHelper)
{
  bool (__thiscall *getVisible)(struct CChoreoActorWidget *); // edx
  CChoreoActor *m_pActor; // edi
  bool Active; // al
  CChoreoWidgetDrawHelper *v6; // esi
  int left; // edi
  int LabelWidth; // eax
  int right; // ebx
  int v10; // eax
  int top; // edi
  int v12; // ebx
  CChoreoActor *v13; // ebx
  CChoreoActor *Name; // eax
  char *v15; // edi
  char v16; // cl
  Color *p_drawHelper; // eax
  int FontSize; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  HFONT__ *v25; // edi
  char *FacePoserModelName; // eax
  char *v27; // eax
  char v28; // cl
  int v29; // eax
  _DWORD *v30; // edi
  int v31; // ebx
  int v32; // edi
  int v33; // edi
  int v34; // eax
  int v35; // eax
  int v36; // edi
  CChoreoChannel *Channel; // eax
  int NumEvents; // eax
  int NumChannels; // eax
  int v40; // eax
  const Color *v41; // [esp-14h] [ebp-554h]
  CChoreoActor *v42; // [esp-Ch] [ebp-54Ch]
  int v43; // [esp-Ch] [ebp-54Ch]
  char v44; // [esp+3h] [ebp-53Dh] BYREF
  char shortname[512]; // [esp+4h] [ebp-53Ch] BYREF
  char sz[256]; // [esp+204h] [ebp-33Ch] BYREF
  char n[512]; // [esp+304h] [ebp-23Ch] BYREF
  tagRECT rcName; // [esp+504h] [ebp-3Ch] BYREF
  CChoreoActorWidget *v49; // [esp+514h] [ebp-2Ch]
  tagRECT rcChannel; // [esp+518h] [ebp-28h] BYREF
  CChoreoActor *actor; // [esp+528h] [ebp-18h]
  tagRECT rcModelName; // [esp+52Ch] [ebp-14h] BYREF
  Color clr; // [esp+53Ch] [ebp-4h] BYREF

  getVisible = this->getVisible;
  v49 = this;
  if ( ((unsigned __int8 (__fastcall *)(CChoreoActorWidget *))getVisible)(a1: this) != 0 )
  {
    m_pActor = this->m_pActor;
    actor = m_pActor;
    if ( m_pActor != nullptr )
    {
      rcModelName = *this->getBounds(this);
      Active = CChoreoActor::GetActive(this: m_pActor);
      v6 = (CChoreoWidgetDrawHelper *)drawHelper;
      if ( !Active )
      {
        *(_QWORD *)&rcChannel.left = *(_QWORD *)&rcModelName.left;
        rcChannel.bottom = rcModelName.bottom;
        rcChannel.right = rcModelName.left + CChoreoView::GetLabelWidth(this: CChoreoWidget::m_pView);
        InflateRect(lprc: &rcChannel, dx: -3, dy: -5);
        drawHelper = 14474460;
        CChoreoWidgetDrawHelper::DrawFilledRect(this: v6, clr: (const Color *)&drawHelper, rc: &rcChannel);
      }
      left = rcModelName.left;
      rcChannel.left = rcModelName.left;
      LabelWidth = CChoreoView::GetLabelWidth(this: CChoreoWidget::m_pView);
      right = rcModelName.right;
      v10 = left + LabelWidth;
      top = rcModelName.top;
      rcChannel.right = v10;
      rcChannel.top = rcModelName.top;
      rcChannel.bottom = rcModelName.top + 26;
      drawHelper = 11520200;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: v6,
        clr: (HPEN__ *)&drawHelper,
        style: 0,
        width: 1,
        x1: 0,
        y1: rcModelName.top,
        x2: rcModelName.right,
        y2: rcModelName.top);
      drawHelper = 11520200;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: v6,
        clr: (HPEN__ *)&drawHelper,
        style: 0,
        width: 1,
        x1: 0,
        y1: rcModelName.bottom - 2,
        x2: right,
        y2: rcModelName.bottom - 2);
      v12 = rcModelName.bottom - 1;
      drawHelper = 16764616;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: v6,
        clr: (HPEN__ *)&drawHelper,
        style: 0,
        width: 1,
        x1: 0,
        y1: rcModelName.bottom - 1,
        x2: rcModelName.right,
        y2: rcModelName.bottom - 1);
      drawHelper = 4144959;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: v6,
        clr: (HPEN__ *)&drawHelper,
        style: 0,
        width: 1,
        x1: rcChannel.right,
        y1: top,
        x2: rcChannel.right,
        y2: v12);
      v13 = actor;
      rcName.top = rcChannel.top;
      *(_QWORD *)&rcName.right = *(_QWORD *)&rcChannel.right;
      rcName.left = rcModelName.left + 18;
      Name = CChoreoActor::GetName(this: actor);
      v15 = (char *)(n - (char *)Name);
      do
      {
        v16 = Name->m_szName[0];
        Name->m_szName[(_DWORD)v15] = Name->m_szName[0];
        Name = (CChoreoActor *)((char *)Name + 1);
      }
      while ( v16 != 0 );
      if ( CChoreoActor::GetActive(this: v13) )
      {
        drawHelper = 9868880;
        p_drawHelper = (Color *)&drawHelper;
      }
      else
      {
        clr = (Color)9868950;
        p_drawHelper = &clr;
      }
      v41 = p_drawHelper;
      FontSize = CChoreoView::GetFontSize(this: CChoreoWidget::m_pView);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: v6,
        font: "Arial",
        pointsize: FontSize + 5,
        weight: 1000,
        clr: v41,
        rcText: &rcName,
        fmt: n);
      if ( !CChoreoActor::GetActive(this: v13) )
      {
        strcpy(n, "(inactive)");
        rcModelName = rcName;
        v19 = CChoreoView::GetFontSize(this: CChoreoWidget::m_pView);
        v20 = CChoreoWidgetDrawHelper::CalcTextWidth(
                font: "Arial",
                pointsize: (HFONT__ *)(v19 - 2),
                weight: 500,
                fmt: n);
        rcModelName.top += 3;
        rcModelName.left = rcModelName.right - v20 - 5;
        v21 = CChoreoView::GetFontSize(this: CChoreoWidget::m_pView);
        rcModelName.bottom = v21 + rcModelName.top - 2;
        drawHelper = 9868950;
        v22 = CChoreoView::GetFontSize(this: CChoreoWidget::m_pView);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v6,
          font: "Arial",
          pointsize: v22 - 2,
          weight: 500,
          clr: (const Color *)&drawHelper,
          rcText: &rcModelName,
          fmt: n);
      }
      rcName.left -= 18;
      if ( *CChoreoActor::GetFacePoserModelName(this: v13) != 0 )
      {
        v42 = CChoreoActor::GetName(this: v13);
        v23 = CChoreoView::GetFontSize(this: CChoreoWidget::m_pView);
        v24 = CChoreoWidgetDrawHelper::CalcTextWidth(
                font: "Arial",
                pointsize: (HFONT__ *)(v23 + 5),
                weight: 1000,
                fmt: v42->m_szName);
        rcModelName.top = rcName.top;
        *(_QWORD *)&rcModelName.right = *(_QWORD *)&rcName.right;
        rcModelName.left = v24 + rcName.left + 16;
        v25 = (HFONT__ *)(CChoreoView::GetFontSize(this: CChoreoWidget::m_pView) - 2);
        FacePoserModelName = CChoreoActor::GetFacePoserModelName(this: v13);
        V_FileBase(in: FacePoserModelName, out: shortname, maxlen: 512);
        v27 = &v44;
        do
          v28 = *++v27;
        while ( v28 != 0 );
        strcpy(v27, ".mdl");
        v29 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: v25, weight: 400, fmt: shortname);
        rcModelName.left = rcModelName.right - v29 - 5;
        rcModelName.top = rcModelName.bottom - (_DWORD)v25;
        OffsetRect(lprc: &rcModelName, dx: 0, dy: -3);
        drawHelper = 7910580;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v6,
          font: "Arial",
          pointsize: (int)v25,
          weight: 400,
          clr: (const Color *)&drawHelper,
          rcText: &rcModelName,
          fmt: shortname);
      }
      v30 = &v49->__vftable;
      if ( v49->m_bShowChannels )
      {
        v31 = 0;
        if ( v49->m_Channels.m_Size > 0 )
        {
          actor = (CChoreoActor *)(rcChannel.right + 1);
          while ( 1 )
          {
            v32 = *(_DWORD *)(v30[8] + 4 * v31);
            if ( v32 != 0 )
              (*(void (__thiscall **)(int, CChoreoWidgetDrawHelper *))(*(_DWORD *)v32 + 12))(a1: v32, a2: v6);
            rcChannel = *(tagRECT *)(*(int (__thiscall **)(int))(*(_DWORD *)v32 + 68))(a1: v32);
            v33 = rcChannel.right;
            drawHelper = 11520200;
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: v6,
              clr: (HPEN__ *)&drawHelper,
              style: 0,
              width: 1,
              x1: (int)actor,
              y1: rcChannel.top,
              x2: rcChannel.right,
              y2: rcChannel.top);
            clr = (Color)11520200;
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: v6,
              (HPEN__ *)&clr,
              style: 0,
              width: 1,
              x1: (int)actor,
              y1: rcChannel.bottom,
              x2: v33,
              y2: rcChannel.bottom);
            if ( ++v31 >= v49->m_Channels.m_Size )
              break;
            v30 = &v49->__vftable;
          }
        }
      }
      else
      {
        v34 = CChoreoView::GetLabelWidth(this: CChoreoWidget::m_pView);
        OffsetRect(lprc: &rcName, dx: v34 + 10, dy: 0);
        v35 = (*(int (__thiscall **)(_DWORD *))(*v30 + 48))(a1: v30);
        v36 = 0;
        rcName.right = v35;
        for ( drawHelper = 0; v36 < CChoreoActor::GetNumChannels(this: v13); ++v36 )
        {
          Channel = CChoreoActor::GetChannel(this: v13, channel: v36);
          if ( Channel != nullptr )
          {
            NumEvents = CChoreoChannel::GetNumEvents(this: Channel);
            drawHelper += NumEvents;
          }
        }
        v43 = drawHelper;
        NumChannels = CChoreoActor::GetNumChannels(this: v13);
        sprintf(string: sz, format: "%i channels with %i events hidden", NumChannels, v43);
        drawHelper = 9868880;
        v40 = CChoreoView::GetFontSize(this: CChoreoWidget::m_pView);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v6,
          font: "Arial",
          pointsize: v40,
          weight: 400,
          clr: (const Color *)&drawHelper,
          rcText: &rcName,
          fmt: sz);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048CE90
// Name: public: CChoreoActorWidget::CChoreoActorWidget(class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoActorWidget *__thiscall CChoreoActorWidget::CChoreoActorWidget(CChoreoActorWidget *this, CChoreoWidget *parent)
{
  CActorBitmapButton *v3; // edi
  mxBitmapButton *v4; // eax
  CActorBitmapButton *v5; // edi
  CActorBitmapButton *m_btnOpen; // ecx
  bool v8; // [esp-4h] [ebp-10h]

  CChoreoWidget::CChoreoWidget(this, parent);
  this->__vftable = (CChoreoActorWidget_vtbl *)&CChoreoActorWidget::`vftable';
  this->m_Channels.m_Memory.m_pMemory = nullptr;
  this->m_Channels.m_Memory.m_nAllocationCount = 0;
  this->m_Channels.m_Memory.m_nGrowSize = 0;
  this->m_Channels.m_Size = 0;
  this->m_Channels.m_pElements = nullptr;
  this->m_pParent = parent;
  this->m_pActor = nullptr;
  this->m_bShowChannels = true;
  v3 = (CActorBitmapButton *)operator new(nSize: 0x20u);
  if ( v3 != nullptr )
  {
    mxBitmapButton::mxBitmapButton(
      this: v3,
      parent: CChoreoWidget::m_pView,
      x: 0,
      y: 0,
      w: 0,
      h: 0,
      id: 5030,
      bitmap: "gfx/hlfaceposer/channelopen.bmp");
    v3->__vftable = (CActorBitmapButton_vtbl *)&CActorBitmapButton::`vftable';
    v3->m_pActor = this;
  }
  else
  {
    v3 = nullptr;
  }
  this->m_btnOpen = v3;
  v4 = (mxBitmapButton *)operator new(nSize: 0x20u);
  v5 = (CActorBitmapButton *)v4;
  if ( v4 != nullptr )
  {
    mxBitmapButton::mxBitmapButton(
      this: v4,
      parent: CChoreoWidget::m_pView,
      x: 0,
      y: 0,
      w: 0,
      h: 0,
      id: 5031,
      bitmap: "gfx/hlfaceposer/channelclose.bmp");
    v5->__vftable = (CActorBitmapButton_vtbl *)&CActorBitmapButton::`vftable';
    v5->m_pActor = this;
  }
  else
  {
    v5 = nullptr;
  }
  m_btnOpen = this->m_btnOpen;
  v8 = !this->m_bShowChannels;
  this->m_btnClose = v5;
  mxWidget::setVisible(this: m_btnOpen, b: v8);
  mxWidget::setVisible(this: this->m_btnClose, b: this->m_bShowChannels);
  CChoreoView::InvalidateLayout(this: CChoreoWidget::m_pView);
  memset(dst: (unsigned __int8 *)this->m_rgCurrentSetting, value: 0, count: sizeof(this->m_rgCurrentSetting));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048CF80
// Name: public: virtual CChoreoActorWidget::~CChoreoActorWidget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActorWidget::~CChoreoActorWidget(CChoreoActorWidget *this)
{
  int v2; // edi
  CChoreoChannelWidget *v3; // ecx
  CActorBitmapButton *m_btnOpen; // ecx
  CActorBitmapButton *m_btnClose; // ecx
  CChoreoChannelWidget **m_pMemory; // eax

  v2 = 0;
  for ( this->__vftable = (CChoreoActorWidget_vtbl *)&CChoreoActorWidget::`vftable'; v2 < this->m_Channels.m_Size; ++v2 )
  {
    v3 = this->m_Channels.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CChoreoChannelWidget *, int))v3->dtr_CChoreoWidget)(a1: v3, a2: 1);
  }
  this->m_Channels.m_Size = 0;
  m_btnOpen = this->m_btnOpen;
  if ( m_btnOpen != nullptr )
    ((void (__thiscall *)(CActorBitmapButton *, int))m_btnOpen->dtr_mxWidget)(a1: m_btnOpen, a2: 1);
  m_btnClose = this->m_btnClose;
  if ( m_btnClose != nullptr )
    ((void (__thiscall *)(CActorBitmapButton *, int))m_btnClose->dtr_mxWidget)(a1: m_btnClose, a2: 1);
  this->m_Channels.m_Size = 0;
  if ( this->m_Channels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Channels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Channels.m_Memory.m_pMemory);
      this->m_Channels.m_Memory.m_pMemory = nullptr;
    }
    this->m_Channels.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Channels.m_Memory.m_pMemory;
  this->m_Channels.m_pElements = m_pMemory;
  if ( this->m_Channels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Channels.m_Memory.m_pMemory = nullptr;
    }
    this->m_Channels.m_Memory.m_nAllocationCount = 0;
  }
  CChoreoWidget::~CChoreoWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0048D060
// Name: public: virtual void CChoreoActorWidget::Create(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoActorWidget::Create(CChoreoActorWidget *this)
{
  CChoreoActorWidget *v1; // esi
  int v2; // edi
  CChoreoChannel *Channel; // edi
  unsigned __int8 *v4; // eax
  NHC4::CMatchFinder *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoChannelWidget **m_pMemory; // ecx
  int v9; // eax
  CChoreoChannelWidget **v10; // ecx
  NHC4::CMatchFinder **v11; // edi
  int i; // [esp+8h] [ebp-8h]

  v1 = this;
  v2 = 0;
  for ( i = 0; i < CChoreoActor::GetNumChannels(this: v1->m_pActor); v2 = i )
  {
    Channel = CChoreoActor::GetChannel(this: v1->m_pActor, channel: v2);
    if ( Channel != nullptr )
    {
      v4 = CChoreoWidget::operator new(stAllocateBlock: 0x44u);
      if ( v4 != nullptr )
        v5 = (NHC4::CMatchFinder *)CChoreoChannelWidget::CChoreoChannelWidget(
                                     this: (CChoreoChannelWidget *)v4,
                                     parent: v1);
      else
        v5 = nullptr;
      NBT3::CMatchFinder::SetNumPasses(this: v5, numPasses: (unsigned int)Channel);
      ((void (__thiscall *)(NHC4::CMatchFinder *))v5->AddRef)(a1: v5);
      m_Size = v1->m_Channels.m_Size;
      m_nAllocationCount = v1->m_Channels.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_Channels,
          num: m_Size - m_nAllocationCount + 1);
      ++v1->m_Channels.m_Size;
      m_pMemory = v1->m_Channels.m_Memory.m_pMemory;
      v9 = v1->m_Channels.m_Size - m_Size - 1;
      v1->m_Channels.m_pElements = m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = v1->m_Channels.m_Memory.m_pMemory;
      v1 = this;
      v11 = (NHC4::CMatchFinder **)&v10[m_Size];
      if ( v11 != nullptr )
        *v11 = v5;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491970
// Name: public: class CChoreoActorWidget __near * CActorBitmapButton::GetActor(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CActorBitmapButton::GetActor(TimelineItem *this)
{
  return this->m_nNumSelected;
}
