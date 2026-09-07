// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_thr_init.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E480
// Name: my_sigabrt_handler
// Source: json
//------------------------------------------------------------------------------
void __stdcall my_sigabrt_handler()
{
  __debugbreak();
}

//------------------------------------------------------------------------------
// Address: 0x0040E490
// Name: install_sigabrt_handler
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *install_sigabrt_handler())(int)
{
  _set_abort_behavior(flags: 0, mask: 2u);
  return signal(signum: 22, sigact: (void (__cdecl *)(int))my_sigabrt_handler);
}

//------------------------------------------------------------------------------
// Address: 0x0040E4B0
// Name: _my_thread_init
// Source: json
//------------------------------------------------------------------------------
char my_thread_init()
{
  unsigned __int8 *v0; // eax
  char *v2; // eax
  unsigned __int8 *v3; // [esp+4h] [ebp-4h] BYREF

  if ( TlsGetValue(dwTlsIndex: THR_KEY_mysys) == nullptr )
  {
    install_sigabrt_handler();
    v0 = calloc(count: 1u, size: 0x7Cu);
    v3 = v0;
    if ( v0 == nullptr )
      return 1;
    TlsSetValue(dwTlsIndex: THR_KEY_mysys, lpTlsValue: v0);
    *((_DWORD *)v3 + 20) = GetCurrentThreadId();
    InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)v3 + 2);
    pthread_cond_init(a1: v3 + 4);
    *((_DWORD *)v3 + 29) = (char *)&v3 - my_thread_stack_size;
    EnterCriticalSection(lpCriticalSection: &THR_LOCK_threads);
    v2 = (char *)`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.SsHandle + 1;
    *((_DWORD *)v3 + 21) = (char *)`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.SsHandle + 1;
    ++*(_DWORD *)&`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.Initialized;
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.SsHandle = v2;
    LeaveCriticalSection(lpCriticalSection: &THR_LOCK_threads);
    v3[96] = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E570
// Name: _my_thread_global_init
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None
