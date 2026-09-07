// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/fadedlg.cpp
// Functions: 8
// ============================================================

#include "hammer\fadedlg.h"

//------------------------------------------------------------------------------
// Address: 0x100CEB00
// Name: public: CFadeDlg::CFadeDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CFadeDlg *__thiscall CFadeDlg::CFadeDlg(CFadeDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x159u, pParentWnd: pParent);
  this->__vftable = (CFadeDlg_vtbl *)&CFadeDlg::`vftable';
  Options.view3d.nFadeMode = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CEB60
// Name: protected: void CFadeDlg::OnButtonFadeLow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFadeDlg::OnButtonFadeLow(CFadeDlg *this)
{
  Options.view3d.nFadeMode = 1;
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEB80
// Name: protected: void CFadeDlg::OnButtonFadeMed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFadeDlg::OnButtonFadeMed(CFadeDlg *this)
{
  Options.view3d.nFadeMode = 2;
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEBA0
// Name: protected: void CFadeDlg::OnButtonFadeHigh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFadeDlg::OnButtonFadeHigh(CFadeDlg *this)
{
  Options.view3d.nFadeMode = 3;
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEBC0
// Name: protected: void CFadeDlg::OnButtonFade360(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFadeDlg::OnButtonFade360(CFadeDlg *this)
{
  Options.view3d.nFadeMode = 4;
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEBE0
// Name: protected: void CFadeDlg::OnButtonFadeLevel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFadeDlg::OnButtonFadeLevel(CFadeDlg *this)
{
  Options.view3d.nFadeMode = 5;
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CEC50
// Name: public: virtual int CFadeDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFadeDlg::OnInitDialog(CFadeDlg *this)
{
  CWnd *m_pParentWnd; // ebx
  HWND__ *m_hWnd; // [esp-Ch] [ebp-44h]
  CRect toolbarRect; // [esp+8h] [ebp-30h] BYREF
  CRect buttonRect; // [esp+18h] [ebp-20h] BYREF
  CRect dialogRect; // [esp+28h] [ebp-10h] BYREF

  if ( this->m_pParentWnd != nullptr )
  {
    m_hWnd = this->m_hWnd;
    memset(&dialogRect, 0, sizeof(dialogRect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &dialogRect);
    m_pParentWnd = this->m_pParentWnd;
    memset(&toolbarRect, 0, sizeof(toolbarRect));
    GetWindowRect(hWnd: m_pParentWnd->m_hWnd, lpRect: &toolbarRect);
    memset(&buttonRect, 0, sizeof(buttonRect));
    SendMessageA(hWnd: m_pParentWnd->m_hWnd, Msg: 0x433u, wParam: 0x81B2u, lParam: (LPARAM)&buttonRect);
    SetWindowPos(
      hWnd: this->m_hWnd,
      hWndInsertAfter: nullptr,
      X: toolbarRect.left + buttonRect.left + (buttonRect.right - buttonRect.left) / 2,
      Y: toolbarRect.top + buttonRect.top + (buttonRect.bottom - buttonRect.top) / 2,
      cx: dialogRect.right - dialogRect.left,
      cy: dialogRect.bottom - dialogRect.top,
      uFlags: 0x100u);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CED20
// Name: protected: virtual struct AFX_MSGMAP const __near * CFadeDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFadeDlg::GetMessageMap(CFadeDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EBE64;
}
