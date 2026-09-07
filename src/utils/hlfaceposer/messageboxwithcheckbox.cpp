// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/messageboxwithcheckbox.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00464DB0
// Name: MessageBoxWithCheckBoxPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall MessageBoxWithCheckBoxPropertiesDialogProc(
        HWND__ *hwndDlg,
        unsigned int uMsg,
        __int16 wParam,
        int lParam)
{
  HWND v5; // eax
  HWND DlgItem; // eax
  WPARAM m_bChecked; // [esp-Ch] [ebp-10h]

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_23, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1003, lpString: g_Params_23.m_szPrompt);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1086, lpString: g_Params_23.m_szCheckBoxText);
    m_bChecked = g_Params_23.m_bChecked;
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1086);
    SendMessageA(hWnd: DlgItem, Msg: 0xF1u, wParam: m_bChecked, lParam: 0);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_23.m_szDialogTitle);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      v5 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1086);
      g_Params_23.m_bChecked = SendMessageA(hWnd: v5, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
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
// Address: 0x00464E90
// Name: int MessageBoxWithCheckBox(struct CMessageBoxWithCheckBoxParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl MessageBoxWithCheckBox(CMessageBoxWithCheckBoxParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_23 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x88,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)MessageBoxWithCheckBoxPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_23;
  return result;
}
