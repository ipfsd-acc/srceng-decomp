// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_format.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040FA50
// Name: _strlength
// Source: json
//------------------------------------------------------------------------------
int __cdecl strlength(_BYTE *a1)
{
  char v1; // dl
  _BYTE *v2; // eax
  _BYTE *v3; // ecx
  char v4; // al
  _BYTE *v5; // eax

  v1 = *a1;
  v2 = a1;
  v3 = a1;
  if ( *a1 != 0 )
  {
    while ( v1 == 32 )
    {
LABEL_5:
      v5 = v3;
      do
        ++v3;
      while ( *v3 == 32 );
      v1 = *v3;
      if ( *v3 == 0 )
        return v5 - a1;
    }
    while ( 1 )
    {
      v4 = *++v3;
      if ( v4 == 0 )
        break;
      if ( v4 == 32 )
        goto LABEL_5;
    }
    v2 = v3;
  }
  return v2 - a1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FA90
// Name: _fn_format
// Source: json
//------------------------------------------------------------------------------
_LDBL12 *__cdecl fn_format(char *a1, unsigned __int8 *string, unsigned __int8 *a3, char *a4, __int16 a5)
{
  int v6; // eax
  ExprNode **v7; // ecx
  unsigned __int8 *v8; // esi
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  void *v12; // ecx
  int v13; // eax
  unsigned int v14; // edi
  _LDBL12 *v15; // ebx
  char *v16; // eax
  char *v17; // eax
  void *v18; // ecx
  void *v19; // ecx
  unsigned int v21; // eax
  int v22; // [esp+18h] [ebp-408h] BYREF
  char src[511]; // [esp+1Ch] [ebp-404h] BYREF
  char v24; // [esp+21Bh] [ebp-205h] BYREF
  unsigned __int8 dst[512]; // [esp+21Ch] [ebp-204h] BYREF

  v6 = dirname_part(dst: (unsigned __int8 *)src, string, a3: (int)&v22);
  v8 = &string[v6];
  if ( v6 == 0 || (a5 & 1) != 0 )
  {
    convert_dirname(dst: (unsigned __int8 *)src, src: a3, a3: 0);
  }
  else if ( (a5 & 0x80u) != 0 )
  {
    test_if_hard_path(dir_name: v7);
    if ( v9 == 0 )
    {
      strmake((char *)dst, src, length: 0x1FFu);
      v10 = (char *)convert_dirname(dst: (unsigned __int8 *)src, src: a3, a3: 0);
      strmake(dst: v10, src: (char *)dst, length: &v24 - v10);
    }
  }
  if ( (a5 & 8) != 0 )
    pack_dirname(string: (unsigned __int8 *)src, a2: (int)src);
  if ( (a5 & 4) != 0 )
    unpack_dirname(a1: src, a2: (int)src);
  if ( (a5 & 0x100) != 0 || (strchr(string: v8, chr: 0x2Eu), v11 == 0) )
  {
    v13 = strlength(a1: v8);
  }
  else if ( (a5 & 2) != 0 )
  {
    v13 = v11 - (_DWORD)v8;
  }
  else
  {
    v13 = strlength(a1: v8);
    a4 = (char *)defaultValue;
  }
  v14 = v13;
  if ( v13 + strlen(src) + strlen(a4) >= 0x200 || v14 >= 0x100 )
  {
    if ( (a5 & 0x40) != 0 )
      return nullptr;
    v21 = strlength(a1: string);
    if ( v21 >= 0x1FF )
      v21 = 511;
    strmake(dst: a1, src: (char *)string, length: v21);
    v15 = (_LDBL12 *)a1;
  }
  else
  {
    v15 = (_LDBL12 *)a1;
    if ( a1 == (char *)string )
    {
      memmove(dst, src: v8, count: v14);
      v8 = dst;
    }
    strmov(dst: v12, dsta: a1, src);
    v17 = strmake(dst: v16, src: (char *)v8, length: v14);
    strmov(dst: v18, dsta: v17, src: a4);
  }
  if ( (a5 & 0x20) != 0 )
  {
    my_realpath(a1: (int)v15, result: v15);
  }
  else if ( (a5 & 0x10) != 0 )
  {
    strmov(dst: v19, dsta: (char *)dst, src: (char *)v15);
    my_readlink(dst: (int)v15, a2: (int)dst);
  }
  return v15;
}
