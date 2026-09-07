// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/systeminformation.cpp
// Functions: 3
// ============================================================

#include "tier0\systeminformation.h"

//------------------------------------------------------------------------------
// Address: 0x1000DFF0
// Name: _Plat_GetMemPageSize
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Plat_GetMemPageSize()
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1000E000
// Name: public: CSysCallCacheEntry_FindModule::CSysCallCacheEntry_FindModule(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
CSysCallCacheEntry_FindModule *__thiscall CSysCallCacheEntry_FindModule::CSysCallCacheEntry_FindModule(
        CSysCallCacheEntry_FindModule *this,
        char *pszModule,
        char *pszFunction)
{
  HINSTANCE__ *ModuleHandleA; // eax
  int (__stdcall *ProcAddress)(); // eax

  this->m_eResult = SYSCALL_SUCCESS;
  this->m_pfnSysCall = nullptr;
  this->m_hModule = nullptr;
  *(_WORD *)&this->m_bInitialized = 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: pszModule);
  this->m_hModule = ModuleHandleA;
  this->m_bFreeModule = false;
  if ( ModuleHandleA != nullptr )
  {
    this->m_bInitialized = true;
    ProcAddress = GetProcAddress(hModule: ModuleHandleA, lpProcName: pszFunction);
    this->m_pfnSysCall = ProcAddress;
    this->m_eResult = ProcAddress != nullptr ? SYSCALL_SUCCESS : SYSCALL_NOPROC;
  }
  else
  {
    this->m_eResult = SYSCALL_NODLL;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E060
// Name: _Plat_GetPagedPoolInfo
// Source: json
//------------------------------------------------------------------------------
SYSTEM_CALL_RESULT_t __cdecl Plat_GetPagedPoolInfo(PAGED_POOL_INFO_t *pPPI)
{
  bool v1; // zf
  HINSTANCE__ *ModuleHandleA; // eax
  SYSTEM_CALL_RESULT_t result; // eax
  unsigned int v4; // eax
  HANDLE CurrentProcess; // eax
  SYSTEM_CALL_RESULT_t m_eResult; // eax
  SYSTEM_CALL_RESULT_t v7; // esi
  unsigned int FreePagedPoolPages; // ecx
  ValvePrivateType_SYSTEM_PERFORMANCE_INFORMATION spi; // [esp+8h] [ebp-1E4h] BYREF
  _OSVERSIONINFOA osver; // [esp+140h] [ebp-ACh] BYREF
  unsigned int ulLength; // [esp+1D4h] [ebp-18h] BYREF
  CSysCallCacheEntry_FindModule wow64; // [esp+1D8h] [ebp-14h] BYREF
  int b64; // [esp+1E8h] [ebp-4h] BYREF

  v1 = (_S1_2 & 1) == 0;
  *pPPI = 0;
  if ( v1 )
  {
    _S1_2 |= 1u;
    qsi.m_eResult = SYSCALL_SUCCESS;
    qsi.m_pfnSysCall = nullptr;
    qsi.m_hModule = nullptr;
    *(_WORD *)&qsi.m_bInitialized = 1;
    ModuleHandleA = GetModuleHandleA(lpModuleName: "ntdll.dll");
    qsi.m_hModule = ModuleHandleA;
    qsi.m_bFreeModule = false;
    if ( ModuleHandleA != nullptr )
    {
      qsi.m_bInitialized = true;
      qsi.m_pfnSysCall = GetProcAddress(hModule: ModuleHandleA, lpProcName: "NtQuerySystemInformation");
      qsi.m_eResult = qsi.m_pfnSysCall != nullptr ? SYSCALL_SUCCESS : SYSCALL_NOPROC;
    }
    else
    {
      qsi.m_eResult = SYSCALL_NODLL;
    }
    atexit(func: Plat_GetPagedPoolInfo_::_2_::_dynamic_atexit_destructor_for__qsi__);
  }
  result = qsi.m_eResult;
  if ( qsi.m_eResult == SYSCALL_SUCCESS )
  {
    if ( !s_bOsVersionValid )
    {
      s_bOsVersionValid = true;
      memset(dst: (int)&osver, value: nullptr, count: sizeof(osver));
      osver.dwOSVersionInfoSize = 148;
      GetVersionExA(lpVersionInformation: &osver);
      v4 = LOWORD(osver.dwMinorVersion) | (LOWORD(osver.dwMajorVersion) << 16);
      if ( v4 < 0x50001 || v4 > 0x50002 )
        qsi.m_eResult = SYSCALL_UNSUPPORTED;
      CSysCallCacheEntry_FindModule::CSysCallCacheEntry_FindModule(
        this: &wow64,
        pszModule: "kernel32.dll",
        pszFunction: "IsWow64Process");
      if ( wow64.m_eResult == SYSCALL_SUCCESS )
      {
        b64 = 0;
        CurrentProcess = GetCurrentProcess();
        if ( ((int (__cdecl *)(HANDLE, int *))wow64.m_pfnSysCall)(a1: CurrentProcess, a2: &b64) != 0 && b64 != 0 )
        {
          m_eResult = SYSCALL_UNSUPPORTED;
          qsi.m_eResult = SYSCALL_UNSUPPORTED;
          goto LABEL_16;
        }
      }
      m_eResult = qsi.m_eResult;
      if ( qsi.m_eResult != SYSCALL_SUCCESS )
      {
LABEL_16:
        v7 = m_eResult;
        if ( wow64.m_bInitialized && wow64.m_bFreeModule && wow64.m_hModule != nullptr )
          FreeLibrary(hLibModule: wow64.m_hModule);
        return v7;
      }
      if ( wow64.m_bInitialized && wow64.m_bFreeModule && wow64.m_hModule != nullptr )
        FreeLibrary(hLibModule: wow64.m_hModule);
    }
    ulLength = 312;
    if ( ((NTSTATUS (__stdcall *)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG))qsi.m_pfnSysCall)(
           SystemInformationClass: SystemPerformanceInformation,
           SystemInformation: &spi,
           SystemInformationLength: 0x138u,
           ReturnLength: &ulLength) != 0 )
    {
      return SYSCALL_FAILED;
    }
    else
    {
      FreePagedPoolPages = spi.FreePagedPoolPages;
      pPPI->numPagesUsed = spi.PagedPoolPages;
      pPPI->numPagesFree = FreePagedPoolPages;
      return SYSCALL_SUCCESS;
    }
  }
  return result;
}
