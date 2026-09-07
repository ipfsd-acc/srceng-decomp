// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/common.cpp
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E160
// Name: char const __near * GetCurrentImageVersionString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetCurrentImageVersionString()
{
  return g_szVersionString;
}

//------------------------------------------------------------------------------
// Address: 0x0040E170
// Name: char const __near * UpdateCurrentImageVersionString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl UpdateCurrentImageVersionString()
{
  char *v0; // eax
  unsigned int v1; // esi
  const char *v2; // eax
  char szVersionPath[260]; // [esp+0h] [ebp-10Ch] BYREF
  int fileSize; // [esp+104h] [ebp-8h] BYREF
  char *pVersionDetailString; // [esp+108h] [ebp-4h] BYREF

  g_szVersionString[0] = 0;
  V_ComposeFileName(path: g_targetPath, filename: "version.txt", dest: szVersionPath, destSize: 260);
  if ( LoadTargetFile(pTargetPath: szVersionPath, pFileSize: &fileSize, pData: (void **)&pVersionDetailString) )
  {
    v0 = pVersionDetailString;
    if ( pVersionDetailString != nullptr && *pVersionDetailString != 0 )
    {
      V_strncpy(pDest: g_szVersionString, pSrc: pVersionDetailString, maxLen: 260);
      v0 = pVersionDetailString;
    }
    Sys_Free(ptr: v0);
  }
  v1 = 0;
  v2 = StringAfterPrefix(str: g_szVersionString, prefix: "Change ");
  if ( v2 != nullptr )
    v1 = atoi(nptr: v2);
  SetImageVersion(nVersion: v1);
  return g_szVersionString;
}

//------------------------------------------------------------------------------
// Address: 0x0040E220
// Name: char const __near * GetLocalImageVersionString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLocalImageVersionString()
{
  char *v0; // eax
  char szVersionPath[260]; // [esp+0h] [ebp-108h] BYREF
  char *pVersionDetailString; // [esp+104h] [ebp-4h] BYREF

  szLocalVersionString[0] = 0;
  V_ComposeFileName(path: "c:\\dvd_cache", filename: "version.txt", dest: szVersionPath, destSize: 260);
  if ( Sys_LoadFile(filename: szVersionPath, bufferptr: (void **)&pVersionDetailString, bText: false) > 0 )
  {
    v0 = pVersionDetailString;
    if ( pVersionDetailString != nullptr && *pVersionDetailString != 0 )
    {
      V_strncpy(pDest: szLocalVersionString, pSrc: pVersionDetailString, maxLen: 260);
      v0 = pVersionDetailString;
    }
    Sys_Free(ptr: v0);
  }
  return szLocalVersionString;
}

//------------------------------------------------------------------------------
// Address: 0x0040E2A0
// Name: void FormatImageVersionString(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FormatImageVersionString(const char *pVersion, char *pOutString, int outSize)
{
  const char *v3; // eax
  char *v4; // eax
  char timeOfDay[256]; // [esp+8h] [ebp-218h] BYREF
  char szString[260]; // [esp+108h] [ebp-118h] BYREF
  int hour12; // [esp+20Ch] [ebp-14h] BYREF
  int year; // [esp+210h] [ebp-10h] BYREF
  int month; // [esp+214h] [ebp-Ch] BYREF
  int minute; // [esp+218h] [ebp-8h] BYREF
  int day; // [esp+21Ch] [ebp-4h] BYREF

  szString[0] = 0;
  v3 = V_stristr(pStr: pVersion, pSearch: "DVD_");
  if ( v3 != nullptr )
  {
    year = 0;
    month = 0;
    day = 0;
    hour12 = 0;
    minute = 0;
    timeOfDay[0] = 0;
    sscanf(string: v3, format: "DVD_%d_%d_%d_%d_%d_%s", &year, &month, &day, &hour12, &minute, timeOfDay);
    V_snprintf(
      pDest: szString,
      maxLen: 260,
      pFormat: "%2.2d/%2.2d/%4.4d %2.2d:%2.2d %s ",
      month,
      day,
      year,
      hour12,
      minute,
      timeOfDay);
  }
  V_strncat(pDest: szString, pSrc: pVersion, destBufferSize: 0x104u, max_chars_to_copy: -1);
  v4 = V_stristr(pStr: szString, pSearch: "\r\n");
  if ( v4 != nullptr )
    *v4 = 0;
  V_strncpy(pDest: pOutString, pSrc: szString, maxLen: outSize);
}

