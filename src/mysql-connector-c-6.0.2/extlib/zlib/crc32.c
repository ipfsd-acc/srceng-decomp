// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/crc32.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00454060
// Name: crc32_little
// Source: json
//------------------------------------------------------------------------------
int __usercall crc32_little@<eax>(int a1@<eax>, unsigned int a2@<edx>, _BYTE *a3@<ecx>)
{
  unsigned int v3; // esi
  unsigned int i; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  _BYTE *v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // eax

  v3 = a2;
  for ( i = ~a1; v3 != 0; --v3 )
  {
    if ( ((unsigned __int8)a3 & 3) == 0 )
      break;
    i = crc_table[(unsigned __int8)(i ^ *a3++)] ^ (i >> 8);
  }
  if ( v3 >= 0x20 )
  {
    v5 = v3 >> 5;
    do
    {
      v6 = *(_DWORD *)a3 ^ i;
      v7 = a3 + 8;
      v8 = *((_DWORD *)v7 - 1)
         ^ dword_482EE0[(unsigned __int8)v6]
         ^ crc_table[HIBYTE(v6)]
         ^ dword_482AE0[BYTE1(v6)]
         ^ dword_4826E0[BYTE2(v6)];
      v7 += 8;
      v9 = *((_DWORD *)v7 - 2)
         ^ dword_482EE0[(unsigned __int8)v8]
         ^ crc_table[HIBYTE(v8)]
         ^ dword_482AE0[BYTE1(v8)]
         ^ dword_4826E0[BYTE2(v8)];
      v7 += 8;
      v10 = *((_DWORD *)v7 - 3)
          ^ dword_482EE0[(unsigned __int8)v9]
          ^ crc_table[HIBYTE(v9)]
          ^ dword_482AE0[BYTE1(v9)]
          ^ dword_4826E0[BYTE2(v9)];
      v11 = *((_DWORD *)v7 - 2)
          ^ dword_482EE0[(unsigned __int8)v10]
          ^ crc_table[HIBYTE(v10)]
          ^ dword_482AE0[BYTE1(v10)]
          ^ dword_4826E0[BYTE2(v10)];
      v12 = *((_DWORD *)v7 - 1)
          ^ dword_482EE0[(unsigned __int8)v11]
          ^ crc_table[HIBYTE(v11)]
          ^ dword_482AE0[BYTE1(v11)]
          ^ dword_4826E0[BYTE2(v11)];
      v7 += 4;
      v13 = *((_DWORD *)v7 - 1)
          ^ dword_482EE0[(unsigned __int8)v12]
          ^ crc_table[HIBYTE(v12)]
          ^ dword_482AE0[BYTE1(v12)]
          ^ dword_4826E0[BYTE2(v12)];
      a3 = v7 + 4;
      v3 -= 32;
      v14 = *((_DWORD *)a3 - 1)
          ^ dword_482EE0[(unsigned __int8)v13]
          ^ crc_table[HIBYTE(v13)]
          ^ dword_482AE0[BYTE1(v13)]
          ^ dword_4826E0[BYTE2(v13)];
      i = dword_482EE0[(unsigned __int8)v14]
        ^ crc_table[HIBYTE(v14)]
        ^ dword_482AE0[BYTE1(v14)]
        ^ dword_4826E0[BYTE2(v14)];
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( v3 >= 4 )
  {
    v15 = v3 >> 2;
    do
    {
      v16 = *(_DWORD *)a3 ^ i;
      a3 += 4;
      v3 -= 4;
      --v15;
      i = dword_482EE0[(unsigned __int8)v16]
        ^ crc_table[HIBYTE(v16)]
        ^ dword_482AE0[BYTE1(v16)]
        ^ dword_4826E0[BYTE2(v16)];
    }
    while ( v15 != 0 );
  }
  for ( ; v3 != 0; --v3 )
    i = crc_table[(unsigned __int8)(i ^ *a3++)] ^ (i >> 8);
  return ~i;
}

//------------------------------------------------------------------------------
// Address: 0x00454340
// Name: _crc32
// Source: json
//------------------------------------------------------------------------------
int __cdecl crc32(int a1, _BYTE *a2, unsigned int a3)
{
  if ( a2 != nullptr )
    return crc32_little(a1, a2: a3, a3: a2);
  else
    return 0;
}
