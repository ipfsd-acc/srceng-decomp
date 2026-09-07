// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/osversion.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x3F60BD30
// Name: _Q_memset
// Source: json
//------------------------------------------------------------------------------
void *__cdecl Q_memset(int a1, int a2, void *a3, int Val, int Size)
{
  bool v5; // zf

  v5 = Size == 0;
  if ( Size < 0 )
  {
    AssertMsgImplementation(a1: "Assertion Failed: count >= 0", 0, ".\\strtools.cpp", 121, &unk_3F665783, 0);
    v5 = Size == 0;
  }
  if ( !v5 && a3 == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  return memset(a1: a3, Val, Size);
}

//------------------------------------------------------------------------------
// Address: 0x3F612BA0
// Name: void Q_memset(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void Q_memset()
{
  JUMPOUT(0x3F612BB2);
}

//------------------------------------------------------------------------------
// Address: 0x3F612BC0
// Name: _GetOSType
// Source: json
//------------------------------------------------------------------------------
void __usercall GetOSType(int a1@<eax>, int a2@<ebx>, int a3@<ebp>)
{
  LOBYTE(a1) = a1 & 0x10;
  *(_DWORD *)(a2 + 20) = __ROL4__(a3, 1);
  *(_DWORD *)(*(_DWORD *)(a1 + 180) + 24) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a1 + 180) + 24)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 12)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 32)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 56),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a1 + 180) + 28) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a1 + 180) + 28)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 16)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 36)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 60),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a1 + 180) + 32) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a1 + 180) + 32)
                                            ^ **(_DWORD **)(a1 + 180)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 20)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 40),
                                              1);
  *(_DWORD *)(*(_DWORD *)(a1 + 180) + 36) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a1 + 180) + 36)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 4)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 24)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 44),
                                              1);
  JUMPOUT(0x3F612CD7);
}

//------------------------------------------------------------------------------
// Address: 0x3F612CE0
// Name: _GetNameFromOSType
// Source: json
//------------------------------------------------------------------------------
void __usercall GetNameFromOSType(
        int a1@<eax>,
        char a2@<dh>,
        int a3@<ecx>,
        _BYTE *a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>)
{
  bool v6; // cf
  int v7; // ecx

  v6 = __CFADD__(*(_BYTE *)(a5 - 1126424908), (_BYTE)a3);
  LOBYTE(a3) = *(_BYTE *)(a5 - 1126424908) + a3;
  v7 = a3 - (v6 + *(_DWORD *)(a6 + 1804328331));
  *a4 ^= a2;
  LOBYTE(a1) = a1 & 0x10;
  *(_DWORD *)(76 * *(_DWORD *)(5 * v7) + 0x28) = __ROL4__(
                                                   *(_DWORD *)(76 * *(_DWORD *)(5 * v7) + 0x28)
                                                 ^ *(_DWORD *)(76 * *(_DWORD *)(5 * v7) + 8)
                                                 ^ a5,
                                                   1);
  *(_DWORD *)(*(_DWORD *)(a1 + 180) + 44) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a1 + 180) + 44)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 12)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 32)
                                            ^ *(_DWORD *)(*(_DWORD *)(a1 + 180) + 52),
                                              1);
  JUMPOUT(0x3F612D56);
}

//------------------------------------------------------------------------------
// Address: 0x3F612D60
// Name: _GetOSTypeFromString
// Source: json
//------------------------------------------------------------------------------
void __usercall GetOSTypeFromString(int a1@<ecx>, int a2@<ebx>)
{
  *(_DWORD *)(a1 + 48) = __ROL4__(*(_DWORD *)(a1 + 48) ^ *(_DWORD *)(a1 + 16) ^ a2, 1);
  JUMPOUT(0x3F612DAC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6155B0
// Name: __Q_memset
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _Q_memset(int a1@<eax>, int a2@<ecx>, int a3@<esi>)
{
  unsigned int v3; // eax
  int v4; // esi

  v3 = (unsigned int)&dword_3F664280 | a1;
  *(&String + a3) = *(_BYTE *)(v3 + a2);
  dword_3F66428C = v3 + 1;
  v4 = a3 + 1;
  if ( isdigit_0(C: *(char *)(v3 + 1 + a2)) != 0 )
    JUMPOUT(0x3F6155A2);
  if ( v4 < 127 )
    *(&String + v4) = 0;
}
