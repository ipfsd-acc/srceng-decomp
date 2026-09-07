// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-czech.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00439C10
// Name: my_strnncoll_czech
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_czech(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s1,
        signed int len1,
        const LoggingContext_t *s2,
        signed int len2,
        char p2)
{
  int v6; // ebp
  const LoggingContext_t *v7; // ebx
  const LoggingContext_t *v8; // esi
  signed int v9; // eax
  int v10; // ecx
  int v11; // ebp
  _BYTE *v12; // ecx
  int v13; // eax
  const LoggingContext_t *v14; // edi
  signed int v15; // esi
  int v16; // eax
  signed int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // ebp
  _BYTE *v21; // ecx
  int v22; // eax
  const LoggingContext_t *v23; // edi
  signed int v24; // esi
  int result; // eax
  const LoggingContext_t *p1; // [esp+10h] [ebp-10h]
  int pass2; // [esp+14h] [ebp-Ch]
  int pass1; // [esp+18h] [ebp-8h]
  int v1; // [esp+1Ch] [ebp-4h]
  const LoggingContext_t *p2a; // [esp+38h] [ebp+18h]
  const LoggingContext_t *p2b; // [esp+38h] [ebp+18h]

  v6 = 0;
  pass1 = 0;
  pass2 = 0;
  if ( p2 != 0 && len1 > (unsigned int)len2 )
    len1 = len2;
  v7 = s1;
  v8 = s2;
  p1 = s1;
  for ( p2a = s2; ; v8 = p2a )
  {
    v9 = (char *)v7 - (char *)s1;
    if ( (char *)v7 - (char *)s1 >= len1 )
    {
LABEL_11:
      if ( v6 == 3 )
      {
        v1 = -1;
        goto LABEL_28;
      }
      v7 = s1;
      pass1 = ++v6;
      v1 = 1;
    }
    else
    {
      v10 = (int)*(&CZ_SORT_TABLE + v6);
      while ( 1 )
      {
        v1 = *(unsigned __int8 *)(LOBYTE(v7->m_ChannelID) + v10);
        if ( *(_BYTE *)(LOBYTE(v7->m_ChannelID) + v10) != 0 )
          break;
        if ( v6 >= 3 )
          goto LABEL_26;
        ++v9;
        v7 = (const LoggingContext_t *)((char *)v7 + 1);
        if ( v9 >= len1 )
        {
          p1 = v7;
          goto LABEL_11;
        }
      }
      if ( *(unsigned __int8 *)(LOBYTE(v7->m_ChannelID) + v10) == 255 )
      {
        v11 = 0;
        while ( 1 )
        {
          v12 = *((_BYTE **)doubles + 2 * v11);
          v13 = 0;
          v14 = v7;
          if ( *v12 != 0 )
          {
            v15 = (char *)v7 - (char *)s1;
            do
            {
              if ( v15 >= len1 )
                break;
              if ( LOBYTE(v14->m_ChannelID) != v12[v13] )
                break;
              ++v13;
              v14 = (const LoggingContext_t *)((char *)v14 + 1);
              ++v15;
            }
            while ( v12[v13] != 0 );
          }
          if ( v12[v13] == 0 )
            break;
          if ( ++v11 >= 5 )
          {
            v6 = pass1;
            goto LABEL_25;
          }
        }
        v16 = (int)*(&off_58CE64 + 2 * v11);
        v6 = pass1;
        v1 = *(unsigned __int8 *)(v16 + pass1);
        v7 = (const LoggingContext_t *)((char *)v14 - 1);
LABEL_25:
        v8 = p2a;
      }
LABEL_26:
      v7 = (const LoggingContext_t *)((char *)v7 + 1);
    }
    p1 = v7;
LABEL_28:
    v17 = (char *)v8 - (char *)s2;
    if ( (char *)v8 - (char *)s2 >= len2 )
    {
LABEL_34:
      if ( pass2 == 3 )
      {
        v19 = -1;
      }
      else
      {
        v19 = 1;
        ++pass2;
        p2a = s2;
      }
    }
    else
    {
      v18 = (int)*(&CZ_SORT_TABLE + pass2);
      while ( 1 )
      {
        v19 = *(unsigned __int8 *)(LOBYTE(v8->m_ChannelID) + v18);
        if ( *(_BYTE *)(LOBYTE(v8->m_ChannelID) + v18) != 0 )
          break;
        if ( pass2 >= 3 )
        {
          p2b = v8;
          goto LABEL_51;
        }
        ++v17;
        v8 = (const LoggingContext_t *)((char *)v8 + 1);
        if ( v17 >= len2 )
        {
          p2a = v8;
          goto LABEL_34;
        }
      }
      p2b = v8;
      if ( v19 == 255 )
      {
        v20 = 0;
        while ( 1 )
        {
          v21 = *((_BYTE **)doubles + 2 * v20);
          v22 = 0;
          v23 = v8;
          if ( *v21 != 0 )
          {
            v24 = (char *)v8 - (char *)s2;
            do
            {
              if ( v24 >= len2 )
                break;
              if ( LOBYTE(v23->m_ChannelID) != v21[v22] )
                break;
              ++v22;
              v23 = (const LoggingContext_t *)((char *)v23 + 1);
              ++v24;
            }
            while ( v21[v22] != 0 );
            v7 = p1;
          }
          if ( v21[v22] == 0 )
            break;
          if ( ++v20 >= 5 )
          {
            v6 = pass1;
            goto LABEL_51;
          }
          v8 = p2b;
        }
        v19 = *((unsigned __int8 *)*(&off_58CE64 + 2 * v20) + pass2);
        v6 = pass1;
        p2b = (const LoggingContext_t *)((char *)v23 - 1);
      }
LABEL_51:
      p2a = (const LoggingContext_t *)((char *)&p2b->m_ChannelID + 1);
    }
    result = v1 - v19;
    if ( v1 != v19 )
      return result;
    if ( v1 < 0 )
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00439E10
// Name: my_strnncollsp_czech
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_czech(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        signed int slen,
        const LoggingContext_t *t,
        signed int tlen)
{
  const LoggingContext_t *v5; // esi
  const LoggingContext_t *v6; // ebx
  signed int v7; // eax
  int v8; // ecx
  int v9; // ebp
  _BYTE *v10; // ecx
  int v11; // eax
  const LoggingContext_t *v12; // edi
  signed int v13; // esi
  signed int v14; // eax
  int v15; // ecx
  int v16; // ebp
  int v17; // edx
  int v18; // ebp
  _BYTE *v19; // ecx
  int v20; // eax
  const LoggingContext_t *v21; // edi
  signed int v22; // esi
  int v23; // esi
  int result; // eax
  signed int v25; // eax
  int v26; // ecx
  int v27; // ebp
  _BYTE *v28; // ecx
  int v29; // eax
  const LoggingContext_t *v30; // edi
  signed int v31; // esi
  signed int v32; // edi
  const LoggingContext_t *v33; // edx
  signed int v34; // eax
  int v35; // ecx
  int v36; // ebp
  _BYTE *v37; // ecx
  const LoggingContext_t *v38; // edi
  int v39; // eax
  signed int v40; // esi
  int level; // [esp+10h] [ebp-10h]
  const LoggingContext_t *s1; // [esp+14h] [ebp-Ch]
  const LoggingContext_t *s1a; // [esp+14h] [ebp-Ch]
  int tval; // [esp+18h] [ebp-8h]
  int tvala; // [esp+18h] [ebp-8h]
  int tvalb; // [esp+18h] [ebp-8h]
  int sval; // [esp+1Ch] [ebp-4h]
  int svala; // [esp+1Ch] [ebp-4h]
  int svalb; // [esp+1Ch] [ebp-4h]

  level = 0;
  while ( 2 )
  {
    v5 = s;
    v6 = t;
    s1 = s;
    tval = (int)t;
    while ( 1 )
    {
      v7 = (char *)v5 - (char *)s;
      if ( (char *)v5 - (char *)s >= slen )
      {
LABEL_9:
        sval = -1;
      }
      else
      {
        v8 = (int)*(&CZ_SORT_TABLE + level);
        while ( 1 )
        {
          sval = *(unsigned __int8 *)(LOBYTE(v5->m_ChannelID) + v8);
          if ( *(_BYTE *)(LOBYTE(v5->m_ChannelID) + v8) != 0 )
            break;
          if ( level >= 3 )
            goto LABEL_22;
          ++v7;
          v5 = (const LoggingContext_t *)((char *)v5 + 1);
          if ( v7 >= slen )
          {
            s1 = v5;
            goto LABEL_9;
          }
        }
        s1a = v5;
        if ( *(unsigned __int8 *)(LOBYTE(v5->m_ChannelID) + v8) == 255 )
        {
          v9 = 0;
          while ( 1 )
          {
            v10 = *((_BYTE **)doubles + 2 * v9);
            v11 = 0;
            v12 = v5;
            if ( *v10 != 0 )
            {
              v13 = (char *)v5 - (char *)s;
              do
              {
                if ( v13 >= slen )
                  break;
                if ( LOBYTE(v12->m_ChannelID) != v10[v11] )
                  break;
                ++v11;
                v12 = (const LoggingContext_t *)((char *)v12 + 1);
                ++v13;
              }
              while ( v10[v11] != 0 );
              v5 = s1a;
            }
            if ( v10[v11] == 0 )
              break;
            if ( ++v9 >= 5 )
              goto LABEL_22;
          }
          sval = *((unsigned __int8 *)*(&off_58CE64 + 2 * v9) + level);
          v5 = (const LoggingContext_t *)((char *)v12 - 1);
        }
LABEL_22:
        s1 = (const LoggingContext_t *)((char *)&v5->m_ChannelID + 1);
      }
      v14 = (char *)v6 - (char *)t;
      if ( (char *)v6 - (char *)t >= tlen )
      {
LABEL_29:
        v16 = level;
        v17 = -1;
      }
      else
      {
        v15 = (int)*(&CZ_SORT_TABLE + level);
        v16 = level;
        while ( 1 )
        {
          v17 = *(unsigned __int8 *)(LOBYTE(v6->m_ChannelID) + v15);
          if ( *(_BYTE *)(LOBYTE(v6->m_ChannelID) + v15) != 0 )
            break;
          if ( level >= 3 )
            goto LABEL_43;
          ++v14;
          v6 = (const LoggingContext_t *)((char *)v6 + 1);
          if ( v14 >= tlen )
          {
            tval = (int)v6;
            goto LABEL_29;
          }
        }
        tvala = (int)v6;
        if ( v17 == 255 )
        {
          v18 = 0;
          while ( 1 )
          {
            v19 = *((_BYTE **)doubles + 2 * v18);
            v20 = 0;
            v21 = v6;
            if ( *v19 != 0 )
            {
              v22 = (char *)v6 - (char *)t;
              do
              {
                if ( v22 >= tlen )
                  break;
                if ( LOBYTE(v21->m_ChannelID) != v19[v20] )
                  break;
                ++v20;
                v21 = (const LoggingContext_t *)((char *)v21 + 1);
                ++v22;
              }
              while ( v19[v20] != 0 );
              v6 = (const LoggingContext_t *)tvala;
            }
            if ( v19[v20] == 0 )
              break;
            if ( ++v18 >= 5 )
              goto LABEL_42;
          }
          v17 = *((unsigned __int8 *)*(&off_58CE64 + 2 * v18) + level);
          v6 = (const LoggingContext_t *)((char *)v21 - 1);
LABEL_42:
          v16 = level;
        }
LABEL_43:
        v6 = (const LoggingContext_t *)((char *)v6 + 1);
        tval = (int)v6;
      }
      v23 = sval;
      if ( sval < 0 )
        break;
      if ( v17 < 0 )
      {
        v32 = slen;
        v33 = s1;
        tvalb = *((unsigned __int8 *)&virtual_space->m_ChannelID + v16);
        while ( 1 )
        {
          result = v23 - tvalb;
          if ( v23 != tvalb )
            return result;
          v34 = (char *)v33 - (char *)s;
          if ( (char *)v33 - (char *)s >= v32 )
            goto LABEL_91;
          v35 = (int)*(&CZ_SORT_TABLE + v16);
          while ( 1 )
          {
            v23 = *(unsigned __int8 *)(LOBYTE(v33->m_ChannelID) + v35);
            svalb = v23;
            if ( *(_BYTE *)(LOBYTE(v33->m_ChannelID) + v35) != 0 )
              break;
            if ( v16 >= 3 )
              goto LABEL_90;
            v33 = (const LoggingContext_t *)((char *)v33 + 1);
            ++v34;
            s1 = v33;
            if ( v34 >= v32 )
              goto LABEL_91;
          }
          if ( v23 == 255 )
          {
            v36 = 0;
            while ( 1 )
            {
              v37 = *((_BYTE **)doubles + 2 * v36);
              v38 = s1;
              v39 = 0;
              if ( *v37 != 0 )
              {
                v40 = (char *)s1 - (char *)s;
                do
                {
                  if ( v40 >= slen )
                    break;
                  if ( LOBYTE(v38->m_ChannelID) != v37[v39] )
                    break;
                  ++v39;
                  v38 = (const LoggingContext_t *)((char *)v38 + 1);
                  ++v40;
                }
                while ( v37[v39] != 0 );
              }
              if ( v37[v39] == 0 )
                break;
              if ( ++v36 >= 5 )
                goto LABEL_89;
            }
            svalb = *((unsigned __int8 *)*(&off_58CE64 + 2 * v36) + level);
            s1 = (const LoggingContext_t *)((char *)v38 - 1);
LABEL_89:
            v23 = svalb;
            v33 = s1;
            v16 = level;
            v32 = slen;
          }
LABEL_90:
          v33 = (const LoggingContext_t *)((char *)v33 + 1);
          s1 = v33;
        }
      }
      result = sval - v17;
      if ( sval != v17 )
        return result;
      v5 = s1;
    }
    svala = *((unsigned __int8 *)&virtual_space->m_ChannelID + v16);
    if ( v17 < 0 )
    {
LABEL_91:
      level = v16 + 1;
      if ( v16 + 1 <= 3 )
        continue;
      return 0;
    }
    else
    {
      while ( 1 )
      {
        result = svala - v17;
        if ( svala != v17 )
          break;
        v25 = (char *)v6 - (char *)t;
        if ( (char *)v6 - (char *)t >= tlen )
          goto LABEL_91;
        v26 = (int)*(&CZ_SORT_TABLE + v16);
        while ( 1 )
        {
          v17 = *(unsigned __int8 *)(LOBYTE(v6->m_ChannelID) + v26);
          if ( *(_BYTE *)(LOBYTE(v6->m_ChannelID) + v26) != 0 )
            break;
          if ( v16 >= 3 )
            goto LABEL_69;
          v6 = (const LoggingContext_t *)((char *)v6 + 1);
          ++v25;
          tval = (int)v6;
          if ( v25 >= tlen )
            goto LABEL_91;
        }
        if ( v17 == 255 )
        {
          v27 = 0;
          while ( 1 )
          {
            v28 = *((_BYTE **)doubles + 2 * v27);
            v29 = 0;
            v30 = v6;
            if ( *v28 != 0 )
            {
              v31 = (char *)v6 - (char *)t;
              do
              {
                if ( v31 >= tlen )
                  break;
                if ( LOBYTE(v30->m_ChannelID) != v28[v29] )
                  break;
                ++v29;
                v30 = (const LoggingContext_t *)((char *)v30 + 1);
                ++v31;
              }
              while ( v28[v29] != 0 );
              v6 = (const LoggingContext_t *)tval;
            }
            if ( v28[v29] == 0 )
              break;
            if ( ++v27 >= 5 )
              goto LABEL_68;
          }
          v17 = *((unsigned __int8 *)*(&off_58CE64 + 2 * v27) + level);
          v6 = (const LoggingContext_t *)((char *)v30 - 1);
LABEL_68:
          v16 = level;
        }
LABEL_69:
        v6 = (const LoggingContext_t *)((char *)v6 + 1);
        tval = (int)v6;
      }
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A180
// Name: my_strnxfrmlen_czech
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strnxfrmlen_czech(LIST_ENTRY32 *cs, unsigned int len)
{
  return 4 * len + 4;
}

//------------------------------------------------------------------------------
// Address: 0x0043A190
// Name: my_strnxfrm_czech
// Source: json
//------------------------------------------------------------------------------
int __usercall my_strnxfrm_czech@<eax>(
        __int128 a1@<xmm0>,
        int a2,
        unsigned __int8 *dst,
        int a4,
        int a5,
        int a6,
        int a7,
        unsigned int flags)
{
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // ecx
  unsigned __int8 *v12; // ebp
  int v13; // eax
  int v14; // ecx
  unsigned int v15; // esi
  int v17; // edx
  _BYTE *v18; // ecx
  int v19; // eax
  _BYTE *v20; // edi
  int v21; // esi
  int v22; // [esp+8h] [ebp-14h]
  int v23; // [esp+Ch] [ebp-10h]
  unsigned __int8 *v24; // [esp+10h] [ebp-Ch]
  unsigned __int8 *str; // [esp+14h] [ebp-8h]
  unsigned __int8 *v26; // [esp+18h] [ebp-4h]
  unsigned int v27; // [esp+28h] [ebp+Ch]

  v8 = dst;
  v9 = &dst[a4];
  v26 = dst;
  v24 = &dst[a4];
  if ( (flags & 0xF) == 0 )
    flags |= 0xFu;
  v10 = 0;
  v27 = 0;
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
          v14 = (int)*(&CZ_SORT_TABLE + v10);
          while ( 1 )
          {
            v23 = *(unsigned __int8 *)(*v12 + v14);
            if ( *(_BYTE *)(*v12 + v14) != 0 )
              break;
            if ( v27 >= 3 )
              goto LABEL_38;
            ++v13;
            ++v12;
            if ( v13 >= a7 )
            {
              v10 = v27;
              v11 = v22;
              goto LABEL_13;
            }
          }
          if ( v23 == 255 )
          {
            v17 = 0;
            while ( 1 )
            {
              v18 = *((_BYTE **)doubles + 2 * v17);
              v19 = 0;
              v20 = v12;
              if ( *v18 != 0 )
              {
                v21 = (int)&v12[-a6];
                do
                {
                  if ( v21 >= a7 )
                    break;
                  if ( *v20 != v18[v19] )
                    break;
                  ++v19;
                  ++v20;
                  ++v21;
                }
                while ( v18[v19] != 0 );
                v8 = dst;
              }
              if ( v18[v19] == 0 )
                break;
              if ( ++v17 >= 5 )
                goto LABEL_38;
            }
            LOBYTE(v23) = *((_BYTE *)*(&off_58CE64 + 2 * v17) + v27);
            v12 = v20 - 1;
          }
LABEL_38:
          ++v12;
          --v22;
          v10 = v27;
          *v8++ = v23;
          dst = v8;
          if ( v8 >= v24 )
            goto LABEL_19;
          v11 = v22;
        }
LABEL_13:
        if ( v8 < v24 && v11 != 0 && (flags & 0x40) != 0 )
        {
          v15 = v24 - v8;
          if ( v24 - v8 > v11 )
            v15 = v11;
          memset(a1, dst: (int)v8, value: *((_BYTE *)&virtual_space->m_ChannelID + v10), count: v15);
          v8 += v15;
          dst = v8;
        }
      }
LABEL_19:
      my_strxfrm_desc_and_reverse(str, strend: v8, flags, level: v10);
      v9 = v24;
      if ( v8 < v24 )
      {
        *v8++ = v10 < 3;
        dst = v8;
      }
    }
    v27 = ++v10;
  }
  while ( v10 <= 3 );
  if ( (flags & 0x80u) != 0 && v8 < v9 )
  {
    (*(void (__cdecl **)(int, unsigned __int8 *, int, _DWORD))(*(_DWORD *)(a2 + 100) + 72))(
      a1: a2,
      a2: v8,
      a3: v9 - v8,
      a4: 0);
    v8 = v9;
  }
  return v8 - v26;
}

//------------------------------------------------------------------------------
// Address: 0x0043A380
// Name: my_like_range_czech
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_czech(
        LIST_ENTRY32 *a1,
        tagShutdownType ptr,
        char *min_end,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        char *min_org,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // ecx
  char *v13; // edi
  char *v14; // eax
  char *v15; // ebx
  int v16; // edx
  char v17; // dl
  unsigned __int8 v18; // bl
  tagShutdownType ptra; // [esp+18h] [ebp+8h]

  v11 = (char *)ptr;
  v13 = &min_end[ptr];
  v14 = min_org;
  v15 = &min_org[res_length];
  if ( (char *)ptr != &min_end[ptr] )
  {
    ptra = ptr + 1;
    while ( v14 != v15 )
    {
      v16 = *v11;
      if ( v16 == w_one || v16 == w_many )
        break;
      if ( v16 == escape && (char *)ptra != v13 )
      {
        ++v11;
        ++ptra;
      }
      v17 = *v11;
      v18 = *((_BYTE *)CZ_SORT_TABLE + (unsigned __int8)*v11);
      if ( v18 != 0 )
      {
        if ( v18 <= 2u || v18 == 0xFF )
        {
LABEL_15:
          v15 = &min_org[res_length];
          break;
        }
        *max_str = v17;
        *v14++ = v17;
        ++max_str;
      }
      ++ptra;
      if ( ++v11 == v13 )
        goto LABEL_15;
      v15 = &min_org[res_length];
    }
  }
  if ( (a1[1].Blink & 0x10) != 0 )
    *min_length = v14 - min_org;
  else
    *min_length = res_length;
  for ( *max_length = res_length; v14 != v15; ++max_str )
  {
    *v14++ = 0;
    *max_str = -82;
  }
  return 0;
}
