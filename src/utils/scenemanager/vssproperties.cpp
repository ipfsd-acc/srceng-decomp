// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/vssproperties.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004142C0
// Name: VSSPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall VSSPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND DlgItem; // eax
  HWND v6; // eax

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_3, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1002, lpString: g_Params_3.m_szUserName);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1003, lpString: g_Params_3.m_szProject);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_3.m_szDialogTitle);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1002);
    SetFocus(hWnd: DlgItem);
    v6 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1002);
    SendMessageA(hWnd: v6, Msg: 0xB1u, wParam: 0, lParam: -65536);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      g_Params_3.m_szUserName[0] = 0;
      g_Params_3.m_szProject[0] = 0;
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1002, lpString: g_Params_3.m_szUserName, cchMax: 256);
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1003, lpString: g_Params_3.m_szProject, cchMax: 256);
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
// Address: 0x004143C0
// Name: int VSSProperties(struct CVSSParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl VSSProperties(CVSSParams *params)
{
  CWorkspaceManager *WorkspaceManager; // eax
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_3 = *params;
  WorkspaceManager = GetWorkspaceManager();
  Handle = (HWND)mxWidget::getHandle(this: WorkspaceManager);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x71,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)VSSPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_3;
  return result;
}
