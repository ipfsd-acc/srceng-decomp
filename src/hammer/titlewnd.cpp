// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/titlewnd.cpp
// Functions: 257
// ============================================================

#include "hammer\titlewnd.h"

//------------------------------------------------------------------------------
// Address: 0x100B7FF0
// Name: protected: CTitleWnd::CTitleWnd(void)
// Source: json
//------------------------------------------------------------------------------
CTitleWnd *__thiscall CTitleWnd::CTitleWnd(CTitleWnd *this)
{
  HFONT FontA; // eax
  HFONT v3; // eax

  CWnd::CWnd(this);
  this->__vftable = (CTitleWnd_vtbl *)&CTitleWnd::`vftable';
  if ( CTitleWnd::m_FontNormal.m_hObject == nullptr )
  {
    FontA = CreateFontA(
              cHeight: 16,
              cWidth: 0,
              cEscapement: 0,
              cOrientation: 0,
              cWeight: 400,
              bItalic: 0,
              bUnderline: 0,
              bStrikeOut: 0,
              iCharSet: 0,
              iOutPrecision: 0,
              iClipPrecision: 0,
              iQuality: 0,
              iPitchAndFamily: 0,
              pszFaceName: "MS Sans Serif");
    CGdiObject::Attach(this: &CTitleWnd::m_FontNormal, hObject: FontA);
    v3 = CreateFontA(
           cHeight: 16,
           cWidth: 0,
           cEscapement: 0,
           cOrientation: 0,
           cWeight: 700,
           bItalic: 0,
           bUnderline: 0,
           bStrikeOut: 0,
           iCharSet: 0,
           iOutPrecision: 0,
           iClipPrecision: 0,
           iQuality: 0,
           iPitchAndFamily: 0,
           pszFaceName: "MS Sans Serif");
    CGdiObject::Attach(this: &CTitleWnd::m_FontActive, hObject: v3);
  }
  *(_WORD *)&this->m_bMouseOver = 0;
  this->m_szTitle[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B80A0
// Name: public: void CTitleWnd::SetTitle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTitleWnd::SetTitle(CTitleWnd *this, const char *pszTitle)
{
  const char *v2; // eax
  int v4; // edx
  char v5; // cl
  HDC DC; // eax
  CDC *v7; // eax
  CDC *v8; // edi
  tagSIZE psizl; // [esp+4h] [ebp-8h] BYREF

  v2 = pszTitle;
  if ( pszTitle != nullptr )
  {
    v4 = this->m_szTitle - pszTitle;
    do
    {
      v5 = *v2;
      v2[v4] = *v2;
      ++v2;
    }
    while ( v5 != 0 );
    if ( IsWindow(hWnd: this->m_hWnd) )
    {
      DC = GetDC(hWnd: this->m_hWnd);
      v7 = CDC::FromHandle(hDC: DC);
      v8 = v7;
      if ( v7 != nullptr )
      {
        v7->SelectObject(this: v7, a2: &CTitleWnd::m_FontActive);
        GetTextExtentPoint32A(hdc: v8->m_hAttribDC, lpString: this->m_szTitle, c: strlen(this->m_szTitle), &psizl);
        CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: psizl.cx, cy: psizl.cy, nFlags: 6u);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_hWnd);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8160
// Name: protected: long CTitleWnd::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTitleWnd::OnMouseLeave(CTitleWnd *this, unsigned int wParam, unsigned int lParam)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-10h]

  m_hWnd = this->m_hWnd;
  this->m_bMouseOver = false;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B8190
// Name: protected: void CTitleWnd::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTitleWnd::OnMouseMove(CTitleWnd *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v5; // [esp-Ch] [ebp-20h]
  tagTRACKMOUSEEVENT Track; // [esp+4h] [ebp-10h] BYREF

  if ( !this->m_bMouseOver )
  {
    m_hWnd = this->m_hWnd;
    Track.cbSize = 16;
    Track.dwFlags = 3;
    Track.hwndTrack = m_hWnd;
    Track.dwHoverTime = 0;
    _TrackMouseEvent(lpEventTrack: &Track);
    v5 = this->m_hWnd;
    this->m_bMouseOver = true;
    InvalidateRect(hWnd: v5, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B81F0
// Name: protected: void CTitleWnd::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTitleWnd::OnPaint(CTitleWnd *this)
{
  char *m_szTitle; // edi
  CFont *v3; // eax
  CFont *v4; // esi
  COLORREF v5; // [esp-4h] [ebp-6Ch]
  CPaintDC dc; // [esp+8h] [ebp-60h] BYREF
  int v7; // [esp+64h] [ebp-4h]

  m_szTitle = this->m_szTitle;
  if ( this->m_szTitle[0] != 0 && GetUpdateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true) )
  {
    CPaintDC::CPaintDC(this: &dc, pWnd: this);
    v7 = 0;
    if ( this->m_bMouseOver || this->m_bMenuOpen )
    {
      v3 = CDC::SelectObject(this: &dc, pFont: &CTitleWnd::m_FontActive);
      v5 = 0xFFFFFF;
    }
    else
    {
      v3 = CDC::SelectObject(this: &dc, pFont: &CTitleWnd::m_FontNormal);
      v5 = 13158600;
    }
    v4 = v3;
    CDC::SetTextColor(this: &dc, crColor: v5);
    CDC::SetBkMode(this: &dc, nBkMode: 1);
    TextOutA(hdc: dc.m_hDC, x: 0, y: 0, lpString: m_szTitle, c: strlen(m_szTitle));
    CDC::SelectObject(this: &dc, pFont: v4);
    v7 = -1;
    CPaintDC::~CPaintDC(this: &dc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B82E0
// Name: protected: void CTitleWnd::OnMouseButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTitleWnd::OnMouseButton(CTitleWnd *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  CMenu *v5; // eax
  CMenu *v6; // edi
  CMainFrame *MainWnd; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  HWND__ *v9; // [esp-8h] [ebp-38h]
  CRect rect; // [esp+Ch] [ebp-24h] BYREF
  CPoint MenuLocation; // [esp+1Ch] [ebp-14h] BYREF
  int v12; // [esp+2Ch] [ebp-4h]

  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    Menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    Menu.m_hMenu = nullptr;
    atexit(func: CTitleWnd::OnMouseButton_::_2_::_dynamic_atexit_destructor_for__Menu__);
    v12 = -1;
  }
  if ( bFirstTime != 0 )
  {
    ModuleState = AfxGetModuleState();
    MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
    CMenu::Attach(this: &Menu, hMenu: MenuW);
    bFirstTime = 0;
  }
  SubMenu = GetSubMenu(hMenu: Menu.m_hMenu, nPos: 5);
  v5 = CMenu::FromHandle(hMenu: SubMenu);
  m_hWnd = this->m_hWnd;
  v6 = v5;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  v9 = this->m_hWnd;
  MenuLocation.x = 0;
  MenuLocation.y = rect.bottom;
  ClientToScreen(hWnd: v9, lpPoint: &MenuLocation);
  this->m_bMenuOpen = true;
  MainWnd = GetMainWnd();
  CMenu::TrackPopupMenu(this: v6, nFlags: 2u, x: MenuLocation.x, y: MenuLocation.y, pWnd: MainWnd, lpRect: nullptr);
  this->m_bMenuOpen = false;
}

//------------------------------------------------------------------------------
// Address: 0x100B83F0
// Name: protected: void CTitleWnd::OnRButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTitleWnd::OnRButtonDown(CTitleWnd *this, unsigned int nFlags, CPoint point)
{
  CTitleWnd::OnMouseButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8400
// Name: protected: virtual struct AFX_MSGMAP const __near * CTitleWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTitleWnd::GetMessageMap(CTitleWnd *this)
{
  return (const AFX_MSGMAP *)&off_105E78D4;
}

//------------------------------------------------------------------------------
// Address: 0x100B8410
// Name: public: static class CTitleWnd __near * CTitleWnd::CreateTitleWnd(class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CTitleWnd *__cdecl CTitleWnd::CreateTitleWnd(CWnd *pwndParent, unsigned int uID)
{
  CAfxStringMgr *StringManager; // eax
  HCURSOR CursorA; // esi
  HBRUSH__ *StockObject; // eax
  const char *v5; // eax
  int v6; // ecx
  CTitleWnd *v7; // eax
  CTitleWnd *v8; // esi
  int (__thiscall *Create)(struct CTitleWnd *, const char *, const char *, unsigned int, const tagRECT *, CWnd *, unsigned int, CCreateContext *); // edx
  void *v11[5]; // [esp+8h] [ebp-20h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  if ( (_S1_12 & 1) == 0 )
  {
    _S1_12 |= 1u;
    v12 = 0;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    strTitleWndClass.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    atexit(func: CTitleWnd::CreateTitleWnd_::_2_::_dynamic_atexit_destructor_for__strTitleWndClass__);
    v12 = -1;
  }
  if ( *((_DWORD *)strTitleWndClass.m_pszData - 3) == 0 )
  {
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    StockObject = (HBRUSH__ *)GetStockObject(i: 4);
    v5 = AfxRegisterWndClass(nClassStyle: 0x1000u, hCursor: CursorA, hbrBackground: StockObject, hIcon: nullptr);
    if ( v5 != nullptr )
      v6 = strlen(v5);
    else
      v6 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &strTitleWndClass, pszSrc: v5, nLength: v6);
  }
  v7 = (CTitleWnd *)operator new(nSize: 0x178u);
  v11[4] = v7;
  v12 = 2;
  if ( v7 != nullptr )
    v8 = CTitleWnd::CTitleWnd(this: v7);
  else
    v8 = nullptr;
  v12 = -1;
  if ( v8 != nullptr )
  {
    Create = v8->Create;
    v11[2] = (void *)5;
    v11[3] = (void *)5;
    v11[0] = nullptr;
    v11[1] = nullptr;
    Create(
      this: v8,
      a2: strTitleWndClass.m_pszData,
      a3: "Title Window",
      a4: 1342177280u,
      a5: (const tagRECT *)v11,
      a6: pwndParent,
      a7: uID,
      a8: nullptr);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x103AFB9F
// Name: protected: long CMFCToolBar::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnMouseLeave(CMFCToolBar *this, unsigned int __formal, int a3)
{
  HWND Focus; // eax
  BOOL v5; // edi
  HWND Parent; // eax
  CWnd *v7; // ecx
  HWND v8; // eax
  int m_iHighlighted; // edi
  CMFCToolBar_vtbl *v10; // eax
  CMFCToolBarButton *v11; // edi
  CWnd *Owner; // eax
  CWnd *pImmediateParent; // [esp+8h] [ebp-8h]
  CMFCToolBar *pFocusWnd; // [esp+Ch] [ebp-4h]

  if ( CMFCToolBar::m_hookMouseHelp == nullptr
    && (this->m_bMenuMode == 0
     || CMFCToolBar::m_bCustomizeMode != 0
     || CMFCToolBar::GetDroppedDownMenu(this, pIndex: nullptr) == nullptr) )
  {
    this->m_bTracked = 0;
    this->m_ptLastMouse.x = -1;
    this->m_ptLastMouse.y = -1;
    Focus = GetFocus();
    pFocusWnd = (CMFCToolBar *)CWnd::FromHandle(hWnd: Focus);
    v5 = pFocusWnd == this;
    Parent = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    pImmediateParent = v7;
    if ( v7 != nullptr && CObject::IsKindOf(this: v7, pClass: &CMFCTabCtrl::classCMFCTabCtrl) != 0 )
    {
      v5 = pImmediateParent == pFocusWnd;
      if ( pImmediateParent != pFocusWnd )
      {
        v8 = GetParent(hWnd: pImmediateParent->m_hWnd);
        v5 = pFocusWnd == CWnd::FromHandle(hWnd: v8);
      }
    }
    if ( this->m_iHighlighted >= 0 )
    {
      if ( !v5 && this->AlwaysSaveSelection(this) == 0 )
      {
        m_iHighlighted = this->m_iHighlighted;
        v10 = this->__vftable;
        this->m_iHighlighted = -1;
        v10->OnChangeHot(this, a2: -1);
        v11 = CMFCToolBar::InvalidateButton(this, nIndex: m_iHighlighted);
        UpdateWindow(hWnd: this->m_hWnd);
        if ( v11 == nullptr || v11->IsDroppedDown(this: v11) == 0 )
        {
          Owner = CWnd::GetOwner(this);
          SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
        }
      }
    }
    else
    {
      this->ShowCommandMessageString(this, a2: -1u);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103CB383
// Name: protected: long CMFCRibbonRichEditCtrl::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonRichEditCtrl::OnMouseLeave(
        CMFCRibbonRichEditCtrl *this,
        unsigned int __formal,
        unsigned int __formala)
{
  CWnd *v4; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-18h]

  if ( this->m_edit->GetParentWnd(this: this->m_edit) != nullptr )
  {
    v4 = this->m_edit->GetParentWnd(this: this->m_edit);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0x2A3u, wParam: 0, lParam: 0);
  }
  if ( this->m_bIsHighlighted != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_bIsHighlighted = 0;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  this->m_bTracked = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103CF54D
// Name: protected: long CMFCCaptionBar::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCCaptionBar::OnMouseLeave(CMFCCaptionBar *this, unsigned int __formal, unsigned int __formala)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-18h]
  HWND__ *v6; // [esp-Ch] [ebp-18h]

  this->m_bTracked = 0;
  if ( this->m_bIsBtnPressed != 0 || this->m_bIsBtnHighlighted != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_bIsBtnPressed = 0;
    this->m_bIsBtnHighlighted = 0;
    InvalidateRect(hWnd: m_hWnd, lpRect: &this->m_rectButton, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  if ( this->m_bIsCloseBtnPressed != 0 || this->m_bIsCloseBtnHighlighted != 0 )
  {
    v6 = this->m_hWnd;
    this->m_bIsCloseBtnPressed = 0;
    this->m_bIsCloseBtnHighlighted = 0;
    InvalidateRect(hWnd: v6, lpRect: &this->m_rectClose, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F6EF2
// Name: protected: long CMFCAutoHideBar::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCAutoHideBar::OnMouseLeave(CMFCAutoHideBar *this, unsigned int __formal, unsigned int __formala)
{
  CMFCAutoHideButton *m_pHighlightedButton; // ecx
  HWND__ *m_hWnd; // [esp-4h] [ebp-Ch]

  m_pHighlightedButton = this->m_pHighlightedButton;
  if ( m_pHighlightedButton != nullptr )
  {
    m_pHighlightedButton->HighlightButton(this: m_pHighlightedButton, a2: 0);
    m_hWnd = this->m_hWnd;
    this->m_pHighlightedButton = nullptr;
    UpdateWindow(hWnd: m_hWnd);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
  this->m_bTracked = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104094B5
// Name: protected: long CMFCColorBar::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::OnMouseLeave(CMFCColorBar *this, unsigned int wp, int lp)
{
  int m_iHighlighted; // edi
  CMFCColorBar_vtbl *v6; // eax
  CWnd *Owner; // eax
  CMFCRibbonColorButton *m_pParentRibbonBtn; // ecx

  if ( this->m_pParentBtn == nullptr && this->m_pWndPropList == nullptr )
    return CMFCToolBar::OnMouseLeave(this, __formal: wp, a3: lp);
  if ( CMFCToolBar::m_hookMouseHelp == nullptr
    && (this->m_bMenuMode == 0
     || CMFCToolBar::m_bCustomizeMode != 0
     || CMFCToolBar::GetDroppedDownMenu(this, pIndex: nullptr) == nullptr) )
  {
    m_iHighlighted = this->m_iHighlighted;
    this->m_bTracked = 0;
    this->m_ptLastMouse.x = -1;
    this->m_ptLastMouse.y = -1;
    if ( m_iHighlighted >= 0 )
    {
      v6 = this->__vftable;
      this->m_iHighlighted = -1;
      v6->OnChangeHot(this, a2: -1);
      CMFCToolBar::InvalidateButton(this, nIndex: m_iHighlighted);
      UpdateWindow(hWnd: this->m_hWnd);
      Owner = CWnd::GetOwner(this);
      SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
      m_pParentRibbonBtn = this->m_pParentRibbonBtn;
      if ( m_pParentRibbonBtn != nullptr )
        m_pParentRibbonBtn->NotifyHighlightListItem(this: m_pParentRibbonBtn, a2: -1);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040C39D
// Name: protected: long CMFCSpinButtonCtrl::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCSpinButtonCtrl::OnMouseLeave(
        CMFCSpinButtonCtrl *this,
        unsigned int __formal,
        unsigned int __formala)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-10h]

  this->m_bTracked = 0;
  if ( this->m_bIsButtonPressedUp != 0
    || this->m_bIsButtonPressedDown != 0
    || this->m_bIsButtonHighligtedUp != 0
    || this->m_bIsButtonHighligtedDown != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_bIsButtonHighligtedUp = 0;
    this->m_bIsButtonHighligtedDown = 0;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040CCA9
// Name: protected: long CMFCHeaderCtrl::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCHeaderCtrl::OnMouseLeave(CMFCHeaderCtrl *this, unsigned int __formal, unsigned int __formala)
{
  this->m_bTracked = 0;
  if ( this->m_nHighlightedItem >= 0 )
  {
    this->m_nHighlightedItem = -1;
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040DB9B
// Name: protected: long CMFCToolBarComboBoxEdit::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxEdit::OnMouseLeave(
        CMFCToolBarComboBoxEdit *this,
        unsigned int __formal,
        unsigned int __formala)
{
  HWND Focus; // eax

  this->m_bTracked = 0;
  Focus = GetFocus();
  if ( CWnd::FromHandle(hWnd: Focus) != this )
    CMFCToolBarComboBoxButton::SetHotEdit(this: this->m_combo, bHot: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10416EE0
// Name: protected: long CMFCRibbonPanelMenuBar::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::OnMouseLeave(CMFCRibbonPanelMenuBar *this, unsigned int __formal, int a3)
{
  CMFCRibbonPanel *m_pPanel; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CPoint point; // [esp+8h] [ebp-1Ch] BYREF
  CRect rectClient; // [esp+10h] [ebp-14h] BYREF

  point = 0;
  GetCursorPos(lpPoint: &point);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  if ( !PtInRect(lprc: &rectClient, pt: point.tagPOINT) )
  {
    CMFCRibbonPanelMenuBar::OnMouseMove(this, nFlags: 0, point: (CPoint)-1LL);
    m_pPanel = this->m_pPanel;
    this->m_bTracked = 0;
    if ( m_pPanel != nullptr )
      ((void (__thiscall *)(CMFCRibbonPanel *, _DWORD, int, int))m_pPanel->Highlight)(
        a1: m_pPanel,
        a2: 0,
        a3: -1,
        a4: -1);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
  }
  this->m_bTracked = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042E299
// Name: protected: long CMFCToolBarEditCtrl::OnMouseLeave(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarEditCtrl::OnMouseLeave(
        CMFCToolBarEditCtrl *this,
        unsigned int __formal,
        unsigned int __formala)
{
  HWND Focus; // eax

  this->m_bTracked = 0;
  Focus = GetFocus();
  if ( CWnd::FromHandle(hWnd: Focus) != this )
    CMFCToolBarEditBoxButton::SetHotEdit(this: this->m_buttonEdit, bHot: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x105C0C90
// Name: _dynamic_initializer_for__CTitleWnd::m_FontNormal__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTitleWnd::m_FontNormal__()
{
  CTitleWnd::m_FontNormal.__vftable = (CFont_vtbl *)&CFont::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__CTitleWnd::m_FontNormal__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0CE0
// Name: _dynamic_initializer_for__CTitleWnd::m_FontActive__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTitleWnd::m_FontActive__()
{
  CTitleWnd::m_FontActive.__vftable = (CFont_vtbl *)&CFont::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__CTitleWnd::m_FontActive__);
}

//------------------------------------------------------------------------------
// Address: 0x105CAEB0
// Name: _CTitleWnd::OnMouseButton_::_2_::_dynamic_atexit_destructor_for__Menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTitleWnd::OnMouseButton_::_2_::_dynamic_atexit_destructor_for__Menu__()
{
  Menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &Menu);
}

//------------------------------------------------------------------------------
// Address: 0x105CAED0
// Name: _CTitleWnd::CreateTitleWnd_::_2_::_dynamic_atexit_destructor_for__strTitleWndClass__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTitleWnd::CreateTitleWnd_::_2_::_dynamic_atexit_destructor_for__strTitleWndClass__()
{
  char *v0; // eax

  v0 = strTitleWndClass.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strTitleWndClass.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v0 + 4))(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x105CAF20
// Name: _dynamic_atexit_destructor_for__CTitleWnd::m_FontNormal__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTitleWnd::m_FontNormal__()
{
  CTitleWnd::m_FontNormal.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &CTitleWnd::m_FontNormal);
}

//------------------------------------------------------------------------------
// Address: 0x105CAF70
// Name: _dynamic_atexit_destructor_for__CTitleWnd::m_FontActive__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTitleWnd::m_FontActive__()
{
  CTitleWnd::m_FontActive.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &CTitleWnd::m_FontActive);
}

//------------------------------------------------------------------------------
// Address: 0x103AFCDD
// Name: protected: static long CMFCToolBar::ToolBarMouseHookProc(int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall CMFCToolBar::ToolBarMouseHookProc(int nCode, WPARAM wParam, CPoint *lParam)
{
  HWND v4; // eax
  CWnd *v5; // eax
  CMFCToolBar *v6; // edi
  int m_iHighlighted; // esi
  HWND Parent; // eax
  CWnd *v9; // eax
  CMFCPopupMenu *v10; // eax
  CMFCToolBar *ParentToolBar; // eax
  CMFCToolBar *v12; // ecx
  CPoint ptClient; // [esp+0h] [ebp-8h] BYREF

  if ( nCode != 0 )
    return CallNextHookEx(hhk: CMFCToolBar::m_hookMouseHelp, nCode, wParam, (LPARAM)lParam);
  if ( lParam == nullptr )
    AfxThrowInvalidArgException();
  if ( wParam == 512 )
  {
    v4 = WindowFromPoint(Point: lParam->tagPOINT);
    v5 = CWnd::FromHandle(hWnd: v4);
    v6 = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v5);
    if ( v6 != nullptr )
    {
      ptClient = *lParam;
      ScreenToClient(hWnd: v6->m_hWnd, lpPoint: &ptClient);
      CMFCToolBar::OnMouseMove(this: v6, nFlags: 0, point: ptClient);
    }
    if ( CMFCToolBar::m_pLastHookedToolbar == nullptr )
      goto LABEL_17;
    if ( CMFCToolBar::m_pLastHookedToolbar == v6 )
      goto LABEL_17;
    CMFCToolBar::m_pLastHookedToolbar->m_bTracked = 0;
    CMFCToolBar::m_pLastHookedToolbar->m_ptLastMouse.x = -1;
    CMFCToolBar::m_pLastHookedToolbar->m_ptLastMouse.y = -1;
    if ( CMFCToolBar::m_pLastHookedToolbar->m_iHighlighted < 0 )
      goto LABEL_17;
    m_iHighlighted = CMFCToolBar::m_pLastHookedToolbar->m_iHighlighted;
    CMFCToolBar::m_pLastHookedToolbar->m_iHighlighted = -1;
    if ( v6 != nullptr
      && (Parent = GetParent(hWnd: v6->m_hWnd),
          v9 = CWnd::FromHandle(hWnd: Parent),
          (v10 = (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v9)) != nullptr) )
    {
      ParentToolBar = (CMFCToolBar *)CMFCPopupMenu::GetParentToolBar(this: v10);
      v12 = CMFCToolBar::m_pLastHookedToolbar;
      if ( ParentToolBar == CMFCToolBar::m_pLastHookedToolbar )
      {
LABEL_17:
        CMFCToolBar::m_pLastHookedToolbar = v6;
        return 0;
      }
    }
    else
    {
      v12 = CMFCToolBar::m_pLastHookedToolbar;
    }
    v12->OnChangeHot(this: v12, a2: v12->m_iHighlighted);
    CMFCToolBar::InvalidateButton(this: CMFCToolBar::m_pLastHookedToolbar, nIndex: m_iHighlighted);
    UpdateWindow(hWnd: CMFCToolBar::m_pLastHookedToolbar->m_hWnd);
    goto LABEL_17;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103AFE2F
// Name: public: static void CMFCToolBar::SetHelpMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCToolBar::SetHelpMode(int bOn)
{
  DWORD CurrentThreadId; // eax
  CObList::CNode *m_pNodeHead; // esi
  CMFCToolBar *data; // edi

  if ( bOn != 0 )
  {
    if ( CMFCToolBar::m_hookMouseHelp == nullptr )
    {
      CurrentThreadId = GetCurrentThreadId();
      CMFCToolBar::m_hookMouseHelp = SetWindowsHookExA(
                                       idHook: 7,
                                       lpfn: (HOOKPROC)CMFCToolBar::ToolBarMouseHookProc,
                                       hmod: nullptr,
                                       dwThreadId: CurrentThreadId);
    }
  }
  else if ( CMFCToolBar::m_hookMouseHelp != nullptr )
  {
    UnhookWindowsHookEx(hhk: CMFCToolBar::m_hookMouseHelp);
    m_pNodeHead = afxAllToolBars.m_pNodeHead;
    CMFCToolBar::m_hookMouseHelp = nullptr;
    for ( CMFCToolBar::m_pLastHookedToolbar = nullptr; m_pNodeHead != nullptr; m_pNodeHead = m_pNodeHead->pNext )
    {
      data = (CMFCToolBar *)m_pNodeHead->data;
      if ( data == nullptr )
        AfxThrowInvalidArgException();
      if ( CWnd::FromHandlePermanent(hWnd: data->m_hWnd) != nullptr )
        CMFCToolBar::OnCancelMode(this: data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AFEB5
// Name: public: static void CMFCToolBar::AddBasicCommand(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCToolBar::AddBasicCommand(CFrameWnd *uiCmd)
{
  if ( CList<unsigned int,unsigned int>::Find(
         this: (CList<HWND__ *,HWND__ *> *)&CMFCToolBar::m_lstBasicCommands,
         searchValue: (HWND__ *)uiCmd,
         startAfter: nullptr) == nullptr )
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&CMFCToolBar::m_lstBasicCommands,
      newElement: uiCmd);
}

//------------------------------------------------------------------------------
// Address: 0x103AFEDF
// Name: public: virtual void CMFCToolBar::AdjustLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::AdjustLayout(CMFCToolBar *this)
{
  __int16 v2; // ax
  CObList::CNode *m_pNodeHead; // ecx
  BOOL v4; // eax
  BOOL v5; // edi
  CObject *data; // edx
  HWND Parent; // eax
  CWnd *v8; // eax
  CMFCReBar *v9; // ecx
  CReBarCtrl *ActiveFrame; // ebx
  LRESULT v11; // eax
  unsigned int v12; // ecx
  signed int v13; // [esp+4h] [ebp-84h] BYREF
  unsigned int uiReBarsCount; // [esp+8h] [ebp-80h]
  unsigned int uiBand; // [esp+Ch] [ebp-7Ch]
  tagREBARBANDINFOA bandInfo; // [esp+10h] [ebp-78h] BYREF
  CRect rect; // [esp+74h] [ebp-14h] BYREF

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    v2 = this->GetCurrentAlignment(this);
    m_pNodeHead = this->m_Buttons.m_pNodeHead;
    v4 = (v2 & 0xA000) != 0;
    while ( m_pNodeHead != nullptr )
    {
      v5 = false;
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data == nullptr )
        break;
      if ( ((int)data[9].__vftable & 1) == 0 && this->m_bTextLabels != 0 )
        v5 = v4;
      data[6].__vftable = (CObject_vtbl *)v5;
    }
    Parent = GetParent(hWnd: this->m_hWnd);
    v8 = CWnd::FromHandle(hWnd: Parent);
    v9 = (CMFCReBar *)AfxDynamicDownCast(pClass: &CMFCReBar::classCMFCReBar, pObject: v8);
    uiBand = (unsigned int)v9;
    if ( v9 != nullptr )
    {
      ActiveFrame = CFrameWnd::GetActiveFrame(this: v9);
      v11 = SendMessageA(hWnd: ActiveFrame->m_hWnd, Msg: 0x40Cu, wParam: 0, lParam: 0);
      v12 = *(_DWORD *)(uiBand + 684);
      uiBand = 0;
      uiReBarsCount = v11;
      bandInfo.cbSize = v12;
      for ( bandInfo.fMask = 560; uiBand < uiReBarsCount; ++uiBand )
      {
        SendMessageA(hWnd: ActiveFrame->m_hWnd, Msg: 0x41Du, wParam: uiBand, lParam: (LPARAM)&bandInfo);
        if ( bandInfo.hwndChild == this->m_hWnd )
          break;
      }
      bandInfo.fMask ^= 0x10u;
      if ( uiBand < uiReBarsCount )
      {
        this->m_nMaxBtnHeight = this->CalcMaxButtonHeight(this);
        this->CalcSize(this, result: (CSize *)&v13, a3: 0);
        memset(&rect, 0, sizeof(rect));
        SetRectEmpty(lprc: &rect);
        CPane::CalcInsideRect(this, &rect, bHorz: 1);
        uiReBarsCount += rect.top - rect.bottom;
        v13 += rect.left - rect.right;
        if ( v13 <= 0 )
          v13 = 0;
        if ( (int)uiReBarsCount <= 0 )
          uiReBarsCount = 0;
        bandInfo.cxMinChild = CMFCToolBar::m_sizeButton.cx;
        bandInfo.cyMinChild = uiReBarsCount;
        bandInfo.cxIdeal = v13;
        SendMessageA(hWnd: ActiveFrame->m_hWnd, Msg: 0x406u, wParam: uiBand, lParam: (LPARAM)&bandInfo);
      }
    }
    else
    {
      CMFCToolBar::AdjustSize(this);
    }
    this->AdjustLocations(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B00C1
// Name: public: int CMFCToolBar::ProcessCommand(class CMFCToolBarButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::ProcessCommand(CMFCToolBar *this, CMFCToolBarButton *pButton)
{
  unsigned int m_nID; // eax
  WPARAM v4; // esi
  CWnd *Owner; // eax

  m_nID = pButton->m_nID;
  if ( m_nID == 0 || m_nID == -1 )
    return 0;
  AFXPlaySystemSound(nSound: 1);
  CMFCCmdUsageCount::AddCmd(this: &CMFCToolBar::m_UsageCount, uiCmd: pButton->m_nID);
  v4 = pButton->m_nID;
  Owner = CWnd::GetOwner(this);
  PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: v4, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CB3D7
// Name: public: virtual void CMFCRibbonEdit::OnAfterChangeRect(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonEdit::OnAfterChangeRect(CMFCRibbonEdit *this, CDC *pDC)
{
  CMFCRibbonButton::OnAfterChangeRect(this, pDC);
  CMFCRibbonEdit::RepositionRibbonEditCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CB3F3
// Name: public: virtual int CMFCRibbonEdit::IsHighlighted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::IsHighlighted(CMFCRibbonEdit *this)
{
  int result; // eax

  result = 0;
  if ( this->m_bIsHighlighted != 0 || this->m_bIsEditFocused != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CB406
// Name: public: virtual int CMFCRibbonEdit::HasFocus(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::HasFocus(CMFCRibbonEdit *this)
{
  return this->m_bIsEditFocused;
}

//------------------------------------------------------------------------------
// Address: 0x103CB40D
// Name: public: virtual int CMFCRibbonEdit::HasSpinButtons(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::HasSpinButtons(CMFCRibbonEdit *this)
{
  return this->m_bHasSpinButtons;
}

//------------------------------------------------------------------------------
// Address: 0x103CB414
// Name: public: virtual int CMFCRibbonEdit::GetRangeMin(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::GetRangeMin(CMFCRibbonEdit *this)
{
  return this->m_nMin;
}

//------------------------------------------------------------------------------
// Address: 0x103CB41B
// Name: public: virtual int CMFCRibbonEdit::GetRangeMax(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::GetRangeMax(CMFCRibbonEdit *this)
{
  return this->m_nMax;
}

//------------------------------------------------------------------------------
// Address: 0x103CB422
// Name: protected: CMFCRibbonEdit::CMFCRibbonEdit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonEdit *__thiscall CMFCRibbonEdit::CMFCRibbonEdit(CMFCRibbonEdit *this)
{
  CAfxStringMgr *StringManager; // eax

  CMFCRibbonButton::CMFCRibbonButton(this);
  this->__vftable = (CMFCRibbonEdit_vtbl *)&CMFCRibbonEdit::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strEdit, pStringMgr: StringManager);
  CMFCRibbonEdit::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CB44E
// Name: public: virtual CMFCRibbonEdit::~CMFCRibbonEdit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonEdit::~CMFCRibbonEdit(CMFCRibbonEdit *this)
{
  this->__vftable = (CMFCRibbonEdit_vtbl *)&CMFCRibbonEdit::`vftable';
  CMFCRibbonEdit::DestroyCtrl(this);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strEdit.m_pszData - 1);
  CMFCRibbonButton::~CMFCRibbonButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CB490
