// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/inputproperties.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00408210
// Name: InputPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall InputPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND DlgItem; // eax
  HWND v6; // eax

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1000, lpString: g_Params.m_szInputText);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1001, lpString: g_Params.m_szPrompt);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params.m_szDialogTitle);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1000);
    SetFocus(hWnd: DlgItem);
    v6 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1000);
    SendMessageA(hWnd: v6, Msg: 0xB1u, wParam: 0, lParam: -65536);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      g_Params.m_szInputText[0] = 0;
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1000, lpString: g_Params.m_szInputText, cchMax: 1024);
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
// Address: 0x004082F0
// Name: int InputProperties(struct CInputParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl InputProperties(CInputParams *params)
{
  CWorkspaceManager *WorkspaceManager; // eax
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params = *params;
  WorkspaceManager = GetWorkspaceManager();
  Handle = (HWND)mxWidget::getHandle(this: WorkspaceManager);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x6E,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)InputPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params;
  return result;
}
