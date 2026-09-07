// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strcend.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00416130
// Name: _strcend
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strcend(char *s, char c)
{
  char *result; // eax
  char v3; // cl

  result = s;
  v3 = *s;
  if ( *s != c )
  {
    while ( 1 )
    {
      ++result;
      if ( v3 == 0 )
        break;
      v3 = *result;
      if ( *result == c )
        return result;
    }
    --result;
  }
  return result;
}
