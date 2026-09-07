// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/channelproperties.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00422DE0
// Name: ChannelPropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall ChannelPropertiesDialogProc(HWND__ *hwndDlg, unsigned int uMsg, __int16 wParam, int lParam)
{
  HWND v5; // eax
  HWND v6; // edi
  HWND (__stdcall *v7)(HWND, int); // ebx
  HWND DlgItem; // eax
  HWND v9; // esi
  HWND v10; // eax
  int i; // edi
  CChoreoActor *Actor; // eax
  CChoreoActor *Name; // eax
  HWND v14; // eax

  if ( uMsg == 272 )
  {
    v6 = hwndDlg;
    CBaseDialogParams::PositionSelf(this: &g_Params_2, self: hwndDlg);
    SetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1005, lpString: g_Params_2.m_szName);
    v7 = GetDlgItem;
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
    v9 = DlgItem;
    if ( g_Params_2.m_bShowActors )
    {
      SendMessageA(hWnd: DlgItem, Msg: 0x14Bu, wParam: 0, lParam: 0);
      if ( g_Params_2.m_pScene != nullptr )
      {
        for ( i = 0; i < CChoreoScene::GetNumActors(this: g_Params_2.m_pScene); ++i )
        {
          Actor = CChoreoScene::GetActor(this: g_Params_2.m_pScene, actor: i);
          if ( Actor != nullptr )
          {
            Name = CChoreoActor::GetName(this: Actor);
            SendMessageA(hWnd: v9, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Name);
          }
        }
        v6 = hwndDlg;
      }
      SendMessageA(hWnd: v9, Msg: 0x14Eu, wParam: 0, lParam: 0);
      v7 = GetDlgItem;
    }
    else
    {
      if ( DlgItem != nullptr )
        ShowWindow(hWnd: DlgItem, nCmdShow: 0);
      v10 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1014);
      if ( v10 != nullptr )
        ShowWindow(hWnd: v10, nCmdShow: 0);
    }
    SetWindowTextA(hWnd: v6, lpString: g_Params_2.m_szDialogTitle);
    v14 = v7(hDlg: v6, nIDDlgItem: 1005);
    SetFocus(hWnd: v14);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      g_Params_2.m_szName[0] = 0;
      GetDlgItemTextA(hDlg: hwndDlg, nIDDlgItem: 1005, lpString: g_Params_2.m_szName, cchMax: 256);
      if ( g_Params_2.m_bShowActors )
      {
        v5 = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1013);
        if ( v5 != nullptr )
          SendMessageA(hWnd: v5, Msg: 0xDu, wParam: 0x100u, lParam: (LPARAM)g_Params_2.m_szSelectedActor);
      }
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
// Address: 0x00422F70
// Name: int ChannelProperties(struct CChannelParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl ChannelProperties(CChannelParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_2 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x69,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)ChannelPropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_2;
  return result;
}
