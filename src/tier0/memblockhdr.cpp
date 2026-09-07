// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/memblockhdr.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x3F003780
// Name: void InitStackWalk(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitStackWalk(int (__stdcall *a1)(HMODULE, const char *)@<esi>)
{
  HMODULE LibraryA; // eax
  int v2; // eax

  if ( InterlockedCompareExchange(Destination: &Target, Exchange: -1, Comperand: 0) == 0 )
  {
    if ( hLibModule == nullptr )
    {
      InitializeCriticalSection(lpCriticalSection: &stru_3F03D2D0);
      LibraryA = LoadLibraryA(lpLibFileName: "DbgHelp.dll");
      hLibModule = LibraryA;
      if ( LibraryA != nullptr )
      {
        dword_3F03D390 = a1(a1: LibraryA, a2: "StackWalk64");
        dword_3F03D394 = a1(a1: hLibModule, a2: "SymSetOptions");
        dword_3F03D398 = a1(a1: hLibModule, a2: "SymInitialize");
        dword_3F03D39C = a1(a1: hLibModule, a2: "SymGetLineFromAddr64");
        dword_3F03D3A0 = a1(a1: hLibModule, a2: "SymFromAddr");
        dword_3F03D3A4 = a1(a1: hLibModule, a2: "SymCleanup");
        dword_3F03D3A8 = a1(a1: hLibModule, a2: "SymFunctionTableAccess64");
        v2 = a1(a1: hLibModule, a2: "SymGetModuleBase64");
        dword_3F03D3AC = v2;
        if ( dword_3F03D390 == 0
          || dword_3F03D394 == 0
          || dword_3F03D398 == 0
          || dword_3F03D39C == 0
          || dword_3F03D3A0 == 0
          || dword_3F03D3A4 == 0
          || dword_3F03D3A8 == 0
          || v2 == 0 )
        {
          FreeLibrary(hLibModule: hLibModule);
          DeleteCriticalSection(lpCriticalSection: &stru_3F03D2D0);
          hLibModule = nullptr;
        }
      }
      else
      {
        DeleteCriticalSection(lpCriticalSection: &stru_3F03D2D0);
      }
      JUMPOUT(0x3F0038D1);
    }
    JUMPOUT(0x3F0038CB);
  }
  JUMPOUT(0x3F0038DD);
}

//------------------------------------------------------------------------------
// Address: 0x3F0038D0
// Name: void RealGetCallStack(class CStack __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall RealGetCallStack(CStack *stack@<esi>, int _EAX@<eax>, LONG a3@<edi>)
{
  __asm { aas }
  InterlockedExchange(Target: &Target, Value: a3);
  if ( a3 == -1 )
    InitStackWalk(a1: (int (__stdcall *)(HMODULE, const char *))stack);
}

//------------------------------------------------------------------------------
// Address: 0x3F003A20
// Name: sub_3F003A20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__usercall sub_3F003A20@<eax>(_BYTE *result@<eax>, char *a2@<edx>, int a3)
{
  char i; // cl

  for ( i = *a2; *a2 != 0; ++result )
  {
    if ( (int)&result[1 - a3] >= 2048 )
      break;
    ++a2;
    *result = i;
    i = *a2;
  }
  *result = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F003A60
// Name: sub_3F003A60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None
