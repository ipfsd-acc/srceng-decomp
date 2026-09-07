// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/deflate.c
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0044DEC0
// Name: putShortMSB
// Source: json
//------------------------------------------------------------------------------
int __usercall putShortMSB@<eax>(int result@<eax>, __int16 a2@<cx>)
{
  int v2; // edi

  *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = HIBYTE(a2);
  v2 = *(_DWORD *)(result + 8);
  *(_BYTE *)(++*(_DWORD *)(result + 20) + v2) = a2;
  ++*(_DWORD *)(result + 20);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044DEF0
// Name: flush_pending
// Source: json
//------------------------------------------------------------------------------
int __usercall flush_pending@<eax>(int a1@<eax>)
{
  int result; // eax
  unsigned int v3; // edi
  int v4; // eax
  _DWORD *v5; // esi

  result = *(_DWORD *)(a1 + 28);
  v3 = *(_DWORD *)(result + 20);
  if ( v3 > *(_DWORD *)(a1 + 16) )
    v3 = *(_DWORD *)(a1 + 16);
  if ( v3 != 0 )
  {
    memcpy(dst: *(unsigned __int8 **)(a1 + 12), src: *(unsigned __int8 **)(result + 16), count: v3);
    v4 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 12) += v3;
    *(_DWORD *)(v4 + 16) += v3;
    *(_DWORD *)(a1 + 20) += v3;
    *(_DWORD *)(a1 + 16) -= v3;
    result = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(result + 20) -= v3;
    v5 = *(_DWORD **)(a1 + 28);
    if ( v5[5] == 0 )
      v5[4] = v5[2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044DF40
// Name: _deflate
// Source: json
//------------------------------------------------------------------------------
int __usercall deflate@<eax>(__int128 a1@<xmm0>, int a2, unsigned int a3)
{
  int *v4; // esi
  int v5; // eax
  signed int v7; // edx
  _DWORD *v8; // eax
  int v9; // ebp
  int v10; // eax
  char v11; // al
  int v12; // eax
  char v13; // al
  int v14; // eax
  int v15; // ecx
  int v16; // ebp
  int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // ebx
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // eax
  int v32; // ecx
  int v33; // ebx
  unsigned int v34; // eax
  int v35; // eax
  int v36; // ebx
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  signed int v42; // [esp+Ch] [ebp+4h]

  if ( a2 == 0 )
    return -2;
  v4 = *(int **)(a2 + 28);
  if ( v4 == nullptr || a3 > 4 )
    return -2;
  if ( *(_DWORD *)(a2 + 12) == 0 || *(_DWORD *)a2 == 0 && *(_DWORD *)(a2 + 4) != 0 || (v5 = v4[1]) == 666 && a3 != 4 )
  {
    *(_DWORD *)(a2 + 24) = "stream error";
    return -2;
  }
  if ( *(_DWORD *)(a2 + 16) == 0 )
  {
    *(_DWORD *)(a2 + 24) = "buffer error";
    return -5;
  }
  v7 = v4[10];
  *v4 = a2;
  v42 = v7;
  v4[10] = a3;
  if ( v5 == 42 )
  {
    if ( v4[6] == 2 )
    {
      *(_DWORD *)(a2 + 48) = crc32(a1: 0, a2: 0, a3: 0);
      *(_BYTE *)(v4[2] + v4[5]++) = 31;
      *(_BYTE *)(v4[5] + v4[2]) = -117;
      *(_BYTE *)(++v4[5] + v4[2]) = 8;
      ++v4[5];
      v8 = (_DWORD *)v4[7];
      v9 = v4[5];
      if ( v8 != nullptr )
      {
        *(_BYTE *)(v4[2] + v9) = (*v8 != 0)
                               + (v8[4] != 0 ? 4 : 0)
                               + (v8[7] != 0 ? 8 : 0)
                               + (v8[11] != 0 ? 2 : 0)
                               + (v8[9] != 0 ? 0x10 : 0);
        *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(v4[7] + 4);
        *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(v4[7] + 5);
        *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(v4[7] + 6);
        *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(v4[7] + 7);
        ++v4[5];
        v12 = v4[33];
        if ( v12 == 9 )
        {
          v13 = 2;
        }
        else if ( v4[34] >= 2 || v12 < 2 )
        {
          v13 = 4;
        }
        else
        {
          v13 = 0;
        }
        *(_BYTE *)(v4[5] + v4[2]) = v13;
        *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(v4[7] + 12);
        ++v4[5];
        v14 = v4[7];
        v15 = v4[5];
        if ( *(_DWORD *)(v14 + 16) != 0 )
        {
          *(_BYTE *)(v15 + v4[2]) = *(_BYTE *)(v14 + 20);
          *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(v4[7] + 21);
          v15 = ++v4[5];
        }
        if ( *(_DWORD *)(v4[7] + 44) != 0 )
          *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v4[2], a3: v15);
        v4[8] = 0;
        v4[1] = 69;
      }
      else
      {
        *(_BYTE *)(v4[2] + v9) = 0;
        *(_BYTE *)(++v4[5] + v4[2]) = 0;
        *(_BYTE *)(++v4[5] + v4[2]) = 0;
        *(_BYTE *)(++v4[5] + v4[2]) = 0;
        *(_BYTE *)(++v4[5] + v4[2]) = 0;
        ++v4[5];
        v10 = v4[33];
        if ( v10 == 9 )
        {
          v11 = 2;
        }
        else if ( v4[34] >= 2 || v10 < 2 )
        {
          v11 = 4;
        }
        else
        {
          v11 = 0;
        }
        *(_BYTE *)(v4[5] + v4[2]) = v11;
        *(_BYTE *)(++v4[5] + v4[2]) = 11;
        ++v4[5];
        v4[1] = 113;
      }
    }
    else
    {
      if ( v4[34] >= 2 || (v16 = v4[33]) < 2 )
      {
        v17 = 0;
      }
      else if ( v16 >= 6 )
      {
        v17 = (v16 != 6) + 2;
      }
      else
      {
        v17 = 1;
      }
      v18 = (v17 << 6) | (((v4[12] - 8) << 12) + 2048);
      if ( v4[27] != 0 )
        v18 |= 0x20u;
      v4[1] = 113;
      v19 = putShortMSB(result: (int)v4, a2: 31 * (v18 / 0x1F + 1));
      if ( v4[27] != 0 )
      {
        v20 = putShortMSB(result: v19, a2: *(_WORD *)(a2 + 50));
        putShortMSB(result: v20, a2: *(_WORD *)(a2 + 48));
      }
      *(_DWORD *)(a2 + 48) = adler32(a1: 0, a2: 0, a3: 0);
    }
  }
  if ( v4[1] == 69 )
  {
    v21 = v4[7];
    if ( *(_DWORD *)(v21 + 16) == 0 )
    {
LABEL_57:
      v4[1] = 73;
      goto LABEL_58;
    }
    v22 = v4[5];
    if ( v4[8] < (unsigned int)*(unsigned __int16 *)(v21 + 20) )
    {
      do
      {
        v23 = v4[5];
        if ( v23 == v4[3] )
        {
          if ( *(_DWORD *)(v4[7] + 44) != 0 && v23 > v22 )
            *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v22 + v4[2], a3: v23 - v22);
          flush_pending(a1: a2);
          v23 = v4[5];
          v22 = v23;
          if ( v23 == v4[3] )
            break;
        }
        *(_BYTE *)(v23 + v4[2]) = *(_BYTE *)(*(_DWORD *)(v4[7] + 16) + v4[8]);
        ++v4[5];
        ++v4[8];
      }
      while ( v4[8] < (unsigned int)*(unsigned __int16 *)(v4[7] + 20) );
    }
    if ( *(_DWORD *)(v4[7] + 44) != 0 )
    {
      v24 = v4[5];
      if ( v24 > v22 )
        *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v22 + v4[2], a3: v24 - v22);
    }
    if ( v4[8] == *(_DWORD *)(v4[7] + 20) )
    {
      v4[8] = 0;
      goto LABEL_57;
    }
  }
LABEL_58:
  if ( v4[1] == 73 )
  {
    if ( *(_DWORD *)(v4[7] + 28) == 0 )
    {
LABEL_74:
      v4[1] = 91;
      goto LABEL_75;
    }
    v25 = v4[5];
    while ( 1 )
    {
      v26 = v4[5];
      if ( v26 == v4[3] )
      {
        if ( *(_DWORD *)(v4[7] + 44) != 0 && v26 > v25 )
          *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v25 + v4[2], a3: v26 - v25);
        flush_pending(a1: a2);
        v26 = v4[5];
        v25 = v26;
        if ( v26 == v4[3] )
          break;
      }
      v27 = v4[8];
      v28 = *(unsigned __int8 *)(*(_DWORD *)(v4[7] + 28) + v27);
      v4[8] = v27 + 1;
      *(_BYTE *)(v26 + v4[2]) = v28;
      ++v4[5];
      if ( v28 == 0 )
        goto LABEL_69;
    }
    v28 = 1;
LABEL_69:
    if ( *(_DWORD *)(v4[7] + 44) != 0 )
    {
      v29 = v4[5];
      if ( v29 > v25 )
        *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v25 + v4[2], a3: v29 - v25);
    }
    if ( v28 == 0 )
    {
      v4[8] = 0;
      goto LABEL_74;
    }
  }
