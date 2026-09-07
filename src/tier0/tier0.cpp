// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/tier0.cpp
// Functions: 2
// ============================================================

#include "tier0\tier0.h"

//------------------------------------------------------------------------------
// Address: 0x3F0118D0
// Name: public: class CTier0 __near & CTier0::operator=(class CTier0 const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CTier0::operator=(void *this, int a2)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F0118E0
// Name: public: static void CTier0::ValidateGlobals(class CValidator __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CTier0::ValidateGlobals(struct CValidator *a1)
{
  void *v1; // eax
  void (__thiscall ***v2)(_DWORD, struct CValidator *); // eax
  int v3; // [esp+0h] [ebp-4h]

  v1 = (void *)((int (__stdcall *)(int))loc_3F00EA90)(a1: v3);
  sub_3F00EC50(a1: v1, a2: (int)a1);
  if ( dword_3F03F288 != nullptr )
  {
    v2 = (void (__thiscall ***)(_DWORD, struct CValidator *))dword_3F03F288(a1: "IVALIDATE001", a2: 0);
    if ( v2 != nullptr )
      (**v2)(a1: v2, a2: a1);
  }
}
