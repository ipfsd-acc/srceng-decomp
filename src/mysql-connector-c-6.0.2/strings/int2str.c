// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/int2str.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00410D20
// Name: _int10_to_str
// Source: json
//------------------------------------------------------------------------------
_strflt *__cdecl int10_to_str(int result, char *dst, int radix)
{
  unsigned int v3; // ecx
  char *v4; // edi
  signed int v5; // edx
  char *v6; // esi
  char i; // cl
  char v8; // al
  _BYTE v10[5]; // [esp+4Bh] [ebp-9h] BYREF

  v3 = result;
  v4 = dst;
  if ( radix < 0 && result < 0 )
  {
    *dst = 45;
    v4 = dst + 1;
    v3 = -result;
  }
  v5 = v3 / 0xA;
  v10[0] = v3 % 0xA + 48;
  v10[1] = 0;
  v6 = v10;
  for ( i = v3 / 0xA; v5 != 0; i = v5 )
  {
    v5 /= 10;
    *--v6 = i - 10 * v5 + 48;
  }
  do
  {
    v8 = *v6;
    *v4++ = *v6++;
  }
  while ( v8 != 0 );
  return (_strflt *)(v4 - 1);
}
