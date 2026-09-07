// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/strmov.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040E630
// Name: _strmov
// Source: json
//------------------------------------------------------------------------------
void __thiscall strmov(void *dst, char *dsta, char *src)
{
  char v5; // al

  do
  {
    v5 = *src;
    *dsta++ = *src++;
  }
  while ( v5 != 0 );
}
