// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/vxconsole.cpp
// Functions: 113
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042B280
// Name: bool ParseCommandLineArg(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseCommandLineArg(const char *pKey, char *pValueBuff, int valueBuffSize)
{
  char *v3; // eax
  char *v5; // eax
  char i; // cl
  int j; // ecx

  v3 = V_stristr(pStr: g_pCommandLine, pSearch: pKey);
  if ( v3 == nullptr )
    return 0;
  if ( pValueBuff != nullptr )
  {
    v5 = &v3[strlen(pKey)];
    for ( i = *v5; i != 0; i = *++v5 )
    {
      if ( i != 32 )
        break;
    }
    for ( j = 0; j < valueBuffSize; ++v5 )
    {
      pValueBuff[j] = *v5;
      if ( *v5 == 0 )
        break;
      if ( *v5 == 32 )
        break;
      ++j;
    }
    pValueBuff[j] = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042B300
// Name: void MakeConfigString(char const __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeConfigString(const char *pString, int configID, char *pOutBuff, int outBuffSize)
{
  int v4; // eax
  bool v5; // bl

  if ( configID > 0 )
  {
    v4 = strlen(pString);
    v5 = v4 > 1 && pString[v4 - 1] == 92;
    V_snprintf(pDest: pOutBuff, maxLen: outBuffSize, pFormat: "%s_%d", pString, configID);
    if ( v5 )
      V_strncat(pDest: pOutBuff, pSrc: "\\", destBufferSize: outBuffSize, max_chars_to_copy: -1);
  }
  else
  {
    V_snprintf(pDest: pOutBuff, maxLen: outBuffSize, pFormat: "%s", pString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B380
// Name: void LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall LoadConfig(void *this)
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  ConfigDlg_LoadConfig(this);
  g_captureDebugSpew = g_captureDebugSpew_StartupState;
  Sys_GetRegistryString(keyName: "mainWindowRect", value: buff, defValue: &defValue, valueLen: 0x100u);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_mainWindowRect,
         &g_mainWindowRect.top,
         &g_mainWindowRect.right,
         &g_mainWindowRect.bottom) != 4
    || g_mainWindowRect.left < 0
    || g_mainWindowRect.top < 0
    || g_mainWindowRect.right < 0
    || g_mainWindowRect.bottom < 0 )
  {
    *(_QWORD *)&g_mainWindowRect.left = 0;
    *(_QWORD *)&g_mainWindowRect.right = 0;
  }
  UpdateCurrentImageVersionString();
}

//------------------------------------------------------------------------------
// Address: 0x0042B430
// Name: void SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_hDlgMain, lpwndpl: &wp);
  g_mainWindowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "mainWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x0042B4C0
// Name: void SetMainWindowTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMainWindowTitle()
{
  char configBuff[128]; // [esp+0h] [ebp-200h] BYREF
  char titleBuff[256]; // [esp+80h] [ebp-180h] BYREF
  char versionBuff[128]; // [esp+180h] [ebp-80h] BYREF

  if ( g_hDlgMain != nullptr )
  {
    if ( g_xboxTargetName[0] != 0 )
    {
      V_snprintf(pDest: titleBuff, maxLen: 256, pFormat: "%s: %s", aVxconsol, g_xboxTargetName);
      if ( g_configID != 0 )
      {
        if ( g_configName[0] != 0 && _V_stricmp(s1: g_configName, s2: "default") != 0 )
        {
          V_snprintf(pDest: titleBuff, maxLen: 256, pFormat: "%s: %s", aVxconsol, g_configName);
        }
        else
        {
          V_snprintf(pDest: configBuff, maxLen: 128, pFormat: " (%d)", g_configID);
          V_strncat(pDest: titleBuff, pSrc: configBuff, destBufferSize: 0x100u, max_chars_to_copy: -1);
        }
      }
      if ( g_nActiveVersion != 0 )
      {
        V_snprintf(pDest: versionBuff, maxLen: 128, pFormat: " - Active:%d", g_nActiveVersion);
      }
      else if ( g_nImageVersion != 0 )
      {
        V_snprintf(pDest: versionBuff, maxLen: 128, pFormat: " - Installed:%d", g_nImageVersion);
      }
      else
      {
        versionBuff[0] = 0;
      }
      V_strncat(pDest: titleBuff, pSrc: versionBuff, destBufferSize: 0x100u, max_chars_to_copy: -1);
      SetWindowTextA(hWnd: g_hDlgMain, lpString: titleBuff);
    }
    else
    {
      strcpy(titleBuff, "VXConsole");
      SetWindowTextA(hWnd: g_hDlgMain, lpString: titleBuff);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B640
// Name: void PrintToQueue(unsigned long,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void PrintToQueue(unsigned int rgb, char *strFormat, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+1010h] [ebp+10h] BYREF

  va_start(ap, strFormat);
  EnterCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
  if ( g_captureGameSpew != 0 && g_PrintQueue.numMessages != 4096 )
  {
    if ( _vsnprintf(string, count: 0x1000u, format: strFormat, ap) == -1 )
      string[4095] = 0;
    g_PrintQueue.pMessages[g_PrintQueue.numMessages] = Sys_CopyString(str: string);
    g_PrintQueue.aColors[g_PrintQueue.numMessages++] = rgb;
    if ( g_PrintQueue.numMessages == 1 )
      PostMessageA(hWnd: g_hDlgMain, Msg: 0x400u, wParam: 0, lParam: 0);
  }
  LeaveCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x0042B700
// Name: int ConsoleWindowPrintf(unsigned long,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int ConsoleWindowPrintf(LPARAM rgb, char *strFormat, ...)
{
  LPARAM v2; // esi
  int v3; // eax
  int v4; // edi
  _iobuf *PlaytestFileserverLogFile; // esi
  _iobuf *PlaytestLocalLogFile; // eax
  _iobuf *v7; // esi
  char pDest[4096]; // [esp+4h] [ebp-1044h] BYREF
  _DWORD lParam[15]; // [esp+1004h] [ebp-44h] BYREF
  LPARAM v11[2]; // [esp+1040h] [ebp-8h] BYREF
  va_list ap; // [esp+1058h] [ebp+10h] BYREF

  va_start(ap, strFormat);
  v2 = rgb;
  if ( rgb == 0 )
    v2 = g_textColor;
  v3 = 0;
  v11[0] = -1;
  v11[1] = -2;
  if ( g_playtestMode != 0 )
  {
    _Plat_GetLocalTime(a1: &lParam[6]);
    v3 = V_snprintf(pDest, maxLen: 4096, pFormat: "%2.2d:%2.2d:%2.2d ", lParam[8], lParam[7], lParam[6]);
  }
  v4 = _vsnprintf(string: &pDest[v3], count: 4096 - v3, format: strFormat, ap);
  if ( g_DisplayTTY != 0 )
  {
    memset(dst: (unsigned __int8 *)&lParam[1], value: 0, count: 0x38u);
    lParam[5] = v2;
    lParam[0] = 60;
    lParam[1] = 0x40000000;
    lParam[2] = 0;
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0x444u, wParam: 1u, (LPARAM)lParam);
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0x437u, wParam: 0, lParam: (LPARAM)v11);
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)pDest);
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0xB7u, wParam: 0, lParam: 0);
  }
  if ( g_playtestMode != 0 )
  {
    PlaytestFileserverLogFile = GetPlaytestFileserverLogFile();
    if ( PlaytestFileserverLogFile != nullptr )
    {
      fprintf(str: PlaytestFileserverLogFile, format: "%s", pDest);
      fclose(stream: PlaytestFileserverLogFile);
    }
    PlaytestLocalLogFile = GetPlaytestLocalLogFile();
    v7 = PlaytestLocalLogFile;
    if ( PlaytestLocalLogFile != nullptr )
    {
      fprintf(str: PlaytestLocalLogFile, format: "%s", pDest);
      fclose(stream: v7);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0042B880
// Name: int PerfmonPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int PerfmonPrintf(char *strFormat, ...)
{
  int result; // eax
  int v2; // edi
  _iobuf *PerfmonFileserverLogFile; // esi
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(ap, strFormat);
  result = 0;
  if ( g_playtestMode != 0 )
  {
    v2 = _vsnprintf(string, count: 0x1000u, format: strFormat, ap);
    PerfmonFileserverLogFile = GetPerfmonFileserverLogFile();
    if ( PerfmonFileserverLogFile != nullptr )
    {
      fprintf(str: PerfmonFileserverLogFile, format: "%s\n", string);
      fclose(stream: PerfmonFileserverLogFile);
    }
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B8F0
// Name: int CommandWindow_HandleKey(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CommandWindow_HandleKey(unsigned int wParam)
{
  int v1; // edi
  signed int v3; // esi
  LRESULT v4; // ebx
  char *v5; // eax
  signed int v6; // esi
  LRESULT v7; // eax
  char userCmd[260]; // [esp+8h] [ebp-208h] BYREF
  char hintCmd[260]; // [esp+10Ch] [ebp-104h] BYREF

  v1 = 0;
  if ( wParam - 112 <= 0xB && Bindings_TranslateKey(vkKeyCode: wParam) != 0 )
    return 1;
  switch ( wParam )
  {
    case 9u:
    case 0x26u:
    case 0x28u:
      if ( IsWindowVisible(hWnd: g_hwndCommandHint) )
      {
        v3 = SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x188u, wParam: 0, lParam: 0);
        SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x189u, wParam: v3, lParam: (LPARAM)hintCmd);
        v4 = SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x18Bu, wParam: 0, lParam: 0);
        if ( v4 < 0 )
          v4 = 0;
        switch ( wParam )
        {
          case 9u:
            GetWindowTextA(hWnd: g_hwndCommandCombo, lpString: userCmd, nMaxCount: 260);
            v5 = &userCmd[_V_strlen(str: userCmd) - 1];
            if ( *v5 == 32 )
              *v5 = 0;
            if ( _V_stricmp(s1: userCmd, s2: hintCmd) != 0 )
            {
LABEL_18:
              if ( v3 >= 0 )
              {
                if ( v3 > v4 - 1 )
                  goto LABEL_22;
              }
              else
              {
                v3 = v4 - 1;
              }
              if ( v3 >= 0 )
              {
LABEL_23:
                SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x186u, wParam: v3, lParam: 0);
                SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x189u, wParam: v3, lParam: (LPARAM)hintCmd);
                V_strncat(pDest: hintCmd, pSrc: " ", destBufferSize: 0x104u, max_chars_to_copy: 1);
                SetWindowTextA(hWnd: g_hwndCommandCombo, lpString: hintCmd);
                SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x142u, wParam: 0, lParam: 17039620);
                return 1;
              }
LABEL_22:
              v3 = 0;
              goto LABEL_23;
            }
            if ( GetKeyState(nVirtKey: 16) >= 0 )
            {
LABEL_17:
              ++v3;
              goto LABEL_18;
            }
            break;
          case 0x26u:
            break;
          case 0x28u:
            goto LABEL_17;
          default:
            goto LABEL_18;
        }
        --v3;
        goto LABEL_18;
      }
      v6 = SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x147u, wParam: 0, lParam: 0);
      if ( v6 >= 0 )
        return v1;
      v7 = SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x146u, wParam: 0, lParam: 0);
      if ( v7 <= 0 )
        return v1;
      if ( wParam == 38 )
      {
        v6 = v7 - 1;
      }
      else if ( wParam == 40 )
      {
        v6 = 0;
      }
      SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x14Eu, wParam: v6, lParam: 0);
      return 1;
    case 0xDu:
      if ( SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x157u, wParam: 0, lParam: 0) == 0 )
      {
        PostMessageA(hWnd: g_hDlgMain, Msg: 0x8000u, wParam: 0, lParam: 0);
        return 1;
      }
      SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x14Fu, wParam: 0, lParam: 0);
      return 0;
    default:
      return v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BB80
