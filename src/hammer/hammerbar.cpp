// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/hammerbar.cpp
// Functions: 362
// ============================================================

#include "hammer\hammerbar.h"

//------------------------------------------------------------------------------
// Address: 0x100D01A0
// Name: public: virtual int CDialogBar::Create(class CWnd __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialogBar::Create(
        CDialogBar *this,
        CWnd *pParentWnd,
        unsigned __int16 nIDTemplate,
        unsigned int nStyle,
        unsigned int nID)
{
  return this->Create(this, a2: pParentWnd, a3: (const char *)nIDTemplate, a4: nStyle, a5: nID);
}

//------------------------------------------------------------------------------
// Address: 0x100D01D0
// Name: protected: int CHammerBar::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammerBar::OnSetCursor(CHammerBar *this, CWnd *pWnd, CWnd *nHitTest, unsigned int message)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  HWND v8; // eax
  CWnd *v9; // eax

  ModuleState = AfxGetModuleState();
  if ( CHammer::IsActiveApp(this: (CHammer *)ModuleState->m_pCurrentWinApp) )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    if ( v7 != nullptr )
    {
      v8 = GetParent(hWnd: v7->m_hWnd);
      v9 = CWnd::FromHandle(hWnd: v8);
      if ( v9 != nullptr )
        BringWindowToTop(hWnd: v9->m_hWnd);
    }
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D0230
// Name: public: virtual int CHammerBar::Create(class CWnd __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammerBar::Create(
        CHammerBar *this,
        CWnd *pParentWnd,
        unsigned __int16 nIDTemplate,
        unsigned int nStyle,
        unsigned int nID)
{
  int result; // eax
  int cy; // edx
  int cx; // eax

  result = this->Create(this, a2: pParentWnd, a3: (const char *)nIDTemplate, a4: nStyle & 0xFFFFFFFB, a5: nID);
  if ( result != 0 )
  {
    cy = this->m_sizeDefault.cy;
    cx = this->m_sizeDefault.cx;
    this->m_sizeDocked.cx = cx;
    this->m_sizeFloating.cx = cx;
    this->m_sizeDocked.cy = cy;
    this->m_sizeFloating.cy = cy;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D02A0
// Name: public: void CHammerBar::AdjustControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerBar::AdjustControls(CHammerBar *this)
{
  ControlInfo_t *v2; // eax
  CWnd *DlgItem; // esi
  HWND v4; // [esp-Ch] [ebp-6Ch]
  HWND v5; // [esp-Ch] [ebp-6Ch]
  HWND__ *m_hWnd; // [esp-8h] [ebp-68h]
  __int64 currentControl; // [esp+8h] [ebp-58h]
  __int64 currentControl_8; // [esp+10h] [ebp-50h]
  __int64 currentControl_16; // [esp+18h] [ebp-48h]
  tagRECT Rect; // [esp+20h] [ebp-40h] BYREF
  CRect controlPos; // [esp+30h] [ebp-30h] BYREF
  CRect HammerBarPos; // [esp+40h] [ebp-20h] BYREF
  int nHammerBarWidth; // [esp+50h] [ebp-10h]
  int nHammerBarHeight; // [esp+54h] [ebp-Ch]
  int iControl; // [esp+58h] [ebp-8h]
  unsigned int v16; // [esp+5Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  memset(&HammerBarPos, 0, sizeof(HammerBarPos));
  GetWindowRect(hWnd: m_hWnd, lpRect: &HammerBarPos);
  iControl = 0;
  nHammerBarHeight = HammerBarPos.bottom - HammerBarPos.top;
  nHammerBarWidth = HammerBarPos.right - HammerBarPos.left;
  if ( this->m_ControlList.m_Size > 0 )
  {
    v16 = 0;
    do
    {
      v2 = &this->m_ControlList.m_Memory.m_pMemory[v16 / 0x18];
      currentControl = *(_QWORD *)&v2->m_nIDDialogItem;
      currentControl_8 = *(_QWORD *)&v2->m_nWidthBuffer;
      currentControl_16 = *(_QWORD *)&v2->m_nPosX;
      DlgItem = CWnd::GetDlgItem(this, nID: v2->m_nIDDialogItem);
      if ( DlgItem != nullptr )
      {
        if ( (currentControl & 0x400000000LL) != 0 )
          CWnd::SetWindowPos(
            this: DlgItem,
            pWndInsertAfter: nullptr,
            x: 0,
            y: 0,
            cx: nHammerBarWidth - currentControl_8,
            cy: nHammerBarHeight - HIDWORD(currentControl_8),
            nFlags: 6u);
        if ( (currentControl & 0x200000000LL) != 0 )
        {
          v4 = DlgItem->m_hWnd;
          memset(&controlPos, 0, sizeof(controlPos));
          GetWindowRect(hWnd: v4, lpRect: &controlPos);
          CWnd::SetWindowPos(
            this: DlgItem,
            pWndInsertAfter: nullptr,
            x: controlPos.left - HammerBarPos.left,
            y: HammerBarPos.bottom - HammerBarPos.top - HIDWORD(currentControl_16),
            cx: 0,
            cy: 0,
            nFlags: 5u);
        }
        if ( (currentControl & 0x100000000LL) != 0 )
        {
          v5 = DlgItem->m_hWnd;
          memset(&Rect, 0, sizeof(Rect));
          GetWindowRect(hWnd: v5, lpRect: &Rect);
          CWnd::SetWindowPos(
            this: DlgItem,
            pWndInsertAfter: nullptr,
            x: HammerBarPos.right - currentControl_16 - HammerBarPos.left,
            y: Rect.top - HammerBarPos.top,
            cx: 0,
            cy: 0,
            nFlags: 5u);
        }
      }
      v16 += 24;
      ++iControl;
    }
    while ( iControl < this->m_ControlList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D03F0
// Name: protected: virtual struct AFX_MSGMAP const __near * CHammerBar::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CHammerBar::GetMessageMap(CHammerBar *this)
{
  return &messageMap_5;
}

//------------------------------------------------------------------------------
// Address: 0x100D0400
// Name: public: virtual void CHammerBar::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerBar::OnSize(CHammerBar *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
  CHammerBar::AdjustControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D0420
// Name: public: virtual CHammerBar::~CHammerBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerBar::~CHammerBar(CHammerBar *this)
{
  CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int> > *p_m_ControlList; // esi

  this->__vftable = (CHammerBar_vtbl *)&CHammerBar::`vftable';
  p_m_ControlList = &this->m_ControlList;
  this->m_ControlList.m_Size = 0;
  this->m_ControlList.m_Size = 0;
  if ( this->m_ControlList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ControlList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ControlList->m_Memory.m_pMemory);
      p_m_ControlList->m_Memory.m_pMemory = nullptr;
    }
    p_m_ControlList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_ControlList->m_pElements = p_m_ControlList->m_Memory.m_pMemory;
  if ( p_m_ControlList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ControlList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ControlList->m_Memory.m_pMemory);
      p_m_ControlList->m_Memory.m_pMemory = nullptr;
    }
    p_m_ControlList->m_Memory.m_nAllocationCount = 0;
  }
  CDialogBar::~CDialogBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D04D0
// Name: public: void CHammerBar::AddControl(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerBar::AddControl(CHammerBar *this, int nIDTemplate, unsigned int dwPlacementFlag)
{
  CWnd *DlgItem; // eax
  int v5; // eax
  int v6; // ebx
  HWND m_hWnd; // [esp-10h] [ebp-4Ch]
  int m_Size; // [esp-10h] [ebp-4Ch]
  ControlInfo_t newControl; // [esp+4h] [ebp-38h] BYREF
  CRect hammerBarPos; // [esp+1Ch] [ebp-20h] BYREF
  CRect controlPos; // [esp+2Ch] [ebp-10h] BYREF

  newControl.m_dwPlacementFlag = dwPlacementFlag;
  newControl.m_nIDDialogItem = nIDTemplate;
  DlgItem = CWnd::GetDlgItem(this, nID: nIDTemplate);
  if ( DlgItem != nullptr )
  {
    m_hWnd = DlgItem->m_hWnd;
    memset(&controlPos, 0, sizeof(controlPos));
    memset(&hammerBarPos, 0, sizeof(hammerBarPos));
    GetWindowRect(hWnd: m_hWnd, lpRect: &controlPos);
    GetWindowRect(hWnd: this->m_hWnd, lpRect: &hammerBarPos);
    v5 = hammerBarPos.top + this->m_sizeDefault.cy - controlPos.top;
    newControl.m_nHeightBuffer = controlPos.top + this->m_sizeDefault.cy - controlPos.bottom;
    v6 = this->m_sizeDefault.cx - controlPos.right;
    newControl.m_nPosX = hammerBarPos.left + this->m_sizeDefault.cx - controlPos.left;
    newControl.m_nPosY = v5;
    m_Size = this->m_ControlList.m_Size;
    newControl.m_nWidthBuffer = controlPos.left + v6;
    CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
      this: (CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *)&this->m_ControlList,
      elem: m_Size,
      src: (const CTrackEntry *)&newControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0580
// Name: public: virtual class CSize CHammerBar::CalcDynamicLayout(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
CSize *__thiscall CHammerBar::CalcDynamicLayout(CHammerBar *this, CSize *result, const char *nLength, char dwMode)
{
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  ATL::CStringData *v9; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v11; // eax
  const char *v12; // eax
  int cy; // ecx
  int cx; // edx

  if ( (dwMode & 0x18) != 0 )
  {
    cy = this->m_sizeFloating.cy;
    cx = this->m_sizeDocked.cx;
    this->m_sizeDocked.cy = cy;
    result->cy = cy;
    result->cx = cx;
    return result;
  }
  else if ( (dwMode & 4) != 0 )
  {
    v6 = this->m_sizeFloating.cy;
    result->cx = this->m_sizeFloating.cx;
    result->cy = v6;
    return result;
  }
  else
  {
    if ( (dwMode & 0x20) != 0 )
    {
      v7 = (int)nLength;
      v8 = this->m_sizeFloating.cx;
      this->m_sizeFloating.cy = (int)nLength;
    }
    else
    {
      v8 = (int)nLength;
      v7 = this->m_sizeFloating.cy;
      this->m_sizeFloating.cx = (int)nLength;
    }
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nLength);
    CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nLength);
    if ( *((_DWORD *)nLength - 3) != 0 )
    {
      v9 = (ATL::CStringData *)ATL::operator+(
                                 result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&dwMode,
                                 psz1: "FloatingBarSize\\",
                                 str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nLength);
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&nLength, strSrc: v9);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&dwMode);
      ModuleState = AfxGetModuleState();
      ModuleState->m_pCurrentWinApp->WriteProfileInt(
        this: ModuleState->m_pCurrentWinApp,
        a2: nLength,
        a3: "floatX",
        a4: v8);
      v11 = AfxGetModuleState();
      v11->m_pCurrentWinApp->WriteProfileInt(this: v11->m_pCurrentWinApp, a2: nLength, a3: "floatY", a4: v7);
    }
    result->cx = v8;
    result->cy = v7;
    v12 = nLength - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)nLength - 1) <= 0 )
      (*(void (__stdcall **)(const char *))(**(_DWORD **)v12 + 4))(a1: v12);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0700
// Name: public: int CHammerBar::Create(class CWnd __near *,unsigned int,unsigned int,unsigned int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammerBar::Create(
        CHammerBar *this,
        CWnd *pParentWnd,
        unsigned int nIDTemplate,
        unsigned int nStyle,
        const char *nID,
        char *pszName)
{
  const char *v6; // edi
  int result; // eax
  CAfxStringMgr *StringManager; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v10; // eax
  ATL::CStringData *v11; // eax
  int v12; // eax
  int v13; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  unsigned int v15; // edi
  AFX_MODULE_STATE *v16; // eax
  int v17; // eax
  int cy; // ecx

  v6 = pszName;
  if ( *pszName == 0 )
    return this->Create(this, a2: pParentWnd, a3: nIDTemplate, a4: nStyle, a5: (unsigned int)nID);
  result = this->Create(
             this,
             a2: pParentWnd,
             a3: (const char *)(unsigned __int16)nIDTemplate,
             a4: nStyle,
             a5: (unsigned int)nID);
  if ( result != 0 )
  {
    CWnd::SetWindowTextA(this, lpszString: v6);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    nID = (const char *)&StringManager->GetNilString(this: StringManager)[1];
    v10 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nIDTemplate,
            pszSrc: v6);
    v11 = (ATL::CStringData *)ATL::operator+(
                                result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nStyle,
                                psz1: "FloatingBarSize\\",
                                str2: v10);
    ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&nID, strSrc: v11);
    v12 = nStyle - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)(nStyle - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v12 + 4))(a1: v12);
    v13 = nIDTemplate - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)(nIDTemplate - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v13 + 4))(a1: v13);
    ModuleState = AfxGetModuleState();
    v15 = (unsigned int)nID;
    this->m_sizeFloating.cx = ModuleState->m_pCurrentWinApp->GetProfileIntA(
                                this: ModuleState->m_pCurrentWinApp,
                                a2: nID,
                                a3: "floatX",
                                a4: this->m_sizeDefault.cx);
    v16 = AfxGetModuleState();
    v17 = v16->m_pCurrentWinApp->GetProfileIntA(
            this: v16->m_pCurrentWinApp,
            a2: (const char *)v15,
            a3: "floatY",
            a4: this->m_sizeDefault.cy);
    cy = this->m_sizeDefault.cy;
    this->m_sizeFloating.cy = v17;
    this->m_sizeDocked.cx = this->m_sizeDefault.cx;
    this->m_sizeDocked.cy = cy;
    if ( _InterlockedDecrement((volatile signed __int32 *)(v15 - 16 + 12)) <= 0 )
      (*(void (__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(v15 - 16) + 4))(
        a1: *(_DWORD *)(v15 - 16),
        a2: v15 - 16);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103378C6
// Name: protected: int CSplitterWnd::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::OnSetCursor(
        CSplitterWnd *this,
        CSplitterWnd *pWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  int result; // eax

  result = 1;
  if ( nHitTest != 1 || pWnd != this || this->m_bTracking != 0 )
    return CWnd::Default(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10340147
// Name: protected: int CFrameWnd::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnSetCursor(CFrameWnd *this, CWnd *pWnd, CWnd *nHitTest, unsigned int message)
{
  CFrameWnd *TopLevelFrame; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame == nullptr )
    AfxThrowInvalidArgException();
  if ( TopLevelFrame->m_bHelpMode == 0 )
    return CWnd::Default(this);
  SetCursor(hCursor: afxData.hcurHelp);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10356DE8
// Name: public: virtual int CControlBar::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CControlBar::PreCreateWindow(CControlBar *this, tagCREATESTRUCTA *cs)
{
  int result; // eax
  unsigned int m_dwStyle; // eax
  unsigned int v5; // ecx
  int v6; // ecx

  result = CWnd::PreCreateWindow(this, cs);
  if ( result != 0 )
  {
    cs->style |= 0x4000000u;
    m_dwStyle = this->m_dwStyle;
    if ( (m_dwStyle & 0x80u) == 0 )
    {
      v5 = this->m_dwStyle & 0xFF00;
      switch ( v5 )
      {
        case 0x1400u:
          goto LABEL_9;
        case 0x2800u:
          v6 = 512;
          goto LABEL_10;
        case 0x4100u:
LABEL_9:
          v6 = 2560;
          goto LABEL_10;
        case 0x8200u:
          v6 = 2048;
LABEL_10:
          this->m_dwStyle = v6 | m_dwStyle & 0xFFFFF0FF | 0x80;
          break;
        default:
          break;
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10356F15
// Name: public: virtual class CSize CControlBar::CalcDynamicLayout(int,unsigned long)
// Source: rtti_class
//------------------------------------------------------------------------------
CSize *__thiscall CControlBar::CalcDynamicLayout(CControlBar *this, CSize *result, int __formal, char nMode)
{
  this->CalcFixedLayout(this, result, a3: nMode & 1, a4: nMode & 2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10356FF8
// Name: public: virtual int CControlBar::DestroyWindow(void)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CControlBar::DestroyWindow(CControlBar *this)
{
  CFrameWnd *DockingFrame; // eax

  if ( this->m_hWnd == nullptr || CControlBar::IsFloating(this) == 0 )
    return CWnd::DestroyWindow(this);
  DockingFrame = CControlBar::GetDockingFrame(this);
  return DockingFrame->DestroyWindow(this: DockingFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1035706C
// Name: public: virtual unsigned long CControlBar::RecalcDelayShow(struct AFX_SIZEPARENTPARAMS __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
unsigned int __thiscall CControlBar::RecalcDelayShow(CControlBar *this, AFX_SIZEPARENTPARAMS *lpLayout)
{
  unsigned int v3; // ebx
  unsigned int m_nStateFlags; // eax
  int v5; // edx
  HWND__ *m_hWnd; // [esp-1Ch] [ebp-28h]

  if ( lpLayout == nullptr )
    AfxThrowInvalidArgException();
  v3 = this->m_dwStyle & 0xFF00 | CWnd::GetStyle(this) & 0x10000000;
  m_nStateFlags = this->m_nStateFlags;
  if ( (m_nStateFlags & 3) != 0 )
  {
    if ( (m_nStateFlags & 1) != 0 )
    {
      if ( (v3 & 0x10000000) != 0 )
      {
        v5 = 128;
        goto LABEL_9;
      }
    }
    else if ( (v3 & 0x10000000) == 0 )
    {
      v5 = 64;
LABEL_9:
      v3 ^= 0x10000000u;
      if ( lpLayout->hDWP != nullptr )
      {
        m_hWnd = this->m_hWnd;
        this->m_nStateFlags = m_nStateFlags & 0xFFFFFFFC;
        lpLayout->hDWP = DeferWindowPos(
                           hWinPosInfo: lpLayout->hDWP,
                           hWnd: m_hWnd,
                           hWndInsertAfter: nullptr,
                           x: 0,
                           y: 0,
                           cx: 0,
                           cy: 0,
                           uFlags: v5 | 0x17);
      }
      return v3;
    }
    this->m_nStateFlags = m_nStateFlags & 0xFFFFFFFC;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103570F8
// Name: public: virtual void CControlBar::DelayShow(int)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CControlBar::DelayShow(CControlBar *this, int bShow)
{
  unsigned int Style; // eax

  this->m_nStateFlags &= 0xFFFFFFFC;
  Style = CWnd::GetStyle(this);
  if ( bShow != 0 )
  {
    if ( (Style & 0x10000000) == 0 )
      this->m_nStateFlags |= 2u;
  }
  else if ( (Style & 0x10000000) != 0 )
  {
    this->m_nStateFlags |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10357135
// Name: public: virtual int CControlBar::IsVisible(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
BOOL __thiscall CControlBar::IsVisible(CControlBar *this)
{
  unsigned int m_nStateFlags; // eax

  m_nStateFlags = this->m_nStateFlags;
  return (m_nStateFlags & 1) == 0 && ((m_nStateFlags & 2) != 0 || (CWnd::GetStyle(this) & 0x10000000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10357156
// Name: public: virtual void CControlBar::DrawGripper(class CDC __near *,class CRect const __near &)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CControlBar::DrawGripper(CControlBar *this, CDC *pDC, const CRect *rect)
{
  if ( pDC == nullptr )
    AfxThrowInvalidArgException();
  if ( (this->m_dwStyle & 0x400001) == 0x400000 && this->DrawThemedGripper(this, a2: pDC, a3: rect, a4: 0) == 0 )
    this->DrawNonThemedGripper(this, a2: pDC, a3: rect);
}

//------------------------------------------------------------------------------
// Address: 0x103571A4
// Name: public: virtual void CControlBar::DrawNCGripper(class CDC __near *,class CRect const __near &)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CControlBar::DrawNCGripper(CControlBar *this, CDC *pDC, const CRect *rect)
{
  if ( pDC == nullptr )
    AfxThrowInvalidArgException();
  if ( (this->m_dwStyle & 0x400001) == 0x400000 && this->DrawThemedGripper(this, a2: pDC, a3: rect, a4: 1) == 0 )
    this->DrawNonThemedGripper(this, a2: pDC, a3: rect);
}

//------------------------------------------------------------------------------
// Address: 0x103571F2
// Name: public: virtual void CControlBar::CalcInsideRect(class CRect __near &,int)const
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CControlBar::CalcInsideRect(CControlBar *this, CRect *rect, int bHorz)
{
  unsigned int m_dwStyle; // edx

  m_dwStyle = this->m_dwStyle;
  if ( (m_dwStyle & 0x100) != 0 )
    rect->left += afxData.cxBorder2;
  if ( (m_dwStyle & 0x200) != 0 )
    rect->top += afxData.cyBorder2;
  if ( (m_dwStyle & 0x400) != 0 )
    rect->right -= afxData.cxBorder2;
  if ( (m_dwStyle & 0x800) != 0 )
    rect->bottom -= afxData.cyBorder2;
  if ( bHorz != 0 )
  {
    rect->left += this->m_cxLeftBorder;
    rect->top += this->m_cyTopBorder;
    rect->right -= this->m_cxRightBorder;
    rect->bottom -= this->m_cyBottomBorder;
    if ( (this->m_dwStyle & 0x400001) == 0x400000 )
      rect->left += 7;
  }
  else
  {
    rect->left += this->m_cyTopBorder;
    rect->top += this->m_cxLeftBorder;
    rect->right -= this->m_cyBottomBorder;
    rect->bottom -= this->m_cxRightBorder;
    if ( (this->m_dwStyle & 0x400001) == 0x400000 )
      rect->top += 7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10357A06
// Name: public: virtual void CControlBar::DoPaint(class CDC __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CControlBar::DoPaint(CControlBar *this, CDC *pDC)
{
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  this->DrawBorders(this, a2: pDC, a3: &rect);
  this->DrawGripper(this, a2: pDC, a3: &rect);
}

//------------------------------------------------------------------------------
// Address: 0x10357A68
// Name: public: virtual void CControlBar::DrawBorders(class CDC __near *,class CRect __near &)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CControlBar::DrawBorders(CControlBar *this, CDC *pDC, CRect *rect)
{
  unsigned int m_dwStyle; // eax
  void *m_hReBarTheme; // eax
  CDC *v5; // esi
  COLORREF BkColor; // eax
  COLORREF clrBtnHilite; // edi
  int rect1_8; // [esp+Ch] [ebp-48h]
  int rect1_12; // [esp+10h] [ebp-44h]
  __int16 dwStyle; // [esp+14h] [ebp-40h]
  int v11; // [esp+18h] [ebp-3Ch]
  int rect2_4; // [esp+20h] [ebp-34h]
  int rect2_12; // [esp+28h] [ebp-2Ch]
  COLORREF clr; // [esp+2Ch] [ebp-28h]
  int v15; // [esp+30h] [ebp-24h]
  int v16; // [esp+34h] [ebp-20h]
  CRect rctBk; // [esp+40h] [ebp-14h] BYREF

  m_dwStyle = this->m_dwStyle;
  dwStyle = m_dwStyle;
  if ( (m_dwStyle & 0xF00) == 0 )
    return;
  rect1_8 = rect->right;
  rect1_12 = rect->bottom;
  rect2_4 = rect->top;
  v11 = m_dwStyle & 0x80;
  rect2_12 = rect1_12;
  clr = afxData.clrBtnShadow;
  if ( (m_dwStyle & 0x80) != 0 )
  {
    --rect1_8;
    --rect1_12;
  }
  v15 = m_dwStyle & 0x200;
  if ( (m_dwStyle & 0x200) != 0 )
    rect2_4 += afxData.cyBorder2;
  v16 = m_dwStyle & 0x800;
  if ( (m_dwStyle & 0x800) != 0 )
    rect2_12 -= afxData.cyBorder2;
  if ( CObject::IsKindOf(this, pClass: &CToolBar::classCToolBar) != 0 && v16 != 0 )
  {
    rctBk.right = rect->right;
    rctBk.top = rect->top;
    rctBk.bottom = rect->bottom;
    m_hReBarTheme = this->m_hReBarTheme;
    rctBk.left = 0;
    if ( m_hReBarTheme != nullptr )
    {
      v5 = pDC;
      if ( CThemeHelper::IsThemeBackgroundPartiallyTransparent(hTheme: m_hReBarTheme, nPartId: 6, nStateId: 0) != 0 )
        CThemeHelper::DrawThemeParentBackground(hwnd: this->m_hWnd, hdc: pDC->m_hDC, prc: &rctBk);
      if ( CThemeHelper::DrawThemeBackground(
             hTheme: this->m_hReBarTheme,
             hdc: pDC->m_hDC,
             nPartId: 6,
             nStateId: 0,
             pRect: &rctBk,
             pClipRect: nullptr) >= 0 )
        goto LABEL_18;
    }
    else
    {
      v5 = pDC;
    }
    BkColor = GetBkColor(hdc: v5->m_hAttribDC);
    CDC::FillSolidRect(this: v5, lpRect: &rctBk, clr: BkColor);
  }
  else
  {
    v5 = pDC;
  }
LABEL_18:
  if ( (dwStyle & 0x100) != 0 )
    CDC::FillSolidRect(this: v5, x: 0, y: rect2_4, cx: 1, cy: rect2_12 - rect2_4, clr);
  if ( v15 != 0 )
    CDC::FillSolidRect(this: v5, x: 0, y: 0, cx: rect->right, cy: 1, clr);
  if ( (dwStyle & 0x400) != 0 )
    CDC::FillSolidRect(this: v5, x: rect1_8, y: rect2_4, cx: -1, cy: rect2_12 - rect2_4, clr);
  if ( v16 != 0 )
    CDC::FillSolidRect(this: v5, x: 0, y: rect1_12, cx: rect->right, cy: -1, clr);
  if ( v11 != 0 )
  {
    clrBtnHilite = afxData.clrBtnHilite;
    if ( (dwStyle & 0x100) != 0 )
      CDC::FillSolidRect(this: v5, x: 1, y: rect2_4, cx: 1, cy: rect2_12 - rect2_4, clr: afxData.clrBtnHilite);
    if ( v15 != 0 )
      CDC::FillSolidRect(this: v5, x: 0, y: 1, cx: rect->right, cy: 1, clr: clrBtnHilite);
    if ( (dwStyle & 0x400) != 0 )
      CDC::FillSolidRect(this: v5, x: rect->right, y: rect2_4, cx: -1, cy: rect2_12 - rect2_4, clr: clrBtnHilite);
    if ( v16 != 0 )
      CDC::FillSolidRect(this: v5, x: 0, y: rect->bottom, cx: rect->right, cy: -1, clr: clrBtnHilite);
  }
  if ( (dwStyle & 0x100) != 0 )
    rect->left += afxData.cxBorder2;
  if ( v15 != 0 )
    rect->top += afxData.cyBorder2;
  if ( (dwStyle & 0x400) != 0 )
    rect->right -= afxData.cxBorder2;
  if ( v16 != 0 )
    rect->bottom -= afxData.cyBorder2;
}

//------------------------------------------------------------------------------
// Address: 0x10357CCB
// Name: public: virtual int CControlBar::DrawNonThemedGripper(class CDC __near *,class CRect const __near &)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CControlBar::DrawNonThemedGripper(CControlBar *this, CDC *pDC, const CRect *rect)
{
  int m_cyTopBorder; // edx

  if ( pDC == nullptr )
    AfxThrowInvalidArgException();
  m_cyTopBorder = this->m_cyTopBorder;
  if ( (this->m_dwStyle & 0xA000) != 0 )
    CDC::Draw3dRect(
      this: pDC,
      x: rect->left + 2,
      y: m_cyTopBorder + rect->top,
      cx: 3,
      cy: rect->bottom - this->m_cyBottomBorder - rect->top - m_cyTopBorder,
      clrTopLeft: afxData.clrBtnHilite,
      clrBottomRight: afxData.clrBtnShadow);
  else
    CDC::Draw3dRect(
      this: pDC,
      x: rect->left + m_cyTopBorder,
      y: rect->top + 2,
      cx: rect->right - this->m_cyBottomBorder - m_cyTopBorder - rect->left,
      cy: 3,
      clrTopLeft: afxData.clrBtnHilite,
      clrBottomRight: afxData.clrBtnShadow);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10357D49
// Name: public: virtual int CControlBar::DrawThemedGripper(class CDC __near *,class CRect const __near &,int)
// Source: rtti_class
//------------------------------------------------------------------------------
BOOL __thiscall CControlBar::DrawThemedGripper(CControlBar *this, CDC *pDC, const CRect *rect, int fCentered)
{
  CDC *v4; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int top; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int m_cyTopBorder; // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-64h]
  int nPartId; // [esp+10h] [ebp-4Ch]
  int left; // [esp+14h] [ebp-48h]
  int v21; // [esp+14h] [ebp-48h]
  CRect rectClient; // [esp+18h] [ebp-44h] BYREF
  tagRECT rectGripper; // [esp+28h] [ebp-34h] BYREF
  CRect clipRect; // [esp+38h] [ebp-24h] BYREF
  tagSIZE size; // [esp+48h] [ebp-14h] BYREF
  tagSIZE psz; // [esp+50h] [ebp-Ch] BYREF

  v4 = pDC;
  if ( pDC == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_hReBarTheme == nullptr )
    return false;
  memset(&rectClient, 0, sizeof(rectClient));
  memset(&clipRect, 0, sizeof(clipRect));
  if ( fCentered != 0 )
  {
    GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
    m_hWnd = this->m_hWnd;
    size.cx = 0;
    size.cy = 0;
    psz.cx = 0;
    psz.cy = 0;
    GetWindowRect(hWnd: m_hWnd, lpRect: (LPRECT)&size);
    CWnd::ScreenToClient(this, lpRect: (tagRECT *)&size);
    OffsetRect(lprc: &rectClient, dx: -size.cx, dy: -size.cy);
    v4 = pDC;
  }
  if ( (this->m_dwStyle & 0xA000) == 0 )
  {
    nPartId = 1;
    if ( CThemeHelper::GetThemePartSize(
           hTheme: this->m_hReBarTheme,
           hdc: v4->m_hDC,
           nPartId: 1,
           nStateId: 0,
           pRect: nullptr,
           eSize: TS_TRUE,
           &psz) >= 0 )
    {
      if ( fCentered != 0 )
      {
        top = rect->top;
        v14 = rectClient.top - top;
        v21 = top;
        if ( rectClient.top - top < psz.cy )
          --v14;
        v15 = top + (v14 - psz.cy) / 2;
      }
      else
      {
        v15 = rect->top;
        v21 = v15;
      }
      v16 = rect->right - this->m_cyBottomBorder;
      m_cyTopBorder = this->m_cyTopBorder;
      rectGripper.top = v15;
      rectGripper.left = m_cyTopBorder + rect->left;
      rectGripper.bottom = v15 + psz.cy;
      clipRect.top = v21;
      v12 = rectClient.top;
      rectGripper.right = v16;
      clipRect.left = rectGripper.left;
      clipRect.right = v16;
      goto LABEL_22;
    }
    return false;
  }
  nPartId = 2;
  if ( CThemeHelper::GetThemePartSize(
         hTheme: this->m_hReBarTheme,
         hdc: v4->m_hDC,
         nPartId: 2,
         nStateId: 0,
         pRect: nullptr,
         eSize: TS_TRUE,
         &psz) < 0 )
    return false;
  if ( fCentered != 0 )
  {
    v7 = rectClient.left - rect->left;
    left = rect->left;
    if ( v7 < psz.cx )
      --v7;
    v8 = rect->left + (v7 - psz.cx) / 2;
  }
  else
  {
    v8 = rect->left;
    left = rect->left;
  }
  v9 = rect->top;
  v10 = this->m_cyTopBorder;
  rectGripper.left = v8;
  rectGripper.right = psz.cx + v8;
  v11 = rect->bottom - this->m_cyBottomBorder - v9 - v10;
  rectGripper.top = v9 + v10;
  clipRect.left = left;
  v12 = v9 + v10 + v11;
  rectGripper.bottom = v12;
  clipRect.right = rectClient.left;
  clipRect.top = v9 + v10;
LABEL_22:
  clipRect.bottom = v12;
  return CThemeHelper::DrawThemeBackground(
           hTheme: this->m_hReBarTheme,
           hdc: pDC->m_hDC,
           nPartId,
           nStateId: 0,
           pRect: &rectGripper,
           pClipRect: &clipRect) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10357FEE
// Name: public: virtual int CControlBar::PreTranslateMessage(struct tagMSG __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CControlBar::PreTranslateMessage(CControlBar *this, tagMSG *pMsg)
{
  unsigned int message; // ebx
  CWnd *Owner; // eax
  bool v6; // zf
  CControlBar_vtbl *v7; // eax
  CFrameWnd *TopLevelFrame; // eax
  CWnd *v9; // ebx
  CPoint point; // [esp+8h] [ebp-4Ch] BYREF
  CWnd *pOwner; // [esp+10h] [ebp-44h]
  int bNotButton; // [esp+14h] [ebp-40h]
  AFX_MODULE_THREAD_STATE *pModuleThreadState; // [esp+18h] [ebp-3Ch]
  int nHit; // [esp+1Ch] [ebp-38h]
  tagTOOLINFOA ti; // [esp+20h] [ebp-34h] BYREF

  if ( CWnd::PreTranslateMessage(this, pMsg) != 0 )
    return 1;
  message = pMsg->message;
  Owner = CWnd::GetOwner(this);
  v6 = (this->m_dwStyle & 0x20) == 0;
  pOwner = Owner;
  if ( (!v6 || message == 513 || message == 514) && (message >= 0x200 && message <= 0x209 || message - 160 <= 9) )
  {
    pModuleThreadState = AfxGetModuleThreadState();
    point = (CPoint)pMsg->pt;
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
    memset(dst: (unsigned __int8 *)&ti, value: 0, count: 0x2Cu);
    v7 = this->__vftable;
    ti.cbSize = 48;
    nHit = ((int (__thiscall *)(CControlBar *, int, int, tagTOOLINFOA *))v7->OnToolHitTest)(
             a1: this,
             a2: point.x,
             a3: point.y,
             a4: &ti);
    if ( ti.lpszText != (char *)-1 )
      free(pMem: ti.lpszText);
    if ( message == 513 && (ti.uFlags & 0x80000000) != 0 )
    {
      bNotButton = 1;
    }
    else
    {
      bNotButton = 0;
      if ( message != 513 && GetKeyState(nVirtKey: 1) < 0 )
        nHit = pModuleThreadState->m_nLastStatus;
    }
    if ( nHit < 0 || bNotButton != 0 )
    {
      if ( GetKeyState(nVirtKey: 1) >= 0 || bNotButton != 0 )
      {
        this->SetStatusText(this, a2: -1);
        KillTimer(hWnd: this->m_hWnd, uIDEvent: 0xE001u);
      }
    }
    else if ( message == 514 )
    {
      this->SetStatusText(this, a2: -1);
      CControlBar::ResetTimer(this, nEvent: 0xE001u, nTime: 0xC8u);
    }
    else if ( (this->m_nStateFlags & 8) != 0 || GetKeyState(nVirtKey: 1) < 0 )
    {
      this->SetStatusText(this, a2: nHit);
    }
    else if ( nHit != pModuleThreadState->m_nLastStatus )
    {
      CControlBar::ResetTimer(this, nEvent: 0xE000u, nTime: 0x12Cu);
    }
    pModuleThreadState->m_nLastStatus = nHit;
  }
  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame != nullptr && TopLevelFrame->m_bHelpMode != 0 )
    return 0;
  if ( pOwner == nullptr )
  {
LABEL_36:
    if ( IsWindow(hWnd: this->m_hWnd) )
      return CWnd::PreTranslateInput(this, lpMsg: pMsg);
    return 0;
  }
  while ( 1 )
  {
    v9 = pOwner;
    if ( pOwner->PreTranslateMessage(this: pOwner, a2: pMsg) != 0 )
      return 1;
    pOwner = CWnd::GetParentFrame(this: v9);
    if ( pOwner == nullptr )
      goto LABEL_36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10358205
// Name: public: virtual long CControlBar::WindowProc(unsigned int,unsigned int,long)
// Source: rtti_class
//------------------------------------------------------------------------------
_DWORD *__thiscall CControlBar::WindowProc(CControlBar *this, unsigned int nMsg, unsigned int wParam, _DWORD *lParam)
{
  _DWORD *v4; // esi
  _DWORD *result; // eax
  CWnd *m_pInPlaceOwner; // eax
  CWnd *Owner; // eax
  int v8; // ecx
  _BYTE *v9; // ecx
  bool v10; // zf
  _WORD *v11; // ecx

  if ( nMsg < 0x2B || nMsg > 0x2F && nMsg != 57 && nMsg != 78 && nMsg != 273 )
    return (_DWORD *)CWnd::WindowProc(this, message: nMsg, wParam, (int)lParam);
  v4 = lParam;
  if ( this->OnWndMsg(this, a2: nMsg, a3: wParam, a4: (int)lParam, a5: (int *)&lParam) != 0 )
    return lParam;
  m_pInPlaceOwner = this->m_pInPlaceOwner;
  if ( m_pInPlaceOwner != nullptr && nMsg == 273 )
    return (_DWORD *)SendMessageA(hWnd: m_pInPlaceOwner->m_hWnd, Msg: 0x111u, wParam, lParam: (LPARAM)v4);
  Owner = CWnd::GetOwner(this);
  result = (_DWORD *)SendMessageA(hWnd: Owner->m_hWnd, Msg: nMsg, wParam, lParam: (LPARAM)v4);
  lParam = result;
  if ( nMsg == 78 )
  {
    v8 = v4[2];
    if ( v8 == -520 )
    {
      if ( v4[24] != 0 )
        return result;
      v9 = (_BYTE *)v4[3];
      if ( v9 != nullptr )
      {
        v10 = *v9 == 0;
        goto LABEL_21;
      }
      return (_DWORD *)CWnd::WindowProc(this, message: 0x4Eu, wParam, lParam: (int)v4);
    }
    if ( v8 == -530 && v4[44] == 0 )
    {
      v11 = (_WORD *)v4[3];
      if ( v11 != nullptr )
      {
        v10 = *v11 == 0;
LABEL_21:
        if ( !v10 )
          return result;
        return (_DWORD *)CWnd::WindowProc(this, message: 0x4Eu, wParam, lParam: (int)v4);
      }
      return (_DWORD *)CWnd::WindowProc(this, message: 0x4Eu, wParam, lParam: (int)v4);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103583B6
// Name: protected: static struct AFX_MSGMAP const __near * CControlBar::GetThisMessageMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CControlBar::GetThisMessageMap()
{
  return &messageMap_21;
}

//------------------------------------------------------------------------------
// Address: 0x103583BC
// Name: public: virtual CDialogBar::~CDialogBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogBar::~CDialogBar(CDialogBar *this)
{
  this->__vftable = (CDialogBar_vtbl *)&CDialogBar::`vftable';
  CControlBar::DestroyWindow(this);
  CControlBar::~CControlBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x103583ED
// Name: public: virtual void CDialogBar::OnUpdateCmdUI(class CFrameWnd __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogBar::OnUpdateCmdUI(CDialogBar *this, CFrameWnd *pTarget, int bDisableIfNoHndler)
{
  CWnd::UpdateDialogControls(this, pTarget, bDisableIfNoHndler);
}

//------------------------------------------------------------------------------
// Address: 0x103583F8
// Name: protected: long CDialogBar::HandleInitDialog(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialogBar::HandleInitDialog(CDialogBar *this, unsigned int __formal, unsigned int __formala)
{
  COccManager *m_pOccManager; // eax

  CWnd::Default(this);
  m_pOccManager = AfxGetModuleState()->m_pOccManager;
  if ( m_pOccManager != nullptr && this->m_pOccDialogInfo != nullptr )
    m_pOccManager->CreateDlgControls_2(
      this: m_pOccManager,
      a2: this,
      a3: this->m_lpszTemplateName,
      a4: this->m_pOccDialogInfo);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035842D
// Name: protected: virtual int CDialogBar::SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialogBar::SetOccDialogInfo(CDialogBar *this, _AFX_OCC_DIALOG_INFO *pOccDialogInfo)
{
  this->m_pOccDialogInfo = pOccDialogInfo;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10358442
// Name: public: virtual struct CRuntimeClass __near * CDialogBar::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDialogBar::GetRuntimeClass(CDialogBar *this)
{
  return &CDialogBar::classCDialogBar;
}

//------------------------------------------------------------------------------
// Address: 0x10358448
// Name: public: CDialogBar::CDialogBar(void)
// Source: json
//------------------------------------------------------------------------------
CDialogBar *__thiscall CDialogBar::CDialogBar(CDialogBar *this)
{
  CControlBar::CControlBar(this);
  this->__vftable = (CDialogBar_vtbl *)&CDialogBar::`vftable';
  this->m_sizeDefault.cx = 0;
  this->m_sizeDefault.cy = 0;
  this->m_lpszTemplateName = nullptr;
  this->m_pOccDialogInfo = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10358497
// Name: public: virtual int CDialogBar::Create(class CWnd __near *,char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialogBar::Create(
        CDialogBar *this,
        CWnd *pParentWnd,
        char *lpszTemplateName,
        unsigned int nStyle,
        unsigned int nID)
{
  char *v7; // edi
  int Dlg; // eax
  int v9; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-64h]
  tagCREATESTRUCTA v11; // [esp+Ch] [ebp-50h] BYREF
  char *lpszResourceName; // [esp+3Ch] [ebp-20h]
  CWnd *v13; // [esp+40h] [ebp-1Ch]
  int v14; // [esp+44h] [ebp-18h]
  CRect rect; // [esp+48h] [ebp-14h] BYREF

  v13 = pParentWnd;
  lpszResourceName = lpszTemplateName;
  v14 = nID;
  this->m_dwStyle = nStyle & 0x40FFFF;
  memset(dst: (unsigned __int8 *)&v11, value: 0, count: sizeof(v11));
  v11.lpszClass = "AfxControlBar100s";
  v11.style = nStyle | 0x40000000;
  v11.hMenu = (HMENU__ *)v14;
  v11.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  if ( v13 != nullptr )
    v11.hwndParent = v13->m_hWnd;
  else
    v11.hwndParent = nullptr;
  if ( this->PreCreateWindow(this, a2: &v11) == 0 )
    return 0;
  v7 = lpszResourceName;
  this->m_lpszTemplateName = lpszResourceName;
  AfxEndDeferRegisterClass(fToRegister: 16);
  AfxEndDeferRegisterClass(fToRegister: 245760);
  Dlg = CWnd::CreateDlg(this, lpszTemplateName: v7, pParentWnd: v13);
  this->m_lpszTemplateName = nullptr;
  if ( Dlg == 0 )
    return 0;
  CWnd::SetDlgCtrlID(this, nID: v14);
  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  v9 = rect.right - rect.left;
  this->m_sizeDefault.cy = rect.bottom - rect.top;
  this->m_sizeDefault.cx = v9;
  CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x4000000u, nFlags: 0);
  if ( CWnd::ExecuteDlgInit(this, lpszResourceName: v7) == 0 )
    return 0;
  CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x54u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103585D4
// Name: public: virtual class CSize CDialogBar::CalcFixedLayout(int,int)
// Source: json
//------------------------------------------------------------------------------
CSize *__thiscall CDialogBar::CalcFixedLayout(CDialogBar *this, CSize *result, int bStretch, int bHorz)
{
  int cy; // edx
  int cx; // ecx
  int v7; // edx
  int v8; // ecx

  if ( bStretch != 0 )
  {
    if ( bHorz != 0 )
      cy = this->m_sizeDefault.cy;
    else
      cy = 0x7FFF;
    if ( bHorz != 0 )
      cx = 0x7FFF;
    else
      cx = this->m_sizeDefault.cx;
    result->cx = cx;
    result->cy = cy;
    return result;
  }
  else
  {
    v7 = this->m_sizeDefault.cx;
    v8 = this->m_sizeDefault.cy;
    result->cx = v7;
    result->cy = v8;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10358626
// Name: protected: virtual struct AFX_MSGMAP const __near * CDialogBar::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDialogBar::GetMessageMap(CDialogBar *this)
{
  return &messageMap_22;
}

//------------------------------------------------------------------------------
// Address: 0x1035C0B1
// Name: protected: int CPreviewView::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPreviewView::OnSetCursor(CPreviewView *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HCURSOR CursorA; // [esp-4h] [ebp-10h]
  CPoint point; // [esp+4h] [ebp-8h] BYREF

  if ( nHitTest != 1 )
    return CWnd::Default(this);
  point.x = 0;
  point.y = 0;
  GetCursorPos(lpPoint: &point);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
  if ( this->m_nZoomState == 2 || CPreviewView::FindPageRect(this, &point, nPage: &nHitTest) == 0 )
  {
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    SetCursor(hCursor: CursorA);
  }
  else
  {
    if ( this->m_hMagnifyCursor == nullptr )
    {
      ModuleState = AfxGetModuleState();
      this->m_hMagnifyCursor = LoadCursorW(
                                 hInstance: ModuleState->m_hCurrentResourceHandle,
                                 lpCursorName: (LPCWSTR)0x7902);
    }
    SetCursor(hCursor: this->m_hMagnifyCursor);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037EEC4
// Name: protected: int CMFCPopupMenu::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::OnSetCursor(CMFCPopupMenu *this, CWnd *pWnd, CWnd *nHitTest, unsigned int message)
{
  HCURSOR m_hcurSizeAll; // eax
  CPoint ptCursor; // [esp+4h] [ebp-8h] BYREF

  ptCursor = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  if ( !PtInRect(lprc: &this->m_rectTearOffCaption, pt: ptCursor.tagPOINT) )
    return CFrameWnd::OnSetCursor(this, pWnd, nHitTest, message);
  m_hcurSizeAll = afxGlobalData.m_hcurSizeAll;
  if ( afxGlobalData.m_hcurSizeAll == nullptr )
  {
    AfxGetModuleState();
    m_hcurSizeAll = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
    afxGlobalData.m_hcurSizeAll = m_hcurSizeAll;
  }
  SetCursor(hCursor: m_hcurSizeAll);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039393D
// Name: protected: int CPaneFrameWnd::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPaneFrameWnd::OnSetCursor(CPaneFrameWnd *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  HCURSOR CursorA; // eax
  int result; // eax

  switch ( nHitTest )
  {
    case 0xAu:
    case 0xBu:
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
      goto LABEL_3;
    case 0xCu:
    case 0xFu:
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
      goto LABEL_3;
    case 0xDu:
    case 0x11u:
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F82);
      goto LABEL_3;
    case 0xEu:
    case 0x10u:
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F83);
LABEL_3:
      SetCursor(hCursor: CursorA);
      result = 1;
      break;
    default:
      result = CWnd::Default(this);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039CBE0
// Name: protected: int CMFCPropertyGridCtrl::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnSetCursor(
        CMFCPropertyGridCtrl *this,
        CWnd *pWnd,
        CMFCPropertyGridProperty::ClickArea nHitTest,
        unsigned int message)
{
  CMFCPropertyGridProperty *v6; // eax
  CMFCPropertyGridProperty *v7; // edi
  CPoint point; // [esp+8h] [ebp-8h] BYREF

  if ( nHitTest == ClickName )
  {
    point.x = 0;
    point.y = 0;
    GetCursorPos(lpPoint: &point);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
    if ( this->m_bDescriptionArea != 0 && abs(lnumber: point.y - this->m_rectList.bottom - 4) <= 2 )
    {
      SetCursor(hCursor: afxGlobalData.m_hcurStretchVert);
      return 1;
    }
    if ( point.y <= this->m_rectList.bottom )
    {
      if ( abs(lnumber: point.x - this->m_nLeftColumnWidth - this->m_rectList.left) <= 2 )
      {
        SetCursor(hCursor: afxGlobalData.m_hcurStretch);
        return 1;
      }
      v6 = CMFCPropertyGridCtrl::HitTest(this, pt: point, pnArea: &nHitTest, bPropsOnly: 0);
      v7 = v6;
      if ( v6 != nullptr
        && v6 == this->m_pSel
        && nHitTest == ClickValue
        && !PtInRect(lprc: &v6->m_rectButton, pt: point.tagPOINT)
        && v7->OnSetCursor(this: v7) != 0 )
      {
        return 1;
      }
    }
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A63CA
// Name: protected: int CMFCButton::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCButton::OnSetCursor(CMFCButton *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CPoint ptCursor; // [esp+8h] [ebp-1Ch] BYREF
  CRect rectClient; // [esp+10h] [ebp-14h] BYREF

  if ( this->m_hCursor == nullptr )
    return CWnd::Default(this);
  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  ptCursor = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  if ( !PtInRect(lprc: &rectClient, pt: ptCursor.tagPOINT) )
    return CWnd::Default(this);
  SetCursor(hCursor: this->m_hCursor);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AD22C
// Name: protected: int CMFCToolBar::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnSetCursor(CMFCToolBar *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  int m_bStretchButton; // edi
  int m_iSelected; // ebx
  CMFCToolBarButton *Button; // ebx
  CPoint ptCursorClient; // [esp+Ch] [ebp-24h] BYREF
  CPoint ptCursor; // [esp+14h] [ebp-1Ch] BYREF
  CRect rectGripper; // [esp+1Ch] [ebp-14h] BYREF

  m_bStretchButton = this->m_bStretchButton;
  ptCursor.x = 0;
  ptCursor.y = 0;
  GetCursorPos(lpPoint: &ptCursor);
  if ( m_bStretchButton != 0
    || CMFCToolBar::m_bCustomizeMode != 0
    && this->m_iSelected != -1
    && this->m_bLocked == 0
    && (ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor),
        m_iSelected = this->m_iSelected,
        ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: ptCursor.x, a3: ptCursor.y) == m_iSelected)
    && (Button = CMFCToolBar::GetButton(this, nIndex: m_iSelected), Button->CanBeStretched(this: Button) != 0)
    && abs(lnumber: ptCursor.x - Button->m_rect.right) <= 6 )
  {
    SetCursor(hCursor: afxGlobalData.m_hcurStretch);
    return 1;
  }
  ptCursorClient = ptCursor;
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursorClient);
  memset(&rectGripper, 0, sizeof(rectGripper));
  CMFCControlBarImpl::GetGripperRect(this: &this->m_Impl, &rectGripper, bClientCoord: 1);
  if ( PtInRect(lprc: &rectGripper, pt: ptCursorClient.tagPOINT) && CMFCPopupMenu::m_pActivePopupMenu == nullptr )
  {
    SetCursor(hCursor: afxGlobalData.m_hcurSizeAll);
    return 1;
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F8B05
// Name: protected: int CPaneDivider::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::OnSetCursor(CPaneDivider *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  unsigned int m_dwDividerStyle; // eax

  if ( nHitTest != 1 )
    return CWnd::Default(this);
  m_dwDividerStyle = this->m_dwDividerStyle;
  if ( (m_dwDividerStyle & 1) != 0 )
  {
    SetCursor(hCursor: afxGlobalData.m_hcurStretchVert);
  }
  else if ( (m_dwDividerStyle & 2) != 0 )
  {
    SetCursor(hCursor: afxGlobalData.m_hcurStretch);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10402B18
// Name: protected: int CMFCTabCtrl::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::OnSetCursor(CMFCTabCtrl *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  HICON__ *m_hcurStretch; // eax
  CPoint ptCursor; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_bFlat != 0 && !IsRectEmpty(lprc: &this->m_rectTabSplitter) )
  {
    ptCursor = 0;
    GetCursorPos(lpPoint: &ptCursor);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
    if ( PtInRect(lprc: &this->m_rectTabSplitter, pt: ptCursor.tagPOINT) )
    {
      SetCursor(hCursor: afxGlobalData.m_hcurStretch);
      return 1;
    }
  }
  if ( !IsRectEmpty(lprc: &this->m_rectResize) )
  {
    ptCursor = 0;
    GetCursorPos(lpPoint: &ptCursor);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
    if ( PtInRect(lprc: &this->m_rectResize, pt: ptCursor.tagPOINT) )
    {
      m_hcurStretch = afxGlobalData.m_hcurStretch;
      if ( this->m_ResizeMode != RESIZE_VERT )
        m_hcurStretch = afxGlobalData.m_hcurStretchVert;
      SetCursor(hCursor: m_hcurStretch);
      return 1;
    }
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10419653
// Name: public: int CMFCOutlookBarToolBar::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarToolBar::OnSetCursor(
        CMFCOutlookBarToolBar *this,
        CWnd *pWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  HCURSOR HandCursor; // eax
  CPoint ptCursor; // [esp+4h] [ebp-8h] BYREF

  ptCursor.x = 0;
  ptCursor.y = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  if ( ((int (__thiscall *)(CMFCOutlookBarToolBar *, int, int))this->HitTest)(a1: this, a2: ptCursor.x, a3: ptCursor.y) < 0 )
    return CMFCToolBar::OnSetCursor(this, pWnd, nHitTest, message);
  HandCursor = AFX_GLOBAL_DATA::GetHandCursor(this: &afxGlobalData);
  SetCursor(hCursor: HandCursor);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10419B17
// Name: protected: int CMFCOutlookBarTabCtrl::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::OnSetCursor(
        CMFCOutlookBarTabCtrl *this,
        CWnd *pWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  HCURSOR CursorA; // eax
  CPoint ptCursor; // [esp+4h] [ebp-8h] BYREF

  ptCursor = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  if ( PtInRect(lprc: &this->m_rectSplitter, pt: ptCursor.tagPOINT) )
  {
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
LABEL_3:
    SetCursor(hCursor: CursorA);
    return 1;
  }
  if ( this->GetTabFromPoint(this, a2: &ptCursor) >= 0 )
  {
    CursorA = AFX_GLOBAL_DATA::GetHandCursor(this: &afxGlobalData);
    goto LABEL_3;
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10423ED0
// Name: protected: int CMFCImagePaintArea::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCImagePaintArea::OnSetCursor(
        CMFCImagePaintArea *this,
        CWnd *pWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  CMFCImagePaintArea::IMAGE_EDIT_MODE m_Mode; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  __int32 v8; // eax
  int v9; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CPoint ptCursor; // [esp+8h] [ebp-1Ch] BYREF
  CRect rectDraw; // [esp+10h] [ebp-14h] BYREF

  ptCursor = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  m_hWnd = this->m_hWnd;
  memset(&rectDraw, 0, sizeof(rectDraw));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectDraw);
  rectDraw.right = rectDraw.left + this->m_sizeImage.cx * this->m_sizeCell.cx;
  rectDraw.bottom = rectDraw.top + this->m_sizeImage.cy * this->m_sizeCell.cy;
  if ( PtInRect(lprc: &rectDraw, pt: ptCursor.tagPOINT) )
  {
    m_Mode = this->m_Mode;
    if ( m_Mode == IMAGE_EDIT_MODE_PEN )
    {
      SetCursor(hCursor: this->m_hcurPen);
      return 1;
    }
    v6 = m_Mode - 1;
    if ( v6 == 0 )
    {
      SetCursor(hCursor: this->m_hcurFill);
      return 1;
    }
    v7 = v6 - 1;
    if ( v7 == 0 )
    {
      SetCursor(hCursor: this->m_hcurLine);
      return 1;
    }
    v8 = v7 - 1;
    if ( v8 == 0 )
    {
      SetCursor(hCursor: this->m_hcurRect);
      return 1;
    }
    v9 = v8 - 1;
    if ( v9 == 0 )
    {
      SetCursor(hCursor: this->m_hcurEllipse);
      return 1;
    }
    if ( v9 == 1 )
    {
      SetCursor(hCursor: this->m_hcurColor);
      return 1;
    }
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042A6B3
// Name: protected: int CMFCColorDialog::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCColorDialog::OnSetCursor(CMFCColorDialog *this, CWnd *pWnd, CWnd *nHitTest, unsigned int message)
{
  if ( this->m_bPickerMode == 0 )
    return CWnd::Default(this);
  SetCursor(hCursor: this->m_hcurPicker);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1043066D
// Name: protected: int CMFCTasksPane::OnSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::OnSetCursor(CMFCTasksPane *this, CWnd *pWnd, unsigned int nHitTest, unsigned int message)
{
  CMFCTasksPaneTask *v5; // eax
  CMFCTasksPaneTask *m_pClickedTask; // ecx
  HCURSOR HandCursor; // eax
  CPoint ptCursor; // [esp+8h] [ebp-8h] BYREF

  ptCursor = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  v5 = CMFCTasksPane::TaskHitTest(this, pt: ptCursor);
  m_pClickedTask = this->m_pClickedTask;
  if ( (m_pClickedTask == nullptr || m_pClickedTask->m_bEnabled == 0)
    && (v5 == nullptr || v5->m_bEnabled == 0)
    && (this->m_bCanCollapse == 0
     || this->m_pClickedGroupCaption == nullptr
     && ((int (__thiscall *)(CMFCTasksPane *, int, int))this->GroupCaptionHitTest)(
          a1: this,
          a2: ptCursor.x,
          a3: ptCursor.y) == 0) )
  {
    return CWnd::Default(this);
  }
  HandCursor = AFX_GLOBAL_DATA::GetHandCursor(this: &afxGlobalData);
  SetCursor(hCursor: HandCursor);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103378EA
// Name: protected: virtual void CSplitterWnd::SetSplitCursor(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::SetSplitCursor(CSplitterWnd *this, int ht)
{
  unsigned int v2; // esi
  int v3; // ebx
  HCURSOR v4; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  HCURSOR CursorW; // eax

  AfxLockGlobals(nLockType: 9);
  if ( ht == 1 || ht >= 101 && ht <= 115 )
  {
    v2 = 30981;
    v3 = 32645;
  }
  else if ( ht == 2 || ht >= 201 && ht <= 215 )
  {
    v2 = 30980;
    v3 = 32644;
  }
  else
  {
    if ( ht != 3 && (ht < 301 || ht > 525) )
    {
      SetCursor(hCursor: afxData.hcurArrow);
      goto LABEL_21;
    }
    v2 = 30979;
    v3 = 32646;
  }
  v4 = nullptr;
  if ( v2 == _afx_idcPrimaryLast )
  {
    CursorW = _afx_hcurLast;
  }
  else
  {
    ModuleState = AfxGetModuleState();
    v4 = _afx_hcurDestroy;
    CursorW = LoadCursorW(hInstance: ModuleState->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)(unsigned __int16)v2);
    _afx_hcurLast = CursorW;
    _afx_hcurDestroy = CursorW;
    if ( CursorW == nullptr )
    {
      CursorW = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)v3);
      _afx_hcurLast = CursorW;
    }
    _afx_idcPrimaryLast = v2;
  }
  SetCursor(hCursor: CursorW);
  if ( v4 != nullptr )
    DestroyCursor(hCursor: v4);
LABEL_21:
  AfxUnlockGlobals(nLockType: 9);
}

//------------------------------------------------------------------------------
// Address: 0x103379CF
// Name: protected: void CSplitterWnd::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnMouseMove(CSplitterWnd *this, unsigned int __formal, CPoint pt)
{
  HWND Capture; // eax
  int top; // eax
  int left; // eax
  int m_htTrack; // eax
  CRect *p_m_rectTracker; // edi
  int v9; // eax

  Capture = GetCapture();
  if ( CWnd::FromHandle(hWnd: Capture) != this )
    this->StopTracking(this, a2: 0);
  if ( this->m_bTracking != 0 )
  {
    pt.x += this->m_ptTrackOffset.x;
    top = this->m_rectLimit.top;
    pt.y += this->m_ptTrackOffset.y;
    if ( pt.y < top || (top = this->m_rectLimit.bottom, pt.y > top) )
      pt.y = top;
    left = this->m_rectLimit.left;
    if ( pt.x < left || (left = this->m_rectLimit.right, pt.x > left) )
      pt.x = left;
    m_htTrack = this->m_htTrack;
    if ( m_htTrack == 1 || m_htTrack >= 101 && m_htTrack <= 115 )
    {
      if ( this->m_rectTracker.top != pt.y )
      {
        this->OnInvertTracker(this, a2: &this->m_rectTracker);
        OffsetRect(lprc: &this->m_rectTracker, dx: 0, dy: pt.y - this->m_rectTracker.top);
        this->OnInvertTracker(this, a2: &this->m_rectTracker);
      }
    }
    else if ( m_htTrack == 2 || m_htTrack >= 201 && m_htTrack <= 215 )
    {
      p_m_rectTracker = &this->m_rectTracker;
      if ( this->m_rectTracker.left != pt.x )
      {
        this->OnInvertTracker(this, a2: &this->m_rectTracker);
        OffsetRect(lprc: &this->m_rectTracker, dx: pt.x - p_m_rectTracker->left, dy: 0);
        goto LABEL_23;
      }
    }
    else if ( m_htTrack == 3 || m_htTrack >= 301 && m_htTrack <= 525 )
    {
      if ( this->m_rectTracker.top != pt.y )
      {
        this->OnInvertTracker(this, a2: &this->m_rectTracker);
        OffsetRect(lprc: &this->m_rectTracker, dx: 0, dy: pt.y - this->m_rectTracker.top);
        this->OnInvertTracker(this, a2: &this->m_rectTracker);
      }
      p_m_rectTracker = &this->m_rectTracker2;
      if ( this->m_rectTracker2.left != pt.x )
      {
        this->OnInvertTracker(this, a2: &this->m_rectTracker2);
        OffsetRect(lprc: &this->m_rectTracker2, dx: pt.x - p_m_rectTracker->left, dy: 0);
LABEL_23:
        this->OnInvertTracker(this, a2: p_m_rectTracker);
      }
    }
  }
  else
  {
    v9 = ((int (__thiscall *)(CSplitterWnd *, int, int))this->HitTest)(a1: this, a2: pt.x, a3: pt.y);
    this->SetSplitCursor(this, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10337B8C
// Name: protected: void CSplitterWnd::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnKeyDown(CSplitterWnd *this, unsigned int nChar, unsigned int __formal, unsigned int a4)
{
  BOOL v5; // ecx
  int v6; // eax
  unsigned int v7; // edi
  int v8; // ecx
  int m_htTrack; // edx
  int top; // eax
  int left; // eax
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  pt.x = 0;
  pt.y = 0;
  GetCursorPos(lpPoint: &pt);
  v5 = GetKeyState(nVirtKey: 17) >= 0;
  v6 = 0;
  v7 = v5 ? 16 : 1;
  v8 = 0;
  if ( nChar == 13 )
  {
    this->StopTracking(this, a2: 1);
  }
  else if ( nChar == 27 )
  {
    this->StopTracking(this, a2: 0);
  }
  else
  {
    switch ( nChar )
    {
      case '%':
        v8 = -1;
        break;
      case '&':
        v6 = -1;
        break;
      case '\'':
        v8 = 1;
        break;
      case '(':
        v6 = 1;
        break;
      default:
        CWnd::Default(this);
        return;
    }
    m_htTrack = this->m_htTrack;
    if ( m_htTrack == 1 || m_htTrack >= 101 && m_htTrack <= 115 )
      v8 = 0;
    if ( m_htTrack == 2 || m_htTrack >= 201 && m_htTrack <= 215 )
      v6 = 0;
    pt.y += v7 * v6;
    pt.x += v7 * v8;
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &pt);
    top = this->m_rectLimit.top;
    if ( pt.y < top || (top = this->m_rectLimit.bottom, pt.y > top) )
      pt.y = top;
    left = this->m_rectLimit.left;
    if ( pt.x < left || (left = this->m_rectLimit.right, pt.x > left) )
      pt.x = left;
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt);
    SetCursorPos(X: pt.x, Y: pt.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034017F
// Name: protected: long CFrameWnd::OnCommandHelp(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnCommandHelp(CFrameWnd *this, unsigned int __formal, unsigned int lParam)
{
  unsigned int v3; // esi
  CWinApp *m_pCurrentWinApp; // eax

  v3 = lParam;
  if ( lParam == 0 )
  {
    v3 = CFrameWnd::IsTracking(this) != 0 ? this->m_nIDTracking + 0x10000 : this->m_nIDHelp + 0x20000;
    if ( v3 == 0 )
      return 0;
  }
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    m_pCurrentWinApp->WinHelpInternal(this: m_pCurrentWinApp, a2: v3, a3: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103401DC
// Name: protected: virtual int CFrameWnd::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnCommand(CFrameWnd *this, unsigned int wParam, int lParam)
{
  CFrameWnd *TopLevelFrame; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame == nullptr )
    AfxThrowInvalidArgException();
  if ( TopLevelFrame->m_bHelpMode == 0
    || lParam != 0
    || (unsigned __int16)wParam == 57670
    || (unsigned __int16)wParam == 57671
    || (unsigned __int16)wParam == 57669 )
  {
    return CWnd::OnCommand(this, wParam, lParam);
  }
  if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x365u, wParam: 0, lParam: (unsigned __int16)wParam + 0x10000) == 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE147u, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10340261
// Name: public: void CFrameWnd::NotifyFloatingWindows(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::NotifyFloatingWindows(CFrameWnd *this, WPARAM dwFlags)
{
  CFrameWnd *TopLevelFrame; // ebx
  int IsWindowEnabled; // eax
  HWND i; // eax
  HWND v6; // esi
  HWND DesktopWindow; // [esp-8h] [ebp-14h]

  if ( (CWnd::GetStyle(this) & 0x40000000) != 0 )
    TopLevelFrame = this;
  else
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame == nullptr )
    AfxThrowInvalidArgException();
  if ( (dwFlags & 0xC) != 0 )
  {
    IsWindowEnabled = CWnd::IsWindowEnabled(this: TopLevelFrame);
    if ( (~(dwFlags >> 3) & 1) != 0 && IsWindowEnabled != 0 && TopLevelFrame != this )
    {
      this->m_nFlags |= 0x200u;
      SendMessageA(hWnd: TopLevelFrame->m_hWnd, Msg: 0x86u, wParam: 1u, lParam: 0);
      this->m_nFlags &= ~0x200u;
    }
    else
    {
      SendMessageA(hWnd: TopLevelFrame->m_hWnd, Msg: 0x86u, wParam: 0, lParam: 0);
    }
  }
  DesktopWindow = GetDesktopWindow();
  for ( i = GetWindow(hWnd: DesktopWindow, uCmd: 5u); ; i = GetWindow(hWnd: v6, uCmd: 2u) )
  {
    v6 = i;
    if ( i == nullptr )
      break;
    if ( AfxIsDescendant(hWndParent: TopLevelFrame->m_hWnd, hWndChild: i) != 0 )
      SendMessageA(hWnd: v6, Msg: 0x36Du, wParam: dwFlags, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034031C
// Name: public: class CWnd __near * CFrameWnd::CreateView(struct CCreateContext __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CFrameWnd::CreateView(CFrameWnd *this, CCreateContext *pContext, unsigned int nID)
{
  CObject *Object; // eax
  CWnd *v4; // ebx
  CObject_vtbl *v6; // eax
  _DWORD v8[4]; // [esp+10h] [ebp-14h] BYREF

  if ( pContext == nullptr || pContext->m_pNewViewClass == nullptr )
    AfxThrowInvalidArgException();
  Object = CRuntimeClass::CreateObject(this: pContext->m_pNewViewClass);
  v4 = (CWnd *)Object;
  if ( Object == nullptr )
    return nullptr;
  v6 = Object->__vftable;
  memset(v8, 0, sizeof(v8));
  if ( ((int (__thiscall *)(CWnd *, _DWORD, _DWORD, int, _DWORD *, CFrameWnd *, unsigned int, CCreateContext *))v6[7].GetRuntimeClass)(
         a1: v4,
         a2: 0,
         a3: 0,
         a4: 1350565888,
         a5: v8,
         a6: this,
         a7: nID,
         a8: pContext) == 0 )
    return nullptr;
  if ( (CWnd::GetExStyle(this: v4) & 0x200) != 0 )
    CWnd::ModifyStyleEx(this, dwRemove: 0x200u, dwAdd: 0, nFlags: 0x20u);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10356E65
// Name: public: void CControlBar::SetBarStyle(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::SetBarStyle(CControlBar *this, unsigned int dwStyle)
{
  unsigned int m_dwStyle; // ecx
  CControlBar_vtbl *v4; // eax

  CWnd::EnableToolTips(this, bEnable: dwStyle & 0x10);
  m_dwStyle = this->m_dwStyle;
  if ( m_dwStyle != dwStyle )
  {
    v4 = this->__vftable;
    this->m_dwStyle = dwStyle;
    v4->OnBarStyleChange(this, a2: m_dwStyle, a3: dwStyle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10356E9E
// Name: public: int CControlBar::AllocElements(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::AllocElements(CControlBar *this, int nElements, int cbElement)
{
  void *v3; // edi
  int result; // eax

  v3 = nullptr;
  if ( nElements < 0 || cbElement < 0 || this->m_pData == nullptr && this->m_nCount != 0 )
    goto LABEL_3;
  if ( nElements > 0 )
  {
    if ( cbElement > 0 )
    {
      result = (int)calloc(count: nElements, size: cbElement);
      v3 = (void *)result;
      if ( result == 0 )
        return result;
      goto LABEL_9;
    }
LABEL_3:
    AfxThrowInvalidArgException();
  }
LABEL_9:
  free(pMem: this->m_pData);
  this->m_pData = v3;
  this->m_nCount = nElements;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10356F3B
// Name: public: long CControlBar::OnThemeChanged(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::OnThemeChanged(CControlBar *this)
{
  if ( CObject::IsKindOf(this, pClass: &CToolBar::classCToolBar) != 0
    || CObject::IsKindOf(this, pClass: &CDockBar::classCDockBar) != 0 )
  {
    if ( this->m_hReBarTheme != nullptr )
      CThemeHelper::CloseThemeData(hTheme: this->m_hReBarTheme);
    this->m_hReBarTheme = CThemeHelper::OpenThemeData(hwnd: this->m_hWnd, pszClassList: L"REBAR");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10356F89
// Name: public: void CControlBar::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnDestroy(CControlBar *this)
{
  CFrameWnd *m_pDockSite; // ecx

  if ( (CObject::IsKindOf(this, pClass: &CToolBar::classCToolBar) != 0
     || CObject::IsKindOf(this, pClass: &CDockBar::classCDockBar) != 0)
    && CThemeHelper::IsAppThemed() != 0 )
  {
    CThemeHelper::CloseThemeData(hTheme: this->m_hReBarTheme);
  }
  if ( AfxGetModuleThreadState()->m_pLastStatus == this )
    this->SetStatusText(this, a2: -1);
  m_pDockSite = this->m_pDockSite;
  if ( m_pDockSite != nullptr )
  {
    CFrameWnd::RemoveControlBar(this: m_pDockSite, pBar: this);
    this->m_pDockSite = nullptr;
  }
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10357023
// Name: public: void CControlBar::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnPaint(CControlBar *this)
{
  CControlBar_vtbl *v2; // eax
  CPaintDC v3; // [esp+10h] [ebp-64h] BYREF
  int v4; // [esp+70h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v3, pWnd: this);
  v2 = this->__vftable;
  v4 = 0;
  if ( v2->IsVisible(this) != 0 )
    this->DoPaint(this, a2: &v3);
  v4 = -1;
  CPaintDC::~CPaintDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x103572C0
// Name: public: virtual CControlBar::~CControlBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::~CControlBar(CControlBar *this)
{
  CFrameWnd *m_pDockSite; // ecx
  CDockContext *m_pDockContext; // ecx
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // eax

  this->m_pInPlaceOwner = nullptr;
  CControlBar::DestroyWindow(this);
  m_pDockSite = this->m_pDockSite;
  if ( m_pDockSite != nullptr )
    CFrameWnd::RemoveControlBar(this: m_pDockSite, pBar: this);
  m_pDockContext = this->m_pDockContext;
  this->m_pDockContext = nullptr;
  if ( m_pDockContext != nullptr )
    ((void (__thiscall *)(CDockContext *, int))m_pDockContext->dtr_CDockContext)(a1: m_pDockContext, a2: 1);
  if ( this->m_pData != nullptr )
    free(pMem: this->m_pData);
  ModuleThreadState = AfxGetModuleThreadState();
  if ( ModuleThreadState->m_pLastStatus == this )
  {
    ModuleThreadState->m_pLastStatus = nullptr;
    ModuleThreadState->m_nLastStatus = -1;
  }
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035733A
// Name: public: void CControlBar::ResetTimer(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::ResetTimer(CControlBar *this, UINT_PTR nEvent, UINT nTime)
{
  KillTimer(hWnd: this->m_hWnd, uIDEvent: 0xE000u);
  KillTimer(hWnd: this->m_hWnd, uIDEvent: 0xE001u);
  SetTimer(hWnd: this->m_hWnd, nIDEvent: nEvent, uElapse: nTime, lpTimerFunc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10357374
// Name: public: void CControlBar::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnTimer(CControlBar *this, unsigned int nIDEvent)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // edi
  CWnd *TopLevelParent; // ebx
  CToolTipCtrl *m_pToolTip; // eax
  HWND__ *m_hWnd; // edi
  HWND Capture; // eax
  CControlBar *v8; // eax
  HWND__ *v9; // edx
  HWND v10; // edi
  HWND__ *v11; // eax
  CToolTipCtrl *v12; // eax
  CPoint point; // [esp+4h] [ebp-10h] BYREF
  AFX_MODULE_THREAD_STATE *pModuleThreadState; // [esp+Ch] [ebp-8h]
  int nHit; // [esp+10h] [ebp-4h]

  if ( GetKeyState(nVirtKey: 1) >= 0 )
  {
    ModuleThreadState = AfxGetModuleThreadState();
    pModuleThreadState = ModuleThreadState;
    point.x = 0;
    point.y = 0;
    GetCursorPos(lpPoint: &point);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
    nHit = ((int (__thiscall *)(CControlBar *, int, int, _DWORD))this->OnToolHitTest)(
             a1: this,
             a2: point.x,
             a3: point.y,
             a4: 0);
    if ( nHit < 0 )
    {
      ModuleThreadState->m_nLastStatus = -1;
    }
    else
    {
      TopLevelParent = CWnd::GetTopLevelParent(this);
      if ( CWnd::IsTopParentActive(this) == 0 )
        goto LABEL_7;
      if ( TopLevelParent == nullptr )
        AfxThrowInvalidArgException();
      if ( CWnd::IsWindowEnabled(this: TopLevelParent) == 0 )
LABEL_7:
        nHit = -1;
      m_pToolTip = ModuleThreadState->m_pToolTip;
      if ( m_pToolTip != nullptr )
        m_hWnd = m_pToolTip->m_hWnd;
      else
        m_hWnd = nullptr;
      Capture = GetCapture();
      v8 = (CControlBar *)CWnd::FromHandle(hWnd: Capture);
      if ( v8 != this )
      {
        v9 = v8 != nullptr ? v8->m_hWnd : nullptr;
        if ( v9 != m_hWnd && CWnd::GetTopLevelParent(this: v8) == TopLevelParent )
          nHit = -1;
      }
    }
    if ( nHit < 0 )
      goto LABEL_28;
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
    v10 = WindowFromPoint(Point: point.tagPOINT);
    if ( v10 == nullptr )
      goto LABEL_26;
    v11 = this->m_hWnd;
    if ( v10 != v11 && !IsChild(hWndParent: v11, hWnd: v10) )
    {
      v12 = pModuleThreadState->m_pToolTip;
      if ( v12 != nullptr )
        v12 = (CToolTipCtrl *)v12->m_hWnd;
      if ( v12 != (CToolTipCtrl *)v10 )
      {
LABEL_26:
        nHit = -1;
        pModuleThreadState->m_nLastStatus = -1;
      }
    }
    if ( nHit < 0 )
    {
LABEL_28:
      if ( pModuleThreadState->m_nLastStatus == -1 )
        KillTimer(hWnd: this->m_hWnd, uIDEvent: 0xE001u);
      this->SetStatusText(this, a2: -1);
    }
    if ( nIDEvent == 57344 )
    {
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 0xE000u);
      if ( nHit >= 0 )
        this->SetStatusText(this, a2: nHit);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103574E7
// Name: public: void CControlBar::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnWindowPosChanging(CControlBar *this, tagWINDOWPOS *lpWndPos)
{
  int cx; // ecx
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-30h]
  int cy; // [esp+Ch] [ebp-1Ch]
  int xRight; // [esp+10h] [ebp-18h]
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  DefWindowProcA(hWnd: this->m_hWnd, Msg: 0x46u, wParam: 0, lParam: (LPARAM)lpWndPos);
  if ( (lpWndPos->flags & 1) == 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
    cx = lpWndPos->cx;
    v4 = rect.right - rect.left;
    v5 = rect.bottom - rect.top;
    v6 = lpWndPos->cy;
    xRight = cx;
    cy = v6;
    if ( cx != rect.right - rect.left && (this->m_dwStyle & 0x400) != 0 )
    {
      SetRect(lprc: &rect, xLeft: cx - afxData.cxBorder2, yTop: 0, xRight: cx, yBottom: v6);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
      SetRect(lprc: &rect, xLeft: v4 - afxData.cxBorder2, yTop: 0, xRight: v4, yBottom: cy);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
      cx = xRight;
      v6 = cy;
    }
    if ( v6 != v5 && (this->m_dwStyle & 0x800) != 0 )
    {
      SetRect(lprc: &rect, xLeft: 0, yTop: v6 - afxData.cyBorder2, xRight: cx, yBottom: v6);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
      SetRect(lprc: &rect, xLeft: 0, yTop: v5 - afxData.cyBorder2, xRight, yBottom: v5);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035761A
// Name: public: int CControlBar::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::OnCreate(CControlBar *this, tagCREATESTRUCTA *lpcs)
{
  int result; // eax
  HWND Parent; // eax
  CWnd *v5; // edi

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    if ( (this->m_dwStyle & 0x10) != 0 )
      CWnd::EnableToolTips(this, bEnable: 1);
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    if ( v5->IsFrameWnd(this: v5) != 0 )
    {
      this->m_pDockSite = (CFrameWnd *)v5;
      CPtrList::AddTail(this: (CObList *)&v5[1].m_xAccessible, newElement: this);
    }
    if ( (CObject::IsKindOf(this, pClass: &CToolBar::classCToolBar) != 0
       || CObject::IsKindOf(this, pClass: &CDockBar::classCDockBar) != 0)
      && CThemeHelper::IsAppThemed() != 0 )
    {
      this->m_hReBarTheme = CThemeHelper::OpenThemeData(hwnd: this->m_hWnd, pszClassList: L"REBAR");
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103576B9
// Name: public: int CControlBar::OnMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::OnMouseActivate(CControlBar *this, CWnd *pDesktopWnd, CWnd *nHitTest, unsigned int nMsg)
{
  if ( CControlBar::IsFloating(this) == 0 )
    return CWnd::Default(this);
  CWnd::ActivateTopParent(this);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x103576DC
// Name: public: void CControlBar::EraseNonClient(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::EraseNonClient(CControlBar *this)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-5Ch]
  HWND__ *v3; // [esp-8h] [ebp-5Ch]
  CWindowDC v4; // [esp+10h] [ebp-44h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-30h] BYREF
  tagRECT rc; // [esp+34h] [ebp-20h] BYREF
  int v7; // [esp+50h] [ebp-4h]

  CWindowDC::CWindowDC(this: &v4, pWnd: this);
  m_hWnd = this->m_hWnd;
  v7 = 0;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v3 = this->m_hWnd;
  memset(&rc, 0, sizeof(rc));
  GetWindowRect(hWnd: v3, lpRect: &rc);
  CWnd::ScreenToClient(this, lpRect: &rc);
  OffsetRect(lprc: &Rect, dx: -rc.left, dy: -rc.top);
  CDC::ExcludeClipRect(this: &v4, lpRect: &Rect);
  OffsetRect(lprc: &rc, dx: -rc.left, dy: -rc.top);
  this->DrawBorders(this, a2: &v4, a3: (CRect *)&rc);
  CDC::IntersectClipRect(this: &v4, lpRect: &rc);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14u, wParam: (WPARAM)v4.m_hDC, lParam: 0);
  this->DrawNCGripper(this, a2: &v4, a3: (const CRect *)&rc);
  v7 = -1;
  CWindowDC::~CWindowDC(this: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x103577BC
// Name: public: struct HBRUSH__ __near * CControlBar::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CControlBar::OnCtlColor(CControlBar *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  HWND__ *v4; // esi

  v4 = (HWND__ *)pWnd;
  if ( CWnd::SendChildNotifyLastMsg(this: pWnd, pResult: (int *)&pWnd) != 0 )
    return (HBRUSH__ *)pWnd;
  if ( v4 != nullptr )
    v4 = *((HWND__ **)v4 + 8);
  if ( CWnd::GrayCtlColor(
         hDC: pDC->m_hDC,
         hWnd: v4,
         nCtlColor,
         hbrGray: afxData.hbrBtnFace,
         clrText: afxData.clrBtnText) != 0 )
    return afxData.hbrBtnFace;
  else
    return (HBRUSH__ *)CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10357816
// Name: public: void CControlBar::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnLButtonDown(CControlBar *this, unsigned int nFlags, CPoint pt)
{
  if ( this->m_pDockBar != nullptr
    && ((int (__thiscall *)(CControlBar *, int, int, _DWORD))this->OnToolHitTest)(a1: this, a2: pt.x, a3: pt.y, a4: 0) == -1 )
  {
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt);
    ((void (__thiscall *)(CDockContext *, int, int))this->m_pDockContext->StartDrag)(
      a1: this->m_pDockContext,
      a2: pt.x,
      a3: pt.y);
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10357864
// Name: public: void CControlBar::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnLButtonDblClk(CControlBar *this, unsigned int nFlags, CPoint pt)
{
  if ( this->m_pDockBar != nullptr
    && ((int (__thiscall *)(CControlBar *, int, int, _DWORD))this->OnToolHitTest)(a1: this, a2: pt.x, a3: pt.y, a4: 0) == -1 )
  {
    this->m_pDockContext->ToggleDocking(this: this->m_pDockContext);
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103578A0
// Name: public: long CControlBar::OnSizeParent(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::OnSizeParent(CControlBar *this, unsigned int __formal, AFX_SIZEPARENTPARAMS *lParam)
{
  CControlBar_vtbl *v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  int v6; // ebx
  unsigned int m_dwStyle; // eax
  BOOL v8; // edx
  int v9; // edx
  int cx; // ecx
  int cy; // eax
  __int16 v12; // di
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  bool v17; // zf
  CSize size; // [esp+4h] [ebp-24h] BYREF
  unsigned int dwStyle; // [esp+Ch] [ebp-1Ch]
  CControlBar *v21; // [esp+10h] [ebp-18h]
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  v3 = this->__vftable;
  v21 = this;
  v4 = ((int (__stdcall *)(AFX_SIZEPARENTPARAMS *))v3->RecalcDelayShow)(a1: lParam);
  dwStyle = v4;
  if ( (v4 & 0x10000000) != 0 && (v4 & 0xF000) != 0 )
  {
    memset(&rect, 0, sizeof(rect));
    CopyRect(lprcDst: &rect, lprcSrc: &lParam->rect);
    v5 = rect.right - rect.left;
    v6 = rect.bottom - rect.top;
    m_dwStyle = v21->m_dwStyle;
    v8 = lParam->bStretch != 0;
    if ( (m_dwStyle & 4) != 0 && (m_dwStyle & 1) != 0 )
    {
      v9 = v8 | 6;
    }
    else if ( (dwStyle & 0xA000) != 0 )
    {
      v9 = v8 | 0xA;
    }
    else
    {
      v9 = v8 | 0x10;
    }
    ((void (__stdcall *)(CSize *, int, int))v21->CalcDynamicLayout)(a1: &size, a2: -1, a3: v9);
    cx = size.cx;
    if ( size.cx >= v5 )
    {
      cx = v5;
      size.cx = v5;
    }
    cy = size.cy;
    if ( size.cy >= v6 )
    {
      cy = v6;
      size.cy = v6;
    }
    v12 = dwStyle;
    if ( (dwStyle & 0xA000) != 0 )
    {
      v13 = lParam->sizeTotal.cx;
      lParam->sizeTotal.cy += cy;
      if ( v13 <= cx )
        v13 = cx;
      lParam->sizeTotal.cx = v13;
      if ( (v12 & 0x2000) != 0 )
      {
        lParam->rect.top += cy;
      }
      else if ( v12 < 0 )
      {
        v14 = rect.bottom - cy;
        lParam->rect.bottom -= cy;
        rect.top = v14;
      }
    }
    else if ( (dwStyle & 0x5000) != 0 )
    {
      v15 = lParam->sizeTotal.cy;
      lParam->sizeTotal.cx += cx;
      if ( v15 <= cy )
        v15 = cy;
      lParam->sizeTotal.cy = v15;
      if ( (v12 & 0x1000) != 0 )
      {
        lParam->rect.left += cx;
      }
      else if ( (v12 & 0x4000) != 0 )
      {
        v16 = rect.right - cx;
        lParam->rect.right -= cx;
        rect.left = v16;
      }
    }
    v17 = lParam->hDWP == nullptr;
    rect.right = cx + rect.left;
    rect.bottom = cy + rect.top;
    if ( !v17 )
      AfxRepositionWindow(lpLayout: lParam, hWnd: v21->m_hWnd, lpRect: &rect);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103582F6
// Name: public: long CControlBar::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CControlBar::OnIdleUpdateCmdUI(CControlBar *this, unsigned int wParam, int __formal)
{
  unsigned int Style; // eax
  unsigned int m_nStateFlags; // ecx
  int v6; // eax
  int v7; // edx
  CDockBar *m_pDockBar; // ecx
  CFrameWnd *Owner; // edi

  Style = CWnd::GetStyle(this);
  m_nStateFlags = this->m_nStateFlags;
  v6 = Style & 0x10000000;
  v7 = 0;
  if ( (m_nStateFlags & 1) != 0 && v6 != 0 )
  {
    v7 = 128;
  }
  else if ( (m_nStateFlags & 2) != 0 && v6 == 0 )
  {
    v7 = 64;
  }
  this->m_nStateFlags = m_nStateFlags & 0xFFFFFFFC;
  if ( v7 != 0 )
    CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: v7 | 0x17);
  if ( (CWnd::GetStyle(this) & 0x10000000) != 0 )
  {
    m_pDockBar = this->m_pDockBar;
    if ( m_pDockBar == nullptr || (CWnd::GetStyle(this: m_pDockBar) & 0x10000000) != 0 )
    {
      Owner = (CFrameWnd *)CWnd::GetOwner(this);
      if ( Owner == nullptr || Owner->IsFrameWnd(this: Owner) == 0 )
        Owner = CWnd::GetParentFrame(this);
      if ( Owner != nullptr )
        this->OnUpdateCmdUI(this, a2: Owner, a3: wParam);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103583AC
// Name: public: void CControlBar::OnInitialUpdate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CControlBar::OnInitialUpdate(CControlBar *this)
{
  CControlBar::OnIdleUpdateCmdUI(this, wParam: 1u, __formal: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1035C149
// Name: int _AfxPreviewCloseProc(class CFrameWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxPreviewCloseProc(CFrameWnd *pFrameWnd)
{
  CPreviewView *DlgItem; // eax

  DlgItem = (CPreviewView *)CWnd::GetDlgItem(this: pFrameWnd, nID: 59648);
  CPreviewView::OnPreviewClose(this: DlgItem);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035C168
// Name: public: CPreviewView::CPreviewView(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPreviewView *__thiscall CPreviewView::CPreviewView(CPreviewView *this)
{
  CPreviewView::PAGE_INFO *v2; // edx
  int i; // [esp+10h] [ebp-14h]
  CPreviewView::PAGE_INFO *m_pageInfoArray; // [esp+14h] [ebp-10h]

  CScrollView::CScrollView(this);
  this->__vftable = (CPreviewView_vtbl *)&CPreviewView::`vftable';
  CDC::CDC(this: &this->m_dcPrint);
  m_pageInfoArray = this->m_pageInfoArray;
  for ( i = 1; i >= 0; --i )
    CPreviewView::PAGE_INFO::PAGE_INFO(this: m_pageInfoArray++);
  this->m_sizePrinterPPI.cx = 0;
  this->m_sizePrinterPPI.cy = 0;
  this->m_ptCenterPoint.x = 0;
  this->m_ptCenterPoint.y = 0;
  this->m_pToolBar = nullptr;
  this->m_pPrintView = nullptr;
  this->m_pOrigView = nullptr;
  this->m_pPreviewInfo = nullptr;
  this->m_pPreviewDC = nullptr;
  this->m_pPreviewState = nullptr;
  this->m_hMagnifyCursor = nullptr;
  this->m_bPageNumDisplayed = 0;
  this->m_nZoomState = 0;
  this->m_pPageInfo = v2;
  this->m_nMaxPages = 2;
  this->m_bCenter = 1;
  this->m_nMapMode = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035C247
// Name: public: int CPreviewView::SetPrintView(class CView __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewView::SetPrintView(CPreviewView *this, CView *pPrintView)
{
  CPrintInfo *v3; // eax
  CPrintInfo *v4; // eax
  tagPDA *m_pd; // eax
  tagPDA *v6; // eax
  CPreviewDC *v7; // eax
  CPreviewDC *v8; // eax
  CView *m_pPrintView; // ecx
  int result; // eax
  CDC_vtbl *v11; // eax
  int DeviceCaps; // eax
  unsigned int m_nNumPreviewPages; // eax
  unsigned int m_nMaxPages; // ecx
  CPrintInfo *v15; // eax
  tagPDA *v16; // ecx
  int nMaxPage; // edx
  HDC__ *m_hAttribDC; // [esp-8h] [ebp-48h]
  CPrintInfo *m_pPreviewInfo; // [esp-4h] [ebp-44h]
  HDC__ *hDC; // [esp+10h] [ebp-30h]
  tagSCROLLINFO ScrollInfo; // [esp+14h] [ebp-2Ch] BYREF
  int v22; // [esp+3Ch] [ebp-4h]

  this->m_pPrintView = pPrintView;
  v3 = (CPrintInfo *)operator new(nSize: 0x40u);
  v22 = 0;
  if ( v3 != nullptr )
    v4 = CPrintInfo::CPrintInfo(this: v3);
  else
    v4 = nullptr;
  v22 = -1;
  this->m_pPreviewInfo = v4;
  v4->m_pPD->m_nIDHelp = 28681;
  m_pd = this->m_pPreviewInfo->m_pPD->m_pd;
  m_pd->Flags |= 0x40u;
  v6 = this->m_pPreviewInfo->m_pPD->m_pd;
  v6->Flags &= ~0x100u;
  this->m_pPreviewInfo->m_bPreview = 1;
  v7 = (CPreviewDC *)operator new(nSize: 0x40u);
  v22 = 1;
  if ( v7 != nullptr )
    v8 = CPreviewDC::CPreviewDC(this: v7);
  else
    v8 = nullptr;
  m_pPrintView = this->m_pPrintView;
  m_pPreviewInfo = this->m_pPreviewInfo;
  v22 = -1;
  this->m_pPreviewDC = v8;
  result = m_pPrintView->OnPreparePrinting(this: m_pPrintView, a2: m_pPreviewInfo);
  if ( result != 0 )
  {
    CDC::Attach(this: &this->m_dcPrint, hDC: this->m_pPreviewInfo->m_pPD->m_pd->hDC);
    this->m_pPreviewDC->SetAttribDC(this: this->m_pPreviewDC, a2: this->m_pPreviewInfo->m_pPD->m_pd->hDC);
    this->m_pPreviewDC->m_bPrinting = 1;
    v11 = this->m_dcPrint.__vftable;
    this->m_dcPrint.m_bPrinting = 1;
    v11->SaveDC(this: &this->m_dcPrint);
    hDC = GetDC(hWnd: this->m_hWnd);
    this->m_pPreviewDC->SetOutputDC(this: this->m_pPreviewDC, a2: hDC);
    this->m_pPrintView->OnBeginPrinting(this: this->m_pPrintView, a2: this->m_pPreviewDC, a3: this->m_pPreviewInfo);
    this->m_pPreviewDC->ReleaseOutputDC(this: this->m_pPreviewDC);
    ReleaseDC(hWnd: this->m_hWnd, hDC);
    this->m_dcPrint.RestoreDC(this: &this->m_dcPrint, a2: -1);
    DeviceCaps = GetDeviceCaps(hdc: this->m_dcPrint.m_hAttribDC, index: 88);
    m_hAttribDC = this->m_dcPrint.m_hAttribDC;
    this->m_sizePrinterPPI.cx = DeviceCaps;
    this->m_sizePrinterPPI.cy = GetDeviceCaps(hdc: m_hAttribDC, index: 90);
    m_nNumPreviewPages = this->m_pPreviewInfo->m_nNumPreviewPages;
    this->m_nPages = m_nNumPreviewPages;
    if ( m_nNumPreviewPages != 0 )
    {
      m_nMaxPages = this->m_nMaxPages;
      if ( m_nNumPreviewPages > m_nMaxPages )
        this->m_nPages = m_nMaxPages;
    }
    else
    {
      this->m_nPages = 1;
    }
    this->m_nZoomOutPages = this->m_nPages;
    CScrollView::SetScrollSizes(
      this,
      nMapMode: 1,
      sizeTotal: (CSize)0x100000001LL,
      sizePage: &CScrollView::sizeDefault,
      sizeLine: &CScrollView::sizeDefault);
    v15 = this->m_pPreviewInfo;
    v16 = v15->m_pPD->m_pd;
    nMaxPage = v16->nMaxPage;
    if ( (unsigned __int16)nMaxPage >= 0x8000u || nMaxPage - (unsigned int)v16->nMinPage > 0x7FFF )
    {
      ShowScrollBar(hWnd: this->m_hWnd, wBar: 1, bShow: false);
    }
    else
    {
      ScrollInfo.fMask = 3;
      ScrollInfo.nMin = v15->m_pPD->m_pd->nMinPage;
      ScrollInfo.nMax = v15->m_pPD->m_pd->nMaxPage;
      ScrollInfo.nPage = 1;
      if ( CWnd::SetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, bRedraw: 0) == 0 )
        CWnd::SetScrollRange(this, nBar: 1, nMinPos: ScrollInfo.nMin, nMaxPos: ScrollInfo.nMax, bRedraw: 0);
    }
    CPreviewView::SetCurrentPage(this, nPage: this->m_pPreviewInfo->m_nCurPage, bClearRatios: 1);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035C4C3
// Name: protected: virtual void CPreviewView::PositionPage(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::PositionPage(CPreviewView *this, unsigned int nPage)
{
  unsigned int v3; // ebx
  CSize *p_sizeUnscaled; // edi
  int *v5; // eax
  CPreviewView::PAGE_INFO *m_pPageInfo; // ecx
  _BYTE v7[8]; // [esp+Ch] [ebp-10h] BYREF
  CSize windowSize; // [esp+14h] [ebp-8h] BYREF

  CPreviewView::CalcPageDisplaySize(this, result: &windowSize);
  v3 = nPage;
  this->m_dcPrint.Escape(this: &this->m_dcPrint, a2: 12, a3: 0, a4: nullptr, a5: &this->m_pPageInfo[nPage].sizeUnscaled);
  p_sizeUnscaled = &this->m_pPageInfo[nPage].sizeUnscaled;
  p_sizeUnscaled->cx = MulDiv(
                         nNumber: p_sizeUnscaled->cx,
                         nNumerator: afxData.cxPixelsPerInch,
                         nDenominator: this->m_sizePrinterPPI.cx);
  p_sizeUnscaled->cy = MulDiv(
                         nNumber: p_sizeUnscaled->cy,
                         nNumerator: afxData.cyPixelsPerInch,
                         nDenominator: this->m_sizePrinterPPI.cy);
  v5 = (int *)((int (__thiscall *)(CPreviewView *, _BYTE *, int, int, int, int))this->CalcScaleRatio)(
                a1: this,
                a2: v7,
                a3: windowSize.cx,
                a4: windowSize.cy,
                a5: p_sizeUnscaled->cx,
                a6: p_sizeUnscaled->cy);
  m_pPageInfo = this->m_pPageInfo;
  m_pPageInfo[v3].sizeZoomOutRatio.cx = *v5;
  m_pPageInfo[v3].sizeZoomOutRatio.cy = v5[1];
  CPreviewView::SetScaledSize(this, nPage);
}

//------------------------------------------------------------------------------
// Address: 0x1035C570
// Name: protected: void CPreviewView::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnVScroll(
        CPreviewView *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  unsigned int nMinPage; // eax
  tagPDA *v5; // edx
  tagPDA *m_pd; // edx

  if ( this->m_nZoomState != 0 )
  {
    CScrollView::OnVScroll(this, nSBCode, nPos, pScrollBar);
    return;
  }
  if ( nSBCode != 0 )
  {
    switch ( nSBCode )
    {
      case 1u:
        nMinPage = this->m_nCurrentPage + 1;
        break;
      case 2u:
        m_pd = this->m_pPreviewInfo->m_pPD->m_pd;
        CPreviewView::SetCurrentPage(
          this,
          nPage: this->m_nCurrentPage - (m_pd->nMaxPage - (unsigned int)m_pd->nMinPage + 9) / 0xA,
          bClearRatios: 1);
        return;
      case 3u:
        v5 = this->m_pPreviewInfo->m_pPD->m_pd;
        nMinPage = this->m_nCurrentPage + (v5->nMaxPage - (unsigned int)v5->nMinPage + 9) / 0xA;
        break;
      case 4u:
        CPreviewView::SetCurrentPage(this, nPage: nPos, bClearRatios: 1);
        return;
      case 6u:
        nMinPage = this->m_pPreviewInfo->m_pPD->m_pd->nMinPage;
        break;
      case 7u:
        nMinPage = this->m_pPreviewInfo->m_pPD->m_pd->nMaxPage;
        break;
      default:
        return;
    }
  }
  else
  {
    nMinPage = this->m_nCurrentPage - 1;
  }
  CPreviewView::SetCurrentPage(this, nPage: nMinPage, bClearRatios: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035C657
// Name: protected: void CPreviewView::OnNumPageChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnNumPageChange(CPreviewView *this)
{
  unsigned int m_nCurrentPage; // [esp-8h] [ebp-10h]

  this->m_nPages = 3 - this->m_nPages;
  AfxGetModuleState()->m_pCurrentWinApp->m_nNumPreviewPages = this->m_nPages;
  m_nCurrentPage = this->m_nCurrentPage;
  this->m_nZoomOutPages = this->m_nPages;
  CPreviewView::SetCurrentPage(this, nPage: m_nCurrentPage, bClearRatios: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035C69E
// Name: protected: void CPreviewView::OnNextPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnNextPage(CPreviewView *this)
{
  CPreviewView::SetCurrentPage(this, nPage: this->m_nCurrentPage + 1, bClearRatios: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035C6AE
// Name: protected: void CPreviewView::OnPrevPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnPrevPage(CPreviewView *this)
{
  CPreviewView::SetCurrentPage(this, nPage: this->m_nCurrentPage - 1, bClearRatios: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035C6BE
// Name: protected: void CPreviewView::DoZoom(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::DoZoom(CPreviewView *this, unsigned int nPage, CPoint point)
{
  tagPDA *m_pd; // eax
  int nMaxPage; // ecx
  CPrintInfo *m_pPreviewInfo; // eax
  CPreviewView::PAGE_INFO *m_pPageInfo; // eax
  CSize *p_sizeScaleRatio; // edi
  CPreviewView::PAGE_INFO *v9; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-3Ch]
  BOOL bShowBar; // [esp+Ch] [ebp-24h]
  tagSCROLLINFO info; // [esp+10h] [ebp-20h] BYREF

  if ( this->m_nZoomState != 0 )
  {
    m_pPageInfo = this->m_pPageInfo;
    this->m_nPages = 1;
    m_pPageInfo->sizeZoomOutRatio = m_pPageInfo[nPage].sizeZoomOutRatio;
    this->m_pPageInfo->sizeUnscaled = this->m_pPageInfo[nPage].sizeUnscaled;
    CPreviewView::SetCurrentPage(this, nPage: nPage + this->m_nCurrentPage, bClearRatios: 0);
    CPreviewView::SetScaledSize(this, nPage: 0);
    p_sizeScaleRatio = &this->m_pPageInfo[nPage].sizeScaleRatio;
    point.x = MulDiv(nNumber: point.x, nNumerator: p_sizeScaleRatio->cx, nDenominator: p_sizeScaleRatio->cy);
    point.y = MulDiv(nNumber: point.y, nNumerator: p_sizeScaleRatio->cx, nDenominator: p_sizeScaleRatio->cy);
    v9 = this->m_pPageInfo;
    point.y += v9->rectScreen.top;
    point.x += v9->rectScreen.left;
    CScrollView::CenterOnPoint(this, ptCenter: point);
  }
  else
  {
    m_hWnd = this->m_hWnd;
    this->m_nPages = this->m_nZoomOutPages;
    ShowScrollBar(hWnd: m_hWnd, wBar: 0, bShow: false);
    m_pd = this->m_pPreviewInfo->m_pPD->m_pd;
    nMaxPage = m_pd->nMaxPage;
    if ( (unsigned __int16)nMaxPage >= 0x8000u || (bShowBar = true, nMaxPage - (unsigned int)m_pd->nMinPage > 0x7FFF) )
      bShowBar = false;
    ShowScrollBar(hWnd: this->m_hWnd, wBar: 1, bShow: bShowBar);
    if ( bShowBar )
    {
      m_pPreviewInfo = this->m_pPreviewInfo;
      info.fMask = 3;
      info.nMin = m_pPreviewInfo->m_pPD->m_pd->nMinPage;
      info.nMax = m_pPreviewInfo->m_pPD->m_pd->nMaxPage;
      info.nPage = 1;
      if ( CWnd::SetScrollInfo(this, nBar: 1, lpScrollInfo: &info, bRedraw: 0) == 0 )
        CWnd::SetScrollRange(this, nBar: 1, nMinPos: info.nMin, nMaxPos: info.nMax, bRedraw: 0);
    }
    CPreviewView::SetCurrentPage(this, nPage: this->m_nCurrentPage, bClearRatios: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035C84F
// Name: public: static class CObject __near * CPreviewView::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPreviewView *__stdcall CPreviewView::CreateObject()
{
  CPreviewView *v0; // ecx
  CPreviewView *result; // eax

  v0 = (CPreviewView *)operator new(nSize: 0x15Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CPreviewView::CPreviewView(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035C87F
// Name: public: CPrintPreviewState::CPrintPreviewState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPrintPreviewState *__thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this)
{
  this->nIDMainPane = 59648;
  this->dwStates = 2;
  this->lpfnCloseProc = _AfxPreviewCloseProc;
  this->hMenu = nullptr;
  this->pViewActiveOld = nullptr;
  this->hAccelTable = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035C8A1
// Name: public: int CView::DoPrintPreview(unsigned int,class CView __near *,struct CRuntimeClass __near *,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::DoPrintPreview(
        CView *this,
        unsigned __int16 nIDResource,
        CView *pPrintView,
        CRuntimeClass *pPreviewViewClass,
        CPrintPreviewState *pState)
{
  CFrameWnd *ParentFrame; // edi
  CDocument *m_pDocument; // eax
  CPreviewView *Object; // esi
  CDialogBar *v10; // eax
  CDialogBar *v11; // eax
  CObject *v12; // eax
  CObject *v13; // eax
  CDialogBar *m_pToolBar; // ecx
  IOleInPlaceUIWindow *v15; // eax
  CPreviewView_vtbl *v16; // eax
  CView *ActiveView; // eax
  CFrameWnd *v18; // eax
  CView *v19; // eax
  CPrintPreviewState *v20; // [esp-4h] [ebp-6Ch]
  CMFCColorPickerCtrl::COLORTYPE v21; // [esp-4h] [ebp-6Ch]
  unsigned __int8 dst[20]; // [esp+10h] [ebp-58h] BYREF
  void *pData; // [esp+24h] [ebp-44h]
  CRuntimeClass *v24; // [esp+28h] [ebp-40h]
  CMFCColorPickerCtrl::COLORTYPE colorType; // [esp+2Ch] [ebp-3Ch]
  CPrintPreviewState *v26; // [esp+30h] [ebp-38h]
  IOleInPlaceUIWindow *ppUIWindow; // [esp+34h] [ebp-34h] BYREF
  _DWORD v28[4]; // [esp+38h] [ebp-30h] BYREF
  _DWORD v29[7]; // [esp+48h] [ebp-20h] BYREF
  int v30; // [esp+64h] [ebp-4h]

  v24 = pPreviewViewClass;
  ppUIWindow = (IOleInPlaceUIWindow *)this;
  v26 = pState;
  ParentFrame = CWnd::GetParentFrame(this);
  if ( AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: ParentFrame) == nullptr )
    ParentFrame = (CFrameWnd *)AfxGetMainWnd();
  memset(dst, value: 0, count: sizeof(dst));
  m_pDocument = this->m_pDocument;
  *(_DWORD *)&dst[16] = ParentFrame;
  *(_DWORD *)&dst[4] = m_pDocument;
  *(_DWORD *)&dst[12] = this;
  Object = (CPreviewView *)CRuntimeClass::CreateObject(this: v24);
  if ( Object == nullptr )
    return 0;
  v20 = v26;
  Object->m_pPreviewState = v26;
  ParentFrame->OnSetPreviewMode(this: ParentFrame, a2: 1, a3: v20);
  v10 = (CDialogBar *)operator new(nSize: 0xC8u);
  pData = v10;
  v30 = 0;
  if ( v10 != nullptr )
    v11 = CDialogBar::CDialogBar(this: v10);
  else
    v11 = nullptr;
  v30 = -1;
  Object->m_pToolBar = v11;
  v12 = ParentFrame->GetActiveFrame(this: ParentFrame);
  colorType = (CMFCColorPickerCtrl::COLORTYPE)AfxDynamicDownCast(
                                                pClass: &COleIPFrameWnd::classCOleIPFrameWnd,
                                                pObject: v12);
  if ( colorType == CURRENT )
  {
    if ( Object->m_pToolBar->Create(
           this: Object->m_pToolBar,
           a2: ParentFrame,
           a3: (const char *)nIDResource,
           a4: 10240u,
           a5: 59394u) != 0 )
    {
      Object->m_pToolBar->m_bAutoDelete = 1;
      goto LABEL_26;
    }
LABEL_10:
    ParentFrame->OnSetPreviewMode(this: ParentFrame, a2: 0, a3: v26);
    m_pToolBar = Object->m_pToolBar;
    if ( m_pToolBar != nullptr )
      ((void (__thiscall *)(CDialogBar *, int))m_pToolBar->dtr_CObject)(a1: m_pToolBar, a2: 1);
    Object->m_pToolBar = nullptr;
    goto LABEL_13;
  }
  v13 = AfxDynamicDownCast(pClass: &COleServerDoc::classCOleServerDoc, pObject: (CObject *)ppUIWindow[29].__vftable);
  pData = v13;
  if ( v13 == nullptr )
    goto LABEL_10;
  ppUIWindow = *(IOleInPlaceUIWindow **)(colorType + 308);
  if ( ppUIWindow == nullptr )
    ppUIWindow = *(IOleInPlaceUIWindow **)(colorType + 304);
  v13->__vftable[30].Serialize(this: v13, a2: nullptr);
  if ( ppUIWindow == nullptr
    || Object->m_pToolBar->Create(
         this: Object->m_pToolBar,
         a2: (CWnd *)ppUIWindow,
         a3: (const char *)nIDResource,
         a4: 10240u,
         a5: 59394u) == 0 )
  {
    goto LABEL_10;
  }
  v21 = colorType;
  Object->m_pToolBar->m_bAutoDelete = 1;
  CControlBar::SetInPlaceOwner(this: (CMFCColorPickerCtrl *)Object->m_pToolBar, colorType: v21);
  memset(v29, 0, 16);
  v24 = nullptr;
  ppUIWindow = nullptr;
  v30 = 1;
  if ( COleIPFrameWnd::GetInPlaceDocFrame(this: (COleIPFrameWnd *)colorType, &ppUIWindow) < 0 )
  {
    COleIPFrameWnd::GetInPlaceFrame(this: (COleIPFrameWnd *)colorType, &ppUIWindow);
    v24 = (CRuntimeClass *)1;
  }
  v15 = ppUIWindow;
  if ( ppUIWindow != nullptr )
  {
    ppUIWindow->GetBorder(this: ppUIWindow, a2: (tagRECT *)v29);
    (*(void (__thiscall **)(void *, _DWORD *, IOleInPlaceUIWindow *, CRuntimeClass *))(*(_DWORD *)pData + 396))(
      a1: pData,
      a2: v29,
      a3: ppUIWindow,
      a4: v24);
    v15 = ppUIWindow;
  }
  v30 = -1;
  *(_DWORD *)(colorType + 380) = 1;
  if ( v15 != nullptr )
    v15->Release(this: v15);
LABEL_26:
  v16 = Object->__vftable;
  memset(v28, 0, sizeof(v28));
  if ( v16->Create(
         this: Object,
         a2: nullptr,
         a3: nullptr,
         a4: 1350565888u,
         a5: (const tagRECT *)v28,
         a6: ParentFrame,
         a7: 59648u,
         a8: (CCreateContext *)dst) == 0 )
  {
    ParentFrame->OnSetPreviewMode(this: ParentFrame, a2: 0, a3: v26);
LABEL_13:
    Object->m_pPreviewState = nullptr;
    ((void (__thiscall *)(CPreviewView *, int))Object->dtr_CObject)(a1: Object, a2: 1);
    return 0;
  }
  ActiveView = CFrameWnd::GetActiveView(this: ParentFrame);
  v26->pViewActiveOld = ActiveView;
  v18 = ParentFrame->GetActiveFrame(this: ParentFrame);
  v19 = CFrameWnd::GetActiveView(this: v18);
  if ( v19 != nullptr )
    v19->OnActivateView(this: v19, a2: 0, a3: v19, a4: v19);
  if ( CPreviewView::SetPrintView(this: Object, pPrintView) != 0 )
  {
    CFrameWnd::SetActiveView(this: ParentFrame, pViewNew: Object, bNotify: 1);
    SendMessageA(hWnd: Object->m_pToolBar->m_hWnd, Msg: 0x363u, wParam: 1u, lParam: 0);
    ParentFrame->RecalcLayout(this: ParentFrame, a2: 1);
    UpdateWindow(hWnd: ParentFrame->m_hWnd);
  }
  else
  {
    CPreviewView::OnPreviewClose(this: Object);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035CBA8
// Name: protected: void CPreviewView::SetZoomState(unsigned int,unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::SetZoomState(
        CPreviewView *this,
        unsigned int nNewState,
        unsigned int nPage,
        CPoint point)
{
  if ( this->m_nZoomState != nNewState )
  {
    this->m_nZoomState = nNewState;
    CPreviewView::DoZoom(this, nPage, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035CBD0
// Name: protected: void CPreviewView::OnZoomIn(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnZoomIn(CPreviewView *this)
{
  unsigned int m_nZoomState; // eax

  m_nZoomState = this->m_nZoomState;
  if ( m_nZoomState != 2 )
    CPreviewView::SetZoomState(this, nNewState: m_nZoomState + 1, nPage: 0, point: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1035CBEC
// Name: protected: void CPreviewView::OnZoomOut(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnZoomOut(CPreviewView *this)
{
  unsigned int m_nZoomState; // eax

  m_nZoomState = this->m_nZoomState;
  if ( m_nZoomState != 0 )
    CPreviewView::SetZoomState(this, nNewState: m_nZoomState - 1, nPage: 0, point: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1035CC07
// Name: protected: virtual void CPreviewView::OnDisplayPageNumber(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnDisplayPageNumber(CPreviewView *this, unsigned int nPage, unsigned int nPagesDisplayed)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // eax
  int v6; // eax
  CWnd *m_pMainWnd; // [esp+10h] [ebp-6Ch]
  ATL::CSimpleStringT<char,0> v8; // [esp+18h] [ebp-64h] BYREF
  char string[92]; // [esp+1Ch] [ebp-60h] BYREF
  int v10; // [esp+78h] [ebp-4h]

  m_pMainWnd = AfxGetThread()->m_pMainWnd;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v8, pStringMgr: StringManager);
  m_pszData = this->m_pPreviewInfo->m_strPageDesc.m_pszData;
  v10 = 0;
  if ( AfxExtractSubString(
         rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v8,
         lpszFullString: m_pszData,
         iSubString: nPagesDisplayed != 1,
         chSep: 10) != 0 )
  {
    if ( nPagesDisplayed == 1 )
      v6 = sprintf_s(string, sizeInBytes: 0x50u, format: v8.m_pszData, nPage);
    else
      v6 = sprintf_s(string, sizeInBytes: 0x50u, format: v8.m_pszData, nPage, nPage + nPagesDisplayed - 1);
    if ( v6 > 0 )
      SendMessageA(hWnd: m_pMainWnd->m_hWnd, Msg: 0x362u, wParam: 0, lParam: (LPARAM)string);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)v8.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035CCBB
// Name: protected: void CView::OnFilePrintPreview(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnFilePrintPreview(CView *this)
{
  CPrintPreviewState *v2; // eax
  CPrintPreviewState *pState; // [esp+14h] [ebp-14h]

  v2 = (CPrintPreviewState *)operator new(nSize: 0x18u);
  if ( v2 != nullptr )
    pState = CPrintPreviewState::CPrintPreviewState(this: v2);
  else
    pState = nullptr;
  if ( CView::DoPrintPreview(
         this,
         nIDResource: 0x7803u,
         pPrintView: this,
         pPreviewViewClass: &CPreviewView::classCPreviewView,
         pState) == 0 )
  {
    AfxMessageBox(nIDPrompt: 0xF109u, nType: 0, nIDHelp: 0xFFFFFFFF);
    operator delete(p: pState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035CD31
// Name: protected: void CPreviewView::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnLButtonDown(CPreviewView *this, unsigned int __formal, CPoint point)
{
  unsigned int m_nZoomState; // eax
  unsigned int v5; // eax
  unsigned int nPage; // [esp+4h] [ebp-4h] BYREF

  if ( CPreviewView::FindPageRect(this, &point, &nPage) != 0 )
  {
    m_nZoomState = this->m_nZoomState;
    if ( m_nZoomState == 2 )
      v5 = 0;
    else
      v5 = m_nZoomState + 1;
    CPreviewView::SetZoomState(this, nNewState: v5, nPage, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035CD71
// Name: protected: void CPreviewView::OnUpdateNumPageChange(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnUpdateNumPageChange(CPreviewView *this, CCmdUI *pCmdUI)
{
  CAfxStringMgr *StringManager; // eax
  unsigned int m_nZoomOutPages; // eax
  unsigned int v5; // edi
  HINSTANCE__ *StringResourceHandle; // eax
  char *m_pszData; // ebx
  int v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > text; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &text, pStringMgr: StringManager);
  v10 = 0;
  if ( this->m_nZoomState != 0 )
    m_nZoomOutPages = this->m_nZoomOutPages;
  else
    m_nZoomOutPages = this->m_nPages;
  v5 = 61506 - (m_nZoomOutPages != 1);
  StringResourceHandle = AfxFindStringResourceHandle(__formal: v5);
  if ( StringResourceHandle == nullptr
    || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: &text,
         hInstance: StringResourceHandle,
         nID: v5) == 0 )
  {
    AfxThrowInvalidArgException();
  }
  m_pszData = text.m_pszData;
  pCmdUI->SetText(this: pCmdUI, a2: text.m_pszData);
  if ( this->m_nZoomState != 0
    || (v8 = 1, this->m_nMaxPages == 1)
    || this->m_pPreviewInfo->m_pPD->m_pd->nMaxPage <= 1u && this->m_nPages <= 1 )
  {
    v8 = 0;
  }
  pCmdUI->Enable(this: pCmdUI, a2: v8);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035CE27
// Name: protected: int CPreviewView::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewView::OnEraseBkgnd(CPreviewView *this, CDC *pDC)
{
  COLORREF SysColor; // eax
  CFont *v3; // ebx
  CDC_vtbl *v4; // eax
  CBrush v6; // [esp+10h] [ebp-28h] BYREF
  int x; // [esp+18h] [ebp-20h] BYREF
  int y; // [esp+1Ch] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-18h]
  int v10; // [esp+24h] [ebp-14h]
  int v11; // [esp+34h] [ebp-4h]

  SysColor = GetSysColor(nIndex: 12);
  CBrush::CBrush(this: &v6, crColor: SysColor);
  v11 = 0;
  v3 = CDC::SelectObject(this: pDC, pFont: (CFont *)&v6);
  v4 = pDC->__vftable;
  x = 0;
  y = 0;
  v9 = 0;
  v10 = 0;
  v4->GetClipBox(this: pDC, a2: (tagRECT *)&x);
  PatBlt(hdc: pDC->m_hDC, x, y, w: v9 - x, h: v10 - y, rop: 0xF00021u);
  CDC::SelectObject(this: pDC, pFont: v3);
  v11 = -1;
  v6.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035CEB8
// Name: protected: virtual void CPreviewView::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnDraw(CPreviewView *this, CDC *pDC)
{
  CDC *v2; // edi
  COLORREF SysColor; // eax
  HPEN Pen; // eax
  COLORREF v6; // eax
  unsigned int v7; // esi
  HPEN v8; // eax
  HDC__ *m_hDC; // eax
  unsigned int m_nCurrentPage; // eax
  int DeviceCaps; // eax
  CPreviewView::PAGE_INFO *v12; // esi
  bool v13; // zf
  CPoint *DeviceScrollPosition; // eax
  int v15; // ecx
  int cx; // ecx
  int cy; // ecx
  int *p_top; // esi
  HBRUSH StockObject; // eax
  CDC *v20; // esi
  CPrintInfo *m_pPreviewInfo; // eax
  unsigned int v22; // esi
  unsigned int v23; // ecx
  CPreviewView_vtbl *v24; // edx
  int *v25; // esi
  CPreviewDC *m_pPreviewDC; // ecx
  int v27; // eax
  int v28; // esi
  unsigned int v29; // eax
  CPoint v30; // [esp+10h] [ebp-8Ch] BYREF
  CPoint v31; // [esp+18h] [ebp-84h] BYREF
  CPoint v32; // [esp+20h] [ebp-7Ch] BYREF
  CPoint v33; // [esp+28h] [ebp-74h] BYREF
  CPoint v34; // [esp+30h] [ebp-6Ch] BYREF
  CDC *v35; // [esp+38h] [ebp-64h]
  int v36; // [esp+3Ch] [ebp-60h]
  CGdiObject v37; // [esp+40h] [ebp-5Ch] BYREF
  CGdiObject v38; // [esp+48h] [ebp-54h] BYREF
  int yBottom; // [esp+50h] [ebp-4Ch]
  unsigned int v40; // [esp+54h] [ebp-48h]
  CPoint result; // [esp+58h] [ebp-44h] BYREF
  unsigned int v42; // [esp+60h] [ebp-3Ch]
  tagPOINT Point; // [esp+64h] [ebp-38h] BYREF
  RECT rc; // [esp+6Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+7Ch] [ebp-20h] BYREF
  int v46; // [esp+98h] [ebp-4h]

  v2 = pDC;
  v35 = pDC;
  if ( this->m_pPrintView != nullptr && this->m_dcPrint.m_hDC != nullptr )
  {
    CDC::GetViewportOrg(this: pDC, &result);
    v37.m_hObject = nullptr;
    v37.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
    v46 = 0;
    SysColor = GetSysColor(nIndex: 6);
    Pen = CreatePen(iStyle: 0, cWidth: 2, color: SysColor);
    CGdiObject::Attach(this: &v37, hObject: Pen);
    v38.m_hObject = nullptr;
    v38.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
    LOBYTE(v46) = 1;
    v6 = GetSysColor(nIndex: 16);
    v7 = 0;
    v8 = CreatePen(iStyle: 0, cWidth: 3, color: v6);
    CGdiObject::Attach(this: &v38, hObject: v8);
    this->m_pPreviewInfo->m_bContinuePrinting = 1;
    v42 = 0;
    if ( this->m_nPages != 0 )
    {
      v40 = 0;
      while ( 1 )
      {
        v36 = this->m_dcPrint.SaveDC(this: &this->m_dcPrint);
        if ( v2 != nullptr )
          m_hDC = v2->m_hDC;
        else
          m_hDC = nullptr;
        this->m_pPreviewDC->SetOutputDC(this: this->m_pPreviewDC, a2: m_hDC);
        this->m_pPreviewInfo->m_nCurPage = v7 + this->m_nCurrentPage;
        m_nCurrentPage = this->m_nCurrentPage;
        if ( m_nCurrentPage + v7 >= m_nCurrentPage
          && v7 + m_nCurrentPage >= v7
          && v7 + m_nCurrentPage <= this->m_pPreviewInfo->m_pPD->m_pd->nMaxPage )
        {
          this->m_pPrintView->OnPrepareDC(this: this->m_pPrintView, a2: this->m_pPreviewDC, a3: this->m_pPreviewInfo);
        }
        yBottom = GetDeviceCaps(hdc: this->m_pPreviewDC->m_hAttribDC, index: 10);
        DeviceCaps = GetDeviceCaps(hdc: this->m_pPreviewDC->m_hAttribDC, index: 8);
        SetRect(lprc: &this->m_pPreviewInfo->m_rectDraw, xLeft: 0, yTop: 0, xRight: DeviceCaps, yBottom);
        DPtoLP(hdc: this->m_pPreviewDC->m_hAttribDC, lppt: (LPPOINT)&this->m_pPreviewInfo->m_rectDraw, c: 2);
        v2->SaveDC(this: v2);
        v12 = &this->m_pPageInfo[v40 / 0x28];
        v13 = v12->sizeScaleRatio.cx == 0;
        yBottom = (int)v12;
        if ( v13 )
        {
          this->PositionPage(this, a2: v42);
          if ( this->m_nZoomState != 0 )
          {
            DeviceScrollPosition = CScrollView::GetDeviceScrollPosition(this, result: &v30);
            v15 = -DeviceScrollPosition->y;
            v13 = this->m_bCenter == 0;
            result.x = -DeviceScrollPosition->x;
            result.y = v15;
            if ( !v13 )
            {
              memset(&Rect, 0, sizeof(Rect));
              GetClientRect(hWnd: this->m_hWnd, lpRect: &Rect);
              cx = this->m_totalDev.cx;
              if ( cx < Rect.right - Rect.left )
                result.x = (Rect.right - Rect.left - cx) / 2;
              cy = this->m_totalDev.cy;
              if ( cy < Rect.bottom - Rect.top )
                result.y = (Rect.bottom - Rect.top - cy) / 2;
            }
          }
        }
        v2->SetMapMode(this: v2, a2: 1);
        v2->SetViewportOrg(this: v2, result: &v32, a3: result.x, a4: result.y);
        CDC::SetWindowOrg(this: v2, result: &v34, x: 0, y: 0);
        v2->SelectStockObject(this: v2, a2: 5);
        CDC::SelectObject(this: v2, pFont: (CFont *)&v37);
        CDC::Rectangle(this: v2, lpRect: &v12->rectScreen);
        CDC::SelectObject(this: v2, pFont: (CFont *)&v38);
        CDC::MoveTo(this: v2, result: &v31, x: v12->rectScreen.right + 1, y: v12->rectScreen.top + 3);
        CDC::LineTo(this: v2, x: v12->rectScreen.right + 1, y: v12->rectScreen.bottom + 1);
        CDC::MoveTo(this: v2, result: &v33, x: v12->rectScreen.left + 3, y: v12->rectScreen.bottom + 1);
        CDC::LineTo(this: v2, x: v12->rectScreen.right + 1, y: v12->rectScreen.bottom + 1);
        rc.left = v12->rectScreen.left;
        p_top = &v12->rectScreen.top;
        rc.top = *p_top++;
        rc.right = *p_top;
        rc.bottom = p_top[1];
        ++rc.left;
        ++rc.top;
        rc.right -= 2;
        rc.bottom -= 2;
        StockObject = (HBRUSH)GetStockObject(i: 0);
        v20 = v35;
        FillRect(hDC: v35->m_hDC, lprc: &rc, hbr: StockObject);
        v20->RestoreDC(this: v20, a2: -1);
        m_pPreviewInfo = this->m_pPreviewInfo;
        v22 = v42;
        if ( m_pPreviewInfo->m_bContinuePrinting == 0 )
          break;
        v23 = this->m_nCurrentPage;
        if ( v23 + v42 > m_pPreviewInfo->m_pPD->m_pd->nMaxPage )
          break;
        v24 = this->__vftable;
        v24->OnDisplayPageNumber(this, a2: v23, a3: ++v42);
        v25 = (int *)yBottom;
        CPreviewDC::SetScaleRatio(
          this: this->m_pPreviewDC,
          nNumerator: *(_DWORD *)(yBottom + 24),
          nDenominator: *(_DWORD *)(yBottom + 28));
        m_pPreviewDC = this->m_pPreviewDC;
        Point.x = 0;
        Point.y = 0;
        m_pPreviewDC->Escape(this: m_pPreviewDC, a2: 13, a3: 0, a4: nullptr, a5: &Point);
        CPreviewDC::PrinterDPtoScreenDP(this: this->m_pPreviewDC, lpPoint: &Point);
        v27 = *v25;
        v28 = v25[1];
        Point.x += v27;
        Point.y += v28;
        ++Point.x;
        Point.x += result.x;
        ++Point.y;
        Point.y += result.y;
        CPreviewDC::SetTopLeftOffset(this: this->m_pPreviewDC, sizeTopLeft: (CSize)Point);
        CPreviewDC::ClipToPage(this: this->m_pPreviewDC);
        this->m_pPrintView->OnPrint(this: this->m_pPrintView, a2: this->m_pPreviewDC, a3: this->m_pPreviewInfo);
        this->m_pPreviewDC->ReleaseOutputDC(this: this->m_pPreviewDC);
        this->m_dcPrint.RestoreDC(this: &this->m_dcPrint, a2: v36);
        v40 += 40;
        if ( v42 >= this->m_nPages )
          goto LABEL_27;
        v2 = v35;
        v7 = v42;
      }
      this->m_pPreviewDC->ReleaseOutputDC(this: this->m_pPreviewDC);
      this->m_dcPrint.RestoreDC(this: &this->m_dcPrint, a2: v36);
      if ( v22 == 0 )
      {
        v29 = this->m_nCurrentPage;
        if ( v29 > 1 )
          CPreviewView::SetCurrentPage(this, nPage: v29 - 1, bClearRatios: 1);
      }
    }
LABEL_27:
    CGdiObject::DeleteObject(this: &v37);
    CGdiObject::DeleteObject(this: &v38);
    LOBYTE(v46) = 0;
    v38.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
    CGdiObject::~CGdiObject(this: &v38);
    v46 = -1;
    v37.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
    CGdiObject::~CGdiObject(this: &v37);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D33A
// Name: protected: static struct AFX_MSGMAP const __near * CPreviewView::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CPreviewView::GetThisMessageMap(CPreviewView *this)
{
  return &messageMap_24;
}

//------------------------------------------------------------------------------
// Address: 0x1035D340
// Name: void AfxTextFloatFormat(class CDataExchange __near *,int,void __near *,double,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxTextFloatFormat(
        CDataExchange *pDX,
        HWND__ *nIDC,
        CDataExchange *pData,
        long double value,
        int nSizeGcvt)
{
  int v5; // esi
  int *v6; // eax
  double v7; // [esp+10h] [ebp-1A0h] BYREF
  long double d; // [esp+18h] [ebp-198h] BYREF

  CDataExchange::PrepareEditCtrl(this: pDX, nIDC);
  CWnd::GetDlgItem(this: pDX->m_pDlgWnd, nID: (int)nIDC, phWnd: (HWND__ **)&d);
  if ( pDX->m_bSaveAndValidate != 0 )
  {
    GetWindowTextA(hWnd: (HWND)LODWORD(d), lpString: (LPSTR)&d + 4, nMaxCount: 400);
    if ( _snscanf_s(string: (const char *)&d + 4, count: 0x190u, format: "%lf", &v7) != 1 )
    {
      AfxMessageBox(nIDPrompt: 0xF111u, nType: 0, nIDHelp: 0xFFFFFFFF);
      CDataExchange::Fail(this: pDX);
    }
    if ( nSizeGcvt == 6 )
      *(float *)&pData->m_bSaveAndValidate = v7;
    else
      *(double *)&pData->m_bSaveAndValidate = v7;
  }
  else
  {
    v5 = *_errno();
    *_errno() = 0;
    _snprintf_s(string: (char *)&d + 4, sizeInBytes: 0x190u, count: 0x18Fu, format: "%.*g", nSizeGcvt, (double)value);
    if ( *_errno() != 0 )
    {
      v6 = _errno();
      ATL::AtlCrtErrorCheck(nError: *v6);
    }
    else
    {
      *_errno() = v5;
    }
    AfxSetWindowText(hWndCtrl: (HWND__ *)LODWORD(d), lpszNew: (const char *)&d + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D464
// Name: void DDX_Text(class CDataExchange __near *,int,float __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Text(CDataExchange *pDX, HWND__ *nIDC, CDataExchange *value)
{
  AfxTextFloatFormat(pDX, nIDC, pData: value, value: *(float *)&value->m_bSaveAndValidate, nSizeGcvt: 6);
}

//------------------------------------------------------------------------------
// Address: 0x1035D485
// Name: void _AfxFailMinMaxReal(class CDataExchange __near *,double,double,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxFailMinMaxReal(
        CDataExchange *pDX,
        long double minVal,
        long double maxVal,
        unsigned int precision,
        unsigned int nIDPrompt)
{
  CAfxStringMgr *StringManager; // eax
  int v6; // ebx
  int *v7; // eax
  int v8; // ebx
  int *v9; // eax
  ATL::CSimpleStringT<char,0> v10; // [esp+1Ch] [ebp-54h] BYREF
  CDataExchange *v11; // [esp+20h] [ebp-50h] BYREF
  char v12[8]; // [esp+40h] [ebp-30h] BYREF
  int v13; // [esp+6Ch] [ebp-4h]

  if ( pDX->m_bSaveAndValidate != 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v10, pStringMgr: StringManager);
    v13 = 0;
    v6 = *_errno();
    *_errno() = 0;
    _snprintf_s(string: (char *)&v11, sizeInBytes: 0x20u, count: 0x1Fu, format: "%.*g", precision, (double)minVal);
    if ( *_errno() != 0 )
    {
      v7 = _errno();
      ATL::AtlCrtErrorCheck(nError: *v7);
    }
    else
    {
      *_errno() = v6;
    }
    v8 = *_errno();
    *_errno() = 0;
    _snprintf_s(string: v12, sizeInBytes: 0x20u, count: 0x1Fu, format: "%.*g", precision, (double)maxVal);
    if ( *_errno() != 0 )
    {
      v9 = _errno();
      ATL::AtlCrtErrorCheck(nError: *v9);
    }
    else
    {
      *_errno() = v8;
    }
    AfxFormatString2(
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v10,
      nIDS: nIDPrompt,
      lpsz1: (const char *)&v11,
      lpsz2: v12);
    AfxMessageBox(lpszText: v10.m_pszData, nType: 0x30u, nIDHelp: nIDPrompt);
    ATL::CSimpleStringT<char,0>::Empty(this: &v10);
    CDataExchange::Fail(this: pDX);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D58D
// Name: void DDV_MinMaxFloat(class CDataExchange __near *,float const __near &,float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDV_MinMaxFloat(CDataExchange *pDX, const float *value, float minVal, float maxVal)
{
  if ( minVal > (double)*value || maxVal < (double)*value )
    _AfxFailMinMaxReal(pDX, minVal, maxVal, precision: 6u, nIDPrompt: 0xF113u);
}

//------------------------------------------------------------------------------
// Address: 0x1035D5D4
// Name: public: static struct CPlex __near * CPlex::Create(struct CPlex __near * __near &,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPlex *__stdcall CPlex::Create(CPlex **pHead, unsigned int nMax, unsigned int cbElement)
{
  CPlex *result; // eax

  if ( nMax == 0 || cbElement == 0 )
    AfxThrowInvalidArgException();
  result = (CPlex *)operator new(nSize: cbElement * nMax + 4);
  result->pNext = *pHead;
  *pHead = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035D607
// Name: public: void CPlex::FreeDataChain(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPlex::FreeDataChain(CPlex *this)
{
  CPlex *pNext; // esi

  if ( this != nullptr )
  {
    do
    {
      pNext = this->pNext;
      operator delete(p: this);
      this = pNext;
    }
    while ( pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035D61D
// Name: public: virtual struct CRuntimeClass __near * CStringList::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CStringList::GetRuntimeClass(CStringList *this)
{
  return &CStringList::classCStringList;
}

//------------------------------------------------------------------------------
// Address: 0x1035D623
// Name: public: CStringList::CStringList(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList *__thiscall CStringList::CStringList(CStringList *this, int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CStringList_vtbl *)&CStringList::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035D64B
// Name: public: static class CObject __near * CStringList::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList *__stdcall CStringList::CreateObject()
{
  CStringList *v0; // eax

  v0 = (CStringList *)operator new(nSize: 0x1Cu);
  if ( v0 != nullptr )
    return CStringList::CStringList(this: v0, nBlockSize: 10);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1035D664
// Name: protected: struct CStringList::CNode __near * CStringList::NewNode(struct CStringList::CNode __near *,struct CStringList::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList::CNode *__thiscall CStringList::NewNode(
        CStringList *this,
        CStringList::CNode *pPrev,
        CStringList::CNode *pNext)
{
  CPlex *v4; // eax
  int v5; // ecx
  CStringList::CNode *i; // eax
  CStringList::CNode *m_pNodeFree; // edi
  CAfxStringMgr *StringManager; // eax

  if ( this->m_pNodeFree == nullptr )
  {
    v4 = CPlex::Create(pHead: &this->m_pBlocks, nMax: this->m_nBlockSize, cbElement: 0xCu);
    v5 = this->m_nBlockSize - 1;
    for ( i = (CStringList::CNode *)&v4[3 * this->m_nBlockSize - 2]; v5 >= 0; --v5 )
    {
      i->pNext = this->m_pNodeFree;
      this->m_pNodeFree = i--;
    }
  }
  m_pNodeFree = this->m_pNodeFree;
  this->m_pNodeFree = m_pNodeFree->pNext;
  m_pNodeFree->pPrev = pPrev;
  m_pNodeFree->pNext = pNext;
  ++this->m_nCount;
  if ( m_pNodeFree == (CStringList::CNode *)-8 )
    AfxThrowInvalidArgException();
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &m_pNodeFree->data, pStringMgr: StringManager);
  return m_pNodeFree;
}

//------------------------------------------------------------------------------
// Address: 0x1035D6D5
// Name: public: struct __POSITION __near * CStringList::Find(char const __near *,struct __POSITION __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStringList::CNode *__thiscall CStringList::Find(CStringList *this, const char *searchValue, __POSITION *startAfter)
{
  CStringList::CNode *m_pNodeHead; // esi

  if ( startAfter != nullptr )
    m_pNodeHead = *(CStringList::CNode **)startAfter;
  else
    m_pNodeHead = this->m_pNodeHead;
  while ( 1 )
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: &m_pNodeHead->data,
           psz: searchValue) == 0 )
      break;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  return m_pNodeHead;
}

//------------------------------------------------------------------------------
// Address: 0x1035D70B
// Name: public: void CStringList::RemoveAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringList::RemoveAll(CStringList *this)
{
  CStringList::CNode *i; // esi
  CPlex *m_pBlocks; // ecx

  for ( i = this->m_pNodeHead; i != nullptr; i = i->pNext )
  {
    if ( i == (CStringList::CNode *)-8 )
      AfxThrowInvalidArgException();
    ATL::CStringData::Release(this: (ATL::CStringData *)i->data.m_pszData - 1);
  }
  m_pBlocks = this->m_pBlocks;
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  CPlex::FreeDataChain(this: m_pBlocks);
  this->m_pBlocks = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1035D751
// Name: public: virtual CStringList::~CStringList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringList::~CStringList(CStringList *this)
{
  this->__vftable = (CStringList_vtbl *)&CStringList::`vftable';
  CStringList::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035D75C
// Name: protected: void CStringList::FreeNode(struct CStringList::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStringList::FreeNode(CStringList *this, CStringList::CNode *pNode)
{
  bool v3; // zf

  if ( pNode == nullptr || pNode == (CStringList::CNode *)-8 )
    AfxThrowInvalidArgException();
  ATL::CStringData::Release(this: (ATL::CStringData *)pNode->data.m_pszData - 1);
  pNode->pNext = this->m_pNodeFree;
  v3 = this->m_nCount-- == 1;
  this->m_pNodeFree = pNode;
  if ( v3 )
    CStringList::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037EF45
// Name: protected: void CMFCPopupMenu::SetScrollBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::SetScrollBar(CMFCPopupMenu *this)
{
  int m_iShadowSize; // eax
  int v3; // eax
  CMFCPopupMenu::LOGO_LOCATION m_nLogoLocation; // eax
  __int32 v5; // eax
  __int32 v6; // eax
  int SystemMetrics; // eax
  CMFCToolBar *v8; // edi
  int Count; // eax
  int v10; // eax
  UINT v11; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-54h]
  CMFCPopupMenuBar *nMenuRowHeight; // [esp+8h] [ebp-44h]
  int nMenuRowHeighta; // [esp+8h] [ebp-44h]
  tagSCROLLINFO ScrollInfo; // [esp+Ch] [ebp-40h] BYREF
  CRect rectScrollBar; // [esp+28h] [ebp-24h] BYREF
  CRect rectClient; // [esp+38h] [ebp-14h] BYREF

  if ( this->m_bShowScrollBar != 0 && this->m_bScrollable != 0 )
  {
    nMenuRowHeight = this->GetMenuBar(this);
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    if ( CMFCToolBar::m_bCustomizeMode == 0 )
    {
      m_iShadowSize = this->m_iShadowSize;
      rectClient.right -= m_iShadowSize;
      rectClient.bottom -= m_iShadowSize;
    }
    v3 = this->GetBorderSize(this);
    InflateRect(lprc: &rectClient, dx: -v3, dy: -v3);
    m_nLogoLocation = this->m_nLogoLocation;
    if ( m_nLogoLocation != MENU_LOGO_LEFT )
    {
      v5 = m_nLogoLocation - 1;
      if ( v5 != 0 )
      {
        v6 = v5 - 1;
        if ( v6 != 0 )
        {
          if ( v6 == 1 )
            rectClient.bottom -= this->m_iLogoWidth;
        }
        else
        {
          rectClient.top += this->m_iLogoWidth;
        }
      }
      else
      {
        rectClient.right -= this->m_iLogoWidth;
      }
    }
    else
    {
      rectClient.left += this->m_iLogoWidth;
    }
    rectClient.top += this->m_rectTearOffCaption.bottom - this->m_rectTearOffCaption.top;
    if ( this->m_bIsResizeBarOnTop != 0 )
      rectClient.top += this->m_rectResize.bottom - this->m_rectResize.top;
    else
      rectClient.bottom += this->m_rectResize.top - this->m_rectResize.bottom;
    SystemMetrics = GetSystemMetrics(nIndex: 2);
    rectScrollBar.top = rectClient.top;
    rectScrollBar.right = rectClient.right;
    rectScrollBar.bottom = rectClient.bottom;
    rectScrollBar.left = rectClient.right - SystemMetrics;
    rectClient.right -= SystemMetrics;
    memset(dst: (unsigned __int8 *)&ScrollInfo, value: 0, count: sizeof(ScrollInfo));
    ScrollInfo.cbSize = 28;
    ScrollInfo.fMask = 7;
    if ( this != (CMFCPopupMenu *)-3880 && this->m_wndScrollBarVert.m_hWnd != nullptr )
    {
      CWnd::SetWindowPos(
        this: &this->m_wndScrollBarVert,
        pWndInsertAfter: nullptr,
        x: rectScrollBar.left,
        y: rectScrollBar.top,
        cx: rectScrollBar.right - rectScrollBar.left,
        cy: rectScrollBar.bottom - rectScrollBar.top,
        nFlags: 0x14u);
      CWnd::GetScrollInfo(this: &this->m_wndScrollBarVert, nBar: 2, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
    }
    else
    {
      this->m_wndScrollBarVert.Create(
        this: &this->m_wndScrollBarVert,
        a2: 1342177281u,
        a3: &rectScrollBar,
        a4: this,
        a5: 1u);
    }
    memset(&ScrollInfo.nMin, 0, 12);
    v8 = nMenuRowHeight;
    nMenuRowHeighta = nMenuRowHeight->GetRowHeight(this: nMenuRowHeight);
    Count = CMFCToolBar::GetCount(this: v8);
    if ( Count <= 0 || nMenuRowHeighta <= 0 )
    {
      LODWORD(v8[1].m_ulGestureArg) = 0;
    }
    else
    {
      v10 = nMenuRowHeighta * Count - this->m_nMenuBarHeight;
      ScrollInfo.nPage = 1;
      ScrollInfo.nMax = v10 / nMenuRowHeighta + 1;
      LODWORD(v8[1].m_ulGestureArg) = this->m_nMenuBarHeight / nMenuRowHeighta;
    }
    CWnd::SetScrollInfo(this: &this->m_wndScrollBarVert, nBar: 2, lpScrollInfo: &ScrollInfo, bRedraw: 1);
    v11 = 0;
    if ( ScrollInfo.nMax <= 0 )
      v11 = 3;
    EnableScrollBar(hWnd: this->m_wndScrollBarVert.m_hWnd, wSBflags: 2u, wArrows: v11);
    CWnd::EnableWindow(this: &this->m_wndScrollBarVert, bEnable: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F162
// Name: protected: void CMFCPopupMenu::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnVScroll(
        CMFCPopupMenu *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  HWND__ *m_hWnd; // edx
  HWND__ *p_m_wndScrollBarVert; // eax
  CMFCPopupMenuBar *v7; // ebx
  int m_iOffset; // esi
  int nMax; // esi
  int v10; // ecx
  tagSCROLLINFO scrollInfo; // [esp+4h] [ebp-20h] BYREF

  if ( pScrollBar != nullptr )
    m_hWnd = pScrollBar->m_hWnd;
  else
    m_hWnd = nullptr;
  p_m_wndScrollBarVert = (HWND__ *)&this->m_wndScrollBarVert;
  if ( this != (CMFCPopupMenu *)-3880 )
    p_m_wndScrollBarVert = this->m_wndScrollBarVert.m_hWnd;
  if ( m_hWnd == p_m_wndScrollBarVert )
  {
    v7 = this->GetMenuBar(this);
    memset(dst: (unsigned __int8 *)&scrollInfo, value: 0, count: sizeof(scrollInfo));
    scrollInfo.fMask = 23;
    scrollInfo.cbSize = 28;
    CWnd::GetScrollInfo(this: &this->m_wndScrollBarVert, nBar: 2, lpScrollInfo: &scrollInfo, nMask: 0x17u);
    m_iOffset = v7->m_iOffset;
    switch ( nSBCode )
    {
      case 0u:
        nMax = m_iOffset - 1;
        goto LABEL_20;
      case 1u:
        nMax = m_iOffset + 1;
        goto LABEL_20;
      case 2u:
        nMax = m_iOffset - scrollInfo.nPage;
        goto LABEL_20;
      case 3u:
        nMax = scrollInfo.nPage + m_iOffset;
        goto LABEL_20;
      case 4u:
      case 5u:
        nMax = nPos;
        goto LABEL_20;
      case 6u:
        nMax = 0;
        v10 = 0;
        goto LABEL_13;
      case 7u:
        nMax = scrollInfo.nMax;
LABEL_20:
        if ( nMax >= 0 )
          v10 = nMax;
        else
          v10 = 0;
LABEL_13:
        if ( v10 >= scrollInfo.nMax )
        {
          nMax = scrollInfo.nMax;
        }
        else if ( nMax < 0 )
        {
          nMax = 0;
        }
        if ( nMax != v7->m_iOffset )
        {
          CMFCPopupMenuBar::SetOffset(this: v7, iOffset: nMax);
          if ( this != (CMFCPopupMenu *)-3880 && this->m_wndScrollBarVert.m_hWnd != nullptr )
            SetScrollPos(hWnd: this->m_wndScrollBarVert.m_hWnd, nBar: 2, nPos: nMax, bRedraw: true);
          CMFCPopupMenu::AdjustScroll(this, bForceMenuBarResize: 0);
        }
        break;
      default:
        return;
    }
  }
  else
  {
    CFrameWnd::OnVScroll(this, __formal: nSBCode, __formala: nPos, a4: pScrollBar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F296
// Name: protected: int CMFCPopupMenu::OnMouseWheel(unsigned int,short,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::OnMouseWheel(CMFCPopupMenu *this, unsigned int __formal, __int16 zDelta, CPoint a4)
{
  int v5; // eax
  int v6; // ebx
  unsigned int zDeltaa; // [esp+10h] [ebp+Ch]

  if ( CMFCPopupMenu::m_pActivePopupMenu == (HWND)this && this->m_bScrollable != 0 )
  {
    v5 = abs(lnumber: zDelta) / 120;
    if ( v5 > 0 )
    {
      v6 = v5;
      zDeltaa = zDelta < 0;
      do
      {
        CMFCPopupMenu::OnVScroll(this, nSBCode: zDeltaa, nPos: 0, pScrollBar: &this->m_wndScrollBarVert);
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037F2F4
// Name: protected: int CMFCPopupMenu::StartResize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::StartResize(CMFCPopupMenu *this)
{
  BOOL i; // eax
  HWND v3; // eax
  CMFCPopupMenu_vtbl *v4; // eax
  CMFCShadowWnd *m_pWndShadow; // ecx
  CMFCPopupMenu_vtbl *v6; // eax
  HWND Capture; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int cy; // edx
  int cx; // ecx
  int v14; // edi
  int v15; // eax
  CMFCPopupMenuBar *v16; // eax
  unsigned int ScrollPos; // eax
  CMFCShadowWnd *v18; // ecx
  CMFCPopupMenu_vtbl *v19; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-74h]
  tagMSG msgPaint; // [esp+Ch] [ebp-60h] BYREF
  tagMSG msg; // [esp+28h] [ebp-44h] BYREF
  int nBorderSize; // [esp+44h] [ebp-28h]
  int bIsMoseMove; // [esp+48h] [ebp-24h]
  HWND__ *hwndMenu; // [esp+4Ch] [ebp-20h]
  int bSuccess; // [esp+50h] [ebp-1Ch]
  int iShadowSize; // [esp+54h] [ebp-18h]
  CRect rectWindow; // [esp+58h] [ebp-14h] BYREF

  if ( this != nullptr )
    hwndMenu = this->m_hWnd;
  else
    hwndMenu = nullptr;
  for ( i = PeekMessageA(lpMsg: &msgPaint, hWnd: nullptr, wMsgFilterMin: 0xFu, wMsgFilterMax: 0xFu, wRemoveMsg: 0);
        i;
        i = PeekMessageA(lpMsg: &msgPaint, hWnd: nullptr, wMsgFilterMin: 0xFu, wMsgFilterMax: 0xFu, wRemoveMsg: 0) )
  {
    if ( !GetMessageA(lpMsg: &msgPaint, hWnd: nullptr, wMsgFilterMin: 0xFu, wMsgFilterMax: 0xFu) )
      return 0;
    DispatchMessageA(lpMsg: &msgPaint);
  }
  if ( GetCapture() != nullptr )
    return 0;
  v3 = SetCapture(hWnd: this->m_hWnd);
  CWnd::FromHandle(hWnd: v3);
  m_hWnd = this->m_hWnd;
  bSuccess = 0;
  memset(&rectWindow, 0, sizeof(rectWindow));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWindow);
  v4 = this->__vftable;
  this->m_bResizeTracking = 1;
  v4->GetMenuBar(this)->m_bResizeTracking = 1;
  m_pWndShadow = this->m_pWndShadow;
  iShadowSize = this->m_iShadowSize;
  this->m_iShadowSize = 0;
  if ( m_pWndShadow != nullptr && m_pWndShadow->m_hWnd != nullptr )
    CWnd::ShowWindow(this: m_pWndShadow, nCmdShow: 0);
  v6 = this->__vftable;
  bIsMoseMove = 0;
  nBorderSize = v6->GetBorderSize(this);
  while ( 1 )
  {
    Capture = GetCapture();
    if ( CWnd::FromHandle(hWnd: Capture) != this )
      break;
    if ( !GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
    {
      AfxPostQuitMessage(nExitCode: msg.wParam);
      break;
    }
    if ( msg.message == 512 )
    {
      bIsMoseMove = 1;
      if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
        v9 = rectWindow.right - msg.pt.x;
      else
        v9 = msg.pt.x - rectWindow.left;
      v10 = iShadowSize + v9 + 2 * nBorderSize;
      if ( this->m_bIsResizeBarOnTop != 0 )
        v11 = rectWindow.bottom - msg.pt.y;
      else
        v11 = msg.pt.y - rectWindow.top;
      if ( this->m_sizeMinResize.cy <= v11 )
      {
        if ( this->m_bIsResizeBarOnTop != 0 )
          cy = rectWindow.bottom - msg.pt.y;
        else
          cy = msg.pt.y - rectWindow.top;
      }
      else
      {
        cy = this->m_sizeMinResize.cy;
      }
      cx = this->m_sizeMinResize.cx;
      if ( cx <= 0 )
      {
        v10 = rectWindow.right - rectWindow.left - iShadowSize;
      }
      else if ( cx > v10 )
      {
        v10 = this->m_sizeMinResize.cx;
      }
      if ( v10 != this->m_sizeCurrent.cx || cy != this->m_sizeCurrent.cy )
      {
        this->m_sizeCurrent.cx = v10;
        this->m_sizeCurrent.cy = cy;
        if ( this->m_bIsResizeBarOnTop != 0 && cy > this->m_sizeMinResize.cy )
        {
          v14 = this->m_rectResize.bottom - this->m_rectResize.top;
          v15 = this->GetBorderSize(this);
          this->m_ptLocation.y = msg.pt.y - v14 - v15 - 1;
        }
        this->RecalcLayout(this, a2: 1);
        v16 = this->GetMenuBar(this);
        v16->AdjustLocations(this: v16);
        if ( this != (CMFCPopupMenu *)-3880 && this->m_wndScrollBarVert.m_hWnd != nullptr )
        {
          ScrollPos = GetScrollPos(hWnd: this->m_wndScrollBarVert.m_hWnd, nBar: 2);
          CMFCPopupMenu::OnVScroll(this, nSBCode: 5u, nPos: ScrollPos, pScrollBar: &this->m_wndScrollBarVert);
        }
        RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x581u);
        CMFCPopupMenu::UpdateBottomWindows(this, bCheckOnly: 0);
        this->m_bWasResized = 1;
      }
    }
    else
    {
      if ( msg.message == 514 )
      {
        bSuccess = 1;
        this->m_iShadowSize = iShadowSize;
        if ( bIsMoseMove != 0 )
        {
          if ( this != (CMFCPopupMenu *)-4036 && this->m_bmpShadowRight.m_hObject != nullptr )
            CGdiObject::DeleteObject(this: &this->m_bmpShadowRight);
          if ( this != (CMFCPopupMenu *)-4044 && this->m_bmpShadowBottom.m_hObject != nullptr )
            CGdiObject::DeleteObject(this: &this->m_bmpShadowBottom);
          this->RecalcLayout(this, a2: 1);
          CMFCPopupMenu::UpdateBottomWindows(this, bCheckOnly: 0);
          v18 = this->m_pWndShadow;
          if ( v18 != nullptr && v18->m_hWnd != nullptr )
            CMFCShadowWnd::Repos(this: v18);
          CWnd::ShowWindow(this, nCmdShow: 4);
        }
        break;
      }
      DispatchMessageA(lpMsg: &msg);
    }
  }
  ReleaseCapture();
  if ( IsWindow(hWnd: hwndMenu) )
  {
    v19 = this->__vftable;
    this->m_bResizeTracking = 0;
    v19->GetMenuBar(this)->m_bResizeTracking = 0;
  }
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x1037F622
// Name: protected: static class CMFCPopupMenu __near * CMFCPopupMenu::FindMenuWithConnectedFloaty(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__stdcall CMFCPopupMenu::FindMenuWithConnectedFloaty()
{
  CMFCPopupMenu *i; // esi

  if ( CMFCRibbonMiniToolBar::m_pCurrent == nullptr )
    return nullptr;
  for ( i = (CMFCPopupMenu *)CMFCPopupMenu::m_pActivePopupMenu; ; i = CMFCPopupMenu::GetParentPopupMenu(this: i) )
  {
    if ( i == nullptr )
      return nullptr;
    if ( CWnd::FromHandlePermanent(hWnd: i->m_hWnd) != nullptr && i->m_hwndConnectedFloaty != nullptr )
      break;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1037F662
// Name: public: void CMFCPopupMenu::TriggerResize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::TriggerResize(CMFCPopupMenu *this)
{
  CMFCPopupMenu_vtbl *v2; // eax
  CMFCPopupMenuBar *v3; // eax
  CMFCPopupMenu_vtbl *v4; // eax

  v2 = this->__vftable;
  this->m_bResizeTracking = 1;
  *(_DWORD *)(((int (*)(void))v2->GetMenuBar)() + 3348) = 1;
  v3 = this->GetMenuBar(this);
  v3->AdjustLocations(this: v3);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x581u);
  CMFCPopupMenu::UpdateBottomWindows(this, bCheckOnly: 0);
  v4 = this->__vftable;
  this->m_bResizeTracking = 0;
  v4->GetMenuBar(this)->m_bResizeTracking = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037F6C6
// Name: protected: void CMFCPopupMenu::OnWindowPosChanged(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnWindowPosChanged(CMFCPopupMenu *this, tagWINDOWPOS *lpwndpos)
{
  CMFCShadowWnd *m_pWndShadow; // ecx
  unsigned int flags; // eax

  CWnd::Default(this);
  m_pWndShadow = this->m_pWndShadow;
  if ( m_pWndShadow != nullptr && m_pWndShadow->m_hWnd != nullptr && this->m_bResizeTracking == 0 )
  {
    flags = lpwndpos->flags;
    if ( (flags & 0x80u) == 0 )
    {
      if ( (flags & 3) == 0 || (flags & 0x40) != 0 )
        CMFCShadowWnd::Repos(this: m_pWndShadow);
    }
    else
    {
      CWnd::ShowWindow(this: m_pWndShadow, nCmdShow: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F711
// Name: protected: void CMFCPopupMenu::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnSize(CMFCPopupMenu *this, unsigned int nType, int cx, int cy)
{
  CMFCPopupMenuBar *v5; // eax
  int v6; // ebx
  CMFCPopupMenu::LOGO_LOCATION m_nLogoLocation; // eax
  __int32 v8; // eax
  __int32 v9; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-28h]
  CRect rectLogo; // [esp+8h] [ebp-14h] BYREF

  CFrameWnd::OnSize(this, nType, cx, cy);
  v5 = this->GetMenuBar(this);
  if ( v5->m_bInUpdateShadow == 0 )
  {
    if ( v5->m_hWnd != nullptr )
    {
      CMFCPopupMenu::AdjustScroll(this, bForceMenuBarResize: 1);
      CMFCPopupMenu::SetScrollBar(this);
    }
    v6 = this->GetBorderSize(this);
    if ( this->m_iLogoWidth > 0 )
    {
      m_hWnd = this->m_hWnd;
      memset(&rectLogo, 0, sizeof(rectLogo));
      GetClientRect(hWnd: m_hWnd, lpRect: &rectLogo);
      m_nLogoLocation = this->m_nLogoLocation;
      if ( m_nLogoLocation != MENU_LOGO_LEFT )
      {
        v8 = m_nLogoLocation - 1;
        if ( v8 != 0 )
        {
          v9 = v8 - 1;
          if ( v9 != 0 )
          {
            if ( v9 == 1 )
              rectLogo.top = rectLogo.bottom - this->m_iLogoWidth - v6;
          }
          else
          {
            rectLogo.bottom = v6 + rectLogo.top + this->m_iLogoWidth;
          }
        }
        else
        {
          rectLogo.left = rectLogo.right - this->m_iLogoWidth - v6;
        }
      }
      else
      {
        rectLogo.right = v6 + rectLogo.left + this->m_iLogoWidth;
      }
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectLogo, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F810
// Name: protected: void CMFCPopupMenu::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnDestroy(CMFCPopupMenu *this)
{
  CWnd *Owner; // ecx
  CPaneFrameWnd *v3; // ebx
  CMFCCaptionButton *Button; // eax
  CMFCPopupMenuBar *v5; // ebx
  const CMFCToolBarButton *m_pDragButton; // eax
  int v7; // eax
  CMFCRibbonBaseElement *m_pParentRibbonElement; // eax
  CMFCPopupMenu *ParentPopupMenu; // ebx
  CObject *v10; // eax
  CMFCPopupMenu *v11; // eax
  CMFCToolBarsMenuPropertyPage *m_pMenuCustomizationPage; // ecx
  CFrameWnd *TopLevelFrame; // eax
  CObject *v14; // ebx
  CObject *v15; // eax
  CObject *v16; // eax
  CObject *v17; // eax
  HWND Focus; // eax
  CMFCToolBarMenuButton *v19; // ebx
  CMFCToolBarMenuButton *ParentToolBar; // eax
  CMFCShadowWnd *m_pWndShadow; // ecx
  HWND m_hWnd; // [esp-8h] [ebp-30h]
  tagPOINT Point; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rectParent; // [esp+14h] [ebp-14h] BYREF

  if ( this->m_bQuickCusomize != 0 )
  {
    CMFCMenuBar::SetRecentlyUsedMenus(bOn: CMFCCustomizeMenuButton::m_bRecentlyUsedOld);
    Owner = CWnd::GetOwner(this);
    Point.y = (int)Owner;
    if ( Owner != nullptr && CObject::IsKindOf(this: Owner, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
    {
      v3 = (CPaneFrameWnd *)AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: (CObject *)Point.y);
      Button = CPaneFrameWnd::FindButton(this: v3, uiHit: 0x19u);
      if ( Button != nullptr )
      {
        Button->m_bPushed = 0;
        CPaneFrameWnd::OnNcPaint(this: v3);
      }
    }
  }
  v5 = this->GetMenuBar(this);
  m_pDragButton = v5->m_pDragButton;
  if ( m_pDragButton != nullptr && v5->m_bIsDragCopy == 0 )
  {
    Point.y = (int)v5->__vftable;
    v7 = CMFCToolBar::ButtonToIndex(this: v5, pButton: m_pDragButton);
    (*(void (__thiscall **)(CMFCPopupMenuBar *, int))(Point.y + 844))(a1: v5, a2: v7);
    v5->m_pDragButton = nullptr;
  }
  m_pParentRibbonElement = this->m_pParentRibbonElement;
  if ( m_pParentRibbonElement != nullptr )
  {
    m_pParentRibbonElement->m_pPopupMenu = nullptr;
    ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
    if ( ParentPopupMenu != nullptr )
    {
      if ( ParentPopupMenu->IsRibbonMiniToolBar(this: ParentPopupMenu) != 0 )
      {
        v10 = AfxDynamicDownCast(pClass: &CMFCRibbonMiniToolBar::classCMFCRibbonMiniToolBar, pObject: ParentPopupMenu);
        if ( v10 != nullptr && v10[1984].__vftable == nullptr )
          this->m_bAutoDestroyParent = 0;
      }
      if ( this->m_bAutoDestroyParent != 0 && CMFCToolBar::m_bCustomizeMode == 0 )
      {
        Point.x = 0;
        Point.y = 0;
        GetCursorPos(lpPoint: &Point);
        m_hWnd = ParentPopupMenu->m_hWnd;
        memset(&rectParent, 0, sizeof(rectParent));
        GetWindowRect(hWnd: m_hWnd, lpRect: &rectParent);
        if ( ParentPopupMenu->IsAlwaysClose(this: ParentPopupMenu) != 0 || !PtInRect(lprc: &rectParent, pt: Point) )
        {
          SendMessageA(hWnd: ParentPopupMenu->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
          this->m_pParentRibbonElement = nullptr;
        }
      }
    }
  }
  if ( this->m_pParentBtn != nullptr )
  {
    this->SaveState(this);
    this->m_pParentBtn->m_pPopupMenu = nullptr;
    this->m_pParentBtn->m_bClickedOnMenu = 0;
    v11 = CMFCPopupMenu::GetParentPopupMenu(this);
    if ( v11 != nullptr && this->m_bAutoDestroyParent != 0 && CMFCToolBar::m_bCustomizeMode == 0 )
    {
      SendMessageA(hWnd: v11->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
      this->m_pParentBtn = nullptr;
    }
  }
  else
  {
    CMFCMenuBar::SetShowAllCommands(bShowAllCommands: 0);
  }
  m_pMenuCustomizationPage = this->m_pMenuCustomizationPage;
  if ( m_pMenuCustomizationPage != nullptr )
    CMFCToolBarsMenuPropertyPage::CloseContextMenu(this: m_pMenuCustomizationPage, pMenu: this);
  CMFCPopupMenu::NotifyParentDlg(this, bActivate: 0);
  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v14 = TopLevelFrame;
  v15 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( v15 != nullptr )
  {
    ((void (__thiscall *)(CObject *, CMFCPopupMenu *))v15->__vftable[40].dtr_CObject)(a1: v15, a2: this);
  }
  else
  {
    v16 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: v14);
    if ( v16 != nullptr )
    {
      v16->__vftable[38].Serialize(this: v16, a2: (CArchive *)this);
    }
    else
    {
      v17 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: v14);
      if ( v17 != nullptr
        || (v17 = AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject: v14)) != nullptr )
      {
        ((void (__thiscall *)(CObject *, CMFCPopupMenu *))v17->__vftable[41].GetRuntimeClass)(a1: v17, a2: this);
      }
    }
  }
  if ( this->m_bTrackMode != 0 && CMFCPopupMenu::m_pActivePopupMenu == (HWND)this )
    CMFCPopupMenu::m_pActivePopupMenu = nullptr;
  if ( CMFCToolBar::m_bCustomizeMode == 0
    && v14 != nullptr
    && CMFCPopupMenu::m_pActivePopupMenu == nullptr
    && CMFCPopupMenu::GetParentToolBar(this) != nullptr )
  {
    Focus = GetFocus();
    v19 = (CMFCToolBarMenuButton *)CWnd::FromHandle(hWnd: Focus);
    if ( CMFCPopupMenu::GetParentToolBar(this) != v19 )
    {
      ParentToolBar = CMFCPopupMenu::GetParentToolBar(this);
      ((void (__thiscall *)(CMFCToolBarMenuButton *))ParentToolBar->__vftable[3].OnBeforeDrop)(a1: ParentToolBar);
    }
  }
  m_pWndShadow = this->m_pWndShadow;
  if ( m_pWndShadow != nullptr && m_pWndShadow->m_hWnd != nullptr )
    m_pWndShadow->DestroyWindow(this: m_pWndShadow);
  CFrameWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037FAF5
// Name: protected: void CMFCPopupMenu::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnTimer(CMFCPopupMenu *this, int nIDEvent)
{
  CMFCPopupMenuBar *v3; // ebx
  CMFCToolBarMenuButton *SelItem; // eax
  int v5; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  int m_iShadowSize; // eax
  HWND__ *v10; // [esp-Ch] [ebp-20h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-1Ch]
  tagPOINT Point; // [esp+Ch] [ebp-8h] BYREF
  int iOffset; // [esp+1Ch] [ebp+8h]
  int iOffseta; // [esp+1Ch] [ebp+8h]

  v3 = this->GetMenuBar(this);
  if ( nIDEvent == 1 )
  {
    if ( this->m_bAnimationIsDone != 0 )
      goto LABEL_32;
    Point.y = clock();
    iOffseta = (int)((double)(Point.y - nLastAnimTime) / (double)CMFCPopupMenu::m_AnimationSpeed + 0.5);
    v6 = CMFCPopupMenu::GetAnimationType(bNoSystem: 0) - 1;
    if ( v6 != 0 )
    {
      v7 = v6 - 1;
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
        {
          this->m_iFadePercent += 10;
          if ( this->m_iFadePercent > 10 * (iOffseta + 10) )
            this->m_iFadePercent = 101;
        }
        goto LABEL_21;
      }
    }
    else
    {
      this->m_AnimSize.cx += iOffseta * v3->GetColumnWidth(this: v3);
    }
    this->m_AnimSize.cy += iOffseta * v3->GetRowHeight(this: v3);
LABEL_21:
    AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
    if ( AnimationType != FADE && this->m_AnimSize.cy - this->m_iShadowSize >= this->m_FinalSize.cy
      || AnimationType == UNFOLD && this->m_AnimSize.cx - this->m_iShadowSize >= this->m_FinalSize.cx
      || AnimationType == FADE && this->m_iFadePercent > 100 )
    {
      m_iShadowSize = this->m_iShadowSize;
      this->m_AnimSize.cx = m_iShadowSize + this->m_FinalSize.cx;
      m_hWnd = this->m_hWnd;
      this->m_AnimSize.cy = m_iShadowSize + this->m_FinalSize.cy;
      KillTimer(hWnd: m_hWnd, uIDEvent: 1u);
      v3->SetWindowPos(this: v3, a2: nullptr, a3: 0, a4: 0, a5: 0, a6: 0, a7: 95u, a8: nullptr);
      ValidateRect(hWnd: v3->m_hWnd, lpRect: nullptr);
      this->m_bAnimationIsDone = 1;
      if ( this->m_iShadowSize != 0
        && CMFCPopupMenu::GetAnimationType(bNoSystem: 0) != FADE
        && this->m_DropDirection == DROP_DIRECTION_TOP )
      {
        CMFCPopupMenu::UpdateShadow(this, lprectScreen: nullptr);
      }
    }
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
    nLastAnimTime = Point.y;
    goto LABEL_32;
  }
  if ( nIDEvent == 2 )
  {
    Point.x = 0;
    Point.y = 0;
    GetCursorPos(lpPoint: &Point);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &Point);
    SelItem = CMFCPopupMenu::GetSelItem(this);
    if ( SelItem != nullptr )
      SelItem->OnCancelMode(this: SelItem);
    iOffset = v3->m_iOffset;
    if ( PtInRect(lprc: &this->m_rectScrollUp, pt: Point) && this->m_iScrollMode < 0 )
    {
      v5 = iOffset - 1;
    }
    else
    {
      if ( !PtInRect(lprc: &this->m_rectScrollDn, pt: Point) || this->m_iScrollMode <= 0 )
      {
        KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
        v10 = this->m_hWnd;
        this->m_iScrollMode = 0;
        InvalidateRect(hWnd: v10, lpRect: &this->m_rectScrollDn, bErase: true);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollUp, bErase: true);
        goto LABEL_32;
      }
      v5 = iOffset + 1;
    }
    CMFCPopupMenuBar::SetOffset(this: v3, iOffset: v5);
    CMFCPopupMenu::AdjustScroll(this, bForceMenuBarResize: 0);
  }
LABEL_32:
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037FD74
// Name: public: void CMFCPopupMenu::ShowAllCommands(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::ShowAllCommands(CMFCPopupMenu *this)
{
  CObject *v2; // ebx
  CMFCPopupMenuBar *v3; // eax
  CObject_vtbl *v4; // eax

  v2 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: this->m_pParentBtn);
  if ( v2 != nullptr )
  {
    v3 = this->GetMenuBar(this);
    CMFCToolBar::SetHot(this: v3, pMenuButton: nullptr);
    CMFCMenuBar::SetShowAllCommands(bShowAllCommands: 1);
    AFXPlaySystemSound(nSound: 2);
    CWnd::ShowWindow(this, nCmdShow: 0);
    this->m_bShown = 0;
    if ( this != (CMFCPopupMenu *)-4036 && this->m_bmpShadowRight.m_hObject != nullptr )
      CGdiObject::DeleteObject(this: &this->m_bmpShadowRight);
    if ( this != (CMFCPopupMenu *)-4044 && this->m_bmpShadowBottom.m_hObject != nullptr )
      CGdiObject::DeleteObject(this: &this->m_bmpShadowBottom);
    this->m_ptLocation.x = this->m_ptLocationInitial.x;
    this->m_ptLocation.y = this->m_ptLocationInitial.y;
    this->InitMenuBar(this);
    if ( this->m_bScrollable != 0 )
    {
      CMFCPopupMenu::AdjustScroll(this, bForceMenuBarResize: 0);
      CMFCPopupMenu::SetScrollBar(this);
    }
    CMFCPopupMenu::UpdateBottomWindows(this, bCheckOnly: 0);
    CWnd::ShowWindow(this, nCmdShow: 4);
    v4 = v2[27].__vftable;
    if ( v4 != nullptr && IsWindow(hWnd: (HWND)v4[2].Serialize) )
    {
      InvalidateRect(hWnd: (HWND)v2[27].__vftable[2].Serialize, lpRect: (const RECT *)&v2[21], bErase: true);
      UpdateWindow(hWnd: (HWND)v2[27].__vftable[2].Serialize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037FE70
// Name: protected: void CMFCPopupMenu::OnNcLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnNcLButtonDown(CMFCPopupMenu *this, unsigned int nHitTest, CPoint point)
{
  if ( this->m_bIsResizeBarOnTop != 0 )
  {
    if ( nHitTest == 13 || nHitTest == 14 || nHitTest == 12 )
    {
LABEL_5:
      CMFCPopupMenu::StartResize(this);
      return;
    }
  }
  else if ( nHitTest == 16 || nHitTest == 17 || nHitTest == 15 )
  {
    goto LABEL_5;
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037FEB2
// Name: protected: void CMFCPopupMenu::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnKeyDown(
        CMFCPopupMenu *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMFCPopupMenuBar *v5; // esi
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  CMFCToolBarButton *Button; // ebx
  int v9; // eax
  int v10; // ebx
  CMFCToolBarMenuButton *v11; // eax
  CMFCToolBarMenuButton *m_pParentBtn; // ecx
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  CMFCToolBarMenuButton *SelItem; // eax
  CMFCToolBarMenuButton *v15; // esi
  unsigned int m_nID; // eax
  CMFCToolBarMenuButton *ParentToolBar; // eax
  CMFCToolBarMenuButton *v18; // esi
  CMFCPopupMenu *ParentPopupMenu; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int iOffset; // [esp+Ch] [ebp-18h]
  int iOffseta; // [esp+Ch] [ebp-18h]
  CMFCPopupMenu::ANIMATION_TYPE iOffsetb; // [esp+Ch] [ebp-18h]
  int iOffsetc; // [esp+Ch] [ebp-18h]
  CRect rectBar; // [esp+10h] [ebp-14h] BYREF

  iOffset = 0;
  v5 = this->GetMenuBar(this);
  v6 = CWnd::GetExStyle(this) & 0x400000;
  if ( v6 != 0 )
  {
    if ( nChar == 37 )
    {
      nChar = 39;
      goto LABEL_4;
    }
    if ( nChar == 39 )
      nChar = 37;
  }
  v7 = nChar;
  if ( nChar > 0x25 )
  {
LABEL_4:
    v7 = nChar;
    if ( nChar != 38 )
    {
      if ( nChar == 39 )
      {
        AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
        CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
        iOffsetb = AnimationType;
        SelItem = CMFCPopupMenu::GetSelItem(this);
        v15 = SelItem;
        if ( SelItem != nullptr
          && ((m_nID = SelItem->m_nID) == -1 || m_nID == 0 || v15->IsEmptyMenuAllowed(this: v15) != 0)
          && v15->OpenPopupMenu(this: v15, a2: nullptr) != 0 )
        {
          if ( v15->m_pPopupMenu != nullptr && CMFCPopupMenu::GetSelItem(this) == v15 )
            CMFCPopupMenu::OnKeyDown(this: v15->m_pPopupMenu, nChar: 0x24u, nRepCnt: 0, nFlags: 0);
        }
        else
        {
          ParentToolBar = CMFCPopupMenu::GetParentToolBar(this);
          v18 = ParentToolBar;
          if ( ParentToolBar == nullptr
            || CObject::IsKindOf(this: ParentToolBar, pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar) != 0 )
          {
            ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
            if ( ParentPopupMenu != nullptr )
              SendMessageA(hWnd: ParentPopupMenu->m_hWnd, Msg: 0x100u, wParam: 2 * (v6 == 0) + 37, lParam: 0);
          }
          else
          {
            v18->__vftable[3].IsLastInGroup(this: v18);
          }
        }
        CMFCPopupMenu::m_AnimationType = iOffsetb;
        return;
      }
      if ( nChar != 40 )
        goto LABEL_7;
      if ( GetAsyncKeyState(vKey: 17) < 0 && v5->m_bAreAllCommandsShown == 0 )
      {
        CMFCPopupMenu::ShowAllCommands(this);
        return;
      }
    }
    goto LABEL_17;
  }
  if ( nChar == 37 )
  {
    v11 = CMFCPopupMenu::GetParentToolBar(this);
    if ( v11 != nullptr )
    {
      v11->__vftable[3].IsFirstInGroup(this: v11);
    }
    else
    {
      m_pParentBtn = this->m_pParentBtn;
      if ( m_pParentBtn != nullptr && m_pParentBtn->IsDroppedDown(this: m_pParentBtn) != 0 )
        CMFCPopupMenu::CloseMenu(this, bSetFocusToBar: 0);
    }
    return;
  }
  if ( nChar != 13 )
  {
    if ( nChar == 27 )
    {
      this->m_bEscClose = 1;
      CMFCPopupMenu::CloseMenu(this, bSetFocusToBar: 1);
      return;
    }
    if ( nChar <= 0x20 )
      goto LABEL_7;
    if ( nChar <= 0x22 )
    {
      if ( this->m_bShowScrollBar == 0 )
      {
LABEL_7:
        if ( v5->OnKey(this: v5, a2: v7) == 0 )
          CWnd::Default(this);
        return;
      }
      v5->OnKey(this: v5, a2: nChar);
LABEL_21:
      if ( this->m_bScrollable != 0 && v5->m_iHighlighted >= 0 )
      {
        Button = CMFCToolBar::GetButton(this: v5, nIndex: v5->m_iHighlighted);
        if ( Button != nullptr || v5->GetRowHeight(this: v5) != 0 )
        {
          memset(&rectBar, 0, sizeof(rectBar));
          GetClientRect(hWnd: v5->m_hWnd, lpRect: &rectBar);
          iOffseta = v5->m_iOffset;
          if ( Button->m_rect.top >= rectBar.top )
          {
            if ( Button->m_rect.bottom <= rectBar.bottom )
              goto LABEL_69;
            v20 = v5->GetRowHeight(this: v5);
            v10 = (Button->m_rect.bottom - rectBar.bottom) / v20 + 1;
          }
          else
          {
            v9 = v5->GetRowHeight(this: v5);
            v10 = (Button->m_rect.top - rectBar.top) / v9 - 1;
          }
          if ( v10 != 0 )
          {
            v21 = this->m_FinalSize.cy / v5->GetRowHeight(this: v5) - 2;
            iOffsetc = v10 + iOffseta;
            if ( iOffsetc >= 0 )
              v22 = iOffsetc;
            else
              v22 = 0;
            v23 = v5->m_Buttons.m_nCount - v21;
            if ( v22 >= v23 - 1 )
            {
              iOffsetc = v23 - 1;
            }
            else if ( iOffsetc < 0 )
            {
              iOffsetc = 0;
              CMFCPopupMenuBar::SetOffset(this: v5, iOffset: 0);
LABEL_63:
              v24 = CMFCPopupMenu::AdjustScroll(this, bForceMenuBarResize: 0);
              if ( this->m_bShowScrollBar != 0
                && this != (CMFCPopupMenu *)-3880
                && this->m_wndScrollBarVert.m_hWnd != nullptr )
              {
                SetScrollPos(hWnd: this->m_wndScrollBarVert.m_hWnd, nBar: 2, nPos: iOffsetc, bRedraw: true);
              }
              else if ( v24 != 0 )
              {
                CMFCPopupMenu::AdjustScroll(this, bForceMenuBarResize: 0);
              }
              goto LABEL_69;
            }
            CMFCPopupMenuBar::SetOffset(this: v5, iOffset: iOffsetc);
            goto LABEL_63;
          }
        }
      }
LABEL_69:
      if ( v5->m_bDropDownListMode != 0 )
        this->OnChangeHot(this, a2: v5->m_iHighlighted);
      return;
    }
LABEL_17:
    v7 = nChar;
    iOffset = 1;
  }
  if ( CMFCToolBar::m_bCustomizeMode == 0 )
    v5->OnKey(this: v5, a2: v7);
  if ( iOffset != 0 )
    goto LABEL_21;
}

//------------------------------------------------------------------------------
// Address: 0x10380261
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCPopupMenu::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCPopupMenu::GetMessageMap(CMFCPopupMenu *this)
{
  return &messageMap_30;
}

//------------------------------------------------------------------------------
// Address: 0x10380267
// Name: protected: virtual int CMFCPopupMenu::InitMenuBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::InitMenuBar(CMFCPopupMenu *this)
{
  CMFCPopupMenu *v1; // edi
  CMFCPopupMenu_vtbl *v2; // eax
  CMFCToolBar *v3; // esi
  int v4; // eax
  __POSITION *m_pNodeHead; // eax
  __POSITION *v7; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v8; // ebx
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  CAfxStringMgr *StringManager; // eax
  CRecentFileList_vtbl *v14; // eax
  CAfxStringMgr *v15; // eax
  CMFCToolBarMenuButton *v16; // eax
  CMFCToolBar_vtbl *v17; // edx
  _BYTE *v18; // edi
  CUserToolsManager *v19; // edx
  __POSITION *v20; // eax
  int v21; // ebx
  CObList *p_m_lstUserTools; // edi
  CObList::CNode *v23; // ebx
  CObject *data; // edi
  _STATIC_CREATOR_ *CmdMgr; // eax
  int CmdImage; // eax
  CMFCToolBarMenuButton *v27; // eax
  CMFCToolBar_vtbl *v28; // edx
  int v29; // eax
  CFrameWnd *v30; // ebx
  CFrameWnd *TopLevelFrame; // eax
  CDocument *v32; // [esp-8h] [ebp-234h]
  CRecentFileList *m_pRecentFileList; // [esp+10h] [ebp-21Ch]
  ATL::CSimpleStringT<char,0> v34; // [esp+14h] [ebp-218h] BYREF
  __POSITION *position; // [esp+18h] [ebp-214h] BYREF
  CMFCPopupMenu *v36; // [esp+1Ch] [ebp-210h]
  int v37; // [esp+20h] [ebp-20Ch]
  __POSITION *v38; // [esp+24h] [ebp-208h]
  int v39; // [esp+28h] [ebp-204h]
  int v40; // [esp+2Ch] [ebp-200h]
  CMFCToolBarMenuButton v41; // [esp+30h] [ebp-1FCh] BYREF
  CHAR Buffer[272]; // [esp+118h] [ebp-114h] BYREF
  int v43; // [esp+228h] [ebp-4h]

  v1 = this;
  v2 = this->__vftable;
  v36 = this;
  v3 = (CMFCToolBar *)((int (__fastcall *)(CMFCPopupMenu *))v2->GetMenuBar)(a1: this);
  if ( v1->m_hMenu != nullptr )
  {
    if ( !IsMenu(hMenu: v1->m_hMenu) )
      goto LABEL_3;
    if ( v1->m_pParentBtn != nullptr || CMenuHash::LoadMenuBar(this: &afxMenuHash, hMenu: v1->m_hMenu, pBar: v3) == 0 )
    {
      v4 = CMFCMenuBar::IsShowAllCommands() != 0
         ? ((int (__thiscall *)(CMFCToolBar *, HMENU__ *, int))v3->__vftable[1].dtr_CObject)(
             a1: v3,
             a2: v1->m_hMenu,
             a3: 1)
         : ((int (__thiscall *)(CMFCToolBar *, HMENU__ *, bool))v3->__vftable[1].dtr_CObject)(
             a1: v3,
             a2: v1->m_hMenu,
             a3: v1->m_pParentBtn == nullptr);
      if ( v4 == 0 )
        return 0;
    }
  }
  m_pRecentFileList = AfxGetModuleState()->m_pCurrentWinApp->m_pRecentFileList;
  if ( m_pRecentFileList != nullptr && CMFCToolBar::m_bCustomizeMode == 0 )
  {
    m_pNodeHead = (__POSITION *)v3->m_Buttons.m_pNodeHead;
    v39 = 0;
    v37 = 0;
    if ( m_pNodeHead != nullptr )
    {
      while ( 1 )
      {
        position = m_pNodeHead;
        if ( m_pNodeHead == nullptr )
          goto LABEL_3;
        v7 = *(__POSITION **)m_pNodeHead;
        v8 = *(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **)&m_pNodeHead[8];
        v38 = *(__POSITION **)m_pNodeHead;
        if ( v8 == nullptr )
          goto LABEL_3;
        if ( v8[8].m_pszData == (char *)57616
          && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v8 + 11, psz: "Recent File") == 0 )
        {
          break;
        }
        v9 = (int)v8[9].m_pszData & 1;
        ++v39;
        v37 = v9;
        if ( v7 == nullptr )
          goto LABEL_32;
        m_pNodeHead = v38;
      }
      CPtrList::RemoveAt(this: &v3->m_Buttons, position);
      (*((void (__thiscall **)(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *, int))v8->m_pszData + 1))(
        a1: v8,
        a2: 1);
      GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: Buffer);
      v10 = lstrlenA(lpString: Buffer);
      Buffer[v10] = 92;
      v11 = 0;
      v12 = v10 + 1;
      Buffer[v10 + 1] = 0;
      v40 = 0;
      if ( m_pRecentFileList->m_nSize <= 0 )
        goto LABEL_28;
      do
      {
        StringManager = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
          this: (ATL::CSimpleStringT<char,0> *)&position,
          pStringMgr: StringManager);
        v14 = m_pRecentFileList->__vftable;
        v43 = 0;
        if ( v14->GetDisplayName(
               this: m_pRecentFileList,
               a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&position,
               a3: v11,
               a4: Buffer,
               a5: v12,
               a6: 1) != 0 )
        {
          v15 = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v34, pStringMgr: v15);
          ++v40;
          LOBYTE(v43) = 1;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v34,
            pszFormat: "&%d %s",
            v40,
            (const char *)position);
          v16 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                  this: &v41,
                  uiID: v11 + 57616,
                  hMenu: nullptr,
                  iImage: -1,
                  lpszText: v34.m_pszData,
                  bUserButton: 0);
          v17 = v3->__vftable;
          LOBYTE(v43) = 2;
          v17->InsertButton(this: v3, a2: v16, a3: v39++);
          LOBYTE(v43) = 1;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v41);
          ATL::CStringData::Release(this: (ATL::CStringData *)v34.m_pszData - 1);
        }
        v43 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)&position[-16]);
        ++v11;
      }
      while ( v11 < m_pRecentFileList->m_nSize );
      if ( v40 == 0 )
      {
LABEL_28:
        if ( v37 != 0 && v38 != nullptr )
        {
          v18 = *(_BYTE **)&v38[8];
          if ( v18 == nullptr )
            goto LABEL_3;
          if ( (v18[36] & 1) != 0 )
          {
            CPtrList::RemoveAt(this: &v3->m_Buttons, position: v38);
            (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v18 + 4))(a1: v18, a2: 1);
          }
        }
      }
LABEL_32:
      v1 = v36;
    }
  }
  v19 = afxUserToolsManager;
  if ( afxUserToolsManager != nullptr && CMFCToolBar::m_bCustomizeMode == 0 )
  {
    v20 = (__POSITION *)v3->m_Buttons.m_pNodeHead;
    v37 = 0;
    v40 = 0;
    v39 = 0;
    if ( v20 != nullptr )
    {
      while ( 1 )
      {
        v38 = *(__POSITION **)v20;
        v21 = *(_DWORD *)&v20[8];
        if ( v21 == 0 )
          break;
        if ( v19->m_uiCmdToolsDummy == *(_DWORD *)(v21 + 32) )
        {
          p_m_lstUserTools = &v19->m_lstUserTools;
          if ( CMFCPopupMenu::m_bAlwaysShowEmptyToolsEntry == 0 || v19->m_lstUserTools.m_nCount != 0 )
          {
            CPtrList::RemoveAt(this: &v3->m_Buttons, position: v20);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 4))(a1: v21, a2: 1);
          }
          if ( v37 == 0 )
          {
            if ( v39 == 0 && p_m_lstUserTools->m_nCount != 0 && v3->m_Buttons.m_nCount != 0 )
              v3->InsertSeparator(this: v3, a2: v40++);
            v23 = p_m_lstUserTools->m_pNodeHead;
            while ( v23 != nullptr )
            {
              data = v23->data;
              v23 = v23->pNext;
              v32 = (CDocument *)data[4].__vftable;
              CmdMgr = GetCmdMgr();
              CmdImage = CCommandManager::GetCmdImage(this: &CmdMgr->s_TheCmdMgr, uiCmd: v32, bUserImage: 1);
              v27 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                      this: &v41,
                      uiID: (unsigned int)data[4].__vftable,
                      hMenu: nullptr,
                      iImage: CmdImage != -1 ? CmdImage : 0,
                      lpszText: (const char *)data[1].__vftable,
                      bUserButton: CmdImage != -1);
              v28 = v3->__vftable;
              v43 = 3;
              v28->InsertButton(this: v3, a2: v27, a3: v40++);
              v43 = -1;
              CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v41);
            }
            if ( v38 != nullptr )
            {
              v29 = v3->InsertSeparator(this: v3, a2: v40++);
              v39 = v29 >= 0;
            }
            v37 = 1;
          }
          v1 = v36;
        }
        else if ( (*(_BYTE *)(v21 + 36) & 1) != 0 )
        {
          if ( v39 != 0 )
          {
            CPtrList::RemoveAt(this: &v3->m_Buttons, position: v20);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 4))(a1: v21, a2: 1);
          }
          v39 = 1;
        }
        else
        {
          v39 = 0;
        }
        ++v40;
        if ( v38 == nullptr )
          goto LABEL_56;
        v20 = v38;
        v19 = afxUserToolsManager;
      }
LABEL_3:
      AfxThrowInvalidArgException();
    }
  }
LABEL_56:
  v30 = (CFrameWnd *)v3->GetCommandTarget(this: v3);
  if ( v30 == nullptr || v30->IsFrameWnd(this: v30) == 0 )
    v30 = AFXGetParentFrame(pWnd: v1);
  if ( v30 != nullptr )
    v3->OnUpdateCmdUI(this: v3, a2: v30, a3: 0);
  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this: v1);
  if ( CMFCPopupMenu::ActivatePopupMenu(pTopFrame: TopLevelFrame, pPopupMenu: v1) == 0 )
    return 0;
  v1->RecalcLayout(this: v1, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103807B3
// Name: protected: virtual int CMFCPopupMenu::TearOff(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCPopupMenu::TearOff(CMFCPopupMenu *this, tagPOINT point)
{
  CMFCPopupMenu *v2; // edi
  CMFCToolBarMenuButton *m_pParentBtn; // eax
  unsigned int m_uiTearOffBarID; // ebx
  CFrameWnd *TopLevelFrame; // eax
  CMDIFrameWndEx *v6; // eax
  CMDIFrameWndEx *v7; // esi
  CBasePane *Pane; // eax
  CFrameImpl *p_m_Impl; // esi
  CFrameWndEx *v10; // eax
  CFrameWndEx *v11; // esi
  COleIPFrameWndEx *v12; // eax
  COleIPFrameWndEx *v13; // esi
  COleDocIPFrameWndEx *v14; // eax
  COleDocIPFrameWndEx *v15; // esi
  CPane *v16; // ebx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  CPane_vtbl *v21; // eax
  bool v22; // zf
  CPane_vtbl *v23; // eax
  CBasePane *v24; // eax
  int v26; // eax
  CObject *v27; // eax
  CObject *v28; // eax
  CSize *v29; // eax
  int cx; // ecx
  int cy; // eax
  CPane_vtbl *v32; // eax
  CPaneFrameWnd *v33; // eax
  HWND m_hWnd; // [esp-8h] [ebp-58h]
  char v35; // [esp+10h] [ebp-40h] BYREF
  CMDIFrameWndEx *v36; // [esp+14h] [ebp-3Ch]
  unsigned int v37; // [esp+18h] [ebp-38h]
  CMFCPopupMenu *pMenu; // [esp+1Ch] [ebp-34h]
  tagPOINT Point; // [esp+20h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v40; // [esp+28h] [ebp-28h] BYREF
  CObject *pObject; // [esp+2Ch] [ebp-24h]
  tagRECT Rect; // [esp+30h] [ebp-20h] BYREF
  int v43; // [esp+4Ch] [ebp-4h]

  v2 = this;
  m_pParentBtn = this->m_pParentBtn;
  pMenu = this;
  if ( m_pParentBtn == nullptr )
    return nullptr;
  m_uiTearOffBarID = m_pParentBtn->m_uiTearOffBarID;
  v37 = m_uiTearOffBarID;
  if ( m_uiTearOffBarID == 0 )
    return nullptr;
  Point = point;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &Point);
  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this: v2);
  pObject = TopLevelFrame;
  if ( TopLevelFrame == nullptr )
    return nullptr;
  v6 = (CMDIFrameWndEx *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  v7 = v6;
  v36 = v6;
  if ( v6 != nullptr )
  {
    Pane = CMDIFrameWndEx::GetPane(this: v6, nID: m_uiTearOffBarID);
    p_m_Impl = &v7->m_Impl;
  }
  else
  {
    v10 = (CFrameWndEx *)AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject);
    v11 = v10;
    if ( v10 != nullptr )
    {
      Pane = CFrameWndEx::GetPane(this: v10, nID: m_uiTearOffBarID);
      p_m_Impl = &v11->m_Impl;
    }
    else
    {
      v12 = (COleIPFrameWndEx *)AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject);
      v13 = v12;
      if ( v12 != nullptr )
      {
        Pane = COleIPFrameWndEx::GetPane(this: v12, nID: m_uiTearOffBarID);
        p_m_Impl = &v13->m_Impl;
      }
      else
      {
        v14 = (COleDocIPFrameWndEx *)AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject);
        v15 = v14;
        if ( v14 == nullptr )
          return nullptr;
        Pane = COleDocIPFrameWndEx::GetPane(this: v14, nID: m_uiTearOffBarID);
        p_m_Impl = &v15->m_Impl;
      }
    }
  }
  v16 = (CPane *)Pane;
  if ( p_m_Impl == nullptr )
    return nullptr;
  if ( Pane == nullptr )
  {
    v40.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v2->m_pParentBtn->m_strText.m_pszData - 1)[1];
    v43 = 0;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(this: &v40, chRemove: 38);
    v24 = v2->CreateTearOffBar(this: v2, a2: pObject, a3: v37, a4: v40.m_pszData);
    v16 = (CPane *)v24;
    if ( v24 != nullptr )
    {
      CFrameImpl::AddTearOffToolbar(this: p_m_Impl, pToolBar: v24);
      v43 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v40.m_pszData - 1);
      goto LABEL_23;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)v40.m_pszData - 1);
    return nullptr;
  }
  Pane->ShowPane(this: Pane, a2: 1, a3: 0, a4: 1);
  m_hWnd = v16->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
  v17 = Rect.right - Rect.left;
  Rect.left = Point.x;
  v18 = v17 + Point.x;
  v19 = Rect.bottom - Rect.top;
  Rect.right = v18;
  Rect.top = Point.y;
  v20 = v19 + Point.y;
  v21 = v16->__vftable;
  Rect.bottom = v20;
  v22 = v21->IsDocked(this: v16) == 0;
  v23 = v16->__vftable;
  if ( v22 )
  {
    v23->MoveWindow(this: v16, a2: (CRect *)&Rect, a3: 1, a4: nullptr);
  }
  else
  {
    ((void (__thiscall *)(CPane *, int, int, int, int, int, int))v23->FloatPane)(
      a1: v16,
      a2: Rect.left,
      a3: Rect.top,
      a4: Rect.right,
      a5: Rect.bottom,
      a6: 3,
      a7: 1);
    v2 = pMenu;
  }
LABEL_23:
  if ( v36 != nullptr )
  {
    v26 = v36->OnTearOffMenu(this: v36, a2: v2, a3: v16);
  }
  else
  {
    v27 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject);
    if ( v27 != nullptr )
    {
      v26 = ((int (__thiscall *)(CObject *, CMFCPopupMenu *, CPane *))v27->__vftable[40].dtr_CObject)(
              a1: v27,
              a2: v2,
              a3: v16);
    }
    else
    {
      v28 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject);
      if ( v28 == nullptr )
      {
        v28 = AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject);
        if ( v28 == nullptr )
          goto LABEL_32;
      }
      v26 = ((int (__thiscall *)(CObject *, CMFCPopupMenu *, CPane *))v28->__vftable[42].Serialize)(
              a1: v28,
              a2: v2,
              a3: v16);
    }
  }
  if ( v26 == 0 )
  {
    v16->DestroyWindow(this: v16);
    ((void (__thiscall *)(CPane *, int))v16->dtr_CObject)(a1: v16, a2: 1);
    return nullptr;
  }
LABEL_32:
  v16->OnUpdateCmdUI(this: v16, a2: (CFrameWnd *)pObject, a3: 1);
  v29 = v16->CalcSize(this: v16, result: (CSize *)&v35, a3: 0);
  cx = v29->cx;
  cy = v29->cy;
  Rect.right = Point.x + cx;
  Rect.top = Point.y;
  Rect.bottom = Point.y + cy;
  v32 = v16->__vftable;
  Rect.left = Point.x;
  ((void (__thiscall *)(CPane *, int, int, int, int, int, int))v32->FloatPane)(
    a1: v16,
    a2: Point.x,
    a3: Point.y,
    a4: Point.x + cx,
    a5: Rect.bottom,
    a6: 3,
    a7: 1);
  v16->RecalcLayout(this: v16);
  ((void (__thiscall *)(CObject *, int))pObject->__vftable[31].GetRuntimeClass)(a1: pObject, a2: 1);
  v33 = v16->GetParentMiniFrame(this: v16, a2: 1);
  if ( v33 == nullptr )
    return nullptr;
  return CPaneFrameWnd::StartTearOff(this: v33, pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x10380AC4
// Name: protected: void CMFCShadowWnd::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShadowWnd::OnSize(CMFCShadowWnd *this, unsigned __int8 *nType, CBitmap *cx, int cy)
{
  int v5; // edi
  HBITMAP__ *v6; // eax
  HDC CompatibleDC; // eax
  void *m_hObject; // eax
  HWND m_hWnd; // [esp-24h] [ebp-90h]
  CClientDC clientDC; // [esp+10h] [ebp-5Ch] BYREF
  CPoint v11; // [esp+24h] [ebp-48h]
  int v12; // [esp+2Ch] [ebp-40h]
  int v13; // [esp+30h] [ebp-3Ch]
  CDC dc; // [esp+34h] [ebp-38h] BYREF
  CPoint point; // [esp+44h] [ebp-28h] BYREF
  CBitmap bitmap; // [esp+4Ch] [ebp-20h] BYREF
  CSize size; // [esp+54h] [ebp-18h] BYREF
  CMFCShadowWnd *v18; // [esp+5Ch] [ebp-10h]
  int v19; // [esp+68h] [ebp-4h]

  v18 = this;
  v5 = cy;
  CFrameWnd::OnSize(this, (unsigned int)nType, (int)cx, cy);
  if ( cx != nullptr && v5 != 0 )
  {
    size.cx = (int)cx;
    point.x = 0;
    point.y = 0;
    size.cy = v5;
    nType = nullptr;
    v6 = CDrawingManager::CreateBitmap_32(&size, pBits: (void **)&nType);
    if ( v6 != nullptr )
    {
      bitmap.m_hObject = nullptr;
      bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
      v19 = 0;
      CGdiObject::Attach(this: &bitmap, hObject: v6);
      CClientDC::CClientDC(this: &clientDC, pWnd: this);
      LOBYTE(v19) = 1;
      CDC::CDC(this: &dc);
      LOBYTE(v19) = 2;
      CompatibleDC = CreateCompatibleDC(hdc: clientDC.m_hDC);
      CDC::Attach(this: &dc, hDC: CompatibleDC);
      cx = (CBitmap *)CDC::SelectGdiObject(hDC: dc.m_hDC, h: bitmap.m_hObject);
      v12 = point.x + size.cx;
      v11 = point;
      v13 = point.y + size.cy;
      ((void (__thiscall *)(CMFCShadowRenderer *, CDC *, int, int, int, int, _DWORD, int))this->m_Shadow.Draw)(
        a1: &this->m_Shadow,
        a2: &dc,
        a3: point.x,
        a4: point.y,
        a5: point.x + size.cx,
        a6: point.y + size.cy,
        a7: 0,
        a8: 255);
      m_hWnd = v18->m_hWnd;
      cy = 33488896;
      UpdateLayeredWindow(
        hWnd: m_hWnd,
        hdcDst: nullptr,
        pptDst: nullptr,
        psize: &size,
        hdcSrc: dc.m_hDC,
        pptSrc: &point,
        crKey: 0,
        pblend: (BLENDFUNCTION *)&cy,
        dwFlags: 2u);
      if ( cx != nullptr )
        m_hObject = cx->m_hObject;
      else
        m_hObject = nullptr;
      CDC::SelectGdiObject(hDC: dc.m_hDC, h: m_hObject);
      LOBYTE(v19) = 1;
      CDC::~CDC(this: &dc);
      LOBYTE(v19) = 0;
      CClientDC::~CClientDC(this: &clientDC);
      v19 = -1;
      bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
      CGdiObject::~CGdiObject(this: &bitmap);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10380C19
// Name: public: CMFCPopupMenu::CMFCPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__thiscall CMFCPopupMenu::CMFCPopupMenu(CMFCPopupMenu *this)
{
  CAfxStringMgr *StringManager; // eax

  CMiniFrameWnd::CMiniFrameWnd(this);
  this->__vftable = (CMFCPopupMenu_vtbl *)&CMFCPopupMenu::`vftable';
  this->m_ptLocation.x = 0;
  this->m_ptLocation.y = 0;
  this->m_ptLocationInitial.x = 0;
  this->m_ptLocationInitial.y = 0;
  this->m_FinalSize.cx = 0;
  this->m_FinalSize.cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  this->m_pMenuCustomizationPage = nullptr;
  CMFCPopupMenuBar::CMFCPopupMenuBar(this: &this->m_wndMenuBar);
  this->m_AnimSize.cx = 0;
  this->m_AnimSize.cy = 0;
  this->m_rectScrollUp.left = 0;
  this->m_rectScrollUp.top = 0;
  this->m_rectScrollUp.right = 0;
  this->m_rectScrollUp.bottom = 0;
  this->m_rectScrollDn.left = 0;
  this->m_rectScrollDn.top = 0;
  this->m_rectScrollDn.right = 0;
  this->m_rectScrollDn.bottom = 0;
  CWnd::CWnd(this: &this->m_wndScrollBarVert);
  this->m_wndScrollBarVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  this->m_bmpScreenSrc.m_hObject = nullptr;
  this->m_bmpScreenSrc.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpScreenDst.m_hObject = nullptr;
  this->m_bmpScreenDst.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpScreenTmp.m_hObject = nullptr;
  this->m_bmpScreenTmp.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpShadowRight.m_hObject = nullptr;
  this->m_bmpShadowRight.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpShadowBottom.m_hObject = nullptr;
  this->m_bmpShadowBottom.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_rectTearOffCaption.left = 0;
  this->m_rectTearOffCaption.top = 0;
  this->m_rectTearOffCaption.right = 0;
  this->m_rectTearOffCaption.bottom = 0;
  CToolTipCtrl::CToolTipCtrl(this: &this->m_wndToolTip);
  this->m_sizeMinResize.cx = 0;
  this->m_sizeMinResize.cy = 0;
  this->m_sizeCurrent.cx = 0;
  this->m_sizeCurrent.cy = 0;
  this->m_rectResize.left = 0;
  this->m_rectResize.top = 0;
  this->m_rectResize.right = 0;
  this->m_rectResize.bottom = 0;
  CMFCPopupMenu::Initialize(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10380D84
// Name: public: virtual class CMFCPopupMenuBar __near * CMFCPopupMenu::GetMenuBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenuBar *__thiscall CMFCPopupMenu::GetMenuBar(CMFCPopupMenu *this)
{
  return &this->m_wndMenuBar;
}

//------------------------------------------------------------------------------
// Address: 0x10380D8B
// Name: public: virtual int CMFCPopupMenu::InCommand(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenuBar *__thiscall CMFCPopupMenu::InCommand(CMFCPopupMenu *this)
{
  CMFCPopupMenuBar *result; // eax

  result = this->GetMenuBar(this);
  if ( result != nullptr )
    return (CMFCPopupMenuBar *)result->m_bInCommand;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10380D9F
// Name: public: virtual int CMFCPopupMenu::IsIdle(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCPopupMenu::IsIdle(CMFCPopupMenu *this)
{
  BOOL result; // eax

  result = false;
  if ( this->m_bAnimationIsDone != 0 )
    return this->m_iScrollMode == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10380DB3
// Name: public: virtual int CMFCMenuBar::AllowShowOnPaneMenu(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CMFCMenuBar::AllowShowOnPaneMenu()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10380DB6
// Name: public: virtual CMFCPopupMenu::~CMFCPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::~CMFCPopupMenu(CMFCPopupMenu *this)
{
  CMFCRibbonBaseElement *m_pParentRibbonElement; // ecx

  this->__vftable = (CMFCPopupMenu_vtbl *)&CMFCPopupMenu::`vftable';
  m_pParentRibbonElement = this->m_pParentRibbonElement;
  if ( m_pParentRibbonElement != nullptr )
    CMFCRibbonBaseElement::SetDroppedDown(this: m_pParentRibbonElement, pPopupMenu: nullptr);
  if ( this->m_bAutoDestroy != 0 && this->m_hMenu != nullptr )
    DestroyMenu(hMenu: this->m_hMenu);
  if ( this->m_hwndConnectedFloaty != nullptr && IsWindow(hWnd: this->m_hwndConnectedFloaty) )
    SendMessageA(hWnd: this->m_hwndConnectedFloaty, Msg: 0x10u, wParam: 0, lParam: 0);
  CToolTipCtrl::~CToolTipCtrl(this: &this->m_wndToolTip);
  this->m_bmpShadowBottom.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpShadowBottom);
  this->m_bmpShadowRight.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpShadowRight);
  this->m_bmpScreenTmp.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpScreenTmp);
  this->m_bmpScreenDst.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpScreenDst);
  this->m_bmpScreenSrc.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpScreenSrc);
  CScrollBar::~CScrollBar(this: &this->m_wndScrollBarVert);
  CMFCPopupMenuBar::~CMFCPopupMenuBar(this: &this->m_wndMenuBar);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCaption.m_pszData - 1);
  CMiniFrameWnd::~CMiniFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10380ECA
// Name: protected: virtual class CPane __near * CMFCPopupMenu::CreateTearOffBar(class CFrameWnd __near *,unsigned int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBar *__thiscall CMFCPopupMenu::CreateTearOffBar(
        CMFCPopupMenu *this,
        CFrameWnd *pWndMain,
        unsigned int uiID,
        char *lpszName)
{
  CMFCToolBar *v4; // esi
  char *v6; // eax
  CMFCToolBar_vtbl *v7; // eax
  CMenu *v8; // ebx
  int MenuItemCount; // eax
  UINT MenuItemID; // edi
  CAfxStringMgr *StringManager; // eax
  int m_iImage; // eax
  int v13; // eax
  ATL::CStringData *v14; // eax
  char *m_pszData; // edi
  HMENU SubMenu; // eax
  HMENU__ *v17; // eax
  int m_iUserImage; // eax
  CMFCToolBar_vtbl *v19; // edi
  int v20; // eax
  CMFCToolBarMenuButton *m_pParentBtn; // eax
  int m_nPaletteRows; // edi
  int v23; // eax
  char v24[4]; // [esp+10h] [ebp-184h] BYREF
  CMFCPopupMenu *v25; // [esp+14h] [ebp-180h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v26; // [esp+18h] [ebp-17Ch] BYREF
  int i; // [esp+1Ch] [ebp-178h]
  CMenu *v28; // [esp+20h] [ebp-174h]
  int nPos; // [esp+24h] [ebp-170h]
  ATL::CSimpleStringT<char,0> v30; // [esp+28h] [ebp-16Ch] BYREF
  CMFCToolBarMenuButton v31; // [esp+2Ch] [ebp-168h] BYREF
  CMFCToolBarButton v32; // [esp+114h] [ebp-80h] BYREF
  int v33; // [esp+190h] [ebp-4h]

  v4 = nullptr;
  v25 = this;
  if ( lpszName == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_hMenu == nullptr )
    return nullptr;
  v28 = CMenu::FromHandle(hMenu: this->m_hMenu);
  if ( v28 == nullptr )
    return nullptr;
  v6 = (char *)operator new(nSize: 0xCC8u);
  v26.m_pszData = v6;
  v33 = 0;
  if ( v6 != nullptr )
    v4 = CMFCToolBar::CMFCToolBar(this: (CMFCToolBar *)v6);
  v7 = v4->__vftable;
  v33 = -1;
  if ( v7->Create(this: v4, a2: pWndMain, a3: 1346381832u, a4: uiID) == 0 )
  {
    ((void (__thiscall *)(CMFCToolBar *, int))v4->dtr_CObject)(a1: v4, a2: 1);
    return nullptr;
  }
  CWnd::SetWindowTextA(this: v4, lpszString: lpszName);
  v8 = v28;
  MenuItemCount = GetMenuItemCount(hMenu: v28->m_hMenu);
  nPos = 0;
  for ( i = MenuItemCount; nPos < i; ++nPos )
  {
    MenuItemID = GetMenuItemID(hMenu: v8->m_hMenu, nPos);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v30, pStringMgr: StringManager);
    v33 = 1;
    CMenu::GetMenuStringA(
      this: v8,
      nIDItem: nPos,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v30,
      nFlags: 0x400u);
    if ( MenuItemID != 0 )
    {
      if ( MenuItemID == -1 )
      {
        v28 = nullptr;
        if ( g_pTearOffMenuManager != nullptr )
          v28 = (CMenu *)CMenuTearOffManager::Parse(
                           this: g_pTearOffMenuManager,
                           str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v30);
        v13 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v30,
                ch: 9u,
                iStart: 0);
        if ( v13 >= 0 )
        {
          v14 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v30,
                                      result: &v26,
                                      nCount: v13);
          LOBYTE(v33) = 2;
          ATL::CSimpleStringT<char,0>::operator=(this: &v30, strSrc: v14);
          LOBYTE(v33) = 1;
          ATL::CStringData::Release(this: (ATL::CStringData *)v26.m_pszData - 1);
        }
        m_pszData = v30.m_pszData;
        SubMenu = GetSubMenu(hMenu: v8->m_hMenu, nPos);
        v17 = (HMENU__ *)CMenu::FromHandle(hMenu: SubMenu);
        if ( v17 != nullptr )
          v17 = *((HMENU__ **)v17 + 1);
        CMFCToolBarMenuButton::CMFCToolBarMenuButton(
          this: &v31,
          uiID: 0xFFFFFFFF,
          hMenu: v17,
          iImage: -1,
          lpszText: m_pszData,
          bUserButton: 0);
        m_iUserImage = v31.m_iUserImage;
        LOBYTE(v33) = 3;
        if ( v31.m_bUserButton == 0 )
          m_iUserImage = v31.m_iImage;
        if ( m_iUserImage == -1 )
        {
          v31.m_bImage = 0;
          v31.m_bText = 1;
        }
        CMFCToolBarMenuButton::SetTearOff(this: &v31, uiBarID: (unsigned int)v28);
        v4->InsertButton(this: v4, a2: &v31, a3: -1);
        LOBYTE(v33) = 1;
        CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v31);
      }
      else if ( IsStandardCommand(uiCmd: MenuItemID) == 0 )
      {
        CMFCToolBarButton::CMFCToolBarButton(
          this: &v32,
          uiID: MenuItemID,
          iImage: -1,
          lpszText: v30.m_pszData,
          bUserButton: 0,
          bLocked: 0);
        m_iImage = v32.m_iUserImage;
        LOBYTE(v33) = 4;
        if ( v32.m_bUserButton == 0 )
          m_iImage = v32.m_iImage;
        if ( m_iImage == -1 )
        {
          v32.m_bImage = 0;
          v32.m_bText = 1;
        }
        v4->InsertButton(this: v4, a2: &v32, a3: -1);
        LOBYTE(v33) = 1;
        CMFCToolBarButton::~CMFCToolBarButton(this: &v32);
      }
    }
    else if ( nPos != i - 1 )
    {
      v4->InsertSeparator(this: v4, a2: -1);
    }
    v33 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)v30.m_pszData - 1);
  }
  v19 = v4->__vftable;
  v20 = v4->GetPaneStyle(this: v4);
  v19->SetPaneStyle(this: v4, a2: v20 | 0x34);
  v4->EnableDocking(this: v4, a2: 61440u);
  m_pParentBtn = v25->m_pParentBtn;
  if ( m_pParentBtn != nullptr && m_pParentBtn->m_bMenuPaletteMode != 0 )
  {
    m_nPaletteRows = m_pParentBtn->m_nPaletteRows;
    v23 = v4->GetColumnWidth(this: v4);
    ((void (__fastcall *)(CMFCToolBar *, int, char *, int, _DWORD))v4->StretchPane)(
      a1: v4,
      a2: i % m_nPaletteRows,
      a3: v24,
      a4: (i / m_nPaletteRows + 1) * v23,
      a5: 0);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103811FE
// Name: public: virtual class CMFCPopupMenu __near * CMFCToolBarMenuButton::CreatePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__stdcall CMFCToolBarMenuButton::CreatePopupMenu()
{
  CMFCPopupMenu *v0; // ecx
  CMFCPopupMenu *result; // eax

  v0 = (CMFCPopupMenu *)operator new(nSize: 0x10C4u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCPopupMenu::CMFCPopupMenu(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038124F
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCShadowWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCShadowWnd::GetMessageMap(CMFCShadowWnd *this)
{
  return (const AFX_MSGMAP *)&off_1067C0E0;
}

//------------------------------------------------------------------------------
// Address: 0x10381255
// Name: public: virtual int CMFCShadowWnd::Create(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShadowWnd::Create(CMFCShadowWnd *this)
{
  int v3; // ebx
  HCURSOR CursorA; // eax
  const char *v5; // eax
  CMFCPopupMenu *m_pOwner; // ecx
  HWND Parent; // eax
  CWnd *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v9; // [esp+10h] [ebp-24h] BYREF
  tagRECT rect; // [esp+14h] [ebp-20h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  if ( afxGlobalData.m_nBitsPerPixel <= 8 )
    return 0;
  v3 = 0;
  CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  v5 = AfxRegisterWndClass(nClassStyle: 0x800u, hCursor: CursorA, hbrBackground: (HBRUSH__ *)0x10, hIcon: nullptr);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v9,
    pszSrc: v5);
  m_pOwner = this->m_pOwner;
  v11 = 0;
  memset(&rect, 0, sizeof(rect));
  if ( (CWnd::GetExStyle(this: m_pOwner) & 0x400000) != 0 )
    this->m_bIsRTL = 1;
  Parent = GetParent(hWnd: this->m_pOwner->m_hWnd);
  v8 = CWnd::FromHandle(hWnd: Parent);
  if ( CMiniFrameWnd::CreateEx(
         this,
         dwExStyle: 0x80080u,
         lpClassName: v9.m_pszData,
         lpszWindowName: &var,
         dwStyle: 0x80000000,
         &rect,
         pParentWnd: v8,
         nID: nullptr) != 0 )
  {
    this->m_Shadow.Create_2(this: &this->m_Shadow, a2: this->m_nOffset, a3: 5921370u, a4: 0, a5: 50);
    v3 = 1;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)v9.m_pszData - 1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1038132C
// Name: protected: CMFCPopupMenu::CMFCPopupMenu(class CMFCToolBarsMenuPropertyPage __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__thiscall CMFCPopupMenu::CMFCPopupMenu(
        CMFCPopupMenu *this,
        CMFCToolBarsMenuPropertyPage *pCustPage,
        const char *lpszTitle)
{
  CMiniFrameWnd::CMiniFrameWnd(this);
  this->__vftable = (CMFCPopupMenu_vtbl *)&CMFCPopupMenu::`vftable';
  this->m_ptLocation.x = 0;
  this->m_ptLocation.y = 0;
  this->m_ptLocationInitial.x = 0;
  this->m_ptLocationInitial.y = 0;
  this->m_FinalSize.cx = 0;
  this->m_FinalSize.cy = 0;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &this->m_strCaption,
    pszSrc: lpszTitle);
  this->m_pMenuCustomizationPage = pCustPage;
  CMFCPopupMenuBar::CMFCPopupMenuBar(this: &this->m_wndMenuBar);
  this->m_AnimSize.cx = 0;
  this->m_AnimSize.cy = 0;
  this->m_rectScrollUp.left = 0;
  this->m_rectScrollUp.top = 0;
  this->m_rectScrollUp.right = 0;
  this->m_rectScrollUp.bottom = 0;
  this->m_rectScrollDn.left = 0;
  this->m_rectScrollDn.top = 0;
  this->m_rectScrollDn.right = 0;
  this->m_rectScrollDn.bottom = 0;
  CWnd::CWnd(this: &this->m_wndScrollBarVert);
  this->m_wndScrollBarVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  this->m_bmpScreenSrc.m_hObject = nullptr;
  this->m_bmpScreenSrc.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpScreenDst.m_hObject = nullptr;
  this->m_bmpScreenDst.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpScreenTmp.m_hObject = nullptr;
  this->m_bmpScreenTmp.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpShadowRight.m_hObject = nullptr;
  this->m_bmpShadowRight.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bmpShadowBottom.m_hObject = nullptr;
  this->m_bmpShadowBottom.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_rectTearOffCaption.left = 0;
  this->m_rectTearOffCaption.top = 0;
  this->m_rectTearOffCaption.right = 0;
  this->m_rectTearOffCaption.bottom = 0;
  CToolTipCtrl::CToolTipCtrl(this: &this->m_wndToolTip);
  this->m_sizeMinResize.cx = 0;
  this->m_sizeMinResize.cy = 0;
  this->m_sizeCurrent.cx = 0;
  this->m_sizeCurrent.cy = 0;
  this->m_rectResize.left = 0;
  this->m_rectResize.top = 0;
  this->m_rectResize.right = 0;
  this->m_rectResize.bottom = 0;
  CMFCPopupMenu::Initialize(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10381499
// Name: public: virtual int CMFCPopupMenu::Create(class CWnd __near *,int,int,struct HMENU__ __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::Create(
        CMFCPopupMenu *this,
        CWnd *pWndParent,
        int x,
        int y,
        HMENU__ *hMenu,
        int bLocked,
        int bOwnMessage)
{
  HCURSOR CursorA; // eax
  const char *v9; // eax
  int v10; // ecx
  CMFCPopupMenu *ParentPopupMenu; // eax
  CWnd *Owner; // eax
  unsigned int v13; // eax
  CMFCPopupMenuBar *v15; // edi
  int m_iShadowSize; // edx
  int v17; // ecx
  __int32 v18; // eax
  int cy; // eax
  char *v20; // [esp-18h] [ebp-68h]
  char *m_pszData; // [esp-14h] [ebp-64h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-58h]
  CWnd *v23; // [esp-8h] [ebp-58h]
  unsigned int dwStyle; // [esp+10h] [ebp-40h]
  int v25; // [esp+18h] [ebp-38h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v26; // [esp+1Ch] [ebp-34h] BYREF
  tagRECT Rect; // [esp+20h] [ebp-30h] BYREF
  tagRECT rect; // [esp+30h] [ebp-20h] BYREF
  int v29; // [esp+4Ch] [ebp-4h]

  AFXPlaySystemSound(nSound: 2);
  if ( pWndParent == nullptr )
    AfxThrowInvalidArgException();
  CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  v9 = AfxRegisterWndClass(nClassStyle: 0x800u, hCursor: CursorA, hbrBackground: (HBRUSH__ *)0x10, hIcon: nullptr);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v26,
    pszSrc: v9);
  this->m_hMenu = hMenu;
  v29 = 0;
  if ( x == -1 && y == -1 )
  {
    m_hWnd = pWndParent->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    CWnd::ClientToScreen(this: pWndParent, lpRect: &Rect);
    v10 = Rect.top + 5;
    this->m_ptLocation.x = Rect.left + 5;
    this->m_ptLocation.y = v10;
  }
  else
  {
    this->m_ptLocation.x = x;
    this->m_ptLocation.y = y;
  }
  this->m_ptLocationInitial.x = this->m_ptLocation.x;
  this->m_ptLocationInitial.y = this->m_ptLocation.y;
  dwStyle = 0x80000000;
  if ( this->m_pMenuCustomizationPage != nullptr )
    dwStyle = -2134376448;
  if ( pWndParent->m_hWnd != nullptr && (CWnd::GetExStyle(this: pWndParent) & 0x400000) != 0 )
    this->m_bDisableAnimation = 1;
  if ( this->m_bDisableAnimation != 0 )
    this->m_bAnimationIsDone = 1;
  if ( CMFCPopupMenu::GetAnimationType(bNoSystem: 0) == NO_ANIMATION
    || CMFCToolBar::m_bCustomizeMode != 0
    || (v25 = 1, this->m_bDisableAnimation != 0) )
  {
    v25 = 0;
  }
  ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
  if ( ParentPopupMenu != nullptr )
    this->m_bTrackMode = ParentPopupMenu->m_bTrackMode;
  if ( bOwnMessage != 0 )
  {
    this->m_pMessageWnd = pWndParent;
  }
  else if ( ParentPopupMenu != nullptr )
  {
    this->m_pMessageWnd = ParentPopupMenu->m_pMessageWnd;
  }
  rect.left = x;
  rect.right = x;
  rect.top = y;
  rect.bottom = y;
  if ( CWnd::GetOwner(this: pWndParent) != nullptr )
    Owner = CWnd::GetOwner(this: pWndParent);
  else
    Owner = pWndParent;
  v23 = Owner;
  m_pszData = this->m_strCaption.m_pszData;
  v20 = v26.m_pszData;
  v13 = CWnd::GetExStyle(this: pWndParent);
  if ( CMiniFrameWnd::CreateEx(
         this,
         dwExStyle: v13 & 0x400000,
         lpClassName: v20,
         lpszWindowName: m_pszData,
         dwStyle,
         &rect,
         pParentWnd: v23,
         nID: nullptr) == 0 )
  {
    ATL::CStringData::Release(this: (ATL::CStringData *)v26.m_pszData - 1);
    return 0;
  }
  if ( this->m_bRightAlign != 0 )
  {
    this->m_ptLocation.x += 1 - this->m_FinalSize.cx;
    this->m_ptLocationInitial.x = this->m_ptLocation.x;
    this->m_ptLocationInitial.y = this->m_ptLocation.y;
    this->RecalcLayout(this, a2: 1);
  }
  v15 = this->GetMenuBar(this);
  v15->m_bLocked = bLocked;
  v15->m_bDropDownListMode = this->m_bShowScrollBar;
  if ( v25 != 0 )
  {
    m_iShadowSize = this->m_iShadowSize;
    v17 = m_iShadowSize + this->m_FinalSize.cy;
    this->m_AnimSize.cx = m_iShadowSize + this->m_FinalSize.cx;
    this->m_AnimSize.cy = v17;
    v18 = CMFCPopupMenu::GetAnimationType(bNoSystem: 0) - 1;
    if ( v18 != 0 )
    {
      if ( v18 != 1 )
        goto LABEL_37;
    }
    else
    {
      this->m_AnimSize.cx = v15->GetColumnWidth(this: v15);
    }
    this->m_AnimSize.cy = v15->GetRowHeight(this: v15);
LABEL_37:
    if ( IsWindowVisible(hWnd: v15->m_hWnd) )
      CWnd::ShowWindow(this: v15, nCmdShow: 0);
    SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: CMFCPopupMenu::m_AnimationSpeed, lpTimerFunc: nullptr);
    nLastAnimTime = clock();
  }
  CMFCPopupMenu::UpdateBottomWindows(this, bCheckOnly: 0);
  if ( this->m_iShadowSize == 0 && CMFCPopupMenu::GetAnimationType(bNoSystem: 0) == FADE && v25 != 0 )
  {
    cy = this->m_FinalSize.cy;
    this->m_AnimSize.cx = this->m_FinalSize.cx;
    this->m_AnimSize.cy = cy;
  }
  CWnd::SetWindowPos(this, pWndInsertAfter: &CWnd::wndTop, x: -1, y: -1, cx: -1, cy: -1, nFlags: 0x53u);
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
  {
    InvalidateRect(hWnd: v15->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: v15->m_hWnd);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)v26.m_pszData - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103817E1
// Name: public: int AFX_GLOBAL_DATA::GetShellAutohideBars(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall AFX_GLOBAL_DATA::GetShellAutohideBars(AFX_GLOBAL_DATA *this)
{
  _AppBarData abd; // [esp+8h] [ebp-28h] BYREF

  if ( this->m_bRefreshAutohideBars != 0 )
  {
    this->m_bRefreshAutohideBars = 0;
    memset(dst: (unsigned __int8 *)&abd, value: 0, count: sizeof(abd));
    abd.cbSize = 36;
    abd.uEdge = 3;
    if ( SHAppBarMessage(dwMessage: 7u, pData: &abd) != 0 )
      this->m_nShellAutohideBars |= 8u;
    abd.uEdge = 1;
    if ( SHAppBarMessage(dwMessage: 7u, pData: &abd) != 0 )
      this->m_nShellAutohideBars |= 4u;
    abd.uEdge = 0;
    if ( SHAppBarMessage(dwMessage: 7u, pData: &abd) != 0 )
      this->m_nShellAutohideBars |= 1u;
    abd.uEdge = 2;
    if ( SHAppBarMessage(dwMessage: 7u, pData: &abd) != 0 )
      this->m_nShellAutohideBars |= 2u;
  }
  return this->m_nShellAutohideBars;
}

//------------------------------------------------------------------------------
// Address: 0x1038189D
// Name: public: CSettingsStoreSP::~CSettingsStoreSP(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSettingsStoreSP::~CSettingsStoreSP(CSettingsStoreSP *this)
{
  CSettingsStore *m_pRegistry; // ecx

  m_pRegistry = this->m_pRegistry;
  if ( m_pRegistry != nullptr )
    ((void (__thiscall *)(CSettingsStore *, int))m_pRegistry->dtr_CObject)(a1: m_pRegistry, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103818AB
// Name: protected: int CFrameImpl::IsUserDefinedToolbar(class CMFCToolBar const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameImpl::IsUserDefinedToolbar(CFrameImpl *this, const CMFCToolBar *pToolBar)
{
  unsigned int DlgCtrlID; // eax

  DlgCtrlID = CWnd::GetDlgCtrlID(this: &pToolBar->CMFCBaseToolBar);
  return DlgCtrlID >= this->m_uiUserToolbarFirst && DlgCtrlID <= this->m_uiUserToolbarLast;
}

//------------------------------------------------------------------------------
// Address: 0x103818D1
// Name: protected: static unsigned int CFrameImpl::GetFreeCtrlBarID(unsigned int,unsigned int,class CObList const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall CFrameImpl::GetFreeCtrlBarID(
        unsigned int uiFirstID,
        unsigned int uiLastID,
        const CObList *lstCtrlBars)
{
  unsigned int v3; // ebx
  CObList::CNode *m_pNodeHead; // esi
  BOOL i; // eax
  CWnd *data; // ecx

  if ( uiFirstID == -1 )
    return 0;
  if ( uiLastID == -1 )
    return 0;
  if ( lstCtrlBars->m_nCount == uiLastID - uiFirstID + 1 )
    return 0;
  v3 = uiFirstID;
  if ( uiFirstID > uiLastID )
    return 0;
  while ( 1 )
  {
    m_pNodeHead = lstCtrlBars->m_pNodeHead;
    for ( i = false; !i; i = v3 == CWnd::GetDlgCtrlID(this: data) )
    {
      if ( m_pNodeHead == nullptr )
        break;
      data = (CWnd *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
    }
    if ( !i )
      break;
    if ( ++v3 > uiLastID )
      return 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1038192F
// Name: protected: void CFrameImpl::AddTearOffToolbar(class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::AddTearOffToolbar(CFrameImpl *this, CBasePane *pToolBar)
{
  CPtrList::AddTail(this: &this->m_listTearOffToolbars, newElement: pToolBar);
}

//------------------------------------------------------------------------------
// Address: 0x1038193D
// Name: protected: void CFrameImpl::RemoveTearOffToolbar(class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::RemoveTearOffToolbar(CFrameImpl *this, CBasePane *pToolBar)
{
  CObList *p_m_listTearOffToolbars; // esi
  __POSITION *v3; // eax

  p_m_listTearOffToolbars = &this->m_listTearOffToolbars;
  v3 = (__POSITION *)CPtrList::Find(this: &this->m_listTearOffToolbars, searchValue: pToolBar, startAfter: nullptr);
  if ( v3 != nullptr )
    CPtrList::RemoveAt(this: p_m_listTearOffToolbars, position: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10381963
// Name: protected: int CFrameImpl::OnMenuChar(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameImpl::OnMenuChar(CFrameImpl *this, unsigned int nChar)
{
  CMFCRibbonBar *m_pRibbonBar; // ecx
  CDockingManager *m_pDockManager; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CMFCMenuBar *m_pMenuBar; // ecx
  CMFCMenuBar *data; // edi
  int bInPrintPreview; // [esp+4h] [ebp-4h]

  m_pRibbonBar = this->m_pRibbonBar;
  if ( m_pRibbonBar != nullptr
    && (CWnd::GetStyle(this: m_pRibbonBar) & 0x10000000) != 0
    && this->m_pRibbonBar->TranslateChar(this: this->m_pRibbonBar, a2: nChar) != 0 )
  {
    return 1;
  }
  m_pDockManager = this->m_pDockManager;
  if ( m_pDockManager != nullptr && m_pDockManager->m_bIsPrintPreviewMode != 0 )
  {
    bInPrintPreview = 1;
  }
  else
  {
    m_pMenuBar = this->m_pMenuBar;
    bInPrintPreview = 0;
    if ( m_pMenuBar != nullptr
      && (CWnd::GetStyle(this: m_pMenuBar) & 0x10000000) != 0
      && this->m_pMenuBar->TranslateChar(this: this->m_pMenuBar, a2: nChar) != 0 )
    {
      return 1;
    }
  }
  m_pNodeHead = afxAllToolBars.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return 0;
    data = (CMFCMenuBar *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
  }
  while ( bInPrintPreview != 0
       && CObject::IsKindOf(this: data, pClass: &CMFCPrintPreviewToolBar::classCMFCPrintPreviewToolBar) == 0
       || CWnd::FromHandlePermanent(hWnd: data->m_hWnd) == nullptr
       || data == this->m_pMenuBar
       || (CWnd::GetStyle(this: data) & 0x10000000) == 0
       || CWnd::GetTopLevelFrame(this: data) != this->m_pFrame
       || data->TranslateChar(this: data, a2: nChar) == 0 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10381A7A
// Name: protected: static int CFrameImpl::IsHelpKey(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CFrameImpl::IsHelpKey(tagMSG *lpMsg)
{
  return lpMsg->message == 256
      && lpMsg->wParam == 112
      && (lpMsg->lParam & 0x40000000) == 0
      && GetKeyState(nVirtKey: 16) >= 0
      && GetKeyState(nVirtKey: 17) >= 0
      && GetKeyState(nVirtKey: 18) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10381ACA
// Name: protected: int CFrameImpl::OnShowCustomizePane(class CMFCPopupMenu __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameImpl::OnShowCustomizePane(CFrameImpl *this, CMFCPopupMenu *pMenuPane, unsigned int uiToolbarID)
{
  int v4; // edi
  CObject *v5; // eax
  CObject *v7; // eax
  CObject *v8; // eax

  v4 = 0;
  v5 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: this->m_pFrame);
  if ( v5 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCPopupMenu *, unsigned int))v5->__vftable[40].GetRuntimeClass)(
             a1: v5,
             a2: pMenuPane,
             a3: uiToolbarID);
  v7 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: this->m_pFrame);
  if ( v7 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCPopupMenu *, unsigned int))v7->__vftable[38].dtr_CObject)(
             a1: v7,
             a2: pMenuPane,
             a3: uiToolbarID);
  v8 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: this->m_pFrame);
  if ( v8 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCPopupMenu *, unsigned int))v8->__vftable[40].Serialize)(
             a1: v8,
             a2: pMenuPane,
             a3: uiToolbarID);
  v8 = AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject: this->m_pFrame);
  if ( v8 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCPopupMenu *, unsigned int))v8->__vftable[40].Serialize)(
             a1: v8,
             a2: pMenuPane,
             a3: uiToolbarID);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10381B6B
// Name: protected: void CFrameImpl::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::OnWindowPosChanging(CFrameImpl *this, tagWINDOWPOS *lpwndpos)
{
  unsigned int flags; // eax
  CMFCVisualManager *Instance; // eax
  int v6; // eax
  bool v7; // zf
  int oldState; // [esp+Ch] [ebp+8h]

  if ( this->m_bWindowPosChanging == 0 && this->m_bIsOleInPlaceActive == 0 )
  {
    flags = lpwndpos->flags;
    if ( ((flags & 1) == 0 || (flags & 0x20) != 0)
      && (this->m_pRibbonBar != nullptr || CFrameImpl::IsOwnerDrawCaption(this) != 0) )
    {
      this->m_bWindowPosChanging = 1;
      oldState = 0;
      if ( this->m_pDockManager != nullptr )
      {
        oldState = CDockingManager::m_bDisableRecalcLayout;
        CDockingManager::m_bDisableRecalcLayout = 1;
      }
      Instance = CMFCVisualManager::GetInstance();
      v6 = ((int (__thiscall *)(CMFCVisualManager *, CFrameWnd *, int, int))Instance->OnSetWindowRegion)(
             a1: Instance,
             a2: this->m_pFrame,
             a3: lpwndpos->cx,
             a4: lpwndpos->cy);
      v7 = this->m_pDockManager == nullptr;
      this->m_bIsWindowRgn = v6;
      if ( !v7 )
        CDockingManager::m_bDisableRecalcLayout = oldState;
      this->m_bWindowPosChanging = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381C03
// Name: protected: class CMFCCaptionButtonEx __near * CFrameImpl::GetSysButton(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionButtonEx *__thiscall CFrameImpl::GetSysButton(CFrameImpl *this, unsigned int nHit)
{
  CObList::CNode *m_pNodeHead; // ecx
  CMFCCaptionButtonEx *result; // eax

  m_pNodeHead = this->m_lstCaptionSysButtons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    result = (CMFCCaptionButtonEx *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( result->m_nHit == nHit )
      return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10381C33
// Name: protected: int CFrameImpl::IsPrintPreview(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameImpl::IsPrintPreview(CFrameImpl *this)
{
  CDockingManager *m_pDockManager; // eax

  m_pDockManager = this->m_pDockManager;
  return m_pDockManager != nullptr && m_pDockManager->m_bIsPrintPreviewMode != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10381C4D
// Name: unsigned int HashKey<unsigned long>(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall HashKey<unsigned long>(CDocument *key)
{
  _ldiv_t v1; // rax

  v1 = ldiv(numer: (int)key, denom: 127773);
  return 16807 * v1.rem - 2836 * v1.quot + (16807 * v1.rem - 2836 * v1.quot < 0 ? 0x7FFFFFFF : 0);
}

//------------------------------------------------------------------------------
// Address: 0x10381C7C
// Name: public: int CMFCDropDownListBox::IsEditFocused(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCDropDownListBox::IsEditFocused(CMFCDropDownListBox *this)
{
  CWnd *m_pEditCtrl; // eax
  HWND m_hWnd; // esi

  m_pEditCtrl = this->m_pEditCtrl;
  if ( m_pEditCtrl != nullptr )
    m_hWnd = m_pEditCtrl->m_hWnd;
  else
    m_hWnd = nullptr;
  return m_hWnd == GetFocus();
}

//------------------------------------------------------------------------------
// Address: 0x10381C9F
// Name: protected: void CFrameImpl::StoreWindowPlacement(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::StoreWindowPlacement(CFrameImpl *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CObject *v3; // edi
  CFrameWnd *m_pFrame; // eax
  CFrameWnd *v5; // ecx
  tagRECT rcDst; // [esp+8h] [ebp-50h] BYREF
  tagWINDOWPLACEMENT wp; // [esp+18h] [ebp-40h] BYREF
  tagRECT rectDesktop; // [esp+44h] [ebp-14h] BYREF

  ModuleState = AfxGetModuleState();
  v3 = AfxDynamicDownCast(pClass: &CWinAppEx::classCWinAppEx, pObject: ModuleState->m_pCurrentWinApp);
  if ( v3 != nullptr )
  {
    m_pFrame = this->m_pFrame;
    if ( m_pFrame != nullptr )
      m_pFrame = (CFrameWnd *)m_pFrame->m_hWnd;
    if ( IsWindow(hWnd: (HWND)m_pFrame) )
    {
      v5 = this->m_pFrame;
      wp.length = 44;
      if ( CWnd::GetWindowPlacement(this: v5, lpwndpl: &wp) != 0 )
      {
        if ( wp.showCmd != 3 )
          wp.showCmd = 1;
        SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rectDesktop, fWinIni: 0);
        OffsetRect(lprc: &wp.rcNormalPosition, dx: rectDesktop.left, dy: rectDesktop.top);
        CopyRect(lprcDst: &rcDst, lprcSrc: &wp.rcNormalPosition);
        ((void (__thiscall *)(CObject *, tagRECT *, unsigned int, unsigned int))v3->__vftable[27].GetRuntimeClass)(
          a1: v3,
          a2: &rcDst,
          a3: wp.flags,
          a4: wp.showCmd);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381D62
// Name: protected: void CFrameImpl::RestorePosition(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::RestorePosition(CFrameImpl *this, tagCREATESTRUCTA *cs)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CObject *v3; // eax
  CObject *v4; // ebx
  int cy; // ecx
  int x; // edx
  CObject_vtbl *v7; // eax
  int y; // edi
  int m_nCmdShow; // eax
  HMONITOR v10; // eax
  int top; // ecx
  int v12; // edx
  int bottom; // eax
  int v14; // eax
  int nFlags; // [esp+8h] [ebp-64h] BYREF
  int nShowCmd; // [esp+Ch] [ebp-60h] BYREF
  tagMONITORINFO mi; // [esp+10h] [ebp-5Ch] BYREF
  CRect rectInter; // [esp+38h] [ebp-34h] BYREF
  CRect rectDesktop; // [esp+48h] [ebp-24h] BYREF
  CRect rectNormal; // [esp+58h] [ebp-14h] BYREF

  ModuleState = AfxGetModuleState();
  v3 = AfxDynamicDownCast(pClass: &CWinAppEx::classCWinAppEx, pObject: ModuleState->m_pCurrentWinApp);
  v4 = v3;
  if ( v3 != nullptr && cs->hInstance != nullptr )
  {
    cy = cs->cy;
    x = cs->x;
    v7 = v3->__vftable;
    nFlags = 0;
    y = cs->y;
    rectNormal.bottom = y + cy;
    rectNormal.top = y;
    rectNormal.left = x;
    rectNormal.right = cs->cx + x;
    nShowCmd = 1;
    if ( ((int (__thiscall *)(CObject *, CRect *, int *, int *))v7[26].Serialize)(
           a1: v4,
           a2: &rectNormal,
           a3: &nFlags,
           a4: &nShowCmd) != 0 )
    {
      if ( nShowCmd != 3 )
        nShowCmd = 1;
      m_nCmdShow = AfxGetModuleState()->m_pCurrentWinApp->m_nCmdShow;
      if ( m_nCmdShow < 2 || m_nCmdShow > 3 && (unsigned int)(m_nCmdShow - 6) > 1 )
        AfxGetModuleState()->m_pCurrentWinApp->m_nCmdShow = nShowCmd;
      memset(&rectDesktop, 0, sizeof(rectDesktop));
      memset(&rectInter, 0, sizeof(rectInter));
      mi.cbSize = 40;
      v10 = MonitorFromPoint(pt: *(POINT *)&rectNormal.left, dwFlags: 2u);
      if ( GetMonitorInfoA(hMonitor: v10, lpmi: &mi) )
        CopyRect(lprcDst: &rectDesktop, lprcSrc: &mi.rcWork);
      else
        SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rectDesktop, fWinIni: 0);
      if ( nShowCmd == 3 )
      {
        top = rectDesktop.top;
        v12 = rectDesktop.right - rectDesktop.left;
        cs->x = rectDesktop.left;
        bottom = rectDesktop.bottom;
        cs->y = top;
        cs->cx = v12;
        v14 = bottom - top;
      }
      else
      {
        if ( !IntersectRect(lprcDst: &rectInter, lprcSrc1: &rectDesktop, lprcSrc2: &rectNormal) )
          return;
        cs->x = rectInter.left;
        cs->y = rectInter.top;
        cs->cx = rectNormal.right - rectNormal.left;
        v14 = rectNormal.bottom - rectNormal.top;
      }
      cs->cy = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381ED9
// Name: protected: void CFrameImpl::OnLoadFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::OnLoadFrame(CFrameImpl *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CObject *v3; // eax
  CMFCRibbonStatusBar *m_pRibbonStatusBar; // eax
  CMFCRibbonBar *m_pRibbonBar; // ecx

  ModuleState = AfxGetModuleState();
  v3 = AfxDynamicDownCast(pClass: &CWinAppEx::classCWinAppEx, pObject: ModuleState->m_pCurrentWinApp);
  if ( v3 != nullptr )
    ((void (__thiscall *)(CObject *, _DWORD, CFrameImpl *))v3->__vftable[22].Serialize)(a1: v3, a2: 0, a3: this);
  m_pRibbonStatusBar = this->m_pRibbonStatusBar;
  if ( m_pRibbonStatusBar != nullptr && m_pRibbonStatusBar->m_hWnd != nullptr )
  {
    CWnd::SetWindowPos(this: this->m_pFrame, pWndInsertAfter: nullptr, x: -1, y: -1, cx: -1, cy: -1, nFlags: 0x37u);
  }
  else
  {
    m_pRibbonBar = this->m_pRibbonBar;
    if ( m_pRibbonBar != nullptr && m_pRibbonBar->m_hWnd != nullptr )
      m_pRibbonBar->RecalcLayout(this: m_pRibbonBar);
  }
  afxGlobalData.m_bIsRTL = CWnd::GetExStyle(this: this->m_pFrame) & 0x400000;
}

//------------------------------------------------------------------------------
// Address: 0x10381F5C
// Name: protected: int CFrameImpl::DeleteToolBar(class CMFCToolBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameImpl::DeleteToolBar(CFrameImpl *this, CMFCToolBar *pToolBar)
{
  int result; // eax
  CDockSite *v4; // ebx
  CPaneFrameWnd *v5; // eax

  result = (int)CPtrList::Find(this: &this->m_listUserDefinedToolbars, searchValue: pToolBar, startAfter: nullptr);
  if ( result != 0 )
  {
    CPtrList::RemoveAt(this: &this->m_listUserDefinedToolbars, position: (__POSITION *)result);
    pToolBar->RemoveStateFromRegistry(this: pToolBar, a2: this->m_strControlBarRegEntry.m_pszData, a3: -1, a4: -1u);
    v4 = pToolBar->GetParentDockSite(this: pToolBar);
    v5 = pToolBar->GetParentMiniFrame(this: pToolBar, a2: 0);
    if ( v4 != nullptr )
    {
      v4->RemovePane(this: v4, a2: pToolBar, a3: DM_UNKNOWN);
    }
    else if ( v5 != nullptr )
    {
      v5->RemovePane(this: v5, a2: pToolBar, a3: 0, a4: 0);
    }
    pToolBar->DestroyWindow(this: pToolBar);
    ((void (__thiscall *)(CMFCToolBar *, int))pToolBar->dtr_CObject)(a1: pToolBar, a2: 1);
    this->m_pFrame->RecalcLayout(this: this->m_pFrame, a2: 1);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10381FFC
// Name: protected: void CFrameImpl::SetMenuBar(class CMFCMenuBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::SetMenuBar(CFrameImpl *this, CMFCMenuBar *pMenuBar)
{
  CFrameWnd *m_pFrame; // ecx
  HMENU__ *v4; // eax
  CMFCMenuBar *m_pMenuBar; // ecx

  if ( this->m_pMenuBar != nullptr )
    AfxThrowInvalidArgException();
  m_pFrame = this->m_pFrame;
  this->m_pMenuBar = pMenuBar;
  v4 = (HMENU__ *)m_pFrame->GetMenu(this: m_pFrame);
  if ( v4 != nullptr )
    v4 = *((HMENU__ **)v4 + 1);
  m_pMenuBar = this->m_pMenuBar;
  this->m_hDefaultMenu = v4;
  m_pMenuBar->OnDefaultMenuLoaded(this: m_pMenuBar, a2: v4);
  this->m_pMenuBar->CreateFromMenu(this: this->m_pMenuBar, a2: this->m_hDefaultMenu, a3: 1, a4: 0);
  this->m_pFrame->SetMenu(this: this->m_pFrame, a2: nullptr);
  CMFCMenuBar::SetDefaultMenuResId(this: this->m_pMenuBar, uiResId: this->m_nIDDefaultResource);
}

//------------------------------------------------------------------------------
// Address: 0x10382074
// Name: protected: int CFrameImpl::ProcessKeyboard(int,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameImpl::ProcessKeyboard(CFrameImpl *this, int nKey, int *pbProcessAccel)
{
  int v3; // ebx
  HWND Focus; // eax
  CWnd *v6; // esi
  HWND v7; // eax
  HWND__ *m_hWnd; // esi
  HWND__ *v9; // ecx
  HWND v11; // esi
  int v12; // esi
  CMFCDropDownListBox *v13; // eax
  CObList::CNode *m_pNodeHead; // edi
  CMFCToolBar *data; // esi
  CMFCToolBarButton *Button; // eax
  CFrameWnd *v17; // eax
  CMFCRibbonBar *m_pRibbonBar; // eax
  CMFCRibbonBar *v19; // ecx
  int bIsToolbarCtrlFocus; // [esp+Ch] [ebp-8h]
  unsigned __int8 fVirt; // [esp+13h] [ebp-1h]

  v3 = 0;
  if ( pbProcessAccel != nullptr )
    *pbProcessAccel = 1;
  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr && IsWindow(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8)) )
  {
    Focus = GetFocus();
    v6 = CWnd::FromHandle(hWnd: Focus);
    if ( (*(int (__thiscall **)(HWND))(*(_DWORD *)CMFCPopupMenu::m_pActivePopupMenu + 512))(a1: CMFCPopupMenu::m_pActivePopupMenu) != 0 )
    {
      if ( v6 != nullptr && v6->m_hWnd != nullptr )
      {
        if ( IsChild(hWndParent: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), hWnd: v6->m_hWnd) )
          return 0;
        v7 = CMFCPopupMenu::m_pActivePopupMenu;
        m_hWnd = v6->m_hWnd;
        v9 = CMFCPopupMenu::m_pActivePopupMenu != nullptr
           ? *((HWND__ **)CMFCPopupMenu::m_pActivePopupMenu + 8)
           : nullptr;
        if ( m_hWnd == v9 )
          return 0;
      }
      else
      {
        v7 = CMFCPopupMenu::m_pActivePopupMenu;
      }
      SendMessageA(hWnd: *((HWND *)v7 + 8), Msg: 0x10u, wParam: 0, lParam: 0);
      return 0;
    }
    if ( v6 != nullptr )
    {
      v11 = v6->m_hWnd;
      if ( v11 != nullptr && IsChild(hWndParent: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), hWnd: v11) )
        return 0;
    }
    v12 = *(_DWORD *)((*(int (__thiscall **)(HWND))(*(_DWORD *)CMFCPopupMenu::m_pActivePopupMenu + 448))(a1: CMFCPopupMenu::m_pActivePopupMenu)
                    + 3336);
    SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x100u, wParam: nKey, lParam: 0);
    if ( v12 != 0 )
    {
      v13 = (CMFCDropDownListBox *)AfxDynamicDownCast(
                                     pClass: &CMFCDropDownListBox::classCMFCDropDownListBox,
                                     pObject: (CObject *)CMFCPopupMenu::m_pActivePopupMenu);
      if ( v13 != nullptr && CMFCDropDownListBox::IsEditFocused(this: v13) )
        return 0;
    }
  }
  else if ( !IsIconic(hWnd: this->m_pFrame->m_hWnd) )
  {
    if ( CMFCToolBar::m_bCustomizeMode != 0 )
      return 0;
    m_pNodeHead = afxAllToolBars.m_pNodeHead;
    bIsToolbarCtrlFocus = 0;
    do
    {
      if ( m_pNodeHead == nullptr )
        break;
      data = (CMFCToolBar *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data == nullptr )
        AfxThrowInvalidArgException();
      if ( CWnd::FromHandlePermanent(hWnd: data->m_hWnd) != nullptr && CMFCToolBar::GetCount(this: data) > 0 )
      {
        while ( 1 )
        {
          Button = CMFCToolBar::GetButton(this: data, nIndex: v3);
          if ( Button->HasFocus(this: Button) != 0 )
            break;
          if ( ++v3 >= CMFCToolBar::GetCount(this: data) )
            goto LABEL_35;
        }
        bIsToolbarCtrlFocus = 1;
      }
LABEL_35:
      v3 = 0;
    }
    while ( bIsToolbarCtrlFocus == 0 );
    fVirt = 0;
    if ( GetAsyncKeyState(vKey: 17) < 0 )
      fVirt = 8;
    if ( GetAsyncKeyState(vKey: 18) < 0 )
      fVirt |= 0x10u;
    if ( GetAsyncKeyState(vKey: 16) < 0 )
      fVirt |= 4u;
    if ( bIsToolbarCtrlFocus != 0
      || CKeyboardManager::IsKeyHandled(nKey, fVirt: fVirt | 1, pWndFrame: this->m_pFrame, bIsDefaultFrame: 1) == 0
      && (v17 = this->m_pFrame->GetActiveFrame(this: this->m_pFrame),
          CKeyboardManager::IsKeyHandled(nKey, fVirt: fVirt | 1, pWndFrame: v17, bIsDefaultFrame: 0) == 0) )
    {
      m_pRibbonBar = this->m_pRibbonBar;
      if ( m_pRibbonBar != nullptr && IsWindowVisible(hWnd: m_pRibbonBar->m_hWnd) && fVirt == 8 )
      {
        if ( nKey == 112 )
        {
          v19 = this->m_pRibbonBar;
          if ( v19->m_pActiveCategory != nullptr )
          {
            CMFCRibbonBar::ToggleMimimizeState(this: v19);
            return 1;
          }
        }
      }
      else if ( fVirt == 16 && CFrameImpl::OnMenuChar(this, nChar: nKey) != 0 )
      {
        return 1;
      }
      if ( bIsToolbarCtrlFocus != 0 && pbProcessAccel != nullptr )
        *pbProcessAccel = 0;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10382307
// Name: protected: int CFrameImpl::ProcessMouseMove(struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameImpl::ProcessMouseMove(CFrameImpl *this, tagPOINT pt)
{
  CMFCPopupMenu *MenuWithConnectedFloaty; // eax
  CMFCPopupMenuBar *v3; // eax
  HWND m_hwndConnectedFloaty; // [esp-8h] [ebp-44h]
  CMFCPopupMenu *pMenuWithFloaty; // [esp+Ch] [ebp-30h]
  CRect rectFloaty; // [esp+18h] [ebp-24h] BYREF
  CRect rectMenu; // [esp+28h] [ebp-14h] BYREF

  if ( CMFCToolBar::m_bCustomizeMode != 0 )
    return false;
  if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr )
    return false;
  MenuWithConnectedFloaty = CMFCPopupMenu::FindMenuWithConnectedFloaty();
  pMenuWithFloaty = MenuWithConnectedFloaty;
  if ( MenuWithConnectedFloaty != nullptr && IsWindow(hWnd: MenuWithConnectedFloaty->m_hwndConnectedFloaty) )
  {
    m_hwndConnectedFloaty = pMenuWithFloaty->m_hwndConnectedFloaty;
    memset(&rectFloaty, 0, sizeof(rectFloaty));
    GetWindowRect(hWnd: m_hwndConnectedFloaty, lpRect: &rectFloaty);
    if ( PtInRect(lprc: &rectFloaty, pt) )
      return false;
  }
  memset(&rectMenu, 0, sizeof(rectMenu));
  GetWindowRect(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), lpRect: &rectMenu);
  if ( PtInRect(lprc: &rectMenu, pt) )
    return false;
  v3 = (CMFCPopupMenuBar *)(*(int (__thiscall **)(HWND))(*(_DWORD *)CMFCPopupMenu::m_pActivePopupMenu + 448))(a1: CMFCPopupMenu::m_pActivePopupMenu);
  return CMFCPopupMenuBar::FindDestintationToolBar(this: v3, point: (CPoint)pt) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103823FD
// Name: protected: int CFrameImpl::ProcessMouseWheel(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CFrameImpl::ProcessMouseWheel(CFrameImpl *this, WPARAM wParam, LPARAM lParam)
{
  HWND v4; // ecx
  HWND Focus; // eax
  CWnd *v6; // eax
  CWnd *v7; // esi
  HWND v8; // eax
  HWND__ *m_hWnd; // esi
  HWND__ *v10; // ecx
  CMFCRibbonBar *m_pRibbonBar; // eax

  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr && IsWindow(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8)) )
  {
    v4 = CMFCPopupMenu::m_pActivePopupMenu;
    if ( *((_DWORD *)CMFCPopupMenu::m_pActivePopupMenu + 956) != 0 )
    {
      SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x20Au, wParam, lParam);
      v4 = CMFCPopupMenu::m_pActivePopupMenu;
    }
    if ( (*(int (__thiscall **)(HWND))(*(_DWORD *)v4 + 512))(a1: v4) == 0 )
      return 1;
    Focus = GetFocus();
    v6 = CWnd::FromHandle(hWnd: Focus);
    v7 = v6;
    if ( v6 != nullptr && v6->m_hWnd != nullptr )
    {
      if ( IsChild(hWndParent: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), hWnd: v6->m_hWnd) )
        return 1;
      v8 = CMFCPopupMenu::m_pActivePopupMenu;
      m_hWnd = v7->m_hWnd;
      v10 = CMFCPopupMenu::m_pActivePopupMenu != nullptr ? *((HWND__ **)CMFCPopupMenu::m_pActivePopupMenu + 8) : nullptr;
      if ( m_hWnd == v10 )
        return 1;
    }
    else
    {
      v8 = CMFCPopupMenu::m_pActivePopupMenu;
    }
    SendMessageA(hWnd: *((HWND *)v8 + 8), Msg: 0x10u, wParam: 0, lParam: 0);
    return 1;
  }
  m_pRibbonBar = this->m_pRibbonBar;
  if ( m_pRibbonBar != nullptr && IsWindowVisible(hWnd: m_pRibbonBar->m_hWnd) )
    return SendMessageA(hWnd: this->m_pRibbonBar->m_hWnd, Msg: 0x20Au, wParam, lParam);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103824F0
// Name: protected: void CFrameImpl::DeactivateMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameImpl::DeactivateMenu(CFrameImpl *this)
{
  CMFCRibbonBar *m_pRibbonBar; // eax

  if ( CMFCToolBar::m_bCustomizeMode == 0 && CMFCPopupMenu::m_pActivePopupMenu != nullptr && this->m_pMenuBar != nullptr )
    this->m_pMenuBar->Deactivate(this: this->m_pMenuBar);
  m_pRibbonBar = this->m_pRibbonBar;
  if ( m_pRibbonBar != nullptr && IsWindowVisible(hWnd: m_pRibbonBar->m_hWnd) )
    CMFCRibbonBar::DeactivateKeyboardFocus(this: this->m_pRibbonBar, bSetFocus: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103939C1
// Name: protected: void CPaneFrameWnd::OnSizing(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnSizing(CPaneFrameWnd *this, unsigned int fwSide, tagRECT *pRect)
{
  int v4; // eax
  int v5; // ecx
  CWnd *v6; // eax
  CPaneFrameWnd_vtbl *v7; // eax
  int v8; // esi
  int v9; // ebx
  CMFCToolBar *v10; // ebx
  int v11; // esi
  int v12; // eax
  int top; // eax
  int bottom; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-78h]
  HWND__ *v16; // [esp-8h] [ebp-78h]
  CSize sizeBarOld; // [esp+Ch] [ebp-64h] BYREF
  CSize sizeBar; // [esp+14h] [ebp-5Ch] BYREF
  CWnd *v19; // [esp+1Ch] [ebp-54h]
  CMFCToolBar *pNextBar; // [esp+20h] [ebp-50h]
  int bParam; // [esp+24h] [ebp-4Ch] BYREF
  int bHorz; // [esp+28h] [ebp-48h]
  CRect rectOldClient; // [esp+2Ch] [ebp-44h] BYREF
  CRect rect; // [esp+3Ch] [ebp-34h] BYREF
  CRect rectBorderSize; // [esp+4Ch] [ebp-24h] BYREF
  CRect rectOldWnd; // [esp+5Ch] [ebp-14h] BYREF

  v19 = this;
  CWnd::Default(this);
  if ( this->m_bRolledUp == 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectOldWnd, 0, sizeof(rectOldWnd));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectOldWnd);
    CopyRect(lprcDst: &rect, lprcSrc: pRect);
    v16 = this->m_hWnd;
    memset(&rectOldClient, 0, sizeof(rectOldClient));
    GetClientRect(hWnd: v16, lpRect: &rectOldClient);
    if ( fwSide == 1 || fwSide == 2 )
    {
      bHorz = 1;
      v4 = rect.right - rect.left;
      v5 = rectOldWnd.right - rectOldWnd.left;
    }
    else
    {
      v4 = rect.bottom - rect.top;
      v5 = rectOldWnd.bottom - rectOldWnd.top;
      bHorz = 0;
    }
    if ( v4 != v5 )
    {
      v6 = CWnd::FromHandlePermanent(hWnd: this->m_hEmbeddedBar);
      pNextBar = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v6);
      if ( pNextBar != nullptr )
      {
        v7 = this->__vftable;
        memset(&rectBorderSize, 0, sizeof(rectBorderSize));
        v7->CalcBorderSize(this, a2: &rectBorderSize);
        v8 = rect.bottom - this->m_nCaptionHeight - rect.top - rectBorderSize.bottom - rectBorderSize.top;
        v9 = rect.right - rect.left - rectBorderSize.right - rectBorderSize.left;
        pNextBar->CalcSize(this: pNextBar, result: &sizeBarOld, a3: 0);
        if ( bHorz != 0 )
          v8 = v9;
        v10 = pNextBar;
        pNextBar->StretchPane(this: pNextBar, result: &sizeBar, a3: v8, a4: bHorz == 0);
        v11 = sizeBar.cy - sizeBarOld.cy;
        v12 = sizeBar.cx - sizeBarOld.cx;
        if ( sizeBar.cx == sizeBarOld.cx )
        {
          if ( v11 == 0 && CObject::IsKindOf(this: v10, pClass: &CMFCBaseToolBar::classCMFCBaseToolBar) != 0 )
          {
            *pRect = rectOldWnd.tagRECT;
            return;
          }
          if ( fwSide == 2 )
            pRect->right = rectOldWnd.right;
          else
            pRect->left = rectOldWnd.left;
        }
        else if ( fwSide == 2 )
        {
          pRect->right = v12 + rectOldWnd.right + pRect->left - rectOldWnd.left;
        }
        else
        {
          pRect->left = rectOldWnd.left + pRect->right - rectOldWnd.right - v12;
        }
        if ( v11 != 0 )
        {
          if ( fwSide != 6 && fwSide != 2 && fwSide != 1 )
          {
            top = rectOldWnd.top + pRect->bottom - rectOldWnd.bottom - v11;
LABEL_30:
            pRect->top = top;
LABEL_31:
            v10->RecalcLayout(this: v10);
            bParam = 0;
            SystemParametersInfoA(uiAction: 0x26u, uiParam: 0, pvParam: &bParam, fWinIni: 0);
            if ( bParam == 0 && CObject::IsKindOf(this: v10, pClass: &CMFCBaseToolBar::classCMFCBaseToolBar) != 0 )
              CWnd::SetWindowPos(
                this: v19,
                pWndInsertAfter: nullptr,
                x: pRect->left,
                y: pRect->top,
                cx: pRect->right - pRect->left,
                cy: pRect->bottom - pRect->top,
                nFlags: 0x14u);
            return;
          }
          bottom = v11 + rectOldWnd.bottom + pRect->top - rectOldWnd.top;
        }
        else
        {
          if ( fwSide != 6 )
          {
            top = rectOldWnd.top;
            goto LABEL_30;
          }
          bottom = rectOldWnd.bottom;
        }
        pRect->bottom = bottom;
        goto LABEL_31;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10393C08
// Name: public: virtual void CPaneFrameWnd::SizeToContent(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::SizeToContent(CPaneFrameWnd *this)
{
  CWnd *v2; // eax
  CObject *v3; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-3Ch]
  HWND__ *v5; // [esp-8h] [ebp-3Ch]
  CSize sizeBar; // [esp+8h] [ebp-2Ch] BYREF
  CRect rectClient; // [esp+10h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+20h] [ebp-14h] BYREF

  v2 = CWnd::FromHandlePermanent(hWnd: this->m_hEmbeddedBar);
  v3 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v2);
  if ( v3 != nullptr )
  {
    ((void (__thiscall *)(CObject *, CSize *, _DWORD, int))v3->__vftable[50].dtr_CObject)(
      a1: v3,
      a2: &sizeBar,
      a3: 0,
      a4: 1);
    m_hWnd = this->m_hWnd;
    memset(&rectWnd, 0, sizeof(rectWnd));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
    v5 = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: v5, lpRect: &rectClient);
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: nullptr,
      x: 0,
      y: 0,
      cx: sizeBar.cx + rectClient.left + rectWnd.right - rectClient.right - rectWnd.left,
      cy: sizeBar.cy + rectWnd.bottom + rectClient.top - rectClient.bottom - rectWnd.top,
      nFlags: 0x16u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10393CB9
// Name: public: virtual void CPaneFrameWnd::OnPaneRecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnPaneRecalcLayout(CPaneFrameWnd *this)
{
  CPaneFrameWnd *v1; // ebx
  CWnd *v2; // eax
  CObject *v3; // eax
  HWND *v4; // esi
  CObject_vtbl *v5; // eax
  int right; // ecx
  int bottom; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  CSize size; // [esp+Ch] [ebp-24h] BYREF
  CPaneFrameWnd *v10; // [esp+14h] [ebp-1Ch]
  int bSizeChanged; // [esp+18h] [ebp-18h]
  CRect rect; // [esp+1Ch] [ebp-14h] BYREF

  v1 = this;
  m_hWnd = this->m_hWnd;
  v10 = this;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  v2 = CWnd::FromHandlePermanent(hWnd: v1->m_hEmbeddedBar);
  v3 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v2);
  v4 = (HWND *)v3;
  bSizeChanged = 0;
  if ( v3 != nullptr )
  {
    if ( CPane::m_bHandleMinSize != 0 )
    {
      v5 = v3->__vftable;
      size.cx = 0;
      size.cy = 0;
      v5[51].Serialize(this: (CObject *)v4, a2: (CArchive *)&size);
      right = rect.right;
      if ( rect.right - rect.left < size.cx )
      {
        right = rect.left + size.cx;
        rect.right = rect.left + size.cx;
        bSizeChanged = 1;
      }
      bottom = rect.bottom;
      v1 = v10;
      if ( rect.bottom - rect.top < size.cy )
      {
        bottom = size.cy + rect.top;
        rect.bottom = size.cy + rect.top;
        bSizeChanged = 1;
      }
    }
    else
    {
      bottom = rect.bottom;
      right = rect.right;
    }
    (*((void (__thiscall **)(HWND *, _DWORD, int, int, int, int, int, _DWORD))*v4 + 141))(
      a1: v4,
      a2: 0,
      a3: rect.left,
      a4: rect.top,
      a5: right - rect.left,
      a6: bottom - rect.top,
      a7: 52,
      a8: 0);
    RedrawWindow(hWnd: v4[8], lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    if ( bSizeChanged != 0 )
      v1->SizeToContent(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10393DC0
// Name: public: virtual int CPaneFrameWnd::SetPreDockState(enum AFX_PREDOCK_STATE,class CBasePane __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneFrameWnd::SetPreDockState(
        CPaneFrameWnd *this,
        AFX_PREDOCK_STATE preDockState,
        CBasePane *pBarToDock,
        AFX_DOCK_METHOD __formal)
{
  bool m_bCaptured; // al
  CPaneFrameWnd_vtbl *v6; // eax
  CWnd *v7; // eax
  CPaneFrameWnd_vtbl *v8; // eax
  int v9; // eax
  int v10; // esi
  CPoint ptClientBar; // [esp+Ch] [ebp-18h] BYREF
  CPoint ptScreen; // [esp+14h] [ebp-10h] BYREF
  int bWasCaptured; // [esp+1Ch] [ebp-8h]
  int bWasDocked; // [esp+20h] [ebp-4h] BYREF

  if ( preDockState == PDS_NOTHING )
    return 1;
  if ( preDockState != PDS_DOCK_TO_TAB )
  {
LABEL_5:
    if ( pBarToDock == nullptr || pBarToDock->GetParentMiniFrame(this: pBarToDock, a2: 0) == nullptr )
      goto LABEL_7;
    return 1;
  }
  if ( pBarToDock != nullptr )
  {
    if ( pBarToDock->CanBeAttached(this: pBarToDock) == 0 )
      return 1;
    goto LABEL_5;
  }
LABEL_7:
  m_bCaptured = this->m_bCaptured;
  bWasCaptured = m_bCaptured;
  if ( m_bCaptured )
  {
    ReleaseCapture();
    v6 = this->__vftable;
    this->m_bCaptured = false;
    v6->OnCapture(this, a2: 0);
  }
  ptScreen.x = 0;
  ptScreen.y = 0;
  GetCursorPos(lpPoint: &ptScreen);
  ptClientBar = ptScreen;
  v7 = this->GetPane(this);
  ScreenToClient(hWnd: v7->m_hWnd, lpPoint: &ptClientBar);
  this->m_preDockStateCurr = preDockState;
  this->m_pPreDockBar = (CDockablePane *)AfxDynamicDownCast(
                                           pClass: &CDockablePane::classCDockablePane,
                                           pObject: pBarToDock);
  v8 = this->__vftable;
  bWasDocked = 0;
  v9 = (int)v8->DockPane(this, a2: &bWasDocked);
  v10 = v9;
  if ( v9 != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 612))(a1: v9, a2: 0);
    if ( bWasCaptured != 0 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 788))(a1: v10, a2: 0);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10393EC6
// Name: public: virtual void CPaneFrameWnd::OnMovePane(class CPane __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnMovePane(CPaneFrameWnd *this, CPane *__formal, CPoint ptOffset)
{
  CRect rectMiniFrame; // [esp+4h] [ebp-14h] BYREF

  memset(&rectMiniFrame, 0, sizeof(rectMiniFrame));
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectMiniFrame);
  OffsetRect(lprc: &rectMiniFrame, dx: ptOffset.x, dy: ptOffset.y);
  CWnd::MoveWindow(
    this,
    x: rectMiniFrame.left,
    y: rectMiniFrame.top,
    nWidth: rectMiniFrame.right - rectMiniFrame.left,
    nHeight: rectMiniFrame.bottom - rectMiniFrame.top,
    bRepaint: true);
}

//------------------------------------------------------------------------------
// Address: 0x10393F32
// Name: protected: void CPaneFrameWnd::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnWindowPosChanging(CPaneFrameWnd *this, tagWINDOWPOS *lpwndpos)
{
  bool v3; // zf
  int y; // eax
  int x; // ecx
  HWND__ *m_hWnd; // [esp-Ch] [ebp-48h]
  CRect rectDelta; // [esp+8h] [ebp-34h] BYREF
  CRect rectWnd; // [esp+18h] [ebp-24h] BYREF
  CRect rect; // [esp+28h] [ebp-14h] BYREF

  lpwndpos->flags |= 0x10u;
  if ( (lpwndpos->flags & 2) == 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectWnd, 0, sizeof(rectWnd));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
    v3 = (lpwndpos->flags & 1) == 0;
    y = lpwndpos->y;
    x = lpwndpos->x;
    memset(&rect, 0, sizeof(rect));
    if ( v3 )
      SetRect(lprc: &rect, xLeft: x, yTop: y, xRight: x + lpwndpos->cx, yBottom: y + lpwndpos->cy);
    else
      SetRect(
        lprc: &rect,
        xLeft: x,
        yTop: y,
        xRight: rectWnd.right + x - rectWnd.left,
        yBottom: rectWnd.bottom + y - rectWnd.top);
    rectDelta.left = this->GetCaptionHeight(this);
    rectDelta.top = rectDelta.left;
    rectDelta.right = rectDelta.left;
    rectDelta.bottom = rectDelta.left;
    CGlobalUtils::AdjustRectToWorkArea(this: &afxGlobalUtils, &rect, pRectDelta: &rectDelta);
    lpwndpos->x = rect.left;
    lpwndpos->y = rect.top;
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10394004
// Name: protected: void CPaneFrameWnd::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnTimer(CPaneFrameWnd *this, unsigned int nIDEvent)
{
  CDockingManager *m_pDockManager; // eax
  CWnd *v4; // eax

  if ( nIDEvent == 4 )
  {
    m_pDockManager = this->m_pDockManager;
    if ( m_pDockManager == nullptr )
    {
      v4 = CWnd::FromHandlePermanent(hWnd: this->m_hParentWnd);
      m_pDockManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v4);
    }
    m_pDockManager->OnMoveMiniFrame(this: m_pDockManager, a2: this);
  }
  else
  {
    if ( nIDEvent == 5 )
      this->OnCheckRollState(this);
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10394055
// Name: protected: int CPaneFrameWnd::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneFrameWnd::OnNcActivate(CPaneFrameWnd *this, int bActive)
{
  HWND Focus; // eax
  int v4; // eax
  CWnd *v5; // eax

  if ( (CWnd::GetStyle(this) & 0x100) == 0 )
  {
    Focus = GetFocus();
    v4 = this == CWnd::FromHandle(hWnd: Focus);
    if ( this->m_bActive != v4 )
    {
      this->m_bActive = v4;
      if ( this->m_pDockManager != nullptr
        || (v5 = CWnd::FromHandlePermanent(hWnd: this->m_hParentWnd),
            CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v5) != nullptr) )
      {
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
      }
    }
  }
  else if ( (this->m_nFlags & 0x200) != 0 )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039CCC7
// Name: protected: void CMFCPropertyGridCtrl::OnChar(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnChar(
        CMFCPropertyGridCtrl *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMFCPropertyGridProperty *m_pSel; // eax

  CWnd::Default(this);
  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr && m_pSel->m_bEnabled != 0 && this->EditItem(this, a2: m_pSel, a3: nullptr) != 0 )
    this->m_pSel->PushChar(this: this->m_pSel, a2: nChar);
}

//------------------------------------------------------------------------------
// Address: 0x1039CD08
// Name: protected: struct HBRUSH__ __near * CMFCPropertyGridCtrl::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CMFCPropertyGridCtrl::OnCtlColor(
        CMFCPropertyGridCtrl *this,
        CDC *pDC,
        CWnd *pWnd,
        unsigned int nCtlColor)
{
  HWND__ *m_hWnd; // edi
  HBRUSH__ *v6; // ebx
  CMFCPropertyGridProperty *m_pSel; // eax
  CWnd *m_pWndInPlace; // eax
  HBRUSH__ *result; // eax

  m_hWnd = (HWND__ *)pWnd;
  v6 = CWnd::OnCtlColor(this, __formal: pDC, pWnd, __formal: nCtlColor);
  m_pSel = this->m_pSel;
  if ( m_pSel == nullptr )
    return v6;
  if ( pWnd != nullptr )
    m_hWnd = pWnd->m_hWnd;
  m_pWndInPlace = m_pSel->m_pWndInPlace;
  if ( m_pWndInPlace != nullptr )
    m_pWndInPlace = (CWnd *)m_pWndInPlace->m_hWnd;
  if ( m_hWnd != (HWND__ *)m_pWndInPlace )
    return v6;
  result = this->m_pSel->OnCtlColor(this: this->m_pSel, a2: pDC, a3: nCtlColor);
  if ( result == nullptr )
    return v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039CD66
// Name: public: virtual void CMFCPropertyGridCtrl::CloseColorPopup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::CloseColorPopup(CMFCPropertyGridCtrl *this)
{
  CObject *v1; // eax
  CObject *v2; // esi
  CWnd *v3; // ecx

  v1 = AfxDynamicDownCast(
         pClass: &CMFCPropertyGridColorProperty::classCMFCPropertyGridColorProperty,
         pObject: this->m_pSel);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v1[62].__vftable = nullptr;
    v1[19].__vftable = nullptr;
    CMFCPropertyGridProperty::Redraw(this: (CMFCPropertyGridProperty *)v1);
    v3 = (CWnd *)v2[45].__vftable;
    if ( v3 != nullptr )
      CWnd::SetFocus(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039CDA5
// Name: protected: void CMFCPropertyGridCtrl::OnEditKillFocus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnEditKillFocus(CMFCPropertyGridCtrl *this)
{
  CMFCPropertyGridProperty *m_pSel; // eax
  HWND Focus; // eax
  HWND v4; // eax
  HWND v5; // eax
  CWnd *v6; // eax

  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr && m_pSel->m_bInPlaceEdit != 0 && m_pSel->m_bEnabled != 0 )
  {
    Focus = GetFocus();
    v4 = (HWND)CWnd::FromHandle(hWnd: Focus);
    if ( v4 != nullptr )
      v4 = *((HWND *)v4 + 8);
    if ( !IsChild(hWndParent: this->m_hWnd, hWnd: v4) && this->m_pSel->OnEditKillFocus(this: this->m_pSel) != 0 )
    {
      if ( this->EndEditItem(this, a2: 1) != 0 )
      {
        v5 = GetFocus();
        v6 = CWnd::FromHandle(hWnd: v5);
        CMFCPropertyGridCtrl::OnKillFocus(this, pNewWnd: v6);
      }
      else
      {
        CWnd::SetFocus(this: this->m_pSel->m_pWndInPlace);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039CE2C
// Name: protected: void CMFCPropertyGridCtrl::OnComboKillFocus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnComboKillFocus(CMFCPropertyGridCtrl *this)
{
  CMFCPropertyGridProperty *m_pSel; // eax
  HWND Focus; // eax
  HWND v4; // eax
  HWND v5; // eax
  CWnd *v6; // eax

  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr && m_pSel->m_pWndCombo != nullptr && m_pSel->m_bEnabled != 0 )
  {
    Focus = GetFocus();
    v4 = (HWND)CWnd::FromHandle(hWnd: Focus);
    if ( v4 != nullptr )
      v4 = *((HWND *)v4 + 8);
    if ( !IsChild(hWndParent: this->m_hWnd, hWnd: v4) )
    {
      if ( this->EndEditItem(this, a2: 1) != 0 )
      {
        v5 = GetFocus();
        v6 = CWnd::FromHandle(hWnd: v5);
        CMFCPropertyGridCtrl::OnKillFocus(this, pNewWnd: v6);
      }
      else
      {
        CWnd::SetFocus(this: this->m_pSel->m_pWndCombo);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039CEA4
// Name: public: void CMFCPropertyGridCtrl::SetDescriptionRows(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::SetDescriptionRows(CMFCPropertyGridCtrl *this, int nDescRows)
{
  this->m_nDescrRows = nDescRows;
  if ( this->m_hWnd != nullptr )
  {
    this->AdjustLayout(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039CEDB
// Name: public: void CMFCPropertyGridCtrl::SetVSDotNetLook(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::SetVSDotNetLook(CMFCPropertyGridCtrl *this, int bSet)
{
  HWND__ *m_hWnd; // ecx

  this->m_bVSDotNetLook = bSet;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1039CF04
// Name: protected: void CMFCPropertyGridCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnMouseMove(CMFCPropertyGridCtrl *this, unsigned int nFlags, CPoint point)
{
  CWnd::Default(this);
  if ( this->m_bTracking != 0 )
  {
    CMFCPropertyGridCtrl::TrackHeader(this, nOffset: point.x);
  }
  else if ( this->m_bTrackingDescr != 0 )
  {
    CMFCPropertyGridCtrl::TrackDescr(this, nOffset: point.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039CF3E
// Name: protected: void CMFCPropertyGridCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnLButtonUp(CMFCPropertyGridCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // edi
  int v5; // edi
  int x; // edi
  int v7; // edi
  CMFCPropertyGridCtrl_vtbl *v8; // eax
  int v9; // eax
  CMFCHeaderCtrl *v10; // eax
  HWND__ *v11; // edi
  int v12; // eax
  int v13; // edx
  HWND__ *v14; // [esp-8h] [ebp-5Ch]
  HWND__ *v15; // [esp-8h] [ebp-5Ch]
  _HD_ITEMA hdItem; // [esp+Ch] [ebp-48h] BYREF
  int m_nRowHeight; // [esp+3Ch] [ebp-18h]
  CRect rectClient; // [esp+40h] [ebp-14h] BYREF

  CWnd::Default(this);
  if ( this->m_bTracking != 0 )
  {
    CMFCPropertyGridCtrl::TrackHeader(this, nOffset: -1);
    m_hWnd = this->m_hWnd;
    this->m_bTracking = 0;
    if ( GetCapture() == m_hWnd )
      ReleaseCapture();
    v14 = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: v14, lpRect: &rectClient);
    m_nRowHeight = this->m_nRowHeight;
    if ( m_nRowHeight <= point.x )
      m_nRowHeight = point.x;
    v5 = rectClient.right - rectClient.left;
    if ( m_nRowHeight >= v5 - GetSystemMetrics(nIndex: 21) - 5 )
    {
      v7 = rectClient.right - rectClient.left;
      x = v7 - GetSystemMetrics(nIndex: 21) - 5;
    }
    else
    {
      x = this->m_nRowHeight;
      if ( x <= point.x )
        x = point.x;
    }
    v8 = this->__vftable;
    this->m_nLeftColumnWidth = x;
    hdItem.mask = 1;
    hdItem.cxy = x + 2;
    v9 = (int)v8->GetHeaderCtrl(this);
    SendMessageA(hWnd: *(HWND *)(v9 + 32), Msg: 0x1204u, wParam: 0, lParam: (LPARAM)&hdItem);
    hdItem.cxy = rectClient.right - rectClient.left + 10;
    v10 = this->GetHeaderCtrl(this);
    SendMessageA(hWnd: v10->m_hWnd, Msg: 0x1204u, wParam: 1u, lParam: (LPARAM)&hdItem);
  }
  if ( this->m_bTrackingDescr != 0 )
  {
    CMFCPropertyGridCtrl::TrackDescr(this, nOffset: 0x80000000);
    v11 = this->m_hWnd;
    this->m_bTrackingDescr = 0;
    if ( GetCapture() == v11 )
      ReleaseCapture();
    v15 = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: v15, lpRect: &rectClient);
    v12 = this->m_nRowHeight;
    if ( point.y <= v12 + this->m_nHeaderHeight )
      point.y = v12 + this->m_nHeaderHeight;
    v13 = rectClient.bottom - rectClient.top - point.y + 2;
    this->m_nDescrHeight = v13;
    if ( v12 <= v13 )
      v12 = v13;
    this->m_nDescrHeight = v12;
    this->AdjustLayout(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D0F0
// Name: protected: void CMFCPropertyGridCtrl::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnNcCalcSize(
        CMFCPropertyGridCtrl *this,
        int bCalcValidRects,
        tagNCCALCSIZE_PARAMS *lpncsp)
{
  CWnd::Default(this);
  if ( (CWnd::GetStyle(this) & 0x800000) != 0 )
  {
    ++lpncsp->rgrc[0].left;
    ++lpncsp->rgrc[0].top;
    --lpncsp->rgrc[0].right;
    --lpncsp->rgrc[0].bottom;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D11E
// Name: protected: virtual int CMFCPropertyGridCtrl::ProcessClipboardAccelerators(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::ProcessClipboardAccelerators(CMFCPropertyGridCtrl *this, unsigned int nChar)
{
  CMFCPropertyGridProperty *m_pSel; // eax
  CWnd *m_pWndInPlace; // eax
  int v4; // ebx
  int v5; // eax

  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr )
  {
    m_pWndInPlace = m_pSel->m_pWndInPlace;
    if ( m_pWndInPlace != nullptr && m_pWndInPlace->m_hWnd != nullptr )
    {
      v4 = GetAsyncKeyState(vKey: 17) & 0x8000;
      v5 = GetAsyncKeyState(vKey: 16) & 0x8000;
      if ( v4 != 0 )
      {
        if ( nChar == 67 || nChar == 45 )
        {
          SendMessageA(hWnd: this->m_pSel->m_pWndInPlace->m_hWnd, Msg: 0x301u, wParam: 0, lParam: 0);
          return 1;
        }
        if ( nChar == 86 )
          goto LABEL_12;
      }
      if ( v5 != 0 && nChar == 45 )
      {
LABEL_12:
        SendMessageA(hWnd: this->m_pSel->m_pWndInPlace->m_hWnd, Msg: 0x302u, wParam: 0, lParam: 0);
        return 1;
      }
      if ( v4 != 0 && nChar == 88 || v5 != 0 && nChar == 46 )
      {
        SendMessageA(hWnd: this->m_pSel->m_pWndInPlace->m_hWnd, Msg: 0x300u, wParam: 0, lParam: 0);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039D1DC
// Name: protected: virtual void CMFCPropertyGridCtrl::NotifyAccessibility(class CMFCPropertyGridProperty __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::NotifyAccessibility(CMFCPropertyGridCtrl *this, CMFCPropertyGridProperty *pProp)
{
  int left; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-14h]
  CPoint pt; // [esp+4h] [ebp-8h] BYREF

  if ( afxGlobalData.m_bEnableAccessibility != 0 && pProp != nullptr )
  {
    this->m_pAccProp = pProp;
    left = pProp->m_Rect.left;
    pt.y = pProp->m_Rect.top;
    m_hWnd = this->m_hWnd;
    pt.x = left;
    ClientToScreen(hWnd: m_hWnd, lpPoint: &pt);
    NotifyWinEvent(event: 0x8005u, hwnd: this->m_hWnd, idObject: -4, idChild: LOWORD(pt.x) | (LOWORD(pt.y) << 16));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D239
// Name: public: void CMFCPropertyGridCtrl::MarkModifiedProperties(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::MarkModifiedProperties(CMFCPropertyGridCtrl *this, int bMark, int bRedraw)
{
  HWND__ *m_hWnd; // ecx

  this->m_bMarkModifiedProperties = bMark;
  if ( bRedraw != 0 )
  {
    m_hWnd = this->m_hWnd;
    if ( m_hWnd != nullptr )
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D267
// Name: public: virtual long CMFCPropertyGridCtrl::accLocation(long __near *,long __near *,long __near *,long __near *,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::accLocation(
        CMFCPropertyGridCtrl *this,
        int *pxLeft,
        int *pyTop,
        int *pcxWidth,
        int *pcyHeight,
        tagVARIANT varChild)
{
  int left; // eax
  int right; // edx
  int top; // ecx
  __int64 v9; // kr00_8
  CMFCPropertyGridProperty *m_pAccProp; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-34h]
  CRect rcProp; // [esp+18h] [ebp-14h] BYREF

  if ( pxLeft != nullptr && pyTop != nullptr && pcxWidth != nullptr && pcyHeight != nullptr )
  {
    if ( varChild.vt != 3 || varChild.decVal.Lo32 != 0 )
    {
      m_pAccProp = this->m_pAccProp;
      if ( m_pAccProp == nullptr )
        return 0;
      rcProp = m_pAccProp->m_Rect;
      CWnd::ClientToScreen(this, lpRect: &rcProp);
      v9 = *(_QWORD *)&rcProp.left;
      *pxLeft = rcProp.left;
      *pyTop = HIDWORD(v9);
      *pcxWidth = rcProp.right - v9;
    }
    else
    {
      m_hWnd = this->m_hWnd;
      memset(&rcProp, 0, sizeof(rcProp));
      GetWindowRect(hWnd: m_hWnd, lpRect: &rcProp);
      left = rcProp.left;
      right = rcProp.right;
      top = rcProp.top;
      *pxLeft = rcProp.left;
      *pyTop = top;
      *pcxWidth = right - left;
      HIDWORD(v9) = top;
    }
    *pcyHeight = rcProp.bottom - HIDWORD(v9);
    return 0;
  }
  return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x1039D33B
// Name: public: virtual long CMFCPropertyGridCtrl::accHitTest(long,long,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::accHitTest(
        CMFCPropertyGridCtrl *this,
        unsigned int xLeft,
        unsigned int yTop,
        tagVARIANT *pvarChild)
{
  CMFCPropertyGridProperty *v6; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-1Ch]
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  if ( pvarChild == nullptr )
    return -2147024809;
  m_hWnd = this->m_hWnd;
  pt = (CPoint)__PAIR64__(yTop, xLeft);
  ScreenToClient(hWnd: m_hWnd, lpPoint: &pt);
  v6 = CMFCPropertyGridCtrl::HitTest(this, pt, pnArea: nullptr, bPropsOnly: 0);
  pvarChild->vt = 3;
  if ( v6 != nullptr )
    pvarChild->decVal.Lo32 = (unsigned __int16)xLeft | ((unsigned __int16)yTop << 16);
  else
    pvarChild->decVal.Lo32 = 0;
  this->m_pAccProp = v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039D3AD
// Name: protected: virtual void CMFCPropertyGridCtrl::Init(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::Init(CMFCPropertyGridCtrl *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v3; // eax
  CMFCPropertyGridCtrl_vtbl *v4; // eax
  int v5; // eax
  CMFCPropertyGridCtrl_vtbl *v6; // eax
  int v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  BOOL v10; // eax
  _HD_ITEMA hdItem; // [esp+Ch] [ebp-44h] BYREF
  CRect rectDummy; // [esp+3Ch] [ebp-14h] BYREF

  memset(&rectDummy, 0, sizeof(rectDummy));
  SetRectEmpty(lprc: &rectDummy);
  if ( afxGlobalData.m_hcurStretch == nullptr )
  {
    AfxGetModuleState();
    ModuleState = AfxGetModuleState();
    afxGlobalData.m_hcurStretch = LoadCursorW(
                                    hInstance: ModuleState->m_hCurrentResourceHandle,
                                    lpCursorName: (LPCWSTR)0x7904);
  }
  if ( afxGlobalData.m_hcurStretchVert == nullptr )
  {
    AfxGetModuleState();
    v3 = AfxGetModuleState();
    afxGlobalData.m_hcurStretchVert = LoadCursorW(
                                        hInstance: v3->m_hCurrentResourceHandle,
                                        lpCursorName: (LPCWSTR)0x7905);
  }
  this->InitHeader(this);
  v4 = this->__vftable;
  hdItem.mask = 6;
  hdItem.fmt = 0;
  hdItem.pszText = "Property";
  hdItem.cchTextMax = 100;
  v5 = (int)v4->GetHeaderCtrl(this);
  SendMessageA(hWnd: *(HWND *)(v5 + 32), Msg: 0x1201u, wParam: 0, lParam: (LPARAM)&hdItem);
  v6 = this->__vftable;
  hdItem.pszText = "Value";
  hdItem.cchTextMax = 100;
  v7 = (int)v6->GetHeaderCtrl(this);
  SendMessageA(hWnd: *(HWND *)(v7 + 32), Msg: 0x1201u, wParam: 1u, lParam: (LPARAM)&hdItem);
  this->m_wndScrollVert.Create(this: &this->m_wndScrollVert, a2: 1342177281u, a3: &rectDummy, a4: this, a5: 2u);
  this->m_ToolTip.Create_2(this: &this->m_ToolTip, a2: this, a3: 1u);
  SendMessageA(hWnd: this->m_ToolTip.m_hWnd, Msg: 0x401u, wParam: 1u, lParam: 0);
  if ( afxGlobalData.m_nMaxToolTipWidth != -1 )
    SendMessageA(hWnd: this->m_ToolTip.m_hWnd, Msg: 0x418u, wParam: 0, lParam: afxGlobalData.m_nMaxToolTipWidth);
  CWnd::SetWindowPos(
    this: &this->m_ToolTip,
    pWndInsertAfter: &CWnd::wndTop,
    x: -1,
    y: -1,
    cx: -1,
    cy: -1,
    nFlags: 0x13u);
  ((void (__stdcall *)(CMFCPropertyGridCtrl *))this->m_IPToolTip.Create_2)(a1: this);
  Parent = GetParent(hWnd: this->m_hWnd);
  v9 = CWnd::FromHandle(hWnd: Parent);
  v10 = v9 == nullptr || CObject::IsKindOf(this: v9, pClass: &CDialog::classCDialog) == 0;
  this->m_bControlBarColors = v10;
  this->AdjustLayout(this);
  CMFCPropertyGridCtrl::CreateBoldFont(this);
  CMFCPropertyGridCtrl::CalcEditMargin(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039D55C
// Name: protected: long CMFCPropertyGridCtrl::OnSetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnSetFont(CMFCPropertyGridCtrl *this, HFONT__ *wParam, int __formal)
{
  this->m_hFont = wParam;
  CMFCPropertyGridCtrl::CreateBoldFont(this);
  CMFCPropertyGridCtrl::CalcEditMargin(this);
  this->AdjustLayout(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039D58A
// Name: public: virtual void CMFCPropertyGridCtrl::OnPropertyChanged(class CMFCPropertyGridProperty __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnPropertyChanged(CMFCPropertyGridCtrl *this, CMFCPropertyGridProperty *pProp)
{
  int DlgCtrlID; // eax
  UINT v4; // esi
  WPARAM v5; // ebx
  CWnd *Owner; // eax

  CMFCPropertyGridProperty::SetModifiedFlag(this: pProp);
  DlgCtrlID = CWnd::GetDlgCtrlID(this);
  v4 = AFX_WM_PROPERTY_CHANGED;
  v5 = DlgCtrlID;
  Owner = CWnd::GetOwner(this);
  SendMessageA(hWnd: Owner->m_hWnd, Msg: v4, wParam: v5, lParam: (LPARAM)pProp);
}

//------------------------------------------------------------------------------
// Address: 0x1039D5C7
// Name: protected: void CMFCPropertyGridCtrl::OnHeaderTrack(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnHeaderTrack(CMFCPropertyGridCtrl *this, tagNMHDR *pNMHDR, int *pResult)
{
  int v3; // eax

  if ( pNMHDR == nullptr )
    AfxThrowInvalidArgException();
  v3 = this->m_rectList.right - this->m_rectList.left;
  if ( *(_DWORD *)(pNMHDR[1].code + 4) < v3 )
    v3 = *(_DWORD *)(pNMHDR[1].code + 4);
  *(_DWORD *)(pNMHDR[1].code + 4) = v3;
  CMFCPropertyGridCtrl::TrackHeader(this, nOffset: *(_DWORD *)(pNMHDR[1].code + 4));
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039D60D
// Name: protected: void CMFCPropertyGridCtrl::OnHeaderEndTrack(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnHeaderEndTrack(CMFCPropertyGridCtrl *this, tagNMHDR *__formal, int *pResult)
{
  CMFCPropertyGridCtrl::TrackHeader(this, nOffset: -1);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039D623
// Name: protected: void CMFCPropertyGridCtrl::SetScrollSizes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::SetScrollSizes(CMFCPropertyGridCtrl *this)
{
  UINT v2; // edi
  int m_nRowHeight; // ecx
  int TotalItems; // eax
  int m_nVertScrollOffset; // eax
  CScrollBar *p_m_wndScrollVert; // [esp+8h] [ebp-24h]
  tagSCROLLINFO ScrollInfo; // [esp+Ch] [ebp-20h] BYREF

  v2 = 0;
  p_m_wndScrollVert = &this->m_wndScrollVert;
  if ( this != (CMFCPropertyGridCtrl *)-580 && this->m_wndScrollVert.m_hWnd != nullptr )
  {
    m_nRowHeight = this->m_nRowHeight;
    if ( m_nRowHeight != 0 )
    {
      this->m_nVertScrollPage = (this->m_rectList.bottom - this->m_rectList.top) / m_nRowHeight - 1;
      TotalItems = CMFCPropertyGridCtrl::GetTotalItems(this, bIncludeHidden: 0);
      this->m_nVertScrollTotal = TotalItems;
      if ( TotalItems <= this->m_nVertScrollPage )
      {
        this->m_nVertScrollPage = 0;
        this->m_nVertScrollTotal = 0;
      }
      m_nVertScrollOffset = this->m_nVertScrollOffset;
      if ( m_nVertScrollOffset >= this->m_nVertScrollTotal )
        m_nVertScrollOffset = this->m_nVertScrollTotal;
      this->m_nVertScrollOffset = m_nVertScrollOffset;
    }
    else
    {
      this->m_nVertScrollPage = 0;
      this->m_nVertScrollTotal = 0;
      this->m_nVertScrollOffset = 0;
    }
    memset(dst: (unsigned __int8 *)&ScrollInfo, value: 0, count: sizeof(ScrollInfo));
    ScrollInfo.nMax = this->m_nVertScrollTotal;
    ScrollInfo.nPage = this->m_nVertScrollPage;
    ScrollInfo.nPos = this->m_nVertScrollOffset;
    ScrollInfo.cbSize = 28;
    ScrollInfo.fMask = 7;
    ScrollInfo.nMin = 0;
    CWnd::SetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, bRedraw: 1);
    if ( this->m_nVertScrollTotal <= 0 )
      v2 = 3;
    EnableScrollBar(hWnd: this->m_wndScrollVert.m_hWnd, wSBflags: 2u, wArrows: v2);
    CWnd::EnableWindow(this: p_m_wndScrollVert, bEnable: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D73F
// Name: protected: void CMFCPropertyGridCtrl::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnDestroy(CMFCPropertyGridCtrl *this)
{
  CMFCPropertyGridProperty *v2; // eax

  while ( this->m_lstProps.m_nCount != 0 )
  {
    v2 = CList<CPropertyPage *,CPropertyPage *>::RemoveHead(this: &this->m_lstProps);
    if ( v2 != nullptr )
      ((void (__thiscall *)(CMFCPropertyGridProperty *, int))v2->dtr_CObject)(a1: v2, a2: 1);
  }
  this->m_pSel = nullptr;
  this->m_IPToolTip.DestroyWindow(this: &this->m_IPToolTip);
  this->m_ToolTip.DestroyWindow(this: &this->m_ToolTip);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039D792
// Name: protected: virtual int CMFCPropertyGridCtrl::CompareProps(class CMFCPropertyGridProperty const __near *,class CMFCPropertyGridProperty const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::CompareProps(
        CMFCPropertyGridCtrl *this,
        const CMFCPropertyGridProperty *pProp1,
        const CMFCPropertyGridProperty *pProp2)
{
  return ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: &pProp1->m_strName,
           psz: pProp2->m_strName.m_pszData);
}

//------------------------------------------------------------------------------
// Address: 0x1039D7B2
// Name: protected: void CMFCPropertyGridProperty::AddTerminalProp(class CList<class CMFCPropertyGridProperty __near *,class CMFCPropertyGridProperty __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridProperty::AddTerminalProp(
        CMFCPropertyGridProperty *this,
        CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *lstProps)
{
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v3; // edi
  CMFCPropertyGridProperty *v4; // ecx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // esi
  const CMFCPropertyGridProperty *data; // eax
  __POSITION *v7; // ebx
  int bInserted; // [esp+8h] [ebp-4h]

  if ( this->m_bGroup == 0 || this->m_bIsValueList != 0 )
  {
    bInserted = 0;
    m_pNodeHead = lstProps->m_pNodeHead;
    do
    {
      if ( m_pNodeHead == nullptr )
        break;
      data = m_pNodeHead->data;
      v7 = (__POSITION *)m_pNodeHead;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( this->m_pWndList->CompareProps(this: this->m_pWndList, a2: data, a3: this) > 0 )
      {
        CList<unsigned long,unsigned long>::InsertBefore(this: lstProps, position: v7, newElement: this);
        bInserted = 1;
      }
    }
    while ( bInserted == 0 );
    if ( bInserted == 0 )
      CList<CFrameWnd *,CFrameWnd *>::AddTail(
        this: (CList<CFrameWnd *,CFrameWnd *> *)lstProps,
        newElement: (CFrameWnd *)this);
  }
  else
  {
    SetRectEmpty(lprc: &this->m_Rect);
    v3 = this->m_lstSubItems.m_pNodeHead;
    while ( v3 != nullptr )
    {
      v4 = v3->data;
      v3 = v3->pNext;
      CMFCPropertyGridProperty::AddTerminalProp(this: v4, lstProps);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D843
// Name: public: void CMFCPropertyGridColorProperty::SetColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridColorProperty::SetColor(CMFCPropertyGridColorProperty *this, unsigned int color)
{
  CMFCPropertyGridCtrl *m_pWndList; // eax
  CWnd *m_pWndInPlace; // ecx
  char *m_pszData; // [esp-4h] [ebp-38h]
  int v6; // [esp+10h] [ebp-24h] BYREF
  tagRECT rc; // [esp+14h] [ebp-20h] BYREF
  int v8; // [esp+30h] [ebp-4h]

  this->m_Color = color;
  COleVariant::operator=(this: &this->m_varValue, lSrc: color);
  m_pWndList = this->m_pWndList;
  if ( m_pWndList != nullptr )
    m_pWndList = (CMFCPropertyGridCtrl *)m_pWndList->m_hWnd;
  if ( IsWindow(hWnd: (HWND)m_pWndList) )
  {
    rc = (tagRECT)this->m_Rect;
    InflateRect(lprc: &rc, dx: 0, dy: -1);
    InvalidateRect(hWnd: this->m_pWndList->m_hWnd, lpRect: &rc, bErase: true);
    UpdateWindow(hWnd: this->m_pWndList->m_hWnd);
  }
  if ( this->m_pWndInPlace != nullptr )
  {
    m_pszData = this->FormatProperty(this, result: &v6)->m_pszData;
    m_pWndInPlace = this->m_pWndInPlace;
    v8 = 0;
    CWnd::SetWindowTextA(this: m_pWndInPlace, lpszString: m_pszData);
    ATL::CStringData::Release(this: (ATL::CStringData *)(v6 - 16));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D8EF
// Name: protected: void CMFCPropertyGridCtrl::ReposProperties(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::ReposProperties(CMFCPropertyGridCtrl *this)
{
  bool v2; // zf
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // esi
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v4; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v5; // edi
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v6; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v7; // esi
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v8; // eax
  int y; // [esp+Ch] [ebp-4h] BYREF

  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstTerminalProps);
  if ( this != (CMFCPropertyGridCtrl *)-116 && this->m_ToolTip.m_hWnd != nullptr )
  {
    while ( this->m_nTooltipsCount > 0 )
    {
      CToolTipCtrl::DelTool(this: &this->m_ToolTip, pWnd: this, nIDTool: this->m_nTooltipsCount);
      --this->m_nTooltipsCount;
    }
  }
  v2 = this->m_bAlphabeticMode == 0;
  y = this->m_rectList.top - this->m_nRowHeight * this->m_nVertScrollOffset - 1;
  if ( v2 )
  {
    m_pNodeHead = this->m_lstProps.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      v4 = m_pNodeHead;
      m_pNodeHead = m_pNodeHead->pNext;
      CMFCPropertyGridProperty::Reposition(this: v4->data, &y);
    }
  }
  else
  {
    v5 = this->m_lstProps.m_pNodeHead;
    while ( v5 != nullptr )
    {
      v6 = v5;
      v5 = v5->pNext;
      CMFCPropertyGridProperty::AddTerminalProp(this: v6->data, lstProps: &this->m_lstTerminalProps);
    }
    v7 = this->m_lstTerminalProps.m_pNodeHead;
    while ( v7 != nullptr )
    {
      v8 = v7;
      v7 = v7->pNext;
      CMFCPropertyGridProperty::Reposition(this: v8->data, &y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039D9B1
// Name: protected: void CMFCPropertyGridCtrl::OnHeaderItemChanged(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnHeaderItemChanged(CMFCPropertyGridCtrl *this, tagNMHDR *pNMHDR, int *pResult)
{
  CMFCPropertyGridCtrl_vtbl *v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-5Ch]
  _HD_ITEMA hdItem; // [esp+8h] [ebp-4Ch] BYREF
  int *v11; // [esp+38h] [ebp-1Ch]
  int m_nRowHeight; // [esp+3Ch] [ebp-18h]
  CRect rectClient; // [esp+40h] [ebp-14h] BYREF

  v11 = pResult;
  if ( pNMHDR == nullptr )
    AfxThrowInvalidArgException();
  if ( pNMHDR[1].hwndFrom == nullptr )
  {
    v4 = this->__vftable;
    hdItem.mask = 1;
    v5 = (int)v4->GetHeaderCtrl(this);
    SendMessageA(hWnd: *(HWND *)(v5 + 32), Msg: 0x1203u, wParam: 0, lParam: (LPARAM)&hdItem);
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    m_nRowHeight = this->m_nRowHeight;
    if ( m_nRowHeight <= hdItem.cxy - 2 )
      m_nRowHeight = hdItem.cxy - 2;
    v6 = rectClient.right - rectClient.left;
    if ( m_nRowHeight >= v6 - GetSystemMetrics(nIndex: 21) - 5 )
    {
      v8 = rectClient.right - rectClient.left;
      v7 = v8 - GetSystemMetrics(nIndex: 21) - 5;
    }
    else
    {
      v7 = this->m_nRowHeight;
      if ( v7 <= hdItem.cxy - 2 )
        v7 = hdItem.cxy - 2;
    }
    this->m_nLeftColumnWidth = v7;
    CMFCPropertyGridCtrl::ReposProperties(this);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectList, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  *v11 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039DAB3
// Name: public: virtual int CMFCPropertyGridCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::Create(
        CMFCPropertyGridCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  char *m_pszData; // eax
  int v7; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  m_pszData = AFX_GLOBAL_DATA::RegisterWindowClass(
                this: &afxGlobalData,
                result: &v9,
                lpszClassNamePrefix: "Afx:PropList")->m_pszData;
  v10 = 0;
  v7 = CWnd::Create(
         this,
         lpszClassName: m_pszData,
         lpszWindowName: &var,
         dwStyle,
         rect,
         pParentWnd,
         nID,
         pContext: nullptr);
  ATL::CStringData::Release(this: (ATL::CStringData *)v9.m_pszData - 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1039DB0C
// Name: protected: void CMFCPropertyGridCtrl::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnVScroll(
        CMFCPropertyGridCtrl *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  CMFCPropertyGridProperty *m_pSel; // eax
  HWND__ *m_hWnd; // ecx
  CSpinButtonCtrl *m_pWndSpin; // eax
  int m_nVertScrollOffset; // eax
  int v9; // edi
  unsigned int m_nVertScrollTotal; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  CMFCPropertyGridProperty *v14; // eax

  m_pSel = this->m_pSel;
  if ( m_pSel == nullptr )
    goto LABEL_28;
  if ( pScrollBar == nullptr )
    goto LABEL_28;
  m_hWnd = pScrollBar->m_hWnd;
  if ( m_hWnd == nullptr )
    goto LABEL_28;
  m_pWndSpin = m_pSel->m_pWndSpin;
  if ( m_pWndSpin != nullptr )
    m_pWndSpin = (CSpinButtonCtrl *)m_pWndSpin->m_hWnd;
  if ( m_pWndSpin != (CSpinButtonCtrl *)m_hWnd )
  {
LABEL_28:
    CMFCPropertyGridToolTipCtrl::Hide(this: &this->m_IPToolTip);
    this->EndEditItem(this, a2: 1);
    m_nVertScrollOffset = this->m_nVertScrollOffset;
    v9 = m_nVertScrollOffset;
    switch ( nSBCode )
    {
      case 0u:
        m_nVertScrollTotal = m_nVertScrollOffset - 1;
        goto LABEL_15;
      case 1u:
        m_nVertScrollTotal = m_nVertScrollOffset + 1;
        goto LABEL_15;
      case 2u:
        m_nVertScrollTotal = m_nVertScrollOffset - this->m_nVertScrollPage;
        goto LABEL_15;
      case 3u:
        this->m_nVertScrollOffset = m_nVertScrollOffset + this->m_nVertScrollPage;
        goto LABEL_16;
      case 4u:
      case 5u:
        m_nVertScrollTotal = nPos;
        goto LABEL_15;
      case 6u:
        this->m_nVertScrollOffset = 0;
        goto LABEL_16;
      case 7u:
        m_nVertScrollTotal = this->m_nVertScrollTotal;
LABEL_15:
        this->m_nVertScrollOffset = m_nVertScrollTotal;
LABEL_16:
        v11 = this->m_nVertScrollOffset;
        if ( v11 >= 0 )
          v12 = this->m_nVertScrollOffset;
        else
          v12 = 0;
        v13 = this->m_nVertScrollTotal - this->m_nVertScrollPage + 1;
        if ( v12 < v13 )
        {
          if ( v11 >= 0 )
            v13 = this->m_nVertScrollOffset;
          else
            v13 = 0;
        }
        this->m_nVertScrollOffset = v13;
        if ( v13 != v9 )
        {
          CWnd::SetScrollPos(this, nBar: 1, nPos: v13, bRedraw: 1);
          CMFCPropertyGridCtrl::ReposProperties(this);
          CWnd::ScrollWindow(
            this,
            xAmount: 0,
            yAmount: this->m_nRowHeight * (v9 - this->m_nVertScrollOffset),
            lpRect: &this->m_rectList,
            lpClipRect: &this->m_rectList);
          v14 = this->m_pSel;
          if ( v14 != nullptr )
            RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &v14->m_rectButton, hrgnUpdate: nullptr, flags: 0x105u);
        }
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DC58
// Name: protected: int CMFCPropertyGridCtrl::OnMouseWheel(unsigned int,short,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnMouseWheel(
        CMFCPropertyGridCtrl *this,
        unsigned int __formal,
        __int16 zDelta,
        CPoint a4)
{
  int v4; // eax
  int i; // edi

  if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr && this->m_nVertScrollTotal > 0 )
  {
    v4 = abs(lnumber: zDelta) / 120;
    if ( v4 > 0 )
    {
      for ( i = v4; i != 0; --i )
        CMFCPropertyGridCtrl::OnVScroll(this, nSBCode: zDelta < 0, nPos: 0, pScrollBar: nullptr);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039DCAE
// Name: public: void CMFCPropertyGridCtrl::EnsureVisible(class CMFCPropertyGridProperty __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::EnsureVisible(
        CMFCPropertyGridCtrl *this,
        CMFCPropertyGridProperty *pProp,
        int bExpandParents)
{
  CMFCPropertyGridProperty *v3; // eax
  CMFCPropertyGridProperty *m_pParent; // esi
  CRect *p_m_rectButton; // eax
  int v7; // eax
  int bottom; // eax
  int rect_4; // [esp+8h] [ebp-28h]
  int rect_12; // [esp+10h] [ebp-20h]
  RECT *lprcUpdate; // [esp+14h] [ebp-1Ch]
  CRect rectButton; // [esp+1Ch] [ebp-14h] BYREF

  v3 = pProp;
  if ( this->m_nRowHeight != 0 )
  {
    if ( bExpandParents != 0 && pProp->m_pParent != nullptr )
    {
      m_pParent = pProp->m_pParent;
      if ( m_pParent != nullptr )
      {
        do
        {
          CMFCPropertyGridProperty::Expand(this: m_pParent, bExpand: 1);
          m_pParent = m_pParent->m_pParent;
        }
        while ( m_pParent != nullptr );
        v3 = pProp;
      }
    }
    rect_4 = v3->m_Rect.top;
    rect_12 = v3->m_Rect.bottom;
    if ( rect_4 < this->m_rectList.top - 1 || rect_12 > this->m_rectList.bottom )
    {
      p_m_rectButton = &v3->m_rectButton;
      rectButton = *p_m_rectButton;
      lprcUpdate = p_m_rectButton;
      SetRectEmpty(lprc: p_m_rectButton);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &rectButton, hrgnUpdate: nullptr, flags: 0x105u);
      v7 = this->m_rectList.top - 1;
      if ( rect_4 >= v7 || rect_12 < v7 )
      {
        bottom = this->m_rectList.bottom;
        if ( rect_12 <= bottom || rect_4 > bottom )
          CMFCPropertyGridCtrl::OnVScroll(
            this,
            nSBCode: 4u,
            nPos: rect_4 / this->m_nRowHeight - this->m_nVertScrollOffset,
            pScrollBar: nullptr);
        else
          CMFCPropertyGridCtrl::OnVScroll(this, nSBCode: 1u, nPos: 0, pScrollBar: nullptr);
      }
      else
      {
        CMFCPropertyGridCtrl::OnVScroll(this, nSBCode: 0, nPos: 0, pScrollBar: nullptr);
      }
      if ( !IsRectEmpty(lprc: &rectButton) )
      {
        pProp->AdjustButtonRect(this: pProp);
        RedrawWindow(hWnd: this->m_hWnd, lprcUpdate, hrgnUpdate: nullptr, flags: 0x105u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DDD6
// Name: public: virtual void CMFCPropertyGridCtrl::UpdateColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::UpdateColor(CMFCPropertyGridCtrl *this, unsigned int color)
{
  CMFCPropertyGridColorProperty *v3; // eax
  CMFCPropertyGridProperty *v4; // esi
  unsigned int m_Color; // ebx
  CWnd *m_pWndInPlace; // eax

  v3 = (CMFCPropertyGridColorProperty *)AfxDynamicDownCast(
                                          pClass: &CMFCPropertyGridColorProperty::classCMFCPropertyGridColorProperty,
                                          pObject: this->m_pSel);
  v4 = v3;
  if ( v3 != nullptr )
  {
    m_Color = v3->m_Color;
    CMFCPropertyGridColorProperty::SetColor(this: v3, color);
    if ( color != m_Color )
      this->OnPropertyChanged(this, a2: v4);
    if ( color == -1 )
    {
      m_pWndInPlace = v4->m_pWndInPlace;
      if ( m_pWndInPlace != nullptr && IsWindow(hWnd: m_pWndInPlace->m_hWnd) )
        CWnd::SetWindowTextA(this: v4->m_pWndInPlace, lpszString: &var);
    }
    v4->OnUpdateValue(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DE53
// Name: public: void CMFCPropertyGridCtrl::SetAlphabeticMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::SetAlphabeticMode(CMFCPropertyGridCtrl *this, int bSet)
{
  if ( this->m_bAlphabeticMode != bSet )
  {
    this->m_bAlphabeticMode = bSet;
    this->m_nVertScrollOffset = 0;
    CMFCPropertyGridCtrl::SetCurSel(this, pProp: nullptr, bRedraw: 1);
    if ( this->m_hWnd != nullptr )
    {
      if ( this->m_bAlphabeticMode != 0 )
        CMFCPropertyGridCtrl::ReposProperties(this);
      this->AdjustLayout(this);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DEB1
// Name: public: virtual long CMFCPropertyGridCtrl::get_accValue(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accValue(
        CMFCPropertyGridCtrl *this,
        tagVARIANT varChild,
        wchar_t **pszValue)
{
  CMFCPropertyGridProperty *m_pAccProp; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strValue; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  if ( varChild.vt == 3 && varChild.decVal.Lo32 == 0 )
    return 1;
  m_pAccProp = this->m_pAccProp;
  if ( m_pAccProp == nullptr || m_pAccProp->m_bGroup != 0 && m_pAccProp->m_bIsValueList == 0 )
    return 1;
  m_pAccProp->FormatProperty(this: m_pAccProp, result: &strValue);
  v6 = 0;
  *pszValue = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::AllocSysString(this: &strValue);
  ATL::CStringData::Release(this: (ATL::CStringData *)strValue.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039DF14
// Name: protected: long CMFCPropertyGridCtrl::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnInitControl(CMFCPropertyGridCtrl *this, unsigned int wParam, const char *lParam)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  int v6; // eax
  CTagManager tagManager; // [esp+10h] [ebp-30h] BYREF
  int bVSDotNetLook; // [esp+18h] [ebp-28h] BYREF
  int bModifiedProperties; // [esp+1Ch] [ebp-24h] BYREF
  int bAlphabeticMode; // [esp+20h] [ebp-20h] BYREF
  int bHeaderCtrl; // [esp+24h] [ebp-1Ch] BYREF
  int bDescriptionArea; // [esp+28h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+2Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDescriptionRows; // [esp+30h] [ebp-10h] BYREF
  int v16; // [esp+3Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v16 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v16) = 1;
  bDescriptionArea = 1;
  if ( CMFCControlContainer::ReadBoolProp(
         &tagManager,
         lpszTag: "MFCPropertyGrid_DescriptionArea",
         bMember: &bDescriptionArea) != 0 )
    CMFCPropertyGridCtrl::EnableDescriptionArea(this, bEnable: bDescriptionArea);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDescriptionRows, pStringMgr: v5);
  LOBYTE(v16) = 2;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCPropertyGrid_DescriptionRows",
         strTag: &strDescriptionRows,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strDescriptionRows.m_pszData - 3) != 0 )
  {
    v6 = atoi(nptr: strDescriptionRows.m_pszData);
    if ( v6 >= 0 )
      CMFCPropertyGridCtrl::SetDescriptionRows(this, nDescRows: v6);
  }
  bHeaderCtrl = 1;
  if ( CMFCControlContainer::ReadBoolProp(&tagManager, lpszTag: "MFCPropertyGrid_HeaderCtrl", bMember: &bHeaderCtrl) != 0 )
    CMFCPropertyGridCtrl::EnableHeaderCtrl(
      this,
      bEnable: bHeaderCtrl,
      lpszLeftColumn: "Property",
      lpszRightColumn: "Value");
  bAlphabeticMode = 0;
  if ( CMFCControlContainer::ReadBoolProp(
         &tagManager,
         lpszTag: "MFCPropertyGrid_AlphabeticMode",
         bMember: &bAlphabeticMode) != 0 )
    CMFCPropertyGridCtrl::SetAlphabeticMode(this, bSet: bAlphabeticMode);
  bModifiedProperties = 1;
  if ( CMFCControlContainer::ReadBoolProp(
         &tagManager,
         lpszTag: "MFCPropertyGrid_ModifiedProperties",
         bMember: &bModifiedProperties) != 0 )
    CMFCPropertyGridCtrl::MarkModifiedProperties(this, bMark: bModifiedProperties, bRedraw: 1);
  bVSDotNetLook = 1;
  if ( CMFCControlContainer::ReadBoolProp(&tagManager, lpszTag: "MFCPropertyGrid_VSDotNetLook", bMember: &bVSDotNetLook) != 0 )
    CMFCPropertyGridCtrl::SetVSDotNetLook(this, bSet: bVSDotNetLook);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDescriptionRows.m_pszData - 1);
  LOBYTE(v16) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A645C
// Name: protected: virtual void CMFCButton::OnDrawFocusRect(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnDrawFocusRect(CMFCButton *this, CDC *pDC, const CRect *rectClient)
{
  unsigned int m_clrFace; // eax
  COLORREF clrBckgr; // [esp+10h] [ebp-18h]
  CRect rectFocus; // [esp+14h] [ebp-14h] BYREF

  rectFocus = *rectClient;
  InflateRect(lprc: &rectFocus, dx: -1, dy: -1);
  m_clrFace = this->m_clrFace;
  if ( m_clrFace == -1 )
    m_clrFace = afxGlobalData.clrBtnFace;
  clrBckgr = m_clrFace;
  if ( CMFCButton::m_bWinXPTheme == 0 || this->m_bDontUseWinXPTheme != 0 )
  {
    InflateRect(lprc: &rectFocus, dx: -1, dy: -1);
    CDC::Draw3dRect(this: pDC, lpRect: &rectFocus, clrTopLeft: clrBckgr, clrBottomRight: clrBckgr);
  }
  DrawFocusRect(hDC: pDC->m_hDC, lprc: &rectFocus);
}

//------------------------------------------------------------------------------
// Address: 0x103A64F3
// Name: protected: void CMFCButton::OnEnable(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnEnable(CMFCButton *this, int bEnable)
{
  if ( bEnable == 0 )
  {
    this->m_bPushed = 0;
    this->m_bClickiedInside = 0;
    this->m_bHighlighted = 0;
    if ( this->m_bCaptured != 0 )
    {
      ReleaseCapture();
      this->m_bCaptured = 0;
    }
  }
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A6548
// Name: protected: virtual class CFont __near * CMFCButton::SelectFont(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFont *__thiscall CMFCButton::SelectFont(CMFCButton *this, CDC *pDC)
{
  HFONT__ **p_m_hFont; // esi
  HFONT__ *v3; // esi
  CFont *result; // eax
  CFont *v5; // eax

  p_m_hFont = &this->m_hFont;
  if ( this->m_hFont != nullptr && GetObjectType(h: this->m_hFont) != 6 )
    *p_m_hFont = nullptr;
  v3 = *p_m_hFont;
  if ( v3 != nullptr )
  {
    v5 = (CFont *)CGdiObject::FromHandle(h: v3);
    result = pDC->SelectObject(this: pDC, a2: v5);
  }
  else
  {
    result = (CFont *)pDC->SelectStockObject(this: pDC, a2: 17);
  }
  if ( result == nullptr )
    AfxThrowInvalidArgException();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A6598
// Name: protected: long CMFCButton::OnSetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::OnSetFont(CMFCButton *this, HFONT__ *wParam, __int16 lParam)
{
  this->m_hFont = wParam;
  if ( lParam != 0 )
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A65CD
// Name: protected: void CMFCButton::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnSize(CMFCButton *this, unsigned int nType, unsigned int cx, int cy)
{
  this->m_bDelayFullTextTooltipSet = this->m_bFullTextTooltip;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A65E1
// Name: protected: virtual void CMFCButton::OnDrawBorder(class CDC __near *,class CRect __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnDrawBorder(CMFCButton *this, CDC *pDC, CRect *rectClient, unsigned int uiState)
{
  CMFCButton::DrawBorder(this, pDC, rectClient, uiState);
}

//------------------------------------------------------------------------------
// Address: 0x103A65EC
// Name: protected: void CMFCButton::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnKillFocus(CMFCButton *this, CWnd *pNewWnd)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-18h]

  CWnd::Default(this);
  if ( this->m_bCaptured != 0 )
  {
    ReleaseCapture();
    this->m_bCaptured = 0;
  }
  m_hWnd = this->m_hWnd;
  this->m_bPushed = 0;
  this->m_bClickiedInside = 0;
  this->m_bHighlighted = 0;
  this->m_bHover = 0;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x103A6641
// Name: protected: void CMFCButton::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnLButtonDblClk(CMFCButton *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-14h]

  m_hWnd = this->m_hWnd;
  this->m_bPushed = 1;
  this->m_bClickiedInside = 1;
  this->m_bHighlighted = 1;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
  CWnd::Default(this);
  this->m_bWasDblClk = 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A6683
// Name: protected: int CMFCButton::CheckNextPrevRadioButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::CheckNextPrevRadioButton(CMFCButton *this, CWnd *bNext)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  CMFCButton *v6; // esi
  HWND v7; // eax
  CWnd *v8; // eax
  HWND m_hWnd; // ebx
  unsigned __int16 WindowLongA; // ax
  HWND v11; // [esp-Ch] [ebp-18h]
  CWnd *pWndParent; // [esp+4h] [ebp-8h]
  BOOL bPrevious; // [esp+8h] [ebp-4h]
  CMFCButton *pWnd; // [esp+14h] [ebp+8h]

  if ( this->m_bRadioButton == 0 )
    return 0;
  Parent = GetParent(hWnd: this->m_hWnd);
  pWndParent = CWnd::FromHandle(hWnd: Parent);
  bPrevious = bNext == nullptr;
  pWnd = (CMFCButton *)CWnd::GetNextDlgGroupItem(this: pWndParent, pWndCtl: this, bPrevious);
  if ( pWnd == this )
    return 0;
  do
  {
    v5 = (CWnd *)AfxDynamicDownCast(pClass: &CMFCButton::classCMFCButton, pObject: pWnd);
    v6 = (CMFCButton *)v5;
    if ( v5 != nullptr && HIDWORD(v5[1].m_ulGestureArg) != 0 && (CWnd::GetStyle(this: v5) & 0x18000000) == 0x10000000 )
      break;
    pWnd = (CMFCButton *)CWnd::GetNextDlgGroupItem(this: pWndParent, pWndCtl: pWnd, bPrevious);
  }
  while ( pWnd != this );
  if ( v6 == nullptr || v6 == this || v6->m_bChecked != 0 )
    return 0;
  SendMessageA(hWnd: v6->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  CWnd::SetFocus(this: v6);
  v7 = GetParent(hWnd: v6->m_hWnd);
  v8 = CWnd::FromHandle(hWnd: v7);
  if ( v8 != nullptr )
    m_hWnd = v8->m_hWnd;
  else
    m_hWnd = nullptr;
  v11 = v6->m_hWnd;
  WindowLongA = GetWindowLongA(hWnd: v11, nIndex: -12);
  SendMessageA(hWnd: m_hWnd, Msg: 0x111u, wParam: WindowLongA, lParam: (LPARAM)v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A6781
// Name: protected: void CMFCButton::UncheckRadioButtonsInGroup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::UncheckRadioButtonsInGroup(CMFCButton *this)
{
  HWND Parent; // eax
  CMFCButton *i; // eax
  CObject *v4; // eax
  CWnd *v5; // edi
  HWND v6; // [esp-14h] [ebp-20h]
  CWnd *pWndParent; // [esp+8h] [ebp-4h]

  Parent = GetParent(hWnd: this->m_hWnd);
  pWndParent = CWnd::FromHandle(hWnd: Parent);
  if ( pWndParent != nullptr && CWnd::IsWindowEnabled(this) != 0 )
  {
    for ( i = (CMFCButton *)CWnd::GetNextDlgGroupItem(this: pWndParent, pWndCtl: this, bPrevious: 0);
          ;
          i = (CMFCButton *)CWnd::GetNextDlgGroupItem(this: pWndParent, pWndCtl: v5, bPrevious: 0) )
    {
      v5 = i;
      if ( i == this || i == nullptr )
        break;
      v4 = AfxDynamicDownCast(pClass: &CMFCButton::classCMFCButton, pObject: i);
      if ( v4 != nullptr && v4[47].__vftable != nullptr && v4[45].__vftable != nullptr )
      {
        v6 = (HWND)v4[8].__vftable;
        v4[45].__vftable = nullptr;
        RedrawWindow(hWnd: v6, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A6803
// Name: protected: void CMFCButton::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnTimer(CMFCButton *this, unsigned int nIDEvent)
{
  HWND Parent; // eax
  CWnd *v4; // edi
  HWND__ *m_hWnd; // ebx
  unsigned __int16 DlgCtrlID; // ax

  if ( nIDEvent == 1 && this->m_bPushed != 0 && this->m_bHighlighted != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    if ( v4 != nullptr )
    {
      m_hWnd = this->m_hWnd;
      DlgCtrlID = CWnd::GetDlgCtrlID(this);
      SendMessageA(hWnd: v4->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
    }
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A6865
// Name: public: static class CObject __near * CMFCButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCButton *__stdcall CMFCButton::CreateObject()
{
  CMFCButton *v0; // ecx
  CMFCButton *result; // eax

  v0 = (CMFCButton *)operator new(nSize: 0x750u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCButton::CMFCButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AD349
// Name: public: int CMFCToolBar::WrapToolBar(int,int,class CDC __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::WrapToolBar(
        CMFCToolBar *this,
        int nWidth,
        int nHeight,
        CDmAttributeOp<VMatrix> *pDC,
        int nColumnWidth,
        int nRowHeight)
{
  CDC *v6; // edi
  CMFCToolBar_vtbl *v8; // eax
  BOOL v9; // esi
  CClientDC *v10; // eax
  CClientDC *v11; // eax
  CFont *v12; // eax
  _DWORD *v13; // eax
  CObList::CNode *m_pNodeHead; // eax
  CObject *data; // edi
  CObList::CNode *pNext; // ecx
  int *v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  char v22[8]; // [esp+10h] [ebp-54h] BYREF
  int v23; // [esp+18h] [ebp-4Ch] BYREF
  int v24; // [esp+1Ch] [ebp-48h]
  int top; // [esp+20h] [ebp-44h]
  CObject *v26; // [esp+24h] [ebp-40h]
  char v27[4]; // [esp+28h] [ebp-3Ch] BYREF
  int v28; // [esp+2Ch] [ebp-38h]
  void *pData; // [esp+30h] [ebp-34h]
  int v30; // [esp+34h] [ebp-30h]
  CFont *v31; // [esp+38h] [ebp-2Ch]
  int v32; // [esp+3Ch] [ebp-28h]
  CDC *v33; // [esp+40h] [ebp-24h]
  tagRECT Rect; // [esp+44h] [ebp-20h] BYREF
  int v35; // [esp+60h] [ebp-4h]

  v6 = (CDC *)pDC;
  v30 = 0;
  v31 = nullptr;
  v8 = this->__vftable;
  v33 = (CDC *)pDC;
  v9 = (v8->GetCurrentAlignment(this) & 0xA000) == 0;
  pData = nullptr;
  if ( pDC == nullptr )
  {
    v10 = (CClientDC *)operator new(nSize: 0x14u);
    pData = v10;
    v35 = 0;
    if ( v10 != nullptr )
      v11 = CClientDC::CClientDC(this: v10, pWnd: this);
    else
      v11 = nullptr;
    v35 = -1;
    v33 = v11;
    pData = (void *)1;
    if ( v9 )
      v12 = v11->SelectObject(this: v11, a2: &afxGlobalData.fontVert);
    else
      v12 = CBasePane::SelectDefaultFont(this, pDC: v11);
    v31 = v12;
    if ( v12 == nullptr )
      AfxThrowInvalidArgException();
    v6 = v33;
  }
  v26 = nullptr;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &Rect);
  v32 = 0;
  top = Rect.top;
  if ( this->IsFloating(this) != 0 )
    nHeight = 0x7FFF;
  v23 = nColumnWidth;
  v24 = nRowHeight;
  if ( nColumnWidth < 0 || nRowHeight < 0 )
  {
    v28 = this->GetRowHeight(this);
    v23 = this->GetColumnWidth(this);
    v24 = v28;
  }
  if ( this->IsFloating(this) == 0 && !v9 && this->m_pCustomizeBtn != nullptr )
  {
    v13 = (_DWORD *)((int (__thiscall *)(CMFCCustomizeButton *, char *, CDC *, int *, int))this->m_pCustomizeBtn->OnCalculateSize)(
                      a1: this->m_pCustomizeBtn,
                      a2: v27,
                      a3: v6,
                      a4: &v23,
                      a5: 1);
    nWidth -= *v13;
    v28 = v13[1];
  }
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = m_pNodeHead->data;
      pNext = m_pNodeHead->pNext;
      v28 = (int)m_pNodeHead->pNext;
      if ( data == nullptr )
        break;
      data[4].__vftable = nullptr;
      if ( pNext == nullptr && this->m_pCustomizeBtn != nullptr )
        break;
      if ( data[20].__vftable != nullptr )
      {
        v17 = (int *)((int (__thiscall *)(CObject *, char *, CDC *, int *, bool))data->__vftable[2].dtr_CObject)(
                       a1: data,
                       a2: v22,
                       a3: v33,
                       a4: &v23,
                       a5: !v9);
        v18 = *v17;
        v19 = v17[1];
        if ( v32 == 0 && ((int)data[9].__vftable & 1) != 0 )
        {
          v18 = 0;
          v19 = 0;
        }
        if ( v18 + v32 > nWidth )
        {
          v20 = top + v19;
          if ( v20 < nHeight && ((int)data[9].__vftable & 1) == 0 && v26 != nullptr )
          {
            v32 = 0;
            ++v30;
            v26[4].__vftable = (CObject_vtbl *)1;
            top = v20 + 5;
          }
        }
        v32 += v18;
        v26 = data;
      }
      if ( v28 == 0 )
        break;
      m_pNodeHead = (CObList::CNode *)v28;
    }
    v6 = v33;
  }
  if ( pData != nullptr )
  {
    v6->SelectObject(this: v6, a2: v31);
    ((void (__thiscall *)(CDC *, int))v6->dtr_CObject)(a1: v6, a2: 1);
  }
  return v30 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AD55E
// Name: protected: void CMFCToolBar::SizeToolBar(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::SizeToolBar(CMFCToolBar *this, int nLength, int bVert)
{
  CMFCToolBar_vtbl *v4; // eax
  int v5; // ebx
  CFont *v6; // eax
  int v7; // ebx
  int v8; // ebx
  int v9; // eax
  CSize *v10; // eax
  int cx; // ecx
  CSize *v12; // eax
  CSize *v13; // eax
  CClientDC dc; // [esp+10h] [ebp-3Ch] BYREF
  int nTarget; // [esp+24h] [ebp-28h] BYREF
  int cy; // [esp+28h] [ebp-24h]
  CFont *pOldFont; // [esp+2Ch] [ebp-20h]
  _BYTE v18[4]; // [esp+30h] [ebp-1Ch] BYREF
  int nMax; // [esp+34h] [ebp-18h]
  int nColumnWidth; // [esp+38h] [ebp-14h]
  int nRowHeight; // [esp+3Ch] [ebp-10h]
  int v22; // [esp+48h] [ebp-4h]
  int nMin; // [esp+58h] [ebp+Ch]

  nColumnWidth = this->GetColumnWidth(this);
  nRowHeight = this->GetRowHeight(this);
  CClientDC::CClientDC(this: &dc, pWnd: this);
  v4 = this->__vftable;
  v5 = 0;
  v22 = 0;
  if ( (v4->GetCurrentAlignment(this) & 0xA000) != 0 )
    v6 = CBasePane::SelectDefaultFont(this, pDC: &dc);
  else
    v6 = CDC::SelectObject(this: &dc, pFont: &afxGlobalData.fontVert);
  pOldFont = v6;
  if ( v6 == nullptr )
    AfxThrowInvalidArgException();
  if ( bVert != 0 )
  {
    CMFCToolBar::WrapToolBar(
      this,
      nWidth: 0x7FFF,
      nHeight: 0x7FFF,
      pDC: (CDmAttributeOp<VMatrix> *)&dc,
      nColumnWidth,
      nRowHeight);
    v12 = this->CalcSize(this, result: &nTarget, a3: 0);
    cx = v12->cx;
    if ( nLength > v12->cy )
    {
      do
      {
        v5 += CMFCToolBar::GetButtonSize(this, a2: 0x7FFF, result: (CSize *)&nTarget)->cx;
        CMFCToolBar::WrapToolBar(
          this,
          nWidth: v5,
          nHeight: 0x7FFF,
          pDC: (CDmAttributeOp<VMatrix> *)&dc,
          nColumnWidth,
          nRowHeight);
        v13 = this->CalcSize(this, result: v18, a3: 0);
        cx = v13->cx;
      }
      while ( nLength < v13->cy );
    }
  }
  else
  {
    nMin = 0;
    v7 = CMFCToolBar::WrapToolBar(
           this,
           nWidth: 0,
           nHeight: 0x7FFF,
           pDC: (CDmAttributeOp<VMatrix> *)&dc,
           nColumnWidth,
           nRowHeight);
    nMax = nLength;
    cy = CMFCToolBar::WrapToolBar(
           this,
           nWidth: nLength,
           nHeight: 0x7FFF,
           pDC: (CDmAttributeOp<VMatrix> *)&dc,
           nColumnWidth,
           nRowHeight);
    if ( v7 != cy && nLength > 0 )
    {
      do
      {
        v8 = (nMin + nMax) / 2;
        v9 = CMFCToolBar::WrapToolBar(
               this,
               nWidth: v8,
               nHeight: 0x7FFF,
               pDC: (CDmAttributeOp<VMatrix> *)&dc,
               nColumnWidth,
               nRowHeight);
        if ( v9 == cy )
        {
          nMax = v8;
        }
        else
        {
          if ( nMin == v8 )
          {
            CMFCToolBar::WrapToolBar(
              this,
              nWidth: nMax,
              nHeight: 0x7FFF,
              pDC: (CDmAttributeOp<VMatrix> *)&dc,
              nColumnWidth,
              nRowHeight);
            break;
          }
          nMin = v8;
        }
      }
      while ( nMin < nMax );
    }
    v10 = this->CalcSize(this, result: &nTarget, a3: 0);
    cx = v10->cx;
    cy = v10->cy;
  }
  CMFCToolBar::WrapToolBar(
    this,
    nWidth: cx,
    nHeight: 0x7FFF,
    pDC: (CDmAttributeOp<VMatrix> *)&dc,
    nColumnWidth,
    nRowHeight);
  CDC::SelectObject(this: &dc, pFont: pOldFont);
  v22 = -1;
  CClientDC::~CClientDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x103AD713
// Name: protected: virtual void CMFCToolBar::AddRemoveSeparator(class CMFCToolBarButton const __near *,class CPoint const __near &,class CPoint const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::AddRemoveSeparator(
        CMFCToolBar *this,
        const CMFCToolBarButton *pButton,
        const CPoint *ptStart,
        const CPoint *ptDrop)
{
  int v5; // edi
  int v6; // ebx
  int v7; // edi
  CMFCToolBarButton *Button; // eax

  v5 = CMFCToolBar::ButtonToIndex(this, pButton);
  if ( v5 > 0 )
  {
    v6 = (this->GetCurrentAlignment(this) & 0xA000) != 0 ? ptDrop->x - ptStart->x : ptDrop->y - ptStart->y;
    if ( abs(lnumber: v6) >= 6 )
    {
      if ( v6 <= 0 )
      {
        v7 = v5 - 1;
        Button = CMFCToolBar::GetButton(this, nIndex: v7);
        if ( (Button->m_nStyle & 1) == 0 )
          return;
        if ( Button->m_bVisible != 0 )
          this->RemoveButton(this, a2: v7);
      }
      else
      {
        if ( (CMFCToolBar::GetButton(this, nIndex: v5 - 1)->m_nStyle & 1) != 0 )
          return;
        this->InsertSeparator(this, a2: v5);
      }
      this->AdjustLayout(this);
      this->m_iSelected = -1;
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AD7CB
// Name: public: virtual int CMFCToolBar::RestoreOriginalstate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::RestoreOriginalstate(CMFCToolBar *this)
{
  unsigned int m_uiOriginalResID; // eax
  CMFCToolBar_vtbl *v4; // ebx
  int v5; // eax
  CFrameWnd *v6; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-34h]
  int bRes; // [esp+8h] [ebp-20h]
  CSize sizeCurr; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  m_uiOriginalResID = this->m_uiOriginalResID;
  if ( m_uiOriginalResID == 0 )
    return 0;
  bRes = this->LoadToolBar(this, a2: m_uiOriginalResID, a3: 0, a4: 0, a5: 0, a6: 0, a7: 0, a8: 0);
  this->AdjustLayout(this);
  if ( this->IsFloating(this) != 0 )
  {
    this->RecalcLayout(this);
  }
  else if ( this->m_pParentDockBar != nullptr )
  {
    v4 = this->__vftable;
    v5 = this->IsHorizontal(this);
    v4->CalcFixedLayout(this, result: &sizeCurr, a3: 0, a4: v5);
    m_hWnd = this->m_hWnd;
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
    if ( rect.right - rect.left != sizeCurr.cx || rect.bottom - rect.top != sizeCurr.cy )
    {
      this->SetWindowPos(this, a2: nullptr, a3: 0, a4: 0, a5: sizeCurr.cx, a6: sizeCurr.cy, a7: 22u, a8: nullptr);
      CPane::UpdateVirtualRect(this);
    }
    this->m_pDockBarRow->ArrangePanes(this: this->m_pDockBarRow, a2: this);
    v6 = AFXGetParentFrame(pWnd: this);
    v6->RecalcLayout(this: v6, a2: 1);
  }
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x103AD8DF
// Name: protected: virtual int CMFCToolBar::EnableContextMenuItems(class CMFCToolBarButton __near *,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::EnableContextMenuItems(CMFCToolBar *this, CMFCToolBarButton *pButton, CMenu *pPopup)
{
  BOOL v3; // esi
  int m_iImage; // eax
  unsigned int m_nID; // eax
  void (__stdcall *v6)(HMENU, UINT, UINT); // esi
  CObList::CNode *m_pNodeHead; // eax
  CMFCToolBarButton *v8; // edx
  CMFCToolBarButton *data; // ecx

  v3 = (this->m_dwStyle & 0xA000) != 0;
  if ( pButton->OnCustomizeMenu(this: pButton, a2: pPopup) != 0 )
  {
    v6 = (void (__stdcall *)(HMENU, UINT, UINT))EnableMenuItem;
  }
  else
  {
    if ( pButton->m_bImage == 0
      || (pButton->m_bUserButton == 0 ? (m_iImage = pButton->m_iImage) : (m_iImage = pButton->m_iUserImage), m_iImage < 0) )
    {
      EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x420Fu, uEnable: 1u);
    }
    m_nID = pButton->m_nID;
    if ( m_nID == -1 || m_nID == 0 )
      EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x420Eu, uEnable: 1u);
    if ( pButton->m_bText != 0 || pButton->m_bTextBelow != 0 && v3 )
    {
      if ( pButton->m_bImage != 0 )
        CheckMenuItem(hMenu: pPopup->m_hMenu, uIDCheckItem: 0x4214u, uCheck: 8u);
      else
        CheckMenuItem(hMenu: pPopup->m_hMenu, uIDCheckItem: 0x4213u, uCheck: 8u);
    }
    else
    {
      CheckMenuItem(hMenu: pPopup->m_hMenu, uIDCheckItem: 0x4212u, uCheck: 8u);
    }
    if ( pButton->m_bTextBelow != 0 && v3 )
    {
      v6 = (void (__stdcall *)(HMENU, UINT, UINT))EnableMenuItem;
      EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4212u, uEnable: 1u);
    }
    else
    {
      v6 = (void (__stdcall *)(HMENU, UINT, UINT))EnableMenuItem;
    }
    if ( this->IsPureMenuButton(this, a2: pButton) != 0 )
    {
      v6(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4212u, uEnable: 1u);
      v6(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4213u, uEnable: 1u);
      v6(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4214u, uEnable: 1u);
      pButton->m_bText = 1;
    }
  }
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  v8 = nullptr;
  while ( m_pNodeHead != nullptr )
  {
    data = (CMFCToolBarButton *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == pButton )
    {
      if ( v8 != nullptr )
      {
        if ( (v8->m_nStyle & 1) != 0 )
          CheckMenuItem(hMenu: pPopup->m_hMenu, uIDCheckItem: 0x4215u, uCheck: 8u);
      }
      else
      {
        v6(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4215u, uEnable: 1u);
      }
      return 1;
    }
    v8 = data;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103ADA4C
// Name: public: virtual void CMFCToolBar::OnChangeHot(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnChangeHot(CMFCToolBar *this, int iHot)
{
  int v2; // ebx
  int m_iHot; // eax
  CMFCToolBarMenuButton *DroppedDownMenu; // edi
  CMFCToolBarButton *Button; // eax
  CObject *v7; // ebx
  int v8; // eax
  CMFCToolBarButton *v9; // eax
  int v10; // ecx
  int m_iHighlighted; // eax
  int v12; // [esp-4h] [ebp-18h]
  CMFCPopupMenu::ANIMATION_TYPE animType; // [esp+Ch] [ebp-8h]
  int iHighlighted; // [esp+1Ch] [ebp+8h]
  int iHighlighteda; // [esp+1Ch] [ebp+8h]

  v2 = iHot;
  m_iHot = this->m_iHot;
  if ( m_iHot == iHot && m_iHot >= 0 )
    v2 = -1;
  this->m_iHot = v2;
  DroppedDownMenu = CMFCToolBar::GetDroppedDownMenu(this, pIndex: nullptr);
  if ( DroppedDownMenu != nullptr )
  {
    if ( DroppedDownMenu->IsExclusive(this: DroppedDownMenu) != 0 )
      return;
  }
  else if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    return;
  }
  if ( v2 < 0 || v2 >= this->m_Buttons.m_nCount )
  {
    this->m_iHot = -1;
    if ( DroppedDownMenu != nullptr && CMFCToolBar::m_bCustomizeMode != 0 && CMFCToolBar::m_bAltCustomizeMode == 0 )
      DroppedDownMenu->OnCancelMode(this: DroppedDownMenu);
  }
  else
  {
    Button = CMFCToolBar::GetButton(this, nIndex: v2);
    v7 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: Button);
    if ( v7 == DroppedDownMenu )
    {
      if ( CMFCToolBar::m_bCustomizeMode == 0 )
        goto LABEL_33;
      if ( DroppedDownMenu != nullptr && DroppedDownMenu->IsDroppedDown(this: DroppedDownMenu) != 0 )
        DroppedDownMenu->OnCancelMode(this: DroppedDownMenu);
    }
    else
    {
      iHighlighted = 0;
      animType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
      if ( DroppedDownMenu != nullptr )
      {
        iHighlighteda = this->m_iHighlighted;
        if ( CMFCToolBar::m_bCustomizeMode == 0 )
          this->m_iHighlighted = -1;
        DroppedDownMenu->OnCancelMode(this: DroppedDownMenu);
        this->m_iHighlighted = iHighlighteda;
        iHighlighted = 1;
      }
      if ( v7 != nullptr
        && (CMFCToolBar::m_bCustomizeMode == 0
         || CObject::IsKindOf(this: v7, pClass: &CMFCToolBarSystemMenuButton::classCMFCToolBarSystemMenuButton) == 0) )
      {
        if ( iHighlighted != 0 )
          CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
        ((void (__thiscall *)(CObject *, CMFCToolBar *, int))v7->__vftable[2].Serialize)(a1: v7, a2: this, a3: 1);
        CMFCPopupMenu::m_AnimationType = animType;
      }
    }
    if ( CMFCToolBar::m_bCustomizeMode == 0 || this->m_iDragIndex >= 0 )
    {
LABEL_33:
      v10 = this->m_iHot;
      if ( v10 >= 0 )
      {
        m_iHighlighted = this->m_iHighlighted;
        if ( v10 != m_iHighlighted )
        {
          if ( m_iHighlighted >= 0 )
            CMFCToolBar::InvalidateButton(this, nIndex: this->m_iHighlighted);
          v12 = this->m_iHot;
          this->m_iHighlighted = v12;
          CMFCToolBar::InvalidateButton(this, nIndex: v12);
          UpdateWindow(hWnd: this->m_hWnd);
        }
      }
      return;
    }
    v8 = this->m_iHighlighted;
    this->m_iSelected = this->m_iHot;
    if ( v8 != -1 )
      CMFCToolBar::InvalidateButton(this, nIndex: v8);
    v9 = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
    if ( v9 != nullptr )
    {
      if ( (v9->m_nStyle & 1) != 0 )
        this->m_iSelected = -1;
      else
        CMFCToolBar::InvalidateButton(this, nIndex: this->m_iSelected);
      goto LABEL_33;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ADC3F
// Name: public: virtual int CMFCToolBar::PrevMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::PrevMenu(CMFCToolBar *this)
{
  CMFCToolBarMenuButton *DroppedDownMenu; // eax
  int v3; // edi
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  CMFCToolBarButton *Button; // eax
  CObject *v7; // esi
  CMFCToolBarButton *pButton; // [esp+Ch] [ebp-Ch]
  CMFCToolBarButton *pButtona; // [esp+Ch] [ebp-Ch]
  int iTotalItems; // [esp+10h] [ebp-8h]
  int iHot; // [esp+14h] [ebp-4h] BYREF

  DroppedDownMenu = CMFCToolBar::GetDroppedDownMenu(this, pIndex: &iHot);
  if ( DroppedDownMenu == nullptr || DroppedDownMenu->IsExclusive(this: DroppedDownMenu) != 0 )
    return 0;
  v3 = iHot - 1;
  iTotalItems = this->m_Buttons.m_nCount;
  do
  {
    if ( v3 < 0 )
      v3 = iTotalItems - 1;
    pButton = CMFCToolBar::GetButton(this, nIndex: v3);
    if ( AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: pButton) != nullptr
      && (pButton->m_nStyle & 0x40000) == 0 )
    {
      break;
    }
    --v3;
  }
  while ( v3 != iHot );
  if ( v3 != iHot )
  {
    AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
    CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
    pButtona = (CMFCToolBarButton *)AnimationType;
    this->OnChangeHot(this, a2: v3);
    if ( this->m_iHot >= 0 )
    {
      Button = CMFCToolBar::GetButton(this, nIndex: this->m_iHot);
      v7 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: Button);
      if ( v7 != nullptr && ((int (__thiscall *)(CObject *))v7->__vftable[9].dtr_CObject)(a1: v7) != 0 )
        SendMessageA(hWnd: (HWND)v7[35].__vftable[2].Serialize, Msg: 0x100u, wParam: 0x24u, lParam: 0);
    }
    CMFCPopupMenu::m_AnimationType = (CMFCPopupMenu::ANIMATION_TYPE)pButtona;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103ADD36
// Name: public: virtual int CMFCToolBar::NextMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::NextMenu(CMFCToolBar *this)
{
  CMFCToolBarMenuButton *DroppedDownMenu; // eax
  int v3; // edi
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  CMFCToolBarButton *Button; // eax
  CObject *v7; // esi
  CMFCToolBarButton *pButton; // [esp+Ch] [ebp-Ch]
  CMFCToolBarButton *pButtona; // [esp+Ch] [ebp-Ch]
  int iTotalItems; // [esp+10h] [ebp-8h]
  int iHot; // [esp+14h] [ebp-4h] BYREF

  DroppedDownMenu = CMFCToolBar::GetDroppedDownMenu(this, pIndex: &iHot);
  if ( DroppedDownMenu == nullptr || DroppedDownMenu->IsExclusive(this: DroppedDownMenu) != 0 )
    return 0;
  v3 = iHot + 1;
  iTotalItems = this->m_Buttons.m_nCount;
  do
  {
    if ( v3 >= iTotalItems )
      v3 = 0;
    pButton = CMFCToolBar::GetButton(this, nIndex: v3);
    if ( AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: pButton) != nullptr
      && (pButton->m_nStyle & 0x40000) == 0 )
    {
      break;
    }
    ++v3;
  }
  while ( v3 != iHot );
  if ( v3 != iHot )
  {
    AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
    CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
    pButtona = (CMFCToolBarButton *)AnimationType;
    this->OnChangeHot(this, a2: v3);
    if ( this->m_iHot >= 0 )
    {
      Button = CMFCToolBar::GetButton(this, nIndex: this->m_iHot);
      v7 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: Button);
      if ( v7 != nullptr && ((int (__thiscall *)(CObject *))v7->__vftable[9].dtr_CObject)(a1: v7) != 0 )
        SendMessageA(hWnd: (HWND)v7[35].__vftable[2].Serialize, Msg: 0x100u, wParam: 0x24u, lParam: 0);
    }
    CMFCPopupMenu::m_AnimationType = (CMFCPopupMenu::ANIMATION_TYPE)pButtona;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103ADE2C
// Name: public: int CMFCToolBar::SetHot(class CMFCToolBarButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::SetHot(CMFCToolBar *this, CMFCToolBarButton *pMenuButton)
{
  CMFCToolBarMenuButton *DroppedDownMenu; // eax
  int result; // eax
  int v5; // edx
  int v6; // ecx

  DroppedDownMenu = CMFCToolBar::GetDroppedDownMenu(this, pIndex: nullptr);
  if ( DroppedDownMenu != nullptr && DroppedDownMenu->IsExclusive(this: DroppedDownMenu) != 0 )
    return 1;
  if ( pMenuButton != nullptr )
  {
    result = (int)this->m_Buttons.m_pNodeHead;
    v5 = 0;
    while ( result != 0 )
    {
      v6 = result;
      result = *(_DWORD *)result;
      if ( pMenuButton == *(CMFCToolBarButton **)(v6 + 8) )
      {
        if ( this->m_iHot != v5 )
          this->OnChangeHot(this, a2: v5);
        return 1;
      }
      ++v5;
    }
  }
  else
  {
    this->m_iHot = -1;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103ADEA2
// Name: protected: int CMFCToolBar::DropDownMenu(class CMFCToolBarButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::DropDownMenu(CMFCToolBar *this, CMFCToolBarButton *pButton)
{
  CObject *v4; // eax
  CMFCToolBarButton *v5; // esi

  if ( pButton == nullptr )
    return 0;
  v4 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: pButton);
  v5 = (CMFCToolBarButton *)v4;
  if ( v4 == nullptr
    || ((int (__thiscall *)(CObject *, CMFCToolBar *, int))v4->__vftable[2].Serialize)(a1: v4, a2: this, a3: 1) == 0 )
  {
    return 0;
  }
  if ( v5->IsDroppedDown(this: v5) != 0 )
    SendMessageA(hWnd: *(HWND *)(v5[1].m_bDragFromCollection + 32), Msg: 0x100u, wParam: 0x24u, lParam: 0);
  CMFCToolBar::SetHot(this, pMenuButton: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103ADF10
// Name: protected: void CMFCToolBar::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnSetFocus(CMFCToolBar *this, CWnd *pOldWnd)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  HWND v5; // eax
  CWnd *v6; // eax

  CWnd::OnSetFocus(this, __formal: pOldWnd);
  if ( this->m_bLeaveFocus != 0
    && pOldWnd != nullptr
    && IsWindow(hWnd: pOldWnd->m_hWnd)
    && AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: pOldWnd) == nullptr )
  {
    Parent = GetParent(hWnd: pOldWnd->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    if ( AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v4) == nullptr )
    {
      v5 = GetParent(hWnd: this->m_hWnd);
      v6 = CWnd::FromHandle(hWnd: v5);
      if ( AfxDynamicDownCast(pClass: &CMFCBaseTabCtrl::classCMFCBaseTabCtrl, pObject: v6) == nullptr )
        this->m_hwndLastFocus = pOldWnd->m_hWnd;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ADFA0
// Name: protected: void CMFCToolBar::OnToolbarNewMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarNewMenu(CMFCToolBar *this)
{
  CMFCToolBarMenuButton *v2; // eax
  CMFCToolBarMenuButton *v3; // edi
  int v4; // eax
  CMFCToolBarButtonCustomizeDialog v5; // [esp+14h] [ebp-4E0h] BYREF
  int v6; // [esp+4F0h] [ebp-4h]

  v2 = (CMFCToolBarMenuButton *)operator new(nSize: 0xE8u);
  v3 = nullptr;
  v6 = 0;
  if ( v2 != nullptr )
    v3 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(this: v2);
  v3->m_bImage = 0;
  v6 = -1;
  v3->m_bText = 1;
  v4 = this->IsPureMenuButton(this, a2: v3);
  CMFCToolBarButtonCustomizeDialog::CMFCToolBarButtonCustomizeDialog(
    this: &v5,
    pButton: v3,
    pImages: CMFCToolBar::m_pUserImages,
    pParent: this,
    iStartImage: 0,
    bMenuMode: v4);
  v6 = 1;
  if ( CDialog::DoModal(this: &v5) == 1 )
  {
    this->m_iSelected = this->InsertButton(this, a2: v3, a3: this->m_iSelected);
    this->AdjustLayout(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
    v3->OnClick(this: v3, a2: this, a3: 0);
  }
  else
  {
    ((void (__thiscall *)(CMFCToolBarMenuButton *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  v6 = -1;
  CMFCToolBarButtonCustomizeDialog::~CMFCToolBarButtonCustomizeDialog(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x103AE070
// Name: public: static void CMFCToolBar::SetLargeIcons(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCToolBar::SetLargeIcons(int bLargeIcons)
{
  int cy; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObject *data; // esi
  int v4; // edi
  double v5; // st6
  int v6; // eax
  double v7; // st6
  int v8; // eax
  double v9; // st6
  int v10; // eax
  HWND Parent; // eax
  CWnd *v12; // eax
  CObject *v13; // eax

  CMFCToolBar::m_bLargeIcons = bLargeIcons;
  if ( bLargeIcons != 0 )
  {
    CMFCToolBar::m_sizeCurButton.cx = (int)((double)CMFCToolBar::m_sizeButton.cx * CMFCToolBar::m_dblLargeImageRatio
                                          + 0.5);
    CMFCToolBar::m_sizeCurButton.cy = (int)((double)CMFCToolBar::m_sizeButton.cy * CMFCToolBar::m_dblLargeImageRatio
                                          + 0.5);
    CMFCToolBar::m_sizeCurImage.cx = (int)((double)CMFCToolBar::m_sizeImage.cx * CMFCToolBar::m_dblLargeImageRatio + 0.5);
    cy = (int)(CMFCToolBar::m_dblLargeImageRatio * (double)CMFCToolBar::m_sizeImage.cy + 0.5);
  }
  else
  {
    CMFCToolBar::m_sizeCurButton = CMFCToolBar::m_sizeButton;
    CMFCToolBar::m_sizeCurImage.cx = CMFCToolBar::m_sizeImage.cx;
    cy = CMFCToolBar::m_sizeImage.cy;
  }
  m_pNodeHead = afxAllToolBars.m_pNodeHead;
  CMFCToolBar::m_sizeCurImage.cy = cy;
  while ( m_pNodeHead != nullptr )
  {
    if ( m_pNodeHead == nullptr || (data = m_pNodeHead->data, m_pNodeHead = m_pNodeHead->pNext, data == nullptr) )
      AfxThrowInvalidArgException();
    if ( CWnd::FromHandlePermanent(hWnd: (HWND__ *)data[8].__vftable) == nullptr )
      continue;
    if ( data[705].__vftable == nullptr )
      goto LABEL_21;
    if ( CMFCToolBar::m_bLargeIcons != 0 )
    {
      v4 = (int)((double)(int)data[743].__vftable * CMFCToolBar::m_dblLargeImageRatio + 0.5);
      if ( data[747].__vftable != (CObject_vtbl *)v4
        || data[748].__vftable != (CObject_vtbl *)(int)((double)(int)data[744].__vftable
                                                      * CMFCToolBar::m_dblLargeImageRatio
                                                      + 0.5)
        || data[749].__vftable != (CObject_vtbl *)(int)((double)(int)data[745].__vftable
                                                      * CMFCToolBar::m_dblLargeImageRatio
                                                      + 0.5)
        || data[750].__vftable != (CObject_vtbl *)(int)(CMFCToolBar::m_dblLargeImageRatio
                                                      * (double)(int)data[746].__vftable
                                                      + 0.5) )
      {
        v5 = (double)(int)data[744].__vftable;
        data[747].__vftable = (CObject_vtbl *)v4;
        v6 = (int)(v5 * CMFCToolBar::m_dblLargeImageRatio + 0.5);
        v7 = (double)(int)data[745].__vftable;
        data[748].__vftable = (CObject_vtbl *)v6;
        v8 = (int)(v7 * CMFCToolBar::m_dblLargeImageRatio + 0.5);
        v9 = (double)(int)data[746].__vftable;
        data[749].__vftable = (CObject_vtbl *)v8;
        v10 = (int)(v9 * CMFCToolBar::m_dblLargeImageRatio + 0.5);
LABEL_20:
        data[750].__vftable = (CObject_vtbl *)v10;
LABEL_21:
        data->__vftable[43].dtr_CObject(this: data);
        if ( data[705].__vftable != nullptr )
        {
          Parent = GetParent(hWnd: (HWND)data[8].__vftable);
          v12 = CWnd::FromHandle(hWnd: Parent);
          v13 = AfxDynamicDownCast(pClass: &CBasePane::classCBasePane, pObject: v12);
          if ( v13 != nullptr )
            v13->__vftable[43].dtr_CObject(this: v13);
        }
      }
    }
    else if ( CPoint::operator!=(this: (CPoint *)&data[747], point: *(tagPOINT *)&data[743].__vftable)
           || CPoint::operator!=(this: (CPoint *)&data[749], point: *(tagPOINT *)&data[745].__vftable) )
    {
      data[747].__vftable = data[743].__vftable;
      data[748].__vftable = data[744].__vftable;
      data[749].__vftable = data[745].__vftable;
      v10 = (int)data[746].__vftable;
      goto LABEL_20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE2DA
// Name: protected: void CMFCToolBar::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnWindowPosChanging(CMFCToolBar *this, tagWINDOWPOS *lpwndpos)
{
  HWND Parent; // eax
  CWnd *v4; // eax

  CWnd::Default(this);
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( AfxDynamicDownCast(pClass: &CMFCReBar::classCMFCReBar, pObject: v4) != nullptr )
    this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AE312
// Name: protected: void CMFCToolBar::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnKillFocus(CMFCToolBar *this, CWnd *pNewWnd)
{
  CMFCPopupMenu *v3; // eax

  CWnd::Default(this);
  if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    v3 = (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: pNewWnd);
    if ( v3 == nullptr || CMFCPopupMenu::GetParentToolBar(this: v3) != (CMFCToolBarMenuButton *)this )
      this->Deactivate(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE355
// Name: protected: long CMFCToolBar::OnGetButton(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnGetButton(CMFCToolBar *this, unsigned int wParam, int lParam)
{
  CMFCToolBarButton *ButtonStyle; // eax

  ButtonStyle = CMFCToolBar::GetButtonStyle(this, nIndex: wParam);
  *(_BYTE *)(lParam + 9) = (_BYTE)ButtonStyle;
  *(_BYTE *)(lParam + 8) = BYTE2(ButtonStyle);
  *(_DWORD *)(lParam + 4) = CMFCToolBar::GetItemID(this, nIndex: wParam);
  *(_DWORD *)lParam = 0;
  *(_DWORD *)(lParam + 12) = 0;
  *(_DWORD *)(lParam + 16) = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AE390
// Name: protected: virtual void CMFCToolBar::OnAfterDock(class CBasePane __near *,struct tagRECT const __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnAfterDock(
        CMFCToolBar *this,
        CBasePane *pBar,
        const tagRECT *lpRect,
        AFX_DOCK_METHOD dockMethod)
{
  HWND Parent; // eax
  CWnd *v6; // edi
  HWND__ *v7; // [esp-8h] [ebp-28h]
  HWND__ *m_hWnd; // [esp-4h] [ebp-24h]
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  this->m_bFloating = 0;
  Parent = GetParent(hWnd: m_hWnd);
  v6 = CWnd::FromHandle(hWnd: Parent);
  if ( v6 != nullptr )
  {
    v7 = this->m_hWnd;
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: v7, lpRect: &rect);
    CWnd::ScreenToClient(this: v6, lpRect: &rect);
    RedrawWindow(hWnd: v6->m_hWnd, lprcUpdate: &rect, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE40C
// Name: protected: virtual void CMFCToolBar::AccNotifyObjectFocusEvent(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::AccNotifyObjectFocusEvent(CMFCToolBar *this, int iButton)
{
  CMFCToolBar *m_hWnd; // esi
  CMFCToolBarButton *Button; // eax

  m_hWnd = this;
  if ( afxGlobalData.m_bEnableAccessibility != 0 )
  {
    Button = CMFCToolBar::GetButton(this, nIndex: iButton);
    if ( Button != nullptr )
    {
      Button->SetACCData(this: Button, a2: m_hWnd, a3: &m_hWnd->m_AccData);
      if ( m_hWnd != nullptr )
        m_hWnd = (CMFCToolBar *)m_hWnd->m_hWnd;
      NotifyWinEvent(event: 0x8005u, hwnd: (HWND)m_hWnd, idObject: -4, idChild: iButton + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE45A
// Name: public: void CMFCToolBar::AdjustSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CMFCToolBar::AdjustSize(CMFCToolBar *this@<ecx>, int a2@<edi>)
{
  CFrameWnd *v3; // eax
  CMFCToolBar_vtbl *v4; // edi
  int v5; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  int m_nMaxLen; // ecx
  HWND v9; // eax
  CWnd *v10; // eax
  CObject *v11; // eax
  int *v12; // esi
  CMFCToolBar_vtbl *v13; // eax
  int v14; // eax
  CMFCToolBar_vtbl *v15; // eax
  int cx; // ecx
  int bottom; // eax
  CMFCToolBar_vtbl *v18; // eax
  int v19; // edi
  int cy; // eax
  CPaneFrameWnd *v21; // edi
  HWND v22; // eax
  HWND__ *v23; // [esp-Ch] [ebp-44h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-40h]
  CFrameWnd *pParent; // [esp+8h] [ebp-30h]
  CSize sizeCurr; // [esp+Ch] [ebp-2Ch] BYREF
  CRect rect; // [esp+14h] [ebp-24h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-14h] BYREF

  v3 = AFXGetParentFrame(pWnd: this);
  pParent = v3;
  if ( v3 == nullptr || v3->m_hWnd == nullptr )
    return;
  v4 = this->__vftable;
  Rect.bottom = this->m_pParentDockBar == nullptr;
  v5 = v4->IsHorizontal(this);
  v4->CalcFixedLayout(this, result: &sizeCurr, a3: Rect.bottom, a4: v5);
  if ( sizeCurr.cx == 0x7FFF || sizeCurr.cy == 0x7FFF )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    Parent = GetParent(hWnd: m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    GetClientRect(hWnd: v7->m_hWnd, lpRect: &Rect);
    m_nMaxLen = this->m_nMaxLen;
    if ( sizeCurr.cx == 0x7FFF )
    {
      sizeCurr.cx = Rect.right - Rect.left;
      if ( m_nMaxLen != 0 && Rect.right - Rect.left >= m_nMaxLen )
        sizeCurr.cx = m_nMaxLen;
    }
    else
    {
      sizeCurr.cy = Rect.bottom - Rect.top;
      if ( m_nMaxLen != 0 && Rect.bottom - Rect.top >= m_nMaxLen )
        sizeCurr.cy = m_nMaxLen;
    }
  }
  v23 = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: v23, lpRect: &rect);
  v9 = GetParent(hWnd: this->m_hWnd);
  v10 = CWnd::FromHandle(hWnd: v9);
  v11 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: v10);
  if ( v11 != nullptr )
  {
    Rect.left = (int)v11[168].__vftable;
    Rect.top = (int)v11[169].__vftable;
    v12 = (int *)&v11[170];
    v13 = this->__vftable;
    Rect.right = *v12;
    Rect.bottom = v12[1];
    v13->SetWindowPos(
      this,
      a2: nullptr,
      a3: -1,
      a4: -1,
      a5: Rect.right - Rect.left,
      a6: Rect.bottom - Rect.top,
      a7: 22u,
      a8: nullptr);
  }
  else
  {
    v14 = rect.bottom - rect.top;
    if ( CMFCToolBar::m_bCustomizeMode != 0 )
    {
      if ( (v14 == sizeCurr.cy || sizeCurr.cy == 0x7FFF || this->IsHorizontal(this) == 0)
        && (rect.right - rect.left == sizeCurr.cx || sizeCurr.cx == 0x7FFF || this->IsHorizontal(this) != 0) )
      {
        goto LABEL_34;
      }
      this->SetWindowPos(this, a2: nullptr, a3: 0, a4: 0, a5: sizeCurr.cx, a6: sizeCurr.cy, a7: 22u, a8: nullptr);
    }
    else
    {
      if ( (v14 == sizeCurr.cy || sizeCurr.cy == 0x7FFF || this->IsHorizontal(this) == 0)
        && (rect.right - rect.left == sizeCurr.cx || sizeCurr.cx == 0x7FFF || this->IsHorizontal(this) != 0) )
      {
        goto LABEL_34;
      }
      v15 = this->__vftable;
      Rect.right = 0;
      Rect.bottom = 0;
      ((void (__thiscall *)(CMFCToolBar *, int *, int))v15->GetMinSize)(a1: this, a2: &Rect.right, a3: a2);
      cx = sizeCurr.cx;
      if ( Rect.right > sizeCurr.cx )
        cx = Rect.right;
      bottom = Rect.bottom;
      if ( Rect.bottom <= sizeCurr.cy )
        bottom = sizeCurr.cy;
      ((void (__thiscall *)(CMFCToolBar *, _DWORD, _DWORD, _DWORD, int, int, int))this->SetWindowPos)(
        a1: this,
        a2: 0,
        a3: 0,
        a4: 0,
        a5: cx,
        a6: bottom,
        a7: 22);
    }
    CPane::UpdateVirtualRect(this);
  }
LABEL_34:
  if ( this->IsFloating(this) == 0
    && this->IsVisible(this) != 0
    && this->m_pParentDockBar != nullptr
    && this->m_pDockBarRow != nullptr )
  {
    v18 = this->__vftable;
    memset(&Rect, 0, sizeof(Rect));
    v19 = v18->IsHorizontal(this);
    CDockingPanesRow::GetClientRect(this: this->m_pDockBarRow, rect: (CRect *)&Rect);
    if ( Rect.bottom - Rect.top == sizeCurr.cy || v19 == 0 )
    {
      if ( Rect.right - Rect.left == sizeCurr.cx || v19 != 0 )
      {
LABEL_47:
        if ( CMFCToolBar::m_bCustomizeMode != 0 )
        {
          CPane::UpdateVirtualRect(this, sizeNew: sizeCurr);
          this->m_pDockBarRow->ArrangePanes(this: this->m_pDockBarRow, a2: this);
        }
LABEL_53:
        pParent->RecalcLayout(this: pParent, a2: 1);
        return;
      }
      Rect.right = sizeCurr.cx + Rect.left;
    }
    else
    {
      Rect.bottom = sizeCurr.cy + Rect.top;
    }
    cy = sizeCurr.cy;
    if ( v19 == 0 )
      cy = sizeCurr.cx;
    CDockSite::ResizeRow(this: this->m_pParentDockBar, pRow: this->m_pDockBarRow, nNewSize: cy, bAdjustLayout: 1);
    goto LABEL_47;
  }
  v21 = this->GetParentMiniFrame(this, a2: 0);
  if ( v21 != nullptr )
  {
    v22 = GetParent(hWnd: this->m_hWnd);
    if ( CWnd::FromHandle(hWnd: v22) == v21 )
    {
      v21->SizeToContent(this: v21);
      RedrawWindow(hWnd: v21->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      return;
    }
  }
  if ( CObject::IsKindOf(this, pClass: &CMFCDropDownToolBar::classCMFCDropDownToolBar) == 0 )
    goto LABEL_53;
}

//------------------------------------------------------------------------------
// Address: 0x103AE7B3
// Name: protected: virtual void CMFCToolBar::OnCalcSeparatorRect(class CMFCToolBarButton __near *,class CRect __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnCalcSeparatorRect(
        CMFCToolBar *this,
        CMFCToolBarButton *pButton,
        CRect *rectSeparator,
        int bHorz)
{
  int bottom; // eax
  CRect rectClient; // [esp+Ch] [ebp-14h] BYREF

  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
  *rectSeparator = pButton->m_rect;
  if ( pButton->m_bWrap != 0 && bHorz != 0 )
  {
    rectSeparator->left = rectClient.left;
    rectSeparator->right = rectClient.right;
    bottom = pButton->m_rect.bottom;
    rectSeparator->top = bottom;
    rectSeparator->bottom = bottom + 5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE826
// Name: protected: void CMFCToolBar::OnShowWindow(int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnShowWindow(CMFCToolBar *this, int bShow, unsigned int nStatus)
{
  CWnd::Default(this);
  if ( CMFCToolBar::m_bCustomizeMode != 0 && g_pWndCustomize != nullptr && this->m_bLocked == 0 )
  {
    if ( bShow != 0 )
    {
      CMFCToolBarsCustomizeDialog::ShowToolBar(this: g_pWndCustomize, pToolBar: this, bShow: 1);
    }
    else
    {
      CMFCToolBarsCustomizeDialog::ShowToolBar(this: g_pWndCustomize, pToolBar: this, bShow: 0);
      if ( CMFCToolBar::m_pSelToolbar == this )
      {
        CMFCToolBar::m_pSelToolbar = nullptr;
        this->m_iSelected = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE881
// Name: protected: void CMFCToolBar::OnRButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnRButtonDown(CMFCToolBar *this, unsigned int nFlags, CPoint point)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  HWND v6; // eax
  CWnd *v7; // eax

  CWnd::Default(this);
  if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    if ( AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v5) != nullptr )
    {
      v6 = GetParent(hWnd: this->m_hWnd);
      v7 = CWnd::FromHandle(hWnd: v6);
      CWnd::SetFocus(this: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE8CE
// Name: protected: void CMFCToolBar::RedrawCustomizeButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::RedrawCustomizeButton(CMFCToolBar *this)
{
  CSize *ExtraSize; // eax
  CSize result; // [esp+4h] [ebp-1Ch] BYREF
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  if ( this != nullptr && this->m_hWnd != nullptr && this->m_pCustomizeBtn != nullptr )
  {
    this->m_pCustomizeBtn->GetInvalidateRect(this: this->m_pCustomizeBtn, result: &rect);
    ExtraSize = CMFCCustomizeButton::GetExtraSize(this: this->m_pCustomizeBtn, &result);
    InflateRect(lprc: &rect, dx: ExtraSize->cx, dy: ExtraSize->cy);
    rect.right += 10;
    rect.bottom += 10;
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &rect, hrgnUpdate: nullptr, flags: 0x505u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AE950
// Name: public: void CAccessibilityData::Clear(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAccessibilityData::Clear(CAccessibilityData *this)
{
  this->m_rectAccLocation.left = 0;
  this->m_rectAccLocation.top = 0;
  this->m_rectAccLocation.right = 0;
  this->m_ptAccHit.x = 0;
  this->m_nAccRole = 0;
  this->m_bAccState = 0;
  this->m_nAccHit = 0;
  this->m_rectAccLocation.bottom = 0;
  this->m_ptAccHit.y = 0;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAccName);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAccValue);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strDescription);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAccKeys);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAccHelp);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAccName);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strAccDefAction);
}

//------------------------------------------------------------------------------
// Address: 0x103AE9C1
// Name: public: static int CMFCToolBar::IsCommandPermitted(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CMFCToolBar::IsCommandPermitted(HWND__ *uiCmd)
{
  return CList<unsigned int,unsigned int>::Find(
           this: (CList<HWND__ *,HWND__ *> *)&CMFCToolBar::m_lstUnpermittedCommands,
           searchValue: uiCmd,
           startAfter: nullptr) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AE9DE
// Name: public: static int CMFCToolBar::IsBasicCommand(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CMFCToolBar::IsBasicCommand(HWND__ *uiCmd)
{
  return CList<unsigned int,unsigned int>::Find(
           this: (CList<HWND__ *,HWND__ *> *)&CMFCToolBar::m_lstBasicCommands,
           searchValue: uiCmd,
           startAfter: nullptr) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AE9FC
// Name: protected: virtual int CMFCToolBar::InsertButton(class CMFCToolBarButton __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::InsertButton(CMFCToolBar *this, CMFCToolBarButton *pButton, int iInsertAt)
{
  int v5; // edi
  int m_nCount; // eax
  __POSITION *Index; // eax

  if ( pButton == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  if ( !CMFCToolBar::IsCommandPermitted(uiCmd: (HWND__ *)pButton->m_nID) )
    return -1;
  v5 = iInsertAt;
  if ( iInsertAt == -1 )
    goto LABEL_10;
  if ( iInsertAt < 0 )
    return -1;
  m_nCount = this->m_Buttons.m_nCount;
  if ( iInsertAt > m_nCount )
    return -1;
  if ( iInsertAt == m_nCount )
  {
LABEL_10:
    if ( this->m_pCustomizeBtn == nullptr )
    {
      CPtrList::AddTail(this: &this->m_Buttons, newElement: pButton);
      pButton->OnChangeParentWnd(this: pButton, a2: this);
      return this->m_Buttons.m_nCount - 1;
    }
    v5 = this->m_Buttons.m_nCount - 1;
  }
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_Buttons, nIndex: v5);
  if ( Index == nullptr )
    goto LABEL_2;
  CObList::InsertBefore(this: &this->m_Buttons, position: Index, newElement: pButton);
  pButton->OnChangeParentWnd(this: pButton, a2: this);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103AEA9B
// Name: public: virtual void CMFCToolBar::SetButtonStyle(int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::SetButtonStyle(CMFCToolBar *this, int nIndex, unsigned int nStyle)
{
  CMFCToolBarButton *Button; // eax
  unsigned int m_nStyle; // esi
  unsigned int v6; // edi

  Button = CMFCToolBar::GetButton(this, nIndex);
  if ( Button != nullptr )
  {
    m_nStyle = Button->m_nStyle;
    v6 = nStyle;
    if ( m_nStyle != nStyle )
    {
      if ( (nStyle & 0x40000) != 0 )
        v6 = nStyle & 0xFFFDFFFF;
      Button->SetStyle(this: Button, a2: v6);
      if ( (v6 & m_nStyle & 0x20000) == 0 )
        CMFCToolBar::InvalidateButton(this, nIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AEAEF
// Name: protected: void CMFCToolBar::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnLButtonDown(CMFCToolBar *this, WPARAM nFlags, CPoint point)
{
  CMFCToolBar *v4; // eax
  CMFCToolBar *v5; // ecx
  int m_iSelected; // edx
  HWND Parent; // eax
  CWnd *v8; // eax
  HWND v9; // eax
  CWnd *v10; // eax
  int v11; // ecx
  CMFCToolBarButton *Button; // edi
  int v13; // eax
  CMFCToolBar_vtbl *v14; // edx
  CMFCToolBarButton *v15; // eax
  bool v16; // zf
  CMFCToolBarButton *m_pDragButton; // ecx
  HWND v18; // eax
  CMFCToolBarButton *v19; // ecx
  CMFCToolBarButton_vtbl *v20; // eax
  HWND__ *m_hWnd; // edi
  CMFCToolBarButton *v22; // eax
  CMFCToolBar_vtbl *v23; // edi
  int v24; // eax
  HWND v25; // eax
  CWnd *v26; // eax
  HWND v27; // eax
  CWnd *v28; // eax
  HWND v29; // eax
  CWnd *v30; // eax
  HWND v31; // eax
  CWnd *v32; // eax
  HWND v33; // eax
  CWnd *v34; // eax
  CObject *v35; // eax
  CMFCToolBarButton *v36; // eax
  CMFCToolBar_vtbl *v37; // edx
  CMFCToolBar_vtbl *v38; // eax
  HWND v39; // eax
  int v40; // [esp-8h] [ebp-7Ch]
  int v41; // [esp-4h] [ebp-78h]
  int v42; // [esp-4h] [ebp-78h]
  int v43; // [esp-4h] [ebp-78h]
  COleDataSource v44; // [esp+10h] [ebp-64h] BYREF
  tagPOINT Point; // [esp+44h] [ebp-30h] BYREF
  int v46; // [esp+4Ch] [ebp-28h]
  int nIndex; // [esp+50h] [ebp-24h]
  tagRECT RectStartDrag; // [esp+54h] [ebp-20h] BYREF
  int v49; // [esp+70h] [ebp-4h]

  nIndex = ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y);
  v4 = CMFCToolBar::m_pSelToolbar;
  if ( CMFCToolBar::m_pSelToolbar == this )
    goto LABEL_5;
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
  {
    v5 = CMFCToolBar::m_pSelToolbar;
    CMFCToolBar::m_pSelToolbar = this;
    if ( v4 != nullptr )
    {
      m_iSelected = v4->m_iSelected;
      v4->m_iSelected = -1;
      CMFCToolBar::InvalidateButton(this: v5, nIndex: m_iSelected);
    }
LABEL_5:
    if ( CMFCToolBar::m_bCustomizeMode != 0 )
      goto LABEL_8;
  }
  Parent = GetParent(hWnd: this->m_hWnd);
  v8 = CWnd::FromHandle(hWnd: Parent);
  if ( AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v8) != nullptr )
  {
    v9 = GetParent(hWnd: this->m_hWnd);
    v10 = CWnd::FromHandle(hWnd: v9);
    CWnd::SetFocus(this: v10);
  }
LABEL_8:
  if ( nIndex < 0 )
  {
    this->m_iButtonCapture = -1;
    if ( CMFCToolBar::m_bCustomizeMode != 0 && this->m_bLocked == 0 )
    {
      v11 = this->m_iSelected;
      this->m_iSelected = -1;
      if ( v11 != -1 )
      {
        CMFCToolBar::InvalidateButton(this, nIndex: v11);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      this->OnChangeHot(this, a2: -1);
    }
    if ( this->CanFloat(this) != 0 )
      SetCursor(hCursor: afxGlobalData.m_hcurSizeAll);
    CPane::OnLButtonDown(this, nFlags, point);
    return;
  }
  Button = CMFCToolBar::GetButton(this, nIndex);
  if ( Button == nullptr )
    return;
  this->AccNotifyObjectFocusEvent(this, a2: nIndex);
  CMFCToolBar::m_bAltCustomizeMode = 0;
  if ( CMFCToolBar::m_bAltCustomization != 0 && this->AllowAltCustomization(this) != 0 )
  {
    if ( CMFCToolBar::m_bCustomizeMode != 0 )
      goto LABEL_25;
    if ( GetAsyncKeyState(vKey: 18) < 0 )
    {
      v13 = nIndex;
      CMFCToolBar::m_bAltCustomizeMode = 1;
      this->m_iHighlighted = -1;
      this->m_iSelected = v13;
      CMFCToolBar::m_pSelToolbar = this;
    }
  }
  if ( CMFCToolBar::m_bCustomizeMode == 0 && CMFCToolBar::m_bAltCustomizeMode == 0 )
    goto LABEL_67;
LABEL_25:
  if ( this->m_bLocked != 0 || this->m_bDisableCustomize != 0 )
  {
LABEL_67:
    v42 = nIndex;
    this->m_iButtonCapture = nIndex;
    CMFCToolBar::UpdateButton(this, nIndex: v42);
    if ( (Button->m_nStyle & 0x40000) != 0
      && CObject::IsKindOf(this: Button, pClass: &CMFCDropDownToolbarButton::classCMFCDropDownToolbarButton) == 0 )
    {
      this->m_iButtonCapture = -1;
      return;
    }
    v43 = nIndex;
    Button->m_nStyle |= 0x20000u;
    CMFCToolBar::InvalidateButton(this, nIndex: v43);
    UpdateWindow(hWnd: this->m_hWnd);
    this->ShowCommandMessageString(this, a2: Button->m_nID);
    if ( Button->OnClick(this: Button, a2: this, a3: 0) != 0 )
    {
      if ( CPtrList::Find(this: &this->m_Buttons, searchValue: Button, startAfter: nullptr) != nullptr )
        Button->m_nStyle &= ~0x20000u;
      v38 = this->__vftable;
      this->m_iButtonCapture = -1;
      this->m_iHighlighted = -1;
      v38->OnChangeHot(this, a2: -1);
      CMFCToolBar::InvalidateButton(this, nIndex);
      UpdateWindow(hWnd: this->m_hWnd);
    }
    else
    {
      v39 = SetCapture(hWnd: this->m_hWnd);
      this->m_pWndLastCapture = CWnd::FromHandle(hWnd: v39);
    }
    goto LABEL_75;
  }
  v14 = this->__vftable;
  v46 = this->m_iSelected;
  v40 = nIndex;
  this->m_iSelected = nIndex;
  memset(&RectStartDrag, 0, sizeof(RectStartDrag));
  v14->GetItemRect(this, a2: v40, a3: &RectStartDrag);
  if ( v46 != -1 )
    CMFCToolBar::InvalidateButton(this, nIndex: v46);
  v15 = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  this->m_pDragButton = v15;
  if ( v15 == nullptr )
    AfxThrowInvalidArgException();
  this->m_bIsDragCopy = nFlags & 8;
  if ( v15->IsEditable(this: v15) == 0 )
  {
    this->m_iSelected = -1;
    v16 = v46 == -1;
    this->m_pDragButton = nullptr;
    if ( !v16 )
      CMFCToolBar::InvalidateButton(this, nIndex: v46);
    return;
  }
  CMFCToolBar::InvalidateButton(this, nIndex);
  UpdateWindow(hWnd: this->m_hWnd);
  if ( this->m_pDragButton->CanBeStretched(this: this->m_pDragButton) != 0
    && abs(lnumber: point.x - RectStartDrag.right) <= 6
    && CMFCToolBar::m_bAltCustomizeMode == 0 )
  {
    m_pDragButton = this->m_pDragButton;
    this->m_bStretchButton = 1;
    this->m_rectTrack.left = m_pDragButton->m_rect.left;
    this->m_rectTrack.top = m_pDragButton->m_rect.top;
    this->m_rectTrack.right = m_pDragButton->m_rect.right;
    this->m_rectTrack.bottom = m_pDragButton->m_rect.bottom;
    if ( m_pDragButton->GetHwnd(this: m_pDragButton) != nullptr )
      InflateRect(lprc: &this->m_rectTrack, dx: 2, dy: 2);
    v18 = SetCapture(hWnd: this->m_hWnd);
    this->m_pWndLastCapture = CWnd::FromHandle(hWnd: v18);
    SetCursor(hCursor: afxGlobalData.m_hcurStretch);
    goto LABEL_75;
  }
  if ( this->m_pDragButton->CanBeStored(this: this->m_pDragButton) == 0
    || this->m_pDragButton->OnBeforeDrag(this: this->m_pDragButton) == 0 )
  {
    this->m_pDragButton = nullptr;
LABEL_75:
    if ( CMFCToolBar::m_bAltCustomizeMode != 0 )
    {
      CMFCToolBar::m_bAltCustomizeMode = 0;
      CMFCToolBar::m_pSelToolbar = nullptr;
      CMFCToolBar::SetCustomizeMode(bSet: 0);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
    }
    return;
  }
  COleDataSource::COleDataSource(this: &v44);
  v19 = this->m_pDragButton;
  v20 = v19->__vftable;
  v49 = 0;
  v20->PrepareDrag(this: v19, a2: &v44);
  this->ShowCommandMessageString(this, a2: Button->m_nID);
  CMFCToolBar::m_DropSource.m_bDragStarted = 0;
  m_hWnd = this->m_hWnd;
  this->m_ptStartDrag = point;
  if ( CMFCToolBar::m_bAltCustomizeMode != 0 )
    CMFCToolBar::m_bCustomizeMode = 1;
  v46 = COleDataSource::DoDragDrop(
          this: &v44,
          dwEffects: 3u,
          lpRectStartDrag: &RectStartDrag,
          pDropSource: &CMFCToolBar::m_DropSource);
  if ( IsWindow(hWnd: m_hWnd) )
  {
    Point.x = 0;
    Point.y = 0;
    GetCursorPos(lpPoint: &Point);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &Point);
    if ( CMFCToolBar::m_DropSource.m_bDragStarted == 0 || PtInRect(lprc: &RectStartDrag, pt: Point) )
    {
      v37 = this->__vftable;
      v41 = nIndex;
      this->m_iHighlighted = nIndex;
      v37->OnChangeHot(this, a2: v41);
    }
    else if ( v46 == 1
           || (v22 = this->m_pDragButton) == nullptr
           || CMFCToolBar::m_DropSource.m_bEscapePressed != 0
           || this->OnBeforeRemoveButton(this, a2: v22, a3: v46) == 0 )
    {
      v36 = this->m_pDragButton;
      if ( v36 != nullptr )
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &v36->m_rect, bErase: true);
    }
    else
    {
      v23 = this->__vftable;
      v24 = CMFCToolBar::ButtonToIndex(this, pButton: this->m_pDragButton);
      v23->RemoveButton(this, a2: v24);
      this->AdjustLocations(this);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
      this->AdjustSizeImmediate(this, a2: 1);
      v25 = GetParent(hWnd: this->m_hWnd);
      v26 = CWnd::FromHandle(hWnd: v25);
      if ( v26 != nullptr && v26->m_hWnd != nullptr )
      {
        v27 = GetParent(hWnd: this->m_hWnd);
        v28 = CWnd::FromHandle(hWnd: v27);
        RedrawWindow(hWnd: v28->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
      }
      if ( CMFCToolBar::m_bAltCustomizeMode == 0 )
      {
        this->AdjustLayout(this);
        RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
      }
      v29 = GetParent(hWnd: this->m_hWnd);
      v30 = CWnd::FromHandle(hWnd: v29);
      if ( CObject::IsKindOf(this: v30, pClass: &CMFCTabCtrl::classCMFCTabCtrl) != 0 )
      {
        v31 = GetParent(hWnd: this->m_hWnd);
        v32 = CWnd::FromHandle(hWnd: v31);
        v33 = GetParent(hWnd: v32->m_hWnd);
        v34 = CWnd::FromHandle(hWnd: v33);
        v35 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v34);
        if ( v35 != nullptr )
          ((void (__thiscall *)(CObject *))v35->__vftable[43].Serialize)(a1: v35);
      }
    }
    this->m_ptStartDrag.y = -1;
    v49 = -1;
    this->m_pDragButton = nullptr;
    this->m_ptStartDrag.x = -1;
    COleDataSource::~COleDataSource(this: &v44);
    goto LABEL_75;
  }
  if ( CMFCToolBar::m_bAltCustomizeMode != 0 )
  {
    CMFCToolBar::m_bCustomizeMode = 0;
    CMFCToolBar::m_bAltCustomizeMode = 0;
    CMFCToolBar::m_pSelToolbar = nullptr;
  }
  v49 = -1;
  COleDataSource::~COleDataSource(this: &v44);
}

//------------------------------------------------------------------------------
// Address: 0x103AF14D
// Name: protected: void CMFCToolBar::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnMouseMove(CMFCToolBar *this, unsigned int nFlags, CPoint point)
{
  CMFCToolBar *v3; // ebx
  int m_iHighlighted; // esi
  CMFCToolBar_vtbl *v5; // edx
  int v6; // eax
  bool v7; // zf
  int v8; // edi
  HWND Focus; // eax
  CMFCToolBarMenuButton *DroppedDownMenu; // eax
  CMFCToolBarButton *v11; // esi
  CMFCToolBarButton *Button; // eax
  unsigned int m_nStyle; // eax
  int v14; // eax
  HWND__ *v15; // eax
  int m_iButtonCapture; // eax
  CWnd *Owner; // eax
  int v18; // eax
  CMFCToolBarButton *v19; // eax
  unsigned int v20; // edx
  int v21; // ecx
  unsigned int v22; // eax
  int v23; // eax
  int v24; // eax
  BOOL v25; // esi
  CMFCToolBarButton *v26; // eax
  CObject *v27; // eax
  int v28; // eax
  HWND m_hWnd; // [esp-10h] [ebp-6Ch]
  HWND v30; // [esp-8h] [ebp-64h]
  CClientDC v31; // [esp+10h] [ebp-4Ch] BYREF
  tagTRACKMOUSEEVENT ptme; // [esp+24h] [ebp-38h] BYREF
  int v33; // [esp+34h] [ebp-28h]
  int nIndex; // [esp+38h] [ebp-24h]
  tagRECT RectLast; // [esp+3Ch] [ebp-20h] BYREF
  int v36; // [esp+58h] [ebp-4h]

  v3 = this;
  if ( this->m_bDragMode != 0 )
  {
LABEL_72:
    CPane::OnMouseMove(this, nFlags, point);
    return;
  }
  if ( CMFCToolBar::m_bCustomizeMode == 0 || this->m_bLocked != 0 )
  {
    if ( CPoint::operator!=(this: &this->m_ptLastMouse, point: (tagPOINT)-1LL)
      && abs(lnumber: v3->m_ptLastMouse.x - point.x) < 1
      && abs(lnumber: v3->m_ptLastMouse.y - point.y) < 1 )
    {
      v3->m_ptLastMouse = point;
      return;
    }
    m_iHighlighted = v3->m_iHighlighted;
    v5 = v3->__vftable;
    v3->m_ptLastMouse = point;
    nIndex = m_iHighlighted;
    v6 = ((int (__thiscall *)(CMFCToolBar *, int, int))v5->HitTest)(a1: v3, a2: point.x, a3: point.y);
    v7 = v3->m_bLeaveFocus == 0;
    v8 = v6;
    v3->m_iHighlighted = v6;
    if ( !v7 && v6 == -1 && (Focus = GetFocus(), CWnd::FromHandle(hWnd: Focus) == v3)
      || (DroppedDownMenu = CMFCToolBar::GetDroppedDownMenu(this: v3, pIndex: nullptr)) != nullptr
      && DroppedDownMenu->IsExclusive(this: DroppedDownMenu) != 0 )
    {
      v3->m_iHighlighted = m_iHighlighted;
      return;
    }
    if ( v3->m_iHighlighted == -1 )
    {
      v11 = nullptr;
    }
    else
    {
      Button = CMFCToolBar::GetButton(this: v3, nIndex: v3->m_iHighlighted);
      v11 = Button;
      if ( Button != nullptr )
      {
        m_nStyle = Button->m_nStyle;
        if ( (m_nStyle & 1) != 0 || (m_nStyle & 0x40000) != 0 && v3->AllowSelectDisabled(this: v3) == 0 )
          v3->m_iHighlighted = -1;
      }
    }
    if ( v3->m_bMenuMode != 0 && v3->m_iHighlighted == -1 && afxGlobalData.m_bEnableAccessibility != 0 )
    {
      v14 = ((int (__thiscall *)(CMFCToolBar *, int, int))v3->HitTest)(a1: v3, a2: point.x, a3: point.y);
      if ( v14 != -1 && v14 != v3->m_iAccHotItem )
      {
        m_hWnd = v3->m_hWnd;
        v3->m_iAccHotItem = v14;
        SetTimer(hWnd: m_hWnd, nIDEvent: 0x14u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
      }
    }
    if ( v3->m_bTracked == 0 )
    {
      v15 = v3->m_hWnd;
      ptme.dwHoverTime = -1;
      ptme.hwndTrack = v15;
      v3->m_bTracked = 1;
      ptme.cbSize = 16;
      ptme.dwFlags = 2;
      AFXTrackMouse(&ptme);
    }
    if ( nIndex != v8 )
    {
      if ( v8 != -1
        && (v3->m_bMenuMode != 0
         || (m_iButtonCapture = v3->m_iButtonCapture, v8 == m_iButtonCapture)
         || m_iButtonCapture == -1) )
      {
        if ( v11 != nullptr )
          v3->ShowCommandMessageString(this: v3, a2: v11->m_nID);
      }
      else if ( (v3->m_iButtonCapture == -1 || v3->m_bMenuMode != 0 && v8 == -1)
             && CMFCToolBar::m_hookMouseHelp == nullptr )
      {
        Owner = CWnd::GetOwner(this: v3);
        SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
      }
    }
    if ( nIndex != v3->m_iHighlighted )
    {
      v18 = v3->m_iButtonCapture;
      v33 = 0;
      if ( v18 != -1 )
      {
        v19 = CMFCToolBar::GetButton(this: v3, nIndex: v18);
        if ( v19 == nullptr )
          AfxThrowInvalidArgException();
        v20 = v19->m_nStyle;
        v21 = v3->m_iButtonCapture;
        v22 = v20 & 0xFFFDFFFF;
        if ( v3->m_iHighlighted == v21 )
          v22 |= 0x20000u;
        if ( v22 != v20 )
        {
          v3->SetButtonStyle(this: v3, a2: v21, a3: v22);
          v33 = 1;
        }
      }
      if ( (v3->m_bMenuMode != 0 || (v23 = v3->m_iButtonCapture) == -1 || nIndex == v23) && nIndex != -1 )
      {
        CMFCToolBar::InvalidateButton(this: v3, nIndex);
        v33 = 1;
      }
      if ( (v3->m_bMenuMode != 0 || (v24 = v3->m_iButtonCapture) == -1 || v3->m_iHighlighted == v24)
        && v3->m_iHighlighted != -1 )
      {
        CMFCToolBar::InvalidateButton(this: v3, nIndex: v3->m_iHighlighted);
        v33 = 1;
        if ( afxGlobalData.m_bEnableAccessibility != 0 )
        {
          v25 = false;
          v26 = CMFCToolBar::GetButton(this: v3, nIndex: v3->m_iHighlighted);
          v27 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: v26);
          if ( v27 != nullptr )
            v25 = v27[36].__vftable != nullptr;
          v28 = ((int (__thiscall *)(CMFCToolBar *, int, int))v3->HitTest)(a1: v3, a2: point.x, a3: point.y);
          if ( v28 != v3->m_iAccHotItem )
          {
            v30 = v3->m_hWnd;
            v3->m_iAccHotItem = v28;
            KillTimer(hWnd: v30, uIDEvent: 0x14u);
            if ( v25 )
              SetTimer(hWnd: v3->m_hWnd, nIDEvent: 0x14u, uElapse: 0x514u, lpTimerFunc: nullptr);
            else
              SetTimer(hWnd: v3->m_hWnd, nIDEvent: 0x14u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
          }
        }
      }
      v3->OnChangeHot(this: v3, a2: v3->m_iHighlighted);
      if ( v33 != 0 )
        UpdateWindow(hWnd: v3->m_hWnd);
    }
    this = v3;
    goto LABEL_72;
  }
  if ( this->m_bStretchButton != 0 )
  {
    if ( point.x - this->m_pDragButton->m_rect.left >= 5 )
    {
      CClientDC::CClientDC(this: &v31, pWnd: this);
      v36 = 0;
      RectLast = (tagRECT)v3->m_rectTrack;
      v3->m_rectTrack.right = point.x;
      CDC::DrawDragRect(
        this: &v31,
        lpRect: &v3->m_rectTrack,
        size: (tagSIZE)0x200000002LL,
        lpRectLast: &RectLast,
        sizeLast: (tagSIZE)0x200000002LL,
        pBrush: nullptr,
        pBrushLast: nullptr);
      v36 = -1;
      CClientDC::~CClientDC(this: &v31);
    }
    SetCursor(hCursor: afxGlobalData.m_hcurStretch);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AF578
// Name: protected: void CMFCToolBar::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnLButtonUp(CMFCToolBar *this, WPARAM nFlags, CPoint point)
{
  CMFCToolBar *v3; // ebx
  CMFCToolBarButton *m_pDragButton; // eax
  int v5; // esi
  CWnd *m_pWndLastCapture; // eax
  HWND v7; // eax
  CWnd *v8; // eax
  HWND v9; // eax
  int v10; // eax
  CMFCToolBarButton *Button; // eax
  CMFCToolBarButton *v12; // esi
  int v13; // eax
  unsigned int v14; // edi
  unsigned int m_nStyle; // eax
  CWnd *Owner; // eax
  HWND__ *v17; // eax
  int v18; // edi
  CWnd *v19; // eax
  CMFCToolBarButton *v20; // eax
  HWND m_hWnd; // [esp-10h] [ebp-38h]
  int m_iButtonCapture; // [esp-4h] [ebp-2Ch]
  int bIsSystemMenuButton; // [esp+1Ch] [ebp-Ch]
  unsigned int nNewStyle; // [esp+20h] [ebp-8h]
  HWND__ *hwndSaved; // [esp+24h] [ebp-4h]
  HWND__ *hwndSaveda; // [esp+24h] [ebp-4h]
  unsigned int nIDCmd; // [esp+30h] [ebp+8h]

  v3 = this;
  if ( CMFCToolBar::m_bCustomizeMode != 0 && this->m_bLocked == 0 )
  {
    if ( this->m_bStretchButton != 0 )
    {
      m_pDragButton = this->m_pDragButton;
      v5 = point.x - m_pDragButton->m_rect.left;
      if ( v5 >= 5 && abs(lnumber: m_pDragButton->m_rect.right - point.x) > 6 )
      {
        v3->m_pDragButton->OnSize(this: v3->m_pDragButton, a2: v5);
        v3->AdjustLayout(this: v3);
      }
      SetRectEmpty(lprc: &v3->m_rectTrack);
      m_hWnd = v3->m_hWnd;
      v3->m_pDragButton = nullptr;
      v3->m_bStretchButton = 0;
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
      ReleaseCapture();
      m_pWndLastCapture = v3->m_pWndLastCapture;
      if ( m_pWndLastCapture != nullptr )
      {
        v7 = SetCapture(hWnd: m_pWndLastCapture->m_hWnd);
        CWnd::FromHandle(hWnd: v7);
        v3->m_pWndLastCapture = nullptr;
      }
      v3->AdjustSizeImmediate(this: v3, a2: 1);
    }
    this = v3;
    goto LABEL_11;
  }
  if ( this->m_bDragMode != 0 )
  {
LABEL_11:
    CPane::OnLButtonUp(this, nFlags, point);
    return;
  }
  if ( this->m_iButtonCapture == -1 )
  {
    if ( ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y) != -1 )
      return;
    CPane::OnLButtonUp(this: v3, nFlags, point);
    goto LABEL_47;
  }
  ReleaseCapture();
  v8 = v3->m_pWndLastCapture;
  if ( v8 != nullptr )
  {
    v9 = SetCapture(hWnd: v8->m_hWnd);
    CWnd::FromHandle(hWnd: v9);
    v3->m_pWndLastCapture = nullptr;
  }
  v10 = ((int (__thiscall *)(CMFCToolBar *, int, int))v3->HitTest)(a1: v3, a2: point.x, a3: point.y);
  m_iButtonCapture = v3->m_iButtonCapture;
  v3->m_iHighlighted = v10;
  Button = CMFCToolBar::GetButton(this: v3, nIndex: m_iButtonCapture);
  v12 = Button;
  if ( Button != nullptr )
  {
    nIDCmd = 0;
    bIsSystemMenuButton = CObject::IsKindOf(
                            this: Button,
                            pClass: &CMFCToolBarMenuButtonsButton::classCMFCToolBarMenuButtonsButton);
    v13 = v3->m_iButtonCapture;
    v14 = v12->m_nStyle & 0xFFFDFFFF;
    nNewStyle = v14;
    if ( v13 == v3->m_iHighlighted )
    {
      hwndSaved = (HWND__ *)v3->m_iButtonCapture;
      if ( ((int (__thiscall *)(CMFCToolBar *, int, int))v3->HitTest)(a1: v3, a2: point.x, a3: point.y) == v13 )
      {
        CMFCToolBar::UpdateButton(this: v3, nIndex: (int)hwndSaved);
        m_nStyle = v12->m_nStyle;
        if ( (m_nStyle & 0x40000) == 0 )
        {
          nIDCmd = v12->m_nID;
          if ( (m_nStyle & 2) != 0 )
          {
            if ( (v14 & 0x100000) != 0 )
              v14 &= ~0x100000u;
            nNewStyle = v14 ^ 0x10000;
          }
        }
      }
    }
    if ( CMFCToolBar::m_hookMouseHelp == nullptr )
    {
      Owner = CWnd::GetOwner(this: v3);
      SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
    }
    v17 = v3->m_hWnd;
    v18 = v3->m_iButtonCapture;
    v3->m_iButtonCapture = -1;
    v3->m_iHighlighted = -1;
    hwndSaveda = v17;
    v3->RestoreFocus(this: v3);
    if ( ((int (__thiscall *)(CMFCToolBar *, int, int))v3->HitTest)(a1: v3, a2: point.x, a3: point.y) != v18
      || v3->OnSendCommand(this: v3, a2: v12) != 0
      || nIDCmd == 0
      || nIDCmd == -1 )
    {
      if ( IsWindow(hWnd: hwndSaveda) && !IsIconic(hWnd: hwndSaveda) && IsZoomed(hWnd: hwndSaveda) )
        v12->OnClickUp(this: v12);
    }
    else
    {
      CMFCToolBar::InvalidateButton(this: v3, nIndex: v18);
      UpdateWindow(hWnd: v3->m_hWnd);
      CMFCCmdUsageCount::AddCmd(this: &CMFCToolBar::m_UsageCount, uiCmd: nIDCmd);
      if ( v12->OnClickUp(this: v12) == 0
        && (afxUserToolsManager == nullptr
         || CUserToolsManager::InvokeTool(this: afxUserToolsManager, uiCmdId: nIDCmd) == 0) )
      {
        v19 = CWnd::GetOwner(this: v3);
        SendMessageA(hWnd: v19->m_hWnd, Msg: 0x111u, wParam: nIDCmd, lParam: 0);
      }
    }
    if ( IsWindow(hWnd: hwndSaveda) && v18 < v3->m_Buttons.m_nCount )
    {
      if ( bIsSystemMenuButton != 0 )
      {
        v20 = CMFCToolBar::GetButton(this: v3, nIndex: v18);
        if ( v20 != nullptr )
          v20->m_nStyle &= ~0x20000u;
      }
      else
      {
        v3->SetButtonStyle(this: v3, a2: v18, a3: nNewStyle);
      }
      CMFCToolBar::UpdateButton(this: v3, nIndex: v18);
      CMFCToolBar::InvalidateButton(this: v3, nIndex: v18);
      UpdateWindow(hWnd: v3->m_hWnd);
LABEL_47:
      v3->m_ptLastMouse.y = -1;
      v3->m_ptLastMouse.x = -1;
      CMFCToolBar::OnMouseMove(this: v3, nFlags: 0, point);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AF8EA
// Name: protected: void CMFCToolBar::OnWindowPosChanged(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnWindowPosChanged(CMFCToolBar *this, tagWINDOWPOS *lpwndpos)
{
  int cx; // ecx
  BOOL v4; // edi
  int cy; // eax
  HWND Parent; // eax
  CWnd *v7; // eax

  cx = lpwndpos->cx;
  v4 = this->m_sizeLast.cx < cx || this->m_sizeLast.cy < lpwndpos->cy;
  cy = lpwndpos->cy;
  this->m_sizeLast.cx = cx;
  this->m_sizeLast.cy = cy;
  CWnd::Default(this);
  Parent = GetParent(hWnd: this->m_hWnd);
  v7 = CWnd::FromHandle(hWnd: Parent);
  if ( v4 || v7 != nullptr && CObject::IsKindOf(this: v7, pClass: &CMFCReBar::classCMFCReBar) != 0 )
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
  CMFCToolBar::RedrawCustomizeButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AF96F
// Name: protected: virtual int CMFCToolBar::NotifyControlCommand(class CMFCToolBarButton __near *,int,int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::NotifyControlCommand(
        CMFCToolBar *this,
        CMFCToolBarButton *pButton,
        int bAccelerator,
        int nNotifyCode,
        unsigned int wParam,
        LPARAM lParam)
{
  int result; // eax
  WPARAM v8; // esi
  CWnd *Owner; // eax

  if ( bAccelerator != 0 || (result = pButton->NotifyCommand(this: pButton, a2: nNotifyCode)) != 0 )
  {
    v8 = LOWORD(pButton->m_nID) | ((unsigned __int16)nNotifyCode << 16);
    Owner = CWnd::GetOwner(this);
    PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: v8, lParam);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AF9C0
// Name: public: virtual class CSize CMFCToolBar::StretchPane(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolBar::StretchPane(CMFCToolBar *this, CSize *result, int nLength, int bVert)
{
  CMFCCustomizeButton *m_pCustomizeBtn; // eax
  int v6; // eax
  CMFCToolBar_vtbl *v7; // ebx
  int v8; // eax
  int cx; // eax
  CSize v11; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  m_pCustomizeBtn = this->m_pCustomizeBtn;
  if ( m_pCustomizeBtn != nullptr )
    m_pCustomizeBtn->m_bIsEmpty = 0;
  this->m_nMaxBtnHeight = this->CalcMaxButtonHeight(this);
  result->cx = 0;
  result->cy = 0;
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  if ( this->IsHorizontal(this) != 0 )
    v6 = rect.bottom - rect.top;
  else
    v6 = rect.right - rect.left;
  CMFCToolBar::SizeToolBar(this, nLength: nLength + v6, bVert);
  v7 = this->__vftable;
  v8 = this->IsHorizontal(this);
  *result = *v7->CalcSize(this, result: &v11, a3: v8 == 0);
  if ( this->m_pParentDockBar == nullptr )
  {
    if ( this->IsHorizontal(this) != 0 )
      cx = result->cx;
    else
      cx = result->cy;
    this->m_nMRUWidth = cx;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AFA9C
// Name: protected: void CMFCToolBar::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnLButtonDblClk(CMFCToolBar *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax
  CMFCToolBarButton *Button; // eax
  CMFCToolBarButton *v6; // edi
  int IsKindOf; // ebx
  CPaneFrameWnd *v8; // eax

  v4 = ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y);
  if ( v4 < 0 )
  {
    if ( this->IsDocked(this) != 0 )
    {
      CPane::OnLButtonDblClk(this, nFlags, point);
    }
    else
    {
      v8 = this->GetParentMiniFrame(this, a2: 0);
      if ( v8 != nullptr )
        v8->OnDockToRecentPos(this: v8);
    }
  }
  else
  {
    Button = CMFCToolBar::GetButton(this, nIndex: v4);
    v6 = Button;
    if ( Button != nullptr )
    {
      IsKindOf = CObject::IsKindOf(this: Button, pClass: &CMFCToolBarSystemMenuButton::classCMFCToolBarSystemMenuButton);
      v6->OnDblClk(this: v6, a2: this);
      if ( IsKindOf == 0 )
        CMFCToolBar::OnLButtonDown(this, nFlags, point);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AFB2F
// Name: protected: virtual void CMFCToolBar::ShowCommandMessageString(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::ShowCommandMessageString(CMFCToolBar *this, WPARAM uiCmdId)
{
  WPARAM v2; // esi
  CWnd *v3; // eax
  CWnd *Owner; // eax

  if ( CMFCToolBar::m_hookMouseHelp == nullptr )
  {
    v2 = uiCmdId;
    if ( uiCmdId == -1 || uiCmdId == -20 )
    {
      Owner = CWnd::GetOwner(this);
      SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
    }
    else
    {
      if ( uiCmdId - 61440 > 0x1EF )
      {
        if ( uiCmdId >= 0xFF00 )
          v2 = 61215;
      }
      else
      {
        v2 = ((uiCmdId - 61440) >> 4) + 61184;
      }
      v3 = CWnd::GetOwner(this);
      SendMessageA(hWnd: v3->m_hWnd, Msg: 0x362u, wParam: v2, lParam: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8B40
// Name: protected: void CPaneDivider::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnLButtonDown(CPaneDivider *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  int v5; // edi
  HWND DesktopWindow; // eax
  CWnd *v7; // eax
  CPaneContainerManager *m_pContainerManager; // ecx
  int *p_m_nMaxOffset; // esi
  bool v10; // zf
  int m_nMinOffset; // eax
  tagSIZE v12; // [esp-1Ch] [ebp-60h]
  tagSIZE v13; // [esp-10h] [ebp-54h]
  HWND__ *v14; // [esp-8h] [ebp-4Ch]
  HWND__ *m_hWnd; // [esp-4h] [ebp-48h]
  CWindowDC v16; // [esp+10h] [ebp-34h] BYREF
  tagRECT Rect; // [esp+24h] [ebp-20h] BYREF
  int v18; // [esp+40h] [ebp-4h]

  if ( !this->m_bCaptured )
  {
    m_hWnd = this->m_hWnd;
    this->m_bCaptured = true;
    v4 = SetCapture(hWnd: m_hWnd);
    CWnd::FromHandle(hWnd: v4);
    v14 = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: v14, lpRect: &Rect);
    v5 = this->m_nWidth / 2;
    DesktopWindow = GetDesktopWindow();
    v7 = CWnd::FromHandle(hWnd: DesktopWindow);
    CWindowDC::CWindowDC(this: &v16, pWnd: v7);
    v13.cy = v5;
    v13.cx = v5;
    v12.cy = v5;
    v12.cx = v5;
    v18 = 0;
    CDC::DrawDragRect(
      this: &v16,
      lpRect: &Rect,
      size: v12,
      lpRectLast: nullptr,
      sizeLast: v13,
      pBrush: nullptr,
      pBrushLast: nullptr);
    this->m_rectLastDragRect.left = Rect.left;
    this->m_rectLastDragRect.top = Rect.top;
    m_pContainerManager = this->m_pContainerManager;
    this->m_rectLastDragRect.right = Rect.right;
    this->m_rectLastDragRect.bottom = Rect.bottom;
    this->m_rectDragBounds = (CRect)Rect;
    if ( m_pContainerManager != nullptr )
    {
      p_m_nMaxOffset = &this->m_nMaxOffset;
      m_pContainerManager->GetMinMaxOffset(
        this: m_pContainerManager,
        a2: this,
        a3: &this->m_nMinOffset,
        a4: &this->m_nMaxOffset,
        a5: &this->m_nStep);
      v10 = this->IsHorizontal(this) == 0;
      m_nMinOffset = this->m_nMinOffset;
      if ( v10 )
      {
        this->m_rectDragBounds.left = Rect.left + m_nMinOffset;
        this->m_rectDragBounds.right = Rect.right + *p_m_nMaxOffset;
      }
      else
      {
        this->m_rectDragBounds.top = Rect.top + m_nMinOffset;
        this->m_rectDragBounds.bottom = Rect.bottom + *p_m_nMaxOffset;
      }
      this->m_pContainerManager->SetResizeMode(this: this->m_pContainerManager, a2: 1);
    }
    v18 = -1;
    CWindowDC::~CWindowDC(this: &v16);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F8C68
// Name: protected: void CPaneDivider::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnLButtonUp(CPaneDivider *this, unsigned int nFlags, CPoint point)
{
  this->StopTracking(this, a2: 1);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F8C82
// Name: protected: void CPaneDivider::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnMouseMove(CPaneDivider *this, unsigned int nFlags, CPoint point)
{
  int left; // edx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int right; // ecx
  int m_nWidth; // ecx
  int top; // esi
  int v11; // edx
  int bottom; // eax
  HWND DesktopWindow; // eax
  CWnd *v14; // eax
  tagSIZE v15; // [esp-1Ch] [ebp-68h]
  tagSIZE v16; // [esp-10h] [ebp-5Ch]
  CWindowDC v17; // [esp+10h] [ebp-3Ch] BYREF
  tagPOINT Point; // [esp+24h] [ebp-28h] BYREF
  tagRECT Rect; // [esp+2Ch] [ebp-20h] BYREF
  int v20; // [esp+48h] [ebp-4h]

  if ( this->m_bCaptured )
  {
    Point.x = 0;
    Point.y = 0;
    Rect = (tagRECT)this->m_rectLastDragRect;
    GetCursorPos(lpPoint: &Point);
    if ( (this->m_dwDividerStyle & 2) != 0 )
    {
      left = this->m_rectDragBounds.left;
      v5 = this->m_nWidth / 2;
      v6 = this->m_nWidth + Point.x - v5;
      Rect.left = Point.x - v5;
      Rect.right = v6;
      if ( Point.x - v5 < left )
      {
        v7 = this->m_rectLastDragRect.right - this->m_rectLastDragRect.left;
        Rect.left = left;
        v6 = left + v7;
        Rect.right = v6;
      }
      right = this->m_rectDragBounds.right;
      if ( v6 > right )
      {
        Rect.right = this->m_rectDragBounds.right;
        Rect.left = this->m_rectLastDragRect.left + right - this->m_rectLastDragRect.right;
      }
    }
    else
    {
      m_nWidth = this->m_nWidth;
      top = this->m_rectDragBounds.top;
      v5 = m_nWidth / 2;
      v11 = m_nWidth + Point.y - m_nWidth / 2;
      Rect.top = Point.y - m_nWidth / 2;
      Rect.bottom = v11;
      if ( Rect.top < top )
      {
        v11 = m_nWidth + top;
        Rect.top = top;
        Rect.bottom = m_nWidth + top;
      }
      bottom = this->m_rectDragBounds.bottom;
      if ( v11 > bottom )
      {
        Rect.bottom = this->m_rectDragBounds.bottom;
        Rect.top = bottom - m_nWidth;
      }
    }
    DesktopWindow = GetDesktopWindow();
    v14 = CWnd::FromHandle(hWnd: DesktopWindow);
    CWindowDC::CWindowDC(this: &v17, pWnd: v14);
    v16.cy = v5;
    v16.cx = v5;
    v20 = 0;
    v15.cy = v5;
    v15.cx = v5;
    CDC::DrawDragRect(
      this: &v17,
      lpRect: &Rect,
      size: v15,
      lpRectLast: &this->m_rectLastDragRect,
      sizeLast: v16,
      pBrush: nullptr,
      pBrushLast: nullptr);
    v20 = -1;
    this->m_rectLastDragRect = (CRect)Rect;
    CWindowDC::~CWindowDC(this: &v17);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F8DBD
// Name: protected: void CPaneDivider::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnCancelMode(CPaneDivider *this)
{
  this->StopTracking(this, a2: 0);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F8DD4
// Name: protected: virtual void CPaneDivider::StopTracking(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::StopTracking(CPaneDivider *this, int bMoveSlider)
{
  int v3; // ecx
  CPaneContainerManager *m_pContainerManager; // ecx
  tagSIZE v5; // [esp-1Ch] [ebp-78h]
  tagSIZE v6; // [esp-10h] [ebp-6Ch]
  HWND__ *m_hWnd; // [esp-8h] [ebp-64h]
  CWindowDC v8; // [esp+10h] [ebp-4Ch] BYREF
  _DWORD v9[2]; // [esp+24h] [ebp-38h] BYREF
  tagRECT rc; // [esp+2Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+3Ch] [ebp-20h] BYREF
  int v12; // [esp+58h] [ebp-4h]

  if ( this->m_bCaptured )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    v3 = this->m_rectLastDragRect.left - Rect.left;
    v9[1] = this->m_rectLastDragRect.top - Rect.top;
    v9[0] = v3;
    memset(&rc, 0, sizeof(rc));
    SetRectEmpty(lprc: &rc);
    CWindowDC::CWindowDC(this: &v8, pWnd: nullptr);
    v6.cy = this->m_nWidth / 2;
    v6.cx = v6.cy;
    v5.cy = v6.cy;
    v5.cx = v6.cy;
    v12 = 0;
    CDC::DrawDragRect(
      this: &v8,
      lpRect: &rc,
      size: v5,
      lpRectLast: &this->m_rectLastDragRect,
      sizeLast: v6,
      pBrush: nullptr,
      pBrushLast: nullptr);
    if ( bMoveSlider != 0 )
      this->Move(this, a2: (CPoint *)v9, a3: 1);
    SetRectEmpty(lprc: &this->m_rectLastDragRect);
    ReleaseCapture();
    m_pContainerManager = this->m_pContainerManager;
    this->m_bCaptured = false;
    if ( m_pContainerManager != nullptr )
      m_pContainerManager->SetResizeMode(this: m_pContainerManager, a2: 0);
    v12 = -1;
    CWindowDC::~CWindowDC(this: &v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8EAF
// Name: protected: void CPaneDivider::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::OnPaint(CPaneDivider *this)
{
  CMFCVisualManager *Instance; // eax
  CDC *p_m_dcMem; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-C8h]
  CPaintDC v5; // [esp+10h] [ebp-B0h] BYREF
  CMemDC v6; // [esp+64h] [ebp-5Ch] BYREF
  tagRECT Rect; // [esp+A0h] [ebp-20h] BYREF
  int v8; // [esp+BCh] [ebp-4h]

  CPaintDC::CPaintDC(this: &v5, pWnd: this);
  v8 = 0;
  CMemDC::CMemDC(this: &v6, dc: &v5, pWnd: (HDC__ *)this);
  m_hWnd = this->m_hWnd;
  LOBYTE(v8) = 1;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  Instance = CMFCVisualManager::GetInstance();
  p_m_dcMem = &v6.m_dcMem;
  if ( v6.m_bMemDC == 0 )
    p_m_dcMem = v6.m_dc;
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CPaneDivider *, int, int, int, int, int))Instance->OnDrawPaneDivider)(
    a1: Instance,
    a2: p_m_dcMem,
    a3: this,
    a4: Rect.left,
    a5: Rect.top,
    a6: Rect.right,
    a7: Rect.bottom,
    a8: this->m_bAutoHideMode);
  LOBYTE(v8) = 0;
  CMemDC::~CMemDC(this: &v6);
  v8 = -1;
  CPaintDC::~CPaintDC(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x10402BE8
// Name: public: void CMFCTabCtrl::StopResize(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::StopResize(CMFCTabCtrl *this, int bCancel)
{
  CMFCTabCtrl::ResizeMode m_ResizeMode; // eax
  HWND Parent; // eax
  CWnd *v5; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-44h]
  HWND__ *v7; // [esp-8h] [ebp-44h]
  tagRECT rect; // [esp+8h] [ebp-34h] BYREF
  CRect rectEmpty; // [esp+18h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+28h] [ebp-14h] BYREF

  if ( this->m_bResize != 0 )
  {
    memset(&rectEmpty, 0, sizeof(rectEmpty));
    SetRectEmpty(lprc: &rectEmpty);
    this->DrawResizeDragRect(this, a2: &rectEmpty, a3: &this->m_rectResizeDrag);
    this->m_bResize = 0;
    ReleaseCapture();
    if ( bCancel == 0 )
    {
      m_hWnd = this->m_hWnd;
      memset(&rectWnd, 0, sizeof(rectWnd));
      GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
      m_ResizeMode = this->m_ResizeMode;
      if ( m_ResizeMode == RESIZE_VERT )
      {
        rectWnd.right = this->m_rectResizeDrag.right;
      }
      else if ( m_ResizeMode == RESIZE_HORIZ )
      {
        rectWnd.bottom = this->m_rectResizeDrag.bottom;
      }
      v7 = this->m_hWnd;
      rect = rectWnd.tagRECT;
      Parent = GetParent(hWnd: v7);
      v5 = CWnd::FromHandle(hWnd: Parent);
      SendMessageA(hWnd: v5->m_hWnd, Msg: AFX_WM_ON_DRAGCOMPLETE, wParam: (WPARAM)this, lParam: (LPARAM)&rect);
    }
    SetRectEmpty(lprc: &this->m_rectResizeDrag);
    SetRectEmpty(lprc: &this->m_rectResizeBounds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402CDC
// Name: protected: void CMFCTabCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnMouseMove(CMFCTabCtrl *this, WPARAM nFlags, CPoint point)
{
  CMFCTabCtrl::ResizeMode m_ResizeMode; // eax
  int v5; // ecx
  int v6; // eax
  int left; // edx
  int v8; // esi
  int right; // eax
  int v10; // ecx
  int v11; // eax
  int top; // edx
  int v13; // esi
  int bottom; // eax
  CRect *p_m_rectTabSplitter; // esi
  int v16; // eax
  int SystemMetrics; // ecx
  int y; // eax
  int v19; // eax
  int v20; // eax
  CMFCTabCtrl_vtbl *v21; // eax
  int v22; // eax
  HWND Capture; // eax
  int v24; // ecx
  HWND v25; // eax
  HWND Parent; // eax
  CWnd *v27; // eax
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager *v29; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-3Ch]
  int nDrag; // [esp+Ch] [ebp-28h]
  int nDraga; // [esp+Ch] [ebp-28h]
  CRect rectTabSplitter; // [esp+10h] [ebp-24h] BYREF
  CPoint pointDelta; // [esp+20h] [ebp-14h] BYREF
  tagPOINT Point; // [esp+28h] [ebp-Ch] BYREF

  if ( this->m_bResize != 0 )
  {
    pointDelta.x = this->m_rectResizeDrag.left;
    pointDelta.y = this->m_rectResizeDrag.top;
    Point.x = this->m_rectResizeDrag.right;
    m_hWnd = this->m_hWnd;
    Point.y = this->m_rectResizeDrag.bottom;
    ClientToScreen(hWnd: m_hWnd, lpPoint: &point);
    m_ResizeMode = this->m_ResizeMode;
    if ( m_ResizeMode == RESIZE_VERT )
    {
      v5 = Point.x - pointDelta.x;
      v6 = point.x - (Point.x - pointDelta.x) / 2;
      left = this->m_rectResizeBounds.left;
      v8 = v6 + Point.x - pointDelta.x;
      pointDelta.x = v6;
      Point.x = v8;
      if ( v6 >= left )
      {
        right = this->m_rectResizeBounds.right;
        if ( v8 > right )
        {
          Point.x = this->m_rectResizeBounds.right;
          pointDelta.x = right - v5;
        }
      }
      else
      {
        pointDelta.x = left;
        Point.x = v5 + left;
      }
    }
    else if ( m_ResizeMode == RESIZE_HORIZ )
    {
      v10 = Point.y - pointDelta.y;
      v11 = point.y - (Point.y - pointDelta.y) / 2;
      top = this->m_rectResizeBounds.top;
      v13 = v11 + Point.y - pointDelta.y;
      pointDelta.y = v11;
      Point.y = v13;
      if ( v11 >= top )
      {
        bottom = this->m_rectResizeBounds.bottom;
        if ( v13 > bottom )
        {
          Point.y = this->m_rectResizeBounds.bottom;
          pointDelta.y = bottom - v10;
        }
      }
      else
      {
        pointDelta.y = top;
        Point.y = v10 + top;
      }
    }
    this->DrawResizeDragRect(this, a2: (CRect *)&pointDelta, a3: &this->m_rectResizeDrag);
    *(CPoint *)&this->m_rectResizeDrag.left = pointDelta;
    *(tagPOINT *)&this->m_rectResizeDrag.right = Point;
  }
  else
  {
    if ( this->m_bTrackSplitter != 0 )
    {
      p_m_rectTabSplitter = &this->m_rectTabSplitter;
      nDrag = this->m_rectTabSplitter.left;
      v16 = this->m_nScrollBarRight - point.x;
      if ( this->m_nScrollBarRight - this->m_rectTabsArea.left - 5 < v16 )
        v16 = this->m_nScrollBarRight - this->m_rectTabsArea.left - 5;
      this->m_nHorzScrollWidth = v16;
      Point.y = v16;
      SystemMetrics = GetSystemMetrics(nIndex: 21);
      y = Point.y;
      if ( 2 * SystemMetrics > Point.y )
        y = 2 * GetSystemMetrics(nIndex: 21);
      this->m_nHorzScrollWidth = y;
      this->AdjustWndScroll(this);
      v19 = p_m_rectTabSplitter->left;
      if ( p_m_rectTabSplitter->left > nDrag )
      {
        pointDelta.x = p_m_rectTabSplitter->left;
        pointDelta.y = this->m_rectTabSplitter.top;
        Point = *(tagPOINT *)&this->m_rectTabSplitter.right;
        pointDelta.x = nDrag - 20;
        Point.x = v19;
        v20 = this->GetTabBorderSize(this);
        InflateRect(lprc: (LPRECT)&pointDelta, dx: 0, dy: v20 + 1);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: (const RECT *)&pointDelta, bErase: true);
      }
      v21 = this->__vftable;
      rectTabSplitter = this->m_rectTabSplitter;
      v22 = v21->GetTabBorderSize(this);
      InflateRect(lprc: &rectTabSplitter, dx: 0, dy: v22);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectTabSplitter, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
      this->AdjustTabsScroll(this);
    }
    else
    {
      Capture = GetCapture();
      if ( CWnd::FromHandle(hWnd: Capture) == this && this->IsMDITabGroup(this) != 0 && this->m_bReadyToDetach != 0 )
      {
        Point.x = 0;
        Point.y = 0;
        GetCursorPos(lpPoint: &Point);
        v24 = this->m_ptHot.y - Point.y;
        Point.x = this->m_ptHot.x - Point.x;
        Point.y = v24;
        nDraga = GetSystemMetrics(nIndex: 68);
        v25 = GetCapture();
        if ( CWnd::FromHandle(hWnd: v25) == this
          && this->m_bReadyToDetach != 0
          && abs(lnumber: Point.x) < nDraga
          && abs(lnumber: Point.y) < nDraga )
        {
          return;
        }
        Parent = GetParent(hWnd: this->m_hWnd);
        v27 = CWnd::FromHandle(hWnd: Parent);
        if ( SendMessageA(
               hWnd: v27->m_hWnd,
               Msg: AFX_WM_ON_TABGROUPMOUSEMOVE,
               wParam: nFlags,
               lParam: LOWORD(point.x) | (LOWORD(point.y) << 16)) != 0 )
          return;
      }
    }
    if ( this->m_bFlat == 0 )
    {
      Instance = CMFCVisualManager::GetInstance();
      if ( Instance->AlwaysHighlight3DTabs(this: Instance) != 0 )
      {
        this->m_bHighLightTabs = 1;
      }
      else if ( this->m_bIsOneNoteStyle != 0 )
      {
        v29 = CMFCVisualManager::GetInstance();
        this->m_bHighLightTabs = v29->IsHighlightOneNoteTabs(this: v29);
      }
    }
    CMFCBaseTabCtrl::OnMouseMove(this, nFlags, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402FF7
// Name: protected: void CMFCTabCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnCancelMode(CMFCTabCtrl *this)
{
  HWND Capture; // eax
  BOOL v3; // edi
  HWND Parent; // eax
  CWnd *v5; // eax

  Capture = GetCapture();
  v3 = this == CWnd::FromHandle(hWnd: Capture);
  if ( this->IsMDITabGroup(this) != 0 && v3 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    SendMessageA(hWnd: v5->m_hWnd, Msg: AFX_WM_ON_CANCELTABMOVE, wParam: 0, lParam: 0);
  }
  CMFCBaseTabCtrl::OnCancelMode(this);
  CMFCTabCtrl::StopResize(this, bCancel: 1);
  if ( this->m_bTrackSplitter != 0 )
  {
    this->m_bResize = 0;
    this->m_bTrackSplitter = 0;
    ReleaseCapture();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403075
// Name: protected: void CMFCTabCtrl::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnSysColorChange(CMFCTabCtrl *this)
{
  COLORREF v2; // eax
  HBRUSH SolidBrush; // eax

  CMFCBaseTabCtrl::OnSysColorChange(this);
  if ( this->m_bFlat != 0 && this->m_clrActiveTabFg == -1 )
  {
    if ( this != (CMFCTabCtrl *)-292 && this->m_brActiveTab.m_hObject != nullptr )
      CGdiObject::DeleteObject(this: &this->m_brActiveTab);
    v2 = this->GetActiveTabColor(this);
    SolidBrush = CreateSolidBrush(color: v2);
    CGdiObject::Attach(this: &this->m_brActiveTab, hObject: SolidBrush);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104030DB
// Name: public: void CMFCTabCtrl::HideActiveWindowHorzScrollBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::HideActiveWindowHorzScrollBar(CMFCTabCtrl *this)
{
  CWnd *v2; // eax
  CWnd *v3; // edi

  v2 = this->GetActiveWnd(this);
  v3 = v2;
  if ( v2 != nullptr && this->m_bSharedScroll != 0 )
  {
    ShowScrollBar(hWnd: v2->m_hWnd, wBar: 0, bShow: false);
    CWnd::ModifyStyle(this: v3, dwRemove: 0x100000u, dwAdd: 0, nFlags: 0x20u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403118
// Name: protected: virtual void CMFCTabCtrl::SetTabsHeight(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::SetTabsHeight(CMFCTabCtrl *this)
{
  HFONT v2; // eax
  HFONT v3; // eax
  int cy; // eax
  int v5; // ecx
  int v6; // eax
  CClientDC v7; // [esp+10h] [ebp-D8h] BYREF
  CFont *pFont; // [esp+24h] [ebp-C4h]
  tagTEXTMETRICA tm; // [esp+28h] [ebp-C0h] BYREF
  int pv[5]; // [esp+60h] [ebp-88h] BYREF
  unsigned __int8 v11; // [esp+77h] [ebp-71h]
  LOGFONTA dst; // [esp+9Ch] [ebp-4Ch] BYREF
  int v13; // [esp+E4h] [ebp-4h]

  if ( this->m_bFlat != 0 )
  {
    this->m_nTabsHeight = CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN / 2 + GetSystemMetrics(nIndex: 3);
    GetObjectA(h: afxGlobalData.fontRegular.m_hObject, c: 60, pv);
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    dst.lfCharSet = v11;
    dst.lfHeight = pv[0];
    dst.lfQuality = 5;
    lstrcpyA(lpString1: dst.lfFaceName, lpString2: "Arial");
    CClientDC::CClientDC(this: &v7, pWnd: this);
    v13 = 0;
    do
    {
      CGdiObject::DeleteObject(this: &this->m_fntTabs);
      v2 = CreateFontIndirectA(lplf: &dst);
      CGdiObject::Attach(this: &this->m_fntTabs, hObject: v2);
      pFont = CDC::SelectObject(this: &v7, pFont: &this->m_fntTabs);
      if ( pFont == nullptr )
        AfxThrowInvalidArgException();
      GetTextMetricsA(hdc: v7.m_hAttribDC, lptm: &tm);
      CDC::SelectObject(this: &v7, pFont);
      if ( tm.tmHeight + CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN / 2 <= this->m_nTabsHeight )
        break;
      if ( dst.lfHeight >= 0 )
        --dst.lfHeight;
      else
        ++dst.lfHeight;
    }
    while ( dst.lfHeight != 0 );
    dst.lfWeight = 700;
    CGdiObject::DeleteObject(this: &this->m_fntTabsBold);
    v3 = CreateFontIndirectA(lplf: &dst);
    CGdiObject::Attach(this: &this->m_fntTabsBold, hObject: v3);
    v13 = -1;
    CClientDC::~CClientDC(this: &v7);
  }
  else if ( this->m_bIsVS2005Style != 0 )
  {
    cy = this->m_sizeImage.cy;
    if ( cy > 0 )
      v5 = cy + 7;
    else
      v5 = 0;
    v6 = afxGlobalData.m_nTextHeightHorz + 4;
    if ( v5 > afxGlobalData.m_nTextHeightHorz + 4 )
      v6 = v5;
    this->m_nTabsHeight = v6;
  }
  else
  {
    CMFCBaseTabCtrl::SetTabsHeight(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104032B4
// Name: public: virtual int CMFCTabCtrl::EnsureVisible(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::EnsureVisible(CMFCTabCtrl *this, int iTab)
{
  int v2; // edx
  int v4; // ecx
  void **m_pData; // eax
  int *v6; // esi
  int left; // eax
  int right; // esi
  int v9; // ecx
  void **v10; // esi
  int v11; // edi
  int m_nFirstVisibleTab; // edi
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // edi
  int i; // [esp+Ch] [ebp-1Ch]
  int nWidthLeft; // [esp+10h] [ebp-18h]
  CRect rectTab; // [esp+14h] [ebp-14h] BYREF

  v2 = iTab;
  if ( iTab >= 0 && iTab < this->m_iTabsNum )
  {
    if ( this->m_bScroll == 0 )
      return 1;
    v4 = this->m_rectTabsArea.right - this->m_rectTabsArea.left;
    if ( this->m_rectTabsArea.right - this->m_rectTabsArea.left <= 0 )
      return 1;
    if ( iTab >= this->m_arTabs.m_nSize )
LABEL_33:
      AfxThrowInvalidArgException();
    m_pData = this->m_arTabs.m_pData;
    v6 = (int *)((char *)m_pData[iTab] + 16);
    rectTab.left = *v6++;
    rectTab.top = *v6++;
    rectTab.right = *v6;
    rectTab.bottom = v6[1];
    if ( this->m_bTabDocumentsMenu != 0 )
    {
      if ( rectTab.left >= this->m_rectTabsArea.right )
      {
LABEL_10:
        CMFCBaseTabCtrl::MoveTab(this, nSource: v2, nDest: 0);
        return 1;
      }
      if ( IsRectEmpty(lprc: &rectTab) )
      {
        v2 = iTab;
        goto LABEL_10;
      }
    }
    else
    {
      if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bLeftRightRounded != 0 )
      {
        if ( rectTab.left >= this->m_rectTabsArea.left && rectTab.right <= this->m_rectTabsArea.right )
          return 1;
        i = 0;
        nWidthLeft = 0;
        v9 = this->m_rectTabsArea.bottom - this->m_rectTabsArea.top - CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN - 1;
        v10 = m_pData;
        do
        {
          if ( i < 0 || i >= this->m_arTabs.m_nSize )
            goto LABEL_33;
          v11 = *((_DWORD *)*v10 + 6) - *((_DWORD *)*v10 + 4);
          ++v10;
          nWidthLeft += v11 - v9;
          ++i;
        }
        while ( i <= iTab );
        this->m_nTabsHorzOffset = 0;
        this->m_nFirstVisibleTab = 0;
        if ( iTab > 0 )
        {
          while ( nWidthLeft > this->m_rectTabsArea.right - this->m_rectTabsArea.left )
          {
            m_nFirstVisibleTab = this->m_nFirstVisibleTab;
            if ( m_nFirstVisibleTab < 0 || m_nFirstVisibleTab >= this->m_arTabs.m_nSize )
              goto LABEL_33;
            v13 = this->m_arTabs.m_pData[m_nFirstVisibleTab];
            v14 = v13[6] - v13[4] - v9;
            this->m_nTabsHorzOffset += v14;
            nWidthLeft -= v14;
            v15 = m_nFirstVisibleTab + 1;
            this->m_nFirstVisibleTab = v15;
            if ( v15 >= iTab )
              break;
          }
        }
      }
      else
      {
        left = this->m_rectTabsArea.left;
        if ( rectTab.left >= left )
        {
          right = this->m_rectTabsArea.right;
          if ( rectTab.right <= right || rectTab.right - rectTab.left > v4 )
            return 1;
          this->m_nTabsHorzOffset += rectTab.right - right;
        }
        else
        {
          this->m_nTabsHorzOffset += rectTab.left - left;
        }
      }
      this->AdjustTabs(this);
      this->AdjustTabsScroll(this);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104034C0
// Name: private: virtual void CMFCTabButton::OnFillBackground(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabButton::OnFillBackground(CMFCTabButton *this, CDC *pDC, const CRect *rectClient)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  CMFCVisualManager_vtbl *v6; // ebx
  CObject *v7; // eax
  CMFCVisualManager *Instance; // [esp+Ch] [ebp-4h]

  Instance = CMFCVisualManager::GetInstance();
  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  v6 = Instance->__vftable;
  v7 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: v5);
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CMFCTabButton *, CObject *))v6->OnEraseTabsButton)(
    a1: Instance,
    a2: pDC,
    a3: rectClient->left,
    a4: rectClient->top,
    a5: rectClient->right,
    a6: rectClient->bottom,
    a7: this,
    a8: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10403514
// Name: private: virtual void CMFCTabButton::OnDrawBorder(class CDC __near *,class CRect __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabButton::OnDrawBorder(CMFCTabButton *this, CDC *pDC, CRect *rectClient, unsigned int uiState)
{
  CMFCVisualManager *Instance; // ebx
  HWND Parent; // eax
  CWnd *v7; // eax
  CMFCVisualManager_vtbl *v8; // esi
  CObject *v9; // eax

  Instance = CMFCVisualManager::GetInstance();
  Parent = GetParent(hWnd: this->m_hWnd);
  v7 = CWnd::FromHandle(hWnd: Parent);
  v8 = Instance->__vftable;
  v9 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: v7);
  v8->OnDrawTabsButtonBorder(this: Instance, a2: pDC, a3: rectClient, a4: this, a5: uiState, a6: (CMFCBaseTabCtrl *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1040355D
// Name: protected: void CMFCTabCtrl::ReposButtons(class CPoint,class CSize,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::ReposButtons(CMFCTabCtrl *this, CPoint pt, CSize sizeButton, int bHide, int nButtonMargin)
{
  CList<HWND__ *,HWND__ *>::CNode *m_pNodeHead; // eax
  HWND data; // ebx
  BOOL v8; // eax
  HWND__ *m_hWnd; // eax
  int x; // eax
  __POSITION *pos; // [esp+8h] [ebp-8h]
  int bIsFirst; // [esp+Ch] [ebp-4h]

  m_pNodeHead = this->m_lstButtons.m_pNodeHead;
  bIsFirst = 1;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = m_pNodeHead->data;
      pos = (__POSITION *)m_pNodeHead->pNext;
      if ( data == nullptr )
        AfxThrowInvalidArgException();
      v8 = this->m_bCloseBtn != 0 && this->m_bActiveTabCloseButton == 0;
      if ( bHide != 0
        || !v8
        && (this != (CMFCTabCtrl *)-8340 ? (m_hWnd = this->m_btnClose.m_hWnd) : (m_hWnd = nullptr), data == m_hWnd)
        || this->m_bTabDocumentsMenu != 0 && bIsFirst != 0 )
      {
        SetWindowPos(hWnd: data, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x14u);
      }
      else
      {
        x = pt.x;
        if ( (*(_QWORD *)&this->m_bIsOneNoteStyle != 0 || this->m_bLeftRightRounded != 0) && bIsFirst != 0 )
          x = this->m_rectTabsArea.left - sizeButton.cx - 1;
        SetWindowPos(
          hWnd: data,
          hWndInsertAfter: nullptr,
          X: x,
          Y: pt.y,
          cx: sizeButton.cx,
          cy: sizeButton.cy,
          uFlags: 0x14u);
        if ( *(_QWORD *)&this->m_bIsOneNoteStyle == 0 && this->m_bLeftRightRounded == 0 || bIsFirst == 0 )
          pt.x += nButtonMargin + sizeButton.cx;
      }
      InvalidateRect(hWnd: data, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: data);
      bIsFirst = 0;
      if ( pos == nullptr )
        break;
      m_pNodeHead = (CList<HWND__ *,HWND__ *>::CNode *)pos;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403679
// Name: protected: void CMFCTabCtrl::UpdateScrollButtonsState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::UpdateScrollButtonsState(CMFCTabCtrl *this)
{
  bool v2; // cc
  CMFCTabButton *p_m_btnScrollLeft; // ecx
  int v4; // eax
  int v5; // eax
  CMenuImages::IMAGE_STATE v6; // eax
  CList<HWND__ *,HWND__ *>::CNode *m_pNodeHead; // esi
  HWND data; // edi

  if ( this == nullptr || this->m_hWnd == nullptr || this->m_bScroll == 0 || this->m_bFlat != 0 )
    return;
  if ( this->m_bIsOneNoteStyle == 0 && this->m_bIsVS2005Style == 0 && this->m_bLeftRightRounded == 0 )
  {
    CWnd::EnableWindow(this: &this->m_btnScrollLeft, bEnable: this->m_nTabsHorzOffset > 0);
    if ( this->m_bTabDocumentsMenu == 0 )
    {
      v2 = this->m_nTabsHorzOffset < this->m_nTabsHorzOffsetMax;
LABEL_17:
      if ( !v2 )
        goto LABEL_18;
    }
LABEL_19:
    v5 = 1;
    goto LABEL_20;
  }
  p_m_btnScrollLeft = &this->m_btnScrollLeft;
  if ( this->m_arTabs.m_nSize == 0 )
  {
    CWnd::EnableWindow(this: p_m_btnScrollLeft, bEnable: 0);
    CWnd::EnableWindow(this: &this->m_btnScrollRight, bEnable: 0);
    goto LABEL_21;
  }
  CWnd::EnableWindow(this: p_m_btnScrollLeft, bEnable: this->m_nFirstVisibleTab > 0);
  v4 = this->m_arTabs.m_nSize - 1;
  if ( v4 < 0 || v4 >= this->m_arTabs.m_nSize )
LABEL_34:
    AfxThrowInvalidArgException();
  if ( this->m_bTabDocumentsMenu != 0 )
    goto LABEL_19;
  if ( *((_DWORD *)this->m_arTabs.m_pData[v4] + 6) > this->m_rectTabsArea.right )
  {
    v2 = this->m_nFirstVisibleTab < v4;
    goto LABEL_17;
  }
LABEL_18:
  v5 = 0;
LABEL_20:
  CWnd::EnableWindow(this: &this->m_btnScrollRight, bEnable: v5);
LABEL_21:
  if ( this->m_bTabDocumentsMenu != 0 )
  {
    if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bLeftRightRounded != 0 )
      v6 = ImageBlack;
    else
      v6 = ImageDkGray;
    CMFCButton::SetStdImage(
      this: &this->m_btnScrollRight,
      id: (CMenuImages::IMAGES_IDS)(this->m_bHiddenDocuments != 0 ? IdCustomizeArrowDownBold : IdArrowDownLarge),
      state: v6,
      idDisabled: IdArrowDownLarge);
  }
  m_pNodeHead = this->m_lstButtons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      goto LABEL_34;
    if ( !IsWindowEnabled(hWnd: data) )
      SendMessageA(hWnd: data, Msg: 0x1Fu, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104037E3
// Name: public: int CMFCTabCtrl::ModifyTabStyle(enum CMFCTabCtrl::Style)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::ModifyTabStyle(CMFCTabCtrl *this, CMFCTabCtrl::Style style)
{
  BOOL v3; // eax
  BOOL v4; // eax

  this->m_bFlat = style == STYLE_FLAT;
  v3 = style == STYLE_3D_ONENOTE;
  this->m_bIsOneNoteStyle = v3;
  this->m_bHighLightTabs = v3;
  this->m_bIsVS2005Style = style == STYLE_3D_VS2005;
  v4 = style == STYLE_3D_ROUNDED || style == STYLE_3D_ROUNDED_SCROLL;
  this->m_bLeftRightRounded = v4;
  CMFCTabCtrl::SetScrollButtons(this);
  this->SetTabsHeight(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1040384B
// Name: protected: void CMFCTabCtrl::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnWindowPosChanging(CMFCTabCtrl *this, tagWINDOWPOS *lpwndpos)
{
  CWnd::Default(this);
  if ( this->IsMDITabGroup(this) != 0 )
    lpwndpos->hwndInsertAfter = (HWND__ *)1;
}

//------------------------------------------------------------------------------
// Address: 0x10403875
// Name: protected: virtual void CMFCTabCtrl::DrawResizeDragRect(class CRect __near &,class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::DrawResizeDragRect(CMFCTabCtrl *this, CRect *rectNew, CRect *rectOld)
{
  HWND DesktopWindow; // eax
  CWnd *v5; // eax
  int v6; // eax
  tagSIZE v7; // [esp-1Ch] [ebp-4Ch]
  tagSIZE v8; // [esp-10h] [ebp-40h]
  CWindowDC dc; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+2Ch] [ebp-4h]

  DesktopWindow = GetDesktopWindow();
  v5 = CWnd::FromHandle(hWnd: DesktopWindow);
  CWindowDC::CWindowDC(this: &dc, pWnd: v5);
  v10 = 0;
  if ( this->m_ResizeMode == RESIZE_VERT )
    v6 = this->m_rectResizeDrag.right - this->m_rectResizeDrag.left;
  else
    v6 = this->m_rectResizeDrag.bottom - this->m_rectResizeDrag.top;
  v8.cy = v6 / 2 + 1;
  v8.cx = v8.cy;
  v7.cy = v8.cy;
  v7.cx = v8.cy;
  CDC::DrawDragRect(
    this: &dc,
    lpRect: rectNew,
    size: v7,
    lpRectLast: rectOld,
    sizeLast: v8,
    pBrush: nullptr,
    pBrushLast: nullptr);
  v10 = -1;
  CWindowDC::~CWindowDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x104038EF
// Name: public: virtual int CMFCTabCtrl::IsMDITabGroup(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::IsMDITabGroup(CMFCTabCtrl *this)
{
  HWND Parent; // eax
  CWnd *v2; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  if ( v2 != nullptr )
    return CObject::IsKindOf(this: v2, pClass: &CMDIClientAreaWnd::classCMDIClientAreaWnd);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10403912
// Name: public: void CMFCTabCtrl::ActivateMDITab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::ActivateMDITab(CMFCTabCtrl *this, int nTab)
{
  int m_iActiveTab; // edi
  CWnd *v4; // ebx
  WPARAM m_hWnd; // edi
  HWND Parent; // eax
  CWnd *v7; // eax

  m_iActiveTab = nTab;
  if ( nTab != -1 || (m_iActiveTab = this->m_iActiveTab) != -1 )
  {
    v4 = this->GetTabWnd(this, a2: m_iActiveTab);
    if ( v4 != nullptr && (m_iActiveTab == this->m_iActiveTab || this->SetActiveTab(this, a2: m_iActiveTab) != 0) )
    {
      m_hWnd = (WPARAM)v4->m_hWnd;
      Parent = GetParent(hWnd: this->m_hWnd);
      v7 = CWnd::FromHandle(hWnd: Parent);
      SendMessageA(hWnd: v7->m_hWnd, Msg: 0x222u, wParam: m_hWnd, lParam: 0);
      CWnd::SetFocus(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403986
// Name: protected: long CMFCTabCtrl::OnUpdateToolTips(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::OnUpdateToolTips(CMFCTabCtrl *this, char wp, int __formal)
{
  CToolTipCtrl **p_m_pToolTip; // ebx
  CToolTipCtrl *m_pToolTipClose; // ecx
  int i; // edi
  _DWORD *v7; // eax
  int v8; // ecx
  CRect rectDummy; // [esp+4h] [ebp-14h] BYREF

  if ( (wp & 4) != 0 )
  {
    p_m_pToolTip = &this->m_pToolTip;
    CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 4u);
    if ( *p_m_pToolTip != nullptr && (*p_m_pToolTip)->m_hWnd != nullptr )
    {
      memset(&rectDummy, 0, sizeof(rectDummy));
      CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTipClose, pWndParent: this, nType: 4u);
      m_pToolTipClose = this->m_pToolTipClose;
      if ( m_pToolTipClose != nullptr && m_pToolTipClose->m_hWnd != nullptr )
        CToolTipCtrl::AddTool(
          this: m_pToolTipClose,
          pWnd: this,
          lpszText: (char *)0xFFFFFFFF,
          lpRectTool: &rectDummy,
          nIDTool: 1u);
      for ( i = 0; i < this->m_iTabsNum; ++i )
      {
        if ( i < 0 || i >= this->m_arTabs.m_nSize )
          AfxThrowInvalidArgException();
        v7 = this->m_arTabs.m_pData[i];
        if ( this->m_bCustomToolTips != 0 )
          v8 = -1;
        else
          v8 = v7[1];
        CToolTipCtrl::AddTool(
          this: *p_m_pToolTip,
          pWnd: this,
          lpszText: (char *)v8,
          lpRectTool: &rectDummy,
          nIDTool: v7[10]);
      }
      this->RecalcLayout(this);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10403A6C
// Name: public: static class CObject __near * CMFCTabCtrl::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__stdcall CMFCTabCtrl::CreateObject()
{
  CMFCTabCtrl *v0; // ecx
  CMFCTabCtrl *result; // eax

  v0 = (CMFCTabCtrl *)operator new(nSize: 0x2804u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCTabCtrl::CMFCTabCtrl(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403ABD
// Name: protected: void CMFCTabCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnLButtonDown(CMFCTabCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  HWND Parent; // eax
  CWnd *v6; // eax
  HWND v7; // eax
  int v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // esi
  HWND__ *v11; // [esp-8h] [ebp-38h]
  HWND__ *m_hWnd; // [esp-4h] [ebp-34h]
  LRESULT lResult; // [esp+8h] [ebp-28h]
  tagRECT rectBounds; // [esp+Ch] [ebp-24h] BYREF
  CRect rectEmpty; // [esp+1Ch] [ebp-14h] BYREF

  if ( PtInRect(lprc: &this->m_rectTabSplitter, pt: point.tagPOINT) )
  {
    m_hWnd = this->m_hWnd;
    this->m_bTrackSplitter = 1;
    v4 = SetCapture(hWnd: m_hWnd);
    CWnd::FromHandle(hWnd: v4);
  }
  else if ( this->m_ResizeMode != RESIZE_NO
         && PtInRect(lprc: &this->m_rectResize, pt: point.tagPOINT)
         && (Parent = GetParent(hWnd: this->m_hWnd),
             v6 = CWnd::FromHandle(hWnd: Parent),
             lResult = SendMessageA(
                         hWnd: v6->m_hWnd,
                         Msg: AFX_WM_GETDRAGBOUNDS,
                         wParam: (WPARAM)this,
                         lParam: (LPARAM)&rectBounds),
             CopyRect(lprcDst: &this->m_rectResizeBounds, lprcSrc: &rectBounds),
             lResult != 0)
         && !IsRectEmpty(lprc: &this->m_rectResizeBounds) )
  {
    v11 = this->m_hWnd;
    this->m_bResize = 1;
    v7 = SetCapture(hWnd: v11);
    CWnd::FromHandle(hWnd: v7);
    this->m_rectResizeDrag.left = this->m_rectResize.left;
    this->m_rectResizeDrag.top = this->m_rectResize.top;
    this->m_rectResizeDrag.right = this->m_rectResize.right;
    this->m_rectResizeDrag.bottom = this->m_rectResize.bottom;
    CWnd::ClientToScreen(this, lpRect: &this->m_rectResizeDrag);
    memset(&rectEmpty, 0, sizeof(rectEmpty));
    SetRectEmpty(lprc: &rectEmpty);
    this->DrawResizeDragRect(this, a2: &this->m_rectResizeDrag, a3: &rectEmpty);
  }
  else
  {
    if ( this->IsMDITabGroup(this) != 0 )
    {
      v8 = this->GetTabFromPoint(this, a2: &point);
      if ( v8 == this->m_iActiveTab )
        CMFCTabCtrl::ActivateMDITab(this, nTab: v8);
    }
    CMFCBaseTabCtrl::OnLButtonDown(this, nFlags, point);
    if ( this->m_bReadyToDetach == 0 )
    {
      v9 = this->FindTargetWnd(this, a2: &point);
      v10 = v9;
      if ( v9 != nullptr )
      {
        MapWindowPoints(hWndFrom: this->m_hWnd, hWndTo: v9->m_hWnd, lpPoints: &point, cPoints: 1u);
        SendMessageA(hWnd: v10->m_hWnd, Msg: 0x201u, wParam: nFlags, lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403C76
// Name: protected: void CMFCTabCtrl::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnHScroll(
        CMFCTabCtrl *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  HWND__ *m_hWnd; // ecx
  HWND__ *v6; // eax
  CWnd *v7; // ecx
  int m_iActiveTab; // eax
  WPARAM v9; // edi
  bool v10; // zf
  int ScrollPos; // eax
  int v12; // eax
  HWND Parent; // eax
  CWnd *v14; // eax
  CWnd *pWndActive; // [esp+1Ch] [ebp+10h]

  if ( this->m_bFlat != 0 )
  {
    if ( pScrollBar != nullptr )
      m_hWnd = pScrollBar->m_hWnd;
    else
      m_hWnd = nullptr;
    if ( this == (CMFCTabCtrl *)-736 )
      v6 = nullptr;
    else
      v6 = this->m_wndScrollWnd.m_hWnd;
    if ( m_hWnd == v6 )
    {
      if ( this->m_iActiveTab != -1 && bInsideScroll == 0 )
      {
        v7 = this->GetActiveWnd(this);
        m_iActiveTab = this->m_iActiveTab;
        pWndActive = v7;
        if ( m_iActiveTab < 0 || m_iActiveTab >= this->m_arTabs.m_nSize )
          AfxThrowInvalidArgException();
        v9 = (unsigned __int16)nSBCode | ((unsigned __int16)nPos << 16);
        v10 = *((_DWORD *)this->m_arTabs.m_pData[m_iActiveTab] + 14) == 0;
        bInsideScroll = 1;
        if ( !v10 && ((_BYTE)nSBCode == 4 || (_BYTE)nSBCode == 5) )
        {
          ScrollPos = CWnd::GetScrollPos(this: v7, nBar: 0);
          SendMessageA(hWnd: pWndActive->m_hWnd, Msg: 0x1014u, wParam: nPos - ScrollPos, lParam: 0);
        }
        SendMessageA(hWnd: pWndActive->m_hWnd, Msg: 0x114u, wParam: v9, lParam: 0);
        bInsideScroll = 0;
        v12 = CWnd::GetScrollPos(this: pWndActive, nBar: 0);
        SetScrollPos(hWnd: this->m_wndScrollWnd.m_hWnd, nBar: 2, nPos: v12, bRedraw: true);
        CMFCTabCtrl::HideActiveWindowHorzScrollBar(this);
        Parent = GetParent(hWnd: this->m_hWnd);
        v14 = CWnd::FromHandle(hWnd: Parent);
        SendMessageA(hWnd: v14->m_hWnd, Msg: AFX_WM_ON_HSCROLL, wParam: v9, lParam: 0);
      }
    }
    else
    {
      CWnd::OnHScroll(this, __formal: nSBCode, __formal: nPos, pScrollBar);
    }
  }
  else
  {
    CWnd::OnHScroll(this, __formal: nSBCode, __formal: nPos, pScrollBar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403DC0
// Name: protected: virtual void CMFCTabCtrl::AdjustTabsScroll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::AdjustTabsScroll(CMFCTabCtrl *this)
{
  int v2; // ecx
  int m_nTabsHorzOffset; // edx
  int v4; // eax
  int v5; // ebx

  v2 = 0;
  if ( this->m_bScroll == 0 )
    goto LABEL_2;
  if ( this->m_iTabsNum == 0 )
  {
    this->m_nTabsHorzOffsetMax = 0;
LABEL_2:
    this->m_nTabsHorzOffset = 0;
    this->m_nFirstVisibleTab = 0;
    return;
  }
  m_nTabsHorzOffset = this->m_nTabsHorzOffset;
  v4 = this->m_rectTabsArea.left + this->m_nTabsTotalWidth - this->m_rectTabsArea.right;
  if ( v4 < 0 )
    v4 = 0;
  this->m_nTabsHorzOffsetMax = v4;
  if ( this->m_bIsOneNoteStyle != 0
    || this->m_bIsVS2005Style != 0
    || this->m_bLeftRightRounded != 0
    || (m_nTabsHorzOffset >= 0 ? (v5 = m_nTabsHorzOffset) : (v5 = 0), v5 < v4) )
  {
    if ( m_nTabsHorzOffset >= 0 )
      v2 = m_nTabsHorzOffset;
  }
  else
  {
    v2 = v4;
  }
  this->m_nTabsHorzOffset = v2;
  if ( m_nTabsHorzOffset != v2 )
  {
    this->AdjustTabs(this);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectTabsArea, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  CMFCTabCtrl::UpdateScrollButtonsState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10403E75
// Name: public: virtual void CMFCTabCtrl::RecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::RecalcLayout(CMFCTabCtrl *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  CMFCVisualManager *Instance; // eax
  CSize *v6; // esi
  int v7; // eax
  int m_nCount; // ecx
  int v9; // esi
  int left; // eax
  int right; // eax
  int cy; // eax
  int top; // edi
  int v14; // eax
  int v15; // ecx
  int SystemMetrics; // eax
  int v17; // esi
  int i; // esi
  void *v19; // eax
  CWnd *v20; // ecx
  int m_bFlat; // eax
  CRect *p_Rect; // eax
  CPoint v23; // [esp-1Ch] [ebp-7Ch]
  CSize v24; // [esp-14h] [ebp-74h]
  HWND__ *m_hWnd; // [esp-Ch] [ebp-6Ch]
  int v26; // [esp-Ch] [ebp-6Ch]
  HWND__ *v27; // [esp-Ch] [ebp-6Ch]
  int bottom; // [esp-8h] [ebp-68h]
  CSize result; // [esp+8h] [ebp-58h] BYREF
  int bHideTabs; // [esp+10h] [ebp-50h]
  int nTabsHeight; // [esp+14h] [ebp-4Ch]
  int nTabBorderSize; // [esp+18h] [ebp-48h]
  CRect rectClient; // [esp+1Ch] [ebp-44h] BYREF
  CRect rcUpdateArea; // [esp+2Ch] [ebp-34h] BYREF
  CRect rectFrame; // [esp+3Ch] [ebp-24h] BYREF
  RECT Rect; // [esp+4Ch] [ebp-14h] BYREF

  if ( this == nullptr || this->m_hWnd == nullptr )
    return;
  nTabsHeight = this->GetTabsHeight(this);
  nTabBorderSize = this->GetTabBorderSize(this);
  v2 = this->GetVisibleTabsNum(this);
  bHideTabs = this->m_bHideSingleTab != 0 && v2 <= 1 || this->m_bHideNoTabs != 0 && v2 == 0;
  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  if ( this->m_ResizeMode == RESIZE_VERT )
  {
    this->m_rectResize = rectClient;
    rectClient.right -= 6;
    this->m_rectResize.left = rectClient.right + 1;
  }
  else if ( this->m_ResizeMode == RESIZE_HORIZ )
  {
    this->m_rectResize = rectClient;
    rectClient.bottom -= 6;
    this->m_rectResize.top = rectClient.bottom + 1;
  }
  else
  {
    SetRectEmpty(lprc: &this->m_rectResize);
  }
  this->m_rectTabsArea = rectClient;
  InflateRect(lprc: &this->m_rectTabsArea, dx: -2, dy: 0);
  v3 = 0;
  v4 = 0;
  result.cy = 0;
  Rect.bottom = 0;
  if ( this->m_bScroll != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    v6 = Instance->GetButtonExtraBorder(this: Instance, result: (CSize *)&Rect.right);
    v3 = v6->cx + CMenuImages::Size(&result)->cx + 4;
    result.cy = v3;
    if ( this->m_bFlat == 0 )
    {
      v7 = v3 + 2;
      v3 = nTabsHeight - 4;
      if ( nTabsHeight - 4 >= v7 )
      {
        v3 = v7;
        result.cy = v7;
      }
      else
      {
        result.cy = nTabsHeight - 4;
      }
    }
    m_nCount = this->m_lstButtons.m_nCount;
    if ( this->m_bCloseBtn == 0 || this->m_bActiveTabCloseButton != 0 )
      --m_nCount;
    if ( this->m_bTabDocumentsMenu != 0 )
      --m_nCount;
    Rect.bottom = 3;
    v4 = bHideTabs == 0 ? m_nCount * (v3 + 3) : 0;
  }
  if ( this->m_bFlat != 0 )
  {
    v9 = nTabBorderSize;
    if ( this->m_location != LOCATION_BOTTOM )
    {
      if ( nTabBorderSize > 1 )
        this->m_rectTabsArea.top += nTabBorderSize - 1;
      this->m_rectTabsArea.bottom = nTabsHeight + this->m_rectTabsArea.top;
    }
    else
    {
      if ( nTabBorderSize > 1 )
        this->m_rectTabsArea.bottom += 1 - nTabBorderSize;
      this->m_rectTabsArea.top = this->m_rectTabsArea.bottom - nTabsHeight;
    }
    this->m_rectTabsArea.left += v4 + 1;
    left = this->m_rectTabsArea.left;
    if ( --this->m_rectTabsArea.right < left )
    {
      if ( v9 <= 0 )
      {
        this->m_rectTabsArea.left = rectClient.left;
        right = rectClient.right;
      }
      else
      {
        this->m_rectTabsArea.left = rectClient.left + v9 + 1;
        right = rectClient.right - v9 - 1;
      }
      this->m_rectTabsArea.right = right;
    }
    cy = this->m_rectTabsArea.bottom - this->m_rectTabsArea.top;
    if ( cy + v9 > rectClient.bottom - rectClient.top )
    {
      cy = 0;
      this->m_rectTabsArea.left = 0;
      this->m_rectTabsArea.right = 0;
    }
    top = this->m_rectTabsArea.top;
    if ( cy != 0 )
    {
      v14 = (cy - result.cy) / 2;
      if ( v14 < 0 )
        v14 = 0;
      top += v14;
      cy = result.cy;
    }
    bottom = Rect.bottom;
    v26 = bHideTabs;
    v15 = rectClient.left + v9 + 1;
    v24 = (CSize)__PAIR64__(cy, result.cy);
    v23.y = top;
LABEL_55:
    v23.x = v15;
    CMFCTabCtrl::ReposButtons(this, pt: v23, sizeButton: v24, bHide: v26, nButtonMargin: bottom);
    goto LABEL_56;
  }
  if ( this->m_location != LOCATION_BOTTOM )
    this->m_rectTabsArea.bottom = nTabsHeight + this->m_rectTabsArea.top;
  else
    this->m_rectTabsArea.top = this->m_rectTabsArea.bottom - nTabsHeight;
  if ( this->m_bScroll != 0 )
  {
    this->m_rectTabsArea.right -= v4;
    if ( (this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bLeftRightRounded != 0)
      && this->m_bTabDocumentsMenu == 0 )
    {
      OffsetRect(lprc: &this->m_rectTabsArea, dx: v3, dy: 0);
    }
    bottom = Rect.bottom;
    v26 = bHideTabs;
    v24.cy = v3;
    v15 = this->m_rectTabsArea.right + 1;
    v24.cx = v3;
    v23.y = (this->m_rectTabsArea.top + this->m_rectTabsArea.bottom) / 2 - v3 / 2;
    goto LABEL_55;
  }
LABEL_56:
  this->m_rectWndArea = rectClient;
  SystemMetrics = GetSystemMetrics(nIndex: 2);
  v17 = nTabBorderSize;
  this->m_nScrollBarRight = this->m_rectTabsArea.right - SystemMetrics;
  if ( v17 > 0 )
  {
    InflateRect(lprc: &this->m_rectWndArea, dx: -1 - v17, dy: -1 - v17);
    if ( this->m_ResizeMode == RESIZE_VERT )
    {
      this->m_rectWndArea.right += v17 + 2;
    }
    else if ( this->m_ResizeMode == RESIZE_HORIZ )
    {
      this->m_rectWndArea.bottom += v17 + 2;
    }
  }
  if ( this->m_bFlat != 0 )
  {
    if ( this->m_location != LOCATION_BOTTOM )
    {
      this->m_rectWndArea.top = v17 + this->m_rectTabsArea.bottom;
      if ( v17 == 0 )
      {
        --this->m_rectWndArea.bottom;
        goto LABEL_67;
      }
    }
    else
    {
      this->m_rectWndArea.bottom = this->m_rectTabsArea.top;
      if ( v17 == 0 )
      {
        ++this->m_rectWndArea.top;
LABEL_67:
        ++this->m_rectWndArea.left;
      }
    }
  }
  else if ( this->m_location != LOCATION_BOTTOM )
  {
    this->m_rectWndArea.top = v17 + this->m_rectTabsArea.bottom;
  }
  else
  {
    this->m_rectWndArea.bottom = this->m_rectTabsArea.top - v17;
  }
  if ( this->m_bAutoSizeWindow != 0 )
  {
    for ( i = 0; i < this->m_iTabsNum; ++i )
    {
      if ( i < 0 || i >= this->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      v19 = this->m_arTabs.m_pData[i];
      if ( *((_DWORD *)v19 + 13) != 0 )
      {
        v20 = *((CWnd **)v19 + 8);
        if ( v20 != nullptr && v20->m_hWnd != nullptr )
          CWnd::SetWindowPos(
            this: v20,
            pWndInsertAfter: nullptr,
            x: this->m_rectWndArea.left,
            y: this->m_rectWndArea.top,
            cx: this->m_rectWndArea.right - this->m_rectWndArea.left,
            cy: this->m_rectWndArea.bottom - this->m_rectWndArea.top,
            nFlags: 0x14u);
      }
    }
  }
  this->AdjustWndScroll(this);
  this->AdjustTabs(this);
  this->AdjustTabsScroll(this);
  rectFrame = rectClient;
  if ( nTabBorderSize != 0 )
  {
    m_bFlat = this->m_bFlat;
    if ( m_bFlat == 0 )
    {
      if ( this->m_location != LOCATION_BOTTOM )
        rectFrame.top = this->m_rectTabsArea.bottom;
      else
        rectFrame.bottom = this->m_rectTabsArea.top;
    }
    if ( this->m_bFlatFrame != 0 )
    {
      Rect = rectFrame.tagRECT;
      if ( m_bFlat != 0 )
      {
        if ( this->m_location != LOCATION_BOTTOM )
          Rect.top = this->m_rectTabsArea.bottom - 1;
        else
          Rect.bottom = this->m_rectTabsArea.top + 1;
      }
      p_Rect = (CRect *)&Rect;
      goto LABEL_97;
    }
    InflateRect(lprc: &rectFrame, dx: -1, dy: -1);
  }
  else if ( this->m_location != LOCATION_BOTTOM )
  {
    rectFrame.top = this->m_rectTabsArea.bottom - 1;
  }
  else
  {
    rectFrame.bottom = this->m_rectTabsArea.top + 1;
  }
  p_Rect = &rectFrame;
LABEL_97:
  InvalidateRect(hWnd: this->m_hWnd, lpRect: p_Rect, bErase: true);
  v27 = this->m_hWnd;
  memset(&rcUpdateArea, 0, sizeof(rcUpdateArea));
  GetClientRect(hWnd: v27, lpRect: &rcUpdateArea);
  if ( this->m_location != LOCATION_BOTTOM )
    rcUpdateArea.bottom = this->m_rectWndArea.bottom;
  else
    rcUpdateArea.top = this->m_rectWndArea.top;
  InvalidateRect(hWnd: this->m_hWnd, lpRect: &rcUpdateArea, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10404408
// Name: protected: void CMFCTabCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnLButtonUp(CMFCTabCtrl *this, unsigned int nFlags, CPoint point)
{
  int v4; // ecx
  int SystemMetrics; // edi
  HWND Capture; // eax
  HWND Parent; // eax
  CWnd *v8; // eax
  CPoint pointDelta; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_bTrackSplitter != 0 || this->m_bResize != 0 )
  {
    CMFCTabCtrl::StopResize(this, bCancel: 0);
    this->m_bTrackSplitter = 0;
    this->m_bResize = 0;
    ReleaseCapture();
  }
  if ( this->IsMDITabGroup(this) != 0 )
  {
    pointDelta.x = 0;
    pointDelta.y = 0;
    GetCursorPos(lpPoint: &pointDelta);
    v4 = this->m_ptHot.y - pointDelta.y;
    pointDelta.x = this->m_ptHot.x - pointDelta.x;
    pointDelta.y = v4;
    SystemMetrics = GetSystemMetrics(nIndex: 68);
    Capture = GetCapture();
    if ( CWnd::FromHandle(hWnd: Capture) == this
      && this->m_bReadyToDetach != 0
      && (abs(lnumber: pointDelta.x) > SystemMetrics || abs(lnumber: pointDelta.y) > SystemMetrics) )
    {
      ReleaseCapture();
      if ( ((int (__thiscall *)(CMFCTabCtrl *, int, int))this->IsPtInTabArea)(a1: this, a2: point.x, a3: point.y) == 0 )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v8 = CWnd::FromHandle(hWnd: Parent);
        SendMessageA(
          hWnd: v8->m_hWnd,
          Msg: AFX_WM_ON_MOVETABCOMPLETE,
          wParam: (WPARAM)this,
          lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
      }
    }
    else
    {
      CMFCTabCtrl::ActivateMDITab(this, nTab: -1);
    }
  }
  CMFCBaseTabCtrl::OnLButtonUp(this, nFlags, point);
}

//------------------------------------------------------------------------------
// Address: 0x1040451D
// Name: public: int CMFCTabCtrl::SynchronizeScrollBar(struct tagSCROLLINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::SynchronizeScrollBar(CMFCTabCtrl *this, tagSCROLLINFO *pScrollInfo)
{
  CMFCTabCtrl_vtbl *v4; // eax
  CWnd *v5; // eax
  tagSCROLLINFO scrollInfo; // [esp+8h] [ebp-20h] BYREF

  if ( this->m_bSharedScroll == 0 )
    return 0;
  memset(dst: (unsigned __int8 *)&scrollInfo, value: 0, count: sizeof(scrollInfo));
  v4 = this->__vftable;
  scrollInfo.cbSize = 28;
  scrollInfo.fMask = 23;
  v5 = v4->GetActiveWnd(this);
  if ( pScrollInfo != nullptr )
  {
    scrollInfo = *pScrollInfo;
  }
  else if ( v5 != nullptr
         && (CWnd::GetScrollInfo(this: v5, nBar: 0, lpScrollInfo: &scrollInfo, nMask: 0x17u) == 0
          || (signed int)(scrollInfo.nMin + scrollInfo.nPage) >= scrollInfo.nMax) )
  {
    EnableScrollBar(hWnd: this->m_wndScrollWnd.m_hWnd, wSBflags: 2u, wArrows: 3u);
    return 1;
  }
  EnableScrollBar(hWnd: this->m_wndScrollWnd.m_hWnd, wSBflags: 2u, wArrows: 0);
  CWnd::SetScrollInfo(this: &this->m_wndScrollWnd, nBar: 2, lpScrollInfo: &scrollInfo, bRedraw: 1);
  CMFCTabCtrl::HideActiveWindowHorzScrollBar(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104196BB
// Name: public: virtual void CMFCOutlookBarToolBar::AdjustLocations(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarToolBar::AdjustLocations(CMFCOutlookBarToolBar *this)
{
  CMFCOutlookBarToolBar *v1; // edi
  long double m_dblRibbonImageScale; // st7
  int cx; // eax
  int v4; // ebx
  int m_nCount; // ecx
  int v6; // esi
  int m_pNodeTail; // eax
  CObject *v8; // ebx
  CObject *v9; // eax
  CMFCCustomizeButton *m_pCustomizeBtn; // edi
  CObject v11; // eax
  int v12; // ecx
  int cy; // eax
  CObject v14; // eax
  HWND m_hWnd; // [esp-8h] [ebp-70h]
  CObject_vtbl *v16; // [esp+18h] [ebp-50h]
  CSize result; // [esp+2Ch] [ebp-3Ch] BYREF
  CMFCOutlookBarToolBar *v18; // [esp+34h] [ebp-34h]
  int nCountToHide; // [esp+38h] [ebp-30h]
  double pos; // [esp+3Ch] [ebp-2Ch] BYREF
  CSize sizeButton; // [esp+44h] [ebp-24h]
  CSize sizeImage; // [esp+4Ch] [ebp-1Ch] BYREF
  CRect rectToolbar; // [esp+54h] [ebp-14h] BYREF

  v1 = this;
  v18 = this;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  pos = m_dblRibbonImageScale;
  CMFCToolBar::GetImageSize(this, result: &sizeImage);
  cx = sizeImage.cx;
  if ( sizeImage.cx == 0 && sizeImage.cy == 0 )
  {
    cx = 16;
    sizeImage.cy = 16;
  }
  v4 = cx + 10;
  sizeButton.cy = sizeImage.cy + 14;
  sizeButton.cx = cx + 10;
  if ( 1.0 != pos )
  {
    v4 = (int)((double)sizeButton.cx * pos + 0.5);
    sizeButton.cx = v4;
    sizeButton.cy = (int)((double)sizeButton.cy * pos + 0.5);
  }
  sizeImage.cx = 0;
  sizeImage.cy = 0;
  if ( v1->m_pCustomizeBtn != nullptr )
  {
    sizeImage.cy = sizeButton.cy;
    sizeImage.cx = v4;
    if ( v4 <= CMenuImages::Size(result: (CSize *)&pos)->cx + 10 )
      sizeImage.cx = CMenuImages::Size(&result)->cx + 10;
  }
  m_hWnd = v1->m_hWnd;
  memset(&rectToolbar, 0, sizeof(rectToolbar));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectToolbar);
  if ( sizeImage.cx != 0 || sizeImage.cy != 0 )
    m_nCount = v1->m_Buttons.m_nCount - 1;
  else
    m_nCount = v1->m_Buttons.m_nCount;
  v6 = rectToolbar.right - sizeImage.cx + 2;
  result.cy = v6;
  m_pNodeTail = (int)v1->m_Buttons.m_pNodeTail;
  nCountToHide = m_nCount - (rectToolbar.right - rectToolbar.left - sizeImage.cx + 2) / (v4 - 2);
  if ( m_pNodeTail != 0 )
  {
    while ( 1 )
    {
      v8 = *(CObject **)(m_pNodeTail + 8);
      HIDWORD(pos) = *(_DWORD *)(m_pNodeTail + 4);
      v9 = AfxDynamicDownCast(pClass: &CMFCCustomizeButton::classCMFCCustomizeButton, pObject: v8);
      if ( nCountToHide <= 0 || v9 != nullptr )
      {
        v12 = sizeButton.cx;
        cy = sizeButton.cy;
        if ( v8 == v1->m_pCustomizeBtn )
        {
          v12 = sizeImage.cx;
          cy = sizeImage.cy;
        }
        v16 = (CObject_vtbl *)cy;
        v14.__vftable = v8->__vftable;
        v8[21].__vftable = (CObject_vtbl *)v6;
        v8[22].__vftable = (CObject_vtbl *)-1;
        v8[23].__vftable = (CObject_vtbl *)(v6 + v12);
        v8[24].__vftable = v16;
        v14.__vftable[4].GetRuntimeClass(this: v8);
        result.cy += 2 - sizeButton.cx;
      }
      else
      {
        m_pCustomizeBtn = v1->m_pCustomizeBtn;
        if ( m_pCustomizeBtn != nullptr )
          CObList::AddHead(this: &m_pCustomizeBtn->m_lstInvisibleButtons, newElement: v8);
        v11.__vftable = v8->__vftable;
        v8[21].__vftable = nullptr;
        v8[22].__vftable = nullptr;
        v8[23].__vftable = nullptr;
        v8[24].__vftable = nullptr;
        v11.__vftable[4].GetRuntimeClass(this: v8);
        --nCountToHide;
      }
      v1 = v18;
      if ( HIDWORD(pos) == 0 )
        break;
      m_pNodeTail = HIDWORD(pos);
      v6 = result.cy;
    }
  }
  CMFCToolBar::UpdateTooltips(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x104198BC
// Name: public: CMFCOutlookBarTabCtrl::CMFCOutlookBarTabCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarTabCtrl *__thiscall CMFCOutlookBarTabCtrl::CMFCOutlookBarTabCtrl(CMFCOutlookBarTabCtrl *this)
{
  CMFCBaseTabCtrl::CMFCBaseTabCtrl(this);
  this->__vftable = (CMFCOutlookBarTabCtrl_vtbl *)&CMFCOutlookBarTabCtrl::`vftable';
  this->m_rectWndArea.left = 0;
  this->m_rectWndArea.top = 0;
  this->m_rectWndArea.right = 0;
  this->m_rectWndArea.bottom = 0;
  this->m_rectCaption.left = 0;
  this->m_rectCaption.top = 0;
  this->m_rectCaption.right = 0;
  this->m_rectCaption.bottom = 0;
  this->m_rectSplitter.left = 0;
  this->m_rectSplitter.top = 0;
  this->m_rectSplitter.right = 0;
  this->m_rectSplitter.bottom = 0;
  this->m_sizeToolbarImage.cx = 0;
  this->m_sizeToolbarImage.cy = 0;
  CImageList::CImageList(this: &this->m_imagesToolbar);
  CMFCOutlookBarToolBar::CMFCOutlookBarToolBar(this: &this->m_wndToolBar, pParentBar: this);
  CMFCButton::CMFCButton(this: &this->m_btnUp);
  this->m_btnUp.__vftable = (CMFCOutlookBarScrollButton_vtbl *)&CMFCOutlookBarScrollButton::`vftable';
  CMFCButton::CMFCButton(this: &this->m_btnDown);
  this->m_btnDown.__vftable = (CMFCOutlookBarScrollButton_vtbl *)&CMFCOutlookBarScrollButton::`vftable';
  SetRectEmpty(lprc: &this->m_rectWndArea);
  SetRectEmpty(lprc: &this->m_rectCaption);
  this->m_btnUp.m_nFlatStyle = BUTTONSTYLE_SEMIFLAT;
  this->m_btnDown.m_nFlatStyle = BUTTONSTYLE_SEMIFLAT;
  this->m_nBorderSize = 0;
  this->m_bActivateOnBtnUp = 1;
  this->m_bEnableTabSwap = 0;
  this->m_bScrollButtons = 0;
  this->m_btnUp.m_bDrawFocus = 0;
  this->m_btnDown.m_bDrawFocus = 0;
  this->m_nPageButtonTextAlign = 6;
  this->m_bIsTracking = 0;
  SetRectEmpty(lprc: &this->m_rectSplitter);
  this->m_nVisiblePageButtons = -1;
  this->m_sizeToolbarImage.cx = 0;
  this->m_nMaxVisiblePageButtons = 0;
  this->m_bDontAdjustLayout = 0;
  this->m_sizeToolbarImage.cy = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10419A02
// Name: public: virtual void CMFCOutlookBarTabCtrl::EnableInPlaceEdit(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::EnableInPlaceEdit(CMFCOutlookBarTabCtrl *this, int bEnable)
{
  this->m_bIsInPlaceEdit = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10419A14
// Name: public: virtual void CMFCOutlookBarTabCtrl::CalcRectEdit(class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::CalcRectEdit(CMFCOutlookBarTabCtrl *this, CRect *rectEdit)
{
  InflateRect(lprc: rectEdit, dx: -1, dy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10419A2A
// Name: public: virtual CMFCOutlookBarTabCtrl::~CMFCOutlookBarTabCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::~CMFCOutlookBarTabCtrl(CMFCOutlookBarTabCtrl *this)
{
  this->__vftable = (CMFCOutlookBarTabCtrl_vtbl *)&CMFCOutlookBarTabCtrl::`vftable';
  CMFCButton::~CMFCButton(this: &this->m_btnDown);
  CMFCButton::~CMFCButton(this: &this->m_btnUp);
  CMFCOutlookBarToolBar::~CMFCOutlookBarToolBar(this: &this->m_wndToolBar);
  CImageList::~CImageList(this: &this->m_imagesToolbar);
  CMFCBaseTabCtrl::~CMFCBaseTabCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x10419A91
// Name: public: virtual class CWnd __near * CMFCOutlookBarTabCtrl::FindTargetWnd(class CPoint const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCOutlookBarTabCtrl::FindTargetWnd(CMFCOutlookBarTabCtrl *this, const CPoint *pt)
{
  int v3; // edi
  const RECT *v4; // eax
  HWND Parent; // eax

  v3 = 0;
  if ( this->m_iTabsNum <= 0 )
  {
LABEL_7:
    Parent = GetParent(hWnd: this->m_hWnd);
    return CWnd::FromHandle(hWnd: Parent);
  }
  else
  {
    while ( 1 )
    {
      if ( v3 < 0 || v3 >= this->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      v4 = (const RECT *)this->m_arTabs.m_pData[v3];
      if ( v4[3].top != 0 && PtInRect(lprc: v4 + 1, pt: pt->tagPOINT) )
        return nullptr;
      if ( ++v3 >= this->m_iTabsNum )
        goto LABEL_7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10419AFF
// Name: protected: void CMFCOutlookBarTabCtrl::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnSize(CMFCOutlookBarTabCtrl *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
  this->RecalcLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10419B9F
// Name: protected: int CMFCOutlookBarTabCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::OnCreate(CMFCOutlookBarTabCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  CMFCOutlookBarScrollButton_vtbl *v4; // eax
  HWND__ *m_hWnd; // eax
  CMFCOutlookBarToolBar_vtbl *v6; // edi
  int v7; // eax
  CRect rectDummy; // [esp+1Ch] [ebp-14h] BYREF

  result = CMFCBaseTabCtrl::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    v4 = this->m_btnUp.__vftable;
    memset(&rectDummy, 0, sizeof(rectDummy));
    v4->Create_2(this: &this->m_btnUp, a2: &var, a3: 0x40000000u, a4: &rectDummy, a5: this, a6: -1u);
    CMFCButton::SetStdImage(this: &this->m_btnUp, id: IdArrowUpLarge, state: ImageBlack, idDisabled: IdArrowDown);
    CMFCButton::SetAutorepeatMode(this: &this->m_btnUp, nTimeDelay: 100);
    this->m_btnDown.Create_2(this: &this->m_btnDown, a2: &var, a3: 0x40000000u, a4: &rectDummy, a5: this, a6: -1u);
    CMFCButton::SetStdImage(this: &this->m_btnDown, id: IdArrowDownLarge, state: ImageBlack, idDisabled: IdArrowDown);
    CMFCButton::SetAutorepeatMode(this: &this->m_btnDown, nTimeDelay: 100);
    this->m_wndToolBar.m_bLargeIconsAreEnbaled = 0;
    ((void (__stdcall *)(CMFCOutlookBarTabCtrl *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int))this->m_wndToolBar.CreateEx)(
      a1: this,
      a2: 2048,
      a3: 1346381832,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: 0,
      a8: 59392);
    m_hWnd = this->m_hWnd;
    v6 = this->m_wndToolBar.__vftable;
    this->m_wndToolBar.m_bRouteCommandsViaFrame = 0;
    this->m_wndToolBar.m_hWndOwner = m_hWnd;
    v7 = v6->GetPaneStyle(this: &this->m_wndToolBar);
    v6->SetPaneStyle(this: &this->m_wndToolBar, a2: v7 & 0xFFBFF0FF);
    this->m_wndToolBar.m_bShowHotBorder = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419CE1
// Name: protected: virtual int CMFCOutlookBarTabCtrl::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::OnCommand(CMFCOutlookBarTabCtrl *this, unsigned int wParam, HWND__ *lParam)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  CObject *v6; // ecx
  CMFCOutlookBarScrollButton *p_m_btnUp; // edi
  HWND__ *m_hWnd; // eax
  HWND__ *v10; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  v6 = AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v5);
  if ( v6 == nullptr )
    return CWnd::OnCommand(this, wParam, (int)lParam);
  p_m_btnUp = &this->m_btnUp;
  if ( this == (CMFCOutlookBarTabCtrl *)-3912 )
    m_hWnd = nullptr;
  else
    m_hWnd = this->m_btnUp.m_hWnd;
  if ( m_hWnd != lParam )
  {
    p_m_btnUp = &this->m_btnDown;
    if ( this == (CMFCOutlookBarTabCtrl *)-5784 )
      v10 = nullptr;
    else
      v10 = this->m_btnDown.m_hWnd;
    if ( v10 == lParam )
    {
      ((void (__thiscall *)(CObject *, int))v6->__vftable[84].dtr_CObject)(a1: v6, a2: 1);
      goto LABEL_7;
    }
    return CWnd::OnCommand(this, wParam, (int)lParam);
  }
  ((void (__thiscall *)(CObject *, _DWORD))v6->__vftable[84].dtr_CObject)(a1: v6, a2: 0);
LABEL_7:
  if ( CWnd::IsWindowEnabled(this: p_m_btnUp) == 0 )
    CWnd::SetFocus(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10419D70
// Name: public: int CMFCOutlookBarTabCtrl::IsMode2003(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarTabCtrl::IsMode2003(CMFCOutlookBarTabCtrl *this)
{
  HWND Parent; // eax
  CWnd *v2; // eax
  CObject *v3; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  v3 = AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v2);
  return v3 != nullptr && v3[227].__vftable != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10419DA0
// Name: public: virtual int CMFCOutlookBarTabCtrl::IsTabDetachable(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::IsTabDetachable(CMFCOutlookBarTabCtrl *this, int iTab)
{
  if ( CMFCOutlookBarTabCtrl::IsMode2003(this) )
    return 0;
  else
    return CMFCBaseTabCtrl::IsTabDetachable(this, iTab);
}

//------------------------------------------------------------------------------
// Address: 0x10419DC4
// Name: protected: void CMFCOutlookBarTabCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnLButtonDown(CMFCOutlookBarTabCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-8h]

  if ( PtInRect(lprc: &this->m_rectSplitter, pt: point.tagPOINT) )
  {
    m_hWnd = this->m_hWnd;
    this->m_bIsTracking = 1;
    v4 = SetCapture(hWnd: m_hWnd);
    CWnd::FromHandle(hWnd: v4);
  }
  else
  {
    CMFCBaseTabCtrl::OnLButtonDown(this, nFlags, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10419E13
// Name: protected: void CMFCOutlookBarTabCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnMouseMove(CMFCOutlookBarTabCtrl *this, unsigned int nFlags, CPoint point)
{
  int v4; // edi
  int m_nTabsHeight; // ecx
  int v6; // eax
  int v7; // eax
  int m_nVisiblePageButtons; // ebx
  int v9; // eax
  CMFCOutlookBarTabCtrl_vtbl *v10; // eax

  v4 = 0;
  if ( this->m_bIsTracking != 0 )
  {
    m_nTabsHeight = this->m_nTabsHeight;
    if ( m_nTabsHeight != 0 && this->m_nVisiblePageButtons != -1 )
    {
      v6 = (this->m_rectSplitter.top - point.y) / m_nTabsHeight;
      if ( v6 != 0 )
      {
        v7 = this->m_nVisiblePageButtons + v6;
        m_nVisiblePageButtons = this->m_nVisiblePageButtons;
        this->m_nVisiblePageButtons = v7;
        if ( v7 >= 0 )
          v4 = v7;
        if ( this->GetVisibleTabsNum(this) >= v4 )
        {
          v9 = this->m_nVisiblePageButtons;
          if ( v9 < 0 )
            v9 = 0;
        }
        else
        {
          v9 = this->GetVisibleTabsNum(this);
        }
        this->m_nVisiblePageButtons = v9;
        if ( m_nVisiblePageButtons != v9 )
        {
          v10 = this->__vftable;
          this->m_bDontAdjustLayout = 1;
          v10->RecalcLayout(this);
          this->m_bDontAdjustLayout = 0;
          point.y = (this->m_rectSplitter.top + this->m_rectSplitter.bottom) / 2;
          ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
          SetCursorPos(X: point.x, Y: point.y);
        }
      }
    }
  }
  else
  {
    CMFCBaseTabCtrl::OnMouseMove(this, nFlags, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10419EFE
// Name: public: COutlookOptionsDlg::COutlookOptionsDlg(class CMFCOutlookBarTabCtrl __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COutlookOptionsDlg *__thiscall COutlookOptionsDlg::COutlookOptionsDlg(
        COutlookOptionsDlg *this,
        CMFCOutlookBarTabCtrl *parentBar)
{
  CDialog::CDialog(this, nIDTemplate: 0x426Cu, pParentWnd: parentBar);
  this->__vftable = (COutlookOptionsDlg_vtbl *)&COutlookOptionsDlg::`vftable';
  CWnd::CWnd(this: &this->m_btnMoveUp);
  this->m_btnMoveUp.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndMoveDown);
  this->m_wndMoveDown.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndReset);
  this->m_wndReset.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CMFCToolBarsListCheckBox::CMFCToolBarsListCheckBox(this: &this->m_wndList);
  this->m_parentBar = parentBar;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10419FA9
// Name: protected: virtual void COutlookOptionsDlg::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::DoDataExchange(COutlookOptionsDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x4281, rControl: (HWND__ *)&this->m_btnMoveUp);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4282, rControl: (HWND__ *)&this->m_wndMoveDown);
  DDX_Control(pDX, nIDC: (HWND__ *)0x421B, rControl: (HWND__ *)&this->m_wndList);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40E5, rControl: (HWND__ *)&this->m_wndReset);
}

//------------------------------------------------------------------------------
// Address: 0x1041A003
// Name: protected: void COutlookOptionsDlg::OnSelchange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::OnSelchange(COutlookOptionsDlg *this)
{
  LRESULT v2; // eax
  LRESULT v3; // ebx
  LRESULT v4; // eax

  v2 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_btnMoveUp, bEnable: v2 > 0);
  v3 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v4 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_wndMoveDown, bEnable: v3 < v4 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1041A06D
// Name: protected: void COutlookOptionsDlg::OnDblclkList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::OnDblclkList(COutlookOptionsDlg *this)
{
  LRESULT v2; // eax
  int v3; // edi
  int v4; // eax

  v2 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 >= 0 )
  {
    v4 = CCheckListBox::GetCheck(this: &this->m_wndList, nIndex: v2);
    CCheckListBox::SetCheck(this: &this->m_wndList, nIndex: v3, nCheck: v4 == 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041A0AF
// Name: public: virtual void CMFCOutlookBarTabCtrl::OnShowOptions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnShowOptions(CMFCOutlookBarTabCtrl *this)
{
  CMFCOutlookBarTabCtrl_vtbl *v2; // eax
  COutlookOptionsDlg dlg; // [esp+10h] [ebp-290h] BYREF
  int v4; // [esp+29Ch] [ebp-4h]

  COutlookOptionsDlg::COutlookOptionsDlg(this: &dlg, parentBar: this);
  v4 = 0;
  if ( CDialog::DoModal(this: &dlg) == 1 )
  {
    v2 = this->__vftable;
    this->m_bDontAdjustLayout = 1;
    v2->RecalcLayout(this);
    this->m_bDontAdjustLayout = 0;
  }
  v4 = -1;
  COutlookOptionsDlg::~COutlookOptionsDlg(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x1041A12F
// Name: public: static class CObject __near * CMFCOutlookBarTabCtrl::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarTabCtrl *__stdcall CMFCOutlookBarTabCtrl::CreateObject()
{
  CMFCOutlookBarTabCtrl *v0; // ecx
  CMFCOutlookBarTabCtrl *result; // eax

  v0 = (CMFCOutlookBarTabCtrl *)operator new(nSize: 0x1DE8u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCOutlookBarTabCtrl::CMFCOutlookBarTabCtrl(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A180
// Name: public: void CMFCOutlookBarTabCtrl::EnableScrollButtons(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::EnableScrollButtons(
        CMFCOutlookBarTabCtrl *this,
        int bEnable,
        int bIsUp,
        int bIsDown)
{
  int v5; // ecx
  bool v6; // zf
  BOOL v7; // edx
  CMFCOutlookBarScrollButton *p_m_btnUp; // ecx
  int bRecalcLayout; // [esp+14h] [ebp+8h]

  if ( CMFCOutlookBarTabCtrl::IsMode2003(this) )
    v5 = 0;
  else
    v5 = bEnable;
  v6 = this->m_bScrollButtons == v5;
  this->m_bScrollButtons = v5;
  v7 = !v6;
  v6 = v5 == 0;
  p_m_btnUp = &this->m_btnUp;
  bRecalcLayout = v7;
  if ( v6 )
  {
    CWnd::ShowWindow(this: p_m_btnUp, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_btnDown, nCmdShow: 0);
  }
  else
  {
    CWnd::ShowWindow(this: p_m_btnUp, nCmdShow: 4);
    CWnd::EnableWindow(this: &this->m_btnUp, bEnable: bIsUp);
    CMFCButton::SetStdImage(
      this: &this->m_btnUp,
      id: IdArrowUpLarge,
      state: (CMenuImages::IMAGE_STATE)(bIsUp == 0),
      idDisabled: IdArrowDown);
    CWnd::ShowWindow(this: &this->m_btnDown, nCmdShow: 4);
    CWnd::EnableWindow(this: &this->m_btnDown, bEnable: bIsDown);
    CMFCButton::SetStdImage(
      this: &this->m_btnDown,
      id: IdArrowDownLarge,
      state: (CMenuImages::IMAGE_STATE)(bIsDown == 0),
      idDisabled: IdArrowDown);
  }
  RedrawWindow(hWnd: this->m_btnUp.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  RedrawWindow(hWnd: this->m_btnDown.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  if ( bRecalcLayout != 0 )
    this->RecalcLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041A267
// Name: protected: virtual void COutlookOptionsDlg::OnOK(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::OnOK(COutlookOptionsDlg *this)
{
  int v2; // eax
  CMFCOutlookBarTabCtrl *m_parentBar; // ecx
  int v4; // eax
  LRESULT v5; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-4Ch]
  CArray<int,int> arTabsOrder; // [esp+10h] [ebp-2Ch] BYREF
  int bVisible; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  int nIndex; // [esp+2Ch] [ebp-10h]
  int v11; // [esp+38h] [ebp-4h]

  arTabsOrder.__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
  memset(&arTabsOrder.m_pData, 0, 16);
  m_hWnd = this->m_wndList.m_hWnd;
  v11 = 0;
  nIndex = 0;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) > 0 )
  {
    do
    {
      i = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x199u, wParam: nIndex, lParam: 0);
      v2 = CCheckListBox::GetCheck(this: &this->m_wndList, nIndex);
      m_parentBar = this->m_parentBar;
      bVisible = v2;
      v4 = m_parentBar->IsTabVisible(this: m_parentBar, a2: i);
      if ( bVisible != v4 )
        this->m_parentBar->ShowTab(this: this->m_parentBar, a2: i, a3: bVisible, a4: 0, a5: 0);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&arTabsOrder,
        nIndex: arTabsOrder.m_nSize,
        newElement: (CMFCRibbonKeyTip *)i);
      ++nIndex;
      v5 = SendMessageA(hWnd: this->m_wndList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
    }
    while ( nIndex < v5 );
  }
  CMFCBaseTabCtrl::SetTabsOrder(this: this->m_parentBar, arOrder: &arTabsOrder);
  CDialog::OnOK(this);
  v11 = -1;
  CArray<int,int>::~CArray<int,int>(this: &arTabsOrder);
}

//------------------------------------------------------------------------------
// Address: 0x1041A347
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCOutlookBarToolBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCOutlookBarToolBar::GetMessageMap(CMFCOutlookBarToolBar *this)
{
  return (const AFX_MSGMAP *)&off_1068EF64;
}

//------------------------------------------------------------------------------
// Address: 0x1041A34D
// Name: public: virtual int CMFCOutlookBarToolBar::OnSendCommand(class CMFCToolBarButton const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarToolBar::OnSendCommand(CMFCOutlookBarToolBar *this, int pButton)
{
  signed int v3; // eax
  const CMFCToolBarButton *v4; // eax
  CMFCOutlookBarTabCtrl *m_pParentBar; // esi
  UINT v6; // edi
  CFrameWnd *ParentFrame; // eax

  v3 = CMFCToolBar::ButtonToIndex(this, (const CMFCToolBarButton *)pButton);
  if ( v3 < 0 )
    return 0;
  pButton = -1;
  if ( CMap<int,int,unsigned int,unsigned int>::Lookup(this: &this->m_TabButtons, key: v3, rValue: &pButton) == 0 )
    return 0;
  v4 = (const CMFCToolBarButton *)this->m_pParentBar->GetActiveTab(this: this->m_pParentBar);
  if ( v4 == (const CMFCToolBarButton *)pButton )
    return 0;
  if ( this->m_pParentBar->SetActiveTab(this: this->m_pParentBar, a2: pButton) != 0
    && CWnd::GetParentFrame(this: this->m_pParentBar) != nullptr )
  {
    m_pParentBar = this->m_pParentBar;
    v6 = AFX_WM_CHANGE_ACTIVE_TAB;
    ParentFrame = CWnd::GetParentFrame(this: m_pParentBar);
    SendMessageA(hWnd: ParentFrame->m_hWnd, Msg: v6, wParam: pButton, lParam: (LPARAM)m_pParentBar);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042A6D5
// Name: protected: void CMFCColorDialog::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorDialog::OnMouseMove(CMFCColorDialog *this, unsigned int nFlags, CPoint point)
{
  COLORREF Pixel; // eax
  CClientDC dc; // [esp+10h] [ebp-20h] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  if ( this->m_bPickerMode != 0 )
  {
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
    CClientDC::CClientDC(this: &dc, pWnd: nullptr);
    v6 = 0;
    Pixel = GetPixel(hdc: dc.m_hDC, x: point.x, y: point.y);
    CMFCColorDialog::SetNewColor(this, rgb: Pixel);
    v6 = -1;
    CClientDC::~CClientDC(this: &dc);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042A739
// Name: protected: void CMFCColorDialog::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorDialog::OnLButtonDown(CMFCColorDialog *this, unsigned int nFlags, CPoint point)
{
  unsigned __int8 v4; // al

  v4 = BYTE2(this->m_NewColor);
  this->m_bPickerMode = 0;
  CMFCColorDialog::SetPageOne(this, R: this->m_NewColor, G: BYTE1(this->m_NewColor), B: v4);
  CMFCCustomColorsPropertyPage::Setup(
    this: this->m_pColourSheetTwo,
    R: this->m_NewColor,
    G: BYTE1(this->m_NewColor),
    B: BYTE2(this->m_NewColor));
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042A7B9
// Name: protected: void CScreenWnd::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CScreenWnd::OnMouseMove(CScreenWnd *this, WPARAM nFlags, CPoint point)
{
  CMFCColorDialog *m_pColorDlg; // eax

  m_pColorDlg = this->m_pColorDlg;
  if ( m_pColorDlg != nullptr )
    m_pColorDlg = (CMFCColorDialog *)m_pColorDlg->m_hWnd;
  MapWindowPoints(hWndFrom: this->m_hWnd, hWndTo: (HWND)m_pColorDlg, lpPoints: &point, cPoints: 1u);
  SendMessageA(
    hWnd: this->m_pColorDlg->m_hWnd,
    Msg: 0x200u,
    wParam: nFlags,
    lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042A809
// Name: protected: void CScreenWnd::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CScreenWnd::OnLButtonDown(CScreenWnd *this, WPARAM nFlags, CPoint point)
{
  CMFCColorDialog *m_pColorDlg; // eax

  m_pColorDlg = this->m_pColorDlg;
  if ( m_pColorDlg != nullptr )
    m_pColorDlg = (CMFCColorDialog *)m_pColorDlg->m_hWnd;
  MapWindowPoints(hWndFrom: this->m_hWnd, hWndTo: (HWND)m_pColorDlg, lpPoints: &point, cPoints: 1u);
  SendMessageA(
    hWnd: this->m_pColorDlg->m_hWnd,
    Msg: 0x201u,
    wParam: nFlags,
    lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
}

//------------------------------------------------------------------------------
// Address: 0x1042A852
// Name: protected: void CMFCColorDialog::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorDialog::OnSysColorChange(CMFCColorDialog *this)
{
  int v2; // eax
  void *v3; // eax
  CColorDialog dlg; // [esp+10h] [ebp-C4h] BYREF
  int v5; // [esp+D0h] [ebp-4h]

  CDialogEx::OnSysColorChange(this);
  AFX_GLOBAL_DATA::UpdateSysColors(this: &afxGlobalData);
  if ( this->m_bIsMyPalette != 0 )
  {
    if ( afxGlobalData.m_nBitsPerPixel >= 8 )
    {
      v3 = CGdiObject::Detach(this: this->m_pPalette);
      DeleteObject(ho: v3);
      CMFCColorDialog::RebuildPalette(this);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
    else
    {
      CWnd::ShowWindow(this, nCmdShow: 0);
      CColorDialog::CColorDialog(this: &dlg, clrInit: this->m_CurrentColor, dwFlags: 0x102u, pParentWnd: nullptr);
      v5 = 0;
      v2 = CColorDialog::DoModal(this: &dlg);
      this->m_NewColor = dlg.m_cc.rgbResult;
      CDialog::EndDialog(this, nResult: v2);
      v5 = -1;
      dlg.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
      CDialog::~CDialog(this: &dlg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042A916
// Name: protected: virtual struct AFX_MSGMAP const __near * CScreenWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CScreenWnd::GetMessageMap(CScreenWnd *this)
{
  return (const AFX_MSGMAP *)&off_10693698;
}

//------------------------------------------------------------------------------
// Address: 0x1042A91C
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCColorDialog::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCColorDialog::GetMessageMap(CMFCColorDialog *this)
{
  return (const AFX_MSGMAP *)&off_10693718;
}

//------------------------------------------------------------------------------
// Address: 0x1042A922
// Name: public: virtual int CMFCColorDialog::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorDialog::PreTranslateMessage(CMFCColorDialog *this, tagMSG *pMsg)
{
  tagMSG *v3; // esi
  unsigned int wParam; // ebx
  CAfxStringMgr *StringManager; // eax
  int v6; // ecx
  int m_NewColor_low; // eax
  char *m_pszData; // esi
  HGLOBAL v9; // ebx
  CHAR *v10; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  v3 = pMsg;
  if ( pMsg->message == 256 )
  {
    wParam = pMsg->wParam;
    if ( GetAsyncKeyState(vKey: 17) < 0 && (wParam == 67 || wParam == 45) && OpenClipboard(hWndNewOwner: this->m_hWnd) )
    {
      EmptyClipboard();
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strText, pStringMgr: StringManager);
      v6 = BYTE2(this->m_NewColor);
      m_NewColor_low = LOBYTE(this->m_NewColor);
      v13 = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strText,
        pszFormat: "RGB(%d, %d, %d)",
        m_NewColor_low,
        BYTE1(this->m_NewColor),
        v6);
      m_pszData = strText.m_pszData;
      v9 = GlobalAlloc(uFlags: 0x2000u, dwBytes: *((_DWORD *)strText.m_pszData - 3) + 1);
      v10 = (CHAR *)GlobalLock(hMem: v9);
      lstrcpyA(lpString1: v10, lpString2: m_pszData);
      GlobalUnlock(hMem: v9);
      SetClipboardData(uFormat: 1u, hMem: v9);
      CloseClipboard();
      v13 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
      v3 = pMsg;
    }
  }
  return CDialogEx::PreTranslateMessage(this, pMsg: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1042AA0F
// Name: public: virtual CMFCColorDialog::~CMFCColorDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorDialog::~CMFCColorDialog(CMFCColorDialog *this)
{
  CMFCStandardColorsPropertyPage *m_pColourSheetOne; // ecx
  CMFCCustomColorsPropertyPage *m_pColourSheetTwo; // ecx

  this->__vftable = (CMFCColorDialog_vtbl *)&CMFCColorDialog::`vftable';
  m_pColourSheetOne = this->m_pColourSheetOne;
  if ( m_pColourSheetOne != nullptr )
    ((void (__thiscall *)(CMFCStandardColorsPropertyPage *, int))m_pColourSheetOne->dtr_CObject)(
      a1: m_pColourSheetOne,
      a2: 1);
  m_pColourSheetTwo = this->m_pColourSheetTwo;
  if ( m_pColourSheetTwo != nullptr )
    ((void (__thiscall *)(CMFCCustomColorsPropertyPage *, int))m_pColourSheetTwo->dtr_CObject)(
      a1: m_pColourSheetTwo,
      a2: 1);
  CMFCColorPickerCtrl::~CMFCColorPickerCtrl(this: &this->m_wndColors);
  CStatic::~CStatic(this: &this->m_wndStaticPlaceHolder);
  CMFCButton::~CMFCButton(this: &this->m_btnColorSelect);
  CDialogEx::~CDialogEx(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042AA8D
// Name: protected: virtual int CMFCColorDialog::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorDialog::OnInitDialog(CMFCColorDialog *this)
{
  CWnd *MainWnd; // eax
  int v3; // eax
  CPalette *v4; // eax
  CMFCColorPropertySheet *v5; // ecx
  CMFCColorPropertySheet *v6; // eax
  CMFCStandardColorsPropertyPage *v7; // ecx
  CMFCStandardColorsPropertyPage *v8; // eax
  CMFCCustomColorsPropertyPage *v9; // ecx
  CMFCCustomColorsPropertyPage *v10; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-F4h]
  CColorDialog v14; // [esp+10h] [ebp-DCh] BYREF
  void *pData; // [esp+C8h] [ebp-24h]
  tagRECT Rect; // [esp+CCh] [ebp-20h] BYREF
  int v17; // [esp+E8h] [ebp-4h]

  CDialog::OnInitDialog(this);
  if ( AfxGetMainWnd() != nullptr )
  {
    MainWnd = AfxGetMainWnd();
    if ( (CWnd::GetExStyle(this: MainWnd) & 0x400000) != 0 )
      CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: 0x400000u, nFlags: 0);
  }
  if ( afxGlobalData.m_nBitsPerPixel >= 8 )
  {
    if ( this->m_pPalette == nullptr )
    {
      v4 = (CPalette *)operator new(nSize: 8u);
      if ( v4 != nullptr )
      {
        v4->m_hObject = nullptr;
        v4->__vftable = (CPalette_vtbl *)&CPalette::`vftable';
      }
      else
      {
        v4 = nullptr;
      }
      this->m_pPalette = v4;
      CMFCColorDialog::RebuildPalette(this);
    }
    CControlBar::SetInPlaceOwner(this: &this->m_wndColors, colorType: CURRENT);
    CMFCColorPickerCtrl::SetPalette(this: &this->m_wndColors, pPalette: this->m_pPalette);
    CBasePane::SetControlBarStyle(this: &this->m_wndColors, ref: this->m_CurrentColor);
    CMFCColorPickerCtrl::SetColor(this: &this->m_wndColors, Color: this->m_NewColor);
    v5 = (CMFCColorPropertySheet *)operator new(nSize: 0xD0u);
    pData = v5;
    v17 = 1;
    if ( v5 != nullptr )
      v6 = CMFCColorPropertySheet::CMFCColorPropertySheet(this: v5, pszCaption: &var, pParentWnd: this, iSelectPage: 0);
    else
      v6 = nullptr;
    v17 = -1;
    this->m_pPropSheet = v6;
    if ( v6 == nullptr )
      AfxThrowInvalidArgException();
    v7 = (CMFCStandardColorsPropertyPage *)operator new(nSize: 0x228u);
    pData = v7;
    v17 = 2;
    if ( v7 != nullptr )
      v8 = CMFCStandardColorsPropertyPage::CMFCStandardColorsPropertyPage(this: v7);
    else
      v8 = nullptr;
    this->m_pColourSheetOne = v8;
    v9 = (CMFCCustomColorsPropertyPage *)operator new(nSize: 0x244u);
    pData = v9;
    v17 = 3;
    if ( v9 != nullptr )
      v10 = CMFCCustomColorsPropertyPage::CMFCCustomColorsPropertyPage(this: v9);
    else
      v10 = nullptr;
    v17 = -1;
    this->m_pColourSheetTwo = v10;
    this->m_pColourSheetOne->m_pDialog = this;
    this->m_pColourSheetTwo->m_pDialog = this;
    CPropertySheet::AddPage(this: this->m_pPropSheet, pPage: this->m_pColourSheetOne);
    CPropertySheet::AddPage(this: this->m_pPropSheet, pPage: this->m_pColourSheetTwo);
    m_hWnd = this->m_wndStaticPlaceHolder.m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    CWnd::ScreenToClient(this, lpRect: &Rect);
    this->m_pPropSheet->Create_2(this: this->m_pPropSheet, a2: this, a3: 1409286144u, a4: 0);
    CWnd::SetWindowPos(
      this: this->m_pPropSheet,
      pWndInsertAfter: nullptr,
      x: Rect.left,
      y: Rect.top,
      cx: Rect.right - Rect.left,
      cy: Rect.bottom - Rect.top,
      nFlags: 0x14u);
    CMFCColorDialog::SetPageOne(
      this,
      R: this->m_CurrentColor,
      G: BYTE1(this->m_CurrentColor),
      B: BYTE2(this->m_CurrentColor));
    CMFCCustomColorsPropertyPage::Setup(
      this: this->m_pColourSheetTwo,
      R: this->m_CurrentColor,
      G: BYTE1(this->m_CurrentColor),
      B: BYTE2(this->m_CurrentColor));
    CMFCButton::SetImage(this: &this->m_btnColorSelect, uiBmpResId: 0x4296u, uiBmpHotResId: 0, uiBmpDsblResID: 0);
    AfxGetModuleState();
    ModuleState = AfxGetModuleState();
    this->m_hcurPicker = LoadCursorW(hInstance: ModuleState->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F11);
  }
  else
  {
    CColorDialog::CColorDialog(this: &v14, clrInit: this->m_CurrentColor, dwFlags: 0x102u, pParentWnd: nullptr);
    v17 = 0;
    v3 = CColorDialog::DoModal(this: &v14);
    this->m_NewColor = v14.m_cc.rgbResult;
    CDialog::EndDialog(this, nResult: v3);
    v17 = -1;
    v14.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
    CDialog::~CDialog(this: &v14);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042AD4C
// Name: public: CMFCColorDialog::CMFCColorDialog(unsigned long,unsigned long,class CWnd __near *,struct HPALETTE__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorDialog *__thiscall CMFCColorDialog::CMFCColorDialog(
        CMFCColorDialog *this,
        unsigned int clrInit,
        unsigned int __formal,
        CWnd *pParentWnd,
        HPALETTE__ *hPal)
{
  CPalette *v6; // eax

  CDialogEx::CDialogEx(this, nIDTemplate: 0x4241u, pParent: pParentWnd);
  this->__vftable = (CMFCColorDialog_vtbl *)&CMFCColorDialog::`vftable';
  CMFCButton::CMFCButton(this: &this->m_btnColorSelect);
  CWnd::CWnd(this: &this->m_wndStaticPlaceHolder);
  this->m_wndStaticPlaceHolder.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CMFCColorPickerCtrl::CMFCColorPickerCtrl(this: &this->m_wndColors);
  this->m_pPalette = nullptr;
  this->m_pColourSheetOne = nullptr;
  this->m_pColourSheetTwo = nullptr;
  this->m_NewColor = clrInit;
  this->m_CurrentColor = clrInit;
  this->m_pPropSheet = nullptr;
  this->m_bIsMyPalette = 1;
  if ( hPal != nullptr )
  {
    v6 = (CPalette *)CGdiObject::FromHandle(h: hPal);
    this->m_bIsMyPalette = 0;
    this->m_pPalette = v6;
  }
  this->m_bPickerMode = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042AE28
// Name: public: virtual int CScreenWnd::Create(class CMFCColorDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CScreenWnd::Create(CScreenWnd *this, CMFCColorDialog *pColorDlg)
{
  HWND DesktopWindow; // eax
  CWnd *v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HCURSOR CursorW; // eax
  const char *v8; // eax
  int v9; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v10; // [esp+10h] [ebp-24h] BYREF
  tagRECT Rect; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+30h] [ebp-4h]

  DesktopWindow = GetDesktopWindow();
  v4 = CWnd::FromHandle(hWnd: DesktopWindow);
  if ( v4 == nullptr )
    return 0;
  this->m_pColorDlg = pColorDlg;
  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd: v4->m_hWnd, lpRect: &Rect);
  AfxGetModuleState();
  ModuleState = AfxGetModuleState();
  CursorW = LoadCursorW(hInstance: ModuleState->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F11);
  v8 = AfxRegisterWndClass(nClassStyle: 0x800u, hCursor: CursorW, hbrBackground: (HBRUSH__ *)0x10, hIcon: nullptr);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v10,
    pszSrc: v8);
  v12 = 0;
  v9 = CWnd::CreateEx(
         this,
         dwExStyle: 0xA0u,
         lpszClassName: v10.m_pszData,
         lpszWindowName: &var,
         dwStyle: 0x90000000,
         rect: &Rect,
         pParentWnd: nullptr,
         nID: 0,
         lpParam: nullptr);
  ATL::CStringData::Release(this: (ATL::CStringData *)v10.m_pszData - 1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1042AED8
// Name: public: CMFCColorPopupMenu::CMFCColorPopupMenu(class CArray<unsigned long,unsigned long> const __near &,unsigned long,char const __near *,char const __near *,char const __near *,class CList<unsigned long,unsigned long> __near &,int,int,int,unsigned long,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorPopupMenu *__thiscall CMFCColorPopupMenu::CMFCColorPopupMenu(
        CMFCColorPopupMenu *this,
        const CArray<unsigned long,unsigned long> *colors,
        unsigned int color,
        const char *lpszAutoColor,
        const char *lpszOtherColor,
        const char *lpszDocColors,
        CList<unsigned long,unsigned long> *lstDocColors,
        int nColumns,
        int nHorzDockRows,
        int nVertDockColumns,
        unsigned int colorAutomatic,
        unsigned int uiCommandID,
        int bStdColorDlg)
{
  CMFCPopupMenu::CMFCPopupMenu(this);
  this->__vftable = (CMFCColorPopupMenu_vtbl *)&CMFCColorPopupMenu::`vftable';
  CMFCColorBar::CMFCColorBar(
    this: &this->m_wndColorBar,
    colors,
    color,
    lpszAutoColor,
    lpszOtherColor,
    lpszDocColors,
    lstDocColors,
    nColumns,
    nRowsDockHorz: nHorzDockRows,
    nColDockVert: nVertDockColumns,
    colorAutomatic,
    nCommandID: uiCommandID,
    pParentBtn: nullptr);
  this->m_bEnabledInCustomizeMode = 0;
  this->m_wndColorBar.m_bStdColorDlg = bStdColorDlg;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042AF40
// Name: public: virtual struct CRuntimeClass __near * CMFCColorMenuButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCColorMenuButton::GetRuntimeClass(CMFCColorMenuButton *this)
{
  return &CMFCColorMenuButton::classCMFCColorMenuButton;
}

//------------------------------------------------------------------------------
// Address: 0x1042AF46
// Name: protected: void CMFCColorMenuButton::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorMenuButton::Initialize(CMFCColorMenuButton *this)
{
  this->m_Color = -1;
  this->m_colorAutomatic = 0;
  this->m_nColumns = -1;
  this->m_nVertDockColumns = -1;
  this->m_nHorzDockRows = -1;
  this->m_bIsAutomaticButton = 0;
  this->m_bIsOtherButton = 0;
  this->m_bIsDocumentColors = 0;
  this->m_bStdColorDlg = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042AF82
// Name: protected: virtual int CMFCColorMenuButton::OnDrawOnCustomizeList(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorMenuButton::OnDrawOnCustomizeList(
        CMFCColorMenuButton *this,
        CDC *pDC,
        const CRect *rect,
        int bSelected)
{
  unsigned int m_nID; // eax
  int result; // eax
  unsigned int nID; // [esp+10h] [ebp-1Ch]
  CRect rectColor; // [esp+18h] [ebp-14h] BYREF

  m_nID = this->m_nID;
  this->m_nID = 0;
  rectColor = *rect;
  nID = m_nID;
  InflateRect(lprc: &rectColor, dx: -1, dy: 0);
  result = CMFCToolBarMenuButton::OnDrawOnCustomizeList(this, pDC, rect, bSelected);
  this->m_nID = nID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AFEB
// Name: public: virtual void CMFCColorMenuButton::OnChangeParentWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorMenuButton::OnChangeParentWnd(CMFCColorMenuButton *this, CWnd *pWndParent)
{
  CMFCToolBarButton::OnChangeParentWnd(this, pWndParent);
  if ( pWndParent != nullptr )
  {
    if ( CObject::IsKindOf(this: pWndParent, pClass: &CMFCMenuBar::classCMFCMenuBar) != 0 )
      this->m_bText = 1;
    if ( CObject::IsKindOf(this: pWndParent, pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar) != 0 )
    {
      this->m_bMenuMode = 1;
      this->m_bText = 1;
    }
    else
    {
      this->m_bMenuMode = 0;
    }
  }
  this->m_bDrawDownArrow = 1;
  this->m_pWndParent = pWndParent;
}

//------------------------------------------------------------------------------
// Address: 0x1042B071
// Name: public: virtual int CMFCColorMenuButton::OpenColorDialog(unsigned long,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorMenuButton::OpenColorDialog(
        CMFCColorMenuButton *this,
        unsigned int colorDefault,
        unsigned int *colorRes)
{
  int v3; // ebx
  CColorDialog v5; // [esp+10h] [ebp-A24h] BYREF
  CMFCColorDialog v6; // [esp+C8h] [ebp-96Ch] BYREF
  int v7; // [esp+A30h] [ebp-4h]

  v3 = 0;
  if ( this->m_bStdColorDlg != 0 )
  {
    CColorDialog::CColorDialog(this: &v5, clrInit: colorDefault, dwFlags: 0x102u, pParentWnd: nullptr);
    v7 = 0;
    if ( CColorDialog::DoModal(this: &v5) == 1 )
    {
      *colorRes = v5.m_cc.rgbResult;
      v3 = 1;
    }
    v7 = -1;
    v5.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
    CDialog::~CDialog(this: &v5);
  }
  else
  {
    CMFCColorDialog::CMFCColorDialog(this: &v6, clrInit: colorDefault, __formal: 0, pParentWnd: nullptr, hPal: nullptr);
    v7 = 1;
    if ( CDialog::DoModal(this: &v6) == 1 )
    {
      *colorRes = v6.m_NewColor;
      v3 = 1;
    }
    v7 = -1;
    CMFCColorDialog::~CMFCColorDialog(this: &v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1042B122
// Name: protected: virtual class CMFCPopupMenu __near * CMFCColorMenuButton::CreatePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__thiscall CMFCColorMenuButton::CreatePopupMenu(CMFCColorMenuButton *this)
{
  char *v2; // edi
  CWnd *m_pWndParent; // ecx
  CFrameWnd *TopLevelFrame; // eax
  char *m_pszData; // ecx
  char *v6; // eax
  CList<unsigned long,unsigned long> lstDocColors; // [esp+10h] [ebp-2Ch] BYREF
  CMFCColorPopupMenu *v9; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+38h] [ebp-4h]

  v2 = nullptr;
  lstDocColors.__vftable = (CList<unsigned long,unsigned long>_vtbl *)&CList<unsigned long,unsigned long>::`vftable';
  memset(&lstDocColors.m_pNodeHead, 0, 20);
  lstDocColors.m_nBlockSize = 10;
  v10 = 0;
  if ( this->m_bIsDocumentColors != 0 )
  {
    m_pWndParent = this->m_pWndParent;
    if ( m_pWndParent != nullptr )
    {
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
      if ( g_pTopLevelFrame == nullptr )
        TopLevelFrame = CWnd::GetTopLevelFrame(this: m_pWndParent);
      SendMessageA(
        hWnd: TopLevelFrame->m_hWnd,
        Msg: AFX_WM_GETDOCUMENTCOLORS,
        wParam: this->m_nID,
        lParam: (LPARAM)&lstDocColors);
    }
  }
  v9 = (CMFCColorPopupMenu *)operator new(nSize: 0x1EB8u);
  LOBYTE(v10) = 1;
  if ( v9 != nullptr )
  {
    if ( this->m_bIsDocumentColors != 0 )
      m_pszData = this->m_strDocumentColorsLabel.m_pszData;
    else
      m_pszData = nullptr;
    if ( this->m_bIsOtherButton != 0 )
      v6 = this->m_strOtherButtonLabel.m_pszData;
    else
      v6 = nullptr;
    if ( this->m_bIsAutomaticButton != 0 )
      v2 = this->m_strAutomaticButtonLabel.m_pszData;
    v2 = (char *)CMFCColorPopupMenu::CMFCColorPopupMenu(
                   this: v9,
                   colors: &this->m_Colors,
                   color: this->m_Color,
                   lpszAutoColor: v2,
                   lpszOtherColor: v6,
                   lpszDocColors: m_pszData,
                   &lstDocColors,
                   nColumns: this->m_nColumns,
                   nHorzDockRows: this->m_nHorzDockRows,
                   nVertDockColumns: this->m_nVertDockColumns,
                   colorAutomatic: this->m_colorAutomatic,
                   uiCommandID: this->m_nID,
                   bStdColorDlg: this->m_bStdColorDlg);
  }
  v10 = -1;
  lstDocColors.__vftable = (CList<unsigned long,unsigned long>_vtbl *)&CList<unsigned long,unsigned long>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&lstDocColors);
  return (CMFCPopupMenu *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10430703
// Name: protected: void CMFCTasksPane::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnMouseMove(CMFCTasksPane *this, unsigned int nFlags, CPoint point)
{
  __int64 v4; // rdi
  CMFCTasksPaneTask *m_pHotTask; // eax
  CMFCTasksPaneTaskGroup *v6; // eax
  CMFCTasksPaneTask *v7; // eax
  CWnd *v8; // eax
  CMFCTasksPaneTaskGroup *v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  CMFCTasksPaneTask *v12; // eax
  CWnd *Owner; // eax
  HWND Capture; // eax
  HWND v15; // eax
  CMFCTasksPaneTaskGroup *m_pHotGroupCaption; // eax
  unsigned int v17; // esi
  HWND__ *v18; // [esp-10h] [ebp-3Ch]
  HWND__ *v19; // [esp-10h] [ebp-3Ch]
  HWND__ *m_hWnd; // [esp-10h] [ebp-3Ch]
  HWND__ *v21; // [esp-10h] [ebp-3Ch]
  HWND__ *v22; // [esp-10h] [ebp-3Ch]
  int bUpdate; // [esp+14h] [ebp-18h]
  CRect rectUpdate; // [esp+18h] [ebp-14h] BYREF

  CDockablePane::OnMouseMove(this, nFlags, point);
  bUpdate = 0;
  if ( this->m_bUseScrollButtons != 0 )
  {
    if ( PtInRect(lprc: &this->m_rectScrollUp, pt: point.tagPOINT) && this->m_nVertScrollOffset > 0 )
    {
      this->m_iScrollMode = -1;
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollUp, bErase: true);
    }
    else if ( PtInRect(lprc: &this->m_rectScrollDn, pt: point.tagPOINT) && CMFCTasksPane::IsScrollDnAvailable(this) != 0 )
    {
      this->m_iScrollMode = 1;
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollDn, bErase: true);
    }
    else
    {
      this->m_iScrollMode = 0;
    }
    if ( this->m_iScrollMode != 0 )
    {
      SetTimer(hWnd: this->m_hWnd, nIDEvent: 5u, uElapse: 0x50u, lpTimerFunc: nullptr);
      return;
    }
  }
  LODWORD(v4) = ((int (__thiscall *)(CMFCTasksPane *, int, int))this->GroupCaptionHitTest)(
                  a1: this,
                  a2: point.x,
                  a3: point.y);
  HIDWORD(v4) = CMFCTasksPane::TaskHitTest(this, pt: point);
  m_pHotTask = this->m_pHotTask;
  if ( __PAIR64__((unsigned int)m_pHotTask, this->m_pHotGroupCaption) == v4 )
    return;
  if ( HIDWORD(v4) != 0 )
  {
    if ( (_DWORD)v4 == 0 )
    {
      if ( *(_DWORD *)(HIDWORD(v4) + 56) == 0 )
      {
        Owner = CWnd::GetOwner(this);
        SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
        return;
      }
      if ( m_pHotTask != nullptr )
      {
        rectUpdate.left = m_pHotTask->m_rect.left;
        rectUpdate.top = m_pHotTask->m_rect.top;
        rectUpdate.right = m_pHotTask->m_rect.right;
        m_hWnd = this->m_hWnd;
        rectUpdate.bottom = m_pHotTask->m_rect.bottom;
        this->m_pHotTask = nullptr;
        RedrawWindow(hWnd: m_hWnd, lprcUpdate: &rectUpdate, hrgnUpdate: nullptr, flags: 5u);
      }
      else
      {
        Capture = GetCapture();
        if ( CWnd::FromHandle(hWnd: Capture) != nullptr )
          return;
        v15 = SetCapture(hWnd: this->m_hWnd);
        CWnd::FromHandle(hWnd: v15);
      }
      m_pHotGroupCaption = this->m_pHotGroupCaption;
      if ( m_pHotGroupCaption != nullptr )
      {
        rectUpdate.left = m_pHotGroupCaption->m_rect.left;
        rectUpdate.top = m_pHotGroupCaption->m_rect.top;
        rectUpdate.right = m_pHotGroupCaption->m_rect.right;
        v21 = this->m_hWnd;
        rectUpdate.bottom = m_pHotGroupCaption->m_rect.bottom;
        this->m_pHotGroupCaption = nullptr;
        RedrawWindow(hWnd: v21, lprcUpdate: &rectUpdate, hrgnUpdate: nullptr, flags: 5u);
      }
      v22 = this->m_hWnd;
      this->m_pHotTask = (CMFCTasksPaneTask *)HIDWORD(v4);
      RedrawWindow(hWnd: v22, lprcUpdate: (const RECT *)(HIDWORD(v4) + 12), hrgnUpdate: nullptr, flags: 5u);
      v17 = *(_DWORD *)(HIDWORD(v4) + 36);
      if ( v17 != 0 )
        this->ShowCommandMessageString(this, a2: v17);
      goto LABEL_42;
    }
    goto LABEL_25;
  }
  if ( (_DWORD)v4 != 0 )
  {
LABEL_25:
    v9 = this->m_pHotGroupCaption;
    if ( v9 != nullptr )
    {
      rectUpdate.left = v9->m_rect.left;
      rectUpdate.top = v9->m_rect.top;
      rectUpdate.right = v9->m_rect.right;
      v18 = this->m_hWnd;
      rectUpdate.bottom = v9->m_rect.bottom;
      this->m_pHotGroupCaption = nullptr;
      RedrawWindow(hWnd: v18, lprcUpdate: &rectUpdate, hrgnUpdate: nullptr, flags: 5u);
    }
    else
    {
      v10 = GetCapture();
      if ( CWnd::FromHandle(hWnd: v10) != nullptr )
        return;
      v11 = SetCapture(hWnd: this->m_hWnd);
      CWnd::FromHandle(hWnd: v11);
    }
    v12 = this->m_pHotTask;
    if ( v12 != nullptr )
    {
      rectUpdate.left = v12->m_rect.left;
      rectUpdate.top = v12->m_rect.top;
      rectUpdate.right = v12->m_rect.right;
      v19 = this->m_hWnd;
      rectUpdate.bottom = v12->m_rect.bottom;
      this->m_pHotTask = nullptr;
      RedrawWindow(hWnd: v19, lprcUpdate: &rectUpdate, hrgnUpdate: nullptr, flags: 5u);
    }
    this->m_pHotGroupCaption = (CMFCTasksPaneTaskGroup *)v4;
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: (const RECT *)(v4 + 52), hrgnUpdate: nullptr, flags: 5u);
    goto LABEL_42;
  }
  v6 = this->m_pHotGroupCaption;
  if ( v6 != nullptr )
  {
    rectUpdate = v6->m_rect;
    this->m_pHotGroupCaption = nullptr;
    if ( this->m_pClickedGroupCaption == nullptr )
      ReleaseCapture();
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &rectUpdate, hrgnUpdate: nullptr, flags: 5u);
    bUpdate = 1;
  }
  v7 = this->m_pHotTask;
  if ( v7 != nullptr )
  {
    rectUpdate = v7->m_rect;
    this->m_pHotTask = nullptr;
    if ( this->m_pClickedTask == nullptr )
      ReleaseCapture();
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &rectUpdate, hrgnUpdate: nullptr, flags: 0x105u);
    bUpdate = 1;
  }
  v8 = CWnd::GetOwner(this);
  SendMessageA(hWnd: v8->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
  if ( bUpdate != 0 )
LABEL_42:
    UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10430A4C
// Name: protected: void CMFCTasksPane::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnLButtonUp(CMFCTasksPane *this, WPARAM nFlags, CPoint point)
{
  CMFCTasksPaneTaskGroup *m_pHotGroupCaption; // edi
  BOOL v5; // eax
  int v6; // ecx
  int *p_left; // esi
  int *v8; // esi
  CMFCTasksPaneTask *m_pHotTask; // esi
  int *v10; // esi
  int *v11; // esi
  int v12; // edi
  int v13; // ecx
  CObject *v14; // edx
  CObject_vtbl *v15; // eax
  CObject_vtbl *v16; // esi
  CObList::CNode *m_pNodeHead; // eax
  int v18; // edi
  CObList::CNode *v19; // esi
  HWND__ *m_hWnd; // [esp-18h] [ebp-58h]
  HWND__ *v21; // [esp-18h] [ebp-58h]
  int nGroupNumber; // [esp+4h] [ebp-3Ch]
  int nGroupNumbera; // [esp+4h] [ebp-3Ch]
  int nTaskNumber; // [esp+8h] [ebp-38h]
  int nTaskNumbera; // [esp+8h] [ebp-38h]
  CRect rectGroupCaption; // [esp+Ch] [ebp-34h] BYREF
  CRect rectTask; // [esp+1Ch] [ebp-24h] BYREF
  int v28; // [esp+2Ch] [ebp-14h] BYREF
  int v29; // [esp+30h] [ebp-10h]
  int v30; // [esp+34h] [ebp-Ch]
  int v31; // [esp+38h] [ebp-8h]

  CDockablePane::OnLButtonUp(this, nFlags, point);
  if ( *(_QWORD *)&this->m_pHotTask != 0
    || this->m_pHotGroupCaption != nullptr
    || this->m_pClickedGroupCaption != nullptr )
  {
    ReleaseCapture();
    m_pHotGroupCaption = this->m_pHotGroupCaption;
    v5 = m_pHotGroupCaption != nullptr
      && m_pHotGroupCaption == (CMFCTasksPaneTaskGroup *)((int (__thiscall *)(CMFCTasksPane *, int, int))this->GroupCaptionHitTest)(
                                                           a1: this,
                                                           a2: point.x,
                                                           a3: point.y)
      && this->m_pClickedGroupCaption == m_pHotGroupCaption;
    this->m_pClickedGroupCaption = nullptr;
    if ( v5 )
    {
      this->m_pHotGroupCaption = nullptr;
      m_pHotGroupCaption->m_bIsCollapsed = m_pHotGroupCaption->m_bIsCollapsed == 0;
      if ( this->m_bAnimationEnabled != 0 )
      {
        this->m_pAnimatedGroup = m_pHotGroupCaption;
        v6 = m_pHotGroupCaption->m_rectGroup.bottom - m_pHotGroupCaption->m_rectGroup.top;
        m_hWnd = this->m_hWnd;
        this->m_sizeAnim.cx = m_pHotGroupCaption->m_rectGroup.right - m_pHotGroupCaption->m_rectGroup.left;
        this->m_sizeAnim.cy = v6;
        SetTimer(hWnd: m_hWnd, nIDEvent: 4u, uElapse: 0x1Eu, lpTimerFunc: nullptr);
        CMFCTasksPane::m_nLastAnimTime = clock();
      }
      CMFCTasksPane::AdjustScroll(this);
      this->ReposTasks(this, a2: 0);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x200u, wParam: nFlags, lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
    }
    else
    {
      if ( m_pHotGroupCaption != nullptr )
      {
        p_left = &m_pHotGroupCaption->m_rect.left;
      }
      else
      {
        v28 = 0;
        v29 = 0;
        v30 = 0;
        v31 = 0;
        p_left = &v28;
      }
      rectGroupCaption.left = *p_left;
      v8 = p_left + 1;
      rectGroupCaption.top = *v8++;
      rectGroupCaption.right = *v8;
      rectGroupCaption.bottom = v8[1];
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &rectGroupCaption, hrgnUpdate: nullptr, flags: 0x105u);
      m_pHotTask = this->m_pHotTask;
      nGroupNumber = (int)m_pHotTask;
      if ( m_pHotTask == nullptr
        || m_pHotTask != CMFCTasksPane::TaskHitTest(this, pt: point)
        || (nTaskNumber = 1, this->m_pClickedTask != m_pHotTask) )
      {
        nTaskNumber = 0;
      }
      if ( m_pHotTask != nullptr )
      {
        v10 = &m_pHotTask->m_rect.left;
      }
      else
      {
        v28 = 0;
        v29 = 0;
        v30 = 0;
        v31 = 0;
        v10 = &v28;
      }
      rectTask.left = *v10;
      v11 = v10 + 1;
      rectTask.top = *v11++;
      rectTask.right = *v11;
      rectTask.bottom = v11[1];
      v12 = 0;
      v21 = this->m_hWnd;
      this->m_pHotTask = nullptr;
      this->m_pClickedTask = nullptr;
      RedrawWindow(hWnd: v21, lprcUpdate: &rectTask, hrgnUpdate: nullptr, flags: 0x105u);
      if ( nTaskNumber != 0 )
      {
        v13 = nGroupNumber;
        v14 = *(CObject **)(nGroupNumber + 4);
        v15 = v14[4].__vftable;
        nTaskNumbera = -1;
        if ( v15 != nullptr )
        {
          while ( 1 )
          {
            v16 = v15;
            v15 = (CObject_vtbl *)v15->GetRuntimeClass;
            if ( v16->Serialize == (void (__thiscall *)(CObject *, CArchive *))nGroupNumber )
              break;
            ++v12;
            if ( v15 == nullptr )
              goto LABEL_29;
          }
          nTaskNumbera = v12;
        }
LABEL_29:
        nGroupNumbera = -1;
        m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
        v18 = 0;
        while ( m_pNodeHead != nullptr )
        {
          v19 = m_pNodeHead;
          m_pNodeHead = m_pNodeHead->pNext;
          if ( v14 == v19->data )
          {
            nGroupNumbera = v18;
            break;
          }
          ++v18;
        }
        this->OnClickTask(
          this,
          a2: nGroupNumbera,
          a3: nTaskNumbera,
          a4: *(_DWORD *)(v13 + 36),
          a5: *(_DWORD *)(v13 + 40));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430C99
// Name: public: virtual void CMFCTasksPane::OnClickTask(int,int,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnClickTask(
        CMFCTasksPane *this,
        int __formal,
        int a3,
        WPARAM uiCommandID,
        unsigned int a5)
{
  CWnd *Owner; // eax

  if ( uiCommandID != 0 )
  {
    Owner = CWnd::GetOwner(this);
    PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: uiCommandID, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430CC0
// Name: protected: void CMFCTasksPane::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnLButtonDown(CMFCTasksPane *this, WPARAM nFlags, CPoint point)
{
  CMFCTasksPaneTask *v4; // eax
  int rect_4; // [esp+Ch] [ebp-28h]
  CPoint pt; // [esp+18h] [ebp-1Ch] BYREF
  CRect rectClient; // [esp+20h] [ebp-14h] BYREF

  this->m_pClickedGroupCaption = (CMFCTasksPaneTaskGroup *)((int (__thiscall *)(CMFCTasksPane *, int, int))this->GroupCaptionHitTest)(
                                                             a1: this,
                                                             a2: point.x,
                                                             a3: point.y);
  v4 = CMFCTasksPane::TaskHitTest(this, pt: point);
  this->m_pClickedTask = v4;
  if ( v4 != nullptr )
  {
    rect_4 = v4->m_rect.top;
    pt.x = v4->m_rect.left;
    pt.y = rect_4;
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt);
    NotifyWinEvent(event: 0x8005u, hwnd: this->m_hWnd, idObject: -4, idChild: LOWORD(pt.x) | (LOWORD(pt.y) << 16));
  }
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
  if ( !PtInRect(lprc: &rectClient, pt: point.tagPOINT) || PtInRect(lprc: &this->m_rectToolbar, pt: point.tagPOINT) )
  {
    CDockablePane::OnLButtonDown(this, nFlags, point);
  }
  else if ( this->IsToolBox(this) != 0 )
  {
    CWnd::SetFocus(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430DC0
// Name: protected: void CMFCTasksPane::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnVScroll(
        CMFCTasksPane *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *__formal)
{
  int m_nVertScrollOffset; // eax
  int v6; // ebx
  unsigned int m_nVertScrollTotal; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax

  m_nVertScrollOffset = this->m_nVertScrollOffset;
  v6 = m_nVertScrollOffset;
  switch ( nSBCode )
  {
    case 0u:
      m_nVertScrollTotal = m_nVertScrollOffset - 1;
      goto LABEL_9;
    case 1u:
      m_nVertScrollTotal = m_nVertScrollOffset + 1;
      goto LABEL_9;
    case 2u:
      m_nVertScrollTotal = m_nVertScrollOffset - this->m_nVertScrollPage;
      goto LABEL_9;
    case 3u:
      this->m_nVertScrollOffset = m_nVertScrollOffset + this->m_nVertScrollPage;
      goto LABEL_10;
    case 4u:
    case 5u:
      m_nVertScrollTotal = nPos;
      goto LABEL_9;
    case 6u:
      this->m_nVertScrollOffset = 0;
      goto LABEL_10;
    case 7u:
      m_nVertScrollTotal = this->m_nVertScrollTotal;
LABEL_9:
      this->m_nVertScrollOffset = m_nVertScrollTotal;
LABEL_10:
      v8 = this->m_nVertScrollOffset;
      if ( v8 >= 0 )
        v9 = this->m_nVertScrollOffset;
      else
        v9 = 0;
      v10 = this->m_nVertScrollTotal - this->m_nVertScrollPage + 1;
      if ( v9 < v10 )
      {
        if ( v8 >= 0 )
          v10 = this->m_nVertScrollOffset;
        else
          v10 = 0;
      }
      this->m_nVertScrollOffset = v10;
      if ( v10 != v6 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v10, bRedraw: 1);
        CMFCTasksPane::AdjustScroll(this);
        this->ReposTasks(this, a2: 0);
        RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430EA8
// Name: protected: void CMFCTasksPane::SaveHistory(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::SaveHistory(CMFCTasksPane *this, CMFCRibbonKeyTip *nPageIdx)
{
  int m_iActivePage; // eax
  int m_nSize; // ecx
  int v5; // eax

  m_iActivePage = this->m_iActivePage;
  if ( m_iActivePage < 0 || m_iActivePage >= this->m_arrHistoryStack.m_nSize )
    AfxThrowInvalidArgException();
  if ( nPageIdx != (CMFCRibbonKeyTip *)this->m_arrHistoryStack.m_pData[m_iActivePage] )
  {
    m_nSize = this->m_arrHistoryStack.m_nSize;
    if ( m_iActivePage < m_nSize - 1 )
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrHistoryStack,
        nIndex: m_iActivePage + 1,
        nCount: m_nSize - m_iActivePage - 1);
    if ( this->m_arrHistoryStack.m_nSize == this->m_nMaxHistory )
    {
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arrHistoryStack,
        nIndex: 0,
        nCount: 1);
      v5 = this->m_iActivePage;
      if ( v5 > 0 )
        this->m_iActivePage = v5 - 1;
    }
    CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arrHistoryStack,
      nIndex: this->m_arrHistoryStack.m_nSize,
      newElement: nPageIdx);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430F3D
// Name: protected: int CMFCTasksPane::OnMouseWheel(unsigned int,short,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::OnMouseWheel(CMFCTasksPane *this, unsigned int nFlags, __int16 zDelta, CPoint pt)
{
  int v6; // ebx
  int v7; // eax
  CScrollBar *p_m_wndScrollVert; // [esp-8h] [ebp-10h]

  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
    return 1;
  if ( this->m_nVertScrollTotal > 0 )
  {
    v6 = abs(lnumber: zDelta);
    while ( v6 != 0 )
    {
      p_m_wndScrollVert = &this->m_wndScrollVert;
      if ( zDelta <= 0 )
        CMFCTasksPane::OnVScroll(this, nSBCode: 1u, nPos: 0, __formal: p_m_wndScrollVert);
      else
        CMFCTasksPane::OnVScroll(this, nSBCode: 0, nPos: 0, __formal: p_m_wndScrollVert);
      v7 = 120;
      if ( v6 <= 120 )
        v7 = v6;
      v6 -= v7;
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x180u);
    }
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10430FB4
// Name: public: virtual void CMFCTasksPane::ShowCommandMessageString(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::ShowCommandMessageString(CMFCTasksPane *this, WPARAM uiCmdId)
{
  WPARAM v2; // esi
  CWnd *Owner; // eax

  v2 = uiCmdId;
  if ( uiCmdId == -1 )
    v2 = 57345;
  Owner = CWnd::GetOwner(this);
  SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: v2, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10430FE2
// Name: public: struct HMENU__ __near * CMFCTasksPane::CreateMenu(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU __thiscall CMFCTasksPane::CreateMenu(CMFCTasksPane *this)
{
  HMENU PopupMenu; // eax
  CObList::CNode *m_pNodeHead; // esi
  HMENU v4; // esi
  UINT ActivePage; // eax
  const char *v7; // [esp-4h] [ebp-2Ch]
  CMenu menu; // [esp+10h] [ebp-18h] BYREF
  CMFCTasksPane *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  menu.m_hMenu = nullptr;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  v10 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  m_pNodeHead = this->m_lstTasksPanes.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    v7 = (const char *)m_pNodeHead->data[1].__vftable;
    m_pNodeHead = m_pNodeHead->pNext;
    AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x4280u, lpNewItem: v7);
  }
  v4 = CMenu::Detach(this: &menu);
  if ( v4 != nullptr )
  {
    ActivePage = CMFCTasksPane::GetActivePage(this: v9);
    CheckMenuItem(hMenu: v4, uIDCheckItem: ActivePage, uCheck: 0x408u);
  }
  v10 = -1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1043107C
// Name: public: void CMFCTasksPane::GetPreviousPages(class CStringList __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::GetPreviousPages(CMFCTasksPane *this, CStringList *lstPrevPages)
{
  int m_iActivePage; // edi
  int i; // ebx
  int v5; // eax
  __POSITION *Index; // eax

  CStringList::RemoveAll(this: lstPrevPages);
  m_iActivePage = this->m_iActivePage;
  for ( i = 0; i < m_iActivePage; ++i )
  {
    v5 = this->m_iActivePage - i - 1;
    if ( v5 < 0
      || v5 >= this->m_arrHistoryStack.m_nSize
      || (Index = CStringList::FindIndex(
                    this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
                    nIndex: this->m_arrHistoryStack.m_pData[v5])) == nullptr )
    {
      AfxThrowInvalidArgException();
    }
    CStringList::AddTail(
      this: lstPrevPages,
      newElement: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)(*(_DWORD *)&Index[8] + 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x104310E6
// Name: public: void CMFCTasksPane::GetNextPages(class CStringList __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::GetNextPages(CMFCTasksPane *this, CStringList *lstNextPages)
{
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  __POSITION *Index; // eax

  CStringList::RemoveAll(this: lstNextPages);
  v3 = 0;
  v4 = this->m_arrHistoryStack.m_nSize - this->m_iActivePage - 1;
  if ( v4 > 0 )
  {
    do
    {
      v5 = this->m_iActivePage + v3 + 1;
      if ( v5 < 0
        || v5 >= this->m_arrHistoryStack.m_nSize
        || (Index = CStringList::FindIndex(
                      this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
                      nIndex: this->m_arrHistoryStack.m_pData[v5])) == nullptr )
      {
        AfxThrowInvalidArgException();
      }
      CStringList::AddTail(
        this: lstNextPages,
        newElement: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)(*(_DWORD *)&Index[8] + 4));
      ++v3;
    }
    while ( v3 < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043115A
// Name: public: virtual int CMFCTasksPane::OnSetAccData(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::OnSetAccData(CMFCTasksPane *this, CMFCTasksPaneTaskGroup *lVal)
{
  CMFCTasksPaneTaskGroup *v3; // esi
  CMFCTasksPaneTask *v4; // eax
  int ActivePage; // eax
  __POSITION *Index; // eax
  int v7; // ecx
  CMFCTasksPaneTask *v8; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-20h]
  CPoint pt; // [esp+Ch] [ebp-Ch] BYREF
  CMFCTasksPaneTask *pTask; // [esp+14h] [ebp-4h]

  pt.y = (unsigned int)lVal >> 16;
  m_hWnd = this->m_hWnd;
  pt.x = (unsigned __int16)lVal;
  ScreenToClient(hWnd: m_hWnd, lpPoint: &pt);
  v3 = (CMFCTasksPaneTaskGroup *)((int (__thiscall *)(CMFCTasksPane *, int, int))this->GroupCaptionHitTest)(
                                   a1: this,
                                   a2: pt.x,
                                   a3: pt.y);
  v4 = CMFCTasksPane::TaskHitTest(this, pt);
  pTask = v4;
  if ( v3 == nullptr && v4 == nullptr )
  {
    ActivePage = CMFCTasksPane::GetActivePage(this);
    Index = CStringList::FindIndex(
              this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
              nIndex: ActivePage);
    if ( Index == nullptr )
      AfxThrowInvalidArgException();
    v7 = *(_DWORD *)&Index[8];
    if ( v7 != 0 )
    {
      (*(void (__thiscall **)(int, CMFCTasksPane *, CAccessibilityData *))(*(_DWORD *)v7 + 12))(
        a1: v7,
        a2: this,
        a3: &this->m_AccData);
      this->m_AccData.m_rectAccLocation.left = this->m_rectTasks.left;
      this->m_AccData.m_rectAccLocation.top = this->m_rectTasks.top;
      this->m_AccData.m_rectAccLocation.right = this->m_rectTasks.right;
      this->m_AccData.m_rectAccLocation.bottom = this->m_rectTasks.bottom;
      CWnd::ClientToScreen(this, lpRect: &this->m_AccData.m_rectAccLocation);
      v3 = nullptr;
    }
  }
  CAccessibilityData::Clear(this: &this->m_AccData);
  if ( v3 != nullptr )
  {
    v3->SetACCData(this: v3, a2: this, a3: &this->m_AccData);
    if ( v3 == this->m_pClickedGroupCaption )
      this->m_AccData.m_bAccState |= 0x200004u;
  }
  v8 = pTask;
  if ( pTask != nullptr )
  {
    pTask->SetACCData(this: pTask, a2: this, a3: &this->m_AccData);
    if ( v8 == this->m_pClickedTask )
      this->m_AccData.m_bAccState |= 4u;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10431252
// Name: public: void CTasksPaneHistoryButton::UpdateMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CTasksPaneHistoryButton::UpdateMenu(CTasksPaneHistoryButton *this)
{
  CMFCTasksPane *m_pParentBar; // ecx
  unsigned int m_nID; // eax
  HMENU PopupMenu; // eax
  CStringList::CNode *m_pNodeHead; // esi
  const char *m_pszData; // eax
  CMenu menu; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  m_pParentBar = this->m_pParentBar;
  if ( m_pParentBar != nullptr )
  {
    m_nID = this->m_nID;
    if ( m_nID == 17020 )
    {
      CMFCTasksPane::GetPreviousPages(this: m_pParentBar, lstPrevPages: &this->m_lstPages);
    }
    else if ( m_nID == 17021 )
    {
      CMFCTasksPane::GetNextPages(this: m_pParentBar, lstNextPages: &this->m_lstPages);
    }
    menu.m_hMenu = nullptr;
    menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    v8 = 0;
    PopupMenu = CreatePopupMenu();
    CMenu::Attach(this: &menu, hMenu: PopupMenu);
    m_pNodeHead = this->m_lstPages.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      m_pszData = m_pNodeHead->data.m_pszData;
      m_pNodeHead = m_pNodeHead->pNext;
      AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: this->m_nID, lpNewItem: m_pszData);
    }
    this->CreateFromMenu(this, a2: menu.m_hMenu);
    v8 = -1;
    menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    CMenu::DestroyMenu(this: &menu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10431307
// Name: public: virtual struct HMENU__ __near * CTasksPaneMenuButton::CreateMenu(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU __thiscall CTasksPaneMenuButton::CreateMenu(CTasksPaneMenuButton *this)
{
  CMFCTasksPane *m_pParentBar; // ecx

  m_pParentBar = this->m_pParentBar;
  if ( m_pParentBar != nullptr )
    return CMFCTasksPane::CreateMenu(this: m_pParentBar);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10431319
// Name: public: void CMFCTasksPaneToolBar::UpdateButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneToolBar::UpdateButtons(CMFCTasksPaneToolBar *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CTasksPaneHistoryButton *v2; // eax
  CObject *data; // [esp-4h] [ebp-8h]

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v2 = (CTasksPaneHistoryButton *)AfxDynamicDownCast(
                                      pClass: &CTasksPaneHistoryButton::classCTasksPaneHistoryButton,
                                      pObject: data);
    if ( v2 != nullptr )
      CTasksPaneHistoryButton::UpdateMenu(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10431352
// Name: protected: virtual int CMFCTasksPane::ReposTasks(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall CMFCTasksPane::ReposTasks(CMFCTasksPane *this, int bCalcHeightOnly)
{
  int top; // eax
  int left; // eax
  int m_nVertMargin; // esi
  int m_nHorzMargin; // eax
  int cy; // eax
  int v8; // ecx
  int m_iActivePage; // eax
  __POSITION *Index; // eax
  CMFCTasksPanePropertyPage *v11; // ecx
  CObList::CNode *m_pNodeHead; // eax
  CMFCTasksPaneTaskGroup *data; // esi
  int m_nGroupCaptionVertOffset; // eax
  int v15; // edi
  int m_nGroupCaptionHeight; // eax
  int v17; // ecx
  int v18; // eax
  CRect *p_m_rect; // edi
  CMFCTasksPaneTaskGroup *v20; // eax
  CRect *p_m_rectGroup; // edi
  CObList::CNode *v22; // esi
  CObject *v23; // eax
  CObList::CNode *v24; // esi
  int pNext; // eax
  CObject *v26; // esi
  int v27; // eax
  int v28; // eax
  int m_nTasksIconHorzOffset; // eax
  int m_bWrapTasks; // eax
  int v31; // ecx
  int v32; // eax
  CFont *v33; // eax
  CObject *v34; // esi
  CFont *v35; // edi
  CObject *v36; // edi
  int v37; // eax
  int v38; // eax
  CFont *v39; // edi
  int v40; // eax
  int v41; // edx
  CObject *v42; // eax
  CObject *v43; // edi
  int v44; // eax
  int m_nTasksIconVertOffset; // eax
  CObject_vtbl *v46; // eax
  int v47; // edx
  int v48; // eax
  int m_nTasksHorzOffset; // eax
  CObject *v50; // edi
  CObject *v51; // esi
  bool v52; // zf
  CMFCTasksPane_vtbl *v53; // eax
  int v54; // eax
  int v55; // ecx
  CFont *v56; // eax
  char *v57; // esi
  CFont *v58; // ecx
  char *v59; // edx
  CRect *v60; // edi
  int m_nGroupVertOffset; // eax
  CObList::CNode *m_pNodeTail; // eax
  CObject *v63; // esi
  CObject_vtbl *v64; // eax
  void (__thiscall *Serialize)(CObject *, CArchive *); // ecx
  CObject_vtbl *v66; // edi
  void (__thiscall *v67)(CObject *, CArchive *); // eax
  CObList::CNode *v68; // ecx
  CMFCTasksPaneTaskGroup *v69; // eax
  char *m_pszData; // esi
  int v71; // edi
  HWND__ *v72; // eax
  int v73; // edi
  int v74; // eax
  int v75; // esi
  char *v76; // esi
  CSize v78; // [esp+10h] [ebp-120h] BYREF
  int v79; // [esp+18h] [ebp-118h]
  CFont *v80; // [esp+1Ch] [ebp-114h]
  int right; // [esp+20h] [ebp-110h]
  char *v82; // [esp+24h] [ebp-10Ch]
  int v83; // [esp+28h] [ebp-108h]
  CFont *v84; // [esp+2Ch] [ebp-104h]
  int v85; // [esp+30h] [ebp-100h]
  CObject_vtbl *v86; // [esp+34h] [ebp-FCh]
  int v87; // [esp+38h] [ebp-F8h]
  char *v88; // [esp+3Ch] [ebp-F4h]
  int v89; // [esp+40h] [ebp-F0h]
  char *v90; // [esp+44h] [ebp-ECh]
  int v91; // [esp+48h] [ebp-E8h]
  CFont *v92; // [esp+4Ch] [ebp-E4h]
  int v93; // [esp+50h] [ebp-E0h]
  CFont *v94; // [esp+54h] [ebp-DCh]
  CSize v95; // [esp+58h] [ebp-D8h] BYREF
  CFont *v96; // [esp+60h] [ebp-D0h]
  int v97; // [esp+64h] [ebp-CCh] BYREF
  int v98; // [esp+68h] [ebp-C8h]
  CMFCTasksPanePropertyPage *v99; // [esp+6Ch] [ebp-C4h]
  CClientDC v100; // [esp+70h] [ebp-C0h] BYREF
  CObList::CNode *v101; // [esp+84h] [ebp-ACh]
  CMFCTasksPaneTaskGroup *v102; // [esp+88h] [ebp-A8h]
  int v103; // [esp+8Ch] [ebp-A4h]
  CFont *pFont; // [esp+90h] [ebp-A0h]
  int dy; // [esp+94h] [ebp-9Ch]
  CObject *v106; // [esp+98h] [ebp-98h]
  int v107; // [esp+9Ch] [ebp-94h]
  int v108; // [esp+A0h] [ebp-90h]
  CFont *v109; // [esp+A4h] [ebp-8Ch]
  tagRECT rc; // [esp+A8h] [ebp-88h] BYREF
  tagTEXTMETRICA tm; // [esp+B8h] [ebp-78h] BYREF
  _DWORD v112[4]; // [esp+F0h] [ebp-40h] BYREF
  tagRECT v113; // [esp+100h] [ebp-30h] BYREF
  tagRECT v114; // [esp+110h] [ebp-20h] BYREF
  int v115; // [esp+12Ch] [ebp-4h]

  if ( afxGlobalData.bIsRemoteSession != 0 )
    this->m_bAnimationEnabled = 0;
  if ( this == nullptr )
    return nullptr;
  if ( this->m_hWnd == nullptr )
    return nullptr;
  if ( this->m_lstTaskGroups.m_nCount == 0 )
    return nullptr;
  top = this->m_rectTasks.top;
  if ( top < 0 )
    return nullptr;
  if ( this->m_rectTasks.bottom <= top )
    return nullptr;
  left = this->m_rectTasks.left;
  if ( left < 0 || this->m_rectTasks.right <= left )
    return nullptr;
  rc = (tagRECT)this->m_rectTasks;
  m_nVertMargin = this->m_nVertMargin;
  if ( m_nVertMargin == -1 )
    m_nVertMargin = CMFCVisualManager::GetInstance()->m_nVertMargin;
  m_nHorzMargin = this->m_nHorzMargin;
  if ( m_nHorzMargin == -1 )
    m_nHorzMargin = CMFCVisualManager::GetInstance()->m_nHorzMargin;
  InflateRect(lprc: &rc, dx: -m_nHorzMargin, dy: -m_nVertMargin);
  CClientDC::CClientDC(this: &v100, pWnd: this);
  v115 = 0;
  v96 = CDC::SelectObject(this: &v100, pFont: &this->m_fontBold);
  GetTextMetricsA(hdc: v100.m_hAttribDC, lptm: &tm);
  cy = this->m_sizeIcon.cy;
  if ( tm.tmHeight > cy )
    cy = tm.tmHeight;
  v8 = cy * this->m_nVertScrollOffset;
  this->m_nRowHeight = cy;
  v109 = (CFont *)(rc.top - v8);
  m_iActivePage = this->m_iActivePage;
  this->m_nAnimGroupExtraHeight = 0;
  if ( m_iActivePage < 0
    || m_iActivePage >= this->m_arrHistoryStack.m_nSize
    || (Index = CStringList::FindIndex(
                  this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
                  nIndex: this->m_arrHistoryStack.m_pData[m_iActivePage])) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  v11 = *(CMFCTasksPanePropertyPage **)&Index[8];
  m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
  v99 = v11;
  while ( m_pNodeHead != nullptr )
  {
    data = (CMFCTasksPaneTaskGroup *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v101 = m_pNodeHead;
    v102 = data;
    if ( data->m_pPage == v11 )
    {
      CDC::SelectObject(this: &v100, pFont: &this->m_fontBold);
      if ( *((_DWORD *)data->m_strName.m_pszData - 3) != 0 )
      {
        pFont = CDC::SelectObject(this: &v100, pFont: &afxGlobalData.fontBold);
        CDC::GetTextExtent(this: &v100, result: &v78, str: &data->m_strName);
        CDC::SelectObject(this: &v100, pFont);
        m_nGroupCaptionVertOffset = this->m_nGroupCaptionVertOffset;
        if ( m_nGroupCaptionVertOffset == -1 )
          m_nGroupCaptionVertOffset = CMFCVisualManager::GetInstance()->m_nGroupCaptionVertOffset;
        v15 = m_nGroupCaptionVertOffset;
        m_nGroupCaptionHeight = this->m_nGroupCaptionHeight;
        if ( m_nGroupCaptionHeight == -1 )
          m_nGroupCaptionHeight = CMFCVisualManager::GetInstance()->m_nGroupCaptionHeight;
        v107 = m_nGroupCaptionHeight;
        if ( this->IsToolBox(this) != 0 )
        {
          if ( v15 < 5 )
            v15 = 5;
          if ( this->m_nGroupCaptionHeight == -1 )
            v107 = 18;
        }
        v17 = v15 + v78.cy;
        if ( v15 + v78.cy <= v107 )
          v17 = v107;
      }
      else
      {
        v17 = 0;
      }
      if ( data->m_hIcon != nullptr && data->m_sizeIcon.cx < rc.right - rc.left - v17 )
      {
        v18 = data->m_sizeIcon.cy;
        if ( v17 < v18 )
          v109 = (CFont *)((char *)v109 + v18 - v17);
      }
      if ( bCalcHeightOnly == 0 )
      {
        v79 = rc.left;
        v80 = v109;
        p_m_rect = &v102->m_rect;
        right = rc.right;
        v82 = (char *)v109 + v17;
        v102->m_rect.left = rc.left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        p_m_rect->left = (int)v80;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        p_m_rect->left = right;
        p_m_rect->top = (int)v82;
        data = v102;
      }
      v109 = (CFont *)((char *)v109 + v17);
      pFont = v109;
      CMFCTasksPane::SetFont(this, pDC: (HDC__ *)&v100);
      if ( this->m_bCanCollapse != 0
        && data->m_bIsCollapsed != 0
        && *((_DWORD *)data->m_strName.m_pszData - 3) != 0
        && (this->m_bAnimationEnabled == 0
         || data != this->m_pAnimatedGroup
         || this->m_sizeAnim.cy <= 0
         || bCalcHeightOnly != 0) )
      {
        if ( bCalcHeightOnly == 0 )
        {
          v87 = rc.left;
          v88 = (char *)&v109[-1].m_hObject + 3;
          v90 = (char *)&v109[-1].m_hObject + 3;
          v20 = v102;
          v89 = rc.right;
          p_m_rectGroup = &v102->m_rectGroup;
          v102->m_rectGroup.left = rc.left;
          p_m_rectGroup = (CRect *)((char *)p_m_rectGroup + 4);
          p_m_rectGroup->left = (int)v88;
          p_m_rectGroup = (CRect *)((char *)p_m_rectGroup + 4);
          p_m_rectGroup->left = v89;
          p_m_rectGroup->top = (int)v90;
          v22 = v20->m_lstTasks.m_pNodeHead;
          while ( v22 != nullptr )
          {
            v23 = v22->data;
            v22 = v22->pNext;
            if ( v23[11].__vftable == nullptr )
              SetRectEmpty(lprc: (LPRECT)&v23[3]);
          }
        }
        goto LABEL_141;
      }
      v108 = 1;
      v107 = 1;
      this->GetTasksGroupBorders(this, result: (CSize *)&v97);
      v24 = data->m_lstTasks.m_pNodeHead;
      if ( v24 != nullptr )
      {
        while ( 1 )
        {
          pNext = (int)v24->pNext;
          v26 = v24->data;
          v103 = pNext;
          v106 = v26;
          if ( v26[11].__vftable != nullptr )
          {
            if ( v108 != 0 && v26[13].__vftable != nullptr )
            {
              if ( this->m_bOffsetCustomControls != 0 )
              {
                m_nTasksIconVertOffset = this->m_nTasksIconVertOffset;
                if ( m_nTasksIconVertOffset == -1 )
                  m_nTasksIconVertOffset = CMFCVisualManager::GetInstance()->m_nTasksIconVertOffset;
              }
              else
              {
                m_nTasksIconVertOffset = v98;
              }
              v109 = (CFont *)((char *)v109 + m_nTasksIconVertOffset);
            }
            CWnd::FromHandle(hWnd: (HWND__ *)v26[11].__vftable);
            if ( bCalcHeightOnly != 0 )
              goto LABEL_115;
            v113 = rc;
            if ( v106[13].__vftable != nullptr )
              v46 = v106[8].__vftable;
            else
              v46 = nullptr;
            v47 = (int)v109 + (_DWORD)v46;
            v48 = this->m_rectTasks.top + 1;
            v113.bottom = v47;
            v113.top = v48;
            if ( v48 <= (int)v109 )
              v113.top = (int)v109;
            dy = (int)v106[8].__vftable + v113.top - v47;
            if ( this->m_rectTasks.bottom < v47 )
              v113.bottom = this->m_rectTasks.bottom;
            if ( this->m_bOffsetCustomControls != 0 )
            {
              m_nTasksHorzOffset = this->m_nTasksHorzOffset;
              if ( m_nTasksHorzOffset == -1 )
                m_nTasksHorzOffset = CMFCVisualManager::GetInstance()->m_nTasksHorzOffset;
            }
            else
            {
              m_nTasksHorzOffset = v97;
            }
            InflateRect(lprc: &v113, dx: -m_nTasksHorzOffset, dy: 0);
            v50 = v106 + 3;
            v106[3].__vftable = (CObject_vtbl *)v113.left;
            ++v50;
            v50->__vftable = (CObject_vtbl *)v113.top;
            ++v50;
            v50->__vftable = (CObject_vtbl *)v113.right;
            v50[1].__vftable = (CObject_vtbl *)v113.bottom;
            if ( this->IsToolBox(this) == 0 )
            {
LABEL_115:
              v51 = v106;
            }
            else
            {
              v51 = v106;
              v52 = !IsRectEmpty(lprc: (const RECT *)&v106[3]);
              v53 = this->__vftable;
              if ( v52 )
                ((void (__stdcall *)(CObject_vtbl *, int))v53->ScrollChild)(a1: v51[11].__vftable, a2: dy);
              else
                ((void (__stdcall *)(CObject_vtbl *, _DWORD))v53->ScrollChild)(a1: v51[11].__vftable, a2: 0);
            }
            if ( v51[13].__vftable != nullptr )
            {
              v109 = (CFont *)((char *)v109 + (unsigned int)v51[8].__vftable);
              v108 = 1;
              v107 = 1;
            }
          }
          else
          {
            if ( v26[13].__vftable != nullptr )
            {
              if ( v108 != 0 )
              {
                v27 = this->m_nTasksIconVertOffset;
                if ( v27 == -1 )
                  v27 = CMFCVisualManager::GetInstance()->m_nTasksIconVertOffset;
                v109 = (CFont *)((char *)v109 + v27);
              }
              v28 = this->m_nTasksHorzOffset;
              if ( v28 == -1 )
                v28 = CMFCVisualManager::GetInstance()->m_nTasksHorzOffset;
              dy = v28;
              m_nTasksIconHorzOffset = this->m_nTasksIconHorzOffset;
              if ( m_nTasksIconHorzOffset == -1 )
                m_nTasksIconHorzOffset = CMFCVisualManager::GetInstance()->m_nTasksIconHorzOffset;
              v107 = m_nTasksIconHorzOffset;
              if ( v26[9].__vftable != nullptr )
                m_bWrapTasks = this->m_bWrapTasks;
              else
                m_bWrapTasks = this->m_bWrapLabels;
              if ( m_bWrapTasks != 0 )
              {
                v114 = rc;
                InflateRect(lprc: &v114, dx: -dy, dy: 0);
                v31 = this->m_sizeIcon.cy;
                v114.top = (int)v109;
                v32 = v114.left + this->m_sizeIcon.cx;
                v114.bottom = (int)v109 + v31;
                v112[1] = v109;
                v112[2] = v114.right;
                v112[3] = (char *)v109 + v31;
                v112[0] = v107 + v32;
                v33 = CDC::SelectObject(this: &v100, pFont: &afxGlobalData.fontUnderline);
                v34 = v106;
                v35 = v33;
                v108 = v100.DrawTextA(
                         this: &v100,
                         a2: (const char *)v106[2].__vftable,
                         a3: (int)v106[2].__vftable[-1].GetRuntimeClass,
                         a4: (tagRECT *)v112,
                         a5: 1040u);
                CDC::SelectObject(this: &v100, pFont: v35);
                if ( v34[15].__vftable != nullptr && v108 <= 10 )
                  v108 = 10;
                if ( v108 <= this->m_sizeIcon.cy )
                  v108 = this->m_sizeIcon.cy;
                v114.bottom = v114.top + v108;
                if ( bCalcHeightOnly == 0 )
                {
                  v36 = v106 + 3;
                  v106[3].__vftable = (CObject_vtbl *)v114.left;
                  ++v36;
                  v36->__vftable = (CObject_vtbl *)v114.top;
                  ++v36;
                  v36->__vftable = (CObject_vtbl *)v114.right;
                  v36[1].__vftable = (CObject_vtbl *)v114.bottom;
                }
              }
              else
              {
                v39 = CDC::SelectObject(this: &v100, pFont: &afxGlobalData.fontUnderline);
                CDC::GetTextExtent(
                  this: &v100,
                  result: &v95,
                  str: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v26[2]);
                CDC::SelectObject(this: &v100, pFont: v39);
                v40 = this->m_sizeIcon.cy;
                v108 = v95.cy;
                if ( v95.cy <= v40 )
                  v108 = v40;
                if ( v26[15].__vftable != nullptr && v108 <= 10 )
                  v108 = 10;
                if ( bCalcHeightOnly == 0 )
                {
                  v41 = dy;
                  v85 = rc.left + dy + v107 + v95.cx + this->m_sizeIcon.cx;
                  v83 = dy + rc.left;
                  v86 = (CObject_vtbl *)((char *)v109 + v108);
                  v42 = v106;
                  v84 = v109;
                  v43 = v106 + 3;
                  v106[3].__vftable = (CObject_vtbl *)(dy + rc.left);
                  ++v43;
                  v43->__vftable = (CObject_vtbl *)v84;
                  ++v43;
                  v43->__vftable = (CObject_vtbl *)v85;
                  v43[1].__vftable = v86;
                  v44 = (int)v42[3].__vftable;
                  if ( v44 <= rc.right - v41 )
                    v44 = rc.right - v41;
                  v106[5].__vftable = (CObject_vtbl *)v44;
                }
              }
              v37 = this->m_nTasksIconVertOffset;
              if ( v37 == -1 )
                v37 = CMFCVisualManager::GetInstance()->m_nTasksIconVertOffset;
              v38 = v108 + v37;
              v108 = 0;
              v109 = (CFont *)((char *)v109 + v38);
              v107 = 0;
              goto LABEL_125;
            }
            if ( bCalcHeightOnly == 0 )
              SetRectEmpty(lprc: (LPRECT)&v106[3]);
          }
          if ( v107 != 0 && v106[13].__vftable != nullptr )
          {
            if ( this->m_bOffsetCustomControls != 0 )
            {
              v54 = this->m_nTasksIconVertOffset;
              if ( v54 == -1 )
                v54 = CMFCVisualManager::GetInstance()->m_nTasksIconVertOffset;
            }
            else
            {
              v54 = v98;
            }
            v109 = (CFont *)((char *)v109 + v54);
          }
LABEL_125:
          if ( bCalcHeightOnly == 0 && this->m_bAnimationEnabled != 0 && v102 == this->m_pAnimatedGroup )
          {
            v55 = this->m_sizeAnim.cy;
            v56 = v109;
            if ( (int)v109 > (int)((char *)pFont + v55) )
            {
              if ( v55 < 0 )
                v55 = 0;
              v57 = (char *)v106[6].__vftable;
              v58 = (CFont *)((char *)pFont + v55);
              v59 = (char *)&v58[-1].m_hObject + 3;
              v109 = v58;
              if ( (int)v57 >= (int)((char *)&v58[-1].m_hObject + 3) )
                v57 = (char *)&v58[-1].m_hObject + 3;
              if ( (int)v106[4].__vftable <= (int)v57 )
              {
                if ( (int)v106[6].__vftable < (int)v59 )
                  v59 = (char *)v106[6].__vftable;
              }
              else
              {
                v59 = (char *)v106[4].__vftable;
              }
              v106[6].__vftable = (CObject_vtbl *)v59;
              this->m_nAnimGroupExtraHeight += (char *)v56 - (char *)v58;
            }
          }
          if ( v103 == 0 )
            break;
          v24 = (CObList::CNode *)v103;
        }
      }
      if ( bCalcHeightOnly == 0 )
      {
        v91 = rc.left;
        v92 = pFont;
        v93 = rc.right;
        v60 = &v102->m_rectGroup;
        v94 = v109;
        v102->m_rectGroup.left = rc.left;
        v60 = (CRect *)((char *)v60 + 4);
        v60->left = (int)v92;
        v60 = (CRect *)((char *)v60 + 4);
        v60->left = v93;
        v60->top = (int)v94;
      }
LABEL_141:
      m_nGroupVertOffset = this->m_nGroupVertOffset;
      if ( m_nGroupVertOffset == -1 )
        m_nGroupVertOffset = CMFCVisualManager::GetInstance()->m_nGroupVertOffset;
      v109 = (CFont *)((char *)v109 + m_nGroupVertOffset);
      m_pNodeHead = v101;
      v11 = v99;
    }
  }
  if ( bCalcHeightOnly == 0 )
  {
    m_pNodeTail = this->m_lstTaskGroups.m_pNodeTail;
    while ( m_pNodeTail != nullptr )
    {
      v63 = m_pNodeTail->data;
      m_pNodeTail = m_pNodeTail->pPrev;
      if ( (CMFCTasksPanePropertyPage *)v63[1].__vftable == v11 )
      {
        if ( v63[10].__vftable != nullptr && v63[6].__vftable != nullptr && this->m_nVertScrollTotal == 0 )
        {
          v64 = v63[5].__vftable;
          while ( v64 != nullptr )
          {
            Serialize = v64->Serialize;
            v64 = (CObject_vtbl *)v64->dtr_CObject;
            if ( *((_DWORD *)Serialize + 13) != 0 )
            {
              dy = rc.bottom - (unsigned int)v63[20].__vftable;
              if ( dy > 0 )
              {
                v66 = v63[4].__vftable;
                while ( v66 != nullptr )
                {
                  v67 = v66->Serialize;
                  v66 = (CObject_vtbl *)v66->GetRuntimeClass;
                  if ( *((_DWORD *)v67 + 13) != 0 )
                    OffsetRect(lprc: (LPRECT)((char *)v67 + 12), dx: 0, dy);
                }
                OffsetRect(lprc: (LPRECT)&v63[13], dx: 0, dy);
                OffsetRect(lprc: (LPRECT)&v63[17], dx: 0, dy);
              }
              goto LABEL_163;
            }
          }
        }
        break;
      }
    }
LABEL_163:
    v68 = this->m_lstTaskGroups.m_pNodeHead;
    while ( v68 != nullptr )
    {
      v69 = (CMFCTasksPaneTaskGroup *)v68->data;
      v68 = v68->pNext;
      v101 = v68;
      if ( v69->m_pPage == v99 )
      {
        if ( this->m_bCanCollapse == 0
          || v69->m_bIsCollapsed == 0
          || (m_pszData = v69->m_strName.m_pszData, pFont = (CFont *)1, *((_DWORD *)m_pszData - 3) == 0) )
        {
          pFont = nullptr;
        }
        if ( this->m_bAnimationEnabled == 0 || v69 != this->m_pAnimatedGroup || (v103 = 1, this->m_sizeAnim.cy <= 0) )
          v103 = 0;
        v107 = (int)v69->m_lstTasks.m_pNodeHead;
        if ( v107 != 0 )
        {
          do
          {
            v71 = *(_DWORD *)(v107 + 8);
            v72 = *(HWND__ **)(v71 + 44);
            v107 = *(_DWORD *)v107;
            if ( v72 != nullptr )
            {
              dy = (int)CWnd::FromHandle(hWnd: v72);
              if ( pFont != nullptr && v103 == 0
                || *(_DWORD *)(v71 + 52) == 0
                || IsRectEmpty(lprc: (const RECT *)(v71 + 12)) )
              {
                CWnd::ShowWindow(this: (CWnd *)dy, nCmdShow: 0);
              }
              else
              {
                CWnd::SetWindowPos(
                  this: (CWnd *)dy,
                  pWndInsertAfter: nullptr,
                  x: *(_DWORD *)(v71 + 12),
                  y: *(_DWORD *)(v71 + 16),
                  cx: *(_DWORD *)(v71 + 20) - *(_DWORD *)(v71 + 12),
                  cy: *(_DWORD *)(v71 + 24) - *(_DWORD *)(v71 + 16),
                  nFlags: 0x14u);
                CWnd::ShowWindow(this: (CWnd *)dy, nCmdShow: 4);
              }
            }
          }
          while ( v107 != 0 );
          v68 = v101;
        }
      }
    }
  }
  CDC::SelectObject(this: &v100, pFont: v96);
  if ( this->m_nGroupVertOffset == -1 )
    v73 = CMFCVisualManager::GetInstance()->m_nGroupVertOffset;
  else
    v73 = this->m_nGroupVertOffset;
  v74 = this->m_nVertMargin;
  if ( v74 == -1 )
    v74 = CMFCVisualManager::GetInstance()->m_nVertMargin;
  v75 = this->m_nVertScrollOffset * this->m_nRowHeight;
  v115 = -1;
  v76 = (char *)v109 + v74 + v75 - v73;
  CClientDC::~CClientDC(this: &v100);
  return v76;
}

//------------------------------------------------------------------------------
// Address: 0x10431EFD
// Name: protected: void CMFCTasksPane::RebuildMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::RebuildMenu(CMFCTasksPane *this)
{
  HMENU Menu; // eax

  if ( this->m_menuOther.m_hMenu != nullptr )
    CMenu::DestroyMenu(this: &this->m_menuOther);
  Menu = CMFCTasksPane::CreateMenu(this);
  CMenu::Attach(this: &this->m_menuOther, hMenu: Menu);
  CMFCTasksPaneToolBar::UpdateButtons(this: &this->m_wndToolBar);
  CDockablePane::EnableButton(this, nHit: 0x17u, bEnable: this->m_iActivePage > 0);
  CDockablePane::EnableButton(this, nHit: 0x18u, bEnable: this->m_iActivePage < this->m_arrHistoryStack.m_nSize - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10431F67
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCTasksPaneToolBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCTasksPaneToolBar::GetMessageMap(CMFCTasksPaneToolBar *this)
{
  return (const AFX_MSGMAP *)&off_10694EF0;
}

//------------------------------------------------------------------------------
// Address: 0x10431F6D
// Name: protected: int CMFCTasksPane::OnNeedTipText(unsigned int,struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::OnNeedTipText(CMFCTasksPane *this, unsigned int id, tagNMHDR *pNMH, int *pResult)
{
  CAfxStringMgr *StringManager; // eax
  CToolTipCtrl *m_pToolTip; // eax
  unsigned int idFrom; // eax
  unsigned int v8; // edi
  HINSTANCE__ *StringResourceHandle; // eax

  if ( (_S1_47 & 1) == 0 )
  {
    _S1_47 |= 1u;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTipText_6, pStringMgr: StringManager);
    atexit(func: CMFCTasksPane::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__);
  }
  if ( pNMH == nullptr )
LABEL_4:
    AfxThrowInvalidArgException();
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip == nullptr || m_pToolTip->m_hWnd == nullptr || pNMH->hwndFrom != m_pToolTip->m_hWnd )
    return 0;
  idFrom = pNMH->idFrom;
  switch ( idFrom )
  {
    case 4u:
      v8 = 17020;
      break;
    case 5u:
      v8 = 17021;
      break;
    case 6u:
      v8 = 17024;
      break;
    default:
      return CDockablePane::OnNeedTipText(this, __formal: id, pNMH, __formal: pResult);
  }
  StringResourceHandle = AfxFindStringResourceHandle(__formal: v8);
  if ( StringResourceHandle == nullptr
    || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: &strTipText_6,
         hInstance: StringResourceHandle,
         nID: v8) == 0 )
  {
    goto LABEL_4;
  }
  pNMH[1].hwndFrom = (HWND__ *)strTipText_6.m_pszData;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1043202D
// Name: public: virtual int CMFCTasksPane::SaveState(char const __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::SaveState(
        CMFCTasksPane *this,
        const char *lpszProfileName,
        int nIndex,
        unsigned int uiID)
{
  CAfxStringMgr *StringManager; // eax
  CMFCTasksPane_vtbl *v6; // eax
  unsigned __int8 *v7; // edi
  CSettingsStore *v8; // esi
  int v9; // esi
  CArchive ar; // [esp+10h] [ebp-A4h] BYREF
  CMemFile file; // [esp+58h] [ebp-5Ch] BYREF
  unsigned __int64 Length; // [esp+88h] [ebp-2Ch]
  CSettingsStoreSP regSP; // [esp+90h] [ebp-24h] BYREF
  CDockablePane *v15; // [esp+98h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strProfileName; // [esp+9Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strSection; // [esp+A0h] [ebp-14h] BYREF
  int v18; // [esp+B0h] [ebp-4h]

  v15 = this;
  AFXGetRegPath(result: &strProfileName, lpszPostFix: strTasksPaneProfile.m_pszData, lpszProfileName);
  v18 = 0;
  if ( nIndex == -1 )
    nIndex = CWnd::GetDlgCtrlID(this);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strSection, pStringMgr: StringManager);
  LOBYTE(v18) = 1;
  if ( uiID == -1 )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strSection,
      pszFormat: "%sMFCTasksPane-%d",
      strProfileName.m_pszData,
      nIndex);
  else
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strSection,
      pszFormat: "%sMFCTasksPane-%d%x",
      strProfileName.m_pszData,
      nIndex,
      uiID);
  LOBYTE(v18) = 2;
  CMemFile::CMemFile(this: &file, nGrowBytes: 0x400u);
  LOBYTE(v18) = 3;
  CArchive::CArchive(this: &ar, pFile: &file, nMode: 0, nBufSize: 4096, lpBuf: nullptr);
  v6 = this->__vftable;
  LOBYTE(v18) = 4;
  v6->Serialize(this, a2: &ar);
  CArchive::Flush(this: &ar);
  LOBYTE(v18) = 3;
  CArchive::~CArchive(this: &ar);
  Length = CMemFile::GetLength(this: &file);
  v7 = CMemFile::Detach(this: &file);
  if ( v7 != nullptr )
  {
    regSP.m_pRegistry = nullptr;
    regSP.m_dwUserData = 0;
    LOBYTE(v18) = 5;
    v8 = CSettingsStoreSP::Create(this: &regSP, bAdmin: 0, bReadOnly: 0);
    if ( v8->CreateKey(this: v8, a2: strSection.m_pszData) != 0 )
      v8->Write_3(this: v8, a2: "Settings", a3: v7, a4: Length);
    free(pMem: v7);
    LOBYTE(v18) = 3;
    if ( regSP.m_pRegistry != nullptr )
      ((void (__cdecl *)(int))regSP.m_pRegistry->dtr_CObject)(a1: 1);
  }
  LOBYTE(v18) = 2;
  CMemFile::~CMemFile(this: &file);
  v18 = 1;
  v9 = CDockablePane::SaveState(this: v15, lpszProfileName, nIndex, uiID);
  ATL::CStringData::Release(this: (ATL::CStringData *)strSection.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strProfileName.m_pszData - 1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x104321CE
// Name: public: virtual int CMFCTasksPane::LoadState(char const __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::LoadState(
        CMFCTasksPane *this,
        const char *lpszProfileName,
        int nIndex,
        unsigned int uiID)
{
  CAfxStringMgr *StringManager; // eax
  CSettingsStore *v5; // eax
  char *m_pszData; // ebx
  CSettingsStore *v7; // esi
  int State; // esi
  CWnd_vtbl *v10; // eax
  CArchive ar; // [esp+10h] [ebp-A8h] BYREF
  CMemFile file; // [esp+58h] [ebp-60h] BYREF
  unsigned int uiDataSize; // [esp+8Ch] [ebp-2Ch] BYREF
  CSettingsStoreSP regSP; // [esp+90h] [ebp-28h] BYREF
  CWnd *v15; // [esp+98h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strProfileName; // [esp+9Ch] [ebp-1Ch] BYREF
  unsigned __int8 *lpbData; // [esp+A0h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strSection; // [esp+A4h] [ebp-14h] BYREF
  int v19; // [esp+B4h] [ebp-4h]

  v15 = this;
  AFXGetRegPath(result: &strProfileName, lpszPostFix: strTasksPaneProfile.m_pszData, lpszProfileName);
  v19 = 0;
  if ( nIndex == -1 )
    nIndex = CWnd::GetDlgCtrlID(this: v15);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strSection, pStringMgr: StringManager);
  LOBYTE(v19) = 1;
  if ( uiID == -1 )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strSection,
      pszFormat: "%sMFCTasksPane-%d",
      strProfileName.m_pszData,
      nIndex);
  else
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strSection,
      pszFormat: "%sMFCTasksPane-%d%x",
      strProfileName.m_pszData,
      nIndex,
      uiID);
  lpbData = nullptr;
  regSP.m_pRegistry = nullptr;
  regSP.m_dwUserData = 0;
  LOBYTE(v19) = 2;
  v5 = CSettingsStoreSP::Create(this: &regSP, bAdmin: 0, bReadOnly: 1);
  m_pszData = strSection.m_pszData;
  v7 = v5;
  if ( v5->Open(this: v5, a2: strSection.m_pszData) != 0 )
  {
    if ( v7->Read_3(this: v7, a2: "Settings", a3: &lpbData, a4: &uiDataSize) != 0 )
    {
      LOBYTE(v19) = 3;
      CMemFile::CMemFile(this: &file, lpBuffer: lpbData, nBufferSize: uiDataSize, nGrowBytes: 0);
      LOBYTE(v19) = 4;
      CArchive::CArchive(this: &ar, pFile: &file, nMode: 1u, nBufSize: 4096, lpBuf: nullptr);
      v10 = v15->__vftable;
      LOBYTE(v19) = 5;
      ((void (__cdecl *)(CArchive *))v10->Serialize)(a1: &ar);
      LOBYTE(v19) = 4;
      CArchive::~CArchive(this: &ar);
      LOBYTE(v19) = 3;
      CMemFile::~CMemFile(this: &file);
      v19 = 2;
      if ( lpbData != nullptr )
        operator delete(p: lpbData);
      State = CDockablePane::LoadState(this: (CDockablePane *)v15, lpszProfileName, nIndex, uiID);
      LOBYTE(v19) = 1;
      if ( regSP.m_pRegistry != nullptr )
        ((void (__thiscall *)(CSettingsStore *, int))regSP.m_pRegistry->dtr_CObject)(a1: regSP.m_pRegistry, a2: 1);
      m_pszData = strSection.m_pszData;
    }
    else
    {
      LOBYTE(v19) = 1;
      if ( regSP.m_pRegistry != nullptr )
        ((void (__thiscall *)(CSettingsStore *, int))regSP.m_pRegistry->dtr_CObject)(a1: regSP.m_pRegistry, a2: 1);
      State = 0;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)strProfileName.m_pszData - 1);
    return State;
  }
  else
  {
    LOBYTE(v19) = 1;
    if ( regSP.m_pRegistry != nullptr )
      ((void (__thiscall *)(CSettingsStore *, int))regSP.m_pRegistry->dtr_CObject)(a1: regSP.m_pRegistry, a2: 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)strProfileName.m_pszData - 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104323BA
// Name: public: virtual int CMFCTasksPanePropertyPage::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPanePropertyPage::SetACCData(
        CMFCTasksPanePropertyPage *this,
        CWnd *__formal,
        CAccessibilityData *data)
{
  CAccessibilityData::Clear(this: data);
  ATL::CSimpleStringT<char,0>::operator=(this: &data->m_strAccName, strSrc: (ATL::CStringData *)&this->m_strName);
  data->m_nAccRole = 37;
  data->m_nAccHit = 1;
  data->m_bAccState = 256;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104323F2
// Name: public: void CMFCTasksPaneToolBar::UpdateMenuButtonText(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneToolBar::UpdateMenuButtonText(CMFCTasksPaneToolBar *this, ATL::CStringData *str)
{
  CObList::CNode *m_pNodeHead; // esi
  ATL::CSimpleStringT<char,0> *v3; // eax
  CObject *data; // [esp-4h] [ebp-8h]

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v3 = (ATL::CSimpleStringT<char,0> *)AfxDynamicDownCast(
                                          pClass: &CTasksPaneMenuButton::classCTasksPaneMenuButton,
                                          pObject: data);
    if ( v3 != nullptr )
      ATL::CSimpleStringT<char,0>::operator=(this: v3 + 11, strSrc: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10432435
// Name: protected: virtual int CMFCTasksPaneToolBar::OnUserToolTip(class CMFCToolBarButton __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPaneToolBar::OnUserToolTip(
        CMFCTasksPaneToolBar *this,
        CMFCToolBarButton *pButton,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strTTText)
{
  HINSTANCE__ *StringResourceHandle; // eax
  CObject *v5; // eax

  if ( CObject::IsKindOf(this: pButton, pClass: &CTasksPaneMenuButton::classCTasksPaneMenuButton) != 0 )
  {
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x4280u);
    if ( StringResourceHandle == nullptr
      || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: strTTText,
           hInstance: StringResourceHandle,
           nID: 0x4280u) == 0 )
    {
      AfxThrowInvalidArgException();
    }
    return 1;
  }
  v5 = AfxDynamicDownCast(pClass: &CTasksPaneNavigateButton::classCTasksPaneNavigateButton, pObject: pButton);
  if ( v5 != nullptr
    || (v5 = AfxDynamicDownCast(pClass: &CTasksPaneHistoryButton::classCTasksPaneHistoryButton, pObject: pButton)) != nullptr )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: strTTText, strSrc: (ATL::CStringData *)&v5[11]);
    return 1;
  }
  return CMFCToolBar::OnUserToolTip(this, pButton, strTTText);
}

//------------------------------------------------------------------------------
// Address: 0x104324B7
// Name: public: CMFCTasksPane::CMFCTasksPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPane *__thiscall CMFCTasksPane::CMFCTasksPane(CMFCTasksPane *this)
{
  CAfxStringMgr *StringManager; // eax
  bool v3; // zf
  CSize v5; // [esp+10h] [ebp-18h] BYREF
  CMFCTasksPane *v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+24h] [ebp-4h]

  v6 = this;
  CDockablePane::CDockablePane(this);
  this->__vftable = (CMFCTasksPane_vtbl *)&CMFCTasksPane::`vftable';
  this->m_nMaxHistory = 10;
  v7 = 0;
  this->m_fontBold.m_hObject = nullptr;
  this->m_fontBold.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->m_fontBoldUnderline.m_hObject = nullptr;
  this->m_fontBoldUnderline.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->m_fontUnderline.m_hObject = nullptr;
  this->m_fontUnderline.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->m_sizeIcon.cx = 0;
  this->m_sizeIcon.cy = 0;
  this->m_sizeToolbarImage.cx = 0;
  this->m_sizeToolbarImage.cy = 0;
  this->m_sizeToolbarButton.cx = 0;
  this->m_sizeToolbarButton.cy = 0;
  this->m_sizeAnim.cx = 0;
  this->m_sizeAnim.cy = 0;
  this->m_rectToolbar.left = 0;
  this->m_rectToolbar.top = 0;
  this->m_rectToolbar.right = 0;
  this->m_rectToolbar.bottom = 0;
  this->m_rectScrollUp.left = 0;
  this->m_rectScrollUp.top = 0;
  this->m_rectScrollUp.right = 0;
  this->m_rectScrollUp.bottom = 0;
  this->m_rectScrollDn.left = 0;
  this->m_rectScrollDn.top = 0;
  this->m_rectScrollDn.right = 0;
  this->m_rectScrollDn.bottom = 0;
  this->m_rectTasks.left = 0;
  this->m_rectTasks.top = 0;
  this->m_rectTasks.right = 0;
  this->m_rectTasks.bottom = 0;
  this->m_menuOther.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_menuOther.m_hMenu = nullptr;
  CObList::CObList(this: &this->m_lstTasksPanes, nBlockSize: 10);
  CObList::CObList(this: &this->m_lstTaskGroups, nBlockSize: 10);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  CWnd::CWnd(this: &this->m_wndScrollVert);
  this->m_wndScrollVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  CImageList::CImageList(this: &this->m_lstIcons);
  this->m_arrHistoryStack.__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
  this->m_arrHistoryStack.m_pData = nullptr;
  this->m_arrHistoryStack.m_nGrowBy = 0;
  this->m_arrHistoryStack.m_nMaxSize = 0;
  this->m_arrHistoryStack.m_nSize = 0;
  CMFCTasksPaneToolBar::CMFCTasksPaneToolBar(this: &this->m_wndToolBar);
  LOBYTE(v7) = 11;
  this->m_hFont = nullptr;
  this->m_sizeIcon.cx = 0;
  this->m_sizeIcon.cy = 0;
  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arrHistoryStack,
    nIndex: this->m_arrHistoryStack.m_nSize,
    newElement: nullptr);
  this->m_nVertMargin = -1;
  this->m_nHorzMargin = -1;
  this->m_nGroupVertOffset = -1;
  this->m_nGroupCaptionHeight = -1;
  this->m_nGroupCaptionHorzOffset = -1;
  this->m_nGroupCaptionVertOffset = -1;
  this->m_nTasksHorzOffset = -1;
  this->m_nTasksIconHorzOffset = -1;
  this->m_nTasksIconVertOffset = -1;
  this->m_iActivePage = 0;
  this->m_pHotTask = nullptr;
  this->m_pClickedTask = nullptr;
  this->m_pHotGroupCaption = nullptr;
  this->m_pClickedGroupCaption = nullptr;
  this->m_bCanCollapse = 1;
  this->m_nVertScrollOffset = 0;
  this->m_nVertScrollTotal = 0;
  this->m_nVertScrollPage = 0;
  this->m_nRowHeight = 0;
  this->m_bOffsetCustomControls = 1;
  SetRectEmpty(lprc: &this->m_rectTasks);
  this->m_sizeToolbarImage.cx = 0;
  this->m_sizeToolbarButton.cx = 0;
  this->m_bUseNavigationToolbar = 0;
  this->m_bHistoryMenuButtons = 0;
  this->m_uiToolbarBmpRes = 0;
  this->m_sizeToolbarImage.cy = 0;
  this->m_sizeToolbarButton.cy = 0;
  SetRectEmpty(lprc: &this->m_rectToolbar);
  this->m_bUseScrollButtons = 1;
  SetRectEmpty(lprc: &this->m_rectScrollUp);
  SetRectEmpty(lprc: &this->m_rectScrollDn);
  this->m_iScrollBtnHeight = CMenuImages::Size(result: &v5)->cy + 2;
  this->m_iScrollMode = 0;
  v3 = afxGlobalData.bIsRemoteSession == 0;
  this->m_pAnimatedGroup = nullptr;
  this->m_sizeAnim.cy = 0;
  this->m_bMenuBtnPressed = 0;
  this->m_bWrapTasks = 0;
  this->m_bWrapLabels = 0;
  this->m_bEnableActiveAccessibility = true;
  this->m_bAnimationEnabled = v3;
  this->m_sizeAnim.cx = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1043279D
// Name: public: virtual CMFCTasksPane::~CMFCTasksPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::~CMFCTasksPane(CMFCTasksPane *this)
{
  CObject *v2; // eax

  this->__vftable = (CMFCTasksPane_vtbl *)&CMFCTasksPane::`vftable';
  while ( this->m_lstTasksPanes.m_nCount != 0 )
  {
    v2 = CObList::RemoveHead(this: &this->m_lstTasksPanes);
    if ( v2 != nullptr )
      ((void (__thiscall *)(CObject *, int))v2->dtr_CObject)(a1: v2, a2: 1);
  }
  CMFCToolBar::~CMFCToolBar(this: &this->m_wndToolBar);
  CArray<int,int>::~CArray<int,int>(this: &this->m_arrHistoryStack);
  CImageList::~CImageList(this: &this->m_lstIcons);
  CScrollBar::~CScrollBar(this: &this->m_wndScrollVert);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCaption.m_pszData - 1);
  CObList::~CObList(this: &this->m_lstTaskGroups);
  CObList::~CObList(this: &this->m_lstTasksPanes);
  this->m_menuOther.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &this->m_menuOther);
  this->m_fontUnderline.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_fontUnderline);
  this->m_fontBoldUnderline.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_fontBoldUnderline);
  this->m_fontBold.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_fontBold);
  CDockablePane::~CDockablePane(this);
}

//------------------------------------------------------------------------------
// Address: 0x104328A4
// Name: protected: virtual void CMFCTasksPane::OnDrawTasks(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnDrawTasks(CMFCTasksPane *this, CDC *pDC, CRect __formal)
{
  int v4; // eax
  CMFCTasksPane_vtbl *v5; // eax
  int m_iActivePage; // eax
  __POSITION *Index; // eax
  HRGN v8; // eax
  CObList::CNode *m_pNodeHead; // eax
  CMFCTasksPaneTaskGroup *data; // edi
  CMFCVisualManager *v11; // eax
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager *v13; // eax
  CMFCVisualManager *v14; // eax
  CObList::CNode *v15; // edi
  CObList::CNode *v16; // ecx
  CMFCTasksPaneTask *v17; // edi
  CMFCVisualManager *v18; // eax
  CMFCVisualManager *v19; // eax
  CMFCVisualManager *v20; // eax
  CMFCTasksPanePropertyPage *v21; // [esp+10h] [ebp-48h]
  CRect m_rectTasks; // [esp+18h] [ebp-40h] BYREF
  CObList::CNode *pNext; // [esp+28h] [ebp-30h]
  CRect *p_m_rectGroup; // [esp+2Ch] [ebp-2Ch]
  CMFCTasksPaneTaskGroup *v25; // [esp+30h] [ebp-28h]
  CDC *v26; // [esp+34h] [ebp-24h]
  RECT rect; // [esp+38h] [ebp-20h] BYREF
  int v28; // [esp+54h] [ebp-4h]

  v4 = this->m_nVertScrollOffset * this->m_nRowHeight;
  m_rectTasks = this->m_rectTasks;
  m_rectTasks.top -= v4;
  v5 = this->__vftable;
  v26 = pDC;
  ((void (__thiscall *)(CMFCTasksPane *, CDC *, int, int, int, int))v5->OnFillBackground)(
    a1: this,
    a2: pDC,
    a3: m_rectTasks.left,
    a4: m_rectTasks.top,
    a5: m_rectTasks.right,
    a6: m_rectTasks.bottom);
  m_iActivePage = this->m_iActivePage;
  if ( m_iActivePage < 0
    || m_iActivePage >= this->m_arrHistoryStack.m_nSize
    || (Index = CStringList::FindIndex(
                  this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
                  nIndex: this->m_arrHistoryStack.m_pData[m_iActivePage])) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  v21 = *(CMFCTasksPanePropertyPage **)&Index[8];
  m_rectTasks.bottom = 0;
  m_rectTasks.right = (int)&CRgn::`vftable';
  v28 = 0;
  memset(&rect, 0, sizeof(rect));
  v8 = CreateRectRgnIndirect(lprect: &rect);
  CGdiObject::Attach(this: (CGdiObject *)&m_rectTasks.right, hObject: v8);
  m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = (CMFCTasksPaneTaskGroup *)m_pNodeHead->data;
      pNext = m_pNodeHead->pNext;
      v25 = data;
      if ( data->m_pPage == v21 )
      {
        if ( data->m_bIsCollapsed == 0
          || *((_DWORD *)data->m_strName.m_pszData - 3) == 0
          || this->m_bAnimationEnabled != 0 && data == this->m_pAnimatedGroup && this->m_sizeAnim.cy > 0 )
        {
          p_m_rectGroup = &data->m_rectGroup;
          if ( !IsRectEmpty(lprc: &data->m_rectGroup) )
          {
            Instance = CMFCVisualManager::GetInstance();
            ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD))Instance->OnFillTasksGroupInterior)(
              a1: Instance,
              a2: v26,
              a3: p_m_rectGroup->left,
              a4: p_m_rectGroup->top,
              a5: p_m_rectGroup->right,
              a6: p_m_rectGroup->bottom,
              a7: 0);
            data = v25;
          }
          if ( !IsRectEmpty(lprc: &data->m_rect) )
          {
            v13 = CMFCVisualManager::GetInstance();
            v13->OnDrawTasksGroupCaption(
              this: v13,
              a2: v26,
              a3: data,
              a4: this->m_pHotGroupCaption == data,
              a5: 0,
              a6: this->m_bCanCollapse);
          }
          p_m_rectGroup = &data->m_rectGroup;
          if ( !IsRectEmpty(lprc: &data->m_rectGroup) )
          {
            this->GetTasksGroupBorders(this, result: (CSize *)&rect.right);
            if ( rect.right > 0 || rect.bottom > 0 )
            {
              v14 = CMFCVisualManager::GetInstance();
              ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, bool))v14->OnDrawTasksGroupAreaBorder)(
                a1: v14,
                a2: v26,
                a3: p_m_rectGroup->left,
                a4: p_m_rectGroup->top,
                a5: p_m_rectGroup->right,
                a6: p_m_rectGroup->bottom,
                a7: data->m_bIsSpecial,
                a8: *((_DWORD *)data->m_strName.m_pszData - 3) == 0);
              data = v25;
            }
            v15 = data->m_lstTasks.m_pNodeHead;
            if ( v15 != nullptr )
            {
              while ( 1 )
              {
                v16 = v15->pNext;
                v17 = (CMFCTasksPaneTask *)v15->data;
                v25 = (CMFCTasksPaneTaskGroup *)v16;
                if ( v17->m_bVisible != 0 && v17->m_hwndTask == nullptr )
                {
                  SetRectRgn(
                    hrgn: (HRGN)m_rectTasks.bottom,
                    left: v17->m_rect.left,
                    top: v17->m_rect.top,
                    right: v17->m_rect.right,
                    bottom: v17->m_rect.bottom);
                  CDC::SelectClipRgn(this: v26, pRgn: (CRgn *)&m_rectTasks.right);
                  v18 = CMFCVisualManager::GetInstance();
                  v18->OnDrawTask(
                    this: v18,
                    a2: v26,
                    a3: v17,
                    a4: &this->m_lstIcons,
                    a5: v17 == this->m_pHotTask,
                    a6: 0);
                  CDC::SelectClipRgn(this: v26, pRgn: nullptr);
                }
                if ( v25 == nullptr )
                  break;
                v15 = (CObList::CNode *)v25;
              }
            }
          }
        }
        else if ( !IsRectEmpty(lprc: &data->m_rect) )
        {
          v11 = CMFCVisualManager::GetInstance();
          v11->OnDrawTasksGroupCaption(
            this: v11,
            a2: v26,
            a3: data,
            a4: this->m_pHotGroupCaption == data,
            a5: 0,
            a6: this->m_bCanCollapse);
        }
      }
      if ( pNext == nullptr )
        break;
      m_pNodeHead = pNext;
    }
  }
  CGdiObject::DeleteObject(this: (CGdiObject *)&m_rectTasks.right);
  if ( this->m_bUseNavigationToolbar != 0 )
  {
    InvalidateRect(hWnd: this->m_wndToolBar.m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_wndToolBar.m_hWnd);
  }
  if ( this->m_bUseScrollButtons != 0 )
  {
    if ( this->m_nVertScrollOffset > 0 )
    {
      v19 = CMFCVisualManager::GetInstance();
      v19->OnDrawScrollButtons(this: v19, a2: v26, a3: &this->m_rectScrollUp, a4: 1, a5: 7, a6: this->m_iScrollMode < 0);
    }
    if ( CMFCTasksPane::IsScrollDnAvailable(this) != 0 )
    {
      v20 = CMFCVisualManager::GetInstance();
      v20->OnDrawScrollButtons(this: v20, a2: v26, a3: &this->m_rectScrollDn, a4: 1, a5: 0, a6: this->m_iScrollMode > 0);
    }
  }
  v28 = -1;
  m_rectTasks.right = (int)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: (CGdiObject *)&m_rectTasks.right);
}

//------------------------------------------------------------------------------
// Address: 0x10432BF3
// Name: protected: void CMFCTasksPane::UpdateCaption(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::UpdateCaption(CMFCTasksPane *this)
{
  int ActivePage; // eax
  __POSITION *Index; // eax
  int m_nCount; // ebx
  int v5; // edi
  CPaneFrameWnd *v6; // eax

  ActivePage = CMFCTasksPane::GetActivePage(this);
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes, nIndex: ActivePage);
  if ( Index == nullptr )
    AfxThrowInvalidArgException();
  m_nCount = this->m_lstTasksPanes.m_nCount;
  v5 = *(_DWORD *)&Index[8];
  if ( this->m_bUseNavigationToolbar != 0 || CMFCTasksPane::ForceShowNavToolbar(this) != 0 || m_nCount > 1 )
    CWnd::SetWindowTextA(this, lpszString: this->m_strCaption.m_pszData);
  else
    CWnd::SetWindowTextA(this, lpszString: *(const char **)(v5 + 4));
  CMFCTasksPaneToolBar::UpdateMenuButtonText(this: &this->m_wndToolBar, str: (ATL::CStringData *)(v5 + 4));
  v6 = this->GetParentMiniFrame(this, a2: 1);
  if ( v6 != nullptr )
    CWnd::SetWindowPos(this: v6, pWndInsertAfter: nullptr, x: -1, y: -1, cx: -1, cy: -1, nFlags: 0x37u);
  else
    this->SetWindowPos(this, a2: nullptr, a3: -1, a4: -1, a5: -1, a6: -1, a7: 55u, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10432C92
// Name: public: virtual void CMFCTasksPane::Update(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::Update(CMFCTasksPane *this)
{
  CMFCTasksPane::UpdateCaption(this);
  CMFCTasksPane::AdjustScroll(this);
  this->ReposTasks(this, a2: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x10432CC3
// Name: public: CMFCTasksPanePropertyPage::CMFCTasksPanePropertyPage(char const __near *,class CMFCTasksPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPanePropertyPage *__thiscall CMFCTasksPanePropertyPage::CMFCTasksPanePropertyPage(
        CMFCTasksPanePropertyPage *this,
        const char *lpszName,
        CMFCTasksPane *pTaskPane)
{
  CAfxStringMgr *StringManager; // eax

  this->__vftable = (CMFCTasksPanePropertyPage_vtbl *)&CMFCTasksPanePropertyPage::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strName, pStringMgr: StringManager);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strName, pszSrc: lpszName);
  this->m_pTaskPane = pTaskPane;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10432D07
// Name: public: virtual CMFCTasksPanePropertyPage::~CMFCTasksPanePropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPanePropertyPage::~CMFCTasksPanePropertyPage(CMFCTasksPanePropertyPage *this)
{
  this->m_pTaskPane = nullptr;
  this->__vftable = (CMFCTasksPanePropertyPage_vtbl *)&CMFCTasksPanePropertyPage::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10432D3D
// Name: public: CTasksPaneHistoryButton::CTasksPaneHistoryButton(unsigned int,int,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTasksPaneHistoryButton *__thiscall CTasksPaneHistoryButton::CTasksPaneHistoryButton(
        CTasksPaneHistoryButton *this,
        unsigned int uiID,
        int iImage,
        const char *lpszText,
        int bUserButton)
{
  const char *v6; // eax
  HMENU PopupMenu; // eax
  CMenu menu; // [esp+10h] [ebp-18h] BYREF
  CTasksPaneHistoryButton *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v10 = this;
  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this);
  v11 = 0;
  this->__vftable = (CTasksPaneHistoryButton_vtbl *)&CTasksPaneHistoryButton::`vftable';
  CStringList::CStringList(this: &this->m_lstPages, nBlockSize: 10);
  this->m_nID = uiID;
  LOBYTE(v11) = 1;
  this->m_bUserButton = bUserButton;
  CMFCToolBarButton::SetImage(this, iImage);
  v6 = lpszText;
  if ( lpszText == nullptr )
    v6 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strText, pszSrc: v6);
  menu.m_hMenu = nullptr;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  LOBYTE(v11) = 2;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  CMFCToolBarMenuButton::CreateFromMenu(this, hMenu: menu.m_hMenu);
  this->m_pParentBar = nullptr;
  LOBYTE(v11) = 1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10432DE2
// Name: public: static class CObject __near * CMFCTasksPane::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPane *__stdcall CMFCTasksPane::CreateObject()
{
  CMFCTasksPane *v0; // ecx
  CMFCTasksPane *result; // eax

  v0 = (CMFCTasksPane *)operator new(nSize: 0x11F4u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCTasksPane::CMFCTasksPane(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10432E33
// Name: public: int CMFCTasksPane::AddPage(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::AddPage(CMFCTasksPane *this, const char *lpszPageLabel)
{
  CMFCTasksPanePropertyPage *v3; // ecx
  CMFCTasksPanePropertyPage *v4; // eax

  if ( lpszPageLabel == nullptr )
    AfxThrowInvalidArgException();
  v3 = (CMFCTasksPanePropertyPage *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = CMFCTasksPanePropertyPage::CMFCTasksPanePropertyPage(this: v3, lpszName: lpszPageLabel, pTaskPane: this);
  else
    v4 = nullptr;
  CPtrList::AddTail(this: &this->m_lstTasksPanes, newElement: v4);
  CMFCTasksPane::RebuildMenu(this);
  return this->m_lstTasksPanes.m_nCount - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10432E9A
// Name: protected: virtual int CMFCTasksPane::GetMRUFileName(class CRecentFileList __near *,int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::GetMRUFileName(
        CMFCTasksPane *this,
        CRecentFileList *pRecentFileList,
        int nIndex,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strName)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax
  CHAR lpcszBuffer[516]; // [esp+Ch] [ebp-208h] BYREF

  if ( pRecentFileList == nullptr )
    AfxThrowInvalidArgException();
  if ( *((_DWORD *)CRecentFileList::operator[](this: pRecentFileList, nIndex)->m_pszData - 3) == 0 )
    return 0;
  memset(dst: (unsigned __int8 *)lpcszBuffer, value: 0, count: 0x200u);
  v4 = CRecentFileList::operator[](this: pRecentFileList, nIndex);
  if ( GetFileTitleA(a1: v4->m_pszData, Buf: lpcszBuffer, cchSize: 0x200u) != 0 )
    return 0;
  ATL::CSimpleStringT<char,0>::SetString(this: strName, pszSrc: lpcszBuffer);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10432F39
// Name: protected: void CMFCTasksPane::ChangeActivePage(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCTasksPane::ChangeActivePage(
        CMFCTasksPane *this@<ecx>,
        int a2@<ebx>,
        CMFCTasksPanePropertyPage *nNewPageHistoryIdx,
        int nOldPageHistoryIdx)
{
  int m_nSize; // eax
  int *m_pData; // edi
  int v7; // ecx
  __POSITION *Index; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObject *data; // eax
  CObject_vtbl *v11; // edi
  HWND__ *v12; // eax
  CWnd *v13; // eax
  CMFCTasksPanePropertyPage *pOldPage; // [esp+10h] [ebp+8h]

  if ( (int)nNewPageHistoryIdx < 0 )
    goto LABEL_10;
  m_nSize = this->m_arrHistoryStack.m_nSize;
  if ( (int)nNewPageHistoryIdx >= m_nSize || nOldPageHistoryIdx < 0 || nOldPageHistoryIdx >= m_nSize )
    goto LABEL_10;
  m_pData = this->m_arrHistoryStack.m_pData;
  v7 = m_pData[nOldPageHistoryIdx];
  if ( m_pData[(_DWORD)nNewPageHistoryIdx] == v7 )
    return;
  if ( this == nullptr || this->m_hWnd == nullptr )
  {
    this->OnActivateTasksPanePage(this);
    CMFCTasksPane::RebuildMenu(this);
    return;
  }
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes, nIndex: v7);
  if ( Index == nullptr )
LABEL_10:
    AfxThrowInvalidArgException();
  m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
  pOldPage = *(CMFCTasksPanePropertyPage **)&Index[8];
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( (CMFCTasksPanePropertyPage *)data[1].__vftable == pOldPage )
    {
      v11 = data[4].__vftable;
      while ( v11 != nullptr )
      {
        v12 = *((HWND__ **)v11->Serialize + 11);
        v11 = (CObject_vtbl *)v11->GetRuntimeClass;
        if ( v12 != nullptr )
        {
          v13 = CWnd::FromHandle(hWnd: v12);
          CWnd::ShowWindow(this: v13, nCmdShow: 0);
        }
      }
    }
  }
  CMFCTasksPane::UpdateCaption(this);
  ((void (__thiscall *)(CMFCTasksPane *, int))this->OnActivateTasksPanePage)(a1: this, a2);
  CMFCTasksPane::RebuildMenu(this);
  this->m_nVertScrollOffset = 0;
  CMFCTasksPane::AdjustScroll(this);
  ((void (__thiscall *)(CMFCTasksPane *))this->ReposTasks)(a1: this);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}