LABEL_75:
  if ( v4[1] == 91 )
  {
    if ( *(_DWORD *)(v4[7] + 36) == 0 )
      goto LABEL_90;
    v30 = v4[5];
    while ( 1 )
    {
      v31 = v4[5];
      if ( v31 == v4[3] )
      {
        if ( *(_DWORD *)(v4[7] + 44) != 0 && v31 > v30 )
          *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v30 + v4[2], a3: v31 - v30);
        flush_pending(a1: a2);
        v31 = v4[5];
        v30 = v31;
        if ( v31 == v4[3] )
          break;
      }
      v32 = v4[8];
      v33 = *(unsigned __int8 *)(*(_DWORD *)(v4[7] + 36) + v32);
      v4[8] = v32 + 1;
      *(_BYTE *)(v31 + v4[2]) = v33;
      ++v4[5];
      if ( v33 == 0 )
        goto LABEL_86;
    }
    v33 = 1;
LABEL_86:
    if ( *(_DWORD *)(v4[7] + 44) != 0 )
    {
      v34 = v4[5];
      if ( v34 > v30 )
        *(_DWORD *)(a2 + 48) = crc32(a1: *(_DWORD *)(a2 + 48), a2: v30 + v4[2], a3: v34 - v30);
    }
    if ( v33 == 0 )
LABEL_90:
      v4[1] = 103;
  }
  if ( v4[1] == 103 )
  {
    if ( *(_DWORD *)(v4[7] + 44) == 0 )
    {
LABEL_97:
      v4[1] = 113;
      goto LABEL_98;
    }
    if ( v4[5] + 2 > (unsigned int)v4[3] )
      flush_pending(a1: a2);
    v35 = v4[5];
    if ( v35 + 2 <= (unsigned int)v4[3] )
    {
      *(_BYTE *)(v35 + v4[2]) = *(_BYTE *)(a2 + 48);
      *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 49);
      ++v4[5];
      *(_DWORD *)(a2 + 48) = crc32(a1: 0, a2: 0, a3: 0);
      goto LABEL_97;
    }
  }
LABEL_98:
  if ( v4[5] != 0 )
  {
    flush_pending(a1: a2);
    if ( *(_DWORD *)(a2 + 16) == 0 )
    {
LABEL_100:
      v4[10] = -1;
      return 0;
    }
    v36 = a3;
  }
  else
  {
    v36 = a3;
    if ( *(_DWORD *)(a2 + 4) == 0 && (int)a3 <= v42 && a3 != 4 )
    {
      *(_DWORD *)(a2 + 24) = "buffer error";
      return -5;
    }
  }
  v37 = v4[1];
  if ( v37 == 666 )
  {
    if ( *(_DWORD *)(a2 + 4) != 0 )
    {
      *(_DWORD *)(a2 + 24) = "buffer error";
      return -5;
    }
LABEL_111:
    if ( v4[29] == 0 && (v36 == 0 || v37 == 666) )
      goto LABEL_125;
    goto LABEL_114;
  }
  if ( *(_DWORD *)(a2 + 4) == 0 )
    goto LABEL_111;