// Name: public: virtual void CMFCRibbonEdit::OnDrawOnList(class CDC __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonEdit::OnDrawOnList(
        CMFCRibbonEdit *this,
        CDC *pDC,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText,
        int nTextOffset,
        CRect rect,
        int __formal,
        int a7)
{
  int m_bIsDisabled; // eax
  int v9; // eax
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager *v11; // eax
  int v12; // eax
  CMFCVisualManager *v13; // eax
  CDC *v14; // esi
  CFont *v15; // edi
  int v16; // eax
  int left; // [esp+10h] [ebp-17Ch]
  int top; // [esp+14h] [ebp-178h]
  int right; // [esp+18h] [ebp-174h]
  int bottom; // [esp+1Ch] [ebp-170h]
  int v21; // [esp+20h] [ebp-16Ch]
  int v22; // [esp+24h] [ebp-168h]
  int v23; // [esp+28h] [ebp-164h]
  int v24; // [esp+2Ch] [ebp-160h]
  int v25; // [esp+30h] [ebp-15Ch] BYREF
  int v26; // [esp+34h] [ebp-158h]
  int v27; // [esp+38h] [ebp-154h]
  CPoint result; // [esp+3Ch] [ebp-150h] BYREF
  CDC *v29; // [esp+44h] [ebp-148h]
  CMFCToolBarComboBoxButton v30; // [esp+48h] [ebp-144h] BYREF
  tagRECT v31; // [esp+13Ch] [ebp-50h] BYREF
  tagRECT v32; // [esp+14Ch] [ebp-40h] BYREF
  tagRECT rc; // [esp+15Ch] [ebp-30h] BYREF
  tagRECT v34; // [esp+16Ch] [ebp-20h] BYREF
  int v35; // [esp+188h] [ebp-4h]

  v29 = pDC;
  v35 = 0;
  rc.left = rect.left;
  rc.top = rect.top;
  result.y = 2 * (rect.bottom - rect.top);
  m_bIsDisabled = this->m_bIsDisabled;
  this->m_bIsDisabled = 0;
  v27 = m_bIsDisabled;
  rc.bottom = rect.bottom;
  rc.right = nTextOffset + rect.left;
  this->GetImageSize(this, result: (CSize *)&v25, a3: RibbonImageSmall);
  if ( v25 != 0 || v26 != 0 )
  {
    InflateRect(lprc: &rc, dx: -1, dy: 0);
    v9 = (rc.bottom - rc.top - v26) / 2;
    if ( v9 < 0 )
      v9 = 0;
    rc.top += v9;
    rc.bottom = v26 + rc.top;
    ((void (__thiscall *)(CMFCRibbonEdit *, CDC *, int, int, int, int, int))this->DrawImage)(
      a1: this,
      a2: v29,
      a3: 1,
      a4: rc.left,
      a5: rc.top,
      a6: rc.right,
      a7: v26 + rc.top);
  }
  v32.top = rect.top;
  v32.right = rect.right;
  v32.bottom = rect.bottom;
  v32.left = rect.right - result.y;
  InflateRect(lprc: &v32, dx: -1, dy: -1);
  v31.top = rect.top;
  v31.bottom = rect.bottom;
  v31.left = nTextOffset + rect.left;
  v31.right = v32.left;
  InflateRect(lprc: &v31, dx: -3, dy: 0);
  v29->DrawTextA(this: v29, a2: strText.m_pszData, a3: *((_DWORD *)strText.m_pszData - 3), a4: &v31, a5: 2084u);
  left = this->m_rect.left;
  top = this->m_rect.top;
  right = this->m_rect.right;
  bottom = this->m_rect.bottom;
  v21 = this->m_rectCommand.left;
  v22 = this->m_rectCommand.top;
  v23 = this->m_rectCommand.right;
  v24 = this->m_rectCommand.bottom;
  this->m_rect = (CRect)v32;
  this->m_rectCommand = (CRect)v32;
  this->m_rectCommand.right -= 15;
  Instance = CMFCVisualManager::GetInstance();
  Instance->OnFillRibbonButton(this: Instance, a2: v29, a3: this);
  v11 = CMFCVisualManager::GetInstance();
  v11->OnDrawRibbonButtonBorder(this: v11, a2: v29, a3: this);
  if ( this->m_bHasDropDownList != 0 )
  {
    CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton(this: &v30);
    v12 = this->m_rectCommand.right;
    v34.top = v32.top;
    v34.right = v32.right;
    v34.bottom = v32.bottom;
    v34.left = v12;
    LOBYTE(v35) = 1;
    InflateRect(lprc: &v34, dx: -2, dy: -2);
    v13 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD, _DWORD, _DWORD, CMFCToolBarComboBoxButton *))v13->OnDrawComboDropButton)(
      a1: v13,
      a2: v29,
      a3: v34.left,
      a4: v34.top,
      a5: v34.right,
      a6: v34.bottom,
      a7: 0,
      a8: 0,
      a9: 0,
      a10: &v30);
    LOBYTE(v35) = 0;
    CMFCToolBarComboBoxButton::~CMFCToolBarComboBoxButton(this: &v30);
  }
  else
  {
    v34 = v32;
    InflateRect(lprc: &v34, dx: -3, dy: -3);
    v14 = v29;
    --v34.bottom;
    v34.right = v34.left + 7;
    v15 = (CFont *)v29->SelectStockObject(this: v29, a2: 7);
    CDC::MoveTo(this: v14, &result, x: v34.left, y: v34.top);
    CDC::LineTo(this: v14, x: v34.right, y: v34.top);
    CDC::MoveTo(this: v14, &result, x: (v34.right + v34.left) / 2, y: v34.top);
    CDC::LineTo(this: v14, x: (v34.right + v34.left) / 2, y: v34.bottom);
    CDC::MoveTo(this: v14, &result, x: v34.left, y: v34.bottom);
    CDC::LineTo(this: v14, x: v34.right, y: v34.bottom);
    CDC::SelectObject(this: v14, pFont: v15);
  }
  this->m_rect.left = left;
  this->m_rect.top = top;
  v16 = v27;
  this->m_rect.right = right;
  this->m_rect.bottom = bottom;
  this->m_rectCommand.left = v21;
  this->m_rectCommand.top = v22;
  this->m_rectCommand.right = v23;
  this->m_rectCommand.bottom = v24;
  this->m_bIsDisabled = v16;
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103CB778
// Name: public: virtual int CMFCRibbonEdit::OnKey(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::OnKey(CMFCRibbonEdit *this, int bIsMenuKey)
{
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  CMFCRibbonRichEditCtrl *m_pWndEdit; // ecx

  if ( this->m_bIsDisabled != 0 )
    return 0;
  if ( IsRectEmpty(lprc: &this->m_rect) )
    return CMFCRibbonBaseElement::OnKey(this, bIsMenuKey);
  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( TopLevelRibbonBar != nullptr )
    CMFCRibbonBar::HideKeyTips(this: TopLevelRibbonBar);
  if ( bIsMenuKey == 0 && (m_pWndEdit = this->m_pWndEdit) != nullptr && m_pWndEdit->m_hWnd != nullptr )
  {
    CWnd::SetFocus(this: m_pWndEdit);
    if ( *((_DWORD *)this->m_strEdit.m_pszData - 3) != 0 )
      CRichEditCtrl::SetSel(this: this->m_pWndEdit, nStartChar: 0, nEndChar: -1);
  }
  else
  {
    this->DropDownList(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CB7FD
// Name: public: CMFCRibbonRichEditCtrl::CMFCRibbonRichEditCtrl(class CMFCRibbonEdit __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonRichEditCtrl *__thiscall CMFCRibbonRichEditCtrl::CMFCRibbonRichEditCtrl(
        CMFCRibbonRichEditCtrl *this,
        CMFCRibbonEdit *edit)
{
  CAfxStringMgr *StringManager; // eax

  CWnd::CWnd(this);
  this->__vftable = (CMFCRibbonRichEditCtrl_vtbl *)&CMFCRibbonRichEditCtrl::`vftable';
  this->m_edit = edit;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strOldText, pStringMgr: StringManager);
  this->m_bTracked = 0;
  this->m_bIsHighlighted = 0;
  this->m_bIsContextMenu = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CB83C
// Name: public: virtual CMFCRibbonRichEditCtrl::~CMFCRibbonRichEditCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonRichEditCtrl::~CMFCRibbonRichEditCtrl(CMFCRibbonRichEditCtrl *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strOldText.m_pszData - 16);
  this->__vftable = (CMFCRibbonRichEditCtrl_vtbl *)&CMFCRibbonRichEditCtrl::`vftable';
  ATL::CStringData::Release(this: v2);
  CRichEditCtrl::~CRichEditCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CB85D
// Name: public: static class CObject __near * CMFCRibbonEdit::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonEdit *__stdcall CMFCRibbonEdit::CreateObject()
{
  CMFCRibbonEdit *v0; // ecx
  CMFCRibbonEdit *result; // eax

  v0 = (CMFCRibbonEdit *)operator new(nSize: 0x198u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonEdit::CMFCRibbonEdit(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CB8AE
// Name: public: virtual class CMFCRibbonRichEditCtrl __near * CMFCRibbonEdit::CreateEdit(class CWnd __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonRichEditCtrl *__thiscall CMFCRibbonEdit::CreateEdit(
        CMFCRibbonEdit *this,
        CWnd *pWndParent,
        unsigned int dwEditStyle)
{
  CMFCRibbonRichEditCtrl *v4; // ecx
  CMFCRibbonRichEditCtrl *v5; // ebx
  unsigned int m_nID; // [esp-4h] [ebp-3Ch]
  tagRECT rect; // [esp+18h] [ebp-20h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  v4 = (CMFCRibbonRichEditCtrl *)operator new(nSize: 0x88u);
  v9 = 0;
  if ( v4 != nullptr )
    v5 = CMFCRibbonRichEditCtrl::CMFCRibbonRichEditCtrl(this: v4, edit: this);
  else
    v5 = nullptr;
  m_nID = this->m_nID;
  v9 = -1;
  memset(&rect, 0, sizeof(rect));
  if ( CRichEditCtrl::Create(this: v5, dwStyle: dwEditStyle, &rect, pParentWnd: pWndParent, nID: m_nID) != 0 )
  {
    if ( this->m_bHasSpinButtons != 0 )
      CMFCRibbonEdit::CreateSpinButton(this, pWndEdit: v5, pWndParent);
    return v5;
  }
  else
  {
    if ( v5 != nullptr )
      ((void (__thiscall *)(CMFCRibbonRichEditCtrl *, int))v5->dtr_CObject)(a1: v5, a2: 1);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CB95E
// Name: public: void CMFCRibbonEdit::SetEditText(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonEdit::SetEditText(
        CMFCRibbonEdit *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText)
{
  CMFCRibbonRichEditCtrl *m_pWndEdit; // ecx
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  int v5; // eax
  CMFCRibbonEdit *v6; // eax
  CMFCRibbonEdit *v7; // esi
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *v8; // ecx
  ATL::CStringData *v9; // eax
  unsigned int m_nID; // [esp-8h] [ebp-40h]
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *p_arButtons; // [esp-4h] [ebp-3Ch] BYREF
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> arButtons; // [esp+10h] [ebp-28h] BYREF
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> **p_p_arButtons; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int v15; // [esp+34h] [ebp-4h]

  v15 = 0;
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
         this: &this->m_strEdit,
         psz: strText.m_pszData) != 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strEdit, strSrc: (ATL::CStringData *)&strText);
    m_pWndEdit = this->m_pWndEdit;
    if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
      CWnd::SetWindowTextA(this: m_pWndEdit, lpszString: this->m_strEdit.m_pszData);
    this->Redraw(this);
  }
  if ( this->m_bDontNotify == 0 )
  {
    TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
    if ( TopLevelRibbonBar != nullptr )
    {
      arButtons.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
      memset(&arButtons.m_pData, 0, 16);
      p_arButtons = &arButtons;
      m_nID = this->m_nID;
      LOBYTE(v15) = 1;
      CMFCRibbonBar::GetElementsByID(this: TopLevelRibbonBar, uiCmdID: m_nID, &arButtons);
      v5 = 0;
      i = 0;
      if ( arButtons.m_nSize > 0 )
      {
        while ( 1 )
        {
          if ( v5 < 0 || v5 >= arButtons.m_nSize )
            AfxThrowInvalidArgException();
          v6 = (CMFCRibbonEdit *)AfxDynamicDownCast(
                                   pClass: &CMFCRibbonEdit::classCMFCRibbonEdit,
                                   pObject: arButtons.m_pData[v5]);
          v7 = v6;
          v8 = p_arButtons;
          if ( v6 != nullptr && v6 != this )
          {
            v6->m_bDontNotify = 1;
            p_arButtons = v8;
            p_p_arButtons = &p_arButtons;
            v9 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strText.m_pszData - 1);
            CMFCRibbonEdit::SetEditText(
              this: v7,
              strText: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)&v9[1]);
            v7->m_bDontNotify = 0;
          }
          if ( ++i >= arButtons.m_nSize )
            break;
          v5 = i;
        }
      }
      LOBYTE(v15) = 0;
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arButtons);
    }
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103CBA80
// Name: public: virtual void CMFCRibbonEdit::CopyFrom(class CMFCRibbonBaseElement const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonEdit::CopyFrom(CMFCRibbonEdit *this, const CMFCRibbonBaseElement *s)
{
  CMFCRibbonRichEditCtrl *m_pWndEdit; // ecx
  CMFCRibbonRichEditCtrl *v4; // ecx
  CMFCRibbonSpinButtonCtrl *m_pWndSpin; // ecx
  CMFCRibbonSpinButtonCtrl *v6; // ecx

  CMFCRibbonButton::CopyFrom(this, s);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strEdit, strSrc: (ATL::CStringData *)&s[2].m_pParentGroup);
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit != nullptr )
  {
    m_pWndEdit->DestroyWindow(this: m_pWndEdit);
    v4 = this->m_pWndEdit;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CMFCRibbonRichEditCtrl *, int))v4->dtr_CObject)(a1: v4, a2: 1);
    this->m_pWndEdit = nullptr;
  }
  m_pWndSpin = this->m_pWndSpin;
  if ( m_pWndSpin != nullptr )
  {
    m_pWndSpin->DestroyWindow(this: m_pWndSpin);
    v6 = this->m_pWndSpin;
    if ( v6 != nullptr )
      ((void (__thiscall *)(CMFCRibbonSpinButtonCtrl *, int))v6->dtr_CObject)(a1: v6, a2: 1);
    this->m_pWndSpin = nullptr;
  }
  this->m_nWidth = (int)s[2].m_strMenuKeys.m_pszData;
  this->m_nWidthFloaty = (int)s[2].m_strToolTip.m_pszData;
  this->m_bHasSpinButtons = (int)s[2].m_pRibbonBar;
  this->m_bHasDropDownList = s[2].m_rect.bottom;
  this->m_nMin = (int)s[2].m_strDescription.m_pszData;
  this->m_nMax = s[2].m_rect.left;
  this->m_nAlign = s[2].m_rect.top;
  this->m_nLabelImageWidth = s[2].m_rect.right;
}

//------------------------------------------------------------------------------
// Address: 0x103CBB58
// Name: public: virtual int CMFCRibbonEdit::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonEdit::SetACCData(CMFCRibbonEdit *this, CWnd *pParent, CAccessibilityData *data)
{
  CMFCRibbonButton::SetACCData(this, pParent, data);
  ATL::CSimpleStringT<char,0>::operator=(this: &data->m_strAccValue, strSrc: (ATL::CStringData *)&this->m_strEdit);
  if ( this->IsMenuAreaHighlighted(this) != 0 )
  {
    data->m_bAccState = 0;
    data->m_nAccRole = 43;
  }
  else
  {
    data->m_nAccRole = 42;
  }
  if ( this->IsFocused(this) != 0 )
    data->m_bAccState |= 4u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CBBB6
// Name: public: virtual int CMFCRibbonRichEditCtrl::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonRichEditCtrl::PreTranslateMessage(CMFCRibbonRichEditCtrl *this, tagMSG *pMsg)
{
  CMFCRibbonRichEditCtrl *v2; // esi
  tagMSG *v3; // ebx
  unsigned int message; // eax
  CMFCRibbonEdit *m_edit; // ecx
  HWND Focus; // eax
  int m_hWnd; // eax
  int v9; // eax
  LPARAM v10; // edi
  int v11; // eax
  unsigned int wParam; // eax
  _DWORD *v13; // ecx
  HWND v14; // eax
  char *m_pszData; // eax
  tagTRACKMOUSEEVENT *v16; // ecx
  ATL::CStringData *v17; // eax
  CFrameWnd *v18; // eax
  CAfxStringMgr *StringManager; // eax
  tagTRACKMOUSEEVENT *v20; // ecx
  ATL::CStringData *v21; // eax
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  HWND Parent; // eax
  CWnd *v24; // eax
  HWND__ *v25; // ecx
  HWND v26; // eax
  CFrameWnd *v27; // eax
  CFrameWnd *TopLevelFrame; // eax
  HWND v29; // [esp-10h] [ebp-3Ch]
  tagTRACKMOUSEEVENT *v30[5]; // [esp-4h] [ebp-30h] BYREF
  CPoint point; // [esp+10h] [ebp-1Ch] BYREF
  tagPOINT Point; // [esp+18h] [ebp-14h] BYREF
  int v33; // [esp+28h] [ebp-4h]

  v2 = this;
  v3 = pMsg;
  message = pMsg->message;
  if ( message == 20 )
    return 1;
  if ( this->m_bIsContextMenu == 0 )
  {
    if ( message == 513 )
    {
      m_edit = this->m_edit;
      if ( m_edit->m_bIsEditFocused != 0 && m_edit->m_bIsFocused == 0 && pMsg->hwnd != v2->m_hWnd )
        m_edit->OnSetFocus(this: m_edit, a2: 0);
    }
    if ( v3->message == 512 && v2->m_edit->IsDisabled(this: v2->m_edit) == 0 )
    {
      if ( GetAsyncKeyState(vKey: 1) < 0 )
      {
        Focus = GetFocus();
        if ( CWnd::FromHandle(hWnd: Focus) != v2 )
          return 1;
      }
      if ( v2->m_bTracked == 0 )
      {
        m_hWnd = (int)v2->m_hWnd;
        Point.y = -1;
        Point.x = m_hWnd;
        v30[0] = (tagTRACKMOUSEEVENT *)&point;
        v2->m_bTracked = 1;
        point.x = 16;
        point.y = 2;
        AFXTrackMouse(ptme: v30[0]);
        RedrawWindow(hWnd: v2->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      }
      if ( v2->m_bIsHighlighted == 0 && v2->m_edit->GetParentWnd(this: v2->m_edit) != nullptr )
      {
        Point.x = 0;
        Point.y = 0;
        GetCursorPos(lpPoint: &Point);
        v30[0] = (tagTRACKMOUSEEVENT *)261;
        v29 = v2->m_hWnd;
        v2->m_bIsHighlighted = 1;
        RedrawWindow(hWnd: v29, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: (UINT)v30[0]);
        v9 = (int)v2->m_edit->GetParentWnd(this: v2->m_edit);
        ScreenToClient(hWnd: *(HWND *)(v9 + 32), lpPoint: &Point);
        v10 = LOWORD(Point.x) | (LOWORD(Point.y) << 16);
        v11 = (int)v2->m_edit->GetParentWnd(this: v2->m_edit);
        SendMessageA(hWnd: *(HWND *)(v11 + 32), Msg: 0x200u, wParam: 0, lParam: v10);
      }
      v3 = pMsg;
    }
    if ( v3->message != 256 || v2->m_edit->IsDisabled(this: v2->m_edit) != 0 )
      goto LABEL_59;
    if ( CMFCRibbonRichEditCtrl::ProcessClipboardAccelerators(this: v2, nChar: v3->wParam) != 0 )
      return 1;
    wParam = v3->wParam;
    switch ( wParam )
    {
      case 9u:
        if ( v2->m_edit->IsFocused(this: v2->m_edit) == 0 )
          return 1;
        break;
      case 0xDu:
        if ( v2->m_edit->IsDroppedDown(this: v2->m_edit) == 0 )
        {
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
            this: (ATL::CSimpleStringT<char,0> *)&pMsg,
            pStringMgr: StringManager);
          v33 = 0;
          CWnd::GetWindowTextA(
            this: v2,
            rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMsg);
          v30[0] = v20;
          Point.y = (int)v30;
          v21 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)&pMsg[-1].lParam);
          CMFCRibbonEdit::SetEditText(
            this: v2->m_edit,
            strText: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)&v21[1]);
          CMFCRibbonBaseElement::NotifyCommand(this: v2->m_edit, bWithDelay: 1);
          m_pParentMenu = v2->m_edit->m_pParentMenu;
          if ( m_pParentMenu == nullptr )
            goto LABEL_55;
          Parent = GetParent(hWnd: m_pParentMenu->m_hWnd);
          v24 = CWnd::FromHandle(hWnd: Parent);
          if ( v24 != nullptr )
            v25 = v24->m_hWnd;
          else
            v25 = nullptr;
          v26 = CMFCPopupMenu::m_pActivePopupMenu;
          if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
            v26 = *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8);
          if ( v25 == v26 )
          {
            v27 = AFXGetParentFrame(pWnd: v2->m_edit->m_pParentMenu);
            v27->DestroyWindow(this: v27);
          }
          else
          {
LABEL_55:
            if ( CWnd::GetTopLevelFrame(this: v2) == nullptr )
            {
              v33 = -1;
              ATL::CStringData::Release(this: (ATL::CStringData *)&pMsg[-1].lParam);
              break;
            }
            v2->m_edit->m_bNotifyCommand = 0;
            TopLevelFrame = CWnd::GetTopLevelFrame(this: v2);
            CWnd::SetFocus(this: TopLevelFrame);
          }
          ATL::CStringData::Release(this: (ATL::CStringData *)&pMsg[-1].lParam);
          return 1;
        }
        break;
      case 0x1Bu:
        if ( v2->m_edit->IsDroppedDown(this: v2->m_edit) != 0 && CMFCPopupMenu::m_pActivePopupMenu != nullptr )
        {
          SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
          return 1;
        }
        if ( v2->m_edit->IsDroppedDown(this: v2->m_edit) == 0 )
        {
          CWnd::SetWindowTextA(this: v2, lpszString: v2->m_strOldText.m_pszData);
          m_pszData = v2->m_strOldText.m_pszData;
          v30[0] = v16;
          Point.y = (int)v30;
          v17 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)m_pszData - 1);
          CMFCRibbonEdit::SetEditText(
            this: v2->m_edit,
            strText: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)&v17[1]);
          v3 = pMsg;
        }
        if ( CWnd::GetTopLevelFrame(this: v2) != nullptr && v2->m_edit->IsDroppedDown(this: v2->m_edit) == 0 )
        {
          v18 = CWnd::GetTopLevelFrame(this: v2);
          CWnd::SetFocus(this: v18);
          return 1;
        }
        break;
      default:
        if ( wParam > 0x20 )
        {
          if ( wParam <= 0x22 || wParam == 38 )
          {
LABEL_32:
            if ( v2->m_edit->IsDroppedDown(this: v2->m_edit) != 0 )
            {
              v14 = CMFCPopupMenu::m_pActivePopupMenu;
              if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
                v14 = *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8);
              SendMessageA(hWnd: v14, Msg: 0x100u, wParam: v3->wParam, lParam: v3->lParam);
              return 1;
            }
            break;
          }
          if ( wParam == 40 )
          {
            v13 = &v2->m_edit->__vftable;
            if ( v13[95] != 0 && (*(int (__thiscall **)(_DWORD *))(*v13 + 64))(a1: v13) == 0 )
            {
              v2->m_edit->DropDownList(this: v2->m_edit);
              return 1;
            }
            goto LABEL_32;
          }
        }
        break;
    }
