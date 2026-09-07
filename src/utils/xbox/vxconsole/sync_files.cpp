// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/sync_files.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00422D90
// Name: DvdDevLog
// Source: json
//------------------------------------------------------------------------------
void DvdDevLog(char *strFormat, ...)
{
  _iobuf *v1; // esi
  char string[4096]; // [esp+0h] [ebp-1104h] BYREF
  char dest[260]; // [esp+1000h] [ebp-104h] BYREF
  va_list ap; // [esp+1110h] [ebp+Ch] BYREF

  va_start(ap, strFormat);
  if ( g_bDvdDevLog )
  {
    _vsnprintf(string, count: 0x1000u, format: strFormat, ap);
    ConsoleWindowPrintf(rgb: 0, strFormat: string);
    V_ComposeFileName(path: g_localPath, filename: "dvddev.log", dest, destSize: 260);
    v1 = fopen(file: dest, mode: "at+");
    if ( v1 != nullptr )
    {
      fprintf(str: v1, format: string);
      fclose(stream: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422E20
// Name: DoConversionProcess
// Source: json
//------------------------------------------------------------------------------
char __usercall DoConversionProcess@<al>(
        const char *pszModDir@<esi>,
        const char *pszLogName@<edi>,
        const char *pszScriptName,
        bool bForce)
{
  const char *v4; // eax
  char szCommandLine[1040]; // [esp+0h] [ebp-66Ch] BYREF
  char szMGDPath[260]; // [esp+410h] [ebp-25Ch] BYREF
  char szLogPath[260]; // [esp+514h] [ebp-158h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+618h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+65Ch] [ebp-10h] BYREF

  V_ComposeFileName(path: pszModDir, filename: pszLogName, dest: szLogPath, destSize: 260);
  DeleteFileA(lpFileName: szLogPath);
  V_ComposeFileName(path: g_localPath, filename: "bin\\makegamedata.exe", dest: szMGDPath, destSize: 260);
  v4 = "-f";
  if ( !bForce )
    v4 = &defValue;
  V_snprintf(
    pDest: szCommandLine,
    maxLen: 1040,
    pFormat: "\"%s\" -allowdebug -files %s -dvddev -log %s %s",
    szMGDPath,
    pszScriptName,
    pszLogName,
    v4);
  DvdDevLog(strFormat: "Process Directory: %s\n", pszModDir);
  DvdDevLog(strFormat: "Process: %s\n", szCommandLine);
  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  memset(&pi, 0, sizeof(pi));
  StartupInfo.cb = 68;
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: szCommandLine,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: false,
         dwCreationFlags: 0xC000000u,
         lpEnvironment: nullptr,
         lpCurrentDirectory: pszModDir,
         lpStartupInfo: &StartupInfo,
         lpProcessInformation: &pi) )
  {
    WaitForSingleObject(hHandle: pi.hProcess, dwMilliseconds: 0xFFFFFFFF);
    return 1;
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Failed to launch: %s\n", szCommandLine);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422F40
// Name: FixupFATXFilename
// Source: json
//------------------------------------------------------------------------------
char __cdecl FixupFATXFilename(const char *pFilename, char *pOutFilename, int nOutSize)
{
  const char *v3; // esi
  int v4; // edi
  int v6; // eax
  unsigned int v7; // esi
  char szFixedFilename[260]; // [esp+Ch] [ebp-128h] BYREF
  char szUnique[32]; // [esp+110h] [ebp-24h] BYREF
  unsigned int pulCRC; // [esp+130h] [ebp-4h] BYREF

  v3 = V_UnqualifiedFileName(in: pFilename);
  v4 = strlen(v3);
  if ( v4 <= 42 )
    return 0;
  V_strncpy(pDest: szFixedFilename, pSrc: v3, maxLen: 260);
  strlwr(string: szFixedFilename);
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: szFixedFilename, nBuffer: v4);
  CRC32_Final(&pulCRC);
  sprintf(string: szUnique, format: "~%d", pulCRC % 0x2710);
  szFixedFilename[-strlen(szUnique) + 42] = 0;
  V_strncat(pDest: szFixedFilename, pSrc: szUnique, destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( v3 == pFilename )
  {
    v7 = nOutSize;
  }
  else
  {
    v6 = v3 - pFilename + 1;
    v7 = nOutSize;
    if ( nOutSize < v6 )
      v6 = nOutSize;
    V_strncpy(pDest: pOutFilename, pSrc: pFilename, maxLen: v6);
  }
  V_strncat(pDest: pOutFilename, pSrc: szFixedFilename, destBufferSize: v7, max_chars_to_copy: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423060
// Name: bool SetupP4(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupP4()
{
  struct CSysModule *Module; // eax
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IP4 *v4; // eax
  P4Client_t *v5; // eax
  __int16 v6; // ecx^2
  const char *v7; // eax
  int v8; // [esp-4h] [ebp-10Ch]
  char szPerforcePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( g_p4 == nullptr )
  {
    if ( ParseCommandLineArg(pKey: "-nop4", pValueBuff: nullptr, valueBuffSize: 0) )
      return 0;
    V_ComposeFileName(path: g_localPath, filename: "bin/p4lib.dll", dest: szPerforcePath, destSize: 260);
    if ( Sys_Exists(filename: szPerforcePath) == 0 )
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Can't find expected %s.\n", szPerforcePath);
      return 0;
    }
    Module = Sys_LoadModule(pModuleName: szPerforcePath);
    v2 = Module;
    if ( Module == nullptr )
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Can't load %s.\n", szPerforcePath);
      return 0;
    }
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory == nullptr )
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Can't get factory from %s.\n", szPerforcePath);
      Sys_UnloadModule(pModule: v2);
      return 0;
    }
    v4 = (IP4 *)Factory(a1: "VP4002", a2: nullptr);
    g_p4 = v4;
    if ( v4 == nullptr )
    {
      ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Can't get IP4 interface from %s.\n", szPerforcePath);
      return 1;
    }
    v4->Init(this: v4);
    v5 = g_p4->GetActiveClient(this: g_p4);
    HIWORD(v8) = v6;
    LOWORD(v8) = v5->m_sName.m_Id;
    v7 = (const char *)((int (__thiscall *)(IP4 *, int))g_p4->String)(a1: g_p4, a2: v8);
    ConsoleWindowPrintf(rgb: 0, strFormat: "DVDDEV: Using Client: %s\n", v7);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004234B0
// Name: bool GetTargetDetails(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetTargetDetails()
{
  fileNode_s *i; // edi
  int m_Size; // eax
  int v3; // esi
  CUtlString *m_pMemory; // ecx
  int v5; // eax
  CUtlString *v6; // ecx
  char szLocalPath[260]; // [esp+4h] [ebp-31Ch] BYREF
  char szLogPath[260]; // [esp+108h] [ebp-218h] BYREF
  char szPath[260]; // [esp+20Ch] [ebp-114h] BYREF
  CUtlString string; // [esp+310h] [ebp-10h] BYREF

  V_ComposeFileName(path: g_localPath, filename: "dvddev.log", dest: szLogPath, destSize: 260);
  DeleteFileA(lpFileName: szLogPath);
  DvdDevLog(strFormat: "\nTarget: %s\n", g_targetPath);
  if ( GetTargetFileList_r(
         targetPath: g_targetPath,
         recurse: true,
         attributes: 145,
         level: 0,
         pFileList: &g_pTargetFileDetails) )
  {
    for ( i = g_pTargetFileDetails; i != nullptr; i = i->nextPtr )
    {
      DvdDevLog(strFormat: "  %s\n", i->filename);
      if ( i->level == 0 && (i->attributes & 0x10) != 0 )
      {
        V_FileBase(in: i->filename, out: szPath, maxlen: 260);
        if ( _V_stricmp(s1: szPath, s2: "dvddev") != 0 )
        {
          V_ComposeFileName(path: g_localPath, filename: szPath, dest: szLocalPath, destSize: 260);
          CUtlString::CUtlString(this: &string, pString: szLocalPath);
          m_Size = g_GameDirTable.m_Size;
          v3 = g_GameDirTable.m_Size;
          if ( g_GameDirTable.m_Size + 1 > g_GameDirTable.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CUtlString,int>::Grow(
              this: &g_GameDirTable.m_Memory,
              num: g_GameDirTable.m_Size - g_GameDirTable.m_Memory.m_nAllocationCount + 1);
            m_Size = g_GameDirTable.m_Size;
          }
          m_pMemory = g_GameDirTable.m_Memory.m_pMemory;
          g_GameDirTable.m_Size = m_Size + 1;
          v5 = m_Size - v3;
          g_GameDirTable.m_pElements = g_GameDirTable.m_Memory.m_pMemory;
          if ( v5 > 0 )
          {
            _V_memmove(
              dest: &g_GameDirTable.m_Memory.m_pMemory[v3 + 1],
              src: &g_GameDirTable.m_Memory.m_pMemory[v3],
              count: 16 * v5);
            m_pMemory = g_GameDirTable.m_Memory.m_pMemory;
          }
          v6 = &m_pMemory[v3];
          if ( v6 != nullptr )
            CUtlString::CUtlString(this: v6, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
      }
    }
    return 1;
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: No files at target: %s\n", g_targetPath);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004238B0
// Name: bool SyncShaderCache(bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SyncShaderCache(bool bForce)
{
  fileNode_s *j; // esi
  const char *v2; // eax
  const char *v3; // edi
  int v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // edi
  const char *v8; // eax
  int v9; // eax
  fileList_t *m_pMemory; // eax
  const char *v12; // [esp-8h] [ebp-440h]
  const char *v13; // [esp-8h] [ebp-440h]
  char szPath[260]; // [esp+Ch] [ebp-42Ch] BYREF
  char szShaderCache[260]; // [esp+110h] [ebp-328h] BYREF
  char szShaderPath[260]; // [esp+214h] [ebp-224h] BYREF
  char szTargetPath[260]; // [esp+318h] [ebp-120h] BYREF
  fileNode_s *pShaderFileDetails; // [esp+41Ch] [ebp-1Ch] BYREF
  int i; // [esp+420h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > shaderFiles; // [esp+424h] [ebp-14h] BYREF

  V_ComposeFileName(path: g_targetPath, filename: "shadercache", dest: szShaderCache, destSize: 260);
  GetTargetFileList_r(
    targetPath: szShaderCache,
    recurse: true,
    attributes: 145,
    level: 0,
    pFileList: &pShaderFileDetails);
  for ( j = pShaderFileDetails; j != nullptr; j = j->nextPtr )
  {
    v2 = StringAfterPrefix(str: j->filename, prefix: szShaderCache);
    v3 = v2;
    if ( (j->attributes & 0x10) == 0 && v2 != nullptr && *v2 == 92 )
    {
      V_ComposeFileName(
        path: g_localPath,
        filename: "..\\src\\materialsystem\\stdshaders",
        dest: szTargetPath,
        destSize: 260);
      V_ComposeFileName(path: szTargetPath, filename: v3 + 1, dest: szTargetPath, destSize: 260);
      if ( Sys_Exists(filename: szTargetPath) == 0 )
        DmDeleteFile(a1: j->filename, a2: 0);
    }
  }
  V_ComposeFileName(
    path: g_localPath,
    filename: "..\\src\\materialsystem\\stdshaders\\",
    dest: szShaderPath,
    destSize: 260);
  memset(&shaderFiles, 0, sizeof(shaderFiles));
  V_ComposeFileName(path: szShaderPath, filename: "*.*", dest: szPath, destSize: 260);
  FindFiles(pFileMask: szPath, bRecurse: true, fileList: &shaderFiles);
  i = 0;
  if ( shaderFiles.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = CUtlString::operator char const *(this: &shaderFiles.m_Memory.m_pMemory[v4].fileName);
      v6 = StringAfterPrefix(str: v5, prefix: szShaderPath);
      v7 = v6;
      if ( v6 != nullptr
        && (V_stristr(pStr: v6, pSearch: ".fxc") != nullptr || V_stristr(pStr: v7, pSearch: ".h") != nullptr) )
      {
        V_ComposeFileName(path: g_targetPath, filename: "shadercache", dest: szTargetPath, destSize: 260);
        V_ComposeFileName(path: szTargetPath, filename: v7, dest: szTargetPath, destSize: 260);
        v8 = CUtlString::operator char const *(this: &shaderFiles.m_Memory.m_pMemory[v4].fileName);
        v9 = FileSyncEx(
               localFilename: v8,
               targetFilename: szTargetPath,
               fileSyncMode: 2 * !bForce + 1,
               bVerbose: false,
               bNoWrite: false);
        if ( v9 == -1 )
        {
          v12 = CUtlString::operator char const *(this: &shaderFiles.m_Memory.m_pMemory[v4].fileName);
          ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Error: %s -> %s\n", v12, szTargetPath);
        }
        else if ( v9 == 1 )
        {
          v13 = CUtlString::operator char const *(this: &shaderFiles.m_Memory.m_pMemory[v4].fileName);
          ConsoleWindowPrintf(rgb: 0, strFormat: "Copy %s -> %s\n", v13, szTargetPath);
        }
      }
      ++v4;
      ++i;
    }
    while ( i < shaderFiles.m_Size );
  }
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &shaderFiles);
  m_pMemory = shaderFiles.m_Memory.m_pMemory;
  if ( shaderFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( shaderFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: shaderFiles.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      shaderFiles.m_Memory.m_pMemory = nullptr;
    }
    shaderFiles.m_Memory.m_nAllocationCount = 0;
  }
  shaderFiles.m_pElements = m_pMemory;
  if ( shaderFiles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423C80
// Name: BuildCandidateScripts
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildCandidateScripts(bool bForce)
{
  int m_Size; // eax
  __int16 m_pMemory_high; // ecx^2
  fileNode_s *v3; // esi
  const char *v4; // edi
  const char *v5; // eax
  int v6; // ebx
  int v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  int *p_m_Size; // ebx
  int v11; // edi
  const char *v12; // eax
  const char *v13; // esi
  CFmtStrN<256> *v14; // eax
  const char *v15; // eax
  const char *v16; // esi
  const char *v17; // eax
  signed int File; // esi
  CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> *v19; // edi
  char *v20; // eax
  int v21; // esi
  int m_nAllocationCount; // eax
  int v23; // eax
  BuildCandidateScripts::__l5::outFile_t *m_pMemory; // ecx
  int v25; // eax
  int v26; // esi
  fileNode_s *v27; // edi
  const char *v28; // eax
  bool v29; // zf
  const char *v30; // esi
  bool v31; // bl
  const char *v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // edi
  int v36; // esi
  const char *v37; // eax
  int v38; // eax
  int *v39; // ebx
  const char *v40; // eax
  const char *v41; // eax
  bool v42; // cc
  int v43; // esi
  const char *v44; // edi
  const char *v45; // eax
  const char *v46; // esi
  int v47; // eax
  CFmtStrN<256> *v48; // eax
  _iobuf *v49; // esi
  P4File_t *v50; // eax
  int v52; // [esp-4h] [ebp-754h]
  char szDvdDevPath[260]; // [esp+Ch] [ebp-744h] BYREF
  char szScriptPath[260]; // [esp+110h] [ebp-640h] BYREF
  CFmtStrN<256> v55; // [esp+214h] [ebp-53Ch] BYREF
  CFmtStrN<256> v56; // [esp+320h] [ebp-430h] BYREF
  char szLocalPath[260]; // [esp+42Ch] [ebp-324h] BYREF
  char dest[4]; // [esp+530h] [ebp-220h] BYREF
  characterset_t breakSet; // [esp+534h] [ebp-21Ch] BYREF
  CUtlBuffer results; // [esp+634h] [ebp-11Ch] BYREF
  CUtlBuffer excludeBuffer; // [esp+664h] [ebp-ECh] BYREF
  CUtlBuffer script; // [esp+694h] [ebp-BCh] BYREF
  CUtlString src; // [esp+6C4h] [ebp-8Ch] BYREF
  BuildCandidateScripts::__l5::outFile_t outFile; // [esp+6D4h] [ebp-7Ch] BYREF
  CUtlVector<CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> >,CUtlMemory<CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> >,int> > outputFiles; // [esp+6F8h] [ebp-58h] BYREF
  CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,int> > candidates; // [esp+70Ch] [ebp-44h] BYREF
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > fileList; // [esp+720h] [ebp-30h] BYREF
  const char *pDvdDevFile; // [esp+734h] [ebp-1Ch] BYREF
  int v69; // [esp+738h] [ebp-18h]
  int j; // [esp+73Ch] [ebp-14h]
  bool bFixed; // [esp+743h] [ebp-Dh]
  int i; // [esp+744h] [ebp-Ch]
  const char *pGameDir; // [esp+748h] [ebp-8h]
  fileNode_s *pFileNode; // [esp+74Ch] [ebp-4h]

  if ( g_p4 == nullptr || !g_p4->IsConnectedToServer(this: g_p4, a2: true) )
    return 0;
  memset(&fileList, 0, sizeof(fileList));
  g_p4->GetOpenedFileList_2(this: g_p4, a2: &fileList, a3: false);
  m_Size = g_GameDirTable.m_Size;
  memset(&candidates, 0, sizeof(candidates));
  if ( g_GameDirTable.m_Size > 0 )
  {
    _InsertMultipleBefore___CUtlVector_V__CUtlVector_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_V__CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H____V__CUtlMemory_V__CUtlVector_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_V__CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H____H____QAEHHH_Z(
      this: (CUtlVector<CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> >,CUtlMemory<CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> >,int> > *)&candidates,
      elem: 0,
      num: g_GameDirTable.m_Size);
    m_Size = g_GameDirTable.m_Size;
  }
  memset(&outputFiles, 0, sizeof(outputFiles));
  if ( m_Size > 0 )
    _InsertMultipleBefore___CUtlVector_V__CUtlVector_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_V__CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H____V__CUtlMemory_V__CUtlVector_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_V__CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H____H____QAEHHH_Z(
      this: &outputFiles,
      elem: 0,
      num: m_Size);
  DvdDevLog(strFormat: "\nPerforce Files:\n");
  i = 0;
  if ( fileList.m_Size > 0 )
  {
    pFileNode = nullptr;
    do
    {
      v3 = pFileNode;
      HIWORD(v52) = m_pMemory_high;
      LOWORD(v52) = *(_WORD *)((char *)&pFileNode->creationTime.dwHighDateTime
                             + (unsigned int)fileList.m_Memory.m_pMemory);
      v4 = (const char *)((int (__thiscall *)(IP4 *, int))g_p4->String)(a1: g_p4, a2: v52);
      v5 = " (DELETED)";
      if ( *((_BYTE *)&v3->sizeHigh + (unsigned int)fileList.m_Memory.m_pMemory + 2) == 0 )
        v5 = &defValue;
      DvdDevLog(strFormat: " %s%s\n", v4, v5);
      m_pMemory_high = HIWORD(fileList.m_Memory.m_pMemory);
      if ( *((_BYTE *)&v3->sizeHigh + (unsigned int)fileList.m_Memory.m_pMemory + 2) == 0 )
      {
        v6 = 0;
        if ( g_GameDirTable.m_Size > 0 )
        {
          v7 = 0;
          while ( 1 )
          {
            v8 = CUtlString::operator char const *(this: &g_GameDirTable.m_Memory.m_pMemory[v7]);
            v9 = StringAfterPrefix(str: v4, prefix: v8);
            if ( v9 != nullptr && *v9 == 92 )
              break;
            ++v6;
            ++v7;
            if ( v6 >= g_GameDirTable.m_Size )
              goto LABEL_22;
          }
          CUtlString::CUtlString(this: &src, pString: v9 + 1);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: &candidates.m_Memory.m_pMemory[v6],
            elem: candidates.m_Memory.m_pMemory[v6].m_Size,
            &src);
          src.m_Storage.m_nActualLength = 0;
          if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
              src.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            src.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
      }
LABEL_22:
      pFileNode = (fileNode_s *)((char *)pFileNode + 32);
      ++i;
    }
    while ( i < fileList.m_Size );
  }
  CUtlBuffer::CUtlBuffer(this: &script, growSize: 0, initSize: 0, nFlags: 1);
  if ( candidates.m_Size > 0 )
  {
    j = (int)outputFiles.m_Memory.m_pMemory;
    p_m_Size = &candidates.m_Memory.m_pMemory->m_Size;
    pGameDir = nullptr;
    i = (char *)outputFiles.m_Memory.m_pMemory - (char *)candidates.m_Memory.m_pMemory;
    v69 = candidates.m_Size;
    while ( 1 )
    {
      v11 = 0;
      v12 = CUtlString::operator char const *(this: (CUtlString *)&pGameDir[(unsigned int)g_GameDirTable.m_Memory.m_pMemory]);
      DvdDevLog(strFormat: "\nGameDir: %s\n", v12);
      memset(&script.m_Get, 0, 9);
      script.m_nOffset = 0;
      script.m_nMaxPut = 0;
      if ( script.m_Memory.m_nGrowSize >= 0 )
      {
        if ( script.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: script.m_Memory.m_pMemory);
          script.m_Memory.m_pMemory = nullptr;
        }
        script.m_Memory.m_nAllocationCount = 0;
      }
      if ( *p_m_Size > 0 )
      {
        pFileNode = nullptr;
        do
        {
          v13 = CUtlString::operator char const *(this: (CUtlString *)((char *)pFileNode + *(p_m_Size - 3)));
          DvdDevLog(strFormat: "  %s\n", v13);
          v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v55, pszFormat: "\"%s\"\n", v13);
          CUtlBuffer::PutString(this: &script, pString: v14->m_szBuf);
          pFileNode = (fileNode_s *)((char *)pFileNode + 16);
          ++v11;
        }
        while ( v11 < *p_m_Size );
      }
      if ( script.m_Put == 0 )
        goto LABEL_33;
      v15 = CUtlString::operator char const *(this: (CUtlString *)&pGameDir[(unsigned int)g_GameDirTable.m_Memory.m_pMemory]);
      V_ComposeFileName(path: v15, filename: "dvddev.tmp", dest: szScriptPath, destSize: 260);
      if ( Sys_SaveFile(filename: szScriptPath, buffer: script.m_Memory.m_pMemory, count: script.m_Put, bText: 1) == 0 )
      {
        ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Failed to create: %s\n", szScriptPath);
        goto LABEL_59;
      }
      DvdDevLog(strFormat: "Created: %s\n", szScriptPath);
      v16 = CUtlString::operator char const *(this: (CUtlString *)&pGameDir[(unsigned int)g_GameDirTable.m_Memory.m_pMemory]);
      if ( DoConversionProcess(pszModDir: v16, pszLogName: "makegamedata.log", pszScriptName: "dvddev.tmp", bForce) != 0 )
        break;
LABEL_59:
      pGameDir += 16;
      j += 20;
      p_m_Size += 5;
      if ( --v69 == 0 )
        goto LABEL_60;
    }
    v17 = CUtlString::operator char const *(this: (CUtlString *)&pGameDir[(unsigned int)g_GameDirTable.m_Memory.m_pMemory]);
    V_ComposeFileName(path: v17, filename: "makegamedata.log", dest: &v56.m_szBuf[3], destSize: 260);
    DvdDevLog(strFormat: "Results: %s\n", &v56.m_szBuf[3]);
    File = Sys_LoadFile(filename: &v56.m_szBuf[3], bufferptr: (void **)&pDvdDevFile, bText: true);
    if ( File > 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &results, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::SetExternalBuffer(
        this: &results,
        pMemory: (void *)pDvdDevFile,
        nSize: File,
        nInitialPut: File,
        nFlags: 1);
      CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: &defValue);
      if ( CUtlBuffer::ParseToken(
             this: &results,
             pBreaks: &breakSet,
             pTokenBuf: szLocalPath,
             nMaxLen: 260,
             bParseComments: true) > 0 )
      {
        v19 = (CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> *)j;
        do
        {
          DvdDevLog(strFormat: "  %s\n", szLocalPath);
          bFixed = FixupFATXFilename(pFilename: szLocalPath, pOutFilename: &v55.m_szBuf[3], nOutSize: 260);
          CUtlString::CUtlString(this: &outFile.m_sName);
          CUtlString::CUtlString(this: &outFile.m_sFixedName);
          CUtlString::operator=(this: &outFile.m_sName, src: szLocalPath);
          v20 = &v55.m_szBuf[3];
          if ( !bFixed )
            v20 = szLocalPath;
          CUtlString::operator=(this: &outFile.m_sFixedName, src: v20);
          outFile.m_bFixed = bFixed;
          v21 = *(int *)((char *)p_m_Size + i);
          m_nAllocationCount = v19->m_nAllocationCount;
          if ( v21 + 1 > m_nAllocationCount )
            _Grow___CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H__QAEXH_Z(
              this: v19,
              num: v21 - m_nAllocationCount + 1);
          v23 = i;
          ++*(int *)((char *)p_m_Size + i);
          m_pMemory = v19->m_pMemory;
          v25 = *(int *)((char *)p_m_Size + v23) - v21 - 1;
          v19[1].m_nAllocationCount = (int)v19->m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 36 * v25);
          v26 = (int)&v19->m_pMemory[v21];
          if ( v26 != 0 )
          {
            CUtlString::CUtlString(this: (CUtlString *)v26, string: &outFile.m_sName);
            CUtlString::CUtlString(this: (CUtlString *)(v26 + 16), string: &outFile.m_sFixedName);
            *(_BYTE *)(v26 + 32) = outFile.m_bFixed;
          }
          outFile.m_sFixedName.m_Storage.m_nActualLength = 0;
          if ( outFile.m_sFixedName.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( outFile.m_sFixedName.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outFile.m_sFixedName.m_Storage.m_Memory.m_pMemory);
              outFile.m_sFixedName.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            outFile.m_sFixedName.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          outFile.m_sName.m_Storage.m_nActualLength = 0;
          if ( outFile.m_sName.m_Storage.m_Memory.m_nGrowSize >= 0
            && outFile.m_sName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outFile.m_sName.m_Storage.m_Memory.m_pMemory);
          }
        }
        while ( CUtlBuffer::ParseToken(
                  this: &results,
                  pBreaks: &breakSet,
                  pTokenBuf: szLocalPath,
                  nMaxLen: 260,
                  bParseComments: true) > 0 );
      }
      if ( results.m_Memory.m_nGrowSize >= 0 && results.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: results.m_Memory.m_pMemory);
      goto LABEL_59;
    }
LABEL_33:
    DvdDevLog(strFormat: "  (Empty)\n");
    goto LABEL_59;
  }
LABEL_60:
  V_ComposeFileName(path: g_targetPath, filename: "dvddev", dest: szDvdDevPath, destSize: 260);
  v27 = g_pTargetFileDetails;
  for ( pFileNode = g_pTargetFileDetails; v27 != nullptr; pFileNode = v27 )
  {
    v28 = StringAfterPrefix(str: v27->filename, prefix: szDvdDevPath);
    v29 = (v27->attributes & 0x10) == 0;
    v30 = v28;
    pDvdDevFile = v28;
    if ( v29 && v28 != nullptr )
    {
      v31 = false;
      v69 = 0;
      i = 0;
      pGameDir = (const char *)outputFiles.m_Memory.m_pMemory;
      while ( v69 < g_GameDirTable.m_Size )
      {
        v32 = CUtlString::operator char const *(this: (CUtlString *)((char *)g_GameDirTable.m_Memory.m_pMemory + i));
        v33 = StringAfterPrefix(str: v32, prefix: g_localPath);
        if ( v33 != nullptr && *v33 == 92 )
        {
          v34 = StringAfterPrefix(str: v30, prefix: v33);
          if ( v34 != nullptr && *v34 == 92 )
          {
            v35 = v34 + 1;
            j = 0;
            v36 = 0;
            do
            {
              if ( j >= *((_DWORD *)pGameDir + 3) )
                break;
              v37 = CUtlString::operator char const *(this: (CUtlString *)(*(_DWORD *)pGameDir + v36 + 16));
              v38 = _V_stricmp(s1: v37, s2: v35);
              v31 = v38 == 0;
              ++j;
              v36 += 36;
            }
            while ( v38 != 0 );
            v30 = pDvdDevFile;
          }
        }
        ++v69;
        i += 16;
        pGameDir += 20;
        if ( v31 )
        {
          v27 = pFileNode;
          goto LABEL_75;
        }
      }
      v27 = pFileNode;
      DvdDevLog(strFormat: "Deleting: %s\n", pFileNode->filename);
      DmDeleteFile(a1: v27->filename, a2: 0);
    }
LABEL_75:
    v27 = v27->nextPtr;
  }
  CUtlBuffer::CUtlBuffer(this: &excludeBuffer, growSize: 0, initSize: 0, nFlags: 1);
  DvdDevLog(strFormat: "\n");
  j = 0;
  if ( g_GameDirTable.m_Size > 0 )
  {
    pFileNode = nullptr;
    v39 = &outputFiles.m_Memory.m_pMemory->m_Size;
    while ( 1 )
    {
      v40 = CUtlString::operator char const *(this: (CUtlString *)((char *)pFileNode
                                                                 + (unsigned int)g_GameDirTable.m_Memory.m_pMemory));
      v41 = StringAfterPrefix(str: v40, prefix: g_localPath);
      pGameDir = v41;
      if ( v41 != nullptr && *v41 == 92 )
      {
        ++pGameDir;
        v42 = *v39 <= 0;
        v69 = 0;
        if ( !v42 )
          break;
      }
LABEL_96:
      pFileNode = (fileNode_s *)((char *)pFileNode + 16);
      v39 += 5;
      if ( ++j >= g_GameDirTable.m_Size )
        goto LABEL_97;
    }
    i = 0;
    pDvdDevFile = (const char *)(!bForce + 1);
    while ( 1 )
    {
      v43 = i;
      v44 = CUtlString::operator char const *(this: (CUtlString *)(i + *(v39 - 3)));
      v45 = CUtlString::operator char const *(this: (CUtlString *)((char *)g_GameDirTable.m_Memory.m_pMemory
                                                                 + (unsigned int)pFileNode));
      V_ComposeFileName(path: v45, filename: v44, dest: szLocalPath, destSize: 260);
      v46 = CUtlString::operator char const *(this: (CUtlString *)(*(v39 - 3) + v43 + 16));
      V_ComposeFileName(path: g_targetPath, filename: "dvddev", dest, destSize: 260);
      V_ComposeFileName(path: dest, filename: pGameDir, dest, destSize: 260);
      V_ComposeFileName(path: dest, filename: v46, dest, destSize: 260);
      v47 = FileSyncEx(
              localFilename: szLocalPath,
              targetFilename: dest,
              fileSyncMode: (int)pDvdDevFile,
              bVerbose: g_bDvdDevLog,
              bNoWrite: false);
      if ( v47 == -1 )
      {
        if ( g_bDvdDevLog )
          DvdDevLog(strFormat: "Error: %s -> %s\n", szLocalPath, dest);
        else
          ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV ERROR: Cannot copy '%s' to '%s'\n", szLocalPath, dest);
        goto LABEL_95;
      }
      if ( v47 == 0 )
        break;
      if ( v47 == 1 )
      {
        if ( g_bDvdDevLog )
          DvdDevLog(strFormat: "Copy: %s -> %s\n", szLocalPath, dest);
        else
          ConsoleWindowPrintf(rgb: 0, strFormat: "DVDDEV: Update %s\n", dest);
        goto LABEL_94;
      }
      if ( v47 >= 0 )
        goto LABEL_94;
LABEL_95:
      i += 36;
      if ( ++v69 >= *v39 )
        goto LABEL_96;
    }
    DvdDevLog(strFormat: "No Update: %s -> %s\n", szLocalPath, dest);
LABEL_94:
    V_ComposeFileName(path: pGameDir, filename: v44, dest: &v55.m_szBuf[3], destSize: 260);
    v48 = CFmtStrN<256>::CFmtStrN<256>(this: &v56, pszFormat: "\"%s\"\n", &v55.m_szBuf[3]);
    CUtlBuffer::PutString(this: &excludeBuffer, pString: v48->m_szBuf);
    goto LABEL_95;
  }
LABEL_97:
  if ( excludeBuffer.m_Put != 0 )
  {
    V_ComposeFileName(path: g_localPath, filename: "xbox_exclude_paths.txt", dest: &v56.m_szBuf[3], destSize: 260);
    V_ComposeFileName(
      path: g_targetPath,
      filename: "dvddev/xbox_exclude_paths.txt",
      dest: &v55.m_szBuf[3],
      destSize: 260);
    v49 = fopen(file: &v56.m_szBuf[3], mode: "wt");
    if ( v49 != nullptr )
    {
      fwrite(buffer: excludeBuffer.m_Memory.m_pMemory, size: 1u, count: excludeBuffer.m_Put, stream: v49);
      fclose(stream: v49);
      FileSyncEx(
        localFilename: &v56.m_szBuf[3],
        targetFilename: &v55.m_szBuf[3],
        fileSyncMode: 1,
        bVerbose: g_bDvdDevLog,
        bNoWrite: false);
    }
  }
  if ( excludeBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( excludeBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: excludeBuffer.m_Memory.m_pMemory);
      excludeBuffer.m_Memory.m_pMemory = nullptr;
    }
    excludeBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( script.m_Memory.m_nGrowSize >= 0 )
  {
    if ( script.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: script.m_Memory.m_pMemory);
      script.m_Memory.m_pMemory = nullptr;
    }
    script.m_Memory.m_nAllocationCount = 0;
  }
  _RemoveAll___CUtlVector_V__CUtlVector_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_V__CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H____V__CUtlMemory_V__CUtlVector_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_V__CUtlMemory_UoutFile_t__4__BuildCandidateScripts__YA_N_N_Z_H____H____QAEXXZ(this: &outputFiles);
  if ( outputFiles.m_Memory.m_nGrowSize >= 0 && outputFiles.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputFiles.m_Memory.m_pMemory);
  CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>::RemoveAll(this: &candidates);
  if ( candidates.m_Memory.m_nGrowSize >= 0 && candidates.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: candidates.m_Memory.m_pMemory);
  v50 = fileList.m_Memory.m_pMemory;
  fileList.m_Size = 0;
  if ( fileList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( fileList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
      v50 = nullptr;
      fileList.m_Memory.m_pMemory = nullptr;
    }
    fileList.m_Memory.m_nAllocationCount = 0;
  }
  fileList.m_pElements = v50;
  if ( fileList.m_Memory.m_nGrowSize >= 0 && v50 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004247C0
// Name: bool SyncDvdDevCache(bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SyncDvdDevCache(bool bForce)
{
  if ( SetupP4() == 0 )
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "DVDDEV: Valid file serving not possible.\n");
    return 0;
  }
  if ( GetTargetDetails() == 0 )
    return 0;
  return BuildCandidateScripts(bForce);
}
