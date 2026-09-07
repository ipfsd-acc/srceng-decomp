// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/strdlg.cpp
// Functions: 5
// ============================================================

#include "hammer\strdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D3F70
// Name: protected: virtual struct AFX_MSGMAP const __near * CStrDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CStrDlg::GetMessageMap(CManifestMapDlg *this)
{
  return (const AFX_MSGMAP *)&off_105ECD2C;
}

//------------------------------------------------------------------------------
// Address: 0x10100340
// Name: public: void CStrDlg::SetRange(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStrDlg::SetRange(CStrDlg *this, int iLow, int iHigh, int iIncrement)
{
  this->iRangeLow = iLow;
  this->iRangeHigh = iHigh;
  this->iIncrement = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10100370
// Name: protected: virtual void CStrDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStrDlg::DoDataExchange(CStrDlg *this, CDataExchange *pDX)
{
  DDX_Text(pDX, nIDC: (HWND__ *)0x492, value: &this->m_strPrompt);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_string);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_cEdit);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_cSpin);
}

//------------------------------------------------------------------------------
// Address: 0x101003D0
// Name: protected: virtual int CStrDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStrDlg::OnInitDialog(CStrDlg *this)
{
  CSpinButtonCtrl *p_m_cSpin; // ecx
  void *p_m_cEdit; // eax
  HWND__ *v4; // eax

  CDialog::OnInitDialog(this);
  p_m_cSpin = &this->m_cSpin;
  if ( (this->dwFlags & 1) != 0 )
  {
    CWnd::EnableWindow(this: p_m_cSpin, bEnable: 1);
    SendMessageA(
      hWnd: this->m_cSpin.m_hWnd,
      Msg: 0x465u,
      wParam: 0,
      lParam: LOWORD(this->iRangeHigh) | (LOWORD(this->iRangeLow) << 16));
    p_m_cEdit = &this->m_cEdit;
    if ( this != (CStrDlg *)-408 )
      p_m_cEdit = this->m_cEdit.m_hWnd;
    v4 = (HWND__ *)SendMessageA(hWnd: this->m_cSpin.m_hWnd, Msg: 0x469u, wParam: (WPARAM)p_m_cEdit, lParam: 0);
    CWnd::FromHandle(hWnd: v4);
  }
  else
  {
    CWnd::ShowWindow(this: p_m_cSpin, nCmdShow: 0);
  }
  CWnd::SetWindowTextA(this, lpszString: this->m_strTitle.m_pszData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10100460
// Name: public: CStrDlg::CStrDlg(unsigned long,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CStrDlg *__thiscall CStrDlg::CStrDlg(
        CStrDlg *this,
        unsigned int dwFlags,
        const char *pszString,
        const char *pszPrompt,
        const char *pszTitle)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v7; // eax
  CAfxStringMgr *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax

  CDialog::CDialog(this, nIDTemplate: 0xC6u, pParentWnd: nullptr);
  this->__vftable = (CStrDlg_vtbl *)&CStrDlg::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_string.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v7 = AfxGetStringManager();
  if ( v7 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strPrompt.m_pszData = (char *)&v7->GetNilString(this: v7)[1];
  v8 = AfxGetStringManager();
  if ( v8 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strTitle.m_pszData = (char *)&v8->GetNilString(this: v8)[1];
  CWnd::CWnd(this: &this->m_cSpin);
  this->m_cSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  CWnd::CWnd(this: &this->m_cPrompt);
  this->m_cPrompt.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cEdit);
  this->m_cEdit.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_string, pszSrc: &var, nLength: 0);
  this->dwFlags = dwFlags;
  this->iRangeLow = 0;
  this->iRangeHigh = 10;
  this->iIncrement = 1;
  if ( pszString != nullptr )
    v9 = strlen(pszString);
  else
    v9 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_string, pszSrc: pszString, nLength: v9);
  if ( pszPrompt != nullptr )
    v10 = strlen(pszPrompt);
  else
    v10 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strPrompt, pszSrc: pszPrompt, nLength: v10);
  if ( pszTitle != nullptr )
    v11 = strlen(pszTitle);
  else
    v11 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strTitle, pszSrc: pszTitle, nLength: v11);
  return this;
}