LABEL_114:
  v38 = funcs_44E59B[3 * v4[33]](a1: (int)v4, a2: v36);
  if ( v38 == 2 || v38 == 3 )
    v4[1] = 666;
  if ( v38 == 0 || v38 == 2 )
  {
    if ( *(_DWORD *)(a2 + 16) != 0 )
      return 0;
    v4[10] = -1;
    return 0;
  }
  if ( v38 == 1 )
  {
    if ( v36 == 1 )
    {
      _tr_align(a1: v4);
    }
    else
    {
      _tr_stored_block(a1: v4, a2: 0, a3: 0, a4: 0);
      if ( v36 == 3 )
      {
        *(_WORD *)(v4[17] + 2 * v4[19] - 2) = 0;
        memset(a1, dst: v4[17], value: 0, count: 2 * v4[19] - 2);
      }
    }
    flush_pending(a1: a2);
    if ( *(_DWORD *)(a2 + 16) == 0 )
      goto LABEL_100;
  }
LABEL_125:
  if ( v36 != 4 )
    return 0;
  v39 = v4[6];
  if ( v39 <= 0 )
    return 1;
  if ( v39 == 2 )
  {
    *(_BYTE *)(v4[2] + v4[5]++) = *(_BYTE *)(a2 + 48);
    *(_BYTE *)(v4[5] + v4[2]) = *(_BYTE *)(a2 + 49);
    *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 50);
    *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 51);
    *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 8);
    *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 9);
    *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 10);
    *(_BYTE *)(++v4[5] + v4[2]) = *(_BYTE *)(a2 + 11);
    ++v4[5];
  }
  else
  {
    v40 = putShortMSB(result: (int)v4, a2: *(_WORD *)(a2 + 50));
    putShortMSB(result: v40, a2: *(_WORD *)(a2 + 48));
  }
  flush_pending(a1: a2);
  v41 = v4[6];
  if ( v41 > 0 )
    v4[6] = -v41;
  return v4[5] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044E720
// Name: _deflateEnd
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl deflateEnd(int a1)
{
  int v1; // eax
  int v2; // edi
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx

  if ( a1 == 0 )
    return -2;
  v1 = *(_DWORD *)(a1 + 28);
  if ( v1 == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 4);
  if ( v2 != 42 && v2 != 69 && v2 != 73 && v2 != 91 && v2 != 103 && v2 != 113 && v2 != 666 )
    return -2;
  v4 = *(_DWORD *)(v1 + 8);
  if ( v4 != 0 )
    (*(void (__cdecl **)(_DWORD, int))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
  v5 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v5 + 68) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v5 + 68));
  v6 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v6 + 64) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v6 + 64));
  v7 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v7 + 56) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v7 + 56));
  (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(a1 + 28));
  *(_DWORD *)(a1 + 28) = 0;
  return v2 != 113 ? 0 : 0xFFFFFFFD;
}

