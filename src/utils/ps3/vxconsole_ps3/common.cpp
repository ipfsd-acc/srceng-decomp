// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/common.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00404470
// Name: enum vprofState_e VProf_GetState(void)
// Source: json
//------------------------------------------------------------------------------
vprofState_e __cdecl VProf_GetState()
{
  return g_vprof_state;
}

//------------------------------------------------------------------------------
// Address: 0x00404480
// Name: char __near * GetPerfmonFileserverPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetPerfmonFileserverPath()
{
  return g_FileserverPerfmonLogFileName;
}

//------------------------------------------------------------------------------
// Address: 0x00404490
// Name: bool MakePerfmonLogFilePath(char restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MakePerfmonLogFilePath(char *outPath, int outLen)
{
  tm *v2; // eax
  __int64 ltime; // [esp+0h] [ebp-8h] BYREF

  _time64(timeptr: &ltime);
  v2 = _localtime64(ptime: &ltime);
  if ( g_ps3TargetName[0] != 0 )
  {
    V_snprintf(
      pDest: outPath,
      maxLen: outLen,
      pFormat: "%s\\perfmon\\%s\\%2.2d_%2.2d_%2.2d__%2.2d_%2.2d_%2.2d\\",
      g_installPath,
      g_ps3TargetName,
      v2->tm_mon + 1,
      v2->tm_mday,
      v2->tm_year % 100,
      v2->tm_hour,
      v2->tm_min,
      v2->tm_sec);
    return 1;
  }
  else
  {
    if ( outLen > 0 )
      *outPath = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404510
// Name: struct _iobuf __near * GetPerfmonFileserverLogFile(void)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl GetPerfmonFileserverLogFile()
{
  char szLogPath[260]; // [esp+0h] [ebp-208h] BYREF
  char szLogName[260]; // [esp+104h] [ebp-104h] BYREF

  if ( g_FileserverPerfmonLogFileName[0] == 0 )
    return nullptr;
  V_snprintf(pDest: szLogName, maxLen: 260, pFormat: "perfmon_%s.log", g_ps3TargetName);
  V_ComposeFileName(path: g_FileserverPerfmonLogFileName, filename: szLogName, dest: szLogPath, destSize: 260);
  return fopen(file: szLogPath, mode: "at+");
}

//------------------------------------------------------------------------------
// Address: 0x00404580
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
