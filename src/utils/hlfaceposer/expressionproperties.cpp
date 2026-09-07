// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/expressionproperties.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00448520
// Name: ExpressionPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall ExpressionPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND DlgItem; // eax

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_20, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1004, lpString: g_Params_20.m_szName);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1001, lpString: g_Params_20.m_szDescription);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_20.m_szDialogTitle);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1004);
    SetFocus(hWnd: DlgItem);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      g_Params_20.m_szName[0] = 0;
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1004, lpString: g_Params_20.m_szName, cchMax: 256);
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1001, lpString: g_Params_20.m_szDescription, cchMax: 256);
      EndDialog(hDlg: hwndDlg, nResult: 1);
    }
    else if ( wParam == 2 )
    {
      EndDialog(hDlg: hwndDlg, nResult: 0);
      return 1;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00448600
// Name: int ExpressionProperties(struct CExpressionParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl ExpressionProperties(CExpressionParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_20 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x68,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)ExpressionPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_20;
  return result;
}
