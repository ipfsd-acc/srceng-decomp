// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mainfrm.cpp
// Functions: 329
// ============================================================

#include "hammer\mainfrm.h"

//------------------------------------------------------------------------------
// Address: 0x10053370
// Name: public: virtual CTextureBar::~CTextureBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::~CTextureBar(CTextureBar *this)
{
  CStatic::~CStatic(this: &this->m_TexturePic);
  CComboBox::~CComboBox(this: &this->m_TextureGroupList);
  CTextureBox::~CTextureBox(this: &this->m_TextureList);
  CHammerBar::~CHammerBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x100533F0
// Name: public: int CBitmap::LoadBitmapA(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBitmap::LoadBitmapA(CBitmap *this, unsigned __int16 nIDResource)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HBITMAP BitmapW; // eax

  ModuleState = AfxGetModuleState();
  BitmapW = LoadBitmapW(hInstance: ModuleState->m_hCurrentResourceHandle, lpBitmapName: (LPCWSTR)nIDResource);
  return CGdiObject::Attach(this, hObject: BitmapW);
}

//------------------------------------------------------------------------------
// Address: 0x10053420
// Name: public: virtual CMenu::~CMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMenu::~CMenu(CMenu *this)
{
  this->__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053430
// Name: public: virtual struct CRuntimeClass __near * CMainFrame::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMainFrame::GetRuntimeClass(CMainFrame *this)
{
  return &CMainFrame::classCMainFrame;
}

//------------------------------------------------------------------------------
// Address: 0x10053440
// Name: public: virtual CMDIFrameWnd::~CMDIFrameWnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::~CMDIFrameWnd(CMDIChildWnd *this)
{
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053480
// Name: public: virtual CSelectModeDlgBar::~CSelectModeDlgBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::~CSelectModeDlgBar(CSelectModeDlgBar *this)
{
  CHammerBar::~CHammerBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x100534C0
// Name: public: void CMainFrame::BeginShellSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::BeginShellSession(CMainFrame *this)
{
  this->m_bShellSessionActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x100534D0
// Name: public: void CMainFrame::EndShellSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::EndShellSession(CMainFrame *this)
{
  this->m_bShellSessionActive = false;
}

//------------------------------------------------------------------------------
// Address: 0x100534E0
// Name: protected: void CMainFrame::OnUpdateOpaqueMaterials(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateOpaqueMaterials(CMainFrame *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: g_materialSystemConfig.bNoTransparency);
}

//------------------------------------------------------------------------------
// Address: 0x10053500
// Name: protected: void CMainFrame::OnOpaqueMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnOpaqueMaterials(CMainFrame *this)
{
  g_materialSystemConfig.bNoTransparency = !g_materialSystemConfig.bNoTransparency;
  materials->OverrideConfig(this: materials, a2: &g_materialSystemConfig, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10053530
// Name: protected: void CMainFrame::OnUpdateView3d(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateView3d(CMainFrame *this, CCmdUI *pCmdUI)
{
  pCmdUI->SetCheck(this: pCmdUI, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10053550
// Name: protected: void CMainFrame::OnEnterMenuLoop(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnEnterMenuLoop(CMainFrame *this, int bIsTrackPopupMenu)
{
  int ActiveTool; // eax

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)CMapDoc::m_pMapDoc->m_pToolManager);
    if ( ActiveTool != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)ActiveTool + 12))(a1: ActiveTool) != 0 )
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053590
// Name: public: virtual int CMainFrame::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::PreCreateWindow(CMainFrame *this, tagCREATESTRUCTA *cs)
{
  cs->style |= 0x1000000u;
  cs->lpszClass = "VALVEWORLDCRAFT";
  return CMDIFrameWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x10053670
// Name: public: virtual int CToolHandler_Disabled::UpdateCmdUI(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolHandler_Disabled::UpdateCmdUI(CToolHandler_Disabled *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: 0);
  pCmdUI->SetCheck(this: pCmdUI, a2: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100536A0
// Name: protected: void CMainFrame::OnViewMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnViewMessages(CMainFrame *this)
{
  CMessageWnd::ToggleMessageWindow(this: g_pwndMessage);
}

//------------------------------------------------------------------------------
// Address: 0x100536B0
// Name: protected: void CMainFrame::OnUpdateViewMessages(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateViewMessages(CMainFrame *this, CCmdUI *pCmdUI)
{
  CCmdUI_vtbl *v2; // edi
  bool IsVisible; // al

  v2 = pCmdUI->__vftable;
  IsVisible = CMessageWnd::IsVisible(this: g_pwndMessage);
  v2->SetCheck(this: pCmdUI, a2: IsVisible);
}

//------------------------------------------------------------------------------
// Address: 0x100536E0
// Name: protected: void CMainFrame::OnEditProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnEditProperties(CMainFrame *this)
{
  BOOL v2; // eax

  v2 = IsWindowVisible(hWnd: this->pObjectProperties->m_hWnd);
  CWnd::ShowWindow(this: this->pObjectProperties, nCmdShow: v2 ? 0 : 5);
}

//------------------------------------------------------------------------------
// Address: 0x10053710
// Name: public: void CMainFrame::UpdateAllDocViews(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::UpdateAllDocViews(CMainFrame *this, unsigned int dwCmd)
{
  int i; // esi
  CMapDoc *Document; // eax

  for ( i = 0; i < CMapDoc::GetDocumentCount(); ++i )
  {
    Document = CMapDoc::GetDocument(index: i);
    if ( Document->m_pGame != nullptr )
      CMapDoc::UpdateAllViews(this: Document, nFlags: dwCmd, ub: nullptr);
  }
  if ( (dwCmd & 0x400) != 0 )
  {
    CFilterControl::UpdateGroupList(this: &this->m_FilterControl);
  }
  else if ( (dwCmd & 0x200) != 0 )
  {
    CFilterControl::UpdateGroupListChecks(this: &this->m_FilterControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053780
// Name: protected: void CMainFrame::OnActivateApp(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnActivateApp(CMainFrame *this, int bActive, unsigned int hTask)
{
  AFX_MODULE_STATE *ModuleState; // eax

  CWnd::Default(this);
  if ( !this->m_bMinimized )
  {
    materials->EvictManagedResources(this: materials);
    ModuleState = AfxGetModuleState();
    CHammer::OnActivateApp(this: (CHammer *)ModuleState->m_pCurrentWinApp, bActive: bActive == 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100537D0
// Name: protected: void CMainFrame::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnSysCommand(CMainFrame *this, unsigned int nID, int lParam)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v5; // eax

  CFrameWnd::OnSysCommand(this, nID, lParam);
  if ( nID == 61472 )
  {
    this->m_bMinimized = true;
    ModuleState = AfxGetModuleState();
    CHammer::OnActivateApp(this: (CHammer *)ModuleState->m_pCurrentWinApp, bActive: false);
  }
  else if ( nID == 61488 || nID == 61728 )
  {
    this->m_bMinimized = false;
    v5 = AfxGetModuleState();
    CHammer::OnActivateApp(this: (CHammer *)v5->m_pCurrentWinApp, bActive: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053840
// Name: public: void CMainFrame::OnDeleteActiveDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnDeleteActiveDocument(CMainFrame *this)
{
  CObjectProperties::MarkDataDirty(this: this->pObjectProperties);
}

//------------------------------------------------------------------------------
// Address: 0x10053850
// Name: protected: void CMainFrame::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnSize(CMainFrame *this, unsigned int nType, int cx, int cy)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-30h]
  CRect rect; // [esp+8h] [ebp-20h] BYREF
  CRect clientrect; // [esp+18h] [ebp-10h] BYREF

  CMDIFrameWnd::OnSize(this, nType, __formal: cx, __formal: cy);
  if ( g_pwndMessage != nullptr )
  {
    m_hWnd = this->wndMDIClient.m_hWnd;
    memset(&clientrect, 0, sizeof(clientrect));
    GetClientRect(hWnd: m_hWnd, lpRect: &clientrect);
    rect.top = clientrect.bottom - clientrect.top - 130;
    rect.right = clientrect.right - clientrect.left;
    rect.left = 0;
    rect.bottom = clientrect.bottom - clientrect.top;
    CMessageWnd::Resize(this: g_pwndMessage, &rect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100538D0
// Name: class CMainFrame __near * GetMainWnd(void)
// Source: json
//------------------------------------------------------------------------------
CMainFrame *__cdecl GetMainWnd()
{
  return g_pMainWnd;
}

//------------------------------------------------------------------------------
// Address: 0x100538E0
// Name: void SetStatusText(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetStatusText(int nIndex, const char *pszText)
{
  CStatusBar::SetPaneText(this: &g_pMainWnd->m_wndStatusBar, nIndex, lpszNewText: pszText, bUpdate: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10053900
// Name: public: void CMainFrame::Configure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::Configure(CMainFrame *this)
{
  COptionProperties v1; // [esp+0h] [ebp-1BECh] BYREF
  int v2; // [esp+1BE8h] [ebp-4h]

  COptionProperties::COptionProperties(this: &v1, pszCaption: "Configure Hammer", pParentWnd: nullptr, iSelectPage: 0);
  v2 = 0;
  if ( CPropertySheet::DoModal(this: &v1) == 1 )
    COptions::Write(this: &Options, fOverwrite: 1, fSaveConfigs: 1);
  v2 = -1;
  COptionProperties::~COptionProperties(this: &v1);
}

//------------------------------------------------------------------------------
// Address: 0x10053980
// Name: protected: void CMainFrame::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnDestroy(CMainFrame *this)
{
  CMDIFrameWnd::OnDestroy(this);
  PostQuitMessage(nExitCode: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10053990
// Name: protected: void CMainFrame::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnPaint(CMainFrame *this)
{
  CPaintDC dc; // [esp+4h] [ebp-60h] BYREF
  int v3; // [esp+60h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v3 = 0;
  if ( bFirst_0 )
  {
    bFirst_0 = false;
    SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
  }
  v3 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x10053A00
// Name: public: void CMainFrame::ResetAutosaveTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::ResetAutosaveTimer(CMainFrame *this)
{
  if ( Options.general.iMaxAutosavesPerMap != 0 )
    SetTimer(hWnd: this->m_hWnd, nIDEvent: 0, uElapse: 60000 * Options.general.iTimeBetweenSaves, lpTimerFunc: nullptr);
  else
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10053A30
// Name: public: class CModelBrowser __near * CMainFrame::GetModelBrowser(void)
// Source: json
//------------------------------------------------------------------------------
CModelBrowser *__thiscall CMainFrame::GetModelBrowser(CMainFrame *this)
{
  CModelBrowser *v2; // eax
  CModelBrowser *v3; // eax

  if ( this->m_pModelBrowser == nullptr )
  {
    v2 = (CModelBrowser *)operator new(nSize: 0x130u);
    if ( v2 != nullptr )
      v3 = CModelBrowser::CModelBrowser(this: v2, pParent: this);
    else
      v3 = nullptr;
    this->m_pModelBrowser = v3;
  }
  return this->m_pModelBrowser;
}

//------------------------------------------------------------------------------
// Address: 0x10053AA0
// Name: protected: int CMainFrame::OnReloadSounds(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::OnReloadSounds(CMainFrame *this, unsigned int nID)
{
  SoundType_t i; // esi

  for ( i = SOUND_TYPE_RAW; i < SOUND_TYPE_COUNT; ++i )
    CSoundSystem::BuildSoundList(this: &g_Sounds, type: i);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053AC0
// Name: public: bool CMainFrame::IsInFaceEditMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMainFrame::IsInFaceEditMode(CMainFrame *this)
{
  CToolManager *v1; // eax
  CToolManager *v2; // eax
  bool result; // al

  v1 = ToolManager();
  result = true;
  if ( CToolManager::GetActiveToolID(this: v1) != TOOL_FACEEDIT_MATERIAL )
  {
    v2 = ToolManager();
    if ( CToolManager::GetActiveToolID(this: v2) != TOOL_FACEEDIT_DISP )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053AF0
// Name: public: virtual CPrefabsDlg::~CPrefabsDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::~CPrefabsDlg(CPrefabsDlg *this)
{
  CImageList::~CImageList(this: &this->PrefabImages);
  CComboBox::~CComboBox(this: &this->m_Libraries);
  CStatic::~CStatic(this: &this->m_LibraryNotes);
  CEdit::~CEdit(this: &this->m_ObjectNotes);
  CListCtrl::~CListCtrl(this: &this->m_Objects);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053B80
// Name: protected: int CMainFrame::OnHelpOpenURL(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMainFrame::OnHelpOpenURL@<eax>(CMainFrame *this@<ecx>, int a2@<edi>, unsigned int nID)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  CHammer::OpenURL(this: (CHammer *)ModuleState->m_pCurrentWinApp, a2, nID, hwnd: this->m_hWnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053BB0
// Name: protected: void CMainFrame::OnEditUndoredoactive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnEditUndoredoactive(CMainFrame *this)
{
  BOOL v1; // eax

  v1 = this->m_bUndoActive == 0;
  this->m_bUndoActive = v1;
  CMapDoc::SetUndoActive(this: CMapDoc::m_pMapDoc, bActive: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10053BE0
// Name: public: void CMainFrame::GlobalNotify(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMainFrame::GlobalNotify(CMainFrame *this@<ecx>, int a2@<edi>, int nCode)
{
  CMapDoc *v3; // ebx
  ToolID_t ActiveToolID; // eax
  CObjectProperties *pObjectProperties; // eax
  COP_Groups *m_pGroups; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v3 = CMapDoc::m_pMapDoc;
  switch ( nCode )
  {
    case 1026:
      CFilterControl::UpdateGroupList(this: &this->m_FilterControl);
      CFilterControl::UpdateCordonList(this: &this->m_FilterControl, pSelectCordon: nullptr, pSelectBox: nullptr);
      pObjectProperties = this->pObjectProperties;
      if ( pObjectProperties != nullptr )
      {
        m_pGroups = pObjectProperties->m_pGroups;
        if ( m_pGroups != nullptr )
          COP_Groups::UpdateGroupList(this: m_pGroups);
      }
      if ( v3 != nullptr )
        CMapDoc::UpdateStatusbar(this: v3, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: (int)this);
      CManifestFilter::UpdateManifestList(this: &this->m_ManifestFilterControl);
      break;
    case 1028:
      CTextureBrowser::SetTextureFormat(this: this->pTextureBrowser, eTextureFormat: g_pGameConfig->textureformat);
      CTextureBar::NotifyGraphicsChanged(this: &this->m_TextureBar);
      CFaceEditMaterialPage::NotifyGraphicsChanged(this: &this->m_pFaceEditSheet->m_MaterialPage);
      if ( v3 != nullptr )
      {
        ActiveToolID = CToolManager::GetActiveToolID(this: v3->m_pToolManager);
        CObjectBar::UpdateListForTool(this: &this->m_ObjectBar, iTool: ActiveToolID);
      }
      break;
    case 1032:
      this->m_bLightingPreviewOutputWindowShowing = false;
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053CC0
// Name: protected: void CMainFrame::OnHDR(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnHDR(CMainFrame *this)
{
  CMenu *v2; // esi

  v2 = this->GetMenu(this);
  if ( (GetMenuState(hMenu: v2->m_hMenu, uId: 0xF000u, uFlags: 0) & 8) != 0 )
  {
    CheckMenuItem(hMenu: v2->m_hMenu, uIDCheckItem: 0xF000u, uCheck: 0);
    g_bHDR = false;
  }
  else
  {
    CheckMenuItem(hMenu: v2->m_hMenu, uIDCheckItem: 0xF000u, uCheck: 8u);
    g_bHDR = true;
  }
  DrawMenuBar(hWnd: this->m_hWnd);
  SignalUpdate(ev: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10053D30
// Name: protected: int CMainFrame::OnUnits(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMainFrame::OnUnits@<eax>(CMainFrame *this@<ecx>, int a2@<edi>, int a3@<esi>, unsigned int nID)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  switch ( nID )
  {
    case 0x814Bu:
      Box3D::m_eWorldUnits = Units_None;
      break;
    case 0x814Cu:
      Box3D::m_eWorldUnits = Units_Inches;
      CMapDoc::UpdateStatusbar(this: CMapDoc::m_pMapDoc, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3);
      return 1;
    case 0x814Du:
      Box3D::m_eWorldUnits = Units_Feet_Inches;
      CMapDoc::UpdateStatusbar(this: CMapDoc::m_pMapDoc, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3);
      return 1;
    default:
      break;
  }
  CMapDoc::UpdateStatusbar(this: CMapDoc::m_pMapDoc, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053DA0
// Name: public: virtual int CMainFrame::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::PreTranslateMessage(CMainFrame *this, tagMSG *pMsg)
{
  return CMDIFrameWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10053DB0
// Name: private: class CChildFrame __near * CMainFrame::GetNextMDIChildWndRecursive(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CChildFrame *__thiscall CMainFrame::GetNextMDIChildWndRecursive(CMainFrame *this, CWnd *pCurChild)
{
  HWND Window; // eax
  HWND v5; // eax
  HWND v6; // eax

  while ( 1 )
  {
    if ( pCurChild == nullptr )
    {
      Window = GetWindow(hWnd: this->wndMDIClient.m_hWnd, uCmd: 5u);
      pCurChild = CWnd::FromHandle(hWnd: Window);
      goto LABEL_4;
    }
    v5 = GetWindow(hWnd: pCurChild->m_hWnd, uCmd: 2u);
    pCurChild = CWnd::FromHandle(hWnd: v5);
    if ( pCurChild == nullptr )
      return nullptr;
LABEL_4:
    v6 = GetWindow(hWnd: pCurChild->m_hWnd, uCmd: 4u);
    if ( CWnd::FromHandle(hWnd: v6) == nullptr
      && CObject::IsKindOf(this: pCurChild, pClass: &CChildFrame::classCChildFrame) != 0 )
    {
      return (CChildFrame *)pCurChild;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053E30
// Name: public: bool CMainFrame::IsShellSessionActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMainFrame::IsShellSessionActive(CMainFrame *this)
{
  return this->m_bShellSessionActive;
}

//------------------------------------------------------------------------------
// Address: 0x10053E40
// Name: protected: void CMainFrame::OnUpdateEditFunction(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateEditFunction(CMainFrame *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: !this->m_bShellSessionActive);
}

//------------------------------------------------------------------------------
// Address: 0x10053E60
// Name: public: void CMainFrame::ShowFaceEditSheetOrTextureBar(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::ShowFaceEditSheetOrTextureBar(CMainFrame *this, bool bShowFaceEditSheet)
{
  CFaceEditSheet *m_pFaceEditSheet; // ecx

  m_pFaceEditSheet = this->m_pFaceEditSheet;
  if ( bShowFaceEditSheet )
  {
    CFaceEditSheet::SetVisibility(this: m_pFaceEditSheet, bVisible: true);
    CFrameWnd::ShowControlBar(this, pBar: &this->m_TextureBar, bShow: 0, bDelay: 1);
  }
  else
  {
    CFaceEditSheet::SetVisibility(this: m_pFaceEditSheet, bVisible: false);
    CFaceEditSheet::CloseAllPageDialogs(this: this->m_pFaceEditSheet);
    CFrameWnd::ShowControlBar(this, pBar: &this->m_TextureBar, bShow: 1, bDelay: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053EC0
// Name: public: void CMainFrame::ShowSearchReplaceDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::ShowSearchReplaceDialog(CMainFrame *this)
{
  CSearchReplaceDlg *v2; // eax
  CSearchReplaceDlg *v3; // eax

  if ( this->m_pSearchReplaceDlg == nullptr )
  {
    v2 = (CSearchReplaceDlg *)operator new(nSize: 0xB0u);
    if ( v2 != nullptr )
      v3 = CSearchReplaceDlg::CSearchReplaceDlg(this: v2, pParent: nullptr);
    else
      v3 = nullptr;
    this->m_pSearchReplaceDlg = v3;
    CSearchReplaceDlg::Create(this: v3, pwndParent: this);
  }
  CWnd::ShowWindow(this: this->m_pSearchReplaceDlg, nCmdShow: 5);
  CWnd::SetFocus(this: this->m_pSearchReplaceDlg);
}

//------------------------------------------------------------------------------
// Address: 0x10053F50
// Name: public: bool CMainFrame::VerifyBarState(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMainFrame::VerifyBarState(CMainFrame *this)
{
  int m_nSize; // eax
  int v2; // ecx
  unsigned int *v3; // edi
  int v4; // ebx
  int v5; // esi
  unsigned int v6; // eax
  CDockState state; // [esp+Ch] [ebp-5Ch] BYREF
  CFrameWnd *v9; // [esp+54h] [ebp-14h]
  int i; // [esp+58h] [ebp-10h]
  int v11; // [esp+64h] [ebp-4h]

  v9 = this;
  CDockState::CDockState(this: &state);
  v11 = 0;
  CDockState::LoadState(this: &state, lpszProfileName: "BarState");
  m_nSize = state.m_arrBarInfo.m_nSize;
  v2 = 0;
  i = 0;
  if ( state.m_arrBarInfo.m_nSize <= 0 )
  {
LABEL_18:
    v11 = -1;
    CDockState::~CDockState(this: &state);
    return 1;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= m_nSize )
      goto LABEL_20;
    v3 = (unsigned int *)state.m_arrBarInfo.m_pData[v2];
    v4 = v3[19];
    if ( v4 > 0 )
    {
      v5 = 0;
      while ( v5 >= 0 && v5 < (int)v3[19] )
      {
        v6 = *(_DWORD *)(v3[18] + 4 * v5);
        if ( v6 != 0 )
        {
          if ( v6 > 0xFFFF )
            v6 = (unsigned __int16)*(_DWORD *)(v3[18] + 4 * v5);
          if ( CFrameWnd::GetControlBar(this: v9, nID: v6) == nullptr )
            goto LABEL_19;
          v2 = i;
        }
        if ( ++v5 >= v4 )
          goto LABEL_14;
      }
LABEL_20:
      AfxThrowInvalidArgException();
    }
LABEL_14:
    if ( v3[2] == 0 )
      break;
LABEL_17:
    m_nSize = state.m_arrBarInfo.m_nSize;
    i = ++v2;
    if ( v2 >= state.m_arrBarInfo.m_nSize )
      goto LABEL_18;
  }
  if ( CFrameWnd::GetControlBar(this: v9, nID: *v3) != nullptr )
  {
    v2 = i;
    goto LABEL_17;
  }
LABEL_19:
  v11 = -1;
  CDockState::~CDockState(this: &state);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10054080
// Name: public: virtual void CMainFrame::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMainFrame::WinHelpA(CMainFrame *this@<ecx>, int a2@<edi>, unsigned int dwData, unsigned int nCmd)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  CHammer::OpenURL(this: (CHammer *)ModuleState->m_pCurrentWinApp, a2, nID: 0x80ACu, hwnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x100540A0
// Name: protected: void CMainFrame::OnFoundrySendSelectedEntitiesToEngine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnFoundrySendSelectedEntitiesToEngine(CMainFrame *this)
{
  if ( g_pFoundryTool != nullptr )
    g_pFoundryTool->ConsoleCommand(this: g_pFoundryTool, a2: "foundry_send_ents_to_engine");
}

//------------------------------------------------------------------------------
// Address: 0x100540C0
// Name: protected: void CMainFrame::OnFoundryMoveEngineViewToHammer3DView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnFoundryMoveEngineViewToHammer3DView(CMainFrame *this)
{
  if ( g_pFoundryTool != nullptr )
    g_pFoundryTool->ConsoleCommand(this: g_pFoundryTool, a2: "foundry_sync_engine_view");
}

//------------------------------------------------------------------------------
// Address: 0x100540E0
// Name: protected: void CMainFrame::OnFoundryRemoveSelectedEntitiesFromEngine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnFoundryRemoveSelectedEntitiesFromEngine(CMainFrame *this)
{
  if ( g_pFoundryTool != nullptr )
    g_pFoundryTool->ConsoleCommand(this: g_pFoundryTool, a2: "foundry_remove_selected");
}

//------------------------------------------------------------------------------
// Address: 0x10054120
// Name: protected: void CMainFrame::OnFoundryMoveFocusToEngine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnFoundryMoveFocusToEngine(CMainFrame *this)
{
  if ( g_pFoundryTool != nullptr )
    g_pFoundryTool->ConsoleCommand(this: g_pFoundryTool, a2: "foundry_move_focus_to_engine");
}

//------------------------------------------------------------------------------
// Address: 0x10054140
// Name: protected: long CMainFrame::OnWTPacket(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::OnWTPacket(CMainFrame *this, unsigned int wSerial, int hCtx)
{
  WinTab_Packet(wSerial, hContext: hCtx);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100541E0
// Name: public: virtual CManifestListBox::~CManifestListBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestListBox::~CManifestListBox(CManifestListBox *this)
{
  CMenu *p_m_ManifestFilterBlankMenu; // ecx

  p_m_ManifestFilterBlankMenu = &this->m_ManifestFilterBlankMenu;
  p_m_ManifestFilterBlankMenu->__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: p_m_ManifestFilterBlankMenu);
  this->m_ManifestFilterPrimaryMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &this->m_ManifestFilterPrimaryMenu);
  this->m_ManifestFilterSecondaryMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &this->m_ManifestFilterSecondaryMenu);
  this->m_ManifestFilterMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &this->m_ManifestFilterMenu);
  CImageList::~CImageList(this: &this->m_Icons);
  CListBox::~CListBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x100542B0
// Name: private: void CMainFrame::DockControlBarLeftOf(class CControlBar __near *,class CControlBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::DockControlBarLeftOf(CMainFrame *this, CControlBar *Bar, CControlBar *LeftOf)
{
  void (__thiscall *RecalcLayout)(CFrameWnd *, int); // edx
  unsigned int m_dwStyle; // edi
  unsigned int v6; // eax
  CRect rect; // [esp+Ch] [ebp-10h] BYREF

  RecalcLayout = this->RecalcLayout;
  memset(&rect, 0, sizeof(rect));
  RecalcLayout(this, a2: 1);
  GetWindowRect(hWnd: LeftOf->m_hWnd, lpRect: &rect);
  OffsetRect(lprc: &rect, dx: 1, dy: 0);
  m_dwStyle = LeftOf->m_dwStyle;
  v6 = 0;
  if ( (m_dwStyle & 0x2000) != 0 )
    v6 = 59419;
  if ( (m_dwStyle & 0x8000) != 0 && v6 == 0 )
    v6 = 59422;
  if ( (m_dwStyle & 0x1000) != 0 && v6 == 0 )
    v6 = 59420;
  if ( (m_dwStyle & 0x4000) != 0 && v6 == 0 )
    v6 = 59421;
  CFrameWnd::DockControlBar(this, pBar: Bar, nDockBarID: v6, lpRect: &rect);
}

//------------------------------------------------------------------------------
// Address: 0x10054360
// Name: protected: void CMainFrame::OnUpdateToolUI(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateToolUI(CMainFrame *this, CCmdUI *pUI)
{
  CMapDoc *v2; // edi
  unsigned __int8 IsSelectionEditable; // al
  unsigned int m_nID; // ecx
  int v5; // ebx
  ToolID_t v6; // edi
  CCmdUI_vtbl *v7; // ebx
  CToolManager *v8; // eax
  ToolID_t ActiveToolID; // eax

  if ( this->m_bShellSessionActive )
  {
    pUI->Enable(this: pUI, a2: 0);
  }
  else
  {
    v2 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr )
      IsSelectionEditable = CMapDoc::IsSelectionEditable(this: CMapDoc::m_pMapDoc);
    else
      IsSelectionEditable = 0;
    m_nID = pUI->m_nID;
    if ( m_nID != 33008 && m_nID != 33107 && m_nID != 32955 && m_nID != 32952 )
      IsSelectionEditable = v2 != nullptr;
    v5 = IsSelectionEditable;
    pUI->Enable(this: pUI, a2: IsSelectionEditable);
    if ( pUI->m_nID != 41006
      || g_pToolHandlerSyncMesh == nullptr
      || g_pToolHandlerSyncMesh->UpdateCmdUI(this: g_pToolHandlerSyncMesh, a2: pUI) == 0 )
    {
      v6 = ToolMsgToEnum(uMsg: pUI->m_nID);
      pUI->Enable(this: pUI, a2: v5);
      v7 = pUI->__vftable;
      v8 = ToolManager();
      ActiveToolID = CToolManager::GetActiveToolID(this: v8);
      v7->SetCheck(this: pUI, a2: v6 == ActiveToolID);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054420
// Name: public: void CMainFrame::SetBrightness(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::SetBrightness(CMainFrame *this, float fBrightness)
{
  float v2; // xmm0_4
  int v4; // esi
  CToolManager *v5; // eax
  int i; // esi
  CMapDoc *Document; // eax

  v2 = fBrightness;
  if ( fBrightness >= 0.1 && fBrightness <= 5.0 )
  {
    v4 = 0;
    Options.textures.fBrightness = fBrightness;
    if ( Options.configs.nConfigs > 0 )
    {
      while ( 1 )
      {
        if ( v4 < 0 || v4 >= Options.configs.Configs.m_nSize )
          AfxThrowInvalidArgException();
        CGamePalette::SetBrightness(
          this: (CGamePalette *)((char *)Options.configs.Configs.m_pData[v4++] + 1920),
          fValue: v2);
        if ( v4 >= Options.configs.nConfigs )
          break;
        v2 = fBrightness;
      }
    }
    CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&g_Textures);
    v5 = ToolManager();
    if ( CToolManager::GetActiveToolID(this: v5) == TOOL_FACEEDIT_MATERIAL )
      RedrawWindow(hWnd: this->m_pFaceEditSheet->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    else
      RedrawWindow(hWnd: this->m_TextureBar.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    for ( i = 0; i < CMapDoc::GetDocumentCount(); ++i )
    {
      Document = CMapDoc::GetDocument(index: i);
      if ( Document->m_pGame != nullptr )
        CMapDoc::UpdateAllViews(this: Document, nFlags: 68, ub: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054520
// Name: protected: int CMainFrame::OnView3dChangeBrightness(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::OnView3dChangeBrightness(CMainFrame *this, unsigned int nID)
{
  float v2; // xmm0_4

  if ( nID == 32909 )
    v2 = 0.2;
  else
    v2 = -0.2;
  CMainFrame::SetBrightness(this, fBrightness: v2 + Options.textures.fBrightness);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10054560
// Name: protected: void CMainFrame::OnUpdateApplicatorUI(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateApplicatorUI(CMainFrame *this, CCmdUI *pUI)
{
  CToolManager *v2; // eax
  CToolManager *v3; // eax
  bool v4; // al

  if ( this->m_bShellSessionActive )
  {
    pUI->Enable(this: pUI, a2: 0);
  }
  else
  {
    v2 = ToolManager();
    v4 = true;
    if ( CToolManager::GetActiveToolID(this: v2) != TOOL_FACEEDIT_MATERIAL )
    {
      v3 = ToolManager();
      if ( CToolManager::GetActiveToolID(this: v3) != TOOL_FACEEDIT_DISP )
        v4 = false;
    }
    pUI->SetCheck(this: pUI, a2: v4);
    pUI->Enable(this: pUI, a2: CMapDoc::m_pMapDoc != nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100545D0
// Name: protected: void CMainFrame::OnToolsPrefabfactory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnToolsPrefabfactory(CMainFrame *this)
{
  CToolManager *v2; // eax
  ToolID_t ActiveToolID; // eax
  CPrefabsDlg dlg; // [esp+4h] [ebp-284h] BYREF
  int v5; // [esp+284h] [ebp-4h]

  CPrefabsDlg::CPrefabsDlg(this: &dlg, pParent: nullptr);
  v5 = 0;
  CDialog::DoModal(this: &dlg);
  CPrefabLibrary::LoadAllLibraries();
  v2 = ToolManager();
  ActiveToolID = CToolManager::GetActiveToolID(this: v2);
  CObjectBar::UpdateListForTool(this: &this->m_ObjectBar, iTool: ActiveToolID);
  v5 = -1;
  CPrefabsDlg::~CPrefabsDlg(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x10054650
// Name: protected: void CMainFrame::OnUpdateEditUndoredoactive(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateEditUndoredoactive(CMainFrame *this, CCmdUI *pCmdUI)
{
  const char *v3; // eax

  pCmdUI->Enable(this: pCmdUI, a2: !this->m_bShellSessionActive);
  v3 = "Disable Undo/Redo";
  if ( this->m_bUndoActive == 0 )
    v3 = "Enable Undo/Redo";
  pCmdUI->SetText(this: pCmdUI, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100546A0
// Name: protected: void CMainFrame::OnUpdateUnits(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnUpdateUnits(CMainFrame *this, CCmdUI *pCmdUI)
{
  unsigned int m_nID; // eax

  pCmdUI->Enable(this: pCmdUI, a2: !this->m_bShellSessionActive);
  m_nID = pCmdUI->m_nID;
  switch ( m_nID )
  {
    case 0x814Bu:
      pCmdUI->SetCheck(this: pCmdUI, a2: Box3D::m_eWorldUnits == Units_None);
      break;
    case 0x814Cu:
      pCmdUI->SetCheck(this: pCmdUI, a2: Box3D::m_eWorldUnits == Units_Inches);
      break;
    case 0x814Du:
      pCmdUI->SetCheck(this: pCmdUI, a2: Box3D::m_eWorldUnits == Units_Feet_Inches);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054730
// Name: public: virtual std::basic_iostream<char,struct std::char_traits<char>>::~basic_iostream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::iostream::~iostream<char,std::char_traits<char>>(std::iostream *this)
{
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 6) + 4) - 24) = &std::iostream::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 2) + 4) - 8) = &std::ostream::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 6) + 4) - 24) = &std::istream::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10054870
// Name: protected: int CMainFrame::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMainFrame::OnCreate@<eax>(
        CMainFrame *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        tagCREATESTRUCTA *lpCreateStruct)
{
  HBITMAP__ *p_m_bmMapEditTools256; // eax
  unsigned int *p_nStyle; // eax
  CFaceEditSheet *v8; // eax
  CFaceEditSheet *v9; // eax
  CObjectProperties *v10; // eax
  CObjectProperties *v11; // eax
  CMainFrame *v12; // edi
  int (__thiscall *Create)(CDialog *, unsigned int, CWnd *); // edx
  CToolManager *v14; // eax
  CTextureBrowser *v15; // eax
  CTextureBrowser *v16; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-6Ch]
  tagWINDOWPLACEMENT wp; // [esp+4h] [ebp-58h] BYREF
  CRect rect; // [esp+30h] [ebp-2Ch] BYREF
  CRect clientrect; // [esp+40h] [ebp-1Ch] BYREF
  int v21; // [esp+58h] [ebp-4h]
  unsigned int *lpCreateStructa; // [esp+64h] [ebp+8h]

  lpCreateStruct->lpszClass = "VALVEWORLDCRAFT";
  if ( CFrameWnd::OnCreate(this, lpcs: lpCreateStruct) == -1
    || CWnd::SubclassWindow(this: &this->wndMDIClient, hWnd: this->m_hWndMDIClient) == 0 )
  {
    return -1;
  }
  if ( this->m_wndMapToolBar.Create(this: &this->m_wndMapToolBar, a2: this, a3: 1342187520u, a4: 59402u) == 0 )
    return -1;
  if ( CToolBar::LoadToolBar(this: &this->m_wndMapToolBar, lpszResourceName: (const char *)0x81) == 0 )
    return -1;
  CWnd::ModifyStyle(this: &this->m_wndMapToolBar, dwRemove: 0, dwAdd: 0x800u, nFlags: 0);
  if ( this->m_wndUndoRedoToolBar.Create(this: &this->m_wndUndoRedoToolBar, a2: this, a3: 1342187520u, a4: 59408u) == 0
    || CToolBar::LoadToolBar(this: &this->m_wndUndoRedoToolBar, lpszResourceName: (const char *)0x146) == 0 )
  {
    return -1;
  }
  CWnd::ModifyStyle(this: &this->m_wndUndoRedoToolBar, dwRemove: 0, dwAdd: 0x800u, nFlags: 0);
  ((void (__thiscall *)(CToolBar *, CMainFrame *, int, int, int, int))this->m_wndMapEditToolBar.Create)(
    a1: &this->m_wndMapEditToolBar,
    a2: this,
    a3: 1342187520,
    a4: 59401,
    a5: a2,
    a6: a3);
  CWnd::ModifyStyle(this: &this->m_wndMapEditToolBar, dwRemove: 0, dwAdd: 0x800u, nFlags: 0);
  CToolBar::LoadToolBar(this: &this->m_wndMapEditToolBar, lpszResourceName: (const char *)0x102);
  CBitmap::LoadBitmapA(this: &this->m_bmMapEditTools256, nIDResource: 0x11Cu);
  p_m_bmMapEditTools256 = (HBITMAP__ *)&this->m_bmMapEditTools256;
  if ( this != (CMainFrame *)-5084 )
    p_m_bmMapEditTools256 = (HBITMAP__ *)this->m_bmMapEditTools256.m_hObject;
  CToolBar::SetBitmap(this: &this->m_wndMapEditToolBar, hbmImageWell: p_m_bmMapEditTools256);
  if ( ((int (__thiscall *)(CToolBar *, CMainFrame *))this->m_wndMapOps.Create)(a1: &this->m_wndMapOps, a2: this) == 0 )
    return -1;
  if ( CToolBar::LoadToolBar(this: &this->m_wndMapOps, lpszResourceName: (const char *)0x104) == 0 )
    return -1;
  CWnd::ModifyStyle(this: &this->m_wndMapOps, dwRemove: 0, dwAdd: 0x800u, nFlags: 0);
  if ( this->m_wndStatusBar.Create(this: &this->m_wndStatusBar, a2: this, a3: 1342210560u, a4: 59393u) == 0
    || CStatusBar::SetIndicators(this: &this->m_wndStatusBar, lpIDArray: nullptr, nIDCount: 7) == 0 )
  {
    return -1;
  }
  p_nStyle = &paneinfo[0].nStyle;
  for ( lpCreateStructa = &paneinfo[0].nStyle; ; p_nStyle = lpCreateStructa )
  {
    CStatusBar::SetPaneInfo(
      this: &this->m_wndStatusBar,
      nIndex: *(p_nStyle - 2),
      nID: *(p_nStyle - 1),
      nStyle: *p_nStyle,
      cxWidth: p_nStyle[1]);
    lpCreateStructa += 4;
    if ( (int)lpCreateStructa >= (int)&vec4_invalid_37 )
      break;
  }
  CFrameWnd::EnableDocking(this, dwDockStyle: 0xF000u);
  CControlBar::SetBarStyle(this: &this->m_wndMapToolBar, dwStyle: this->m_wndMapToolBar.m_dwStyle | 0x34);
  CControlBar::SetBarStyle(this: &this->m_wndUndoRedoToolBar, dwStyle: this->m_wndUndoRedoToolBar.m_dwStyle | 0x34);
  CControlBar::SetBarStyle(this: &this->m_wndMapEditToolBar, dwStyle: this->m_wndMapEditToolBar.m_dwStyle | 0x34);
  CControlBar::SetBarStyle(this: &this->m_wndMapOps, dwStyle: this->m_wndMapOps.m_dwStyle | 0x34);
  CControlBar::EnableDocking(this: &this->m_wndMapToolBar, dwDockStyle: 0xF000u);
  CControlBar::EnableDocking(this: &this->m_wndUndoRedoToolBar, dwDockStyle: 0xF000u);
  CControlBar::EnableDocking(this: &this->m_wndMapEditToolBar, dwDockStyle: 0xF000u);
  CControlBar::EnableDocking(this: &this->m_wndMapOps, dwDockStyle: 0xF000u);
  CFrameWnd::DockControlBar(this, pBar: &this->m_wndMapEditToolBar, nDockBarID: 0xE81Cu, lpRect: nullptr);
  CFrameWnd::DockControlBar(this, pBar: &this->m_wndMapToolBar, nDockBarID: 0xE81Bu, lpRect: nullptr);
  CMainFrame::DockControlBarLeftOf(this, Bar: &this->m_wndUndoRedoToolBar, LeftOf: &this->m_wndMapToolBar);
  CMainFrame::DockControlBarLeftOf(this, Bar: &this->m_wndMapOps, LeftOf: &this->m_wndUndoRedoToolBar);
  CObjectBar::Create(this: &this->m_ObjectBar, pParentWnd: this);
  CControlBar::SetBarStyle(this: &this->m_ObjectBar, dwStyle: this->m_ObjectBar.m_dwStyle | 0x32);
  CControlBar::EnableDocking(this: &this->m_ObjectBar, dwDockStyle: 0x5000u);
  CFrameWnd::DockControlBar(this, pBar: &this->m_ObjectBar, nDockBarID: 0xE81Du, lpRect: nullptr);
  CFilterControl::Create(this: &this->m_FilterControl, pParentWnd: this);
  CControlBar::SetBarStyle(this: &this->m_FilterControl, dwStyle: this->m_FilterControl.m_dwStyle | 0x32);
  CControlBar::EnableDocking(this: &this->m_FilterControl, dwDockStyle: 0x5000u);
  CMainFrame::DockControlBarLeftOf(this, Bar: &this->m_FilterControl, LeftOf: &this->m_ObjectBar);
  CTextureBar::Create(this: &this->m_TextureBar, pParentWnd: this, IDD: 171, iBarID: 59403);
  CControlBar::SetBarStyle(this: &this->m_TextureBar, dwStyle: this->m_TextureBar.m_dwStyle | 0x32);
  CControlBar::EnableDocking(this: &this->m_TextureBar, dwDockStyle: 0x5000u);
  CMainFrame::DockControlBarLeftOf(this, Bar: &this->m_TextureBar, LeftOf: &this->m_FilterControl);
  CManifestFilter::Create(this: &this->m_ManifestFilterControl, pParentWnd: this);
  CControlBar::SetBarStyle(
    this: &this->m_ManifestFilterControl,
    dwStyle: this->m_ManifestFilterControl.m_dwStyle | 0x32);
  CControlBar::EnableDocking(this: &this->m_ManifestFilterControl, dwDockStyle: 0x5000u);
  CFrameWnd::DockControlBar(this, pBar: &this->m_ManifestFilterControl, nDockBarID: 0xE81Du, lpRect: nullptr);
  v8 = (CFaceEditSheet *)operator new(nSize: 0x1684u);
  v21 = 0;
  if ( v8 != nullptr )
    v9 = CFaceEditSheet::CFaceEditSheet(this: v8, pszCaption: "Face Edit Sheet", pParentWnd: this, iSelectPage: 0);
  else
    v9 = nullptr;
  v21 = -1;
  this->m_pFaceEditSheet = v9;
  CFaceEditSheet::Setup(this: v9);
  CFaceEditSheet::Create(this: this->m_pFaceEditSheet, pParentWnd: this);
  CFaceEditSheet::SetVisibility(this: this->m_pFaceEditSheet, bVisible: false);
  this->m_pLightingPreviewOutputWindow = nullptr;
  CSelectModeDlgBar::Create(this: &this->m_SelectModeDlg, pParentWnd: this);
  CControlBar::SetBarStyle(this: &this->m_SelectModeDlg, dwStyle: this->m_TextureBar.m_dwStyle | 0x32);
  CControlBar::EnableDocking(this: &this->m_SelectModeDlg, dwDockStyle: 0x5000u);
  CMainFrame::DockControlBarLeftOf(this, Bar: &this->m_SelectModeDlg, LeftOf: &this->m_TextureBar);
  v10 = (CObjectProperties *)operator new(nSize: 0x150u);
  v21 = 1;
  if ( v10 != nullptr )
    v11 = CObjectProperties::CObjectProperties(this: v10);
  else
    v11 = nullptr;
  v21 = -1;
  this->pObjectProperties = v11;
  CObjectProperties::SetupPages(this: v11);
  v12 = this;
  if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) != 0 )
    v12 = nullptr;
  ((void (__stdcall *)(CMainFrame *, int, _DWORD))this->pObjectProperties->Create_2)(a1: v12, a2: -2134114176, a3: 0);
  Create = this->m_SmoothingGroupDlg.Create;
  g_pMainWnd = this;
  Create(this: &this->m_SmoothingGroupDlg, a2: 319u, a3: this);
  m_hWnd = this->wndMDIClient.m_hWnd;
  memset(&clientrect, 0, sizeof(clientrect));
  GetClientRect(hWnd: m_hWnd, lpRect: &clientrect);
  rect.bottom = clientrect.bottom - clientrect.top;
  rect.right = clientrect.right - clientrect.left;
  rect.left = 0;
  rect.top = clientrect.bottom - clientrect.top - 90;
  CMessageWnd::CreateMessageWindow(this: g_pwndMessage, pwndParent: this, &rect);
  CPrefabLibrary::LoadAllLibraries();
  v14 = ToolManager();
  CToolManager::SetTool(this: v14, eNewTool: TOOL_POINTER);
  v15 = (CTextureBrowser *)operator new(nSize: 0xD00u);
  v21 = 2;
  if ( v15 != nullptr )
    v16 = CTextureBrowser::CTextureBrowser(this: v15, pParent: this);
  else
    v16 = nullptr;
  v21 = -1;
  this->pTextureBrowser = v16;
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  CWnd::SetWindowPlacement(this, lpwndpl: &wp);
  if ( CMainFrame::VerifyBarState(this) != 0 )
    CFrameWnd::LoadBarState(this, lpszProfileName: "Barstate");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10054E70
// Name: protected: int CMainFrame::OnChangeTool(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::OnChangeTool(CMainFrame *this, unsigned int nMessageID)
{
  CToolManager *v3; // eax
  CToolManager *v4; // eax
  CMapDoc *v5; // edi
  CToolManager *v6; // eax
  ToolID_t v8; // [esp-4h] [ebp-8h]

  v3 = ToolManager();
  if ( CToolManager::GetActiveToolID(this: v3) == TOOL_FACEEDIT_MATERIAL
    || (v4 = ToolManager(), CToolManager::GetActiveToolID(this: v4) == TOOL_FACEEDIT_DISP) )
  {
    v5 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      CFaceEditSheet::SetVisibility(this: this->m_pFaceEditSheet, bVisible: false);
      CFaceEditSheet::CloseAllPageDialogs(this: this->m_pFaceEditSheet);
      CFrameWnd::ShowControlBar(this, pBar: &this->m_TextureBar, bShow: 1, bDelay: 1);
      CMapDoc::UpdateForApplicator(this: v5, a2: (int)v5, bApplicator: nullptr);
    }
  }
  if ( nMessageID != 41006
    || g_pToolHandlerSyncMesh == nullptr
    || g_pToolHandlerSyncMesh->Execute(this: g_pToolHandlerSyncMesh, a2: 41006u) == 0 )
  {
    v8 = ToolMsgToEnum(uMsg: nMessageID);
    v6 = ToolManager();
    CToolManager::SetTool(this: v6, eNewTool: v8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10054F20
// Name: protected: void CMainFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnClose(CMainFrame *this)
{
  CDocument *v2; // ebx
  CChildFrame *NextMDIChildWndRecursive; // eax
  CWinApp *m_pCurrentWinApp; // edi
  AFX_MODULE_STATE *ModuleState; // eax

  v2 = this->GetActiveDocument(this);
  if ( v2 == nullptr || v2->CanCloseFrame(this: v2, a2: this) != 0 )
  {
    NextMDIChildWndRecursive = CMainFrame::GetNextMDIChildWndRecursive(this, pCurChild: nullptr);
    if ( NextMDIChildWndRecursive != nullptr )
      CChildFrame::SaveOptions(this: NextMDIChildWndRecursive);
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    if ( m_pCurrentWinApp == nullptr || m_pCurrentWinApp->m_pMainWnd != this )
      goto LABEL_10;
    if ( v2 != nullptr || m_pCurrentWinApp->SaveAllModified(this: m_pCurrentWinApp) != 0 )
    {
      CWinApp::CloseAllDocuments(this: m_pCurrentWinApp, bEndSession: 0);
LABEL_10:
      ModuleState = AfxGetModuleState();
      CHammer::BeginClosing(this: (CHammer *)ModuleState->m_pCurrentWinApp);
      CFaceEditSheet::SetVisibility(this: this->m_pFaceEditSheet, bVisible: false);
      CFaceEditSheet::CloseAllPageDialogs(this: this->m_pFaceEditSheet);
      CFrameWnd::ShowControlBar(this, pBar: &this->m_TextureBar, bShow: 1, bDelay: 1);
      CFrameWnd::SaveBarState(this, lpszProfileName: "Barstate");
      this->m_SmoothingGroupDlg.DestroyWindow(this: &this->m_SmoothingGroupDlg);
      Options.general.bClosedCorrectly = 1;
      COptions::Write(this: &Options, fOverwrite: 1, fSaveConfigs: 1);
      CFrameWnd::OnClose(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055010
// Name: protected: void CMainFrame::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnTimer(CMainFrame *this, unsigned int nIDEvent)
{
  AFX_MODULE_STATE *ModuleState; // eax

  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    if ( nIDEvent != 0 )
    {
      if ( nIDEvent == 1 )
      {
        KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
        if ( Options.configs.nConfigs != 0 )
        {
          COptions::SetClosedCorrectly(this: &Options, bClosed: 0);
          CMainFrame::SetBrightness(this, fBrightness: Options.textures.fBrightness);
          InvalidateRect(hWnd: this->m_TextureBar.m_hWnd, lpRect: nullptr, bErase: true);
          if ( Options.general.iMaxAutosavesPerMap != 0 )
            SetTimer(
              hWnd: this->m_hWnd,
              nIDEvent: 0,
              uElapse: 60000 * Options.general.iTimeBetweenSaves,
              lpTimerFunc: nullptr);
        }
      }
    }
    else
    {
      ModuleState = AfxGetModuleState();
      CHammer::Autosave(this: (CHammer *)ModuleState->m_pCurrentWinApp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100550C0
// Name: protected: int CMainFrame::OnApplicator(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::OnApplicator(CMainFrame *this, unsigned int nID)
{
  CToolManager *v3; // eax
  CToolManager *v4; // eax
  bool v5; // al
  CMapDoc *v6; // esi
  bool v7; // bl
  CToolManager *v8; // eax

  v3 = ToolManager();
  v5 = true;
  if ( CToolManager::GetActiveToolID(this: v3) != TOOL_FACEEDIT_MATERIAL )
  {
    v4 = ToolManager();
    if ( CToolManager::GetActiveToolID(this: v4) != TOOL_FACEEDIT_DISP )
      v5 = false;
  }
  v6 = CMapDoc::m_pMapDoc;
  v7 = !v5;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CMainFrame::ShowFaceEditSheetOrTextureBar(this, bShowFaceEditSheet: !v5);
    CMapDoc::UpdateForApplicator(this: v6, a2: (int)this, bApplicator: (CMapClass *)v7);
  }
  if ( !v7 )
  {
    v8 = ToolManager();
    CToolManager::SetTool(this: v8, eNewTool: TOOL_POINTER);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055170
// Name: public: CObjectBar::tagprevsel::tagblock::~tagblock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::tagprevsel::tagblock::~tagblock(CObjectBar::tagprevsel::tagentity *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax

  v2 = (volatile signed __int32 *)(this->strCategory.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->strItem.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10055200
// Name: public: virtual CSoundBrowser::~CSoundBrowser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::~CSoundBrowser(CSoundBrowser *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax

  CComboBox::~CComboBox(this: &this->m_cFilter);
  v2 = (volatile signed __int32 *)(this->m_SoundSource.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_SoundFile.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_SoundNameSelected.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  CListBox::~CListBox(this: &this->m_SoundList);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055300
// Name: public: EntityReportFilterParms_t::~EntityReportFilterParms_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EntityReportFilterParms_t::~EntityReportFilterParms_t(EntityReportFilterParms_t *this)
{
  CUtlString *p_m_filterClass; // esi
  CUtlString *p_m_filterValue; // esi
  CUtlString *p_m_filterKey; // esi

  p_m_filterClass = &this->m_filterClass;
  this->m_filterClass.m_Storage.m_nActualLength = 0;
  if ( this->m_filterClass.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_filterClass->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_filterClass->m_Storage.m_Memory.m_pMemory);
      p_m_filterClass->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    p_m_filterClass->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  p_m_filterValue = &this->m_filterValue;
  this->m_filterValue.m_Storage.m_nActualLength = 0;
  if ( this->m_filterValue.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_filterValue->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_filterValue->m_Storage.m_Memory.m_pMemory);
      p_m_filterValue->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_filterValue.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  p_m_filterKey = &this->m_filterKey;
  this->m_filterKey.m_Storage.m_nActualLength = 0;
  if ( this->m_filterKey.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_filterKey->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_filterKey->m_Storage.m_Memory.m_pMemory);
      p_m_filterKey->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_filterKey.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100553D0
// Name: public: CObjectBar::tagprevsel::~tagprevsel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::tagprevsel::~tagprevsel(CObjectBar::tagprevsel *this)
{
  CObjectBar::tagprevsel::tagentity *p_entity; // esi
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax
  volatile signed __int32 *v5; // eax
  volatile signed __int32 *v6; // eax

  p_entity = &this->entity;
  v3 = (volatile signed __int32 *)(this->entity.strCategory.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(p_entity->strItem.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  v5 = (volatile signed __int32 *)(this->block.strCategory.m_pszData - 16);
  if ( _InterlockedDecrement(v5 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(a1: v5);
  v6 = (volatile signed __int32 *)(this->block.strItem.m_pszData - 16);
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100554C0
// Name: protected: int CMainFrame::OnSoundBrowser(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMainFrame::OnSoundBrowser(CMainFrame *this, unsigned int nID)
{
  CSoundBrowser dlg; // [esp+0h] [ebp-4C0h] BYREF
  int v4; // [esp+4BCh] [ebp-4h]

  CSoundBrowser::CSoundBrowser(this: &dlg, pCurrentSoundName: &var, pParent: nullptr);
  v4 = 0;
  CSoundBrowser::DoModal(this: &dlg);
  v4 = -1;
  CSoundBrowser::~CSoundBrowser(this: &dlg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055560
// Name: public: CTextureBar::CTextureBar(void)
// Source: json
//------------------------------------------------------------------------------
CTextureBar *__thiscall CTextureBar::CTextureBar(CTextureBar *this)
{
  ControlInfo_t *m_pMemory; // ecx

  CDialogBar::CDialogBar(this);
  this->__vftable = (CTextureBar_vtbl *)&CHammerBar::`vftable';
  this->m_sizeDocked.cx = 0;
  this->m_sizeDocked.cy = 0;
  this->m_sizeFloating.cx = 0;
  this->m_sizeFloating.cy = 0;
  this->m_ControlList.m_Memory.m_pMemory = nullptr;
  this->m_ControlList.m_Memory.m_nAllocationCount = 0;
  this->m_ControlList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_ControlList.m_Memory.m_pMemory;
  this->m_ControlList.m_Size = 0;
  this->m_ControlList.m_pElements = m_pMemory;
  this->__vftable = (CTextureBar_vtbl *)&CTextureBar::`vftable';
  CTextureBox::CTextureBox(this: &this->m_TextureList);
  CWnd::CWnd(this: &this->m_TextureGroupList);
  this->m_TextureGroupList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_TexturePic);
  this->m_TexturePic.__vftable = (wndTex_vtbl *)&CStatic::`vftable';
  this->m_TexturePic.__vftable = (wndTex_vtbl *)&wndTex::`vftable';
  this->m_TexturePic.m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100556E0
// Name: public: CManifestFilter::CManifestFilter(void)
// Source: json
//------------------------------------------------------------------------------
CManifestFilter *__thiscall CManifestFilter::CManifestFilter(CManifestFilter *this)
{
  ControlInfo_t *m_pMemory; // ecx

  CDialogBar::CDialogBar(this);
  this->__vftable = (CManifestFilter_vtbl *)&CHammerBar::`vftable';
  this->m_sizeDocked.cx = 0;
  this->m_sizeDocked.cy = 0;
  this->m_sizeFloating.cx = 0;
  this->m_sizeFloating.cy = 0;
  this->m_ControlList.m_Memory.m_pMemory = nullptr;
  this->m_ControlList.m_Memory.m_nAllocationCount = 0;
  this->m_ControlList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_ControlList.m_Memory.m_pMemory;
  this->m_ControlList.m_Size = 0;
  this->m_ControlList.m_pElements = m_pMemory;
  this->__vftable = (CManifestFilter_vtbl *)&CManifestFilter::`vftable';
  CManifestListBox::CManifestListBox(this: &this->m_ManifestList);
  this->bInitialized = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100557C0
// Name: public: virtual CBitmap::~CBitmap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmap::~CBitmap(CBitmap *this)
{
  this->__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055800
// Name: public: CSelectModeDlgBar::CSelectModeDlgBar(void)
// Source: json
//------------------------------------------------------------------------------
CSelectModeDlgBar *__thiscall CSelectModeDlgBar::CSelectModeDlgBar(CSelectModeDlgBar *this)
{
  CDialogBar::CDialogBar(this);
  this->__vftable = (CSelectModeDlgBar_vtbl *)&CHammerBar::`vftable';
  this->m_sizeDocked.cx = 0;
  this->m_sizeDocked.cy = 0;
  this->m_sizeFloating.cx = 0;
  this->m_sizeFloating.cy = 0;
  this->m_ControlList.m_Memory.m_pMemory = nullptr;
  this->m_ControlList.m_Memory.m_nAllocationCount = 0;
  this->m_ControlList.m_Memory.m_nGrowSize = 0;
  this->m_ControlList.m_Size = 0;
  this->m_ControlList.m_pElements = this->m_ControlList.m_Memory.m_pMemory;
  this->__vftable = (CSelectModeDlgBar_vtbl *)&CSelectModeDlgBar::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100558E0
// Name: public: CBitmapButton::CBitmapButton(void)
// Source: json
//------------------------------------------------------------------------------
CBitmapButton *__thiscall CBitmapButton::CBitmapButton(CBitmapButton *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CBitmapButton_vtbl *)&CButton::`vftable';
  this->__vftable = (CBitmapButton_vtbl *)&CBitmapButton::`vftable';
  this->m_bitmap.__vftable = (CBitmap_vtbl *)&CGdiObject::`vftable';
  this->m_bitmap.m_hObject = nullptr;
  this->m_bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bitmapSel.__vftable = (CBitmap_vtbl *)&CGdiObject::`vftable';
  this->m_bitmapSel.m_hObject = nullptr;
  this->m_bitmapSel.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bitmapFocus.__vftable = (CBitmap_vtbl *)&CGdiObject::`vftable';
  this->m_bitmapFocus.m_hObject = nullptr;
  this->m_bitmapFocus.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->m_bitmapDisabled.__vftable = (CBitmap_vtbl *)&CGdiObject::`vftable';
  this->m_bitmapDisabled.m_hObject = nullptr;
  this->m_bitmapDisabled.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100559B0
// Name: public: virtual CBitmapButton::~CBitmapButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapButton::~CBitmapButton(CBitmapButton *this)
{
  this->m_bitmapDisabled.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bitmapDisabled);
  this->m_bitmapFocus.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bitmapFocus);
  this->m_bitmapSel.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bitmapSel);
  this->m_bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bitmap);
  CButton::~CButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055A60
// Name: public: CFilterControl::CFilterControl(void)
// Source: json
//------------------------------------------------------------------------------
CFilterControl *__thiscall CFilterControl::CFilterControl(CFilterControl *this)
{
  ControlInfo_t *m_pMemory; // ecx

  CDialogBar::CDialogBar(this);
  this->__vftable = (CFilterControl_vtbl *)&CHammerBar::`vftable';
  this->m_sizeDocked.cx = 0;
  this->m_sizeDocked.cy = 0;
  this->m_sizeFloating.cx = 0;
  this->m_sizeFloating.cy = 0;
  this->m_ControlList.m_Memory.m_pMemory = nullptr;
  this->m_ControlList.m_Memory.m_nAllocationCount = 0;
  this->m_ControlList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_ControlList.m_Memory.m_pMemory;
  this->m_ControlList.m_Size = 0;
  this->m_ControlList.m_pElements = m_pMemory;
  this->__vftable = (CFilterControl_vtbl *)&CFilterControl::`vftable';
  CBitmapButton::CBitmapButton(this: &this->m_cMoveUpButton);
  CBitmapButton::CBitmapButton(this: &this->m_cMoveDownButton);
  CGroupList::CGroupList(this: &this->m_cGroupBox);
  CCordonList::CCordonList(this: &this->m_cCordonBox);
  CWnd::CWnd(this: &this->m_cTabControl);
  this->m_cTabControl.__vftable = (CTabCtrl_vtbl *)&CTabCtrl::`vftable';
  this->m_bInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10055B50
// Name: public: virtual CFilterControl::~CFilterControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilterControl::~CFilterControl(CFilterControl *this)
{
  CTabCtrl::~CTabCtrl(this: &this->m_cTabControl);
  CCordonList::~CCordonList(this: &this->m_cCordonBox);
  CGroupList::~CGroupList(this: &this->m_cGroupBox);
  CBitmapButton::~CBitmapButton(this: &this->m_cMoveDownButton);
  CBitmapButton::~CBitmapButton(this: &this->m_cMoveUpButton);
  CHammerBar::~CHammerBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055C70
// Name: public: std::basic_iostream<char,struct std::char_traits<char>>::basic_iostream<char,struct std::char_traits<char>>(class std::basic_streambuf<char,struct std::char_traits<char>> __near *)
// Source: json
//------------------------------------------------------------------------------
std::iostream *__thiscall std::iostream::iostream(std::iostream *this, std::streambuf *_Strbuf, int a3)
{
  int v4; // edx
  std::ios *v5; // esi

  if ( a3 != 0 )
  {
    *(_DWORD *)this->gap0 = &std::iostream::`vbtable'{for `std::istream'};
    *(_DWORD *)this->gap10 = &std::iostream::`vbtable'{for `std::ostream'};
    *(_DWORD *)&this->gap10[8] = &std::ios_base::`vftable';
    *(_DWORD *)&this->gap10[8] = &std::ios::`vftable';
  }
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::istream::`vftable';
  v4 = *(_DWORD *)this->gap0;
  this->_Chcount = 0;
  v5 = (std::ios *)&this->gap0[*(_DWORD *)(v4 + 4)];
  std::ios_base::_Init(this: v5);
  v5->_Mystrbuf = _Strbuf;
  v5->_Tiestr = nullptr;
  v5->_Fillch = std::ios::widen(this: v5, _Byte: 32);
  if ( v5->_Mystrbuf == nullptr )
    std::ios_base::clear(this: v5, _State: LOBYTE(v5->_Mystate) | 4, _Reraise: false);
  *(_DWORD *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap10 + 4)] = &std::ostream::`vftable';
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::iostream::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100560D0
// Name: public: virtual CObjectBar::~CObjectBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectBar::~CObjectBar(CObjectBar *this)
{
  `eh vector destructor iterator'(
    ptr: this->m_PrevSel,
    size: 0x14u,
    count: 12,
    pDtor: (void (__thiscall *)(void *))CObjectBar::tagprevsel::~tagprevsel);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_FacesSpin);
  CEdit::~CEdit(this: &this->m_Faces);
  CComboBox::~CComboBox(this: &this->m_CategoryList);
  CFilteredComboBox::~CFilteredComboBox(this: &this->m_CreateList);
  CHammerBar::~CHammerBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056170
// Name: public: virtual CMainFrame::~CMainFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::~CMainFrame(CMainFrame *this)
{
  CObjectProperties *pObjectProperties; // ecx
  CTextureBrowser *pTextureBrowser; // ecx
  CFaceEditSheet *m_pFaceEditSheet; // ecx
  CSearchReplaceDlg *m_pSearchReplaceDlg; // ecx
  CLightingPreviewResultsWindow *m_pLightingPreviewOutputWindow; // ecx
  CModelBrowser *m_pModelBrowser; // ecx

  this->__vftable = (CMainFrame_vtbl *)&CMainFrame::`vftable';
  pObjectProperties = this->pObjectProperties;
  if ( pObjectProperties != nullptr )
    ((void (__thiscall *)(CObjectProperties *, int))pObjectProperties->dtr_CObject)(a1: pObjectProperties, a2: 1);
  pTextureBrowser = this->pTextureBrowser;
  if ( pTextureBrowser != nullptr )
    ((void (__thiscall *)(CTextureBrowser *, int))pTextureBrowser->dtr_CObject)(a1: pTextureBrowser, a2: 1);
  m_pFaceEditSheet = this->m_pFaceEditSheet;
  if ( m_pFaceEditSheet != nullptr )
    ((void (__thiscall *)(CFaceEditSheet *, int))m_pFaceEditSheet->dtr_CObject)(a1: m_pFaceEditSheet, a2: 1);
  m_pSearchReplaceDlg = this->m_pSearchReplaceDlg;
  if ( m_pSearchReplaceDlg != nullptr )
    ((void (__thiscall *)(CSearchReplaceDlg *, int))m_pSearchReplaceDlg->dtr_CObject)(a1: m_pSearchReplaceDlg, a2: 1);
  m_pLightingPreviewOutputWindow = this->m_pLightingPreviewOutputWindow;
  if ( m_pLightingPreviewOutputWindow != nullptr )
    ((void (__thiscall *)(CLightingPreviewResultsWindow *, int))m_pLightingPreviewOutputWindow->dtr_CObject)(
      a1: m_pLightingPreviewOutputWindow,
      a2: 1);
  m_pModelBrowser = this->m_pModelBrowser;
  if ( m_pModelBrowser != nullptr )
    ((void (__thiscall *)(CModelBrowser *, int))m_pModelBrowser->dtr_CObject)(a1: m_pModelBrowser, a2: 1);
  g_pMainWnd = nullptr;
  CPrefabLibrary::FreeAllLibraries();
  this->m_bmMapEditTools256.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmMapEditTools256);
  CFaceSmoothingVisualDlg::~CFaceSmoothingVisualDlg(this: &this->m_SmoothingGroupDlg);
  CHammerBar::~CHammerBar(this: &this->m_SelectModeDlg);
  CToolBar::~CToolBar(this: &this->m_wndMapEditToolBar);
  CToolBar::~CToolBar(this: &this->m_wndUndoRedoToolBar);
  CToolBar::~CToolBar(this: &this->m_wndMapToolBar);
  CStatusBar::~CStatusBar(this: &this->m_wndStatusBar);
  CMDIClientWnd::~CMDIClientWnd(this: &this->wndMDIClient);
  CManifestFilter::~CManifestFilter(this: &this->m_ManifestFilterControl);
  CStatic::~CStatic(this: &this->m_TextureBar.m_TexturePic);
  CComboBox::~CComboBox(this: &this->m_TextureBar.m_TextureGroupList);
  CTextureBox::~CTextureBox(this: &this->m_TextureBar.m_TextureList);
  CHammerBar::~CHammerBar(this: &this->m_TextureBar);
  CToolBar::~CToolBar(this: &this->m_wndMapOps);
  CObjectBar::~CObjectBar(this: &this->m_ObjectBar);
  CFilterControl::~CFilterControl(this: &this->m_FilterControl);
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056360
// Name: protected: void CMainFrame::OnModelBrowser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnModelBrowser(CMainFrame *this)
{
  CMapDoc *v2; // eax
  CModelBrowser *v3; // eax
  CModelBrowser *m_pModelBrowser; // esi
  char szModelName[1024]; // [esp+Ch] [ebp-460h] BYREF
  EntityReportFilterParms_t filter; // [esp+40Ch] [ebp-60h] BYREF
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > usedModels; // [esp+444h] [ebp-28h] BYREF
  int nRet; // [esp+458h] [ebp-14h]
  CMapDoc *pDoc; // [esp+45Ch] [ebp-10h]
  int v10; // [esp+468h] [ebp-4h]

  if ( this->m_pModelBrowser == nullptr )
  {
    v2 = (CMapDoc *)operator new(nSize: 0x130u);
    pDoc = v2;
    v10 = 0;
    if ( v2 != nullptr )
      v3 = CModelBrowser::CModelBrowser(this: (CModelBrowser *)v2, pParent: this);
    else
      v3 = nullptr;
    v10 = -1;
    this->m_pModelBrowser = v3;
  }
  m_pModelBrowser = this->m_pModelBrowser;
  CModelBrowser::Show(this: m_pModelBrowser);
  pDoc = CMapDoc::m_pMapDoc;
  memset(&usedModels, 0, sizeof(usedModels));
  v10 = 2;
  CMapDoc::GetUsedModels(this: CMapDoc::m_pMapDoc, &usedModels);
  CModelBrowser::SetUsedModelList(this: m_pModelBrowser, &usedModels);
  nRet = m_pModelBrowser->DoModal(this: m_pModelBrowser);
  CModelBrowser::Hide(this: m_pModelBrowser);
  if ( nRet == 100 )
  {
    CModelBrowser::GetModelName(this: m_pModelBrowser, pModelName: szModelName, length: 1024);
    CUtlString::CUtlString(this: &filter.m_filterKey);
    LOBYTE(v10) = 3;
    CUtlString::CUtlString(this: &filter.m_filterValue);
    LOBYTE(v10) = 4;
    CUtlString::CUtlString(this: &filter.m_filterClass);
    *(_DWORD *)&filter.m_bFilterByKeyvalue = 1;
    filter.m_nFilterByType = 0;
    LOBYTE(v10) = 6;
    CUtlString::Set(this: &filter.m_filterKey, pValue: "model");
    CUtlString::Set(this: &filter.m_filterValue, pValue: szModelName);
    CEntityReportDlg::ShowEntityReport(pDoc, pwndParent: this, pParms: &filter);
    LOBYTE(v10) = 2;
    EntityReportFilterParms_t::~EntityReportFilterParms_t(this: &filter);
  }
  v10 = -1;
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &usedModels);
}

//------------------------------------------------------------------------------
// Address: 0x10056530
// Name: public: void CMainFrame::LoadWindowStates(class std::basic_fstream<char,struct std::char_traits<char>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::LoadWindowStates(CMainFrame *this, std::fstream *pFile)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CDocTemplate *m_pDocTemplate; // edi
  CMapDoc *v5; // ebx
  HWND__ *m_hWndMDIClient; // edx
  __POSITION *(__thiscall *GetFirstViewPosition)(CDocument *); // eax
  CView *v8; // esi
  CMDIChildWnd *v9; // eax
  CChildFrame *v10; // esi
  CView *ActiveView; // eax
  CChildFrame *ParentFrame; // eax
  int v13; // eax
  CMDIFrameWnd *v14; // esi
  std::fpos<int> v15; // [esp-18h] [ebp-36Ch] BYREF
  char szFullPath[260]; // [esp+Ch] [ebp-348h] BYREF
  char szRootDir[260]; // [esp+110h] [ebp-244h] BYREF
  CRect r; // [esp+214h] [ebp-140h]
  std::fstream file; // [esp+224h] [ebp-130h] BYREF
  CTypedPtrList<CPtrList,CView *> UsedViews; // [esp+2DCh] [ebp-78h] BYREF
  double top; // [esp+2F8h] [ebp-5Ch] BYREF
  double right; // [esp+300h] [ebp-54h] BYREF
  float fThisVersion; // [esp+308h] [ebp-4Ch] BYREF
  double bottom; // [esp+30Ch] [ebp-48h] BYREF
  double left; // [esp+314h] [ebp-40h] BYREF
  CRect rectClient; // [esp+31Ch] [ebp-38h] BYREF
  char tag[4]; // [esp+32Ch] [ebp-28h] BYREF
  int bNew; // [esp+330h] [ebp-24h]
  __POSITION *p; // [esp+334h] [ebp-20h] BYREF
  CView *pView; // [esp+338h] [ebp-1Ch]
  int iDrawType; // [esp+33Ch] [ebp-18h] BYREF
  int iViewType; // [esp+340h] [ebp-14h] BYREF
  CMDIFrameWnd *v33; // [esp+344h] [ebp-10h]
  int v34; // [esp+350h] [ebp-4h]

  v33 = this;
  ModuleState = AfxGetModuleState();
  m_pDocTemplate = nullptr;
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szRootDir);
  V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: "winstate.wc", pStartingDir: szRootDir);
  std::fstream::fstream(this: &file, _Filename: szFullPath, _Mode: 33, _Prot: 64, a5: 1);
  v34 = 0;
  if ( *(_DWORD *)&file._Filebuffer[12] == 0 )
    goto LABEL_2;
  std::istream::read(this: &file, _Str: tag, _Count: 4);
  if ( *(_DWORD *)tag != *(_DWORD *)WINSTATETAG )
  {
    v33 = (CMDIFrameWnd *)&v15;
    v15._Myoff = -4;
    memset(&v15._Fpos, 0, 12);
    std::istream::seekg(this: &file, _Pos: v15);
    v34 = -1;
    std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
    v33 = (CMDIFrameWnd *)file.gap70;
    *(_DWORD *)file.gap70 = &std::ios::`vftable';
    goto LABEL_35;
  }
  std::istream::read(this: &file, _Str: (char *)&fThisVersion, _Count: 4);
  v5 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc == nullptr )
  {
LABEL_2:
    v34 = -1;
    std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
    v33 = (CMDIFrameWnd *)file.gap70;
    *(_DWORD *)file.gap70 = &std::ios::`vftable';
LABEL_35:
    v34 = -1;
    *(&v15._Mystate + 1) = (int)file.gap70;
    goto LABEL_36;
  }
  m_hWndMDIClient = this->m_hWndMDIClient;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWndMDIClient, lpRect: &rectClient);
  CPtrList::CPtrList(this: &UsedViews, nBlockSize: 10);
  UsedViews.__vftable = (CTypedPtrList<CPtrList,CView *>_vtbl *)&CTypedPtrList<CPtrList,CView *>::`vftable';
  LOBYTE(v34) = 6;
  SetDefaultChildType(b4Views: 0);
  std::istream::read(this: &file, _Str: (char *)&iViewType, _Count: 4);
  if ( (*(_DWORD *)((_BYTE *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4) & 1) == 0 )
  {
    while ( 1 )
    {
      if ( iViewType == -1 )
        goto LABEL_33;
      std::istream::read(this: &file, _Str: (char *)&iDrawType, _Count: 4);
      GetFirstViewPosition = v5->GetFirstViewPosition;
      pView = nullptr;
      p = GetFirstViewPosition(this: v5);
      while ( p != nullptr )
      {
        v8 = v5->GetNextView(this: v5, a2: &p);
        if ( CPtrList::Find(this: (CObList *)&UsedViews, searchValue: v8, startAfter: nullptr) == nullptr
          && (iViewType != 0 || CObject::IsKindOf(this: v8, pClass: &CMapView2D::classCMapView2D) != 0)
          && (iViewType != 2 || CObject::IsKindOf(this: v8, pClass: &CMapViewLogical::classCMapViewLogical) != 0)
          && (iViewType != 1 || CObject::IsKindOf(this: v8, pClass: &CMapView3D::classCMapView3D) != 0) )
        {
          pView = v8;
          CPtrList::AddTail(this: (CObList *)&UsedViews, newElement: v8);
          break;
        }
      }
      bNew = 0;
      if ( pView != nullptr )
      {
        ParentFrame = (CChildFrame *)CWnd::GetParentFrame(this: pView);
        v10 = ParentFrame;
        if ( ParentFrame->bUsingSplitter != 0 )
          CChildFrame::SetSplitterMode(this: ParentFrame, a2: (int)v5, a3: 0, bSplitter: 0);
      }
      else
      {
        v9 = CMDIFrameWnd::MDIGetActive(this: v33, pbMaximized: nullptr);
        m_pDocTemplate = v5->m_pDocTemplate;
        v10 = (CChildFrame *)m_pDocTemplate->CreateNewFrame(this: m_pDocTemplate, a2: v5, a3: v9);
        SendMessageA(hWnd: v10->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
        m_pDocTemplate->InitialUpdateFrame(this: m_pDocTemplate, a2: v10, a3: v5, a4: 0);
        ActiveView = CChildFrame::GetActiveView(this: v10);
        CPtrList::AddTail(this: (CObList *)&UsedViews, newElement: ActiveView);
        bNew = 1;
      }
      SendMessageA(hWnd: v10->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      if ( iViewType == 1 )
        break;
      if ( iViewType == 0 )
      {
        *(&v15._Mystate + 1) = iDrawType;
        goto LABEL_29;
      }
      if ( iViewType == 2 )
      {
        v13 = iDrawType;
        goto LABEL_28;
      }
LABEL_30:
      std::istream::read(this: &file, _Str: (char *)&left, _Count: 8);
      std::istream::read(this: &file, _Str: (char *)&top, _Count: 8);
      std::istream::read(this: &file, _Str: (char *)&right, _Count: 8);
      std::istream::read(this: &file, _Str: (char *)&bottom, _Count: 8);
      r.top = (int)((double)rectClient.bottom * top);
      CWnd::MoveWindow(
        this: v10,
        x: (int)((double)rectClient.right * left),
        y: r.top,
        nWidth: (int)((double)rectClient.right * right) - (int)((double)rectClient.right * left),
        nHeight: (int)((double)rectClient.bottom * bottom) - r.top,
        bRepaint: false);
      if ( bNew != 0 )
        m_pDocTemplate->InitialUpdateFrame(this: m_pDocTemplate, a2: v10, a3: v5, a4: 1);
      SendMessageA(hWnd: v10->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
      InvalidateRect(hWnd: v10->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: v10->m_hWnd);
      std::istream::read(this: &file, _Str: (char *)&iViewType, _Count: 4);
      m_pDocTemplate = nullptr;
      if ( (*((_BYTE *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4) & 1) != 0 )
        goto LABEL_33;
    }
    v13 = iDrawType;
    if ( (unsigned int)iDrawType <= 2 )
    {
      v13 = iDrawType + 3;
      iDrawType += 3;
    }
LABEL_28:
    *(&v15._Mystate + 1) = v13;
LABEL_29:
    CChildFrame::SetViewType(this: v10, eViewType: *((DrawType_t *)&v15._Mystate + 1));
    goto LABEL_30;
  }
LABEL_33:
  v14 = v33;
  InvalidateRect(hWnd: v33->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: v14->m_hWnd);
  LOBYTE(v34) = 0;
  CPtrList::~CPtrList(this: &UsedViews);
  v34 = -1;
  std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
  v33 = (CMDIFrameWnd *)file.gap70;
  *(_DWORD *)file.gap70 = &std::ios::`vftable';
  v34 = -1;
  *(&v15._Mystate + 1) = (int)file.gap70;
LABEL_36:
  *(_DWORD *)file.gap70 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: *((std::ios_base **)&v15._Mystate + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100569E0
// Name: protected: void CMainFrame::OnLoadwindowstate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnLoadwindowstate(CMainFrame *this)
{
  CMainFrame::LoadWindowStates(this, pFile: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10056A60
// Name: public: CMainFrame::CMainFrame(void)
// Source: json
//------------------------------------------------------------------------------
CMainFrame *__thiscall CMainFrame::CMainFrame(CMainFrame *this)
{
  CMDIFrameWnd::CMDIFrameWnd(this);
  this->__vftable = (CMainFrame_vtbl *)&CMainFrame::`vftable';
  CFilterControl::CFilterControl(this: &this->m_FilterControl);
  CObjectBar::CObjectBar(this: &this->m_ObjectBar);
  CToolBar::CToolBar(this: &this->m_wndMapOps);
  CTextureBar::CTextureBar(this: &this->m_TextureBar);
  CManifestFilter::CManifestFilter(this: &this->m_ManifestFilterControl);
  CMDIClientWnd::CMDIClientWnd(this: &this->wndMDIClient);
  CStatusBar::CStatusBar(this: &this->m_wndStatusBar);
  CToolBar::CToolBar(this: &this->m_wndMapToolBar);
  CToolBar::CToolBar(this: &this->m_wndUndoRedoToolBar);
  CToolBar::CToolBar(this: &this->m_wndMapEditToolBar);
  CSelectModeDlgBar::CSelectModeDlgBar(this: &this->m_SelectModeDlg);
  CFaceSmoothingVisualDlg::CFaceSmoothingVisualDlg(this: &this->m_SmoothingGroupDlg, pParent: nullptr);
  this->m_bmMapEditTools256.__vftable = (CBitmap_vtbl *)&CGdiObject::`vftable';
  this->m_bmMapEditTools256.m_hObject = nullptr;
  this->m_bmMapEditTools256.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  this->pTextureBrowser = nullptr;
  this->pObjectProperties = nullptr;
  this->m_pModelBrowser = nullptr;
  this->m_bUndoActive = 1;
  this->m_pFaceEditSheet = nullptr;
  *(_WORD *)&this->m_bMinimized = 0;
  this->m_pSearchReplaceDlg = nullptr;
  this->m_pLightingPreviewOutputWindow = nullptr;
  this->m_bLightingPreviewOutputWindowShowing = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056BF0
// Name: private: void CMainFrame::SaveWindowStates(class std::basic_fstream<char,struct std::char_traits<char>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::SaveWindowStates(CMainFrame *this, std::fstream *pFile)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CMapDoc *v4; // esi
  CWnd *v5; // esi
  CFrameWnd *ParentFrame; // eax
  HWND__ *v7; // edx
  HWND__ *m_hWndMDIClient; // [esp-8h] [ebp-33Ch]
  char szFullPath[260]; // [esp+Ch] [ebp-328h] BYREF
  char szRootDir[260]; // [esp+110h] [ebp-224h] BYREF
  std::fstream file; // [esp+214h] [ebp-120h] BYREF
  double bottom; // [esp+2CCh] [ebp-68h] BYREF
  double left; // [esp+2D4h] [ebp-60h] BYREF
  double right; // [esp+2DCh] [ebp-58h] BYREF
  double top; // [esp+2E4h] [ebp-50h] BYREF
  CRect rectClient; // [esp+2ECh] [ebp-48h] BYREF
  CRect rectView; // [esp+2FCh] [ebp-38h] BYREF
  CPoint pt2; // [esp+30Ch] [ebp-28h] BYREF
  CPoint pt1; // [esp+314h] [ebp-20h] BYREF
  __POSITION *p; // [esp+31Ch] [ebp-18h] BYREF
  int iDrawType; // [esp+320h] [ebp-14h] BYREF
  CMapDoc *pDoc; // [esp+324h] [ebp-10h]
  int v23; // [esp+330h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szRootDir);
  V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: "winstate.wc", pStartingDir: szRootDir);
  std::fstream::fstream(this: &file, _Filename: szFullPath, _Mode: 34, _Prot: 64, a5: 1);
  v23 = 0;
  v4 = CMapDoc::m_pMapDoc;
  pDoc = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    std::ostream::write(this: (std::ostream *)file.gap10, _Str: WINSTATETAG, _Count: 4);
    std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&fVersion, _Count: 4);
    m_hWndMDIClient = this->m_hWndMDIClient;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWndMDIClient, lpRect: &rectClient);
    p = v4->GetFirstViewPosition(this: v4);
    if ( p == nullptr )
    {
LABEL_14:
      std::ostream::write(this: (std::ostream *)file.gap10, _Str: WINSTATEEND, _Count: 4);
      v23 = -1;
      std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
      pDoc = (CMapDoc *)file.gap70;
      *(_DWORD *)file.gap70 = &std::ios::`vftable';
      v23 = -1;
      goto LABEL_15;
    }
    while ( 1 )
    {
      v5 = v4->GetNextView(this: v4, a2: &p);
      if ( CObject::IsKindOf(this: v5, pClass: &CMapView2D::classCMapView2D) != 0 )
      {
        std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&WINSTATE2DVIEW, _Count: 4);
      }
      else if ( CObject::IsKindOf(this: v5, pClass: &CMapView3D::classCMapView3D) != 0 )
      {
        std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&WINSTATE3DVIEW, _Count: 4);
      }
      else
      {
        if ( CObject::IsKindOf(this: v5, pClass: &CMapViewLogical::classCMapViewLogical) == 0 )
          goto LABEL_13;
        std::ostream::write(this: (std::ostream *)file.gap10, _Str: WINSTATELOGICALVIEW, _Count: 4);
      }
      iDrawType = ((int (__thiscall *)(IUnknown **))v5[1].m_pOuterUnknown[2].__vftable)(a1: &v5[1].m_pOuterUnknown);
      std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&iDrawType, _Count: 4);
      memset(&rectView, 0, sizeof(rectView));
      ParentFrame = CWnd::GetParentFrame(this: v5);
      GetWindowRect(hWnd: ParentFrame->m_hWnd, lpRect: &rectView);
      pt1.y = rectView.top;
      pt2.x = rectView.right;
      v7 = this->m_hWndMDIClient;
      pt1.x = rectView.left;
      pt2.y = rectView.bottom;
      ScreenToClient(hWnd: v7, lpPoint: &pt1);
      ScreenToClient(hWnd: this->m_hWndMDIClient, lpPoint: &pt2);
      left = (double)pt1.x / (double)rectClient.right;
      top = (double)pt1.y / (double)rectClient.bottom;
      right = (double)pt2.x / (double)rectClient.right;
      bottom = (double)pt2.y / (double)rectClient.bottom;
      std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&left, _Count: 8);
      std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&top, _Count: 8);
      std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&right, _Count: 8);
      std::ostream::write(this: (std::ostream *)file.gap10, _Str: (const char *)&bottom, _Count: 8);
LABEL_13:
      if ( p == nullptr )
        goto LABEL_14;
      v4 = pDoc;
    }
  }
  v23 = -1;
  std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
  pDoc = (CMapDoc *)file.gap70;
  *(_DWORD *)file.gap70 = &std::ios::`vftable';
  v23 = -1;
LABEL_15:
  *(_DWORD *)file.gap70 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap70);
}

//------------------------------------------------------------------------------
// Address: 0x10056F00
// Name: protected: void CMainFrame::OnSavewindowstate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainFrame::OnSavewindowstate(CMainFrame *this)
{
  CMainFrame::SaveWindowStates(this, pFile: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10056F10
// Name: protected: static struct AFX_MSGMAP const __near * CMainFrame::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CMainFrame::GetThisMessageMap()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    messageEntries_42[3].nID = 32820;
    messageEntries_42[3].nLastID = 32820;
    messageEntries_42[4].nID = 32820;
    messageEntries_42[4].nLastID = 32820;
    messageEntries_42[5].nID = 33267;
    messageEntries_42[5].nLastID = 33267;
    messageEntries_42[6].nID = 33267;
    messageEntries_42[6].nLastID = 33267;
    messageEntries_42[7].nID = 33268;
    messageEntries_42[7].nLastID = 33268;
    messageEntries_42[8].nID = 33268;
    messageEntries_42[8].nLastID = 33268;
    messageEntries_42[1].nID = 32819;
    messageEntries_42[1].nLastID = 32819;
    messageEntries_42[2].nID = 32819;
    messageEntries_42[2].nLastID = 32819;
    messageEntries_42[9].nID = 33269;
    messageEntries_42[9].nLastID = 33269;
    messageEntries_42[10].nID = 33269;
    messageEntries_42[10].nLastID = 33269;
    messageEntries_42[0].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnCreate;
    messageEntries_42[1].nMessage = 273;
    messageEntries_42[1].nCode = 0;
    messageEntries_42[1].nSig = 57;
    messageEntries_42[1].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnEditProperties;
    messageEntries_42[2].nMessage = 273;
    messageEntries_42[2].nCode = -1;
    messageEntries_42[2].nSig = 65;
    messageEntries_42[2].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateEditFunction;
    messageEntries_42[3].nMessage = 273;
    messageEntries_42[3].nCode = 0;
    messageEntries_42[3].nSig = 57;
    messageEntries_42[3].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnViewMessages;
    messageEntries_42[4].nMessage = 273;
    messageEntries_42[4].nCode = -1;
    messageEntries_42[4].nSig = 65;
    messageEntries_42[4].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateViewMessages;
    messageEntries_42[5].nMessage = 273;
    messageEntries_42[5].nCode = -1;
    messageEntries_42[5].nSig = 65;
    messageEntries_42[5].pfn = (void (__thiscall *)(CCmdTarget *))CChildFrame::OnUpdateViewMaximizepane;
    messageEntries_42[6].nMessage = 273;
    messageEntries_42[6].nCode = 0;
    messageEntries_42[6].nSig = 57;
    messageEntries_42[6].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnFoundrySendSelectedEntitiesToEngine;
    messageEntries_42[7].nMessage = 273;
    messageEntries_42[7].nCode = -1;
    messageEntries_42[7].nSig = 65;
    messageEntries_42[7].pfn = (void (__thiscall *)(CCmdTarget *))CChildFrame::OnUpdateViewMaximizepane;
    messageEntries_42[8].nMessage = 273;
    messageEntries_42[8].nCode = 0;
    messageEntries_42[8].nSig = 57;
    messageEntries_42[8].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnFoundryMoveEngineViewToHammer3DView;
    messageEntries_42[9].nMessage = 273;
    messageEntries_42[9].nCode = -1;
    messageEntries_42[9].nSig = 65;
    messageEntries_42[9].pfn = (void (__thiscall *)(CCmdTarget *))CChildFrame::OnUpdateViewMaximizepane;
    messageEntries_42[10].nMessage = 273;
    messageEntries_42[10].nCode = 0;
    messageEntries_42[10].nSig = 57;
    messageEntries_42[10].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnFoundryRemoveSelectedEntitiesFromEngine;
    messageEntries_42[11].nMessage = 273;
    messageEntries_42[11].nCode = -1;
    messageEntries_42[11].nID = 33270;
    messageEntries_42[11].nLastID = 33270;
    messageEntries_42[11].nSig = 65;
    messageEntries_42[11].pfn = (void (__thiscall *)(CCmdTarget *))CChildFrame::OnUpdateViewMaximizepane;
    messageEntries_42[12].nID = 33270;
    messageEntries_42[12].nLastID = 33270;
    messageEntries_42[15].nSig = 19;
    messageEntries_42[16].nSig = 19;
    messageEntries_42[17].nSig = 19;
    messageEntries_42[19].nID = 32870;
    messageEntries_42[19].nLastID = 32870;
    messageEntries_42[20].nID = 32932;
    messageEntries_42[20].nLastID = 32932;
    messageEntries_42[21].nID = 32940;
    messageEntries_42[21].nLastID = 32940;
    messageEntries_42[12].nMessage = 273;
    messageEntries_42[12].nCode = 0;
    messageEntries_42[12].nSig = 57;
    messageEntries_42[12].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnFoundryMoveFocusToEngine;
    messageEntries_42[13].nMessage = 28;
    messageEntries_42[13].nCode = 0;
    messageEntries_42[13].nID = 0;
    messageEntries_42[13].nLastID = 0;
    messageEntries_42[13].nSig = 21;
    messageEntries_42[13].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnActivateApp;
    messageEntries_42[14].nMessage = 5;
    messageEntries_42[14].nCode = 0;
    messageEntries_42[14].nID = 0;
    messageEntries_42[14].nLastID = 0;
    messageEntries_42[14].nSig = 25;
    messageEntries_42[14].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnSize;
    messageEntries_42[15].nMessage = 16;
    messageEntries_42[15].nCode = 0;
    messageEntries_42[15].nID = 0;
    messageEntries_42[15].nLastID = 0;
    messageEntries_42[15].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnClose;
    messageEntries_42[16].nMessage = 2;
    messageEntries_42[16].nCode = 0;
    messageEntries_42[16].nID = 0;
    messageEntries_42[16].nLastID = 0;
    messageEntries_42[16].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnDestroy;
    messageEntries_42[17].nMessage = 15;
    messageEntries_42[17].nCode = 0;
    messageEntries_42[17].nID = 0;
    messageEntries_42[17].nLastID = 0;
    messageEntries_42[17].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnPaint;
    messageEntries_42[18].nMessage = 275;
    messageEntries_42[18].nCode = 0;
    messageEntries_42[18].nID = 0;
    messageEntries_42[18].nLastID = 0;
    messageEntries_42[18].nSig = 20;
    messageEntries_42[18].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnTimer;
    messageEntries_42[19].nMessage = 273;
    messageEntries_42[19].nCode = 0;
    messageEntries_42[19].nSig = 57;
    messageEntries_42[19].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::Configure;
    messageEntries_42[20].nMessage = 273;
    messageEntries_42[20].nCode = 0;
    messageEntries_42[20].nSig = 57;
    messageEntries_42[20].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnToolsPrefabfactory;
    messageEntries_42[21].nMessage = 273;
    messageEntries_42[21].nCode = 0;
    messageEntries_42[21].nSig = 60;
    messageEntries_42[21].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnHelpOpenURL;
    messageEntries_42[22].nMessage = 273;
    messageEntries_42[22].nCode = 0;
    messageEntries_42[22].nID = 32944;
    messageEntries_42[22].nLastID = 32944;
    messageEntries_42[22].nSig = 60;
    messageEntries_42[22].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnHelpOpenURL;
    messageEntries_42[23].nMessage = 273;
    messageEntries_42[23].nCode = 0;
    messageEntries_42[23].nID = 33093;
    messageEntries_42[23].nLastID = 33093;
    messageEntries_42[23].nSig = 60;
    messageEntries_42[23].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnHelpOpenURL;
    messageEntries_42[24].nMessage = 273;
    messageEntries_42[24].nCode = 0;
    messageEntries_42[24].nID = 32949;
    messageEntries_42[24].nLastID = 32949;
    messageEntries_42[24].nSig = 57;
    messageEntries_42[24].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnEditUndoredoactive;
    messageEntries_42[25].nMessage = 273;
    messageEntries_42[25].nCode = -1;
    messageEntries_42[25].nID = 32949;
    messageEntries_42[25].nLastID = 32949;
    messageEntries_42[25].nSig = 65;
    messageEntries_42[25].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateEditUndoredoactive;
    messageEntries_42[26].nMessage = 273;
    messageEntries_42[26].nCode = 0;
    messageEntries_42[26].nID = 57600;
    messageEntries_42[26].nLastID = 57600;
    messageEntries_42[26].nSig = 60;
    messageEntries_42[26].pfn = (void (__thiscall *)(CCmdTarget *))CBaseToolSystem::CreateActionMenu;
    messageEntries_42[27].nMessage = 273;
    messageEntries_42[27].nCode = 0;
    messageEntries_42[27].nID = 33009;
    messageEntries_42[27].nLastID = 33009;
    messageEntries_42[27].nSig = 57;
    messageEntries_42[27].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnSavewindowstate;
    messageEntries_42[28].nMessage = 273;
    messageEntries_42[28].nCode = 0;
    messageEntries_42[28].nID = 33010;
    messageEntries_42[28].nLastID = 33010;
    messageEntries_42[28].nSig = 57;
    messageEntries_42[28].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnLoadwindowstate;
    messageEntries_42[29].nMessage = 273;
    messageEntries_42[29].nCode = 0;
    messageEntries_42[29].nID = 33099;
    messageEntries_42[29].nLastID = 33099;
    messageEntries_42[29].nSig = 60;
    messageEntries_42[29].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUnits;
    messageEntries_42[30].nMessage = 273;
    messageEntries_42[30].nCode = -1;
    messageEntries_42[30].nID = 33099;
    messageEntries_42[30].nLastID = 33099;
    messageEntries_42[30].nSig = 65;
    messageEntries_42[30].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateUnits;
    messageEntries_42[31].nMessage = 273;
    messageEntries_42[31].nCode = 0;
    messageEntries_42[31].nID = 33100;
    messageEntries_42[31].nLastID = 33100;
    messageEntries_42[31].nSig = 60;
    messageEntries_42[31].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUnits;
    messageEntries_42[32].nMessage = 273;
    messageEntries_42[32].nCode = -1;
    messageEntries_42[32].nID = 33100;
    messageEntries_42[32].nLastID = 33100;
    messageEntries_42[32].nSig = 65;
    messageEntries_42[32].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateUnits;
    messageEntries_42[33].nMessage = 273;
    messageEntries_42[33].nCode = 0;
    messageEntries_42[33].nID = 33101;
    messageEntries_42[33].nLastID = 33101;
    messageEntries_42[33].nSig = 60;
    messageEntries_42[33].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUnits;
    messageEntries_42[34].nMessage = 273;
    messageEntries_42[34].nCode = -1;
    messageEntries_42[34].nID = 33101;
    messageEntries_42[34].nLastID = 33101;
    messageEntries_42[34].nSig = 65;
    messageEntries_42[34].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateUnits;
    messageEntries_42[35].nMessage = 273;
    messageEntries_42[35].nCode = -1;
    messageEntries_42[35].nID = 33103;
    messageEntries_42[35].nLastID = 33103;
    messageEntries_42[35].nSig = 65;
    messageEntries_42[35].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateOpaqueMaterials;
    messageEntries_42[36].nMessage = 273;
    messageEntries_42[36].nCode = -1;
    messageEntries_42[36].nID = 32780;
    messageEntries_42[36].nLastID = 32780;
    messageEntries_42[36].nSig = 65;
    messageEntries_42[36].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateView3d;
    messageEntries_42[37].nMessage = 273;
    messageEntries_42[37].nCode = -1;
    messageEntries_42[37].nID = 32781;
    messageEntries_42[37].nLastID = 32781;
    messageEntries_42[37].nSig = 65;
    messageEntries_42[37].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateView3d;
    messageEntries_42[38].nMessage = 273;
    messageEntries_42[38].nCode = -1;
    messageEntries_42[38].nID = 32779;
    messageEntries_42[38].nLastID = 32779;
    messageEntries_42[38].nSig = 65;
    messageEntries_42[38].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateView3d;
    messageEntries_42[39].nMessage = 273;
    messageEntries_42[39].nCode = -1;
    messageEntries_42[39].nID = 32778;
    messageEntries_42[39].nLastID = 32778;
    messageEntries_42[39].nSig = 65;
    messageEntries_42[39].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateView3d;
    messageEntries_42[40].nMessage = 273;
    messageEntries_42[40].nCode = -1;
    messageEntries_42[40].nID = 32790;
    messageEntries_42[40].nLastID = 32790;
    messageEntries_42[40].nSig = 65;
    messageEntries_42[40].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateView3d;
    messageEntries_42[41].nMessage = 273;
    messageEntries_42[41].nCode = -1;
    messageEntries_42[41].nID = 32777;
    messageEntries_42[41].nLastID = 32777;
    messageEntries_42[41].nSig = 65;
    messageEntries_42[41].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateView3d;
    messageEntries_42[42].nMessage = 273;
    messageEntries_42[42].nCode = 0;
    messageEntries_42[42].nID = 33103;
    messageEntries_42[42].nLastID = 33103;
    messageEntries_42[42].nSig = 57;
    messageEntries_42[42].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnOpaqueMaterials;
    messageEntries_42[43].nMessage = 273;
    messageEntries_42[43].nCode = 0;
    messageEntries_42[43].nID = 32909;
    messageEntries_42[43].nLastID = 32909;
    messageEntries_42[43].nSig = 60;
    messageEntries_42[43].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnView3dChangeBrightness;
    messageEntries_42[44].nMessage = 273;
    messageEntries_42[44].nCode = 0;
    messageEntries_42[44].nID = 32910;
    messageEntries_42[44].nLastID = 32910;
    messageEntries_42[44].nSig = 60;
    messageEntries_42[44].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnView3dChangeBrightness;
    messageEntries_42[45].nMessage = 273;
    messageEntries_42[45].nCode = -1;
    messageEntries_42[45].nID = 59400;
    messageEntries_42[45].nLastID = 59400;
    messageEntries_42[45].nSig = 65;
    messageEntries_42[45].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[46].nMessage = 273;
    messageEntries_42[46].nCode = 0;
    messageEntries_42[46].nID = 59400;
    messageEntries_42[46].nLastID = 59400;
    messageEntries_42[46].nSig = 60;
    messageEntries_42[46].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[47].nMessage = 273;
    messageEntries_42[47].nCode = -1;
    messageEntries_42[47].nID = 59407;
    messageEntries_42[47].nLastID = 59407;
    messageEntries_42[47].nSig = 65;
    messageEntries_42[47].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[48].nMessage = 273;
    messageEntries_42[48].nCode = 0;
    messageEntries_42[48].nID = 59407;
    messageEntries_42[48].nLastID = 59407;
    messageEntries_42[48].nSig = 60;
    messageEntries_42[48].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[49].nMessage = 273;
    messageEntries_42[49].nCode = -1;
    messageEntries_42[49].nID = 59399;
    messageEntries_42[49].nLastID = 59399;
    messageEntries_42[49].nSig = 65;
    messageEntries_42[49].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[50].nMessage = 273;
    messageEntries_42[50].nCode = 0;
    messageEntries_42[50].nID = 59399;
    messageEntries_42[50].nLastID = 59399;
    messageEntries_42[50].nSig = 60;
    messageEntries_42[50].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[51].nMessage = 273;
    messageEntries_42[51].nCode = -1;
    messageEntries_42[51].nID = 59402;
    messageEntries_42[51].nLastID = 59402;
    messageEntries_42[51].nSig = 65;
    messageEntries_42[51].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[52].nMessage = 273;
    messageEntries_42[52].nCode = 0;
    messageEntries_42[52].nID = 59402;
    messageEntries_42[52].nLastID = 59402;
    messageEntries_42[52].nSig = 60;
    messageEntries_42[52].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[53].nMessage = 273;
    messageEntries_42[53].nCode = -1;
    messageEntries_42[53].nID = 59401;
    messageEntries_42[53].nLastID = 59401;
    messageEntries_42[53].nSig = 65;
    messageEntries_42[53].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[54].nMessage = 273;
    messageEntries_42[54].nCode = 0;
    messageEntries_42[54].nID = 59401;
    messageEntries_42[54].nLastID = 59401;
    messageEntries_42[54].nSig = 60;
    messageEntries_42[54].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[55].nMessage = 273;
    messageEntries_42[55].nCode = -1;
    messageEntries_42[55].nID = 59403;
    messageEntries_42[55].nLastID = 59403;
    messageEntries_42[55].nSig = 65;
    messageEntries_42[55].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[56].nMessage = 273;
    messageEntries_42[56].nCode = 0;
    messageEntries_42[56].nID = 59403;
    messageEntries_42[56].nLastID = 59403;
    messageEntries_42[56].nSig = 60;
    messageEntries_42[56].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[57].nMessage = 273;
    messageEntries_42[57].nCode = -1;
    messageEntries_42[57].nID = 59409;
    messageEntries_42[57].nLastID = 59409;
    messageEntries_42[57].nSig = 65;
    messageEntries_42[57].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[58].nMessage = 273;
    messageEntries_42[58].nCode = 0;
    messageEntries_42[58].nID = 59409;
    messageEntries_42[58].nLastID = 59409;
    messageEntries_42[58].nSig = 60;
    messageEntries_42[58].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[59].nMessage = 273;
    messageEntries_42[59].nCode = -1;
    messageEntries_42[59].nID = 59404;
    messageEntries_42[59].nLastID = 59404;
    messageEntries_42[59].nSig = 65;
    messageEntries_42[59].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnUpdateControlBarMenu;
    messageEntries_42[60].nMessage = 273;
    messageEntries_42[60].nCode = 0;
    messageEntries_42[60].nID = 59404;
    messageEntries_42[60].nLastID = 59404;
    messageEntries_42[60].nSig = 60;
    messageEntries_42[60].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnBarCheck;
    messageEntries_42[61].nMessage = 273;
    messageEntries_42[61].nCode = 0;
    messageEntries_42[61].nID = 32813;
    messageEntries_42[61].nLastID = 32813;
    messageEntries_42[61].nSig = 60;
    messageEntries_42[61].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[62].nMessage = 273;
    messageEntries_42[62].nCode = -1;
    messageEntries_42[62].nID = 32813;
    messageEntries_42[62].nLastID = 32813;
    messageEntries_42[62].nSig = 65;
    messageEntries_42[62].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[63].nMessage = 273;
    messageEntries_42[63].nCode = 0;
    messageEntries_42[63].nID = 32833;
    messageEntries_42[63].nLastID = 32833;
    messageEntries_42[63].nSig = 60;
    messageEntries_42[63].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[64].nMessage = 273;
    messageEntries_42[64].nCode = -1;
    messageEntries_42[64].nID = 32833;
    messageEntries_42[64].nLastID = 32833;
    messageEntries_42[64].nSig = 65;
    messageEntries_42[64].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[65].nMessage = 273;
    messageEntries_42[65].nCode = 0;
    messageEntries_42[65].nID = 32829;
    messageEntries_42[65].nLastID = 32829;
    messageEntries_42[65].nSig = 60;
    messageEntries_42[65].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[66].nMessage = 273;
    messageEntries_42[66].nCode = -1;
    messageEntries_42[66].nID = 32829;
    messageEntries_42[66].nLastID = 32829;
    messageEntries_42[66].nSig = 65;
    messageEntries_42[66].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[67].nMessage = 273;
    messageEntries_42[67].nCode = 0;
    messageEntries_42[67].nID = 32812;
    messageEntries_42[67].nLastID = 32812;
    messageEntries_42[67].nSig = 60;
    messageEntries_42[67].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[68].nMessage = 273;
    messageEntries_42[68].nCode = -1;
    messageEntries_42[68].nID = 32812;
    messageEntries_42[68].nLastID = 32812;
    messageEntries_42[68].nSig = 65;
    messageEntries_42[68].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[69].nMessage = 273;
    messageEntries_42[69].nCode = 0;
    messageEntries_42[69].nID = 32816;
    messageEntries_42[69].nLastID = 32816;
    messageEntries_42[69].nSig = 60;
    messageEntries_42[69].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[70].nMessage = 273;
    messageEntries_42[70].nCode = -1;
    messageEntries_42[70].nID = 32816;
    messageEntries_42[70].nLastID = 32816;
    messageEntries_42[70].nSig = 65;
    messageEntries_42[70].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[71].nMessage = 273;
    messageEntries_42[71].nCode = 0;
    messageEntries_42[71].nID = 33008;
    messageEntries_42[71].nLastID = 33008;
    messageEntries_42[71].nSig = 60;
    messageEntries_42[71].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[72].nMessage = 273;
    messageEntries_42[72].nCode = -1;
    messageEntries_42[72].nID = 33008;
    messageEntries_42[72].nLastID = 33008;
    messageEntries_42[72].nSig = 65;
    messageEntries_42[72].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[73].nMessage = 273;
    messageEntries_42[73].nCode = 0;
    messageEntries_42[73].nID = 32952;
    messageEntries_42[73].nLastID = 32952;
    messageEntries_42[73].nSig = 60;
    messageEntries_42[73].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[74].nMessage = 273;
    messageEntries_42[74].nCode = -1;
    messageEntries_42[74].nID = 32952;
    messageEntries_42[74].nLastID = 32952;
    messageEntries_42[74].nSig = 65;
    messageEntries_42[74].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[75].nMessage = 273;
    messageEntries_42[75].nCode = 0;
    messageEntries_42[75].nID = 41006;
    messageEntries_42[75].nLastID = 41006;
    messageEntries_42[75].nSig = 60;
    messageEntries_42[75].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[76].nMessage = 273;
    messageEntries_42[76].nCode = -1;
    messageEntries_42[76].nID = 41006;
    messageEntries_42[76].nLastID = 41006;
    messageEntries_42[76].nSig = 65;
    messageEntries_42[76].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[77].nMessage = 273;
    messageEntries_42[77].nCode = 0;
    messageEntries_42[77].nID = 32955;
    messageEntries_42[77].nLastID = 32955;
    messageEntries_42[77].nSig = 60;
    messageEntries_42[77].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[78].nMessage = 273;
    messageEntries_42[78].nCode = -1;
    messageEntries_42[78].nID = 32955;
    messageEntries_42[78].nLastID = 32955;
    messageEntries_42[78].nSig = 65;
    messageEntries_42[79].nSig = 60;
    messageEntries_42[80].nSig = 65;
    messageEntries_42[81].nSig = 60;
    messageEntries_42[82].nSig = 65;
    messageEntries_42[83].nSig = 60;
    messageEntries_42[84].nSig = 65;
    messageEntries_42[85].nSig = 60;
    messageEntries_42[86].nSig = 60;
    messageEntries_42[88].nSig = 60;
    messageEntries_42[89].nSig = 65;
    messageEntries_42[89].nID = 32913;
    messageEntries_42[89].nLastID = 32913;
    messageEntries_42[90].nID = 57667;
    messageEntries_42[90].nLastID = 57667;
    messageEntries_42[78].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[79].nMessage = 273;
    messageEntries_42[79].nCode = 0;
    messageEntries_42[79].nID = 32962;
    messageEntries_42[79].nLastID = 32962;
    messageEntries_42[79].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[80].nMessage = 273;
    messageEntries_42[80].nCode = -1;
    messageEntries_42[80].nID = 32962;
    messageEntries_42[80].nLastID = 32962;
    messageEntries_42[80].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[81].nMessage = 273;
    messageEntries_42[81].nCode = 0;
    messageEntries_42[81].nID = 32966;
    messageEntries_42[81].nLastID = 32966;
    messageEntries_42[81].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[82].nMessage = 273;
    messageEntries_42[82].nCode = -1;
    messageEntries_42[82].nID = 32966;
    messageEntries_42[82].nLastID = 32966;
    messageEntries_42[82].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[83].nMessage = 273;
    messageEntries_42[83].nCode = 0;
    messageEntries_42[83].nID = 33107;
    messageEntries_42[83].nLastID = 33107;
    messageEntries_42[83].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnChangeTool;
    messageEntries_42[84].nMessage = 273;
    messageEntries_42[84].nCode = -1;
    messageEntries_42[84].nID = 33107;
    messageEntries_42[84].nLastID = 33107;
    messageEntries_42[84].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateToolUI;
    messageEntries_42[85].nMessage = 273;
    messageEntries_42[85].nCode = 0;
    messageEntries_42[85].nID = 32913;
    messageEntries_42[85].nLastID = 32913;
    messageEntries_42[85].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnApplicator;
    messageEntries_42[86].nMessage = 273;
    messageEntries_42[86].nCode = 0;
    messageEntries_42[86].nID = 33177;
    messageEntries_42[86].nLastID = 33177;
    messageEntries_42[86].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnSoundBrowser;
    messageEntries_42[87].nMessage = 273;
    messageEntries_42[87].nCode = 0;
    messageEntries_42[87].nID = 33178;
    messageEntries_42[87].nLastID = 33178;
    messageEntries_42[87].nSig = 57;
    messageEntries_42[87].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnModelBrowser;
    messageEntries_42[88].nMessage = 273;
    messageEntries_42[88].nCode = 0;
    messageEntries_42[88].nID = 33179;
    messageEntries_42[88].nLastID = 33179;
    messageEntries_42[88].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnReloadSounds;
    messageEntries_42[89].nMessage = 273;
    messageEntries_42[89].nCode = -1;
    messageEntries_42[89].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnUpdateApplicatorUI;
    messageEntries_42[90].nMessage = 273;
    messageEntries_42[90].nCode = 0;
    messageEntries_42[90].nSig = 57;
    messageEntries_42[90].pfn = (void (__thiscall *)(CCmdTarget *))CWnd::OnHelpFinder;
    messageEntries_42[91].nMessage = 273;
    messageEntries_42[91].nCode = 0;
    messageEntries_42[91].nID = 57670;
    messageEntries_42[91].nLastID = 57670;
    messageEntries_42[92].nMessage = 273;
    messageEntries_42[92].nID = 57669;
    messageEntries_42[92].nLastID = 57669;
    messageEntries_42[93].nMessage = 273;
    messageEntries_42[94].nMessage = 273;
    messageEntries_42[91].nSig = 57;
    messageEntries_42[91].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnHelp;
    messageEntries_42[92].nCode = 0;
    messageEntries_42[92].nSig = 57;
    messageEntries_42[92].pfn = (void (__thiscall *)(CCmdTarget *))CFrameWnd::OnContextHelp;
    messageEntries_42[93].nCode = 0;
    messageEntries_42[93].nID = 57671;
    messageEntries_42[93].nLastID = 57671;
    messageEntries_42[93].nSig = 57;
    messageEntries_42[93].pfn = (void (__thiscall *)(CCmdTarget *))CWnd::OnHelpFinder;
    messageEntries_42[94].nCode = 0;
    messageEntries_42[94].nID = 61440;
    messageEntries_42[94].nLastID = 61440;
    messageEntries_42[94].nSig = 57;
    messageEntries_42[94].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnHDR;
    messageEntries_42[95].nMessage = 83;
    messageEntries_42[95].nCode = 0;
    messageEntries_42[95].nID = 0;
    messageEntries_42[95].nLastID = 0;
    messageEntries_42[95].nSig = 7;
    messageEntries_42[95].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnHelpInfo;
    messageEntries_42[96].nMessage = 274;
    messageEntries_42[96].nCode = 0;
    messageEntries_42[96].nID = 0;
    messageEntries_42[96].nLastID = 0;
    messageEntries_42[96].nSig = 30;
    messageEntries_42[96].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnSysCommand;
    messageEntries_42[97].nMessage = 529;
    messageEntries_42[97].nCode = 0;
    messageEntries_42[97].nID = 0;
    messageEntries_42[97].nLastID = 0;
    messageEntries_42[97].nSig = 20;
    messageEntries_42[97].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnEnterMenuLoop;
    messageEntries_42[98].nMessage = 32752;
    messageEntries_42[98].nCode = 0;
    messageEntries_42[98].nID = 0;
    messageEntries_42[98].nLastID = 0;
    messageEntries_42[98].nSig = 14;
    messageEntries_42[98].pfn = (void (__thiscall *)(CCmdTarget *))CMainFrame::OnWTPacket;
    messageEntries_42[99].nMessage = 0;
    messageEntries_42[99].nCode = 0;
    messageEntries_42[99].nID = 0;
    messageEntries_42[99].nLastID = 0;
    messageEntries_42[99].nSig = 0;
    messageEntries_42[99].pfn = nullptr;
  }
  return &messageMap_0;
}

//------------------------------------------------------------------------------
// Address: 0x10058150
// Name: protected: virtual struct AFX_MSGMAP const __near * CMainFrame::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const AFX_MSGMAP *__thiscall CMainFrame::GetMessageMap(CMainFrame *this)
{
  return CMainFrame::GetThisMessageMap();
}

//------------------------------------------------------------------------------
// Address: 0x100C5240
// Name: public: virtual wndTex::~wndTex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall wndTex::~wndTex(wndTex *this)
{
  CStatic::~CStatic(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEF30
// Name: protected: int CMainFrame::OnHelpInfo(struct tagHELPINFO __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CMainFrame::OnHelpInfo(CMainFrame *this, tagHELPINFO *pHelpInfo)
{
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103341D5
// Name: public: CMDIFrameWnd::CMDIFrameWnd(void)
// Source: json
//------------------------------------------------------------------------------
CMDIFrameWnd *__thiscall CMDIFrameWnd::CMDIFrameWnd(CMDIFrameWnd *this)
{
  CFrameWnd::CFrameWnd(this);
  this->m_hWndMDIClient = nullptr;
  this->__vftable = (CMDIFrameWnd_vtbl *)&CMDIFrameWnd::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103341F0
// Name: protected: virtual long CMDIFrameWnd::DefWindowProcA(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CMDIFrameWnd::DefWindowProcA(CMDIFrameWnd *this, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
  return DefFrameProcA(hWnd: this->m_hWnd, hWndMDIClient: this->m_hWndMDIClient, uMsg: nMsg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10334211
// Name: public: virtual void CMDIFrameWnd::DelayUpdateFrameMenu(struct HMENU__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::DelayUpdateFrameMenu(CMDIFrameWnd *this, HMENU__ *hMenuAlt)
{
  this->OnUpdateFrameMenu(this, a2: hMenuAlt);
  this->m_nIdleFlags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10334230
// Name: public: virtual int CMDIFrameWnd::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::PreCreateWindow(CMDIFrameWnd *this, tagCREATESTRUCTA *cs)
{
  if ( cs->lpszClass == nullptr )
  {
    AfxEndDeferRegisterClass(fToRegister: 4);
    cs->lpszClass = "AfxMDIFrame100s";
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10334255
// Name: public: virtual int CMDIFrameWnd::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::LoadFrame(
        CMDIFrameWnd *this,
        const char *nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  int result; // eax

  result = CFrameWnd::LoadFrame(this, nIDResource, dwDefaultStyle, pParentWnd, pContext);
  if ( result != 0 )
  {
    this->m_hMenuDefault = GetMenu(hWnd: this->m_hWnd);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10334286
// Name: protected: void CMDIFrameWnd::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnDestroy(CMDIFrameWnd *this)
{
  HMENU__ *m_hMenuDefault; // edi

  CFrameWnd::OnDestroy(this);
  if ( this->m_hMenuDefault != nullptr )
  {
    m_hMenuDefault = this->m_hMenuDefault;
    if ( GetMenu(hWnd: this->m_hWnd) != m_hMenuDefault )
      SendMessageA(hWnd: this->m_hWndMDIClient, Msg: 0x230u, wParam: (WPARAM)m_hMenuDefault, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103342BE
// Name: protected: void CMDIFrameWnd::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnSize(CMDIFrameWnd *this, unsigned int nType, int __formal, int a4)
{
  if ( nType != 1 )
    this->RecalcLayout(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103342D7
// Name: protected: long CMDIFrameWnd::OnMenuChar(unsigned int,unsigned int,class CMenu __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::OnMenuChar(CMDIFrameWnd *this, unsigned int nChar, unsigned int __formal, CMenu *a4)
{
  if ( this->m_lpfnCloseProc != nullptr && nChar == 45 )
    return 0;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103342F8
// Name: public: class CMDIChildWnd __near * CMDIFrameWnd::MDIGetActive(int __near *)const
// Source: json
//------------------------------------------------------------------------------
CMDIChildWnd *__thiscall CMDIFrameWnd::MDIGetActive(CMDIFrameWnd *this, int *pbMaximized)
{
  HWND__ *m_hWndMDIClient; // eax
  HWND__ *v4; // eax
  CWnd *v5; // eax
  CWnd *v6; // esi

  m_hWndMDIClient = this->m_hWndMDIClient;
  if ( m_hWndMDIClient != nullptr )
  {
    v4 = (HWND__ *)SendMessageA(hWnd: m_hWndMDIClient, Msg: 0x229u, wParam: 0, lParam: (LPARAM)pbMaximized);
    v5 = CWnd::FromHandlePermanent(hWnd: v4);
    v6 = v5;
    if ( v5 != nullptr && v5[2].m_pProxy != nullptr && (CWnd::GetStyle(this: v5) & 0x10000000) == 0 )
    {
      v6 = nullptr;
      if ( pbMaximized != nullptr )
        *pbMaximized = 0;
    }
    return (CMDIChildWnd *)v6;
  }
  else
  {
    if ( pbMaximized != nullptr )
      *pbMaximized = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103343EC
// Name: public: virtual struct HMENU__ __near * CMDIFrameWnd::GetWindowMenuPopup(struct HMENU__ __near *)
// Source: json
//------------------------------------------------------------------------------
HMENU __thiscall CMDIFrameWnd::GetWindowMenuPopup(CMDIFrameWnd *this, HMENU__ *hMenuBar)
{
  HMENU result; // eax
  HMENU SubMenu; // eax
  HMENU v4; // edi
  int v5; // ebx
  UINT MenuItemID; // eax
  HMENU__ *iItem; // [esp+0h] [ebp-8h]
  int iItemMax; // [esp+4h] [ebp-4h]

  if ( hMenuBar == nullptr )
    return nullptr;
  for ( result = (HMENU)GetMenuItemCount(hMenu: hMenuBar); result != nullptr; result = iItem )
  {
    iItem = (HMENU)((char *)result - 1);
    SubMenu = GetSubMenu(hMenu: hMenuBar, nPos: (int)result - 1);
    v4 = SubMenu;
    if ( SubMenu != nullptr )
    {
      v5 = 0;
      iItemMax = GetMenuItemCount(hMenu: SubMenu);
      if ( iItemMax > 0 )
      {
        do
        {
          MenuItemID = GetMenuItemID(hMenu: v4, nPos: v5);
          if ( MenuItemID >= 0xE130 && MenuItemID <= 0xE13F )
            return v4;
        }
        while ( ++v5 < iItemMax );
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033445B
// Name: public: virtual void CMDIFrameWnd::OnUpdateFrameMenu(struct HMENU__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnUpdateFrameMenu(CMDIFrameWnd *this, HMENU__ *hMenuAlt)
{
  CMDIChildWnd *v3; // eax
  HMENU__ *m_hMenuDefault; // eax

  v3 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( v3 != nullptr )
  {
    v3->OnUpdateFrameMenu(this: v3, a2: 1, a3: v3, a4: hMenuAlt);
  }
  else
  {
    m_hMenuDefault = hMenuAlt;
    if ( hMenuAlt == nullptr )
      m_hMenuDefault = this->m_hMenuDefault;
    SendMessageA(hWnd: this->m_hWndMDIClient, Msg: 0x230u, wParam: (WPARAM)m_hMenuDefault, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033456D
// Name: protected: void CMDIFrameWnd::OnUpdateMDIWindowCmd(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnUpdateMDIWindowCmd(CMDIFrameWnd *this, CCmdUI *pCmdUI)
{
  CCmdUI_vtbl *v2; // esi
  CMDIChildWnd *v3; // eax

  v2 = pCmdUI->__vftable;
  v3 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  v2->Enable(this: pCmdUI, a2: v3 != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10334591
// Name: protected: int CMDIFrameWnd::OnMDIWindowCmd(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::OnMDIWindowCmd(CMDIFrameWnd *this, unsigned int nID)
{
  WPARAM v2; // edx
  UINT v4; // eax

  v2 = 0;
  if ( nID == 57649 )
  {
    v4 = 552;
  }
  else if ( nID == 57650 )
  {
    v4 = 551;
  }
  else
  {
    if ( nID == 57651 )
    {
      v2 = 1;
    }
    else if ( nID != 57652 )
    {
      return 0;
    }
    v4 = 550;
  }
  SendMessageA(hWnd: this->m_hWndMDIClient, Msg: v4, wParam: v2, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103345DC
// Name: public: virtual void CMDIFrameWnd::SetMenuBarVisibility(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::SetMenuBarVisibility(CMDIFrameWnd *this, unsigned int dwStyle)
{
  if ( dwStyle != 1 )
    AfxThrowInvalidArgException();
}

//------------------------------------------------------------------------------
// Address: 0x103345F0
// Name: public: virtual int CMDIFrameWnd::SetMenuBarState(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::SetMenuBarState(CMDIFrameWnd *this, unsigned int dwState)
{
  if ( this->m_dwMenuBarState == 2 )
    return 0;
  else
    return CFrameWnd::SetMenuBarState(this, dwState);
}

//------------------------------------------------------------------------------
// Address: 0x1033460A
// Name: public: static class CObject __near * CMDIFrameWnd::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMDIFrameWnd *__stdcall CMDIFrameWnd::CreateObject()
{
  CMDIFrameWnd *v0; // ecx
  CMDIFrameWnd *result; // eax

  v0 = (CMDIFrameWnd *)operator new(nSize: 0x114u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMDIFrameWnd::CMDIFrameWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033463A
// Name: public: virtual struct CRuntimeClass __near * CMDIFrameWnd::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMDIFrameWnd::GetRuntimeClass(CMDIFrameWnd *this)
{
  return &CMDIFrameWnd::classCMDIFrameWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1033471D
// Name: public: void CMDIFrameWnd::MDIActivate(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::MDIActivate(CMDIFrameWnd *this, CWnd *pWndActivate)
{
  SendMessageA(hWnd: this->m_hWndMDIClient, Msg: 0x222u, wParam: (WPARAM)pWndActivate->m_hWnd, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1033473F
// Name: public: void CMDIFrameWnd::MDINext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::MDINext(CMDIFrameWnd *this)
{
  SendMessageA(hWnd: this->m_hWndMDIClient, Msg: 0x224u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103347F7
// Name: protected: virtual int CMDIFrameWnd::OnCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::OnCommand(CMDIFrameWnd *this, unsigned int wParam, CNoTrackObject_vtbl *lParam)
{
  CMDIChildWnd *v4; // eax

  v4 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( v4 != nullptr
    && AfxCallWndProc(
         pWnd: v4,
         hWnd: (CNoTrackObject_vtbl *)v4->m_hWnd,
         nMsg: (CNoTrackObject_vtbl *)0x111,
         (CNoTrackObject_vtbl *)wParam,
         lParam) != 0
    || CFrameWnd::OnCommand(this, wParam, (int)lParam) != 0 )
  {
    return 1;
  }
  if ( lParam == nullptr && (wParam & 0xF000) == 0xF000 )
  {
    this->DefWindowProcA(this, a2: 273u, a3: wParam, a4: 0);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10334866
// Name: public: virtual int CMDIFrameWnd::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMDIFrameWnd::OnCmdMsg(
        CMDIFrameWnd *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  CMDIChildWnd *v6; // esi
  CMDIChildWnd_vtbl *v7; // eax
  CPushRoutingFrame push; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  v6 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( v6 != nullptr )
  {
    CPushRoutingFrame::CPushRoutingFrame(this: &push, pNewRoutingFrame: this);
    v7 = v6->__vftable;
    v10 = 0;
    if ( v7->OnCmdMsg(this: v6, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo) != 0 )
    {
      CPushRoutingFrame::~CPushRoutingFrame(this: &push);
      return true;
    }
    v10 = -1;
    CPushRoutingFrame::~CPushRoutingFrame(this: &push);
  }
  return CFrameWnd::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x103348D6
// Name: protected: long CMDIFrameWnd::OnCommandHelp(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::OnCommandHelp(
        CMDIFrameWnd *this,
        CNoTrackObject_vtbl *wParam,
        CNoTrackObject_vtbl *lParam)
{
  CNoTrackObject_vtbl *v3; // esi
  CMDIChildWnd *v5; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  v3 = lParam;
  if ( lParam == nullptr && CFrameWnd::IsTracking(this) != 0 )
    v3 = (CNoTrackObject_vtbl *)(this->m_nIDTracking + 0x10000);
  v5 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( v5 != nullptr
    && AfxCallWndProc(
         pWnd: v5,
         hWnd: (CNoTrackObject_vtbl *)v5->m_hWnd,
         nMsg: (CNoTrackObject_vtbl *)0x365,
         wParam,
         lParam: v3) != 0
    || CFrameWnd::OnCommandHelp(this, __formal: (unsigned int)wParam, lParam: (int)v3) != 0 )
  {
    return 1;
  }
  if ( v3 != nullptr && AfxGetModuleState()->m_pCurrentWinApp != nullptr )
  {
    ModuleState = AfxGetModuleState();
    ModuleState->m_pCurrentWinApp->WinHelpInternal(this: ModuleState->m_pCurrentWinApp, a2: (unsigned int)v3, a3: 1u);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10334960
// Name: public: virtual int CMDIFrameWnd::OnCreateClient(struct tagCREATESTRUCTA __near *,struct CCreateContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::OnCreateClient(CMDIFrameWnd *this, tagCREATESTRUCTA *lpcs, CCreateContext *__formal)
{
  CMenu *v4; // eax
  CMenu *v5; // edi
  int MenuItemCount; // eax
  HMENU SubMenu; // eax

  v4 = nullptr;
  if ( this->m_hMenuDefault == nullptr )
  {
    v5 = this->GetMenu(this);
    MenuItemCount = GetMenuItemCount(hMenu: v5->m_hMenu);
    SubMenu = GetSubMenu(hMenu: v5->m_hMenu, nPos: MenuItemCount - 2);
    v4 = CMenu::FromHandle(hMenu: SubMenu);
  }
  return this->CreateClient(this, a2: lpcs, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103349A7
// Name: public: virtual int CMDIFrameWnd::CreateClient(struct tagCREATESTRUCTA __near *,class CMenu __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWnd::CreateClient(CMDIFrameWnd *this, tagCREATESTRUCTA *lpCreateStruct, CMenu *pWindowMenu)
{
  DWORD v4; // ebx
  int v5; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HWND v7; // eax
  tagCLIENTCREATESTRUCT ccs; // [esp+Ch] [ebp-8h] BYREF

  v4 = 1442840577;
  if ( pWindowMenu != nullptr )
    ccs.hWindowMenu = pWindowMenu->m_hMenu;
  else
    ccs.hWindowMenu = nullptr;
  v5 = lpCreateStruct->style & 0x300000;
  ccs.idFirstChild = 65280;
  if ( v5 != 0 )
  {
    v4 = v5 | 0x56000001;
    CWnd::ModifyStyle(this, dwRemove: 0x300000u, dwAdd: 0, nFlags: 0x28u);
  }
  ModuleState = AfxGetModuleState();
  v7 = AfxCtxCreateWindowExA(
         dwExStyle: 0x200u,
         lpClassName: "mdiclient",
         lpWindowName: nullptr,
         dwStyle: v4,
         X: 0,
         Y: 0,
         nWidth: 0,
         nHeight: 0,
         hWndParent: this->m_hWnd,
         hMenu: (HMENU__ *)0xE900,
         hInstance: ModuleState->m_hCurrentInstanceHandle,
         lpParam: &ccs);
  this->m_hWndMDIClient = v7;
  if ( v7 == nullptr )
    return 0;
  BringWindowToTop(hWnd: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10334A3F
// Name: public: virtual int CMDIFrameWnd::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMDIFrameWnd::PreTranslateMessage(CMDIFrameWnd *this, tagMSG *pMsg)
{
  unsigned int message; // eax
  BOOL result; // eax
  CMDIChildWnd *v5; // eax
  unsigned int v6; // eax
  HACCEL__ *m_hAccelTable; // eax
  unsigned int v8; // eax

  message = pMsg->message;
  if ( message == 513 || message == 161 )
    AfxCancelModes(hWndRcvr: pMsg->hwnd);
  if ( CWnd::PreTranslateMessage(this, pMsg) != 0
    || this->m_pNotifyHook != nullptr
    && this->m_pNotifyHook->OnPreTranslateMessage(this: this->m_pNotifyHook, a2: pMsg) != 0 )
  {
    return 1;
  }
  v5 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( v5 != nullptr && v5->PreTranslateMessage(this: v5, a2: pMsg) != 0 )
    return 1;
  v6 = pMsg->message;
  result = false;
  if ( v6 >= 0x100 && v6 <= 0x109 )
  {
    m_hAccelTable = this->m_hAccelTable;
    if ( m_hAccelTable != nullptr
      && TranslateAcceleratorA(hWnd: this->m_hWnd, hAccTable: m_hAccelTable, lpMsg: pMsg) != 0 )
    {
      return true;
    }
    if ( CFrameWnd::GetActiveView(this) == nullptr )
    {
      v8 = pMsg->message;
      if ( (v8 == 256 || v8 == 260) && TranslateMDISysAccel(hWndClient: this->m_hWndMDIClient, lpMsg: pMsg) )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10334B13
// Name: protected: void CMDIFrameWnd::OnIdleUpdateCmdUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnIdleUpdateCmdUI(CMDIFrameWnd *this)
{
  if ( (this->m_nIdleFlags & 1) != 0 )
  {
    DrawMenuBar(hWnd: this->m_hWnd);
    this->m_nIdleFlags &= ~1u;
  }
  CFrameWnd::OnIdleUpdateCmdUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x10334B3B
// Name: public: virtual class CFrameWnd __near * CMDIFrameWnd::GetActiveFrame(void)
// Source: json
//------------------------------------------------------------------------------
CMDIFrameWnd *__thiscall CMDIFrameWnd::GetActiveFrame(CMDIFrameWnd *this)
{
  CMDIFrameWnd *result; // eax

  result = (CMDIFrameWnd *)CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( result == nullptr )
    return this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103352CE
// Name: protected: void CMDIFrameWnd::OnWindowNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnWindowNew(CMDIFrameWnd *this)
{
  CMDIChildWnd *v1; // ebx
  int v2; // eax
  int v3; // edi
  int v4; // esi
  int v5; // eax

  v1 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  if ( v1 != nullptr && (v2 = (int)v1->GetActiveDocument(this: v1), v3 = v2, v2 != 0) )
  {
    v4 = *(_DWORD *)(v2 + 40);
    v5 = (*(int (__thiscall **)(int, int, CMDIChildWnd *))(*(_DWORD *)v4 + 112))(a1: v4, a2: v2, a3: v1);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v4 + 116))(a1: v4, a2: v5, a3: v3, a4: 1);
  }
  else
  {
    AfxMessageBox(nIDPrompt: 0xF109u, nType: 0, nIDHelp: 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033531F
// Name: protected: virtual struct AFX_MSGMAP const __near * CMDIFrameWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMDIFrameWnd::GetMessageMap(CMDIFrameWnd *this)
{
  return &messageMap_8;
}

//------------------------------------------------------------------------------
// Address: 0x10335431
// Name: public: virtual void CMDIFrameWnd::OnUpdateFrameTitle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWnd::OnUpdateFrameTitle(CMDIFrameWnd *this, const char *bAddToTitle)
{
  CFrameWnd *v3; // esi
  CMDIChildWnd *v4; // eax
  CAfxStringMgr *StringManager; // eax
  ATL::CStringData *Title; // eax
  const char *v7; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-14h] BYREF
  const char *lpstrTitle; // [esp+14h] [ebp-10h]
  int v10; // [esp+20h] [ebp-4h]

  if ( (CWnd::GetStyle(this) & 0x8000) != 0
    && (this->m_pNotifyHook == nullptr || this->m_pNotifyHook->OnUpdateFrameTitle(this: this->m_pNotifyHook) == 0) )
  {
    v3 = nullptr;
    lpstrTitle = (const char *)this->GetActiveDocument(this);
    if ( bAddToTitle != nullptr
      && (v4 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr), v3 = v4, v4 != nullptr)
      && (CWnd::GetStyle(this: v4) & 0x1000000) == 0
      && (lpstrTitle != nullptr || (lpstrTitle = (const char *)v3->GetActiveDocument(this: v3)) != nullptr) )
    {
      CFrameWnd::UpdateFrameTitleForDocument(this, lpszDocName: *((char **)lpstrTitle + 8));
    }
    else
    {
      lpstrTitle = nullptr;
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
        this: (ATL::CSimpleStringT<char,0> *)&bAddToTitle,
        pStringMgr: StringManager);
      v10 = 0;
      if ( v3 == nullptr || (CWnd::GetStyle(this: v3) & 0x1000000) != 0 )
      {
        v7 = bAddToTitle;
      }
      else
      {
        Title = (ATL::CStringData *)CFrameWnd::GetTitle(this: v3, &result);
        LOBYTE(v10) = 1;
        ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&bAddToTitle, strSrc: Title);
        LOBYTE(v10) = 0;
        ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
        v7 = bAddToTitle;
        if ( *((_DWORD *)bAddToTitle - 3) != 0 )
          lpstrTitle = bAddToTitle;
      }
      CFrameWnd::UpdateFrameTitleForDocument(this, lpszDocName: (char *)lpstrTitle);
      ATL::CStringData::Release(this: (ATL::CStringData *)v7 - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10337CB1
// Name: protected: void CSplitterWnd::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnSysCommand(CSplitterWnd *this, WPARAM nID, LPARAM lParam)
{
  CWnd *SizingParent; // eax

  if ( (nID & 0xFFF0) == 0xF000 && (SizingParent = CSplitterWnd::GetSizingParent(this)) != nullptr )
    SendMessageA(hWnd: SizingParent->m_hWnd, Msg: 0x112u, wParam: nID, lParam);
  else
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034094A
// Name: protected: void CFrameWnd::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnSysCommand(CFrameWnd *this, __int16 nID, int lParam)
{
  CFrameWnd *TopLevelFrame; // eax
  unsigned int v5; // ecx
  bool v6; // zf
  unsigned int v7; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame == nullptr )
    AfxThrowInvalidArgException();
  v5 = nID & 0xFFF0;
  if ( TopLevelFrame->m_bHelpMode == 0 )
    goto LABEL_11;
  if ( v5 > 0xF040 )
  {
    if ( v5 == 61520 || v5 == 61536 )
      goto LABEL_16;
    v7 = v5 - 61728;
    v6 = v5 == 61728;
  }
  else
  {
    if ( v5 == 61504 || v5 == 61440 || v5 == 61456 )
      goto LABEL_16;
    v7 = v5 - 61472;
    v6 = v5 == 61472;
  }
  if ( !v6 && v7 != 16 )
  {
LABEL_11:
    CWnd::Default(this);
    return;
  }
LABEL_16:
  if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x365u, wParam: 0, lParam: ((v5 - 61440) >> 4) + 126720) == 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x111u, wParam: 0xE147u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103439E4
// Name: public: virtual struct CRuntimeClass __near * CBitmap::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBitmap::GetRuntimeClass(CBitmap *this)
{
  return &CBitmap::classCBitmap;
}

//------------------------------------------------------------------------------
// Address: 0x10345C63
// Name: public: virtual class CWnd __near * CWinThread::GetMainWnd(void)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWinThread::GetMainWnd(CWinThread *this)
{
  CWnd *result; // eax
  HWND ActiveWindow; // eax

  result = this->m_pActiveWnd;
  if ( result == nullptr )
  {
    result = this->m_pMainWnd;
    if ( result == nullptr )
    {
      ActiveWindow = GetActiveWindow();
      return CWnd::FromHandle(hWnd: ActiveWindow);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034AADB
// Name: protected: virtual int CTabCtrl::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabCtrl::OnChildNotify(
        CTabCtrl *this,
        unsigned int message,
        unsigned int wParam,
        tagDRAWITEMSTRUCT *lParam,
        int *pResult)
{
  if ( message != 43 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, (int)lParam, pResult);
  this->DrawItem(this, a2: lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034AAFE
// Name: public: virtual int CTabCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabCtrl::Create(
        CTabCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AfxEndDeferRegisterClass(fToRegister: 256);
  return this->Create(
           this,
           a2: "SysTabControl32",
           a3: nullptr,
           a4: dwStyle,
           a5: rect,
           a6: pParentWnd,
           a7: nID,
           a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034AB31
// Name: public: virtual CTabCtrl::~CTabCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabCtrl::~CTabCtrl(CTabCtrl *this)
{
  this->__vftable = (CTabCtrl_vtbl *)&CTabCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034AB62
// Name: public: long CTabCtrl::InsertItem(unsigned int,int,char const __near *,int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CTabCtrl::InsertItem(
        CTabCtrl *this,
        unsigned int nMask,
        WPARAM nItem,
        char *lpszItem,
        int nImage,
        int lParam)
{
  tagTCITEMA item; // [esp+0h] [ebp-1Ch] BYREF

  item.mask = nMask;
  item.iImage = nImage;
  item.lParam = lParam;
  item.pszText = lpszItem;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1307u, wParam: nItem, lParam: (LPARAM)&item);
}

//------------------------------------------------------------------------------
// Address: 0x1034ABE4
// Name: public: virtual struct CRuntimeClass __near * CTabCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CTabCtrl::GetRuntimeClass(CTabCtrl *this)
{
  return &CTabCtrl::classCTabCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034B251
// Name: protected: void CTabCtrl::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabCtrl::OnDestroy(CTabCtrl *this)
{
  struct _IMAGELIST *v2; // eax

  v2 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1302u, wParam: 0, lParam: 0);
  if ( CImageList::FromHandlePermanent(h: v2) != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1303u, wParam: 0, lParam: 0);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034B387
// Name: protected: virtual struct AFX_MSGMAP const __near * CTabCtrl::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTabCtrl::GetMessageMap(CTabCtrl *this)
{
  return (const AFX_MSGMAP *)&off_10676540;
}

//------------------------------------------------------------------------------
// Address: 0x10353EFD
// Name: public: int CToolBar::LoadBitmapA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolBar::LoadBitmapA(CToolBar *this, const char *lpszResourceName)
{
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HRSRC__ *v5; // ebx
  HBITMAP__ *SysColorBitmap; // eax

  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  ResourceA = FindResourceA(hModule: m_hCurrentResourceHandle, lpName: lpszResourceName, lpType: (LPCSTR)2);
  v5 = ResourceA;
  if ( ResourceA == nullptr )
    return 0;
  SysColorBitmap = AfxLoadSysColorBitmap(hInst: m_hCurrentResourceHandle, hRsrc: ResourceA, bMono: 0);
  if ( CToolBar::AddReplaceBitmap(this, hbmImageWell: SysColorBitmap) == 0 )
    return 0;
  this->m_hInstImageWell = m_hCurrentResourceHandle;
  this->m_hRsrcImageWell = v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10357F4D
// Name: public: virtual int CControlBar::SetStatusText(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CControlBar::SetStatusText(CControlBar *this, WPARAM nHit)
{
  CWnd *Owner; // ebx
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // eax

  Owner = CWnd::GetOwner(this);
  ModuleThreadState = AfxGetModuleThreadState();
  if ( nHit != -1 )
  {
    if ( (this->m_nStateFlags & 8) == 0 || ModuleThreadState->m_nLastStatus != nHit )
    {
      ModuleThreadState->m_pLastStatus = this;
      SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x362u, wParam: nHit, lParam: 0);
      this->m_nStateFlags |= 8u;
      CControlBar::ResetTimer(this, nEvent: 0xE001u, nTime: 0xC8u);
      return 1;
    }
    return 0;
  }
  ModuleThreadState->m_pLastStatus = nullptr;
  if ( (this->m_nStateFlags & 8) == 0 )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 0xE000u);
    return 0;
  }
  SendMessageA(hWnd: Owner->m_hWnd, Msg: 0x375u, wParam: 0xE001u, lParam: 0);
  this->m_nStateFlags &= ~8u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035862C
// Name: public: virtual struct CRuntimeClass __near * CBitmapButton::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBitmapButton::GetRuntimeClass(CBitmapButton *this)
{
  return &CBitmapButton::classCBitmapButton;
}

//------------------------------------------------------------------------------
// Address: 0x10358632
// Name: protected: virtual void CBitmapButton::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapButton::DrawItem(CBitmapButton *this, tagDRAWITEMSTRUCT *lpDIS)
{
  unsigned int itemState; // ecx
  CBitmap *p_m_bitmap; // ebx
  HDC m_hDC; // eax
  HDC CompatibleDC; // eax
  void *m_hObject; // ebx
  CGdiObject *v8; // ebx
  CDC v9; // [esp+10h] [ebp-34h] BYREF
  CDC *v10; // [esp+20h] [ebp-24h]
  tagRECT rcDst; // [esp+24h] [ebp-20h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  itemState = lpDIS->itemState;
  p_m_bitmap = &this->m_bitmap;
  if ( (itemState & 1) != 0 && this->m_bitmapSel.m_hObject != nullptr )
  {
    p_m_bitmap = &this->m_bitmapSel;
  }
  else if ( (itemState & 0x10) != 0 && this->m_bitmapFocus.m_hObject != nullptr )
  {
    p_m_bitmap = &this->m_bitmapFocus;
  }
  else if ( (itemState & 4) != 0 && this->m_bitmapDisabled.m_hObject != nullptr )
  {
    p_m_bitmap = &this->m_bitmapDisabled;
  }
  v10 = CDC::FromHandle(hDC: lpDIS->hDC);
  CDC::CDC(this: &v9);
  v12 = 0;
  if ( v10 != nullptr )
    m_hDC = v10->m_hDC;
  else
    m_hDC = nullptr;
  CompatibleDC = CreateCompatibleDC(hdc: m_hDC);
  CDC::Attach(this: &v9, hDC: CompatibleDC);
  if ( p_m_bitmap != nullptr )
    m_hObject = p_m_bitmap->m_hObject;
  else
    m_hObject = nullptr;
  v8 = CDC::SelectGdiObject(hDC: v9.m_hDC, h: m_hObject);
  if ( v8 != nullptr )
  {
    memset(&rcDst, 0, sizeof(rcDst));
    CopyRect(lprcDst: &rcDst, lprcSrc: &lpDIS->rcItem);
    BitBlt(
      hdc: v10->m_hDC,
      x: rcDst.left,
      y: rcDst.top,
      cx: rcDst.right - rcDst.left,
      cy: rcDst.bottom - rcDst.top,
      hdcSrc: v9.m_hDC,
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    CDC::SelectGdiObject(hDC: v9.m_hDC, h: v8->m_hObject);
  }
  v12 = -1;
  CDC::~CDC(this: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x10360F97
// Name: protected: void CMDIChildWndEx::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnSysCommand(CMDIChildWndEx *this, unsigned int nID, int lParam)
{
  CMDIFrameWndEx *m_pMDIFrame; // ecx

  if ( nID != 61696
    || (m_pMDIFrame = this->m_pMDIFrame) == nullptr
    || CMDIFrameWndEx::AreMDITabs(this: m_pMDIFrame, pnMDITabsType: nullptr) == 0 )
  {
    CFrameWnd::OnSysCommand(this, nID, lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103628C7
// Name: protected: void CMDITabProxyWnd::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDITabProxyWnd::OnSysCommand(CMDITabProxyWnd *this, WPARAM nID, LPARAM lParam)
{
  CMDIChildWndEx *m_pRelatedMDIChildFrame; // ecx
  CFrameWnd *TopLevelFrame; // eax
  CObject *v6; // edi

  m_pRelatedMDIChildFrame = this->m_pRelatedMDIChildFrame;
  if ( m_pRelatedMDIChildFrame != nullptr )
  {
    TopLevelFrame = CWnd::GetTopLevelFrame(this: m_pRelatedMDIChildFrame);
    v6 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
    if ( nID == 61536 )
    {
      CWnd::Default(this);
    }
    else
    {
      if ( nID != 61472 )
        this->m_pRelatedMDIChildFrame->ActivateTopLevelFrame(this: this->m_pRelatedMDIChildFrame);
      SendMessageA(hWnd: (HWND)v6[8].__vftable, Msg: 0x112u, wParam: nID, lParam);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10370177
// Name: public: void CMiniFrameWnd::OnSysCommand(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniFrameWnd::OnSysCommand(CMiniFrameWnd *this, unsigned int nID, int lParam)
{
  int Style; // eax
  __int16 v5; // bx

  Style = CWnd::GetStyle(this);
  v5 = Style;
  if ( Style >= 0
    || (nID & 0xFFF0) == 0xF060
    && (GetKeyState(nVirtKey: 115) >= 0 || GetKeyState(nVirtKey: 18) >= 0 || (v5 & 0x100) == 0)
    || CWnd::HandleFloatingSysCommand(this, nID, lParam) == 0 )
  {
    CFrameWnd::OnSysCommand(this, nID, lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038EC52
// Name: public: virtual void CMDIFrameWndEx::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::WinHelpA(CMDIFrameWndEx *this, unsigned int dwData, unsigned int nCmd)
{
  if ( dwData != 0 || this->m_bContextHelp == 0 )
    CWnd::WinHelpA(this, dwData, nCmd);
  else
    CMDIFrameWndEx::OnContextHelp(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A7D8D
// Name: public: virtual void COleDocIPFrameWndEx::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::WinHelpA(COleDocIPFrameWndEx *this, unsigned int dwData, unsigned int nCmd)
{
  if ( dwData != 0 || this->m_bContextHelp == 0 )
    CWnd::WinHelpA(this, dwData, nCmd);
  else
    COleDocIPFrameWndEx::OnContextHelp(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A95BF
// Name: public: virtual void CFrameWndEx::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::WinHelpA(CFrameWndEx *this, unsigned int dwData, unsigned int nCmd)
{
  if ( dwData != 0 || this->m_bContextHelp == 0 )
    CWnd::WinHelpA(this, dwData, nCmd);
  else
    CFrameWndEx::OnContextHelp(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AA271
// Name: public: virtual int CMFCToolBar::LoadBitmapA(unsigned int,unsigned int,unsigned int,int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::LoadBitmapA(
        CMFCToolBar *this,
        unsigned int uiResID,
        unsigned int uiColdResID,
        unsigned int uiMenuResID,
        int bLocked,
        unsigned int uiDisabledResID,
        unsigned int uiMenuDisabledResID)
{
  int v7; // edx
  CMFCToolBarInfo params; // [esp+0h] [ebp-20h] BYREF

  CMFCToolBarInfo::CMFCToolBarInfo(this: &params);
  params.m_uiColdResID = uiColdResID;
  params.m_uiHotResID = uiResID;
  params.m_uiDisabledResID = uiDisabledResID;
  params.m_uiMenuResID = uiMenuResID;
  params.m_uiMenuDisabledResID = uiMenuDisabledResID;
  return (*(int (__thiscall **)(int, CMFCToolBarInfo *, int))(*(_DWORD *)v7 + 820))(a1: v7, a2: &params, a3: bLocked);
}

//------------------------------------------------------------------------------
// Address: 0x103E5291
// Name: public: virtual int CMFCDropDownToolBar::LoadBitmapA(unsigned int,unsigned int,unsigned int,int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolBar::LoadBitmapA(
        CMFCDropDownToolBar *this,
        unsigned int uiResID,
        unsigned int uiColdResID,
        unsigned int uiMenuResID,
        int __formal,
        unsigned int uiDisabledResID,
        unsigned int uiMenuDisabledResID)
{
  return CMFCToolBar::LoadBitmapA(
           this,
           uiResID,
           uiColdResID,
           uiMenuResID,
           bLocked: 1,
           uiDisabledResID,
           uiMenuDisabledResID);
}

//------------------------------------------------------------------------------
// Address: 0x103F32C1
// Name: protected: int CMFCToolBarsCustomizeDialog::OnHelpInfo(struct tagHELPINFO __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsCustomizeDialog::OnHelpInfo(CMFCToolBarsCustomizeDialog *this, tagHELPINFO *__formal)
{
  WPARAM ActiveIndex; // eax

  ActiveIndex = CPropertySheet::GetActiveIndex(this);
  SendMessageA(hWnd: this->m_pParentFrame->m_hWnd, Msg: AFX_WM_CUSTOMIZEHELP, wParam: ActiveIndex, lParam: (LPARAM)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100535B0
// Name: _ToolMsgToEnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ToolID_t __thiscall ToolMsgToEnum(void *uMsg)
{
  int v1; // eax
  _ToolMsgToEnum::__l2::ToolIDMap_t nIDMap[11]; // [esp+0h] [ebp-58h]

  v1 = 0;
  nIDMap[0].uMsg = 32813;
  nIDMap[0].eToolID = TOOL_POINTER;
  nIDMap[1].uMsg = 32812;
  nIDMap[1].eToolID = TOOL_BLOCK;
  nIDMap[2].uMsg = 32816;
  nIDMap[2].eToolID = TOOL_ENTITY;
  nIDMap[3].uMsg = 32833;
  nIDMap[3].eToolID = TOOL_CAMERA;
  nIDMap[4].uMsg = 32829;
  nIDMap[4].eToolID = TOOL_MAGNIFY;
  nIDMap[5].uMsg = 32952;
  nIDMap[5].eToolID = TOOL_MORPH;
  nIDMap[6].uMsg = 32955;
  nIDMap[6].eToolID = TOOL_CLIPPER;
  nIDMap[7].uMsg = 32962;
  nIDMap[7].eToolID = TOOL_EDITCORDON;
  nIDMap[8].uMsg = 33107;
  nIDMap[8].eToolID = TOOL_OVERLAY;
  nIDMap[9].uMsg = 33008;
  nIDMap[9].eToolID = TOOL_DECAL;
  nIDMap[10].uMsg = 32913;
  nIDMap[10].eToolID = TOOL_FACEEDIT_MATERIAL;
  while ( uMsg != (void *)nIDMap[v1].uMsg )
  {
    if ( (unsigned int)++v1 >= 0xB )
      return TOOL_POINTER;
  }
  return nIDMap[v1].eToolID;
}

//------------------------------------------------------------------------------
// Address: 0x10335539
// Name: public: CSplitterWnd::CSplitterWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSplitterWnd *__thiscall CSplitterWnd::CSplitterWnd(CSplitterWnd *this)
{
  CWnd::CWnd(this);
  this->m_pDynamicViewClass = nullptr;
  this->m_nMaxRows = 0;
  this->m_nMaxCols = 0;
  this->m_nRows = 0;
  this->m_nCols = 0;
  this->m_bHasHScroll = 0;
  this->m_bHasVScroll = 0;
  this->m_pColInfo = nullptr;
  this->m_pRowInfo = nullptr;
  this->m_bTracking = 0;
  this->m_bTracking2 = 0;
  this->m_ptTrackOffset.y = 0;
  this->m_ptTrackOffset.x = 0;
  this->m_rectLimit.right = 0;
  this->m_rectLimit.left = 0;
  this->m_rectLimit.bottom = 0;
  this->m_rectLimit.top = 0;
  this->m_rectTracker.right = 0;
  this->m_rectTracker.left = 0;
  this->m_rectTracker.bottom = 0;
  this->m_rectTracker.top = 0;
  this->m_rectTracker2.right = 0;
  this->m_rectTracker2.left = 0;
  this->m_rectTracker2.bottom = 0;
  this->m_rectTracker2.top = 0;
  this->m_htTrack = 0;
  this->m_cyBorderShare = 0;
  this->m_cxBorderShare = 0;
  this->m_cyBorder = 2;
  this->m_cxBorder = 2;
  this->__vftable = (CSplitterWnd_vtbl *)&CSplitterWnd::`vftable';
  this->m_cySplitter = 7;
  this->m_cxSplitter = 7;
  this->m_cySplitterGap = 7;
  this->m_cxSplitterGap = 7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10335618
// Name: public: virtual CSplitterWnd::~CSplitterWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::~CSplitterWnd(CSplitterWnd *this)
{
  this->__vftable = (CSplitterWnd_vtbl *)&CSplitterWnd::`vftable';
  operator delete(p: this->m_pRowInfo);
  operator delete(p: this->m_pColInfo);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1033565C
// Name: public: class CWnd __near * CSplitterWnd::GetPane(int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CSplitterWnd::GetPane(CSplitterWnd *this, int row, int col)
{
  return CWnd::GetDlgItem(this, nID: col + 16 * (row + 3728));
}

//------------------------------------------------------------------------------
// Address: 0x10335679
// Name: public: void CSplitterWnd::GetRowInfo(int,int __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::GetRowInfo(CSplitterWnd *this, int row, int *cyCur, int *cyMin)
{
  *cyCur = this->m_pRowInfo[row].nCurSize;
  *cyMin = this->m_pRowInfo[row].nMinSize;
}

//------------------------------------------------------------------------------
// Address: 0x103356A7
// Name: public: void CSplitterWnd::SetRowInfo(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::SetRowInfo(CSplitterWnd *this, int row, int cyIdeal, int cyMin)
{
  int v4; // eax

  v4 = row;
  this->m_pRowInfo[v4].nIdealSize = cyIdeal;
  this->m_pRowInfo[v4].nMinSize = cyMin;
}

//------------------------------------------------------------------------------
// Address: 0x103356D1
// Name: public: void CSplitterWnd::GetColumnInfo(int,int __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::GetColumnInfo(CSplitterWnd *this, int col, int *cxCur, int *cxMin)
{
  *cxCur = this->m_pColInfo[col].nCurSize;
  *cxMin = this->m_pColInfo[col].nMinSize;
}

//------------------------------------------------------------------------------
// Address: 0x10337CF3
// Name: protected: virtual int CSplitterWnd::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSplitterWnd::OnCommand(CSplitterWnd *this, unsigned int wParam, int lParam)
{
  CFrameWnd *ParentFrame; // eax

  if ( CWnd::OnCommand(this, wParam, lParam) != 0 )
    return true;
  ParentFrame = CWnd::GetParentFrame(this);
  if ( ParentFrame == nullptr )
    AfxThrowInvalidArgException();
  return SendMessageA(hWnd: ParentFrame->m_hWnd, Msg: 0x111u, wParam, lParam) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10337D3D
// Name: protected: virtual int CSplitterWnd::OnNotify(unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::OnNotify(CSplitterWnd *this, WPARAM wParam, LPARAM lParam, int *pResult)
{
  CFrameWnd *ParentFrame; // eax

  if ( CWnd::OnNotify(this, __formal: wParam, lParam, pResult) == 0 )
  {
    ParentFrame = CWnd::GetParentFrame(this);
    if ( ParentFrame == nullptr )
      AfxThrowInvalidArgException();
    *pResult = SendMessageA(hWnd: ParentFrame->m_hWnd, Msg: 0x4Eu, wParam, lParam);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10337D85
// Name: protected: int CSplitterWnd::OnMouseWheel(unsigned int,short,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::OnMouseWheel(CSplitterWnd *this, unsigned int fFlags, __int16 zDelta, CPoint point)
{
  int v4; // ebx
  int v6; // esi
  CWnd *Pane; // eax
  CObject *v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // eax
  CObject *v11; // eax
  CScrollView *v12; // ebx
  CWnd *v13; // eax
  CWnd *v14; // esi
  bool v15; // cc
  int nOldPos; // [esp+Ch] [ebp-10h]
  int bHasVert; // [esp+10h] [ebp-Ch]
  int row; // [esp+14h] [ebp-8h]
  int col; // [esp+18h] [ebp-4h]

  v4 = 0;
  bHasVert = 0;
  if ( this->m_nRows > 0 )
  {
    while ( 1 )
    {
      v6 = 0;
      if ( this->m_nCols > 0 )
        break;
LABEL_7:
      if ( ++v4 >= this->m_nRows )
        goto LABEL_10;
    }
    while ( 1 )
    {
      Pane = CSplitterWnd::GetPane(this, row: v4, col: v6);
      v8 = AfxDynamicDownCast(pClass: &CScrollView::classCScrollView, pObject: Pane);
      if ( v8 != nullptr )
      {
        v9 = (CWnd *)((int (__thiscall *)(CObject *, int))v8->__vftable[10].GetRuntimeClass)(a1: v8, a2: 1);
        if ( v9 != nullptr && CWnd::IsWindowEnabled(this: v9) != 0 )
          break;
      }
      if ( ++v6 >= this->m_nCols )
        goto LABEL_7;
    }
    bHasVert = 1;
  }
LABEL_10:
  for ( row = 0; row < this->m_nRows; ++row )
  {
    for ( col = 0; col < this->m_nCols; ++col )
    {
      v10 = CSplitterWnd::GetPane(this, row, col);
      v11 = AfxDynamicDownCast(pClass: &CScrollView::classCScrollView, pObject: v10);
      v12 = (CScrollView *)v11;
      if ( v11 != nullptr )
      {
        v13 = (CWnd *)((int (__stdcall *)(bool))v11->__vftable[10].GetRuntimeClass)(a1: bHasVert != 0);
        v14 = v13;
        if ( v13 != nullptr && CWnd::IsWindowEnabled(this: v13) != 0 )
        {
          nOldPos = GetScrollPos(hWnd: v14->m_hWnd, nBar: 2);
          CScrollView::DoMouseWheel(this: v12, fFlags, zDelta, point);
          if ( bHasVert != 0 )
            v15 = col < this->m_nCols - 1;
          else
            v15 = row < this->m_nRows - 1;
          if ( v15 )
            SetScrollPos(hWnd: v14->m_hWnd, nBar: 2, nPos: nOldPos, bRedraw: false);
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10337ED9
// Name: protected: void CSplitterWnd::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnHScroll(
        CSplitterWnd *this,
        unsigned __int16 nSBCode,
        unsigned __int16 nPos,
        CScrollBar *pScrollBar)
{
  int v6; // ebx
  int ScrollPos; // eax
  CWnd *Pane; // eax
  int nOldPos; // [esp+Ch] [ebp-4h]
  WPARAM nSBCodea; // [esp+18h] [ebp+8h]
  HWND__ *nPosa; // [esp+1Ch] [ebp+Ch]
  int row; // [esp+20h] [ebp+10h]

  v6 = GetDlgCtrlID(hWnd: pScrollBar->m_hWnd) - 59904;
  ScrollPos = GetScrollPos(hWnd: pScrollBar->m_hWnd, nBar: 2);
  row = 0;
  nOldPos = ScrollPos;
  if ( this->m_nRows > 0 )
  {
    nSBCodea = nSBCode | (nPos << 16);
    do
    {
      nPosa = pScrollBar->m_hWnd;
      Pane = CSplitterWnd::GetPane(this, row, col: v6);
      SendMessageA(hWnd: Pane->m_hWnd, Msg: 0x114u, wParam: nSBCodea, lParam: (LPARAM)nPosa);
      if ( row < this->m_nRows - 1 )
        SetScrollPos(hWnd: pScrollBar->m_hWnd, nBar: 2, nPos: nOldPos, bRedraw: false);
      ++row;
    }
    while ( row < this->m_nRows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10337F77
// Name: protected: void CSplitterWnd::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::OnVScroll(
        CSplitterWnd *this,
        unsigned __int16 nSBCode,
        unsigned __int16 nPos,
        CScrollBar *pScrollBar)
{
  int v6; // ebx
  int ScrollPos; // eax
  CWnd *Pane; // eax
  int nOldPos; // [esp+Ch] [ebp-4h]
  WPARAM nSBCodea; // [esp+18h] [ebp+8h]
  HWND__ *nPosa; // [esp+1Ch] [ebp+Ch]
  int col; // [esp+20h] [ebp+10h]

  v6 = GetDlgCtrlID(hWnd: pScrollBar->m_hWnd) - 59920;
  ScrollPos = GetScrollPos(hWnd: pScrollBar->m_hWnd, nBar: 2);
  col = 0;
  nOldPos = ScrollPos;
  if ( this->m_nCols > 0 )
  {
    nSBCodea = nSBCode | (nPos << 16);
    do
    {
      nPosa = pScrollBar->m_hWnd;
      Pane = CSplitterWnd::GetPane(this, row: v6, col);
      SendMessageA(hWnd: Pane->m_hWnd, Msg: 0x115u, wParam: nSBCodea, lParam: (LPARAM)nPosa);
      if ( col < this->m_nCols - 1 )
        SetScrollPos(hWnd: pScrollBar->m_hWnd, nBar: 2, nPos: nOldPos, bRedraw: false);
      ++col;
    }
    while ( col < this->m_nCols );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10338015
// Name: public: virtual int CSplitterWnd::DoScroll(class CView __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CSplitterWnd::DoScroll@<eax>(
        CSplitterWnd *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CView *pViewFrom,
        unsigned int nScrollCode,
        int bDoScroll)
{
  int result; // eax
  CView_vtbl *v7; // eax
  int v8; // eax
  int v9; // edi
  CView_vtbl *v10; // eax
  CScrollBar *v11; // eax
  CWnd *Pane; // eax
  int i; // edi
  CWnd *v14; // eax
  int colFrom; // [esp+4h] [ebp-1Ch] BYREF
  CScrollBar *pScrollHorz; // [esp+8h] [ebp-18h]
  int nOldHorz; // [esp+Ch] [ebp-14h]
  int rowFrom; // [esp+10h] [ebp-10h] BYREF
  int nOldVert; // [esp+14h] [ebp-Ch]
  int bResult; // [esp+18h] [ebp-8h]
  CSplitterWnd *v21; // [esp+1Ch] [ebp-4h]
  int col; // [esp+28h] [ebp+8h]

  v21 = this;
  result = CSplitterWnd::IsChildPane(this, pWnd: pViewFrom, pRow: &rowFrom, pCol: &colFrom);
  if ( result != 0 )
  {
    v7 = pViewFrom->__vftable;
    bResult = 0;
    nOldVert = 0;
    v8 = ((int (__thiscall *)(CView *, int, int, int))v7->GetScrollBarCtrl)(a1: pViewFrom, a2: 1, a3, a4: a2);
    v9 = v8;
    if ( v8 != 0 )
      nOldVert = GetScrollPos(hWnd: *(HWND *)(v8 + 32), nBar: 2);
    v10 = pViewFrom->__vftable;
    nOldHorz = 0;
    v11 = v10->GetScrollBarCtrl(this: pViewFrom, a2: 0);
    pScrollHorz = v11;
    if ( v11 != nullptr )
      nOldHorz = GetScrollPos(hWnd: v11->m_hWnd, nBar: 2);
    if ( ((int (__thiscall *)(CView *, unsigned int))pViewFrom->OnScroll)(a1: pViewFrom, a2: nScrollCode) != 0 )
      bResult = 1;
    if ( v9 != 0 )
    {
      for ( col = 0; col < v21->m_nCols; ++col )
      {
        if ( col != colFrom )
        {
          SetScrollPos(hWnd: *(HWND *)(v9 + 32), nBar: 2, nPos: nOldVert, bRedraw: false);
          Pane = CSplitterWnd::GetPane(this: v21, row: rowFrom, col);
          if ( ((int (__thiscall *)(CWnd *, int, _DWORD, int))Pane->__vftable[1].dtr_CObject)(
                 a1: Pane,
                 a2: (unsigned __int16)(BYTE1(nScrollCode) << 8) | 0xFF,
                 a3: 0,
                 a4: bDoScroll) != 0 )
            bResult = 1;
        }
      }
    }
    if ( pScrollHorz != nullptr )
    {
      for ( i = 0; i < v21->m_nRows; ++i )
      {
        if ( i != rowFrom )
        {
          SetScrollPos(hWnd: pScrollHorz->m_hWnd, nBar: 2, nPos: nOldHorz, bRedraw: false);
          v14 = CSplitterWnd::GetPane(this: v21, row: i, col: colFrom);
          if ( ((int (__thiscall *)(CWnd *, int, _DWORD, int))v14->__vftable[1].dtr_CObject)(
                 a1: v14,
                 a2: (unsigned __int8)nScrollCode | 0xFF00,
                 a3: 0,
                 a4: bDoScroll) != 0 )
            bResult = 1;
        }
      }
    }
    return bResult;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10338182
// Name: public: virtual int CSplitterWnd::DoScrollBy(class CView __near *,class CSize,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CSplitterWnd::DoScrollBy@<eax>(
        CSplitterWnd *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CView *pViewFrom,
        CSize sizeScroll,
        int bDoScroll)
{
  int result; // eax
  CView_vtbl *v7; // eax
  int v8; // eax
  int v9; // edi
  CView_vtbl *v10; // eax
  CScrollBar *v11; // eax
  CSplitterWnd *v12; // ebx
  CWnd *Pane; // eax
  CWnd *v14; // eax
  int colFrom; // [esp+4h] [ebp-20h] BYREF
  CScrollBar *pScrollHorz; // [esp+8h] [ebp-1Ch]
  int nOldHorz; // [esp+Ch] [ebp-18h]
  int rowFrom; // [esp+10h] [ebp-14h] BYREF
  int v19; // [esp+14h] [ebp-10h]
  CSplitterWnd *v20; // [esp+18h] [ebp-Ch]
  int nOldVert; // [esp+1Ch] [ebp-8h]
  int bResult; // [esp+20h] [ebp-4h]
  int row; // [esp+2Ch] [ebp+8h]
  int rowa; // [esp+2Ch] [ebp+8h]

  v20 = this;
  result = CSplitterWnd::IsChildPane(this, pWnd: pViewFrom, pRow: &rowFrom, pCol: &colFrom);
  if ( result != 0 )
  {
    v7 = pViewFrom->__vftable;
    bResult = 0;
    nOldVert = 0;
    v8 = ((int (__thiscall *)(CView *, int, int, int))v7->GetScrollBarCtrl)(a1: pViewFrom, a2: 1, a3, a4: a2);
    v9 = v8;
    if ( v8 != 0 )
      nOldVert = GetScrollPos(hWnd: *(HWND *)(v8 + 32), nBar: 2);
    v10 = pViewFrom->__vftable;
    nOldHorz = 0;
    v11 = v10->GetScrollBarCtrl(this: pViewFrom, a2: 0);
    pScrollHorz = v11;
    if ( v11 != nullptr )
      nOldHorz = GetScrollPos(hWnd: v11->m_hWnd, nBar: 2);
    if ( ((int (__thiscall *)(CView *, int))pViewFrom->OnScrollBy)(a1: pViewFrom, a2: sizeScroll.cx) != 0 )
      bResult = 1;
    v12 = v20;
    if ( v9 != 0 )
    {
      row = 0;
      if ( v20->m_nCols > 0 )
      {
        do
        {
          if ( row != colFrom )
          {
            SetScrollPos(hWnd: *(HWND *)(v9 + 32), nBar: 2, nPos: nOldVert, bRedraw: false);
            Pane = CSplitterWnd::GetPane(this: v12, row: rowFrom, col: row);
            v19 = 0;
            if ( ((int (__thiscall *)(CWnd *, _DWORD, int, int))Pane->__vftable[1].Serialize)(
                   a1: Pane,
                   a2: 0,
                   a3: sizeScroll.cy,
                   a4: bDoScroll) != 0 )
              bResult = 1;
          }
          ++row;
        }
        while ( row < v12->m_nCols );
      }
    }
    if ( pScrollHorz != nullptr )
    {
      for ( rowa = 0; rowa < v12->m_nRows; ++rowa )
      {
        if ( rowa != rowFrom )
        {
          SetScrollPos(hWnd: pScrollHorz->m_hWnd, nBar: 2, nPos: nOldHorz, bRedraw: false);
          v14 = CSplitterWnd::GetPane(this: v12, row: rowa, col: colFrom);
          if ( ((int (__thiscall *)(CWnd *, int, _DWORD, int))v14->__vftable[1].Serialize)(
                 a1: v14,
                 a2: sizeScroll.cx,
                 a3: 0,
                 a4: bDoScroll) != 0 )
            bResult = 1;
        }
      }
    }
    return bResult;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103382E5
// Name: public: virtual void CSplitterWnd::SetActivePane(int,int,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSplitterWnd::SetActivePane(CSplitterWnd *this, int row, int col, CView *pWnd)
{
  CView *Pane; // esi
  CFrameWnd *ParentFrame; // eax

  Pane = pWnd;
  if ( pWnd == nullptr )
    Pane = (CView *)CSplitterWnd::GetPane(this, row, col);
  if ( CObject::IsKindOf(this: Pane, pClass: &CView::classCView) != 0 )
  {
    ParentFrame = CWnd::GetParentFrame(this);
    if ( ParentFrame == nullptr )
      AfxThrowInvalidArgException();
    CFrameWnd::SetActiveView(this: ParentFrame, pViewNew: Pane, bNotify: 1);
  }
  else
  {
    CWnd::SetFocus(this: Pane);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033833B
// Name: public: virtual class CWnd __near * CSplitterWnd::GetActivePane(int __near *,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CView *__thiscall CSplitterWnd::GetActivePane(CSplitterWnd *this, int *pRow, int *pCol)
{
  CFrameWnd *ParentFrame; // eax
  CView *ActiveView; // esi
  HWND Focus; // eax

  ParentFrame = CWnd::GetParentFrame(this);
  if ( ParentFrame == nullptr )
    AfxThrowInvalidArgException();
  ActiveView = CFrameWnd::GetActiveView(this: ParentFrame);
  if ( ActiveView != nullptr || (Focus = GetFocus(), (ActiveView = (CView *)CWnd::FromHandle(hWnd: Focus)) != nullptr) )
  {
    if ( CSplitterWnd::IsChildPane(this, pWnd: ActiveView, pRow, pCol) == 0 )
      return nullptr;
  }
  return ActiveView;
}

//------------------------------------------------------------------------------
// Address: 0x1033838D
// Name: public: virtual int CSplitterWnd::Create(class CWnd __near *,int,int,struct tagSIZE,struct CCreateContext __near *,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSplitterWnd::Create(
        CSplitterWnd *this,
        CWnd *pParentWnd,
        int nMaxRows,
        int nMaxCols,
        tagSIZE sizeMin,
        CCreateContext *pContext,
        unsigned int dwStyle,
        unsigned int nID)
{
  CRuntimeClass *m_pNewViewClass; // eax
  CSplitterWnd_vtbl *v11; // edx

  this->m_nMaxRows = nMaxRows;
  this->m_nMaxCols = nMaxCols;
  this->m_nCols = 1;
  this->m_nRows = 1;
  if ( CSplitterWnd::CreateCommon(this, pParentWnd, sizeMin, dwStyle, nID) == 0 )
    return 0;
  m_pNewViewClass = pContext->m_pNewViewClass;
  v11 = this->__vftable;
  this->m_pDynamicViewClass = pContext->m_pNewViewClass;
  if ( ((int (__thiscall *)(CSplitterWnd *, _DWORD, _DWORD, CRuntimeClass *, int, int, CCreateContext *))v11->CreateView)(
         a1: this,
         a2: 0,
         a3: 0,
         a4: m_pNewViewClass,
         a5: sizeMin.cx,
         a6: sizeMin.cy,
         a7: pContext) == 0 )
  {
    this->DestroyWindow(this);
    return 0;
  }
  this->m_pColInfo->nIdealSize = sizeMin.cx;
  this->m_pRowInfo->nIdealSize = sizeMin.cy;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10338418
// Name: public: virtual int CSplitterWnd::CreateStatic(class CWnd __near *,int,int,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSplitterWnd::CreateStatic(
        CSplitterWnd *this,
        CWnd *pParentWnd,
        int nRows,
        int nCols,
        unsigned int dwStyle,
        unsigned int nID)
{
  this->m_nMaxRows = nRows;
  this->m_nRows = nRows;
  this->m_nMaxCols = nCols;
  this->m_nCols = nCols;
  return CSplitterWnd::CreateCommon(this, pParentWnd, sizeMin: 0, dwStyle, nID) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10338453
// Name: protected: virtual struct AFX_MSGMAP const __near * CSplitterWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSplitterWnd::GetMessageMap(CSplitterWnd *this)
{
  return (const AFX_MSGMAP *)&off_10673E1C;
}

//------------------------------------------------------------------------------
// Address: 0x10338459
// Name: protected: CView::CView(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CView *__thiscall CView::CView(CView *this)
{
  CWnd::CWnd(this);
  this->m_pDocument = nullptr;
  this->m_bInitialRedraw = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1033846F
// Name: protected: virtual int CView::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::PreCreateWindow(CView *this, tagCREATESTRUCTA *cs)
{
  int style; // eax

  if ( cs->lpszClass == nullptr )
  {
    AfxEndDeferRegisterClass(fToRegister: 8);
    cs->lpszClass = "AfxFrameOrView100s";
  }
  style = cs->style;
  if ( (style & 0x800000) != 0 )
  {
    cs->dwExStyle |= 0x200u;
    cs->style = style & 0xFF7FFFFF;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103384AD
// Name: protected: void CView::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnDestroy(CView *this)
{
  CFrameWnd *ParentFrame; // eax
  CFrameWnd *v3; // esi

  ParentFrame = CWnd::GetParentFrame(this);
  v3 = ParentFrame;
  if ( ParentFrame != nullptr && CFrameWnd::GetActiveView(this: ParentFrame) == this )
    CFrameWnd::SetActiveView(this: v3, pViewNew: nullptr, bNotify: 1);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103409F0
// Name: protected: void CFrameWnd::OnDropFiles(struct HDROP__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnDropFiles(CFrameWnd *this, HDROP__ *hDropInfo)
{
  HWND v2; // eax
  CWinApp *i; // edi
  UINT nFiles; // [esp+Ch] [ebp-110h]
  UINT iFile; // [esp+10h] [ebp-10Ch]
  char szFileName[260]; // [esp+14h] [ebp-108h] BYREF

  v2 = SetActiveWindow(hWnd: this->m_hWnd);
  CWnd::FromHandle(hWnd: v2);
  nFiles = DragQueryFileA(hDrop: hDropInfo, iFile: 0xFFFFFFFF, lpszFile: nullptr, cch: 0);
  iFile = 0;
  for ( i = AfxGetModuleState()->m_pCurrentWinApp; iFile < nFiles; ++iFile )
  {
    DragQueryFileA(hDrop: hDropInfo, iFile, lpszFile: szFileName, cch: 0x104u);
    i->OpenDocumentFile(this: i, a2: szFileName);
  }
  DragFinish(hDrop: hDropInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10340A99
// Name: protected: int CFrameWnd::OnQueryEndSession(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnQueryEndSession(CFrameWnd *this)
{
  CWinApp *m_pCurrentWinApp; // esi
  bool v3; // zf
  CWinApp_vtbl *v4; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp == nullptr || m_pCurrentWinApp->m_pMainWnd != this )
    return 1;
  v3 = (AfxGetThreadState()->m_lastSentMsg.lParam & 1) == 0;
  v4 = m_pCurrentWinApp->__vftable;
  if ( v3 )
    return v4->SaveAllModified(this: m_pCurrentWinApp);
  else
    return v4->SupportsRestartManager(this: m_pCurrentWinApp);
}

//------------------------------------------------------------------------------
// Address: 0x10340AD3
// Name: protected: void CFrameWnd::OnEndSession(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnEndSession(CFrameWnd *this, int bEnding)
{
  CWinApp *m_pCurrentWinApp; // esi
  int v4; // eax

  if ( bEnding != 0 )
  {
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    if ( m_pCurrentWinApp != nullptr && m_pCurrentWinApp->m_pMainWnd == this )
    {
      if ( (AfxGetThreadState()->m_lastSentMsg.lParam & 1) != 0
        && (v4 = (int)m_pCurrentWinApp->GetDataRecoveryHandler(this: m_pCurrentWinApp)) != 0 )
      {
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 52))(a1: v4, a2: 1);
      }
      else
      {
        AfxOleSetUserCtrl(bUserCtrl: 1);
        CWinApp::CloseAllDocuments(this: m_pCurrentWinApp, bEndSession: 1);
        m_pCurrentWinApp->ExitInstance(this: m_pCurrentWinApp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10340B34
// Name: protected: long CFrameWnd::OnDDEInitiate(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnDDEInitiate(CFrameWnd *this, HWND wParam, int lParam)
{
  CWinApp *m_pCurrentWinApp; // esi
  char szAtomName[260]; // [esp+Ch] [ebp-108h] BYREF

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr
    && (_WORD)lParam != 0
    && HIWORD(lParam) != 0
    && lParam == *(_DWORD *)&m_pCurrentWinApp->m_atomApp )
  {
    GlobalGetAtomNameA(nAtom: m_pCurrentWinApp->m_atomApp, lpBuffer: szAtomName, nSize: 259);
    GlobalAddAtomA(lpString: szAtomName);
    GlobalGetAtomNameA(nAtom: m_pCurrentWinApp->m_atomSystemTopic, lpBuffer: szAtomName, nSize: 259);
    GlobalAddAtomA(lpString: szAtomName);
    SendMessageA(
      hWnd: wParam,
      Msg: 0x3E4u,
      wParam: (WPARAM)this->m_hWnd,
      lParam: *(_DWORD *)&m_pCurrentWinApp->m_atomApp);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10340C1F
// Name: public: virtual class CDocument __near * CFrameWnd::GetActiveDocument(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocument *__thiscall CFrameWnd::GetActiveDocument(CFrameWnd *this)
{
  CView *m_pViewActive; // eax

  m_pViewActive = this->m_pViewActive;
  if ( m_pViewActive != nullptr )
    return m_pViewActive->m_pDocument;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10340C30
// Name: public: void CFrameWnd::ShowControlBar(class CControlBar __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::ShowControlBar(CFrameWnd *this, CControlBar *pBar, int bShow, int bDelay)
{
  CFrameWnd *DockingFrame; // esi
  int v5; // eax

  if ( pBar == nullptr )
    AfxThrowInvalidArgException();
  DockingFrame = CControlBar::GetDockingFrame(this: pBar);
  if ( bDelay != 0 )
  {
    pBar->DelayShow(this: pBar, a2: bShow);
    DockingFrame->m_nIdleFlags |= 0xCu;
  }
  else
  {
    CWnd::SetWindowPos(
      this: pBar,
      pWndInsertAfter: nullptr,
      x: 0,
      y: 0,
      cx: 0,
      cy: 0,
      nFlags: (bShow != 0 ? 64 : 128) | 0x17);
    pBar->DelayShow(this: pBar, a2: bShow);
    if ( bShow != 0 || CControlBar::IsFloating(this: pBar) == 0 )
      DockingFrame->RecalcLayout(this: DockingFrame, a2: 0);
  }
  if ( CControlBar::IsFloating(this: pBar) != 0 )
  {
    if ( pBar->m_pDockBar != nullptr )
      v5 = pBar->m_pDockBar->GetDockedVisibleCount(this: pBar->m_pDockBar);
    else
      v5 = bShow != 0;
    if ( v5 == 1 )
    {
      if ( bShow != 0 )
      {
        DockingFrame->m_nShowDelay = -1;
        if ( bDelay == 0 )
        {
          CWnd::ShowWindow(this: DockingFrame, nCmdShow: 8);
          return;
        }
        DockingFrame->m_nShowDelay = 8;
LABEL_22:
        ((void (__stdcall *)(_DWORD))DockingFrame->RecalcLayout)(a1: 0);
        return;
      }
LABEL_21:
      if ( bDelay != 0 )
        return;
      goto LABEL_22;
    }
    if ( v5 != 0 )
      goto LABEL_21;
    DockingFrame->m_nShowDelay = -1;
    if ( bDelay != 0 )
      DockingFrame->m_nShowDelay = 0;
    else
      CWnd::ShowWindow(this: DockingFrame, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10340D3B
// Name: protected: void CFrameWnd::OnInitMenuPopup(class CMenu __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnInitMenuPopup(CFrameWnd *this, CMenu *pMenu, unsigned int nIndex, int bSysMenu)
{
  CFrameWnd *v4; // ebx
  HMENU Menu; // eax
  CWnd *TopLevelParent; // eax
  int v7; // eax
  HMENU__ *v8; // edi
  int v9; // ebx
  unsigned int MenuItemCount; // eax
  UINT MenuItemID; // eax
  HMENU SubMenu; // eax
  CMenu *v13; // eax
  UINT v14; // eax
  BOOL v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ebx
  UINT v18; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-38h]
  CCmdUI state; // [esp+8h] [ebp-2Ch] BYREF
  CFrameWnd *v21; // [esp+30h] [ebp-4h]
  int nIndexMax; // [esp+44h] [ebp+10h]

  v4 = this;
  m_hWnd = this->m_hWnd;
  v21 = this;
  AfxCancelModes(hWndRcvr: m_hWnd);
  if ( bSysMenu == 0
    && (v4->m_pNotifyHook == nullptr
     || v4->m_pNotifyHook->OnInitMenuPopup(this: v4->m_pNotifyHook, a2: pMenu, a3: nIndex, a4: 0) == 0) )
  {
    if ( pMenu == nullptr )
      AfxThrowInvalidArgException();
    CCmdUI::CCmdUI(this: &state);
    state.m_pMenu = pMenu;
    if ( AfxGetThreadState()->m_hTrackingMenu == pMenu->m_hMenu )
    {
      state.m_pParentMenu = pMenu;
    }
    else
    {
      if ( v4->m_dwMenuBarState == 1 )
        Menu = GetMenu(hWnd: v4->m_hWnd);
      else
        Menu = v4->m_hMenu;
      if ( Menu != nullptr )
      {
        TopLevelParent = CWnd::GetTopLevelParent(this: v4);
        if ( TopLevelParent != nullptr )
        {
          v7 = (int)TopLevelParent->GetMenu(this: TopLevelParent);
          if ( v7 != 0 )
          {
            v8 = *(HMENU__ **)(v7 + 4);
            if ( v8 != nullptr )
            {
              v9 = 0;
              nIndexMax = GetMenuItemCount(hMenu: *(HMENU *)(v7 + 4));
              if ( nIndexMax > 0 )
              {
                while ( GetSubMenu(hMenu: v8, nPos: v9) != pMenu->m_hMenu )
                {
                  if ( ++v9 >= nIndexMax )
                    goto LABEL_20;
                }
                state.m_pParentMenu = CMenu::FromHandle(hMenu: v8);
              }
LABEL_20:
              v4 = v21;
            }
          }
        }
      }
    }
    MenuItemCount = GetMenuItemCount(hMenu: pMenu->m_hMenu);
    state.m_nIndex = 0;
    for ( state.m_nIndexMax = MenuItemCount; state.m_nIndex < state.m_nIndexMax; ++state.m_nIndex )
    {
      MenuItemID = GetMenuItemID(hMenu: pMenu->m_hMenu, nPos: state.m_nIndex);
      state.m_nID = MenuItemID;
      if ( MenuItemID != 0 )
      {
        if ( MenuItemID != -1 )
        {
          state.m_pSubMenu = nullptr;
          v15 = v4->m_bAutoMenuEnable != 0 && MenuItemID < 0xF000;
          CCmdUI::DoUpdate(this: &state, pTarget: v4, bDisableIfNoHndler: v15);
LABEL_33:
          v16 = GetMenuItemCount(hMenu: pMenu->m_hMenu);
          v17 = v16;
          if ( v16 < state.m_nIndexMax )
          {
            for ( state.m_nIndex += v16 - state.m_nIndexMax; state.m_nIndex < v17; ++state.m_nIndex )
            {
              v18 = GetMenuItemID(hMenu: pMenu->m_hMenu, nPos: state.m_nIndex);
              if ( v18 != state.m_nID )
                break;
            }
          }
          state.m_nIndexMax = v17;
          v4 = v21;
          continue;
        }
        SubMenu = GetSubMenu(hMenu: pMenu->m_hMenu, nPos: state.m_nIndex);
        v13 = CMenu::FromHandle(hMenu: SubMenu);
        state.m_pSubMenu = v13;
        if ( v13 != nullptr )
        {
          v14 = GetMenuItemID(hMenu: v13->m_hMenu, nPos: 0);
          state.m_nID = v14;
          if ( v14 != 0 && v14 != -1 )
          {
            CCmdUI::DoUpdate(this: &state, pTarget: v4, bDisableIfNoHndler: 0);
            goto LABEL_33;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10340EE6
// Name: protected: void CFrameWnd::OnMenuSelect(unsigned int,unsigned int,struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnMenuSelect(CFrameWnd *this, unsigned int nItemID, unsigned int nFlags, HMENU__ *hSysMenu)
{
  CFrameWnd *TopLevelFrame; // edx
  COleFrameHook *m_pNotifyHook; // ecx
  unsigned int v7; // edi
  CWnd *v8; // eax
  HWND Parent; // eax
  CFrameWnd *pFrameWnd; // [esp+Ch] [ebp-4h]

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  pFrameWnd = TopLevelFrame;
  if ( TopLevelFrame == nullptr )
    AfxThrowInvalidArgException();
  m_pNotifyHook = this->m_pNotifyHook;
  v7 = nItemID;
  if ( m_pNotifyHook != nullptr )
  {
    if ( m_pNotifyHook->OnMenuSelect(this: m_pNotifyHook, a2: nItemID, a3: nFlags, a4: hSysMenu) != 0 )
      return;
    TopLevelFrame = pFrameWnd;
  }
  if ( nFlags == 0xFFFF )
  {
    this->m_nFlags &= ~0x40u;
    if ( TopLevelFrame->m_bHelpMode != 0 )
      this->m_nIDTracking = 57346;
    else
      this->m_nIDTracking = 57345;
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x362u, wParam: this->m_nIDTracking, lParam: 0);
    v8 = this->GetMessageBar(this);
    if ( v8 != nullptr )
      UpdateWindow(hWnd: v8->m_hWnd);
    if ( hSysMenu == nullptr
      && (this->m_dwMenuBarVisibility & 1) == 0
      && GetKeyState(nVirtKey: 121) >= 0
      && GetKeyState(nVirtKey: 18) >= 0
      && this->m_bMouseHitMenu == 0 )
    {
      this->SetMenuBarState(this, a2: 2u);
    }
    goto LABEL_31;
  }
  if ( this->m_bTempShowMenu != 0 )
  {
    this->m_bTempShowMenu = 0;
    if ( (nFlags & 0x2000) != 0 && (this->m_dwMenuBarVisibility & 1) == 0 )
    {
      this->SetMenuBarState(this, a2: 2u);
      TopLevelFrame = pFrameWnd;
    }
  }
  if ( nItemID == 0 || (nFlags & 0x810) != 0 )
  {
    this->m_nIDTracking = 0;
    goto LABEL_30;
  }
  if ( nItemID - 61440 > 0x1EF )
  {
    if ( nItemID >= 0xFF00 )
    {
      this->m_nIDTracking = 61215;
      goto LABEL_30;
    }
  }
  else
  {
    v7 = ((nItemID - 61440) >> 4) + 61184;
  }
  this->m_nIDTracking = v7;
LABEL_30:
  TopLevelFrame->m_nFlags |= 0x40u;
LABEL_31:
  if ( this->m_nIDTracking != this->m_nIDLastMessage )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
      PostMessageA(hWnd: this->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10341090
// Name: protected: long CFrameWnd::OnPopMessageString(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CFrameWnd::OnPopMessageString(CFrameWnd *this, WPARAM wParam, LPARAM lParam)
{
  if ( (this->m_nFlags & 0x40) != 0 )
    return 0;
  else
    return SendMessageA(hWnd: this->m_hWnd, Msg: 0x362u, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103410B7
// Name: public: virtual class CWnd __near * CFrameWnd::GetMessageBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CFrameWnd::GetMessageBar(CFrameWnd *this)
{
  return CWnd::GetDescendantWindow(hWnd: this->m_hWnd, nID: 59393, bOnlyPerm: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103410C7
// Name: public: void CFrameWnd::SetMessageText(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::SetMessageText(CFrameWnd *this, WPARAM nID)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x362u, wParam: nID, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103410E3
// Name: public: class CControlBar __near * CFrameWnd::GetControlBar(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND *__thiscall CFrameWnd::GetControlBar(CFrameWnd *this, unsigned int nID)
{
  CPtrList::CNode *m_pNodeHead; // esi
  HWND *data; // edi

  if ( nID == 0 )
    return nullptr;
  m_pNodeHead = this->m_listControlBars.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = (HWND *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  while ( GetDlgCtrlID(hWnd: data[8]) != nID );
  return data;
}

//------------------------------------------------------------------------------
// Address: 0x1034112A
// Name: public: void CFrameWnd::OnUpdateControlBarMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnUpdateControlBarMenu(CFrameWnd *this, CCmdUI *pCmdUI)
{
  CWnd *ControlBar; // eax
  CCmdUI_vtbl *v3; // edi
  unsigned int Style; // eax

  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  ControlBar = (CWnd *)CFrameWnd::GetControlBar(this, nID: pCmdUI->m_nID);
  if ( ControlBar != nullptr )
  {
    v3 = pCmdUI->__vftable;
    Style = CWnd::GetStyle(this: ControlBar);
    v3->SetCheck(this: pCmdUI, a2: (Style & 0x10000000) != 0);
  }
  else
  {
    pCmdUI->m_bContinueRouting = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034116D
// Name: public: int CFrameWnd::OnBarCheck(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnBarCheck(CFrameWnd *this, unsigned int nID)
{
  CWnd *ControlBar; // eax
  CControlBar *v4; // esi
  unsigned int Style; // eax

  ControlBar = (CWnd *)CFrameWnd::GetControlBar(this, nID);
  v4 = (CControlBar *)ControlBar;
  if ( ControlBar == nullptr )
    return 0;
  Style = CWnd::GetStyle(this: ControlBar);
  CFrameWnd::ShowControlBar(this, pBar: v4, bShow: (Style & 0x10000000) == 0, bDelay: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103411AB
// Name: protected: void CFrameWnd::OnUpdateKeyIndicator(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnUpdateKeyIndicator(CFrameWnd *this, CCmdUI *pCmdUI)
{
  int v2; // eax
  CCmdUI_vtbl *v3; // esi
  char KeyState; // al
  int v5; // [esp-4h] [ebp-8h]

  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  switch ( pCmdUI->m_nID )
  {
    case 0xE701u:
      v5 = 20;
LABEL_12:
      v2 = v5;
      break;
    case 0xE702u:
      v2 = 144;
      break;
    case 0xE703u:
      v2 = 145;
      break;
    case 0xE706u:
      v5 = 21;
      goto LABEL_12;
    default:
      pCmdUI->m_bContinueRouting = 1;
      return;
  }
  v3 = pCmdUI->__vftable;
  KeyState = GetKeyState(nVirtKey: v2);
  v3->Enable(this: pCmdUI, a2: KeyState & 1);
}

//------------------------------------------------------------------------------
// Address: 0x10341208
// Name: protected: void CFrameWnd::OnUpdateContextHelp(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnUpdateContextHelp(CFrameWnd *this, CCmdUI *pCmdUI)
{
  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  if ( AfxGetMainWnd() == this )
    pCmdUI->SetCheck(this: pCmdUI, a2: this->m_bHelpMode != 0);
  else
    pCmdUI->m_bContinueRouting = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10341248
// Name: public: virtual void CFrameWnd::OnSetPreviewMode(int,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnSetPreviewMode(CFrameWnd *this, HWND__ *bPreview, CPrintPreviewState *pState)
{
  CFrameWnd *v5; // eax
  CPtrList::CNode *m_pNodeHead; // eax
  CControlBar *data; // edi
  int DlgCtrlID; // eax
  HMENU__ *Menu; // eax
  HWND DlgItem; // eax
  unsigned int m_dwMenuBarState; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CFrameWnd *pActiveFrame; // [esp+Ch] [ebp-10h]
  unsigned int nID; // [esp+10h] [ebp-Ch]
  __POSITION *pos; // [esp+14h] [ebp-8h]
  unsigned int dwMask; // [esp+18h] [ebp-4h]
  HWND__ *hWnd; // [esp+24h] [ebp+8h]
  HWND__ *hWnda; // [esp+24h] [ebp+8h]
  unsigned int dwOldStates; // [esp+28h] [ebp+Ch]

  if ( pState == nullptr )
    goto LABEL_2;
  v5 = this->GetActiveFrame(this);
  pActiveFrame = v5;
  if ( v5 == nullptr )
    goto LABEL_2;
  if ( bPreview != nullptr && v5->m_pNotifyHook != nullptr )
    v5->m_pNotifyHook->OnDocActivate(this: v5->m_pNotifyHook, a2: 0);
  m_pNodeHead = this->m_listControlBars.m_pNodeHead;
  dwOldStates = 0;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = (CControlBar *)m_pNodeHead->data;
      pos = (__POSITION *)m_pNodeHead->pNext;
      if ( data == nullptr )
        break;
      DlgCtrlID = GetDlgCtrlID(hWnd: data->m_hWnd);
      nID = DlgCtrlID;
      if ( (unsigned int)(DlgCtrlID - 59392) <= 0x1F )
      {
        dwMask = 1 << DlgCtrlID;
        if ( data->IsVisible(this: data) != 0 )
          dwOldStates |= dwMask;
        if ( data->IsDockBar(this: data) == 0 || nID != 59423 )
          CFrameWnd::ShowControlBar(this, pBar: data, bShow: dwMask & pState->dwStates, bDelay: 1);
      }
      if ( pos == nullptr )
        goto LABEL_18;
      m_pNodeHead = (CPtrList::CNode *)pos;
    }
LABEL_2:
    AfxThrowInvalidArgException();
  }
LABEL_18:
  pState->dwStates = dwOldStates;
  if ( bPreview != nullptr )
  {
    this->m_lpfnCloseProc = pState->lpfnCloseProc;
    CFrameWnd::ShowOwnedWindows(this, bShow: 0);
    hWnd = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: pState->nIDMainPane);
    ShowWindow(hWnd, nCmdShow: 0);
    if ( this->m_dwMenuBarState == 1 )
      Menu = GetMenu(hWnd: this->m_hWnd);
    else
      Menu = this->m_hMenu;
    pState->hMenu = Menu;
    if ( Menu != nullptr )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      this->SetMenu(this, a2: nullptr);
      this->m_nIdleFlags &= ~1u;
    }
    pState->hAccelTable = this->m_hAccelTable;
    this->m_hAccelTable = nullptr;
    CFrameWnd::LoadAccelTable(this, lpszResourceName: (const char *)0x7915);
    if ( pState->nIDMainPane != 59648 )
      hWnd = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 59648);
    if ( hWnd != nullptr )
      SetWindowLongA(hWnd, nIndex: -12, dwNewLong: 59937);
  }
  else
  {
    m_hWnd = this->m_hWnd;
    this->m_lpfnCloseProc = nullptr;
    hWnda = GetDlgItem(hDlg: m_hWnd, nIDDlgItem: 59937);
    if ( hWnda != nullptr )
    {
      DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 59648);
      if ( DlgItem != nullptr )
        SetWindowLongA(hWnd: DlgItem, nIndex: -12, dwNewLong: 59937);
      SetWindowLongA(hWnd: hWnda, nIndex: -12, dwNewLong: 59648);
    }
    if ( pState->hMenu != nullptr )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      m_dwMenuBarState = this->m_dwMenuBarState;
      if ( m_dwMenuBarState == 1 )
      {
        SetMenu(hWnd: this->m_hWnd, hMenu: pState->hMenu);
      }
      else if ( m_dwMenuBarState == 2 )
      {
        this->m_hMenu = pState->hMenu;
      }
    }
    if ( pActiveFrame->m_pNotifyHook != nullptr )
      pActiveFrame->m_pNotifyHook->OnDocActivate(this: pActiveFrame->m_pNotifyHook, a2: 1);
    this->RecalcLayout(this, a2: 1);
    if ( pState->nIDMainPane != 59648 )
      hWnda = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: pState->nIDMainPane);
    ShowWindow(hWnd: hWnda, nCmdShow: 5);
    this->m_hAccelTable = pState->hAccelTable;
    CFrameWnd::ShowOwnedWindows(this, bShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103414B9
// Name: protected: void CFrameWnd::OnIdleUpdateCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnIdleUpdateCmdUI(CFrameWnd *this)
{
  unsigned int m_nIdleFlags; // eax
  HMENU__ *m_hMenuAlt; // [esp-4h] [ebp-8h]

  m_nIdleFlags = this->m_nIdleFlags;
  if ( (m_nIdleFlags & 1) != 0 )
  {
    m_hMenuAlt = this->m_hMenuAlt;
    this->m_nIdleFlags = m_nIdleFlags & 0xFFFFFFFE;
    this->OnUpdateFrameMenu(this, a2: m_hMenuAlt);
  }
  if ( (this->m_nIdleFlags & 2) != 0 )
    this->OnUpdateFrameTitle(this, a2: 1);
  if ( (this->m_nIdleFlags & 8) != 0 )
  {
    this->RecalcLayout(this, a2: this->m_nIdleFlags & 4);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  if ( this->m_nIDTracking != this->m_nIDLastMessage )
    CFrameWnd::SetMessageText(this, nID: this->m_nIDTracking);
  this->m_nIdleFlags = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10341534
// Name: public: virtual void CFrameWnd::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::RecalcLayout(CFrameWnd *this, int bNotify)
{
  unsigned int m_nIdleFlags; // eax
  COleFrameHook *m_pNotifyHook; // ecx
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  if ( this->m_bInRecalcLayout == 0 )
  {
    m_nIdleFlags = this->m_nIdleFlags;
    this->m_bInRecalcLayout = 1;
    if ( (m_nIdleFlags & 4) != 0 )
      bNotify = 1;
    this->m_nIdleFlags = m_nIdleFlags & 0xFFFFFFF3;
    if ( bNotify != 0 )
    {
      m_pNotifyHook = this->m_pNotifyHook;
      if ( m_pNotifyHook != nullptr )
        m_pNotifyHook->OnRecalcLayout(this: m_pNotifyHook);
    }
    if ( (CWnd::GetStyle(this) & 0x2000) != 0 )
    {
      rect.right = 0x7FFF;
      rect.bottom = 0x7FFF;
      rect.left = 0;
      rect.top = 0;
      CWnd::RepositionBars(
        this,
        nIDFirst: 0,
        nIDLast: 0xFFFFu,
        nIDLeftOver: 0xE900u,
        nFlags: 1u,
        lpRectParam: &rect,
        lpRectClient: &rect,
        bStretch: 0);
      CWnd::RepositionBars(
        this,
        nIDFirst: 0,
        nIDLast: 0xFFFFu,
        nIDLeftOver: 0xE900u,
        nFlags: 2u,
        lpRectParam: &this->m_rectBorder,
        lpRectClient: &rect,
        bStretch: 1);
      this->CalcWindowRect(this, a2: &rect, a3: 0);
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: nullptr,
        x: 0,
        y: 0,
        cx: rect.right - rect.left,
        cy: rect.bottom - rect.top,
        nFlags: 0x16u);
    }
    else
    {
      CWnd::RepositionBars(
        this,
        nIDFirst: 0,
        nIDLast: 0xFFFFu,
        nIDLeftOver: 0xE900u,
        nFlags: 2u,
        lpRectParam: &this->m_rectBorder,
        lpRectClient: nullptr,
        bStretch: 1);
    }
    this->m_bInRecalcLayout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034163C
// Name: public: virtual int CFrameWnd::NegotiateBorderSpace(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::NegotiateBorderSpace(CFrameWnd *this, unsigned int nBorderCmd, tagRECT *lpRectBorder)
{
  CRect *p_m_rectBorder; // esi

  if ( nBorderCmd == 1 )
  {
    CWnd::RepositionBars(
      this,
      nIDFirst: 0,
      nIDLast: 0xFFFFu,
      nIDLeftOver: 0xE900u,
      nFlags: 1u,
      lpRectParam: lpRectBorder,
      lpRectClient: nullptr,
      bStretch: 1);
    return 1;
  }
  if ( nBorderCmd == 3 )
  {
    p_m_rectBorder = &this->m_rectBorder;
    if ( lpRectBorder != nullptr )
    {
      if ( !EqualRect(lprc1: &this->m_rectBorder, lprc2: lpRectBorder) )
      {
        CopyRect(lprcDst: p_m_rectBorder, lprcSrc: lpRectBorder);
        return 1;
      }
    }
    else if ( CRect::IsRectNull(this: &this->m_rectBorder) == 0 )
    {
      SetRectEmpty(lprc: p_m_rectBorder);
      return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103416AD
// Name: protected: void CFrameWnd::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnSize(CFrameWnd *this, unsigned int nType, int cx, int cy)
{
  CWnd::Default(this);
  if ( nType != 1 )
    this->RecalcLayout(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103416D1
// Name: protected: int CFrameWnd::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnEraseBkgnd(CFrameWnd *this, CDC *pDC)
{
  if ( this->m_pViewActive != nullptr )
    return 1;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103416E7
// Name: public: virtual void CFrameWnd::ActivateFrame(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::ActivateFrame(CFrameWnd *this, int nCmdShow)
{
  int v2; // edi

  v2 = nCmdShow;
  if ( nCmdShow == -1 )
  {
    if ( IsWindowVisible(hWnd: this->m_hWnd) )
    {
      if ( IsIconic(hWnd: this->m_hWnd) )
        v2 = 9;
    }
    else
    {
      v2 = 1;
    }
  }
  CFrameWnd::BringToTop(this, nCmdShow: v2);
  if ( v2 != -1 )
  {
    CWnd::ShowWindow(this, nCmdShow: v2);
    CFrameWnd::BringToTop(this, nCmdShow: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034173D
// Name: protected: long CFrameWnd::OnMenuChar(unsigned int,unsigned int,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnMenuChar(CFrameWnd *this, unsigned int nChar, unsigned int nFlags, CMenu *pMenu)
{
  if ( this->m_bTempShowMenu != 0 )
  {
    this->m_bTempShowMenu = 0;
    if ( (this->m_dwMenuBarVisibility & 1) == 0 )
      this->SetMenuBarState(this, a2: 2u);
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10341770
// Name: public: virtual int CFrameWnd::SetMenu(class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameWnd::SetMenu(CFrameWnd *this, HMENU__ *pMenu)
{
  unsigned int m_dwMenuBarState; // eax
  HMENU__ *v3; // eax
  HMENU__ *v5; // eax

  m_dwMenuBarState = this->m_dwMenuBarState;
  if ( m_dwMenuBarState == 1 )
  {
    v3 = pMenu;
    if ( pMenu != nullptr )
      v3 = *((HMENU__ **)pMenu + 1);
    return SetMenu(hWnd: this->m_hWnd, hMenu: v3);
  }
  else
  {
    if ( m_dwMenuBarState != 2 )
      AfxThrowInvalidArgException();
    v5 = pMenu;
    if ( pMenu != nullptr )
      v5 = *((HMENU__ **)pMenu + 1);
    this->m_hMenu = v5;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10345C7E
// Name: int AfxInternalPumpMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxInternalPumpMessage()
{
  _AFX_THREAD_STATE *ThreadState; // esi
  BOOL result; // eax

  ThreadState = AfxGetThreadState();
  result = GetMessageA(lpMsg: &ThreadState->m_msgCur, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0);
  if ( result )
  {
    if ( ThreadState->m_msgCur.message != 874 && AfxPreTranslateMessage(pMsg: &ThreadState->m_msgCur) == 0 )
    {
      TranslateMessage(lpMsg: &ThreadState->m_msgCur);
      DispatchMessageA(lpMsg: &ThreadState->m_msgCur);
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10345CC4
// Name: int AfxPumpMessage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxPumpMessage()
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->PumpMessage(this: m_pCurrentWinThread);
  else
    return AfxInternalPumpMessage();
}

//------------------------------------------------------------------------------
// Address: 0x10345CDA
// Name: long _AfxMsgFilterHook(int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall _AfxMsgFilterHook(int code, WPARAM wParam, LPARAM lParam)
{
  CWinThread *m_pCurrentWinThread; // ecx
  CNoTrackObject *Data; // eax

  if ( AfxGetModuleState()->m_bDLL == 0 && code >= 0 )
  {
    m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
    if ( m_pCurrentWinThread != nullptr )
      return m_pCurrentWinThread->ProcessMessageFilter(this: m_pCurrentWinThread, a2: code, a3: (tagMSG *)lParam);
  }
  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  return CallNextHookEx(hhk: (HHOOK)Data[11].__vftable, nCode: code, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10353F50
// Name: public: int CToolBar::SetBitmap(struct HBITMAP__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::SetBitmap(CToolBar *this, HBITMAP__ *hbmImageWell)
{
  this->m_hInstImageWell = nullptr;
  this->m_hRsrcImageWell = nullptr;
  return CToolBar::AddReplaceBitmap(this, hbmImageWell);
}

//------------------------------------------------------------------------------
// Address: 0x10353F69
// Name: protected: void CToolBar::_SetButton(int,struct _TBBUTTON __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CToolBar::_SetButton(CToolBar *this@<ecx>, int a2@<ebx>, unsigned int nIndex, _TBBUTTON *pButton)
{
  CToolBar_vtbl *v5; // eax
  unsigned int dwStyle; // [esp+8h] [ebp-30h]
  WPARAM iTextRows; // [esp+Ch] [ebp-2Ch]
  _TBBUTTON button; // [esp+10h] [ebp-28h] BYREF
  CRect rect; // [esp+24h] [ebp-14h] BYREF

  this->DefWindowProcA(this, a2: 1047u, a3: nIndex, a4: (int)&button);
  pButton->fsState ^= 4u;
  *(_WORD *)button.bReserved = 0;
  *(_WORD *)pButton->bReserved = 0;
  if ( memcmp(lhs: pButton, rhs: &button, siz: 0x14u) != 0 )
  {
    dwStyle = CWnd::GetStyle(this);
    CWnd::ModifyStyle(this, dwRemove: 0x10000000u, dwAdd: 0, nFlags: 0);
    ((void (__thiscall *)(CToolBar *, int, unsigned int, _DWORD, int))this->DefWindowProcA)(
      a1: this,
      a2: 1046,
      a3: nIndex,
      a4: 0,
      a5: a2);
    if ( pButton->iString < -1 )
    {
      iTextRows = SendMessageA(hWnd: this->m_hWnd, Msg: 0x43Du, wParam: 0, lParam: 0);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x43Cu, wParam: iTextRows + 1, lParam: 0);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x43Cu, wParam: iTextRows, lParam: 0);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
      pButton->iString += 1000000;
    }
    ((void (__thiscall *)(CToolBar *, int, unsigned int))this->DefWindowProcA)(a1: this, a2: 1045, a3: nIndex);
    CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: dwStyle & 0x10000000, nFlags: 0);
    if ( ((button.fsStyle ^ pButton->fsStyle) & 1) != 0
      || (pButton->fsStyle & 1) != 0 && pButton->iBitmap != button.iBitmap )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    }
    else
    {
      v5 = this->__vftable;
      memset(&rect, 0, sizeof(rect));
      if ( v5->DefWindowProcA(this, a2: 1053u, a3: nIndex, a4: (int)&rect) != 0 )
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103540CF
// Name: public: virtual void CToolBar::GetItemRect(int,struct tagRECT __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolBar::GetItemRect(CToolBar *this, unsigned int nIndex, tagRECT *lpRect)
{
  if ( this->m_bDelayedButtonLayout != 0 )
    CToolBar::Layout(this);
  if ( this->DefWindowProcA(this, a2: 1053u, a3: nIndex, a4: (int)lpRect) == 0 )
    SetRectEmpty(lprc: lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x1035410C
// Name: public: void CToolBar::SetButtonStyle(int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CToolBar::SetButtonStyle(CToolBar *this@<ecx>, int a2@<ebx>, int nIndex, unsigned int nStyle)
{
  _TBBUTTON button; // [esp+4h] [ebp-18h] BYREF

  CToolBar::_GetButton(this, nIndex, pButton: &button);
  if ( button.fsStyle != (_BYTE)nStyle || button.fsState != BYTE2(nStyle) )
  {
    button.fsStyle = nStyle;
    button.fsState = BYTE2(nStyle);
    CToolBar::_SetButton(this, a2, nIndex, pButton: &button);
    this->m_bDelayedButtonLayout = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035416F
// Name: protected: class CSize CToolBar::CalcSize(struct _TBBUTTON __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CToolBar::CalcSize(CToolBar *this, CSize *result, _TBBUTTON *pData, _TBBUTTON *nCount)
{
  CToolBar_vtbl *v6; // eax
  unsigned __int8 *p_fsStyle; // ebx
  int cx; // edx
  int cy; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int cur; // [esp+Ch] [ebp-Ch]
  int cur_4; // [esp+10h] [ebp-8h]
  char dwExtendedStyle; // [esp+14h] [ebp-4h]
  char result_3; // [esp+23h] [ebp+Bh]
  _TBBUTTON *pDataa; // [esp+24h] [ebp+Ch]
  int cySep; // [esp+28h] [ebp+10h]

  v6 = this->__vftable;
  cur = 0;
  cur_4 = 0;
  result->cx = 0;
  result->cy = 0;
  dwExtendedStyle = v6->DefWindowProcA(this, a2: 1109u, a3: 0, a4: 0);
  if ( (int)nCount > 0 )
  {
    p_fsStyle = &pData->fsStyle;
    for ( pDataa = nCount; pDataa != nullptr; pDataa = (_TBBUTTON *)((char *)pDataa - 1) )
    {
      cySep = *(_DWORD *)(p_fsStyle - 9);
      if ( (CWnd::GetStyle(this) & 0x800) == 0 && _afxComCtlVersion != 262215 )
        cySep = 2 * cySep / 3;
      if ( (*(p_fsStyle - 1) & 8) != 0 )
        goto LABEL_28;
      cx = this->m_sizeButton.cx;
      result_3 = *p_fsStyle & 1;
      if ( result_3 != 0 )
      {
        if ( (*(p_fsStyle - 1) & 0x20) == 0 )
        {
          v10 = cur + *(_DWORD *)(p_fsStyle - 9);
          if ( v10 <= result->cx )
            v10 = result->cx;
          result->cx = v10;
          goto LABEL_22;
        }
        cy = cySep + cur_4 + this->m_sizeButton.cy;
      }
      else
      {
        if ( (*p_fsStyle & 8) != 0 && (dwExtendedStyle & 1) != 0 )
          cx += _afxDropDownWidth;
        v11 = cx + cur;
        if ( cx + cur <= result->cx )
          v11 = result->cx;
        result->cx = v11;
        cy = cur_4 + this->m_sizeButton.cy;
      }
      if ( cy <= result->cy )
        cy = result->cy;
      result->cy = cy;
LABEL_22:
      if ( result_3 != 0 )
        cur += *(_DWORD *)(p_fsStyle - 9);
      else
        cur += cx;
      if ( (*(p_fsStyle - 1) & 0x20) != 0 )
      {
        v12 = this->m_sizeButton.cy + cur_4;
        cur = 0;
        cur_4 = v12;
        if ( result_3 != 0 )
          cur_4 = cySep + v12;
      }
LABEL_28:
      p_fsStyle += 20;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035429D
// Name: protected: void CToolBar::SizeToolBar(struct _TBBUTTON __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolBar::SizeToolBar(CToolBar *this, _TBBUTTON *pData, _TBBUTTON *nCount, int nLength, int bVert)
{
  int v5; // edi
  CSize *v7; // eax
  int cx; // edi
  CSize *v9; // eax
  int v10; // esi
  int cy; // eax
  CSize *v12; // eax
  int v13; // ecx
  CSize result; // [esp+14h] [ebp-18h] BYREF
  CSize sizeMax; // [esp+1Ch] [ebp-10h] BYREF
  int nTarget; // [esp+28h] [ebp-4h]
  int nMax; // [esp+40h] [ebp+14h]

  v5 = 0;
  if ( bVert != 0 )
  {
    CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: 0);
    v7 = CToolBar::CalcSize(this, result: &sizeMax, pData, nCount);
    cx = v7->cx;
    nTarget = v7->cy;
    CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: 0x7FFF);
    v9 = CToolBar::CalcSize(this, result: &sizeMax, pData, nCount);
    v10 = v9->cx;
    cy = v9->cy;
LABEL_21:
    sizeMax.cy = cy;
    while ( cx < v10 )
    {
      CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: (v10 + cx) / 2);
      v12 = CToolBar::CalcSize(this, &result, pData, nCount);
      v13 = v12->cy;
      if ( nLength >= v13 )
      {
        if ( nLength <= v13 )
          return;
        if ( v10 != v12->cx || sizeMax.cy != v12->cy )
        {
          v10 = v12->cx;
          cy = v12->cy;
          goto LABEL_21;
        }
        CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: cx);
        return;
      }
      if ( cx == v12->cx && nTarget == v12->cy )
      {
        CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: v10);
        return;
      }
      cx = v12->cx;
      nTarget = v12->cy;
    }
  }
  else
  {
    nMax = nLength;
    nTarget = CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: nLength);
    if ( CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: 0) != nTarget && nLength > 0 )
    {
      do
      {
        if ( CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: (v5 + nMax) / 2) == nTarget )
        {
          nMax = (v5 + nMax) / 2;
        }
        else
        {
          if ( v5 == (v5 + nMax) / 2 )
          {
            CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: nMax);
            break;
          }
          v5 = (v5 + nMax) / 2;
        }
      }
      while ( v5 < nMax );
    }
    CToolBar::CalcSize(this, result: &sizeMax, pData, nCount);
    CToolBar::WrapToolBar(this, pData, (int)nCount, nWidth: sizeMax.cx);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10354406
// Name: public: virtual int CToolBar::OnToolHitTest(class CPoint,struct tagTOOLINFOA __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CToolBar::OnToolHitTest(CToolBar *this, CPoint point, tagTOOLINFOA *pTI)
{
  unsigned int result; // eax
  unsigned int v5; // edi
  HWND__ *m_hWnd; // ecx
  int nButtons; // [esp+8h] [ebp-40h]
  _TBBUTTON pButton; // [esp+Ch] [ebp-3Ch] BYREF
  _TBBUTTON button; // [esp+20h] [ebp-28h] BYREF
  CRect rect; // [esp+34h] [ebp-14h] BYREF

  result = CWnd::OnToolHitTest(this, point, pTI);
  if ( result == -1 )
  {
    v5 = 0;
    nButtons = this->DefWindowProcA(this, a2: 1048u, a3: 0, a4: 0);
    if ( nButtons <= 0 )
      return -1;
    while ( 1 )
    {
      memset(&rect, 0, sizeof(rect));
      if ( this->DefWindowProcA(this, a2: 1053u, a3: v5, a4: (int)&rect) != 0 )
      {
        ++rect.bottom;
        ++rect.right;
        if ( PtInRect(lprc: &rect, pt: point.tagPOINT)
          && this->DefWindowProcA(this, a2: 1047u, a3: v5, a4: (int)&button) != 0
          && (button.fsStyle & 1) == 0 )
        {
          break;
        }
      }
      if ( (int)++v5 >= nButtons )
        return -1;
    }
    CToolBar::_GetButton(this, nIndex: v5, &pButton);
    result = pButton.idCommand;
    if ( pTI != nullptr && pTI->cbSize >= 0x2C )
    {
      m_hWnd = this->m_hWnd;
      pTI->lpszText = (char *)-1;
      pTI->rect.left = rect.left;
      pTI->rect.top = rect.top;
      pTI->rect.right = rect.right;
      pTI->hwnd = m_hWnd;
      pTI->rect.bottom = rect.bottom;
      pTI->uId = result;
    }
    if ( result == 0 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10354500
// Name: protected: void CToolBar::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolBar::OnNcCalcSize(CToolBar *this, int __formal, tagNCCALCSIZE_PARAMS *lpncsp)
{
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  CControlBar::CalcInsideRect(this, &rect, bHorz: (this->m_dwStyle & 0xA000) != 0);
  lpncsp->rgrc[0].left += rect.left;
  lpncsp->rgrc[0].top += rect.top;
  if ( _afxComCtlVersion < 262215 )
    lpncsp->rgrc[0].top -= 2;
  lpncsp->rgrc[0].right += rect.right;
  lpncsp->rgrc[0].bottom += rect.bottom;
}

//------------------------------------------------------------------------------
// Address: 0x1035458A
// Name: protected: void CToolBar::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolBar::OnWindowPosChanging(CToolBar *this, tagWINDOWPOS *lpWndPos)
{
  unsigned int m_dwStyle; // ebx

  m_dwStyle = this->m_dwStyle;
  this->m_dwStyle = m_dwStyle & 0xFFFFF0FF;
  CControlBar::OnWindowPosChanging(this, lpWndPos);
  this->m_dwStyle = m_dwStyle;
  if ( (m_dwStyle & 4) != 0 && (lpWndPos->flags & 1) == 0 )
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x103545D7
// Name: protected: long CToolBar::OnSetSizeHelper(class CSize __near &,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::OnSetSizeHelper(CToolBar *this, CSize *size, int lParam)
{
  HWND__ *v4; // eax
  LRESULT v5; // eax
  int lResult; // [esp+Ch] [ebp-10h]
  LONG dwStyle; // [esp+10h] [ebp-Ch]
  int bModify; // [esp+14h] [ebp-8h]
  LPARAM dwStyleEx; // [esp+18h] [ebp-4h]

  bModify = 0;
  dwStyle = 0;
  dwStyleEx = 0;
  if ( _afxComCtlVersion >= 262215 )
  {
    dwStyle = CWnd::GetStyle(this);
    bModify = CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x8800u, nFlags: 0);
    if ( _afxComCtlVersion >= 393216 )
    {
      v4 = this != nullptr ? this->m_hWnd : nullptr;
      if ( IsWindow(hWnd: v4) )
      {
        v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x455u, wParam: 0, lParam: 0);
        dwStyleEx = SendMessageA(hWnd: this->m_hWnd, Msg: 0x454u, wParam: 0, lParam: v5 & 0xFFFFFFFE);
      }
    }
  }
  lResult = CWnd::Default(this);
  if ( lResult != 0 )
  {
    size->cx = (__int16)lParam;
    size->cy = SHIWORD(lParam);
  }
  if ( bModify != 0 )
    SetWindowLongA(hWnd: this->m_hWnd, nIndex: -16, dwNewLong: dwStyle);
  if ( dwStyleEx != 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x454u, wParam: 0, lParam: dwStyleEx);
  return lResult;
}

//------------------------------------------------------------------------------
// Address: 0x103546AA
// Name: protected: long CToolBar::OnPreserveZeroBorderHelper(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::OnPreserveZeroBorderHelper(CToolBar *this, unsigned int __formal, int a3)
{
  HWND__ *v4; // eax
  LRESULT v5; // eax
  int lResult; // [esp+Ch] [ebp-10h]
  LONG dwStyle; // [esp+10h] [ebp-Ch]
  int bModify; // [esp+14h] [ebp-8h]
  LPARAM dwStyleEx; // [esp+18h] [ebp-4h]

  bModify = 0;
  dwStyle = 0;
  dwStyleEx = 0;
  if ( _afxComCtlVersion >= 262215 )
  {
    dwStyle = CWnd::GetStyle(this);
    bModify = CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x8800u, nFlags: 0);
    if ( _afxComCtlVersion >= 393216 )
    {
      v4 = this != nullptr ? this->m_hWnd : nullptr;
      if ( IsWindow(hWnd: v4) )
      {
        v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x455u, wParam: 0, lParam: 0);
        dwStyleEx = SendMessageA(hWnd: this->m_hWnd, Msg: 0x454u, wParam: 0, lParam: v5 & 0xFFFFFFFE);
      }
    }
  }
  lResult = CWnd::Default(this);
  if ( bModify != 0 )
    SetWindowLongA(hWnd: this->m_hWnd, nIndex: -16, dwNewLong: dwStyle);
  if ( (dwStyleEx & 1) != 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x454u, wParam: 0, lParam: dwStyleEx);
  return lResult;
}

//------------------------------------------------------------------------------
// Address: 0x1035476C
// Name: protected: long CToolBar::OnPreserveSizingPolicyHelper(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolBar::OnPreserveSizingPolicyHelper(CToolBar *this, unsigned int __formal, int a3)
{
  _DWORD *i; // edi
  unsigned int v5; // esi
  unsigned int ButtonStyle; // eax
  unsigned int v7; // esi
  int lResult; // [esp+Ch] [ebp-8h]
  unsigned int uiButtonNum; // [esp+10h] [ebp-4h]

  i = nullptr;
  uiButtonNum = 0;
  if ( _afxComCtlVersion >= 393216 )
  {
    uiButtonNum = SendMessageA(hWnd: this->m_hWnd, Msg: 0x418u, wParam: 0, lParam: 0);
    v5 = 0;
    for ( i = operator new(nSize: 4 * uiButtonNum); v5 < uiButtonNum; ++v5 )
    {
      ButtonStyle = CToolBar::GetButtonStyle(this, nIndex: v5);
      i[v5] = ButtonStyle;
      CToolBar::SetButtonStyle(this, a2: (int)this, nIndex: v5, nStyle: ButtonStyle & 0xFFFFFFF7);
    }
  }
  v7 = 0;
  lResult = CWnd::Default(this);
  if ( i != nullptr )
  {
    if ( uiButtonNum != 0 )
    {
      do
      {
        CToolBar::SetButtonStyle(this, a2: (int)this, nIndex: v7, nStyle: i[v7]);
        ++v7;
      }
      while ( v7 < uiButtonNum );
    }
    operator delete(p: i);
  }
  return lResult;
}

//------------------------------------------------------------------------------
// Address: 0x1035480E
// Name: protected: void CToolBar::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolBar::OnSysColorChange(CToolBar *this)
{
  HINSTANCE__ *m_hInstImageWell; // eax
  HBITMAP__ *SysColorBitmap; // eax

  m_hInstImageWell = this->m_hInstImageWell;
  if ( m_hInstImageWell != nullptr && this->m_hbmImageWell != nullptr )
  {
    SysColorBitmap = AfxLoadSysColorBitmap(hInst: m_hInstImageWell, hRsrc: this->m_hRsrcImageWell, bMono: 0);
    if ( SysColorBitmap != nullptr )
      CToolBar::AddReplaceBitmap(this, hbmImageWell: SysColorBitmap);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10358736
// Name: unsigned long _AfxMapClientArea(struct HWND__ __near *,struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall _AfxMapClientArea(HWND__ *hWnd, tagPOINT point)
{
  LRESULT v3; // edi

  while ( 1 )
  {
    ScreenToClient(hWnd, lpPoint: &point);
    v3 = SendMessageA(hWnd, Msg: 0x366u, wParam: 0, lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
    ClientToScreen(hWnd, lpPoint: &point);
    if ( (GetWindowLongA(hWnd, nIndex: -16) & 0x40000000) == 0 )
      break;
    hWnd = GetParent(hWnd);
    if ( hWnd == nullptr )
      break;
    if ( v3 != 0 )
      return v3;
  }
  if ( v3 != 0 )
    return v3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103587A6
// Name: unsigned long _AfxMapNonClientArea(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _AfxMapNonClientArea(unsigned int iHit)
{
  if ( iHit > 0x15 )
    return -1;
  else
    return iHit + 0x40000;
}

//------------------------------------------------------------------------------
// Address: 0x10360FCF
// Name: protected: long CMDIChildWndEx::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnIdleUpdateCmdUI(CMDIChildWndEx *this, unsigned int __formal, unsigned int __formala)
{
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10360FE8
// Name: protected: long CMDIChildWndEx::OnChangeVisualManager(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnChangeVisualManager(
        CMDIChildWndEx *this,
        unsigned int __formal,
        unsigned int __formala)
{
  CMDIFrameWndEx *m_pMDIFrame; // eax

  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr && m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup == 0 )
    CFrameImpl::OnChangeVisualManager(this: &this->m_Impl);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036100B
// Name: public: virtual void CMDIChildWndEx::OnTaskbarTabThumbnailActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnTaskbarTabThumbnailActivate(
        CMDIChildWndEx *this,
        unsigned int nState,
        CWnd *pWndOther,
        int bMinimized)
{
  CFrameWnd *TopLevelFrame; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( nState != 2 )
    this->ActivateTopLevelFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036103A
// Name: public: virtual int CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate(
        CMDIChildWndEx *this,
        CWnd *pDesktopWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  CFrameWnd *TopLevelFrame; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( message == 514 )
    this->ActivateTopLevelFrame(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1036106F
// Name: public: virtual struct CRuntimeClass __near * CMDITabProxyWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMDITabProxyWnd::GetRuntimeClass(CMDITabProxyWnd *this)
{
  return &CMDITabProxyWnd::classCMDITabProxyWnd;
}

//------------------------------------------------------------------------------
// Address: 0x10361075
// Name: public: CMDITabProxyWnd::CMDITabProxyWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDITabProxyWnd *__thiscall CMDITabProxyWnd::CMDITabProxyWnd(CMDITabProxyWnd *this)
{
  CWnd::CWnd(this);
  this->m_pRelatedMDIChildFrame = nullptr;
  this->__vftable = (CMDITabProxyWnd_vtbl *)&CMDITabProxyWnd::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036108D
// Name: protected: void CMDITabProxyWnd::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDITabProxyWnd::OnActivate(
        CMDITabProxyWnd *this,
        unsigned int nState,
        CWnd *pWndOther,
        int bMinimized)
{
  if ( this->m_pRelatedMDIChildFrame != nullptr )
    this->m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailActivate(
      this: this->m_pRelatedMDIChildFrame,
      a2: nState,
      a3: pWndOther,
      a4: bMinimized);
}

//------------------------------------------------------------------------------
// Address: 0x103610A8
// Name: protected: int CMDITabProxyWnd::OnMouseActivate(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDITabProxyWnd::OnMouseActivate(
        CMDITabProxyWnd *this,
        CWnd *pDesktopWnd,
        unsigned int nHitTest,
        unsigned int message)
{
  if ( this->m_pRelatedMDIChildFrame != nullptr )
    return this->m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailMouseActivate(
             this: this->m_pRelatedMDIChildFrame,
             a2: pDesktopWnd,
             a3: nHitTest,
             a4: message);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103610C5
// Name: protected: void CMDITabProxyWnd::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDITabProxyWnd::OnClose(CMDITabProxyWnd *this)
{
  if ( this->m_pRelatedMDIChildFrame != nullptr )
    this->m_pRelatedMDIChildFrame->OnPressTaskbarThmbnailCloseButton(this: this->m_pRelatedMDIChildFrame);
}

//------------------------------------------------------------------------------
// Address: 0x103610D7
// Name: public: enum Gdiplus::Status Gdiplus::Graphics::DrawImage(class Gdiplus::Image __near *,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Gdiplus::Status __thiscall Gdiplus::Graphics::DrawImage(
        Gdiplus::Graphics *this,
        Gdiplus::Image *image,
        int x,
        int y,
        int width,
        int height)
{
  Gdiplus::GpImage *nativeImage; // eax
  Gdiplus::Status result; // eax

  if ( image != nullptr )
    nativeImage = image->nativeImage;
  else
    nativeImage = nullptr;
  result = GdipDrawImageRectI(a1: (int)this->nativeGraphics, a2: (int)nativeImage, a3: x, a4: y, a5: width, a6: height);
  if ( result == Ok )
    return Ok;
  this->lastResult = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103701E0
// Name: public: static void CMiniFrameWnd::CalcBorders(struct tagRECT __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMiniFrameWnd::CalcBorders(tagRECT *lpClientRect, DWORD dwStyle, unsigned int dwExStyle)
{
  AdjustWindowRectEx(lpRect: lpClientRect, dwStyle, bMenu: false, dwExStyle: 0x188u);
}

//------------------------------------------------------------------------------
// Address: 0x103701FC
// Name: public: long CMiniFrameWnd::OnQueryCenterWnd(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CMiniFrameWnd::OnQueryCenterWnd(CMiniFrameWnd *this, unsigned int __formal, unsigned int __formala)
{
  HWND Parent; // esi
  LRESULT result; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  result = SendMessageA(hWnd: Parent, Msg: 0x36Bu, wParam: 0, lParam: 0);
  if ( result == 0 )
    return (LRESULT)Parent;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10370224
// Name: public: virtual struct CRuntimeClass __near * CMiniFrameWnd::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMiniFrameWnd::GetRuntimeClass(CMiniFrameWnd *this)
{
  return &CMiniFrameWnd::classCMiniFrameWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1037022A
// Name: protected: int CPaneFrameWnd::OnNcCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneFrameWnd::OnNcCreate(CPaneFrameWnd *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  HWND ForegroundWindow; // eax
  CWnd *v5; // ebx
  HWND LastActivePopup; // eax
  BOOL v7; // eax
  CWnd *pParentWnd; // [esp+8h] [ebp-4h]

  result = CWnd::Default(this);
  if ( result != 0 )
  {
    if ( (CWnd::GetStyle(this) & 0x100) != 0 )
    {
      pParentWnd = CWnd::GetTopLevelParent(this);
      if ( pParentWnd == nullptr )
        AfxThrowInvalidArgException();
      ForegroundWindow = GetForegroundWindow();
      v5 = CWnd::FromHandle(hWnd: ForegroundWindow);
      v7 = true;
      if ( pParentWnd != v5 )
      {
        LastActivePopup = GetLastActivePopup(hWnd: pParentWnd->m_hWnd);
        if ( CWnd::FromHandle(hWnd: LastActivePopup) != v5
          || SendMessageA(hWnd: v5->m_hWnd, Msg: 0x36Du, wParam: 0x40u, lParam: 0) == 0 )
        {
          v7 = false;
        }
      }
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x36Du, wParam: 4 * !v7 + 4, lParam: 0);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038EC75
// Name: protected: void CMDIFrameWndEx::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnActivate(
        CMDIFrameWndEx *this,
        unsigned int nState,
        CFrameWnd *pWndOther,
        int bMinimized)
{
  CFrameWnd::OnActivate(this, nState, pWndOther, bMinimized);
  if ( nState != 0 )
  {
    if ( nState == 2 )
      UpdateWindow(hWnd: this->m_hWnd);
  }
  else if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    CFrameImpl::DeactivateMenu(this: &this->m_Impl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038ECBB
// Name: protected: virtual class COleClientItem __near * CFrameWndEx::GetInPlaceActiveItem(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CFrameWndEx::GetInPlaceActiveItem(CFrameWndEx *this)
{
  CFrameWnd *result; // eax
  CView *ActiveView; // eax
  CView *v3; // esi
  CObject *v4; // eax

  result = this->GetActiveFrame(this);
  if ( result != nullptr )
  {
    ActiveView = CFrameWnd::GetActiveView(this: result);
    v3 = ActiveView;
    if ( ActiveView != nullptr
      && CObject::IsKindOf(this: ActiveView, pClass: &CPreviewViewEx::classCPreviewViewEx) == 0
      && (v4 = AfxDynamicDownCast(pClass: &COleDocument::classCOleDocument, pObject: v3->m_pDocument)) != nullptr )
    {
      return (CFrameWnd *)((int (__thiscall *)(CObject *, CView *))v4->__vftable[22].Serialize)(a1: v4, a2: v3);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038ED0A
// Name: public: virtual void CMDIFrameWndEx::OnSetPreviewMode(int,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnSetPreviewMode(CMDIFrameWndEx *this, HWND__ *bPreview, CPrintPreviewState *pState)
{
  unsigned int dwStates; // ebx
  CMFCRibbonBar *m_pRibbonBar; // eax

  if ( this->m_wndClientArea.m_bTabIsEnabled != 0 )
  {
    this->m_wndClientArea.m_bTabIsVisible = bPreview == nullptr;
    CWnd::ShowWindow(this: &this->m_wndClientArea.m_wndTab, nCmdShow: bPreview != nullptr ? 0 : 4);
  }
  CDockingManager::SetPrintPreviewMode(this: &this->m_dockManager, (int)bPreview, __formal: pState);
  dwStates = pState->dwStates;
  CFrameWnd::OnSetPreviewMode(this, bPreview, pState);
  pState->dwStates = dwStates;
  this->AdjustDockingLayout(this, a2: nullptr);
  this->RecalcLayout(this, a2: 1);
  m_pRibbonBar = this->m_Impl.m_pRibbonBar;
  if ( m_pRibbonBar != nullptr && m_pRibbonBar->m_bReplaceFrameCaption != 0 )
    PostMessageA(hWnd: this->m_hWnd, Msg: AFX_WM_POSTSETPREVIEWFRAME, wParam: (WPARAM)bPreview, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1038EDAC
// Name: public: virtual void CMDIFrameWndEx::AdjustDockingLayout(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::AdjustDockingLayout(CMDIFrameWndEx *this, void *hdwp)
{
  if ( this->m_dockManager.m_bAdjustingBarLayout == 0 )
  {
    this->m_dockManager.AdjustDockingLayout(this: &this->m_dockManager, a2: hdwp);
    this->AdjustClientArea(this);
    if ( CDockingManager::IsOLEContainerMode(this: &this->m_dockManager) != 0 )
      this->RecalcLayout(this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038EDFB
// Name: public: virtual void CMDIFrameWndEx::AdjustClientArea(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::AdjustClientArea(CMDIFrameWndEx *this)
{
  int left; // ecx
  CRect rectClientAreaBounds; // [esp+8h] [ebp-14h] BYREF

  left = this->m_rectBorder.left;
  rectClientAreaBounds = this->m_dockManager.m_rectClientAreaBounds;
  rectClientAreaBounds.left += left;
  rectClientAreaBounds.top += this->m_rectBorder.top;
  rectClientAreaBounds.right -= this->m_rectBorder.right;
  rectClientAreaBounds.bottom -= this->m_rectBorder.bottom;
  if ( this != (CMDIFrameWndEx *)-1088 && this->m_wndClientArea.m_hWnd != nullptr )
    this->m_wndClientArea.CalcWindowRect(this: &this->m_wndClientArea, a2: &rectClientAreaBounds, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1038EE6B
// Name: public: void CMDIFrameWndEx::ActiveItemRecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::ActiveItemRecalcLayout(CMDIFrameWndEx *this)
{
  COleClientItem *v2; // eax
  COleClientItem *v3; // esi
  CWnd *m_pView; // ecx
  CFrameWnd *ParentFrame; // eax

  v2 = this->GetInPlaceActiveItem(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    if ( v2->m_pInPlaceFrame != nullptr )
      v2->m_pInPlaceFrame->OnRecalcLayout(this: v2->m_pInPlaceFrame);
    m_pView = v3->m_pView;
    if ( m_pView != nullptr )
    {
      ParentFrame = CWnd::GetParentFrame(this: m_pView);
      if ( ParentFrame != nullptr && ParentFrame[1].m_pStdObject != nullptr )
        v3->m_pInPlaceFrame->OnRecalcLayout(this: v3->m_pInPlaceFrame);
    }
  }
  this->AdjustClientArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x1038EEBA
// Name: protected: int CMDIFrameWndEx::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnCreate(CMDIFrameWndEx *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CFrameWnd::OnCreate(this, lpcs: lpCreateStruct);
  if ( result != -1 )
  {
    CDockingManager::Create(this: &this->m_dockManager, pParentWnd: this);
    this->m_Impl.m_bHasBorder = (lpCreateStruct->style & 0x800000) != 0;
    CFrameImpl::AddFrame(pFrame: this);
    CFrameImpl::OnChangeVisualManager(this: &this->m_Impl);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038EF09
// Name: protected: void CMDIFrameWndEx::OnUpdatePaneMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnUpdatePaneMenu(CMDIFrameWndEx *this, CCmdUI *pCmdUI)
{
  CBasePane *Pane; // eax
  BOOL v3; // eax

  Pane = CMDIFrameWndEx::GetPane(this, nID: pCmdUI->m_nID);
  if ( Pane != nullptr )
  {
    v3 = IsWindowVisible(hWnd: Pane->m_hWnd);
    pCmdUI->SetCheck(this: pCmdUI, a2: v3);
  }
  else
  {
    pCmdUI->m_bContinueRouting = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038EF3D
// Name: protected: int CMDIFrameWndEx::OnPaneCheck(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnPaneCheck(CMDIFrameWndEx *this, unsigned int nID)
{
  CBasePane *Pane; // eax
  CBasePane *v3; // esi
  BOOL v4; // eax

  Pane = CMDIFrameWndEx::GetPane(this, nID);
  v3 = Pane;
  if ( Pane == nullptr )
    return 0;
  v4 = IsWindowVisible(hWnd: Pane->m_hWnd);
  v3->ShowPane(this: v3, a2: !v4, a3: 0, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1038EF7A
// Name: protected: void CMDIFrameWndEx::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnSize(CMDIFrameWndEx *this, unsigned int nType, int cx, int cy)
{
  CFrameImpl *p_m_Impl; // ebx
  CMDIFrameWndEx_vtbl *v6; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-48h]
  tagWINDOWPOS wndpos; // [esp+8h] [ebp-34h] BYREF
  int bParam; // [esp+24h] [ebp-18h] BYREF
  CRect rectWindow; // [esp+28h] [ebp-14h] BYREF

  if ( this->m_bClosing != 0 )
  {
    CMDIFrameWnd::OnSize(this, nType, __formal: cx, a4: cy);
  }
  else
  {
    this->m_bIsMinimized = nType == 1;
    if ( this->m_Impl.m_pRibbonBar != nullptr
      || (p_m_Impl = &this->m_Impl, CFrameImpl::IsOwnerDrawCaption(this: &this->m_Impl) != 0) )
    {
      m_hWnd = this->m_hWnd;
      memset(&rectWindow, 0, sizeof(rectWindow));
      GetWindowRect(hWnd: m_hWnd, lpRect: &rectWindow);
      wndpos.x = rectWindow.left;
      wndpos.cy = rectWindow.bottom - rectWindow.top;
      wndpos.y = rectWindow.top;
      p_m_Impl = &this->m_Impl;
      wndpos.flags = 32;
      wndpos.cx = rectWindow.right - rectWindow.left;
      CFrameImpl::OnWindowPosChanging(this: &this->m_Impl, lpwndpos: &wndpos);
    }
    ((void (__stdcall *)(bool))this->m_dockManager.OnActivateFrame)(a1: this->m_bIsMinimized == 0);
    if ( this->m_bIsMinimized != 0 || nType == 2 || this->m_bWasMaximized != 0 )
    {
      CMDIFrameWnd::OnSize(this, nType, __formal: cx, a4: cy);
      if ( nType == 2 || nType == 0 && this->m_bWasMaximized != 0 )
        this->RecalcLayout(this, a2: 1);
      this->m_bWasMaximized = nType == 2;
    }
    else
    {
      v6 = this->__vftable;
      this->m_dockManager.m_bSizeFrame = 1;
      v6->AdjustDockingLayout(this, a2: nullptr);
      CMDIFrameWnd::OnSize(this, nType, __formal: cx, a4: cy);
      this->m_dockManager.m_bSizeFrame = 0;
      bParam = 0;
      SystemParametersInfoA(uiAction: 0x26u, uiParam: 0, pvParam: &bParam, fWinIni: 0);
      if ( bParam == 0 )
        this->RecalcLayout(this, a2: 1);
    }
    CFrameImpl::UpdateCaption(this: p_m_Impl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038F0F5
// Name: protected: void CMDIFrameWndEx::OnWindowNew(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnWindowNew(CMDIFrameWndEx *this)
{
  CMDIChildWnd *v1; // eax
  CWnd *v2; // esi
  int v3; // ebx
  CMDIChildWnd *v4; // eax

  v1 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v3 = 0;
    if ( IsZoomed(hWnd: v1->m_hWnd) )
    {
      CWnd::ShowWindow(this: v2, nCmdShow: 9);
      v3 = 1;
    }
    CMDIFrameWnd::OnWindowNew(this);
    RedrawWindow(hWnd: v2->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    if ( v3 != 0 )
    {
      v4 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: nullptr);
      if ( v4 != nullptr )
        CWnd::ShowWindow(this: v4, nCmdShow: 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A7DB0
// Name: protected: void COleDocIPFrameWndEx::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnActivate(
        COleDocIPFrameWndEx *this,
        unsigned int nState,
        CFrameWnd *pWndOther,
        int bMinimized)
{
  HWND__ *v5; // eax
  CWnd *v6; // eax

  CFrameWnd::OnActivate(this, nState, pWndOther, bMinimized);
  if ( nState != 0 )
  {
    if ( nState == 2 )
    {
      UpdateWindow(hWnd: this->m_hWnd);
LABEL_4:
      v5 = g_pTopLevelFrame;
      if ( g_pTopLevelFrame != nullptr )
        v5 = *((HWND__ **)g_pTopLevelFrame + 8);
      this->m_hwndLastTopLevelFrame = v5;
      g_pTopLevelFrame = (HWND)this;
      return;
    }
  }
  else
  {
    CFrameImpl::DeactivateMenu(this: &this->m_Impl);
  }
  if ( nState != 0 )
    goto LABEL_4;
  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
    SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
  if ( g_pTopLevelFrame == (HWND)this )
  {
    v6 = CWnd::FromHandlePermanent(hWnd: this->m_hwndLastTopLevelFrame);
    g_pTopLevelFrame = (HWND)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A7E4A
// Name: public: virtual void COleDocIPFrameWndEx::AdjustDockingLayout(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::AdjustDockingLayout(COleDocIPFrameWndEx *this, void *hdwp)
{
  HWND i; // eax
  CWnd *v4; // eax

  for ( i = GetWindow(hWnd: this->m_hWnd, uCmd: 5u); ; i = GetWindow(hWnd: this->m_hWnd, uCmd: 2u) )
  {
    v4 = CWnd::FromHandle(hWnd: i);
    if ( v4 == nullptr || CObject::IsKindOf(this: v4, pClass: &CBasePane::classCBasePane) == 0 )
      break;
  }
  this->m_dockManager.AdjustDockingLayout(this: &this->m_dockManager, a2: hdwp);
}

//------------------------------------------------------------------------------
// Address: 0x103A7E8C
// Name: protected: void COleDocIPFrameWndEx::OnUpdatePaneMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnUpdatePaneMenu(COleDocIPFrameWndEx *this, CCmdUI *pCmdUI)
{
  CBasePane *Pane; // eax
  CCmdUI_vtbl *v3; // edi
  unsigned int Style; // eax

  Pane = COleDocIPFrameWndEx::GetPane(this, nID: pCmdUI->m_nID);
  if ( Pane != nullptr )
  {
    v3 = pCmdUI->__vftable;
    Style = CWnd::GetStyle(this: Pane);
    v3->SetCheck(this: pCmdUI, a2: (Style & 0x10000000) != 0);
  }
  else
  {
    pCmdUI->m_bContinueRouting = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A7EC6
// Name: protected: void COleDocIPFrameWndEx::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnDestroy(COleDocIPFrameWndEx *this)
{
  CWnd *v2; // eax
  HWND i; // eax
  CWnd *v4; // eax
  CWnd *v5; // esi
  CList<HWND__ *,HWND__ *>::CNode *m_pNodeHead; // esi
  HWND data; // ebx
  HWND__ *m_hWnd; // [esp-4h] [ebp-3Ch]
  CList<HWND__ *,HWND__ *> lstChildren; // [esp+10h] [ebp-28h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
    SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
  if ( g_pTopLevelFrame == (HWND)this )
  {
    v2 = CWnd::FromHandlePermanent(hWnd: this->m_hwndLastTopLevelFrame);
    g_pTopLevelFrame = (HWND)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v2);
  }
  CFrameImpl::DeactivateMenu(this: &this->m_Impl);
  if ( this->m_hAccelTable != nullptr )
  {
    DestroyAcceleratorTable(hAccel: this->m_hAccelTable);
    this->m_hAccelTable = nullptr;
  }
  this->m_dockManager.m_bEnableAdjustLayout = 0;
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  memset(&lstChildren.m_pNodeHead, 0, 20);
  lstChildren.m_nBlockSize = 10;
  m_hWnd = this->m_hWnd;
  v10 = 0;
  for ( i = GetTopWindow(hWnd: m_hWnd); ; i = GetWindow(hWnd: v5->m_hWnd, uCmd: 2u) )
  {
    v4 = CWnd::FromHandle(hWnd: i);
    v5 = v4;
    if ( v4 == nullptr )
      break;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&lstChildren,
      newElement: (CFrameWnd *)v4->m_hWnd);
  }
  m_pNodeHead = lstChildren.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( IsWindow(hWnd: data) && GetParent(hWnd: data) == this->m_hWnd )
      DestroyWindow(hWnd: data);
  }
  COleIPFrameWnd::OnDestroy(this);
  v10 = -1;
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&lstChildren);
}

//------------------------------------------------------------------------------
// Address: 0x103A7FD5
// Name: protected: virtual struct AFX_MSGMAP const __near * COleDocIPFrameWndEx::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COleDocIPFrameWndEx::GetMessageMap(COleDocIPFrameWndEx *this)
{
  return (const AFX_MSGMAP *)&off_10680C00;
}

//------------------------------------------------------------------------------
// Address: 0x103A7FDB
// Name: public: virtual struct CRuntimeClass __near * COleIPFrameWndEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COleIPFrameWndEx::GetRuntimeClass(COleIPFrameWndEx *this)
{
  return &COleIPFrameWndEx::classCOleIPFrameWndEx;
}

//------------------------------------------------------------------------------
// Address: 0x103A7FE1
// Name: protected: COleIPFrameWndEx::COleIPFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleIPFrameWndEx *__thiscall COleIPFrameWndEx::COleIPFrameWndEx(COleIPFrameWndEx *this)
{
  COleIPFrameWnd::COleIPFrameWnd(this);
  this->__vftable = (COleIPFrameWndEx_vtbl *)&COleIPFrameWndEx::`vftable';
  this->m_bContextHelp = 0;
  this->m_hwndLastTopLevelFrame = nullptr;
  CFrameImpl::CFrameImpl(this: &this->m_Impl, pFrame: this);
  CDockingManager::CDockingManager(this: &this->m_dockManager);
  CDockingManager::Create(this: &this->m_dockManager, pParentWnd: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A8041
// Name: public: virtual int COleIPFrameWndEx::OnShowCustomizePane(class CMFCPopupMenu __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnShowCustomizePane(
        COleIPFrameWndEx *this,
        CMFCPopupMenu *pMenuPane,
        unsigned int uiToolbarID)
{
  CFrameImpl::AddDefaultButtonsToCustomizePane(this: &this->m_Impl, pMenuPane, __formal: uiToolbarID);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A805E
// Name: protected: virtual COleIPFrameWndEx::~COleIPFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::~COleIPFrameWndEx(COleIPFrameWndEx *this)
{
  this->__vftable = (COleIPFrameWndEx_vtbl *)&COleIPFrameWndEx::`vftable';
  CDockingManager::~CDockingManager(this: &this->m_dockManager);
  CFrameImpl::~CFrameImpl(this: &this->m_Impl);
  COleIPFrameWnd::~COleIPFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A80A7
// Name: protected: long COleIPFrameWndEx::OnMenuChar(unsigned int,unsigned int,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnMenuChar(
        COleIPFrameWndEx *this,
        unsigned int nChar,
        unsigned int nFlags,
        CMenu *pMenu)
{
  if ( CFrameImpl::OnMenuChar(this: &this->m_Impl, nChar) != 0 )
    return -65534;
  else
    return CFrameWnd::OnMenuChar(this, nChar, nFlags, pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x103A80DD
// Name: protected: int COleIPFrameWndEx::ShowPopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::ShowPopupMenu(COleIPFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  int result; // eax

  result = CFrameImpl::OnShowPopupMenu(this: &this->m_Impl, pMenuPopup, __formal: this);
  if ( result != 0 )
  {
    if ( pMenuPopup != nullptr && pMenuPopup->m_bShown != 0 )
      return 1;
    else
      return this->OnShowPopupMenu(this, a2: pMenuPopup);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A811D
// Name: public: virtual void COleIPFrameWndEx::OnClosePopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::OnClosePopupMenu(COleIPFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  if ( CMFCPopupMenu::m_pActivePopupMenu == (HWND)pMenuPopup )
    CMFCPopupMenu::m_pActivePopupMenu = nullptr;
  CDockingManager::OnClosePopupMenu(this: &this->m_dockManager);
}

//------------------------------------------------------------------------------
// Address: 0x103A8142
// Name: protected: virtual int COleIPFrameWndEx::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnCommand(COleIPFrameWndEx *this, unsigned int wParam, int lParam)
{
  if ( HIWORD(wParam) == 1 )
  {
    CMFCToolBar::AddCommandUsage(uiCommand: (unsigned __int16)wParam);
    if ( CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: 27, pbProcessAccel: nullptr) != 0
      || afxUserToolsManager != nullptr
      && CUserToolsManager::InvokeTool(this: afxUserToolsManager, uiCmdId: (unsigned __int16)wParam) != 0 )
    {
      return 1;
    }
  }
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
    return 0;
  return CFrameWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103A81AD
// Name: public: virtual int COleIPFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::LoadFrame(
        COleIPFrameWndEx *this,
        const char *nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  this->m_Impl.m_nIDDefaultResource = (unsigned int)nIDResource;
  CFrameImpl::LoadLargeIconsState(this: &this->m_Impl);
  return CFrameWnd::LoadFrame(this, nIDResource, dwDefaultStyle, pParentWnd, pContext);
}

//------------------------------------------------------------------------------
// Address: 0x103A81E1
// Name: protected: long COleIPFrameWndEx::OnToolbarCreateNew(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CMFCToolBar *__thiscall COleIPFrameWndEx::OnToolbarCreateNew(
        COleIPFrameWndEx *this,
        unsigned int __formal,
        const char *lp)
{
  if ( lp == nullptr )
    AfxThrowInvalidArgException();
  return CFrameImpl::CreateNewToolBar(this: &this->m_Impl, lpszName: lp);
}

//------------------------------------------------------------------------------
// Address: 0x103A8203
// Name: protected: long COleIPFrameWndEx::OnToolbarDelete(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnToolbarDelete(COleIPFrameWndEx *this, unsigned int __formal, CMFCToolBar *lp)
{
  return CFrameImpl::DeleteToolBar(this: &this->m_Impl, pToolBar: lp);
}

//------------------------------------------------------------------------------
// Address: 0x103A821A
// Name: protected: void COleIPFrameWndEx::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::OnClose(COleIPFrameWndEx *this)
{
  CFrameImpl::OnCloseFrame(this: &this->m_Impl);
  CFrameWnd::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A8232
// Name: public: int COleIPFrameWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::AddPane(COleIPFrameWndEx *this, CBasePane *pControlBar, int bTail)
{
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A8250
// Name: public: int COleIPFrameWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::InsertPane(
        COleIPFrameWndEx *this,
        CBasePane *pControlBar,
        CBasePane *pTarget,
        int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x103A8261
// Name: public: void COleIPFrameWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::RemovePaneFromDockManager(
        COleIPFrameWndEx *this,
        CBasePane *pControlBar,
        int bDestroy,
        int bAdjustLayout,
        int bAutoHide,
        CBasePane *pBarReplacement)
{
  CDockingManager::RemovePaneFromDockManager(
    this: &this->m_dockManager,
    pWnd: pControlBar,
    bDestroy,
    bAdjustLayout,
    bAutoHide,
    pBarReplacement);
}

//------------------------------------------------------------------------------
// Address: 0x103A8272
// Name: public: void COleIPFrameWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::DockPane(
        COleIPFrameWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *lpRect)
{
  CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x103A8283
// Name: public: class CBasePane __near * COleIPFrameWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall COleIPFrameWndEx::PaneFromPoint(
        COleIPFrameWndEx *this,
        CPoint point,
        int nSensitivity,
        int bExactBar,
        CRuntimeClass *pRTCBarType)
{
  return ((CBasePane *(__thiscall *)(CDockingManager *, int, int, int, int, CRuntimeClass *, _DWORD, _DWORD))this->m_dockManager.PaneFromPoint_2)(
           a1: &this->m_dockManager,
           a2: point.x,
           a3: point.y,
           a4: nSensitivity,
           a5: bExactBar,
           a6: pRTCBarType,
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A82AA
// Name: public: int COleIPFrameWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::IsPointNearDockSite(
        COleIPFrameWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x103A82CA
// Name: public: virtual int COleIPFrameWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnMoveMiniFrame(COleIPFrameWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x103A82DB
// Name: protected: virtual int COleIPFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::PreCreateWindow(COleIPFrameWndEx *this, tagCREATESTRUCTA *cs)
{
  this->m_Impl.m_pDockManager = &this->m_dockManager;
  return CFrameWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x103A82F2
// Name: public: class CBasePane __near * COleIPFrameWndEx::GetPane(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall COleIPFrameWndEx::GetPane(COleIPFrameWndEx *this, unsigned int nID)
{
  return this->m_dockManager.FindPaneByID(this: &this->m_dockManager, a2: nID, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A830B
// Name: protected: int COleIPFrameWndEx::OnPaneCheck(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnPaneCheck(COleIPFrameWndEx *this, unsigned int nID)
{
  CBasePane *Pane; // eax
  CBasePane *v3; // esi
  unsigned int Style; // eax

  Pane = COleIPFrameWndEx::GetPane(this, nID);
  v3 = Pane;
  if ( Pane == nullptr )
    return 0;
  Style = CWnd::GetStyle(this: Pane);
  v3->ShowPane(this: v3, a2: (Style & 0x10000000) == 0, a3: 0, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A8349
// Name: public: virtual void COleIPFrameWndEx::OnSetPreviewMode(int,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::OnSetPreviewMode(
        COleIPFrameWndEx *this,
        HWND__ *bPreview,
        CPrintPreviewState *pState)
{
  unsigned int dwStates; // ebx

  CDockingManager::SetPrintPreviewMode(this: &this->m_dockManager, (int)bPreview, __formal: pState);
  dwStates = pState->dwStates;
  CFrameWnd::OnSetPreviewMode(this, bPreview, pState);
  pState->dwStates = dwStates;
  this->RecalcLayout(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A8389
// Name: public: virtual void COleIPFrameWndEx::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::RecalcLayout(COleIPFrameWndEx *this, CView *bNotify)
{
  CDockingManager_vtbl *v3; // eax
  CView *ActiveView; // ecx
  CView *pView; // [esp+20h] [ebp+8h]

  COleIPFrameWnd::RecalcLayout(this, __formal: (int)bNotify);
  if ( this->m_bInRecalcLayout == 0 )
  {
    v3 = this->m_dockManager.__vftable;
    this->m_bInRecalcLayout = 1;
    v3->AdjustDockingLayout(this: &this->m_dockManager, a2: nullptr);
    this->m_dockManager.RecalcLayout(this: &this->m_dockManager, a2: (int)bNotify);
    ActiveView = CFrameWnd::GetActiveView(this);
    pView = ActiveView;
    if ( ActiveView != nullptr
      && CObject::IsKindOf(this: ActiveView, pClass: &CPreviewViewEx::classCPreviewViewEx) != 0
      && this->m_dockManager.m_bIsPrintPreviewMode != 0 )
    {
      CWnd::SetWindowPos(
        this: pView,
        pWndInsertAfter: nullptr,
        x: this->m_dockManager.m_rectClientAreaBounds.left,
        y: this->m_dockManager.m_rectClientAreaBounds.top,
        cx: this->m_dockManager.m_rectClientAreaBounds.right - this->m_dockManager.m_rectClientAreaBounds.left,
        cy: this->m_dockManager.m_rectClientAreaBounds.bottom - this->m_dockManager.m_rectClientAreaBounds.top,
        nFlags: 0x14u);
    }
    this->m_bInRecalcLayout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8439
// Name: protected: long COleIPFrameWndEx::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnIdleUpdateCmdUI(
        COleIPFrameWndEx *this,
        unsigned int __formal,
        unsigned int __formala)
{
  COleCntrFrameWndEx *v4; // eax

  COleIPFrameWnd::OnIdleUpdateCmdUI(this);
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  v4 = (COleCntrFrameWndEx *)AfxDynamicDownCast(
                               pClass: &COleCntrFrameWndEx::classCOleCntrFrameWndEx,
                               pObject: this->m_pMainFrame);
  if ( v4 != nullptr )
    COleCntrFrameWndEx::OnIdleUpdateCmdUI(this: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A847A
// Name: protected: virtual int COleDocIPFrameWndEx::OnCreateControlBars(class CFrameWnd __near *,class CFrameWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnCreateControlBars(
        COleDocIPFrameWndEx *this,
        CFrameWnd *pWndFrame,
        CFrameWnd *pWndDoc)
{
  COleCntrFrameWndEx *v4; // edi
  COleCntrFrameWndEx *v5; // ecx
  HWND__ *v6; // eax
  COleCntrFrameWnd *m_pMainFrame; // ecx
  HWND__ *v8; // ebx

  v4 = nullptr;
  if ( AfxDynamicDownCast(pClass: &COleCntrFrameWndEx::classCOleCntrFrameWndEx, pObject: pWndFrame) == nullptr )
  {
    v5 = (COleCntrFrameWndEx *)operator new(nSize: 0x304u);
    if ( v5 != nullptr )
      v4 = COleCntrFrameWndEx::COleCntrFrameWndEx(this: v5, pInPlaceFrame: this);
    v6 = CWnd::Detach(this: this->m_pMainFrame);
    m_pMainFrame = this->m_pMainFrame;
    v8 = v6;
    if ( m_pMainFrame != nullptr )
      ((void (__thiscall *)(COleCntrFrameWnd *, int))m_pMainFrame->dtr_CObject)(a1: m_pMainFrame, a2: 1);
    this->m_pMainFrame = v4;
    CWnd::Attach(this: v4, hWndNew: v8);
    CDockingManager::Create(this: &v4->m_dockManager, pParentWnd: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A8503
// Name: public: virtual int COleIPFrameWndEx::OnShowPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnShowPanes(COleIPFrameWndEx *this, int bShow)
{
  int v3; // edi

  v3 = this->m_dockManager.ShowPanes(this: &this->m_dockManager, a2: bShow);
  this->AdjustDockingLayout(this, a2: nullptr);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103A8530
// Name: public: virtual int COleIPFrameWndEx::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::OnCmdMsg(
        COleIPFrameWndEx *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  if ( CFrameWnd::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) )
    return 1;
  else
    return CDockingManager::ProcessPaneContextMenuCommand(
             this: &this->m_dockManager,
             nID,
             nCode,
             pExtra,
             __formal: pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x103A856E
// Name: public: static class CObject __near * COleIPFrameWndEx::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleIPFrameWndEx *__stdcall COleIPFrameWndEx::CreateObject()
{
  COleIPFrameWndEx *v0; // ecx
  COleIPFrameWndEx *result; // eax

  v0 = (COleIPFrameWndEx *)operator new(nSize: 0x48Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return COleIPFrameWndEx::COleIPFrameWndEx(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A85BF
// Name: public: virtual int COleIPFrameWndEx::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleIPFrameWndEx::PreTranslateMessage(COleIPFrameWndEx *this, CWnd *pMsg)
{
  unsigned int m_dwRef; // eax
  int v5; // eax
  CWnd *v7; // eax
  tagPOINT v8; // [esp-Ch] [ebp-20h]
  HWND__ *v9; // [esp-4h] [ebp-18h]
  HWND__ *v10; // [esp-4h] [ebp-18h]
  CPoint pt; // [esp+Ch] [ebp-8h] BYREF
  CWnd *pWnd; // [esp+1Ch] [ebp+8h]

  m_dwRef = pMsg->m_dwRef;
  if ( m_dwRef > 0x100 )
  {
    if ( m_dwRef != 512 )
    {
      if ( m_dwRef == 513 || m_dwRef - 515 <= 6 )
      {
        v9 = (HWND__ *)pMsg->__vftable;
        pt.x = SLOWORD(pMsg->m_xInnerUnknown);
        pt.y = SHIWORD(pMsg->m_xInnerUnknown);
        pWnd = CWnd::FromHandle(hWnd: v9);
        if ( pWnd != nullptr && IsWindow(hWnd: (HWND)pMsg->__vftable) )
          ClientToScreen(hWnd: pWnd->m_hWnd, lpPoint: &pt);
        if ( CFrameImpl::ProcessMouseClick(
               this: &this->m_Impl,
               uiMsg: pMsg->m_dwRef,
               pt: pt.tagPOINT,
               hwnd: (HWND__ *)pMsg->__vftable) != 0
          || !IsWindow(hWnd: (HWND)pMsg->__vftable) )
        {
          return 1;
        }
      }
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    }
    v10 = (HWND__ *)pMsg->__vftable;
    pt.x = SLOWORD(pMsg->m_xInnerUnknown);
    pt.y = SHIWORD(pMsg->m_xInnerUnknown);
    v7 = CWnd::FromHandle(hWnd: v10);
    if ( v7 != nullptr )
      ClientToScreen(hWnd: v7->m_hWnd, lpPoint: &pt);
    v5 = CFrameImpl::ProcessMouseMove(this: &this->m_Impl, pt: pt.tagPOINT);
  }
  else if ( m_dwRef == 256 )
  {
    if ( CFrameImpl::IsHelpKey(lpMsg: (tagMSG *)pMsg) != 0 )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    v5 = CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: (int)pMsg->m_pOuterUnknown, pbProcessAccel: nullptr);
  }
  else
  {
    if ( m_dwRef < 0xA1 || m_dwRef > 0xA2 && (m_dwRef <= 0xA3 || m_dwRef > 0xA5 && m_dwRef - 167 > 1) )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    v8.y = SHIWORD(pMsg->m_xInnerUnknown);
    v8.x = SLOWORD(pMsg->m_xInnerUnknown);
    v5 = CFrameImpl::ProcessMouseClick(this: &this->m_Impl, uiMsg: m_dwRef, pt: v8, hwnd: (HWND__ *)pMsg->__vftable);
  }
  if ( v5 != 0 )
    return 1;
  return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103A870E
// Name: protected: void COleIPFrameWndEx::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::OnActivate(
        COleIPFrameWndEx *this,
        unsigned int nState,
        CFrameWnd *pWndOther,
        int bMinimized)
{
  HWND__ *v5; // eax
  CWnd *v6; // eax

  CFrameWnd::OnActivate(this, nState, pWndOther, bMinimized);
  if ( nState != 0 )
  {
    if ( nState == 2 )
    {
      UpdateWindow(hWnd: this->m_hWnd);
LABEL_4:
      if ( g_pTopLevelFrame != nullptr )
        v5 = *((HWND__ **)g_pTopLevelFrame + 8);
      else
        v5 = nullptr;
      this->m_hwndLastTopLevelFrame = v5;
      g_pTopLevelFrame = (HWND)this;
      return;
    }
  }
  else
  {
    if ( CMFCToolBar::m_bCustomizeMode == 0 )
      CFrameImpl::DeactivateMenu(this: &this->m_Impl);
    if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr )
      goto LABEL_11;
    SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
  }
  if ( nState != 0 )
    goto LABEL_4;
LABEL_11:
  if ( g_pTopLevelFrame == (HWND)this )
  {
    v6 = CWnd::FromHandlePermanent(hWnd: this->m_hwndLastTopLevelFrame);
    g_pTopLevelFrame = (HWND)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A87B2
// Name: public: virtual void COleIPFrameWndEx::AdjustDockingLayout(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::AdjustDockingLayout(COleIPFrameWndEx *this, void *hdwp)
{
  HWND i; // eax
  CWnd *v4; // eax

  for ( i = GetWindow(hWnd: this->m_hWnd, uCmd: 5u); ; i = GetWindow(hWnd: this->m_hWnd, uCmd: 2u) )
  {
    v4 = CWnd::FromHandle(hWnd: i);
    if ( v4 == nullptr || CObject::IsKindOf(this: v4, pClass: &CBasePane::classCBasePane) == 0 )
      break;
  }
  this->m_dockManager.AdjustDockingLayout(this: &this->m_dockManager, a2: hdwp);
}

//------------------------------------------------------------------------------
// Address: 0x103A87F4
// Name: protected: void COleIPFrameWndEx::OnUpdatePaneMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::OnUpdatePaneMenu(COleIPFrameWndEx *this, CCmdUI *pCmdUI)
{
  CBasePane *Pane; // eax
  CCmdUI_vtbl *v3; // edi
  unsigned int Style; // eax

  Pane = COleIPFrameWndEx::GetPane(this, nID: pCmdUI->m_nID);
  if ( Pane != nullptr )
  {
    v3 = pCmdUI->__vftable;
    Style = CWnd::GetStyle(this: Pane);
    v3->SetCheck(this: pCmdUI, a2: (Style & 0x10000000) != 0);
  }
  else
  {
    pCmdUI->m_bContinueRouting = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A882E
// Name: protected: void COleIPFrameWndEx::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleIPFrameWndEx::OnDestroy(COleIPFrameWndEx *this)
{
  CWnd *v2; // eax
  HWND i; // eax
  CWnd *v4; // eax
  CWnd *v5; // esi
  CList<HWND__ *,HWND__ *>::CNode *m_pNodeHead; // esi
  HWND data; // ebx
  HWND__ *m_hWnd; // [esp-4h] [ebp-3Ch]
  CList<HWND__ *,HWND__ *> lstChildren; // [esp+10h] [ebp-28h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
    SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
  if ( g_pTopLevelFrame == (HWND)this )
  {
    v2 = CWnd::FromHandlePermanent(hWnd: this->m_hwndLastTopLevelFrame);
    g_pTopLevelFrame = (HWND)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v2);
  }
  CFrameImpl::DeactivateMenu(this: &this->m_Impl);
  if ( this->m_hAccelTable != nullptr )
  {
    DestroyAcceleratorTable(hAccel: this->m_hAccelTable);
    this->m_hAccelTable = nullptr;
  }
  this->m_dockManager.m_bEnableAdjustLayout = 0;
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  memset(&lstChildren.m_pNodeHead, 0, 20);
  lstChildren.m_nBlockSize = 10;
  m_hWnd = this->m_hWnd;
  v10 = 0;
  for ( i = GetTopWindow(hWnd: m_hWnd); ; i = GetWindow(hWnd: v5->m_hWnd, uCmd: 2u) )
  {
    v4 = CWnd::FromHandle(hWnd: i);
    v5 = v4;
    if ( v4 == nullptr )
      break;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&lstChildren,
      newElement: (CFrameWnd *)v4->m_hWnd);
  }
  m_pNodeHead = lstChildren.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( IsWindow(hWnd: data) && GetParent(hWnd: data) == this->m_hWnd )
      DestroyWindow(hWnd: data);
  }
  COleIPFrameWnd::OnDestroy(this);
  v10 = -1;
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&lstChildren);
}

//------------------------------------------------------------------------------
// Address: 0x103A893D
// Name: protected: virtual struct AFX_MSGMAP const __near * COleIPFrameWndEx::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COleIPFrameWndEx::GetMessageMap(COleIPFrameWndEx *this)
{
  return (const AFX_MSGMAP *)&off_10680FB0;
}

//------------------------------------------------------------------------------
// Address: 0x103A8943
// Name: public: virtual struct CRuntimeClass __near * CFrameWndEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFrameWndEx::GetRuntimeClass(CFrameWndEx *this)
{
  return &CFrameWndEx::classCFrameWndEx;
}

//------------------------------------------------------------------------------
// Address: 0x103A8949
// Name: protected: CFrameWndEx::CFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWndEx *__thiscall CFrameWndEx::CFrameWndEx(CFrameWndEx *this)
{
  CFrameWnd::CFrameWnd(this);
  this->__vftable = (CFrameWndEx_vtbl *)&CFrameWndEx::`vftable';
  this->m_bContextHelp = 0;
  this->m_bWasMaximized = 0;
  this->m_bIsMinimized = 0;
  CFrameImpl::CFrameImpl(this: &this->m_Impl, pFrame: this);
  CDockingManager::CDockingManager(this: &this->m_dockManager);
  this->m_pPrintPreviewFrame = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A89A5
// Name: public: virtual int CFrameWndEx::OnShowCustomizePane(class CMFCPopupMenu __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnShowCustomizePane(CFrameWndEx *this, CMFCPopupMenu *pMenuPane, unsigned int uiToolbarID)
{
  CFrameImpl::AddDefaultButtonsToCustomizePane(this: &this->m_Impl, pMenuPane, __formal: uiToolbarID);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A89C2
// Name: protected: long CMFCToolBar::OnNcHitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnNcHitTest(CMFCBaseTabCtrl *this, int __formal, CWnd *pWndFrame)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A89C8
// Name: protected: virtual CFrameWndEx::~CFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::~CFrameWndEx(CFrameWndEx *this)
{
  this->__vftable = (CFrameWndEx_vtbl *)&CFrameWndEx::`vftable';
  CDockingManager::~CDockingManager(this: &this->m_dockManager);
  CFrameImpl::~CFrameImpl(this: &this->m_Impl);
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A8A11
// Name: public: long CFrameWndEx::OnMenuChar(unsigned int,unsigned int,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnMenuChar(CFrameWndEx *this, unsigned int nChar, unsigned int nFlags, CMenu *pMenu)
{
  if ( CFrameImpl::OnMenuChar(this: &this->m_Impl, nChar) != 0 )
    return -65534;
  else
    return CFrameWnd::OnMenuChar(this, nChar, nFlags, pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x103A8A47
// Name: protected: int CFrameWndEx::ShowPopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::ShowPopupMenu(CFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  int result; // eax

  result = CFrameImpl::OnShowPopupMenu(this: &this->m_Impl, pMenuPopup, __formal: this);
  if ( result != 0 )
  {
    if ( pMenuPopup != nullptr && pMenuPopup->m_bShown != 0 )
      return 1;
    else
      return this->OnShowPopupMenu(this, a2: pMenuPopup);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A8A87
// Name: public: virtual int CFrameWndEx::OnDrawMenuImage(class CDC __near *,class CMFCToolBarMenuButton const __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnDrawMenuImage(
        CFrameWndEx *this,
        CDC *pDC,
        const CMFCToolBarMenuButton *pMenuButton,
        const CRect *rectImage)
{
  CMFCRibbonBar *m_pRibbonBar; // ecx

  m_pRibbonBar = this->m_Impl.m_pRibbonBar;
  if ( m_pRibbonBar != nullptr )
    return CMFCRibbonBar::DrawMenuImage(this: m_pRibbonBar, pDC, pMenuItem: pMenuButton, rectImage);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A8AA2
// Name: protected: virtual int CFrameWndEx::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnCommand(CFrameWndEx *this, unsigned int wParam, int lParam)
{
  if ( HIWORD(wParam) == 1 )
  {
    CMFCToolBar::AddCommandUsage(uiCommand: (unsigned __int16)wParam);
    if ( CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: 27, pbProcessAccel: nullptr) != 0
      || afxUserToolsManager != nullptr
      && CUserToolsManager::InvokeTool(this: afxUserToolsManager, uiCmdId: (unsigned __int16)wParam) != 0 )
    {
      return 1;
    }
  }
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
    return 0;
  return CFrameWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103A8B0D
// Name: public: virtual int CFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::LoadFrame(
        CFrameWndEx *this,
        const char *nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  int result; // eax

  this->m_Impl.m_nIDDefaultResource = (unsigned int)nIDResource;
  CFrameImpl::LoadLargeIconsState(this: &this->m_Impl);
  result = CFrameWnd::LoadFrame(this, nIDResource, dwDefaultStyle, pParentWnd, pContext);
  if ( result != 0 )
  {
    CFrameImpl::OnLoadFrame(this: &this->m_Impl);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A8B55
// Name: protected: virtual int CFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::PreCreateWindow(CFrameWndEx *this, tagCREATESTRUCTA *cs)
{
  CDockingManager *p_m_dockManager; // edi

  p_m_dockManager = &this->m_dockManager;
  CDockingManager::Create(this: &this->m_dockManager, pParentWnd: this);
  this->m_Impl.m_pDockManager = p_m_dockManager;
  CFrameImpl::RestorePosition(this: &this->m_Impl, cs);
  return CFrameWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x103A8B90
// Name: public: void CFrameWndEx::OnContextHelp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnContextHelp(CFrameWndEx *this)
{
  bool v2; // zf

  v2 = this->m_bHelpMode == 0;
  this->m_bContextHelp = 1;
  if ( v2 && CFrameWnd::CanEnterHelpMode(this) != 0 )
    CMFCToolBar::SetHelpMode(bOn: 1);
  CFrameWnd::OnContextHelp(this);
  if ( this->m_bHelpMode == 0 )
    CMFCToolBar::SetHelpMode(bOn: 0);
  this->m_bContextHelp = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A8BD8
// Name: public: long CFrameWndEx::OnToolbarCreateNew(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CMFCToolBar *__thiscall CFrameWndEx::OnToolbarCreateNew(CFrameWndEx *this, unsigned int __formal, const char *lp)
{
  if ( lp == nullptr )
    AfxThrowInvalidArgException();
  return CFrameImpl::CreateNewToolBar(this: &this->m_Impl, lpszName: lp);
}

//------------------------------------------------------------------------------
// Address: 0x103A8BFA
// Name: public: long CFrameWndEx::OnToolbarDelete(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnToolbarDelete(CFrameWndEx *this, unsigned int __formal, CMFCToolBar *lp)
{
  if ( lp == nullptr )
    AfxThrowInvalidArgException();
  return CFrameImpl::DeleteToolBar(this: &this->m_Impl, pToolBar: lp);
}

//------------------------------------------------------------------------------
// Address: 0x103A8C1C
// Name: public: void CFrameWndEx::OnActivateApp(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnActivateApp(CFrameWndEx *this, int bActive, unsigned int __formal)
{
  this->m_dockManager.OnActivateFrame(this: &this->m_dockManager, a2: bActive);
  CFrameImpl::OnActivateApp(this: &this->m_Impl, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x103A8C45
// Name: public: virtual void CFrameWndEx::DelayUpdateFrameMenu(struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::DelayUpdateFrameMenu(CFrameWndEx *this, HMENU__ *hMenuAlt)
{
  this->OnUpdateFrameMenu(this, a2: hMenuAlt);
  CFrameWnd::DelayUpdateFrameMenu(this, hMenuAlt);
}

//------------------------------------------------------------------------------
// Address: 0x103A8C67
// Name: public: virtual void CFrameWndEx::OnUpdateFrameMenu(struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnUpdateFrameMenu(CFrameWndEx *this, HMENU__ *hMenuAlt)
{
  CMFCMenuBar *m_pMenuBar; // ecx
  int v4; // ebx
  CMFCRibbonBar *m_pRibbonBar; // ecx
  COleClientItem *v6; // eax
  CFrameWndEx_vtbl *v7; // edi
  CMenu *v8; // eax
  int bIsMenuBar; // [esp+Ch] [ebp-4h]

  CFrameWnd::OnUpdateFrameMenu(this, hMenuAlt);
  m_pMenuBar = this->m_Impl.m_pMenuBar;
  v4 = 0;
  if ( m_pMenuBar == nullptr || (bIsMenuBar = 1, (CWnd::GetStyle(this: m_pMenuBar) & 0x10000000) == 0) )
    bIsMenuBar = 0;
  m_pRibbonBar = this->m_Impl.m_pRibbonBar;
  if ( m_pRibbonBar != nullptr && (CWnd::GetStyle(this: m_pRibbonBar) & 0x10000000) != 0 )
    v4 = 1;
  if ( bIsMenuBar != 0 || v4 != 0 )
  {
    v6 = this->GetInPlaceActiveItem(this);
    if ( v6 != nullptr && COleClientItem::GetInPlaceWindow(this: v6) != nullptr )
    {
      v7 = this->__vftable;
      v8 = CMenu::FromHandle(hMenu: hMenuAlt);
      v7->SetMenu(this, a2: v8);
    }
    else
    {
      this->SetMenu(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8CF9
// Name: public: int CFrameWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::AddPane(CFrameWndEx *this, CBasePane *pControlBar, int bTail)
{
  CMFCRibbonBar *v4; // edi
  CMFCRibbonStatusBar *v5; // eax

  v4 = (CMFCRibbonBar *)AfxDynamicDownCast(pClass: &CMFCRibbonBar::classCMFCRibbonBar, pObject: pControlBar);
  if ( v4 != nullptr && v4->IsMainRibbonBar(this: v4) != 0 )
    this->m_Impl.m_pRibbonBar = v4;
  v5 = (CMFCRibbonStatusBar *)AfxDynamicDownCast(
                                pClass: &CMFCRibbonStatusBar::classCMFCRibbonStatusBar,
                                pObject: pControlBar);
  if ( v5 != nullptr )
    this->m_Impl.m_pRibbonStatusBar = v5;
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A8D5F
// Name: public: int CFrameWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::InsertPane(CFrameWndEx *this, CBasePane *pControlBar, CBasePane *pTarget, int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x103A8D70
// Name: public: void CFrameWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::RemovePaneFromDockManager(
        CFrameWndEx *this,
        CBasePane *pControlBar,
        int bDestroy,
        int bAdjustLayout,
        int bAutoHide,
        CBasePane *pBarReplacement)
{
  CDockingManager::RemovePaneFromDockManager(
    this: &this->m_dockManager,
    pWnd: pControlBar,
    bDestroy,
    bAdjustLayout,
    bAutoHide,
    pBarReplacement);
}

//------------------------------------------------------------------------------
// Address: 0x103A8D81
// Name: public: void CFrameWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::DockPane(
        CFrameWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *lpRect)
{
  CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x103A8D92
// Name: public: class CBasePane __near * CFrameWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall CFrameWndEx::PaneFromPoint(
        CFrameWndEx *this,
        CPoint point,
        int nSensitivity,
        int bExactBar,
        CRuntimeClass *pRTCBarType)
{
  return ((CBasePane *(__thiscall *)(CDockingManager *, int, int, int, int, CRuntimeClass *, _DWORD, _DWORD))this->m_dockManager.PaneFromPoint_2)(
           a1: &this->m_dockManager,
           a2: point.x,
           a3: point.y,
           a4: nSensitivity,
           a5: bExactBar,
           a6: pRTCBarType,
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A8DB9
// Name: public: int CFrameWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::IsPointNearDockSite(
        CFrameWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x103A8DD9
// Name: protected: virtual void CFrameWndEx::AdjustClientArea(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::AdjustClientArea(CFrameWndEx *this)
{
  CWnd *DlgItem; // eax
  int left; // ecx
  CWnd_vtbl *v4; // edx
  CWnd *pChildWnd; // [esp+4h] [ebp-18h]
  CRect rectClientAreaBounds; // [esp+8h] [ebp-14h] BYREF

  DlgItem = CWnd::GetDlgItem(this, nID: 59648);
  pChildWnd = DlgItem;
  if ( DlgItem != nullptr )
  {
    left = this->m_rectBorder.left;
    v4 = DlgItem->__vftable;
    rectClientAreaBounds = this->m_dockManager.m_rectClientAreaBounds;
    rectClientAreaBounds.left += left;
    rectClientAreaBounds.top += this->m_rectBorder.top;
    rectClientAreaBounds.right -= this->m_rectBorder.right;
    rectClientAreaBounds.bottom -= this->m_rectBorder.bottom;
    v4->CalcWindowRect(this: DlgItem, a2: &rectClientAreaBounds, a3: 0);
    if ( CObject::IsKindOf(this: pChildWnd, pClass: &CSplitterWnd::classCSplitterWnd) != 0
      || CObject::IsKindOf(this: pChildWnd, pClass: &CFormView::classCFormView) != 0 )
    {
      CWnd::ModifyStyle(this: pChildWnd, dwRemove: 0, dwAdd: 0x4000000u, nFlags: 0);
    }
    else
    {
      CWnd::ModifyStyle(this: pChildWnd, dwRemove: 0, dwAdd: 0x6000000u, nFlags: 0);
    }
    CWnd::SetWindowPos(
      this: pChildWnd,
      pWndInsertAfter: &CWnd::wndBottom,
      x: rectClientAreaBounds.left,
      y: rectClientAreaBounds.top,
      cx: rectClientAreaBounds.right - rectClientAreaBounds.left,
      cy: rectClientAreaBounds.bottom - rectClientAreaBounds.top,
      nFlags: 0x10u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8EAF
// Name: public: virtual int CFrameWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnMoveMiniFrame(CFrameWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x103A8EC0
// Name: public: class CBasePane __near * CFrameWndEx::GetPane(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall CFrameWndEx::GetPane(CFrameWndEx *this, unsigned int nID)
{
  return this->m_dockManager.FindPaneByID(this: &this->m_dockManager, a2: nID, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A8ED9
// Name: public: void CMDIFrameWndEx::ShowPane(class CBasePane __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::ShowPane(CFrameWndEx *this, CBasePane *pBar, int bShow, int bDelay, int bActivate)
{
  pBar->ShowPane(this: pBar, a2: bShow, a3: bDelay, a4: bActivate);
}

//------------------------------------------------------------------------------
// Address: 0x103A8EF6
// Name: public: int CFrameWndEx::OnPaneCheck(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnPaneCheck(CFrameWndEx *this, unsigned int nID)
{
  CBasePane *Pane; // eax
  CBasePane *v3; // esi
  unsigned int Style; // eax

  Pane = CFrameWndEx::GetPane(this, nID);
  v3 = Pane;
  if ( Pane == nullptr )
    return 0;
  Style = CWnd::GetStyle(this: Pane);
  v3->ShowPane(this: v3, a2: (Style & 0x10000000) == 0, a3: 0, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A8F34
// Name: public: void CFrameWndEx::ActiveItemRecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::ActiveItemRecalcLayout(CFrameWndEx *this)
{
  COleClientItem *v2; // eax

  v2 = this->GetInPlaceActiveItem(this);
  if ( v2 != nullptr && v2->m_pInPlaceFrame != nullptr )
    v2->m_pInPlaceFrame->OnRecalcLayout(this: v2->m_pInPlaceFrame);
  this->AdjustClientArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A8F60
// Name: public: virtual int CFrameWndEx::NegotiateBorderSpace(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::NegotiateBorderSpace(CFrameWndEx *this, unsigned int nBorderCmd, tagRECT *lpRectBorder)
{
  CRect *p_m_rectClientAreaBounds; // esi
  int *p_top; // esi
  tagRECT rectBounds; // 0:^10.16

  if ( nBorderCmd == 1 )
  {
    CFrameWnd::NegotiateBorderSpace(this, nBorderCmd: 1u, lpRectBorder);
    p_m_rectClientAreaBounds = &this->m_dockManager.m_rectClientAreaBounds;
    rectBounds.left = p_m_rectClientAreaBounds->left;
    p_m_rectClientAreaBounds = (CRect *)((char *)p_m_rectClientAreaBounds + 4);
    rectBounds.top = p_m_rectClientAreaBounds->left;
    p_top = &p_m_rectClientAreaBounds->top;
    if ( lpRectBorder == nullptr )
      AfxThrowInvalidArgException();
    rectBounds.right = *p_top;
    rectBounds.bottom = p_top[1];
    *lpRectBorder = rectBounds;
  }
  else if ( nBorderCmd == 3 )
  {
    return CFrameWnd::NegotiateBorderSpace(this, nBorderCmd: 3u, lpRectBorder);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A8FB9
// Name: public: virtual int CFrameWndEx::OnShowPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnShowPanes(CFrameWndEx *this, int bShow)
{
  int v3; // edi

  v3 = this->m_dockManager.ShowPanes(this: &this->m_dockManager, a2: bShow);
  this->AdjustDockingLayout(this, a2: nullptr);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103A8FE6
// Name: public: long CFrameWndEx::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnIdleUpdateCmdUI(CFrameWndEx *this, unsigned int __formal, unsigned int __formala)
{
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A8FFF
// Name: public: long CFrameWndEx::OnExitSizeMove(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnExitSizeMove(CFrameWndEx *this, unsigned int __formal, unsigned int __formala)
{
  this->RecalcLayout(this, a2: 1);
  this->m_dockManager.FixupVirtualRects(this: &this->m_dockManager);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A901F
// Name: public: virtual int CFrameWndEx::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnCmdMsg(
        CFrameWndEx *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  if ( CFrameWnd::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) )
    return 1;
  else
    return CDockingManager::ProcessPaneContextMenuCommand(
             this: &this->m_dockManager,
             nID,
             nCode,
             pExtra,
             __formal: pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x103A95E2
// Name: public: void CFrameWndEx::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnActivate(CFrameWndEx *this, unsigned int nState, CFrameWnd *pWndOther, int bMinimized)
{
  CFrameWnd::OnActivate(this, nState, pWndOther, bMinimized);
  if ( nState != 0 )
  {
    if ( nState == 2 )
      UpdateWindow(hWnd: this->m_hWnd);
  }
  else if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    CFrameImpl::DeactivateMenu(this: &this->m_Impl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9628
// Name: public: virtual void CFrameWndEx::AdjustDockingLayout(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::AdjustDockingLayout(CFrameWndEx *this, void *hdwp)
{
  if ( this->m_dockManager.m_bAdjustingBarLayout == 0 )
  {
    this->m_dockManager.AdjustDockingLayout(this: &this->m_dockManager, a2: hdwp);
    this->AdjustClientArea(this);
    if ( CDockingManager::IsOLEContainerMode(this: &this->m_dockManager) != 0 )
      this->RecalcLayout(this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9677
// Name: public: void CFrameWndEx::OnUpdatePaneMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnUpdatePaneMenu(CFrameWndEx *this, CCmdUI *pCmdUI)
{
  CBasePane *Pane; // eax
  CCmdUI_vtbl *v3; // edi
  unsigned int Style; // eax

  Pane = CFrameWndEx::GetPane(this, nID: pCmdUI->m_nID);
  if ( Pane != nullptr )
  {
    v3 = pCmdUI->__vftable;
    Style = CWnd::GetStyle(this: Pane);
    v3->SetCheck(this: pCmdUI, a2: (Style & 0x10000000) != 0);
  }
  else
  {
    pCmdUI->m_bContinueRouting = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A96B1
// Name: public: void CFrameWndEx::OnSizing(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnSizing(CFrameWndEx *this, unsigned int fwSide, tagRECT *pRect)
{
  CWnd::Default(this);
  this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103A96CB
// Name: public: virtual void CFrameWndEx::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::RecalcLayout(CFrameWndEx *this, int bNotify)
{
  CFrameWndEx_vtbl *v3; // eax
  int v4; // eax
  CView *ActiveView; // eax
  int m_bIsOleInPlaceActive; // eax
  int bWasOleInPlaceActive; // [esp+18h] [ebp-8h]
  CView *pView; // [esp+1Ch] [ebp-4h]

  if ( this->m_bInRecalcLayout != 0 )
    return;
  bWasOleInPlaceActive = this->m_Impl.m_bIsOleInPlaceActive;
  v3 = this->__vftable;
  this->m_bInRecalcLayout = 1;
  this->m_Impl.m_bIsOleInPlaceActive = 0;
  v4 = ((int (*)(void))v3->GetInPlaceActiveItem)();
  if ( v4 != 0 && *(_DWORD *)(v4 + 96) != 0 && *(_DWORD *)(v4 + 80) == 4 )
  {
    this->m_Impl.m_bIsOleInPlaceActive = 1;
    this->m_Impl.m_bHadCaption = (CWnd::GetStyle(this) & 0xC00000) != 0;
  }
  if ( this->m_bIsMinimized == 0 )
  {
    ActiveView = CFrameWnd::GetActiveView(this);
    pView = ActiveView;
    if ( this->m_dockManager.m_bIsPrintPreviewMode != 0 || this->m_pNotifyHook != nullptr )
    {
      if ( ActiveView != nullptr
        && CObject::IsKindOf(this: ActiveView, pClass: &CPreviewViewEx::classCPreviewViewEx) != 0 )
      {
        this->m_dockManager.RecalcLayout(this: &this->m_dockManager, a2: bNotify);
        CWnd::SetWindowPos(
          this: pView,
          pWndInsertAfter: nullptr,
          x: this->m_dockManager.m_rectClientAreaBounds.left,
          y: this->m_dockManager.m_rectClientAreaBounds.top,
          cx: this->m_dockManager.m_rectClientAreaBounds.right - this->m_dockManager.m_rectClientAreaBounds.left,
          cy: this->m_dockManager.m_rectClientAreaBounds.bottom - this->m_dockManager.m_rectClientAreaBounds.top,
          nFlags: 0x14u);
        goto LABEL_18;
      }
      if ( bNotify != 0 && this->m_pNotifyHook != nullptr )
      {
        CFrameWndEx::ActiveItemRecalcLayout(this);
        goto LABEL_18;
      }
      this->m_bInRecalcLayout = 0;
      CFrameWnd::RecalcLayout(this, bNotify);
    }
    else
    {
      this->m_dockManager.RecalcLayout(this: &this->m_dockManager, a2: bNotify);
    }
    this->AdjustClientArea(this);
  }
LABEL_18:
  m_bIsOleInPlaceActive = this->m_Impl.m_bIsOleInPlaceActive;
  this->m_bInRecalcLayout = 0;
  if ( bWasOleInPlaceActive != m_bIsOleInPlaceActive )
  {
    if ( this->m_Impl.m_bHadCaption == 0 )
    {
      if ( m_bIsOleInPlaceActive != 0 )
        CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0xC00000u, nFlags: 0);
      else
        CWnd::ModifyStyle(this, dwRemove: 0xC00000u, dwAdd: 0, nFlags: 0);
    }
    CFrameImpl::OnChangeVisualManager(this: &this->m_Impl);
    CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: -1, cy: -1, nFlags: 0x37u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9842
// Name: public: virtual void CFrameWndEx::OnSetPreviewMode(int,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnSetPreviewMode(CFrameWndEx *this, HWND__ *bPreview, CPrintPreviewState *pState)
{
  CFrameWnd *TopLevelFrame; // eax
  CObject *v5; // eax
  unsigned int dwStates; // ebx
  CMFCRibbonBar *m_pRibbonBar; // eax

  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v5 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: TopLevelFrame);
  if ( v5 != nullptr )
    v5[262].__vftable = bPreview != nullptr ? (CObject_vtbl *)this : nullptr;
  CDockingManager::SetPrintPreviewMode(this: &this->m_dockManager, (int)bPreview, __formal: pState);
  dwStates = pState->dwStates;
  CFrameWnd::OnSetPreviewMode(this, bPreview, pState);
  pState->dwStates = dwStates;
  this->AdjustDockingLayout(this, a2: nullptr);
  this->RecalcLayout(this, a2: 1);
  m_pRibbonBar = this->m_Impl.m_pRibbonBar;
  if ( m_pRibbonBar != nullptr && m_pRibbonBar->m_bReplaceFrameCaption != 0 )
    PostMessageA(hWnd: this->m_hWnd, Msg: AFX_WM_POSTSETPREVIEWFRAME, wParam: (WPARAM)bPreview, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A98E2
// Name: public: void CFrameWndEx::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnSize(CFrameWndEx *this, unsigned int nType, int cx, int cy)
{
  CFrameImpl *p_m_Impl; // ebx
  HWND__ *m_hWnd; // [esp-8h] [ebp-44h]
  tagWINDOWPOS wndpos; // [esp+Ch] [ebp-30h] BYREF
  CRect rectWindow; // [esp+28h] [ebp-14h] BYREF

  this->m_bIsMinimized = nType == 1;
  if ( this->m_Impl.m_pRibbonBar != nullptr
    || (p_m_Impl = &this->m_Impl, CFrameImpl::IsOwnerDrawCaption(this: &this->m_Impl) != 0) )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectWindow, 0, sizeof(rectWindow));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectWindow);
    wndpos.x = rectWindow.left;
    wndpos.cy = rectWindow.bottom - rectWindow.top;
    wndpos.y = rectWindow.top;
    p_m_Impl = &this->m_Impl;
    wndpos.flags = 32;
    wndpos.cx = rectWindow.right - rectWindow.left;
    CFrameImpl::OnWindowPosChanging(this: &this->m_Impl, lpwndpos: &wndpos);
  }
  CFrameImpl::UpdateCaption(this: p_m_Impl);
  ((void (__stdcall *)(bool))this->m_dockManager.OnActivateFrame)(a1: this->m_bIsMinimized == 0);
  if ( this->m_bIsMinimized != 0 || nType == 2 || this->m_bWasMaximized != 0 )
  {
    CFrameWnd::OnSize(this, nType, cx, cy);
    if ( nType == 2 || nType == 0 && this->m_bWasMaximized != 0 )
      this->RecalcLayout(this, a2: 1);
    this->m_bWasMaximized = nType == 2;
  }
  else
  {
    this->m_dockManager.m_bSizeFrame = 1;
    CFrameWnd::OnSize(this, nType, cx, cy);
    this->AdjustDockingLayout(this, a2: nullptr);
    this->m_dockManager.m_bSizeFrame = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA2B6
// Name: public: virtual int CMFCToolBar::LoadToolBar(unsigned int,unsigned int,unsigned int,int,unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::LoadToolBar(
        CMFCToolBar *this,
        unsigned int uiResID,
        unsigned int uiColdResID,
        unsigned int uiMenuResID,
        int bLocked,
        unsigned int uiDisabledResID,
        unsigned int uiMenuDisabledResID,
        unsigned int uiHotResID)
{
  int v8; // edx
  CMFCToolBarInfo params; // [esp+0h] [ebp-20h] BYREF

  CMFCToolBarInfo::CMFCToolBarInfo(this: &params);
  params.m_uiColdResID = uiColdResID;
  params.m_uiHotResID = uiHotResID;
  params.m_uiDisabledResID = uiDisabledResID;
  params.m_uiMenuResID = uiMenuResID;
  params.m_uiMenuDisabledResID = uiMenuDisabledResID;
  return (*(int (__thiscall **)(int, unsigned int, CMFCToolBarInfo *, int))(*(_DWORD *)v8 + 824))(
           a1: v8,
           a2: uiResID,
           a3: &params,
           a4: bLocked);
}

//------------------------------------------------------------------------------
// Address: 0x103AA2FE
// Name: public: virtual int CMFCToolBar::InsertButton(class CMFCToolBarButton const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::InsertButton(CMFCToolBar *this, CMFCToolBarButton *button, int iInsertAt)
{
  CRuntimeClass *v4; // eax
  CObject *Object; // eax
  CMFCToolBarButton *v6; // esi
  int v7; // edi

  v4 = (CRuntimeClass *)button->GetRuntimeClass(this: button);
  if ( v4 == nullptr
    || (Object = CRuntimeClass::CreateObject(this: v4), v6 = (CMFCToolBarButton *)Object, Object == nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  Object->__vftable[1].Serialize(this: Object, a2: (CArchive *)button);
  v7 = this->InsertButton(this, a2: v6, a3: iInsertAt);
  if ( v7 < 0 )
    ((void (__thiscall *)(CMFCToolBarButton *, int))v6->dtr_CObject)(a1: v6, a2: 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x103AA355
// Name: public: virtual int CMFCToolBar::InsertSeparator(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::InsertSeparator(CMFCToolBar *this, int iInsertAt)
{
  CMFCToolBarButton *v3; // esi
  CMFCToolBarButton *v4; // ecx
  int v5; // edi

  v3 = nullptr;
  if ( this->m_Buttons.m_nCount == 0 || iInsertAt == 0 )
    return -1;
  v4 = (CMFCToolBarButton *)operator new(nSize: 0x70u);
  if ( v4 != nullptr )
    v3 = CMFCToolBarButton::CMFCToolBarButton(this: v4);
  v3->m_nStyle = 1;
  v5 = this->InsertButton(this, a2: v3, a3: iInsertAt);
  if ( v5 == -1 )
    ((void (__thiscall *)(CMFCToolBarButton *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103AA3C5
// Name: public: virtual void CMFCToolBar::RemoveAllButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::RemoveAllButtons(CMFCToolBar *this)
{
  CObject *v2; // edi

  this->m_iButtonCapture = -1;
  this->m_iHighlighted = -1;
  this->m_iSelected = -1;
  while ( this->m_Buttons.m_nCount != 0 )
  {
    v2 = CObList::RemoveHead(this: &this->m_Buttons);
    if ( v2 != nullptr )
    {
      v2->__vftable[7].dtr_CObject(this: v2);
      ((void (__thiscall *)(CObject *, int))v2->dtr_CObject)(a1: v2, a2: 1);
    }
  }
  this->m_pCustomizeBtn = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AA41F
// Name: public: int CMFCToolBar::CommandToIndex(unsigned int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::CommandToIndex(CMFCToolBar *this, CObject_vtbl *nIDFind, int iIndexFirst)
{
  CObList::CNode *m_pNodeHead; // ecx
  int result; // eax
  CObject *data; // edx

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  result = 0;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    if ( result >= iIndexFirst && data[8].__vftable == nIDFind )
      return result;
    ++result;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103AA45C
// Name: public: int CMFCToolBar::ButtonToIndex(class CMFCToolBarButton const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::ButtonToIndex(CMFCToolBar *this, const CMFCToolBarButton *pButton)
{
  CObList::CNode *m_pNodeHead; // ecx
  int result; // eax
  const CMFCToolBarButton *data; // edx

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  result = 0;
  while ( m_pNodeHead != nullptr )
  {
    data = (const CMFCToolBarButton *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    if ( data == pButton )
      return result;
    ++result;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103AA491
// Name: public: virtual class CSize CMFCToolBar::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolBar::CalcFixedLayout(CMFCToolBar *this, CSize *result, int bStretch, int bHorz)
{
  this->CalcLayout(this, result, a3: (bHorz != 0 ? 2 : 0) | (bStretch != 0), a4: -1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AA4C1
// Name: public: int CMFCToolBar::IsButtonHighlighted(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::IsButtonHighlighted(CMFCToolBar *this, int iButton)
{
  int m_iButtonCapture; // ecx

  if ( CMFCToolBar::m_bCustomizeMode != 0 && this->m_bLocked == 0 )
    return false;
  if ( this->m_bMenuMode != 0 )
    return iButton == this->m_iHighlighted;
  return (iButton == this->m_iHighlighted || iButton == this->m_iButtonCapture)
      && ((m_iButtonCapture = this->m_iButtonCapture) == -1 || iButton == m_iButtonCapture);
}

//------------------------------------------------------------------------------
// Address: 0x103AA51D
// Name: protected: virtual int CMFCToolBar::DrawButton(class CDC __near *,class CMFCToolBarButton __near *,class CMFCToolBarImages __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::DrawButton(
        CMFCToolBar *this,
        CDC *pDC,
        CMFCToolBarButton *pButton,
        CMFCToolBarImages *pImages,
        int bHighlighted,
        int bDrawDisabledImages)
{
  BOOL v7; // eax
  int v8; // ecx
  BOOL v9; // edx

  if ( pButton->m_bVisible != 0 && pButton->m_bIsHidden == 0 && pDC->RectVisible(this: pDC, a2: &pButton->m_rect) != 0 )
  {
    v7 = (this->GetCurrentAlignment(this) & 0xA000) != 0;
    v8 = 1;
    v9 = this->m_bGrayDisabledButtons != 0 && bDrawDisabledImages == 0;
    if ( CMFCToolBar::m_bCustomizeMode == 0 || CMFCToolBar::m_bAltCustomizeMode != 0 || this->m_bLocked != 0 )
      v8 = 0;
    pButton->OnDraw(
      this: pButton,
      a2: pDC,
      a3: &pButton->m_rect,
      a4: pImages,
      a5: v7,
      a6: v8,
      a7: bHighlighted,
      a8: this->m_bShowHotBorder,
      a9: v9);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103E52B0
// Name: public: virtual int CMFCDropDownToolBar::LoadToolBar(unsigned int,unsigned int,unsigned int,int,unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCDropDownToolBar::LoadToolBar(
        CMFCDropDownToolBar *this,
        unsigned int uiResID,
        unsigned int uiColdResID,
        unsigned int uiMenuResID,
        int __formal,
        unsigned int uiDisabledResID,
        unsigned int uiMenuDisabledResID,
        unsigned int uiHotResID)
{
  return CMFCToolBar::LoadToolBar(
           this,
           uiResID,
           uiColdResID,
           uiMenuResID,
           bLocked: 1,
           uiDisabledResID,
           uiMenuDisabledResID,
           uiHotResID);
}

//------------------------------------------------------------------------------
// Address: 0x103E52F9
// Name: public: static class CObject __near * CMFCDropDownToolBar::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCDropDownToolBar *__stdcall CMFCDropDownToolBar::CreateObject()
{
  CMFCDropDownToolBar *v0; // ecx
  CMFCDropDownToolBar *result; // eax

  v0 = (CMFCDropDownToolBar *)operator new(nSize: 0xCC8u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCDropDownToolBar::CMFCDropDownToolBar(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E5329
// Name: public: virtual struct CRuntimeClass __near * CMFCDropDownToolBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCDropDownToolBar::GetRuntimeClass(CMFCDropDownToolBar *this)
{
  return &CMFCDropDownToolBar::classCMFCDropDownToolBar;
}

//------------------------------------------------------------------------------
// Address: 0x103F32E9
// Name: public: virtual CList<class CPropertyPage __near *,class CPropertyPage __near *>::~CList<class CPropertyPage __near *,class CPropertyPage __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<CPropertyPage *,CPropertyPage *>::~CList<CPropertyPage *,CPropertyPage *>(
        CList<CPropertyPage *,CPropertyPage *> *this)
{
  this->__vftable = (CList<CPropertyPage *,CPropertyPage *>_vtbl *)&CList<CPropertyPage *,CPropertyPage *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}
