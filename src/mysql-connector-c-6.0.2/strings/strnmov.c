// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strnmov.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00418DA0
// Name: _strnmov
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strnmov(char *dst, char *src, unsigned int n)
{
  char *result; // eax
  unsigned int v4; // esi
  char v6; // cl

  result = dst;
  v4 = n;
  if ( n != 0 )
  {
    while ( 1 )
    {
      v6 = *src;
      *result = *src;
      --v4;
      ++result;
      ++src;
      if ( v6 == 0 )
        break;
      if ( v4 == 0 )
        return result;
    }
    --result;
  }
  return result;
}
