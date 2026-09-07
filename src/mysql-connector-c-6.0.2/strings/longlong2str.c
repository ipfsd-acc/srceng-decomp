// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/longlong2str.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00411660
// Name: _ll2str
// Source: json
//------------------------------------------------------------------------------
void __stdcall ll2str(__int64 val, char *dst, int radix, int upcase)
{
  char *v4; // ebp
  int v5; // ebx
  unsigned __int64 v6; // kr00_8
  char *v7; // esi
  unsigned __int64 v8; // rax
  int i; // ecx
  char v10; // al
  char *dig_vec; // [esp+Ch] [ebp-50h]
  char *v12; // [esp+10h] [ebp-4Ch]
  char v13; // [esp+54h] [ebp-8h] BYREF

  v4 = dst;
  v12 = dst;
  dig_vec = (char *)_dig_vec_upper;
  if ( upcase == 0 )
    dig_vec = "0123456789abcdefghijklmnopqrstuvwxyz";
  v5 = radix;
  v6 = val;
  if ( radix >= 0 )
  {
    if ( (unsigned int)(radix - 2) > 0x22 )
      return;
  }
  else
  {
    if ( (unsigned int)(radix + 36) > 0x22 )
      return;
    if ( val < 0 )
    {
      v4 = dst + 1;
      *dst = 45;
      v12 = dst + 1;
      v6 = -val;
    }
    v5 = -radix;
  }
  if ( v6 != 0 )
  {
    v7 = &v13;
    v13 = 0;
    if ( v6 > 0x7FFFFFFF )
    {
      do
      {
        v8 = v6 / (unsigned int)v5;
        *--v7 = dig_vec[v6 % (unsigned int)v5];
        v6 = v8;
      }
      while ( v8 > 0x7FFFFFFF );
      v4 = v12;
    }
    for ( i = v6; i != 0; i /= v5 )
      *--v7 = dig_vec[(unsigned __int8)(i % v5)];
    do
    {
      v10 = *v7;
      *v4++ = *v7++;
    }
    while ( v10 != 0 );
  }
  else
  {
    *v4 = 48;
    v4[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004117B0
// Name: _longlong10_to_str
// Source: json
//------------------------------------------------------------------------------
void __stdcall longlong10_to_str(int val, signed int dst, char *radix, int radixa)
{
  signed int v4; // ecx
  char *v5; // ebp
  unsigned int v6; // edi
  char *v7; // esi
  unsigned __int64 v8; // kr00_8
  signed int i; // ebx
  char v10; // al
  char v11; // [esp+48h] [ebp-8h] BYREF

  v4 = dst;
  v5 = radix;
  v6 = val;
  if ( radixa < 0 && dst < 0 )
  {
    *radix = 45;
    v5 = radix + 1;
    v6 = -val;
    v4 = (unsigned __int64)-__SPAIR64__(dst, val) >> 32;
  }
  if ( (v4 | v6) != 0 )
  {
    v7 = &v11;
    v11 = 0;
    if ( v4 != 0 || v6 > 0x7FFFFFFF )
    {
      do
      {
        *--v7 = *((_BYTE *)_dig_vec_upper + __PAIR64__(v4, v6) % 0xA);
        v8 = __PAIR64__(v4, v6) / 0xA;
        v4 = (__PAIR64__(v4, v6) / 0xA) >> 32;
        v6 = v8;
      }
      while ( __PAIR64__(v4, v8) > 0x7FFFFFFF );
    }
    for ( i = v6; i != 0; i /= 10 )
      *--v7 = *((_BYTE *)_dig_vec_upper + (unsigned __int8)(i % 10));
    do
    {
      v10 = *v7;
      *v5++ = *v7++;
    }
    while ( v10 != 0 );
  }
  else
  {
    *v5 = 48;
    v5[1] = 0;
  }
}
