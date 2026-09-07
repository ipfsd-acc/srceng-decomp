// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/runmapexpertdlg.cpp
// Functions: 27
// ============================================================

#include "hammer\runmapexpertdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F52B0
// Name: protected: char const __near * CRunMapExpertDlg::GetCmdString(struct CCOMMAND __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRunMapExpertDlg::GetCmdString(CRunMapExpertDlg *this, CCOMMAND *pCommand)
{
  int iSpecialCmd; // eax
  char *result; // eax

  iSpecialCmd = pCommand->iSpecialCmd;
  if ( iSpecialCmd > 256 )
  {
    switch ( iSpecialCmd )
    {
      case 257:
        result = "Copy File";
        break;
      case 258:
        result = "Delete File";
        break;
      case 259:
        result = "Rename File";
        break;
      case 260:
        result = "Generate Grid Nav";
        break;
      default:
        return (char *)&var;
    }
  }
  else if ( iSpecialCmd == 256 )
  {
    return "Change Directory";
  }
  else if ( iSpecialCmd != 0 )
  {
    return (char *)&var;
  }
  else
  {
    return pCommand->szRun;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F5380
// Name: protected: virtual void CRunMapExpertDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::DoDataExchange(CRunMapExpertDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x4BC, rControl: (HWND__ *)&this->m_cCmdSequences);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4D5, rControl: (HWND__ *)&this->m_cMoveUp);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4D9, rControl: (HWND__ *)&this->m_cMoveDown);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4DE, rControl: (HWND__ *)&this->m_cEnsureFn);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4DD, rControl: (HWND__ *)&this->m_cEnsureCheck);
  DDX_Control(pDX, nIDC: (HWND__ *)0x437, rControl: (HWND__ *)&this->m_cParameters);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4D7, rControl: (HWND__ *)&this->m_cCommand);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x473, value: &this->m_bWaitForKeypress);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4D8, rControl: (HWND__ *)&this->m_cCommandList);
}

//------------------------------------------------------------------------------
// Address: 0x100F5440
// Name: protected: void CRunMapExpertDlg::OnBrowsecommand(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnBrowsecommand(CRunMapExpertDlg *this)
{
  HMENU PopupMenu; // eax
  CWnd *DlgItem; // eax
  CRect r; // [esp+Ch] [ebp-24h] BYREF
  CMenu menu; // [esp+1Ch] [ebp-14h] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  menu.m_hMenu = nullptr;
  v6 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x150u, lpNewItem: "Executable");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x151u, lpNewItem: "Change Directory");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x152u, lpNewItem: "Copy File");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x153u, lpNewItem: "Delete File");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x154u, lpNewItem: "Rename File");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x157u, lpNewItem: "BSP program");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x156u, lpNewItem: "VIS program");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x158u, lpNewItem: "LIGHT program");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x155u, lpNewItem: "Game program");
  if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::m_pMapDoc->m_pGridNav != nullptr && CGridNav::sm_bEnabled )
  {
    AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
    AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x159u, lpNewItem: "Generate Grid Nav");
  }
  DlgItem = CWnd::GetDlgItem(this, nID: 1238);
  memset(&r, 0, sizeof(r));
  GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: &r);
  CMenu::TrackPopupMenu(this: &menu, nFlags: 0, x: r.left, y: r.bottom, pWnd: this, lpRect: nullptr);
  v6 = -1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
}