//------------------------------------------------------------------------------
// Address: 0x0044E7F0
// Name: read_buf
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall read_buf@<eax>(unsigned int a1@<ecx>, _DWORD *a2@<esi>, unsigned __int8 *dst)
{
  unsigned int v3; // edi
  int v5; // eax
  int v6; // eax

  v3 = a2[1];
  if ( v3 > a1 )
    v3 = a1;
  if ( v3 == 0 )
    return 0;
  a2[1] -= v3;
  v5 = *(_DWORD *)(a2[7] + 24);
  if ( v5 == 1 )
  {
    v6 = adler32(a1: a2[12], a2: *a2, a3: v3);
LABEL_9:
    a2[12] = v6;
    goto LABEL_10;
  }
  if ( v5 == 2 )
  {
    v6 = crc32(a1: a2[12], a2: *a2, a3: v3);
    goto LABEL_9;
  }
LABEL_10:
  memcpy(dst, src: (unsigned __int8 *)*a2, count: v3);
  *a2 += v3;
  a2[2] += v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0044E860
// Name: lm_init
// Source: json
//------------------------------------------------------------------------------
int __usercall lm_init@<eax>(_DWORD *a1@<esi>, __int128 a2@<xmm0>)
{
  int v2; // ecx
  int v3; // edx
  int v4; // eax
  int v5; // edx

  v2 = a1[19];
  v3 = a1[17];
  a1[15] = 2 * a1[11];
  *(_WORD *)(v3 + 2 * v2 - 2) = 0;
  memset(a1: a2, dst: a1[17], value: 0, count: 2 * a1[19] - 2);
  v4 = 6 * a1[33];
  a1[32] = (unsigned __int16)word_480B02[v4];
  a1[35] = (unsigned __int16)configuration_table[v4];
  a1[36] = (unsigned __int16)word_480B04[v4];
  v5 = (unsigned __int16)word_480B06[v4];
  a1[27] = 0;
  a1[23] = 0;
  a1[29] = 0;
  a1[26] = 0;
  a1[18] = 0;
  a1[31] = v5;
  a1[30] = 2;
  a1[24] = 2;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044E8F0
// Name: longest_match
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall longest_match@<eax>(unsigned int a1@<eax>, _DWORD *a2@<edi>)
{
  unsigned int v2; // edx
  unsigned int v3; // ebp
  int v4; // esi
  _BYTE *v5; // ecx
  _BYTE *v6; // esi
  _BYTE *v7; // edx
  char v8; // bl
  _BYTE *v9; // edx
  _BYTE *v10; // ecx
  _BYTE *v11; // edx
  char v12; // bl
  _BYTE *v13; // edx
  char v14; // bl
  _BYTE *v15; // edx
  char v16; // bl
  _BYTE *v17; // edx
  char v18; // bl
  _BYTE *v19; // edx
  char v20; // bl
  _BYTE *v21; // edx
  char v22; // bl
  _BYTE *v23; // edx
  char v24; // bl
  _BYTE *v25; // edx
  char v26; // bl
  int v27; // edx
  unsigned int result; // eax
  char v29; // [esp+Eh] [ebp-12h]
  char v30; // [esp+Fh] [ebp-11h]
  unsigned int v31; // [esp+10h] [ebp-10h]
  int v32; // [esp+14h] [ebp-Ch]
  unsigned int v33; // [esp+18h] [ebp-8h]

  v2 = a2[27];
  v3 = a2[30];
  v31 = a2[31];
  v32 = a2[36];
  v4 = a2[11];
  v5 = (_BYTE *)(v2 + a2[14]);
  if ( v2 <= v4 - 262 )
    v33 = 0;
  else
    v33 = v2 - v4 + 262;
  v29 = v5[v3 - 1];
  v6 = v5 + 258;
  v30 = v5[v3];
  if ( v3 >= a2[35] )
    v31 >>= 2;
  if ( (unsigned int)v32 > a2[29] )
    v32 = a2[29];
  do
  {
    v7 = (_BYTE *)(a1 + a2[14]);
    if ( v7[v3] == v30 && v7[v3 - 1] == v29 && *v7 == *v5 )
    {
      v8 = v7[1];
      v9 = v7 + 1;
      if ( v8 == v5[1] )
      {
        v10 = v5 + 2;
        v11 = v9 + 1;
        do
        {
          v12 = *++v10;
          v13 = v11 + 1;
          if ( v12 != *v13 )
            break;
          v14 = *++v10;
          v15 = v13 + 1;
          if ( v14 != *v15 )
            break;
          v16 = *++v10;
          v17 = v15 + 1;
          if ( v16 != *v17 )
            break;
          v18 = *++v10;
          v19 = v17 + 1;
          if ( v18 != *v19 )
            break;
          v20 = *++v10;
          v21 = v19 + 1;
          if ( v20 != *v21 )
            break;
          v22 = *++v10;
          v23 = v21 + 1;
          if ( v22 != *v23 )
            break;
          v24 = *++v10;
          v25 = v23 + 1;
          if ( v24 != *v25 )
            break;
          v26 = *++v10;
          v11 = v25 + 1;
          if ( v26 != *v11 )
            break;
        }
        while ( v10 < v6 );
        v27 = v10 - v6 + 258;
        v5 = v6 - 258;
        if ( v27 > (int)v3 )
        {
          a2[28] = a1;
          v3 = v27;
          if ( v27 >= v32 )
            break;
          v29 = v5[v27 - 1];
          v30 = v5[v27];
        }
      }
    }
    a1 = *(unsigned __int16 *)(a2[16] + 2 * (a1 & a2[13]));
    if ( a1 <= v33 )
      break;
    --v31;
  }
  while ( v31 != 0 );
  result = a2[29];
  if ( v3 <= result )
    return v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044EA50
// Name: longest_match_fast
// Source: json
//------------------------------------------------------------------------------
int __usercall longest_match_fast@<eax>(_DWORD *a1@<esi>, int a2)
{
  int v2; // ecx
  char v3; // dl
  _BYTE *v4; // eax
  int v5; // ecx
  _BYTE *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ecx
  char v9; // dl
  _BYTE *v10; // ecx
  char v11; // dl
  _BYTE *v12; // ecx
  char v13; // dl
  _BYTE *v14; // ecx
  char v15; // dl
  _BYTE *v16; // ecx
  char v17; // dl
  _BYTE *v18; // ecx
  char v19; // dl
  _BYTE *v20; // ecx
  char v21; // dl
  _BYTE *v22; // ecx
  char v23; // dl
  int result; // eax
  unsigned int v25; // ecx

  v2 = a1[14];
  v3 = *(_BYTE *)(v2 + a2);
  v4 = (_BYTE *)(v2 + a1[27]);
  v5 = a2 + v2;
  v6 = v4 + 258;
  if ( v3 != *v4 || *(_BYTE *)(v5 + 1) != v4[1] )
    return 2;
  v7 = v4 + 2;
  v8 = (_BYTE *)(v5 + 2);
  do
  {
    v9 = *++v7;
    v10 = v8 + 1;
    if ( v9 != *v10 )
      break;
    v11 = *++v7;
    v12 = v10 + 1;
    if ( v11 != *v12 )
      break;
    v13 = *++v7;
    v14 = v12 + 1;
    if ( v13 != *v14 )
      break;
    v15 = *++v7;
    v16 = v14 + 1;
    if ( v15 != *v16 )
      break;
    v17 = *++v7;
    v18 = v16 + 1;
    if ( v17 != *v18 )
      break;
    v19 = *++v7;
    v20 = v18 + 1;
    if ( v19 != *v20 )
      break;
    v21 = *++v7;
    v22 = v20 + 1;
    if ( v21 != *v22 )
      break;
    v23 = *++v7;
    v8 = v22 + 1;
    if ( v23 != *v8 )
      break;
  }
  while ( v7 < v6 );
  result = v7 - v6 + 258;
  if ( result < 3 )
    return 2;
  v25 = a1[29];
  a1[28] = a2;
  if ( result > v25 )
    return v25;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044EAF0
// Name: fill_window
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall fill_window@<eax>(_DWORD **a1@<edi>)
{
  unsigned int v1; // ebx
  unsigned int result; // eax
  unsigned int v3; // ebp
  _DWORD *v4; // edx
  _DWORD *v5; // eax
  _WORD *v6; // ecx
  unsigned int v7; // eax
  __int16 v8; // ax
  unsigned int v9; // edx
  _WORD *v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned __int8 *v13; // esi
  _DWORD *v14; // eax
  _DWORD *v15; // ecx

  v1 = (unsigned int)a1[11];
  do
  {
    result = (unsigned int)a1[27];
    v3 = (char *)a1[15] - (char *)a1[29] - result;
    if ( result >= (unsigned int)a1[11] + v1 - 262 )
    {
      memcpy(dst: (unsigned __int8 *)a1[14], src: (unsigned __int8 *)a1[14] + v1, count: v1);
      v4 = a1[19];
      v5 = a1[17];
      a1[28] = (_DWORD *)((char *)a1[28] - v1);
      a1[27] = (_DWORD *)((char *)a1[27] - v1);
      a1[23] = (_DWORD *)((char *)a1[23] - v1);
      v6 = (_WORD *)v5 + (_DWORD)v4;
      do
      {
        v7 = (unsigned __int16)*--v6;
        if ( v7 < v1 )
          v8 = 0;
        else
          v8 = v7 - v1;
        v4 = (_DWORD *)((char *)v4 - 1);
        *v6 = v8;
      }
      while ( v4 != nullptr );
      v9 = v1;
      v10 = (_WORD *)a1[16] + v1;
      do
      {
        v11 = (unsigned __int16)*--v10;
        if ( v11 < v1 )
          result = 0;
        else
          result = v11 - v1;
        --v9;
        *v10 = result;
      }
      while ( v9 != 0 );
      v3 += v1;
    }
    if ( (*a1)[1] == 0 )
      break;
    result = read_buf(a1: v3, a2: *a1, dst: (unsigned __int8 *)a1[14] + (unsigned int)a1[29] + (_DWORD)a1[27]);
    a1[29] = (_DWORD *)((char *)a1[29] + result);
    v12 = (unsigned int)a1[29];
    if ( v12 >= 3 )
    {
      v13 = (unsigned __int8 *)a1[14] + (_DWORD)a1[27];
      v14 = (_DWORD *)*v13;
      v15 = a1[22];
      a1[18] = v14;
      result = (unsigned int)a1[21] & (v13[1] ^ ((_DWORD)v14 << (char)v15));
      a1[18] = (_DWORD *)result;
    }
  }
  while ( v12 < 0x106 && (*a1)[1] != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044EBD0
// Name: deflate_stored
// Source: json
//------------------------------------------------------------------------------
int __cdecl deflate_stored(int a1, int a2)
{
  int v2; // esi
  unsigned int v3; // eax
  bool v4; // zf
  int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // eax
  int v8; // edx
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  _DWORD *v12; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax

  v2 = 0xFFFF;
  if ( (unsigned int)(*(_DWORD *)(a1 + 12) - 5) < 0xFFFF )
    v2 = *(_DWORD *)(a1 + 12) - 5;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 116);
    if ( v3 <= 1 )
    {
      fill_window((_DWORD **)a1);
      v3 = *(_DWORD *)(a1 + 116);
      if ( v3 == 0 )
        break;
    }
    v4 = v3 + *(_DWORD *)(a1 + 108) == 0;
    *(_DWORD *)(a1 + 108) += v3;
    v5 = *(_DWORD *)(a1 + 92);
    v6 = *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a1 + 116) = 0;
    v7 = v5 + v2;
    if ( !v4 && v6 < v7
      || ((*(_DWORD *)(a1 + 116) = v6 - v7, *(_DWORD *)(a1 + 108) = v7, v5 < 0)
        ? (v8 = 0)
        : (v8 = v5 + *(_DWORD *)(a1 + 56)),
          _tr_flush_block(a1, a2: v8, a3: v2, a4: 0),
          *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108),
          flush_pending(a1: *(_DWORD *)a1),
          *(_DWORD *)(*(_DWORD *)a1 + 16) != 0) )
    {
      v9 = *(_DWORD *)(a1 + 92);
      v10 = *(_DWORD *)(a1 + 108) - v9;
      if ( v10 < *(_DWORD *)(a1 + 44) - 262 )
        continue;
      v11 = v9 < 0 ? 0 : v9 + *(_DWORD *)(a1 + 56);
      _tr_flush_block(a1, a2: v11, a3: v10, a4: 0);
      v12 = *(_DWORD **)a1;
      *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
      flush_pending(a1: (int)v12);
      if ( *(_DWORD *)(*(_DWORD *)a1 + 16) != 0 )
        continue;
    }
    return 0;
  }
  if ( a2 == 0 )
    return 0;
  v14 = *(_DWORD *)(a1 + 92);
  if ( v14 < 0 )
    v15 = 0;
  else
    v15 = v14 + *(_DWORD *)(a1 + 56);
  _tr_flush_block(a1, a2: v15, a3: *(_DWORD *)(a1 + 108) - v14, a4: a2 == 4);
  *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
  flush_pending(a1: *(_DWORD *)a1);
  v16 = 0;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v16) = a2 == 4;
  return 2 * v16 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044ED00
// Name: deflate_fast
// Source: json
//------------------------------------------------------------------------------
int __cdecl deflate_fast(int a1, int a2)
{
  unsigned int v2; // ebp
  unsigned int v3; // eax
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  unsigned int matched; // eax
  unsigned __int8 v11; // al
  __int16 v12; // cx
  unsigned __int16 v13; // cx
  int v14; // eax
  unsigned int v15; // eax
  BOOL v16; // ecx
  BOOL v17; // esi
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // ebp
  int v22; // edx
  unsigned __int8 *v24; // edx
  int v25; // ecx
  int v26; // eax
  unsigned __int8 v27; // al
  BOOL v28; // ecx
  int v29; // ecx
  int v30; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // eax

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 116);
    if ( v3 < 0x106 )
    {
      fill_window((_DWORD **)a1);
      v3 = *(_DWORD *)(a1 + 116);
      if ( v3 < 0x106 && a2 == 0 )
        return 0;
      if ( v3 == 0 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = *(_DWORD *)(a1 + 108);
      v5 = *(_DWORD *)(a1 + 52);
      v6 = *(_DWORD *)(a1 + 84)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 56) + v4 + 2)
          ^ (*(_DWORD *)(a1 + 72) << *(_DWORD *)(a1 + 88)));
      v7 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a1 + 72) = v6;
      *(_WORD *)(*(_DWORD *)(a1 + 64) + 2 * (v4 & v5)) = *(_WORD *)(v7 + 2 * v6);
      v2 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 64) + 2 * (*(_DWORD *)(a1 + 52) & *(_DWORD *)(a1 + 108)));
      *(_WORD *)(*(_DWORD *)(a1 + 68) + 2 * *(_DWORD *)(a1 + 72)) = *(_WORD *)(a1 + 108);
    }
    if ( v2 != 0 )
    {
      v8 = *(_DWORD *)(a1 + 108) - v2;
      if ( v8 <= *(_DWORD *)(a1 + 44) - 262 )
      {
        v9 = *(_DWORD *)(a1 + 136);
        if ( v9 != 2 )
        {
          if ( v9 == 3 )
          {
            if ( v8 != 1 )
              goto LABEL_17;
            matched = longest_match_fast((_DWORD *)a1, a2: v2);
          }
          else
          {
            matched = longest_match(a1: v2, a2: (_DWORD *)a1);
          }
          *(_DWORD *)(a1 + 96) = matched;
        }
      }
    }
