// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/uncompr.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042F660
// Name: _uncompress
// Source: json
//------------------------------------------------------------------------------
int __cdecl uncompress(int a1, int *a2, int a3, int a4)
{
  int v4; // eax
  int result; // eax
  int v6; // esi
  int v7; // [esp+4h] [ebp-38h] BYREF
  int v8; // [esp+8h] [ebp-34h]
  int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+28h] [ebp-14h]

  v8 = a4;
  v7 = a3;
  v4 = *a2;
  v9 = a1;
  v10 = v4;
  v12 = 0;
  v13 = 0;
  result = inflateInit_(a1: &v7, a2: "1.2.3", a3: 56);
  if ( result == 0 )
  {
    v6 = inflate(a1: &v7, a2: 4);
    if ( v6 == 1 )
    {
      *a2 = v11;
      return inflateEnd(a1: &v7);
    }
    else
    {
      inflateEnd(a1: &v7);
      if ( v6 == 2 || v6 == -5 && v8 == 0 )
        return -3;
      else
        return v6;
    }
  }
  return result;
}