//------------------------------------------------------------------------------
// Address: 0x100F55D0
// Name: protected: int CRunMapExpertDlg::HandleInsertParm(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRunMapExpertDlg::HandleInsertParm(CRunMapExpertDlg *this, unsigned int nID)
{
  const char *v2; // eax

  switch ( nID )
  {
    case 0x100u:
      v2 = "$file";
      break;
    case 0x101u:
      v2 = "$file.$ext";
      break;
    case 0x102u:
      v2 = "$path";
      break;
    case 0x103u:
      v2 = "$bspdir";
      break;
    case 0x104u:
      v2 = "$exedir";
      break;
    default:
      v2 = "$gamedir";
      break;
  }
  SendMessageA(hWnd: this->m_cParameters.m_hWnd, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F5650
// Name: protected: void CRunMapExpertDlg::OnInsertparm(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnInsertparm(CRunMapExpertDlg *this)
{
  HMENU PopupMenu; // eax
  CWnd *DlgItem; // eax
  CRect r; // [esp+Ch] [ebp-24h] BYREF
  CMenu menu; // [esp+1Ch] [ebp-14h] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  menu.m_hMenu = nullptr;
  v6 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x100u, lpNewItem: "Map Filename (no extension)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x101u, lpNewItem: "Map Filename (with extension)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x102u, lpNewItem: "Map Path (no filename)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x104u, lpNewItem: "Game Executable Directory");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x103u, lpNewItem: "BSP Directory");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x105u, lpNewItem: "Game Directory");
  DlgItem = CWnd::GetDlgItem(this, nID: 1243);
  memset(&r, 0, sizeof(r));
  GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: &r);
  CMenu::TrackPopupMenu(this: &menu, nFlags: 0, x: r.left, y: r.bottom, pWnd: this, lpRect: nullptr);
  v6 = -1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
}

//------------------------------------------------------------------------------
// Address: 0x100F5770
// Name: public: CRunMapExpertDlg::CRunMapExpertDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CRunMapExpertDlg *__thiscall CRunMapExpertDlg::CRunMapExpertDlg(CRunMapExpertDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xD7u, pParentWnd: pParent);
  this->__vftable = (CRunMapExpertDlg_vtbl *)&CRunMapExpertDlg::`vftable';
  CWnd::CWnd(this: &this->m_cCmdSequences);
  this->m_cCmdSequences.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_cMoveUp);
  this->m_cMoveUp.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cMoveDown);
  this->m_cMoveDown.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cEnsureFn);
  this->m_cEnsureFn.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cEnsureCheck);
  this->m_cEnsureCheck.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cLongFilenames);
  this->m_cLongFilenames.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cParameters);
  this->m_cParameters.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cCommand);
  this->m_cCommand.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cCommandList);
  this->m_cCommandList.__vftable = (CMyCheckListBox_vtbl *)&CListBox::`vftable';
  this->m_cCommandList.__vftable = (CMyCheckListBox_vtbl *)&CCheckListBox::`vftable';
  this->m_cCommandList.m_cyText = 0;
  this->m_cCommandList.m_nStyle = 0;
  this->m_cCommandList.m_bEnableActiveAccessibility = true;
  this->m_cCommandList.__vftable = (CMyCheckListBox_vtbl *)&CMyCheckListBox::`vftable';
  this->m_pActiveSequence = nullptr;
  this->m_bNoUpdateCmd = 0;
  this->m_bSwitchMode = 0;
  this->m_bWaitForKeypress = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F5940
// Name: protected: void CRunMapExpertDlg::SaveCommandsToSequence(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100F5A70
// Name: protected: virtual void CRunMapExpertDlg::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnCancel(CRunMapExpertDlg *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  CRunMapExpertDlg::SaveCommandsToSequence(this);
  ModuleState = AfxGetModuleState();
  CHammer::SaveSequences(this: (CHammer *)ModuleState->m_pCurrentWinApp);
  CDialog::OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F5A90
// Name: protected: void CRunMapExpertDlg::OnNormal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnNormal(CRunMapExpertDlg *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  this->m_bSwitchMode = 1;
  CRunMapExpertDlg::SaveCommandsToSequence(this);
  ModuleState = AfxGetModuleState();
  CHammer::SaveSequences(this: (CHammer *)ModuleState->m_pCurrentWinApp);
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CDialog::EndDialog(this, nResult: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100F5AD0
// Name: protected: virtual void CRunMapExpertDlg::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnOK(CRunMapExpertDlg *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  CRunMapExpertDlg::SaveCommandsToSequence(this);
  ModuleState = AfxGetModuleState();
  CHammer::SaveSequences(this: (CHammer *)ModuleState->m_pCurrentWinApp);
  CDialog::OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F5AF0
// Name: protected: void CRunMapExpertDlg::AddCommand(int,struct CCOMMAND __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::AddCommand(CRunMapExpertDlg *this, WPARAM iIndex, CCOMMAND *pCommand)
{
  CAfxStringMgr *StringManager; // eax
  char *CmdString; // eax
  char *m_pszData; // ebx
  WPARAM v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  CmdString = CRunMapExpertDlg::GetCmdString(this, pCommand);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &str,
    pszFormat: "%s %s",
    CmdString,
    pCommand->szParms);
  m_pszData = str.m_pszData;
  v7 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x181u, wParam: iIndex, lParam: (LPARAM)str.m_pszData);
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x19Au, wParam: v7, lParam: (LPARAM)pCommand);
  v9 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100F5BD0
