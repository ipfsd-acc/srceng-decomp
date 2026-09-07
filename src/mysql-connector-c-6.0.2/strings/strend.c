// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strend.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417B70
// Name: _strend
// Source: json
//------------------------------------------------------------------------------
ioinfo *__cdecl strend(ioinfo *result)
{
  return (ioinfo *)((char *)result + strlen((const char *)result));
}