LABEL_17:
    if ( *(_DWORD *)(a1 + 96) < 3u )
    {
      v27 = *(_BYTE *)(*(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 56));
      *(_WORD *)(*(_DWORD *)(a1 + 5796) + 2 * *(_DWORD *)(a1 + 5792)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5784) + (*(_DWORD *)(a1 + 5792))++) = v27;
      ++*(_WORD *)(a1 + 4 * v27 + 148);
      v28 = *(_DWORD *)(a1 + 5792) == *(_DWORD *)(a1 + 5788) - 1;
      --*(_DWORD *)(a1 + 116);
      v17 = v28;
    }
    else
    {
      v11 = *(_BYTE *)(a1 + 96);
      v12 = *(_WORD *)(a1 + 108) - *(_WORD *)(a1 + 112);
      *(_WORD *)(*(_DWORD *)(a1 + 5796) + 2 * *(_DWORD *)(a1 + 5792)) = v12;
      v11 -= 3;
      *(_BYTE *)(*(_DWORD *)(a1 + 5784) + (*(_DWORD *)(a1 + 5792))++) = v11;
      ++*(_WORD *)(a1 + 4 * _length_code[v11] + 1176);
      v13 = v12 - 1;
      if ( v13 >= 0x100u )
        v14 = (unsigned __int8)byte_481FF0[v13 >> 7];
      else
        v14 = (unsigned __int8)_dist_code[v13];
      ++*(_WORD *)(a1 + 4 * v14 + 2440);
      v15 = *(_DWORD *)(a1 + 96);
      v16 = *(_DWORD *)(a1 + 5792) == *(_DWORD *)(a1 + 5788) - 1;
      *(_DWORD *)(a1 + 116) -= v15;
      v17 = v16;
      if ( v15 > *(_DWORD *)(a1 + 128) || *(_DWORD *)(a1 + 116) < 3u )
      {
        *(_DWORD *)(a1 + 108) += v15;
        v24 = (unsigned __int8 *)(*(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 56));
        v25 = *(_DWORD *)(a1 + 88);
        *(_DWORD *)(a1 + 96) = 0;
        v26 = *v24;
        *(_DWORD *)(a1 + 72) = v26;
        *(_DWORD *)(a1 + 72) = *(_DWORD *)(a1 + 84) & (v24[1] ^ (v26 << v25));
        goto LABEL_29;
      }
      *(_DWORD *)(a1 + 96) = v15 - 1;
      do
      {
        v18 = ++*(_DWORD *)(a1 + 108);
        v19 = *(_DWORD *)(a1 + 68);
        v20 = *(_DWORD *)(a1 + 84)
            & ((*(_DWORD *)(a1 + 72) << *(_DWORD *)(a1 + 88))
             ^ *(unsigned __int8 *)(v18 + *(_DWORD *)(a1 + 56) + 2));
        v21 = v18 & *(_DWORD *)(a1 + 52);
        v22 = *(_DWORD *)(a1 + 64);
        *(_DWORD *)(a1 + 72) = v20;
        *(_WORD *)(v22 + 2 * v21) = *(_WORD *)(v19 + 2 * v20);
        v2 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 64) + 2 * (*(_DWORD *)(a1 + 52) & *(_DWORD *)(a1 + 108)));
        *(_WORD *)(*(_DWORD *)(a1 + 68) + 2 * *(_DWORD *)(a1 + 72)) = *(_WORD *)(a1 + 108);
      }
      while ( (*(_DWORD *)(a1 + 96))-- != 1 );
    }
    ++*(_DWORD *)(a1 + 108);
