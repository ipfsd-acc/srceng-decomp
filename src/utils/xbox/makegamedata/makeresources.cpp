// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makeresources.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040ED00
// Name: bool CreateTargetFile_CCDAT(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_CCDAT(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  bool v3; // bl
  CUtlBuffer targetBuffer; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  v3 = false;
  if ( ReadFileToBuffer(pSourceName, buffer: &targetBuffer, bText: false, bNoOpenFailureWarning: false) )
  {
    if ( SwapClosecaptionFile(pData: targetBuffer.m_Memory.m_pMemory) )
      v3 = WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
    return v3;
  }
  else
  {
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F110
// Name: bool FindOrAddFileToResourceList(char const __near *,class CUtlRBTree<class CUtlString,int,bool (*)(class CUtlString const __near &,class CUtlString const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CUtlString,int>,int>> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindOrAddFileToResourceList(
        const char *pFilename,
        CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > *pTree,
        bool bAdd)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  bool v8; // bl
  int v10; // eax
  char *v11; // edx
  int v12; // edi
  UtlRBTreeNode_t<CUtlString,int> *v13; // ecx
  UtlRBTreeNode_t<CUtlString,int> *m_pMemory; // ecx
  int v15; // edx
  UtlRBTreeNode_t<CUtlString,int> *v16; // edx
  char szOutName[260]; // [esp+Ch] [ebp-11Ch] BYREF
  CUtlString search; // [esp+110h] [ebp-18h] BYREF
  char *pOutName; // [esp+120h] [ebp-8h] BYREF
  bool leftchild; // [esp+127h] [ebp-1h] BYREF

  V_strncpy(pDest: szOutName, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: szOutName, separator: 92);
  V_RemoveDotSlashes(pFilename: szOutName, separator: 92);
  _V_strlower(start: szOutName);
  v3 = 0;
  pOutName = szOutName;
  if ( g_GameNames.m_Size > 0 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = strlen(CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v4]));
      v6 = CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v4]);
      if ( V_strnicmp(s1: szOutName, s2: v6, n: v5) == 0 && szOutName[v5] == 92 )
      {
        pOutName = &szOutName[v5 + 1];
        goto LABEL_12;
      }
      v7 = CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v4]);
      if ( V_strnicmp(s1: szOutName, s2: v7, n: v5) == 0
        && V_strnicmp(s1: &szOutName[v5], s2: "_tempcontent", n: 12) == 0
        && szOutName[v5 + 12] == 92 )
      {
        break;
      }
      ++v3;
      ++v4;
      if ( v3 >= g_GameNames.m_Size )
        goto LABEL_12;
    }
    pOutName = &szOutName[v5 + 13];
  }
