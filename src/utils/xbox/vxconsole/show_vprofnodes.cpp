// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/show_vprofnodes.cpp
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00420B50
// Name: void PixTraceDlg_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixTraceDlg_LoadConfig()
{
  char szFilename[260]; // [esp+0h] [ebp-104h] BYREF

  V_ComposeFileName(path: g_localPath, filename: "capture.pix2", dest: szFilename, destSize: 260);
  Sys_GetRegistryString(
    keyName: "pixTraceCaptureFilename",
    value: g_pixTraceDlg_captureFilename,
    defValue: szFilename,
    valueLen: 0x104u);
  Sys_GetRegistryInteger(keyName: "pixTraceLaunchPix", defValue: 1, value: &g_pixTraceDlg_launchPix);
}

//------------------------------------------------------------------------------
// Address: 0x00420BB0
// Name: void PixTraceDlg_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixTraceDlg_SaveConfig()
{
  Sys_SetRegistryString(keyName: "pixTraceCaptureFilename", value: g_pixTraceDlg_captureFilename);
  Sys_SetRegistryInteger(keyName: "pixTraceLaunchPix", value: g_pixTraceDlg_launchPix);
}

//------------------------------------------------------------------------------
// Address: 0x00420BE0
// Name: bool PixTraceDlg_GetChanges(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PixTraceDlg_GetChanges(HWND__ *hWnd)
{
  GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1100, lpString: g_pixTraceDlg_captureFilename, cchMax: 260);
  g_pixTraceDlg_launchPix = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1083);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00420C20
