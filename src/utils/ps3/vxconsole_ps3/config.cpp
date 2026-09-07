// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/config.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00404630
// Name: bool gConnectedToTarget(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl gConnectedToTarget()
{
  return g_connectionState == kCONNECTEDTARGET || g_connectionState == kCONNECTEDAPP;
}

//------------------------------------------------------------------------------
// Address: 0x00404650
// Name: void ConfigDlg_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_LoadConfig()
{
  const char *v0; // eax
  char dest[260]; // [esp+0h] [ebp-208h] BYREF
  char defaultLocalTargetPath[260]; // [esp+104h] [ebp-104h] BYREF

  v0 = getenv(option: "VGAME");
  if ( v0 != nullptr )
  {
    V_ComposeFileName(path: v0, filename: "../ps3bdvd", dest, destSize: 260);
    V_MakeAbsolutePath(pOut: defaultLocalTargetPath, outLen: 259, pPath: dest, pStartingDir: nullptr);
  }
  else
  {
    memset(dst: (unsigned __int8 *)defaultLocalTargetPath, value: 0, count: sizeof(defaultLocalTargetPath));
  }
  Sys_GetRegistryString(keyName: "ps3Name", value: g_ps3TargetName, defValue: &str, valueLen: 64);
  Sys_GetRegistryString(keyName: "localPath", value: g_localPath, defValue: "u:\\dev\\game", valueLen: 260);
  Sys_GetRegistryString(keyName: "targetPath", value: g_targetPath, defValue: defaultLocalTargetPath, valueLen: 260);
  Sys_GetRegistryString(
    keyName: "installPath",
    value: g_installPath,
    defValue: "\\\\fileserver\\user\\xbox\\xbox_orange",
    valueLen: 260);
  Sys_GetRegistryInteger(keyName: "clearOnConnect", defValue: 1, value: &g_clsOnConnect);
  Sys_GetRegistryInteger(keyName: "loadSymbolsOnConnect", defValue: 0, value: &g_loadSymbolsOnConnect);
  Sys_GetRegistryInteger(keyName: "alwaysAutoConnect", defValue: 0, value: &g_alwaysAutoConnect);
  Sys_GetRegistryInteger(keyName: "startMinimized", defValue: 0, value: &g_startMinimized);
  Sys_GetRegistryInteger(keyName: "captureDebugSpew", defValue: 1, value: &g_captureDebugSpew_StartupState);
  Sys_GetRegistryInteger(keyName: "verboseDebugPrinting", defValue: 0, value: &g_bVerbosePrinting);
}

//------------------------------------------------------------------------------
// Address: 0x00404790
// Name: void ConfigDlg_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_SaveConfig()
{
  Sys_SetRegistryString(keyName: "ps3Name", value: g_ps3TargetName);
  Sys_SetRegistryString(keyName: "localPath", value: g_localPath);
  Sys_SetRegistryString(keyName: "targetPath", value: g_targetPath);
  Sys_SetRegistryString(keyName: "installPath", value: g_installPath);
  Sys_SetRegistryInteger(keyName: "clearOnConnect", value: g_clsOnConnect);
  Sys_SetRegistryInteger(keyName: "loadSymbolsOnConnect", value: g_loadSymbolsOnConnect);
  Sys_SetRegistryInteger(keyName: "alwaysAutoConnect", value: g_alwaysAutoConnect);
  Sys_SetRegistryInteger(keyName: "startMinimized", value: g_startMinimized);
  Sys_SetRegistryInteger(keyName: "captureDebugSpew", value: g_captureDebugSpew_StartupState);
  Sys_SetRegistryInteger(keyName: "verboseDebugPrinting", value: g_bVerbosePrinting);
  SetMainWindowTitle();
}

