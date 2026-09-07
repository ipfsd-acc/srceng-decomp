// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/transformdlg.cpp
// Functions: 2
// ============================================================

#include "hammer\transformdlg.h"

//------------------------------------------------------------------------------
// Address: 0x10103FB0
// Name: public: CTransformDlg::CTransformDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CTransformDlg *__thiscall CTransformDlg::CTransformDlg(CTransformDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x72u, pParentWnd: pParent);
  this->__vftable = (CTransformDlg_vtbl *)&CTransformDlg::`vftable';
  this->m_iMode = -1;
  this->m_X = 0.0;
  this->m_Y = 0.0;
  this->m_Z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10104030
// Name: protected: virtual void CTransformDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransformDlg::DoDataExchange(CTransformDlg *this, CDataExchange *pDX)
{
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x4FA, value: (HWND__ **)&this->m_iMode);
  DDX_Text(pDX, nIDC: (HWND__ *)0x72, value: (CDataExchange *)&this->m_X);
  DDX_Text(pDX, nIDC: (HWND__ *)0x73, value: (CDataExchange *)&this->m_Y);
  DDX_Text(pDX, nIDC: (HWND__ *)0x74, value: (CDataExchange *)&this->m_Z);
}
