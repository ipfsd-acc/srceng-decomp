// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/assert_dialog.cpp
// Functions: 39
// ============================================================

#include "tier0\assert_dialog.h"

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: public: class CCallStackStorage __near & CCallStackStorage::operator=(class CCallStackStorage const __near &)
// Source: json
//------------------------------------------------------------------------------
CCallStackStorage *__thiscall CCallStackStorage::operator=(CCallStackStorage *this, const CCallStackStorage *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: public: class CStackTop_ReferenceParentStack __near & CStackTop_ReferenceParentStack::operator=(class CStackTop_ReferenceParentStack const __near &)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '??4CStackTop_Base@@QAEAAV0@ABV0@@Z'
// Alternative name is '??4CStackTop_CopyParentStack@@QAEAAV0@ABV0@@Z'
CStackTop_ReferenceParentStack *__thiscall CStackTop_ReferenceParentStack::operator=(
        CStackTop_ReferenceParentStack *this,
        const CStackTop_ReferenceParentStack *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: void __near * CThreadSyncObject::GetHandle(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '??BCThreadSyncObject@@QAEPAXXZ'
// Alternative name is '?GetHandle@CThreadSyncObject@@QBEQAXXZ'
void *__thiscall CThreadSyncObject::GetHandle(CThreadSyncObject *this)
{
  return this->m_hSyncObject;
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: CThreadFullMutex::~CThreadFullMutex(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '??1CThreadEvent@@QAE@XZ'
// Alternative name is '??1CThreadFullMutex@@QAE@XZ'
// attributes: thunk
void __thiscall CThreadFullMutex::~CThreadFullMutex(CThreadEvent *this)
{
  CThreadSyncObject::~CThreadSyncObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: void CThreadFullMutex::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::Lock(CThreadFullMutex *this)
{
  CThreadEvent::Wait((CThreadEvent *)this, dwTimeout: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: void CThreadFullMutex::Lock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::Lock(CThreadFullMutex *this, unsigned int timeout)
{
  CThreadEvent::Wait((CThreadEvent *)this, dwTimeout: timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: public: void CThreadFullMutex::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadFullMutex::Unlock(CThreadFullMutex *this)
{
  CThreadFullMutex::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: CThreadRWLock::~CThreadRWLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::~CThreadRWLock(CThreadRWLock *this)
{
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_CanRead);
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_CanWrite);
}

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: CThreadSpinRWLock::CThreadSpinRWLock(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSpinRWLock *__thiscall CThreadSpinRWLock::CThreadSpinRWLock(CThreadSpinRWLock *this)
{
  this->m_lockInfo.m_i32 = 0;
  this->m_writerId = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001190
// Name: public: class CThreadSpinRWLock __near & CThreadSpinRWLock::operator=(class CThreadSpinRWLock const __near &)
// Source: json
//------------------------------------------------------------------------------
CThreadSpinRWLock *__thiscall CThreadSpinRWLock::operator=(CThreadSpinRWLock *this, const CThreadSpinRWLock *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100011B0
// Name: public: unsigned int CThread::CalcStackDepth(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThread::CalcStackDepth(CThread *this, void *pStackVariable)
{
  return (char *)this->m_pStackBase - (char *)pStackVariable;
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: bool CThread::IsSuspended(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThread::IsSuspended(CThread *this)
{
  return !CThreadEvent::Check(this: &this->m_NotSuspendedEvent);
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: protected: unsigned int const CThread::GetThreadID(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThread::GetThreadID(CThread *this)
{
  return this->m_threadId;
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: virtual CWorkerThread::~CWorkerThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerThread::~CWorkerThread(CWorkerThread *this)
{
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_EventComplete);
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_EventSend);
  CThread::~CThread(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001210
// Name: public: CThreadRWLock::CThreadRWLock(void)
// Source: json
//------------------------------------------------------------------------------
CThreadRWLock *__thiscall CThreadRWLock::CThreadRWLock(CThreadRWLock *this)
{
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CThreadEvent::CThreadEvent(this: &this->m_CanWrite, bManualReset: false);
  CThreadEvent::CThreadEvent(this: &this->m_CanRead, bManualReset: true);
  this->m_nWriters = 0;
  this->m_nActiveReaders = 0;
  this->m_nPendingReaders = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: void CThreadRWLock::UnlockRead(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?UnlockRead@CThreadRWLock@@QAEXXZ'
void __thiscall CThreadRWLock::UnlockRead(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx
  bool v3; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  v3 = this->m_nActiveReaders-- == 1;
  if ( v3 && this->m_nWriters != 0 )
    CThreadEvent::Set(this: &this->m_CanWrite);
  v3 = this->m_mutex.m_depth-- == 1;
  if ( v3 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100012A0
// Name: public: bool CThreadSpinRWLock::IsLockedForWrite(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSpinRWLock::IsLockedForWrite(CThreadSpinRWLock *this)
{
  return this->m_lockInfo.m_fWriting == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100012B0
// Name: public: bool CThreadSpinRWLock::IsLockedForRead(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSpinRWLock::IsLockedForRead(CThreadSpinRWLock *this)
{
  return this->m_lockInfo.m_nReaders != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: public: bool CThreadSpinRWLock::TryLockForWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?TryLockForWrite@CThreadSpinRWLock@@QAE_NXZ'
// Alternative name is '?TryLockForWrite@CThreadSpinRWLock@@QBE_NXZ'
char __thiscall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this)
{
  if ( (this->m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
  {
    return 0;
  }
  this->m_writerId = GetCurrentThreadId();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: public: void CThreadSpinRWLock::LockForWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?LockForWrite@CThreadSpinRWLock@@QAEXXZ'
void __thiscall CThreadSpinRWLock::LockForWrite(CThreadSpinRWLock *this)
{
  if ( (this->m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this);
  }
  else
  {
    this->m_writerId = GetCurrentThreadId();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: public: bool CThreadSpinRWLock::TryLockForRead_UnforcedInline(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?TryLockForRead@CThreadSpinRWLock@@QAE_NXZ'
// Alternative name is '?TryLockForRead@CThreadSpinRWLock@@QBE_NXZ'
bool __thiscall CThreadSpinRWLock::TryLockForRead_UnforcedInline(CThreadSpinRWLock *this)
{
  signed __int32 m_i32; // edx
  bool result; // al

  result = false;
  if ( (this->m_lockInfo.m_i32 & 0x10000) == 0 )
  {
    m_i32 = (unsigned __int16)this->m_lockInfo.m_i32;
    if ( _InterlockedCompareExchange((volatile signed __int32 *)this, m_i32 + 1, m_i32) == m_i32 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: void CThreadSpinRWLock::UnlockRead(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?UnlockRead@CThreadSpinRWLock@@QAEXXZ'
void __thiscall CThreadSpinRWLock::UnlockRead(CThreadSpinRWLock *this)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  g_hTier0Instance = hinstDLL;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10001380
// Name: AssertStack
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AssertStack()
{
  unsigned __int8 *CommandLineA; // eax
  int v1; // eax
  bool result; // al

  if ( (_S2 & 1) != 0 )
    return bResult;
  _S2 |= 1u;
  CommandLineA = (unsigned __int8 *)Plat_GetCommandLineA();
  strstr(str1: CommandLineA, str2: "-assertstack");
  result = v1 != 0;
  bResult = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: AllAssertOnce
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AllAssertOnce()
{
  unsigned __int8 *CommandLineA; // eax
  int v1; // eax
  bool result; // al

  if ( (_S4 & 1) != 0 )
    return bResult_0;
  _S4 |= 1u;
  CommandLineA = (unsigned __int8 *)Plat_GetCommandLineA();
  strstr(str1: CommandLineA, str2: "-assertonce");
  result = v1 != 0;
  bResult_0 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: AreAssertsEnabledInFileLine
// Source: json
//------------------------------------------------------------------------------
char __cdecl AreAssertsEnabledInFileLine(const char *pFilename, int iLine)
{
  CAssertDisable *v2; // esi
  CAssertDisable *m_pNext; // ebx
  int m_LineMin; // eax
  bool v5; // cl
  int m_nIgnoreTimes; // eax
  int v7; // eax
  CAssertDisable **pPrev; // [esp+Ch] [ebp-4h]

  v2 = g_pAssertDisables;
  pPrev = &g_pAssertDisables;
  if ( g_pAssertDisables == nullptr )
    return 1;
  while ( 1 )
  {
    m_pNext = v2->m_pNext;
    if ( _stricmp(dst: pFilename, src: v2->m_Filename) != 0 )
      goto LABEL_11;
    m_LineMin = v2->m_LineMin;
    v5 = true;
    if ( m_LineMin == -1 )
      v5 = v2->m_LineMax != -1;
    if ( (iLine < m_LineMin || iLine > v2->m_LineMax) && v5 )
    {
LABEL_11:
      pPrev = &v2->m_pNext;
      goto LABEL_12;
    }
    m_nIgnoreTimes = v2->m_nIgnoreTimes;
    if ( m_nIgnoreTimes <= 0 )
      return 0;
    v7 = m_nIgnoreTimes - 1;
    v2->m_nIgnoreTimes = v7;
    if ( v7 != 0 )
      return 0;
    *pPrev = m_pNext;
    operator delete(p: v2);
LABEL_12:
    v2 = m_pNext;
    if ( m_pNext == nullptr )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: void IgnoreAssertsInCurrentFile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IgnoreAssertsInCurrentFile()
{
  CAssertDisable *v0; // eax
  unsigned __int8 *m_pFilename; // ecx
  CAssertDisable *v2; // esi

  v0 = (CAssertDisable *)operator new(size: 0x210u);
  m_pFilename = (unsigned __int8 *)g_Info.m_pFilename;
  v2 = v0;
  v0->m_pNext = g_pAssertDisables;
  g_pAssertDisables = v0;
  v0->m_LineMax = -1;
  v0->m_LineMin = -1;
  v0->m_nIgnoreTimes = -1;
  strncpy(dest: (unsigned __int8 *)v0, source: m_pFilename, count: 0x1FFu);
  v2->m_Filename[511] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001510
// Name: class CAssertDisable __near * IgnoreAssertsNearby(int)
// Source: json
//------------------------------------------------------------------------------
CAssertDisable *__cdecl IgnoreAssertsNearby(int nRange)
{
  CAssertDisable *v1; // eax
  unsigned __int8 *m_pFilename; // ecx
  CAssertDisable *v3; // esi
  int v4; // eax

  v1 = (CAssertDisable *)operator new(size: 0x210u);
  m_pFilename = (unsigned __int8 *)g_Info.m_pFilename;
  v3 = v1;
  v1->m_pNext = g_pAssertDisables;
  g_pAssertDisables = v1;
  v1->m_LineMax = -1;
  v1->m_LineMin = -1;
  v1->m_nIgnoreTimes = -1;
  strncpy(dest: (unsigned __int8 *)v1, source: m_pFilename, count: 0x1FFu);
  v4 = g_Info.m_iLine - nRange;
  v3->m_Filename[511] = 0;
  v3->m_LineMin = v4;
  v3->m_LineMax = v4;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: int AssertDialogProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall AssertDialogProc(HWND__ *hDlg, int uMsg, unsigned int wParam, int lParam)
{
  int result; // eax
  UINT v5; // eax
  UINT v6; // esi
  UINT DlgItemInt; // eax
  HWND DesktopWindow; // eax
  tagRECT rcDesktop; // [esp+8h] [ebp-20h] BYREF
  tagRECT rcDlg; // [esp+18h] [ebp-10h] BYREF

  switch ( uMsg )
  {
    case 256:
LABEL_18:
      if ( wParam == 2 )
LABEL_19:
        EndDialog(hDlg, nResult: 0);
      return 1;
    case 272:
      SetDlgItemTextA(hDlg, nIDDlgItem: 1011, lpString: g_Info.m_pExpression);
      SetDlgItemTextA(hDlg, nIDDlgItem: 1000, lpString: g_Info.m_pFilename);
      SetDlgItemInt(hDlg, nIDDlgItem: 1001, uValue: g_Info.m_iLine, bSigned: false);
      SetDlgItemInt(hDlg, nIDDlgItem: 1004, uValue: g_iLastLineRange, bSigned: false);
      SetDlgItemInt(hDlg, nIDDlgItem: 1010, uValue: g_nLastIgnoreNumTimes, bSigned: false);
      GetWindowRect(hWnd: hDlg, lpRect: &rcDlg);
      DesktopWindow = GetDesktopWindow();
      GetWindowRect(hWnd: DesktopWindow, lpRect: &rcDesktop);
      SetWindowPos(
        hWnd: hDlg,
        hWndInsertAfter: nullptr,
        X: (rcDesktop.right + rcDlg.left - rcDlg.right - rcDesktop.left) / 2,
        Y: (rcDesktop.bottom + rcDlg.top - rcDlg.bottom - rcDesktop.top) / 2,
        cx: 0,
        cy: 0,
        uFlags: 1u);
      return 1;
    case 273:
      switch ( (__int16)wParam )
      {
        case 1002:
          IgnoreAssertsInCurrentFile();
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1003:
          uMsg = 0;
          DlgItemInt = GetDlgItemInt(hDlg, nIDDlgItem: 1004, lpTranslated: &uMsg, bSigned: false);
          if ( uMsg == 0 || DlgItemInt == 0 )
            return 1;
          IgnoreAssertsNearby(nRange: DlgItemInt);
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1005:
          uMsg = 0;
          v5 = GetDlgItemInt(hDlg, nIDDlgItem: 1010, lpTranslated: &uMsg, bSigned: false);
          v6 = v5;
          if ( uMsg != 0 && v5 > 1 )
          {
            IgnoreAssertsNearby(nRange: 0)->m_nIgnoreTimes = v5 - 1;
            g_nLastIgnoreNumTimes = v6;
          }
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1006:
          g_bBreak = true;
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1008:
          g_bAssertsEnabled = false;
          goto LABEL_19;
        case 1009:
          IgnoreAssertsNearby(nRange: 0);
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        default:
          goto LABEL_18;
      }
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: ParentWindowEnumProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall ParentWindowEnumProc(HWND hWnd, HWND__ *lParam)
{
  HWND v2; // esi

  v2 = hWnd;
  if ( !IsWindowVisible(hWnd) )
    return 1;
  GetWindowThreadProcessId(hWnd: v2, lpdwProcessId: (LPDWORD)&hWnd);
  if ( hWnd != lParam )
    return 1;
  g_hBestParentWindow = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001820
// Name: _AreAllAssertsDisabled
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AreAllAssertsDisabled()
{
  return !g_bAssertsEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: _SetAllAssertsDisabled
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetAllAssertsDisabled(bool bAssertsDisabled)
{
  g_bAssertsEnabled = !bAssertsDisabled;
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: _ShouldUseNewAssertDialog
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ShouldUseNewAssertDialog()
{
  unsigned __int8 *CommandLineA; // eax
  int v1; // eax

  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    CommandLineA = (unsigned __int8 *)Plat_GetCommandLineA();
    strstr(str1: CommandLineA, str2: "-mpi_worker");
    bMPIWorker = v1 != 0;
  }
  return !bMPIWorker;
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: void CThreadRWLock::LockForRead(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?LockForRead@CThreadRWLock@@QAEXXZ'
void __thiscall CThreadRWLock::LockForRead(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  if ( this->m_nWriters != 0 )
    CThreadRWLock::WaitForRead(this);
  ++this->m_nActiveReaders;
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: void CThreadSpinRWLock::LockForRead(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?LockForRead@CThreadSpinRWLock@@QAEXXZ'
void __thiscall CThreadSpinRWLock::LockForRead(CThreadSpinRWLock *this)
{
  signed __int32 m_i32; // edx

  if ( (this->m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)this->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)this, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001920
// Name: public: void CThreadSpinRWLock::UnlockWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?UnlockWrite@CThreadSpinRWLock@@QAEXXZ'
void __thiscall CThreadSpinRWLock::UnlockWrite(CThreadSpinRWLock *this)
{
  this->m_writerId = 0;
  this->m_lockInfo.m_i32 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001930
// Name: public: void CThreadMutex::UnlockSilent(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?Unlock@CThreadMutex@@QAEXXZ'
// Alternative name is '?Unlock@CThreadMutex@@QBEXXZ'
void __thiscall CThreadMutex::UnlockSilent(CThreadMutex *this)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: _DoNewAssertDialog
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoNewAssertDialog(const char *pFilename, int line, const char *pExpression)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 *CommandLineA; // eax
  int v5; // eax
  char result; // al
  unsigned __int8 *v7; // eax
  int v8; // eax
  DWORD CurrentProcessId; // eax
  int v10; // eax

  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &autoMutex__, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    CommandLineA = (unsigned __int8 *)Plat_GetCommandLineA();
    strstr(str1: CommandLineA, str2: "-noassert");
    byte_1003A770 = v5 != 0;
  }
  if ( byte_1003A770 != 0 || g_bDisableAsserts )
    goto LABEL_11;
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    v7 = (unsigned __int8 *)Plat_GetCommandLineA();
    strstr(str1: v7, str2: "-debugbreak");
    byte_1003A760 = v8 != 0;
  }
  if ( byte_1003A760 != 0 )
  {
    if ( --autoMutex__.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
    return 1;
  }
  else
  {
    if ( !g_bAssertsEnabled || AreAssertsEnabledInFileLine(pFilename, iLine: line) == 0 )
    {
LABEL_11:
      if ( --autoMutex__.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
      return 0;
    }
    g_Info.m_pFilename = pFilename;
    g_Info.m_iLine = line;
    g_Info.m_pExpression = pExpression;
    if ( AssertStack() )
    {
      IgnoreAssertsNearby(nRange: 0);
      Warning(pMsgFormat: "%s (%d) : Assertion callstack...(NOT IMPLEMENTED IN NEW LOGGING SYSTEM.)\n", pFilename, line);
      if ( --autoMutex__.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
      return 0;
    }
    else
    {
      if ( AllAssertOnce() )
        IgnoreAssertsNearby(nRange: 0);
      g_bBreak = false;
      if ( g_hTier0Instance != nullptr && ThreadInMainThread() )
      {
        g_hBestParentWindow = nullptr;
        CurrentProcessId = GetCurrentProcessId();
        EnumWindows(lpEnumFunc: (WNDENUMPROC)ParentWindowEnumProc, lParam: CurrentProcessId);
        DialogBoxParamA(
          hInstance: g_hTier0Instance,
          lpTemplateName: (LPCSTR)0x65,
          hWndParent: g_hBestParentWindow,
          lpDialogFunc: (DLGPROC)AssertDialogProc,
          dwInitParam: 0);
      }
      else
      {
        v10 = MessageBoxA(hWnd: nullptr, lpText: pExpression, lpCaption: "Assertion Failed", uType: 0x1006u);
        if ( v10 == 2 )
        {
          IgnoreAssertsNearby(nRange: 0);
        }
        else if ( v10 == 11 )
        {
          g_bBreak = true;
        }
      }
      result = g_bBreak;
      if ( --autoMutex__.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001B80
// Name: public: void CThreadMutex::Lock(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?Lock@CThreadMutex@@QAEXXZ'
// Alternative name is '?Lock@CThreadMutex@@QBEXXZ'
void __thiscall CThreadMutex::Lock(CThreadMutex *this)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F001010
// Name: public: void CThreadMutex::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadMutex::Unlock(CThreadMutex *this)
{
  JUMPOUT(0x3F001018);
}

//------------------------------------------------------------------------------
// Address: 0x3F001090
// Name: public: CThreadFullMutex::~CThreadFullMutex(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CThreadFullMutex::~CThreadFullMutex(
        CThreadSemaphore *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  int v5; // eax

  *(_BYTE *)(a5 + 4) += BYTE1(a2);
  if ( (_BYTE)this != 0 )
  {
    *(_DWORD *)(a3 - 4) = a4;
LABEL_6:
    if ( a2 != 0 )
      CThreadFullMutex::Lock((CThreadFullMutex *)this);
    return;
  }
  v5 = *(_DWORD *)(a5 + 520);
  if ( v5 > 0 )
  {
    *(_DWORD *)(a5 + 520) = v5 - 1;
    if ( v5 == 1 )
    {
      **(_DWORD **)(a3 - 4) = a2;
      j__free(Block: (void *)a5);
      goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0014F0
// Name: DoNewAssertDialog
// Source: json
//------------------------------------------------------------------------------
char DoNewAssertDialog()
{
  LPSTR CommandLineA; // eax
  LPSTR v1; // eax

  CommandLineA = GetCommandLineA();
  if ( sub_3F01A2BB(a1: CommandLineA, a2: "-noassert") == 0 )
  {
    v1 = GetCommandLineA();
    if ( sub_3F01A2BB(a1: v1, a2: "-nocrashdialog") == 0 )
    {
      if ( GetCurrentThreadId() != dword_3F0415CC )
      {
        IsDebuggerPresent();
        JUMPOUT(0x3F00153F);
      }
      JUMPOUT(0x3F001544);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0015E0
// Name: SetInAssert
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetInAssert(char a1)
{
  byte_3F03D369 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F0015F0
// Name: IsInAssert
// Source: json
//------------------------------------------------------------------------------
char IsInAssert()
{
  return byte_3F03D369;
}

//------------------------------------------------------------------------------
// Address: 0x3F001740
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
unsigned __int32 __stdcall DllMain()
{
  return __indword(0x5Du);
}

//------------------------------------------------------------------------------
// Address: 0x3F001760
// Name: AreAssertsEnabledInFileLine
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __usercall AreAssertsEnabledInFileLine@<al>(char a1@<cf>, char a2@<al>, int a3@<ecx>, int _EBX@<ebx>)
{
  bool result; // al
  int v5; // ecx

  __asm { fmul    qword ptr [ebx-173E03BBh] }
  result = a1 + a2 - 125;
  v5 = a3 - 1;
  if ( result && v5 != 0 )
    JUMPOUT(0x3F00176B);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F001800
// Name: void IgnoreAssertsInCurrentFile(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall IgnoreAssertsInCurrentFile(int a1@<ecx>, int a2@<ebp>)
{
  ((void (__cdecl *)(int, int, int, int, int))loc_3F001600)(a1: -2147483647, a2: a2 - 4, a3: a2 - 4, a4: a2 - 4, a5: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F001860
// Name: class CAssertDisable __near * IgnoreAssertsNearby(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IgnoreAssertsNearby()
{
  JUMPOUT(0x3F001861);
}

//------------------------------------------------------------------------------
// Address: 0x3F0018D0
// Name: int AssertDialogProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __usercall AssertDialogProc@<al>(char a1@<al>, int a2@<ebp>)
{
  int v2; // eax

  return a1 != 0
      && (unsigned __int8)((int (__cdecl *)(int, int, int, int, int))loc_3F001600)(
                            a1: 1,
                            a2: a2 - 8,
                            a3: a2 - 4,
                            a4: a2 - 4,
                            a5: a2 - 12) != 0
      && (((v2 = *(_DWORD *)(a2 - 8)) & 0xF00) == 0xF00 || (v2 & 0xF00000) != 0)
      && *(_DWORD *)(a2 - 24) == 1970169159
      && *(_DWORD *)(a2 - 20) == 1231384169
      && *(_DWORD *)(a2 - 16) == 1818588270
      && (*(_DWORD *)(a2 - 12) & 0x10000000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F001C10
// Name: ParentWindowEnumProc
// Source: json
//------------------------------------------------------------------------------
void __userpurge ParentWindowEnumProc(int a1@<eax>, unsigned __int16 a2@<dx>, int a3@<ecx>, HWND__ *hWnd, int lParam)
{
  *(_BYTE *)(a1 + a3 - 117) *= 32;
  LOBYTE(a1) = __inbyte(a2);
  BYTE1(dword_3F041A1C) ^= (BYTE1(dword_3F041A1C) ^ (8 * ((a1 & 0x800000) != 0))) & 8;
  if ( (unsigned __int8)sub_3F001690() == 0 )
    JUMPOUT(0x3F001C4B);
  JUMPOUT(0x3F001C66);
}

//------------------------------------------------------------------------------
// Address: 0x3F001C50
// Name: _ShouldUseNewAssertDialog
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl ShouldUseNewAssertDialog()
{
  ((void (__cdecl *)(int))loc_3F001600)(a1: 1);
  JUMPOUT(0x3F001C78);
}

//------------------------------------------------------------------------------
// Address: 0x3F001C80
// Name: _DoNewAssertDialog
// Source: json
//------------------------------------------------------------------------------
void __usercall DoNewAssertDialog(unsigned __int16 a1@<dx>, int a2@<ecx>, int a3@<ebp>)
{
  char v3; // al
  char v4; // al
  char v5; // al

  __inbyte(a1);
  v3 = ((int (__cdecl *)(int, int, int, int, int))loc_3F001600)(a1: 1, a2: a3 - 24, a3: a3 - 28, a4: a3 - 32, a5: a2);
  if ( v3 != 0 )
    v3 = (*(_DWORD *)(a3 - 20) & 0x4000000) != 0;
  LOBYTE(dword_3F041A1C) = (dword_3F041A1C ^ (16 * v3)) & 0x10 ^ dword_3F041A1C;
  v4 = ((int (__cdecl *)(int, int, int, int, int))loc_3F001600)(
         a1: 1,
         a2: a3 - 24,
         a3: a3 - 28,
         a4: a3 - 20,
         a5: a3 - 32);
  if ( v4 != 0 )
    v4 = *(_BYTE *)(a3 - 20) & 1;
  LOBYTE(dword_3F041A1C) = (dword_3F041A1C ^ (32 * v4)) & 0x20 ^ dword_3F041A1C;
  v5 = ((int (__cdecl *)(int, int, int, int, int))loc_3F001600)(
         a1: 1,
         a2: a3 - 24,
         a3: a3 - 28,
         a4: a3 - 20,
         a5: a3 - 32);
  if ( v5 != 0 )
    v5 = (*(_DWORD *)(a3 - 20) & 0x200) != 0;
  LOBYTE(dword_3F041A1C) = (dword_3F041A1C ^ (v5 << 6)) & 0x40 ^ dword_3F041A1C;
  BYTE1(dword_3F041A1C) ^= (BYTE1(dword_3F041A1C) ^ (2 * ((int (*)(void))loc_3F001770)())) & 2;
  ((void (__cdecl *)(int, int, int, int, int))loc_3F001600)(a1: 1, a2: a3 - 24, a3: a3 - 28, a4: a3 - 20, a5: a3 - 32);
  JUMPOUT(0x3F001D5C);
}

//------------------------------------------------------------------------------
// Address: 0x3F001D60
// Name: _SetInAssert
// Source: json
//------------------------------------------------------------------------------
void __usercall SetInAssert(int a1@<eax>, unsigned __int16 a2@<dx>, int a3@<ecx>)
{
  *(_BYTE *)(a1 + a3 - 117) *= 32;
  __inbyte(a2);
  JUMPOUT(0x3F001D6B);
}

//------------------------------------------------------------------------------
// Address: 0x3F001D70
// Name: _IsInAssert
// Source: json
//------------------------------------------------------------------------------
void IsInAssert()
{
  __asm { aas }
  JUMPOUT(0x3F001D77);
}

//------------------------------------------------------------------------------
// Address: 0x3F003CF0
// Name: public: class CThreadLocalBase __near & CThreadLocalBase::operator=(class CThreadLocalBase const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CThreadLocalBase::operator=(_DWORD *this, _DWORD *a2)
{
  *this = *a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F003D00
// Name: public: void CThreadMutex::Unlock(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?Unlock@CThreadMutex@@QAEXXZ'
void __thiscall CThreadMutex::Unlock(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F003D10
// Name: public: bool CThreadMutex::TryLock(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadMutex::TryLock(LPCRITICAL_SECTION lpCriticalSection)
{
  if ( dword_3F0415D0 != nullptr )
    return dword_3F0415D0(a1: lpCriticalSection) != 0;
  EnterCriticalSection(lpCriticalSection);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x3F003D30
// Name: public: class CValObject __near * CValidator::PValObjectFirst(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '??BCThreadSyncObject@@QAEPAXXZ'
// Alternative name is '?Handle@CThreadSyncObject@@QAEPAXXZ'
struct CValObject *__thiscall CValidator::PValObjectFirst(CValidator *this)
{
  return this->m_pValObjectFirst;
}

//------------------------------------------------------------------------------
// Address: 0x3F003D40
// Name: public: void CThreadFullMutex::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::Lock(CThreadFullMutex *this)
{
  CThreadSyncObject::Wait(this, a2: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x3F003D50
// Name: public: void CThreadFullMutex::Lock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::Lock(CThreadFullMutex *this, unsigned int a2)
{
  JUMPOUT(0x3F00F590);
}

//------------------------------------------------------------------------------
// Address: 0x3F003D60
// Name: public: void CThreadFullMutex::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::Unlock(CThreadFullMutex *this)
{
  ReleaseMutex(hMutex: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x3F003D80
// Name: public: CThreadSemaphore::~CThreadSemaphore(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '??1CThreadEvent@@QAE@XZ'
// Alternative name is '??1CThreadFullMutex@@QAE@XZ'
void __thiscall CThreadSemaphore::~CThreadSemaphore(CThreadSemaphore *this)
{
  if ( this->m_hSyncObject != nullptr && this->m_bOwnEventHandle && !CloseHandle(hObject: this->m_hSyncObject) )
    ((void (__cdecl *)(unsigned __int8 *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &__initialmbcinfo.mbcasemap[127],
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 748,
      a5: &unk_3F041A6C,
      a6: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F003E10
// Name: public: void CThreadRWLock::LockForRead(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadRWLock::LockForRead(CThreadRWLock *this)
{
  ?LockForRead@CThreadRWLock@@QAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003E20
// Name: public: void CThreadRWLock::UnlockRead(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadRWLock::UnlockRead(CThreadRWLock *this)
{
  ?UnlockRead@CThreadRWLock@@QAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003E30
// Name: public: void CThreadRWLock::LockForWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadRWLock::LockForWrite(CThreadRWLock *this)
{
  JUMPOUT(0x3F010220);
}

//------------------------------------------------------------------------------
// Address: 0x3F003E40
// Name: public: void CThreadRWLock::UnlockWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadRWLock::UnlockWrite(CThreadRWLock *this)
{
  ?UnlockWrite@CThreadRWLock@@QAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003EA0
// Name: public: CThreadSpinRWLock::CThreadSpinRWLock(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSpinRWLock *__thiscall CThreadSpinRWLock::CThreadSpinRWLock(CThreadSpinRWLock *this)
{
  this->m_nWriters.m_value = 0;
  this->m_lockInfo.m_writerId = 0;
  this->m_lockInfo.m_nReaders = 0;
  this->m_nWriters.m_value = 0;
  *((_DWORD *)&this->m_nWriters + 1) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F003EC0
// Name: public: bool CThreadSpinRWLock::TryLockForWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this)
{
  return ?TryLockForWrite@CThreadSpinRWLock@@QAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003ED0
// Name: public: bool CThreadSpinRWLock::TryLockForRead(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThreadSpinRWLock::TryLockForRead(CThreadSpinRWLock *this)
{
  return ?TryLockForRead@CThreadSpinRWLock@@QAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003EE0
// Name: public: void CThreadSpinRWLock::LockForRead(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadSpinRWLock::LockForRead(CThreadSpinRWLock *this)
{
  JUMPOUT(0x3F0104A0);
}

//------------------------------------------------------------------------------
// Address: 0x3F003EF0
// Name: public: void CThreadSpinRWLock::UnlockRead(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadSpinRWLock::UnlockRead(CThreadSpinRWLock *this)
{
  JUMPOUT(0x3F010650);
}

//------------------------------------------------------------------------------
// Address: 0x3F003F00
// Name: public: void CThreadSpinRWLock::UnlockWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadSpinRWLock::UnlockWrite(CThreadSpinRWLock *this, int a2)
{
  ?UnlockWrite@CThreadSpinRWLock@@QAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003F10
// Name: public: class CThreadSpinRWLock __near & CThreadSpinRWLock::operator=(class CThreadSpinRWLock const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CThreadSpinRWLock::operator=(_DWORD *this, _DWORD *a2)
{
  *this = *a2;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F003F40
// Name: public: unsigned int CThread::CalcStackDepth(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThread::CalcStackDepth(CThread *this, void *a2)
{
  return (char *)this->m_pStackBase - (char *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F003F50
// Name: public: virtual CWorkerThread::~CWorkerThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerThread::~CWorkerThread(CWorkerThread *this)
{
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)&this->m_EventComplete);
  CThreadSemaphore::~CThreadSemaphore(this: (CThreadSemaphore *)&this->m_EventSend);
  CThread::~CThread(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x3F003FB0
// Name: public: void CThreadMutex::Lock(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?Lock@CThreadMutex@@QAEXXZ'
void __thiscall CThreadMutex::Lock(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F003FD0
// Name: public: CThreadRWLock::CThreadRWLock(void)
// Source: json
//------------------------------------------------------------------------------
CThreadRWLock *__thiscall CThreadRWLock::CThreadRWLock(CThreadRWLock *this)
{
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CThreadEvent::CThreadEvent(this: &this->m_CanWrite, a2: false);
  CThreadEvent::CThreadEvent(this: &this->m_CanRead, a2: true);
  this->m_nWriters = 0;
  this->m_nActiveReaders = 0;
  this->m_nPendingReaders = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F004040
// Name: public: void CThreadRWLock::LockForRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::LockForRead(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: CurrentThreadId, dwMilliseconds: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  if ( this->m_nWriters != 0 )
    CThreadRWLock::WaitForRead(this);
  ++this->m_nActiveReaders;
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0040A0
// Name: public: void CThreadRWLock::UnlockRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::UnlockRead(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx
  bool v3; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: CurrentThreadId, dwMilliseconds: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  v3 = this->m_nActiveReaders-- == 1;
  if ( v3 && this->m_nWriters != 0 )
  {
    CThreadSyncObject::AssertUseable(this: &this->m_CanWrite);
    SetEvent(hEvent: this->m_CanWrite.m_hSyncObject);
  }
  v3 = this->m_mutex.m_depth-- == 1;
  if ( v3 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F004110
// Name: private: bool CThreadSpinRWLock::AssignIf(struct CThreadSpinRWLock::LockInfo_t const __near &,struct CThreadSpinRWLock::LockInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSpinRWLock::AssignIf(
        CThreadSpinRWLock *this,
        const struct CThreadSpinRWLock::LockInfo_t *a2,
        const struct CThreadSpinRWLock::LockInfo_t *a3)
{
  signed __int64 v4; // [esp+18h] [ebp-8h]

  v4 = (signed __int64)*a3;
  return v4 == _InterlockedCompareExchange64((volatile signed __int64 *)this, (signed __int64)*a2, (signed __int64)*a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F004170
// Name: private: bool CThreadSpinRWLock::TryLockForWrite(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this, unsigned int a2)
{
  struct CThreadSpinRWLock::LockInfo_t v3; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_lockInfo.m_nReaders > 0 || this->m_lockInfo.m_writerId != 0 && this->m_lockInfo.m_writerId != a2 )
    return false;
  v3.m_writerId = a2;
  v3.m_nReaders = 0;
  return CThreadSpinRWLock::AssignIf(this, a2: &v3, a3: &`CThreadSpinRWLock::TryLockForWrite'::`5'::oldValue);
}

//------------------------------------------------------------------------------
// Address: 0x3F0041C0
// Name: public: bool CThreadSpinRWLock::TryLockForWrite(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this)
{
  CInterlockedIntT<int> *p_m_nWriters; // edi
  DWORD CurrentThreadId; // eax
  struct CThreadSpinRWLock::LockInfo_t v5; // [esp+8h] [ebp-8h] BYREF

  p_m_nWriters = &this->m_nWriters;
  _InterlockedExchangeAdd(&this->m_nWriters.m_value, 1u);
  CurrentThreadId = GetCurrentThreadId();
  if ( this->m_lockInfo.m_nReaders <= 0
    && (this->m_lockInfo.m_writerId == 0 || this->m_lockInfo.m_writerId == CurrentThreadId) )
  {
    v5.m_writerId = CurrentThreadId;
    v5.m_nReaders = 0;
    if ( CThreadSpinRWLock::AssignIf(this, a2: &v5, a3: &`CThreadSpinRWLock::TryLockForWrite'::`5'::oldValue) )
      return 1;
  }
  _InterlockedExchangeAdd(&p_m_nWriters->m_value, 0xFFFFFFFF);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F004230
// Name: public: bool CThreadSpinRWLock::TryLockForRead(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadSpinRWLock::TryLockForRead(CThreadSpinRWLock *this)
{
  signed __int64 v2; // [esp+18h] [ebp-8h]

  if ( this->m_nWriters.m_value != 0 )
    return false;
  LODWORD(v2) = 0;
  HIDWORD(v2) = this->m_lockInfo.m_nReaders;
  return v2 == _InterlockedCompareExchange64((volatile signed __int64 *)this, __SPAIR64__(HIDWORD(v2) + 1, 0), v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F0042A0
// Name: public: void CThreadSpinRWLock::LockForWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?LockForWrite@CThreadSpinRWLock@@QAEXXZ'
void __thiscall CThreadSpinRWLock::LockForWrite(CThreadSpinRWLock *this)
{
  DWORD CurrentThreadId; // edi

  CurrentThreadId = GetCurrentThreadId();
  _InterlockedExchangeAdd(&this->m_nWriters.m_value, 1u);
  if ( !CThreadSpinRWLock::TryLockForWrite(this, a2: CurrentThreadId) )
  {
    _mm_pause();
    CThreadSpinRWLock::SpinLockForWrite(this, a2: CurrentThreadId);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0096D0
// Name: public: bool CThreadFullMutex::AssertOwnedByCurrentThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::AssertOwnedByCurrentThread(CThread *this)
{
  (*(void (**)(void))((char *)this + 106))();
  JUMPOUT(0x3F0096D3);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A050
// Name: public: __int64 CValidator::GetCubTotal(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CValidator::GetCubTotal(CValidator *this)
{
  return *((_QWORD *)this + 263);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A060
// Name: public: bool CValidator::BCountingOnly(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CValidator::BCountingOnly(CValidator *this)
{
  return *((_BYTE *)this + 2112);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A070
// Name: public: void CValidator::AddToTotal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::AddToTotal(CValidator *this, int a2)
{
  *((_QWORD *)this + 263) += a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A090
// Name: public: bool CValidator::BMemLeaks(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CValidator::BMemLeaks(CValidator *this)
{
  return (bool)this->m_threadMutexValidationLock[1];
}

//------------------------------------------------------------------------------
// Address: 0x3F00A0A0
// Name: public: class CValidator __near & CValidator::operator=(class CValidator const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CValidator::operator=(void *this, const void *a2)
{
  qmemcpy(this, a2, 0x848u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F010050
// Name: public: bool CThreadMutex::TryLock(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadMutex::TryLock(LPCRITICAL_SECTION lpCriticalSection, int a2)
{
  if ( dword_3F0415D0 != nullptr )
    return dword_3F0415D0(a1: lpCriticalSection) != 0;
  EnterCriticalSection(lpCriticalSection);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x3F0102A0
// Name: public: void CThreadRWLock::UnlockWrite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::UnlockWrite(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx
  bool v3; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: CurrentThreadId, dwMilliseconds: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  v3 = this->m_nWriters-- == 1;
  if ( v3 )
  {
    if ( this->m_nPendingReaders != 0 )
    {
      CThreadSyncObject::AssertUseable(this: &this->m_CanRead);
      SetEvent(hEvent: this->m_CanRead.m_hSyncObject);
    }
  }
  else
  {
    CThreadSyncObject::AssertUseable(this: &this->m_CanWrite);
    SetEvent(hEvent: this->m_CanWrite.m_hSyncObject);
  }
  v3 = this->m_mutex.m_depth-- == 1;
  if ( v3 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F010810
// Name: public: void CThreadSpinRWLock::UnlockWrite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSpinRWLock::UnlockWrite(CThreadSpinRWLock *this, const char *a2)
{
  CVProfile *v2; // ecx

  GetCurrentThreadId();
  CVProfile::BudgetGroupNameToBudgetGroupID(this: v2, pBudgetGroupName: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F010D80
// Name: protected: bool CThread::BHasValidThreadID(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThread::BHasValidThreadID(CThread *this)
{
  return this->m_hThread != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F010D90
// Name: protected: virtual bool CThread::IsThreadRunning(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThread::IsThreadRunning(CThread *this)
{
  char v1; // bl
  HANDLE v2; // esi
  unsigned int ExitCode; // [esp+8h] [ebp-4h] BYREF

  v1 = 1;
  v2 = OpenThread(dwDesiredAccess: 0x40u, bInheritHandle: false, dwThreadId: this->m_threadId);
  if ( v2 == nullptr )
    return 0;
  if ( !GetExitCodeThread(hThread: v2, lpExitCode: &ExitCode) || ExitCode != 259 )
    v1 = 0;
  CloseHandle(hObject: v2);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F011100
// Name: private: virtual unsigned int (*CThread::GetThreadProc(void))(void __near *)
// Source: json
//------------------------------------------------------------------------------
void (__userpurge *__thiscall CThread::GetThreadProc(
        CThread *this))(std::vector<TimeSums_t> *this, const TimeSums_t *_Val@<ebx>)
{
  return std::vector<TimeSums_t>::push_back;
}

//------------------------------------------------------------------------------
// Address: 0x3F011A00
// Name: public: void CValidator::SetAllocSizeFilter(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::SetAllocSizeFilter(CValidator *this, int a2)
{
  this->m_cpvOwned = a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F011BC0
// Name: public: bool CValidator::IsClaimed(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CValidator::IsClaimed(CValidator *this, void *a2)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x3F011BD0
// Name: public: void CValidator::ClaimUntrackedMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::ClaimUntrackedMemory(CValidator *this, int a2)
{
  if ( *((_BYTE *)this + 2112) != 0 )
  {
    *((_QWORD *)this + 263) += a2;
  }
  else if ( BYTE1(this->m_threadMutexValidationLock[1]) == 0 && this->m_pValObjectCur != nullptr )
  {
    sub_3F012520(a1: a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F001000
// Name: _DllMain@12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  CThreadMutex *v3; // ecx
  BOOL result; // eax

  if ( fdwReason == 1 )
    JUMPOUT(0x3F00101F);
  if ( fdwReason == 2 )
    JUMPOUT(0x3F001024);
  CThreadMutex::Unlock(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F001020
// Name: ?TryLock@CThreadMutex@@QBE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CThreadMutex::TryLock@<eax>(
        CThreadMutex *this@<ecx>,
        int _EAX@<eax>,
        _DWORD *a3@<ebx>,
        int a4,
        int a5,
        int a6)
{
  *a3 = __ROL4__(*a3, (char)this);
  __asm { aas }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F001040
// Name: ?PValObjectFirst@CValidator@@QAEPAVCValObject@@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CValidator::PValObjectFirst(CThreadSyncObject *this@<ecx>, unsigned int a2@<ebx>)
{
  __writefsdword(a2, __ROL4__(__readfsdword(a2), (char)this));
  JUMPOUT(0x3F001045);
}

//------------------------------------------------------------------------------
// Address: 0x3F001050
// Name: ?Lock@CThreadFullMutex@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadFullMutex::Lock(CThreadFullMutex *this)
{
  JUMPOUT(0x3F001059);
}

//------------------------------------------------------------------------------
// Address: 0x3F001110
// Name: ??_FCThreadEvent@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadEvent::`default constructor closure'(CThreadEvent *this)
{
  JUMPOUT(0x3F001112);
}

//------------------------------------------------------------------------------
// Address: 0x3F001120
// Name: ?LockForRead@CThreadRWLock@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F001140
// Name: ?LockForWrite@CThreadRWLock@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::LockForWrite(CThreadRWLock *this)
{
  ((void (__thiscall *)(CThreadRWLock *))loc_3F0010E0)(a1: this);
  JUMPOUT(0x3F001148);
}

//------------------------------------------------------------------------------
// Address: 0x3F001150
// Name: ?UnlockWrite@CThreadRWLock@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::UnlockWrite(CThreadRWLock *this)
{
  *((_BYTE *)this + 131208) |= (unsigned __int8)this;
  JUMPOUT(0x3F001156);
}

//------------------------------------------------------------------------------
// Address: 0x3F001160
// Name: ??1CThreadRWLock@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::~CThreadRWLock(
        CThreadRWLock *this,
        HWND hDlg,
        BOOL Translated,
        CThreadSpinRWLock *a4,
        int a5)
{
  UINT DlgItemInt; // eax
  CThreadRWLock *v6; // ecx
  UINT v7; // esi
  UINT v8; // ebx
  int v9; // eax

  switch ( Translated )
  {
    case 256:
LABEL_13:
      if ( a4 == (CThreadSpinRWLock *)2 )
        EndDialog(hDlg, nResult: 0);
      break;
    case 272:
      JUMPOUT(0x3F00138C);
    case 273:
      switch ( (__int16)a4 )
      {
        case 1002:
          ((void (*)(void))loc_3F0010E0)();
          EndDialog(hDlg, nResult: 0);
          JUMPOUT(0x3F0011BC);
        case 1003:
          CThreadSpinRWLock::UnlockRead(this: a4);
          return;
        case 1005:
          Translated = false;
          DlgItemInt = GetDlgItemInt(hDlg, nIDDlgItem: 1010, lpTranslated: &Translated, bSigned: false);
          v7 = DlgItemInt;
          if ( Translated && DlgItemInt > 1 )
          {
            v8 = DlgItemInt - 1;
            CThreadRWLock::LockForWrite(this: v6);
            *(_DWORD *)(v9 + 520) = v8;
            dword_3F03C280 = v7;
          }
          JUMPOUT(0x3F00120F);
        case 1006:
          JUMPOUT(0x3F0012A2);
        default:
          goto LABEL_13;
      }
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F001210
// Name: ?TryLockForWrite@CThreadSpinRWLock@@QBE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this)
{
  JUMPOUT(0x3F001215);
}

//------------------------------------------------------------------------------
// Address: 0x3F001240
// Name: ?UnlockRead@CThreadSpinRWLock@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadSpinRWLock::UnlockRead(CThreadSpinRWLock *this@<ecx>, int a2@<ebp>)
{
  *(_DWORD *)(a2 + 12) = 0;
  JUMPOUT(0x3F001248);
}

//------------------------------------------------------------------------------
// Address: 0x3F001250
// Name: ?UnlockWrite@CThreadSpinRWLock@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadSpinRWLock::UnlockWrite(CThreadSpinRWLock *this@<ecx>, char a2@<al>)
{
  if ( a2 != 0 )
    JUMPOUT(0x3F001258);
  JUMPOUT(0x3F001449);
}

//------------------------------------------------------------------------------
// Address: 0x3F001280
// Name: ?CalcStackDepth@CThread@@QAEIPAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CThread::CalcStackDepth(CThread *this@<ecx>, int a2@<ebx>, void *pStackVariable)
{
  *(_BYTE *)(a2 + 6948941) += (_BYTE)this;
  byte_3F03C284 = 0;
  JUMPOUT(0x3F00128E);
}

//------------------------------------------------------------------------------
// Address: 0x3F001290
// Name: ??1CWorkerThread@@UAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CWorkerThread::~CWorkerThread(
        CWorkerThread *this@<ecx>,
        char _BH@<bh>,
        int _EDI@<edi>,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __asm { repne add bh, [edi] }
}

//------------------------------------------------------------------------------
// Address: 0x3F001300
// Name: ?Lock@CThreadMutex@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadMutex::Lock(CThreadMutex *this@<ecx>, int _EAX@<eax>)
{
  __asm { rcl     dword ptr [eax-1], cl }
  JUMPOUT(0x3F001308);
}

//------------------------------------------------------------------------------
// Address: 0x3F001310
// Name: ??0CThreadRWLock@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CThreadRWLock *__userpurge CThreadRWLock::CThreadRWLock@<eax>(
        CThreadRWLock *this@<ecx>,
        void *a2@<eax>,
        HWND a3@<edi>,
        int a4,
        int a5,
        int a6,
        int a7)
{
  char *v8; // eax

  __asm { icebp }
  if ( a2 != nullptr )
  {
    v8 = (char *)GlobalLock(hMem: a2);
    wsprintfA(
      a1: v8,
      a2: "File: %s\r\nLine: %d\r\nAssertion: %s\r\n",
      (const char *)dword_3F03D294,
      uValue,
      (const char *)dword_3F03D29C);
    GlobalUnlock(hMem: a2);
    SetClipboardData(uFormat: 1u, hMem: a2);
    if ( CloseClipboard() )
      JUMPOUT(0x3F001449);
  }
  MessageBoxA(hWnd: a3, lpText: "Assert", lpCaption: "Couldn't copy to clipboard.", uType: 0x10u);
  return (CThreadRWLock *)1;
}

//------------------------------------------------------------------------------
// Address: 0x3F001390
// Name: ?LockForRead@CThreadRWLock@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadRWLock::LockForRead(
        CThreadRWLock *this@<ecx>,
        int a2@<edx>,
        int a3@<ebp>,
        void (__thiscall *a4)(CThreadRWLock *, HWND, int, int)@<edi>,
        HWND a5@<esi>)
{
  HWND DesktopWindow; // eax

  a4(a1: this, a2: a5, a3: 1012, a4: a2);
  ((void (__cdecl *)(HWND, int, int))a4)(a1: a5, a2: 1000, a3: dword_3F03D294);
  SetDlgItemInt(hDlg: a5, nIDDlgItem: 1001, uValue: uValue, bSigned: false);
  SetDlgItemInt(hDlg: a5, nIDDlgItem: 1004, uValue: 5u, bSigned: false);
  SetDlgItemInt(hDlg: a5, nIDDlgItem: 1010, uValue: dword_3F03C280, bSigned: false);
  GetWindowRect(hWnd: a5, lpRect: (LPRECT)(a3 - 16));
  DesktopWindow = GetDesktopWindow();
  GetWindowRect(hWnd: DesktopWindow, lpRect: (LPRECT)(a3 - 32));
  SetWindowPos(
    hWnd: a5,
    hWndInsertAfter: nullptr,
    X: (*(_DWORD *)(a3 - 24) + *(_DWORD *)(a3 - 16) - *(_DWORD *)(a3 - 8) - *(_DWORD *)(a3 - 32)) / 2,
    Y: (*(_DWORD *)(a3 - 20) + *(_DWORD *)(a3 - 12) - *(_DWORD *)(a3 - 4) - *(_DWORD *)(a3 - 28)) / 2,
    cx: 0,
    cy: 0,
    uFlags: 1u);
  JUMPOUT(0x3F00142A);
}

//------------------------------------------------------------------------------
// Address: 0x3F001430
// Name: ?UnlockRead@CThreadRWLock@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CThreadRWLock::UnlockRead(CThreadRWLock *this@<ecx>, int a2@<ebx>, int a3, int a4, int a5, int a6)
{
  *(_BYTE *)(a2 - 117) += a2;
  __indword(0x5Du);
}

//------------------------------------------------------------------------------
// Address: 0x3F001480
// Name: EnumFunc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall EnumFunc(HWND__ *hWnd, HWND__ *a2)
{
  HWND v2; // esi

  v2 = hWnd;
  if ( !IsWindowVisible(hWnd) )
    return 1;
  GetWindowThreadProcessId(hWnd: v2, lpdwProcessId: (LPDWORD)&hWnd);
  if ( hWnd != a2 )
    return 1;
  dword_3F03D290 = (int)v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0014E0
// Name: ?AssignIf@CThreadSpinRWLock@@AAE_NABULockInfo_t@1@0@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall CThreadSpinRWLock::AssignIf@<eax>(CThreadSpinRWLock *this@<ecx>, int _EAX@<eax>)
{
  __asm { aas }
  return _EAX != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F001540
// Name: ?TryLockForWrite@CThreadSpinRWLock@@AAE_NI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this@<ecx>, int _ESI@<esi>)
{
  __asm { fcomp   dword ptr [esi+5Dh] }
}

//------------------------------------------------------------------------------
// Address: 0x3F0015C0
// Name: ?TryLockForWrite@CThreadSpinRWLock@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __fastcall CThreadSpinRWLock::TryLockForWrite(CThreadSpinRWLock *this, HINSTANCE a2)
{
  DialogBoxParamA(
    hInstance: a2,
    lpTemplateName: (LPCSTR)0x65,
    hWndParent: (HWND)this,
    lpDialogFunc: (DLGPROC)CThreadRWLock::~CThreadRWLock,
    dwInitParam: 0);
  return byte_3F03D368;
}

//------------------------------------------------------------------------------
// Address: 0x3F001640
// Name: ?TryLockForRead@CThreadSpinRWLock@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CThreadSpinRWLock::TryLockForRead(CThreadSpinRWLock *this)
{
  __asm { fmul    dword ptr [this+0DEBDC55h] }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00164D
// Name: sub_3F00164D
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall sub_3F00164D@<al>(_DWORD **a1@<ebp>)
{
  int v2; // [esp-1Ch] [ebp-1Ch]

  *((_BYTE *)a1 - 25) = 0;
  *(a1 - 1) = (_DWORD *)-1;
  *a1[3] = *(a1 - 8);
  *a1[4] = *(a1 - 11);
  *a1[5] = *(a1 - 10);
  *a1[6] = *(a1 - 9);
  return *(_BYTE *)(v2 - 25);
}

//------------------------------------------------------------------------------
// Address: 0x3F001690
// Name: sub_3F001690
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F001690()
{
  CThreadSpinRWLock *v0; // ecx
  _BYTE v1[156]; // [esp+8h] [ebp-9Ch] BYREF

  memset_0(a1: v1, Val: 0, Size: sizeof(v1));
  CThreadSpinRWLock::LockForWrite(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x3F0016B0
// Name: ?LockForWrite@CThreadSpinRWLock@@QBEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CThreadSpinRWLock::LockForWrite(CThreadSpinRWLock *this@<ecx>, int a2@<ebp>)
{
  CValidator *v2; // ecx

  *(_DWORD *)(a2 - 156) = 156;
  if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)(a2 - 156)) )
  {
    *(_DWORD *)(a2 - 156) = 148;
    if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)(a2 - 156)) )
      ((void (__cdecl *)(const char *))Error)(a1: "IsWin98OrOlder:  Unable to get OS version information");
  }
  if ( *(_DWORD *)(a2 - 140) <= 1u )
    JUMPOUT(0x3F001707);
  CValidator::BMemLeaks(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F001710
// Name: ?BMemLeaks@CValidator@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CValidator::BMemLeaks(CValidator *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0042E0
// Name: sub_3F0042E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int sub_3F0042E0()
{
  return sub_3F0043F0();
}

//------------------------------------------------------------------------------
// Address: 0x3F0042F0
// Name: sub_3F0042F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall sub_3F0042F0(volatile signed __int64 *a1, unsigned int *a2)
{
  volatile signed __int64 *v2; // eax
  unsigned int *i; // esi
  unsigned int v4; // ecx
  unsigned int v5; // eax

  v2 = a1;
  for ( i = a2; ; i = a2 )
  {
    v4 = *(_DWORD *)v2;
    v5 = *((_DWORD *)v2 + 1);
    *i = v4;
    if ( __PAIR64__(v5, v4) == _InterlockedCompareExchange64(
                                 a1,
                                 __SPAIR64__(v5 + 65537, (unsigned int)i),
                                 __SPAIR64__(v5, v4)) )
      break;
    _mm_pause();
    v2 = a1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F004360
// Name: sub_3F004360
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__stdcall sub_3F004360(int a1)
{
  _DWORD *v1; // eax
  unsigned int v2; // ecx
  _DWORD *v4; // [esp+20h] [ebp-8h]

  v1 = *(_DWORD **)a1;
  v2 = *(_DWORD *)(a1 + 4);
  v4 = *(_DWORD **)a1;
  if ( *(_DWORD *)a1 == 0 )
    return nullptr;
  while ( __PAIR64__(v2, (unsigned int)v1) != _InterlockedCompareExchange64(
                                                (volatile signed __int64 *)a1,
                                                __SPAIR64__(v2 - 1, *v1),
                                                __SPAIR64__(v2, (unsigned int)v1)) )
  {
    _mm_pause();
    v1 = *(_DWORD **)a1;
    v2 = *(_DWORD *)(a1 + 4);
    v4 = *(_DWORD **)a1;
    if ( *(_DWORD *)a1 == 0 )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F0043F0
// Name: sub_3F0043F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F0043F0(CSmallBlockHeap *this)
{
  CSmallBlockHeap::~CSmallBlockHeap(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A0C0
// Name: sub_3F00A0C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int sub_3F00A0C0()
{
  unsigned int result; // eax

  result = Frequency.HighPart | Frequency.LowPart;
  if ( Frequency.QuadPart == 0 )
  {
    QueryPerformanceFrequency(lpFrequency: &Frequency);
    qword_3F03D318 = Frequency.QuadPart / 1000;
    QueryPerformanceCounter(lpPerformanceCount: &PerformanceCount);
    qword_3F03D308 = PerformanceCount.QuadPart;
    return PerformanceCount.LowPart;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F010820
// Name: ?BudgetGroupNameToBudgetGroupID@CVProfile@@QAEHPBD@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::BudgetGroupNameToBudgetGroupID(
        CVProfile *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<esi>,
        const char *pBudgetGroupName)
{
  if ( *a3 != a2 || a3[1] != 0 )
    ((void (__cdecl *)(const char *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: m_lockInfo.m_writerId == ThreadGetCurrentId() && m_lockInfo.m_nReaders == 0",
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 2517,
      a5: &unk_3F041A7B,
      a6: 0);
  ThreadInterlockedExchange64(a1: a3, a2: 0, a3: 0);
  JUMPOUT(0x3F010866);
}

} // namespace tier0_s
