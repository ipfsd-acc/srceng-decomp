// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxstring.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0056F660
// Name: _mx_strcasecmp
// Source: json
//------------------------------------------------------------------------------
int __cdecl mx_strcasecmp(const char *s1, const char *s2)
{
  return _stricmp(dst: s1, src: s2);
}
