// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/overwatch/overwatchlib/overwatchclient.cpp
// Functions: 24
// ============================================================

#include "utils\overwatch\overwatchlib\overwatchclient.h"

//------------------------------------------------------------------------------
// Address: 0x004013B0
// Name: public: void COverwatchSnapshot::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchSnapshot::Release(COverwatchSnapshot *this)
{
  if ( --this->m_nRefCount <= 0 )
    ((void (__thiscall *)(COverwatchSnapshot *, int))this->dtr_COverwatchSnapshot)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004013D0
// Name: public: virtual class CSnapshotDir __near * COverwatchSnapshot::GetRootDir(void)
// Source: json
//------------------------------------------------------------------------------
CSnapshotDir *__thiscall COverwatchSnapshot::GetRootDir(COverwatchSnapshot *this)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004013E0
// Name: public: COverwatchClient::COverwatchClient(void)
// Source: json
//------------------------------------------------------------------------------
COverwatchClient *__thiscall COverwatchClient::COverwatchClient(COverwatchClient *this)
{
  CSharedMemoryMgr *v2; // eax
  CSharedMemoryMgr *v3; // eax
  CSharedMemoryMgr *v4; // eax
  CSharedMemoryMgr *v5; // eax

  this->m_pOverwatchHeader = nullptr;
  this->m_hDataMutex = nullptr;
  v2 = (CSharedMemoryMgr *)operator new(nSize: 0x10u);
  if ( v2 != nullptr )
    v3 = CSharedMemoryMgr::CSharedMemoryMgr(this: v2);
  else
    v3 = nullptr;
  this->m_pSharedMemoryMgr = v3;
  v4 = (CSharedMemoryMgr *)operator new(nSize: 0x10u);
  if ( v4 != nullptr )
  {
    v5 = CSharedMemoryMgr::CSharedMemoryMgr(this: v4);
    this->m_hAppSignalEvent = nullptr;
    this->m_hOverwatchServiceProcess = nullptr;
    this->m_pAppSignalMemory = v5;
  }
  else
  {
    this->m_hAppSignalEvent = nullptr;
    this->m_hOverwatchServiceProcess = nullptr;
    this->m_pAppSignalMemory = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401440
// Name: bool InitSharedMemoryWithNames(class CSharedMemoryMgr __near *,char __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitSharedMemoryWithNames(
        CSharedMemoryMgr *pMgr,
        char *pOutName,
        int nMaxBytes,
        const char *pBaseName,
        int nTries)
{
  int v5; // esi

  v5 = 0;
  if ( nTries <= 0 )
    return 0;
  while ( 1 )
  {
    V_snprintf(pDest: pOutName, maxLen: nMaxBytes, pFormat: "%s_%d", pBaseName, v5);
    if ( CSharedMemoryMgr::Create(this: pMgr, pSharedName: pOutName, nBytes: 0x400u) )
      break;
    if ( ++v5 >= nTries )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004014A0
// Name: void __near * CreateEventWithNames(char __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
HANDLE __cdecl CreateEventWithNames(char *pOutName, int nMaxBytes, const char *pBaseName, int nTries)
{
  int v4; // edi
  HANDLE result; // eax

  v4 = 0;
  if ( nTries <= 0 )
    return nullptr;
  while ( 1 )
  {
    V_snprintf(pDest: pOutName, maxLen: nMaxBytes, pFormat: "%s_%d", pBaseName, v4);
    result = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: false, lpName: pOutName);
    if ( result != nullptr )
      break;
    if ( ++v4 >= nTries )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004014F0
// Name: public: void COverwatchClient::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchClient::Term(COverwatchClient *this)
{
  void *m_hDataMutex; // eax

  m_hDataMutex = this->m_hDataMutex;
  this->m_pOverwatchHeader = nullptr;
  if ( m_hDataMutex != nullptr )
  {
    CloseHandle(hObject: m_hDataMutex);
    this->m_hDataMutex = nullptr;
  }
  if ( this->m_hOverwatchServiceProcess != nullptr )
  {
    CloseHandle(hObject: this->m_hOverwatchServiceProcess);
    this->m_hOverwatchServiceProcess = nullptr;
  }
  CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
}

//------------------------------------------------------------------------------
// Address: 0x00401530
// Name: public: bool COverwatchClient::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverwatchClient::IsConnected(COverwatchClient *this)
{
  void *m_hDataMutex; // eax

  if ( CSharedMemoryMgr::IsValid(this: this->m_pSharedMemoryMgr)
    && WaitForSingleObject(hHandle: this->m_hOverwatchServiceProcess, dwMilliseconds: 0) != 0 )
  {
    return 1;
  }
  m_hDataMutex = this->m_hDataMutex;
  this->m_pOverwatchHeader = nullptr;
  if ( m_hDataMutex != nullptr )
  {
    CloseHandle(hObject: m_hDataMutex);
    this->m_hDataMutex = nullptr;
  }
  if ( this->m_hOverwatchServiceProcess != nullptr )
  {
    CloseHandle(hObject: this->m_hOverwatchServiceProcess);
    this->m_hOverwatchServiceProcess = nullptr;
  }
  CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401590
// Name: public: class COverwatchStats const __near * COverwatchClient::GetOverwatchStats(void)
// Source: json
//------------------------------------------------------------------------------
COverwatchHeader *__thiscall COverwatchClient::GetOverwatchStats(COverwatchClient *this)
{
  return this->m_pOverwatchHeader;
}

//------------------------------------------------------------------------------
// Address: 0x004015A0
// Name: public: bool COverwatchClient::GetNumFilesScanned(int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverwatchClient::GetNumFilesScanned(COverwatchClient *this, int *pnFilesScanned, DWORD nTimeout)
{
  int v4; // eax
  DWORD v5; // edi
  void *m_hDataMutex; // ecx
  DWORD v8; // ecx
  DWORD v9; // eax
  void *v10; // eax
  COverwatchHeader *m_pOverwatchHeader; // eax
  int v12; // ebx
  DWORD v13; // eax
  void *m_hAppSignalEvent; // edx
  int v15; // [esp+Ch] [ebp-Ch]
  HANDLE Handles; // [esp+10h] [ebp-8h] BYREF
  void *v17; // [esp+14h] [ebp-4h]

  v4 = _Plat_MSTime();
  v5 = nTimeout;
  m_hDataMutex = this->m_hDataMutex;
  v15 = v4;
  Handles = this->m_hOverwatchServiceProcess;
  v17 = m_hDataMutex;
  if ( WaitForMultipleObjects(nCount: 2u, lpHandles: &Handles, bWaitAll: false, dwMilliseconds: nTimeout) != 1 )
    return 0;
  while ( this->m_pOverwatchHeader->m_nAppSignals >= 4u )
  {
    ReleaseMutex(hMutex: this->m_hDataMutex);
    _ThreadSleep(a1: 1);
    if ( nTimeout == -1 )
    {
      v8 = -1;
    }
    else
    {
      v9 = _Plat_MSTime() - v15;
      v8 = v9 <= nTimeout ? nTimeout - v9 : 0;
    }
    v10 = this->m_hDataMutex;
    Handles = this->m_hOverwatchServiceProcess;
    v17 = v10;
    if ( WaitForMultipleObjects(nCount: 2u, lpHandles: &Handles, bWaitAll: false, dwMilliseconds: v8) != 1 )
      return 0;
  }
  m_pOverwatchHeader = this->m_pOverwatchHeader;
  v12 = (int)&m_pOverwatchHeader->m_AppSignals[m_pOverwatchHeader->m_nAppSignals++];
  *(_DWORD *)v12 = 2;
  V_strncpy(pDest: (char *)(v12 + 264), pSrc: this->m_AppSignalMemoryName, maxLen: 32);
  V_strncpy(pDest: (char *)(v12 + 296), pSrc: this->m_AppSignalEventName, maxLen: 32);
  ReleaseMutex(hMutex: this->m_hDataMutex);
  if ( nTimeout != -1 )
  {
    v13 = _Plat_MSTime() - v15;
    if ( v13 <= nTimeout )
      v5 = nTimeout - v13;
    else
      v5 = 0;
  }
  m_hAppSignalEvent = this->m_hAppSignalEvent;
  Handles = this->m_hOverwatchServiceProcess;
  v17 = m_hAppSignalEvent;
  if ( WaitForMultipleObjects(nCount: 2u, lpHandles: &Handles, bWaitAll: false, dwMilliseconds: v5) != 1 )
    return 0;
  *pnFilesScanned = *(_DWORD *)this->m_pAppSignalMemory->m_pStart;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401720
// Name: public: CSnapshotInternal::CSnapshotInternal(void)
// Source: json
//------------------------------------------------------------------------------
CSnapshotInternal *__thiscall CSnapshotInternal::CSnapshotInternal(CSnapshotInternal *this)
{
  this->m_nRefCount = 1;
  this->__vftable = (CSnapshotInternal_vtbl *)&CSnapshotInternal::`vftable';
  CLinearMemoryAllocator::CLinearMemoryAllocator(this: &this->m_Allocator);
  this->m_pRootDir = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401750
// Name: public: virtual void CSnapshotInternal::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnapshotInternal::Release(CSnapshotInternal *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CSnapshotInternal *, int))this->dtr_COverwatchSnapshot)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401760
// Name: public: virtual class CSnapshotDir __near * CSnapshotInternal::GetRootDir(void)
// Source: json
//------------------------------------------------------------------------------
CSnapshotDir *__thiscall CSnapshotInternal::GetRootDir(CSnapshotInternal *this)
{
  return this->m_pRootDir;
}

//------------------------------------------------------------------------------
// Address: 0x00401770
// Name: public: class CSnapshotDir __near * CSnapshotDir::GetDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSnapshotDir *__thiscall CSnapshotDir::GetDir(CSnapshotDir *this, const char *pLongName)
{
  int m_nOffset; // eax
  _DWORD *v3; // esi
  const char *v4; // eax
  int v5; // eax

  m_nOffset = this->m_pFirstDir.m_nOffset;
  if ( m_nOffset == 0 )
    return nullptr;
  v3 = (int *)((char *)&this->m_pFirstDir.m_nOffset + m_nOffset);
  if ( (CSnapshotDir *)((char *)this + m_nOffset) == (CSnapshotDir *)-4 )
    return nullptr;
  while ( 1 )
  {
    v4 = *v3 != 0 ? (char *)v3 + *v3 : nullptr;
    if ( _stricmp(dst: v4, src: pLongName) == 0 )
      break;
    v5 = v3[2];
    if ( v5 != 0 )
    {
      v3 = (_DWORD *)((char *)v3 + v5 + 8);
      if ( v3 != nullptr )
        continue;
    }
    return nullptr;
  }
  return (CSnapshotDir *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004017E0
// Name: public: COverwatchClient::~COverwatchClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverwatchClient::~COverwatchClient(COverwatchClient *this)
{
  CSharedMemoryMgr *m_pSharedMemoryMgr; // edi
  CSharedMemoryMgr *m_pAppSignalMemory; // esi

  m_pSharedMemoryMgr = this->m_pSharedMemoryMgr;
  if ( this->m_pSharedMemoryMgr != nullptr )
  {
    CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
    free(pMem: m_pSharedMemoryMgr);
  }
  m_pAppSignalMemory = this->m_pAppSignalMemory;
  if ( m_pAppSignalMemory != nullptr )
  {
    CSharedMemoryMgr::~CSharedMemoryMgr(this: m_pAppSignalMemory);
    free(pMem: m_pAppSignalMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401820
// Name: public: bool COverwatchClient::Connect(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverwatchClient::Connect(COverwatchClient *this, DWORD nTimeout)
{
  void *m_hDataMutex; // eax
  unsigned int v4; // ebx
  DWORD v5; // edi
  HANDLE v6; // eax
  unsigned int v7; // eax
  unsigned __int8 *m_pStart; // eax
  COverwatchHeader *v10; // eax
  HANDLE v11; // eax
  HANDLE EventWithNames; // eax
  int v13; // [esp+10h] [ebp-4h]

  m_hDataMutex = this->m_hDataMutex;
  v4 = 0;
  this->m_pOverwatchHeader = nullptr;
  if ( m_hDataMutex != nullptr )
  {
    CloseHandle(hObject: m_hDataMutex);
    this->m_hDataMutex = nullptr;
  }
  if ( this->m_hOverwatchServiceProcess != nullptr )
  {
    CloseHandle(hObject: this->m_hOverwatchServiceProcess);
    this->m_hOverwatchServiceProcess = nullptr;
  }
  CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
  v13 = _Plat_MSTime();
  v5 = nTimeout;
  if ( !CSharedMemoryMgr::Open(this: this->m_pSharedMemoryMgr, pSharedName: "overwatch_shared_data", nBytes: 0x2800000u) )
  {
    while ( nTimeout != 0 )
    {
      _ThreadSleep(a1: 20);
      v4 += 20;
      if ( v4 > nTimeout )
        break;
      if ( CSharedMemoryMgr::Open(
             this: this->m_pSharedMemoryMgr,
             pSharedName: "overwatch_shared_data",
             nBytes: 0x2800000u) )
      {
        goto LABEL_9;
      }
    }
    return 0;
  }
LABEL_9:
  v6 = OpenMutexA(dwDesiredAccess: 0x100000u, bInheritHandle: false, lpName: "overwatch_mutex");
  this->m_hDataMutex = v6;
  if ( v6 == nullptr )
    goto LABEL_17;
  if ( nTimeout != -1 )
  {
    v7 = _Plat_MSTime() - v13;
    if ( v7 <= nTimeout )
      v5 = nTimeout - v7;
    else
      v5 = 0;
  }
  if ( WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: v5) != 0 )
  {
LABEL_17:
    COverwatchClient::Term(this);
    return 0;
  }
  ReleaseMutex(hMutex: this->m_hDataMutex);
  m_pStart = this->m_pSharedMemoryMgr->m_pStart;
  if ( *(_DWORD *)m_pStart != 342526 )
  {
    _Warning(a1: "Invalid overwatch protocol version number (%lu)\n");
    goto LABEL_17;
  }
  v10 = (COverwatchHeader *)(m_pStart + 4);
  this->m_pOverwatchHeader = v10;
  v11 = OpenProcess(dwDesiredAccess: 0x100000u, bInheritHandle: false, dwProcessId: v10->m_dwOverwatchProcessID);
  this->m_hOverwatchServiceProcess = v11;
  if ( v11 == nullptr )
  {
    _Warning(a1: "Can't get overwatch process handle from id %lu\n");
    goto LABEL_17;
  }
  if ( InitSharedMemoryWithNames(
         pMgr: this->m_pAppSignalMemory,
         pOutName: this->m_AppSignalMemoryName,
         nMaxBytes: 32,
         pBaseName: "ow_signal_",
         nTries: 2000) != 0 )
  {
    EventWithNames = CreateEventWithNames(
                       pOutName: this->m_AppSignalEventName,
                       nMaxBytes: 32,
                       pBaseName: "ow_signal_event_",
                       nTries: 2000);
    this->m_hAppSignalEvent = EventWithNames;
    if ( EventWithNames != nullptr )
    {
      return 1;
    }
    else
    {
      _Warning(a1: "Can't create AppSignal event.\n");
      COverwatchClient::Term(this);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Can't create AppSignal shared memory.\n");
    COverwatchClient::Term(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019E0
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AA0
// Name: AddRoot
// Source: json
//------------------------------------------------------------------------------
CSnapshotDir *__cdecl AddRoot(CSnapshotInternal *pRet)
{
  CUtlString *sDirName; // ecx
  unsigned __int8 *m_pBase; // esi
  unsigned int v3; // eax
  bool v4; // zf
  CSnapshotDir *v5; // esi
  const char *v6; // eax
  char *v7; // eax

  m_pBase = pRet->m_Allocator.m_pBase;
  v3 = 4 * ((pRet->m_Allocator.m_nCurOffset + 3) >> 2);
  v4 = &m_pBase[v3] == nullptr;
  v5 = (CSnapshotDir *)&m_pBase[v3];
  pRet->m_Allocator.m_nCurOffset = v3 + 16;
  if ( !v4 )
  {
    v5->m_pLongName.m_nOffset = 0;
    v5->m_pNextDir.m_nOffset = 0;
    v5->m_pFirstDir.m_nOffset = 0;
    v5->m_pFirstFile.m_nOffset = 0;
  }
  v6 = CUtlString::operator char const *(this: sDirName);
  v7 = CLinearMemoryAllocator::CopyString(this: &pRet->m_Allocator, pStr: v6);
  if ( v7 != nullptr )
    v5->m_pLongName.m_nOffset = v7 - (char *)v5;
  else
    v5->m_pLongName.m_nOffset = 0;
  v5->m_pFirstFile.m_nOffset = 0;
  v5->m_pNextDir.m_nOffset = 0;
  v5->m_pFirstDir.m_nOffset = 0;
  pRet->m_pRootDir = v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: void ConvertWatchedDirToSnapshotDir(class CLinearMemoryAllocator __near &,class CWatchedDir __near *,class CSnapshotDir __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertWatchedDirToSnapshotDir(
        CLinearMemoryAllocator *allocator,
        CWatchedDir *pFromRoot,
        CSnapshotDir *pToRoot)
{
  CWatchedDir *v3; // ecx
  int m_nOffset; // eax
  CWatchedDir *v5; // edi
  COffsetPtr<CSnapshotDir> *p_m_pFirstDir; // ebp
  unsigned int v7; // eax
  bool v8; // zf
  CSnapshotDir *v9; // esi
  int v10; // eax
  const char *v11; // eax
  char *v12; // eax
  COffsetPtr<CSnapshotDir> *p_m_pNextDir; // ebx
  char *v14; // eax
  int v15; // eax
  int v16; // edi
  int i; // edi
  unsigned int v18; // eax
  unsigned __int8 *v19; // esi
  char *v20; // eax
  char *v21; // ecx
  char *v22; // eax
  COffsetPtr<CSnapshotFile> *p_m_pFirstFile; // eax
  int v24; // ecx
  char *v25; // edx
  char *v26; // ecx
  int v27; // eax

  v3 = pFromRoot;
  m_nOffset = pFromRoot->m_pFirstChildDir.m_nOffset;
  if ( pFromRoot->m_pFirstChildDir.m_nOffset != 0 )
  {
    v5 = (CWatchedDir *)((char *)pFromRoot + m_nOffset);
    if ( (CWatchedDir *)((char *)pFromRoot + m_nOffset) != nullptr )
    {
      p_m_pFirstDir = &pToRoot->m_pFirstDir;
      do
      {
        v7 = 4 * ((allocator->m_nCurOffset + 3) >> 2);
        v8 = &allocator->m_pBase[v7] == nullptr;
        v9 = (CSnapshotDir *)&allocator->m_pBase[v7];
        allocator->m_nCurOffset = v7 + 16;
        if ( !v8 )
        {
          v9->m_pLongName.m_nOffset = 0;
          v9->m_pNextDir.m_nOffset = 0;
          v9->m_pFirstDir.m_nOffset = 0;
          v9->m_pFirstFile.m_nOffset = 0;
        }
        v10 = v5->m_pLongName.m_nOffset;
        if ( v10 != 0 )
          v11 = (char *)&v5->m_pLongName + v10;
        else
          v11 = nullptr;
        v12 = CLinearMemoryAllocator::CopyString(this: allocator, pStr: v11);
        if ( v12 != nullptr )
          v9->m_pLongName.m_nOffset = v12 - (char *)v9;
        else
          v9->m_pLongName.m_nOffset = 0;
        v9->m_pFirstFile.m_nOffset = 0;
        p_m_pNextDir = &v9->m_pNextDir;
        v9->m_pNextDir.m_nOffset = 0;
        v9->m_pFirstDir.m_nOffset = 0;
        ConvertWatchedDirToSnapshotDir(allocator, pFromRoot: v5, pToRoot: v9);
        if ( p_m_pFirstDir->m_nOffset != 0 && (v14 = (char *)p_m_pFirstDir + p_m_pFirstDir->m_nOffset) != nullptr )
          p_m_pNextDir->m_nOffset = v14 - (char *)p_m_pNextDir;
        else
          p_m_pNextDir->m_nOffset = 0;
        p_m_pFirstDir->m_nOffset = (char *)v9 - (char *)p_m_pFirstDir;
        v15 = v5->m_pNextChildDir.m_nOffset;
        if ( v15 == 0 )
          break;
        v5 = (CWatchedDir *)((char *)v5 + v15 + 4);
      }
      while ( v5 != nullptr );
      v3 = pFromRoot;
    }
  }
  v16 = v3->m_pFirstFile.m_nOffset;
  if ( v16 != 0 )
  {
    for ( i = (int)&v3->m_pFirstFile + v16; i != 0; i += v27 + 20 )
    {
      if ( (*(_DWORD *)(i + 4) & *(_DWORD *)i) != -1 )
      {
        v18 = 4 * ((allocator->m_nCurOffset + 3) >> 2);
        v8 = &allocator->m_pBase[v18] == nullptr;
        v19 = &allocator->m_pBase[v18];
        allocator->m_nCurOffset = v18 + 24;
        if ( !v8 )
        {
          *(_DWORD *)v19 = 0;
          *((_DWORD *)v19 + 1) = 0;
          *((_DWORD *)v19 + 2) = 0;
          *((_DWORD *)v19 + 3) = 0;
          *((_DWORD *)v19 + 4) = 0;
        }
        v20 = CLinearMemoryAllocator::CopyString(this: allocator, pStr: (const char *)(i + 36));
        v21 = (char *)(v19 + 8);
        if ( v20 != nullptr )
          *(_DWORD *)v21 = v20 - v21;
        else
          *(_DWORD *)v21 = 0;
        *(_DWORD *)v19 = *(_DWORD *)i;
        *((_DWORD *)v19 + 1) = *(_DWORD *)(i + 4);
        v22 = (char *)(v19 + 16);
        if ( pToRoot != nullptr )
          *(_DWORD *)v22 = (char *)pToRoot - v22;
        else
          *(_DWORD *)v22 = 0;
        p_m_pFirstFile = &pToRoot->m_pFirstFile;
        v24 = pToRoot->m_pFirstFile.m_nOffset;
        v25 = (char *)(v19 + 12);
        if ( v24 != 0 && (v26 = (char *)p_m_pFirstFile + v24) != nullptr )
          *(_DWORD *)v25 = v26 - v25;
        else
          *(_DWORD *)v25 = 0;
        p_m_pFirstFile->m_nOffset = v19 - (unsigned __int8 *)p_m_pFirstFile;
      }
      v27 = *(_DWORD *)(i + 20);
      if ( v27 == 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401CC0
// Name: void SlowGenerateSnapshot_R(class CLinearMemoryAllocator __near &,class CSnapshotDir __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SlowGenerateSnapshot_R(CLinearMemoryAllocator *allocator, CSnapshotDir *pRoot, const char *pRootPath)
{
  unsigned __int8 *m_pBase; // esi
  unsigned int v4; // eax
  bool v5; // zf
  CSnapshotDir *v6; // esi
  char *v7; // eax
  COffsetPtr<CSnapshotDir> *p_m_pNextDir; // edi
  int m_nOffset; // ecx
  char *p_m_pFirstDir; // eax
  char *v11; // ecx
  char *v12; // eax
  COffsetPtr<CSnapshotDir> *v13; // ecx
  unsigned int nFileSizeLow; // edx
  CSnapshotDir *v15; // eax
  int v16; // ecx
  COffsetPtr<CSnapshotFile> *p_m_pFirstFile; // edx
  char *v18; // ecx
  _WIN32_FIND_DATAA findData; // [esp+4h] [ebp-34Ch] BYREF
  char szFullName[260]; // [esp+144h] [ebp-20Ch] BYREF
  char szSearch[264]; // [esp+248h] [ebp-108h] BYREF

  V_ComposeFileName(path: pRootPath, filename: "*.*", dest: &szSearch[4], destSize: 260);
  findData.dwFileAttributes = (unsigned int)FindFirstFileA(
                                              lpFileName: &szSearch[4],
                                              lpFindFileData: (LPWIN32_FIND_DATAA)&findData.ftCreationTime);
  if ( findData.dwFileAttributes != -1 )
  {
    do
    {
      if ( findData.cFileName[4] != 46 )
      {
        V_ComposeFileName(path: pRootPath, filename: &findData.cFileName[4], dest: &szFullName[4], destSize: 260);
        m_pBase = allocator->m_pBase;
        v4 = 4 * ((allocator->m_nCurOffset + 3) >> 2);
        if ( (findData.ftCreationTime.dwLowDateTime & 0x10) != 0 )
        {
          v5 = &m_pBase[v4] == nullptr;
          v6 = (CSnapshotDir *)&m_pBase[v4];
          allocator->m_nCurOffset = v4 + 16;
          if ( !v5 )
          {
            v6->m_pLongName.m_nOffset = 0;
            v6->m_pNextDir.m_nOffset = 0;
            v6->m_pFirstDir.m_nOffset = 0;
            v6->m_pFirstFile.m_nOffset = 0;
          }
          v7 = CLinearMemoryAllocator::CopyString(this: allocator, pStr: &szFullName[4]);
          if ( v7 != nullptr )
            v6->m_pLongName.m_nOffset = v7 - (char *)v6;
          else
            v6->m_pLongName.m_nOffset = 0;
          v6->m_pFirstFile.m_nOffset = 0;
          p_m_pNextDir = &v6->m_pNextDir;
          v6->m_pNextDir.m_nOffset = 0;
          v6->m_pFirstDir.m_nOffset = 0;
          SlowGenerateSnapshot_R(allocator, pRoot: v6, pRootPath: &szFullName[4]);
          m_nOffset = pRoot->m_pFirstDir.m_nOffset;
          p_m_pFirstDir = (char *)&pRoot->m_pFirstDir;
          if ( m_nOffset != 0 && (v11 = &p_m_pFirstDir[m_nOffset]) != nullptr )
            p_m_pNextDir->m_nOffset = v11 - (char *)p_m_pNextDir;
          else
            p_m_pNextDir->m_nOffset = 0;
        }
        else
        {
          v5 = &m_pBase[v4] == nullptr;
          v6 = (CSnapshotDir *)&m_pBase[v4];
          allocator->m_nCurOffset = v4 + 24;
          if ( !v5 )
          {
            v6->m_pLongName.m_nOffset = 0;
            v6->m_pFirstDir.m_nOffset = 0;
            v6->m_pNextDir.m_nOffset = 0;
            v6->m_pFirstFile.m_nOffset = 0;
            v6[1].m_pLongName.m_nOffset = 0;
          }
          v12 = CLinearMemoryAllocator::CopyString(this: allocator, pStr: &findData.cFileName[4]);
          v13 = &v6->m_pNextDir;
          if ( v12 != nullptr )
            v13->m_nOffset = v12 - (char *)v13;
          else
            v13->m_nOffset = 0;
          nFileSizeLow = findData.nFileSizeLow;
          v6->m_pLongName.m_nOffset = findData.dwReserved0;
          v6->m_pFirstDir.m_nOffset = nFileSizeLow;
          v15 = v6 + 1;
          if ( pRoot != nullptr )
            v15->m_pLongName.m_nOffset = (char *)pRoot - (char *)v15;
          else
            v15->m_pLongName.m_nOffset = 0;
          p_m_pFirstDir = (char *)&pRoot->m_pFirstFile;
          v16 = pRoot->m_pFirstFile.m_nOffset;
          p_m_pFirstFile = &v6->m_pFirstFile;
          if ( v16 != 0 && (v18 = &p_m_pFirstDir[v16]) != nullptr )
            p_m_pFirstFile->m_nOffset = v18 - (char *)p_m_pFirstFile;
          else
            p_m_pFirstFile->m_nOffset = 0;
        }
        *(_DWORD *)p_m_pFirstDir = (char *)v6 - p_m_pFirstDir;
      }
    }
    while ( FindNextFileA(
              hFindFile: (HANDLE)findData.dwFileAttributes,
              lpFindFileData: (LPWIN32_FIND_DATAA)&findData.ftCreationTime) );
    FindClose(hFindFile: (HANDLE)findData.dwFileAttributes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E70
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  if ( this->m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EA0
// Name: private: enum GetSnapshotStatus_t COverwatchClient::GetSlowSnapshotForDir(char const __near *,class COverwatchSnapshot __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
GetSnapshotStatus_t __thiscall COverwatchClient::GetSlowSnapshotForDir(
        COverwatchClient *this,
        const char *pDirName,
        COverwatchSnapshot **pSnapshot,
        int nFlags)
{
  CSnapshotInternal *v4; // eax
  CSnapshotInternal *v5; // esi
  void *v6; // eax
  CSnapshotDir *v7; // ebp
  CUtlString v9; // [esp+10h] [ebp-10h] BYREF

  v4 = (CSnapshotInternal *)operator new(nSize: 0x1Cu);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_nRefCount = 1;
    v4->__vftable = (CSnapshotInternal_vtbl *)&CSnapshotInternal::`vftable';
    CLinearMemoryAllocator::CLinearMemoryAllocator(this: &v4->m_Allocator);
    v5->m_pRootDir = nullptr;
  }
  else
  {
    v5 = nullptr;
  }
  v6 = operator new(nSize: 0x200000u);
  CLinearMemoryAllocator::Init(this: &v5->m_Allocator, pBase: v6, nMaxBytes: 0x200000u, bAutoFree: true);
  CUtlString::CUtlString(this: &v9, pString: pDirName);
  v7 = AddRoot(pRet: v5);
  if ( v9.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_Storage.m_Memory.m_pMemory);
      v9.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v9.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  SlowGenerateSnapshot_R(allocator: &v5->m_Allocator, pRoot: v7, pRootPath: pDirName);
  *pSnapshot = v5;
  return GETSNAPSHOT_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00401F60
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401FC0
// Name: FindOrAddDirs
// Source: json
//------------------------------------------------------------------------------
CSnapshotDir *__usercall FindOrAddDirs@<eax>(const CUtlString *sDirName@<eax>, CSnapshotInternal *pRet)
{
  unsigned __int8 *m_nAllocationCount; // ebp
  int m_nGrowSize; // esi
  unsigned __int8 *m_pElements; // edi
  CSnapshotDir *v5; // ebx
  unsigned __int8 *m_pBase; // esi
  unsigned int v7; // eax
  bool v8; // zf
  CSnapshotDir *v9; // esi
  char *v10; // eax
  CUtlString *v11; // ecx
  const char *v12; // eax
  CSnapshotDir *Dir; // ebp
  unsigned __int8 *v14; // esi
  unsigned int v15; // eax
  CSnapshotDir *v16; // esi
  const char *v17; // eax
  char *v18; // eax
  int m_nOffset; // ecx
  COffsetPtr<CSnapshotDir> *p_m_pFirstDir; // eax
  COffsetPtr<CSnapshotDir> *p_m_pNextDir; // edx
  char *v22; // ecx
  CUtlString *v24; // [esp+10h] [ebp-3Ch]
  CUtlString sNext; // [esp+14h] [ebp-38h] BYREF
  CUtlString sCur; // [esp+24h] [ebp-28h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirNames; // [esp+34h] [ebp-18h] BYREF
  unsigned __int8 *v28; // [esp+48h] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&sCur.m_Storage.m_Memory.m_nAllocationCount, string: sDirName);
  m_nAllocationCount = nullptr;
  m_nGrowSize = 0;
  m_pElements = nullptr;
  memset(&dirNames.m_Memory.m_nAllocationCount, 0, 16);
  v28 = nullptr;
  while ( 1 )
  {
    if ( (int)(m_pElements + 1) > m_nGrowSize )
    {
      CUtlMemory<CUtlString,int>::Grow(
        this: (CUtlMemory<CUtlString,int> *)&dirNames.m_Memory.m_nAllocationCount,
        num: (int)&m_pElements[-m_nGrowSize + 1]);
      m_pElements = (unsigned __int8 *)dirNames.m_pElements;
      m_nGrowSize = dirNames.m_Memory.m_nGrowSize;
      m_nAllocationCount = (unsigned __int8 *)dirNames.m_Memory.m_nAllocationCount;
    }
    dirNames.m_pElements = (CUtlString *)++m_pElements;
    v28 = m_nAllocationCount;
    if ( (int)(m_pElements - 1) > 0 )
      memmove(dst: m_nAllocationCount + 16, src: m_nAllocationCount, count: 16 * (_DWORD)(m_pElements - 1));
    if ( m_nAllocationCount != nullptr )
      CUtlString::CUtlString(
        this: (CUtlString *)m_nAllocationCount,
        string: (const CUtlString *)&sCur.m_Storage.m_Memory.m_nAllocationCount);
    CUtlString::DirName(
      this: (CUtlString *)&sCur.m_Storage.m_Memory.m_nAllocationCount,
      result: (CUtlString *)&sNext.m_Storage.m_Memory.m_nAllocationCount);
    if ( CUtlString::operator==(
           this: (CUtlString *)&sNext.m_Storage.m_Memory.m_nAllocationCount,
           src: (const CUtlString *)&sCur.m_Storage.m_Memory.m_nAllocationCount)
      || CUtlString::Length(this: (CUtlString *)&sNext.m_Storage.m_Memory.m_nAllocationCount) == 0 )
    {
      break;
    }
    CUtlString::operator=(
      this: (CUtlString *)&sCur.m_Storage.m_Memory.m_nAllocationCount,
      src: (const CUtlString *)&sNext.m_Storage.m_Memory.m_nAllocationCount);
    if ( sNext.m_Storage.m_nActualLength >= 0 )
    {
      if ( sNext.m_Storage.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)sNext.m_Storage.m_Memory.m_nAllocationCount);
        sNext.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      sNext.m_Storage.m_Memory.m_nGrowSize = 0;
    }
  }
  if ( sNext.m_Storage.m_nActualLength >= 0 && sNext.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)sNext.m_Storage.m_Memory.m_nAllocationCount);
  v5 = (CSnapshotDir *)pRet->GetRootDir(this: pRet);
  if ( v5 == nullptr )
  {
    m_pBase = pRet->m_Allocator.m_pBase;
    v7 = 4 * ((pRet->m_Allocator.m_nCurOffset + 3) >> 2);
    v8 = &m_pBase[v7] == nullptr;
    v9 = (CSnapshotDir *)&m_pBase[v7];
    pRet->m_Allocator.m_nCurOffset = v7 + 16;
    if ( !v8 )
    {
      v9->m_pLongName.m_nOffset = 0;
      v9->m_pNextDir.m_nOffset = 0;
      v9->m_pFirstDir.m_nOffset = 0;
      v9->m_pFirstFile.m_nOffset = 0;
    }
    v5 = v9;
    v10 = CLinearMemoryAllocator::CopyString(this: &pRet->m_Allocator, pStr: pString);
    if ( v10 != nullptr )
      v9->m_pLongName.m_nOffset = v10 - (char *)v9;
    else
      v9->m_pLongName.m_nOffset = 0;
    pRet->m_pRootDir = v9;
  }
  if ( (int)m_pElements > 0 )
  {
    v11 = (CUtlString *)m_nAllocationCount;
    v24 = (CUtlString *)m_nAllocationCount;
    sNext.m_Storage.m_Memory.m_pMemory = m_pElements;
    do
    {
      v12 = CUtlString::operator char const *(this: v11);
      Dir = CSnapshotDir::GetDir(this: v5, pLongName: v12);
      if ( Dir == nullptr )
      {
        v14 = pRet->m_Allocator.m_pBase;
        v15 = 4 * ((pRet->m_Allocator.m_nCurOffset + 3) >> 2);
        v8 = &v14[v15] == nullptr;
        v16 = (CSnapshotDir *)&v14[v15];
        pRet->m_Allocator.m_nCurOffset = v15 + 16;
        if ( !v8 )
        {
          v16->m_pLongName.m_nOffset = 0;
          v16->m_pNextDir.m_nOffset = 0;
          v16->m_pFirstDir.m_nOffset = 0;
          v16->m_pFirstFile.m_nOffset = 0;
        }
        Dir = v16;
        v17 = CUtlString::operator char const *(this: v24);
        v18 = CLinearMemoryAllocator::CopyString(this: &pRet->m_Allocator, pStr: v17);
        if ( v18 != nullptr )
          v16->m_pLongName.m_nOffset = v18 - (char *)v16;
        else
          v16->m_pLongName.m_nOffset = 0;
        v16->m_pFirstDir.m_nOffset = 0;
        if ( v5 != nullptr )
        {
          m_nOffset = v5->m_pFirstDir.m_nOffset;
          p_m_pFirstDir = &v5->m_pFirstDir;
          p_m_pNextDir = &v16->m_pNextDir;
          if ( m_nOffset != 0 && (v22 = (char *)p_m_pFirstDir + m_nOffset) != nullptr )
          {
            p_m_pNextDir->m_nOffset = v22 - (char *)p_m_pNextDir;
            p_m_pFirstDir->m_nOffset = (char *)v16 - (char *)p_m_pFirstDir;
          }
          else
          {
            p_m_pNextDir->m_nOffset = 0;
            p_m_pFirstDir->m_nOffset = (char *)v16 - (char *)p_m_pFirstDir;
          }
        }
        else
        {
          pRet->m_pRootDir = v16;
        }
      }
      v11 = v24 + 1;
      v8 = sNext.m_Storage.m_Memory.m_pMemory-- == (unsigned __int8 *)1;
      v5 = Dir;
      ++v24;
    }
    while ( !v8 );
  }
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&dirNames.m_Memory.m_nAllocationCount);
  if ( dirNames.m_Size >= 0 && dirNames.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dirNames.m_Memory.m_nAllocationCount);
  if ( sCur.m_Storage.m_nActualLength >= 0 && sCur.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)sCur.m_Storage.m_Memory.m_nAllocationCount);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00402250
// Name: public: enum GetSnapshotStatus_t COverwatchClient::GetSnapshotForDir(char const __near *,class COverwatchSnapshot __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
GetSnapshotStatus_t __thiscall COverwatchClient::GetSnapshotForDir(
        COverwatchClient *this,
        const char *pDirName,
        CSnapshotInternal **pSnapshot,
        int nFlags)
{
  void *m_hDataMutex; // eax
  CWatchedDir *ChildDir; // eax
  CWatchedDir *v8; // edi
  int v9; // eax
  int v10; // eax
  CSnapshotInternal *v11; // eax
  CSnapshotInternal *v12; // ebx
  unsigned int m_nMemoryBytesLimit; // esi
  void *v14; // eax
  int m_nOffset; // eax
  const char *v16; // eax
  const CUtlString *v17; // eax
  CSnapshotDir *v18; // eax
  CUtlString *p_Handles; // ecx
  const char *v20; // eax
  CSnapshotDir *v21; // esi
  CUtlString Handles; // [esp+4h] [ebp-20h] BYREF
  CUtlString v23; // [esp+14h] [ebp-10h] BYREF

  if ( COverwatchClient::IsConnected(this) != 0 )
  {
    m_hDataMutex = this->m_hDataMutex;
    Handles.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)this->m_hOverwatchServiceProcess;
    Handles.m_Storage.m_Memory.m_nAllocationCount = (int)m_hDataMutex;
    if ( WaitForMultipleObjects(
           nCount: 2u,
           lpHandles: (const HANDLE *)&Handles.m_Storage.m_Memory.m_pMemory,
           bWaitAll: false,
           dwMilliseconds: 0x64u) != 1 )
      return GETSNAPSHOT_ERROR;
    ChildDir = CWatchedDir::FindChildDir(this: &this->m_pOverwatchHeader->m_RootDir, pLongDirName: pDirName);
    v8 = ChildDir;
    if ( ChildDir != nullptr
      && (v9 = ChildDir->m_pWatchedDirectoryRoot.m_nOffset) != 0
      && (v10 = (int)&v8->m_pWatchedDirectoryRoot + v9) != 0 )
    {
      if ( *(_BYTE *)(v10 + 28) != 0 )
      {
        v11 = (CSnapshotInternal *)operator new(nSize: 0x1Cu);
        if ( v11 != nullptr )
          v12 = CSnapshotInternal::CSnapshotInternal(this: v11);
        else
          v12 = nullptr;
        m_nMemoryBytesLimit = this->m_pOverwatchHeader->m_Stats.m_nMemoryBytesLimit;
        v14 = operator new(nSize: m_nMemoryBytesLimit);
        CLinearMemoryAllocator::Init(
          this: &v12->m_Allocator,
          pBase: v14,
          nMaxBytes: m_nMemoryBytesLimit,
          bAutoFree: true);
        m_nOffset = v8->m_pLongName.m_nOffset;
        if ( (nFlags & 1) != 0 )
        {
          if ( m_nOffset != 0 )
            v16 = (char *)&v8->m_pLongName + m_nOffset;
          else
            v16 = nullptr;
          v17 = CUtlString::CUtlString(this: &Handles, pString: v16);
          v18 = FindOrAddDirs(sDirName: v17, pRet: v12);
          p_Handles = &Handles;
        }
        else
        {
          if ( m_nOffset != 0 )
            v20 = (char *)&v8->m_pLongName + m_nOffset;
          else
            v20 = nullptr;
          CUtlString::CUtlString(this: &v23, pString: v20);
          v18 = AddRoot(pRet: v12);
          p_Handles = &v23;
        }
        v21 = v18;
        CUtlString::~CUtlString(this: p_Handles);
        ConvertWatchedDirToSnapshotDir(allocator: &v12->m_Allocator, pFromRoot: v8, pToRoot: v21);
        ReleaseMutex(hMutex: this->m_hDataMutex);
        *pSnapshot = v12;
        return GETSNAPSHOT_OK;
      }
      else
      {
        ReleaseMutex(hMutex: this->m_hDataMutex);
        return GETSNAPSHOT_NOTDONESCANNING;
      }
    }
    else
    {
      ReleaseMutex(hMutex: this->m_hDataMutex);
      return GETSNAPSHOT_ERROR;
    }
  }
  else
  {
    if ( (nFlags & 1) != 0 )
      return GETSNAPSHOT_ERROR;
    return COverwatchClient::GetSlowSnapshotForDir(this, pDirName, pSnapshot, nFlags);
  }
}
