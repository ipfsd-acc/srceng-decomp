// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/multiplerequest.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00408680
// Name: MultipleRequestDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall MultipleRequestDialogProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned __int16 wParam, int lParam)
{
  HWND DlgItem; // eax
  HWND v6; // eax

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_0, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1023, lpString: g_Params_0.m_szPrompt);
    SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_0.m_szDialogTitle);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1000);
    SetFocus(hWnd: DlgItem);
    v6 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1000);
    SendMessageA(hWnd: v6, Msg: 0xB1u, wParam: 0, lParam: -65536);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam > 0x400u )
    {
      if ( wParam == 1025 )
        EndDialog(hDlg: hwndDlg, nResult: 1);
    }
    else
    {
      switch ( wParam )
      {
        case 0x400u:
          EndDialog(hDlg: hwndDlg, nResult: 0);
          return 1;
        case 3u:
          EndDialog(hDlg: hwndDlg, nResult: 2);
          return 1;
        case 4u:
          EndDialog(hDlg: hwndDlg, nResult: 3);
          return 1;
        default:
          break;
      }
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408770
// Name: void MultipleRequestChangeContext(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MultipleRequestChangeContext()
{
  ++g_MRContext;
}

//------------------------------------------------------------------------------
// Address: 0x00408780
// Name: int _MultipleRequest(struct CMultipleParams __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _MultipleRequest(CMultipleParams *params)
{
  INT_PTR v1; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  HMODULE ModuleHandleA; // eax
  int result; // eax
  HWND Handle; // [esp-18h] [ebp-18h]

  if ( g_MRCurrentContext != g_MRContext )
    goto LABEL_6;
  v1 = g_MRLastResult;
  if ( g_MRLastResult == -1 )
    goto LABEL_6;
  if ( g_MRLastResult != 0 )
  {
    if ( g_MRLastResult == 3 )
    {
      v1 = 1;
    }
    else
    {
LABEL_6:
      g_Params_0 = *params;
      WorkspaceManager = GetWorkspaceManager();
      Handle = (HWND)mxWidget::getHandle(this: WorkspaceManager);
      ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
      v1 = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x78,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)MultipleRequestDialogProc,
             dwInitParam: 0);
      *params = g_Params_0;
    }
  }
  g_MRCurrentContext = g_MRContext;
  g_MRLastResult = v1;
  switch ( v1 )
  {
    case 0:
    case 1:
      result = 0;
      break;
    case 2:
    case 3:
      result = 1;
      break;
    default:
      result = 2;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408840
// Name: int MultipleRequest(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MultipleRequest(const char *prompt)
{
  CMultipleParams params; // [esp+0h] [ebp-18Ch] BYREF

  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  _V_strcpy(dest: params.m_szDialogTitle, src: g_appTitle);
  V_strncpy(pDest: params.m_szPrompt, pSrc: prompt, maxLen: 256);
  return _MultipleRequest(&params);
}
