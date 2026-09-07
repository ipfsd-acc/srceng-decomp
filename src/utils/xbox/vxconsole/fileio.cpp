// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/fileio.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00411120
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
// Address: 0x004111B0
// Name: int CompareFileTimes_NTFStoFATX(struct _FILETIME __near *,char __near *,int,struct _FILETIME __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareFileTimes_NTFStoFATX(
        _FILETIME *ntfsFileTime,
        char *ntfsTimeString,
        unsigned int ntfsStringSize,
        _FILETIME *fatxFileTime,
        char *fatxTimeString,
        unsigned int fatxStringSize)
{
  int result; // eax
  int v7; // ecx
  _TIME_ZONE_INFORMATION tzInfo; // [esp+4h] [ebp-ECh] BYREF
  _SYSTEMTIME fatxSystemTime; // [esp+B0h] [ebp-40h] BYREF
  _SYSTEMTIME ntfsSystemTime; // [esp+C0h] [ebp-30h] BYREF
  _SYSTEMTIME ntfsLocalTime; // [esp+D0h] [ebp-20h] BYREF
  _SYSTEMTIME fatxLocalTime; // [esp+E0h] [ebp-10h] BYREF

  GetTimeZoneInformation(lpTimeZoneInformation: &tzInfo);
  FileTimeToSystemTime(lpFileTime: ntfsFileTime, lpSystemTime: &ntfsSystemTime);
  FileTimeToSystemTime(lpFileTime: fatxFileTime, lpSystemTime: &fatxSystemTime);
  SystemTimeToTzSpecificLocalTime(
    lpTimeZoneInformation: &tzInfo,
    lpUniversalTime: &ntfsSystemTime,
    lpLocalTime: &ntfsLocalTime);
  SystemTimeToTzSpecificLocalTime(
    lpTimeZoneInformation: &tzInfo,
    lpUniversalTime: &fatxSystemTime,
    lpLocalTime: &fatxLocalTime);
  if ( ntfsTimeString != nullptr )
    SystemTimeToString(systemTime: &ntfsLocalTime, buffer: ntfsTimeString, bufferSize: ntfsStringSize);
  if ( fatxTimeString != nullptr )
    SystemTimeToString(systemTime: &fatxLocalTime, buffer: fatxTimeString, bufferSize: fatxStringSize);
  result = ntfsLocalTime.wYear - fatxLocalTime.wYear;
  if ( ntfsLocalTime.wYear == fatxLocalTime.wYear )
  {
    result = ntfsLocalTime.wMonth - fatxLocalTime.wMonth;
    if ( ntfsLocalTime.wMonth == fatxLocalTime.wMonth )
    {
      result = ntfsLocalTime.wDay - fatxLocalTime.wDay;
      if ( ntfsLocalTime.wDay == fatxLocalTime.wDay )
      {
        result = ntfsLocalTime.wHour - fatxLocalTime.wHour;
        if ( ntfsLocalTime.wHour == fatxLocalTime.wHour )
        {
          v7 = ntfsLocalTime.wSecond
             + 60 * (ntfsLocalTime.wMinute + 60 * result - fatxLocalTime.wMinute)
             - fatxLocalTime.wSecond;
          return (unsigned int)(v7 + 3) > 6 ? v7 : 0;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004112B0
// Name: int CompareFileTimes_NTFStoNTFS(struct _FILETIME __near *,char __near *,int,struct _FILETIME __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareFileTimes_NTFStoNTFS(
        _FILETIME *ntfsFileTimeA,
        char *ntfsTimeStringA,
        unsigned int ntfsStringSizeA,
        _FILETIME *ntfsFileTimeB,
        char *ntfsTimeStringB,
        unsigned int ntfsStringSizeB)
{
  int result; // eax
  _TIME_ZONE_INFORMATION tzInfo; // [esp+4h] [ebp-ECh] BYREF
  _SYSTEMTIME ntfsSystemTimeB; // [esp+B0h] [ebp-40h] BYREF
  _SYSTEMTIME ntfsSystemTimeA; // [esp+C0h] [ebp-30h] BYREF
  _SYSTEMTIME ntfsLocalTimeA; // [esp+D0h] [ebp-20h] BYREF
  _SYSTEMTIME ntfsLocalTimeB; // [esp+E0h] [ebp-10h] BYREF

  GetTimeZoneInformation(lpTimeZoneInformation: &tzInfo);
  FileTimeToSystemTime(lpFileTime: ntfsFileTimeA, lpSystemTime: &ntfsSystemTimeA);
  FileTimeToSystemTime(lpFileTime: ntfsFileTimeB, lpSystemTime: &ntfsSystemTimeB);
  SystemTimeToTzSpecificLocalTime(
    lpTimeZoneInformation: &tzInfo,
    lpUniversalTime: &ntfsSystemTimeA,
    lpLocalTime: &ntfsLocalTimeA);
  SystemTimeToTzSpecificLocalTime(
    lpTimeZoneInformation: &tzInfo,
    lpUniversalTime: &ntfsSystemTimeB,
    lpLocalTime: &ntfsLocalTimeB);
  if ( ntfsTimeStringA != nullptr )
    SystemTimeToString(systemTime: &ntfsLocalTimeA, buffer: ntfsTimeStringA, bufferSize: ntfsStringSizeA);
  if ( ntfsTimeStringB != nullptr )
    SystemTimeToString(systemTime: &ntfsLocalTimeB, buffer: ntfsTimeStringB, bufferSize: ntfsStringSizeB);
  result = ntfsLocalTimeA.wYear - ntfsLocalTimeB.wYear;
  if ( ntfsLocalTimeA.wYear == ntfsLocalTimeB.wYear )
  {
    result = ntfsLocalTimeA.wMonth - ntfsLocalTimeB.wMonth;
    if ( ntfsLocalTimeA.wMonth == ntfsLocalTimeB.wMonth )
    {
      result = ntfsLocalTimeA.wDay - ntfsLocalTimeB.wDay;
      if ( ntfsLocalTimeA.wDay == ntfsLocalTimeB.wDay )
      {
        result = ntfsLocalTimeA.wHour - ntfsLocalTimeB.wHour;
        if ( ntfsLocalTimeA.wHour == ntfsLocalTimeB.wHour )
          return ntfsLocalTimeA.wSecond
               + 60 * (ntfsLocalTimeA.wMinute + 60 * result - ntfsLocalTimeB.wMinute)
               - ntfsLocalTimeB.wSecond;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004113A0
// Name: void FreeTargetFileList(struct fileNode_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeTargetFileList(fileNode_s *pFileList)
{
  fileNode_s *v1; // esi
  fileNode_s *nextPtr; // edi

  v1 = pFileList;
  if ( pFileList != nullptr )
  {
    do
    {
      nextPtr = v1->nextPtr;
      Sys_Free(ptr: v1->filename);
      Sys_Free(ptr: v1);
      v1 = nextPtr;
    }
    while ( nextPtr != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004113D0
// Name: bool GetTargetFileList_r(char __near *,bool,int,int,struct fileNode_s __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetTargetFileList_r(char *targetPath, bool recurse, int attributes, int level, fileNode_s **pFileList)
{
  char *v5; // edi
  int v6; // esi
  int v7; // edx
  char *v8; // eax
  char v9; // cl
  unsigned int v10; // eax
  _DM_FILE_ATTRIBUTES *v11; // edi
  char v12; // cl
  char *v13; // edi
  char *v14; // esi
  char v15; // cl
  unsigned int v16; // eax
  bool v17; // zf
  fileNode_s *v18; // esi
  char v20; // [esp+Bh] [ebp-231h] BYREF
  char filename[260]; // [esp+Ch] [ebp-230h] BYREF
  _DM_FILE_ATTRIBUTES fileAttr; // [esp+110h] [ebp-12Ch] BYREF
  int i; // [esp+22Ch] [ebp-10h]
  int fixedAttributes; // [esp+230h] [ebp-Ch]
  _DM_WALK_DIR *pWalkDir; // [esp+234h] [ebp-8h] BYREF
  bool bGetNormal; // [esp+23Bh] [ebp-1h]

  pWalkDir = nullptr;
  if ( level == 0 )
    *pFileList = nullptr;
  fixedAttributes = attributes;
  if ( (attributes & 0x80u) == 0 )
  {
    bGetNormal = false;
  }
  else
  {
    fixedAttributes = attributes & 0xFFFFFF7F;
    bGetNormal = true;
  }
  v5 = targetPath;
  v6 = DmWalkDir(a1: &pWalkDir, a2: targetPath, a3: &fileAttr);
  if ( v6 == 47841280 )
  {
    v7 = filename - targetPath;
    for ( i = filename - targetPath; ; v7 = i )
    {
      v8 = v5;
      do
      {
        v9 = *v8;
        v8[v7] = *v8;
        ++v8;
      }
      while ( v9 != 0 );
      Sys_AddFileSeperator(path: filename, pathLen: 260);
      v10 = strlen(fileAttr.Name) + 1;
      v11 = (_DM_FILE_ATTRIBUTES *)&v20;
      do
      {
        v12 = v11->Name[1];
        v11 = (_DM_FILE_ATTRIBUTES *)((char *)v11 + 1);
      }
      while ( v12 != 0 );
      qmemcpy(v11, &fileAttr, 4 * (v10 >> 2));
      v14 = &fileAttr.Name[4 * (v10 >> 2)];
      v13 = &v11->Name[4 * (v10 >> 2)];
      v15 = v10;
      v16 = fileAttr.Attributes;
      v17 = !bGetNormal;
      qmemcpy(v13, v14, v15 & 3);
      if ( !v17 && v16 == 0 || (v16 & fixedAttributes) != 0 )
      {
        Sys_NormalizePath(path: filename, forceToLower: false);
        v18 = (fileNode_s *)Sys_Alloc(size: 44);
        v18->filename = Sys_CopyString(str: filename);
        v18->changeTime = fileAttr.ChangeTime;
        v18->creationTime = fileAttr.CreationTime;
        v18->sizeHigh = fileAttr.SizeHigh;
        v18->sizeLow = fileAttr.SizeLow;
        v18->attributes = fileAttr.Attributes;
        v18->level = level;
        v18->nextPtr = *pFileList;
        LOBYTE(v16) = fileAttr.Attributes;
        *pFileList = v18;
      }
      if ( (v16 & 0x10) != 0
        && recurse
        && !GetTargetFileList_r(targetPath: filename, recurse, attributes, level: level + 1, pFileList) )
      {
        break;
      }
      v6 = DmWalkDir(a1: &pWalkDir, a2: targetPath, a3: &fileAttr);
      if ( v6 != 47841280 )
        goto LABEL_21;
      v5 = targetPath;
    }
    return false;
  }
  else
  {
LABEL_21:
    DmCloseDir(a1: pWalkDir);
    return v6 == -2099642108;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411580
// Name: bool LoadTargetFile(char const __near *,int __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadTargetFile(const char *pTargetPath, int *pFileSize, void **pData)
{
  void **v3; // eax
  int *v4; // ebx
  _BYTE *v5; // esi
  void **v6; // edx
  _DM_FILE_ATTRIBUTES fileAttributes; // [esp+8h] [ebp-11Ch] BYREF

  v3 = pData;
  v4 = pFileSize;
  *pFileSize = 0;
  *v3 = nullptr;
  if ( DmGetFileAttributes(a1: pTargetPath, a2: &fileAttributes) != 47841280 || fileAttributes.SizeLow == 0 )
    return 0;
  v5 = Sys_Alloc(size: fileAttributes.SizeLow + 1);
  if ( DmReadFilePartial(a1: pTargetPath, a2: 0, a3: v5, a4: fileAttributes.SizeLow, a5: &pFileSize) == 47841280
    && pFileSize == (int *)fileAttributes.SizeLow )
  {
    v6 = pData;
    v5[fileAttributes.SizeLow] = 0;
    *v4 = fileAttributes.SizeLow;
    *v6 = v5;
    return 1;
  }
  else
  {
    Sys_Free(ptr: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411620
// Name: bool CreateTargetPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTargetPath(const char *pTargetFilename)
{
  _BYTE *v1; // eax
  _BYTE *v2; // esi
  _BYTE *v3; // eax
  char dirPath[260]; // [esp+0h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetFilename);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v2 = v1;
  if ( v1 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v2 + 1, chr: 0x5Cu);
      v2 = v3;
      if ( v3 == nullptr )
        break;
      *v3 = 0;
      DmMkdir(a1: dirPath);
      *v2 = 92;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00411690
// Name: int FileSyncEx(char const __near *,char const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileSyncEx(
        const char *localFilename,
        const char *targetFilename,
        int fileSyncMode,
        bool bVerbose,
        bool bNoWrite)
{
  int v5; // esi
  char v7; // bl
  int v8; // eax
  int v9; // esi
  char targetTimeString[256]; // [esp+8h] [ebp-344h] BYREF
  char localTimeString[256]; // [esp+108h] [ebp-244h] BYREF
  _DM_FILE_ATTRIBUTES targetAttributes; // [esp+208h] [ebp-144h] BYREF
  _WIN32_FILE_ATTRIBUTE_DATA localAttributes; // [esp+324h] [ebp-28h] BYREF
  int errCode; // [esp+348h] [ebp-4h]
  char pathExist_3; // [esp+35Fh] [ebp+13h]

  v5 = fileSyncMode & 0xF;
  if ( (fileSyncMode & 0xF) == 0 )
    return 0;
  if ( GetFileAttributesExA(
         lpFileName: localFilename,
         fInfoLevelId: GetFileExInfoStandard,
         lpFileInformation: &localAttributes) )
  {
    if ( (localAttributes.dwFileAttributes & 0x10) != 0 )
      return 0;
    if ( fileSyncMode < 0 && DmGetFileAttributes(a1: targetFilename, a2: &targetAttributes) != 47841280 )
    {
      if ( bVerbose )
        ConsoleWindowPrintf(rgb: 0, strFormat: "No Update, Target file %s not available\n", targetFilename);
      return 0;
    }
    errCode = 0;
    v7 = 1;
    pathExist_3 = 0;
    if ( v5 != 2 && v5 != 3 )
    {
      if ( v5 == 1 && bVerbose )
        ConsoleWindowPrintf(rgb: 0, strFormat: "Force Update, %s\n", targetFilename);
LABEL_34:
      if ( !bNoWrite )
      {
        if ( pathExist_3 == 0 )
          CreateTargetPath(pTargetFilename: targetFilename);
        v9 = DmSendFileA(a1: localFilename, a2: targetFilename);
        if ( v9 == 47841280 )
        {
          memset(dst: (unsigned __int8 *)&targetAttributes, value: 0, count: sizeof(targetAttributes));
          targetAttributes.SizeHigh = localAttributes.nFileSizeHigh;
          targetAttributes.CreationTime = localAttributes.ftCreationTime;
          targetAttributes.SizeLow = localAttributes.nFileSizeLow;
          targetAttributes.ChangeTime = localAttributes.ftLastWriteTime;
          DmSetFileAttributes(a1: targetFilename, a2: &targetAttributes);
          errCode = 1;
        }
        else
        {
          if ( bVerbose )
            ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Sync Failed!\n");
          errCode = -1;
        }
        DebugCommand(pStrFormat: "0x%8.8x = FileSyncEx( %s, %s )\n", v9, localFilename, targetFilename);
      }
      return errCode;
    }
    if ( DmGetFileAttributes(a1: targetFilename, a2: &targetAttributes) != 47841280 )
    {
      if ( bVerbose )
        ConsoleWindowPrintf(rgb: 0, strFormat: "Initial Copy, %s\n", targetFilename);
      goto LABEL_34;
    }
    pathExist_3 = 1;
    v8 = CompareFileTimes_NTFStoFATX(
           ntfsFileTime: &localAttributes.ftLastWriteTime,
           ntfsTimeString: localTimeString,
           ntfsStringSize: 0x100u,
           fatxFileTime: &targetAttributes.ChangeTime,
           fatxTimeString: targetTimeString,
           fatxStringSize: 0x100u);
    if ( v5 == 2 )
    {
      if ( v8 < 0 )
      {
        if ( bVerbose )
        {
          ConsoleWindowPrintf(
            rgb: 0,
            strFormat: "No Update, %s [%s] is newer than %s [%s]\n",
            targetFilename,
            targetTimeString,
            localFilename,
            localTimeString);
          return errCode;
        }
        return errCode;
      }
      if ( v8 != 0 )
      {
        if ( bVerbose )
          ConsoleWindowPrintf(
            rgb: 0,
            strFormat: "Update, %s [%s] is older than %s [%s]\n",
            targetFilename,
            targetTimeString,
            localFilename,
            localTimeString);
        goto LABEL_34;
      }
    }
    else if ( v8 != 0 )
    {
      if ( bVerbose )
        ConsoleWindowPrintf(
          rgb: 0,
          strFormat: "Update, %s [%s] has different time than %s [%s]\n",
          targetFilename,
          targetTimeString,
          localFilename,
          localTimeString);
      goto LABEL_34;
    }
    if ( localAttributes.nFileSizeLow == targetAttributes.SizeLow
      && localAttributes.nFileSizeHigh == targetAttributes.SizeHigh )
    {
      v7 = 0;
    }
    if ( bVerbose )
    {
      if ( v7 == 0 )
      {
        ConsoleWindowPrintf(
          rgb: 0,
          strFormat: "No Update, %s [%s] [%d] has same time and file size as %s [%s] [%d]\n",
          targetFilename,
          targetTimeString,
          targetAttributes.SizeLow,
          localFilename,
          localTimeString,
          localAttributes.nFileSizeLow);
        return errCode;
      }
      ConsoleWindowPrintf(
        rgb: 0,
        strFormat: "Update, %s [%s] [%d] has different size than %s [%s] [%d]\n",
        targetFilename,
        targetTimeString,
        targetAttributes.SizeLow,
        localFilename,
        localTimeString,
        localAttributes.nFileSizeLow);
    }
    if ( v7 == 0 )
      return errCode;
    goto LABEL_34;
  }
  if ( bVerbose )
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Sync Failure: Local file %s not available\n", localFilename);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004119B0
// Name: int FileSyncToAny(char const __near *,char const __near *,bool,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileSyncToAny(
        const char *localFilename,
        const char *targetFilename,
        bool bTargetIsXbox,
        int fileSyncMode,
        bool bVerbose,
        bool bNoWrite)
{
  int v7; // esi
  int v8; // eax
  bool v9; // bl
  char targetTimeString[256]; // [esp+0h] [ebp-250h] BYREF
  char localTimeString[256]; // [esp+100h] [ebp-150h] BYREF
  _WIN32_FILE_ATTRIBUTE_DATA targetAttributes; // [esp+200h] [ebp-50h] BYREF
  _WIN32_FILE_ATTRIBUTE_DATA localAttributes; // [esp+224h] [ebp-2Ch] BYREF
  int errCode; // [esp+248h] [ebp-8h]
  bool copy; // [esp+24Fh] [ebp-1h]
  bool pathExist; // [esp+263h] [ebp+13h]

  if ( bTargetIsXbox )
    return FileSyncEx(localFilename, targetFilename, fileSyncMode, bVerbose, bNoWrite);
  v7 = fileSyncMode & 0xF;
  if ( (fileSyncMode & 0xF) == 0 )
    return 0;
  if ( GetFileAttributesExA(
         lpFileName: localFilename,
         fInfoLevelId: GetFileExInfoStandard,
         lpFileInformation: &localAttributes) )
  {
    if ( (localAttributes.dwFileAttributes & 0x10) != 0 )
      return 0;
    if ( fileSyncMode < 0
      && !GetFileAttributesExA(
            lpFileName: targetFilename,
            fInfoLevelId: GetFileExInfoStandard,
            lpFileInformation: &targetAttributes) )
    {
      if ( bVerbose )
        ConsoleWindowPrintf(rgb: 0, strFormat: "No Update, Target file %s not available\n", targetFilename);
      return 0;
    }
    errCode = 0;
    copy = true;
    pathExist = false;
    if ( v7 != 2 && v7 != 3 )
    {
      if ( v7 == 1 && bVerbose )
        ConsoleWindowPrintf(rgb: 0, strFormat: "Force Update, %s\n", targetFilename);
LABEL_37:
      if ( !bNoWrite )
      {
        if ( !pathExist )
          Sys_CreatePath(pInPath: targetFilename);
        if ( CopyFileA(lpExistingFileName: localFilename, lpNewFileName: targetFilename, bFailIfExists: false) )
        {
          errCode = 1;
        }
        else
        {
          if ( bVerbose )
            ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Sync Failed!\n");
          errCode = -1;
        }
        DebugCommand(pStrFormat: "0x%8.8x = FileSyncEx( %s, %s )\n", errCode, localFilename, targetFilename);
      }
      return errCode;
    }
    if ( !GetFileAttributesExA(
            lpFileName: targetFilename,
            fInfoLevelId: GetFileExInfoStandard,
            lpFileInformation: &targetAttributes) )
    {
      if ( bVerbose )
        ConsoleWindowPrintf(rgb: 0, strFormat: "Initial Copy, %s\n", targetFilename);
      goto LABEL_37;
    }
    pathExist = true;
    v8 = CompareFileTimes_NTFStoNTFS(
           ntfsFileTimeA: &localAttributes.ftLastWriteTime,
           ntfsTimeStringA: localTimeString,
           ntfsStringSizeA: 0x100u,
           ntfsFileTimeB: &targetAttributes.ftLastWriteTime,
           ntfsTimeStringB: targetTimeString,
           ntfsStringSizeB: 0x100u);
    if ( v7 == 2 )
    {
      if ( v8 < 0 )
      {
        if ( bVerbose )
        {
          ConsoleWindowPrintf(
            rgb: 0,
            strFormat: "No Update, %s [%s] is newer than %s [%s]\n",
            targetFilename,
            targetTimeString,
            localFilename,
            localTimeString);
          return errCode;
        }
        return errCode;
      }
      if ( v8 != 0 )
      {
        if ( bVerbose )
          ConsoleWindowPrintf(
            rgb: 0,
            strFormat: "Update, %s [%s] is older than %s [%s]\n",
            targetFilename,
            targetTimeString,
            localFilename,
            localTimeString);
        goto LABEL_37;
      }
    }
    else if ( v8 != 0 )
    {
      if ( bVerbose )
        ConsoleWindowPrintf(
          rgb: 0,
          strFormat: "Update, %s [%s] has different time than %s [%s]\n",
          targetFilename,
          targetTimeString,
          localFilename,
          localTimeString);
      goto LABEL_37;
    }
    v9 = (localAttributes.nFileSizeLow != targetAttributes.nFileSizeLow
       || localAttributes.nFileSizeHigh != targetAttributes.nFileSizeHigh)
      && copy;
    if ( bVerbose )
    {
      if ( !v9 )
      {
        ConsoleWindowPrintf(
          rgb: 0,
          strFormat: "No Update, %s [%s] [%d] has same time and file size as %s [%s] [%d]\n",
          targetFilename,
          targetTimeString,
          targetAttributes.nFileSizeLow,
          localFilename,
          localTimeString,
          localAttributes.nFileSizeLow);
        return errCode;
      }
      ConsoleWindowPrintf(
        rgb: 0,
        strFormat: "Update, %s [%s] [%d] has different size than %s [%s] [%d]\n",
        targetFilename,
        targetTimeString,
        targetAttributes.nFileSizeLow,
        localFilename,
        localTimeString,
        localAttributes.nFileSizeLow);
    }
    if ( !v9 )
      return errCode;
    goto LABEL_37;
  }
  if ( bVerbose )
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Sync Failure: Local file %s not available\n", localFilename);
  return -1;
}
