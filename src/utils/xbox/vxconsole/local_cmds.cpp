// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/local_cmds.cpp
// Functions: 24
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00411CA0
// Name: int MatchLocalCommands(char __near *,char const __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MatchLocalCommands(char *cmdStr, const char **cmdList, int maxCmds)
{
  int v3; // edi
  localCommand_t *v4; // esi
  unsigned int matchLen; // [esp+Ch] [ebp-4h]

  v3 = 0;
  matchLen = strlen(cmdStr);
  v4 = g_localCommands;
  do
  {
    if ( V_strncasecmp(s1: cmdStr, s2: v4->strCommand, n: matchLen) == 0 )
    {
      cmdList[v3++] = v4->strCommand;
      if ( v3 >= maxCmds )
        break;
    }
    ++v4;
  }
  while ( (int)v4 < (int)&vec2_invalid_7 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00411D00
// Name: void DecodeRebootArgs(int,char __near * __near *,char __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeRebootArgs(int argc, char **argv, char *xexPath, char *xexName, char *xexArgs)
{
  int i; // ebx
  char filename[260]; // [esp+8h] [ebp-410h] BYREF
  char dir[260]; // [esp+10Ch] [ebp-30Ch] BYREF
  char extension[260]; // [esp+210h] [ebp-208h] BYREF
  char drive[260]; // [esp+314h] [ebp-104h] BYREF

  *xexPath = 0;
  *xexName = 0;
  *xexArgs = 0;
  if ( argc != 0 )
  {
    _splitpath(path: *argv, drive, dir, fname: filename, ext: extension);
    sprintf(string: xexPath, format: "%s%s", drive, dir);
    sprintf(string: xexName, format: "%s%s", filename, extension);
    for ( i = 1; i < argc; ++i )
    {
      qmemcpy(&xexArgs[strlen(xexArgs)], argv[i], &argv[i][strlen(argv[i]) + 1] - argv[i]);
      if ( i < argc - 1 )
        strcat(xexArgs, " ");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411DF0
// Name: int lc_memory(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lc_memory()
{
  return DmAPI_SendCommand(strCommand: "XCMD!__memory__", wait: true) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00411E10
// Name: int lc_threads(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_threads()
{
  int v1; // ebx
  signed int v2; // eax
  int i; // edi
  int v4; // esi
  unsigned int v5; // [esp+8h] [ebp-574h]
  unsigned int threadList[256]; // [esp+1Ch] [ebp-560h] BYREF
  char nameBuff[256]; // [esp+41Ch] [ebp-160h] BYREF
  char suspendBuff[32]; // [esp+51Ch] [ebp-60h] BYREF
  _DM_THREADINFOEX threadInfoEx; // [esp+53Ch] [ebp-40h] BYREF
  int v10; // [esp+574h] [ebp-8h]
  unsigned int numThreads; // [esp+578h] [ebp-4h] BYREF

  numThreads = 256;
  memset(dst: (unsigned __int8 *)threadList, value: 0, count: sizeof(threadList));
  if ( DmGetThreadList(a1: threadList, a2: &numThreads) < 0 )
    return 0;
  v1 = 0;
  while ( 2 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "\n--- CORE %d ---\n", v1);
    v2 = numThreads;
    for ( i = 0; i < 2; ++i )
    {
      v4 = 0;
      if ( v2 > 0 )
      {
        do
        {
          v5 = threadList[v4];
          threadInfoEx.Size = 56;
          if ( DmGetThreadInfoEx(a1: v5, a2: &threadInfoEx) < 0 )
            return 0;
          if ( threadInfoEx.CurrentProcessor == i + 2 * v1 )
          {
            nameBuff[0] = 0;
            DmGetMemory(a1: threadInfoEx.ThreadNameAddress, a2: threadInfoEx.ThreadNameLength, a3: nameBuff, a4: 0);
            if ( nameBuff[0] == 0 )
              strcpy(nameBuff, "???");
            suspendBuff[0] = 0;
            if ( threadInfoEx.SuspendCount != 0 )
              sprintf(string: suspendBuff, format: "(Suspend: %d)", threadInfoEx.SuspendCount);
            v10 = (char *)threadInfoEx.StackBase - (char *)threadInfoEx.StackLimit;
            ConsoleWindowPrintf(
              rgb: 0,
              strFormat: "   Id: 0x%8.8x Pri: %2d Proc: %1d Stack: %7.2f KB [%s] %s\n",
              threadList[v4],
              threadInfoEx.Priority,
              threadInfoEx.CurrentProcessor,
              (double)(unsigned int)((char *)threadInfoEx.StackBase - (char *)threadInfoEx.StackLimit) * 0.0009765625,
              nameBuff,
              suspendBuff);
          }
          v2 = numThreads;
        }
        while ( ++v4 < (int)numThreads );
      }
    }
    if ( ++v1 < 3 )
      continue;
    break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00411F90
// Name: int lc_help(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_help(int argc, char **argv)
{
  localCommand_t *v2; // esi
  signed int j; // esi
  unsigned int v5; // ebx
  localCommand_t *v6; // esi
  signed int i; // esi
  remoteCommand_t *v8; // eax

  if ( argc > 1 )
  {
    v5 = lstrlenA(lpString: argv[1]);
    v6 = g_localCommands;
    do
    {
      if ( _strnicmp(dst: v6->strCommand, src: argv[1], count: v5) == 0 && v6->strHelp != nullptr )
        ConsoleWindowPrintf(rgb: 0, strFormat: "%s %s\n", v6->strCommand, v6->strHelp);
      ++v6;
    }
    while ( (int)v6 < (int)&vec2_invalid_7 );
    if ( g_connectedToApp )
    {
      for ( i = 0; i < (int)g_numRemoteCommands; ++i )
      {
        if ( _strnicmp(dst: g_remoteCommands[i]->strCommand, src: argv[1], count: v5) == 0 )
        {
          v8 = g_remoteCommands[i];
          if ( v8->strHelp != nullptr )
            ConsoleWindowPrintf(rgb: 0, strFormat: "%s %s\n", v8->strCommand, v8->strHelp);
        }
      }
    }
    ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
    return 1;
  }
  ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
  ConsoleWindowPrintf(rgb: 0, strFormat: "Console Commands:\n");
  ConsoleWindowPrintf(rgb: 0, strFormat: "---------------\n");
  v2 = g_localCommands;
  do
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "%s\n", v2->strCommand);
    ++v2;
  }
  while ( (int)v2 < (int)&vec2_invalid_7 );
  if ( !g_connectedToApp )
    return 1;
  ConsoleWindowPrintf(rgb: 0, strFormat: "Remote Commands: ( %d )\n", g_numRemoteCommands);
  ConsoleWindowPrintf(rgb: 0, strFormat: "----------------\n");
  if ( g_numRemoteCommands != 0 )
  {
    for ( j = 0; j < (int)g_numRemoteCommands; ++j )
      ConsoleWindowPrintf(rgb: 0, strFormat: "%s\n", g_remoteCommands[j]->strCommand);
    ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
    return 1;
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "( None )\n");
    ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412150
// Name: int lc_cls(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_cls()
{
  SetWindowTextA(hWnd: g_hwndOutputWindow, lpString: &defValue);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412170
// Name: int lc_autoConnect(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_autoConnect()
{
  if ( g_autoConnect == 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Enabling Auto Connect.\n");
    ConsoleWindowPrintf(rgb: 0, strFormat: "Looking for Connection...\n");
    g_autoConnect = 1;
    if ( g_autoConnectTimer == 0 )
      g_autoConnectTimer = SetTimer(hWnd: g_hDlgMain, nIDEvent: 0x1000u, uElapse: 0x3E8u, lpTimerFunc: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004121D0
// Name: int lc_disconnect(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_disconnect()
{
  if ( g_autoConnect != 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Disabling Auto Connect.\n");
    if ( g_autoConnectTimer != 0 )
      KillTimer(hWnd: g_hDlgMain, uIDEvent: 0x1000u);
    g_autoConnectTimer = 0;
    g_autoConnect = 0;
  }
  if ( g_connectedToApp )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Closing Session.\n");
    DmAPI_SendCommand(strCommand: "XCMD!__disconnect__", wait: false);
    DmNotify(a1: g_pdmnSession, a2: 0, a3: 0);
    DmCloseNotificationSession(a1: g_pdmnSession);
    g_connectedToApp = false;
  }
  if ( g_connectedToXBox != 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Closing Connection.\n");
    DmCloseConnection(a1: g_pdmConnection);
    SetEvent(hEvent: g_hCommandReadyEvent);
    g_connectedToXBox = 0;
    g_xboxName[0] = 0;
    g_xboxAddress = 0;
  }
  SetConnectionIcon(icon: 1);
  g_connectCount = 0;
  Remote_DeleteCommands();
  StackTranslation_UnloadSymbols();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004122B0
// Name: int lc_crashdump(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_crashdump()
{
  DmCrashDump();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004122C0
// Name: int lc_quit(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_quit()
{
  PostMessageA(hWnd: g_hDlgMain, Msg: 0x10u, wParam: 0, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004122E0
// Name: void DoDisconnect(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoDisconnect(int bKeepConnection, int waitTime)
{
  int v2; // esi

  v2 = g_autoConnect;
  lc_disconnect();
  if ( v2 != 0 && bKeepConnection != 0 && waitTime > 0 )
  {
    lc_autoConnect();
    g_bAutoConnectWait = waitTime;
    g_bAutoConnectQuiet = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412330
// Name: int lc_bug(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_bug(int argc, char **argv)
{
  char *v2; // ecx
  char *args[2]; // [esp+0h] [ebp-8h] BYREF

  if ( argc == 1 )
  {
    BugDlg_Open();
    return 1;
  }
  else
  {
    v2 = *argv;
    args[0] = "*help";
    args[1] = v2;
    lc_help(argc: 1, argv: args);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412370
// Name: int lc_dir(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_dir(int argc, char **argv)
{
  int v2; // esi
  char *v3; // ecx
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  int v7; // eax
  int v8; // eax
  char *v9; // edi
  char v10; // al
  fileNode_s *v11; // ebx
  int v12; // esi
  unsigned int sizeHigh; // edi
  unsigned int sizeLow; // esi
  const char *v15; // esi
  bool v16; // cf
  char dateTimeString[256]; // [esp+4h] [ebp-634h] BYREF
  _TIME_ZONE_INFORMATION tzInfo; // [esp+104h] [ebp-534h] BYREF
  char targetName[260]; // [esp+1B0h] [ebp-488h] BYREF
  char filePath[260]; // [esp+2B4h] [ebp-384h] BYREF
  char newPath[260]; // [esp+3B8h] [ebp-280h] BYREF
  char fileName[260]; // [esp+4BCh] [ebp-17Ch] BYREF
  char sizeString[64]; // [esp+5C0h] [ebp-78h] BYREF
  _SYSTEMTIME systemTime; // [esp+600h] [ebp-38h] BYREF
  _SYSTEMTIME localTime; // [esp+610h] [ebp-28h] BYREF
  const char *dirString; // [esp+620h] [ebp-18h]
  int nPass; // [esp+624h] [ebp-14h]
  fileNode_s *pFileList; // [esp+628h] [ebp-10h] BYREF
  char *args[2]; // [esp+62Ch] [ebp-Ch] BYREF
  int numDirs; // [esp+634h] [ebp-4h]
  int numFiles; // [esp+640h] [ebp+8h]

  v2 = 0;
  pFileList = nullptr;
  if ( argc < 2 )
  {
    v3 = *argv;
    args[0] = "*dir";
    args[1] = v3;
    lc_help(argc: 2, argv: args);
    goto cleanUp_5;
  }
  v4 = argv[1];
  v5 = (char *)(newPath - v4);
  do
  {
    v6 = *v4;
    v4[(_DWORD)v5] = *v4;
    ++v4;
  }
  while ( v6 != 0 );
  Sys_StripFilename(inpath: newPath, outpath: filePath, outPathLen: 260);
  Sys_StripPath(inpath: newPath, outpath: fileName, outPathLen: 260);
  if ( fileName[0] != 0 )
  {
    strstr(str1: (unsigned __int8 *)fileName, str2: "*");
    if ( v7 == 0 )
    {
      strstr(str1: (unsigned __int8 *)fileName, str2: "?");
      if ( v8 == 0 )
      {
        v9 = &filePath[259];
        do
          v10 = *++v9;
        while ( v10 != 0 );
        strcpy(v9, "\\");
        Sys_StripFilename(inpath: newPath, outpath: filePath, outPathLen: 260);
        Sys_StripPath(inpath: newPath, outpath: fileName, outPathLen: 260);
      }
    }
  }
  LOBYTE(numDirs) = 0;
  if ( argc >= 3 )
    LOBYTE(numDirs) = _V_stricmp(s1: argv[2], s2: "/s") == 0;
  if ( !GetTargetFileList_r(targetPath: filePath, recurse: numDirs, attributes: 145, level: 0, &pFileList) )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bad Target Path '%s'\n", filePath);
    goto cleanUp_5;
  }
  ConsoleWindowPrintf(rgb: 0, strFormat: "\nDirectory of %s\n\n", argv[1]);
  GetTimeZoneInformation(lpTimeZoneInformation: &tzInfo);
  v11 = pFileList;
  v12 = 0;
  numFiles = 0;
  numDirs = 0;
  *(_QWORD *)args = 0;
  nPass = 0;
  do
  {
    if ( v11 == nullptr )
      goto LABEL_29;
    do
    {
      if ( v12 != 0 )
      {
        if ( (v11->attributes & 0x10) != 0 )
          goto LABEL_27;
      }
      else if ( (v11->attributes & 0x10) == 0 )
      {
        goto LABEL_27;
      }
      Sys_StripPath(inpath: v11->filename, outpath: targetName, outPathLen: 260);
      if ( fileName[0] == 0
        || Sys_IsWildcardMatch(wildcardString: fileName, stringToCheck: targetName, caseSensitive: false) )
      {
        FileTimeToSystemTime(lpFileTime: &v11->changeTime, lpSystemTime: &systemTime);
        SystemTimeToTzSpecificLocalTime(
          lpTimeZoneInformation: &tzInfo,
          lpUniversalTime: &systemTime,
          lpLocalTime: &localTime);
        SystemTimeToString(systemTime: &localTime, buffer: dateTimeString, bufferSize: 0x100u);
        sizeHigh = v11->sizeHigh;
        sizeLow = v11->sizeLow;
        if ( (v11->attributes & 0x10) != 0 )
        {
          ++numDirs;
          v15 = "<DIR>";
          sprintf(string: sizeString, format: "%s", "         ");
        }
        else
        {
          ++numFiles;
          dirString = "     ";
          Sys_NumberToCommaString(number: __SPAIR64__(sizeHigh, sizeLow), buffer: sizeString, bufferSize: 64);
          v16 = __CFADD__(sizeLow, args[0]);
          args[0] += sizeLow;
          v15 = dirString;
          args[1] += sizeHigh + v16;
        }
        ConsoleWindowPrintf(rgb: 0, strFormat: "%s  %s %12s %s\n", dateTimeString, v15, sizeString, targetName);
        v12 = nPass;
      }
LABEL_27:
      v11 = v11->nextPtr;
    }
    while ( v11 != nullptr );
    v11 = pFileList;
LABEL_29:
    nPass = ++v12;
  }
  while ( v12 < 2 );
  Sys_NumberToCommaString(number: *(__int64 *)args, buffer: sizeString, bufferSize: 64);
  ConsoleWindowPrintf(rgb: 0, strFormat: "%9s %d File(s) %s bytes\n", " ", numFiles, sizeString);
  ConsoleWindowPrintf(rgb: 0, strFormat: "%9s %d Dir(s)\n", " ", numDirs);
  v2 = 1;
cleanUp_5:
  if ( pFileList != nullptr )
    FreeTargetFileList(pFileList);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004126B0
// Name: int lc_CopyCache(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_CopyCache(int argc, char **argv)
{
  int v2; // esi
  char *v3; // ecx
  fileNode_s *i; // esi
  char szLocalPathHead[260]; // [esp+4h] [ebp-214h] BYREF
  char szLocalPath[260]; // [esp+108h] [ebp-110h] BYREF
  char *args[2]; // [esp+20Ch] [ebp-Ch] BYREF
  fileNode_s *pFileList; // [esp+214h] [ebp-4h] BYREF

  v2 = 0;
  pFileList = nullptr;
  if ( argc >= 2 )
  {
    V_strncpy(pDest: szLocalPathHead, pSrc: argv[1], maxLen: 260);
    if ( GetTargetFileList_r(targetPath: "cache:\\p2_001", recurse: true, attributes: 145, level: 0, &pFileList) )
    {
      ConsoleWindowPrintf(rgb: 0, strFormat: "\nDirectory of %s\n\n", "cache:\\p2_001");
      for ( i = pFileList; i != nullptr; i = i->nextPtr )
      {
        if ( (i->attributes & 0x10) == 0 )
        {
          V_ComposeFileName(
            path: szLocalPathHead,
            filename: (const char *)i->filename + 14,
            dest: szLocalPath,
            destSize: 260);
          ConsoleWindowPrintf(rgb: 0, strFormat: "Copying: %s -> %s\n", i->filename, szLocalPath);
          Sys_CreatePath(pInPath: szLocalPath);
          DmReceiveFileA(a1: szLocalPath, a2: i->filename);
        }
      }
      ConsoleWindowPrintf(rgb: 0, strFormat: "Finished.\n");
      v2 = 1;
    }
    else
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bad Target Path '%s'\n", "cache:\\p2_001");
    }
  }
  else
  {
    v3 = *argv;
    args[0] = "*copycache";
    args[1] = v3;
    lc_help(argc: 2, argv: args);
  }
  if ( pFileList != nullptr )
    FreeTargetFileList(pFileList);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004127E0
// Name: int lc_del(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_del(int argc, char **argv)
{
  int v3; // ecx
  int v4; // esi
  fileNode_s *v5; // esi
  int v6; // ebx
  int v7; // edi
  char targetName[260]; // [esp+4h] [ebp-31Ch] BYREF
  char filePath[260]; // [esp+108h] [ebp-218h] BYREF
  char fileName[260]; // [esp+20Ch] [ebp-114h] BYREF
  char *v12; // [esp+310h] [ebp-10h] BYREF
  BOOL recurse; // [esp+314h] [ebp-Ch]
  int errCode; // [esp+318h] [ebp-8h]
  fileNode_s *pFileList; // [esp+31Ch] [ebp-4h] BYREF
  char bQuiet_3; // [esp+32Bh] [ebp+Bh]

  pFileList = nullptr;
  errCode = 0;
  if ( argc >= 2 )
  {
    Sys_StripFilename(inpath: argv[1], outpath: filePath, outPathLen: 260);
    Sys_StripPath(inpath: argv[1], outpath: fileName, outPathLen: 260);
    bQuiet_3 = 0;
    LOBYTE(recurse) = 0;
    if ( argc >= 3 )
    {
      v4 = 2;
      do
      {
        if ( _V_stricmp(s1: argv[v4], s2: "/s") != 0 )
        {
          if ( _V_stricmp(s1: argv[v4], s2: "/q") == 0 )
            bQuiet_3 = 1;
        }
        else
        {
          LOBYTE(recurse) = 1;
        }
        ++v4;
      }
      while ( v4 < argc );
    }
    if ( GetTargetFileList_r(targetPath: filePath, recurse, attributes: 145, level: 0, &pFileList) )
    {
      v5 = pFileList;
      v6 = 0;
      v7 = 0;
      if ( pFileList == nullptr )
        goto LABEL_23;
      do
      {
        Sys_StripPath(inpath: v5->filename, outpath: targetName, outPathLen: 260);
        if ( fileName[0] == 0
          || Sys_IsWildcardMatch(wildcardString: fileName, stringToCheck: targetName, caseSensitive: false) )
        {
          if ( DmDeleteFile(a1: v5->filename, a2: (v5->attributes & 0x10) != 0) == 47841280 )
          {
            ConsoleWindowPrintf(rgb: 0, strFormat: "Deleted '%s'\n", v5->filename);
            ++v7;
          }
          else
          {
            if ( bQuiet_3 == 0 )
              ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Error Deleting '%s'\n", v5->filename);
            ++v6;
          }
        }
        v5 = v5->nextPtr;
      }
      while ( v5 != nullptr );
      if ( v7 != 0 || v6 != 0 )
        ConsoleWindowPrintf(rgb: 0, strFormat: "%d files deleted.\n", v7);
      else
LABEL_23:
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "No Files found for '%s'\n", argv[1]);
      errCode = 1;
    }
    else
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bad Target Path '%s'\n", filePath);
    }
  }
  else
  {
    v3 = (int)*argv;
    v12 = "*del";
    recurse = v3;
    lc_help(argc: 2, argv: &v12);
  }
  if ( pFileList != nullptr )
    FreeTargetFileList(pFileList);
  return errCode;
}

//------------------------------------------------------------------------------
// Address: 0x004129D0
// Name: int lc_screenshot(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_screenshot(int argc, char **argv)
{
  int v2; // eax
  char v3; // cl
  HRESULT v4; // eax
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  char *v9; // ecx
  char filepath[260]; // [esp+0h] [ebp-240h] BYREF
  char filename[260]; // [esp+104h] [ebp-13Ch] BYREF
  _stat64i32 dummyStat; // [esp+208h] [ebp-38h] BYREF
  char *args[2]; // [esp+238h] [ebp-8h] BYREF

  if ( argc > 1 )
  {
    if ( argc != 2 )
    {
      v9 = *argv;
      args[0] = "*help";
      args[1] = v9;
      lc_help(argc: 2, argv: args);
      return 0;
    }
    v6 = argv[1];
    v7 = (char *)(filename - v6);
    do
    {
      v8 = *v6;
      v6[(_DWORD)v7] = *v6;
      ++v6;
    }
    while ( v8 != 0 );
    Sys_AddExtension(extension: ".bmp", outpath: filename, outPathLen: 260, bForce: false);
  }
  else
  {
    v2 = 0;
    do
    {
      v3 = g_localPath[v2];
      filepath[v2++] = v3;
    }
    while ( v3 != 0 );
    Sys_AddFileSeperator(path: filepath, pathLen: 260);
    sprintf(string: filename, format: "%sscreenshot_%4.4d.bmp", filepath, shot);
    while ( _stat64i32(name: filename, buf: &dummyStat) != -1 )
      sprintf(string: filename, format: "%sscreenshot_%4.4d.bmp", filepath, ++shot);
  }
  v4 = DmScreenShot(a1: filename);
  if ( v4 >= 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Screenshot saved to %s\n", filename);
    ++shot;
    return 1;
  }
  else
  {
    DmAPI_DisplayError(message: "lc_screenshot(): DmScreenShot() failure", hr: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412B40
// Name: int lc_sections(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lc_sections(int argc, char **argv)
{
  char *v2; // ecx
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  HRESULT v7; // esi
  char moduleName[260]; // [esp+10h] [ebp-220h] BYREF
  _DMN_SECTIONLOAD sectLoad; // [esp+114h] [ebp-11Ch] BYREF
  char *args[2]; // [esp+224h] [ebp-Ch] BYREF
  _DM_WALK_MODSECT *pWalkModSect; // [esp+22Ch] [ebp-4h] BYREF

  pWalkModSect = nullptr;
  if ( argc != 2 )
  {
    v2 = *argv;
    args[0] = "*help";
    args[1] = v2;
    lc_help(argc: 2, argv: args);
    return false;
  }
  v4 = argv[1];
  v5 = (char *)(moduleName - v4);
  do
  {
    v6 = *v4;
    v4[(_DWORD)v5] = *v4;
    ++v4;
  }
  while ( v6 != 0 );
  ConsoleWindowPrintf(rgb: 0, strFormat: "Sections:\n");
  v7 = DmWalkModuleSections(a1: &pWalkModSect, a2: moduleName, a3: &sectLoad);
  if ( v7 == -2099642108 )
  {
LABEL_9:
    v7 = 47841280;
  }
  else
  {
    while ( v7 >= 0 )
    {
      ConsoleWindowPrintf(rgb: 0, strFormat: "[%s]:\n", sectLoad.Name);
      ConsoleWindowPrintf(rgb: 0, strFormat: "  Base:  0x%8.8x\n", sectLoad.BaseAddress);
      ConsoleWindowPrintf(
        rgb: 0,
        strFormat: "  Size:  %.2f MB ( %d bytes )\n",
        (double)sectLoad.Size * 0.00000095367432,
        sectLoad.Size);
      ConsoleWindowPrintf(rgb: 0, strFormat: "  Index: %d\n", sectLoad.Index);
      v7 = DmWalkModuleSections(a1: &pWalkModSect, a2: moduleName, a3: &sectLoad);
      if ( v7 == -2099642108 )
        goto LABEL_9;
    }
    DmAPI_DisplayError(message: "lc_sections(): DmWalkModuleSections() failure", hr: v7);
  }
  ConsoleWindowPrintf(rgb: 0, strFormat: "End.\n\n");
  if ( pWalkModSect != nullptr )
    DmCloseModuleSections(a1: pWalkModSect);
  return v7 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412CA0
// Name: int lc_run(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_run(int argc, char **argv)
{
  char *v2; // ecx
  int v3; // esi
  int v4; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  HRESULT v8; // eax
  HRESULT v9; // eax
  int i; // esi
  char xexName[260]; // [esp+8h] [ebp-51Ch] BYREF
  char xexDrive[260]; // [esp+10Ch] [ebp-418h] BYREF
  char xexArgs[260]; // [esp+210h] [ebp-314h] BYREF
  char szTempPath[260]; // [esp+314h] [ebp-210h] BYREF
  char xexPath[260]; // [esp+418h] [ebp-10Ch] BYREF
  char *args[2]; // [esp+51Ch] [ebp-8h] BYREF

  if ( argc != 0 )
  {
    v3 = 1;
    v4 = argc - 1;
    g_rebootArgc = argc - 1;
    if ( argc > 1 )
    {
      do
      {
        if ( v3 == 1 )
        {
          v5 = argv[1];
          v6 = (char *)(xexPath - v5);
          do
          {
            v7 = *v5;
            v5[(_DWORD)v6] = *v5;
            ++v5;
          }
          while ( v7 != 0 );
          Sys_AddExtension(extension: ".xex", outpath: xexPath, outPathLen: 260, bForce: false);
          _splitpath(path: xexPath, drive: xexDrive, dir: nullptr, fname: nullptr, ext: nullptr);
          if ( xexDrive[0] == 0 )
          {
            V_strncpy(pDest: szTempPath, pSrc: "e:\\", maxLen: 260);
            V_strncat(pDest: szTempPath, pSrc: xexPath, destBufferSize: 0x104u, max_chars_to_copy: -1);
            V_strncpy(pDest: xexPath, pSrc: szTempPath, maxLen: 260);
          }
          g_rebootArgv[0] = Sys_CopyString(str: xexPath);
        }
        else
        {
          *(&g_hRichEdit + v3) = (HMODULE)Sys_CopyString(str: argv[v3]);
        }
        ++v3;
      }
      while ( v3 < argc );
      v4 = g_rebootArgc;
    }
    if ( v4 != 0 )
    {
      DecodeRebootArgs(argc: v4, argv: g_rebootArgv, xexPath, xexName, xexArgs);
      v9 = DmSetTitle(a1: xexPath, a2: xexName, a3: xexArgs);
      if ( v9 < 0 )
      {
        DmAPI_DisplayError(message: "lc_Run(): DmSetTitle() failure", hr: v9);
        goto LABEL_20;
      }
      v8 = DmReboot(a1: 1);
    }
    else
    {
      v8 = DmReboot(a1: 4);
    }
    if ( v8 >= 0 )
    {
      g_reboot = 1;
      return 1;
    }
    DmAPI_DisplayError(message: "lc_Run(): DmReboot() failure", hr: v8);
  }
  else
  {
    v2 = *argv;
    args[0] = "*help";
    args[1] = v2;
    lc_help(argc: 2, argv: args);
  }
LABEL_20:
  for ( i = 0; i < g_rebootArgc; ++i )
    Sys_Free(ptr: g_rebootArgv[i]);
  g_rebootArgc = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412E80
// Name: int lc_reset(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_reset(int argc, char **argv)
{
  char *v2; // ecx
  HRESULT v4; // eax
  char *args[2]; // [esp+0h] [ebp-8h] BYREF

  if ( argc != 0 )
  {
    v4 = DmReboot(a1: 0);
    if ( v4 >= 0 )
    {
      g_reboot = 1;
      return 1;
    }
    else
    {
      DmAPI_DisplayError(message: "lc_Run(): DmReboot() failure", hr: v4);
      return 0;
    }
  }
  else
  {
    v2 = *argv;
    args[0] = "*help";
    args[1] = v2;
    lc_help(argc: 2, argv: args);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412EE0
// Name: int lc_ClearConfigs(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_ClearConfigs(int argc, char **argv)
{
  const char *v2; // ecx
  char szTempFilename[260]; // [esp+0h] [ebp-114h] BYREF
  char *args[2]; // [esp+104h] [ebp-10h] BYREF
  char *v6; // [esp+10Ch] [ebp-8h] BYREF
  const char *v7; // [esp+110h] [ebp-4h]

  if ( argc == 1 )
  {
    V_ComposeFileName(path: "HDD:\\Content", filename: "*.*", dest: szTempFilename, destSize: 260);
    args[0] = "*del";
    args[1] = szTempFilename;
    v6 = "/s";
    v7 = "/q";
    lc_del(argc: 4, argv: args);
    return 1;
  }
  else
  {
    v2 = *argv;
    v6 = "*help";
    v7 = v2;
    lc_help(argc: 1, argv: &v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413010
// Name: int lc_connect(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_connect(int argc, char **argv)
{
  int result; // eax
  HRESULT v3; // esi
  HRESULT v4; // eax
  HRESULT XboxName; // eax
  HRESULT v6; // eax
  char *v7; // eax
  CFmtStrN<256> *v8; // eax
  CFmtStrN<256> v9; // [esp+0h] [ebp-110h] BYREF
  unsigned int namelen; // [esp+10Ch] [ebp-4h] BYREF

  if ( g_connectedToXBox == 0 || (result = lc_disconnect()) != 0 )
  {
    if ( argc >= 1 && **argv != 0 )
    {
      v3 = DmSetXboxName(a1: *argv);
      if ( v3 < 0 )
      {
        sprintf(string: &v9.m_szBuf[7], format: "ConnectToXBox(): DmSetXboxName( %s ) failure", *argv);
        DmAPI_DisplayError(message: &v9.m_szBuf[7], hr: v3);
        return 0;
      }
    }
    v4 = DmOpenConnection(a1: &g_pdmConnection);
    if ( v4 < 0 )
    {
      DmAPI_DisplayError(message: "ConnectToXBox(): DmOpenConnection() failure", hr: v4);
      return 0;
    }
    namelen = 64;
    XboxName = DmGetXboxName(a1: g_xboxName, a2: &namelen);
    if ( XboxName < 0 )
    {
      DmAPI_DisplayError(message: "ConnectToXBox(): DmGetXboxName() failure", hr: XboxName);
LABEL_13:
      DmCloseConnection(a1: g_pdmConnection);
      return 0;
    }
    v6 = DmResolveXboxName(a1: &g_xboxAddress);
    if ( v6 < 0 )
    {
      DmAPI_DisplayError(message: "ConnectToXBox(): DmResolveXboxName() failure", hr: v6);
      goto LABEL_13;
    }
    g_connectedToXBox = 1;
    g_connectFailure = 0;
    if ( g_connectCount == 0 )
      ConsoleWindowPrintf(
        rgb: 0,
        strFormat: "Connected To: '%s'(%d.%d.%d.%d)\n",
        g_xboxName,
        HIBYTE(g_xboxAddress),
        BYTE2(g_xboxAddress),
        BYTE1(g_xboxAddress),
        (unsigned __int8)g_xboxAddress);
    ++g_connectCount;
    SetConnectionIcon(icon: 2);
    if ( g_connectCount == 1 )
    {
      v7 = V_stristr(pStr: g_pCommandLine, pSearch: "-run");
      if ( !bDoneAutoRun && v7 != nullptr )
      {
        v8 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "*run %s", v7 + 4);
        ProcessCommand(strCmdIn: v8->m_szBuf);
      }
      bDoneAutoRun = true;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004131B0
// Name: int lc_listen(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_listen()
{
  HRESULT v1; // eax
  HRESULT v2; // eax
  HRESULT v3; // eax
  HRESULT v4; // eax
  char *CurrentImageVersionString; // eax
  char *v6; // eax
  char szFormatted[260]; // [esp+0h] [ebp-208h] BYREF
  char cmdStr[256]; // [esp+104h] [ebp-104h] BYREF
  char *args[1]; // [esp+204h] [ebp-4h] BYREF

  if ( g_connectedToXBox == 0 && !g_connectedToApp )
    goto LABEL_6;
  if ( lc_disconnect() == 0 )
    return 0;
  if ( g_connectedToXBox == 0 )
  {
LABEL_6:
    args[0] = g_xboxTargetName;
    if ( lc_connect(argc: 1, argv: args) == 0 )
      return 0;
  }
  v1 = DmOpenNotificationSession(a1: 0, a2: &g_pdmnSession);
  if ( v1 < 0 )
  {
    DmAPI_DisplayError(message: "lc_session(): DmOpenNotificationSession() failure", hr: v1);
    StackTranslation_UnloadSymbols();
    return 0;
  }
  v2 = DmNotify(a1: g_pdmnSession, a2: 2, a3: Remote_NotifyDebugString);
  if ( v2 < 0 )
  {
    DmAPI_DisplayError(message: "lc_session(): DmNotify() failure", hr: v2);
LABEL_18:
    DmCloseNotificationSession(a1: g_pdmnSession);
    StackTranslation_UnloadSymbols();
    return 0;
  }
  v3 = DmRegisterNotificationProcessor(a1: g_pdmnSession, a2: "XCMD", a3: Remote_NotifyCommandFunc);
  if ( v3 < 0
    || (v3 = DmRegisterNotificationProcessor(a1: g_pdmnSession, a2: "XPRT", a3: Remote_NotifyPrintFunc)) < 0
    || (v3 = DmRegisterNotificationProcessor(a1: g_pdmnSession, a2: "XBIN", a3: Remote_NotifyBinaryFunc)) < 0 )
  {
    DmAPI_DisplayError(message: "lc_session(): DmRegisterNotificationProcessor() failure", hr: v3);
    goto LABEL_18;
  }
  v4 = DmRegisterNotificationProcessor(a1: g_pdmnSession, a2: "XPRF", a3: Remote_NotifyPerfFunc);
  if ( v4 < 0 )
  {
    DmAPI_DisplayError(message: "lc_session(): DmRegisterNotificationProcessor() failure", hr: v4);
LABEL_17:
    DmNotify(a1: g_pdmnSession, a2: 0, a3: 0);
    goto LABEL_18;
  }
  sprintf(string: cmdStr, format: "%s %d", "XCMD!__connect__", 300);
  if ( DmAPI_SendCommand(strCommand: cmdStr, wait: true) < 0 )
  {
    if ( g_autoConnect == 0 )
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Couldn't Find Application\n");
    goto LABEL_17;
  }
  g_connectedToApp = true;
  g_connectedTime = Sys_GetSystemTime();
  SetConnectionIcon(icon: 4);
  if ( g_playtestMode != 0 )
    InitiateLoggingPlaytestToFileserver();
  if ( g_clsOnConnect != 0 )
  {
    if ( !g_bForceDisconnect )
      SetWindowTextA(hWnd: g_hwndOutputWindow, lpString: &defValue);
    CpuProfile_Clear();
    TimeStampLog_Clear();
  }
  ConsoleWindowPrintf(rgb: 0xFF000000, strFormat: "\n******** CONNECTION ********\n");
  CurrentImageVersionString = GetCurrentImageVersionString();
  if ( CurrentImageVersionString != nullptr && *CurrentImageVersionString != 0 )
  {
    FormatImageVersionString(pVersion: CurrentImageVersionString, pOutString: szFormatted, outSize: 260);
    v6 = szFormatted;
  }
  else
  {
    v6 = "Unknown";
  }
  ConsoleWindowPrintf(rgb: 0xFF000000, strFormat: "Installed Image: %s\n", v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413410
// Name: void AutoConnectTimerProc(struct HWND__ __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AutoConnectTimerProc()
{
  int v0; // edi
  int i; // esi
  HRESULT v2; // eax
  HRESULT v3; // eax
  int v4; // eax
  int v5; // esi
  char xexPath[260]; // [esp+8h] [ebp-30Ch] BYREF
  char xexArgs[260]; // [esp+10Ch] [ebp-208h] BYREF
  char xexName[260]; // [esp+210h] [ebp-104h] BYREF

  v0 = 1;
  if ( g_connectedToApp && g_bBlinkIcon != 0 )
    SetConnectionIcon(icon: (g_currentIcon == 3) + 3);
  if ( busy == 0 )
  {
    if ( g_bAutoConnectWait > 0 && !g_bForceDisconnect )
    {
      if ( g_bAutoConnectQuiet == 0 )
        ConsoleWindowPrintf(rgb: 0, strFormat: "Waiting... %d seconds remaining\n", g_bAutoConnectWait);
      --g_bAutoConnectWait;
      return;
    }
    busy = 1;
    if ( g_connectedToApp )
    {
      if ( g_bForceDisconnect )
      {
        g_bForceDisconnect = false;
LABEL_30:
        v0 = 0;
disconnect:
        ConsoleWindowPrintf(rgb: 0, strFormat: "Connection To Xbox Lost.\n");
        v5 = g_autoConnect;
        lc_disconnect();
        if ( v5 != 0 && v0 != 0 )
        {
          lc_autoConnect();
          g_bAutoConnectQuiet = 0;
LABEL_37:
          g_bAutoConnectWait = 3;
        }
        busy = 0;
        return;
      }
      v4 = DmAPI_SendCommand(strCommand: "XCMD!", wait: false);
      if ( v4 < 0 && v4 != -2099642368 )
        goto disconnect;
    }
    else
    {
      if ( g_connectedToXBox != 0 )
      {
        DmCloseConnection(a1: g_pdmConnection);
        g_connectedToXBox = 0;
      }
      lc_listen();
      if ( g_connectedToXBox == 0 )
      {
        SetConnectionIcon(icon: 1);
        ++g_connectFailure;
      }
      if ( g_reboot != 0 && g_connectedToXBox != 0 )
      {
        DecodeRebootArgs(argc: g_rebootArgc, argv: g_rebootArgv, xexPath, xexName, xexArgs);
        if ( g_rebootArgc != 0 )
        {
          for ( i = 0; i < g_rebootArgc; ++i )
            Sys_Free(ptr: g_rebootArgv[i]);
          g_rebootArgc = 0;
          v2 = DmSetTitle(a1: xexPath, a2: xexName, a3: xexArgs);
          if ( v2 >= 0 )
          {
            v3 = DmGo();
            if ( v3 < 0 )
              DmAPI_DisplayError(message: "Reboot: DmGo() failure", hr: v3);
          }
          else
          {
            DmAPI_DisplayError(message: "Reboot: DmSetTitle() failure", hr: v2);
          }
        }
        g_reboot = 0;
      }
      if ( g_connectFailure != 0 )
      {
        if ( g_connectFailure == 1 )
        {
          g_bAutoConnectQuiet = 0;
          busy = 0;
          g_bAutoConnectWait = 15;
          return;
        }
        goto LABEL_30;
      }
    }
    g_bAutoConnectQuiet = 1;
    goto LABEL_37;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004136C0
// Name: int lc_modules(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_modules()
{
  unsigned int v0; // edi
  HRESULT v1; // eax
  int m_Size; // ebx
  int v3; // esi
  int v4; // esi
  _DMN_MODLOAD *m_pMemory; // edi
  void **p_BaseAddress; // eax
  _DMN_MODLOAD *v7; // edi
  int v8; // ebx
  unsigned int *p_Size; // esi
  _DMN_MODLOAD modLoad; // [esp+18h] [ebp-144h] BYREF
  unsigned int v12; // [esp+13Ch] [ebp-20h]
  CUtlVector<_DMN_MODLOAD,CUtlMemory<_DMN_MODLOAD,int> > list; // [esp+140h] [ebp-1Ch] BYREF
  _DM_WALK_MODULES *pWalkMod; // [esp+154h] [ebp-8h] BYREF
  HRESULT hr; // [esp+158h] [ebp-4h]

  v0 = 0;
  pWalkMod = nullptr;
  memset(&list, 0, sizeof(list));
  memset(&modLoad, 0, 260);
  memset(&modLoad.Size, 0, 28);
  modLoad.BaseAddress = (void *)-1;
  CUtlVector<_DMN_MODLOAD,CUtlMemory<_DMN_MODLOAD,int>>::InsertBefore(this: &list, elem: 0, src: &modLoad);
  ConsoleWindowPrintf(rgb: 0, strFormat: "Modules:\n");
  v1 = DmWalkLoadedModules(a1: &pWalkMod, a2: &modLoad);
  m_Size = list.m_Size;
  v3 = v1;
  hr = v1;
  if ( v1 == -2099642108 )
  {
LABEL_17:
    hr = 47841280;
    v3 = 47841280;
  }
  else
  {
    while ( v3 >= 0 )
    {
      v4 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = list.m_Memory.m_pMemory;
        p_BaseAddress = &list.m_Memory.m_pMemory->BaseAddress;
        while ( modLoad.BaseAddress > *p_BaseAddress )
        {
          ++v4;
          p_BaseAddress += 73;
          if ( v4 >= m_Size )
            goto LABEL_16;
        }
        if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<_DMN_MODLOAD,int>::Grow(this: &list.m_Memory, num: m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
          m_pMemory = list.m_Memory.m_pMemory;
        }
        list.m_Size = ++m_Size;
        list.m_pElements = m_pMemory;
        if ( m_Size - v4 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 292 * (m_Size - v4 - 1));
        v7 = &m_pMemory[v4];
        if ( v7 != nullptr )
          *v7 = modLoad;
      }
LABEL_16:
      v0 = 0;
      hr = DmWalkLoadedModules(a1: &pWalkMod, a2: &modLoad);
      if ( hr == -2099642108 )
        goto LABEL_17;
      v3 = hr;
    }
    DmAPI_DisplayError(message: "lc_modules(): DmWalkLoadedModules() failure", hr: v3);
  }
  v8 = m_Size - 1;
  if ( v8 > 0 )
  {
    p_Size = &list.m_Memory.m_pMemory->Size;
    do
    {
      ConsoleWindowPrintf(
        rgb: 0,
        strFormat: "Base: 0x%8.8x, Size: %5.2f MB, [%s]\n",
        *(p_Size - 1),
        (double)*p_Size * 0.00000095367432,
        (const char *)p_Size - 264);
      v0 += *p_Size;
      p_Size += 73;
      --v8;
    }
    while ( v8 != 0 );
    v3 = hr;
  }
  v12 = v0;
  ConsoleWindowPrintf(rgb: 0, strFormat: "Total: %.2f MB\n\n", (double)v0 * 0.00000095367432);
  if ( pWalkMod != nullptr )
    DmCloseLoadedModules(a1: pWalkMod);
  if ( v3 < 0 )
  {
    if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    return 1;
  }
}
