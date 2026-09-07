// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/globaleventproperties.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0045D0D0
// Name: ExtractAutoStateFromParams
// Source: json
//------------------------------------------------------------------------------
void __usercall ExtractAutoStateFromParams(CGlobalEventParams *params@<esi>)
{
  ParseFromMemory(buffer: params->m_szAction, size: strlen(params->m_szAction));
  params->m_bAutomate = false;
  if ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    params->m_bAutomate = _V_stricmp(s1: token, s2: "automate") == 0;
  }
  if ( params->m_bAutomate )
  {
    params->m_szType[0] = 0;
    if ( TokenAvailable() != 0 )
    {
      GetToken(crossline: 0);
      strcpy(params->m_szType, token);
    }
    params->m_flWaitTime = 0.0;
    if ( TokenAvailable() != 0 )
    {
      GetToken(crossline: 0);
      params->m_flWaitTime = atof(nptr: token);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D1A0
// Name: CreateAutoStateFromControls
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAutoStateFromControls(CGlobalEventParams *params@<eax>)
{
  if ( params->m_bAutomate )
    sprintf(string: params->m_szAction, format: "automate %s %f", params->m_szType, params->m_flWaitTime);
  else
    sprintf(string: params->m_szAction, format: "noaction");
}

//------------------------------------------------------------------------------
// Address: 0x0045D1F0
// Name: GlobalEventPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall GlobalEventPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND v5; // eax
  HWND v6; // eax
  const char *v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  void (__stdcall *v18)(HWND, UINT, WPARAM, LPARAM); // esi
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND DlgItem; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  const char *v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // eax
  __int64 m_bAutomate; // [esp+0h] [ebp-54h]
  char *v36; // [esp+4h] [ebp-50h]
  char *v37; // [esp+4h] [ebp-50h]
  char szLoop[32]; // [esp+14h] [ebp-40h] BYREF
  char szTime[32]; // [esp+34h] [ebp-20h] BYREF

  if ( uMsg == 272 )
  {
    CBaseDialogParams::PositionSelf(this: &g_Params_21, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1012, lpString: g_Params_21.m_szName);
    v7 = va(fmt: "%f", g_Params_21.m_flStartTime);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1015, lpString: v7);
    switch ( g_Params_21.m_nType )
    {
      case 1:
        DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1023);
        ShowWindow(hWnd: DlgItem, nCmdShow: 0);
        v26 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1054);
        ShowWindow(hWnd: v26, nCmdShow: 0);
        v27 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1016);
        ShowWindow(hWnd: v27, nCmdShow: 0);
        v28 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1055);
        ShowWindow(hWnd: v28, nCmdShow: 0);
        ExtractAutoStateFromParams(params: &g_Params_21);
        break;
      case 0xC:
        v36 = va(fmt: "%i", g_Params_21.m_nLoopCount);
        v17 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1023);
        v18 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
        SendMessageA(hWnd: v17, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v36);
        v37 = va(fmt: "%f", g_Params_21.m_flLoopTime);
        v19 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1016);
        SendMessageA(hWnd: v19, Msg: 0xCu, wParam: 0, lParam: (LPARAM)v37);
        v20 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
        ShowWindow(hWnd: v20, nCmdShow: 0);
        v21 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1021);
        ShowWindow(hWnd: v21, nCmdShow: 0);
        v22 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1019);
        ShowWindow(hWnd: v22, nCmdShow: 0);
        v23 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1056);
        ShowWindow(hWnd: v23, nCmdShow: 0);
        v24 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1057);
        ShowWindow(hWnd: v24, nCmdShow: 0);
LABEL_15:
        m_bAutomate = g_Params_21.m_bAutomate;
        v29 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1019);
        v18(hWnd: v29, Msg: 0xF1u, wParam: m_bAutomate, lParam: SHIDWORD(m_bAutomate));
        v30 = va(fmt: "%f", g_Params_21.m_flWaitTime);
        SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1021, lpString: v30);
        v31 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
        v18(hWnd: v31, Msg: 0xCu, wParam: 0, lParam: (LPARAM)g_Params_21.m_szType);
        v32 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
        v18(hWnd: v32, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Cancel");
        v33 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
        v18(hWnd: v33, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Resume");
        SetWindowTextA(hWnd: hwndDlg, lpString: g_Params_21.m_szDialogTitle);
        v34 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1012);
        SetFocus(hWnd: v34);
        return 0;
      case 0xE:
        v8 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1023);
        ShowWindow(hWnd: v8, nCmdShow: 0);
        v9 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1054);
        ShowWindow(hWnd: v9, nCmdShow: 0);
        v10 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1016);
        ShowWindow(hWnd: v10, nCmdShow: 0);
        v11 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1055);
        ShowWindow(hWnd: v11, nCmdShow: 0);
        v12 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
        ShowWindow(hWnd: v12, nCmdShow: 0);
        v13 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1021);
        ShowWindow(hWnd: v13, nCmdShow: 0);
        v14 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1019);
        ShowWindow(hWnd: v14, nCmdShow: 0);
        v15 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1056);
        ShowWindow(hWnd: v15, nCmdShow: 0);
        v16 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1057);
        ShowWindow(hWnd: v16, nCmdShow: 0);
        break;
      default:
        break;
    }
    v18 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
    goto LABEL_15;
  }
  if ( uMsg != 273 )
    return 0;
  if ( wParam == 1 )
  {
    v5 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1020);
    SendMessageA(hWnd: v5, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_21.m_szType);
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1021, lpString: szTime, cchMax: 32);
    g_Params_21.m_flWaitTime = atof(nptr: szTime);
    v6 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1019);
    g_Params_21.m_bAutomate = SendMessageA(hWnd: v6, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
    CreateAutoStateFromControls(params: &g_Params_21);
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1012, lpString: g_Params_21.m_szName, cchMax: 256);
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
    g_Params_21.m_flStartTime = atof(nptr: szTime);
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1023, lpString: szLoop, cchMax: 32);
    g_Params_21.m_nLoopCount = atoi(nptr: szLoop);
    GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1016, lpString: szLoop, cchMax: 32);
    g_Params_21.m_flLoopTime = atof(nptr: szLoop);
    EndDialog(hDlg: hwndDlg, nResult: 1);
  }
  else if ( wParam == 2 )
  {
    EndDialog(hDlg: hwndDlg, nResult: 0);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D5D0
// Name: int GlobalEventProperties(struct CGlobalEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl GlobalEventProperties(CGlobalEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_21 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x6C,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)GlobalEventPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_21;
  return result;
}
