// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_services_watch/setpassworddlg.cpp
// Functions: 3
// ============================================================

#include "utils\vmpi\vmpi_services_watch\setpassworddlg.h"

//------------------------------------------------------------------------------
// Address: 0x00405B50
// Name: protected: virtual void CSetPasswordDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSetPasswordDlg::DoDataExchange(CSetPasswordDlg *this, CDataExchange *pDX)
{
  DDX_Text(pDX, nIDC: (HWND__ *)0x3E9, value: &this->m_Password);
}

//------------------------------------------------------------------------------
// Address: 0x00405B70
// Name: protected: virtual struct AFX_MSGMAP const __near * CSetPasswordDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSetPasswordDlg::GetMessageMap(CPatchTimeout *this)
{
  return (const AFX_MSGMAP *)&off_52BBB8;
}

//------------------------------------------------------------------------------
// Address: 0x00405B80
// Name: public: CSetPasswordDlg::CSetPasswordDlg(int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSetPasswordDlg *__thiscall CSetPasswordDlg::CSetPasswordDlg(CSetPasswordDlg *this, unsigned int dlgID, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax

  CDialog::CDialog(this, nIDTemplate: dlgID, pParentWnd: pParent);
  this->__vftable = (CSetPasswordDlg_vtbl *)&CSetPasswordDlg::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_Password.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_Password, pszSrc: szGroupName, nLength: 0);
  return this;
}
