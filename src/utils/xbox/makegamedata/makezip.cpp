// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makezip.cpp
// Functions: 35
// ============================================================

#include "utils\xbox\makegamedata\makezip.h"

//------------------------------------------------------------------------------
// Address: 0x00401D90
// Name: protected: static int CUtlSortVector<int,class CFileLess>::CompareHelper(void __near *,int const __near *,int const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<int,CFileLess>::CompareHelper(void *context, const int *lhs, const int *rhs)
{
  if ( *lhs <= *rhs )
    return *rhs > *lhs;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00410870
// Name: protected: static int CUtlSortVector<class CSortedCacheFile,class CSortedCacheFile>::CompareHelper(void __near *,class CSortedCacheFile const __near *,class CSortedCacheFile const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper(
        void *context,
        const CSortedCacheFile *lhs,
        const CSortedCacheFile *rhs)
{
  char s1[512]; // [esp+8h] [ebp-400h] BYREF
  char s2[512]; // [esp+208h] [ebp-200h] BYREF

  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  if ( _V_stricmp(s1, s2) < 0 )
    return -1;
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  return _V_stricmp(s1: s2, s2: s1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410B20
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int> *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418910
// Name: GetPreloadBuffer
// Source: json
//------------------------------------------------------------------------------
bool __usercall GetPreloadBuffer@<al>(
        const char *pFilename@<ecx>,
        CUtlBuffer *fileBuffer@<eax>,
        CUtlBuffer *preloadBuffer)
{
  bool v6; // bl
  signed int m_nMaxPut; // ecx
  unsigned __int8 *v8; // esi
  unsigned __int8 *m_pMemory; // [esp-14h] [ebp-124h]
  char fileExtension[260]; // [esp+8h] [ebp-108h] BYREF
  unsigned int compressedSize; // [esp+10Ch] [ebp-4h] BYREF

  if ( CUtlSymbolTable::Find(this: &g_PreloadBlackTable, result: (CUtlSymbol *)&compressedSize + 1, pString: pFilename)->m_Id != 0xFFFF )
    return false;
  v6 = CUtlSymbolTable::Find(this: &g_PreloadWhiteTable, result: (CUtlSymbol *)&compressedSize + 1, pString: pFilename)->m_Id != 0xFFFF;
  V_ExtractFileExtension(path: pFilename, dest: fileExtension, destSize: 260);
  if ( !v6
    && (_V_stricmp(s1: fileExtension, s2: "bns") == 0
     || _V_stricmp(s1: fileExtension, s2: "cfg") == 0
     || _V_stricmp(s1: fileExtension, s2: "ctx") == 0
     || _V_stricmp(s1: fileExtension, s2: "ekv") == 0
     || _V_stricmp(s1: fileExtension, s2: "inf") == 0
     || _V_stricmp(s1: fileExtension, s2: "lst") == 0
     || _V_stricmp(s1: fileExtension, s2: "nut") == 0
     || _V_stricmp(s1: fileExtension, s2: "pcf") == 0
     || _V_stricmp(s1: fileExtension, s2: "rc") == 0
     || _V_stricmp(s1: fileExtension, s2: "res") == 0
     || _V_stricmp(s1: fileExtension, s2: "scr") == 0
     || _V_stricmp(s1: fileExtension, s2: "txt") == 0
     || _V_stricmp(s1: fileExtension, s2: "vbf") == 0
     || _V_stricmp(s1: fileExtension, s2: "vfe") == 0
     || _V_stricmp(s1: fileExtension, s2: "vmt") == 0
     || _V_stricmp(s1: fileExtension, s2: "vscr") == 0
     || _V_stricmp(s1: fileExtension, s2: "vtest") == 0) )
  {
    v6 = true;
  }
  if ( !g_bIsUpdateZip )
  {
    if ( !v6 )
    {
LABEL_41:
      if ( _V_stricmp(s1: fileExtension, s2: "wav") == 0 )
        return GetPreloadData_WAV(pFilename, fileBufferIn: fileBuffer, preloadBufferOut: preloadBuffer);
      if ( _V_stricmp(s1: fileExtension, s2: "vtf") == 0 )
        return GetPreloadData_VTF(pFilename, fileBufferIn: fileBuffer, preloadBufferOut: preloadBuffer);
      if ( _V_stricmp(s1: fileExtension, s2: "vcs") == 0 )
        return GetPreloadData_VCS(pFilename, fileBufferIn: fileBuffer, preloadBufferOut: preloadBuffer);
      if ( _V_stricmp(s1: fileExtension, s2: "vhv") == 0 )
        return GetPreloadData_VHV(pFilename, fileBufferIn: fileBuffer, preloadBufferOut: preloadBuffer);
      if ( _V_stricmp(s1: fileExtension, s2: "vtx") == 0 )
        return GetPreloadData_VTX(pFilename, fileBufferIn: fileBuffer, preloadBufferOut: preloadBuffer);
      if ( _V_stricmp(s1: fileExtension, s2: "vvd") == 0 )
        return GetPreloadData_VVD(pFilename, fileBufferIn: fileBuffer, preloadBufferOut: preloadBuffer);
      return false;
    }
    if ( _V_stricmp(s1: fileExtension, s2: "lst") == 0
      && V_stristr(pStr: pFilename, pSearch: "reslists_xbox") != nullptr )
    {
      return false;
    }
    if ( !g_bIsUpdateZip )
      goto LABEL_30;
  }
  if ( _V_stricmp(s1: fileExtension, s2: "vtf") != 0 && _V_stricmp(s1: fileExtension, s2: "wav") != 0 )
  {
LABEL_30:
    if ( !v6 )
      goto LABEL_33;
  }
  else
  {
    v6 = true;
  }
  if ( LZMA_IsCompressed(pInput: fileBuffer->m_Memory.m_pMemory) )
    v6 = false;
LABEL_33:
  if ( g_bIsUpdateZip )
  {
    if ( !v6 )
    {
      _Warning(a1: "ERROR: update zip not handling '%s' as expected.\n", pFilename);
      exit(code: 1);
    }
    goto LABEL_37;
  }
  if ( !v6 )
    goto LABEL_41;
LABEL_37:
  m_nMaxPut = fileBuffer->m_nMaxPut;
  if ( m_nMaxPut >= 1024
    && (m_pMemory = fileBuffer->m_Memory.m_pMemory,
        compressedSize = 0,
        (v8 = LZMA_Compress(
                pInput: m_pMemory,
                inputSize: m_nMaxPut,
                pOutputSize: &compressedSize,
                dictionarySize: 0x12u)) != nullptr) )
  {
    CUtlBuffer::EnsureCapacity(this: preloadBuffer, num: compressedSize);
    CUtlBuffer::Put(this: preloadBuffer, pMem: v8, size: compressedSize);
    free(pMem: v8);
    return true;
  }
  else
  {
    CUtlBuffer::EnsureCapacity(this: preloadBuffer, num: fileBuffer->m_nMaxPut);
    CUtlBuffer::Put(this: preloadBuffer, pMem: fileBuffer->m_Memory.m_pMemory, size: fileBuffer->m_nMaxPut);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418D90
// Name: public: int CUtlSortVector<struct CRCEntry_t,class CZipCRCLessFunc>::FindLessOrEqual(struct CRCEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CRCEntry_t,CZipCRCLessFunc>::FindLessOrEqual(
        CUtlSortVector<CRCEntry_t,CZipCRCLessFunc> *this,
        const CRCEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  CRCEntry_t *m_pMemory; // ebx
  unsigned int fileNameCRC; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    fileNameCRC = src->fileNameCRC;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].fileNameCRC;
      if ( fileNameCRC <= v8 )
      {
        if ( fileNameCRC >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00418EA0
// Name: bool IsFilenameAlternateCandidate(char const __near *,bool __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsFilenameAlternateCandidate(
        const char *pFilename,
        bool *bIsOriginal,
        char *pOutFilename,
        int nOutFilenameSize)
{
  int m_Size; // eax
  int v5; // esi
  int v6; // edi
  const char *v7; // eax
  int v8; // esi
  int i; // edi
  const char *v10; // eax
  char *v12; // edi
  AlternateFile_t *p_m_Alternate; // ecx
  const char *v14; // eax
  int v15; // [esp-4h] [ebp-110h]
  char fixedFilename[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: fixedFilename, pSrc: pFilename, maxLen: 260);
  _V_strlower(start: fixedFilename);
  V_FixSlashes(pname: fixedFilename, separator: 92);
  m_Size = g_AlternateFileTable.m_Size;
  v5 = 0;
  if ( g_AlternateFileTable.m_Size > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = CUtlString::Get(this: &g_AlternateFileTable.m_Memory.m_pMemory[v6].m_Original);
      if ( _V_stricmp(s1: v7, s2: fixedFilename) == 0 )
        break;
      m_Size = g_AlternateFileTable.m_Size;
      ++v5;
      ++v6;
      if ( v5 >= g_AlternateFileTable.m_Size )
        goto LABEL_5;
    }
    v12 = pOutFilename;
    *bIsOriginal = true;
    if ( pOutFilename == nullptr )
      return 1;
    v15 = nOutFilenameSize;
    p_m_Alternate = (AlternateFile_t *)&g_AlternateFileTable.m_Memory.m_pMemory[v5].m_Alternate;
    goto LABEL_12;
  }
LABEL_5:
  v8 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v10 = CUtlString::Get(this: &g_AlternateFileTable.m_Memory.m_pMemory[i].m_Alternate);
    if ( _V_stricmp(s1: v10, s2: fixedFilename) == 0 )
      break;
    if ( ++v8 >= g_AlternateFileTable.m_Size )
      return 0;
  }
  v12 = pOutFilename;
  *bIsOriginal = false;
  if ( pOutFilename != nullptr )
  {
    v15 = nOutFilenameSize;
    p_m_Alternate = &g_AlternateFileTable.m_Memory.m_pMemory[v8];
LABEL_12:
    v14 = CUtlString::Get(this: &p_m_Alternate->m_Original);
    V_strncpy(pDest: v12, pSrc: v14, maxLen: v15);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418FC0
// Name: public: int CUtlSortVector<struct CRCEntry_t,class CZipCRCLessFunc>::Find(struct CRCEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CRCEntry_t,CZipCRCLessFunc>::Find(
        CUtlSortVector<CRCEntry_t,CZipCRCLessFunc> *this,
        const CRCEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  CRCEntry_t *m_pMemory; // ebx
  unsigned int fileNameCRC; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    fileNameCRC = src->fileNameCRC;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].fileNameCRC;
      if ( fileNameCRC <= v8 )
      {
        if ( fileNameCRC >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00419800
// Name: public: CRCEntry_t::~CRCEntry_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRCEntry_t::~CRCEntry_t(CRCEntry_t *this)
{
  bool v2; // sf

  v2 = this->filename.m_Storage.m_Memory.m_nGrowSize < 0;
  this->filename.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->filename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->filename.m_Storage.m_Memory.m_pMemory);
      this->filename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->filename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A080
// Name: void SetupCriticalPreloadScript(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupCriticalPreloadScript()
{
  char v0; // bl
  char szCriticaList[260]; // [esp+0h] [ebp-340h] BYREF
  characterset_t breakSet; // [esp+104h] [ebp-23Ch] BYREF
  char szToken[260]; // [esp+204h] [ebp-13Ch] BYREF
  CUtlBuffer criticalListBuffer; // [esp+308h] [ebp-38h] BYREF
  CUtlSymbol result; // [esp+338h] [ebp-8h] BYREF
  CUtlSymbol v6; // [esp+33Ah] [ebp-6h] BYREF
  CUtlSymbol v7; // [esp+33Ch] [ebp-4h] BYREF
  CUtlSymbol v8; // [esp+33Eh] [ebp-2h] BYREF

  CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: pDefaultValue);
  CUtlSymbolTable::RemoveAll(this: &g_PreloadWhiteTable);
  CUtlSymbolTable::RemoveAll(this: &g_PreloadBlackTable);
  FindScriptFile(pFilename: "scripts/preload_xbox.xsc", pOutBuff: szCriticaList, nOutBuffSize: 260, bCanFallback: true);
  CUtlBuffer::CUtlBuffer(this: &criticalListBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(
         pSourceName: szCriticaList,
         buffer: &criticalListBuffer,
         bText: true,
         bNoOpenFailureWarning: true) )
  {
    if ( CUtlBuffer::ParseToken(
           this: &criticalListBuffer,
           pBreaks: &breakSet,
           pTokenBuf: szToken,
           nMaxLen: 260,
           bParseComments: true) <= 0 )
    {
LABEL_18:
      if ( criticalListBuffer.m_Memory.m_nGrowSize >= 0 && criticalListBuffer.m_Memory.m_pMemory != nullptr )
        goto LABEL_20;
      return;
    }
    while ( _V_stricmp(s1: szToken, s2: "-") != 0 )
    {
      if ( _V_stricmp(s1: szToken, s2: "+") == 0 )
      {
        v0 = 1;
        goto LABEL_10;
      }
      _Warning(a1: "Bad Syntax, expecting '+' or '-' as first token in preload fixup file '%s'.\n", szCriticaList);
LABEL_17:
      if ( CUtlBuffer::ParseToken(
             this: &criticalListBuffer,
             pBreaks: &breakSet,
             pTokenBuf: szToken,
             nMaxLen: 260,
             bParseComments: true) <= 0 )
        goto LABEL_18;
    }
    v0 = 0;
LABEL_10:
    if ( CUtlBuffer::ParseToken(
           this: &criticalListBuffer,
           pBreaks: &breakSet,
           pTokenBuf: szToken,
           nMaxLen: 260,
           bParseComments: true) <= 0 )
      goto LABEL_18;
    _V_strlower(start: szToken);
    V_FixSlashes(pname: szToken, separator: 92);
    if ( v0 != 0 )
    {
      if ( CUtlSymbolTable::Find(this: &g_PreloadWhiteTable, &result, pString: szToken)->m_Id == 0xFFFF )
        CUtlSymbolTable::AddString(this: &g_PreloadWhiteTable, result: &v6, pString: szToken);
    }
    else if ( CUtlSymbolTable::Find(this: &g_PreloadBlackTable, result: &v7, pString: szToken)->m_Id == 0xFFFF )
    {
      CUtlSymbolTable::AddString(this: &g_PreloadBlackTable, result: &v8, pString: szToken);
    }
    goto LABEL_17;
  }
  _Warning(a1: "Missing preload script file '%s'\n", szCriticaList);
  if ( criticalListBuffer.m_Memory.m_nGrowSize >= 0 && criticalListBuffer.m_Memory.m_pMemory != nullptr )
LABEL_20:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: criticalListBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041A320
// Name: public: int CUtlSortVector<struct CRCEntry_t,class CZipCRCLessFunc>::Insert(struct CRCEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CRCEntry_t,CZipCRCLessFunc>::Insert(
        CUtlSortVector<CRCEntry_t,CZipCRCLessFunc> *this,
        const CRCEntry_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CRCEntry_t *m_pMemory; // ecx
  int v8; // eax
  CRCEntry_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CRCEntry_t,CZipCRCLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 20 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
  {
    v9->fileNameCRC = src->fileNameCRC;
    CUtlString::CUtlString(this: &v9->filename, string: &src->filename);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041A610
// Name: public: void CXZipTool::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXZipTool::Reset(CXZipTool *this)
{
  preloadRemap_t *m_pMemory; // ecx

  if ( this->m_hOutputZipFile != (void *)-1 )
  {
    CloseHandle(hObject: this->m_hOutputZipFile);
    this->m_hOutputZipFile = (void *)-1;
  }
  if ( this->m_hPreloadFile != (void *)-1 )
  {
    CloseHandle(hObject: this->m_hPreloadFile);
    this->m_hPreloadFile = (void *)-1;
  }
  if ( this->m_PreloadFilename[0] != 0 )
  {
    DeleteFileA(lpFileName: this->m_PreloadFilename);
    this->m_PreloadFilename[0] = 0;
  }
  if ( this->m_pZip != nullptr )
  {
    IZip::ReleaseZip(pZip: this->m_pZip);
    this->m_pZip = nullptr;
  }
  this->m_ZipPreloadDirectoryEntries.m_Size = 0;
  if ( this->m_ZipPreloadDirectoryEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ZipPreloadDirectoryEntries.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ZipPreloadDirectoryEntries.m_Memory.m_pMemory);
      this->m_ZipPreloadDirectoryEntries.m_Memory.m_pMemory = nullptr;
    }
    this->m_ZipPreloadDirectoryEntries.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ZipPreloadDirectoryEntries.m_pElements = this->m_ZipPreloadDirectoryEntries.m_Memory.m_pMemory;
  CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>::RemoveAll(this: (CUtlVector<errorList_t,CUtlMemory<errorList_t,int> > *)&this->m_ZipCRCList);
  if ( this->m_ZipCRCList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ZipCRCList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ZipCRCList.m_Memory.m_pMemory);
      this->m_ZipCRCList.m_Memory.m_pMemory = nullptr;
    }
    this->m_ZipCRCList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ZipCRCList.m_pElements = this->m_ZipCRCList.m_Memory.m_pMemory;
  CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::RemoveAll(this: &this->m_ZipPreloadRemapEntries);
  if ( this->m_ZipPreloadRemapEntries.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ZipPreloadRemapEntries.m_pElements = this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory);
      this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory;
    this->m_ZipPreloadRemapEntries.m_Memory.m_nAllocationCount = 0;
    this->m_ZipPreloadRemapEntries.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A750
// Name: public: bool CXZipTool::AddBuffer(char const __near *,class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXZipTool::AddBuffer(CXZipTool *this, int pFilename, CUtlBuffer *fileBuffer, unsigned int bDoPreload)
{
  char *v6; // esi
  CUtlSortVector<CRCEntry_t,CZipCRCLessFunc> *p_m_ZipCRCList; // ebx
  int v8; // eax
  int v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  bool v12; // al
  DWORD m_nMaxPut; // ebx
  void *m_hPreloadFile; // edx
  DWORD v15; // eax
  int m_Size; // edx
  unsigned int ActualSize; // eax
  int v18; // ebx
  char alternateFilename[260]; // [esp+4h] [ebp-164h] BYREF
  CUtlBuffer preloadBuffer; // [esp+108h] [ebp-60h] BYREF
  preloadRemap_t remap; // [esp+138h] [ebp-30h] BYREF
  ZIP_PreloadDirectoryEntry entry; // [esp+14Ch] [ebp-1Ch] BYREF
  CRCEntry_t crcEntry; // [esp+154h] [ebp-14h] BYREF

  if ( this->m_pZip == nullptr )
    return 0;
  v6 = (char *)pFilename;
  if ( V_strncasecmp(s1: (const char *)pFilename, s2: asc_58D3CC, n: 2) == 0 )
    v6 += 2;
  HIBYTE(pFilename) = 0;
  if ( IsFilenameAlternateCandidate(
         pFilename: v6,
         bIsOriginal: (bool *)&pFilename + 3,
         pOutFilename: alternateFilename,
         nOutFilenameSize: 260) != 0 )
  {
    if ( HIBYTE(pFilename) != 0 )
      return 1;
    v6 = alternateFilename;
  }
  CUtlString::CUtlString(this: &crcEntry.filename);
  crcEntry.fileNameCRC = HashStringCaselessConventional(pszKey: v6);
  CUtlString::operator=(this: &crcEntry.filename, src: v6);
  p_m_ZipCRCList = &this->m_ZipCRCList;
  v8 = CUtlSortVector<CRCEntry_t,CZipCRCLessFunc>::Find(this: &this->m_ZipCRCList, src: &crcEntry);
  if ( v8 != -1 )
  {
    v9 = v8;
    v10 = CUtlString::operator char const *(this: &p_m_ZipCRCList->m_Memory.m_pMemory[v8].filename);
    if ( _V_stricmp(s1: v6, s2: v10) != 0 )
    {
      v11 = CUtlString::operator char const *(this: &p_m_ZipCRCList->m_Memory.m_pMemory[v9].filename);
      _Warning(a1: "ERROR: CRC Collision: '%s' with '%s'\n", v6, v11);
      CRCEntry_t::~CRCEntry_t(this: &crcEntry);
      return 0;
    }
    else
    {
      CRCEntry_t::~CRCEntry_t(this: &crcEntry);
      return 1;
    }
  }
  CUtlSortVector<CRCEntry_t,CZipCRCLessFunc>::Insert(this: &this->m_ZipCRCList, src: &crcEntry);
  pFilename = 0xFFFF;
  if ( (_BYTE)bDoPreload != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &preloadBuffer, growSize: 0, initSize: 0, nFlags: 0);
    v12 = GetPreloadBuffer(pFilename: v6, fileBuffer, &preloadBuffer);
    m_nMaxPut = preloadBuffer.m_nMaxPut;
    if ( v12 && preloadBuffer.m_nMaxPut > 0 )
    {
      if ( this->m_ZipPreloadDirectoryEntries.m_Size >= 65534 )
      {
        _Warning(a1: "ERROR: Preload section FULL!, skipping %s\n", v6);
LABEL_31:
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &preloadBuffer);
        CRCEntry_t::~CRCEntry_t(this: &crcEntry);
        return 0;
      }
      m_hPreloadFile = this->m_hPreloadFile;
      entry.DataOffset = 0;
      entry.Length = preloadBuffer.m_nMaxPut;
      v15 = SetFilePointer(hFile: m_hPreloadFile, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u);
      m_Size = this->m_ZipPreloadDirectoryEntries.m_Size;
      entry.DataOffset = v15;
      pFilename = (unsigned __int16)CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
                                      this: &this->m_ZipPreloadDirectoryEntries,
                                      elem: m_Size,
                                      src: &entry);
      if ( !WriteFile(
              hFile: this->m_hPreloadFile,
              lpBuffer: preloadBuffer.m_Memory.m_pMemory,
              nNumberOfBytesToWrite: m_nMaxPut,
              lpNumberOfBytesWritten: &bDoPreload,
              lpOverlapped: nullptr)
        || m_nMaxPut != bDoPreload )
      {
        _Warning(a1: "ERROR: writing %d preload bytes of '%s'\n", m_nMaxPut, v6);
        goto LABEL_31;
      }
      if ( LZMA_IsCompressed(pInput: preloadBuffer.m_Memory.m_pMemory) )
      {
        ActualSize = LZMA_GetActualSize(pInput: preloadBuffer.m_Memory.m_pMemory);
        _Msg(a1: "Preload: '%s': Compressed:%u Actual:%u\n", v6, m_nMaxPut, ActualSize);
      }
      else
      {
        _Msg(a1: "Preload: '%s': Length:%u\n", v6, m_nMaxPut);
      }
    }
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &preloadBuffer);
  }
  v18 = fileBuffer->m_nMaxPut;
  if ( v18 != 0 )
  {
    this->m_pZip->AddBufferToZip(this: this->m_pZip, a2: v6, a3: fileBuffer->m_Memory.m_pMemory, a4: v18, a5: false);
    CUtlString::CUtlString(this: &remap.filename);
    CUtlString::operator=(this: &remap.filename, src: v6);
    remap.preloadDirIndex = pFilename;
    CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::InsertBefore(
      this: &this->m_ZipPreloadRemapEntries,
      elem: this->m_ZipPreloadRemapEntries.m_Size,
      src: &remap);
    _Msg(a1: "File: '%s': Length:%u\n", v6, v18);
    CUtlString::~CUtlString(this: &remap.filename);
  }
  crcEntry.filename.m_Storage.m_nActualLength = 0;
  if ( crcEntry.filename.m_Storage.m_Memory.m_nGrowSize >= 0
    && crcEntry.filename.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: crcEntry.filename.m_Storage.m_Memory.m_pMemory);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA30
// Name: public: bool CXZipTool::End(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXZipTool::End(CXZipTool *this)
{
  IZip *m_pZip; // ecx
  void *m_hPreloadFile; // eax
  DWORD v5; // eax
  unsigned int m_Size; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v9; // ecx
  unsigned int Alignment; // eax
  unsigned int v11; // ecx
  int j; // edi
  ZIP_PreloadDirectoryEntry *m_pMemory; // eax
  int v14; // edi
  int v15; // ebx
  IZip *v16; // ecx
  int v17; // edi
  int v18; // ebx
  const char *v19; // eax
  int v20; // eax
  int k; // edi
  unsigned __int16 v22; // ax
  unsigned __int16 v23; // bx
  int v24; // eax
  unsigned __int8 *v25; // eax
  unsigned int v26; // ebx
  void *v27; // edi
  int m_nMaxPut; // eax
  unsigned int m; // ebx
  int n; // edi
  char fileName[260]; // [esp+4h] [ebp-158h] BYREF
  unsigned int preloadDataSize; // [esp+108h] [ebp-54h]
  CUtlBuffer sectionBuffer; // [esp+10Ch] [ebp-50h] BYREF
  unsigned int sectionSize; // [esp+13Ch] [ebp-20h]
  int fileSize; // [esp+140h] [ebp-1Ch] BYREF
  unsigned __int16 *pRemapTable; // [esp+144h] [ebp-18h]
  unsigned int numBytesRead; // [esp+148h] [ebp-14h] BYREF
  unsigned int pOutputBuffer; // [esp+14Ch] [ebp-10h] BYREF
  int s; // [esp+150h] [ebp-Ch]
  CByteswap byteSwap; // [esp+154h] [ebp-8h] BYREF
  int i; // [esp+158h] [ebp-4h] BYREF

  m_pZip = this->m_pZip;
  if ( m_pZip == nullptr )
    return 0;
  if ( this->m_ZipPreloadDirectoryEntries.m_Size != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &sectionBuffer, growSize: 0, initSize: 0, nFlags: 0);
    m_hPreloadFile = this->m_hPreloadFile;
    byteSwap = (CByteswap)(*(_DWORD *)&byteSwap | 3);
    v5 = SetFilePointer(hFile: m_hPreloadFile, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 1u);
    m_Size = this->m_ZipPreloadDirectoryEntries.m_Size;
    v7 = v5;
    v8 = this->m_ZipPreloadRemapEntries.m_Size;
    this->m_ZipPreloadHeader.PreloadDirectoryEntries = m_Size;
    v9 = v8 + 4 * m_Size + 8;
    this->m_ZipPreloadHeader.DirectoryEntries = v8;
    Alignment = this->m_ZipPreloadHeader.Alignment;
    v11 = v7 + 2 * v9;
    preloadDataSize = v7;
    sectionSize = v11;
    if ( Alignment != 0 )
    {
      sectionSize = ~(Alignment - 1) & (Alignment + v11 - 1);
      v11 = sectionSize;
    }
    CUtlBuffer::EnsureCapacity(this: &sectionBuffer, num: v11);
    CByteswap::SwapFieldsToTargetEndian(
      this: &byteSwap,
      pOutputBuffer: &this->m_ZipPreloadHeader,
      pBaseData: &this->m_ZipPreloadHeader,
      pDataMap: &ZIP_PreloadHeader::m_DataMap);
    CUtlBuffer::Put(this: &sectionBuffer, pMem: &this->m_ZipPreloadHeader, size: 16);
    for ( j = 0; j < this->m_ZipPreloadDirectoryEntries.m_Size; ++j )
    {
      m_pMemory = this->m_ZipPreloadDirectoryEntries.m_Memory.m_pMemory;
      pOutputBuffer = m_pMemory[j].Length;
      s = m_pMemory[j].DataOffset;
      CByteswap::SwapFieldsToTargetEndian(
        this: &byteSwap,
        &pOutputBuffer,
        pBaseData: &pOutputBuffer,
        pDataMap: &ZIP_PreloadDirectoryEntry::m_DataMap);
      CUtlBuffer::Put(this: &sectionBuffer, pMem: &pOutputBuffer, size: 8);
    }
    v14 = this->m_ZipPreloadRemapEntries.m_Size;
    v15 = -1;
    pRemapTable = (unsigned __int16 *)MemAlloc_Alloc(nSize: 2 * v14);
    i = 0;
    if ( v14 > 0 )
    {
      while ( 1 )
      {
        v16 = this->m_pZip;
        fileName[0] = 0;
        fileSize = 0;
        v17 = 0;
        s = v16->GetNextFilename(this: v16, a2: v15, a3: fileName, a4: 260, a5: &fileSize);
        if ( this->m_ZipPreloadRemapEntries.m_Size <= 0 )
        {
LABEL_15:
          _Warning(a1: "ERROR: file '%s' was expected to have an entry in preload table\n", fileName);
        }
        else
        {
          v18 = 0;
          while ( 1 )
          {
            v19 = CUtlString::operator char const *(this: &this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory[v18].filename);
            if ( _V_stricmp(s1: fileName, s2: v19) == 0 )
              break;
            ++v17;
            ++v18;
            if ( v17 >= this->m_ZipPreloadRemapEntries.m_Size )
              goto LABEL_15;
          }
        }
        v20 = i;
        pRemapTable[i] = this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory[v17].preloadDirIndex;
        i = v20 + 1;
        if ( v20 + 1 >= this->m_ZipPreloadRemapEntries.m_Size )
          break;
        v15 = s;
      }
    }
    for ( k = 0; k < this->m_ZipPreloadRemapEntries.m_Size; ++k )
    {
      s = pRemapTable[k];
      LOBYTE(v22) = BYTE1(s);
      HIBYTE(v22) = s;
      v23 = v22;
      if ( (sectionBuffer.m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: &sectionBuffer, pFmt: "%hd", (__int16)v22);
      }
      else
      {
        i = v22;
        if ( CUtlBuffer::CheckPut(this: &sectionBuffer, nSize: 2) )
        {
          v24 = sectionBuffer.m_Put - sectionBuffer.m_nOffset;
          if ( (*(_BYTE *)&sectionBuffer.m_Byteswap & 1) != 0 )
          {
            v25 = &sectionBuffer.m_Memory.m_pMemory[v24];
            if ( v25 != nullptr )
            {
              if ( (*(_BYTE *)&sectionBuffer.m_Byteswap & 1) != 0 )
              {
                HIWORD(i) = 0;
                LOBYTE(i) = HIBYTE(v23);
                BYTE1(i) = v23;
                _V_memcpy(dest: v25, src: &i, count: 2);
              }
              else if ( v25 != (unsigned __int8 *)&i )
              {
                *(_WORD *)v25 = i;
              }
            }
          }
          else
          {
            *(_WORD *)&sectionBuffer.m_Memory.m_pMemory[v24] = v23;
          }
          sectionBuffer.m_Put += 2;
          CUtlBuffer::AddNullTermination(this: &sectionBuffer, nPut: sectionBuffer.m_Put);
        }
      }
    }
    free(pMem: pRemapTable);
    v26 = preloadDataSize;
    v27 = MemAlloc_Alloc(nSize: preloadDataSize);
    SetFilePointer(hFile: this->m_hPreloadFile, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 0);
    if ( !ReadFile(
            hFile: this->m_hPreloadFile,
            lpBuffer: v27,
            nNumberOfBytesToRead: v26,
            lpNumberOfBytesRead: &numBytesRead,
            lpOverlapped: nullptr)
      || numBytesRead != v26 )
    {
      _Warning(a1: "ERROR: failed to read %d bytes from temporary preload file\n", v26);
    }
    CloseHandle(hObject: this->m_hPreloadFile);
    this->m_hPreloadFile = (void *)-1;
    CUtlBuffer::Put(this: &sectionBuffer, pMem: v27, size: v26);
    free(pMem: v27);
    m_nMaxPut = sectionBuffer.m_nMaxPut;
    for ( m = sectionSize; sectionBuffer.m_nMaxPut < m; m_nMaxPut = sectionBuffer.m_nMaxPut )
    {
      if ( (sectionBuffer.m_Flags & 1) != 0
        && sectionBuffer.m_Put != 0
        && sectionBuffer.m_Memory.m_pMemory[sectionBuffer.m_Put - sectionBuffer.m_nOffset - 1] == 10 )
      {
        for ( n = (sectionBuffer.m_Flags & 0x10) == 0 ? sectionBuffer.m_nTab - 1 : -1; n >= 0; --n )
        {
          if ( CUtlBuffer::CheckPut(this: &sectionBuffer, nSize: 1) )
          {
            sectionBuffer.m_Memory.m_pMemory[sectionBuffer.m_Put - sectionBuffer.m_nOffset] = 9;
            CUtlBuffer::AddNullTermination(this: &sectionBuffer, nPut: ++sectionBuffer.m_Put);
          }
        }
      }
      if ( CUtlBuffer::CheckPut(this: &sectionBuffer, nSize: 1) )
      {
        sectionBuffer.m_Memory.m_pMemory[sectionBuffer.m_Put - sectionBuffer.m_nOffset] = 0;
        CUtlBuffer::AddNullTermination(this: &sectionBuffer, nPut: ++sectionBuffer.m_Put);
      }
    }
    this->m_pZip->AddBufferToZip(
      this: this->m_pZip,
      a2: "__preload_section.pre",
      a3: sectionBuffer.m_Memory.m_pMemory,
      a4: m_nMaxPut,
      a5: false);
    if ( sectionBuffer.m_Memory.m_nGrowSize >= 0 && sectionBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sectionBuffer.m_Memory.m_pMemory);
  }
  else
  {
    m_pZip->RemoveFileFromZip(this: m_pZip, a2: "__preload_section.pre");
  }
  this->m_pZip->SaveToDisk(this: this->m_pZip, a2: this->m_hOutputZipFile);
  CXZipTool::Reset(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE50
// Name: public: bool CXZipTool::Begin(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXZipTool::Begin(CXZipTool *this, const char *pZipFileName, unsigned int alignment)
{
  IZip *Zip; // eax
  HANDLE FileA; // eax
  HANDLE v7; // eax
  IZip *m_pZip; // ecx
  char drivePath[260]; // [esp+Ch] [ebp-118h] BYREF
  preloadRemap_t remap; // [esp+110h] [ebp-14h] BYREF

  _splitpath(path: pZipFileName, drive: drivePath, dir: nullptr, fname: nullptr, ext: nullptr);
  Zip = IZip::CreateZip(pDiskCacheWritePath: drivePath, bSortByName: true);
  this->m_pZip = Zip;
  if ( g_bIsUpdateZip )
  {
    alignment = 0;
    Zip->ForceAlignment(this: Zip, a2: true, a3: g_bCompatibleZipFormat, a4: -1u);
  }
  else if ( alignment != 0 )
  {
    ((void (__stdcall *)(int, bool, unsigned int))Zip->ForceAlignment)(a1: 1, a2: g_bCompatibleZipFormat, a3: alignment);
  }
  FileA = CreateFileA(
            lpFileName: pZipFileName,
            dwDesiredAccess: 0x40000000u,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 2u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  this->m_hOutputZipFile = FileA;
  if ( FileA == (HANDLE)-1 )
  {
    _Warning(a1: "ERROR: failed to create zip file '%s'\n", pZipFileName);
    return 0;
  }
  else
  {
    MakeTemporaryFilename(pPath: this->m_PreloadFilename, pathSize: 260);
    v7 = CreateFileA(
           lpFileName: this->m_PreloadFilename,
           dwDesiredAccess: 0xC0000000,
           dwShareMode: 0,
           lpSecurityAttributes: nullptr,
           dwCreationDisposition: 2u,
           dwFlagsAndAttributes: 0x80u,
           hTemplateFile: nullptr);
    this->m_hPreloadFile = v7;
    if ( v7 == (HANDLE)-1 )
    {
      _Warning(a1: "ERROR: failed to create temporary file '%s' for preload data\n", this->m_PreloadFilename);
      CloseHandle(hObject: this->m_hOutputZipFile);
      this->m_hOutputZipFile = (void *)-1;
      return 0;
    }
    else
    {
      *(_QWORD *)&this->m_ZipPreloadHeader.Version = 0;
      *(_QWORD *)&this->m_ZipPreloadHeader.PreloadDirectoryEntries = 0;
      m_pZip = this->m_pZip;
      this->m_ZipPreloadHeader.Alignment = alignment;
      this->m_ZipPreloadHeader.Version = 3;
      m_pZip->AddBufferToZip(this: m_pZip, a2: "__preload_section.pre", a3: nullptr, a4: 0, a5: false);
      CUtlString::CUtlString(this: &remap.filename);
      CUtlString::operator=(this: &remap.filename, src: "__preload_section.pre");
      remap.preloadDirIndex = -1;
      CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::InsertBefore(
        this: &this->m_ZipPreloadRemapEntries,
        elem: this->m_ZipPreloadRemapEntries.m_Size,
        src: &remap);
      remap.filename.m_Storage.m_nActualLength = 0;
      if ( remap.filename.m_Storage.m_Memory.m_nGrowSize >= 0 && remap.filename.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: remap.filename.m_Storage.m_Memory.m_pMemory);
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B070
// Name: public: int CUtlMap<char const __near *,unsigned int,int>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,unsigned int,int>::Insert(
        CUtlMap<char const *,unsigned int,int> *this,
        const char **key)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int> *m_pMemory; // edx
  CUtlMap<char const *,unsigned int,int>::Node_t node; // [esp+8h] [ebp-Ch] BYREF
  int parent; // [esp+10h] [ebp-4h] BYREF

  node.key = *key;
  parent = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    &parent,
    leftchild: (bool *)&key);
  v3 = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v3,
    parent,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = node;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041B0E0
// Name: void GetAlternateFileFixupScript(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetAlternateFileFixupScript()
{
  AlternateFile_t *m_pMemory; // eax
  const char *v1; // eax
  CFmtStrN<256> *v2; // eax
  int m_Size; // eax
  int v4; // esi
  AlternateFile_t *v5; // ecx
  int v6; // eax
  unsigned int v7; // esi
  CUtlString *p_m_Original; // edi
  CFmtStrN<256> v9; // [esp+0h] [ebp-54Ch] BYREF
  char szAlternateList[260]; // [esp+10Ch] [ebp-440h] BYREF
  characterset_t breakSet; // [esp+210h] [ebp-33Ch] BYREF
  char alternateFilename[260]; // [esp+310h] [ebp-23Ch] BYREF
  char originalFilename[260]; // [esp+414h] [ebp-138h] BYREF
  CUtlBuffer alternateListBuffer; // [esp+518h] [ebp-34h] BYREF
  bool bIsOriginal; // [esp+54Bh] [ebp-1h] BYREF

  CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: pDefaultValue);
  CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>::RemoveAll(this: &g_AlternateFileTable);
  m_pMemory = g_AlternateFileTable.m_Memory.m_pMemory;
  if ( g_AlternateFileTable.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_AlternateFileTable.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_AlternateFileTable.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_AlternateFileTable.m_Memory.m_pMemory = nullptr;
    }
    g_AlternateFileTable.m_Memory.m_nAllocationCount = 0;
  }
  g_AlternateFileTable.m_pElements = m_pMemory;
  v1 = "ps3";
  if ( !g_bSonyPS3 )
    v1 = "xbox";
  v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "scripts/zip_alternate_%s.xsc", v1);
  FindScriptFile(pFilename: v2->m_szBuf, pOutBuff: szAlternateList, nOutBuffSize: 260, bCanFallback: true);
  CUtlBuffer::CUtlBuffer(this: &alternateListBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(
         pSourceName: szAlternateList,
         buffer: &alternateListBuffer,
         bText: true,
         bNoOpenFailureWarning: true)
    && CUtlBuffer::ParseToken(
         this: &alternateListBuffer,
         pBreaks: &breakSet,
         pTokenBuf: originalFilename,
         nMaxLen: 260,
         bParseComments: true) > 0 )
  {
    do
    {
      _V_strlower(start: originalFilename);
      V_FixSlashes(pname: originalFilename, separator: 92);
      if ( CUtlBuffer::ParseToken(
             this: &alternateListBuffer,
             pBreaks: &breakSet,
             pTokenBuf: alternateFilename,
             nMaxLen: 260,
             bParseComments: true) <= 0 )
        break;
      _V_strlower(start: alternateFilename);
      V_FixSlashes(pname: alternateFilename, separator: 92);
      if ( IsFilenameAlternateCandidate(
             pFilename: originalFilename,
             &bIsOriginal,
             pOutFilename: nullptr,
             nOutFilenameSize: 0) == 0 )
      {
        m_Size = g_AlternateFileTable.m_Size;
        v4 = g_AlternateFileTable.m_Size;
        if ( g_AlternateFileTable.m_Size + 1 > g_AlternateFileTable.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(
            this: (CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *)&g_AlternateFileTable,
            num: g_AlternateFileTable.m_Size - g_AlternateFileTable.m_Memory.m_nAllocationCount + 1);
          m_Size = g_AlternateFileTable.m_Size;
        }
        v5 = g_AlternateFileTable.m_Memory.m_pMemory;
        g_AlternateFileTable.m_Size = m_Size + 1;
        v6 = m_Size - v4;
        g_AlternateFileTable.m_pElements = g_AlternateFileTable.m_Memory.m_pMemory;
        if ( v6 > 0 )
        {
          _V_memmove(
            dest: &g_AlternateFileTable.m_Memory.m_pMemory[v4 + 1],
            src: &g_AlternateFileTable.m_Memory.m_pMemory[v4],
            count: 32 * v6);
          v5 = g_AlternateFileTable.m_Memory.m_pMemory;
        }
        v7 = v4;
        p_m_Original = &v5[v7].m_Original;
        if ( &v5[v7] != nullptr )
        {
          CUtlString::CUtlString(this: &v5[v7].m_Original);
          CUtlString::CUtlString(this: p_m_Original + 1);
          v5 = g_AlternateFileTable.m_Memory.m_pMemory;
        }
        CUtlString::operator=(this: &v5[v7].m_Original, src: originalFilename);
        CUtlString::operator=(this: &g_AlternateFileTable.m_Memory.m_pMemory[v7].m_Alternate, src: alternateFilename);
      }
    }
    while ( CUtlBuffer::ParseToken(
              this: &alternateListBuffer,
              pBreaks: &breakSet,
              pTokenBuf: originalFilename,
              nMaxLen: 260,
              bParseComments: true) > 0 );
  }
  if ( alternateListBuffer.m_Memory.m_nGrowSize >= 0 && alternateListBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: alternateListBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041B340
// Name: public: CXZipTool::~CXZipTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXZipTool::~CXZipTool(CXZipTool *this)
{
  CXZipTool::Reset(this);
  CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>::~CUtlVector<preloadRemap_t,CUtlMemory<preloadRemap_t,int>>(this: &this->m_ZipPreloadRemapEntries);
  CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>::~CUtlVector<errorList_t,CUtlMemory<errorList_t,int>>(this: (CUtlVector<errorList_t,CUtlMemory<errorList_t,int> > *)&this->m_ZipCRCList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ZipPreloadDirectoryEntries);
}

//------------------------------------------------------------------------------
// Address: 0x0041B3D0
// Name: public: int CUtlDict<unsigned int,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<unsigned int,int>::Insert(CUtlDict<unsigned int,int> *this, char *pName)
{
  const char *v2; // edi
  char *v4; // eax

  v2 = pName;
  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, v2);
    pName = v4;
    return CUtlMap<char const *,unsigned int,int>::Insert(this: &this->m_Elements, key: (const char **)&pName);
  }
  else
  {
    pName = nullptr;
    return CUtlMap<char const *,unsigned int,int>::Insert(this: &this->m_Elements, key: (const char **)&pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B440
// Name: public: CXZipTool::CXZipTool(void)
// Source: json
//------------------------------------------------------------------------------
CXZipTool *__thiscall CXZipTool::CXZipTool(CXZipTool *this)
{
  this->m_ZipPreloadDirectoryEntries.m_Memory.m_pMemory = nullptr;
  this->m_ZipPreloadDirectoryEntries.m_Memory.m_nAllocationCount = 0;
  this->m_ZipPreloadDirectoryEntries.m_Memory.m_nGrowSize = 0;
  this->m_ZipPreloadDirectoryEntries.m_Size = 0;
  this->m_ZipPreloadDirectoryEntries.m_pElements = nullptr;
  this->m_ZipCRCList.m_Memory.m_pMemory = nullptr;
  this->m_ZipCRCList.m_Memory.m_nAllocationCount = 0;
  this->m_ZipCRCList.m_Memory.m_nGrowSize = 0;
  this->m_ZipCRCList.m_Size = 0;
  this->m_ZipCRCList.m_pElements = nullptr;
  this->m_ZipCRCList.m_pLessContext = nullptr;
  this->m_ZipCRCList.m_bNeedsSort = false;
  this->m_ZipPreloadRemapEntries.m_Memory.m_pMemory = nullptr;
  this->m_ZipPreloadRemapEntries.m_Memory.m_nAllocationCount = 0;
  this->m_ZipPreloadRemapEntries.m_Memory.m_nGrowSize = 0;
  this->m_ZipPreloadRemapEntries.m_Size = 0;
  this->m_ZipPreloadRemapEntries.m_pElements = nullptr;
  this->m_pZip = nullptr;
  this->m_hPreloadFile = (void *)-1;
  this->m_hOutputZipFile = (void *)-1;
  this->m_PreloadFilename[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041B4C0
// Name: public: void CXZipTool::SpewPreloadInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXZipTool::SpewPreloadInfo(CXZipTool *this, const char *pZipName)
{
  IZip *Zip; // esi
  void *(__thiscall *ParseFromDisk)(IZip *, const char *); // edx
  int v4; // edi
  unsigned __int8 *m_pMemory; // eax
  bool v6; // zf
  unsigned int PreloadDirectoryEntries; // esi
  unsigned int DirectoryEntries; // edi
  unsigned int v9; // esi
  __int16 Short; // ax
  int v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  ZIP_PreloadDirectoryEntry *v14; // edi
  char *FileExtension; // esi
  int v16; // eax
  int m_NumElements; // edi
  int *p_elem; // esi
  int j; // esi
  char fileName[260]; // [esp+3Ch] [ebp-184h] BYREF
  CUtlBuffer preloadBuffer; // [esp+140h] [ebp-80h] BYREF
  CUtlMap<char const *,unsigned int,int>::Node_t search; // [esp+170h] [ebp-50h] BYREF
  ZIP_PreloadHeader header; // [esp+178h] [ebp-48h] BYREF
  CUtlDict<unsigned int,int> sizes; // [esp+188h] [ebp-38h] BYREF
  unsigned int i; // [esp+1ACh] [ebp-14h]
  ZIP_PreloadDirectoryEntry *pDir; // [esp+1B0h] [ebp-10h]
  int fileSize; // [esp+1B4h] [ebp-Ch] BYREF
  IZip *pZip; // [esp+1B8h] [ebp-8h]
  int zipIndex; // [esp+1BCh] [ebp-4h]
  unsigned __int16 *pRemap; // [esp+1C8h] [ebp+8h]

  Zip = IZip::CreateZip(pDiskCacheWritePath: nullptr, bSortByName: true);
  ParseFromDisk = Zip->ParseFromDisk;
  pZip = Zip;
  v4 = (int)ParseFromDisk(this: Zip, a2: pZipName);
  if ( v4 == 0 )
  {
    _Warning(a1: "Bad or missing zip file, failed to open '%s'\n", pZipName);
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &preloadBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !Zip->ReadFileFromZip(this: Zip, a2: (void *)v4, a3: "__preload_section.pre", a4: false, a5: &preloadBuffer) )
  {
    _Msg(a1: "No preload info for '%s'\n", pZipName);
    if ( preloadBuffer.m_Memory.m_nGrowSize < 0 )
      return;
    m_pMemory = preloadBuffer.m_Memory.m_pMemory;
    v6 = preloadBuffer.m_Memory.m_pMemory == nullptr;
    goto LABEL_28;
  }
  CUtlBuffer::ActivateByteSwapping(this: &preloadBuffer, bActivate: true);
  CUtlBuffer::GetObjects<ZIP_PreloadHeader>(this: &preloadBuffer, dest: &header, count: 1);
  PreloadDirectoryEntries = header.PreloadDirectoryEntries;
  pDir = (ZIP_PreloadDirectoryEntry *)MemAlloc_Alloc(nSize: 8 * header.PreloadDirectoryEntries);
  CUtlBuffer::GetObjects<ZIP_PreloadDirectoryEntry>(this: &preloadBuffer, dest: pDir, count: PreloadDirectoryEntries);
  DirectoryEntries = header.DirectoryEntries;
  v9 = 0;
  for ( pRemap = (unsigned __int16 *)MemAlloc_Alloc(nSize: 2 * header.DirectoryEntries); v9 < DirectoryEntries; ++v9 )
  {
    Short = CUtlBuffer::GetShort(this: &preloadBuffer);
    DirectoryEntries = header.DirectoryEntries;
    pRemap[v9] = Short;
  }
  v11 = -1;
  v12 = 0;
  memset(&sizes.m_Elements.m_Tree.m_Elements, 0, sizeof(sizes.m_Elements.m_Tree.m_Elements));
  sizes.m_Elements.m_Tree.m_NumElements = 0;
  sizes.m_Elements.m_Tree.m_pElements = nullptr;
  sizes.m_Elements.m_Tree.m_Root = -1;
  sizes.m_Elements.m_Tree.m_FirstFree = -1;
  sizes.m_Elements.m_Tree.m_LastAlloc.index = -1;
  sizes.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  i = 0;
  if ( DirectoryEntries != 0 )
  {
    while ( 1 )
    {
      fileName[0] = 0;
      fileSize = 0;
      zipIndex = pZip->GetNextFilename(this: pZip, a2: v11, a3: fileName, a4: 260, a5: &fileSize);
      v13 = pRemap[v12];
      if ( (_WORD)v13 != 0xFFFF )
      {
        v14 = &pDir[v13];
        _Msg(a1: "Offset: 0x%8.8x Length: %5d %s (%d)\n", v14->DataOffset, v14->Length, fileName, fileSize);
        FileExtension = (char *)V_GetFileExtension(path: fileName);
        if ( FileExtension == nullptr )
          FileExtension = "???";
        search.key = FileExtension;
        v16 = CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::Find(
                this: &sizes.m_Elements.m_Tree,
                &search);
        if ( v16 == -1 )
        {
          v16 = CUtlDict<unsigned int,int>::Insert(this: &sizes, pName: FileExtension);
          sizes.m_Elements.m_Tree.m_Elements.m_pMemory[v16].m_Data.elem = 0;
        }
        v12 = i;
        sizes.m_Elements.m_Tree.m_Elements.m_pMemory[v16].m_Data.elem += v14->Length;
      }
      i = ++v12;
      if ( v12 >= header.DirectoryEntries )
        break;
      v11 = zipIndex;
    }
  }
  _Msg(a1: "\n");
  _Msg(a1: "Preload Size:    %.2f MB\n", (float)((float)preloadBuffer.m_nMaxPut * 0.00000095367432));
  _Msg(a1: "Zip Entries:     %d\n", header.DirectoryEntries);
  _Msg(a1: "Preload Entries: %d\n", header.PreloadDirectoryEntries);
  if ( sizes.m_Elements.m_Tree.m_NumElements != 0 )
  {
    m_NumElements = sizes.m_Elements.m_Tree.m_NumElements;
    p_elem = (int *)&sizes.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem;
    do
    {
      zipIndex = *p_elem;
      _Msg(
        a1: "Extension: '%3s' %d bytes (%.2f%s)\n",
        (const char *)*(p_elem - 1),
        zipIndex,
        (double)(unsigned int)zipIndex / (double)preloadBuffer.m_nMaxPut * 100.0,
        "%%");
      p_elem += 6;
      --m_NumElements;
    }
    while ( m_NumElements != 0 );
  }
  _Msg(a1: "\n");
  free(pMem: pRemap);
  free(pMem: pDir);
  IZip::ReleaseZip(pZip);
  for ( j = CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::FirstInorder(this: &sizes.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::NextInorder(
              this: &sizes.m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)sizes.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::RemoveAll(this: &sizes.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,unsigned int,int>::Node_t,int,CUtlMap<char const *,unsigned int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,unsigned int,int>::Node_t,int>,int>>::RemoveAll(this: &sizes.m_Elements.m_Tree);
  if ( sizes.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && sizes.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sizes.m_Elements.m_Tree.m_Elements.m_pMemory);
  if ( preloadBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = preloadBuffer.m_Memory.m_pMemory;
    v6 = preloadBuffer.m_Memory.m_pMemory == nullptr;
LABEL_28:
    if ( !v6 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B57E0
// Name: public: int CUtlSortVector<struct SceneImageEntry_t,class CSceneImageEntryLessFunc>::FindLessOrEqual(struct SceneImageEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::FindLessOrEqual(
        CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> *this,
        const SceneImageEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  SceneImageEntry_t *m_pMemory; // ebx
  unsigned int crcFilename; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    crcFilename = src->crcFilename;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].crcFilename;
      if ( crcFilename <= v8 )
      {
        if ( crcFilename >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B58C0
// Name: public: int CUtlSortVector<struct SceneImageEntry_t,class CSceneImageEntryLessFunc>::Find(struct SceneImageEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Find(
        CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> *this,
        const SceneImageEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  SceneImageEntry_t *m_pMemory; // ebx
  unsigned int crcFilename; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    crcFilename = src->crcFilename;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].crcFilename;
      if ( crcFilename <= v8 )
      {
        if ( crcFilename >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B5A70
// Name: public: int CUtlSortVector<struct SceneImageEntry_t,class CSceneImageEntryLessFunc>::Insert(struct SceneImageEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Insert(
        CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> *this,
        const SceneImageEntry_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  SceneImageEntry_t *m_pMemory; // ecx
  int v8; // eax
  SceneImageEntry_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResourceCopy_t,int>::Grow((CUtlMemory<ResourceCopy_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 16 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004B79D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CDmElementFactoryHelper __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: m_pMemory,
                                                                                                 a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF2F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1850
// Name: public: int CUtlDict<struct EventGroup,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Find(CUtlDict<EventGroup,int> *this, const char *pName)
{
  int v2; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t search; // [esp+0h] [ebp-20h] BYREF

  if ( pName == nullptr )
    return -1;
  search.elem.timeSortedEvents.m_Root = -1;
  memset(&search.elem.timeSortedEvents.m_Elements, 0, sizeof(search.elem.timeSortedEvents.m_Elements));
  search.elem.timeSortedEvents.m_pElements = nullptr;
  search.elem.timeSortedEvents.m_NumElements = 0;
  search.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  search.elem.timeSortedEvents.m_FirstFree = -1;
  search.elem.timeSortedEvents.m_LastAlloc.index = -1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &search.elem.timeSortedEvents);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004C1A00
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004C1A50
// Name: public: int CUtlDict<struct EventGroup,int>::Insert(char const __near *,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Insert(
        CUtlDict<EventGroup,int> *this,
        const char *pName,
        const EventGroup *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *p_m_Tree; // [esp+2Ch] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  insert.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  memset(&insert.elem.timeSortedEvents.m_Elements, 0, sizeof(insert.elem.timeSortedEvents.m_Elements));
  *(_DWORD *)&insert.elem.timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&insert.elem.timeSortedEvents.m_FirstFree = -1;
  insert.elem.timeSortedEvents.m_pElements = nullptr;
  EventGroup::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         &insert);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &insert.elem.timeSortedEvents);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004C9890
// Name: public: void CUtlDict<class CDmElementFactoryHelper __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElementFactoryHelper *,int>::RemoveAll(CUtlDict<CDmElementFactoryHelper *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004CA500
// Name: public: int CUtlMap<char const __near *,class CDmElementFactoryHelper __near *,int>::Insert(char const __near * const __near &,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
        CUtlMap<char const *,CDmElementFactoryHelper *,int> *this,
        const char **key,
        int insert)
{
  CDmElementFactoryHelper *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CDmElementFactoryHelper **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004CB2D0
// Name: public: int CUtlDict<class CDmElementFactoryHelper __near *,int>::Insert(char const __near *,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElementFactoryHelper *,int>::Insert(
        CUtlDict<CDmElementFactoryHelper *,int> *this,
        char *pName,
        CDmElementFactoryHelper *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x0050D600
// Name: public: void CUtlDict<class CDmElement __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElement *,int>::RemoveAll(CUtlDict<CDmElement *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0050E280
// Name: public: int CUtlMap<char const __near *,class CDmElement __near *,int>::Insert(char const __near * const __near &,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CDmElement *,int>::Insert(
        CUtlMap<char const *,CDmElement *,int> *this,
        const char **key,
        int insert)
{
  CDmElement *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CDmElement *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CDmElement **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0050ED10
// Name: public: int CUtlDict<class CDmElement __near *,int>::Insert(char const __near *,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElement *,int>::Insert(
        CUtlDict<CDmElement *,int> *this,
        char *pName,
        CDmElement *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElement *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x0041B820
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}
