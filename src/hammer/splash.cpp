// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/splash.cpp
// Functions: 104
// ============================================================

#include "hammer\splash.h"

//------------------------------------------------------------------------------
// Address: 0x100A5C40
// Name: public: static void CSplashWnd::EnableSplashScreen(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSplashWnd::EnableSplashScreen(bool bEnable)
{
  s_bShowSplashWnd = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A5C50
// Name: public: virtual void CSplashWnd::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplashWnd::PostNcDestroy(CSplashWnd *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CSplashWnd *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100A5C60
// Name: public: int CDC::CreateCompatibleDC(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDC::CreateCompatibleDC(CDC *this, CDC *pDC)
{
  HDC CompatibleDC; // eax

  if ( pDC != nullptr )
    CompatibleDC = CreateCompatibleDC(hdc: pDC->m_hDC);
  else
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  return CDC::Attach(this, hDC: CompatibleDC);
}

//------------------------------------------------------------------------------
// Address: 0x100A5CA0
// Name: public: int CDC::BitBlt(int,int,int,int,class CDC __near *,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDC::BitBlt(
        CDC *this,
        int x,
        int y,
        int nWidth,
        int nHeight,
        HDC__ *pSrcDC,
        int xSrc,
        int ySrc,
        DWORD dwRop)
{
  HDC__ *v9; // eax

  v9 = pSrcDC;
  if ( pSrcDC != nullptr )
    v9 = *((HDC__ **)pSrcDC + 1);
  return BitBlt(hdc: this->m_hDC, x, y, cx: nWidth, cy: nHeight, hdcSrc: v9, x1: xSrc, y1: ySrc, rop: dwRop);
}

