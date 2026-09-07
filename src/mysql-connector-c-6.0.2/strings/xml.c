// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/xml.c
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042FA10
// Name: lex2str
// Source: json
//------------------------------------------------------------------------------
CCommand *__usercall lex2str@<eax>(int a1@<eax>)
{
  CCommand *v1; // eax

  switch ( a1 )
  {
    case '!':
      v1 = (CCommand *)"'!'";
      break;
    case '/':
      v1 = (CCommand *)"'/'";
      break;
    case '<':
      v1 = (CCommand *)"'<'";
      break;
    case '=':
      v1 = (CCommand *)"'='";
      break;
    case '>':
      v1 = (CCommand *)"'>'";
      break;
    case '?':
      v1 = (CCommand *)"'?'";
      break;
    case 'C':
      v1 = (CCommand *)"COMMENT";
      break;
    case 'D':
      v1 = (CCommand *)"CDATA";
      break;
    case 'E':
      v1 = (CCommand *)"END-OF-INPUT";
      break;
    case 'I':
      v1 = (CCommand *)"IDENT";
      break;
    case 'S':
      v1 = (CCommand *)"STRING";
      break;
    case 'T':
      v1 = (CCommand *)"TEXT";
      break;
    default:
      v1 = (CCommand *)"unknown token";
      break;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FAE0
// Name: my_xml_norm_text
// Source: json
//------------------------------------------------------------------------------
unsigned int *__usercall my_xml_norm_text@<eax>(unsigned int *result@<eax>)
{
  unsigned __int8 *v1; // edx
  unsigned int v2; // ecx
  unsigned __int8 *v3; // ecx
  int v4; // edx
  unsigned __int8 *v5; // ecx

  v1 = (unsigned __int8 *)result[1];
  if ( *result < (unsigned int)v1 )
  {
    do
    {
      if ( (*((_BYTE *)&my_xml_ctype + *(unsigned __int8 *)*result) & 8) == 0 )
        break;
      v2 = *result + 1;
      *result = v2;
    }
    while ( v2 < (unsigned int)v1 );
    if ( *result < (unsigned int)v1 )
    {
      do
      {
        v3 = (unsigned __int8 *)result[1];
        v4 = *(v3 - 1);
        v5 = v3 - 1;
        if ( (*((_BYTE *)&my_xml_ctype + v4) & 8) == 0 )
          break;
        result[1] = (unsigned int)v5;
      }
      while ( *result < result[1] );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042FB30
// Name: my_xml_scan
// Source: json
//------------------------------------------------------------------------------
void __usercall my_xml_scan(wchar_t *p@<eax>, unsigned int *a)
{
  unsigned int v3; // ecx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned __int8 *v8; // eax
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  const char *v13; // edx
  _DWORD *v14; // edi
  unsigned int v15; // eax
  _BYTE *v16; // eax
  int v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 v19; // cl
  unsigned __int8 *v20; // eax
  _BYTE *v21; // eax
  _BYTE *v22; // edx
  _BYTE *v23; // eax

  v3 = *((_DWORD *)p + 69);
  if ( *((_DWORD *)p + 68) < v3 )
  {
    do
    {
      v4 = *((unsigned __int8 **)p + 68);
      if ( (*((_BYTE *)&my_xml_ctype + *v4) & 8) == 0 )
        break;
      v5 = v4 + 1;
      *((_DWORD *)p + 68) = v5;
    }
    while ( (unsigned int)v5 < v3 );
  }
  v6 = *((_DWORD *)p + 68);
  if ( v6 < v3 )
  {
    *a = v6;
    a[1] = *((_DWORD *)p + 68);
    v7 = *((_DWORD *)p + 69);
    v8 = *((unsigned __int8 **)p + 68);
    if ( (int)(v7 - (_DWORD)v8) > 3 && *(_DWORD *)v8 == 757932348 )
    {
      if ( (unsigned int)v8 < v7 )
      {
        do
        {
          v9 = *((_BYTE **)p + 68);
          if ( *v9 == 45 && v9[1] == 45 && v9[2] == 62 )
            break;
          v10 = v9 + 1;
          *((_DWORD *)p + 68) = v10;
        }
        while ( (unsigned int)v10 < v7 );
      }
      v11 = *((_BYTE **)p + 68);
      if ( *v11 == 45 && v11[1] == 45 && v11[2] == 62 )
        *((_DWORD *)p + 68) = v11 + 3;
      a[1] = *((_DWORD *)p + 68);
    }
    else
    {
      v12 = 9;
      v13 = "<![CDATA[";
      v14 = *((_DWORD **)p + 68);
      do
      {
        if ( *v14 != *(_DWORD *)v13 )
          goto LABEL_30;
        v12 -= 4;
        v13 += 4;
        ++v14;
      }
      while ( v12 >= 4 );
      if ( *v13 != *(_BYTE *)v14 )
      {
LABEL_30:
        strchr(string: "?=/<>!", chr: *v8);
        if ( v17 != 0 )
        {
          a[1] = ++*((_DWORD *)p + 68);
        }
        else
        {
          v18 = *((unsigned __int8 **)p + 68);
          v19 = *v18;
          if ( *v18 == 34 || v19 == 39 )
          {
            v21 = v18 + 1;
            for ( *((_DWORD *)p + 68) = v21; (unsigned int)v21 < *((_DWORD *)p + 69); *((_DWORD *)p + 68) = ++v21 )
            {
              if ( *v21 == *(_BYTE *)*a )
                break;
            }
            v22 = (_BYTE *)*a;
            a[1] = *((_DWORD *)p + 68);
            v23 = *((_BYTE **)p + 68);
            if ( *v22 == *v23 )
              *((_DWORD *)p + 68) = v23 + 1;
            ++*a;
            if ( (*(_BYTE *)p & 2) == 0 )
              my_xml_norm_text(result: a);
          }
          else if ( (*((_BYTE *)&my_xml_ctype + v19) & 1) != 0 )
          {
            v20 = v18 + 1;
            for ( *((_DWORD *)p + 68) = v20; (unsigned int)v20 < *((_DWORD *)p + 69); *((_DWORD *)p + 68) = ++v20 )
            {
              if ( (*((_BYTE *)&my_xml_ctype + *v20) & 2) == 0 )
                break;
            }
            a[1] = *((_DWORD *)p + 68);
            my_xml_norm_text(result: a);
          }
        }
        return;
      }
      v15 = (unsigned int)(v8 + 9);
      *((_DWORD *)p + 68) = v15;
      if ( v15 < v7 - 2 )
      {
        while ( 1 )
        {
          v16 = *((_BYTE **)p + 68);
          if ( *v16 == 93 && v16[1] == 93 && v16[2] == 62 )
            break;
          *((_DWORD *)p + 68) = v16 + 1;
          if ( *((_DWORD *)p + 68) >= (unsigned int)(*((_DWORD *)p + 69) - 2) )
            return;
        }
        *((_DWORD *)p + 68) += 3;
        a[1] = *((_DWORD *)p + 68);
      }
    }
  }
  else
  {
    *a = v3;
    a[1] = *((_DWORD *)p + 69);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FDB0
// Name: my_xml_value
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __fastcall my_xml_value(int a1, int a2, tagShutdownType str)
{
  unsigned __int8 (__cdecl *v3)(int, tagShutdownType, int); // eax

  v3 = *(unsigned __int8 (__cdecl **)(int, tagShutdownType, int))(a1 + 288);
  if ( v3 != nullptr )
    return v3(a1, a2: str, a3: a2);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042FDD0
// Name: my_xml_enter
// Source: json
//------------------------------------------------------------------------------
int __usercall my_xml_enter@<eax>(int a1@<eax>, unsigned int a2@<edi>, unsigned __int8 *str)
{
  _BYTE *v4; // eax
  int (__cdecl *v6)(int, unsigned __int8 *, unsigned int); // eax

  v4 = *(_BYTE **)(a1 + 264);
  if ( (unsigned int)&v4[a2 - a1 - 135] > 0x80 )
  {
    sprintf(string: (char *)(a1 + 8), format: "To deep XML");
    return 1;
  }
  if ( (unsigned int)v4 > a1 + 136 )
  {
    *v4 = 47;
    ++*(_DWORD *)(a1 + 264);
  }
  memcpy(dst: *(unsigned __int8 **)(a1 + 264), src: str, count: a2);
  *(_DWORD *)(a1 + 264) += a2;
  **(_BYTE **)(a1 + 264) = 0;
  v6 = *(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(a1 + 284);
  if ( (*(_BYTE *)a1 & 1) != 0 )
  {
    if ( v6 != nullptr )
      return v6(a1, a2: str, a3: a2);
  }
  else if ( v6 != nullptr )
  {
    return v6(a1, a2: (unsigned __int8 *)(a1 + 136), a3: *(_DWORD *)(a1 + 264) - a1 - 136);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042FEA0
// Name: my_xml_leave
// Source: json
//------------------------------------------------------------------------------
int __fastcall my_xml_leave(int a1, unsigned __int8 *a2, unsigned int slen)
{
  unsigned int v4; // ecx
  _BYTE *v5; // ebx
  unsigned int v6; // ebp
  int result; // eax
  int (__cdecl *v8)(int, unsigned __int8 *, unsigned int); // ecx
  int (__cdecl *v9)(int, int, unsigned int); // eax
  unsigned __int8 v10[32]; // [esp+10h] [ebp-44h] BYREF
  unsigned __int8 v11[32]; // [esp+30h] [ebp-24h] BYREF

  v4 = *(_DWORD *)(a1 + 264);
  v5 = (_BYTE *)v4;
  if ( v4 <= a1 + 136 )
  {
LABEL_4:
    if ( *v5 != 47 )
    {
      v6 = v4 - (_DWORD)v5;
      goto LABEL_7;
    }
  }
  else
  {
    while ( *v5 != 47 )
    {
      if ( (unsigned int)--v5 <= a1 + 136 )
        goto LABEL_4;
    }
  }
  v6 = v4 - (_DWORD)v5 - 1;
LABEL_7:
  if ( a2 == nullptr || slen == v6 )
  {
    if ( (*(_BYTE *)a1 & 1) != 0 )
    {
      v8 = *(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(a1 + 292);
      if ( v8 != nullptr )
      {
        result = v8(a1, a2, a3: slen);
LABEL_19:
        *v5 = 0;
        *(_DWORD *)(a1 + 264) = v5;
        return result;
      }
    }
    else
    {
      v9 = *(int (__cdecl **)(int, int, unsigned int))(a1 + 292);
      if ( v9 != nullptr )
      {
        result = v9(a1, a2: a1 + 136, a3: v4 - a1 - 136);
        goto LABEL_19;
      }
    }
    result = 0;
    goto LABEL_19;
  }
  mstr_0(a1: slen, a2: 0x1Fu, a3: v10, src: a2);
  if ( v6 != 0 )
  {
    mstr_0(a1: v6, a2: 0x1Fu, a3: v11, src: v5 + 1);
    sprintf(
      string: (char *)(a1 + 8),
      format: "'</%s>' unexpected ('</%s>' wanted)",
      (const char *)v10,
      (const char *)v11);
  }
  else
  {
    sprintf(string: (char *)(a1 + 8), format: "'</%s>' unexpected (END-OF-INPUT wanted)", (const char *)v10);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FFE0
// Name: _my_xml_parse
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_xml_parse(STATE p, tagShutdownType str, unsigned int len)
{
  _BYTE *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  unsigned __int8 *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // ebx
  unsigned int v14; // edi
  int v15; // eax
  int v17; // eax
  int v18; // eax
  void (__cdecl *v19)(char *, localeinfo_struct *); // ecx
  _BYTE *v20; // eax
  _BYTE *v21; // eax
  bool v22; // zf
  void (__cdecl *v23)(char *, localeinfo_struct *); // edx
  unsigned __int8 *v24; // [esp-4h] [ebp-2Ch]
  unsigned __int8 *v25; // [esp-4h] [ebp-2Ch]
  CCommand *v26; // [esp-4h] [ebp-2Ch]
  CCommand *v27; // [esp-4h] [ebp-2Ch]
  CCommand *v28; // [esp-4h] [ebp-2Ch]
  CCommand *v29; // [esp-4h] [ebp-2Ch]
  CCommand *v30; // [esp-4h] [ebp-2Ch]
  int exclam; // [esp+10h] [ebp-18h]
  int question; // [esp+14h] [ebp-14h]
  void (__cdecl *a)(char *, localeinfo_struct *); // [esp+18h] [ebp-10h] BYREF
  void (__cdecl *v34)(char *, localeinfo_struct *); // [esp+1Ch] [ebp-Ch]
  void (__cdecl *b)(char *, localeinfo_struct *); // [esp+20h] [ebp-8h] BYREF
  int v36; // [esp+24h] [ebp-4h]

  *(_DWORD *)(p + 264) = p + 136;
  *(_DWORD *)(p + 268) = str;
  *(_DWORD *)(p + 272) = str;
  *(_DWORD *)(p + 276) = str + len;
  if ( str >= str + len )
  {
LABEL_51:
    if ( *(_BYTE *)(p + 136) == 0 )
      return 0;
    sprintf(string: (char *)(p + 8), format: "unexpected END-OF-INPUT");
    return 1;
  }
  while ( 1 )
  {
    v3 = *(_BYTE **)(p + 272);
    if ( *v3 != 60 )
    {
      v19 = *(void (__cdecl **)(char *, localeinfo_struct *))(p + 272);
      a = v19;
      if ( (unsigned int)v3 < *(_DWORD *)(p + 276) )
      {
        do
        {
          v20 = *(_BYTE **)(p + 272);
          if ( *v20 == 60 )
            break;
          v21 = v20 + 1;
          *(_DWORD *)(p + 272) = v21;
        }
        while ( (unsigned int)v21 < *(_DWORD *)(p + 276) );
      }
      v22 = (*(_BYTE *)p & 2) == 0;
      v23 = *(void (__cdecl **)(char *, localeinfo_struct *))(p + 272);
      v34 = v23;
      if ( v22 )
      {
        my_xml_norm_text(result: (unsigned int *)&a);
        v23 = v34;
        v19 = a;
      }
      if ( v19 != v23 )
        my_xml_value(a1: p, a2: (char *)v23 - (char *)v19, str: (tagShutdownType)v19);
      goto LABEL_50;
    }
    question = 0;
    exclam = 0;
    my_xml_scan((wchar_t *)p, (unsigned int *)&a);
    if ( v4 != 67 )
      break;
LABEL_50:
    if ( *(_DWORD *)(p + 272) >= *(_DWORD *)(p + 276) )
      goto LABEL_51;
  }
  if ( v4 == 68 )
  {
    v34 = (void (__cdecl *)(char *, localeinfo_struct *))((char *)v34 - 3);
    a = (void (__cdecl *)(char *, localeinfo_struct *))((char *)a + 9);
    my_xml_value(a1: p, a2: (char *)v34 - (char *)a, str: (tagShutdownType)a);
    goto LABEL_50;
  }
  my_xml_scan((wchar_t *)p, (unsigned int *)&a);
  switch ( v5 )
  {
    case '/':
      my_xml_scan((wchar_t *)p, (unsigned int *)&a);
      if ( v6 != 73 )
      {
        v27 = lex2str(a1: v6);
        sprintf(string: (char *)(p + 8), format: "%s unexpected (ident wanted)", v27);
        return 1;
      }
      if ( my_xml_leave(a1: p, a2: (unsigned __int8 *)a, slen: (char *)v34 - (char *)a) != 0 )
        return 1;
      my_xml_scan((wchar_t *)p, (unsigned int *)&a);
      v8 = v7;
LABEL_41:
      if ( v8 != 62 )
      {
        v26 = lex2str(a1: v8);
        sprintf(string: (char *)(p + 8), format: "%s unexpected ('>' wanted)", v26);
        return 1;
      }
      goto LABEL_50;
    case '!':
      my_xml_scan((wchar_t *)p, (unsigned int *)&a);
      exclam = 1;
      break;
    case '?':
      my_xml_scan((wchar_t *)p, (unsigned int *)&a);
      question = 1;
      break;
    default:
      break;
  }
  if ( v5 != 73 )
  {
    v30 = lex2str(a1: v5);
    sprintf(string: (char *)(p + 8), format: "%s unexpected (ident or '/' wanted)", v30);
    return 1;
  }
  v9 = (unsigned __int8 *)a;
  *(_DWORD *)(p + 4) = 0;
  if ( my_xml_enter(a1: p, a2: (char *)v34 - (char *)v9, str: v9) != 0 )
    return 1;
  while ( 2 )
  {
    my_xml_scan((wchar_t *)p, (unsigned int *)&a);
    v8 = v10;
    if ( v10 != 73 )
    {
      if ( v10 != 83 )
        break;
      if ( exclam == 0 )
        goto gt;
    }
    my_xml_scan((wchar_t *)p, a: (unsigned int *)&b);
    v8 = v11;
    switch ( v11 )
    {
      case '=':
        my_xml_scan((wchar_t *)p, a: (unsigned int *)&b);
        if ( v12 != 73 && v12 != 83 )
        {
          v28 = lex2str(a1: v12);
          sprintf(string: (char *)(p + 8), format: "%s unexpected (ident or string wanted)", v28);
          return 1;
        }
        v13 = (unsigned __int8 *)a;
        v14 = (char *)v34 - (char *)a;
        v24 = (unsigned __int8 *)a;
        *(_DWORD *)(p + 4) = 1;
        if ( my_xml_enter(a1: p, a2: v14, str: v24) != 0 )
          return 1;
        LOBYTE(v15) = my_xml_value(a1: p, a2: v36 - (_DWORD)b, str: (tagShutdownType)b);
        goto LABEL_24;
      case 'I':
        v13 = (unsigned __int8 *)a;
        v14 = (char *)v34 - (char *)a;
        v25 = (unsigned __int8 *)a;
        *(_DWORD *)(p + 4) = 1;
        v15 = my_xml_enter(a1: p, a2: v14, str: v25);
LABEL_24:
        if ( v15 != 0 )
          return 1;
        if ( my_xml_leave(a1: p, a2: v13, slen: v14) != 0 )
          return 1;
        continue;
      case 'S':
        if ( exclam == 0 )
          goto gt;
        continue;
      default:
        break;
    }
    break;
  }
  if ( v8 == 47 )
  {
    if ( my_xml_leave(a1: p, a2: nullptr, slen: 0) != 0 )
      return 1;
    my_xml_scan((wchar_t *)p, (unsigned int *)&a);
    v8 = v17;
  }
gt:
  if ( question == 0 )
  {
LABEL_39:
    if ( exclam != 0 && my_xml_leave(a1: p, a2: nullptr, slen: 0) != 0 )
      return 1;
    goto LABEL_41;
  }
  if ( v8 == 63 )
  {
    if ( my_xml_leave(a1: p, a2: nullptr, slen: 0) != 0 )
      return 1;
    my_xml_scan((wchar_t *)p, (unsigned int *)&a);
    v8 = v18;
    goto LABEL_39;
  }
  v29 = lex2str(a1: v8);
  sprintf(string: (char *)(p + 8), format: "%s unexpected ('?' wanted)", v29);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004303B0
// Name: _my_xml_parser_create
// Source: json
//------------------------------------------------------------------------------
void __usercall my_xml_parser_create(__int128 a1@<xmm0>, STATE p)
{
  memset(a1, dst: p, value: 0, count: 0x128u);
}

//------------------------------------------------------------------------------
// Address: 0x004303E0
// Name: _my_xml_set_value_handler
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_xml_set_value_handler(STATE p, _output_s_l::__l2::<unnamed_type_buffer> action)
{
  *(_DWORD *)(p + 288) = *(_DWORD *)action.sz;
  return *(_DWORD *)action.sz;
}

//------------------------------------------------------------------------------
// Address: 0x004303F0
// Name: _my_xml_set_enter_handler
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_xml_set_enter_handler(STATE p, _output_s_l::__l2::<unnamed_type_buffer> action)
{
  *(_DWORD *)(p + 284) = *(_DWORD *)action.sz;
  return *(_DWORD *)action.sz;
}

//------------------------------------------------------------------------------
// Address: 0x00430400
// Name: _my_xml_set_leave_handler
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_xml_set_leave_handler(STATE p, _output_s_l::__l2::<unnamed_type_buffer> action)
{
  *(_DWORD *)(p + 292) = *(_DWORD *)action.sz;
  return *(_DWORD *)action.sz;
}

//------------------------------------------------------------------------------
// Address: 0x00430410
// Name: _my_xml_set_user_data
// Source: json
//------------------------------------------------------------------------------
void *__cdecl my_xml_set_user_data(STATE p, void *user_data)
{
  *(_DWORD *)(p + 280) = user_data;
  return user_data;
}
