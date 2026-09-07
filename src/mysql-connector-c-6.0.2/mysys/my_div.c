// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_div.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00418DD0
// Name: _my_filename
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl my_filename(int fd)
{
  _DWORD *v2; // eax

  if ( fd >= my_file_limit )
    return "UNKNOWN";
  if ( fd >= 0 )
  {
    v2 = (_DWORD *)((char *)my_file_info + 16 * fd);
    if ( v2[3] != 0 )
      return (const char *)*v2;
  }
  return "UNOPENED";
}
