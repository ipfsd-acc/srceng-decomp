// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/tier0_strtools.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000FF20
// Name: _V_tier0_stricmp
// Source: json
//------------------------------------------------------------------------------
int __cdecl V_tier0_stricmp(const char *s1, const char *s2)
{
  int result; // eax
  int v5; // ecx

  do
  {
    while ( 1 )
    {
      result = *(unsigned __int8 *)s1;
      v5 = *(unsigned __int8 *)s2;
      if ( result == v5 )
      {
        if ( *s1 == 0 )
          return result;
      }
      else
      {
        if ( *s2 == 0 )
          return result;
        if ( (unsigned int)(result - 65) <= 0x19 )
          result += 32;
        if ( (unsigned int)(v5 - 65) <= 0x19 )
          v5 += 32;
        if ( result != v5 )
          goto LABEL_19;
      }
      result = *((unsigned __int8 *)s1 + 1);
      v5 = *((unsigned __int8 *)s2 + 1);
      s1 += 2;
      s2 += 2;
      if ( result != v5 )
        break;
      if ( result == 0 )
        return result;
    }
    if ( v5 == 0 )
      return result;
    if ( (unsigned int)(result - 65) <= 0x19 )
      result += 32;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( result == v5 );
LABEL_19:
  result -= v5;
  return result;
}
