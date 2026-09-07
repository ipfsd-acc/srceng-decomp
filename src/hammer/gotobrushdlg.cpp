// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/gotobrushdlg.cpp
// Functions: 3
// ============================================================

#include "hammer\gotobrushdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D0110
// Name: public: CGotoBrushDlg::CGotoBrushDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CGotoBrushDlg *__thiscall CGotoBrushDlg::CGotoBrushDlg(CGotoBrushDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x11Eu, pParentWnd: pParent);
  this->__vftable = (CGotoBrushDlg_vtbl *)&CGotoBrushDlg::`vftable';
  this->m_nBrushID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D0170
// Name: protected: virtual void CGotoBrushDlg::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CGotoBrushDlg::OnOK(CGotoBrushDlg *this)
{
  CDialog::OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D0180
// Name: protected: virtual void CGotoBrushDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGotoBrushDlg::DoDataExchange(CGotoBrushDlg *this, CDataExchange *pDX)
{
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_nBrushID);
}
