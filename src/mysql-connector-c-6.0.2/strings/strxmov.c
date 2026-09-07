// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strxmov.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414C30
// Name: _strxmov
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strxmov(char *dst, tagShutdownType src)
{
  char *v2; // ecx
  char *result; // eax
  tagShutdownType *p_src; // esi
  char v5; // dl

  v2 = (char *)src;
  result = dst;
  if ( src != IdleShutdown )
  {
    p_src = &src;
    do
    {
      do
      {
        v5 = *v2;
        *result++ = *v2++;
      }
      while ( v5 != 0 );
      ++p_src;
      src = (tagShutdownType)v2;
      v2 = (char *)*p_src;
      --result;
    }
    while ( *p_src != IdleShutdown );
  }
  *result = 0;
  return result;
}
