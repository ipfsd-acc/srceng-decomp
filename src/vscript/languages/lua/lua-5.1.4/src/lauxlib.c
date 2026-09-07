// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lauxlib.c
// Functions: 28
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001DA0
// Name: _luaL_argerror
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn luaL_argerror(lua_State *L@<esi>, const char *extramsg@<edi>, int narg)
{
  CallInfo *ci; // eax
  CallInfo *base_ci; // ecx
  int v5; // ebx
  const char *name; // eax
  lua_Debug ar; // [esp+4h] [ebp-68h] BYREF

  ci = L->ci;
  base_ci = L->base_ci;
  v5 = narg;
  if ( ci > base_ci )
  {
    ar.i_ci = ci - base_ci;
    lua_getinfo(L, what: "n", &ar);
    if ( strcmp(ar.namewhat, "method") == 0 )
    {
      v5 = narg - 1;
      if ( narg == 1 )
        luaL_error(L, fmt: "calling '%s' on bad self (%s)", ar.name, extramsg);
    }
    name = ar.name;
    if ( ar.name == nullptr )
    {
      name = "?";
      ar.name = "?";
    }
    luaL_error(L, fmt: "bad argument #%d to '%s' (%s)", v5, name, extramsg);
  }
  luaL_error(L, fmt: "bad argument #%d (%s)", narg, extramsg);
}

