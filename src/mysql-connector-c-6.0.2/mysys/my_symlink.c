// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_symlink.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004193E0
// Name: _my_readlink
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_readlink(void *dst, char *a2)
{
  strmov(dst, dsta: (char *)dst, src: a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419400
// Name: _my_realpath
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_realpath(int a1, _LDBL12 *result)
{
  my_load_path(a1, result, src: 0);
  return 0;
}
