// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/loslib.c
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10013BE0
// Name: os_pushresult
// Source: json
//------------------------------------------------------------------------------
int __usercall os_pushresult@<eax>(lua_State *L@<esi>, int i, const char *filename)
{
  int v3; // edi
  lua_TValue *top; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax

  v3 = *_errno();
  top = L->top;
  if ( i != 0 )
  {
    top->value.b = 1;
    top->tt = 1;
    ++L->top;
    return 1;
  }
  else
  {
    top->tt = 0;
    ++L->top;
    v6 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s: %s", filename, v6);
    v7 = L->top;
    v7->value.n = (double)v3;
    v7->tt = 3;
    ++L->top;
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013C60
// Name: os_execute
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_execute(lua_State *L)
{
  lua_TValue *base; // eax
  const char *v2; // eax
  int v3; // eax
  lua_TValue *top; // ecx

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt <= 0 )
    v2 = nullptr;
  else
    v2 = luaL_checklstring(L, len: nullptr, narg: 1);
  v3 = system(command: v2);
  top = L->top;
  top->value.n = (double)v3;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013CC0
// Name: os_remove
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_remove(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  char *path; // [esp+8h] [ebp-4h]

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
  path = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = remove(path);
  return os_pushresult((lua_State *)L, i: v7 == 0, filename: path);
}

//------------------------------------------------------------------------------
// Address: 0x10013D90
// Name: os_rename
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_rename(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // esi
  int v8; // esi
  lua_TValue *v9; // eax
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  char *oldname; // [esp+10h] [ebp-4h]

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
  oldname = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v7 >= L->ts.tsv.hash )
    v7 = &luaO_nilobject_;
  if ( v7->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v7) == 0 )
    {
LABEL_25:
      v9 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
      if ( (unsigned int)v9 >= L->ts.tsv.hash
        || v9 == &luaO_nilobject_
        || (v10 = *(_DWORD *)(L->ts.tsv.keyhash + 24)) == -1 )
      {
        v11 = "no value";
      }
      else
      {
        v11 = luaT_typenames[v10];
      }
      v12 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v11);
      luaL_argerror((lua_State *)L, extramsg: v12, narg: 2);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
    if ( (unsigned int)v7 >= L->ts.tsv.hash )
      v7 = &luaO_nilobject_;
  }
  v8 = v7->value.b;
  if ( v8 == -24 )
    goto LABEL_25;
  v13 = rename(oldname, newname: (const char *)(v8 + 24));
  return os_pushresult((lua_State *)L, i: v13 == 0, filename: oldname);
}