LABEL_59:
    this = v2;
  }
  return CWnd::PreTranslateMessage(this, pMsg: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103CBF59
// Name: protected: void CMFCRibbonRichEditCtrl::OnChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonRichEditCtrl::OnChange(CMFCRibbonRichEditCtrl *this)
{
  CAfxStringMgr *StringManager; // eax
  int v3; // ecx
  ATL::CStringData *v4; // eax
  _DWORD v5[6]; // [esp-4h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strText, pStringMgr: StringManager);
  v7 = 0;
  CWnd::GetWindowTextA(this, rString: &strText);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_edit->m_strEdit, strSrc: (ATL::CStringData *)&strText);
  v5[0] = v3;
  v5[5] = v5;
  v4 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strText.m_pszData - 1);
  CMFCRibbonEdit::SetEditText(
    this: this->m_edit,
    strText: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)&v4[1]);
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103CBFC9
// Name: protected: void CMFCRibbonRichEditCtrl::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonRichEditCtrl::OnKillFocus(CMFCRibbonRichEditCtrl *this, CWnd *pNewWnd)
{
  CMFCRibbonEdit *m_edit; // ecx

  CWnd::Default(this);
  this->m_edit->m_bIsEditFocused = 0;
  this->m_edit->Redraw(this: this->m_edit);
  CRichEditCtrl::SetSel(this, nStartChar: 0, nEndChar: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  CWnd::GetWindowTextA(this, rString: &this->m_strOldText);
  ATL::CSimpleStringT<char,0>::operator=(
    this: &this->m_edit->m_strEdit,
    strSrc: (ATL::CStringData *)&this->m_strOldText);
  m_edit = this->m_edit;
  if ( m_edit->m_bNotifyCommand != 0 )
  {
    CMFCRibbonBaseElement::NotifyCommand(this: m_edit, bWithDelay: 1);
    this->m_edit->m_bNotifyCommand = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC042
// Name: private: void CMFCRibbonSpinButtonCtrl::OnDeltapos(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonSpinButtonCtrl::OnDeltapos(CMFCRibbonSpinButtonCtrl *this, tagNMHDR *__formal, int *pResult)
{
  CWnd *Buddy; // eax
  CAfxStringMgr *StringManager; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax
  int v8; // ecx
  ATL::CStringData *v9; // eax
  _DWORD v10[6]; // [esp-4h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  if ( this->m_pEdit != nullptr )
  {
    Buddy = CSpinButtonCtrl::GetBuddy(this);
    if ( Buddy != nullptr && Buddy->m_hWnd != nullptr )
    {
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
      v12 = 0;
      v6 = CSpinButtonCtrl::GetBuddy(this);
      CWnd::GetWindowTextA(this: v6, rString: &str);
      v7 = CSpinButtonCtrl::GetBuddy(this);
      CWnd::SetFocus(this: v7);
      v10[0] = v8;
      v10[5] = v10;
      v9 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)str.m_pszData - 1);
      CMFCRibbonEdit::SetEditText(
        this: this->m_pEdit,
        strText: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)&v9[1]);
      CMFCRibbonBaseElement::NotifyCommand(this: this->m_pEdit, bWithDelay: 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
    }
  }
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103CC0E3
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCRibbonRichEditCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCRibbonRichEditCtrl::GetMessageMap(CMFCRibbonRichEditCtrl *this)
{
  return (const AFX_MSGMAP *)&off_10683B2C;
}

//------------------------------------------------------------------------------
// Address: 0x103CC0E9
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCRibbonSpinButtonCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCRibbonSpinButtonCtrl::GetMessageMap(CMFCRibbonSpinButtonCtrl *this)
{
  return (const AFX_MSGMAP *)&off_10683BE0;
}

//------------------------------------------------------------------------------
// Address: 0x103CC0EF
// Name: public: virtual struct CRuntimeClass __near * CPane::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPane::GetRuntimeClass(CPane *this)
{
  return &CPane::classCPane;
}

//------------------------------------------------------------------------------
// Address: 0x103CC0F5
// Name: protected: CPane::CPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPane *__thiscall CPane::CPane(CPane *this)
{
  CBasePane::CBasePane(this);
  this->__vftable = (CPane_vtbl *)&CPane::`vftable';
  this->m_bDisableMove = false;
  this->m_rectVirtual.left = 0;
  this->m_rectVirtual.top = 0;
  this->m_rectVirtual.right = 0;
  this->m_rectVirtual.bottom = 0;
  this->m_rectDragImmediate.left = 0;
  this->m_rectDragImmediate.top = 0;
  this->m_rectDragImmediate.right = 0;
  this->m_rectDragImmediate.bottom = 0;
  this->m_sizeMin.cx = 0;
  this->m_sizeMin.cy = 0;
  this->m_ptClientHotSpot.x = 0;
  this->m_ptClientHotSpot.y = 0;
  this->m_bCaptured = false;
  this->m_nID = 0;
  CMFCDragFrameImpl::CMFCDragFrameImpl(this: &this->m_dragFrameImpl);
  CRecentDockSiteInfo::CRecentDockSiteInfo(this: &this->m_recentDockInfo, pBar: this);
  this->m_rectSavedDockedRect.left = 0;
  this->m_rectSavedDockedRect.top = 0;
  this->m_rectSavedDockedRect.right = 0;
  this->m_rectSavedDockedRect.bottom = 0;
  this->m_cxRightBorder = 6;
  this->m_cxLeftBorder = 6;
  this->m_cxDefaultGap = 2;
  this->m_cyBottomBorder = 2;
  this->m_cyTopBorder = 2;
  this->m_pData = nullptr;
  this->m_nCount = 0;
  this->m_nMRUWidth = 0x7FFF;
  this->m_bDblClick = false;
  this->m_ptClientHotSpot.y = 0;
  this->m_ptClientHotSpot.x = 0;
  SetRectEmpty(lprc: &this->m_rectSavedDockedRect);
  this->m_bDragMode = 0;
  this->m_bWasFloatingBeforeMove = 0;
  this->m_bWasFloatingBeforeTabbed = 0;
  this->m_bRecentFloatingState = 0;
  this->m_pMiniFrameRTC = &CPaneFrameWnd::classCPaneFrameWnd;
  SetRectEmpty(lprc: &this->m_rectDragImmediate);
  this->m_bFirstInGroup = 1;
  this->m_bLastInGroup = 1;
  this->m_bActiveInGroup = 1;
  this->m_sizeMin.cy = 1;
  this->m_sizeMin.cx = 1;
  this->m_hwndMiniFrameToBeClosed = nullptr;
  this->m_bExclusiveRow = 0;
  this->m_bPinState = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CC24C
// Name: public: virtual int CBasePane::IsFloating(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CBasePane::IsFloating(CBasePane *this)
{
  return this->IsDocked(this) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103CC25A
// Name: public: virtual int CBasePane::CanBeClosed(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CBasePane::CanBeClosed(CBasePane *this)
{
  return this->m_dwControlBarStyle & 8;
}

//------------------------------------------------------------------------------
// Address: 0x103CC264
// Name: public: virtual void CPane::GetMinSize(class CSize __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::GetMinSize(CPane *this, CSize *size)
{
  *size = this->m_sizeMin;
}

//------------------------------------------------------------------------------
// Address: 0x103CC281
// Name: public: virtual CPane::~CPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::~CPane(CPane *this)
{
  void *m_pData; // eax

  this->__vftable = (CPane_vtbl *)&CPane::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    free(pMem: m_pData);
  CRecentDockSiteInfo::~CRecentDockSiteInfo(this: &this->m_recentDockInfo);
  CMFCDragFrameImpl::~CMFCDragFrameImpl(this: &this->m_dragFrameImpl);
  CBasePane::~CBasePane(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CC2DB
// Name: public: void CPane::SetBorders(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::SetBorders(CPane *this, int cxLeft, int cyTop, int cxRight, int cyBottom)
{
  this->m_cxLeftBorder = cxLeft;
  this->m_cxRightBorder = cxRight;
  this->m_cyTopBorder = cyTop;
  this->m_cyBottomBorder = cyBottom;
}

//------------------------------------------------------------------------------
// Address: 0x103CC308
// Name: public: void CPane::SetBorders(struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::SetBorders(CPane *this, const tagRECT *lpRect)
{
  this->m_cxLeftBorder = lpRect->left;
  this->m_cxRightBorder = lpRect->right;
  this->m_cyTopBorder = lpRect->top;
  this->m_cyBottomBorder = lpRect->bottom;
}

//------------------------------------------------------------------------------
// Address: 0x103CC337
// Name: public: virtual int CPane::DockByMouse(class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPane::DockByMouse(CPane *this, CBasePane *pDockBar)
{
  if ( this->OnBeforeDock(this, a2: &pDockBar, a3: nullptr, a4: DM_MOUSE) == 0
    || this->Dock(this, a2: pDockBar, a3: nullptr, a4: DM_MOUSE) == 0 )
  {
    return 0;
  }
  this->OnAfterDock(this, a2: pDockBar, a3: nullptr, a4: DM_MOUSE);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CC387
// Name: public: virtual int CPane::DockPane(class CBasePane __near *,struct tagRECT const __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPane::DockPane(CPane *this, CBasePane *pDockBar, const tagRECT *lpRect, AFX_DOCK_METHOD dockMethod)
{
  if ( this->OnBeforeDock(this, a2: &pDockBar, a3: lpRect, a4: dockMethod) == 0
    || this->Dock(this, a2: pDockBar, a3: lpRect, a4: dockMethod) == 0 )
  {
    return 0;
  }
  this->OnAfterDock(this, a2: pDockBar, a3: lpRect, a4: dockMethod);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CC3DD
// Name: public: virtual void CPane::PrepareToDock(class CDockSite __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::PrepareToDock(CPane *this, CDockSite *pDockBar, AFX_DOCK_METHOD dockMethod)
{
  unsigned int v4; // eax
  CPane_vtbl *v5; // ebx
  unsigned int v6; // eax

  if ( pDockBar != nullptr )
  {
    this->m_pParentDockBar = (CDockSite *)AfxDynamicDownCast(pClass: &CDockSite::classCDockSite, pObject: pDockBar);
    this->RemoveFromMiniframe(this, a2: pDockBar, a3: dockMethod);
    v4 = this->GetPaneStyle(this);
    this->SetPaneStyle(this, a2: v4 & 0xFFFF0FFE | this->m_dwStyle & 0xF000 | 0xF00);
    v5 = this->__vftable;
    v6 = pDockBar->GetCurrentAlignment(this: pDockBar);
    v5->SetPaneAlignment(this, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC45C
// Name: protected: virtual int CPane::OnBeforeDock(class CBasePane __near * __near *,struct tagRECT const __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPane::OnBeforeDock(CPane *this, CBasePane **__formal, CBasePane **__formala, AFX_DOCK_METHOD a4)
{
  CPaneFrameWnd *v5; // eax

  v5 = this->GetParentMiniFrame(this, a2: 0);
  if ( v5 != nullptr )
    this->m_bPinState = v5->m_bPinned;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CC482
// Name: protected: virtual void CPane::OnContinueMoving(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnContinueMoving(CPane *this)
{
  this->EnterDragMode(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103CC48D
// Name: public: virtual void CPane::OnBeforeChangeParent(class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnBeforeChangeParent(CPane *this, CWnd *pWndNewParent, CWnd *bDelay)
{
  if ( this->m_pParentDockBar != nullptr )
    this->m_pParentDockBar->RemovePane(this: this->m_pParentDockBar, a2: this, a3: DM_UNKNOWN);
}

//------------------------------------------------------------------------------
// Address: 0x103CC4AC
// Name: public: virtual class CPaneFrameWnd __near * CPane::CreateDefaultMiniframe(class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneFrameWnd *__thiscall CPane::CreateDefaultMiniframe(CPane *this, CRect rectInitial)
{
  CRuntimeClass *m_pMiniFrameRTC; // ecx
  CObject *Object; // esi
  CFrameWnd *v5; // edi
  CWnd *v6; // eax
  CRect rectVirtual; // [esp+Ch] [ebp-14h] BYREF

  rectVirtual.left = rectInitial.left;
  rectVirtual.top = rectInitial.top;
  rectVirtual.right = rectInitial.right;
  m_pMiniFrameRTC = this->m_pMiniFrameRTC;
  rectVirtual.bottom = rectInitial.bottom;
  Object = CRuntimeClass::CreateObject(this: m_pMiniFrameRTC);
  if ( Object == nullptr )
    return (CPaneFrameWnd *)Object;
  v5 = AFXGetParentFrame(pWnd: this);
  v6 = this->GetDockSiteFrameWnd(this);
  Object[94].__vftable = (CObject_vtbl *)CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v6);
  if ( ((int (__thiscall *)(CObject *, _DWORD, unsigned int, CRect *, CFrameWnd *, _DWORD))Object->__vftable[42].Serialize)(
         a1: Object,
         a2: 0,
         a3: 0x80000000,
         a4: &rectVirtual,
         a5: v5,
         a6: 0) != 0 )
    return (CPaneFrameWnd *)Object;
  ((void (__thiscall *)(CObject *, int))Object->dtr_CObject)(a1: Object, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103CC53E
// Name: protected: void CPane::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnNcDestroy(CPane *this)
{
  CPaneFrameWnd *v2; // eax

  CPaneFrameWnd::AddRemovePaneFromGlobalList(pWnd: this, bAdd: 0);
  v2 = this->GetParentMiniFrame(this, a2: 1);
  if ( v2 != nullptr )
    v2->RemovePane(this: v2, a2: this, a3: 0, a4: 0);
  CWnd::OnNcDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CC572
// Name: public: void CPane::CalcInsideRect(class CRect __near &,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::CalcInsideRect(CPane *this, CRect *rect, int bHorz)
{
  unsigned int v4; // ebx
  int v5; // ebx

  v4 = this->GetPaneStyle(this);
  if ( this->IsFloating(this) == 0 && this->IsTabbed(this) == 0 )
  {
    if ( (v4 & 0x100) != 0 )
      ++rect->left;
    if ( (v4 & 0x200) != 0 )
      ++rect->top;
    if ( (v4 & 0x400) != 0 )
      --rect->right;
    if ( (v4 & 0x800) != 0 )
      --rect->bottom;
  }
  v5 = v4 & 0x400001;
  if ( bHorz != 0 )
  {
    rect->left += this->m_cxLeftBorder;
    rect->top += this->m_cyTopBorder;
    rect->right -= this->m_cxRightBorder;
    rect->bottom -= this->m_cyBottomBorder;
    if ( v5 == 0x400000 )
    {
      if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
        rect->right -= 7;
      else
        rect->left += 7;
    }
  }
  else
  {
    rect->left += this->m_cyTopBorder;
    rect->top += this->m_cxLeftBorder;
    rect->right -= this->m_cyBottomBorder;
    rect->bottom -= this->m_cxRightBorder;
    if ( v5 == 0x400000 )
      rect->top += 7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC653
// Name: public: virtual void CPane::OnProcessDblClk(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnProcessDblClk(CPane *this)
{
  CPane_vtbl *v2; // eax
  CPane_vtbl *v3; // eax

  v2 = this->__vftable;
  this->m_bDblClick = true;
  ((void (*)(void))v2->StoreRecentDockSiteInfo)();
  if ( this->m_bCaptured )
  {
    ReleaseCapture();
    v3 = this->__vftable;
    this->m_bCaptured = false;
    v3->SetDragMode(this, a2: 0);
    if ( this->m_hwndMiniFrameToBeClosed != nullptr && IsWindow(hWnd: this->m_hwndMiniFrameToBeClosed) )
      DestroyWindow(hWnd: this->m_hwndMiniFrameToBeClosed);
    this->m_hwndMiniFrameToBeClosed = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC6B5
// Name: protected: virtual void CPane::SetDragMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::SetDragMode(CPane *this, int bOnOff)
{
  this->m_bDragMode = bOnOff;
}

//------------------------------------------------------------------------------
// Address: 0x103CC6C7
// Name: protected: void CPane::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnContextMenu(CPane *this, CWnd *__formal, CPoint point)
{
  CFrameWnd *TopLevelFrame; // eax

  if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr
    && CMFCToolBar::m_bCustomizeMode == 0
    && ((int (__thiscall *)(CPane *, int, int))this->OnShowControlBarMenu)(a1: this, a2: point.x, a3: point.y) == 0 )
  {
    TopLevelFrame = (CFrameWnd *)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: this->m_pDockSite);
    if ( TopLevelFrame != nullptr
      || (TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame, g_pTopLevelFrame != nullptr)
      || (TopLevelFrame = CWnd::GetTopLevelFrame(this)) != nullptr )
    {
      ((void (__thiscall *)(CPane *, CFrameWnd *, int, int))this->OnPaneContextMenu)(
        a1: this,
        a2: TopLevelFrame,
        a3: point.x,
        a4: point.y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC733
// Name: public: virtual void CPane::SetDockState(class CDockingManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::SetDockState(CPane *this, CDockingManager *pDockManager)
{
  CDockSite *v3; // eax
  unsigned int v4; // eax
  CDockSite_vtbl *v5; // edi
  int v6; // eax
  CDockingPanesRow *m_pDockBarRow; // ecx

  if ( this->m_bRecentFloatingState == 0 )
  {
    v3 = pDockManager->FindDockSite(this: pDockManager, a2: this->m_recentDockInfo.m_dwRecentAlignmentToFrame, a3: 1);
    if ( v3 != nullptr )
    {
      v4 = v3->GetDockSiteID(this: v3);
      CDockingManager::DockPane(
        this: pDockManager,
        pBar: this,
        nDockBarID: v4,
        lpRect: &this->m_recentDockInfo.m_recentSliderInfo.m_rectDockedRect);
    }
    if ( this->m_pParentDockBar != nullptr )
    {
      v5 = this->m_pParentDockBar->CBasePane::__vftable;
      v6 = ((int (__thiscall *)(CPane *, int, _DWORD))this->GetRecentVisibleState)(a1: this, a2: 1, a3: 0);
      ((void (__thiscall *)(CDockSite *, CPane *, int))v5->ShowPane)(a1: this->m_pParentDockBar, a2: this, a3: v6);
      m_pDockBarRow = this->m_pDockBarRow;
      if ( m_pDockBarRow != nullptr )
        CDockingPanesRow::ExpandStretchedPanes(this: m_pDockBarRow, a2: (int)v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC7B7
// Name: public: virtual void CPane::SetActiveInGroup(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::SetActiveInGroup(CPane *this, int bActive)
{
  this->m_bActiveInGroup = bActive;
}

//------------------------------------------------------------------------------
// Address: 0x103CC7C9
// Name: public: virtual void CPane::UndockPane(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::UndockPane(CPane *this, int bDelay)
{
  if ( this->m_pParentDockBar != nullptr )
    this->m_pParentDockBar->RemovePane(this: this->m_pParentDockBar, a2: this, a3: DM_UNKNOWN);
  if ( bDelay == 0 )
    this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103CC804
// Name: protected: virtual void CPane::OnRTLChanged(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnRTLChanged(CPane *this, int bIsRTL)
{
  afxGlobalData.m_bIsRTL = bIsRTL;
  if ( this->GetParentDockSite(this) != nullptr && this->IsHorizontal(this) != 0 )
    this->SetWindowPos(
      this,
      a2: nullptr,
      a3: this->m_rectVirtual.left,
      a4: this->m_rectVirtual.top,
      a5: this->m_rectVirtual.right - this->m_rectVirtual.left,
      a6: this->m_rectVirtual.bottom - this->m_rectVirtual.top,
      a7: 4u,
      a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103CC868
// Name: public: virtual void CPane::OnPressCloseButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::OnPressCloseButton(CPane *this)
{
  CPaneFrameWnd *v1; // eax

  v1 = this->GetParentMiniFrame(this, a2: 0);
  if ( v1 != nullptr )
    v1->CloseMiniFrame(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x103CC881
// Name: public: virtual void CPane::CopyState(class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPane::CopyState(CPane *this, CPane *pOrgBar)
{
  CBasePane::CopyState(this, pOrgBar);
  this->m_bFirstInGroup = pOrgBar->m_bFirstInGroup;
  this->m_bLastInGroup = pOrgBar->m_bLastInGroup;
  this->m_bActiveInGroup = pOrgBar->m_bActiveInGroup;
  pOrgBar->GetMinSize(this: pOrgBar, a2: &this->m_sizeMin);
  CRecentDockSiteInfo::operator=(this: &this->m_recentDockInfo, src: &pOrgBar->m_recentDockInfo);
  this->m_rectSavedDockedRect = pOrgBar->m_rectSavedDockedRect;
  this->m_bRecentFloatingState = pOrgBar->m_bRecentFloatingState;
}

//------------------------------------------------------------------------------
// Address: 0x103CC901
// Name: public: virtual int CPane::CanBeTabbedDocument(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPane::CanBeTabbedDocument(CPane *this)
{
  CWnd *v3; // eax
  CObject *v4; // eax

  if ( this->IsAutoHideMode(this) != 0 )
    return false;
  v3 = this->GetDockSiteFrameWnd(this);
  v4 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: v3);
  return v4 != nullptr && v4->__vftable[39].GetRuntimeClass(this: v4) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103CC943
// Name: public: virtual class CSize CBasePane::StretchPane(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CBasePane::StretchPane(CBasePane *this, CSize *result, int nLength, int bVert)
{
  result->cx = 0;
  result->cy = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CF5D0
// Name: protected: virtual void CMFCCaptionBar::AdjustLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::AdjustLayout(CMFCCaptionBar *this)
{
  CFrameWnd *v2; // eax

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    v2 = AFXGetParentFrame(pWnd: this);
    if ( v2 != nullptr && v2->m_hWnd != nullptr )
      v2->RecalcLayout(this: v2, a2: 1);
    this->RecalcLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CF609
// Name: protected: virtual int CMFCCaptionBar::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCCaptionBar::PreTranslateMessage(CMFCCaptionBar *this, tagMSG *pMsg)
{
  unsigned int message; // eax
  unsigned int v4; // eax
  CToolTipCtrl *m_pToolTip; // eax

  message = pMsg->message;
  if ( message > 0x202 )
  {
    if ( message < 0x204 || message > 0x205 && message - 519 > 1 )
      return CBasePane::PreTranslateMessage(this, pMsg);
  }
  else if ( message < 0x200 )
  {
    v4 = message - 256;
    if ( v4 != 0 && v4 != 4 )
      return CBasePane::PreTranslateMessage(this, pMsg);
  }
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    SendMessageA(hWnd: m_pToolTip->m_hWnd, Msg: 0x407u, wParam: 0, lParam: (LPARAM)pMsg);
  return CBasePane::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103CF67B
// Name: protected: long CMFCCaptionBar::OnUpdateToolTips(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCCaptionBar::OnUpdateToolTips(CMFCCaptionBar *this, __int16 wp, int __formal)
{
  CToolTipCtrl **p_m_pToolTip; // esi
  CRect rectDummy; // [esp+4h] [ebp-14h] BYREF

  if ( (wp & 0x400) != 0 )
  {
    p_m_pToolTip = &this->m_pToolTip;
    CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 0x400u);
    memset(&rectDummy, 0, sizeof(rectDummy));
    SendMessageA(hWnd: (*p_m_pToolTip)->m_hWnd, Msg: 0x418u, wParam: 0, lParam: 640);
    CToolTipCtrl::AddTool(
      this: *p_m_pToolTip,
      pWnd: this,
      lpszText: (char *)0xFFFFFFFF,
      lpRectTool: &rectDummy,
      nIDTool: 1u);
    CToolTipCtrl::AddTool(
      this: *p_m_pToolTip,
      pWnd: this,
      lpszText: (char *)0xFFFFFFFF,
      lpRectTool: &rectDummy,
      nIDTool: 2u);
    CToolTipCtrl::AddTool(
      this: *p_m_pToolTip,
      pWnd: this,
      lpszText: (char *)0xFFFFFFFF,
      lpRectTool: &rectDummy,
      nIDTool: 3u);
    CToolTipCtrl::AddTool(
      this: *p_m_pToolTip,
      pWnd: this,
      lpszText: (char *)0xFFFFFFFF,
      lpRectTool: &rectDummy,
      nIDTool: 4u);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103CF71F
// Name: protected: void CMFCCaptionBar::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnLButtonDown(CMFCCaptionBar *this, WPARAM nFlags, CPoint point)
{
  CWnd *Owner; // eax
  WPARAM nFlagsa; // [esp+14h] [ebp+8h]

  CPane::OnLButtonDown(this, nFlags, point);
  if ( this->m_uiBtnID != 0 && this->m_bBtnEnabled != 0 && this->m_bIsBtnHighlighted != 0 )
  {
    this->m_bIsBtnPressed = 1;
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectButton, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
    if ( this->m_bBtnHasDropDownArrow != 0 )
    {
      nFlagsa = this->m_uiBtnID;
      Owner = CWnd::GetOwner(this);
      SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: nFlagsa, lParam: 0);
    }
  }
  if ( this->m_bIsCloseBtnHighlighted != 0 )
  {
    this->m_bIsCloseBtnPressed = 1;
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectClose, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CF7CD
// Name: protected: void CMFCCaptionBar::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnLButtonUp(CMFCCaptionBar *this, WPARAM nFlags, CPoint point)
{
  WPARAM m_uiBtnID; // ebx
  CWnd *Owner; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-18h]
  HWND__ *v7; // [esp-Ch] [ebp-18h]

  CPane::OnLButtonUp(this, nFlags, point);
  if ( this->m_bIsBtnPressed != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_bIsBtnPressed = 0;
    InvalidateRect(hWnd: m_hWnd, lpRect: &this->m_rectButton, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
    if ( this->m_bBtnHasDropDownArrow == 0 )
    {
      m_uiBtnID = this->m_uiBtnID;
      if ( m_uiBtnID != 0 )
      {
        Owner = CWnd::GetOwner(this);
        SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: m_uiBtnID, lParam: 0);
      }
    }
  }
  else if ( this->m_bIsCloseBtnPressed != 0 )
  {
    v7 = this->m_hWnd;
    this->m_bIsCloseBtnPressed = 0;
    InvalidateRect(hWnd: v7, lpRect: &this->m_rectClose, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
    this->ShowPane(this, a2: 0, a3: 0, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CF878
// Name: protected: void CMFCCaptionBar::OnRButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnRButtonUp(CMFCCaptionBar *this, unsigned int nFlags, CPoint point)
{
  CMFCCaptionBar_vtbl *v4; // edi
  CWnd *Owner; // eax
  CPoint v6; // 0:^4.8

  if ( CMFCToolBar::m_bCustomizeMode != 0 )
  {
    CWnd::Default(this);
  }
  else
  {
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
    v6 = point;
    v4 = this->__vftable;
    Owner = CWnd::GetOwner(this);
    ((void (__thiscall *)(CMFCCaptionBar *, CWnd *, int, int))v4->OnPaneContextMenu)(
      a1: this,
      a2: Owner,
      a3: v6.x,
      a4: v6.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CF8BC
// Name: public: CMFCCaptionBar::CMFCCaptionBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionBar *__thiscall CMFCCaptionBar::CMFCCaptionBar(CMFCCaptionBar *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax
  CAfxStringMgr *v7; // eax

  CPane::CPane(this);
  this->__vftable = (CMFCCaptionBar_vtbl *)&CMFCCaptionBar::`vftable';
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_Bitmap);
  this->m_rectImage.left = 0;
  this->m_rectImage.top = 0;
  this->m_rectImage.right = 0;
  this->m_rectImage.bottom = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strImageToolTip, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strImageDescription, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strText, pStringMgr: v4);
  CStringArray::CStringArray(this: &this->m_arTextParts);
  this->m_rectText.left = 0;
  this->m_rectText.top = 0;
  this->m_rectText.right = 0;
  this->m_rectText.bottom = 0;
  this->m_rectDrawText.left = 0;
  this->m_rectDrawText.top = 0;
  this->m_rectDrawText.right = 0;
  this->m_rectDrawText.bottom = 0;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strBtnText, pStringMgr: v5);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strButtonToolTip, pStringMgr: v6);
  v7 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strButtonDescription, pStringMgr: v7);
  this->m_rectButton.left = 0;
  this->m_rectButton.top = 0;
  this->m_rectButton.right = 0;
  this->m_rectButton.bottom = 0;
  this->m_rectClose.left = 0;
  this->m_rectClose.top = 0;
  this->m_rectClose.right = 0;
  this->m_rectClose.bottom = 0;
  this->m_nBorderSize = 4;
  this->m_nMargin = 4;
  this->m_nHorzElementOffset = 4;
  this->m_pToolTip = nullptr;
  this->m_clrBarText = -1;
  this->m_clrBarBackground = -1;
  this->m_clrBarBorder = -1;
  this->m_hIcon = nullptr;
  this->m_hFont = nullptr;
  this->m_nDefaultHeight = -1;
  this->m_nCurrentHeight = 0;
  this->m_btnAlignnment = ALIGN_LEFT;
  this->m_iconAlignment = ALIGN_LEFT;
  this->m_textAlignment = ALIGN_LEFT;
  this->m_bStretchImage = 0;
  this->m_bFlatBorder = 0;
  this->m_uiBtnID = 0;
  this->m_bIsBtnPressed = 0;
  this->m_bIsBtnForcePressed = 0;
  this->m_bIsBtnHighlighted = 0;
  this->m_bTracked = 0;
  this->m_bBtnEnabled = 1;
  this->m_bBtnHasDropDownArrow = 1;
  SetRectEmpty(lprc: &this->m_rectImage);
  SetRectEmpty(lprc: &this->m_rectText);
  SetRectEmpty(lprc: &this->m_rectDrawText);
  SetRectEmpty(lprc: &this->m_rectButton);
  this->m_bTextIsTruncated = 0;
  this->m_bIsMessageBarMode = 0;
  this->m_bIsCloseBtnPressed = 0;
  this->m_bIsCloseBtnHighlighted = 0;
  this->m_bCloseTracked = 0;
  SetRectEmpty(lprc: &this->m_rectClose);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CFAC0
