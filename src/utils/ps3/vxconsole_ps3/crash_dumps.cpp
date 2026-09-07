// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/crash_dumps.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00406500
// Name: bool DownloadDumpFileToFileserver(char const __near *,char const __near *,struct ps3FileInfo_t __near *,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DownloadDumpFileToFileserver(
        const char *szDestFolder,
        const char *szDestFilename,
        ps3FileInfo_t *pFileNode,
        int *iProgress,
        bool bPrintStatus)
{
  char *Name; // edi
  unsigned int Size_high; // eax
  unsigned int v7; // kr00_4
  int v8; // eax
  char *v9; // ecx
  int v10; // eax
  CProgress *v11; // ecx
  int v12; // ebx
  CProgress *v14; // ecx
  char statusBuff1[260]; // [esp+14h] [ebp-418h] BYREF
  char statusBuff2[260]; // [esp+118h] [ebp-314h] BYREF
  char szFinalTargetPath[260]; // [esp+21Ch] [ebp-210h] BYREF
  char szTempPath[260]; // [esp+320h] [ebp-10Ch] BYREF
  unsigned int Size; // [esp+424h] [ebp-8h]
  unsigned int v20; // [esp+428h] [ebp-4h]

  V_snprintf(pDest: szTempPath, maxLen: 260, pFormat: "%s%s\\%s", "c:\\tmp\\", g_ps3TargetName, szDestFilename);
  Sys_CreatePath(pInPath: szTempPath);
  V_ComposeFileName(path: szDestFolder, filename: szDestFilename, dest: szFinalTargetPath, destSize: 260);
  Sys_CreatePath(pInPath: szFinalTargetPath);
  if ( bPrintStatus )
    ConsoleWindowPrintf(rgb: 0, strFormat: "Publishing: '%s'\n", szFinalTargetPath);
  Name = pFileNode->Name;
  Size_high = HIDWORD(pFileNode->Size);
  Size = pFileNode->Size;
  v7 = Size;
  v20 = Size_high & 0x80000000;
  Size = 0;
  V_snprintf(
    pDest: statusBuff1,
    maxLen: 260,
    pFormat: "From: %s (%.2f MB)",
    pFileNode->Name,
    (double)__PAIR64__(Size_high, v7) * 0.00000095367432);
  V_snprintf(pDest: statusBuff2, maxLen: 260, pFormat: "To: %s", szFinalTargetPath);
  if ( pProgress != nullptr && bPrintStatus )
    CProgress::SetStatus(this: pProgress, line1: "Copying...", line2: statusBuff1, line3: statusBuff2);
  v8 = _V_strlen(str: Name);
  if ( v8 > 0 )
  {
    v9 = pFileNode->Name;
    do
    {
      if ( *v9 == 92 )
        *v9 = 47;
      ++v9;
      --v8;
    }
    while ( v8 != 0 );
  }
  v10 = CPS3TargetConnection::DownloadFileAsync(this: &g_PS3CurrentTargetConn, pszSource: Name, pszDest: szTempPath);
  v11 = pProgress;
  v12 = v10;
  if ( pProgress != nullptr )
    CProgress::SetMeter(this: v11, currentPos: ++*iProgress, range: -1);
  if ( v12 < 0 )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Copy Failed: '%s'\n", szTempPath);
    return 0;
  }
  CPS3TargetConnection::DeleteFileA(this: &g_PS3CurrentTargetConn, pszFileName: Name, fIsDirectory: false);
  if ( !CopyFileA(lpExistingFileName: szTempPath, lpNewFileName: szFinalTargetPath, bFailIfExists: false) )
    return 0;
  DeleteFileA(lpFileName: szTempPath);
  v14 = pProgress;
  if ( pProgress != nullptr )
    CProgress::SetMeter(this: v14, currentPos: ++*iProgress, range: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406760
// Name: void CrashDumps_Publish(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrashDumps_Publish()
{
  unsigned int m_Head; // eax
  int i; // esi
  CProgress *v2; // ecx
  CProgress *v3; // eax
  unsigned int v4; // edx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *m_pMemory; // ecx
  int v6; // edi
  ps3FileInfo_t *p_m_Element; // esi
  unsigned int m_Next; // eax
  unsigned int v9; // edi
  ps3FileInfo_t *v10; // ebx
  CProgress *v11; // esi
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v12; // eax
  IMemAlloc *v13; // ecx
  unsigned int v14; // esi
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v15; // eax
  unsigned int v16; // esi
  const char *Name; // edi
  int v18; // eax
  char *v19; // ecx
  char szDumpPath[260]; // [esp+8h] [ebp-160h] BYREF
  const char *pDumpName; // [esp+10Ch] [ebp-5Ch]
  int v22; // [esp+110h] [ebp-58h]
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > junkFileList; // [esp+114h] [ebp-54h] BYREF
  int iNumDumps; // [esp+13Ch] [ebp-2Ch] BYREF
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > fileList; // [esp+140h] [ebp-28h] BYREF

  memset(&fileList, 0, 12);
  fileList.m_LastAlloc.index = -1;
  memset(&fileList.m_Head, 255, 12);
  fileList.m_ElementCount = 0;
  fileList.m_NumAlloced = 0;
  fileList.m_pElements = nullptr;
  if ( !GetTargetFileList_r(
          targetPath: "/dev_hdd0/game_debug",
          recurse: true,
          attributes: 128,
          level: 0,
          pFileList: &fileList) )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cannot access '%s'.\n", "/dev_hdd0/game_debug");
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= 0 && fileList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
    return;
  }
  m_Head = fileList.m_Head;
  for ( i = 0; m_Head != -1; ++i )
    m_Head = fileList.m_Memory.m_pMemory[m_Head].m_Next;
  ConsoleWindowPrintf(rgb: 0, strFormat: "\n");
  if ( i != 0 )
  {
    if ( g_installPath[0] == 0 )
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Installation depot not set in Configuration!\n");
      goto LABEL_48;
    }
    v2 = pProgress;
    if ( pProgress == nullptr )
    {
      v3 = (CProgress *)operator new(nSize: 0x28u);
      if ( v3 == nullptr )
      {
        v2 = nullptr;
        pProgress = nullptr;
LABEL_15:
        v4 = fileList.m_Head;
        iNumDumps = 0;
        if ( fileList.m_Head != -1 )
        {
          m_pMemory = fileList.m_Memory.m_pMemory;
          do
          {
            v6 = 400 * v4;
            p_m_Element = &m_pMemory[v4].m_Element;
            v22 = 400 * v4;
            pDumpName = &p_m_Element->Name[21];
            if ( _V_strcmp(s1: &p_m_Element->Name[strlen(&p_m_Element->Name[21]) + 17], s2: ".elf") != 0
              || (V_snprintf(
                    pDest: szDumpPath,
                    maxLen: 260,
                    pFormat: "%s/dumps/%s/%2.2d_%2.2d_%4.4d__%2.2d_%2.2d_%2.2d",
                    g_installPath,
                    g_ps3TargetName,
                    p_m_Element->CreateTime.tm_mon,
                    p_m_Element->CreateTime.tm_mday,
                    p_m_Element->CreateTime.tm_year,
                    p_m_Element->CreateTime.tm_hour,
                    p_m_Element->CreateTime.tm_min,
                    p_m_Element->CreateTime.tm_sec),
                  DownloadDumpFileToFileserver(
                    szDestFolder: szDumpPath,
                    szDestFilename: &p_m_Element->Name[21],
                    pFileNode: p_m_Element,
                    iProgress: &iNumDumps,
                    bPrintStatus: true),
                  m_Next = fileList.m_Head,
                  fileList.m_Head == -1) )
            {
              m_pMemory = fileList.m_Memory.m_pMemory;
            }
            else
            {
              m_pMemory = fileList.m_Memory.m_pMemory;
              do
              {
                v9 = m_Next;
                v10 = &m_pMemory[m_Next].m_Element;
                if ( _V_strcmp(s1: &v10->Name[strlen(&v10->Name[21]) + 17], s2: ".log") == 0
                  && V_strncmp(s1: &v10->Name[21], s2: pDumpName, count: strlen(&v10->Name[21]) - 4) == 0 )
                {
                  DownloadDumpFileToFileserver(
                    szDestFolder: szDumpPath,
                    szDestFilename: &v10->Name[21],
                    pFileNode: v10,
                    iProgress: &iNumDumps,
                    bPrintStatus: false);
                }
                m_pMemory = fileList.m_Memory.m_pMemory;
                m_Next = fileList.m_Memory.m_pMemory[v9].m_Next;
              }
              while ( m_Next != -1 );
              v6 = v22;
            }
            v4 = *(unsigned int *)((char *)&m_pMemory->m_Next + v6);
          }
          while ( v4 != -1 );
          v2 = pProgress;
        }
        v11 = v2;
        if ( v2 != nullptr )
        {
          CProgress::~CProgress(this: v2);
          free(pMem: v11);
        }
        pProgress = nullptr;
        memset(&junkFileList, 0, 12);
        junkFileList.m_LastAlloc.index = -1;
        memset(&junkFileList.m_Head, 255, 12);
        junkFileList.m_ElementCount = 0;
        junkFileList.m_NumAlloced = 0;
        junkFileList.m_pElements = nullptr;
        if ( GetTargetFileList_r(
               targetPath: "/dev_hdd0/game_debug",
               recurse: true,
               attributes: 128,
               level: 0,
               pFileList: &junkFileList) )
        {
          v14 = junkFileList.m_Head;
          if ( junkFileList.m_Head != -1 )
          {
            v15 = junkFileList.m_Memory.m_pMemory;
            do
            {
              v16 = v14;
              Name = v15[v16].m_Element.Name;
              v18 = _V_strlen(str: Name);
              if ( v18 > 0 )
              {
                v19 = (char *)Name;
                do
                {
                  if ( *v19 == 92 )
                    *v19 = 47;
                  ++v19;
                  --v18;
                }
                while ( v18 != 0 );
              }
              CPS3TargetConnection::DeleteFileA(this: &g_PS3CurrentTargetConn, pszFileName: Name, fIsDirectory: false);
              v15 = junkFileList.m_Memory.m_pMemory;
              v14 = junkFileList.m_Memory.m_pMemory[v16].m_Next;
            }
            while ( v14 != -1 );
          }
          ConsoleWindowPrintf(rgb: 0, strFormat: "Done.\n");
          CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &junkFileList);
          if ( junkFileList.m_Memory.m_nGrowSize < 0 )
            goto LABEL_48;
          v12 = junkFileList.m_Memory.m_pMemory;
          if ( junkFileList.m_Memory.m_pMemory == nullptr )
            goto LABEL_47;
          v13 = _g_pMemAlloc;
        }
        else
        {
          ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cannot access '%s'.\n", "/dev_hdd0/game_debug");
          CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &junkFileList);
          if ( junkFileList.m_Memory.m_nGrowSize < 0 )
            goto LABEL_48;
          v12 = junkFileList.m_Memory.m_pMemory;
          if ( junkFileList.m_Memory.m_pMemory == nullptr )
          {
LABEL_47:
            junkFileList.m_Memory.m_nAllocationCount = 0;
            goto LABEL_48;
          }
          v13 = _g_pMemAlloc;
        }
        v13->Free_2(this: v13, a2: v12);
        junkFileList.m_Memory.m_pMemory = nullptr;
        goto LABEL_47;
      }
      v2 = CProgress::CProgress(this: v3);
      pProgress = v2;
      if ( v2 == nullptr )
        goto LABEL_15;
    }
    CProgress::Open(this: v2, title: "Publishing Crash Dumps...", canCancel: false, bHasMeter: true);
    CProgress::SetMeter(this: pProgress, currentPos: 0, range: 2 * i);
    v2 = pProgress;
    goto LABEL_15;
  }
  ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "No Crash Dumps Found in '%s'.\n", "/dev_hdd0/game_debug");
LABEL_48:
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileList);
  if ( fileList.m_Memory.m_nGrowSize >= 0 && fileList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
}
