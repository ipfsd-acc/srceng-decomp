// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/stack_translation.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00422160
// Name: bool RecursivePDBCopy(class CProgress __near *,char const __near *,char __near *,int,char const __near *,char __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RecursivePDBCopy(
        CProgress *pProgress,
        const char *szDestPath,
        char *pDestWritePosition,
        int iDestLengthRemaining,
        const char *szSourcePath,
        char *pSourceWritePosition,
        int iSourceLengthRemaining,
        int *iCopyCount)
{
  HANDLE FirstFileA; // eax
  signed int v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // esi
  int v13; // esi
  unsigned int v14; // esi
  void *v15; // esi
  char statusBuff1[128]; // [esp+14h] [ebp-1ECh] BYREF
  _WIN32_FIND_DATAA searchResults; // [esp+94h] [ebp-16Ch] BYREF
  _WIN32_FILE_ATTRIBUTE_DATA fileAttributes; // [esp+1D4h] [ebp-2Ch] BYREF
  float sourceFileSize; // [esp+1F8h] [ebp-8h]
  void *hSearch; // [esp+1FCh] [ebp-4h]
  char bFirstCopy_3; // [esp+21Fh] [ebp+1Fh]

  V_strncpy(pDest: pSourceWritePosition, pSrc: "*.*", maxLen: iSourceLengthRemaining);
  FirstFileA = FindFirstFileA(lpFileName: szSourcePath, lpFindFileData: &searchResults);
  hSearch = FirstFileA;
  *pSourceWritePosition = 0;
  if ( FirstFileA == (HANDLE)-1 )
    return 1;
  bFirstCopy_3 = 1;
  while ( (searchResults.dwFileAttributes & 0x10) != 0 )
  {
    if ( searchResults.cFileName[0] != 46
      || searchResults.cFileName[1] != 0 && (searchResults.cFileName[1] != 46 || searchResults.cFileName[2] != 0) )
    {
      v10 = _V_strlen(str: searchResults.cFileName);
      v11 = v10;
      if ( v10 >= iDestLengthRemaining )
        goto LABEL_24;
      if ( v10 >= iSourceLengthRemaining )
        goto LABEL_24;
      memcpy(dst: (unsigned __int8 *)pDestWritePosition, src: (unsigned __int8 *)searchResults.cFileName, count: v10);
      memcpy(dst: (unsigned __int8 *)pSourceWritePosition, src: (unsigned __int8 *)searchResults.cFileName, count: v11);
      pDestWritePosition[v11] = 92;
      pSourceWritePosition[v11] = 92;
      v12 = v11 + 1;
      pDestWritePosition[v12] = 0;
      pSourceWritePosition[v12] = 0;
      if ( !RecursivePDBCopy(
              pProgress,
              szDestPath,
              pDestWritePosition: &pDestWritePosition[v12],
              iDestLengthRemaining: iDestLengthRemaining - v12,
              szSourcePath,
              pSourceWritePosition: &pSourceWritePosition[v12],
              iSourceLengthRemaining: iSourceLengthRemaining - v12,
              iCopyCount) )
        goto LABEL_24;
LABEL_20:
      *pDestWritePosition = 0;
      *pSourceWritePosition = 0;
    }
LABEL_21:
    v15 = hSearch;
    if ( !FindNextFileA(hFindFile: hSearch, lpFindFileData: &searchResults) )
    {
      FindClose(hFindFile: v15);
      return 1;
    }
  }
  v13 = _V_strlen(str: searchResults.cFileName);
  if ( v13 <= 4 || _V_stricmp(s1: (const char *)&searchResults.dwReserved1 + v13, s2: ".pdb") != 0 )
    goto LABEL_21;
  if ( bFirstCopy_3 != 0 )
  {
    Sys_CreatePath(pInPath: szDestPath);
    bFirstCopy_3 = 0;
  }
  v14 = v13 + 1;
  memcpy(dst: (unsigned __int8 *)pDestWritePosition, src: (unsigned __int8 *)searchResults.cFileName, count: v14);
  memcpy(dst: (unsigned __int8 *)pSourceWritePosition, src: (unsigned __int8 *)searchResults.cFileName, count: v14);
  sourceFileSize = 0.0;
  if ( GetFileAttributesExA(
         lpFileName: szSourcePath,
         fInfoLevelId: GetFileExInfoStandard,
         lpFileInformation: &fileAttributes) )
  {
    sourceFileSize = (double)fileAttributes.nFileSizeLow * 0.00000095367432;
  }
  V_snprintf(
    pDest: statusBuff1,
    maxLen: 128,
    pFormat: "Copying PDB to local disk (%.2f MB) ... Please Wait",
    sourceFileSize);
  CProgress::SetStatus(this: pProgress, line1: statusBuff1, line2: szSourcePath, line3: szDestPath);
  if ( CopyFileA(lpExistingFileName: szSourcePath, lpNewFileName: szDestPath, bFailIfExists: false) )
  {
    ++*iCopyCount;
    goto LABEL_20;
  }
LABEL_24:
  FindClose(hFindFile: hSearch);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004223D0
// Name: bool StackTranslation_CopyDVDPDBsToLocalFolder(char const __near *,class CProgress __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl StackTranslation_CopyDVDPDBsToLocalFolder(
        const char *pDVDImagePath,
        CProgress *pProgress,
        int *pNumPDBsCopied)
{
  int v4; // esi
  char v5; // al
  int v6; // esi
  int v7; // ebx
  char *v8; // edi
  const char *v9; // edi
  int v10; // ebx
  int v11; // edi
  char *v12; // ebx
  int *p_iDummyCount; // eax
  int v14; // [esp-20h] [ebp-330h]
  char szImageName[260]; // [esp+0h] [ebp-310h] BYREF
  char szDestinationPath[260]; // [esp+104h] [ebp-20Ch] BYREF
  char szSourcePath[260]; // [esp+208h] [ebp-108h] BYREF
  int iDummyCount; // [esp+30Ch] [ebp-4h] BYREF

  if ( g_localPath[0] == 0 )
    return 0;
  v4 = _V_strlen(str: g_localPath);
  memcpy(dst: (unsigned __int8 *)szDestinationPath, src: (unsigned __int8 *)g_localPath, count: v4 + 1);
  for ( ; v4 > 0; szDestinationPath[v4] = 0 )
  {
    v5 = szDestinationPath[v4 - 1];
    if ( v5 != 92 && v5 != 47 )
      break;
    --v4;
  }
  v6 = V_snprintf(pDest: &szDestinationPath[v4], maxLen: 260 - v4, pFormat: "\\X360_DVD_PDBs\\") + v4;
  V_strncpy(pDest: szSourcePath, pSrc: pDVDImagePath, maxLen: 260);
  v7 = _V_strlen(str: szSourcePath);
  v8 = &szSourcePath[v7];
  if ( &szSourcePath[v7] >= szSourcePath )
  {
    while ( *v8 != 92 && *v8 != 47 )
    {
      if ( --v8 < szSourcePath )
        goto LABEL_14;
    }
    v9 = v8 + 1;
    if ( V_strnicmp(s1: v9, s2: "DVD_", n: 4) != 0 )
      return 0;
    V_strncpy(pDest: szImageName, pSrc: v9, maxLen: 260);
    v7 = v9 - szSourcePath;
    *v9 = 0;
  }
LABEL_14:
  v10 = V_snprintf(pDest: &szSourcePath[v7], maxLen: 260 - v7, pFormat: "PDBs\\%s\\", szImageName) + v7;
  v11 = 260 - v10;
  v14 = 260 - v10;
  v12 = &szSourcePath[v10];
  V_strncpy(pDest: v12, pSrc: "default.pdb", maxLen: v14);
  if ( Sys_Exists(filename: szSourcePath) == 0 )
    return 0;
  p_iDummyCount = pNumPDBsCopied;
  *v12 = 0;
  iDummyCount = 0;
  if ( pNumPDBsCopied == nullptr )
    p_iDummyCount = &iDummyCount;
  return RecursivePDBCopy(
           pProgress,
           szDestPath: szDestinationPath,
           pDestWritePosition: &szDestinationPath[v6],
           iDestLengthRemaining: 260 - v6,
           szSourcePath,
           pSourceWritePosition: v12,
           iSourceLengthRemaining: v11,
           iCopyCount: p_iDummyCount);
}