// Name: public: virtual CMFCCaptionBar::~CMFCCaptionBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::~CMFCCaptionBar(CMFCCaptionBar *this)
{
  this->__vftable = (CMFCCaptionBar_vtbl *)&CMFCCaptionBar::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strButtonDescription.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strButtonToolTip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strBtnText.m_pszData - 1);
  CStringArray::~CStringArray(this: &this->m_arTextParts);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strText.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strImageDescription.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strImageToolTip.m_pszData - 1);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_Bitmap);
  CPane::~CPane(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CFB5A
// Name: protected: virtual void CMFCCaptionBar::OnDrawText(class CDC __near *,class CRect,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnDrawText(
        CMFCCaptionBar *this,
        CDC *pDC,
        CRect rect,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strText)
{
  int m_nSize; // edx
  CDC *v6; // esi
  int v7; // eax
  int v8; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pData; // ecx
  CSize sizePart; // [esp+8h] [ebp-34h] BYREF
  unsigned int v11; // [esp+10h] [ebp-2Ch]
  CDC *v12; // [esp+14h] [ebp-28h]
  int bIsBold; // [esp+18h] [ebp-24h]
  int x; // [esp+1Ch] [ebp-20h]
  CFont *pOldFont; // [esp+20h] [ebp-1Ch]
  int i; // [esp+24h] [ebp-18h]
  CRect rectPart; // [esp+28h] [ebp-14h] BYREF

  m_nSize = this->m_arTextParts.m_nSize;
  v6 = pDC;
  v12 = pDC;
  if ( m_nSize == 1 )
  {
    pDC->DrawTextA(this: pDC, a2: strText->m_pszData, a3: *((_DWORD *)strText->m_pszData - 3), a4: &rect, a5: 32804u);
  }
  else
  {
    x = rect.left;
    v7 = 0;
    bIsBold = 0;
    i = 0;
    if ( m_nSize > 0 )
    {
      while ( v7 >= 0 && v7 < this->m_arTextParts.m_nSize )
      {
        if ( *((_DWORD *)this->m_arTextParts.m_pData[v7].m_pszData - 3) != 0 )
        {
          pOldFont = nullptr;
          if ( bIsBold != 0 )
            pOldFont = v6->SelectObject(this: v6, a2: &afxGlobalData.fontBold);
          rectPart.top = rect.top;
          rectPart.right = rect.right;
          rectPart.bottom = rect.bottom;
          v8 = i;
          rectPart.left = x;
          if ( i >= this->m_arTextParts.m_nSize )
            break;
          m_pData = this->m_arTextParts.m_pData;
          v6 = v12;
          v11 = 4 * i;
          CDC::GetTextExtent(this: v12, result: &sizePart, str: &m_pData[i]);
          if ( v8 >= this->m_arTextParts.m_nSize )
            break;
          v6->DrawTextA(
            this: v6,
            a2: this->m_arTextParts.m_pData[v11 / 4].m_pszData,
            a3: *((_DWORD *)this->m_arTextParts.m_pData[v11 / 4].m_pszData - 3),
            a4: &rectPart,
            a5: 32804u);
          if ( pOldFont != nullptr )
            v6->SelectObject(this: v6, a2: pOldFont);
          x += sizePart.cx;
          v7 = i;
        }
        i = ++v7;
        bIsBold = bIsBold == 0;
        if ( v7 >= this->m_arTextParts.m_nSize )
          return;
      }
      AfxThrowInvalidArgException();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CFCA7
// Name: protected: void CMFCCaptionBar::UpdateTooltips(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::UpdateTooltips(CMFCCaptionBar *this)
{
  CToolTipCtrl *m_pToolTip; // ecx
  CToolTipCtrl *v3; // ecx
  CRect *p_m_rectDrawText; // eax
  CToolTipCtrl *v5; // ecx
  CRect *p_m_rectImage; // eax
  CToolTipCtrl *v7; // ecx
  CRect *p_m_rectButton; // eax
  int v9; // [esp+8h] [ebp-14h] BYREF
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]

  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
  {
    CToolTipCtrl::SetToolRect(this: m_pToolTip, pWnd: this, nIDTool: 1u, lpRect: &this->m_rectClose);
    v3 = this->m_pToolTip;
    if ( this->m_bTextIsTruncated != 0 )
    {
      p_m_rectDrawText = &this->m_rectDrawText;
    }
    else
    {
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v12 = 0;
      p_m_rectDrawText = (CRect *)&v9;
    }
    CToolTipCtrl::SetToolRect(this: v3, pWnd: this, nIDTool: 2u, lpRect: p_m_rectDrawText);
    v5 = this->m_pToolTip;
    if ( *((_DWORD *)this->m_strImageToolTip.m_pszData - 3) != 0 )
    {
      p_m_rectImage = &this->m_rectImage;
    }
    else
    {
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v12 = 0;
      p_m_rectImage = (CRect *)&v9;
    }
    CToolTipCtrl::SetToolRect(this: v5, pWnd: this, nIDTool: 3u, lpRect: p_m_rectImage);
    v7 = this->m_pToolTip;
    if ( *((_DWORD *)this->m_strButtonToolTip.m_pszData - 3) != 0 )
    {
      p_m_rectButton = &this->m_rectButton;
    }
    else
    {
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v12 = 0;
      p_m_rectButton = (CRect *)&v9;
    }
    CToolTipCtrl::SetToolRect(this: v7, pWnd: this, nIDTool: 4u, lpRect: p_m_rectButton);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F6F34
// Name: public: virtual class CSize CMFCAutoHideBar::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCAutoHideBar::CalcFixedLayout(CMFCAutoHideBar *this, CSize *result, int __formal, int a4)
{
  CRect rect; // [esp+4h] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rect);
  result->cx = rect.right - rect.left;
  result->cy = rect.bottom - rect.top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F6F89
// Name: protected: void CMFCAutoHideBar::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideBar::OnNcDestroy(CMFCAutoHideBar *this)
{
  if ( this->m_nDisplayAHWndTimerID != 0 )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: this->m_nDisplayAHWndTimerID);
    this->m_nDisplayAHWndTimerID = 0;
  }
  CWnd::OnNcDestroy(this);
  ((void (__thiscall *)(CMFCAutoHideBar *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103F6FBD
// Name: protected: void CMFCAutoHideBar::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideBar::OnTimer(CMFCAutoHideBar *this, CMFCAutoHideButton *nIDEvent)
{
  CPoint pt; // [esp+4h] [ebp-8h] BYREF
  CMFCAutoHideButton *pBtn; // [esp+14h] [ebp+8h]

  if ( nIDEvent == (CMFCAutoHideButton *)1 )
  {
    pt = 0;
    GetCursorPos(lpPoint: &pt);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &pt);
    pBtn = CMFCAutoHideBar::ButtonFromPoint(this, pt);
    KillTimer(hWnd: this->m_hWnd, uIDEvent: this->m_nDisplayAHWndTimerID);
    this->m_nDisplayAHWndTimerID = 0;
    if ( pBtn != nullptr && this->m_bReadyToDisplayAHWnd != 0 )
    {
      this->m_bReadyToDisplayAHWnd = 0;
      if ( !IsWindowVisible(hWnd: pBtn->m_pAutoHideWindow->m_hWnd) )
        CMFCAutoHideButton::ShowAttachedWindow(this: pBtn, bShow: 1);
    }
    else
    {
      this->m_bReadyToDisplayAHWnd = 0;
    }
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F7057
// Name: public: virtual class CSize CMFCAutoHideBar::StretchPane(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCAutoHideBar::StretchPane(CMFCAutoHideBar *this, CSize *result, int __formal, int a4)
{
  CObList::CNode *m_pNodeHead; // edi
  CMFCAutoHideButton *data; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-34h]
  CSize v9; // [esp+Ch] [ebp-20h] BYREF
  CMFCAutoHideBar *v10; // [esp+14h] [ebp-18h]
  CRect rect; // [esp+18h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  v10 = this;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  result->cx = 0;
  result->cy = 0;
  m_pNodeHead = this->m_lstAutoHideButtons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (CMFCAutoHideButton *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    *result = *CMFCAutoHideButton::GetSize(this: data, result: &v9);
  }
  v10->SetWindowPos(this: v10, a2: nullptr, a3: 0, a4: 0, a5: result->cx, a6: result->cy, a7: 6u, a8: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F710E
// Name: public: int CMFCAutoHideBar::ShowAutoHideWindow(class CDockablePane __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCAutoHideBar::ShowAutoHideWindow(
        CMFCAutoHideBar *this,
        CDockablePane *pAutoHideWnd,
        int bShow,
        int __formal)
{
  int result; // eax

  result = (int)CMFCAutoHideBar::ButtonFromAutoHideWindow(this, pAutoHideWnd);
  if ( result != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)result + 16))(a1: result, a2: bShow);
    CMFCAutoHideBar::UpdateVisibleState(this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F713B
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCAutoHideBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCAutoHideBar::GetMessageMap(CMFCAutoHideBar *this)
{
  return (const AFX_MSGMAP *)&off_1068950C;
}

//------------------------------------------------------------------------------
// Address: 0x103F7141
// Name: public: virtual class CFrameWnd __near * CFrameWnd::GetActiveFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCReBar *__thiscall CFrameWnd::GetActiveFrame(CMFCReBar *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F7144
// Name: public: virtual struct CRuntimeClass __near * CBaseTabbedPane::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBaseTabbedPane::GetRuntimeClass(CBaseTabbedPane *this)
{
  return &CBaseTabbedPane::classCBaseTabbedPane;
}

//------------------------------------------------------------------------------
// Address: 0x103F714A
// Name: protected: void CBaseTabbedPane::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBaseTabbedPane::OnNcDestroy(CBaseTabbedPane *this)
{
  CMFCBaseTabCtrl *m_pTabWnd; // ecx

  m_pTabWnd = this->m_pTabWnd;
  if ( m_pTabWnd != nullptr )
  {
    ((void (__thiscall *)(CMFCBaseTabCtrl *, int))m_pTabWnd->dtr_CObject)(a1: m_pTabWnd, a2: 1);
    this->m_pTabWnd = nullptr;
  }
  CPane::OnNcDestroy(this);
  if ( this->m_bAutoDestroy != 0 )
    ((void (__thiscall *)(CBaseTabbedPane *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103F7184
// Name: public: virtual class CWnd __near * CBaseTabbedPane::FindPaneByID(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CBaseTabbedPane::FindPaneByID(CBaseTabbedPane *this, unsigned int uBarID)
{
  int v3; // edi
  CWnd *v4; // ebx

  v3 = 0;
  if ( this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_pTabWnd->GetTabWnd(this: this->m_pTabWnd, a2: v3);
    if ( CWnd::GetDlgCtrlID(this: v4) == uBarID )
      break;
    if ( ++v3 >= this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd) )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103F71DF
// Name: public: virtual class CWnd __near * CBaseTabbedPane::FindBarByTabNumber(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CBaseTabbedPane::FindBarByTabNumber(CBaseTabbedPane *this, int nTabNum, int bGetWrappedBar)
{
  CMFCBaseTabCtrl **p_m_pTabWnd; // esi
  CObject *v4; // eax
  CObject *v5; // edi
  CObject *v6; // eax

  if ( nTabNum < 0 )
    return nullptr;
  p_m_pTabWnd = &this->m_pTabWnd;
  if ( nTabNum >= this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd) )
    return nullptr;
  v4 = (*p_m_pTabWnd)->GetTabWnd(this: *p_m_pTabWnd, a2: nTabNum);
  v5 = v4;
  if ( bGetWrappedBar != 0 && CObject::IsKindOf(this: v4, pClass: &CDockablePaneAdapter::classCDockablePaneAdapter) != 0 )
  {
    v6 = AfxDynamicDownCast(pClass: &CDockablePaneAdapter::classCDockablePaneAdapter, pObject: v5);
    return (CWnd *)v6->__vftable[78].GetRuntimeClass(this: v6);
  }
  return (CWnd *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x103F7248
// Name: protected: virtual void CBaseTabbedPane::StoreRecentDockSiteInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBaseTabbedPane::StoreRecentDockSiteInfo(CBaseTabbedPane *this)
{
  int v2; // ebx
  int i; // edi
  CWnd *v4; // eax
  CObject *v5; // eax

  v2 = this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd);
  for ( i = 0; i < v2; ++i )
  {
    v4 = this->m_pTabWnd->GetTabWnd(this: this->m_pTabWnd, a2: i);
    v5 = AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: v4);
    if ( v5 != nullptr )
      v5->__vftable[74].dtr_CObject(this: v5);
  }
  CDockablePane::StoreRecentDockSiteInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x10409588
// Name: protected: static int CMFCColorBar::CreatePalette(class CArray<unsigned long,unsigned long> const __near &,class CPalette __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCColorBar::CreatePalette(const CArray<unsigned long,unsigned long> *arColors, CPalette *palette)
{
  CPalette *v2; // ebx
  int v3; // esi
  void *v4; // eax
  int m_nSize; // edi
  unsigned int *v7; // ecx
  unsigned __int8 *p_peGreen; // eax
  HPALETTE v9; // eax
  CMFCColorBar::CreatePalette::__l19::<unnamed_type_pal> pal; // [esp+Ch] [ebp-19Ch] BYREF

  v2 = palette;
  v3 = 0;
  if ( palette != nullptr && palette->m_hObject != nullptr )
  {
    v4 = CGdiObject::Detach(this: palette);
    DeleteObject(ho: v4);
    if ( palette->m_hObject != nullptr )
LABEL_4:
      AfxThrowInvalidArgException();
  }
  if ( afxGlobalData.m_nBitsPerPixel != 8 )
    return 0;
  m_nSize = arColors->m_nSize;
  if ( m_nSize == 0 )
    return 0;
  if ( m_nSize > 100 )
    m_nSize = 100;
  pal.LogPalette.palVersion = 768;
  pal.LogPalette.palNumEntries = m_nSize;
  if ( m_nSize > 0 )
  {
    do
    {
      if ( v3 < 0 || v3 >= arColors->m_nSize )
        goto LABEL_4;
      v7 = &arColors->m_pData[v3];
      p_peGreen = &pal.LogPalette.palPalEntry[v3].peGreen;
      *(p_peGreen - 1) = *(_BYTE *)v7;
      *p_peGreen = *((_BYTE *)v7 + 1);
      ++v3;
      p_peGreen[1] = *((_BYTE *)v7 + 2);
      p_peGreen[2] = 0;
    }
    while ( v3 < m_nSize );
    v2 = palette;
  }
  v9 = CreatePalette(plpal: &pal.LogPalette);
  CGdiObject::Attach(this: v2, hObject: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10409664
// Name: protected: class CPalette __near * CMFCColorBar::SelectPalette(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPalette *__thiscall CMFCColorBar::SelectPalette(CMFCColorBar *this, CDC *pDC)
{
  CPalette *v2; // ecx
  void *v3; // eax
  CMFCColorButton *m_pParentBtn; // eax
  CPalette *m_pPalette; // eax
  CPalette *v7; // eax
  CPalette *p_m_Palette; // esi
  CPalette *v9; // esi

  if ( afxGlobalData.m_nBitsPerPixel == 8 )
  {
    m_pParentBtn = this->m_pParentBtn;
    if ( m_pParentBtn != nullptr && (m_pPalette = m_pParentBtn->m_pPalette) != nullptr )
    {
      v7 = CDC::SelectPalette(this: pDC, pPalette: m_pPalette, bForceBackground: false);
    }
    else
    {
      p_m_Palette = &this->m_Palette;
      if ( this == (CMFCColorBar *)-3528 || this->m_Palette.m_hObject == nullptr )
        CMFCColorBar::CreatePalette(arColors: &this->m_colors, palette: &this->m_Palette);
      v7 = CDC::SelectPalette(this: pDC, pPalette: p_m_Palette, bForceBackground: false);
    }
    v9 = v7;
    if ( v7 == nullptr )
      AfxThrowInvalidArgException();
    RealizePalette(hdc: pDC->m_hDC);
    return v9;
  }
  else
  {
    v2 = &this->m_Palette;
    if ( v2 != nullptr && v2->m_hObject != nullptr )
    {
      v3 = CGdiObject::Detach(this: v2);
      DeleteObject(ho: v3);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104096F0
// Name: protected: virtual void CMFCColorBar::AdjustLocations(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::AdjustLocations(CMFCColorBar *this)
{
  char *m_pszData; // eax
  int left; // edi
  int top; // esi
  bool v5; // zf
  __POSITION **m_pNodeHead; // eax
  __POSITION *v7; // edx
  __POSITION *v8; // eax
  CMFCToolBarColorButton *v9; // eax
  int cx; // edx
  int cy; // ecx
  int v12; // ecx
  int v13; // eax
  int *v14; // esi
  int v15; // eax
  int *v16; // esi
  CMFCToolBarButton_vtbl *v17; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-A4h]
  _DWORD v19[6]; // [esp+28h] [ebp-70h] BYREF
  int v20; // [esp+40h] [ebp-58h]
  int v21; // [esp+44h] [ebp-54h]
  _DWORD v22[3]; // [esp+48h] [ebp-50h] BYREF
  int v23; // [esp+54h] [ebp-44h]
  CMFCToolBarButton *pButton; // [esp+58h] [ebp-40h]
  __POSITION *pos; // [esp+5Ch] [ebp-3Ch]
  CMFCToolBarColorButton *pColorButton; // [esp+60h] [ebp-38h]
  int bIsOtherColor; // [esp+64h] [ebp-34h]
  int bPrevSeparator; // [esp+68h] [ebp-30h]
  int y; // [esp+6Ch] [ebp-2Ch]
  int x; // [esp+70h] [ebp-28h]
  CRect rectButton; // [esp+74h] [ebp-24h] BYREF
  CRect rectClient; // [esp+84h] [ebp-14h] BYREF

  if ( this != nullptr && this->m_hWnd != nullptr && IsWindow(hWnd: this->m_hWnd) && this->m_bInUpdateShadow == 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    InflateRect(
      lprc: &rectClient,
      dx: -(this->m_nHorzMargin + this->m_nHorzOffset),
      dy: -(this->m_nVertMargin + this->m_nVertOffset));
    m_pszData = this->m_strAutoColor.m_pszData;
    left = rectClient.left;
    top = rectClient.top;
    x = rectClient.left;
    y = rectClient.top;
    bPrevSeparator = 0;
    if ( *((_DWORD *)m_pszData - 3) == 0 || (v5 = this->m_ColorSelected == -1, bIsOtherColor = 0, !v5) )
      bIsOtherColor = 1;
    m_pNodeHead = (__POSITION **)this->m_Buttons.m_pNodeHead;
    if ( m_pNodeHead == nullptr )
    {
LABEL_9:
      CMFCToolBar::UpdateTooltips(this);
      return;
    }
    while ( 1 )
    {
      memset(&rectButton, 0, sizeof(rectButton));
      v7 = *m_pNodeHead;
      v8 = m_pNodeHead[2];
      v5 = (*(_BYTE *)&v8[36] & 1) == 0;
      pos = v7;
      pButton = (CMFCToolBarButton *)v8;
      if ( v5 )
      {
        v9 = (CMFCToolBarColorButton *)AfxDynamicDownCast(
                                         pClass: &CMFCToolBarColorButton::classCMFCToolBarColorButton,
                                         pObject: (CObject *)v8);
        pColorButton = v9;
        if ( v9 == nullptr )
          goto LABEL_47;
        if ( v9->m_bIsDocument == 0 || this->m_bShowDocColorsWhenDocked != 0 )
          goto LABEL_25;
        if ( this->IsFloating(this) != 0 )
        {
          v9 = pColorButton;
LABEL_25:
          if ( v9->m_bIsAutomatic != 0 || v9->m_bIsOther != 0 || v9->m_bIsLabel != 0 )
          {
            if ( left > rectClient.left )
            {
              top += this->m_nVertMargin + this->m_BoxSize.cy;
              y = top;
              left = rectClient.left;
            }
            if ( v9->m_bIsOther != 0 && bIsOtherColor != 0 )
            {
              v12 = rectClient.right - this->m_BoxSize.cx - rectClient.left;
              v23 = top + this->m_nRowHeight - this->m_nVertMargin / 2;
              v13 = v23 - this->m_BoxSize.cy - y;
              v22[1] = top;
              y += v13 / 2;
              v22[0] = left;
              v22[2] = left + v12;
              v14 = v22;
              x = left + v12;
            }
            else
            {
              v15 = this->m_nRowHeight - this->m_nVertMargin / 2;
              y += v15;
              v19[2] = left + rectClient.right - rectClient.left;
              v19[1] = top;
              v19[0] = left;
              v19[3] = v15 + top;
              v14 = v19;
              x = rectClient.left;
            }
            rectButton.left = *v14;
            v16 = v14 + 1;
            rectButton.top = *v16++;
            rectButton.right = *v16;
            rectButton.bottom = v16[1];
            if ( pColorButton->m_bIsOther != 0 )
              InflateRect(lprc: &rectButton, dx: this->m_nHorzMargin / -2, dy: this->m_nVertMargin / -2);
            bPrevSeparator = 0;
          }
          else
          {
            cx = this->m_BoxSize.cx;
            if ( cx + left > rectClient.right )
            {
              top += this->m_BoxSize.cy;
              x = rectClient.left;
              y = top;
              left = rectClient.left;
            }
            if ( v9->m_bIsOtherColor == 0 || bIsOtherColor != 0 )
            {
              cy = this->m_BoxSize.cy;
              x += cx;
              bPrevSeparator = 0;
              rectButton.left = left;
              rectButton.top = top;
              rectButton.right = left + cx;
              rectButton.bottom = top + cy;
            }
            else
            {
              SetRectEmpty(lprc: &rectButton);
            }
            if ( pColorButton->m_Color == this->m_ColorSelected && pColorButton->m_bIsOtherColor == 0 )
              bIsOtherColor = 0;
          }
          goto LABEL_46;
        }
        SetRectEmpty(lprc: &rectButton);
      }
      else
      {
        if ( bPrevSeparator != 0 )
        {
          SetRectEmpty(lprc: &rectButton);
        }
        else
        {
          if ( left > rectClient.left )
          {
            left = rectClient.left;
            top += this->m_nVertMargin + this->m_BoxSize.cy;
            y = top;
          }
          v19[5] = top;
          v19[4] = left;
          v21 = top + 2;
          y += 4;
          v20 = left + rectClient.right - rectClient.left;
          rectButton.left = left;
          rectButton.top = top;
          rectButton.right = v20;
          rectButton.bottom = top + 2;
          x = rectClient.left;
        }
        bPrevSeparator = 1;
      }
LABEL_46:
      v17 = pButton->__vftable;
      pButton->m_rect = rectButton;
      ((void (*)(void))v17->OnMove)();
      top = y;
      left = x;
LABEL_47:
      if ( pos == nullptr )
        goto LABEL_9;
      m_pNodeHead = (__POSITION **)pos;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10409A63
// Name: protected: int CMFCColorBar::GetExtraHeight(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::GetExtraHeight(CMFCColorBar *this, int nNumColumns)
{
  int m_nRowHeight; // ebx
  int v4; // eax

  m_nRowHeight = 0;
  if ( *((_DWORD *)this->m_strAutoColor.m_pszData - 3) != 0 )
  {
    m_nRowHeight = this->m_nRowHeight;
  }
  else if ( *((_DWORD *)this->m_strOtherColor.m_pszData - 3) != 0 )
  {
    m_nRowHeight = this->m_nVertMargin;
  }
  if ( *((_DWORD *)this->m_strOtherColor.m_pszData - 3) != 0 )
    m_nRowHeight += this->m_nRowHeight;
  if ( *((_DWORD *)this->m_strDocColors.m_pszData - 3) != 0
    && this->m_lstDocColors.m_nCount != 0
    && (this->m_bShowDocColorsWhenDocked != 0 || this->IsFloating(this) != 0) )
  {
    v4 = this->m_lstDocColors.m_nCount / nNumColumns;
    if ( this->m_lstDocColors.m_nCount % nNumColumns != 0 )
      ++v4;
    m_nRowHeight += this->m_nRowHeight + this->m_nVertMargin + v4 * this->m_BoxSize.cy + 4;
  }
  return m_nRowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10409B02
// Name: protected: virtual void CMFCColorBar::DoPaint(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::DoPaint(CMFCColorBar *this, CDC *pDC)
{
  CPalette *v3; // edi

  v3 = CMFCColorBar::SelectPalette(this, pDC);
  CMFCToolBar::DoPaint(this, pDCPaint: pDC);
  if ( v3 != nullptr )
    CDC::SelectPalette(this: pDC, pPalette: v3, bForceBackground: false);
}

//------------------------------------------------------------------------------
// Address: 0x10409B34
// Name: public: virtual int CMFCColorBar::Create(class CWnd __near *,unsigned long,unsigned int,class CPalette __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::Create(
        CMFCColorBar *this,
        CWnd *pParentWnd,
        unsigned int dwStyle,
        unsigned int nID,
        CPalette *pPalette,
        int nColumns,
        int nRowsDockHorz,
        int nColDockVert)
{
  CMFCColorBar *v8; // esi

  v8 = this;
  if ( this->m_colors.m_nSize == 0 )
  {
    this->m_nNumColumns = nColumns;
    this->m_nNumColumnsVert = nColDockVert;
    this->m_nNumRowsHorz = nRowsDockHorz;
    CMFCColorBar::InitColors(pPalette, arColors: &this->m_colors);
    this = v8;
  }
  return CMFCToolBar::Create(this, pParentWnd, dwStyle, nID);
}

//------------------------------------------------------------------------------
// Address: 0x10409B84
// Name: protected: virtual class CSize CMFCColorBar::CalcSize(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCColorBar::CalcSize(CMFCColorBar *this, CSize *result, int bVertDock)
{
  int ExtraHeight; // eax
  int v5; // ecx
  CSize sizeGrid; // [esp+4h] [ebp-8h] BYREF

  CMFCColorBar::GetColorGridSize(this, result: &sizeGrid, bVertDock);
  ExtraHeight = CMFCColorBar::GetExtraHeight(this, nNumColumns: sizeGrid.cx);
  v5 = sizeGrid.cy * this->m_BoxSize.cy + ExtraHeight + 2 * this->m_nHorzMargin;
  result->cx = sizeGrid.cx * this->m_BoxSize.cx + 2 * this->m_nVertMargin;
  result->cy = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409BD9
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCColorBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCColorBar::GetMessageMap(CMFCColorBar *this)
{
  return (const AFX_MSGMAP *)&off_1068BA54;
}

//------------------------------------------------------------------------------
// Address: 0x10409BDF
// Name: protected: virtual int CMFCColorBar::OnSendCommand(class CMFCToolBarButton const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorBar::OnSendCommand(CMFCColorBar *this, const CMFCToolBarButton *pButton)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  CMFCPopupMenu *v5; // eax
  unsigned int *v6; // eax
  HWND v8; // ecx
  CFrameWnd *TopLevelFrame; // eax
  CFrameWnd *v10; // eax
  unsigned int m_ColorSelected; // eax
  CFrameWnd *v12; // ecx
  CFrameWnd *v13; // eax
  CMFCRibbonColorButton *m_pParentRibbonBtn; // ecx
  HWND v15; // eax
  CWnd *v16; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObject *v18; // eax
  unsigned int v19; // ebx
  WPARAM v20; // ebx
  CWnd *Owner; // eax
  CFrameWnd *v22; // ecx
  CFrameWnd *v23; // eax
  unsigned int m_nCommandID; // [esp-8h] [ebp-4Ch]
  HWND__ *m_hWnd; // [esp-4h] [ebp-48h]
  CObject *data; // [esp-4h] [ebp-48h]
  CObList listButtons; // [esp+10h] [ebp-34h] BYREF
  CMFCPopupMenu *pParentMenu; // [esp+2Ch] [ebp-18h]
  CMFCColorMenuButton *pColorMenuButton; // [esp+30h] [ebp-14h]
  unsigned int color[3]; // [esp+34h] [ebp-10h] BYREF
  int v31; // [esp+40h] [ebp-4h]

  if ( this->m_pParentBtn != nullptr || this->m_pWndPropList != nullptr )
    ReleaseCapture();
  m_hWnd = this->m_hWnd;
  color[0] = -1;
  pColorMenuButton = nullptr;
  Parent = GetParent(hWnd: m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v4);
  pParentMenu = v5;
  if ( v5 != nullptr )
    pColorMenuButton = (CMFCColorMenuButton *)AfxDynamicDownCast(
                                                pClass: &CMFCColorMenuButton::classCMFCColorMenuButton,
                                                pObject: v5->m_pParentBtn);
  v6 = (unsigned int *)AfxDynamicDownCast(
                         pClass: &CMFCToolBarColorButton::classCMFCToolBarColorButton,
                         pObject: &pButton->CObject);
  if ( v6 == nullptr )
    goto LABEL_40;
  if ( v6[32] != 0 )
    return 0;
  if ( v6[31] == 0 )
  {
    if ( v6[30] != 0 )
      color[0] = -1;
    else
      color[0] = v6[28];
    goto LABEL_40;
  }
  CMFCPopupMenuBar::SetInCommand(this, bInCommand: 1);
  if ( pParentMenu != nullptr )
  {
    CWnd::ShowWindow(this: pParentMenu, nCmdShow: 0);
    v8 = g_pTopLevelFrame;
    if ( g_pTopLevelFrame != nullptr )
    {
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    }
    else
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this);
      v8 = g_pTopLevelFrame;
    }
    if ( TopLevelFrame != nullptr )
    {
      if ( v8 != nullptr )
        v10 = (CFrameWnd *)v8;
      else
        v10 = CWnd::GetTopLevelFrame(this);
      CMFCPopupMenu::ActivatePopupMenu(pTopFrame: v10, pPopupMenu: nullptr);
    }
  }
  pParentMenu = (CMFCPopupMenu *)this->m_hWnd;
  InvalidateRect(hWnd: (HWND)pParentMenu, lpRect: &pButton->m_rect, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
  m_ColorSelected = this->m_ColorSelected;
  if ( m_ColorSelected == -1 )
    m_ColorSelected = this->m_ColorAutomatic;
  if ( this->OpenColorDialog(this, a2: m_ColorSelected, a3: color) != 0 )
  {
    if ( !IsWindow(hWnd: (HWND)pParentMenu) )
      return 1;
    CMFCPopupMenuBar::SetInCommand(this, bInCommand: 0);
LABEL_40:
    if ( pColorMenuButton != nullptr )
    {
      pColorMenuButton->SetColor(this: pColorMenuButton, a2: color[0], a3: 1);
      CMFCPopupMenuBar::InvokeMenuCommand(this, uiCmdId: pColorMenuButton->m_nID, pMenuItem: pColorMenuButton);
      return 1;
    }
    if ( this->m_pParentBtn != nullptr )
    {
      this->m_pParentBtn->UpdateColor(this: this->m_pParentBtn, a2: color[0]);
    }
    else
    {
      m_pParentRibbonBtn = this->m_pParentRibbonBtn;
      if ( m_pParentRibbonBtn != nullptr )
      {
        CMFCRibbonColorButton::UpdateColor(this: m_pParentRibbonBtn, color: color[0]);
      }
      else
      {
        if ( this->m_pWndPropList == nullptr )
        {
          CMFCColorBar::SetColor(this, color: (CObject_vtbl *)color[0]);
          CObList::CObList(this: &listButtons, nBlockSize: 10);
          m_nCommandID = this->m_nCommandID;
          v31 = 0;
          if ( CMFCToolBar::GetCommandButtons(uiCmd: m_nCommandID, &listButtons) > 0 )
          {
            m_pNodeHead = listButtons.m_pNodeHead;
            while ( m_pNodeHead != nullptr )
            {
              data = m_pNodeHead->data;
              m_pNodeHead = m_pNodeHead->pNext;
              v18 = AfxDynamicDownCast(pClass: &CMFCColorMenuButton::classCMFCColorMenuButton, pObject: data);
              if ( v18 != nullptr )
                ((void (__thiscall *)(CObject *, unsigned int, _DWORD))v18->__vftable[20].Serialize)(
                  a1: v18,
                  a2: color[0],
                  a3: 0);
            }
          }
          v19 = color[0];
          *CMap<unsigned int,unsigned int,unsigned long,unsigned long>::operator[](
             this: &CMFCColorMenuButton::m_ColorsByID,
             key: this->m_nCommandID) = v19;
          v20 = this->m_nCommandID;
          Owner = CWnd::GetOwner(this);
          SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: v20, lParam: 0);
          v22 = (CFrameWnd *)g_pTopLevelFrame;
          if ( g_pTopLevelFrame != nullptr )
          {
            v23 = (CFrameWnd *)g_pTopLevelFrame;
          }
          else
          {
            v23 = CWnd::GetTopLevelFrame(this);
            v22 = (CFrameWnd *)g_pTopLevelFrame;
          }
          if ( v23 != nullptr )
          {
            if ( v22 == nullptr )
              v22 = CWnd::GetTopLevelFrame(this);
            CWnd::SetFocus(this: v22);
          }
          v31 = -1;
          CObList::~CObList(this: &listButtons);
          return 1;
        }
        this->m_pWndPropList->UpdateColor(this: this->m_pWndPropList, a2: color[0]);
      }
    }
    goto LABEL_49;
  }
  if ( IsWindow(hWnd: (HWND)pParentMenu) )
  {
    CMFCPopupMenuBar::SetInCommand(this, bInCommand: 0);
    if ( this->m_pParentBtn == nullptr && this->m_pWndPropList == nullptr && this->m_pParentRibbonBtn == nullptr )
    {
      if ( pColorMenuButton != nullptr )
      {
        CMFCPopupMenuBar::InvokeMenuCommand(this, uiCmdId: 0, pMenuItem: pColorMenuButton);
      }
      else
      {
        v12 = (CFrameWnd *)g_pTopLevelFrame;
        if ( g_pTopLevelFrame != nullptr )
        {
          v13 = (CFrameWnd *)g_pTopLevelFrame;
        }
        else
        {
          v13 = CWnd::GetTopLevelFrame(this);
          v12 = (CFrameWnd *)g_pTopLevelFrame;
        }
        if ( v13 != nullptr )
        {
          if ( v12 == nullptr )
            v12 = CWnd::GetTopLevelFrame(this);
          CWnd::SetFocus(this: v12);
        }
      }
      return 1;
    }
LABEL_49:
    v15 = GetParent(hWnd: this->m_hWnd);
    v16 = CWnd::FromHandle(hWnd: v15);
    SendMessageA(hWnd: v16->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1040C3DA
// Name: protected: static struct AFX_MSGMAP const __near * CMFCSpinButtonCtrl::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCSpinButtonCtrl::GetThisMessageMap(CMFCSpinButtonCtrl *this)
{
  return &messageMap_46;
}

//------------------------------------------------------------------------------
// Address: 0x1040C3E0
// Name: public: virtual struct CRuntimeClass __near * CMFCPropertyGridToolTipCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCPropertyGridToolTipCtrl::GetRuntimeClass(CMFCPropertyGridToolTipCtrl *this)
{
  return &CMFCPropertyGridToolTipCtrl::classCMFCPropertyGridToolTipCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1040CCD5
// Name: protected: void CMFCHeaderCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnCancelMode(CMFCHeaderCtrl *this)
{
  CWnd::Default(this);
  if ( this->m_nHighlightedItem >= 0 )
  {
    this->m_nHighlightedItem = -1;
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CD02
// Name: protected: void CMFCHeaderCtrl::CommonInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::CommonInit(CMFCHeaderCtrl *this)
{
  HWND i; // eax
  CWnd *v3; // eax
  CWnd *v4; // edi

  for ( i = GetParent(hWnd: this->m_hWnd); ; i = GetParent(hWnd: v4->m_hWnd) )
  {
    v3 = CWnd::FromHandle(hWnd: i);
    v4 = v3;
    if ( v3 == nullptr )
      break;
    if ( CObject::IsKindOf(this: v3, pClass: &CDialog::classCDialog) != 0 )
    {
      this->m_bIsDlgControl = 1;
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CD45
// Name: protected: long CMFCHeaderCtrl::OnSetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCHeaderCtrl::OnSetFont(CMFCHeaderCtrl *this, HFONT__ *wParam, __int16 lParam)
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
// Address: 0x1040CD7A
// Name: public: CMFCHeaderCtrl::CMFCHeaderCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCHeaderCtrl *__thiscall CMFCHeaderCtrl::CMFCHeaderCtrl(CMFCHeaderCtrl *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCHeaderCtrl_vtbl *)&CMFCHeaderCtrl::`vftable';
  CMap<int,int,int,int>::CMap<int,int,int,int>(this: &this->m_mapColumnsStatus, nBlockSize: 10);
  this->m_nHighlightedItem = -1;
  this->m_bIsMousePressed = 0;
  this->m_bMultipleSort = 0;
  this->m_bTracked = 0;
  this->m_bIsDlgControl = 0;
  this->m_hFont = nullptr;
  this->m_bAscending = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040CDC9
// Name: public: virtual CMFCHeaderCtrl::~CMFCHeaderCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::~CMFCHeaderCtrl(CMFCHeaderCtrl *this)
{
  CMap<unsigned int,unsigned int,unsigned long,unsigned long> *p_m_mapColumnsStatus; // ecx

  this->__vftable = (CMFCHeaderCtrl_vtbl *)&CMFCHeaderCtrl::`vftable';
  p_m_mapColumnsStatus = (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapColumnsStatus;
  p_m_mapColumnsStatus->__vftable = (CMap<unsigned int,unsigned int,unsigned long,unsigned long>_vtbl *)&CMap<int,int,int,int>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: p_m_mapColumnsStatus);
  CHeaderCtrl::~CHeaderCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040CE03
// Name: protected: int CMFCHeaderCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCHeaderCtrl::OnCreate(CMFCHeaderCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    CMFCHeaderCtrl::CommonInit(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040DBC4
// Name: protected: void CMFCToolBarComboBoxEdit::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxEdit::OnContextMenu(CMFCToolBarComboBoxEdit *this, CWnd *pWnd, CPoint point)
{
  CMFCToolBarComboBoxEdit *v3; // esi
  HWND Parent; // eax
  CWnd *v5; // ebx
  HINSTANCE__ *m_hCurrentResourceHandle; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  HWND m_hWnd; // ecx

  v3 = this;
  if ( this->m_combo->m_uiMenuResID == 0 )
    goto LABEL_4;
  Parent = GetParent(hWnd: pWnd->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  if ( m_hCurrentResourceHandle == nullptr
    || (MenuW = LoadMenuW(hInstance: m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)LOWORD(v3->m_combo->m_uiMenuResID))) == nullptr
    || (SubMenu = GetSubMenu(hMenu: MenuW, nPos: 0)) == nullptr )
  {
    this = v3;
LABEL_4:
    CWnd::Default(this);
    return;
  }
  if ( afxContextMenuManager != nullptr )
  {
    afxContextMenuManager->ShowPopupMenu(
      this: afxContextMenuManager,
      a2: SubMenu,
      a3: point.x,
      a4: point.y,
      a5: v5,
      a6: 0,
      a7: 1,
      a8: 0);
  }
  else
  {
    if ( v5 != nullptr )
      m_hWnd = v5->m_hWnd;
    else
      m_hWnd = nullptr;
    TrackPopupMenu(hMenu: SubMenu, uFlags: 4u, x: point.x, y: point.y, nReserved: 0, hWnd: m_hWnd, prcRect: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040DC67
// Name: public: virtual void CMFCToolBarComboBoxButton::OnGlobalFontsChanged(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::OnGlobalFontsChanged(CMFCToolBarComboBoxButton *this)
{
  CEdit *m_pWndEdit; // eax
  CComboBox *m_pWndCombo; // eax

  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
    SendMessageA(hWnd: m_pWndEdit->m_hWnd, Msg: 0x30u, wParam: (WPARAM)afxGlobalData.fontRegular.m_hObject, lParam: 1);
  m_pWndCombo = this->m_pWndCombo;
  if ( m_pWndCombo != nullptr && m_pWndCombo->m_hWnd != nullptr )
    SendMessageA(hWnd: m_pWndCombo->m_hWnd, Msg: 0x30u, wParam: (WPARAM)afxGlobalData.fontRegular.m_hObject, lParam: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1040DCB6
// Name: public: virtual void CMFCToolBarComboBoxButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::CopyFrom(CMFCToolBarComboBoxButton *this, const CMFCToolBarButton *s)
{
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_bVisible; // ebx
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax
  CWnd *m_pWndParent; // ebx
  CFrameWnd *m_pOuterUnknown; // [esp-4h] [ebp-10h]

  CMFCToolBarButton::CopyFrom(this, src: s);
  CStringList::RemoveAll(this: &this->m_lstItems);
  m_bVisible = (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)s[1].m_bVisible;
  while ( m_bVisible != nullptr )
  {
    v4 = m_bVisible;
    m_bVisible = (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)m_bVisible->m_pszData;
    CStringList::AddTail(this: &this->m_lstItems, newElement: v4 + 2);
  }
  this->ClearData(this);
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstItemData);
  m_pWndParent = s[1].m_pWndParent;
  while ( m_pWndParent != nullptr )
  {
    m_pOuterUnknown = (CFrameWnd *)m_pWndParent->m_pOuterUnknown;
    m_pWndParent = (CWnd *)m_pWndParent->__vftable;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstItemData,
      newElement: m_pOuterUnknown);
  }
  this->DuplicateData(this);
  this->m_dwStyle = s[1].m_bDragFromCollection;
  this->m_iWidth = (int)s[1].__vftable;
  this->m_iSelIndex = s[1].m_bUserButton;
  this->m_nDropDownHeight = s[1].m_bText;
  this->m_uiMenuResID = s[1].m_bTextBelow;
  this->m_bIsRibbon = s[1].m_bWholeText;
}

//------------------------------------------------------------------------------
// Address: 0x1040DD74
// Name: public: int CMFCToolBarComboBoxButton::FindItem(char const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxButton::FindItem(CMFCToolBarComboBoxButton *this, const char *lpszText)
{
  CStringList::CNode *m_pNodeHead; // esi
  int i; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax

  if ( lpszText == nullptr )
    AfxThrowInvalidArgException();
  m_pNodeHead = this->m_lstItems.m_pNodeHead;
  for ( i = 0; ; ++i )
  {
    if ( m_pNodeHead == nullptr )
      return -1;
    v4 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)m_pNodeHead;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CompareNoCase(this: v4 + 2, psz: lpszText) == 0 )
      break;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1040DDB9
// Name: public: virtual class CMFCToolBarComboBoxEdit __near * CMFCToolBarComboBoxButton::CreateEdit(class CWnd __near *,class CRect const __near &,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarComboBoxEdit *__thiscall CMFCToolBarComboBoxButton::CreateEdit(
        CMFCToolBarComboBoxButton *this,
        CWnd *pWndParent,
        const CRect *rect,
        unsigned int dwEditStyle)
{
  CMFCToolBarComboBoxEdit *v5; // ecx
  CMFCToolBarComboBoxEdit *v6; // esi

  v5 = (CMFCToolBarComboBoxEdit *)operator new(nSize: 0x7Cu);
  if ( v5 != nullptr )
    v6 = CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit(this: v5, combo: this);
  else
    v6 = nullptr;
  if ( CEdit::Create(this: v6, dwStyle: dwEditStyle, rect, pParentWnd: pWndParent, nID: this->m_nID) != 0 )
    return v6;
  if ( v6 != nullptr )
    ((void (__thiscall *)(CMFCToolBarComboBoxEdit *, int))v6->dtr_CObject)(a1: v6, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1040DE1E
// Name: public: virtual int CMFCToolBarComboBoxEdit::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxEdit::PreTranslateMessage(CMFCToolBarComboBoxEdit *this, tagMSG *pMsg)
{
  CComboBox *m_pWndCombo; // eax
  CComboBox *v5; // eax
  unsigned int wParam; // ecx
  CComboBox *v7; // eax
  LPARAM m_hWnd; // edi
  CMFCToolBarComboBoxButton *m_combo; // esi
  CWnd *v10; // ecx
  WPARAM m_nID_low; // esi
  CWnd *Owner; // eax
  CComboBox *v13; // eax
  HWND v14; // eax
  CMFCToolBarComboBoxButton *v15; // esi
  HWND v16; // eax
  CWnd *v17; // eax
  CComboBox *v18; // eax
  CFrameWnd *NextDlgTabItem; // eax
  HWND Parent; // eax
  HWND v21; // eax
  CWnd *v22; // eax

  if ( pMsg->message == 522 )
  {
    m_pWndCombo = this->m_combo->m_pWndCombo;
    if ( m_pWndCombo != nullptr && SendMessageA(hWnd: m_pWndCombo->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0) != 0 )
    {
LABEL_4:
      SendMessageA(
        hWnd: this->m_combo->m_pWndCombo->m_hWnd,
        Msg: pMsg->message,
        wParam: pMsg->wParam,
        lParam: pMsg->lParam);
      return 1;
    }
  }
  if ( pMsg->message == 256 )
  {
    if ( GetKeyState(nVirtKey: 18) >= 0 && GetKeyState(nVirtKey: 17) >= 0 )
    {
      v5 = this->m_combo->m_pWndCombo;
      if ( v5 != nullptr )
      {
        wParam = pMsg->wParam;
        if ( wParam == 13
          || wParam > 0x20
          && (wParam <= 0x24 || wParam == 38 || wParam == 40)
          && SendMessageA(hWnd: v5->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0) != 0 )
        {
          CWnd::SetFocus(this);
          if ( SendMessageA(hWnd: this->m_combo->m_pWndCombo->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0) == 0 )
          {
            if ( CWnd::GetOwner(this: this->m_combo->m_pWndCombo) != nullptr )
            {
              CWnd::GetWindowTextA(this, rString: &this->m_combo->m_strEdit);
              v7 = this->m_combo->m_pWndCombo;
              if ( v7 != nullptr )
                m_hWnd = (LPARAM)v7->m_hWnd;
              else
                m_hWnd = 0;
              m_combo = this->m_combo;
              v10 = m_combo->m_pWndCombo;
              m_nID_low = LOWORD(m_combo->m_nID);
              Owner = CWnd::GetOwner(this: v10);
              PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: m_nID_low, lParam: m_hWnd);
            }
            return 1;
          }
          goto LABEL_4;
        }
      }
    }
    if ( pMsg->wParam == 9 )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      if ( CWnd::FromHandle(hWnd: Parent) == nullptr )
        return CWnd::PreTranslateMessage(this, pMsg);
      v21 = GetParent(hWnd: this->m_hWnd);
      v22 = CWnd::FromHandle(hWnd: v21);
      NextDlgTabItem = (CFrameWnd *)CWnd::GetNextDlgTabItem(this: v22, pWndCtl: this, bPrevious: 0);
    }
    else
    {
      if ( pMsg->wParam != 27 )
      {
        if ( (pMsg->wParam == 38 || pMsg->wParam == 40)
          && GetKeyState(nVirtKey: 18) >= 0
          && GetKeyState(nVirtKey: 17) >= 0 )
        {
          v13 = this->m_combo->m_pWndCombo;
          if ( v13 != nullptr )
          {
            if ( SendMessageA(hWnd: v13->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0) == 0 )
            {
              SendMessageA(hWnd: this->m_combo->m_pWndCombo->m_hWnd, Msg: 0x14Fu, wParam: 1u, lParam: 0);
              v14 = GetParent(hWnd: this->m_combo->m_pWndCombo->m_hWnd);
              if ( CWnd::FromHandle(hWnd: v14) != nullptr )
              {
                v15 = this->m_combo;
                v16 = GetParent(hWnd: v15->m_pWndCombo->m_hWnd);
                v17 = CWnd::FromHandle(hWnd: v16);
                InvalidateRect(hWnd: v17->m_hWnd, lpRect: &v15->m_rectCombo, bErase: true);
              }
            }
            return 1;
          }
        }
        return CWnd::PreTranslateMessage(this, pMsg);
      }
      v18 = this->m_combo->m_pWndCombo;
      if ( v18 != nullptr )
        SendMessageA(hWnd: v18->m_hWnd, Msg: 0x14Fu, wParam: 0, lParam: 0);
      if ( CWnd::GetTopLevelFrame(this) == nullptr )
        return CWnd::PreTranslateMessage(this, pMsg);
      NextDlgTabItem = CWnd::GetTopLevelFrame(this);
    }
    CWnd::SetFocus(this: NextDlgTabItem);
    return 1;
  }
  return CWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1040E0C8
// Name: public: struct __POSITION __near * CList<unsigned long,unsigned long>::InsertBefore(struct __POSITION __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__POSITION *__thiscall CList<unsigned long,unsigned long>::InsertBefore(
        CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *this,
        __POSITION *position,
        CMFCPropertyGridProperty *newElement)
{
  __POSITION *result; // eax
  _DWORD *v5; // ecx

  if ( position == nullptr )
    return CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::AddHead(this, newElement);
  result = (__POSITION *)CList<unsigned int,unsigned int>::NewNode(
                           (CList<HWND__ *,HWND__ * &> *)this,
                           pPrev: *(CList<HWND__ *,HWND__ * &>::CNode **)&position[4],
                           pNext: (CList<HWND__ *,HWND__ * &>::CNode *)position);
  *(_DWORD *)&result[8] = newElement;
  v5 = *(_DWORD **)&position[4];
  if ( v5 != nullptr )
    *v5 = result;
  else
    this->m_pNodeHead = (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *)result;
  *(_DWORD *)&position[4] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040E108
// Name: public: CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarComboBoxButton *__thiscall CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton(
        CMFCToolBarComboBoxButton *this)
{
  CAfxStringMgr *StringManager; // eax

  CMFCToolBarButton::CMFCToolBarButton(this);
  this->__vftable = (CMFCToolBarComboBoxButton_vtbl *)&CMFCToolBarComboBoxButton::`vftable';
  this->m_rectCombo.left = 0;
  this->m_rectCombo.top = 0;
  this->m_rectCombo.right = 0;
  this->m_rectCombo.bottom = 0;
  this->m_rectButton.left = 0;
  this->m_rectButton.top = 0;
  this->m_rectButton.right = 0;
  this->m_rectButton.bottom = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strEdit, pStringMgr: StringManager);
  CStringList::CStringList(this: &this->m_lstItems, nBlockSize: 10);
  CList<unsigned long,unsigned long>::CList<unsigned long,unsigned long>(this: &this->m_lstItemData, nBlockSize: 10);
  this->m_dwStyle = 1344275459;
  this->m_iWidth = 150;
  CMFCToolBarComboBoxButton::Initialize(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10416F95
// Name: protected: void CMFCRibbonPanelMenuBar::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnLButtonUp(CMFCRibbonPanelMenuBar *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // ebx
  CMFCRibbonCategory *m_pCategory; // ecx

  if ( this->m_bAutoCommandTimer != 0 )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 3u);
    this->m_bAutoCommandTimer = 0;
    this->m_pPressed = nullptr;
    SetRectEmpty(lprc: &this->m_rectAutoCommand);
  }
  m_hWnd = this->m_hWnd;
  CMFCPopupMenuBar::OnLButtonUp(this, nFlags, point);
  if ( IsWindow(hWnd: m_hWnd) )
  {
    m_pCategory = this->m_pCategory;
    if ( m_pCategory != nullptr )
      ((void (__thiscall *)(CMFCRibbonCategory *, int, int))m_pCategory->OnLButtonUp)(
        a1: m_pCategory,
        a2: point.x,
        a3: point.y);
    else
      ((void (__thiscall *)(CMFCRibbonPanel *, int, int))this->m_pPanel->MouseButtonUp)(
        a1: this->m_pPanel,
        a2: point.x,
        a3: point.y);
    if ( IsWindow(hWnd: m_hWnd) )
    {
      GetCursorPos(lpPoint: &point);
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
      CMFCRibbonPanelMenuBar::OnMouseMove(this, nFlags, point);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417044
// Name: protected: void CMFCRibbonPanelMenuBar::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnLButtonDown(CMFCRibbonPanelMenuBar *this, unsigned int nFlags, CPoint point)
{
  CMFCRibbonButton *DroppedDown; // eax
  CRect *p_m_rectAutoCommand; // edi
  CMFCRibbonCategory *m_pCategory; // ecx
  int v7; // eax
  CMFCRibbonBaseElement *v8; // ebx
  CRect *p_m_rect; // esi
  int *p_top; // edi

  CMFCPopupMenuBar::OnLButtonDown(this, nFlags, point);
  DroppedDown = CMFCRibbonPanelMenuBar::GetDroppedDown(this);
  if ( DroppedDown != nullptr )
    DroppedDown->ClosePopupMenu(this: DroppedDown);
  CMFCRibbonPanelMenuBar::OnMouseMove(this, nFlags, point);
  this->m_pPressed = nullptr;
  p_m_rectAutoCommand = &this->m_rectAutoCommand;
  SetRectEmpty(lprc: &this->m_rectAutoCommand);
  m_pCategory = this->m_pCategory;
  nFlags = (unsigned int)this->m_hWnd;
  if ( m_pCategory != nullptr )
    v7 = ((int (__thiscall *)(CMFCRibbonCategory *, int, int))m_pCategory->OnLButtonDown)(
           a1: m_pCategory,
           a2: point.x,
           a3: point.y);
  else
    v7 = ((int (__thiscall *)(CMFCRibbonPanel *, int, int))this->m_pPanel->MouseButtonDown)(
           a1: this->m_pPanel,
           a2: point.x,
           a3: point.y);
  v8 = (CMFCRibbonBaseElement *)v7;
  if ( IsWindow(hWnd: (HWND)nFlags) )
  {
    this->m_pPressed = v8;
    if ( v8 != nullptr )
    {
      nFlags = 100;
      if ( v8->IsAutoRepeatMode(this: v8, a2: (int *)&nFlags) != 0 )
      {
        SetTimer(hWnd: this->m_hWnd, nIDEvent: 3u, uElapse: nFlags, lpTimerFunc: nullptr);
        this->m_bAutoCommandTimer = 1;
        p_m_rect = &this->m_pPressed->m_rect;
        p_m_rectAutoCommand->left = p_m_rect->left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        p_top = &p_m_rectAutoCommand->top;
        *p_top = p_m_rect->left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        *++p_top = p_m_rect->left;
        p_top[1] = p_m_rect->top;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041711D
// Name: protected: void CMFCRibbonPanelMenuBar::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnLButtonDblClk(
        CMFCRibbonPanelMenuBar *this,
        unsigned int nFlags,
        CPoint point)
{
  CMFCRibbonButton *DroppedDown; // eax
  CMFCRibbonBaseElement *v5; // eax

  CMFCPopupMenuBar::OnLButtonDblClk(this, nFlags, point);
  if ( this->IsRibbonPanelInRegularMode(this) != 0 )
  {
    DroppedDown = CMFCRibbonPanelMenuBar::GetDroppedDown(this);
    if ( DroppedDown != nullptr )
      DroppedDown->ClosePopupMenu(this: DroppedDown);
  }
  v5 = CMFCRibbonPanelMenuBar::HitTest(this, point);
  if ( v5 != nullptr )
    ((void (__thiscall *)(CMFCRibbonBaseElement *, int, int))v5->OnLButtonDblClk)(a1: v5, a2: point.x, a3: point.y);
}

//------------------------------------------------------------------------------
// Address: 0x1041717C
// Name: public: virtual void CMFCRibbonPanelMenuBar::OnClickButton(class CMFCRibbonButton __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnClickButton(
        CMFCRibbonPanelMenuBar *this,
        CMFCRibbonButton *pButton,
        CPoint __formal)
{
  CMFCRibbonPanel *m_pPanel; // eax
  int v5; // edi
  HWND v6; // eax
  CWnd *v7; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  CMFCPopupMenu *v10; // eax
  CMFCPopupMenu *ParentPopupMenu; // eax
  CObject *v12; // eax
  CFrameWnd *v13; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-34h]
  RECT rcUpdate; // [esp+10h] [ebp-14h] BYREF

  rcUpdate.left = pButton->m_rect.left;
  rcUpdate.top = pButton->m_rect.top;
  pButton->m_bIsPressed = 0;
  pButton->m_bIsHighlighted = 0;
  rcUpdate.right = pButton->m_rect.right;
  m_hWnd = this->m_hWnd;
  rcUpdate.bottom = pButton->m_rect.bottom;
  RedrawWindow(hWnd: m_hWnd, lprcUpdate: &rcUpdate, hrgnUpdate: nullptr, flags: 0x105u);
  m_pPanel = this->m_pPanel;
  if ( m_pPanel == nullptr
    || m_pPanel->m_pPaletteButton == nullptr
    || m_pPanel->m_pPaletteButton->OnClickPaletteSubItem(this: m_pPanel->m_pPaletteButton, a2: pButton, a3: this) == 0 )
  {
    v5 = CMFCRibbonBaseElement::NotifyCommand(this: pButton, bWithDelay: 1);
    if ( this->m_bIsFloaty == 0
      || (v6 = GetParent(hWnd: this->m_hWnd),
          v7 = CWnd::FromHandle(hWnd: v6),
          AfxDynamicDownCast(pClass: &CMFCRibbonMiniToolBar::classCMFCRibbonMiniToolBar, pObject: v7) == nullptr) )
    {
      if ( v5 != 0 )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v9 = CWnd::FromHandle(hWnd: Parent);
        v10 = (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu, pObject: v9);
        if ( v10 != nullptr )
        {
          ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this: v10);
          v12 = AfxDynamicDownCast(pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu, pObject: ParentPopupMenu);
          if ( v12 != nullptr )
            v12[1983].__vftable = (CObject_vtbl *)1;
        }
      }
      v13 = AFXGetParentFrame(pWnd: this);
      v13->DestroyWindow(this: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417282
// Name: public: virtual void CMFCRibbonPanelMenuBar::OnChangeHighlighted(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnChangeHighlighted(CMFCRibbonPanelMenuBar *this, CMFCRibbonBaseElement *pHot)
{
  CMFCRibbonPanel *m_pPanel; // ecx
  CMFCRibbonBaseElement *DroppedDown; // eax
  CMFCRibbonPanelMenu *v5; // esi
  CMFCRibbonButton *v6; // eax
  HWND Parent; // eax
  CWnd *v8; // eax
  const tagMSG *CurrentMessage; // eax
  CFrameWnd *TopLevelFrame; // eax
  CMFCRibbonButton *v11; // esi
  int *p_left; // esi
  CMFCRibbonPanelMenuBar *ParentRibbonMenuBar; // eax
  CMFCRibbonBaseElement *m_pParentRibbonElement; // ecx
  CMFCRibbonButton *m_pDelayedCloseButton; // ecx
  HWND v16; // eax
  CWnd *v17; // eax
  CObject *v18; // eax
  CObject_vtbl *v19; // ecx
  HWND__ *m_hWnd; // [esp-10h] [ebp-3Ch]
  tagPOINT Point; // [esp+4h] [ebp-28h] BYREF
  CObject *pObject; // [esp+Ch] [ebp-20h]
  CMFCRibbonButton *pHotButton; // [esp+10h] [ebp-1Ch]
  CMFCRibbonPanelMenu *pParentMenu; // [esp+14h] [ebp-18h]
  CRect rectMenu; // [esp+18h] [ebp-14h] BYREF

  m_pPanel = this->m_pPanel;
  pObject = pHot;
  if ( m_pPanel != nullptr && m_pPanel->m_bMenuMode != 0 )
  {
    DroppedDown = CMFCRibbonPanel::GetDroppedDown(this: m_pPanel);
    v5 = (CMFCRibbonPanelMenu *)AfxDynamicDownCast(
                                  pClass: &CMFCRibbonButton::classCMFCRibbonButton,
                                  pObject: DroppedDown);
    pParentMenu = v5;
    v6 = (CMFCRibbonButton *)AfxDynamicDownCast(pClass: &CMFCRibbonButton::classCMFCRibbonButton, pObject);
    pHotButton = v6;
    if ( v5 == nullptr || pObject != nullptr )
    {
      Point.y = v5 != (CMFCRibbonPanelMenu *)pObject;
      if ( v6 != nullptr && v5 == (CMFCRibbonPanelMenu *)v6 )
      {
        rectMenu = v6->m_rectMenu;
        if ( !IsRectEmpty(lprc: &rectMenu) && pHotButton->IsMenuAreaHighlighted(this: pHotButton) == 0 )
          Point.y = 1;
        v5 = pParentMenu;
      }
      if ( Point.y != 0 )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v8 = CWnd::FromHandle(hWnd: Parent);
        pParentMenu = (CMFCRibbonPanelMenu *)AfxDynamicDownCast(
                                               pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu,
                                               pObject: v8);
        if ( v5 != nullptr )
        {
          CurrentMessage = CWnd::GetCurrentMessage();
          if ( CMFCToolBar::m_bCustomizeMode != 0 || CurrentMessage != nullptr && CurrentMessage->message == 256 )
          {
            KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
            this->m_pDelayedCloseButton = nullptr;
            ((void (__thiscall *)(CMFCRibbonPanelMenu *))v5->OnNotify)(a1: v5);
            if ( pParentMenu != nullptr )
            {
              TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
              if ( g_pTopLevelFrame == nullptr )
                TopLevelFrame = CWnd::GetTopLevelFrame(this);
              CMFCPopupMenu::ActivatePopupMenu(pTopFrame: TopLevelFrame, pPopupMenu: &pParentMenu->CMFCPopupMenu);
            }
          }
          else
          {
            this->m_pDelayedCloseButton = (CMFCRibbonButton *)v5;
            v5->m_ptLocation.x = 1;
            SetTimer(
              hWnd: this->m_hWnd,
              nIDEvent: 2u,
              uElapse: CMFCPopupMenuBar::m_uiPopupTimerDelay - 1,
              lpTimerFunc: nullptr);
            ((void (__thiscall *)(CMFCRibbonPanelMenu *))v5->OnWndMsg)(a1: v5);
          }
        }
        v11 = pHotButton;
        if ( pHotButton != nullptr && pHotButton->HasMenu(this: pHotButton) != 0 )
        {
          if ( this->m_pDelayedButton != nullptr )
            KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
          this->m_pDelayedButton = pHotButton;
          if ( v11 == this->m_pDelayedCloseButton )
          {
            p_left = &v11->m_rectMenu.left;
            rectMenu.left = *p_left++;
            rectMenu.top = *p_left++;
            rectMenu.right = *p_left;
            rectMenu.bottom = p_left[1];
            if ( IsRectEmpty(lprc: &rectMenu)
              || (Point = 0,
                  GetCursorPos(lpPoint: &Point),
                  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &Point),
                  PtInRect(lprc: &rectMenu, pt: Point)) )
            {
              this->RestoreDelayedSubMenu(this);
              this->m_pDelayedButton = nullptr;
            }
            v11 = pHotButton;
          }
          else
          {
            SetTimer(
              hWnd: this->m_hWnd,
              nIDEvent: 1u,
              uElapse: CMFCPopupMenuBar::m_uiPopupTimerDelay,
              lpTimerFunc: nullptr);
          }
        }
        if ( pParentMenu != nullptr )
        {
          ParentRibbonMenuBar = CMFCRibbonPanelMenu::GetParentRibbonMenuBar(this: pParentMenu);
          if ( ParentRibbonMenuBar != nullptr
            && ParentRibbonMenuBar->m_pDelayedCloseButton == pParentMenu->m_pParentRibbonElement )
          {
            ParentRibbonMenuBar->RestoreDelayedSubMenu(this: ParentRibbonMenuBar);
          }
          m_pParentRibbonElement = pParentMenu->m_pParentRibbonElement;
          if ( m_pParentRibbonElement != nullptr )
            m_pParentRibbonElement->OnChangeMenuHighlight(this: m_pParentRibbonElement, a2: this, a3: v11);
        }
      }
      else if ( pHotButton != nullptr )
      {
        m_pDelayedCloseButton = this->m_pDelayedCloseButton;
        if ( pHotButton == m_pDelayedCloseButton )
        {
          m_pDelayedCloseButton->m_bToBeClosed = 0;
          m_hWnd = this->m_hWnd;
          this->m_pDelayedCloseButton = nullptr;
          KillTimer(hWnd: m_hWnd, uIDEvent: 2u);
        }
      }
      if ( pObject == nullptr )
      {
        v16 = GetParent(hWnd: this->m_hWnd);
        v17 = CWnd::FromHandle(hWnd: v16);
        v18 = AfxDynamicDownCast(pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu, pObject: v17);
        if ( v18 != nullptr )
        {
          v19 = v18[1071].__vftable;
          if ( v19 != nullptr )
            (*((void (__thiscall **)(CObject_vtbl *, CMFCRibbonPanelMenuBar *, _DWORD))v19->GetRuntimeClass + 87))(
              a1: v19,
              a2: this,
              a3: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417556
// Name: protected: int CMFCRibbonPanelMenuBar::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::OnCreate(CMFCRibbonPanelMenuBar *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  CToolTipCtrl **p_m_pToolTip; // edi
  unsigned int DlgCtrlID; // eax
  CMFCRibbonPanel *m_pPanel; // eax
  CScrollBar_vtbl *v7; // eax
  CMFCRibbonBar *m_pRibbonBar; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-28h]
  CRect rectClient; // [esp+4h] [ebp-14h] BYREF

  result = CMFCPopupMenuBar::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    if ( this->m_bIsFloaty == 0 || this->m_bIsQATPopup != 0 )
    {
      p_m_pToolTip = &this->m_pToolTip;
      CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 0x200u);
      if ( this->m_pToolTip != nullptr && this->m_pToolTip->m_hWnd != nullptr )
      {
        m_hWnd = this->m_hWnd;
        memset(&rectClient, 0, sizeof(rectClient));
        GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
        SendMessageA(hWnd: (*p_m_pToolTip)->m_hWnd, Msg: 0x418u, wParam: 0, lParam: 640);
        DlgCtrlID = CWnd::GetDlgCtrlID(this);
        CToolTipCtrl::AddTool(
          this: *p_m_pToolTip,
          pWnd: this,
          lpszText: (char *)0xFFFFFFFF,
          lpRectTool: &rectClient,
          nIDTool: DlgCtrlID);
      }
    }
    m_pPanel = this->m_pPanel;
    if ( m_pPanel != nullptr && m_pPanel->m_pPaletteButton != nullptr )
    {
      v7 = this->m_wndScrollBarVert.__vftable;
      memset(&rectClient, 0, sizeof(rectClient));
      v7->Create(this: &this->m_wndScrollBarVert, a2: 1342177281u, a3: &rectClient, a4: this, a5: 1u);
      this->m_pPanel->m_pScrollBar = &this->m_wndScrollBarVert;
    }
    m_pRibbonBar = this->m_pRibbonBar;
    if ( m_pRibbonBar != nullptr && m_pRibbonBar->m_nKeyboardNavLevel >= 0 )
    {
      this->m_bSetKeyTips = 1;
      this->m_bHasKeyTips = 1;
    }
    GetCursorPos(lpPoint: &this->m_ptStartMenu);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041767D
// Name: protected: void CMFCRibbonPanelMenuBar::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnSize(CMFCRibbonPanelMenuBar *this, unsigned int nType, int cx, int cy)
{
  CToolTipCtrl *m_pToolTip; // eax
  unsigned int DlgCtrlID; // eax
  tagRECT Rect; // [esp+Ch] [ebp-14h] BYREF

  CMFCToolBar::OnSize(this, nType, cx, cy);
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
  {
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = cx;
    Rect.bottom = cy;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    CToolTipCtrl::SetToolRect(this: this->m_pToolTip, pWnd: this, nIDTool: DlgCtrlID, lpRect: &Rect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104176EB
// Name: protected: long CMFCRibbonPanelMenuBar::OnUpdateToolTips(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::OnUpdateToolTips(CMFCRibbonPanelMenuBar *this, __int16 wp, int __formal)
{
  CToolTipCtrl **p_m_pToolTip; // edi
  unsigned int DlgCtrlID; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-28h]
  CRect rectClient; // [esp+4h] [ebp-14h] BYREF

  if ( (wp & 0x200) != 0 && (this->m_bIsFloaty == 0 || this->m_bIsQATPopup != 0) )
  {
    p_m_pToolTip = &this->m_pToolTip;
    CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 0x200u);
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    SendMessageA(hWnd: (*p_m_pToolTip)->m_hWnd, Msg: 0x418u, wParam: 0, lParam: 640);
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    CToolTipCtrl::AddTool(
      this: *p_m_pToolTip,
      pWnd: this,
      lpszText: (char *)0xFFFFFFFF,
      lpRectTool: &rectClient,
      nIDTool: DlgCtrlID);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10417784
// Name: public: void CMFCRibbonPanelMenuBar::PopTooltip(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::PopTooltip(CMFCRibbonPanelMenuBar *this)
{
  CToolTipCtrl *m_pToolTip; // eax

  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    SendMessageA(hWnd: m_pToolTip->m_hWnd, Msg: 0x41Cu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104177A7
// Name: public: void CMFCRibbonPanelMenuBar::SetActive(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::SetActive(CMFCRibbonPanelMenuBar *this, CArchive *bIsActive)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CObject *v4; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = AfxDynamicDownCast(pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu, pObject: v3);
  if ( v4 != nullptr )
    v4->__vftable[43].Serialize(this: v4, a2: bIsActive);
}

//------------------------------------------------------------------------------
// Address: 0x104177DB
// Name: protected: void CMFCRibbonPanelMenuBar::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnTimer(CMFCRibbonPanelMenuBar *this, unsigned int nIDEvent)
{
  CToolTipCtrl *m_pToolTip; // ecx
  CMFCRibbonButton *m_pDelayedCloseButton; // eax
  CMFCRibbonButton *m_pDelayedButton; // edi
  HWND Parent; // eax
  CWnd *v7; // eax
  CObject *v8; // eax
  CRect *p_m_rect; // esi
  CFrameWnd *TopLevelFrame; // eax
  int v11; // esi
  int m_iAccHotItem; // eax
  CMFCRibbonBaseElement *m_pPressed; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-34h]
  HWND__ *v15; // [esp-8h] [ebp-34h]
  CMFCPopupMenu *pParentMenu; // [esp+Ch] [ebp-20h]
  CPoint ptCursor; // [esp+10h] [ebp-1Ch] BYREF
  CRect rc; // [esp+18h] [ebp-14h] BYREF

  ptCursor.x = 0;
  ptCursor.y = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  switch ( nIDEvent )
  {
    case 1u:
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
      m_pToolTip = this->m_pToolTip;
      if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
        CWnd::ShowWindow(this: m_pToolTip, nCmdShow: 0);
      m_pDelayedCloseButton = this->m_pDelayedCloseButton;
      if ( m_pDelayedCloseButton == nullptr
        || (rc = m_pDelayedCloseButton->m_rect, !PtInRect(lprc: &rc, pt: ptCursor.tagPOINT)) )
      {
        this->CloseDelayedSubMenu(this);
        m_pDelayedButton = this->m_pDelayedButton;
        this->m_pDelayedButton = nullptr;
        if ( m_pDelayedButton != nullptr && m_pDelayedButton->IsHighlighted(this: m_pDelayedButton) != 0 )
          m_pDelayedButton->OnShowPopupMenu(this: m_pDelayedButton);
      }
      break;
    case 2u:
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
      if ( this->m_pDelayedCloseButton != nullptr )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v7 = CWnd::FromHandle(hWnd: Parent);
        v8 = AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v7);
        p_m_rect = &this->m_pDelayedCloseButton->m_rect;
        rc.left = p_m_rect->left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        rc.top = p_m_rect->left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        rc.right = p_m_rect->left;
        pParentMenu = (CMFCPopupMenu *)v8;
        rc.bottom = p_m_rect->top;
        if ( !PtInRect(lprc: &rc, pt: ptCursor.tagPOINT) )
        {
          this->m_pDelayedCloseButton->ClosePopupMenu(this: this->m_pDelayedCloseButton);
          this->m_pDelayedCloseButton = nullptr;
          if ( pParentMenu != nullptr )
          {
            TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
            if ( g_pTopLevelFrame == nullptr )
              TopLevelFrame = CWnd::GetTopLevelFrame(this);
            CMFCPopupMenu::ActivatePopupMenu(pTopFrame: TopLevelFrame, pPopupMenu: pParentMenu);
          }
        }
      }
      break;
    case 0x14u:
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 0x14u);
      m_hWnd = this->m_hWnd;
      memset(&rc, 0, sizeof(rc));
      GetClientRect(hWnd: m_hWnd, lpRect: &rc);
      if ( PtInRect(lprc: &rc, pt: ptCursor.tagPOINT) )
      {
        v11 = CMFCRibbonPanelMenuBar::HitTestEx(this, point: ptCursor);
        if ( v11 != -1 )
        {
          m_iAccHotItem = this->m_iAccHotItem;
          if ( m_iAccHotItem == v11 && m_iAccHotItem != -1 )
          {
            GetCursorPos(lpPoint: &ptCursor);
            if ( this->OnSetAccData(this, a2: LOWORD(ptCursor.x) | (LOWORD(ptCursor.y) << 16)) != 0 )
              NotifyWinEvent(event: 0x8005u, hwnd: this->m_hWnd, idObject: -4, idChild: v11 + 1);
          }
        }
      }
      break;
    case 3u:
      if ( PtInRect(lprc: &this->m_rectAutoCommand, pt: ptCursor.tagPOINT) )
      {
        m_pPressed = this->m_pPressed;
        if ( m_pPressed != nullptr )
        {
          rc = m_pPressed->m_rect;
          if ( PtInRect(lprc: &rc, pt: ptCursor.tagPOINT) && this->m_pPressed->OnAutoRepeat(this: this->m_pPressed) == 0 )
            KillTimer(hWnd: this->m_hWnd, uIDEvent: 3u);
        }
      }
      else
      {
        v15 = this->m_hWnd;
        this->m_pPressed = nullptr;
        KillTimer(hWnd: v15, uIDEvent: 3u);
        SetRectEmpty(lprc: &this->m_rectAutoCommand);
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417A89
// Name: public: virtual void CMFCRibbonPanelMenuBar::CloseDelayedSubMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::CloseDelayedSubMenu(CMFCRibbonPanelMenuBar *this)
{
  if ( this->m_pDelayedCloseButton != nullptr )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    this->m_pDelayedCloseButton->ClosePopupMenu(this: this->m_pDelayedCloseButton);
    this->m_pDelayedCloseButton = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417AB9
// Name: public: virtual void CMFCRibbonPanelMenuBar::RestoreDelayedSubMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::RestoreDelayedSubMenu(CMFCRibbonPanelMenuBar *this)
{
  CMFCRibbonButton *m_pDelayedCloseButton; // eax
  CMFCRibbonBaseElement *Highlighted; // eax
  CMFCRibbonPanel *m_pPanel; // ecx
  CRect *p_m_rect; // esi
  CMFCRibbonButton *v6; // eax
  int v7; // esi
  HWND__ *m_hWnd; // [esp-14h] [ebp-30h]
  HWND__ *v9; // [esp-14h] [ebp-30h]
  CMFCRibbonBaseElement *pPrev; // [esp+4h] [ebp-18h]
  RECT Rect; // [esp+8h] [ebp-14h] BYREF

  m_pDelayedCloseButton = this->m_pDelayedCloseButton;
  if ( m_pDelayedCloseButton != nullptr && this->m_pPanel != nullptr )
  {
    m_pDelayedCloseButton->m_bToBeClosed = 0;
    Highlighted = CMFCRibbonPanel::GetHighlighted(this: this->m_pPanel);
    m_pPanel = this->m_pPanel;
    p_m_rect = &this->m_pDelayedCloseButton->m_rect;
    Rect.left = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    Rect.top = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    Rect.right = p_m_rect->left;
    Rect.bottom = p_m_rect->top;
    pPrev = Highlighted;
    ((void (__thiscall *)(CMFCRibbonPanel *, int, int, int))m_pPanel->Highlight)(
      a1: m_pPanel,
      a2: 1,
      a3: Rect.left,
      a4: Rect.top);
    v6 = this->m_pDelayedCloseButton;
    v7 = 0;
    if ( v6 != pPrev )
    {
      if ( v6 != nullptr )
      {
        Rect.left = v6->m_rect.left;
        Rect.top = v6->m_rect.top;
        Rect.right = v6->m_rect.right;
        m_hWnd = this->m_hWnd;
        Rect.bottom = v6->m_rect.bottom;
        InvalidateRect(hWnd: m_hWnd, lpRect: &Rect, bErase: true);
      }
      if ( pPrev != nullptr )
      {
        Rect.left = pPrev->m_rect.left;
        Rect.top = pPrev->m_rect.top;
        Rect.right = pPrev->m_rect.right;
        v9 = this->m_hWnd;
        Rect.bottom = pPrev->m_rect.bottom;
        InvalidateRect(hWnd: v9, lpRect: &Rect, bErase: true);
      }
      v7 = 1;
    }
    this->m_pDelayedCloseButton = nullptr;
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    if ( v7 != 0 )
      UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417B9E
// Name: protected: void CMFCRibbonPanelMenuBar::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnContextMenu(CMFCRibbonPanelMenuBar *this, CWnd *__formal, CPoint point)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  CObject *v6; // eax
  CObject_vtbl *v7; // eax
  CMFCRibbonButton *DroppedDown; // eax
  CMFCRibbonDefaultPanelButton *Focused; // eax
  CMFCRibbonBar_vtbl *v10; // esi
  CMFCRibbonBaseElement *v11; // eax
  CMFCRibbonBaseElement *pFocused; // [esp+4h] [ebp-20h]
  CPoint ptClient; // [esp+8h] [ebp-1Ch] BYREF
  CRect rectFocus; // [esp+10h] [ebp-14h] BYREF

  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  v6 = AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v5);
  if ( v6 == nullptr || (v7 = v6[1071].__vftable) == nullptr || v7[8].dtr_CObject == nullptr )
  {
    if ( this->m_bAutoCommandTimer != 0 )
    {
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 3u);
      this->m_bAutoCommandTimer = 0;
      this->m_pPressed = nullptr;
      SetRectEmpty(lprc: &this->m_rectAutoCommand);
    }
    if ( this->IsRibbonPanel(this) != 0
      && this->m_bCustomizeMenu != 0
      && (this->m_bIsFloaty == 0 || this->m_bIsQATPopup != 0)
      && GetAsyncKeyState(vKey: 1) >= 0 )
    {
      ptClient = point;
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptClient);
      DroppedDown = CMFCRibbonPanelMenuBar::GetDroppedDown(this);
      if ( DroppedDown != nullptr )
        DroppedDown->ClosePopupMenu(this: DroppedDown);
      if ( this->m_pDelayedButton != nullptr )
        KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
      if ( point == -1 && (Focused = CMFCRibbonPanelMenuBar::GetFocused(this), pFocused = Focused, Focused != nullptr) )
      {
        rectFocus = Focused->m_rect;
        CWnd::ClientToScreen(this, lpRect: &rectFocus);
        this->m_pRibbonBar->OnShowRibbonContextMenu(
          this: this->m_pRibbonBar,
          a2: this,
          a3: rectFocus.left,
          a4: rectFocus.top,
          a5: pFocused);
      }
      else
      {
        v10 = this->m_pRibbonBar->__vftable;
        v11 = CMFCRibbonPanelMenuBar::HitTest(this, point: ptClient);
        v10->OnShowRibbonContextMenu(this: this->m_pRibbonBar, a2: this, a3: point.x, a4: point.y, a5: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417D24
// Name: protected: void CMFCRibbonPanelMenuBar::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::OnVScroll(
        CMFCRibbonPanelMenuBar *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  CMFCRibbonPanel *m_pPanel; // ecx
  HWND__ *m_hWnd; // esi
  HWND__ *v7; // edx
  unsigned int nPage; // ebx
  CMFCRibbonPanel *v9; // ecx
  int m_nScrollOffset; // esi
  int MenuRowHeight; // eax
  int v12; // esi
  int v13; // ecx
  CMFCRibbonPanel *v14; // ecx
  int nMaxOffset; // [esp+Ch] [ebp-24h]
  tagSCROLLINFO scrollInfo; // [esp+10h] [ebp-20h] BYREF

  m_pPanel = this->m_pPanel;
  if ( m_pPanel != nullptr
    && (pScrollBar != nullptr ? (m_hWnd = pScrollBar->m_hWnd) : (m_hWnd = nullptr),
        this != (CMFCRibbonPanelMenuBar *)-3496 ? (v7 = this->m_wndScrollBarVert.m_hWnd) : (v7 = nullptr),
        m_hWnd == v7 && m_pPanel->m_pPaletteButton != nullptr) )
  {
    memset(dst: (unsigned __int8 *)&scrollInfo, value: 0, count: sizeof(scrollInfo));
    scrollInfo.fMask = 23;
    scrollInfo.cbSize = 28;
    CWnd::GetScrollInfo(this: &this->m_wndScrollBarVert, nBar: 2, lpScrollInfo: &scrollInfo, nMask: 0x17u);
    nPage = scrollInfo.nPage;
    v9 = this->m_pPanel;
    m_nScrollOffset = v9->m_nScrollOffset;
    nMaxOffset = scrollInfo.nMax;
    if ( (signed int)(scrollInfo.nMax - scrollInfo.nPage) > 1 )
    {
      MenuRowHeight = CMFCRibbonGallery::GetMenuRowHeight(this: v9->m_pPaletteButton);
      switch ( nSBCode )
      {
        case 0u:
          v12 = m_nScrollOffset - MenuRowHeight;
          goto LABEL_23;
        case 1u:
          v12 = MenuRowHeight + m_nScrollOffset;
          goto LABEL_23;
        case 2u:
          v12 = m_nScrollOffset - nPage;
          goto LABEL_23;
        case 3u:
          v12 = nPage + m_nScrollOffset;
          goto LABEL_23;
        case 4u:
        case 5u:
          v12 = nPos;
          goto LABEL_23;
        case 6u:
          v12 = 0;
          v13 = 0;
          goto LABEL_16;
        case 7u:
          v12 = nMaxOffset;
LABEL_23:
          if ( v12 >= 0 )
            v13 = v12;
          else
            v13 = 0;
LABEL_16:
          if ( v13 >= (int)(nMaxOffset - nPage) )
          {
            v12 = nMaxOffset - nPage;
          }
          else if ( v12 < 0 )
          {
            v12 = 0;
          }
          v14 = this->m_pPanel;
          if ( v12 != v14->m_nScrollOffset )
          {
            CMFCRibbonPanel::ScrollPalette(this: v14, nScrollOffset: v12, bIsDelta: 0);
            SetScrollPos(hWnd: this->m_wndScrollBarVert.m_hWnd, nBar: 2, nPos: v12, bRedraw: true);
            RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
          }
          break;
        default:
          return;
      }
    }
  }
  else if ( bAlreadyHere == 0 )
  {
    bAlreadyHere = 1;
    CWnd::OnHScroll(this, __formal: nSBCode, __formal: nPos, pScrollBar);
    bAlreadyHere = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417EAC
// Name: protected: virtual int CMFCRibbonPanelMenuBar::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::PreTranslateMessage(CMFCRibbonPanelMenuBar *this, tagMSG *pMsg)
{
  HWND Focus; // eax
  CWnd *v5; // eax
  CObject *v6; // esi
  CPoint point; // [esp+8h] [ebp-8h] BYREF

  if ( pMsg->message == 256 && pMsg->wParam == 9 && this->OnKey(this, a2: 9u) != 0 )
    return 1;
  if ( pMsg->message == 513 )
  {
    Focus = GetFocus();
    v5 = CWnd::FromHandle(hWnd: Focus);
    v6 = AfxDynamicDownCast(pClass: &CMFCRibbonRichEditCtrl::classCMFCRibbonRichEditCtrl, pObject: v5);
    if ( v6 != nullptr )
    {
      point.x = 0;
      point.y = 0;
      GetCursorPos(lpPoint: &point);
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
      (*((void (__thiscall **)(CObject_vtbl *, int, int))v6[29].GetRuntimeClass + 119))(
        a1: v6[29].__vftable,
        a2: point.x,
        a3: point.y);
    }
  }
  return CMFCToolBar::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10417F44
// Name: protected: CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenu *__thiscall CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(CMFCRibbonPanelMenu *this)
{
  CMFCPopupMenu::CMFCPopupMenu(this: &this->CMFCPopupMenu);
  this->__vftable = (CMFCRibbonPanelMenu_vtbl *)&CMFCRibbonPanelMenu::`vftable';
  CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(this: &this->m_wndRibbonBar);
  this->m_bForceClose = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10417F7E
// Name: public: virtual CMFCRibbonPanelMenu::~CMFCRibbonPanelMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenu::~CMFCRibbonPanelMenu(CMFCRibbonPanelMenu *this)
{
  this->__vftable = (CMFCRibbonPanelMenu_vtbl *)&CMFCRibbonPanelMenu::`vftable';
  this->m_bForceClose = 0;
  CMFCRibbonPanelMenuBar::~CMFCRibbonPanelMenuBar(this: &this->m_wndRibbonBar);
  CMFCPopupMenu::~CMFCPopupMenu(this: &this->CMFCPopupMenu);
}

//------------------------------------------------------------------------------
// Address: 0x10417FBC
// Name: protected: int CMFCRibbonPanelMenu::OnMouseWheel(unsigned int,short,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenu::OnMouseWheel(
        CMFCRibbonPanelMenu *this,
        unsigned int __formal,
        __int16 zDelta,
        CPoint a4)
{
  int v5; // eax
  int m_iOffset; // edi
  CMFCRibbonPanelMenu_vtbl *v7; // eax
  int v8; // edi
  int i; // [esp+8h] [ebp-4h]

  v5 = abs(lnumber: zDelta) / 120;
  if ( v5 > 0 )
  {
    for ( i = v5; i != 0; --i )
    {
      if ( this->IsScrollUpAvailable((CMFCPopupMenu *)this) != 0
        || this->IsScrollDnAvailable((CMFCPopupMenu *)this) != 0 )
      {
        m_iOffset = this->m_wndRibbonBar.m_iOffset;
        v7 = this->__vftable;
        if ( zDelta <= 0 )
        {
          if ( v7->IsScrollDnAvailable(this: &this->CMFCPopupMenu) != 0 )
          {
            v8 = m_iOffset + 1;
            goto LABEL_11;
          }
        }
        else if ( v7->IsScrollUpAvailable(this: &this->CMFCPopupMenu) != 0 )
        {
          v8 = m_iOffset - 1;
LABEL_11:
          CMFCPopupMenuBar::SetOffset(this: &this->m_wndRibbonBar, iOffset: v8);
          CMFCPopupMenu::AdjustScroll(this: &this->CMFCPopupMenu, bForceMenuBarResize: 0);
        }
      }
      else
      {
        CMFCRibbonPanelMenuBar::OnVScroll(
          this: &this->m_wndRibbonBar,
          nSBCode: zDelta < 0,
          nPos: 0,
          pScrollBar: &this->m_wndRibbonBar.m_wndScrollBarVert);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041806B
// Name: protected: void CMFCRibbonPanelMenu::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenu::OnLButtonDown(CMFCRibbonPanelMenu *this, unsigned int nFlags, CPoint point)
{
  CMFCPopupMenu::OnLButtonDown(this: &this->CMFCPopupMenu, nFlags, point);
  if ( CMFCRibbonPanelMenuBar::IsMainPanel(this: &this->m_wndRibbonBar) )
  {
    ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
    ((void (__thiscall *)(CMFCRibbonPanel *, int, int))this->m_wndRibbonBar.m_pPanel->MouseButtonDown)(
      a1: this->m_wndRibbonBar.m_pPanel,
      a2: point.x,
      a3: point.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104180C0
// Name: public: CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(class CMFCRibbonPanel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenuBar *__thiscall CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(
        CMFCRibbonPanelMenuBar *this,
        CMFCRibbonPanel *pPanel)
{
  CRuntimeClass *v3; // eax
  CObject *Object; // eax
  CMFCRibbonPanel *v5; // eax
  CMFCRibbonPanel *m_pPanel; // eax
  int i; // ebx
  CMFCRibbonPanel *v8; // eax
  CMFCRibbonBaseElement *v9; // ecx

  CMFCPopupMenuBar::CMFCPopupMenuBar(this);
  this->__vftable = (CMFCRibbonPanelMenuBar_vtbl *)&CMFCRibbonPanelMenuBar::`vftable';
  this->m_sizePrefered.cx = 0;
  this->m_sizePrefered.cy = 0;
  this->m_sizeCategory.cx = 0;
  this->m_sizeCategory.cy = 0;
  this->m_rectAutoCommand.left = 0;
  this->m_rectAutoCommand.top = 0;
  this->m_rectAutoCommand.right = 0;
  this->m_rectAutoCommand.bottom = 0;
  this->m_ptStartMenu.x = 0;
  this->m_ptStartMenu.y = 0;
  CWnd::CWnd(this: &this->m_wndScrollBarVert);
  this->m_wndScrollBarVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  v3 = (CRuntimeClass *)pPanel->GetRuntimeClass(this: pPanel);
  Object = CRuntimeClass::CreateObject(this: v3);
  v5 = (CMFCRibbonPanel *)AfxDynamicDownCast(pClass: &CMFCRibbonPanel::classCMFCRibbonPanel, pObject: Object);
  this->m_pPanel = v5;
  v5->CopyFrom(this: v5, a2: pPanel);
  CMFCRibbonPanelMenuBar::CommonInit(this);
  m_pPanel = this->m_pPanel;
  this->m_pPanelOrigin = pPanel;
  m_pPanel->m_pParentMenuBar = this;
  for ( i = 0; i < this->m_pPanel->m_arElements.m_nSize; ++i )
  {
    v8 = this->m_pPanel;
    if ( i < 0 || i >= v8->m_arElements.m_nSize )
      AfxThrowInvalidArgException();
    v9 = v8->m_arElements.m_pData[i];
    v9->SetParentMenu(this: v9, a2: this);
  }
  this->m_pRibbonBar = this->m_pPanel->m_pParent->m_pParentRibbonBar;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10418206
// Name: protected: void CMFCRibbonPanelMenuBar::AddButtons(class CMFCRibbonBar __near *,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::AddButtons(
        CMFCRibbonPanelMenuBar *this,
        CMFCRibbonBar *pRibbonBar,
        const CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons,
        int bFloatyMode)
{
  CMFCRibbonPanel *m_pPanel; // eax
  int m_nSize; // eax
  CMFCRibbonBaseElement *v7; // ebx
  CRuntimeClass *v8; // eax
  CMFCRibbonBaseElement *Object; // edi
  CMFCRibbonBaseElement_vtbl *v10; // eax
  int i; // [esp+Ch] [ebp+8h]

  this->m_pRibbonBar = pRibbonBar;
  m_pPanel = this->m_pPanel;
  this->m_bSimpleMode = 1;
  m_pPanel->m_pParentMenuBar = this;
  this->m_pPanel->m_bFloatyMode = bFloatyMode;
  this->m_pPanel->m_nXMargin = 2;
  this->m_pPanel->m_nYMargin = 2;
  CMFCRibbonPanel::RemoveAll(this: this->m_pPanel);
  m_nSize = arButtons->m_nSize;
  for ( i = 0; i < m_nSize; m_nSize = arButtons->m_nSize )
  {
    if ( i < 0 || i >= m_nSize )
      AfxThrowInvalidArgException();
    v7 = arButtons->m_pData[i];
    v8 = (CRuntimeClass *)v7->GetRuntimeClass(this: v7);
    Object = (CMFCRibbonBaseElement *)CRuntimeClass::CreateObject(this: v8);
    Object->CopyFrom(this: Object, a2: v7);
    Object->SetOriginal(this: Object, a2: v7);
    v10 = Object->__vftable;
    Object->m_bCompactMode = 1;
    v10->SetParentMenu(this: Object, a2: this);
    this->m_pPanel->Add(this: this->m_pPanel, a2: Object);
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104182DB
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanelMenuBar::FindByOrigin(class CMFCRibbonBaseElement __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanelMenuBar::FindByOrigin(
        CMFCRibbonPanelMenuBar *this,
        CMFCRibbonBaseElement *pOrigin)
{
  CMFCRibbonPanel *m_pPanel; // ecx
  int v3; // esi
  CMFCRibbonBaseElement *v4; // edi
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> arElems; // [esp+10h] [ebp-20h] BYREF
  int v7; // [esp+2Ch] [ebp-4h]

  m_pPanel = this->m_pPanel;
  if ( m_pPanel == nullptr )
    return nullptr;
  arElems.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  memset(&arElems.m_pData, 0, 16);
  v7 = 0;
  CMFCRibbonPanel::GetElements(this: m_pPanel, arElements: &arElems);
  v3 = 0;
  if ( arElems.m_nSize <= 0 )
  {
LABEL_7:
    v7 = -1;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arElems);
    return nullptr;
  }
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= arElems.m_nSize )
      AfxThrowInvalidArgException();
    v4 = arElems.m_pData[v3]->FindByOriginal(this: arElems.m_pData[v3], a2: pOrigin);
    if ( v4 != nullptr )
      break;
    if ( ++v3 >= arElems.m_nSize )
      goto LABEL_7;
  }
  v7 = -1;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arElems);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1041836D
// Name: public: virtual int CMFCRibbonPanelMenuBar::OnKey(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::OnKey(CMFCRibbonPanelMenuBar *this, unsigned int nChar)
{
  int result; // eax
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // ebx

  if ( nChar == 121 && GetKeyState(nVirtKey: 16) < 0 || nChar == 93 )
  {
    CMFCRibbonPanelMenuBar::OnContextMenu(this, __formal: this, point: (CPoint)-1LL);
    return 1;
  }
  if ( CMFCRibbonBar::ProcessKey(this: this->m_pRibbonBar, nChar) != 0 )
    return 1;
  if ( this->m_pPanel != nullptr )
  {
    AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
    CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
    result = this->m_pPanel->OnKey(this: this->m_pPanel, a2: nChar);
LABEL_9:
    CMFCPopupMenu::m_AnimationType = AnimationType;
    return result;
  }
  if ( this->m_pCategory != nullptr )
  {
    AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
    CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
    result = this->m_pCategory->OnKey(this: this->m_pCategory, a2: nChar);
    goto LABEL_9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041843E
// Name: public: virtual int CMFCRibbonPanelMenuBar::OnSetAccData(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanelMenuBar::OnSetAccData(CMFCRibbonPanelMenuBar *this, unsigned int lVal)
{
  CMFCRibbonBaseElement *result; // eax
  int v4; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-18h]
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  pt.y = HIWORD(lVal);
  m_hWnd = this->m_hWnd;
  pt.x = (unsigned __int16)lVal;
  ScreenToClient(hWnd: m_hWnd, lpPoint: &pt);
  result = CMFCRibbonPanelMenuBar::HitTest(this, point: pt);
  v4 = (int)result;
  if ( result != nullptr )
  {
    CAccessibilityData::Clear(this: &this->m_AccData);
    return (CMFCRibbonBaseElement *)(*(int (__thiscall **)(int, CMFCRibbonPanelMenuBar *, CAccessibilityData *))(*(_DWORD *)v4 + 188))(
                                      a1: v4,
                                      a2: this,
                                      a3: &this->m_AccData);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10418499
// Name: public: CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(class CMFCRibbonPanel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenu *__thiscall CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(
        CMFCRibbonPanelMenu *this,
        CMFCRibbonPanel *pPanel)
{
  CMFCPopupMenu::CMFCPopupMenu(this: &this->CMFCPopupMenu);
  this->__vftable = (CMFCRibbonPanelMenu_vtbl *)&CMFCRibbonPanelMenu::`vftable';
  CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(this: &this->m_wndRibbonBar, pPanel);
  this->m_bForceClose = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104184F9
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCRibbonPanelMenu::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCRibbonPanelMenu::GetMessageMap(CMFCRibbonPanelMenu *this)
{
  return &messageMap_48;
}

//------------------------------------------------------------------------------
// Address: 0x104184FF
// Name: public: CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(class CMFCRibbonBar __near *,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenuBar *__thiscall CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(
        CMFCRibbonPanelMenuBar *this,
        CMFCRibbonBar *pRibbonBar,
        const CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons,
        int bIsFloatyMode)
{
  CMFCRibbonPanel *v5; // ecx
  CMFCRibbonPanel *v6; // eax

  CMFCPopupMenuBar::CMFCPopupMenuBar(this);
  this->__vftable = (CMFCRibbonPanelMenuBar_vtbl *)&CMFCRibbonPanelMenuBar::`vftable';
  this->m_sizePrefered.cx = 0;
  this->m_sizePrefered.cy = 0;
  this->m_sizeCategory.cx = 0;
  this->m_sizeCategory.cy = 0;
  this->m_rectAutoCommand.left = 0;
  this->m_rectAutoCommand.top = 0;
  this->m_rectAutoCommand.right = 0;
  this->m_rectAutoCommand.bottom = 0;
  this->m_ptStartMenu.x = 0;
  this->m_ptStartMenu.y = 0;
  CWnd::CWnd(this: &this->m_wndScrollBarVert);
  this->m_wndScrollBarVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  v5 = (CMFCRibbonPanel *)operator new(nSize: 0x268u);
  if ( v5 != nullptr )
    v6 = CMFCRibbonPanel::CMFCRibbonPanel(this: v5, lpszName: nullptr, hIcon: nullptr);
  else
    v6 = nullptr;
  this->m_pPanel = v6;
  CMFCRibbonPanelMenuBar::CommonInit(this);
  CMFCRibbonPanelMenuBar::AddButtons(this, pRibbonBar, arButtons, bFloatyMode: bIsFloatyMode);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104185C3
// Name: public: CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(class CMFCRibbonGallery __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenuBar *__thiscall CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(
        CMFCRibbonPanelMenuBar *this,
        CMFCRibbonGallery *pPaletteButton)
{
  CMFCRibbonPanel *v3; // ecx
  CMFCRibbonPanel *v4; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> arButtons; // [esp+10h] [ebp-28h] BYREF
  void *pData; // [esp+24h] [ebp-14h]
  CMFCRibbonPanelMenuBar *v9; // [esp+28h] [ebp-10h]
  int v10; // [esp+34h] [ebp-4h]

  v9 = this;
  CMFCPopupMenuBar::CMFCPopupMenuBar(this);
  this->__vftable = (CMFCRibbonPanelMenuBar_vtbl *)&CMFCRibbonPanelMenuBar::`vftable';
  this->m_sizePrefered.cx = 0;
  this->m_sizePrefered.cy = 0;
  this->m_sizeCategory.cx = 0;
  this->m_sizeCategory.cy = 0;
  this->m_rectAutoCommand.left = 0;
  this->m_rectAutoCommand.top = 0;
  this->m_rectAutoCommand.right = 0;
  this->m_rectAutoCommand.bottom = 0;
  v10 = 0;
  this->m_ptStartMenu.x = 0;
  this->m_ptStartMenu.y = 0;
  CWnd::CWnd(this: &this->m_wndScrollBarVert);
  this->m_wndScrollBarVert.__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  v3 = (CMFCRibbonPanel *)operator new(nSize: 0x268u);
  pData = v3;
  LOBYTE(v10) = 2;
  if ( v3 != nullptr )
    v4 = CMFCRibbonPanel::CMFCRibbonPanel(this: v3, pPaletteButton);
  else
    v4 = nullptr;
  this->m_pPanel = v4;
  CMFCRibbonPanelMenuBar::CommonInit(this);
  arButtons.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  memset(&arButtons.m_pData, 0, 16);
  LOBYTE(v10) = 3;
  CMFCRibbonGallery::GetMenuItems(this: pPaletteButton, &arButtons);
  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this: pPaletteButton);
  CMFCRibbonPanelMenuBar::AddButtons(this, pRibbonBar: TopLevelRibbonBar, &arButtons, bFloatyMode: 0);
  LOBYTE(v10) = 1;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arButtons);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104186B8
// Name: public: CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(class CMFCRibbonBar __near *,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenu *__thiscall CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(
        CMFCRibbonPanelMenu *this,
        CMFCRibbonBar *pRibbonBar,
        const CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons,
        int bIsFloatyMode)
{
  CMFCPopupMenu::CMFCPopupMenu(this: &this->CMFCPopupMenu);
  this->__vftable = (CMFCRibbonPanelMenu_vtbl *)&CMFCRibbonPanelMenu::`vftable';
  CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(this: &this->m_wndRibbonBar, pRibbonBar, arButtons, bIsFloatyMode);
  this->m_bForceClose = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104186FD
// Name: public: CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(class CMFCRibbonGallery __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanelMenu *__thiscall CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(
        CMFCRibbonPanelMenu *this,
        CMFCRibbonGallery *pPaletteButton)
{
  int BorderSize; // eax
  int v4; // ecx
  CSize v6; // [esp-8h] [ebp-30h]
  CSize sizeMin; // [esp+10h] [ebp-18h] BYREF
  CMFCRibbonPanelMenu *v8; // [esp+18h] [ebp-10h]
  int v9; // [esp+24h] [ebp-4h]

  v8 = this;
  CMFCPopupMenu::CMFCPopupMenu(this: &this->CMFCPopupMenu);
  v9 = 0;
  this->__vftable = (CMFCRibbonPanelMenu_vtbl *)&CMFCRibbonPanelMenu::`vftable';
  CMFCRibbonPanelMenuBar::CMFCRibbonPanelMenuBar(this: &this->m_wndRibbonBar, pPaletteButton);
  this->m_bForceClose = 0;
  this->m_bScrollable = 1;
  LOBYTE(v9) = 1;
  if ( pPaletteButton->m_bEnableMenuResize != 0 )
  {
    CMFCRibbonPanel::GetPaltteMinSize(this: this->m_wndRibbonBar.m_pPanel, result: &sizeMin);
    if ( sizeMin.cx > 0 && sizeMin.cy > 0 )
    {
      BorderSize = CMFCRibbonPanelMenu::GetBorderSize(this);
      v4 = sizeMin.cx + 2 * (__int16)BorderSize;
      sizeMin.cx = v4;
      sizeMin.cy += 2 * SHIWORD(BorderSize);
      v6.cy = sizeMin.cy;
      if ( pPaletteButton->m_bMenuResizeVertical != 0 )
      {
        CMFCPopupMenu::EnableVertResize(this: &this->CMFCPopupMenu, nMinResize: sizeMin.cy);
      }
      else
      {
        v6.cx = v4;
        CMFCPopupMenu::EnableResize(this: &this->CMFCPopupMenu, sizeMinResize: v6);
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104187A6
// Name: public: virtual class CSize CMFCRibbonPanelMenuBar::CalcSize(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonPanelMenuBar::CalcSize(CMFCRibbonPanelMenuBar *this, CSize *result, int __formal)
{
  CSize *v3; // eax
  CMFCRibbonBar *m_pRibbonBar; // ecx
  CFont *Font; // eax
  int cy; // eax
  CMFCRibbonPanel *v8; // ecx
  CMFCRibbonPanel *v9; // esi
  int v10; // edi
  int v11; // eax
  int v12; // ebx
  HWND Parent; // eax
  CWnd *v14; // eax
  CObject *v15; // eax
  CSize *v16; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  CMFCRibbonPanel *m_pPanel; // ecx
  CMFCRibbonPanel_vtbl *v19; // eax
  CMFCRibbonPanel *v20; // eax
  int v21; // eax
  CMFCRibbonPanel *v22; // ecx
  int v23; // eax
  const CRect *v24; // edx
  CMFCRibbonPanel *v25; // eax
  CMFCRibbonPanel *v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  CMFCRibbonPanel *v30; // eax
  CMFCRibbonPanel *v31; // ecx
  CMFCRibbonBaseElement *Element; // eax
  CMFCRibbonPanel *v33; // ecx
  int Count; // eax
  CMFCRibbonPanel *v35; // ebx
  int top; // [esp+14h] [ebp-6Ch]
  int right; // [esp+18h] [ebp-68h]
  int bottom; // [esp+1Ch] [ebp-64h]
  CClientDC v39; // [esp+20h] [ebp-60h] BYREF
  int v40; // [esp+34h] [ebp-4Ch]
  int left; // [esp+38h] [ebp-48h]
  int v42; // [esp+3Ch] [ebp-44h]
  CWaitCursor v43; // [esp+43h] [ebp-3Dh] BYREF
  int v44; // [esp+44h] [ebp-3Ch]
  CSize *v45; // [esp+48h] [ebp-38h]
  CFont *pFont; // [esp+4Ch] [ebp-34h]
  _DWORD v47[4]; // [esp+50h] [ebp-30h] BYREF
  int v48; // [esp+60h] [ebp-20h] BYREF
  int v49; // [esp+64h] [ebp-1Ch]
  int cx; // [esp+68h] [ebp-18h]
  int m_nSize; // [esp+6Ch] [ebp-14h]
  int v52; // [esp+7Ch] [ebp-4h]

  v3 = result;
  v45 = result;
  if ( this->m_pCategory != nullptr )
  {
    *result = this->m_sizeCategory;
    return v3;
  }
  this->m_pPanel->m_bIsQATPopup = this->m_bIsQATPopup;
  CClientDC::CClientDC(this: &v39, pWnd: this->m_pRibbonBar);
  m_pRibbonBar = this->m_pRibbonBar;
  v52 = 0;
  Font = CWnd::GetFont(this: m_pRibbonBar);
  pFont = CDC::SelectObject(this: &v39, pFont: Font);
  if ( pFont == nullptr )
LABEL_4:
    AfxThrowInvalidArgException();
  if ( this->m_bIsMenuMode == 0 )
  {
    if ( this->m_bSimpleMode != 0 && this->m_pPanel->m_arWidths.m_nSize == 0 )
    {
      ModuleState = AfxGetModuleState();
      CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
      m_pPanel = this->m_pPanel;
      v19 = m_pPanel->__vftable;
      LOBYTE(v52) = 1;
      v19->RecalcWidths(this: m_pPanel, a2: &v39, a3: 0x7FFF);
      LOBYTE(v52) = 0;
      CWaitCursor::~CWaitCursor(this: &v43);
    }
    v20 = this->m_pPanel;
    m_nSize = v20->m_arWidths.m_nSize;
    if ( m_nSize == 0 )
    {
      CDC::SelectObject(this: &v39, pFont);
      v16 = v45;
      v21 = 10;
      v45->cx = 10;
LABEL_26:
      v16->cy = v21;
      goto LABEL_20;
    }
    if ( v20->m_bAlignByColumn == 0 || v20->m_bFloatyMode != 0 || v20->IsFixedSize(this: v20) != 0 )
    {
      v25 = this->m_pPanel;
      if ( this->m_bIsQATPopup == 0 )
      {
        if ( v25->m_bFloatyMode != 0 )
        {
          v29 = m_nSize > 2;
          if ( v29 >= v25->m_arWidths.m_nSize )
            goto LABEL_4;
          v27 = v25->m_arWidths.m_pData[v29] + 4 * v25->m_nXMargin;
          v28 = 0x7FFF;
        }
        else
        {
          if ( v25->m_arWidths.m_nSize <= 0 )
            goto LABEL_4;
          v26 = this->m_pPanel;
          v27 = *v25->m_arWidths.m_pData + 4 * v26->m_nXMargin;
          v28 = this->m_pRibbonBar->m_nCategoryHeight - 2 * v26->m_nYMargin;
        }
        v22 = this->m_pPanel;
        v47[2] = v27;
        v47[0] = 0;
        v47[1] = 0;
        v47[3] = v28;
        v24 = (const CRect *)v47;
        goto LABEL_41;
      }
      if ( v25->m_arWidths.m_nSize <= 0 )
        goto LABEL_4;
      v22 = this->m_pPanel;
      cx = *v25->m_arWidths.m_pData + 2 * v22->m_nXMargin;
      m_nSize = 0x7FFF;
    }
    else
    {
      v22 = this->m_pPanel;
      v23 = this->m_pRibbonBar->m_nCategoryHeight - 2 * v22->m_nYMargin;
      cx = 0x7FFF;
      m_nSize = v23;
    }
    v49 = 0;
    v48 = 0;
    v24 = (const CRect *)&v48;
LABEL_41:
    v22->Reposition(this: v22, a2: &v39, a3: v24);
    v30 = this->m_pPanel;
    m_nSize = v30->m_rect.bottom - v30->m_rect.top;
    v40 = v30->m_rect.right - v30->m_rect.left;
    CDC::SelectObject(this: &v39, pFont);
    if ( this->m_bSimpleMode == 0 || CMFCRibbonPanel::GetCount(this: this->m_pPanel) <= 0 || this->m_bIsQATPopup != 0 )
    {
      v16 = v45;
      v45->cx = v40;
      v21 = m_nSize;
    }
    else
    {
      v31 = this->m_pPanel;
      left = 0x7FFF;
      m_nSize = 0;
      v42 = 0x7FFF;
      v44 = 0;
      pFont = nullptr;
      if ( CMFCRibbonPanel::GetCount(this: v31) > 0 )
      {
        do
        {
          Element = CMFCRibbonPanel::GetElement(this: this->m_pPanel, nIndex: (int)pFont);
          top = Element->m_rect.top;
          right = Element->m_rect.right;
          bottom = Element->m_rect.bottom;
          if ( left >= Element->m_rect.left )
            left = Element->m_rect.left;
          if ( v42 >= top )
            v42 = top;
          if ( m_nSize <= right )
            m_nSize = right;
          if ( v44 <= bottom )
            v44 = bottom;
          v33 = this->m_pPanel;
          pFont = (CFont *)((char *)pFont + 1);
          Count = CMFCRibbonPanel::GetCount(this: v33);
        }
        while ( (int)pFont < Count );
      }
      v35 = this->m_pPanel;
      v16 = v45;
      v21 = v44 + 2 * v35->m_nYMargin - v42;
      v45->cx = m_nSize + 2 * v35->m_nXMargin - left;
    }
    goto LABEL_26;
  }
  this->m_pPanel->m_bMenuMode = 1;
  this->m_pPanel->m_bIsDefaultMenuLook = this->m_bIsDefaultMenuLook;
  cy = this->m_sizePrefered.cy;
  cx = this->m_sizePrefered.cx;
  v8 = this->m_pPanel;
  v48 = 0;
  v49 = 0;
  m_nSize = cy;
  v8->Reposition(this: v8, a2: &v39, a3: (const CRect *)&v48);
  CDC::SelectObject(this: &v39, pFont);
  v9 = this->m_pPanel;
  v10 = v9->m_rect.bottom - v9->m_rect.top;
  cx = v9->m_rect.right - v9->m_rect.left;
  m_nSize = v10;
  if ( !CPoint::operator!=(this: (CPoint *)&this->m_sizePrefered, point: 0) )
    goto LABEL_18;
  if ( this->m_sizePrefered.cx > cx )
    cx = this->m_sizePrefered.cx;
  v11 = this->m_sizePrefered.cy;
  if ( v11 > 0 )
  {
    if ( v9->m_pPaletteButton == nullptr )
    {
      if ( v10 > v11 )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v14 = CWnd::FromHandle(hWnd: Parent);
        v15 = AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v14);
        if ( v15 != nullptr )
          v15[956].__vftable = (CObject_vtbl *)1;
      }
      v12 = this->m_sizePrefered.cy;
      goto LABEL_19;
    }
    if ( v10 <= v11 )
    {
      v12 = this->m_sizePrefered.cy;
      goto LABEL_19;
    }
LABEL_18:
    v12 = m_nSize;
    goto LABEL_19;
  }
  v12 = v9->m_rect.bottom - v9->m_rect.top;
LABEL_19:
  v16 = v45;
  v45->cx = cx;
  v16->cy = v12;
LABEL_20:
  v52 = -1;
  CClientDC::~CClientDC(this: &v39);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x10418BA7
// Name: public: virtual void CMFCRibbonPanelMenuBar::DoPaint(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonPanelMenuBar::DoPaint(CMFCRibbonPanelMenuBar *this, CDC *pDCPaint)
{
  CDC *p_m_dcMem; // eax
  CDC_vtbl *v4; // eax
  HRGN v5; // eax
  CDC_vtbl *v6; // esi
  CFont *Font; // eax
  CMFCVisualManager *Instance; // eax
  CDC *v9; // esi
  CMFCRibbonCategory *m_pParent; // eax
  CMFCVisualManager *v11; // eax
  CMFCVisualManager *v12; // eax
  CMFCVisualManager *v13; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-ACh]
  CMFCRibbonPanelMenuBar *m_pParentMenuBar; // [esp+10h] [ebp-94h]
  int v16; // [esp+14h] [ebp-90h]
  CMFCRibbonCategory *v17; // [esp+18h] [ebp-8Ch]
  CGdiObject v18; // [esp+1Ch] [ebp-88h] BYREF
  CDC *v19; // [esp+24h] [ebp-80h]
  CMemDC v20; // [esp+28h] [ebp-7Ch] BYREF
  tagRECT v21; // [esp+64h] [ebp-40h] BYREF
  RECT rc; // [esp+74h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+84h] [ebp-20h] BYREF
  int v24; // [esp+A0h] [ebp-4h]

  CMemDC::CMemDC(this: &v20, dc: pDCPaint, pWnd: (HDC__ *)this);
  v24 = 0;
  p_m_dcMem = &v20.m_dcMem;
  if ( v20.m_bMemDC == 0 )
    p_m_dcMem = v20.m_dc;
  v19 = p_m_dcMem;
  v4 = pDCPaint->__vftable;
  memset(&rc, 0, sizeof(rc));
  v4->GetClipBox(this: pDCPaint, a2: &rc);
  v18.m_hObject = nullptr;
  v18.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  LOBYTE(v24) = 1;
  if ( !IsRectEmpty(lprc: &rc) )
  {
    v5 = CreateRectRgnIndirect(lprect: &rc);
    CGdiObject::Attach(this: &v18, hObject: v5);
    CDC::SelectClipRgn(this: v19, pRgn: (CRgn *)&v18);
  }
  v6 = v19->__vftable;
  Font = CWnd::GetFont(this: this->m_pRibbonBar);
  v16 = (int)v6->SelectObject(this: v19, a2: Font);
  if ( v16 == 0 )
    AfxThrowInvalidArgException();
  CDC::SetBkMode(this: v19, nBkMode: 1);
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v21 = Rect;
  InflateRect(lprc: &v21, dx: 3, dy: 3);
  if ( this->m_pCategory != nullptr )
  {
    Instance = CMFCVisualManager::GetInstance();
    v9 = v19;
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonCategory *, int, int, int, int))Instance->OnDrawRibbonCategory)(
      a1: Instance,
      a2: v19,
      a3: this->m_pCategory,
      a4: v21.left,
      a5: v21.top,
      a6: v21.right,
      a7: v21.bottom);
    this->m_pCategory->OnDraw(this: this->m_pCategory, a2: v9);
  }
  else
  {
    m_pParent = this->m_pPanel->m_pParent;
    v17 = m_pParent;
    if ( m_pParent != nullptr )
    {
      m_pParentMenuBar = m_pParent->m_pParentMenuBar;
      m_pParent->m_pParentMenuBar = this;
      v11 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonCategory *, int, int, int, int))v11->OnDrawRibbonCategory)(
        a1: v11,
        a2: v19,
        a3: v17,
        a4: v21.left,
        a5: v21.top,
        a6: v21.right,
        a7: v21.bottom);
      v17->m_pParentMenuBar = m_pParentMenuBar;
    }
    else if ( this->m_bIsQATPopup != 0 )
    {
      v12 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonPanelMenuBar *, int, int, int, int))v12->OnFillRibbonQuickAccessToolBarPopup)(
        a1: v12,
        a2: v19,
        a3: this,
        a4: Rect.left,
        a5: Rect.top,
        a6: Rect.right,
        a7: Rect.bottom);
    }
    else
    {
      v13 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonPanelMenuBar *, int, int, int, int, int, int, int, int, _DWORD))v13->OnFillBarBackground)(
        a1: v13,
        a2: v19,
        a3: this,
        a4: Rect.left,
        a5: Rect.top,
        a6: Rect.right,
        a7: Rect.bottom,
        a8: Rect.left,
        a9: Rect.top,
        a10: Rect.right,
        a11: Rect.bottom,
        a12: 0);
    }
    this->m_pPanel->DoPaint(this: this->m_pPanel, a2: v19);
    v9 = v19;
  }
  v9->SelectObject(this: v9, a2: (CFont *)v16);
  CDC::SelectClipRgn(this: v9, pRgn: nullptr);
  LOBYTE(v24) = 0;
  v18.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v18);
  v24 = -1;
  CMemDC::~CMemDC(this: &v20);
}

//------------------------------------------------------------------------------
// Address: 0x10418DE5
// Name: protected: int CMFCRibbonPanelMenuBar::OnNeedTipText(unsigned int,struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanelMenuBar::OnNeedTipText(
        CMFCRibbonPanelMenuBar *this,
        unsigned int __formal,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pNMH,
        int *a4)
{
  CAfxStringMgr *StringManager; // eax
  CToolTipCtrl *m_pToolTip; // eax
  CWnd *v7; // esi
  HWND Parent; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  CMFCRibbonBaseElement *v11; // esi
  ATL::CStringData *v12; // eax
  CMFCToolTipCtrl *v13; // eax
  _DWORD *v14; // ecx
  CMFCRibbonBaseElement_vtbl *v15; // eax
  CMFCRibbonButton *v16; // eax
  int *p_left; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-5Ch]
  _DWORD v19[5]; // [esp-4h] [ebp-58h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v20; // [esp+10h] [ebp-44h]
  tagPOINT Point; // [esp+14h] [ebp-40h] BYREF
  _DWORD *v22; // [esp+1Ch] [ebp-38h]
  CMFCToolTipCtrl *v23; // [esp+20h] [ebp-34h] BYREF
  tagRECT v24; // [esp+24h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+34h] [ebp-20h] BYREF
  int v26; // [esp+50h] [ebp-4h]

  v20 = pNMH;
  if ( (_S1_45 & 1) == 0 )
  {
    _S1_45 |= 1u;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTipText_4, pStringMgr: StringManager);
    atexit(func: CMFCRibbonPanelMenuBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__);
  }
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr && pNMH->m_pszData == (char *)m_pToolTip->m_hWnd )
  {
    if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr
      || (v7 = (CWnd *)CMFCPopupMenu::m_pActivePopupMenu,
          Parent = GetParent(hWnd: this->m_hWnd),
          v7 == CWnd::FromHandle(hWnd: Parent)) )
    {
      TopLevelRibbonBar = CMFCRibbonPanelMenuBar::GetTopLevelRibbonBar(this);
      v22 = &TopLevelRibbonBar->__vftable;
      if ( TopLevelRibbonBar != nullptr && TopLevelRibbonBar->m_bToolTip == 0 )
        return 1;
      Point = 0;
      GetCursorPos(lpPoint: &Point);
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &Point);
      v11 = CMFCRibbonPanelMenuBar::HitTest(this, point: (CPoint)Point);
      if ( v11 != nullptr )
      {
        if ( v11->HasMenu(this: v11) != 0 && CMFCRibbonPanelMenuBar::IsMainPanel(this) )
          return 1;
        v12 = (ATL::CStringData *)v11->GetToolTipText(
                                    this: v11,
                                    result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v23);
        v26 = 0;
        ATL::CSimpleStringT<char,0>::operator=(this: &strTipText_4, strSrc: v12);
        v26 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)&v23[-1].m_ptLocation);
        if ( *((_DWORD *)strTipText_4.m_pszData - 3) != 0 )
        {
          v13 = (CMFCToolTipCtrl *)AfxDynamicDownCast(
                                     pClass: &CMFCToolTipCtrl::classCMFCToolTipCtrl,
                                     pObject: this->m_pToolTip);
          v23 = v13;
          if ( v13 != nullptr )
          {
            v14 = v22;
            if ( v22 == nullptr
              || (v22 = (_DWORD *)v22[179],
                  v13->m_nFixedWidthRegular = v14[178],
                  v13->m_nFixedWidthWithImage = (int)v22,
                  v14[192] != 0) )
            {
              v15 = v11->__vftable;
              v19[0] = v14;
              v22 = v19;
              v15->GetDescription(
                this: v11,
                result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v19);
              ((void (__thiscall *)(CMFCToolTipCtrl *))v23->SetDescription)(a1: v23);
            }
            v16 = (CMFCRibbonButton *)AfxDynamicDownCast(pClass: &CMFCRibbonButton::classCMFCRibbonButton, pObject: v11);
            CMFCToolTipCtrl::SetHotRibbonButton(this: v23, pRibbonButton: v16);
            if ( this->m_bIsMenuMode == 0 && !CMFCRibbonPanelMenuBar::IsMainPanel(this) )
            {
              v19[0] = &Rect;
              m_hWnd = this->m_hWnd;
              memset(&Rect, 0, sizeof(Rect));
              GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
              p_left = &v11->m_rect.left;
              v24.left = *p_left++;
              v24.top = *p_left++;
              v24.right = *p_left;
              v19[0] = &v24;
              v24.bottom = p_left[1];
              CWnd::ClientToScreen(this, lpRect: &v24);
              CMFCToolTipCtrl::SetLocation(this: v23, pt: (CPoint)__PAIR64__(Rect.bottom, v24.left));
            }
          }
          if ( this->m_bHasKeyTips != 0 )
            CWnd::SetWindowPos(
              this: this->m_pToolTip,
              pWndInsertAfter: &CWnd::wndTopMost,
              x: -1,
              y: -1,
              cx: -1,
              cy: -1,
              nFlags: 0x13u);
          v20[3].m_pszData = strTipText_4.m_pszData;
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10419019
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCRibbonPanelMenuBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCRibbonPanelMenuBar::GetMessageMap(CMFCRibbonPanelMenuBar *this)
{
  return (const AFX_MSGMAP *)&off_1068E220;
}

//------------------------------------------------------------------------------
// Address: 0x1041901F
// Name: private: virtual void CMFCOutlookBarScrollButton::OnFillBackground(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarScrollButton::OnFillBackground(
        CMFCOutlookBarScrollButton *this,
        CDC *pDC,
        const CRect *rectClient)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  Instance->OnFillOutlookPageButton(
    this: Instance,
    a2: pDC,
    a3: rectClient,
    a4: this->m_bHighlighted,
    a5: this->m_bPushed,
    a6: &afxGlobalData.clrBarText);
}

//------------------------------------------------------------------------------
// Address: 0x10419052
// Name: private: virtual void CMFCOutlookBarScrollButton::OnDrawBorder(class CDC __near *,class CRect __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarScrollButton::OnDrawBorder(
        CMFCOutlookBarScrollButton *this,
        CDC *pDC,
        CRect *rectClient,
        unsigned int __formal)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  Instance->OnDrawOutlookPageButtonBorder(
    this: Instance,
    a2: pDC,
    a3: rectClient,
    a4: this->m_bHighlighted,
    a5: this->m_bPushed);
}

//------------------------------------------------------------------------------
// Address: 0x10419080
// Name: public: virtual COutlookCustomizeButton::~COutlookCustomizeButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COutlookCustomizeButton::~COutlookCustomizeButton(COutlookCustomizeButton *this)
{
  CMFCCustomizeButton::~CMFCCustomizeButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x10419085
// Name: public: virtual struct CRuntimeClass __near * COutlookCustomizeButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COutlookCustomizeButton::GetRuntimeClass(COutlookCustomizeButton *this)
{
  return &COutlookCustomizeButton::classCOutlookCustomizeButton;
}

//------------------------------------------------------------------------------
// Address: 0x1041908B
// Name: public: virtual void COutlookCustomizeButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookCustomizeButton::OnDraw(
        COutlookCustomizeButton *this,
        CDC *pDC,
        const CRect *rect,
        CMFCToolBarImages *__formal,
        int a5,
        int a6,
        int bHighlight,
        int a8,
        int a9)
{
  int v10; // eax
  int v11; // eax
  int v12; // edi
  int top; // ecx
  int v14; // eax
  int v15; // esi
  CPoint ptImage; // [esp+Ch] [ebp-18h] BYREF
  CSize v17; // [esp+14h] [ebp-10h] BYREF
  CSize sizeImage; // [esp+1Ch] [ebp-8h] BYREF

  this->m_bDefaultDraw = 1;
  if ( bHighlight != 0 || (v10 = this->IsDroppedDown(this)) != 0 )
    v10 = 1;
  CMFCToolBarButton::FillInterior(this, pDC, rect, bHighlight: v10, bMenuImage: 0);
  CMenuImages::Size(result: &sizeImage);
  v11 = (rect->right - rect->left - sizeImage.cx) / 2;
  if ( v11 < 0 )
    v11 = 0;
  v12 = rect->left + v11;
  top = rect->top;
  v14 = (rect->bottom - 2 * sizeImage.cy - top) / 2;
  if ( v14 < 0 )
    v14 = 0;
  v15 = top + v14;
  v17.cx = 0;
  v17.cy = 0;
  ptImage.x = v12;
  ptImage.y = top + v14;
  CMenuImages::Draw(pDC, id: IdMoreButtons, &ptImage, state: ImageBlack, sizeImage: &v17);
  v17.cy = v15 + sizeImage.cy;
  ptImage.x = 0;
  ptImage.y = 0;
  v17.cx = v12;
  CMenuImages::Draw(
    pDC,
    id: IdArrowDown,
    ptImage: (const CPoint *)&v17,
    state: ImageBlack,
    sizeImage: (const CSize *)&ptImage);
}

//------------------------------------------------------------------------------
// Address: 0x10419147
// Name: public: virtual struct CRuntimeClass __near * CMFCOutlookBarToolBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCOutlookBarToolBar::GetRuntimeClass(CMFCOutlookBarToolBar *this)
{
  return &CMFCOutlookBarToolBar::classCMFCOutlookBarToolBar;
}

//------------------------------------------------------------------------------
// Address: 0x1041914D
// Name: public: virtual void CMFCOutlookBarToolBar::OnCustomizeMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarToolBar::OnCustomizeMode(CMFCOutlookBarToolBar *this, int bSet)
{
  CMFCToolBar::OnCustomizeMode(this, bSet);
  CWnd::EnableWindow(this, bEnable: bSet == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10419172
// Name: public: virtual struct CRuntimeClass __near * CMFCOutlookBarTabCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCOutlookBarTabCtrl::GetRuntimeClass(CMFCOutlookBarTabCtrl *this)
{
  return &CMFCOutlookBarTabCtrl::classCMFCOutlookBarTabCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x10419178
// Name: public: virtual CMFCOutlookBarScrollButton::~CMFCOutlookBarScrollButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMFCOutlookBarScrollButton::~CMFCOutlookBarScrollButton(CMFCOutlookBarScrollButton *this)
{
  CMFCButton::~CMFCButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041919E
// Name: public: virtual int CMFCOutlookBarTabCtrl::Create(class CRect const __near &,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::Create(
        CMFCOutlookBarTabCtrl *this,
        const CRect *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  int result; // eax

  result = CWnd::Create(
             this,
             lpszClassName: nullptr,
             lpszWindowName: &var,
             dwStyle: 0x56000000u,
             rect,
             pParentWnd,
             nID,
             pContext: nullptr);
  if ( result != 0 )
  {
    this->SetTabsHeight(this);
    this->m_bHighLightTabs = 1;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104191DB
// Name: public: virtual int CMFCOutlookBarTabCtrl::IsPtInTabArea(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarTabCtrl::IsPtInTabArea(CMFCOutlookBarTabCtrl *this, CPoint point)
{
  BOOL result; // eax
  CRect rectBottom; // [esp+Ch] [ebp-24h] BYREF
  CRect rectTop; // [esp+1Ch] [ebp-14h] BYREF

  memset(&rectTop, 0, sizeof(rectTop));
  SetRectEmpty(lprc: &rectTop);
  memset(&rectBottom, 0, sizeof(rectBottom));
  SetRectEmpty(lprc: &rectBottom);
  this->GetTabArea(this, a2: &rectTop, a3: &rectBottom);
  CWnd::ScreenToClient(this, lpRect: &rectTop);
  CWnd::ScreenToClient(this, lpRect: &rectBottom);
  if ( PtInRect(lprc: &rectTop, pt: point.tagPOINT) )
    return true;
  result = PtInRect(lprc: &rectBottom, pt: point.tagPOINT);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419280
// Name: public: virtual void CMFCOutlookBarTabCtrl::GetTabArea(class CRect __near &,class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::GetTabArea(
        CMFCOutlookBarTabCtrl *this,
        CRect *rectTabAreaTop,
        CRect *rectTabAreaBottom)
{
  CRect *v4; // edi
  int v5; // eax
  _DWORD *v6; // esi
  int *v7; // esi
  int bottom; // ecx
  int *v9; // esi
  int *p_top; // edi
  int i; // [esp+Ch] [ebp-4h]

  SetRectEmpty(lprc: rectTabAreaTop);
  v4 = rectTabAreaBottom;
  SetRectEmpty(lprc: rectTabAreaBottom);
  v5 = 0;
  for ( i = 0; v5 < this->m_iTabsNum; i = v5 )
  {
    if ( v5 < 0 || v5 >= this->m_arTabs.m_nSize )
      AfxThrowInvalidArgException();
    v6 = this->m_arTabs.m_pData[v5];
    if ( v5 != 0 )
    {
      bottom = rectTabAreaTop->bottom;
      if ( bottom == v6[5] )
      {
        rectTabAreaTop->bottom = bottom + v6[7] - v6[5];
      }
      else
      {
        if ( IsRectEmpty(lprc: v4) )
        {
          v9 = v6 + 4;
          v4->left = *v9++;
          p_top = &v4->top;
          *p_top = *v9++;
          *++p_top = *v9;
          p_top[1] = v9[1];
          v4 = rectTabAreaBottom;
        }
        else
        {
          v4->bottom += v6[7] - v6[5];
        }
        v5 = i;
      }
    }
    else
    {
      v7 = v6 + 4;
      rectTabAreaTop->left = *v7++;
      rectTabAreaTop->top = *v7++;
      rectTabAreaTop->right = *v7;
      rectTabAreaTop->bottom = v7[1];
      v4 = rectTabAreaBottom;
    }
    ++v5;
  }
  CWnd::ClientToScreen(this, lpRect: rectTabAreaTop);
  CWnd::ClientToScreen(this, lpRect: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1041933E
// Name: protected: virtual int CMFCOutlookBarTabCtrl::GetTabNumberToDetach(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::GetTabNumberToDetach(CMFCOutlookBarTabCtrl *this, int nTabNum)
{
  int result; // eax

  result = nTabNum;
  if ( nTabNum == -1 )
    return this->m_iPressed;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419355
// Name: protected: virtual unsigned long CMFCOutlookBarTabCtrl::OnDragEnter(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCOutlookBarTabCtrl::OnDragEnter(
        CMFCOutlookBarTabCtrl *this,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  return ((unsigned int (__thiscall *)(CMFCOutlookBarTabCtrl *, COleDataObject *, unsigned int, int, int))this->OnDragOver)(
           a1: this,
           a2: pDataObject,
           a3: dwKeyState,
           a4: point.x,
           a5: point.y);
}

//------------------------------------------------------------------------------
// Address: 0x10419372
// Name: protected: virtual unsigned long CMFCOutlookBarTabCtrl::OnDragOver(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarTabCtrl::OnDragOver(
        CMFCOutlookBarTabCtrl *this,
        COleDataObject *pDataObject,
        char dwKeyState,
        CPoint point)
{
  CMFCToolBarButton *v5; // eax
  int *v6; // esi
  bool v8; // zf
  int v9; // eax
  int v10; // eax

  v5 = CMFCToolBarButton::CreateFromOleData(pDataObject);
  v6 = (int *)v5;
  if ( v5 == nullptr )
    return 0;
  v8 = CObject::IsKindOf(this: v5, pClass: &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton) == 0;
  v9 = *v6;
  if ( v8 )
  {
    (*(void (__thiscall **)(int *, int))(v9 + 4))(a1: v6, a2: 1);
    return 0;
  }
  (*(void (__thiscall **)(int *, int))(v9 + 4))(a1: v6, a2: 1);
  v10 = this->GetTabFromPoint(this, a2: &point);
  if ( v10 < 0 )
    return 0;
  this->SetActiveTab(this, a2: v10);
  return ((dwKeyState & 8) == 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x104193D9
// Name: protected: void CMFCOutlookBarTabCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnLButtonUp(CMFCOutlookBarTabCtrl *this, unsigned int nFlags, CPoint point)
{
  if ( this->m_bIsTracking != 0 )
  {
    ReleaseCapture();
    this->m_bIsTracking = 0;
  }
  CMFCBaseTabCtrl::OnLButtonUp(this, nFlags, point);
}

//------------------------------------------------------------------------------
// Address: 0x1041940E
// Name: protected: void CMFCOutlookBarTabCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnCancelMode(CMFCOutlookBarTabCtrl *this)
{
  CMFCBaseTabCtrl::OnCancelMode(this);
  if ( this->m_bIsTracking != 0 )
  {
    ReleaseCapture();
    this->m_bIsTracking = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10419430
// Name: public: virtual void CMFCOutlookBarTabCtrl::OnShowMorePageButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnShowMorePageButtons(CMFCOutlookBarTabCtrl *this)
{
  CMFCOutlookBarTabCtrl_vtbl *v1; // eax
  int *p_m_bDontAdjustLayout; // esi

  v1 = this->__vftable;
  ++this->m_nVisiblePageButtons;
  p_m_bDontAdjustLayout = &this->m_bDontAdjustLayout;
  this->m_bDontAdjustLayout = 1;
  ((void (*)(void))v1->RecalcLayout)();
  *p_m_bDontAdjustLayout = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10419450
// Name: public: virtual void CMFCOutlookBarTabCtrl::OnShowFewerPageButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnShowFewerPageButtons(CMFCOutlookBarTabCtrl *this)
{
  CMFCOutlookBarTabCtrl_vtbl *v1; // eax
  int *p_m_bDontAdjustLayout; // esi

  v1 = this->__vftable;
  --this->m_nVisiblePageButtons;
  p_m_bDontAdjustLayout = &this->m_bDontAdjustLayout;
  this->m_bDontAdjustLayout = 1;
  ((void (*)(void))v1->RecalcLayout)();
  *p_m_bDontAdjustLayout = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10419470
// Name: public: virtual int CMFCOutlookBarTabCtrl::CanShowMorePageButtons(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarTabCtrl::CanShowMorePageButtons(CMFCOutlookBarTabCtrl *this)
{
  return this->m_nVisiblePageButtons < this->m_nMaxVisiblePageButtons;
}

//------------------------------------------------------------------------------
// Address: 0x10419484
// Name: public: virtual int CMFCOutlookBarTabCtrl::CanShowFewerPageButtons(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarTabCtrl::CanShowFewerPageButtons(CMFCOutlookBarTabCtrl *this)
{
  return this->m_nVisiblePageButtons > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10419490
// Name: public: virtual void CMFCOutlookBarTabCtrl::OnChangeTabs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnChangeTabs(CMFCOutlookBarTabCtrl *this)
{
  this->m_nVisiblePageButtons = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10419498
// Name: protected: void CMFCOutlookBarTabCtrl::OnToolbarCommand(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnToolbarCommand(CMFCOutlookBarTabCtrl *this, unsigned int id)
{
  switch ( id )
  {
    case 0xF200u:
      this->OnShowMorePageButtons(this);
      break;
    case 0xF201u:
      this->OnShowFewerPageButtons(this);
      break;
    case 0xF202u:
      this->OnShowOptions(this);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104194CD
// Name: protected: void CMFCOutlookBarTabCtrl::OnUpdateToolbarCommand(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarTabCtrl::OnUpdateToolbarCommand(CMFCOutlookBarTabCtrl *this, CCmdUI *pCmdUI)
{
  CCmdUI_vtbl *v2; // edi
  int v3; // eax

  if ( pCmdUI->m_nID == 61952 )
  {
    v2 = pCmdUI->__vftable;
    v3 = this->CanShowMorePageButtons(this);
  }
  else
  {
    if ( pCmdUI->m_nID != 61953 )
      return;
    v2 = pCmdUI->__vftable;
    v3 = this->CanShowFewerPageButtons(this);
  }
  v2->Enable(this: pCmdUI, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10419505
// Name: public: virtual COutlookOptionsDlg::~COutlookOptionsDlg(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COutlookOptionsDlg::~COutlookOptionsDlg(COutlookOptionsDlg *this)
{
  CMFCToolBarsListCheckBox::~CMFCToolBarsListCheckBox(this: &this->m_wndList);
  CButton::~CButton(this: &this->m_wndReset);
  CButton::~CButton(this: &this->m_wndMoveDown);
  CButton::~CButton(this: &this->m_btnMoveUp);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042E2C8
// Name: protected: void CMFCToolBarEditCtrl::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditCtrl::OnContextMenu(CMFCToolBarEditCtrl *this, CWnd *pWnd, CPoint point)
{
  CMFCToolBarEditCtrl *v3; // esi
  HWND Parent; // eax
  CWnd *v5; // ebx
  HINSTANCE__ *m_hCurrentResourceHandle; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  HWND m_hWnd; // ecx

  v3 = this;
  if ( this->m_buttonEdit->m_uiMenuResID == 0 )
    goto LABEL_4;
  Parent = GetParent(hWnd: pWnd->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  if ( m_hCurrentResourceHandle == nullptr
    || (MenuW = LoadMenuW(
                  hInstance: m_hCurrentResourceHandle,
                  lpMenuName: (LPCWSTR)LOWORD(v3->m_buttonEdit->m_uiMenuResID))) == nullptr
    || (SubMenu = GetSubMenu(hMenu: MenuW, nPos: 0)) == nullptr )
  {
    this = v3;
LABEL_4:
    CWnd::Default(this);
    return;
  }
  if ( afxContextMenuManager != nullptr )
  {
    afxContextMenuManager->ShowPopupMenu(
      this: afxContextMenuManager,
      a2: SubMenu,
      a3: point.x,
      a4: point.y,
      a5: v5,
      a6: 0,
      a7: 1,
      a8: 0);
  }
  else
  {
    if ( v5 != nullptr )
      m_hWnd = v5->m_hWnd;
    else
      m_hWnd = nullptr;
    TrackPopupMenu(hMenu: SubMenu, uFlags: 4u, x: point.x, y: point.y, nReserved: 0, hWnd: m_hWnd, prcRect: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042E371
// Name: public: CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarEditBoxButton *__thiscall CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton(CMFCToolBarEditBoxButton *this)
{
  CAfxStringMgr *StringManager; // eax

  CMFCToolBarButton::CMFCToolBarButton(this);
  this->__vftable = (CMFCToolBarEditBoxButton_vtbl *)&CMFCToolBarEditBoxButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strContents, pStringMgr: StringManager);
  this->m_dwStyle = 1342177408;
  this->m_iWidth = 150;
  CMFCToolBarEditBoxButton::Initialize(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042E3A8
// Name: public: virtual struct HWND__ __near * CMFCToolBarEditBoxButton::GetHwnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEdit *__thiscall CMFCToolBarEditBoxButton::GetHwnd(CMFCToolBarEditBoxButton *this)
{
  CEdit *result; // eax

  result = this->m_pWndEdit;
  if ( result != nullptr )
    return (CEdit *)result->m_hWnd;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042E3B4
// Name: public: virtual int CMFCToolBarEditBoxButton::HaveHotBorder(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarEditBoxButton::HaveHotBorder(CMFCToolBarEditBoxButton *this)
{
  CEdit *m_pWndEdit; // ecx

  m_pWndEdit = this->m_pWndEdit;
  return m_pWndEdit == nullptr || m_pWndEdit->m_hWnd == nullptr || (CWnd::GetStyle(this: m_pWndEdit) & 0x10000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042E3D4
// Name: public: virtual CMFCToolBarEditBoxButton::~CMFCToolBarEditBoxButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::~CMFCToolBarEditBoxButton(CMFCToolBarEditBoxButton *this)
{
  CEdit *m_pWndEdit; // ecx
  CEdit *v3; // ecx

  this->__vftable = (CMFCToolBarEditBoxButton_vtbl *)&CMFCToolBarEditBoxButton::`vftable';
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit != nullptr )
  {
    m_pWndEdit->DestroyWindow(this: m_pWndEdit);
    v3 = this->m_pWndEdit;
    if ( v3 != nullptr )
      ((void (__thiscall *)(CEdit *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strContents.m_pszData - 1);
  CMFCToolBarButton::~CMFCToolBarButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042E428
// Name: public: virtual struct tagSIZE CMFCToolBarEditBoxButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CMFCToolBarEditBoxButton::OnCalculateSize(
        CMFCToolBarEditBoxButton *this,
        CDC *pDC,
        CDC *sizeDefault,
        CSize *bHorz,
        int bHorza)
{
  CEdit *m_pWndEdit; // ecx
  int v7; // edx
  int cy; // eax
  int v9; // eax
  CDC_vtbl *m_iWidth; // eax
  HDC__ *v11; // esi
  CRect rectText; // [esp+14h] [ebp-14h] BYREF

  m_pWndEdit = this->m_pWndEdit;
  if ( this->m_bVisible != 0 )
  {
    this->m_bHorz = bHorza;
    if ( bHorza != 0 )
    {
      if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr && this->m_bIsHidden == 0 )
      {
        CWnd::ShowWindow(this: m_pWndEdit, nCmdShow: 4);
        this->OnShowEditbox(this, a2: 1);
      }
      if ( this->m_bTextBelow != 0 && *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
      {
        v7 = (int)sizeDefault->__vftable;
        rectText.right = this->m_iWidth;
        cy = bHorz->cy;
        rectText.left = 0;
        rectText.top = 0;
        rectText.bottom = cy;
        (*(void (__thiscall **)(CDC *, char *, _DWORD, CRect *, int))(v7 + 104))(
          a1: sizeDefault,
          a2: this->m_strText.m_pszData,
          a3: *((_DWORD *)this->m_strText.m_pszData - 3),
          a4: &rectText,
          a5: 1041);
        v9 = rectText.right - rectText.left;
        this->m_sizeText.cy = rectText.bottom - rectText.top;
      }
      else
      {
        v9 = 0;
        this->m_sizeText.cy = 0;
      }
      this->m_sizeText.cx = v9;
      m_iWidth = (CDC_vtbl *)this->m_iWidth;
      v11 = (HDC__ *)(bHorz->cy + this->m_sizeText.cy);
      pDC->__vftable = m_iWidth;
      pDC->m_hDC = v11;
    }
    else
    {
      if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
      {
        CWnd::ShowWindow(this: m_pWndEdit, nCmdShow: 0);
        this->OnShowEditbox(this, a2: 0);
      }
      this->m_sizeText.cx = 0;
      this->m_sizeText.cy = 0;
      CMFCToolBarButton::OnCalculateSize(this, pDC, (const CSize *)sizeDefault, bHorz: &bHorz->cx, a5: 0);
    }
  }
  else
  {
    if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
      CWnd::ShowWindow(this: m_pWndEdit, nCmdShow: 0);
    this->OnShowEditbox(this, a2: 0);
    pDC->__vftable = nullptr;
    pDC->m_hDC = nullptr;
  }
  return pDC;
}

//------------------------------------------------------------------------------
// Address: 0x1042E55A
// Name: public: virtual void CMFCToolBarEditBoxButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::OnDraw(
        CMFCToolBarEditBoxButton *this,
        CDC *pDC,
        const CRect *rect,
        CMFCToolBarImages *pImages,
        int bHorz,
        int bCustomizeMode,
        int bHighlight,
        int bDrawBorder,
        int bGrayDisabledButtons)
{
  CEdit *m_pWndEdit; // ecx
  int v11; // esi
  int v12; // edi
  CMFCToolBarEditBoxButton_vtbl *v13; // eax
  CMFCVisualManager *Instance; // eax
  unsigned int HotTextColor; // eax
  int v16; // eax
  char *m_pszData; // ebx
  CRect rectText; // [esp+18h] [ebp-24h] BYREF
  CRect rectBorder; // [esp+28h] [ebp-14h] BYREF

  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit == nullptr || m_pWndEdit->m_hWnd == nullptr || (CWnd::GetStyle(this: m_pWndEdit) & 0x10000000) == 0 )
  {
    CMFCToolBarButton::OnDraw(
      this,
      pDC,
      rect,
      pImages,
      bHorz,
      bCustomizeMode,
      bHighlight,
      bDrawBorder,
      bGrayDisabledButtons);
    return;
  }
  v11 = 0;
  if ( bCustomizeMode == 0 )
  {
    if ( (this->m_nStyle & 0x40000) == 0 )
      goto LABEL_6;
LABEL_18:
    v12 = 1;
    goto LABEL_7;
  }
  if ( this->IsEditable(this) == 0 )
    goto LABEL_18;
LABEL_6:
  v12 = 0;
LABEL_7:
  v13 = this->__vftable;
  memset(&rectBorder, 0, sizeof(rectBorder));
  v13->GetEditBorder(this, a2: &rectBorder);
  if ( CMFCToolBarEditBoxButton::m_bFlat == 0 || this->m_bIsHotEdit != 0 )
    v11 = 1;
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, int, CMFCToolBarEditBoxButton *))Instance->OnDrawEditBorder)(
    a1: Instance,
    a2: pDC,
    a3: rectBorder.left,
    a4: rectBorder.top,
    a5: rectBorder.right,
    a6: rectBorder.bottom,
    a7: v12,
    a8: v11,
    a9: this);
  if ( this->m_bTextBelow != 0 && bHorz != 0 && *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    if ( bCustomizeMode != 0 )
    {
      if ( this->IsEditable(this) != 0 )
        goto LABEL_15;
    }
    else if ( (this->m_nStyle & 0x40000) == 0 )
    {
LABEL_15:
      if ( bHighlight != 0 )
        HotTextColor = CMFCToolBar::GetHotTextColor();
      else
        HotTextColor = afxGlobalData.clrBtnText;
      goto LABEL_22;
    }
    HotTextColor = afxGlobalData.clrGrayedText;
LABEL_22:
    pDC->SetTextColor(this: pDC, a2: HotTextColor);
    v16 = rect->bottom - this->m_sizeText.cy;
    m_pszData = this->m_strText.m_pszData;
    rectText = *rect;
    rectText.top = (rectBorder.bottom + v16) / 2;
    pDC->DrawTextA(this: pDC, a2: m_pszData, a3: *((_DWORD *)m_pszData - 3), a4: &rectText, a5: 17u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042E6DE
// Name: public: virtual class CRect const CMFCToolBarEditBoxButton::GetInvalidateRect(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CRect *__thiscall CMFCToolBarEditBoxButton::GetInvalidateRect(
        CMFCToolBarEditBoxButton *this,
        const CRect *result)
{
  int left; // edi
  int cx; // esi
  int right; // ebx
  int v5; // edx
  int v6; // edx
  CRect *p_rect; // esi
  int *p_top; // esi
  CRect rect; // [esp+8h] [ebp-10h] BYREF

  if ( this->m_bTextBelow != 0 && this->m_bHorz != 0 && *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    left = this->m_rect.left;
    cx = this->m_sizeText.cx;
    right = this->m_rect.right;
    rect.left = (right + left - cx) / 2;
    v5 = this->m_rect.bottom + this->m_sizeText.cy;
    rect.right = (right + left + cx) / 2;
    v6 = this->m_rect.top + v5;
    rect.top = this->m_rect.top;
    rect.bottom = v6;
    p_rect = &rect;
  }
  else
  {
    p_rect = &this->m_rect;
  }
  result->left = p_rect->left;
  p_top = &p_rect->top;
  result->top = *p_top++;
  result->right = *p_top;
  result->bottom = p_top[1];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042E74D
// Name: public: virtual int CMFCToolBarEditBoxButton::OnUpdateToolTip(class CWnd __near *,int,class CToolTipCtrl __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarEditBoxButton::OnUpdateToolTip(
        CMFCToolBarEditBoxButton *this,
        CWnd *__formal,
        int a3,
        CToolTipCtrl *wndToolTip,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str)
{
  CEdit *m_pWndEdit; // esi
  CAfxStringMgr *StringManager; // eax
  CMFCToolBarEditBoxButton_vtbl *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTips; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit == nullptr || !IsWindow(hWnd: m_pWndEdit->m_hWnd) )
    return 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTips, pStringMgr: StringManager);
  v8 = this->__vftable;
  v11 = 0;
  if ( v8->OnGetCustomToolTipText(this, a2: &strTips) != 0 )
    CToolTipCtrl::AddTool(
      this: wndToolTip,
      pWnd: m_pWndEdit,
      lpszText: strTips.m_pszData,
      lpRectTool: nullptr,
      nIDTool: 0);
  else
    CToolTipCtrl::AddTool(this: wndToolTip, pWnd: m_pWndEdit, lpszText: str->m_pszData, lpRectTool: nullptr, nIDTool: 0);
  ATL::CStringData::Release(this: (ATL::CStringData *)strTips.m_pszData - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042E7C3
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarEditCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarEditCtrl::GetMessageMap(CMFCToolBarEditCtrl *this)
{
  return (const AFX_MSGMAP *)&off_10694390;
}

//------------------------------------------------------------------------------
// Address: 0x1042E7C9
// Name: public: static class CObject __near * CMFCToolBarEditBoxButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarEditBoxButton *__stdcall CMFCToolBarEditBoxButton::CreateObject()
{
  CMFCToolBarEditBoxButton *v0; // ecx
  CMFCToolBarEditBoxButton *result; // eax

  v0 = (CMFCToolBarEditBoxButton *)operator new(nSize: 0x90u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042E81A
// Name: public: virtual void CMFCToolBarEditBoxButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::CopyFrom(CMFCToolBarEditBoxButton *this, const CMFCToolBarButton *s)
{
  CMFCToolBarButton::CopyFrom(this, src: s);
  this->m_dwStyle = s[1].m_bUserButton;
  this->m_iWidth = (int)s[1].__vftable;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strContents, strSrc: (ATL::CStringData *)&s[1].m_bImage);
  this->m_uiMenuResID = s[1].m_bDragFromCollection;
}

//------------------------------------------------------------------------------
// Address: 0x1042E856
// Name: public: virtual void CMFCToolBarEditBoxButton::OnChangeParentWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::OnChangeParentWnd(CMFCToolBarEditBoxButton *this, CWnd *pWndParent)
{
  CEdit *m_pWndEdit; // eax
  HWND Parent; // eax
  CWnd *v5; // eax
  CEdit *v6; // ecx
  CMFCToolBarEditBoxButton_vtbl *v7; // eax
  CEdit *v8; // eax
  CAfxStringMgr *StringManager; // eax
  CEdit *v10; // ecx
  CEdit *v11; // ecx
  char *m_pszData; // [esp-4h] [ebp-3Ch]
  ATL::CSimpleStringT<char,0> strSrc; // [esp+14h] [ebp-24h] BYREF
  tagRECT rc; // [esp+18h] [ebp-20h] BYREF
  int v15; // [esp+34h] [ebp-4h]

  CMFCToolBarButton::OnChangeParentWnd(this, pWndParent);
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit == nullptr || m_pWndEdit->m_hWnd == nullptr )
  {
LABEL_10:
    if ( pWndParent != nullptr && pWndParent->m_hWnd != nullptr )
    {
      rc = (tagRECT)this->m_rect;
      InflateRect(lprc: &rc, dx: -3, dy: -1);
      v7 = this->__vftable;
      rc.bottom = rc.top + afxGlobalData.m_nTextHeightHorz;
      v8 = v7->CreateEdit(this, a2: pWndParent, a3: (const CRect *)&rc);
      this->m_pWndEdit = v8;
      if ( v8 != nullptr )
      {
        this->OnMove(this);
        SendMessageA(
          hWnd: this->m_pWndEdit->m_hWnd,
          Msg: 0x30u,
          wParam: (WPARAM)afxGlobalData.fontRegular.m_hObject,
          lParam: 1);
        StringManager = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strSrc, pStringMgr: StringManager);
        v10 = this->m_pWndEdit;
        v15 = 0;
        CWnd::GetWindowTextA(
          this: v10,
          rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&strSrc);
        if ( *((_DWORD *)strSrc.m_pszData - 3) != 0 )
        {
          ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strContents, (ATL::CStringData *)&strSrc);
        }
        else
        {
          m_pszData = this->m_strContents.m_pszData;
          v11 = this->m_pWndEdit;
          this->m_bChangingText = 1;
          CWnd::SetWindowTextA(this: v11, lpszString: m_pszData);
          this->m_bChangingText = 0;
        }
        ATL::CStringData::Release(this: (ATL::CStringData *)strSrc.m_pszData - 1);
      }
    }
    return;
  }
  Parent = GetParent(hWnd: m_pWndEdit->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  if ( v5 == nullptr )
    AfxThrowInvalidArgException();
  if ( pWndParent == nullptr || v5->m_hWnd != pWndParent->m_hWnd )
  {
    CWnd::GetWindowTextA(this: this->m_pWndEdit, rString: &this->m_strContents);
    this->m_pWndEdit->DestroyWindow(this: this->m_pWndEdit);
    v6 = this->m_pWndEdit;
    if ( v6 != nullptr )
      ((void (__thiscall *)(CEdit *, int))v6->dtr_CObject)(a1: v6, a2: 1);
    this->m_pWndEdit = nullptr;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042E9A7
// Name: public: virtual void CMFCToolBarEditBoxButton::SetContents(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::SetContents(CMFCToolBarEditBoxButton *this, ATL::CStringData *sContents)
{
  CEdit *m_pWndEdit; // ecx
  char *m_pszData; // [esp-4h] [ebp-10h]

  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
         this: &this->m_strContents,
         psz: (const char *)sContents->pStringMgr) != 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strContents, strSrc: sContents);
    m_pWndEdit = this->m_pWndEdit;
    if ( m_pWndEdit != nullptr )
    {
      m_pszData = this->m_strContents.m_pszData;
      this->m_bChangingText = 1;
      CWnd::SetWindowTextA(this: m_pWndEdit, lpszString: m_pszData);
      this->m_bChangingText = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C0D30
// Name: _dynamic_initializer_for__g_uToggleStateMsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uToggleStateMsg__()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_ToggleState");
  g_uToggleStateMsg = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0D50
// Name: _dynamic_initializer_for__g_uLeftDragDropMsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uLeftDragDropMsg__()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_LeftDragDrop");
  g_uLeftDragDropMsg = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0D70
// Name: _dynamic_initializer_for__g_uRightDragDropMsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uRightDragDropMsg__()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_RightDragDrop");
  g_uRightDragDropMsg = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0D90
// Name: _dynamic_initializer_for__g_uSelChangeMsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uSelChangeMsg__()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_SelChange");
  g_uSelChangeMsg = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0DB0
// Name: _dynamic_initializer_for__g_uKeyDownMsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uKeyDownMsg__()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_KeyDown");
  g_uKeyDownMsg = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0DD0
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0DE0
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0DF0
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E00
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E10
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E20
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E30
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E40
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E50
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E60
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E70
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E80
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0E90
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0EA0
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0EB0
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0EC0
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0ED0
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0EE0
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0EF0
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F00
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F10
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F20
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F30
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F40
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F50
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F60
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F70
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F80
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0F90
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0FA0
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0FB0
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0FC0
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0FD0
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x105C0FE0
// Name: _dynamic_initializer_for__g_uSelChangeMsg___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uSelChangeMsg___0()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_SelChange");
  g_uSelChangeMsg_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C1000
// Name: _dynamic_initializer_for__g_uToggleStateMsg___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uToggleStateMsg___0()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_ToggleState");
  g_uToggleStateMsg_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C1020
// Name: _dynamic_initializer_for__g_uLeftDragDropMsg___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uLeftDragDropMsg___0()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_LeftDragDrop");
  g_uLeftDragDropMsg_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C1040
// Name: _dynamic_initializer_for__g_uRightDragDropMsg___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uRightDragDropMsg___0()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_RightDragDrop");
  g_uRightDragDropMsg_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C1060
// Name: _dynamic_initializer_for__g_uSelChangeMsg___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uSelChangeMsg___1()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_SelChange");
  g_uSelChangeMsg_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C1080
// Name: _dynamic_initializer_for__g_uKeyDownMsg___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uKeyDownMsg___0()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_KeyDown");
  g_uKeyDownMsg_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C10A0
// Name: _dynamic_initializer_for__g_uSelChangeMsg___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uSelChangeMsg___2()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_SelChange");
  g_uSelChangeMsg_2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C10C0
// Name: _dynamic_initializer_for__e_CMapClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__e_CMapClass__()
{
  CMapClass::CMapClass(this: &e_CMapClass.CMapClass);
  e_CMapClass.CObject::__vftable = (editCMapClass_vtbl *)&editCMapClass::`vftable'{for `CObject'};
  e_CMapClass.CMapClass::CMapPoint::CMapAtom::__vftable = (CMapClass_vtbl *)&editCMapClass::`vftable'{for `CMapClass'};
  return atexit(func: dynamic_atexit_destructor_for__e_CMapClass__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1120
// Name: _dynamic_initializer_for__e_CEditGameClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__e_CEditGameClass__()
{
  CEditGameClass::CEditGameClass(this: &e_CEditGameClass.CEditGameClass);
  e_CEditGameClass.CObject::__vftable = (editCEditGameClass_vtbl *)&editCEditGameClass::`vftable'{for `CObject'};
  e_CEditGameClass.CEditGameClass::__vftable = (CEditGameClass_vtbl *)&editCEditGameClass::`vftable'{for `CEditGameClass'};
  return atexit(func: dynamic_atexit_destructor_for__e_CEditGameClass__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1180
// Name: _dynamic_initializer_for__kvClipboard__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kvClipboard__()
{
  WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(this: &kvClipboard);
  return atexit(func: dynamic_atexit_destructor_for__kvClipboard__);
}

//------------------------------------------------------------------------------
// Address: 0x105C11A0
// Name: _dynamic_initializer_for__g_uToggleStateMsg___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT dynamic_initializer_for__g_uToggleStateMsg___1()
{
  UINT result; // eax

  result = RegisterWindowMessageA(lpString: "TreeList_ToggleState");
  g_uToggleStateMsg_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C11C0
// Name: _dynamic_initializer_for__COP_Output::m_pConnectionBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *dynamic_initializer_for__COP_Output::m_pConnectionBuffer__()
{
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *result; // eax
  CEntityConnection **m_pMemory; // edx

  result = (CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *)operator new(nSize: 0x14u);
  if ( result != nullptr )
  {
    result->m_Memory.m_pMemory = nullptr;
    result->m_Memory.m_nAllocationCount = 0;
    result->m_Memory.m_nGrowSize = 0;
    m_pMemory = result->m_Memory.m_pMemory;
    result->m_Size = 0;
    result->m_pElements = m_pMemory;
    COP_Output::m_pConnectionBuffer = result;
  }
  else
  {
    COP_Output::m_pConnectionBuffer = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105CAFC0
// Name: _VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl VmfGetSaveLoadHandlers_::_2_::_dynamic_atexit_destructor_for__s_arrHandlers__()
{
  vgui::TreeNode **m_pMemory; // eax

  m_pMemory = stru_107B0610.m_pMemory;
  num = 0;
  if ( stru_107B0610.m_nGrowSize >= 0 )
  {
    if ( stru_107B0610.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stru_107B0610.m_pMemory);
      m_pMemory = nullptr;
      stru_107B0610.m_pMemory = nullptr;
    }
    stru_107B0610.m_nAllocationCount = 0;
  }
  dword_107B0620 = (int)m_pMemory;
  if ( stru_107B0610.m_nGrowSize >= 0 )
  {
    if ( stru_107B0610.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stru_107B0610.m_pMemory);
      stru_107B0610.m_pMemory = nullptr;
    }
    stru_107B0610.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CB060
// Name: _VmfAddMapEntityHandlers_::_2_::_dynamic_atexit_destructor_for__arrHandlerInfos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl VmfAddMapEntityHandlers_::_2_::_dynamic_atexit_destructor_for__arrHandlerInfos__()
{
  VmfSaveLoadHandlerInfo_t *m_pMemory; // eax

  m_pMemory = arrHandlerInfos.m_Memory.m_pMemory;
  arrHandlerInfos.m_Size = 0;
  if ( arrHandlerInfos.m_Memory.m_nGrowSize >= 0 )
  {
    if ( arrHandlerInfos.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrHandlerInfos.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      arrHandlerInfos.m_Memory.m_pMemory = nullptr;
    }
    arrHandlerInfos.m_Memory.m_nAllocationCount = 0;
  }
  arrHandlerInfos.m_pElements = m_pMemory;
  if ( arrHandlerInfos.m_Memory.m_nGrowSize >= 0 )
  {
    if ( arrHandlerInfos.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrHandlerInfos.m_Memory.m_pMemory);
      arrHandlerInfos.m_Memory.m_pMemory = nullptr;
    }
    arrHandlerInfos.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CB100
// Name: _dynamic_atexit_destructor_for__e_CMapClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__e_CMapClass__()
{
  CMapClass::~CMapClass(this: &e_CMapClass.CMapClass);
}

//------------------------------------------------------------------------------
// Address: 0x105CB140
// Name: _dynamic_atexit_destructor_for__e_CEditGameClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__e_CEditGameClass__()
{
  CEditGameClass::~CEditGameClass(this: &e_CEditGameClass.CEditGameClass);
}

//------------------------------------------------------------------------------
// Address: 0x105CB180
// Name: _dynamic_atexit_destructor_for__kvClipboard__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kvClipboard__()
{
  WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &kvClipboard);
}
