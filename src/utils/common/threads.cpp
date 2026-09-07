// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/threads.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10010F00
// Name: unsigned long InternalRunThreadsFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall InternalRunThreadsFn(_DWORD *pParameter)
{
  ((void (__cdecl *)(_DWORD, _DWORD))pParameter[2])(a1: *pParameter, a2: pParameter[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010F20
// Name: void RunThreads_Start(void (*)(int,void __near *),void __near *,enum ERunThreadsPriority)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_Start(void (__cdecl *fn)(int, void *), void *pUserData, ERunThreadsPriority ePriority)
{
  int v3; // eax
  signed int v4; // edi
  CRunThreadsData *v5; // esi
  HANDLE v6; // eax
  unsigned int dwDummy; // [esp+0h] [ebp-4h] BYREF

  v3 = numthreads;
  threaded = 1;
  if ( (int)numthreads > 16 )
  {
    v3 = 16;
    numthreads = 16;
  }
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = g_RunThreadsData;
    do
    {
      v5->m_iThread = v4;
      v5->m_pUserData = pUserData;
      v5->m_Fn = fn;
      v6 = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)InternalRunThreadsFn,
             lpParameter: v5,
             dwCreationFlags: 0,
             lpThreadId: &dwDummy);
      g_ThreadHandles[v4] = v6;
      if ( ePriority != k_eRunThreadsPriority_UseGlobalState )
      {
        if ( ePriority == k_eRunThreadsPriority_Idle )
          SetThreadPriority(hThread: v6, nPriority: -15);
      }
      else if ( g_bLowPriorityThreads )
      {
        SetThreadPriority(hThread: v6, nPriority: -2);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (int)numthreads );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010FB0
// Name: void RunThreads_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_End()
{
  signed int v0; // esi

  WaitForMultipleObjects(nCount: numthreads, lpHandles: g_ThreadHandles, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF);
  v0 = 0;
  if ( (int)numthreads <= 0 )
  {
    threaded = 0;
  }
  else
  {
    do
      CloseHandle(hObject: g_ThreadHandles[v0++]);
    while ( v0 < (int)numthreads );
    threaded = 0;
  }
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10002A20
// Name: unsigned long InternalRunThreadsFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall InternalRunThreadsFn(_DWORD *pParameter)
{
  ((void (__cdecl *)(_DWORD, _DWORD))pParameter[2])(a1: *pParameter, a2: pParameter[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002A40
// Name: void RunThreads_Start(void (*)(int,void __near *),void __near *,enum ERunThreadsPriority)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_Start(void (__cdecl *fn)(int, void *), void *pUserData, ERunThreadsPriority ePriority)
{
  int v3; // eax
  signed int v4; // edi
  CRunThreadsData *v5; // esi
  HANDLE v6; // eax
  unsigned int dwDummy; // [esp+0h] [ebp-4h] BYREF

  v3 = numthreads;
  threaded = 1;
  if ( (int)numthreads > 16 )
  {
    v3 = 16;
    numthreads = 16;
  }
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = g_RunThreadsData;
    do
    {
      v5->m_iThread = v4;
      v5->m_pUserData = pUserData;
      v5->m_Fn = fn;
      v6 = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)InternalRunThreadsFn,
             lpParameter: v5,
             dwCreationFlags: 0,
             lpThreadId: &dwDummy);
      g_ThreadHandles[v4] = v6;
      if ( ePriority != k_eRunThreadsPriority_UseGlobalState )
      {
        if ( ePriority == k_eRunThreadsPriority_Idle )
          SetThreadPriority(hThread: v6, nPriority: -15);
      }
      else if ( g_bLowPriorityThreads )
      {
        SetThreadPriority(hThread: v6, nPriority: -2);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (int)numthreads );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AD0
// Name: void RunThreads_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_End()
{
  signed int v0; // esi

  WaitForMultipleObjects(nCount: numthreads, lpHandles: g_ThreadHandles, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF);
  v0 = 0;
  if ( (int)numthreads <= 0 )
  {
    threaded = 0;
  }
  else
  {
    do
      CloseHandle(hObject: g_ThreadHandles[v0++]);
    while ( v0 < (int)numthreads );
    threaded = 0;
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0044CF90
// Name: void SetLowPriority(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLowPriority()
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x0044CFA0
// Name: void ThreadSetDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetDefault()
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO info; // [esp+0h] [ebp-24h] BYREF

  dwNumberOfProcessors = numthreads;
  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &info);
    dwNumberOfProcessors = info.dwNumberOfProcessors;
    numthreads = info.dwNumberOfProcessors;
    if ( (int)info.dwNumberOfProcessors < 1 || (int)info.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
  }
  _Msg(a1: "%i threads\n", dwNumberOfProcessors);
}

//------------------------------------------------------------------------------
// Address: 0x0044CFF0
// Name: void ThreadLock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadLock()
{
  if ( threaded != 0 )
  {
    EnterCriticalSection(lpCriticalSection: &crit);
    if ( enter != 0 )
      _Error(a1: "Recursive ThreadLock\n");
    enter = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D030
// Name: void ThreadUnlock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadUnlock()
{
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D070
// Name: unsigned long InternalRunThreadsFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall InternalRunThreadsFn(_DWORD *pParameter)
{
  ((void (__cdecl *)(_DWORD, _DWORD))pParameter[2])(a1: *pParameter, a2: pParameter[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044D090
// Name: void RunThreads_Start(void (*)(int,void __near *),void __near *,enum ERunThreadsPriority)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_Start(void (__cdecl *fn)(int, void *), void *pUserData, ERunThreadsPriority ePriority)
{
  int v3; // eax
  signed int v4; // edi
  CRunThreadsData *v5; // esi
  HANDLE v6; // eax
  unsigned int dwDummy; // [esp+0h] [ebp-4h] BYREF

  v3 = numthreads;
  threaded = 1;
  if ( (int)numthreads > 16 )
  {
    v3 = 16;
    numthreads = 16;
  }
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = g_RunThreadsData;
    do
    {
      v5->m_iThread = v4;
      v5->m_pUserData = pUserData;
      v5->m_Fn = fn;
      v6 = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)InternalRunThreadsFn,
             lpParameter: v5,
             dwCreationFlags: 0,
             lpThreadId: &dwDummy);
      g_ThreadHandles[v4] = v6;
      if ( ePriority != k_eRunThreadsPriority_UseGlobalState )
      {
        if ( ePriority == k_eRunThreadsPriority_Idle )
          SetThreadPriority(hThread: v6, nPriority: -15);
      }
      else if ( g_bLowPriorityThreads )
      {
        SetThreadPriority(hThread: v6, nPriority: -2);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (int)numthreads );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D120
// Name: void RunThreads_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_End()
{
  signed int v0; // esi

  WaitForMultipleObjects(nCount: numthreads, lpHandles: g_ThreadHandles, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF);
  v0 = 0;
  if ( (int)numthreads <= 0 )
  {
    threaded = 0;
  }
  else
  {
    do
      CloseHandle(hObject: g_ThreadHandles[v0++]);
    while ( v0 < (int)numthreads );
    threaded = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D180
// Name: void RunThreadsOn(int,int,void (*)(int,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOn(int workcnt, int showpacifier, void (__cdecl *fn)(int, void *), void *pUserData)
{
  int v4; // edi
  int v5; // esi

  v4 = (int)_Plat_FloatTime();
  dispatch = 0;
  workcount = workcnt;
  StartPacifier(pPrefix: &defaultValue);
  pacifier = showpacifier;
  RunThreads_Start(fn, pUserData, ePriority: k_eRunThreadsPriority_UseGlobalState);
  RunThreads_End();
  v5 = (int)_Plat_FloatTime();
  if ( pacifier != 0 )
  {
    EndPacifier(bCarriageReturn: false);
    printf(format: " (%i)\n", v5 - v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D200
// Name: void ThreadWorkerFunction(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadWorkerFunction(int iThread)
{
  int v1; // esi

  while ( 1 )
  {
    if ( threaded != 0 )
    {
      EnterCriticalSection(lpCriticalSection: &crit);
      if ( enter != 0 )
        _Error(a1: "Recursive ThreadLock\n");
      enter = 1;
    }
    if ( dispatch == workcount )
      break;
    UpdatePacifier(flPercent: (float)dispatch / (float)workcount);
    v1 = dispatch++;
    if ( threaded != 0 )
    {
      if ( enter == 0 )
        _Error(a1: "ThreadUnlock without lock\n");
      enter = 0;
      LeaveCriticalSection(lpCriticalSection: &crit);
    }
    if ( v1 == -1 )
      return;
    workfunction(a1: iThread, a2: v1);
  }
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D300
// Name: void RunThreadsOnIndividual(int,int,void (*)(int,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOnIndividual(int workcnt, int showpacifier, void (__cdecl *func)(int, int))
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &SystemInfo);
    dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
    numthreads = SystemInfo.dwNumberOfProcessors;
    if ( (int)SystemInfo.dwNumberOfProcessors < 1 || (int)SystemInfo.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
    _Msg(a1: "%i threads\n", dwNumberOfProcessors);
  }
  workfunction = func;
  RunThreadsOn(workcnt, showpacifier, fn: (void (__cdecl *)(int, void *))ThreadWorkerFunction, pUserData: nullptr);
}

} // namespace vbsp

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x004582E0
// Name: void SetLowPriority(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLowPriority()
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x004582F0
// Name: void ThreadSetDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetDefault()
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO info; // [esp+0h] [ebp-24h] BYREF

  dwNumberOfProcessors = numthreads;
  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &info);
    dwNumberOfProcessors = info.dwNumberOfProcessors;
    numthreads = info.dwNumberOfProcessors;
    if ( (int)info.dwNumberOfProcessors < 1 || (int)info.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
  }
  _Msg(a1: "%i threads\n", dwNumberOfProcessors);
}

//------------------------------------------------------------------------------
// Address: 0x00458340
// Name: void ThreadLock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadLock()
{
  if ( threaded != 0 )
  {
    EnterCriticalSection(lpCriticalSection: &crit);
    if ( enter != 0 )
      _Error(a1: "Recursive ThreadLock\n");
    enter = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458380
// Name: void ThreadUnlock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadUnlock()
{
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004583C0
// Name: unsigned long InternalRunThreadsFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall InternalRunThreadsFn(_DWORD *pParameter)
{
  ((void (__cdecl *)(_DWORD, _DWORD))pParameter[2])(a1: *pParameter, a2: pParameter[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004583E0
// Name: void RunThreads_Start(void (*)(int,void __near *),void __near *,enum ERunThreadsPriority)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_Start(void (__cdecl *fn)(int, void *), void *pUserData, ERunThreadsPriority ePriority)
{
  int v3; // eax
  signed int v4; // edi
  CRunThreadsData *v5; // esi
  HANDLE v6; // eax
  unsigned int dwDummy; // [esp+0h] [ebp-4h] BYREF

  v3 = numthreads;
  threaded = 1;
  if ( (int)numthreads > 16 )
  {
    v3 = 16;
    numthreads = 16;
  }
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = g_RunThreadsData;
    do
    {
      v5->m_iThread = v4;
      v5->m_pUserData = pUserData;
      v5->m_Fn = fn;
      v6 = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)InternalRunThreadsFn,
             lpParameter: v5,
             dwCreationFlags: 0,
             lpThreadId: &dwDummy);
      g_ThreadHandles[v4] = v6;
      if ( ePriority != k_eRunThreadsPriority_UseGlobalState )
      {
        if ( ePriority == k_eRunThreadsPriority_Idle )
          SetThreadPriority(hThread: v6, nPriority: -15);
      }
      else if ( g_bLowPriorityThreads )
      {
        SetThreadPriority(hThread: v6, nPriority: -2);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (int)numthreads );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458470
// Name: void RunThreads_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_End()
{
  signed int v0; // esi

  WaitForMultipleObjects(nCount: numthreads, lpHandles: g_ThreadHandles, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF);
  v0 = 0;
  if ( (int)numthreads <= 0 )
  {
    threaded = 0;
  }
  else
  {
    do
      CloseHandle(hObject: g_ThreadHandles[v0++]);
    while ( v0 < (int)numthreads );
    threaded = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004584D0
// Name: void RunThreadsOn(int,int,void (*)(int,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOn(int workcnt, int showpacifier, void (__cdecl *fn)(int, void *), void *pUserData)
{
  int v4; // edi
  int v5; // esi

  v4 = (int)_Plat_FloatTime();
  dispatch = 0;
  workcount = workcnt;
  StartPacifier(pPrefix: var);
  pacifier = showpacifier;
  RunThreads_Start(fn, pUserData, ePriority: k_eRunThreadsPriority_UseGlobalState);
  RunThreads_End();
  v5 = (int)_Plat_FloatTime();
  if ( pacifier != 0 )
  {
    EndPacifier(bCarriageReturn: false);
    printf(format: " (%i)\n", v5 - v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458550
// Name: void ThreadWorkerFunction(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadWorkerFunction(int iThread)
{
  int v1; // esi

  while ( 1 )
  {
    if ( threaded != 0 )
    {
      EnterCriticalSection(lpCriticalSection: &crit);
      if ( enter != 0 )
        _Error(a1: "Recursive ThreadLock\n");
      enter = 1;
    }
    if ( dispatch == workcount )
      break;
    UpdatePacifier(flPercent: (float)dispatch / (float)workcount);
    v1 = dispatch++;
    if ( threaded != 0 )
    {
      if ( enter == 0 )
        _Error(a1: "ThreadUnlock without lock\n");
      enter = 0;
      LeaveCriticalSection(lpCriticalSection: &crit);
    }
    if ( v1 == -1 )
      return;
    workfunction(a1: iThread, a2: v1);
  }
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458650
// Name: void RunThreadsOnIndividual(int,int,void (*)(int,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOnIndividual(int workcnt, int showpacifier, void (__cdecl *func)(int, int))
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &SystemInfo);
    dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
    numthreads = SystemInfo.dwNumberOfProcessors;
    if ( (int)SystemInfo.dwNumberOfProcessors < 1 || (int)SystemInfo.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
    _Msg(a1: "%i threads\n", dwNumberOfProcessors);
  }
  workfunction = func;
  RunThreadsOn(workcnt, showpacifier, fn: (void (__cdecl *)(int, void *))ThreadWorkerFunction, pUserData: nullptr);
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1004C470
// Name: void SetLowPriority(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLowPriority()
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x1004C480
// Name: void ThreadSetDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetDefault()
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO info; // [esp+0h] [ebp-24h] BYREF

  dwNumberOfProcessors = numthreads;
  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &info);
    dwNumberOfProcessors = info.dwNumberOfProcessors;
    numthreads = info.dwNumberOfProcessors;
    if ( (int)info.dwNumberOfProcessors < 1 || (int)info.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
  }
  _Msg(a1: "%i threads\n", dwNumberOfProcessors);
}

//------------------------------------------------------------------------------
// Address: 0x1004C4D0
// Name: void ThreadLock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadLock()
{
  if ( threaded != 0 )
  {
    EnterCriticalSection(lpCriticalSection: &crit);
    if ( enter != 0 )
      _Error(a1: "Recursive ThreadLock\n");
    enter = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C510
// Name: void ThreadUnlock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadUnlock()
{
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C550
// Name: unsigned long InternalRunThreadsFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall InternalRunThreadsFn(_DWORD *pParameter)
{
  ((void (__cdecl *)(_DWORD, _DWORD))pParameter[2])(a1: *pParameter, a2: pParameter[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C570
// Name: void RunThreads_Start(void (*)(int,void __near *),void __near *,enum ERunThreadsPriority)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_Start(void (__cdecl *fn)(int, void *), void *pUserData, ERunThreadsPriority ePriority)
{
  int v3; // eax
  signed int v4; // edi
  CRunThreadsData *v5; // esi
  HANDLE v6; // eax
  unsigned int dwDummy; // [esp+0h] [ebp-4h] BYREF

  v3 = numthreads;
  threaded = 1;
  if ( (int)numthreads > 16 )
  {
    v3 = 16;
    numthreads = 16;
  }
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = g_RunThreadsData;
    do
    {
      v5->m_iThread = v4;
      v5->m_pUserData = pUserData;
      v5->m_Fn = fn;
      v6 = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)InternalRunThreadsFn,
             lpParameter: v5,
             dwCreationFlags: 0,
             lpThreadId: &dwDummy);
      g_ThreadHandles[v4] = v6;
      if ( ePriority != k_eRunThreadsPriority_UseGlobalState )
      {
        if ( ePriority == k_eRunThreadsPriority_Idle )
          SetThreadPriority(hThread: v6, nPriority: -15);
      }
      else if ( g_bLowPriorityThreads )
      {
        SetThreadPriority(hThread: v6, nPriority: -2);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (int)numthreads );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C600
// Name: void RunThreads_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_End()
{
  signed int v0; // esi

  WaitForMultipleObjects(nCount: numthreads, lpHandles: g_ThreadHandles, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF);
  v0 = 0;
  if ( (int)numthreads <= 0 )
  {
    threaded = 0;
  }
  else
  {
    do
      CloseHandle(hObject: g_ThreadHandles[v0++]);
    while ( v0 < (int)numthreads );
    threaded = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C660
// Name: void RunThreadsOn(int,int,void (*)(int,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOn(int workcnt, int showpacifier, void (__cdecl *fn)(int, void *), void *pUserData)
{
  int v4; // edi
  int v5; // esi

  v4 = (int)_Plat_FloatTime();
  dispatch = 0;
  workcount = workcnt;
  StartPacifier(pPrefix: defaultValue);
  pacifier = showpacifier;
  RunThreads_Start(fn, pUserData, ePriority: k_eRunThreadsPriority_UseGlobalState);
  RunThreads_End();
  v5 = (int)_Plat_FloatTime();
  if ( pacifier != 0 )
  {
    EndPacifier(bCarriageReturn: false);
    printf(format: " (%i)\n", v5 - v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C6E0
// Name: int GetThreadWork(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetThreadWork()
{
  int v1; // esi

  if ( threaded != 0 )
  {
    EnterCriticalSection(lpCriticalSection: &crit);
    if ( enter != 0 )
      _Error(a1: "Recursive ThreadLock\n");
    enter = 1;
  }
  if ( dispatch == workcount )
  {
    if ( threaded != 0 )
    {
      if ( enter == 0 )
        _Error(a1: "ThreadUnlock without lock\n");
      enter = 0;
      LeaveCriticalSection(lpCriticalSection: &crit);
    }
    return -1;
  }
  else
  {
    UpdatePacifier(flPercent: (float)dispatch / (float)workcount);
    v1 = dispatch++;
    if ( threaded != 0 )
    {
      if ( enter == 0 )
        _Error(a1: "ThreadUnlock without lock\n");
      enter = 0;
      LeaveCriticalSection(lpCriticalSection: &crit);
    }
    return v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C7D0
// Name: void ThreadWorkerFunction(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadWorkerFunction(int iThread)
{
  int v1; // esi

  while ( 1 )
  {
    if ( threaded != 0 )
    {
      EnterCriticalSection(lpCriticalSection: &crit);
      if ( enter != 0 )
        _Error(a1: "Recursive ThreadLock\n");
      enter = 1;
    }
    if ( dispatch == workcount )
      break;
    UpdatePacifier(flPercent: (float)dispatch / (float)workcount);
    v1 = dispatch++;
    if ( threaded != 0 )
    {
      if ( enter == 0 )
        _Error(a1: "ThreadUnlock without lock\n");
      enter = 0;
      LeaveCriticalSection(lpCriticalSection: &crit);
    }
    if ( v1 == -1 )
      return;
    workfunction(a1: iThread, a2: v1);
  }
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C8D0
// Name: void RunThreadsOnIndividual(int,int,void (*)(int,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOnIndividual(int workcnt, int showpacifier, void (__cdecl *func)(int, int))
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &SystemInfo);
    dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
    numthreads = SystemInfo.dwNumberOfProcessors;
    if ( (int)SystemInfo.dwNumberOfProcessors < 1 || (int)SystemInfo.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
    _Msg(a1: "%i threads\n", dwNumberOfProcessors);
  }
  workfunction = func;
  RunThreadsOn(workcnt, showpacifier, fn: (void (__cdecl *)(int, void *))ThreadWorkerFunction, pUserData: nullptr);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10013E00
// Name: void SetLowPriority(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLowPriority()
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x10013E10
// Name: void ThreadSetDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetDefault()
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO info; // [esp+0h] [ebp-24h] BYREF

  dwNumberOfProcessors = numthreads;
  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &info);
    dwNumberOfProcessors = info.dwNumberOfProcessors;
    numthreads = info.dwNumberOfProcessors;
    if ( (int)info.dwNumberOfProcessors < 1 || (int)info.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
  }
  _Msg(a1: "%i threads\n", dwNumberOfProcessors);
}

//------------------------------------------------------------------------------
// Address: 0x10013E60
// Name: unsigned long InternalRunThreadsFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall InternalRunThreadsFn(_DWORD *pParameter)
{
  ((void (__cdecl *)(_DWORD, _DWORD))pParameter[2])(a1: *pParameter, a2: pParameter[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013E80
// Name: void RunThreads_Start(void (*)(int,void __near *),void __near *,enum ERunThreadsPriority)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_Start(void (__cdecl *fn)(int, void *), void *pUserData, ERunThreadsPriority ePriority)
{
  int v3; // eax
  signed int v4; // edi
  CRunThreadsData *v5; // esi
  HANDLE v6; // eax
  unsigned int dwDummy; // [esp+0h] [ebp-4h] BYREF

  v3 = numthreads;
  threaded = 1;
  if ( (int)numthreads > 16 )
  {
    v3 = 16;
    numthreads = 16;
  }
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = g_RunThreadsData;
    do
    {
      v5->m_iThread = v4;
      v5->m_pUserData = pUserData;
      v5->m_Fn = fn;
      v6 = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: 0,
             lpStartAddress: (LPTHREAD_START_ROUTINE)InternalRunThreadsFn,
             lpParameter: v5,
             dwCreationFlags: 0,
             lpThreadId: &dwDummy);
      g_ThreadHandles[v4] = v6;
      if ( ePriority != k_eRunThreadsPriority_UseGlobalState )
      {
        if ( ePriority == k_eRunThreadsPriority_Idle )
          SetThreadPriority(hThread: v6, nPriority: -15);
      }
      else if ( g_bLowPriorityThreads )
      {
        SetThreadPriority(hThread: v6, nPriority: -2);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (int)numthreads );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013F10
// Name: void RunThreads_End(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreads_End()
{
  signed int v0; // esi

  WaitForMultipleObjects(nCount: numthreads, lpHandles: g_ThreadHandles, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF);
  v0 = 0;
  if ( (int)numthreads <= 0 )
  {
    threaded = 0;
  }
  else
  {
    do
      CloseHandle(hObject: g_ThreadHandles[v0++]);
    while ( v0 < (int)numthreads );
    threaded = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013F70
// Name: void RunThreadsOn(int,int,void (*)(int,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOn(int workcnt, int showpacifier, void (__cdecl *fn)(int, void *), void *pUserData)
{
  int v4; // edi
  int v5; // esi

  v4 = (int)_Plat_FloatTime();
  dispatch = 0;
  workcount = workcnt;
  StartPacifier(pPrefix: defaultValue);
  pacifier = showpacifier;
  RunThreads_Start(fn, pUserData, ePriority: k_eRunThreadsPriority_UseGlobalState);
  RunThreads_End();
  v5 = (int)_Plat_FloatTime();
  if ( pacifier != 0 )
  {
    EndPacifier(bCarriageReturn: false);
    printf(format: " (%i)\n", v5 - v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013FF0
// Name: void ThreadWorkerFunction(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadWorkerFunction(int iThread)
{
  int v1; // esi

  while ( 1 )
  {
    if ( threaded != 0 )
    {
      EnterCriticalSection(lpCriticalSection: &crit);
      if ( enter != 0 )
        _Error(a1: "Recursive ThreadLock\n");
      enter = 1;
    }
    if ( dispatch == workcount )
      break;
    UpdatePacifier(flPercent: (float)dispatch / (float)workcount);
    v1 = dispatch++;
    if ( threaded != 0 )
    {
      if ( enter == 0 )
        _Error(a1: "ThreadUnlock without lock\n");
      enter = 0;
      LeaveCriticalSection(lpCriticalSection: &crit);
    }
    if ( v1 == -1 )
      return;
    workfunction(a1: iThread, a2: v1);
  }
  if ( threaded != 0 )
  {
    if ( enter == 0 )
      _Error(a1: "ThreadUnlock without lock\n");
    enter = 0;
    LeaveCriticalSection(lpCriticalSection: &crit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100140F0
// Name: void RunThreadsOnIndividual(int,int,void (*)(int,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunThreadsOnIndividual(int workcnt, int showpacifier, void (__cdecl *func)(int, int))
{
  unsigned int dwNumberOfProcessors; // eax
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  if ( numthreads == -1 )
  {
    GetSystemInfo(lpSystemInfo: &SystemInfo);
    dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
    numthreads = SystemInfo.dwNumberOfProcessors;
    if ( (int)SystemInfo.dwNumberOfProcessors < 1 || (int)SystemInfo.dwNumberOfProcessors > 32 )
    {
      dwNumberOfProcessors = 1;
      numthreads = 1;
    }
    _Msg(a1: "%i threads\n", dwNumberOfProcessors);
  }
  workfunction = func;
  RunThreadsOn(workcnt, showpacifier, fn: (void (__cdecl *)(int, void *))ThreadWorkerFunction, pUserData: nullptr);
}

} // namespace vvis_dll
