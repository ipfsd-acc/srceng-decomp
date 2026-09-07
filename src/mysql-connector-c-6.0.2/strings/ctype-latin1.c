// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-latin1.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00411060
// Name: my_mb_wc_latin1
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_latin1(int a1, _DWORD *a2, _BYTE *a3, unsigned int a4)
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
// Address: 0x004110A0
// Name: my_wc_mb_latin1
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_latin1(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *str, unsigned __int8 *end, ...)
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

//------------------------------------------------------------------------------
// Address: 0x004110F0
// Name: my_strnncoll_latin1_de
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_latin1_de(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *b_end,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length,
        char b_is_prefix)
{
  const LoggingContext_t *v6; // esi
  const LoggingContext_t *v7; // edi
  const LoggingContext_t *v8; // ebp
  const LoggingContext_t *v9; // eax
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // dl
  unsigned __int8 v12; // bl
  int m_ChannelID_low; // eax
  unsigned __int8 v14; // al
  int v15; // eax

  v6 = b_end;
  v7 = b;
  v8 = (const LoggingContext_t *)((char *)b_end + a_length);
  v9 = (const LoggingContext_t *)((char *)b + b_length);
  v10 = 0;
  v11 = 0;
  while ( (v6 < v8 || v10 != 0) && (v7 < v9 || v11 != 0) )
  {
    if ( v10 != 0 )
    {
      v12 = v10;
      v10 = 0;
    }
    else
    {
      m_ChannelID_low = LOBYTE(v6->m_ChannelID);
      v10 = *((_BYTE *)&loc_4906F6 + m_ChannelID_low + 2);
      v12 = combo1map[m_ChannelID_low];
      v6 = (const LoggingContext_t *)((char *)v6 + 1);
    }
    if ( v11 != 0 )
    {
      v14 = v11;
      v11 = 0;
    }
    else
    {
      v15 = LOBYTE(v7->m_ChannelID);
      v11 = *((_BYTE *)&loc_4906F6 + v15 + 2);
      v14 = combo1map[v15];
      v7 = (const LoggingContext_t *)((char *)v7 + 1);
    }
    if ( v12 != v14 )
      return v12 - v14;
    v9 = (const LoggingContext_t *)((char *)b + b_length);
  }
  if ( v6 < v8 || v10 != 0 )
    return b_is_prefix == 0;
  if ( v7 < v9 || v11 != 0 )
    return -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004111A0
// Name: my_strnncollsp_latin1_de
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_latin1_de(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *a_extend,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length)
{
  const LoggingContext_t *v5; // eax
  const LoggingContext_t *v6; // esi
  const LoggingContext_t *v7; // edi
  unsigned __int8 *v8; // ebp
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  unsigned __int8 v11; // bl
  int m_ChannelID_low; // ecx
  unsigned __int8 v13; // cl
  int v14; // ecx
  int v16; // ecx
  bool v17; // cf
  unsigned __int8 a_extenda; // [esp+18h] [ebp+8h]

  v5 = a_extend;
  v6 = b;
  v7 = (const LoggingContext_t *)((char *)a_extend + a_length);
  v8 = (unsigned __int8 *)b + b_length;
  v9 = 0;
  v10 = 0;
  while ( v5 < v7 || v9 != 0 )
  {
    if ( v6 >= (const LoggingContext_t *)v8 && v10 == 0 )
    {
      if ( v9 != 0 )
        return 1;
      goto LABEL_18;
    }
    if ( v9 != 0 )
    {
      v11 = v9;
      a_extenda = 0;
    }
    else
    {
      m_ChannelID_low = LOBYTE(v5->m_ChannelID);
      a_extenda = *((_BYTE *)&loc_4906F6 + m_ChannelID_low + 2);
      v11 = combo1map[m_ChannelID_low];
      v5 = (const LoggingContext_t *)((char *)v5 + 1);
    }
    if ( v10 != 0 )
    {
      v13 = v10;
      v10 = 0;
    }
    else
    {
      v14 = LOBYTE(v6->m_ChannelID);
      v10 = *((_BYTE *)&loc_4906F6 + v14 + 2);
      v13 = combo1map[v14];
      v6 = (const LoggingContext_t *)((char *)v6 + 1);
    }
    if ( v11 != v13 )
      return v11 - v13;
    v9 = a_extenda;
  }
  if ( v10 != 0 )
    return -1;
LABEL_18:
  if ( v5 == v7 && v6 == (const LoggingContext_t *)v8 )
    return 0;
  v16 = 1;
  v17 = v5 < v7;
  if ( v5 == v7 )
  {
    v7 = (const LoggingContext_t *)((char *)b + b_length);
    v5 = v6;
    v16 = -1;
    v17 = v6 < (const LoggingContext_t *)v8;
  }
  if ( !v17 )
    return 0;
  while ( LOBYTE(v5->m_ChannelID) == 32 )
  {
    v5 = (const LoggingContext_t *)((char *)v5 + 1);
    if ( v5 >= v7 )
      return 0;
  }
  if ( LOBYTE(v5->m_ChannelID) < 0x20u )
    return -v16;
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x00411280
// Name: my_strnxfrm_latin1_de
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_latin1_de(
        int a1,
        unsigned __int8 *str,
        int a3,
        unsigned int a4,
        unsigned __int8 *a5,
        int a6,
        unsigned int flags)
{
  unsigned __int8 *v7; // eax
  unsigned __int8 *v9; // ebp
  unsigned __int8 *i; // ecx
  unsigned __int8 v11; // dl

  v7 = str;
  v9 = &str[a3];
  for ( i = a5; i < &a5[a6]; --a4 )
  {
    if ( v7 >= v9 || a4 == 0 )
      break;
    *v7 = combo1map[*i];
    v11 = *((_BYTE *)&loc_4906F6 + *i + 2);
    ++v7;
    if ( v11 != 0 && v7 < v9 && a4 > 1 )
    {
      *v7++ = v11;
      --a4;
    }
    ++i;
  }
  return my_strxfrm_pad_desc_and_reverse(a1, str, strend: v7, a4: (int)v9, a5: a4, flags, level: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00411300
// Name: _my_hash_sort_latin1_de
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_hash_sort_latin1_de(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *end,
        unsigned int len,
        unsigned int *nr1,
        unsigned int *nr2)
{
  unsigned int result; // eax
  int m_ChannelID_low; // edx
  const LoggingContext_t *enda; // [esp+Ch] [ebp+8h]

  result = skip_trailing_space();
  for ( enda = (const LoggingContext_t *)result;
        (unsigned int)end < result;
        end = (const LoggingContext_t *)((char *)end + 1) )
  {
    *nr1 ^= (*nr1 << 8) + (*nr2 + (*nr1 & 0x3F)) * (unsigned __int8)combo1map[LOBYTE(end->m_ChannelID)];
    *nr2 += 3;
    m_ChannelID_low = LOBYTE(end->m_ChannelID);
    if ( *((_BYTE *)&loc_4906F6 + m_ChannelID_low + 2) != 0 )
    {
      *nr1 ^= (*nr1 << 8) + *((unsigned __int8 *)&loc_4906F6 + m_ChannelID_low + 2) * (*nr2 + (*nr1 & 0x3F));
      *nr2 += 3;
      result = (unsigned int)enda;
    }
  }
  return result;
}
