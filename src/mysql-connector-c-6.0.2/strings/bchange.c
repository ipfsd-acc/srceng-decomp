// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/bchange.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042F9B0
// Name: _bchange
// Source: json
//------------------------------------------------------------------------------
void __cdecl bchange(unsigned __int8 *dst, unsigned int a2, unsigned __int8 *src, unsigned int count, int a5)
{
  unsigned int v5; // [esp-4h] [ebp-Ch]

  v5 = a5 - a2;
  if ( a2 >= count )
    memmove(dst: &dst[count], src: &dst[a2], count: v5);
  else
    bmove_upp(a1: &dst[a5 - a2 + count], a2: (int)&dst[a5], a3: v5);
  memcpy(dst, src, count);
}