LABEL_29:
    if ( v17 )
    {
      v29 = *(_DWORD *)(a1 + 92);
      v30 = v29 < 0 ? 0 : v29 + *(_DWORD *)(a1 + 56);
      _tr_flush_block(a1, a2: v30, a3: *(_DWORD *)(a1 + 108) - v29, a4: 0);
      *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
      flush_pending(a1: *(_DWORD *)a1);
      if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
        return 0;
    }
  }
  v32 = *(_DWORD *)(a1 + 92);
  if ( v32 < 0 )
    v33 = 0;
  else
    v33 = v32 + *(_DWORD *)(a1 + 56);
  _tr_flush_block(a1, a2: v33, a3: *(_DWORD *)(a1 + 108) - v32, a4: a2 == 4);
  *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
  flush_pending(a1: *(_DWORD *)a1);
  v34 = 0;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v34) = a2 == 4;
  return 2 * v34 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044F020
// Name: deflate_slow
// Source: json
//------------------------------------------------------------------------------
int __cdecl deflate_slow(int a1, int a2)
{
  unsigned int v2; // eax
  int v3; // edx
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  unsigned int matched; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned __int8 v14; // al
  __int16 v15; // cx
  unsigned __int16 v16; // cx
  int v17; // eax
  int v18; // eax
  BOOL v19; // ebx
  unsigned int v20; // edx
  int v21; // ebp
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  _DWORD *v27; // eax
  bool v28; // zf
  unsigned __int8 v30; // al
  int v31; // ecx
  int v32; // eax
  _DWORD *v33; // ecx
  unsigned __int8 v34; // al
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  unsigned int v38; // [esp+10h] [ebp-4h]

  v38 = 0;
  while ( 1 )
  {
    v2 = *(_DWORD *)(a1 + 116);
    if ( v2 < 0x106 )
    {
      fill_window((_DWORD **)a1);
      v2 = *(_DWORD *)(a1 + 116);
      if ( v2 < 0x106 && a2 == 0 )
        return 0;
      if ( v2 == 0 )
        break;
    }
    if ( v2 >= 3 )
    {
      v3 = *(_DWORD *)(a1 + 108);
      v4 = *(_DWORD *)(a1 + 52);
      v5 = *(_DWORD *)(a1 + 84)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 56) + v3 + 2)
          ^ (*(_DWORD *)(a1 + 72) << *(_DWORD *)(a1 + 88)));
      v6 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a1 + 72) = v5;
      *(_WORD *)(*(_DWORD *)(a1 + 64) + 2 * (v3 & v4)) = *(_WORD *)(v6 + 2 * v5);
      v38 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 64) + 2 * (*(_DWORD *)(a1 + 52) & *(_DWORD *)(a1 + 108)));
      *(_WORD *)(*(_DWORD *)(a1 + 68) + 2 * *(_DWORD *)(a1 + 72)) = *(_WORD *)(a1 + 108);
    }
    v7 = *(_DWORD *)(a1 + 96);
    *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 112);
    *(_DWORD *)(a1 + 120) = v7;
    *(_DWORD *)(a1 + 96) = 2;
    if ( v38 == 0 )
      goto LABEL_23;
    if ( v7 >= *(_DWORD *)(a1 + 128) )
      goto LABEL_23;
    v8 = *(_DWORD *)(a1 + 108) - v38;
    if ( v8 <= *(_DWORD *)(a1 + 44) - 262 )
    {
      v9 = *(_DWORD *)(a1 + 136);
      if ( v9 != 2 )
      {
        if ( v9 != 3 )
        {
          matched = longest_match(a1: v38, a2: (_DWORD *)a1);
LABEL_17:
          *(_DWORD *)(a1 + 96) = matched;
          goto LABEL_18;
        }
        if ( v8 == 1 )
        {
          matched = longest_match_fast((_DWORD *)a1, a2: v38);
          goto LABEL_17;
        }
      }
LABEL_18:
      v11 = *(_DWORD *)(a1 + 96);
      if ( v11 <= 5
        && (*(_DWORD *)(a1 + 136) == 1
         || v11 == 3 && (unsigned int)(*(_DWORD *)(a1 + 108) - *(_DWORD *)(a1 + 112)) > 0x1000) )
      {
        *(_DWORD *)(a1 + 96) = 2;
      }
    }
