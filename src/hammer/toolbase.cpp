// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolbase.cpp
// Functions: 42
// ============================================================

#include "hammer\toolbase.h"

//------------------------------------------------------------------------------
// Address: 0x10157750
// Name: public: virtual void CBaseTool::Init(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTool::Init(CBaseTool *this, CMapDoc *pDocument)
{
  this->m_bActiveTool = false;
  this->m_pDocument = pDocument;
}

//------------------------------------------------------------------------------
// Address: 0x10157770
// Name: public: void CBaseTool::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTool::Activate(CBaseTool *this)
{
  this->OnActivate(this);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  this->m_bActiveTool = true;
}

//------------------------------------------------------------------------------
// Address: 0x10157790
// Name: public: void CBaseTool::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseTool::Deactivate(CBaseTool *this)
{
  CMapDoc *m_pDocument; // ecx

  this->OnDeactivate(this);
  m_pDocument = this->m_pDocument;
  if ( m_pDocument != nullptr )
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
  this->m_bActiveTool = false;
}

//------------------------------------------------------------------------------
// Address: 0x103B0116
// Name: public: virtual void CMFCToolBar::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::Deactivate(CMFCToolBar *this)
{
  int m_iHighlighted; // ecx
  CWnd *Owner; // eax

  m_iHighlighted = this->m_iHighlighted;
  if ( m_iHighlighted >= 0 && m_iHighlighted < this->m_Buttons.m_nCount )
  {
    this->m_iHot = -1;
    this->m_iHighlighted = -1;
    CMFCToolBar::InvalidateButton(this, nIndex: m_iHighlighted);
    UpdateWindow(hWnd: this->m_hWnd);
    Owner = CWnd::GetOwner(this);
    SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
  }
  this->RestoreFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10406E94
// Name: public: void COleClientItem::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COleClientItem::Deactivate(COleClientItem *this)
{
  IUnknown *Interface; // eax
  IUnknown *v3; // edi

  Interface = _AfxQueryInterface(lpUnknown: this->m_lpObject, iid: &IID_IOleInPlaceObject);
  v3 = Interface;
  if ( Interface != nullptr
    && (this->m_scLast = Interface->__vftable[1].Release(this: Interface), v3->Release(this: v3), this->m_scLast >= 0) )
  {
    this->m_nItemState = loadedState;
  }
  else
  {
    COleClientItem::Close(this, dwCloseOption: OLECLOSE_SAVEIFDIRTY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040C4BB
// Name: public: void CMFCPropertyGridToolTipCtrl::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridToolTipCtrl::Deactivate(CMFCPropertyGridToolTipCtrl *this)
{
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strText);
  SetRectEmpty(lprc: &this->m_rectLast);
  CMFCPropertyGridToolTipCtrl::Hide(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B0173
// Name: public: static int CMFCToolBar::IsCommandRarelyUsed(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CMFCToolBar::IsCommandRarelyUsed(HWND__ *uiCmd)
{
  return CMFCToolBar::m_bCustomizeMode == 0
      && uiCmd != nullptr
      && uiCmd != (HWND__ *)-1
      && IsStandardCommand((unsigned int)uiCmd) == 0
      && CMFCToolBar::m_lstBasicCommands.m_nCount != 0
      && uiCmd != (HWND__ *)17020
      && uiCmd != (HWND__ *)17021
      && uiCmd != (HWND__ *)17024
      && !CMFCToolBar::IsBasicCommand(uiCmd)
      && CMFCCmdUsageCount::IsFreqeuntlyUsedCmd(this: &CMFCToolBar::m_UsageCount, (unsigned int)uiCmd) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103B01DC
// Name: public: virtual int CMFCToolBar::OnSetAccData(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnSetAccData(CMFCToolBar *this, unsigned int lVal)
{
  int v3; // ebx
  CMFCToolBarButton *Button; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-18h]
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  pt.y = HIWORD(lVal);
  m_hWnd = this->m_hWnd;
  pt.x = (unsigned __int16)lVal;
  ScreenToClient(hWnd: m_hWnd, lpPoint: &pt);
  v3 = ((int (__thiscall *)(CMFCToolBar *, int, int))this->HitTest)(a1: this, a2: pt.x, a3: pt.y);
  if ( v3 < 0 )
    return 0;
  CAccessibilityData::Clear(this: &this->m_AccData);
  Button = CMFCToolBar::GetButton(this, nIndex: v3);
  if ( Button != nullptr )
    Button->SetACCData(this: Button, a2: this, a3: &this->m_AccData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103B024D
// Name: public: int CMFCToolBarImages::GetResourceOffset(unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::GetResourceOffset(CMFCToolBarImages *this, CDocument *uiResId)
{
  int iOffset; // [esp+0h] [ebp-4h] BYREF

  iOffset = -1;
  if ( CMap<CWnd *,CWnd *,CImageList *,CImageList *>::Lookup(
         this: (CMap<unsigned int,unsigned int,CPane *,CPane *> *)&this->m_mapOrigResOffsets,
         key: uiResId,
         rValue: (CPane **)&iOffset) != 0 )
    return iOffset;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103B0279
// Name: public: virtual int CMFCToolBar::CreateEx(class CWnd __near *,unsigned long,unsigned long,class CRect,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::CreateEx(
        CMFCToolBar *this,
        CWnd *pParentWnd,
        unsigned int dwCtrlStyle,
        unsigned int dwStyle,
        tagRECT rcBorders,
        unsigned int nID)
{
  CMFCToolBar_vtbl *v7; // edx
  char *m_pszData; // eax
  char v9; // bl
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v11; // [esp+14h] [ebp-24h] BYREF
  tagRECT rc; // [esp+18h] [ebp-20h] BYREF
  int v13; // [esp+34h] [ebp-4h]

  if ( rcBorders.left < 1 )
    rcBorders.left = 1;
  if ( rcBorders.top < 1 )
    rcBorders.top = 1;
  CPane::SetBorders(this, lpRect: &rcBorders);
  v7 = this->__vftable;
  this->m_dwStyle = (unsigned __int16)dwStyle | 0x400000;
  v7->SetPaneAlignment(this, a2: (unsigned __int16)dwStyle | 0x400000);
  if ( nID == 59392 )
    this->m_dwStyle |= 8u;
  AfxEndDeferRegisterClass(fToRegister: 16);
  memset(&rc, 0, sizeof(rc));
  SetRectEmpty(lprc: &rc);
  m_pszData = AFX_GLOBAL_DATA::RegisterWindowClass(
                this: &afxGlobalData,
                result: &v11,
                lpszClassNamePrefix: "Afx:ToolBar")->m_pszData;
  v13 = 0;
  v9 = -(CPane::Create(
           this,
           lpszClassName: m_pszData,
           dwStyle: dwCtrlStyle & 0xFFFFFFB1 | 0x4C | dwStyle & 0xFFBF0000,
           rect: &rc,
           pParentWnd,
           nID,
           dwControlBarStyle: 0,
           pContext: nullptr) != 0);
  ATL::CStringData::Release(this: (ATL::CStringData *)v11.m_pszData - 1);
  return v9 == -1;
}

//------------------------------------------------------------------------------
// Address: 0x103B0363
// Name: public: virtual int CMFCToolBar::LoadBitmapEx(class CMFCToolBarInfo __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::LoadBitmapEx(CMFCToolBar *this, CMFCToolBarInfo *params, int bLocked)
{
  unsigned int m_uiDisabledResID; // eax
  unsigned int m_uiLargeHotResID; // eax
  unsigned int m_uiLargeColdResID; // eax
  unsigned int m_uiLargeDisabledResID; // eax
  unsigned int m_uiMenuResID; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int m_uiMenuDisabledResID; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // edi

  this->m_bLocked = bLocked;
  if ( bLocked != 0 )
  {
    if ( CMFCToolBarImages::Load(this: &this->m_ImagesLocked, uiResID: params->m_uiHotResID, hinstRes: nullptr, bAdd: 1) == 0 )
      return false;
    if ( params->m_uiColdResID != 0 )
    {
      if ( CMFCToolBarImages::Load(
             this: &this->m_ColdImagesLocked,
             uiResID: params->m_uiColdResID,
             hinstRes: nullptr,
             bAdd: 1) == 0 )
        return false;
    }
    else if ( CMFCToolBar::m_bAutoGrayInactiveImages != 0 )
    {
      CMFCToolBarImages::CopyTo(this: &this->m_ImagesLocked, dest: &this->m_ColdImagesLocked);
      CMFCToolBarImages::GrayImages(
        this: &this->m_ColdImagesLocked,
        nGrayImageLuminancePercentage: CMFCToolBar::m_nGrayImagePercentage);
    }
    m_uiDisabledResID = params->m_uiDisabledResID;
    if ( m_uiDisabledResID != 0
      && CMFCToolBarImages::Load(
           this: &this->m_DisabledImagesLocked,
           uiResID: m_uiDisabledResID,
           hinstRes: nullptr,
           bAdd: 1) == 0 )
    {
      return false;
    }
    m_uiLargeHotResID = params->m_uiLargeHotResID;
    if ( m_uiLargeHotResID != 0
      && CMFCToolBarImages::Load(
           this: &this->m_LargeImagesLocked,
           uiResID: m_uiLargeHotResID,
           hinstRes: nullptr,
           bAdd: 1) == 0 )
    {
      return false;
    }
    m_uiLargeColdResID = params->m_uiLargeColdResID;
    if ( m_uiLargeColdResID != 0
      && CMFCToolBarImages::Load(
           this: &this->m_LargeColdImagesLocked,
           uiResID: m_uiLargeColdResID,
           hinstRes: nullptr,
           bAdd: 1) == 0 )
    {
      return false;
    }
    m_uiLargeDisabledResID = params->m_uiLargeDisabledResID;
    if ( m_uiLargeDisabledResID != 0
      && CMFCToolBarImages::Load(
           this: &this->m_LargeDisabledImagesLocked,
           uiResID: m_uiLargeDisabledResID,
           hinstRes: nullptr,
           bAdd: 1) == 0 )
    {
      return false;
    }
    m_uiMenuResID = params->m_uiMenuResID;
    if ( m_uiMenuResID != 0
      && CMFCToolBarImages::Load(this: &this->m_MenuImagesLocked, uiResID: m_uiMenuResID, hinstRes: nullptr, bAdd: 1) == 0 )
    {
      return false;
    }
    return params->m_uiMenuDisabledResID == 0
        || CMFCToolBarImages::Load(
             this: &this->m_MenuImagesLocked,
             uiResID: params->m_uiMenuResID,
             hinstRes: nullptr,
             bAdd: 1) != 0;
  }
  else
  {
    if ( CMFCToolBarImages::Load(
           this: &CMFCToolBar::m_Images,
           uiResID: params->m_uiHotResID,
           hinstRes: nullptr,
           bAdd: 1) == 0 )
      return false;
    this->m_iImagesOffset = CMFCToolBarImages::GetResourceOffset(
                              this: &CMFCToolBar::m_Images,
                              uiResId: (CDocument *)params->m_uiHotResID);
    if ( params->m_uiColdResID != 0 )
    {
      if ( CMFCToolBarImages::Load(
             this: &CMFCToolBar::m_ColdImages,
             uiResID: params->m_uiColdResID,
             hinstRes: nullptr,
             bAdd: 1) == 0 )
        return false;
    }
    else if ( CMFCToolBar::m_bAutoGrayInactiveImages != 0 )
    {
      CMFCToolBarImages::CopyTo(this: &CMFCToolBar::m_Images, dest: &CMFCToolBar::m_ColdImages);
      CMFCToolBarImages::GrayImages(
        this: &CMFCToolBar::m_ColdImages,
        nGrayImageLuminancePercentage: CMFCToolBar::m_nGrayImagePercentage);
    }
    v10 = params->m_uiMenuResID;
    if ( v10 != 0
      && CMFCToolBarImages::Load(this: &CMFCToolBar::m_MenuImages, uiResID: v10, hinstRes: nullptr, bAdd: 1) == 0 )
    {
      return false;
    }
    v11 = params->m_uiDisabledResID;
    if ( v11 != 0
      && CMFCToolBarImages::Load(this: &CMFCToolBar::m_DisabledImages, uiResID: v11, hinstRes: nullptr, bAdd: 1) == 0 )
    {
      return false;
    }
    m_uiMenuDisabledResID = params->m_uiMenuDisabledResID;
    if ( m_uiMenuDisabledResID != 0
      && CMFCToolBarImages::Load(
           this: &CMFCToolBar::m_DisabledMenuImages,
           uiResID: m_uiMenuDisabledResID,
           hinstRes: nullptr,
           bAdd: 1) == 0 )
    {
      return false;
    }
    v13 = params->m_uiLargeHotResID;
    if ( v13 != 0
      && CMFCToolBarImages::Load(this: &CMFCToolBar::m_LargeImages, uiResID: v13, hinstRes: nullptr, bAdd: 1) == 0 )
    {
      return false;
    }
    v14 = params->m_uiLargeColdResID;
    if ( v14 != 0
      && CMFCToolBarImages::Load(this: &CMFCToolBar::m_LargeColdImages, uiResID: v14, hinstRes: nullptr, bAdd: 1) == 0 )
    {
      return false;
    }
    v15 = params->m_uiLargeDisabledResID;
    return v15 == 0
        || CMFCToolBarImages::Load(this: &CMFCToolBar::m_LargeDisabledImages, uiResID: v15, hinstRes: nullptr, bAdd: 1) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B05BB
// Name: protected: void CMFCToolBar::OnToolbarAppearance(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarAppearance(CMFCToolBar *this)
{
  CMFCToolBarButton *Button; // eax
  CMFCToolBarButton *v3; // edi
  int v4; // eax
  CMFCToolBarButtonCustomizeDialog v5; // [esp+10h] [ebp-4E0h] BYREF
  int v6; // [esp+4ECh] [ebp-4h]

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  v3 = Button;
  if ( Button != nullptr )
  {
    if ( *((_DWORD *)Button->m_strText.m_pszData - 3) == 0 )
      this->OnSetDefaultButtonText(this, a2: Button);
    v4 = this->IsPureMenuButton(this, a2: v3);
    CMFCToolBarButtonCustomizeDialog::CMFCToolBarButtonCustomizeDialog(
      this: &v5,
      pButton: v3,
      pImages: CMFCToolBar::m_pUserImages,
      pParent: this,
      iStartImage: 0,
      bMenuMode: v4);
    v6 = 0;
    if ( CDialog::DoModal(this: &v5) == 1 )
    {
      this->AdjustLayout(this);
      this->AdjustSizeImmediate(this, a2: 1);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
    }
    v6 = -1;
    CMFCToolBarButtonCustomizeDialog::~CMFCToolBarButtonCustomizeDialog(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0660
// Name: protected: void CMFCToolBar::OnToolbarImageAndText(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarImageAndText(CMFCToolBar *this)
{
  CMFCToolBarButton *Button; // eax
  CMFCToolBarButton *v3; // esi
  bool v4; // zf
  int m_iImage; // eax
  int v6; // eax
  int v7; // eax
  int m_bText; // [esp+10h] [ebp-4E8h]
  int m_bImage; // [esp+14h] [ebp-4E4h]
  CMFCToolBarButtonCustomizeDialog v10; // [esp+18h] [ebp-4E0h] BYREF
  int v11; // [esp+4F4h] [ebp-4h]

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  v3 = Button;
  if ( Button != nullptr )
  {
    v4 = Button->m_bUserButton == 0;
    m_bText = Button->m_bText;
    m_bImage = Button->m_bImage;
    Button->m_bText = 1;
    Button->m_bImage = 1;
    if ( v4 )
      m_iImage = Button->m_iImage;
    else
      m_iImage = Button->m_iUserImage;
    if ( m_iImage < 0 )
    {
      v6 = this->IsPureMenuButton(this, a2: v3);
      CMFCToolBarButtonCustomizeDialog::CMFCToolBarButtonCustomizeDialog(
        this: &v10,
        pButton: v3,
        pImages: CMFCToolBar::m_pUserImages,
        pParent: this,
        iStartImage: 0,
        bMenuMode: v6);
      v11 = 0;
      v7 = CDialog::DoModal(this: &v10);
      v11 = -1;
      if ( v7 != 1 )
      {
        v3->m_bText = m_bText;
        v3->m_bImage = m_bImage;
        CMFCToolBarButtonCustomizeDialog::~CMFCToolBarButtonCustomizeDialog(this: &v10);
        return;
      }
      CMFCToolBarButtonCustomizeDialog::~CMFCToolBarButtonCustomizeDialog(this: &v10);
    }
    if ( *((_DWORD *)v3->m_strText.m_pszData - 3) == 0 )
      this->OnSetDefaultButtonText(this, a2: v3);
    if ( *((_DWORD *)v3->m_strText.m_pszData - 3) == 0 )
    {
      MessageBeep(uType: 0xFFFFFFFF);
      v3->m_bText = 0;
      v3->m_bImage = 1;
    }
    this->AdjustLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B074B
// Name: protected: void CMFCToolBar::OnToolbarText(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarText(CMFCToolBar *this)
{
  CMFCToolBarButton *Button; // eax
  CMFCToolBarButton *v3; // esi
  char *m_pszData; // eax

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  v3 = Button;
  if ( Button != nullptr )
  {
    m_pszData = Button->m_strText.m_pszData;
    v3->m_bImage = 0;
    v3->m_bText = 1;
    if ( *((_DWORD *)m_pszData - 3) == 0 )
      this->OnSetDefaultButtonText(this, a2: v3);
    if ( *((_DWORD *)v3->m_strText.m_pszData - 3) == 0 )
    {
      MessageBeep(uType: 0xFFFFFFFF);
      v3->m_bText = 0;
      v3->m_bImage = 1;
    }
    this->AdjustLayout(this);
    this->AdjustSizeImmediate(this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B07B2
// Name: protected: void CMFCToolBar::OnToolbarReset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarReset(CMFCToolBar *this)
{
  CMFCToolBarButton *Button; // eax
  CMFCToolBarButton *v3; // esi
  CMFCToolBarButton_vtbl *v4; // eax
  BOOL v5; // eax
  _STATIC_CREATOR_ *CmdMgr; // eax
  int v7; // [esp-4h] [ebp-14h]
  CDocument *m_nID; // [esp-4h] [ebp-14h]
  int iImage; // [esp+Ch] [ebp-4h] BYREF

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  v3 = Button;
  if ( Button != nullptr )
  {
    if ( afxUserToolsManager == nullptr
      || CUserToolsManager::FindTool(this: afxUserToolsManager, uiCmdId: Button->m_nID) == nullptr )
    {
      if ( CMap<CWnd *,CWnd *,CImageList *,CImageList *>::Lookup(
             this: (CMap<unsigned int,unsigned int,CPane *,CPane *> *)&CMFCToolBar::m_DefaultImages,
             key: (CDocument *)v3->m_nID,
             rValue: (CPane **)&iImage) != 0 )
      {
        v7 = iImage;
        v4 = v3->__vftable;
        v3->m_bUserButton = 0;
        v4->SetImage(this: v3, a2: v7);
        v3->m_bImage = 1;
      }
      else
      {
        v3->m_bImage = 0;
      }
    }
    v5 = this->m_bMenuMode != 0 || v3->m_bImage == 0;
    v3->m_bText = v5;
    this->OnSetDefaultButtonText(this, a2: v3);
    this->AdjustLayout(this);
    m_nID = (CDocument *)v3->m_nID;
    CmdMgr = GetCmdMgr();
    CCommandManager::ClearCmdImage(this: &CmdMgr->s_TheCmdMgr, uiCmd: m_nID);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B086B
// Name: protected: long CMFCToolBar::OnHelpHitTest(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnHelpHitTest(CMFCToolBar *this, unsigned int wParam, int lParam)
{
  int v4; // eax
  CMFCToolBarButton *Button; // eax
  CObject *v7; // edi
  signed int v8; // esi
  CObject_vtbl *v9; // eax
  CObject *v10; // eax

  CMFCToolBar::OnCancelMode(this);
  v4 = ((int (__thiscall *)(CMFCToolBar *, _DWORD, _DWORD))this->HitTest)(
         a1: this,
         a2: (__int16)lParam,
         a3: SHIWORD(lParam));
  if ( v4 < 0 )
  {
    MessageBeep(uType: 0xFFFFFFFF);
    return -1;
  }
  Button = CMFCToolBar::GetButton(this, nIndex: v4);
  v7 = Button;
  if ( Button == nullptr || Button->OnContextHelp(this: Button, a2: this) != 0 )
    return -1;
  v8 = CBasePane::OnHelpHitTest(this, __formal: wParam, lParam);
  v9 = v7[8].__vftable;
  if ( (unsigned int)&v9[-5120] <= 0x1EF )
    v8 = ((unsigned int)&v9[-5120] >> 4) + 126720;
  v10 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButtonsButton::classCMFCToolBarMenuButtonsButton, pObject: v7);
  if ( v10 != nullptr )
    v8 = ((unsigned int)&v10[28].__vftable[-5120] >> 4) + 126720;
  if ( v8 > 0 )
    CMFCToolBar::SetHelpMode(bOn: 0);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x103B0928
// Name: protected: virtual int CMFCToolBar::CalcMaxButtonHeight(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::CalcMaxButtonHeight(CMFCToolBar *this)
{
  BOOL v2; // eax
  void *m_pNodeHead; // eax
  CMFCToolBarButton *v4; // edi
  CMFCToolBarButton_vtbl *v5; // esi
  CSize *ButtonSize; // eax
  int *v7; // eax
  int v8; // ecx
  int v9; // eax
  CSize *v10; // eax
  int v11; // esi
  int v13; // [esp-4h] [ebp-5Ch]
  CFont *v14; // [esp-4h] [ebp-5Ch]
  CClientDC dc; // [esp+10h] [ebp-48h] BYREF
  CSize sizeButton; // [esp+24h] [ebp-34h] BYREF
  _BYTE v17[8]; // [esp+2Ch] [ebp-2Ch] BYREF
  CSize v18; // [esp+34h] [ebp-24h] BYREF
  CFont *pOldFont; // [esp+3Ch] [ebp-1Ch]
  int bHorz; // [esp+40h] [ebp-18h]
  __POSITION *pos; // [esp+44h] [ebp-14h]
  int nMaxBtnHeight; // [esp+48h] [ebp-10h]
  int v23; // [esp+54h] [ebp-4h]

  v2 = (this->GetCurrentAlignment(this) & 0xA000) != 0;
  bHorz = v2;
  this->m_bDrawTextLabels = 0;
  if ( this->m_bTextLabels == 0 || !v2 )
    return 0;
  nMaxBtnHeight = 0;
  CClientDC::CClientDC(this: &dc, pWnd: this);
  v23 = 0;
  pOldFont = CBasePane::SelectDefaultFont(this, pDC: &dc);
  if ( pOldFont == nullptr )
    goto LABEL_4;
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v4 = *((CMFCToolBarButton **)m_pNodeHead + 2);
      pos = *(__POSITION **)m_pNodeHead;
      if ( v4 == nullptr )
        break;
      if ( v4->m_bTextBelow != 0 )
      {
        if ( *((_DWORD *)v4->m_strText.m_pszData - 3) == 0 )
          this->OnSetDefaultButtonText(this, a2: v4);
        v13 = bHorz;
        v5 = v4->__vftable;
        ButtonSize = CMFCToolBar::GetButtonSize(this, a2: (int)v4->__vftable, result: &v18);
        v7 = (int *)((int (__thiscall *)(CMFCToolBarButton *, _BYTE *, CClientDC *, CSize *, int))v5->OnCalculateSize)(
                      a1: v4,
                      a2: v17,
                      a3: &dc,
                      a4: ButtonSize,
                      a5: v13);
        v8 = *v7;
        v9 = v7[1];
        sizeButton.cx = v8;
        if ( nMaxBtnHeight <= v9 )
          nMaxBtnHeight = v9;
      }
      if ( pos == nullptr )
        goto LABEL_15;
      m_pNodeHead = pos;
    }
LABEL_4:
    AfxThrowInvalidArgException();
  }
LABEL_15:
  v10 = CMFCToolBar::GetButtonSize(this, a2: 0, result: &sizeButton);
  v11 = nMaxBtnHeight;
  v14 = pOldFont;
  this->m_bDrawTextLabels = nMaxBtnHeight > v10->cy;
  CDC::SelectObject(this: &dc, pFont: v14);
  v23 = -1;
  CClientDC::~CClientDC(this: &dc);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x103B0A47
// Name: public: virtual int CMFCToolBar::TranslateChar(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::TranslateChar(CMFCToolBar *this, CMFCToolBarButton *nChar)
{
  unsigned int v4; // eax
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  CMFCPopupMenu::ANIMATION_TYPE v6; // esi
  int v7; // eax
  unsigned int nUpperChar; // [esp+4h] [ebp-4h] BYREF

  if ( !CKeyboardManager::IsKeyPrintable((unsigned int)nChar) )
    return 0;
  v4 = CKeyboardManager::TranslateCharToUpper((unsigned int)nChar);
  nChar = nullptr;
  nUpperChar = v4;
  if ( CMap<HMENU__ *,HMENU__ * &,void *,void * &>::Lookup(
         this: (CMap<HMENU__ *,HMENU__ * &,void *,void * &> *)&this->m_AccelKeys,
         key: (HMENU__ **)&nUpperChar,
         rValue: (void **)&nChar) == 0 )
    return 0;
  AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
  CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
  v6 = AnimationType;
  v7 = CMFCToolBar::DropDownMenu(this, pButton: nChar);
  CMFCPopupMenu::m_AnimationType = v6;
  if ( v7 != 0 )
    return 1;
  else
    return CMFCToolBar::ProcessCommand(this, pButton: nChar);
}

//------------------------------------------------------------------------------
// Address: 0x103B0AC0
// Name: protected: virtual int CMFCToolBar::SmartUpdate(class CObList const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::SmartUpdate(CMFCToolBar *this, const CObList *lstPrevButtons)
{
  const CObList *v2; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObList::CNode *v5; // edi
  CObject *v6; // eax
  int v7; // eax
  int v8; // eax
  CObList::CNode *v9; // ecx
  CObList::CNode *v10; // edi
  CObject *v11; // eax
  CPane *v12; // eax
  CDocument *m_hWnd; // edi
  CMFCToolBarButton *v14; // eax
  CMFCToolBar_vtbl *v15; // edx
  CMFCToolBarButton *v16; // eax
  CObList::CNode *v17; // edi
  CObList::CNode *v18; // ebx
  CObject *v19; // eax
  CObject *v20; // eax
  CObject *v22; // [esp-Ch] [ebp-120h]
  CObject *data; // [esp-4h] [ebp-118h]
  CObject *v24; // [esp-4h] [ebp-118h]
  CObject *v25; // [esp-4h] [ebp-118h]
  CObject *v26; // [esp-4h] [ebp-118h]
  int v27; // [esp+10h] [ebp-104h]
  CObList::CNode *pNext; // [esp+18h] [ebp-FCh]
  CObject *v29; // [esp+18h] [ebp-FCh]
  CPane *rValue; // [esp+1Ch] [ebp-F8h] BYREF
  int iInsertAt; // [esp+20h] [ebp-F4h]
  CMFCToolBarButton v32; // [esp+24h] [ebp-F0h] BYREF
  CMFCToolBarButton v33; // [esp+94h] [ebp-80h] BYREF
  int v34; // [esp+110h] [ebp-4h]

  v2 = lstPrevButtons;
  this->m_bResourceWasChanged = 0;
  m_pNodeHead = lstPrevButtons->m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    do
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      iInsertAt = (int)AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: data);
      if ( iInsertAt != 0 )
      {
        v5 = this->m_OrigButtons.m_pNodeHead;
        while ( v5 != nullptr )
        {
          v24 = v5->data;
          v5 = v5->pNext;
          v6 = AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: v24);
          if ( v6 != nullptr
            && ((int (__thiscall *)(CObject *, int))v6->__vftable[12].dtr_CObject)(a1: v6, a2: iInsertAt) != 0 )
          {
            goto LABEL_10;
          }
        }
        v7 = iInsertAt;
        this->m_bResourceWasChanged = 1;
        v8 = CMFCToolBar::CommandToIndex(this, nIDFind: *(CObject_vtbl **)(v7 + 32), iIndexFirst: 0);
        if ( v8 >= 0 )
        {
          this->RemoveButton(this, a2: v8);
          if ( this->m_bQuickCustomize != 0 )
            CMFCToolBar::RemoveResetStateButton(this, uiCmdId: *(CObject_vtbl **)(iInsertAt + 32));
        }
      }
LABEL_10:
      ;
    }
    while ( m_pNodeHead != nullptr );
    v2 = lstPrevButtons;
  }
  v9 = this->m_OrigButtons.m_pNodeHead;
  v27 = 0;
  if ( v9 != nullptr )
  {
    while ( 1 )
    {
      pNext = v9->pNext;
      rValue = (CPane *)AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: v9->data);
      if ( rValue != nullptr )
      {
        v10 = lstPrevButtons->m_pNodeHead;
        while ( v10 != nullptr )
        {
          v25 = v10->data;
          v10 = v10->pNext;
          v11 = AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: v25);
          if ( v11 != nullptr
            && ((int (__thiscall *)(CPane *, CObject *))rValue->EnsureStdObj)(a1: rValue, a2: v11) != 0 )
          {
            goto LABEL_27;
          }
        }
        v12 = rValue;
        this->m_bResourceWasChanged = 1;
        m_hWnd = (CDocument *)v12->m_hWnd;
        iInsertAt = this->m_Buttons.m_nCount;
        if ( iInsertAt >= v27 )
          iInsertAt = v27;
        if ( m_hWnd != nullptr )
        {
          rValue = (CPane *)-1;
          CMap<CWnd *,CWnd *,CImageList *,CImageList *>::Lookup(
            this: (CMap<unsigned int,unsigned int,CPane *,CPane *> *)&CMFCToolBar::m_DefaultImages,
            key: m_hWnd,
            &rValue);
          v14 = CMFCToolBarButton::CMFCToolBarButton(
                  this: &v33,
                  uiID: (unsigned int)m_hWnd,
                  iImage: (int)rValue,
                  lpszText: nullptr,
                  bUserButton: 0,
                  bLocked: this->m_bLocked);
          v15 = this->__vftable;
          v34 = 0;
          v15->InsertButton(this, a2: v14, a3: iInsertAt);
          v34 = -1;
          CMFCToolBarButton::~CMFCToolBarButton(this: &v33);
          if ( this->m_bQuickCustomize != 0 )
          {
            v16 = CMFCToolBarButton::CMFCToolBarButton(
                    this: &v32,
                    uiID: (unsigned int)m_hWnd,
                    iImage: (int)rValue,
                    lpszText: nullptr,
                    bUserButton: 0,
                    bLocked: this->m_bLocked);
            v34 = 1;
            CMFCToolBar::InsertResetStateButton(this, a2: 0, button: v16, iInsertAt);
            v34 = -1;
            CMFCToolBarButton::~CMFCToolBarButton(this: &v32);
          }
        }
        else
        {
          this->InsertSeparator(this, a2: iInsertAt);
        }
      }
LABEL_27:
      ++v27;
      if ( pNext == nullptr )
        break;
      v9 = pNext;
    }
    v2 = lstPrevButtons;
  }
  if ( v2->m_nCount == this->m_OrigButtons.m_nCount )
  {
    v17 = this->m_OrigButtons.m_pNodeHead;
    v18 = v2->m_pNodeHead;
    while ( v17 != nullptr )
    {
      if ( v18 == nullptr )
        AfxThrowInvalidArgException();
      v26 = v17->data;
      v17 = v17->pNext;
      v19 = AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: v26);
      v22 = v18->data;
      v18 = v18->pNext;
      v29 = v19;
      v20 = AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: v22);
      if ( v29 != nullptr
        && v20 != nullptr
        && ((int (__stdcall *)(CObject *))v29->__vftable[12].dtr_CObject)(a1: v20) == 0 )
      {
        goto LABEL_37;
      }
    }
  }
  else
  {
LABEL_37:
    this->m_bResourceWasChanged = 1;
  }
  return this->m_bResourceWasChanged;
}

//------------------------------------------------------------------------------
// Address: 0x103B0DB2
// Name: protected: void CMFCToolBar::UpdateTooltips(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::UpdateTooltips(CMFCToolBar *this)
{
  CToolTipCtrl *m_pToolTip; // eax
  int v3; // ebx
  CMFCToolBarButton *Button; // edi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // ecx
  ATL::CSimpleStringT<char,0> v7; // [esp+10h] [ebp-114h] BYREF
  char szBuf[268]; // [esp+14h] [ebp-110h] BYREF
  int v9; // [esp+120h] [ebp-4h]

  m_pToolTip = this->m_pToolTip;
  v3 = 0;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
  {
    while ( this->m_nTooltipsCount >= 0 )
      CToolTipCtrl::DelTool(this: this->m_pToolTip, pWnd: this, nIDTool: --this->m_nTooltipsCount);
    this->m_nTooltipsCount = 0;
    if ( this->m_Buttons.m_nCount > 0 )
    {
      do
      {
        Button = CMFCToolBar::GetButton(this, nIndex: v3);
        if ( Button->m_nStyle != 1 )
        {
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v7, pStringMgr: StringManager);
          v9 = 0;
          AfxLoadString(nID: Button->m_nID, lpszBuf: szBuf, nMaxBuf: 0x100u);
          AfxExtractSubString(
            rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v7,
            lpszFullString: szBuf,
            iSubString: 1,
            chSep: 10);
          if ( Button->OnUpdateToolTip(
                 this: Button,
                 a2: this,
                 a3: v3,
                 a4: this->m_pToolTip,
                 a5: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v7) == 0 )
            CToolTipCtrl::AddTool(
              this: this->m_pToolTip,
              pWnd: this,
              lpszText: (char *)0xFFFFFFFF,
              lpRectTool: &Button->m_rect,
              nIDTool: v3 + 1);
          m_pszData = v7.m_pszData;
          ++this->m_nTooltipsCount;
          v9 = -1;
          ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
        }
        ++v3;
      }
      while ( v3 < this->m_Buttons.m_nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0EC2
// Name: protected: long CMFCToolBar::OnUpdateToolTips(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnUpdateToolTips(CMFCToolBar *this, char wp, int __formal)
{
  if ( (wp & 2) != 0 )
  {
    CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 2u);
    CMFCToolBar::UpdateTooltips(this);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103B0EED
// Name: public: static void CMFCToolBar::RedrawUnderlines(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall CMFCToolBar::RedrawUnderlines()
{
  CObList::CNode *m_pNodeHead; // eax
  CObject *v1; // eax
  CObject *v2; // ebx
  CObject_vtbl *v3; // edi
  void (__thiscall *Serialize)(CObject *, CArchive *); // esi
  __POSITION *posTlb; // [esp+0h] [ebp-8h]
  int bRedrawButtons; // [esp+4h] [ebp-4h]

  m_pNodeHead = afxAllToolBars.m_pNodeHead;
  if ( afxAllToolBars.m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      if ( m_pNodeHead == nullptr )
        AfxThrowInvalidArgException();
      posTlb = (__POSITION *)m_pNodeHead->pNext;
      v1 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: m_pNodeHead->data);
      v2 = v1;
      if ( v1 != nullptr && CWnd::FromHandlePermanent(hWnd: (CDocument *)v1[8].__vftable) != nullptr )
      {
        v3 = v2[755].__vftable;
        bRedrawButtons = 0;
        if ( v3 != nullptr )
        {
          do
          {
            Serialize = v3->Serialize;
            v3 = (CObject_vtbl *)v3->GetRuntimeClass;
            if ( Serialize == nullptr )
              break;
            if ( (*((_BYTE *)Serialize + 36) & 1) == 0
              && *((_DWORD *)Serialize + 2) != 0
              && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                   this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)Serialize + 11,
                   ch: 0x26u,
                   iStart: 0) >= 0 )
            {
              InvalidateRect(hWnd: (HWND)v2[8].__vftable, lpRect: (const RECT *)((char *)Serialize + 84), bErase: true);
              bRedrawButtons = 1;
            }
          }
          while ( v3 != nullptr );
          if ( bRedrawButtons != 0 )
            UpdateWindow(hWnd: (HWND)v2[8].__vftable);
        }
      }
      if ( posTlb == nullptr )
        break;
      m_pNodeHead = (CObList::CNode *)posTlb;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0FAE
// Name: public: virtual int CMFCToolBar::Create(class CWnd __near *,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::Create(CMFCToolBar *this, CWnd *pParentWnd, unsigned int dwStyle, unsigned int nID)
{
  tagRECT v5; // [esp-14h] [ebp-2Ch]

  *(_QWORD *)&v5.left = 0x100000001LL;
  *(_QWORD *)&v5.right = 0x100000001LL;
  return CMFCToolBar::CreateEx(this, pParentWnd, dwCtrlStyle: 0x800u, dwStyle, rcBorders: v5, nID);
}

//------------------------------------------------------------------------------
// Address: 0x103B0FEC
// Name: protected: virtual void CMFCToolBar::AdjustLocations(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::AdjustLocations(CMFCToolBar *this)
{
  __int16 v2; // ax
  BOOL v3; // edi
  CFont *v4; // eax
  int v5; // ecx
  int v6; // esi
  CMFCCustomizeButton *m_pCustomizeBtn; // eax
  int m_bIsEmpty; // ecx
  int v9; // ecx
  int v10; // eax
  CMFCCustomizeButton *v11; // ecx
  int *v12; // eax
  int v13; // ecx
  int v14; // eax
  CObList::CNode *m_pNodeHead; // eax
  int data; // edi
  CObject v17; // eax
  int *v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  CMFCCustomizeButton *v23; // eax
  CMFCCustomizeButton *v24; // eax
  int v25; // esi
  int v26; // edx
  int *v27; // edi
  int v28; // esi
  CMFCToolBar_vtbl *v29; // eax
  int v30; // esi
  int i; // eax
  BOOL v32; // esi
  int v33; // ecx
  int *v34; // eax
  int v35; // eax
  CMFCCustomizeButton *v36; // eax
  CMFCCustomizeButton *v37; // ecx
  CMFCCustomizeButton_vtbl *v38; // eax
  CMFCCustomizeButton *v39; // ecx
  CMFCCustomizeButton *v40; // ecx
  CMFCCustomizeButton_vtbl *v41; // eax
  CMFCCustomizeButton *v42; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-C0h]
  char v44[8]; // [esp+10h] [ebp-A8h] BYREF
  CClientDC v45; // [esp+18h] [ebp-A0h] BYREF
  char v46[4]; // [esp+2Ch] [ebp-8Ch] BYREF
  int v47; // [esp+30h] [ebp-88h]
  int v48; // [esp+34h] [ebp-84h] BYREF
  int v49; // [esp+38h] [ebp-80h]
  int v50; // [esp+3Ch] [ebp-7Ch] BYREF
  int v51; // [esp+40h] [ebp-78h]
  int v52; // [esp+44h] [ebp-74h]
  int top; // [esp+48h] [ebp-70h]
  int right; // [esp+4Ch] [ebp-6Ch]
  int v55; // [esp+50h] [ebp-68h]
  int v56; // [esp+54h] [ebp-64h]
  CFont *pFont; // [esp+58h] [ebp-60h]
  int bShow; // [esp+5Ch] [ebp-5Ch]
  CObList::CNode *pNext; // [esp+60h] [ebp-58h]
  tagRECT v60; // [esp+64h] [ebp-54h] BYREF
  int v61; // [esp+74h] [ebp-44h]
  int v62; // [esp+78h] [ebp-40h]
  BOOL v63; // [esp+7Ch] [ebp-3Ch]
  int v64; // [esp+80h] [ebp-38h]
  int *v65; // [esp+84h] [ebp-34h]
  tagRECT rc; // [esp+88h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+98h] [ebp-20h] BYREF
  int v68; // [esp+B4h] [ebp-4h]

  if ( this->m_Buttons.m_nCount != 0 && this->m_hWnd != nullptr )
  {
    v2 = this->GetCurrentAlignment(this);
    m_hWnd = this->m_hWnd;
    v3 = (v2 & 0xA000) != 0;
    v63 = v3;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    right = Rect.right;
    CClientDC::CClientDC(this: &v45, pWnd: this);
    v68 = 0;
    if ( v3 )
      v4 = CBasePane::SelectDefaultFont(this, pDC: &v45);
    else
      v4 = CDC::SelectObject(this: &v45, pFont: &afxGlobalData.fontVert);
    pFont = v4;
    if ( v4 == nullptr )
      goto LABEL_7;
    if ( v3 )
      v5 = Rect.left + 1;
    else
      v5 = Rect.top + 1;
    v61 = v5;
    v6 = v5;
    top = Rect.top;
    v62 = this->GetRowHeight(this);
    v50 = this->GetColumnWidth(this);
    v51 = v62;
    v55 = 0;
    v56 = 0;
    if ( this->m_pCustomizeBtn != nullptr && this->IsFloating(this) == 0 && CMFCToolBar::m_bCustomizeMode == 0 )
    {
      CObList::RemoveAll(this: &this->m_pCustomizeBtn->m_lstInvisibleButtons);
      m_pCustomizeBtn = this->m_pCustomizeBtn;
      m_bIsEmpty = m_pCustomizeBtn->m_bIsEmpty;
      m_pCustomizeBtn->m_bIsEmpty = 0;
      v62 = m_bIsEmpty;
      if ( v3 )
        v9 = Rect.bottom - Rect.top;
      else
        v9 = v51;
      if ( v3 )
        v10 = v50;
      else
        v10 = Rect.right - Rect.left;
      v49 = v9;
      v11 = this->m_pCustomizeBtn;
      v48 = v10;
      v12 = (int *)((int (__thiscall *)(CMFCCustomizeButton *, char *, CClientDC *, int *, BOOL))v11->OnCalculateSize)(
                     a1: v11,
                     a2: v46,
                     a3: &v45,
                     a4: &v48,
                     a5: v3);
      v13 = *v12;
      v14 = v12[1];
      v55 = v13;
      v56 = v14;
      this->m_pCustomizeBtn->m_bIsEmpty = v62;
    }
    m_pNodeHead = this->m_Buttons.m_pNodeHead;
    v52 = 0;
    v65 = nullptr;
    if ( m_pNodeHead != nullptr )
    {
      while ( 1 )
      {
        v62 = (int)m_pNodeHead;
        data = (int)m_pNodeHead->data;
        pNext = m_pNodeHead->pNext;
        v49 = data;
        if ( data == 0 )
          break;
        v17.__vftable = *(CObject_vtbl **)data;
        bShow = 1;
        v18 = (int *)((int (__thiscall *)(int, char *, CClientDC *, int *, BOOL))v17.__vftable[2].dtr_CObject)(
                       a1: data,
                       a2: v44,
                       a3: &v45,
                       a4: &v50,
                       a5: v63);
        v19 = *v18;
        v20 = v18[1];
        if ( *(_DWORD *)(data + 24) != 0 && v63 )
          v20 = v51;
        if ( (*(_BYTE *)(data + 36) & 1) != 0 )
        {
          if ( v6 == v61 || v52 != 0 )
          {
            v20 = 0;
            v19 = 0;
            bShow = 0;
          }
          else
          {
            v52 = 1;
          }
        }
        v47 = v6;
        if ( v63 )
        {
          v21 = v19 + v6;
          v60.left = v6;
          v6 = top;
          v22 = top + v20;
          v65 = (int *)((char *)v65 + v19);
          v60.right = v21;
          v64 = v21;
        }
        else
        {
          v22 = v6 + v20;
          v60.left = Rect.left;
          v60.right = Rect.left + v19;
          v64 = v22;
        }
        v60.bottom = v22;
        v23 = this->m_pCustomizeBtn;
        v60.top = v6;
        if ( v23 != nullptr
          && (CMFCCustomizeButton *)data != v23
          && this->IsFloating(this) == 0
          && CMFCToolBar::m_bCustomizeMode == 0 )
        {
          v24 = this->m_pCustomizeBtn;
          v25 = v55;
          v26 = v56;
          if ( v24->m_iCustomizeCmdId <= 0
            && pNext != nullptr
            && pNext->data == v24
            && v24->m_lstInvisibleButtons.m_nCount == 0 )
          {
            v26 = 0;
            v25 = 0;
          }
          if ( !v63 )
          {
            if ( v60.bottom <= Rect.bottom - v26 )
              goto LABEL_51;
LABEL_50:
            bShow = 0;
            v64 = v47;
            CPtrList::AddTail(this: &v24->m_lstInvisibleButtons, newElement: (CObject *)data);
            goto LABEL_51;
          }
          if ( v60.right > right - v25 )
            goto LABEL_50;
        }
LABEL_51:
        CMFCToolBarButton::Show(this: (CMFCToolBarButton *)data, bShow);
        v27 = (int *)(data + 84);
        *v27++ = v60.left;
        *v27++ = v60.top;
        *v27 = v60.right;
        v27[1] = v60.bottom;
        v28 = v49;
        (*(void (__thiscall **)(int))(*(_DWORD *)v49 + 48))(a1: v49);
        if ( bShow != 0 )
          v52 = *(_DWORD *)(v28 + 36) & 1;
        if ( *(_DWORD *)(v28 + 16) != 0 || pNext == nullptr )
        {
          if ( v63 )
          {
            v29 = this->__vftable;
            v30 = (right - (int)v65 - v61) / 2;
            v49 = v30;
            if ( v29->IsFloating(this) != 0 && v30 > 0 && this->m_bTextLabels != 0 )
            {
              for ( i = v62; ; i = v64 )
              {
                v32 = i == v62;
                if ( i == 0 )
                  break;
                v33 = *(_DWORD *)(i + 4);
                v34 = *(int **)(i + 8);
                v64 = v33;
                v65 = v34;
                if ( v34 == nullptr )
                  break;
                if ( v34[4] != 0 && !v32 )
                  goto LABEL_66;
                rc = *(tagRECT *)(v34 + 21);
                OffsetRect(lprc: &rc, dx: v49, dy: 0);
                v35 = *v65;
                *(tagRECT *)(v65 + 21) = rc;
                (*(void (**)(void))(v35 + 48))();
                if ( v64 == 0 )
                  goto LABEL_66;
              }
LABEL_7:
              AfxThrowInvalidArgException();
            }
LABEL_66:
            v65 = nullptr;
            v64 = v61;
            top += v51 + 5;
          }
          if ( pNext == nullptr )
            break;
        }
        v6 = v64;
        m_pNodeHead = pNext;
      }
    }
    v36 = this->m_pCustomizeBtn;
    if ( v36 != nullptr )
    {
      v60 = Rect;
      if ( v36->m_iCustomizeCmdId <= 0 && v36->m_lstInvisibleButtons.m_nCount == 0
        || this->IsFloating(this) != 0
        || CMFCToolBar::m_bCustomizeMode != 0 )
      {
        v40 = this->m_pCustomizeBtn;
        v41 = v40->__vftable;
        memset(&v60, 0, sizeof(v60));
        v40->m_rect.left = 0;
        v40->m_rect.top = v60.top;
        v40->m_rect.right = v60.right;
        v40->m_rect.bottom = v60.bottom;
        ((void (*)(void))v41->OnMove)();
        v42 = this->m_pCustomizeBtn;
        if ( v42->m_bIsHidden != 1 )
        {
          v42->m_bIsHidden = 1;
          v42->OnShow(this: v42, a2: 0);
        }
      }
      else
      {
        if ( v63 )
        {
          v60.right = right - 1;
          v60.left = right - v55;
        }
        else
        {
          v60.top = --v60.bottom - v56;
        }
        v37 = this->m_pCustomizeBtn;
        v38 = v37->__vftable;
        v37->m_rect = (CRect)v60;
        ((void (*)(void))v38->OnMove)();
        v39 = this->m_pCustomizeBtn;
        if ( v39->m_bIsHidden != 0 )
        {
          v39->m_bIsHidden = 0;
          v39->OnShow(this: v39, a2: 1);
        }
      }
    }
    CDC::SelectObject(this: &v45, pFont);
    CMFCToolBar::UpdateTooltips(this);
    CMFCToolBar::RedrawCustomizeButton(this);
    v68 = -1;
    CClientDC::~CClientDC(this: &v45);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B14DB
// Name: public: virtual void CMFCToolBar::RestoreFocus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::RestoreFocus(CMFCToolBar *this)
{
  HWND__ **p_m_hwndLastFocus; // esi

  p_m_hwndLastFocus = &this->m_hwndLastFocus;
  if ( IsWindow(hWnd: this->m_hwndLastFocus) )
    SetFocus(hWnd: *p_m_hwndLastFocus);
  *p_m_hwndLastFocus = nullptr;
  if ( afxGlobalData.m_bUnderlineKeyboardShortcuts != 0
    && afxGlobalData.m_bSysUnderlineKeyboardShortcuts == 0
    && CMFCToolBar::m_bCustomizeMode == 0 )
  {
    afxGlobalData.m_bUnderlineKeyboardShortcuts = 0;
    CMFCToolBar::RedrawUnderlines();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10406ED7
// Name: public: static class CNoTrackObject __near * CProcessLocal<class _AFX_OLE_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_OLE_STATE *__stdcall CProcessLocal<_AFX_OLE_STATE>::CreateObject()
{
  _AFX_OLE_STATE *v0; // ecx
  _AFX_OLE_STATE *result; // eax

  v0 = (_AFX_OLE_STATE *)CNoTrackObject::operator new(nSize: 0x14u);
  result = nullptr;
  if ( v0 != nullptr )
    return _AFX_OLE_STATE::_AFX_OLE_STATE(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406F03
// Name: public: class CWnd __near * COleClientItem::GetInPlaceWindow(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall COleClientItem::GetInPlaceWindow(COleClientItem *this)
{
  if ( this->m_nItemState != activeUIState )
    return nullptr;
  if ( this->m_hWndServer != nullptr && !IsWindow(hWnd: this->m_hWndServer) )
  {
    COleClientItem::Close(this, dwCloseOption: OLECLOSE_SAVEIFDIRTY);
    return nullptr;
  }
  return CWnd::FromHandle(hWnd: this->m_hWndServer);
}

//------------------------------------------------------------------------------
// Address: 0x10406F38
// Name: public: CSmartDockingManager::CSmartDockingManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartDockingManager *__thiscall CSmartDockingManager::CSmartDockingManager(CSmartDockingManager *this)
{
  this->__vftable = (CSmartDockingManager_vtbl *)&CSmartDockingManager::`vftable';
  this->m_bStarted = 0;
  this->m_bCreated = 0;
  this->m_bShown = 0;
  this->m_bCentralGroupShown = 0;
  this->m_pwndOwner = nullptr;
  this->m_pDockingWnd = nullptr;
  this->m_rcOuter.left = 0;
  this->m_rcOuter.top = 0;
  this->m_rcOuter.right = 0;
  this->m_rcOuter.bottom = 0;
  CSmartDockingHighlighterWnd::CSmartDockingHighlighterWnd(this: &this->m_wndPlaceMarker);
  this->m_nHiliteSideNo = sdNONE;
  memset(dst: (unsigned __int8 *)this->m_arMarkers, value: 0, count: sizeof(this->m_arMarkers));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040C4DA
// Name: public: CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPropertyGridToolTipCtrl *__thiscall CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl(
        CMFCPropertyGridToolTipCtrl *this)
{
  CAfxStringMgr *StringManager; // eax

  CWnd::CWnd(this);
  this->__vftable = (CMFCPropertyGridToolTipCtrl_vtbl *)&CMFCPropertyGridToolTipCtrl::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strText, pStringMgr: StringManager);
  this->m_rectLast.left = 0;
  this->m_rectLast.top = 0;
  this->m_rectLast.right = 0;
  this->m_rectLast.bottom = 0;
  SetRectEmpty(lprc: &this->m_rectLast);
  this->m_hFont = nullptr;
  this->m_pWndParent = nullptr;
  this->m_nTextMargin = 10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040C52B
// Name: public: virtual CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl(CMFCPropertyGridToolTipCtrl *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strText.m_pszData - 16);
  this->__vftable = (CMFCPropertyGridToolTipCtrl_vtbl *)&CMFCPropertyGridToolTipCtrl::`vftable';
  ATL::CStringData::Release(this: v2);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040C56A
// Name: protected: void CMFCPropertyGridToolTipCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridToolTipCtrl::OnPaint(CMFCPropertyGridToolTipCtrl *this)
{
  CMFCVisualManager *Instance; // eax
  HDC__ *m_hDC; // esi
  HBRUSH SysColorBrush; // eax
  unsigned int m_nGradientAngle; // eax
  void *m_clrBorder; // eax
  COLORREF SysColor; // esi
  CFont *v8; // eax
  CFont *v9; // eax
  const unsigned __int8 *v10; // eax
  int v11; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-D0h]
  CMFCToolTipInfo v13; // [esp+10h] [ebp-B8h] BYREF
  CDrawingManager v14; // [esp+44h] [ebp-84h] BYREF
  CBrush v15; // [esp+4Ch] [ebp-7Ch] BYREF
  CPaintDC v16; // [esp+54h] [ebp-74h] BYREF
  tagRECT Rect; // [esp+A8h] [ebp-20h] BYREF
  int v18; // [esp+C4h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v16, pWnd: this);
  m_hWnd = this->m_hWnd;
  v18 = 0;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  CMFCToolTipInfo::CMFCToolTipInfo(this: &v13);
  Instance = CMFCVisualManager::GetInstance();
  Instance->GetToolTipInfo(this: Instance, a2: &v13, a3: -1u);
  if ( v13.m_clrFill == -1 )
  {
    m_hDC = v16.m_hDC;
    SysColorBrush = GetSysColorBrush(nIndex: 24);
    FillRect(hDC: m_hDC, lprc: &Rect, hbr: SysColorBrush);
  }
  else if ( v13.m_clrFillGradient == -1 )
  {
    CBrush::CBrush(this: &v15, crColor: v13.m_clrFill);
    FillRect(hDC: v16.m_hDC, lprc: &Rect, hbr: (HBRUSH)v15.m_hObject);
    v15.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &v15);
  }
  else
  {
    CDrawingManager::CDrawingManager(this: &v14, m_dc: &v16);
    m_nGradientAngle = v13.m_nGradientAngle;
    LOBYTE(v18) = 1;
    if ( v13.m_nGradientAngle == -1 )
      m_nGradientAngle = 90;
    CDrawingManager::FillGradient2(
      this: &v14,
      rect: (CRect)Rect,
      colorStart: v13.m_clrFillGradient,
      colorFinish: v13.m_clrFill,
      nAngle: m_nGradientAngle);
    LOBYTE(v18) = 0;
    CDrawingManager::~CDrawingManager(this: &v14);
  }
  m_clrBorder = (void *)v13.m_clrBorder;
  if ( v13.m_clrBorder == -1 )
    m_clrBorder = (void *)GetSysColor(nIndex: 23);
  v15.m_hObject = m_clrBorder;
  if ( v13.m_clrText == -1 )
    SysColor = GetSysColor(nIndex: 23);
  else
    SysColor = v13.m_clrText;
  CDC::Draw3dRect(
    this: &v16,
    lpRect: &Rect,
    clrTopLeft: (COLORREF)v15.m_hObject,
    clrBottomRight: (COLORREF)v15.m_hObject);
  if ( this->m_hFont != nullptr )
  {
    v9 = (CFont *)CGdiObject::FromHandle(h: this->m_hFont);
    v8 = CDC::SelectObject(this: &v16, pFont: v9);
  }
  else
  {
    v8 = (CFont *)CDC::SelectStockObject(this: &v16, nIndex: 17);
  }
  v15.m_hObject = v8;
  if ( v8 == nullptr )
    AfxThrowInvalidArgException();
  CDC::SetBkMode(this: &v16, nBkMode: 1);
  CDC::SetTextColor(this: &v16, crColor: SysColor);
  v10 = _mbspbrk(string: (const unsigned __int8 *)this->m_strText.m_pszData, charset: "\n");
  if ( v10 == nullptr || v10 - (const unsigned __int8 *)this->m_strText.m_pszData == -1 )
  {
    InflateRect(lprc: &Rect, dx: -this->m_nTextMargin, dy: 0);
    v16.DrawTextA(
      this: &v16,
      a2: this->m_strText.m_pszData,
      a3: *((_DWORD *)this->m_strText.m_pszData - 3),
      a4: &Rect,
      a5: 36u);
  }
  else
  {
    InflateRect(lprc: &Rect, dx: -this->m_nTextMargin, dy: -this->m_nTextMargin);
    v11 = this->m_rectLast.bottom - this->m_rectLast.top;
    if ( Rect.bottom - Rect.top < v11 )
      Rect.top += (Rect.top + v11 - Rect.bottom) / 2;
    v16.DrawTextA(
      this: &v16,
      a2: this->m_strText.m_pszData,
      a3: *((_DWORD *)this->m_strText.m_pszData - 3),
      a4: &Rect,
      a5: 16u);
  }
  CDC::SelectObject(this: &v16, pFont: (CFont *)v15.m_hObject);
  v18 = -1;
  CPaintDC::~CPaintDC(this: &v16);
}

//------------------------------------------------------------------------------
// Address: 0x1040C7A5
// Name: public: void CMFCPropertyGridToolTipCtrl::Track(class CRect,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridToolTipCtrl::Track(
        CMFCPropertyGridToolTipCtrl *this,
        RECT rect,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strText)
{
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v3; // esi
  CRect *p_m_rectLast; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strText; // esi
  HFONT__ *m_hFont; // eax
  CFont *v8; // eax
  CFont *v9; // eax
  int v10; // edi
  const unsigned __int8 *v11; // eax
  const unsigned __int8 *m_pszData; // ecx
  int v13; // edi
  int v14; // eax
  ATL::CSimpleStringT<char,0> *v15; // esi
  int left; // edx
  int top; // ecx
  int v18; // esi
  int bottom; // eax
  HMONITOR v20; // eax
  char *right; // eax
  int v22; // ecx
  int v23; // ecx
  HCURSOR CursorA; // eax
  ATL::CSimpleStringT<char,0> *v25; // [esp-4h] [ebp-88h]
  CClientDC v26; // [esp+10h] [ebp-74h] BYREF
  CFont *pFont; // [esp+24h] [ebp-60h]
  ATL::CSimpleStringT<char,0> *strSrc; // [esp+28h] [ebp-5Ch]
  tagMONITORINFO mi; // [esp+2Ch] [ebp-58h] BYREF
  _DWORD v30[2]; // [esp+54h] [ebp-30h] BYREF
  CSize result; // [esp+5Ch] [ebp-28h] BYREF
  tagRECT rcDst; // [esp+64h] [ebp-20h] BYREF
  int v33; // [esp+80h] [ebp-4h]

  v3 = strText;
  strSrc = &strText->ATL::CSimpleStringT<char,0>;
  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    p_m_rectLast = &this->m_rectLast;
    if ( !EqualRect(lprc1: &this->m_rectLast, lprc2: &rect)
      || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: &this->m_strText,
           psz: v3->m_pszData) != 0 )
    {
      v25 = strSrc;
      p_m_rectLast->left = rect.left;
      this->m_rectLast.top = rect.top;
      this->m_rectLast.right = rect.right;
      this->m_rectLast.bottom = rect.bottom;
      p_m_strText = &this->m_strText;
      ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strText, strSrc: (ATL::CStringData *)v25);
      CClientDC::CClientDC(this: &v26, pWnd: this);
      m_hFont = this->m_hFont;
      v33 = 0;
      if ( m_hFont != nullptr )
      {
        v9 = (CFont *)CGdiObject::FromHandle(h: m_hFont);
        v8 = CDC::SelectObject(this: &v26, pFont: v9);
      }
      else
      {
        v8 = (CFont *)CDC::SelectStockObject(this: &v26, nIndex: 17);
      }
      pFont = v8;
      if ( v8 == nullptr )
        AfxThrowInvalidArgException();
      v10 = rect.bottom - rect.top;
      v11 = _mbspbrk(string: (const unsigned __int8 *)p_m_strText->m_pszData, charset: "\n");
      if ( v11 == nullptr
        || (m_pszData = (const unsigned __int8 *)p_m_strText->m_pszData,
            v11 - (const unsigned __int8 *)p_m_strText->m_pszData == -1) )
      {
        v15 = (ATL::CSimpleStringT<char,0> *)(CDC::GetTextExtent(this: &v26, &result, str: &this->m_strText)->cx
                                            + 2 * this->m_nTextMargin);
        strSrc = v15;
      }
      else
      {
        v30[0] = 0;
        v30[1] = 0;
        result.cy = afxGlobalData.m_nTextHeightHorz;
        result.cx = 200;
        v13 = v26.DrawTextA(
                this: &v26,
                a2: (const char *)m_pszData,
                a3: *((_DWORD *)m_pszData - 3),
                a4: (tagRECT *)v30,
                a5: 1040u);
        v14 = 2 * this->m_nTextMargin;
        v10 = v14 + v13;
        v15 = (ATL::CSimpleStringT<char,0> *)(result.cx + v14 - v30[0]);
        strSrc = v15;
      }
      CDC::SelectObject(this: &v26, pFont);
      if ( (CWnd::GetExStyle(this: this->m_pWndParent) & 0x400000) != 0 )
      {
        left = rect.right - (_DWORD)v15;
        rect.left = rect.right - (_DWORD)v15;
      }
      else
      {
        left = rect.left;
        rect.right = (int)v15 + rect.left;
      }
      top = rect.top;
      v18 = this->m_rectLast.bottom - this->m_rectLast.top;
      rect.bottom = rect.top + v10;
      if ( v10 < v18 )
      {
        top = this->m_rectLast.top;
        bottom = this->m_rectLast.bottom;
        rect.top = top;
        rect.bottom = bottom;
      }
      mi.cbSize = 40;
      memset(&rcDst, 0, sizeof(rcDst));
      v20 = MonitorFromPoint(pt: (POINT)__PAIR64__(top, left), dwFlags: 2u);
      if ( GetMonitorInfoA(hMonitor: v20, lpmi: &mi) )
        CopyRect(lprcDst: &rcDst, lprcSrc: &mi.rcWork);
      else
        SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rcDst, fWinIni: 0);
      right = (char *)rect.right;
      if ( rect.right - rect.left <= rcDst.right - rcDst.left )
      {
        if ( rect.right <= rcDst.right )
        {
          v22 = rcDst.left;
          if ( rect.left >= rcDst.left )
            goto LABEL_30;
          right = (char *)strSrc + rcDst.left;
        }
        else
        {
          right = (char *)rcDst.right;
          v22 = rcDst.right - (_DWORD)strSrc;
        }
        rect.left = v22;
      }
      else
      {
        rect.left = rcDst.left;
        right = (char *)rcDst.right;
      }
      rect.right = (int)right;
LABEL_30:
      if ( rect.bottom - rect.top > rcDst.bottom - rcDst.top )
      {
        rect.top = rcDst.top;
        rect.bottom = rcDst.bottom;
LABEL_37:
        CWnd::SetWindowPos(
          this,
          pWndInsertAfter: &CWnd::wndTop,
          x: rect.left,
          y: rect.top,
          cx: (int)&right[-rect.left],
          cy: rect.bottom - rect.top,
          nFlags: 0x210u);
        CWnd::ShowWindow(this, nCmdShow: 4);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_hWnd);
        AfxGetModuleState();
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
        SetCursor(hCursor: CursorA);
        v33 = -1;
        CClientDC::~CClientDC(this: &v26);
        return;
      }
      if ( rect.bottom <= rcDst.bottom )
      {
        v23 = rcDst.top;
        if ( rect.top >= rcDst.top )
          goto LABEL_37;
        rect.bottom += v10;
      }
      else
      {
        rect.bottom = rcDst.bottom;
        v23 = rcDst.bottom - v10;
      }
      rect.top = v23;
      goto LABEL_37;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CA52
// Name: public: virtual int CMFCPropertyGridToolTipCtrl::Create(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridToolTipCtrl::Create(CMFCPropertyGridToolTipCtrl *this, CWnd *pWndParent)
{
  HCURSOR CursorA; // eax
  char *v4; // eax
  HWND__ *m_hWnd; // ebx

  this->m_pWndParent = pWndParent;
  if ( *((_DWORD *)CMFCPropertyGridToolTipCtrl::m_strClassName.m_pszData - 3) == 0 )
  {
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    v4 = AfxRegisterWndClass(nClassStyle: 0x800u, hCursor: CursorA, hbrBackground: (HBRUSH__ *)0x10, hIcon: nullptr);
    ATL::CSimpleStringT<char,0>::SetString(this: &CMFCPropertyGridToolTipCtrl::m_strClassName, pszSrc: v4);
  }
  if ( pWndParent != nullptr )
    m_hWnd = pWndParent->m_hWnd;
  else
    m_hWnd = nullptr;
  return this->CreateEx_2(
           this,
           a2: 0,
           a3: CMFCPropertyGridToolTipCtrl::m_strClassName.m_pszData,
           a4: &var,
           a5: 0x80000000,
           a6: 0,
           a7: 0,
           a8: 0,
           a9: 0,
           a10: m_hWnd,
           a11: nullptr,
           a12: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1040CAC7
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCPropertyGridToolTipCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCPropertyGridToolTipCtrl::GetMessageMap(CMFCPropertyGridToolTipCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1068C7E0;
}

//------------------------------------------------------------------------------
// Address: 0x1040CACD
// Name: public: virtual struct CRuntimeClass __near * CMFCHeaderCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCHeaderCtrl::GetRuntimeClass(CMFCHeaderCtrl *this)
{
  return &CMFCHeaderCtrl::classCMFCHeaderCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1040CAD3
// Name: public: class CImageList __near * CHeaderCtrl::GetImageList(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CImageList *__thiscall CHeaderCtrl::GetImageList(CHeaderCtrl *this, WPARAM nImageList)
{
  struct _IMAGELIST *v2; // eax

  v2 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1209u, wParam: nImageList, lParam: 0);
  return CImageList::FromHandle(h: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1040CAF5
// Name: protected: virtual void CMFCHeaderCtrl::OnFillBackground(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnFillBackground(CMFCHeaderCtrl *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  CRect rectClient; // [esp+10h] [ebp-14h] BYREF

  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CMFCHeaderCtrl *, CDC *, int, int, int, int))Instance->OnFillHeaderCtrlBackground)(
    a1: Instance,
    a2: this,
    a3: pDC,
    a4: rectClient.left,
    a5: rectClient.top,
    a6: rectClient.right,
    a7: rectClient.bottom);
}

//------------------------------------------------------------------------------
// Address: 0x1040CB5D
// Name: protected: class CFont __near * CMFCHeaderCtrl::SelectFont(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFont *__thiscall CMFCHeaderCtrl::SelectFont(CMFCHeaderCtrl *this, CDC *pDC)
{
  CFont *v2; // eax
  CDC_vtbl *v4; // eax

  if ( this->m_hFont != nullptr )
  {
    v2 = (CFont *)CGdiObject::FromHandle(h: this->m_hFont);
    return pDC->SelectObject(this: pDC, a2: v2);
  }
  else
  {
    v4 = pDC->__vftable;
    if ( this->m_bIsDlgControl != 0 )
      return ((CFont *(__stdcall *)(int))v4->SelectStockObject)(a1: 17);
    else
      return ((CFont *(__stdcall *)(CFont *))v4->SelectObject)(a1: &afxGlobalData.fontRegular);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CB9E
// Name: protected: void CMFCHeaderCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnLButtonDown(CMFCHeaderCtrl *this, unsigned int nFlags, CPoint point)
{
  this->m_bIsMousePressed = 1;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040CBB0
// Name: protected: void CMFCHeaderCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnLButtonUp(CMFCHeaderCtrl *this, unsigned int nFlags, CPoint point)
{
  this->m_bIsMousePressed = 0;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040CBBF
// Name: protected: virtual void CMFCHeaderCtrl::OnDrawSortArrow(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnDrawSortArrow(CMFCHeaderCtrl *this, CDC *pDC, CRect rectArrow)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  Instance->OnDrawHeaderCtrlSortArrow(this: Instance, a2: this, a3: pDC, a4: &rectArrow, a5: this->m_bAscending);
}

//------------------------------------------------------------------------------
// Address: 0x1040CBEC
// Name: protected: void CMFCHeaderCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnMouseMove(CMFCHeaderCtrl *this, char nFlags, CPoint point)
{
  int m_nHighlightedItem; // edi
  HWND__ *m_hWnd; // eax
  tagTRACKMOUSEEVENT trackmouseevent; // [esp+4h] [ebp-24h] BYREF
  _HD_HITTESTINFO hdHitTestInfo; // [esp+14h] [ebp-14h] BYREF

  if ( (nFlags & 1) == 0 )
  {
    hdHitTestInfo.pt.x = point.x;
    m_nHighlightedItem = this->m_nHighlightedItem;
    hdHitTestInfo.pt.y = point.y;
    this->m_nHighlightedItem = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1206u, wParam: 0, lParam: (LPARAM)&hdHitTestInfo);
    if ( (hdHitTestInfo.flags & 2) == 0 )
      this->m_nHighlightedItem = -1;
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
    if ( m_nHighlightedItem != this->m_nHighlightedItem )
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  CWnd::Default(this);
}
