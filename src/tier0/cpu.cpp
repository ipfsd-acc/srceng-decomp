// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/cpu.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100026B0
// Name: cpuid
// Source: json
//------------------------------------------------------------------------------
char __cdecl cpuid(
        unsigned int function,
        unsigned int *out_eax,
        unsigned int *out_ebx,
        unsigned int *out_ecx,
        unsigned int *out_edx)
{
  _EAX = function;
  __asm { cpuid }
  *out_eax = _EAX;
  *out_ebx = _EBX;
  *out_ecx = _ECX;
  *out_edx = _EDX;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002750
// Name: IsWin98OrOlder
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsWin98OrOlder()
{
  _OSVERSIONINFOEXA osvi; // [esp+8h] [ebp-9Ch] BYREF

  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) )
  {
    osvi.dwOSVersionInfoSize = 148;
    if ( !GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) )
      Error(pMsgFormat: "IsWin98OrOlder:  Unable to get OS version information");
  }
  return osvi.dwPlatformId <= 1;
}

//------------------------------------------------------------------------------
// Address: 0x100027E0
// Name: Check3DNowTechnology
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Check3DNowTechnology()
{
  int v0; // eax
  unsigned int out_eax; // [esp+0h] [ebp-8h] BYREF
  unsigned int unused; // [esp+4h] [ebp-4h] BYREF

  if ( cpuid(function: 0x80000000, &out_eax, out_ebx: &unused, out_ecx: &unused, out_edx: &unused) != 0
    && out_eax > 0x80000000
    && cpuid(function: 0x80000001, out_eax: &unused, out_ebx: &unused, out_ecx: &unused, out_edx: &out_eax) != 0 )
  {
    return out_eax >> 31;
  }
  else
  {
    LOBYTE(v0) = 0;
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x10002840
// Name: char const __near * GetProcessorVendorId(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetProcessorVendorId()
{
  unsigned int VendorIDRegisters[3]; // [esp+0h] [ebp-10h] BYREF
  unsigned int unused; // [esp+Ch] [ebp-4h] BYREF

  *(_QWORD *)VendorID = 0;
  dword_1003A7A0 = 0;
  byte_1003A7A4 = 0;
  if ( cpuid(
         function: 0,
         out_eax: &unused,
         out_ebx: VendorIDRegisters,
         out_ecx: &VendorIDRegisters[2],
         out_edx: &VendorIDRegisters[1]) != 0 )
  {
    dword_1003A7A0 = VendorIDRegisters[2];
    *(_DWORD *)VendorID = VendorIDRegisters[0];
    *(_DWORD *)&VendorID[4] = VendorIDRegisters[1];
  }
  else
  {
    strcpy(VendorID, "Generic_x86");
  }
  return VendorID;
}

//------------------------------------------------------------------------------
// Address: 0x100028D0
// Name: bool CheckSSE4aTechnology(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckSSE4aTechnology()
{
  char *ProcessorVendorId; // eax
  unsigned int out_eax; // [esp+0h] [ebp-10h] BYREF
  unsigned int out_ebx; // [esp+4h] [ebp-Ch] BYREF
  unsigned int out_edx; // [esp+8h] [ebp-8h] BYREF
  unsigned int out_ecx; // [esp+Ch] [ebp-4h] BYREF

  ProcessorVendorId = GetProcessorVendorId();
  return V_tier0_stricmp(s1: ProcessorVendorId, s2: "AuthenticAMD") == 0
      && cpuid(function: 0x80000001, &out_eax, &out_ebx, &out_ecx, &out_edx) != 0
      && (out_ecx & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002930
// Name: CalculateClockSpeed
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __cdecl CalculateClockSpeed()
{
  _LARGE_INTEGER startCount; // [esp+0h] [ebp-2Ch] BYREF
  _LARGE_INTEGER curCount; // [esp+8h] [ebp-24h] BYREF
  CCycleCount start; // [esp+10h] [ebp-1Ch] BYREF
  CCycleCount end; // [esp+18h] [ebp-14h]
  _LARGE_INTEGER waitTime; // [esp+20h] [ebp-Ch] BYREF
  CCycleCount *p_start; // [esp+28h] [ebp-4h]

  start.m_Int64 = 0;
  end.m_Int64 = 0;
  QueryPerformanceFrequency(lpFrequency: &waitTime);
  waitTime.QuadPart >>= 5;
  QueryPerformanceCounter(lpPerformanceCount: &startCount);
  p_start = &start;
  start.m_Int64 = __rdtsc();
  do
    QueryPerformanceCounter(lpPerformanceCount: &curCount);
  while ( curCount.QuadPart - startCount.QuadPart < waitTime.QuadPart );
  return 32 * (__rdtsc() - start.m_Int64);
}

//------------------------------------------------------------------------------
// Address: 0x100029D0
// Name: _GetCPUInformation
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
const CPUInformation *__usercall GetCPUInformation@<eax>(ICpuTopology *a1@<ebp>)
{
  char *ProcessorVendorId; // eax
  char v2; // al
  char v3; // al
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  char v9; // al
  char v10; // al
  char *v11; // eax
  bool v12; // al
  _SYSTEM_INFO v14; // [esp-Ch] [ebp-4Ch] OVERLAPPED BYREF
  unsigned int v15; // [esp+24h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+28h] [ebp-18h] BYREF
  unsigned int v17; // [esp+2Ch] [ebp-14h] BYREF
  CpuTopology v18[3]; // [esp+30h] [ebp-10h] BYREF
  ICpuTopology *retaddr; // [esp+40h] [ebp+0h]

  v18[1].m_pImpl = a1;
  v18[2].m_pImpl = retaddr;
  if ( s_cpuInformation.m_Size != 24 )
  {
    *(_QWORD *)&s_cpuInformation.m_Size = 24;
    s_cpuInformation.m_Speed = 0;
    *(_QWORD *)&s_cpuInformation.m_szProcessorID = 0;
    s_cpuInformation.m_Speed = CalculateClockSpeed();
    memset(&v14, 0, sizeof(v14));
    GetSystemInfo(lpSystemInfo: &v14);
    s_cpuInformation.m_nLogicalProcessors = v14.dwNumberOfProcessors;
    ProcessorVendorId = GetProcessorVendorId();
    if ( V_tier0_stricmp(s1: ProcessorVendorId, s2: "AuthenticAMD") != 0 )
    {
      CpuTopology::CpuTopology(this: v18, bForceCpuid: 0);
      s_cpuInformation.m_nPhysicalProcessors = CpuTopology::NumberOfSystemCores(this: v18);
      CpuTopology::~CpuTopology(this: v18);
    }
    else
    {
      s_cpuInformation.m_nPhysicalProcessors = s_cpuInformation.m_nLogicalProcessors;
    }
    if ( s_cpuInformation.m_nPhysicalProcessors == 0 && s_cpuInformation.m_nLogicalProcessors == 0 )
      *(_WORD *)&s_cpuInformation.m_nLogicalProcessors = 257;
    v2 = cpuid(function: 1u, out_eax: &v15, out_ebx: &v16, out_ecx: &v17, out_edx: (unsigned int *)v18);
    if ( v2 != 0 )
      v2 = ((int)v18[0].m_pImpl & 0x10) != 0;
    *((_BYTE *)&s_cpuInformation + 4) ^= (v2 ^ *((_BYTE *)&s_cpuInformation + 4)) & 1;
    v3 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: &v15, out_edx: (unsigned int *)v18);
    if ( v3 != 0 )
      v3 = ((int)v18[0].m_pImpl & 0x8000) != 0;
    *((_BYTE *)&s_cpuInformation + 4) ^= (*((_BYTE *)&s_cpuInformation + 4) ^ (2 * v3)) & 2;
    v4 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: &v15, out_edx: (unsigned int *)v18);
    if ( v4 != 0 )
      v4 = BYTE2(v18[0].m_pImpl) & 1;
    *((_BYTE *)&s_cpuInformation + 4) ^= (*((_BYTE *)&s_cpuInformation + 4) ^ (4 * v4)) & 4;
    v5 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: &v15, out_edx: (unsigned int *)v18);
    if ( v5 != 0 )
      v5 = ((int)v18[0].m_pImpl & 0x800000) != 0;
    *((_BYTE *)&s_cpuInformation + 4) ^= (*((_BYTE *)&s_cpuInformation + 4) ^ (v5 << 6)) & 0x40;
    if ( IsWin98OrOlder() )
    {
      v6 = 0;
    }
    else
    {
      v6 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: &v15, out_edx: (unsigned int *)v18);
      if ( v6 != 0 )
        v6 = ((int)v18[0].m_pImpl & 0x2000000) != 0;
    }
    *((_BYTE *)&s_cpuInformation + 4) ^= (*((_BYTE *)&s_cpuInformation + 4) ^ (8 * v6)) & 8;
    v7 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: &v15, out_edx: (unsigned int *)v18);
    if ( v7 != 0 )
      v7 = ((int)v18[0].m_pImpl & 0x4000000) != 0;
    *((_BYTE *)&s_cpuInformation + 4) ^= (*((_BYTE *)&s_cpuInformation + 4) ^ (16 * v7)) & 0x10;
    v8 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: (unsigned int *)v18, out_edx: &v15);
    if ( v8 != 0 )
      v8 = (int)v18[0].m_pImpl & 1;
    *((_BYTE *)&s_cpuInformation + 7) ^= (*((_BYTE *)&s_cpuInformation + 7) ^ v8) & 1;
    v9 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: (unsigned int *)v18, out_edx: &v15);
    if ( v9 != 0 )
      v9 = ((int)v18[0].m_pImpl & 0x200) != 0;
    *((_BYTE *)&s_cpuInformation + 7) ^= (*((_BYTE *)&s_cpuInformation + 7) ^ (2 * v9)) & 2;
    *((_BYTE *)&s_cpuInformation + 7) ^= (*((_BYTE *)&s_cpuInformation + 7) ^ (4 * CheckSSE4aTechnology())) & 4;
    v10 = cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: (unsigned int *)v18, out_edx: &v15);
    if ( v10 != 0 )
      v10 = ((int)v18[0].m_pImpl & 0x80000) != 0;
    *((_BYTE *)&s_cpuInformation + 7) ^= (*((_BYTE *)&s_cpuInformation + 7) ^ (8 * v10)) & 8;
    v11 = GetProcessorVendorId();
    v12 = V_tier0_stricmp(s1: v11, s2: "GenuineIntel") == 0
       && cpuid(function: 1u, out_eax: &v17, out_ebx: &v16, out_ecx: (unsigned int *)v18, out_edx: &v15) != 0
       && ((int)v18[0].m_pImpl & 0x100000) != 0;
    *((_BYTE *)&s_cpuInformation + 7) ^= (*((_BYTE *)&s_cpuInformation + 7) ^ (16 * v12)) & 0x10;
    *((_BYTE *)&s_cpuInformation + 4) ^= (*((_BYTE *)&s_cpuInformation + 4) ^ (32 * Check3DNowTechnology())) & 0x20;
    s_cpuInformation.m_szProcessorID = GetProcessorVendorId();
    *((_BYTE *)&s_cpuInformation + 4) = *((_BYTE *)&s_cpuInformation + 4) & 0x7F
                                      | ((s_cpuInformation.m_nPhysicalProcessors < s_cpuInformation.m_nLogicalProcessors) << 7);
  }
  return &s_cpuInformation;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F001D80