// Name: long OutputWindow_SubclassedProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall OutputWindow_SubclassedProc(HWND__ *hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if ( msg != 256 || GetKeyState(nVirtKey: 17) < 0 )
    return CallWindowProcA(lpPrevWndFunc: g_hwndOutputSubclassed, hWnd: hDlg, Msg: msg, wParam, lParam);
  SetFocus(hWnd: g_hwndCommandCombo);
  PostMessageA(hWnd: g_hwndCommandCombo, Msg: 0x100u, wParam, lParam);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042BBF0
// Name: long CommandWindow_SubclassedProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall CommandWindow_SubclassedProc(HWND__ *hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if ( msg != 256 )
  {
    if ( msg == 258 )
    {
      if ( wParam != 13 )
        return CallWindowProcA(lpPrevWndFunc: g_hwndCommandSubclassed, hWnd: hDlg, Msg: msg, wParam, lParam);
      return 0;
    }
    if ( msg != 260 )
      return CallWindowProcA(lpPrevWndFunc: g_hwndCommandSubclassed, hWnd: hDlg, Msg: msg, wParam, lParam);
  }
  if ( CommandWindow_HandleKey(wParam) == 0 )
    return CallWindowProcA(lpPrevWndFunc: g_hwndCommandSubclassed, hWnd: hDlg, Msg: msg, wParam, lParam);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042BC50
