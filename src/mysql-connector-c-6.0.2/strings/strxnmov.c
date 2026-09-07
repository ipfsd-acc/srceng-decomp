// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strxnmov.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414BE0
// Name: _strxnmov
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strxnmov(char *dst, unsigned int len, char *src)
{
  char *result; // eax
  char *v4; // ecx
  tagShutdownType *p_src; // esi
  char v6; // dl

  result = dst;
  v4 = src;
  if ( src != nullptr )
  {
    p_src = (tagShutdownType *)&src;
    while ( result != &dst[len] )
    {
      v6 = *v4;
      *result++ = *v4++;
      src = v4;
      if ( v6 == 0 )
      {
        v4 = *((char **)p_src++ + 1);
        --result;
        if ( v4 == nullptr )
          break;
      }
    }
  }
  *result = 0;
  return result;
}
