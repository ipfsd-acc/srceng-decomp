// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vwatch/vwatchlib/vwatchclient.cpp
// Functions: 11
// ============================================================

#include "utils\vwatch\vwatchlib\vwatchclient.h"

//------------------------------------------------------------------------------
// Address: 0x00405B50
// Name: public: CVWatchClient::CVWatchClient(void)
// Source: json
//------------------------------------------------------------------------------
CVWatchClient *__thiscall CVWatchClient::CVWatchClient(CVWatchClient *this)
{
  CSharedMemoryMgr *v2; // eax
  CSharedMemoryMgr *v3; // eax
  CSharedMemoryMgr *v4; // eax
  CSharedMemoryMgr *v5; // eax

  this->m_hDataMutex = nullptr;
  v2 = (CSharedMemoryMgr *)operator new(nSize: 0x10u);
  if ( v2 != nullptr )
    v3 = CSharedMemoryMgr::CSharedMemoryMgr(this: v2);
  else
    v3 = nullptr;
  this->m_pSharedMemoryMgr = v3;
  v4 = (CSharedMemoryMgr *)operator new(nSize: 0x10u);
  if ( v4 != nullptr )
    v5 = CSharedMemoryMgr::CSharedMemoryMgr(this: v4);
  else
    v5 = nullptr;
  this->m_pAppSignalMemory = v5;
  this->m_hAppSignalEvent = nullptr;
  this->m_hServiceProcess = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405BB0
// Name: void __near * CreateEventWithNames(char __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
HANDLE __cdecl CreateEventWithNames(char *pOutName, unsigned int nMaxBytes, const char *pBaseName, int nTries)
{
  int v4; // esi
  HANDLE result; // eax
  _SECURITY_DESCRIPTOR sd; // [esp+Ch] [ebp-20h] BYREF
  _SECURITY_ATTRIBUTES sa; // [esp+20h] [ebp-Ch] BYREF

  InitializeSecurityDescriptor(pSecurityDescriptor: &sd, dwRevision: 1u);
  v4 = 0;
  SetSecurityDescriptorDacl(pSecurityDescriptor: &sd, bDaclPresent: true, pDacl: nullptr, bDaclDefaulted: false);
  sa.bInheritHandle = 0;
  sa.lpSecurityDescriptor = &sd;
  sa.nLength = 12;
  if ( nTries <= 0 )
    return nullptr;
  while ( 1 )
  {
    V_snprintf(pDest: pOutName, maxLen: nMaxBytes, pFormat: "%s_%d", pBaseName, v4);
    result = CreateEventA(lpEventAttributes: &sa, bManualReset: false, bInitialState: false, lpName: pOutName);
    if ( result != nullptr )
      break;
    if ( ++v4 >= nTries )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405C30
// Name: public: void CVWatchClient::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchClient::Term(CVWatchClient *this)
{
  if ( this->m_hDataMutex != nullptr )
  {
    CloseHandle(hObject: this->m_hDataMutex);
    this->m_hDataMutex = nullptr;
  }
  if ( this->m_hServiceProcess != nullptr )
  {
    CloseHandle(hObject: this->m_hServiceProcess);
    this->m_hServiceProcess = nullptr;
  }
  CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
}

//------------------------------------------------------------------------------
// Address: 0x00405C70
// Name: public: class CVWatchStats const __near * CVWatchClient::GetStats(void)
// Source: json
//------------------------------------------------------------------------------
const CVWatchStats *__thiscall CVWatchClient::GetStats(CVWatchClient *this)
{
  void *m_hServiceProcess; // eax
  CVWatchStats *m_hDataMutex; // ecx
  void *v4; // edx
  unsigned __int8 *v5; // esi
  HANDLE Handles; // [esp+4h] [ebp-8h] BYREF
  CVWatchStats *p_m_BackedUpVWatchStats; // [esp+8h] [ebp-4h]

  m_hServiceProcess = this->m_hServiceProcess;
  m_hDataMutex = (CVWatchStats *)this->m_hDataMutex;
  Handles = m_hServiceProcess;
  p_m_BackedUpVWatchStats = m_hDataMutex;
  if ( WaitForMultipleObjects(nCount: 2u, lpHandles: &Handles, bWaitAll: false, dwMilliseconds: 0) != 1 )
    return nullptr;
  ++*((_DWORD *)this->m_pSharedMemoryMgr->m_pStart + 16);
  v4 = this->m_hDataMutex;
  v5 = this->m_pSharedMemoryMgr->m_pStart + 4;
  p_m_BackedUpVWatchStats = &this->m_BackedUpVWatchStats;
  qmemcpy(&this->m_BackedUpVWatchStats, v5, sizeof(this->m_BackedUpVWatchStats));
  ReleaseMutex(hMutex: v4);
  return p_m_BackedUpVWatchStats;
}

//------------------------------------------------------------------------------
// Address: 0x00405CE0
// Name: private: class CAppSignal __near * CVWatchClient::StartAppSignal(int)
// Source: json
//------------------------------------------------------------------------------
CAppSignal *__thiscall CVWatchClient::StartAppSignal(CVWatchClient *this, DWORD nTimeout)
{
  unsigned int v3; // eax
  void *m_hDataMutex; // ecx
  unsigned __int8 *m_pStart; // ebx
  DWORD v6; // ecx
  unsigned int v8; // eax
  void *v9; // edx
  int v10; // ecx
  int v11; // edi
  HANDLE Handles; // [esp+8h] [ebp-Ch] BYREF
  void *v13; // [esp+Ch] [ebp-8h]
  unsigned int nStartTime; // [esp+10h] [ebp-4h]

  v3 = _Plat_MSTime();
  m_hDataMutex = this->m_hDataMutex;
  nStartTime = v3;
  Handles = this->m_hServiceProcess;
  v13 = m_hDataMutex;
  if ( WaitForMultipleObjects(nCount: 2u, lpHandles: &Handles, bWaitAll: false, dwMilliseconds: nTimeout) != 1 )
    return nullptr;
  ++*((_DWORD *)this->m_pSharedMemoryMgr->m_pStart + 16);
  m_pStart = this->m_pSharedMemoryMgr->m_pStart;
  if ( *((_DWORD *)m_pStart + 346) < 4u )
  {
LABEL_13:
    v10 = 328 * *((_DWORD *)m_pStart + 346);
    v11 = (int)&m_pStart[v10 + 72];
    ++*((_DWORD *)m_pStart + 346);
    V_strncpy(pDest: (char *)&m_pStart[v10 + 336], pSrc: this->m_AppSignalMemoryName, maxLen: 32);
    V_strncpy(pDest: (char *)(v11 + 296), pSrc: this->m_AppSignalEventName, maxLen: 32);
    return (CAppSignal *)v11;
  }
  else
  {
    while ( 1 )
    {
      ReleaseMutex(hMutex: this->m_hDataMutex);
      _ThreadSleep(a1: 1);
      if ( nTimeout == -1 )
      {
        v6 = -1;
      }
      else
      {
        v8 = _Plat_MSTime() - nStartTime;
        v6 = v8 <= nTimeout ? nTimeout - v8 : 0;
      }
      v9 = this->m_hDataMutex;
      Handles = this->m_hServiceProcess;
      v13 = v9;
      if ( WaitForMultipleObjects(nCount: 2u, lpHandles: &Handles, bWaitAll: false, dwMilliseconds: v6) != 1 )
        return nullptr;
      ++*((_DWORD *)this->m_pSharedMemoryMgr->m_pStart + 16);
      if ( nTimeout != -1 && _Plat_MSTime() - nStartTime >= nTimeout )
        return nullptr;
      if ( *((_DWORD *)m_pStart + 346) < 4u )
        goto LABEL_13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405EA0
// Name: public: CVWatchClient::~CVWatchClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVWatchClient::~CVWatchClient(CVWatchClient *this)
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
// Address: 0x00405EE0
// Name: public: bool CVWatchClient::Connect(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVWatchClient::Connect(CVWatchClient *this, DWORD nTimeout)
{
  unsigned int v3; // edi
  DWORD v4; // ebx
  int v5; // edi
  HANDLE v6; // eax
  unsigned int v7; // eax
  unsigned __int8 *m_pStart; // ebx
  HANDLE v10; // eax
  HANDLE EventWithNames; // eax
  unsigned int nStartTime; // [esp+Ch] [ebp-4h]
  CSharedMemoryMgr *nTimeouta; // [esp+18h] [ebp+8h]

  v3 = 0;
  if ( this->m_hDataMutex != nullptr )
  {
    CloseHandle(hObject: this->m_hDataMutex);
    this->m_hDataMutex = nullptr;
  }
  if ( this->m_hServiceProcess != nullptr )
  {
    CloseHandle(hObject: this->m_hServiceProcess);
    this->m_hServiceProcess = nullptr;
  }
  CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
  nStartTime = _Plat_MSTime();
  v4 = nTimeout;
  if ( !CSharedMemoryMgr::Open(
          this: this->m_pSharedMemoryMgr,
          pSharedName: "Global\\vwatch_shared_data",
          nBytes: 0x6400000u) )
  {
    while ( nTimeout != 0 )
    {
      _ThreadSleep(a1: 20);
      v3 += 20;
      if ( v3 > nTimeout )
        break;
      if ( CSharedMemoryMgr::Open(
             this: this->m_pSharedMemoryMgr,
             pSharedName: "Global\\vwatch_shared_data",
             nBytes: 0x6400000u) )
      {
        goto LABEL_9;
      }
    }
    return 0;
  }
LABEL_9:
  v5 = 0;
  v6 = OpenMutexA(dwDesiredAccess: 0x100000u, bInheritHandle: false, lpName: "Global\\vwatch_mutex");
  this->m_hDataMutex = v6;
  if ( v6 != nullptr )
  {
    if ( nTimeout != -1 )
    {
      v7 = _Plat_MSTime() - nStartTime;
      if ( v7 <= nTimeout )
        v4 = nTimeout - v7;
      else
        v4 = 0;
    }
    if ( WaitForSingleObject(hHandle: this->m_hDataMutex, dwMilliseconds: v4) == 0 )
    {
      ReleaseMutex(hMutex: this->m_hDataMutex);
      m_pStart = this->m_pSharedMemoryMgr->m_pStart;
      if ( *(_DWORD *)m_pStart != 2 )
      {
        _Warning(a1: "Invalid vwatch protocol version number (%lu)\n");
LABEL_17:
        CVWatchClient::Term(this);
        return 0;
      }
      v10 = OpenProcess(dwDesiredAccess: 0x100000u, bInheritHandle: false, dwProcessId: *((_DWORD *)m_pStart + 17));
      this->m_hServiceProcess = v10;
      if ( v10 == nullptr )
      {
        _Warning(a1: "Can't get vwatch process handle from id %lu\n");
        goto LABEL_17;
      }
      nTimeouta = this->m_pAppSignalMemory;
      while ( 1 )
      {
        V_snprintf(pDest: this->m_AppSignalMemoryName, maxLen: 0x20u, pFormat: "%s_%d", "Global\\ow_signal_", v5);
        if ( CSharedMemoryMgr::Create(this: nTimeouta, pSharedName: this->m_AppSignalMemoryName, nBytes: 0x400u) )
          break;
        if ( ++v5 >= 2000 )
        {
          _Warning(a1: "Can't create AppSignal shared memory.\n");
          CVWatchClient::Term(this);
          return 0;
        }
      }
      EventWithNames = CreateEventWithNames(
                         pOutName: this->m_AppSignalEventName,
                         nMaxBytes: 0x20u,
                         pBaseName: "Global\\ow_signal_event_",
                         nTries: 2000);
      this->m_hAppSignalEvent = EventWithNames;
      if ( EventWithNames != nullptr )
        return 1;
      _Warning(a1: "Can't create AppSignal event.\n");
      CVWatchClient::Term(this);
      return 0;
    }
  }
  if ( this->m_hDataMutex != nullptr )
  {
    CloseHandle(hObject: this->m_hDataMutex);
    this->m_hDataMutex = nullptr;
  }
  if ( this->m_hServiceProcess != nullptr )
  {
    CloseHandle(hObject: this->m_hServiceProcess);
    this->m_hServiceProcess = nullptr;
  }
  CSharedMemoryMgr::~CSharedMemoryMgr(this: this->m_pSharedMemoryMgr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406100
// Name: public: bool CVWatchClient::SendRestartSignal(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVWatchClient::SendRestartSignal(CVWatchClient *this)
{
  int v2; // ebx
  CAppSignal *started; // eax
  unsigned int v5; // eax
  DWORD v6; // ecx
  void *m_hAppSignalEvent; // eax
  HANDLE Handles[2]; // [esp+Ch] [ebp-8h] BYREF

  v2 = _Plat_MSTime();
  started = CVWatchClient::StartAppSignal(this, nTimeout: 0x64u);
  if ( started == nullptr )
    return 0;
  started->m_eSignalType = APPSIGNAL_RESTART;
  ReleaseMutex(hMutex: this->m_hDataMutex);
  v5 = _Plat_MSTime() - v2;
  if ( v5 <= 0x64 )
    v6 = 100 - v5;
  else
    v6 = 0;
  m_hAppSignalEvent = this->m_hAppSignalEvent;
  Handles[0] = this->m_hServiceProcess;
  Handles[1] = m_hAppSignalEvent;
  WaitForMultipleObjects(nCount: 2u, lpHandles: Handles, bWaitAll: false, dwMilliseconds: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406180
// Name: public: enum StartWatchingDirStatus_t CVWatchClient::StartWatchingDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVWatchClient::StartWatchingDir(CVWatchClient *this, char *pDirName)
{
  int v3; // ebx
  CAppSignal *started; // eax
  unsigned int v6; // eax
  DWORD v7; // ecx
  void *m_hAppSignalEvent; // edx
  HANDLE Handles[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = _Plat_MSTime();
  started = CVWatchClient::StartAppSignal(this, nTimeout: 0x64u);
  if ( started == nullptr )
    return 2;
  started->m_eSignalType = APPSIGNAL_ADD_DIRECTORY;
  V_strncpy(pDest: started->m_SignalData, pSrc: pDirName, maxLen: 260);
  ReleaseMutex(hMutex: this->m_hDataMutex);
  v6 = _Plat_MSTime() - v3;
  v7 = v6 <= 0x64 ? 100 - v6 : 0;
  m_hAppSignalEvent = this->m_hAppSignalEvent;
  Handles[0] = this->m_hServiceProcess;
  Handles[1] = m_hAppSignalEvent;
  if ( WaitForMultipleObjects(nCount: 2u, lpHandles: Handles, bWaitAll: false, dwMilliseconds: v7) == 1 )
    return *(_DWORD *)this->m_pAppSignalMemory->m_pStart != 1;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00406230
// Name: public: bool CVWatchClient::StopWatchingDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVWatchClient::StopWatchingDir(CVWatchClient *this, char *pDirName)
{
  int v3; // ebx
  CAppSignal *started; // eax
  unsigned int v6; // eax
  DWORD v7; // ecx
  void *m_hAppSignalEvent; // edx
  HANDLE Handles[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = _Plat_MSTime();
  started = CVWatchClient::StartAppSignal(this, nTimeout: 0x64u);
  if ( started == nullptr )
    return false;
  started->m_eSignalType = APPSIGNAL_REMOVE_DIRECTORY;
  V_strncpy(pDest: started->m_SignalData, pSrc: pDirName, maxLen: 260);
  ReleaseMutex(hMutex: this->m_hDataMutex);
  v6 = _Plat_MSTime() - v3;
  v7 = v6 <= 0x64 ? 100 - v6 : 0;
  m_hAppSignalEvent = this->m_hAppSignalEvent;
  Handles[0] = this->m_hServiceProcess;
  Handles[1] = m_hAppSignalEvent;
  return WaitForMultipleObjects(nCount: 2u, lpHandles: Handles, bWaitAll: false, dwMilliseconds: v7) == 1
      && *(_DWORD *)this->m_pAppSignalMemory->m_pStart != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004062E0
// Name: public: bool CVWatchClient::GetWatchedDirectories(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVWatchClient::GetWatchedDirectories(
        CVWatchClient *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirs)
{
  CVWatchClient *v2; // edi
  int m_hDataMutex; // eax
  _DWORD *v4; // eax
  char *i; // ebx
  int v6; // eax
  char *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v12; // eax
  CUtlString *v13; // edi
  int v14; // eax
  CUtlString string; // [esp+8h] [ebp-14h] BYREF
  CVWatchClient *v16; // [esp+18h] [ebp-4h]

  v2 = this;
  v16 = this;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: dirs);
  if ( dirs->m_Memory.m_nGrowSize >= 0 )
  {
    if ( dirs->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirs->m_Memory.m_pMemory);
      dirs->m_Memory.m_pMemory = nullptr;
    }
    dirs->m_Memory.m_nAllocationCount = 0;
  }
  dirs->m_pElements = dirs->m_Memory.m_pMemory;
  m_hDataMutex = (int)v2->m_hDataMutex;
  string.m_Storage.m_Memory.m_nGrowSize = (int)v2->m_hServiceProcess;
  string.m_Storage.m_nActualLength = m_hDataMutex;
  if ( WaitForMultipleObjects(
         nCount: 2u,
         lpHandles: (const HANDLE *)&string.m_Storage.m_Memory.m_nGrowSize,
         bWaitAll: false,
         dwMilliseconds: 0x32u) != 1 )
    return 0;
  ++*((_DWORD *)v2->m_pSharedMemoryMgr->m_pStart + 16);
  v4 = v2->m_pSharedMemoryMgr->m_pStart + 1388;
  if ( *v4 != 0 )
  {
    for ( i = (char *)v4 + *v4; i != nullptr; i += v14 + 32 )
    {
      if ( i[28] != 0 )
      {
        v6 = *((_DWORD *)i + 6);
        if ( v6 != 0 )
          v7 = &i[v6 + 24];
        else
          v7 = nullptr;
        CUtlString::CUtlString(this: &string, pString: v7);
        m_Size = dirs->m_Size;
        m_nAllocationCount = dirs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CUtlString,int>::Grow(this: &dirs->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++dirs->m_Size;
        m_pMemory = dirs->m_Memory.m_pMemory;
        v12 = dirs->m_Size - m_Size - 1;
        dirs->m_pElements = dirs->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v12);
        v13 = &dirs->m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          CUtlString::CUtlString(this: v13, &string);
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
        v2 = v16;
      }
      v14 = *((_DWORD *)i + 8);
      if ( v14 == 0 )
        break;
    }
  }
  ReleaseMutex(hMutex: v2->m_hDataMutex);
  return 1;
}
