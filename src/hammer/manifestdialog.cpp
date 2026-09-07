// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/manifestdialog.cpp
// Functions: 82
// ============================================================

#include "hammer\manifestdialog.h"

//------------------------------------------------------------------------------
// Address: 0x1005B3F0
// Name: public: virtual struct CRuntimeClass __near * CManifestMove::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CManifestMove::GetRuntimeClass(CManifestMove *this)
{
  return &CManifestMove::classCManifestMove;
}

//------------------------------------------------------------------------------
// Address: 0x1005B400
// Name: public: virtual int CManifestMove::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CManifestMove::OnInitDialog(CManifestMove *this)
{
  CDialog::OnInitDialog(this);
  CWnd::SetWindowTextA(this: &this->m_FileNameControl, lpszString: &var);
  if ( !this->m_bIsMove )
    CWnd::ShowWindow(this: &this->m_CenterContentsControl, nCmdShow: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005B440
// Name: public: virtual void CManifestListBox::MeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::MeasureItem(CManifestListBox *this, tagMEASUREITEMSTRUCT *lpMeasureItemStruct)
{
  lpMeasureItemStruct->itemHeight = 36;
}

//------------------------------------------------------------------------------
// Address: 0x1005B460
// Name: public: void CManifestListBox::OnMoveSelectionToSubMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnMoveSelectionToSubMap(CManifestListBox *this)
{
  CManifestMap *m_pTrackerManifestMap; // eax

  m_pTrackerManifestMap = this->m_pTrackerManifestMap;
  if ( m_pTrackerManifestMap != nullptr && CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
  {
    CManifest::MoveSelectionToSubmap(
      this: CMapDoc::m_pManifest,
      pManifestMap: m_pTrackerManifestMap,
      CenterContents: false);
    this->m_pTrackerManifestMap = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B4A0
// Name: public: void CManifestListBox::OnInsertExistingSubMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnInsertExistingSubMap(CManifestListBox *this)
{
  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
    CManifest::AddExistingMap(this: CMapDoc::m_pManifest);
}

//------------------------------------------------------------------------------
// Address: 0x1005B4C0
// Name: public: void CManifestFilter::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestFilter::OnDestroy(CManifestFilter *this)
{
  CBrush *m_pBkBrush; // ecx

  CControlBar::OnDestroy(this);
  m_pBkBrush = this->m_pBkBrush;
  if ( m_pBkBrush != nullptr )
    ((void (__thiscall *)(CBrush *, int))m_pBkBrush->dtr_CObject)(a1: m_pBkBrush, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1005B4F0
// Name: public: virtual struct CRuntimeClass __near * CManifestMapDlg::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CManifestMapDlg::GetRuntimeClass(CManifestMapDlg *this)
{
  return &CManifestMapDlg::classCManifestMapDlg;
}

//------------------------------------------------------------------------------
// Address: 0x1005B500
// Name: public: virtual CManifestMapDlg::~CManifestMapDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMapDlg::~CManifestMapDlg(CManifestMapDlg *this)
{
  this->__vftable = (CManifestMapDlg_vtbl *)&CManifestMapDlg::`vftable';
  CStatic::~CStatic(this: &this->m_FullFileNameCtrl);
  CEdit::~CEdit(this: &this->m_FriendlyNameControl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B570
// Name: protected: virtual void CManifestMapDlg::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMapDlg::OnOK(CManifestMapDlg *this)
{
  CWnd::GetWindowTextA(this: &this->m_FriendlyNameControl, rString: &this->m_pManifestMap->m_FriendlyName);
  CDialog::OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B590
// Name: public: virtual struct CRuntimeClass __near * CManifestCheckin::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CManifestCheckin::GetRuntimeClass(CManifestCheckin *this)
{
  return &CManifestCheckin::classCManifestCheckin;
}

//------------------------------------------------------------------------------
// Address: 0x1005B5A0
// Name: public: virtual CManifestCheckin::~CManifestCheckin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestCheckin::~CManifestCheckin(CManifestCheckin *this)
{
  this->__vftable = (CManifestCheckin_vtbl *)&CManifestCheckin::`vftable';
  CEdit::~CEdit(this: &this->m_DescriptionCtrl);
  CListCtrl::~CListCtrl(this: &this->m_CheckinListCtrl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B610
// Name: public: int CMenu::LoadMenuA(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMenu::LoadMenuA(CMenu *this, unsigned __int16 nIDResource)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax

  ModuleState = AfxGetModuleState();
  MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)nIDResource);
  return CMenu::Attach(this, hMenu: MenuW);
}

//------------------------------------------------------------------------------
// Address: 0x1005B670
// Name: public: int CListCtrl::SetItemData(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CListCtrl::SetItemData(CListCtrl *this, int nItem, unsigned int dwData)
{
  return CListCtrl::SetItem(
           this,
           nItem,
           nSubItem: 0,
           nMask: 4u,
           lpszItem: nullptr,
           nImage: 0,
           nState: 0,
           nStateMask: 0,
           lParam: dwData);
}

//------------------------------------------------------------------------------
// Address: 0x1005B690
// Name: public: struct HINSTANCE__ __near * CDllIsolationWrapperBase::GetModuleHandleA(void)
// Source: json
//------------------------------------------------------------------------------
HMODULE __thiscall CDllIsolationWrapperBase::GetModuleHandleA(CDllIsolationWrapperBase *this)
{
  HMODULE result; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m_hModule == nullptr )
  {
    result = GetModuleHandleA(lpModuleName: this->m_strModuleName.m_pszData);
    this->m_hModule = result;
    if ( result != nullptr )
      return result;
    LibraryA = LoadLibraryA(lpLibFileName: this->m_strModuleName.m_pszData);
    this->m_hModule = LibraryA;
    this->m_bFreeLib = LibraryA != nullptr;
  }
  return this->m_hModule;
}

//------------------------------------------------------------------------------
// Address: 0x1005B6D0
// Name: public: struct CComCtlWrapper::ImageList_Draw_Type CComCtlWrapper::GetProcAddress_ImageList_Draw(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_Draw_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_Draw(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_Draw_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_Draw.p == nullptr )
  {
    if ( this->m_hModule == nullptr )
    {
      ModuleHandleA = GetModuleHandleA(lpModuleName: this->m_strModuleName.m_pszData);
      this->m_hModule = ModuleHandleA;
      if ( ModuleHandleA == nullptr )
      {
        LibraryA = LoadLibraryA(lpLibFileName: this->m_strModuleName.m_pszData);
        this->m_hModule = LibraryA;
        this->m_bFreeLib = LibraryA != nullptr;
      }
    }
    this->m__ImageList_Draw.p = (int (__stdcall *)(struct _IMAGELIST *, int, HDC__ *, int, int, unsigned int))GetProcAddress(hModule: this->m_hModule, lpProcName: "ImageList_Draw");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *, int, HDC__ *, int, int, unsigned int))this->m__ImageList_Draw;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005B730
// Name: public: int CComCtlWrapper::_ImageList_Draw(struct _IMAGELIST __near *,int,struct HDC__ __near *,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_Draw(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        int i,
        HDC__ *hdcDst,
        int x,
        int y,
        unsigned int fStyle)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v10; // eax
  int (__stdcall *p)(struct _IMAGELIST *, int, HDC__ *, int, int, unsigned int); // esi
  int v13; // ebx
  int v14; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_Draw_Type v15; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v17; // [esp+14h] [ebp-1Ch]
  int v18; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v10 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v17 = 0;
  if ( !v10 )
    return 0;
  v18 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_Draw(this, result: &v15);
  p = this->m__ImageList_Draw.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v13 = ((int (__stdcall *)(struct _IMAGELIST *, int, HDC__ *, int, int, unsigned int, int))p)(
          a1: himl,
          a2: i,
          a3: hdcDst,
          a4: x,
          a5: y,
          a6: fStyle,
          a7: v14);
  v17 = v13;
  v18 = -1;
  if ( v13 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v13 == 0 )
    SetLastError(dwErrCode: LastError);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x1005B820
// Name: protected: virtual void CManifestMove::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMove::DoDataExchange(CManifestMove *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x68E, rControl: (HWND__ *)&this->m_FileNameControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x670, rControl: (HWND__ *)&this->m_CenterContentsControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x68F, rControl: (HWND__ *)&this->m_FriendlyNameControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x697, rControl: (HWND__ *)&this->m_FullPathNameControl);
}

//------------------------------------------------------------------------------
// Address: 0x1005B880
// Name: public: CManifestListBox::CManifestListBox(void)
// Source: json
//------------------------------------------------------------------------------
CManifestListBox *__thiscall CManifestListBox::CManifestListBox(CManifestListBox *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  HMENU v5; // eax
  HMENU v6; // eax

  CWnd::CWnd(this);
  this->__vftable = (CManifestListBox_vtbl *)&CListBox::`vftable';
  this->__vftable = (CManifestListBox_vtbl *)&CManifestListBox::`vftable';
  CImageList::CImageList(this: &this->m_Icons);
  this->m_ManifestFilterMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_ManifestFilterMenu.m_hMenu = nullptr;
  this->m_ManifestFilterSecondaryMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_ManifestFilterSecondaryMenu.m_hMenu = nullptr;
  this->m_ManifestFilterPrimaryMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_ManifestFilterPrimaryMenu.m_hMenu = nullptr;
  this->m_ManifestFilterBlankMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_ManifestFilterBlankMenu.m_hMenu = nullptr;
  CImageList::Create(this: &this->m_Icons, nBitmapID: 0x15Cu, cx: 16, nGrow: 1, crMask: 0xFFFF00u);
  ModuleState = AfxGetModuleState();
  MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0x15D);
  CMenu::Attach(this: &this->m_ManifestFilterMenu, hMenu: MenuW);
  SubMenu = GetSubMenu(hMenu: this->m_ManifestFilterMenu.m_hMenu, nPos: 0);
  CMenu::Attach(this: &this->m_ManifestFilterSecondaryMenu, hMenu: SubMenu);
  v5 = GetSubMenu(hMenu: this->m_ManifestFilterMenu.m_hMenu, nPos: 1);
  CMenu::Attach(this: &this->m_ManifestFilterPrimaryMenu, hMenu: v5);
  v6 = GetSubMenu(hMenu: this->m_ManifestFilterMenu.m_hMenu, nPos: 2);
  CMenu::Attach(this: &this->m_ManifestFilterBlankMenu, hMenu: v6);
  this->m_pTrackerManifestMap = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005B9F0
// Name: public: void CManifestListBox::OnLButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnLButtonDblClk(CManifestListBox *this, unsigned int nFlags, CPoint point)
{
  int bOutside; // [esp+4h] [ebp-4h] BYREF

  this->m_pTrackerManifestMap = nullptr;
  CListBox::ItemFromPoint(this, pt: point, &bOutside);
  if ( bOutside == 0 && point.x >= 36 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005BA30
// Name: public: void CManifestListBox::OnVersionControlCheckOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnVersionControlCheckOut(CManifestListBox *this)
{
  CManifest *v2; // edi
  const char *v3; // eax
  char temp[2048]; // [esp+4h] [ebp-800h] BYREF

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v2 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      if ( p4->OpenFileForEdit(this: p4, a2: this->m_pTrackerManifestMap->m_AbsoluteMapFileName.m_pszData) )
      {
        CManifest::CheckFileStatus(this: v2);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      }
      else
      {
        v3 = p4->GetLastError(this: p4);
        sprintf(string: temp, format: "Could not check out map: %s", v3);
        AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BAD0
// Name: public: void CManifestListBox::OnVersionControlAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnVersionControlAdd(CManifestListBox *this)
{
  CManifest *v2; // edi
  const char *v3; // eax
  char temp[2048]; // [esp+4h] [ebp-800h] BYREF

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v2 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      if ( p4->OpenFileForAdd(this: p4, a2: this->m_pTrackerManifestMap->m_AbsoluteMapFileName.m_pszData) )
      {
        CManifest::CheckFileStatus(this: v2);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      }
      else
      {
        v3 = p4->GetLastError(this: p4);
        sprintf(string: temp, format: "Could not add map: %s", v3);
        AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BB70
// Name: public: virtual CManifestFilter::~CManifestFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestFilter::~CManifestFilter(CManifestFilter *this)
{
  this->__vftable = (CManifestFilter_vtbl *)&CManifestFilter::`vftable';
  CManifestListBox::~CManifestListBox(this: &this->m_ManifestList);
  CHammerBar::~CHammerBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005BBD0
// Name: public: struct HBRUSH__ __near * CManifestFilter::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CManifestFilter::OnCtlColor(CManifestFilter *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  HBRUSH__ *result; // eax
  CDC_vtbl *v5; // edi
  DWORD SysColor; // eax
  CDC_vtbl *v7; // edi
  DWORD v8; // eax

  if ( nCtlColor != 2 )
    return CControlBar::OnCtlColor(this, pDC, pWnd, nCtlColor);
  v5 = pDC->__vftable;
  SysColor = GetSysColor(nIndex: 8);
  v5->SetTextColor(this: pDC, a2: SysColor);
  v7 = pDC->__vftable;
  v8 = GetSysColor(nIndex: 15);
  v7->SetBkColor(this: pDC, a2: v8);
  result = (HBRUSH__ *)this->m_pBkBrush;
  if ( result != nullptr )
    return *((HBRUSH__ **)result + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005BC40
// Name: public: CManifestMapDlg::CManifestMapDlg(class CManifestMap __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CManifestMapDlg *__thiscall CManifestMapDlg::CManifestMapDlg(
        CManifestMapDlg *this,
        CManifestMap *pManifestMap,
        CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x15Eu, pParentWnd: pParent);
  this->__vftable = (CManifestMapDlg_vtbl *)&CManifestMapDlg::`vftable';
  CWnd::CWnd(this: &this->m_FriendlyNameControl);
  this->m_FriendlyNameControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_FullFileNameCtrl);
  this->m_FullFileNameCtrl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  this->m_pManifestMap = pManifestMap;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005BD60
// Name: protected: virtual void CManifestMapDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMapDlg::DoDataExchange(CManifestMapDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_FriendlyNameControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x68F, rControl: (HWND__ *)&this->m_FullFileNameCtrl);
}

//------------------------------------------------------------------------------
// Address: 0x1005BDA0
// Name: public: virtual int CManifestMapDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CManifestMapDlg::OnInitDialog(CManifestMapDlg *this)
{
  CDialog::OnInitDialog(this);
  CWnd::SetWindowTextA(this: &this->m_FriendlyNameControl, lpszString: this->m_pManifestMap->m_FriendlyName.m_pszData);
  CWnd::SetWindowTextA(
    this: &this->m_FullFileNameCtrl,
    lpszString: this->m_pManifestMap->m_AbsoluteMapFileName.m_pszData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005BDE0
// Name: public: CManifestCheckin::CManifestCheckin(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CManifestCheckin *__thiscall CManifestCheckin::CManifestCheckin(CManifestCheckin *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x163u, pParentWnd: pParent);
  this->__vftable = (CManifestCheckin_vtbl *)&CManifestCheckin::`vftable';
  CWnd::CWnd(this: &this->m_CheckinListCtrl);
  this->m_CheckinListCtrl.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::CWnd(this: &this->m_DescriptionCtrl);
  this->m_DescriptionCtrl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005BEF0
// Name: protected: virtual void CManifestCheckin::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestCheckin::DoDataExchange(CManifestCheckin *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A5, rControl: (HWND__ *)&this->m_CheckinListCtrl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_DescriptionCtrl);
}

//------------------------------------------------------------------------------
// Address: 0x1005BF30
// Name: int AfxImageList_Draw(struct _IMAGELIST __near *,int,struct HDC__ __near *,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall AfxImageList_Draw(struct _IMAGELIST *himl, int i, HDC__ *hdcDst, int x, int y, unsigned int fStyle)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_Draw(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl,
           i,
           hdcDst,
           x,
           y,
           fStyle);
}

//------------------------------------------------------------------------------
// Address: 0x1005BF60
// Name: public: int CImageList::Draw(class CDC __near *,int,struct tagPOINT,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImageList::Draw(CImageList *this, HDC__ *pDC, int nImage, tagPOINT pt, unsigned int nStyle)
{
  HDC__ *v5; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  struct _IMAGELIST *m_hImageList; // [esp-18h] [ebp-18h]
  HDC__ *v9; // [esp-10h] [ebp-10h]

  v5 = pDC;
  if ( pDC != nullptr )
    v5 = *((HDC__ **)pDC + 1);
  v9 = v5;
  m_hImageList = this->m_hImageList;
  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_Draw(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl: m_hImageList,
           i: nImage,
           hdcDst: v9,
           x: pt.x,
           y: pt.y,
           fStyle: nStyle);
}

//------------------------------------------------------------------------------
// Address: 0x1005BFA0
// Name: protected: void CManifestListBox::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnLButtonDown(CManifestListBox *this, unsigned int nFlags, CPoint point)
{
  WPARAM v4; // ebx
  CManifest *v5; // edi
  CManifestMap *v6; // ecx
  LRESULT height; // [esp+8h] [ebp-8h]
  int bOutside; // [esp+Ch] [ebp-4h] BYREF

  this->m_pTrackerManifestMap = nullptr;
  v4 = CListBox::ItemFromPoint(this, pt: point, &bOutside);
  if ( bOutside == 0 )
  {
    height = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A1u, wParam: v4, lParam: 0);
    if ( point.x >= 36 )
    {
      CWnd::Default(this);
    }
    else if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v5 = CMapDoc::m_pManifest;
      if ( CMapDoc::m_pManifest != nullptr )
      {
        v6 = v5->m_Maps.m_Memory.m_pMemory[SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam: v4, lParam: 0)];
        if ( v6 != nullptr && point.x < 18 && point.y % height < 18 )
          CManifest::SetVisibility(this: v5, pManifestMap: v6, bIsVisible: !v6->m_bVisible);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C060
// Name: public: void CManifestListBox::OnRButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnRButtonUp(CManifestListBox *this, unsigned int nFlags, CPoint point)
{
  CMapDoc *v3; // edi
  CManifest *v5; // esi
  WPARAM v6; // eax
  CMenu *p_m_ManifestFilterBlankMenu; // esi
  CManifestMap *v8; // eax
  CManifestMap *m_pTrackerManifestMap; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-24h]
  CPoint ptScreen; // [esp+8h] [ebp-10h] BYREF
  CManifest *pManifest; // [esp+10h] [ebp-8h]
  int bOutside; // [esp+14h] [ebp-4h] BYREF

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v5 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      ptScreen.x = point.x;
      m_hWnd = this->m_hWnd;
      pManifest = CMapDoc::m_pManifest;
      this->m_pTrackerManifestMap = nullptr;
      ptScreen.y = point.y;
      ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
      v6 = CListBox::ItemFromPoint(this, pt: point, &bOutside);
      if ( bOutside != 0 )
      {
        p_m_ManifestFilterBlankMenu = &this->m_ManifestFilterBlankMenu;
      }
      else
      {
        v8 = v5->m_Maps.m_Memory.m_pMemory[SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam: v6, lParam: 0)];
        this->m_pTrackerManifestMap = v8;
        p_m_ManifestFilterBlankMenu = &this->m_ManifestFilterPrimaryMenu;
        if ( !v8->m_bPrimaryMap )
          p_m_ManifestFilterBlankMenu = &this->m_ManifestFilterSecondaryMenu;
      }
      if ( CSelection::IsEmpty(this: v3->m_pSelection) )
      {
        EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81DEu, uEnable: 3u);
        EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81DFu, uEnable: 3u);
      }
      else
      {
        EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81DEu, uEnable: 0);
        EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81DFu, uEnable: 0);
      }
      if ( pManifest->m_Maps.m_Size <= 1 )
        EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x8200u, uEnable: 3u);
      else
        EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x8200u, uEnable: 0);
      EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81E0u, uEnable: 3u);
      EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81EAu, uEnable: 3u);
      EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x820Au, uEnable: 3u);
      if ( p4 != nullptr )
      {
        m_pTrackerManifestMap = this->m_pTrackerManifestMap;
        if ( m_pTrackerManifestMap != nullptr )
        {
          if ( m_pTrackerManifestMap->m_bIsVersionControlled )
          {
            if ( m_pTrackerManifestMap->m_bCheckedOut )
              EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81EAu, uEnable: 0);
            else
              EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x81E0u, uEnable: 0);
          }
          else
          {
            EnableMenuItem(hMenu: p_m_ManifestFilterBlankMenu->m_hMenu, uIDEnableItem: 0x820Au, uEnable: 0);
          }
        }
      }
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      CMenu::TrackPopupMenu(
        this: p_m_ManifestFilterBlankMenu,
        nFlags: 2u,
        x: ptScreen.x,
        y: ptScreen.y,
        pWnd: this,
        lpRect: nullptr);
      CWnd::Default(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C210
// Name: public: void CManifestListBox::OnVersionControlCheckIn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnVersionControlCheckIn(CManifestListBox *this)
{
  CManifest *v2; // esi
  int v3; // eax
  CManifestMap *v4; // ecx
  CManifestMap *m_pTrackerManifestMap; // eax
  CManifestCheckin ManifestCheckin; // [esp+4h] [ebp-190h] BYREF
  CManifestListBox *v7; // [esp+180h] [ebp-14h]
  void *p_m_CheckinListCtrl; // [esp+184h] [ebp-10h]
  int v9; // [esp+190h] [ebp-4h]

  v7 = this;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v2 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      v3 = 0;
      for ( CMapDoc::m_pManifest->m_bDefaultCheckin = false; v3 < v2->m_Maps.m_Size; v4->m_bDefaultCheckin = false )
        v4 = v2->m_Maps.m_Memory.m_pMemory[v3++];
      m_pTrackerManifestMap = this->m_pTrackerManifestMap;
      if ( m_pTrackerManifestMap != nullptr )
        m_pTrackerManifestMap->m_bDefaultCheckin = true;
      CDialog::CDialog(this: &ManifestCheckin, nIDTemplate: 0x163u, pParentWnd: nullptr);
      v9 = 0;
      ManifestCheckin.__vftable = (CManifestCheckin_vtbl *)&CManifestCheckin::`vftable';
      p_m_CheckinListCtrl = &ManifestCheckin.m_CheckinListCtrl;
      CWnd::CWnd(this: &ManifestCheckin.m_CheckinListCtrl);
      ManifestCheckin.m_CheckinListCtrl.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
      LOBYTE(v9) = 2;
      p_m_CheckinListCtrl = &ManifestCheckin.m_DescriptionCtrl;
      CWnd::CWnd(this: &ManifestCheckin.m_DescriptionCtrl);
      ManifestCheckin.m_DescriptionCtrl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
      v9 = 5;
      if ( CDialog::DoModal(this: &ManifestCheckin) == 1 )
      {
        CManifest::CheckFileStatus(this: v2);
        InvalidateRect(hWnd: v7->m_hWnd, lpRect: nullptr, bErase: true);
      }
      ManifestCheckin.__vftable = (CManifestCheckin_vtbl *)&CManifestCheckin::`vftable';
      v9 = 7;
      CEdit::~CEdit(this: &ManifestCheckin.m_DescriptionCtrl);
      LOBYTE(v9) = 6;
      CListCtrl::~CListCtrl(this: &ManifestCheckin.m_CheckinListCtrl);
      v9 = -1;
      CDialog::~CDialog(this: &ManifestCheckin);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C360
// Name: public: void CManifestListBox::OnManifestProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnManifestProperties(CManifestListBox *this)
{
  CManifestMap *m_pTrackerManifestMap; // eax
  CManifest *v3; // edi
  CManifestMapDlg ManifestMapDlg; // [esp+4h] [ebp-18Ch] BYREF
  int v5; // [esp+18Ch] [ebp-4h]

  m_pTrackerManifestMap = this->m_pTrackerManifestMap;
  if ( m_pTrackerManifestMap != nullptr && CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      CManifestMapDlg::CManifestMapDlg(this: &ManifestMapDlg, pManifestMap: m_pTrackerManifestMap, pParent: this);
      v5 = 0;
      if ( CDialog::DoModal(this: &ManifestMapDlg) == 1 )
      {
        CManifest::SetManifestPrefsModifiedFlag(this: v3, bModified: true);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      }
      v5 = -1;
      CManifestMapDlg::~CManifestMapDlg(this: &ManifestMapDlg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C400
// Name: public: void CManifestListBox::OnManifestRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnManifestRemove(CManifestListBox *this)
{
  CManifest *v2; // esi

  if ( this->m_pTrackerManifestMap != nullptr && CMapDoc::m_pMapDoc != nullptr )
  {
    v2 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr
      && AfxMessageBox(
           lpszText: "Are you sure you want to remove this sub map from the manifest?",
           nType: 0x24u,
           nIDHelp: 0) != 7 )
    {
      CManifest::RemoveSubMap(this: v2, pManifestMap: this->m_pTrackerManifestMap);
      CManifest::SetPrimaryMap(this: v2, a2: (int)this, pManifestMap: *v2->m_Maps.m_Memory.m_pMemory);
      this->m_pTrackerManifestMap = nullptr;
      AfxMessageBox(
        lpszText: "The sub map has been removed from the manifest, but the file has not been deleted.",
        nType: 0x40u,
        nIDHelp: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C470
// Name: public: void CManifestFilter::UpdateManifestList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestFilter::UpdateManifestList(CManifestFilter *this)
{
  LPARAM v2; // edi
  WPARAM v3; // esi
  int *p_m_Size; // [esp+4h] [ebp-Ch]
  CManifestMap *pManifestMap; // [esp+8h] [ebp-8h]
  CUtlVector<CManifestMap *,CUtlMemory<CManifestMap *,int> > *p_m_Maps; // [esp+Ch] [ebp-4h]

  SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
  {
    v2 = 0;
    p_m_Size = &CMapDoc::m_pManifest->m_Maps.m_Size;
    if ( CMapDoc::m_pManifest->m_Maps.m_Size > 0 )
    {
      p_m_Maps = &CMapDoc::m_pManifest->m_Maps;
      do
      {
        pManifestMap = p_m_Maps->m_Memory.m_pMemory[v2];
        v3 = SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)"Manifest");
        SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x19Au, wParam: v3, lParam: v2);
        if ( pManifestMap->m_bPrimaryMap )
          SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x186u, wParam: v3, lParam: 0);
        ++v2;
      }
      while ( v2 < *p_m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C530
// Name: public: void CManifestFilter::OnLbnSelchangeManifestList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestFilter::OnLbnSelchangeManifestList(CManifestFilter *this)
{
  LRESULT v2; // eax
  CManifest *v3; // esi
  LRESULT v4; // eax
  WPARAM nIndex; // [esp+Ch] [ebp-4h]

  nIndex = SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v2 = SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  if ( nIndex != -1 && v2 > 1 && CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      v4 = SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x199u, wParam: nIndex, lParam: 0);
      CManifest::SetPrimaryMap(this: v3, a2: (int)this, pManifestMap: v3->m_Maps.m_Memory.m_pMemory[v4]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C5C0
// Name: public: void CManifestFilter::OnLbnDblClkManifestList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestFilter::OnLbnDblClkManifestList(CManifestFilter *this)
{
  WPARAM v2; // eax
  CManifest *v3; // edi
  LRESULT v4; // eax
  CManifestMapDlg ManifestMapDlg; // [esp+8h] [ebp-18Ch] BYREF
  int v6; // [esp+190h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v2 != -1 && CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = CMapDoc::m_pManifest;
    if ( CMapDoc::m_pManifest != nullptr )
    {
      v4 = SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
      CManifestMapDlg::CManifestMapDlg(
        this: &ManifestMapDlg,
        pManifestMap: v3->m_Maps.m_Memory.m_pMemory[v4],
        pParent: this);
      v6 = 0;
      if ( CDialog::DoModal(this: &ManifestMapDlg) == 1 )
      {
        CManifest::SetManifestPrefsModifiedFlag(this: v3, bModified: true);
        InvalidateRect(hWnd: this->m_ManifestList.m_hWnd, lpRect: nullptr, bErase: true);
      }
      v6 = -1;
      CManifestMapDlg::~CManifestMapDlg(this: &ManifestMapDlg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C690
// Name: public: virtual int CManifestCheckin::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CManifestCheckin::OnInitDialog(CManifestCheckin *this)
{
  LRESULT v2; // eax
  CListCtrl *p_m_CheckinListCtrl; // esi
  CManifest *v4; // ebx
  bool v5; // zf
  int inserted; // ebx
  __int16 v7; // ecx^2
  const char *v8; // eax
  __int16 v9; // ecx^2
  const char *v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  WPARAM v14; // edi
  __int16 v15; // ecx^2
  const char *v16; // eax
  __int16 v17; // ecx^2
  const char *v18; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-88h]
  HWND v21; // [esp-10h] [ebp-88h]
  int v22; // [esp-4h] [ebp-7Ch]
  int v23; // [esp-4h] [ebp-7Ch]
  int v24; // [esp-4h] [ebp-7Ch]
  int v25; // [esp-4h] [ebp-7Ch]
  tagLVITEMA _macro_lvi; // [esp+Ch] [ebp-6Ch] BYREF
  P4File_t FileInfo; // [esp+48h] [ebp-30h] BYREF
  CManifestCheckin *v28; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  int nCount; // [esp+70h] [ebp-8h]
  CManifest *pManifest; // [esp+74h] [ebp-4h]

  v28 = this;
  memset(&FileInfo, 255, 10);
  CDialog::OnInitDialog(this);
  v2 = SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1037u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1036u, wParam: 0, lParam: v2 | 0x24);
  p_m_CheckinListCtrl = &this->m_CheckinListCtrl;
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 0,
    lpszColumnHeading: &var,
    nFormat: 0,
    nWidth: 30,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 1,
    lpszColumnHeading: "Status",
    nFormat: 0,
    nWidth: 50,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 2,
    lpszColumnHeading: "Name",
    nFormat: 0,
    nWidth: 100,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 3,
    lpszColumnHeading: "Folder",
    nFormat: 0,
    nWidth: 350,
    nSubItem: -1);
  if ( p4 != nullptr )
  {
    nCount = 0;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v4 = CMapDoc::m_pManifest;
      if ( CMapDoc::m_pManifest != nullptr )
      {
        v5 = !CMapDoc::m_pManifest->m_bCheckedOut;
        pManifest = CMapDoc::m_pManifest;
        if ( !v5 && p4->GetFileInfo(this: p4, a2: CMapDoc::m_pManifest->m_strPathName.m_pszData, a3: &FileInfo) )
        {
          inserted = CListCtrl::InsertItem(
                       this: &this->m_CheckinListCtrl,
                       nMask: 1u,
                       nItem: 0,
                       lpszItem: &var,
                       nState: 0,
                       nStateMask: 0,
                       nImage: 0,
                       lParam: 0);
          nCount = 1;
          CListCtrl::SetItemData(this: &this->m_CheckinListCtrl, nItem: inserted, dwData: 0);
          if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_ADD )
          {
            CListCtrl::SetItemText(this: &this->m_CheckinListCtrl, nItem: inserted, nSubItem: 1, lpszText: "Add");
          }
          else if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_EDIT )
          {
            CListCtrl::SetItemText(this: &this->m_CheckinListCtrl, nItem: inserted, nSubItem: 1, lpszText: "Edit");
          }
          HIWORD(v22) = v7;
          LOWORD(v22) = FileInfo.m_sName.m_Id;
          v8 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v22);
          CListCtrl::SetItemText(this: &this->m_CheckinListCtrl, nItem: inserted, nSubItem: 2, lpszText: v8);
          HIWORD(v23) = v9;
          LOWORD(v23) = FileInfo.m_sPath.m_Id;
          v10 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v23);
          CListCtrl::SetItemText(this: &this->m_CheckinListCtrl, nItem: inserted, nSubItem: 3, lpszText: v10);
          if ( pManifest->m_bDefaultCheckin )
          {
            m_hWnd = this->m_CheckinListCtrl.m_hWnd;
            _macro_lvi.stateMask = 61440;
            _macro_lvi.state = 0x2000;
            SendMessageA(hWnd: m_hWnd, Msg: 0x102Bu, wParam: inserted, lParam: (LPARAM)&_macro_lvi);
          }
          v4 = pManifest;
        }
        v11 = 0;
        i = 0;
        if ( v4->m_Maps.m_Size > 0 )
        {
          while ( 1 )
          {
            v12 = (int)v4->m_Maps.m_Memory.m_pMemory[v11];
            if ( *(_BYTE *)(v12 + 19) != 0 && p4->GetFileInfo(this: p4, a2: *(const char **)(v12 + 8), a3: &FileInfo) )
            {
              v13 = CListCtrl::InsertItem(
                      this: p_m_CheckinListCtrl,
                      nMask: 1u,
                      nItem: nCount++,
                      lpszItem: &var,
                      nState: 0,
                      nStateMask: 0,
                      nImage: 0,
                      lParam: 0);
              v14 = v13;
              CListCtrl::SetItem(
                this: p_m_CheckinListCtrl,
                nItem: v13,
                nSubItem: 0,
                nMask: 4u,
                lpszItem: nullptr,
                nImage: 0,
                nState: 0,
                nStateMask: 0,
                lParam: v12);
              if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_ADD )
              {
                CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: v14, nSubItem: 1, lpszText: "Add");
              }
              else if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_EDIT )
              {
                CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: v14, nSubItem: 1, lpszText: "Edit");
              }
              HIWORD(v24) = v15;
              LOWORD(v24) = FileInfo.m_sName.m_Id;
              v16 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v24);
              CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: v14, nSubItem: 2, lpszText: v16);
              HIWORD(v25) = v17;
              LOWORD(v25) = FileInfo.m_sPath.m_Id;
              v18 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v25);
              CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: v14, nSubItem: 3, lpszText: v18);
              if ( *(_BYTE *)(v12 + 20) != 0 )
              {
                v21 = v28->m_CheckinListCtrl.m_hWnd;
                _macro_lvi.stateMask = 61440;
                _macro_lvi.state = 0x2000;
                SendMessageA(hWnd: v21, Msg: 0x102Bu, wParam: v14, lParam: (LPARAM)&_macro_lvi);
              }
            }
            v11 = i + 1;
            i = v11;
            if ( v11 >= pManifest->m_Maps.m_Size )
              break;
            v4 = pManifest;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005C9B0
// Name: public: CManifestMove::CManifestMove(bool,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CManifestMove *__thiscall CManifestMove::CManifestMove(CManifestMove *this, bool bIsMove, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax

  CDialog::CDialog(this, nIDTemplate: 0x157u, pParentWnd: pParent);
  this->__vftable = (CManifestMove_vtbl *)&CManifestMove::`vftable';
  CWnd::CWnd(this: &this->m_FileNameControl);
  this->m_FileNameControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_CenterContentsControl);
  this->m_CenterContentsControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_FriendlyNameControl);
  this->m_FriendlyNameControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_FullPathNameControl);
  this->m_FullPathNameControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_FriendlyName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_FileName.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  this->m_bIsMove = bIsMove;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005CB00
// Name: public: virtual CManifestMove::~CManifestMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMove::~CManifestMove(CManifestMove *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax

  this->__vftable = (CManifestMove_vtbl *)&CManifestMove::`vftable';
  v2 = (volatile signed __int32 *)(this->m_FileName.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_FriendlyName.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  CStatic::~CStatic(this: &this->m_FullPathNameControl);
  CEdit::~CEdit(this: &this->m_FriendlyNameControl);
  CButton::~CButton(this: &this->m_CenterContentsControl);
  CEdit::~CEdit(this: &this->m_FileNameControl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005CBF0
// Name: public: int CManifestFilter::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CManifestFilter::Create(CManifestFilter *this, CWnd *pParentWnd)
{
  int result; // eax
  CBrush *v4; // edi
  COLORREF SysColor; // eax
  CBrush *v6; // eax

  result = CHammerBar::Create(
             this,
             pParentWnd,
             nIDTemplate: 0x15Bu,
             nStyle: 0x4104u,
             nID: 0xE811u,
             pszName: "Manifest Control");
  if ( result != 0 )
  {
    CWnd::SubclassDlgItem(this: &this->m_ManifestList, nID: 0x68Du, pParent: this);
    SendMessageA(hWnd: this->m_ManifestList.m_hWnd, Msg: 0x1A0u, wParam: 0, lParam: 36);
    CHammerBar::AddControl(this, nIDTemplate: 1677, dwPlacementFlag: 4u);
    CManifestFilter::UpdateManifestList(this);
    v4 = (CBrush *)operator new(nSize: 8u);
    if ( v4 != nullptr )
    {
      SysColor = GetSysColor(nIndex: 15);
      v6 = CBrush::CBrush(this: v4, crColor: SysColor);
    }
    else
    {
      v6 = nullptr;
    }
    this->m_pBkBrush = v6;
    this->bInitialized = 1;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005CCE0
// Name: public: void CManifestCheckin::OnBnClickedOk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestCheckin::OnBnClickedOk(CManifestCheckin *this)
{
  signed int v1; // edi
  LRESULT (__stdcall *v3)(HWND, UINT, WPARAM, LPARAM); // ebx
  int v4; // edi
  CAfxStringMgr *StringManager; // eax
  char *v6; // eax
  bool v7; // cc
  void *v8; // esp
  HWND__ *v9; // ecx
  int v10; // edi
  unsigned int ItemData; // eax
  const char *v12; // eax
  char *v13; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-838h]
  int v15; // [esp+0h] [ebp-828h] BYREF
  char temp[2048]; // [esp+Ch] [ebp-81Ch] BYREF
  CManifest *pManifest; // [esp+80Ch] [ebp-1Ch]
  const char **ppFileNames; // [esp+810h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > Description; // [esp+814h] [ebp-14h] BYREF
  int nFileCount; // [esp+818h] [ebp-10h]
  int v21; // [esp+824h] [ebp-4h]

  v1 = 0;
  nFileCount = 0;
  if ( CMapDoc::m_pMapDoc == nullptr || CMapDoc::m_pManifest == nullptr )
    this->OnOK(this);
  v3 = SendMessageA;
  m_hWnd = this->m_CheckinListCtrl.m_hWnd;
  pManifest = CMapDoc::m_pManifest;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) <= 0 )
    goto LABEL_26;
  do
  {
    if ( SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v1, lParam: 61440) == 0x2000 )
      ++nFileCount;
    ++v1;
  }
  while ( v1 < SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
  v4 = nFileCount;
  if ( nFileCount <= 0 )
    goto LABEL_26;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  Description.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v21 = 1;
  CWnd::GetWindowTextA(this: &this->m_DescriptionCtrl, rString: &Description);
  if ( *((int *)Description.m_pszData - 3) < 2 )
  {
    AfxMessageBox(
      lpszText: "Please put in something descriptive for the description.  I took the time to type this dialog, the least you could"
      " do is type something!",
      nType: 0x10u,
      nIDHelp: 0);
    v21 = -1;
    v6 = Description.m_pszData - 16;
    v7 = _InterlockedDecrement((volatile signed __int32 *)Description.m_pszData - 1) <= 0;
    goto LABEL_13;
  }
  v8 = alloca(4 * v4);
  v9 = this->m_CheckinListCtrl.m_hWnd;
  ppFileNames = (const char **)&v15;
  v10 = 0;
  nFileCount = 0;
  if ( SendMessageA(hWnd: v9, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
  {
    do
    {
      if ( v3(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v10, lParam: 61440) == 0x2000 )
      {
        ItemData = CListCtrl::GetItemData(this: &this->m_CheckinListCtrl, nItem: v10);
        if ( ItemData != 0 )
        {
          ppFileNames[nFileCount] = *(const char **)(ItemData + 8);
          CMapDoc::SaveVMF(this: *(CMapDoc **)ItemData, pszFileName: *(const char **)(ItemData + 8), saveFlags: 0);
          v3 = SendMessageA;
        }
        else
        {
          ppFileNames[nFileCount] = pManifest->m_strPathName.m_pszData;
          CManifest::SaveVMFManifest(this: pManifest, pszFileName: pManifest->m_strPathName.m_pszData);
        }
        ++nFileCount;
      }
      ++v10;
    }
    while ( v10 < v3(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
  }
  if ( p4->SubmitFiles(this: p4, a2: nFileCount, a3: ppFileNames, a4: Description.m_pszData) )
  {
    v21 = -1;
    v13 = Description.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)Description.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
LABEL_26:
    this->OnOK(this);
    return;
  }
  v12 = p4->GetLastError(this: p4);
  sprintf(string: temp, format: "Could not check in map(s): %s", v12);
  AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
  v21 = -1;
  v6 = Description.m_pszData - 16;
  v7 = _InterlockedDecrement((volatile signed __int32 *)Description.m_pszData - 1) <= 0;
LABEL_13:
  if ( v7 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1005CFB0
// Name: protected: virtual struct AFX_MSGMAP const __near * CManifestFilter::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CManifestFilter::GetMessageMap(CManifestFilter *this)
{
  return (const AFX_MSGMAP *)&off_105DE8D0;
}

//------------------------------------------------------------------------------
// Address: 0x1005CFC0
// Name: protected: virtual struct AFX_MSGMAP const __near * CManifestCheckin::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CManifestCheckin::GetMessageMap(CManifestCheckin *this)
{
  return (const AFX_MSGMAP *)&off_105DEA14;
}

//------------------------------------------------------------------------------
// Address: 0x1005CFD0
// Name: public: virtual void CManifestListBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::DrawItem(CManifestListBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  CManifestMap *v2; // ebx
  tagRECT *p_rcItem; // esi
  HDC__ *hDC; // eax
  COLORREF SysColor; // eax
  HPEN Pen; // eax
  COLORREF v7; // eax
  COLORREF v8; // eax
  COLORREF v9; // eax
  int v10; // eax
  int v11; // ecx
  COLORREF v12; // eax
  COLORREF v13; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  int v15; // ecx
  COLORREF v16; // eax
  COLORREF v17; // eax
  struct _IMAGELIST *v18; // eax
  AFX_MODULE_STATE *v19; // eax
  int v20; // eax
  int v21; // ecx
  COLORREF v22; // eax
  COLORREF v23; // eax
  AFX_MODULE_STATE *v24; // eax
  COLORREF v25; // eax
  COLORREF v26; // eax
  int left; // edx
  int right; // ecx
  const char *m_pszData; // ebx
  int bottom; // edx
  struct _IMAGELIST *m_hImageList; // [esp-18h] [ebp-7Ch]
  struct _IMAGELIST *v32; // [esp-18h] [ebp-7Ch]
  struct _IMAGELIST *v33; // [esp-18h] [ebp-7Ch]
  int v34; // [esp-14h] [ebp-78h]
  HDC__ *m_hDC; // [esp-10h] [ebp-74h]
  HDC__ *v36; // [esp-10h] [ebp-74h]
  HDC__ *v37; // [esp-10h] [ebp-74h]
  COLORREF v38; // [esp-4h] [ebp-68h]
  COLORREF v39; // [esp-4h] [ebp-68h]
  COLORREF v40; // [esp-4h] [ebp-68h]
  tagRECT ItemRect; // [esp+Ch] [ebp-58h] BYREF
  tagRECT VisibleRect; // [esp+1Ch] [ebp-48h] BYREF
  CDC dc; // [esp+2Ch] [ebp-38h] BYREF
  CPen m_hPen; // [esp+3Ch] [ebp-28h] BYREF
  tagPOINT p; // [esp+44h] [ebp-20h] BYREF
  CPen *pOldPen; // [esp+4Ch] [ebp-18h]
  int iForeIndex; // [esp+50h] [ebp-14h]
  CManifestListBox *v48; // [esp+54h] [ebp-10h]
  int v49; // [esp+60h] [ebp-4h]
  tagPOINT v50; // 0:^C.8
  tagPOINT v51; // 0:^C.8
  tagPOINT v52; // 0:^C.8

  v48 = this;
  CDC::CDC(this: &dc);
  v2 = nullptr;
  v49 = 0;
  p_rcItem = &lpDrawItemStruct->rcItem;
  hDC = lpDrawItemStruct->hDC;
  *(_QWORD *)&ItemRect.left = *(_QWORD *)&lpDrawItemStruct->rcItem.left;
  ItemRect.left += 36;
  *(_QWORD *)&ItemRect.right = *(_QWORD *)&lpDrawItemStruct->rcItem.right;
  CDC::Attach(this: &dc, hDC);
  CDC::SetROP2(this: &dc, nDrawMode: 13);
  m_hPen.m_hObject = nullptr;
  m_hPen.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v49) = 2;
  SysColor = GetSysColor(nIndex: 16);
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: SysColor);
  CGdiObject::Attach(this: &m_hPen, hObject: Pen);
  pOldPen = (CPen *)CDC::SelectObject(this: &dc, pFont: (CFont *)&m_hPen);
  iForeIndex = 8;
  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
    v2 = CMapDoc::m_pManifest->m_Maps.m_Memory.m_pMemory[lpDrawItemStruct->itemData];
  v7 = GetSysColor(nIndex: 15);
  CDC::FillSolidRect(this: &dc, lpRect: p_rcItem, clr: v7);
  if ( (lpDrawItemStruct->itemState & 1) != 0 )
  {
    v8 = GetSysColor(nIndex: 13);
    CDC::FillSolidRect(this: &dc, lpRect: &ItemRect, clr: v8);
    iForeIndex = 14;
  }
  else if ( v48->m_pTrackerManifestMap == v2 )
  {
    v9 = GetSysColor(nIndex: 3);
    CDC::FillSolidRect(this: &dc, lpRect: &ItemRect, clr: v9);
  }
  CDC::MoveTo(this: &dc, result: (CPoint *)&p, x: lpDrawItemStruct->rcItem.left, y: lpDrawItemStruct->rcItem.top);
  CDC::LineTo(this: &dc, x: lpDrawItemStruct->rcItem.right, y: lpDrawItemStruct->rcItem.top);
  CDC::MoveTo(this: &dc, result: (CPoint *)&p, x: lpDrawItemStruct->rcItem.left, y: lpDrawItemStruct->rcItem.bottom);
  CDC::LineTo(this: &dc, x: lpDrawItemStruct->rcItem.right, y: lpDrawItemStruct->rcItem.bottom);
  CDC::MoveTo(this: &dc, result: (CPoint *)&p, x: lpDrawItemStruct->rcItem.left + 35, y: lpDrawItemStruct->rcItem.top);
  CDC::LineTo(this: &dc, x: lpDrawItemStruct->rcItem.left + 35, y: lpDrawItemStruct->rcItem.bottom);
  if ( v2 != nullptr )
  {
    v10 = p_rcItem->left + 1;
    v11 = lpDrawItemStruct->rcItem.top + 2;
    VisibleRect.right = p_rcItem->left + 17;
    VisibleRect.left = v10;
    VisibleRect.top = v11;
    VisibleRect.bottom = v11 + 16;
    p.x = v10;
    p.y = v11;
    v12 = GetSysColor(nIndex: 15);
    CDC::FillSolidRect(this: &dc, lpRect: &VisibleRect, clr: v12);
    v38 = GetSysColor(nIndex: 20);
    v13 = GetSysColor(nIndex: 16);
    CDC::Draw3dRect(this: &dc, lpRect: &VisibleRect, clrTopLeft: v13, clrBottomRight: v38);
    if ( v2->m_bVisible )
    {
      v50 = p;
      m_hDC = dc.m_hDC;
      m_hImageList = v48->m_Icons.m_hImageList;
      ModuleState = AfxGetModuleState();
      CComCtlWrapper::_ImageList_Draw(
        this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
        himl: m_hImageList,
        i: 0,
        hdcDst: m_hDC,
        x: v50.x,
        y: v50.y,
        fStyle: 0);
    }
    v15 = p_rcItem->left + 34;
    VisibleRect.left = p_rcItem->left + 18;
    VisibleRect.right = v15;
    p.x = VisibleRect.left;
    p.y = VisibleRect.top;
    v16 = GetSysColor(nIndex: 15);
    CDC::FillSolidRect(this: &dc, lpRect: &VisibleRect, clr: v16);
    v39 = GetSysColor(nIndex: 20);
    v17 = GetSysColor(nIndex: 16);
    CDC::Draw3dRect(this: &dc, lpRect: &VisibleRect, clrTopLeft: v17, clrBottomRight: v39);
    if ( v2->m_bProtected )
    {
      v18 = v48->m_Icons.m_hImageList;
      v51 = p;
      v36 = dc.m_hDC;
      v34 = 1;
    }
    else
    {
      if ( !v2->m_bReadOnly )
      {
        if ( v2->m_bCheckedOut )
          CImageList::Draw(this: &v48->m_Icons, pDC: (HDC__ *)&dc, nImage: 3, pt: p, nStyle: 0);
        goto LABEL_18;
      }
      v18 = v48->m_Icons.m_hImageList;
      v51 = p;
      v36 = dc.m_hDC;
      v34 = 2;
    }
    v32 = v18;
    v19 = AfxGetModuleState();
    CComCtlWrapper::_ImageList_Draw(
      this: *(CComCtlWrapper **)v19->m_pDllIsolationWrappers,
      himl: v32,
      i: v34,
      hdcDst: v36,
      x: v51.x,
      y: v51.y,
      fStyle: 0);
LABEL_18:
    v20 = p_rcItem->left + 18;
    v21 = lpDrawItemStruct->rcItem.top + 19;
    VisibleRect.right = p_rcItem->left + 34;
    VisibleRect.left = v20;
    VisibleRect.top = v21;
    VisibleRect.bottom = v21 + 16;
    p.x = v20;
    p.y = v21;
    v22 = GetSysColor(nIndex: 15);
    CDC::FillSolidRect(this: &dc, lpRect: &VisibleRect, clr: v22);
    v40 = GetSysColor(nIndex: 20);
    v23 = GetSysColor(nIndex: 16);
    CDC::Draw3dRect(this: &dc, lpRect: &VisibleRect, clrTopLeft: v23, clrBottomRight: v40);
    if ( v2->m_Map->IsModified(this: v2->m_Map) != 0 )
    {
      v52 = p;
      v37 = dc.m_hDC;
      v33 = v48->m_Icons.m_hImageList;
      v24 = AfxGetModuleState();
      CComCtlWrapper::_ImageList_Draw(
        this: *(CComCtlWrapper **)v24->m_pDllIsolationWrappers,
        himl: v33,
        i: 4,
        hdcDst: v37,
        x: v52.x,
        y: v52.y,
        fStyle: 0);
    }
    v25 = GetSysColor(nIndex: iForeIndex);
    CDC::SetTextColor(this: &dc, crColor: v25);
    v26 = GetSysColor(nIndex: 5);
    CDC::SetBkColor(this: &dc, crColor: v26);
    CDC::SetBkMode(this: &dc, nBkMode: 1);
    left = p_rcItem->left;
    right = lpDrawItemStruct->rcItem.right;
    m_pszData = v2->m_FriendlyName.m_pszData;
    VisibleRect.top = lpDrawItemStruct->rcItem.top + 1;
    VisibleRect.left = left + 36;
    bottom = lpDrawItemStruct->rcItem.bottom;
    VisibleRect.right = right - 1;
    VisibleRect.bottom = bottom - 1;
    DrawTextA(hdc: dc.m_hDC, lpchText: m_pszData, cchText: -1, lprc: &VisibleRect, format: 4u);
  }
  if ( (lpDrawItemStruct->itemState & 0x10) != 0 )
    DrawFocusRect(hDC: dc.m_hDC, lprc: &ItemRect);
  CDC::SelectObject(this: &dc, pFont: (CFont *)pOldPen);
  CDC::Detach(this: &dc);
  m_hPen.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v49) = 0;
  CGdiObject::~CGdiObject(this: &m_hPen);
  v49 = -1;
  CDC::~CDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x1005D3C0
// Name: public: void CManifestListBox::OnMoveSelectionToNewSubMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnMoveSelectionToNewSubMap(CManifestListBox *this)
{
  char *v1; // eax
  char *v2; // eax
  CManifestMove ManifestMove; // [esp+0h] [ebp-288h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > FileName; // [esp+274h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > FriendlyName; // [esp+278h] [ebp-10h] BYREF
  int v6; // [esp+284h] [ebp-4h]

  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
  {
    CManifestMove::CManifestMove(this: &ManifestMove, bIsMove: true, pParent: nullptr);
    v6 = 0;
    if ( CDialog::DoModal(this: &ManifestMove) == 1 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &FriendlyName);
      LOBYTE(v6) = 1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &FileName);
      LOBYTE(v6) = 2;
      ATL::CSimpleStringT<char,0>::operator=(
        this: &FriendlyName,
        strSrc: (ATL::CStringData *)&ManifestMove.m_FriendlyName);
      ATL::CSimpleStringT<char,0>::operator=(this: &FileName, strSrc: (ATL::CStringData *)&ManifestMove.m_FileName);
      CManifest::MoveSelectionToNewSubmap(
        this: CMapDoc::m_pManifest,
        &FriendlyName,
        &FileName,
        CenterContents: ManifestMove.m_CenterContents);
      LOBYTE(v6) = 1;
      v1 = FileName.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)FileName.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v1 + 4))(a1: v1);
      LOBYTE(v6) = 0;
      v2 = FriendlyName.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)FriendlyName.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v2 + 4))(a1: v2);
    }
    v6 = -1;
    CManifestMove::~CManifestMove(this: &ManifestMove);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D4D0
// Name: public: void CManifestListBox::OnInsertEmptySubMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::OnInsertEmptySubMap(CManifestListBox *this)
{
  char *v1; // eax
  char *v2; // eax
  CManifestMove ManifestMove; // [esp+0h] [ebp-288h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > FileName; // [esp+274h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > FriendlyName; // [esp+278h] [ebp-10h] BYREF
  int v6; // [esp+284h] [ebp-4h]

  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
  {
    CManifestMove::CManifestMove(this: &ManifestMove, bIsMove: false, pParent: nullptr);
    v6 = 0;
    if ( CDialog::DoModal(this: &ManifestMove) == 1 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &FriendlyName);
      LOBYTE(v6) = 1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &FileName);
      LOBYTE(v6) = 2;
      ATL::CSimpleStringT<char,0>::operator=(
        this: &FriendlyName,
        strSrc: (ATL::CStringData *)&ManifestMove.m_FriendlyName);
      ATL::CSimpleStringT<char,0>::operator=(this: &FileName, strSrc: (ATL::CStringData *)&ManifestMove.m_FileName);
      CManifest::AddNewSubmap(this: CMapDoc::m_pManifest, &FriendlyName, &FileName);
      LOBYTE(v6) = 1;
      v1 = FileName.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)FileName.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v1 + 4))(a1: v1);
      LOBYTE(v6) = 0;
      v2 = FriendlyName.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)FriendlyName.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v2 + 4))(a1: v2);
    }
    v6 = -1;
    CManifestMove::~CManifestMove(this: &ManifestMove);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D5E0
// Name: protected: virtual void CManifestMove::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMove::OnOK(CManifestMove *this)
{
  char *m_pszData; // eax
  char *v3; // edx
  char v4; // cl
  char FullFileName[260]; // [esp+8h] [ebp-104h] BYREF

  CDialog::OnOK(this);
  CWnd::GetWindowTextA(this: &this->m_FriendlyNameControl, rString: &this->m_FriendlyName);
  CWnd::GetWindowTextA(this: &this->m_FileNameControl, rString: &this->m_FileName);
  m_pszData = this->m_FileName.m_pszData;
  v3 = (char *)(FullFileName - m_pszData);
  do
  {
    v4 = *m_pszData;
    m_pszData[(_DWORD)v3] = *m_pszData;
    ++m_pszData;
  }
  while ( v4 != 0 );
  V_SetExtension(path: FullFileName, extension: ".vmf", pathStringLength: 260);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_FileName, pszSrc: FullFileName, nLength: strlen(FullFileName));
  this->m_CenterContents = SendMessageA(hWnd: this->m_CenterContentsControl.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D690
// Name: public: void CManifestMove::OnEnChangeManifestFilename(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMove::OnEnChangeManifestFilename(CManifestMove *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_FileName; // esi
  CManifest *v3; // ebx
  const char *m_pszData; // eax
  char *v5; // edx
  char v6; // cl
  CWnd *DlgItem; // eax
  BOOL v8; // [esp-Ch] [ebp-114h]
  char FullFileName[260]; // [esp+4h] [ebp-104h] BYREF

  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pManifest != nullptr )
  {
    p_m_FileName = &this->m_FileName;
    v3 = CMapDoc::m_pManifest;
    CWnd::GetWindowTextA(this: &this->m_FileNameControl, rString: &this->m_FileName);
    m_pszData = p_m_FileName->m_pszData;
    v5 = (char *)(FullFileName - p_m_FileName->m_pszData);
    do
    {
      v6 = *m_pszData;
      m_pszData[(_DWORD)v5] = *m_pszData;
      ++m_pszData;
    }
    while ( v6 != 0 );
    v8 = FullFileName[0] != 0;
    DlgItem = CWnd::GetDlgItem(this, nID: 1);
    CWnd::EnableWindow(this: DlgItem, bEnable: v8);
    V_SetExtension(path: FullFileName, extension: ".vmf", pathStringLength: 260);
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_FileName, pszSrc: FullFileName, nLength: strlen(FullFileName));
    CManifest::GetFullMapPath(this: v3, pManifestMapFileName: p_m_FileName->m_pszData, pOutputPath: FullFileName);
    CWnd::SetWindowTextA(this: &this->m_FullPathNameControl, lpszString: FullFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D770
// Name: protected: virtual struct AFX_MSGMAP const __near * CManifestListBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CManifestListBox::GetMessageMap(CManifestListBox *this)
{
  return (const AFX_MSGMAP *)&off_105DEA4C;
}

//------------------------------------------------------------------------------
// Address: 0x1005D780
// Name: protected: virtual struct AFX_MSGMAP const __near * CManifestMove::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CManifestMove::GetMessageMap(CManifestMove *this)
{
  return (const AFX_MSGMAP *)&off_105DEB90;
}

//------------------------------------------------------------------------------
// Address: 0x1033ACE2
// Name: public: int CMenu::TrackPopupMenu(unsigned int,int,int,class CWnd __near *,struct tagRECT const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMenu::TrackPopupMenu(CMenu *this, UINT nFlags, int x, int y, CWnd *pWnd, const tagRECT *lpRect)
{
  _AFX_THREAD_STATE *ThreadState; // esi
  HWND__ *m_hTrackingWindow; // ebx
  HWND__ *m_hWnd; // eax
  BOOL result; // eax
  HMENU__ *hMenuOld; // [esp+Ch] [ebp-4h]

  ThreadState = AfxGetThreadState();
  m_hTrackingWindow = ThreadState->m_hTrackingWindow;
  hMenuOld = ThreadState->m_hTrackingMenu;
  m_hWnd = (HWND__ *)pWnd;
  if ( pWnd != nullptr )
    m_hWnd = pWnd->m_hWnd;
  ThreadState->m_hTrackingWindow = m_hWnd;
  ThreadState->m_hTrackingMenu = this->m_hMenu;
  result = TrackPopupMenu(hMenu: this->m_hMenu, uFlags: nFlags, x, y, nReserved: 0, hWnd: m_hWnd, prcRect: lpRect);
  ThreadState->m_hTrackingWindow = m_hTrackingWindow;
  ThreadState->m_hTrackingMenu = hMenuOld;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10343104
// Name: public: CDllIsolationWrapperBase::CDllIsolationWrapperBase(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CDllIsolationWrapperBase *__thiscall CDllIsolationWrapperBase::CDllIsolationWrapperBase(
        CDllIsolationWrapperBase *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strModuleName)
{
  this->__vftable = (CDllIsolationWrapperBase_vtbl *)&CDllIsolationWrapperBase::`vftable';
  this->m_strModuleName.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strModuleName->m_pszData - 1)[1];
  this->m_hModule = nullptr;
  this->m_bFreeLib = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10343136
// Name: public: virtual CDllIsolationWrapperBase::~CDllIsolationWrapperBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDllIsolationWrapperBase::~CDllIsolationWrapperBase(CDllIsolationWrapperBase *this)
{
  bool v2; // zf

  v2 = !this->m_bFreeLib;
  this->__vftable = (CDllIsolationWrapperBase_vtbl *)&CDllIsolationWrapperBase::`vftable';
  if ( !v2 )
    FreeLibrary(hLibModule: this->m_hModule);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strModuleName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1034EF55
// Name: public: virtual struct CRuntimeClass __near * CMenu::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMenu::GetRuntimeClass(CMenu *this)
{
  return &CMenu::classCMenu;
}

//------------------------------------------------------------------------------
// Address: 0x1034EF6E
// Name: public: static class CObject __near * CMenu::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CObject *__stdcall CMenu::CreateObject()
{
  CObject *result; // eax

  result = (CObject *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (CObject_vtbl *)&CMenu::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034F016
// Name: public: static class CMenu __near * CMenu::FromHandle(struct HMENU__ __near *)
// Source: json
//------------------------------------------------------------------------------
CMenu *__stdcall CMenu::FromHandle(HMENU__ *hMenu)
{
  CHandleMap *v1; // eax

  v1 = afxMapHMENU(bCreate: 1);
  return (CMenu *)CHandleMap::FromHandle(this: v1, h: hMenu);
}

//------------------------------------------------------------------------------
// Address: 0x1034F02A
// Name: public: static class CMenu __near * CMenu::FromHandlePermanent(struct HMENU__ __near *)
// Source: json
//------------------------------------------------------------------------------
CMenu *__stdcall CMenu::FromHandlePermanent(HMENU__ *hMenu)
{
  CHandleMap *v1; // ecx
  CMenu *result; // eax

  v1 = afxMapHMENU(bCreate: 0);
  result = nullptr;
  if ( v1 != nullptr )
    return (CMenu *)CMapPtrToPtr::GetValueAt(this: &v1->m_permanentMap, key: hMenu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034F04B
// Name: public: int CMenu::Attach(struct HMENU__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMenu::Attach(CMenu *this, HMENU__ *hMenu)
{
  int result; // eax
  CHandleMap *v4; // eax

  result = (int)hMenu;
  if ( hMenu != nullptr )
  {
    this->m_hMenu = hMenu;
    v4 = afxMapHMENU(bCreate: 1);
    *CMapPtrToPtr::operator[](this: &v4->m_permanentMap, key: this->m_hMenu) = this;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034F079
// Name: public: struct HMENU__ __near * CMenu::Detach(void)
// Source: json
//------------------------------------------------------------------------------
HMENU__ *__thiscall CMenu::Detach(CMenu *this)
{
  HMENU__ *m_hMenu; // edi
  CHandleMap *v3; // eax

  m_hMenu = this->m_hMenu;
  if ( m_hMenu != nullptr )
  {
    v3 = afxMapHMENU(bCreate: 0);
    if ( v3 != nullptr )
      CMapPtrToPtr::RemoveKey(this: &v3->m_permanentMap, key: this->m_hMenu);
  }
  this->m_hMenu = nullptr;
  return m_hMenu;
}

//------------------------------------------------------------------------------
// Address: 0x1034F0A5
// Name: public: int CMenu::DestroyMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMenu::DestroyMenu(CMenu *this)
{
  HMENU v2; // eax

  if ( this->m_hMenu == nullptr )
    return false;
  v2 = CMenu::Detach(this);
  return DestroyMenu(hMenu: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1034F0BB
// Name: public: int CMenu::GetMenuStringA(unsigned int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMenu::GetMenuStringA(
        CMenu *this,
        UINT nIDItem,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        UINT nFlags)
{
  int MenuStringA; // eax
  int v6; // ebx
  CHAR *BufferSetLength; // eax
  int nStringLen; // [esp+8h] [ebp-4h]

  MenuStringA = GetMenuStringA(hMenu: this->m_hMenu, uIDItem: nIDItem, lpString: nullptr, cchMax: 0, flags: nFlags);
  nStringLen = MenuStringA;
  if ( MenuStringA <= 0 )
  {
    ATL::CSimpleStringT<char,0>::Empty(this: rString);
  }
  else
  {
    v6 = MenuStringA + 1;
    BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: rString, nLength: MenuStringA + 1);
    GetMenuStringA(hMenu: this->m_hMenu, uIDItem: nIDItem, lpString: BufferSetLength, cchMax: v6, flags: nFlags);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: -1);
  }
  return nStringLen;
}

//------------------------------------------------------------------------------
// Address: 0x10398FED
// Name: public: virtual void CVSListBox::SetItemData(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVSListBox::SetItemData(CVSListBox *this, int iIndex, unsigned int dwData)
{
  CListCtrl *m_pWndList; // ecx

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    m_pWndList = this->m_pWndList;
    if ( m_pWndList != nullptr )
      CListCtrl::SetItem(
        this: m_pWndList,
        nItem: iIndex,
        nSubItem: 0,
        nMask: 4u,
        lpszItem: nullptr,
        nImage: 0,
        nState: 0,
        nStateMask: 0,
        lParam: dwData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033AD38
// Name: class CMenu __near * _AfxFindPopupMenuFromID(class CMenu __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMenu *__stdcall _AfxFindPopupMenuFromID(CMenu *pMenu, HMENU__ *nID)
{
  int v3; // edi
  HMENU SubMenu; // eax
  CMenu *v5; // eax
  CMenu *result; // eax
  int nItems; // [esp+14h] [ebp+8h]

  if ( pMenu == nullptr )
    AfxThrowInvalidArgException();
  v3 = 0;
  nItems = GetMenuItemCount(hMenu: pMenu->m_hMenu);
  if ( nItems > 0 )
  {
    do
    {
      SubMenu = GetSubMenu(hMenu: pMenu->m_hMenu, nPos: v3);
      v5 = CMenu::FromHandle(hMenu: SubMenu);
      if ( v5 != nullptr )
      {
        if ( v5->m_hMenu == nID )
          return CMenu::FromHandlePermanent(hMenu: pMenu->m_hMenu);
        result = _AfxFindPopupMenuFromID(pMenu: v5, (unsigned int)nID);
        if ( result != nullptr )
          return result;
      }
      else if ( (HMENU__ *)GetMenuItemID(hMenu: pMenu->m_hMenu, nPos: v3) == nID )
      {
        return CMenu::FromHandlePermanent(hMenu: pMenu->m_hMenu);
      }
      ++v3;
    }
    while ( v3 < nItems );
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1034EF5B
// Name: public: static void ConstructDestruct<class CGdiObject>::Destruct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CGdiObject>::Destruct(CObject *pObject)
{
  ((void (__thiscall *)(CObject *, _DWORD))pObject->dtr_CObject)(a1: pObject, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034EF88
// Name: public: static void ConstructDestruct<class CMenu>::Construct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CMenu>::Construct(CObject *pObject)
{
  if ( pObject != nullptr )
  {
    pObject[1].__vftable = nullptr;
    pObject->__vftable = (CObject_vtbl *)&CMenu::`vftable';
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034EFA2
// Name: class CHandleMap __near * afxMapHMENU(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHandleMap *__stdcall afxMapHMENU(int bCreate)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // esi
  int (__cdecl *v2)(unsigned int); // ebx
  CHandleMap *v3; // ecx
  CHandleMap *v4; // eax

  ModuleThreadState = AfxGetModuleThreadState();
  if ( ModuleThreadState->m_pmapHMENU == nullptr && bCreate != 0 )
  {
    v2 = AfxSetNewHandler(pfnNewHandler: AfxCriticalNewHandler);
    v3 = (CHandleMap *)operator new(nSize: 0x60u);
    if ( v3 != nullptr )
      v4 = CHandleMap::CHandleMap(
             this: v3,
             pClass: &CMenu::classCMenu,
             pfnConstructObject: ConstructDestruct<CMenu>::Construct,
             pfnDestructObject: ConstructDestruct<CGdiObject>::Destruct,
             nOffset: 4u,
             nHandles: 1);
    else
      v4 = nullptr;
    ModuleThreadState->m_pmapHMENU = v4;
    AfxSetNewHandler(pfnNewHandler: v2);
  }
  return ModuleThreadState->m_pmapHMENU;
}

//------------------------------------------------------------------------------
// Address: 0x1034F116
// Name: public: virtual void CChevronOwnerDrawMenu::MeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CChevronOwnerDrawMenu::MeasureItem(CChevronOwnerDrawMenu *this, tagMEASUREITEMSTRUCT *pmis)
{
  tagMEASUREITEMSTRUCT *v2; // edi
  unsigned int itemData; // eax
  char *v4; // esi
  CAfxStringMgr *StringManager; // eax
  char *v6; // eax
  BOOL MenuItemInfoA; // ebx
  CFont *v8; // ebx
  int SystemMetrics; // eax
  ATL::CStringData *p_itemID; // ecx
  HMENU v11; // [esp-10h] [ebp-80h]
  UINT itemID; // [esp-Ch] [ebp-7Ch]
  tagMENUITEMINFOA info; // [esp+10h] [ebp-60h] BYREF
  CWindowDC dc; // [esp+40h] [ebp-30h] BYREF
  int nHeight; // [esp+58h] [ebp-18h]
  CSize size; // [esp+5Ch] [ebp-14h] BYREF
  int v17; // [esp+6Ch] [ebp-4h]

  size.cy = (int)this;
  v2 = pmis;
  itemData = pmis->itemData;
  if ( itemData != 0 )
  {
    GetObjectA(h: *(HANDLE *)(itemData + 4), c: 24, pv: &dc);
    nHeight = (int)dc.m_hAttribDC + 2;
    v4 = (char *)dc.m_hDC + 2;
  }
  else
  {
    nHeight = GetSystemMetrics(nIndex: 50) + 2;
    v4 = (char *)(GetSystemMetrics(nIndex: 49) + 2);
  }
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&pmis,
    pStringMgr: StringManager);
  v17 = 0;
  memset(dst: (unsigned __int8 *)&info, value: 0, count: sizeof(info));
  itemID = v2->itemID;
  v11 = *(HMENU *)(size.cy + 4);
  info.cbSize = 48;
  info.fMask = 64;
  if ( GetMenuItemInfoA(hmenu: v11, item: itemID, fByPosition: false, lpmii: &info) )
  {
    v6 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: (ATL::CSimpleStringT<char,0> *)&pmis, nLength: info.cch++);
    info.dwTypeData = v6;
    MenuItemInfoA = GetMenuItemInfoA(hmenu: *(HMENU *)(size.cy + 4), item: v2->itemID, fByPosition: false, lpmii: &info);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: (ATL::CSimpleStringT<char,0> *)&pmis, nNewLength: -1);
    if ( MenuItemInfoA )
    {
      CWindowDC::CWindowDC(this: (CWindowDC *)&dc.m_hDC, pWnd: nullptr);
      LOBYTE(v17) = 1;
      v8 = CDC::SelectObject(this: (CDC *)&dc.m_hDC, pFont: (CFont *)(size.cy + 8));
      CDC::GetTextExtent(
        this: (CDC *)&dc.m_hDC,
        result: &size,
        str: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pmis);
      CDC::SelectObject(this: (CDC *)&dc.m_hDC, pFont: v8);
      v4 += size.cx + 3;
      LOBYTE(v17) = 0;
      CWindowDC::~CWindowDC(this: (CWindowDC *)&dc.m_hDC);
    }
  }
  if ( GetSystemMetrics(nIndex: 15) <= nHeight )
    SystemMetrics = nHeight;
  else
    SystemMetrics = GetSystemMetrics(nIndex: 15);
  p_itemID = (ATL::CStringData *)&pmis[-1].itemID;
  v2->itemHeight = SystemMetrics;
  v2->itemWidth = (unsigned int)v4;
  ATL::CStringData::Release(this: p_itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1034F25F
// Name: public: CChevronOwnerDrawMenu::CChevronOwnerDrawMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CChevronOwnerDrawMenu *__thiscall CChevronOwnerDrawMenu::CChevronOwnerDrawMenu(CChevronOwnerDrawMenu *this)
{
  HFONT v2; // eax
  UINT pvParam[40]; // [esp+14h] [ebp-168h] BYREF
  LOGFONTA lf; // [esp+B4h] [ebp-C8h] BYREF
  int v6; // [esp+178h] [ebp-4h]

  this->m_hMenu = nullptr;
  v6 = 0;
  this->__vftable = (CChevronOwnerDrawMenu_vtbl *)&CChevronOwnerDrawMenu::`vftable';
  this->m_MenuFont.m_hObject = nullptr;
  this->m_MenuFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  LOBYTE(v6) = 1;
  pvParam[0] = _AfxGetComCtlVersion() < 0x60001 ? 340 : 344;
  SystemParametersInfoA(uiAction: 0x29u, uiParam: pvParam[0], pvParam, fWinIni: 0);
  v2 = CreateFontIndirectA(lplf: &lf);
  CGdiObject::Attach(this: &this->m_MenuFont, hObject: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034F2FE
// Name: public: virtual void CChevronOwnerDrawMenu::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CChevronOwnerDrawMenu::DrawItem(CChevronOwnerDrawMenu *this, tagDRAWITEMSTRUCT *pdis)
{
  CDC *v2; // esi
  char *v3; // eax
  CObject *v4; // edi
  int left; // edi
  unsigned int SystemMetrics; // eax
  HDC CompatibleDC; // eax
  CSize *TextExtent; // eax
  HDC__ *cx; // ecx
  bool v10; // zf
  COLORREF v11; // eax
  COLORREF v12; // eax
  DWORD v13; // eax
  unsigned int v14; // eax
  unsigned int itemState; // eax
  DWORD SysColor; // eax
  DWORD v17; // eax
  COLORREF v18; // eax
  DWORD v19; // eax
  unsigned int v20; // eax
  HDC v21; // eax
  CObject_vtbl *v22; // eax
  HMENU m_hMenu; // [esp-10h] [ebp-E0h]
  UINT itemID; // [esp-Ch] [ebp-DCh]
  CObject_vtbl *v25; // [esp-Ch] [ebp-DCh]
  HDC__ *hDC; // [esp-4h] [ebp-D4h]
  COLORREF v27; // [esp-4h] [ebp-D4h]
  COLORREF v28; // [esp-4h] [ebp-D4h]
  tagMENUITEMINFOA dst; // [esp+10h] [ebp-C0h] BYREF
  CDC v30; // [esp+40h] [ebp-90h] BYREF
  int v31; // [esp+50h] [ebp-80h]
  CDC pSrcDC; // [esp+54h] [ebp-7Ch] BYREF
  int v33; // [esp+64h] [ebp-6Ch]
  tagDRAWITEMSTRUCT *v34; // [esp+68h] [ebp-68h]
  CObject *itemData; // [esp+6Ch] [ebp-64h]
  CChevronOwnerDrawMenu *v36; // [esp+70h] [ebp-60h]
  int MenuItemInfoA; // [esp+74h] [ebp-5Ch]
  unsigned int clr; // [esp+78h] [ebp-58h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+7Ch] [ebp-54h] BYREF
  CSize result; // [esp+80h] [ebp-50h] BYREF
  tagRECT rcDst; // [esp+88h] [ebp-48h] BYREF
  _BYTE pv[4]; // [esp+98h] [ebp-38h] BYREF
  unsigned int v43; // [esp+9Ch] [ebp-34h]
  tagRECT Rect; // [esp+A0h] [ebp-30h] BYREF
  tagRECT x; // [esp+B0h] [ebp-20h] BYREF
  int v46; // [esp+CCh] [ebp-4h]

  v36 = this;
  v34 = pdis;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &str,
    pszSrc: &var);
  hDC = pdis->hDC;
  v46 = 0;
  v2 = CDC::FromHandle(hDC);
  v31 = v2->SaveDC(this: v2);
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  itemID = pdis->itemID;
  m_hMenu = v36->m_hMenu;
  dst.cbSize = 48;
  dst.fMask = 64;
  MenuItemInfoA = 0;
  if ( GetMenuItemInfoA(hmenu: m_hMenu, item: itemID, fByPosition: false, lpmii: &dst) )
  {
    v3 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &str, nLength: dst.cch++);
    dst.dwTypeData = v3;
    MenuItemInfoA = GetMenuItemInfoA(hmenu: v36->m_hMenu, item: pdis->itemID, fByPosition: false, lpmii: &dst);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &str, nNewLength: -1);
  }
  itemData = (CObject *)pdis->itemData;
  memset(&x, 0, sizeof(x));
  CopyRect(lprcDst: &rcDst, lprcSrc: &pdis->rcItem);
  v4 = itemData;
  if ( itemData != nullptr && CObject::IsKindOf(this: itemData, pClass: &CBitmap::classCBitmap) != 0 )
  {
    v25 = v4[1].__vftable;
    v33 = 1;
    GetObjectA(h: v25, c: 24, pv);
    left = Rect.left;
    SystemMetrics = v43;
  }
  else
  {
    v33 = 0;
    left = GetSystemMetrics(nIndex: 50);
    SystemMetrics = GetSystemMetrics(nIndex: 49);
  }
  clr = SystemMetrics;
  x.bottom = (rcDst.bottom - rcDst.top) / 2 - left / 2 + rcDst.top + left;
  x.top = (rcDst.bottom - rcDst.top) / 2 - left / 2 + rcDst.top - 1;
  x.left = 0;
  x.right = SystemMetrics + 1;
  clr = GetSysColor(nIndex: 4);
  CDC::CDC(this: &v30);
  LOBYTE(v46) = 1;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &v30, hDC: CompatibleDC);
  v2->SelectObject(this: v2, a2: &v36->m_MenuFont);
  TextExtent = CDC::GetTextExtent(this: v2, &result, &str);
  cx = (HDC__ *)TextExtent->cx;
  pSrcDC.m_bPrinting = TextExtent->cy;
  v10 = (v34->itemState & 1) == 0;
  pSrcDC.m_hAttribDC = cx;
  if ( v10 )
  {
    CDC::FillSolidRect(this: v2, lpRect: &v34->rcItem, clr);
    v2->SetBkColor(this: v2, a2: clr);
    itemState = v34->itemState;
    if ( (itemState & 2) != 0 )
    {
      result.cy = (int)v2->__vftable;
      SysColor = GetSysColor(nIndex: 20);
      (*(void (__thiscall **)(CDC *, DWORD))(result.cy + 48))(a1: v2, a2: SysColor);
      CDC::SetBkMode(this: v2, nBkMode: 1);
      if ( MenuItemInfoA != 0 )
      {
        MenuItemInfoA = pSrcDC.m_bPrinting / 2;
        ExtTextOutA(
          hdc: v2->m_hDC,
          x: x.right + 4,
          y: (x.bottom - x.top) / 2 - pSrcDC.m_bPrinting / 2 + x.top + 1,
          options: 2u,
          lprect: nullptr,
          lpString: str.m_pszData,
          c: *((_DWORD *)str.m_pszData - 3),
          lpDx: nullptr);
        result.cy = (int)v2->__vftable;
        v17 = GetSysColor(nIndex: 17);
        (*(void (__thiscall **)(CDC *, DWORD))(result.cy + 48))(a1: v2, a2: v17);
        ExtTextOutA(
          hdc: v2->m_hDC,
          x: x.right + 3,
          y: x.top + (x.bottom - x.top) / 2 - MenuItemInfoA,
          options: 0,
          lprect: nullptr,
          lpString: str.m_pszData,
          c: *((_DWORD *)str.m_pszData - 3),
          lpDx: nullptr);
      }
    }
    else
    {
      if ( v33 != 0 && (itemState & 8) != 0 )
      {
        result.cy = x.bottom - x.top;
        v36 = (CChevronOwnerDrawMenu *)(x.right - x.left);
        v28 = GetSysColor(nIndex: 20);
        v18 = GetSysColor(nIndex: 16);
        CDC::Draw3dRect(
          this: v2,
          x: x.left,
          y: x.top,
          cx: (int)&v36->__vftable + 1,
          cy: result.cy + 1,
          clrTopLeft: v18,
          clrBottomRight: v28);
      }
      if ( MenuItemInfoA != 0 )
      {
        v2->SetBkColor(this: v2, a2: clr);
        result.cy = (int)v2->__vftable;
        v19 = GetSysColor(nIndex: 7);
        (*(void (__thiscall **)(CDC *, DWORD))(result.cy + 48))(a1: v2, a2: v19);
LABEL_24:
        ExtTextOutA(
          hdc: v2->m_hDC,
          x: x.right + 3,
          y: x.top + (x.bottom - x.top) / 2 - pSrcDC.m_bPrinting / 2,
          options: 2u,
          lprect: nullptr,
          lpString: str.m_pszData,
          c: *((_DWORD *)str.m_pszData - 3),
          lpDx: nullptr);
      }
    }
  }
  else
  {
    CopyRect(lprcDst: &Rect, lprcSrc: &v34->rcItem);
    Rect.left = x.right + 2;
    v11 = GetSysColor(nIndex: 13);
    CDC::FillSolidRect(this: v2, lpRect: &Rect, clr: v11);
    if ( v33 != 0 && (v34->itemState & 0xA) == 0 )
    {
      v36 = (CChevronOwnerDrawMenu *)(x.bottom - x.top);
      result.cy = x.right - x.left;
      v27 = GetSysColor(nIndex: 16);
      v12 = GetSysColor(nIndex: 20);
      CDC::Draw3dRect(
        this: v2,
        x: x.left,
        y: x.top,
        cx: result.cy + 1,
        cy: (int)&v36->__vftable + 1,
        clrTopLeft: v12,
        clrBottomRight: v27);
    }
    if ( MenuItemInfoA != 0 )
    {
      result.cy = (int)v2->__vftable;
      v13 = GetSysColor(nIndex: 13);
      (*(void (__thiscall **)(CDC *, DWORD))(result.cy + 44))(a1: v2, a2: v13);
      if ( (v34->itemState & 2) != 0 )
        v14 = clr;
      else
        v14 = GetSysColor(nIndex: 14);
      v2->SetTextColor(this: v2, a2: v14);
      goto LABEL_24;
    }
  }
  if ( v33 == 0 )
    goto LABEL_35;
  result.cy = 0;
  result.cx = (int)&CBitmap::`vftable';
  v20 = v34->itemState;
  LOBYTE(v46) = 2;
  if ( (v20 & 2) != 0 )
  {
    AfxGetGrayBitmap(rSrc: (const CBitmap *)itemData, pDest: (CBrush *)&result, crBackground: clr);
LABEL_30:
    itemData = (CObject *)&result;
    goto LABEL_31;
  }
  if ( (v20 & 8) != 0 )
  {
    AfxGetDitheredBitmap(rSrc: (const CBitmap *)itemData, pDest: (CBitmap *)&result, cr1: clr, cr2: 0xFFFFFFu);
    goto LABEL_30;
  }
LABEL_31:
  CDC::CDC(this: &pSrcDC);
  LOBYTE(v46) = 3;
  v21 = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &pSrcDC, hDC: v21);
  if ( itemData != nullptr )
    v22 = itemData[1].__vftable;
  else
    v22 = nullptr;
  CDC::SelectGdiObject(hDC: pSrcDC.m_hDC, h: v22);
  InflateRect(lprc: &x, dx: -1, dy: -1);
  CDC::BitBlt(
    this: v2,
    x: x.left,
    y: x.top,
    nWidth: x.right,
    nHeight: x.bottom,
    &pSrcDC,
    xSrc: 0,
    ySrc: 0,
    dwRop: 0xCC0020u);
  LOBYTE(v46) = 2;
  CDC::~CDC(this: &pSrcDC);
  LOBYTE(v46) = 1;
  result.cx = (int)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: (CGdiObject *)&result);
LABEL_35:
  v2->RestoreDC(this: v2, a2: v31);
  LOBYTE(v46) = 0;
  CDC::~CDC(this: &v30);
  ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1034F7B4
// Name: public: CStatusBar::CStatusBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStatusBar *__thiscall CStatusBar::CStatusBar(CStatusBar *this)
{
  CControlBar::CControlBar(this);
  this->m_cxLeftBorder = 0;
  this->m_cxRightBorder = 0;
  this->m_cyBottomBorder = 0;
  this->m_nMinHeight = 0;
  this->__vftable = (CStatusBar_vtbl *)&CStatusBar::`vftable';
  this->m_cyTopBorder = 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034F7E9
// Name: public: virtual int CStatusBar::Create(class CWnd __near *,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::Create(CStatusBar *this, CWnd *pParentWnd, unsigned int dwStyle, unsigned int nID)
{
  return this->CreateEx(this, a2: pParentWnd, a3: 0, a4: dwStyle, a5: nID);
}

//------------------------------------------------------------------------------
// Address: 0x1034F805
// Name: public: virtual int CStatusBar::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::PreCreateWindow(CStatusBar *this, tagCREATESTRUCTA *cs)
{
  if ( (this->m_dwStyle & 0xFF00) == 0x8200 )
    this->m_dwStyle &= 0xFFFFF07F;
  return CControlBar::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x1034F833
// Name: public: virtual void CStatusBar::CalcInsideRect(class CRect __near &,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::CalcInsideRect(CStatusBar *this, CRect *rect, int bHorz)
{
  HWND Parent; // eax
  int v5; // esi
  int rgBorders[3]; // [esp+8h] [ebp-10h] BYREF

  CControlBar::CalcInsideRect(this, rect, bHorz);
  if ( (CWnd::GetStyle(this) & 0x100) != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    if ( !IsZoomed(hWnd: Parent) )
    {
      this->DefWindowProcA(this, a2: 1031u, a3: 0, a4: (int)rgBorders);
      v5 = rect->right - 2 * GetSystemMetrics(nIndex: 5) - rgBorders[0];
      rect->right = v5 - GetSystemMetrics(nIndex: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034F8BB
// Name: public: int CStatusBar::CommandToIndex(unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::CommandToIndex(CStatusBar *this, unsigned int nIDFind)
{
  int m_nCount; // edx
  int result; // eax
  _DWORD *m_pData; // ecx

  m_nCount = this->m_nCount;
  if ( m_nCount <= 0 )
    return -1;
  m_pData = this->m_pData;
  result = 0;
  while ( *m_pData != nIDFind )
  {
    ++result;
    m_pData += 5;
    if ( result >= m_nCount )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034F8F3
// Name: protected: long CStatusBar::OnNcHitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::OnNcHitTest(CStatusBar *this, CPoint __formal)
{
  return CWnd::Default(this) != 17 ? 1 : 17;
}

//------------------------------------------------------------------------------
// Address: 0x1034F908
// Name: public: virtual void CStatusBar::OnBarStyleChange(unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::OnBarStyleChange(CStatusBar *this, unsigned int dwOldStyle, unsigned int dwNewStyle)
{
  if ( this->m_hWnd != nullptr && ((dwNewStyle ^ dwOldStyle) & 0xF00) != 0 )
    CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x33u);
}

//------------------------------------------------------------------------------
// Address: 0x1039901D
// Name: protected: void CVSListBox::OnKeyDown(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBox::OnKeyDown(CVSListBox *this, tagNMHDR *pNMHDR, int *pResult)
{
  CList<unsigned long,unsigned long>::CNode *m_pNodeHead; // eax
  int i; // esi
  unsigned int data; // ecx

  *pResult = 0;
  if ( pNMHDR != nullptr )
  {
    LOBYTE(pResult) = 0;
    if ( GetAsyncKeyState(vKey: 17) < 0 )
      LOBYTE(pResult) = 8;
    if ( GetAsyncKeyState(vKey: 18) < 0 )
      LOBYTE(pResult) = (unsigned __int8)pResult | 0x10;
    if ( GetAsyncKeyState(vKey: 16) < 0 )
      LOBYTE(pResult) = (unsigned __int8)pResult | 4;
    m_pNodeHead = this->m_lstKeyAccell.m_pNodeHead;
    for ( i = 0; ; ++i )
    {
      if ( m_pNodeHead == nullptr )
      {
        this->OnKey(this, a2: (unsigned __int16)pNMHDR[1].hwndFrom, a3: (unsigned __int8)pResult);
        return;
      }
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data != 0 && LOWORD(pNMHDR[1].hwndFrom) == (_WORD)data && (_BYTE)pResult == BYTE2(data) )
        break;
    }
    this->OnClickButton(this, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103990BB
// Name: public: virtual int CVSListBox::GetSelItem(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CVSListBox::GetSelItem(CVSListBox *this)
{
  CListCtrl *m_pWndList; // ecx

  if ( this != nullptr && this->m_hWnd != nullptr && (m_pWndList = this->m_pWndList) != nullptr )
    return SendMessageA(hWnd: m_pWndList->m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103990E6
// Name: public: virtual int CVSListBox::SelectItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CVSListBox::SelectItem(CVSListBox *this, int iItem)
{
  CListCtrl *m_pWndList; // ecx

  if ( this != nullptr
    && this->m_hWnd != nullptr
    && (m_pWndList = this->m_pWndList) != nullptr
    && CListCtrl::SetItemState(this: m_pWndList, nItem: iItem, nState: 3u, nStateMask: 3u) != 0 )
  {
    return SendMessageA(hWnd: this->m_pWndList->m_hWnd, Msg: 0x1013u, wParam: iItem, lParam: 0);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399134
// Name: public: virtual int CVSListBox::RemoveItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBox::RemoveItem(CVSListBox *this, int iIndex)
{
  int v3; // ebx
  BOOL v4; // esi

  if ( this == nullptr )
    return 0;
  if ( this->m_hWnd == nullptr )
    return 0;
  if ( this->m_pWndList == nullptr )
    return 0;
  v3 = iIndex;
  v4 = iIndex == this->GetSelItem(this);
  if ( SendMessageA(hWnd: this->m_pWndList->m_hWnd, Msg: 0x1008u, wParam: iIndex, lParam: 0) == 0
    || !v4
    || this->GetCount(this) == 0 )
  {
    return 0;
  }
  if ( iIndex >= this->GetCount(this) )
    v3 = iIndex - 1;
  this->SelectItem(this, a2: v3);
  return 1;
}
