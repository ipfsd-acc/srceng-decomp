// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/sync_image.cpp
// Functions: 20
// ============================================================

#include "utils\xbox\vxconsole\sync_image.h"

//------------------------------------------------------------------------------
// Address: 0x00424800
// Name: int EmulateDlg_EnumWindowsProc(struct HWND__ __near *,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall EmulateDlg_EnumWindowsProc(HWND__ *hWnd, int lParam)
{
  char titleBuffer[256]; // [esp+4h] [ebp-100h] BYREF

  GetWindowTextA(hWnd, lpString: titleBuffer, nMaxCount: 256);
  if ( V_stristr(pStr: titleBuffer, pSearch: "Game Disc Emulator") == nullptr )
    return 1;
  GetWindowThreadProcessId(hWnd, lpdwProcessId: &g_emulatorProcessID);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424860
// Name: unsigned long EmulateDlg_GetEmulatorProcessID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl EmulateDlg_GetEmulatorProcessID()
{
  g_emulatorProcessID = 0;
  EnumWindows(lpEnumFunc: EmulateDlg_EnumWindowsProc, lParam: 0);
  return g_emulatorProcessID;
}

//------------------------------------------------------------------------------
// Address: 0x00424880
// Name: int SortDVDImages(struct dvdimage_t const __near *,struct dvdimage_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortDVDImages(const dvdimage_t *pA, const dvdimage_t *pB)
{
  int result; // eax

  result = pB->year - pA->year;
  if ( result == 0 )
  {
    result = pB->month - pA->month;
    if ( result == 0 )
    {
      result = pB->day - pA->day;
      if ( result == 0 )
      {
        result = pB->hour - pA->hour;
        if ( result == 0 )
          return pB->minute - pA->minute;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004248D0
// Name: bool InstallDlg_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InstallDlg_Init()
{
  Sys_GetRegistryString(
    keyName: "install_LastKnownImageName",
    value: g_install_LastKnownImageName,
    defValue: &defValue,
    valueLen: 0x104u);
  Sys_GetRegistryInteger(
    keyName: "install_showcandidatesonly",
    defValue: g_playtestMode,
    value: &g_install_bShowCandidatesOnly);
  Sys_GetRegistryInteger(keyName: "install_sync_lv", defValue: 1, value: &g_install_bSyncLV);
  Sys_GetRegistryInteger(keyName: "install_sync_languages", defValue: 1, value: &g_install_bSyncLanguages);
  Sys_GetRegistryInteger(keyName: "install_sync_movies", defValue: 1, value: &g_install_bSyncMovies);
  Sys_GetRegistryInteger(keyName: "install_cache_locally", defValue: 1, value: &g_install_bCacheLocally);
  Sys_GetRegistryInteger(keyName: "install_cache_exact_image", defValue: 1, value: &g_install_bCacheExactImage);
  if ( g_install_ImagePollTimer == 0 )
    g_install_ImagePollTimer = SetTimer(hWnd: g_hDlgMain, nIDEvent: 0x1002u, uElapse: 0x493E0u, lpTimerFunc: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00424990
// Name: void InstallDlg_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Shutdown()
{
  if ( g_install_ImagePollTimer != 0 )
  {
    KillTimer(hWnd: g_hDlgMain, uIDEvent: 0x1002u);
    g_install_ImagePollTimer = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004249C0
// Name: bool EmulateDlg_EmulateImage(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EmulateDlg_EmulateImage(const char *pInstallPath, bool bInstallIsLocal, bool bLowViolence)
{
  const char *v3; // eax
  char szCommandLine[1040]; // [esp+0h] [ebp-770h] BYREF
  char szXEDKPath[260]; // [esp+410h] [ebp-360h] BYREF
  char szToolPath[260]; // [esp+514h] [ebp-25Ch] BYREF
  char szXGDPath[260]; // [esp+618h] [ebp-158h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+71Ch] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+760h] [ebp-10h] BYREF

  if ( bInstallIsLocal )
  {
    v3 = "dvd_local_layout_lv.xgd";
    if ( !bLowViolence )
      v3 = "dvd_local_layout.xgd";
  }
  else
  {
    v3 = "dvd_layout_lv.xgd";
    if ( !bLowViolence )
      v3 = "dvd_layout.xgd";
  }
  V_ComposeFileName(path: pInstallPath, filename: v3, dest: szXGDPath, destSize: 260);
  if ( Sys_Exists(filename: szXGDPath) != 0 )
  {
    if ( g_bPublicTest != 0
      || (g_emulatorProcessID = 0,
          EnumWindows(lpEnumFunc: EmulateDlg_EnumWindowsProc, lParam: 0),
          g_emulatorProcessID == 0) )
    {
      memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
      if ( GetEnvironmentVariableA(lpName: "XEDK", lpBuffer: szXEDKPath, nSize: 0x104u) != 0 )
      {
        V_ComposeFileName(path: szXEDKPath, filename: "bin\\win32\\xbemulate.exe", dest: szToolPath, destSize: 260);
        memset(&pi, 0, sizeof(pi));
        V_snprintf(
          pDest: szCommandLine,
          maxLen: 1040,
          pFormat: "\"%s\" /media \"%s\" /emulate start",
          szToolPath,
          szXGDPath);
        if ( CreateProcessA(
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
        {
          return 1;
        }
        else
        {
          ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed to launch: %s\n", szCommandLine);
          return 0;
        }
      }
      else
      {
        ConsoleWindowPrintf(
          rgb: 0xFFu,
          strFormat: "Missing XEDK Environment Variable. Xbox 360 XDK not installed properly!\n");
        return 0;
      }
    }
    else
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "You must close all prior instances of the 'Game Disc Emulator'.\n");
      return 0;
    }
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cannot find '%s'\n", szXGDPath);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424B60
// Name: public: struct dvdimage_t __near & dvdimage_t::operator=(struct dvdimage_t const __near &)
// Source: json
//------------------------------------------------------------------------------
dvdimage_t *__thiscall dvdimage_t::operator=(dvdimage_t *this, const dvdimage_t *__that)
{
  dvdimage_t *v3; // eax
  int v4; // ecx
  int i; // edx

  v3 = this;
  v4 = (char *)__that - (char *)this;
  for ( i = 260; i != 0; --i )
  {
    v3->szString[0] = v3->szString[v4];
    v3 = (dvdimage_t *)((char *)v3 + 1);
  }
  CUtlString::operator=(this: &this->installPath, src: &__that->installPath);
  CUtlString::operator=(this: &this->versionDetailString, src: &__that->versionDetailString);
  CUtlString::operator=(this: &this->notesString, src: &__that->notesString);
  CUtlString::operator=(this: &this->buildLogPath, src: &__that->buildLogPath);
  this->year = __that->year;
  this->month = __that->month;
  this->day = __that->day;
  this->hour = __that->hour;
  this->minute = __that->minute;
  this->bCurrent = __that->bCurrent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424CC0
// Name: void InstallDlg_InstallImage(char const __near *,char const __near *,bool,bool,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_InstallImage(
        const char *pInstallPath,
        const char *pTargetPath,
        bool bTargetIsXbox,
        bool bForce,
        bool bCleanTarget,
        bool bSyncLanguages,
        bool bSyncMovies,
        bool bSyncLV)
{
  CProgress *v8; // eax
  CProgress *v9; // eax
  const char *Token; // esi
  const char *v11; // edi
  char *v12; // eax
  char *v13; // eax
  char *v14; // esi
  char TargetFile; // al
  char *v16; // eax
  const char *v17; // esi
  char *v18; // eax
  char *v19; // esi
  char *v20; // eax
  char *v21; // esi
  int v22; // eax
  char v23; // cl
  unsigned int v24; // eax
  char *v25; // edi
  char v26; // cl
  int v27; // eax
  char v28; // cl
  char v29; // cl
  unsigned int v30; // eax
  char *v31; // edi
  char v32; // cl
  int v33; // eax
  CProgress *v34; // edi
  char *v35; // eax
  char *v36; // eax
  int v37; // esi
  _DM_FILE_ATTRIBUTES fileAttributes; // [esp+24h] [ebp-CE8h] BYREF
  char filename[260]; // [esp+140h] [ebp-BCCh] BYREF
  char sourcePath[260]; // [esp+244h] [ebp-AC8h] BYREF
  char szVersionPath[260]; // [esp+348h] [ebp-9C4h] BYREF
  _WIN32_FIND_DATAA findData; // [esp+44Ch] [ebp-8C0h] BYREF
  char szScriptPath[260]; // [esp+58Ch] [ebp-780h] BYREF
  char statusBuff1[260]; // [esp+690h] [ebp-67Ch] BYREF
  char szTempFilename[260]; // [esp+794h] [ebp-578h] BYREF
  char szRootPath[260]; // [esp+898h] [ebp-474h] BYREF
  char targetFilename[260]; // [esp+99Ch] [ebp-370h] BYREF
  char arg2[128]; // [esp+AA0h] [ebp-26Ch] BYREF
  char sourceFilename[260]; // [esp+B20h] [ebp-1ECh] BYREF
  char arg1[128]; // [esp+C24h] [ebp-E8h] BYREF
  _WIN32_FILE_ATTRIBUTE_DATA localAttributes; // [esp+CA4h] [ebp-68h] BYREF
  double startTime; // [esp+CC8h] [ebp-44h]
  char *pArgs[3]; // [esp+CD0h] [ebp-3Ch] BYREF
  double fileSize; // [esp+CDCh] [ebp-30h] BYREF
  int iPDBCopyCount; // [esp+CE4h] [ebp-28h] BYREF
  int numUpdated; // [esp+CE8h] [ebp-24h]
  int numSkipped; // [esp+CECh] [ebp-20h]
  float numMBCopied; // [esp+CF0h] [ebp-1Ch]
  char *pVersionDetailString; // [esp+CF4h] [ebp-18h] BYREF
  int numFailed; // [esp+CF8h] [ebp-14h]
  float sourceFileSize; // [esp+CFCh] [ebp-10h]
  char *pTargetVersionDetailString; // [esp+D00h] [ebp-Ch] BYREF
  CProgress *pProgress; // [esp+D04h] [ebp-8h]
  bool bFailed; // [esp+D09h] [ebp-3h]
  bool bCancelled; // [esp+D0Ah] [ebp-2h]
  bool bSyntaxError; // [esp+D0Bh] [ebp-1h]

  startTime = _Plat_FloatTime();
  if ( *pInstallPath != 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "\nSyncing From Install Depot: %s\n", pInstallPath);
    V_ComposeFileName(path: pInstallPath, filename: "../dvd_install.txt", dest: szScriptPath, destSize: 260);
    if ( Sys_Exists(filename: szScriptPath) != 0 )
    {
      V_ComposeFileName(path: pInstallPath, filename: "default.xex", dest: szTempFilename, destSize: 260);
      if ( Sys_Exists(filename: szTempFilename) != 0 )
      {
        pVersionDetailString = nullptr;
        V_ComposeFileName(path: pInstallPath, filename: "version.txt", dest: szVersionPath, destSize: 260);
        if ( (int)Sys_LoadFile(filename: szVersionPath, bufferptr: (void **)&pVersionDetailString, bText: false) > 0 )
        {
          Sys_LoadScriptFile(filename: szScriptPath);
          v8 = (CProgress *)operator new(nSize: 0x24u);
          if ( v8 != nullptr )
            v9 = CProgress::CProgress(this: v8);
          else
            v9 = nullptr;
          pProgress = v9;
          CProgress::Open(this: v9, title: "Installing DVD Image...", canCancel: true, bHasMeter: false);
          numFailed = 0;
          numSkipped = 0;
          numUpdated = 0;
          numMBCopied = 0.0;
          bFailed = true;
          bSyntaxError = false;
          bCancelled = false;
          Token = Sys_GetToken(crossline: true);
          if ( Token != nullptr )
          {
            v11 = pTargetPath;
            while ( *Token != 0 )
            {
              if ( CProgress::IsCancel(this: pProgress) )
              {
                bCancelled = true;
                break;
              }
              if ( _V_stricmp(s1: Token, s2: "$version") != 0 )
              {
                if ( _V_stricmp(s1: Token, s2: "$print") != 0 )
                {
                  if ( _V_stricmp(s1: Token, s2: "$copy") != 0 )
                  {
                    if ( _V_stricmp(s1: Token, s2: "$end") == 0 )
                    {
                      bFailed = false;
                      break;
                    }
                    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Unknown token: '%s' in '%s'\n", Token, szScriptPath);
LABEL_97:
                    bSyntaxError = true;
                    break;
                  }
                  v18 = Sys_GetToken(crossline: false);
                  v19 = v18;
                  if ( v18 == nullptr || *v18 == 0 )
                    goto LABEL_97;
                  Sys_StripQuotesFromToken(pToken: v18);
                  V_FixSlashes(pname: v19, separator: 92);
                  if ( V_strnicmp(s1: v19, s2: "DVD\\", n: 4) == 0 )
                    v19 += 4;
                  V_ComposeFileName(path: pInstallPath, filename: v19, dest: arg1, destSize: 128);
                  v20 = Sys_GetToken(crossline: false);
                  v21 = v20;
                  if ( v20 == nullptr || *v20 == 0 )
                    goto LABEL_97;
                  Sys_StripQuotesFromToken(pToken: v20);
                  V_FixSlashes(pname: v21, separator: 92);
                  if ( *v21 == 92 )
                    memcpy(dst: (unsigned __int8 *)v21, src: (unsigned __int8 *)v21 + 1, count: strlen(v21));
                  V_ComposeFileName(path: v11, filename: v21, dest: arg2, destSize: 128);
                  Sys_StripFilename(inpath: arg1, outpath: sourcePath, outPathLen: 0x104u);
                  if ( (bSyncLV || V_stristr(pStr: arg1, pSearch: "_lv") == nullptr)
                    && (bSyncLanguages
                     || V_stristr(pStr: arg1, pSearch: "_french") == nullptr
                     && V_stristr(pStr: arg1, pSearch: "_german") == nullptr
                     && V_stristr(pStr: arg1, pSearch: "_russian") == nullptr
                     && V_stristr(pStr: arg1, pSearch: "_spanish") == nullptr) )
                  {
                    pTargetVersionDetailString = (char *)FindFirstFileA(lpFileName: arg1, lpFindFileData: &findData);
                    if ( pTargetVersionDetailString != (char *)-1 )
                    {
                      while ( !CProgress::IsCancel(this: pProgress) )
                      {
                        if ( _V_stricmp(s1: findData.cFileName, s2: ".") != 0
                          && _V_stricmp(s1: findData.cFileName, s2: "..") != 0
                          && (findData.dwFileAttributes & 0x10) == 0 )
                        {
                          v22 = 0;
                          do
                          {
                            v23 = sourcePath[v22];
                            sourceFilename[v22++] = v23;
                          }
                          while ( v23 != 0 );
                          Sys_AddFileSeperator(path: sourceFilename, pathLen: 0x104u);
                          v24 = strlen(findData.cFileName) + 1;
                          v25 = &arg2[127];
                          do
                            v26 = *++v25;
                          while ( v26 != 0 );
                          qmemcpy(v25, findData.cFileName, v24);
                          Sys_NormalizePath(path: sourceFilename, forceToLower: false);
                          Sys_StripPath(inpath: arg2, outpath: filename, outPathLen: 0x104u);
                          v27 = 0;
                          if ( filename[0] != 0 )
                          {
                            do
                            {
                              v28 = arg2[v27];
                              targetFilename[v27++] = v28;
                            }
                            while ( v28 != 0 );
                          }
                          else
                          {
                            do
                            {
                              v29 = arg2[v27];
                              targetFilename[v27++] = v29;
                            }
                            while ( v29 != 0 );
                            Sys_AddFileSeperator(path: targetFilename, pathLen: 0x104u);
                            v30 = strlen(findData.cFileName) + 1;
                            v31 = &szRootPath[259];
                            do
                              v32 = *++v31;
                            while ( v32 != 0 );
                            qmemcpy(v31, findData.cFileName, v30);
                            Sys_NormalizePath(path: targetFilename, forceToLower: false);
                          }
                          sourceFileSize = 0.0;
                          if ( GetFileAttributesExA(
                                 lpFileName: sourceFilename,
                                 fInfoLevelId: GetFileExInfoStandard,
                                 lpFileInformation: &localAttributes) )
                          {
                            sourceFileSize = (double)localAttributes.nFileSizeLow * 0.00000095367432;
                          }
                          if ( bSyncMovies
                            || V_stristr(pStr: sourceFilename, pSearch: ".bik") == nullptr
                            && V_stristr(pStr: sourceFilename, pSearch: ".wmv") == nullptr
                            || sourceFileSize < 20.0 )
                          {
                            ConsoleWindowPrintf(
                              rgb: 0,
                              strFormat: "\nCopying: %s -> %s\n",
                              sourceFilename,
                              targetFilename);
                            V_snprintf(
                              pDest: statusBuff1,
                              maxLen: 260,
                              pFormat: "Copying (%.2f MB) ... Please Wait",
                              sourceFileSize);
                            CProgress::SetStatus(
                              this: pProgress,
                              line1: statusBuff1,
                              line2: sourceFilename,
                              line3: targetFilename);
                            v33 = FileSyncToAny(
                                    localFilename: sourceFilename,
                                    targetFilename,
                                    bTargetIsXbox,
                                    fileSyncMode: 2 * !bForce + 1,
                                    bVerbose: true,
                                    bNoWrite: false);
                            if ( v33 >= 0 )
                            {
                              if ( v33 != 0 )
                              {
                                if ( v33 == 1 )
                                {
                                  ConsoleWindowPrintf(rgb: 0xFF00u, strFormat: "Sync Completed!\n");
                                  ++numUpdated;
                                  numMBCopied = sourceFileSize + numMBCopied;
                                }
                              }
                              else
                              {
                                ConsoleWindowPrintf(rgb: 0xFF0000u, strFormat: "Sync Skipped!\n");
                                ++numSkipped;
                              }
                            }
                            else
                            {
                              ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Sync Failure!\n");
                              ++numFailed;
                            }
                          }
                        }
                        if ( !FindNextFileA(hFindFile: pTargetVersionDetailString, lpFindFileData: &findData) )
                          goto LABEL_89;
                      }
                      bCancelled = true;
LABEL_89:
                      FindClose(hFindFile: pTargetVersionDetailString);
                      v11 = pTargetPath;
                    }
                  }
                }
                else
                {
                  v16 = Sys_GetToken(crossline: false);
                  v17 = v16;
                  if ( v16 == nullptr || *v16 == 0 )
                    goto LABEL_97;
                  Sys_StripQuotesFromToken(pToken: v16);
                  ConsoleWindowPrintf(rgb: 0, strFormat: "%s\n", v17);
                }
              }
              else
              {
                v12 = Sys_GetToken(crossline: false);
                if ( v12 == nullptr )
                  goto LABEL_97;
                if ( *v12 == 0 )
                  goto LABEL_97;
                atoi(nptr: v12);
                v13 = Sys_GetToken(crossline: false);
                v14 = v13;
                if ( v13 == nullptr || *v13 == 0 )
                  goto LABEL_97;
                Sys_StripQuotesFromToken(pToken: v13);
                V_FixSlashes(pname: v14, separator: 92);
                if ( *v14 == 92 )
                  memcpy(dst: (unsigned __int8 *)v14, src: (unsigned __int8 *)v14 + 1, count: strlen(v14));
                V_ComposeFileName(path: v11, filename: v14, dest: szRootPath, destSize: 260);
                if ( bCleanTarget )
                {
                  if ( bTargetIsXbox )
                  {
                    if ( DmGetFileAttributes(a1: szRootPath, a2: &fileAttributes) == 47841280 )
                    {
                      V_ComposeFileName(path: szRootPath, filename: "*.*", dest: szTempFilename, destSize: 260);
                      pArgs[0] = "*del";
                      pArgs[1] = szTempFilename;
                      pArgs[2] = "/s";
                      if ( lc_del(argc: 3, argv: pArgs) == 0 )
                        goto LABEL_26;
                    }
                  }
                  else if ( GetFileAttributesExA(
                              lpFileName: szRootPath,
                              fInfoLevelId: GetFileExInfoStandard,
                              lpFileInformation: &localAttributes) )
                  {
                    V_ComposeFileName(path: szRootPath, filename: "*.*", dest: szTempFilename, destSize: 260);
                    if ( DeleteFiles(pFileMask: szTempFilename, bRecurse: true, bVerbose: true) == 0 )
                    {
LABEL_26:
                      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed To Delete Files At '%s'.\n", szRootPath);
                      break;
                    }
                  }
                }
                V_ComposeFileName(path: szRootPath, filename: "version.txt", dest: statusBuff1, destSize: 260);
                if ( !bForce )
                {
                  pTargetVersionDetailString = nullptr;
                  if ( bTargetIsXbox )
                    TargetFile = LoadTargetFile(
                                   pTargetPath: statusBuff1,
                                   pFileSize: (int *)&fileSize + 1,
                                   pData: (void **)&pTargetVersionDetailString);
                  else
                    TargetFile = (int)Sys_LoadFile(
                                        filename: statusBuff1,
                                        bufferptr: (void **)&pTargetVersionDetailString,
                                        bText: true) > 0;
                  if ( TargetFile == 0 )
                    bForce = true;
                  Sys_Free(ptr: pTargetVersionDetailString);
                }
                if ( FileSyncToAny(
                       localFilename: szVersionPath,
                       targetFilename: statusBuff1,
                       bTargetIsXbox,
                       fileSyncMode: 1,
                       bVerbose: true,
                       bNoWrite: false) == 0 )
                {
                  ++numFailed;
                  break;
                }
              }
              Token = Sys_GetToken(crossline: true);
              if ( Token == nullptr )
                break;
            }
          }
          iPDBCopyCount = 0;
          if ( g_bLocallySyncDVDPDBs == 0 || bSyntaxError || bCancelled || bFailed )
          {
            v34 = pProgress;
          }
          else
          {
            v34 = pProgress;
            StackTranslation_CopyDVDPDBsToLocalFolder(
              pDVDImagePath: pInstallPath,
              pProgress,
              pNumPDBsCopied: &iPDBCopyCount);
          }
          fileSize = _Plat_FloatTime();
          if ( bSyntaxError )
            ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Syntax Error in '%s'.\n", szScriptPath);
          if ( bCancelled )
          {
            ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cancelled Installation!\n");
          }
          else if ( bFailed )
          {
            ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed Installation!\n");
          }
          else
          {
            v35 = V_stristr(pStr: pVersionDetailString, pSearch: "\r\n");
            if ( v35 != nullptr )
              *v35 = 0;
            ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
            ConsoleWindowPrintf(rgb: 0, strFormat: "Installation Completed.\n");
            ConsoleWindowPrintf(rgb: 0, strFormat: "-----------------------\n");
            v36 = pVersionDetailString;
            if ( pVersionDetailString == nullptr )
              v36 = "???";
            ConsoleWindowPrintf(rgb: 0, strFormat: "Version: %s\n", v36);
            if ( !bSyncLV )
              ConsoleWindowPrintf(rgb: 0, strFormat: "Skipped: Low Violence.\n");
            if ( !bSyncLanguages )
              ConsoleWindowPrintf(rgb: 0, strFormat: "Skipped: Languages.\n");
            if ( !bSyncMovies )
              ConsoleWindowPrintf(rgb: 0, strFormat: "Skipped: Movies.\n");
            if ( numFailed != 0 )
              ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "%d Failures.\n", numFailed);
            ConsoleWindowPrintf(rgb: 0, strFormat: "%d Files In Sync.\n", numSkipped);
            v37 = numUpdated;
            ConsoleWindowPrintf(rgb: 0, strFormat: "%d Files Updated.\n", numUpdated);
            if ( g_bLocallySyncDVDPDBs != 0 )
              ConsoleWindowPrintf(rgb: 0, strFormat: "%d PDBs Copied To Local Disk.\n", iPDBCopyCount);
            if ( v37 != 0 )
              ConsoleWindowPrintf(
                rgb: 0,
                strFormat: "%.2f MB Copied, %.2f seconds, %.2f MB/s.\n",
                numMBCopied,
                fileSize - startTime,
                numMBCopied / (fileSize - startTime));
            jpeg_mem_term();
          }
          if ( v34 != nullptr )
          {
            CProgress::~CProgress(this: v34);
            free(pMem: v34);
          }
          Sys_Free(ptr: pVersionDetailString);
          Sys_FreeScriptFile();
        }
        else
        {
          ConsoleWindowPrintf(
            rgb: 0xFFu,
            strFormat: "Cancelled Installation! DVD Image Auto-Build Process Failed! - Missing version.txt\n");
        }
      }
      else
      {
        ConsoleWindowPrintf(
          rgb: 0xFFu,
          strFormat: "Cancelled Installation! DVD Image Auto-Build Process Failed - Missing default.xex!\n");
      }
    }
    else
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed to open: %s\n", szScriptPath);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425790
// Name: bool InstallDlg_GetChanges(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InstallDlg_GetChanges(HWND__ *hWnd)
{
  int v1; // eax
  WPARAM v2; // esi
  HWND DlgItem; // eax
  const char *v4; // ecx
  const char *v5; // eax
  const char *v7; // [esp-8h] [ebp-110h]
  char szXGDPath[260]; // [esp+4h] [ebp-104h] BYREF

  v1 = -1;
  v2 = 0;
  g_install_Selection = -1;
  if ( g_install_dvdImages.m_Size > 0 )
  {
    while ( 1 )
    {
      DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
      if ( SendMessageA(hWnd: DlgItem, Msg: 0x102Cu, wParam: v2, lParam: 3) == 3 )
        break;
      if ( (int)++v2 >= g_install_dvdImages.m_Size )
      {
        v1 = g_install_Selection;
        goto LABEL_6;
      }
    }
    v1 = v2;
    g_install_Selection = v2;
  }
LABEL_6:
  if ( !g_install_bEmulateDialog || v1 == -1 )
    return 1;
  v4 = "dvd_layout_lv.xgd";
  if ( !g_install_bEmulateLVImage )
    v4 = "dvd_layout.xgd";
  v7 = v4;
  v5 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[v1].installPath);
  V_ComposeFileName(path: v5, filename: v7, dest: szXGDPath, destSize: 260);
  if ( Sys_Exists(filename: szXGDPath) == 0 )
  {
    Sys_MessageBox(title: "Emulate Failure", format: "Missing DVD Layout File.\nFailed to open: '%s'", szXGDPath);
    return 0;
  }
  if ( g_bPublicTest != 0 )
    return 1;
  g_emulatorProcessID = 0;
  EnumWindows(lpEnumFunc: EmulateDlg_EnumWindowsProc, lParam: 0);
  if ( g_emulatorProcessID == 0 )
    return 1;
  Sys_MessageBox(
    title: "Emulate Failure",
    format: "'Game Disc Emulator' already running.\nYou must close all prior instances of the 'Game Disc Emulator'.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004258C0
// Name: void InstallDlg_ViewLog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_ViewLog(HWND__ *hWnd)
{
  WPARAM v1; // esi
  HWND DlgItem; // eax
  WPARAM v3; // esi
  const char *v4; // eax
  const char *v5; // edi
  CFmtStrN<256> *v6; // eax
  CFmtStrN<256> v7; // [esp+4h] [ebp-264h] BYREF
  char szCommandLine[260]; // [esp+110h] [ebp-158h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+214h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+258h] [ebp-10h] BYREF

  v1 = 0;
  if ( g_install_dvdImages.m_Size > 0 )
  {
    while ( 1 )
    {
      DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
      if ( SendMessageA(hWnd: DlgItem, Msg: 0x102Cu, wParam: v1, lParam: 3) == 3 )
        break;
      if ( (int)++v1 >= g_install_dvdImages.m_Size )
        return;
    }
    if ( v1 != -1 )
    {
      v3 = v1;
      v4 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[v3].buildLogPath);
      if ( *v4 != 0 )
      {
        V_snprintf(pDest: szCommandLine, maxLen: 260, pFormat: "\"%s\" \"%s\"", "notepad.exe", v4);
        memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
        StartupInfo.cb = 68;
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
      else
      {
        v5 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[v3].installPath);
        v6 = CFmtStrN<256>::CFmtStrN<256>(
               this: &v7,
               pszFormat: "Image: %s",
               g_install_dvdImages.m_Memory.m_pMemory[v3].szString);
        Sys_MessageBox(title: v6->m_szBuf, format: "No Build Log Found At:\n%s", v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A00
// Name: public: dvdimage_t::dvdimage_t(void)
// Source: json
//------------------------------------------------------------------------------
dvdimage_t *__thiscall dvdimage_t::dvdimage_t(dvdimage_t *this)
{
  CUtlString::CUtlString(this: &this->installPath);
  CUtlString::CUtlString(this: &this->versionDetailString);
  CUtlString::CUtlString(this: &this->notesString);
  CUtlString::CUtlString(this: &this->buildLogPath);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425A40
// Name: public: dvdimage_t::~dvdimage_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall dvdimage_t::~dvdimage_t(dvdimage_t *this)
{
  this->buildLogPath.m_Storage.m_nActualLength = 0;
  if ( this->buildLogPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->buildLogPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->buildLogPath.m_Storage.m_Memory.m_pMemory);
      this->buildLogPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->buildLogPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->notesString.m_Storage.m_nActualLength = 0;
  if ( this->notesString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->notesString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->notesString.m_Storage.m_Memory.m_pMemory);
      this->notesString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->notesString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->versionDetailString.m_Storage.m_nActualLength = 0;
  if ( this->versionDetailString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->versionDetailString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->versionDetailString.m_Storage.m_Memory.m_pMemory);
      this->versionDetailString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->versionDetailString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->installPath.m_Storage.m_nActualLength = 0;
  if ( this->installPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->installPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->installPath.m_Storage.m_Memory.m_pMemory);
      this->installPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->installPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425B20
// Name: public: dvdimage_t::dvdimage_t(struct dvdimage_t const __near &)
// Source: json
//------------------------------------------------------------------------------
dvdimage_t *__thiscall dvdimage_t::dvdimage_t(dvdimage_t *this, const dvdimage_t *__that)
{
  qmemcpy(this, __that, 0x104u);
  CUtlString::CUtlString(this: &this->installPath, string: &__that->installPath);
  CUtlString::CUtlString(this: &this->versionDetailString, string: &__that->versionDetailString);
  CUtlString::CUtlString(this: &this->notesString, string: &__that->notesString);
  CUtlString::CUtlString(this: &this->buildLogPath, string: &__that->buildLogPath);
  this->year = __that->year;
  this->month = __that->month;
  this->day = __that->day;
  this->hour = __that->hour;
  this->minute = __that->minute;
  this->bCurrent = __that->bCurrent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425D30
// Name: void InstallDlg_BuildImageList(class CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>> __near &,int,int,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_BuildImageList(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *imageList,
        int bCandidatesOnly,
        int bLowViolenceOnly,
        bool bForEmulationOnly,
        const char *pCurrentVersionString)
{
  HANDLE FirstFileA; // ebx
  bool v6; // al
  char *v7; // edi
  char v8; // al
  char *v9; // edi
  char *v10; // eax
  int v11; // ebx
  char *v12; // esi
  int v13; // ecx
  char *v14; // eax
  int v15; // esi
  char *v16; // ebx
  const char *v17; // edi
  char szNotesPath[260]; // [esp+4h] [ebp-D9Ch] BYREF
  char szBuildLogPath[260]; // [esp+108h] [ebp-C98h] BYREF
  char szPath[260]; // [esp+20Ch] [ebp-B94h] BYREF
  char szBooterPath[260]; // [esp+310h] [ebp-A90h] BYREF
  char szVersionPath[260]; // [esp+414h] [ebp-98Ch] BYREF
  _WIN32_FIND_DATAA imageData; // [esp+518h] [ebp-888h] BYREF
  _WIN32_FIND_DATAA childData; // [esp+658h] [ebp-748h] BYREF
  char szNotes[256]; // [esp+798h] [ebp-608h] BYREF
  char szCommentBuff[128]; // [esp+898h] [ebp-508h] BYREF
  char timeOfDay[256]; // [esp+918h] [ebp-488h] BYREF
  char szInstallPath[260]; // [esp+A18h] [ebp-388h] BYREF
  char szToken[256]; // [esp+B1Ch] [ebp-284h] BYREF
  dvdimage_t image; // [esp+C1Ch] [ebp-184h] BYREF
  int v31; // [esp+D78h] [ebp-28h]
  void *h; // [esp+D7Ch] [ebp-24h]
  int c; // [esp+D80h] [ebp-20h]
  int month; // [esp+D84h] [ebp-1Ch] BYREF
  int year; // [esp+D88h] [ebp-18h] BYREF
  int minute; // [esp+D8Ch] [ebp-14h] BYREF
  int day; // [esp+D90h] [ebp-10h] BYREF
  int hour12; // [esp+D94h] [ebp-Ch] BYREF
  char *pVersionDetailString; // [esp+D98h] [ebp-8h] BYREF
  char *pNotesString; // [esp+D9Ch] [ebp-4h] BYREF

  V_ComposeFileName(path: g_installPath, filename: "DVD_*", dest: szPath, destSize: 260);
  FirstFileA = FindFirstFileA(lpFileName: szPath, lpFindFileData: &childData);
  h = FirstFileA;
  if ( FirstFileA != (HANDLE)-1 )
  {
    while ( 1 )
    {
      if ( _V_stricmp(s1: childData.cFileName, s2: ".") == 0 )
        goto LABEL_66;
      if ( _V_stricmp(s1: childData.cFileName, s2: "..") == 0 )
        goto LABEL_66;
      if ( (childData.dwFileAttributes & 0x10) == 0 )
        goto LABEL_66;
      V_strncpy(pDest: szInstallPath, pSrc: g_installPath, maxLen: 260);
      imageData = childData;
      V_AppendSlash(pStr: szInstallPath, strSize: 260);
      V_strncat(pDest: szInstallPath, pSrc: imageData.cFileName, destBufferSize: 0x104u, max_chars_to_copy: -1);
      V_ComposeFileName(path: szInstallPath, filename: "default.xex", dest: szBooterPath, destSize: 260);
      if ( Sys_Exists(filename: szBooterPath) == 0 )
        goto LABEL_66;
      V_ComposeFileName(path: szInstallPath, filename: "version.txt", dest: szVersionPath, destSize: 260);
      pVersionDetailString = nullptr;
      if ( Sys_LoadFile(filename: szVersionPath, bufferptr: (void **)&pVersionDetailString, bText: false) == -1 )
        goto LABEL_66;
      if ( pVersionDetailString == nullptr )
        goto LABEL_66;
      if ( *pVersionDetailString == 0 )
        goto LABEL_66;
      V_ComposeFileName(path: szInstallPath, filename: "notes.txt", dest: szNotesPath, destSize: 260);
      pNotesString = nullptr;
      v6 = Sys_LoadFile(filename: szNotesPath, bufferptr: (void **)&pNotesString, bText: false) != -1;
      if ( v6 || bCandidatesOnly == 0 && bLowViolenceOnly == 0 )
      {
        szNotes[0] = 0;
        if ( !v6 )
          goto LABEL_33;
        v7 = pNotesString;
        if ( pNotesString == nullptr )
          goto LABEL_33;
        if ( bCandidatesOnly == 0 )
          goto LABEL_24;
        if ( V_stristr(pStr: pNotesString, pSearch: "xlsp") != nullptr
          || V_stristr(pStr: pNotesString, pSearch: "cert") != nullptr
          || V_stristr(pStr: pNotesString, pSearch: "sync me") != nullptr
          || V_stristr(pStr: pNotesString, pSearch: "candidate") != nullptr
          || V_stristr(pStr: pNotesString, pSearch: "this one") != nullptr
          || V_stristr(pStr: pNotesString, pSearch: "final") != nullptr
          || V_stristr(pStr: pNotesString, pSearch: "test") != nullptr )
        {
          break;
        }
LABEL_22:
        Sys_Free(ptr: pNotesString);
      }
LABEL_66:
      if ( !FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &childData) )
      {
        FindClose(hFindFile: FirstFileA);
        goto LABEL_68;
      }
    }
    v7 = pNotesString;
LABEL_24:
    if ( bLowViolenceOnly == 0 )
      goto LABEL_29;
    if ( V_stristr(pStr: v7, pSearch: "LV") != nullptr
      || V_stristr(pStr: pNotesString, pSearch: "LowViolenece") != nullptr
      || V_stristr(pStr: pNotesString, pSearch: "Low Violence") != nullptr )
    {
      v7 = pNotesString;
LABEL_29:
      while ( 1 )
      {
        v8 = *v7;
        if ( *v7 == 0 )
          break;
        while ( isprint(c: v8) == 0 )
        {
          v8 = *++v7;
          if ( v8 == 0 )
            goto LABEL_32;
        }
        if ( *v7 == 0 )
          break;
        v10 = V_stristr(pStr: v7, pSearch: "\r\n");
        if ( v10 != nullptr )
        {
          v11 = v10 - v7;
          if ( (unsigned int)(v10 - v7) >= 0xFF )
            v11 = 255;
          _V_memcpy(dest: szToken, src: v7, count: v11);
          szToken[v11] = 0;
          if ( v11 > 0 )
          {
            v12 = &szInstallPath[v11 + 259];
            v31 = 1 - (_DWORD)szToken;
            do
            {
              c = *v12;
              if ( isprint(c) != 0 && isspace(c) == 0 )
                break;
              v13 = v31;
              *v12-- = 0;
            }
            while ( (int)&v12[v13] > 0 );
          }
        }
        else
        {
          V_strncpy(pDest: szToken, pSrc: v7, maxLen: 256);
          v11 = strlen(v7);
        }
        v7 += v11;
        Sys_StripQuotesFromToken(pToken: szToken);
        if ( szNotes[0] != 0 && szToken[0] != 0 )
          V_strncat(pDest: szNotes, pSrc: ", ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        V_strncat(pDest: szNotes, pSrc: szToken, destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
LABEL_32:
      Sys_Free(ptr: pNotesString);
LABEL_33:
      dvdimage_t::dvdimage_t(this: &image);
      if ( pCurrentVersionString == nullptr || _V_strcmp(s1: pVersionDetailString, s2: pCurrentVersionString) != 0 )
      {
        image.bCurrent = false;
      }
      else
      {
        v9 = (char *)Sys_Alloc(size: strlen(pVersionDetailString) + 5);
        sprintf(string: v9, format: "*** %s", pVersionDetailString);
        Sys_Free(ptr: pVersionDetailString);
        pVersionDetailString = v9;
        image.bCurrent = true;
      }
      v14 = V_stristr(pStr: pVersionDetailString, pSearch: "\r\n");
      if ( v14 != nullptr )
        *v14 = 0;
      year = 0;
      month = 0;
      day = 0;
      hour12 = 0;
      minute = 0;
      timeOfDay[0] = 0;
      sscanf(
        string: imageData.cFileName,
        format: "DVD_%d_%d_%d_%d_%d_%s",
        &year,
        &month,
        &day,
        &hour12,
        &minute,
        timeOfDay);
      v15 = hour12;
      v16 = timeOfDay;
      v17 = &defValue;
      if ( V_strnicmp(s1: timeOfDay, s2: "PM", n: 2) == 0 )
      {
        if ( hour12 != 12 )
          v15 += 12;
        v17 = " PM";
        goto LABEL_61;
      }
      if ( V_strnicmp(s1: timeOfDay, s2: "AM", n: 2) == 0 )
      {
        if ( hour12 == 12 )
          v15 = 0;
        v17 = " AM";
LABEL_61:
        v16 = &timeOfDay[2];
      }
      if ( *v16 == 95 )
        V_snprintf(pDest: szCommentBuff, maxLen: 128, pFormat: " (%s)", v16 + 1);
      else
        szCommentBuff[0] = 0;
      image.hour = v15;
      image.minute = minute;
      image.month = month;
      image.year = year;
      image.day = day;
      V_snprintf(
        pDest: image.szString,
        maxLen: 260,
        pFormat: "%2.2d/%2.2d/%4.4d %2.2d:%2.2d%s%s",
        month,
        day,
        year,
        hour12,
        minute,
        v17,
        szCommentBuff);
      CUtlString::operator=(this: &image.installPath, src: szInstallPath);
      CUtlString::operator=(this: &image.versionDetailString, src: pVersionDetailString);
      CUtlString::operator=(this: &image.notesString, src: szNotes);
      V_ComposeFileName(path: szInstallPath, filename: "dvdlog.txt", dest: szBuildLogPath, destSize: 260);
      CUtlString::operator=(this: &image.buildLogPath, src: szBuildLogPath);
      CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::InsertBefore(
        this: imageList,
        elem: imageList->m_Size,
        src: &image);
      Sys_Free(ptr: pVersionDetailString);
      dvdimage_t::~dvdimage_t(this: &image);
      FirstFileA = h;
      goto LABEL_66;
    }
    goto LABEL_22;
  }
LABEL_68:
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Sort(
    this: imageList,
    pfnCompare: (int (__cdecl *)(const void *, const void *))SortDVDImages);
}

//------------------------------------------------------------------------------
// Address: 0x00426420
// Name: void InstallDlg_Populate(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Populate(HWND__ *hWnd)
{
  HWND DlgItem; // edi
  char *LocalImageVersionString; // eax
  const char *v3; // esi
  int v4; // esi
  bool v5; // zf
  tagLVITEMA _macro_lvi; // [esp+Ch] [ebp-3Ch] BYREF

  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
  SendMessageA(hWnd: DlgItem, Msg: 0x1009u, wParam: 0, lParam: 0);
  if ( g_install_bEmulateDialog )
    LocalImageVersionString = GetLocalImageVersionString();
  else
    LocalImageVersionString = GetCurrentImageVersionString();
  v3 = LocalImageVersionString;
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &g_install_dvdImages);
  InstallDlg_BuildImageList(
    imageList: &g_install_dvdImages,
    bCandidatesOnly: g_install_bShowCandidatesOnly,
    bLowViolenceOnly: g_install_bEmulateLVImage & (unsigned __int8)-g_install_bEmulateDialog,
    bForEmulationOnly: g_install_bEmulateDialog,
    pCurrentVersionString: v3);
  v4 = 0;
  v5 = g_install_dvdImages.m_Size == 0;
  if ( g_install_dvdImages.m_Size > 0 )
  {
    do
    {
      memset(dst: (unsigned __int8 *)&_macro_lvi, value: 0, count: sizeof(_macro_lvi));
      _macro_lvi.mask = 13;
      _macro_lvi.iItem = v4;
      memset(&_macro_lvi.iSubItem, 0, 12);
      _macro_lvi.pszText = (char *)-1;
      _macro_lvi.lParam = v4;
      SendMessageA(hWnd: DlgItem, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&_macro_lvi);
      ++v4;
    }
    while ( v4 < g_install_dvdImages.m_Size );
    v5 = g_install_dvdImages.m_Size == 0;
  }
  if ( !v5 )
  {
    _macro_lvi.stateMask = 3;
    _macro_lvi.state = 3;
    SendMessageA(hWnd: DlgItem, Msg: 0x102Bu, wParam: 0, lParam: (LPARAM)&_macro_lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426510
// Name: void InstallDlg_Setup(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Setup(HWND__ *hWnd)
{
  HWND DlgItem; // edi
  tagLVCOLUMNA lvc; // [esp+Ch] [ebp-2Ch] BYREF

  g_install_Selection = -1;
  g_install_bForceSync = false;
  g_install_bCleanTarget = false;
  CheckDlgButton(hDlg: hWnd, nIDButton: 1084, uCheck: g_install_bShowCandidatesOnly != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1092, uCheck: g_install_bSyncLV != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1093, uCheck: g_install_bSyncLanguages != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1094, uCheck: g_install_bSyncMovies != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1086, uCheck: g_install_bCacheLocally != 0);
  CheckDlgButton(hDlg: hWnd, nIDButton: 1087, uCheck: g_install_bCacheExactImage != 0);
  DlgItem = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1088);
  memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
  lvc.iSubItem = 0;
  lvc.fmt = 0;
  lvc.mask = 15;
  lvc.cx = 150;
  lvc.pszText = "Date Built:";
  SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 0, lParam: (LPARAM)&lvc);
  lvc.iSubItem = 0;
  lvc.fmt = 0;
  lvc.cx = 250;
  lvc.pszText = "Notes:";
  SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 1u, lParam: (LPARAM)&lvc);
  lvc.iSubItem = 0;
  lvc.fmt = 0;
  lvc.cx = 500;
  lvc.pszText = "Perforce Changelist:";
  SendMessageA(hWnd: DlgItem, Msg: 0x101Bu, wParam: 2u, lParam: (LPARAM)&lvc);
  SendMessageA(hWnd: DlgItem, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
  SendMessageA(hWnd: DlgItem, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
  SendMessageA(hWnd: DlgItem, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
  SendMessageA(hWnd: DlgItem, Msg: 0x1036u, wParam: 0x21u, lParam: 33);
  InstallDlg_Populate(hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x004266A0
// Name: int InstallDlg_Proc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall InstallDlg_Proc(HWND hWnd, unsigned int message, INT_PTR wParam, _DWORD *lParam)
{
  int result; // eax
  UINT (__stdcall *v5)(HWND, int); // edi
  int v6; // ecx
  int v7; // eax
  int v8; // ecx

  if ( message == 78 )
  {
    if ( lParam[2] == -150 )
    {
      v6 = lParam[5];
      v7 = lParam[11];
      if ( v6 == 0 )
      {
        lParam[8] = &g_install_dvdImages.m_Memory.m_pMemory[v7];
        return 1;
      }
      v8 = v6 - 1;
      if ( v8 == 0 )
      {
        lParam[8] = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[v7].notesString);
        return 1;
      }
      if ( v8 == 1 )
      {
        lParam[8] = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[v7].versionDetailString);
        return 1;
      }
    }
    return 0;
  }
  if ( message == 272 )
  {
    InstallDlg_Setup(hWnd);
    return 1;
  }
  if ( message != 273 )
    return 0;
  if ( (unsigned __int16)wParam <= 0x3FBu )
  {
    if ( (unsigned __int16)wParam != 1019 )
    {
      if ( (unsigned __int16)wParam == 2 )
        goto LABEL_9;
      return 0;
    }
    if ( InstallDlg_GetChanges(hWnd) != 0 )
    {
LABEL_9:
      EndDialog(hDlg: hWnd, nResult: wParam);
      return 1;
    }
    return 1;
  }
  v5 = IsDlgButtonChecked;
  switch ( (__int16)wParam )
  {
    case 1020:
      goto LABEL_9;
    case 1083:
      g_install_bForceSync = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1083) != 0;
      return 0;
    case 1084:
      goto $LN3_8;
    case 1085:
      g_install_bEmulateLVImage = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1085) != 0;
$LN3_8:
      g_install_bShowCandidatesOnly = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1084) != 0;
      goto $LN2_8;
    case 1086:
      goto $LN8_7;
    case 1087:
      g_install_bCacheExactImage = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1087) != 0;
      return 0;
    case 1089:
$LN2_8:
      InstallDlg_Populate(hWnd);
      result = 1;
      break;
    case 1090:
      InstallDlg_ViewLog(hWnd);
      result = 1;
      break;
    case 1091:
      g_install_bCleanTarget = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1091) != 0;
      result = 0;
      break;
    case 1092:
      v5 = IsDlgButtonChecked;
      g_install_bSyncLV = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1092) != 0;
$LN8_7:
      g_install_bCacheLocally = v5(hDlg: hWnd, nIDButton: 1086) != 0;
      result = 0;
      break;
    case 1093:
      g_install_bSyncLanguages = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1093) != 0;
      result = 0;
      break;
    case 1094:
      g_install_bSyncMovies = IsDlgButtonChecked(hDlg: hWnd, nIDButton: 1094) != 0;
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004269A0
// Name: void InstallDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_Open()
{
  int v0; // eax
  bool *p_bCurrent; // ecx
  const char *v2; // eax

  g_install_bEmulateDialog = false;
  if ( (unsigned __int16)DialogBoxParamA(
                           hInstance: g_hInstance,
                           lpTemplateName: (LPCSTR)0x84,
                           hWndParent: g_hDlgMain,
                           lpDialogFunc: (DLGPROC)InstallDlg_Proc,
                           dwInitParam: 0) == 1019
    && g_install_Selection != -1 )
  {
    v0 = 0;
    if ( g_install_dvdImages.m_Size > 0 )
    {
      p_bCurrent = &g_install_dvdImages.m_Memory.m_pMemory->bCurrent;
      do
      {
        if ( *p_bCurrent )
          break;
        ++v0;
        p_bCurrent += 348;
      }
      while ( v0 < g_install_dvdImages.m_Size );
    }
    if ( v0 != g_install_dvdImages.m_Size && g_install_Selection > v0 )
      g_install_bForceSync = true;
    v2 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[g_install_Selection].installPath);
    InstallDlg_InstallImage(
      pInstallPath: v2,
      pTargetPath: g_targetPath,
      bTargetIsXbox: true,
      bForce: g_install_bForceSync,
      bCleanTarget: g_install_bCleanTarget,
      bSyncLanguages: g_install_bSyncLanguages != 0,
      bSyncMovies: g_install_bSyncMovies != 0,
      bSyncLV: g_install_bSyncLV != 0);
    UpdateCurrentImageVersionString();
  }
  Sys_SetRegistryInteger(keyName: "install_showcandidatesonly", value: g_install_bShowCandidatesOnly);
  Sys_SetRegistryInteger(keyName: "install_sync_lv", value: g_install_bSyncLV);
  Sys_SetRegistryInteger(keyName: "install_sync_languages", value: g_install_bSyncLanguages);
  Sys_SetRegistryInteger(keyName: "install_sync_movies", value: g_install_bSyncMovies);
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &g_install_dvdImages);
}

//------------------------------------------------------------------------------
// Address: 0x00426AE0
// Name: void EmulateDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmulateDlg_Open()
{
  int v0; // eax
  const char *v1; // esi
  const char *v2; // eax
  const char *v3; // eax
  bool v4; // zf
  const char *v5; // eax
  char szSourceXGDPath[260]; // [esp+4h] [ebp-208h] BYREF
  char szTargetXGDPath[260]; // [esp+108h] [ebp-104h] BYREF

  g_install_bEmulateDialog = true;
  if ( (unsigned __int16)DialogBoxParamA(
                           hInstance: g_hInstance,
                           lpTemplateName: (LPCSTR)0x99,
                           hWndParent: g_hDlgMain,
                           lpDialogFunc: (DLGPROC)InstallDlg_Proc,
                           dwInitParam: 0) != 1019 )
    goto LABEL_13;
  v0 = g_install_Selection;
  if ( g_install_Selection == -1 )
    goto LABEL_13;
  if ( g_install_bCacheLocally != 0 )
  {
    v1 = "c:\\dvd_cache";
    if ( g_install_bCacheExactImage != 0 )
    {
      if ( EmulateDlg_GetEmulatorProcessID() != 0 )
      {
        ConsoleWindowPrintf(
          rgb: 0xFFu,
          strFormat: "Cannot clear out emulator image cache due to open file references.\n");
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "You must close all prior instances of the 'Game Disc Emulator'.\n");
        return;
      }
      v0 = g_install_Selection;
    }
    v2 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[v0].installPath);
    InstallDlg_InstallImage(
      pInstallPath: v2,
      pTargetPath: "c:\\dvd_cache",
      bTargetIsXbox: false,
      bForce: false,
      bCleanTarget: g_install_bCacheExactImage != 0,
      bSyncLanguages: true,
      bSyncMovies: true,
      bSyncLV: true);
    v3 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[g_install_Selection].installPath);
    V_ComposeFileName(path: v3, filename: "dvd_local_layout.xgd", dest: szSourceXGDPath, destSize: 260);
    V_ComposeFileName(path: "c:\\dvd_cache", filename: "dvd_local_layout.xgd", dest: szTargetXGDPath, destSize: 260);
    FileSyncToAny(
      localFilename: szSourceXGDPath,
      targetFilename: szTargetXGDPath,
      bTargetIsXbox: false,
      fileSyncMode: 3,
      bVerbose: true,
      bNoWrite: false);
    v4 = !g_install_bEmulateLVImage;
    if ( !g_install_bEmulateLVImage )
      goto LABEL_12;
    v5 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[g_install_Selection].installPath);
    V_ComposeFileName(path: v5, filename: "dvd_local_layout_lv.xgd", dest: szSourceXGDPath, destSize: 260);
    V_ComposeFileName(path: "c:\\dvd_cache", filename: "dvd_local_layout_lv.xgd", dest: szTargetXGDPath, destSize: 260);
    FileSyncToAny(
      localFilename: szSourceXGDPath,
      targetFilename: szTargetXGDPath,
      bTargetIsXbox: false,
      fileSyncMode: 3,
      bVerbose: true,
      bNoWrite: false);
  }
  else
  {
    v1 = CUtlString::operator char const *(this: &g_install_dvdImages.m_Memory.m_pMemory[g_install_Selection].installPath);
  }
  v4 = !g_install_bEmulateLVImage;
LABEL_12:
  EmulateDlg_EmulateImage(pInstallPath: v1, bInstallIsLocal: g_install_bCacheLocally != 0, bLowViolence: !v4);
LABEL_13:
  Sys_SetRegistryInteger(keyName: "install_showcandidatesonly", value: g_install_bShowCandidatesOnly);
  Sys_SetRegistryInteger(keyName: "install_cache_locally", value: g_install_bCacheLocally);
  Sys_SetRegistryInteger(keyName: "install_cache_exact_image", value: g_install_bCacheExactImage);
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &g_install_dvdImages);
}

//------------------------------------------------------------------------------
// Address: 0x00426D30
// Name: void InstallDlg_ImagePollTimerProc(struct HWND__ __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallDlg_ImagePollTimerProc()
{
  dvdimage_t *m_pMemory; // esi
  const char *v1; // eax
  FLASHWINFO flashWInfo; // [esp+4h] [ebp-28h] BYREF
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > imageList; // [esp+18h] [ebp-14h] BYREF

  if ( g_bNotifyOnNewImage != 0 && busy_1 == 0 )
  {
    busy_1 = 1;
    memset(&imageList, 0, sizeof(imageList));
    InstallDlg_BuildImageList(
      &imageList,
      bCandidatesOnly: 0,
      bLowViolenceOnly: 0,
      bForEmulationOnly: false,
      pCurrentVersionString: nullptr);
    if ( imageList.m_Size != 0 )
    {
      m_pMemory = imageList.m_Memory.m_pMemory;
      if ( _V_stricmp(s1: imageList.m_Memory.m_pMemory->szString, s2: g_install_LastKnownImageName) != 0 )
      {
        V_strncpy(pDest: g_install_LastKnownImageName, pSrc: m_pMemory->szString, maxLen: 260);
        Sys_SetRegistryString(keyName: "install_LastKnownImageName", value: g_install_LastKnownImageName);
        ConsoleWindowPrintf(rgb: 0x50FF50u, strFormat: "********************************************************\n");
        ConsoleWindowPrintf(rgb: 0xFF00FFu, strFormat: "A New DVD Image Has Been Detected: %s\n", m_pMemory->szString);
        v1 = CUtlString::operator char const *(this: &m_pMemory->versionDetailString);
        ConsoleWindowPrintf(rgb: 0xFF00FFu, strFormat: "%s\n", v1);
        ConsoleWindowPrintf(rgb: 0x50FF50u, strFormat: "********************************************************\n");
        flashWInfo.cbSize = 20;
        flashWInfo.hwnd = g_hDlgMain;
        flashWInfo.dwFlags = 15;
        flashWInfo.uCount = 5;
        flashWInfo.dwTimeout = 250;
        FlashWindowEx(pfwi: &flashWInfo);
      }
    }
    busy_1 = 0;
    CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &imageList);
    if ( imageList.m_Memory.m_nGrowSize >= 0 && imageList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: imageList.m_Memory.m_pMemory);
  }
}
