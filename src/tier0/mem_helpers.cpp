// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/mem_helpers.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10006540
// Name: void InitializeToFeeFee(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeToFeeFee(char *pMem, unsigned int nSize)
{
  unsigned int v2; // edx
  char *v3; // eax
  unsigned int v4; // ecx
  int v5; // esi

  v2 = nSize >> 2;
  v3 = pMem;
  if ( nSize >> 2 != 0 )
  {
    memset32(pMem, -1114130, v2);
    v3 = &pMem[4 * v2];
  }
  v4 = nSize & 3;
  if ( (nSize & 3) != 0 )
  {
    v5 = (char *)&g_dwFeeFee - v3;
    do
    {
      *v3 = v3[v5];
      ++v3;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006590
// Name: void InitializeToRandom(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeToRandom(_BYTE *pMem, unsigned int nSize)
{
  unsigned int i; // eax

  for ( i = 0; i < nSize; ++i )
    pMem[i] = g_RandomValues[(unsigned __int8)g_iCurRandomValueOffset++];
}

//------------------------------------------------------------------------------
// Address: 0x100065D0
// Name: void DoApplyMemoryInitializations(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoApplyMemoryInitializations(char *pMem, unsigned int nSize)
{
  unsigned __int8 *CommandLineA; // eax
  int v3; // eax
  int v4; // eax
  char tempStr[512]; // [esp+4h] [ebp-200h] BYREF

  if ( pMem != nullptr )
  {
    if ( (_S1_1 & 1) == 0 )
    {
      _S1_1 |= 1u;
      bDebuggerPresent = Plat_IsInDebugSession();
    }
    if ( !bCheckedCommandLine )
    {
      bCheckedCommandLine = true;
      CommandLineA = (unsigned __int8 *)Plat_GetCommandLineA();
      if ( CommandLineA != nullptr )
      {
        strncpy(dest: (unsigned __int8 *)tempStr, source: CommandLineA, count: 0x1FFu);
        tempStr[511] = 0;
        _strupr(string: tempStr);
        strstr(str1: (unsigned __int8 *)tempStr, str2: "-RANDOMIZEMEMORY");
        if ( v3 != 0 )
          bRandomizeMemory = true;
        strstr(str1: (unsigned __int8 *)tempStr, str2: "-NOINITMEMORY");
        if ( v4 != 0 )
          g_bInitMemory = false;
      }
    }
    if ( bRandomizeMemory )
    {
      InitializeToRandom(pMem, nSize);
    }
    else if ( bDebuggerPresent )
    {
      InitializeToFeeFee(pMem, nSize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100066C0
// Name: unsigned int CalcHeapUsed(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CalcHeapUsed()
{
  int v0; // esi
  int i; // eax
  _heapinfo hinfo; // [esp+4h] [ebp-Ch] BYREF

  v0 = 0;
  hinfo._pentry = nullptr;
  for ( i = _heapwalk(_entry: &hinfo); i == -2; i = _heapwalk(_entry: &hinfo) )
    v0 += hinfo._useflag == 1 ? hinfo._size : 0;
  if ( i == -5 || i == -1 )
    return v0;
  else
    return -1;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F003590
// Name: void InitializeToFeeFee(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0035E0
// Name: void InitializeToRandom(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeToRandom(
        char *pMem@<edi>,
        int nSize@<esi>,
        void (*a3)(void)@<eax>,
        void *a4@<edx>,
        unsigned int a5@<ecx>,
        int a6@<ebx>,
        int a7@<ebp>)
{
  const char *v7; // edi

  v7 = &pMem[*(_DWORD *)pMem];
  if ( a3 != nullptr )
    a3();
  if ( a6 == 0 )
  {
    if ( (unsigned __int8)((int (*)(void))ShouldUseNewAssertDialog)() != 0 && DoNewAssertDialog() != 0 )
      __debugbreak();
    if ( *(_BYTE *)(a7 + 12) != 0 )
    {
      ExitOnFatalAssert(a1: v7, a2: nSize);
      JUMPOUT(0x3F003615);
    }
  }
  if ( **(_BYTE **)(a7 + 24) != 0 )
    JUMPOUT(0x3F003640);
  ApplyMemoryInitializations(pMem: a4, nSize: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F003620
// Name: void ApplyMemoryInitializations(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall ApplyMemoryInitializations(_BYTE *a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  if ( !IsDebuggerPresent() )
  {
    WriteMiniDump(a1: *(_DWORD *)(a2 + 8), a2: a3, a3: a4, a4: *(_DWORD *)(a2 + 28), a5: 0);
    *a1 = 1;
  }
  byte_3F03D369 = 0;
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
}

} // namespace tier0_s