//------------------------------------------------------------------------------
// Address: 0x10013F00
// Name: os_tmpname
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_tmpname(lua_State *L)
{
  char buff[16]; // [esp+0h] [ebp-10h] BYREF

  if ( tmpnam(s: buff) == nullptr )
    luaL_error(L, fmt: "unable to generate a unique filename");
  lua_pushstring(L, s: buff);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013F50
// Name: os_getenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_getenv(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned int v9; // edi
  lua_TValue *k; // esi
  char *option; // [esp+Ch] [ebp-4h]

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
  v7 = getenv(option: (const char *)(b + 24));
  option = (char *)v7;
  if ( v7 != nullptr )
  {
    v9 = strlen(v7);
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    k = L->p.k;
    k->value.b = (int)luaS_newlstr((lua_State *)L, str: option, l: v9);
    k->tt = 4;
    L->ts.tsv.hash += 16;
    return 1;
  }
  else
  {
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
    L->ts.tsv.hash += 16;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014070
// Name: os_clock
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_clock(lua_State *L)
{
  int v1; // eax
  lua_TValue *top; // ecx

  v1 = clock();
  top = L->top;
  top->value.n = (double)v1 * 0.001;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100140B0
// Name: setboolfield
// Source: json
//------------------------------------------------------------------------------
void __usercall setboolfield(lua_State *L@<esi>, int value@<ecx>)
{
  lua_TValue *top; // eax
  const lua_TValue *v3; // edi
  lua_TValue *v4; // [esp-10h] [ebp-28h]
  lua_TValue v5; // [esp+8h] [ebp-10h] BYREF

  if ( value >= 0 )
  {
    top = L->top;
    top->tt = 1;
    top->value.b = value != 0;
    v3 = ++L->top - 2;
    v5.value.b = (int)luaS_newlstr(L, str: "isdst", l: 5u);
    v4 = L->top - 1;
    v5.tt = 4;
    luaV_settable(L, t: v3, key: &v5, val: v4);
    --L->top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014120
// Name: getboolfield
// Source: json
//------------------------------------------------------------------------------
int __usercall getboolfield@<eax>(lua_State *L@<esi>)
{
  const lua_TValue *v1; // edi
  lua_TValue *v2; // ecx
  int tt; // eax
  lua_TValue *top; // [esp-10h] [ebp-28h]
  lua_TValue v6; // [esp+8h] [ebp-10h] BYREF

  v1 = L->top - 1;
  v6.value.b = (int)luaS_newlstr(L, str: "isdst", l: 5u);
  top = L->top;
  v6.tt = 4;
  luaV_gettable(L, t: v1, key: &v6, val: top);
  v2 = L->top++;
  if ( v2 == &luaO_nilobject_ || v2->tt != 0 )
  {
    tt = v2->tt;
    if ( tt != 0 && (tt != 1 || v2->value.b != 0) )
    {
      L->top = v2;
      return 1;
    }
    else
    {
      L->top = v2;
      return 0;
    }
  }
  else
  {
    L->top = v2;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100141B0
// Name: getfield
// Source: json
//------------------------------------------------------------------------------
int __cdecl getfield(lua_State *L, const char *key, int d)
{
  const char *v3; // edi
  const lua_TValue *v4; // esi
  lua_TValue *v5; // ecx
  int tt; // eax
  lua_TValue *v7; // eax
  int v8; // ecx
  int result; // eax
  lua_TValue *top; // [esp-4h] [ebp-2Ch]
  long double v11; // [esp+10h] [ebp-18h] BYREF
  lua_TValue v12; // [esp+18h] [ebp-10h] BYREF

  v3 = key;
  v4 = L->top - 1;
  v12.value.b = (int)luaS_newlstr(L, str: key, l: strlen(key));
  top = L->top;
  v12.tt = 4;
  luaV_gettable(L, t: v4, key: &v12, val: top);
  v5 = ++L->top;
  tt = v5[-1].tt;
  if ( tt != 3 )
  {
    if ( tt == 4 )
    {
      if ( luaO_str2d(s: (char *)(v5[-1].value.b + 24), result: (long double *)&v12) )
        goto LABEL_4;
      v3 = key;
    }
    result = d;
    if ( d < 0 )
      luaL_error(L, fmt: "field '%s' missing in date table", v3);
    goto LABEL_9;
  }
LABEL_4:
  v7 = index2adr(L, idx: -1);
  v8 = v7->tt;
  if ( v8 == 3 )
  {
LABEL_8:
    v12.value.n = v7->value.n;
    LODWORD(v11) = (int)v12.value.n;
    result = (int)v12.value.n;
LABEL_9:
    --L->top;
    return result;
  }
  if ( v8 == 4 && luaO_str2d(s: (char *)(v7->value.b + 24), result: &v11) )
  {
    v12.value.n = v11;
    v12.tt = 3;
    v7 = &v12;
    goto LABEL_8;
  }
  --L->top;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100142C0
// Name: os_date
// Source: json
//------------------------------------------------------------------------------
int __usercall os_date@<eax>(double a1@<xmm0>, GCObject *L)
{
  GCObject *v2; // esi
  lua_TValue *array; // eax
  const char *v4; // ebx
  lua_TValue *v5; // eax
  __int64 v6; // rax
  tm *v7; // eax
  const tm *v8; // edi
  lua_TValue *k; // eax
  const lua_TValue *v11; // ebx
  lua_TValue *v12; // eax
  __m128i v13; // xmm0
  TString *v14; // eax
  lua_TValue *v15; // eax
  __m128i v16; // xmm0
  TString *v17; // eax
  lua_TValue *v18; // eax
  __m128i v19; // xmm0
  TString *v20; // eax
  lua_TValue *v21; // eax
  int v22; // edx
  lua_TValue *v23; // eax
  int v24; // ecx
  TString *v25; // eax
  lua_TValue *v26; // eax
  int v27; // edx
  lua_TValue *v28; // eax
  int v29; // ecx
  TString *v30; // eax
  char v31; // al
  char *buffer; // ecx
  char v33; // dl
  unsigned int v34; // eax
  _DWORD *hash; // ebx
  unsigned int v36; // ebx
  _DWORD *v37; // edi
  lua_TValue *v38; // [esp-4h] [ebp-30Ch]
  lua_TValue *v39; // [esp-4h] [ebp-30Ch]
  lua_TValue *v40; // [esp-4h] [ebp-30Ch]
  lua_TValue *v41; // [esp-4h] [ebp-30Ch]
  lua_TValue *v42; // [esp-4h] [ebp-30Ch]
  lua_TValue *v43; // [esp-4h] [ebp-30Ch]
  lua_TValue *v44; // [esp-4h] [ebp-30Ch]
  lua_TValue *v45; // [esp-4h] [ebp-30Ch]
  const char *s; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *sa; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *sb; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *sc; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *sd; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *se; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *sf; // [esp+Ch] [ebp-2FCh]
  const lua_TValue *sg; // [esp+Ch] [ebp-2FCh]
  lua_TValue key; // [esp+10h] [ebp-2F8h] BYREF
  char cc[4]; // [esp+24h] [ebp-2E4h] BYREF
  __int64 t; // [esp+28h] [ebp-2E0h] BYREF
  luaL_Buffer b; // [esp+30h] [ebp-2D8h] BYREF
  char v58; // [esp+23Ch] [ebp-CCh] BYREF
  char buff[200]; // [esp+240h] [ebp-C8h] BYREF

  v2 = L;
  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash || array == &luaO_nilobject_ || array->tt <= 0 )
  {
    v4 = "%c";
    s = "%c";
  }
  else
  {
    s = luaL_checklstring((lua_State *)L, len: nullptr, narg: 1);
    v4 = s;
  }
  v5 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v5 >= L->ts.tsv.hash || v5 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 24) <= 0 )
  {
    v6 = _time64(timeptr: nullptr);
  }
  else
  {
    luaL_checknumber((lua_State *)L, narg: 2);
    key.value.n = a1;
    v6 = (unsigned __int64)a1;
  }
  t = v6;
  if ( *v4 == 33 )
  {
    v7 = _gmtime64(timp: &t);
    s = ++v4;
  }
  else
  {
    v7 = _localtime64(ptime: &t);
  }
  v8 = v7;
  if ( v7 != nullptr )
  {
    if ( strcmp(v4, "*t") == 0 )
    {
      lua_createtable((lua_State *)L, narray: 9);
      k = L->p.k;
      k->value.n = (double)v8->tm_sec;
      k->tt = 3;
      L->ts.tsv.hash += 16;
      v11 = (const lua_TValue *)(L->ts.tsv.hash - 32);
      key.value.b = (int)luaS_newlstr((lua_State *)L, str: "sec", l: 3u);
      v38 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.tt = 4;
      luaV_settable((lua_State *)L, t: v11, &key, val: v38);
      L->ts.tsv.hash -= 16;
      v12 = L->p.k;
      v13 = _mm_cvtsi32_si128(v8->tm_min);
      v12->tt = 3;
      v12->value.n = _mm_cvtepi32_pd(v13).m128d_f64[0];
      L->ts.tsv.hash += 16;
      sa = (const lua_TValue *)(L->ts.tsv.hash - 32);
      v14 = luaS_newlstr((lua_State *)L, str: "min", l: 3u);
      v39 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.value.b = (int)v14;
      key.tt = 4;
      luaV_settable((lua_State *)L, t: sa, &key, val: v39);
      L->ts.tsv.hash -= 16;
      v15 = L->p.k;
      v16 = _mm_cvtsi32_si128(v8->tm_hour);
      v15->tt = 3;
      v15->value.n = _mm_cvtepi32_pd(v16).m128d_f64[0];
      L->ts.tsv.hash += 16;
      sb = (const lua_TValue *)(L->ts.tsv.hash - 32);
      v17 = luaS_newlstr((lua_State *)L, str: "hour", l: 4u);
      v40 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.value.b = (int)v17;
      key.tt = 4;
      luaV_settable((lua_State *)L, t: sb, &key, val: v40);
      L->ts.tsv.hash -= 16;
      v18 = L->p.k;
      v19 = _mm_cvtsi32_si128(v8->tm_mday);
      v18->tt = 3;
      v18->value.n = _mm_cvtepi32_pd(v19).m128d_f64[0];
      L->ts.tsv.hash += 16;
      sc = (const lua_TValue *)(L->ts.tsv.hash - 32);
      v20 = luaS_newlstr((lua_State *)L, str: "day", l: 3u);
      v41 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.value.b = (int)v20;
      key.tt = 4;
      luaV_settable((lua_State *)L, t: sc, &key, val: v41);
      L->ts.tsv.hash -= 16;
      v21 = L->p.k;
      v22 = v8->tm_mon + 1;
      v21->tt = 3;
      v21->value.n = (double)v22;
      L->ts.tsv.hash += 16;
      sd = (const lua_TValue *)(L->ts.tsv.hash - 32);
      key.value.b = (int)luaS_newlstr((lua_State *)L, str: "month", l: 5u);
      v42 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.tt = 4;
      luaV_settable((lua_State *)L, t: sd, &key, val: v42);
      L->ts.tsv.hash -= 16;
      v23 = L->p.k;
      v24 = v8->tm_year + 1900;
      v23->tt = 3;
      v23->value.n = (double)v24;
      L->ts.tsv.hash += 16;
      se = (const lua_TValue *)(L->ts.tsv.hash - 32);
      v25 = luaS_newlstr((lua_State *)L, str: "year", l: 4u);
      v43 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.value.b = (int)v25;
      key.tt = 4;
      luaV_settable((lua_State *)L, t: se, &key, val: v43);
      L->ts.tsv.hash -= 16;
      v26 = L->p.k;
      v27 = v8->tm_wday + 1;
      v26->tt = 3;
      v26->value.n = (double)v27;
      L->ts.tsv.hash += 16;
      sf = (const lua_TValue *)(L->ts.tsv.hash - 32);
      key.value.b = (int)luaS_newlstr((lua_State *)L, str: "wday", l: 4u);
      v44 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.tt = 4;
      luaV_settable((lua_State *)L, t: sf, &key, val: v44);
      L->ts.tsv.hash -= 16;
      v28 = L->p.k;
      v29 = v8->tm_yday + 1;
      v28->tt = 3;
      v28->value.n = (double)v29;
      L->ts.tsv.hash += 16;
      sg = (const lua_TValue *)(L->ts.tsv.hash - 32);
      v30 = luaS_newlstr((lua_State *)L, str: "yday", l: 4u);
      v45 = (lua_TValue *)(L->ts.tsv.hash - 16);
      key.value.b = (int)v30;
      key.tt = 4;
      luaV_settable((lua_State *)L, t: sg, &key, val: v45);
      L->ts.tsv.hash -= 16;
      setboolfield((lua_State *)L, value: v8->tm_isdst);
      return 1;
    }
    else
    {
      v31 = *v4;
      buffer = b.buffer;
      cc[0] = 37;
      cc[2] = 0;
      b.L = (lua_State *)L;
      b.p = b.buffer;
      for ( b.lvl = 0; v31 != 0; s = v4 )
      {
        if ( v31 == 37 && v4[1] != 0 )
        {
          v33 = *++v4;
          cc[1] = v33;
          v34 = strftime(string: buff, maxsize: 0xC8u, format: cc, timeptr: v8);
          luaL_addlstring(B: &b, s: buff, l: v34);
          buffer = b.p;
        }
        else
        {
          if ( buffer >= &v58 )
          {
            key.value.b = buffer - b.buffer;
            if ( buffer != b.buffer )
            {
              if ( *(_DWORD *)(v2->ts.tsv.len + 68) >= *(_DWORD *)(v2->ts.tsv.len + 64) )
                luaC_step(L: v2);
              hash = (_DWORD *)v2->ts.tsv.hash;
              *hash = luaS_newlstr(L: (lua_State *)v2, str: b.buffer, l: (unsigned int)key.value.gc);
              hash[2] = 4;
              v2->ts.tsv.hash += 16;
              ++b.lvl;
              b.p = b.buffer;
              adjuststack(B: &b);
              buffer = b.p;
              v4 = s;
            }
          }
          *buffer = *v4;
          buffer = ++b.p;
        }
        v31 = v4[1];
        v2 = (GCObject *)b.L;
        ++v4;
      }
      v36 = buffer - b.buffer;
      if ( buffer != b.buffer )
      {
        if ( *(_DWORD *)(v2->ts.tsv.len + 68) >= *(_DWORD *)(v2->ts.tsv.len + 64) )
          luaC_step(L: v2);
        v37 = (_DWORD *)v2->ts.tsv.hash;
        *v37 = luaS_newlstr(L: (lua_State *)v2, str: b.buffer, l: v36);
        v37[2] = 4;
        v2->ts.tsv.hash += 16;
        v2 = (GCObject *)b.L;
        ++b.lvl;
        b.p = b.buffer;
      }
      lua_concat(L: (lua_State *)v2, n: b.lvl);
      return 1;
    }
  }
  else
  {
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
    L->ts.tsv.hash += 16;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014830
// Name: os_time
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_time(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  __int64 v3; // rax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  bool v7; // zf
  lua_TValue *v8; // eax
  __int64 t; // [esp+10h] [ebp-30h]
  tm ts; // [esp+1Ch] [ebp-24h] BYREF

  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt <= 0 )
  {
    v3 = _time64(timeptr: nullptr);
    goto LABEL_17;
  }
  if ( base >= top )
    goto LABEL_11;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v5 = luaT_typenames[tt];
LABEL_13:
        v6 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v5);
        luaL_argerror(L, extramsg: v6, narg: 1);
      }
    }
LABEL_11:
    v5 = "no value";
    goto LABEL_13;
  }
  for ( ; L->top < L->base + 1; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 1;
  ts.tm_sec = getfield(L, key: "sec", d: 0);
  ts.tm_min = getfield(L, key: "min", d: 0);
  ts.tm_hour = getfield(L, key: "hour", d: 12);
  ts.tm_mday = getfield(L, key: "day", d: -1);
  ts.tm_mon = getfield(L, key: "month", d: -1) - 1;
  ts.tm_year = getfield(L, key: "year", d: -1) - 1900;
  ts.tm_isdst = getboolfield(L);
  v3 = _mktime64(tb: &ts);
LABEL_17:
  t = v3;
  v7 = (HIDWORD(v3) & (unsigned int)v3) == -1;
  v8 = L->top;
  if ( v7 )
  {
    v8->tt = 0;
  }
  else
  {
    v8->tt = 3;
    v8->value.n = (double)t;
  }
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100149C0
// Name: os_difftime
// Source: json
//------------------------------------------------------------------------------
int __usercall os_difftime@<eax>(double a1@<xmm0>, lua_State *L)
{
  lua_TValue *v2; // eax
  long double v3; // st7
  lua_TValue *top; // eax

  v2 = L->base + 1;
  if ( v2 >= L->top || v2 == &luaO_nilobject_ || L->base[1].tt <= 0 )
    a1 = 0.0;
  else
    luaL_checknumber(L, narg: 2);
  luaL_checknumber(L, narg: 1);
  v3 = _difftime64(b: (unsigned __int64)a1, a: (unsigned __int64)a1);
  top = L->top;
  top->value.n = v3;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014A50
// Name: os_setlocale
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_setlocale(GCObject *L)
{
  lua_TValue *array; // eax
  const char *v2; // edi
  int v3; // eax
  const char *v4; // eax
  const char *v5; // ebx
  lua_TValue *k; // edi
  unsigned int l; // [esp+Ch] [ebp-4h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash || array == &luaO_nilobject_ || array->tt <= 0 )
    v2 = nullptr;
  else
    v2 = luaL_checklstring((lua_State *)L, len: nullptr, narg: 1);
  v3 = luaL_checkoption(def: "all", lst: (const char **)catnames, (lua_State *)L, narg: 2);
  v4 = setlocale(_category: cat[v3], _locale: v2);
  v5 = v4;
  if ( v4 != nullptr )
  {
    l = strlen(v4);
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    k = L->p.k;
    k->value.b = (int)luaS_newlstr((lua_State *)L, str: v5, l);
    k->tt = 4;
    L->ts.tsv.hash += 16;
    return 1;
  }
  else
  {
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
    L->ts.tsv.hash += 16;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014B10
// Name: os_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn os_exit(lua_State *L)
{
  lua_TValue *base; // eax
  int v2; // eax

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt <= 0 )
    v2 = 0;
  else
    v2 = luaL_checkinteger(L, narg: 1);
  exit(code: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10014B50
// Name: _luaopen_os
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_os(lua_State *L)
{
  luaL_openlib(L, libname: "os", l: syslib);
  return 1;
}
