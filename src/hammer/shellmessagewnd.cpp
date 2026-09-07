// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/shellmessagewnd.cpp
// Functions: 3
// ============================================================

#include "hammer\shellmessagewnd.h"

//------------------------------------------------------------------------------
// Address: 0x1014DDE0
// Name: protected: int CShellMessageWnd::OnCopyData(class CWnd __near *,struct tagCOPYDATASTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShellMessageWnd::OnCopyData(CShellMessageWnd *this, CWnd *pWnd, tagCOPYDATASTRUCT *pCopyData)
{
  CShell *m_pShell; // ecx

  m_pShell = this->m_pShell;
  return m_pShell != nullptr
      && pCopyData->lpData != nullptr
      && CShell::RunCommand(this: m_pShell, pszCommand: (const char *)pCopyData->lpData);
}

//------------------------------------------------------------------------------
// Address: 0x1014DE10
// Name: public: bool CShellMessageWnd::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShellMessageWnd::Create(CShellMessageWnd *this)
{
  tagWNDCLASSA wndcls; // [esp+8h] [ebp-38h] BYREF
  tagRECT rect; // [esp+30h] [ebp-10h] BYREF

  memset(&wndcls.cbClsExtra, 0, 32);
  wndcls.style = 0;
  wndcls.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))AfxGetAfxWndProc();
  wndcls.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  wndcls.lpszClassName = g_pszClassName;
  if ( AfxRegisterClass(lpWndClass: &wndcls) != 0 )
  {
    rect.right = 10;
    rect.bottom = 10;
    rect.left = 0;
    rect.top = 0;
    return CWnd::CreateEx(
             this,
             dwExStyle: 0,
             lpszClassName: g_pszClassName,
             lpszWindowName: g_pszClassName,
             dwStyle: 0,
             &rect,
             pParentWnd: nullptr,
             nID: nullptr,
             lpParam: nullptr) == 1;
  }
  else
  {
    AfxMessageBox(lpszText: "Could not register the Hammer shell message window class.", nType: 0, nIDHelp: 0);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DEC0
// Name: protected: virtual struct AFX_MSGMAP const __near * CShellMessageWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CShellMessageWnd::GetMessageMap(CShellMessageWnd *this)
{
  return (const AFX_MSGMAP *)&off_105FA328;
}
