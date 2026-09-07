// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/fileio.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00406B70
// Name: char __near * SystemTimeToString(struct _SYSTEMTIME __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl SystemTimeToString(_SYSTEMTIME *systemTime, char *buffer, unsigned int bufferSize)
{
  bool v3; // zf
  char *result; // eax
  char dateString[256]; // [esp+8h] [ebp-200h] BYREF
  char timeString[256]; // [esp+108h] [ebp-100h] BYREF

  GetDateFormatA(
    Locale: 0x800u,
    dwFlags: 0,
    lpDate: systemTime,
    lpFormat: "MM'/'dd'/'yyyy",
    lpDateStr: dateString,
    cchDate: 256);
  GetTimeFormatA(
    Locale: 0x800u,
    dwFlags: 0,
    lpTime: systemTime,
    lpFormat: "hh':'mm':'ss tt",
    lpTimeStr: timeString,
    cchTime: 256);
  v3 = _snprintf(string: buffer, count: bufferSize, format: "%s  %s", dateString, timeString) == -1;
  result = buffer;
  if ( v3 )
    buffer[bufferSize - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406F60
// Name: bool GetTargetFileList_r(char __near *,bool,int,int,class CUtlLinkedList<struct ps3FileInfo_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct ps3FileInfo_t,unsigned int>,unsigned int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetTargetFileList_r(
        char *targetPath,
        bool recurse,
        int attributes,
        int level,
        CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > *pFileList)
{
  HRESULT DirectoryListing; // esi
  int v7; // edx
  char *v8; // eax
  char v9; // cl
  unsigned int v10; // eax
  bool *v11; // edi
  char v12; // cl
  int WindowsAttribs; // eax
  SNPS3DirEntry *m_pMemory; // eax
  const char *v15; // [esp+0h] [ebp-2B8h]
  ps3FileInfo_t fileInfo; // [esp+Ch] [ebp-2ACh] BYREF
  char filename[260]; // [esp+194h] [ebp-124h] BYREF
  int v18; // [esp+298h] [ebp-20h]
  int i; // [esp+29Ch] [ebp-1Ch]
  CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > listing; // [esp+2A0h] [ebp-18h] BYREF
  unsigned int v21; // [esp+2B4h] [ebp-4h]

  memset(&listing, 0, sizeof(listing));
  DirectoryListing = CPS3TargetConnection::GetDirectoryListing(
                       this: &g_PS3CurrentTargetConn,
                       pszTargetDirectory: targetPath,
                       aDirEntries: &listing);
  if ( DirectoryListing != 0 )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Couldn't list directory %s", v15);
    DmAPI_DisplayError(message: &str, hr: DirectoryListing);
LABEL_3:
    CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&listing);
    return 0;
  }
  i = 0;
  if ( listing.m_Size > 0 )
  {
    v7 = filename - targetPath;
    v18 = filename - targetPath;
    v21 = 0;
    while ( 1 )
    {
      v8 = targetPath;
      fileInfo.SNPS3DirEntry = listing.m_Memory.m_pMemory[v21 / 0x180];
      fileInfo.level = level;
      fileInfo.needsUpdate = false;
      do
      {
        v9 = *v8;
        v8[v7] = *v8;
        ++v8;
      }
      while ( v9 != 0 );
      Sys_AddFileSeperator(path: filename, pathLen: 260);
      v10 = strlen(fileInfo.Name) + 1;
      v11 = &fileInfo.needsUpdate + 3;
      do
        v12 = *++v11;
      while ( v12 != 0 );
      qmemcpy(v11, fileInfo.Name, v10);
      WindowsAttribs = ps3FileInfo_t::GetWindowsAttribs(this: &fileInfo);
      if ( attributes == 128 && WindowsAttribs == 128 || (attributes & WindowsAttribs) == (attributes & 0xFFFFFF7F) )
      {
        Sys_NormalizePath(path: filename, forceToLower: false);
        V_strncpy(pDest: fileInfo.Name, pSrc: filename, maxLen: 256);
        CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::AddToTail(
          this: pFileList,
          src: &fileInfo);
      }
      if ( fileInfo.Type == 1
        && recurse
        && !GetTargetFileList_r(targetPath: filename, recurse, attributes, level: level + 1, pFileList) )
      {
        goto LABEL_3;
      }
      v21 += 384;
      if ( ++i >= listing.m_Size )
        break;
      v7 = v18;
    }
  }
  m_pMemory = listing.m_Memory.m_pMemory;
  listing.m_Size = 0;
  if ( listing.m_Memory.m_nGrowSize >= 0 )
  {
    if ( listing.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: listing.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      listing.m_Memory.m_pMemory = nullptr;
    }
    listing.m_Memory.m_nAllocationCount = 0;
  }
  listing.m_pElements = m_pMemory;
  if ( listing.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}