// Name: protected: void CRunMapExpertDlg::UpdateCommandWithEditFields(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::UpdateCommandWithEditFields(CRunMapExpertDlg *this, CCOMMAND *iIndex)
{
  WPARAM v2; // edi
  int bCmdChecked; // [esp+10h] [ebp-4h]
  CCOMMAND *pCommand; // [esp+1Ch] [ebp+8h]

  v2 = (WPARAM)iIndex;
  if ( iIndex == (CCOMMAND *)-1
    && (v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0)) == -1 )
  {
    pCommand = nullptr;
  }
  else
  {
    pCommand = (CCOMMAND *)SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
  }
  CWnd::GetWindowTextA(this: &this->m_cCommand, lpszString: pCommand->szRun, nMaxCount: 260);
  CWnd::GetWindowTextA(this: &this->m_cParameters, lpszString: pCommand->szParms, nMaxCount: 260);
  CWnd::GetWindowTextA(this: &this->m_cEnsureFn, lpszString: pCommand->szEnsureFn, nMaxCount: 260);
  pCommand->bEnsureCheck = SendMessageA(hWnd: this->m_cEnsureCheck.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  bCmdChecked = CCheckListBox::GetCheck(this: &this->m_cCommandList, nIndex: v2);
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x182u, wParam: v2, lParam: 0);
  CRunMapExpertDlg::AddCommand(this, iIndex: v2, pCommand);
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x186u, wParam: v2, lParam: 0);
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_cCommandList.m_hWnd, lpRect: nullptr, bErase: true);
  CCheckListBox::SetCheck(this: &this->m_cCommandList, nIndex: v2, nCheck: bCmdChecked);
}