LABEL_12:
  CUtlString::CUtlString(this: &search, pString: pOutName);
  v8 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
         this: pTree,
         &search) != -1;
  search.m_Storage.m_nActualLength = 0;
  if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
  if ( v8 )
    return 1;
  if ( bAdd )
  {
    CUtlString::CUtlString(this: &search, pString: pOutName);
    pOutName = (char *)-1;
    leftchild = false;
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FindInsertionPosition(
      this: pTree,
      insert: &search,
      parent: (int *)&pOutName,
      &leftchild);
    v10 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NewNode(this: pTree);
    v11 = pOutName;
    v12 = v10;
    v13 = &pTree->m_Elements.m_pMemory[v10];
    v13->m_Parent = (int)pOutName;
    v13->m_Right = -1;
    v13->m_Left = -1;
    v13->m_Tag = 0;
    if ( v11 == (char *)-1 )
    {
      pTree->m_Root = v10;
    }
    else
    {
      m_pMemory = pTree->m_Elements.m_pMemory;
      v15 = (int)v11;
      if ( leftchild )
        m_pMemory[v15].m_Left = v10;
      else
        m_pMemory[v15].m_Right = v10;
    }
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::InsertRebalance(
      this: pTree,
      elem: v10);
    v16 = pTree->m_Elements.m_pMemory;
    ++pTree->m_NumElements;
    if ( &v16[v12] != (UtlRBTreeNode_t<CUtlString,int> *)-16 )
      CUtlString::CUtlString(this: &v16[v12].m_Data, string: &search);
    search.m_Storage.m_nActualLength = 0;
    if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040F350
// Name: bool RemoveFileFromResourceList(char const __near *,class CUtlRBTree<class CUtlString,int,bool (*)(class CUtlString const __near &,class CUtlString const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CUtlString,int>,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RemoveFileFromResourceList(
        const char *pFilename,
        CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > *pTree)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  bool v7; // bl
  int v8; // eax
  int v9; // edi
  char szOutName[260]; // [esp+Ch] [ebp-118h] BYREF
  CUtlString search; // [esp+110h] [ebp-14h] BYREF
  char *pOutName; // [esp+120h] [ebp-4h]

  V_strncpy(pDest: szOutName, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: szOutName, separator: 92);
  V_RemoveDotSlashes(pFilename: szOutName, separator: 92);
  _V_strlower(start: szOutName);
  v2 = 0;
  pOutName = szOutName;
  if ( g_GameNames.m_Size > 0 )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = strlen(CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v3]));
      v5 = CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v3]);
      if ( V_strnicmp(s1: szOutName, s2: v5, n: v4) == 0 && szOutName[v4] == 92 )
      {
        pOutName = &szOutName[v4 + 1];
        goto LABEL_12;
      }
      v6 = CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v3]);
      if ( V_strnicmp(s1: szOutName, s2: v6, n: v4) == 0
        && V_strnicmp(s1: &szOutName[v4], s2: "_tempcontent", n: 12) == 0
        && szOutName[v4 + 12] == 92 )
      {
        break;
      }
      ++v2;
      ++v3;
      if ( v2 >= g_GameNames.m_Size )
        goto LABEL_12;
    }
    pOutName = &szOutName[v4 + 13];
  }
LABEL_12:
  CUtlString::CUtlString(this: &search, pString: pOutName);
  v7 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
         this: pTree,
         &search) != -1;
  search.m_Storage.m_nActualLength = 0;
  if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
  if ( !v7 )
    return 0;
  CUtlString::CUtlString(this: &search, pString: pOutName);
  v8 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
         this: pTree,
         &search);
  v9 = v8;
  if ( v8 != -1 )
  {
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Unlink(
      this: pTree,
      elem: v8);
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FreeNode(
      this: pTree,
      i: v9);
    --pTree->m_NumElements;
  }
  search.m_Storage.m_nActualLength = 0;
  if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F530
