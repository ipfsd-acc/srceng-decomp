// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/optbuild.cpp
// Functions: 20
// ============================================================

#include "hammer\optbuild.h"

//------------------------------------------------------------------------------
// Address: 0x100EC9F0
// Name: protected: void COPTBuild::SaveInfo(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::SaveInfo(COPTBuild *this, CGameConfig *pConfig)
{
  if ( pConfig != nullptr )
  {
    EditorUtil_TransferPath(pDlg: this, nIDC: 1011, szDest: this->m_pConfig->szBSP, bExpand: true);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1132, szDest: this->m_pConfig->szLIGHT, bExpand: true);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1133, szDest: this->m_pConfig->szVIS, bExpand: true);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1009, szDest: this->m_pConfig->szExecutable, bExpand: true);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1400, szDest: this->m_pConfig->szBSPDir, bExpand: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECA90
// Name: public: virtual int COPTBuild::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTBuild::OnApply(COPTBuild *this)
{
  COPTBuild::SaveInfo(this, pConfig: this->m_pConfig);
  return CPropertyPage::OnApply(this);
}

//------------------------------------------------------------------------------
// Address: 0x100ECAB0
// Name: public: COPTBuild::COPTBuild(void)
// Source: json
//------------------------------------------------------------------------------
COPTBuild *__thiscall COPTBuild::COPTBuild(COPTBuild *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x113u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COPTBuild_vtbl *)&COPTBuild::`vftable';
  CWnd::CWnd(this: &this->m_cBSPDir);
  this->m_cBSPDir.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cVIS);
  this->m_cVIS.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cLIGHT);
  this->m_cLIGHT.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cGame);
  this->m_cGame.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cBSP);
  this->m_cBSP.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cConfigs);
  this->m_cConfigs.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  this->m_pConfig = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100ECBD0
// Name: public: virtual COPTBuild::~COPTBuild(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::~COPTBuild(COPTBuild *this)
{
  CComboBox::~CComboBox(this: &this->m_cConfigs);
  CEdit::~CEdit(this: &this->m_cBSP);
  CEdit::~CEdit(this: &this->m_cGame);
  CEdit::~CEdit(this: &this->m_cLIGHT);
  CEdit::~CEdit(this: &this->m_cVIS);
  CEdit::~CEdit(this: &this->m_cBSPDir);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100ECCA0
// Name: protected: virtual void COPTBuild::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::DoDataExchange(COPTBuild *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x578, rControl: (HWND__ *)&this->m_cBSPDir);
  DDX_Control(pDX, nIDC: (HWND__ *)0x46D, rControl: (HWND__ *)&this->m_cVIS);
  DDX_Control(pDX, nIDC: (HWND__ *)0x46C, rControl: (HWND__ *)&this->m_cLIGHT);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_cGame);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F3, rControl: (HWND__ *)&this->m_cBSP);
  DDX_Control(pDX, nIDC: (HWND__ *)0x56F, rControl: (HWND__ *)&this->m_cConfigs);
}

//------------------------------------------------------------------------------
// Address: 0x100ECD20
// Name: protected: void COPTBuild::OnSelchangeConfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnSelchangeConfigs(COPTBuild *this)
{
  WPARAM v2; // ebx
  BOOL v3; // edi
  LRESULT v4; // eax
  CGameConfig *Config; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-1Ch]

  COPTBuild::SaveInfo(this, pConfig: this->m_pConfig);
  m_hWnd = this->m_cConfigs.m_hWnd;
  this->m_pConfig = nullptr;
  v2 = SendMessageA(hWnd: m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v3 = v2 != -1;
  CWnd::EnableWindow(this: &this->m_cBSP, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cLIGHT, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cVIS, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cGame, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cBSPDir, bEnable: v3);
  if ( v2 != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    Config = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v4, piIndex: nullptr);
    this->m_pConfig = Config;
    EditorUtil_TransferPath(pDlg: this, nIDC: 1011, szDest: Config->szBSP, bExpand: false);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1132, szDest: this->m_pConfig->szLIGHT, bExpand: false);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1133, szDest: this->m_pConfig->szVIS, bExpand: false);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1009, szDest: this->m_pConfig->szExecutable, bExpand: false);
    EditorUtil_TransferPath(pDlg: this, nIDC: 1400, szDest: this->m_pConfig->szBSPDir, bExpand: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECE50
// Name: protected: virtual int COPTBuild::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTBuild::OnInitDialog(COPTBuild *this)
{
  CDialog::OnInitDialog(this);
  this->m_pConfig = nullptr;
  UpdateConfigList(combo: &this->m_cConfigs);
  SelectActiveConfig(combo: &this->m_cConfigs);
  COPTBuild::OnSelchangeConfigs(this);
  CPropertyPage::SetModified(this, bChanged: 1);
  CPropertyPage::SetModified(this, bChanged: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ECEA0
// Name: protected: int COPTBuild::HandleInsertParm(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTBuild::HandleInsertParm(COPTBuild *this, unsigned int nID)
{
  const char *v2; // eax

  switch ( nID )
  {
    case 0x100u:
      v2 = "$file";
      goto LABEL_8;
    case 0x101u:
      v2 = "$file.$ext";
      goto LABEL_8;
    case 0x102u:
      v2 = "$path";
      goto LABEL_8;
    case 0x103u:
      v2 = "$bspdir";
      goto LABEL_8;
    case 0x104u:
      v2 = "$exedir";
      goto LABEL_8;
    case 0x105u:
      v2 = "$gamedir";
LABEL_8:
      SendMessageA(hWnd: this->m_pAddParmWnd->m_hWnd, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)v2);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ECF20
// Name: protected: void COPTBuild::InsertParm(unsigned int,class CEdit __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::InsertParm(COPTBuild *this, unsigned int nID, CEdit *pEdit)
{
  HMENU PopupMenu; // eax
  CWnd *DlgItem; // eax
  CRect r; // [esp+Ch] [ebp-24h] BYREF
  CMenu menu; // [esp+1Ch] [ebp-14h] BYREF
  int v8; // [esp+2Ch] [ebp-4h]

  this->m_pAddParmWnd = pEdit;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  menu.m_hMenu = nullptr;
  v8 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x100u, lpNewItem: "Map Filename (no extension)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x101u, lpNewItem: "Map Filename (with extension)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x102u, lpNewItem: "Map Path (no filename)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x104u, lpNewItem: "Game Executable Directory");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x103u, lpNewItem: "BSP Directory");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x105u, lpNewItem: "Game Directory");
  DlgItem = CWnd::GetDlgItem(this, nID);
  memset(&r, 0, sizeof(r));
  GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: &r);
  CMenu::TrackPopupMenu(this: &menu, nFlags: 0, x: r.left, y: r.bottom, pWnd: this, lpRect: nullptr);
  v8 = -1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
}

//------------------------------------------------------------------------------
// Address: 0x100ED050
// Name: protected: void COPTBuild::OnParmsBsp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnParmsBsp(COPTBuild *this)
{
  COPTBuild::InsertParm(this, nID: 0x3F5u, pEdit: &this->m_cBSP);
}

//------------------------------------------------------------------------------
// Address: 0x100ED070
// Name: protected: void COPTBuild::OnParmsGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnParmsGame(COPTBuild *this)
{
  COPTBuild::InsertParm(this, nID: 0x577u, pEdit: &this->m_cGame);
}

//------------------------------------------------------------------------------
// Address: 0x100ED090
// Name: protected: void COPTBuild::OnParmsLight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnParmsLight(COPTBuild *this)
{
  COPTBuild::InsertParm(this, nID: 0x3F7u, pEdit: &this->m_cLIGHT);
}

//------------------------------------------------------------------------------
// Address: 0x100ED0B0
// Name: protected: void COPTBuild::OnParmsVis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnParmsVis(COPTBuild *this)
{
  COPTBuild::InsertParm(this, nID: 0x3F9u, pEdit: &this->m_cVIS);
}

//------------------------------------------------------------------------------
// Address: 0x100ED0D0
// Name: protected: void COPTBuild::DoBrowse(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::DoBrowse(COPTBuild *this, CWnd *pWnd)
{
  CAfxStringMgr *StringManager; // eax
  CWnd *v4; // edi
  ATL::CStringData *PathName; // eax
  COleDropTarget **p_m_pDropTarget; // eax
  char *v7; // eax
  CFileDialog dlg; // [esp+8h] [ebp-214h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+20Ch] [ebp-10h] BYREF
  int v10; // [esp+218h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v10 = 1;
  v4 = pWnd;
  CWnd::GetWindowTextA(this: pWnd, rString: &str);
  EditorUtil_ConvertPath(&str, bExpand: true);
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 1,
    lpszDefExt: ".exe",
    lpszFileName: str.m_pszData,
    dwFlags: 0x100Cu,
    lpszFilter: "Programs (*.exe)|*.exe||",
    pParentWnd: this,
    dwSize: 0,
    bVistaStyle: 1);
  LOBYTE(v10) = 2;
  if ( CFileDialog::DoModal(this: &dlg) == 2 )
  {
    LOBYTE(v10) = 1;
    CFileDialog::~CFileDialog(this: &dlg);
  }
  else
  {
    PathName = (ATL::CStringData *)CFileDialog::GetPathName(
                                     this: &dlg,
                                     result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pWnd);
    LOBYTE(v10) = 4;
    ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: PathName);
    LOBYTE(v10) = 2;
    p_m_pDropTarget = &pWnd[-1].m_pDropTarget;
    if ( _InterlockedDecrement((volatile signed __int32 *)&pWnd[-1].m_pMFCCtrlContainer) <= 0 )
      ((void (__stdcall *)(COleDropTarget **))(*p_m_pDropTarget)->dtr_CObject)(a1: p_m_pDropTarget);
    EditorUtil_ConvertPath(&str, bExpand: false);
    CWnd::SetWindowTextA(this: v4, lpszString: str.m_pszData);
    LOBYTE(v10) = 1;
    CFileDialog::~CFileDialog(this: &dlg);
  }
  v10 = -1;
  v7 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100ED230
// Name: protected: void COPTBuild::OnBrowseBsp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnBrowseBsp(COPTBuild *this)
{
  COPTBuild::DoBrowse(this, pWnd: &this->m_cBSP);
}

//------------------------------------------------------------------------------
// Address: 0x100ED240
// Name: protected: void COPTBuild::OnBrowseGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnBrowseGame(COPTBuild *this)
{
  COPTBuild::DoBrowse(this, pWnd: &this->m_cGame);
}

//------------------------------------------------------------------------------
// Address: 0x100ED250
// Name: protected: void COPTBuild::OnBrowseLight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnBrowseLight(COPTBuild *this)
{
  COPTBuild::DoBrowse(this, pWnd: &this->m_cLIGHT);
}

//------------------------------------------------------------------------------
// Address: 0x100ED260
// Name: protected: void COPTBuild::OnBrowseVis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnBrowseVis(COPTBuild *this)
{
  COPTBuild::DoBrowse(this, pWnd: &this->m_cVIS);
}

//------------------------------------------------------------------------------
// Address: 0x100ED270
// Name: protected: void COPTBuild::OnBrowseBspdir(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTBuild::OnBrowseBspdir(COPTBuild *this)
{
  CAfxStringMgr *StringManager; // eax
  CEdit *p_m_cBSPDir; // edi
  HWND__ *m_hWnd; // edx
  const _ITEMIDLIST *v5; // eax
  _ITEMIDLIST *v6; // esi
  char *v7; // eax
  char szTemp[260]; // [esp+8h] [ebp-134h] BYREF
  _browseinfoA bi; // [esp+10Ch] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+12Ch] [ebp-10h] BYREF
  int v11; // [esp+138h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v11 = 1;
  p_m_cBSPDir = &this->m_cBSPDir;
  CWnd::GetWindowTextA(this: &this->m_cBSPDir, rString: &str);
  EditorUtil_ConvertPath(&str, bExpand: true);
  V_strncpy(pDest: szTemp, pSrc: str.m_pszData, maxLen: 260);
  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  memset(&bi.lpfn, 0, 12);
  bi.hwndOwner = m_hWnd;
  bi.pszDisplayName = szTemp;
  bi.lpszTitle = "Select BSP file directory";
  bi.ulFlags = 1;
  v5 = SHBrowseForFolderA(lpbi: &bi);
  v6 = (_ITEMIDLIST *)v5;
  if ( v5 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v5, pszPath: szTemp);
    CoTaskMemFree(pv: v6);
    ATL::CSimpleStringT<char,0>::SetString(this: &str, pszSrc: szTemp, nLength: strlen(szTemp));
    EditorUtil_ConvertPath(&str, bExpand: false);
    CWnd::SetWindowTextA(this: p_m_cBSPDir, lpszString: str.m_pszData);
  }
  v11 = -1;
  v7 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100ED3D0
// Name: protected: virtual struct AFX_MSGMAP const __near * COPTBuild::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COPTBuild::GetMessageMap(COPTBuild *this)
{
  return (const AFX_MSGMAP *)&off_105EFDC0;
}