//------------------------------------------------------------------------------
// Address: 0x00422610
// Name: void StackTranslation_UnloadSymbols(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StackTranslation_UnloadSymbols()
{
  int v0; // edi
  int v1; // esi

  v0 = 0;
  if ( g_LoadedPDBs.m_Size != 0 )
  {
    v1 = 0;
    do
    {
      DmUnloadSymbolsForModule(a1: g_LoadedPDBs.m_Memory.m_pMemory[v1].modLoad.BaseAddress);
      ++v0;
      ++v1;
    }
    while ( v0 != g_LoadedPDBs.m_Size );
    g_LoadedPDBs.m_Size = 0;
    s_bReloadSymbols = 1;
  }
  else
  {
    g_LoadedPDBs.m_Size = 0;
    s_bReloadSymbols = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422680
// Name: bool X360GetModuleNameFromAddress(void __near *,char __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl X360GetModuleNameFromAddress(void *pAddress, char *ModuleName, unsigned int BufferSize)
{
  int m_Size; // ecx
  int v5; // esi
  int v6; // eax
  SymbolInfoStructs_t *v7; // eax

  m_Size = g_LoadedPDBs.m_Size;
  if ( g_LoadedPDBs.m_Size == 0 )
    return 0;
  v5 = 0;
  if ( g_LoadedPDBs.m_Size > 0 )
  {
    do
    {
      v6 = (v5 + m_Size) >> 1;
      if ( pAddress >= g_LoadedPDBs.m_Memory.m_pMemory[v6].modLoad.BaseAddress )
      {
        if ( pAddress < g_LoadedPDBs.m_Memory.m_pMemory[v6].pEndAddress )
        {
          V_strncpy(pDest: ModuleName, pSrc: g_LoadedPDBs.m_Memory.m_pMemory[v6].modLoad.Name, maxLen: BufferSize);
          return 1;
        }
        v5 = v6 + 1;
      }
      else
      {
        m_Size = (v5 + m_Size) >> 1;
      }
    }
    while ( v5 < m_Size );
    if ( m_Size < g_LoadedPDBs.m_Size )
    {
      v7 = &g_LoadedPDBs.m_Memory.m_pMemory[m_Size];
      if ( pAddress > v7->modLoad.BaseAddress && pAddress < v7->pEndAddress )
      {
        V_strncpy(pDest: ModuleName, pSrc: g_LoadedPDBs.m_Memory.m_pMemory[m_Size].modLoad.Name, maxLen: BufferSize);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004227B0
// Name: void LoadDebugInfoForModules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadDebugInfoForModules()
{
  int v0; // esi
  void **p_BaseAddress; // eax
  int v2; // edi
  int m_Size; // eax
  int v4; // eax
  void **v5; // ecx
  SymbolInfoStructs_t symbolInfoStruct; // [esp+0h] [ebp-244h] BYREF
  _DM_WALK_MODULES *pWalkMod; // [esp+240h] [ebp-4h] BYREF

  if ( !g_connectedToApp )
  {
    StackTranslation_UnloadSymbols();
    return;
  }
  pWalkMod = nullptr;
  while ( DmWalkLoadedModules(a1: &pWalkMod, a2: &symbolInfoStruct) == 47841280 )
  {
    v0 = g_LoadedPDBs.m_Size - 1;
    if ( g_LoadedPDBs.m_Size - 1 >= 0 )
    {
      p_BaseAddress = &g_LoadedPDBs.m_Memory.m_pMemory[v0].modLoad.BaseAddress;
      while ( *p_BaseAddress != symbolInfoStruct.modLoad.BaseAddress )
      {
        p_BaseAddress -= 144;
        if ( --v0 < 0 )
          goto LABEL_16;
      }
      v2 = v0;
      if ( g_LoadedPDBs.m_Memory.m_pMemory[v0].modLoad.CheckSum == symbolInfoStruct.modLoad.CheckSum
        && g_LoadedPDBs.m_Memory.m_pMemory[v2].modLoad.TimeStamp == symbolInfoStruct.modLoad.TimeStamp
        && g_LoadedPDBs.m_Memory.m_pMemory[v2].modLoad.Size == symbolInfoStruct.modLoad.Size )
      {
        continue;
      }
      DmUnloadSymbolsForModule(a1: g_LoadedPDBs.m_Memory.m_pMemory[v2].modLoad.BaseAddress);
      m_Size = g_LoadedPDBs.m_Size;
      if ( g_LoadedPDBs.m_Size > 0 )
      {
        if ( v0 != g_LoadedPDBs.m_Size - 1 )
        {
          qmemcpy(
            &g_LoadedPDBs.m_Memory.m_pMemory[v2],
            &g_LoadedPDBs.m_Memory.m_pMemory[g_LoadedPDBs.m_Size - 1],
            sizeof(g_LoadedPDBs.m_Memory.m_pMemory[v2]));
          m_Size = g_LoadedPDBs.m_Size;
        }
        g_LoadedPDBs.m_Size = m_Size - 1;
      }
    }
LABEL_16:
    if ( DmFindPdbSignature(a1: symbolInfoStruct.modLoad.BaseAddress, a2: &symbolInfoStruct.pdbSignature) == 47841280
      && DmLoadSymbolsForModuleEx(
           a1: &symbolInfoStruct,
           a2: symbolInfoStruct.modLoad.BaseAddress,
           a3: symbolInfoStruct.modLoad.Size,
           a4: symbolInfoStruct.modLoad.TimeStamp,
           a5: &symbolInfoStruct.pdbSignature) == 47841280 )
    {
      symbolInfoStruct.pEndAddress = (char *)symbolInfoStruct.modLoad.BaseAddress + symbolInfoStruct.modLoad.Size;
      v4 = 0;
      if ( g_LoadedPDBs.m_Size != 0 )
      {
        v5 = &g_LoadedPDBs.m_Memory.m_pMemory->modLoad.BaseAddress;
        while ( *v5 <= symbolInfoStruct.modLoad.BaseAddress )
        {
          ++v4;
          v5 += 144;
          if ( v4 == g_LoadedPDBs.m_Size )
            goto LABEL_22;
        }
        CUtlVector<SymbolInfoStructs_t,CUtlMemory<SymbolInfoStructs_t,int>>::InsertBefore(
          this: &g_LoadedPDBs,
          elem: v4,
          src: &symbolInfoStruct);
      }
      else
      {
LABEL_22:
        CUtlVector<SymbolInfoStructs_t,CUtlMemory<SymbolInfoStructs_t,int>>::InsertBefore(
          this: &g_LoadedPDBs,
          elem: g_LoadedPDBs.m_Size,
          src: &symbolInfoStruct);
      }
    }
  }
  DmCloseLoadedModules(a1: pWalkMod);
  s_bReloadSymbols = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422970
// Name: bool StackTranslation_TranslatePointer(unsigned long,char __near *,int,enum TranslateStackInfo_StyleFlags_t)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StackTranslation_TranslatePointer(
        void *pAddress,
        char *pTranslationOut,
        int iTranslationBufferLength,
        TranslateStackInfo_StyleFlags_t style)
{
  char *v4; // edi
  int v6; // ebx
  bool v7; // zf
  char *v8; // esi
  unsigned int v9; // eax
  char v10; // cl
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edi
  char *v14; // eax
  int i; // edx
  signed int v16; // eax
  char v17; // cl
  char szFileName[260]; // [esp+4h] [ebp-108h] BYREF
  unsigned int dwDisplacement; // [esp+108h] [ebp-4h] BYREF

  v4 = pTranslationOut;
  if ( pTranslationOut == nullptr )
    return false;
  v6 = iTranslationBufferLength;
  if ( iTranslationBufferLength <= 0 )
    return false;
  if ( s_bReloadSymbols != 0 )
    LoadDebugInfoForModules();
  v7 = (style & 1) == 0;
  v8 = v4;
  *v4 = 0;
  if ( !v7 )
  {
    if ( X360GetModuleNameFromAddress(pAddress, ModuleName: v4, BufferSize: v6) == 0 )
      V_strncpy(pDest: v4, pSrc: "unknown_module", maxLen: v6);
    v9 = strlen(v4);
    v6 -= v9;
    v8 = &v4[v9];
    if ( v6 < 2 )
      return false;
    if ( (style & 2) != 0 )
    {
      *v8++ = 33;
      --v6;
      *v8 = v10;
    }
  }
  v11 = v6;
  if ( v6 >= 260 )
    v11 = 260;
  if ( DmGetSymbolFromAddress(a1: pAddress, a2: v8, a3: v11, a4: &dwDisplacement) != 47841280 )
  {
    _snprintf(string: v8, count: v6, format: "0x%p", pAddress);
    return (int)strlen(v8) < v6;
  }
  if ( (style & 2) != 0 )
  {
    v12 = strlen(v8);
    v8 += v12;
    v6 -= v12;
  }
  else
  {
    *v8 = 0;
  }
  if ( (style & 0x3C) == 0 )
    return (int)strlen(v8) < v6;
  if ( v8 != v4 )
  {
    if ( v6 < 6 )
      return false;
    *(_DWORD *)v8 = 2108704;
    v8 += 3;
    v6 -= 3;
  }
  if ( DmGetSourceLineFromAddress(a1: pAddress, a2: szFileName, a3: 260, a4: &pTranslationOut) == 47841280 )
  {
    if ( (style & 4) != 0 )
    {
      v13 = strlen(szFileName);
      memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)szFileName, count: v13 + 1);
LABEL_37:
      v8 += v13;
      v6 -= v13;
LABEL_38:
      if ( (style & 0x30) != 0 )
        _snprintf(string: v8, count: v6, format: "(%d)", pTranslationOut);
      return (int)strlen(v8) < v6;
    }
    if ( (style & 8) == 0 )
      goto LABEL_38;
    v14 = &szFileName[strlen(szFileName)];
    for ( i = 3; v14 > szFileName; --v14 )
    {
      if ( (*v14 == 92 || *v14 == 47) && --i == 0 )
        break;
    }
    v16 = strlen(v14);
    v13 = v16;
    if ( v6 > v16 )
    {
      memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)szFileName, count: v16 + 1);
      goto LABEL_37;
    }
    *(v8 - 3) = v17;
    return false;
  }
  v8 -= 3;
  v6 += 3;
  *v8 = 0;
  return (int)strlen(v8) < v6;
}

//------------------------------------------------------------------------------
// Address: 0x00422BB0
// Name: unsigned long StackTranslation_GetTranslationInfoHandler(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl StackTranslation_GetTranslationInfoHandler(
        unsigned __int8 *pData,
        int iDataSize,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  int v27; // ebx
  int *v28; // eax
  unsigned int v29; // edx
  unsigned __int8 *v30; // edi
  unsigned int v31; // esi
  void *v32; // esp
  FullStackInfo_t *v33; // ecx
  char *v34; // esi
  void *v35; // edi
  _BYTE v37[12]; // [esp+0h] [ebp-2Ch] BYREF
  unsigned int iByteCount; // [esp+Ch] [ebp-20h]
  FullStackInfo_t *pStackInfoTemp; // [esp+10h] [ebp-1Ch]
  unsigned int v40; // [esp+14h] [ebp-18h]
  int *pRetValWrite; // [esp+18h] [ebp-14h]
  FullStackInfo_t *pTranslateWrite; // [esp+1Ch] [ebp-10h]
  unsigned int iRequestCount; // [esp+20h] [ebp-Ch]
  unsigned int offset; // [esp+24h] [ebp-8h] BYREF
  int iTranslated; // [esp+28h] [ebp-4h] BYREF
  unsigned __int8 *pDataa; // [esp+34h] [ebp+8h]

  v27 = 0;
  if ( s_bReloadSymbols != 0 )
    LoadDebugInfoForModules();
  if ( (unsigned int)iDataSize < 8 )
    goto LABEL_21;
  v28 = *(int **)pData;
  iTranslated = 0;
  pRetValWrite = v28;
  v29 = *((_DWORD *)pData + 1);
  v30 = pData + 8;
  pRetValWrite = (int *)_byteswap_ulong((unsigned int)v28);
  pDataa = pData + 8;
  v31 = _byteswap_ulong(v29);
  iRequestCount = v31;
  if ( iDataSize < (int)(4 * v31 + 12) )
    goto LABEL_21;
  pTranslateWrite = (FullStackInfo_t *)_byteswap_ulong(*(_DWORD *)&v30[4 * v31]);
  iByteCount = 230 * v31;
  v32 = alloca(230 * v31);
  v33 = (FullStackInfo_t *)v37;
  pStackInfoTemp = (FullStackInfo_t *)v37;
  if ( v31 != 0 )
  {
    v34 = (char *)&a27 + 2;
    while ( 1 )
    {
      *(_DWORD *)(v34 - 158) = *(_DWORD *)&v30[4 * v27];
      v40 = *(_DWORD *)&v30[4 * v27];
      v35 = (void *)_byteswap_ulong(v40);
      if ( X360GetModuleNameFromAddress(pAddress: v35, ModuleName: v34 - 154, BufferSize: 0x18u) == 0 )
        *(v34 - 154) = 0;
      if ( DmGetSymbolFromAddress(a1: v35, a2: v34, a3: 64, a4: &offset) == 47841280 )
      {
        *((_DWORD *)v34 + 17) = _byteswap_ulong(offset);
      }
      else
      {
        *v34 = 0;
        *((_DWORD *)v34 + 17) = 0;
      }
      if ( DmGetSourceLineFromAddress(a1: v35, a2: v34 - 130, a3: 130, a4: &iDataSize) == 47841280 )
      {
        *((_DWORD *)v34 + 16) = _byteswap_ulong(iDataSize);
      }
      else
      {
        *(v34 - 130) = 0;
        *((_DWORD *)v34 + 16) = 0;
      }
      ++v27;
      v34 += 230;
      if ( v27 == iRequestCount )
        break;
      v30 = pDataa;
    }
    v33 = pStackInfoTemp;
  }
  iTranslated = _byteswap_ulong(iRequestCount);
  if ( SetXboxMemory(pWriteAddress: pTranslateWrite, pSource: v33, iByteCount) != 0
    && SetXboxMemory(pWriteAddress: pRetValWrite, pSource: &iTranslated, iByteCount: 4u) != 0 )
  {
    CommandCompleted(errCode: 0);
    return 0;
  }
  else
  {
LABEL_21:
    CommandCompleted(errCode: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422D60
// Name: unsigned long StackTranslation_BinaryHandler(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None