// Name: public: void CCycleCount::Sample(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycleCount::Sample(CCycleCount *this)
{
  JUMPOUT(0x3F001D81);
}

//------------------------------------------------------------------------------
// Address: 0x3F001DF0
// Name: cpuid
// Source: json
//------------------------------------------------------------------------------
int __usercall cpuid@<eax>(int *a1@<esi>)
{
  int v1; // eax
  bool v2; // cc
  int result; // eax

  *(_QWORD *)a1 = __rdtsc();
  v1 = a1[1];
  v2 = v1 < dword_3F03D38C;
  if ( v1 <= dword_3F03D38C
    && ((result = g_ulLastCycleSample, v2) || *a1 < (unsigned int)g_ulLastCycleSample)
    && (++g_cBadCycleCountReceived, g_cBadCycleCountReceived < 1000) )
  {
    *a1 = g_ulLastCycleSample;
    a1[1] = dword_3F03D38C;
  }
  else
  {
    result = *a1;
    g_ulLastCycleSample = *a1;
    dword_3F03D38C = a1[1];
    g_cBadCycleCountReceived = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F001E90
// Name: IsWin98OrOlder
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsWin98OrOlder()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F001F40
// Name: bool Check3DNowTechnology(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge Check3DNowTechnology@<eax>(unsigned int a1@<eax>, int a2@<ebp>, _BYTE *a3@<edi>, int a4@<esi>, int a5)
{
  *a3 = a1;
  a3[1] = a1;
  *(_DWORD *)(a4 + 8) = (unsigned int)((*(unsigned int *)(a2 - 16) * (unsigned __int64)a1) >> 32) >> 4;
  *(_DWORD *)(a2 - 4) = -1;
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F001FA0
// Name: char const __near * GetProcessorVendorId(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__userpurge GetProcessorVendorId@<eax>(const char *result@<eax>, int a2@<ebp>, _DWORD *a3@<esi>, int a4)
{
  *(_DWORD *)result += result;
  a3[1] = 0;
  a3[2] = 0;
  *(_DWORD *)(a2 - 4) = -1;
  *a3 = &ICpuTopology::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002020
// Name: HTSupported
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __fastcall HTSupported(int a1, int a2)
{
  if ( a2 != 1 )
    JUMPOUT(0x3F002010);
}

//------------------------------------------------------------------------------
// Address: 0x3F0020D0
// Name: CalculateClockSpeed
// Source: json
//------------------------------------------------------------------------------
FARPROC __cdecl CalculateClockSpeed()
{
  HMODULE ModuleHandleA; // edi
  BOOL (__stdcall *VerifyVersionInfoA)(LPOSVERSIONINFOEXA, DWORD, DWORDLONG); // ebx
  FARPROC result; // eax
  ULONGLONG (__stdcall *VerSetConditionMask)(ULONGLONG, DWORD, BYTE); // esi
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  int v8; // [esp+40h] [ebp-A0h] BYREF
  _DWORD v9[28]; // [esp+44h] [ebp-9Ch] BYREF
  _LARGE_INTEGER startCount; // [esp+D0h] [ebp-10h]

  ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32");
  VerifyVersionInfoA = (BOOL (__stdcall *)(LPOSVERSIONINFOEXA, DWORD, DWORDLONG))GetProcAddress(
                                                                                   hModule: ModuleHandleA,
                                                                                   lpProcName: "VerifyVersionInfoA");
  result = nullptr;
  if ( VerifyVersionInfoA != nullptr )
  {
    VerSetConditionMask = (ULONGLONG (__stdcall *)(ULONGLONG, DWORD, BYTE))GetProcAddress(
                                                                             hModule: ModuleHandleA,
                                                                             lpProcName: "VerSetConditionMask");
    v8 = 156;
    memset_0(a1: v9, Val: 0, Size: 0x98u);
    v9[0] = 6;
    v9[1] = 0;
    startCount.HighPart = 0;
    v4 = ((__int64 (__stdcall *)(_DWORD, _DWORD, int, int))VerSetConditionMask)(a1: 0, a2: 0, a3: 2, a4: 3);
    v5 = ((__int64 (__stdcall *)(_DWORD, _DWORD, int, int))VerSetConditionMask)(a1: v4, a2: HIDWORD(v4), a3: 1, a4: 3);
    v6 = ((__int64 (__stdcall *)(_DWORD, _DWORD, int, int))VerSetConditionMask)(a1: v5, a2: HIDWORD(v5), a3: 32, a4: 3);
    v7 = ((__int64 (__stdcall *)(_DWORD, _DWORD, int, int))VerSetConditionMask)(a1: v6, a2: HIDWORD(v6), a3: 16, a4: 3);
    if ( ((int (__stdcall *)(int *, int, _DWORD, _DWORD))VerifyVersionInfoA)(a1: &v8, a2: 51, a3: v7, a4: HIDWORD(v7)) != 0 )
      return GetProcAddress(hModule: ModuleHandleA, lpProcName: "GetLogicalProcessorInformation");
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0021C0
// Name: _GetCPUInformation
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const CPUInformation *__usercall GetCPUInformation@<eax>(char a1@<cf>, int a2@<eax>, int a3@<ebp>, int a4@<edi>)
{
  const CPUInformation *result; // eax

  if ( a2 != a1 + *(_DWORD *)(2 * a4) )
    return (const CPUInformation *)dword_3F041BCC;
  *(_DWORD *)(a3 - 4) = 0;
  result = (const CPUInformation *)CalculateClockSpeed();
  dword_3F041BCC = (int)result;
  *(_DWORD *)(a3 - 4) = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F001EB0
// Name: sub_3F001EB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall sub_3F001EB0(unsigned int SystemAffinityMask)
{
  unsigned int result; // eax
  HANDLE CurrentProcess; // eax
  unsigned int ProcessAffinityMask; // [esp+0h] [ebp-4h] BYREF

  result = 0;
  ProcessAffinityMask = 0;
  if ( SystemAffinityMask == 1 )
  {
    CurrentProcess = GetCurrentProcess();
    GetProcessAffinityMask(
      hProcess: CurrentProcess,
      lpProcessAffinityMask: &ProcessAffinityMask,
      lpSystemAffinityMask: &SystemAffinityMask);
    return ProcessAffinityMask;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002210
// Name: sub_3F002210
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__thiscall sub_3F002210(void *Block, char a2)
{
  ((void (__stdcall *)(void *))loc_3F001F70)(a1: Block);
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}

//------------------------------------------------------------------------------
// Address: 0x3F002240
// Name: sub_3F002240
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __userpurge sub_3F002240@<al>(unsigned __int8 *a1@<esi>, unsigned __int8 a2, unsigned __int8 a3)
{
  char v3; // dl
  unsigned __int8 i; // bl
  char v5; // al
  unsigned __int8 j; // bl
  char v7; // di
  unsigned __int8 v8; // dl
  unsigned __int8 result; // al

  *a1 = a2;
  a1[1] = a3;
  v3 = 8;
  for ( i = 0x80; i != 0; i >>= 1 )
  {
    if ( (i & (unsigned __int8)(a2 / (__int16)a3 - 1)) != 0 )
      break;
    --v3;
  }
  a1[2] = v3;
  v5 = 8;
  for ( j = 0x80; j != 0; j >>= 1 )
  {
    if ( (j & (unsigned __int8)(a3 - 1)) != 0 )
      break;
    --v5;
  }
  a1[6] = 8 - v5 - v3;
  v7 = v3;
  v8 = -1 << (v3 + v5);
  a1[4] = v5;
  a1[7] = v8;
  result = ~(-1 << v7);
  a1[5] = v8 ^ (-1 << v7);
  a1[3] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0022C0
// Name: sub_3F0022C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall sub_3F0022C0@<eax>(_DWORD *a1@<esi>)
{
  if ( (dword_3F041BC8 & 1) == 0 )
  {
    dword_3F041BC8 |= 1u;
    sub_3F002410(a1: 0, a2: 0);
  }
  return dword_3F041BBC == *a1 && dword_3F041BC0 == a1[2] && dword_3F041BC4 == a1[1];
}

//------------------------------------------------------------------------------
// Address: 0x3F002350
// Name: sub_3F002350
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F002350@<eax>(int a1@<edi>, unsigned int a2)
{
  int result; // eax
  bool v3; // cf
  bool v4; // zf
  int v5; // [esp+4h] [ebp-1Ch]

  if ( (dword_3F041BB4 & 1) == 0 )
  {
    dword_3F041BB4 |= 1u;
    sub_3F002410(a1: 0, a2: 0);
    dword_3F041BB0 = v5;
  }
  if ( (dword_3F041BB4 & 2) == 0 )
  {
    dword_3F041BB4 |= 2u;
    sub_3F002410(a1: 0x80000000, a2: 0);
    dword_3F041BAC = v5;
  }
  LOBYTE(result) = 0;
  if ( a1 == 0x80000000 )
  {
    v3 = a2 < dword_3F041BAC;
    v4 = a2 == dword_3F041BAC;
    goto LABEL_9;
  }
  if ( a1 == 0 )
  {
    v3 = a2 < dword_3F041BB0;
    v4 = a2 == dword_3F041BB0;
LABEL_9:
    LOBYTE(result) = v3 || v4;
  }
  return (unsigned __int8)result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002410
// Name: sub_3F002410
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F002410(_DWORD *this, __int64 a2)
{
  int result; // eax

  _EAX = a2 | HIDWORD(a2);
  __asm { cpuid }
  *this = result;
  *(this + 1) = _EBX;
  *(this + 2) = _ECX;
  *(this + 3) = _EDX;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002470
// Name: ??0CStack@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CStack::CStack(CStack *this@<ecx>, _DWORD *a2@<eax>, char a3@<dl>, int a4@<ebx>)
{
  bool v4; // of

  v4 = __OFADD__(a3, *(_BYTE *)(a4 - 115));
  *(_BYTE *)(a4 - 115) += a3;
  if ( !v4 )
  {
    *a2 = &`anonymous namespace'::CpuidImpl::`vftable';
    JUMPOUT(0x3F00247C);
  }
  JUMPOUT(0x3F00249A);
}

//------------------------------------------------------------------------------
// Address: 0x3F002480
// Name: ?Reset@CStack@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CStack::Reset(CStack *this@<ecx>, int a2@<ebx>, int a3@<ebp>, unsigned __int8 *a4@<esi>)
{
  unsigned __int8 v4; // [esp-8h] [ebp-8h]
  unsigned __int8 v5; // [esp-4h] [ebp-4h]

  sub_3F002240(a1: a4, a2: v4, a3: v5);
  *(_DWORD *)(a3 - 20) = a2;
  JUMPOUT(0x3F002489);
}

//------------------------------------------------------------------------------
// Address: 0x3F002490
// Name: ?Add@CStack@@QAEX_K@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CStack::Add(
        CStack *this@<ecx>,
        char a2@<sf>,
        char a3@<of>,
        unsigned int a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        unsigned __int64 ulPC)
{
  unsigned int v7; // [esp-4h] [ebp-4h]

  if ( a2 != a3 )
  {
    *(_DWORD *)(a5 - 32) = a6;
    if ( sub_3F002350(a1: a6, a2: v7) != 0 )
      sub_3F002410(this: (_DWORD *)(a5 - 44), a2: __SPAIR64__(a4, a6));
    JUMPOUT(0x3F0024AB);
  }
  JUMPOUT(0x3F00246E);
}

//------------------------------------------------------------------------------
// Address: 0x3F0024B0
// Name: ?GetThreadId@CThread@@QAEIXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThread::GetThreadId(CVProfNode *this@<ecx>, _BYTE *a2@<eax>, char a3@<dl>)
{
  bool v3; // zf

  v3 = a3 + *a2 == 0;
  *a2 += a3;
  if ( !v3 )
    JUMPOUT(0x3F0024B4);
  JUMPOUT(0x3F002524);
}

//------------------------------------------------------------------------------
// Address: 0x3F0024C0
// Name: ?NGetPC@CStack@@QAE_KH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CStack::NGetPC(CStack *this@<ecx>, int a2@<ebp>, _DWORD *a3@<esi>, int iPC)
{
  if ( sub_3F0022C0(a1: a3) )
  {
    if ( sub_3F002350(a1: 0, a2: 4u) != 0 )
    {
      sub_3F002410(this: (_DWORD *)(a2 - 44), a2: 0x400000000LL);
      JUMPOUT(0x3F002521);
    }
    JUMPOUT(0x3F002524);
  }
  sub_3F002350(a1: 0x80000000, a2: 8u);
  JUMPOUT(0x3F0024F8);
}

//------------------------------------------------------------------------------
// Address: 0x3F002520
// Name: __AssertValidReadPtr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F002550
// Name: __AssertValidWritePtr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _AssertValidWritePtr(void *a1@<ebx>, int a2@<ebp>, void *a3@<edi>)
{
  int v3; // eax
  int v4; // eax
  void *v5; // [esp-18h] [ebp-18h]
  unsigned int *v6; // [esp-14h] [ebp-14h]
  unsigned int *v7; // [esp-10h] [ebp-10h]

  GetProcessAffinityMask(hProcess: v5, lpProcessAffinityMask: v6, lpSystemAffinityMask: v7);
  v3 = *(_DWORD *)(a2 - 16);
  if ( v3 == 1 )
  {
    v4 = *(_DWORD *)(a2 + 8);
    *(_BYTE *)((unsigned __int8)(*(_BYTE *)(v4 + 36))++ + v4 + 4) = 0;
    *(_DWORD *)(a2 - 4) = -1;
    JUMPOUT(0x3F002582);
  }
  if ( *(_DWORD *)(a2 - 24) != v3 )
  {
    SetProcessAffinityMask(hProcess: a3, dwProcessAffinityMask: *(_DWORD *)(a2 - 16));
    v3 = *(_DWORD *)(a2 - 16);
  }
  *(_DWORD *)(a2 - 20) = 0;
  if ( v3 != 0 )
  {
    if ( (v3 & 1) != 0 )
    {
      if ( *(_DWORD *)(a2 - 20) == 0 )
      {
        *(_DWORD *)(a2 - 20) = SetThreadAffinityMask(hThread: a1, dwThreadAffinityMask: 1u);
        JUMPOUT(0x3F0025C5);
      }
      JUMPOUT(0x3F0025BF);
    }
    JUMPOUT(0x3F002603);
  }
  JUMPOUT(0x3F002607);
}

} // namespace tier0_s
