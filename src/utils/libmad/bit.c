// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/bit.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051A360
// Name: _mad_bit_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_bit_init(mad_bitptr *bitptr, const unsigned __int8 *byte)
{
  bitptr->byte = byte;
  *(_DWORD *)&bitptr->cache = 0x80000;
}

//------------------------------------------------------------------------------
// Address: 0x0051A380
// Name: _mad_bit_length
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_bit_length(const mad_bitptr *begin, const mad_bitptr *end)
{
  return begin->left + 8 * (end->byte - begin->byte) - end->left;
}

//------------------------------------------------------------------------------
// Address: 0x0051A3B0
// Name: _mad_bit_nextbyte
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__cdecl mad_bit_nextbyte(const mad_bitptr *bitptr)
{
  const unsigned __int8 *result; // eax

  result = bitptr->byte;
  if ( bitptr->left != 8 )
    ++result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051A3D0
// Name: _mad_bit_skip
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_bit_skip(mad_bitptr *bitptr, unsigned int len)
{
  unsigned int left; // ecx

  bitptr->left -= len & 7;
  left = bitptr->left;
  bitptr->byte += len >> 3;
  if ( left > 8 )
  {
    ++bitptr->byte;
    bitptr->left = left + 8;
  }
  if ( bitptr->left < 8u )
    bitptr->cache = *bitptr->byte;
}

//------------------------------------------------------------------------------
// Address: 0x0051A410
// Name: _mad_bit_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_bit_read(mad_bitptr *bitptr, unsigned int len)
{
  unsigned int left; // esi
  int result; // eax
  int cache; // eax
  unsigned int v5; // ebx
  int v6; // esi
  const unsigned __int8 *byte; // eax
  unsigned int v8; // ecx
  int v9; // edi
  unsigned int v10; // eax

  left = bitptr->left;
  if ( left == 8 )
    bitptr->cache = *bitptr->byte;
  if ( len >= left )
  {
    cache = bitptr->cache;
    ++bitptr->byte;
    v5 = len - left;
    bitptr->left = 8;
    v6 = cache & ((1 << left) - 1);
    byte = bitptr->byte;
    if ( v5 >= 8 )
    {
      v8 = v5 >> 3;
      do
      {
        v9 = *byte++;
        v6 = v9 | (v6 << 8);
        v5 -= 8;
        --v8;
        bitptr->byte = byte;
      }
      while ( v8 != 0 );
    }
    if ( v5 != 0 )
    {
      v10 = *byte;
      bitptr->cache = v10;
      v6 = (v10 >> (8 - v5)) | (v6 << v5);
      bitptr->left = 8 - v5;
    }
    return v6;
  }
  else
  {
    result = (bitptr->cache & ((1 << left) - 1)) >> (left - len);
    bitptr->left = left - len;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051A4C0
// Name: _mad_bit_crc
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl mad_bit_crc(mad_bitptr bitptr, unsigned int len, unsigned __int16 init)
{
  unsigned int v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax

  v3 = init;
  v4 = len;
  if ( len >= 0x20 )
  {
    v5 = len >> 5;
    do
    {
      v6 = mad_bit_read(&bitptr, len: 0x20u);
      v7 = (v3 << 8) ^ crc_table[(unsigned __int8)((unsigned __int16)(v3 ^ HIWORD(v6)) >> 8)];
      v8 = (v7 << 8) ^ crc_table[(unsigned __int8)((unsigned __int16)(v7 ^ (v6 >> 8)) >> 8)];
      v3 = (((v8 << 8) ^ crc_table[(unsigned __int8)((unsigned __int16)(v8 ^ v6) >> 8)]) << 8)
         ^ crc_table[(unsigned __int8)(v6
                                     ^ ((unsigned __int16)(((_WORD)v8 << 8)
                                                         ^ crc_table[(unsigned __int8)((unsigned __int16)(v8 ^ v6) >> 8)]) >> 8))];
      v4 -= 32;
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( v4 >> 3 != 1 )
  {
    if ( v4 >> 3 != 2 )
    {
      if ( v4 >> 3 != 3 )
        goto LABEL_10;
      v3 = crc_table[(unsigned __int8)(BYTE1(v3) ^ mad_bit_read(&bitptr, len: 8u))] ^ (v3 << 8);
    }
    v3 = crc_table[(unsigned __int8)(BYTE1(v3) ^ mad_bit_read(&bitptr, len: 8u))] ^ (v3 << 8);
  }
  v3 = crc_table[(unsigned __int8)(BYTE1(v3) ^ mad_bit_read(&bitptr, len: 8u))] ^ (v3 << 8);
  v4 &= 7u;
LABEL_10:
  while ( v4 != 0 )
  {
    --v4;
    v9 = (v3 >> 15) ^ mad_bit_read(&bitptr, len: 1u);
    v3 *= 2;
    if ( (v9 & 1) != 0 )
      v3 ^= 0x8005u;
  }
  return v3;
}
