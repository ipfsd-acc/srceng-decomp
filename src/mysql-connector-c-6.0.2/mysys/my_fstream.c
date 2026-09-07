// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_fstream.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042F860
// Name: _my_fileno
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl my_fileno(_iobuf *file)
{
  return my_win_fileno(file);
}
