// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/is_prefix.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041DF10
// Name: _is_prefix
// Source: json
//------------------------------------------------------------------------------
int __cdecl is_prefix(_LDBL12 *result, char *t)
{
  char *v2; // ecx
  char v3; // al
  unsigned __int8 v5; // dl

  v2 = t;
  v3 = *t;
  if ( *t == 0 )
    return 1;
  while ( 1 )
  {
    v5 = result->ld12[0];
    ++v2;
    result = (_LDBL12 *)((char *)result + 1);
    if ( v5 != v3 )
      break;
    v3 = *v2;
    if ( *v2 == 0 )
      return 1;
  }
  return 0;
}
