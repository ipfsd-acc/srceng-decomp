// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_pack.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00419420
// Name: _cleanup_dirname
// Source: json
//------------------------------------------------------------------------------
int __cdecl cleanup_dirname(char *a1, unsigned __int8 *string)
{
  int *v2; // ebx
  unsigned __int8 *v3; // ebp
  int v4; // eax
  void *v5; // ecx
  unsigned int v6; // edi
  char *v7; // ecx
  int v8; // eax
  unsigned int v9; // edi
  char *v10; // esi
  int (__cdecl *v11)(LIST_ENTRY32 *, unsigned __int8 *, unsigned __int8 *); // eax
  unsigned __int8 *v12; // ebp
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int *v16; // ebp
  unsigned int v17; // eax
  char *v18; // edi
  int v19; // eax
  int v20; // eax
  char *i; // ebp
  unsigned int v22; // eax
  char *v23; // edi
  char *v24; // eax
  unsigned int v25; // eax
  int *v26; // edi
  unsigned __int8 v27; // al
  int *v29; // [esp+10h] [ebp-224h]
  unsigned int v30; // [esp+14h] [ebp-220h]
  unsigned __int8 *v31; // [esp+18h] [ebp-21Ch]
  LIST_ENTRY32 *v32; // [esp+1Ch] [ebp-218h]
  char v33; // [esp+24h] [ebp-210h] BYREF
  char v34[7]; // [esp+25h] [ebp-20Fh] BYREF
  char dst[516]; // [esp+2Ch] [ebp-208h] BYREF

  v2 = (int *)dst;
  v32 = fs_character_set();
  v29 = (int *)dst;
  v3 = string;
  strrchr(string, chr: 0x3Au);
  if ( v4 != 0 )
  {
    v6 = v4 - (_DWORD)string + 1;
    v2 = (int *)strnmov(dst, src: (char *)string, n: v6);
    v29 = v2;
    v3 = &string[v6];
  }
  v33 = 92;
  strmov(dst: v5, dsta: v34, src: "..");
  v9 = v8 - (_DWORD)&v33;
  LOBYTE(v8) = *v3;
  v30 = v9;
  v10 = (char *)v2;
  *(_BYTE *)v2 = *v3;
  if ( (_BYTE)v8 != 0 )
  {
    while ( 1 )
    {
      v7 = (char *)v32;
      v11 = *(int (__cdecl **)(LIST_ENTRY32 *, unsigned __int8 *, unsigned __int8 *))(v32[12].Blink + 4);
      v12 = v3 + 1;
      v31 = v12;
      if ( v11 != nullptr )
      {
        v13 = v11(a1: v32, a2: v12 - 1, a3: v12 + 2);
        if ( v13 != 0 )
        {
          v14 = v13 - 1;
          if ( v14 != 0 )
          {
            do
            {
              LOBYTE(v7) = *v12;
              ++v10;
              ++v12;
              --v14;
              *v10 = (char)v7;
            }
            while ( v14 != 0 );
            v31 = v12;
          }
          v2 = (int *)(v10 + 1);
          goto LABEL_79;
        }
      }
      if ( *v10 == 47 )
      {
        *v10 = 92;
      }
      else if ( *v10 != 92 )
      {
        goto LABEL_80;
      }
      v15 = v10 - (char *)v2;
      if ( v10 - (char *)v2 > v9 )
      {
        v16 = (int *)&v10[-v9];
        v17 = v9;
        v7 = &v33;
        v18 = &v10[-v9];
        if ( v30 < 4 )
        {
LABEL_19:
          if ( v17 == 0 || *v7 == *v18 && (v17 <= 1 || v7[1] == v18[1] && (v17 <= 2 || v7[2] == v18[2])) )
          {
            v2 = v29;
            v10 = (char *)v16;
            if ( v16 == v29 )
              goto LABEL_80;
            v10 = (char *)v16 - 1;
            if ( *((_BYTE *)v16 - 1) == 126 && (v10 == (char *)v29 || *((_BYTE *)v16 - 2) == 92) )
            {
              if ( home_dir == nullptr )
              {
                v7 = (char *)v30;
                v10 = (char *)v16 + v30;
                goto LABEL_80;
              }
              strmov(dst: v7, dsta: dst, src: home_dir);
              v10 = (char *)(v19 - 1);
              if ( *(_BYTE *)(v19 - 1) == 92 )
                v10 = (char *)(v19 - 2);
            }
            if ( *v10 == 46 && (v10 == (char *)v29 || *(v10 - 1) == 92) )
            {
              if ( my_getwd(pnbuf: (char *)&curr_dir, a2: 512, a3: 0) != 0 )
              {
                v10 += v30 + 1;
                goto LABEL_80;
              }
              strmov(dst, dsta: dst, src: (char *)&curr_dir);
              v10 = (char *)(v20 - 1);
              if ( *(_BYTE *)(v20 - 1) == 92 )
                v10 = (char *)(v20 - 2);
            }
            for ( i = v10; v10 >= (char *)v29; --v10 )
            {
              if ( *v10 == 92 )
                break;
            }
            if ( v10[1] == 126 )
            {
LABEL_53:
              strmov(dst: &v33, dsta: i + 1, src: &v33);
              v10 = v24;
              *v24 = 92;
              goto LABEL_80;
            }
            v22 = v30;
            v7 = &v33;
            v23 = v10;
            if ( v30 < 4 )
            {
LABEL_47:
              if ( v22 == 0 || *v7 == *v23 && (v22 <= 1 || v7[1] == v23[1] && (v22 <= 2 || v7[2] == v23[2])) )
                goto LABEL_53;
            }
            else
            {
              while ( *(_DWORD *)v23 == *(_DWORD *)v7 )
              {
                v22 -= 4;
                v7 += 4;
                v23 += 4;
                if ( v22 < 4 )
                  goto LABEL_47;
              }
            }
            goto LABEL_80;
          }
        }
        else
        {
          while ( *(_DWORD *)v18 == *(_DWORD *)v7 )
          {
            v17 -= 4;
            v7 += 4;
            v18 += 4;
            if ( v17 < 4 )
              goto LABEL_19;
          }
        }
        v2 = v29;
      }
      v25 = v30 - 1;
      if ( v15 == v30 - 1 )
      {
        v7 = v34;
        v26 = v2;
        if ( v25 < 4 )
        {
LABEL_59:
          if ( v25 == 0
            || *v7 == *(_BYTE *)v26
            && (v25 <= 1 || v7[1] == *((_BYTE *)v26 + 1) && (v25 <= 2 || v7[2] == *((_BYTE *)v26 + 2))) )
          {
            v2 = (int *)v10;
LABEL_79:
            v29 = v2;
            goto LABEL_80;
          }
          v2 = v29;
        }
        else
        {
          while ( *v26 == *(_DWORD *)v7 )
          {
            v25 -= 4;
            v7 += 4;
            ++v26;
            if ( v25 < 4 )
              goto LABEL_59;
          }
        }
      }
      if ( v15 > 0 && *(v10 - 1) == 92 )
      {
        if ( v15 != 1 )
          --v10;
      }
      else
      {
        if ( v15 > 1 && *(v10 - 1) == 46 && *(v10 - 2) == 92 )
        {
          v10 -= 2;
          goto LABEL_80;
        }
        v7 = &dst[1];
        if ( v10 > &dst[1] && *(v10 - 1) == 126 && *(v10 - 2) == 92 )
        {
          *(_WORD *)dst = 23678;
          v2 = (int *)dst;
          v10 = &dst[1];
          goto LABEL_79;
        }
      }
LABEL_80:
      v3 = v31;
      v27 = *v31;
      *++v10 = *v31;
      if ( v27 == 0 )
        break;
      v9 = v30;
    }
  }
  strmov(dst: v7, dsta: a1, src: dst);
  return v10 - dst;
}