//------------------------------------------------------------------------------
// Address: 0x100F5D10
// Name: protected: void CRunMapExpertDlg::OnUpdateCommand(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnUpdateCommand(CRunMapExpertDlg *this)
{
  WPARAM v2; // eax
  LRESULT v3; // edi

  if ( this->m_bNoUpdateCmd == 0 )
  {
    v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
    if ( v2 == -1 )
      v3 = 0;
    else
      v3 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    if ( *(_DWORD *)(v3 + 4) != 0 )
    {
      this->m_bNoUpdateCmd = 1;
      CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: &var);
      this->m_bNoUpdateCmd = 0;
      *(_DWORD *)(v3 + 4) = 0;
    }
    CRunMapExpertDlg::UpdateCommandWithEditFields(this, iIndex: (CCOMMAND *)0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5D90
// Name: protected: void CRunMapExpertDlg::OnUpdateEnsurefn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnUpdateEnsurefn(CRunMapExpertDlg *this)
{
  if ( this->m_bNoUpdateCmd == 0 )
    CRunMapExpertDlg::UpdateCommandWithEditFields(this, iIndex: (CCOMMAND *)0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x100F5DB0
// Name: protected: void CRunMapExpertDlg::OnEnsurecheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnEnsurecheck(CRunMapExpertDlg *this)
{
  LRESULT v2; // eax

  if ( this->m_bNoUpdateCmd == 0 )
    CRunMapExpertDlg::UpdateCommandWithEditFields(this, iIndex: (CCOMMAND *)0xFFFFFFFF);
  v2 = SendMessageA(hWnd: this->m_cEnsureCheck.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_cEnsureFn, bEnable: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100F5DF0
// Name: protected: void CRunMapExpertDlg::OnSelchangeCommandlist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnSelchangeCommandlist(CRunMapExpertDlg *this)
{
  LRESULT v2; // eax
  LRESULT v3; // ebx
  int v4; // eax
  CWnd *DlgItem; // edi
  int v6; // edi
  LRESULT v7; // eax
  int v8; // eax
  const char *v9; // eax
  LRESULT v10; // eax
  int iEnableCmds[7]; // [esp+Ch] [ebp-28h]
  int iIndex; // [esp+28h] [ebp-Ch]
  int bEnable; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  iIndex = v2;
  if ( v2 == -1 )
    v3 = 0;
  else
    v3 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
  v4 = 1239;
  iEnableCmds[0] = 1239;
  iEnableCmds[1] = 1079;
  iEnableCmds[2] = 1246;
  iEnableCmds[3] = 1245;
  iEnableCmds[4] = 1243;
  bEnable = v3 != 0;
  iEnableCmds[5] = 1238;
  iEnableCmds[6] = -1;
  this->m_bNoUpdateCmd = 1;
  i = 0;
  do
  {
    DlgItem = CWnd::GetDlgItem(this, nID: v4);
    CWnd::EnableWindow(this: DlgItem, bEnable);
    if ( bEnable == 0 )
    {
      if ( i >= 3 )
        SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      else
        CWnd::SetWindowTextA(this: DlgItem, lpszString: &var);
    }
    v4 = iEnableCmds[++i];
  }
  while ( v4 != -1 );
  this->m_bNoUpdateCmd = 0;
  if ( v3 != 0 )
  {
    v6 = iIndex;
    CWnd::EnableWindow(this: &this->m_cMoveUp, bEnable: iIndex != 0);
    v7 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
    CWnd::EnableWindow(this: &this->m_cMoveDown, bEnable: v6 != v7 - 1);
    this->m_bNoUpdateCmd = 1;
    v8 = *(_DWORD *)(v3 + 4);
    if ( v8 > 256 )
    {
      switch ( v8 )
      {
        case 257:
          v9 = "Copy File";
          break;
        case 258:
          v9 = "Delete File";
          break;
        case 259:
          v9 = "Rename File";
          break;
        case 260:
          v9 = "Generate Grid Nav";
          break;
        default:
          goto LABEL_21;
      }
    }
    else if ( v8 == 256 )
    {
      v9 = "Change Directory";
    }
    else if ( v8 != 0 )
    {
LABEL_21:
      v9 = &var;
    }
    else
    {
      v9 = (const char *)(v3 + 8);
    }
    CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: v9);
    CWnd::SetWindowTextA(this: &this->m_cParameters, lpszString: (const char *)(v3 + 268));
    SendMessageA(hWnd: this->m_cEnsureCheck.m_hWnd, Msg: 0xF1u, wParam: *(_DWORD *)(v3 + 532), lParam: 0);
    CWnd::SetWindowTextA(this: &this->m_cEnsureFn, lpszString: (const char *)(v3 + 536));
    if ( this->m_bNoUpdateCmd == 0 )
      CRunMapExpertDlg::UpdateCommandWithEditFields(this, iIndex: (CCOMMAND *)0xFFFFFFFF);
    v10 = SendMessageA(hWnd: this->m_cEnsureCheck.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
    CWnd::EnableWindow(this: &this->m_cEnsureFn, bEnable: v10);
    this->m_bNoUpdateCmd = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6020
// Name: protected: void CRunMapExpertDlg::DeleteCommand(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::DeleteCommand(CRunMapExpertDlg *this, CCOMMAND *iIndex)
{
  signed int v2; // esi
  CCOMMAND *pCommand; // [esp+14h] [ebp+8h]

  v2 = (signed int)iIndex;
  if ( iIndex == (CCOMMAND *)-1
    && (v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0)) == -1 )
  {
    pCommand = nullptr;
  }
  else
  {
    pCommand = (CCOMMAND *)SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
  }
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x182u, wParam: v2, lParam: 0);
  if ( v2 >= SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) - 1 )
    v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) - 1;
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x186u, wParam: v2, lParam: 0);
  CRunMapExpertDlg::OnSelchangeCommandlist(this);
  operator delete(p: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x100F60E0
// Name: protected: void CRunMapExpertDlg::OnMovedown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnMovedown(CRunMapExpertDlg *this)
{
  WPARAM v2; // eax
  unsigned int v3; // edi
  WPARAM v4; // edi
  int nCheck; // [esp+Ch] [ebp-8h]
  CCOMMAND *pCommand; // [esp+10h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    pCommand = (CCOMMAND *)SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    if ( pCommand != nullptr )
    {
      nCheck = CCheckListBox::GetCheck(this: &this->m_cCommandList, nIndex: v3);
      SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0);
      v4 = v3 + 1;
      CRunMapExpertDlg::AddCommand(this, iIndex: v4, pCommand);
      CCheckListBox::SetCheck(this: &this->m_cCommandList, nIndex: v4, nCheck);
      SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x186u, wParam: v4, lParam: 0);
      CRunMapExpertDlg::OnSelchangeCommandlist(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6180
// Name: protected: void CRunMapExpertDlg::OnMoveup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnMoveup(CRunMapExpertDlg *this)
{
  WPARAM v2; // eax
  unsigned int v3; // edi
  WPARAM v4; // edi
  int nCheck; // [esp+Ch] [ebp-8h]
  CCOMMAND *pCommand; // [esp+10h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    pCommand = (CCOMMAND *)SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    if ( pCommand != nullptr )
    {
      nCheck = CCheckListBox::GetCheck(this: &this->m_cCommandList, nIndex: v3);
      SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0);
      v4 = v3 - 1;
      CRunMapExpertDlg::AddCommand(this, iIndex: v4, pCommand);
      CCheckListBox::SetCheck(this: &this->m_cCommandList, nIndex: v4, nCheck);
      SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x186u, wParam: v4, lParam: 0);
      CRunMapExpertDlg::OnSelchangeCommandlist(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6220
// Name: protected: void CRunMapExpertDlg::OnNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnNew(CRunMapExpertDlg *this)
{
  unsigned __int8 *v2; // edi
  LRESULT v3; // eax

  v2 = (unsigned __int8 *)operator new(nSize: 0x324u);
  memset(dst: v2, value: 0, count: 0x324u);
  CRunMapExpertDlg::AddCommand(this, iIndex: 0xFFFFFFFF, pCommand: (CCOMMAND *)v2);
  v3 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x186u, wParam: v3 - 1, lParam: 0);
  CRunMapExpertDlg::OnSelchangeCommandlist(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F6280
// Name: protected: void CRunMapExpertDlg::OnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnRemove(CRunMapExpertDlg *this)
{
  CCOMMAND *v2; // eax

  v2 = (CCOMMAND *)SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v2 != (CCOMMAND *)-1 )
    CRunMapExpertDlg::DeleteCommand(this, iIndex: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100F62B0
// Name: protected: void CRunMapExpertDlg::OnSelchangeConfigurations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnSelchangeConfigurations(CRunMapExpertDlg *this)
{
  CRunMapExpertDlg *v1; // esi
  WPARAM v2; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  LRESULT v4; // edi
  signed int v5; // ebx
  CCOMMAND *v6; // eax
  CCommandSequence *pSeq; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-14h]
  CCOMMAND *pCommand; // [esp+1Ch] [ebp-10h]

  v1 = this;
  CRunMapExpertDlg::SaveCommandsToSequence(this);
  v2 = SendMessageA(hWnd: v1->m_cCmdSequences.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
  {
    v1->m_pActiveSequence = nullptr;
  }
  else
  {
    ModuleState = AfxGetModuleState();
    ModuleState->m_pCurrentWinApp->WriteProfileInt(
      this: ModuleState->m_pCurrentWinApp,
      a2: "RunMapExpert",
      a3: "LastSequence",
      a4: v2);
    v4 = SendMessageA(hWnd: v1->m_cCmdSequences.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    pSeq = (CCommandSequence *)v4;
    SendMessageA(hWnd: v1->m_cCommandList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
    v5 = 0;
    v1->m_pActiveSequence = (CCommandSequence *)v4;
    if ( *(int *)(v4 + 8) > 0 )
    {
      v9 = 0;
      do
      {
        v6 = (CCOMMAND *)operator new(nSize: 0x324u);
        if ( v6 != nullptr )
        {
          if ( v5 < 0 || v5 >= *(_DWORD *)(v4 + 8) )
            AfxThrowInvalidArgException();
          qmemcpy(v6, (const void *)(v9 + *(_DWORD *)(v4 + 4)), sizeof(CCOMMAND));
          v1 = this;
          v4 = (LRESULT)pSeq;
          pCommand = v6;
        }
        else
        {
          pCommand = nullptr;
        }
        CRunMapExpertDlg::AddCommand(this: v1, iIndex: v5, pCommand);
        CCheckListBox::SetCheck(this: &v1->m_cCommandList, nIndex: v5, nCheck: pCommand->bEnable);
        v9 += 804;
        ++v5;
      }
      while ( v5 < *(_DWORD *)(v4 + 8) );
    }
    SendMessageA(hWnd: v1->m_cCommandList.m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
    CRunMapExpertDlg::OnSelchangeCommandlist(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6420
// Name: protected: int CRunMapExpertDlg::HandleInsertCommand(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRunMapExpertDlg::HandleInsertCommand(CRunMapExpertDlg *this, unsigned int nID)
{
  WPARAM v3; // eax
  LRESULT v4; // esi
  int IsAlwaysLargeImage; // eax
  CFileDialog dlg; // [esp+8h] [ebp-210h] BYREF
  int v8; // [esp+214h] [ebp-4h]

  v3 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v3 != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_cCommandList.m_hWnd, Msg: 0x199u, wParam: v3, lParam: 0);
    if ( v4 != 0 )
    {
      if ( nID == 336 )
      {
        CFileDialog::CFileDialog(
          this: &dlg,
          bOpenFileDialog: 1,
          lpszDefExt: "exe",
          lpszFileName: nullptr,
          dwFlags: 0x100Cu,
          lpszFilter: "Executable Files|*.exe||",
          pParentWnd: this,
          dwSize: 0,
          bVistaStyle: 1);
        v8 = 0;
        if ( CFileDialog::DoModal(this: &dlg) != 2 )
        {
          IsAlwaysLargeImage = CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg);
          CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: *(const char **)(IsAlwaysLargeImage + 28));
          *(_DWORD *)(v4 + 4) = 0;
        }
        v8 = -1;
        CFileDialog::~CFileDialog(this: &dlg);
      }
      else
      {
        *(_DWORD *)(v4 + 4) = 0;
        switch ( nID )
        {
          case 0x151u:
            *(_DWORD *)(v4 + 4) = 256;
            break;
          case 0x152u:
            *(_DWORD *)(v4 + 4) = 257;
            break;
          case 0x153u:
            *(_DWORD *)(v4 + 4) = 258;
            break;
          case 0x154u:
            *(_DWORD *)(v4 + 4) = 259;
            break;
          case 0x155u:
            CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: "$game_exe");
            break;
          case 0x156u:
            CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: "$vis_exe");
            break;
          case 0x157u:
            CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: "$bsp_exe");
            break;
          case 0x158u:
            CWnd::SetWindowTextA(this: &this->m_cCommand, lpszString: "$light_exe");
            break;
          case 0x159u:
            *(_DWORD *)(v4 + 4) = 260;
            break;
          default:
            break;
        }
        if ( *(_DWORD *)(v4 + 4) != 0 )
          *(_DWORD *)(v4 + 528) = 1;
        CRunMapExpertDlg::OnSelchangeCommandlist(this);
        CRunMapExpertDlg::UpdateCommandWithEditFields(this, iIndex: (CCOMMAND *)0xFFFFFFFF);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F65E0
// Name: protected: void CRunMapExpertDlg::InitSequenceList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::InitSequenceList(CRunMapExpertDlg *this)
{
  CWinApp *m_pCurrentWinApp; // edi
  char *v3; // esi
  int m_xInnerUnknown; // eax
  char *v5; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  LPARAM v7; // edi
  WPARAM v8; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-30h]
  CHammer *pApp; // [esp+Ch] [ebp-14h]
  int iSize; // [esp+10h] [ebp-10h]

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  v3 = nullptr;
  pApp = (CHammer *)m_pCurrentWinApp;
  SendMessageA(hWnd: this->m_cCmdSequences.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  m_xInnerUnknown = m_pCurrentWinApp[1].m_xInnerUnknown;
  iSize = m_xInnerUnknown;
  if ( m_xInnerUnknown == 0 )
  {
    v5 = (char *)operator new(nSize: 0x94u);
    if ( v5 != nullptr )
    {
      *(_DWORD *)v5 = &CArray<CCOMMAND,CCOMMAND &>::`vftable';
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 4) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 2) = 0;
      v3 = v5;
    }
    strcpy(v3 + 20, "Default");
    ModuleState = AfxGetModuleState();
    CUIntArray::SetAtGrow(
      this: (CPtrArray *)&ModuleState->m_pCurrentWinApp[1].m_dwRef,
      nIndex: ModuleState->m_pCurrentWinApp[1].m_xInnerUnknown,
      newElement: v3);
    iSize = 1;
    m_xInnerUnknown = 1;
    v3 = nullptr;
  }
  if ( m_xInnerUnknown > 0 )
  {
    while ( 1 )
    {
      if ( (int)v3 < 0 || (int)v3 >= (signed int)m_pCurrentWinApp[1].m_xInnerUnknown )
        AfxThrowInvalidArgException();
      v7 = (LPARAM)m_pCurrentWinApp[1].m_pOuterUnknown[(_DWORD)v3].__vftable;
      v8 = SendMessageA(hWnd: this->m_cCmdSequences.m_hWnd, Msg: 0x143u, wParam: 0, lParam: v7 + 20);
      SendMessageA(hWnd: this->m_cCmdSequences.m_hWnd, Msg: 0x151u, wParam: v8, lParam: v7);
      if ( (int)++v3 >= iSize )
        break;
      m_pCurrentWinApp = pApp;
    }
  }
  m_hWnd = this->m_cCmdSequences.m_hWnd;
  this->m_pActiveSequence = nullptr;
  SendMessageA(hWnd: m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  CRunMapExpertDlg::OnSelchangeConfigurations(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F6740
// Name: protected: virtual int CRunMapExpertDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRunMapExpertDlg::OnInitDialog(CRunMapExpertDlg *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  WPARAM v3; // edi

  CDialog::OnInitDialog(this);
  ModuleState = AfxGetModuleState();
  v3 = ModuleState->m_pCurrentWinApp->GetProfileIntA(
         this: ModuleState->m_pCurrentWinApp,
         a2: "RunMapExpert",
         a3: "LastSequence",
         a4: 0);
  CRunMapExpertDlg::InitSequenceList(this);
  SendMessageA(hWnd: this->m_cCmdSequences.m_hWnd, Msg: 0x14Eu, wParam: v3, lParam: 0);
  CRunMapExpertDlg::OnSelchangeConfigurations(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F67A0
// Name: protected: void CRunMapExpertDlg::OnEditconfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapExpertDlg::OnEditconfigs(CRunMapExpertDlg *this)
{
  CRunMapCfgDlg dlg; // [esp+4h] [ebp-118h] BYREF
  int v3; // [esp+118h] [ebp-4h]

  CRunMapCfgDlg::CRunMapCfgDlg(this: &dlg, pParent: nullptr);
  v3 = 0;
  CRunMapExpertDlg::SaveCommandsToSequence(this);
  if ( CDialog::DoModal(this: &dlg) == 1 )
    CRunMapExpertDlg::InitSequenceList(this);
  v3 = 1;
  CListBox::~CListBox(this: &dlg.m_cConfigurations);
  v3 = -1;
  CDialog::~CDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100F6830
// Name: protected: virtual struct AFX_MSGMAP const __near * CRunMapExpertDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CRunMapExpertDlg::GetMessageMap(CRunMapExpertDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F24BC;
}