LABEL_23:
    v12 = *(_DWORD *)(a1 + 120);
    if ( v12 < 3 || *(_DWORD *)(a1 + 96) > v12 )
    {
      if ( *(_DWORD *)(a1 + 104) != 0 )
      {
        v30 = *(_BYTE *)(*(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 56) - 1);
        *(_WORD *)(*(_DWORD *)(a1 + 5796) + 2 * *(_DWORD *)(a1 + 5792)) = 0;
        *(_BYTE *)(*(_DWORD *)(a1 + 5784) + (*(_DWORD *)(a1 + 5792))++) = v30;
        ++*(_WORD *)(a1 + 4 * v30 + 148);
        if ( *(_DWORD *)(a1 + 5792) == *(_DWORD *)(a1 + 5788) - 1 )
        {
          v31 = *(_DWORD *)(a1 + 92);
          if ( v31 < 0 )
            v32 = 0;
          else
            v32 = v31 + *(_DWORD *)(a1 + 56);
          _tr_flush_block(a1, a2: v32, a3: *(_DWORD *)(a1 + 108) - v31, a4: 0);
          *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
          flush_pending(a1: *(_DWORD *)a1);
        }
        v33 = *(_DWORD **)a1;
        ++*(_DWORD *)(a1 + 108);
        --*(_DWORD *)(a1 + 116);
        v28 = v33[4] == 0;
        goto LABEL_37;
      }
      ++*(_DWORD *)(a1 + 108);
      --*(_DWORD *)(a1 + 116);
      *(_DWORD *)(a1 + 104) = 1;
    }
    else
    {
      v13 = *(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 116) - 3;
      v14 = *(_BYTE *)(a1 + 120);
      v15 = *(_WORD *)(a1 + 108) - *(_WORD *)(a1 + 100) - 1;
      *(_WORD *)(*(_DWORD *)(a1 + 5796) + 2 * *(_DWORD *)(a1 + 5792)) = v15;
      v14 -= 3;
      *(_BYTE *)(*(_DWORD *)(a1 + 5784) + (*(_DWORD *)(a1 + 5792))++) = v14;
      ++*(_WORD *)(a1 + 4 * _length_code[v14] + 1176);
      v16 = v15 - 1;
      if ( v16 >= 0x100u )
        v17 = (unsigned __int8)byte_481FF0[v16 >> 7];
      else
        v17 = (unsigned __int8)_dist_code[v16];
      ++*(_WORD *)(a1 + 4 * v17 + 2440);
      v18 = *(_DWORD *)(a1 + 120);
      v19 = *(_DWORD *)(a1 + 5792) == *(_DWORD *)(a1 + 5788) - 1;
      *(_DWORD *)(a1 + 116) += 1 - v18;
      *(_DWORD *)(a1 + 120) = v18 - 2;
      do
      {
        v20 = ++*(_DWORD *)(a1 + 108);
        if ( v20 <= v13 )
        {
          v21 = *(_DWORD *)(a1 + 52);
          v22 = *(_DWORD *)(a1 + 84)
              & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 56) + v20 + 2)
               ^ (*(_DWORD *)(a1 + 72) << *(_DWORD *)(a1 + 88)));
          v23 = *(_DWORD *)(a1 + 68);
          *(_DWORD *)(a1 + 72) = v22;
          *(_WORD *)(*(_DWORD *)(a1 + 64) + 2 * (v20 & v21)) = *(_WORD *)(v23 + 2 * v22);
          v38 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 64) + 2 * (*(_DWORD *)(a1 + 52) & *(_DWORD *)(a1 + 108)));
          *(_WORD *)(*(_DWORD *)(a1 + 68) + 2 * *(_DWORD *)(a1 + 72)) = *(_WORD *)(a1 + 108);
        }
        v28 = (*(_DWORD *)(a1 + 120))-- == 1;
      }
      while ( !v28 );
      v24 = ++*(_DWORD *)(a1 + 108);
      *(_DWORD *)(a1 + 104) = 0;
      *(_DWORD *)(a1 + 96) = 2;
      if ( v19 )
      {
        v25 = *(_DWORD *)(a1 + 92);
        if ( v25 < 0 )
          v26 = 0;
        else
          v26 = v25 + *(_DWORD *)(a1 + 56);
        _tr_flush_block(a1, a2: v26, a3: v24 - v25, a4: 0);
        v27 = *(_DWORD **)a1;
        *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
        flush_pending(a1: (int)v27);
        v28 = *(_DWORD *)(*(_DWORD *)a1 + 16) == 0;
LABEL_37:
        if ( v28 )
          return 0;
      }
    }
  }
  if ( *(_DWORD *)(a1 + 104) != 0 )
  {
    v34 = *(_BYTE *)(*(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 56) - 1);
    *(_WORD *)(*(_DWORD *)(a1 + 5796) + 2 * *(_DWORD *)(a1 + 5792)) = 0;
    *(_BYTE *)(*(_DWORD *)(a1 + 5784) + (*(_DWORD *)(a1 + 5792))++) = v34;
    ++*(_WORD *)(a1 + 4 * v34 + 148);
    *(_DWORD *)(a1 + 104) = 0;
  }
  v35 = *(_DWORD *)(a1 + 92);
  if ( v35 < 0 )
    v36 = 0;
  else
    v36 = v35 + *(_DWORD *)(a1 + 56);
  _tr_flush_block(a1, a2: v36, a3: *(_DWORD *)(a1 + 108) - v35, a4: a2 == 4);
  *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 108);
  flush_pending(a1: *(_DWORD *)a1);
  v37 = 0;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v37) = a2 == 4;
  return 2 * v37 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044F420