//------------------------------------------------------------------------------
// Address: 0x10001E70
// Name: _luaL_where
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_where(lua_State *L@<esi>, int level@<ecx>)
{
  lua_TValue *top; // edi
  lua_Debug ar; // [esp+8h] [ebp-68h] BYREF

  if ( lua_getstack(L, level, &ar) != 0 && (lua_getinfo(L, what: "Sl", &ar), ar.currentline > 0) )
  {
    lua_pushfstring(L, fmt: "%s:%d: ", ar.short_src, ar.currentline);
  }
  else
  {
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    top->value.b = (int)luaS_newlstr(L, str: Ptr, l: 0);
    top->tt = 4;
    ++L->top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EF0
// Name: _luaL_error
// Source: json
//------------------------------------------------------------------------------
void __noreturn luaL_error(lua_State *L, const char *fmt, ...)
{
  va_list argp; // [esp+18h] [ebp+10h] BYREF

  va_start(argp, fmt);
  luaL_where(L, level: 1);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  luaO_pushvfstring(L, fmt, argp);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  luaV_concat(L, total: 2, last: L->top - L->base - 1);
  --L->top;
  luaG_errormsg(L);
}

//------------------------------------------------------------------------------
// Address: 0x10001F70
// Name: _luaL_checkoption
// Source: json
//------------------------------------------------------------------------------
int __usercall luaL_checkoption@<eax>(const char *def@<ecx>, const char **lst@<eax>, lua_State *L, int narg)
{
  lua_State *v6; // ebx
  lua_TValue *v7; // eax
  const char *v8; // eax
  const char *v9; // ecx
  int v10; // edi
  const char *v11; // eax

  if ( def != nullptr )
  {
    v6 = L;
    v7 = index2adr(L, idx: narg);
    if ( v7 == &luaO_nilobject_ || v7->tt <= 0 )
      v8 = def;
    else
      v8 = luaL_checklstring(L, narg, len: nullptr);
  }
  else
  {
    v8 = luaL_checklstring(L, narg, len: nullptr);
    v6 = L;
  }
  v9 = *lst;
  v10 = 0;
  if ( *lst == nullptr )
  {
LABEL_11:
    v11 = lua_pushfstring(L: v6, fmt: "invalid option '%s'", v8);
    luaL_argerror(L: v6, extramsg: v11, narg);
  }
  while ( strcmp(v9, v8) != 0 )
  {
    v9 = lst[++v10];
    if ( v9 == nullptr )
    {
      v6 = L;
      goto LABEL_11;
    }
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10002040
// Name: _luaL_newmetatable
// Source: json
//------------------------------------------------------------------------------
int __usercall luaL_newmetatable@<eax>(lua_State *L@<esi>, const char *tname)
{
  lua_TValue *p_l_registry; // edi
  lua_TValue *v3; // eax
  lua_TValue *v5; // edi
  lua_TValue *top; // [esp-4h] [ebp-1Ch]
  lua_TValue *v7; // [esp-4h] [ebp-1Ch]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  p_l_registry = &L->l_G->l_registry;
  key.value.b = (int)luaS_newlstr(L, str: tname, l: strlen(tname));
  top = L->top;
  key.tt = 4;
  luaV_gettable(L, t: p_l_registry, &key, val: top);
  v3 = L->top++;
  if ( v3 == &luaO_nilobject_ || v3->tt != 0 )
    return 0;
  L->top = v3;
  lua_createtable(L, narray: 0);
  *L->top = L->top[-1];
  ++L->top;
  v5 = &L->l_G->l_registry;
  key.value.b = (int)luaS_newlstr(L, str: tname, l: strlen(tname));
  v7 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v5, &key, val: v7);
  --L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002130
// Name: _luaL_checkudata
// Source: json
//------------------------------------------------------------------------------
void *__usercall luaL_checkudata@<eax>(lua_State *L@<eax>, int ud, const char *tname)
{
  int v3; // edi
  lua_TValue *v5; // eax
  int b; // eax
  lua_TValue *v7; // eax
  Table *v8; // ecx
  lua_TValue *top; // eax
  global_State *l_G; // edi
  TString *v11; // eax
  lua_TValue *v13; // eax
  int tt; // eax
  const char *v15; // eax
  const char *v16; // eax
  lua_TValue *v17; // [esp-4h] [ebp-24h]
  void *p; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  v3 = ud;
  v5 = index2adr(L, idx: ud);
  if ( v5->tt == 2 )
  {
    b = v5->value.b;
  }
  else
  {
    if ( v5->tt != 7 )
    {
LABEL_15:
      v13 = index2adr(L, idx: v3);
      if ( v13 == &luaO_nilobject_ || (tt = v13->tt) == -1 )
        v15 = "no value";
      else
        v15 = luaT_typenames[tt];
      v16 = lua_pushfstring(L, fmt: "%s expected, got %s", tname, v15);
      luaL_argerror(L, extramsg: v16, narg: v3);
    }
    b = v5->value.b + 24;
  }
  p = (void *)b;
  if ( b == 0 )
    goto LABEL_15;
  v7 = index2adr(L, idx: ud);
  if ( v7->tt == 5 )
    v8 = *(Table **)(v7->value.b + 8);
  else
    v8 = v7->tt == 7 ? *(Table **)(v7->value.b + 8) : L->l_G->mt[v7->tt];
  if ( v8 == nullptr )
    goto LABEL_15;
  top = L->top;
  top->value.b = (int)v8;
  top->tt = 5;
  l_G = L->l_G;
  ++L->top;
  v11 = luaS_newlstr(L, str: tname, l: strlen(tname));
  v17 = L->top;
  key.value.b = (int)v11;
  key.tt = 4;
  luaV_gettable(L, t: &l_G->l_registry, &key, val: v17);
  ++L->top;
  if ( !lua_rawequal(L, index1: -1, index2: -2) )
  {
    v3 = ud;
    goto LABEL_15;
  }
  L->top -= 2;
  return p;
}

//------------------------------------------------------------------------------
// Address: 0x10002270
// Name: _luaL_checklstring
// Source: json
//------------------------------------------------------------------------------
const char *__usercall luaL_checklstring@<eax>(lua_State *L@<ecx>, unsigned int *len@<eax>, int narg)
{
  const char *result; // eax
  lua_TValue *v5; // eax
  int tt; // eax
  const char *v7; // eax
  const char *v8; // eax

  result = lua_tolstring(L, idx: narg, len);
  if ( result == nullptr )
  {
    v5 = index2adr(L, idx: narg);
    if ( v5 == &luaO_nilobject_ || (tt = v5->tt) == -1 )
      v7 = "no value";
    else
      v7 = luaT_typenames[tt];
    v8 = lua_pushfstring(L, fmt: "%s expected, got %s", "string", v7);
    luaL_argerror(L, extramsg: v8, narg);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100022E0
// Name: _luaL_checknumber
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_checknumber(lua_State *L, int narg)
{
  lua_TValue *p_result; // eax
  int tt; // ecx
  lua_TValue *v4; // eax
  int v5; // ecx
  lua_TValue *v6; // eax
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  double d; // [esp+10h] [ebp-18h] BYREF
  double result; // [esp+18h] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-8h]

  p_result = index2adr(L, idx: narg);
  tt = p_result->tt;
  if ( tt == 3 )
  {
LABEL_5:
    d = p_result->value.n;
    if ( d != 0.0 )
      return;
    goto LABEL_6;
  }
  if ( tt == 4 && luaO_str2d(s: (const char *)(p_result->value.b + 24), result: &d) != 0 )
  {
    result = d;
    v12 = 3;
    p_result = (lua_TValue *)&result;
    goto LABEL_5;
  }
  d = 0.0;
LABEL_6:
  v4 = index2adr(L, idx: narg);
  v5 = v4->tt;
  if ( v5 != 3 && (v5 != 4 || luaO_str2d(s: (const char *)(v4->value.b + 24), &result) == 0) )
  {
    v6 = index2adr(L, idx: narg);
    if ( v6 == &luaO_nilobject_ || (v7 = v6->tt) == -1 )
      v8 = "no value";
    else
      v8 = luaT_typenames[v7];
    v9 = lua_pushfstring(L, fmt: "%s expected, got %s", "number", v8);
    luaL_argerror(L, extramsg: v9, narg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023E0
// Name: _luaL_checkinteger
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_checkinteger(lua_State *L, int narg)
{
  lua_TValue *p_n; // eax
  int tt; // ecx
  int result; // eax
  lua_TValue *v5; // eax
  int v6; // ecx
  lua_TValue *v7; // eax
  int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  double d; // [esp+10h] [ebp-18h] BYREF
  double n; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+20h] [ebp-8h]

  p_n = index2adr(L, idx: narg);
  tt = p_n->tt;
  if ( tt == 3 )
  {
LABEL_5:
    n = p_n->value.n;
    result = (int)n;
    LODWORD(d) = (int)n;
    if ( (int)n != 0 )
      return result;
    goto LABEL_6;
  }
  if ( tt == 4 && luaO_str2d(s: (const char *)(p_n->value.b + 24), result: &d) != 0 )
  {
    n = d;
    v13 = 3;
    p_n = (lua_TValue *)&n;
    goto LABEL_5;
  }
  LODWORD(d) = 0;
LABEL_6:
  v5 = index2adr(L, idx: narg);
  v6 = v5->tt;
  if ( v6 != 3 && (v6 != 4 || luaO_str2d(s: (const char *)(v5->value.b + 24), result: &n) == 0) )
  {
    v7 = index2adr(L, idx: narg);
    if ( v7 == &luaO_nilobject_ || (v8 = v7->tt) == -1 )
      v9 = "no value";
    else
      v9 = luaT_typenames[v8];
    v10 = lua_pushfstring(L, fmt: "%s expected, got %s", "number", v9);
    luaL_argerror(L, extramsg: v10, narg);
  }
  return LODWORD(d);
}

//------------------------------------------------------------------------------
// Address: 0x100024F0
// Name: _luaL_getmetafield
// Source: json
//------------------------------------------------------------------------------
int __usercall luaL_getmetafield@<eax>(lua_State *L@<esi>, const char *event)
{
  unsigned int v2; // ebx
  lua_TValue *top; // edi
  lua_TValue *v4; // ecx
  lua_TValue *v6; // eax
  int *v7; // ecx

  if ( event != nullptr )
  {
    v2 = strlen(event);
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    top->value.b = (int)luaS_newlstr(L, str: event, l: v2);
    top->tt = 4;
  }
  else
  {
    L->top->tt = 0;
  }
  ++L->top;
  L->top[-1] = *luaH_get(t: (Table *)L->top[-2].value.gc, key: (const lua_TValue *)L->top - 1);
  v4 = L->top;
  if ( &v4[-1] == &luaO_nilobject_ || v4[-1].tt != 0 )
  {
    v6 = v4 - 1;
    if ( (unsigned int)v4 >= 0x10 )
    {
      v7 = (int *)&v4[-2];
      do
      {
        *v7 = v6->value.b;
        v7[1] = *(&v6->value.b + 1);
        v7[2] = v7[6];
        ++v6;
        v7 += 4;
      }
      while ( v6 < L->top );
    }
    --L->top;
    return 1;
  }
  else
  {
    L->top = v4 - 2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: _luaL_callmeta
// Source: json
//------------------------------------------------------------------------------
int __usercall luaL_callmeta@<eax>(lua_State *L@<eax>)
{
  lua_TValue *v2; // eax
  Table *v3; // ecx
  lua_TValue *top; // eax

  v2 = index2adr(L, idx: 1);
  if ( v2->tt == 5 )
  {
    v3 = *(Table **)(v2->value.b + 8);
  }
  else if ( v2->tt == 7 )
  {
    v3 = *(Table **)(v2->value.b + 8);
  }
  else
  {
    v3 = L->l_G->mt[v2->tt];
  }
  if ( v3 == nullptr )
    return 0;
  top = L->top;
  top->value.b = (int)v3;
  top->tt = 5;
  ++L->top;
  if ( luaL_getmetafield(L, event: "__tostring") == 0 )
    return 0;
  *L->top++ = *index2adr(L, idx: 1);
  luaD_call(L, func: L->top - 2, nResults: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002670
// Name: _luaL_openlib
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_openlib(lua_State *L@<eax>, const char *libname, const luaL_Reg *l)
{
  const luaL_Reg *v3; // ebx
  int v5; // ecx
  const luaL_Reg *v6; // eax
  const lua_TValue *v7; // edi
  TString *v8; // eax
  lua_TValue *v9; // eax
  lua_TValue *v10; // eax
  lua_TValue *v11; // ecx
  lua_TValue *v12; // eax
  int *v13; // ecx
  const lua_TValue *v14; // edi
  lua_TValue *top; // [esp-4h] [ebp-24h]
  lua_TValue *v16; // [esp-4h] [ebp-24h]
  int szhint; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  v3 = l;
  if ( libname != nullptr )
  {
    v5 = 0;
    v6 = l;
    szhint = 0;
    if ( l->name != nullptr )
    {
      do
      {
        ++v6;
        ++v5;
      }
      while ( v6->name != nullptr );
      szhint = v5;
    }
    luaL_findtable(L, idx: -10000, fname: "_LOADED", szhint: 1);
    v7 = L->top - 1;
    v8 = luaS_newlstr(L, str: libname, l: strlen(libname));
    top = L->top;
    key.value.b = (int)v8;
    key.tt = 4;
    luaV_gettable(L, t: v7, &key, val: top);
    v9 = L->top++;
    if ( v9 == &luaO_nilobject_ || v9->tt != 5 )
    {
      L->top = v9;
      if ( luaL_findtable(L, idx: -10002, fname: libname, szhint) != nullptr )
        luaL_error(L, fmt: "name conflict for module '%s'", libname);
      v10 = L->top;
      v10->value.b = v10[-1].value.b;
      *(&v10->value.b + 1) = *(&v10[-1].value.b + 1);
      v10->tt = v10[-1].tt;
      ++L->top;
      lua_setfield(L, idx: -3, k: libname);
    }
    v11 = L->top;
    v12 = v11 - 1;
    if ( (unsigned int)v11 >= 0x10 )
    {
      v13 = (int *)&v11[-2];
      do
      {
        *v13 = v12->value.b;
        v13[1] = *(&v12->value.b + 1);
        v13[2] = v13[6];
        ++v12;
        v13 += 4;
      }
      while ( v12 < L->top );
    }
    --L->top;
    lua_insert(L, idx: -1);
  }
  if ( l->name != nullptr )
  {
    do
    {
      lua_pushcclosure(L, fn: v3->func, n: 0);
      v14 = L->top - 2;
      key.value.b = (int)luaS_newlstr(L, str: v3->name, l: strlen(v3->name));
      v16 = L->top - 1;
      key.tt = 4;
      luaV_settable(L, t: v14, &key, val: v16);
      --L->top;
      ++v3;
    }
    while ( v3->name != nullptr );
  }
  L->top = L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10002820
// Name: _luaL_gsub
// Source: json
//------------------------------------------------------------------------------
const char *__usercall luaL_gsub@<eax>(char *s@<eax>, lua_State *L, char *p, const char *r)
{
  int v5; // eax
  int v6; // edi
  int v7; // eax
  unsigned int v8; // edi
  lua_State *v9; // esi
  int *top; // ebx
  lua_TValue *v11; // esi
  const char *result; // eax
  luaL_Buffer b; // [esp+Ch] [ebp-218h] BYREF
  unsigned int l; // [esp+220h] [ebp-4h]

  l = strlen(p);
  b.L = L;
  b.p = b.buffer;
  b.lvl = 0;
  strstr(str1: (unsigned __int8 *)s, str2: (unsigned __int8 *)p);
  v6 = v5;
  if ( v5 != 0 )
  {
    do
    {
      luaL_addlstring(B: &b, s, l: v6 - (_DWORD)s);
      luaL_addlstring(B: &b, s: r, l: strlen(r));
      s = (char *)(v6 + l);
      strstr(str1: (unsigned __int8 *)(v6 + l), str2: (unsigned __int8 *)p);
      v6 = v7;
    }
    while ( v7 != 0 );
  }
  luaL_addlstring(B: &b, s, l: strlen(s));
  v8 = b.p - b.buffer;
  if ( b.p != b.buffer )
  {
    v9 = b.L;
    if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
      luaC_step(L: b.L);
    top = (int *)v9->top;
    *top = (int)luaS_newlstr(L: v9, str: b.buffer, l: v8);
    top[2] = 4;
    ++v9->top;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: b.L, n: b.lvl);
  v11 = L->top - 1;
  b.lvl = 1;
  if ( v11->tt != 4 )
  {
    result = (const char *)luaV_tostring(L, obj: v11);
    if ( result == nullptr )
      return result;
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v11 = L->top - 1;
  }
  return (const char *)(v11->value.b + 24);
}

//------------------------------------------------------------------------------
// Address: 0x100029A0
// Name: _luaL_findtable
// Source: json
//------------------------------------------------------------------------------
char *__usercall luaL_findtable@<eax>(lua_State *L@<esi>, int idx@<eax>, char *fname, int szhint)
{
  const char *v4; // eax
  const char *v5; // ebx
  lua_TValue *top; // edi
  unsigned int v7; // ebx
  lua_TValue *v8; // eax
  int v9; // eax
  lua_TValue *v10; // edi
  lua_TValue *v11; // ecx
  lua_TValue *v12; // eax
  int *v13; // ecx
  const char *e; // [esp+Ch] [ebp-4h]

  *L->top++ = *index2adr(L, idx);
  while ( 1 )
  {
    strchr(string: (unsigned __int8 *)fname, chr: 0x2Eu);
    v5 = v4;
    e = v4;
    if ( v4 == nullptr )
    {
      e = &fname[strlen(fname)];
      v5 = e;
    }
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    v7 = v5 - fname;
    top->value.b = (int)luaS_newlstr(L, str: fname, l: v7);
    top->tt = 4;
    ++L->top;
    L->top[-1] = *luaH_get(t: (Table *)L->top[-2].value.gc, key: (const lua_TValue *)L->top - 1);
    v8 = L->top - 1;
    if ( v8 == &luaO_nilobject_ )
      break;
    if ( v8->tt != 0 )
    {
      if ( v8 == &luaO_nilobject_ || v8->tt != 5 )
        break;
    }
    else
    {
      L->top = v8;
      v9 = 1;
      if ( *e != 46 )
        v9 = szhint;
      lua_createtable(L, narray: v9);
      if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
        luaC_step(L);
      v10 = L->top;
      v10->value.b = (int)luaS_newlstr(L, str: fname, l: v7);
      v10->tt = 4;
      ++L->top;
      *L->top = L->top[-2];
      ++L->top;
      luaV_settable(L, t: (const lua_TValue *)L->top - 4, key: L->top - 2, val: L->top - 1);
      L->top -= 2;
    }
    v11 = L->top;
    v12 = v11 - 1;
    if ( (unsigned int)v11 >= 0x10 )
    {
      v13 = (int *)&v11[-2];
      do
      {
        *v13 = v12->value.b;
        v13[1] = *(&v12->value.b + 1);
        v13[2] = v13[6];
        ++v12;
        v13 += 4;
      }
      while ( v12 < L->top );
    }
    --L->top;
    fname = (char *)(e + 1);
    if ( *e != 46 )
      return nullptr;
  }
  L->top -= 2;
  return fname;
}

//------------------------------------------------------------------------------
// Address: 0x10002B50
// Name: emptybuffer
// Source: json
//------------------------------------------------------------------------------
int __usercall emptybuffer@<eax>(luaL_Buffer *B@<edi>)
{
  lua_State *v2; // esi
  int *top; // ebx
  int l; // [esp+Ch] [ebp-4h]

  l = B->p - (char *)B - 12;
  if ( B->p - (char *)B == 12 )
    return 0;
  v2 = B->L;
  if ( v2->l_G->totalbytes >= v2->l_G->GCthreshold )
    luaC_step(L: B->L);
  top = (int *)v2->top;
  *top = (int)luaS_newlstr(L: v2, str: B->buffer, l);
  top[2] = 4;
  ++v2->top;
  B->p = B->buffer;
  ++B->lvl;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002BC0
// Name: adjuststack
// Source: json
//------------------------------------------------------------------------------
void __cdecl adjuststack(luaL_Buffer *B)
{
  int v1; // edi
  lua_State *L; // ebx
  lua_TValue *top; // esi
  int tt; // eax
  lua_TValue *v5; // esi
  lua_TValue *v6; // esi
  unsigned int v7; // eax
  int idx; // [esp+Ch] [ebp-8h]
  unsigned int toplen; // [esp+10h] [ebp-4h]

  v1 = 1;
  if ( B->lvl > 1 )
  {
    L = B->L;
    top = L->top;
    tt = top[-1].tt;
    v5 = top - 1;
    switch ( tt )
    {
      case 3:
        if ( luaV_tostring(L, obj: v5) != 0 )
          toplen = *(_DWORD *)(v5->value.b + 16);
        else
          toplen = 0;
        break;
      case 4:
        toplen = *(_DWORD *)(v5->value.b + 16);
        break;
      case 5:
        toplen = luaH_getn(t: (Table *)v5->value.gc);
        break;
      case 7:
        toplen = *(_DWORD *)(v5->value.b + 16);
        break;
      default:
        toplen = 0;
        break;
    }
    idx = -2;
    do
    {
      v6 = index2adr(L, idx);
      switch ( v6->tt )
      {
        case 3:
          if ( luaV_tostring(L, obj: v6) == 0 )
            goto LABEL_17;
          v7 = *(_DWORD *)(v6->value.b + 16);
          break;
        case 4:
          v7 = *(_DWORD *)(v6->value.b + 16);
          break;
        case 5:
          v7 = luaH_getn(t: (Table *)v6->value.gc);
          break;
        case 7:
          v7 = *(_DWORD *)(v6->value.b + 16);
          break;
        default:
LABEL_17:
          v7 = 0;
          break;
      }
      if ( B->lvl - v1 + 1 < 10 && toplen <= v7 )
        break;
      toplen += v7;
      --idx;
      ++v1;
    }
    while ( v1 < B->lvl );
    lua_concat(L, n: v1);
    B->lvl += 1 - v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D00
// Name: _luaL_prepbuffer
// Source: json
//------------------------------------------------------------------------------
char *__usercall luaL_prepbuffer@<eax>(luaL_Buffer *B@<esi>)
{
  lua_State *v1; // edi
  int *top; // ebx
  int l; // [esp+Ch] [ebp-4h]

  l = B->p - (char *)B - 12;
  if ( B->p - (char *)B != 12 )
  {
    v1 = B->L;
    if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
      luaC_step(L: B->L);
    top = (int *)v1->top;
    *top = (int)luaS_newlstr(L: v1, str: B->buffer, l);
    top[2] = 4;
    ++v1->top;
    ++B->lvl;
    B->p = B->buffer;
    adjuststack(B);
  }
  return B->buffer;
}

//------------------------------------------------------------------------------
// Address: 0x10002D70
// Name: _luaL_addlstring
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_addlstring(luaL_Buffer *B@<esi>, const char *s, unsigned int l)
{
  char *p; // eax
  lua_State *v4; // edi
  int *top; // ebx
  int v6; // [esp+Ch] [ebp-4h]

  for ( ; l != 0; ++s )
  {
    p = B->p;
    --l;
    if ( B->p >= (char *)&B[1] )
    {
      v6 = p - (char *)B - 12;
      if ( p - (char *)B != 12 )
      {
        v4 = B->L;
        if ( v4->l_G->totalbytes >= v4->l_G->GCthreshold )
          luaC_step(L: B->L);
        top = (int *)v4->top;
        *top = (int)luaS_newlstr(L: v4, str: B->buffer, l: v6);
        top[2] = 4;
        ++v4->top;
        ++B->lvl;
        B->p = B->buffer;
        adjuststack(B);
      }
    }
    *B->p++ = *s;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E00
// Name: _luaL_pushresult
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_pushresult(luaL_Buffer *B@<edi>)
{
  lua_State *v1; // esi
  int *top; // ebx
  int l; // [esp+Ch] [ebp-4h]

  l = B->p - (char *)B - 12;
  if ( B->p - (char *)B != 12 )
  {
    v1 = B->L;
    if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
      luaC_step(L: B->L);
    top = (int *)v1->top;
    *top = (int)luaS_newlstr(L: v1, str: B->buffer, l);
    top[2] = 4;
    ++v1->top;
    ++B->lvl;
    B->p = B->buffer;
  }
  lua_concat(L: B->L, n: B->lvl);
  B->lvl = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002E70
// Name: _luaL_addvalue
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_addvalue(luaL_Buffer *B@<eax>)
{
  lua_State *L; // ebx
  lua_TValue *v3; // esi
  unsigned int v4; // esi
  unsigned __int8 *v5; // ecx
  int v6; // eax

  L = B->L;
  v3 = L->top - 1;
  if ( v3->tt != 4 )
  {
    if ( luaV_tostring(L: B->L, obj: v3) == 0 )
    {
      v4 = 0;
      v5 = nullptr;
      goto LABEL_8;
    }
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v3 = L->top - 1;
  }
  v6 = v3->value.b;
  v4 = *(_DWORD *)(v3->value.b + 16);
  v5 = (unsigned __int8 *)(v6 + 24);
LABEL_8:
  if ( v4 > (char *)B - B->p + 524 )
  {
    if ( emptybuffer(B) != 0 )
      lua_insert(L, idx: -2);
    ++B->lvl;
    adjuststack(B);
  }
  else
  {
    memcpy(dst: (unsigned __int8 *)B->p, src: v5, count: v4);
    B->p += v4;
    --L->top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F10
// Name: _luaL_ref
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_ref(lua_State *L)
{
  lua_TValue *v1; // eax
  Table **v3; // eax
  lua_TValue *v4; // eax
  int tt; // ecx
  int v6; // esi
  Table **v7; // eax
  int v8; // edi
  long double v9; // [esp+10h] [ebp-1Ch] BYREF
  long double n; // [esp+18h] [ebp-14h]
  long double v11; // [esp+20h] [ebp-Ch] BYREF

  v1 = L->top - 1;
  if ( v1 != &luaO_nilobject_ && v1->tt == 0 )
  {
    L->top = v1;
    return -1;
  }
  v3 = (Table **)index2adr(L, idx: -10000);
  *L->top++ = *luaH_getnum(t: *v3, key: 0);
  v4 = index2adr(L, idx: -1);
  tt = v4->tt;
  if ( tt != 3 )
  {
    if ( tt != 4 || luaO_str2d(s: (const char *)(v4->value.b + 24), result: &v11) == 0 )
    {
      v6 = 0;
      HIDWORD(v11) = 0;
      goto LABEL_9;
    }
    v9 = v11;
    LODWORD(n) = 3;
    v4 = (lua_TValue *)&v9;
  }
  n = v4->value.n;
  HIDWORD(v11) = (int)n;
  v6 = (int)n;
LABEL_9:
  --L->top;
  if ( v6 != 0 )
  {
    v7 = (Table **)index2adr(L, idx: -10000);
    *L->top++ = *luaH_getnum(t: *v7, key: v6);
    lua_rawseti(idx: -10000, n: 0, (lua_TValue *)L);
    v8 = HIDWORD(v11);
  }
  else
  {
    v8 = lua_objlen(L, idx: -10000) + 1;
  }
  lua_rawseti(idx: -10000, n: v8, (lua_TValue *)L);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10003040
// Name: _luaL_unref
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_unref(int ref@<eax>, lua_State *L)
{
  Table **v3; // eax
  lua_TValue *top; // eax

  if ( ref >= 0 )
  {
    v3 = (Table **)index2adr(L, idx: -10000);
    *L->top++ = *luaH_getnum(t: *v3, key: 0);
    lua_rawseti(idx: -10000, n: ref, (lua_TValue *)L);
    top = L->top;
    top->value.n = (double)ref;
    top->tt = 3;
    ++L->top;
    lua_rawseti(idx: -10000, n: 0, (lua_TValue *)L);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030C0
// Name: getF
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl getF(lua_State *L, _iobuf **ud, unsigned int *size)
{
  unsigned int v4; // eax

  if ( *ud != nullptr )
  {
    *ud = nullptr;
    *size = 1;
    return "\n";
  }
  else if ( feof(stream: ud[1]) != 0 )
  {
    return nullptr;
  }
  else
  {
    v4 = fread(buffer: ud + 2, elementSize: 1u, count: 0x200u, stream: ud[1]);
    *size = v4;
    return v4 != 0 ? (const char *)(ud + 2) : nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003130
// Name: errfile
// Source: json
//------------------------------------------------------------------------------
int __usercall errfile@<eax>(lua_State *L@<edi>, const char *what, int fnameindex)
{
  int *v3; // eax
  lua_TValue *v4; // eax
  int v5; // eax
  lua_TValue *v6; // eax
  int *v7; // ecx
  char *serr; // [esp+Ch] [ebp-4h]

  v3 = _errno();
  serr = strerror(errnum: *v3);
  v4 = index2adr(L, idx: fnameindex);
  if ( v4->tt != 4 )
  {
    v5 = luaV_tostring(L, obj: v4);
    if ( v5 == 0 )
      goto LABEL_7;
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v4 = index2adr(L, idx: fnameindex);
  }
  v5 = v4->value.b + 24;
LABEL_7:
  lua_pushfstring(L, fmt: "cannot %s %s: %s", what, (const char *)(v5 + 1), serr);
  v6 = index2adr(L, idx: fnameindex) + 1;
  if ( v6 < L->top )
  {
    v7 = (int *)&v6[-1];
    do
    {
      *v7 = v6->value.b;
      v7[1] = *(&v6->value.b + 1);
      v7[2] = v7[6];
      ++v6;
      v7 += 4;
    }
    while ( v6 < L->top );
  }
  --L->top;
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x100031F0
// Name: _luaL_loadfile
// Source: json
//------------------------------------------------------------------------------
int __usercall luaL_loadfile@<eax>(lua_State *L@<eax>, const char *filename)
{
  const char *v2; // esi
  int v4; // ebx
  int v5; // ebx
  lua_TValue *top; // esi
  _iobuf *v7; // eax
  int v8; // eax
  _iobuf *f; // eax
  lua_TValue *v11; // esi
  const char *v12; // esi
  int v13; // esi
  lua_TValue *v14; // eax
  int *v15; // ecx
  int status; // [esp+Ch] [ebp-20Ch]
  LoadF lf; // [esp+10h] [ebp-208h] BYREF

  v2 = filename;
  v4 = (char *)L->top - (char *)L->base;
  lf.extraline = 0;
  v5 = (v4 >> 4) + 1;
  if ( filename != nullptr )
  {
    lua_pushfstring(L, fmt: "@%s", filename);
    v7 = fopen(file: filename, mode: "r");
    lf.f = v7;
    if ( v7 == nullptr )
      return errfile(L, what: "open", fnameindex: v5);
  }
  else
  {
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    top->value.b = (int)luaS_newlstr(L, str: "=stdin", l: 6u);
    top->tt = 4;
    ++L->top;
    v7 = __iob_func();
    v2 = nullptr;
    lf.f = v7;
  }
  v8 = getc(stream: v7);
  if ( v8 == 35 )
  {
    lf.extraline = 1;
    while ( 1 )
    {
      v8 = getc(stream: lf.f);
      if ( v8 == -1 )
        break;
      if ( v8 == 10 )
      {
        v8 = getc(stream: lf.f);
        goto LABEL_10;
      }
    }
  }
  else
  {
LABEL_10:
    if ( v8 == 27 && v2 != nullptr )
    {
      f = freopen(filename: v2, mode: "rb", str: lf.f);
      lf.f = f;
      if ( f == nullptr )
        return errfile(L, what: "reopen", fnameindex: v5);
      while ( 1 )
      {
        v8 = getc(stream: f);
        if ( v8 == -1 || v8 == 27 )
          break;
        f = lf.f;
      }
      lf.extraline = 0;
    }
  }
  ungetc(ch: v8, stream: lf.f);
  v11 = L->top - 1;
  if ( v11->tt == 4 )
    goto LABEL_26;
  if ( luaV_tostring(L, obj: v11) != 0 )
  {
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v11 = L->top - 1;
LABEL_26:
    v12 = (const char *)(v11->value.b + 24);
    goto LABEL_27;
  }
  v12 = nullptr;
LABEL_27:
  status = lua_load(
             reader: (const char *(__cdecl *)(lua_State *, void *, unsigned int *))getF,
             chunkname: v12,
             L,
             data: &lf);
  v13 = ferror(stream: lf.f);
  if ( filename != nullptr )
    fclose(stream: lf.f);
  if ( v13 != 0 )
  {
    lua_settop(L, idx: v5);
    return errfile(L, what: "read", fnameindex: v5);
  }
  else
  {
    v14 = index2adr(L, idx: v5) + 1;
    if ( v14 < L->top )
    {
      v15 = (int *)&v14[-1];
      do
      {
        *v15 = v14->value.b;
        v15[1] = *(&v14->value.b + 1);
        v15[2] = v15[6];
        ++v14;
        v15 += 4;
      }
      while ( v14 < L->top );
    }
    --L->top;
    return status;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003430
// Name: getS
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl getS(lua_State *L, _DWORD *ud, unsigned int *size)
{
  unsigned int v3; // ecx

  v3 = ud[1];
  if ( v3 == 0 )
    return nullptr;
  *size = v3;
  ud[1] = 0;
  return (const char *)*ud;
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: l_alloc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl l_alloc(void *ud, void *ptr, unsigned int osize, unsigned int nsize)
{
  if ( nsize != 0 )
    return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: nsize);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ptr);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: panic
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn panic(lua_State *L)
{
  lua_TValue *v1; // esi
  const char *v2; // esi
  _iobuf *v3; // eax

  v1 = L->top - 1;
  if ( v1->tt == 4 )
  {
LABEL_7:
    v2 = (const char *)(v1->value.b + 24);
    goto LABEL_8;
  }
  if ( luaV_tostring(L, obj: v1) != 0 )
  {
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v1 = L->top - 1;
    goto LABEL_7;
  }
  v2 = nullptr;
LABEL_8:
  v3 = __iob_func();
  fprintf(str: v3 + 2, format: "PANIC: unprotected error in call to Lua API (%s)\n", v2);
}
