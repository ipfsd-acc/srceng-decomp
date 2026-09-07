// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype.c
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041BFE0
// Name: mstr
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall mstr@<eax>(
        unsigned __int8 *str@<edi>,
        unsigned int l1@<ecx>,
        unsigned int a3@<eax>,
        long double src)
{
  unsigned int v4; // esi

  v4 = l1;
  if ( l1 >= a3 )
    v4 = a3;
  memcpy(dst: str, src: (unsigned __int8 *)LODWORD(src), count: v4);
  str[v4] = 0;
  return str;
}

//------------------------------------------------------------------------------
// Address: 0x0041C000
// Name: cs_file_sec
// Source: json
//------------------------------------------------------------------------------
char *__usercall cs_file_sec@<eax>(const char *a1@<ebx>, unsigned int a2@<edi>)
{
  char *v2; // esi

  v2 = (char *)&sec;
  if ( off_49129C == nullptr )
    return nullptr;
  while ( strncmp(first: a1, last: *((const char **)v2 + 1), count: a2) != 0 )
  {
    v2 += 8;
    if ( *((_DWORD *)v2 + 1) == 0 )
      return nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0041C040
// Name: fill_uchar
// Source: json
//------------------------------------------------------------------------------
int __usercall fill_uchar@<eax>(char *nptr@<ecx>, int a2@<eax>, unsigned __int8 *a, unsigned int size)
{
  unsigned __int8 *v4; // esi
  char *v5; // edi
  unsigned int v6; // ebx
  int v7; // eax
  const char *v8; // ebp
  int v9; // eax

  v4 = (unsigned __int8 *)nptr;
  v5 = &nptr[a2];
  v6 = 0;
  if ( nptr < &nptr[a2] )
  {
    do
    {
      do
      {
        strchr(string: " \t\r\n", chr: *v4);
        if ( v7 == 0 )
          break;
        ++v4;
      }
      while ( v4 < (unsigned __int8 *)v5 );
      v8 = (const char *)v4;
      if ( v4 >= (unsigned __int8 *)v5 )
        break;
      do
      {
        strchr(string: " \t\r\n", chr: *v4);
        if ( v9 != 0 )
          break;
        ++v4;
      }
      while ( v4 < (unsigned __int8 *)v5 );
      if ( v4 == (unsigned __int8 *)v8 )
        break;
      if ( v6 > size )
        break;
      a[v6++] = strtoul(nptr: v8, endptr: nullptr, ibase: 16);
    }
    while ( v4 < (unsigned __int8 *)v5 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C0C0
// Name: fill_uint16
// Source: json
//------------------------------------------------------------------------------
int __usercall fill_uint16@<eax>(char *nptr@<ecx>, int a2@<eax>, unsigned __int16 *a, unsigned int size)
{
  unsigned __int8 *v4; // esi
  char *v5; // edi
  unsigned int v6; // ebx
  int v7; // eax
  const char *v8; // ebp
  int v9; // eax

  v4 = (unsigned __int8 *)nptr;
  v5 = &nptr[a2];
  v6 = 0;
  if ( nptr < &nptr[a2] )
  {
    do
    {
      do
      {
        strchr(string: " \t\r\n", chr: *v4);
        if ( v7 == 0 )
          break;
        ++v4;
      }
      while ( v4 < (unsigned __int8 *)v5 );
      v8 = (const char *)v4;
      if ( v4 >= (unsigned __int8 *)v5 )
        break;
      do
      {
        strchr(string: " \t\r\n", chr: *v4);
        if ( v9 != 0 )
          break;
        ++v4;
      }
      while ( v4 < (unsigned __int8 *)v5 );
      if ( v4 == (unsigned __int8 *)v8 )
        break;
      if ( v6 > size )
        break;
      a[v6++] = strtol(nptr: v8, endptr: nullptr, ibase: 16);
    }
    while ( v4 < (unsigned __int8 *)v5 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C140
// Name: cs_enter
// Source: json
//------------------------------------------------------------------------------
int __cdecl cs_enter(STATE st, const char *attr, unsigned int len)
{
  int v3; // ebp
  char *v4; // eax
  char *v5; // esi
  int result; // eax

  v3 = *(_DWORD *)(st + 280);
  v4 = cs_file_sec(a1: attr, a2: len);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  if ( *(_DWORD *)v4 == 8 )
    memset(dst: (unsigned __int8 *)(v3 + 2696), value: 0, count: 0x6Cu);
  result = 0;
  if ( *(_DWORD *)v5 == 9 )
    *(_DWORD *)(v3 + 2692) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C1A0
// Name: cs_leave
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl cs_leave(STATE st, const char *attr, unsigned int len)
{
  int v3; // esi
  char *v4; // eax
  unsigned __int8 (__cdecl *v5)(int); // eax

  v3 = *(_DWORD *)(st + 280);
  v4 = cs_file_sec(a1: attr, a2: len);
  if ( v4 != nullptr && *(_DWORD *)v4 == 9 && (v5 = *(unsigned __int8 (__cdecl **)(int))(v3 + 2804)) != nullptr )
    return v5(a1: v3 + 2696);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C1F0
// Name: cs_value
// Source: json
//------------------------------------------------------------------------------
int __cdecl cs_value(STATE st, char *attr, unsigned int len)
{
  int v3; // esi
  char *v4; // eax
  int v5; // ebx
  int result; // eax
  int v7; // eax
  _DWORD v8[13]; // [esp+0h] [ebp-70h]
  long double v9; // [esp+34h] [ebp-3Ch]
  const char *v10; // [esp+48h] [ebp-28h]
  const char *v11; // [esp+4Ch] [ebp-24h]
  const char *v12; // [esp+50h] [ebp-20h]
  const char *v13; // [esp+54h] [ebp-1Ch]
  const char *v14; // [esp+58h] [ebp-18h]
  char str[16]; // [esp+5Ch] [ebp-14h] BYREF

  v3 = *(_DWORD *)(st + 280);
  v4 = cs_file_sec(a1: (const char *)(st + 136), a2: strlen((const char *)(st + 136)));
  if ( v4 != nullptr )
    v5 = *(_DWORD *)v4;
  else
    v5 = 0;
  switch ( v5 )
  {
    case 2:
      *(_DWORD *)(v3 + 2696) = strtol(nptr: attr, endptr: nullptr, ibase: 10);
      result = 0;
      break;
    case 3:
      LODWORD(v9) = attr;
      *(_DWORD *)(v3 + 2712) = mstr(str: (unsigned __int8 *)v3, l1: len, a3: 0x1Fu, src: v9);
      result = 0;
      break;
    case 6:
      LODWORD(v9) = attr;
      *(_DWORD *)(v3 + 2716) = mstr(str: (unsigned __int8 *)(v3 + 32), l1: len, a3: 0x1Fu, src: v9);
      result = 0;
      break;
    case 7:
      result = strncmp(first: "primary", last: attr, count: len);
      if ( result != 0 )
      {
        result = strncmp(first: "binary", last: attr, count: len);
        if ( result != 0 )
        {
          result = strncmp(first: "compiled", last: attr, count: len);
          if ( result != 0 )
            goto LABEL_24;
          *(_DWORD *)(v3 + 2708) |= 1u;
        }
        else
        {
          *(_DWORD *)(v3 + 2708) |= 0x10u;
        }
      }
      else
      {
        *(_DWORD *)(v3 + 2708) |= 0x20u;
      }
      break;
    case 10:
      fill_uchar(nptr: attr, a2: len, a: (unsigned __int8 *)(v3 + 577), size: 0x100u);
      *(_DWORD *)(v3 + 2736) = v3 + 577;
      result = 0;
      break;
    case 11:
      fill_uchar(nptr: attr, a2: len, a: (unsigned __int8 *)(v3 + 321), size: 0x100u);
      *(_DWORD *)(v3 + 2732) = v3 + 321;
      result = 0;
      break;
    case 12:
      fill_uint16(nptr: attr, a2: len, a: (unsigned __int16 *)(v3 + 1090), size: 0x100u);
      *(_DWORD *)(v3 + 2752) = v3 + 1090;
      result = 0;
      break;
    case 13:
      fill_uchar(nptr: attr, a2: len, a: (unsigned __int8 *)(v3 + 833), size: 0x100u);
      *(_DWORD *)(v3 + 2740) = v3 + 833;
      result = 0;
      break;
    case 14:
      fill_uchar(nptr: attr, a2: len, a: (unsigned __int8 *)(v3 + 64), size: 0x101u);
      *(_DWORD *)(v3 + 2728) = v3 + 64;
      result = 0;
      break;
    case 15:
      *(_DWORD *)(v3 + 2700) = strtol(nptr: attr, endptr: nullptr, ibase: 10);
      result = 0;
      break;
    case 16:
      *(_DWORD *)(v3 + 2704) = strtol(nptr: attr, endptr: nullptr, ibase: 10);
      result = 0;
      break;
    case 17:
      LODWORD(v9) = attr;
      *(_DWORD *)(v3 + 2720) = mstr(str: (unsigned __int8 *)(v3 + 1602), l1: len, a3: 0x3Fu, src: v9);
      result = 0;
      break;
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
      *(_DWORD *)(v3 + 2724) = v3 + 1666;
      LODWORD(v9) = attr;
      v10 = "&";
      v11 = "<";
      v12 = "<<";
      v13 = "<<<";
      v14 = "=";
      mstr((unsigned __int8 *)str, l1: len, a3: 0xFu, src: v9);
      v7 = *(_DWORD *)(v3 + 2692);
      if ( (unsigned int)(v7 + 20) < 0x400 )
        *(_DWORD *)(v3 + 2692) += sprintf(string: (char *)(v7 + v3 + 1666), format: " %s %s", (const char *)v8[v5], str);
      goto LABEL_24;
    default:
LABEL_24:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C5E0
// Name: _my_parse_charset_xml
// Source: json
//------------------------------------------------------------------------------
bool __cdecl my_parse_charset_xml(int a1, int a2, int a3)
{
  int v3; // eax
  bool v4; // bl
  _QWORD v6[330]; // [esp-18h] [ebp-C48h] BYREF
  int v7; // [esp+C28h] [ebp-8h]

  my_xml_parser_create(p: (STATE)((char *)&v6[4] + 4));
  LODWORD(v6[2]) = cs_enter;
  my_xml_set_enter_handler(p: (STATE)((char *)&v6[4] + 4), action: *(_output_s_l::__l2::<unnamed_type_buffer> *)&v6[2]);
  LODWORD(v6[1]) = cs_value;
  my_xml_set_value_handler(p: (STATE)((char *)&v6[4] + 4), action: *(_output_s_l::__l2::<unnamed_type_buffer> *)&v6[1]);
  LODWORD(v6[0]) = cs_leave;
  my_xml_set_leave_handler(p: (STATE)((char *)&v6[4] + 4), action: *(_output_s_l::__l2::<unnamed_type_buffer> *)v6);
  v7 = a3;
  my_xml_set_user_data();
  LOBYTE(v3) = my_xml_parse();
  v4 = v3 != 0;
  vio_ignore_timeout();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041C6A0
// Name: _my_charset_is_8bit_pure_ascii
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_charset_is_8bit_pure_ascii(LIST_ENTRY32 *a1)
{
  _WORD *Flink; // ecx
  unsigned int v3; // eax

  Flink = (_WORD *)a1[7].Flink;
  if ( Flink != nullptr )
  {
    v3 = 0;
    while ( *Flink <= 0x7Fu )
    {
      ++v3;
      ++Flink;
      if ( v3 >= 0x100 )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C6D0
// Name: _my_charset_is_ascii_compatible
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_charset_is_ascii_compatible(LIST_ENTRY32 *a1)
{
  unsigned __int16 *Flink; // ecx
  unsigned int v2; // eax

  Flink = (unsigned __int16 *)a1[7].Flink;
  if ( Flink == nullptr )
    return 1;
  v2 = 0;
  while ( *Flink == v2 )
  {
    ++v2;
    ++Flink;
    if ( v2 >= 0x80 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE80
// Name: mstr_0
// Source: json
//------------------------------------------------------------------------------
void __usercall mstr_0(unsigned int a1@<eax>, unsigned int a2@<ecx>, unsigned __int8 *a3@<edi>, unsigned __int8 *src)
{
  unsigned int v4; // esi

  v4 = a2;
  if ( a2 >= a1 )
    v4 = a1;
  memcpy(dst: a3, src, count: v4);
  a3[v4] = 0;
}