//------------------------------------------------------------------------------
// Address: 0x100A5CE0
// Name: public: static void CSplashWnd::HideSplashScreen(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSplashWnd::HideSplashScreen()
{
  if ( s_pSplashWnd != nullptr )
  {
    if ( s_pSplashWnd->m_bMinTimerExpired )
      ((void (*)(void))s_pSplashWnd->DestroyWindow)();
    else
      s_pSplashWnd->m_bHideRequested = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5D00
// Name: protected: void CSplashWnd::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplashWnd::OnTimer(CSplashWnd *this, UINT_PTR nIDEvent)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-Ch]

  m_hWnd = this->m_hWnd;
  this->m_bMinTimerExpired = true;
  KillTimer(hWnd: m_hWnd, uIDEvent: nIDEvent);
  if ( this->m_bHideRequested )
    this->DestroyWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A5D30
// Name: public: static int CSplashWnd::PreTranslateAppMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSplashWnd::PreTranslateAppMessage(tagMSG *pMsg)
{
  unsigned int message; // eax

  if ( s_pSplashWnd == nullptr )
    return 0;
  message = pMsg->message;
  if ( message != 256
    && message != 260
    && message != 513
    && message != 516
    && message != 519
    && message != 161
    && message != 164
    && message != 167 )
  {
    return 0;
  }
  if ( s_pSplashWnd->m_bMinTimerExpired )
    ((void (*)(void))s_pSplashWnd->DestroyWindow)();
  else
    s_pSplashWnd->m_bHideRequested = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A5DA0
// Name: public: int CSplashWnd::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplashWnd::Create(CSplashWnd *this, CWnd *pParentWnd)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HBITMAP BitmapW; // eax
  int result; // eax
  HWND__ *m_hWnd; // ebx
  HCURSOR CursorA; // eax
  CSplashWnd_vtbl *v8; // edi
  const char *v9; // eax
  int bmWidth; // [esp-1Ch] [ebp-38h]
  int bmHeight; // [esp-18h] [ebp-34h]
  tagBITMAP bm; // [esp+4h] [ebp-18h] BYREF

  ModuleState = AfxGetModuleState();
  BitmapW = LoadBitmapW(hInstance: ModuleState->m_hCurrentResourceHandle, lpBitmapName: (LPCWSTR)0xAC);
  result = CGdiObject::Attach(this: &this->m_bitmap, hObject: BitmapW);
  if ( result != 0 )
  {
    GetObjectA(h: this->m_bitmap.m_hObject, c: 24, pv: &bm);
    if ( pParentWnd != nullptr )
      m_hWnd = pParentWnd->m_hWnd;
    else
      m_hWnd = nullptr;
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    v8 = this->__vftable;
    bmHeight = bm.bmHeight;
    bmWidth = bm.bmWidth;
    v9 = AfxRegisterWndClass(nClassStyle: 0, hCursor: CursorA, hbrBackground: nullptr, hIcon: nullptr);
    return v8->CreateEx_2(
             this,
             a2: 0,
             a3: v9,
             a4: nullptr,
             a5: -1879048192u,
             a6: 0,
             a7: 0,
             a8: bmWidth,
             a9: bmHeight,
             a10: m_hWnd,
             a11: nullptr,
             a12: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A5E40
// Name: protected: int CSplashWnd::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplashWnd::OnCreate(CSplashWnd *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    CWnd::CenterWindow(this, pAlternateOwner: nullptr);
    CWnd::SetWindowPos(this, pWndInsertAfter: &CWnd::wndTop, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0xBu);
    SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A5E90
// Name: protected: void CSplashWnd::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplashWnd::OnPaint(CSplashWnd *this)
{
  HDC CompatibleDC; // eax
  void *p_m_bitmap; // eax
  CGdiObject *v4; // esi
  CPaintDC dc; // [esp+4h] [ebp-88h] BYREF
  tagBITMAP bm; // [esp+58h] [ebp-34h] BYREF
  CDC dcImage; // [esp+70h] [ebp-1Ch] BYREF
  int v8; // [esp+88h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v8 = 0;
  CDC::CDC(this: &dcImage);
  LOBYTE(v8) = 1;
  CompatibleDC = CreateCompatibleDC(hdc: dc.m_hDC);
  if ( CDC::Attach(this: &dcImage, hDC: CompatibleDC) != 0 )
  {
    GetObjectA(h: this->m_bitmap.m_hObject, c: 24, pv: &bm);
    p_m_bitmap = &this->m_bitmap;
    if ( this != (CSplashWnd *)-116 )
      p_m_bitmap = this->m_bitmap.m_hObject;
    v4 = CDC::SelectGdiObject(hDC: dcImage.m_hDC, h: p_m_bitmap);
    BitBlt(
      hdc: dc.m_hDC,
      x: 0,
      y: 0,
      cx: bm.bmWidth,
      cy: bm.bmHeight,
      hdcSrc: dcImage.m_hDC,
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    if ( v4 != nullptr )
      v4 = (CGdiObject *)v4->m_hObject;
    CDC::SelectGdiObject(hDC: dcImage.m_hDC, h: v4);
  }
  LOBYTE(v8) = 0;
  CDC::~CDC(this: &dcImage);
  v8 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100A5F80
// Name: protected: virtual struct AFX_MSGMAP const __near * CSplashWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSplashWnd::GetMessageMap(CSplashWnd *this)
{
  return (const AFX_MSGMAP *)&off_105E65C8;
}

//------------------------------------------------------------------------------
// Address: 0x100A5F90
// Name: protected: CSplashWnd::CSplashWnd(void)
// Source: json
//------------------------------------------------------------------------------
CSplashWnd *__thiscall CSplashWnd::CSplashWnd(CSplashWnd *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CSplashWnd_vtbl *)&CSplashWnd::`vftable';
  this->m_bitmap.__vftable = (CBitmap_vtbl *)&CGdiObject::`vftable';
  this->m_bitmap.m_hObject = nullptr;
  this->m_bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  *(_WORD *)&this->m_bHideRequested = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A6000
// Name: public: static void CSplashWnd::ShowSplashScreen(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSplashWnd::ShowSplashScreen(CWnd *pParentWnd)
{
  CSplashWnd *v1; // eax
  CSplashWnd *v2; // eax

  if ( s_bShowSplashWnd && s_pSplashWnd == nullptr )
  {
    v1 = (CSplashWnd *)operator new(nSize: 0x80u);
    if ( v1 != nullptr )
      v2 = CSplashWnd::CSplashWnd(this: v1);
    else
      v2 = nullptr;
    s_pSplashWnd = v2;
    if ( CSplashWnd::Create(this: v2, pParentWnd) != 0 )
    {
      UpdateWindow(hWnd: s_pSplashWnd->m_hWnd);
    }
    else if ( s_pSplashWnd != nullptr )
    {
      ((void (__thiscall *)(CSplashWnd *, int))s_pSplashWnd->dtr_CObject)(a1: s_pSplashWnd, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103384DD
// Name: protected: virtual void CFrameWnd::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::PostNcDestroy(CView *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CView *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10356F07
// Name: public: virtual void CControlBar::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlBar::PostNcDestroy(CControlBar *this)
{
  if ( this->m_bAutoDelete != 0 )
    ((void (__thiscall *)(CControlBar *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1037C18B
// Name: protected: virtual void CMFCPopupMenu::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::PostNcDestroy(CMFCPopupMenu *this)
{
  if ( this->m_pParentBtn != nullptr )
    this->m_pParentBtn->OnCancelMode(this: this->m_pParentBtn);
  if ( this->m_pParentRibbonElement != nullptr )
    this->m_pParentRibbonElement->ClosePopupMenu(this: this->m_pParentRibbonElement);
  CFrameWnd::PostNcDestroy((CView *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103E5355
// Name: protected: virtual void CMFCDropDownFrame::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::PostNcDestroy(CMFCDropDownFrame *this)
{
  if ( this->m_pParentBtn != nullptr )
    this->m_pParentBtn->OnCancelMode(this: this->m_pParentBtn);
  CFrameWnd::PostNcDestroy((CView *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103F3DD7
// Name: public: virtual void CMFCToolBarsCustomizeDialog::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::PostNcDestroy(CMFCToolBarsCustomizeDialog *this)
{
  g_pWndCustomize = nullptr;
  CMFCToolBarsCustomizeDialog::SetFrameCustMode(this, bCustMode: 0);
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( this != nullptr )
    ((void (__thiscall *)(CMFCToolBarsCustomizeDialog *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10436C79
// Name: protected: virtual void CMFCColorPropertySheet::PostNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCColorPropertySheet::PostNcDestroy(CMFCColorPropertySheet *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( this->m_bModeless != 0 )
    ((void (__thiscall *)(CMFCColorPropertySheet *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1037C1C7
// Name: public: class CMFCPopupMenu __near * CMFCPopupMenu::GetParentPopupMenu(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__thiscall CMFCPopupMenu::GetParentPopupMenu(CMFCPopupMenu *this)
{
  CMFCToolBarMenuButton *m_pParentBtn; // eax
  const CWnd *v2; // eax
  CFrameWnd *v3; // eax
  CWnd *v5; // [esp-4h] [ebp-4h]

  m_pParentBtn = this->m_pParentBtn;
  if ( m_pParentBtn != nullptr )
  {
    v2 = (const CWnd *)AfxDynamicDownCast(
                         pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar,
                         pObject: m_pParentBtn->m_pWndParent);
  }
  else
  {
    if ( this->m_pParentRibbonElement == nullptr )
      return nullptr;
    v5 = this->m_pParentRibbonElement->GetParentWnd(this: this->m_pParentRibbonElement);
    v2 = (const CWnd *)AfxDynamicDownCast(pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar, pObject: v5);
  }
  if ( v2 != nullptr )
  {
    v3 = AFXGetParentFrame(pWnd: v2);
    return (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v3);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1037C218
// Name: public: class CMFCToolBar __near * CMFCPopupMenu::GetParentToolBar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarMenuButton *__thiscall CMFCPopupMenu::GetParentToolBar(CMFCPopupMenu *this)
{
  CMFCToolBarMenuButton *result; // eax

  result = this->m_pParentBtn;
  if ( result != nullptr )
    return (CMFCToolBarMenuButton *)AfxDynamicDownCast(
                                      pClass: &CMFCToolBar::classCMFCToolBar,
                                      pObject: result->m_pWndParent);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037C233
// Name: public: class CMFCToolBarMenuButton __near * CMFCPopupMenu::GetSelItem(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarMenuButton *__thiscall CMFCPopupMenu::GetSelItem(CMFCPopupMenu *this)
{
  CMFCPopupMenuBar *v1; // eax
  CMFCToolBarButton *HighlightedButton; // eax

  v1 = this->GetMenuBar(this);
  HighlightedButton = CMFCToolBar::GetHighlightedButton(this: v1);
  return (CMFCToolBarMenuButton *)AfxDynamicDownCast(
                                    pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton,
                                    pObject: HighlightedButton);
}

//------------------------------------------------------------------------------
// Address: 0x1037C250
// Name: public: int CMFCPopupMenu::InsertItem(class CMFCToolBarMenuButton const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::InsertItem(CMFCPopupMenu *this, const CMFCToolBarMenuButton *button, int iInsertAt)
{
  CMFCPopupMenuBar *v3; // eax

  v3 = this->GetMenuBar(this);
  return v3->InsertButton(this: v3, a2: button, a3: iInsertAt);
}

//------------------------------------------------------------------------------
// Address: 0x1037C268
// Name: public: int CMFCPopupMenu::InsertSeparator(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::InsertSeparator(CMFCPopupMenu *this, int iInsertAt)
{
  CMFCPopupMenuBar *v2; // eax

  v2 = this->GetMenuBar(this);
  return v2->InsertSeparator(this: v2, a2: iInsertAt);
}

//------------------------------------------------------------------------------
// Address: 0x1037C280
// Name: public: int CMFCPopupMenu::GetMenuItemCount(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::GetMenuItemCount(CMFCPopupMenu *this)
{
  return this->GetMenuBar(this)->m_Buttons.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1037C28F
// Name: public: class CMFCToolBarMenuButton __near * CMFCPopupMenu::GetMenuItem(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarMenuButton *__thiscall CMFCPopupMenu::GetMenuItem(CMFCPopupMenu *this, int iIndex)
{
  CMFCPopupMenuBar *v2; // eax

  v2 = this->GetMenuBar(this);
  return (CMFCToolBarMenuButton *)CMFCToolBar::GetButton(this: v2, nIndex: iIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1037C2A4
// Name: public: int CMFCPopupMenu::RemoveItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::RemoveItem(CMFCPopupMenu *this, int iIndex)
{
  CMFCPopupMenuBar *v2; // eax

  v2 = this->GetMenuBar(this);
  return v2->RemoveButton(this: v2, a2: iIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1037C2BC
// Name: public: void CMFCPopupMenu::RemoveAllItems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::RemoveAllItems(CMFCPopupMenu *this)
{
  CMFCPopupMenuBar *v1; // eax

  v1 = this->GetMenuBar(this);
  v1->RemoveAllButtons(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1037C2CE
// Name: protected: virtual int CMFCPopupMenu::IsScrollUpAvailable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCPopupMenu::IsScrollUpAvailable(CMFCPopupMenu *this)
{
  return this->GetMenuBar(this)->m_iOffset > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037C2E4
// Name: protected: virtual int CMFCPopupMenu::IsScrollDnAvailable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::IsScrollDnAvailable(CMFCPopupMenu *this)
{
  CMFCPopupMenuBar *v2; // esi
  int result; // eax
  CMFCPopupMenuBar_vtbl *v4; // ebx
  int Count; // eax
  int v6; // eax
  CRect rectLastItem; // [esp+8h] [ebp-14h] BYREF

  v2 = this->GetMenuBar(this);
  result = CMFCToolBar::GetCount(this: v2);
  if ( result != 0 )
  {
    memset(&rectLastItem, 0, sizeof(rectLastItem));
    v4 = v2->__vftable;
    Count = CMFCToolBar::GetCount(this: v2);
    v4->GetItemRect(this: v2, a2: Count - 1, a3: &rectLastItem);
    v6 = v2->GetRowHeight(this: v2);
    return rectLastItem.bottom > this->m_nMenuBarHeight + v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037C35E
// Name: protected: void CMFCPopupMenu::CollapseSubmenus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::CollapseSubmenus(CMFCPopupMenu *this)
{
  CMFCPopupMenuBar *v1; // eax
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // ecx

  v1 = this->GetMenuBar(this);
  if ( v1 == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  m_pNodeHead = v1->m_Buttons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      goto LABEL_2;
    data->__vftable[7].dtr_CObject(this: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037C392
// Name: public: int CMFCPopupMenu::HideRarelyUsedCommands(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCPopupMenu::HideRarelyUsedCommands(CMFCPopupMenu *this)
{
  return this->m_pParentBtn != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1037C39E
// Name: public: virtual int CMFCPopupMenu::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::OnCmdMsg(
        CMFCPopupMenu *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  if ( CFrameWnd::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) )
    return 1;
  if ( this->m_pMessageWnd != nullptr )
    return this->m_pMessageWnd->OnCmdMsg(this: this->m_pMessageWnd, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037C3DC
// Name: protected: int CMFCPopupMenu::NotifyParentDlg(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::NotifyParentDlg(CMFCPopupMenu *this, int bActivate)
{
  CDialogEx *v3; // ebx
  CObject *v4; // eax
  CMFCPropertyPage *pPropPage; // [esp+Ch] [ebp-4h]

  v3 = (CDialogEx *)AfxDynamicDownCast(pClass: &CDialogEx::classCDialogEx, pObject: this->m_pMessageWnd);
  v4 = AfxDynamicDownCast(pClass: &CMFCPropertyPage::classCMFCPropertyPage, pObject: this->m_pMessageWnd);
  pPropPage = (CMFCPropertyPage *)v4;
  if ( v3 == nullptr && v4 == nullptr || bActivate == 0 && CMFCPopupMenu::m_pActivePopupMenu != (HWND)this )
    return 0;
  if ( v3 != nullptr )
    CDialogEx::SetActiveMenu(this: v3, pMenu: bActivate != 0 ? this : nullptr);
  if ( pPropPage != nullptr )
    CMFCPropertyPage::SetActiveMenu(this: pPropPage, pMenu: bActivate != 0 ? this : nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037C45B
// Name: public: void CMFCPopupMenu::SetQuickMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::SetQuickMode(CMFCPopupMenu *this)
{
  CMFCCustomizeMenuButton::m_bRecentlyUsedOld = CMFCMenuBar::m_bRecentlyUsedMenus;
  CMFCMenuBar::SetRecentlyUsedMenus(bOn: 0);
  this->m_bQuickCusomize = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037C47B
// Name: public: void CMFCPopupMenu::SetParentRibbonElement(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::SetParentRibbonElement(CMFCPopupMenu *this, CMFCRibbonBaseElement *pElem)
{
  this->m_pParentRibbonElement = pElem;
  pElem->m_pPopupMenu = this;
}

//------------------------------------------------------------------------------
// Address: 0x1037C490
// Name: public: virtual class CWnd __near * CMFCPopupMenu::GetParentArea(class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CMFCPopupMenu::GetParentArea(CMFCPopupMenu *this, CRect *rectParentBtn)
{
  CMFCToolBarMenuButton *m_pParentBtn; // edx
  CWnd *result; // eax
  int *p_left; // esi
  int *v5; // esi
  CMFCRibbonBaseElement **p_m_pParentRibbonElement; // esi
  CRect *p_m_rect; // esi
  _DWORD v8[4]; // [esp+8h] [ebp-10h] BYREF

  m_pParentBtn = this->m_pParentBtn;
  if ( m_pParentBtn != nullptr )
  {
    result = m_pParentBtn->m_pWndParent;
    if ( result != nullptr )
    {
      p_left = &m_pParentBtn->m_rect.left;
LABEL_4:
      rectParentBtn->left = *p_left;
      v5 = p_left + 1;
      rectParentBtn->top = *v5++;
      rectParentBtn->right = *v5;
      rectParentBtn->bottom = v5[1];
      return result;
    }
  }
  else
  {
    p_m_pParentRibbonElement = &this->m_pParentRibbonElement;
    if ( this->m_pParentRibbonElement != nullptr )
    {
      result = (*p_m_pParentRibbonElement)->GetParentWnd(this: *p_m_pParentRibbonElement);
      if ( result != nullptr )
      {
        p_m_rect = &(*p_m_pParentRibbonElement)->m_rect;
        v8[0] = p_m_rect->left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        v8[1] = p_m_rect->left;
        p_m_rect = (CRect *)((char *)p_m_rect + 4);
        v8[2] = p_m_rect->left;
        v8[3] = p_m_rect->top;
        p_left = v8;
        goto LABEL_4;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1037C4E9
// Name: protected: virtual int CMFCPopupMenu::GetBorderSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::GetBorderSize(CMFCPopupMenu *this)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  return Instance->GetPopupMenuBorderSize(this: Instance);
}

//------------------------------------------------------------------------------
// Address: 0x1037C4F8
// Name: protected: long CMFCPopupMenu::OnNcHitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::OnNcHitTest(CMFCPopupMenu *this, CPoint point)
{
  CRect *p_m_rectResize; // esi
  unsigned int bRTL; // [esp+8h] [ebp-18h]
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  p_m_rectResize = &this->m_rectResize;
  bRTL = CWnd::GetExStyle(this) & 0x400000;
  if ( IsRectEmpty(lprc: p_m_rectResize) )
    return CMiniFrameWnd::OnNcHitTest(this, point);
  rect.left = p_m_rectResize->left;
  rect.top = this->m_rectResize.top;
  rect.right = this->m_rectResize.right;
  rect.bottom = this->m_rectResize.bottom;
  if ( this->m_sizeMinResize.cx <= 0 )
  {
    CWnd::ClientToScreen(this, lpRect: &rect);
    if ( PtInRect(lprc: &rect, pt: point.tagPOINT) )
      return this->m_bIsResizeBarOnTop != 0 ? 12 : 15;
    return CMiniFrameWnd::OnNcHitTest(this, point);
  }
  rect.left = rect.right + rect.top - rect.bottom;
  CWnd::ClientToScreen(this, lpRect: &rect);
  if ( !PtInRect(lprc: &rect, pt: point.tagPOINT) )
    return CMiniFrameWnd::OnNcHitTest(this, point);
  if ( this->m_bIsResizeBarOnTop != 0 )
    return 14 - (bRTL != 0);
  else
    return 17 - (bRTL != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1037C5D6
// Name: public: void CMFCPopupMenu::EnableResize(class CSize)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::EnableResize(CMFCPopupMenu *this, CSize sizeMinResize)
{
  int cy; // edx

  cy = sizeMinResize.cy;
  this->m_bIsResizable = sizeMinResize != 0;
  if ( sizeMinResize != 0 )
    cy = (sizeMinResize.cx <= 0 ? 9 : 12) + sizeMinResize.cy;
  this->m_sizeMinResize.cx = sizeMinResize.cx;
  this->m_sizeMinResize.cy = cy;
}

//------------------------------------------------------------------------------
// Address: 0x1037C61C
// Name: public: void CMFCPopupMenu::EnableVertResize(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::EnableVertResize(CMFCPopupMenu *this, int nMinResize)
{
  this->m_sizeMinResize.cy = nMinResize;
  this->m_bIsResizable = nMinResize > 0;
  this->m_sizeMinResize.cx = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037C643
// Name: private: void CMFCShadowWnd::Repos(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShadowWnd::Repos(CMFCShadowWnd *this)
{
  CMFCPopupMenu *m_pOwner; // eax
  int m_nOffset; // ecx
  CRect rectWindow; // [esp+8h] [ebp-14h] BYREF

  m_pOwner = this->m_pOwner;
  memset(&rectWindow, 0, sizeof(rectWindow));
  GetWindowRect(hWnd: m_pOwner->m_hWnd, lpRect: &rectWindow);
  m_nOffset = this->m_nOffset;
  if ( this->m_bIsRTL != 0 )
    m_nOffset = -m_nOffset;
  OffsetRect(lprc: &rectWindow, dx: m_nOffset, dy: this->m_nOffset);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  if ( IsWindowVisible(hWnd: this->m_hWnd) )
  {
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: nullptr,
      x: rectWindow.left,
      y: rectWindow.top,
      cx: rectWindow.right - rectWindow.left,
      cy: rectWindow.bottom - rectWindow.top,
      nFlags: 0x14u);
  }
  else
  {
    CWnd::ShowWindow(this, nCmdShow: 4);
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: &CWnd::wndTop,
      x: rectWindow.left,
      y: rectWindow.top,
      cx: rectWindow.right - rectWindow.left,
      cy: rectWindow.bottom - rectWindow.top,
      nFlags: 0x10u);
    CWnd::SetWindowPos(
      this: this->m_pOwner,
      pWndInsertAfter: &CWnd::wndTop,
      x: -1,
      y: -1,
      cx: -1,
      cy: -1,
      nFlags: 0x53u);
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1037C73F
// Name: protected: int CMFCPopupMenu::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::OnCreate(CMFCPopupMenu *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  int v4; // ebx
  CMFCPopupMenuBar *v5; // edi
  CMFCToolBarMenuButton *m_pParentBtn; // ecx
  CMFCPopupMenu *ParentPopupMenu; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  HWND__ *m_hWnd; // eax
  CMFCShadowWnd *v11; // eax
  CMFCShadowWnd *v12; // eax

  result = CFrameWnd::OnCreate(this, lpcs: lpCreateStruct);
  if ( result != -1 )
  {
    v4 = 1346381832;
    if ( CMFCPopupMenu::GetAnimationType(bNoSystem: 0) != NO_ANIMATION
      && CMFCToolBar::m_bCustomizeMode == 0
      && this->m_bDisableAnimation == 0 )
    {
      v4 = 1077946376;
    }
    v5 = this->GetMenuBar(this);
    v5->m_bTrackMode = this->m_bTrackMode;
    m_pParentBtn = this->m_pParentBtn;
    if ( m_pParentBtn != nullptr && m_pParentBtn->m_bMenuPaletteMode != 0 )
    {
      v5->m_bPaletteMode = 1;
      v5->m_bDisableSideBarInXPMode = 1;
      v5->m_bPaletteRows = this->m_pParentBtn->m_nPaletteRows;
    }
    result = v5->Create(this: v5, a2: this, a3: v4 | 0x30, a4: 1u);
    if ( result != 0 )
    {
      ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
      if ( ParentPopupMenu != nullptr )
        this->m_iMaxWidth = ParentPopupMenu->m_iMaxWidth;
      v5->m_iMaxWidth = this->m_iMaxWidth;
      v5->m_iMinWidth = CMFCPopupMenu::m_nMinWidth;
      Parent = GetParent(hWnd: this->m_hWnd);
      v9 = CWnd::FromHandle(hWnd: Parent);
      if ( v9 != nullptr )
        m_hWnd = v9->m_hWnd;
      else
        m_hWnd = nullptr;
      v5->m_hWndOwner = m_hWnd;
      if ( this->m_iShadowSize > 0 && this->m_pParentRibbonElement != nullptr )
      {
        v11 = (CMFCShadowWnd *)operator new(nSize: 0x294u);
        if ( v11 != nullptr )
          v12 = CMFCShadowWnd::CMFCShadowWnd(this: v11, pOwner: this, nOffset: this->m_iShadowSize);
        else
          v12 = nullptr;
        this->m_pWndShadow = v12;
        this->m_iShadowSize = 0;
        v12->Create(this: v12);
      }
      return (this->InitMenuBar(this) != 0) - 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037C8A2
// Name: public: virtual void CMFCPopupMenu::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::RecalcLayout(CMFCPopupMenu *this, int __formal)
{
  CMFCPopupMenuBar *v3; // edi
  CMFCToolBarMenuButton *m_pParentBtn; // ecx
  HMONITOR v5; // eax
  int v6; // edi
  unsigned int v7; // eax
  int m_bResizeTracking; // ecx
  int right; // esi
  int v10; // eax
  int v11; // ecx
  int cx; // eax
  int cy; // edx
  int v14; // ecx
  int x; // eax
  int v16; // ecx
  bool v17; // zf
  int y; // eax
  int bottom; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // esi
  int *v23; // eax
  CMFCPopupMenu::LOGO_LOCATION m_nLogoLocation; // eax
  int v25; // ecx
  int v26; // esi
  int v27; // eax
  int m_nMaxHeight; // ecx
  int v29; // esi
  int v30; // edi
  int v31; // eax
  bool v32; // sf
  int v33; // edx
  CMFCToolBarMenuButton *v34; // eax
  CMFCMenuBar *v35; // esi
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int left; // ecx
  int v41; // eax
  int v42; // ecx
  CRect *p_m_rect; // eax
  int v44; // ecx
  int v45; // edx
  CMFCVisualManager *Instance; // eax
  CMFCPopupMenu *ParentPopupMenu; // esi
  CMFCToolBarMenuButton *v48; // eax
  CWnd *v49; // ecx
  int v50; // eax
  int v51; // esi
  CMFCPopupMenu *v52; // eax
  int v53; // eax
  CMFCRibbonBaseElement *m_pParentRibbonElement; // ecx
  CRect *v55; // esi
  int v56; // eax
  CRect *v57; // esi
  int v58; // ecx
  int v59; // eax
  int v60; // ecx
  int v61; // eax
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  int v63; // eax
  int v64; // esi
  CMFCPopupMenu_vtbl *v65; // eax
  CMFCPopupMenu::DROP_DIRECTION m_DropDirection; // eax
  int v67; // ecx
  int v68; // edx
  CMFCPopupMenu::DROP_DIRECTION v69; // eax
  CMFCToolBarMenuButton *v70; // eax
  CMFCToolBarMenuButton *v71; // eax
  CMFCToolBarMenuButton *v72; // eax
  CMFCPopupMenu::DROP_DIRECTION v73; // eax
  int v74; // eax
  int m_iShadowSize; // eax
  CMFCToolBarMenuButton *v76; // eax
  int m_bShown; // ecx
  CWnd *m_pWndParent; // esi
  int v79; // ecx
  int v80; // edx
  int v81; // eax
  int v82; // ecx
  POINT v83; // [esp-10h] [ebp-C8h]
  HWND m_hWnd; // [esp-8h] [ebp-C0h]
  HWND__ *v85; // [esp-8h] [ebp-C0h]
  HWND__ *v86; // [esp-8h] [ebp-C0h]
  HWND__ *v87; // [esp-8h] [ebp-C0h]
  CMFCPopupMenuBar *pMenuBar; // [esp+Ch] [ebp-ACh]
  int nResizeBarHeight; // [esp+10h] [ebp-A8h]
  int nResizeBarHeighta; // [esp+10h] [ebp-A8h]
  tagPOINT Point; // [esp+14h] [ebp-A4h] BYREF
  CWnd *pWndParent; // [esp+1Ch] [ebp-9Ch]
  int nBorderSize; // [esp+20h] [ebp-98h]
  CMFCMenuBar *pParentMenuBar; // [esp+24h] [ebp-94h]
  int bRTL; // [esp+28h] [ebp-90h]
  tagMONITORINFO mi; // [esp+2Ch] [ebp-8Ch] BYREF
  CRect rectShadowRight; // [esp+54h] [ebp-64h] BYREF
  CRect rectQCParent; // [esp+64h] [ebp-54h] BYREF
  CRect rectMenu; // [esp+74h] [ebp-44h] BYREF
  CRect rectInter; // [esp+84h] [ebp-34h] BYREF
  CRect rectScreen; // [esp+94h] [ebp-24h] BYREF
  tagRECT Rect; // [esp+A4h] [ebp-14h] BYREF

  v3 = this->GetMenuBar(this);
  pMenuBar = v3;
  if ( !IsWindow(hWnd: this->m_hWnd) || v3 == nullptr || !IsWindow(hWnd: v3->m_hWnd) || v3->m_bInUpdateShadow != 0 )
    return;
  m_pParentBtn = this->m_pParentBtn;
  if ( m_pParentBtn == nullptr
    || m_pParentBtn->IsTearOffMenu(this: m_pParentBtn) == 0
    || (pParentMenuBar = (CMFCMenuBar *)1, CMFCToolBar::m_bCustomizeMode != 0) )
  {
    pParentMenuBar = nullptr;
  }
  v83.y = this->m_ptLocation.y;
  memset(&rectScreen, 0, sizeof(rectScreen));
  v83.x = this->m_ptLocation.x;
  mi.cbSize = 40;
  v5 = MonitorFromPoint(pt: v83, dwFlags: 2u);
  if ( GetMonitorInfoA(hMonitor: v5, lpmi: &mi) )
    CopyRect(lprcDst: &rectScreen, lprcSrc: &mi.rcWork);
  else
    SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rectScreen, fWinIni: 0);
  v6 = this->GetBorderSize(this);
  nBorderSize = v6;
  v7 = CWnd::GetExStyle(this);
  m_bResizeTracking = this->m_bResizeTracking;
  right = rectScreen.right;
  v10 = v7 & 0x400000;
  bRTL = v10;
  if ( m_bResizeTracking != 0 )
  {
    v11 = 2 * v6;
    if ( v10 != 0 )
      cx = this->m_ptLocation.x - v11 - rectScreen.left;
    else
      cx = rectScreen.right - v11 - this->m_ptLocation.x;
    if ( this->m_sizeCurrent.cx < cx )
      cx = this->m_sizeCurrent.cx;
    cy = this->m_sizeCurrent.cy;
    this->m_sizeCurrent.cx = cx;
    v14 = this->m_rectResize.top - this->m_ptLocation.y - this->m_rectResize.bottom - 2 * v6 + rectScreen.bottom;
    if ( cy < v14 )
      v14 = cy;
    this->m_sizeCurrent.cy = v14;
  }
  x = this->m_ptLocation.x;
  v16 = x;
  if ( x >= right )
    v16 = right;
  if ( rectScreen.left <= v16 )
  {
    if ( x >= right )
      x = right;
  }
  else
  {
    x = rectScreen.left;
  }
  v17 = this->m_pParentBtn == nullptr;
  this->m_ptLocation.x = x;
  if ( v17 )
  {
    y = this->m_ptLocation.y;
    bottom = y;
    if ( y >= rectScreen.bottom )
      bottom = rectScreen.bottom;
    if ( rectScreen.top <= bottom )
    {
      if ( y >= rectScreen.bottom )
        y = rectScreen.bottom;
    }
    else
    {
      y = rectScreen.top;
    }
    this->m_ptLocation.y = y;
  }
  v20 = this->m_bResizeTracking;
  v21 = this->m_sizeCurrent.cx;
  v22 = this->m_sizeCurrent.cy;
  Rect.right = v21;
  Rect.bottom = v22;
  if ( v20 == 0 && this->m_bWasResized == 0 )
  {
    v23 = (int *)pMenuBar->CalcSize(this: pMenuBar, result: (CSize *)&rectMenu.right, a3: 1);
    v21 = *v23;
    v22 = v23[1];
    Rect.right = *v23;
    Rect.bottom = v22;
  }
  if ( this->m_bResizeTracking == 0 && this->m_bWasResized == 0 )
  {
    v22 += 2 * v6;
    m_nLogoLocation = this->m_nLogoLocation;
    v25 = v21 + 2 * v6;
    Rect.right = v25;
    Rect.bottom = v22;
    if ( m_nLogoLocation >= MENU_LOGO_LEFT )
    {
      if ( m_nLogoLocation <= MENU_LOGO_RIGHT )
      {
        Rect.right = this->m_iLogoWidth + v25;
      }
      else if ( m_nLogoLocation <= MENU_LOGO_BOTTOM )
      {
        v22 += this->m_iLogoWidth;
        Rect.bottom = v22;
      }
    }
  }
  if ( this->m_pMenuCustomizationPage != nullptr )
  {
    v26 = GetSystemMetrics(nIndex: 51) + v22;
    Rect.bottom = v26 + 2 * GetSystemMetrics(nIndex: 6) + 5;
LABEL_54:
    v27 = nBorderSize;
    goto LABEL_55;
  }
  if ( pParentMenuBar == nullptr )
    goto LABEL_54;
  v27 = nBorderSize;
  Rect.bottom += 10;
  rectInter.right = nBorderSize + Rect.right - 2 * nBorderSize;
  rectInter.left = nBorderSize;
  rectInter.top = nBorderSize;
  rectInter.bottom = nBorderSize + 10;
  this->m_rectTearOffCaption.left = nBorderSize;
  this->m_rectTearOffCaption.top = rectInter.top;
  this->m_rectTearOffCaption.right = rectInter.right;
  this->m_rectTearOffCaption.bottom = rectInter.bottom;
  if ( CMFCToolBar::m_bCustomizeMode == 0 && (this == (CMFCPopupMenu *)-4080 || this->m_wndToolTip.m_hWnd == nullptr) )
  {
    this->m_wndToolTip.Create_2(this: &this->m_wndToolTip, a2: this, a3: 0);
    SendMessageA(hWnd: this->m_wndToolTip.m_hWnd, Msg: 0x401u, wParam: 1u, lParam: 0);
    if ( afxGlobalData.m_nMaxToolTipWidth != -1 )
      SendMessageA(hWnd: this->m_wndToolTip.m_hWnd, Msg: 0x418u, wParam: 0, lParam: afxGlobalData.m_nMaxToolTipWidth);
    CToolTipCtrl::AddTool(
      this: &this->m_wndToolTip,
      pWnd: this,
      nIDText: 0x3E9Cu,
      lpRectTool: &this->m_rectTearOffCaption,
      nIDTool: 1u);
    goto LABEL_54;
  }
LABEL_55:
  m_nMaxHeight = this->m_nMaxHeight;
  if ( m_nMaxHeight != -1 && Rect.bottom > m_nMaxHeight )
  {
    if ( this->m_bResizeTracking == 0 && this->m_bWasResized == 0 )
    {
      v29 = 2 * nBorderSize;
      v30 = m_nMaxHeight - 2 * nBorderSize;
      v31 = pMenuBar->GetRowHeight(this: pMenuBar);
      this->m_bHasBeenResized = 1;
      Rect.bottom = v29 - v30 % v31 + v30 + 2;
      v27 = nBorderSize;
    }
    this->m_bScrollable = 1;
  }
  if ( this->m_bIsResizable != 0 )
  {
    v17 = this->m_sizeMinResize.cx == 0;
    v32 = this->m_sizeMinResize.cx < 0;
    rectInter.left = v27;
    v33 = v32 || v17 ? 9 : 12;
    if ( this->m_bIsResizeBarOnTop != 0 )
    {
      rectInter.top = v27;
      rectInter.right = v27 + Rect.right - 2 * v27;
      rectInter.bottom = v33 + v27;
    }
    else
    {
      rectInter.top = Rect.bottom - v27;
      rectInter.right = v27 + Rect.right - 2 * v27;
      rectInter.bottom = v33 + Rect.bottom - v27;
    }
    Rect.bottom += v33;
    this->m_rectResize = rectInter;
  }
  if ( bRTL != 0 || (pWndParent = nullptr, this->m_bRightAlign != 0) )
    pWndParent = (CWnd *)1;
  v34 = this->m_pParentBtn;
  if ( v34 != nullptr )
  {
    v35 = (CMFCMenuBar *)AfxDynamicDownCast(pClass: &CMFCMenuBar::classCMFCMenuBar, pObject: v34->m_pWndParent);
    pParentMenuBar = v35;
    if ( v35 != nullptr && v35->IsFloating(this: v35) != 0 )
    {
      v36 = CMFCMenuBar::GetFloatPopupDirection(this: v35, pMenuButton: this->m_pParentBtn) - 2;
      if ( v36 == 0 )
      {
        v45 = this->m_pParentBtn->m_rect.top + this->m_ptLocationInitial.y - this->m_pParentBtn->m_rect.bottom;
        this->m_DropDirection = DROP_DIRECTION_TOP;
        this->m_ptLocation.y = v45 - Rect.bottom + 1;
        goto LABEL_86;
      }
      v37 = v36 - 1;
      if ( v37 != 0 )
      {
        if ( v37 == 1 )
        {
          this->m_ptLocation.y = this->m_ptLocationInitial.y
                               - this->m_pParentBtn->m_rect.bottom
                               + this->m_pParentBtn->m_rect.top
                               + 1;
          v38 = this->m_ptLocationInitial.x;
          this->m_DropDirection = DROP_DIRECTION_LEFT;
          if ( bRTL != 0 )
          {
            v39 = Rect.right + v38;
            left = rectScreen.right;
            this->m_ptLocation.x = v39;
            if ( v39 <= left )
              goto LABEL_86;
          }
          else
          {
            v41 = v38 - Rect.right;
            left = rectScreen.left;
            this->m_ptLocation.x = v41;
            if ( v41 >= left )
              goto LABEL_86;
          }
          this->m_ptLocation.x = left;
          this->m_DropDirection = DROP_DIRECTION_NONE;
        }
      }
      else
      {
        v42 = this->m_ptLocationInitial.x;
        p_m_rect = &this->m_pParentBtn->m_rect;
        if ( bRTL != 0 )
          v44 = p_m_rect->left + v42 - this->m_pParentBtn->m_rect.right;
        else
          v44 = this->m_pParentBtn->m_rect.right + v42 - p_m_rect->left;
        this->m_ptLocation.x = v44;
        this->m_ptLocation.y = this->m_ptLocationInitial.y - p_m_rect->bottom + p_m_rect->top + 1;
        this->m_DropDirection = DROP_DIRECTION_RIGHT;
      }
    }
  }
  else
  {
    pParentMenuBar = nullptr;
  }
LABEL_86:
  memset(&rectQCParent, 0, sizeof(rectQCParent));
  SetRectEmpty(lprc: &rectQCParent);
  Point.y = 0;
  Instance = CMFCVisualManager::GetInstance();
  if ( Instance->IsOfficeXPStyleMenus(this: Instance) != 0 )
  {
    ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
    if ( ParentPopupMenu != nullptr )
    {
      v48 = this->m_pParentBtn;
      nResizeBarHeight = (int)v48;
      if ( v48 != nullptr && v48->m_bQuickCustomMode != 0 )
      {
        if ( bRTL == 0 )
          RedrawWindow(hWnd: ParentPopupMenu->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
        if ( ParentPopupMenu->m_bQuickCusomize != 0 && this->m_bQuickCusomize == 0 )
        {
          rectQCParent = *(CRect *)(nResizeBarHeight + 84);
          v49 = *(CWnd **)(nResizeBarHeight + 108);
          if ( v49 != nullptr && v49->m_hWnd != nullptr )
          {
            CWnd::ClientToScreen(this: v49, lpRect: &rectQCParent);
            v17 = this->m_DropDirection == DROP_DIRECTION_LEFT;
            this->m_ptLocation.y = rectQCParent.top;
            Point.y = 1;
            if ( v17 )
            {
              v50 = rectQCParent.left;
              if ( bRTL == 0 )
                v50 = rectQCParent.left - Rect.right;
            }
            else
            {
              v50 = rectQCParent.right;
              if ( bRTL != 0 )
                v50 = Rect.right + rectQCParent.right;
            }
            this->m_ptLocation.x = v50;
          }
        }
      }
    }
  }
  if ( bRTL == 0 || (v51 = Rect.right, this->m_ptLocation.x - Rect.right >= rectScreen.left) )
  {
    if ( pWndParent != nullptr || Rect.right + this->m_ptLocation.x <= rectScreen.right )
      goto LABEL_144;
    v51 = Rect.right;
  }
  v52 = CMFCPopupMenu::GetParentPopupMenu(this);
  pWndParent = v52;
  if ( v52 != nullptr )
  {
    m_hWnd = v52->m_hWnd;
    memset(&rectMenu, 0, sizeof(rectMenu));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectMenu);
    if ( bRTL != 0 )
      v53 = v51 + rectMenu.right;
    else
      v53 = rectMenu.left - v51;
    m_pParentRibbonElement = this->m_pParentRibbonElement;
    this->m_ptLocation.x = v53;
    if ( m_pParentRibbonElement != nullptr && CMFCRibbonBaseElement::IsMenuMode(this: m_pParentRibbonElement) == 0 )
    {
      v55 = &this->m_pParentRibbonElement->m_rect;
      rectMenu.left = v55->left;
      v55 = (CRect *)((char *)v55 + 4);
      rectMenu.top = v55->left;
      v55 = (CRect *)((char *)v55 + 4);
      rectMenu.right = v55->left;
      rectMenu.bottom = v55->top;
      CWnd::ClientToScreen(this: pWndParent, lpRect: &rectMenu);
      if ( bRTL != 0 )
        v56 = Rect.right + rectMenu.left;
      else
        v56 = rectMenu.right - Rect.right;
      this->m_ptLocation.x = v56;
    }
    this->m_DropDirection = 4 - (bRTL != 0);
LABEL_126:
    v60 = rectScreen.left;
    goto LABEL_133;
  }
  if ( pParentMenuBar != nullptr && pParentMenuBar->IsHorizontal(this: pParentMenuBar) == 0 )
  {
    v57 = &this->m_pParentBtn->m_rect;
    rectInter.left = v57->left;
    v57 = (CRect *)((char *)v57 + 4);
    rectInter.top = v57->left;
    v57 = (CRect *)((char *)v57 + 4);
    rectInter.right = v57->left;
    rectInter.bottom = v57->top;
    CWnd::ClientToScreen(this: pParentMenuBar, lpRect: &rectInter);
    v58 = Rect.right;
    if ( bRTL != 0 )
      v59 = Rect.right + rectInter.right;
    else
      v59 = rectInter.left - Rect.right;
    this->m_ptLocation.x = v59;
    if ( v58 + v59 >= rectScreen.right )
      this->m_ptLocation.x = rectScreen.right - v58 - 1;
    this->m_DropDirection = DROP_DIRECTION_LEFT;
    goto LABEL_126;
  }
  v60 = rectScreen.left;
  if ( bRTL != 0 )
  {
    v61 = v51 + rectScreen.left + 1;
  }
  else if ( this->m_bRightAlign != 0 )
  {
    v61 = rectScreen.left + 1;
  }
  else
  {
    v61 = rectScreen.right - v51 - 1;
  }
  this->m_ptLocation.x = v61;
  this->m_DropDirection = DROP_DIRECTION_NONE;
LABEL_133:
  if ( bRTL != 0 )
  {
    if ( this->m_ptLocation.x <= rectScreen.right )
      goto LABEL_139;
    this->m_ptLocation.x = rectScreen.right;
  }
  else
  {
    if ( this->m_ptLocation.x >= v60 )
      goto LABEL_139;
    this->m_ptLocation.x = v60;
  }
  this->m_DropDirection = DROP_DIRECTION_NONE;
LABEL_139:
  if ( this->m_bDisableAnimation == 0 )
  {
    AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
    if ( AnimationType == UNFOLD )
    {
LABEL_143:
      this->m_bIsAnimRight = 0;
      goto LABEL_144;
    }
    if ( AnimationType == FADE )
    {
      this->m_bIsAnimDown = 0;
      goto LABEL_143;
    }
  }
LABEL_144:
  v63 = this->m_ptLocation.y;
  v64 = Rect.bottom;
  if ( v63 + Rect.bottom > rectScreen.bottom )
  {
    nResizeBarHeighta = this->m_rectResize.bottom - this->m_rectResize.top;
    if ( this->m_bIsResizable != 0 )
    {
      rectInter.right = nBorderSize + Rect.right - 2 * nBorderSize;
      rectInter.left = nBorderSize;
      rectInter.top = nBorderSize;
      rectInter.bottom = nBorderSize + nResizeBarHeighta;
      this->m_rectResize.left = nBorderSize;
      this->m_rectResize.top = rectInter.top;
      this->m_rectResize.right = rectInter.right;
      this->m_rectResize.bottom = rectInter.bottom;
      v64 = Rect.bottom;
      this->m_bIsResizeBarOnTop = 1;
    }
    v65 = this->__vftable;
    this->m_bIsAnimDown = 0;
    memset(&rectShadowRight, 0, sizeof(rectShadowRight));
    pWndParent = v65->GetParentArea(this, a2: &rectShadowRight);
    if ( pWndParent == nullptr
      || (m_DropDirection = this->m_DropDirection) == DROP_DIRECTION_LEFT
      || m_DropDirection == DROP_DIRECTION_RIGHT )
    {
      if ( Point.y != 0 )
      {
        this->m_ptLocation.y = rectQCParent.bottom - v64 - 1;
      }
      else
      {
        this->m_ptLocation.y -= v64;
        if ( CMFCPopupMenu::GetParentPopupMenu(this) != nullptr )
          this->m_ptLocation.y += pMenuBar->GetRowHeight(this: pMenuBar) + 2 * nBorderSize;
      }
    }
    else
    {
      rectMenu.right = rectShadowRight.right;
      v85 = pWndParent->m_hWnd;
      rectMenu.bottom = 0;
      ClientToScreen(hWnd: v85, lpPoint: (LPPOINT)&rectMenu.right);
      Point.y = rectShadowRight.top - v64;
      v86 = pWndParent->m_hWnd;
      Point.x = 0;
      ClientToScreen(hWnd: v86, lpPoint: &Point);
      if ( Point.y >= 0 )
      {
        this->m_ptLocation.y = Point.y;
        if ( pParentMenuBar != nullptr && pParentMenuBar->IsHorizontal(this: pParentMenuBar) != 0 )
          v69 = DROP_DIRECTION_TOP;
        else
          v69 = DROP_DIRECTION_NONE;
        this->m_DropDirection = v69;
      }
      else
      {
        v64 += Point.y;
        if ( rectScreen.bottom - v64 >= v64 - rectScreen.top )
        {
          v64 = rectScreen.bottom - this->m_ptLocation.y;
          this->m_bIsAnimDown = 1;
          Rect.bottom = v64;
          if ( this->m_bIsResizable != 0 )
          {
            v67 = nBorderSize;
            v68 = Rect.right;
            this->m_bIsResizeBarOnTop = 0;
            rectInter.top = v64 - nResizeBarHeighta - v67;
            rectInter.left = v67;
            rectInter.right = v67 + v68 - 2 * v67;
            rectInter.bottom = v64 - v67;
            this->m_rectResize.left = v67;
            this->m_rectResize.top = rectInter.top;
            this->m_rectResize.right = rectInter.right;
            this->m_rectResize.bottom = rectInter.bottom;
            v64 = Rect.bottom;
          }
        }
        else
        {
          this->m_ptLocation.y = rectScreen.top;
          this->m_DropDirection = DROP_DIRECTION_NONE;
        }
        this->m_bHasBeenResized = 1;
        this->m_bScrollable = 1;
      }
    }
    if ( this->m_ptLocation.y < rectScreen.top )
    {
      this->m_ptLocation.y = rectScreen.top;
      this->m_DropDirection = DROP_DIRECTION_NONE;
    }
    v63 = this->m_ptLocation.y;
    if ( v63 + v64 > rectScreen.bottom )
    {
      v64 = rectScreen.bottom - v63;
      this->m_bHasBeenResized = 1;
      this->m_bScrollable = 1;
    }
  }
  if ( v63 < rectScreen.top )
  {
    v70 = this->m_pParentBtn;
    if ( v70 != nullptr && v70->m_pWndParent != nullptr && CMFCPopupMenu::GetParentPopupMenu(this) == nullptr )
    {
      v71 = this->m_pParentBtn;
      rectMenu.right = v71->m_rect.right;
      rectMenu.bottom = 0;
      ClientToScreen(hWnd: v71->m_pWndParent->m_hWnd, lpPoint: (LPPOINT)&rectMenu.right);
      v72 = this->m_pParentBtn;
      Point.y = v72->m_rect.bottom;
      Point.x = 0;
      ClientToScreen(hWnd: v72->m_pWndParent->m_hWnd, lpPoint: &Point);
      this->m_ptLocation.y = Point.y;
      if ( pParentMenuBar == nullptr )
        goto LABEL_176;
      if ( pParentMenuBar->IsHorizontal(this: pParentMenuBar) != 0 )
        v73 = DROP_DIRECTION_BOTTOM;
      else
LABEL_176:
        v73 = DROP_DIRECTION_NONE;
      this->m_DropDirection = v73;
    }
    else
    {
      this->m_ptLocation.y = rectScreen.top;
    }
    if ( v64 + this->m_ptLocation.y > rectScreen.bottom )
    {
      v74 = rectScreen.bottom - rectScreen.top;
      this->m_ptLocation.y = rectScreen.top;
      if ( v64 > v74 )
      {
        v64 = v74;
        this->m_bHasBeenResized = 1;
        this->m_bScrollable = 1;
      }
      this->m_DropDirection = DROP_DIRECTION_NONE;
    }
  }
  if ( this->m_bScrollable != 0
    && this->m_bShowScrollBar != 0
    && this->m_bResizeTracking == 0
    && this->m_bWasResized == 0 )
  {
    Rect.right += GetSystemMetrics(nIndex: 2);
    if ( !IsRectEmpty(lprc: &this->m_rectResize) )
      this->m_rectResize.right += GetSystemMetrics(nIndex: 2);
  }
  this->m_FinalSize.cx = Rect.right;
  this->m_FinalSize.cy = v64;
  if ( CMFCPopupMenu::GetAnimationType(bNoSystem: 0) != NO_ANIMATION
    || this->m_bAnimationIsDone != 0
    || CMFCToolBar::m_bCustomizeMode != 0 )
  {
    if ( CMFCToolBar::m_bCustomizeMode == 0 )
    {
      m_iShadowSize = this->m_iShadowSize;
      Rect.right += m_iShadowSize;
      v64 += m_iShadowSize;
    }
    if ( this->m_pMenuCustomizationPage != nullptr )
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: Rect.right, cy: v64, nFlags: 0x16u);
    else
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: nullptr,
        x: this->m_ptLocation.x - (bRTL != 0 ? Rect.right : 0),
        y: this->m_ptLocation.y,
        cx: Rect.right,
        cy: v64,
        nFlags: 0x14u);
    if ( CMFCToolBar::m_bCustomizeMode != 0 )
      pMenuBar->AdjustLocations(this: pMenuBar);
  }
  if ( this->m_iShadowSize != 0 && CMFCToolBar::m_bCustomizeMode == 0 )
  {
    v76 = this->m_pParentBtn;
    if ( v76 != nullptr && v76->m_pWndParent != nullptr )
    {
      m_bShown = this->m_bShown;
      this->m_bShown = 1;
      m_pWndParent = v76->m_pWndParent;
      v87 = this->m_hWnd;
      Point.y = m_bShown;
      memset(&rectInter, 0, sizeof(rectInter));
      memset(&rectMenu, 0, sizeof(rectMenu));
      GetWindowRect(hWnd: v87, lpRect: &rectMenu);
      if ( bRTL != 0 )
        v79 = rectMenu.left - this->m_iShadowSize - 1;
      else
        v79 = rectMenu.right + 1;
      v80 = this->m_iShadowSize;
      rectShadowRight.top = rectMenu.top;
      rectShadowRight.left = v79;
      rectShadowRight.right = v79 + v80;
      rectShadowRight.bottom = rectMenu.bottom + v80;
      CWnd::ScreenToClient(this: m_pWndParent, lpRect: &rectShadowRight);
      if ( IntersectRect(lprcDst: &rectInter, lprcSrc1: &rectShadowRight, lprcSrc2: &this->m_pParentBtn->m_rect) )
      {
        InvalidateRect(hWnd: m_pWndParent->m_hWnd, lpRect: &this->m_pParentBtn->m_rect, bErase: true);
        UpdateWindow(hWnd: m_pWndParent->m_hWnd);
      }
      v81 = this->m_iShadowSize + rectMenu.right - rectMenu.left;
      Rect.top = rectMenu.bottom + 1;
      v82 = this->m_iShadowSize + rectMenu.bottom + 1;
      Rect.left = rectMenu.left;
      Rect.bottom = v82;
      Rect.right = v81 + rectMenu.left;
      CWnd::ScreenToClient(this: m_pWndParent, lpRect: &Rect);
      if ( IntersectRect(lprcDst: &rectInter, lprcSrc1: &Rect, lprcSrc2: &this->m_pParentBtn->m_rect) )
      {
        InvalidateRect(hWnd: m_pWndParent->m_hWnd, lpRect: &this->m_pParentBtn->m_rect, bErase: true);
        UpdateWindow(hWnd: m_pWndParent->m_hWnd);
      }
      this->m_bShown = Point.y;
    }
  }
  if ( this->m_bScrollable != 0
    && this->m_bShowScrollBar != 0
    && this->m_bResizeTracking == 0
    && this->m_bWasResized == 0 )
  {
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037D681
// Name: public: virtual void CMFCPopupMenu::SaveState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CMFCPopupMenu::SaveState(CMFCPopupMenu *this@<ecx>, int a2@<edi>)
{
  CMFCToolBarMenuButton *m_pParentBtn; // eax
  int v4; // eax
  HMENU v5; // edi
  CMFCPopupMenu *ParentPopupMenu; // eax

  if ( CMFCToolBar::m_bCustomizeMode != 0 )
  {
    m_pParentBtn = this->m_pParentBtn;
    if ( m_pParentBtn != nullptr && m_pParentBtn->m_bMenuPaletteMode == 0 )
    {
      v4 = ((int (__thiscall *)(CMFCPopupMenu *, int))this->GetMenuBar)(a1: this, a2);
      v5 = (HMENU)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 1080))(a1: v4);
      if ( v5 == nullptr )
        AfxThrowInvalidArgException();
      ((void (__thiscall *)(CMFCToolBarMenuButton *))this->m_pParentBtn->CreateFromMenu)(a1: this->m_pParentBtn);
      DestroyMenu(hMenu: v5);
      ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
      if ( ParentPopupMenu != nullptr )
        ParentPopupMenu->SaveState(this: ParentPopupMenu);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037D6ED
// Name: public: void CMFCPopupMenu::CloseMenu(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::CloseMenu(CMFCPopupMenu *this, int bSetFocusToBar)
{
  CMFCPopupMenu_vtbl *v3; // eax
  CMFCPopupMenu *ParentPopupMenu; // ebx
  CFrameWnd *TopLevelFrame; // eax
  CMFCToolBar *pParentToolBar; // [esp+8h] [ebp-4h]

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    v3 = this->__vftable;
    this->m_bTobeDstroyed = 1;
    ((void (*)(void))v3->SaveState)();
    ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
    pParentToolBar = (CMFCToolBar *)CMFCPopupMenu::GetParentToolBar(this);
    TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame == nullptr )
      TopLevelFrame = CWnd::GetTopLevelFrame(this);
    if ( ParentPopupMenu != nullptr )
    {
      this->m_bAutoDestroyParent = 0;
      CMFCPopupMenu::ActivatePopupMenu(pTopFrame: TopLevelFrame, pPopupMenu: ParentPopupMenu);
    }
    else
    {
      CMFCPopupMenu::ActivatePopupMenu(pTopFrame: TopLevelFrame, pPopupMenu: nullptr);
      CMFCPopupMenu::NotifyParentDlg(this, bActivate: 0);
      if ( pParentToolBar != nullptr && bSetFocusToBar != 0 )
        CWnd::SetFocus(this: pParentToolBar);
    }
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037D780
// Name: public: static int CMFCPopupMenu::ActivatePopupMenu(class CFrameWnd __near *,class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCPopupMenu::ActivatePopupMenu(CFrameWnd *pTopFrame, CMFCPopupMenu *pPopupMenu)
{
  CMDIFrameWndEx *v2; // eax
  int v3; // eax
  CFrameWndEx *v4; // eax
  COleIPFrameWndEx *v5; // eax
  COleDocIPFrameWndEx *v6; // eax
  CMFCPopupMenuBar *v8; // esi
  HWND Parent; // eax
  CWnd *v10; // eax
  CObject *v11; // eax
  CMFCShowAllButton *v12; // eax
  CMFCPopupMenuBar_vtbl *v13; // edx
  CMFCShowAllButton v14; // [esp+10h] [ebp-F8h] BYREF
  int v15; // [esp+104h] [ebp-4h]

  if ( pPopupMenu != nullptr )
    CMFCPopupMenu::NotifyParentDlg(this: pPopupMenu, bActivate: 1);
  if ( pTopFrame == nullptr )
    goto LABEL_17;
  v2 = (CMDIFrameWndEx *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: pTopFrame);
  if ( v2 != nullptr )
  {
    v3 = CMDIFrameWndEx::ShowPopupMenu(this: v2, pMenuPopup: pPopupMenu);
  }
  else
  {
    v4 = (CFrameWndEx *)AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: pTopFrame);
    if ( v4 != nullptr )
    {
      v3 = CFrameWndEx::ShowPopupMenu(this: v4, pMenuPopup: pPopupMenu);
    }
    else
    {
      v5 = (COleIPFrameWndEx *)AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: pTopFrame);
      if ( v5 != nullptr )
      {
        v3 = COleIPFrameWndEx::ShowPopupMenu(this: v5, pMenuPopup: pPopupMenu);
      }
      else
      {
        v6 = (COleDocIPFrameWndEx *)AfxDynamicDownCast(
                                      pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx,
                                      pObject: pTopFrame);
        if ( v6 == nullptr )
          goto LABEL_17;
        v3 = COleDocIPFrameWndEx::ShowPopupMenu(this: v6, pMenuPopup: pPopupMenu);
      }
    }
  }
  if ( v3 == 0 )
  {
    if ( pPopupMenu != nullptr && pPopupMenu->m_bTobeDstroyed == 0 )
      CMFCPopupMenu::CloseMenu(this: pPopupMenu, bSetFocusToBar: 0);
    return 0;
  }
LABEL_17:
  if ( pPopupMenu != nullptr )
  {
    v8 = pPopupMenu->GetMenuBar(this: pPopupMenu);
    Parent = GetParent(hWnd: v8->m_hWnd);
    v10 = CWnd::FromHandle(hWnd: Parent);
    v11 = AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v10);
    if ( v11 != nullptr
      && v11[82].__vftable != nullptr
      && v8->m_bAreAllCommandsShown == 0
      && (v8->m_Buttons.m_nCount == 0
       || AfxDynamicDownCast(
            pClass: &CMFCShowAllButton::classCMFCShowAllButton,
            pObject: v8->m_Buttons.m_pNodeTail->data) == nullptr) )
    {
      v12 = CMFCShowAllButton::CMFCShowAllButton(this: &v14);
      v13 = v8->__vftable;
      v15 = 0;
      v13->InsertButton(this: v8, a2: v12, a3: -1);
      v15 = -1;
      CMFCShowAllButton::~CMFCShowAllButton(this: &v14);
    }
    if ( pPopupMenu->m_bTrackMode != 0 )
      CMFCPopupMenu::m_pActivePopupMenu = (HWND)pPopupMenu;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037D8DD
// Name: protected: void CMFCPopupMenu::OnActivateApp(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnActivateApp(CMFCPopupMenu *this, int bActive, unsigned int __formal)
{
  if ( bActive == 0 && CMFCToolBar::m_bCustomizeMode == 0 && this->InCommand(this) == 0 )
  {
    if ( this->m_bTrackMode != 0 )
      this->m_bTobeDstroyed = 1;
    PostMessageA(hWnd: this->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037D926
// Name: protected: void CMFCPopupMenu::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnMouseMove(CMFCPopupMenu *this, unsigned int nFlags, CPoint point)
{
  CMFCPopupMenu_vtbl *v4; // eax

  if ( this->m_bTearOffTracking != 0 )
  {
    if ( !PtInRect(lprc: &this->m_rectTearOffCaption, pt: point.tagPOINT) )
    {
      ReleaseCapture();
      v4 = this->__vftable;
      this->m_bTearOffTracking = 0;
      ((void (__thiscall *)(CMFCPopupMenu *, int, int))v4->TearOff)(a1: this, a2: point.x, a3: point.y);
    }
  }
  else
  {
    CWnd::Default(this);
    if ( this->m_bScrollable != 0 && this->m_iScrollMode == 0 )
    {
      if ( PtInRect(lprc: &this->m_rectScrollUp, pt: point.tagPOINT) && this->IsScrollUpAvailable(this) != 0 )
      {
        this->m_iScrollMode = -1;
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollUp, bErase: true);
      }
      else if ( PtInRect(lprc: &this->m_rectScrollDn, pt: point.tagPOINT) && this->IsScrollDnAvailable(this) != 0 )
      {
        this->m_iScrollMode = 1;
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollDn, bErase: true);
      }
      else
      {
        this->m_iScrollMode = 0;
      }
      if ( this->m_iScrollMode != 0 )
        SetTimer(hWnd: this->m_hWnd, nIDEvent: 2u, uElapse: 0x50u, lpTimerFunc: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037DA22
// Name: protected: void CMFCPopupMenu::UpdateBottomWindows(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::UpdateBottomWindows(CMFCPopupMenu *this, int bCheckOnly)
{
  CWnd *TopLevelParent; // eax
  int m_iShadowSize; // edx
  int y; // edi
  int v6; // ecx
  int v7; // eax
  CWnd *pWndMain; // [esp+8h] [ebp-38h]
  CRect rectInter; // [esp+Ch] [ebp-34h] BYREF
  CRect rectMenu; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectMain; // [esp+2Ch] [ebp-14h] BYREF

  TopLevelParent = CWnd::GetTopLevelParent(this);
  pWndMain = TopLevelParent;
  if ( TopLevelParent != nullptr )
  {
    if ( this->m_iShadowSize == 0 || CMFCPopupMenu::m_bForceShadow != 0 )
    {
      UpdateWindow(hWnd: TopLevelParent->m_hWnd);
    }
    else
    {
      memset(&rectMain, 0, sizeof(rectMain));
      GetWindowRect(hWnd: TopLevelParent->m_hWnd, lpRect: &rectMain);
      m_iShadowSize = this->m_iShadowSize;
      y = this->m_ptLocation.y;
      v6 = m_iShadowSize + this->m_FinalSize.cy;
      v7 = m_iShadowSize + this->m_FinalSize.cx;
      rectMenu.left = this->m_ptLocation.x;
      rectMenu.top = y;
      rectMenu.right = v7 + rectMenu.left;
      rectMenu.bottom = v6 + y;
      if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
        OffsetRect(lprc: &rectMenu, dx: -(this->m_FinalSize.cx + this->m_iShadowSize), dy: 0);
      memset(&rectInter, 0, sizeof(rectInter));
      UnionRect(lprcDst: &rectInter, lprcSrc1: &rectMenu, lprcSrc2: &rectMain);
      if ( EqualRect(lprc1: &rectInter, lprc2: &rectMain) )
      {
        UpdateWindow(hWnd: pWndMain->m_hWnd);
      }
      else
      {
        this->m_iShadowSize = 0;
        if ( bCheckOnly == 0 )
          CWnd::SetWindowPos(
            this,
            pWndInsertAfter: nullptr,
            x: -1,
            y: -1,
            cx: this->m_FinalSize.cx,
            cy: this->m_FinalSize.cy,
            nFlags: 0x16u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037DB4F
// Name: protected: virtual void CMFCPopupMenu::DoPaint(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::DoPaint(CMFCPopupMenu *this, CDC *pPaintDC)
{
  bool v3; // zf
  unsigned int v4; // eax
  int m_iShadowSize; // eax
  CMFCToolBarMenuButton *m_pParentBtn; // ecx
  CWnd *m_pWndParent; // eax
  int *p_left; // esi
  HWND__ *v9; // ecx
  CMFCVisualManager *Instance; // eax
  CMFCPopupMenu *ParentPopupMenu; // eax
  CMFCToolBarMenuButton *v12; // ecx
  CWnd *v13; // eax
  int *v14; // esi
  HWND__ *v15; // ecx
  CDC *v16; // edi
  CMFCVisualManager *v17; // eax
  CMFCVisualManager *v18; // eax
  int m_iLogoWidth; // eax
  CMFCPopupMenu::LOGO_LOCATION m_nLogoLocation; // ecx
  __int32 v21; // ecx
  __int32 v22; // ecx
  CFrameWnd *TopLevelFrame; // esi
  CObject *v24; // eax
  CObject *v25; // eax
  CMFCVisualManager *v26; // eax
  CMFCVisualManager *v27; // eax
  int top; // eax
  int v29; // eax
  CMFCVisualManager *v30; // eax
  int v31; // edi
  CMFCVisualManager *v32; // eax
  RECT v33; // [esp-14h] [ebp-98h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-8Ch]
  HWND__ *v35; // [esp-8h] [ebp-8Ch]
  CClientDC v36; // [esp+10h] [ebp-74h] BYREF
  CDrawingManager v37; // [esp+24h] [ebp-60h] BYREF
  int v38; // [esp+2Ch] [ebp-58h]
  CDC *m_dc; // [esp+30h] [ebp-54h]
  tagRECT v40; // [esp+34h] [ebp-50h] BYREF
  tagRECT rc; // [esp+44h] [ebp-40h] BYREF
  tagRECT v42; // [esp+54h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+64h] [ebp-20h] BYREF
  int v44; // [esp+80h] [ebp-4h]

  m_dc = pPaintDC;
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  if ( this->m_iShadowSize != 0 && CMFCToolBar::m_bCustomizeMode == 0 )
  {
    v4 = CWnd::GetExStyle(this) & 0x400000;
    v3 = v4 == 0;
    v38 = v4;
    m_iShadowSize = this->m_iShadowSize;
    if ( v3 )
      Rect.right -= m_iShadowSize;
    else
      Rect.left += m_iShadowSize;
    Rect.bottom -= m_iShadowSize;
    memset(&rc, 0, sizeof(rc));
    SetRectEmpty(lprc: &rc);
    if ( this->m_pParentBtn != nullptr && CMFCPopupMenu::GetParentPopupMenu(this) == nullptr )
    {
      m_pParentBtn = this->m_pParentBtn;
      m_pWndParent = m_pParentBtn->m_pWndParent;
      if ( m_pWndParent != nullptr && m_pWndParent->m_hWnd != nullptr )
      {
        p_left = &m_pParentBtn->m_rect.left;
        v9 = this->m_hWnd;
        rc.left = *p_left++;
        rc.top = *p_left++;
        rc.right = *p_left;
        rc.bottom = p_left[1];
        --rc.right;
        --rc.bottom;
        MapWindowPoints(hWndFrom: m_pWndParent->m_hWnd, hWndTo: v9, lpPoints: (LPPOINT)&rc, cPoints: 2u);
      }
    }
    Instance = CMFCVisualManager::GetInstance();
    if ( Instance->IsOfficeXPStyleMenus(this: Instance) != 0 )
    {
      ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this);
      if ( ParentPopupMenu != nullptr )
      {
        v12 = this->m_pParentBtn;
        if ( v12 != nullptr
          && v12->m_bQuickCustomMode != 0
          && ParentPopupMenu->m_bQuickCusomize != 0
          && this->m_bQuickCusomize == 0
          && this->m_DropDirection == DROP_DIRECTION_LEFT )
        {
          v13 = v12->m_pWndParent;
          if ( v13 != nullptr && v13->m_hWnd != nullptr )
          {
            v14 = &v12->m_rect.left;
            v15 = this->m_hWnd;
            rc.left = *v14++;
            rc.top = *v14++;
            rc.right = *v14;
            rc.bottom = v14[1];
            rc.bottom += 2;
            MapWindowPoints(hWndFrom: v13->m_hWnd, hWndTo: v15, lpPoints: (LPPOINT)&rc, cPoints: 2u);
          }
        }
      }
    }
    if ( afxGlobalData.bIsWindowsVista != 0 )
    {
      CClientDC::CClientDC(this: &v36, pWnd: nullptr);
      v35 = this->m_hWnd;
      v44 = 0;
      memset(&v42, 0, sizeof(v42));
      GetWindowRect(hWnd: v35, lpRect: &v42);
      v16 = m_dc;
      BitBlt(
        hdc: m_dc->m_hDC,
        x: 0,
        y: 0,
        cx: v42.right - v42.left,
        cy: v42.bottom - v42.top,
        hdcSrc: v36.m_hDC,
        x1: v42.left,
        y1: v42.top,
        rop: 0xCC0020u);
      if ( v38 != 0 )
      {
        CDrawingManager::CDrawingManager(this: &v37, m_dc: v16);
        v40.left = 0;
        v40.top = 0;
        v40.right = v42.right - v42.left;
        v40.bottom = v42.bottom - v42.top;
        *(_QWORD *)&v33.left = 0;
        v33.right = v42.right - v42.left;
        LOBYTE(v44) = 1;
        v33.bottom = v42.bottom - v42.top;
        CDrawingManager::MirrorRect(this: &v37, rect: v33, bHorz: 1);
        LOBYTE(v44) = 0;
        CDrawingManager::~CDrawingManager(this: &v37);
      }
      v44 = -1;
      CClientDC::~CClientDC(this: &v36);
    }
    v17 = CMFCVisualManager::GetInstance();
    v17->OnDrawMenuShadow(
      this: v17,
      a2: m_dc,
      a3: (const CRect *)&Rect,
      a4: (const CRect *)&rc,
      a5: this->m_iShadowSize,
      a6: 100,
      a7: 65,
      a8: &this->m_bmpShadowBottom,
      a9: &this->m_bmpShadowRight,
      a10: v38);
    if ( v38 != 0 )
      OffsetRect(lprc: &Rect, dx: -this->m_iShadowSize, dy: 0);
  }
  v18 = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCPopupMenu *, int, int, int, int))v18->OnDrawMenuBorder)(
    a1: v18,
    a2: m_dc,
    a3: this,
    a4: Rect.left,
    a5: Rect.top,
    a6: Rect.right,
    a7: Rect.bottom);
  v38 = this->GetBorderSize(this);
  InflateRect(lprc: &Rect, dx: -v38, dy: -v38);
  m_iLogoWidth = this->m_iLogoWidth;
  if ( m_iLogoWidth > 0 )
  {
    m_nLogoLocation = this->m_nLogoLocation;
    v40 = Rect;
    if ( m_nLogoLocation != MENU_LOGO_LEFT )
    {
      v21 = m_nLogoLocation - 1;
      if ( v21 != 0 )
      {
        v22 = v21 - 1;
        if ( v22 != 0 )
        {
          if ( v22 == 1 )
            v40.top = Rect.bottom - m_iLogoWidth - v38;
        }
        else
        {
          v40.bottom = v38 + Rect.top + m_iLogoWidth;
        }
      }
      else
      {
        v40.left = Rect.right - m_iLogoWidth - v38;
      }
    }
    else
    {
      v40.right = Rect.left + v38 + m_iLogoWidth;
    }
    TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame == nullptr )
      TopLevelFrame = CWnd::GetTopLevelFrame(this);
    v24 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
    if ( v24 != nullptr )
      goto LABEL_43;
    v25 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: TopLevelFrame);
    if ( v25 != nullptr )
    {
      ((void (__thiscall *)(CObject *, CDC *, CMFCPopupMenu *, tagRECT *))v25->__vftable[40].GetRuntimeClass)(
        a1: v25,
        a2: m_dc,
        a3: this,
        a4: &v40);
      goto LABEL_44;
    }
    v24 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: TopLevelFrame);
    if ( v24 != nullptr
      || (v24 = AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject: TopLevelFrame)) != nullptr )
    {
LABEL_43:
      ((void (__thiscall *)(CObject *, CDC *, CMFCPopupMenu *, tagRECT *))v24->__vftable[42].dtr_CObject)(
        a1: v24,
        a2: m_dc,
        a3: this,
        a4: &v40);
    }
  }
LABEL_44:
  if ( !IsRectEmpty(lprc: &this->m_rectTearOffCaption) )
  {
    v26 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int))v26->OnDrawTearOffCaption)(
      a1: v26,
      a2: m_dc,
      a3: this->m_rectTearOffCaption.left,
      a4: this->m_rectTearOffCaption.top,
      a5: this->m_rectTearOffCaption.right,
      a6: this->m_rectTearOffCaption.bottom,
      a7: this->m_bIsTearOffCaptionActive);
  }
  if ( this->m_bScrollable != 0 )
  {
    if ( this->IsScrollUpAvailable(this) != 0 )
    {
      v27 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD, bool, _DWORD, _DWORD))v27->OnDrawMenuScrollButton)(
        a1: v27,
        a2: m_dc,
        a3: this->m_rectScrollUp.left,
        a4: this->m_rectScrollUp.top,
        a5: this->m_rectScrollUp.right,
        a6: this->m_rectScrollUp.bottom,
        a7: 0,
        a8: this->m_iScrollMode < 0,
        a9: 0,
        a10: 0);
    }
    if ( this->IsScrollDnAvailable(this) != 0 )
    {
      if ( this->GetMenuBar(this) != nullptr )
      {
        top = this->m_rectScrollDn.top;
        v42.left = Rect.left;
        v42.right = Rect.right;
        v42.bottom = top;
        v42.top = top - v38 - 1;
        v38 = (int)CMFCVisualManager::GetInstance();
        v37.m_dc = (CDC *)(*(_DWORD *)v38 + 52);
        v29 = ((int (__thiscall *)(CMFCPopupMenu *, int, int, int, int, int, int, int, int, _DWORD))this->GetMenuBar)(
                a1: this,
                a2: v42.left,
                a3: v42.top,
                a4: v42.right,
                a5: v42.bottom,
                a6: v42.left,
                a7: v42.top,
                a8: v42.right,
                a9: v42.bottom,
                a10: 0);
        ((void (__thiscall *)(int, CDC *, int))v37.m_dc->__vftable)(a1: v38, a2: m_dc, a3: v29);
      }
      v30 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, bool, _DWORD, _DWORD))v30->OnDrawMenuScrollButton)(
        a1: v30,
        a2: m_dc,
        a3: this->m_rectScrollDn.left,
        a4: this->m_rectScrollDn.top,
        a5: this->m_rectScrollDn.right,
        a6: this->m_rectScrollDn.bottom,
        a7: 1,
        a8: this->m_iScrollMode > 0,
        a9: 0,
        a10: 0);
    }
  }
  if ( !IsRectEmpty(lprc: &this->m_rectResize) )
  {
    if ( this->m_bIsResizeBarOnTop != 0 )
      v31 = (this->m_sizeMinResize.cx > 0) + 2;
    else
      v31 = this->m_sizeMinResize.cx > 0;
    v32 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int))v32->OnDrawMenuResizeBar)(
      a1: v32,
      a2: m_dc,
      a3: this->m_rectResize.left,
      a4: this->m_rectResize.top,
      a5: this->m_rectResize.right,
      a6: this->m_rectResize.bottom,
      a7: v31);
  }
  this->m_bShown = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037E027
// Name: protected: virtual void CMFCPopupMenu::DrawFade(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::DrawFade(CMFCPopupMenu *this, CDC *pPaintDC)
{
  void *v3; // edi
  int m_iShadowSize; // ecx
  int v5; // ebx
  int v6; // eax
  HDC m_hDC; // eax
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  void *m_hObject; // ebx
  HBITMAP v11; // eax
  HBITMAP v12; // eax
  HBITMAP v13; // eax
  void *v14; // eax
  HDC v15; // eax
  void *v16; // eax
  CMFCPopupMenu_vtbl *v17; // eax
  CMFCPopupMenuBar *v18; // ebx
  void *v19; // eax
  char *m_cFadeDstBits; // ebx
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  void *v22; // eax
  char *v23; // ecx
  unsigned int v24; // eax
  CGdiObject *v25; // ebx
  void *v26; // eax
  int top; // edx
  int left; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-A8h]
  _BYTE v30[8]; // [esp+10h] [ebp-90h] BYREF
  _BYTE v31[4]; // [esp+18h] [ebp-88h] BYREF
  CGdiObject *v32; // [esp+1Ch] [ebp-84h]
  int v33; // [esp+20h] [ebp-80h]
  int v34; // [esp+24h] [ebp-7Ch]
  CDC *v35; // [esp+28h] [ebp-78h]
  int cy; // [esp+2Ch] [ebp-74h]
  char *m_cFadeSrcBits; // [esp+30h] [ebp-70h]
  CDC v38; // [esp+34h] [ebp-6Ch] BYREF
  CGdiObject *m_cFadeTmpBits; // [esp+44h] [ebp-5Ch]
  BITMAPINFO pbmi; // [esp+48h] [ebp-58h] BYREF
  int v41; // [esp+74h] [ebp-2Ch]
  int v42; // [esp+78h] [ebp-28h]
  int v43; // [esp+7Ch] [ebp-24h]
  tagRECT Rect; // [esp+80h] [ebp-20h] BYREF
  int v45; // [esp+9Ch] [ebp-4h]

  v35 = pPaintDC;
  v3 = nullptr;
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  m_iShadowSize = this->m_iShadowSize;
  v5 = m_iShadowSize + this->m_FinalSize.cx;
  v6 = m_iShadowSize + this->m_FinalSize.cy;
  v34 = v5;
  cy = v6;
  CDC::CDC(this: &v38);
  v45 = 0;
  if ( pPaintDC != nullptr )
    m_hDC = v35->m_hDC;
  else
    m_hDC = nullptr;
  CompatibleDC = CreateCompatibleDC(hdc: m_hDC);
  if ( CDC::Attach(this: &v38, hDC: CompatibleDC) != 0 )
  {
    if ( this != (CMFCPopupMenu *)-4004 && this->m_bmpScreenDst.m_hObject != nullptr )
      goto LABEL_33;
    if ( CMFCPopupMenu::GetAnimationType(bNoSystem: 0) != FADE && afxGlobalData.m_nBitsPerPixel <= 8 )
    {
      CompatibleBitmap = CreateCompatibleBitmap(hdc: v35->m_hDC, cx: v5, cy);
      CGdiObject::Attach(this: &this->m_bmpScreenDst, hObject: CompatibleBitmap);
      if ( this == (CMFCPopupMenu *)-4004 )
        m_hObject = nullptr;
      else
        m_hObject = this->m_bmpScreenDst.m_hObject;
      m_cFadeTmpBits = CDC::SelectGdiObject(hDC: v38.m_hDC, h: m_hObject);
LABEL_29:
      v17 = this->__vftable;
      pbmi.bmiColors[0] = 0;
      v41 = 0;
      v42 = 0;
      v43 = 0;
      v17->DoPaint(this, a2: &v38);
      v18 = this->GetMenuBar(this);
      GetWindowRect(hWnd: v18->m_hWnd, lpRect: (LPRECT)pbmi.bmiColors);
      CWnd::ScreenToClient(this, lpRect: (tagRECT *)pbmi.bmiColors);
      v38.SetViewportOrg(this: &v38, result: (CPoint *)v31, a3: *(_DWORD *)pbmi.bmiColors, a4: v41);
      v18->DoPaint(this: v18, a2: &v38);
      v38.SetViewportOrg(this: &v38, result: (CPoint *)v30, a3: 0, a4: 0);
      if ( m_cFadeTmpBits != nullptr )
        v19 = m_cFadeTmpBits->m_hObject;
      else
        v19 = nullptr;
      CDC::SelectGdiObject(hDC: v38.m_hDC, h: v19);
LABEL_33:
      m_cFadeDstBits = (char *)this->m_cFadeDstBits;
      m_cFadeSrcBits = (char *)this->m_cFadeSrcBits;
      m_cFadeTmpBits = (CGdiObject *)this->m_cFadeTmpBits;
      AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
      if ( AnimationType > NO_ANIMATION )
      {
        if ( AnimationType <= SLIDE )
        {
          if ( this == (CMFCPopupMenu *)-4004 )
            v26 = nullptr;
          else
            v26 = this->m_bmpScreenDst.m_hObject;
          v25 = CDC::SelectGdiObject(hDC: v38.m_hDC, h: v26);
          if ( this->m_bIsAnimDown != 0 )
            top = Rect.top;
          else
            top = Rect.bottom - this->m_AnimSize.cy;
          if ( this->m_bIsAnimRight != 0 )
            left = Rect.left;
          else
            left = Rect.right - this->m_AnimSize.cx;
          BitBlt(
            hdc: v35->m_hDC,
            x: left,
            y: top,
            cx: this->m_AnimSize.cx,
            cy: this->m_AnimSize.cy,
            hdcSrc: v38.m_hDC,
            x1: 0,
            y1: 0,
            rop: 0xCC0020u);
LABEL_54:
          if ( v25 != nullptr )
            v3 = v25->m_hObject;
          goto LABEL_56;
        }
        if ( AnimationType == FADE )
        {
          if ( this == (CMFCPopupMenu *)-4012 )
            v22 = nullptr;
          else
            v22 = this->m_bmpScreenTmp.m_hObject;
          v32 = CDC::SelectGdiObject(hDC: v38.m_hDC, h: v22);
          if ( v34 * cy > 0 )
          {
            v23 = (char *)(m_cFadeSrcBits - m_cFadeDstBits);
            m_cFadeSrcBits -= (int)m_cFadeDstBits;
            v33 = (char *)m_cFadeTmpBits - m_cFadeDstBits;
            m_cFadeTmpBits = (CGdiObject *)(v34 * cy);
            while ( 1 )
            {
              v24 = CDrawingManager::PixelAlpha(
                      srcPixel: *(_DWORD *)&m_cFadeDstBits[(_DWORD)v23],
                      dstPixel: *(_DWORD *)m_cFadeDstBits,
                      percent: 100 - this->m_iFadePercent);
              *(_DWORD *)&m_cFadeDstBits[v33] = v24;
              m_cFadeDstBits += 4;
              m_cFadeTmpBits = (CGdiObject *)((char *)m_cFadeTmpBits - 1);
              if ( m_cFadeTmpBits == nullptr )
                break;
              v23 = m_cFadeSrcBits;
            }
          }
          BitBlt(
            hdc: v35->m_hDC,
            x: Rect.left,
            y: Rect.top,
            cx: v34,
            cy,
            hdcSrc: v38.m_hDC,
            x1: 0,
            y1: 0,
            rop: 0xCC0020u);
          v25 = v32;
          goto LABEL_54;
        }
      }
LABEL_56:
      CDC::SelectGdiObject(hDC: v38.m_hDC, h: v3);
      goto LABEL_57;
    }
    pbmi.bmiHeader.biHeight = cy;
    pbmi.bmiHeader.biPlanes = 1;
    m_cFadeSrcBits = (char *)(v5 * cy);
    pbmi.bmiHeader.biSizeImage = v5 * cy;
    pbmi.bmiHeader.biWidth = v5;
    pbmi.bmiHeader.biSize = 40;
    pbmi.bmiHeader.biBitCount = 32;
    pbmi.bmiHeader.biCompression = 0;
    memset(&pbmi.bmiHeader.biXPelsPerMeter, 0, 16);
    v11 = CreateDIBSection(
            hdc: v38.m_hDC,
            &pbmi,
            usage: 0,
            ppvBits: (void **)&this->m_cFadeSrcBits,
            hSection: nullptr,
            offset: 0);
    if ( v11 != nullptr && this->m_cFadeSrcBits != nullptr )
    {
      CGdiObject::Attach(this: &this->m_bmpScreenSrc, hObject: v11);
      v12 = CreateDIBSection(
              hdc: v38.m_hDC,
              &pbmi,
              usage: 0,
              ppvBits: (void **)&this->m_cFadeDstBits,
              hSection: nullptr,
              offset: 0);
      if ( v12 != nullptr && this->m_cFadeDstBits != nullptr )
      {
        CGdiObject::Attach(this: &this->m_bmpScreenDst, hObject: v12);
        v13 = CreateDIBSection(
                hdc: v38.m_hDC,
                &pbmi,
                usage: 0,
                ppvBits: (void **)&this->m_cFadeTmpBits,
                hSection: nullptr,
                offset: 0);
        if ( v13 != nullptr && this->m_cFadeTmpBits != nullptr )
        {
          CGdiObject::Attach(this: &this->m_bmpScreenTmp, hObject: v13);
          if ( this == (CMFCPopupMenu *)-3996 )
            v14 = nullptr;
          else
            v14 = this->m_bmpScreenSrc.m_hObject;
          m_cFadeTmpBits = CDC::SelectGdiObject(hDC: v38.m_hDC, h: v14);
          if ( v35 != nullptr )
            v15 = v35->m_hDC;
          else
            v15 = nullptr;
          BitBlt(hdc: v38.m_hDC, x: 0, y: 0, cx: v34, cy, hdcSrc: v15, x1: Rect.left, y1: Rect.top, rop: 0xCC0020u);
          memcpy(
            dst: (unsigned __int8 *)this->m_cFadeDstBits,
            src: (unsigned __int8 *)this->m_cFadeSrcBits,
            count: 4 * (_DWORD)m_cFadeSrcBits);
          if ( this == (CMFCPopupMenu *)-4004 )
            v16 = nullptr;
          else
            v16 = this->m_bmpScreenDst.m_hObject;
          CDC::SelectGdiObject(hDC: v38.m_hDC, h: v16);
          goto LABEL_29;
        }
      }
    }
  }
LABEL_57:
  v45 = -1;
  CDC::~CDC(this: &v38);
}

//------------------------------------------------------------------------------
// Address: 0x103E5378
// Name: public: virtual struct CRuntimeClass __near * CMFCDropDownToolbarButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCDropDownToolbarButton::GetRuntimeClass(CMFCDropDownToolbarButton *this)
{
  return &CMFCDropDownToolbarButton::classCMFCDropDownToolbarButton;
}

//------------------------------------------------------------------------------
// Address: 0x103E537E
// Name: public: void CMFCDropDownToolbarButton::SetDefaultCommand(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolbarButton::SetDefaultCommand(CMFCDropDownToolbarButton *this, unsigned int uiCmd)
{
  CMFCDropDownToolBar *m_pToolBar; // ecx
  int v5; // ebx
  CMFCToolBarButton *Button; // eax
  int m_bUserButton; // ecx
  int m_iUserImage; // eax
  int iImage; // [esp+14h] [ebp+8h]

  m_pToolBar = this->m_pToolBar;
  this->m_iSelectedImage = -1;
  v5 = 0;
  this->m_nID = uiCmd;
  iImage = 0;
  if ( CMFCToolBar::GetCount(this: m_pToolBar) <= 0 )
    goto LABEL_13;
  while ( 1 )
  {
    Button = CMFCToolBar::GetButton(this: this->m_pToolBar, nIndex: v5);
    if ( (Button->m_nStyle & 1) == 0 )
      break;
LABEL_5:
    if ( ++v5 >= CMFCToolBar::GetCount(this: this->m_pToolBar) )
      goto LABEL_13;
  }
  if ( Button->m_nID != uiCmd )
  {
    ++iImage;
    goto LABEL_5;
  }
  m_bUserButton = Button->m_bUserButton;
  this->m_bLocalUserButton = m_bUserButton;
  if ( m_bUserButton != 0 )
  {
    if ( Button->m_bUserButton != 0 )
      m_iUserImage = Button->m_iUserImage;
    else
      m_iUserImage = Button->m_iImage;
  }
  else
  {
    m_iUserImage = iImage;
  }
  this->m_iSelectedImage = m_iUserImage;
LABEL_13:
  if ( this->m_iSelectedImage == -1 )
    this->m_iSelectedImage = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E5409
// Name: TimerProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall TimerProc(HWND__ *hWnd, unsigned int __formal, unsigned int a3, unsigned int a4)
{
  CWnd *v4; // eax

  v4 = CWnd::FromHandle(hWnd);
  if ( g_pButtonDown != nullptr )
    g_pButtonDown->OnClick(this: g_pButtonDown, a2: v4, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103E542C
// Name: public: virtual struct tagSIZE CMFCDropDownToolbarButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CMFCDropDownToolbarButton::OnCalculateSize(
        CMFCDropDownToolbarButton *this,
        CDC *pDC,
        CDC *sizeDefault,
        CSize *bHorz,
        int bHorza)
{
  CMFCDropDownToolBar *m_pToolBar; // ecx
  CMFCToolBarButton *Button; // eax
  int m_bImage; // edi
  CDC *v9; // eax
  long double v10; // st7
  CDC_vtbl *v11; // ebx
  int m_hDC; // eax
  int v13; // edx
  long double m_dblRibbonImageScale; // st5
  int v15; // eax
  HDC__ *cy; // ecx
  CSize sizeBtn; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nID == 0 )
  {
    m_pToolBar = this->m_pToolBar;
    if ( m_pToolBar != nullptr )
    {
      Button = CMFCToolBar::GetButton(this: m_pToolBar, nIndex: 0);
      if ( Button != nullptr )
        CMFCDropDownToolbarButton::SetDefaultCommand(this, uiCmd: Button->m_nID);
    }
  }
  m_bImage = this->m_bImage;
  this->m_iImage = this->m_iSelectedImage;
  this->m_bImage = 1;
  v9 = CMFCToolBarButton::OnCalculateSize(
         this,
         pDC: (CDC *)&sizeBtn,
         (const CSize *)sizeDefault,
         bHorz: &bHorz->cx,
         a5: bHorza);
  v10 = 1.0;
  v11 = v9->__vftable;
  m_hDC = (int)v9->m_hDC;
  this->m_iImage = -1;
  this->m_bImage = m_bImage;
  sizeBtn.cy = m_hDC;
  v13 = 7;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  if ( 1.0 != m_dblRibbonImageScale )
  {
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      v10 = afxGlobalData.m_dblRibbonImageScale;
    v13 = (int)(v10 * 7.0);
  }
  if ( CMFCToolBar::m_bLargeIcons != 0 )
    v15 = v13 + 2;
  else
    v15 = v13 / 2 + 1;
  cy = (HDC__ *)sizeBtn.cy;
  pDC->__vftable = (CDC_vtbl *)((char *)v11 + v15);
  pDC->m_hDC = cy;
  return pDC;
}

//------------------------------------------------------------------------------
// Address: 0x103E54FD
// Name: public: void CMFCDropDownToolBar::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolBar::OnLButtonUp(CMFCDropDownToolBar *this, unsigned int nFlags, CPoint point)
{
  CFrameWnd *ParentFrame; // eax
  int m_iHighlighted; // eax
  CMFCToolBarButton *Button; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  int v8; // [esp-4h] [ebp-20h]
  CRect rectClient; // [esp+8h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    if ( !PtInRect(lprc: &rectClient, pt: point.tagPOINT) )
    {
      ParentFrame = CWnd::GetParentFrame(this);
      ParentFrame->DestroyWindow(this: ParentFrame);
      return;
    }
    if ( CMFCToolBar::m_bCustomizeMode == 0 )
    {
      m_iHighlighted = this->m_iHighlighted;
      if ( m_iHighlighted >= 0 )
      {
        v8 = this->m_iHighlighted;
        this->m_iButtonCapture = m_iHighlighted;
        Button = CMFCToolBar::GetButton(this, nIndex: v8);
        Button->m_nStyle &= ~0x20000u;
      }
    }
  }
  CMFCToolBar::OnLButtonUp(this, nFlags, point);
}

//------------------------------------------------------------------------------
// Address: 0x103E55A1
// Name: protected: void CMFCDropDownFrame::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::OnSize(CMFCDropDownFrame *this, unsigned int nType, int cx, int cy)
{
  CFrameWnd::OnSize(this, nType, cx, cy);
  if ( this != (CMFCDropDownFrame *)-296 && this->m_wndToolBar.m_hWnd != nullptr )
    this->m_wndToolBar.SetWindowPos(
      this: &this->m_wndToolBar,
      a2: nullptr,
      a3: 2,
      a4: 2,
      a5: cx - 4,
      a6: cy - 4,
      a7: 20u,
      a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103E55EC
// Name: protected: void CMFCDropDownFrame::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::OnPaint(CMFCDropDownFrame *this)
{
  CPaintDC v2; // [esp+10h] [ebp-74h] BYREF
  tagRECT Rect; // [esp+64h] [ebp-20h] BYREF
  int v4; // [esp+80h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v2, pWnd: this);
  v4 = 0;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &Rect);
  CDC::Draw3dRect(
    this: &v2,
    lpRect: &Rect,
    clrTopLeft: afxGlobalData.clrBarLight,
    clrBottomRight: afxGlobalData.clrBarDkShadow);
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: &v2,
    lpRect: &Rect,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarShadow);
  v4 = -1;
  CPaintDC::~CPaintDC(this: &v2);
}

//------------------------------------------------------------------------------
// Address: 0x103E5671
// Name: public: virtual void CMFCDropDownFrame::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::RecalcLayout(CMFCDropDownFrame *this, int __formal)
{
  CMFCDropDownToolbarButton *m_pParentBtn; // eax
  CObject *v4; // eax
  int v5; // eax
  int m_y; // ecx
  int m_x; // eax
  HMONITOR v8; // eax
  int right; // eax
  CMFCDropDownToolbarButton *v10; // ecx
  CObject *v11; // ebx
  int v12; // eax
  int v13; // ecx
  int cy; // edx
  CMFCDropDownToolbarButton *v15; // eax
  int v16; // ecx
  HWND v17; // [esp-Ch] [ebp-68h]
  CSize size; // [esp+8h] [ebp-54h] BYREF
  tagMONITORINFO mi; // [esp+10h] [ebp-4Ch] BYREF
  CRect rectParent; // [esp+38h] [ebp-24h] BYREF
  CRect rectScreen; // [esp+48h] [ebp-14h] BYREF

  if ( !IsWindow(hWnd: this->m_hWnd) || !IsWindow(hWnd: this->m_wndToolBar.m_hWnd) )
    return;
  m_pParentBtn = this->m_pParentBtn;
  if ( m_pParentBtn != nullptr
    && (v4 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: m_pParentBtn->m_pWndParent)) != nullptr )
  {
    v5 = ((int (__thiscall *)(CObject *))v4->__vftable[29].dtr_CObject)(a1: v4);
  }
  else
  {
    v5 = 1;
  }
  this->m_wndToolBar.CalcSize(this: &this->m_wndToolBar, result: &size, a3: v5);
  m_y = this->m_y;
  m_x = this->m_x;
  size.cx += 6;
  size.cy += 6;
  memset(&rectScreen, 0, sizeof(rectScreen));
  mi.cbSize = 40;
  v8 = MonitorFromPoint(pt: (POINT)__PAIR64__(m_y, m_x), dwFlags: 2u);
  if ( GetMonitorInfoA(hMonitor: v8, lpmi: &mi) )
    CopyRect(lprcDst: &rectScreen, lprcSrc: &mi.rcWork);
  else
    SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rectScreen, fWinIni: 0);
  right = rectScreen.right;
  if ( size.cx + this->m_x > rectScreen.right )
  {
    v10 = this->m_pParentBtn;
    if ( v10 != nullptr )
    {
      v11 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v10->m_pWndParent);
      if ( v11 != nullptr && ((int (__thiscall *)(CObject *))v11->__vftable[29].dtr_CObject)(a1: v11) == 0 )
      {
        v17 = (HWND)v11[8].__vftable;
        memset(&rectParent, 0, sizeof(rectParent));
        GetWindowRect(hWnd: v17, lpRect: &rectParent);
        v12 = rectParent.left - size.cx;
LABEL_17:
        this->m_x = v12;
        goto LABEL_18;
      }
      right = rectScreen.right;
    }
    v12 = right - rectScreen.left - size.cx - 1;
    goto LABEL_17;
  }
LABEL_18:
  v13 = this->m_y;
  cy = size.cy;
  if ( v13 + size.cy > rectScreen.bottom )
  {
    v15 = this->m_pParentBtn;
    v16 = v13 - size.cy;
    this->m_y = v16;
    if ( v15 != nullptr )
    {
      this->m_y = v15->m_rect.top - v15->m_rect.bottom + v16 - 4;
    }
    else if ( v16 < 0 )
    {
      this->m_y = 0;
    }
  }
  CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: this->m_x, y: this->m_y, cx: size.cx, cy, nFlags: 0x14u);
}

//------------------------------------------------------------------------------
// Address: 0x103E581F
// Name: protected: void CMFCDropDownFrame::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::OnDestroy(CMFCDropDownFrame *this)
{
  CObject *v2; // esi
  CPoint point; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_pParentBtn != nullptr )
  {
    this->m_pParentBtn->m_pPopupMenu = nullptr;
    this->m_pParentBtn->m_nStyle &= ~0x20000u;
    v2 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: this->m_pParentBtn->m_pWndParent);
    if ( v2 != nullptr )
    {
      point.x = 0;
      point.y = 0;
      GetCursorPos(lpPoint: &point);
      ScreenToClient(hWnd: (HWND)v2[8].__vftable, lpPoint: &point);
      SendMessageA(
        hWnd: (HWND)v2[8].__vftable,
        Msg: 0x202u,
        wParam: 0,
        lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
    }
  }
  CFrameWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103E58AC
// Name: protected: int CMFCDropDownFrame::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownFrame::OnEraseBkgnd(CMFCDropDownFrame *this, CDC *pDC)
{
  CRect rectClient; // [esp+4h] [ebp-14h] BYREF

  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
  CDC::FillSolidRect(this: pDC, lpRect: &rectClient, clr: afxGlobalData.clrBarFace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103E5902
// Name: protected: void CMFCDropDownFrame::OnActivateApp(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::OnActivateApp(CMFCDropDownFrame *this, int bActive, unsigned int __formal)
{
  if ( bActive == 0 && CMFCToolBar::m_bCustomizeMode == 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103E5927
// Name: public: virtual void CMFCDropDownToolbarButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolbarButton::OnDraw(
        CMFCDropDownToolbarButton *this,
        CDC *pDC,
        CRect *rect,
        CMFCToolBarImages *__formal,
        int bHorz,
        int bCustomizeMode,
        int bHighlight,
        int bDrawBorder,
        int bGrayDisabledButtons)
{
  long double v10; // st7
  int v11; // edx
  long double m_dblRibbonImageScale; // st5
  CMFCDropDownToolBar *m_pToolBar; // esi
  long double v14; // st7
  long double v15; // st6
  CMFCToolBarImages *p_m_LargeImagesLocked; // esi
  CMFCToolBarImages *v17; // ecx
  int m_iSelectedImage; // eax
  int m_bDisableFill; // ecx
  int m_bLocalUserButton; // eax
  CRect *v21; // esi
  int cy; // eax
  CMFCToolBarImages *v23; // ecx
  int v24; // ecx
  BOOL v25; // eax
  int v26; // edx
  int v27; // edi
  CDC_vtbl *v28; // eax
  unsigned int m_nStyle; // eax
  bool v30; // zf
  CMFCVisualManager *Instance; // eax
  unsigned int m_nID; // eax
  CMFCVisualManager *v33; // eax
  tagAFXDrawState v34; // [esp+Ch] [ebp-5Ch] BYREF
  int v35; // [esp+18h] [ebp-50h]
  CMFCToolBarImages *pImages; // [esp+1Ch] [ebp-4Ch]
  CRect *v37; // [esp+20h] [ebp-48h]
  int bImage; // [esp+24h] [ebp-44h]
  int nHalfArrowSize; // [esp+28h] [ebp-40h]
  int nActualArrowSize; // [esp+2Ch] [ebp-3Ch]
  CSize result; // [esp+30h] [ebp-38h] BYREF
  CDC *v42; // [esp+38h] [ebp-30h]
  CRect rectParent; // [esp+3Ch] [ebp-2Ch] BYREF
  CPoint triang[3]; // [esp+4Ch] [ebp-1Ch] BYREF

  v42 = pDC;
  v37 = rect;
  CMFCToolBarButton::FillInterior(this, pDC, rect, bHighlight, bMenuImage: 0);
  v10 = 1.0;
  v11 = 7;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  if ( 1.0 != m_dblRibbonImageScale )
  {
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      v10 = afxGlobalData.m_dblRibbonImageScale;
    v11 = (int)(v10 * 7.0);
  }
  if ( CMFCToolBar::m_bLargeIcons != 0 )
    nActualArrowSize = 2 * v11;
  else
    nActualArrowSize = v11;
  if ( CMFCToolBar::m_bLargeIcons != 0 )
    nHalfArrowSize = v11;
  else
    nHalfArrowSize = v11 / 2 + 1;
  rectParent = *rect;
  m_pToolBar = this->m_pToolBar;
  rectParent.right += -1 - nActualArrowSize / 2;
  if ( m_pToolBar != nullptr )
  {
    bImage = this->m_bImage;
    this->m_bInternalDraw = 1;
    CMFCToolBar::GetImageSize(this: m_pToolBar, &result);
    v14 = afxGlobalData.m_dblRibbonImageScale;
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      v15 = afxGlobalData.m_dblRibbonImageScale;
    else
      v15 = 1.0;
    if ( 1.0 != v15 )
    {
      if ( afxGlobalData.m_bIsRibbonImageScale == 0 )
        v14 = 1.0;
      v35 = (int)((double)result.cx * v14 + 0.5);
      result.cx = v35;
      result.cy = (int)(v14 * (double)result.cy + 0.5);
    }
    if ( CMFCToolBar::m_bLargeIcons != 0 && m_pToolBar->m_LargeImagesLocked.m_iCount > 0 )
      p_m_LargeImagesLocked = &m_pToolBar->m_LargeImagesLocked;
    else
      p_m_LargeImagesLocked = &m_pToolBar->m_ImagesLocked;
    pImages = p_m_LargeImagesLocked;
    if ( this->m_bLocalUserButton != 0 )
    {
      CMFCToolBarImages::SetTransparentColor(this: CMFCToolBar::m_pUserImages, clrTransparent: afxGlobalData.clrBtnFace);
      v17 = CMFCToolBar::m_pUserImages;
    }
    else
    {
      CMFCToolBarImages::SetTransparentColor(this: p_m_LargeImagesLocked, clrTransparent: afxGlobalData.clrBtnFace);
      v17 = p_m_LargeImagesLocked;
    }
    CMFCToolBarImages::PrepareDrawImage(this: v17, ds: &v34, sizeImageDest: result, bFadeInactive: 0);
    m_iSelectedImage = this->m_iSelectedImage;
    m_bDisableFill = this->m_bDisableFill;
    this->m_iImage = m_iSelectedImage;
    this->m_iUserImage = m_iSelectedImage;
    this->m_bImage = 1;
    this->m_bDisableFill = 1;
    m_bLocalUserButton = this->m_bLocalUserButton;
    result.cy = m_bDisableFill;
    if ( m_bLocalUserButton != 0 )
    {
      v21 = v37;
      this->m_bUserButton = m_bLocalUserButton;
      CMFCToolBarButton::OnDraw(
        this,
        pDC: v42,
        rect: v21,
        pImages: CMFCToolBar::m_pUserImages,
        bHorz,
        bCustomizeMode,
        bHighlight,
        bDrawBorder: 0,
        bGrayDisabledButtons);
      this->m_bUserButton = 0;
    }
    else
    {
      CMFCToolBarButton::OnDraw(
        this,
        pDC: v42,
        rect: &rectParent,
        pImages,
        bHorz,
        bCustomizeMode,
        bHighlight,
        bDrawBorder: 0,
        bGrayDisabledButtons);
      v21 = v37;
    }
    cy = result.cy;
    this->m_iImage = -1;
    this->m_iUserImage = -1;
    v23 = pImages;
    this->m_bDisableFill = cy;
    this->m_bImage = bImage;
    if ( this->m_bLocalUserButton != 0 )
      v23 = CMFCToolBar::m_pUserImages;
    CMFCToolBarImages::EndDrawImage(this: v23, ds: &v34);
    this->m_bInternalDraw = 0;
  }
  else
  {
    v21 = v37;
  }
  v24 = v21->right - nHalfArrowSize;
  v25 = (this->m_nStyle & 0x20000) != 0;
  triang[0].x = v21->right - nActualArrowSize + v25 - 1;
  v26 = v21->bottom - nActualArrowSize;
  v27 = v21->bottom - nHalfArrowSize + v25 + 1;
  triang[1].x = v24 + v25 + 1;
  triang[2].x = triang[1].x;
  triang[2].y = v26 + v25 - 1;
  v28 = v42->__vftable;
  triang[0].y = v27;
  triang[1].y = v27;
  bImage = (int)v28->SelectStockObject(this: v42, a2: 8);
  if ( bImage == 0
    || (result.cy = (int)CDC::SelectObject(this: v42, pFont: (CFont *)&afxGlobalData.brBlack), result.cy == 0) )
  {
    AfxThrowInvalidArgException();
  }
  Polygon(hdc: v42->m_hDC, apt: &triang[0], cpt: 3);
  if ( bCustomizeMode == 0 && this->HaveHotBorder(this) != 0 && bDrawBorder != 0 )
  {
    if ( this->m_pPopupMenu != nullptr || ((m_nStyle = this->m_nStyle) & 0x30000) != 0 )
    {
      m_nID = this->m_nID;
      if ( m_nID != 0 )
      {
        v30 = m_nID == -1;
LABEL_47:
        if ( !v30 )
        {
          Instance = CMFCVisualManager::GetInstance();
          ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCDropDownToolbarButton *, int, int, int, int, int))Instance->OnDrawButtonBorder)(
            a1: Instance,
            a2: v42,
            a3: this,
            a4: v21->left,
            a5: v21->top,
            a6: v21->right,
            a7: v21->bottom,
            a8: 1);
          goto LABEL_52;
        }
      }
      v33 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCDropDownToolbarButton *, int, int, int, int, int))v33->OnDrawButtonBorder)(
        a1: v33,
        a2: v42,
        a3: this,
        a4: v21->left,
        a5: v21->top,
        a6: v21->right,
        a7: v21->bottom,
        a8: 2);
      goto LABEL_52;
    }
    if ( bHighlight != 0 && (m_nStyle & 0x150000) == 0 )
    {
      v30 = (m_nStyle & 0x20000) == 0;
      goto LABEL_47;
    }
  }
LABEL_52:
  CDC::SelectObject(this: v42, pFont: (CFont *)bImage);
  CDC::SelectObject(this: v42, pFont: (CFont *)result.cy);
}

//------------------------------------------------------------------------------
// Address: 0x103E5C65
// Name: public: virtual int CMFCDropDownToolbarButton::OnClickUp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolbarButton::OnClickUp(CMFCDropDownToolbarButton *this)
{
  CObject *v2; // eax
  UINT_PTR m_uiTimer; // ecx
  CMFCToolBar *v4; // ebx
  CWnd *m_pWndParent; // eax
  CMFCDropDownFrame *m_pPopupMenu; // eax

  v2 = AfxDynamicDownCast(pClass: &CMFCMenuBar::classCMFCMenuBar, pObject: this->m_pWndParent);
  m_uiTimer = this->m_uiTimer;
  v4 = (CMFCToolBar *)v2;
  if ( m_uiTimer != 0 )
  {
    m_pWndParent = this->m_pWndParent;
    if ( m_pWndParent != nullptr )
      KillTimer(hWnd: m_pWndParent->m_hWnd, uIDEvent: m_uiTimer);
    this->m_uiTimer = 0;
    g_pButtonDown = nullptr;
    return 0;
  }
  else
  {
    m_pPopupMenu = this->m_pPopupMenu;
    if ( m_pPopupMenu != nullptr )
    {
      m_pPopupMenu->m_bAutoDestroyParent = 0;
      this->m_pPopupMenu->DestroyWindow(this: this->m_pPopupMenu);
      this->m_pPopupMenu = nullptr;
      if ( v4 != nullptr )
        CMFCToolBar::SetHot(this: v4, pMenuButton: nullptr);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E5CCF
// Name: public: virtual void CMFCDropDownToolbarButton::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolbarButton::OnCancelMode(CMFCDropDownToolbarButton *this)
{
  CWnd *m_pWndParent; // eax

  m_pWndParent = this->m_pWndParent;
  if ( m_pWndParent != nullptr && IsWindow(hWnd: m_pWndParent->m_hWnd) )
  {
    InvalidateRect(hWnd: this->m_pWndParent->m_hWnd, lpRect: &this->m_rect, bErase: true);
    UpdateWindow(hWnd: this->m_pWndParent->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E5D08
// Name: public: virtual int CMFCDropDownToolbarButton::OnCustomizeMenu(class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolbarButton::OnCustomizeMenu(CMFCDropDownToolbarButton *this, CMenu *pPopup)
{
  EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4212u, uEnable: 1u);
  EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4213u, uEnable: 1u);
  EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4214u, uEnable: 1u);
  EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4211u, uEnable: 1u);
  EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x420Fu, uEnable: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103E5D5C
// Name: public: virtual int CMFCDropDownToolBar::OnSendCommand(class CMFCToolBarButton const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolBar::OnSendCommand(CMFCDropDownToolBar *this, const CMFCToolBarButton *pButton)
{
  unsigned int m_nID; // eax
  HWND Parent; // eax
  CWnd *v5; // eax
  CFrameWnd *ParentFrame; // eax
  WPARAM v7; // esi
  CFrameWnd *v8; // edi
  CWnd *Owner; // eax

  if ( (pButton->m_nStyle & 0x40000) != 0 )
    return 0;
  m_nID = pButton->m_nID;
  if ( m_nID == 0 || m_nID == -1 )
    return 0;
  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  CMFCDropDownToolbarButton::SetDefaultCommand(
    this: (CMFCDropDownToolbarButton *)v5[2].m_ptGestureFrom.x,
    uiCmd: pButton->m_nID);
  ParentFrame = CWnd::GetParentFrame(this);
  v7 = pButton->m_nID;
  v8 = ParentFrame;
  Owner = CWnd::GetOwner(this);
  PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: v7, lParam: 0);
  v8->DestroyWindow(this: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103E5DD4
// Name: public: void CMFCDropDownToolBar::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolBar::OnMouseMove(CMFCDropDownToolBar *this, unsigned int __formal, CPoint point)
{
  CMFCDropDownToolBar_vtbl *v4; // edx
  int m_iHighlighted; // ebx
  int v6; // eax
  CMFCToolBarButton *Button; // eax
  unsigned int m_nStyle; // eax
  HWND__ *m_hWnd; // eax
  int v10; // eax
  CMFCToolBarButton *v11; // eax
  unsigned int v12; // ecx
  CMFCToolBarButton *v13; // eax
  unsigned int v14; // edx
  int m_iButtonCapture; // ecx
  unsigned int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  CWnd *Owner; // eax
  tagTRACKMOUSEEVENT trackmouseevent; // [esp+8h] [ebp-18h] BYREF
  CMFCToolBarButton *pButton; // [esp+18h] [ebp-8h]
  int bNeedUpdate; // [esp+1Ch] [ebp-4h]

  if ( CPoint::operator!=(this: &this->m_ptLastMouse, point: (tagPOINT)-1LL)
    && abs(lnumber: this->m_ptLastMouse.x - point.x) < 1
    && abs(lnumber: this->m_ptLastMouse.y - point.y) < 1 )
  {
    this->m_ptLastMouse = point;
    return;
  }
  v4 = this->__vftable;
  m_iHighlighted = this->m_iHighlighted;
  this->m_ptLastMouse = point;
  v6 = ((int (__thiscall *)(CMFCDropDownToolBar *, int, int))v4->HitTest)(a1: this, a2: point.x, a3: point.y);
  this->m_iHighlighted = v6;
  if ( v6 == -1 )
  {
    pButton = nullptr;
  }
  else
  {
    Button = CMFCToolBar::GetButton(this, nIndex: v6);
    pButton = Button;
    if ( Button != nullptr )
    {
      m_nStyle = Button->m_nStyle;
      if ( (m_nStyle & 1) != 0 || (m_nStyle & 0x40000) != 0 && this->AllowSelectDisabled(this) == 0 )
        this->m_iHighlighted = -1;
    }
  }
  if ( this->m_bTracked == 0 )
  {
    m_hWnd = this->m_hWnd;
    trackmouseevent.dwHoverTime = -1;
    trackmouseevent.hwndTrack = m_hWnd;
    this->m_bTracked = 1;
    trackmouseevent.cbSize = 16;
    trackmouseevent.dwFlags = 2;
    AFXTrackMouse(ptme: &trackmouseevent);
  }
  v10 = this->m_iHighlighted;
  if ( m_iHighlighted != v10 )
  {
    bNeedUpdate = 0;
    this->m_iButtonCapture = v10;
    if ( m_iHighlighted != -1 )
    {
      v11 = CMFCToolBar::GetButton(this, nIndex: m_iHighlighted);
      if ( v11 == nullptr )
        goto LABEL_17;
      v12 = v11->m_nStyle;
      if ( (v12 & 0xFFFDFFFF) != v12 )
        this->SetButtonStyle(this, a2: m_iHighlighted, a3: v12 & 0xFFFDFFFF);
    }
    if ( this->m_iButtonCapture != -1 )
    {
      v13 = CMFCToolBar::GetButton(this, nIndex: this->m_iButtonCapture);
      if ( v13 == nullptr )
        goto LABEL_17;
      v14 = v13->m_nStyle;
      m_iButtonCapture = this->m_iButtonCapture;
      v16 = v14 & 0xFFFDFFFF;
      if ( this->m_iHighlighted == m_iButtonCapture )
        v16 |= 0x20000u;
      if ( v16 != v14 )
      {
        this->SetButtonStyle(this, a2: m_iButtonCapture, a3: v16);
        bNeedUpdate = 1;
      }
    }
    v17 = this->m_iButtonCapture;
    if ( (v17 == -1 || m_iHighlighted == v17) && m_iHighlighted != -1 )
    {
      CMFCToolBar::InvalidateButton(this, nIndex: m_iHighlighted);
      bNeedUpdate = 1;
    }
    v18 = this->m_iButtonCapture;
    if ( (v18 == -1 || this->m_iHighlighted == v18) && this->m_iHighlighted != -1 )
    {
      CMFCToolBar::InvalidateButton(this, nIndex: this->m_iHighlighted);
      bNeedUpdate = 1;
    }
    if ( bNeedUpdate != 0 )
      UpdateWindow(hWnd: this->m_hWnd);
    v19 = this->m_iHighlighted;
    if ( v19 == -1 || (v20 = this->m_iButtonCapture, v19 != v20) && v20 != -1 )
    {
      if ( this->m_iButtonCapture == -1 && CMFCToolBar::m_hookMouseHelp == nullptr )
      {
        Owner = CWnd::GetOwner(this);
        SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
      }
      goto LABEL_44;
    }
    if ( pButton != nullptr )
    {
      this->ShowCommandMessageString(this, a2: pButton->m_nID);
LABEL_44:
      this->OnChangeHot(this, a2: this->m_iHighlighted);
      return;
    }
LABEL_17:
    AfxThrowInvalidArgException();
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E603E
// Name: protected: int CMFCDropDownFrame::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownFrame::OnCreate(CMFCDropDownFrame *this, tagCREATESTRUCTA *lpCreateStruct)
{
  CMFCDropDownToolbarButton *m_pParentBtn; // eax
  CObject *v5; // eax
  int v6; // eax
  CMFCDropDownToolBar *m_pWndOriginToolbar; // ecx
  CMFCDropDownToolBar *v8; // ecx
  int cy; // eax
  CWnd *Owner; // eax
  HWND__ *m_hWnd; // eax
  CMFCDropDownToolBar *v12; // eax
  HWND v13; // eax

  if ( CFrameWnd::OnCreate(this, lpcs: lpCreateStruct) == -1 )
    return -1;
  m_pParentBtn = this->m_pParentBtn;
  if ( m_pParentBtn != nullptr
    && (v5 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: m_pParentBtn->m_pWndParent)) != nullptr )
  {
    v6 = ((int (__thiscall *)(CObject *))v5->__vftable[29].dtr_CObject)(a1: v5);
  }
  else
  {
    v6 = 1;
  }
  if ( ((int (__stdcall *)(CMFCDropDownFrame *, int, int, int, int, int, int, int))this->m_wndToolBar.CreateEx)(
         a1: this,
         a2: 2048,
         a3: (v6 != 0 ? 20480 : 40960) | 0x50000000,
         a4: 1,
         a5: 1,
         a6: 1,
         a7: 1,
         a8: 59431) == 0 )
    return -1;
  m_pWndOriginToolbar = this->m_pWndOriginToolbar;
  this->m_wndToolBar.m_bLocked = 1;
  CMFCToolBarImages::CopyTemp(
    this: &m_pWndOriginToolbar->m_ImagesLocked,
    imagesDest: &this->m_wndToolBar.m_ImagesLocked);
  CMFCToolBarImages::CopyTemp(
    this: &this->m_pWndOriginToolbar->m_ColdImagesLocked,
    imagesDest: &this->m_wndToolBar.m_ColdImagesLocked);
  CMFCToolBarImages::CopyTemp(
    this: &this->m_pWndOriginToolbar->m_DisabledImagesLocked,
    imagesDest: &this->m_wndToolBar.m_DisabledImagesLocked);
  CMFCToolBarImages::CopyTemp(
    this: &this->m_pWndOriginToolbar->m_LargeImagesLocked,
    imagesDest: &this->m_wndToolBar.m_LargeImagesLocked);
  CMFCToolBarImages::CopyTemp(
    this: &this->m_pWndOriginToolbar->m_LargeColdImagesLocked,
    imagesDest: &this->m_wndToolBar.m_LargeColdImagesLocked);
  CMFCToolBarImages::CopyTemp(
    this: &this->m_pWndOriginToolbar->m_LargeDisabledImagesLocked,
    imagesDest: &this->m_wndToolBar.m_LargeDisabledImagesLocked);
  v8 = this->m_pWndOriginToolbar;
  this->m_wndToolBar.m_sizeButtonLocked.cx = v8->m_sizeButtonLocked.cx;
  this->m_wndToolBar.m_sizeButtonLocked.cy = v8->m_sizeButtonLocked.cy;
  this->m_wndToolBar.m_sizeImageLocked.cx = v8->m_sizeImageLocked.cx;
  this->m_wndToolBar.m_sizeImageLocked.cy = v8->m_sizeImageLocked.cy;
  this->m_wndToolBar.m_sizeCurButtonLocked.cx = v8->m_sizeCurButtonLocked.cx;
  this->m_wndToolBar.m_sizeCurButtonLocked.cy = v8->m_sizeCurButtonLocked.cy;
  this->m_wndToolBar.m_sizeCurImageLocked.cx = v8->m_sizeCurImageLocked.cx;
  cy = v8->m_sizeCurImageLocked.cy;
  this->m_wndToolBar.m_dwStyle &= ~0x400000u;
  this->m_wndToolBar.m_sizeCurImageLocked.cy = cy;
  Owner = CWnd::GetOwner(this: v8);
  if ( Owner != nullptr )
    m_hWnd = Owner->m_hWnd;
  else
    m_hWnd = nullptr;
  this->m_wndToolBar.m_hWndOwner = m_hWnd;
  v12 = this->m_pWndOriginToolbar;
  this->m_wndToolBar.m_bRouteCommandsViaFrame = v12->m_bRouteCommandsViaFrame;
  CObList::AddTail(this: &this->m_wndToolBar.m_Buttons, pNewList: &v12->m_Buttons);
  this->RecalcLayout(this, a2: 1);
  ReleaseCapture();
  v13 = SetCapture(hWnd: this->m_wndToolBar.m_hWnd);
  CWnd::FromHandle(hWnd: v13);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E624C
// Name: public: virtual void CMFCDropDownToolbarButton::OnChangeParentWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolbarButton::OnChangeParentWnd(CMFCDropDownToolbarButton *this, CWnd *pWndParent)
{
  CMFCToolBarButton::OnChangeParentWnd(this, pWndParent);
  this->m_bText = 0;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strText);
  this->m_bUserButton = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E6271
// Name: public: CMFCDropDownFrame::CMFCDropDownFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCDropDownFrame *__thiscall CMFCDropDownFrame::CMFCDropDownFrame(CMFCDropDownFrame *this)
{
  CAfxStringMgr *StringManager; // eax

  CMiniFrameWnd::CMiniFrameWnd(this);
  this->__vftable = (CMFCDropDownFrame_vtbl *)&CMFCDropDownFrame::`vftable';
  CMFCDropDownToolBar::CMFCDropDownToolBar(this: &this->m_wndToolBar);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCaption, pStringMgr: StringManager);
  this->m_bAutoDestroyParent = 1;
  this->m_bAutoDestroy = 1;
  this->m_y = 0;
  this->m_x = 0;
  this->m_pParentBtn = nullptr;
  this->m_pWndOriginToolbar = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103E62DD
// Name: public: virtual CMFCDropDownFrame::~CMFCDropDownFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownFrame::~CMFCDropDownFrame(CMFCDropDownFrame *this)
{
  this->__vftable = (CMFCDropDownFrame_vtbl *)&CMFCDropDownFrame::`vftable';
  CObList::RemoveAll(this: &this->m_wndToolBar.m_Buttons);
  if ( this->m_bAutoDestroy != 0 )
    this->m_wndToolBar.DestroyWindow(this: &this->m_wndToolBar);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCaption.m_pszData - 1);
  this->m_wndToolBar.__vftable = (CMFCDropDownToolBar_vtbl *)&CMFCDropDownToolBar::`vftable';
  CMFCToolBar::~CMFCToolBar(this: &this->m_wndToolBar);
  CMiniFrameWnd::~CMiniFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103E634E
// Name: public: CMFCDropDownToolbarButton::CMFCDropDownToolbarButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCDropDownToolbarButton *__thiscall CMFCDropDownToolbarButton::CMFCDropDownToolbarButton(
        CMFCDropDownToolbarButton *this)
{
  CAfxStringMgr *StringManager; // eax

  CMFCToolBarButton::CMFCToolBarButton(this);
  this->__vftable = (CMFCDropDownToolbarButton_vtbl *)&CMFCDropDownToolbarButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strName, pStringMgr: StringManager);
  this->m_pToolBar = nullptr;
  this->m_pPopupMenu = nullptr;
  this->m_pWndParent = nullptr;
  this->m_uiTimer = 0;
  this->m_iSelectedImage = 0;
  this->m_bInternalDraw = 0;
  this->m_bLocalUserButton = 0;
  this->m_bLocked = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103E6397
// Name: public: virtual int CMFCToolBarMenuButton::OnContextHelp(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarMenuButton::OnContextHelp(CMFCDropDownToolbarButton *this, CWnd *pWnd)
{
  return this->OnClick(this, a2: pWnd, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103E63AA
// Name: public: virtual int CMFCDropDownToolbarButton::IsExtraSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCDropDownToolbarButton::IsExtraSize(CMFCDropDownToolbarButton *this)
{
  BOOL result; // eax

  result = false;
  if ( this->m_bExtraSize != 0 )
    return this->m_bInternalDraw == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E63BB
// Name: public: virtual CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton(CMFCDropDownToolbarButton *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strName.m_pszData - 16);
  this->__vftable = (CMFCDropDownToolbarButton_vtbl *)&CMFCDropDownToolbarButton::`vftable';
  ATL::CStringData::Release(this: v2);
  CMFCToolBarButton::~CMFCToolBarButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103E63D9
// Name: public: int CMFCDropDownToolbarButton::DropDownToolbar(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolbarButton::DropDownToolbar(CMFCDropDownToolbarButton *this, CWnd *pWnd)
{
  CWnd *m_pWndParent; // edi
  CObject *v5; // eax
  int bottom; // ecx
  int v7; // eax
  CMFCDropDownFrame *v8; // ecx
  CMFCDropDownFrame *v9; // eax
  CWnd *v10; // [esp-4h] [ebp-28h]
  CPoint point; // [esp+10h] [ebp-14h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  if ( this->m_pToolBar == nullptr )
    return 0;
  if ( this->m_pPopupMenu != nullptr )
    return 0;
  m_pWndParent = pWnd;
  if ( pWnd == nullptr )
  {
    m_pWndParent = this->m_pWndParent;
    if ( m_pWndParent == nullptr )
      return 0;
  }
  v10 = this->m_pWndParent;
  point.x = 0;
  point.y = 0;
  v5 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v10);
  if ( v5 == nullptr || ((int (__thiscall *)(CObject *))v5->__vftable[29].dtr_CObject)(a1: v5) != 0 )
  {
    bottom = this->m_rect.bottom;
    v7 = this->m_rect.left - 1;
  }
  else
  {
    bottom = this->m_rect.top;
    v7 = this->m_rect.right + 1;
  }
  point.x = v7;
  point.y = bottom;
  ClientToScreen(hWnd: m_pWndParent->m_hWnd, lpPoint: &point);
  v8 = (CMFCDropDownFrame *)operator new(nSize: 0xE04u);
  v12 = 0;
  if ( v8 != nullptr )
    v9 = CMFCDropDownFrame::CMFCDropDownFrame(this: v8);
  else
    v9 = nullptr;
  v12 = -1;
  this->m_pPopupMenu = v9;
  v9->m_pParentBtn = this;
  return this->m_pPopupMenu->Create(
           this: this->m_pPopupMenu,
           a2: m_pWndParent,
           a3: point.x,
           a4: point.y,
           a5: this->m_pToolBar);
}

//------------------------------------------------------------------------------
// Address: 0x103E649C
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCDropDownToolBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCDropDownToolBar::GetMessageMap(CMFCDropDownToolBar *this)
{
  return (const AFX_MSGMAP *)&off_1068733C;
}

//------------------------------------------------------------------------------
// Address: 0x103E64A2
// Name: public: static class CObject __near * CMFCDropDownFrame::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCDropDownFrame *__stdcall CMFCDropDownFrame::CreateObject()
{
  CMFCDropDownFrame *v0; // ecx
  CMFCDropDownFrame *result; // eax

  v0 = (CMFCDropDownFrame *)operator new(nSize: 0xE04u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCDropDownFrame::CMFCDropDownFrame(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E64F3
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCDropDownFrame::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCDropDownFrame::GetMessageMap(CMFCDropDownFrame *this)
{
  return (const AFX_MSGMAP *)&off_10687558;
}

//------------------------------------------------------------------------------
// Address: 0x103E64F9
// Name: public: static class CObject __near * CMFCDropDownToolbarButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCDropDownToolbarButton *__stdcall CMFCDropDownToolbarButton::CreateObject()
{
  CMFCDropDownToolbarButton *v0; // ecx
  CMFCDropDownToolbarButton *result; // eax

  v0 = (CMFCDropDownToolbarButton *)operator new(nSize: 0x8Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCDropDownToolbarButton::CMFCDropDownToolbarButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E654A
// Name: public: virtual int CMFCDropDownToolbarButton::OnClick(class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolbarButton::OnClick(CMFCDropDownToolbarButton *this, CWnd *pWnd, int bDelay)
{
  UINT_PTR m_uiTimer; // ecx
  CWnd *m_pWndParent; // eax
  CMFCToolBar *v6; // ebx
  CMFCDropDownFrame *m_pPopupMenu; // eax
  CObject *v8; // eax
  CWnd *v9; // eax
  CWnd *v11; // [esp-8h] [ebp-10h]

  m_uiTimer = this->m_uiTimer;
  m_pWndParent = this->m_pWndParent;
  if ( m_uiTimer != 0 )
  {
    if ( m_pWndParent != nullptr )
      KillTimer(hWnd: m_pWndParent->m_hWnd, uIDEvent: m_uiTimer);
    v11 = this->m_pWndParent;
    this->m_uiTimer = 0;
    g_pButtonDown = nullptr;
    v6 = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCMenuBar::classCMFCMenuBar, pObject: v11);
    m_pPopupMenu = this->m_pPopupMenu;
    if ( m_pPopupMenu != nullptr )
    {
      m_pPopupMenu->m_bAutoDestroyParent = 0;
      this->m_pPopupMenu->DestroyWindow(this: this->m_pPopupMenu);
      this->m_pPopupMenu = nullptr;
      if ( v6 != nullptr )
        CMFCToolBar::SetHot(this: v6, pMenuButton: nullptr);
    }
    else
    {
      v8 = AfxDynamicDownCast(pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar, pObject: this->m_pWndParent);
      if ( bDelay == 0 || v8 == nullptr || CMFCToolBar::m_bCustomizeMode != 0 )
        CMFCDropDownToolbarButton::DropDownToolbar(this, pWnd);
      if ( v6 != nullptr )
        CMFCToolBar::SetHot(this: v6, pMenuButton: this);
    }
    v9 = this->m_pWndParent;
    if ( v9 != nullptr )
      InvalidateRect(hWnd: v9->m_hWnd, lpRect: &this->m_rect, bErase: true);
  }
  else
  {
    if ( m_pWndParent != nullptr )
      this->m_uiTimer = SetTimer(
                          hWnd: m_pWndParent->m_hWnd,
                          nIDEvent: 1u,
                          uElapse: CMFCDropDownToolbarButton::m_uiShowBarDelay,
                          lpTimerFunc: TimerProc);
    g_pButtonDown = this;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E6624
// Name: public: virtual void CMFCDropDownToolbarButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDropDownToolbarButton::CopyFrom(CMFCDropDownToolbarButton *this, const CMFCToolBarButton *s)
{
  int m_bWrap; // eax

  CMFCToolBarButton::CopyFrom(this, src: s);
  this->m_pToolBar = (CMFCDropDownToolBar *)s[1].__vftable;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strName, strSrc: (ATL::CStringData *)&s[1].m_bUserButton);
  m_bWrap = s[1].m_bWrap;
  this->m_bDragFromCollection = 0;
  this->m_iSelectedImage = m_bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x103E665E
// Name: public: virtual int CMFCDropDownToolbarButton::ExportToMenuButton(class CMFCToolBarMenuButton __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolbarButton::ExportToMenuButton(
        CMFCDropDownToolbarButton *this,
        CMFCToolBarMenuButton *menuButton)
{
  CMFCDropDownToolbarButton *v2; // ebx
  CMFCToolBarMenuButton *v4; // edi
  HMENU PopupMenu; // eax
  __POSITION *m_pNodeHead; // eax
  CMFCToolBarMenuButton_vtbl *v7; // eax
  int v8; // esi
  int v9; // eax
  ATL::CStringData *v10; // eax
  char *m_pszData; // ebx
  bool v12; // zf
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int v15; // eax
  ATL::CStringData *v16; // eax
  HMENU__ *m_hMenu; // [esp-4h] [ebp-3Ch]
  unsigned int v18; // [esp-4h] [ebp-3Ch]
  CMenu menu; // [esp+10h] [ebp-28h] BYREF
  CMFCDropDownToolbarButton *v20; // [esp+18h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v21; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int nID; // [esp+20h] [ebp-18h]
  __POSITION *pos; // [esp+24h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strItem; // [esp+28h] [ebp-10h] BYREF
  int v25; // [esp+34h] [ebp-4h]

  v2 = this;
  v20 = this;
  if ( this->m_pToolBar == nullptr )
    return 0;
  v4 = menuButton;
  if ( CMFCToolBarButton::ExportToMenuButton(this, menuButton) == 0 )
    return 0;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  menu.m_hMenu = nullptr;
  v25 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  m_pNodeHead = (__POSITION *)v2->m_pToolBar->m_Buttons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)&m_pNodeHead[8];
      pos = *(__POSITION **)m_pNodeHead;
      if ( v8 == 0 )
        AfxThrowInvalidArgException();
      if ( (*(_BYTE *)(v8 + 36) & 1) != 0 )
      {
        AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
      }
      else
      {
        v9 = *(_DWORD *)(v8 + 32);
        if ( v9 != 0 && v9 != -1 )
        {
          v10 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)(*(_DWORD *)(v8 + 44) - 16));
          m_pszData = (char *)&v10[1];
          strItem.m_pszData = (char *)&v10[1];
          v12 = v10->nDataLength == 0;
          LOBYTE(v25) = 1;
          if ( v12 )
          {
            StringManager = AfxGetStringManager();
            ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
              this: (ATL::CSimpleStringT<char,0> *)&menuButton,
              pStringMgr: StringManager);
            v18 = *(_DWORD *)(v8 + 32);
            LOBYTE(v25) = 2;
            nID = v18;
            StringResourceHandle = AfxFindStringResourceHandle(__formal: v18);
            if ( StringResourceHandle != nullptr
              && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                   this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&menuButton,
                   hInstance: StringResourceHandle,
                   nID) != 0 )
            {
              v15 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&menuButton,
                      ch: 0xAu,
                      iStart: 0);
              if ( v15 != -1 )
              {
                v16 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&menuButton,
                                            result: &v21,
                                            iFirst: v15 + 1);
                LOBYTE(v25) = 3;
                ATL::CSimpleStringT<char,0>::operator=(this: &strItem, strSrc: v16);
                ATL::CStringData::Release(this: (ATL::CStringData *)v21.m_pszData - 1);
                m_pszData = strItem.m_pszData;
              }
            }
            ATL::CStringData::Release(this: (ATL::CStringData *)&menuButton[-1].m_rectButton);
          }
          AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: *(_DWORD *)(v8 + 32), lpNewItem: m_pszData);
          LOBYTE(v25) = 0;
          ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
          v2 = v20;
        }
      }
      if ( pos == nullptr )
        break;
      m_pNodeHead = pos;
    }
  }
  v4->m_nID = 0;
  ATL::CSimpleStringT<char,0>::operator=(this: &v4->m_strText, strSrc: (ATL::CStringData *)&v2->m_strName);
  v4->SetImage(this: v4, a2: -1);
  m_hMenu = menu.m_hMenu;
  v7 = v4->__vftable;
  v4->m_bImage = 0;
  v7->CreateFromMenu(this: v4, a2: m_hMenu);
  CMenu::DestroyMenu(this: &menu);
  v25 = -1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103E6821
// Name: public: virtual int CMFCDropDownToolbarButton::OnDrawOnCustomizeList(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolbarButton::OnDrawOnCustomizeList(
        CMFCDropDownToolbarButton *this,
        CDC *pDC,
        const CRect *rect,
        int bSelected)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strText; // edi
  char *v6; // ebx
  int v7; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  p_m_strText = &this->m_strText;
  v6 = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strText.m_pszData - 1)[1];
  strText.m_pszData = v6;
  v10 = 0;
  ATL::CSimpleStringT<char,0>::operator=(this: p_m_strText, strSrc: (ATL::CStringData *)&this->m_strName);
  v7 = CMFCToolBarButton::OnDrawOnCustomizeList(this, pDC, rect, bSelected);
  ATL::CSimpleStringT<char,0>::operator=(this: p_m_strText, strSrc: (ATL::CStringData *)&strText);
  ATL::CStringData::Release(this: (ATL::CStringData *)v6 - 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x103E6882
// Name: public: virtual int CMFCDropDownFrame::Create(class CWnd __near *,int,int,class CMFCDropDownToolBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownFrame::Create(
        CMFCDropDownFrame *this,
        CWnd *pWndParent,
        int x,
        int y,
        CMFCDropDownToolBar *pWndOriginToolbar)
{
  HCURSOR CursorA; // eax
  const char *v7; // eax
  int v8; // eax
  CWnd *Owner; // eax
  int result; // eax
  CRect rect; // [esp+Ch] [ebp-24h] BYREF
  CRect rectParent; // [esp+1Ch] [ebp-14h] BYREF

  if ( pWndParent == nullptr )
    AfxThrowInvalidArgException();
  AFXPlaySystemSound(nSound: 2);
  if ( *((_DWORD *)CMFCDropDownFrame::m_strClassName.m_pszData - 3) == 0 )
  {
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    v7 = AfxRegisterWndClass(nClassStyle: 0x800u, hCursor: CursorA, hbrBackground: (HBRUSH__ *)0x10, hIcon: nullptr);
    ATL::CSimpleStringT<char,0>::SetString(this: &CMFCDropDownFrame::m_strClassName, pszSrc: v7);
  }
  this->m_pWndOriginToolbar = pWndOriginToolbar;
  v8 = y;
  if ( x == -1 && y == -1 )
  {
    memset(&rectParent, 0, sizeof(rectParent));
    GetClientRect(hWnd: pWndParent->m_hWnd, lpRect: &rectParent);
    CWnd::ClientToScreen(this: pWndParent, lpRect: &rectParent);
    this->m_x = rectParent.left + 5;
    this->m_y = rectParent.top + 5;
    v8 = -1;
  }
  else
  {
    this->m_x = x;
    this->m_y = y;
  }
  rect.left = x;
  rect.top = v8;
  rect.right = x;
  rect.bottom = v8;
  if ( CWnd::GetOwner(this: pWndParent) != nullptr )
    Owner = CWnd::GetOwner(this: pWndParent);
  else
    Owner = pWndParent;
  result = CMiniFrameWnd::CreateEx(
             this,
             dwExStyle: 0,
             lpClassName: CMFCDropDownFrame::m_strClassName.m_pszData,
             lpszWindowName: this->m_strCaption.m_pszData,
             dwStyle: 0x80000000,
             &rect,
             pParentWnd: Owner,
             nID: 0);
  if ( result != 0 )
  {
    CWnd::ShowWindow(this, nCmdShow: 4);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F3DFE
// Name: public: virtual CMFCImageEditorDialog::~CMFCImageEditorDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImageEditorDialog::~CMFCImageEditorDialog(CMFCImageEditorDialog *this)
{
  CMFCToolBar::~CMFCToolBar(this: &this->m_wndPaletteBar);
  CMFCColorBar::~CMFCColorBar(this: &this->m_wndColorBar);
  CMFCImagePaintArea::~CMFCImagePaintArea(this: &this->m_wndLargeDrawArea);
  CStatic::~CStatic(this: &this->m_wndPreview);
  CStatic::~CStatic(this: &this->m_wndPaletteBarLocation);
  CStatic::~CStatic(this: &this->m_wndColorPickerLocation);
  CDialogEx::~CDialogEx(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F3E9E
// Name: public: virtual int CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage(class CWnd __near *,class CBitmap __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage(
        CMFCToolBarsCustomizeDialog *this,
        CWnd *pWndParent,
        CBitmap *bitmap,
        int nBitsPerPixel)
{
  int v4; // esi
  CMFCImageEditorDialog v6; // [esp+8h] [ebp-1DF8h] BYREF
  int v7; // [esp+1DFCh] [ebp-4h]

  CMFCImageEditorDialog::CMFCImageEditorDialog(
    this: &v6,
    pBitmap: bitmap,
    pParent: pWndParent,
    nBitsPixel: nBitsPerPixel);
  v7 = 0;
  v4 = -(CDialog::DoModal(this: &v6) != 1);
  v7 = -1;
  CMFCImageEditorDialog::~CMFCImageEditorDialog(this: &v6);
  return v4 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10436C97
// Name: protected: virtual int CMFCColorPropertySheet::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPropertySheet::PreTranslateMessage(CMFCColorPropertySheet *this, tagMSG *pMsg)
{
  HACCEL__ *m_hAccel; // eax

  m_hAccel = this->m_hAccel;
  if ( m_hAccel != nullptr && TranslateAcceleratorA(hWnd: this->m_hWnd, hAccTable: m_hAccel, lpMsg: pMsg) != 0 )
    return 1;
  else
    return CPropertySheet::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10436CF5
// Name: protected: void CMFCColorPropertySheet::ResizeControl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPropertySheet::ResizeControl(CMFCColorPropertySheet *this)
{
  int PageCount; // ebx
  int v3; // edi
  CPropertyPage *Page; // eax
  CWnd *v5; // ebx
  HWND v6; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-4Ch]
  int nXBorder; // [esp+8h] [ebp-38h]
  int nYBorder; // [esp+10h] [ebp-30h]
  CTabCtrl *pTabCtrl; // [esp+14h] [ebp-2Ch]
  int nPage; // [esp+18h] [ebp-28h]
  CRect rcTabCtrl; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectClient; // [esp+2Ch] [ebp-14h] BYREF

  pTabCtrl = CPropertySheet::GetTabControl(this);
  if ( pTabCtrl != nullptr )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    CWnd::SetWindowPos(
      this: pTabCtrl,
      pWndInsertAfter: nullptr,
      x: 0,
      y: 0,
      cx: rectClient.right - rectClient.left,
      cy: rectClient.bottom - rectClient.top,
      nFlags: 0x14u);
    PageCount = CPropertySheet::GetPageCount(this);
    nXBorder = GetSystemMetrics(nIndex: 45);
    v3 = PageCount - 1;
    nYBorder = GetSystemMetrics(nIndex: 46);
    for ( nPage = 0; nPage <= v3; ++nPage )
    {
      Page = CPropertySheet::GetPage(this, nPage);
      v5 = Page;
      if ( Page != nullptr )
      {
        v6 = Page->m_hWnd;
        if ( v6 != nullptr )
        {
          memset(&rcTabCtrl, 0, sizeof(rcTabCtrl));
          GetWindowRect(hWnd: v6, lpRect: &rcTabCtrl);
          CWnd::ScreenToClient(this: pTabCtrl, lpRect: &rcTabCtrl);
          CWnd::SetWindowPos(
            this: v5,
            pWndInsertAfter: nullptr,
            x: rcTabCtrl.left,
            y: rcTabCtrl.top,
            cx: rectClient.right - 3 * nXBorder - rectClient.left,
            cy: rectClient.bottom - rectClient.top - rcTabCtrl.top - nYBorder,
            nFlags: 0x14u);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10436DFA
// Name: public: virtual int CMFCColorPropertySheet::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPropertySheet::OnInitDialog(CMFCColorPropertySheet *this)
{
  int inited; // edi

  inited = CPropertySheet::OnInitDialog(this);
  CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: 0x10000u, nFlags: 0);
  CMFCColorPropertySheet::ResizeControl(this);
  return inited;
}

//------------------------------------------------------------------------------
// Address: 0x10436E23
// Name: protected: virtual int CMFCColorPropertySheet::OnNotify(unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPropertySheet::OnNotify(
        CMFCColorPropertySheet *this,
        unsigned int wParam,
        int lParam,
        int *pResult)
{
  if ( lParam == 0 )
    AfxThrowInvalidArgException();
  if ( *(_DWORD *)(lParam + 8) == -551 )
    CMFCColorPropertySheet::ResizeControl(this);
  return CWnd::OnNotify(this, __formal: wParam, lParam, pResult);
}

//------------------------------------------------------------------------------
// Address: 0x10436E5A
// Name: protected: void CMFCColorPropertySheet::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPropertySheet::OnSize(
        CMFCColorPropertySheet *this,
        unsigned int nType,
        unsigned int cx,
        int cy)
{
  CWnd::Default(this);
  CMFCColorPropertySheet::ResizeControl(this);
}

//------------------------------------------------------------------------------
// Address: 0x10436E6F
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCColorPropertySheet::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCColorPropertySheet::GetMessageMap(CMFCColorPropertySheet *this)
{
  return (const AFX_MSGMAP *)&off_106965AC;
}

//------------------------------------------------------------------------------
// Address: 0x104370BB
// Name: TranslatorGuardHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext)
{
  void *pContinue; // [esp+4h] [ebp-4h] BYREF

  if ( (pExcept->ExceptionFlags & 0x66) != 0 )
  {
    pRN[3].pNext = (EHRegistrationNode *)1;
    return ExceptionContinueSearch;
  }
  else
  {
    __InternalCxxFrameHandler(
      pExcept,
      pRN: (EHRegistrationNode *)pRN[1].frameHandler,
      pContext,
      pDC: nullptr,
      pFuncInfo: (const _s_FuncInfo *)pRN[1].pNext,
      CatchDepth: pRN[1].state,
      pMarkerRN: pRN[2].pNext,
      recursive: 1u);
    if ( pRN[3].pNext == nullptr )
      _UnwindNestedFrames(pRN, pExcept);
    _CallSETranslator(
      pExcept: (EHExceptionRecord *)0x123,
      pRN: (EHRegistrationNode *)&pContinue,
      pContext: nullptr,
      pDC: nullptr,
      pFuncInfo: nullptr,
      CatchDepth: 0,
      pMarkerRN: nullptr);
    return ((_EXCEPTION_DISPOSITION (*)(void))pContinue)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x104371CD
// Name: __CreateFrameInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FrameInfo *__cdecl _CreateFrameInfo(FrameInfo *pFrameInfo, void *pExceptionObject)
{
  pFrameInfo->pExceptionObject = pExceptionObject;
  pFrameInfo->pNext = (FrameInfo *)_getptd()->_pFrameInfoChain;
  _getptd()->_pFrameInfoChain = pFrameInfo;
  return pFrameInfo;
}

//------------------------------------------------------------------------------
// Address: 0x104371F9
// Name: __IsExceptionObjectToBeDestroyed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _IsExceptionObjectToBeDestroyed(void *pExceptionObject)
{
  void **i; // eax

  for ( i = (void **)_getptd()->_pFrameInfoChain; ; i = (void **)i[1] )
  {
    if ( i == nullptr )
      return 1;
    if ( *i == pExceptionObject )
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10437220
// Name: __FindAndUnlinkFrame
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _FindAndUnlinkFrame(FrameInfo *pFrameInfo)
{
  _DWORD *i; // eax

  if ( pFrameInfo == _getptd()->_pFrameInfoChain )
  {
    _getptd()->_pFrameInfoChain = pFrameInfo->pNext;
  }
  else
  {
    for ( i = _getptd()->_pFrameInfoChain; ; i = (_DWORD *)i[1] )
    {
      if ( i[1] == 0 )
        _inconsistency();
      if ( pFrameInfo == (FrameInfo *)i[1] )
        break;
    }
    i[1] = pFrameInfo->pNext;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10437272
// Name: void __near * _CallCatchBlock2(struct EHRegistrationNode __near *,struct _s_FuncInfo const __near *,void __near *,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CallCatchBlock2(
        EHRegistrationNode *pRN,
        const _s_FuncInfo *pFuncInfo,
        void *handlerAddress,
        int CatchDepth,
        unsigned int NLGCode)
{
  _CallSettingFrame(funclet: (unsigned int)handlerAddress, (unsigned int)pRN, dwInCode: NLGCode);
}

//------------------------------------------------------------------------------
// Address: 0x10437330
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10437339
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1043734C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp-4h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10437366
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}
