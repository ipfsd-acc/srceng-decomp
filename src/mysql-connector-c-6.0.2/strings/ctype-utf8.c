// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-utf8.c
// Functions: 40
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041EAE0
// Name: _my_wildcmp_unicode
// Source: json
//------------------------------------------------------------------------------
void __thiscall my_wildcmp_unicode(
        DNameStatus cs,
        LIST_ENTRY32 *a2,
        tagShutdownType str,
        tagShutdownType str_end,
        unsigned int w_wc,
        tagShutdownType wildend,
        int escape,
        int w_one,
        int w_many,
        int (__stdcall *weights)())
{
  unsigned int v10; // ebp
  LIST_ENTRY32 *v11; // esi
  char v13; // bl
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // edx
  int v19; // eax
  int v20; // eax
  int (__cdecl *v21)(LIST_ENTRY32 *, unsigned int *, unsigned int, tagShutdownType); // ebx
  int v22; // eax
  int v23; // eax
  int v24; // eax
  unsigned int v25; // ebp
  int i; // eax
  unsigned int v27; // esi
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // eax
  unsigned int s_wc; // [esp+8h] [ebp-8h] BYREF
  int (__cdecl *v33)(LIST_ENTRY32 *, unsigned int *, unsigned int, tagShutdownType); // [esp+Ch] [ebp-4h]

  v10 = w_wc;
  v11 = a2;
  v33 = *(int (__cdecl **)(LIST_ENTRY32 *, unsigned int *, unsigned int, tagShutdownType))(a2[12].Blink + 32);
  if ( w_wc != wildend )
  {
    while ( 1 )
    {
      v13 = 0;
      v14 = v33(a1: a2, a2: &w_wc, a3: v10, a4: wildend);
      if ( v14 <= 0 )
        break;
      if ( w_wc == w_many )
      {
        if ( v10 != wildend )
        {
          while ( 1 )
          {
            v21 = v33;
            v22 = v33(a1: a2, a2: &w_wc, a3: v10, a4: wildend);
            if ( v22 <= 0 )
              break;
            if ( w_wc == w_many )
            {
              v10 += v22;
            }
            else
            {
              if ( w_wc != w_one )
              {
                if ( v10 != wildend && str != str_end )
                {
                  v24 = v21(a1: a2, a2: &w_wc, a3: v10, a4: wildend);
                  if ( v24 > 0 )
                  {
                    v25 = v24 + v10;
                    if ( w_wc != escape || v25 >= wildend || v21(a1: a2, a2: &w_wc, a3: v25, a4: wildend) > 0 )
                    {
LABEL_37:
                      if ( str != str_end )
                      {
                        for ( i = v21(a1: v11, a2: &s_wc, a3: str, a4: str_end);
                              i > 0;
                              i = v33(a1: a2, a2: &s_wc, a3: str, a4: str_end) )
                        {
                          v27 = s_wc;
                          if ( weights != nullptr )
                          {
                            v28 = *((_DWORD *)weights + BYTE1(s_wc));
                            if ( v28 != 0 )
                            {
                              v27 = *(unsigned __int16 *)(v28 + 6 * (unsigned __int8)s_wc + 4);
                              s_wc = v27;
                            }
                            v29 = w_wc;
                            v30 = *((_DWORD *)weights + BYTE1(w_wc));
                            if ( v30 != 0 )
                            {
                              v29 = *(unsigned __int16 *)(v30 + 6 * (unsigned __int8)w_wc + 4);
                              w_wc = v29;
                            }
                          }
                          else
                          {
                            v29 = w_wc;
                          }
                          if ( v27 == v29 )
                          {
                            if ( str != str_end )
                            {
                              str += i;
                              my_wildcmp_unicode(cs: (DNameStatus)str_end);
                              if ( v31 > 0 )
                              {
                                v11 = a2;
                                v21 = v33;
                                goto LABEL_37;
                              }
                            }
                            return;
                          }
                          str += i;
                          if ( str == str_end )
                            return;
                        }
                      }
                    }
                  }
                }
                return;
              }
              v10 += v22;
              v23 = v21(a1: a2, a2: &s_wc, a3: str, a4: str_end);
              if ( v23 <= 0 )
                return;
              str += v23;
            }
            if ( v10 == wildend )
              return;
          }
        }
        return;
      }
      v10 += v14;
      if ( w_wc == escape && v10 < wildend )
      {
        v15 = v33(a1: a2, a2: &w_wc, a3: v10, a4: wildend);
        if ( v15 <= 0 )
          return;
        v10 += v15;
        v13 = 1;
      }
      v16 = v33(a1: a2, a2: &s_wc, a3: str, a4: str_end);
      if ( v16 <= 0 )
        return;
      v17 = w_wc;
      str += v16;
      if ( v13 != 0 || w_wc != w_one )
      {
        v18 = s_wc;
        if ( weights != nullptr )
        {
          if ( s_wc < 0x10000 )
          {
            v19 = *((_DWORD *)weights + BYTE1(s_wc));
            if ( v19 != 0 )
            {
              v18 = *(unsigned __int16 *)(v19 + 6 * (unsigned __int8)s_wc + 4);
              s_wc = v18;
            }
          }
          if ( w_wc < 0x10000 )
          {
            v20 = *((_DWORD *)weights + BYTE1(w_wc));
            if ( v20 != 0 )
            {
              v17 = *(unsigned __int16 *)(v20 + 6 * (unsigned __int8)w_wc + 4);
              w_wc = v17;
            }
          }
        }
        if ( v18 != v17 )
          return;
      }
      if ( v10 == wildend )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EDF0
// Name: my_strxfrm_pad_nweights_unicode
// Source: json
//------------------------------------------------------------------------------
void __usercall my_strxfrm_pad_nweights_unicode(const DName *str@<eax>, int a2@<edx>, unsigned int a3@<ecx>)
{
  for ( ; (unsigned int)str < a3; --a2 )
  {
    if ( a2 == 0 )
      break;
    LOBYTE(str->node) = 0;
    str = (const DName *)((char *)str + 1);
    if ( (unsigned int)str < a3 )
    {
      LOBYTE(str->node) = 32;
      str = (const DName *)((char *)str + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EE10
// Name: my_strxfrm_pad_unicode
// Source: json
//------------------------------------------------------------------------------
_BYTE *__usercall my_strxfrm_pad_unicode@<eax>(_BYTE *a1@<eax>, unsigned int a2@<ecx>)
{
  _BYTE *i; // edx

  for ( i = a1; (unsigned int)a1 < a2; *a1++ = 32 )
  {
    *a1++ = 0;
    if ( (unsigned int)a1 >= a2 )
      break;
  }
  return (_BYTE *)(a1 - i);
}

//------------------------------------------------------------------------------
// Address: 0x0041EE30
// Name: _my_strnxfrm_unicode
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_unicode(int a1, DName *str, int a3, int a4, int a5, int a6, unsigned int flags)
{
  int v7; // ebx
  bool v8; // zf
  DName *v9; // esi
  DName *v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  char v15; // bl
  unsigned __int8 *v17; // [esp+10h] [ebp-4h]

  v7 = a5;
  v8 = (*(_BYTE *)(a1 + 12) & 0x10) == 0;
  v9 = str;
  v17 = (unsigned __int8 *)str;
  v10 = (DName *)((char *)str + a3);
  a5 += a6;
  if ( v8 )
    a3 = *(_DWORD *)(a1 + 64);
  else
    a3 = 0;
  if ( str >= v10 )
    goto LABEL_22;
  while ( 1 )
  {
    v11 = a4;
    if ( a4 == 0 )
      break;
    v12 = (*(int (__cdecl **)(int, DName **, int, int))(*(_DWORD *)(a1 + 100) + 32))(a1, a2: &str, a3: v7, a4: a5);
    if ( v12 <= 0 )
    {
      v11 = a4;
      break;
    }
    v7 += v12;
    LOWORD(v12) = (_WORD)str;
    if ( a3 != 0 )
    {
      if ( (unsigned int)str >> 8 >= 0x100 )
      {
        v12 = 65533;
        goto LABEL_12;
      }
      v13 = *(_DWORD *)(a3 + 4 * ((unsigned int)str >> 8));
      if ( v13 != 0 )
      {
        v12 = *(unsigned __int16 *)(v13 + 6 * (unsigned __int8)str + 4);
LABEL_12:
        str = (DName *)v12;
      }
    }
    LOBYTE(v9->node) = BYTE1(v12);
    v9 = (DName *)((char *)v9 + 1);
    if ( v9 < v10 )
    {
      LOBYTE(v9->node) = v12;
      v9 = (DName *)((char *)v9 + 1);
    }
    --a4;
    if ( v9 >= v10 )
      goto LABEL_22;
  }
  if ( v9 < v10 && v11 != 0 && (flags & 0x40) != 0 )
  {
    my_strxfrm_pad_nweights_unicode(str: v9, a2: v11, a3: (unsigned int)v10);
    v9 = (DName *)((char *)v9 + v14);
  }
LABEL_22:
  v15 = flags;
  my_strxfrm_desc_and_reverse(str: v17, strend: (unsigned __int8 *)v9, flags, level: 0);
  if ( v15 < 0 && v9 < v10 )
    v9 = (DName *)((char *)v9 + (_DWORD)my_strxfrm_pad_unicode(a1: v9, a2: (unsigned int)v10));
  return (char *)v9 - (char *)v17;
}

//------------------------------------------------------------------------------
// Address: 0x0041EF40
// Name: my_mb_wc_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_utf8mb4(int a1, int *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // al
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // al
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // al
  unsigned __int8 v12; // [esp+Ch] [ebp+Ch]

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v6 = *a3;
  if ( *a3 < 0x80u )
  {
    *a2 = v6;
    return 1;
  }
  if ( v6 < 0xC2u )
    return 0;
  if ( v6 >= 0xE0u )
  {
    if ( v6 >= 0xF0u )
    {
      if ( v6 < 0xF5u )
      {
        if ( (unsigned int)(a3 + 4) > a4 )
          return -104;
        v10 = a3[1];
        if ( (v10 ^ 0x80u) < 0x40 )
        {
          v12 = a3[2];
          if ( (v12 ^ 0x80u) < 0x40 )
          {
            v11 = a3[3];
            if ( (v11 ^ 0x80u) < 0x40 && (v6 >= 0xF1u || v10 >= 0x90u) && (v6 <= 0xF3u || v10 <= 0x8Fu) )
            {
              *a2 = v11 ^ 0x80 | ((v12 ^ 0x80 | ((v10 ^ 0x80 | ((v6 & 7) << 6)) << 6)) << 6);
              return 4;
            }
          }
        }
      }
    }
    else
    {
      if ( (unsigned int)(a3 + 3) > a4 )
        return -103;
      v8 = a3[1];
      if ( (v8 ^ 0x80u) < 0x40 )
      {
        v9 = a3[2];
        if ( (v9 ^ 0x80u) < 0x40 && (v6 >= 0xE1u || v8 >= 0xA0u) )
        {
          *a2 = v9 ^ 0x80 | ((v8 ^ 0x80 | ((v6 & 0xF) << 6)) << 6);
          return 3;
        }
      }
    }
    return 0;
  }
  else if ( (unsigned int)(a3 + 2) <= a4 )
  {
    v7 = a3[1];
    if ( (v7 ^ 0x80u) < 0x40 )
    {
      *a2 = v7 ^ 0x80 | ((v6 & 0x1F) << 6);
      return 2;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return -102;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F0D0
// Name: my_mb_wc_utf8mb4_no_range
// Source: json
//------------------------------------------------------------------------------
int __usercall my_mb_wc_utf8mb4_no_range@<eax>(unsigned __int8 *a1@<eax>, int *a2@<esi>)
{
  unsigned __int8 v2; // cl
  unsigned __int8 v4; // al
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // al
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // al
  unsigned __int8 v9; // [esp+1h] [ebp-1h]

  v2 = *a1;
  if ( *a1 < 0x80u )
  {
    *a2 = v2;
    return 1;
  }
  if ( v2 < 0xC2u )
    return 0;
  if ( v2 >= 0xE0u )
  {
    if ( v2 >= 0xF0u )
    {
      if ( v2 < 0xF5u )
      {
        v7 = a1[1];
        if ( (v7 ^ 0x80u) < 0x40 )
        {
          v9 = a1[2];
          if ( (v9 ^ 0x80u) < 0x40 )
          {
            v8 = a1[3];
            if ( (v8 ^ 0x80u) < 0x40 && (v2 >= 0xF1u || v7 >= 0x90u) && (v2 <= 0xF3u || v7 <= 0x8Fu) )
            {
              *a2 = v8 ^ 0x80 | ((v9 ^ 0x80 | ((v7 ^ 0x80 | ((v2 & 7) << 6)) << 6)) << 6);
              return 4;
            }
          }
        }
      }
    }
    else
    {
      v5 = a1[1];
      if ( (v5 ^ 0x80u) < 0x40 )
      {
        v6 = a1[2];
        if ( (v6 ^ 0x80u) < 0x40 && (v2 >= 0xE1u || v5 >= 0xA0u) )
        {
          *a2 = v6 ^ 0x80 | ((v5 ^ 0x80 | ((v2 & 0xF) << 6)) << 6);
          return 3;
        }
      }
    }
    return 0;
  }
  else
  {
    v4 = a1[1];
    if ( (v4 ^ 0x80u) >= 0x40 )
      return 0;
    *a2 = v4 ^ 0x80 | ((v2 & 0x1F) << 6);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F200
// Name: my_wc_mb_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_utf8mb4(LIST_ENTRY32 *cs, unsigned int wc, unsigned __int8 *r, unsigned __int8 *e, ...)
{
  int result; // eax
  unsigned int v5; // eax
  int v6; // esi

  if ( r >= e )
    return -101;
  v5 = wc;
  if ( wc >= 0x80 )
  {
    if ( wc >= 0x800 )
    {
      if ( wc >= 0x10000 )
      {
        if ( wc >= 0x200000 )
          return 0;
        v6 = 4;
      }
      else
      {
        v6 = 3;
      }
    }
    else
    {
      v6 = 2;
    }
  }
  else
  {
    v6 = 1;
  }
  if ( &r[v6] > e )
    return -100 - v6;
  switch ( v6 )
  {
    case 1:
      goto $LN1;
    case 2:
      goto $LN2_2;
    case 3:
      goto $LN3_3;
    case 4:
      r[3] = wc & 0x3F | 0x80;
      v5 = (wc | 0x400000) >> 6;
$LN3_3:
      r[2] = v5 & 0x3F | 0x80;
      v5 = (v5 | 0x20000) >> 6;
$LN2_2:
      r[1] = v5 & 0x3F | 0x80;
      v5 = (v5 | 0x3000) >> 6;
$LN1:
      *r = v5;
      result = v6;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F2D0
// Name: my_wc_mb_utf8mb4_no_range
// Source: json
//------------------------------------------------------------------------------
int __usercall my_wc_mb_utf8mb4_no_range@<eax>(unsigned int wc@<ecx>, _BYTE *a2@<esi>)
{
  int result; // eax

  if ( wc >= 0x80 )
  {
    if ( wc >= 0x800 )
    {
      if ( wc >= 0x10000 )
      {
        if ( wc >= 0x200000 )
          return 0;
        result = 4;
      }
      else
      {
        result = 3;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 1;
  }
  switch ( result )
  {
    case 1:
      goto $LN1_0;
    case 2:
      goto $LN2_3;
    case 3:
      goto $LN3_4;
    case 4:
      a2[3] = wc & 0x3F | 0x80;
      wc = (wc | 0x400000) >> 6;
$LN3_4:
      a2[2] = wc & 0x3F | 0x80;
      wc = (wc | 0x20000) >> 6;
$LN2_3:
      a2[1] = wc & 0x3F | 0x80;
      wc = (wc | 0x3000) >> 6;
$LN1_0:
      *a2 = wc;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F370
// Name: my_caseup_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_caseup_utf8mb4(
        LIST_ENTRY32 *cs,
        unsigned int src,
        int (__stdcall *uni_plane)(),
        char *dstend,
        int srcres)
{
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  int (__stdcall *Flink)(); // eax
  unsigned int v9; // eax
  int v10; // ecx
  int v11; // eax
  char *dst0; // [esp+10h] [ebp-4h]

  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)dstend;
  v7 = (unsigned __int8 *)uni_plane + src;
  Flink = (int (__stdcall *)())cs[8].Flink;
  dstend += srcres;
  dst0 = (char *)v6;
  uni_plane = Flink;
  if ( src < (unsigned int)v7 )
  {
    do
    {
      srcres = my_mb_wc_utf8mb4(a1: (int)cs, a2: (int *)&src, a3: v5, a4: (unsigned int)v7);
      if ( srcres <= 0 )
        break;
      v9 = src;
      if ( src >> 8 < 0x100 )
      {
        v10 = *((_DWORD *)uni_plane + (src >> 8));
        if ( v10 != 0 )
        {
          v9 = *(unsigned __int16 *)(v10 + 6 * (unsigned __int8)src);
          src = v9;
        }
      }
      v11 = my_wc_mb_utf8mb4(cs, wc: v9, r: v6, e: (unsigned __int8 *)dstend);
      if ( v11 <= 0 )
        break;
      v5 += srcres;
      v6 += v11;
    }
    while ( v5 < v7 );
  }
  return v6 - (unsigned __int8 *)dst0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F410
// Name: my_hash_sort_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_hash_sort_utf8mb4(
        LIST_ENTRY32 *a1,
        unsigned __int8 *s,
        unsigned int wc,
        unsigned int *n1,
        unsigned int *n2)
{
  unsigned int v5; // ebp
  int result; // eax
  unsigned int *v7; // esi
  unsigned int *v8; // edi
  unsigned int v9; // ecx
  int v10; // edx
  int res; // [esp+4h] [ebp-8h]
  int (__stdcall *uni_plane)(); // [esp+8h] [ebp-4h]

  v5 = (unsigned int)&s[wc];
  uni_plane = (int (__stdcall *)())a1[8].Flink;
  if ( &s[wc] > s )
  {
    do
    {
      if ( *(_BYTE *)(v5 - 1) != 32 )
        break;
      --v5;
    }
    while ( v5 > (unsigned int)s );
  }
  result = my_mb_wc_utf8mb4((int)a1, a2: (int *)&wc, a3: s, a4: v5);
  res = result;
  if ( result > 0 )
  {
    v7 = n2;
    v8 = n1;
    while ( 1 )
    {
      v9 = wc;
      if ( wc >> 8 >= 0x100 )
        break;
      v10 = *((_DWORD *)uni_plane + (wc >> 8));
      if ( v10 != 0 )
      {
        v9 = *(unsigned __int16 *)(v10 + 6 * (unsigned __int8)wc + 4);
LABEL_10:
        wc = v9;
      }
      *v8 ^= (*v8 << 8) + (unsigned __int8)v9 * (*v7 + (*v8 & 0x3F));
      *v7 += 3;
      *v8 ^= (*v8 << 8) + BYTE1(v9) * (*v7 + (*v8 & 0x3F));
      *v7 += 3;
      if ( v9 > 0xFFFF )
      {
        *v8 ^= (*v8 << 8) + BYTE2(v9) * (*v7 + (*v8 & 0x3F));
        *v7 += 3;
      }
      s += res;
      result = my_mb_wc_utf8mb4((int)a1, a2: (int *)&wc, a3: s, a4: v5);
      res = result;
      if ( result <= 0 )
        return result;
    }
    v9 = 65533;
    goto LABEL_10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F540
// Name: my_caseup_str_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_caseup_str_utf8mb4(int a1, char *wc)
{
  unsigned __int8 *v2; // edi
  char *v3; // ebx
  int v4; // ebp
  char *v5; // eax
  int v6; // edx
  int v7; // eax
  char *v9; // [esp+0h] [ebp-4h]
  int v10; // [esp+8h] [ebp+4h]

  v2 = (unsigned __int8 *)wc;
  v3 = wc;
  v9 = wc;
  v10 = *(_DWORD *)(a1 + 64);
  if ( *wc != 0 )
  {
    do
    {
      v4 = my_mb_wc_utf8mb4_no_range(a1: v2, a2: (int *)&wc);
      if ( v4 <= 0 )
        break;
      v5 = wc;
      if ( (unsigned int)wc >> 8 < 0x100 )
      {
        v6 = *(_DWORD *)(v10 + 4 * ((unsigned int)wc >> 8));
        if ( v6 != 0 )
        {
          v5 = (char *)*(unsigned __int16 *)(v6 + 6 * (unsigned __int8)wc);
          wc = v5;
        }
      }
      v7 = my_wc_mb_utf8mb4_no_range(wc: (unsigned int)v5, a2: v3);
      if ( v7 <= 0 )
        break;
      v2 += v4;
      v3 += v7;
    }
    while ( *v2 != 0 );
  }
  *v3 = 0;
  return v3 - v9;
}

//------------------------------------------------------------------------------
// Address: 0x0041F5D0
// Name: my_casedn_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_casedn_utf8mb4(
        LIST_ENTRY32 *cs,
        unsigned int src,
        int (__stdcall *uni_plane)(),
        char *dstend,
        int srcres)
{
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  int (__stdcall *Flink)(); // eax
  unsigned int v9; // eax
  int v10; // ecx
  int v11; // eax
  char *dst0; // [esp+10h] [ebp-4h]

  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)dstend;
  v7 = (unsigned __int8 *)uni_plane + src;
  Flink = (int (__stdcall *)())cs[8].Flink;
  dstend += srcres;
  dst0 = (char *)v6;
  uni_plane = Flink;
  if ( src < (unsigned int)v7 )
  {
    do
    {
      srcres = my_mb_wc_utf8mb4(a1: (int)cs, a2: (int *)&src, a3: v5, a4: (unsigned int)v7);
      if ( srcres <= 0 )
        break;
      v9 = src;
      if ( src >> 8 < 0x100 )
      {
        v10 = *((_DWORD *)uni_plane + (src >> 8));
        if ( v10 != 0 )
        {
          v9 = *(unsigned __int16 *)(v10 + 6 * (unsigned __int8)src + 2);
          src = v9;
        }
      }
      v11 = my_wc_mb_utf8mb4(cs, wc: v9, r: v6, e: (unsigned __int8 *)dstend);
      if ( v11 <= 0 )
        break;
      v5 += srcres;
      v6 += v11;
    }
    while ( v5 < v7 );
  }
  return v6 - (unsigned __int8 *)dst0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F680
// Name: my_casedn_str_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_casedn_str_utf8mb4(int a1, char *wc)
{
  unsigned __int8 *v2; // edi
  char *v3; // ebx
  int v4; // ebp
  char *v5; // eax
  int v6; // edx
  int v7; // eax
  char *v9; // [esp+0h] [ebp-4h]
  int v10; // [esp+8h] [ebp+4h]

  v2 = (unsigned __int8 *)wc;
  v3 = wc;
  v9 = wc;
  v10 = *(_DWORD *)(a1 + 64);
  if ( *wc != 0 )
  {
    do
    {
      v4 = my_mb_wc_utf8mb4_no_range(a1: v2, a2: (int *)&wc);
      if ( v4 <= 0 )
        break;
      v5 = wc;
      if ( (unsigned int)wc >> 8 < 0x100 )
      {
        v6 = *(_DWORD *)(v10 + 4 * ((unsigned int)wc >> 8));
        if ( v6 != 0 )
        {
          v5 = (char *)*(unsigned __int16 *)(v6 + 6 * (unsigned __int8)wc + 2);
          wc = v5;
        }
      }
      v7 = my_wc_mb_utf8mb4_no_range(wc: (unsigned int)v5, a2: v3);
      if ( v7 <= 0 )
        break;
      v2 += v4;
      v3 += v7;
    }
    while ( *v2 != 0 );
  }
  *v3 = 0;
  return v3 - v9;
}

//------------------------------------------------------------------------------
// Address: 0x0041F710
// Name: my_strnncoll_utf8mb4
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncoll_utf8mb4(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        unsigned int t_wc,
        int (__stdcall *uni_plane)(),
        const LoggingContext_t *te,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // esi
  int (__stdcall *Flink)(); // eax
  const LoggingContext_t *v10; // ebp
  int v11; // eax
  unsigned int v12; // eax
  int v13; // edx
  unsigned int v14; // ecx
  int v15; // edx
  int s_res; // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v6 = (unsigned __int8 *)uni_plane;
  v7 = (unsigned __int8 *)s_wc;
  v8 = s_wc + t_wc;
  Flink = (int (__stdcall *)())cs[8].Flink;
  v10 = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  te = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  uni_plane = Flink;
  if ( s_wc < s_wc + t_wc )
  {
    do
    {
      if ( v6 >= (unsigned __int8 *)v10 )
        break;
      s_res = my_mb_wc_utf8mb4(a1: (int)cs, a2: (int *)&s_wc, a3: v7, a4: v8);
      v11 = my_mb_wc_utf8mb4(a1: (int)cs, a2: (int *)&t_wc, a3: v6, a4: (unsigned int)v10);
      t_res = v11;
      if ( s_res <= 0 || v11 <= 0 )
        return bincmp(s: (DNameStatus)v7);
      v12 = s_wc;
      if ( s_wc >> 8 >= 0x100 )
      {
        v12 = 65533;
      }
      else
      {
        v13 = *((_DWORD *)uni_plane + (s_wc >> 8));
        if ( v13 == 0 )
          goto LABEL_10;
        v12 = *(unsigned __int16 *)(v13 + 6 * (unsigned __int8)s_wc + 4);
      }
      s_wc = v12;
LABEL_10:
      v14 = t_wc;
      if ( t_wc >> 8 >= 0x100 )
      {
        v14 = 65533;
      }
      else
      {
        v15 = *((_DWORD *)uni_plane + (t_wc >> 8));
        v10 = te;
        if ( v15 == 0 )
          goto LABEL_15;
        v14 = *(unsigned __int16 *)(v15 + 6 * (unsigned __int8)t_wc + 4);
      }
      t_wc = v14;
LABEL_15:
      if ( v14 != v12 )
        return (DName *)(v14 < v12 ? 1 : -1);
      v7 += s_res;
      v6 += t_res;
    }
    while ( (unsigned int)v7 < v8 );
  }
  if ( t_is_prefix != 0 )
    return (DName *)(v6 - (unsigned __int8 *)v10);
  else
    return (DName *)&v6[v8 - (_DWORD)v10 - (_DWORD)v7];
}

//------------------------------------------------------------------------------
// Address: 0x0041F860
// Name: my_strnncollsp_utf8mb4
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncollsp_utf8mb4(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        unsigned int t_wc,
        int (__stdcall *uni_plane)(),
        const LoggingContext_t *te)
{
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  unsigned int v7; // edi
  int (__stdcall *Flink)(); // eax
  const LoggingContext_t *v9; // ebp
  int v10; // eax
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // edx
  int s_res; // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v5 = (unsigned __int8 *)uni_plane;
  v6 = (unsigned __int8 *)s_wc;
  v7 = s_wc + t_wc;
  Flink = (int (__stdcall *)())cs[8].Flink;
  v9 = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  te = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  uni_plane = Flink;
  if ( s_wc < s_wc + t_wc )
  {
    do
    {
      if ( v5 >= (unsigned __int8 *)v9 )
        break;
      s_res = my_mb_wc_utf8mb4(a1: (int)cs, a2: (int *)&s_wc, a3: v6, a4: v7);
      v10 = my_mb_wc_utf8mb4(a1: (int)cs, a2: (int *)&t_wc, a3: v5, a4: (unsigned int)v9);
      t_res = v10;
      if ( s_res <= 0 || v10 <= 0 )
        return bincmp(s: (DNameStatus)v6);
      v11 = s_wc;
      if ( s_wc >> 8 >= 0x100 )
      {
        v11 = 65533;
      }
      else
      {
        v12 = *((_DWORD *)uni_plane + (s_wc >> 8));
        if ( v12 == 0 )
          goto LABEL_10;
        v11 = *(unsigned __int16 *)(v12 + 6 * (unsigned __int8)s_wc + 4);
      }
      s_wc = v11;
LABEL_10:
      v13 = t_wc;
      if ( t_wc >> 8 >= 0x100 )
      {
        v13 = 65533;
      }
      else
      {
        v14 = *((_DWORD *)uni_plane + (t_wc >> 8));
        v9 = te;
        if ( v14 == 0 )
          goto LABEL_15;
        v13 = *(unsigned __int16 *)(v14 + 6 * (unsigned __int8)t_wc + 4);
      }
      t_wc = v13;
LABEL_15:
      if ( v13 != v11 )
        return (DName *)(v13 < v11 ? 1 : -1);
      v6 += s_res;
      v5 += t_res;
    }
    while ( (unsigned int)v6 < v7 );
  }
  if ( v7 - (_DWORD)v6 == (char *)v9 - (char *)v5 )
    return nullptr;
  v15 = 1;
  if ( v7 - (unsigned int)v6 < (char *)v9 - (char *)v5 )
  {
    v6 = v5;
    v7 = (unsigned int)v9;
    v15 = -1;
  }
  if ( (unsigned int)v6 >= v7 )
    return nullptr;
  while ( *v6 == 32 )
  {
    if ( (unsigned int)++v6 >= v7 )
      return nullptr;
  }
  if ( *v6 < 0x20u )
    return (DName *)-v15;
  return (DName *)v15;
}

//------------------------------------------------------------------------------
// Address: 0x0041F9D0
// Name: my_strcasecmp_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strcasecmp_utf8mb4(unsigned int s_wc, unsigned int t_wc, unsigned __int8 *t)
{
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // ebp
  unsigned __int8 v5; // al
  unsigned int v6; // edi
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // eax
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // eax
  bool v15; // cf
  unsigned __int8 v16; // dl
  unsigned __int8 *v17; // ecx
  unsigned __int8 *v18; // eax
  unsigned __int8 v19; // dl
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp-4h]

  v3 = t;
  v4 = (unsigned __int8 *)t_wc;
  v5 = *(_BYTE *)t_wc;
  uni_plane = *(int (__stdcall **)())(s_wc + 64);
  if ( *(_BYTE *)t_wc == 0 )
    return *v4 - *v3;
  while ( 1 )
  {
    if ( *v3 == 0 )
      return *v4 - *v3;
    if ( v5 < 0x80u )
    {
      v6 = (unsigned __int16)word_4C4A2A[3 * v5];
      ++v4;
LABEL_9:
      s_wc = v6;
      goto LABEL_10;
    }
    v7 = my_mb_wc_utf8mb4_no_range(a1: v4, a2: (int *)&s_wc);
    if ( v7 <= 0 )
    {
      v13 = v3;
      v14 = v4;
      while ( 1 )
      {
        v15 = *v14 < *v13;
        if ( *v14 != *v13 )
          break;
        if ( *v14 != 0 )
        {
          v16 = v14[1];
          v15 = v16 < v13[1];
          if ( v16 != v13[1] )
            return -v15 - (v15 - 1);
          v14 += 2;
          v13 += 2;
          if ( v16 != 0 )
            continue;
        }
        return 0;
      }
      return -v15 - (v15 - 1);
    }
    v6 = s_wc;
    v4 += v7;
    if ( s_wc >> 8 < 0x100 )
    {
      v8 = *((_DWORD *)uni_plane + (s_wc >> 8));
      if ( v8 != 0 )
      {
        v6 = *(unsigned __int16 *)(v8 + 6 * (unsigned __int8)s_wc + 2);
        goto LABEL_9;
      }
    }
LABEL_10:
    if ( *v3 < 0x80u )
    {
      v9 = (unsigned __int16)word_4C4A2A[3 * *v3++];
LABEL_16:
      t_wc = v9;
      goto LABEL_17;
    }
    v10 = my_mb_wc_utf8mb4_no_range(a1: v3, a2: (int *)&t_wc);
    if ( v10 <= 0 )
    {
      v17 = v3;
      v18 = v4;
      while ( 1 )
      {
        v15 = *v18 < *v17;
        if ( *v18 != *v17 )
          break;
        if ( *v18 != 0 )
        {
          v19 = v18[1];
          v15 = v19 < v17[1];
          if ( v19 != v17[1] )
            return -v15 - (v15 - 1);
          v18 += 2;
          v17 += 2;
          if ( v19 != 0 )
            continue;
        }
        return 0;
      }
      return -v15 - (v15 - 1);
    }
    v9 = t_wc;
    v3 += v10;
    if ( t_wc >> 8 < 0x100 )
    {
      v11 = *((_DWORD *)uni_plane + (t_wc >> 8));
      if ( v11 != 0 )
      {
        v9 = *(unsigned __int16 *)(v11 + 6 * (unsigned __int8)t_wc + 2);
        goto LABEL_16;
      }
    }
LABEL_17:
    if ( v6 != v9 )
      return v6 - v9;
    v5 = *v4;
    if ( *v4 == 0 )
      return *v4 - *v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FB40
// Name: my_wildcmp_utf8mb4
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_wildcmp_utf8mb4(
        int a1,
        tagShutdownType a2,
        tagShutdownType a3,
        unsigned int a4,
        tagShutdownType a5,
        int a6,
        int a7,
        int a8)
{
  my_wildcmp_unicode(
    cs: (DNameStatus)a3,
    a2: (LIST_ENTRY32 *)a1,
    str: a2,
    str_end: a3,
    w_wc: a4,
    wildend: a5,
    escape: a6,
    w_one: a7,
    w_many: a8,
    weights: *(int (__stdcall **)())(a1 + 64));
}

//------------------------------------------------------------------------------
// Address: 0x0041FB80
// Name: my_strnxfrmlen_utf8mb4
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strnxfrmlen_utf8mb4(LIST_ENTRY32 *cs, unsigned int len)
{
  return (2 * len + 2) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB90
// Name: my_ismbchar_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_ismbchar_utf8mb4(int a1, unsigned __int8 *a2, unsigned int a3)
{
  int v3; // ecx
  int v4; // eax
  int v6; // [esp+0h] [ebp-4h] BYREF

  v6 = v3;
  v4 = my_mb_wc_utf8mb4(a1, a2: &v6, a3: a2, a4: a3);
  return v4 <= 1 ? 0 : v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041FBC0
// Name: my_mbcharlen_utf8mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mbcharlen_utf8mb4(LIST_ENTRY32 *cs, unsigned int c)
{
  if ( c < 0x80 )
    return 1;
  if ( c < 0xC2 )
    return 0;
  if ( c < 0xE0 )
    return 2;
  if ( c >= 0xF0 )
    return c < 0xF8 ? 4 : 0;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0041FC00
// Name: my_mb_wc_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_utf8mb3(int a1, int *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // al

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *a3;
  if ( *a3 < 0x80u )
  {
    *a2 = v5;
    return 1;
  }
  if ( v5 < 0xC2u )
    return 0;
  if ( v5 < 0xE0u )
  {
    if ( (unsigned int)(a3 + 2) > a4 )
      return -102;
    v6 = a3[1];
    if ( (v6 ^ 0x80u) < 0x40 )
    {
      *a2 = v6 ^ 0x80 | ((v5 & 0x1F) << 6);
      return 2;
    }
  }
  else if ( v5 < 0xF0u )
  {
    if ( (unsigned int)(a3 + 3) > a4 )
      return -103;
    v7 = a3[1];
    if ( (v7 ^ 0x80u) >= 0x40 )
      return 0;
    v8 = a3[2];
    if ( (v8 ^ 0x80u) >= 0x40 || v5 < 0xE1u && v7 < 0xA0u )
      return 0;
    *a2 = v8 ^ 0x80 | ((v7 ^ 0x80 | ((v5 & 0xF) << 6)) << 6);
    return 3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FCF0
// Name: my_mb_wc_utf8mb3_no_range
// Source: json
//------------------------------------------------------------------------------
int __usercall my_mb_wc_utf8mb3_no_range@<eax>(unsigned __int8 *a1@<ecx>, int *a2@<esi>)
{
  unsigned __int8 v2; // al
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl

  v2 = *a1;
  if ( *a1 < 0x80u )
  {
    *a2 = v2;
    return 1;
  }
  if ( v2 < 0xC2u )
    return 0;
  if ( v2 < 0xE0u )
  {
    v4 = a1[1];
    if ( (v4 ^ 0x80u) < 0x40 )
    {
      *a2 = v4 ^ 0x80 | ((v2 & 0x1F) << 6);
      return 2;
    }
    return 0;
  }
  if ( v2 >= 0xF0u )
    return 0;
  v5 = a1[1];
  if ( (v5 ^ 0x80u) >= 0x40 )
    return 0;
  v6 = a1[2];
  if ( (v6 ^ 0x80u) >= 0x40 || v2 < 0xE1u && v5 < 0xA0u )
    return 0;
  *a2 = v6 ^ 0x80 | ((v5 ^ 0x80 | ((v2 & 0xF) << 6)) << 6);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0041FD90
// Name: my_wc_mb_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_utf8mb3(LIST_ENTRY32 *cs, unsigned int wc, unsigned __int8 *r, unsigned __int8 *e, ...)
{
  unsigned int v5; // eax
  int v6; // esi

  if ( r >= e )
    return -101;
  v5 = wc;
  if ( wc >= 0x80 )
  {
    if ( wc >= 0x800 )
    {
      if ( wc >= 0x10000 )
        return 0;
      v6 = 3;
    }
    else
    {
      v6 = 2;
    }
  }
  else
  {
    v6 = 1;
  }
  if ( &r[v6] > e )
    return -100 - v6;
  if ( v6 != 1 )
  {
    if ( v6 != 2 )
    {
      r[2] = wc & 0x3F | 0x80;
      v5 = (wc | 0x20000) >> 6;
    }
    r[1] = v5 & 0x3F | 0x80;
    v5 = (v5 | 0x3000) >> 6;
  }
  *r = v5;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041FE30
// Name: my_wc_mb_utf8mb3_no_range
// Source: json
//------------------------------------------------------------------------------
int __usercall my_wc_mb_utf8mb3_no_range@<eax>(unsigned int wc@<ecx>, _BYTE *a2@<esi>)
{
  int result; // eax

  if ( wc >= 0x80 )
  {
    if ( wc >= 0x800 )
    {
      if ( wc >= 0x10000 )
        return 0;
      result = 3;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 1;
  }
  if ( result != 1 )
  {
    if ( result != 2 )
    {
      a2[2] = wc & 0x3F | 0x80;
      wc = (wc | 0x20000) >> 6;
    }
    a2[1] = wc & 0x3F | 0x80;
    wc = (wc | 0x3000) >> 6;
  }
  *a2 = wc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FEA0
// Name: my_caseup_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_caseup_utf8mb3(LIST_ENTRY32 *cs, _iobuf *src, int (__stdcall *uni_plane)(), char *dstend, int srcres)
{
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  int (__stdcall *Flink)(); // eax
  _iobuf *v9; // ecx
  int v10; // eax
  int v11; // eax
  char *dst0; // [esp+10h] [ebp-4h]

  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)dstend;
  v7 = (unsigned __int8 *)uni_plane + (_DWORD)src;
  Flink = (int (__stdcall *)())cs[8].Flink;
  dstend += srcres;
  dst0 = (char *)v6;
  uni_plane = Flink;
  if ( src < (_iobuf *)v7 )
  {
    do
    {
      srcres = my_mb_wc_utf8mb3(a1: (int)cs, a2: (int *)&src, a3: v5, a4: (unsigned int)v7);
      if ( srcres <= 0 )
        break;
      v9 = src;
      v10 = *((_DWORD *)uni_plane + BYTE1(src));
      if ( v10 != 0 )
      {
        v9 = (_iobuf *)*(unsigned __int16 *)(v10 + 6 * (unsigned __int8)src);
        src = v9;
      }
      v11 = my_wc_mb_utf8mb3(cs, wc: (unsigned int)v9, r: v6, e: (unsigned __int8 *)dstend);
      if ( v11 <= 0 )
        break;
      v5 += srcres;
      v6 += v11;
    }
    while ( v5 < v7 );
  }
  return v6 - (unsigned __int8 *)dst0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FF40
// Name: my_hash_sort_utf8mb3
// Source: json
//------------------------------------------------------------------------------
signed int __cdecl my_hash_sort_utf8mb3(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *e,
        unsigned int wc,
        unsigned int *n1,
        unsigned int *n2)
{
  unsigned __int8 *v5; // ebx
  signed int result; // eax
  unsigned int *v7; // esi
  unsigned int *v8; // edi
  unsigned int v9; // ecx
  int v10; // edx
  int (__stdcall *uni_plane)(); // [esp+4h] [ebp-8h]
  const LoggingContext_t *ea; // [esp+14h] [ebp+8h]

  v5 = (unsigned __int8 *)e;
  result = (signed int)e + wc;
  uni_plane = (int (__stdcall *)())a1[8].Flink;
  if ( (const LoggingContext_t *)((char *)e + wc) > e )
  {
    while ( *(_BYTE *)(result - 1) == 32 )
    {
      if ( --result <= (unsigned int)e )
        return result;
    }
    ea = (const LoggingContext_t *)result;
    if ( (unsigned int)v5 < result )
    {
      v7 = n2;
      v8 = n1;
      do
      {
        result = my_mb_wc_utf8mb3((int)a1, a2: (int *)&wc, a3: v5, a4: result);
        if ( result <= 0 )
          break;
        v9 = wc;
        v10 = *((_DWORD *)uni_plane + BYTE1(wc));
        if ( v10 != 0 )
        {
          v9 = *(unsigned __int16 *)(v10 + 6 * (unsigned __int8)wc + 4);
          wc = v9;
        }
        v5 += result;
        *v8 ^= (*v8 << 8) + (unsigned __int8)v9 * (*v7 + (*v8 & 0x3F));
        *v7 += 3;
        result = (signed int)ea;
        *v8 ^= (*v8 << 8) + (v9 >> 8) * (*v7 + (*v8 & 0x3F));
        *v7 += 3;
      }
      while ( v5 < (unsigned __int8 *)ea );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420030
// Name: my_caseup_str_utf8mb3
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_caseup_str_utf8mb3(int a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // edi
  unsigned __int8 *v3; // ebx
  int v4; // ebp
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v9; // [esp+0h] [ebp-4h]
  int i; // [esp+8h] [ebp+4h]

  v2 = a2;
  v3 = a2;
  v9 = (int)a2;
  for ( i = *(_DWORD *)(a1 + 64); *v2 != 0; v3 += v7 )
  {
    v4 = my_mb_wc_utf8mb3_no_range(a1: v2, (int *)&a2);
    if ( v4 <= 0 )
      break;
    v5 = (unsigned int)a2;
    v6 = *(_DWORD *)(i + 4 * BYTE1(a2));
    if ( v6 != 0 )
    {
      v5 = *(unsigned __int16 *)(v6 + 6 * (unsigned __int8)a2);
      a2 = (unsigned __int8 *)v5;
    }
    v7 = my_wc_mb_utf8mb3_no_range(wc: v5, a2: v3);
    if ( v7 <= 0 )
      break;
    v2 += v4;
  }
  *v3 = 0;
  return &v3[-v9];
}

//------------------------------------------------------------------------------
// Address: 0x004200B0
// Name: my_casedn_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_casedn_utf8mb3(LIST_ENTRY32 *cs, _iobuf *src, int (__stdcall *uni_plane)(), char *dstend, int srcres)
{
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  int (__stdcall *Flink)(); // eax
  _iobuf *v9; // ecx
  int v10; // eax
  int v11; // eax
  char *dst0; // [esp+10h] [ebp-4h]

  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)dstend;
  v7 = (unsigned __int8 *)uni_plane + (_DWORD)src;
  Flink = (int (__stdcall *)())cs[8].Flink;
  dstend += srcres;
  dst0 = (char *)v6;
  uni_plane = Flink;
  if ( src < (_iobuf *)v7 )
  {
    do
    {
      srcres = my_mb_wc_utf8mb3(a1: (int)cs, a2: (int *)&src, a3: v5, a4: (unsigned int)v7);
      if ( srcres <= 0 )
        break;
      v9 = src;
      v10 = *((_DWORD *)uni_plane + BYTE1(src));
      if ( v10 != 0 )
      {
        v9 = (_iobuf *)*(unsigned __int16 *)(v10 + 6 * (unsigned __int8)src + 2);
        src = v9;
      }
      v11 = my_wc_mb_utf8mb3(cs, wc: (unsigned int)v9, r: v6, e: (unsigned __int8 *)dstend);
      if ( v11 <= 0 )
        break;
      v5 += srcres;
      v6 += v11;
    }
    while ( v5 < v7 );
  }
  return v6 - (unsigned __int8 *)dst0;
}

//------------------------------------------------------------------------------
// Address: 0x00420150
// Name: my_casedn_str_utf8mb3
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_casedn_str_utf8mb3(int a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // edi
  unsigned __int8 *v3; // ebx
  int v4; // ebp
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v9; // [esp+0h] [ebp-4h]
  int i; // [esp+8h] [ebp+4h]

  v2 = a2;
  v3 = a2;
  v9 = (int)a2;
  for ( i = *(_DWORD *)(a1 + 64); *v2 != 0; v3 += v7 )
  {
    v4 = my_mb_wc_utf8mb3_no_range(a1: v2, (int *)&a2);
    if ( v4 <= 0 )
      break;
    v5 = (unsigned int)a2;
    v6 = *(_DWORD *)(i + 4 * BYTE1(a2));
    if ( v6 != 0 )
    {
      v5 = *(unsigned __int16 *)(v6 + 6 * (unsigned __int8)a2 + 2);
      a2 = (unsigned __int8 *)v5;
    }
    v7 = my_wc_mb_utf8mb3_no_range(wc: v5, a2: v3);
    if ( v7 <= 0 )
      break;
    v2 += v4;
  }
  *v3 = 0;
  return &v3[-v9];
}

//------------------------------------------------------------------------------
// Address: 0x004201D0
// Name: my_strnncoll_utf8mb3
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncoll_utf8mb3(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        unsigned int t_wc,
        int s_res,
        const LoggingContext_t *te,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // esi
  int Flink; // eax
  const LoggingContext_t *v10; // ebp
  int v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  unsigned int v14; // edx
  int v15; // ecx
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v6 = (unsigned __int8 *)s_res;
  v7 = (unsigned __int8 *)s_wc;
  v8 = s_wc + t_wc;
  Flink = cs[8].Flink;
  v10 = (const LoggingContext_t *)((char *)te + s_res);
  te = (const LoggingContext_t *)((char *)te + s_res);
  uni_plane = (int (__stdcall *)())Flink;
  if ( s_wc < s_wc + t_wc )
  {
    while ( v6 < (unsigned __int8 *)v10 )
    {
      s_res = my_mb_wc_utf8mb3(a1: (int)cs, a2: (int *)&s_wc, a3: v7, a4: v8);
      v11 = my_mb_wc_utf8mb3(a1: (int)cs, a2: (int *)&t_wc, a3: v6, a4: (unsigned int)v10);
      t_res = v11;
      if ( s_res <= 0 || v11 <= 0 )
        return bincmp(s: (DNameStatus)v7);
      v12 = s_wc;
      v13 = *((_DWORD *)uni_plane + BYTE1(s_wc));
      if ( v13 != 0 )
      {
        v12 = *(unsigned __int16 *)(v13 + 6 * (unsigned __int8)s_wc + 4);
        s_wc = v12;
      }
      v14 = t_wc;
      v15 = *((_DWORD *)uni_plane + BYTE1(t_wc));
      if ( v15 != 0 )
      {
        v14 = *(unsigned __int16 *)(v15 + 6 * (unsigned __int8)t_wc + 4);
        t_wc = v14;
      }
      if ( v14 != v12 )
        return (DName *)(v14 < v12 ? 1 : -1);
      v7 += s_res;
      v6 += t_res;
      v10 = te;
      if ( (unsigned int)v7 >= v8 )
        break;
    }
  }
  if ( t_is_prefix != 0 )
    return (DName *)(v6 - (unsigned __int8 *)v10);
  else
    return (DName *)&v6[v8 - (_DWORD)v10 - (_DWORD)v7];
}

//------------------------------------------------------------------------------
// Address: 0x00420310
// Name: my_strnncollsp_utf8mb3
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncollsp_utf8mb3(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        unsigned int t_wc,
        int s_res,
        const LoggingContext_t *te)
{
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  unsigned int v7; // edi
  int Flink; // eax
  const LoggingContext_t *v9; // ebp
  int v10; // eax
  unsigned int v11; // eax
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // ecx
  int v15; // edx
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v5 = (unsigned __int8 *)s_res;
  v6 = (unsigned __int8 *)s_wc;
  v7 = s_wc + t_wc;
  Flink = cs[8].Flink;
  v9 = (const LoggingContext_t *)((char *)te + s_res);
  te = (const LoggingContext_t *)((char *)te + s_res);
  uni_plane = (int (__stdcall *)())Flink;
  if ( s_wc < s_wc + t_wc )
  {
    while ( v5 < (unsigned __int8 *)v9 )
    {
      s_res = my_mb_wc_utf8mb3(a1: (int)cs, a2: (int *)&s_wc, a3: v6, a4: v7);
      v10 = my_mb_wc_utf8mb3(a1: (int)cs, a2: (int *)&t_wc, a3: v5, a4: (unsigned int)v9);
      t_res = v10;
      if ( s_res <= 0 || v10 <= 0 )
        return bincmp(s: (DNameStatus)v6);
      v11 = s_wc;
      v12 = *((_DWORD *)uni_plane + BYTE1(s_wc));
      if ( v12 != 0 )
      {
        v11 = *(unsigned __int16 *)(v12 + 6 * (unsigned __int8)s_wc + 4);
        s_wc = v11;
      }
      v13 = t_wc;
      v14 = *((_DWORD *)uni_plane + BYTE1(t_wc));
      if ( v14 != 0 )
      {
        v13 = *(unsigned __int16 *)(v14 + 6 * (unsigned __int8)t_wc + 4);
        t_wc = v13;
      }
      if ( v13 != v11 )
        return (DName *)(v13 < v11 ? 1 : -1);
      v6 += s_res;
      v5 += t_res;
      v9 = te;
      if ( (unsigned int)v6 >= v7 )
        break;
    }
  }
  if ( v7 - (_DWORD)v6 == (char *)v9 - (char *)v5 )
    return nullptr;
  v15 = 1;
  if ( v7 - (unsigned int)v6 < (char *)v9 - (char *)v5 )
  {
    v6 = v5;
    v7 = (unsigned int)v9;
    v15 = -1;
  }
  if ( (unsigned int)v6 >= v7 )
    return nullptr;
  while ( *v6 == 32 )
  {
    if ( (unsigned int)++v6 >= v7 )
      return nullptr;
  }
  if ( *v6 < 0x20u )
    return (DName *)-v15;
  return (DName *)v15;
}

//------------------------------------------------------------------------------
// Address: 0x00420470
// Name: my_strcasecmp_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strcasecmp_utf8mb3(LIST_ENTRY32 *a1, unsigned __int8 *s_wc, unsigned __int8 *t)
{
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v4; // esi
  unsigned __int8 v5; // al
  unsigned __int8 v6; // bl
  unsigned __int8 *v7; // edi
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // eax
  bool v14; // cf
  unsigned __int8 v15; // al
  unsigned __int8 v16; // al
  unsigned int t_wc; // [esp+10h] [ebp-8h] BYREF
  int (__stdcall *uni_plane)(); // [esp+14h] [ebp-4h]

  v3 = t;
  v4 = s_wc;
  v5 = *s_wc;
  uni_plane = (int (__stdcall *)())a1[8].Flink;
  if ( v5 == 0 )
    return *v4 - *v3;
  while ( 1 )
  {
    v6 = *v3;
    if ( *v3 == 0 )
      return *v4 - *v3;
    if ( v5 < 0x80u )
    {
      v7 = (unsigned __int8 *)(unsigned __int16)word_4C4A2A[3 * v5];
      ++v4;
LABEL_8:
      s_wc = v7;
      goto LABEL_9;
    }
    v8 = my_mb_wc_utf8mb3((int)a1, a2: (int *)&s_wc, a3: v4, a4: (unsigned int)(v4 + 3));
    if ( v8 <= 0 )
    {
      while ( 1 )
      {
        v14 = *v4 < *v3;
        if ( *v4 != *v3 )
          break;
        if ( *v4 != 0 )
        {
          v15 = v4[1];
          v14 = v15 < v3[1];
          if ( v15 != v3[1] )
            return -v14 - (v14 - 1);
          v4 += 2;
          v3 += 2;
          if ( v15 != 0 )
            continue;
        }
        return 0;
      }
      return -v14 - (v14 - 1);
    }
    v7 = s_wc;
    v4 += v8;
    v9 = *((_DWORD *)uni_plane + BYTE1(s_wc));
    if ( v9 != 0 )
    {
      v7 = (unsigned __int8 *)*(unsigned __int16 *)(v9 + 6 * (unsigned __int8)s_wc + 2);
      goto LABEL_8;
    }
LABEL_9:
    if ( v6 < 0x80u )
    {
      v10 = (unsigned __int16)word_4C4A2A[3 * v6];
      ++v3;
      goto LABEL_14;
    }
    v11 = my_mb_wc_utf8mb3((int)a1, a2: (int *)&t_wc, a3: v3, a4: (unsigned int)(v3 + 3));
    if ( v11 <= 0 )
    {
      while ( 1 )
      {
        v14 = *v4 < *v3;
        if ( *v4 != *v3 )
          break;
        if ( *v4 != 0 )
        {
          v16 = v4[1];
          v14 = v16 < v3[1];
          if ( v16 != v3[1] )
            return -v14 - (v14 - 1);
          v4 += 2;
          v3 += 2;
          if ( v16 != 0 )
            continue;
        }
        return 0;
      }
      return -v14 - (v14 - 1);
    }
    v10 = t_wc;
    v3 += v11;
    v12 = *((_DWORD *)uni_plane + BYTE1(t_wc));
    if ( v12 != 0 )
    {
      v10 = *(unsigned __int16 *)(v12 + 6 * (unsigned __int8)t_wc + 2);
LABEL_14:
      t_wc = v10;
    }
    if ( v7 != (unsigned __int8 *)v10 )
      return (int)&v7[-v10];
    v5 = *v4;
    if ( *v4 == 0 )
      return *v4 - *v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004205F0
// Name: my_strnxfrmlen_utf8mb3
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strnxfrmlen_utf8mb3(LIST_ENTRY32 *cs, unsigned int len)
{
  return (2 * len + 2) / 3;
}

//------------------------------------------------------------------------------
// Address: 0x00420610
// Name: my_ismbchar_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_ismbchar_utf8mb3(int a1, unsigned __int8 *a2, unsigned int a3)
{
  int v3; // ecx
  int v4; // eax
  int v6; // [esp+0h] [ebp-4h] BYREF

  v6 = v3;
  v4 = my_mb_wc_utf8mb3(a1, a2: &v6, a3: a2, a4: a3);
  return v4 <= 1 ? 0 : v4;
}

//------------------------------------------------------------------------------
// Address: 0x00420640
// Name: my_mbcharlen_utf8mb3
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mbcharlen_utf8mb3(LIST_ENTRY32 *cs, unsigned int c)
{
  if ( c < 0x80 )
    return 1;
  if ( c < 0xC2 )
    return 0;
  if ( c >= 0xE0 )
    return c < 0xF0 ? 3 : 0;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00420680
// Name: hexlo
// Source: json
//------------------------------------------------------------------------------
int __usercall hexlo@<eax>(int a1@<eax>)
{
  return *((char *)&hex_lo_digit + a1);
}

//------------------------------------------------------------------------------
// Address: 0x00420690
// Name: my_mb_wc_filename
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_filename(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned __int8 v5; // al
  int v6; // eax
  int v7; // esi
  int v8; // edx
  unsigned __int16 v9; // dx
  int v10; // esi
  int v11; // eax
  int v12; // edx
  int v13; // ecx

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *a3;
  if ( *a3 < 0x80u && filename_safe_char[v5] != 0 )
  {
    *a2 = v5;
    return 1;
  }
  if ( v5 != 64 )
    return 0;
  if ( (unsigned int)(a3 + 3) > a4 )
    return -103;
  v6 = a3[1];
  v7 = a3[2];
  if ( (unsigned int)(v6 - 48) > 0x4F || (unsigned int)(v7 - 48) > 0x4F )
    goto LABEL_18;
  v8 = 80 * v6 + v7 - 3888;
  if ( v8 < 5994 )
  {
    v9 = touni[v8];
    if ( v9 != 0 )
    {
      *a2 = v9;
      return 3;
    }
  }
  if ( v6 == 64 && v7 == 64 )
  {
    *a2 = 0;
    return 3;
  }
  else
  {
LABEL_18:
    if ( (unsigned int)(a3 + 4) <= a4 )
    {
      if ( hexlo(a1: v6) < 0 )
        return 0;
      v10 = hexlo(a1: v7);
      if ( v10 < 0 )
        return 0;
      hexlo(a1: a3[3]);
      v11 = hexlo(a1: a3[4]);
      if ( v12 < 0 || v11 < 0 )
      {
        return 0;
      }
      else
      {
        *a2 = v11 + 16 * (v12 + 16 * (v10 + 16 * v13));
        return 5;
      }
    }
    else
    {
      return -104;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004207B0
// Name: my_wc_mb_filename
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_filename(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  _BYTE *v5; // esi
  int v6; // ecx
  unsigned __int8 v7; // dl
  _OVERLAPPED hex; // [esp+4h] [ebp-18h] BYREF

  strcpy((char *)&hex, "0123456789abcdef");
  if ( (unsigned int)wc < 0x80 && filename_safe_char[(_DWORD)wc] != 0 )
  {
    *s = (unsigned __int8)wc;
    return 1;
  }
  else if ( s + 3 <= e )
  {
    *s = 64;
    v5 = s + 1;
    if ( (unsigned int)(wc - 192) <= 0x53F
      && (v6 = (unsigned __int16)word_4CD0E0[(_DWORD)wc], word_4CD0E0[(_DWORD)wc] != 0)
      || (unsigned int)(wc - 7680) <= 0x1FF
      && (v6 = *((unsigned __int16 *)&to_upper_utf8 + (_DWORD)wc), *((_WORD *)&to_upper_utf8 + (_DWORD)wc) != 0)
      || (unsigned int)(wc - 8544) <= 0x1F
      && (v6 = *((unsigned __int16 *)&off_4C9E20 + (_DWORD)wc), *((_WORD *)&off_4C9E20 + (_DWORD)wc) != 0)
      || (unsigned int)(wc - 9392) <= 0x3F
      && (v6 = (unsigned __int16)word_4C97C0[(_DWORD)wc], word_4C97C0[(_DWORD)wc] != 0)
      || (unsigned int)(wc - 65312) <= 0x3F
      && (v6 = (unsigned __int16)word_4AE360[(_DWORD)wc], word_4AE360[(_DWORD)wc] != 0) )
    {
      *v5 = v6 / 80 + 48;
      s[2] = v6 % 80 + 48;
      return 3;
    }
    else if ( s + 6 <= e )
    {
      *v5 = *((_BYTE *)&hex.Internal + ((unsigned __int16)wc >> 12));
      s[2] = *((_BYTE *)&hex.Internal + (((unsigned int)wc >> 8) & 0xF));
      v7 = *((_BYTE *)&hex.Internal + ((unsigned __int8)wc & 0xF));
      s[3] = *((_BYTE *)&hex.Internal + ((unsigned __int8)wc >> 4));
      s[4] = v7;
      return 5;
    }
    else
    {
      return -105;
    }
  }
  else
  {
    return -103;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430420
// Name: bincmp
// Source: json
//------------------------------------------------------------------------------
DName *__usercall bincmp@<eax>(char *s@<edx>, int a2@<eax>, unsigned __int8 *a3@<ecx>, const LoggingContext_t *se)
{
  unsigned int v4; // esi
  signed int v5; // eax
  int v6; // edi
  signed int v7; // ebx
  int v8; // eax
  DName *result; // eax

  v4 = (char *)se - s;
  v5 = a2 - (_DWORD)a3;
  v6 = (char *)se - s;
  v7 = v5;
  if ( (char *)se - s >= v5 )
    v4 = v5;
  if ( v4 < 4 )
  {
LABEL_6:
    if ( v4 == 0 )
      goto LABEL_15;
  }
  else
  {
    while ( *(_DWORD *)s == *(_DWORD *)a3 )
    {
      v4 -= 4;
      a3 += 4;
      s += 4;
      if ( v4 < 4 )
        goto LABEL_6;
    }
  }
  v8 = (unsigned __int8)*s - *a3;
  if ( v8 != 0 )
    goto LABEL_14;
  if ( v4 <= 1 )
    goto LABEL_15;
  v8 = (unsigned __int8)s[1] - a3[1];
  if ( v8 != 0 )
    goto LABEL_14;
  if ( v4 <= 2 )
    goto LABEL_15;
  v8 = (unsigned __int8)s[2] - a3[2];
  if ( v8 != 0 )
  {
LABEL_14:
    result = (DName *)((v8 >> 31) | 1);
    goto LABEL_16;
  }
  if ( v4 > 3 )
  {
    v8 = (unsigned __int8)s[3] - a3[3];
    goto LABEL_14;
  }
LABEL_15:
  result = nullptr;
LABEL_16:
  if ( result == nullptr )
    return (DName *)(v6 - v7);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431E50
// Name: my_wildcmp_utf8mb3
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_wildcmp_utf8mb3(
        int a1,
        tagShutdownType a2,
        tagShutdownType a3,
        unsigned int a4,
        tagShutdownType a5,
        int a6,
        int a7,
        int a8)
{
  my_wildcmp_unicode(
    cs: (DNameStatus)a2,
    a2: (LIST_ENTRY32 *)a1,
    str: a2,
    str_end: a3,
    w_wc: a4,
    wildend: a5,
    escape: a6,
    w_one: a7,
    w_many: a8,
    weights: *(int (__stdcall **)())(a1 + 64));
}