// Name: void PixTraceDlg_BrowseCaptureFilename(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixTraceDlg_BrowseCaptureFilename(HWND__ *hWnd)
{
  char szFixedName[260]; // [esp+4h] [ebp-364h] BYREF
  char szFilename[260]; // [esp+108h] [ebp-260h] BYREF
  char szInitialDir[260]; // [esp+20Ch] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+310h] [ebp-58h] BYREF

  GetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1100, lpString: szInitialDir, cchMax: 260);
  V_StripFilename(path: szInitialDir);
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = hWnd;
  ofn.lpstrFile = szFilename;
  szFilename[0] = 0;
  ofn.nMaxFile = 260;
  ofn.lpstrFilter = "PIX Files";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = nullptr;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = szInitialDir;
  ofn.Flags = 2048;
  if ( GetSaveFileNameA(a1: &ofn) )
  {
    Sys_StripExtension(inpath: szFilename, outpath: szFixedName, outPathLen: 0x104u);
    Sys_AddExtension(extension: ".pix2", outpath: szFixedName, outPathLen: 0x104u, bForce: false);
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1100, lpString: szFixedName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420D10
// Name: int PixTraceDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall PixTraceDlg_Proc(HWND__ *hWnd, unsigned int message, INT_PTR wParam, int lParam)
{
  if ( message == 272 )
  {
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1101, lpString: g_pixTraceDlg_selectedNodeName);
    SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1100, lpString: g_pixTraceDlg_captureFilename);
    CheckDlgButton(hDlg: hWnd, nIDButton: 1083, uCheck: g_pixTraceDlg_launchPix != 0);
    return 1;
  }
  else
  {
    if ( message == 273 )
    {
      if ( (unsigned __int16)wParam > 0x3FCu )
      {
        if ( (unsigned __int16)wParam == 1098 )
          PixTraceDlg_BrowseCaptureFilename(hWnd);
      }
      else
      {
        if ( (unsigned __int16)wParam == 1020 || (unsigned __int16)wParam == 2 )
          goto LABEL_9;
        if ( (unsigned __int16)wParam == 1019 && PixTraceDlg_GetChanges(hWnd) != 0 )
        {
          PixTraceDlg_SaveConfig();
LABEL_9:
          EndDialog(hDlg: hWnd, nResult: wParam);
          return 1;
        }
      }
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420DD0
// Name: void PixTraceDlg_Open(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixTraceDlg_Open(HWND__ *hWndParent)
{
  LRESULT v1; // esi
  char szCommand[256]; // [esp+8h] [ebp-13Ch] BYREF
  tagLVITEMA lvitem; // [esp+108h] [ebp-3Ch] BYREF

  v1 = SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1042u, wParam: 0, lParam: 0);
  if ( v1 == -1 )
  {
    Sys_MessageBox(title: "PIX Trace Setup Error", format: "No VProf Budget Node Selected!");
  }
  else
  {
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    lvitem.iItem = v1;
    SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
    g_pixTraceDlg_selectedNodeName = CUtlString::operator char const *(this: (CUtlString *)(lvitem.lParam + 4));
    if ( (unsigned __int16)DialogBoxParamA(
                             hInstance: g_hInstance,
                             lpTemplateName: (LPCSTR)0x98,
                             hWndParent,
                             lpDialogFunc: (DLGPROC)PixTraceDlg_Proc,
                             dwInitParam: 0) == 1019
      && g_connectedToApp )
    {
      g_pixTraceDlg_launchPixOneShot = g_pixTraceDlg_launchPix;
      unlink(path: g_pixTraceDlg_captureFilename);
      DmDeleteFile(a1: "e:\\capture.pix2", a2: 0);
      V_snprintf(pDest: szCommand, maxLen: 256, pFormat: "vx_vprof_trace \"%s\"", g_pixTraceDlg_selectedNodeName);
      if ( !ProcessCommand(strCmdIn: szCommand) )
        g_pixTraceDlg_launchPixOneShot = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420EF0
// Name: void ShowVProfNodes_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "showVProfNodesSortColumn", value: g_showVProfNodes_sortColumn);
  Sys_SetRegistryInteger(keyName: "showVProfNodesSortDescending", value: g_showVProfNodes_sortDescending);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_showVProfNodes_hWnd, lpwndpl: &wp);
  g_showVProfNodes_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "showVProfNodesWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x00420FA0
// Name: void ShowVProfNodes_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "showVProfNodesSortColumn", defValue: 0, value: &g_showVProfNodes_sortColumn);
  Sys_GetRegistryInteger(keyName: "showVProfNodesSortDescending", defValue: 0, value: &g_showVProfNodes_sortDescending);
  Sys_GetRegistryString(keyName: "showVProfNodesWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_showVProfNodes_windowRect,
         &g_showVProfNodes_windowRect.top,
         &g_showVProfNodes_windowRect.right,
         &g_showVProfNodes_windowRect.bottom) != 4
    || g_showVProfNodes_windowRect.left < 0
    || g_showVProfNodes_windowRect.top < 0
    || g_showVProfNodes_windowRect.right < 0
    || g_showVProfNodes_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_showVProfNodes_windowRect.left = 0;
    *(_QWORD *)&g_showVProfNodes_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421050
// Name: int ShowVProfNodes_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowVProfNodes_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax
  const char *v4; // esi
  const char *v5; // eax
  const char *v6; // esi
  const char *v7; // eax
  double v8; // xmm0_8

  result = 0;
  switch ( g_showVProfNodes_sortColumn )
  {
    case 0:
      v4 = CUtlString::operator char const *(this: (CUtlString *)(lParam2 + 4));
      v5 = CUtlString::operator char const *(this: (CUtlString *)(lParam1 + 4));
      result = _V_stricmp(s1: v5, s2: v4);
      break;
    case 1:
      v6 = CUtlString::operator char const *(this: (CUtlString *)(lParam2 + 20));
      v7 = CUtlString::operator char const *(this: (CUtlString *)(lParam1 + 20));
      result = _V_stricmp(s1: v7, s2: v6);
      break;
    case 2:
      result = *(_DWORD *)(lParam1 + 40) - *(_DWORD *)(lParam2 + 40);
      break;
    case 3:
      v8 = *(double *)(lParam1 + 64) - *(double *)(lParam2 + 64);
      goto LABEL_7;
    case 4:
      v8 = *(double *)(lParam1 + 88) - *(double *)(lParam2 + 88);
LABEL_7:
      result = (int)v8;
      break;
    default:
      break;
  }
  if ( g_showVProfNodes_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421110
// Name: void ShowVProfNodes_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_showVProfNodes_hWnd != nullptr )
  {
    SendMessageA(
      hWnd: g_showVProfNodes_hWndListView,
      Msg: 0x1030u,
      wParam: 0,
      lParam: (LPARAM)ShowVProfNodes_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = byte_4668C4;
    for ( j = 5; j != 0; --j )
    {
      if ( v2 == g_showVProfNodes_sortColumn )
        v4 = 2 * (g_showVProfNodes_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421210
// Name: void ShowVProfNodes_AddViewItem(struct VProfNode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_AddViewItem(VProfNode_t *pNode)
{
  LRESULT v2; // ebx
  tagLVITEMA lvi; // [esp+14h] [ebp-3Ch] BYREF

  if ( g_showVProfNodes_hWnd != nullptr )
  {
    sprintf(string: pNode->totalCallsBuff, format: "%d", pNode->totalCalls);
    sprintf(string: pNode->inclusiveTimeBuff, format: "%10.3f", (double)pNode->inclusiveTime);
    sprintf(string: pNode->exclusiveTimeBuff, format: "%10.3f", (double)pNode->exclusiveTime);
    v2 = SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    lvi.mask = 13;
    lvi.iItem = v2;
    memset(&lvi.iSubItem, 0, 12);
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pNode;
    pNode->listIndex = SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004212E0
// Name: void ShowVProfNodes_Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_Refresh()
{
  bool v0; // zf
  const char *v1; // eax

  if ( g_connectedToApp )
  {
    v0 = VProf_GetState() == VPROF_OFF;
    v1 = "vprof_on ; wait 10 ; vx_vprof_nodeslist ; vprof_off";
    if ( !v0 )
      v1 = "vx_vprof_nodeslist";
    ProcessCommand(strCmdIn: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421310
// Name: void ShowVProfNodes_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_SizeWindow(HWND__ *hwnd, int cx, int cy)
{
  int right; // ecx
  int bottom; // eax
  tagRECT rcClient; // [esp+0h] [ebp-10h] BYREF

  right = cx;
  if ( cx == 0 || (bottom = cy, cy == 0) )
  {
    GetClientRect(hWnd: hwnd, lpRect: &rcClient);
    right = rcClient.right;
    bottom = rcClient.bottom;
  }
  SetWindowPos(
    hWnd: g_showVProfNodes_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00421360
// Name: long ShowVProfNodes_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ShowVProfNodes_WndProc(HWND__ *hWnd, UINT message, HMENU wParam, unsigned int lParam)
{
  int result; // eax
  int v5; // eax
  int v6; // eax

  if ( message > 0x4E )
  {
    if ( message != 273 )
    {
      if ( message == 278 )
      {
        EnableMenuItem(hMenu: wParam, uIDEnableItem: 0xC5C6u, uEnable: !g_connectedToApp);
        return 0;
      }
      return DefWindowProcA(hWnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam == 40136 )
    {
      ShowVProfNodes_Refresh();
      return 0;
    }
    if ( (unsigned __int16)wParam == 50630 )
    {
      PixTraceDlg_Open(hWndParent: hWnd);
      return 0;
    }
    return DefWindowProcA(hWnd, Msg: message, (WPARAM)wParam, lParam);
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        ShowVProfNodes_SaveConfig();
        g_showVProfNodes_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        ShowVProfNodes_SizeWindow(hwnd: hWnd, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd, Msg: message, (WPARAM)wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 != -150 )
  {
    if ( v5 == -108 )
    {
      if ( g_showVProfNodes_sortColumn == *(_DWORD *)(lParam + 16) )
        g_showVProfNodes_sortDescending ^= 1u;
      else
        g_showVProfNodes_sortColumn = *(_DWORD *)(lParam + 16);
      ShowVProfNodes_SortItems();
      return 0;
    }
    return DefWindowProcA(hWnd, Msg: message, (WPARAM)wParam, lParam);
  }
  v6 = *(_DWORD *)(lParam + 44);
  switch ( *(_DWORD *)(lParam + 20) )
  {
    case 0:
      *(_DWORD *)(lParam + 32) = CUtlString::operator char const *(this: (CUtlString *)(v6 + 4));
      result = 0;
      break;
    case 1:
      *(_DWORD *)(lParam + 32) = CUtlString::operator char const *(this: (CUtlString *)(v6 + 20));
      result = 0;
      break;
    case 2:
      *(_DWORD *)(lParam + 32) = v6 + 44;
      result = 0;
      break;
    case 3:
      *(_DWORD *)(lParam + 32) = v6 + 72;
      result = 0;
      break;
    case 4:
      *(_DWORD *)(lParam + 32) = v6 + 96;
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd, Msg: message, (WPARAM)wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421500
// Name: bool ShowVProfNodes_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShowVProfNodes_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = ShowVProfNodes_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)151;
  wndclass.hCursor = (HICON__ *)"SHOWVPROFNODESCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  ShowVProfNodes_LoadConfig();
  PixTraceDlg_LoadConfig();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004215A0
// Name: int rc_TraceComplete(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_TraceComplete()
{
  char szCommandLine[1040]; // [esp+0h] [ebp-66Ch] BYREF
  char szPixPath[260]; // [esp+410h] [ebp-25Ch] BYREF
  char szXEDKPath[260]; // [esp+514h] [ebp-158h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+618h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+65Ch] [ebp-10h] BYREF

  DebugCommand(pStrFormat: "0x%8.8x = TraceComplete()\n", 0);
  ConsoleWindowPrintf(
    rgb: 0,
    strFormat: "Trace Completed. Copying capture to %s. A large capture may take a few moments...\n",
    g_pixTraceDlg_captureFilename);
  if ( DmReceiveFileA(a1: g_pixTraceDlg_captureFilename, a2: "e:\\capture.pix2") != 47841280 )
  {
    ConsoleWindowPrintf(
      rgb: 0xFFu,
      strFormat: "Failed to copy remote capture file '%s' to local '%s'.\n",
      "e:\\capture.pix2",
      g_pixTraceDlg_captureFilename);
    return 0;
  }
  ConsoleWindowPrintf(
    rgb: 0,
    strFormat: "Copied remote '%s' to local '%s'.\n",
    "e:\\capture.pix2",
    g_pixTraceDlg_captureFilename);
  if ( g_pixTraceDlg_launchPixOneShot != 0 )
  {
    g_pixTraceDlg_launchPixOneShot = 0;
    memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
    StartupInfo.cb = 68;
    if ( GetEnvironmentVariableA(lpName: "XEDK", lpBuffer: szXEDKPath, nSize: 0x104u) == 0 )
    {
      ConsoleWindowPrintf(
        rgb: 0xFFu,
        strFormat: "Missing XEDK Environment Variable. Xbox 360 XDK not installed properly!\n");
      return 0;
    }
    V_ComposeFileName(path: szXEDKPath, filename: "bin\\win32\\pix.exe", dest: szPixPath, destSize: 260);
    V_snprintf(pDest: szCommandLine, maxLen: 1040, pFormat: "\"%s\" \"%s\"", szPixPath, g_pixTraceDlg_captureFilename);
    if ( !CreateProcessA(
            lpApplicationName: nullptr,
            lpCommandLine: szCommandLine,
            lpProcessAttributes: nullptr,
            lpThreadAttributes: nullptr,
            bInheritHandles: false,
            dwCreationFlags: 8u,
            lpEnvironment: nullptr,
            lpCurrentDirectory: nullptr,
            lpStartupInfo: &StartupInfo,
            lpProcessInformation: &pi) )
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed to launch: %s\n", szCommandLine);
  }
  if ( VProf_GetState() == VPROF_OFF )
    ProcessCommand(strCmdIn: "vprof_off");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00421840
// Name: void ShowVProfNodes_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  int v2; // ecx
  char *v3; // edx
  int v4; // esi
  int v5; // edi
  bool v6; // zf
  const char *v7; // eax
  tagLVCOLUMNA lvc; // [esp+0h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+2Ch] [ebp-10h] BYREF

  if ( g_showVProfNodes_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_showVProfNodes_hWnd) )
      ShowWindow(hWnd: g_showVProfNodes_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_showVProfNodes_hWnd);
  }
  else
  {
    g_showVProfNodes_hWnd = CreateWindowExA(
                              dwExStyle: 0x200u,
                              lpClassName: "SHOWVPROFNODESCLASS",
                              lpWindowName: "VProf Budget Nodes",
                              dwStyle: 0x80CF0000,
                              X: 0,
                              Y: 0,
                              nWidth: 700,
                              nHeight: 400,
                              hWndParent: g_hDlgMain,
                              hMenu: nullptr,
                              hInstance: g_hInstance,
                              lpParam: nullptr);
    GetClientRect(hWnd: g_showVProfNodes_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_showVProfNodes_hWndListView = CreateWindowExA(
                                      dwExStyle: 0,
                                      lpClassName: "SysListView32",
                                      lpWindowName: &defValue,
                                      dwStyle: 0x5000000Du,
                                      X: 0,
                                      Y: 0,
                                      nWidth: clientRect.right - clientRect.left,
                                      nHeight: clientRect.bottom - clientRect.top,
                                      hWndParent: g_showVProfNodes_hWnd,
                                      hMenu: (HMENU)0x64,
                                      hInstance: g_hInstance,
                                      lpParam: nullptr);
    for ( i = 0; i < 55; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = dword_4668BC[i];
      v3 = *(char **)((char *)&g_showVProfNodes_Labels[0].name + i * 4);
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.cx = v2;
      lvc.mask = 15;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    v4 = 0;
    if ( g_showVProfNodes_Contents.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        ShowVProfNodes_AddViewItem(pNode: &g_showVProfNodes_Contents.m_Memory.m_pMemory[v5]);
        ++v4;
        ++v5;
      }
      while ( v4 < g_showVProfNodes_Contents.m_Size );
    }
    ShowVProfNodes_SortItems();
    if ( g_showVProfNodes_windowRect.right != 0 && g_showVProfNodes_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_showVProfNodes_hWnd,
        X: g_showVProfNodes_windowRect.left,
        Y: g_showVProfNodes_windowRect.top,
        nWidth: g_showVProfNodes_windowRect.right - g_showVProfNodes_windowRect.left,
        nHeight: g_showVProfNodes_windowRect.bottom - g_showVProfNodes_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_showVProfNodes_hWnd, nCmdShow: 1);
    if ( g_connectedToApp )
    {
      v6 = VProf_GetState() == VPROF_OFF;
      v7 = "vprof_on ; wait 10 ; vx_vprof_nodeslist ; vprof_off";
      if ( !v6 )
        v7 = "vx_vprof_nodeslist";
      ProcessCommand(strCmdIn: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C60
// Name: void ShowVProfNodes_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowVProfNodes_Clear()
{
  VProfNode_t *m_pMemory; // eax

  if ( g_showVProfNodes_hWnd != nullptr )
    SendMessageA(hWnd: g_showVProfNodes_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_showVProfNodes_Contents.m_Size != 0 )
  {
    CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::RemoveAll(this: &g_showVProfNodes_Contents);
    m_pMemory = g_showVProfNodes_Contents.m_Memory.m_pMemory;
    if ( g_showVProfNodes_Contents.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_showVProfNodes_Contents.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_showVProfNodes_Contents.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_showVProfNodes_Contents.m_Memory.m_pMemory = nullptr;
      }
      g_showVProfNodes_Contents.m_Memory.m_nAllocationCount = 0;
    }
    g_showVProfNodes_Contents.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421D30
// Name: int rc_VProfNodeList(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_VProfNodeList(char *pCommand)
{
  int v1; // ebx
  const char *Token; // eax
  const char *v3; // eax
  const char *v4; // eax
  xrVProfNodeItem_t *m_pMemory; // esi
  char *v6; // esi
  int v7; // eax
  int v8; // edi
  VProfNode_t *v9; // edx
  char *v10; // eax
  char *v11; // eax
  int elem; // ecx
  char v13; // dl
  char v14; // al
  char v15; // dl
  char v16; // al
  char v17; // dl
  char v18; // al
  char v19; // dl
  char v20; // dl
  char v21; // al
  char v22; // dl
  char v23; // al
  char v24; // dl
  char v25; // al
  char v26; // dl
  double v27; // xmm0_8
  int v28; // ebx
  int v29; // esi
  int v30; // esi
  int j; // esi
  CUtlDict<int,int> symbols; // [esp+Ch] [ebp-68h] BYREF
  CUtlVector<xrVProfNodeItem_t,CUtlMemory<xrVProfNodeItem_t,int> > localList; // [esp+30h] [ebp-44h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+44h] [ebp-30h] BYREF
  double exclusiveTime; // [esp+4Ch] [ebp-28h]
  double inclusiveTime; // [esp+54h] [ebp-20h]
  int iNodeIndex; // [esp+5Ch] [ebp-18h] BYREF
  int i; // [esp+60h] [ebp-14h]
  int retAddr; // [esp+64h] [ebp-10h] BYREF
  int xboxRetVal; // [esp+68h] [ebp-Ch] BYREF
  int nodeList; // [esp+6Ch] [ebp-8h] BYREF
  int numEntries; // [esp+70h] [ebp-4h] BYREF

  v1 = -1;
  memset(&localList, 0, sizeof(localList));
  memset(&symbols.m_Elements.m_Tree.m_Elements, 0, sizeof(symbols.m_Elements.m_Tree.m_Elements));
  symbols.m_Elements.m_Tree.m_Root = -1;
  symbols.m_Elements.m_Tree.m_NumElements = 0;
  symbols.m_Elements.m_Tree.m_FirstFree = -1;
  symbols.m_Elements.m_Tree.m_LastAlloc.index = -1;
  symbols.m_Elements.m_Tree.m_pElements = nullptr;
  symbols.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  ShowVProfNodes_Clear();
  Token = GetToken(ppTokenStream: &pCommand);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%x", &numEntries);
    v3 = GetToken(ppTokenStream: &pCommand);
    if ( *v3 != 0 )
    {
      sscanf(string: v3, format: "%x", &nodeList);
      v4 = GetToken(ppTokenStream: &pCommand);
      if ( *v4 != 0 )
      {
        sscanf(string: v4, format: "%x", &retAddr);
        localList.m_Size = 0;
        CUtlVector<xrVProfNodeItem_t,CUtlMemory<xrVProfNodeItem_t,int>>::InsertMultipleBefore(
          this: &localList,
          elem: 0,
          num: numEntries);
        m_pMemory = localList.m_Memory.m_pMemory;
        DmGetMemory(a1: nodeList, a2: 280 * numEntries, a3: localList.m_Memory.m_pMemory, a4: 0);
        CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::EnsureCapacity(
          this: &g_showVProfNodes_Contents,
          num: numEntries);
        i = 0;
        if ( numEntries > 0 )
        {
          v6 = (char *)&m_pMemory->inclusiveTime + 6;
          do
          {
            if ( _V_stricmp(s1: v6 - 270, s2: "root") != 0 )
            {
              if ( v6 == (char *)270
                || (search.key = v6 - 270,
                    (v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                            this: &symbols.m_Elements.m_Tree,
                            &search)) == -1) )
              {
                v8 = CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::InsertBefore(
                       this: &g_showVProfNodes_Contents,
                       elem: g_showVProfNodes_Contents.m_Size);
                iNodeIndex = v8;
                CUtlDict<int,int>::Insert(this: &symbols, pName: v6 - 270, element: &iNodeIndex);
                v8 *= 112;
                CUtlString::operator=(
                  this: (CUtlString *)((char *)&g_showVProfNodes_Contents.m_Memory.m_pMemory->name + v8),
                  src: v6 - 270);
                CUtlString::operator=(
                  this: (CUtlString *)((char *)&g_showVProfNodes_Contents.m_Memory.m_pMemory->budgetGroupName + v8),
                  src: v6 - 142);
                iNodeIndex = *(_DWORD *)(v6 - 14);
                *(unsigned int *)((char *)&g_showVProfNodes_Contents.m_Memory.m_pMemory->budgetGroupColor + v8) = _byteswap_ulong(iNodeIndex);
                iNodeIndex = *(_DWORD *)(v6 - 10);
                *(unsigned int *)((char *)&g_showVProfNodes_Contents.m_Memory.m_pMemory->totalCalls + v8) = _byteswap_ulong(iNodeIndex);
                v9 = g_showVProfNodes_Contents.m_Memory.m_pMemory;
                g_showVProfNodes_Contents.m_Memory.m_pMemory->totalCallsBuff[v8 + 20] = v6[1];
                v10 = &v9->totalCallsBuff[v8 + 20];
                v10[1] = *v6;
                v10[2] = *(v6 - 1);
                v10[3] = *(v6 - 2);
                v10[4] = *(v6 - 3);
                v10[5] = *(v6 - 4);
                v10[6] = *(v6 - 5);
                v10[7] = *(v6 - 6);
                v11 = &g_showVProfNodes_Contents.m_Memory.m_pMemory->inclusiveTimeBuff[v8 + 16];
                *v11 = v6[9];
                v11[1] = v6[8];
                v11[2] = v6[7];
                v11[3] = v6[6];
                v11[4] = v6[5];
                v11[5] = v6[4];
                v11[6] = v6[3];
                v11[7] = v6[2];
              }
              else
              {
                elem = symbols.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
                iNodeIndex = *(_DWORD *)(v6 - 10);
                g_showVProfNodes_Contents.m_Memory.m_pMemory[elem].totalCalls += _byteswap_ulong(iNodeIndex);
                v13 = v6[1];
                BYTE1(inclusiveTime) = *v6;
                v14 = *(v6 - 2);
                LOBYTE(inclusiveTime) = v13;
                v15 = *(v6 - 1);
                BYTE3(inclusiveTime) = v14;
                v16 = *(v6 - 4);
                BYTE2(inclusiveTime) = v15;
                v17 = *(v6 - 3);
                BYTE5(inclusiveTime) = v16;
                v18 = *(v6 - 6);
                BYTE4(inclusiveTime) = v17;
                v19 = *(v6 - 5);
                HIBYTE(inclusiveTime) = v18;
                BYTE6(inclusiveTime) = v19;
                g_showVProfNodes_Contents.m_Memory.m_pMemory[elem].inclusiveTime = inclusiveTime
                                                                                 + g_showVProfNodes_Contents.m_Memory.m_pMemory[elem].inclusiveTime;
                v20 = v6[9];
                BYTE1(exclusiveTime) = v6[8];
                v21 = v6[6];
                LOBYTE(exclusiveTime) = v20;
                v22 = v6[7];
                BYTE3(exclusiveTime) = v21;
                v23 = v6[4];
                BYTE2(exclusiveTime) = v22;
                v24 = v6[5];
                BYTE5(exclusiveTime) = v23;
                v25 = v6[2];
                BYTE4(exclusiveTime) = v24;
                v26 = v6[3];
                HIBYTE(exclusiveTime) = v25;
                v27 = g_showVProfNodes_Contents.m_Memory.m_pMemory[elem].exclusiveTime;
                BYTE6(exclusiveTime) = v26;
                g_showVProfNodes_Contents.m_Memory.m_pMemory[elem].exclusiveTime = v27 + exclusiveTime;
              }
            }
            v6 += 280;
            ++i;
          }
          while ( i < numEntries );
        }
        v28 = 0;
        if ( g_showVProfNodes_Contents.m_Size > 0 )
        {
          v29 = 0;
          do
          {
            ShowVProfNodes_AddViewItem(pNode: &g_showVProfNodes_Contents.m_Memory.m_pMemory[v29]);
            ++v28;
            ++v29;
          }
          while ( v28 < g_showVProfNodes_Contents.m_Size );
        }
        v30 = numEntries;
        iNodeIndex = numEntries;
        xboxRetVal = _byteswap_ulong(numEntries);
        DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
        DebugCommand(pStrFormat: "0x%8.8x = VProfNodeList( 0x%8.8x, 0x%8.8x )\n", v30, numEntries, nodeList);
        ShowVProfNodes_SortItems();
        v1 = 0;
      }
    }
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &symbols.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &symbols.m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)symbols.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &symbols.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &symbols.m_Elements.m_Tree);
  if ( symbols.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && symbols.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
  if ( localList.m_Memory.m_nGrowSize >= 0 && localList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: localList.m_Memory.m_pMemory);
  return v1;
}