// Name: _deflateReset
// Source: json
//------------------------------------------------------------------------------
int __usercall deflateReset@<eax>(__int128 a1@<xmm0>, _DWORD *a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax

  if ( a2 == nullptr )
    return -2;
  v2 = (_DWORD *)a2[7];
  if ( v2 == nullptr || a2[8] == 0 || a2[9] == 0 )
    return -2;
  a2[5] = 0;
  a2[2] = 0;
  a2[6] = 0;
  a2[11] = 2;
  v2[4] = v2[2];
  v3 = v2[6];
  v2[5] = 0;
  if ( v3 < 0 )
    v2[6] = -v3;
  v4 = v2[6];
  v2[1] = v4 != 0 ? 42 : 113;
  if ( v4 == 2 )
    v5 = crc32(a1: 0, a2: 0, a3: 0);
  else
    v5 = adler32(a1: 0, a2: 0, a3: 0);
  a2[12] = v5;
  v2[10] = 0;
  _tr_init(a1: v2);
  lm_init(a1: v2, a2: a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044F4B0
// Name: _deflateInit2_
// Source: json
//------------------------------------------------------------------------------
int __usercall deflateInit2_@<eax>(
        __int128 a1@<xmm0>,
        _DWORD *a2,
        unsigned int a3,
        int a4,
        int a5,
        int a6,
        unsigned int a7,
        _BYTE *a8,
        int a9)
{
  int v9; // ebp
  int v11; // ebx
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // ecx
  bool v21; // zf

  v9 = 1;
  if ( a8 == nullptr || *a8 != 49 || a9 != 56 )
    return -6;
  if ( a2 == nullptr )
    return -2;
  a2[6] = 0;
  if ( a2[8] == 0 )
  {
    a2[8] = zcalloc;
    a2[10] = 0;
  }
  if ( a2[9] == 0 )
    a2[9] = zcfree;
  if ( a3 == -1 )
    a3 = 6;
  v11 = a5;
  if ( a5 >= 0 )
  {
    if ( a5 > 15 )
    {
      v9 = 2;
      v11 = a5 - 16;
    }
  }
  else
  {
    v9 = 0;
    v11 = -a5;
  }
  if ( (unsigned int)(a6 - 1) > 8 || a4 != 8 || (unsigned int)(v11 - 8) > 7 || a3 > 9 || a7 > 4 )
    return -2;
  if ( v11 == 8 )
    v11 = 9;
  v12 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a2[8])(a1: a2[10], a2: 1, a3: 5824);
  v13 = v12;
  if ( v12 != nullptr )
  {
    a2[7] = v12;
    v12[6] = v9;
    v12[12] = v11;
    v12[13] = (1 << v11) - 1;
    v14 = 1 << (a6 + 7);
    v13[20] = a6 + 7;
    *v13 = a2;
    v13[19] = v14;
    v13[21] = v14 - 1;
    v13[7] = 0;
    v13[11] = 1 << v11;
    v13[22] = (a6 + 9) / 3u;
    v15 = ((int (__cdecl *)(_DWORD, int, int))a2[8])(a1: a2[10], a2: 1 << v11, a3: 2);
    v16 = v13[11];
    v13[14] = v15;
    v17 = ((int (__cdecl *)(_DWORD, int, int))a2[8])(a1: a2[10], a2: v16, a3: 2);
    v18 = v13[19];
    v13[16] = v17;
    v13[17] = ((int (__cdecl *)(_DWORD, int, int))a2[8])(a1: a2[10], a2: v18, a3: 2);
    v13[1447] = 1 << (a6 + 6);
    v19 = ((int (__cdecl *)(_DWORD, int, int))a2[8])(a1: a2[10], a2: 1 << (a6 + 6), a3: 4);
    v20 = v13[1447];
    v21 = v13[14] == 0;
    v13[2] = v19;
    v13[3] = 4 * v20;
    if ( !v21 && v13[16] != 0 && v13[17] != 0 && v19 != 0 )
    {
      v13[1449] = v19 + 2 * (v20 >> 1);
      v13[1446] = v20 + v19 + 2 * v20;
      v13[33] = a3;
      v13[34] = a7;
      *((_BYTE *)v13 + 36) = 8;
      return deflateReset(a1, a2);
    }
    v13[1] = 666;
    a2[6] = "insufficient memory";
    deflateEnd(a1: (int)a2);
  }
  return -4;
}

//------------------------------------------------------------------------------
// Address: 0x0044F6D0
// Name: _deflateInit_
// Source: json
//------------------------------------------------------------------------------
int __usercall deflateInit_@<eax>(__int128 a1@<xmm0>, _DWORD *a2, unsigned int a3, _BYTE *a4, int a5)
{
  return deflateInit2_(a1, a2, a3, a4: 8, a5: 15, a6: 8, a7: 0, a8: a4, a9: a5);
}
