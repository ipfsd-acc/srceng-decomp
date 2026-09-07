// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/thread.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x3F0075D0
// Name: _Plat_SetThreadName
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Plat_SetThreadName(int a1@<ebp>)
{
  void *v1; // [esp+10h] [ebp-18h]
  unsigned int v2; // [esp+14h] [ebp-14h]
  int v3; // [esp+18h] [ebp-10h]
  void (__thiscall *v4)(void *); // [esp+1Ch] [ebp-Ch]
  void (__thiscall *v5)(void *); // [esp+20h] [ebp-8h]

  `eh vector constructor iterator'(a1: v1, a2: v2, a3: v3, a4: v4, a5: v5);
  *(_DWORD *)(a1 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F007660
// Name: _Plat_RegisterThread
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_RegisterThread()
{
  JUMPOUT(0x3F00767C);
}

//------------------------------------------------------------------------------
// Address: 0x3F0076A0
// Name: _Plat_GetCurrentThreadID
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_GetCurrentThreadID()
{
  JUMPOUT(0x3F0076B8);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F050
// Name: Plat_RegisterThread
// Source: json
//------------------------------------------------------------------------------
DWORD Plat_RegisterThread()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex) + 4) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F070
// Name: Plat_RegisterPrimaryThread
// Source: json
//------------------------------------------------------------------------------
DWORD Plat_RegisterPrimaryThread()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex) + 4) = result;
  Plat_PrimaryThreadID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F090
// Name: Plat_GetCurrentThreadID
// Source: json
//------------------------------------------------------------------------------
int Plat_GetCurrentThreadID()
{
  return *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F0B0
// Name: sub_3F00F0B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall sub_3F00F0B0(unsigned int (__cdecl **Block)(int))
{
  unsigned int (__cdecl *v1)(int); // esi
  unsigned int (__cdecl *v2)(int); // edi

  v1 = *Block;
  v2 = Block[1];
  j__free(Block);
  return v1(a1: (int)v2);
}
