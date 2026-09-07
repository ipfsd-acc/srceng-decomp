// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/vxconsole.cpp
// Functions: 28
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00415C60
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
// Address: 0x00415CE0
// Name: void LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  ConfigDlg_LoadConfig();
  g_captureDebugSpew = g_captureDebugSpew_StartupState;
  Sys_GetRegistryString(keyName: "mainWindowRect", value: buff, defValue: &str, valueLen: 0x100u);
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
}

//------------------------------------------------------------------------------
// Address: 0x00415D80
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
// Address: 0x00415E10
// Name: void SetConnectionIcon(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetConnectionIcon(int icon)
{
  if ( g_currentIcon != icon )
  {
    g_currentIcon = icon;
    SetClassLongA(hWnd: g_hDlgMain, nIndex: -14, dwNewLong: *(&g_hIcons + icon));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415E40
// Name: void SetMainWindowTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMainWindowTitle()
{
  char titleBuff[128]; // [esp+0h] [ebp-A0h] BYREF
  char configBuff[32]; // [esp+80h] [ebp-20h] BYREF

  if ( g_hDlgMain != nullptr )
  {
    if ( g_ps3TargetName[0] != 0 )
    {
      sprintf(string: titleBuff, format: "%s: %s", aVxconsol, g_ps3TargetName);
      if ( g_configID != 0 )
      {
        sprintf(string: configBuff, format: " (%d)", g_configID);
        V_strncat(pDest: titleBuff, pSrc: configBuff, destBufferSize: 0x80u, max_chars_to_copy: -1);
      }
    }
    else
    {
      strcpy(titleBuff, "VXConsole_PS3");
    }
    SetWindowTextA(hWnd: g_hDlgMain, lpString: titleBuff);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415F00
// Name: long DmAPI_SendCommand(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DmAPI_SendCommand(char *strCommand, bool wait)
{
  HANDLE v3; // edi
  char *v4; // esi
  int v5; // esi

  if ( WaitForSingleObject(hHandle: g_hCommandReadyEvent, dwMilliseconds: -wait) != 0 )
    return -22;
  v3 = g_hCommandReadyEvent;
  ResetEvent(hEvent: g_hCommandReadyEvent);
  v4 = strCommand;
  if ( *strCommand == 42 )
    v4 = strCommand + 1;
  else
    _V_stricmp(s1: strCommand, s2: "XCMD!");
  v5 = CPS3TargetConnection::SendDMProtocolData(
         this: &g_PS3CurrentTargetConn,
         pData: (unsigned __int8 *)v4,
         uLength: strlen(v4));
  SetEvent(hEvent: v3);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00415F80
// Name: void PrintToQueue(unsigned long,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void PrintToQueue(unsigned int rgb, const char *strFormat, ...)
{
  char buffer[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+210h] [ebp+10h] BYREF

  va_start(ap, strFormat);
  EnterCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
  if ( g_captureGameSpew != 0 && g_PrintQueue.numMessages != 4096 )
  {
    if ( _vsnprintf(string: buffer, count: 0x200u, format: strFormat, ap) == -1 )
      buffer[511] = 0;
    g_PrintQueue.pMessages[g_PrintQueue.numMessages] = Sys_CopyString(str: buffer);
    g_PrintQueue.aColors[g_PrintQueue.numMessages++] = rgb;
    if ( g_PrintQueue.numMessages == 1 )
      PostMessageA(hWnd: g_hDlgMain, Msg: 0x40Bu, wParam: 0, lParam: 0);
  }
  LeaveCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x00416040
// Name: GetPlaytestFileserverLogFile
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl GetPlaytestFileserverLogFile()
{
  char szLogPath[260]; // [esp+0h] [ebp-208h] BYREF
  char szLogName[260]; // [esp+104h] [ebp-104h] BYREF

  if ( g_FileserverPlaytestLogFileName[0] == 0 )
    return nullptr;
  V_snprintf(pDest: szLogName, maxLen: 260, pFormat: "vxconsole_%s.log", g_ps3TargetName);
  V_ComposeFileName(path: g_FileserverPlaytestLogFileName, filename: szLogName, dest: szLogPath, destSize: 260);
  return fopen(file: szLogPath, mode: "at+");
}

//------------------------------------------------------------------------------
// Address: 0x004160B0
// Name: GetPlaytestLocalLogFile
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl GetPlaytestLocalLogFile()
{
  char szLogPath[260]; // [esp+0h] [ebp-208h] BYREF
  char szLogName[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: szLogName, maxLen: 260, pFormat: "vxconsole_%s.log", g_ps3TargetName);
  V_ComposeFileName(path: g_localPath, filename: szLogName, dest: szLogPath, destSize: 260);
  return fopen(file: szLogPath, mode: "at+");
}

//------------------------------------------------------------------------------
// Address: 0x00416110
// Name: void InitiateLoggingPlaytestToFileserver(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitiateLoggingPlaytestToFileserver()
{
  tm *v0; // eax
  __int64 timeptr; // [esp+0h] [ebp-8h] BYREF

  _time64(&timeptr);
  v0 = _localtime64(ptime: &timeptr);
  if ( g_ps3TargetName[0] != 0 )
  {
    V_snprintf(
      pDest: g_FileserverPlaytestLogFileName,
      maxLen: 260,
      pFormat: "%s\\logs\\%s\\%2.2d_%2.2d_%2.2d__%2.2d_%2.2d_%2.2d\\",
      g_installPath,
      g_ps3TargetName,
      v0->tm_mon + 1,
      v0->tm_mday,
      v0->tm_year % 100,
      v0->tm_hour,
      v0->tm_min,
      v0->tm_sec);
    Sys_CreatePath(pInPath: g_FileserverPlaytestLogFileName);
  }
  else
  {
    g_FileserverPlaytestLogFileName[0] = 0;
  }
  if ( MakePerfmonLogFilePath(outPath: g_FileserverPerfmonLogFileName, outLen: 260) != 0 )
    Sys_CreatePath(pInPath: g_FileserverPerfmonLogFileName);
}

//------------------------------------------------------------------------------
// Address: 0x004161C0
// Name: int ConsoleWindowPrintf(unsigned long,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int ConsoleWindowPrintf(unsigned int rgb, const char *strFormat, ...)
{
  int v2; // edi
  _iobuf *PlaytestFileserverLogFile; // esi
  _iobuf *PlaytestLocalLogFile; // eax
  _iobuf *v5; // esi
  char strTemp[512]; // [esp+8h] [ebp-244h] BYREF
  _charformat v8; // [esp+208h] [ebp-44h] BYREF
  _charrange cr; // [esp+244h] [ebp-8h] BYREF
  va_list ap; // [esp+25Ch] [ebp+10h] BYREF

  va_start(ap, strFormat);
  cr.cpMin = -1;
  cr.cpMax = -2;
  v2 = _vsnprintf(string: strTemp, count: 0x200u, format: strFormat, ap);
  if ( g_DisplayTTY != 0 )
  {
    memset(dst: (unsigned __int8 *)&v8.dwMask, value: 0, count: 0x38u);
    v8.cbSize = 60;
    v8.dwMask = 0x40000000;
    v8.dwEffects = 0;
    v8.crTextColor = rgb;
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0x444u, wParam: 1u, lParam: (LPARAM)&v8);
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0x437u, wParam: 0, lParam: (LPARAM)&cr);
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)strTemp);
    SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1010, Msg: 0xB7u, wParam: 0, lParam: 0);
  }
  if ( g_bPlayTestMode != 0 )
  {
    PlaytestFileserverLogFile = GetPlaytestFileserverLogFile();
    if ( PlaytestFileserverLogFile != nullptr )
    {
      fprintf(str: PlaytestFileserverLogFile, format: strTemp);
      fclose(stream: PlaytestFileserverLogFile);
    }
    PlaytestLocalLogFile = GetPlaytestLocalLogFile();
    v5 = PlaytestLocalLogFile;
    if ( PlaytestLocalLogFile != nullptr )
    {
      fprintf(str: PlaytestLocalLogFile, format: strTemp);
      fclose(stream: v5);
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004162F0
// Name: int PerfmonPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int PerfmonPrintf(const char *strFormat, ...)
{
  int result; // eax
  int v2; // edi
  _iobuf *PerfmonFileserverLogFile; // esi
  char strTemp[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+20Ch] [ebp+Ch] BYREF

  va_start(ap, strFormat);
  result = 0;
  if ( g_bPlayTestMode != 0 )
  {
    v2 = _vsnprintf(string: strTemp, count: 0x200u, format: strFormat, ap);
    PerfmonFileserverLogFile = GetPerfmonFileserverLogFile();
    if ( PerfmonFileserverLogFile != nullptr )
    {
      fprintf(str: PerfmonFileserverLogFile, format: strTemp);
      fclose(stream: PerfmonFileserverLogFile);
    }
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416350
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
// Address: 0x004165E0
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
// Address: 0x00416640
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
// Address: 0x004167D0
// Name: int _SortCommands(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _SortCommands(const char **a, const char **b)
{
  return _V_stricmp(s1: *a, s2: *b);
}

//------------------------------------------------------------------------------
// Address: 0x004167F0
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
// Address: 0x00416A40
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
// Address: 0x00416AD0
// Name: void CreateCommandHint(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateCommandHint()
{
  g_hwndCommandHint = CreateWindowExA(
                        dwExStyle: 4u,
                        lpClassName: "LISTBOX",
                        lpWindowName: &str,
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
  SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 666, Msg: 0x30u, wParam: g_hFixedFont, lParam: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00416B30
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
  g_backgroundColor = 11842740;
  g_hBackgroundBrush = CreateSolidBrush(color: 0xB4B4B4u);
  g_hIcons = (LONG)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xC8);
  dword_490B48 = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xC9);
  dword_490B4C = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xCA);
  dword_490B50 = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xCC);
  dword_490B54 = (int)LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0xCB);
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
  lf.lfHeight = v4;
  lf.lfWeight = 400;
  strcpy(lf.lfFaceName, "Courier");
  g_hFixedFont = (WPARAM)CreateFontIndirectA(lplf: &lf);
  if ( g_hFixedFont == 0 )
    return 0;
  memset(dst: (unsigned __int8 *)&lf, value: 0, count: sizeof(lf));
  strcpy(lf.lfFaceName, "Tahoma");
  lf.lfHeight = -11;
  lf.lfWeight = 400;
  g_hProportionalFont = CreateFontIndirectA(lplf: &lf);
  if ( g_hProportionalFont == nullptr )
    return 0;
  v5 = GetWindowDC(hWnd: nullptr);
  hFontOld = (HFONT__ *)SelectObject(hdc: v5, h: (HGDIOBJ)g_hFixedFont);
  GetTextMetricsA(hdc: v5, lptm: &g_fixedFontMetrics);
  SelectObject(hdc: v5, h: hFontOld);
  ReleaseDC(hWnd: nullptr, hDC: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416D10
// Name: void Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shutdown()
{
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
  if ( g_hFixedFont != 0 )
  {
    DeleteObject(ho: (HGDIOBJ)g_hFixedFont);
    g_hFixedFont = 0;
  }
  if ( g_hProportionalFont != nullptr )
  {
    DeleteObject(ho: g_hProportionalFont);
    g_hProportionalFont = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416DA0
// Name: void DmAPI_DisplayError(char const __near *,long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DmAPI_DisplayError(const char *message, HRESULT hr)
{
  const char *pszError; // [esp+4h] [ebp-4h] BYREF

  ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "%s\n", message);
  if ( SNPS3TranslateError(a1: hr, a2: (int)&pszError) < 0 )
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Reason: 0x%08lx\n", hr);
  else
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Reason: '%s'\n", pszError);
}

//------------------------------------------------------------------------------
// Address: 0x00416E00
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
// Address: 0x00416E70
// Name: bool ProcessCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ProcessCommand(const char *strCmdIn)
{
  int v2; // esi
  localCommand_t *v3; // edi
  int v4; // esi
  bool v5; // zf
  char *v6; // esi
  int v7; // esi
  int v8; // esi
  void (__cdecl *v9)(int, char **); // edx
  int v10; // edi
  int v11; // eax
  HANDLE v12; // edi
  char strCmd[512]; // [esp+0h] [ebp-664h] BYREF
  char strCmdBak[512]; // [esp+200h] [ebp-464h] BYREF
  char strRemoteCmd[524]; // [esp+400h] [ebp-264h] BYREF
  char *argv[20]; // [esp+60Ch] [ebp-58h] BYREF
  int isXCommand; // [esp+65Ch] [ebp-8h]
  int argc; // [esp+660h] [ebp-4h] BYREF

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
    if ( v2 >= 18 )
    {
      if ( g_connectionState != kCONNECTEDAPP )
        goto LABEL_15;
      v4 = 0;
      v5 = g_numRemoteCommands == 0;
      if ( (int)g_numRemoteCommands > 0 )
      {
        while ( lstrcmpiA(lpString1: g_remoteCommands[v4]->strCommand, lpString2: argv[0]) != 0 )
        {
          if ( ++v4 >= (int)g_numRemoteCommands )
          {
            if ( g_connectionState != kCONNECTEDAPP )
              goto LABEL_15;
            v5 = g_numRemoteCommands == 0;
            goto LABEL_14;
          }
        }
        if ( g_connectionState == kCONNECTEDAPP )
          goto LABEL_16;
LABEL_28:
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "'%s' is not available until connected to Application.\n", argv[0]);
        return 1;
      }
LABEL_14:
      if ( !v5 )
LABEL_15:
        ConsoleWindowPrintf(
          rgb: 0xFFu,
          strFormat: "'%s' is not a recognized command. I'll try just sending it to the game and hope for the best.\n",
          argv[0]);
LABEL_16:
      lstrcpyA(lpString1: strRemoteCmd, lpString2: "XCMD!");
      lstrcatA(lpString1: strRemoteCmd, lpString2: strCmdBak);
      goto LABEL_17;
    }
  }
  v8 = 4 * v2;
  v9 = *(void (__cdecl **)(int, char **))((char *)&off_444168 + v8 * 4);
  v10 = 1;
  if ( v9 != nullptr )
    v10 = isXCommand;
  v11 = dword_444164[v8];
  if ( (v11 & 1) != 0 && g_connectionState != kCONNECTEDTARGET && g_connectionState != kCONNECTEDAPP )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "'%s' is not available until connected to XBox.\n", argv[0]);
    return 1;
  }
  if ( (v11 & 2) != 0 && g_connectionState != kCONNECTEDAPP )
    goto LABEL_28;
  if ( v10 == 0 )
  {
    v9(a1: argc, a2: argv);
    return 1;
  }
  lstrcpyA(lpString1: strRemoteCmd, lpString2: strCmdBak);
LABEL_17:
  v6 = strRemoteCmd;
  if ( WaitForSingleObject(hHandle: g_hCommandReadyEvent, dwMilliseconds: 0xFFFFFFFF) != 0 )
  {
    v7 = -22;
  }
  else
  {
    v12 = g_hCommandReadyEvent;
    ResetEvent(hEvent: g_hCommandReadyEvent);
    if ( strRemoteCmd[0] == 42 )
      v6 = &strRemoteCmd[1];
    else
      _V_stricmp(s1: strRemoteCmd, s2: "XCMD!");
    v7 = CPS3TargetConnection::SendDMProtocolData(
           this: &g_PS3CurrentTargetConn,
           pData: (unsigned __int8 *)v6,
           uLength: strlen(v6));
    SetEvent(hEvent: v12);
    if ( v7 >= 0 )
      return 1;
  }
  ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "%s\n", "DmSendCommand");
  if ( SNPS3TranslateError(a1: v7, a2: (int)&argc) < 0 )
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Reason: 0x%08lx\n", v7);
  else
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Reason: '%s'\n", (const char *)argc);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417190
// Name: void OnPlaytestModeChange(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnPlaytestModeChange(bool bTurnedOn)
{
  if ( bTurnedOn && g_connectionState == kCONNECTEDAPP )
    InitiateLoggingPlaytestToFileserver();
  else
    ProcessCommand(strCmdIn: "exec playtest_off.ps3.cfg");
}

//------------------------------------------------------------------------------
// Address: 0x004171C0
// Name: long Main_DlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
HGDIOBJ __stdcall Main_DlgProc(HWND__ *hDlg, UINT message, WPARAM wParam, unsigned int lParam)
{
  HGDIOBJ result; // eax
  UINT v5; // eax
  char strCmd[264]; // [esp+Ch] [ebp-108h] BYREF

  if ( message > 0x111 )
  {
    if ( message > 0x134 )
    {
      if ( message == 1034 )
      {
        HandleCleanupOfGlobalFileUploadThread();
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      }
      if ( message == 1035 )
      {
        ProcessPrintQueue();
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      }
      if ( message != 0x8000 )
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
      GetWindowTextA(hWnd: g_hwndCommandCombo, lpString: strCmd, nMaxCount: 260);
      ProcessCommand(strCmdIn: strCmd);
      SetWindowTextA(hWnd: g_hwndCommandCombo, lpString: &str);
      goto LABEL_73;
    }
    if ( message >= 0x133 )
    {
      SetBkColor(hdc: (HDC)wParam, color: g_backgroundColor);
      return g_hBackgroundBrush;
    }
    if ( message == 274 )
    {
      if ( (_WORD)wParam == 0xF060 )
      {
$LN1_1:
        PostMessageA(hWnd: hDlg, Msg: 0x10u, wParam: 0, lParam: 0);
        return nullptr;
      }
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    }
    if ( message != 278 )
      return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
    CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0x9C49u, uCheck: g_autoConnect != 0 ? 8 : 0);
    CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC580u, uCheck: g_captureGameSpew != 0 ? 8 : 0);
    CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC581u, uCheck: g_captureDebugSpew != 0 ? 8 : 0);
    CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0x9C48u, uCheck: g_debugCommands != 0 ? 8 : 0);
    CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC59Au, uCheck: g_bPlayTestMode != 0 ? 8 : 0);
    v5 = !gConnectedToTarget() || IsADirectoryUploadCurrentlyInProgress();
    EnableMenuItem(hMenu: (HMENU)wParam, uIDEnableItem: 0xC567u, uEnable: v5);
    CheckMenuItem(hMenu: (HMENU)wParam, uIDCheckItem: 0xC59Du, uCheck: g_DisplayTTY != 0 ? 8 : 0);
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
        case 0xC584u:
          ExcludePathsDlg_Open();
          result = nullptr;
          break;
        case 0xC58Bu:
          MemProfile_Open();
          result = nullptr;
          break;
        case 0xC59Au:
          g_bPlayTestMode ^= 1u;
          Sys_SetRegistryInteger(keyName: "playtestMode", value: g_bPlayTestMode);
          OnPlaytestModeChange(bTurnedOn: g_bPlayTestMode != 0);
          result = nullptr;
          break;
        case 0xC59Cu:
          lc_cls();
          result = nullptr;
          break;
        case 0xC59Du:
          g_DisplayTTY ^= 1u;
          result = nullptr;
          break;
        case 0xC59Fu:
          CrashDumps_Publish();
          result = nullptr;
          break;
        default:
          return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
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
        if ( (unsigned __int16)wParam != 1000 )
          return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
        if ( HIWORD(wParam) == 3 )
          goto LABEL_17;
        if ( HIWORD(wParam) != 4 )
        {
          if ( HIWORD(wParam) == 5 )
LABEL_17:
            EnableCommandHint(enable: true);
          return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
        }
