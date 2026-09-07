// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/zutil.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00454360
// Name: _zcalloc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl zcalloc(int a1, int a2, int a3)
{
  return operator new(nSize: a3 * a2);
}

//------------------------------------------------------------------------------
// Address: 0x00454380
// Name: _zcfree
// Source: json
//------------------------------------------------------------------------------
void __cdecl zcfree(int a1, void *pMem)
{
  free(pMem);
}
