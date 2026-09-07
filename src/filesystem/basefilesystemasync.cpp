// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: filesystem/basefilesystemasync.cpp
// Functions: 135
// ============================================================

#include "filesystem\basefilesystemasync.h"

//------------------------------------------------------------------------------
// Address: 0x100056F0
// Name: public: virtual bool CFileAsyncAppendFileJob::IsWrite(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileAsyncAppendFileJob::IsWrite(ConCommand *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010260
// Name: public: virtual void (*CBaseFileSystem::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CBaseFileSystem::GetDirtyDiskReportFunc(CBaseFileSystem *this))()
{
  return this->m_DirtyDiskReportFunc;
}

//------------------------------------------------------------------------------
// Address: 0x10011340
// Name: async_suspend
// Source: json
//------------------------------------------------------------------------------
void __cdecl async_suspend()
{
  CBaseFileSystem *v0; // eax

  v0 = BaseFileSystem();
  v0->AsyncSuspend(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10011360
// Name: async_resume
// Source: json
//------------------------------------------------------------------------------
void __cdecl async_resume()
{
  CBaseFileSystem *v0; // eax

  v0 = BaseFileSystem();
  v0->AsyncResume(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10011380
// Name: public: static void CFileAsyncReadJob::InterceptCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFileAsyncReadJob::InterceptCallback(
        const FileAsyncRequest_t *request,
        int nBytesRead,
        FSAsyncStatus_t result)
{
  void *pContext; // eax
  void (__cdecl *v4)(const FileAsyncRequest_t *, int, FSAsyncStatus_t); // edx

  pContext = request->pContext;
  if ( result == FSASYNC_OK && (request->flags & 2) == 0 )
  {
    *((_DWORD *)pContext + 23) = request->pData;
    *((_DWORD *)pContext + 24) = nBytesRead;
  }
  v4 = *((void (__cdecl **)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))pContext + 26);
  if ( v4 != nullptr )
  {
    request->pfnCallback = v4;
    request->pContext = *((void **)pContext + 25);
    (*((void (__cdecl **)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))pContext + 26))(
      a1: request,
      a2: nBytesRead,
      a3: result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100113D0
// Name: public: virtual int CFileAsyncDirectoryScanJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncDirectoryScanJob::DoExecute(CFileAsyncDirectoryScanJob *this)
{
  char *m_SearchSpec; // ebx
  char *m_CurPath; // edi
  char *i; // eax
  int findSession; // [esp+Ch] [ebp-4h] BYREF

  m_SearchSpec = this->m_SearchSpec;
  m_CurPath = this->m_CurPath;
  findSession = -1;
  _V_strcpy(dest: this->m_CurPath, src: this->m_SearchSpec);
  V_StripFilename(path: m_CurPath);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: m_SearchSpec, a3: &findSession);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findSession) )
  {
    this->m_pAddResultCallback(a1: this->m_pContext, a2: m_CurPath, a3: i);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findSession);
  this->m_pCompletionCallback(a1: this->m_pContext, a2: FSASYNC_OK);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011460
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncReadMultiple(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **phControls)
{
  return this->AsyncReadMultipleCreditAlloc(this, a2: pRequests, a3: nRequests, a4: nullptr, a5: 0, a6: phControls);
}

//------------------------------------------------------------------------------
// Address: 0x10011490
// Name: AsyncWriteJobFilter
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AsyncWriteJobFilter(CJob *pJob)
{
  void *v1; // eax

  v1 = __RTDynamicCast(
         inptr: pJob,
         VfDelta: 0,
         SrcType: &CJob `RTTI Type Descriptor',
         TargetType: &CFileAsyncJob `RTTI Type Descriptor',
         isReference: 0);
  return v1 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v1 + 28))(a1: v1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100114D0
// Name: public: virtual bool CBaseFileSystem::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFileSystem::AsyncSuspend(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->SuspendExecution(this: this->m_pThreadPool);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100114F0
// Name: public: virtual bool CBaseFileSystem::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFileSystem::AsyncResume(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->ResumeExecution(this: this->m_pThreadPool);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011510
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncGetResult(
        CBaseFileSystem *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  int v5; // eax

  if ( ppData != nullptr )
    *ppData = nullptr;
  if ( pSize != nullptr )
    *pSize = 0;
  if ( hControl == nullptr )
    return FSASYNC_ERR_FAILURE;
  v5 = *((_DWORD *)hControl + 3);
  if ( v5 == 1 || v5 == 2 || v5 == 4 )
    return FSASYNC_STATUS_PENDING;
  else
    return (*(FSAsyncStatus_t (__stdcall **)(void **, int *))(*(_DWORD *)hControl + 24))(a1: ppData, a2: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x10011570
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncStatus(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncStatus(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    return *((_DWORD *)hControl + 3);
  else
    return -5;
}

//------------------------------------------------------------------------------
// Address: 0x10011590
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncFlush(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncFlush(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->AbortAll(this: this->m_pThreadPool);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100115B0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncSetPriority(struct FSAsyncControl_t__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncSetPriority(CBaseFileSystem *this, FSAsyncControl_t__ *hControl, int newPriority)
{
  JobPriority_t v4; // eax

  if ( this->m_pThreadPool != nullptr )
  {
    if ( hControl == nullptr )
      return -5;
    if ( newPriority != 0 )
      v4 = newPriority <= 0 ? JP_LOW : JP_HIGH;
    else
      v4 = JP_NORMAL;
    if ( v4 != *((_DWORD *)hControl + 4) )
      this->m_pThreadPool->ChangePriority(this: this->m_pThreadPool, a2: (CJob *)hControl, a3: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011610
// Name: public: virtual void CBaseFileSystem::AsyncAddRef(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncAddRef(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    (**(void (__thiscall ***)(FSAsyncControl_t__ *))hControl)(a1: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10011630
// Name: public: virtual void CBaseFileSystem::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncRelease(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    (*(void (__thiscall **)(FSAsyncControl_t__ *))(*(_DWORD *)hControl + 4))(a1: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10011650
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncWrite(char const __near *,void const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::SyncWrite(
        CBaseFileSystem *this,
        const char *pszFilename,
        void *pSrc,
        int nSrcBytes,
        bool bFreeMemory,
        bool bAppend)
{
  const char *v7; // eax
  void *v8; // ebx

  v7 = "ab+";
  if ( !bAppend )
    v7 = "wb";
  v8 = this->OpenEx(this, a2: pszFilename, a3: v7, a4: 0, a5: 0, a6: 0);
  if ( v8 == nullptr )
    return -1;
  this->SetBufferSize(this, a2: v8, a3: 0);
  this->Write(this: &this->IBaseFileSystem, a2: pSrc, a3: nSrcBytes, a4: v8);
  this->Close(this: &this->IBaseFileSystem, a2: v8);
  if ( bFreeMemory )
    free(pMem: pSrc);
  if ( this->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this, accesstype: "asyncwrite", fullpath: pszFilename, options: setName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011700
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncAppendFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::SyncAppendFile(
        CBaseFileSystem *this,
        const char *pAppendToFileName,
        char *pAppendFromFileName)
{
  CBaseFileSystem *v3; // ebx
  int v4; // esi
  int v5; // edi
  int v6; // edi
  IBaseFileSystem *v7; // esi
  int v8; // edi
  int v9; // ebx
  FSAsyncStatus_t v12; // [esp+10h] [ebp-Ch]
  void *hDestFile; // [esp+14h] [ebp-8h]
  void *hSourceFile; // [esp+18h] [ebp-4h]
  char *buf; // [esp+28h] [ebp+Ch]

  v3 = this;
  v4 = ((int (__stdcall *)(const char *, const char *, _DWORD, _DWORD, _DWORD))this->OpenEx)(
         a1: pAppendToFileName,
         a2: "ab+",
         a3: 0,
         a4: 0,
         a5: 0);
  v5 = -5;
  hDestFile = (void *)v4;
  v12 = FSASYNC_ERR_FAILURE;
  if ( v4 != 0 )
  {
    v3->SetBufferSize(this: v3, a2: (void *)v4, a3: 0);
    v6 = (int)v3->OpenEx(this: v3, a2: pAppendFromFileName, a3: "rb", a4: 0, a5: nullptr, a6: nullptr);
    hSourceFile = (void *)v6;
    if ( v6 != 0 )
    {
      v3->SetBufferSize(this: v3, a2: (void *)v6, a3: 0);
      v7 = &v3->IBaseFileSystem;
      v8 = v3->Size_2(this: &v3->IBaseFileSystem, a2: (void *)v6);
      buf = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x20000);
      if ( v8 > 0 )
      {
        do
        {
          v9 = 0x20000;
          if ( v8 <= 0x20000 )
            v9 = v8;
          v7->Read(this: v7, a2: buf, a3: v9, a4: hSourceFile);
          v7->Write(this: v7, a2: buf, a3: v9, a4: hDestFile);
          v8 -= v9;
        }
        while ( v8 > 0 );
        v3 = this;
      }
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
      v7->Close(this: v7, a2: hSourceFile);
      v4 = (int)hDestFile;
      v12 = FSASYNC_OK;
    }
    v3->Close(this: &v3->IBaseFileSystem, a2: (void *)v4);
    v5 = v12;
  }
  if ( v3->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this: v3, accesstype: "asyncappend", fullpath: pAppendToFileName, options: setName);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10011850
// Name: public: int CJob::Execute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Execute(CJob *this)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int (__thiscall *DoExecute)(CJob *); // edx
  int v6; // eax
  int m_status; // ebx

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        DoExecute = this->DoExecute;
        this->m_status = 2;
        v6 = DoExecute(this);
        this->m_status = v6;
        m_status = v6;
        this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011920
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100119F0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10011A00
// Name: public: virtual int CFileAsyncJob::GetResult(void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncJob::GetResult(CFileAsyncJob *this, void **ppData, int *pSize)
{
  *ppData = nullptr;
  *pSize = 0;
  return this->m_status;
}

//------------------------------------------------------------------------------
// Address: 0x10011A20
// Name: public: virtual char const __near * CFileAsyncWriteJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileAsyncWriteJob::Describe(CFileAsyncWriteJob *this)
{
  return this->m_pszFilename;
}

//------------------------------------------------------------------------------
// Address: 0x10011A30
// Name: public: virtual void CFileAsyncWriteJob::DoCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileAsyncWriteJob::DoCleanup(CFileAsyncWriteJob *this)
{
  if ( this->m_pData != nullptr && this->m_bFreeMemory )
    free(pMem: (void *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10011A60
// Name: public: virtual int CFileAsyncWriteJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncWriteJob::DoExecute(CFileAsyncWriteJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  CBaseFileSystem *v5; // eax
  const char *m_pszFilename; // [esp-14h] [ebp-18h]
  void *m_pData; // [esp-10h] [ebp-14h]
  int m_nBytes; // [esp-Ch] [ebp-10h]
  bool m_bAppend; // [esp-4h] [ebp-8h]

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  m_bAppend = this->m_bAppend;
  m_nBytes = this->m_nBytes;
  m_pData = (void *)this->m_pData;
  m_pszFilename = this->m_pszFilename;
  v5 = BaseFileSystem();
  return CBaseFileSystem::SyncWrite(
           this: v5,
           pszFilename: m_pszFilename,
           pSrc: m_pData,
           nSrcBytes: m_nBytes,
           bFreeMemory: false,
           bAppend: m_bAppend);
}

//------------------------------------------------------------------------------
// Address: 0x10011B30
// Name: public: void CBaseFileSystem::ShutdownAsync(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::ShutdownAsync(CBaseFileSystem *this)
{
  IThreadPool *m_pThreadPool; // ecx

  if ( this->m_pThreadPool != nullptr )
  {
    this->AsyncFlush(this);
    this->m_pThreadPool->Stop(this: this->m_pThreadPool, a2: -1);
    m_pThreadPool = this->m_pThreadPool;
    if ( m_pThreadPool != nullptr )
    {
      m_pThreadPool->Release(this: m_pThreadPool);
      this->m_pThreadPool = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011B80
// Name: public: virtual void CBaseFileSystem::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncFinishAll(CBaseFileSystem *this, int iToPriority)
{
  JobPriority_t v3; // eax

  if ( this->m_pThreadPool != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
    if ( iToPriority != 0 )
      v3 = iToPriority <= 0 ? JP_LOW : JP_HIGH;
    else
      v3 = JP_NORMAL;
    this->m_pThreadPool->ExecuteToPriority(this: this->m_pThreadPool, a2: v3, a3: nullptr);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011BE0
// Name: public: virtual void CBaseFileSystem::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncFinishAllWrites(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr && g_nAsyncWriteJobs != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
    this->m_pThreadPool->ExecuteToPriority(
      this: this->m_pThreadPool,
      a2: JP_LOW,
      a3: (bool (__cdecl *)(CJob *))AsyncWriteJobFilter);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011C30
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncFinish(CBaseFileSystem *this, FSAsyncControl_t__ *hControl, bool wait)
{
  if ( wait )
  {
    if ( hControl != nullptr )
      return CJob::Execute(this: (CJob *)hControl);
    else
      return -5;
  }
  else
  {
    this->AsyncSetPriority(this, a2: hControl, a3: 0x7FFFFFFF);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011C70
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncAbort(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    return CJob::Abort(this: (CJob *)hControl, bDiscard: true);
  else
    return -5;
}

//------------------------------------------------------------------------------
// Address: 0x10011C90
// Name: public: void CBaseFileSystem::DoAsyncCallback(struct FileAsyncRequest_t const __near &,void __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::DoAsyncCallback(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *request,
        void *pData,
        int nBytesRead,
        FSAsyncStatus_t result)
{
  bool v5; // zf
  CThreadFastMutex *p_m_AsyncCallbackMutex; // edi
  DWORD CurrentThreadId; // ecx
  void *v8; // ebx
  void *(__cdecl *pfnAlloc)(const char *, unsigned int); // eax
  __int64 v10; // xmm0_8
  FileAsyncRequest_t temp; // [esp+4h] [ebp-30h] BYREF
  void *pDataToFree; // [esp+30h] [ebp-4h]

  v5 = request->pfnCallback == nullptr;
  pDataToFree = nullptr;
  if ( v5 )
    return;
  p_m_AsyncCallbackMutex = &this->m_AsyncCallbackMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncCallbackMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncCallbackMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncCallbackMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncCallbackMutex->m_depth;
  }
  v8 = pData;
  if ( pData == nullptr || request->pData == pData )
  {
    request->pfnCallback(a1: request, a2: nBytesRead, a3: result);
    if ( (request->flags & 2) != 0 )
    {
      v8 = request->pData;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  pfnAlloc = request->pfnAlloc;
  *(_QWORD *)&temp.pszFilename = *(_QWORD *)&request->pszFilename;
  *(_QWORD *)&temp.nOffset = *(_QWORD *)&request->nOffset;
  *(_QWORD *)&temp.pfnCallback = *(_QWORD *)&request->pfnCallback;
  v10 = *(_QWORD *)&request->priority;
  temp.pfnAlloc = pfnAlloc;
  *(_QWORD *)&temp.priority = v10;
  *(_QWORD *)&temp.pszPathID = *(_QWORD *)&request->pszPathID;
  temp.pData = pData;
  temp.pfnCallback(a1: &temp, a2: nBytesRead, a3: result);
  if ( (request->flags & 1) != 0 )
LABEL_9:
    v8 = pDataToFree;
LABEL_10:
  v5 = p_m_AsyncCallbackMutex->m_depth-- == 1;
  if ( v5 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncCallbackMutex, 0);
  if ( v8 != nullptr )
    free(pMem: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10011E30
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x10011E80
// Name: public: CFileAsyncWriteJob::CFileAsyncWriteJob(char const __near *,void const __near *,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncWriteJob *__thiscall CFileAsyncWriteJob::CFileAsyncWriteJob(
        CFileAsyncWriteJob *this,
        const char *pszFilename,
        const void *pData,
        unsigned int nBytes,
        bool bFreeMemory,
        bool bAppend)
{
  const char *v7; // ebx
  char *v8; // eax

  this->m_iRefs = 1;
  v7 = nullptr;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_LOW;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->m_bFreeMemory = bFreeMemory;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CFileAsyncWriteJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncWriteJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pData = pData;
  this->m_nBytes = nBytes;
  this->m_bAppend = bAppend;
  if ( pszFilename != nullptr )
  {
    v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszFilename) + 1);
    if ( v8 != nullptr )
    {
      strcpy(v8, pszFilename);
      v7 = v8;
    }
  }
  ++g_nAsyncWriteJobs;
  this->m_flags |= 4u;
  this->m_pszFilename = v7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011F50
// Name: public: CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncAppendFileJob *__thiscall CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(
        CFileAsyncAppendFileJob *this,
        const char *pszAppendTo,
        const char *pszAppendFrom)
{
  char *v4; // eax
  char *v5; // eax
  char *m_pszAppendTo; // [esp-8h] [ebp-14h]

  this->m_iRefs = 1;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncAppendFileJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_LOW;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncAppendFileJob_vtbl *)&CFileAsyncAppendFileJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncAppendFileJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  if ( pszAppendTo != nullptr
    && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszAppendTo) + 1)) != nullptr )
  {
    strcpy(v4, pszAppendTo);
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pszAppendTo = v4;
  if ( pszAppendFrom != nullptr
    && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszAppendFrom) + 1)) != nullptr )
  {
    strcpy(v5, pszAppendFrom);
  }
  else
  {
    v5 = nullptr;
  }
  m_pszAppendTo = (char *)this->m_pszAppendTo;
  this->m_pszAppendFrom = v5;
  V_FixSlashes(pname: m_pszAppendTo, separator: 92);
  V_FixSlashes(pname: (char *)this->m_pszAppendFrom, separator: 92);
  ++g_nAsyncWriteJobs;
  this->m_flags |= 4u;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012080
// Name: public: virtual int CFileAsyncAppendFileJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncAppendFileJob::DoExecute(CFileAsyncAppendFileJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  CBaseFileSystem *v5; // eax
  const char *m_pszAppendTo; // [esp-8h] [ebp-Ch]
  char *m_pszAppendFrom; // [esp-4h] [ebp-8h]

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  m_pszAppendFrom = (char *)this->m_pszAppendFrom;
  m_pszAppendTo = this->m_pszAppendTo;
  v5 = BaseFileSystem();
  return CBaseFileSystem::SyncAppendFile(
           this: v5,
           pAppendToFileName: m_pszAppendTo,
           pAppendFromFileName: m_pszAppendFrom);
}

//------------------------------------------------------------------------------
// Address: 0x10012140
// Name: public: CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t))
// Source: json
//------------------------------------------------------------------------------
CFileAsyncDirectoryScanJob *__thiscall CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(
        CFileAsyncDirectoryScanJob *this,
        const char *pSearchSpec,
        bool bRecurseDirs,
        void *pContext,
        void (__cdecl *pAddCallback)(void *, char *, char *),
        void (__cdecl *pDoneCallback)(void *, FSAsyncStatus_t))
{
  this->m_iRefs = 1;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncDirectoryScanJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_NORMAL;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_flags = 0;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->m_pCompletionCallback = pDoneCallback;
  this->m_bRecurse = bRecurseDirs;
  this->m_pAddResultCallback = pAddCallback;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncDirectoryScanJob_vtbl *)&CFileAsyncDirectoryScanJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncDirectoryScanJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pContext = pContext;
  _V_strcpy(dest: this->m_SearchSpec, src: pSearchSpec);
  _V_memset(dest: this->m_CurPath, fill: 0, count: 260);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100121E0
// Name: public: virtual char const __near * CFileAsyncDirectoryScanJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileAsyncDirectoryScanJob::Describe(CFileAsyncDirectoryScanJob *this)
{
  return this->m_SearchSpec;
}

//------------------------------------------------------------------------------
// Address: 0x10012250
// Name: public: void CBaseFileSystem::InitAsync(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseFileSystem::InitAsync(CBaseFileSystem *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  IThreadPool *NewThreadPool; // eax
  char v5; // cl
  IThreadPool *m_pThreadPool; // ecx
  ThreadPoolStartParams_t params; // [esp+4h] [ebp-114h] BYREF

  if ( this->m_pThreadPool == nullptr )
  {
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-noasync") != 0 )
    {
      _Msg(a1: "Async I/O disabled from command line\n");
    }
    else
    {
      NewThreadPool = (IThreadPool *)_CreateNewThreadPool(a1: a2);
      params.nThreads = -1;
      params.nStackSize = -1;
      v5 = *((_BYTE *)&params + 272) & 0xFC;
      this->m_pThreadPool = NewThreadPool;
      params.fDistribute = TRS_NONE;
      *((_BYTE *)&params + 272) = v5;
      if ( (v5 & 2) != 0 )
        qmemcpy(params.iAffinityTable, nullptr, sizeof(params.iAffinityTable));
      *((_BYTE *)&params + 272) |= 1u;
      params.iThreadPriority = 0;
      if ( !NewThreadPool->Start_2(this: NewThreadPool, a2: &params) )
      {
        m_pThreadPool = this->m_pThreadPool;
        if ( m_pThreadPool != nullptr )
        {
          m_pThreadPool->Release(this: m_pThreadPool);
          this->m_pThreadPool = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012320
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncWrite(
        CBaseFileSystem *this,
        const char *pFileName,
        const void *pSrc,
        unsigned int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncWriteJob *v11; // eax
  CFileAsyncWriteJob *v12; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncWriteJob *)operator new(nSize: 0x44u);
  if ( v11 != nullptr )
    v12 = CFileAsyncWriteJob::CFileAsyncWriteJob(
            this: v11,
            pszFilename: pFileName,
            pData: pSrc,
            nBytes: nSrcBytes,
            bFreeMemory,
            bAppend);
  else
    v12 = nullptr;
  if ( v10 )
    CJob::Execute(this: v12);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: v12);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v12;
  else
    v12->Release(this: v12);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100123E0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncWriteFile(
        CBaseFileSystem *this,
        const char *pFileName,
        CFileAsyncWriteJob_vtbl *pBuff,
        unsigned int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  CBaseFileSystem *v7; // edi
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncWriteJob *v11; // esi

  v7 = this;
  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncWriteJob *)operator new(nSize: 0x48u);
  if ( v11 != nullptr )
  {
    CFileAsyncWriteJob::CFileAsyncWriteJob(
      this: v11,
      pszFilename: pFileName,
      pData: pBuff->AddRef,
      nBytes: nSrcBytes,
      bFreeMemory,
      bAppend);
    v11[1].CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = pBuff;
    v7 = this;
    v11->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CFileAsyncWriteFileJob::`vftable'{for `IRefCounted'};
    v11->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncWriteFileJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  }
  else
  {
    v11 = nullptr;
  }
  if ( v10 )
    CJob::Execute(this: v11);
  else
    v7->m_pThreadPool->AddJob(this: v7->m_pThreadPool, a2: v11);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v11;
  else
    v11->Release(this: v11);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100124B0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncAppendFile(
        CBaseFileSystem *this,
        const char *pAppendToFileName,
        const char *pAppendFromFileName,
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v6; // al
  bool v7; // bl
  CFileAsyncAppendFileJob *v8; // eax
  CFileAsyncAppendFileJob *appended; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v6 = m_nValue == 0;
  v7 = !v6 || this->m_pThreadPool == nullptr;
  if ( !v6 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v8 = (CFileAsyncAppendFileJob *)operator new(nSize: 0x38u);
  if ( v8 != nullptr )
    appended = CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(
                 this: v8,
                 pszAppendTo: pAppendToFileName,
                 pszAppendFrom: pAppendFromFileName);
  else
    appended = nullptr;
  if ( v7 )
    CJob::Execute(this: appended);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: appended);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)appended;
  else
    appended->Release(this: appended);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10012560
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncDirectoryScan(
        CBaseFileSystem *this,
        const char *pSearchSpec,
        bool recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncDirectoryScanJob *v11; // eax
  CFileAsyncDirectoryScanJob *v12; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncDirectoryScanJob *)operator new(nSize: 0x248u);
  if ( v11 != nullptr )
    v12 = CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(
            this: v11,
            pSearchSpec,
            bRecurseDirs: recurseFolders,
            pContext,
            pAddCallback: pfnAdd,
            pDoneCallback: pfnDone);
  else
    v12 = nullptr;
  if ( v10 )
    CJob::Execute(this: v12);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: v12);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v12;
  else
    v12->Release(this: v12);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10012A40
// Name: public: struct AsyncOpenedFile_t __near * CAsyncOpenedFiles::Get(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncOpenedFile_t *__thiscall CAsyncOpenedFiles::Get(CAsyncOpenedFiles *this, FSAsyncFile_t__ *item)
{
  AsyncOpenedFile_t *result; // eax
  DWORD CurrentThreadId; // ecx

  if ( item == (FSAsyncFile_t__ *)0xFFFF )
    return nullptr;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->m_iRefs, 1u);
  result = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012AC0
// Name: public: void CAsyncOpenedFiles::AddRef(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncOpenedFiles::AddRef(CAsyncOpenedFiles *this, FSAsyncFile_t__ *item)
{
  DWORD CurrentThreadId; // ecx

  if ( item != (FSAsyncFile_t__ *)0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->m_iRefs, 1u);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012B30
// Name: public: CFileAsyncReadJob::CFileAsyncReadJob(struct FileAsyncRequest_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncReadJob *__thiscall CFileAsyncReadJob::CFileAsyncReadJob(
        CFileAsyncReadJob *this,
        const FileAsyncRequest_t *fromRequest)
{
  int priority; // eax
  char *v3; // ebx
  JobPriority_t v5; // eax
  const char *pszFilename; // edi
  const FileAsyncRequest_t *v7; // eax
  const char *v8; // ecx
  int v9; // eax
  char v10; // dl
  FSAsyncFile_t__ *hSpecificAsyncFile; // eax
  const FileAsyncRequest_t *fromRequesta; // [esp+14h] [ebp+8h]

  priority = fromRequest->priority;
  v3 = nullptr;
  if ( priority != 0 )
    v5 = priority <= 0 ? JP_LOW : JP_HIGH;
  else
    v5 = JP_NORMAL;
  this->m_iRefs = 1;
  this->m_priority = v5;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->FileAsyncRequest_t = *fromRequest;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncReadJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncReadJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pResultData = nullptr;
  this->m_nResultSize = 0;
  this->m_pRealContext = fromRequest->pContext;
  this->m_pfnRealCallback = fromRequest->pfnCallback;
  pszFilename = fromRequest->pszFilename;
  if ( fromRequest->pszFilename != nullptr )
  {
    v7 = (const FileAsyncRequest_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszFilename) + 1);
    fromRequesta = v7;
    if ( v7 != nullptr )
    {
      v8 = pszFilename;
      v9 = (char *)v7 - pszFilename;
      do
      {
        v10 = *v8;
        v8[v9] = *v8;
        ++v8;
      }
      while ( v10 != 0 );
      v3 = (char *)fromRequesta;
    }
  }
  this->pszFilename = v3;
  V_FixSlashes(pname: v3, separator: 92);
  hSpecificAsyncFile = this->hSpecificAsyncFile;
  this->pContext = this;
  this->pfnCallback = CFileAsyncReadJob::InterceptCallback;
  if ( hSpecificAsyncFile != (FSAsyncFile_t__ *)0xFFFF )
    CAsyncOpenedFiles::AddRef(this: &g_AsyncOpenedFiles, item: hSpecificAsyncFile);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012C80
// Name: public: virtual char const __near * CFileAsyncReadJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileAsyncReadJob::Describe(CFileAsyncReadJob *this)
{
  return this->pszFilename;
}

//------------------------------------------------------------------------------
// Address: 0x10012C90
// Name: public: virtual int CFileAsyncReadJob::GetResult(void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncReadJob::GetResult(CFileAsyncReadJob *this, void **ppData, int *pSize)
{
  void *m_pResultData; // eax

  m_pResultData = this->m_pResultData;
  if ( m_pResultData != nullptr )
  {
    *ppData = m_pResultData;
    *pSize = this->m_nResultSize;
  }
  return this->m_status;
}

//------------------------------------------------------------------------------
// Address: 0x10014090
// Name: public: virtual void CFileAsyncWriteFileJob::DoCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileAsyncWriteFileJob::DoCleanup(CFileAsyncWriteFileJob *this)
{
  CUtlBuffer *m_pBuffer; // esi

  m_pBuffer = (CUtlBuffer *)this->m_pBuffer;
  if ( m_pBuffer != nullptr && this->m_bFreeMemory )
  {
    if ( m_pBuffer->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pBuffer->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBuffer->m_Memory.m_pMemory);
        m_pBuffer->m_Memory.m_pMemory = nullptr;
      }
      m_pBuffer->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_pBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014480
// Name: public: struct FSAsyncFile_t__ __near * CAsyncOpenedFiles::FindOrAdd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncFile_t__ *__thiscall CAsyncOpenedFiles::FindOrAdd(CAsyncOpenedFiles *this, const char *pszFilename)
{
  DWORD CurrentThreadId; // ecx
  AsyncOpenedFile_t *v4; // edi
  FSAsyncFile_t__ *result; // eax
  AsyncOpenedFile_t *v6; // eax
  char szFixedName[512]; // [esp+Ch] [ebp-210h] BYREF
  CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t search; // [esp+20Ch] [ebp-10h] BYREF
  CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t insert; // [esp+214h] [ebp-8h] BYREF

  V_strncpy(pDest: szFixedName, pSrc: pszFilename, maxLen: 512);
  V_FixSlashes(pname: szFixedName, separator: 92);
  CurrentThreadId = GetCurrentThreadId();
  v4 = nullptr;
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  search.key = szFixedName;
  result = (FSAsyncFile_t__ *)CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                this: &this->m_map.m_Tree,
                                &search);
  if ( (unsigned __int16)result == 0xFFFF )
  {
    v6 = (AsyncOpenedFile_t *)operator new(nSize: 0xCu);
    if ( v6 != nullptr )
    {
      v6->hFile = nullptr;
      v6->m_iRefs = 1;
      v6->__vftable = (AsyncOpenedFile_t_vtbl *)&AsyncOpenedFile_t::`vftable';
      v4 = v6;
    }
    insert.key = MemAlloc_StrDup(pString: szFixedName);
    insert.elem = v4;
    result = (FSAsyncFile_t__ *)CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                                  this: &this->m_map.m_Tree,
                                  &insert);
  }
  else
  {
    _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)result].m_Data.elem->m_iRefs, 1u);
  }
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014580
// Name: public: void CAsyncOpenedFiles::Release(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncOpenedFiles::Release(CAsyncOpenedFiles *this, int item)
{
  DWORD CurrentThreadId; // ecx
  AsyncOpenedFile_t *elem; // ecx
  CBaseFileSystem *v5; // eax
  AsyncOpenedFile_t *v6; // ecx

  if ( item != 0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    elem = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
    if ( _InterlockedDecrement(&elem->m_iRefs) == 0 )
    {
      elem->OnFinalRelease(this: elem);
      if ( this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->hFile != nullptr )
      {
        v5 = BaseFileSystem();
        v5->Close(
          this: &v5->IBaseFileSystem,
          a2: this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->hFile);
      }
      v6 = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
      if ( v6 != nullptr )
        ((void (__thiscall *)(AsyncOpenedFile_t *, int))v6->dtr_CRefCountServiceBase<0,CRefMT>)(a1: v6, a2: 1);
      free(pMem: (void *)this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.key);
      if ( (_WORD)item != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_map.m_Tree,
          elem: item);
        this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Left = item;
        this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Right = this->m_map.m_Tree.m_FirstFree;
        this->m_map.m_Tree.m_FirstFree = item;
        --this->m_map.m_Tree.m_NumElements;
      }
    }
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100146F0
// Name: public: virtual int CFileAsyncFileSizeJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncFileSizeJob::DoExecute(CFileAsyncFileSizeJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  FileAsyncRequest_t *v5; // esi
  CBaseFileSystem *v6; // edi
  int v7; // eax

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  if ( this != nullptr )
    v5 = &this->FileAsyncRequest_t;
  else
    v5 = nullptr;
  v6 = BaseFileSystem();
  v7 = v6->Size(this: &v6->IBaseFileSystem, a2: v5->pszFilename, a3: v5->pszPathID);
  CBaseFileSystem::DoAsyncCallback(
    this: v6,
    request: v5,
    pData: nullptr,
    nBytesRead: v7,
    result: (FSAsyncStatus_t)((v7 != 0) - 1));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014790
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncReadMultipleCreditAlloc(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **phControls)
{
  int m_nValue; // eax
  bool v7; // al
  const FileAsyncRequest_t *v8; // edi
  int i; // ebx
  CFileAsyncReadJob *v10; // eax
  CFileAsyncReadJob *Job; // esi
  CFileAsyncReadJob *v12; // eax
  char bSynchronous_3; // [esp+Fh] [ebp+Bh]

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue == 0;
  v8 = pRequests;
  if ( !v7 || (pRequests->flags & 4) != 0 || (bSynchronous_3 = 0, this->m_pThreadPool == nullptr) )
    bSynchronous_3 = 1;
  if ( !v7 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  for ( i = 0; i < nRequests; ++i )
  {
    if ( v8->nBytes < 0 )
    {
      v12 = (CFileAsyncReadJob *)operator new(nSize: 0x6Cu);
      Job = v12;
      if ( v12 == nullptr )
      {
LABEL_16:
        Job = nullptr;
        goto LABEL_17;
      }
      CFileAsyncReadJob::CFileAsyncReadJob(this: v12, fromRequest: v8);
      Job->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncFileSizeJob::`vftable'{for `IRefCounted'};
      Job->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncFileSizeJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    }
    else
    {
      v10 = (CFileAsyncReadJob *)operator new(nSize: 0x6Cu);
      if ( v10 == nullptr )
        goto LABEL_16;
      Job = CFileAsyncReadJob::CFileAsyncReadJob(this: v10, fromRequest: v8);
    }
LABEL_17:
    if ( bSynchronous_3 != 0 )
      CJob::Execute(this: Job);
    else
      this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: Job);
    if ( phControls != nullptr )
      phControls[i] = (FSAsyncControl_t__ *)Job;
    else
      Job->Release(this: Job);
    ++v8;
  }
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10014890
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncBeginRead(
        CBaseFileSystem *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  if ( async_allow_held_files.m_pParent != nullptr && async_allow_held_files.m_pParent->m_Value.m_nValue != 0 )
  {
    *phFile = CAsyncOpenedFiles::FindOrAdd(this: &g_AsyncOpenedFiles, pszFilename: pszFile);
    return FSASYNC_OK;
  }
  else
  {
    *phFile = (FSAsyncFile_t__ *)0xFFFF;
    return FSASYNC_OK;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100148D0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncEndRead(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncEndRead(CBaseFileSystem *this, FSAsyncFile_t__ *hFile)
{
  if ( hFile != (FSAsyncFile_t__ *)0xFFFF )
    CAsyncOpenedFiles::Release(this: &g_AsyncOpenedFiles, item: (int)hFile);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100148F0
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncRead(struct FileAsyncRequest_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseFileSystem::SyncRead@<eax>(
        CBaseFileSystem *this@<ecx>,
        int a2@<edi>,
        const FileAsyncRequest_t *request)
{
  FSAsyncFile_t__ *hSpecificAsyncFile; // eax
  AsyncOpenedFile_t *v6; // eax
  AsyncOpenedFile_t *v7; // edi
  void *v8; // eax
  signed int nBytes; // eax
  unsigned int Size; // edi
  void *(__cdecl *pfnAlloc)(const char *, unsigned int); // eax
  void *v12; // eax
  int nOffset; // eax
  int v14; // edi
  int iPrevPriority; // [esp+8h] [ebp-14h]
  unsigned int nOffsetAlign; // [esp+Ch] [ebp-10h] BYREF
  AsyncOpenedFile_t *pHeldFile; // [esp+10h] [ebp-Ch]
  void *pDest; // [esp+14h] [ebp-8h]
  int nBytesToRead; // [esp+18h] [ebp-4h]
  void *hFile; // [esp+24h] [ebp+8h]
  FSAsyncStatus_t hFilea; // [esp+24h] [ebp+8h]

  if ( request->nBytes < 0 || request->nOffset < 0 )
  {
    _Msg(a1: "Invalid async read of %s\n", request->pszFilename);
    CBaseFileSystem::DoAsyncCallback(this, request, pData: nullptr, nBytesRead: 0, result: FSASYNC_ERR_FILEOPEN);
    return -1;
  }
  hSpecificAsyncFile = request->hSpecificAsyncFile;
  if ( hSpecificAsyncFile == (FSAsyncFile_t__ *)0xFFFF )
  {
    pHeldFile = nullptr;
    v7 = nullptr;
    goto LABEL_8;
  }
  v6 = CAsyncOpenedFiles::Get(this: &g_AsyncOpenedFiles, item: hSpecificAsyncFile);
  v7 = v6;
  pHeldFile = v6;
  if ( v6 == nullptr || v6->hFile == nullptr )
  {
LABEL_8:
    v8 = this->OpenEx(this, a2: request->pszFilename, a3: "rb", a4: 0, a5: request->pszPathID, a6: 0);
    hFile = v8;
    if ( v7 != nullptr )
      v7->hFile = v8;
    goto LABEL_10;
  }
  hFile = v6->hFile;
LABEL_10:
  if ( hFile != nullptr )
  {
    nBytes = request->nBytes;
    if ( nBytes != 0 )
    {
      nBytesToRead = request->nBytes;
    }
    else
    {
      nBytes = this->Size_2(this: &this->IBaseFileSystem, a2: hFile) - request->nOffset;
      nBytesToRead = nBytes;
    }
    if ( nBytes < 0 )
    {
      nBytesToRead = 0;
      nBytes = 0;
    }
    if ( request->pData != nullptr )
    {
      pDest = request->pData;
      Size = nBytes;
    }
    else
    {
      Size = nBytes + ((request->flags & 8) != 0);
      if ( this->GetOptimalIOConstraints(this, a2: hFile, a3: &nOffsetAlign, a4: nullptr, a5: nullptr)
        && request->nOffset % nOffsetAlign == 0 )
      {
        Size = IFileSystem::GetOptimalReadSize(this, hFile, nLogicalSize: Size);
      }
      pfnAlloc = request->pfnAlloc;
      if ( pfnAlloc != nullptr )
        v12 = pfnAlloc(a1: request->pszFilename, a2: Size);
      else
        v12 = this->AllocOptimalReadBuffer(this, a2: hFile, a3: Size, a4: request->nOffset);
      pDest = v12;
    }
    ((void (__thiscall *)(CBaseFileSystem *, void *, _DWORD, int))this->SetBufferSize)(
      a1: this,
      a2: hFile,
      a3: 0,
      a4: a2);
    nOffset = request->nOffset;
    if ( nOffset > 0 )
      this->Seek(this: &this->IBaseFileSystem, a2: hFile, a3: nOffset, a4: FILESYSTEM_SEEK_HEAD);
    iPrevPriority = _ThreadGetPriority(a1: 0);
    if ( iPrevPriority < 2 )
      _ThreadSetPriority(a1: 0, a2: 2);
    v14 = ((int (__thiscall *)(CBaseFileSystem *, void *, unsigned int, int))this->ReadEx)(
            a1: this,
            a2: pDest,
            a3: Size,
            a4: nBytesToRead);
    if ( iPrevPriority < 2 )
      _ThreadSetPriority(a1: 0, a2: iPrevPriority);
    if ( pHeldFile == nullptr )
      this->Close(this: &this->IBaseFileSystem, a2: hFile);
    if ( (request->flags & 8) != 0 )
      *((_BYTE *)pDest + v14) = 0;
    if ( v14 != 0 || (hFilea = FSASYNC_ERR_READING, nBytesToRead == 0) )
      hFilea = FSASYNC_OK;
    if ( v14 >= nBytesToRead )
      v14 = nBytesToRead;
    CBaseFileSystem::DoAsyncCallback(this, request, pData: pDest, nBytesRead: v14, result: hFilea);
    v7 = pHeldFile;
  }
  else
  {
    CBaseFileSystem::DoAsyncCallback(this, request, pData: nullptr, nBytesRead: 0, result: FSASYNC_ERR_FILEOPEN);
    hFilea = FSASYNC_ERR_FILEOPEN;
  }
  if ( v7 != nullptr )
    CAsyncOpenedFiles::Release(this: &g_AsyncOpenedFiles, item: (int)request->hSpecificAsyncFile);
  if ( this->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this, accesstype: "async", fullpath: request->pszFilename, options: setName);
  return hFilea;
}

//------------------------------------------------------------------------------
// Address: 0x10014B70
// Name: public: virtual int CFileAsyncReadJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CFileAsyncReadJob::DoExecute@<eax>(CFileAsyncReadJob *this@<ecx>, int a2@<edx>, int a3@<edi>)
{
  int m_nValue; // ecx
  int v5; // eax
  CBaseFileSystem *v6; // eax

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v5 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v5);
  }
  v6 = BaseFileSystem();
  if ( this != nullptr )
    return CBaseFileSystem::SyncRead(this: v6, a2: a3, request: &this->FileAsyncRequest_t);
  else
    return CBaseFileSystem::SyncRead(this: v6, a2: a3, request: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002CA80
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,class CUtlStringList __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CUtlStringList *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CUtlStringList *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,CUtlStringList *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CUtlStringList *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CUtlStringList *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043C60
// Name: _dynamic_initializer_for__filesystem_buffer_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_buffer_size__()
{
  ConVar::ConVar(
    this: &filesystem_buffer_size,
    pName: "filesystem_buffer_size",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Size of per file buffers. 0 for none");
  return atexit(func: dynamic_atexit_destructor_for__filesystem_buffer_size__);
}

//------------------------------------------------------------------------------
// Address: 0x10043CB0
// Name: _dynamic_initializer_for__CBaseFileSystem::m_ExcludeFilePaths__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_ExcludeFilePaths__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__);
}

//------------------------------------------------------------------------------
// Address: 0x10043CC0
// Name: _dynamic_initializer_for__CBaseFileSystem::m_DLCContents__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_DLCContents__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__);
}

//------------------------------------------------------------------------------
// Address: 0x10043CD0
// Name: _dynamic_initializer_for__CBaseFileSystem::m_CorruptDLC__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_CorruptDLC__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__);
}

//------------------------------------------------------------------------------
// Address: 0x10043EC0
// Name: _dynamic_initializer_for__async_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_mode__()
{
  ConVar::ConVar(
    this: &async_mode,
    pName: "async_mode",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set the async filesystem mode (0 = async, 1 = synchronous)");
  return atexit(func: dynamic_atexit_destructor_for__async_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10043EF0
// Name: _dynamic_initializer_for__async_simulate_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_simulate_delay__()
{
  ConVar::ConVar(
    this: &async_simulate_delay,
    pName: "async_simulate_delay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Simulate a delay of up to a set msec per file operation");
  return atexit(func: dynamic_atexit_destructor_for__async_simulate_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10043F20
// Name: _dynamic_initializer_for__async_allow_held_files__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_allow_held_files__()
{
  ConVar::ConVar(
    this: &async_allow_held_files,
    pName: "async_allow_held_files",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow AsyncBegin/EndRead()");
  return atexit(func: dynamic_atexit_destructor_for__async_allow_held_files__);
}

//------------------------------------------------------------------------------
// Address: 0x10043F50
// Name: _dynamic_initializer_for__async_suspend_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_suspend_command__()
{
  ConCommand::ConCommand(
    this: &async_suspend_command,
    pName: "async_suspend",
    callback: (void (__cdecl *)(const CCommand *))async_suspend,
    pHelpString: setName,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__async_suspend_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043F80
// Name: _dynamic_initializer_for__async_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_resume_command__()
{
  ConCommand::ConCommand(
    this: &async_resume_command,
    pName: "async_resume",
    callback: (void (__cdecl *)(const CCommand *))async_resume,
    pHelpString: setName,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__async_resume_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100440E0
// Name: _dynamic_initializer_for__filesystem_unbuffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_unbuffered_io__()
{
  ConVar::ConVar(
    this: &filesystem_unbuffered_io,
    pName: "filesystem_unbuffered_io",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: setName);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_unbuffered_io__);
}

//------------------------------------------------------------------------------
// Address: 0x10044110
// Name: _dynamic_initializer_for__filesystem_native__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_native__()
{
  ConVar::ConVar(
    this: &filesystem_native,
    pName: "filesystem_native",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use native FS or STDIO");
  return atexit(func: dynamic_atexit_destructor_for__filesystem_native__);
}

//------------------------------------------------------------------------------
// Address: 0x10044140
// Name: _dynamic_initializer_for__filesystem_max_stdio_read__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_max_stdio_read__()
{
  ConVar::ConVar(
    this: &filesystem_max_stdio_read,
    pName: "filesystem_max_stdio_read",
    pDefaultValue: "16",
    flags: 0,
    pHelpString: setName);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_max_stdio_read__);
}

//------------------------------------------------------------------------------
// Address: 0x10044170
// Name: _dynamic_initializer_for__filesystem_report_buffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_report_buffered_io__()
{
  ConVar::ConVar(
    this: &filesystem_report_buffered_io,
    pName: "filesystem_report_buffered_io",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_report_buffered_io__);
}

//------------------------------------------------------------------------------
// Address: 0x100441A0
// Name: _dynamic_initializer_for__filesystem_use_overlapped_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_use_overlapped_io__()
{
  ConVar::ConVar(
    this: &filesystem_use_overlapped_io,
    pName: "filesystem_use_overlapped_io",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: setName);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_use_overlapped_io__);
}

//------------------------------------------------------------------------------
// Address: 0x10044530
// Name: _dynamic_atexit_destructor_for__filesystem_buffer_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_buffer_size__()
{
  ConVar::~ConVar(this: &filesystem_buffer_size);
}

//------------------------------------------------------------------------------
// Address: 0x10044630
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&CBaseFileSystem::m_CorruptDLC);
}

//------------------------------------------------------------------------------
// Address: 0x10044680
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&CBaseFileSystem::m_ExcludeFilePaths);
}

//------------------------------------------------------------------------------
// Address: 0x10044690
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&CBaseFileSystem::m_DLCContents);
}

//------------------------------------------------------------------------------
// Address: 0x100446A0
// Name: _dynamic_atexit_destructor_for__async_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_mode__()
{
  ConVar::~ConVar(this: &async_mode);
}

//------------------------------------------------------------------------------
// Address: 0x100446B0
// Name: _dynamic_atexit_destructor_for__async_simulate_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_simulate_delay__()
{
  ConVar::~ConVar(this: &async_simulate_delay);
}

//------------------------------------------------------------------------------
// Address: 0x100446C0
// Name: _dynamic_atexit_destructor_for__async_allow_held_files__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_allow_held_files__()
{
  ConVar::~ConVar(this: &async_allow_held_files);
}

//------------------------------------------------------------------------------
// Address: 0x100446D0
// Name: _dynamic_atexit_destructor_for__async_suspend_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_suspend_command__()
{
  ConCommand::~ConCommand(this: &async_suspend_command);
}

//------------------------------------------------------------------------------
// Address: 0x100446E0
// Name: _dynamic_atexit_destructor_for__async_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_resume_command__()
{
  ConCommand::~ConCommand(this: &async_resume_command);
}

//------------------------------------------------------------------------------
// Address: 0x10044720
// Name: _dynamic_atexit_destructor_for__filesystem_unbuffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_unbuffered_io__()
{
  ConVar::~ConVar(this: &filesystem_unbuffered_io);
}

//------------------------------------------------------------------------------
// Address: 0x10044730
// Name: _dynamic_atexit_destructor_for__filesystem_native__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_native__()
{
  ConVar::~ConVar(this: &filesystem_native);
}

//------------------------------------------------------------------------------
// Address: 0x10044740
// Name: _dynamic_atexit_destructor_for__filesystem_max_stdio_read__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_max_stdio_read__()
{
  ConVar::~ConVar(this: &filesystem_max_stdio_read);
}

//------------------------------------------------------------------------------
// Address: 0x10044750
// Name: _dynamic_atexit_destructor_for__filesystem_report_buffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_report_buffered_io__()
{
  ConVar::~ConVar(this: &filesystem_report_buffered_io);
}

//------------------------------------------------------------------------------
// Address: 0x10044760
// Name: _dynamic_atexit_destructor_for__filesystem_use_overlapped_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_use_overlapped_io__()
{
  ConVar::~ConVar(this: &filesystem_use_overlapped_io);
}

//------------------------------------------------------------------------------
// Address: 0x10043C90
// Name: _dynamic_initializer_for__g_FileOpenDuplicateTimes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileOpenDuplicateTimes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__);
}

//------------------------------------------------------------------------------
// Address: 0x10043CA0
// Name: _dynamic_initializer_for__g_FileOpenDuplicateTimesMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileOpenDuplicateTimesMutex__()
{
  g_FileOpenDuplicateTimesMutex.m_ownerID = 0;
  g_FileOpenDuplicateTimesMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10043CE0
// Name: _dynamic_initializer_for__g_UpdateZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UpdateZipBuffer__()
{
  CUtlBuffer::CUtlBuffer(this: &g_UpdateZipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_UpdateZipBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x10043D00
// Name: _dynamic_initializer_for__g_XLSPPatchZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_XLSPPatchZipBuffer__()
{
  CUtlBuffer::CUtlBuffer(this: &g_XLSPPatchZipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x10043D20
// Name: _dynamic_initializer_for__s_IoStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_IoStats__()
{
  s_IoStats.m_nNumberOfFileSeeks.m_value = 0;
  s_IoStats.m_nTimeInFileSeek.m_value = 0;
  s_IoStats.m_nNumberOfFileReads.m_value = 0;
  s_IoStats.m_nTimeInFileRead.m_value = 0;
  s_IoStats.m_nFileReadTotalSize.m_value = 0;
  s_IoStats.m_nNumberOfFileOpens.m_value = 0;
  return atexit(func: dynamic_atexit_destructor_for__s_IoStats__);
}

//------------------------------------------------------------------------------
// Address: 0x10043D50
// Name: _dynamic_initializer_for__g_pszReadFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pszReadFilename__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_pszReadFilename);
  return atexit(func: dynamic_atexit_destructor_for__g_pszReadFilename__);
}

//------------------------------------------------------------------------------
// Address: 0x10043D70
// Name: _dynamic_initializer_for__fs_dump_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_dump_open_duplicate_times_command__()
{
  ConCommand::ConCommand(
    this: &fs_dump_open_duplicate_times_command,
    pName: "fs_dump_open_duplicate_times",
    callback: (void (__cdecl *)(const CCommand *))fs_dump_open_duplicate_times,
    pHelpString: "Set fs_report_long_reads 1 before loading to use this. Prints a list of files that were opened more than once and ~h"
    "ow long was spent reading from them.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043DA0
// Name: _dynamic_initializer_for__fs_clear_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_clear_open_duplicate_times_command__()
{
  ConCommand::ConCommand(
    this: &fs_clear_open_duplicate_times_command,
    pName: "fs_clear_open_duplicate_times",
    callback: (void (__cdecl *)(const CCommand *))fs_clear_open_duplicate_times,
    pHelpString: "Clear the list of files that have been opened.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043DD0
// Name: _dynamic_initializer_for__fs_fios_flush_cache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_flush_cache_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_flush_cache_command,
    pName: "fs_fios_flush_cache",
    callback: (void (__cdecl *)(const CCommand *))CPackFile::SetupPreloadData,
    pHelpString: "Flushes the FIOS HDD cache.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_flush_cache_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043E00
// Name: _dynamic_initializer_for__fs_fios_print_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_print_prefetches_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_print_prefetches_command,
    pName: "fs_fios_print_prefetches",
    callback: (void (__cdecl *)(const CCommand *))CPackFile::SetupPreloadData,
    pHelpString: "Displays all the prefetches currently in progress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043E30
// Name: _dynamic_initializer_for__fs_fios_prefetch_file_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_prefetch_file_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_prefetch_file_command,
    pName: "fs_fios_prefetch_file",
    callback: (void (__cdecl *)(const CCommand *))CPackFile::SetupPreloadData,
    pHelpString: "Prefetches a file: </PS3_GAME/USRDIR/filename.bin>.\nThe preftech is medium priority and persistent.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043E60
// Name: _dynamic_initializer_for__fs_fios_prefetch_file_in_pack_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_prefetch_file_in_pack_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_prefetch_file_in_pack_command,
    pName: "fs_fios_prefetch_file_in_pack",
    callback: (void (__cdecl *)(const CCommand *))CPackFile::SetupPreloadData,
    pHelpString: "Prefetches a file in a pack: <portal2/models/container_ride/fineDebris_part5.ani>.\n"
    "The preftech is medium priority and non-persistent.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043E90
// Name: _dynamic_initializer_for__fs_fios_cancel_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_cancel_prefetches_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_cancel_prefetches_command,
    pName: "fs_fios_cancel_prefetches",
    callback: (void (__cdecl *)(const CCommand *))CPackFile::SetupPreloadData,
    pHelpString: "Cancels all the prefetches in progress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10043FB0
// Name: _dynamic_initializer_for__g_AsyncOpenedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncOpenedFiles__()
{
  g_AsyncOpenedFiles.m_mutex.m_ownerID = 0;
  g_AsyncOpenedFiles.m_mutex.m_depth = 0;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_pMemory = nullptr;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_AsyncOpenedFiles.m_map.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_AsyncOpenedFiles.m_map.m_Tree.m_FirstFree = -1;
  g_AsyncOpenedFiles.m_map.m_Tree.m_pElements = nullptr;
  g_AsyncOpenedFiles.m_map.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncOpenedFiles__);
}

//------------------------------------------------------------------------------
// Address: 0x10044000
// Name: _dynamic_initializer_for__g_AsyncFinishMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncFinishMutex__()
{
  CThreadMutex::CThreadMutex(this: &g_AsyncFinishMutex);
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncFinishMutex__);
}

//------------------------------------------------------------------------------
// Address: 0x10044020
// Name: _dynamic_initializer_for__g_FileSystem_Stdio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileSystem_Stdio__()
{
  CBaseFileSystem::CBaseFileSystem(this: &g_FileSystem_Stdio);
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Stdio_vtbl *)&CFileSystem_Stdio::`vftable'{for `IAppSystem'};
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Stdio::`vftable'{for `IBaseFileSystem'};
  *(_WORD *)&g_FileSystem_Stdio.m_bMounted = 256;
  return atexit(func: dynamic_atexit_destructor_for__g_FileSystem_Stdio__);
}

//------------------------------------------------------------------------------
// Address: 0x10044060
// Name: _dynamic_initializer_for__g_FileSystem_Async__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileSystem_Async__()
{
  CAsyncFileSystem::CAsyncFileSystem(this: &g_FileSystem_Async);
  return atexit(func: dynamic_atexit_destructor_for__g_FileSystem_Async__);
}

//------------------------------------------------------------------------------
// Address: 0x10044080
// Name: _dynamic_initializer_for____g_CreateCFileSystem_StdioIFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCFileSystem_StdioIFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCFileSystem_StdioIFileSystem_reg,
           fn: (void *(__cdecl *)())_CreateCFileSystem_StdioIFileSystem_interface,
           pName: "VFileSystem017");
}

//------------------------------------------------------------------------------
// Address: 0x100440A0
// Name: _dynamic_initializer_for____g_CreateCFileSystem_StdioIBaseFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCFileSystem_StdioIBaseFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCFileSystem_StdioIBaseFileSystem_reg,
           fn: (void *(__cdecl *)())_CreateCFileSystem_StdioIBaseFileSystem_interface,
           pName: "VBaseFileSystem011");
}

//------------------------------------------------------------------------------
// Address: 0x100440C0
// Name: _dynamic_initializer_for____g_CreateCAsyncFileSystemIAsyncFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCAsyncFileSystemIAsyncFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCAsyncFileSystemIAsyncFileSystem_reg,
           fn: (void *(__cdecl *)())_CreateCAsyncFileSystemIAsyncFileSystem_interface,
           pName: "VNewAsyncFileSystem001");
}

//------------------------------------------------------------------------------
// Address: 0x100441D0
// Name: _dynamic_initializer_for__g_ThreadIOEvents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ThreadIOEvents__()
{
  if ( ((unsigned __int8)&g_ThreadIOEvents & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_ThreadIOEvents = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_ThreadIOEvents__);
}

//------------------------------------------------------------------------------
// Address: 0x10044200
// Name: _dynamic_initializer_for__g_QueuedLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QueuedLoader__()
{
  CQueuedLoader::CQueuedLoader(this: &g_QueuedLoader);
  return atexit(func: dynamic_atexit_destructor_for__g_QueuedLoader__);
}

//------------------------------------------------------------------------------
// Address: 0x10044220
// Name: _dynamic_initializer_for____g_CreateCQueuedLoaderIQueuedLoader_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCQueuedLoaderIQueuedLoader_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCQueuedLoaderIQueuedLoader_reg,
           fn: _CreateCQueuedLoaderIQueuedLoader_interface,
           pName: "QueuedLoaderVersion001");
}

//------------------------------------------------------------------------------
// Address: 0x10044240
// Name: _dynamic_initializer_for__g_nActiveJobs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nActiveJobs__()
{
  g_nActiveJobs.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044250
// Name: _dynamic_initializer_for__g_nQueuedJobs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nQueuedJobs__()
{
  g_nQueuedJobs.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044260
// Name: _dynamic_initializer_for__g_nHighPriorityJobs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nHighPriorityJobs__()
{
  g_nHighPriorityJobs.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044270
// Name: _dynamic_initializer_for__g_nJobsToFinishBeforePlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nJobsToFinishBeforePlay__()
{
  g_nJobsToFinishBeforePlay.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044280
// Name: _dynamic_initializer_for__g_nIOMemory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nIOMemory__()
{
  g_nIOMemory.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044290
// Name: _dynamic_initializer_for__g_nAnonymousIOMemory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nAnonymousIOMemory__()
{
  g_nAnonymousIOMemory.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100442A0
// Name: _dynamic_initializer_for__g_SuspendIO__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_SuspendIO__()
{
  g_SuspendIO.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100442B0
// Name: _dynamic_initializer_for__g_nForceSuspendIO__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_nForceSuspendIO__()
{
  g_nForceSuspendIO.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100442C0
// Name: _dynamic_initializer_for__g_DVDLayout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DVDLayout__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DVDLayout__);
}

//------------------------------------------------------------------------------
// Address: 0x10044540
// Name: _dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__()
{
  ConCommand::~ConCommand(this: &fs_dump_open_duplicate_times_command);
}

//------------------------------------------------------------------------------
// Address: 0x10044550
// Name: _dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__()
{
  ConCommand::~ConCommand(this: &fs_clear_open_duplicate_times_command);
}

//------------------------------------------------------------------------------
// Address: 0x10044560
// Name: _dynamic_atexit_destructor_for__fs_fios_flush_cache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_flush_cache_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_flush_cache_command);
}

//------------------------------------------------------------------------------
// Address: 0x10044570
// Name: _dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_print_prefetches_command);
}

//------------------------------------------------------------------------------
// Address: 0x10044580
// Name: _dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_prefetch_file_command);
}

//------------------------------------------------------------------------------
// Address: 0x10044590
// Name: _dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_prefetch_file_in_pack_command);
}

//------------------------------------------------------------------------------
// Address: 0x100445A0
// Name: _dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_cancel_prefetches_command);
}

//------------------------------------------------------------------------------
// Address: 0x100445B0
// Name: _dynamic_atexit_destructor_for__g_PathIDTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PathIDTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PathIDTable);
}

//------------------------------------------------------------------------------
// Address: 0x100445C0
// Name: _dynamic_atexit_destructor_for__s_IoStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_IoStats__()
{
  s_IoStats.__vftable = (CIoStats_vtbl *)&IIoStats::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100445D0
// Name: _dynamic_atexit_destructor_for__g_pszReadFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pszReadFilename__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_pszReadFilename);
}

//------------------------------------------------------------------------------
// Address: 0x100445E0
// Name: _dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__()
{
  if ( g_XLSPPatchZipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_XLSPPatchZipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_XLSPPatchZipBuffer.m_Memory.m_pMemory);
      g_XLSPPatchZipBuffer.m_Memory.m_pMemory = nullptr;
    }
    g_XLSPPatchZipBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044620
// Name: _dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&g_FileOpenDuplicateTimes);
}

//------------------------------------------------------------------------------
// Address: 0x10044640
// Name: _dynamic_atexit_destructor_for__g_UpdateZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UpdateZipBuffer__()
{
  if ( g_UpdateZipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_UpdateZipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_UpdateZipBuffer.m_Memory.m_pMemory);
      g_UpdateZipBuffer.m_Memory.m_pMemory = nullptr;
    }
    g_UpdateZipBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100446F0
// Name: _dynamic_atexit_destructor_for__g_AsyncFinishMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncFinishMutex__()
{
  CThreadMutex::~CThreadMutex(this: &g_AsyncFinishMutex);
}

//------------------------------------------------------------------------------
// Address: 0x10044700
// Name: _dynamic_atexit_destructor_for__g_AsyncOpenedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncOpenedFiles__()
{
  CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_AsyncOpenedFiles.m_map.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10044710
// Name: _dynamic_atexit_destructor_for__g_FileSystem_Async__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileSystem_Async__()
{
  CAsyncFileSystem::~CAsyncFileSystem(this: &g_FileSystem_Async);
}

//------------------------------------------------------------------------------
// Address: 0x10044770
// Name: _dynamic_atexit_destructor_for__g_FileSystem_Stdio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileSystem_Stdio__()
{
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Stdio_vtbl *)&CFileSystem_Stdio::`vftable'{for `IAppSystem'};
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Stdio::`vftable'{for `IBaseFileSystem'};
  CBaseFileSystem::~CBaseFileSystem(this: &g_FileSystem_Stdio);
}

//------------------------------------------------------------------------------
// Address: 0x10044790
// Name: _dynamic_atexit_destructor_for__g_ThreadIOEvents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThreadIOEvents__()
{
  CTSPool<CThreadEvent>::~CTSPool<CThreadEvent>(this: &g_ThreadIOEvents.m_Events);
}

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10008BE0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncEndRead(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBaseFileSystem::AsyncEndRead(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014A10
// Name: public: virtual void (*CBaseFileSystem::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CBaseFileSystem::GetDirtyDiskReportFunc(CBaseFileSystem *this))()
{
  return this->m_DirtyDiskReportFunc;
}

//------------------------------------------------------------------------------
// Address: 0x10015AE0
// Name: async_suspend
// Source: json
//------------------------------------------------------------------------------
void __cdecl async_suspend()
{
  CBaseFileSystem *v0; // eax

  v0 = BaseFileSystem();
  v0->AsyncSuspend(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10015B00
// Name: async_resume
// Source: json
//------------------------------------------------------------------------------
void __cdecl async_resume()
{
  CBaseFileSystem *v0; // eax

  v0 = BaseFileSystem();
  v0->AsyncResume(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10015B20
// Name: public: static void CFileAsyncReadJob::InterceptCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFileAsyncReadJob::InterceptCallback(
        const FileAsyncRequest_t *request,
        int nBytesRead,
        FSAsyncStatus_t result)
{
  void *pContext; // eax
  void (__cdecl *v4)(const FileAsyncRequest_t *, int, FSAsyncStatus_t); // edx

  pContext = request->pContext;
  if ( result == FSASYNC_OK && (request->flags & 2) == 0 )
  {
    *((_DWORD *)pContext + 23) = request->pData;
    *((_DWORD *)pContext + 24) = nBytesRead;
  }
  v4 = *((void (__cdecl **)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))pContext + 26);
  if ( v4 != nullptr )
  {
    request->pfnCallback = v4;
    request->pContext = *((void **)pContext + 25);
    (*((void (__cdecl **)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))pContext + 26))(
      a1: request,
      a2: nBytesRead,
      a3: result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015B70
// Name: public: virtual int CFileAsyncDirectoryScanJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncDirectoryScanJob::DoExecute(CFileAsyncDirectoryScanJob *this)
{
  char *m_SearchSpec; // ebx
  char *m_CurPath; // edi
  char *i; // eax
  int findSession; // [esp+Ch] [ebp-4h] BYREF

  m_SearchSpec = this->m_SearchSpec;
  m_CurPath = this->m_CurPath;
  findSession = -1;
  _V_strcpy(dest: this->m_CurPath, src: this->m_SearchSpec);
  V_StripFilename(path: m_CurPath);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: m_SearchSpec, a3: &findSession);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findSession) )
  {
    this->m_pAddResultCallback(a1: this->m_pContext, a2: m_CurPath, a3: i);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findSession);
  this->m_pCompletionCallback(a1: this->m_pContext, a2: FSASYNC_OK);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015C00
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncReadMultiple(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **phControls)
{
  return this->AsyncReadMultipleCreditAlloc(this, a2: pRequests, a3: nRequests, a4: nullptr, a5: 0, a6: phControls);
}

//------------------------------------------------------------------------------
// Address: 0x10015C30
// Name: AsyncWriteJobFilter
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AsyncWriteJobFilter(CJob *pJob)
{
  void *v1; // eax

  v1 = __RTDynamicCast(
         inptr: pJob,
         VfDelta: 0,
         SrcType: &CJob `RTTI Type Descriptor',
         TargetType: &CFileAsyncJob `RTTI Type Descriptor',
         isReference: 0);
  return v1 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v1 + 28))(a1: v1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015C70
// Name: public: virtual bool CBaseFileSystem::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFileSystem::AsyncSuspend(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->SuspendExecution(this: this->m_pThreadPool);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015C90
// Name: public: virtual bool CBaseFileSystem::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFileSystem::AsyncResume(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->ResumeExecution(this: this->m_pThreadPool);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015CB0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncBeginRead(
        CBaseFileSystem *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  *phFile = (FSAsyncFile_t__ *)0xFFFF;
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10015CD0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncGetResult(
        CBaseFileSystem *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  int v5; // eax

  if ( ppData != nullptr )
    *ppData = nullptr;
  if ( pSize != nullptr )
    *pSize = 0;
  if ( hControl == nullptr )
    return FSASYNC_ERR_FAILURE;
  v5 = *((_DWORD *)hControl + 3);
  if ( v5 == 1 || v5 == 2 || v5 == 4 )
    return FSASYNC_STATUS_PENDING;
  else
    return (*(FSAsyncStatus_t (__stdcall **)(void **, int *))(*(_DWORD *)hControl + 24))(a1: ppData, a2: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x10015D30
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncStatus(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncStatus(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    return *((_DWORD *)hControl + 3);
  else
    return -5;
}

//------------------------------------------------------------------------------
// Address: 0x10015D50
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncFlush(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncFlush(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->AbortAll(this: this->m_pThreadPool);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10015D70
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncSetPriority(struct FSAsyncControl_t__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncSetPriority(CBaseFileSystem *this, FSAsyncControl_t__ *hControl, int newPriority)
{
  JobPriority_t v4; // eax

  if ( this->m_pThreadPool != nullptr )
  {
    if ( hControl == nullptr )
      return -5;
    if ( newPriority != 0 )
      v4 = newPriority <= 0 ? JP_LOW : JP_HIGH;
    else
      v4 = JP_NORMAL;
    if ( v4 != *((_DWORD *)hControl + 4) )
      this->m_pThreadPool->ChangePriority(this: this->m_pThreadPool, a2: (CJob *)hControl, a3: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015DD0
// Name: public: virtual void CBaseFileSystem::AsyncAddRef(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncAddRef(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    (**(void (__thiscall ***)(FSAsyncControl_t__ *))hControl)(a1: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10015DF0
// Name: public: virtual void CBaseFileSystem::AsyncRelease(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncRelease(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    (*(void (__thiscall **)(FSAsyncControl_t__ *))(*(_DWORD *)hControl + 4))(a1: hControl);
}

//------------------------------------------------------------------------------
// Address: 0x10015E10
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncWrite(char const __near *,void const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::SyncWrite(
        CBaseFileSystem *this,
        const char *pszFilename,
        void *pSrc,
        int nSrcBytes,
        bool bFreeMemory,
        bool bAppend)
{
  const char *v7; // eax
  void *v8; // ebx

  v7 = "ab+";
  if ( !bAppend )
    v7 = "wb";
  v8 = this->OpenEx(this, a2: pszFilename, a3: v7, a4: 0, a5: 0, a6: 0);
  if ( v8 == nullptr )
    return -1;
  this->SetBufferSize(this, a2: v8, a3: 0);
  this->Write(this: &this->IBaseFileSystem, a2: pSrc, a3: nSrcBytes, a4: v8);
  this->Close(this: &this->IBaseFileSystem, a2: v8);
  if ( bFreeMemory )
    free(pMem: pSrc);
  if ( this->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this, accesstype: "asyncwrite", fullpath: pszFilename, options: defaultValue);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015EC0
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncAppendFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::SyncAppendFile(
        CBaseFileSystem *this,
        const char *pAppendToFileName,
        char *pAppendFromFileName)
{
  CBaseFileSystem *v3; // ebx
  int v4; // esi
  int v5; // edi
  int v6; // edi
  IBaseFileSystem *v7; // esi
  int v8; // edi
  int v9; // ebx
  FSAsyncStatus_t v12; // [esp+10h] [ebp-Ch]
  void *hDestFile; // [esp+14h] [ebp-8h]
  void *hSourceFile; // [esp+18h] [ebp-4h]
  char *buf; // [esp+28h] [ebp+Ch]

  v3 = this;
  v4 = ((int (__stdcall *)(const char *, const char *, _DWORD, _DWORD, _DWORD))this->OpenEx)(
         a1: pAppendToFileName,
         a2: "ab+",
         a3: 0,
         a4: 0,
         a5: 0);
  v5 = -5;
  hDestFile = (void *)v4;
  v12 = FSASYNC_ERR_FAILURE;
  if ( v4 != 0 )
  {
    v3->SetBufferSize(this: v3, a2: (void *)v4, a3: 0);
    v6 = (int)v3->OpenEx(this: v3, a2: pAppendFromFileName, a3: "rb", a4: 0, a5: nullptr, a6: nullptr);
    hSourceFile = (void *)v6;
    if ( v6 != 0 )
    {
      v3->SetBufferSize(this: v3, a2: (void *)v6, a3: 0);
      v7 = &v3->IBaseFileSystem;
      v8 = v3->Size_2(this: &v3->IBaseFileSystem, a2: (void *)v6);
      buf = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x20000);
      if ( v8 > 0 )
      {
        do
        {
          v9 = 0x20000;
          if ( v8 <= 0x20000 )
            v9 = v8;
          v7->Read(this: v7, a2: buf, a3: v9, a4: hSourceFile);
          v7->Write(this: v7, a2: buf, a3: v9, a4: hDestFile);
          v8 -= v9;
        }
        while ( v8 > 0 );
        v3 = this;
      }
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
      v7->Close(this: v7, a2: hSourceFile);
      v4 = (int)hDestFile;
      v12 = FSASYNC_OK;
    }
    v3->Close(this: &v3->IBaseFileSystem, a2: (void *)v4);
    v5 = v12;
  }
  if ( v3->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(
      this: v3,
      accesstype: "asyncappend",
      fullpath: pAppendToFileName,
      options: defaultValue);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10016010
// Name: public: int CJob::Execute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Execute(CJob *this)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int (__thiscall *DoExecute)(CJob *); // edx
  int v6; // eax
  int m_status; // ebx

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        DoExecute = this->DoExecute;
        this->m_status = 2;
        v6 = DoExecute(this);
        this->m_status = v6;
        m_status = v6;
        this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100160E0
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100161B0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x100161C0
// Name: public: virtual int CFileAsyncJob::GetResult(void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncJob::GetResult(CFileAsyncJob *this, void **ppData, int *pSize)
{
  *ppData = nullptr;
  *pSize = 0;
  return this->m_status;
}

//------------------------------------------------------------------------------
// Address: 0x100161E0
// Name: public: virtual char const __near * CFileAsyncWriteJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileAsyncWriteJob::Describe(CFileAsyncWriteJob *this)
{
  return this->m_pszFilename;
}

//------------------------------------------------------------------------------
// Address: 0x100161F0
// Name: public: virtual void CFileAsyncWriteJob::DoCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileAsyncWriteJob::DoCleanup(CFileAsyncWriteJob *this)
{
  if ( this->m_pData != nullptr && this->m_bFreeMemory )
    free(pMem: (void *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10016220
// Name: public: virtual int CFileAsyncWriteJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncWriteJob::DoExecute(CFileAsyncWriteJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  CBaseFileSystem *v5; // eax
  const char *m_pszFilename; // [esp-14h] [ebp-18h]
  void *m_pData; // [esp-10h] [ebp-14h]
  int m_nBytes; // [esp-Ch] [ebp-10h]
  bool m_bAppend; // [esp-4h] [ebp-8h]

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  m_bAppend = this->m_bAppend;
  m_nBytes = this->m_nBytes;
  m_pData = (void *)this->m_pData;
  m_pszFilename = this->m_pszFilename;
  v5 = BaseFileSystem();
  return CBaseFileSystem::SyncWrite(
           this: v5,
           pszFilename: m_pszFilename,
           pSrc: m_pData,
           nSrcBytes: m_nBytes,
           bFreeMemory: false,
           bAppend: m_bAppend);
}

//------------------------------------------------------------------------------
// Address: 0x100162F0
// Name: public: void CBaseFileSystem::ShutdownAsync(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::ShutdownAsync(CBaseFileSystem *this)
{
  IThreadPool *m_pThreadPool; // ecx

  if ( this->m_pThreadPool != nullptr )
  {
    this->AsyncFlush(this);
    this->m_pThreadPool->Stop(this: this->m_pThreadPool, a2: -1);
    m_pThreadPool = this->m_pThreadPool;
    if ( m_pThreadPool != nullptr )
    {
      m_pThreadPool->Release(this: m_pThreadPool);
      this->m_pThreadPool = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016340
// Name: public: virtual void CBaseFileSystem::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncFinishAll(CBaseFileSystem *this, int iToPriority)
{
  JobPriority_t v3; // eax

  if ( this->m_pThreadPool != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
    if ( iToPriority != 0 )
      v3 = iToPriority <= 0 ? JP_LOW : JP_HIGH;
    else
      v3 = JP_NORMAL;
    this->m_pThreadPool->ExecuteToPriority(this: this->m_pThreadPool, a2: v3, a3: nullptr);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100163A0
// Name: public: virtual void CBaseFileSystem::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncFinishAllWrites(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr && g_nAsyncWriteJobs != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
    this->m_pThreadPool->ExecuteToPriority(
      this: this->m_pThreadPool,
      a2: JP_LOW,
      a3: (bool (__cdecl *)(CJob *))AsyncWriteJobFilter);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100163F0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncFinish(struct FSAsyncControl_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncFinish(CBaseFileSystem *this, FSAsyncControl_t__ *hControl, bool wait)
{
  if ( wait )
  {
    if ( hControl != nullptr )
      return CJob::Execute(this: (CJob *)hControl);
    else
      return -5;
  }
  else
  {
    this->AsyncSetPriority(this, a2: hControl, a3: 0x7FFFFFFF);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016430
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncAbort(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    return CJob::Abort(this: (CJob *)hControl, bDiscard: true);
  else
    return -5;
}

//------------------------------------------------------------------------------
// Address: 0x10016450
// Name: public: void CBaseFileSystem::DoAsyncCallback(struct FileAsyncRequest_t const __near &,void __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::DoAsyncCallback(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *request,
        void *pData,
        int nBytesRead,
        FSAsyncStatus_t result)
{
  bool v5; // zf
  CThreadFastMutex *p_m_AsyncCallbackMutex; // edi
  DWORD CurrentThreadId; // ecx
  void *v8; // ebx
  void *(__cdecl *pfnAlloc)(const char *, unsigned int); // eax
  __int64 v10; // xmm0_8
  FileAsyncRequest_t temp; // [esp+4h] [ebp-30h] BYREF
  void *pDataToFree; // [esp+30h] [ebp-4h]

  v5 = request->pfnCallback == nullptr;
  pDataToFree = nullptr;
  if ( v5 )
    return;
  p_m_AsyncCallbackMutex = &this->m_AsyncCallbackMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncCallbackMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncCallbackMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncCallbackMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncCallbackMutex->m_depth;
  }
  v8 = pData;
  if ( pData == nullptr || request->pData == pData )
  {
    request->pfnCallback(a1: request, a2: nBytesRead, a3: result);
    if ( (request->flags & 2) != 0 )
    {
      v8 = request->pData;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  pfnAlloc = request->pfnAlloc;
  *(_QWORD *)&temp.pszFilename = *(_QWORD *)&request->pszFilename;
  *(_QWORD *)&temp.nOffset = *(_QWORD *)&request->nOffset;
  *(_QWORD *)&temp.pfnCallback = *(_QWORD *)&request->pfnCallback;
  v10 = *(_QWORD *)&request->priority;
  temp.pfnAlloc = pfnAlloc;
  *(_QWORD *)&temp.priority = v10;
  *(_QWORD *)&temp.pszPathID = *(_QWORD *)&request->pszPathID;
  temp.pData = pData;
  temp.pfnCallback(a1: &temp, a2: nBytesRead, a3: result);
  if ( (request->flags & 1) != 0 )
LABEL_9:
    v8 = pDataToFree;
LABEL_10:
  v5 = p_m_AsyncCallbackMutex->m_depth-- == 1;
  if ( v5 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncCallbackMutex, 0);
  if ( v8 != nullptr )
    free(pMem: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10016550
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10016560
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100165F0
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x10016640
// Name: public: CFileAsyncWriteJob::CFileAsyncWriteJob(char const __near *,void const __near *,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncWriteJob *__thiscall CFileAsyncWriteJob::CFileAsyncWriteJob(
        CFileAsyncWriteJob *this,
        const char *pszFilename,
        const void *pData,
        unsigned int nBytes,
        bool bFreeMemory,
        bool bAppend)
{
  const char *v7; // ebx
  char *v8; // eax

  this->m_iRefs = 1;
  v7 = nullptr;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_LOW;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->m_bFreeMemory = bFreeMemory;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CFileAsyncWriteJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncWriteJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pData = pData;
  this->m_nBytes = nBytes;
  this->m_bAppend = bAppend;
  if ( pszFilename != nullptr )
  {
    v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszFilename) + 1);
    if ( v8 != nullptr )
    {
      strcpy(v8, pszFilename);
      v7 = v8;
    }
  }
  ++g_nAsyncWriteJobs;
  this->m_flags |= 4u;
  this->m_pszFilename = v7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016710
// Name: public: CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncAppendFileJob *__thiscall CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(
        CFileAsyncAppendFileJob *this,
        const char *pszAppendTo,
        const char *pszAppendFrom)
{
  char *v4; // eax
  char *v5; // eax
  char *m_pszAppendTo; // [esp-8h] [ebp-14h]

  this->m_iRefs = 1;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncAppendFileJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_LOW;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncAppendFileJob_vtbl *)&CFileAsyncAppendFileJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncAppendFileJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  if ( pszAppendTo != nullptr
    && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszAppendTo) + 1)) != nullptr )
  {
    strcpy(v4, pszAppendTo);
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pszAppendTo = v4;
  if ( pszAppendFrom != nullptr
    && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszAppendFrom) + 1)) != nullptr )
  {
    strcpy(v5, pszAppendFrom);
  }
  else
  {
    v5 = nullptr;
  }
  m_pszAppendTo = (char *)this->m_pszAppendTo;
  this->m_pszAppendFrom = v5;
  V_FixSlashes(pname: m_pszAppendTo, separator: 92);
  V_FixSlashes(pname: (char *)this->m_pszAppendFrom, separator: 92);
  ++g_nAsyncWriteJobs;
  this->m_flags |= 4u;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016840
// Name: public: virtual int CFileAsyncAppendFileJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncAppendFileJob::DoExecute(CFileAsyncAppendFileJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  CBaseFileSystem *v5; // eax
  const char *m_pszAppendTo; // [esp-8h] [ebp-Ch]
  char *m_pszAppendFrom; // [esp-4h] [ebp-8h]

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  m_pszAppendFrom = (char *)this->m_pszAppendFrom;
  m_pszAppendTo = this->m_pszAppendTo;
  v5 = BaseFileSystem();
  return CBaseFileSystem::SyncAppendFile(
           this: v5,
           pAppendToFileName: m_pszAppendTo,
           pAppendFromFileName: m_pszAppendFrom);
}

//------------------------------------------------------------------------------
// Address: 0x10016900
// Name: public: CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t))
// Source: json
//------------------------------------------------------------------------------
CFileAsyncDirectoryScanJob *__thiscall CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(
        CFileAsyncDirectoryScanJob *this,
        const char *pSearchSpec,
        bool bRecurseDirs,
        void *pContext,
        void (__cdecl *pAddCallback)(void *, char *, char *),
        void (__cdecl *pDoneCallback)(void *, FSAsyncStatus_t))
{
  this->m_iRefs = 1;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncDirectoryScanJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_NORMAL;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_flags = 0;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->m_pCompletionCallback = pDoneCallback;
  this->m_bRecurse = bRecurseDirs;
  this->m_pAddResultCallback = pAddCallback;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncDirectoryScanJob_vtbl *)&CFileAsyncDirectoryScanJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncDirectoryScanJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pContext = pContext;
  _V_strcpy(dest: this->m_SearchSpec, src: pSearchSpec);
  _V_memset(dest: this->m_CurPath, fill: 0, count: 260);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100169A0
// Name: public: virtual char const __near * CFileAsyncDirectoryScanJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileAsyncDirectoryScanJob::Describe(CFileAsyncDirectoryScanJob *this)
{
  return this->m_SearchSpec;
}

//------------------------------------------------------------------------------
// Address: 0x10016A00
// Name: public: void CBaseFileSystem::InitAsync(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseFileSystem::InitAsync(CBaseFileSystem *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  IThreadPool *NewThreadPool; // eax
  char v5; // cl
  IThreadPool *m_pThreadPool; // ecx
  ThreadPoolStartParams_t params; // [esp+4h] [ebp-114h] BYREF

  if ( this->m_pThreadPool == nullptr )
  {
    v3 = _CommandLine(a1: this);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-noasync") != 0 )
    {
      _Msg(a1: "Async I/O disabled from command line\n");
    }
    else
    {
      NewThreadPool = (IThreadPool *)_CreateNewThreadPool(a1: a2);
      params.nThreads = -1;
      params.nStackSize = -1;
      v5 = *((_BYTE *)&params + 272) & 0xFC;
      this->m_pThreadPool = NewThreadPool;
      params.fDistribute = TRS_NONE;
      *((_BYTE *)&params + 272) = v5;
      if ( (v5 & 2) != 0 )
        qmemcpy(params.iAffinityTable, nullptr, sizeof(params.iAffinityTable));
      *((_BYTE *)&params + 272) |= 1u;
      params.iThreadPriority = 0;
      if ( !NewThreadPool->Start_2(this: NewThreadPool, a2: &params) )
      {
        m_pThreadPool = this->m_pThreadPool;
        if ( m_pThreadPool != nullptr )
        {
          m_pThreadPool->Release(this: m_pThreadPool);
          this->m_pThreadPool = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016AD0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncWrite(
        CBaseFileSystem *this,
        const char *pFileName,
        const void *pSrc,
        unsigned int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncWriteJob *v11; // eax
  CFileAsyncWriteJob *v12; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncWriteJob *)operator new(nSize: 0x44u);
  if ( v11 != nullptr )
    v12 = CFileAsyncWriteJob::CFileAsyncWriteJob(
            this: v11,
            pszFilename: pFileName,
            pData: pSrc,
            nBytes: nSrcBytes,
            bFreeMemory,
            bAppend);
  else
    v12 = nullptr;
  if ( v10 )
    CJob::Execute(this: v12);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: v12);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v12;
  else
    v12->Release(this: v12);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10016B90
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncWriteFile(
        CBaseFileSystem *this,
        const char *pFileName,
        CFileAsyncWriteJob_vtbl *pBuff,
        unsigned int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  CBaseFileSystem *v7; // edi
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncWriteJob *v11; // esi

  v7 = this;
  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncWriteJob *)operator new(nSize: 0x48u);
  if ( v11 != nullptr )
  {
    CFileAsyncWriteJob::CFileAsyncWriteJob(
      this: v11,
      pszFilename: pFileName,
      pData: pBuff->AddRef,
      nBytes: nSrcBytes,
      bFreeMemory,
      bAppend);
    v11[1].CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = pBuff;
    v7 = this;
    v11->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CFileAsyncWriteFileJob::`vftable'{for `IRefCounted'};
    v11->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncWriteFileJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  }
  else
  {
    v11 = nullptr;
  }
  if ( v10 )
    CJob::Execute(this: v11);
  else
    v7->m_pThreadPool->AddJob(this: v7->m_pThreadPool, a2: v11);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v11;
  else
    v11->Release(this: v11);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10016C60
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncAppendFile(
        CBaseFileSystem *this,
        const char *pAppendToFileName,
        const char *pAppendFromFileName,
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v6; // al
  bool v7; // bl
  CFileAsyncAppendFileJob *v8; // eax
  CFileAsyncAppendFileJob *appended; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v6 = m_nValue == 0;
  v7 = !v6 || this->m_pThreadPool == nullptr;
  if ( !v6 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v8 = (CFileAsyncAppendFileJob *)operator new(nSize: 0x38u);
  if ( v8 != nullptr )
    appended = CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(
                 this: v8,
                 pszAppendTo: pAppendToFileName,
                 pszAppendFrom: pAppendFromFileName);
  else
    appended = nullptr;
  if ( v7 )
    CJob::Execute(this: appended);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: appended);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)appended;
  else
    appended->Release(this: appended);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10016D10
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncDirectoryScan(
        CBaseFileSystem *this,
        const char *pSearchSpec,
        bool recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncDirectoryScanJob *v11; // eax
  CFileAsyncDirectoryScanJob *v12; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncDirectoryScanJob *)operator new(nSize: 0x248u);
  if ( v11 != nullptr )
    v12 = CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(
            this: v11,
            pSearchSpec,
            bRecurseDirs: recurseFolders,
            pContext,
            pAddCallback: pfnAdd,
            pDoneCallback: pfnDone);
  else
    v12 = nullptr;
  if ( v10 )
    CJob::Execute(this: v12);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: v12);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v12;
  else
    v12->Release(this: v12);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10016FE0
// Name: public: struct AsyncOpenedFile_t __near * CAsyncOpenedFiles::Get(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncOpenedFile_t *__thiscall CAsyncOpenedFiles::Get(CAsyncOpenedFiles *this, FSAsyncFile_t__ *item)
{
  AsyncOpenedFile_t *result; // eax
  DWORD CurrentThreadId; // ecx

  if ( item == (FSAsyncFile_t__ *)0xFFFF )
    return nullptr;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->m_iRefs, 1u);
  result = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017060
// Name: public: void CAsyncOpenedFiles::AddRef(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncOpenedFiles::AddRef(CAsyncOpenedFiles *this, FSAsyncFile_t__ *item)
{
  DWORD CurrentThreadId; // ecx

  if ( item != (FSAsyncFile_t__ *)0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->m_iRefs, 1u);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100170D0
// Name: public: CFileAsyncReadJob::CFileAsyncReadJob(struct FileAsyncRequest_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncReadJob *__thiscall CFileAsyncReadJob::CFileAsyncReadJob(
        CFileAsyncReadJob *this,
        const FileAsyncRequest_t *fromRequest)
{
  int priority; // eax
  char *v3; // ebx
  JobPriority_t v5; // eax
  const char *pszFilename; // edi
  const FileAsyncRequest_t *v7; // eax
  const char *v8; // ecx
  int v9; // eax
  char v10; // dl
  FSAsyncFile_t__ *hSpecificAsyncFile; // eax
  const FileAsyncRequest_t *fromRequesta; // [esp+14h] [ebp+8h]

  priority = fromRequest->priority;
  v3 = nullptr;
  if ( priority != 0 )
    v5 = priority <= 0 ? JP_LOW : JP_HIGH;
  else
    v5 = JP_NORMAL;
  this->m_iRefs = 1;
  this->m_priority = v5;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->FileAsyncRequest_t = *fromRequest;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncReadJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncReadJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pResultData = nullptr;
  this->m_nResultSize = 0;
  this->m_pRealContext = fromRequest->pContext;
  this->m_pfnRealCallback = fromRequest->pfnCallback;
  pszFilename = fromRequest->pszFilename;
  if ( fromRequest->pszFilename != nullptr )
  {
    v7 = (const FileAsyncRequest_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszFilename) + 1);
    fromRequesta = v7;
    if ( v7 != nullptr )
    {
      v8 = pszFilename;
      v9 = (char *)v7 - pszFilename;
      do
      {
        v10 = *v8;
        v8[v9] = *v8;
        ++v8;
      }
      while ( v10 != 0 );
      v3 = (char *)fromRequesta;
    }
  }
  this->pszFilename = v3;
  V_FixSlashes(pname: v3, separator: 92);
  hSpecificAsyncFile = this->hSpecificAsyncFile;
  this->pContext = this;
  this->pfnCallback = CFileAsyncReadJob::InterceptCallback;
  if ( hSpecificAsyncFile != (FSAsyncFile_t__ *)0xFFFF )
    CAsyncOpenedFiles::AddRef(this: &g_AsyncOpenedFiles, item: hSpecificAsyncFile);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017220
// Name: public: virtual char const __near * CFileAsyncReadJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileAsyncReadJob::Describe(CFileAsyncReadJob *this)
{
  return this->pszFilename;
}

//------------------------------------------------------------------------------
// Address: 0x10017230
// Name: public: virtual int CFileAsyncReadJob::GetResult(void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncReadJob::GetResult(CFileAsyncReadJob *this, void **ppData, int *pSize)
{
  void *m_pResultData; // eax

  m_pResultData = this->m_pResultData;
  if ( m_pResultData != nullptr )
  {
    *ppData = m_pResultData;
    *pSize = this->m_nResultSize;
  }
  return this->m_status;
}

//------------------------------------------------------------------------------
// Address: 0x10017EB0
// Name: public: virtual void CFileAsyncWriteFileJob::DoCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileAsyncWriteFileJob::DoCleanup(CFileAsyncWriteFileJob *this)
{
  CUtlBuffer *m_pBuffer; // esi

  m_pBuffer = (CUtlBuffer *)this->m_pBuffer;
  if ( m_pBuffer != nullptr && this->m_bFreeMemory )
  {
    if ( m_pBuffer->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pBuffer->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBuffer->m_Memory.m_pMemory);
        m_pBuffer->m_Memory.m_pMemory = nullptr;
      }
      m_pBuffer->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_pBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018240
// Name: public: void CAsyncOpenedFiles::Release(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncOpenedFiles::Release(CAsyncOpenedFiles *this, int item)
{
  DWORD CurrentThreadId; // ecx
  AsyncOpenedFile_t *elem; // ecx
  CBaseFileSystem *v5; // eax
  AsyncOpenedFile_t *v6; // ecx

  if ( item != 0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    elem = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
    if ( _InterlockedDecrement(&elem->m_iRefs) == 0 )
    {
      elem->OnFinalRelease(this: elem);
      if ( this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->hFile != nullptr )
      {
        v5 = BaseFileSystem();
        v5->Close(
          this: &v5->IBaseFileSystem,
          a2: this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->hFile);
      }
      v6 = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
      if ( v6 != nullptr )
        ((void (__thiscall *)(AsyncOpenedFile_t *, int))v6->dtr_CRefCountServiceBase<0,CRefMT>)(a1: v6, a2: 1);
      free(pMem: (void *)this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.key);
      if ( (_WORD)item != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_map.m_Tree,
          elem: item);
        this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Left = item;
        this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Right = this->m_map.m_Tree.m_FirstFree;
        this->m_map.m_Tree.m_FirstFree = item;
        --this->m_map.m_Tree.m_NumElements;
      }
    }
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100183B0
// Name: public: virtual int CFileAsyncFileSizeJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncFileSizeJob::DoExecute(CFileAsyncFileSizeJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  FileAsyncRequest_t *v5; // esi
  CBaseFileSystem *v6; // edi
  int v7; // eax

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  if ( this != nullptr )
    v5 = &this->FileAsyncRequest_t;
  else
    v5 = nullptr;
  v6 = BaseFileSystem();
  v7 = v6->Size(this: &v6->IBaseFileSystem, a2: v5->pszFilename, a3: v5->pszPathID);
  CBaseFileSystem::DoAsyncCallback(
    this: v6,
    request: v5,
    pData: nullptr,
    nBytesRead: v7,
    result: (FSAsyncStatus_t)((v7 != 0) - 1));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018450
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncReadMultipleCreditAlloc(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **phControls)
{
  int m_nValue; // eax
  bool v7; // al
  const FileAsyncRequest_t *v8; // edi
  int i; // ebx
  CFileAsyncReadJob *v10; // eax
  CFileAsyncReadJob *Job; // esi
  CFileAsyncReadJob *v12; // eax
  char bSynchronous_3; // [esp+Fh] [ebp+Bh]

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue == 0;
  v8 = pRequests;
  if ( !v7 || (pRequests->flags & 4) != 0 || (bSynchronous_3 = 0, this->m_pThreadPool == nullptr) )
    bSynchronous_3 = 1;
  if ( !v7 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  for ( i = 0; i < nRequests; ++i )
  {
    if ( v8->nBytes < 0 )
    {
      v12 = (CFileAsyncReadJob *)operator new(nSize: 0x6Cu);
      Job = v12;
      if ( v12 == nullptr )
      {
LABEL_16:
        Job = nullptr;
        goto LABEL_17;
      }
      CFileAsyncReadJob::CFileAsyncReadJob(this: v12, fromRequest: v8);
      Job->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncFileSizeJob::`vftable'{for `IRefCounted'};
      Job->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncFileSizeJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    }
    else
    {
      v10 = (CFileAsyncReadJob *)operator new(nSize: 0x6Cu);
      if ( v10 == nullptr )
        goto LABEL_16;
      Job = CFileAsyncReadJob::CFileAsyncReadJob(this: v10, fromRequest: v8);
    }
LABEL_17:
    if ( bSynchronous_3 != 0 )
      CJob::Execute(this: Job);
    else
      this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: Job);
    if ( phControls != nullptr )
      phControls[i] = (FSAsyncControl_t__ *)Job;
    else
      Job->Release(this: Job);
    ++v8;
  }
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10018550
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncRead(struct FileAsyncRequest_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseFileSystem::SyncRead@<eax>(
        CBaseFileSystem *this@<ecx>,
        int a2@<edi>,
        const FileAsyncRequest_t *request)
{
  FSAsyncFile_t__ *hSpecificAsyncFile; // eax
  AsyncOpenedFile_t *v6; // eax
  AsyncOpenedFile_t *v7; // edi
  void *v8; // eax
  signed int nBytes; // eax
  unsigned int Size; // edi
  void *(__cdecl *pfnAlloc)(const char *, unsigned int); // eax
  void *v12; // eax
  int nOffset; // eax
  int v14; // edi
  int iPrevPriority; // [esp+8h] [ebp-14h]
  unsigned int nOffsetAlign; // [esp+Ch] [ebp-10h] BYREF
  AsyncOpenedFile_t *pHeldFile; // [esp+10h] [ebp-Ch]
  void *pDest; // [esp+14h] [ebp-8h]
  int nBytesToRead; // [esp+18h] [ebp-4h]
  void *hFile; // [esp+24h] [ebp+8h]
  FSAsyncStatus_t hFilea; // [esp+24h] [ebp+8h]

  if ( request->nBytes < 0 || request->nOffset < 0 )
  {
    _Msg(a1: "Invalid async read of %s\n", request->pszFilename);
    CBaseFileSystem::DoAsyncCallback(this, request, pData: nullptr, nBytesRead: 0, result: FSASYNC_ERR_FILEOPEN);
    return -1;
  }
  hSpecificAsyncFile = request->hSpecificAsyncFile;
  if ( hSpecificAsyncFile == (FSAsyncFile_t__ *)0xFFFF )
  {
    pHeldFile = nullptr;
    v7 = nullptr;
    goto LABEL_8;
  }
  v6 = CAsyncOpenedFiles::Get(this: &g_AsyncOpenedFiles, item: hSpecificAsyncFile);
  v7 = v6;
  pHeldFile = v6;
  if ( v6 == nullptr || v6->hFile == nullptr )
  {
LABEL_8:
    v8 = this->OpenEx(this, a2: request->pszFilename, a3: "rb", a4: 0, a5: request->pszPathID, a6: 0);
    hFile = v8;
    if ( v7 != nullptr )
      v7->hFile = v8;
    goto LABEL_10;
  }
  hFile = v6->hFile;
LABEL_10:
  if ( hFile != nullptr )
  {
    nBytes = request->nBytes;
    if ( nBytes != 0 )
    {
      nBytesToRead = request->nBytes;
    }
    else
    {
      nBytes = this->Size_2(this: &this->IBaseFileSystem, a2: hFile) - request->nOffset;
      nBytesToRead = nBytes;
    }
    if ( nBytes < 0 )
    {
      nBytesToRead = 0;
      nBytes = 0;
    }
    if ( request->pData != nullptr )
    {
      pDest = request->pData;
      Size = nBytes;
    }
    else
    {
      Size = nBytes + ((request->flags & 8) != 0);
      if ( this->GetOptimalIOConstraints(this, a2: hFile, a3: &nOffsetAlign, a4: nullptr, a5: nullptr)
        && request->nOffset % nOffsetAlign == 0 )
      {
        Size = IFileSystem::GetOptimalReadSize(this, hFile, nLogicalSize: Size);
      }
      pfnAlloc = request->pfnAlloc;
      if ( pfnAlloc != nullptr )
        v12 = pfnAlloc(a1: request->pszFilename, a2: Size);
      else
        v12 = this->AllocOptimalReadBuffer(this, a2: hFile, a3: Size, a4: request->nOffset);
      pDest = v12;
    }
    ((void (__thiscall *)(CBaseFileSystem *, void *, _DWORD, int))this->SetBufferSize)(
      a1: this,
      a2: hFile,
      a3: 0,
      a4: a2);
    nOffset = request->nOffset;
    if ( nOffset > 0 )
      this->Seek(this: &this->IBaseFileSystem, a2: hFile, a3: nOffset, a4: FILESYSTEM_SEEK_HEAD);
    iPrevPriority = _ThreadGetPriority(a1: 0);
    if ( iPrevPriority < 2 )
      _ThreadSetPriority(a1: 0, a2: 2);
    v14 = ((int (__thiscall *)(CBaseFileSystem *, void *, unsigned int, int))this->ReadEx)(
            a1: this,
            a2: pDest,
            a3: Size,
            a4: nBytesToRead);
    if ( iPrevPriority < 2 )
      _ThreadSetPriority(a1: 0, a2: iPrevPriority);
    if ( pHeldFile == nullptr )
      this->Close(this: &this->IBaseFileSystem, a2: hFile);
    if ( (request->flags & 8) != 0 )
      *((_BYTE *)pDest + v14) = 0;
    if ( v14 != 0 || (hFilea = FSASYNC_ERR_READING, nBytesToRead == 0) )
      hFilea = FSASYNC_OK;
    if ( v14 >= nBytesToRead )
      v14 = nBytesToRead;
    CBaseFileSystem::DoAsyncCallback(this, request, pData: pDest, nBytesRead: v14, result: hFilea);
    v7 = pHeldFile;
  }
  else
  {
    CBaseFileSystem::DoAsyncCallback(this, request, pData: nullptr, nBytesRead: 0, result: FSASYNC_ERR_FILEOPEN);
    hFilea = FSASYNC_ERR_FILEOPEN;
  }
  if ( v7 != nullptr )
    CAsyncOpenedFiles::Release(this: &g_AsyncOpenedFiles, item: (int)request->hSpecificAsyncFile);
  if ( this->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this, accesstype: "async", fullpath: request->pszFilename, options: defaultValue);
  return hFilea;
}

//------------------------------------------------------------------------------
// Address: 0x100187D0
// Name: public: virtual int CFileAsyncReadJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CFileAsyncReadJob::DoExecute@<eax>(CFileAsyncReadJob *this@<ecx>, int a2@<edx>, int a3@<edi>)
{
  int m_nValue; // ecx
  int v5; // eax
  CBaseFileSystem *v6; // eax

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v5 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v5);
  }
  v6 = BaseFileSystem();
  if ( this != nullptr )
    return CBaseFileSystem::SyncRead(this: v6, a2: a3, request: &this->FileAsyncRequest_t);
  else
    return CBaseFileSystem::SyncRead(this: v6, a2: a3, request: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100B2900
// Name: _dynamic_initializer_for__CBaseFileSystem::m_ExcludeFilePaths__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_ExcludeFilePaths__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2910
// Name: _dynamic_initializer_for__CBaseFileSystem::m_DLCContents__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_DLCContents__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2920
// Name: _dynamic_initializer_for__CBaseFileSystem::m_CorruptDLC__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_CorruptDLC__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3AB0
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CBaseFileSystem::m_CorruptDLC);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B00
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CBaseFileSystem::m_ExcludeFilePaths);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B10
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CBaseFileSystem::m_DLCContents);
}

//------------------------------------------------------------------------------
// Address: 0x100B2930
// Name: _dynamic_initializer_for__g_UpdateZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UpdateZipBuffer__()
{
  CUtlBuffer::CUtlBuffer(this: &g_UpdateZipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_UpdateZipBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2950
// Name: _dynamic_initializer_for__g_XLSPPatchZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_XLSPPatchZipBuffer__()
{
  CUtlBuffer::CUtlBuffer(this: &g_XLSPPatchZipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2970
// Name: _dynamic_initializer_for__s_IoStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_IoStats__()
{
  s_IoStats.m_nNumberOfFileSeeks.m_value = 0;
  s_IoStats.m_nTimeInFileSeek.m_value = 0;
  s_IoStats.m_nNumberOfFileReads.m_value = 0;
  s_IoStats.m_nTimeInFileRead.m_value = 0;
  s_IoStats.m_nFileReadTotalSize.m_value = 0;
  s_IoStats.m_nNumberOfFileOpens.m_value = 0;
  return atexit(func: dynamic_atexit_destructor_for__s_IoStats__);
}

//------------------------------------------------------------------------------
// Address: 0x100B29A0
// Name: _dynamic_initializer_for__g_pszReadFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pszReadFilename__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_pszReadFilename);
  return atexit(func: dynamic_atexit_destructor_for__g_pszReadFilename__);
}

//------------------------------------------------------------------------------
// Address: 0x100B29C0
// Name: _dynamic_initializer_for__fs_dump_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_dump_open_duplicate_times_command__()
{
  ConCommand::ConCommand(
    this: &fs_dump_open_duplicate_times_command,
    pName: "fs_dump_open_duplicate_times",
    callback: fs_dump_open_duplicate_times,
    pHelpString: "Set fs_report_long_reads 1 before loading to use this. Prints a list of files that were opened more than once and ~h"
    "ow long was spent reading from them.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B29F0
// Name: _dynamic_initializer_for__fs_clear_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_clear_open_duplicate_times_command__()
{
  ConCommand::ConCommand(
    this: &fs_clear_open_duplicate_times_command,
    pName: "fs_clear_open_duplicate_times",
    callback: fs_clear_open_duplicate_times,
    pHelpString: "Clear the list of files that have been opened.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2A20
// Name: _dynamic_initializer_for__fs_fios_flush_cache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_flush_cache_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_flush_cache_command,
    pName: "fs_fios_flush_cache",
    callback: (void (__cdecl *)())CSteamApplication::PostShutdown,
    pHelpString: "Flushes the FIOS HDD cache.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_flush_cache_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2A50
// Name: _dynamic_initializer_for__fs_fios_print_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_print_prefetches_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_print_prefetches_command,
    pName: "fs_fios_print_prefetches",
    callback: (void (__cdecl *)())CSteamApplication::PostShutdown,
    pHelpString: "Displays all the prefetches currently in progress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2A80
// Name: _dynamic_initializer_for__fs_fios_prefetch_file_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_prefetch_file_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_prefetch_file_command,
    pName: "fs_fios_prefetch_file",
    callback: (void (__cdecl *)())CSteamApplication::PostShutdown,
    pHelpString: "Prefetches a file: </PS3_GAME/USRDIR/filename.bin>.\nThe preftech is medium priority and persistent.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2AB0
// Name: _dynamic_initializer_for__fs_fios_prefetch_file_in_pack_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_prefetch_file_in_pack_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_prefetch_file_in_pack_command,
    pName: "fs_fios_prefetch_file_in_pack",
    callback: (void (__cdecl *)())CSteamApplication::PostShutdown,
    pHelpString: "Prefetches a file in a pack: <portal2/models/container_ride/fineDebris_part5.ani>.\n"
    "The preftech is medium priority and non-persistent.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2AE0
// Name: _dynamic_initializer_for__fs_fios_cancel_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_cancel_prefetches_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_cancel_prefetches_command,
    pName: "fs_fios_cancel_prefetches",
    callback: (void (__cdecl *)())CSteamApplication::PostShutdown,
    pHelpString: "Cancels all the prefetches in progress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3AC0
// Name: _dynamic_atexit_destructor_for__g_UpdateZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UpdateZipBuffer__()
{
  if ( g_UpdateZipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_UpdateZipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_UpdateZipBuffer.m_Memory.m_pMemory);
      g_UpdateZipBuffer.m_Memory.m_pMemory = nullptr;
    }
    g_UpdateZipBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace dedicated

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x100056C0
// Name: public: virtual bool CFileAsyncAppendFileJob::IsWrite(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileAsyncAppendFileJob::IsWrite(ConCommand *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010180
// Name: public: virtual void (*CBaseFileSystem::GetDirtyDiskReportFunc(void))(void)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__thiscall CBaseFileSystem::GetDirtyDiskReportFunc(CBaseFileSystem *this))()
{
  return this->m_DirtyDiskReportFunc;
}

//------------------------------------------------------------------------------
// Address: 0x10011270
// Name: async_suspend
// Source: json
//------------------------------------------------------------------------------
void __cdecl async_suspend()
{
  CBaseFileSystem *v0; // eax

  v0 = BaseFileSystem();
  v0->AsyncSuspend(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10011290
// Name: async_resume
// Source: json
//------------------------------------------------------------------------------
void __cdecl async_resume()
{
  CBaseFileSystem *v0; // eax

  v0 = BaseFileSystem();
  v0->AsyncResume(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100112B0
// Name: public: static void CFileAsyncReadJob::InterceptCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFileAsyncReadJob::InterceptCallback(
        const FileAsyncRequest_t *request,
        int nBytesRead,
        FSAsyncStatus_t result)
{
  void *pContext; // eax
  void (__cdecl *v4)(const FileAsyncRequest_t *, int, FSAsyncStatus_t); // edx

  pContext = request->pContext;
  if ( result == FSASYNC_OK && (request->flags & 2) == 0 )
  {
    *((_DWORD *)pContext + 23) = request->pData;
    *((_DWORD *)pContext + 24) = nBytesRead;
  }
  v4 = *((void (__cdecl **)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))pContext + 26);
  if ( v4 != nullptr )
  {
    request->pfnCallback = v4;
    request->pContext = *((void **)pContext + 25);
    (*((void (__cdecl **)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))pContext + 26))(
      a1: request,
      a2: nBytesRead,
      a3: result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011300
// Name: public: virtual int CFileAsyncDirectoryScanJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncDirectoryScanJob::DoExecute(CFileAsyncDirectoryScanJob *this)
{
  char *m_SearchSpec; // ebx
  char *m_CurPath; // edi
  char *i; // eax
  int findSession; // [esp+Ch] [ebp-4h] BYREF

  m_SearchSpec = this->m_SearchSpec;
  m_CurPath = this->m_CurPath;
  findSession = -1;
  _V_strcpy(dest: this->m_CurPath, src: this->m_SearchSpec);
  V_StripFilename(path: m_CurPath);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: m_SearchSpec, a3: &findSession);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findSession) )
  {
    this->m_pAddResultCallback(a1: this->m_pContext, a2: m_CurPath, a3: i);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findSession);
  this->m_pCompletionCallback(a1: this->m_pContext, a2: FSASYNC_OK);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011390
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncReadMultiple(struct FileAsyncRequest_t const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncReadMultiple(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        FSAsyncControl_t__ **phControls)
{
  return this->AsyncReadMultipleCreditAlloc(this, a2: pRequests, a3: nRequests, a4: nullptr, a5: 0, a6: phControls);
}

//------------------------------------------------------------------------------
// Address: 0x100113C0
// Name: AsyncWriteJobFilter
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AsyncWriteJobFilter(CJob *pJob)
{
  void *v1; // eax

  v1 = __RTDynamicCast(
         inptr: pJob,
         VfDelta: 0,
         SrcType: &CJob `RTTI Type Descriptor',
         TargetType: &CFileAsyncJob `RTTI Type Descriptor',
         isReference: 0);
  return v1 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v1 + 28))(a1: v1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011400
// Name: public: virtual bool CBaseFileSystem::AsyncSuspend(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFileSystem::AsyncSuspend(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->SuspendExecution(this: this->m_pThreadPool);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011420
// Name: public: virtual bool CBaseFileSystem::AsyncResume(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseFileSystem::AsyncResume(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr )
    this->m_pThreadPool->ResumeExecution(this: this->m_pThreadPool);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011440
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncBeginRead(char const __near *,struct FSAsyncFile_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncBeginRead(
        CBaseFileSystem *this,
        const char *pszFile,
        FSAsyncFile_t__ **phFile)
{
  *phFile = (FSAsyncFile_t__ *)0xFFFF;
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10011470
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncGetResult(struct FSAsyncControl_t__ __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncGetResult(
        CBaseFileSystem *this,
        FSAsyncControl_t__ *hControl,
        void **ppData,
        int *pSize)
{
  int v5; // eax

  if ( ppData != nullptr )
    *ppData = nullptr;
  if ( pSize != nullptr )
    *pSize = 0;
  if ( hControl == nullptr )
    return FSASYNC_ERR_FAILURE;
  v5 = *((_DWORD *)hControl + 3);
  if ( v5 == 1 || v5 == 2 || v5 == 4 )
    return FSASYNC_STATUS_PENDING;
  else
    return (*(FSAsyncStatus_t (__stdcall **)(void **, int *))(*(_DWORD *)hControl + 24))(a1: ppData, a2: pSize);
}

//------------------------------------------------------------------------------
// Address: 0x10011660
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncAppendFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::SyncAppendFile(
        CBaseFileSystem *this,
        const char *pAppendToFileName,
        char *pAppendFromFileName)
{
  CBaseFileSystem *v3; // ebx
  int v4; // esi
  int v5; // edi
  int v6; // edi
  IBaseFileSystem *v7; // esi
  int v8; // edi
  int v9; // ebx
  FSAsyncStatus_t v12; // [esp+10h] [ebp-Ch]
  void *hDestFile; // [esp+14h] [ebp-8h]
  void *hSourceFile; // [esp+18h] [ebp-4h]
  char *buf; // [esp+28h] [ebp+Ch]

  v3 = this;
  v4 = ((int (__stdcall *)(const char *, const char *, _DWORD, _DWORD, _DWORD))this->OpenEx)(
         a1: pAppendToFileName,
         a2: "ab+",
         a3: 0,
         a4: 0,
         a5: 0);
  v5 = -5;
  hDestFile = (void *)v4;
  v12 = FSASYNC_ERR_FAILURE;
  if ( v4 != 0 )
  {
    v3->SetBufferSize(this: v3, a2: (void *)v4, a3: 0);
    v6 = (int)v3->OpenEx(this: v3, a2: pAppendFromFileName, a3: "rb", a4: 0, a5: nullptr, a6: nullptr);
    hSourceFile = (void *)v6;
    if ( v6 != 0 )
    {
      v3->SetBufferSize(this: v3, a2: (void *)v6, a3: 0);
      v7 = &v3->IBaseFileSystem;
      v8 = v3->Size_2(this: &v3->IBaseFileSystem, a2: (void *)v6);
      buf = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x20000);
      if ( v8 > 0 )
      {
        do
        {
          v9 = 0x20000;
          if ( v8 <= 0x20000 )
            v9 = v8;
          v7->Read(this: v7, a2: buf, a3: v9, a4: hSourceFile);
          v7->Write(this: v7, a2: buf, a3: v9, a4: hDestFile);
          v8 -= v9;
        }
        while ( v8 > 0 );
        v3 = this;
      }
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf);
      v7->Close(this: v7, a2: hSourceFile);
      v4 = (int)hDestFile;
      v12 = FSASYNC_OK;
    }
    v3->Close(this: &v3->IBaseFileSystem, a2: (void *)v4);
    v5 = v12;
  }
  if ( v3->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this: v3, accesstype: "asyncappend", fullpath: pAppendToFileName, options: setName);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100117B0
// Name: public: int CJob::Execute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Execute(CJob *this)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int (__thiscall *DoExecute)(CJob *); // edx
  int v6; // eax
  int m_status; // ebx

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        DoExecute = this->DoExecute;
        this->m_status = 2;
        v6 = DoExecute(this);
        this->m_status = v6;
        m_status = v6;
        this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011880
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011950
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10011960
// Name: public: virtual int CFileAsyncJob::GetResult(void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncJob::GetResult(CFileAsyncJob *this, void **ppData, int *pSize)
{
  *ppData = nullptr;
  *pSize = 0;
  return this->m_status;
}

//------------------------------------------------------------------------------
// Address: 0x10011980
// Name: public: virtual char const __near * CFileAsyncWriteJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileAsyncWriteJob::Describe(CFileAsyncWriteJob *this)
{
  return this->m_pszFilename;
}

//------------------------------------------------------------------------------
// Address: 0x10011990
// Name: public: virtual void CFileAsyncWriteJob::DoCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileAsyncWriteJob::DoCleanup(CFileAsyncWriteJob *this)
{
  if ( this->m_pData != nullptr && this->m_bFreeMemory )
    free(pMem: (void *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x100119B0
// Name: public: virtual int CFileAsyncWriteJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __fastcall CFileAsyncWriteJob::DoExecute(CFileAsyncWriteJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  CBaseFileSystem *v5; // eax
  const char *m_pszFilename; // [esp-14h] [ebp-18h]
  const void *m_pData; // [esp-10h] [ebp-14h]
  int m_nBytes; // [esp-Ch] [ebp-10h]
  bool m_bAppend; // [esp-4h] [ebp-8h]

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  m_bAppend = this->m_bAppend;
  m_nBytes = this->m_nBytes;
  m_pData = this->m_pData;
  m_pszFilename = this->m_pszFilename;
  v5 = BaseFileSystem();
  return CBaseFileSystem::SyncWrite(
           this: v5,
           pszFilename: m_pszFilename,
           pSrc: m_pData,
           nSrcBytes: m_nBytes,
           bFreeMemory: false,
           bAppend: m_bAppend);
}

//------------------------------------------------------------------------------
// Address: 0x10011A80
// Name: public: virtual void CBaseFileSystem::AsyncFinishAll(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncFinishAll(CBaseFileSystem *this, int iToPriority)
{
  JobPriority_t v3; // eax

  if ( this->m_pThreadPool != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
    if ( iToPriority != 0 )
      v3 = iToPriority <= 0 ? JP_LOW : JP_HIGH;
    else
      v3 = JP_NORMAL;
    this->m_pThreadPool->ExecuteToPriority(this: this->m_pThreadPool, a2: v3, a3: nullptr);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011AE0
// Name: public: virtual void CBaseFileSystem::AsyncFinishAllWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::AsyncFinishAllWrites(CBaseFileSystem *this)
{
  if ( this->m_pThreadPool != nullptr && g_nAsyncWriteJobs != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
    this->m_pThreadPool->ExecuteToPriority(
      this: this->m_pThreadPool,
      a2: JP_LOW,
      a3: (bool (__cdecl *)(CJob *))AsyncWriteJobFilter);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_AsyncFinishMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011B70
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncAbort(struct FSAsyncControl_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseFileSystem::AsyncAbort(CBaseFileSystem *this, FSAsyncControl_t__ *hControl)
{
  if ( hControl != nullptr )
    return CJob::Abort(this: (CJob *)hControl, bDiscard: true);
  else
    return -5;
}

//------------------------------------------------------------------------------
// Address: 0x10011B90
// Name: public: void CBaseFileSystem::DoAsyncCallback(struct FileAsyncRequest_t const __near &,void __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFileSystem::DoAsyncCallback(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *request,
        void *pData,
        int nBytesRead,
        FSAsyncStatus_t result)
{
  bool v5; // zf
  CThreadFastMutex *p_m_AsyncCallbackMutex; // edi
  DWORD CurrentThreadId; // ecx
  void *v8; // ebx
  void *(__cdecl *pfnAlloc)(const char *, unsigned int); // eax
  __int64 v10; // xmm0_8
  FileAsyncRequest_t temp; // [esp+4h] [ebp-30h] BYREF
  void *pDataToFree; // [esp+30h] [ebp-4h]

  v5 = request->pfnCallback == nullptr;
  pDataToFree = nullptr;
  if ( v5 )
    return;
  p_m_AsyncCallbackMutex = &this->m_AsyncCallbackMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncCallbackMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncCallbackMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncCallbackMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncCallbackMutex->m_depth;
  }
  v8 = pData;
  if ( pData == nullptr || request->pData == pData )
  {
    request->pfnCallback(a1: request, a2: nBytesRead, a3: result);
    if ( (request->flags & 2) != 0 )
    {
      v8 = request->pData;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  pfnAlloc = request->pfnAlloc;
  *(_QWORD *)&temp.pszFilename = *(_QWORD *)&request->pszFilename;
  *(_QWORD *)&temp.nOffset = *(_QWORD *)&request->nOffset;
  *(_QWORD *)&temp.pfnCallback = *(_QWORD *)&request->pfnCallback;
  v10 = *(_QWORD *)&request->priority;
  temp.pfnAlloc = pfnAlloc;
  *(_QWORD *)&temp.priority = v10;
  *(_QWORD *)&temp.pszPathID = *(_QWORD *)&request->pszPathID;
  temp.pData = pData;
  temp.pfnCallback(a1: &temp, a2: nBytesRead, a3: result);
  if ( (request->flags & 1) != 0 )
LABEL_9:
    v8 = pDataToFree;
LABEL_10:
  v5 = p_m_AsyncCallbackMutex->m_depth-- == 1;
  if ( v5 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncCallbackMutex, 0);
  if ( v8 != nullptr )
    free(pMem: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10011CA0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011D30
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x10011D80
// Name: public: CFileAsyncWriteJob::CFileAsyncWriteJob(char const __near *,void const __near *,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncWriteJob *__thiscall CFileAsyncWriteJob::CFileAsyncWriteJob(
        CFileAsyncWriteJob *this,
        const char *pszFilename,
        const void *pData,
        unsigned int nBytes,
        bool bFreeMemory,
        bool bAppend)
{
  const char *v7; // ebx
  char *v8; // eax

  this->m_iRefs = 1;
  v7 = nullptr;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_LOW;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->m_bFreeMemory = bFreeMemory;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CFileAsyncWriteJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncWriteJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pData = pData;
  this->m_nBytes = nBytes;
  this->m_bAppend = bAppend;
  if ( pszFilename != nullptr )
  {
    v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszFilename) + 1);
    if ( v8 != nullptr )
    {
      strcpy(v8, pszFilename);
      v7 = v8;
    }
  }
  ++g_nAsyncWriteJobs;
  this->m_flags |= 4u;
  this->m_pszFilename = v7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011EB0
// Name: public: CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncAppendFileJob *__thiscall CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(
        CFileAsyncAppendFileJob *this,
        const char *pszAppendTo,
        const char *pszAppendFrom)
{
  char *v4; // eax
  char *v5; // eax
  char *m_pszAppendTo; // [esp-8h] [ebp-14h]

  this->m_iRefs = 1;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncAppendFileJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_LOW;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncAppendFileJob_vtbl *)&CFileAsyncAppendFileJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncAppendFileJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  if ( pszAppendTo != nullptr
    && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszAppendTo) + 1)) != nullptr )
  {
    strcpy(v4, pszAppendTo);
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pszAppendTo = v4;
  if ( pszAppendFrom != nullptr
    && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszAppendFrom) + 1)) != nullptr )
  {
    strcpy(v5, pszAppendFrom);
  }
  else
  {
    v5 = nullptr;
  }
  m_pszAppendTo = (char *)this->m_pszAppendTo;
  this->m_pszAppendFrom = v5;
  V_FixSlashes(pname: m_pszAppendTo, separator: 92);
  V_FixSlashes(pname: (char *)this->m_pszAppendFrom, separator: 92);
  ++g_nAsyncWriteJobs;
  this->m_flags |= 4u;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011FF0
// Name: public: virtual int CFileAsyncAppendFileJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncAppendFileJob::DoExecute(CFileAsyncAppendFileJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  CBaseFileSystem *v5; // eax
  const char *m_pszAppendTo; // [esp-8h] [ebp-Ch]
  char *m_pszAppendFrom; // [esp-4h] [ebp-8h]

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  m_pszAppendFrom = (char *)this->m_pszAppendFrom;
  m_pszAppendTo = this->m_pszAppendTo;
  v5 = BaseFileSystem();
  return CBaseFileSystem::SyncAppendFile(
           this: v5,
           pAppendToFileName: m_pszAppendTo,
           pAppendFromFileName: m_pszAppendFrom);
}

//------------------------------------------------------------------------------
// Address: 0x100120B0
// Name: public: CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t))
// Source: json
//------------------------------------------------------------------------------
CFileAsyncDirectoryScanJob *__thiscall CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(
        CFileAsyncDirectoryScanJob *this,
        const char *pSearchSpec,
        bool bRecurseDirs,
        void *pContext,
        void (__cdecl *pAddCallback)(void *, char *, char *),
        void (__cdecl *pDoneCallback)(void *, FSAsyncStatus_t))
{
  this->m_iRefs = 1;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncDirectoryScanJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_NORMAL;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_flags = 0;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->m_pCompletionCallback = pDoneCallback;
  this->m_bRecurse = bRecurseDirs;
  this->m_pAddResultCallback = pAddCallback;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncDirectoryScanJob_vtbl *)&CFileAsyncDirectoryScanJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncDirectoryScanJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pContext = pContext;
  _V_strcpy(dest: this->m_SearchSpec, src: pSearchSpec);
  _V_memset(dest: this->m_CurPath, fill: 0, count: 260);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012150
// Name: public: virtual char const __near * CFileAsyncDirectoryScanJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileAsyncDirectoryScanJob::Describe(CFileAsyncDirectoryScanJob *this)
{
  return this->m_SearchSpec;
}

//------------------------------------------------------------------------------
// Address: 0x100121C0
// Name: public: void CBaseFileSystem::InitAsync(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseFileSystem::InitAsync(CBaseFileSystem *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  IThreadPool *NewThreadPool; // eax
  char v5; // cl
  IThreadPool *m_pThreadPool; // ecx
  ThreadPoolStartParams_t params; // [esp+4h] [ebp-114h] BYREF

  if ( this->m_pThreadPool == nullptr )
  {
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-noasync") != 0 )
    {
      _Msg(a1: "Async I/O disabled from command line\n");
    }
    else
    {
      NewThreadPool = (IThreadPool *)_CreateNewThreadPool(a1: a2);
      params.nThreads = -1;
      params.nStackSize = -1;
      v5 = *((_BYTE *)&params + 272) & 0xFC;
      this->m_pThreadPool = NewThreadPool;
      params.fDistribute = TRS_NONE;
      *((_BYTE *)&params + 272) = v5;
      if ( (v5 & 2) != 0 )
        qmemcpy(params.iAffinityTable, nullptr, sizeof(params.iAffinityTable));
      *((_BYTE *)&params + 272) |= 1u;
      params.iThreadPriority = 0;
      if ( !NewThreadPool->Start_2(this: NewThreadPool, a2: &params) )
      {
        m_pThreadPool = this->m_pThreadPool;
        if ( m_pThreadPool != nullptr )
        {
          m_pThreadPool->Release(this: m_pThreadPool);
          this->m_pThreadPool = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012290
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncWrite(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncWrite(
        CBaseFileSystem *this,
        const char *pFileName,
        const void *pSrc,
        unsigned int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncWriteJob *v11; // eax
  CFileAsyncWriteJob *v12; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncWriteJob *)operator new(nSize: 0x44u);
  if ( v11 != nullptr )
    v12 = CFileAsyncWriteJob::CFileAsyncWriteJob(
            this: v11,
            pszFilename: pFileName,
            pData: pSrc,
            nBytes: nSrcBytes,
            bFreeMemory,
            bAppend);
  else
    v12 = nullptr;
  if ( v10 )
    CJob::Execute(this: v12);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: v12);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v12;
  else
    v12->Release(this: v12);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10012350
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncWriteFile(char const __near *,class CUtlBuffer const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncWriteFile(
        CBaseFileSystem *this,
        const char *pFileName,
        CFileAsyncWriteJob_vtbl *pBuff,
        unsigned int nSrcBytes,
        bool bFreeMemory,
        bool bAppend,
        FSAsyncControl_t__ **pControl)
{
  CBaseFileSystem *v7; // edi
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncWriteJob *v11; // esi

  v7 = this;
  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncWriteJob *)operator new(nSize: 0x48u);
  if ( v11 != nullptr )
  {
    CFileAsyncWriteJob::CFileAsyncWriteJob(
      this: v11,
      pszFilename: pFileName,
      pData: pBuff->AddRef,
      nBytes: nSrcBytes,
      bFreeMemory,
      bAppend);
    v11[1].CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = pBuff;
    v7 = this;
    v11->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncWriteJob_vtbl *)&CFileAsyncWriteFileJob::`vftable'{for `IRefCounted'};
    v11->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncWriteFileJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  }
  else
  {
    v11 = nullptr;
  }
  if ( v10 )
    CJob::Execute(this: v11);
  else
    v7->m_pThreadPool->AddJob(this: v7->m_pThreadPool, a2: v11);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v11;
  else
    v11->Release(this: v11);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10012420
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncAppendFile(char const __near *,char const __near *,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncAppendFile(
        CBaseFileSystem *this,
        const char *pAppendToFileName,
        const char *pAppendFromFileName,
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v6; // al
  bool v7; // bl
  CFileAsyncAppendFileJob *v8; // eax
  CFileAsyncAppendFileJob *appended; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v6 = m_nValue == 0;
  v7 = !v6 || this->m_pThreadPool == nullptr;
  if ( !v6 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v8 = (CFileAsyncAppendFileJob *)operator new(nSize: 0x38u);
  if ( v8 != nullptr )
    appended = CFileAsyncAppendFileJob::CFileAsyncAppendFileJob(
                 this: v8,
                 pszAppendTo: pAppendToFileName,
                 pszAppendFrom: pAppendFromFileName);
  else
    appended = nullptr;
  if ( v7 )
    CJob::Execute(this: appended);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: appended);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)appended;
  else
    appended->Release(this: appended);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100124D0
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncDirectoryScan(char const __near *,bool,void __near *,void (*)(void __near *,char __near *,char __near *),void (*)(void __near *,enum FSAsyncStatus_t),struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncDirectoryScan(
        CBaseFileSystem *this,
        const char *pSearchSpec,
        bool recurseFolders,
        void *pContext,
        void (__cdecl *pfnAdd)(void *, char *, char *),
        void (__cdecl *pfnDone)(void *, FSAsyncStatus_t),
        FSAsyncControl_t__ **pControl)
{
  int m_nValue; // eax
  bool v9; // al
  bool v10; // bl
  CFileAsyncDirectoryScanJob *v11; // eax
  CFileAsyncDirectoryScanJob *v12; // esi

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = m_nValue == 0;
  v10 = !v9 || this->m_pThreadPool == nullptr;
  if ( !v9 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  v11 = (CFileAsyncDirectoryScanJob *)operator new(nSize: 0x248u);
  if ( v11 != nullptr )
    v12 = CFileAsyncDirectoryScanJob::CFileAsyncDirectoryScanJob(
            this: v11,
            pSearchSpec,
            bRecurseDirs: recurseFolders,
            pContext,
            pAddCallback: pfnAdd,
            pDoneCallback: pfnDone);
  else
    v12 = nullptr;
  if ( v10 )
    CJob::Execute(this: v12);
  else
    this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: v12);
  if ( pControl != nullptr )
    *pControl = (FSAsyncControl_t__ *)v12;
  else
    v12->Release(this: v12);
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100127A0
// Name: public: struct AsyncOpenedFile_t __near * CAsyncOpenedFiles::Get(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncOpenedFile_t *__thiscall CAsyncOpenedFiles::Get(CAsyncOpenedFiles *this, FSAsyncFile_t__ *item)
{
  AsyncOpenedFile_t *result; // eax
  DWORD CurrentThreadId; // ecx

  if ( item == (FSAsyncFile_t__ *)0xFFFF )
    return nullptr;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->m_iRefs, 1u);
  result = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012820
// Name: public: void CAsyncOpenedFiles::AddRef(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncOpenedFiles::AddRef(CAsyncOpenedFiles *this, FSAsyncFile_t__ *item)
{
  DWORD CurrentThreadId; // ecx

  if ( item != (FSAsyncFile_t__ *)0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    _InterlockedExchangeAdd(&this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->m_iRefs, 1u);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012890
// Name: public: CFileAsyncReadJob::CFileAsyncReadJob(struct FileAsyncRequest_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFileAsyncReadJob *__thiscall CFileAsyncReadJob::CFileAsyncReadJob(
        CFileAsyncReadJob *this,
        const FileAsyncRequest_t *fromRequest)
{
  int priority; // eax
  char *v3; // ebx
  JobPriority_t v5; // eax
  const char *pszFilename; // edi
  const FileAsyncRequest_t *v7; // eax
  const char *v8; // ecx
  int v9; // eax
  char v10; // dl
  FSAsyncFile_t__ *hSpecificAsyncFile; // eax
  const FileAsyncRequest_t *fromRequesta; // [esp+14h] [ebp+8h]

  priority = fromRequest->priority;
  v3 = nullptr;
  if ( priority != 0 )
    v5 = priority <= 0 ? JP_LOW : JP_HIGH;
  else
    v5 = JP_NORMAL;
  this->m_iRefs = 1;
  this->m_priority = v5;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->m_flags |= 1u;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->FileAsyncRequest_t = *fromRequest;
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncReadJob::`vftable'{for `IRefCounted'};
  this->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncReadJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pResultData = nullptr;
  this->m_nResultSize = 0;
  this->m_pRealContext = fromRequest->pContext;
  this->m_pfnRealCallback = fromRequest->pfnCallback;
  pszFilename = fromRequest->pszFilename;
  if ( fromRequest->pszFilename != nullptr )
  {
    v7 = (const FileAsyncRequest_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszFilename) + 1);
    fromRequesta = v7;
    if ( v7 != nullptr )
    {
      v8 = pszFilename;
      v9 = (char *)v7 - pszFilename;
      do
      {
        v10 = *v8;
        v8[v9] = *v8;
        ++v8;
      }
      while ( v10 != 0 );
      v3 = (char *)fromRequesta;
    }
  }
  this->pszFilename = v3;
  V_FixSlashes(pname: v3, separator: 92);
  hSpecificAsyncFile = this->hSpecificAsyncFile;
  this->pContext = this;
  this->pfnCallback = CFileAsyncReadJob::InterceptCallback;
  if ( hSpecificAsyncFile != (FSAsyncFile_t__ *)0xFFFF )
    CAsyncOpenedFiles::AddRef(this: &g_AsyncOpenedFiles, item: hSpecificAsyncFile);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100129E0
// Name: public: virtual char const __near * CFileAsyncReadJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFileAsyncReadJob::Describe(CFileAsyncReadJob *this)
{
  return this->pszFilename;
}

//------------------------------------------------------------------------------
// Address: 0x100129F0
// Name: public: virtual int CFileAsyncReadJob::GetResult(void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileAsyncReadJob::GetResult(CFileAsyncReadJob *this, void **ppData, int *pSize)
{
  void *m_pResultData; // eax

  m_pResultData = this->m_pResultData;
  if ( m_pResultData != nullptr )
  {
    *ppData = m_pResultData;
    *pSize = this->m_nResultSize;
  }
  return this->m_status;
}

//------------------------------------------------------------------------------
// Address: 0x10013670
// Name: public: virtual void CFileAsyncWriteFileJob::DoCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileAsyncWriteFileJob::DoCleanup(CFileAsyncWriteFileJob *this)
{
  CUtlBuffer *m_pBuffer; // esi

  m_pBuffer = (CUtlBuffer *)this->m_pBuffer;
  if ( m_pBuffer != nullptr && this->m_bFreeMemory )
  {
    if ( m_pBuffer->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pBuffer->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBuffer->m_Memory.m_pMemory);
        m_pBuffer->m_Memory.m_pMemory = nullptr;
      }
      m_pBuffer->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_pBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100139F0
// Name: public: void CAsyncOpenedFiles::Release(struct FSAsyncFile_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncOpenedFiles::Release(CAsyncOpenedFiles *this, int item)
{
  DWORD CurrentThreadId; // ecx
  AsyncOpenedFile_t *elem; // ecx
  CBaseFileSystem *v5; // eax
  AsyncOpenedFile_t *v6; // ecx

  if ( item != 0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    elem = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
    if ( _InterlockedDecrement(&elem->m_iRefs) == 0 )
    {
      elem->OnFinalRelease(this: elem);
      if ( this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->hFile != nullptr )
      {
        v5 = BaseFileSystem();
        v5->Close(
          this: &v5->IBaseFileSystem,
          a2: this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem->hFile);
      }
      v6 = this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.elem;
      if ( v6 != nullptr )
        ((void (__thiscall *)(AsyncOpenedFile_t *, int))v6->dtr_CRefCountServiceBase<0,CRefMT>)(a1: v6, a2: 1);
      free(pMem: (void *)this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Data.key);
      if ( (_WORD)item != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_map.m_Tree,
          elem: item);
        this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Left = item;
        this->m_map.m_Tree.m_Elements.m_pMemory[(unsigned __int16)item].m_Right = this->m_map.m_Tree.m_FirstFree;
        this->m_map.m_Tree.m_FirstFree = item;
        --this->m_map.m_Tree.m_NumElements;
      }
    }
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013B60
// Name: public: virtual int CFileAsyncFileSizeJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __fastcall CFileAsyncFileSizeJob::DoExecute(CFileAsyncFileSizeJob *this, int a2)
{
  int m_nValue; // ecx
  int v4; // eax
  FileAsyncRequest_t *v5; // esi
  CBaseFileSystem *v6; // edi
  int v7; // eax

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v4);
  }
  if ( this != nullptr )
    v5 = &this->FileAsyncRequest_t;
  else
    v5 = nullptr;
  v6 = BaseFileSystem();
  v7 = v6->Size(this: &v6->IBaseFileSystem, a2: v5->pszFilename, a3: v5->pszPathID);
  CBaseFileSystem::DoAsyncCallback(
    this: v6,
    request: v5,
    pData: nullptr,
    nBytesRead: v7,
    result: (FSAsyncStatus_t)((v7 != 0) - 1));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013C00
// Name: public: virtual enum FSAsyncStatus_t CBaseFileSystem::AsyncReadMultipleCreditAlloc(struct FileAsyncRequest_t const __near *,int,char const __near *,int,struct FSAsyncControl_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CBaseFileSystem::AsyncReadMultipleCreditAlloc(
        CBaseFileSystem *this,
        const FileAsyncRequest_t *pRequests,
        int nRequests,
        const char *pszFile,
        int line,
        FSAsyncControl_t__ **phControls)
{
  int m_nValue; // eax
  bool v7; // al
  const FileAsyncRequest_t *v8; // edi
  int i; // ebx
  CFileAsyncReadJob *v10; // eax
  CFileAsyncReadJob *Job; // esi
  CFileAsyncReadJob *v12; // eax
  char bSynchronous_3; // [esp+Fh] [ebp+Bh]

  if ( async_mode.m_pParent != nullptr )
    m_nValue = async_mode.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue == 0;
  v8 = pRequests;
  if ( !v7 || (pRequests->flags & 4) != 0 || (bSynchronous_3 = 0, this->m_pThreadPool == nullptr) )
    bSynchronous_3 = 1;
  if ( !v7 )
    this->AsyncFinishAll(this, a2: 0x80000000);
  for ( i = 0; i < nRequests; ++i )
  {
    if ( v8->nBytes < 0 )
    {
      v12 = (CFileAsyncReadJob *)operator new(nSize: 0x6Cu);
      Job = v12;
      if ( v12 == nullptr )
      {
LABEL_16:
        Job = nullptr;
        goto LABEL_17;
      }
      CFileAsyncReadJob::CFileAsyncReadJob(this: v12, fromRequest: v8);
      Job->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFileAsyncReadJob_vtbl *)&CFileAsyncFileSizeJob::`vftable'{for `IRefCounted'};
      Job->CFileAsyncJob::CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFileAsyncFileSizeJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    }
    else
    {
      v10 = (CFileAsyncReadJob *)operator new(nSize: 0x6Cu);
      if ( v10 == nullptr )
        goto LABEL_16;
      Job = CFileAsyncReadJob::CFileAsyncReadJob(this: v10, fromRequest: v8);
    }
LABEL_17:
    if ( bSynchronous_3 != 0 )
      CJob::Execute(this: Job);
    else
      this->m_pThreadPool->AddJob(this: this->m_pThreadPool, a2: Job);
    if ( phControls != nullptr )
      phControls[i] = (FSAsyncControl_t__ *)Job;
    else
      Job->Release(this: Job);
    ++v8;
  }
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10013D00
// Name: public: enum FSAsyncStatus_t CBaseFileSystem::SyncRead(struct FileAsyncRequest_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseFileSystem::SyncRead@<eax>(
        CBaseFileSystem *this@<ecx>,
        int a2@<edi>,
        const FileAsyncRequest_t *request)
{
  FSAsyncFile_t__ *hSpecificAsyncFile; // eax
  AsyncOpenedFile_t *v6; // eax
  AsyncOpenedFile_t *v7; // edi
  void *v8; // eax
  signed int nBytes; // eax
  unsigned int Size; // edi
  void *(__cdecl *pfnAlloc)(const char *, unsigned int); // eax
  void *v12; // eax
  int nOffset; // eax
  int v14; // edi
  int iPrevPriority; // [esp+8h] [ebp-14h]
  unsigned int nOffsetAlign; // [esp+Ch] [ebp-10h] BYREF
  AsyncOpenedFile_t *pHeldFile; // [esp+10h] [ebp-Ch]
  void *pDest; // [esp+14h] [ebp-8h]
  int nBytesToRead; // [esp+18h] [ebp-4h]
  void *hFile; // [esp+24h] [ebp+8h]
  FSAsyncStatus_t hFilea; // [esp+24h] [ebp+8h]

  if ( request->nBytes < 0 || request->nOffset < 0 )
  {
    _Msg(a1: "Invalid async read of %s\n", request->pszFilename);
    CBaseFileSystem::DoAsyncCallback(this, request, pData: nullptr, nBytesRead: 0, result: FSASYNC_ERR_FILEOPEN);
    return -1;
  }
  hSpecificAsyncFile = request->hSpecificAsyncFile;
  if ( hSpecificAsyncFile == (FSAsyncFile_t__ *)0xFFFF )
  {
    pHeldFile = nullptr;
    v7 = nullptr;
    goto LABEL_8;
  }
  v6 = CAsyncOpenedFiles::Get(this: &g_AsyncOpenedFiles, item: hSpecificAsyncFile);
  v7 = v6;
  pHeldFile = v6;
  if ( v6 == nullptr || v6->hFile == nullptr )
  {
LABEL_8:
    v8 = this->OpenEx(this, a2: request->pszFilename, a3: "rb", a4: 0, a5: request->pszPathID, a6: 0);
    hFile = v8;
    if ( v7 != nullptr )
      v7->hFile = v8;
    goto LABEL_10;
  }
  hFile = v6->hFile;
LABEL_10:
  if ( hFile != nullptr )
  {
    nBytes = request->nBytes;
    if ( nBytes != 0 )
    {
      nBytesToRead = request->nBytes;
    }
    else
    {
      nBytes = this->Size_2(this: &this->IBaseFileSystem, a2: hFile) - request->nOffset;
      nBytesToRead = nBytes;
    }
    if ( nBytes < 0 )
    {
      nBytesToRead = 0;
      nBytes = 0;
    }
    if ( request->pData != nullptr )
    {
      pDest = request->pData;
      Size = nBytes;
    }
    else
    {
      Size = nBytes + ((request->flags & 8) != 0);
      if ( this->GetOptimalIOConstraints(this, a2: hFile, a3: &nOffsetAlign, a4: nullptr, a5: nullptr)
        && request->nOffset % nOffsetAlign == 0 )
      {
        Size = IFileSystem::GetOptimalReadSize(this, hFile, nLogicalSize: Size);
      }
      pfnAlloc = request->pfnAlloc;
      if ( pfnAlloc != nullptr )
        v12 = pfnAlloc(a1: request->pszFilename, a2: Size);
      else
        v12 = this->AllocOptimalReadBuffer(this, a2: hFile, a3: Size, a4: request->nOffset);
      pDest = v12;
    }
    ((void (__thiscall *)(CBaseFileSystem *, void *, _DWORD, int))this->SetBufferSize)(
      a1: this,
      a2: hFile,
      a3: 0,
      a4: a2);
    nOffset = request->nOffset;
    if ( nOffset > 0 )
      this->Seek(this: &this->IBaseFileSystem, a2: hFile, a3: nOffset, a4: FILESYSTEM_SEEK_HEAD);
    iPrevPriority = _ThreadGetPriority(a1: 0);
    if ( iPrevPriority < 2 )
      _ThreadSetPriority(a1: 0, a2: 2);
    v14 = ((int (__thiscall *)(CBaseFileSystem *, void *, unsigned int, int))this->ReadEx)(
            a1: this,
            a2: pDest,
            a3: Size,
            a4: nBytesToRead);
    if ( iPrevPriority < 2 )
      _ThreadSetPriority(a1: 0, a2: iPrevPriority);
    if ( pHeldFile == nullptr )
      this->Close(this: &this->IBaseFileSystem, a2: hFile);
    if ( (request->flags & 8) != 0 )
      *((_BYTE *)pDest + v14) = 0;
    if ( v14 != 0 || (hFilea = FSASYNC_ERR_READING, nBytesToRead == 0) )
      hFilea = FSASYNC_OK;
    if ( v14 >= nBytesToRead )
      v14 = nBytesToRead;
    CBaseFileSystem::DoAsyncCallback(this, request, pData: pDest, nBytesRead: v14, result: hFilea);
    v7 = pHeldFile;
  }
  else
  {
    CBaseFileSystem::DoAsyncCallback(this, request, pData: nullptr, nBytesRead: 0, result: FSASYNC_ERR_FILEOPEN);
    hFilea = FSASYNC_ERR_FILEOPEN;
  }
  if ( v7 != nullptr )
    CAsyncOpenedFiles::Release(this: &g_AsyncOpenedFiles, item: (int)request->hSpecificAsyncFile);
  if ( this->m_fwLevel >= FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC )
    CBaseFileSystem::LogAccessToFile(this, accesstype: "async", fullpath: request->pszFilename, options: setName);
  return hFilea;
}

//------------------------------------------------------------------------------
// Address: 0x10013F80
// Name: public: virtual int CFileAsyncReadJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CFileAsyncReadJob::DoExecute@<eax>(CFileAsyncReadJob *this@<ecx>, int a2@<edx>, int a3@<edi>)
{
  int m_nValue; // ecx
  int v5; // eax
  CBaseFileSystem *v6; // eax

  if ( async_simulate_delay.m_pParent != nullptr
    && async_simulate_delay.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0
    && !g_pQueuedLoader->IsMapLoading(this: g_pQueuedLoader) )
  {
    if ( async_simulate_delay.m_pParent != nullptr )
      m_nValue = async_simulate_delay.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v5 = _RandomInt(a1: m_nValue - m_nValue / 4, a2: m_nValue / 4 + m_nValue);
    _ThreadSleep(a1: v5);
  }
  v6 = BaseFileSystem();
  if ( this != nullptr )
    return CBaseFileSystem::SyncRead(this: v6, a2: a3, request: &this->FileAsyncRequest_t);
  else
    return CBaseFileSystem::SyncRead(this: v6, a2: a3, request: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003CEA0
// Name: _dynamic_initializer_for__filesystem_buffer_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_buffer_size__()
{
  ConVar::ConVar(
    this: &filesystem_buffer_size,
    pName: "filesystem_buffer_size",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Size of per file buffers. 0 for none");
  return atexit(func: dynamic_atexit_destructor_for__filesystem_buffer_size__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CEF0
// Name: _dynamic_initializer_for__CBaseFileSystem::m_ExcludeFilePaths__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_ExcludeFilePaths__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF00
// Name: _dynamic_initializer_for__CBaseFileSystem::m_DLCContents__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_DLCContents__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF10
// Name: _dynamic_initializer_for__CBaseFileSystem::m_CorruptDLC__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseFileSystem::m_CorruptDLC__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D120
// Name: _dynamic_initializer_for__async_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_mode__()
{
  ConVar::ConVar(
    this: &async_mode,
    pName: "async_mode",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set the async filesystem mode (0 = async, 1 = synchronous)");
  return atexit(func: dynamic_atexit_destructor_for__async_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D150
// Name: _dynamic_initializer_for__async_simulate_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_simulate_delay__()
{
  ConVar::ConVar(
    this: &async_simulate_delay,
    pName: "async_simulate_delay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Simulate a delay of up to a set msec per file operation");
  return atexit(func: dynamic_atexit_destructor_for__async_simulate_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D180
// Name: _dynamic_initializer_for__async_allow_held_files__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_allow_held_files__()
{
  ConVar::ConVar(
    this: &async_allow_held_files,
    pName: "async_allow_held_files",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow AsyncBegin/EndRead()");
  return atexit(func: dynamic_atexit_destructor_for__async_allow_held_files__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D1B0
// Name: _dynamic_initializer_for__async_suspend_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_suspend_command__()
{
  ConCommand::ConCommand(
    this: &async_suspend_command,
    pName: "async_suspend",
    callback: async_suspend,
    pHelpString: setName,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__async_suspend_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D1E0
// Name: _dynamic_initializer_for__async_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_resume_command__()
{
  ConCommand::ConCommand(
    this: &async_resume_command,
    pName: "async_resume",
    callback: async_resume,
    pHelpString: setName,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__async_resume_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D4C0
// Name: _dynamic_atexit_destructor_for__filesystem_buffer_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_buffer_size__()
{
  ConVar::~ConVar(this: &filesystem_buffer_size);
}

//------------------------------------------------------------------------------
// Address: 0x1003D5C0
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_CorruptDLC__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&CBaseFileSystem::m_CorruptDLC);
}

//------------------------------------------------------------------------------
// Address: 0x1003D610
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_ExcludeFilePaths__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&CBaseFileSystem::m_ExcludeFilePaths);
}

//------------------------------------------------------------------------------
// Address: 0x1003D620
// Name: _dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseFileSystem::m_DLCContents__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&CBaseFileSystem::m_DLCContents);
}

//------------------------------------------------------------------------------
// Address: 0x1003D630
// Name: _dynamic_atexit_destructor_for__async_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_mode__()
{
  ConVar::~ConVar(this: &async_mode);
}

//------------------------------------------------------------------------------
// Address: 0x1003D640
// Name: _dynamic_atexit_destructor_for__async_simulate_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_simulate_delay__()
{
  ConVar::~ConVar(this: &async_simulate_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1003D650
// Name: _dynamic_atexit_destructor_for__async_allow_held_files__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_allow_held_files__()
{
  ConVar::~ConVar(this: &async_allow_held_files);
}

//------------------------------------------------------------------------------
// Address: 0x1003D660
// Name: _dynamic_atexit_destructor_for__async_suspend_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_suspend_command__()
{
  ConCommand::~ConCommand(this: &async_suspend_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D670
// Name: _dynamic_atexit_destructor_for__async_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_resume_command__()
{
  ConCommand::~ConCommand(this: &async_resume_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003CED0
// Name: _dynamic_initializer_for__g_FileOpenDuplicateTimes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileOpenDuplicateTimes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CEE0
// Name: _dynamic_initializer_for__g_FileOpenDuplicateTimesMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileOpenDuplicateTimesMutex__()
{
  g_FileOpenDuplicateTimesMutex.m_ownerID = 0;
  g_FileOpenDuplicateTimesMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF20
// Name: _dynamic_initializer_for__g_UpdateZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UpdateZipBuffer__()
{
  CUtlBuffer::CUtlBuffer(this: &g_UpdateZipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_UpdateZipBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF40
// Name: _dynamic_initializer_for__g_XLSPPatchZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_XLSPPatchZipBuffer__()
{
  CUtlBuffer::CUtlBuffer(this: &g_XLSPPatchZipBuffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF60
// Name: _dynamic_initializer_for__s_IoStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_IoStats__()
{
  s_IoStats.m_nNumberOfFileSeeks.m_value = 0;
  s_IoStats.m_nTimeInFileSeek.m_value = 0;
  s_IoStats.m_nNumberOfFileReads.m_value = 0;
  s_IoStats.m_nTimeInFileRead.m_value = 0;
  s_IoStats.m_nFileReadTotalSize.m_value = 0;
  s_IoStats.m_nNumberOfFileOpens.m_value = 0;
  return atexit(func: dynamic_atexit_destructor_for__s_IoStats__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF90
// Name: _dynamic_initializer_for__g_pszReadFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pszReadFilename__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_pszReadFilename);
  return atexit(func: dynamic_atexit_destructor_for__g_pszReadFilename__);
}

//------------------------------------------------------------------------------
// Address: 0x1003CFB0
// Name: _dynamic_initializer_for__fs_dump_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_dump_open_duplicate_times_command__()
{
  ConCommand::ConCommand(
    this: &fs_dump_open_duplicate_times_command,
    pName: "fs_dump_open_duplicate_times",
    callback: fs_dump_open_duplicate_times,
    pHelpString: "Set fs_report_long_reads 1 before loading to use this. Prints a list of files that were opened more than once and ~h"
    "ow long was spent reading from them.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D000
// Name: _dynamic_initializer_for__fs_clear_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_clear_open_duplicate_times_command__()
{
  ConCommand::ConCommand(
    this: &fs_clear_open_duplicate_times_command,
    pName: "fs_clear_open_duplicate_times",
    callback: (void (__cdecl *)())fs_clear_open_duplicate_times,
    pHelpString: "Clear the list of files that have been opened.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D030
// Name: _dynamic_initializer_for__fs_fios_flush_cache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_flush_cache_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_flush_cache_command,
    pName: "fs_fios_flush_cache",
    callback: (void (__cdecl *)())CPackFile::SetupPreloadData,
    pHelpString: "Flushes the FIOS HDD cache.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_flush_cache_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D060
// Name: _dynamic_initializer_for__fs_fios_print_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_print_prefetches_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_print_prefetches_command,
    pName: "fs_fios_print_prefetches",
    callback: (void (__cdecl *)())CPackFile::SetupPreloadData,
    pHelpString: "Displays all the prefetches currently in progress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D090
// Name: _dynamic_initializer_for__fs_fios_prefetch_file_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_prefetch_file_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_prefetch_file_command,
    pName: "fs_fios_prefetch_file",
    callback: (void (__cdecl *)())CPackFile::SetupPreloadData,
    pHelpString: "Prefetches a file: </PS3_GAME/USRDIR/filename.bin>.\nThe preftech is medium priority and persistent.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D0C0
// Name: _dynamic_initializer_for__fs_fios_prefetch_file_in_pack_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_prefetch_file_in_pack_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_prefetch_file_in_pack_command,
    pName: "fs_fios_prefetch_file_in_pack",
    callback: (void (__cdecl *)())CPackFile::SetupPreloadData,
    pHelpString: "Prefetches a file in a pack: <portal2/models/container_ride/fineDebris_part5.ani>.\n"
    "The preftech is medium priority and non-persistent.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D0F0
// Name: _dynamic_initializer_for__fs_fios_cancel_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_fios_cancel_prefetches_command__()
{
  ConCommand::ConCommand(
    this: &fs_fios_cancel_prefetches_command,
    pName: "fs_fios_cancel_prefetches",
    callback: (void (__cdecl *)())CPackFile::SetupPreloadData,
    pHelpString: "Cancels all the prefetches in progress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D210
// Name: _dynamic_initializer_for__g_AsyncOpenedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncOpenedFiles__()
{
  g_AsyncOpenedFiles.m_mutex.m_ownerID = 0;
  g_AsyncOpenedFiles.m_mutex.m_depth = 0;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_pMemory = nullptr;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_AsyncOpenedFiles.m_map.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_AsyncOpenedFiles.m_map.m_Tree.m_FirstFree = -1;
  g_AsyncOpenedFiles.m_map.m_Tree.m_pElements = nullptr;
  g_AsyncOpenedFiles.m_map.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncOpenedFiles__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D260
// Name: _dynamic_initializer_for__g_AsyncFinishMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncFinishMutex__()
{
  CThreadMutex::CThreadMutex(this: &g_AsyncFinishMutex);
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncFinishMutex__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D280
// Name: _dynamic_initializer_for__g_FileSystem_Steam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileSystem_Steam__()
{
  CBaseFileSystem::CBaseFileSystem(this: &g_FileSystem_Steam);
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Steam_vtbl *)&CFileSystem_Steam::`vftable'{for `IAppSystem'};
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Steam::`vftable'{for `IBaseFileSystem'};
  *(_DWORD *)&g_FileSystem_Steam.m_bSteamInitialized = 0x1000000;
  g_FileSystem_Steam.m_hWaitForResourcesCallHandle = 0;
  g_FileSystem_Steam.m_iCurrentReturnedCallHandle = 1;
  g_FileSystem_Steam.m_hSteamDLL = nullptr;
  *(_WORD *)&g_FileSystem_Steam.m_bContentLoaded = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_FileSystem_Steam__);
}

//------------------------------------------------------------------------------
// Address: 0x1003D2E0
// Name: _dynamic_initializer_for____g_CreateCFileSystem_SteamIFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCFileSystem_SteamIFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCFileSystem_SteamIFileSystem_reg,
           fn: _CreateCFileSystem_SteamIFileSystem_interface,
           pName: "VFileSystem017");
}

//------------------------------------------------------------------------------
// Address: 0x1003D300
// Name: _dynamic_initializer_for____g_CreateCFileSystem_SteamIBaseFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCFileSystem_SteamIBaseFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCFileSystem_SteamIBaseFileSystem_reg,
           fn: _CreateCFileSystem_SteamIBaseFileSystem_interface,
           pName: "VBaseFileSystem011");
}

//------------------------------------------------------------------------------
// Address: 0x1003D4D0
// Name: _dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__()
{
  ConCommand::~ConCommand(this: &fs_dump_open_duplicate_times_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D4E0
// Name: _dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__()
{
  ConCommand::~ConCommand(this: &fs_clear_open_duplicate_times_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D4F0
// Name: _dynamic_atexit_destructor_for__fs_fios_flush_cache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_flush_cache_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_flush_cache_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D500
// Name: _dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_print_prefetches_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D510
// Name: _dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_prefetch_file_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D520
// Name: _dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_prefetch_file_in_pack_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D530
// Name: _dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_cancel_prefetches_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003D540
// Name: _dynamic_atexit_destructor_for__g_PathIDTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PathIDTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PathIDTable);
}

//------------------------------------------------------------------------------
// Address: 0x1003D550
// Name: _dynamic_atexit_destructor_for__s_IoStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_IoStats__()
{
  s_IoStats.__vftable = (CIoStats_vtbl *)&IIoStats::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003D560
// Name: _dynamic_atexit_destructor_for__g_pszReadFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pszReadFilename__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_pszReadFilename);
}

//------------------------------------------------------------------------------
// Address: 0x1003D570
// Name: _dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__()
{
  if ( g_XLSPPatchZipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_XLSPPatchZipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_XLSPPatchZipBuffer.m_Memory.m_pMemory);
      g_XLSPPatchZipBuffer.m_Memory.m_pMemory = nullptr;
    }
    g_XLSPPatchZipBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D5B0
// Name: _dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__()
{
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&g_FileOpenDuplicateTimes);
}

//------------------------------------------------------------------------------
// Address: 0x1003D5D0
// Name: _dynamic_atexit_destructor_for__g_UpdateZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UpdateZipBuffer__()
{
  if ( g_UpdateZipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_UpdateZipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_UpdateZipBuffer.m_Memory.m_pMemory);
      g_UpdateZipBuffer.m_Memory.m_pMemory = nullptr;
    }
    g_UpdateZipBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D680
// Name: _dynamic_atexit_destructor_for__g_AsyncFinishMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncFinishMutex__()
{
  CThreadMutex::~CThreadMutex(this: &g_AsyncFinishMutex);
}

//------------------------------------------------------------------------------
// Address: 0x1003D690
// Name: _dynamic_atexit_destructor_for__g_AsyncOpenedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncOpenedFiles__()
{
  CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_AsyncOpenedFiles.m_map.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6A0
// Name: _dynamic_atexit_destructor_for__g_FileSystem_Steam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileSystem_Steam__()
{
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Steam_vtbl *)&CFileSystem_Steam::`vftable'{for `IAppSystem'};
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Steam::`vftable'{for `IBaseFileSystem'};
  g_FileSystem_Steam.m_bSteamInitialized = false;
  CBaseFileSystem::~CBaseFileSystem(this: &g_FileSystem_Steam);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6D0
// Name: _DataMapInit_ZIP_EndOfCentralDirRecord__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_EndOfCentralDirRecord__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6E0
// Name: _DataMapInit_ZIP_FileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_FileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6F0
// Name: _DataMapInit_ZIP_LocalFileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_LocalFileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x1003D700
// Name: _DataMapInit_ZIP_PreloadHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_PreloadHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x1003D710
// Name: _DataMapInit_ZIP_PreloadDirectoryEntry__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_PreloadDirectoryEntry__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x1003D720
// Name: _dynamic_atexit_destructor_for__g_ZipUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ZipUtils__()
{
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short> > *)&g_ZipUtils);
  if ( g_ZipUtils.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ZipUtils.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ZipUtils.m_Memory.m_pMemory);
      g_ZipUtils.m_Memory.m_pMemory = nullptr;
    }
    g_ZipUtils.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D770
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D7B0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x1003D7C0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

} // namespace FileSystem_Steam
