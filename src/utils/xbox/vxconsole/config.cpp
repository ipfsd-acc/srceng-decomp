// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/config.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E7F0
// Name: void ConfigDlg_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigDlg_LoadConfig(void *this)
{
  int color; // [esp+0h] [ebp-4h] BYREF

  color = (int)this;
  Sys_GetRegistryString(keyName: "configName", value: g_configName, defValue: "default", valueLen: 64);
  Sys_GetRegistryString(keyName: "xboxName", value: g_xboxTargetName, defValue: &defValue, valueLen: 64);
  Sys_GetRegistryString(keyName: "localPath", value: g_localPath, defValue: "u:\\dev\\game", valueLen: 260);
  Sys_GetRegistryString(keyName: "targetPath", value: g_targetPath, defValue: "e:\\valve", valueLen: 260);
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
  Sys_GetRegistryInteger(keyName: "playtestMode", defValue: 0, value: &g_playtestMode);
  Sys_GetRegistryInteger(keyName: "blinkIcon", defValue: 1, value: &g_bBlinkIcon);
  Sys_GetRegistryInteger(keyName: "notifyOnNewImage", defValue: 1, value: &g_bNotifyOnNewImage);
  Sys_GetRegistryInteger(keyName: "locallySyncDVDPDBs", defValue: 0, value: &g_bLocallySyncDVDPDBs);
  g_bLocallySyncDVDPDBs = 0;
  if ( ParseCommandLineArg(pKey: "-noblink", pValueBuff: nullptr, valueBuffSize: 0) )
    g_bBlinkIcon = 0;
  g_bDvdDevLog = ParseCommandLineArg(pKey: "-dvddevlog", pValueBuff: nullptr, valueBuffSize: 0);
  g_bPublicTest = ParseCommandLineArg(pKey: "-publictest", pValueBuff: nullptr, valueBuffSize: 0);
  Sys_GetRegistryInteger(keyName: "backgroundColor", defValue: 12632256, value: &color);
  g_backgroundColor = color;
  Sys_GetRegistryInteger(keyName: "textColor", defValue: 0, value: &color);
  g_textColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x0040E9A0
// Name: void ConfigDlg_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_SaveConfig()
{
  Sys_SetRegistryString(keyName: "configName", value: g_configName);
  Sys_SetRegistryString(keyName: "xboxName", value: g_xboxTargetName);
  Sys_SetRegistryString(keyName: "localPath", value: g_localPath);
  Sys_SetRegistryString(keyName: "targetPath", value: g_targetPath);
  Sys_SetRegistryString(keyName: "installPath", value: g_installPath);
  Sys_SetRegistryInteger(keyName: "clearOnConnect", value: g_clsOnConnect);
  Sys_SetRegistryInteger(keyName: "loadSymbolsOnConnect", value: g_loadSymbolsOnConnect);
  Sys_SetRegistryInteger(keyName: "alwaysAutoConnect", value: g_alwaysAutoConnect);
  Sys_SetRegistryInteger(keyName: "startMinimized", value: g_startMinimized);
  Sys_SetRegistryInteger(keyName: "captureDebugSpew", value: g_captureDebugSpew_StartupState);
  Sys_SetRegistryInteger(keyName: "playtestMode", value: g_playtestMode);
  Sys_SetRegistryInteger(keyName: "backgroundColor", value: g_backgroundColor);
  Sys_SetRegistryInteger(keyName: "textColor", value: g_textColor);
  Sys_SetRegistryInteger(keyName: "blinkIcon", value: g_bBlinkIcon);
  Sys_SetRegistryInteger(keyName: "notifyOnNewImage", value: g_bNotifyOnNewImage);
  Sys_SetRegistryInteger(keyName: "locallySyncDVDPDBs", value: g_bLocallySyncDVDPDBs);
  SetMainWindowTitle();
}

//------------------------------------------------------------------------------
// Address: 0x0040EAB0
// Name: void ConfigDlg_Setup(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_Setup(HWND__ *hWnd)
{
  HWND DlgItem; // eax
  unsigned int i; // edi
  BOOL v3; // [esp-4h] [ebp-10h]

  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1026, lpString: g_configName);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1015, lpString: g_xboxTargetName);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1017, lpString: g_localPath);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1022, lpString: g_targetPath);
  SetDlgItemTextA(hDlg: hWnd, nIDDlgItem: 1025, lpString: g_installPath);
  v3 = &g_xboxTargetName[strlen(g_xboxTargetName) + 1] != (char *)&unk_46B079;
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1018);
  EnableWindow(hWnd: DlgItem, bEnable: v3);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1021, uCheck: g_clsOnConnect != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1053, uCheck: g_alwaysAutoConnect != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1054, uCheck: g_startMinimized != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1055, uCheck: g_captureDebugSpew_StartupState != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1056, uCheck: g_playtestMode != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1057, uCheck: g_bBlinkIcon != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1058, uCheck: g_bNotifyOnNewImage != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 50638, uCheck: g_bLocallySyncDVDPDBs != 0);
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x14Bu, wParam: 0, lParam: 0);
  for ( i = 0; i < 2; ++i )
    SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x143u, wParam: 0, lParam: (LPARAM)g_Colors[i].pFriendlyName);
  SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x14Eu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040EC30