//------------------------------------------------------------------------------
// Address: 0x004197B0
// Name: _symdirget
// Source: json
//------------------------------------------------------------------------------
void __thiscall symdirget(const char *dir, char *buff)
{
  ioinfo *v2; // eax
  char *v3; // esi
  void *v4; // ecx
  char v5; // bl
  int v6; // ebp
  unsigned int v7; // eax
  IRecordInfo **i; // esi
  IRecordInfo *buffa; // [esp+4h] [ebp-204h] BYREF

  v2 = strend(result: (ioinfo *)buff);
  if ( *buff != 0 )
  {
    v3 = (char *)&v2[-1].dbcsBufferUsed + 7;
    if ( *((_BYTE *)&v2[-1].dbcsBufferUsed + 7) != 58 && my_access(lpFileName: buff, a2: 0) != 0 )
    {
      v5 = *v3;
      strmov(dst: v4, dsta: v3, src: ".sym");
      v6 = my_open(lpFileName: buff, a2: 0, a3: 0);
      *v3 = v5;
      v3[1] = 0;
      if ( v6 >= 0 )
      {
        v7 = my_read(fd: v6, lpBuffer: (char *)&buffa, NumberOfBytesRead: 0x200u, a4: 0);
        if ( v7 != 0 )
        {
          for ( i = (IRecordInfo **)((char *)&buffa + v7); i > &buffa; i = (IRecordInfo **)((char *)i - 1) )
          {
            if ( iscntrl(c: *((char *)i - 1)) == 0 && isspace(c: *((char *)i - 1)) == 0 )
              break;
          }
          if ( i == &buffa || *((_BYTE *)i - 1) != 92 )
          {
            *(_BYTE *)i = 92;
            i = (IRecordInfo **)((char *)i + 1);
          }
          strmake(dst: buff, src: (char *)&buffa, length: (char *)i - (char *)&buffa);
        }
        my_close(fd: v6, a2: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004198D0
// Name: expand_tilde
// Source: json
//------------------------------------------------------------------------------
char *__usercall expand_tilde@<eax>(_BYTE **a1@<eax>)
{
  return **a1 != 92 ? nullptr : home_dir;
}

//------------------------------------------------------------------------------
// Address: 0x004198F0
// Name: _system_filename
// Source: json
//------------------------------------------------------------------------------
int __cdecl system_filename(char *dst, char *src)
{
  return strmake(dst, src, length: 0x1FFu) - dst;
}

//------------------------------------------------------------------------------
// Address: 0x00419910
// Name: _intern_filename
// Source: json
//------------------------------------------------------------------------------
void __thiscall intern_filename(void *to, unsigned __int8 *toa, char *from)
{
  unsigned __int8 *p_buff; // edi
  int v4; // eax
  void *v5; // ecx
  unsigned int to_length; // [esp+8h] [ebp-208h] BYREF
  IRecordInfo *buff; // [esp+Ch] [ebp-204h] BYREF

  p_buff = (unsigned __int8 *)from;
  if ( from == (char *)toa )
  {
    strmov(dst: to, dsta: (char *)&buff, src: from);
    p_buff = (unsigned __int8 *)&buff;
  }
  v4 = dirname_part(dst: toa, string: p_buff, a3: (int)&to_length);
  strmov(dst: v5, dsta: (char *)&toa[to_length], src: (char *)&p_buff[v4]);
}

//------------------------------------------------------------------------------
// Address: 0x00419990
// Name: _pack_dirname
// Source: json
//------------------------------------------------------------------------------
void __cdecl pack_dirname(_LDBL12 *string, char *a2)
{
  void *v2; // ecx
  int v3; // eax
  unsigned __int8 *v4; // ebp
  unsigned int v5; // kr00_4
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned __int8 *p_src; // esi
  unsigned int v10; // eax
  char *v11; // ebp
  unsigned int v12; // esi
  unsigned int v13; // ecx
  unsigned int v14; // eax
  char *v15; // ecx
  _LDBL12 *v16; // edi
  unsigned int v17; // eax
  char *v18; // ecx
  unsigned __int8 *v19; // edi
  void *v20; // ecx
  char *v21; // eax
  unsigned int count; // [esp+10h] [ebp-20Ch]
  int v23; // [esp+14h] [ebp-208h]
  unsigned __int8 src; // [esp+18h] [ebp-204h] BYREF
  char dst[511]; // [esp+19h] [ebp-203h] BYREF

  intern_filename(to: v2, toa: string->ld12, from: a2);
  strrchr(string: string->ld12, chr: 0x3Au);
  if ( v3 != 0 )
    v4 = (unsigned __int8 *)(v3 + 1);
  else
    v4 = (unsigned __int8 *)string;
  v23 = my_getwd(pnbuf: (char *)&src, a2: 512, a3: 0);
  if ( v23 != 0 )
    goto LABEL_19;
  v5 = strlen((const char *)&src);
  v6 = v4 - (unsigned __int8 *)string;
  count = v5;
  if ( v4 == (unsigned __int8 *)string )
    goto LABEL_16;
  if ( v5 != v6 )
    goto LABEL_19;
  v7 = v4 - (unsigned __int8 *)string;
  v8 = v4;
  p_src = &src;
  if ( v6 < 4 )
  {
LABEL_10:
    if ( v7 != 0 && (*v8 != *p_src || v7 > 1 && (v8[1] != p_src[1] || v7 > 2 && v8[2] != p_src[2])) )
      goto LABEL_19;
LABEL_16:
    if ( *v4 != 92 && *v4 != 0 )
      bchange(
        dst: string->ld12,
        a2: v4 - (unsigned __int8 *)string,
        &src,
        count: v5,
        a5: strlen((const char *)string) + 1);
    goto LABEL_19;
  }
  while ( *(_DWORD *)p_src == *(_DWORD *)v8 )
  {
    v7 -= 4;
    v8 += 4;
    p_src += 4;
    if ( v7 < 4 )
      goto LABEL_10;
  }
LABEL_19:
  v10 = cleanup_dirname(a1: (char *)string, string: string->ld12);
  if ( v10 != 0 )
  {
    v11 = home_dir;
    v12 = 0;
    if ( home_dir != nullptr )
    {
      v13 = strlen(home_dir);
      v12 = v13;
      if ( home_dir[v13 - 1] == 92 )
        v12 = v13 - 1;
      if ( v12 > 1 && v12 < v10 )
      {
        v14 = v12;
        v15 = home_dir;
        v16 = string;
        if ( v12 < 4 )
        {
LABEL_28:
          if ( (v14 == 0
             || *v15 == v16->ld12[0] && (v14 <= 1 || v15[1] == v16->ld12[1] && (v14 <= 2 || v15[2] == v16->ld12[2])))
            && string->ld12[v12] == 92 )
          {
            string->ld12[0] = 126;
            strmov(dst: &string->ld12[1], dsta: (char *)&string->ld12[1], src: (char *)&string->ld12[v12]);
            v11 = home_dir;
          }
        }
        else
        {
          while ( *(_DWORD *)v16->ld12 == *(_DWORD *)v15 )
          {
            v14 -= 4;
            v15 += 4;
            v16 = (_LDBL12 *)((char *)v16 + 4);
            if ( v14 < 4 )
              goto LABEL_28;
          }
        }
      }
    }
    if ( v23 == 0 )
    {
      if ( v12 > 1 && v12 < count )
      {
        v17 = v12;
        v18 = v11;
        v19 = &src;
        if ( v12 < 4 )
        {
LABEL_42:
          if ( (v17 == 0 || *v18 == *v19 && (v17 <= 1 || v18[1] == v19[1] && (v17 <= 2 || v18[2] == v19[2])))
            && dst[v12 - 1] == 92 )
          {
            src = 126;
            strmov(dst, dsta: dst, src: &dst[v12 - 1]);
          }
        }
        else
        {
          while ( *(_DWORD *)v19 == *(_DWORD *)v18 )
          {
            v17 -= 4;
            v18 += 4;
            v19 += 4;
            if ( v17 < 4 )
              goto LABEL_42;
          }
        }
      }
      if ( is_prefix(result: string) != nullptr )
      {
        v21 = (char *)&string->ld12[&dst[strlen((const char *)&src)] - dst];
        if ( *v21 != 0 )
        {
          strmov(dst: v20, dsta: (char *)string, src: v21);
        }
        else
        {
          string->ld12[0] = 46;
          string->ld12[1] = 92;
          string->ld12[2] = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C10
// Name: _normalize_dirname
// Source: json
//------------------------------------------------------------------------------
int __cdecl normalize_dirname(char *a1, char *a2)
{
  void *v2; // ecx
  unsigned int v3; // kr00_4
  unsigned __int8 v4; // cl
  unsigned __int8 string[512]; // [esp+4h] [ebp-204h] BYREF

  intern_filename(to: v2, toa: string, from: a2);
  v3 = strlen((const char *)string);
  if ( v3 != 0 )
  {
    v4 = string[v3 - 1];
    if ( v4 != 58 && v4 != 92 && v4 != 47 )
    {
      string[v3] = 92;
      string[v3 + 1] = 0;
    }
  }
  return cleanup_dirname(a1, string);
}

//------------------------------------------------------------------------------
// Address: 0x00419CA0
// Name: _unpack_dirname
// Source: json
//------------------------------------------------------------------------------
int __cdecl unpack_dirname(char *a1, char *a2)
{
  char *v2; // eax
  unsigned int v3; // edx
  unsigned __int8 *v4; // edi
  unsigned int v5; // esi
  unsigned __int8 *v7; // [esp+4h] [ebp-210h] BYREF
  unsigned __int8 dst; // [esp+8h] [ebp-20Ch] BYREF
  unsigned __int8 src[519]; // [esp+9h] [ebp-20Bh] BYREF

  normalize_dirname(a1: (char *)&dst, a2);
  if ( dst == 126 )
  {
    v7 = src;
    v2 = expand_tilde(a1: &v7);
    v4 = (unsigned __int8 *)v2;
    if ( v2 != nullptr )
    {
      v5 = strlen(v2);
      if ( v5 + v3 <= 0x200 )
      {
        if ( v5 != 0 && v4[v5 - 1] == 92 )
          --v5;
        if ( &src[v5 - 1] >= src )
          bmove_upp(a1: &src[v5 - 1 + v3], a2: (int)&src[v3], a3: v3);
        else
          memmove(dst: &src[v5 - 1], src, count: v3);
        memmove(&dst, src: v4, count: v5);
      }
    }
  }
  if ( my_use_symdir != 0 )
    symdirget(dir: (const char *)&dst, buff: (char *)&dst);
  return system_filename(dst: a1, src: (char *)&dst);
}
