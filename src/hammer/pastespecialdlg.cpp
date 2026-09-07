// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/pastespecialdlg.cpp
// Functions: 10
// ============================================================

#include "hammer\pastespecialdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F1F90
// Name: protected: virtual int CPasteSpecialDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPasteSpecialDlg::OnInitDialog(CPasteSpecialDlg *this)
{
  CWnd *DlgItem; // eax
  BOOL v4; // [esp-4h] [ebp-8h]

  v4 = this->m_bAddPrefix != 0;
  DlgItem = CWnd::GetDlgItem(this, nID: 1009);
  CWnd::EnableWindow(this: DlgItem, bEnable: v4);
  return CDialog::OnInitDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F1FC0
// Name: protected: virtual void CPasteSpecialDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::DoDataExchange(CPasteSpecialDlg *this, CDataExchange *pDX)
{
  int *p_m_iCopies; // ebx

  p_m_iCopies = &this->m_iCopies;
  DDX_Text(pDX, nIDC: (HWND__ *)0x494, value: &this->m_iCopies);
  DDV_MinMaxInt(pDX, value: *p_m_iCopies, minVal: 1, maxVal: 256);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x49B, value: &this->m_bGroup);
  DDX_Text(pDX, nIDC: (HWND__ *)0x495, value: &this->m_iOffsetX);
  DDX_Text(pDX, nIDC: (HWND__ *)0x496, value: &this->m_iOffsetY);
  DDX_Text(pDX, nIDC: (HWND__ *)0x497, value: &this->m_iOffsetZ);
  DDX_Text(pDX, nIDC: (HWND__ *)0x49C, value: (CDataExchange *)&this->m_fRotateX);
  DDV_MinMaxFloat(pDX, value: &this->m_fRotateX, minVal: 0.0, maxVal: 360.0);
  DDX_Text(pDX, nIDC: (HWND__ *)0x49E, value: (CDataExchange *)&this->m_fRotateZ);
  DDV_MinMaxFloat(pDX, value: &this->m_fRotateZ, minVal: 0.0, maxVal: 360.0);
  DDX_Text(pDX, nIDC: (HWND__ *)0x49D, value: (CDataExchange *)&this->m_fRotateY);
  DDV_MinMaxFloat(pDX, value: &this->m_fRotateY, minVal: 0.0, maxVal: 360.0);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x49F, value: &this->m_bCenterOriginal);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x66E, value: &this->m_bMakeEntityNamesUnique);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x66F, value: &this->m_bAddPrefix);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_strPrefix);
}

//------------------------------------------------------------------------------
// Address: 0x100F2120
// Name: protected: void CPasteSpecialDlg::OnCheckUncheckAddPrefix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::OnCheckUncheckAddPrefix(CPasteSpecialDlg *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // eax
  LRESULT v4; // [esp-4h] [ebp-8h]

  DlgItem = CWnd::GetDlgItem(this, nID: 1647);
  v4 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  v3 = CWnd::GetDlgItem(this, nID: 1009);
  CWnd::EnableWindow(this: v3, bEnable: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F2160
// Name: public: void CPasteSpecialDlg::SaveToIni(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::SaveToIni(CPasteSpecialDlg *this)
{
  CWinApp *m_pCurrentWinApp; // esi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // ebx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v5; // [esp+24h] [ebp-10h] BYREF
  int v6; // [esp+30h] [ebp-4h]

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v5.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = 1;
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszIni, a3: "Copies", a4: this->m_iCopies);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszIni, a3: "Group", a4: this->m_bGroup);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &v5,
    pszFormat: "%d %d %d",
    this->m_iOffsetX,
    this->m_iOffsetY,
    this->m_iOffsetZ);
  m_pCurrentWinApp->WriteProfileStringA(this: m_pCurrentWinApp, a2: pszIni, a3: "Offset", a4: v5.m_pszData);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &v5,
    pszFormat: "%.1f %.1f %.1f",
    this->m_fRotateX,
    this->m_fRotateY,
    this->m_fRotateZ);
  m_pszData = v5.m_pszData;
  m_pCurrentWinApp->WriteProfileStringA(this: m_pCurrentWinApp, a2: pszIni, a3: "Rotate", a4: v5.m_pszData);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszIni, a3: "Center", a4: this->m_bCenterOriginal);
  m_pCurrentWinApp->WriteProfileInt(
    this: m_pCurrentWinApp,
    a2: pszIni,
    a3: "MakeNamesUnique",
    a4: this->m_bMakeEntityNamesUnique);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszIni, a3: "AddPrefix", a4: this->m_bAddPrefix);
  m_pCurrentWinApp->WriteProfileStringA(
    this: m_pCurrentWinApp,
    a2: pszIni,
    a3: "Prefix",
    a4: this->m_strPrefix.m_pszData);
  v6 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100F2350