// Name: int ConfigDlg_Ping(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ConfigDlg_Ping(HWND__ *hwnd)
{
  int v2; // esi
  char xboxName[64]; // [esp+0h] [ebp-44h] BYREF
  char *args[1]; // [esp+40h] [ebp-4h] BYREF

  xboxName[0] = 0;
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1015, lpString: xboxName, cchMax: 64);
  if ( _V_stricmp(s1: g_xboxName, s2: xboxName) != 0 || g_connectedToXBox == 0 )
  {
    lc_disconnect(argc: 0, argv: nullptr);
    args[0] = xboxName;
    v2 = lc_connect(argc: 1, argv: args);
    if ( v2 != 0 )
    {
      Sys_MessageBox(title: "Ping SUCCESS", format: "Connection Valid To: %s", g_xboxName);
      lc_disconnect(argc: 0, argv: nullptr);
      return v2;
    }
    else
    {
      Sys_MessageBox(title: "Ping FAILURE", format: "Could Not Connect To: %s", xboxName);
      return 0;
    }
  }
  else
  {
    Sys_MessageBox(title: "Ping", format: "Already Connected To: '%s'", xboxName);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ED00
// Name: void ConfigDlg_ChangeColor(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigDlg_ChangeColor(HWND__ *hWnd)
{
  unsigned int v1; // esi
  int v2; // eax
  unsigned int *v3; // ecx
  tagCHOOSECOLORA cc; // [esp+8h] [ebp-24h] BYREF

  v1 = SendDlgItemMessageA(hDlg: hWnd, nIDDlgItem: 1096, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v1 <= 1 )
  {
    g_customColors[0] = *(_DWORD *)off_465678[0];
    v2 = *off_465680;
    v3 = (unsigned int *)off_465678[2 * v1];
    memset(&cc.Flags, 0, 16);
    dword_46B0D4 = v2;
    *(_QWORD *)&cc.hInstance = 0;
    cc.lStructSize = 36;
    cc.lpCustColors = g_customColors;
    cc.hwndOwner = hWnd;
    cc.rgbResult = *v3;
    cc.Flags = 257;
    if ( ChooseColorA(a1: &cc) )
      *(_DWORD *)off_465678[2 * v1] = cc.rgbResult;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EDB0
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
  UINT v9; // eax
  char installPath[260]; // [esp+Ch] [ebp-454h] BYREF
  char targetPath[260]; // [esp+110h] [ebp-350h] BYREF
  char configName[260]; // [esp+214h] [ebp-24Ch] BYREF
  char localPath[260]; // [esp+318h] [ebp-148h] BYREF
  char xboxName[64]; // [esp+41Ch] [ebp-44h] BYREF
  int bOldPlaytestMode; // [esp+45Ch] [ebp-4h]

  xboxName[0] = 0;
  localPath[0] = 0;
  targetPath[0] = 0;
  configName[0] = 0;
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1015, lpString: xboxName, cchMax: 64);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1017, lpString: localPath, cchMax: 260);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1022, lpString: targetPath, cchMax: 260);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1025, lpString: installPath, cchMax: 260);
  GetDlgItemTextA(hDlg: hwnd, nIDDlgItem: 1026, lpString: configName, cchMax: 260);
  v1 = 0;
  do
  {
    v2 = localPath[v1];
    g_localPath[v1++] = v2;
  }
  while ( v2 != 0 );
  Sys_NormalizePath(path: g_localPath, forceToLower: true);
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
    g_xboxTargetName[v7++] = v8;
  }
  while ( v8 != 0 );
  V_strncpy(pDest: g_configName, pSrc: configName, maxLen: 64);
  g_clsOnConnect = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1021);
  g_loadSymbolsOnConnect = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1028);
  g_alwaysAutoConnect = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1053);
  g_startMinimized = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1054);
  g_captureDebugSpew_StartupState = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1055);
  g_bBlinkIcon = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1057);
  g_bNotifyOnNewImage = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1058);
  IsDlgButtonChecked(hDlg: hwnd, nIDButton: 50638);
  g_bLocallySyncDVDPDBs = 0;
  bOldPlaytestMode = g_playtestMode;
  v9 = IsDlgButtonChecked(hDlg: hwnd, nIDButton: 1056);
  g_playtestMode = v9;
  if ( bOldPlaytestMode != v9 )
    OnPlaytestModeChange(bTurnedOn: v9 != 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF90
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
        goto LABEL_15;
      }
      if ( (unsigned __int16)wParam != 1019 )
      {
        if ( (unsigned __int16)wParam != 1020 )
        {
          if ( (unsigned __int16)wParam == 1023 )
          {
            ConfigDlg_ChangeColor(hWnd: hwnd);
            return 0;
          }
          return 0;
        }
        goto LABEL_15;
      }
      if ( ConfigDlg_GetChanges(hwnd) != 0 )
      {
LABEL_15:
        EndDialog(hDlg: hwnd, nResult: wParam);
        return 1;
      }
    }
    return 0;
  }
  ConfigDlg_Setup(hWnd: hwnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0A0
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