LABEL_73:
        EnableCommandHint(enable: false);
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
          if ( (unsigned int)(unsigned __int16)wParam - 50002 <= 0xB )
          {
            Bindings_MenuSelection(wID: (unsigned __int16)wParam);
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
        return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
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
            if ( gConnectedToTarget() || g_autoConnect != 0 )
            {
              lc_disconnect();
              result = nullptr;
            }
            else
            {
              lc_connect(argc: 0, argv: nullptr);
              result = nullptr;
            }
            break;
          case 0x9C51u:
            goto $LN1_1;
          case 0x9C52u:
            ConfigDlg_Open();
            result = nullptr;
            break;
          case 0x9CB5u:
            SyncFilesDlg_Open();
            result = nullptr;
            break;
          case 0x9CC2u:
            ShowTextures_Open();
            result = nullptr;
            break;
          default:
            return (HGDIOBJ)DefDlgProcA(hDlg, Msg: message, wParam, lParam);
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417810
// Name: bool Startup(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall Startup@<al>(int a1@<ebp>)
{
  HWND DialogParamA; // eax
  HMENU Menu; // eax
  HWND Window; // eax
  LONG WindowLongA; // eax
  int v6; // eax
  char v7; // [esp-Ch] [ebp-1BCh] BYREF
  _BYTE v8[315]; // [esp-Bh] [ebp-1BBh] OVERLAPPED BYREF
  _charformat v9; // [esp+134h] [ebp-7Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+170h] [ebp-40h]
  char *v11; // [esp+1A0h] [ebp-10h] BYREF
  _DWORD v12[2]; // [esp+1A4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+1B0h] [ebp+0h]

  v12[0] = a1;
  v12[1] = retaddr;
  LoadConfig();
  if ( CreateResources() == 0 )
    return 0;
  InitializeCriticalSection(lpCriticalSection: &g_PrintQueue.CriticalSection);
  g_PrintQueue.bInit = true;
  g_hCommandReadyEvent = CreateEventA(
                           lpEventAttributes: nullptr,
                           bManualReset: true,
                           bInitialState: true,
                           lpName: nullptr);
  *(_DWORD *)&v9.szFaceName[22] = 0;
  *(_DWORD *)&v9.szFaceName[26] = Main_DlgProc;
  *(_DWORD *)&v9.szFaceName[30] = 0;
  wndclass.style = 34;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = dword_490B48;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)100;
  wndclass.hCursor = (HICON__ *)aVxconsol;
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)&v9.szFaceName[22]) == 0 )
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
  if ( CpuProfile_Init(a1: (const char *)v12) == 0
    || TexProfile_Init(a1: (const char *)v12) == 0
    || Bindings_Init(a1: (const char *)v12) == 0
    || ExcludePathsDlg_Init() == 0
    || ExcludePathsDlg_Init() == 0
    || MemProfile_Init(a1: (const char *)v12) == 0
    || ShowMaterials_Init(a1: (const char *)v12) == 0
    || ShowTextures_Init(a1: (const char *)v12) == 0
    || ShowSounds_Init(a1: (const char *)v12) == 0
    || ShowModels_Init(a1: (const char *)v12) == 0
    || ShowMemDump_Init(a1: (const char *)v12) == 0
    || TimeStampLog_Init(a1: (const char *)v12) == 0
    || ExcludePathsDlg_Init() == 0 )
  {
    return 0;
  }
  g_hwndOutputWindow = GetDlgItem(hDlg: g_hDlgMain, nIDDlgItem: 1010);
  g_hwndCommandCombo = GetDlgItem(hDlg: g_hDlgMain, nIDDlgItem: 1000);
  Sys_GetRegistryInteger(keyName: "playtestMode", defValue: 0, value: &g_bPlayTestMode);
  memset(dst: &v8[259], value: 0, count: 0x30u);
  *(_DWORD *)&v8[263] = 1;
  *(_DWORD *)&v8[271] = g_bPlayTestMode != 0 ? 8 : 0;
  Menu = GetMenu(hWnd: g_hDlgMain);
  SetMenuItemInfoA(hmenu: Menu, item: 0xC59Au, fByPositon: false, lpmii: (LPCMENUITEMINFOA)&v8[259]);
  CreateCommandHint();
  Window = GetWindow(hWnd: g_hwndCommandCombo, uCmd: 5u);
  g_hwndCommandSubclassed = (WNDPROC)SetWindowLongA(
                                       hWnd: Window,
                                       nIndex: -4,
                                       dwNewLong: (LONG)CommandWindow_SubclassedProc);
  *(_DWORD *)&v8[307] = 60;
  SendMessageA(hWnd: g_hwndOutputWindow, Msg: 0x43Au, wParam: 0, lParam: (LPARAM)&v8[307]);
  *(_DWORD *)&v8[311] &= ~0x40000000u;
  v9.cbSize = 200;
  lstrcpyA(lpString1: (LPSTR)&v9.yHeight + 2, lpString2: aCour);
  SendMessageA(hWnd: g_hwndOutputWindow, Msg: 0x444u, wParam: 4u, lParam: (LPARAM)&v8[307]);
  SendMessageA(hWnd: g_hwndOutputWindow, Msg: 0x443u, wParam: 0, lParam: g_backgroundColor);
  WindowLongA = GetWindowLongA(hWnd: g_hwndOutputWindow, nIndex: -16);
  SetWindowLongA(hWnd: g_hwndOutputWindow, nIndex: -16, dwNewLong: WindowLongA | 0x4000000);
  SendDlgItemMessageA(hDlg: g_hDlgMain, nIDDlgItem: 1000, Msg: 0x30u, wParam: g_hFixedFont, lParam: 1);
  SetMainWindowTitle();
  ConsoleWindowPrintf(
    rgb: 0,
    strFormat: "VXConsole %s [%s Build: %s %s] [Protocol: %d]\n",
    "1.2",
    "Release",
    "Dec 28 2010",
    "17:02:39",
    4097);
  ConsoleWindowPrintf(rgb: 0, strFormat: "type '*help' for list of commands...\n\n");
  g_currentIcon = -1;
  SetConnectionIcon(icon: 1);
  v7 = 0;
  memset(dst: v8, value: 0, count: 0xFFu);
  v11 = &v7;
  Sys_GetRegistryString(keyName: "ps3Name", value: &v7, defValue: &str, valueLen: 0x100u);
  if ( &v8[strlen(&v7)] != v8 )
    lc_connect(argc: 1, argv: &v11);
  if ( g_mainWindowRect.right != 0 && g_mainWindowRect.bottom != 0 )
    MoveWindow(
      hWnd: g_hDlgMain,
      X: g_mainWindowRect.left,
      Y: g_mainWindowRect.top,
      nWidth: g_mainWindowRect.right - g_mainWindowRect.left,
      nHeight: g_mainWindowRect.bottom - g_mainWindowRect.top,
      bRepaint: false);
  v6 = 1;
  if ( g_startMinimized != 0 )
    v6 = 2;
  ShowWindow(hWnd: g_hDlgMain, nCmdShow: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00417C40
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *pCmdLine, int nCmdShow)
{
  char *v4; // eax
  char *v5; // eax
  int i; // ecx
  char v7; // dl
  char v8; // dl
  char v9; // dl
  HWND WindowA; // eax
  HWND v11; // esi
  DWORD LastError; // eax
  char str[256]; // [esp+4h] [ebp-19Ch] BYREF
  char buff[128]; // [esp+104h] [ebp-9Ch] BYREF
  tagMSG msg; // [esp+184h] [ebp-1Ch] BYREF
  int savedregs; // [esp+1A0h] [ebp+0h] BYREF

  memset(&msg, 0, sizeof(msg));
  g_hInstance = hInstance;
  g_bSuppressBlink = V_stristr(pStr: pCmdLine, pSearch: "-noblink") != nullptr;
  buff[0] = 0;
  v4 = V_stristr(pStr: pCmdLine, pSearch: "-config ");
  if ( v4 != nullptr )
  {
    v5 = v4 + 8;
    for ( i = 0; i < 128; i += 4 )
    {
      buff[i] = *v5;
      if ( *v5 == 0 || *v5 == 32 )
        break;
      buff[i + 1] = v5[1];
      v7 = v5[1];
      if ( v7 == 0 || v7 == 32 )
      {
        ++i;
        break;
      }
      buff[i + 2] = v5[2];
      v8 = v5[2];
      if ( v8 == 0 || v8 == 32 )
      {
        i += 2;
        break;
      }
      buff[i + 3] = v5[3];
      v9 = v5[3];
      if ( v9 == 0 || v9 == 32 )
      {
        i += 3;
        break;
      }
      v5 += 4;
    }
    buff[i] = 0;
  }
  g_configID = atoi(nptr: buff);
  MakeConfigString(
    pString: "HKEY_CURRENT_USER\\Software\\VXConsole_PS3\\3\\",
    configID: g_configID,
    pOutBuff: buff,
    outBuffSize: 128);
  Sys_SetRegistryPrefix(pPrefix: buff);
  WindowA = FindWindowA(lpClassName: aVxconsol, lpWindowName: nullptr);
  v11 = WindowA;
  if ( WindowA != nullptr && GetWindowLongA(hWnd: WindowA, nIndex: 30) == g_configID )
  {
    if ( IsIconic(hWnd: v11) )
      ShowWindow(hWnd: v11, nCmdShow: 9);
    SetForegroundWindow(hWnd: v11);
    return 0;
  }
  if ( Startup(a1: (int)&savedregs) == 0 )
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
      CPS3TargetConnection::CallThisFunctionEveryTick(this: &g_PS3CurrentTargetConn);
    }
    while ( GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) );
    Shutdown();
    return msg.wParam;
  }
  Shutdown();
  return msg.wParam;
}