// Name: protected: void CPasteSpecialDlg::GetOffset(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::GetOffset(CPasteSpecialDlg *this, int iAxis, const char *iEditCtrl)
{
  CWnd *DlgItem; // edi
  CAfxStringMgr *StringManager; // eax
  int v6; // eax
  float v7; // xmm0_4
  const char *v8; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: (int)iEditCtrl);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  iEditCtrl = (const char *)&StringManager->GetNilString(this: StringManager)[1];
  CWnd::GetWindowTextA(
    this: DlgItem,
    rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&iEditCtrl);
  v6 = atoi(nptr: iEditCtrl);
  v7 = *(&this->ObjectsBox.bmaxs.x + iAxis) - *(&this->ObjectsBox.bmins.x + iAxis);
  if ( v6 == (int)v7 )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&iEditCtrl,
      pszFormat: "%d",
      -(int)v7);
  else
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&iEditCtrl,
      pszFormat: "%d",
      (int)v7);
  CWnd::SetWindowTextA(this: DlgItem, lpszString: iEditCtrl);
  v8 = iEditCtrl - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)iEditCtrl - 1) <= 0 )
    (*(void (__stdcall **)(const char *))(**(_DWORD **)v8 + 4))(a1: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100F2440
// Name: protected: void CPasteSpecialDlg::OnGetoffsetx(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::OnGetoffsetx(CPasteSpecialDlg *this)
{
  CPasteSpecialDlg::GetOffset(this, iAxis: 0, iEditCtrl: (const char *)0x495);
}

//------------------------------------------------------------------------------
// Address: 0x100F2450
// Name: protected: void CPasteSpecialDlg::OnGetoffsety(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::OnGetoffsety(CPasteSpecialDlg *this)
{
  CPasteSpecialDlg::GetOffset(this, iAxis: 1, iEditCtrl: (const char *)0x496);
}

//------------------------------------------------------------------------------
// Address: 0x100F2460
// Name: protected: void CPasteSpecialDlg::OnGetoffsetz(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPasteSpecialDlg::OnGetoffsetz(CPasteSpecialDlg *this)
{
  CPasteSpecialDlg::GetOffset(this, iAxis: 2, iEditCtrl: (const char *)0x497);
}

//------------------------------------------------------------------------------
// Address: 0x100F2470
// Name: public: CPasteSpecialDlg::CPasteSpecialDlg(class CWnd __near *,class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
CPasteSpecialDlg *__thiscall CPasteSpecialDlg::CPasteSpecialDlg(
        CPasteSpecialDlg *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pParent,
        BoundBox *pBox)
{
  CAfxStringMgr *StringManager; // eax
  CWinApp *m_pCurrentWinApp; // edi
  CAfxStringMgr *v6; // eax
  int v7; // eax
  const char *v8; // ecx
  int v9; // eax
  const char *v10; // ecx
  ATL::CStringData *v11; // eax
  int v12; // eax
  char *v13; // ebx
  int v14; // eax
  int v15; // eax
  ATL::CStringData *v16; // eax
  int v17; // eax
  char *v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  const char *v22; // ecx
  int v23; // eax
  const char *v24; // ecx
  int v25; // eax
  const char *v26; // ecx
  ATL::CStringData *v27; // eax
  int v28; // eax
  BoundBox *v29; // eax
  volatile signed __int32 *v30; // ebx
  int v32; // [esp+10h] [ebp-10h] BYREF
  int v33; // [esp+1Ch] [ebp-4h]

  CDialog::CDialog(this, nIDTemplate: 0xC8u, pParentWnd: (CWnd *)pParent);
  v33 = 0;
  this->__vftable = (CPasteSpecialDlg_vtbl *)&CPasteSpecialDlg::`vftable';
  pParent = &this->m_strPrefix;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strPrefix.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  LOBYTE(v33) = 2;
  BoundBox::BoundBox(this: &this->ObjectsBox);
  this->m_iCopies = 1;
  this->m_bGroup = 0;
  this->m_iOffsetX = 0;
  this->m_iOffsetY = 0;
  this->m_iOffsetZ = 0;
  this->m_fRotateX = 0.0;
  this->m_fRotateZ = 0.0;
  this->m_fRotateY = 0.0;
  this->m_bCenterOriginal = 1;
  this->m_bMakeEntityNamesUnique = 0;
  this->m_bAddPrefix = 0;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pParent = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v6->GetNilString(this: v6)[1];
  LOBYTE(v33) = 4;
  v7 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: pszIni, a3: "Copies", a4: 1);
  v8 = pszIni;
  this->m_iCopies = v7;
  v9 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v8, a3: "Group", a4: 0);
  v10 = pszIni;
  this->m_bGroup = v9;
  v11 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v32,
                              a3: v10,
                              a4: "Offset",
                              a5: "0 0 0");
  LOBYTE(v33) = 5;
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v11);
  LOBYTE(v33) = 4;
  v12 = v32 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v32 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v12 + 4))(a1: v12);
  v13 = (char *)pParent;
  if ( (((1 - (unsigned int)pParent[-1].m_pszData) | (unsigned int)pParent[-2].m_pszData) & 0x80000000) != 0 )
  {
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this: (ATL::CSimpleStringT<char,0> *)&pParent, nLength: 0);
    v13 = (char *)pParent;
  }
  this->m_iOffsetX = atoi(nptr: v13);
  strchr(string: v13, chr: 0x20u);
  this->m_iOffsetY = atoi(nptr: (const char *)(v14 + 1));
  strrchr(string: (unsigned __int8 *)v13, chr: 0x20u);
  this->m_iOffsetZ = atoi(nptr: (const char *)(v15 + 1));
  v16 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v32,
                              a3: pszIni,
                              a4: "Rotate",
                              a5: "0 0 0");
  LOBYTE(v33) = 7;
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v16);
  LOBYTE(v33) = 4;
  v17 = v32 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v32 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v17 + 4))(a1: v17);
  v18 = (char *)pParent;
  if ( (((1 - (unsigned int)pParent[-1].m_pszData) | (unsigned int)pParent[-2].m_pszData) & 0x80000000) != 0 )
  {
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this: (ATL::CSimpleStringT<char,0> *)&pParent, nLength: 0);
    v18 = (char *)pParent;
  }
  this->m_fRotateX = atof(nptr: v18);
  strchr(string: v18, chr: 0x20u);
  this->m_fRotateY = atof(nptr: (const char *)(v19 + 1));
  strrchr(string: (unsigned __int8 *)v18, chr: 0x20u);
  this->m_fRotateZ = atof(nptr: (const char *)(v20 + 1));
  v21 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: pszIni, a3: "Center", a4: 1);
  v22 = pszIni;
  this->m_bCenterOriginal = v21;
  v23 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v22, a3: "MakeNamesUnique", a4: 0);
  v24 = pszIni;
  this->m_bMakeEntityNamesUnique = v23;
  v25 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: v24, a3: "AddPrefix", a4: 0);
  v26 = pszIni;
  this->m_bAddPrefix = v25;
  v27 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                              this: m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v32,
                              a3: v26,
                              a4: "Prefix",
                              a5: &var);
  LOBYTE(v33) = 9;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strPrefix, strSrc: v27);
  LOBYTE(v33) = 4;
  v28 = v32 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v32 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v28 + 4))(a1: v28);
  v29 = pBox;
  this->ObjectsBox.bmins = pBox->bmins;
  this->ObjectsBox.bmaxs = v29->bmaxs;
  LOBYTE(v33) = 2;
  v30 = (volatile signed __int32 *)(v18 - 16);
  if ( _InterlockedDecrement(v30 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v30 + 4))(a1: v30);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F28A0
// Name: protected: virtual struct AFX_MSGMAP const __near * CPasteSpecialDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CPasteSpecialDlg::GetMessageMap(CPasteSpecialDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F13EC;
}
