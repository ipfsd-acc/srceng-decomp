// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/crash_dumps.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00410E00
// Name: void CrashDumps_Publish(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrashDumps_Publish()
{
  CProgress *v0; // ebx
  fileNode_s *v1; // eax
  int i; // esi
  CProgress *v3; // eax
  CProgress *v4; // eax
  CProgress *v5; // edi
  fileNode_s *v6; // esi
  HANDLE FileA; // eax
  void *v8; // ebx
  char statusBuff1[260]; // [esp+14h] [ebp-5F0h] BYREF
  char szTargetPath[260]; // [esp+118h] [ebp-4ECh] BYREF
  char statusBuff2[260]; // [esp+21Ch] [ebp-3E8h] BYREF
  char szDumpPath[260]; // [esp+320h] [ebp-2E4h] BYREF
  _TIME_ZONE_INFORMATION tzInfo; // [esp+424h] [ebp-1E0h] BYREF
  char szFinalTargetPath[260]; // [esp+4D0h] [ebp-134h] BYREF
  _SYSTEMTIME fatxSystemTime; // [esp+5D4h] [ebp-30h] BYREF
  _SYSTEMTIME fatxLocalTime; // [esp+5E8h] [ebp-1Ch] BYREF
  int numDumps; // [esp+5F8h] [ebp-Ch]
  fileNode_s *pFileList; // [esp+5FCh] [ebp-8h] BYREF
  CProgress *pProgress; // [esp+600h] [ebp-4h]

  v0 = nullptr;
  pFileList = nullptr;
  if ( GetTargetFileList_r(targetPath: "e:\\dumps", recurse: true, attributes: 129, level: 0, &pFileList) )
  {
    v1 = pFileList;
    for ( i = 0; v1 != nullptr; ++i )
      v1 = v1->nextPtr;
    ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
    if ( i != 0 )
    {
      pProgress = nullptr;
      if ( i >= 2 )
      {
        v3 = (CProgress *)operator new(nSize: 0x24u);
        if ( v3 != nullptr )
        {
          v4 = CProgress::CProgress(this: v3);
          pProgress = v4;
          if ( v4 != nullptr )
          {
            v5 = v4;
            CProgress::Open(this: v4, title: "Publishing Crash Dumps...", canCancel: false, bHasMeter: true);
            CProgress::SetMeter(this: v5, currentPos: 0, range: i);
            v0 = v5;
          }
          else
          {
            v0 = nullptr;
          }
        }
        else
        {
          pProgress = nullptr;
        }
      }
      if ( g_installPath[0] == 0 )
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Installation depot not set in Configuration!\n");
      GetTimeZoneInformation(lpTimeZoneInformation: &tzInfo);
      v6 = pFileList;
      numDumps = 1;
      if ( pFileList != nullptr )
      {
        do
        {
          FileTimeToSystemTime(lpFileTime: &v6->changeTime, lpSystemTime: &fatxSystemTime);
          SystemTimeToTzSpecificLocalTime(
            lpTimeZoneInformation: &tzInfo,
            lpUniversalTime: &fatxSystemTime,
            lpLocalTime: &fatxLocalTime);
          V_snprintf(
            pDest: szDumpPath,
            maxLen: 260,
            pFormat: "dumps/%s/%2.2d_%2.2d_%4.4d__%2.2d_%2.2d_%2.2d",
            g_xboxName,
            fatxLocalTime.wMonth,
            fatxLocalTime.wDay,
            fatxLocalTime.wYear,
            fatxLocalTime.wHour,
            fatxLocalTime.wMinute,
            fatxLocalTime.wSecond);
          V_ComposeFileName(path: g_installPath, filename: szDumpPath, dest: szTargetPath, destSize: 260);
          V_ComposeFileName(
            path: szTargetPath,
            filename: (const char *)v6->filename + 9,
            dest: szFinalTargetPath,
            destSize: 260);
          Sys_CreatePath(pInPath: szFinalTargetPath);
          ConsoleWindowPrintf(rgb: 0, strFormat: "Publishing: '%s'\n", szFinalTargetPath);
          V_snprintf(
            pDest: statusBuff1,
            maxLen: 260,
            pFormat: "From: %s (%.2f MB)",
            v6->filename,
            (double)v6->sizeLow * 0.00000095367432);
          V_snprintf(pDest: statusBuff2, maxLen: 260, pFormat: "To: %s", szFinalTargetPath);
          if ( v0 != nullptr )
            CProgress::SetStatus(this: v0, line1: "Copying...", line2: statusBuff1, line3: statusBuff2);
          if ( DmReceiveFileA(a1: szFinalTargetPath, a2: v6->filename) == 47841280 )
          {
            DmDeleteFile(a1: v6->filename, a2: 0);
            FileA = CreateFileA(
                      lpFileName: szFinalTargetPath,
                      dwDesiredAccess: 0xC0000000,
                      dwShareMode: 1u,
                      lpSecurityAttributes: nullptr,
                      dwCreationDisposition: 3u,
                      dwFlagsAndAttributes: 0x80u,
                      hTemplateFile: nullptr);
            v8 = FileA;
            if ( FileA != (HANDLE)-1 )
            {
              if ( !SetFileTime(
                      hFile: FileA,
                      lpCreationTime: &v6->creationTime,
                      lpLastAccessTime: nullptr,
                      lpLastWriteTime: &v6->changeTime) )
                GetLastError();
              CloseHandle(hObject: v8);
            }
            v0 = pProgress;
          }
          else
          {
            ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Copy Failed: '%s'\n", szFinalTargetPath);
          }
          ++numDumps;
          if ( v0 != nullptr )
            CProgress::SetMeter(this: v0, currentPos: numDumps, range: -1);
          v6 = v6->nextPtr;
        }
        while ( v6 != nullptr );
        if ( pFileList != nullptr )
          FreeTargetFileList(pFileList);
      }
      if ( v0 != nullptr )
      {
        CProgress::~CProgress(this: v0);
        free(pMem: v0);
      }
      ConsoleWindowPrintf(rgb: 0, strFormat: "Done.\n");
    }
    else
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "No Crash Dumps Found in '%s'.\n", "e:\\dumps");
    }
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cannot access '%s'.\n", "e:\\dumps");
  }
}
