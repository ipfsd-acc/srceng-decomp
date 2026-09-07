// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_arr_appstr.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004242E0
// Name: _array_append_string_unique
// Source: json
//------------------------------------------------------------------------------
char __cdecl array_append_string_unique(const char *a1, const char **a2, int a3)
{
  const char **v3; // esi
  const char *i; // eax

  v3 = a2;
  for ( i = *a2; i != nullptr; ++v3 )
  {
    if ( strcmp(i, a1) == 0 )
      break;
    i = v3[1];
  }
  if ( v3 >= &a2[a3 - 1] )
    return 1;
  for ( ; v3[1] != nullptr; ++v3 )
    *v3 = v3[1];
  *v3 = a1;
  return 0;
}
