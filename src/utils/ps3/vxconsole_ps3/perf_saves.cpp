// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/perf_saves.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00409440
// Name: void PerfSaves_Publish(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerfSaves_Publish()
{
  int v0; // edx
  unsigned int m_Head; // eax
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *m_pMemory; // ecx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v3; // eax
  bool v4; // zf
  unsigned int i; // eax
  unsigned int v6; // ebx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v7; // esi
  const char *Name; // esi
  int v9; // eax
  char *v10; // ecx
  HANDLE FileA; // eax
  HANDLE FirstFileA; // esi
  const char *PerfmonFileserverPath; // eax
  char szSearchString[260]; // [esp+8h] [ebp-57Ch] BYREF
  char szDest[260]; // [esp+10Ch] [ebp-478h] BYREF
  _WIN32_FIND_DATAA FindFileData; // [esp+210h] [ebp-374h] BYREF
  char szTempPath[260]; // [esp+350h] [ebp-234h] BYREF
  char szSrc[260]; // [esp+454h] [ebp-130h] BYREF
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > fileList; // [esp+558h] [ebp-2Ch] BYREF
  int iNumSaves; // [esp+580h] [ebp-4h]

  V_snprintf(pDest: szTempPath, maxLen: 260, pFormat: "%s%s\\", "c:\\tmp\\", g_ps3TargetName);
  memset(&fileList, 0, 12);
  fileList.m_LastAlloc.index = -1;
  memset(&fileList.m_Head, 255, 12);
  fileList.m_ElementCount = 0;
  fileList.m_NumAlloced = 0;
  fileList.m_pElements = nullptr;
  if ( GetTargetFileList_r(
         targetPath: "/dev_hdd0/game/PORT00002/USRDIR/tempsave",
         recurse: false,
         attributes: 128,
         level: 0,
         pFileList: &fileList) == 0 )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Cannot access '%s'.\n", "/dev_hdd0/game/PORT00002/USRDIR/tempsave");
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= 0 && fileList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
    return;
  }
  v0 = 0;
  m_Head = fileList.m_Head;
  if ( fileList.m_Head == -1 )
    goto LABEL_9;
  m_pMemory = fileList.m_Memory.m_pMemory;
  do
  {
    m_Head = fileList.m_Memory.m_pMemory[m_Head].m_Next;
    ++v0;
  }
  while ( m_Head != -1 );
  if ( v0 == 0 )
  {
LABEL_9:
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize < 0 )
      return;
    v3 = fileList.m_Memory.m_pMemory;
    v4 = fileList.m_Memory.m_pMemory == nullptr;
    goto LABEL_30;
  }
  iNumSaves = 0;
  for ( i = fileList.m_Head; i != -1; i = fileList.m_Memory.m_pMemory[v6].m_Next )
  {
    v6 = i;
    v7 = &m_pMemory[i];
    if ( StringAfterPrefix(str: &v7->m_Element.Name[41], prefix: "lowframe") != nullptr )
    {
      V_ComposeFileName(path: szTempPath, filename: &v7->m_Element.Name[41], dest: szSrc, destSize: 260);
      Sys_CreatePath(pInPath: szSrc);
      Name = v7->m_Element.Name;
      v9 = _V_strlen(str: Name);
      if ( v9 > 0 )
      {
        v10 = (char *)Name;
        do
        {
          if ( *v10 == 92 )
            *v10 = 47;
          ++v10;
          --v9;
        }
        while ( v9 != 0 );
      }
      if ( CPS3TargetConnection::DownloadFileAsync(this: &g_PS3CurrentTargetConn, pszSource: Name, pszDest: szSrc) >= 0 )
      {
        CPS3TargetConnection::DeleteFileA(this: &g_PS3CurrentTargetConn, pszFileName: Name, fIsDirectory: false);
        FileA = CreateFileA(
                  lpFileName: szSrc,
                  dwDesiredAccess: 0xC0000000,
                  dwShareMode: 1u,
                  lpSecurityAttributes: nullptr,
                  dwCreationDisposition: 3u,
                  dwFlagsAndAttributes: 0x80u,
                  hTemplateFile: nullptr);
        if ( FileA != (HANDLE)-1 )
          CloseHandle(hObject: FileA);
        ++iNumSaves;
      }
      else
      {
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Copy Failed: '%s'\n", szSrc);
      }
    }
    m_pMemory = fileList.m_Memory.m_pMemory;
  }
  if ( iNumSaves != 0 )
  {
    CPS3TargetConnection::WaitForAsyncFileTransfers(this: &g_PS3CurrentTargetConn);
    V_snprintf(pDest: szSearchString, maxLen: 260, pFormat: "%s*.sav", szTempPath);
    FirstFileA = FindFirstFileA(lpFileName: szSearchString, lpFindFileData: &FindFileData);
    do
    {
      V_snprintf(pDest: szSrc, maxLen: 260, pFormat: "%s%s", szTempPath, FindFileData.cFileName);
      PerfmonFileserverPath = GetPerfmonFileserverPath();
      V_snprintf(pDest: szDest, maxLen: 260, pFormat: "%s%s", PerfmonFileserverPath, FindFileData.cFileName);
      CopyFileA(lpExistingFileName: szSrc, lpNewFileName: szDest, bFailIfExists: false);
      DeleteFileA(lpFileName: szSrc);
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &FindFileData) );
    ConsoleWindowPrintf(rgb: 0, strFormat: "%i perf saves published.\n", iNumSaves);
  }
  CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(this: &fileList);
  if ( fileList.m_Memory.m_nGrowSize >= 0 )
  {
    v3 = fileList.m_Memory.m_pMemory;
    v4 = fileList.m_Memory.m_pMemory == nullptr;
LABEL_30:
    if ( !v4 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
  }
}
