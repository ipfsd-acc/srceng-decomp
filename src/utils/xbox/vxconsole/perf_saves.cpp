// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/perf_saves.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004145A0
// Name: void PerfSaves_Publish(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerfSaves_Publish()
{
  fileNode_s *v0; // esi
  int v1; // ecx
  fileNode_s *v2; // eax
  const char *v3; // edi
  const char *PerfmonFileserverPath; // eax
  HANDLE FileA; // edi
  char pConsoleSavePath[260]; // [esp+0h] [ebp-210h] BYREF
  char szFinalTargetPath[260]; // [esp+104h] [ebp-10Ch] BYREF
  fileNode_s *pFileList; // [esp+208h] [ebp-8h] BYREF
  int iNumSaves; // [esp+20Ch] [ebp-4h]

  V_snprintf(pDest: pConsoleSavePath, maxLen: 260, pFormat: "%s\\portal2\\SAVE", g_targetPath);
  pFileList = nullptr;
  if ( GetTargetFileList_r(targetPath: pConsoleSavePath, recurse: true, attributes: 129, level: 0, &pFileList) )
  {
    v0 = pFileList;
    v1 = 0;
    v2 = pFileList;
    if ( pFileList != nullptr )
    {
      do
      {
        v2 = v2->nextPtr;
        ++v1;
      }
      while ( v2 != nullptr );
      if ( v1 != 0 )
      {
        iNumSaves = 1;
        do
        {
          v3 = &v0->filename[strlen(pConsoleSavePath) + 1];
          PerfmonFileserverPath = GetPerfmonFileserverPath();
          V_ComposeFileName(path: PerfmonFileserverPath, filename: v3, dest: szFinalTargetPath, destSize: 260);
          Sys_CreatePath(pInPath: szFinalTargetPath);
          if ( StringAfterPrefix(str: v3, prefix: "lowframe") != nullptr )
          {
            if ( DmReceiveFileA(a1: szFinalTargetPath, a2: v0->filename) == 47841280 )
            {
              DmDeleteFile(a1: v0->filename, a2: 0);
              FileA = CreateFileA(
                        lpFileName: szFinalTargetPath,
                        dwDesiredAccess: 0xC0000000,
                        dwShareMode: 1u,
                        lpSecurityAttributes: nullptr,
                        dwCreationDisposition: 3u,
                        dwFlagsAndAttributes: 0x80u,
                        hTemplateFile: nullptr);
              if ( FileA != (HANDLE)-1 )
              {
                if ( !SetFileTime(
                        hFile: FileA,
                        lpCreationTime: &v0->creationTime,
                        lpLastAccessTime: nullptr,
                        lpLastWriteTime: &v0->changeTime) )
                  GetLastError();
                CloseHandle(hObject: FileA);
              }
            }
            else
            {
              ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Copy Failed: '%s'\n", szFinalTargetPath);
            }
          }
          v0 = v0->nextPtr;
          ++iNumSaves;
        }
        while ( v0 != nullptr );
        if ( pFileList != nullptr )
          FreeTargetFileList(pFileList);
        ConsoleWindowPrintf(rgb: 0, strFormat: "%i perf saves published.\n", iNumSaves);
      }
    }
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cannot access '%s'.\n", pConsoleSavePath);
  }
}
