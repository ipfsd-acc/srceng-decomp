// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/local_cmds.cpp
// Functions: 21
// ============================================================

#include "utils\ps3\vxconsole_ps3\local_cmds.h"

//------------------------------------------------------------------------------
// Address: 0x00407160
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
// Address: 0x004071C0
// Name: int lc_memory(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_memory()
{
  HRESULT ProcessMemoryStatistics; // eax
  SNPS3UserMemoryStats memstat; // [esp+50h] [ebp-20h] BYREF
  unsigned int uCreatedSharedMemorySize; // [esp+6Ch] [ebp-4h]

  ProcessMemoryStatistics = CPS3TargetConnection::GetProcessMemoryStatistics(
                              this: &g_PS3CurrentTargetConn,
                              pMemStats: &memstat);
  if ( ProcessMemoryStatistics < 0 )
  {
    DmAPI_DisplayError(message: "Could not receive memory info for process %d:\t%s\n", hr: ProcessMemoryStatistics);
  }
  else
  {
    uCreatedSharedMemorySize = memstat.uCreatedSharedMemorySize;
    ConsoleWindowPrintf(
      rgb: 0,
      strFormat: "Memory statistics:\n"
      "\tCreatedSharedMemorySize: %d\t(%.1f mb)\n"
      "\tAttachedSharedMemorySize: %d\t(%.1f mb)\n"
      "\tProcessLocalMemorySize: %d\t(%.1f mb)\n"
      "\tProcessLocalTextSize: %d\t(%.1f mb)\n"
      "\tPRXTextSize: %d\t(%.1f mb)\n"
      "\tPRXDataSize: %d\t(%.1f mb)\n"
      "\tMiscMemorySize: %d\t(%.1f mb)\n",
      memstat.uCreatedSharedMemorySize,
      0.00000095367431640625 * (double)memstat.uCreatedSharedMemorySize,
      memstat.uAttachedSharedMemorySize,
      (double)memstat.uAttachedSharedMemorySize * 0.00000095367431640625,
      memstat.uProcessLocalMemorySize,
      (double)memstat.uProcessLocalMemorySize * 0.00000095367431640625,
      memstat.uProcessLocalTextSize,
      (double)memstat.uProcessLocalTextSize * 0.00000095367431640625,
      memstat.uPRXTextSize,
      (double)memstat.uPRXTextSize * 0.00000095367431640625,
      memstat.uPRXDataSize,
      (double)memstat.uPRXDataSize * 0.00000095367431640625,
      memstat.uMiscMemorySize,
      (double)memstat.uMiscMemorySize * 0.00000095367431640625);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004072F0
// Name: int lc_modules(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_modules()
{
  ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "*modules not yet implemented for PS3.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407310
// Name: int lc_threads(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_threads()
{
  ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "*threads not yet implemented for PS3.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407330
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
    if ( g_connectionState == kCONNECTEDAPP )
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
  if ( g_connectionState != kCONNECTEDAPP )
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
// Address: 0x004074F0
// Name: int lc_cls(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_cls()
{
  SetWindowTextA(hWnd: g_hwndOutputWindow, lpString: &str);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407510
// Name: int lc_crashdump(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_crashdump()
{
  CPS3TargetConnection::CrashDump(this: &g_PS3CurrentTargetConn);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407520
// Name: int lc_quit(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_quit()
{
  PostMessageA(hWnd: g_hDlgMain, Msg: 0x10u, wParam: 0, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407540
// Name: int lc_procstop(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lc_procstop()
{
  return CPS3TargetConnection::HaltGameProcess(this: &g_PS3CurrentTargetConn, bStop: true) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407560
// Name: int lc_procgo(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lc_procgo()
{
  return CPS3TargetConnection::HaltGameProcess(this: &g_PS3CurrentTargetConn, bStop: false) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407580
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
// Address: 0x004075C0
// Name: int lc_run(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_run(int argc, const char **argv)
{
  char *v2; // ecx
  HRESULT v4; // eax
  char *args[2]; // [esp+0h] [ebp-8h] BYREF

  if ( argc != 0 )
  {
    v4 = CPS3TargetConnection::RebootELF(
           this: &g_PS3CurrentTargetConn,
           pszFileName: argv[1],
           argc: argc - 1,
           argv: argv + 1);
    if ( v4 >= 0 )
    {
      return 1;
    }
    else
    {
      DmAPI_DisplayError(message: "RebootELF() failure", hr: v4);
      return 0;
    }
  }
  else
  {
    v2 = (char *)*argv;
    args[0] = "*help";
    args[1] = v2;
    return lc_help(argc: 2, argv: args);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407630
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
    v4 = CPS3TargetConnection::RebootCold(this: &g_PS3CurrentTargetConn);
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
// Address: 0x00407700
// Name: int lc_screenshot(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_screenshot(int argc, char **argv)
{
  int v2; // eax
  char v3; // cl
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  IScreenshotArrivalCallback *v9; // eax
  IScreenshotArrivalCallback *v10; // esi
  HRESULT v11; // eax
  char filepath[260]; // [esp+Ch] [ebp-240h] BYREF
  char filename[260]; // [esp+110h] [ebp-13Ch] BYREF
  _stat64i32 dummyStat; // [esp+214h] [ebp-38h] BYREF
  char *args[2]; // [esp+244h] [ebp-8h] BYREF

  if ( argc > 1 )
  {
    if ( argc != 2 )
    {
      v8 = *argv;
      args[0] = "*help";
      args[1] = v8;
      lc_help(argc: 2, argv: args);
      return 0;
    }
    v5 = argv[1];
    v6 = (char *)(filename - v5);
    do
    {
      v7 = *v5;
      v5[(_DWORD)v6] = *v5;
      ++v5;
    }
    while ( v7 != 0 );
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
  if ( g_pOnScreenshotArrivalDoThis != nullptr )
  {
    if ( !IScreenshotArrivalCallback::IsStale(this: g_pOnScreenshotArrivalDoThis, timeout: 10.0) )
    {
      ConsoleWindowPrintf(
        rgb: 0,
        strFormat: "A screenshot is still pending; please wait.\nType vx_screenshot to force a retry now.\n");
      return 0;
    }
    free(pMem: g_pOnScreenshotArrivalDoThis);
    v9 = (IScreenshotArrivalCallback *)operator new(nSize: 0x20u);
    v10 = v9;
    if ( v9 != nullptr )
      goto LABEL_15;
  }
  else
  {
    v9 = (IScreenshotArrivalCallback *)operator new(nSize: 0x20u);
    v10 = v9;
    if ( v9 != nullptr )
    {
LABEL_15:
      IScreenshotArrivalCallback::IScreenshotArrivalCallback(this: v9);
      v10->__vftable = (IScreenshotArrivalCallback_vtbl *)&CScreenshotWriteToBMP::`vftable';
      CUtlString::CUtlString(this: (CUtlString *)&v10[1], pString: filename);
      g_pOnScreenshotArrivalDoThis = v10;
      goto LABEL_18;
    }
  }
  g_pOnScreenshotArrivalDoThis = nullptr;
LABEL_18:
  v11 = DmAPI_SendCommand(strCommand: "XCMD!vx_screenshot", wait: false);
  if ( v11 >= 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Screenshot saved to %s\n", filename);
    ++shot;
    return 1;
  }
  else
  {
    DmAPI_DisplayError(message: "lc_screenshot(): failed to send 'vx_screenshot'", hr: v11);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407930
// Name: public: virtual void CScreenshotWriteToBMP::OnScreenshot(struct VXPS3Screenshot_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenshotWriteToBMP::OnScreenshot(CScreenshotWriteToBMP *this, const VXPS3Screenshot_t *pScreenshot)
{
  unsigned int uColorFmt; // eax
  char *m_pMemory; // eax
  unsigned int v5; // ebx
  signed int v6; // eax
  unsigned int uPitch; // esi
  unsigned int v8; // eax
  char *v9; // eax
  char *v10; // ecx
  unsigned int v11; // esi
  char v12; // dl
  char *v13; // eax
  unsigned int v14; // esi
  char *v15; // ecx
  char v16; // dl
  char v17; // bl
  unsigned int uHeight; // edx
  unsigned int uWidth; // ecx
  CUtlString *v20; // edi
  const char *v21; // eax
  _iobuf *v22; // eax
  _iobuf *v23; // esi
  char *v24; // ebx
  const char *v25; // eax
  unsigned int v26; // [esp-30h] [ebp-490h]
  char complaint[1024]; // [esp+4h] [ebp-45Ch] BYREF
  tagBITMAPFILEHEADER bmpFileHdr; // [esp+404h] [ebp-5Ch] BYREF
  tagBITMAPINFO bmpInfo; // [esp+414h] [ebp-4Ch] BYREF
  CScreenshotWriteToBMP *v30; // [esp+440h] [ebp-20h]
  CUtlMemory<char,int> bgraBits; // [esp+444h] [ebp-1Ch]
  unsigned int row; // [esp+450h] [ebp-10h]
  unsigned int nFrameSizeInBytes; // [esp+454h] [ebp-Ch]
  unsigned int nWidthBytes; // [esp+458h] [ebp-8h]
  unsigned __int8 g; // [esp+45Eh] [ebp-2h]
  unsigned __int8 b; // [esp+45Fh] [ebp-1h]
  char r_3; // [esp+46Bh] [ebp+Bh]
  char r_3a; // [esp+46Bh] [ebp+Bh]

  uColorFmt = pScreenshot->uColorFmt;
  v30 = this;
  if ( uColorFmt != 0 )
  {
    _Error(a1: "Unexpected non-ARGB bitmap format %d\n", uColorFmt);
  }
  else
  {
    m_pMemory = pScreenshot->m_Data.m_pMemory;
    v5 = 4 * pScreenshot->uHeight * pScreenshot->uWidth;
    nFrameSizeInBytes = v5;
    bgraBits.m_pMemory = nullptr;
    if ( m_pMemory != nullptr )
    {
      v6 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: m_pMemory);
      if ( v6 > 0 )
        bgraBits.m_pMemory = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v6);
    }
    uPitch = pScreenshot->uPitch;
    v8 = 4 * pScreenshot->uWidth;
    nWidthBytes = v8;
    if ( v8 >= uPitch )
      nWidthBytes = uPitch;
    if ( uPitch < v8 || (nWidthBytes & 3) != 0 )
    {
      _snprintf(
        string: complaint,
        count: 0x400u,
        format: "Game sent a screenshot with strange byte dimensions\n(%d width, %d pitch)\nIt may look corrupt.",
        v8,
        uPitch);
      MessageBoxA(hWnd: nullptr, lpText: complaint, lpCaption: "Funny Looking Screenshot", uType: 0x30u);
    }
    if ( 4 * pScreenshot->uWidth >= pScreenshot->uPitch )
    {
      if ( v5 != 0 )
      {
        v13 = bgraBits.m_pMemory + 2;
        v14 = -2 - (unsigned int)bgraBits.m_pMemory;
        do
        {
          v15 = &g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory[(unsigned int)&v13[v14]];
          v13 += 4;
          v16 = *v15;
          r_3a = v15[2];
          v17 = v15[3];
          *(v13 - 6) = v15[1];
          *(v13 - 3) = v16;
          *(v13 - 5) = r_3a;
          *(v13 - 4) = v17;
        }
        while ( (unsigned int)&v13[v14] < nFrameSizeInBytes );
        v5 = nFrameSizeInBytes;
      }
    }
    else
    {
      v9 = g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory;
      v10 = bgraBits.m_pMemory;
      for ( row = 0; row < pScreenshot->uHeight; ++row )
      {
        if ( nWidthBytes != 0 )
        {
          v11 = ((nWidthBytes - 1) >> 2) + 1;
          do
          {
            v12 = *v9;
            r_3 = v9[1];
            g = v9[2];
            b = v9[3];
            *v10 = r_3;
            v10[1] = g;
            v10[2] = b;
            v10[3] = v12;
            v9 += 4;
            v10 += 4;
            --v11;
          }
          while ( v11 != 0 );
          v5 = nFrameSizeInBytes;
        }
        v9 += pScreenshot->uPitch - nWidthBytes;
      }
    }
    uHeight = pScreenshot->uHeight;
    uWidth = pScreenshot->uWidth;
    v20 = (CUtlString *)v30;
    bmpFileHdr.bfType = 19778;
    bmpInfo.bmiHeader.biHeight = -uHeight;
    bmpInfo.bmiHeader.biWidth = uWidth;
    bmpInfo.bmiHeader.biSize = 40;
    *(_DWORD *)&bmpInfo.bmiHeader.biPlanes = 2097153;
    bmpInfo.bmiHeader.biCompression = 0;
    bmpInfo.bmiHeader.biSizeImage = v5;
    bmpInfo.bmiHeader.biXPelsPerMeter = 1024;
    bmpInfo.bmiHeader.biYPelsPerMeter = 1024;
    memset(&bmpInfo.bmiHeader.biClrUsed, 0, 12);
    bmpFileHdr.bfSize = v5 + 58;
    bmpFileHdr.bfOffBits = 58;
    v21 = CUtlString::Get(this: &v30->m_Filename);
    v22 = fopen(file: v21, mode: "wb");
    v23 = v22;
    if ( v22 != nullptr )
    {
      fwrite(buffer: &bmpFileHdr, size: 0xEu, count: 1u, stream: v22);
      fwrite(buffer: &bmpInfo, size: 0x2Cu, count: 1u, stream: v23);
      v26 = v5;
      v24 = bgraBits.m_pMemory;
      fwrite(buffer: bgraBits.m_pMemory, size: 1u, count: v26, stream: v23);
    }
    else
    {
      v24 = bgraBits.m_pMemory;
    }
    fclose(stream: v23);
    v25 = CUtlString::Get(this: v20 + 1);
    ConsoleWindowPrintf(rgb: 0, strFormat: "Screenshot saved to %s\n", v25);
    if ( v24 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407C10
// Name: int lc_disconnect(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_disconnect()
{
  CPS3TargetConnection::Disconnect(this: &g_PS3CurrentTargetConn, bDisconnectTargetManagerToo: false);
  if ( g_connectionState == kCONNECTEDAPP )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Closing Session.\n");
    DmAPI_SendCommand(strCommand: "XCMD!__disconnect__", wait: false);
    CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::RemoveAll(this: &g_PS3CurrentTargetConn.m_TTYHandlerFuncs);
    CPS3TargetConnection::PurgeDMEmulatingNotifications(this: &g_PS3CurrentTargetConn);
    g_connectionState = kCONNECTEDTARGET;
LABEL_4:
    ConsoleWindowPrintf(rgb: 0, strFormat: "Closing Connection.\n");
    CPS3TargetConnection::Disconnect(this: &g_PS3CurrentTargetConn, bDisconnectTargetManagerToo: false);
    SetEvent(hEvent: g_hCommandReadyEvent);
    g_connectionState = kDISCONNECTED;
    goto LABEL_5;
  }
  if ( g_connectionState == kCONNECTEDTARGET )
    goto LABEL_4;
LABEL_5:
  SetConnectionIcon(icon: 1);
  g_connectCount = 0;
  Remote_DeleteCommands();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407CC0
// Name: int lc_dir(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_dir(int argc, char **argv)
{
  int v2; // edi
  char *v3; // ecx
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  int v8; // eax
  int v9; // eax
  char *v10; // edi
  char v11; // al
  int v12; // esi
  char *v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // ebx
  const char *v16; // esi
  char dateTimeString[256]; // [esp+8h] [ebp-65Ch] BYREF
  char targetName[260]; // [esp+108h] [ebp-55Ch] BYREF
  _TIME_ZONE_INFORMATION tzInfo; // [esp+20Ch] [ebp-458h] BYREF
  char filePath[260]; // [esp+2B8h] [ebp-3ACh] BYREF
  char newPath[260]; // [esp+3BCh] [ebp-2A8h] BYREF
  char fileName[260]; // [esp+4C0h] [ebp-1A4h] BYREF
  char sizeString[64]; // [esp+5C4h] [ebp-A0h] BYREF
  _SYSTEMTIME systemTime; // [esp+604h] [ebp-60h] BYREF
  _SYSTEMTIME localTime; // [esp+614h] [ebp-50h] BYREF
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > fileInfoList; // [esp+624h] [ebp-40h] BYREF
  int i; // [esp+64Ch] [ebp-18h]
  int nPass; // [esp+650h] [ebp-14h]
  int v29; // [esp+654h] [ebp-10h]
  char *args[2]; // [esp+658h] [ebp-Ch] BYREF
  int numDirs; // [esp+660h] [ebp-4h]
  int numFiles; // [esp+66Ch] [ebp+8h]

  v2 = 0;
  memset(&fileInfoList, 0, 12);
  fileInfoList.m_LastAlloc.index = -1;
  memset(&fileInfoList.m_Head, 255, 12);
  fileInfoList.m_ElementCount = 0;
  fileInfoList.m_NumAlloced = 0;
  fileInfoList.m_pElements = nullptr;
  if ( argc < 2 )
  {
    v3 = *argv;
    args[0] = "*dir";
    args[1] = v3;
    lc_help(argc: 2, argv: args);
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileInfoList);
    if ( fileInfoList.m_Memory.m_nGrowSize >= 0 && fileInfoList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileInfoList.m_Memory.m_pMemory);
    return 0;
  }
  v5 = argv[1];
  v6 = (char *)(newPath - v5);
  do
  {
    v7 = *v5;
    v5[(_DWORD)v6] = *v5;
    ++v5;
  }
  while ( v7 != 0 );
  Sys_StripFilename(inpath: newPath, outpath: filePath, outPathLen: 260);
  Sys_StripPath(inpath: newPath, outpath: fileName, outPathLen: 260);
  if ( fileName[0] != 0 )
  {
    strstr(str1: (unsigned __int8 *)fileName, str2: "*");
    if ( v8 == 0 )
    {
      strstr(str1: (unsigned __int8 *)fileName, str2: "?");
      if ( v9 == 0 )
      {
        v10 = &filePath[259];
        do
          v11 = *++v10;
        while ( v11 != 0 );
        strcpy(v10, "\\");
        Sys_StripFilename(inpath: newPath, outpath: filePath, outPathLen: 260);
        Sys_StripPath(inpath: newPath, outpath: fileName, outPathLen: 260);
        v2 = 0;
      }
    }
  }
  LOBYTE(numDirs) = 0;
  if ( argc >= 3 )
    LOBYTE(numDirs) = _V_stricmp(s1: argv[2], s2: "/s") == 0;
  if ( GetTargetFileList_r(targetPath: filePath, recurse: numDirs, attributes: 145, level: 0, pFileList: &fileInfoList) == 0 )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bad Target Path '%s'\n", filePath);
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileInfoList);
    if ( fileInfoList.m_Memory.m_nGrowSize >= 0 && fileInfoList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileInfoList.m_Memory.m_pMemory);
    return 0;
  }
  ConsoleWindowPrintf(rgb: 0, strFormat: "\nDirectory of %s\n\n", argv[1]);
  GetTimeZoneInformation(lpTimeZoneInformation: &tzInfo);
  numFiles = 0;
  numDirs = 0;
  *(_QWORD *)args = 0;
  nPass = 0;
  do
  {
    v12 = 0;
    i = 0;
    if ( (int)fileInfoList.m_ElementCount > 0 )
    {
      v29 = 0;
      do
      {
        v13 = (char *)fileInfoList.m_Memory.m_pMemory + v12;
        if ( v2 != 0 )
        {
          if ( *(_DWORD *)v13 != 1 )
          {
LABEL_28:
            Sys_StripPath(inpath: v13 + 128, outpath: targetName, outPathLen: 260);
            if ( fileName[0] == 0
              || Sys_IsWildcardMatch(wildcardString: fileName, stringToCheck: targetName, caseSensitive: false) )
            {
              FileTimeToSystemTime(lpFileTime: (const tm *)(v13 + 44), lpSystemTime: &systemTime);
              SystemTimeToTzSpecificLocalTime(
                lpTimeZoneInformation: &tzInfo,
                lpUniversalTime: &systemTime,
                lpLocalTime: &localTime);
              SystemTimeToString(systemTime: &localTime, buffer: dateTimeString, bufferSize: 0x100u);
              v14 = *((_DWORD *)v13 + 30);
              v15 = *((_DWORD *)v13 + 31);
              if ( *(_DWORD *)v13 == 1 )
              {
                ++numDirs;
                v16 = "<DIR>";
                sprintf(string: sizeString, format: "%s", "         ");
              }
              else
              {
                ++numFiles;
                v16 = "     ";
                Sys_NumberToCommaString(number: __SPAIR64__(v15, v14), buffer: sizeString, bufferSize: 64);
                *(_QWORD *)args += __PAIR64__(v15, v14);
              }
              ConsoleWindowPrintf(rgb: 0, strFormat: "%s  %s %12s %s\n", dateTimeString, v16, sizeString, targetName);
              v2 = nPass;
            }
          }
        }
        else if ( *(_DWORD *)v13 == 1 )
        {
          goto LABEL_28;
        }
        v12 = v29 + 400;
        ++i;
        v29 += 400;
      }
      while ( i < (int)fileInfoList.m_ElementCount );
    }
    nPass = ++v2;
  }
  while ( v2 < 2 );
  Sys_NumberToCommaString(number: *(__int64 *)args, buffer: sizeString, bufferSize: 64);
  ConsoleWindowPrintf(rgb: 0, strFormat: "%9s %d File(s) %s bytes\n", " ", numFiles, sizeString);
  ConsoleWindowPrintf(rgb: 0, strFormat: "%9s %d Dir(s)\n", " ", numDirs);
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileInfoList);
  if ( fileInfoList.m_Memory.m_nGrowSize >= 0 && fileInfoList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileInfoList.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004080A0
// Name: int lc_del(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_del(int argc, char **argv)
{
  char *v3; // ecx
  int v5; // esi
  int v6; // ebx
  int v7; // edi
  int v8; // esi
  char targetName[260]; // [esp+8h] [ebp-340h] BYREF
  char fileName[260]; // [esp+10Ch] [ebp-23Ch] BYREF
  char filePath[260]; // [esp+210h] [ebp-138h] BYREF
  char *args[2]; // [esp+314h] [ebp-34h] BYREF
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > fileInfoList; // [esp+31Ch] [ebp-2Ch] BYREF
  int numErrors; // [esp+344h] [ebp-4h]
  char bQuiet_3; // [esp+353h] [ebp+Bh]

  memset(&fileInfoList, 0, 12);
  fileInfoList.m_LastAlloc.index = -1;
  memset(&fileInfoList.m_Head, 255, 12);
  fileInfoList.m_ElementCount = 0;
  fileInfoList.m_NumAlloced = 0;
  fileInfoList.m_pElements = nullptr;
  if ( argc >= 2 )
  {
    Sys_StripFilename(inpath: argv[1], outpath: filePath, outPathLen: 260);
    Sys_StripPath(inpath: argv[1], outpath: fileName, outPathLen: 260);
    bQuiet_3 = 0;
    LOBYTE(numErrors) = 0;
    if ( argc >= 3 )
    {
      v5 = 2;
      do
      {
        if ( _V_stricmp(s1: argv[v5], s2: "/s") != 0 )
        {
          if ( _V_stricmp(s1: argv[v5], s2: "/q") == 0 )
            bQuiet_3 = 1;
        }
        else
        {
          LOBYTE(numErrors) = 1;
        }
        ++v5;
      }
      while ( v5 < argc );
    }
    if ( GetTargetFileList_r(
           targetPath: filePath,
           recurse: numErrors,
           attributes: 145,
           level: 0,
           pFileList: &fileInfoList) != 0 )
    {
      v6 = 0;
      v7 = 0;
      numErrors = 0;
      if ( (int)fileInfoList.m_ElementCount <= 0 )
        goto LABEL_30;
      v8 = 0;
      do
      {
        Sys_StripPath(inpath: fileInfoList.m_Memory.m_pMemory[v8].m_Element.Name, outpath: targetName, outPathLen: 260);
        if ( fileName[0] == 0
          || Sys_IsWildcardMatch(wildcardString: fileName, stringToCheck: targetName, caseSensitive: false) )
        {
          LOBYTE(args[1]) = fileInfoList.m_Memory.m_pMemory[v8].m_Element.Type == 1;
          if ( CPS3TargetConnection::DeleteFileA(
                 this: &g_PS3CurrentTargetConn,
                 pszFileName: fileInfoList.m_Memory.m_pMemory[v8].m_Element.Name,
                 fIsDirectory: (bool)args[1]) != 0 )
          {
            if ( bQuiet_3 == 0 )
              ConsoleWindowPrintf(
                rgb: 0xFFu,
                strFormat: "Error Deleting '%s'\n",
                fileInfoList.m_Memory.m_pMemory[v8].m_Element.Name);
            ++numErrors;
          }
          else
          {
            ConsoleWindowPrintf(rgb: 0, strFormat: "Deleted '%s'\n", fileInfoList.m_Memory.m_pMemory[v8].m_Element.Name);
            ++v7;
          }
        }
        ++v6;
        ++v8;
      }
      while ( v6 < (int)fileInfoList.m_ElementCount );
      if ( v7 != 0 || numErrors != 0 )
        ConsoleWindowPrintf(rgb: 0, strFormat: "%d files deleted.\n", v7);
      else
LABEL_30:
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "No Files found for '%s'\n", argv[1]);
      CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileInfoList);
      if ( fileInfoList.m_Memory.m_nGrowSize >= 0 && fileInfoList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileInfoList.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Bad Target Path '%s'\n", filePath);
      CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileInfoList);
      if ( fileInfoList.m_Memory.m_nGrowSize >= 0 && fileInfoList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileInfoList.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    v3 = *argv;
    args[0] = "*del";
    args[1] = v3;
    lc_help(argc: 2, argv: args);
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileInfoList);
    if ( fileInfoList.m_Memory.m_nGrowSize >= 0 && fileInfoList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileInfoList.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408340
// Name: int lc_connect(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_connect(int argc, char **argv)
{
  int result; // eax
  int InternalTargetIndexForHandle; // eax
  CPS3TargetList::TargetInfo_t *v4; // eax
  const char *v5; // eax
  HRESULT v6; // esi
  unsigned int DebugIPAddr; // ebx
  const char *v8; // eax
  char complaint[1024]; // [esp+0h] [ebp-50Ch] BYREF
  char message[256]; // [esp+400h] [ebp-10Ch] BYREF
  int err; // [esp+500h] [ebp-Ch] BYREF
  int targetIndex; // [esp+504h] [ebp-8h] BYREF
  unsigned int addr; // [esp+508h] [ebp-4h] BYREF

  if ( g_connectionState != kCONNECTEDTARGET && g_connectionState != kCONNECTEDAPP || (result = lc_disconnect()) != 0 )
  {
    targetIndex = -1;
    if ( argc >= 1 && **argv != 0 )
    {
      targetIndex = CPS3TargetList::FindTargetByName(this: &g_PS3TargetList, name: *argv);
      if ( targetIndex == -1 )
      {
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "I see no %s here.\n", *argv);
        return 0;
      }
    }
    else
    {
      while ( 1 )
      {
        CPS3TargetList::EnumerateTargets(this: &g_PS3TargetList);
        err = -1;
        targetIndex = CPS3TargetList::ShowTargetSelectionDialog(this: &g_PS3TargetList, errorValue: &err);
        if ( CPS3TargetList::GetInternalTargetIndexForHandle(this: &g_PS3TargetList, targ: &targetIndex) != -1 )
          break;
        if ( err == -20 )
          return 0;
        if ( err == -19 )
        {
          V_snprintf(
            pDest: complaint,
            maxLen: 1024,
            pFormat: "Target Manager says that it doesn't know about any devkits.\n");
        }
        else
        {
          addr = (unsigned int)"<unknown>";
          SNPS3TranslateError(a1: err, a2: (int)&addr);
          V_snprintf(
            pDest: complaint,
            maxLen: 1024,
            pFormat: "Failed to open target list because of Sony error: %s\n",
            (const char *)addr);
        }
        if ( MessageBoxA(hWnd: nullptr, lpText: complaint, lpCaption: "Failed to open target list", uType: 0x35u) != 4 )
          goto LABEL_19;
        CPS3TargetConnection::EmergencyReset(this: &g_PS3CurrentTargetConn, bReconnectAfter: false);
      }
      addr = targetIndex;
      InternalTargetIndexForHandle = CPS3TargetList::GetInternalTargetIndexForHandle(
                                       this: &g_PS3TargetList,
                                       targ: (const int *)&addr);
      if ( InternalTargetIndexForHandle == -1 )
        v4 = &CPS3TargetList::s_theInvalidTargetInfo;
      else
        v4 = &g_PS3TargetList.m_Targets.m_Memory.m_pMemory[InternalTargetIndexForHandle];
      v5 = CUtlString::Get(this: &v4->szName);
      V_strncpy(pDest: g_ps3TargetName, pSrc: v5, maxLen: 64);
    }
LABEL_19:
    v6 = CPS3TargetConnection::ConnectTo(this: &g_PS3CurrentTargetConn, idx: targetIndex);
    if ( v6 == -5 )
    {
      CPS3TargetConnection::EmergencyReset(this: &g_PS3CurrentTargetConn, bReconnectAfter: false);
      v6 = CPS3TargetConnection::ConnectTo(this: &g_PS3CurrentTargetConn, idx: targetIndex);
    }
    if ( v6 >= 0 )
    {
      g_connectionState = kCONNECTEDTARGET;
      Sys_SetRegistryString(keyName: "ps3Name", value: g_ps3TargetName);
      SetMainWindowTitle();
      g_connectFailure = 0;
      if ( g_connectCount == 0 )
      {
        DebugIPAddr = CPS3TargetConnection::GetDebugIPAddr(this: &g_PS3CurrentTargetConn);
        addr = DebugIPAddr;
        if ( g_PS3CurrentTargetConn.m_nSNHandle < 0 )
          v8 = &str;
        else
          v8 = CUtlString::Get(this: &g_PS3CurrentTargetConn.m_targetInfo.szName);
        ConsoleWindowPrintf(
          rgb: 0,
          strFormat: "Connected To: '%s'(%d.%d.%d.%d)\n",
          v8,
          HIBYTE(addr),
          BYTE2(addr),
          BYTE1(DebugIPAddr),
          (unsigned __int8)DebugIPAddr);
      }
      ++g_connectCount;
      SetConnectionIcon(icon: 2);
      return lc_listen(argc: 0, argv: nullptr);
    }
    else
    {
      sprintf(string: message, format: "Could not connect to %s\n", g_ps3TargetName);
      DmAPI_DisplayError(message, hr: v6);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004085C0
// Name: int lc_listen(int,char __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lc_listen()
{
  int result; // eax
  int v1; // esi
  HRESULT v2; // eax
  char cmdStr[256]; // [esp+0h] [ebp-104h] BYREF
  char *args[1]; // [esp+100h] [ebp-4h] BYREF

  if ( g_connectionState == kCONNECTEDTARGET
    || g_connectionState == kCONNECTEDAPP
    || (args[0] = g_ps3TargetName, (result = lc_connect(argc: 1, argv: args)) != 0) )
  {
    v1 = 0;
    v2 = CPS3TargetConnection::RegisterNotifyDebugStrings(this: &g_PS3CurrentTargetConn, func: Remote_NotifyPrintFunc);
    if ( v2 < 0 )
    {
      DmAPI_DisplayError(message: "lc_session(): DmNotify() failure", hr: v2);
LABEL_6:
      CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::RemoveAll(this: &g_PS3CurrentTargetConn.m_TTYHandlerFuncs);
      CPS3TargetConnection::PurgeDMEmulatingNotifications(this: &g_PS3CurrentTargetConn);
      return v1;
    }
    CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(
      this: &g_PS3CurrentTargetConn,
      pszPrefix: "XCMD",
      func: Remote_NotifyCommandFunc);
    CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(
      this: &g_PS3CurrentTargetConn,
      pszPrefix: "XPRT",
      func: Remote_NotifyPrintFunc);
    CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(
      this: &g_PS3CurrentTargetConn,
      pszPrefix: "XACK",
      func: Remote_NotifyPrintIffVerboseFunc);
    CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(
      this: &g_PS3CurrentTargetConn,
      pszPrefix: "XBCT",
      func: (unsigned int (__stdcall *)(const char *, unsigned int))Remote_NotifyBinaryContinuedMessage);
    CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(
      this: &g_PS3CurrentTargetConn,
      pszPrefix: "XPRF",
      func: Remote_NotifyPerfFunc);
    sprintf(string: cmdStr, format: "%s %d", "XCMD!__connect__", 4097);
    if ( DmAPI_SendCommand(strCommand: cmdStr, wait: true) < 0 )
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Couldn't Find Application\n");
      goto LABEL_6;
    }
    v1 = 1;
    g_connectionState = kCONNECTEDAPP;
    g_connectedTime = Sys_GetSystemTime();
    SetConnectionIcon(icon: 4);
    if ( g_bPlayTestMode != 0 )
      InitiateLoggingPlaytestToFileserver();
    if ( g_clsOnConnect == 0 )
      return v1;
    if ( g_bPlayTestMode != 0 )
      ConsoleWindowPrintf(rgb: 0xFF000000, strFormat: "\n******** CONNECTION ********\n");
    SetWindowTextA(hWnd: g_hwndOutputWindow, lpString: &str);
    CpuProfile_Clear();
    TimeStampLog_Clear();
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408790
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
