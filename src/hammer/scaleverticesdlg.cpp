// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/scaleverticesdlg.cpp
// Functions: 8
// ============================================================

#include "hammer\scaleverticesdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F6840
// Name: public: CScaleVerticesDlg::CScaleVerticesDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CScaleVerticesDlg *__thiscall CScaleVerticesDlg::CScaleVerticesDlg(CScaleVerticesDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xE9u, pParentWnd: pParent);
  this->__vftable = (CScaleVerticesDlg_vtbl *)&CScaleVerticesDlg::`vftable';
  CWnd::CWnd(this: &this->m_cScaleSpin);
  this->m_cScaleSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  CWnd::CWnd(this: &this->m_cScale);
  this->m_cScale.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F68D0
// Name: public: virtual CScaleVerticesDlg::~CScaleVerticesDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScaleVerticesDlg::~CScaleVerticesDlg(CScaleVerticesDlg *this)
{
  CEdit::~CEdit(this: &this->m_cScale);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_cScaleSpin);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F69A0
// Name: protected: virtual void CScaleVerticesDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScaleVerticesDlg::DoDataExchange(CScaleVerticesDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_cScaleSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x515, rControl: (HWND__ *)&this->m_cScale);
}

//------------------------------------------------------------------------------
// Address: 0x100F69E0
// Name: protected: virtual int CScaleVerticesDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScaleVerticesDlg::OnInitDialog(CScaleVerticesDlg *this)
{
  CDialog::OnInitDialog(this);
  CWnd::SetWindowTextA(this: &this->m_cScale, lpszString: "1.0");
  SendMessageA(hWnd: this->m_cScaleSpin.m_hWnd, Msg: 0x465u, wParam: 0, lParam: -2147385345);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F6A20
// Name: protected: void CScaleVerticesDlg::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CScaleVerticesDlg::OnClose(CScaleVerticesDlg *this)
{
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F6A30
// Name: protected: void CScaleVerticesDlg::OnChangeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScaleVerticesDlg::OnChangeScale(CScaleVerticesDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  long double v3; // st7
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = 1;
  CWnd::GetWindowTextA(this: &this->m_cScale, rString: &str);
  v3 = atof(nptr: str.m_pszData);
  this->m_fScale = v3;
  if ( v3 <= 0.0 )
    this->m_fScale = 0.0049999999;
  CMapDoc::m_pMapDoc->OnCmdMsg(this: CMapDoc::m_pMapDoc, a2: 115u, a3: 0, a4: nullptr, a5: nullptr);
  v6 = -1;
  v4 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F6B00
// Name: protected: void CScaleVerticesDlg::OnDeltaposScalespin(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScaleVerticesDlg::OnDeltaposScalespin(CScaleVerticesDlg *this, tagNMHDR *pNMHDR, int *pResult)
{
  CAfxStringMgr *StringManager; // eax
  float v5; // xmm0_4
  char *v6; // eax
  float v7; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > rString; // [esp+14h] [ebp-10h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  rString.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  CWnd::GetWindowTextA(this: &this->m_cScale, &rString);
  v7 = atof(nptr: rString.m_pszData);
  this->m_fScale = v7;
  v5 = (float)((float)(int)pNMHDR[1].idFrom * 0.1) + v7;
  this->m_fScale = v5;
  if ( v5 <= 0.0 )
    this->m_fScale = 0.0;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &rString,
    pszFormat: "%.3f",
    this->m_fScale);
  CWnd::SetWindowTextA(this: &this->m_cScale, lpszString: rString.m_pszData);
  *pResult = 0;
  v9 = -1;
  v6 = rString.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)rString.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100F6C20
// Name: protected: virtual struct AFX_MSGMAP const __near * CScaleVerticesDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CScaleVerticesDlg::GetMessageMap(CScaleVerticesDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F2800;
}