// Name: bool LoadReslist(char const __near *,class CUtlRBTree<class CUtlString,int,bool (*)(class CUtlString const __near &,class CUtlString const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CUtlString,int>,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadReslist(
        char *pReslistName,
        CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > *pTree)
{
  const char *FileExtension; // esi
  int v4; // eax
  char v5; // cl
  unsigned __int8 *m_pMemory; // eax
  bool v7; // zf
  int v8; // esi
  const char *v9; // eax
  const char *v10; // esi
  const char *v11; // eax
  const char *v12; // edi
  int i; // edi
  int v14; // esi
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  int v20; // esi
  int v21; // edi
  const char *v22; // eax
  int v23; // eax
  bool v24; // cc
  char v25; // al
  char *j; // ecx
  int v27; // eax
  CUtlString *v28; // eax
  CUtlString *v29; // eax
  char v30; // bl
  CUtlString *v31; // eax
  CUtlString *v32; // eax
  char s1[8192]; // [esp+4h] [ebp-27D8h] BYREF
  char out[260]; // [esp+2004h] [ebp-7D8h] BYREF
  char pDest[260]; // [esp+2108h] [ebp-6D4h] BYREF
  char pOutBuff[260]; // [esp+220Ch] [ebp-5D0h] BYREF
  char dest[260]; // [esp+2310h] [ebp-4CCh] BYREF
  char pBspName[260]; // [esp+2414h] [ebp-3C8h] BYREF
  characterset_t pSetBuffer; // [esp+2518h] [ebp-2C4h] BYREF
  char pTokenBuf[260]; // [esp+2618h] [ebp-1C4h] BYREF
  CUtlBuffer v41; // [esp+271Ch] [ebp-C0h] BYREF
  CUtlBuffer v42; // [esp+274Ch] [ebp-90h] BYREF
  CUtlBuffer buffer; // [esp+277Ch] [ebp-60h] BYREF
  int v44; // [esp+27ACh] [ebp-30h]
  int v45; // [esp+27B0h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > v46; // [esp+27B4h] [ebp-28h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > pList; // [esp+27C8h] [ebp-14h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName: pReslistName, &buffer, bText: true, bNoOpenFailureWarning: false) )
    goto LABEL_4;
  if ( buffer.m_Put == 0 )
  {
    _Warning(a1: "Bad Reslist File (0 bytes) '%s'\n", pReslistName);
LABEL_4:
    if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
    return 0;
  }
  V_FileBase(in: pReslistName, out, maxlen: 260);
  CharacterSetBuild(&pSetBuffer, pszSetString: pDefaultValue);
  pBspName[0] = 0;
  while ( CUtlBuffer::ParseToken(this: &buffer, pBreaks: &pSetBuffer, pTokenBuf, nMaxLen: 260, bParseComments: true) > 0 )
  {
    _V_strlower(start: pTokenBuf);
    V_FixSlashes(pname: pTokenBuf, separator: 92);
    V_RemoveDotSlashes(pFilename: pTokenBuf, separator: 92);
    FileExtension = V_GetFileExtension(path: pTokenBuf);
    if ( FileExtension != nullptr )
    {
      if ( V_stristr(pStr: pTokenBuf, pSearch: ".360.") != nullptr
        || V_stristr(pStr: pTokenBuf, pSearch: ".ps3.") != nullptr )
      {
        _Warning(a1: "Error! Unexpected console resource '%s' found in reslist '%s'\n.", pTokenBuf, pReslistName);
        continue;
      }
      if ( _V_stricmp(s1: FileExtension, s2: "vmt") == 0
        || _V_stricmp(s1: FileExtension, s2: "vhv") == 0
        || _V_stricmp(s1: FileExtension, s2: "mdl") == 0
        || _V_stricmp(s1: FileExtension, s2: "raw") == 0
        || _V_stricmp(s1: FileExtension, s2: "wav") == 0 )
      {
        goto LABEL_25;
      }
      if ( _V_stricmp(s1: FileExtension, s2: "mp3") != 0 )
      {
        if ( _V_stricmp(s1: FileExtension, s2: "bsp") != 0 || V_stristr(pStr: pTokenBuf, pSearch: out) == nullptr )
          continue;
        if ( V_stristr(pStr: pTokenBuf, pSearch: "platform\\") == nullptr )
        {
          v4 = 0;
          do
          {
            v5 = pTokenBuf[v4];
            pBspName[v4++] = v5;
          }
          while ( v5 != 0 );
LABEL_25:
          FindOrAddFileToResourceList(pFilename: pTokenBuf, pTree, bAdd: true);
          continue;
        }
        _Warning(a1: "Error! Unexpected BSP '%s' found in platform path\n.", pTokenBuf);
      }
      else
      {
        V_SetExtension(path: pTokenBuf, extension: ".wav", pathStringLength: 260);
        FindOrAddFileToResourceList(pFilename: pTokenBuf, pTree, bAdd: true);
      }
    }
  }
  if ( pBspName[0] == 0 )
  {
    if ( buffer.m_Memory.m_nGrowSize < 0 )
      return 1;
    m_pMemory = buffer.m_Memory.m_pMemory;
    v7 = buffer.m_Memory.m_pMemory == nullptr;
LABEL_141:
    if ( !v7 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 1;
  }
  v8 = 0;
  memset(&pList, 0, sizeof(pList));
  if ( GetDependants_BSP(a1: (int)pTree, pBspName, &pList) == 0 )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&pList);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &buffer);
    return 0;
  }
  v45 = 0;
  if ( pList.m_Size > 0 )
  {
    v44 = 0;
    do
    {
      v9 = CUtlString::operator char const *(this: (CUtlString *)((char *)pList.m_Memory.m_pMemory + v8));
      v10 = v9;
      if ( *v9 != 42 || V_stristr(pStr: v9, pSearch: ".phz") == nullptr )
      {
        if ( V_stristr(pStr: v10, pSearch: "simpleworldmodel") == nullptr
          || ((v11 = V_GetFileExtension(path: v10), v12 = v11, v11 == nullptr)
           || _V_stricmp(s1: v11, s2: "vtf") != 0
           && _V_stricmp(s1: v12, s2: "vvd") != 0
           && _V_stricmp(s1: v12, s2: "vtx") != 0)
          && V_stristr(pStr: pBspName, pSearch: "sp_a") == nullptr )
        {
          FindOrAddFileToResourceList(pFilename: v10, pTree, bAdd: true);
        }
      }
      v8 = v44 + 16;
      ++v45;
      v44 += 16;
    }
    while ( v45 < pList.m_Size );
  }
  memset(&v46, 0, sizeof(v46));
  for ( i = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FirstInorder(this: pTree);
        i != -1;
        i = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NextInorder(
              this: pTree,
              i) )
  {
    v14 = i;
    v15 = CUtlString::operator char const *(this: &pTree->m_Elements.m_pMemory[i].m_Data);
    v16 = V_GetFileExtension(path: v15);
    if ( v16 != nullptr && _V_stricmp(s1: v16, s2: "mdl") == 0 )
    {
      v17 = CUtlString::operator char const *(this: &pTree->m_Elements.m_pMemory[v14].m_Data);
      v18 = V_UnqualifiedFileName(pPath: v17);
      if ( V_stristr(pStr: v18, pSearch: "simpleworldmodel") == nullptr )
      {
        v19 = CUtlString::operator char const *(this: &pTree->m_Elements.m_pMemory[v14].m_Data);
        GetDependants_MDL(a1: i, pModelName: v19, pList: &v46);
      }
    }
  }
  v20 = 0;
  if ( v46.m_Size > 0 )
  {
    v21 = 0;
    do
    {
      v22 = CUtlString::operator char const *(this: &v46.m_Memory.m_pMemory[v21]);
      FindOrAddFileToResourceList(pFilename: v22, pTree, bAdd: true);
      ++v20;
      ++v21;
    }
    while ( v20 < v46.m_Size );
  }
  V_ComposeFileName(path: g_szGamePath, filename: pBspName, dest, destSize: 260);
  V_StripExtension(in: dest, out: dest, outSize: 260);
  V_strncat(pDest: dest, pSrc: "_commentary.txt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CUtlBuffer::CUtlBuffer(this: &v42, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: dest, buffer: &v42, bText: true, bNoOpenFailureWarning: true) )
  {
    v23 = CUtlBuffer::ParseToken(this: &v42, pBreaks: &pSetBuffer, pTokenBuf: s1, nMaxLen: 0x2000, bParseComments: true);
    v24 = v23 <= 0;
    if ( v23 >= 0 )
    {
      do
      {
        if ( !v24
          && _V_stricmp(s1, s2: "commentaryfile") == 0
          && CUtlBuffer::ParseToken(
               this: &v42,
               pBreaks: &pSetBuffer,
               pTokenBuf: s1,
               nMaxLen: 0x2000,
               bParseComments: true) > 0 )
        {
          v25 = s1[0];
          for ( j = s1; v25 != 0; v25 = *++j )
          {
            if ( v25 != 42
              && v25 != 63
              && v25 != 33
              && v25 != 35
              && v25 != 64
              && v25 != 40
              && v25 != 62
              && v25 != 60
              && v25 != 94
              && v25 != 41
              && v25 != 125
              && v25 != 36 )
            {
              break;
            }
          }
          V_snprintf(pDest, maxLen: 260, pFormat: "sound/%s", j);
          FindOrAddFileToResourceList(pFilename: pDest, pTree, bAdd: true);
        }
        v27 = CUtlBuffer::ParseToken(
                this: &v42,
                pBreaks: &pSetBuffer,
                pTokenBuf: s1,
                nMaxLen: 0x2000,
                bParseComments: true);
        v24 = v27 <= 0;
      }
      while ( v27 >= 0 );
    }
  }
  FindScriptFile(pFilename: "scripts/reslistfixes_xbox.xsc", pOutBuff, nOutBuffSize: 260, bCanFallback: true);
  CUtlBuffer::CUtlBuffer(this: &v41, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: pOutBuff, buffer: &v41, bText: true, bNoOpenFailureWarning: true) )
  {
    if ( CUtlBuffer::ParseToken(this: &v41, pBreaks: &pSetBuffer, pTokenBuf, nMaxLen: 260, bParseComments: true) <= 0 )
    {
LABEL_115:
      if ( v41.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v41.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41.m_Memory.m_pMemory);
          v41.m_Memory.m_pMemory = nullptr;
        }
        v41.m_Memory.m_nAllocationCount = 0;
      }
      if ( v42.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v42.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_Memory.m_pMemory);
          v42.m_Memory.m_pMemory = nullptr;
        }
        v42.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&v46);
      v31 = v46.m_Memory.m_pMemory;
      if ( v46.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v46.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46.m_Memory.m_pMemory);
          v31 = nullptr;
          v46.m_Memory.m_pMemory = nullptr;
        }
        v46.m_Memory.m_nAllocationCount = 0;
      }
      v46.m_pElements = v31;
      if ( v46.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v31 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v31);
          v46.m_Memory.m_pMemory = nullptr;
        }
        v46.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&pList);
      v32 = pList.m_Memory.m_pMemory;
      if ( pList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( pList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pList.m_Memory.m_pMemory);
          v32 = nullptr;
          pList.m_Memory.m_pMemory = nullptr;
        }
        pList.m_Memory.m_nAllocationCount = 0;
      }
      pList.m_pElements = v32;
      if ( pList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v32 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
          pList.m_Memory.m_pMemory = nullptr;
        }
        pList.m_Memory.m_nAllocationCount = 0;
      }
      if ( buffer.m_Memory.m_nGrowSize < 0 )
        return 1;
      m_pMemory = buffer.m_Memory.m_pMemory;
      v7 = buffer.m_Memory.m_pMemory == nullptr;
      goto LABEL_141;
    }
    while ( _V_stricmp(s1: pTokenBuf, s2: "-") != 0 )
    {
      if ( _V_stricmp(s1: pTokenBuf, s2: "+") == 0 )
      {
        v30 = 1;
        goto LABEL_109;
      }
      _Warning(a1: "Bad Syntax, expecting '+' or '-' as first token in reslist fixup file '%s'.\n", pOutBuff);
LABEL_114:
      if ( CUtlBuffer::ParseToken(this: &v41, pBreaks: &pSetBuffer, pTokenBuf, nMaxLen: 260, bParseComments: true) <= 0 )
        goto LABEL_115;
    }
    v30 = 0;
