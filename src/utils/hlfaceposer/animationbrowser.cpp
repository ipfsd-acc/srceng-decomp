// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/animationbrowser.cpp
// Functions: 45
// ============================================================

#include "utils\hlfaceposer\animationbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x004021D0
// Name: public: virtual bool IFacePoserToolWindow::IsScrubbing(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IFacePoserToolWindow::IsScrubbing(CP4File_Dummy *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x0041FAE0
// Name: public: void AnimationBrowser::Deselect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::Deselect(AnimationBrowser *this)
{
  void (*redraw)(void); // edx

  redraw = (void (*)(void))this->redraw;
  this->m_nCurCell = -1;
  redraw();
}

//------------------------------------------------------------------------------
// Address: 0x0041FB00
// Name: private: bool AnimationBrowser::ComputeRect(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall AnimationBrowser::ComputeRect(AnimationBrowser *this, int cell, int *rcx, int *rcy, int *rcw, int *rch)
{
  int v7; // eax
  int m_nGap; // ecx
  int m_nSnapshotWidth; // ebx
  int v10; // edi
  int v11; // edx
  int v12; // edi
  int v14; // ebx
  int cella; // [esp+14h] [ebp+8h]

  v7 = mxWidget::w2(this);
  m_nGap = this->m_nGap;
  m_nSnapshotWidth = this->m_nSnapshotWidth;
  v10 = (v7 - 16 - m_nGap) / (m_nGap + m_nSnapshotWidth);
  if ( v10 < 1 )
    v10 = 1;
  v11 = cell % v10;
  cella = cell / v10;
  *rcx = m_nGap + v11 * (m_nGap + m_nSnapshotWidth);
  v12 = this->m_nGap;
  *rcy = cella * (v12 + this->m_nSnapshotHeight)
       - this->m_nTopOffset * this->m_nGranularity
       + v12
       + this->GetCaptionHeight(this: &this->IFacePoserToolWindow)
       + 70;
  if ( *rcx < 0 )
    return 0;
  if ( this->m_nSnapshotWidth + this->m_nGap + *rcx > mxWidget::w2(this) )
    return 0;
  v14 = *rcy;
  if ( v14 > mxWidget::h2(this) || this->m_nSnapshotHeight + v14 + this->m_nGap < 0 )
    return 0;
  *rcw = this->m_nSnapshotWidth;
  *rch = this->m_nSnapshotHeight;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FBF0
// Name: private: void AnimationBrowser::SetClickedCell(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::SetClickedCell(AnimationBrowser *this, int cell)
{
  this->m_nClickedCell = cell;
  this->m_nCurCell = cell;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041FC10
// Name: private: void AnimationBrowser::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::DrawFocusRect(AnimationBrowser *this)
{
  HDC DC; // esi

  DC = GetDC(hWnd: nullptr);
  DrawFocusRect(hDC: DC, lprc: &this->m_rcFocus);
  ReleaseDC(hWnd: nullptr, hDC: DC);
}

//------------------------------------------------------------------------------
// Address: 0x0041FC40
// Name: float roundcycle(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl roundcycle(float cycle)
{
  return (float)(cycle - (float)(int)cycle);
}

//------------------------------------------------------------------------------
// Address: 0x0041FC70
// Name: public: void AnimationBrowser::ThumbnailIncrease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::ThumbnailIncrease(AnimationBrowser *this)
{
  int v2; // eax
  int m_nSnapshotWidth; // eax

  v2 = this->m_nSnapshotWidth + 4;
  if ( v2 <= 256 )
  {
    this->m_nSnapshotWidth = v2;
    g_viewerSettings.thumbnailsizeanim = v2;
    m_nSnapshotWidth = this->m_nSnapshotWidth;
    this->m_nSnapshotHeight = m_nSnapshotWidth + this->m_nDescriptionHeight;
    Con_Printf(fmt: "Thumbnail size %i x %i\n", m_nSnapshotWidth, m_nSnapshotWidth);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FCC0
// Name: public: void AnimationBrowser::ThumbnailDecrease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::ThumbnailDecrease(AnimationBrowser *this)
{
  int v2; // eax
  int m_nSnapshotWidth; // eax

  v2 = this->m_nSnapshotWidth - 4;
  if ( v2 >= 64 )
  {
    this->m_nSnapshotWidth = v2;
    g_viewerSettings.thumbnailsizeanim = v2;
    m_nSnapshotWidth = this->m_nSnapshotWidth;
    this->m_nSnapshotHeight = m_nSnapshotWidth + this->m_nDescriptionHeight;
    Con_Printf(fmt: "Thumbnail size %i x %i\n", m_nSnapshotWidth, m_nSnapshotWidth);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FD10
// Name: public: void AnimationBrowser::RestoreThumbnailSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::RestoreThumbnailSize(AnimationBrowser *this)
{
  int thumbnailsizeanim; // eax
  AnimationBrowser_vtbl *v2; // eax

  thumbnailsizeanim = g_viewerSettings.thumbnailsizeanim;
  this->m_nSnapshotWidth = g_viewerSettings.thumbnailsizeanim;
  if ( thumbnailsizeanim < 64 )
    thumbnailsizeanim = 64;
  this->m_nSnapshotWidth = thumbnailsizeanim;
  if ( thumbnailsizeanim > 256 )
    thumbnailsizeanim = 256;
  this->m_nSnapshotWidth = thumbnailsizeanim;
  g_viewerSettings.thumbnailsizeanim = thumbnailsizeanim;
  v2 = this->mxWindow::mxWidget::__vftable;
  this->m_nSnapshotHeight = this->m_nSnapshotWidth + this->m_nDescriptionHeight;
  ((void (*)(void))v2->redraw)();
}

//------------------------------------------------------------------------------
// Address: 0x0041FD60
// Name: IsTypeOfSequence
// Source: json
//------------------------------------------------------------------------------
char __usercall IsTypeOfSequence@<al>(StudioModel *model@<esi>, int sequence, const char *typestring)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  char *m_pModelName; // ebx
  const char *KeyValueText; // eax
  KeyValues *Key; // eax
  const char *String; // eax
  char v12; // bl

  m_pStudioHdr = model->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->m_MDLHandle);
    CStudioHdr::Init(this: model->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = model->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: defaultValue);
  else
    v7 = nullptr;
  m_pModelName = model->m_pModelName;
  KeyValueText = StudioModel::GetKeyValueText(this: model, iSequence: sequence);
  if ( !KeyValues::LoadFromBuffer(
          this: v7,
          resourceName: m_pModelName,
          pBuffer: KeyValueText,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr)
    || (Key = KeyValues::FindKey(this: v7, keyName: "faceposer", bCreate: false)) == nullptr
    || (String = KeyValues::GetString(this: Key, keyName: "type", defaultValue: defaultValue)) == nullptr
    || (v12 = 1, _V_stricmp(s1: String, s2: typestring) != 0) )
  {
    v12 = 0;
  }
  KeyValues::deleteThis(this: v7);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0041FE40
// Name: public: char const __near * CStudioHdr::name(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStudioHdr::name(CStudioHdr *this)
{
  const studiohdr_t *m_pStudioHdr; // edx
  int studiohdr2index; // eax
  int v3; // ecx
  char *v4; // eax
  int v5; // ecx

  m_pStudioHdr = this->m_pStudioHdr;
  studiohdr2index = this->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index == 0 )
    return m_pStudioHdr->name;
  v3 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8];
  v4 = (char *)m_pStudioHdr + studiohdr2index;
  if ( v3 == 0 || &v4[v3] == nullptr )
    return m_pStudioHdr->name;
  v5 = *((_DWORD *)v4 + 5);
  if ( v5 != 0 )
    return &v4[v5];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041FE70
// Name: class Color RGBToColor(unsigned long const __near &)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl RGBToColor(Color *result, const unsigned int *clr)
{
  unsigned __int8 v3; // cl

  result->_color[0] = *(_BYTE *)clr;
  v3 = *((_BYTE *)clr + 2);
  result->_color[1] = *((_BYTE *)clr + 1);
  result->_color[2] = v3;
  result->_color[3] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FEA0
// Name: private: void AnimationBrowser::DrawSequenceDescription(class CChoreoWidgetDrawHelper __near &,int,int,int,int,int,struct mstudioseqdesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::DrawSequenceDescription(
        AnimationBrowser *this,
        CChoreoWidgetDrawHelper *helper,
        int x,
        int y,
        int w,
        int h,
        int sequence,
        mstudioseqdesc_t *seqdesc)
{
  StudioModel *v8; // esi
  int v9; // ebx
  double Duration; // st7
  int NumFrames; // eax
  double FPS; // st7
  const char *v13; // [esp+4h] [ebp-20h]
  tagRECT textRect; // [esp+14h] [ebp-10h] BYREF

  textRect.left = x + 5;
  textRect.top = y + h - 42;
  textRect.right = x + w - 10;
  v13 = (char *)seqdesc + seqdesc->szlabelindex;
  textRect.bottom = y + h - 12;
  x = 4144959;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: helper,
    font: "Arial",
    pointsize: 9,
    weight: 400,
    clr: (const Color *)&x,
    rcText: &textRect,
    fmt: "%s",
    v13);
  v8 = models->GetActiveStudioModel(this: models);
  if ( v8 != nullptr )
  {
    OffsetRect(lprc: &textRect, dx: 0, dy: 15);
    x = 4144959;
    v9 = sequence;
    Duration = StudioModel::GetDuration(this: v8, iSequence: sequence);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: helper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&x,
      rcText: &textRect,
      fmt: "%.2f seconds",
      Duration);
    textRect.top = y + h - 61;
    textRect.bottom = textRect.top + 15;
    y = 16762930;
    NumFrames = StudioModel::GetNumFrames(this: v8, iSequence: v9);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: helper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&y,
      rcText: &textRect,
      fmt: "frames %i",
      NumFrames);
    OffsetRect(lprc: &textRect, dx: 0, dy: 11);
    y = 16762930;
    FPS = StudioModel::GetFPS(this: v8, iSequence: v9);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: helper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&y,
      rcText: &textRect,
      fmt: "fps %.2f",
      FPS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420000
// Name: private: int AnimationBrowser::ComputePixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall AnimationBrowser::ComputePixelsNeeded(AnimationBrowser *this)
{
  int v3; // edi
  int m_nGap; // ebx
  int seqcount; // [esp+4h] [ebp-4h]

  seqcount = this->m_Filtered.m_Size;
  if ( seqcount == 0 )
    return 100;
  v3 = (mxWidget::w2(this) - 16 - this->m_nGap) / (this->m_nGap + this->m_nSnapshotWidth);
  if ( v3 < 1 )
    v3 = 1;
  m_nGap = this->m_nGap;
  return (m_nGap + this->m_nSnapshotHeight) * ((v3 + seqcount - 1) / v3)
       + m_nGap
       + this->GetCaptionHeight(this: &this->IFacePoserToolWindow)
       + 70;
}

//------------------------------------------------------------------------------
// Address: 0x00420080
// Name: private: int AnimationBrowser::GetCellUnderPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall AnimationBrowser::GetCellUnderPosition(AnimationBrowser *this, int x, int y)
{
  int m_Size; // eax
  int v6; // eax
  int m_nGap; // ecx
  int m_nSnapshotWidth; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // ebx
  int m_nSnapshotHeight; // ecx
  int count; // [esp+4h] [ebp-Ch]
  int c; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Filtered.m_Size;
  count = m_Size;
  if ( m_Size == 0 )
    return -1;
  c = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v6 = mxWidget::w2(this);
    m_nGap = this->m_nGap;
    m_nSnapshotWidth = this->m_nSnapshotWidth;
    v9 = (v6 - 16 - m_nGap) / (m_nGap + m_nSnapshotWidth);
    if ( v9 < 1 )
      v9 = 1;
    v10 = c / v9;
    v11 = c % v9;
    v12 = m_nGap + m_nSnapshotWidth;
    v13 = this->m_nGap;
    v14 = m_nGap + v11 * v12;
    v15 = v10 * (v13 + this->m_nSnapshotHeight)
        - this->m_nGranularity * this->m_nTopOffset
        + v13
        + this->GetCaptionHeight(this: &this->IFacePoserToolWindow)
        + 70;
    if ( v14 >= 0 && v14 + this->m_nSnapshotWidth + this->m_nGap <= mxWidget::w2(this) && v15 <= mxWidget::h2(this) )
    {
      m_nSnapshotHeight = this->m_nSnapshotHeight;
      if ( v15 + m_nSnapshotHeight + this->m_nGap >= 0
        && x >= v14
        && x <= this->m_nSnapshotWidth + v14
        && y >= v15
        && y <= m_nSnapshotHeight + v15 )
      {
        break;
      }
    }
    if ( ++c >= count )
      return -1;
  }
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004201A0
// Name: private: void AnimationBrowser::RepositionSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::RepositionSlider(AnimationBrowser *this)
{
  int v2; // ebx
  int v3; // eax
  mxScrollbar *slScrollbar; // ecx
  int v5; // eax
  int v6; // eax
  mxScrollbar *v7; // ecx
  int v8; // [esp-Ch] [ebp-20h]
  int rangepixels; // [esp+Ch] [ebp-8h]
  int heightpixelsa; // [esp+10h] [ebp-4h]
  int heightpixels; // [esp+10h] [ebp-4h]

  heightpixelsa = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  v2 = mxWidget::h2(this) - heightpixelsa;
  heightpixels = v2 / this->m_nGranularity;
  v3 = AnimationBrowser::ComputePixelsNeeded(this);
  slScrollbar = this->slScrollbar;
  rangepixels = v3 / this->m_nGranularity;
  if ( rangepixels >= heightpixels )
  {
    mxWidget::setVisible(this: slScrollbar, b: true);
  }
  else
  {
    this->m_nTopOffset = 0;
    mxWidget::setVisible(this: slScrollbar, b: false);
  }
  v8 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 70;
  v5 = mxWidget::w2(this);
  mxWidget::setBounds(this: this->slScrollbar, x: v5 - 16, y: v8, w: 16, h: v2 - 70);
  v6 = this->m_nTopOffset < 0 ? 0 : this->m_nTopOffset;
  this->m_nTopOffset = v6;
  if ( rangepixels < v6 )
    v6 = rangepixels;
  v7 = this->slScrollbar;
  this->m_nTopOffset = v6;
  mxScrollbar::setRange(this: v7, min: 0, max: rangepixels);
  mxScrollbar::setValue(this: this->slScrollbar, ivalue: this->m_nTopOffset);
  mxScrollbar::setPagesize(this: this->slScrollbar, size: heightpixels);
}

//------------------------------------------------------------------------------
// Address: 0x00420290
// Name: private: int AnimationBrowser::TranslateSequenceNumber(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall AnimationBrowser::TranslateSequenceNumber(AnimationBrowser *this, int index)
{
  if ( index < 0 || index >= this->m_Filtered.m_Size )
    return 0;
  else
    return this->m_Filtered.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x004202C0
// Name: private: int AnimationBrowser::FindCustomFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall AnimationBrowser::FindCustomFile(AnimationBrowser *this, const char *shortName)
{
  int m_Size; // edx
  int result; // eax
  CCustomAnim **i; // ecx

  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&shortName + 1, pStr: shortName);
  m_Size = this->m_CustomAnimationTabs.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_CustomAnimationTabs.m_Memory.m_pMemory; (*i)->m_ShortName.m_Id != HIWORD(shortName); ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420310
// Name: public: bool CCustomAnim::HasAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCustomAnim::HasAnimation(CCustomAnim *this, const char *search)
{
  int m_Size; // edx
  int v4; // eax
  CUtlSymbol *i; // ecx

  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&search + 1, pStr: search);
  m_Size = this->m_Animations.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Animations.m_Memory.m_pMemory; i->m_Id != HIWORD(search); ++i )
  {
    if ( ++v4 >= m_Size )
      return false;
  }
  return v4 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x00420360
// Name: public: virtual void AnimationBrowser::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::Think(AnimationBrowser *this, float dt)
{
  StudioModel *v3; // esi
  int m_nLastNumAnimations; // eax
  int v5; // edi
  float v6; // xmm0_4
  int NewAnimationLayer; // ebx
  float elapsed; // [esp+14h] [ebp-Ch]
  float elapseda; // [esp+14h] [ebp-Ch]
  float flGroundSpeed; // [esp+18h] [ebp-8h] BYREF
  float flFrameRate; // [esp+1Ch] [ebp-4h] BYREF

  if ( LOBYTE(this->m_nDescriptionHeight) != 0 && this->m_nLastNumAnimations >= 0 )
  {
    v3 = models->GetActiveStudioModel(this: models);
    if ( v3 != nullptr )
    {
      m_nLastNumAnimations = this->m_nLastNumAnimations;
      if ( m_nLastNumAnimations < 0 || m_nLastNumAnimations >= (int)this->m_Filtered.m_Memory.m_pMemory )
        v5 = 0;
      else
        v5 = *(_DWORD *)(this->m_nYStart + 4 * m_nLastNumAnimations);
      if ( StudioModel::GetDuration(this: v3, iSequence: v5) > 0.0 )
      {
        v6 = realtime;
        elapsed = v6 - *(float *)&this->m_szSearchString[244];
        flFrameRate = 0.0;
        flGroundSpeed = 0.0;
        StudioModel::GetSequenceInfo(
          this: v3,
          iSequence: v5,
          pflFrameRate: &flFrameRate,
          pflGroundSpeed: &flGroundSpeed);
        elapseda = roundcycle(cycle: flFrameRate * elapsed);
        StudioModel::ClearAnimationLayers(this: v3);
        NewAnimationLayer = StudioModel::GetNewAnimationLayer(this: v3, iPriority: 0);
        StudioModel::SetOverlaySequence(this: v3, iLayer: NewAnimationLayer, iSequence: v5, flWeight: 1.0);
        StudioModel::SetOverlayRate(this: v3, iLayer: NewAnimationLayer, flCycle: elapseda, flPlaybackRate: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420480
// Name: private: bool AnimationBrowser::SequencePassesFilter(class StudioModel __near *,int,struct mstudioseqdesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall AnimationBrowser::SequencePassesFilter(
        AnimationBrowser *this,
        StudioModel *model,
        int sequence,
        mstudioseqdesc_t *seqdesc)
{
  int m_nCurFilter; // eax
  char v6; // al
  bool result; // al
  int v8; // eax

  if ( StudioModel::IsHidden(this: model, iSequence: sequence) )
    return false;
  m_nCurFilter = this->m_nCurFilter;
  switch ( m_nCurFilter )
  {
    case 0:
      goto $LN8_4;
    case 1:
      v6 = IsTypeOfSequence(model, sequence, typestring: "gesture");
      goto LABEL_4;
    case 2:
      v6 = IsTypeOfSequence(model, sequence, typestring: "posture");
LABEL_4:
      if ( v6 != 0 )
        goto $LN8_4;
      return false;
    case 3:
      if ( V_stristr(pStr: (char *)seqdesc + seqdesc->szlabelindex, pSearch: this->m_szSearchString) == nullptr )
        return false;
      goto $LN8_4;
    default:
      v8 = m_nCurFilter - 4;
      if ( v8 < 0 || v8 >= this->m_CustomAnimationTabs.m_Size )
$LN8_4:
        result = true;
      else
        result = CCustomAnim::HasAnimation(
                   this: this->m_CustomAnimationTabs.m_Memory.m_pMemory[v8],
                   search: (const char *)seqdesc + seqdesc->szlabelindex);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420530
// Name: private: struct mstudioseqdesc_t __near * AnimationBrowser::GetSeqDesc(int)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall AnimationBrowser::GetSeqDesc(AnimationBrowser *this, int index)
{
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  int v7; // esi
  int NumSeq_Internal; // eax
  const studiohdr_t *v9; // edi
  int v10; // eax

  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return nullptr;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = v3->m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
      return nullptr;
    m_pStudioHdr = v6;
  }
  if ( m_pStudioHdr == nullptr )
    return nullptr;
  if ( index >= 0 && index < this->m_Filtered.m_Size )
  {
    v7 = this->m_Filtered.m_Memory.m_pMemory[index];
    if ( v7 >= 0 )
      goto LABEL_9;
    return nullptr;
  }
  v7 = 0;
LABEL_9:
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( v7 >= NumSeq_Internal )
    return nullptr;
  if ( m_pStudioHdr->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: v7);
  v9 = m_pStudioHdr->m_pStudioHdr;
  v10 = v7;
  if ( v7 >= v9->numlocalseq )
    v10 = 0;
  return (mstudioseqdesc_t *)((char *)v9 + 212 * v10 + v9->localseqindex);
}

//------------------------------------------------------------------------------
// Address: 0x00420610
// Name: public: void CCustomAnim::SaveToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomAnim::SaveToFile(CCustomAnim *this)
{
  const char *v2; // eax
  int v3; // eax
  int v4; // esi
  const char *v5; // eax
  char fn[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+204h] [ebp-30h] BYREF

  if ( filesystem->String(this: filesystem, a2: &this->m_Handle, a3: fn, a4: 512) )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    v2 = CUtlSymbol::String(this: &this->m_ShortName);
    CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\n", v2);
    CUtlBuffer::Printf(this: &buf, pFmt: "{\n");
    v3 = 0;
    if ( this->m_Animations.m_Size > 0 )
    {
      do
      {
        v4 = v3 + 1;
        v5 = CUtlSymbol::String(this: &this->m_Animations.m_Memory.m_pMemory[v3]);
        CUtlBuffer::Printf(this: &buf, pFmt: "\t\"item%d\" \"%s\"\n", v4, v5);
        v3 = v4;
      }
      while ( v4 < this->m_Animations.m_Size );
    }
    CUtlBuffer::Printf(this: &buf, pFmt: "}\n");
    CreatePath(relative: fn);
    filesystem->WriteFile(this: &filesystem->IBaseFileSystem, a2: fn, a3: "MOD", a4: &buf);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420710
// Name: private: void AnimationBrowser::DrawThumbNail(int,class CChoreoWidgetDrawHelper __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::DrawThumbNail(
        AnimationBrowser *this,
        int sequence,
        CChoreoWidgetDrawHelper *helper,
        int rcx,
        mstudioseqdesc_t *rcy,
        int rcw,
        int rch)
{
  DWORD SysColor; // eax
  int v9; // ebx
  mstudioseqdesc_t *v10; // edi
  int v11; // edx
  int v12; // eax
  mxbitmapdata_t *v13; // eax
  char *v14; // ecx
  int v15; // eax
  char *v16; // ecx
  HDC__ *dc; // [esp+Ch] [ebp-Ch]
  int x2; // [esp+10h] [ebp-8h]
  Color clr; // [esp+14h] [ebp-4h] BYREF

  dc = (HDC__ *)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)helper);
  SysColor = GetSysColor(nIndex: 15);
  v9 = rcx;
  v10 = rcy;
  *(_WORD *)clr._color = SysColor;
  clr._color[2] = BYTE2(SysColor);
  x2 = rcx + rcw;
  clr._color[3] = 0;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: helper, &clr, x1: rcx, y1: (int)rcy, x2: rcx + rcw, y2: (int)rcy + rch);
  rcy = AnimationBrowser::GetSeqDesc(this, index: sequence);
  if ( rcy != nullptr )
  {
    if ( sequence < 0 || sequence >= this->m_Filtered.m_Size )
      v11 = 0;
    else
      v11 = this->m_Filtered.m_Memory.m_pMemory[sequence];
    rcx = (int)models->__vftable;
    v12 = (*(int (__thiscall **)(IFaceposerModels *, int))(rcx + 16))(a1: models, a2: v11);
    v13 = (mxbitmapdata_t *)(*(int (__thiscall **)(IFaceposerModels *, int))(rcx + 116))(a1: models, a2: v12);
    if ( v13 != nullptr && v13->valid )
    {
      DrawBitmapToDC(hdc: dc, x: v9, y: (int)v10, w: rcw, h: rch - this->m_nDescriptionHeight, bitmap: v13);
      v14 = (char *)v10 - this->m_nDescriptionHeight;
      rcx = 8355711;
      CChoreoWidgetDrawHelper::DrawOutlinedRect(
        this: helper,
        clr: (const Color *)&rcx,
        style: 0,
        width: 1,
        x1: v9,
        y1: (int)v10,
        x2,
        y2: (int)&v14[rch]);
    }
    if ( sequence < 0 || sequence >= this->m_Filtered.m_Size )
      v15 = 0;
    else
      v15 = this->m_Filtered.m_Memory.m_pMemory[sequence];
    AnimationBrowser::DrawSequenceDescription(
      this,
      helper,
      x: v9,
      y: (int)v10,
      w: rcw,
      h: rch,
      sequence: v15,
      seqdesc: rcy);
    if ( sequence == this->m_nCurCell )
    {
      v16 = (char *)v10 - this->m_nDescriptionHeight;
      sequence = 4154623;
      CChoreoWidgetDrawHelper::DrawOutlinedRect(
        this: helper,
        clr: (const Color *)&sequence,
        style: 0,
        width: 4,
        x1: v9,
        y1: (int)v10,
        x2,
        y2: (int)&v16[rch]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420880
// Name: public: virtual void AnimationBrowser::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::redraw(AnimationBrowser *this)
{
  int m_Size; // ebx
  DWORD SysColor; // eax
  int v4; // eax
  int i; // edi
  CChoreoWidgetDrawHelper helper; // [esp+8h] [ebp-88h] BYREF
  tagRECT clipRect; // [esp+60h] [ebp-30h] BYREF
  tagRECT rcText; // [esp+70h] [ebp-20h] BYREF
  int rcw; // [esp+80h] [ebp-10h] BYREF
  int rcy; // [esp+84h] [ebp-Ch] BYREF
  int rcx; // [esp+88h] [ebp-8h] BYREF
  int rch; // [esp+8Ch] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) )
  {
    m_Size = this->m_Filtered.m_Size;
    if ( m_Size != this->m_nLastNumAnimations )
    {
      this->m_nTopOffset = 0;
      AnimationBrowser::RepositionSlider(this);
      this->m_nLastNumAnimations = m_Size;
    }
    SysColor = GetSysColor(nIndex: 15);
    LOWORD(rch) = SysColor;
    HIWORD(rch) = BYTE2(SysColor);
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &helper, widget: this, bgColor: (const Color *)&rch);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &helper);
    mxWidget::w2(this);
    mxWidget::h2(this);
    CChoreoWidgetDrawHelper::GetClientRect(this: &helper, rc: &clipRect);
    v4 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
    clipRect.top += v4 + 70;
    CChoreoWidgetDrawHelper::StartClipping(this: &helper, &clipRect);
    EnableStickySnapshotMode();
    for ( i = 0; i < m_Size; ++i )
    {
      if ( AnimationBrowser::ComputeRect(this, cell: i, &rcx, &rcy, &rcw, &rch) != 0 )
        AnimationBrowser::DrawThumbNail(this, sequence: i, &helper, rcx, (mstudioseqdesc_t *)rcy, rcw, rch);
    }
    DisableStickySnapshotMode();
    CChoreoWidgetDrawHelper::StopClipping(this: &helper);
    rcText.right = mxWidget::w2(this);
    rcText.left = rcText.right - 120;
    rcText.top = 8;
    rcText.bottom = 23;
    rch = 4144959;
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: &helper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: (const Color *)&rch,
      &rcText,
      fmt: "%i sequences",
      m_Size);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &helper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420A00
// Name: private: void AnimationBrowser::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::ShowRightClickMenu(AnimationBrowser *this, int mx, int my)
{
  mxPopupMenu *v4; // ebx
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // esi
  const char *v7; // eax
  mxPopupMenu *v8; // eax
  int j; // esi
  const char *v10; // eax
  const char *v11; // eax
  mxPopupMenu *v12; // eax
  mxPopupMenu *v13; // eax
  int v14; // edx
  CCustomAnim *v15; // esi
  int m_Size; // ecx
  int v17; // eax
  CUtlSymbol *m_pMemory; // edx
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  mstudioseqdesc_t *pseqdesc; // [esp+8h] [ebp-14h]
  int i; // [esp+Ch] [ebp-10h]
  mxPopupMenu *ca; // [esp+10h] [ebp-Ch]
  mxPopupMenu *pop; // [esp+14h] [ebp-8h]
  CUtlSymbol v27; // [esp+18h] [ebp-4h] BYREF
  bool useMenu; // [esp+1Bh] [ebp-1h]

  v4 = nullptr;
  pseqdesc = AnimationBrowser::GetSeqDesc(this, index: this->m_nCurCell);
  if ( pseqdesc != nullptr )
  {
    v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v5 != nullptr )
    {
      v6 = mxPopupMenu::mxPopupMenu(this: v5);
      pop = v6;
    }
    else
    {
      pop = nullptr;
      v6 = nullptr;
    }
    v7 = va(fmt: "New Group...");
    mxPopupMenu::add(this: v6, item: v7, id: 1007);
    if ( this->m_CustomAnimationTabs.m_Size > 0 )
    {
      v8 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v8 != nullptr )
        v4 = mxPopupMenu::mxPopupMenu(this: v8);
      for ( j = 0; j < this->m_CustomAnimationTabs.m_Size; ++j )
      {
        v10 = CUtlSymbol::String(this: &this->m_CustomAnimationTabs.m_Memory.m_pMemory[j]->m_ShortName);
        v11 = va(fmt: "%s", v10);
        mxPopupMenu::add(this: v4, item: v11, id: j + 1100);
      }
      mxMenu::addMenu(this: pop, item: "Add to Group", menu: v4);
      v12 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v12 != nullptr )
        v13 = mxPopupMenu::mxPopupMenu(this: v12);
      else
        v13 = nullptr;
      v14 = 0;
      ca = v13;
      useMenu = false;
      i = 0;
      if ( this->m_CustomAnimationTabs.m_Size <= 0 )
        goto LABEL_24;
      do
      {
        v15 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[v14];
        CUtlSymbol::CUtlSymbol(this: &v27, pStr: (const char *)pseqdesc + pseqdesc->szlabelindex);
        m_Size = v15->m_Animations.m_Size;
        v17 = 0;
        if ( m_Size > 0 )
        {
          m_pMemory = v15->m_Animations.m_Memory.m_pMemory;
          while ( m_pMemory->m_Id != v27.m_Id )
          {
            ++v17;
            ++m_pMemory;
            if ( v17 >= m_Size )
              goto LABEL_21;
          }
          if ( v17 != -1 )
          {
            v19 = CUtlSymbol::String(this: &v15->m_ShortName);
            v20 = va(fmt: "%s", v19);
            mxPopupMenu::add(this: ca, item: v20, id: i + 1200);
            useMenu = true;
          }
        }
LABEL_21:
        v14 = i + 1;
        i = v14;
      }
      while ( v14 < this->m_CustomAnimationTabs.m_Size );
      v13 = ca;
      if ( useMenu )
      {
        mxMenu::addMenu(this: pop, item: "Remove from Group", menu: ca);
      }
      else
      {
LABEL_24:
        if ( v13 != nullptr )
          ((void (__thiscall *)(mxPopupMenu *, int))v13->dtr_mxWidget)(a1: v13, a2: 1);
      }
      v6 = pop;
    }
    mxMenu::addSeparator(this: v6);
    v21 = va(fmt: "Re-create thumbnail for '%s'", (const char *)pseqdesc + pseqdesc->szlabelindex);
    mxPopupMenu::add(this: v6, item: v21, id: 1004);
    v22 = va(fmt: "Re-create all thumbnails");
    mxPopupMenu::add(this: v6, item: v22, id: 1005);
    mxPopupMenu::popup(this: v6, widget: this, x: mx, y: my);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420C20
// Name: public: void CCustomAnim::LoadFromFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomAnim::LoadFromFile(CCustomAnim *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // ebx
  const char *String; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v10; // eax
  CUtlSymbol *v11; // eax
  char fn[514]; // [esp+4h] [ebp-208h] BYREF
  CUtlSymbol v13; // [esp+206h] [ebp-6h] BYREF
  KeyValues *kv; // [esp+208h] [ebp-4h]

  if ( filesystem->String(this: filesystem, a2: &this->m_Handle, a3: fn, a4: 512) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "CustomAnimation");
      kv = v3;
    }
    else
    {
      kv = nullptr;
      v3 = nullptr;
    }
    if ( filesystem != nullptr )
      v4 = &filesystem->IBaseFileSystem;
    else
      v4 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v3,
           filesystem: v4,
           resourceName: fn,
           pathID: "MOD",
           pfnEvaluateSymbolProc: nullptr) )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
          CUtlSymbol::CUtlSymbol(this: &v13, pStr: String);
          m_Size = this->m_Animations.m_Size;
          m_nAllocationCount = this->m_Animations.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CUtlSymbol,int>::Grow(
              this: (CUtlMemory<short,int> *)&this->m_Animations,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_Animations.m_Size;
          m_pMemory = this->m_Animations.m_Memory.m_pMemory;
          v10 = this->m_Animations.m_Size - m_Size - 1;
          this->m_Animations.m_pElements = m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v10);
          v11 = &this->m_Animations.m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            v11->m_Id = v13.m_Id;
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v3 = kv;
      }
    }
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420D50
// Name: public: virtual void CAnimBrowserTab::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimBrowserTab::ShowRightClickMenu(CAnimBrowserTab *this, int mx, int my)
{
  HWND Handle; // eax
  mxPopupMenu *v5; // eax
  int v6; // edi
  mxPopupMenu *v7; // ebx
  mxPopupMenu *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  mxPopupMenu *v11; // eax
  mxPopupMenu *v12; // ebx
  int i; // edi
  const char *v14; // eax
  const char *v15; // eax
  mxPopupMenu *v16; // edi
  mxWindow *Parent; // eax
  tagPOINT pt; // [esp+Ch] [ebp-Ch] BYREF
  mxPopupMenu *pop; // [esp+14h] [ebp-4h]
  tagPOINT v20; // 0:^4.8

  GetCursorPos(lpPoint: &pt);
  Handle = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
  v6 = 0;
  if ( v5 != nullptr )
    pop = mxPopupMenu::mxPopupMenu(this: v5);
  else
    pop = nullptr;
  mxPopupMenu::add(this: pop, item: "&New Group...", id: 1007);
  v7 = nullptr;
  if ( this->m_CustomGroups.m_Size > 0 )
  {
    do
    {
      if ( v7 == nullptr )
      {
        v8 = (mxPopupMenu *)operator new(nSize: 0xCu);
        if ( v8 != nullptr )
          v7 = mxPopupMenu::mxPopupMenu(this: v8);
        else
          v7 = nullptr;
      }
      v9 = CUtlSymbol::String(this: &this->m_CustomGroups.m_Memory.m_pMemory[v6]);
      v10 = va(fmt: "%s", v9);
      mxPopupMenu::add(this: v7, item: v10, id: v6 + 1300);
      ++v6;
    }
    while ( v6 < this->m_CustomGroups.m_Size );
    if ( v7 != nullptr )
      mxMenu::addMenu(this: pop, item: "Delete Group", menu: v7);
  }
  mxMenu::addSeparator(this: pop);
  v11 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxPopupMenu::mxPopupMenu(this: v11);
  else
    v12 = nullptr;
  for ( i = 0; i < this->m_CustomGroups.m_Size; ++i )
  {
    v14 = CUtlSymbol::String(this: &this->m_CustomGroups.m_Memory.m_pMemory[i]);
    v15 = va(fmt: "%s", v14);
    mxPopupMenu::add(this: v12, item: v15, id: i + 1400);
  }
  v16 = pop;
  mxMenu::addMenu(this: pop, item: "Rename Group", menu: v12);
  v20 = pt;
  Parent = mxWidget::getParent(this);
  mxPopupMenu::popup(this: v16, widget: Parent, x: v20.x, y: v20.y);
}

//------------------------------------------------------------------------------
// Address: 0x00420EA0
// Name: public: void CAnimBrowserTab::UpdateCustomTabs(class CUtlVector<class CCustomAnim __near *,class CUtlMemory<class CCustomAnim __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimBrowserTab::UpdateCustomTabs(
        CAnimBrowserTab *this,
        CUtlVector<CCustomAnim *,CUtlMemory<CCustomAnim *,int> > *list)
{
  CAnimBrowserTab_vtbl *v3; // edi
  int v4; // eax
  CAnimBrowserTab_vtbl *v5; // edi
  const char *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v10; // eax
  CUtlSymbol *v11; // edi
  CUtlSymbol *p_m_ShortName; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  this->m_CustomGroups.m_Size = 0;
  if ( this->m_CustomGroups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CustomGroups.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CustomGroups.m_Memory.m_pMemory);
      this->m_CustomGroups.m_Memory.m_pMemory = nullptr;
    }
    this->m_CustomGroups.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CustomGroups.m_pElements = this->m_CustomGroups.m_Memory.m_pMemory;
  while ( this->getItemCount(this) > 4 )
  {
    v3 = this->__vftable;
    v4 = this->getItemCount(this);
    v3->remove(this, a2: v4 - 1);
  }
  for ( i = 0; i < list->m_Size; ++i )
  {
    v5 = this->__vftable;
    p_m_ShortName = &list->m_Memory.m_pMemory[i]->m_ShortName;
    v6 = CUtlSymbol::String(this: p_m_ShortName);
    v5->add(this, a2: v6);
    m_Size = this->m_CustomGroups.m_Size;
    m_nAllocationCount = this->m_CustomGroups.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlSymbol,int>::Grow(
        this: (CUtlMemory<short,int> *)&this->m_CustomGroups,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_CustomGroups.m_Size;
    m_pMemory = this->m_CustomGroups.m_Memory.m_pMemory;
    v10 = this->m_CustomGroups.m_Size - m_Size - 1;
    this->m_CustomGroups.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v10);
    v11 = &this->m_CustomGroups.m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      v11->m_Id = p_m_ShortName->m_Id;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420FD0
// Name: private: void AnimationBrowser::OnFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::OnFilter(AnimationBrowser *this)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Filtered; // esi
  int v2; // ebx
  StudioModel *v3; // eax
  StudioModel *v4; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  CStudioHdr *v7; // edi
  const studiohdr_t *v8; // ecx
  int v9; // eax
  mstudioseqdesc_t *v10; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  int *v15; // edi
  StudioModel *model; // [esp+Ch] [ebp-10h]
  int count; // [esp+14h] [ebp-8h]
  CStudioHdr *hdr; // [esp+18h] [ebp-4h]

  p_m_Filtered = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Filtered;
  v2 = 0;
  this->m_Filtered.m_Size = 0;
  v3 = models->GetActiveStudioModel(this: models);
  v4 = v3;
  model = v3;
  if ( v3 != nullptr )
  {
    m_pStudioHdr = v3->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      hdr = v4->m_pStudioHdr;
      v7 = m_pStudioHdr;
    }
    else
    {
      v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v4->m_MDLHandle);
      CStudioHdr::Init(this: v4->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
      v7 = v4->m_pStudioHdr;
      if ( v7->m_pStudioHdr == nullptr )
        return;
      hdr = v7;
    }
    if ( v7 != nullptr )
    {
      if ( v7->m_pVModel != nullptr )
        count = CStudioHdr::GetNumSeq_Internal(this: v7);
      else
        count = v7->m_pStudioHdr->numlocalseq;
      if ( count > 0 )
      {
        do
        {
          if ( v7->m_pVModel != nullptr )
          {
            v10 = CStudioHdr::pSeqdesc_Internal(this: v7, i: v2);
          }
          else
          {
            v8 = v7->m_pStudioHdr;
            v9 = v2;
            if ( v2 < 0 || v2 >= v8->numlocalseq )
              v9 = 0;
            v10 = (mstudioseqdesc_t *)((char *)v8 + 212 * v9 + v8->localseqindex);
          }
          if ( AnimationBrowser::SequencePassesFilter(this, model, sequence: v2, seqdesc: v10) )
          {
            m_pMemory = p_m_Filtered[1].m_pMemory;
            m_nAllocationCount = p_m_Filtered->m_nAllocationCount;
            if ( (int)m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                this: p_m_Filtered,
                num: (int)m_pMemory - m_nAllocationCount + 1);
            ++p_m_Filtered[1].m_pMemory;
            v13 = p_m_Filtered->m_pMemory;
            v14 = (char *)p_m_Filtered[1].m_pMemory - (char *)m_pMemory - 1;
            p_m_Filtered[1].m_nAllocationCount = (int)p_m_Filtered->m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
            v15 = (int *)&p_m_Filtered->m_pMemory[(_DWORD)m_pMemory];
            if ( v15 != nullptr )
              *v15 = v2;
            v7 = hdr;
          }
          ++v2;
        }
        while ( v2 < count );
      }
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421120
// Name: private: void AnimationBrowser::FindCustomFiles(char const __near *,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge AnimationBrowser::FindCustomFiles(
        AnimationBrowser *this@<ecx>,
        int a2@<esi>,
        const char *subdir,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *files)
{
  const char *i; // edi
  void *v5; // eax
  int m_pMemory; // edi
  void *v7; // ebx
  int m_nAllocationCount; // eax
  void **v9; // ecx
  int v10; // eax
  void **v11; // eax
  char fn[512]; // [esp+4h] [ebp-404h] BYREF
  char search[512]; // [esp+204h] [ebp-204h] BYREF
  int findHandle; // [esp+404h] [ebp-4h] BYREF

  V_snprintf(pDest: search, maxLen: 512, pFormat: "%s/*.txt", subdir);
  for ( i = filesystem->FindFirst(this: filesystem, a2: search, a3: &findHandle);
        i != nullptr;
        i = (const char *)((int (__thiscall *)(IFileSystem *))filesystem->FindNext)(a1: filesystem) )
  {
    if ( ((unsigned __int8 (__thiscall *)(IFileSystem *, int, int))filesystem->FindIsDirectory)(
           a1: filesystem,
           a2: findHandle,
           a3: a2) == 0 )
    {
      V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s/%s", subdir, i);
      v5 = filesystem->FindOrAddFileName(this: filesystem, a2: fn);
      m_pMemory = (int)files[1].m_pMemory;
      v7 = v5;
      m_nAllocationCount = files->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: files, num: m_pMemory - m_nAllocationCount + 1);
      ++files[1].m_pMemory;
      v9 = (void **)files->m_pMemory;
      v10 = (int)files[1].m_pMemory - m_pMemory - 1;
      files[1].m_nAllocationCount = (int)files->m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
      v11 = (void **)&files->m_pMemory[m_pMemory];
      if ( v11 != nullptr )
        *v11 = v7;
    }
    a2 = findHandle;
  }
  filesystem->FindClose(this: filesystem, a2: findHandle);
}

//------------------------------------------------------------------------------
// Address: 0x00421250
// Name: private: void AnimationBrowser::UpdateCustomTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::UpdateCustomTabs(AnimationBrowser *this)
{
  CAnimBrowserTab::UpdateCustomTabs(this: this->m_pFilterTab, list: &this->m_CustomAnimationTabs);
}

//------------------------------------------------------------------------------
// Address: 0x00421270
// Name: private: void AnimationBrowser::AddAnimationToCustomFile(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::AddAnimationToCustomFile(
        AnimationBrowser *this,
        int index,
        const char *animationName)
{
  CCustomAnim *v3; // ebx
  int m_Size; // ecx
  int v5; // eax
  CUtlSymbol *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v8; // edi
  CUtlSymbol *v9; // ecx
  int v10; // eax
  CUtlSymbol *v11; // eax

  if ( index >= 0 && index < this->m_CustomAnimationTabs.m_Size )
  {
    v3 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[index];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&index + 1, pStr: animationName);
    m_Size = v3->m_Animations.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
      goto LABEL_9;
    m_pMemory = v3->m_Animations.m_Memory.m_pMemory;
    while ( m_pMemory->m_Id != HIWORD(index) )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_9;
    }
    if ( v5 == -1 )
    {
LABEL_9:
      m_nAllocationCount = v3->m_Animations.m_Memory.m_nAllocationCount;
      v8 = v3->m_Animations.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&v3->m_Animations,
          num: v8 - m_nAllocationCount + 1);
      ++v3->m_Animations.m_Size;
      v9 = v3->m_Animations.m_Memory.m_pMemory;
      v10 = v3->m_Animations.m_Size - v8 - 1;
      v3->m_Animations.m_pElements = v9;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[v8 + 1], src: &v9[v8], count: 2 * v10);
      v11 = &v3->m_Animations.m_Memory.m_pMemory[v8];
      if ( v11 != nullptr )
        v11->m_Id = *(_WORD *)((unsigned __int16)&index + 2);
      v3->m_bDirty = true;
    }
    AnimationBrowser::OnFilter(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421330
// Name: private: void AnimationBrowser::RemoveAnimationFromCustomFile(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::RemoveAnimationFromCustomFile(
        AnimationBrowser *this,
        int index,
        const char *animationName)
{
  CCustomAnim *v4; // esi
  int m_Size; // ecx
  int v6; // eax
  CUtlSymbol *i; // edx
  int v8; // ecx

  if ( index >= 0 && index < this->m_CustomAnimationTabs.m_Size )
  {
    v4 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[index];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&index + 1, pStr: animationName);
    m_Size = v4->m_Animations.m_Size;
    v6 = 0;
    if ( m_Size > 0 )
    {
      for ( i = v4->m_Animations.m_Memory.m_pMemory; i->m_Id != HIWORD(index); ++i )
      {
        if ( ++v6 >= m_Size )
          return;
      }
      if ( v6 != -1 )
      {
        v8 = m_Size - v6 - 1;
        if ( v8 > 0 )
          _V_memmove(
            dest: &v4->m_Animations.m_Memory.m_pMemory[v6],
            src: &v4->m_Animations.m_Memory.m_pMemory[v6 + 1],
            count: 2 * v8);
        --v4->m_Animations.m_Size;
        v4->m_bDirty = true;
        AnimationBrowser::OnFilter(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004213F0
// Name: public: AnimationBrowser::AnimationBrowser(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
AnimationBrowser *__thiscall AnimationBrowser::AnimationBrowser(AnimationBrowser *this, mxWindow *parent, int id)
{
  mxScrollbar *v4; // eax
  mxScrollbar *v5; // eax
  int thumbnailsizeanim; // eax
  CTabWindow *v7; // eax
  CAnimBrowserTab *v8; // edi
  mxLineEdit *v9; // eax
  mxLineEdit *v10; // eax
  mxButton *v11; // eax
  mxButton *v12; // eax
  mxButton *v13; // eax
  mxButton *v14; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: "AnimationBrowser", style: id);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "AnimationBrowser",
    displaynameroot: "Animations");
  this->mxWindow::mxWidget::__vftable = (AnimationBrowser_vtbl *)&AnimationBrowser::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&AnimationBrowser::`vftable'{for `IFacePoserToolWindow'};
  this->m_Filtered.m_Memory.m_pMemory = nullptr;
  this->m_Filtered.m_Memory.m_nAllocationCount = 0;
  this->m_Filtered.m_Memory.m_nGrowSize = 0;
  this->m_Filtered.m_Size = 0;
  this->m_Filtered.m_pElements = nullptr;
  this->m_CustomAnimationTabs.m_Memory.m_pMemory = nullptr;
  this->m_CustomAnimationTabs.m_Memory.m_nAllocationCount = 0;
  this->m_CustomAnimationTabs.m_Memory.m_nGrowSize = 0;
  this->m_CustomAnimationTabs.m_Size = 0;
  this->m_CustomAnimationTabs.m_pElements = nullptr;
  mxWidget::setId(this, id);
  this->m_nTopOffset = 0;
  v4 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxScrollbar::mxScrollbar(this: v4, parent: this, x: 0, y: 0, w: 18, h: 100, id: 1001, style: 1);
  else
    v5 = nullptr;
  this->slScrollbar = v5;
  this->m_nLastNumAnimations = -1;
  this->m_nGranularity = 10;
  this->m_nCurCell = -1;
  this->m_nClickedCell = -1;
  this->m_nGap = 4;
  this->m_nDescriptionHeight = 34;
  thumbnailsizeanim = g_viewerSettings.thumbnailsizeanim;
  this->m_nSnapshotWidth = g_viewerSettings.thumbnailsizeanim;
  if ( thumbnailsizeanim < 64 )
    thumbnailsizeanim = 64;
  this->m_nSnapshotWidth = thumbnailsizeanim;
  if ( thumbnailsizeanim > 256 )
    thumbnailsizeanim = 256;
  this->m_nSnapshotWidth = thumbnailsizeanim;
  g_viewerSettings.thumbnailsizeanim = thumbnailsizeanim;
  this->m_nSnapshotHeight = this->m_nSnapshotWidth + this->m_nDescriptionHeight;
  this->m_bDragging = false;
  this->m_nDragCell = -1;
  this->m_szSearchString[0] = 0;
  v7 = (CTabWindow *)operator new(nSize: 0x68u);
  v8 = (CAnimBrowserTab *)v7;
  if ( v7 != nullptr )
  {
    CTabWindow::CTabWindow(this: v7, parent: this, x: 5, y: 5, w: 240, h: 20, id: 1006, style: 0);
    v8->__vftable = (CAnimBrowserTab_vtbl *)&CAnimBrowserTab::`vftable';
    v8->m_CustomGroups.m_Memory.m_pMemory = nullptr;
    v8->m_CustomGroups.m_Memory.m_nAllocationCount = 0;
    v8->m_CustomGroups.m_Memory.m_nGrowSize = 0;
    v8->m_CustomGroups.m_Size = 0;
    v8->m_CustomGroups.m_pElements = nullptr;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pFilterTab = v8;
  v8->add(this: v8, a2: "all");
  v8->add(this: v8, a2: "gestures");
  v8->add(this: v8, a2: "postures");
  v8->add(this: v8, a2: "search results");
  v9 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxLineEdit::mxLineEdit(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, label: defaultValue, id: 0, style: 0);
  else
    v10 = nullptr;
  this->m_pSearchEntry = v10;
  v11 = (mxButton *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxButton::mxButton(this: v11, parent: this, x: 0, y: 0, w: 18, h: 18, label: "+", id: 1002);
  else
    v12 = nullptr;
  this->m_pThumbnailIncreaseButton = v12;
  v13 = (mxButton *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxButton::mxButton(this: v13, parent: this, x: 0, y: 0, w: 18, h: 18, label: "-", id: 1003);
  else
    v14 = nullptr;
  this->m_pThumbnailDecreaseButton = v14;
  this->m_nCurFilter = 0;
  this->m_flDragTime = 0.0;
  AnimationBrowser::OnFilter(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004216C0
// Name: private: void AnimationBrowser::RenameCustomFile(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::RenameCustomFile(AnimationBrowser *this, int index)
{
  CCustomAnim *v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  StudioModel *v5; // eax
  CStudioHdr *StudioHdr; // ebx
  char *v7; // eax
  void *v8; // eax
  AnimationBrowser *v9; // ecx
  CInputParams params; // [esp+0h] [ebp-810h] BYREF
  char fn[512]; // [esp+58Ch] [ebp-284h] BYREF
  char basename[128]; // [esp+78Ch] [ebp-84h] BYREF
  AnimationBrowser *v13; // [esp+80Ch] [ebp-4h]

  v13 = this;
  if ( index >= 0 && index < this->m_CustomAnimationTabs.m_Size )
  {
    v2 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[index];
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Custom Animation Group");
    _V_strcpy(dest: params.m_szPrompt, src: "Group Name:");
    v3 = CUtlSymbol::String(this: &v2->m_ShortName);
    _V_strcpy(dest: params.m_szInputText, src: v3);
    if ( InputProperties(&params) != 0 && params.m_szInputText[0] != 0 )
    {
      v4 = CUtlSymbol::String(this: &v2->m_ShortName);
      if ( _V_stricmp(s1: v4, s2: params.m_szInputText) != 0
        && filesystem->String(this: filesystem, a2: &v2->m_Handle, a3: fn, a4: 512) )
      {
        v5 = models->GetActiveStudioModel(this: models);
        if ( v5 != nullptr )
        {
          StudioHdr = StudioModel::GetStudioHdr(this: v5);
          if ( StudioHdr != nullptr )
          {
            filesystem->RemoveFile(this: filesystem, a2: fn, a3: "MOD");
            CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&index + 1, pStr: params.m_szInputText);
            v2->m_ShortName.m_Id = HIWORD(index);
            v7 = CStudioHdr::name(this: StudioHdr);
            V_StripExtension(in: v7, out: basename, outSize: 128);
            V_snprintf(
              pDest: fn,
              maxLen: 512,
              pFormat: "expressions/%s/animation/%s.txt",
              basename,
              params.m_szInputText);
            V_FixSlashes(pname: fn, separator: 92);
            _V_strlower(start: fn);
            CreatePath(relative: fn);
            v8 = filesystem->FindOrAddFileName(this: filesystem, a2: fn);
            v9 = v13;
            v2->m_Handle = v8;
            v2->m_bDirty = true;
            AnimationBrowser::UpdateCustomTabs(this: v9);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004218A0
// Name: private: void AnimationBrowser::AddCustomFile(void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::AddCustomFile(AnimationBrowser *this, void *const *handle)
{
  void *const *v2; // esi
  _WORD *v3; // eax
  _WORD *v4; // ebx
  int *v5; // esi
  StudioModel *v6; // eax
  CStudioHdr *StudioHdr; // eax
  mstudioseqdesc_t *v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  _WORD *v13; // eax
  int v14; // edi
  int v15; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v16; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v18; // eax
  CUtlSymbolTable::StringPool_t **v19; // eax
  char fn[512]; // [esp+4h] [ebp-284h] BYREF
  char basename[128]; // [esp+204h] [ebp-84h] BYREF
  AnimationBrowser *v22; // [esp+284h] [ebp-4h]

  v2 = handle;
  v22 = this;
  if ( filesystem->String(this: filesystem, a2: handle, a3: fn, a4: 512) )
  {
    V_FixSlashes(pname: fn, separator: 92);
    _V_strlower(start: fn);
    V_FileBase(in: fn, out: basename, maxlen: 128);
    v3 = operator new(nSize: 0x1Cu);
    if ( v3 != nullptr )
    {
      *(_BYTE *)v3 = 0;
      v3[1] = -1;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 3) = 0;
      *((_DWORD *)v3 + 4) = 0;
      *((_DWORD *)v3 + 5) = 0;
      *((_DWORD *)v3 + 6) = 0;
      *((void **)v3 + 1) = *v2;
      v4 = v3;
    }
    else
    {
      v4 = nullptr;
    }
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&handle + 1, pStr: basename);
    v4[1] = HIWORD(handle);
    CCustomAnim::LoadFromFile(this: (CCustomAnim *)v4);
    v5 = (int *)v22;
    *(_BYTE *)v4 = 1;
    if ( v5[164] != -1 )
    {
      v6 = models->GetActiveStudioModel(this: models);
      if ( v6 != nullptr )
      {
        StudioHdr = StudioModel::GetStudioHdr(this: v6);
        if ( StudioHdr != nullptr )
        {
          v8 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v5[164]);
          CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&handle + 1, pStr: (const char *)v8 + v8->szlabelindex);
          v9 = *((_DWORD *)v4 + 5);
          v10 = *((_DWORD *)v4 + 3);
          if ( v9 + 1 > v10 )
            CUtlMemory<CUtlSymbol,int>::Grow(this: (CUtlMemory<short,int> *)(v4 + 4), num: v9 - v10 + 1);
          ++*((_DWORD *)v4 + 5);
          v11 = *((_DWORD *)v4 + 2);
          v12 = *((_DWORD *)v4 + 5) - v9 - 1;
          *((_DWORD *)v4 + 6) = v11;
          if ( v12 > 0 )
            _V_memmove(dest: (void *)(v11 + 2 * v9 + 2), src: (const void *)(v11 + 2 * v9), count: 2 * v12);
          v13 = (_WORD *)(*((_DWORD *)v4 + 2) + 2 * v9);
          if ( v13 != nullptr )
            *v13 = HIWORD(handle);
        }
      }
    }
    v14 = v5[259];
    v15 = v5[257];
    v16 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v5 + 256);
    if ( v14 + 1 > v15 )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: v16, num: v14 - v15 + 1);
    ++v16[1].m_pMemory;
    m_pMemory = v16->m_pMemory;
    v18 = (int)v16[1].m_pMemory - v14 - 1;
    v16[1].m_nAllocationCount = (int)v16->m_pMemory;
    if ( v18 > 0 )
      _V_memmove(dest: &m_pMemory[v14 + 1], src: &m_pMemory[v14], count: 4 * v18);
    v19 = &v16->m_pMemory[v14];
    if ( v19 != nullptr )
      *v19 = (CUtlSymbolTable::StringPool_t *)v4;
    CAnimBrowserTab::UpdateCustomTabs(
      this: v22->m_pFilterTab,
      list: (CUtlVector<CCustomAnim *,CUtlMemory<CCustomAnim *,int> > *)v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421A70
// Name: private: void AnimationBrowser::DeleteCustomFile(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::DeleteCustomFile(AnimationBrowser *this, int index)
{
  CCustomAnim *v2; // ebx
  CUtlVector<CCustomAnim *,CUtlMemory<CCustomAnim *,int> > *p_m_CustomAnimationTabs; // esi
  char fn[512]; // [esp+4h] [ebp-204h] BYREF
  AnimationBrowser *v5; // [esp+204h] [ebp-4h]

  v5 = this;
  if ( index >= 0 && index < this->m_CustomAnimationTabs.m_Size )
  {
    v2 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[index];
    p_m_CustomAnimationTabs = &this->m_CustomAnimationTabs;
    if ( filesystem->String(this: filesystem, a2: &v2->m_Handle, a3: fn, a4: 512) )
    {
      if ( p_m_CustomAnimationTabs->m_Size - index - 1 > 0 )
        _V_memmove(
          dest: &p_m_CustomAnimationTabs->m_Memory.m_pMemory[index],
          src: &p_m_CustomAnimationTabs->m_Memory.m_pMemory[index + 1],
          count: 4 * (p_m_CustomAnimationTabs->m_Size - index - 1));
      --p_m_CustomAnimationTabs->m_Size;
      filesystem->RemoveFile(this: filesystem, a2: fn, a3: nullptr);
      if ( v2 != nullptr )
      {
        CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v2->m_Animations);
        free(pMem: v2);
      }
      CAnimBrowserTab::UpdateCustomTabs(this: v5->m_pFilterTab, list: p_m_CustomAnimationTabs);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421B40
// Name: public: void AnimationBrowser::OnAddCustomAnimationFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::OnAddCustomAnimationFilter(AnimationBrowser *this)
{
  StudioModel *v2; // eax
  StudioModel *v3; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  char *v7; // eax
  char basename[512]; // [esp+8h] [ebp-990h] BYREF
  CInputParams params; // [esp+208h] [ebp-790h] BYREF
  char fn[512]; // [esp+794h] [ebp-204h] BYREF
  void *fh; // [esp+994h] [ebp-4h] BYREF

  v2 = models->GetActiveStudioModel(this: models);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_pStudioHdr = v2->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v6 = v3->m_pStudioHdr;
    }
    else
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
      CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = v3->m_pStudioHdr;
      if ( v6->m_pStudioHdr == nullptr )
        return;
    }
    if ( v6 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Custom Animation Group");
      _V_strcpy(dest: params.m_szPrompt, src: "Group Name:");
      _V_strcpy(dest: params.m_szInputText, src: defaultValue);
      if ( InputProperties(&params) != 0 && params.m_szInputText[0] != 0 )
      {
        if ( AnimationBrowser::FindCustomFile(this, shortName: params.m_szInputText) == -1 )
        {
          v7 = CStudioHdr::name(this: v6);
          V_StripExtension(in: v7, out: basename, outSize: 512);
          V_snprintf(pDest: fn, maxLen: 512, pFormat: "expressions/%s/animation/%s.txt", basename, params.m_szInputText);
          V_FixSlashes(pname: fn, separator: 92);
          _V_strlower(start: fn);
          CreatePath(relative: fn);
          fh = filesystem->FindOrAddFileName(this: filesystem, a2: fn);
          AnimationBrowser::AddCustomFile(this, handle: &fh);
        }
        else
        {
          _Warning(a1: "Can't add duplicate tab '%s'\n", params.m_szInputText);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421CE0
// Name: public: virtual int AnimationBrowser::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall AnimationBrowser::handleEvent(AnimationBrowser *this, mxEvent *event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  int action; // eax
  int v8; // eax
  int modifiers; // eax
  int height; // edi
  void (__thiscall *redraw)(struct AnimationBrowser *); // edx
  int MinValue; // eax
  HWND Handle; // eax
  IFaceposerModels *v14; // edi
  IFaceposerModels_vtbl *v15; // ebx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edi
  mstudioseqdesc_t *SeqDesc; // eax
  int v21; // edi
  mstudioseqdesc_t *v22; // eax
  int v23; // eax
  int v24; // ebx
  mxEvent *v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  HWND v29; // eax
  void (__thiscall *v30)(struct AnimationBrowser *); // edx
  bool v31; // zf
  int CellUnderPosition; // eax
  mstudioseqdesc_t *v33; // ebx
  int y_low; // edx
  HWND v35; // eax
  HWND v36; // esi
  HWND v37; // eax
  int v38; // ebx
  int v39; // edi
  mxButton *m_pThumbnailIncreaseButton; // ecx
  int y; // edx
  HWND v42; // eax
  int v43; // edi
  CAnimBrowserTab *m_pFilterTab; // ecx
  bool v45; // cc
  void (__thiscall *select)(struct CAnimBrowserTab *, int); // eax
  char sz[512]; // [esp+Ch] [ebp-218h] BYREF
  int cw; // [esp+20Ch] [ebp-18h] BYREF
  IFacePoserToolWindow *tool; // [esp+210h] [ebp-14h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+214h] [ebp-10h]
  tagPOINT Point; // [esp+218h] [ebp-Ch] BYREF
  int cy; // [esp+220h] [ebp-4h] BYREF

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = event;
  HandleToolEvent = this->HandleToolEvent;
  cy = 0;
  tool = &this->IFacePoserToolWindow;
  if ( ((unsigned __int8 (__stdcall *)(mxEvent *))HandleToolEvent)(a1: event) != 0 )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  switch ( v4->event )
  {
    case 0:
      action = v4->action;
      cy = 1;
      switch ( action )
      {
        case 1001:
          modifiers = v4->modifiers;
          switch ( modifiers )
          {
            case 5:
              height = v4->height;
              mxScrollbar::setValue(this: this->slScrollbar, ivalue: height);
LABEL_10:
              redraw = this->redraw;
              this->m_nTopOffset = height;
              redraw(this);
              break;
            case 2:
              height = mxScrollbar::getValue(this: this->slScrollbar) - this->m_nGranularity;
              if ( height > mxScrollbar::getMinValue(this: this->slScrollbar) )
              {
LABEL_17:
                mxScrollbar::setValue(this: this->slScrollbar, ivalue: height);
                Handle = (HWND)mxWidget::getHandle(this: this->slScrollbar);
                InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
                goto LABEL_10;
              }
              MinValue = mxScrollbar::getMinValue(this: this->slScrollbar);
LABEL_16:
              height = MinValue;
              goto LABEL_17;
            case 3:
              height = this->m_nGranularity + mxScrollbar::getValue(this: this->slScrollbar);
              if ( height < mxScrollbar::getMaxValue(this: this->slScrollbar) )
                goto LABEL_17;
              MinValue = mxScrollbar::getMaxValue(this: this->slScrollbar);
              goto LABEL_16;
            default:
              break;
          }
LABEL_11:
          IFacePoserToolWindow::SetActiveTool(tool);
LABEL_12:
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return cy;
        case 1002:
          AnimationBrowser::ThumbnailIncrease(this);
          goto LABEL_11;
        case 1003:
          AnimationBrowser::ThumbnailDecrease(this);
          goto LABEL_11;
        case 1004:
          models->GetActiveModelIndex(this: models);
          if ( this->m_nClickedCell >= 0 )
          {
            v14 = models;
            v15 = models->__vftable;
            v16 = AnimationBrowser::TranslateSequenceNumber(this, index: this->m_nClickedCell);
            v15->RecreateAnimationBitmap(this: v14, a2: v17, a3: v16);
          }
          this->redraw(this);
          goto LABEL_11;
        case 1005:
          v18 = models->GetActiveModelIndex(this: models);
          models->RecreateAllAnimationBitmaps(this: models, a2: v18);
          this->redraw(this);
          goto LABEL_11;
        case 1006:
          v8 = this->m_pFilterTab->getSelectedIndex(this: this->m_pFilterTab);
          if ( v8 >= 0 )
          {
            this->m_nCurFilter = v8;
            AnimationBrowser::OnFilter(this);
          }
          goto LABEL_11;
        case 1007:
          AnimationBrowser::OnAddCustomAnimationFilter(this);
          goto LABEL_11;
        default:
          if ( action >= 1100 && action <= 1199 )
          {
            v19 = action - 1100;
            SeqDesc = AnimationBrowser::GetSeqDesc(this, index: this->m_nCurCell);
            if ( SeqDesc != nullptr )
              AnimationBrowser::AddAnimationToCustomFile(
                this,
                index: v19,
                animationName: (const char *)SeqDesc + SeqDesc->szlabelindex);
            goto LABEL_11;
          }
          if ( action >= 1200 && action <= 1299 )
          {
            v21 = action - 1200;
            v22 = AnimationBrowser::GetSeqDesc(this, index: this->m_nCurCell);
            if ( v22 != nullptr )
              AnimationBrowser::RemoveAnimationFromCustomFile(
                this,
                index: v21,
                animationName: (const char *)v22 + v22->szlabelindex);
            goto LABEL_11;
          }
          if ( action >= 1300 && action <= 1399 )
          {
            AnimationBrowser::DeleteCustomFile(this, index: action - 1300);
            goto LABEL_11;
          }
          if ( action >= 1400 && action <= 1499 )
          {
            AnimationBrowser::RenameCustomFile(this, index: action - 1400);
            goto LABEL_11;
          }
          cy = 0;
          goto LABEL_12;
      }
    case 1:
      v38 = mxWidget::w2(this);
      v39 = tool->GetCaptionHeight(this: tool) + 10;
      mxWidget::setBounds(this: this->m_pSearchEntry, x: 5, y: v39, w: v38 - 180, h: 18);
      m_pThumbnailIncreaseButton = this->m_pThumbnailIncreaseButton;
      event = (mxEvent *)(v39 + 4);
      mxWidget::setBounds(this: m_pThumbnailIncreaseButton, x: v38 - 40, y: v39 + 4, w: 16, h: 16);
      mxWidget::setBounds(this: this->m_pThumbnailDecreaseButton, x: v38 - 20, y: (int)event, w: 16, h: 16);
      mxWidget::setBounds(this: this->m_pFilterTab, x: 5, y: v39 + 20, w: v38 - 10, h: 20);
      this->m_nTopOffset = 0;
      goto LABEL_63;
    case 6:
      v31 = (v4->buttons & 2) == 0;
      cy = 1;
      if ( !v31 )
      {
        CellUnderPosition = AnimationBrowser::GetCellUnderPosition(this, x: SLOWORD(v4->x), y: SLOWORD(v4->y));
        AnimationBrowser::SetClickedCell(this, cell: CellUnderPosition);
        AnimationBrowser::ShowRightClickMenu(this, mx: SLOWORD(v4->x), my: SLOWORD(v4->y));
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 1;
      }
      if ( !this->m_bDragging )
        goto LABEL_11;
      if ( this->m_nClickedCell < 0 )
        goto LABEL_11;
      v33 = AnimationBrowser::GetSeqDesc(this, index: this->m_nClickedCell);
      AnimationBrowser::DrawFocusRect(this);
      this->m_bDragging = false;
      y_low = SLOWORD(v4->y);
      Point.x = SLOWORD(v4->x);
      Point.y = y_low;
      v35 = (HWND)mxWidget::getHandle(this);
      ClientToScreen(hWnd: v35, lpPoint: &Point);
      v36 = WindowFromPoint(Point);
      if ( v36 == nullptr )
        goto LABEL_11;
      if ( v33 == nullptr )
        goto LABEL_11;
      v37 = (HWND)mxWidget::getHandle(this: g_pChoreoView);
      if ( v36 != v37 && !IsChild(hWndParent: v37, hWnd: v36) )
        goto LABEL_11;
      if ( !CChoreoView::CreateAnimationEvent(
              this: g_pChoreoView,
              mx: Point.x,
              my: Point.y,
              animationname: (const char *)v33 + v33->szlabelindex) )
        goto LABEL_11;
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return 1;
    case 7:
      if ( (v4->buttons & 2) != 0 )
        goto LABEL_48;
      v23 = AnimationBrowser::GetCellUnderPosition(this, x: v4->x, y: v4->y);
      v24 = v23;
      if ( v23 < 0 || v23 >= this->m_Filtered.m_Size )
      {
        AnimationBrowser::Deselect(this);
        this->redraw(this);
      }
      else if ( AnimationBrowser::ComputeRect(this, cell: v23, rcx: (int *)&event, rcy: &cy, rcw: &cw, rch: &Point.y) != 0 )
      {
        v25 = event;
        this->m_flDragTime = realtime;
        this->m_bDragging = true;
        this->m_nDragCell = v24;
        this->m_nXStart = SLOWORD(v4->x);
        this->m_nYStart = SLOWORD(v4->y);
        v26 = cy;
        this->m_rcFocus.top = cy;
        v27 = Point.y + v26 - this->m_nDescriptionHeight;
        this->m_rcFocus.left = (int)v25;
        v28 = (int)v25 + cw;
        this->m_rcFocus.bottom = v27;
        Point.y = 0;
        Point.x = 0;
        this->m_rcFocus.right = v28;
        v29 = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: v29, lpPoint: &Point);
        OffsetRect(lprc: &this->m_rcFocus, dx: Point.x, dy: Point.y);
        *(_QWORD *)&this->m_rcOrig.left = *(_QWORD *)&this->m_rcFocus.left;
        *(_QWORD *)&this->m_rcOrig.right = *(_QWORD *)&this->m_rcFocus.right;
        AnimationBrowser::DrawFocusRect(this);
        v30 = this->redraw;
        this->m_nCurCell = v24;
        v30(this);
        this->m_nClickedCell = v24;
        cy = 1;
        goto LABEL_11;
      }
LABEL_48:
      cy = 1;
      goto LABEL_11;
    case 9:
      if ( this->m_bDragging )
      {
        AnimationBrowser::DrawFocusRect(this);
        *(_QWORD *)&this->m_rcFocus.left = *(_QWORD *)&this->m_rcOrig.left;
        *(_QWORD *)&this->m_rcFocus.right = *(_QWORD *)&this->m_rcOrig.right;
        OffsetRect(lprc: &this->m_rcFocus, dx: SLOWORD(v4->x) - this->m_nXStart, dy: SLOWORD(v4->y) - this->m_nYStart);
        AnimationBrowser::DrawFocusRect(this);
      }
      cy = 1;
      goto LABEL_11;
    case 0xA:
    case 0xB:
      if ( v4->key == 27 && this->m_szSearchString[0] != 0 )
      {
        mxWidget::setLabel(this: this->m_pSearchEntry, format: defaultValue);
        m_pFilterTab = this->m_pFilterTab;
        this->m_szSearchString[0] = 0;
        m_pFilterTab->select(this: m_pFilterTab, a2: 0);
        this->m_nCurFilter = 0;
        AnimationBrowser::OnFilter(this);
      }
      else
      {
        mxLineEdit::getText(this: this->m_pSearchEntry, buf: sz, bufsize: 0x200u);
        if ( _V_stricmp(s1: sz, s2: this->m_szSearchString) != 0 )
        {
          V_strncpy(pDest: this->m_szSearchString, pSrc: sz, maxLen: 256);
          v45 = _V_strlen(str: this->m_szSearchString) <= 0;
          select = this->m_pFilterTab->select;
          if ( v45 )
          {
            ((void (__stdcall *)(_DWORD))select)(a1: 0);
            this->m_nCurFilter = 0;
          }
          else
          {
            ((void (__stdcall *)(int))select)(a1: 3);
            this->m_nCurFilter = 3;
          }
          AnimationBrowser::OnFilter(this);
        }
      }
      goto LABEL_12;
    case 0xC:
      y = v4->y;
      Point.x = v4->x;
      Point.y = y;
      v42 = (HWND)mxWidget::getHandle(this);
      ScreenToClient(hWnd: v42, lpPoint: &Point);
      if ( v4->height >= 0 )
      {
        this->m_nTopOffset = this->m_nTopOffset - 10 <= 0 ? 0 : this->m_nTopOffset - 10;
      }
      else
      {
        v43 = this->m_nTopOffset + 10;
        if ( v43 >= mxScrollbar::getMaxValue(this: this->slScrollbar) )
          this->m_nTopOffset = mxScrollbar::getMaxValue(this: this->slScrollbar);
        else
          this->m_nTopOffset = v43;
      }
LABEL_63:
      AnimationBrowser::RepositionSlider(this);
      this->redraw(this);
      cy = 1;
      goto LABEL_11;
    default:
      goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422490
// Name: private: void AnimationBrowser::PurgeCustom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::PurgeCustom(AnimationBrowser *this)
{
  int v2; // esi
  CCustomAnim *v3; // ecx
  CCustomAnim *v4; // esi
  CUtlSymbol *m_pMemory; // eax
  CCustomAnim **v6; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( this->m_CustomAnimationTabs.m_Size > 0 )
  {
    while ( 1 )
    {
      v3 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[v2];
      if ( v3->m_bDirty )
        CCustomAnim::SaveToFile(this: v3);
      v4 = this->m_CustomAnimationTabs.m_Memory.m_pMemory[v2];
      if ( v4 != nullptr )
      {
        v4->m_Animations.m_Size = 0;
        if ( v4->m_Animations.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4->m_Animations.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Animations.m_Memory.m_pMemory);
            v4->m_Animations.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Animations.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v4->m_Animations.m_Memory.m_pMemory;
        v4->m_Animations.m_pElements = m_pMemory;
        if ( v4->m_Animations.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v4->m_Animations.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Animations.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v4);
      }
      if ( ++i >= this->m_CustomAnimationTabs.m_Size )
        break;
      v2 = i;
    }
  }
  this->m_CustomAnimationTabs.m_Size = 0;
  if ( this->m_CustomAnimationTabs.m_Memory.m_nGrowSize < 0 )
  {
    this->m_CustomAnimationTabs.m_pElements = this->m_CustomAnimationTabs.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CustomAnimationTabs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CustomAnimationTabs.m_Memory.m_pMemory);
      this->m_CustomAnimationTabs.m_Memory.m_pMemory = nullptr;
    }
    v6 = this->m_CustomAnimationTabs.m_Memory.m_pMemory;
    this->m_CustomAnimationTabs.m_Memory.m_nAllocationCount = 0;
    this->m_CustomAnimationTabs.m_pElements = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004225A0
// Name: private: void AnimationBrowser::BuildCustomFromFiles(class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::BuildCustomFromFiles(
        AnimationBrowser *this,
        CUtlVector<void *,CUtlMemory<void *,int> > *files)
{
  AnimationBrowser *v2; // esi
  CUtlVector<void *,CUtlMemory<void *,int> > *v3; // ebx
  int v4; // eax
  int v5; // esi
  _WORD *v6; // eax
  void **m_pMemory; // ecx
  CCustomAnim *v8; // ebx
  _DWORD *v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v12; // ecx
  int v13; // eax
  CCustomAnim **v14; // edi
  char fn[512]; // [esp+8h] [ebp-28Ch] BYREF
  char basename[128]; // [esp+208h] [ebp-8Ch] BYREF
  int i; // [esp+288h] [ebp-Ch]
  AnimationBrowser *v18; // [esp+28Ch] [ebp-8h]
  CUtlSymbol v19; // [esp+292h] [ebp-2h] BYREF

  v2 = this;
  v18 = this;
  AnimationBrowser::PurgeCustom(this);
  v3 = files;
  v4 = 0;
  i = 0;
  if ( files->m_Size > 0 )
  {
    do
    {
      v5 = v4;
      if ( filesystem->String(this: filesystem, a2: &v3->m_Memory.m_pMemory[v4], a3: fn, a4: 512) )
      {
        V_FixSlashes(pname: fn, separator: 92);
        _V_strlower(start: fn);
        V_FileBase(in: fn, out: basename, maxlen: 128);
        v6 = operator new(nSize: 0x1Cu);
        if ( v6 != nullptr )
        {
          m_pMemory = v3->m_Memory.m_pMemory;
          *(_BYTE *)v6 = 0;
          v6[1] = -1;
          *((_DWORD *)v6 + 2) = 0;
          *((_DWORD *)v6 + 3) = 0;
          *((_DWORD *)v6 + 4) = 0;
          *((_DWORD *)v6 + 5) = 0;
          *((_DWORD *)v6 + 6) = 0;
          *((_DWORD *)v6 + 1) = m_pMemory[v5];
          v8 = (CCustomAnim *)v6;
        }
        else
        {
          v8 = nullptr;
        }
        CUtlSymbol::CUtlSymbol(this: &v19, pStr: basename);
        v8->m_ShortName = v19;
        CCustomAnim::LoadFromFile(this: v8);
        v9 = &v18->mxWindow::mxWidget::__vftable;
        m_Size = v18->m_CustomAnimationTabs.m_Size;
        m_nAllocationCount = v18->m_CustomAnimationTabs.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v18->m_CustomAnimationTabs,
            num: m_Size - m_nAllocationCount + 1);
        ++v9[259];
        v12 = v9[256];
        v13 = v9[259] - m_Size - 1;
        v9[260] = v12;
        if ( v13 > 0 )
          _V_memmove(dest: (void *)(v12 + 4 * m_Size + 4), src: (const void *)(v12 + 4 * m_Size), count: 4 * v13);
        v14 = (CCustomAnim **)(v9[256] + 4 * m_Size);
        if ( v14 != nullptr )
          *v14 = v8;
        v3 = files;
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < v3->m_Size );
    v2 = v18;
  }
  CAnimBrowserTab::UpdateCustomTabs(this: v2->m_pFilterTab, list: &v2->m_CustomAnimationTabs);
}

//------------------------------------------------------------------------------
// Address: 0x00422720
// Name: public: virtual void AnimationBrowser::OnModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::OnModelChanged(AnimationBrowser *this)
{
  StudioModel *(__thiscall *GetActiveStudioModel)(IFaceposerModels *); // edx
  int v3; // eax
  int v4; // esi
  _DWORD *v5; // eax
  const studiohdr_t *v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  const char *v13; // eax
  int thumbnailsizeanim; // eax
  int v15; // eax
  char basename[512]; // [esp+Ch] [ebp-414h] BYREF
  char subdir[512]; // [esp+20Ch] [ebp-214h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > files; // [esp+40Ch] [ebp-14h] BYREF

  GetActiveStudioModel = models->GetActiveStudioModel;
  memset(&files, 0, sizeof(files));
  v3 = (int)GetActiveStudioModel(this: models);
  v4 = v3;
  if ( v3 != 0 )
  {
    v5 = *(_DWORD **)(v3 + 16);
    if ( v5 == nullptr || *v5 != 0 )
    {
      v7 = *(_DWORD *)(v4 + 16);
    }
    else
    {
      v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: *(unsigned __int16 *)(v4 + 424));
      CStudioHdr::Init(this: *(CStudioHdr **)(v4 + 16), pStudioHdr: v6, mdlcache: nullptr);
      v7 = *(_DWORD *)(v4 + 16);
      if ( *(_DWORD *)v7 == 0 )
        goto LABEL_16;
    }
    if ( v7 != 0 )
    {
      v8 = *(_DWORD *)v7;
      v9 = *(_DWORD *)(*(_DWORD *)v7 + 400);
      if ( v9 != 0 && (v10 = *(_DWORD *)(v9 + v8 + 20), v11 = v8 + v9, v10 != 0) && v11 + v10 != 0 )
      {
        v12 = *(_DWORD *)(v11 + 20);
        if ( v12 != 0 )
          v13 = (const char *)(v12 + v11);
        else
          v13 = nullptr;
      }
      else
      {
        v13 = (const char *)(v8 + 12);
      }
      V_StripExtension(in: v13, out: basename, outSize: 512);
      V_snprintf(pDest: subdir, maxLen: 512, pFormat: "expressions/%s/animation", basename);
      V_FixSlashes(pname: subdir, separator: 92);
      _V_strlower(start: subdir);
      AnimationBrowser::FindCustomFiles(
        this: (AnimationBrowser *)((char *)this - 12),
        a2: v7,
        subdir,
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&files);
    }
  }
LABEL_16:
  AnimationBrowser::BuildCustomFromFiles(this: (AnimationBrowser *)((char *)this - 12), &files);
  thumbnailsizeanim = g_viewerSettings.thumbnailsizeanim;
  this->m_nButtonSquare = g_viewerSettings.thumbnailsizeanim;
  if ( thumbnailsizeanim < 64 )
    thumbnailsizeanim = 64;
  this->m_nButtonSquare = thumbnailsizeanim;
  if ( thumbnailsizeanim > 256 )
    thumbnailsizeanim = 256;
  this->m_nButtonSquare = thumbnailsizeanim;
  g_viewerSettings.thumbnailsizeanim = thumbnailsizeanim;
  v15 = *((_DWORD *)this - 3);
  this->m_nGap = this->m_nButtonSquare + this->m_nClickedCell;
  (*(void (__thiscall **)(char *))(v15 + 16))(a1: (char *)this - 12);
  AnimationBrowser::OnFilter(this: (AnimationBrowser *)((char *)this - 12));
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&files);
}

//------------------------------------------------------------------------------
// Address: 0x004228A0
// Name: public: virtual void AnimationBrowser::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AnimationBrowser::Shutdown(AnimationBrowser *this)
{
  AnimationBrowser::PurgeCustom(this: (AnimationBrowser *)((char *)this - 12));
}

//------------------------------------------------------------------------------
// Address: 0x004A5630
// Name: public: virtual bool mxWindow::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall mxWindow::PaintBackground(CP4File_Dummy *this)
{
  return 1;
}