//------------------------------------------------------------------------------
// Address: 0x0040E390
// Name: enum vprofState_e VProf_GetState(void)
// Source: json
//------------------------------------------------------------------------------
vprofState_e __cdecl VProf_GetState()
{
  return g_vprof_state;
}

//------------------------------------------------------------------------------
// Address: 0x0040E3A0
// Name: void VProf_Enable(enum vprofState_e)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProf_Enable(vprofState_e state)
{
  vprofState_e v1; // edx
  char *v2; // edi
  char *v3; // esi
  int v4; // ecx
  const char *v5; // esi
  char *v6; // edi
  const char *v7; // esi
  char commandString[256]; // [esp+8h] [ebp-100h] BYREF

  v1 = state;
  if ( state == VPROF_CPU )
  {
    v4 = 10;
    v5 = "vprof_off ; vprof_on ; vx_vprof_update cpu";
    goto LABEL_8;
  }
  if ( state == VPROF_TEXTURE )
  {
    v4 = 11;
    v5 = "vprof_off ; vprof_on ; vx_vprof_update texture";
LABEL_8:
    qmemcpy(commandString, v5, 4 * v4);
    v7 = &v5[4 * v4];
    v6 = &commandString[4 * v4];
    *(_WORD *)v6 = *(_WORD *)v7;
    v3 = (char *)(v7 + 2);
    v2 = v6 + 2;
    goto LABEL_9;
  }
  if ( state != VPROF_TEXTUREFRAME )
  {
    v1 = VPROF_OFF;
    strcpy(commandString, "vprof_off");
    goto LABEL_10;
  }
  qmemcpy(commandString, "vprof_off ; vprof_on ; vx_vprof_update texture_frame", 0x34u);
  v3 = "";
  v2 = &commandString[52];
LABEL_9:
  *v2 = *v3;
LABEL_10:
  if ( g_vprof_state != v1 )
  {
    g_vprof_state = v1;
    ProcessCommand(strCmdIn: commandString);
    CpuProfile_SetTitle();
    TexProfile_SetTitle();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E450
// Name: char __near * GetPerfmonFileserverPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetPerfmonFileserverPath()
{
  return g_FileserverPerfmonLogFileName;
}

//------------------------------------------------------------------------------
// Address: 0x0040E460
// Name: struct _iobuf __near * GetPlaytestFileserverLogFile(void)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl GetPlaytestFileserverLogFile()
{
  char szLogPath[260]; // [esp+0h] [ebp-208h] BYREF
  char szLogName[260]; // [esp+104h] [ebp-104h] BYREF

  if ( g_FileserverPlaytestLogFileName[0] == 0 )
    return nullptr;
  V_snprintf(pDest: szLogName, maxLen: 260, pFormat: "vxconsole_%s.log", g_xboxTargetName);
  V_ComposeFileName(path: g_FileserverPlaytestLogFileName, filename: szLogName, dest: szLogPath, destSize: 260);
  return fopen(file: szLogPath, mode: "at+");
}

//------------------------------------------------------------------------------
// Address: 0x0040E4D0
// Name: struct _iobuf __near * GetPerfmonFileserverLogFile(void)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl GetPerfmonFileserverLogFile()
{
  char szLogPath[260]; // [esp+0h] [ebp-208h] BYREF
  char szLogName[260]; // [esp+104h] [ebp-104h] BYREF

  if ( g_FileserverPerfmonLogFileName[0] == 0 )
    return nullptr;
  V_snprintf(pDest: szLogName, maxLen: 260, pFormat: "perfmon_%s.log", g_xboxTargetName);
  V_ComposeFileName(path: g_FileserverPerfmonLogFileName, filename: szLogName, dest: szLogPath, destSize: 260);
  return fopen(file: szLogPath, mode: "at+");
}

//------------------------------------------------------------------------------
// Address: 0x0040E540
// Name: struct _iobuf __near * GetPlaytestLocalLogFile(void)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl GetPlaytestLocalLogFile()
{
  char szLogName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( !bParsedCommandLine )
  {
    ParseCommandLineArg(pKey: "-local_log", pValueBuff: szLogPath, valueBuffSize: 260);
    if ( szLogPath[0] != 0 )
      bOverrideLocalLogFile = true;
    bParsedCommandLine = true;
  }
  if ( !bOverrideLocalLogFile )
  {
    V_snprintf(pDest: szLogName, maxLen: 260, pFormat: "vxconsole_%s.log", g_xboxTargetName);
    V_ComposeFileName(path: g_localPath, filename: szLogName, dest: szLogPath, destSize: 260);
  }
  return fopen(file: szLogPath, mode: "at+");
}

//------------------------------------------------------------------------------
// Address: 0x0040E5E0
// Name: void InitiateLoggingPlaytestToFileserver(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitiateLoggingPlaytestToFileserver()
{
  tm *v0; // eax
  tm *v1; // eax
  __int64 timeptr; // [esp+4h] [ebp-8h] BYREF

  _time64(&timeptr);
  v0 = _localtime64(ptime: &timeptr);
  if ( g_xboxName[0] != 0 )
  {
    V_snprintf(
      pDest: g_FileserverPlaytestLogFileName,
      maxLen: 260,
      pFormat: "%s\\logs\\%s\\%2.2d_%2.2d_%2.2d__%2.2d_%2.2d_%2.2d\\",
      g_installPath,
      g_xboxName,
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
  _time64(&timeptr);
  v1 = _localtime64(ptime: &timeptr);
  if ( g_xboxName[0] != 0 )
  {
    V_snprintf(
      pDest: g_FileserverPerfmonLogFileName,
      maxLen: 260,
      pFormat: "%s\\perfmon\\%s\\%2.2d_%2.2d_%2.2d__%2.2d_%2.2d_%2.2d\\",
      g_installPath,
      g_xboxName,
      v1->tm_mon + 1,
      v1->tm_mday,
      v1->tm_year % 100,
      v1->tm_hour,
      v1->tm_min,
      v1->tm_sec);
    Sys_CreatePath(pInPath: g_FileserverPerfmonLogFileName);
  }
  else
  {
    g_FileserverPerfmonLogFileName[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E6F0
// Name: void OnPlaytestModeChange(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnPlaytestModeChange(bool bTurnedOn)
{
  if ( bTurnedOn )
  {
    if ( g_connectedToApp )
      InitiateLoggingPlaytestToFileserver();
  }
  else if ( g_connectedToApp )
  {
    ProcessCommand(strCmdIn: "exec playtest_off.360.cfg");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E720
// Name: void DrawHelper(struct HDC__ __near *,struct tagRECT __near *,void (*)(struct HDC__ __near *,struct tagRECT __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawHelper(HDC__ *hdc, HBRUSH__ *clientRect, void (__cdecl *drawFunc)(HDC__ *, tagRECT *))
{
  HDC CompatibleDC; // edi
  HBRUSH SolidBrush; // eax
  int v6; // edx
  tagRECT fill; // [esp+Ch] [ebp-18h] BYREF
  HBITMAP__ *bmMemory; // [esp+1Ch] [ebp-8h]
  HBITMAP__ *bmOld; // [esp+20h] [ebp-4h]
  HBRUSH__ *br; // [esp+30h] [ebp+Ch]

  CompatibleDC = CreateCompatibleDC(hdc);
  bmMemory = CreateCompatibleBitmap(
               hdc,
               cx: *((_DWORD *)clientRect + 2) - *(_DWORD *)clientRect,
               cy: *((_DWORD *)clientRect + 3) - *((_DWORD *)clientRect + 1));
  bmOld = (HBITMAP__ *)SelectObject(hdc: CompatibleDC, h: bmMemory);
  SolidBrush = CreateSolidBrush(color: g_backgroundColor);
  v6 = *((_DWORD *)clientRect + 3) - *((_DWORD *)clientRect + 1);
  fill.top = 0;
  fill.left = 0;
  br = SolidBrush;
  fill.right = *((_DWORD *)clientRect + 2) - *(_DWORD *)clientRect;
  fill.bottom = v6;
  FillRect(hDC: CompatibleDC, lprc: &fill, hbr: SolidBrush);
  DeleteObject(ho: br);
  drawFunc(a1: CompatibleDC, a2: &fill);
  BitBlt(
    hdc,
    x: *(_DWORD *)clientRect,
    y: *((_DWORD *)clientRect + 1),
    cx: *((_DWORD *)clientRect + 2) - *(_DWORD *)clientRect,
    cy: *((_DWORD *)clientRect + 3) - *((_DWORD *)clientRect + 1),
    hdcSrc: CompatibleDC,
    x1: 0,
    y1: 0,
    rop: 0xCC0020u);
  SelectObject(hdc: CompatibleDC, h: bmOld);
  DeleteObject(ho: bmMemory);
  DeleteObject(ho: CompatibleDC);
}
