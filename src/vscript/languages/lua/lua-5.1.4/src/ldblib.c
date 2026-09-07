// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ldblib.c
// Functions: 21
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100074C0
// Name: db_getregistry
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getregistry(lua_State *L)
{
  *L->top++ = L->l_G->l_registry;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100074F0
// Name: db_getmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getmetatable(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // eax
  lua_TValue *top; // ecx
  Table *v4; // eax

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  v2 = L->base;
  top = L->top;
  if ( v2 >= top )
    v2 = &luaO_nilobject_;
  if ( v2->tt == 5 )
  {
    v4 = *(Table **)(v2->value.b + 8);
  }
  else if ( v2->tt == 7 )
  {
    v4 = *(Table **)(v2->value.b + 8);
  }
  else
  {
    v4 = L->l_G->mt[v2->tt];
  }
  if ( v4 != nullptr )
  {
    top->value.b = (int)v4;
    top->tt = 5;
  }
  else
  {
    top->tt = 0;
  }
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007580
// Name: db_setmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setmetatable(lua_State *L)
{
  lua_TValue *v1; // eax
  int tt; // eax
  int v3; // eax
  lua_TValue *top; // ecx
  BOOL v5; // edx

  v1 = L->base + 1;
  if ( v1 >= L->top || v1 == &luaO_nilobject_ || (tt = L->base[1].tt) != 0 && tt != 5 )
    luaL_argerror(L, extramsg: "nil or table expected", narg: 2);
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 2;
  v3 = lua_setmetatable(L, objindex: 1);
  top = L->top;
  v5 = v3 != 0;
  top->tt = 1;
  top->value.b = v5;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007610
// Name: db_getfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getfenv(lua_State *L)
{
  lua_TValue *base; // edx
  lua_TValue *top; // eax
  _DWORD *b; // edx
  int v5; // edx

  base = L->base;
  top = L->top;
  if ( base >= top )
    base = &luaO_nilobject_;
  if ( base->tt == 6 || base->tt == 7 )
  {
    v5 = *(_DWORD *)(base->value.b + 12);
    top->tt = 5;
    top->value.b = v5;
    ++L->top;
    return 1;
  }
  else
  {
    if ( base->tt == 8 )
    {
      b = (_DWORD *)base->value.b;
      top->value.b = b[18];
      *(&top->value.b + 1) = b[19];
      top->tt = b[20];
    }
    else
    {
      top->tt = 0;
    }
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007680
// Name: db_setfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setfenv(lua_State *L)
{
  lua_TValue *top; // ecx
  lua_TValue *v2; // eax
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax

  top = L->top;
  v2 = L->base + 1;
  if ( v2 >= top )
    goto LABEL_7;
  if ( v2 == &luaO_nilobject_ || L->base[1].tt != 5 )
  {
    if ( v2 < top && v2 != &luaO_nilobject_ )
    {
      tt = L->base[1].tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 2);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 2;
  if ( lua_setfenv(L, idx: 1) == 0 )
    luaL_error(L, fmt: "'setfenv' cannot change environment of given object");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007740
// Name: settabss
// Source: json
//------------------------------------------------------------------------------
void __usercall settabss(lua_State *L@<esi>, const char *i, const char *v)
{
  unsigned int v3; // ebx
  lua_TValue *top; // edi
  const lua_TValue *v5; // edi
  lua_TValue *v6; // [esp-10h] [ebp-28h]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  if ( v != nullptr )
  {
    v3 = strlen(v);
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    top->value.b = (int)luaS_newlstr(L, str: v, l: v3);
    top->tt = 4;
  }
  else
  {
    L->top->tt = 0;
  }
  v5 = ++L->top - 2;
  key.value.b = (int)luaS_newlstr(L, str: i, l: strlen(i));
  v6 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v5, &key, val: v6);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x100077F0
// Name: settabsi
// Source: json
//------------------------------------------------------------------------------
void __usercall settabsi(lua_State *L@<esi>, const char *i@<ecx>, int v)
{
  lua_TValue *top; // eax
  const lua_TValue *v4; // edi
  lua_TValue *v5; // [esp-18h] [ebp-28h]
  lua_TValue key; // [esp+0h] [ebp-10h] BYREF

  top = L->top;
  top->tt = 3;
  top->value.n = (double)v;
  v4 = ++L->top - 2;
  key.value.b = (int)luaS_newlstr(L, str: i, l: strlen(i));
  v5 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v4, &key, val: v5);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10007860
// Name: treatstackoption
// Source: json
//------------------------------------------------------------------------------
void __usercall treatstackoption(lua_State *L@<esi>, lua_State *L1@<eax>, const char *fname)
{
  lua_TValue *v3; // ecx
  lua_TValue *v4; // eax
  int *v5; // ecx
  lua_TValue *v6; // ecx
  lua_TValue *top; // eax
  const lua_TValue *v8; // edi
  lua_TValue *v9; // [esp-10h] [ebp-28h]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  if ( L == L1 )
  {
    *L->top = L->top[-2];
    v3 = ++L->top;
    v4 = v3 - 2;
    if ( (unsigned int)v3 >= 0x20 )
    {
      v5 = (int *)&v3[-3];
      do
      {
        *v5 = v4->value.b;
        v5[1] = *(&v4->value.b + 1);
        v5[2] = v5[6];
        ++v4;
        v5 += 4;
      }
      while ( v4 < L->top );
    }
    --L->top;
  }
  else
  {
    v6 = --L1->top;
    top = L->top;
    L->top = top + 1;
    *top = *v6;
  }
  v8 = L->top - 2;
  key.value.b = (int)luaS_newlstr(L, str: fname, l: strlen(fname));
  v9 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v8, &key, val: v9);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10007920
// Name: db_getinfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getinfo(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int v3; // esi
  lua_TValue *v4; // eax
  int v5; // edi
  lua_TValue *v6; // eax
  int tt; // ecx
  int v8; // eax
  lua_TValue *v9; // eax
  int v10; // ecx
  int v11; // ecx
  lua_TValue *v13; // eax
  lua_TValue *v14; // esi
  lua_TValue *v15; // eax
  lua_TValue *v16; // ecx
  lua_State *v17; // edx
  lua_TValue *v18; // eax
  lua_TValue *v19; // ecx
  unsigned __int8 *v20; // esi
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  lua_Debug ar; // [esp+Ch] [ebp-88h] BYREF
  __int64 v28; // [esp+70h] [ebp-24h] BYREF
  double n; // [esp+78h] [ebp-1Ch] BYREF
  int narg; // [esp+80h] [ebp-14h]
  int level[2]; // [esp+84h] [ebp-10h] BYREF
  lua_State *L1; // [esp+8Ch] [ebp-8h]
  const char *options; // [esp+90h] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 8 )
  {
    v3 = 0;
    L1 = L;
  }
  else
  {
    v3 = 1;
    if ( base >= top )
      base = &luaO_nilobject_;
    if ( base->tt == 8 )
      L1 = (lua_State *)base->value.b;
    else
      L1 = nullptr;
  }
  narg = v3 + 2;
  v4 = index2adr(L, idx: v3 + 2);
  if ( v4 == &luaO_nilobject_ || v4->tt <= 0 )
    options = "flnSu";
  else
    options = luaL_checklstring(L, len: nullptr, narg: v3 + 2);
  v5 = v3 + 1;
  level[1] = v3 + 1;
  v6 = index2adr(L, idx: v3 + 1);
  tt = v6->tt;
  if ( tt != 3 )
  {
    if ( tt != 4 || (v8 = luaO_str2d(s: (const char *)(v6->value.b + 24), result: &n), v5 = level[1], v8 == 0) )
    {
      v13 = index2adr(L, idx: v5);
      if ( v13 == &luaO_nilobject_ || v13->tt != 6 )
        luaL_argerror(L, extramsg: "function or level expected", narg: v5);
      lua_pushfstring(L, fmt: ">%s", options);
      v14 = L->top - 1;
      if ( v14->tt != 4 )
      {
        if ( luaV_tostring(L, obj: v14) == 0 )
        {
          options = nullptr;
          goto LABEL_34;
        }
        if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
          luaC_step(L);
        v14 = L->top - 1;
      }
      options = (const char *)(v14->value.b + 24);
LABEL_34:
      v15 = index2adr(L, idx: v5);
      v16 = L->top;
      v16->value.b = v15->value.b;
      *(&v16->value.b + 1) = *(&v15->value.b + 1);
      v17 = L1;
      v16->tt = v15->tt;
      ++L->top;
      if ( L != v17 )
      {
        v18 = L->top - 1;
        L->top = v18;
        v19 = v17->top;
        v17->top = v19 + 1;
        *v19 = *v18;
      }
      goto LABEL_36;
    }
  }
  v9 = index2adr(L, idx: v5);
  v10 = v9->tt;
  if ( v10 == 3 )
  {
LABEL_21:
    n = v9->value.n;
    level[1] = (int)n;
    v11 = (int)n;
    goto LABEL_22;
  }
  if ( v10 == 4 && luaO_str2d(s: (const char *)(v9->value.b + 24), result: (long double *)level) != 0 )
  {
    v28 = *(_QWORD *)level;
    LODWORD(n) = 3;
    v9 = (lua_TValue *)&v28;
    goto LABEL_21;
  }
  v11 = 0;
LABEL_22:
  if ( lua_getstack(L: L1, level: v11, &ar) == 0 )
  {
    L->top->tt = 0;
    ++L->top;
    return 1;
  }
LABEL_36:
  v20 = (unsigned __int8 *)options;
  if ( lua_getinfo(L: L1, what: options, &ar) == 0 )
    luaL_argerror(L, extramsg: "invalid option", narg);
  lua_createtable(L, narray: 2);
  strchr(string: v20, chr: 0x53u);
  if ( v21 != 0 )
  {
    settabss(L, i: "source", v: ar.source);
    settabss(L, i: "short_src", v: ar.short_src);
    settabsi(L, i: "linedefined", v: ar.linedefined);
    settabsi(L, i: "lastlinedefined", v: ar.lastlinedefined);
    settabss(L, i: "what", v: ar.what);
    v20 = (unsigned __int8 *)options;
  }
  strchr(string: v20, chr: 0x6Cu);
  if ( v22 != 0 )
  {
    settabsi(L, i: "currentline", v: ar.currentline);
    v20 = (unsigned __int8 *)options;
  }
  strchr(string: v20, chr: 0x75u);
  if ( v23 != 0 )
  {
    settabsi(L, i: "nups", v: ar.nups);
    v20 = (unsigned __int8 *)options;
  }
  strchr(string: v20, chr: 0x6Eu);
  if ( v24 != 0 )
  {
    settabss(L, i: "name", v: ar.name);
    settabss(L, i: "namewhat", v: ar.namewhat);
    v20 = (unsigned __int8 *)options;
  }
  strchr(string: v20, chr: 0x4Cu);
  if ( v25 != 0 )
  {
    treatstackoption(L, L1, fname: "activelines");
    v20 = (unsigned __int8 *)options;
  }
  strchr(string: v20, chr: 0x66u);
  if ( v26 != 0 )
    treatstackoption(L, L1, fname: "func");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007C90
// Name: db_getlocal
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getlocal(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  lua_State *b; // ebx
  int v4; // eax
  int v5; // eax
  CallInfo *v6; // edi
  const char *v7; // eax
  int *v8; // ecx
  int *v9; // edx
  lua_TValue *v10; // ecx
  lua_TValue *v11; // edx
  lua_Debug ar; // [esp+Ch] [ebp-6Ch] BYREF
  int narg; // [esp+70h] [ebp-8h]
  int arg; // [esp+74h] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 8 )
  {
    arg = 0;
    b = L;
  }
  else
  {
    arg = 1;
    if ( base >= top )
      base = &luaO_nilobject_;
    if ( base->tt == 8 )
      b = (lua_State *)base->value.b;
    else
      b = nullptr;
  }
  narg = arg + 1;
  v4 = luaL_checkinteger(L, narg: arg + 1);
  if ( lua_getstack(L: b, level: v4, &ar) == 0 )
    luaL_argerror(L, extramsg: "level out of range", narg);
  v5 = luaL_checkinteger(L, narg: arg + 2);
  v6 = &b->base_ci[ar.i_ci];
  narg = v5;
  v7 = findlocal(L: b, ci: v6, n: v5);
  if ( v7 != nullptr )
  {
    v8 = (int *)&v6->base[narg - 1];
    v9 = (int *)b->top;
    *v9 = *v8;
    v9[1] = v8[1];
    v9[2] = v8[2];
    ++b->top;
    if ( b != L )
    {
      v10 = b->top - 1;
      b->top = v10;
      v11 = L->top;
      L->top = v11 + 1;
      *v11 = *v10;
    }
    lua_pushstring(L, s: v7);
    *L->top = L->top[-2];
    ++L->top;
    return 2;
  }
  else
  {
    L->top->tt = 0;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007DE0
// Name: db_setlocal
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setlocal(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  lua_State *b; // ebx
  int v4; // eax
  int v5; // edi
  lua_TValue *v6; // eax
  int v7; // edi
  lua_TValue *v8; // eax
  lua_TValue *v9; // ecx
  int v10; // eax
  CallInfo *v11; // edi
  const char *v12; // eax
  lua_TValue *v13; // ecx
  int *v14; // edx
  lua_Debug ar; // [esp+Ch] [ebp-6Ch] BYREF
  int narg; // [esp+70h] [ebp-8h]
  int arg; // [esp+74h] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 8 )
  {
    arg = 0;
    b = L;
  }
  else
  {
    arg = 1;
    if ( base >= top )
      base = &luaO_nilobject_;
    if ( base->tt == 8 )
      b = (lua_State *)base->value.b;
    else
      b = nullptr;
  }
  narg = arg + 1;
  v4 = luaL_checkinteger(L, narg: arg + 1);
  if ( lua_getstack(L: b, level: v4, &ar) == 0 )
    luaL_argerror(L, extramsg: "level out of range", narg);
  v5 = arg + 3;
  v6 = index2adr(L, idx: arg + 3);
  if ( v6 == &luaO_nilobject_ || v6->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: v5);
  v7 = arg;
  lua_settop(L, idx: arg + 3);
  if ( L != b )
  {
    --L->top;
    v8 = b->top;
    v9 = L->top;
    b->top = v8 + 1;
    *v8 = *v9;
  }
  v10 = luaL_checkinteger(L, narg: v7 + 2);
  v11 = &b->base_ci[ar.i_ci];
  narg = v10;
  v12 = findlocal(L: b, ci: v11, n: v10);
  if ( v12 != nullptr )
  {
    v13 = b->top;
    v14 = (int *)&v11->base[narg - 1];
    *v14 = v13[-1].value.b;
    v14[1] = *(&v13[-1].value.b + 1);
    v14[2] = v13[-1].tt;
  }
  --b->top;
  lua_pushstring(L, s: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007F20
// Name: auxupvalue
// Source: json
//------------------------------------------------------------------------------
int __usercall auxupvalue@<eax>(lua_State *L@<eax>, int get)
{
  int v3; // eax
  lua_TValue *top; // ecx
  int v5; // ebx
  lua_TValue *base; // eax
  int tt; // eax
  const char *v8; // eax
  const char *v9; // eax
  lua_TValue *v10; // eax
  const char *v12; // eax

  v3 = luaL_checkinteger(L, narg: 2);
  top = L->top;
  v5 = v3;
  base = L->base;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 6 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v8 = luaT_typenames[tt];
LABEL_9:
        v9 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v8);
        luaL_argerror(L, extramsg: v9, narg: 1);
      }
    }
LABEL_7:
    v8 = "no value";
    goto LABEL_9;
  }
  v10 = L->base;
  if ( v10 >= L->top )
    v10 = &luaO_nilobject_;
  if ( v10->tt == 6 && *(_BYTE *)(v10->value.b + 6) != 0 )
    return 0;
  v12 = get != 0 ? lua_getupvalue(L, n: v5) : lua_setupvalue(L, n: v5);
  if ( v12 == nullptr )
    return 0;
  lua_pushstring(L, s: v12);
  lua_insert(L, idx: -1 - get);
  return get + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007FF0
// Name: db_getupvalue
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getupvalue(lua_State *L)
{
  return auxupvalue(L, get: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10008010
// Name: db_setupvalue
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setupvalue(lua_State *L)
{
  lua_TValue *v1; // eax

  v1 = L->base + 2;
  if ( v1 >= L->top || v1 == &luaO_nilobject_ || L->base[2].tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 3);
  return auxupvalue(L, get: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10008050
// Name: hookf
// Source: json
//------------------------------------------------------------------------------
void __cdecl hookf(lua_State *L, lua_Debug *ar)
{
  lua_TValue *top; // eax
  global_State *l_G; // eax
  lua_TValue *v4; // eax
  lua_TValue *v5; // eax
  int currentline; // ecx
  lua_TValue *v7; // eax

  top = L->top;
  top->value.b = (int)&KEY_HOOK;
  top->tt = 2;
  l_G = L->l_G;
  ++L->top;
  L->top[-1] = *luaH_get(t: (Table *)l_G->l_registry.value.gc, key: (const lua_TValue *)L->top - 1);
  v4 = L->top;
  v4->value.b = (int)L;
  v4->tt = 2;
  ++L->top;
  L->top[-1] = *luaH_get(t: (Table *)L->top[-2].value.gc, key: (const lua_TValue *)L->top - 1);
  v5 = L->top - 1;
  if ( v5 != &luaO_nilobject_ && v5->tt == 6 )
  {
    lua_pushstring(L, s: hooknames[ar->event]);
    currentline = ar->currentline;
    v7 = L->top;
    if ( currentline < 0 )
    {
      v7->tt = 0;
    }
    else
    {
      v7->value.n = (double)currentline;
      v7->tt = 3;
    }
    luaD_call(L, func: ++L->top - 3, nResults: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008130
// Name: gethooktable
// Source: json
//------------------------------------------------------------------------------
void __usercall gethooktable(lua_State *L@<eax>)
{
  lua_TValue *top; // eax
  lua_TValue *v3; // eax
  lua_TValue *v4; // eax
  lua_TValue *v5; // eax

  top = L->top;
  top->value.b = (int)&KEY_HOOK;
  top->tt = 2;
  ++L->top;
  L->top[-1] = *luaH_get(t: (Table *)L->l_G->l_registry.value.gc, key: (const lua_TValue *)L->top - 1);
  v3 = L->top - 1;
  if ( v3 == &luaO_nilobject_ || v3->tt != 5 )
  {
    L->top = v3;
    lua_createtable(L, narray: 1);
    v4 = L->top;
    v4->value.b = (int)&KEY_HOOK;
    v4->tt = 2;
    v5 = ++L->top;
    v5->value.b = v5[-2].value.b;
    *(&v5->value.b + 1) = *(&v5[-2].value.b + 1);
    v5->tt = v5[-2].tt;
    ++L->top;
    lua_rawset(L, idx: -10000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100081D0
// Name: db_sethook
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_sethook(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int v4; // edi
  int v5; // ebx
  lua_TValue *v6; // eax
  void (__cdecl *v7)(lua_State *, lua_Debug *); // edi
  int v8; // eax
  lua_TValue *v9; // eax
  lua_TValue *v10; // eax
  int tt; // eax
  const char *v12; // eax
  const char *v13; // eax
  int v14; // edi
  lua_TValue *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  lua_TValue *v20; // eax
  unsigned __int8 v21; // al
  char *smask; // [esp+Ch] [ebp-Ch]
  int count; // [esp+10h] [ebp-8h]
  lua_State *L1; // [esp+14h] [ebp-4h]
  int arg; // [esp+20h] [ebp+8h]
  int arga; // [esp+20h] [ebp+8h]

  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 8 )
  {
    v4 = 0;
    L1 = L;
  }
  else
  {
    v4 = 1;
    if ( base >= top )
      base = &luaO_nilobject_;
    if ( base->tt == 8 )
      L1 = (lua_State *)base->value.b;
    else
      L1 = nullptr;
  }
  v5 = v4 + 1;
  v6 = index2adr(L, idx: v4 + 1);
  if ( v6 == &luaO_nilobject_ || v6->tt <= 0 )
  {
    lua_settop(L, idx: v4 + 1);
    v7 = nullptr;
    v8 = 0;
    count = 0;
  }
  else
  {
    smask = (char *)luaL_checklstring(L, len: nullptr, narg: v4 + 2);
    v9 = index2adr(L, idx: v4 + 1);
    if ( v9 == &luaO_nilobject_ || v9->tt != 6 )
    {
      v10 = index2adr(L, idx: v5);
      if ( v10 == &luaO_nilobject_ || (tt = v10->tt) == -1 )
        v12 = "no value";
      else
        v12 = luaT_typenames[tt];
      v13 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v12);
      luaL_argerror(L, extramsg: v13, narg: v5);
    }
    v14 = v4 + 3;
    v15 = index2adr(L, idx: v14);
    if ( v15 == &luaO_nilobject_ || v15->tt <= 0 )
      count = 0;
    else
      count = luaL_checkinteger(L, narg: v14);
    v7 = hookf;
    strchr(string: (unsigned __int8 *)smask, chr: 0x63u);
    arg = v16 != 0;
    strchr(string: (unsigned __int8 *)smask, chr: 0x72u);
    if ( v17 != 0 )
      arg |= 2u;
    strchr(string: (unsigned __int8 *)smask, chr: 0x6Cu);
    v19 = v18 == 0;
    v8 = arg;
    if ( !v19 )
      v8 = arg | 4;
    if ( count > 0 )
      v8 |= 8u;
  }
  arga = v8;
  gethooktable(L);
  v20 = L->top;
  v20->value.b = (int)L1;
  v20->tt = 2;
  ++L->top;
  *L->top++ = *index2adr(L, idx: v5);
  lua_rawset(L, idx: -3);
  --L->top;
  v21 = arga;
  if ( v7 == nullptr || arga == 0 )
  {
    v21 = 0;
    v7 = nullptr;
  }
  L1->hook = v7;
  L1->hookmask = v21;
  L1->basehookcount = count;
  L1->hookcount = count;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100083D0
// Name: db_gethook
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_gethook(lua_State *L)
{
  lua_State *v1; // esi
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  lua_State *b; // edi
  void (__cdecl *hook)(lua_State *, lua_Debug *); // eax
  unsigned __int8 hookmask; // bl
  int *v7; // edi
  _DWORD *p_b; // eax
  unsigned int v9; // ecx
  lua_TValue *v10; // eax
  int *v11; // ecx
  int v12; // eax
  unsigned int v13; // kr00_4
  int *v14; // edi
  lua_TValue *v15; // eax
  char buff[8]; // [esp+Ch] [ebp-8h] BYREF

  v1 = L;
  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 8 )
  {
    b = L;
  }
  else
  {
    if ( base >= top )
      base = &luaO_nilobject_;
    if ( base->tt == 8 )
    {
      L = (lua_State *)base->value.b;
      b = (lua_State *)base->value.b;
    }
    else
    {
      b = nullptr;
      L = nullptr;
    }
  }
  hook = b->hook;
  hookmask = b->hookmask;
  if ( hook == nullptr || hook == hookf )
  {
    gethooktable(L: v1);
    p_b = &v1->top->value.b;
    *p_b = b;
    p_b[2] = 2;
    ++v1->top;
    v1->top[-1] = *luaH_get(t: (Table *)v1->top[-2].value.gc, key: (const lua_TValue *)v1->top - 1);
    v9 = (unsigned int)v1->top;
    v10 = (lua_TValue *)(v9 - 16);
    if ( v9 >= 0x10 )
    {
      v11 = (int *)(v9 - 32);
      do
      {
        *v11 = v10->value.b;
        v11[1] = *(&v10->value.b + 1);
        v11[2] = v11[6];
        ++v10;
        v11 += 4;
      }
      while ( v10 < v1->top );
    }
    --v1->top;
  }
  else
  {
    if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
      luaC_step(L: v1);
    v7 = (int *)v1->top;
    *v7 = (int)luaS_newlstr(L: v1, str: "external hook", l: 0xDu);
    v7[2] = 4;
    ++v1->top;
  }
  v12 = 0;
  if ( (hookmask & 1) != 0 )
  {
    buff[0] = 99;
    v12 = 1;
  }
  if ( (hookmask & 2) != 0 )
    buff[v12++] = 114;
  if ( (hookmask & 4) != 0 )
    buff[v12++] = 108;
  buff[v12] = 0;
  v13 = strlen(buff);
  if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
    luaC_step(L: v1);
  v14 = (int *)v1->top;
  *v14 = (int)luaS_newlstr(L: v1, str: buff, l: v13);
  v14[2] = 4;
  v15 = ++v1->top;
  v15->value.n = (double)L->basehookcount;
  v15->tt = 3;
  ++v1->top;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10008560
// Name: db_debug
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_debug(lua_State *L)
{
  _iobuf *v1; // eax
  _iobuf *v2; // eax
  int errfunc; // edx
  int v4; // eax
  global_State *l_G; // esi
  int v6; // ebx
  lua_TValue *v7; // esi
  const char *v8; // esi
  _iobuf *v9; // eax
  _iobuf *v10; // eax
  _iobuf *v11; // eax
  _iobuf *v12; // eax
  int v14; // [esp-4h] [ebp-14Ch]
  int v15; // [esp-4h] [ebp-14Ch]
  unsigned int v16; // [esp+Ch] [ebp-13Ch]
  _DWORD v17[2]; // [esp+10h] [ebp-138h] BYREF
  _DWORD v18[2]; // [esp+18h] [ebp-130h] BYREF
  _DWORD *u; // [esp+20h] [ebp-128h] BYREF
  void *v20; // [esp+24h] [ebp-124h]
  unsigned int v21; // [esp+2Ch] [ebp-11Ch]
  const char *v22; // [esp+30h] [ebp-118h]
  _DWORD v23[5]; // [esp+34h] [ebp-114h] BYREF
  char buffer[256]; // [esp+48h] [ebp-100h] BYREF

  v1 = __iob_func();
  fputs(string: "lua_debug> ", stream: v1 + 2);
  v2 = __iob_func();
  if ( fgets(string: buffer, count: 250, str: v2) != nullptr )
  {
    while ( 1 )
    {
      if ( strcmp(buffer, "cont\n") == 0 )
        return 0;
      v18[1] = strlen(buffer);
      v23[3] = v18;
      v14 = (char *)L->top - (char *)L->stack;
      v18[0] = buffer;
      v23[0] = 0;
      v23[1] = 0;
      v20 = nullptr;
      v21 = 0;
      u = v23;
      errfunc = L->errfunc;
      v23[4] = L;
      v23[2] = getS;
      v22 = "=(debug command)";
      v4 = luaD_pcall(L, func: f_parser, &u, old_top: v14, ef: errfunc);
      l_G = L->l_G;
      v6 = v4;
      v16 = v21;
      l_G->frealloc(a1: l_G->ud, a2: v20, a3: v21, a4: 0);
      l_G->totalbytes -= v16;
      if ( v6 != 0 )
        break;
      v17[0] = L->top - 1;
      v15 = v17[0] - (unsigned int)L->stack;
      v17[1] = 0;
      if ( luaD_pcall(L, func: f_call, u: v17, old_top: v15, ef: 0) != 0 )
        break;
LABEL_13:
      while ( L->top < L->base )
      {
        L->top->tt = 0;
        ++L->top;
      }
      L->top = L->base;
      v11 = __iob_func();
      fputs(string: "lua_debug> ", stream: v11 + 2);
      v12 = __iob_func();
      if ( fgets(string: buffer, count: 250, str: v12) == nullptr )
        return 0;
    }
    v7 = L->top - 1;
    if ( v7->tt != 4 )
    {
      if ( luaV_tostring(L, obj: v7) == 0 )
      {
        v8 = nullptr;
LABEL_12:
        v9 = __iob_func();
        fputs(string: v8, stream: v9 + 2);
        v10 = __iob_func();
        fputs(string: "\n", stream: v10 + 2);
        goto LABEL_13;
      }
      if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
        luaC_step(L);
      v7 = L->top - 1;
    }
    v8 = (const char *)(v7->value.b + 24);
    goto LABEL_12;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008770
// Name: db_errorfb
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_errorfb(lua_State *L)
{
  lua_State *v1; // ebx
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  lua_TValue *v4; // eax
  int tt; // ecx
  lua_TValue *v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // esi
  lua_TValue *v10; // eax
  int v11; // eax
  int *v12; // edi
  global_State *l_G; // eax
  int *v14; // edi
  int *v15; // edi
  int *v16; // edi
  char v17; // al
  int *v18; // esi
  int *v19; // esi
  int v20; // edi
  const char *v22; // [esp-8h] [ebp-98h]
  unsigned int v23; // [esp-4h] [ebp-94h]
  lua_Debug ar; // [esp+Ch] [ebp-84h] BYREF
  __int64 v25; // [esp+70h] [ebp-20h] BYREF
  double n; // [esp+78h] [ebp-18h] BYREF
  int firstpart; // [esp+80h] [ebp-10h]
  int level[2]; // [esp+84h] [ebp-Ch] BYREF
  int arg; // [esp+8Ch] [ebp-4h]

  v1 = L;
  base = L->base;
  top = L->top;
  firstpart = 1;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 8 )
  {
    arg = 0;
  }
  else
  {
    arg = 1;
    if ( base >= top )
      base = &luaO_nilobject_;
    if ( base->tt == 8 )
      L = (lua_State *)base->value.b;
    else
      L = nullptr;
  }
  v4 = index2adr(L: v1, idx: arg + 2);
  tt = v4->tt;
  if ( tt == 3 || tt == 4 && luaO_str2d(s: (const char *)(v4->value.b + 24), result: &n) != 0 )
  {
    v6 = index2adr(L: v1, idx: arg + 2);
    v7 = v6->tt;
    if ( v7 == 3 )
    {
LABEL_17:
      n = v6->value.n;
      level[1] = (int)n;
      v8 = (int)n;
      --v1->top;
      v9 = v8;
      goto LABEL_20;
    }
    if ( v7 == 4 && luaO_str2d(s: (const char *)(v6->value.b + 24), result: (long double *)level) != 0 )
    {
      v25 = *(_QWORD *)level;
      LODWORD(n) = 3;
      v6 = (lua_TValue *)&v25;
      goto LABEL_17;
    }
    v9 = 0;
    --v1->top;
  }
  else
  {
    level[1] = v1 == L;
    v9 = level[1];
  }
LABEL_20:
  if ( v1->top - v1->base == arg )
  {
    if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
      luaC_step(L: v1);
    v23 = 0;
    v22 = Ptr;
  }
  else
  {
    v10 = index2adr(L: v1, idx: arg + 1);
    if ( v10 == &luaO_nilobject_ )
      return 1;
    v11 = v10->tt;
    if ( v11 != 4 && v11 != 3 )
      return 1;
    if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
      luaC_step(L: v1);
    v23 = 1;
    v22 = "\n";
  }
  v12 = (int *)v1->top;
  *v12 = (int)luaS_newlstr(L: v1, str: v22, l: v23);
  v12[2] = 4;
  l_G = v1->l_G;
  ++v1->top;
  if ( l_G->totalbytes >= l_G->GCthreshold )
    luaC_step(L: v1);
  v14 = (int *)v1->top;
  *v14 = (int)luaS_newlstr(L: v1, str: "stack traceback:", l: 0x10u);
  v14[2] = 4;
  ++v1->top;
  while ( lua_getstack(L, level: v9, &ar) != 0 )
  {
    level[1] = ++v9;
    if ( v9 > 12 && firstpart != 0 )
    {
      if ( lua_getstack(L, level: v9 + 10, &ar) != 0 )
      {
        if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
          luaC_step(L: v1);
        v15 = (int *)v1->top;
        *v15 = (int)luaS_newlstr(L: v1, str: "\n\t...", l: 5u);
        v15[2] = 4;
        for ( ++v1->top; lua_getstack(L, level: v9 + 10, &ar) != 0; ++v9 )
          ;
        firstpart = 0;
      }
      else
      {
        --v9;
        firstpart = 0;
      }
    }
    else
    {
      if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
        luaC_step(L: v1);
      v16 = (int *)v1->top;
      *v16 = (int)luaS_newlstr(L: v1, str: "\n\t", l: 2u);
      v16[2] = 4;
      ++v1->top;
      lua_getinfo(L, what: "Snl", &ar);
      lua_pushfstring(L: v1, fmt: "%s:", ar.short_src);
      if ( ar.currentline > 0 )
        lua_pushfstring(L: v1, fmt: "%d:", ar.currentline);
      if ( *ar.namewhat != 0 )
      {
        lua_pushfstring(L: v1, fmt: " in function '%s'", ar.name);
      }
      else
      {
        v17 = *ar.what;
        if ( *ar.what == 109 )
        {
          lua_pushfstring(L: v1, fmt: " in main chunk");
        }
        else if ( v17 == 67 || v17 == 116 )
        {
          if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
            luaC_step(L: v1);
          v18 = (int *)v1->top;
          *v18 = (int)luaS_newlstr(L: v1, str: " ?", l: 2u);
          v18[2] = 4;
          ++v1->top;
        }
        else
        {
          lua_pushfstring(L: v1, fmt: " in function <%s:%d>", ar.short_src, ar.linedefined);
        }
      }
      v19 = (int *)v1->top;
      v20 = (((char *)v19 - (char *)v1->base) >> 4) - arg;
      if ( v20 < 2 )
      {
        if ( v20 == 0 )
        {
          *v19 = (int)luaS_newlstr(L: v1, str: Ptr, l: 0);
          v19[2] = 4;
          ++v1->top;
        }
      }
      else
      {
        if ( v1->l_G->totalbytes >= v1->l_G->GCthreshold )
          luaC_step(L: v1);
        luaV_concat(L: v1, total: v20, last: v1->top - v1->base - 1);
        v1->top = (lua_TValue *)((char *)v1->top + 16 - 16 * v20);
      }
      v9 = level[1];
    }
  }
  lua_concat(L: v1, n: v1->top - v1->base - arg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008B70
// Name: _luaopen_debug
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_debug(lua_State *L)
{
  luaL_openlib(L, libname: "debug", l: dblib);
  return 1;
}