// Name: void Main_SizeWindow(struct HWND__ __near *,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Main_SizeWindow(HWND__ *hDlg, unsigned int wParam, int cx, int cy)
{
  int bottom; // edi
  HWND v5; // ebx
  int v6; // ebx
  int v7; // edi
  tagRECT rcOut; // [esp+8h] [ebp-44h] BYREF
  tagRECT rcStaticCmd; // [esp+18h] [ebp-34h] BYREF
  tagRECT rcHint; // [esp+28h] [ebp-24h] BYREF
  tagRECT rcCmd; // [esp+38h] [ebp-14h] BYREF
  HWND__ *hStaticCmd; // [esp+48h] [ebp-4h]

  if ( cx != 0 && (bottom = cy, cy != 0) )
  {
    v5 = hDlg;
  }
  else
  {
    v5 = hDlg;
    GetClientRect(hWnd: hDlg, lpRect: &rcOut);
    bottom = rcOut.bottom;
    cx = rcOut.right;
  }
  if ( g_hwndCommandCombo != nullptr && cx > 64 && bottom > 64 )
  {
    GetWindowRect(hWnd: g_hwndCommandCombo, lpRect: &rcCmd);
    ScreenToClient(hWnd: v5, lpPoint: (LPPOINT)&rcCmd);
    ScreenToClient(hWnd: v5, lpPoint: (LPPOINT)&rcCmd.right);
    v6 = rcCmd.bottom - rcCmd.top;
    v7 = bottom - (rcCmd.bottom - rcCmd.top) - 8;
    SetWindowPos(
      hWnd: g_hwndCommandCombo,
      hWndInsertAfter: nullptr,
      X: rcCmd.left,
      Y: v7,
      cx: cx - rcCmd.left - 8,
      cy: rcCmd.bottom - rcCmd.top,
      uFlags: 4u);
    GetWindowRect(hWnd: g_hwndCommandHint, lpRect: &rcHint);
    ScreenToClient(hWnd: g_hDlgMain, lpPoint: (LPPOINT)&rcHint);
    ScreenToClient(hWnd: g_hDlgMain, lpPoint: (LPPOINT)&rcHint.right);
    SetWindowPos(
      hWnd: g_hwndCommandHint,
      hWndInsertAfter: nullptr,
      X: rcCmd.left,
      Y: rcHint.top - rcHint.bottom + rcCmd.top - 5,
      cx: 0,
      cy: 0,
      uFlags: 5u);
    hStaticCmd = GetDlgItem(hDlg: g_hDlgMain, nIDDlgItem: 113);
    GetWindowRect(hWnd: hStaticCmd, lpRect: &rcStaticCmd);
    ScreenToClient(hWnd: hDlg, lpPoint: (LPPOINT)&rcStaticCmd);
    ScreenToClient(hWnd: hDlg, lpPoint: (LPPOINT)&rcStaticCmd.right);
    SetWindowPos(
      hWnd: hStaticCmd,
      hWndInsertAfter: nullptr,
      X: 8,
      Y: (v6 + rcStaticCmd.top - rcStaticCmd.bottom) / 2 + v7 - 1,
      cx: 0,
      cy: 0,
      uFlags: 5u);
    GetWindowRect(hWnd: g_hwndOutputWindow, lpRect: &rcOut);
    ScreenToClient(hWnd: hDlg, lpPoint: (LPPOINT)&rcOut);
    SetWindowPos(
      hWnd: g_hwndOutputWindow,
      hWndInsertAfter: nullptr,
      X: 0,
      Y: 0,
      cx: cx - rcOut.left - 8,
      cy: v7 - rcOut.top - 8,
      uFlags: 6u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BDE0
// Name: int _SortCommands(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _SortCommands(const char **a, const char **b)
{
  return _V_stricmp(s1: *a, s2: *b);
}

//------------------------------------------------------------------------------
// Address: 0x0042BE00
// Name: void EnableCommandHint(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableCommandHint(bool enable)
{
  int v1; // edi
  int matched; // esi
  signed int v3; // ebx
  signed int v4; // edx
  int v5; // eax
  WPARAM v6; // edi
  signed int i; // esi
  LRESULT v8; // eax
  int v9; // ecx
  BOOL v10; // eax
  const char *cmds[256]; // [esp+0h] [ebp-51Ch] BYREF
  char strCmd[260]; // [esp+400h] [ebp-11Ch] BYREF
  tagRECT rcCmd; // [esp+504h] [ebp-18h] BYREF
  int n; // [esp+514h] [ebp-8h]
  int maxLen; // [esp+518h] [ebp-4h]

  if ( enable )
  {
    GetWindowTextA(hWnd: g_hwndCommandCombo, lpString: strCmd, nMaxCount: 260);
    if ( strCmd[0] != 0 )
    {
      SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x184u, wParam: 0, lParam: 0);
      v1 = 0;
      maxLen = 0;
      matched = MatchLocalCommands(cmdStr: strCmd, cmdList: cmds, maxCmds: 256);
      v3 = MatchRemoteCommands(pCmdStr: strCmd, cmdList: &cmds[matched], maxCmds: 256 - matched) + matched;
      v4 = 0;
      if ( v3 <= 0 )
        goto LABEL_9;
      do
      {
        v5 = strlen(cmds[v4]);
        if ( v1 < v5 )
        {
          maxLen = v5;
          v1 = v5;
        }
        ++v4;
      }
      while ( v4 < v3 );
      if ( v1 != 0 )
      {
        qsort(base: cmds, num: v3, width: 4u, comp: (int (__cdecl *)(const void *, const void *))_SortCommands);
        v6 = -1;
        n = strlen(strCmd);
        for ( i = 0; i < v3; ++i )
        {
          SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x180u, wParam: 0, lParam: (LPARAM)cmds[i]);
          if ( v6 == -1 && V_strncasecmp(s1: strCmd, s2: cmds[i], n) == 0 )
            v6 = i;
        }
        if ( v6 != -1 )
        {
          SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x186u, wParam: v6, lParam: 0);
          if ( v6 == 0 )
            SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x197u, wParam: 0, lParam: 0);
        }
        GetWindowRect(hWnd: g_hwndCommandCombo, lpRect: &rcCmd);
        ScreenToClient(hWnd: g_hDlgMain, lpPoint: (LPPOINT)&rcCmd);
        ScreenToClient(hWnd: g_hDlgMain, lpPoint: (LPPOINT)&rcCmd.right);
        v8 = SendMessageA(hWnd: g_hwndCommandHint, Msg: 0x1A1u, wParam: 0, lParam: 0);
        if ( v8 > 0 )
        {
          v9 = v8 * v3 + 2;
          if ( v9 > rcCmd.top - 8 )
            v9 = rcCmd.top - 8;
          SetWindowPos(
            hWnd: g_hwndCommandHint,
            hWndInsertAfter: nullptr,
            X: rcCmd.left,
            Y: rcCmd.top - v9 - 4,
            cx: g_fixedFontMetrics.tmMaxCharWidth * (maxLen + 5),
            cy: v9,
            uFlags: 4u);
        }
        else
        {
          enable = false;
        }
      }
      else
      {
LABEL_9:
        enable = false;
      }
    }
    else
    {
      enable = false;
    }
  }
  v10 = IsWindowVisible(hWnd: g_hwndCommandHint);
  if ( enable )
  {
    if ( !v10 )
      ShowWindow(hWnd: g_hwndCommandHint, nCmdShow: 8);
  }
  else if ( v10 )
  {
    ShowWindow(hWnd: g_hwndCommandHint, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C050
// Name: int CmdToArgv(char __near *,char __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CmdToArgv(char *str, char **argv, int maxargs)
{
  char *v3; // esi
  int v4; // ebx
  int v5; // edi
  char *v6; // edx
  char v7; // cl
  char v8; // cl
  char v9; // dl
  char *i; // ecx
  char *strNil; // [esp+14h] [ebp+8h]

  v3 = str;
  v4 = 0;
  v5 = 0;
  v6 = &str[lstrlenA(lpString: str)];
  strNil = v6;
  while ( v5 < maxargs )
  {
    v7 = *v3;
    if ( *v3 == 0 )
      goto LABEL_7;
    while ( v7 == 32 )
    {
      v7 = *++v3;
      if ( v7 == 0 )
      {
        argv[v5++] = v6;
        goto LABEL_18;
      }
    }
    v8 = *v3;
    if ( *v3 != 0 )
    {
      if ( v8 == 34 || v8 == 39 )
        v9 = *v3++;
      else
        v9 = 32;
      for ( i = v3; *i != 0; ++i )
      {
        if ( *i == v9 )
          break;
      }
      argv[v5++] = v3;
      v4 = v5;
      v3 = i + 1;
      if ( *i == 0 )
        v3 = i;
      v6 = strNil;
      *i = 0;
    }
    else
    {
LABEL_7:
      argv[v5++] = v6;
    }
LABEL_18:
    ;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0042C0E0
// Name: void CreateCommandHint(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateCommandHint()
{
  g_hwndCommandHint = CreateWindowExA(
                        dwExStyle: 4u,
                        lpClassName: "LISTBOX",
                        lpWindowName: &defValue,
                        dwStyle: 0x40A00040u,
                        X: 0,
                        Y: 0,
                        nWidth: 100,
                        nHeight: 0,
                        hWndParent: g_hDlgMain,
                        hMenu: (HMENU)0x29A,
                        hInstance: g_hInstance,
                        lpParam: nullptr);
  BringWindowToTop(hWnd: g_hwndCommandHint);
  SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 666, Msg: 0x30u, wParam: (WPARAM)g_hFixedFont, lParam: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042C140
// Name: bool CreateResources(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateResources()
{
  LONG *v1; // eax
  HDC WindowDC; // edi
  int DeviceCaps; // eax
  int v4; // esi
  HDC v5; // esi
  tagLOGFONTA lf; // [esp+0h] [ebp-48h] BYREF
  tagINITCOMMONCONTROLSEX initCommon; // [esp+3Ch] [ebp-Ch] BYREF
  HFONT__ *hFontOld; // [esp+44h] [ebp-4h]

  initCommon.dwSize = 8;
  initCommon.dwICC = 513;
  if ( !InitCommonControlsEx(picce: &initCommon) )
    return 0;
  g_hRichEdit = LoadLibraryA(lpLibFileName: "Riched32.dll");
  if ( g_hRichEdit == nullptr )
    return 0;
  g_hBackgroundBrush = CreateSolidBrush(color: g_backgroundColor);
  g_hIcons = (LONG)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xC8);
  dword_4B6938 = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xC9);
  dword_4B693C = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xCA);
  dword_4B6940 = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xCC);
  dword_4B6944 = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xCB);
  v1 = &g_hIcons;
  do
  {
    if ( *v1 == 0 )
      return 0;
    ++v1;
  }
  while ( (int)v1 < (int)&g_connectFailure );
  WindowDC = GetWindowDC(hWnd: nullptr);
  DeviceCaps = GetDeviceCaps(hdc: WindowDC, index: 90);
  v4 = -MulDiv(nNumber: 10, nNumerator: DeviceCaps, nDenominator: 72);
  ReleaseDC(hWnd: nullptr, hDC: WindowDC);
  memset(dst: (unsigned __int8 *)&lf, value: 0, count: sizeof(lf));
  lf.lfHeight = v4 - 1;
  lf.lfWeight = 400;
  strcpy(lf.lfFaceName, "Courier");
  g_hFixedFont = CreateFontIndirectA(lplf: &lf);
  if ( g_hFixedFont == nullptr )
    return 0;
  memset(dst: (unsigned __int8 *)&lf, value: 0, count: sizeof(lf));
  strcpy(lf.lfFaceName, "Tahoma");
  lf.lfHeight = -11;
  lf.lfWeight = 400;
  g_hProportionalFont = CreateFontIndirectA(lplf: &lf);
  if ( g_hProportionalFont == nullptr )
    return 0;
  v5 = GetWindowDC(hWnd: nullptr);
  hFontOld = (HFONT__ *)SelectObject(hdc: v5, h: g_hFixedFont);
  GetTextMetricsA(hdc: v5, lptm: &g_fixedFontMetrics);
  SelectObject(hdc: v5, h: hFontOld);
  ReleaseDC(hWnd: nullptr, hDC: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042C310
// Name: void Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shutdown()
{
  BugReporter_FreeInterfaces();
  InstallDlg_Shutdown();
  if ( g_PrintQueue.bInit )
  {
    DeleteCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
    g_PrintQueue.bInit = false;
  }
  if ( g_hCommandReadyEvent != nullptr )
  {
    CloseHandle(hObject: g_hCommandReadyEvent);
    g_hCommandReadyEvent = nullptr;
  }
  if ( g_hRichEdit != nullptr )
  {
    FreeLibrary(hLibModule: g_hRichEdit);
    g_hRichEdit = nullptr;
  }
  if ( g_hBackgroundBrush != nullptr )
  {
    DeleteObject(ho: g_hBackgroundBrush);
    g_hBackgroundBrush = nullptr;
  }
  if ( g_hFixedFont != nullptr )
  {
    DeleteObject(ho: g_hFixedFont);
    g_hFixedFont = nullptr;
  }
  if ( g_hProportionalFont != nullptr )
  {
    DeleteObject(ho: g_hProportionalFont);
    g_hProportionalFont = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C3B0
// Name: bool InitSubWindows(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall InitSubWindows@<al>(const char *a1@<ebp>)
{
  return BugDlg_Init() != 0
      && CpuProfile_Init(a1) != 0
      && TexProfile_Init(a1) != 0
      && MemProfile_Init(a1) != 0
      && Bindings_Init(a1) != 0
      && ShowDataCache_Init(a1) != 0
      && ShowMaterials_Init(a1) != 0
      && ShowTextures_Init(a1) != 0
      && ShowSounds_Init(a1) != 0
      && ShowModels_Init(a1) != 0
      && ShowMemDump_Init(a1) != 0
      && ShowBudget_Init(a1)
      && TimeStampLog_Init(a1) != 0
      && InstallDlg_Init() != 0
      && ShowVProfNodes_Init(a1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042C440
// Name: void SetActiveVersion(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetActiveVersion(unsigned int nVersion)
{
  if ( g_nActiveVersion != nVersion )
  {
    g_nActiveVersion = nVersion;
    SetMainWindowTitle();
    if ( g_nActiveVersion != g_nImageVersion )
      ConsoleWindowPrintf(rgb: -16777216, strFormat: "Active Image: %d\n", g_nActiveVersion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C480
// Name: void SetImageVersion(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetImageVersion(unsigned int nVersion)
{
  if ( g_nImageVersion != nVersion )
  {
    g_nImageVersion = nVersion;
    SetMainWindowTitle();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C4A0
// Name: void DmAPI_DisplayError(char const __near *,long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DmAPI_DisplayError(const char *message, HRESULT hr)
{
  char strError[128]; // [esp+4h] [ebp-80h] BYREF

  ConsoleWindowPrintf(rgb: 255, strFormat: "%s\n", message);
  if ( DmTranslateErrorA(a1: hr, a2: strError, a3: 128) >= 0 && strError[0] != 0 )
    ConsoleWindowPrintf(rgb: 255, strFormat: "Reason: '%s'\n", strError);
  else
    ConsoleWindowPrintf(rgb: 255, strFormat: "Reason: 0x%08lx\n", hr);
}

//------------------------------------------------------------------------------
// Address: 0x0042C510
// Name: long DmAPI_SendCommand(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl DmAPI_SendCommand(const char *strCommand, unsigned int wait)
{
  const char *v3; // esi
  bool v4; // bl
  bool v5; // zf
  int i; // esi
  int v7; // eax
  char *v8; // edi
  int v9; // eax
  char *v10; // [esp-14h] [ebp-118h]
  char *v11; // [esp-10h] [ebp-114h]
  char strResponse[260]; // [esp+0h] [ebp-104h] BYREF

  if ( WaitForSingleObject(hHandle: g_hCommandReadyEvent, dwMilliseconds: -((unsigned __int8)wait != 0)) != 0 )
    return -2099642368;
  ResetEvent(hEvent: g_hCommandReadyEvent);
  v3 = strCommand;
  v4 = false;
  v5 = *strCommand == 42;
  wait = 260;
  strResponse[0] = 0;
  if ( v5 )
    v3 = strCommand + 1;
  else
    v4 = _V_stricmp(s1: strCommand, s2: "XCMD!") == 0;
  i = DmSendCommand(a1: g_pdmConnection, a2: v3, a3: strResponse, a4: &wait);
  if ( i >= 0 )
  {
    switch ( i )
    {
      case 47841280:
        if ( v4 )
          break;
        strstr(str1: (unsigned __int8 *)strResponse, str2: "XACK");
        if ( v7 != 0 )
        {
          v8 = (char *)(v7 + 4);
          if ( _V_stricmp(s1: (const char *)(v7 + 4), s2: "OK") == 0 )
            break;
        }
        else
        {
          v8 = strResponse;
        }
        if ( V_strnicmp(s1: v8, s2: "Rejecting Connection:", n: 21) != 0 )
        {
          v9 = V_strnicmp(s1: v8, s2: "Cannot Execute:", n: 15);
          v11 = v8;
          v10 = "%s\n";
          if ( v9 == 0 )
            goto LABEL_24;
          ConsoleWindowPrintf(rgb: 0, strFormat: "%s\n", v8);
        }
        else
        {
          ConsoleWindowPrintf(rgb: 255, strFormat: "%s\n", v8);
          g_bForceDisconnect = true;
        }
        break;
      case 47841282:
        wait = 260;
        for ( i = DmReceiveSocketLine(a1: g_pdmConnection, a2: strResponse, a3: &wait);
              i >= 0;
              i = DmReceiveSocketLine(a1: g_pdmConnection, a2: strResponse, a3: &wait) )
        {
          if ( strResponse[0] == 46 )
            break;
          ConsoleWindowPrintf(rgb: 0, strFormat: "%s\n", strResponse);
          wait = 260;
        }
        break;
      case 47841283:
        ConsoleWindowPrintf(rgb: 0, strFormat: "Binary response - not implemented\n");
        break;
      case 47841284:
        ConsoleWindowPrintf(rgb: 0, strFormat: "Ready for binary - not implemented\n");
        break;
      default:
        v11 = strResponse;
        v10 = "Unknown Response: ( %s ).\n";
LABEL_24:
        ConsoleWindowPrintf(rgb: 255, strFormat: v10, v11);
        break;
    }
  }
  SetEvent(hEvent: g_hCommandReadyEvent);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0042C720
// Name: void ProcessPrintQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessPrintQueue()
{
  int i; // esi

  EnterCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
  for ( i = 0; i < g_PrintQueue.numMessages; ++i )
  {
    ConsoleWindowPrintf(rgb: g_PrintQueue.aColors[i], strFormat: "%s", g_PrintQueue.pMessages[i]);
    Sys_Free(ptr: g_PrintQueue.pMessages[i]);
  }
  g_PrintQueue.numMessages = 0;
  LeaveCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x0042C790
// Name: bool ProcessCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ProcessCommand(const char *strCmdIn)
{
  int v2; // esi
  localCommand_t *v3; // edi
  int v4; // esi
  int v5; // esi
  void (__cdecl *v6)(int, char **); // ecx
  int v7; // edx
  int v8; // eax
  HRESULT v9; // esi
  char strRemoteCmd[524]; // [esp+0h] [ebp-6E4h] BYREF
  char strCmd[512]; // [esp+20Ch] [ebp-4D8h] BYREF
  char strCmdBak[512]; // [esp+40Ch] [ebp-2D8h] BYREF
  char v13[128]; // [esp+60Ch] [ebp-D8h] BYREF
  char *argv[20]; // [esp+68Ch] [ebp-58h] BYREF
  int isXCommand; // [esp+6DCh] [ebp-8h]
  int argc; // [esp+6E0h] [ebp-4h]

  isXCommand = 0;
  V_strncpy(pDest: strCmd, pSrc: strCmdIn, maxLen: 512);
  lstrcpyA(lpString1: strCmdBak, lpString2: strCmd);
  ConsoleWindowPrintf(rgb: 0, strFormat: "] %s\n", strCmd);
  argc = CmdToArgv(str: strCmd, argv, maxargs: 20);
  if ( argc == 0 )
    return 1;
  if ( SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x146u, wParam: 0, lParam: 0) >= 25 )
    SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x144u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)strCmdBak);
  SendMessageA(hWnd: g_hwndCommandCombo, Msg: 0x14Eu, wParam: 0xFFFFFFFF, lParam: 0);
  v2 = 0;
  v3 = g_localCommands;
  while ( lstrcmpiA(lpString1: v3->strCommand, lpString2: argv[0]) != 0 )
  {
    ++v2;
    ++v3;
    if ( v2 >= 38 )
    {
      if ( g_connectedToApp )
      {
        v4 = 0;
        if ( (int)g_numRemoteCommands > 0 )
        {
          while ( lstrcmpiA(lpString1: g_remoteCommands[v4]->strCommand, lpString2: argv[0]) != 0 )
          {
            if ( ++v4 >= (int)g_numRemoteCommands )
              goto LABEL_12;
          }
          if ( !g_connectedToApp )
          {
LABEL_22:
            ConsoleWindowPrintf(rgb: 255, strFormat: "'%s' is not available until connected to Application.\n", argv[0]);
            return 1;
          }
LABEL_28:
          lstrcpyA(lpString1: strRemoteCmd, lpString2: "XCMD!");
          lstrcatA(lpString1: strRemoteCmd, lpString2: strCmdBak);
LABEL_29:
          v9 = DmAPI_SendCommand(strCommand: strRemoteCmd, wait: 1u);
          if ( v9 >= 0 )
            return 1;
          ConsoleWindowPrintf(rgb: 255, strFormat: "%s\n", "DmSendCommand");
          if ( DmTranslateErrorA(a1: v9, a2: v13, a3: 128) >= 0 && v13[0] != 0 )
          {
            ConsoleWindowPrintf(rgb: 255, strFormat: "Reason: '%s'\n", v13);
            return 0;
          }
          else
          {
            ConsoleWindowPrintf(rgb: 255, strFormat: "Reason: 0x%08lx\n", v9);
            return 0;
          }
        }
LABEL_12:
        if ( g_connectedToApp )
          goto LABEL_28;
      }
      ConsoleWindowPrintf(rgb: 255, strFormat: "'%s' is not a recognized command.\n", argv[0]);
      return 1;
    }
  }
  v5 = 4 * v2;
  v6 = *(void (__cdecl **)(int, char **))((char *)&off_4656B8 + v5 * 4);
  v7 = 1;
  if ( v6 != nullptr )
    v7 = isXCommand;
  v8 = dword_4656B4[v5];
  if ( (v8 & 1) != 0 && g_connectedToXBox == 0 )
  {
    ConsoleWindowPrintf(rgb: 255, strFormat: "'%s' is not available until connected to XBox.\n", argv[0]);
    return 1;
  }
  if ( (v8 & 2) != 0 && !g_connectedToApp )
    goto LABEL_22;
  if ( v7 != 0 )
  {
    lstrcpyA(lpString1: strRemoteCmd, lpString2: strCmdBak);
    goto LABEL_29;
  }
  v6(a1: argc, a2: argv);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042CA40
// Name: long Main_DlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
HGDIOBJ __stdcall Main_DlgProc(HWND__ *hDlg, UINT message, WPARAM wParam, unsigned int lParam)
{
  HGDIOBJ result; // eax
  char strCmd[264]; // [esp+Ch] [ebp-108h] BYREF

  if ( message > 0x111 )
  {
    if ( message > 0x134 )
    {
      if ( message == 1024 )
      {
        ProcessPrintQueue();
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      }
      if ( message == 1025 )
      {
        if ( g_cvarsReceivedTimer == 0 )
          g_cvarsReceivedTimer = SetTimer(hWnd: g_hDlgMain, nIDEvent: 0x1003u, uElapse: 0x3E8u, lpTimerFunc: nullptr);
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      }
      if ( message != 0x8000 )
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      GetWindowTextA(hWnd: g_hwndCommandCombo, lpString: strCmd, nMaxCount: 260);
      ProcessCommand(strCmdIn: strCmd);
      SetWindowTextA(hWnd: g_hwndCommandCombo, lpString: &defValue);
      goto LABEL_88;
    }
    if ( message >= 0x133 )
    {
      SetBkColor(hdc: (HDC)wParam, color: g_backgroundColor);
      SetTextColor(hdc: (HDC)wParam, color: g_textColor);
      return g_hBackgroundBrush;
    }
    if ( message == 274 )
    {
      if ( (_WORD)wParam == 0xF060 )
      {
LABEL_82:
        PostMessageA(hWnd: hDlg, Msg: 0x10u, wParam: 0, lParam: 0);
        return nullptr;
      }
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    }
    if ( message != 275 )
    {
      if ( message == 278 )
      {
        CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0x9C49u, uCheck: g_autoConnect != 0 ? 8 : 0);
        CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC580u, uCheck: g_captureGameSpew != 0 ? 8 : 0);
        CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC581u, uCheck: g_captureDebugSpew != 0 ? 8 : 0);
        CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0x9C48u, uCheck: g_debugCommands != 0 ? 8 : 0);
        EnableMenuItem(hMenu: (HMENU)wParam, uIDEnableItem: 0xC5CCu, uEnable: g_connectedToXBox == 0);
        EnableMenuItem(hMenu: (HMENU)wParam, uIDEnableItem: 0xC5D6u, uEnable: g_connectedToXBox == 0);
        EnableMenuItem(hMenu: (HMENU)wParam, uIDEnableItem: 0xC567u, uEnable: g_connectedToXBox == 0);
        EnableMenuItem(hMenu: (HMENU)wParam, uIDEnableItem: 0xC5D4u, uEnable: g_connectedToXBox == 0);
        EnableMenuItem(hMenu: (HMENU)wParam, uIDEnableItem: 0xC5D3u, uEnable: g_connectedToXBox == 0);
        CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC5D8u, uCheck: g_DisplayTTY != 0 ? 8 : 0);
        return nullptr;
      }
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    }
    if ( g_AssertDialogActive )
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    if ( (_WORD)wParam == 4096 )
    {
      AutoConnectTimerProc();
      return nullptr;
    }
    if ( (_WORD)wParam == 4098 )
    {
      if ( !g_connectedToApp )
      {
        InstallDlg_ImagePollTimerProc();
        return nullptr;
      }
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    }
    if ( (_WORD)wParam != 4099 )
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    if ( g_playtestMode != 0 && g_connectedToApp )
      ProcessCommand(strCmdIn: "exec playtest.360.cfg");
    if ( g_cvarsReceivedTimer != 0 )
    {
      KillTimer(hWnd: g_hDlgMain, uIDEvent: 0x1003u);
      g_cvarsReceivedTimer = 0;
    }
    return nullptr;
  }
  else
  {
    if ( message != 273 )
    {
      switch ( message )
      {
        case 2u:
          SetWindowLongA(hWnd: g_hwndCommandCombo, nIndex: -4, dwNewLong: (LONG)g_hwndCommandSubclassed);
          SetWindowLongA(hWnd: g_hwndOutputWindow, nIndex: -4, dwNewLong: (LONG)g_hwndOutputSubclassed);
          PostQuitMessage(nExitCode: 0);
          return nullptr;
        case 5u:
          Main_SizeWindow(hDlg, wParam, cx: (unsigned __int16)lParam, cy: HIWORD(lParam));
          break;
        case 0x10u:
          lc_disconnect();
          SaveConfig();
          DestroyWindow(hWnd: hDlg);
          break;
        default:
          break;
      }
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    }
    if ( (unsigned __int16)wParam > 0xC546u )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0xC54Du:
          ShowSounds_Open();
          result = nullptr;
          break;
        case 0xC554u:
          TexProfileSamples_Open();
          result = nullptr;
          break;
        case 0xC555u:
          TexProfileHistory_Open();
          result = nullptr;
          break;
        case 0xC558u:
          ShowMemDump_Open();
          result = nullptr;
          break;
        case 0xC567u:
          InstallDlg_Open();
          result = nullptr;
          break;
        case 0xC578u:
          BugDlg_Open();
          result = nullptr;
          break;
        case 0xC580u:
          g_captureGameSpew ^= 1u;
          result = nullptr;
          break;
        case 0xC581u:
          g_captureDebugSpew ^= 1u;
          result = nullptr;
          break;
        case 0xC58Bu:
          MemProfile_Open();
          result = nullptr;
          break;
        case 0xC59Eu:
          ShowDataCache_Open();
          result = nullptr;
          break;
        case 0xC5C9u:
          ShowVProfNodes_Open();
          result = nullptr;
          break;
        case 0xC5CCu:
          CrashDumps_Publish();
          result = nullptr;
          break;
        case 0xC5D3u:
          SyncDvdDevCache(bForce: true);
          result = nullptr;
          break;
        case 0xC5D4u:
          SyncShaderCache(bForce: true);
          result = nullptr;
          break;
        case 0xC5D6u:
          EmulateDlg_Open();
          result = nullptr;
          break;
        case 0xC5D7u:
          lc_cls();
          result = nullptr;
          break;
        case 0xC5D8u:
          g_DisplayTTY ^= 1u;
          result = nullptr;
          break;
        default:
          goto LABEL_59;
      }
    }
    else
    {
      if ( (unsigned __int16)wParam == 50502 )
      {
        TimeStampLog_Open();
        return nullptr;
      }
      if ( (unsigned __int16)wParam <= 0x9C48u )
      {
        if ( (unsigned __int16)wParam == 40008 )
        {
          g_debugCommands ^= 1u;
          return nullptr;
        }
        if ( (unsigned __int16)wParam == 1000 )
        {
          if ( HIWORD(wParam) == 3 )
          {
LABEL_17:
            EnableCommandHint(enable: true);
            return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
          }
          if ( HIWORD(wParam) != 4 )
          {
            if ( HIWORD(wParam) == 5 )
              goto LABEL_17;
            return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
          }
LABEL_88:
          EnableCommandHint(enable: false);
          return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
        }
LABEL_59:
        if ( (unsigned __int16)wParam >= 0xC352u && (unsigned __int16)wParam < 0xC384u )
        {
          Bindings_MenuSelection(wID: (unsigned __int16)wParam);
          return nullptr;
        }
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      }
      if ( (unsigned __int16)wParam > 0x9CD4u )
      {
        if ( (unsigned __int16)wParam > 0x9CDBu )
        {
          if ( (unsigned __int16)wParam == 50001 )
          {
            Bindings_Open();
            return nullptr;
          }
        }
        else
        {
          switch ( (unsigned __int16)wParam )
          {
            case 0x9CDBu:
              ShowModels_Open();
              return nullptr;
            case 0x9CD5u:
              CpuProfileHistory_Open();
              return nullptr;
            case 0x9CDAu:
              ShowMaterials_Open();
              return nullptr;
            default:
              break;
          }
        }
        goto LABEL_59;
      }
      if ( (unsigned __int16)wParam == 40148 )
      {
        CpuProfileSamples_Open();
        return nullptr;
      }
      else
      {
        switch ( (unsigned __int16)wParam )
        {
          case 0x9C49u:
            if ( g_connectedToXBox != 0 || g_connectedToApp || g_autoConnect != 0 )
            {
              lc_disconnect();
              result = nullptr;
            }
            else
            {
              lc_autoConnect();
              result = nullptr;
            }
            break;
          case 0x9C51u:
            goto LABEL_82;
          case 0x9C52u:
            ConfigDlg_Open();
            result = nullptr;
            break;
          case 0x9CC2u:
            ShowTextures_Open();
            result = nullptr;
            break;
          case 0x9CC3u:
            ShowBudget_Open();
            result = nullptr;
            break;
          default:
            goto LABEL_59;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042D240
// Name: void SetConnectionIcon(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetConnectionIcon(int icon)
{
  LONG v1; // [esp-4h] [ebp-8h]

  if ( icon == 1 && g_nActiveVersion != 0 )
  {
    g_nActiveVersion = 0;
    SetMainWindowTitle();
    if ( g_nActiveVersion != g_nImageVersion )
      ConsoleWindowPrintf(rgb: -16777216, strFormat: "Active Image: %d\n", g_nActiveVersion);
  }
  if ( g_currentIcon != icon )
  {
    v1 = *(&g_hIcons + icon);
    g_currentIcon = icon;
    SetClassLongA(hWnd: g_hDlgMain, nIndex: -14, dwNewLong: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D2B0
// Name: bool Startup(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Startup()
{
  const char *v0; // ebx
  const char *v1; // edi
  void *v2; // esp
  void *v3; // ecx
  HWND DialogParamA; // eax
  HWND Window; // eax
  LONG WindowLongA; // eax
  int v8; // eax
  char v9[12]; // [esp+0h] [ebp-70h] BYREF
  _charformat v10; // [esp+Ch] [ebp-64h] BYREF
  tagWNDCLASSA wndclass; // [esp+48h] [ebp-28h] BYREF
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  v0 = getenv(option: "path");
  v1 = getenv(option: "xedk");
  if ( v1 == nullptr )
    v1 = &defValue;
  v2 = alloca(strlen(v1) + strlen(v0) + 256);
  sprintf(string: v9, format: "path=%s;%s\\bin\\win32", v0, v1);
  _putenv(option: v9);
  if ( LoadLibraryA(lpLibFileName: "xbdm.dll") == nullptr )
  {
    if ( *v1 != 0 )
      Sys_Error(format: "Couldn't load xbdm.dll");
    else
      Sys_Error(format: "Couldn't load xbdm.dll\nXEDK environment variable not set.");
  }
  LoadConfig(this: v3);
  if ( CreateResources() == 0 )
    return 0;
  InitializeCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
  g_PrintQueue.bInit = true;
  g_hCommandReadyEvent = CreateEventA(
                           lpEventAttributes: nullptr,
                           bManualReset: true,
                           bInitialState: true,
                           lpName: nullptr);
  memset(&wndclass.hCursor, 0, 16);
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))Main_DlgProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 34;
  wndclass.hInstance = g_hInstance;
  wndclass.hIcon = (HICON__ *)dword_4B6938;
  wndclass.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hbrBackground = (HBRUSH__ *)g_hBackgroundBrush;
  wndclass.lpszMenuName = (const char *)100;
  wndclass.lpszClassName = aVxconsol;
  if ( RegisterClassA(lpWndClass: &wndclass) == 0 )
    return 0;
  g_hAccel = LoadAcceleratorsA(hInstance: g_hInstance, lpTableName: (LPCSTR)0xBB8);
  if ( g_hAccel == nullptr )
    return 0;
  DialogParamA = CreateDialogParamA(
                   hInstance: g_hInstance,
                   lpTemplateName: (LPCSTR)0x68,
                   hWndParent: nullptr,
                   lpDialogFunc: nullptr,
                   dwInitParam: 0);
  g_hDlgMain = DialogParamA;
  if ( DialogParamA == nullptr )
    return 0;
  SetWindowLongA(hWnd: DialogParamA, nIndex: 30, dwNewLong: g_configID);
  g_hwndOutputWindow = GetDlgItem(hDlg: g_hDlgMain, nIDDlgItem: 1010);
  g_hwndCommandCombo = GetDlgItem(hDlg: g_hDlgMain, nIDDlgItem: 1000);
  CreateCommandHint();
  Window = GetWindow(hWnd: g_hwndCommandCombo, uCmd: 5u);
  g_hwndCommandSubclassed = (WNDPROC)SetWindowLongA(
                                       hWnd: Window,
                                       nIndex: -4,
                                       dwNewLong: (LONG)CommandWindow_SubclassedProc);
  g_hwndOutputSubclassed = (WNDPROC)SetWindowLongA(
                                      hWnd: g_hwndOutputWindow,
                                      nIndex: -4,
                                      dwNewLong: (LONG)OutputWindow_SubclassedProc);
  v10.cbSize = 60;
  SendMessageA(hWnd: g_hwndOutputWindow, Msg: 0x43Au, wParam: 0, lParam: (LPARAM)&v10);
  v10.dwMask &= ~0x40000000u;
  v10.yHeight = 200;
  lstrcpyA(lpString1: v10.szFaceName, lpString2: aCour);
  SendMessageA(hWnd: g_hwndOutputWindow, Msg: 0x444u, wParam: 4u, lParam: (LPARAM)&v10);
  SendMessageA(hWnd: g_hwndOutputWindow, Msg: 0x443u, wParam: 0, lParam: g_backgroundColor);
  WindowLongA = GetWindowLongA(hWnd: g_hwndOutputWindow, nIndex: -16);
  SetWindowLongA(hWnd: g_hwndOutputWindow, nIndex: -16, dwNewLong: WindowLongA | 0x4000000);
  SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1000, Msg: 0x30u, wParam: (WPARAM)g_hFixedFont, lParam: 1);
  SetMainWindowTitle();
  g_currentIcon = -1;
  SetConnectionIcon(icon: 1);
  InitSubWindows(a1: (const char *)&savedregs);
  jpeg_mem_term();
  ConsoleWindowPrintf(
    rgb: 0,
    strFormat: "VXConsole %s [%s Build: %s %s] [Protocol: %d]\n",
    "1.2",
    "Release",
    "Jul 15 2011",
    "03:46:02",
    300);
  ConsoleWindowPrintf(rgb: 0, strFormat: "type '*help' for list of commands...\n\n");
  if ( g_alwaysAutoConnect != 0 )
    lc_autoConnect();
  if ( g_mainWindowRect.right != 0 && g_mainWindowRect.bottom != 0 )
    MoveWindow(
      hWnd: g_hDlgMain,
      X: g_mainWindowRect.left,
      Y: g_mainWindowRect.top,
      nWidth: g_mainWindowRect.right - g_mainWindowRect.left,
      nHeight: g_mainWindowRect.bottom - g_mainWindowRect.top,
      bRepaint: false);
  v8 = 1;
  if ( g_startMinimized != 0 )
    v8 = 2;
  ShowWindow(hWnd: g_hDlgMain, nCmdShow: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D620
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *pCmdLine, int nCmdShow)
{
  HWND WindowA; // eax
  HWND v5; // esi
  DWORD LastError; // eax
  char str[256]; // [esp+4h] [ebp-19Ch] BYREF
  char buff[128]; // [esp+104h] [ebp-9Ch] BYREF
  tagMSG msg; // [esp+184h] [ebp-1Ch] BYREF

  memset(&msg, 0, sizeof(msg));
  g_pCommandLine = pCmdLine;
  g_hInstance = hInstance;
  buff[0] = 0;
  ParseCommandLineArg(pKey: "-config ", pValueBuff: buff, valueBuffSize: 128);
  g_configID = atoi(nptr: buff);
  MakeConfigString(
    pString: "HKEY_CURRENT_USER\\Software\\VXConsole\\3\\",
    configID: g_configID,
    pOutBuff: buff,
    outBuffSize: 128);
  Sys_SetRegistryPrefix(pPrefix: buff);
  WindowA = FindWindowA(lpClassName: aVxconsol, lpWindowName: nullptr);
  v5 = WindowA;
  if ( WindowA != nullptr && GetWindowLongA(hWnd: WindowA, nIndex: 30) == g_configID )
  {
    if ( IsIconic(hWnd: v5) )
      ShowWindow(hWnd: v5, nCmdShow: 9);
    SetForegroundWindow(hWnd: v5);
    return 0;
  }
  if ( Startup() == 0 )
  {
    LastError = GetLastError();
    FormatMessageA(
      dwFlags: 0x1200u,
      lpSource: nullptr,
      dwMessageId: LastError,
      dwLanguageId: 0,
      lpBuffer: str,
      nSize: 0xFFu,
      Arguments: nullptr);
    MessageBoxA(hWnd: nullptr, lpText: str, lpCaption: nullptr, uType: 0);
  }
  else if ( GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
  {
    do
    {
      if ( TranslateAcceleratorA(hWnd: g_hDlgMain, hAccTable: g_hAccel, lpMsg: &msg) == 0 )
      {
        TranslateMessage(lpMsg: &msg);
        DispatchMessageA(lpMsg: &msg);
      }
    }
    while ( GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) );
    Shutdown();
    return msg.wParam;
  }
  Shutdown();
  return msg.wParam;
}

//------------------------------------------------------------------------------
// Address: 0x0042D7AE
// Name: __declspec(dllimport) load__DmSetMemory(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall load__DmSetMemory(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7B8
// Name: __tailMerge_xbdm_DLL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _tailMerge_xbdm_DLL@<eax>(int (__stdcall **a1)()@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int (__stdcall *Helper2)(); // eax

  Helper2 = __delayLoadHelper2(pidd: &_DELAY_IMPORT_DESCRIPTOR_xbdm_DLL, ppfnIATEntry: a1);
  return ((int (__fastcall *)(int, int))Helper2)(a1: a3, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7C9
// Name: _DmSetMemory@16_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSetMemory(int a1, int a2, int a3, int a4)
{
  return __imp__DmSetMemory@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7CF
// Name: __declspec(dllimport) load__DmReceiveFileA(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmReceiveFileA(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmReceiveFileA, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7D9
// Name: _DmReceiveFileA@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmReceiveFileA(int a1, int a2)
{
  return __imp__DmReceiveFileA@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7DF
// Name: __declspec(dllimport) load__DmGetFileAttributes(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetFileAttributes(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetFileAttributes, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7E9
// Name: _DmGetFileAttributes@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetFileAttributes(int a1, int a2)
{
  return __imp__DmGetFileAttributes@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7EF
// Name: __declspec(dllimport) load__DmDeleteFile(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmDeleteFile(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmDeleteFile, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7F9
// Name: _DmDeleteFile@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmDeleteFile(int a1, int a2)
{
  return __imp__DmDeleteFile@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D7FF
// Name: __declspec(dllimport) load__DmGetMemory(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetMemory(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetMemory, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D809
// Name: _DmGetMemory@16_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetMemory(int a1, int a2, int a3, int a4)
{
  return __imp__DmGetMemory@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0042D80F
// Name: __declspec(dllimport) load__DmCloseDir(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmCloseDir(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmCloseDir, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D819
// Name: _DmCloseDir@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmCloseDir(int a1)
{
  return __imp__DmCloseDir@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D81F
// Name: __declspec(dllimport) load__DmWalkDir(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmWalkDir(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmWalkDir, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D829
// Name: _DmWalkDir@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmWalkDir(int a1, int a2, int a3)
{
  return __imp__DmWalkDir@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D82F
// Name: __declspec(dllimport) load__DmReadFilePartial(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmReadFilePartial(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmReadFilePartial, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D839
// Name: _DmReadFilePartial@20_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmReadFilePartial(int a1, int a2, int a3, int a4, int a5)
{
  return __imp__DmReadFilePartial@20(a1, a2, a3, a4, a5);
}

//------------------------------------------------------------------------------
// Address: 0x0042D83F
// Name: __declspec(dllimport) load__DmMkdir(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmMkdir(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmMkdir, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D849
// Name: _DmMkdir@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmMkdir(int a1)
{
  return __imp__DmMkdir@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D84F
// Name: __declspec(dllimport) load__DmSetFileAttributes(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmSetFileAttributes(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmSetFileAttributes, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D859
// Name: _DmSetFileAttributes@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSetFileAttributes(int a1, int a2)
{
  return __imp__DmSetFileAttributes@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D85F
// Name: __declspec(dllimport) load__DmSendFileA(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmSendFileA(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmSendFileA, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D869
// Name: _DmSendFileA@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSendFileA(int a1, int a2)
{
  return __imp__DmSendFileA@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D86F
// Name: __declspec(dllimport) load__DmGetThreadInfoEx(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetThreadInfoEx(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetThreadInfoEx, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D879
// Name: _DmGetThreadInfoEx@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetThreadInfoEx(int a1, int a2)
{
  return __imp__DmGetThreadInfoEx@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D87F
// Name: __declspec(dllimport) load__DmGetThreadList(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetThreadList(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetThreadList, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D889
// Name: _DmGetThreadList@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetThreadList(int a1, int a2)
{
  return __imp__DmGetThreadList@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D88F
// Name: __declspec(dllimport) load__DmCloseConnection(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmCloseConnection(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmCloseConnection, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D899
// Name: _DmCloseConnection@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmCloseConnection(int a1)
{
  return __imp__DmCloseConnection@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D89F
// Name: __declspec(dllimport) load__DmCloseNotificationSession(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmCloseNotificationSession(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmCloseNotificationSession, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8A9
// Name: _DmCloseNotificationSession@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmCloseNotificationSession(int a1)
{
  return __imp__DmCloseNotificationSession@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8AF
// Name: __declspec(dllimport) load__DmNotify(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmNotify(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmNotify, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8B9
// Name: _DmNotify@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmNotify(int a1, int a2, int a3)
{
  return __imp__DmNotify@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8BF
// Name: __declspec(dllimport) load__DmCrashDump()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmCrashDump(int a1, int a2)
{
  return _tailMerge_xbdm_DLL(a1: &DmCrashDump, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8C9
// Name: _DmCrashDump@0_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmCrashDump()
{
  return __imp__DmCrashDump@0();
}

//------------------------------------------------------------------------------
// Address: 0x0042D8CF
// Name: __declspec(dllimport) load__DmScreenShot(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmScreenShot(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmScreenShot, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8D9
// Name: _DmScreenShot@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmScreenShot(int a1)
{
  return __imp__DmScreenShot@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8DF
// Name: __declspec(dllimport) load__DmCloseModuleSections(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmCloseModuleSections(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmCloseModuleSections, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8E9
// Name: _DmCloseModuleSections@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmCloseModuleSections(int a1)
{
  return __imp__DmCloseModuleSections@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8EF
// Name: __declspec(dllimport) load__DmWalkModuleSections(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmWalkModuleSections(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmWalkModuleSections, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8F9
// Name: _DmWalkModuleSections@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmWalkModuleSections(int a1, int a2, int a3)
{
  return __imp__DmWalkModuleSections@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8FF
// Name: __declspec(dllimport) load__DmReboot(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmReboot(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmReboot, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D909
// Name: _DmReboot@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmReboot(int a1)
{
  return __imp__DmReboot@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D90F
// Name: __declspec(dllimport) load__DmSetTitle(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmSetTitle(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmSetTitle, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D919
// Name: _DmSetTitle@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSetTitle(int a1, int a2, int a3)
{
  return __imp__DmSetTitle@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D91F
// Name: __declspec(dllimport) load__DmResolveXboxName(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmResolveXboxName(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmResolveXboxName, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D929
// Name: _DmResolveXboxName@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmResolveXboxName(int a1)
{
  return __imp__DmResolveXboxName@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D92F
// Name: __declspec(dllimport) load__DmGetXboxName(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetXboxName(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetXboxName, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D939
// Name: _DmGetXboxName@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetXboxName(int a1, int a2)
{
  return __imp__DmGetXboxName@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D93F
// Name: __declspec(dllimport) load__DmOpenConnection(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmOpenConnection(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmOpenConnection, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D949
// Name: _DmOpenConnection@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmOpenConnection(int a1)
{
  return __imp__DmOpenConnection@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D94F
// Name: __declspec(dllimport) load__DmSetXboxName(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmSetXboxName(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmSetXboxName, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D959
// Name: _DmSetXboxName@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSetXboxName(int a1)
{
  return __imp__DmSetXboxName@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D95F
// Name: __declspec(dllimport) load__DmRegisterNotificationProcessor(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmRegisterNotificationProcessor(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmRegisterNotificationProcessor, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D969
// Name: _DmRegisterNotificationProcessor@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmRegisterNotificationProcessor(int a1, int a2, int a3)
{
  return __imp__DmRegisterNotificationProcessor@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D96F
// Name: __declspec(dllimport) load__DmOpenNotificationSession(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmOpenNotificationSession(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmOpenNotificationSession, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D979
// Name: _DmOpenNotificationSession@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmOpenNotificationSession(int a1, int a2)
{
  return __imp__DmOpenNotificationSession@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D97F
// Name: __declspec(dllimport) load__DmGo()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGo(int a1, int a2)
{
  return _tailMerge_xbdm_DLL(a1: &DmGo, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D989
// Name: _DmGo@0_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGo()
{
  return __imp__DmGo@0();
}

//------------------------------------------------------------------------------
// Address: 0x0042D98F
// Name: __declspec(dllimport) load__DmCloseLoadedModules(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmCloseLoadedModules(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmCloseLoadedModules, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D999
// Name: _DmCloseLoadedModules@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmCloseLoadedModules(int a1)
{
  return __imp__DmCloseLoadedModules@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D99F
// Name: __declspec(dllimport) load__DmWalkLoadedModules(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmWalkLoadedModules(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmWalkLoadedModules, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9A9
// Name: _DmWalkLoadedModules@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmWalkLoadedModules(int a1, int a2)
{
  return __imp__DmWalkLoadedModules@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9AF
// Name: __declspec(dllimport) load__DmReceiveStatusResponse(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmReceiveStatusResponse(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmReceiveStatusResponse, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9B9
// Name: _DmReceiveStatusResponse@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmReceiveStatusResponse(int a1, int a2, int a3)
{
  return __imp__DmReceiveStatusResponse@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9BF
// Name: __declspec(dllimport) load__DmSendBinary(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmSendBinary(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmSendBinary, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9C9
// Name: _DmSendBinary@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSendBinary(int a1, int a2, int a3)
{
  return __imp__DmSendBinary@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9CF
// Name: __declspec(dllimport) load__DmSendCommand(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmSendCommand(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmSendCommand, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9D9
// Name: _DmSendCommand@16_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmSendCommand(int a1, int a2, int a3, int a4)
{
  return __imp__DmSendCommand@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9DF
// Name: __declspec(dllimport) load__DmUnloadSymbolsForModule(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmUnloadSymbolsForModule(int a1, int a2, int a3)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmUnloadSymbolsForModule, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9E9
// Name: _DmUnloadSymbolsForModule@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmUnloadSymbolsForModule(int a1)
{
  return __imp__DmUnloadSymbolsForModule@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9EF
// Name: __declspec(dllimport) load__DmLoadSymbolsForModuleEx(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmLoadSymbolsForModuleEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmLoadSymbolsForModuleEx, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9F9
// Name: _DmLoadSymbolsForModuleEx@20_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmLoadSymbolsForModuleEx(int a1, int a2, int a3, int a4, int a5)
{
  return __imp__DmLoadSymbolsForModuleEx@20(a1, a2, a3, a4, a5);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9FF
// Name: __declspec(dllimport) load__DmFindPdbSignature(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmFindPdbSignature(int a1, int a2, int a3, int a4)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmFindPdbSignature, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA09
// Name: _DmFindPdbSignature@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmFindPdbSignature(int a1, int a2)
{
  return __imp__DmFindPdbSignature@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA0F
// Name: __declspec(dllimport) load__DmGetSourceLineFromAddress(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetSourceLineFromAddress(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetSourceLineFromAddress, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA19
// Name: _DmGetSourceLineFromAddress@16_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetSourceLineFromAddress(int a1, int a2, int a3, int a4)
{
  return __imp__DmGetSourceLineFromAddress@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA1F
// Name: __declspec(dllimport) load__DmGetSymbolFromAddress(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmGetSymbolFromAddress(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmGetSymbolFromAddress, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA29
// Name: _DmGetSymbolFromAddress@16_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmGetSymbolFromAddress(int a1, int a2, int a3, int a4)
{
  return __imp__DmGetSymbolFromAddress@16(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA2F
// Name: __declspec(dllimport) load__DmTranslateErrorA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmTranslateErrorA(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmTranslateErrorA, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA39
// Name: _DmTranslateErrorA@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmTranslateErrorA(int a1, int a2, int a3)
{
  return __imp__DmTranslateErrorA@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA3F
// Name: __declspec(dllimport) load__DmReceiveSocketLine(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall load__DmReceiveSocketLine(int a1, int a2, int a3, int a4, int a5)
{
  return _tailMerge_xbdm_DLL(a1: (int (__stdcall **)())&DmReceiveSocketLine, a2, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA49
// Name: _DmReceiveSocketLine@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall DmReceiveSocketLine(int a1, int a2, int a3)
{
  return __imp__DmReceiveSocketLine@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042DA4F
// Name: __delayLoadHelper2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__stdcall *__stdcall __delayLoadHelper2(const ImgDelayDescr *pidd, DelayLoadInfo *ppfnIATEntry))()
{
  const ImgDelayDescr *v2; // esi
  unsigned int rvaIAT; // ebx
  const _IMAGE_THUNK_DATA32 *v4; // edi
  const char *v5; // ecx
  char *v6; // ebx
  char *v7; // edx
  bool v8; // zf
  HMODULE LibraryA; // edi
  int v11; // edx
  unsigned int v12; // eax
  int (__stdcall *ProcAddress)(); // ebx
  UnloadInfo *v14; // eax
  int v15; // eax
  DelayLoadInfo dli; // [esp+Ch] [ebp-44h] BYREF
  InternalImgDelayDescr idd; // [esp+30h] [ebp-20h]

  v2 = pidd;
  rvaIAT = pidd->rvaIAT;
  v4 = (const _IMAGE_THUNK_DATA32 *)((char *)&_setlc_active + pidd->rvaBoundIAT);
  v5 = (char *)&_setlc_active + pidd->rvaDLLName;
  idd.phmod = (HINSTANCE__ **)((char *)&_setlc_active + pidd->rvaHmod);
  v6 = (char *)&_setlc_active + rvaIAT;
  v7 = (char *)&_setlc_active + pidd->rvaINT;
  idd.dwTimeStamp = pidd->dwTimeStamp;
  dli.szDll = v5;
  idd.pBoundIAT = v4;
  dli.ppfn = (int (__stdcall **)())ppfnIATEntry;
  v8 = (pidd->grAttrs & 1) == 0;
  dli.cb = 36;
  dli.pidd = pidd;
  memset(&dli.dlp, 0, 20);
  if ( v8 )
  {
    ppfnIATEntry = &dli;
    RaiseException(
      dwExceptionCode: 0xC06D0057,
      dwExceptionFlags: 0,
      nNumberOfArguments: 1u,
      lpArguments: (const ULONG_PTR *)&ppfnIATEntry);
    return nullptr;
  }
  LibraryA = *idd.phmod;
  v11 = *(_DWORD *)&v7[((char *)ppfnIATEntry - v6) & 0xFFFFFFFC];
  pidd = (const ImgDelayDescr *)(((char *)ppfnIATEntry - v6) & 0xFFFFFFFC);
  dli.dlp.fImportByName = v11 >= 0;
  v12 = (unsigned int)&_setlc_active.unused + v11 + 2;
  if ( v11 < 0 )
    v12 = (unsigned __int16)v11;
  dli.dlp.dwOrdinal = v12;
  ProcAddress = nullptr;
  if ( __pfnDliNotifyHook2 == nullptr || (ProcAddress = __pfnDliNotifyHook2(a1: 0, a2: &dli)) == nullptr )
  {
    if ( LibraryA == nullptr )
    {
      if ( __pfnDliNotifyHook2 == nullptr || (LibraryA = (HMODULE)__pfnDliNotifyHook2(a1: 1u, a2: &dli)) == nullptr )
      {
        LibraryA = LoadLibraryA(lpLibFileName: dli.szDll);
        if ( LibraryA == nullptr )
        {
          dli.dwLastError = GetLastError();
          if ( __pfnDliFailureHook2 == nullptr
            || (LibraryA = (HMODULE)__pfnDliFailureHook2(a1: 3u, a2: &dli)) == nullptr )
          {
            ppfnIATEntry = &dli;
            RaiseException(
              dwExceptionCode: 0xC06D007E,
              dwExceptionFlags: 0,
              nNumberOfArguments: 1u,
              lpArguments: (const ULONG_PTR *)&ppfnIATEntry);
            return dli.pfnCur;
          }
        }
      }
      if ( (HMODULE)InterlockedExchange(Target: (volatile LONG *)idd.phmod, Value: (LONG)LibraryA) == LibraryA )
      {
        FreeLibrary(hLibModule: LibraryA);
      }
      else if ( v2->rvaUnloadIAT != 0 )
      {
        v14 = (UnloadInfo *)LocalAlloc(uFlags: 0x40u, uBytes: 8u);
        if ( v14 != nullptr )
        {
          v14->pidd = v2;
          v14->puiNext = __puiHead;
          __puiHead = v14;
        }
      }
    }
    dli.hmodCur = LibraryA;
    if ( __pfnDliNotifyHook2 != nullptr )
      ProcAddress = __pfnDliNotifyHook2(a1: 2u, a2: &dli);
    if ( ProcAddress == nullptr
      && (v2->rvaBoundIAT == 0
       || v2->dwTimeStamp == 0
       || *(_DWORD *)((char *)LibraryA + (v15 = *((_DWORD *)LibraryA + 15))) != 17744
       || *(_DWORD *)((char *)LibraryA + v15 + 8) != idd.dwTimeStamp
       || LibraryA != *(HMODULE *)((char *)LibraryA + v15 + 52)
       || (ProcAddress = *(int (__stdcall **)())((char *)&pidd->grAttrs + (unsigned int)idd.pBoundIAT)) == nullptr) )
    {
      ProcAddress = GetProcAddress(hModule: LibraryA, lpProcName: dli.dlp.szProcName);
      if ( ProcAddress == nullptr )
      {
        dli.dwLastError = GetLastError();
        if ( __pfnDliFailureHook2 == nullptr || (ProcAddress = __pfnDliFailureHook2(a1: 4u, a2: &dli)) == nullptr )
        {
          pidd = (const ImgDelayDescr *)&dli;
          RaiseException(
            dwExceptionCode: 0xC06D007F,
            dwExceptionFlags: 0,
            nNumberOfArguments: 1u,
            lpArguments: (const ULONG_PTR *)&pidd);
          ProcAddress = dli.pfnCur;
        }
      }
    }
    ppfnIATEntry->cb = (unsigned int)ProcAddress;
  }
  if ( __pfnDliNotifyHook2 != nullptr )
  {
    dli.dwLastError = 0;
    dli.hmodCur = LibraryA;
    dli.pfnCur = ProcAddress;
    __pfnDliNotifyHook2(a1: 5u, a2: &dli);
  }
  return ProcAddress;
}
