// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vwatch/vwatch_service/vwatch_service.cpp
// Functions: 22
// ============================================================

#include "utils\vwatch\vwatch_service\vwatch_service.h"

//------------------------------------------------------------------------------
// Address: 0x10002810
// Name: public: void __near * CLinearMemoryAllocator::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CLinearMemoryAllocator::Alloc(CLinearMemoryAllocator *this, unsigned int nBytes)
{
  unsigned int v3; // edx
  unsigned __int8 *m_pBase; // eax

  if ( this->m_bHasRunOutOfMemory )
    return nullptr;
  v3 = 4 * ((this->m_nCurOffset + 3) >> 2);
  this->m_nCurOffset = v3;
  if ( v3 + nBytes > this->m_nMaxBytes )
  {
    this->m_bHasRunOutOfMemory = true;
    return nullptr;
  }
  else
  {
    m_pBase = this->m_pBase;
    this->m_nCurOffset = v3 + nBytes;
    return &m_pBase[v3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002860
// Name: void WriteDataToSharedMemoryByName(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteDataToSharedMemoryByName(const char *pSharedMemoryName, unsigned __int8 *pData, unsigned int dataLen)
{
  CSharedMemoryMgr sharedMemoryMgr; // [esp+8h] [ebp-10h] BYREF

  CSharedMemoryMgr::CSharedMemoryMgr(this: &sharedMemoryMgr);
  if ( CSharedMemoryMgr::Open(this: &sharedMemoryMgr, pSharedName: pSharedMemoryName, nBytes: dataLen) )
    memcpy(dst: sharedMemoryMgr.m_pStart, src: pData, count: dataLen);
  else
    _Warning(a1: "Unable to write CAppSignal response to %s!\n", pSharedMemoryName);
  CSharedMemoryMgr::~CSharedMemoryMgr(this: &sharedMemoryMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100028D0
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
// Address: 0x100028F0
// Name: public: virtual void CVWatchService::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::Stop(CVWatchService *this)
{
  if ( this->m_bRunning.m_value != 0 )
  {
    _InterlockedExchange(&this->m_bExit.m_value, 1);
    while ( this->m_bRunning.m_value != 0 )
      _ThreadSleep(a1: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002940
// Name: private: void CVWatchService::WriteConfigFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::WriteConfigFile(CVWatchService *this)
{
  CVWatchService *v1; // edi
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  CVWatchHeader *m_pVWatchHeader; // eax
  int m_nOffset; // ecx
  int v6; // esi
  KeyValues *NewKey; // edi
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax

  v1 = this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "root");
  else
    v3 = nullptr;
  m_pVWatchHeader = v1->m_pVWatchHeader;
  m_nOffset = m_pVWatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset;
  if ( m_nOffset != 0 )
  {
    v6 = (int)&m_pVWatchHeader->m_pFirstWatchedDirectoryRoot + m_nOffset;
    if ( (CVWatchHeader *)((char *)m_pVWatchHeader + m_nOffset) != (CVWatchHeader *)-1384 )
    {
      do
      {
        if ( *(_BYTE *)(v6 + 28) != 0 )
        {
          NewKey = KeyValues::CreateNewKey(this: v3);
          v8 = *(_DWORD *)(v6 + 24);
          if ( v8 != 0 )
            v9 = (const char *)(v8 + v6 + 24);
          else
            v9 = nullptr;
          KeyValues::SetName(this: NewKey, setName: v9);
          KeyValues::SetInt(this: NewKey, keyName: "watch", value: 1);
          v1 = this;
        }
        v10 = *(_DWORD *)(v6 + 32);
        if ( v10 == 0 )
          break;
        v6 += v10 + 32;
      }
      while ( v6 != 0 );
    }
  }
  v11 = CUtlString::operator char const *(this: &v1->m_sConfigFilename);
  KeyValues::SaveToFile(this: v3, filesystem: v1->m_pFileSystem, resourceName: v11, pathID: nullptr);
  KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10002A00
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
// Address: 0x10002A30
// Name: private: class CWatchedDir __near * CVWatchService::AddChildDir(class CWatchedDir __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CVWatchService::AddChildDir(
        CVWatchService *this,
        CWatchedDir *pDir,
        const char *pShortName,
        const char *pLongName)
{
  unsigned int v5; // eax
  CWatchedDir *v6; // esi
  COffsetPtr<CWatchedDir> *p_m_pNextChildDir; // edx
  char *v8; // ecx
  int m_nOffset; // ecx
  char *v10; // eax
  COffsetPtr<char> *p_m_pShortName; // ecx
  char *v12; // eax
  COffsetPtr<char> *p_m_pLongName; // esi
  int v14; // edi
  CWatchedDir *pChild; // [esp+Ch] [ebp-4h]
  CWatchedDir *pDira; // [esp+18h] [ebp+8h]

  WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
  if ( !this->m_Allocator.m_bHasRunOutOfMemory )
  {
    v5 = 4 * ((this->m_Allocator.m_nCurOffset + 3) >> 2);
    this->m_Allocator.m_nCurOffset = v5;
    if ( v5 + 28 <= this->m_Allocator.m_nMaxBytes )
    {
      v6 = (CWatchedDir *)&this->m_Allocator.m_pBase[v5];
      this->m_Allocator.m_nCurOffset = v5 + 28;
      goto LABEL_6;
    }
    this->m_Allocator.m_bHasRunOutOfMemory = true;
  }
  v6 = nullptr;
LABEL_6:
  pChild = v6;
  if ( v6 != nullptr )
  {
    CWatchedDir::Init(this: v6);
    ++this->m_pVWatchHeader->m_Stats.m_nDirectoryEntriesCreated;
    p_m_pNextChildDir = &v6->m_pNextChildDir;
    if ( pDir->m_pFirstChildDir.m_nOffset != 0 && (v8 = (char *)pDir + pDir->m_pFirstChildDir.m_nOffset) != nullptr )
      p_m_pNextChildDir->m_nOffset = v8 - (char *)p_m_pNextChildDir;
    else
      p_m_pNextChildDir->m_nOffset = 0;
    pDir->m_pFirstChildDir.m_nOffset = (char *)v6 - (char *)pDir;
    m_nOffset = pDir->m_pWatchedDirectoryRoot.m_nOffset;
    if ( m_nOffset == 0 || (CWatchedDir *)((char *)pDir + m_nOffset) == (CWatchedDir *)-12 )
      v6->m_pWatchedDirectoryRoot.m_nOffset = 0;
    else
      v6->m_pWatchedDirectoryRoot.m_nOffset = (char *)pDir + m_nOffset - (char *)v6;
    v10 = CLinearMemoryAllocator::CopyString(this: &this->m_Allocator, pStr: pShortName);
    p_m_pShortName = &v6->m_pShortName;
    pDira = (CWatchedDir *)&v6->m_pShortName;
    if ( v10 != nullptr )
      p_m_pShortName->m_nOffset = v10 - (char *)p_m_pShortName;
    else
      p_m_pShortName->m_nOffset = 0;
    v12 = CLinearMemoryAllocator::CopyString(this: &this->m_Allocator, pStr: pLongName);
    p_m_pLongName = &v6->m_pLongName;
    if ( v12 != nullptr )
      p_m_pLongName->m_nOffset = v12 - (char *)p_m_pLongName;
    else
      p_m_pLongName->m_nOffset = 0;
    if ( pDira->m_pFirstChildDir.m_nOffset != 0
      && (CWatchedDir *)((char *)pDira + pDira->m_pFirstChildDir.m_nOffset) != nullptr
      && p_m_pLongName->m_nOffset != 0
      && (COffsetPtr<char> *)((char *)p_m_pLongName + p_m_pLongName->m_nOffset) != nullptr )
    {
      v14 = _V_strlen(str: pShortName);
      this->m_pVWatchHeader->m_Stats.m_nWatchedDirBytes += (unsigned int)(v14 + _V_strlen(str: pLongName) + 30);
      this->m_pVWatchHeader->m_Stats.m_nWatchedDirLongNameBytes += _V_strlen(str: pLongName) + 1;
    }
    else
    {
      pChild = nullptr;
    }
  }
  ReleaseMutex(hMutex: this->m_hDataMutex);
  return pChild;
}

//------------------------------------------------------------------------------
// Address: 0x10002BC0
// Name: public: CVWatchService::CVWatchService(void)
// Source: json
//------------------------------------------------------------------------------
CVWatchService *__thiscall CVWatchService::CVWatchService(CVWatchService *this)
{
  this->__vftable = (CVWatchService_vtbl *)&CVWatchService::`vftable';
  CSharedMemoryMgr::CSharedMemoryMgr(this: &this->m_SharedMemory);
  CLinearMemoryAllocator::CLinearMemoryAllocator(this: &this->m_Allocator);
  CUtlString::CUtlString(this: &this->m_sConfigFilename);
  CFileChangeWatcher::CFileChangeWatcher(this: &this->m_FileChangeWatcher);
  this->m_bExit.m_value = 0;
  this->m_bRunning.m_value = 0;
  this->m_hDataMutex = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: "Global\\vwatch_mutex");
  this->m_nQueuedFileStats = 0;
  _InterlockedExchange(&this->m_bExit.m_value, 0);
  this->m_nCheckSignalsCounter = 0;
  this->m_nFilesScanned = 0;
  _InterlockedExchange(&this->m_bRunning.m_value, 0);
  this->m_pFileSystem = nullptr;
  this->m_bShouldRestart = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002C70
// Name: public: CVWatchService::~CVWatchService(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::~CVWatchService(CVWatchService *this)
{
  bool v2; // sf
  void *m_hDataMutex; // [esp-4h] [ebp-8h]

  m_hDataMutex = this->m_hDataMutex;
  this->__vftable = (CVWatchService_vtbl *)&CVWatchService::`vftable';
  CloseHandle(hObject: m_hDataMutex);
  CFileChangeWatcher::~CFileChangeWatcher(this: &this->m_FileChangeWatcher);
  v2 = this->m_sConfigFilename.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_sConfigFilename.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_sConfigFilename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sConfigFilename.m_Storage.m_Memory.m_pMemory);
      this->m_sConfigFilename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sConfigFilename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CLinearMemoryAllocator::~CLinearMemoryAllocator(this: &this->m_Allocator);
  CSharedMemoryMgr::~CSharedMemoryMgr(this: &this->m_SharedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10002CF0
// Name: private: class CWatchedDir __near * CVWatchService::FindOrAddChildDir(class CWatchedDir __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CVWatchService::FindOrAddChildDir(
        CVWatchService *this,
        CWatchedDir *pLastDir,
        char *pDirName,
        char *pCurDirBase,
        char *pCur)
{
  CWatchedDir *result; // eax
  unsigned int v6; // esi
  unsigned int v7; // esi
  CVWatchService *v8; // ecx
  int m_nOffset; // ecx
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pWatchedDirectoryRoot; // edx
  char *v11; // ecx
  char szLongName[260]; // [esp+4h] [ebp-20Ch] BYREF
  char szShortName[260]; // [esp+108h] [ebp-108h] BYREF
  CVWatchService *v14; // [esp+20Ch] [ebp-4h]

  v14 = this;
  if ( pCur == pCurDirBase )
    return pLastDir;
  v6 = pCur - pCurDirBase;
  if ( pCur - pCurDirBase >= 259 )
    v6 = 259;
  memcpy(dst: (unsigned __int8 *)szShortName, src: (unsigned __int8 *)pCurDirBase, count: v6);
  szShortName[v6] = 0;
  result = CWatchedDir::FindChildDir(this: pLastDir, pLongDirName: szShortName);
  if ( result == nullptr )
  {
    v7 = pCur - pDirName;
    if ( pCur - pDirName >= 259 )
      v7 = 259;
    memcpy(dst: (unsigned __int8 *)szLongName, src: (unsigned __int8 *)pDirName, count: v7);
    v8 = v14;
    szLongName[v7] = 0;
    result = CVWatchService::AddChildDir(this: v8, pDir: pLastDir, pShortName: szShortName, pLongName: szLongName);
    if ( result != nullptr )
    {
      m_nOffset = pLastDir->m_pWatchedDirectoryRoot.m_nOffset;
      p_m_pWatchedDirectoryRoot = &result->m_pWatchedDirectoryRoot;
      if ( m_nOffset != 0 && (v11 = (char *)&pLastDir->m_pWatchedDirectoryRoot + m_nOffset) != nullptr )
        p_m_pWatchedDirectoryRoot->m_nOffset = v11 - (char *)p_m_pWatchedDirectoryRoot;
      else
        p_m_pWatchedDirectoryRoot->m_nOffset = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002DE0
// Name: private: class CWatchedDir __near * CVWatchService::CreateWatchedDir(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CWatchedDir *__thiscall CVWatchService::CreateWatchedDir(
        CVWatchService *this,
        char *pLongFilename,
        bool bIncludeLastSection)
{
  char *v3; // edx
  CWatchedDir *p_m_RootDir; // edi
  bool v5; // zf
  unsigned __int8 *v6; // eax
  char *v7; // ebx
  unsigned int v8; // esi
  CWatchedDir *ChildDir; // eax
  unsigned int v10; // esi
  CVWatchService *v11; // ecx
  int m_nOffset; // ecx
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pWatchedDirectoryRoot; // edx
  int v14; // ecx
  char pLongName[260]; // [esp+Ch] [ebp-210h] BYREF
  char dst[260]; // [esp+110h] [ebp-10Ch] BYREF
  CVWatchService *v18; // [esp+214h] [ebp-8h]
  unsigned int count; // [esp+218h] [ebp-4h]

  v3 = pLongFilename;
  p_m_RootDir = &this->m_pVWatchHeader->m_RootDir;
  v5 = *pLongFilename == 0;
  v18 = this;
  v6 = (unsigned __int8 *)pLongFilename;
  v7 = pLongFilename;
  if ( !v5 )
  {
    count = 0;
    while ( 1 )
    {
      if ( *v7 == 47 || *v7 == 92 )
      {
        if ( v7 != (char *)v6 )
        {
          v8 = v7 - (char *)v6;
          if ( v7 - (char *)v6 >= 259 )
            v8 = 259;
          memcpy((unsigned __int8 *)dst, src: v6, count: v8);
          dst[v8] = 0;
          ChildDir = CWatchedDir::FindChildDir(this: p_m_RootDir, pLongDirName: dst);
          if ( ChildDir == nullptr )
          {
            v10 = count;
            if ( (int)count >= 259 )
              v10 = 259;
            memcpy(dst: (unsigned __int8 *)pLongName, src: (unsigned __int8 *)pLongFilename, count: v10);
            v11 = v18;
            pLongName[v10] = 0;
            ChildDir = CVWatchService::AddChildDir(this: v11, pDir: p_m_RootDir, pShortName: dst, pLongName);
            if ( ChildDir == nullptr )
              return nullptr;
            m_nOffset = p_m_RootDir->m_pWatchedDirectoryRoot.m_nOffset;
            p_m_pWatchedDirectoryRoot = &ChildDir->m_pWatchedDirectoryRoot;
            if ( m_nOffset != 0 && (v14 = (int)&p_m_RootDir->m_pWatchedDirectoryRoot + m_nOffset) != 0 )
              p_m_pWatchedDirectoryRoot->m_nOffset = v14 - (_DWORD)p_m_pWatchedDirectoryRoot;
            else
              p_m_pWatchedDirectoryRoot->m_nOffset = 0;
          }
          v3 = pLongFilename;
          p_m_RootDir = ChildDir;
        }
        if ( p_m_RootDir == nullptr )
          return nullptr;
        v6 = (unsigned __int8 *)&v3[count + 1];
      }
      ++count;
      if ( *++v7 == 0 )
      {
        this = v18;
        break;
      }
    }
  }
  if ( bIncludeLastSection )
    return CVWatchService::FindOrAddChildDir(
             this,
             pLastDir: p_m_RootDir,
             pDirName: v3,
             pCurDirBase: (char *)v6,
             pCur: v7);
  else
    return p_m_RootDir;
}

//------------------------------------------------------------------------------
// Address: 0x10002F20
// Name: private: void CVWatchService::SetFileStats(char const __near *,unsigned __int64,struct _FILETIME __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::SetFileStats(
        CVWatchService *this,
        char *pLongFilename,
        unsigned __int64 nFileSize,
        _FILETIME *pModifiedTime)
{
  char *v4; // ebx
  CWatchedFile *v6; // esi
  int v7; // edx
  _FILETIME *v8; // eax
  CWatchedDir *WatchedDir; // eax
  int m_nOffset; // ecx
  CWatchedDirectoryRoot *v11; // eax
  int v12; // ebx
  unsigned __int8 *v13; // esi
  CVWatchHeader *m_pVWatchHeader; // eax
  bool v15; // cf
  COffsetPtr<CWatchedFile> *p_m_pFirstFile; // ebx
  int v17; // edx
  _FILETIME *v18; // eax
  unsigned int v19; // ebx
  const char *pExtension; // [esp+Ch] [ebp-10h] BYREF
  int nLongDirNameChars; // [esp+10h] [ebp-Ch] BYREF
  int nShortFilenameChars; // [esp+14h] [ebp-8h] BYREF
  CWatchedDir *pDir; // [esp+18h] [ebp-4h]

  v4 = pLongFilename;
  CVWatchHeader::GetFilenameComponents(
    this: this->m_pVWatchHeader,
    pFullFilename: pLongFilename,
    pShortFilename: (const char **)&pLongFilename,
    pnShortFilenameChars: &nShortFilenameChars,
    pnLongDirNameChars: &nLongDirNameChars,
    &pExtension);
  v6 = CVWatchHeader::LookupFile(
         this: this->m_pVWatchHeader,
         pShortFilename: pLongFilename,
         nShortFilenameChars,
         pLongDirName: v4,
         nLongDirNameChars);
  if ( v6 != nullptr )
  {
    WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
    v7 = nFileSize;
    HIDWORD(v6->m_nFileSize) = HIDWORD(nFileSize);
    v8 = pModifiedTime;
    v6->m_bCRCValid = false;
    LODWORD(v6->m_nFileSize) = v7;
    if ( v8 != nullptr )
    {
      v6->m_ModifiedTime.dwLowDateTime = v8->dwLowDateTime;
      v6->m_ModifiedTime.dwHighDateTime = v8->dwHighDateTime;
    }
    goto LABEL_11;
  }
  if ( (HIDWORD(nFileSize) & (unsigned int)nFileSize) != 0xFFFFFFFF )
  {
    WatchedDir = CVWatchService::CreateWatchedDir(this, pLongFilename: v4, bIncludeLastSection: false);
    pDir = WatchedDir;
    if ( WatchedDir != nullptr )
    {
      m_nOffset = WatchedDir->m_pWatchedDirectoryRoot.m_nOffset;
      if ( m_nOffset != 0 )
      {
        v11 = (CWatchedDirectoryRoot *)((char *)&WatchedDir->m_pWatchedDirectoryRoot + m_nOffset);
        if ( v11 != nullptr && !CWatchedDirectoryRoot::ShouldIgnoreExtension(this: v11, pExt: pExtension) )
        {
          v12 = _V_strlen(str: pLongFilename);
          v13 = CLinearMemoryAllocator::Alloc(this: &this->m_Allocator, nBytes: v12 + 40);
          if ( v13 != nullptr )
          {
            m_pVWatchHeader = this->m_pVWatchHeader;
            v15 = __CFADD__(v12 + 40, m_pVWatchHeader->m_Stats.m_nWatchedFileBytes);
            LODWORD(m_pVWatchHeader->m_Stats.m_nWatchedFileBytes) += v12 + 40;
            HIDWORD(m_pVWatchHeader->m_Stats.m_nWatchedFileBytes) += v15;
            ++this->m_pVWatchHeader->m_Stats.m_nFileEntriesCreated;
            V_strncpy(pDest: (char *)v13 + 36, pSrc: pLongFilename, maxLen: v12 + 1);
            WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
            p_m_pFirstFile = &pDir->m_pFirstFile;
            COffsetPtr<CWatchedFile>::operator=(this: (COffsetPtr<CWatchedFile> *)v13 + 5, p: &pDir->m_pFirstFile);
            COffsetPtr<CWatchedDir>::operator=(this: p_m_pFirstFile, p: (CWatchedFile *)v13);
            COffsetPtr<CWatchedDir>::operator=(this: (COffsetPtr<CWatchedFile> *)v13 + 6, p: (CWatchedFile *)pDir);
            v17 = nFileSize;
            *((_DWORD *)v13 + 1) = HIDWORD(nFileSize);
            v18 = pModifiedTime;
            *(_DWORD *)v13 = v17;
            *((_FILETIME *)v13 + 1) = *v18;
            v13[28] = 0;
            v19 = 4
                * CVWatchHeader::HashFilename(
                    this: this->m_pVWatchHeader,
                    pFilename: pLongFilename,
                    nChars: nShortFilenameChars)
                + 1548;
            COffsetPtr<CWatchedFile>::operator=(
              this: (COffsetPtr<CWatchedFile> *)v13 + 4,
              p: (COffsetPtr<CWatchedFile> *)((char *)this->m_pVWatchHeader + v19));
            COffsetPtr<CWatchedDir>::operator=(
              this: (COffsetPtr<CWatchedFile> *)((char *)this->m_pVWatchHeader + v19),
              p: (CWatchedFile *)v13);
LABEL_11:
            ReleaseMutex(hMutex: this->m_hDataMutex);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030E0
// Name: private: void CVWatchService::CommitQueuedFileStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::CommitQueuedFileStats(CVWatchService *this)
{
  int m_nQueuedFileStats; // eax
  char *m_Filename; // esi
  CWatchedFile *v4; // ebx
  CWatchedDir *WatchedDir; // eax
  COffsetPtr<CWatchedFile> *v6; // ebx
  int m_nOffset; // eax
  unsigned __int8 *v8; // esi
  CVWatchHeader *m_pVWatchHeader; // eax
  bool v10; // cf
  int v11; // ecx
  char *v12; // eax
  unsigned int v13; // ebx
  int v14; // [esp+4h] [ebp-24h]
  char *pExtension; // [esp+Ch] [ebp-1Ch] BYREF
  int pnLongDirNameChars; // [esp+10h] [ebp-18h] BYREF
  int i; // [esp+14h] [ebp-14h]
  int pnShortFilenameChars; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-Ch]
  char *v20; // [esp+20h] [ebp-8h]
  char *pShortFilename; // [esp+24h] [ebp-4h] BYREF

  m_nQueuedFileStats = this->m_nQueuedFileStats;
  if ( m_nQueuedFileStats != 0 )
  {
    i = 0;
    if ( m_nQueuedFileStats > 0 )
    {
      m_Filename = this->m_QueuedFileStats[0].m_Filename;
      v20 = this->m_QueuedFileStats[0].m_Filename;
      do
      {
        v14 = *((_DWORD *)m_Filename - 1);
        CVWatchHeader::GetFilenameComponents(
          this: this->m_pVWatchHeader,
          pFullFilename: m_Filename,
          (const char **)&pShortFilename,
          &pnShortFilenameChars,
          &pnLongDirNameChars,
          (const char **)&pExtension);
        v4 = CVWatchHeader::LookupFile(
               this: this->m_pVWatchHeader,
               pShortFilename,
               nShortFilenameChars: pnShortFilenameChars,
               pLongDirName: m_Filename,
               nLongDirNameChars: pnLongDirNameChars);
        if ( v4 != nullptr )
        {
          WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
          LODWORD(v4->m_nFileSize) = v14;
          v4->m_bCRCValid = false;
          HIDWORD(v4->m_nFileSize) = 0;
          v4->m_ModifiedTime.dwLowDateTime = *((_DWORD *)m_Filename - 3);
          v4->m_ModifiedTime.dwHighDateTime = *((_DWORD *)m_Filename - 2);
          ReleaseMutex(hMutex: this->m_hDataMutex);
        }
        else
        {
          WatchedDir = CVWatchService::CreateWatchedDir(this, pLongFilename: m_Filename, bIncludeLastSection: false);
          v6 = (COffsetPtr<CWatchedFile> *)WatchedDir;
          if ( WatchedDir != nullptr )
          {
            m_nOffset = WatchedDir->m_pWatchedDirectoryRoot.m_nOffset;
            if ( m_nOffset != 0
              && (COffsetPtr<CWatchedFile> *)((char *)v6 + m_nOffset) != (COffsetPtr<CWatchedFile> *)-12
              && !CWatchedDirectoryRoot::ShouldIgnoreExtension(
                    this: (CWatchedDirectoryRoot *)((char *)&v6[3] + m_nOffset),
                    pExt: pExtension) )
            {
              v19 = _V_strlen(str: pShortFilename);
              v8 = CLinearMemoryAllocator::Alloc(this: &this->m_Allocator, nBytes: v19 + 40);
              if ( v8 != nullptr )
              {
                m_pVWatchHeader = this->m_pVWatchHeader;
                v10 = __CFADD__(v19 + 40, m_pVWatchHeader->m_Stats.m_nWatchedFileBytes);
                LODWORD(m_pVWatchHeader->m_Stats.m_nWatchedFileBytes) += v19 + 40;
                v11 = v19;
                HIDWORD(m_pVWatchHeader->m_Stats.m_nWatchedFileBytes) += v10;
                ++this->m_pVWatchHeader->m_Stats.m_nFileEntriesCreated;
                V_strncpy(pDest: (char *)v8 + 36, pSrc: pShortFilename, maxLen: v11 + 1);
                WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
                COffsetPtr<CWatchedFile>::operator=(this: (COffsetPtr<CWatchedFile> *)v8 + 5, p: v6 + 2);
                v6[2].m_nOffset = v8 - (unsigned __int8 *)&v6[2];
                *((_DWORD *)v8 + 6) = (char *)v6 - (char *)(v8 + 24);
                *(_DWORD *)v8 = v14;
                *((_DWORD *)v8 + 1) = 0;
                v12 = v20;
                *((_DWORD *)v8 + 2) = *((_DWORD *)v20 - 3);
                *((_DWORD *)v8 + 3) = *((_DWORD *)v12 - 2);
                v8[28] = 0;
                v13 = 4
                    * CVWatchHeader::HashFilename(
                        this: this->m_pVWatchHeader,
                        pFilename: pShortFilename,
                        nChars: pnShortFilenameChars)
                    + 1548;
                COffsetPtr<CWatchedFile>::operator=(
                  this: (COffsetPtr<CWatchedFile> *)v8 + 4,
                  p: (COffsetPtr<CWatchedFile> *)((char *)this->m_pVWatchHeader + v13));
                *(unsigned int *)((char *)&this->m_pVWatchHeader->m_Stats.m_nFileEntriesCreated + v13) = v8 - ((unsigned __int8 *)this->m_pVWatchHeader + v13);
                ReleaseMutex(hMutex: this->m_hDataMutex);
              }
              m_Filename = v20;
            }
          }
        }
        m_Filename += 272;
        ++i;
        v20 = m_Filename;
      }
      while ( i < this->m_nQueuedFileStats );
    }
    this->m_nQueuedFileStats = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100032F0
// Name: private: void CVWatchService::StartWatchingDirectory(char const __near *,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::StartWatchingDirectory(
        CVWatchService *this,
        const char **pDirName,
        const char **pIgnoreExtensions)
{
  CVWatchService *v3; // edi
  CLinearMemoryAllocator *p_m_Allocator; // esi
  unsigned int v5; // eax
  unsigned __int8 *v6; // ebx
  char *v7; // eax
  char *v8; // ecx
  char *v9; // eax
  char *v10; // ecx
  const char *v11; // edx
  unsigned int v12; // eax
  CIgnoreExtension *v13; // ecx
  CIgnoreExtension *v14; // edi
  char *v15; // eax
  COffsetPtr<char> *p_m_pExtension; // ecx
  bool v17; // zf
  CVWatchHeader *m_pVWatchHeader; // eax
  int m_nOffset; // ecx
  COffsetPtr<CWatchedDirectoryRoot> *p_m_pFirstWatchedDirectoryRoot; // eax
  _DWORD *v21; // edx
  int v22; // eax
  CWatchedDir *WatchedDir; // eax
  char szDirName[260]; // [esp+8h] [ebp-108h] BYREF
  CVWatchService *v25; // [esp+10Ch] [ebp-4h]
  const char **pCur; // [esp+118h] [ebp+8h]

  v3 = this;
  v25 = this;
  V_strncpy(pDest: szDirName, pSrc: (const char *)pDirName, maxLen: 260);
  V_FixSlashes(pname: szDirName, separator: 92);
  CFileChangeWatcher::AddDirectory(this: &v3->m_FileChangeWatcher, pFullDirName: szDirName, bRecursive: true);
  p_m_Allocator = &v3->m_Allocator;
  if ( !v3->m_Allocator.m_bHasRunOutOfMemory )
  {
    v5 = 4 * ((v3->m_Allocator.m_nCurOffset + 3) >> 2);
    v3->m_Allocator.m_nCurOffset = v5;
    if ( v5 + 144 > v3->m_Allocator.m_nMaxBytes )
    {
      v3->m_Allocator.m_bHasRunOutOfMemory = true;
      return;
    }
    v6 = &p_m_Allocator->m_pBase[v5];
    v3->m_Allocator.m_nCurOffset = v5 + 144;
    if ( v6 != nullptr )
    {
      CWatchedDirectoryRoot::Init(this: (CWatchedDirectoryRoot *)v6);
      v7 = CLinearMemoryAllocator::CopyString(this: &v3->m_Allocator, pStr: szDirName);
      v8 = (char *)(v6 + 24);
      *(_DWORD *)v8 = v7 != nullptr ? v7 - v8 : 0;
      if ( *(_DWORD *)v8 != 0 && &v8[*(_DWORD *)v8] != nullptr )
      {
        if ( *(_DWORD *)v8 != 0 )
          v9 = &v8[*(_DWORD *)v8];
        else
          v9 = nullptr;
        v10 = (char *)(v6 + 20);
        if ( v9 != nullptr )
          *(_DWORD *)v10 = v9 - v10;
        else
          *(_DWORD *)v10 = 0;
        *((_WORD *)v6 + 14) = 1;
        *((_DWORD *)v6 + 3) = -12;
        if ( pIgnoreExtensions == nullptr )
          goto LABEL_30;
        pCur = pIgnoreExtensions;
        if ( *pIgnoreExtensions == nullptr )
          goto LABEL_30;
        while ( 1 )
        {
          v11 = *pCur;
          if ( p_m_Allocator->m_bHasRunOutOfMemory )
            goto LABEL_22;
          v12 = 4 * ((p_m_Allocator->m_nCurOffset + 3) >> 2);
          p_m_Allocator->m_nCurOffset = v12;
          if ( v12 + 8 > p_m_Allocator->m_nMaxBytes )
            break;
          v13 = (CIgnoreExtension *)&p_m_Allocator->m_pBase[v12];
          p_m_Allocator->m_nCurOffset = v12 + 8;
          v14 = v13;
LABEL_23:
          v15 = CLinearMemoryAllocator::CopyString(this: p_m_Allocator, pStr: v11);
          p_m_pExtension = &v14->m_pExtension;
          if ( v15 != nullptr )
            p_m_pExtension->m_nOffset = v15 - (char *)p_m_pExtension;
          else
            p_m_pExtension->m_nOffset = 0;
          if ( p_m_pExtension->m_nOffset == 0
            || (COffsetPtr<char> *)((char *)p_m_pExtension + p_m_pExtension->m_nOffset) == nullptr )
          {
            return;
          }
          CWatchedDirectoryRoot::AddIgnoreExtension(this: (CWatchedDirectoryRoot *)v6, pIgnoreExt: v14);
          v17 = pCur[1] == nullptr;
          ++pCur;
          if ( v17 )
          {
            v3 = v25;
LABEL_30:
            m_pVWatchHeader = v3->m_pVWatchHeader;
            m_nOffset = m_pVWatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset;
            p_m_pFirstWatchedDirectoryRoot = &m_pVWatchHeader->m_pFirstWatchedDirectoryRoot;
            v21 = v6 + 32;
            if ( m_nOffset != 0 && (v22 = (int)p_m_pFirstWatchedDirectoryRoot + m_nOffset) != 0 )
              *v21 = v22 - (_DWORD)v21;
            else
              *v21 = 0;
            v3->m_pVWatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset = v6
                                                                        - (unsigned __int8 *)&v3->m_pVWatchHeader->m_pFirstWatchedDirectoryRoot;
            WatchedDir = CVWatchService::CreateWatchedDir(this: v3, pLongFilename: szDirName, bIncludeLastSection: true);
            if ( WatchedDir != nullptr )
              WatchedDir->m_pWatchedDirectoryRoot.m_nOffset = v6
                                                            - (unsigned __int8 *)&WatchedDir->m_pWatchedDirectoryRoot;
            return;
          }
        }
        p_m_Allocator->m_bHasRunOutOfMemory = true;
LABEL_22:
        v14 = nullptr;
        goto LABEL_23;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100034D0
// Name: private: void CVWatchService::ReadConfigFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::ReadConfigFile(CVWatchService *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  const char *v4; // eax
  CUtlString *v5; // eax
  const char *v6; // eax
  KeyValues *i; // esi
  const char **Name; // eax
  const char *ppIgnoreExtensions[10]; // [esp+Ch] [ebp-48h] BYREF
  CUtlString v10; // [esp+34h] [ebp-20h] BYREF
  CUtlString sFilename; // [esp+44h] [ebp-10h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "root");
  else
    v3 = nullptr;
  v4 = CUtlString::operator char const *(this: &this->m_sConfigFilename);
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: this->m_pFileSystem,
         resourceName: v4,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    ppIgnoreExtensions[0] = "pch";
    ppIgnoreExtensions[1] = "pdb";
    ppIgnoreExtensions[2] = "o";
    ppIgnoreExtensions[3] = "obj";
    ppIgnoreExtensions[4] = "ncb";
    ppIgnoreExtensions[5] = "vcproj";
    ppIgnoreExtensions[6] = "icl";
    ppIgnoreExtensions[7] = "remotesnapshot";
    ppIgnoreExtensions[8] = "vtemp";
    ppIgnoreExtensions[9] = nullptr;
    for ( i = KeyValues::GetFirstTrueSubKey(this: v3); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      Name = (const char **)KeyValues::GetName(this: i);
      CVWatchService::StartWatchingDirectory(this, pDirName: Name, pIgnoreExtensions: ppIgnoreExtensions);
    }
    KeyValues::deleteThis(this: v3);
  }
  else
  {
    v5 = CUtlString::CUtlString(this: &v10, pString: g_pVWatchConfigFilename);
    CUtlString::AbsPath(this: v5, result: &sFilename, pStartingDir: nullptr);
    v10.m_Storage.m_nActualLength = 0;
    if ( v10.m_Storage.m_Memory.m_nGrowSize >= 0 && v10.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10.m_Storage.m_Memory.m_pMemory);
    v6 = CUtlString::operator char const *(this: &sFilename);
    _Warning(a1: "Invalid or missing config file in %s for vwatch service.\n", v6);
    sFilename.m_Storage.m_nActualLength = 0;
    if ( sFilename.m_Storage.m_Memory.m_nGrowSize >= 0 && sFilename.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sFilename.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003620
// Name: private: void CVWatchService::HandleAppSignal(class CAppSignal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::HandleAppSignal(CVWatchService *this, unsigned int pSignal)
{
  CAppSignal *v2; // ebx
  AppSignalType_t v3; // eax
  CVWatchHeader *v5; // ecx
  CWatchedDirectoryRoot *v6; // eax
  CVWatchHeader *m_pVWatchHeader; // ecx
  CWatchedDirectoryRoot *WatchedDirectoryRootForDirectory; // eax
  const char *m_ResponseEventName; // ebx
  HANDLE v10; // eax
  void *v11; // esi
  char *v12; // [esp-8h] [ebp-14h]
  unsigned int bStatus; // [esp+8h] [ebp-4h] BYREF

  v2 = (CAppSignal *)pSignal;
  v3 = *(_DWORD *)pSignal;
  if ( *(_DWORD *)pSignal != 0 )
  {
    switch ( v3 )
    {
      case APPSIGNAL_REMOVE_DIRECTORY:
        m_pVWatchHeader = this->m_pVWatchHeader;
        bStatus = 1;
        WatchedDirectoryRootForDirectory = CVWatchHeader::GetWatchedDirectoryRootForDirectory(
                                             this: m_pVWatchHeader,
                                             pDirectoryName: (const char *)(pSignal + 4));
        if ( WatchedDirectoryRootForDirectory != nullptr )
        {
          WatchedDirectoryRootForDirectory->m_bIsWatching = false;
          CVWatchService::WriteConfigFile(this);
        }
        else
        {
          bStatus = 0;
        }
        WriteDataToSharedMemoryByName(
          pSharedMemoryName: v2->m_ResponseDataName,
          pData: (unsigned __int8 *)&bStatus,
          dataLen: 4u);
        break;
      case APPSIGNAL_GET_NUM_FILES_SCANNED:
        WriteDataToSharedMemoryByName(
          pSharedMemoryName: (const char *)(pSignal + 264),
          pData: (unsigned __int8 *)&this->m_nFilesScanned,
          dataLen: 4u);
        break;
      case APPSIGNAL_RESTART:
        this->m_bShouldRestart = true;
        break;
      case APPSIGNAL_EXIT:
        _InterlockedExchange(&this->m_bExit.m_value, 1);
        break;
      default:
        break;
    }
  }
  else
  {
    v5 = this->m_pVWatchHeader;
    v12 = (char *)(pSignal + 4);
    pSignal = 1;
    v6 = CVWatchHeader::GetWatchedDirectoryRootForDirectory(this: v5, pDirectoryName: v12);
    if ( v6 != nullptr )
    {
      if ( v6->m_bIsWatching )
        pSignal = 2;
      else
        v6->m_bIsWatching = true;
    }
    else
    {
      CVWatchService::StartWatchingDirectory(
        this,
        pDirName: (const char **)v2->m_SignalData,
        pIgnoreExtensions: nullptr);
      CVWatchService::WriteConfigFile(this);
    }
    WriteDataToSharedMemoryByName(
      pSharedMemoryName: v2->m_ResponseDataName,
      pData: (unsigned __int8 *)&pSignal,
      dataLen: 4u);
  }
  m_ResponseEventName = v2->m_ResponseEventName;
  v10 = OpenEventA(dwDesiredAccess: 2u, bInheritHandle: false, lpName: m_ResponseEventName);
  v11 = v10;
  if ( v10 != nullptr )
  {
    SetEvent(hEvent: v10);
    CloseHandle(hObject: v11);
  }
  else
  {
    _Warning(a1: "Unable to set CAppSignal event response for %s!\n", m_ResponseEventName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003760
// Name: private: int CVWatchService::CheckSignals(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVWatchService::CheckSignals(CVWatchService *this)
{
  CVWatchHeader *m_pVWatchHeader; // eax
  int v3; // edi
  CVWatchHeader *v4; // eax
  CFileChangeWatcher::CFileChange *v5; // ebx
  HANDLE FirstFileA; // edi
  CWatchedFile *v7; // edi
  CVWatchHeader *v8; // eax
  int v9; // ebx
  _WIN32_FIND_DATAA findData; // [esp+Ch] [ebp-258h] BYREF
  char szFilename[260]; // [esp+14Ch] [ebp-118h] BYREF
  char *pExtension; // [esp+250h] [ebp-14h] BYREF
  int pnLongDirNameChars; // [esp+254h] [ebp-10h] BYREF
  int pnShortFilenameChars; // [esp+258h] [ebp-Ch] BYREF
  char *pShortFilename; // [esp+25Ch] [ebp-8h] BYREF
  int nThingsHandled; // [esp+260h] [ebp-4h]

  m_pVWatchHeader = this->m_pVWatchHeader;
  LODWORD(m_pVWatchHeader->m_Stats.m_nMemoryBytesUsed) = this->m_Allocator.m_nCurOffset;
  v3 = 0;
  HIDWORD(m_pVWatchHeader->m_Stats.m_nMemoryBytesUsed) = 0;
  v4 = this->m_pVWatchHeader;
  LODWORD(v4->m_Stats.m_nMemoryBytesLimit) = this->m_Allocator.m_nMaxBytes;
  HIDWORD(v4->m_Stats.m_nMemoryBytesLimit) = 0;
  this->m_pVWatchHeader->m_Stats.m_bHasRunOutOfMemory = this->m_Allocator.m_bHasRunOutOfMemory;
  nThingsHandled = 0;
  v5 = CFileChangeWatcher::Update(this: &this->m_FileChangeWatcher);
  if ( v5 != nullptr )
  {
    do
    {
      ++nThingsHandled;
      CFileChangeWatcher::CFileChange::GetFullFilename(this: v5, pOut: szFilename, nMaxBytes: 260);
      if ( (this->m_pVWatchHeader->m_nFlags & 1) != 0 )
        _Msg(a1: "Noted a change to %s\n", szFilename);
      ++this->m_pVWatchHeader->m_Stats.m_nFilesIterated;
      FirstFileA = FindFirstFileA(lpFileName: szFilename, lpFindFileData: &findData);
      if ( FirstFileA == (HANDLE)-1 )
      {
        CVWatchHeader::GetFilenameComponents(
          this: this->m_pVWatchHeader,
          pFullFilename: szFilename,
          (const char **)&pShortFilename,
          &pnShortFilenameChars,
          &pnLongDirNameChars,
          (const char **)&pExtension);
        v7 = CVWatchHeader::LookupFile(
               this: this->m_pVWatchHeader,
               pShortFilename,
               nShortFilenameChars: pnShortFilenameChars,
               pLongDirName: szFilename,
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
        if ( (findData.dwFileAttributes & 0x10) == 0 )
          CVWatchService::SetFileStats(
            this,
            pLongFilename: szFilename,
            nFileSize: findData.nFileSizeLow,
            pModifiedTime: &findData.ftLastWriteTime);
        FindClose(hFindFile: FirstFileA);
      }
      v5 = v5->m_pNext;
    }
    while ( v5 != nullptr );
    v3 = 0;
  }
  WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
  v8 = this->m_pVWatchHeader;
  if ( v8->m_nAppSignals > 0 )
  {
    v9 = 0;
    do
    {
      ++nThingsHandled;
      CVWatchService::HandleAppSignal(this, pSignal: (unsigned int)&v8->m_AppSignals[v9]);
      if ( this->m_bExit.m_value != 0 )
        break;
      v8 = this->m_pVWatchHeader;
      ++v3;
      ++v9;
    }
    while ( v3 < v8->m_nAppSignals );
  }
  this->m_pVWatchHeader->m_nAppSignals = 0;
  ReleaseMutex(hMutex: this->m_hDataMutex);
  return nThingsHandled;
}

//------------------------------------------------------------------------------
// Address: 0x10003950
// Name: private: bool CVWatchService::Scan_R(class CWatchedDir __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVWatchService::Scan_R(CVWatchService *this, CWatchedDir *pDir, const char *pDirBase)
{
  CWatchedDir *v3; // ebx
  CWatchedDir *ChildDir; // eax
  int m_nQueuedFileStats; // ecx
  unsigned int dwLowDateTime; // ebx
  int v9; // edx
  CVWatchService::CQueuedFileStat *v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // eax
  int m_nOffset; // eax
  char *v14; // eax
  char szSearch[260]; // [esp+8h] [ebp-360h] BYREF
  char szFullName[260]; // [esp+10Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findData; // [esp+210h] [ebp-158h] BYREF
  unsigned int dwHighDateTime; // [esp+354h] [ebp-14h]
  unsigned int nFileSizeLow; // [esp+358h] [ebp-10h]
  int v20; // [esp+35Ch] [ebp-Ch]
  void *hSearch; // [esp+360h] [ebp-8h]
  bool bRet; // [esp+367h] [ebp-1h]

  v3 = pDir;
  if ( pDir->m_bUpToDate )
    return true;
  V_ComposeFileName(path: pDirBase, filename: "*.*", dest: szSearch, destSize: 260);
  bRet = true;
  hSearch = FindFirstFileA(lpFileName: szSearch, lpFindFileData: &findData);
  if ( hSearch == (void *)-1 )
    goto LABEL_27;
  while ( 1 )
  {
    if ( findData.cFileName[0] != 46 )
    {
      ++this->m_pVWatchHeader->m_Stats.m_nFilesIterated;
      V_ComposeFileName(path: pDirBase, filename: findData.cFileName, dest: szFullName, destSize: 260);
      if ( (findData.dwFileAttributes & 0x10) == 0 )
        break;
      ChildDir = CWatchedDir::FindChildDir(this: v3, pLongDirName: findData.cFileName);
      if ( ChildDir == nullptr )
      {
        ChildDir = CVWatchService::AddChildDir(this, pDir: v3, pShortName: findData.cFileName, pLongName: szFullName);
        if ( ChildDir == nullptr )
          return false;
      }
      if ( !CVWatchService::Scan_R(this, pDir: ChildDir, pDirBase: szFullName) )
        goto LABEL_25;
    }
LABEL_21:
    if ( !FindNextFileA(hFindFile: hSearch, lpFindFileData: &findData) )
      goto LABEL_26;
  }
  m_nQueuedFileStats = this->m_nQueuedFileStats;
  ++this->m_nFilesScanned;
  dwLowDateTime = findData.ftLastWriteTime.dwLowDateTime;
  dwHighDateTime = findData.ftLastWriteTime.dwHighDateTime;
  nFileSizeLow = findData.nFileSizeLow;
  v20 = 0;
  if ( m_nQueuedFileStats + 1 >= 20 )
    CVWatchService::CommitQueuedFileStats(this);
  v9 = this->m_nQueuedFileStats++;
  v10 = &this->m_QueuedFileStats[v9];
  V_strncpy(pDest: this->m_QueuedFileStats[v9].m_Filename, pSrc: szFullName, maxLen: 260);
  v11 = dwHighDateTime;
  v12 = nFileSizeLow;
  v10->m_ModifiedTime.dwLowDateTime = dwLowDateTime;
  v10->m_ModifiedTime.dwHighDateTime = v11;
  v10->m_nFileSize = v12;
  ++this->m_nCheckSignalsCounter;
  if ( (this->m_nCheckSignalsCounter & 0xF) != 0
    || (CVWatchService::CheckSignals(this), this->m_bExit.m_value == 0)
    && !this->m_bShouldRestart
    && !this->m_Allocator.m_bHasRunOutOfMemory
    && ((m_nOffset = pDir->m_pWatchedDirectoryRoot.m_nOffset) == 0
      ? (v14 = nullptr)
      : (v14 = (char *)&pDir->m_pWatchedDirectoryRoot + m_nOffset),
        v14[28] != 0) )
  {
    v3 = pDir;
    goto LABEL_21;
  }
  v3 = pDir;
LABEL_25:
  bRet = false;
LABEL_26:
  FindClose(hFindFile: hSearch);
  if ( bRet )
LABEL_27:
    v3->m_bUpToDate = true;
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x10003B60
// Name: private: void CVWatchService::FinishInitializing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::FinishInitializing(CVWatchService *this)
{
  CVWatchHeader::Init(this: this->m_pVWatchHeader);
  this->m_pVWatchHeader->m_dwProcessID = GetCurrentProcessId();
  CLinearMemoryAllocator::Init(
    this: &this->m_Allocator,
    pBase: this->m_SharedMemory.m_pStart + 34324,
    nMaxBytes: this->m_SharedMemory.m_nBytes - 34324,
    bAutoFree: false);
  CVWatchService::ReadConfigFile(this);
  ReleaseMutex(hMutex: this->m_hDataMutex);
}

//------------------------------------------------------------------------------
// Address: 0x10003BC0
// Name: private: void CVWatchService::Scan(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchService::Scan(CVWatchService *this)
{
  CVWatchHeader *m_pVWatchHeader; // eax
  int m_nOffset; // ecx
  int v4; // esi
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  int v11; // eax
  int nDirectoriesScanned; // [esp+4h] [ebp-4h]

  while ( this->m_bExit.m_value == 0 )
  {
    nDirectoriesScanned = 0;
    if ( this->m_Allocator.m_bHasRunOutOfMemory )
      goto LABEL_21;
    m_pVWatchHeader = this->m_pVWatchHeader;
    m_nOffset = m_pVWatchHeader->m_pFirstWatchedDirectoryRoot.m_nOffset;
    if ( m_nOffset != 0 )
    {
      v4 = (int)&m_pVWatchHeader->m_pFirstWatchedDirectoryRoot + m_nOffset;
      if ( (CVWatchHeader *)((char *)m_pVWatchHeader + m_nOffset) != (CVWatchHeader *)-1384 )
      {
        while ( 1 )
        {
          if ( *(_BYTE *)(v4 + 29) == 0 && *(_BYTE *)(v4 + 28) != 0 )
          {
            v5 = *(_DWORD *)(v4 + 24);
            ++nDirectoriesScanned;
            if ( v5 != 0 )
              v6 = (const char *)(v5 + v4 + 24);
            else
              v6 = nullptr;
            _Msg(a1: "Scanning directory %s\n", v6);
            v7 = *(_DWORD *)(v4 + 24);
            if ( v7 != 0 )
              v8 = (const char *)(v7 + v4 + 24);
            else
              v8 = nullptr;
            if ( !CVWatchService::Scan_R(this, pDir: (CWatchedDir *)v4, pDirBase: v8) )
              break;
            v9 = *(_DWORD *)(v4 + 24);
            if ( v9 != 0 )
              v10 = (const char *)(v9 + v4 + 24);
            else
              v10 = nullptr;
            _Msg(a1: "Finished scanning directory %s\n", v10);
            *(_BYTE *)(v4 + 29) = 1;
          }
          v11 = *(_DWORD *)(v4 + 32);
          if ( v11 != 0 )
          {
            v4 += v11 + 32;
            if ( v4 != 0 )
              continue;
          }
          break;
        }
      }
    }
    CVWatchService::CommitQueuedFileStats(this);
    if ( nDirectoriesScanned == 0 )
    {
LABEL_21:
      if ( CVWatchService::CheckSignals(this) == 0 )
        _ThreadSleep(a1: 50);
    }
    if ( this->m_bShouldRestart )
    {
      WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
      CVWatchHeader::Init(this: this->m_pVWatchHeader);
      this->m_pVWatchHeader->m_dwProcessID = GetCurrentProcessId();
      CLinearMemoryAllocator::Init(
        this: &this->m_Allocator,
        pBase: this->m_SharedMemory.m_pStart + 34324,
        nMaxBytes: this->m_SharedMemory.m_nBytes - 34324,
        bAutoFree: false);
      CVWatchService::ReadConfigFile(this);
      ReleaseMutex(hMutex: this->m_hDataMutex);
      this->m_bShouldRestart = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D30
// Name: public: virtual bool CVWatchService::Run(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVWatchService::Run(CVWatchService *this, void *(__cdecl *pFactoryFn)(const char *, int *))
{
  IBaseFileSystem *v3; // eax
  CUtlString *v5; // eax
  CUtlString *v6; // eax
  const char *v7; // eax
  const CUtlString *v8; // eax
  const char *v9; // [esp-4h] [ebp-140h]
  char moduleFilename[260]; // [esp+8h] [ebp-134h] BYREF
  CUtlString v11; // [esp+10Ch] [ebp-30h] BYREF
  CUtlString v12; // [esp+11Ch] [ebp-20h] BYREF
  CUtlString v13; // [esp+12Ch] [ebp-10h] BYREF

  v3 = (IBaseFileSystem *)pFactoryFn(a1: "VBaseFileSystem011", a2: nullptr);
  this->m_pFileSystem = v3;
  if ( v3 != nullptr )
  {
    GetModuleFileNameA(hModule: nullptr, lpFilename: moduleFilename, nSize: 0x104u);
    v9 = g_pVWatchConfigFilename;
    v5 = CUtlString::CUtlString(this: &v11, pString: moduleFilename);
    v6 = CUtlString::DirName(this: v5, result: &v13);
    v7 = CUtlString::operator char const *(this: v6);
    v8 = CUtlString::PathJoin(result: &v12, pStr1: v7, pStr2: v9);
    CUtlString::operator=(this: &this->m_sConfigFilename, src: v8);
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v12.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
        v12.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v12.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v13.m_Storage.m_nActualLength = 0;
    if ( v13.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v13.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13.m_Storage.m_Memory.m_pMemory);
        v13.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v13.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    v11.m_Storage.m_nActualLength = 0;
    if ( v11.m_Storage.m_Memory.m_nGrowSize >= 0 && v11.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_Storage.m_Memory.m_pMemory);
    _InterlockedExchange(&this->m_bRunning.m_value, 1);
    CFileChangeWatcher::Term(this: &this->m_FileChangeWatcher);
    WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: 0xFFFFFFFF);
    if ( CSharedMemoryMgr::Create(
           this: &this->m_SharedMemory,
           pSharedName: "Global\\vwatch_shared_data",
           nBytes: 0x6400000u) )
    {
      this->m_nWatchedDirLongNameBytes = 0;
      this->m_nWatchedDirBytes = 0;
      this->m_nWatchedFileBytes = 0;
      *(_DWORD *)this->m_SharedMemory.m_pStart = 2;
      this->m_pVWatchHeader = (CVWatchHeader *)(this->m_SharedMemory.m_pStart + 4);
      CVWatchService::FinishInitializing(this);
      CVWatchService::Scan(this);
      _InterlockedExchange(&this->m_bRunning.m_value, 0);
      return 1;
    }
    else
    {
      _Warning(a1: "Unable to create shared memory");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "vwatch service unable to get %s", "VBaseFileSystem011");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: __CreateCVWatchServiceIVWatchService_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVWatchService *__cdecl _CreateCVWatchServiceIVWatchService_interface()
{
  return &g_VWatchService;
}
