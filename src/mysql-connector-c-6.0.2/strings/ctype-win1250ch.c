// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-win1250ch.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0043A460
// Name: my_strnncoll_win1250ch
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_win1250ch(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s1,
        signed int len1,
        const LoggingContext_t *s2,
        signed int len2,
        char p2)
{
  int v6; // edx
  int v7; // edi
  const LoggingContext_t *v8; // eax
  const LoggingContext_t *v9; // ebp
  char *v10; // ecx
  char v11; // al
  const LoggingContext_t *v12; // esi
  signed int v13; // edx
  int v14; // ebx
  int v15; // edi
  char *v16; // ecx
  char v17; // al
  const LoggingContext_t *v18; // esi
  signed int v19; // edx
  int result; // eax
  int v1; // [esp+10h] [ebp-10h]
  const LoggingContext_t *p1; // [esp+14h] [ebp-Ch]
  int pass2; // [esp+18h] [ebp-8h]
  int pass1; // [esp+1Ch] [ebp-4h]
  const LoggingContext_t *p2a; // [esp+38h] [ebp+18h]

  v6 = 0;
  v7 = 0;
  pass1 = 0;
  pass2 = 0;
  if ( p2 != 0 && len1 > (unsigned int)len2 )
    len1 = len2;
  v8 = s1;
  v9 = s1;
  p1 = s1;
  p2a = s2;
  while ( 1 )
  {
    if ( (char *)v9 - (char *)v8 < len1 )
    {
      if ( v6 == 0 )
      {
        v1 = *((unsigned __int8 *)&sort_order_win1250ch1 + LOBYTE(v9->m_ChannelID));
        goto LABEL_10;
      }
    }
    else
    {
      if ( v6 != 0 || len1 <= 0 )
      {
        v1 = 0;
        goto LABEL_27;
      }
      v9 = v8;
      pass1 = 1;
    }
    v1 = *((unsigned __int8 *)&sort_order_win1250ch2 + LOBYTE(v9->m_ChannelID));
LABEL_10:
    if ( v1 == 255 )
    {
      while ( 1 )
      {
        v10 = *((char **)doubles_0 + 2 * v7);
        v11 = *v10;
        v12 = v9;
        if ( *v10 == 0 )
          break;
        v13 = (char *)v9 - (char *)s1;
        while ( v13 < len1 && v11 == LOBYTE(v12->m_ChannelID) )
        {
          v11 = *++v10;
          v12 = (const LoggingContext_t *)((char *)v12 + 1);
          ++v13;
          if ( v11 == 0 )
            goto LABEL_16;
        }
        if ( *v10 == 0 )
          break;
        if ( ++v7 >= 5 )
          goto LABEL_26;
      }
LABEL_16:
      if ( pass1 != 0 )
        v1 = (unsigned __int8)byte_58E15D[8 * v7];
      else
        v1 = (unsigned __int8)byte_58E15C[8 * v7];
      v9 = (const LoggingContext_t *)((char *)v12 - 1);
    }
LABEL_26:
    v9 = (const LoggingContext_t *)((char *)v9 + 1);
    p1 = v9;
LABEL_27:
    if ( (char *)p2a - (char *)s2 < len2 )
    {
      if ( pass2 == 0 )
      {
        v14 = *((unsigned __int8 *)&sort_order_win1250ch1 + LOBYTE(p2a->m_ChannelID));
        goto LABEL_32;
      }
    }
    else
    {
      if ( pass2 != 0 || len2 <= 0 )
      {
        v14 = 0;
        goto LABEL_51;
      }
      p2a = s2;
      pass2 = 1;
    }
    v14 = *((unsigned __int8 *)&sort_order_win1250ch2 + LOBYTE(p2a->m_ChannelID));
LABEL_32:
    if ( v14 == 255 )
    {
      v15 = 0;
      while ( 1 )
      {
        v16 = *((char **)doubles_0 + 2 * v15);
        v17 = *v16;
        v18 = p2a;
        if ( *v16 == 0 )
          break;
        v19 = (char *)p2a - (char *)s2;
        while ( v19 < len2 && v17 == LOBYTE(v18->m_ChannelID) )
        {
          v17 = *++v16;
          v18 = (const LoggingContext_t *)((char *)v18 + 1);
          ++v19;
          if ( v17 == 0 )
          {
            v9 = p1;
            goto LABEL_40;
          }
        }
        v9 = p1;
        if ( *v16 == 0 )
          break;
        if ( ++v15 >= 5 )
          goto LABEL_50;
      }
LABEL_40:
      if ( pass2 != 0 )
        v14 = (unsigned __int8)byte_58E15D[8 * v15];
      else
        v14 = (unsigned __int8)byte_58E15C[8 * v15];
      p2a = (const LoggingContext_t *)((char *)v18 - 1);
    }
LABEL_50:
    p2a = (const LoggingContext_t *)((char *)p2a + 1);
LABEL_51:
    result = v1 - v14;
    if ( v1 != v14 )
      return result;
    v7 = 0;
    if ( v1 == 0 )
      return 0;
    v6 = pass1;
    v8 = s1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A640
// Name: my_strnncollsp_win1250ch
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_win1250ch(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        signed int slen,
        const LoggingContext_t *t,
        signed int tlen)
{
  const LoggingContext_t *v5; // ebx
  int v6; // eax
  int v7; // edi
  char *v8; // ecx
  char v9; // al
  const LoggingContext_t *v10; // edx
  signed int v11; // esi
  int v12; // ebx
  int v13; // edi
  char *v14; // ecx
  char v15; // al
  const LoggingContext_t *v16; // edx
  signed int v17; // esi
  int v18; // eax
  int result; // eax
  int v20; // edi
  char *v21; // ecx
  char v22; // al
  const LoggingContext_t *v23; // edx
  signed int v24; // esi
  int v25; // ebx
  int v26; // eax
  int v27; // edi
  char *v28; // ecx
  char v29; // al
  const LoggingContext_t *v30; // edx
  signed int v31; // esi
  const LoggingContext_t *t1; // [esp+10h] [ebp-10h]
  int sval; // [esp+14h] [ebp-Ch]
  int svala; // [esp+14h] [ebp-Ch]
  int svalb; // [esp+14h] [ebp-Ch]
  int level; // [esp+18h] [ebp-8h]
  const LoggingContext_t *s1; // [esp+1Ch] [ebp-4h]

  level = 0;
  while ( 2 )
  {
    v5 = s;
    s1 = s;
    t1 = t;
    while ( 1 )
    {
      if ( (char *)v5 - (char *)s < slen )
      {
        if ( level != 0 )
          v6 = *((unsigned __int8 *)&sort_order_win1250ch2 + LOBYTE(v5->m_ChannelID));
        else
          v6 = *((unsigned __int8 *)&sort_order_win1250ch1 + LOBYTE(v5->m_ChannelID));
        sval = v6;
        if ( v6 == 255 )
        {
          v7 = 0;
          while ( 1 )
          {
            v8 = *((char **)doubles_0 + 2 * v7);
            v9 = *v8;
            v10 = v5;
            if ( *v8 == 0 )
              break;
            v11 = (char *)v5 - (char *)s;
            while ( v11 < slen && v9 == LOBYTE(v10->m_ChannelID) )
            {
              v9 = *++v8;
              v10 = (const LoggingContext_t *)((char *)v10 + 1);
              ++v11;
              if ( v9 == 0 )
                goto LABEL_15;
            }
            if ( *v8 == 0 )
              break;
            if ( ++v7 >= 5 )
              goto LABEL_22;
          }
LABEL_15:
          if ( level != 0 )
            sval = (unsigned __int8)byte_58E15D[8 * v7];
          else
            sval = (unsigned __int8)byte_58E15C[8 * v7];
          v5 = (const LoggingContext_t *)((char *)v10 - 1);
        }
LABEL_22:
        s1 = (const LoggingContext_t *)((char *)&v5->m_ChannelID + 1);
      }
      else
      {
        sval = 0;
      }
      if ( (char *)t1 - (char *)t < tlen )
      {
        if ( level != 0 )
          v12 = *((unsigned __int8 *)&sort_order_win1250ch2 + LOBYTE(t1->m_ChannelID));
        else
          v12 = *((unsigned __int8 *)&sort_order_win1250ch1 + LOBYTE(t1->m_ChannelID));
        if ( v12 == 255 )
        {
          v13 = 0;
          while ( 1 )
          {
            v14 = *((char **)doubles_0 + 2 * v13);
            v15 = *v14;
            v16 = t1;
            if ( *v14 == 0 )
              break;
            v17 = (char *)t1 - (char *)t;
            while ( v17 < tlen && v15 == LOBYTE(v16->m_ChannelID) )
            {
              v15 = *++v14;
              v16 = (const LoggingContext_t *)((char *)v16 + 1);
              ++v17;
              if ( v15 == 0 )
                goto LABEL_35;
            }
            if ( *v14 == 0 )
              break;
            if ( ++v13 >= 5 )
              goto LABEL_42;
          }
LABEL_35:
          if ( level != 0 )
            v12 = (unsigned __int8)byte_58E15D[8 * v13];
          else
            v12 = (unsigned __int8)byte_58E15C[8 * v13];
          t1 = (const LoggingContext_t *)((char *)v16 - 1);
        }
LABEL_42:
        t1 = (const LoggingContext_t *)((char *)t1 + 1);
      }
      else
      {
        v12 = 0;
      }
      v18 = sval;
      if ( sval == 0 )
        break;
      if ( v12 == 0 )
      {
        if ( level != 0 )
          v25 = loc_58E078;
        else
          v25 = *(&loc_58DF76 + 2);
        while ( 1 )
        {
          result = v18 - v25;
          if ( result != 0 )
            return result;
          if ( (char *)s1 - (char *)s >= slen )
            goto LABEL_96;
          if ( level != 0 )
            v26 = *((unsigned __int8 *)&sort_order_win1250ch2 + LOBYTE(s1->m_ChannelID));
          else
            v26 = *((unsigned __int8 *)&sort_order_win1250ch1 + LOBYTE(s1->m_ChannelID));
          svalb = v26;
          if ( v26 == 255 )
          {
            v27 = 0;
            while ( 1 )
            {
              v28 = *((char **)doubles_0 + 2 * v27);
              v29 = *v28;
              v30 = s1;
              if ( *v28 == 0 )
                break;
              v31 = (char *)s1 - (char *)s;
              while ( v31 < slen && v29 == LOBYTE(v30->m_ChannelID) )
              {
                v29 = *++v28;
                v30 = (const LoggingContext_t *)((char *)v30 + 1);
                ++v31;
                if ( v29 == 0 )
                  goto LABEL_88;
              }
              if ( *v28 == 0 )
                break;
              if ( ++v27 >= 5 )
                goto LABEL_95;
            }
LABEL_88:
            if ( level != 0 )
              svalb = (unsigned __int8)byte_58E15D[8 * v27];
            else
              svalb = (unsigned __int8)byte_58E15C[8 * v27];
            s1 = (const LoggingContext_t *)((char *)v30 - 1);
          }
LABEL_95:
          s1 = (const LoggingContext_t *)((char *)s1 + 1);
          if ( svalb == 0 )
            goto LABEL_96;
          v18 = svalb;
        }
      }
      result = sval - v12;
      if ( sval != v12 )
        return result;
      v5 = s1;
    }
    if ( level != 0 )
      svala = loc_58E078;
    else
      svala = *(&loc_58DF76 + 2);
    if ( v12 != 0 )
    {
      while ( 1 )
      {
        result = svala - v12;
        if ( svala != v12 )
          break;
        if ( (char *)t1 - (char *)t < tlen )
        {
          if ( level == result )
            v12 = *((unsigned __int8 *)&sort_order_win1250ch1 + LOBYTE(t1->m_ChannelID));
          else
            v12 = *((unsigned __int8 *)&sort_order_win1250ch2 + LOBYTE(t1->m_ChannelID));
          if ( v12 == 255 )
          {
            v20 = 0;
            while ( 1 )
            {
              v21 = *((char **)doubles_0 + 2 * v20);
              v22 = *v21;
              v23 = t1;
              if ( *v21 == 0 )
                break;
              v24 = (char *)t1 - (char *)t;
              while ( v24 < tlen && v22 == LOBYTE(v23->m_ChannelID) )
              {
                v22 = *++v21;
                v23 = (const LoggingContext_t *)((char *)v23 + 1);
                ++v24;
                if ( v22 == 0 )
                  goto LABEL_63;
              }
              if ( *v21 == 0 )
                break;
              if ( ++v20 >= 5 )
                goto LABEL_70;
            }
LABEL_63:
            if ( level != 0 )
              v12 = (unsigned __int8)byte_58E15D[8 * v20];
            else
              v12 = (unsigned __int8)byte_58E15C[8 * v20];
            t1 = (const LoggingContext_t *)((char *)v23 - 1);
          }
LABEL_70:
          t1 = (const LoggingContext_t *)((char *)t1 + 1);
          if ( v12 != 0 )
            continue;
        }
        goto LABEL_96;
      }
    }
    else
    {
LABEL_96:
      if ( ++level <= 3 )
        continue;
      return 0;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A990
// Name: my_strnxfrm_win1250ch
// Source: json
//------------------------------------------------------------------------------
int __usercall my_strnxfrm_win1250ch@<eax>(
        __int128 a1@<xmm0>,
        int a2,
        unsigned __int8 *dst,
        unsigned int level,
        int a5,
        int a6,
        int a7,
        unsigned int flags)
{
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned __int8 *v12; // ebp
  int v13; // esi
  int v14; // ecx
  unsigned __int8 *v15; // edx
  int v16; // edi
  char *v17; // ecx
  char v18; // al
  _BYTE *v19; // edx
  unsigned int v20; // esi
  int v22; // [esp+8h] [ebp-14h]
  unsigned __int8 *v23; // [esp+Ch] [ebp-10h]
  unsigned __int8 *str; // [esp+14h] [ebp-8h]
  unsigned __int8 *dsta; // [esp+24h] [ebp+8h]
  unsigned int levela; // [esp+28h] [ebp+Ch]

  v8 = dst;
  v9 = &dst[level];
  v23 = &dst[level];
  if ( (flags & 3) == 0 )
    flags |= 3u;
  v10 = 0;
  levela = 0;
  do
  {
    if ( ((1 << v10) & flags) != 0 )
    {
      v11 = a5;
      v12 = (unsigned __int8 *)a6;
      v22 = a5;
      str = v8;
      if ( v8 < v9 )
      {
        while ( v11 != 0 )
        {
          v13 = (int)&v12[-a6];
          if ( (int)&v12[-a6] >= a7 )
            break;
          v14 = *v12;
          if ( levela != 0 )
            v15 = (unsigned __int8 *)*((unsigned __int8 *)&sort_order_win1250ch2 + v14);
          else
            v15 = (unsigned __int8 *)*((unsigned __int8 *)&sort_order_win1250ch1 + v14);
          dsta = v15;
          if ( v15 == (unsigned __int8 *)255 )
          {
            v16 = 0;
            while ( 1 )
            {
              v17 = *((char **)doubles_0 + 2 * v16);
              v18 = *v17;
              v19 = v12;
              if ( *v17 == 0 )
                break;
              while ( v13 < a7 && v18 == *v19 )
              {
                v18 = *++v17;
                ++v19;
                ++v13;
                if ( v18 == 0 )
                  goto LABEL_17;
              }
              if ( *v17 == 0 )
                break;
              if ( ++v16 >= 5 )
                goto LABEL_24;
              v13 = (int)&v12[-a6];
            }
LABEL_17:
            if ( levela != 0 )
              dsta = (unsigned __int8 *)(unsigned __int8)byte_58E15D[8 * v16];
            else
              dsta = (unsigned __int8 *)(unsigned __int8)byte_58E15C[8 * v16];
            v12 = v19 - 1;
LABEL_24:
            v11 = v22;
            v9 = v23;
          }
          ++v12;
          if ( dsta == nullptr )
            break;
          *v8++ = (unsigned __int8)dsta;
          v22 = --v11;
          if ( v8 >= v9 )
            goto LABEL_34;
        }
        if ( v8 < v9 && v11 != 0 && (flags & 0x40) != 0 )
        {
          v20 = v9 - v8;
          if ( v9 - v8 > v11 )
            v20 = v11;
          memset(a1, dst: (int)v8, value: levela != 0 ? 1 : -126, count: v20);
          v8 += v20;
        }
      }
LABEL_34:
      v10 = levela;
      my_strxfrm_desc_and_reverse(str, strend: v8, flags, level: levela);
    }
    levela = ++v10;
  }
  while ( v10 <= 1 );
  if ( (flags & 0x80u) != 0 && v8 < v9 )
  {
    (*(void (__cdecl **)(int, unsigned __int8 *, int, _DWORD))(*(_DWORD *)(a2 + 100) + 72))(
      a1: a2,
      a2: v8,
      a3: v9 - v8,
      a4: 0);
    v8 = v9;
  }
  return v8 - dst;
}

//------------------------------------------------------------------------------
// Address: 0x0043AB50
// Name: my_like_range_win1250ch
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_win1250ch(
        LIST_ENTRY32 *a1,
        char *min_end,
        char *min_org,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        char *min_str,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // edx
  char *v12; // ecx
  char *v14; // ebp
  char *v15; // edi
  char *v16; // eax
  int v17; // edi
  char v18; // bl
  char only_min_found; // [esp+Ch] [ebp-4h]

  v11 = min_end;
  v12 = min_str;
  v14 = &min_org[(_DWORD)min_end];
  v15 = &min_str[res_length];
  only_min_found = 1;
  if ( min_end != &min_org[(_DWORD)min_end] )
  {
    v16 = min_end + 1;
    while ( v12 != v15 )
    {
      v17 = *v11;
      if ( v17 != escape || v16 == v14 )
      {
        if ( v17 == w_one || v17 == w_many )
          goto LABEL_13;
      }
      else
      {
        ++v11;
        ++v16;
      }
      v18 = *((_BYTE *)&like_range_prefix_min_win1250ch + (unsigned __int8)*v11);
      *v12 = v18;
      if ( v18 != 32 )
        only_min_found = 0;
      *max_str = *((_BYTE *)&like_range_prefix_max_win1250ch + (unsigned __int8)*v11++);
      ++v12;
      ++max_str;
      ++v16;
      if ( v11 == v14 )
      {
LABEL_13:
        v15 = &min_str[res_length];
        break;
      }
      v15 = &min_str[res_length];
    }
  }
  if ( (a1[1].Blink & 0x10) != 0 )
    *min_length = v12 - min_str;
  else
    *min_length = res_length;
  for ( *max_length = res_length; v12 != v15; ++max_str )
  {
    *v12++ = 32;
    *max_str = -1;
  }
  return only_min_found;
}
