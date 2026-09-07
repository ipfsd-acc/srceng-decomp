// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/optgeneral.cpp
// Functions: 11
// ============================================================

#include "hammer\optgeneral.h"

//------------------------------------------------------------------------------
// Address: 0x100EF230
// Name: public: virtual struct CRuntimeClass __near * COPTGeneral::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COPTGeneral::GetRuntimeClass(COPTGeneral *this)
{
  return &COPTGeneral::classCOPTGeneral;
}

//------------------------------------------------------------------------------
// Address: 0x100EF240
// Name: public: virtual COPTGeneral::~COPTGeneral(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTGeneral::~COPTGeneral(COPTGeneral *this)
{
  this->__vftable = (COPTGeneral_vtbl *)&COPTGeneral::`vftable';
  CEdit::~CEdit(this: &this->m_cAutosaveDir);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_UndoSpin);
  CButton::~CButton(this: &this->m_cAutosaveBrowseButton);
  CStatic::~CStatic(this: &this->m_cAutosaveDirectoryLabel);
  CEdit::~CEdit(this: &this->m_cAutosaveIterations);
  CStatic::~CStatic(this: &this->m_cAutosaveIterationLabel);
  CEdit::~CEdit(this: &this->m_cAutosaveSpace);
  CStatic::~CStatic(this: &this->m_cAutosaveSpaceLabel);
  CEdit::~CEdit(this: &this->m_cAutosaveTime);
  CStatic::~CStatic(this: &this->m_cAutosaveTimeLabel);
  CButton::~CButton(this: &this->m_cEnableAutosave);
  CButton::~CButton(this: &this->m_cEnablePerforceIntegration);
  CButton::~CButton(this: &this->m_cIndependentWin);
  CButton::~CButton(this: &this->m_cLoadWinPos);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EF360
// Name: public: COPTGeneral::COPTGeneral(void)
// Source: json
//------------------------------------------------------------------------------
COPTGeneral *__thiscall COPTGeneral::COPTGeneral(COPTGeneral *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0xAEu, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COPTGeneral_vtbl *)&COPTGeneral::`vftable';
  CWnd::CWnd(this: &this->m_cLoadWinPos);
  this->m_cLoadWinPos.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cIndependentWin);
  this->m_cIndependentWin.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cEnablePerforceIntegration);
  this->m_cEnablePerforceIntegration.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cEnableAutosave);
  this->m_cEnableAutosave.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveTimeLabel);
  this->m_cAutosaveTimeLabel.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveTime);
  this->m_cAutosaveTime.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveSpaceLabel);
  this->m_cAutosaveSpaceLabel.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveSpace);
  this->m_cAutosaveSpace.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveIterationLabel);
  this->m_cAutosaveIterationLabel.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveIterations);
  this->m_cAutosaveIterations.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveDirectoryLabel);
  this->m_cAutosaveDirectoryLabel.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveBrowseButton);
  this->m_cAutosaveBrowseButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_UndoSpin);
  this->m_UndoSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  CWnd::CWnd(this: &this->m_cAutosaveDir);
  this->m_cAutosaveDir.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  this->m_iMaxAutosavesPerMap = 0;
  this->m_iUndoLevels = 0;
  this->m_nMaxCameras = 5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EF5B0