LABEL_109:
    if ( CUtlBuffer::ParseToken(this: &v41, pBreaks: &pSetBuffer, pTokenBuf, nMaxLen: 260, bParseComments: true) <= 0 )
      goto LABEL_115;
    if ( v30 != 0 )
      FindOrAddFileToResourceList(pFilename: pTokenBuf, pTree, bAdd: true);
    else
      RemoveFileFromResourceList(pFilename: pTokenBuf, pTree);
    goto LABEL_114;
  }
  _Warning(a1: "Missing reslist fixes script file '%s'\n", pOutBuff);
  if ( v41.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41.m_Memory.m_pMemory);
      v41.m_Memory.m_pMemory = nullptr;
    }
    v41.m_Memory.m_nAllocationCount = 0;
  }
  if ( v42.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v42.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_Memory.m_pMemory);
      v42.m_Memory.m_pMemory = nullptr;
    }
    v42.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&v46);
  v28 = v46.m_Memory.m_pMemory;
  if ( v46.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v46.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46.m_Memory.m_pMemory);
      v28 = nullptr;
      v46.m_Memory.m_pMemory = nullptr;
    }
    v46.m_Memory.m_nAllocationCount = 0;
  }
  v46.m_pElements = v28;
  if ( v46.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v46.m_Memory.m_pMemory = nullptr;
    }
    v46.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&pList);
  v29 = pList.m_Memory.m_pMemory;
  if ( pList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pList.m_Memory.m_pMemory);
      v29 = nullptr;
      pList.m_Memory.m_pMemory = nullptr;
    }
    pList.m_Memory.m_nAllocationCount = 0;
  }
  pList.m_pElements = v29;
  if ( pList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v29 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
      pList.m_Memory.m_pMemory = nullptr;
    }
    pList.m_Memory.m_nAllocationCount = 0;
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF00
// Name: bool CreateTargetFile_RESLST(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_RESLST(char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  int i; // esi
  const char *v5; // eax
  bool v6; // bl
  CUtlBuffer targetBuffer; // [esp+0h] [ebp-54h] BYREF
  CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > rbTree; // [esp+30h] [ebp-24h] BYREF

  if ( g_bModPathIsValid )
  {
    rbTree.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))ModelNamesLessFunc;
    memset(&rbTree.m_Elements, 0, sizeof(rbTree.m_Elements));
    rbTree.m_Root = -1;
    rbTree.m_NumElements = 0;
    rbTree.m_FirstFree = -1;
    rbTree.m_LastAlloc.index = -1;
    rbTree.m_pElements = nullptr;
    if ( LoadReslist(pReslistName: pSourceName, pTree: &rbTree) != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 5);
      for ( i = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FirstInorder(this: &rbTree);
            i != -1;
            i = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NextInorder(
                  this: &rbTree,
                  i) )
      {
        if ( (targetBuffer.m_Flags & 1) != 0
          && targetBuffer.m_Put != 0
          && targetBuffer.m_Memory.m_pMemory[targetBuffer.m_Put - targetBuffer.m_nOffset - 1] == 10 )
        {
          CUtlBuffer::PutTabs(this: &targetBuffer);
        }
        if ( CUtlBuffer::CheckPut(this: &targetBuffer, nSize: 1) )
        {
          targetBuffer.m_Memory.m_pMemory[targetBuffer.m_Put - targetBuffer.m_nOffset] = 34;
          CUtlBuffer::AddNullTermination(this: &targetBuffer, nPut: ++targetBuffer.m_Put);
        }
        v5 = CUtlString::operator char const *(this: &rbTree.m_Elements.m_pMemory[i].m_Data);
        CUtlBuffer::PutString(this: &targetBuffer, pString: v5);
        if ( (targetBuffer.m_Flags & 1) != 0
          && targetBuffer.m_Put != 0
          && targetBuffer.m_Memory.m_pMemory[targetBuffer.m_Put - targetBuffer.m_nOffset - 1] == 10 )
        {
          CUtlBuffer::PutTabs(this: &targetBuffer);
        }
        if ( CUtlBuffer::CheckPut(this: &targetBuffer, nSize: 1) )
        {
          targetBuffer.m_Memory.m_pMemory[targetBuffer.m_Put - targetBuffer.m_nOffset] = 34;
          CUtlBuffer::AddNullTermination(this: &targetBuffer, nPut: ++targetBuffer.m_Put);
        }
        CUtlBuffer::PutString(this: &targetBuffer, pString: "\r\n");
      }
      v6 = WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
      if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
      {
        if ( targetBuffer.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
          targetBuffer.m_Memory.m_pMemory = nullptr;
        }
        targetBuffer.m_Memory.m_nAllocationCount = 0;
      }
      CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &rbTree);
      if ( rbTree.m_Elements.m_nGrowSize >= 0 && rbTree.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rbTree.m_Elements.m_pMemory);
      return v6;
    }
    else
    {
      CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::~CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>(this: &rbTree);
      return false;
    }
  }
  else
  {
    _Warning(a1: "Indeterminate mod path, Cannot perform RESLIST conversion for %s\n", pSourceName);
    return false;
  }
}
