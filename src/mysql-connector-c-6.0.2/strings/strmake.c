// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strmake.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F450
// Name: _strmake
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strmake(char *dst, char *src, unsigned int length)
{
  char *result; // eax
  unsigned int v4; // esi
  char v6; // cl

  result = dst;
  v4 = length;
  if ( length != 0 )
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
        goto LABEL_4;
    }
    --result;
  }
  else
  {
LABEL_4:
    *result = 0;
  }
  return result;
}