// Name: protected: virtual void COPTGeneral::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTGeneral::DoDataExchange(COPTGeneral *this, CDataExchange *pDX)
{
  int m_nMaxCameras; // eax
  int *p_m_iTimeBetweenSaves; // [esp+Ch] [ebp-4h]

  DDX_Control(pDX, nIDC: (HWND__ *)0x53A, rControl: (HWND__ *)&this->m_cLoadWinPos);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53B, rControl: (HWND__ *)&this->m_cIndependentWin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_UndoSpin);
  DDX_Text(pDX, nIDC: (HWND__ *)0x4A5, value: &this->m_iUndoLevels);
  DDX_Text(pDX, nIDC: (HWND__ *)0x4A6, value: &this->m_nMaxCameras);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x57A, value: &Options.general.bStretchArches);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x579, value: &Options.general.bGroupWhileIgnore);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x53B, value: &Options.general.bIndependentwin);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x57C, value: &Options.general.bEnablePerforceIntegration);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x53A, value: &Options.general.bLoadwinpos);
  if ( this->m_iUndoLevels < 5 )
  {
    AfxMessageBox(lpszText: "Undo levels must be at least 5.", nType: 0x30u, nIDHelp: 0);
    CDataExchange::Fail(this: pDX);
  }
  m_nMaxCameras = this->m_nMaxCameras;
  if ( m_nMaxCameras < 1 || m_nMaxCameras > 100 )
  {
    AfxMessageBox(lpszText: "Max cameras must be between 1 and 1000.", nType: 0x30u, nIDHelp: 0);
    CDataExchange::Fail(this: pDX);
  }
  DDX_Control(pDX, nIDC: (HWND__ *)0x673, rControl: (HWND__ *)&this->m_cEnableAutosave);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x673, value: &Options.general.bEnableAutosave);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F3, value: &this->m_iMaxAutosavesPerMap);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F2, value: &this->m_iMaxAutosaveSpace);
  p_m_iTimeBetweenSaves = &this->m_iTimeBetweenSaves;
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_iTimeBetweenSaves);
  DDX_Control(pDX, nIDC: (HWND__ *)0x671, rControl: (HWND__ *)&this->m_cAutosaveDir);
  DDX_Control(pDX, nIDC: (HWND__ *)0x674, rControl: (HWND__ *)&this->m_cAutosaveTimeLabel);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_cAutosaveTime);
  DDX_Control(pDX, nIDC: (HWND__ *)0x675, rControl: (HWND__ *)&this->m_cAutosaveSpaceLabel);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F2, rControl: (HWND__ *)&this->m_cAutosaveSpace);
  DDX_Control(pDX, nIDC: (HWND__ *)0x676, rControl: (HWND__ *)&this->m_cAutosaveIterationLabel);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F3, rControl: (HWND__ *)&this->m_cAutosaveIterations);
  DDX_Control(pDX, nIDC: (HWND__ *)0x677, rControl: (HWND__ *)&this->m_cAutosaveDirectoryLabel);
  DDX_Control(pDX, nIDC: (HWND__ *)0x672, rControl: (HWND__ *)&this->m_cAutosaveBrowseButton);
  if ( this->m_iMaxAutosaveSpace > 10000 )
  {
    AfxMessageBox(
      lpszText: "You have selected too much space for autosaving. The maximum value is 10000.",
      nType: 0x30u,
      nIDHelp: 0);
    CDataExchange::Fail(this: pDX);
  }
  if ( this->m_iMaxAutosavesPerMap > 999 )
  {
    AfxMessageBox(lpszText: "Number of autosaves must be 0-999.", nType: 0x30u, nIDHelp: 0);
    CDataExchange::Fail(this: pDX);
  }
  if ( *p_m_iTimeBetweenSaves < 1 || *p_m_iTimeBetweenSaves > 120 )
  {
    AfxMessageBox(lpszText: "Time must be between 1 - 120 minutes.", nType: 0x30u, nIDHelp: 0);
    CDataExchange::Fail(this: pDX);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF810
// Name: protected: void COPTGeneral::OnIndependentwindows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTGeneral::OnIndependentwindows(COPTGeneral *this)
{
  LRESULT v2; // eax

  v2 = SendMessageA(hWnd: this->m_cIndependentWin.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_cLoadWinPos, bEnable: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100EF840
// Name: protected: void COPTGeneral::OnEnableAutosave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTGeneral::OnEnableAutosave(COPTGeneral *this)
{
  LRESULT v2; // edi

  v2 = SendMessageA(hWnd: this->m_cEnableAutosave.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_cAutosaveDir, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveTime, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveTimeLabel, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveSpaceLabel, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveSpace, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveIterationLabel, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveIterations, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveDirectoryLabel, bEnable: v2);
  CWnd::EnableWindow(this: &this->m_cAutosaveBrowseButton, bEnable: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100EF8D0
// Name: public: static class CObject __near * COPTGeneral::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COPTGeneral *__stdcall COPTGeneral::CreateObject()
{
  COPTGeneral *v0; // eax

  v0 = (COPTGeneral *)operator new(nSize: 0x714u);
  if ( v0 != nullptr )
    return COPTGeneral::COPTGeneral(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EF930
// Name: protected: virtual int COPTGeneral::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTGeneral::OnApply(COPTGeneral *this)
{
  BOOL v2; // edi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // eax
  int v5; // edx
  char v6; // cl
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  char *v9; // eax
  int v11; // esi
  char *v12; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+8h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-4h]

  v2 = Options.general.iTimeBetweenSaves != this->m_iTimeBetweenSaves;
  if ( Options.general.iMaxAutosavesPerMap == 0 )
  {
    if ( this->m_iMaxAutosavesPerMap == 0 )
      goto LABEL_6;
  }
  else if ( this->m_iMaxAutosavesPerMap != 0 )
  {
LABEL_6:
    Options.general.iUndoLevels = this->m_iUndoLevels;
    Options.general.nMaxCameras = this->m_nMaxCameras;
    Options.general.iMaxAutosavesPerMap = this->m_iMaxAutosavesPerMap;
    Options.general.iMaxAutosaveSpace = this->m_iMaxAutosaveSpace;
    Options.general.iTimeBetweenSaves = this->m_iTimeBetweenSaves;
    Options.general.bEnableAutosave = SendMessageA(
                                        hWnd: this->m_cEnableAutosave.m_hWnd,
                                        Msg: 0xF0u,
                                        wParam: 0,
                                        lParam: 0);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v14 = 1;
    CWnd::GetWindowTextA(this: &this->m_cAutosaveDir, rString: &str);
    m_pszData = str.m_pszData;
    if ( strcmp(Options.general.szAutosaveDir, str.m_pszData) != 0 )
    {
      v5 = Options.general.szAutosaveDir - str.m_pszData;
      do
      {
        v6 = *m_pszData;
        m_pszData[v5] = *m_pszData;
        ++m_pszData;
      }
      while ( v6 != 0 );
    }
    else if ( !v2 )
    {
LABEL_14:
      COptions::PerformChanges(this: &Options, dwOptionsChanged: 2);
      if ( Options.general.bEnableAutosave == 0
        || (ModuleState = AfxGetModuleState(),
            CHammer::VerifyAutosaveDirectory(
              this: (CHammer *)ModuleState->m_pCurrentWinApp,
              szAutosaveDirectory: Options.general.szAutosaveDir) != 0) )
      {
        v11 = CPropertyPage::OnApply(this);
        v14 = -1;
        v12 = str.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
        return v11;
      }
      else
      {
        Options.general.bEnableAutosave = 0;
        SendMessageA(hWnd: this->m_cEnableAutosave.m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
        COPTGeneral::OnEnableAutosave(this);
        v14 = -1;
        v9 = str.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
        return 0;
      }
    }
    v7 = AfxGetModuleState();
    CHammer::ResetAutosaveTimer(this: (CHammer *)v7->m_pCurrentWinApp);
    goto LABEL_14;
  }
  v2 = true;
  goto LABEL_6;
}

//------------------------------------------------------------------------------
// Address: 0x100EFB40
// Name: protected: virtual int COPTGeneral::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTGeneral::OnInitDialog(COPTGeneral *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  LRESULT v3; // eax
  char *v4; // eax
  char szAutosaveDir[260]; // [esp+8h] [ebp-114h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+10Ch] [ebp-10h] BYREF
  int v8; // [esp+118h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_AUTOSAVE, p: szAutosaveDir);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &str,
    pszSrc: szAutosaveDir);
  v8 = 0;
  this->m_nMaxCameras = Options.general.nMaxCameras;
  this->m_iUndoLevels = Options.general.iUndoLevels;
  this->m_iMaxAutosavesPerMap = Options.general.iMaxAutosavesPerMap;
  this->m_iMaxAutosaveSpace = Options.general.iMaxAutosaveSpace;
  this->m_iTimeBetweenSaves = Options.general.iTimeBetweenSaves;
  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_cEnableAutosave.m_hWnd, Msg: 0xF1u, wParam: Options.general.bEnableAutosave, lParam: 0);
  CWnd::SetWindowTextA(this: &this->m_cAutosaveDir, lpszString: str.m_pszData);
  SendMessageA(hWnd: this->m_UndoSpin.m_hWnd, Msg: 0x465u, wParam: 0, lParam: 328679);
  COPTGeneral::OnEnableAutosave(this);
  v3 = SendMessageA(hWnd: this->m_cIndependentWin.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_cLoadWinPos, bEnable: v3);
  v8 = -1;
  v4 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EFC80
// Name: protected: void COPTGeneral::OnBrowseAutosaveDir(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTGeneral::OnBrowseAutosaveDir(COPTGeneral *this@<ecx>, int a2@<ebx>)
{
  HWND__ *m_hWnd; // eax
  _ITEMIDLIST *v4; // esi
  char *v5; // eax
  char v6; // [esp+8h] [ebp-238h] BYREF
  char szTmp[260]; // [esp+10Ch] [ebp-134h] BYREF
  _browseinfoA bi; // [esp+210h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+230h] [ebp-10h] BYREF
  int v10; // [esp+23Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  memset(&bi.lpfn, 0, 12);
  bi.hwndOwner = m_hWnd;
  bi.pszDisplayName = &v6;
  bi.lpszTitle = "Select Autosave Directory";
  bi.ulFlags = 1;
  v4 = SHBrowseForFolderA(lpbi: &bi);
  if ( v4 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v4, pszPath: szTmp);
    CoTaskMemFree(pv: v4);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: szTmp);
    v10 = 0;
    EditorUtil_ConvertPath(a1: a2, a2: (int)this, a3: (int)v4, &str, bExpand: false);
    CWnd::SetWindowTextA(this: &this->m_cAutosaveDir, lpszString: str.m_pszData);
    v10 = -1;
    v5 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFD70
// Name: protected: virtual struct AFX_MSGMAP const __near * COPTGeneral::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COPTGeneral::GetMessageMap(COPTGeneral *this)
{
  return (const AFX_MSGMAP *)&off_105F06B0;
}
