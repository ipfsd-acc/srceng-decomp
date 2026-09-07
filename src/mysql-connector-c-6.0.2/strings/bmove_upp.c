// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/bmove_upp.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00411640
// Name: _bmove_upp
// Source: json
//------------------------------------------------------------------------------
int __cdecl bmove_upp(_BYTE *a1, int a2, int a3)
{
  int result; // eax
  char v6; // dl

  for ( result = a3; result != 0; *a1 = v6 )
  {
    v6 = *(_BYTE *)--a2;
    --result;
    --a1;
  }
  return result;
}
