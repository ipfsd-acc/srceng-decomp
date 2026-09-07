// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/actorproperties.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041F670
// Name: ActorPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall ActorPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND DlgItem; // eax

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1000, lpString: g_Params.m_szName);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params.m_szDialogTitle);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1000);
    SetFocus(hWnd: DlgItem);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      g_Params.m_szName[0] = 0;
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1000, lpString: g_Params.m_szName, cchMax: 256);
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
// Address: 0x0041F720
// Name: int ActorProperties(struct CActorParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl ActorProperties(CActorParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x66,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)ActorPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params;
  return result;
}
