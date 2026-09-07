// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lstrlib.c
// Functions: 37
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10019B50
// Name: str_len
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_len(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *k; // eax

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  if ( b == -24 )
    goto LABEL_10;
  k = L->p.k;
  k->value.n = (double)*(int *)(b + 16);
  k->tt = 3;
  L->ts.tsv.hash += 16;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019C20
// Name: str_sub
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_sub(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // edi
  lua_TValue *v9; // eax
  int v10; // eax
  signed int v11; // esi
  global_State *l_G; // eax
  unsigned int totalbytes; // ecx
  lua_TValue *v14; // edi
  lua_TValue *k; // esi
  int v17; // [esp+Ch] [ebp-Ch]
  int start; // [esp+10h] [ebp-8h]
  signed int l; // [esp+14h] [ebp-4h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  l = *(_DWORD *)(b + 16);
  v17 = b + 24;
  if ( b == -24 )
    goto LABEL_10;
  v7 = luaL_checkinteger((lua_State *)L, narg: 2);
  if ( v7 < 0 )
    v7 += l + 1;
  v8 = v7 < 0 ? 0 : v7;
  v9 = (lua_TValue *)(L->ts.tsv.keyhash + 32);
  start = v8;
  if ( (unsigned int)v9 >= L->ts.tsv.hash || v9 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 40) <= 0 )
  {
    v10 = -1;
  }
  else
  {
    v10 = luaL_checkinteger((lua_State *)L, narg: 3);
    if ( v10 >= 0 )
      goto LABEL_24;
  }
  v10 += l + 1;
LABEL_24:
  v11 = v10 < 0 ? 0 : v10;
  if ( v8 < 1 )
  {
    start = 1;
    v8 = 1;
  }
  if ( v11 > l )
    v11 = l;
  l_G = L->th.l_G;
  totalbytes = l_G->totalbytes;
  if ( v8 > v11 )
  {
    if ( totalbytes >= l_G->GCthreshold )
      luaC_step(L);
    k = L->p.k;
    k->value.b = (int)luaS_newlstr((lua_State *)L, str: (char *)Ptr, l: 0);
    k->tt = 4;
    L->ts.tsv.hash += 16;
    return 1;
  }
  else
  {
    if ( totalbytes >= l_G->GCthreshold )
      luaC_step(L);
    v14 = L->p.k;
    v14->value.b = (int)luaS_newlstr((lua_State *)L, str: (char *)(v17 + start - 1), l: v11 - start + 1);
    v14->tt = 4;
    L->ts.tsv.hash += 16;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019DD0
// Name: str_reverse
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_reverse(GCObject *L)
{
  lua_TValue *array; // esi
  int v3; // esi
  lua_TValue *v4; // eax
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned int v8; // ecx
  GCObject *v9; // esi
  char *buffer; // eax
  unsigned int v11; // ebx
  _DWORD *hash; // edi
  unsigned int v13; // ebx
  _DWORD *v14; // edi
  luaL_Buffer b; // [esp+Ch] [ebp-210h] BYREF
  int v17; // [esp+218h] [ebp-4h] BYREF
  unsigned int l; // [esp+224h] [ebp+8h]
  unsigned int la; // [esp+224h] [ebp+8h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
      v17 = 0;
LABEL_11:
      v4 = L->h.array;
      if ( (unsigned int)v4 >= L->ts.tsv.hash || v4 == &luaO_nilobject_ || (tt = v4->tt) == -1 )
        v6 = "no value";
      else
        v6 = luaT_typenames[tt];
      v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v6);
      luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v3 = array->value.b;
  l = *(_DWORD *)(v3 + 16);
  v17 = v3 + 24;
  if ( v3 == -24 )
    goto LABEL_11;
  v8 = l;
  v9 = L;
  buffer = b.buffer;
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  if ( l != 0 )
  {
    do
    {
      la = v8 - 1;
      if ( buffer >= (char *)&v17 )
      {
        v11 = buffer - b.buffer;
        if ( buffer != b.buffer )
        {
          if ( *(_DWORD *)(v9->ts.tsv.len + 68) >= *(_DWORD *)(v9->ts.tsv.len + 64) )
            luaC_step(L: v9);
          hash = (_DWORD *)v9->ts.tsv.hash;
          *hash = luaS_newlstr(L: (lua_State *)v9, str: b.buffer, l: v11);
          hash[2] = 4;
          v9->ts.tsv.hash += 16;
          ++b.lvl;
          b.p = b.buffer;
          adjuststack(B: &b);
          buffer = b.p;
        }
      }
      v8 = la;
      *buffer = *(_BYTE *)(v17 + la);
      v9 = (GCObject *)b.L;
      buffer = ++b.p;
    }
    while ( la != 0 );
  }
  v13 = buffer - b.buffer;
  if ( buffer != b.buffer )
  {
    if ( *(_DWORD *)(v9->ts.tsv.len + 68) >= *(_DWORD *)(v9->ts.tsv.len + 64) )
      luaC_step(L: v9);
    v14 = (_DWORD *)v9->ts.tsv.hash;
    *v14 = luaS_newlstr(L: (lua_State *)v9, str: b.buffer, l: v13);
    v14[2] = 4;
    v9->ts.tsv.hash += 16;
    v9 = (GCObject *)b.L;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: (lua_State *)v9, n: b.lvl);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019FB0
// Name: str_lower
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_lower(GCObject *L)
{
  lua_TValue *array; // esi
  int v3; // esi
  lua_TValue *v4; // eax
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  GCObject *v8; // esi
  int lvl; // ecx
  char *buffer; // eax
  unsigned int v11; // ebx
  _DWORD *hash; // edi
  unsigned int v13; // ebx
  _DWORD *v14; // edi
  int v15; // edi
  _DWORD *v17; // ebx
  luaL_Buffer b; // [esp+Ch] [ebp-214h] BYREF
  unsigned int v19; // [esp+218h] [ebp-8h] BYREF
  int v20; // [esp+21Ch] [ebp-4h]
  unsigned int l; // [esp+228h] [ebp+8h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
      v20 = 0;
LABEL_11:
      v4 = L->h.array;
      if ( (unsigned int)v4 >= L->ts.tsv.hash || v4 == &luaO_nilobject_ || (tt = v4->tt) == -1 )
        v6 = "no value";
      else
        v6 = luaT_typenames[tt];
      v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v6);
      luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v3 = array->value.b;
  l = *(_DWORD *)(v3 + 16);
  v20 = v3 + 24;
  if ( v3 == -24 )
    goto LABEL_11;
  v8 = L;
  lvl = 0;
  buffer = b.buffer;
  v11 = 0;
  b.L = (lua_State *)v8;
  b.p = b.buffer;
  b.lvl = 0;
  if ( l != 0 )
  {
    do
    {
      if ( buffer >= (char *)&v19 )
      {
        v19 = buffer - b.buffer;
        if ( buffer != b.buffer )
        {
          if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
            luaC_step(L: v8);
          hash = (_DWORD *)v8->ts.tsv.hash;
          *hash = luaS_newlstr(L: (lua_State *)v8, str: b.buffer, l: v19);
          hash[2] = 4;
          v8->ts.tsv.hash += 16;
          ++b.lvl;
          b.p = b.buffer;
          adjuststack(B: &b);
        }
      }
      *b.p = tolower(c: *(unsigned __int8 *)(v20 + v11));
      v8 = (GCObject *)b.L;
      buffer = b.p + 1;
      ++v11;
      ++b.p;
    }
    while ( v11 < l );
    lvl = b.lvl;
  }
  v13 = buffer - b.buffer;
  if ( buffer != b.buffer )
  {
    if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
      luaC_step(L: v8);
    v14 = (_DWORD *)v8->ts.tsv.hash;
    *v14 = luaS_newlstr(L: (lua_State *)v8, str: b.buffer, l: v13);
    v14[2] = 4;
    v8->ts.tsv.hash += 16;
    v8 = (GCObject *)b.L;
    lvl = b.lvl + 1;
    b.p = b.buffer;
    ++b.lvl;
  }
  v15 = lvl;
  if ( lvl < 2 )
  {
    if ( lvl == 0 )
    {
      v17 = (_DWORD *)v8->ts.tsv.hash;
      *v17 = luaS_newlstr(L: (lua_State *)v8, str: (char *)Ptr, l: 0);
      v17[2] = 4;
      v8->ts.tsv.hash += 16;
    }
    return 1;
  }
  else
  {
    if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
      luaC_step(L: v8);
    luaV_concat(L: (lua_State *)v8, total: v15, last: ((signed int)(v8->ts.tsv.hash - v8->ts.tsv.keyhash) >> 4) - 1);
    v8->ts.tsv.hash += 16 - 16 * v15;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A210
// Name: str_upper
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_upper(GCObject *L)
{
  lua_TValue *array; // esi
  int v3; // esi
  lua_TValue *v4; // eax
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  GCObject *v8; // esi
  int lvl; // ecx
  char *buffer; // eax
  unsigned int v11; // ebx
  _DWORD *hash; // edi
  unsigned int v13; // ebx
  _DWORD *v14; // edi
  int v15; // edi
  _DWORD *v17; // ebx
  luaL_Buffer b; // [esp+Ch] [ebp-214h] BYREF
  unsigned int v19; // [esp+218h] [ebp-8h] BYREF
  int v20; // [esp+21Ch] [ebp-4h]
  unsigned int l; // [esp+228h] [ebp+8h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
      v20 = 0;
LABEL_11:
      v4 = L->h.array;
      if ( (unsigned int)v4 >= L->ts.tsv.hash || v4 == &luaO_nilobject_ || (tt = v4->tt) == -1 )
        v6 = "no value";
      else
        v6 = luaT_typenames[tt];
      v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v6);
      luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v3 = array->value.b;
  l = *(_DWORD *)(v3 + 16);
  v20 = v3 + 24;
  if ( v3 == -24 )
    goto LABEL_11;
  v8 = L;
  lvl = 0;
  buffer = b.buffer;
  v11 = 0;
  b.L = (lua_State *)v8;
  b.p = b.buffer;
  b.lvl = 0;
  if ( l != 0 )
  {
    do
    {
      if ( buffer >= (char *)&v19 )
      {
        v19 = buffer - b.buffer;
        if ( buffer != b.buffer )
        {
          if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
            luaC_step(L: v8);
          hash = (_DWORD *)v8->ts.tsv.hash;
          *hash = luaS_newlstr(L: (lua_State *)v8, str: b.buffer, l: v19);
          hash[2] = 4;
          v8->ts.tsv.hash += 16;
          ++b.lvl;
          b.p = b.buffer;
          adjuststack(B: &b);
        }
      }
      *b.p = toupper(c: *(unsigned __int8 *)(v20 + v11));
      v8 = (GCObject *)b.L;
      buffer = b.p + 1;
      ++v11;
      ++b.p;
    }
    while ( v11 < l );
    lvl = b.lvl;
  }
  v13 = buffer - b.buffer;
  if ( buffer != b.buffer )
  {
    if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
      luaC_step(L: v8);
    v14 = (_DWORD *)v8->ts.tsv.hash;
    *v14 = luaS_newlstr(L: (lua_State *)v8, str: b.buffer, l: v13);
    v14[2] = 4;
    v8->ts.tsv.hash += 16;
    v8 = (GCObject *)b.L;
    lvl = b.lvl + 1;
    b.p = b.buffer;
    ++b.lvl;
  }
  v15 = lvl;
  if ( lvl < 2 )
  {
    if ( lvl == 0 )
    {
      v17 = (_DWORD *)v8->ts.tsv.hash;
      *v17 = luaS_newlstr(L: (lua_State *)v8, str: (char *)Ptr, l: 0);
      v17[2] = 4;
      v8->ts.tsv.hash += 16;
    }
    return 1;
  }
  else
  {
    if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
      luaC_step(L: v8);
    luaV_concat(L: (lua_State *)v8, total: v15, last: ((signed int)(v8->ts.tsv.hash - v8->ts.tsv.keyhash) >> 4) - 1);
    v8->ts.tsv.hash += 16 - 16 * v15;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A470
// Name: str_rep
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_rep(GCObject *L)
{
  lua_TValue *array; // esi
  int v3; // esi
  lua_TValue *v4; // eax
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8; // edi
  GCObject *v9; // esi
  char *buffer; // eax
  unsigned int v11; // ebx
  _DWORD *hash; // edi
  luaL_Buffer b; // [esp+Ch] [ebp-210h] BYREF
  char *s; // [esp+218h] [ebp-4h]
  unsigned int l; // [esp+224h] [ebp+8h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
      s = nullptr;
LABEL_11:
      v4 = L->h.array;
      if ( (unsigned int)v4 >= L->ts.tsv.hash || v4 == &luaO_nilobject_ || (tt = v4->tt) == -1 )
        v6 = "no value";
      else
        v6 = luaT_typenames[tt];
      v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v6);
      luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v3 = array->value.b;
  l = *(_DWORD *)(v3 + 16);
  s = (char *)(v3 + 24);
  if ( v3 == -24 )
    goto LABEL_11;
  v8 = luaL_checkinteger((lua_State *)L, narg: 2);
  v9 = L;
  buffer = b.buffer;
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  if ( v8 > 0 )
  {
    do
    {
      --v8;
      luaL_addlstring(B: &b, s, l);
    }
    while ( v8 > 0 );
    v9 = (GCObject *)b.L;
    buffer = b.p;
  }
  v11 = buffer - b.buffer;
  if ( buffer != b.buffer )
  {
    if ( *(_DWORD *)(v9->ts.tsv.len + 68) >= *(_DWORD *)(v9->ts.tsv.len + 64) )
      luaC_step(L: v9);
    hash = (_DWORD *)v9->ts.tsv.hash;
    *hash = luaS_newlstr(L: (lua_State *)v9, str: b.buffer, l: v11);
    hash[2] = 4;
    v9->ts.tsv.hash += 16;
    v9 = (GCObject *)b.L;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: (lua_State *)v9, n: b.lvl);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A5F0
// Name: str_byte
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_byte(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax
  int v8; // eax
  unsigned int v9; // esi
  int v10; // ecx
  lua_TValue *v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  lua_TValue *k; // edx
  lua_TValue *v20; // edx
  lua_TValue *v21; // edx
  lua_TValue *v22; // edx
  lua_TValue *v23; // ecx
  int posi; // [esp+10h] [ebp-8h]
  int posia; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  posi = *(_DWORD *)(b + 16);
  v26 = b + 24;
  if ( b == -24 )
    goto LABEL_10;
  v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v7 >= L->ts.tsv.hash || v7 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 24) <= 0 )
  {
    v8 = 1;
  }
  else
  {
    v8 = luaL_checkinteger((lua_State *)L, narg: 2);
    if ( v8 < 0 )
    {
      v9 = posi;
      v8 += posi + 1;
      goto LABEL_21;
    }
  }
  v9 = posi;
LABEL_21:
  v10 = v8 < 0 ? 0 : v8;
  v11 = (lua_TValue *)(L->ts.tsv.keyhash + 32);
  v12 = v10;
  posia = v10;
  if ( (unsigned int)v11 >= L->ts.tsv.hash || v11 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 40) <= 0 )
    v13 = v10;
  else
    v13 = luaL_checkinteger((lua_State *)L, narg: 3);
  if ( v13 < 0 )
    v13 += v9 + 1;
  v14 = v13 < 0 ? 0 : v13;
  if ( v12 <= 0 )
  {
    v12 = 1;
    posia = 1;
  }
  if ( v14 > v9 )
    v14 = v9;
  if ( v12 > v14 )
    return 0;
  v16 = v14 - v12 + 1;
  if ( v14 + 1 <= v14 )
    luaL_error((lua_State *)L, fmt: "string slice too long");
  if ( lua_checkstack((lua_State *)L, size: v14 - v12 + 1) == 0 )
    luaL_error((lua_State *)L, fmt: "stack overflow (%s)", "string slice too long");
  v17 = 0;
  if ( v16 >= 4 )
  {
    v18 = v12 + v26;
    do
    {
      k = L->p.k;
      k->value.n = (double)*(unsigned __int8 *)(v18 + v17 - 1);
      k->tt = 3;
      L->ts.tsv.hash += 16;
      v20 = L->p.k;
      v20->value.n = (double)*(unsigned __int8 *)(v18 + v17);
      v20->tt = 3;
      L->ts.tsv.hash += 16;
      v21 = L->p.k;
      v21->value.n = (double)*(unsigned __int8 *)(v18 + v17 + 1);
      v21->tt = 3;
      L->ts.tsv.hash += 16;
      v22 = L->p.k;
      v22->value.n = (double)*(unsigned __int8 *)(v18 + v17 + 2);
      v22->tt = 3;
      L->ts.tsv.hash += 16;
      v17 += 4;
    }
    while ( v17 < v16 - 3 );
    v12 = posia;
  }
  for ( ; v17 < v16; ++v17 )
  {
    v23 = L->p.k;
    v23->value.n = (double)*(unsigned __int8 *)(v26 + v12 - 1 + v17);
    v23->tt = 3;
    L->ts.tsv.hash += 16;
  }
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x1001A850
// Name: str_char
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_char(GCObject *L)
{
  lua_State *v1; // esi
  int v2; // edi
  int v3; // ebx
  int lvl; // ecx
  GCObject *v5; // eax
  char *buffer; // edx
  int v7; // eax
  lua_State *v8; // edi
  _DWORD *p_b; // esi
  unsigned int v10; // ebx
  lua_State *v11; // esi
  _DWORD *v12; // edi
  int v13; // edi
  lua_State *v14; // esi
  _DWORD *hash; // edi
  unsigned int *p_hash; // esi
  luaL_Buffer b; // [esp+Ch] [ebp-218h] BYREF
  unsigned int l; // [esp+218h] [ebp-Ch] BYREF
  int c; // [esp+21Ch] [ebp-8h]
  int i; // [esp+220h] [ebp-4h]

  v1 = (lua_State *)L;
  v2 = 1;
  v3 = (signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4;
  lvl = 0;
  v5 = L;
  buffer = b.buffer;
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  i = 1;
  if ( v3 >= 1 )
  {
    do
    {
      v7 = luaL_checkinteger(L: v1, narg: v2);
      c = v7;
      if ( (unsigned __int8)v7 != v7 )
        luaL_argerror(L: v1, extramsg: "invalid value", narg: v2);
      if ( b.p >= (char *)&l )
      {
        l = b.p - b.buffer;
        if ( b.p != b.buffer )
        {
          v8 = b.L;
          if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
            luaC_step(L: (GCObject *)b.L);
          p_b = &v8->top->value.b;
          *p_b = luaS_newlstr(L: v8, str: b.buffer, l);
          p_b[2] = 4;
          ++v8->top;
          ++b.lvl;
          b.p = b.buffer;
          adjuststack(B: &b);
          LOBYTE(v7) = c;
          v2 = i;
          v1 = (lua_State *)L;
        }
      }
      *b.p = v7;
      ++v2;
      buffer = ++b.p;
      i = v2;
    }
    while ( v2 <= v3 );
    v5 = (GCObject *)b.L;
    lvl = b.lvl;
  }
  v10 = buffer - b.buffer;
  if ( buffer != b.buffer )
  {
    v11 = (lua_State *)v5;
    if ( *(_DWORD *)(v5->ts.tsv.len + 68) >= *(_DWORD *)(v5->ts.tsv.len + 64) )
      luaC_step(L: v5);
    v12 = &v11->top->value.b;
    *v12 = luaS_newlstr(L: v11, str: b.buffer, l: v10);
    v12[2] = 4;
    ++v11->top;
    v5 = (GCObject *)b.L;
    b.p = b.buffer;
    lvl = ++b.lvl;
  }
  v13 = lvl;
  v14 = (lua_State *)v5;
  if ( lvl < 2 )
  {
    if ( lvl == 0 )
    {
      hash = (_DWORD *)v5->ts.tsv.hash;
      p_hash = &v5->ts.tsv.hash;
      *hash = luaS_newlstr(L: (lua_State *)v5, str: (char *)Ptr, l: 0);
      hash[2] = 4;
      *p_hash += 16;
    }
    return 1;
  }
  else
  {
    if ( *(_DWORD *)(v5->ts.tsv.len + 68) >= *(_DWORD *)(v5->ts.tsv.len + 64) )
      luaC_step(L: v5);
    luaV_concat(L: v14, total: v13, last: v14->top - v14->base - 1);
    v14->top = (lua_TValue *)((char *)v14->top + 16 - 16 * v13);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AA50
// Name: writer
// Source: json
//------------------------------------------------------------------------------
int __cdecl writer(lua_State *L, const char *b, unsigned int size, luaL_Buffer *B)
{
  luaL_addlstring(B, s: b, l: size);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA70
// Name: str_dump
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_dump(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  GCObject *gc; // eax
  unsigned int v8; // ebx
  lua_State *v9; // esi
  _DWORD *p_b; // edi
  luaL_Buffer b; // [esp+Ch] [ebp-20Ch] BYREF

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 6 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  for ( ; L->top < L->base + 1; ++L->top )
    L->top->tt = 0;
  v6 = L->base + 1;
  L->top = v6;
  b.L = L;
  b.p = b.buffer;
  b.lvl = 0;
  if ( v6[-1].tt != 6 || (gc = v6[-1].value.gc)->ts.tsv.reserved != 0 || luaU_dump(L, data: &b, f: gc->cl.l.p) != 0 )
    luaL_error(L, fmt: "unable to dump given function");
  v8 = b.p - b.buffer;
  if ( b.p != b.buffer )
  {
    v9 = b.L;
    if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
      luaC_step(L: (GCObject *)b.L);
    p_b = &v9->top->value.b;
    *p_b = luaS_newlstr(L: v9, str: b.buffer, l: v8);
    p_b[2] = 4;
    ++v9->top;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: b.L, n: b.lvl);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001ABD0
// Name: classend
// Source: json
//------------------------------------------------------------------------------
const char *__usercall classend@<eax>(MatchState *ms@<edi>, const char *p@<eax>)
{
  int v3; // eax
  const char *v4; // esi
  char v6; // cl

  v3 = *p;
  v4 = p + 1;
  if ( v3 == 37 )
  {
    if ( *v4 == 0 )
      luaL_error(L: ms->L, fmt: "malformed pattern (ends with '%%')");
    return v4 + 1;
  }
  else if ( v3 == 91 )
  {
    if ( *v4 == 94 )
      ++v4;
    do
    {
      if ( *v4 == 0 )
        luaL_error(L: ms->L, fmt: "malformed pattern (missing ']')");
      v6 = *v4++;
      if ( v6 == 37 && *v4 != 0 )
        ++v4;
    }
    while ( *v4 != 93 );
    return v4 + 1;
  }
  else
  {
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AC40
// Name: match_class
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall match_class@<eax>(int c@<eax>, int cl@<edi>)
{
  int v3; // esi
  BOOL result; // eax
  int v5; // [esp+0h] [ebp-8h]

  switch ( tolower(c: v5) )
  {
    case 'a':
      v3 = isalpha(c);
      goto LABEL_12;
    case 'c':
      v3 = iscntrl(c);
      goto LABEL_12;
    case 'd':
      v3 = isdigit(c);
      goto LABEL_12;
    case 'l':
      v3 = islower(c);
      goto LABEL_12;
    case 'p':
      v3 = ispunct(c);
      goto LABEL_12;
    case 's':
      v3 = isspace(c);
      goto LABEL_12;
    case 'u':
      v3 = isupper(c);
      goto LABEL_12;
    case 'w':
      v3 = isalnum(c);
      goto LABEL_12;
    case 'x':
      v3 = isxdigit(c);
      goto LABEL_12;
    case 'z':
      v3 = c == 0;
LABEL_12:
      if ( islower(c: cl) != 0 )
        result = v3;
      else
        result = v3 == 0;
      break;
    default:
      result = cl == c;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD50
// Name: matchbracketclass
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall matchbracketclass@<eax>(const char *p@<eax>, int c, const char *ec)
{
  const char *v3; // esi
  const char *v4; // edx
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // eax
  int v7; // edi
  int v8; // edi
  int v9; // ecx
  unsigned __int8 *v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int sig; // [esp+14h] [ebp-4h]

  v3 = p;
  sig = 1;
  if ( p[1] == 94 )
  {
    sig = 0;
    v3 = p + 1;
  }
  v4 = ec;
  v5 = (unsigned __int8 *)(v3 + 1);
  if ( v5 < (unsigned __int8 *)ec )
  {
    v6 = v5 + 2;
    do
    {
      if ( *v5 == 37 )
      {
        v7 = *++v5;
        v11 = v6 + 1;
        v12 = v7;
        switch ( tolower(c: v7) )
        {
          case 'a':
            v8 = isalpha(c);
            goto LABEL_17;
          case 'c':
            v8 = iscntrl(c);
            goto LABEL_17;
          case 'd':
            v8 = isdigit(c);
            goto LABEL_17;
          case 'l':
            v8 = islower(c);
            goto LABEL_17;
          case 'p':
            v8 = ispunct(c);
            goto LABEL_17;
          case 's':
            v8 = isspace(c);
            goto LABEL_17;
          case 'u':
            v8 = isupper(c);
            goto LABEL_17;
          case 'w':
            v8 = isalnum(c);
            goto LABEL_17;
          case 'x':
            v8 = isxdigit(c);
            goto LABEL_17;
          case 'z':
            v8 = c == 0;
LABEL_17:
            if ( islower(c: v12) == 0 )
              v8 = v8 == 0;
            break;
          default:
            v8 = v7 == c;
            break;
        }
        if ( v8 != 0 )
          return sig;
        v6 = v11;
        v4 = ec;
      }
      else if ( v5[1] == 45 && v6 < (unsigned __int8 *)v4 )
      {
        v9 = *v5;
        v5 += 2;
        v6 += 2;
        if ( v9 <= c && c <= *v5 )
          return sig;
      }
      else if ( *v5 == c )
      {
        return sig;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < (unsigned __int8 *)v4 );
  }
  return sig == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF00
// Name: matchbalance
// Source: json
//------------------------------------------------------------------------------
const char *__usercall matchbalance@<eax>(const char *s@<ecx>, char *p@<eax>, MatchState *ms)
{
  char v5; // al
  int v6; // edi
  const char *src_end; // ecx
  const char *v8; // esi
  int i; // edx
  int v10; // eax
  int b; // [esp+10h] [ebp-4h]

  if ( *p == 0 || p[1] == 0 )
    luaL_error(L: ms->L, fmt: "unbalanced pattern");
  v5 = *p;
  if ( *s == *p )
  {
    v6 = p[1];
    b = v5;
    src_end = ms->src_end;
    v8 = s + 1;
    for ( i = 1; v8 < src_end; ++v8 )
    {
      v10 = *v8;
      if ( v10 == v6 )
      {
        if ( --i == 0 )
          return v8 + 1;
      }
      else if ( v10 == b )
      {
        ++i;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF80
// Name: max_expand
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl max_expand(MatchState *ms, const char *s, const char *p, const char *ep)
{
  const char *v4; // esi
  MatchState *v5; // edi
  int v6; // ebx
  unsigned __int8 v7; // cl
  int v8; // eax
  BOOL matched; // eax
  const char *result; // eax

  v4 = s;
  v5 = ms;
  v6 = 0;
  if ( s < ms->src_end )
  {
    while ( 1 )
    {
      v7 = *p;
      v8 = *(unsigned __int8 *)v4;
      if ( *p == 37 )
        break;
      if ( v7 != 46 )
      {
        if ( v7 == 91 )
          matched = matchbracketclass(p, c: v8, ec: ep - 1);
        else
          matched = v7 == v8;
LABEL_8:
        if ( !matched )
          goto LABEL_10;
      }
      ++v4;
      ++v6;
      if ( v4 >= v5->src_end )
      {
LABEL_10:
        if ( v6 >= 0 )
          goto LABEL_11;
        return nullptr;
      }
    }
    matched = match_class(c: v8, cl: *((unsigned __int8 *)p + 1));
    v5 = ms;
    goto LABEL_8;
  }
LABEL_11:
  while ( 1 )
  {
    result = match(ms: v5, s: &s[v6], p: ep + 1);
    if ( result != nullptr )
      break;
    if ( --v6 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B010
// Name: min_expand
// Source: json
//------------------------------------------------------------------------------
const char *__usercall min_expand@<eax>(const char *s@<eax>, MatchState *ms, const char *p, const char *ep)
{
  const char *v4; // edi
  const char *v5; // esi
  const char *result; // eax
  unsigned __int8 v7; // cl
  int v8; // eax
  BOOL matched; // eax

  v4 = ep;
  v5 = s;
  for ( result = match(ms, s, p: ep + 1); result == nullptr; result = match(ms, s: ++v5, p: v4 + 1) )
  {
    if ( v5 >= ms->src_end )
      return nullptr;
    v7 = *p;
    v8 = *(unsigned __int8 *)v5;
    if ( *p == 37 )
    {
      matched = match_class(c: v8, cl: *((unsigned __int8 *)p + 1));
      v4 = ep;
    }
    else
    {
      if ( v7 == 46 )
        continue;
      if ( v7 == 91 )
        matched = matchbracketclass(p, c: v8, ec: v4 - 1);
      else
        matched = v7 == v8;
    }
    if ( !matched )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B0A0
// Name: start_capture
// Source: json
//------------------------------------------------------------------------------
const char *__usercall start_capture@<eax>(MatchState *ms@<esi>, const char *s, const char *p, int what)
{
  int level; // edi
  const char *result; // eax

  level = ms->level;
  if ( level >= 32 )
    luaL_error(L: ms->L, fmt: "too many captures");
  ms->capture[level].init = s;
  ms->capture[level].len = what;
  ms->level = level + 1;
  result = match(ms, s, p);
  if ( result == nullptr )
    --ms->level;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B0F0
// Name: end_capture
// Source: json
//------------------------------------------------------------------------------
const char *__usercall end_capture@<eax>(MatchState *ms@<esi>, const char *s, const char *p)
{
  int v3; // eax
  int *p_len; // ecx
  int v5; // edi
  const char *result; // eax

  v3 = ms->level - 1;
  if ( v3 < 0 )
LABEL_5:
    luaL_error(L: ms->L, fmt: "invalid pattern capture");
  p_len = &ms->capture[v3].len;
  while ( *p_len != -1 )
  {
    p_len -= 2;
    if ( --v3 < 0 )
      goto LABEL_5;
  }
  v5 = v3;
  ms->capture[v3].len = s - ms->capture[v3].init;
  result = match(ms, s, p);
  if ( result == nullptr )
    ms->capture[v5].len = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B150
// Name: match_capture
// Source: json
//------------------------------------------------------------------------------
const char *__usercall match_capture@<eax>(MatchState *ms@<ecx>, int l@<eax>, const char *s)
{
  int v3; // eax
  unsigned int len; // edi
  const char *init; // esi
  unsigned int v6; // ecx
  const char *v7; // edx

  v3 = l - 49;
  if ( v3 < 0 || v3 >= ms->level || ms->capture[v3].len == -1 )
    luaL_error(L: ms->L, fmt: "invalid capture index");
  len = ms->capture[v3].len;
  if ( ms->src_end - s >= len )
  {
    init = ms->capture[v3].init;
    v6 = ms->capture[v3].len;
    v7 = s;
    if ( len < 4 )
    {
LABEL_9:
      if ( v6 == 0 || *v7 == *init && (v6 <= 1 || v7[1] == init[1] && (v6 <= 2 || v7[2] == init[2])) )
        return &s[len];
    }
    else
    {
      while ( *(_DWORD *)init == *(_DWORD *)v7 )
      {
        v6 -= 4;
        v7 += 4;
        init += 4;
        if ( v6 < 4 )
          goto LABEL_9;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1E0
// Name: match
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl match(MatchState *ms, const char *s, const char *p)
{
  unsigned __int8 v5; // al
  const char *v6; // ebx
  const char *v7; // eax
  unsigned __int8 v8; // cl
  const char *v9; // edi
  const char *v10; // eax
  MatchState *v11; // edx
  const char *v12; // edi
  unsigned __int8 v13; // cl
  int v14; // eax
  BOOL matched; // eax
  int v16; // ecx
  const char *result; // eax
  const char *ep; // [esp+Ch] [ebp-4h]
  const char *epa; // [esp+Ch] [ebp-4h]

  while ( 2 )
  {
    switch ( *p )
    {
      case 0:
        return s;
      case 0x24:
        if ( p[1] != 0 )
          goto dflt;
        return s != ms->src_end ? nullptr : s;
      case 0x25:
        v5 = p[1];
        if ( v5 == 98 )
        {
          s = matchbalance(s, p: (char *)p + 2, ms);
          if ( s == nullptr )
            return nullptr;
          p += 4;
          continue;
        }
        if ( v5 != 102 )
        {
          if ( isdigit(c: v5) == 0 )
          {
dflt:
            v10 = classend(ms, p);
            v11 = ms;
            v12 = v10;
            epa = v10;
            if ( s < ms->src_end )
            {
              v13 = *p;
              v14 = *(unsigned __int8 *)s;
              if ( *p == 37 )
              {
                matched = match_class(c: v14, cl: *((unsigned __int8 *)p + 1));
                v12 = epa;
              }
              else
              {
                if ( v13 == 46 )
                {
LABEL_26:
                  v16 = 1;
LABEL_28:
                  switch ( *v12 )
                  {
                    case '*':
                      return max_expand(ms: v11, s, p, ep: v12);
                    case '+':
                      if ( v16 == 0 )
                        return nullptr;
                      return max_expand(ms: v11, s: s + 1, p, ep: v12);
                    case '-':
                      return min_expand(s, ms: v11, p, ep: v12);
                    case '?':
                      if ( v16 != 0 )
                      {
                        result = match(ms: v11, s: s + 1, p: v12 + 1);
                        if ( result != nullptr )
                          return result;
                      }
                      p = v12 + 1;
                      continue;
                    default:
                      if ( v16 == 0 )
                        return nullptr;
                      ++s;
                      p = v12;
                      continue;
                  }
                }
                if ( v13 == 91 )
                  matched = matchbracketclass(p, c: v14, ec: v12 - 1);
                else
                  matched = v13 == v14;
              }
              v11 = ms;
              if ( matched )
                goto LABEL_26;
            }
            v16 = 0;
            goto LABEL_28;
          }
          s = match_capture(ms, l: *((unsigned __int8 *)p + 1), s);
          if ( s == nullptr )
            return nullptr;
          p += 2;
          continue;
        }
        v6 = p + 2;
        if ( *v6 != 91 )
          luaL_error(L: ms->L, fmt: "missing '[' after '%%f' in pattern");
        v7 = classend(ms, p: v6);
        ep = v7;
        if ( s == ms->src_init )
          v8 = 0;
        else
          v8 = *(s - 1);
        v9 = v7 - 1;
        if ( !matchbracketclass(p: v6, c: v8, ec: v7 - 1) && matchbracketclass(p: v6, c: *(unsigned __int8 *)s, ec: v9) )
        {
          p = ep;
          continue;
        }
        return nullptr;
      case 0x28:
        if ( p[1] == 41 )
          return start_capture(ms, s, p: p + 2, what: -2);
        else
          return start_capture(ms, s, p: p + 1, what: -1);
      case 0x29:
        return end_capture(ms, s, p: p + 1);
      default:
        goto dflt;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B4D0
// Name: lmemfind
// Source: json
//------------------------------------------------------------------------------
char *__cdecl lmemfind(char *s1, unsigned int l1, const char *s2, unsigned int l2)
{
  char *result; // eax
  const char *v5; // edi
  const char *v6; // edx
  unsigned int v7; // ecx
  const char *v8; // esi
  bool v9; // zf
  unsigned int l1a; // [esp+10h] [ebp+Ch]

  if ( l2 == 0 )
    return s1;
  if ( l2 > l1 )
    return nullptr;
  l1a = l1 - (l2 - 1);
  if ( l1a != 0 )
  {
    do
    {
      memchr(buf: (unsigned __int8 *)s1, chr: *s2, cnt: l1a);
      if ( result == nullptr )
        break;
      v5 = result + 1;
      v6 = s2 + 1;
      v7 = l2 - 1;
      v8 = result + 1;
      if ( l2 - 1 < 4 )
      {
LABEL_10:
        if ( v7 == 0 || *v6 == *v8 && (v7 <= 1 || v6[1] == v8[1] && (v7 <= 2 || v6[2] == v8[2])) )
          return result;
      }
      else
      {
        while ( *(_DWORD *)v8 == *(_DWORD *)v6 )
        {
          v7 -= 4;
          v6 += 4;
          v8 += 4;
          if ( v7 < 4 )
            goto LABEL_10;
        }
      }
      v9 = s1 - v5 + l1a == 0;
      l1a += s1 - v5;
      s1 = result + 1;
    }
    while ( !v9 );
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B580
// Name: push_onecapture
// Source: json
//------------------------------------------------------------------------------
void __usercall push_onecapture(MatchState *ms@<ecx>, int i@<eax>, char *s, const char *e)
{
  GCObject *v6; // esi
  int len; // eax
  const char *init; // ebx
  _DWORD *hash; // edi
  lua_State *v10; // eax
  lua_TValue *top; // ecx
  char *v12; // [esp-8h] [ebp-18h]
  unsigned int v13; // [esp-4h] [ebp-14h]
  int l; // [esp+Ch] [ebp-4h]

  if ( i >= ms->level )
  {
    if ( i != 0 )
      luaL_error(L: ms->L, fmt: "invalid capture index");
    v6 = (GCObject *)ms->L;
    if ( *(_DWORD *)(v6->ts.tsv.len + 68) >= *(_DWORD *)(v6->ts.tsv.len + 64) )
      luaC_step(L: v6);
    v13 = e - s;
    v12 = s;
LABEL_12:
    hash = (_DWORD *)v6->ts.tsv.hash;
    *hash = luaS_newlstr(L: (lua_State *)v6, str: v12, l: v13);
    hash[2] = 4;
    v6->ts.tsv.hash += 16;
    return;
  }
  len = ms->capture[i].len;
  l = len;
  if ( len == -1 )
    luaL_error(L: ms->L, fmt: "unfinished capture");
  if ( len != -2 )
  {
    init = ms->capture[i].init;
    v6 = (GCObject *)ms->L;
    if ( *(_DWORD *)(v6->ts.tsv.len + 68) >= *(_DWORD *)(v6->ts.tsv.len + 64) )
      luaC_step(L: v6);
    v13 = l;
    v12 = (char *)init;
    goto LABEL_12;
  }
  v10 = ms->L;
  top = v10->top;
  top->value.n = (double)(ms->capture[i].init - ms->src_init + 1);
  top->tt = 3;
  ++v10->top;
}

//------------------------------------------------------------------------------
// Address: 0x1001B660
// Name: push_captures
// Source: json
//------------------------------------------------------------------------------
int __cdecl push_captures(MatchState *ms, char *s, const char *e)
{
  int level; // edi
  lua_State *L; // esi
  int i; // esi

  level = ms->level;
  if ( level == 0 )
    level = s != nullptr;
  L = ms->L;
  if ( lua_checkstack(L, size: level) == 0 )
    luaL_error(L, fmt: "stack overflow (%s)", "too many captures");
  for ( i = 0; i < level; ++i )
    push_onecapture(ms, i, s, e);
  return level;
}

//------------------------------------------------------------------------------
// Address: 0x1001B6D0
// Name: str_find_aux
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_find_aux(GCObject *L, int find)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v4; // eax
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  lua_TValue *v8; // esi
  int v9; // esi
  lua_TValue *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  lua_TValue *v14; // eax
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // esi
  lua_TValue *v18; // eax
  int v19; // edx
  int v20; // eax
  char *v21; // eax
  int v22; // eax
  lua_TValue *k; // ecx
  lua_TValue *v24; // ecx
  char *v26; // esi
  const char *v27; // eax
  const char *v28; // eax
  lua_TValue *v29; // ecx
  lua_TValue *v30; // ecx
  unsigned int l1; // [esp+Ch] [ebp-124h]
  unsigned int anchor; // [esp+10h] [ebp-120h]
  int anchora; // [esp+10h] [ebp-120h]
  const char *v34; // [esp+14h] [ebp-11Ch]
  unsigned __int8 *string; // [esp+18h] [ebp-118h]
  const char *p; // [esp+1Ch] [ebp-114h]
  MatchState ms; // [esp+20h] [ebp-110h] BYREF

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v4 = L->h.array;
      if ( (unsigned int)v4 >= L->ts.tsv.hash || v4 == &luaO_nilobject_ || (tt = v4->tt) == -1 )
        v6 = "no value";
      else
        v6 = luaT_typenames[tt];
      v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v6);
      luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  l1 = *(_DWORD *)(b + 16);
  v34 = (const char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v8 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v8 >= L->ts.tsv.hash )
    v8 = &luaO_nilobject_;
  if ( v8->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v8) == 0 )
    {
LABEL_25:
      v10 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
      if ( (unsigned int)v10 >= L->ts.tsv.hash
        || v10 == &luaO_nilobject_
        || (v11 = *(_DWORD *)(L->ts.tsv.keyhash + 24)) == -1 )
      {
        v12 = "no value";
      }
      else
      {
        v12 = luaT_typenames[v11];
      }
      v13 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v12);
      luaL_argerror((lua_State *)L, extramsg: v13, narg: 2);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v8 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
    if ( (unsigned int)v8 >= L->ts.tsv.hash )
      v8 = &luaO_nilobject_;
  }
  v9 = v8->value.b;
  anchor = *(_DWORD *)(v9 + 16);
  string = (unsigned __int8 *)(v9 + 24);
  if ( v9 == -24 )
    goto LABEL_25;
  v14 = (lua_TValue *)(L->ts.tsv.keyhash + 32);
  p = (const char *)(v9 + 24);
  if ( (unsigned int)v14 >= L->ts.tsv.hash || v14 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 40) <= 0 )
  {
    v15 = 1;
LABEL_35:
    v16 = l1;
    goto LABEL_36;
  }
  v15 = luaL_checkinteger((lua_State *)L, narg: 3);
  if ( v15 >= 0 )
    goto LABEL_35;
  v16 = l1;
  v15 += l1 + 1;
LABEL_36:
  v17 = v15 < 0 ? -1 : v15 - 1;
  if ( v17 >= 0 )
  {
    if ( v17 > v16 )
      v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  if ( find == 0 )
    goto LABEL_51;
  v18 = (lua_TValue *)(L->ts.tsv.keyhash + 48);
  if ( (unsigned int)v18 >= L->ts.tsv.hash )
    v18 = &luaO_nilobject_;
  if ( (v19 = v18->tt) != 0 && (v19 != 1 || v18->value.b != 0)
    || (strpbrk(string, control: "^$*+?.([%-"), v16 = l1, v20 == 0) )
  {
    v21 = lmemfind(s1: (char *)&v34[v17], l1: v16 - v17, s2: (const char *)string, l2: anchor);
    if ( v21 != nullptr )
    {
      v22 = v21 - v34;
      k = L->p.k;
      k->value.n = (double)(v22 + 1);
      k->tt = 3;
      L->ts.tsv.hash += 16;
      v24 = L->p.k;
      v24->value.n = (double)(int)(anchor + v22);
      v24->tt = 3;
      L->ts.tsv.hash += 16;
      return 2;
    }
    else
    {
LABEL_58:
      *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
      L->ts.tsv.hash += 16;
      return 1;
    }
  }
  else
  {
LABEL_51:
    if ( *string == 94 )
    {
      p = (const char *)(string + 1);
      anchora = 1;
    }
    else
    {
      anchora = 0;
    }
    v26 = (char *)&v34[v17];
    ms.L = (lua_State *)L;
    ms.src_init = v34;
    ms.src_end = &v34[v16];
    while ( 1 )
    {
      ms.level = 0;
      v27 = match(&ms, s: v26, p);
      if ( v27 != nullptr )
        break;
      v28 = v26++;
      if ( v28 >= ms.src_end || anchora != 0 )
        goto LABEL_58;
    }
    if ( find != 0 )
    {
      v29 = L->p.k;
      v29->value.n = (double)(v26 - v34 + 1);
      v29->tt = 3;
      L->ts.tsv.hash += 16;
      v30 = L->p.k;
      v30->value.n = (double)(v27 - v34);
      v30->tt = 3;
      L->ts.tsv.hash += 16;
      return push_captures(&ms, s: nullptr, e: nullptr) + 2;
    }
    else
    {
      return push_captures(&ms, s: v26, e: v27);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BA30
// Name: str_find
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_find(GCObject *L)
{
  return str_find_aux(L, find: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001BA50
// Name: str_match
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_match(GCObject *L)
{
  return str_find_aux(L, find: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BA70
// Name: gmatch_aux
// Source: json
//------------------------------------------------------------------------------
int __cdecl gmatch_aux(GCObject *L)
{
  lua_TValue *v1; // ecx
  lua_TValue *v2; // esi
  const char *v3; // edi
  lua_TValue *v4; // ecx
  int b; // esi
  lua_TValue *v6; // ecx
  lua_TValue *v7; // esi
  lua_TValue *v8; // ecx
  lua_TValue *p_e; // eax
  int tt; // ecx
  int v11; // edi
  char *v12; // edi
  const char *v13; // eax
  char *v14; // ecx
  int v16; // eax
  lua_TValue *k; // ecx
  GCObject *v18; // eax
  lua_TValue *v19; // ecx
  lua_TValue *p_hookmask; // eax
  lua_TValue *v21; // eax
  GCObject *gc; // eax
  GCObject *v23; // ecx
  int level; // ebx
  lua_State *v25; // esi
  int stacksize; // eax
  int v27; // eax
  unsigned int v28; // edi
  CallInfo *ci; // eax
  int i; // esi
  unsigned int ls; // [esp+10h] [ebp-130h]
  unsigned int lsa; // [esp+10h] [ebp-130h]
  const char *s; // [esp+14h] [ebp-12Ch]
  const char *p; // [esp+18h] [ebp-128h]
  lua_TValue **pa; // [esp+18h] [ebp-128h]
  double e; // [esp+20h] [ebp-120h] BYREF
  int v37; // [esp+28h] [ebp-118h]
  MatchState ms; // [esp+30h] [ebp-110h] BYREF

  v1 = *(lua_TValue **)&L->cl.l.upvals[0]->tt;
  if ( *(_BYTE *)(v1->value.b + 7) != 0 )
    v2 = (lua_TValue *)(v1->value.b + 24);
  else
    v2 = &luaO_nilobject_;
  if ( v2->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v2) == 0 )
    {
      v3 = nullptr;
      ls = 0;
      s = nullptr;
      goto LABEL_13;
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v4 = *(lua_TValue **)&L->cl.l.upvals[0]->tt;
    if ( *(_BYTE *)(v4->value.b + 7) != 0 )
      v2 = (lua_TValue *)(v4->value.b + 24);
    else
      v2 = &luaO_nilobject_;
  }
  b = v2->value.b;
  ls = *(_DWORD *)(b + 16);
  s = (const char *)(b + 24);
  v3 = (const char *)(b + 24);
LABEL_13:
  v6 = *(lua_TValue **)&L->cl.l.upvals[0]->tt;
  if ( *(_BYTE *)(v6->value.b + 7) < 2u )
    v7 = &luaO_nilobject_;
  else
    v7 = (lua_TValue *)(v6->value.b + 40);
  if ( v7->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v7) == 0 )
    {
      p = nullptr;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v8 = *(lua_TValue **)&L->cl.l.upvals[0]->tt;
    if ( *(_BYTE *)(v8->value.b + 7) < 2u )
      v7 = &luaO_nilobject_;
    else
      v7 = (lua_TValue *)(v8->value.b + 40);
  }
  p = (const char *)(v7->value.b + 24);
LABEL_25:
  ms.L = (lua_State *)L;
  ms.src_init = v3;
  ms.src_end = &v3[ls];
  p_e = index2adr((lua_State *)L, idx: -10005);
  tt = p_e->tt;
  if ( tt == 3 )
  {
LABEL_29:
    e = p_e->value.n;
    v11 = (int)e;
    goto LABEL_30;
  }
  if ( tt == 4 && luaO_str2d(s: (char *)(p_e->value.b + 24), result: &e) )
  {
    v37 = 3;
    p_e = (lua_TValue *)&e;
    goto LABEL_29;
  }
  v11 = 0;
LABEL_30:
  v12 = (char *)&s[v11];
  if ( v12 > ms.src_end )
    return 0;
  while ( 1 )
  {
    ms.level = 0;
    v13 = match(&ms, s: v12, p);
    v14 = (char *)v13;
    LODWORD(e) = v13;
    if ( v13 != nullptr )
      break;
    if ( ++v12 > ms.src_end )
      return 0;
  }
  v16 = v13 - s;
  lsa = (unsigned int)v12;
  if ( v14 == v12 )
    ++v16;
  k = L->p.k;
  k->tt = 3;
  k->value.n = (double)v16;
  L->ts.tsv.hash += 16;
  v18 = **(GCObject ***)&L->cl.l.upvals[0]->tt;
  v19 = L->p.k;
  if ( v18->cl.c.nupvalues < 3u )
    p_hookmask = &luaO_nilobject_;
  else
    p_hookmask = (lua_TValue *)&v18->th.hookmask;
  p_hookmask->value.b = v19[-1].value.b;
  *(&p_hookmask->value.b + 1) = *(&v19[-1].value.b + 1);
  p_hookmask->tt = v19[-1].tt;
  v21 = L->p.k;
  if ( v21[-1].tt >= 4 )
  {
    gc = v21[-1].value.gc;
    if ( (gc->gch.marked & 3) != 0 )
    {
      v23 = **(GCObject ***)&L->cl.l.upvals[0]->tt;
      if ( (v23->gch.marked & 4) != 0 )
        luaC_barrierf((lua_State *)L, o: v23, v: gc);
    }
  }
  L->ts.tsv.hash -= 16;
  level = ms.level;
  if ( ms.level == 0 )
    level = v12 != nullptr;
  v25 = ms.L;
  if ( level > 8000 || (pa = &ms.L->top, level + ms.L->top - ms.L->base > 8000) )
    luaL_error(L: ms.L, fmt: "stack overflow (%s)", "too many captures");
  if ( level > 0 )
  {
    if ( (char *)ms.L->stack_last - (char *)ms.L->top <= 16 * level )
    {
      stacksize = ms.L->stacksize;
      if ( level > stacksize )
        v27 = level + stacksize;
      else
        v27 = 2 * stacksize;
      luaD_reallocstack(L: ms.L, newsize: v27);
    }
    v28 = (unsigned int)&(*pa)[level];
    ci = v25->ci;
    if ( ci->top < (lua_TValue *)v28 )
      ci->top = (lua_TValue *)v28;
    v12 = (char *)lsa;
  }
  for ( i = 0; i < level; ++i )
    push_onecapture(&ms, i, s: v12, e: (const char *)LODWORD(e));
  return level;
}

//------------------------------------------------------------------------------
// Address: 0x1001BD40
// Name: gmatch
// Source: json
//------------------------------------------------------------------------------
int __cdecl gmatch(GCObject *L)
{
  lua_TValue *array; // esi
  lua_TValue *v2; // eax
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // esi
  lua_TValue *v7; // eax
  int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  lua_TValue *v11; // eax

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v2 = L->h.array;
      if ( (unsigned int)v2 >= L->ts.tsv.hash || v2 == &luaO_nilobject_ || (tt = v2->tt) == -1 )
        v4 = "no value";
      else
        v4 = luaT_typenames[tt];
      v5 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v4);
      luaL_argerror((lua_State *)L, extramsg: v5, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  if ( array->value.b == -24 )
    goto LABEL_10;
  v6 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v6 >= L->ts.tsv.hash )
    v6 = &luaO_nilobject_;
  if ( v6->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v6) == 0 )
    {
LABEL_25:
      v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
      if ( (unsigned int)v7 >= L->ts.tsv.hash
        || v7 == &luaO_nilobject_
        || (v8 = *(_DWORD *)(L->ts.tsv.keyhash + 24)) == -1 )
      {
        v9 = "no value";
      }
      else
      {
        v9 = luaT_typenames[v8];
      }
      v10 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v9);
      luaL_argerror((lua_State *)L, extramsg: v10, narg: 2);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v6 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
    if ( (unsigned int)v6 >= L->ts.tsv.hash )
      v6 = &luaO_nilobject_;
  }
  if ( v6->value.b == -24 )
    goto LABEL_25;
  for ( ; L->ts.tsv.hash < L->ts.tsv.keyhash + 32; L->ts.tsv.hash += 16 )
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  v11 = (lua_TValue *)(L->ts.tsv.keyhash + 32);
  L->ts.tsv.hash = (unsigned int)v11;
  v11->value.n = 0.0;
  v11->tt = 3;
  L->ts.tsv.hash += 16;
  lua_pushcclosure((lua_State *)L, fn: (int (__cdecl *)(lua_State *))gmatch_aux, n: 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BED0
// Name: gfind_nodef
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn gfind_nodef(lua_State *L)
{
  luaL_error(L, fmt: "'string.gfind' was renamed to 'string.gmatch'");
}

//------------------------------------------------------------------------------
// Address: 0x1001BEF0
// Name: add_s
// Source: json
//------------------------------------------------------------------------------
void __usercall add_s(luaL_Buffer *b@<edi>, MatchState *ms, char *s, const char *e)
{
  GCObject *v4; // ebx
  lua_TValue *v5; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned int v8; // ebx
  char *p; // eax
  lua_State *v10; // esi
  _DWORD *v11; // ebx
  int v12; // ecx
  lua_State *v13; // esi
  _DWORD *p_b; // ebx
  char v15; // al
  int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+Ch] [ebp-10h]
  unsigned int l; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  unsigned int ia; // [esp+14h] [ebp-8h]
  const char *news; // [esp+18h] [ebp-4h]

  v4 = (GCObject *)ms->L;
  v5 = (lua_TValue *)(v4->ts.tsv.keyhash + 32);
  if ( (unsigned int)v5 >= v4->ts.tsv.hash )
    v5 = &luaO_nilobject_;
  if ( v5->tt != 4 )
  {
    if ( luaV_tostring(L: ms->L, obj: v5) == 0 )
    {
      v6 = nullptr;
      l = 0;
      news = nullptr;
      goto LABEL_11;
    }
    if ( *(_DWORD *)(v4->ts.tsv.len + 68) >= *(_DWORD *)(v4->ts.tsv.len + 64) )
      luaC_step(L: v4);
    v5 = (lua_TValue *)(v4->ts.tsv.keyhash + 32);
    if ( (unsigned int)v5 >= v4->ts.tsv.hash )
      v5 = &luaO_nilobject_;
  }
  v7 = v5->value.b;
  l = *(_DWORD *)(v7 + 16);
  news = (const char *)(v7 + 24);
  v6 = (const char *)(v7 + 24);
LABEL_11:
  v8 = 0;
  for ( i = 0; v8 < l; i = v8 )
  {
    if ( v6[v8] == 37 )
    {
      v12 = (unsigned __int8)v6[v8 + 1];
      ia = ++v8;
      if ( isdigit(c: v12) != 0 )
      {
        v15 = v6[v8];
        if ( v15 == 48 )
        {
          luaL_addlstring(B: b, s, l: e - s);
          v6 = news;
        }
        else
        {
          push_onecapture(ms, i: v15 - 49, s, e);
          luaL_addvalue(B: b);
        }
      }
      else
      {
        if ( b->p >= (char *)&b[1] )
        {
          v17 = b->p - (char *)b - 12;
          if ( b->p - (char *)b != 12 )
          {
            v13 = b->L;
            if ( v13->l_G->totalbytes >= v13->l_G->GCthreshold )
              luaC_step(L: (GCObject *)b->L);
            p_b = &v13->top->value.b;
            *p_b = luaS_newlstr(L: v13, str: b->buffer, l: v17);
            p_b[2] = 4;
            ++v13->top;
            ++b->lvl;
            b->p = b->buffer;
            adjuststack(B: b);
            v8 = ia;
            v6 = news;
          }
        }
        *b->p++ = v6[v8];
      }
    }
    else
    {
      p = b->p;
      if ( b->p >= (char *)&b[1] )
      {
        v16 = p - (char *)b - 12;
        if ( p - (char *)b != 12 )
        {
          v10 = b->L;
          if ( v10->l_G->totalbytes >= v10->l_G->GCthreshold )
            luaC_step(L: (GCObject *)b->L);
          v11 = &v10->top->value.b;
          *v11 = luaS_newlstr(L: v10, str: b->buffer, l: v16);
          v11[2] = 4;
          ++v10->top;
          ++b->lvl;
          b->p = b->buffer;
          adjuststack(B: b);
          v8 = i;
          v6 = news;
        }
      }
      *b->p++ = v6[v8];
    }
    ++v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C0D0
// Name: add_value
// Source: json
//------------------------------------------------------------------------------
void __usercall add_value(MatchState *ms@<ecx>, const char *e@<eax>, luaL_Buffer *b, char *s)
{
  GCObject *L; // esi
  lua_TValue *k; // eax
  lua_TValue *v7; // edx
  int v8; // ebx
  int v9; // eax
  unsigned int hash; // ecx
  const lua_TValue *v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  lua_TValue *v14; // eax
  _DWORD *v15; // ebx
  int tt; // eax
  const char *v17; // eax

  L = (GCObject *)ms->L;
  k = L->p.k;
  v7 = (lua_TValue *)(L->ts.tsv.keyhash + 32);
  if ( v7 >= k || v7 == &luaO_nilobject_ )
    v8 = -1;
  else
    v8 = *(_DWORD *)(L->ts.tsv.keyhash + 40);
  switch ( v8 )
  {
    case 3:
    case 4:
      add_s(b, ms, s, e);
      return;
    case 5:
      push_onecapture(ms, i: 0, s, e);
      hash = L->ts.tsv.hash;
      v11 = (const lua_TValue *)(L->ts.tsv.keyhash + 32);
      if ( (unsigned int)v11 >= hash )
        v11 = &luaO_nilobject_;
      luaV_gettable((lua_State *)L, t: v11, key: (lua_TValue *)(hash - 16), val: (lua_TValue *)(hash - 16));
      goto LABEL_13;
    case 6:
      if ( v7 >= k )
        v7 = &luaO_nilobject_;
      k->value.b = v7->value.b;
      *(&k->value.b + 1) = *(&v7->value.b + 1);
      k->tt = v7->tt;
      L->ts.tsv.hash += 16;
      v9 = push_captures(ms, s, e);
      luaD_call((lua_State *)L, func: (lua_TValue *)(L->ts.tsv.hash - 16 * (v9 + 1)), nResults: 1);
      goto LABEL_13;
    default:
LABEL_13:
      v12 = L->ts.tsv.hash;
      v13 = *(_DWORD *)(v12 - 8);
      v14 = (lua_TValue *)(v12 - 16);
      if ( v13 != 0 && (v13 != 1 || v14->value.b != 0) )
      {
        if ( v14 == &luaO_nilobject_ )
          goto LABEL_24;
        if ( v13 == 4 || v13 == 3 )
        {
          luaL_addvalue(B: b);
          return;
        }
        if ( v14 == &luaO_nilobject_ || (tt = v14->tt) == -1 )
LABEL_24:
          v17 = "no value";
        else
          v17 = luaT_typenames[tt];
        luaL_error((lua_State *)L, fmt: "invalid replacement value (a %s)", v17);
      }
      L->ts.tsv.hash = (unsigned int)v14;
      if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
        luaC_step(L);
      v15 = (_DWORD *)L->ts.tsv.hash;
      *v15 = luaS_newlstr((lua_State *)L, str: s, l: e - s);
      v15[2] = 4;
      L->ts.tsv.hash += 16;
      luaL_addvalue(B: b);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C250
// Name: str_gsub
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_gsub(GCObject *L)
{
  lua_TValue *array; // esi
  int v2; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  char *v7; // edi
  lua_TValue *v8; // eax
  int v9; // eax
  lua_TValue *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  lua_TValue *v14; // ecx
  lua_TValue *k; // edx
  const char *src_end; // eax
  const char *v17; // eax
  char *v18; // esi
  char *v19; // eax
  lua_State *v20; // esi
  _DWORD *p_b; // edi
  lua_State *v22; // esi
  _DWORD *v23; // edi
  lua_TValue *v24; // eax
  _BYTE *n; // [esp+10h] [ebp-340h]
  int na; // [esp+10h] [ebp-340h]
  const char *src; // [esp+14h] [ebp-33Ch]
  int anchor; // [esp+18h] [ebp-338h]
  unsigned int anchora; // [esp+18h] [ebp-338h]
  int tr; // [esp+1Ch] [ebp-334h]
  unsigned int tra; // [esp+1Ch] [ebp-334h]
  int max_s; // [esp+20h] [ebp-330h]
  char *s; // [esp+24h] [ebp-32Ch]
  unsigned int srcl; // [esp+28h] [ebp-328h]
  const char *p; // [esp+2Ch] [ebp-324h]
  luaL_Buffer b; // [esp+30h] [ebp-320h] BYREF
  char v38; // [esp+23Ch] [ebp-114h] BYREF
  MatchState ms; // [esp+240h] [ebp-110h] BYREF

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v2 = array->value.b;
  srcl = *(_DWORD *)(v2 + 16);
  s = (char *)(v2 + 24);
  if ( v2 == -24 )
    goto LABEL_10;
  v7 = (char *)(v2 + 24);
  v8 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  src = (const char *)(v2 + 24);
  if ( (unsigned int)v8 >= L->ts.tsv.hash )
    v8 = &luaO_nilobject_;
  if ( v8->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v8) == 0 )
    {
LABEL_25:
      v10 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
      if ( (unsigned int)v10 >= L->ts.tsv.hash
        || v10 == &luaO_nilobject_
        || (v11 = *(_DWORD *)(L->ts.tsv.keyhash + 24)) == -1 )
      {
        v12 = "no value";
      }
      else
      {
        v12 = luaT_typenames[v11];
      }
      v13 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v12);
      luaL_argerror((lua_State *)L, extramsg: v13, narg: 2);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v8 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
    if ( (unsigned int)v8 >= L->ts.tsv.hash )
      v8 = &luaO_nilobject_;
  }
  v9 = v8->value.b;
  n = (_BYTE *)(v9 + 24);
  if ( v9 == -24 )
    goto LABEL_25;
  v14 = L->h.array;
  k = L->p.k;
  p = (const char *)(v9 + 24);
  if ( &v14[2] >= k || &v14[2] == &luaO_nilobject_ )
    tr = -1;
  else
    tr = v14[2].tt;
  if ( &v14[3] >= k || &v14[3] == &luaO_nilobject_ || v14[3].tt <= 0 )
    max_s = srcl + 1;
  else
    max_s = luaL_checkinteger((lua_State *)L, narg: 4);
  if ( *n == 94 )
  {
    p = n + 1;
    anchor = 1;
  }
  else
  {
    anchor = 0;
  }
  na = 0;
  if ( tr != 3 && tr != 4 && tr != 6 && tr != 5 )
    luaL_argerror((lua_State *)L, extramsg: "string/function/table expected", narg: 3);
  ms.src_init = (const char *)(v2 + 24);
  src_end = &s[srcl];
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  ms.L = (lua_State *)L;
  ms.src_end = &s[srcl];
  if ( max_s > 0 )
  {
    do
    {
      ms.level = 0;
      v17 = match(&ms, s: v7, p);
      v18 = (char *)v17;
      if ( v17 != nullptr && (++na, add_value(&ms, e: v17, &b, s: v7), v18 > v7) )
      {
        src = v18;
        v7 = v18;
      }
      else
      {
        src_end = ms.src_end;
        if ( v7 >= ms.src_end )
          goto LABEL_62;
        v19 = b.p;
        if ( b.p >= &v38 )
        {
          tra = b.p - b.buffer;
          if ( b.p != b.buffer )
          {
            v20 = b.L;
            if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
              luaC_step(L: (GCObject *)b.L);
            p_b = &v20->top->value.b;
            *p_b = luaS_newlstr(L: v20, str: b.buffer, l: tra);
            p_b[2] = 4;
            ++v20->top;
            ++b.lvl;
            b.p = b.buffer;
            adjuststack(B: &b);
            v19 = b.p;
            v7 = (char *)src;
          }
        }
        *v19 = *v7;
        ++b.p;
        src = ++v7;
      }
    }
    while ( anchor == 0 && na < max_s );
    src_end = ms.src_end;
  }
LABEL_62:
  luaL_addlstring(B: &b, s: v7, l: src_end - v7);
  anchora = b.p - b.buffer;
  if ( b.p != b.buffer )
  {
    v22 = b.L;
    if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
      luaC_step(L: (GCObject *)b.L);
    v23 = &v22->top->value.b;
    *v23 = luaS_newlstr(L: v22, str: b.buffer, l: anchora);
    v23[2] = 4;
    ++v22->top;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: b.L, n: b.lvl);
  v24 = L->p.k;
  v24->value.n = (double)na;
  v24->tt = 3;
  L->ts.tsv.hash += 16;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1001C640
// Name: addquoted
// Source: json
//------------------------------------------------------------------------------
void __usercall addquoted(lua_State *L@<eax>, luaL_Buffer *b, int arg)
{
  luaL_Buffer *v3; // ebx
  const char *v5; // eax
  int v6; // edi
  lua_TValue *v7; // eax
  int tt; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // edi
  int v12; // eax
  lua_State *v13; // esi
  _DWORD *p_b; // edi
  lua_State *v15; // esi
  _DWORD *v16; // edi
  lua_State *v17; // esi
  _DWORD *v18; // edi
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+10h] [ebp-8h]
  const char *s; // [esp+14h] [ebp-4h]

  v3 = b;
  v5 = lua_tolstring(L, idx: arg, len: (unsigned int *)&b);
  if ( v5 == nullptr )
  {
    v6 = arg;
    v7 = index2adr(L, idx: arg);
    if ( v7 == &luaO_nilobject_ || (tt = v7->tt) == -1 )
      v9 = "no value";
    else
      v9 = luaT_typenames[tt];
    v10 = lua_pushfstring(L, fmt: "%s expected, got %s", "string", v9);
    luaL_argerror(L, extramsg: v10, narg: v6);
  }
  v11 = v5;
  s = v5;
  if ( v3->p >= (char *)&v3[1] )
    luaL_prepbuffer(B: v3);
  for ( *v3->p++ = 34; b != nullptr; s = v11 )
  {
    v12 = *v11;
    b = (luaL_Buffer *)((char *)b - 1);
    switch ( v12 )
    {
      case 0:
        luaL_addlstring(B: v3, s: "\\000", l: 4u);
        break;
      case 10:
      case 34:
      case 92:
        if ( v3->p >= (char *)&v3[1] )
        {
          v19 = v3->p - (char *)v3 - 12;
          if ( v3->p - (char *)v3 != 12 )
          {
            v13 = v3->L;
            if ( v13->l_G->totalbytes >= v13->l_G->GCthreshold )
              luaC_step(L: (GCObject *)v3->L);
            p_b = &v13->top->value.b;
            *p_b = luaS_newlstr(L: v13, str: v3->buffer, l: v19);
            p_b[2] = 4;
            ++v13->top;
            ++v3->lvl;
            v3->p = v3->buffer;
            adjuststack(B: v3);
          }
        }
        *v3->p++ = 92;
        if ( v3->p >= (char *)&v3[1] )
        {
          v20 = v3->p - (char *)v3 - 12;
          if ( v3->p - (char *)v3 != 12 )
          {
            v15 = v3->L;
            if ( v15->l_G->totalbytes >= v15->l_G->GCthreshold )
              luaC_step(L: (GCObject *)v3->L);
            v16 = &v15->top->value.b;
            *v16 = luaS_newlstr(L: v15, str: v3->buffer, l: v20);
            v16[2] = 4;
            ++v15->top;
            ++v3->lvl;
            v3->p = v3->buffer;
            adjuststack(B: v3);
          }
        }
        v11 = s;
        *v3->p = *s;
        goto LABEL_30;
      case 13:
        luaL_addlstring(B: v3, s: "\\r", l: 2u);
        break;
      default:
        if ( v3->p >= (char *)&v3[1] )
        {
          v21 = v3->p - (char *)v3 - 12;
          if ( v3->p - (char *)v3 != 12 )
          {
            v17 = v3->L;
            if ( v17->l_G->totalbytes >= v17->l_G->GCthreshold )
              luaC_step(L: (GCObject *)v3->L);
            v18 = &v17->top->value.b;
            *v18 = luaS_newlstr(L: v17, str: v3->buffer, l: v21);
            v18[2] = 4;
            ++v17->top;
            ++v3->lvl;
            v3->p = v3->buffer;
            adjuststack(B: v3);
          }
        }
        v11 = s;
        *v3->p = *s;
LABEL_30:
        ++v3->p;
        break;
    }
    ++v11;
  }
  if ( v3->p >= (char *)&v3[1] )
    luaL_prepbuffer(B: v3);
  *v3->p++ = 34;
}

//------------------------------------------------------------------------------
// Address: 0x1001C900
// Name: scanformat
// Source: json
//------------------------------------------------------------------------------
const char *__usercall scanformat@<eax>(lua_State *L@<eax>, char *strfrmt, char *form)
{
  unsigned __int8 *v4; // esi
  int v5; // eax
  int v6; // ecx
  char *forma; // [esp+1Ch] [ebp+Ch]

  v4 = (unsigned __int8 *)strfrmt;
  if ( *strfrmt != 0 )
  {
    do
    {
      strchr(string: "-+ #0", chr: *v4);
      if ( v5 == 0 )
        break;
      ++v4;
    }
    while ( *v4 != 0 );
  }
  if ( (unsigned int)(v4 - (unsigned __int8 *)strfrmt) >= 6 )
    luaL_error(L, fmt: "invalid format (repeated flags)");
  if ( isdigit(c: *v4) != 0 )
    ++v4;
  if ( isdigit(c: *v4) != 0 )
    ++v4;
  if ( *v4 == 46 )
  {
    v6 = *++v4;
    if ( isdigit(c: v6) != 0 )
      ++v4;
    if ( isdigit(c: *v4) != 0 )
      ++v4;
  }
  if ( isdigit(c: *v4) != 0 )
    luaL_error(L, fmt: "invalid format (width or precision too long)");
  *form = 37;
  forma = form + 1;
  strncpy(
    dest: (unsigned __int8 *)forma,
    source: (unsigned __int8 *)strfrmt,
    count: v4 - (unsigned __int8 *)strfrmt + 1);
  forma[v4 - (unsigned __int8 *)strfrmt + 1] = 0;
  return (const char *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9E0
// Name: str_format
// Source: json
//------------------------------------------------------------------------------
int __usercall str_format@<eax>(double a1@<xmm0>, GCObject *L)
{
  int v2; // esi
  char *v3; // eax
  lua_TValue *v4; // eax
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  GCObject *v8; // ecx
  char *buffer; // edx
  lua_State *v11; // esi
  _DWORD *v12; // edi
  lua_State *v13; // esi
  _DWORD *p_b; // edi
  const char *v15; // eax
  int v16; // eax
  unsigned int v17; // kr00_4
  char v18; // cl
  unsigned int v19; // kr04_4
  char v20; // cl
  const char *v21; // edi
  int v22; // eax
  const char *strfrmt; // [esp+3Ch] [ebp-44Ch]
  const char *strfrmta; // [esp+3Ch] [ebp-44Ch]
  unsigned int sfl; // [esp+40h] [ebp-448h] BYREF
  int arg; // [esp+44h] [ebp-444h]
  char form[20]; // [esp+48h] [ebp-440h] BYREF
  unsigned int l; // [esp+5Ch] [ebp-42Ch] BYREF
  __int64 v29; // [esp+60h] [ebp-428h]
  const char *strfrmt_end; // [esp+6Ch] [ebp-41Ch]
  double v31; // [esp+70h] [ebp-418h]
  luaL_Buffer b; // [esp+78h] [ebp-410h] BYREF
  char v33; // [esp+284h] [ebp-204h] BYREF
  char buff[512]; // [esp+288h] [ebp-200h] BYREF

  v2 = 1;
  arg = 1;
  v3 = (char *)lua_tolstring((lua_State *)L, idx: 1, len: &sfl);
  if ( v3 == nullptr )
  {
    v4 = index2adr((lua_State *)L, idx: 1);
    if ( v4 == &luaO_nilobject_ || (tt = v4->tt) == -1 )
      v6 = "no value";
    else
      v6 = luaT_typenames[tt];
    v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v6);
    luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
  }
  v8 = L;
  buffer = b.buffer;
  strfrmt = v3;
  strfrmt_end = &v3[sfl];
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  if ( v3 < &v3[sfl] )
  {
    while ( 1 )
    {
      if ( *v3 == 37 )
      {
        strfrmta = ++v3;
        if ( *v3 == 37 )
        {
          if ( buffer >= &v33 )
          {
            sfl = buffer - b.buffer;
            if ( buffer != b.buffer )
            {
              v13 = (lua_State *)v8;
              if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
                luaC_step(L: v8);
              p_b = &v13->top->value.b;
              *p_b = luaS_newlstr(L: v13, str: b.buffer, l: sfl);
              p_b[2] = 4;
              ++v13->top;
              ++b.lvl;
              b.p = b.buffer;
              adjuststack(B: &b);
              v3 = (char *)strfrmta;
              v2 = arg;
            }
          }
LABEL_22:
          *b.p++ = *v3;
          strfrmt = ++v3;
          goto LABEL_36;
        }
        arg = ++v2;
        v15 = scanformat((lua_State *)L, strfrmt: v3, form);
        strfrmt = v15 + 1;
        switch ( *v15 )
        {
          case 'E':
          case 'G':
          case 'e':
          case 'f':
          case 'g':
            luaL_checknumber((lua_State *)L, narg: v2);
            sprintf(string: buff, format: form, LODWORD(a1), HIDWORD(a1));
            goto LABEL_34;
          case 'X':
          case 'o':
          case 'u':
          case 'x':
            v19 = strlen(form);
            v20 = form[v19 - 1];
            *(_WORD *)&form[v19 - 1] = 108;
            form[v19] = v20;
            form[v19 + 1] = 0;
            luaL_checknumber((lua_State *)L, narg: v2);
            v31 = a1;
            v29 = (__int64)a1;
            v16 = (__int64)a1;
            goto LABEL_25;
          case 'c':
            luaL_checknumber((lua_State *)L, narg: v2);
            v16 = (int)a1;
LABEL_25:
            sprintf(string: buff, format: form, v16);
            goto LABEL_34;
          case 'd':
          case 'i':
            v17 = strlen(form);
            v18 = form[v17 - 1];
            *(_WORD *)&form[v17 - 1] = 108;
            form[v17] = v18;
            form[v17 + 1] = 0;
            luaL_checknumber((lua_State *)L, narg: v2);
            sprintf(string: buff, format: form, (int)a1);
            goto LABEL_34;
          case 'q':
            addquoted((lua_State *)L, &b, arg: v2);
            goto LABEL_35;
          case 's':
            v21 = luaL_checklstring((lua_State *)L, len: &l, narg: v2);
            strchr(string: (unsigned __int8 *)form, chr: 0x2Eu);
            if ( v22 != 0 || l < 0x64 )
            {
              sprintf(string: buff, format: form, v21);
LABEL_34:
              luaL_addlstring(B: &b, s: buff, l: strlen(buff));
              v2 = arg;
            }
            else
            {
              lua_pushvalue((lua_State *)L, idx: v2);
              luaL_addvalue(B: &b);
              v2 = arg;
            }
LABEL_35:
            v3 = (char *)strfrmt;
            break;
          default:
            luaL_error((lua_State *)L, fmt: "invalid option '%%%c' to 'format'", *v15);
        }
      }
      else
      {
        if ( buffer < &v33 )
          goto LABEL_22;
        sfl = buffer - b.buffer;
        if ( buffer == b.buffer )
          goto LABEL_22;
        v11 = (lua_State *)v8;
        if ( *(_DWORD *)(v8->ts.tsv.len + 68) >= *(_DWORD *)(v8->ts.tsv.len + 64) )
          luaC_step(L: v8);
        v12 = &v11->top->value.b;
        *v12 = luaS_newlstr(L: v11, str: b.buffer, l: sfl);
        v12[2] = 4;
        ++v11->top;
        ++b.lvl;
        b.p = b.buffer;
        adjuststack(B: &b);
        v2 = arg;
        *b.p++ = *strfrmt;
        v3 = (char *)++strfrmt;
      }
LABEL_36:
      if ( v3 >= strfrmt_end )
        break;
      v8 = (GCObject *)b.L;
      buffer = b.p;
    }
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001CE40
// Name: createmetatable
// Source: json
//------------------------------------------------------------------------------
void __usercall createmetatable(GCObject *L@<eax>)
{
  lua_TValue *k; // edi
  lua_TValue *v3; // eax
  lua_TValue *v4; // eax
  const lua_TValue *v5; // edi
  GCObject *v6; // eax
  lua_TValue *v7; // [esp-4h] [ebp-1Ch]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  lua_createtable((lua_State *)L, narray: 1);
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  k = L->p.k;
  k->value.b = (int)luaS_newlstr((lua_State *)L, str: (char *)Ptr, l: 0);
  k->tt = 4;
  L->ts.tsv.hash += 16;
  v3 = L->p.k;
  v3->value.b = v3[-2].value.b;
  *(&v3->value.b + 1) = *(&v3[-2].value.b + 1);
  v3->tt = v3[-2].tt;
  L->ts.tsv.hash += 16;
  lua_setmetatable((lua_State *)L, objindex: -2);
  L->ts.tsv.hash -= 16;
  v4 = L->p.k;
  v4->value.b = v4[-2].value.b;
  *(&v4->value.b + 1) = *(&v4[-2].value.b + 1);
  v4->tt = v4[-2].tt;
  L->ts.tsv.hash += 16;
  v5 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v6 = luaS_newlstr((lua_State *)L, str: "__index", l: 7u);
  v7 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v6;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v5, &key, val: v7);
  L->ts.tsv.hash -= 32;
}

//------------------------------------------------------------------------------
// Address: 0x1001CF10
// Name: _luaopen_string
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_string(GCObject *L)
{
  const lua_TValue *v1; // edi
  const lua_TValue *v2; // edi
  GCObject *v3; // eax
  lua_TValue *k; // [esp-4h] [ebp-1Ch]
  lua_TValue *v6; // [esp-4h] [ebp-1Ch]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  luaL_openlib((lua_State *)L, libname: "string", l: strlib);
  v1 = (const lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "gmatch", l: 6u);
  k = L->p.k;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v1, &key, val: k);
  L->ts.tsv.hash += 16;
  v2 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v3 = luaS_newlstr((lua_State *)L, str: "gfind", l: 5u);
  v6 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v3;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v2, &key, val: v6);
  L->ts.tsv.hash -= 16;
  createmetatable(L);
  return 1;
}
