// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/subtitlepanel.cpp
// Functions: 15
// ============================================================

#include "game\client\subtitlepanel.h"

//------------------------------------------------------------------------------
// Address: 0x10178880
// Name: public: static char const __near * CSubtitlePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSubtitlePanel::GetPanelClassName()
{
  return "CSubtitlePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10178890
// Name: public: bool CSubtitlePanel::StartCaptions(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubtitlePanel::StartCaptions(CSubtitlePanel *this)
{
  int v2; // [esp+0h] [ebp-4h]

  if ( !this->m_bHasCaptions )
    return 0;
  this->m_Captions.m_CaptionStartTime = _Plat_FloatTime(a1: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101788B0
// Name: public: void CSubtitlePanel::Pause(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::Pause(CSubtitlePanel *this, bool bPause)
{
  int v2; // [esp+0h] [ebp-4h]

  if ( this->m_Captions.m_bPaused != bPause )
  {
    this->m_Captions.m_bPaused = bPause;
    if ( bPause )
      this->m_Captions.m_flPauseTime = _Plat_FloatTime(a1: v2);
    else
      this->m_Captions.m_flTotalPauseTime = _Plat_FloatTime(a1: v2)
                                          - this->m_Captions.m_flPauseTime
                                          + this->m_Captions.m_flTotalPauseTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178900
// Name: public: bool CSubtitlePanel::HasCaptions(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSubtitlePanel::HasCaptions(CSubtitlePanel *this)
{
  return this->m_bHasCaptions;
}

//------------------------------------------------------------------------------
// Address: 0x10178910
// Name: public: bool CCaptionSequencer::GetNextCaption(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCaptionSequencer::GetNextCaption(CCaptionSequencer *this)
{
  char *m_CurCaptionString; // edi
  const char *v3; // ecx
  char *v4; // eax
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // eax
  const char *v8; // ecx
  char *v9; // eax
  char buff[256]; // [esp+8h] [ebp-100h] BYREF

  m_CurCaptionString = this->m_CurCaptionString;
  if ( this == (CCaptionSequencer *)-76 || this->m_CaptionBuf.m_Error != 0 )
  {
    *m_CurCaptionString = 0;
    return 0;
  }
  else
  {
    CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: this->m_CurCaptionString, nMaxChars: 256);
    v4 = V_stristr(a1: v3, a2: (const char *)&this->m_bCaptions, pStr: m_CurCaptionString, pSearch: "\r");
    if ( v4 != nullptr )
      *v4 = 0;
    CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v5 = V_stristr(a1: buff, a2: (const char *)&this->m_bCaptions, pStr: buff, pSearch: "\r");
      if ( v5 != nullptr )
        *v5 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    sscanf(string: buff, format: "%x", &this->m_CurCaptionColor);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v7 = V_stristr(a1: v6, a2: (const char *)&this->m_bCaptions, pStr: buff, pSearch: "\r");
      if ( v7 != nullptr )
        *v7 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    this->m_CurCaptionStartTime = atof(nptr: buff);
    if ( this->m_CaptionBuf.m_Error == 0 )
    {
      CUtlBuffer::GetLine(this: &this->m_CaptionBuf, pLine: buff, nMaxChars: 256);
      v9 = V_stristr(a1: v8, a2: (const char *)&this->m_bCaptions, pStr: buff, pSearch: "\r");
      if ( v9 != nullptr )
        *v9 = 0;
      CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_CURRENT, offset: 1);
    }
    this->m_CurCaptionEndTime = atof(nptr: buff);
    this->m_bCaptionStale = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178A80
// Name: public: char const __near * CCaptionSequencer::GetCurrentCaption(int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCaptionSequencer::GetCurrentCaption(CCaptionSequencer *this, int *pColorOut)
{
  float m_CaptionStartTime; // xmm1_4
  float v4; // xmm0_4
  char *result; // eax
  int v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]

  if ( !this->m_bCaptions )
    return nullptr;
  m_CaptionStartTime = this->m_CaptionStartTime;
  if ( m_CaptionStartTime == 0.0 )
    return nullptr;
  if ( this->m_bPaused )
  {
    v4 = (float)(this->m_flPauseTime - this->m_flTotalPauseTime) - m_CaptionStartTime;
    v7 = v4;
  }
  else
  {
    v7 = _Plat_FloatTime(a1: v6) - this->m_flTotalPauseTime - this->m_CaptionStartTime;
    v4 = v7;
  }
  if ( this->m_bShowingCaption )
    goto LABEL_21;
  if ( this->m_bCaptionStale )
  {
    CCaptionSequencer::GetNextCaption(this);
    v4 = v7;
  }
  if ( this->m_bShowingCaption )
  {
LABEL_21:
    if ( v4 > this->m_CurCaptionEndTime )
      *(_WORD *)&this->m_bShowingCaption = 256;
  }
  else if ( v4 > this->m_CurCaptionStartTime )
  {
    this->m_bShowingCaption = true;
  }
  if ( !this->m_bShowingCaption )
    return nullptr;
  result = this->m_CurCaptionString;
  if ( this->m_CurCaptionString[0] == 0 )
    return nullptr;
  if ( pColorOut != nullptr )
    *pColorOut = this->m_CurCaptionColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10178B40
// Name: protected: virtual void CSubtitlePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::PaintBackground(CSubtitlePanel *this)
{
  int Wide; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int nLabelX; // [esp+1Ch] [ebp-1Ch] BYREF
  int nLabelTall; // [esp+20h] [ebp-18h] BYREF
  int nLabelY; // [esp+24h] [ebp-14h] BYREF
  int nLabelWide; // [esp+28h] [ebp-10h] BYREF
  int nMsgWide; // [esp+2Ch] [ebp-Ch] BYREF
  int nMsgTall; // [esp+30h] [ebp-8h] BYREF
  int v12; // [esp+34h] [ebp-4h]

  this->m_pSubtitleLabel->GetContentSize(this: this->m_pSubtitleLabel, a2: &nMsgWide, a3: &nMsgTall);
  if ( nMsgWide != 0 && nMsgTall != 0 )
  {
    vgui::Panel::GetBounds(this: this->m_pSubtitleLabel, x: &nLabelX, y: &nLabelY, wide: &nLabelWide, tall: &nLabelTall);
    Wide = vgui::Panel::GetWide(this);
    v3 = nMsgTall + this->m_nFontTall;
    v4 = (int)(float)((float)((float)Wide * 0.050000001) + (float)nLabelWide);
    v5 = vgui::Panel::GetWide(this);
    v12 = -1778384896;
    ((void (__thiscall *)(CSubtitlePanel *, int, int, int, int, int, int, _DWORD))this->DrawBox)(
      a1: this,
      a2: (v5 - v4) / 2,
      a3: nLabelTall + nLabelY + nMsgTall / -2 - v3 / 2,
      a4: v4,
      a5: v3,
      a6: -1778384896,
      a7: 1065353216,
      a8: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178C20
// Name: bool ShouldUseCaptioning(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ShouldUseCaptioning()
{
  if ( cheap_captions_test.m_pParent != nullptr && cheap_captions_test.m_pParent->m_Value.m_nValue != 0 )
    return true;
  if ( closecaption.m_pParent != nullptr )
    return closecaption.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10178C50
// Name: public: float CCaptionSequencer::GetAlpha(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCaptionSequencer::GetAlpha(CCaptionSequencer *this)
{
  double v2; // st7
  float m_CurCaptionStartTime; // xmm2_4
  float v4; // xmm0_4
  float C; // xmm1_4
  float v6; // xmm1_4
  int v8; // [esp+14h] [ebp-8h]
  float val; // [esp+18h] [ebp-4h]

  if ( !this->m_bShowingCaption || this->m_bPaused )
    return 0.0;
  v2 = _Plat_FloatTime(a1: v8);
  m_CurCaptionStartTime = this->m_CurCaptionStartTime;
  v4 = cheap_captions_fadetime.m_pParent->m_Value.m_fValue + m_CurCaptionStartTime;
  val = v2 - this->m_flTotalPauseTime - this->m_CaptionStartTime;
  if ( m_CurCaptionStartTime == v4 )
  {
    if ( (float)(val - v4) < 0.0 )
      C = 0.0;
    else
      C = 255.0;
  }
  else
  {
    v6 = (float)(val - m_CurCaptionStartTime) / (float)(v4 - m_CurCaptionStartTime);
    if ( v6 >= 0.0 )
    {
      if ( v6 > 1.0 )
        v6 = 1.0;
    }
    else
    {
      v6 = 0.0;
    }
    C = v6 * 255.0;
  }
  return RemapValClamped(
           val,
           A: this->m_CurCaptionEndTime - cheap_captions_fadetime.m_pParent->m_Value.m_fValue,
           B: this->m_CurCaptionEndTime,
           C,
           D: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10178D30
// Name: protected: virtual void CSubtitlePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtitlePanel::OnThink(CSubtitlePanel *this)
{
  const char *CurrentCaption; // edi
  int m_nValue; // eax
  float v4; // xmm0_4
  char v5; // al
  int v6; // ecx
  char v7; // dh
  vgui::Label *m_pSubtitleLabel; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // eax
  float Alpha; // [esp+Ch] [ebp-8h]
  int nColor; // [esp+10h] [ebp-4h] BYREF

  nColor = -1;
  CurrentCaption = CCaptionSequencer::GetCurrentCaption(this: &this->m_Captions, pColorOut: &nColor);
  this->m_pSubtitleLabel->SetText(this: this->m_pSubtitleLabel, a2: CurrentCaption);
  if ( cheap_captions_test.m_pParent != nullptr && cheap_captions_test.m_pParent->m_Value.m_nValue != 0
    || (closecaption.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = closecaption.m_pParent->m_Value.m_nValue),
        m_nValue != 0) )
  {
    Alpha = CCaptionSequencer::GetAlpha(this: &this->m_Captions);
    v4 = Alpha;
  }
  else
  {
    v4 = 0.0;
  }
  vgui::Panel::SetAlpha(this, alpha: (int)v4);
  if ( CurrentCaption != nullptr )
  {
    v5 = nColor;
    v6 = nColor;
    LOBYTE(nColor) = HIBYTE(nColor);
    v7 = BYTE1(v6);
    BYTE1(nColor) = BYTE2(v6);
    m_pSubtitleLabel = this->m_pSubtitleLabel;
    HIBYTE(nColor) = v5;
    SetFgColor = m_pSubtitleLabel->SetFgColor;
    BYTE2(nColor) = v7;
    ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pSubtitleLabel, a2: nColor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178DF0
// Name: public: void CCaptionSequencer::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCaptionSequencer::Reset(CCaptionSequencer *this)
{
  this->m_CaptionStartTime = 0.0;
  this->m_flPauseTime = 0.0;
  this->m_flTotalPauseTime = 0.0;
  this->m_bPaused = false;
  *(_WORD *)&this->m_bShowingCaption = 256;
  this->m_CurCaptionString[0] = 0;
  this->m_CurCaptionStartTime = 0.0;
  this->m_CurCaptionEndTime = 0.0;
  this->m_CurCaptionColor = -1;
  if ( this->m_CaptionBuf.m_Put != 0 )
  {
    CUtlBuffer::SeekGet(this: &this->m_CaptionBuf, type: SEEK_HEAD, offset: 0);
  }
  else
  {
    this->m_CaptionBuf.m_Get = 0;
    this->m_CaptionBuf.m_Put = 0;
    this->m_CaptionBuf.m_nOffset = 0;
    this->m_CaptionBuf.m_nMaxPut = 0;
    this->m_CaptionBuf.m_Error = 0;
    if ( this->m_CaptionBuf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_CaptionBuf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CaptionBuf.m_Memory.m_pMemory);
        this->m_CaptionBuf.m_Memory.m_pMemory = nullptr;
      }
      this->m_CaptionBuf.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178E70
// Name: public: CSubtitlePanel::CSubtitlePanel(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSubtitlePanel *__thiscall CSubtitlePanel::CSubtitlePanel(
        CSubtitlePanel *this,
        vgui::Panel *pParent,
        char *pCaptionFile,
        int nPlaybackHeight)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int Wide; // ebx
  unsigned int v9; // eax
  vgui::IScheme *v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  unsigned int m_hFont; // ecx
  char *v14; // ebx
  const char *v15; // ecx
  int v17; // [esp-4h] [ebp-118h]
  BOOL m_bCaptions; // [esp-4h] [ebp-118h]
  char captionFilename[260]; // [esp+Ch] [ebp-108h] BYREF
  int nWidth; // [esp+110h] [ebp-4h]
  const char *pFixedCaptionFile; // [esp+11Ch] [ebp+8h]

  vgui::Panel::Panel(this, parent: pParent, panelName: "SubtitlePanel");
  this->__vftable = (CSubtitlePanel_vtbl *)&CSubtitlePanel::`vftable';
  if ( `CSubtitlePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSubtitlePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSubtitlePanel");
    v5->pfnClassName = CSubtitlePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CSubtitlePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSubtitlePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSubtitlePanel");
    v6->pfnClassName = CSubtitlePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CSubtitlePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSubtitlePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSubtitlePanel");
    v7->pfnClassName = CSubtitlePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_Captions.m_bCaptions = false;
  CUtlBuffer::CUtlBuffer(this: &this->m_Captions.m_CaptionBuf, growSize: 0, initSize: 0, nFlags: 0);
  CCaptionSequencer::Reset(this: &this->m_Captions);
  vgui::Panel::SetScheme(this, tag: "basemodui_scheme");
  vgui::Panel::SetProportional(this, state: true);
  Wide = vgui::Panel::GetWide(this: pParent);
  pFixedCaptionFile = (const char *)vgui::Panel::GetTall(this: pParent);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: Wide, tall: (int)pFixedCaptionFile);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  this->m_hFont = 0;
  v9 = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "basemodui_scheme");
  v10 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v9);
  if ( v10 != nullptr )
    this->m_hFont = v10->GetFont(this: v10, a2: "CloseCaption_Normal", a3: true);
  this->m_nFontTall = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
  v11 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v11 != nullptr )
    v12 = vgui::Label::Label(this: v11, parent: this, panelName: "SubtitleLabel", wszText: &szFunFact);
  else
    v12 = nullptr;
  m_hFont = this->m_hFont;
  this->m_pSubtitleLabel = v12;
  v12->SetFont(this: v12, a2: m_hFont);
  v17 = (int)(float)((float)((float)nPlaybackHeight * 0.85000002)
                   - (float)((nPlaybackHeight - (int)pFixedCaptionFile) / 2))
      - 10 * this->m_nFontTall;
  nWidth = (int)(float)((float)Wide * 0.60000002);
  vgui::Panel::SetPos(this: this->m_pSubtitleLabel, x: (Wide - nWidth) / 2, y: v17);
  vgui::Panel::SetTall(this: this->m_pSubtitleLabel, tall: 10 * this->m_nFontTall);
  vgui::Panel::SetWide(this: this->m_pSubtitleLabel, wide: nWidth);
  this->m_pSubtitleLabel->SetContentAlignment(this: this->m_pSubtitleLabel, a2: a_south);
  vgui::Label::SetWrap(this: this->m_pSubtitleLabel, bWrap: true);
  v14 = pCaptionFile;
  if ( V_stristr(a1: v15, a2: pCaptionFile, pStr: pCaptionFile, pSearch: ".txt") == nullptr )
  {
    V_StripExtension(in: pCaptionFile, out: captionFilename, outSize: 260);
    V_strncat(pDest: captionFilename, pSrc: "_captions.txt", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v14 = captionFilename;
  }
  CCaptionSequencer::Reset(this: &this->m_Captions);
  this->m_Captions.m_bCaptions = false;
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: v14,
         a3: "GAME",
         a4: &this->m_Captions.m_CaptionBuf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    this->m_Captions.m_bCaptions = true;
  }
  m_bCaptions = this->m_Captions.m_bCaptions;
  this->m_bHasCaptions = m_bCaptions;
  vgui::Panel::SetVisible(this, state: m_bCaptions);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10179180
// Name: public: virtual struct vgui::PanelMessageMap __near * CSubtitlePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSubtitlePanel::GetMessageMap(CSubtitlePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSubtitlePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSubtitlePanel::GetMessageMap'::`2'::s_pMap;
  `CSubtitlePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSubtitlePanel");
  `CSubtitlePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101791B0
// Name: public: virtual struct PanelAnimationMap __near * CSubtitlePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSubtitlePanel::GetAnimMap(CSubtitlePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSubtitlePanel");
}

//------------------------------------------------------------------------------
// Address: 0x101791C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSubtitlePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSubtitlePanel::GetKBMap(CSubtitlePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSubtitlePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSubtitlePanel::GetKBMap'::`2'::s_pMap;
  `CSubtitlePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSubtitlePanel");
  `CSubtitlePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}
