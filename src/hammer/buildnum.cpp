// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/buildnum.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009F60
// Name: int build_number(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl build_number()
{
  int result; // eax
  int v1; // edi
  int v2; // esi
  int v3; // edx
  int v4; // edi
  int v5; // eax
  int v6; // edi
  bool v7; // zf
  signed int v8; // eax

  result = b;
  v1 = 0;
  if ( b == 0 )
  {
    v2 = 0;
    do
    {
      if ( V_strnicmp(s1: date, s2: mon[v2], n: 3) == 0 )
        break;
      v3 = mond[v2++];
      v1 += v3;
    }
    while ( v2 < 11 );
    v4 = v1 + atoi(nptr: date + 4) - 1;
    v5 = atoi(nptr: date + 7) - 1900;
    v6 = v4 - (int)((double)(v5 - 1) * -365.25);
    v8 = v5 & 0x80000003;
    v7 = v8 == 0;
    if ( v8 < 0 )
      v7 = (((_BYTE)v8 - 1) | 0xFFFFFFFC) == -1;
    if ( v7 && v2 > 1 )
      ++v6;
    b = v6 - 34995;
    return v6 - 34995;
  }
  return result;
}
