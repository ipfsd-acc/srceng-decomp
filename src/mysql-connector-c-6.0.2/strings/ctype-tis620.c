// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-tis620.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00436CC0
// Name: thai2sortable
// Source: json
//------------------------------------------------------------------------------
int __cdecl thai2sortable(unsigned __int8 *dst, int a2)
{
  int result; // eax
  unsigned __int8 *v3; // esi
  int v4; // ebp
  char v5; // bl
  unsigned __int8 v6; // cl
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9; // al

  result = a2;
  v3 = dst;
  v4 = a2;
  v5 = -8;
  if ( a2 > 0 )
  {
    do
    {
      v6 = *v3;
      if ( *v3 < 0x80u )
      {
        v5 -= 8;
        *v3 = *((_BYTE *)&to_lower_tis620 + v6);
      }
      else
      {
        v7 = dword_502460[5 * v6];
        v8 = 20 * v6;
        if ( (v7 & 0x10) != 0 )
          v5 -= 8;
        if ( (v7 & 0x20) != 0 && v4 != 1 && (v9 = v3[1], (dword_502460[5 * v9] & 0x10) != 0) )
        {
          *v3 = v9;
          v3[1] = v6;
          --v4;
          ++v3;
        }
        else if ( *((int *)&t_ctype.pExceptionObject + 5 * v6) >= 9 )
        {
          memmove(dst: v3, src: v3 + 1, count: v4 - 1);
          dst[a2 - 1] = v5 + *((_BYTE *)&t_ctype.pExceptionObject + v8) - 8;
          --v3;
        }
      }
      --v4;
      ++v3;
    }
    while ( v4 > 0 );
    return a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00436D80
// Name: my_strnncoll_tis620
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_tis620(
        LIST_ENTRY32 *cs,
        unsigned __int8 *s1,
        unsigned int len1,
        unsigned __int8 *s2,
        unsigned int len2,
        char s2_is_prefix)
{
  unsigned int v6; // esi
  unsigned __int8 *p_dst; // ebx
  unsigned __int8 *v8; // edi
  int v9; // esi
  int v11; // [esp+0h] [ebp-68h]
  int v12; // [esp+4h] [ebp-64h]
  CUtlInplaceBuffer dst; // [esp+14h] [ebp-54h] BYREF

  v6 = len1;
  if ( s2_is_prefix != 0 && len1 > len2 )
    v6 = len2;
  p_dst = (unsigned __int8 *)&dst;
  if ( v6 + len2 + 2 > 0x50 )
    p_dst = (unsigned __int8 *)my_str_malloc(nSize: v6 + len2 + 2);
  v8 = &p_dst[v6 + 1];
  memcpy(dst: p_dst, src: s1, count: v6);
  p_dst[v6] = 0;
  memcpy(dst: v8, src: s2, count: len2);
  v8[len2] = 0;
  thai2sortable(dst: p_dst, a2: v6);
  thai2sortable(dst: v8, a2: len2);
  v9 = strcmp((const char *)p_dst, (const char *)v8);
  if ( p_dst != (unsigned __int8 *)&dst )
    my_str_free(this: &dst, a2: (int)p_dst, a3: v11, a4: v12);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00436E60
// Name: my_strnncollsp_tis620
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_tis620(
        LIST_ENTRY32 *cs,
        unsigned __int8 *a0,
        unsigned int a_length,
        unsigned __int8 *b0,
        unsigned int b_length)
{
  unsigned __int8 *p_dst; // esi
  unsigned __int8 *v6; // ebx
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ebp
  signed int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // cl
  char v13; // dl
  int v14; // eax
  unsigned __int8 *v15; // edi
  int res; // [esp+10h] [ebp-64h]
  unsigned int length; // [esp+14h] [ebp-60h]
  unsigned __int8 *alloced; // [esp+18h] [ebp-5Ch]
  unsigned __int8 dst; // [esp+20h] [ebp-54h] BYREF

  alloced = nullptr;
  res = 0;
  p_dst = &dst;
  if ( a_length + b_length + 2 > 0x50 )
  {
    p_dst = (unsigned __int8 *)my_str_malloc(nSize: a_length + b_length + 2);
    alloced = p_dst;
  }
  v6 = &p_dst[a_length + 1];
  memcpy(dst: p_dst, src: a0, count: a_length);
  p_dst[a_length] = 0;
  memcpy(dst: v6, src: b0, count: b_length);
  v6[b_length] = 0;
  v7 = thai2sortable(dst: p_dst, a2: a_length);
  v8 = thai2sortable(dst: v6, a2: b_length);
  v9 = v8;
  if ( v7 >= v8 )
  {
    v10 = v8;
    length = v8;
  }
  else
  {
    v10 = v7;
    length = v7;
  }
  v11 = &p_dst[v10];
  if ( p_dst < &p_dst[v10] )
  {
    while ( 1 )
    {
      v12 = *p_dst;
      v13 = *v6++;
      ++p_dst;
      if ( v12 != v13 )
        break;
      if ( p_dst >= v11 )
      {
        v10 = length;
        goto LABEL_10;
      }
    }
    v10 = *(v6 - 1);
    v14 = *(p_dst - 1) - v10;
    goto LABEL_20;
  }
LABEL_10:
  if ( v7 != v9 )
  {
    v14 = 1;
    if ( v7 < v9 )
    {
      v7 = v9;
      p_dst = v6;
      v14 = -1;
      res = 0;
    }
    v15 = &p_dst[v7 - v10];
    if ( p_dst < v15 )
    {
      while ( *p_dst == 32 )
      {
        if ( ++p_dst >= v15 )
          goto ret_2;
      }
      if ( *p_dst < 0x20u )
        v14 = -v14;
LABEL_20:
      res = v14;
    }
  }
ret_2:
  if ( alloced != nullptr )
    my_str_free(this: (CUtlInplaceBuffer *)v10, a2: (int)alloced, a3: res, a4: length);
  return res;
}

//------------------------------------------------------------------------------
// Address: 0x00436F90
// Name: my_strnxfrm_tis620
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strnxfrm_tis620(
        int a1,
        char *dst,
        unsigned int a3,
        unsigned int a4,
        char *src,
        unsigned int length,
        unsigned int flags)
{
  unsigned int v7; // eax
  unsigned int v8; // edi
  char *v9; // eax
  unsigned int v10; // eax
  unsigned int result; // eax

  v7 = length;
  v8 = a3;
  if ( a3 < length )
    v7 = a3;
  v9 = strmake(dst, src, length: v7);
  v10 = thai2sortable((unsigned __int8 *)dst, a2: v9 - dst);
  if ( a3 > a4 )
    v8 = a4;
  if ( v10 > v8 )
    v10 = v8;
  result = my_strxfrm_pad_desc_and_reverse(
             a1,
             str: (unsigned __int8 *)dst,
             strend: (unsigned __int8 *)&dst[v10],
             a4: (unsigned int)&dst[v8],
             a5: v8 - v10,
             flags,
             level: 0);
  if ( (flags & 0x80u) != 0 && result < a3 )
  {
    (*(void (__cdecl **)(int, char *, unsigned int, _DWORD))(*(_DWORD *)(a1 + 100) + 72))(
      a1,
      a2: &dst[result],
      a3: a3 - result,
      a4: *(unsigned __int8 *)(a1 + 96));
    return a3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437020
// Name: my_mb_wc_tis620
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_tis620(int a1, _DWORD *a2, _BYTE *a3, unsigned int a4)
{
  int v5; // eax

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = (unsigned __int16)cs_to_uni[(unsigned __int8)*a3];
  *a2 = v5;
  if ( v5 != 0 || *a3 == 0 )
    return 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00437060
// Name: my_wc_mb_tis620
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_tis620(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *str, unsigned __int8 *end, ...)
{
  int v5; // eax
  unsigned __int8 v6; // al

  if ( str >= end )
    return -101;
  v5 = *(&uni_to_cs.magicNumber + BYTE1(wc));
  if ( v5 != 0 )
    v6 = *(_BYTE *)((unsigned __int8)wc + v5);
  else
    v6 = 0;
  *str = v6;
  return v6 != 0 || wc == nullptr;
}
