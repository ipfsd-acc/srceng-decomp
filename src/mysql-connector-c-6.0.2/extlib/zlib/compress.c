// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/compress.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042F590
// Name: _compress2
// Source: json
//------------------------------------------------------------------------------
int __cdecl compress2(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // esi
  _DWORD v7[14]; // [esp+4h] [ebp-38h] BYREF

  v7[1] = a4;
  v7[3] = a1;
  v7[0] = a3;
  v7[4] = *a2;
  memset(&v7[8], 0, 12);
  result = deflateInit_(a1: v7, a2: a5, a3: "1.2.3", a4: 56);
  if ( result == 0 )
  {
    v6 = deflate(a1: v7, a2: 4);
    if ( v6 == 1 )
    {
      *a2 = v7[5];
      return deflateEnd(a1: v7);
    }
    else
    {
      deflateEnd(a1: v7);
      result = -5;
      if ( v6 != 0 )
        return v6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F640
// Name: _compress
// Source: json
//------------------------------------------------------------------------------
int __cdecl compress(int a1, _DWORD *a2, int a3, int a4)
{
  return compress2(a1, a2, a3, a4, a5: -1);
}
