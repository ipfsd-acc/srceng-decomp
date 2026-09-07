// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/platform.cpp
// Functions: 25
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000A500
// Name: InitTime
// Source: json
//------------------------------------------------------------------------------
BOOL InitTime()
{
  BOOL result; // eax

  if ( !s_bTimeInitted )
  {
    s_bTimeInitted = true;
    QueryPerformanceFrequency(lpFrequency: &g_PerformanceFrequency);
    g_MSPerformanceFrequency.QuadPart = g_PerformanceFrequency.QuadPart / 1000;
    return QueryPerformanceCounter(lpPerformanceCount: &g_ClockStart);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A550
// Name: _Plat_IsInBenchmarkMode
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Plat_IsInBenchmarkMode()
{
  return g_bBenchmarkMode;
}

//------------------------------------------------------------------------------
// Address: 0x1000A560
// Name: _Plat_SetBenchmarkMode
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_SetBenchmarkMode(bool bBenchmark)
{
  g_bBenchmarkMode = bBenchmark;
}

//------------------------------------------------------------------------------
// Address: 0x1000A570
// Name: _Plat_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl Plat_FloatTime()
{
  long double result; // st7
  _LARGE_INTEGER CurrentTime; // [esp+0h] [ebp-8h] BYREF

  if ( !s_bTimeInitted )
    InitTime();
  if ( g_bBenchmarkMode )
  {
    result = g_FakeBenchmarkTimeInc + g_FakeBenchmarkTime;
    g_FakeBenchmarkTime = g_FakeBenchmarkTimeInc + g_FakeBenchmarkTime;
  }
  else
  {
    QueryPerformanceCounter(lpPerformanceCount: &CurrentTime);
    return (double)(CurrentTime.QuadPart - g_ClockStart.QuadPart) / (double)g_PerformanceFrequency.QuadPart;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A5E0
// Name: _Plat_MSTime
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Plat_MSTime()
{
  __int64 v0; // rax
  _LARGE_INTEGER CurrentTime; // [esp+0h] [ebp-Ch] BYREF

  if ( !s_bTimeInitted )
    InitTime();
  if ( g_bBenchmarkMode )
  {
    g_FakeBenchmarkTime = g_FakeBenchmarkTimeInc + g_FakeBenchmarkTime;
    CurrentTime.QuadPart = (__int64)(g_FakeBenchmarkTime * 1000.0);
    LODWORD(v0) = CurrentTime.LowPart;
  }
  else
  {
    QueryPerformanceCounter(lpPerformanceCount: &CurrentTime);
    return (CurrentTime.QuadPart - g_ClockStart.QuadPart) / g_MSPerformanceFrequency.QuadPart;
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A670
// Name: _Timer_GetTimeUS
// Source: json
//------------------------------------------------------------------------------
__int64 __cdecl Timer_GetTimeUS()
{
  return 1000LL * Plat_MSTime();
}

//------------------------------------------------------------------------------
// Address: 0x1000A680
// Name: _Plat_GetClockStart
// Source: json
//------------------------------------------------------------------------------
_LARGE_INTEGER __cdecl Plat_GetClockStart()
{
  if ( !s_bTimeInitted )
    InitTime();
  return g_ClockStart;
}

//------------------------------------------------------------------------------
// Address: 0x1000A6A0
// Name: _Plat_ConvertToLocalTime
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_ConvertToLocalTime(unsigned __int64 nTime, tm *pNow)
{
  DWORD CurrentThreadId; // ecx
  tm *v3; // eax
  __int64 ltime; // [esp+0h] [ebp-8h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_LocalTimeMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_LocalTimeMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &g_LocalTimeMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++g_LocalTimeMutex.m_depth;
  }
  ltime = nTime;
  v3 = _localtime64(ptime: &ltime);
  if ( v3 != nullptr )
  {
    *pNow = *v3;
  }
  else
  {
    *(_QWORD *)&pNow->tm_sec = 0;
    *(_QWORD *)&pNow->tm_hour = 0;
    *(_QWORD *)&pNow->tm_mon = 0;
    *(_QWORD *)&pNow->tm_wday = 0;
    pNow->tm_isdst = 0;
  }
  if ( --g_LocalTimeMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_LocalTimeMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A770
// Name: _Plat_GetTimeString
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_GetTimeString(tm *pTime, char *pOut, unsigned int nMaxBytes)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 *v4; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_LocalTimeMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_LocalTimeMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &g_LocalTimeMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++g_LocalTimeMutex.m_depth;
  }
  v4 = (unsigned __int8 *)asctime(tb: pTime);
  strncpy(dest: (unsigned __int8 *)pOut, source: v4, count: nMaxBytes);
  pOut[nMaxBytes - 1] = 0;
  if ( --g_LocalTimeMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_LocalTimeMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A7F0
// Name: _Plat_gmtime
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_gmtime(unsigned __int64 nTime, tm *pTime)
{
  __int64 tmtTime; // [esp+0h] [ebp-8h] BYREF

  tmtTime = nTime;
  _gmtime64_s(ptm: pTime, timp: &tmtTime);
}

//------------------------------------------------------------------------------
// Address: 0x1000A820
// Name: _Plat_GetModuleFilename
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_GetModuleFilename(char *pOut, DWORD nMaxBytes)
{
  SetLastError(dwErrCode: 0);
  GetModuleFileNameA(hModule: nullptr, lpFilename: pOut, nSize: nMaxBytes);
  if ( GetLastError() != 0 )
    Error(pMsgFormat: "Plat_GetModuleFilename: The buffer given is too small (%d bytes).", nMaxBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1000A860
// Name: _Plat_ExitProcess
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_ExitProcess(UINT nCode)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: nCode);
}

//------------------------------------------------------------------------------
// Address: 0x1000A880
// Name: _vtune
// Source: json
//------------------------------------------------------------------------------
char __cdecl vtune(bool resume)
{
  HMODULE LibraryA; // eax
  HMODULE v2; // esi
  void (__cdecl *VTPause)(); // eax

  if ( bInitialized
    || (bInitialized = true, LibraryA = LoadLibraryA(lpLibFileName: "vtuneapi.dll"), v2 = LibraryA, LibraryA == nullptr) )
  {
    VTPause = ::VTPause;
  }
  else
  {
    VTResume = (void (__cdecl *)())GetProcAddress(hModule: LibraryA, lpProcName: "VTResume");
    VTPause = (void (__cdecl *)())GetProcAddress(hModule: v2, lpProcName: "VTPause");
    ::VTPause = VTPause;
  }
  if ( resume )
    VTPause = VTResume;
  if ( VTPause == nullptr )
    return 0;
  VTPause();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8F0
// Name: _Plat_IsInDebugSession
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Plat_IsInDebugSession()
{
  return IsDebuggerPresent();
}

//------------------------------------------------------------------------------
// Address: 0x1000A900
// Name: _Plat_DebugString
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_DebugString(const char *psz)
{
  OutputDebugStringA(lpOutputString: psz);
}

//------------------------------------------------------------------------------
// Address: 0x1000A910
// Name: _Plat_MessageBox
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_MessageBox(const char *pTitle, const char *pMessage)
{
  MessageBoxA(hWnd: nullptr, lpText: pMessage, lpCaption: pTitle, uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A930
// Name: _Plat_GetOSVersion
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Plat_GetOSVersion()
{
  _OSVERSIONINFOA info; // [esp+0h] [ebp-94h] BYREF

  info.dwOSVersionInfoSize = 148;
  if ( GetVersionExA(lpVersionInformation: &info) )
    return info.dwMajorVersion;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A970
// Name: _Plat_GetCommandLineA
// Source: json
//------------------------------------------------------------------------------
// Alternative name is 'Plat_GetCommandLine'
// attributes: thunk
LPSTR __stdcall Plat_GetCommandLineA()
{
  return GetCommandLineA();
}

//------------------------------------------------------------------------------
// Address: 0x1000A980
// Name: _Plat_GetProcAddress
// Source: json
//------------------------------------------------------------------------------
FARPROC __cdecl Plat_GetProcAddress(const char *pszModule, const char *pszName)
{
  HMODULE LibraryA; // eax

  LibraryA = LoadLibraryA(lpLibFileName: pszModule);
  if ( LibraryA != nullptr )
    return GetProcAddress(hModule: LibraryA, lpProcName: pszName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000A9B0
// Name: _Plat_Alloc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl Plat_Alloc(unsigned int size)
{
  void *v1; // esi

  EnterCriticalSection(lpCriticalSection: &g_AllocCS);
  v1 = g_pMemAlloc->Alloc_2(this: g_pMemAlloc, a2: size);
  LeaveCriticalSection(lpCriticalSection: &g_AllocCS);
  if ( v1 != nullptr )
    return v1;
  g_AllocError(a1: size);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA00
// Name: _Plat_Realloc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl Plat_Realloc(void *ptr, unsigned int size)
{
  void *v2; // esi

  EnterCriticalSection(lpCriticalSection: &g_AllocCS);
  v2 = g_pMemAlloc->Realloc_2(this: g_pMemAlloc, a2: ptr, a3: size);
  LeaveCriticalSection(lpCriticalSection: &g_AllocCS);
  if ( v2 != nullptr )
    return v2;
  g_AllocError(a1: size);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA50
// Name: _Plat_Free
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_Free(void *ptr)
{
  EnterCriticalSection(lpCriticalSection: &g_AllocCS);
  g_pMemAlloc->Free_2(this: g_pMemAlloc, a2: ptr);
  LeaveCriticalSection(lpCriticalSection: &g_AllocCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000AA80
// Name: _Plat_SetAllocErrorFn
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_SetAllocErrorFn(void (__cdecl *fn)(unsigned int))
{
  g_AllocError = fn;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA90
// Name: _Plat_GetLocalTime
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_GetLocalTime(tm *pNow)
{
  __int64 ltime; // [esp+0h] [ebp-8h] BYREF

  _time64(timeptr: &ltime);
  Plat_ConvertToLocalTime(nTime: ltime, pNow);
}

//------------------------------------------------------------------------------
// Address: 0x1000AAC0
// Name: _GetCurrentDate
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCurrentDate(int *pDay, int *pMonth, int *pYear)
{
  int tm_mon; // eax
  int tm_year; // edx
  tm long_time; // [esp+0h] [ebp-2Ch] BYREF
  __int64 timeptr; // [esp+24h] [ebp-8h] BYREF

  _time64(&timeptr);
  Plat_ConvertToLocalTime(nTime: timeptr, pNow: &long_time);
  tm_mon = long_time.tm_mon;
  *pDay = long_time.tm_mday;
  tm_year = long_time.tm_year;
  *pMonth = tm_mon + 1;
  *pYear = tm_year + 1900;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F005350
// Name: InitTime
// Source: json
//------------------------------------------------------------------------------
long double __usercall InitTime@<st0>(int a1@<ebx>, unsigned int a2@<edi>, _DWORD *a3@<esi>)
{
  unsigned int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax

  v3 = a3[1932];
  if ( v3 <= a2 || a3[1928] == a1 || a2 >= v3 )
    JUMPOUT(0x3F0053C4);
  v4 = a3[1929];
  v5 = *(_DWORD *)(v4 + a2);
  v6 = a2 + v4;
  if ( v5 == -1441723155 )
  {
    sub_3F003A60(a1: v6 + 16);
    goto LABEL_12;
  }
  if ( v5 != a1 )
  {
    Msg(a1: (int)"item %x sentinel corrupted. skipping.\n", a2);
LABEL_12:
    JUMPOUT(0x3F0053B6);
  }
  *(_DWORD *)(v6 + 12) = a3[1933];
  return Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x3F0053B0
// Name: _Plat_FloatTime
// Source: json
//------------------------------------------------------------------------------
void __usercall Plat_FloatTime(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, _DWORD *a4@<esi>)
{
  int v4; // eax
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax

  a4[1933] = a3;
  if ( (unsigned int)(a4[1928] + a3) >= a4[1932] )
  {
    if ( a4[1935] == a1 )
    {
      a4[1926] = *(_DWORD *)(a2 + 8);
      v4 = *(_DWORD *)(a2 + 12);
      a4[1927] = v4;
      v6 = (v4 + 3) & 0xFFFFFFFC;
      a4[1929] = v6;
      v5 = v6 + 180;
      LODWORD(v6) = 256;
      if ( v5 > 0x100 )
      {
        do
          v6 *= 2LL;
        while ( v6 < v5 );
      }
      a4[1928] = v6;
    }
    JUMPOUT(0x3F00541E);
  }
  JUMPOUT(0x3F005370);
}

//------------------------------------------------------------------------------
// Address: 0x3F005420
// Name: _Plat_MSTime
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
volatile __int32 *__userpurge Plat_MSTime@<eax>(
        char a1@<cf>,
        volatile __int32 *result@<eax>,
        __int32 a3@<edx>,
        int a4@<ecx>,
        _BYTE *a5@<ebx>,
        int a6,
        int a7,
        int a8)
{
  *(_BYTE *)(a4 + 1971342) += a4 + a1;
  *a5 += BYTE1(a3);
  byte_3F03D3C0[(_DWORD)result] >>= a4;
  _InterlockedExchange(result, a3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F005460
// Name: _vtune
// Source: json
//------------------------------------------------------------------------------
const void *__usercall vtune@<eax>(char a1@<dh>, CVProfNode *a2@<ecx>, int a3@<ebx>, size_t a4@<edi>)
{
  const void *result; // eax
  void (__thiscall *v5)(int, size_t); // edx

  *(_BYTE *)(2 * a3 + 0x3B) |= a1;
  if ( a4 > MEMORY[0x3C34] || (result = CVProfNode::GetOrigNameAddress(this: a2)) == nullptr )
  {
    dword_3F03D3BC += a4;
    if ( a4 > 0x400 )
      goto LABEL_8;
    result = (const void *)(*(int (__thiscall **)(int))(MEMORY[0x1E18] + 148))(a1: 7704);
    if ( result == nullptr )
    {
      if ( byte_3F041A35 == 0 )
      {
        (*(void (__thiscall **)(int))(MEMORY[0x1E18] + 120))(a1: 7704);
        v5 = *(void (__thiscall **)(int, size_t))(MEMORY[0x1E18] + 148);
        byte_3F041A35 = 1;
        v5(a1: 7704, a2: a4);
        JUMPOUT(0x3F0054C4);
      }
LABEL_8:
      malloc_0(Size: a4);
      JUMPOUT(0x3F0054CF);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0054D0
// Name: _Plat_IsInDebugSession
// Source: json
//------------------------------------------------------------------------------
void __usercall Plat_IsInDebugSession(int a1@<ebp>)
{
  *(_BYTE *)(a1 + 17) = 0;
  JUMPOUT(0x3F0054DD);
}

//------------------------------------------------------------------------------
// Address: 0x3F0054F0
// Name: _Plat_Alloc
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_Alloc(unsigned int size)
{
  _DWORD *v1; // ecx

  if ( size != 0 )
  {
    if ( size + v1[1928] < v1[1931] && size >= v1[1930] )
      JUMPOUT(0x3F005523);
    JUMPOUT(0x3F0055A8);
  }
  JUMPOUT(0x3F005596);
}

//------------------------------------------------------------------------------
// Address: 0x3F005560
// Name: _Plat_Free
// Source: json
//------------------------------------------------------------------------------
void __usercall Plat_Free(int a1@<ebp>, char *a2@<edi>, int a3@<esi>)
{
  size_t v3; // eax

  if ( (unsigned int)a2 < *(_DWORD *)(a3 + 7720) )
    v3 = 0;
  else
    v3 = *(_DWORD *)&a2[*(_DWORD *)(a3 + 7716) + 4];
  memcpy_1(a1: *(void **)(a1 + 12), Src: a2, Size: v3);
  JUMPOUT(0x3F005584);
}

//------------------------------------------------------------------------------
// Address: 0x3F005590
// Name: _Is64BitWindows
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall Is64BitWindows(int a1, int a2, int a3, int a4, int a5)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A120
// Name: Plat_FloatTime
// Source: json
//------------------------------------------------------------------------------
double Plat_FloatTime()
{
  LARGE_INTEGER v0; // kr00_8
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  sub_3F00A0C0();
  QueryPerformanceCounter(lpPerformanceCount: &PerformanceCount);
  v0 = PerformanceCount;
  if ( PerformanceCount.QuadPart >= qword_3F03D308 )
    qword_3F03D308 = PerformanceCount.QuadPart;
  else
    v0.QuadPart = qword_3F03D308;
  return (double)(v0.QuadPart - ::PerformanceCount.QuadPart) / (double)Frequency.QuadPart;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A2C0
// Name: vtune
// Source: json
//------------------------------------------------------------------------------
char __cdecl vtune(char a1)
{
  HMODULE LibraryA; // eax
  HMODULE v2; // esi
  void (*VTPause)(void); // eax

  if ( byte_3F041A51 != 0
    || (byte_3F041A51 = 1, LibraryA = LoadLibraryA(lpLibFileName: "vtuneapi.dll"), v2 = LibraryA, LibraryA == nullptr) )
  {
    VTPause = (void (*)(void))dword_3F041A58;
  }
  else
  {
    VTResume_0 = (int)GetProcAddress(hModule: LibraryA, lpProcName: "VTResume");
    VTPause = (void (*)(void))GetProcAddress(hModule: v2, lpProcName: "VTPause");
    dword_3F041A58 = (int)VTPause;
  }
  if ( a1 != 0 )
    VTPause = (void (*)(void))VTResume_0;
  if ( VTPause == nullptr )
    return 0;
  VTPause();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A330
// Name: Plat_GetCommandLine
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
LPSTR __stdcall Plat_GetCommandLine()
{
  return GetCommandLineA();
}

//------------------------------------------------------------------------------
// Address: 0x3F00A380
// Name: Plat_Alloc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Plat_Alloc(int a1)
{
  int v1; // esi

  EnterCriticalSection(lpCriticalSection: &stru_3F03D2EC);
  v1 = (*(int (__thiscall **)(int, int))(*(_DWORD *)g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: a1);
  LeaveCriticalSection(lpCriticalSection: &stru_3F03D2EC);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A3C0
// Name: Plat_Realloc
// Source: json
//------------------------------------------------------------------------------
int __cdecl Plat_Realloc(int a1, int a2)
{
  int v2; // esi

  EnterCriticalSection(lpCriticalSection: &stru_3F03D2EC);
  v2 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)g_pMemAllocSteam + 16))(a1: g_pMemAllocSteam, a2: a1, a3: a2);
  LeaveCriticalSection(lpCriticalSection: &stru_3F03D2EC);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A400
// Name: Plat_Free
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_Free(int a1)
{
  EnterCriticalSection(lpCriticalSection: &stru_3F03D2EC);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: 0);
  LeaveCriticalSection(lpCriticalSection: &stru_3F03D2EC);
}

//------------------------------------------------------------------------------
// Address: 0x3F005670
// Name: ?GetBudgetGroupID@CVProfNode@@QAEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::GetBudgetGroupID(CVProfNode *this)
{
  LOBYTE(this->m_pszName) >>= (char)this;
  JUMPOUT(0x3F005677);
}

//------------------------------------------------------------------------------
// Address: 0x3F005680
// Name: ?SetBudgetGroupID@CVProfNode@@QAEXH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfNode::SetBudgetGroupID(
        CVProfNode *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        unsigned int a4@<esi>,
        int id)
{
  if ( !a2 && a4 < *(_DWORD *)(a3 + 40) )
    JUMPOUT(0x3F00568B);
  JUMPOUT(0x3F0056BB);
}

//------------------------------------------------------------------------------
// Address: 0x3F005690
// Name: ?SetClientData@CVProfNode@@QAEXH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0056A0
// Name: ?GetClientData@CVProfNode@@QBEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::GetClientData(CVProfNode *this)
{
  ThreadWaitForObjects();
  JUMPOUT(0x3F0056A7);
}

//------------------------------------------------------------------------------
// Address: 0x3F0056B0
// Name: ?SetUniqueNodeID@CVProfNode@@AAEXH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfNode::SetUniqueNodeID(CVProfNode *this, int id, int a3, int a4, int a5)
{
  ThreadWaitForObjects();
}

//------------------------------------------------------------------------------
// Address: 0x3F0056C0
// Name: ?GetUniqueNodeID@CVProfNode@@ABEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfNode::GetUniqueNodeID(CVProfNode *this@<ecx>, _BYTE *a2@<ebx>)
{
  bool v2; // cf
  bool v3; // of

  v2 = __CFADD__(BYTE1(a2), *a2);
  v3 = __OFADD__(BYTE1(a2), *a2);
  *a2 += BYTE1(a2);
  if ( !v3 )
  {
    if ( !v2 )
      JUMPOUT(0x3F0056C9);
    JUMPOUT(0x3F0056FF);
  }
  JUMPOUT(0x3F0056E8);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A1B0
// Name: ?Pop@CValidator@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CValidator::Pop(CValidator *this@<ecx>, int _EAX@<eax>, _DWORD *a3@<ebx>)
{
  *a3 = __ROL4__(*a3, (char)this);
  __asm { aas }
}

//------------------------------------------------------------------------------
// Address: 0x3F00A200
// Name: ?ClaimMemory@CValidator@@QAEXPAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CValidator::ClaimMemory(CValidator *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A220
// Name: Plat_ctime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Plat_ctime(int a1, int a2, int a3)
{
  return ((int (__cdecl *)(int, int, int))loc_3F01CAAE)(a1: a2, a2: a3, a3: a1) != 22 ? a2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A250
// Name: ?ClaimArrayMemory@CValidator@@QAEXPAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CValidator::ClaimArrayMemory(CValidator *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A260
// Name: Plat_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int Plat_daylight()
{
  return dword_3F03BD44;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A340
// Name: Plat_ExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl Plat_ExitProcess(UINT uExitCode)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  return TerminateProcess(hProcess: CurrentProcess, uExitCode);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A360
// Name: PLAT_GetExecutablePath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl PLAT_GetExecutablePath(LPSTR lpFilename, DWORD nSize)
{
  return GetModuleFileNameA(hModule: nullptr, lpFilename, nSize) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A430
// Name: Is64BitOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F00A440
// Name: ?RenderObjects@CValidator@@QAEXH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CValidator::RenderObjects(CValidator *this@<ecx>, int a2@<ebp>)
{
  HMODULE ModuleHandleA; // eax
  HANDLE CurrentProcess; // eax

  if ( (dword_3F041AA4 & 1) == 0 )
  {
    dword_3F041AA4 |= 1u;
    *(_DWORD *)(a2 - 4) = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32");
    IsWow64Process = (BOOL (__stdcall *)(HANDLE, PBOOL))GetProcAddress(
                                                          hModule: ModuleHandleA,
                                                          lpProcName: "IsWow64Process");
    *(_DWORD *)(a2 - 4) = -1;
  }
  if ( byte_3F041A60 == 0 )
  {
    byte_3F041A60 = 1;
    if ( IsWow64Process != nullptr )
    {
      CurrentProcess = GetCurrentProcess();
      IsWow64Process(hProcess: CurrentProcess, Wow64Process: &dword_3F041A5C);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00A530
// Name: ?BExcludeAllocationFromTracking@CValidator@@AAE_NPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned __int64 __usercall CValidator::BExcludeAllocationFromTracking@<edx:eax>(
        CValidator *this@<ecx>,
        unsigned int a2@<eax>,
        int a3@<edx>,
        const char *pchFile,
        const char *nLine,
        int nLinea)
{
  CValidator::BExcludeAllocationFromTracking::__l2::FileLineInfo_t fileLineInfoExclude[15]; // [esp+0h] [ebp-78h] BYREF

  *((_BYTE *)&fileLineInfoExclude[-1].pchFile + a3 + 3) *= 16;
  LOBYTE(a2) = a2 & 0x10;
  return __PAIR64__(nLinea, a2) >> 20;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A550
// Name: GetAvailableRAM
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetAvailableRAM()
{
  __int64 v0; // rax
  _MEMORYSTATUSEX Buffer; // [esp+8h] [ebp-40h] BYREF

  memset_0(a1: &Buffer, Val: 0, Size: sizeof(Buffer));
  Buffer.dwLength = 64;
  if ( GlobalMemoryStatusEx(lpBuffer: &Buffer) )
    return Buffer.ullAvailPhys >> 20;
  else
    LODWORD(v0) = 0;
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A5A0
// Name: GetCRunTimeVersion
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *GetCRunTimeVersion()
{
  return "unknown";
}

//------------------------------------------------------------------------------
// Address: 0x3F00A5B0
// Name: Plat_OutputDebugString
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void Plat_OutputDebugString(char *Format, ...)
{
  char OutputString[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list va; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(va, Format);
  if ( sub_3F01ACDC(Buffer: OutputString, BufferCount: 0x1000u, Format, ArgList: va) <= 0 )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: len > 0",
      a2: 0,
      a3: ".\\platform.cpp",
      a4: 369,
      a5: &unk_3F041A61,
      a6: 0);
  OutputDebugStringA(lpOutputString: OutputString);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A610
// Name: Plat_OutputDebugStringRaw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Plat_OutputDebugStringRaw(LPCSTR lpOutputString)
{
  OutputDebugStringA(lpOutputString);
}

} // namespace tier0_s
