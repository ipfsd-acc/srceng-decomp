// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/overwatch/overwatch_service/overwatch_service.cpp
// Functions: 17
// ============================================================

#include "utils\overwatch\overwatch_service\overwatch_service.h"

//------------------------------------------------------------------------------
// Address: 0x00402760
// Name: public: void __near * CLinearMemoryAllocator::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLinearMemoryAllocator::Alloc(CLinearMemoryAllocator *this, unsigned int nBytes)
{
  unsigned int v2; // edx
  unsigned __int8 *result; // eax

  v2 = 4 * ((this->m_nCurOffset + 3) >> 2);
  result = &this->m_pBase[v2];
  this->m_nCurOffset = nBytes + v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402780
// Name: bool LockMutex(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl LockMutex(void *hMutex, DWORD nTimeout)
{
  return WaitForSingleObject(hHandle: hMutex, dwMilliseconds: nTimeout) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004027A0
// Name: public: class COffsetPtr<class CWatchedDir> __near & COffsetPtr<class CWatchedDir>::operator=(class CWatchedDir __near *)
// Source: json
//------------------------------------------------------------------------------
COffsetPtr<CWatchedFile> *__thiscall COffsetPtr<CWatchedDir>::operator=(
        COffsetPtr<CWatchedFile> *this,
        CWatchedFile *p)
{
  COffsetPtr<CWatchedFile> *result; // eax

  result = this;
  if ( p != nullptr )
    this->m_nOffset = (char *)p - (char *)this;
  else
    this->m_nOffset = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004027C0
// Name: public: class COffsetPtr<class CWatchedFile> __near & COffsetPtr<class CWatchedFile>::operator=(class COffsetPtr<class CWatchedFile> __near &)
// Source: json
//------------------------------------------------------------------------------
COffsetPtr<CWatchedFile> *__thiscall COffsetPtr<CWatchedFile>::operator=(
        COffsetPtr<CWatchedFile> *this,
        COffsetPtr<CWatchedFile> *p)
{
  COffsetPtr<CWatchedFile> *result; // eax
  int m_nOffset; // ecx

  result = this;
  m_nOffset = p->m_nOffset;
  if ( p->m_nOffset != 0 && (COffsetPtr<CWatchedFile> *)((char *)p + m_nOffset) != nullptr )
    result->m_nOffset = (char *)p + m_nOffset - (char *)result;
  else
    result->m_nOffset = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004027E0
// Name: private: class CWatchedDir __near * COverwatchService::AddChildDir(class CWatchedDir __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall COverwatchService::AddChildDir(
        COverwatchService *this,
        CWatchedDir *pDir,
        const char *pShortName,
        const char *pLongName)
{
  CLinearMemoryAllocator *p_m_Allocator; // edi
  unsigned int v6; // eax
  CWatchedDir *v7; // esi
  COffsetPtr<CWatchedDir> *p_m_pNextChildDir; // edx
  char *v9; // ecx
  int m_nOffset; // ecx
  char *v11; // eax
  COffsetPtr<char> *p_m_pShortName; // ecx
  char *v13; // eax
  COffsetPtr<char> *p_m_pLongName; // ecx

  WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
  p_m_Allocator = &this->m_Allocator;
  v6 = 4 * ((this->m_Allocator.m_nCurOffset + 3) >> 2);
  v7 = (CWatchedDir *)&this->m_Allocator.m_pBase[v6];
  this->m_Allocator.m_nCurOffset = v6 + 28;
  CWatchedDir::Init(this: v7);
  ++this->m_pOverwatchHeader->m_Stats.m_nDirectoryEntriesCreated;
  p_m_pNextChildDir = &v7->m_pNextChildDir;
  if ( pDir->m_pFirstChildDir.m_nOffset != 0 && (v9 = (char *)pDir + pDir->m_pFirstChildDir.m_nOffset) != nullptr )
    p_m_pNextChildDir->m_nOffset = v9 - (char *)p_m_pNextChildDir;
  else
    p_m_pNextChildDir->m_nOffset = 0;
  if ( v7 != nullptr )
    pDir->m_pFirstChildDir.m_nOffset = (char *)v7 - (char *)pDir;
  else
    pDir->m_pFirstChildDir.m_nOffset = 0;
  m_nOffset = pDir->m_pWatchedDirectoryRoot.m_nOffset;
  if ( m_nOffset == 0 || (CWatchedDir *)((char *)pDir + m_nOffset) == (CWatchedDir *)-12 )
    v7->m_pWatchedDirectoryRoot.m_nOffset = 0;
  else
    v7->m_pWatchedDirectoryRoot.m_nOffset = (char *)pDir + m_nOffset - (char *)v7;
  v11 = CLinearMemoryAllocator::CopyString(this: p_m_Allocator, pStr: pShortName);
  p_m_pShortName = &v7->m_pShortName;
  if ( v11 != nullptr )
    p_m_pShortName->m_nOffset = v11 - (char *)p_m_pShortName;
  else
    p_m_pShortName->m_nOffset = 0;
  v13 = CLinearMemoryAllocator::CopyString(this: p_m_Allocator, pStr: pLongName);
  p_m_pLongName = &v7->m_pLongName;
  if ( v13 != nullptr )
    p_m_pLongName->m_nOffset = v13 - (char *)p_m_pLongName;
  else
    p_m_pLongName->m_nOffset = 0;
  ReleaseMutex(hMutex: this->m_hDataMutex);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004028D0
// Name: private: class CWatchedDir __near * COverwatchService::FindOrAddChildDir(class CWatchedDir __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall COverwatchService::FindOrAddChildDir(
        COverwatchService *this,
        CWatchedDir *pLastDir,
        char *pDirName,
        char *pCurDirBase,
        char *pCur)
{
  CWatchedDir *result; // eax
  unsigned int v7; // esi
  unsigned int v8; // edi
  int m_nOffset; // ecx
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pWatchedDirectoryRoot; // edx
  char *v11; // ecx
  char szShortName[260]; // [esp+4h] [ebp-20Ch] BYREF
  char szLongName[264]; // [esp+108h] [ebp-108h] BYREF

  if ( pCur == pCurDirBase )
    return pLastDir;
  v7 = pCur - pCurDirBase;
  if ( pCur - pCurDirBase >= 259 )
    v7 = 259;
  memcpy(dst: (unsigned __int8 *)&szShortName[4], src: (unsigned __int8 *)pCurDirBase, count: v7);
  szShortName[v7 + 4] = 0;
  result = CWatchedDir::FindChildDir(this: pLastDir, pLongDirName: &szShortName[4]);
  if ( result == nullptr )
  {
    v8 = pCur - pDirName;
    if ( pCur - pDirName >= 259 )
      v8 = 259;
    memcpy(dst: (unsigned __int8 *)&szLongName[4], src: (unsigned __int8 *)pDirName, count: v8);
    szLongName[v8 + 4] = 0;
    result = COverwatchService::AddChildDir(
               this,
               pDir: pLastDir,
               pShortName: &szShortName[4],
               pLongName: &szLongName[4]);
    m_nOffset = pLastDir->m_pWatchedDirectoryRoot.m_nOffset;
    p_m_pWatchedDirectoryRoot = &result->m_pWatchedDirectoryRoot;
    if ( m_nOffset != 0 && (v11 = (char *)&pLastDir->m_pWatchedDirectoryRoot + m_nOffset) != nullptr )
      p_m_pWatchedDirectoryRoot->m_nOffset = v11 - (char *)p_m_pWatchedDirectoryRoot;
    else
      p_m_pWatchedDirectoryRoot->m_nOffset = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004029C0
// Name: private: class CWatchedDir __near * COverwatchService::CreateWatchedDir(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall COverwatchService::CreateWatchedDir(
        COverwatchService *this,
        char *pLongFilename,
        bool bIncludeLastSection)
{
  CWatchedDir *result; // eax
  char *v5; // ecx
  char *i; // esi

  result = &this->m_pOverwatchHeader->m_RootDir;
  v5 = pLongFilename;
  for ( i = pLongFilename; *i != 0; ++i )
  {
    if ( *i == 47 || *i == 92 )
    {
      result = COverwatchService::FindOrAddChildDir(
                 this,
                 pLastDir: result,
                 pDirName: pLongFilename,
                 pCurDirBase: v5,
                 pCur: i);
      v5 = i + 1;
    }
  }
  if ( bIncludeLastSection )
    return COverwatchService::FindOrAddChildDir(
             this,
             pLastDir: result,
             pDirName: pLongFilename,
             pCurDirBase: v5,
             pCur: i);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402A20
// Name: private: void COverwatchService::SetFileStats(char const __near *,unsigned __int64,struct _FILETIME __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::SetFileStats(
        COverwatchService *this,
        char *pLongFilename,
        unsigned __int64 nFileSize,
        _FILETIME *pModifiedTime)
{
  char *v4; // ebx
  CWatchedFile *v6; // esi
  int v7; // edx
  _FILETIME *v8; // eax
  bool v9; // zf
  CWatchedDir *WatchedDir; // eax
  CWatchedDir *v11; // ebp
  int m_nOffset; // eax
  int v13; // eax
  CWatchedDirectoryRoot *v14; // ecx
  unsigned int v15; // ebx
  unsigned __int8 *v16; // esi
  _FILETIME *v17; // eax
  unsigned int v18; // ebx
  int nLongDirNameChars; // [esp+Ch] [ebp-Ch] BYREF
  const char *pExtension; // [esp+10h] [ebp-8h] BYREF
  char *pExt; // [esp+14h] [ebp-4h] BYREF

  v4 = pLongFilename;
  COverwatchHeader::GetFilenameComponents(
    this: this->m_pOverwatchHeader,
    pFullFilename: pLongFilename,
    pShortFilename: (const char **)&pLongFilename,
    pnShortFilenameChars: &nLongDirNameChars,
    pnLongDirNameChars: (int *)&pExtension,
    pExtension: (const char **)&pExt);
  v6 = COverwatchHeader::LookupFile(
         this: this->m_pOverwatchHeader,
         pShortFilename: pLongFilename,
         nShortFilenameChars: nLongDirNameChars,
         pLongDirName: v4,
         nLongDirNameChars: (int)pExtension);
  if ( v6 != nullptr )
  {
    WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
    v7 = nFileSize;
    HIDWORD(v6->m_nFileSize) = HIDWORD(nFileSize);
    v8 = pModifiedTime;
    v9 = pModifiedTime == nullptr;
    v6->m_bCRCValid = false;
    LODWORD(v6->m_nFileSize) = v7;
    if ( !v9 )
    {
      v6->m_ModifiedTime.dwLowDateTime = v8->dwLowDateTime;
      v6->m_ModifiedTime.dwHighDateTime = v8->dwHighDateTime;
    }
    ReleaseMutex(hMutex: this->m_hDataMutex);
  }
  else if ( (HIDWORD(nFileSize) & (unsigned int)nFileSize) != 0xFFFFFFFF )
  {
    WatchedDir = COverwatchService::CreateWatchedDir(this, pLongFilename: v4, bIncludeLastSection: false);
    v11 = WatchedDir;
    if ( WatchedDir != nullptr )
    {
      m_nOffset = WatchedDir->m_pWatchedDirectoryRoot.m_nOffset;
      if ( m_nOffset != 0 && (CWatchedDir *)((char *)v11 + m_nOffset) != (CWatchedDir *)-12 )
      {
        v13 = v11->m_pWatchedDirectoryRoot.m_nOffset;
        v14 = v13 != 0 ? (CWatchedDirectoryRoot *)((char *)&v11->m_pWatchedDirectoryRoot + v13) : nullptr;
        if ( !CWatchedDirectoryRoot::ShouldIgnoreExtension(this: v14, pExt) )
        {
          v15 = strlen(pLongFilename);
          v16 = CLinearMemoryAllocator::Alloc(this: &this->m_Allocator, nBytes: v15 + 40);
          ++this->m_pOverwatchHeader->m_Stats.m_nFileEntriesCreated;
          V_strncpy(pDest: (char *)v16 + 36, pSrc: pLongFilename, maxLen: v15 + 1);
          LockMutex(hMutex: this->m_hDataMutex, nTimeout: 0xFFFFFFFF);
          COffsetPtr<CWatchedFile>::operator=(this: (COffsetPtr<CWatchedFile> *)v16 + 5, p: &v11->m_pFirstFile);
          COffsetPtr<CWatchedDir>::operator=(this: &v11->m_pFirstFile, p: (CWatchedFile *)v16);
          COffsetPtr<CWatchedDir>::operator=(this: (COffsetPtr<CWatchedFile> *)v16 + 6, p: (CWatchedFile *)v11);
          v17 = pModifiedTime;
          *(_QWORD *)v16 = nFileSize;
          *((_FILETIME *)v16 + 1) = *v17;
          v16[28] = 0;
          v18 = 4
              * COverwatchHeader::HashFilename(
                  this: this->m_pOverwatchHeader,
                  pFilename: pLongFilename,
                  nChars: nLongDirNameChars)
              + 1384;
          COffsetPtr<CWatchedFile>::operator=(
            this: (COffsetPtr<CWatchedFile> *)v16 + 4,
            p: (COffsetPtr<CWatchedFile> *)((char *)this->m_pOverwatchHeader + v18));
          COffsetPtr<CWatchedDir>::operator=(
            this: (COffsetPtr<CWatchedFile> *)((char *)this->m_pOverwatchHeader + v18),
            p: (CWatchedFile *)v16);
          ReleaseMutex(hMutex: this->m_hDataMutex);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C00
// Name: private: void COverwatchService::CommitQueuedFileStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::CommitQueuedFileStats(COverwatchService *this)
{
  int m_nQueuedFileStats; // eax
  int v3; // ebx
  char *m_Filename; // esi

  m_nQueuedFileStats = this->m_nQueuedFileStats;
  if ( m_nQueuedFileStats != 0 )
  {
    v3 = 0;
    if ( m_nQueuedFileStats > 0 )
    {
      m_Filename = this->m_QueuedFileStats[0].m_Filename;
      do
      {
        COverwatchService::SetFileStats(
          this,
          pLongFilename: m_Filename,
          nFileSize: *((unsigned int *)m_Filename - 1),
          pModifiedTime: (_FILETIME *)(m_Filename - 12));
        ++v3;
        m_Filename += 272;
      }
      while ( v3 < this->m_nQueuedFileStats );
    }
    this->m_nQueuedFileStats = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C50
// Name: private: void COverwatchService::QueueFileStats(char const __near *,unsigned __int64,struct _FILETIME)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::QueueFileStats(
        COverwatchService *this,
        const char *pFilename,
        unsigned __int64 nFileSize,
        _FILETIME modifiedTime)
{
  COverwatchService::CQueuedFileStat *v5; // esi

  if ( this->m_nQueuedFileStats + 1 >= 20 )
    COverwatchService::CommitQueuedFileStats(this);
  v5 = &this->m_QueuedFileStats[this->m_nQueuedFileStats++];
  V_strncpy(pDest: v5->m_Filename, pSrc: pFilename, maxLen: 260);
  v5->m_ModifiedTime = modifiedTime;
  v5->m_nFileSize = nFileSize;
}

//------------------------------------------------------------------------------
// Address: 0x00402CB0
// Name: private: int COverwatchService::CheckSignals(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COverwatchService::CheckSignals(COverwatchService *this)
{
  COverwatchHeader *m_pOverwatchHeader; // eax
  int v3; // ebx
  COverwatchHeader *v4; // eax
  CFileChangeWatcher::CFileChange *v5; // ebp
  HANDLE FirstFileA; // edi
  CWatchedFile *v7; // edi
  bool v8; // cc
  COverwatchHeader *v9; // edx
  AppSignalType_t m_eSignalType; // eax
  int v11; // edi
  const char *v12; // ebp
  HANDLE v13; // eax
  void *v14; // edi
  int i; // [esp+10h] [ebp-268h]
  int pnLongDirNameChars; // [esp+14h] [ebp-264h] BYREF
  char *pShortFilename; // [esp+18h] [ebp-260h] BYREF
  int pnShortFilenameChars; // [esp+1Ch] [ebp-25Ch] BYREF
  CSharedMemoryMgr v20; // [esp+20h] [ebp-258h] BYREF
  char szFilename[260]; // [esp+30h] [ebp-248h] BYREF
  _WIN32_FIND_DATAA findData; // [esp+134h] [ebp-144h] BYREF

  m_pOverwatchHeader = this->m_pOverwatchHeader;
  LODWORD(m_pOverwatchHeader->m_Stats.m_nMemoryBytesUsed) = this->m_Allocator.m_nCurOffset;
  v3 = 0;
  HIDWORD(m_pOverwatchHeader->m_Stats.m_nMemoryBytesUsed) = 0;
  v4 = this->m_pOverwatchHeader;
  LODWORD(v4->m_Stats.m_nMemoryBytesLimit) = this->m_Allocator.m_nMaxBytes;
  HIDWORD(v4->m_Stats.m_nMemoryBytesLimit) = 0;
  i = 0;
  v5 = CFileChangeWatcher::Update(this: &this->m_FileChangeWatcher);
  if ( v5 != nullptr )
  {
    do
    {
      ++i;
      CFileChangeWatcher::CFileChange::GetFullFilename(this: v5, pOut: &szFilename[4], nMaxBytes: 260);
      _Msg(a1: "Noted a change to %s\n", &szFilename[4]);
      ++this->m_pOverwatchHeader->m_Stats.m_nFilesIterated;
      FirstFileA = FindFirstFileA(
                     lpFileName: &szFilename[4],
                     lpFindFileData: (LPWIN32_FIND_DATAA)&findData.ftCreationTime);
      if ( FirstFileA == (HANDLE)-1 )
      {
        COverwatchHeader::GetFilenameComponents(
          this: this->m_pOverwatchHeader,
          pFullFilename: &szFilename[4],
          (const char **)&pShortFilename,
          &pnShortFilenameChars,
          &pnLongDirNameChars,
          pExtension: (const char **)szFilename);
        v7 = COverwatchHeader::LookupFile(
               this: this->m_pOverwatchHeader,
               pShortFilename,
               nShortFilenameChars: pnShortFilenameChars,
               pLongDirName: &szFilename[4],
               nLongDirNameChars: pnLongDirNameChars);
        if ( v7 != nullptr )
        {
          WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
          v7->m_bCRCValid = false;
          LODWORD(v7->m_nFileSize) = -1;
          HIDWORD(v7->m_nFileSize) = -1;
          ReleaseMutex(hMutex: this->m_hDataMutex);
        }
      }
      else
      {
        if ( (findData.ftCreationTime.dwLowDateTime & 0x10) == 0 )
          COverwatchService::SetFileStats(
            this,
            pLongFilename: &szFilename[4],
            nFileSize: findData.dwReserved0,
            pModifiedTime: (_FILETIME *)&findData.ftLastWriteTime.dwHighDateTime);
        FindClose(hFindFile: FirstFileA);
      }
      v5 = v5->m_pNext;
    }
    while ( v5 != nullptr );
    v3 = 0;
  }
  WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
  v8 = this->m_pOverwatchHeader->m_nAppSignals <= 0;
  pnLongDirNameChars = 0;
  if ( !v8 )
  {
    do
    {
      v9 = this->m_pOverwatchHeader;
      m_eSignalType = v9->m_AppSignals[v3].m_eSignalType;
      ++i;
      v11 = (int)&v9->m_AppSignals[v3];
      if ( m_eSignalType == APPSIGNAL_GET_NUM_FILES_SCANNED )
      {
        CSharedMemoryMgr::CSharedMemoryMgr(this: &v20);
        if ( CSharedMemoryMgr::Open(this: &v20, pSharedName: (const char *)(v11 + 264), nBytes: 4u) )
          *(_DWORD *)v20.m_pStart = this->m_nFilesScanned;
        else
          _Warning(a1: "Unable to write CAppSignal response to %s!\n", (const char *)(v11 + 264));
        CSharedMemoryMgr::~CSharedMemoryMgr(this: &v20);
      }
      else if ( m_eSignalType == APPSIGNAL_EXIT )
      {
        this->m_bExit = true;
      }
      v12 = (const char *)(v11 + 296);
      v13 = OpenEventA(dwDesiredAccess: 2u, bInheritHandle: false, lpName: (LPCSTR)(v11 + 296));
      v14 = v13;
      if ( v13 != nullptr )
      {
        SetEvent(hEvent: v13);
        CloseHandle(hObject: v14);
      }
      else
      {
        _Warning(a1: "Unable to set CAppSignal event response for %s!\n", v12);
      }
      if ( this->m_bExit )
        break;
      ++v3;
      v8 = ++pnLongDirNameChars < this->m_pOverwatchHeader->m_nAppSignals;
    }
    while ( v8 );
  }
  this->m_pOverwatchHeader->m_nAppSignals = 0;
  ReleaseMutex(hMutex: this->m_hDataMutex);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00402F30
// Name: private: bool COverwatchService::Scan_R(class CWatchedDir __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverwatchService::Scan_R(COverwatchService *this, CWatchedDir *pDir, const char *pDirBase)
{
  HANDLE FirstFileA; // ebp
  CWatchedDir *ChildDir; // eax
  _FILETIME v7; // rax
  unsigned int dwReserved0; // ecx
  _WIN32_FIND_DATAA findData; // [esp+4h] [ebp-34Ch] BYREF
  char szFullName[260]; // [esp+144h] [ebp-20Ch] BYREF
  char szSearch[264]; // [esp+248h] [ebp-108h] BYREF

  if ( pDir->m_bUpToDate )
    return 1;
  V_ComposeFileName(path: pDirBase, filename: "*.*", dest: &szSearch[4], destSize: 260);
  HIBYTE(findData.dwFileAttributes) = 1;
  FirstFileA = FindFirstFileA(lpFileName: &szSearch[4], lpFindFileData: (LPWIN32_FIND_DATAA)&findData.ftCreationTime);
  if ( FirstFileA == (HANDLE)-1 )
    goto LABEL_11;
  while ( 1 )
  {
    if ( findData.cFileName[4] != 46 )
    {
      ++this->m_pOverwatchHeader->m_Stats.m_nFilesIterated;
      V_ComposeFileName(path: pDirBase, filename: &findData.cFileName[4], dest: &szFullName[4], destSize: 260);
      if ( (findData.ftCreationTime.dwLowDateTime & 0x10) != 0 )
        break;
      v7 = *(_FILETIME *)&findData.ftLastWriteTime.dwHighDateTime;
      dwReserved0 = findData.dwReserved0;
      ++this->m_nFilesScanned;
      COverwatchService::QueueFileStats(this, pFilename: &szFullName[4], nFileSize: dwReserved0, modifiedTime: v7);
      ++this->m_nCheckSignalsCounter;
      if ( (this->m_nCheckSignalsCounter & 0xF) == 0 )
      {
        COverwatchService::CheckSignals(this);
        if ( this->m_bExit )
          goto LABEL_10;
      }
    }
LABEL_15:
    if ( !FindNextFileA(hFindFile: FirstFileA, lpFindFileData: (LPWIN32_FIND_DATAA)&findData.ftCreationTime) )
      goto LABEL_10;
  }
  ChildDir = CWatchedDir::FindChildDir(this: pDir, pLongDirName: &findData.cFileName[4]);
  if ( ChildDir == nullptr )
    ChildDir = COverwatchService::AddChildDir(this, pDir, pShortName: &findData.cFileName[4], pLongName: &szFullName[4]);
  if ( COverwatchService::Scan_R(this, pDir: ChildDir, pDirBase: &szFullName[4]) )
    goto LABEL_15;
  HIBYTE(findData.dwFileAttributes) = 0;
LABEL_10:
  FindClose(hFindFile: FirstFileA);
  if ( HIBYTE(findData.dwFileAttributes) != 0 )
LABEL_11:
    pDir->m_bUpToDate = true;
  return HIBYTE(findData.dwFileAttributes);
}

//------------------------------------------------------------------------------
// Address: 0x004030B0
// Name: private: void COverwatchService::Scan(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::Scan(COverwatchService *this)
{
  COverwatchHeader *m_pOverwatchHeader; // eax
  int m_nOffset; // ecx
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pFirstWatchedDirectoryRoot; // eax
  CWatchedDir *v5; // esi
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  int m_nQueuedFileStats; // eax
  int v14; // edi
  char *m_Filename; // esi
  int v16; // [esp+8h] [ebp-4h]

  while ( !this->m_bExit )
  {
    m_pOverwatchHeader = this->m_pOverwatchHeader;
    m_nOffset = m_pOverwatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset;
    p_m_pFirstWatchedDirectoryRoot = &m_pOverwatchHeader->m_pFirstWatchedDirectoryRoot;
    v16 = 0;
    if ( m_nOffset != 0 )
    {
      v5 = (CWatchedDir *)((char *)p_m_pFirstWatchedDirectoryRoot + m_nOffset);
      if ( (COffsetPtr<CWatchedDirectoryRoot> *)((char *)p_m_pFirstWatchedDirectoryRoot + m_nOffset) != nullptr )
      {
        while ( 1 )
        {
          if ( LOBYTE(v5[1].m_pFirstChildDir.m_nOffset) == 0 )
          {
            v6 = v5->m_pLongName.m_nOffset;
            ++v16;
            if ( v6 != 0 )
              v7 = (char *)&v5->m_pLongName + v6;
            else
              v7 = nullptr;
            _Msg(a1: "Scanning directory %s\n", v7);
            v8 = v5->m_pLongName.m_nOffset;
            if ( v8 != 0 )
              v9 = (char *)&v5->m_pLongName + v8;
            else
              v9 = nullptr;
            if ( COverwatchService::Scan_R(this, pDir: v5, pDirBase: v9) == 0 )
              break;
            v10 = v5->m_pLongName.m_nOffset;
            if ( v10 != 0 )
              v11 = (char *)&v5->m_pLongName + v10;
            else
              v11 = nullptr;
            _Msg(a1: "Finished scanning directory %s\n", v11);
            LOBYTE(v5[1].m_pFirstChildDir.m_nOffset) = 1;
          }
          v12 = v5[1].m_pNextChildDir.m_nOffset;
          if ( v12 != 0 )
          {
            v5 = (CWatchedDir *)((char *)v5 + v12 + 32);
            if ( v5 != nullptr )
              continue;
          }
          break;
        }
      }
    }
    m_nQueuedFileStats = this->m_nQueuedFileStats;
    if ( m_nQueuedFileStats != 0 )
    {
      v14 = 0;
      if ( m_nQueuedFileStats > 0 )
      {
        m_Filename = this->m_QueuedFileStats[0].m_Filename;
        do
        {
          COverwatchService::SetFileStats(
            this,
            pLongFilename: m_Filename,
            nFileSize: *((unsigned int *)m_Filename - 1),
            pModifiedTime: (_FILETIME *)(m_Filename - 12));
          ++v14;
          m_Filename += 272;
        }
        while ( v14 < this->m_nQueuedFileStats );
      }
      this->m_nQueuedFileStats = 0;
    }
    if ( v16 == 0 && COverwatchService::CheckSignals(this) == 0 )
      _ThreadSleep(a1: 50);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004031D0
// Name: private: void COverwatchService::StartWatchingDirectory(char const __near *,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::StartWatchingDirectory(
        COverwatchService *this,
        CFileChangeWatcher::CDirWatch *pDirName,
        const char **pIgnoreExtensions)
{
  COverwatchService *v3; // edi
  CLinearMemoryAllocator *p_m_Allocator; // esi
  unsigned int v5; // eax
  CWatchedDirectoryRoot *v6; // ebx
  char *v7; // eax
  COffsetPtr<char> *p_m_pLongName; // ecx
  char *v9; // eax
  COffsetPtr<char> *p_m_pShortName; // ecx
  const char **v11; // ebp
  unsigned int v12; // eax
  CIgnoreExtension *v13; // edi
  char *v14; // eax
  COffsetPtr<char> *p_m_pExtension; // ecx
  COverwatchHeader *m_pOverwatchHeader; // eax
  int m_nOffset; // ecx
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pFirstWatchedDirectoryRoot; // eax
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pNextDirectoryRoot; // edx
  int v20; // eax
  CWatchedDir *p_m_RootDir; // eax
  char *v22; // ecx
  char *i; // esi
  CWatchedDir *v24; // eax
  const char *v25; // [esp-4h] [ebp-18h]

  v3 = this;
  CFileChangeWatcher::AddDirectory(this: &this->m_FileChangeWatcher, pFullDirName: pDirName, bRecursive: true);
  p_m_Allocator = &v3->m_Allocator;
  v5 = 4 * ((v3->m_Allocator.m_nCurOffset + 3) >> 2);
  v6 = (CWatchedDirectoryRoot *)&v3->m_Allocator.m_pBase[v5];
  v3->m_Allocator.m_nCurOffset = v5 + 144;
  CWatchedDirectoryRoot::Init(this: v6);
  v7 = CLinearMemoryAllocator::CopyString(this: &v3->m_Allocator, pStr: pDirName->m_FullDirName);
  p_m_pLongName = &v6->m_pLongName;
  if ( v7 != nullptr )
    p_m_pLongName->m_nOffset = v7 - (char *)p_m_pLongName;
  else
    p_m_pLongName->m_nOffset = 0;
  if ( p_m_pLongName->m_nOffset != 0 )
    v9 = (char *)p_m_pLongName + p_m_pLongName->m_nOffset;
  else
    v9 = nullptr;
  p_m_pShortName = &v6->m_pShortName;
  if ( v9 != nullptr )
    p_m_pShortName->m_nOffset = v9 - (char *)p_m_pShortName;
  else
    p_m_pShortName->m_nOffset = 0;
  v11 = pIgnoreExtensions;
  v6->m_bFullyUpToDate = false;
  if ( *pIgnoreExtensions != nullptr )
  {
    do
    {
      v12 = 4 * ((p_m_Allocator->m_nCurOffset + 3) >> 2);
      v13 = (CIgnoreExtension *)&p_m_Allocator->m_pBase[v12];
      v25 = *v11;
      p_m_Allocator->m_nCurOffset = v12 + 8;
      v14 = CLinearMemoryAllocator::CopyString(this: p_m_Allocator, pStr: v25);
      p_m_pExtension = &v13->m_pExtension;
      if ( v14 != nullptr )
        p_m_pExtension->m_nOffset = v14 - (char *)p_m_pExtension;
      else
        p_m_pExtension->m_nOffset = 0;
      CWatchedDirectoryRoot::AddIgnoreExtension(this: v6, pIgnoreExt: v13);
      ++v11;
    }
    while ( *v11 != nullptr );
    v3 = this;
  }
  m_pOverwatchHeader = v3->m_pOverwatchHeader;
  m_nOffset = m_pOverwatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset;
  p_m_pFirstWatchedDirectoryRoot = &m_pOverwatchHeader->m_pFirstWatchedDirectoryRoot;
  p_m_pNextDirectoryRoot = &v6->m_pNextDirectoryRoot;
  if ( m_nOffset != 0 && (v20 = (int)p_m_pFirstWatchedDirectoryRoot + m_nOffset) != 0 )
    p_m_pNextDirectoryRoot->m_nOffset = v20 - (_DWORD)p_m_pNextDirectoryRoot;
  else
    p_m_pNextDirectoryRoot->m_nOffset = 0;
  v3->m_pOverwatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset = (char *)v6
                                                                 - (char *)&v3->m_pOverwatchHeader->m_pFirstWatchedDirectoryRoot;
  p_m_RootDir = &v3->m_pOverwatchHeader->m_RootDir;
  v22 = (char *)pDirName;
  for ( i = (char *)pDirName; *i != 0; ++i )
  {
    if ( *i == 47 || *i == 92 )
    {
      p_m_RootDir = COverwatchService::FindOrAddChildDir(
                      this: v3,
                      pLastDir: p_m_RootDir,
                      pDirName: pDirName->m_FullDirName,
                      pCurDirBase: v22,
                      pCur: i);
      v22 = i + 1;
    }
  }
  v24 = COverwatchService::FindOrAddChildDir(
          this: v3,
          pLastDir: p_m_RootDir,
          pDirName: pDirName->m_FullDirName,
          pCurDirBase: v22,
          pCur: i);
  v24->m_pWatchedDirectoryRoot.m_nOffset = (char *)v6 - (char *)&v24->m_pWatchedDirectoryRoot;
}

//------------------------------------------------------------------------------
// Address: 0x00403340
// Name: private: void COverwatchService::ReadConfigFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::ReadConfigFile(COverwatchService *this)
{
  int v1; // ebx
  int v3; // esi
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  CFileChangeWatcher::CDirWatch *v8; // eax
  int v9; // eax
  const char *ppIgnoreExtensions[10]; // [esp+Ch] [ebp-2Ch] BYREF
  int v11; // [esp+34h] [ebp-4h]

  v1 = 0;
  ppIgnoreExtensions[1] = "pch";
  ppIgnoreExtensions[2] = "pdb";
  ppIgnoreExtensions[3] = "o";
  ppIgnoreExtensions[4] = "obj";
  ppIgnoreExtensions[5] = "ncb";
  ppIgnoreExtensions[6] = "vcproj";
  ppIgnoreExtensions[7] = "icl";
  ppIgnoreExtensions[8] = "remotesnapshot";
  ppIgnoreExtensions[9] = "vtemp";
  v11 = 0;
  v3 = 1;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 36))(a1: v4) - 1 <= 1 )
    goto LABEL_6;
  do
  {
    v5 = _CommandLine();
    v6 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 44))(a1: v5, a2: v3);
    if ( _stricmp(dst: v6, src: "-watch") == 0 )
    {
      ++v3;
      v7 = _CommandLine();
      v8 = (CFileChangeWatcher::CDirWatch *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: v3);
      COverwatchService::StartWatchingDirectory(this, pDirName: v8, pIgnoreExtensions: &ppIgnoreExtensions[1]);
      ++v1;
    }
    ++v3;
    v9 = _CommandLine();
  }
  while ( v3 < (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 36))(a1: v9) - 1 );
  if ( v1 == 0 )
LABEL_6:
    _Error(a1: "No -watch <directory> parameter(s) specified.");
}

//------------------------------------------------------------------------------
// Address: 0x00403420
// Name: public: void COverwatchService::Run(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchService::Run(COverwatchService *this)
{
  CSharedMemoryMgr *p_m_SharedMemory; // edi
  COverwatchHeader *v3; // ecx
  COverwatchHeader *m_pOverwatchHeader; // eax

  CFileChangeWatcher::Term(this: &this->m_FileChangeWatcher);
  WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
  p_m_SharedMemory = &this->m_SharedMemory;
  if ( !CSharedMemoryMgr::Create(this: &this->m_SharedMemory, pSharedName: "overwatch_shared_data", nBytes: 0x2800000u) )
    _Error(a1: "Unable to create shared memory");
  *(_DWORD *)p_m_SharedMemory->m_pStart = 342526;
  v3 = (COverwatchHeader *)(p_m_SharedMemory->m_pStart + 4);
  this->m_pOverwatchHeader = v3;
  COverwatchHeader::Init(this: v3);
  this->m_pOverwatchHeader->m_dwOverwatchProcessID = GetCurrentProcessId();
  CLinearMemoryAllocator::Init(
    this: &this->m_Allocator,
    pBase: p_m_SharedMemory->m_pStart + 34156,
    nMaxBytes: this->m_SharedMemory.m_nBytes - 34156,
    bAutoFree: false);
  m_pOverwatchHeader = this->m_pOverwatchHeader;
  *(_QWORD *)&m_pOverwatchHeader->m_Stats.m_nFileEntriesCreated = 0;
  m_pOverwatchHeader->m_Stats.m_nMemoryBytesUsed = 0;
  m_pOverwatchHeader->m_Stats.m_nMemoryBytesLimit = 0;
  *(_QWORD *)&m_pOverwatchHeader->m_Stats.m_nFilesIterated = 0;
  COverwatchService::ReadConfigFile(this);
  ReleaseMutex(hMutex: this->m_hDataMutex);
  COverwatchService::Scan(this);
}

//------------------------------------------------------------------------------
// Address: 0x004034F0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  HANDLE CurrentProcess; // eax
  void (__thiscall ***v4)(_DWORD, int, const char **); // eax

  CurrentProcess = GetCurrentProcess();
  SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x40u);
  v4 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v4)(a1: v4, a2: argc, a3: argv);
  COverwatchService::Run(this: &g_OverwatchService);
  return 0;
}
