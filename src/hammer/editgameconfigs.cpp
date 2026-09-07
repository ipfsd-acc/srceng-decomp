// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/editgameconfigs.cpp
// Functions: 20
// ============================================================

#include "hammer\editgameconfigs.h"

//------------------------------------------------------------------------------
// Address: 0x10030120
// Name: protected: void CEditGameConfigs::OnDblclkConfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameConfigs::OnDblclkConfigs(CEditGameConfigs *this)
{
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x10030160
// Name: public: CEditGameConfigs::CEditGameConfigs(int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CEditGameConfigs *__thiscall CEditGameConfigs::CEditGameConfigs(CEditGameConfigs *this, int bSelectOnly, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x110u, pParentWnd: pParent);
  this->__vftable = (CEditGameConfigs_vtbl *)&CEditGameConfigs::`vftable';
  CWnd::CWnd(this: &this->m_cConfigs);
  this->m_cConfigs.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  this->m_bSelectOnly = bSelectOnly;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10030230
// Name: protected: virtual void CEditGameConfigs::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameConfigs::DoDataExchange(CEditGameConfigs *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 1391, rControl: &this->m_cConfigs);
}

//------------------------------------------------------------------------------
// Address: 0x10030250
// Name: protected: void CEditGameConfigs::OnSelchangeConfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameConfigs::OnSelchangeConfigs(CEditGameConfigs *this)
{
  WPARAM v2; // eax
  LRESULT v3; // eax

  v2 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v2 != -1 )
  {
    v3 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    this->m_pSelectedGame = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v3, piIndex: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100302A0
// Name: protected: void CEditGameConfigs::FillConfigList(unsigned long)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10030420
// Name: protected: virtual int CEditGameConfigs::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditGameConfigs::OnInitDialog(CEditGameConfigs *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  CDialog::OnInitDialog(this);
  if ( this->m_bSelectOnly != 0 )
  {
    CWnd::SetWindowTextA(this, lpszString: "Select a game configuration to use");
    DlgItem = CWnd::GetDlgItem(this, nID: 1);
    CWnd::SetWindowTextA(this: DlgItem, lpszString: "OK");
    v3 = CWnd::GetDlgItem(this, nID: 1085);
    CWnd::ShowWindow(this: v3, nCmdShow: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1390);
    CWnd::ShowWindow(this: v4, nCmdShow: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1263);
    CWnd::ShowWindow(this: v5, nCmdShow: 0);
  }
  CEditGameConfigs::FillConfigList(this, dwSelectID: 0xFFFFFFFF);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100304B0
// Name: public: virtual CStrDlg::~CStrDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStrDlg::~CStrDlg(CStrDlg *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax

  CEdit::~CEdit(this: &this->m_cEdit);
  CStatic::~CStatic(this: &this->m_cPrompt);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_cSpin);
  v2 = (volatile signed __int32 *)(this->m_strTitle.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_strPrompt.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_string.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100305B0
// Name: protected: void CEditGameConfigs::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameConfigs::OnCopy(CEditGameConfigs *this)
{
  WPARAM v2; // eax
  LRESULT v3; // eax
  CGameConfig *Config; // ebx
  CGameConfig *v5; // esi

  v2 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v2 != -1 )
  {
    v3 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    Config = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v3, piIndex: nullptr);
    v5 = COptionsConfigs::AddConfig(this: &Options.configs);
    CGameConfig::CopyFrom(this: v5, pConfig: Config);
    CEditGameConfigs::FillConfigList(this, dwSelectID: v5->dwID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030620
// Name: protected: void CEditGameConfigs::OnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameConfigs::OnRemove(CEditGameConfigs *this)
{
  WPARAM v2; // eax
  WPARAM v3; // ebx
  LRESULT v4; // eax
  int v5; // edi
  CMapDoc *Document; // eax
  int iArrayIndex; // [esp+Ch] [ebp-Ch] BYREF
  CGameConfig *pConfig; // [esp+10h] [ebp-8h]
  bool bResetDefaults; // [esp+17h] [ebp-1h]

  v2 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    pConfig = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v4, piIndex: &iArrayIndex);
    v5 = 0;
    if ( CMapDoc::GetDocumentCount() <= 0 )
    {
LABEL_5:
      bResetDefaults = false;
      if ( Options.configs.nConfigs <= 1 )
      {
        if ( AfxMessageBox(
               lpszText: "At least one configuration must be present!\nWould you like to reset to the default configurations?",
               nType: 4u,
               nIDHelp: 0) == 7 )
          return;
        bResetDefaults = true;
      }
      SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0);
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&Options.configs.Configs,
        nIndex: iArrayIndex,
        nCount: 1);
      --Options.configs.nConfigs;
      if ( bResetDefaults )
      {
        COptionsConfigs::ResetGameConfigs(this: &Options.configs, bOverwrite: false);
        CEditGameConfigs::FillConfigList(this, dwSelectID: 0xFFFFFFFF);
      }
      SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
    }
    else
    {
      while ( 1 )
      {
        Document = CMapDoc::GetDocument(index: v5);
        if ( Document->m_pGame == pConfig )
          break;
        if ( ++v5 >= CMapDoc::GetDocumentCount() )
          goto LABEL_5;
      }
      AfxMessageBox(
        lpszText: "You can't delete this game configuration now\n"
        "because some loaded documents are using it.\n"
        "If you want to delete it, you must close those\n"
        "documents first.",
        nType: 0,
        nIDHelp: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030740
// Name: protected: void CEditGameConfigs::OnAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameConfigs::OnAdd(CEditGameConfigs *this)
{
  CGameConfig *v2; // eax
  char *m_pszData; // edx
  char *v4; // esi
  char v5; // cl
  CStrDlg dlg; // [esp+4h] [ebp-298h] BYREF
  char szName[128]; // [esp+210h] [ebp-8Ch] BYREF
  int v8; // [esp+298h] [ebp-4h]

  szName[0] = 0;
  CStrDlg::CStrDlg(
    this: &dlg,
    dwFlags: 0,
    pszString: szName,
    pszPrompt: "Enter the game's name:",
    pszTitle: "Add a game");
  v8 = 0;
  if ( CDialog::DoModal(this: &dlg) == 1 )
  {
    v2 = COptionsConfigs::AddConfig(this: &Options.configs);
    m_pszData = dlg.m_string.m_pszData;
    v4 = v2->szName;
    do
    {
      v5 = *m_pszData;
      *v4++ = *m_pszData++;
    }
    while ( v5 != 0 );
    CEditGameConfigs::FillConfigList(this, dwSelectID: v2->dwID);
    v8 = -1;
    CStrDlg::~CStrDlg(this: &dlg);
  }
  else
  {
    v8 = -1;
    CStrDlg::~CStrDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030810
// Name: protected: virtual struct AFX_MSGMAP const __near * CEditGameConfigs::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CEditGameConfigs::GetMessageMap(CEditGameConfigs *this)
{
  return (const AFX_MSGMAP *)&off_105D9538;
}

//------------------------------------------------------------------------------
// Address: 0x10348678
// Name: public: virtual int CListBox::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CListBox::Create(
        CListBox *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  return this->Create(this, a2: "LISTBOX", a3: nullptr, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034869B
// Name: public: virtual CListBox::~CListBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListBox::~CListBox(CListBox *this)
{
  this->__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103486CC
// Name: protected: virtual int CListBox::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CListBox::OnChildNotify(
        CListBox *this,
        unsigned int message,
        unsigned int wParam,
        tagDRAWITEMSTRUCT *lParam,
        int *pResult)
{
  int v6; // eax

  switch ( message )
  {
    case '+':
      this->DrawItem(this, a2: lParam);
      break;
    case ',':
      this->MeasureItem(this, a2: (tagMEASUREITEMSTRUCT *)lParam);
      break;
    case '-':
      this->DeleteItem(this, a2: (tagDELETEITEMSTRUCT *)lParam);
      break;
    default:
      switch ( message )
      {
        case '.':
          v6 = this->VKeyToItem(this, a2: (unsigned __int16)wParam, a3: HIWORD(wParam));
          break;
        case '/':
          v6 = this->CharToItem(this, a2: (unsigned __int16)wParam, a3: HIWORD(wParam));
          break;
        case '9':
          v6 = this->CompareItem(this, a2: (tagCOMPAREITEMSTRUCT *)lParam);
          break;
        default:
          return CWnd::OnChildNotify(this, uMsg: message, wParam, (int)lParam, pResult);
      }
      *pResult = v6;
      break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034875A
// Name: public: unsigned int CListBox::ItemFromPoint(class CPoint,int __near &)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListBox::ItemFromPoint(CListBox *this, CPoint pt, int *bOutside)
{
  BOOL v3; // edx
  LRESULT result; // eax

  result = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A9u, wParam: 0, lParam: LOWORD(pt.x) | (LOWORD(pt.y) << 16));
  v3 = HIWORD(result) != 0;
  *bOutside = v3;
  return (unsigned __int16)result;
}

//------------------------------------------------------------------------------
// Address: 0x103488FA
// Name: public: virtual struct CRuntimeClass __near * CListBox::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CListBox::GetRuntimeClass(CListBox *this)
{
  return &CListBox::classCListBox;
}

//------------------------------------------------------------------------------
// Address: 0x10348933
// Name: public: void CListBox::GetText(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListBox::GetText(
        CListBox *this,
        WPARAM nIndex,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString)
{
  LRESULT v4; // eax
  char *BufferSetLength; // eax

  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Au, wParam: nIndex, lParam: 0);
  BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: rString, nLength: v4);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x189u, wParam: nIndex, lParam: (LPARAM)BufferSetLength);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103FC3E5
// Name: public: virtual int CListBox::CharToItem(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CListBox::CharToItem(CMultiPaneFrameWnd *this, unsigned int fwSide, tagRECT *pRect)
{
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103FC3ED
// Name: public: virtual void CMultiPaneFrameWnd::OnPaneRecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMultiPaneFrameWnd::OnPaneRecalcLayout(CMultiPaneFrameWnd *this)
{
  CPaneContainerManager_vtbl *v2; // eax
  int v3; // eax
  int v4; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-50h]
  HWND__ *v6; // [esp-8h] [ebp-50h]
  void *hdwp; // [esp+10h] [ebp-38h] BYREF
  CRect rectContainer; // [esp+14h] [ebp-34h] BYREF
  CRect rectWnd; // [esp+24h] [ebp-24h] BYREF
  CRect rectClient; // [esp+34h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  hdwp = BeginDeferWindowPos(nNumWindows: 20);
  ((void (__thiscall *)(CPaneContainerManager *, int, int, int, int, void **))this->m_barContainerManager.ResizePaneContainers)(
    a1: &this->m_barContainerManager,
    a2: rectClient.left,
    a3: rectClient.top,
    a4: rectClient.right,
    a5: rectClient.bottom,
    a6: &hdwp);
  EndDeferWindowPos(hWinPosInfo: hdwp);
  if ( CPane::m_bHandleMinSize != 0 )
  {
    v2 = this->m_barContainerManager.__vftable;
    memset(&rectContainer, 0, sizeof(rectContainer));
    v2->GetWindowRect(this: &this->m_barContainerManager, a2: &rectContainer);
    v6 = this->m_hWnd;
    memset(&rectWnd, 0, sizeof(rectWnd));
    GetWindowRect(hWnd: v6, lpRect: &rectWnd);
    v3 = rectClient.left + rectContainer.right - rectClient.right - rectContainer.left;
    v4 = rectClient.top + rectContainer.bottom - rectContainer.top - rectClient.bottom;
    if ( v3 < 0 )
      v3 = 0;
    if ( v4 < 0 )
      v4 = 0;
    if ( v3 != 0 || v4 != 0 )
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: nullptr,
        x: -1,
        y: -1,
        cx: v3 + rectWnd.right - rectWnd.left,
        cy: v4 + rectWnd.bottom - rectWnd.top,
        nFlags: 0x16u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FC4F2
// Name: public: virtual void CMultiPaneFrameWnd::RemovePane(class CBasePane __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMultiPaneFrameWnd::RemovePane(
        CMultiPaneFrameWnd *this,
        CDockablePane *pBar,
        int bDestroy,
        int __formal)
{
  CBasePane *v5; // eax
  HWND__ *v6; // eax

  if ( CObject::IsKindOf(this: &pBar->CPane, pClass: &CDockablePane::classCDockablePane) != 0 )
  {
    this->m_barContainerManager.RemovePaneFromPaneContainer(this: &this->m_barContainerManager, a2: pBar);
    if ( CPaneContainerManager::IsEmpty(this: &this->m_barContainerManager) )
    {
      CPaneFrameWnd::RemovePane(this, pWnd: &pBar->CPane, bDestroy: 0, bNoDelayedDestroy: 0);
      if ( CWnd::FromHandlePermanent(hWnd: this->m_hEmbeddedBar) == nullptr )
      {
        v6 = (HWND__ *)this->m_barContainerManager.GetFirstPane(this: &this->m_barContainerManager);
        if ( v6 != nullptr )
          v6 = *((HWND__ **)v6 + 8);
        this->m_hEmbeddedBar = v6;
      }
    }
    else
    {
      v5 = this->m_barContainerManager.GetFirstPane(this: &this->m_barContainerManager);
      CPaneFrameWnd::ReplacePane(this, pBarOrg: &pBar->CPane, pBarReplaceWith: v5);
    }
  }
  if ( bDestroy == 0 || this->GetPaneCount(this) != 0 )
  {
    this->CheckGripperVisibility(this);
    this->OnPaneRecalcLayout(this);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
  }
  else
  {
    PostMessageA(hWnd: this->m_hWnd, Msg: AFX_WM_CHECKEMPTYMINIFRAME, wParam: 0, lParam: 0);
  }
  this->OnKillRollUpTimer(this);
}