//------------------------------------------------------------------------------
// Address: 0x00404840
// Name: void ConfigDlg_Setup(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_Setup(HWND__ *hWnd)
{
  HWND DlgItem; // eax
  BOOL v2; // [esp-4h] [ebp-Ch]

  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1015, lpString: g_ps3TargetName);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1017, lpString: g_localPath);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1022, lpString: g_targetPath);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1025, lpString: g_installPath);
  v2 = &g_ps3TargetName[strlen(g_ps3TargetName) + 1] != (char *)&unk_449191;
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1018);
  EnableWindow(hWnd: DlgItem, bEnable: v2);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1021, uCheck: g_clsOnConnect != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1053, uCheck: g_alwaysAutoConnect != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1054, uCheck: g_startMinimized != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1055, uCheck: g_captureDebugSpew_StartupState != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1056, uCheck: g_bVerbosePrinting != 0);
}

//------------------------------------------------------------------------------
// Address: 0x00404930
// Name: int ConfigDlg_Ping(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ConfigDlg_Ping(HWND__ *hwnd)
{
  const char *v1; // eax
  int v3; // esi
  const char *v4; // eax
  char xboxName[64]; // [esp+0h] [ebp-44h] BYREF
  char *args[1]; // [esp+40h] [ebp-4h] BYREF

  xboxName[0] = 0;
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1015, lpString: xboxName, cchMax: 64);
  if ( g_PS3CurrentTargetConn.m_nSNHandle < 0 )
    v1 = &str;
  else
    v1 = CUtlString::Get(this: &g_PS3CurrentTargetConn.m_targetInfo.szName);
  if ( _V_stricmp(s1: v1, s2: xboxName) == 0
    && (g_connectionState == kCONNECTEDTARGET || g_connectionState == kCONNECTEDAPP) )
  {
    Sys_MessageBox(title: "Ping", format: "Already Connected To: '%s'", xboxName);
    return 1;
  }
  else
  {
    lc_disconnect(argc: 0, argv: nullptr);
    args[0] = xboxName;
    v3 = lc_connect(argc: 1, argv: args);
    if ( v3 != 0 )
    {
      if ( g_PS3CurrentTargetConn.m_nSNHandle < 0 )
        v4 = &str;
      else
        v4 = CUtlString::Get(this: &g_PS3CurrentTargetConn.m_targetInfo.szName);
      Sys_MessageBox(title: "Ping SUCCESS", format: "Connection Valid To: %s", v4);
      lc_disconnect(argc: 0, argv: nullptr);
      return v3;
    }
    else
    {
      Sys_MessageBox(title: "Ping FAILURE", format: "Could Not Connect To: %s", xboxName);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404A30
// Name: bool ConfigDlg_GetChanges(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConfigDlg_GetChanges(HWND__ *hwnd)
{
  int v1; // eax
  char v2; // cl
  int v3; // eax
  char v4; // cl
  int v5; // eax
  char v6; // cl
  int v7; // eax
  char v8; // cl
  char complaint[512]; // [esp+8h] [ebp-54Ch] BYREF
  char installPath[260]; // [esp+208h] [ebp-34Ch] BYREF
  char localPath[260]; // [esp+30Ch] [ebp-248h] BYREF
  char targetPath[260]; // [esp+410h] [ebp-144h] BYREF
  char xboxName[64]; // [esp+514h] [ebp-40h] BYREF

  xboxName[0] = 0;
  localPath[0] = 0;
  targetPath[0] = 0;
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1015, lpString: xboxName, cchMax: 64);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1017, lpString: localPath, cchMax: 260);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1022, lpString: targetPath, cchMax: 260);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1025, lpString: installPath, cchMax: 260);
  if ( localPath[0] != 0 && targetPath[0] != 0 && installPath[0] != 0 )
  {
    v1 = 0;
    do
    {
      v2 = localPath[v1];
      g_localPath[v1++] = v2;
    }
    while ( v2 != 0 );
    Sys_NormalizePath(path: g_localPath, forceToLower: true);
    if ( (targetPath[0] == 47 || targetPath[0] == 92) && (targetPath[1] == 47 || targetPath[1] == 92) )
    {
      V_snprintf(
        pDest: complaint,
        maxLen: 512,
        pFormat: "%s isn't a valid directory for \"Local Image Copy\".\n"
        "It has to be a directory on your local computer, not the fileserver.\n"
        "This is where the \"installation depot\" will be copied so that your PS3 can read content from it.\n"
        "Try 'u:\\dev\\portal2\\ps3dvd'.",
        targetPath);
      MessageBoxA(hWnd: hwnd, lpText: complaint, lpCaption: "Bad \"Local Image Copy\"", uType: 0x30u);
      return 0;
    }
    else
    {
      v3 = 0;
      do
      {
        v4 = targetPath[v3];
        g_targetPath[v3++] = v4;
      }
      while ( v4 != 0 );
      Sys_NormalizePath(path: g_targetPath, forceToLower: true);
      v5 = 0;
      do
      {
        v6 = installPath[v5];
        g_installPath[v5++] = v6;
      }
      while ( v6 != 0 );
      Sys_NormalizePath(path: g_installPath, forceToLower: true);
      v7 = 0;
      do
      {
        v8 = xboxName[v7];
        g_ps3TargetName[v7++] = v8;
      }
      while ( v8 != 0 );
      g_clsOnConnect = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1021);
      g_loadSymbolsOnConnect = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1028);
      g_alwaysAutoConnect = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1053);
      g_startMinimized = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1054);
      g_captureDebugSpew_StartupState = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1055);
      g_bVerbosePrinting = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1056);
      return 1;
    }
  }
  else
  {
    MessageBoxA(
      hWnd: hwnd,
      lpText: "You need to fill out all three path boxes.\n"
      "PC Local Game Path is where you p4 sync your game tree.\n"
      "Local Image Copy is where you want to store the DVD image that the PS3 will play.\n"
      "Installation Depot is where to find the DVD images on the fileserver.",
      lpCaption: "Erroneous User",
      uType: 0x30u);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404C40
// Name: int ConfigDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall ConfigDlg_Proc(HWND__ *hwnd, unsigned int message, INT_PTR wParam, int lParam)
{
  HWND DlgItem; // eax
  BOOL v6; // [esp-Ch] [ebp-4Ch]
  char buff[64]; // [esp+0h] [ebp-40h] BYREF

  if ( message != 272 )
  {
    if ( message == 273 )
    {
      if ( (unsigned __int16)wParam <= 0x3FAu )
      {
        if ( (unsigned __int16)wParam == 1018 )
        {
          ConfigDlg_Ping(hwnd);
          return 0;
        }
        if ( (unsigned __int16)wParam != 2 )
        {
          if ( (unsigned __int16)wParam == 1015 )
          {
            GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1015, lpString: buff, cchMax: 64);
            v6 = &buff[strlen(buff) + 1] != &buff[1];
            DlgItem = GetDlgItem(hDlg: hwnd, nIDDlgItem: 1018);
            EnableWindow(hWnd: DlgItem, bEnable: v6);
            return 0;
          }
          return 0;
        }
LABEL_11:
        EndDialog(hDlg: hwnd, nResult: wParam);
        return 1;
      }
      if ( (unsigned __int16)wParam == 1019 )
      {
        if ( ConfigDlg_GetChanges(hwnd) != 0 )
          goto LABEL_11;
      }
      else if ( (unsigned __int16)wParam == 1020 )
      {
        goto LABEL_11;
      }
    }
    return 0;
  }
  ConfigDlg_Setup(hWnd: hwnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404D40
// Name: void ConfigDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_Open()
{
  if ( (unsigned __int16)DialogBoxParamA(
                           hInstance: g_hInstance,
                           lpTemplateName: (LPCSTR)0x6F,
                           hWndParent: g_hDlgMain,
                           lpDialogFunc: (DLGPROC)ConfigDlg_Proc,
                           dwInitParam: 0) == 1019 )
    ConfigDlg_SaveConfig();
}
