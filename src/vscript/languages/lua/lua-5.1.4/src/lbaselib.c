// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lbaselib.c
// Functions: 40
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10003510
// Name: luaB_print
// Source: json
//------------------------------------------------------------------------------
// Force-skipped: luaB_print

//------------------------------------------------------------------------------
// Address: 0x10003670
// Name: luaB_tonumber
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_tonumber(lua_State *L)
{
  lua_TValue *v1; // eax
  int v2; // esi
  lua_TValue *v3; // eax
  lua_TValue *v4; // ecx
  int tt; // eax
  lua_TValue *p_base; // eax
  int v7; // ecx
  long double n; // xmm0_8
  lua_TValue *top; // eax
  const char *v11; // edi
  unsigned int v12; // esi
  lua_TValue *v13; // eax
  char *s2; // [esp+10h] [ebp-18h] BYREF
  const char *s1; // [esp+14h] [ebp-14h]
  long double base; // [esp+18h] [ebp-10h] BYREF
  int v17; // [esp+20h] [ebp-8h]

  v1 = L->base + 1;
  if ( v1 >= L->top
    || v1 == &luaO_nilobject_
    || L->base[1].tt <= 0
    || (v2 = luaL_checkinteger(L, narg: 2), LODWORD(base) = v2, v2 == 10) )
  {
    v3 = L->base;
    if ( v3 >= L->top || v3 == &luaO_nilobject_ || v3->tt == -1 )
      luaL_argerror(L, extramsg: "value expected", narg: 1);
    v4 = L->base;
    if ( v4 >= L->top )
      v4 = &luaO_nilobject_;
    tt = v4->tt;
    if ( tt == 3 || tt == 4 && luaO_str2d(s: (const char *)(v4->value.b + 24), result: &base) != 0 )
    {
      p_base = L->base;
      if ( p_base >= L->top )
        p_base = &luaO_nilobject_;
      v7 = p_base->tt;
      if ( v7 != 3 )
      {
        if ( v7 != 4 || luaO_str2d(s: (const char *)(p_base->value.b + 24), result: &base) == 0 )
        {
          n = 0.0;
          goto LABEL_21;
        }
        v17 = 3;
        p_base = (lua_TValue *)&base;
      }
      n = p_base->value.n;
LABEL_21:
      top = L->top;
      top->value.n = n;
      top->tt = 3;
      ++L->top;
      return 1;
    }
  }
  else
  {
    v11 = luaL_checklstring(L, len: nullptr, narg: 1);
    s1 = v11;
    if ( v2 < 2 || v2 > 36 )
      luaL_argerror(L, extramsg: "base out of range", narg: 2);
    v12 = strtoul(nptr: v11, endptr: &s2, ibase: v2);
    if ( v11 != s2 )
    {
      for ( ; isspace(c: (unsigned __int8)*s2) != 0; ++s2 )
        ;
      if ( *s2 == 0 )
      {
        v13 = L->top;
        LODWORD(base) = v12;
        v13->value.n = (double)v12;
        v13->tt = 3;
        ++L->top;
        return 1;
      }
    }
  }
  L->top->tt = 0;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003840
// Name: luaB_error
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaB_error(lua_State *L)
{
  lua_TValue *v1; // eax
  int v2; // eax
  lua_TValue *v3; // edx
  lua_TValue *base; // edi
  int tt; // edi
  lua_TValue *v6; // ecx
  lua_TValue *top; // eax
  global_State *l_G; // eax

  v1 = L->base + 1;
  if ( v1 >= L->top || v1 == &luaO_nilobject_ || L->base[1].tt <= 0 )
    v2 = 1;
  else
    v2 = luaL_checkinteger(L, narg: 2);
  for ( ; L->top < L->base + 1; ++L->top )
    L->top->tt = 0;
  v3 = L->base + 1;
  base = L->base;
  L->top = v3;
  if ( (unsigned int)v3 >= 0x10 && base != &luaO_nilobject_ )
  {
    tt = base->tt;
    if ( (tt == 4 || tt == 3) && v2 > 0 )
    {
      luaL_where(L, level: v2);
      v6 = L->base;
      top = L->top;
      if ( v6 >= top )
        v6 = &luaO_nilobject_;
      top->value.b = v6->value.b;
      *(&top->value.b + 1) = *(&v6->value.b + 1);
      top->tt = v6->tt;
      l_G = L->l_G;
      ++L->top;
      if ( l_G->totalbytes >= l_G->GCthreshold )
        luaC_step(L);
      luaV_concat(L, total: 2, last: L->top - L->base - 1);
      --L->top;
    }
  }
  luaG_errormsg(L);
}

//------------------------------------------------------------------------------
// Address: 0x10003930
// Name: luaB_getmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_getmetatable(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // edx
  lua_TValue *top; // edi
  Table *v4; // eax
  lua_TValue *v5; // edi
  lua_TValue *v6; // ecx
  Table *v7; // eax

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
    v5 = ++L->top;
    v6 = L->base;
    if ( v6 >= v5 )
      v6 = &luaO_nilobject_;
    if ( v6->tt == 5 )
    {
      v7 = *(Table **)(v6->value.b + 8);
    }
    else if ( v6->tt == 7 )
    {
      v7 = *(Table **)(v6->value.b + 8);
    }
    else
    {
      v7 = L->l_G->mt[v6->tt];
    }
    if ( v7 != nullptr )
    {
      v5->value.b = (int)v7;
      v5->tt = 5;
      ++L->top;
      luaL_getmetafield(L, event: "__metatable");
    }
    return 1;
  }
  else
  {
    top->tt = 0;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003A20
// Name: luaB_setmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_setmetatable(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // edx
  int tt; // ebx
  int v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // ecx
  lua_TValue *v8; // edi
  Table *v9; // eax

  base = L->base;
  top = L->top;
  if ( &base[1] >= top || &base[1] == &luaO_nilobject_ )
    tt = -1;
  else
    tt = base[1].tt;
  if ( base >= top )
    goto LABEL_11;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      v4 = base->tt;
      if ( v4 != -1 )
      {
        v5 = luaT_typenames[v4];
LABEL_13:
        v6 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v5);
        luaL_argerror(L, extramsg: v6, narg: 1);
      }
    }
LABEL_11:
    v5 = "no value";
    goto LABEL_13;
  }
  if ( tt != 0 && tt != 5 )
    luaL_argerror(L, extramsg: "nil or table expected", narg: 2);
  v7 = L->base;
  v8 = L->top;
  if ( v7 >= v8 )
    v7 = &luaO_nilobject_;
  if ( v7->tt == 5 )
  {
    v9 = *(Table **)(v7->value.b + 8);
  }
  else if ( v7->tt == 7 )
  {
    v9 = *(Table **)(v7->value.b + 8);
  }
  else
  {
    v9 = L->l_G->mt[v7->tt];
  }
  if ( v9 != nullptr )
  {
    v8->value.b = (int)v9;
    v8->tt = 5;
    ++L->top;
    if ( luaL_getmetafield(L, event: "__metatable") != 0 )
      luaL_error(L, fmt: "cannot change a protected metatable");
  }
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 2;
  lua_setmetatable(L, objindex: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003B60
// Name: getfunc
// Source: json
//------------------------------------------------------------------------------
void __usercall getfunc(lua_State *L@<eax>, int opt)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int v5; // ebx
  lua_TValue *v6; // eax
  lua_Debug ar; // [esp+Ch] [ebp-68h] BYREF

  base = L->base;
  top = L->top;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 6 )
  {
    if ( opt != 0 && (base >= top || base == &luaO_nilobject_ || base->tt <= 0) )
    {
      v5 = 1;
    }
    else
    {
      v5 = luaL_checkinteger(L, narg: 1);
      if ( v5 < 0 )
        luaL_argerror(L, extramsg: "level must be non-negative", narg: 1);
    }
    if ( lua_getstack(L, level: v5, &ar) == 0 )
      luaL_argerror(L, extramsg: "invalid level", narg: 1);
    lua_getinfo(L, what: "f", &ar);
    v6 = L->top - 1;
    if ( v6 != &luaO_nilobject_ && v6->tt == 0 )
      luaL_error(L, fmt: "no function environment for tail call at level %d", v5);
  }
  else
  {
    if ( base >= top )
      base = &luaO_nilobject_;
    top->value.b = base->value.b;
    *(&top->value.b + 1) = *(&base->value.b + 1);
    top->tt = base->tt;
    ++L->top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003C40
// Name: luaB_getfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_getfenv(lua_State *L)
{
  lua_TValue *top; // eax

  getfunc(L, opt: 1);
  top = L->top;
  if ( top[-1].tt == 6 && *(_BYTE *)(top[-1].value.b + 6) != 0 )
  {
    *top = L->l_gt;
    ++L->top;
    return 1;
  }
  else
  {
    lua_getfenv(L, idx: -1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003CA0
// Name: luaB_setfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_setfenv(lua_State *L)
{
  lua_TValue *top; // ecx
  lua_TValue *v2; // eax
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  lua_TValue *v7; // ecx
  lua_TValue *base; // eax
  int v9; // ecx
  lua_TValue *v10; // eax
  int v11; // ecx
  lua_TValue *v12; // eax
  lua_TValue *v14; // eax
  long double v15; // [esp+10h] [ebp-10h] BYREF
  int v16; // [esp+18h] [ebp-8h]

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
  getfunc(L, opt: 0);
  v6 = L->top;
  v7 = L->base + 1;
  if ( v7 >= v6 )
    v7 = &luaO_nilobject_;
  v6->value.b = v7->value.b;
  *(&v6->value.b + 1) = *(&v7->value.b + 1);
  v6->tt = v7->tt;
  base = L->base;
  if ( base >= ++L->top )
    base = &luaO_nilobject_;
  v9 = base->tt;
  if ( v9 == 3 || v9 == 4 && luaO_str2d(s: (const char *)(base->value.b + 24), result: &v15) != 0 )
  {
    v10 = L->base;
    if ( v10 >= L->top )
      v10 = &luaO_nilobject_;
    v11 = v10->tt;
    if ( v11 != 3 )
    {
      if ( v11 != 4 || luaO_str2d(s: (const char *)(v10->value.b + 24), result: &v15) == 0 )
        goto LABEL_24;
      v16 = 3;
      v10 = (lua_TValue *)&v15;
    }
    if ( v10->value.n == 0.0 )
    {
LABEL_24:
      v12 = L->top;
      v12->value.b = (int)L;
      v12->tt = 8;
      ++L->top;
      lua_insert(L, idx: -2);
      lua_setfenv(L, idx: -2);
      return 0;
    }
  }
  v14 = L->top;
  if ( v14[-2].tt == 6 && *(_BYTE *)(v14[-2].value.b + 6) != 0 || lua_setfenv(L, idx: -2) == 0 )
    luaL_error(L, fmt: "'setfenv' cannot change environment of given object");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003E40
// Name: luaB_rawequal
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_rawequal(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // eax
  lua_TValue *v3; // eax
  lua_TValue *top; // edi
  lua_TValue *v5; // ecx
  lua_TValue *v6; // eax
  int tt; // edx
  BOOL v8; // eax
  BOOL v9; // ecx

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  v2 = L->base + 1;
  if ( v2 >= L->top || v2 == &luaO_nilobject_ || L->base[1].tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 2);
  v3 = L->base;
  top = L->top;
  v5 = &luaO_nilobject_;
  if ( v3 < top )
    v5 = L->base;
  v6 = v3 + 1;
  if ( v6 >= top )
    v6 = &luaO_nilobject_;
  if ( v5 == &luaO_nilobject_ || v6 == &luaO_nilobject_ || (tt = v5->tt) != v6->tt )
  {
LABEL_21:
    v8 = false;
  }
  else
  {
    switch ( tt )
    {
      case 0:
        v8 = true;
        break;
      case 3:
        if ( v5->value.n != v6->value.n )
          goto LABEL_21;
        v8 = true;
        break;
      default:
        v8 = v5->value.b == v6->value.b;
        break;
    }
  }
  v9 = v8;
  top->tt = 1;
  top->value.b = v9;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003F30
// Name: luaB_rawget
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_rawget(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  lua_TValue *v7; // ecx
  lua_TValue *v8; // eax

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base + 1;
  if ( v6 >= L->top || v6 == &luaO_nilobject_ || L->base[1].tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 2);
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  v7 = L->base;
  v8 = v7 + 2;
  L->top = v7 + 2;
  if ( v7 >= &v7[2] )
    v7 = &luaO_nilobject_;
  L->top[-1] = *luaH_get(t: (Table *)v7->value.gc, key: v8 - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004010
// Name: luaB_rawset
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_rawset(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  lua_TValue *v7; // eax

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base + 1;
  if ( v6 >= L->top || v6 == &luaO_nilobject_ || L->base[1].tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 2);
  v7 = L->base + 2;
  if ( v7 >= L->top || v7 == &luaO_nilobject_ || L->base[2].tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 3);
  for ( ; L->top < L->base + 3; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 3;
  lua_rawset(L, idx: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004110
// Name: luaB_gcinfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_gcinfo(lua_State *L)
{
  int v1; // eax
  lua_TValue *top; // ecx

  v1 = lua_gc(data: 0, g: (int)L->l_G, a3: 3, L, res: 0);
  top = L->top;
  top->value.n = (double)v1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004150
// Name: luaB_collectgarbage
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_collectgarbage(lua_State *L)
{
  int v1; // esi
  lua_TValue *v2; // eax
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  lua_TValue *v6; // eax
  int v8; // eax
  lua_TValue *top; // ecx

  v1 = luaL_checkoption(def: "collect", lst: (const char **)opts, L, narg: 1);
  v2 = L->base + 1;
  if ( v2 >= L->top || v2 == &luaO_nilobject_ || L->base[1].tt <= 0 )
    v3 = 0;
  else
    v3 = luaL_checkinteger(L, narg: 2);
  v4 = optsnum[v1];
  if ( v4 > 7 )
    v5 = -1;
  else
    v5 = lua_gc(data: v3, g: (int)L->l_G, a3: v4, L, res: 0);
  if ( optsnum[v1] == 3 )
  {
    v8 = lua_gc(data: 0, g: (int)L->l_G, a3: 4, L, res: 0);
    top = L->top;
    top->value.n = (double)v8 * 0.0009765625 + (double)v5;
    top->tt = 3;
    ++L->top;
    return 1;
  }
  else
  {
    v6 = L->top;
    if ( optsnum[v1] == 5 )
    {
      v6->tt = 1;
      v6->value.b = v5 != 0;
    }
    else
    {
      v6->value.n = (double)v5;
      v6->tt = 3;
    }
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004270
// Name: luaB_type
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_type(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  unsigned int v5; // ebx
  lua_TValue *v6; // edi
  char *str; // [esp+8h] [ebp-4h]

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  v2 = L->base;
  top = L->top;
  if ( v2 >= top || v2 == &luaO_nilobject_ || (tt = v2->tt) == -1 )
  {
    str = "no value";
  }
  else
  {
    str = (char *)luaT_typenames[tt];
    if ( str == nullptr )
    {
      top->tt = 0;
      ++L->top;
      return 1;
    }
  }
  v5 = strlen(str);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  v6 = L->top;
  v6->value.b = (int)luaS_newlstr(L, str, l: v5);
  v6->tt = 4;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004330
// Name: luaB_next
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_next(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // ecx
  lua_TValue *v7; // eax

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  v6 = L->base;
  v7 = v6 + 2;
  L->top = v6 + 2;
  if ( v6 >= &v6[2] )
    v6 = &luaO_nilobject_;
  if ( luaH_next(L, t: (Table *)v6->value.gc, key: v7 - 1) != 0 )
  {
    ++L->top;
    return 2;
  }
  else
  {
    --L->top;
    L->top->tt = 0;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004410
// Name: luaB_pairs
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_pairs(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *func; // edx
  lua_TValue *v7; // ecx
  lua_TValue *v8; // ecx
  lua_TValue *v9; // eax

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  func = L->ci->func;
  v7 = (lua_TValue *)(func->value.b + 24);
  if ( *(_BYTE *)(func->value.b + 7) == 0 )
    v7 = &luaO_nilobject_;
  *L->top = *v7;
  v8 = L->base;
  v9 = ++L->top;
  if ( v8 >= v9 )
    v8 = &luaO_nilobject_;
  v9->value.b = v8->value.b;
  *(&v9->value.b + 1) = *(&v8->value.b + 1);
  v9->tt = v8->tt;
  ++L->top;
  L->top->tt = 0;
  ++L->top;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x100044E0
// Name: ipairsaux
// Source: json
//------------------------------------------------------------------------------
int __cdecl ipairsaux(lua_State *L)
{
  int v1; // eax
  lua_TValue *base; // ecx
  lua_TValue *top; // edx
  int tt; // ecx
  const char *v5; // ecx
  const char *v6; // eax
  lua_TValue *v7; // ecx
  int v8; // eax
  lua_TValue *v9; // edi
  lua_TValue *v10; // ecx
  lua_TValue *v11; // eax

  v1 = luaL_checkinteger(L, narg: 2);
  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v5 = luaT_typenames[tt];
LABEL_9:
        v6 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v5);
        luaL_argerror(L, extramsg: v6, narg: 1);
      }
    }
LABEL_7:
    v5 = "no value";
    goto LABEL_9;
  }
  v7 = L->top;
  v8 = v1 + 1;
  v7->tt = 3;
  v7->value.n = (double)v8;
  v9 = ++L->top;
  v10 = L->base;
  if ( v10 >= v9 )
    v10 = &luaO_nilobject_;
  *v9 = *luaH_getnum(t: (Table *)v10->value.gc, key: v8);
  v11 = L->top++;
  if ( v11 == &luaO_nilobject_ )
    return 2;
  else
    return v11->tt != 0 ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x100045D0
// Name: luaB_ipairs
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_ipairs(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *func; // edx
  lua_TValue *v7; // ecx
  lua_TValue *v8; // ecx
  lua_TValue *v9; // eax
  lua_TValue *v10; // eax

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  func = L->ci->func;
  v7 = (lua_TValue *)(func->value.b + 24);
  if ( *(_BYTE *)(func->value.b + 7) == 0 )
    v7 = &luaO_nilobject_;
  *L->top = *v7;
  v8 = L->base;
  v9 = ++L->top;
  if ( v8 >= v9 )
    v8 = &luaO_nilobject_;
  v9->value.b = v8->value.b;
  *(&v9->value.b + 1) = *(&v8->value.b + 1);
  v9->tt = v8->tt;
  v10 = ++L->top;
  v10->value.n = 0.0;
  v10->tt = 3;
  ++L->top;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x100046A0
// Name: luaB_loadstring
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_loadstring(lua_State *L)
{
  lua_TValue *base; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax
  const char *v8; // eax
  _DWORD data[2]; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int l; // [esp+14h] [ebp-4h]

  base = L->base;
  if ( base >= L->top )
    base = &luaO_nilobject_;
  if ( base->tt != 4 )
  {
    if ( luaV_tostring(L, obj: base) == 0 )
    {
      l = 0;
      data[0] = 0;
LABEL_11:
      v3 = L->base;
      if ( v3 >= L->top || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring(L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror(L, extramsg: v6, narg: 1);
    }
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    base = L->base;
    if ( base >= L->top )
      base = &luaO_nilobject_;
  }
  b = base->value.b;
  l = *(_DWORD *)(b + 16);
  data[0] = b + 24;
  if ( b == -24 )
    goto LABEL_11;
  v7 = L->base + 1;
  if ( v7 >= L->top || v7 == &luaO_nilobject_ || L->base[1].tt <= 0 )
    v8 = (const char *)data[0];
  else
    v8 = luaL_checklstring(L, len: nullptr, narg: 2);
  data[1] = l;
  if ( lua_load(reader: (const char *(__cdecl *)(lua_State *, void *, unsigned int *))getS, chunkname: v8, L, data) == 0 )
    return 1;
  L->top->tt = 0;
  ++L->top;
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x100047E0
// Name: luaB_loadfile
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_loadfile(lua_State *L)
{
  lua_TValue *base; // eax
  const char *v2; // eax

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt <= 0 )
    v2 = nullptr;
  else
    v2 = luaL_checklstring(L, len: nullptr, narg: 1);
  if ( luaL_loadfile(L, filename: v2) == 0 )
    return 1;
  L->top->tt = 0;
  ++L->top;
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10004850
// Name: generic_reader
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl generic_reader(lua_State *L, void *ud, unsigned int *size)
{
  int stacksize; // eax
  int v4; // eax
  CallInfo *ci; // ecx
  lua_TValue *v6; // eax
  lua_TValue *base; // ecx
  lua_TValue *top; // eax
  lua_TValue *v9; // edx
  lua_TValue *v10; // eax
  int tt; // ecx
  lua_TValue *v13; // ecx

  if ( L->top - L->base + 2 > 8000 )
    luaL_error(L, fmt: "stack overflow (%s)", "too many nested functions");
  if ( (char *)L->stack_last - (char *)L->top <= 32 )
  {
    stacksize = L->stacksize;
    if ( stacksize < 2 )
      v4 = stacksize + 2;
    else
      v4 = 2 * stacksize;
    luaD_reallocstack(L, newsize: v4);
  }
  ci = L->ci;
  v6 = L->top + 2;
  if ( ci->top < v6 )
    ci->top = v6;
  base = L->base;
  top = L->top;
  if ( base >= top )
    base = &luaO_nilobject_;
  top->value.b = base->value.b;
  *(&top->value.b + 1) = *(&base->value.b + 1);
  top->tt = base->tt;
  luaD_call(L, func: L->top++, nResults: 1);
  v9 = L->top;
  v10 = v9 - 1;
  if ( &v9[-1] != &luaO_nilobject_ )
  {
    if ( v10->tt == 0 )
    {
      *size = 0;
      return nullptr;
    }
    if ( v10 != &luaO_nilobject_ )
    {
      tt = v10->tt;
      if ( tt == 4 || tt == 3 )
      {
        v13 = L->base + 2;
        if ( v13 >= v9 )
          v13 = &luaO_nilobject_;
        v13->value.b = v10->value.b;
        *(&v13->value.b + 1) = *(&v10->value.b + 1);
        v13->tt = v10->tt;
        --L->top;
        return lua_tolstring(L, idx: 3, len: size);
      }
    }
  }
  luaL_error(L, fmt: "reader function must return a string");
}

//------------------------------------------------------------------------------
// Address: 0x10004970
// Name: luaB_load
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_load(lua_State *L)
{
  lua_TValue *v1; // eax
  const char *v2; // ebx
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax

  v1 = L->base + 1;
  if ( v1 >= L->top || v1 == &luaO_nilobject_ || L->base[1].tt <= 0 )
    v2 = "=(load)";
  else
    v2 = luaL_checklstring(L, len: nullptr, narg: 2);
  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_12;
  if ( base == &luaO_nilobject_ || base->tt != 6 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v6 = luaT_typenames[tt];
LABEL_14:
        v7 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v6);
        luaL_argerror(L, extramsg: v7, narg: 1);
      }
    }
LABEL_12:
    v6 = "no value";
    goto LABEL_14;
  }
  for ( ; L->top < L->base + 3; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 3;
  if ( lua_load(reader: generic_reader, chunkname: v2, L, data: nullptr) == 0 )
    return 1;
  L->top->tt = 0;
  ++L->top;
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10004A80
// Name: luaB_dofile
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_dofile(lua_State *L)
{
  lua_TValue *base; // eax
  const char *v2; // eax
  int v3; // edi
  CallInfo *ci; // eax
  lua_TValue *top; // ecx

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt <= 0 )
    v2 = nullptr;
  else
    v2 = luaL_checklstring(L, len: nullptr, narg: 1);
  v3 = L->top - L->base;
  if ( luaL_loadfile(L, filename: v2) != 0 )
    luaG_errormsg(L);
  luaD_call(L, func: L->top - 1, nResults: -1);
  ci = L->ci;
  top = L->top;
  if ( top >= ci->top )
    ci->top = top;
  return L->top - L->base - v3;
}

//------------------------------------------------------------------------------
// Address: 0x10004B00
// Name: luaB_assert
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_assert(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // ecx
  lua_TValue *top; // eax
  lua_TValue *v4; // edi
  int tt; // edx
  lua_TValue *v6; // ecx
  const char *v7; // eax

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  v2 = L->base;
  top = L->top;
  v4 = &luaO_nilobject_;
  if ( v2 < top )
    v4 = L->base;
  tt = v4->tt;
  if ( tt == 0 || tt == 1 && v4->value.b == 0 )
  {
    v6 = v2 + 1;
    if ( v6 < top && v6 != &luaO_nilobject_ && v6->tt > 0 )
    {
      v7 = luaL_checklstring(L, len: nullptr, narg: 2);
      luaL_error(L, fmt: "%s", v7);
    }
    luaL_error(L, fmt: "%s", "assertion failed!");
  }
  return top - v2;
}

//------------------------------------------------------------------------------
// Address: 0x10004BB0
// Name: luaB_unpack
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_unpack(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  int v7; // edi
  lua_TValue *v8; // esi
  lua_TValue *v9; // ecx
  int v10; // eax
  int v12; // eax
  lua_TValue *v13; // ecx
  lua_TValue *v14; // edi
  lua_TValue *j; // edi
  lua_TValue *v16; // ecx
  int n; // [esp+Ch] [ebp-Ch]
  int e; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base + 1;
  if ( v6 >= L->top || v6 == &luaO_nilobject_ || L->base[1].tt <= 0 )
  {
    v7 = 1;
    i = 1;
  }
  else
  {
    i = luaL_checkinteger(L, narg: 2);
    v7 = i;
  }
  v8 = L->base;
  v9 = L->top;
  if ( &v8[2] >= v9 || &v8[2] == &luaO_nilobject_ || v8[2].tt <= 0 )
  {
    if ( v8 >= v9 )
      v8 = &luaO_nilobject_;
    switch ( v8->tt )
    {
      case 3:
        if ( luaV_tostring(L, obj: v8) == 0 )
          goto LABEL_26;
        v10 = *(_DWORD *)(v8->value.b + 16);
        e = v10;
        break;
      case 4:
        v10 = *(_DWORD *)(v8->value.b + 16);
        e = v10;
        break;
      case 5:
        v10 = luaH_getn(t: (Table *)v8->value.gc);
        e = v10;
        break;
      case 7:
        v10 = *(_DWORD *)(v8->value.b + 16);
        e = v10;
        break;
      default:
LABEL_26:
        v10 = 0;
        e = 0;
        break;
    }
  }
  else
  {
    v10 = luaL_checkinteger(L, narg: 3);
    e = v10;
  }
  if ( v7 > v10 )
    return 0;
  v12 = v10 - v7 + 1;
  n = v12;
  if ( v12 <= 0 || lua_checkstack(L, size: v12) == 0 )
    luaL_error(L, fmt: "too many results to unpack");
  v13 = L->base;
  v14 = L->top;
  if ( v13 >= v14 )
    v13 = &luaO_nilobject_;
  *v14 = *luaH_getnum(t: (Table *)v13->value.gc, key: i);
  for ( j = ++L->top; i < e; j = L->top )
  {
    ++i;
    v16 = &luaO_nilobject_;
    if ( L->base < j )
      v16 = L->base;
    *j = *luaH_getnum(t: (Table *)v16->value.gc, key: i);
    ++L->top;
  }
  return n;
}

//------------------------------------------------------------------------------
// Address: 0x10004DA0
// Name: luaB_select
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_select(lua_State *L)
{
  lua_TValue *top; // ecx
  lua_TValue *base; // eax
  int v3; // edi
  _BYTE *v4; // eax
  lua_TValue *v5; // eax
  int v7; // eax
  int v8; // ecx

  top = L->top;
  base = L->base;
  v3 = top - base;
  if ( base >= top || base == &luaO_nilobject_ || base->tt != 4 )
    goto LABEL_15;
  if ( base >= top )
    base = &luaO_nilobject_;
  if ( base->tt != 4 )
  {
    v4 = (_BYTE *)luaV_tostring(L, obj: base);
    if ( v4 == nullptr )
      goto LABEL_13;
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    base = L->base;
    if ( base >= L->top )
      base = &luaO_nilobject_;
  }
  v4 = (_BYTE *)(base->value.b + 24);
LABEL_13:
  if ( *v4 == 35 )
  {
    v5 = L->top;
    v5->value.n = (double)(v3 - 1);
    v5->tt = 3;
    ++L->top;
    return 1;
  }
LABEL_15:
  v7 = luaL_checkinteger(L, narg: 1);
  v8 = v7;
  if ( v7 >= 0 )
  {
    if ( v7 > v3 )
      v8 = v3;
  }
  else
  {
    v8 = v3 + v7;
  }
  if ( v8 < 1 )
    luaL_argerror(L, extramsg: "index out of range", narg: 1);
  return v3 - v8;
}

//------------------------------------------------------------------------------
// Address: 0x10004E90
// Name: luaB_pcall
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_pcall(lua_State *L)
{
  lua_TValue *base; // eax
  int v2; // eax
  int v3; // eax
  CallInfo *ci; // ecx
  lua_TValue *top; // edx
  lua_TValue *v6; // ecx
  lua_TValue *v7; // ecx
  lua_TValue *v8; // edx
  int *v9; // eax
  _DWORD u[2]; // [esp+8h] [ebp-8h] BYREF

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  u[0] = (char *)L->top - (((char *)L->top - (char *)L->base) & 0xFFFFFFF0);
  v2 = u[0] - (unsigned int)L->stack;
  u[1] = -1;
  v3 = luaD_pcall(L, func: f_call, u, old_top: v2, ef: 0);
  ci = L->ci;
  top = L->top;
  if ( top >= ci->top )
    ci->top = top;
  v6 = L->top;
  v6->tt = 1;
  v6->value.b = v3 == 0;
  v7 = ++L->top;
  v8 = L->base;
  if ( v7 > v8 || (v8 = &luaO_nilobject_, v7 > &luaO_nilobject_) )
  {
    v9 = (int *)&v7[-1];
    do
    {
      v7->value.b = *v9;
      *(&v7->value.b + 1) = v9[1];
      v9[6] = v9[2];
      --v7;
      v9 -= 4;
    }
    while ( v7 > v8 );
  }
  *v8 = *L->top;
  return L->top - L->base;
}

//------------------------------------------------------------------------------
// Address: 0x10004F70
// Name: luaB_xpcall
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_xpcall(lua_State *L)
{
  lua_TValue *v1; // eax
  lua_TValue *base; // edx
  lua_TValue *v3; // ecx
  int *v4; // eax
  lua_TValue *v5; // eax
  lua_TValue *top; // edi
  lua_TValue *stack; // ecx
  int v8; // eax
  CallInfo *ci; // ecx
  lua_TValue *v10; // edx
  lua_TValue *v11; // ecx
  lua_TValue *v12; // eax
  lua_TValue *v13; // ecx
  _DWORD u[2]; // [esp+8h] [ebp-8h] BYREF

  v1 = L->base + 1;
  if ( v1 >= L->top || v1 == &luaO_nilobject_ || L->base[1].tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 2);
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  base = L->base;
  v3 = base + 2;
  L->top = base + 2;
  if ( &base[2] >= base || (base = &luaO_nilobject_, v3 > &luaO_nilobject_) )
  {
    v4 = (int *)&v3[-1];
    do
    {
      v3->value.b = *v4;
      *(&v3->value.b + 1) = v4[1];
      v4[6] = v4[2];
      --v3;
      v4 -= 4;
    }
    while ( v3 > base );
  }
  *base = *L->top;
  v5 = L->base;
  top = L->top;
  if ( v5 >= top )
    v5 = &luaO_nilobject_;
  stack = L->stack;
  u[0] = top - 1;
  u[1] = -1;
  v8 = luaD_pcall(L, func: f_call, u, old_top: (char *)&top[-1] - (char *)stack, ef: (char *)v5 - (char *)stack);
  ci = L->ci;
  v10 = L->top;
  if ( v10 >= ci->top )
    ci->top = v10;
  v11 = L->top;
  v11->tt = 1;
  v11->value.b = v8 == 0;
  v12 = ++L->top;
  v13 = L->base;
  if ( v13 >= v12 )
    v13 = &luaO_nilobject_;
  v13->value.b = v12[-1].value.b;
  *(&v13->value.b + 1) = *(&v12[-1].value.b + 1);
  v13->tt = v12[-1].tt;
  return --L->top - L->base;
}

//------------------------------------------------------------------------------
// Address: 0x100050B0
// Name: luaB_tostring
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_tostring(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // eax
  lua_TValue *top; // edx
  int result; // eax
  int v5; // ecx
  lua_TValue *v6; // ecx
  const void *b; // ecx
  int tt; // eax
  const char *v9; // eax

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  if ( luaL_callmeta(L) != 0 )
    return 1;
  v2 = L->base;
  top = L->top;
  if ( v2 >= top )
    goto LABEL_31;
  if ( v2 == &luaO_nilobject_ )
  {
LABEL_30:
    if ( v2 < top )
    {
      v6 = L->base;
      goto LABEL_33;
    }
LABEL_31:
    v6 = &luaO_nilobject_;
LABEL_33:
    switch ( v6->tt )
    {
      case 2:
      case 7:
        v6 = &luaO_nilobject_;
        if ( v2 < top )
          v6 = L->base;
        if ( v6->tt == 2 )
          goto $LN138;
        if ( v6->tt != 7 )
          goto LABEL_40;
        b = (const void *)(v6->value.b + 24);
        break;
      case 5:
      case 6:
      case 8:
$LN138:
        b = (const void *)v6->value.b;
        break;
      default:
LABEL_40:
        b = nullptr;
        break;
    }
    if ( v2 >= top || v2 == &luaO_nilobject_ || (tt = v2->tt) == -1 )
      v9 = "no value";
    else
      v9 = luaT_typenames[tt];
    lua_pushfstring(L, fmt: "%s: %p", v9, b);
    return 1;
  }
  switch ( v2->tt )
  {
    case 0:
      lua_pushlstring(L, s: "nil", len: 3u);
      return 1;
    case 1:
      if ( v2 >= top )
        v2 = &luaO_nilobject_;
      v5 = v2->tt;
      if ( v5 != 0 && (v5 != 1 || v2->value.b != 0) )
      {
        lua_pushstring(L, s: "true");
        return 1;
      }
      else
      {
        lua_pushstring(L, s: "false");
        return 1;
      }
    case 3:
      if ( v2 >= top )
        v2 = &luaO_nilobject_;
      if ( v2->tt == 4 )
        goto LABEL_18;
      if ( luaV_tostring(L, obj: v2) != 0 )
      {
        if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
          luaC_step(L);
        v2 = L->base;
        if ( v2 >= L->top )
          v2 = &luaO_nilobject_;
LABEL_18:
        lua_pushstring(L, s: (const char *)(v2->value.b + 24));
        result = 1;
      }
      else
      {
        lua_pushstring(L, s: nullptr);
        result = 1;
      }
      break;
    case 4:
      if ( v2 >= top )
        v2 = &luaO_nilobject_;
      top->value.b = v2->value.b;
      *(&top->value.b + 1) = *(&v2->value.b + 1);
      top->tt = v2->tt;
      ++L->top;
      return 1;
    default:
      goto LABEL_30;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100052D0
// Name: luaB_newproxy
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_newproxy(lua_State *L)
{
  global_State *l_G; // eax
  CallInfo *ci; // eax
  GCObject *gc; // ebx
  global_State *v4; // edi
  GCObject *v5; // eax
  unsigned __int8 currentwhite; // dl
  lua_TValue *top; // ecx
  lua_TValue *base; // eax
  lua_TValue *v9; // ecx
  lua_TValue *v10; // edi
  int tt; // edx
  lua_TValue *v12; // eax
  lua_TValue *func; // ecx
  Table **v14; // eax
  lua_TValue *v15; // eax
  int v16; // ecx
  lua_TValue *v17; // eax
  BOOL v18; // ecx

  for ( ; L->top < L->base + 1; ++L->top )
    L->top->tt = 0;
  l_G = L->l_G;
  L->top = L->base + 1;
  if ( l_G->totalbytes >= l_G->GCthreshold )
    luaC_step(L);
  ci = L->ci;
  if ( ci == L->base_ci )
    gc = L->l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
  v4 = L->l_G;
  v5 = (GCObject *)v4->frealloc(a1: v4->ud, a2: nullptr, a3: 0, a4: 24u);
  if ( v5 == nullptr )
    luaD_throw(L, errcode: 4);
  v4->totalbytes += 24;
  currentwhite = L->l_G->currentwhite;
  v5->ts.tsv.keyhash = (unsigned int)gc;
  v5->ts.tsv.len = 0;
  v5->ts.tsv.hash = 0;
  v5->gch.marked = currentwhite & 3;
  v5->gch.tt = 7;
  v5->ts.dummy.l = (int)L->l_G->mainthread->next;
  L->l_G->mainthread->next = v5;
  top = L->top;
  top->value.b = (int)v5;
  top->tt = 7;
  base = L->base;
  v9 = ++L->top;
  v10 = &luaO_nilobject_;
  if ( base < v9 )
    v10 = base;
  tt = v10->tt;
  if ( tt != 0 && (tt != 1 || v10->value.b != 0) )
  {
    if ( base >= v9 || base == &luaO_nilobject_ || base->tt != 1 )
    {
      if ( lua_getmetatable(L, objindex: 1) == 0 )
        goto LABEL_29;
      func = L->ci->func;
      v14 = *(_BYTE *)(func->value.b + 7) != 0 ? (Table **)(func->value.b + 24) : (Table **)&luaO_nilobject_;
      L->top[-1] = *luaH_get(t: *v14, key: (const lua_TValue *)L->top - 1);
      v15 = L->top;
      v16 = v15[-1].tt;
      v17 = v15 - 1;
      v18 = v16 != 0 && (v16 != 1 || v17->value.b != 0);
      L->top = v17;
      if ( !v18 )
LABEL_29:
        luaL_argerror(L, extramsg: "boolean or proxy expected", narg: 1);
      lua_getmetatable(L, objindex: 1);
    }
    else
    {
      lua_createtable(L, narray: 0);
      *L->top = L->top[-1];
      v12 = ++L->top;
      v12->value.b = 1;
      v12->tt = 1;
      ++L->top;
      lua_rawset(L, idx: -10003);
    }
    lua_setmetatable(L, objindex: 2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100054C0
// Name: luaB_costatus
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_costatus(lua_State *L)
{
  lua_TValue *base; // eax
  lua_State *b; // ebx
  int v4; // eax
  const char *v5; // eax
  unsigned int v7; // ebx
  lua_TValue *top; // edi
  lua_Debug ar; // [esp+Ch] [ebp-64h] BYREF
  lua_State *La; // [esp+78h] [ebp+8h]

  base = L->base;
  if ( base >= L->top )
    base = &luaO_nilobject_;
  if ( base->tt != 8 || (b = (lua_State *)base->value.b, base->value.b == 0) )
    luaL_argerror(L, extramsg: "coroutine expected", narg: 1);
  if ( L == b )
  {
    v4 = 0;
  }
  else if ( b->status != 0 )
  {
    if ( b->status == 1 )
      v4 = 1;
    else
      v4 = 3;
  }
  else if ( lua_getstack(L: b, level: 0, &ar) <= 0 )
  {
    v4 = (((char *)b->top - (char *)b->base) & 0xFFFFFFF0) != 0 ? 1 : 3;
  }
  else
  {
    v4 = 2;
  }
  v5 = statnames[v4];
  La = (lua_State *)v5;
  if ( v5 != nullptr )
  {
    v7 = strlen(v5);
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    top->value.b = (int)luaS_newlstr(L, str: (const char *)La, l: v7);
    top->tt = 4;
    ++L->top;
    return 1;
  }
  else
  {
    L->top->tt = 0;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055C0
// Name: auxresume
// Source: json
//------------------------------------------------------------------------------
int __cdecl auxresume(lua_State *L, lua_State *co, int narg)
{
  int v3; // edi
  int v5; // edi
  lua_Debug ar; // [esp+Ch] [ebp-64h] BYREF

  if ( L == co )
  {
    v3 = 0;
  }
  else if ( co->status != 0 )
  {
    if ( co->status == 1 )
      v3 = 1;
    else
      v3 = 3;
  }
  else if ( lua_getstack(L: co, level: 0, &ar) <= 0 )
  {
    v3 = (((char *)co->top - (char *)co->base) & 0xFFFFFFF0) != 0 ? 1 : 3;
  }
  else
  {
    v3 = 2;
  }
  if ( lua_checkstack(L: co, size: narg) == 0 )
    luaL_error(L, fmt: "too many arguments to resume");
  if ( v3 == 1 )
  {
    lua_xmove(from: L, to: co, n: narg);
    co->nCcalls = L->nCcalls;
    if ( (unsigned int)lua_resume(L: co, nargs: narg) < 2 )
    {
      v5 = co->top - co->base;
      if ( lua_checkstack(L, size: v5 + 1) == 0 )
        luaL_error(L, fmt: "too many results to resume");
      lua_xmove(from: co, to: L, n: v5);
      return v5;
    }
    else
    {
      lua_xmove(from: co, to: L, n: 1);
      return -1;
    }
  }
  else
  {
    lua_pushfstring(L, fmt: "cannot resume %s coroutine", statnames[v3]);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100056E0
// Name: luaB_coresume
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_coresume(lua_State *L)
{
  lua_TValue *base; // eax
  int v2; // edi
  lua_TValue *top; // eax

  base = L->base;
  if ( base >= L->top )
    base = &luaO_nilobject_;
  if ( base->tt != 8 || base->value.b == 0 )
    luaL_argerror(L, extramsg: "coroutine expected", narg: 1);
  v2 = auxresume(L, co: (lua_State *)base->value.gc, narg: L->top - L->base - 1);
  top = L->top;
  top->tt = 1;
  if ( v2 >= 0 )
  {
    top->value.b = 1;
    ++L->top;
    lua_insert(L, idx: -1 - v2);
    return v2 + 1;
  }
  else
  {
    top->value.b = 0;
    ++L->top;
    lua_insert(L, idx: -2);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005780
// Name: luaB_auxwrap
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_auxwrap(lua_State *L)
{
  lua_TValue *func; // ecx
  lua_TValue *v2; // eax
  lua_State *b; // ecx
  int result; // eax
  lua_TValue *v5; // eax
  int tt; // eax

  func = L->ci->func;
  if ( *(_BYTE *)(func->value.b + 7) != 0 )
    v2 = (lua_TValue *)(func->value.b + 24);
  else
    v2 = &luaO_nilobject_;
  if ( v2->tt == 8 )
    b = (lua_State *)v2->value.b;
  else
    b = nullptr;
  result = auxresume(L, co: b, narg: L->top - L->base);
  if ( result < 0 )
  {
    v5 = L->top - 1;
    if ( v5 != &luaO_nilobject_ )
    {
      tt = v5->tt;
      if ( tt == 4 || tt == 3 )
      {
        luaL_where(L, level: 1);
        lua_insert(L, idx: -2);
        if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
          luaC_step(L);
        luaV_concat(L, total: 2, last: L->top - L->base - 1);
        --L->top;
      }
    }
    luaG_errormsg(L);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005830
// Name: luaB_cocreate
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_cocreate(lua_State *L)
{
  lua_State *v1; // ebx
  lua_TValue *top; // eax
  lua_TValue *v3; // ecx
  lua_TValue *base; // eax
  lua_TValue *v5; // eax
  lua_TValue *v6; // ecx
  lua_TValue *v7; // eax
  lua_TValue *v8; // ecx

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  v1 = luaE_newthread(L);
  top = L->top;
  top->value.b = (int)v1;
  top->tt = 8;
  v3 = ++L->top;
  base = L->base;
  if ( base < v3 && base != &luaO_nilobject_ && base->tt == 6 )
  {
    if ( base >= v3 )
      base = &luaO_nilobject_;
    if ( base->tt != 6 || *(_BYTE *)(base->value.b + 6) == 0 )
    {
      v5 = L->base;
      v6 = L->top;
      if ( v5 >= v6 )
        v5 = &luaO_nilobject_;
      v6->value.b = v5->value.b;
      *(&v6->value.b + 1) = *(&v5->value.b + 1);
      v6->tt = v5->tt;
      ++L->top;
      if ( L != v1 )
      {
        v7 = L->top - 1;
        L->top = v7;
        v8 = v1->top;
        v1->top = v8 + 1;
        *v8 = *v7;
      }
      return 1;
    }
  }
  luaL_argerror(L, extramsg: "Lua function expected", narg: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10005900
// Name: luaB_cowrap
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_cowrap(lua_State *L)
{
  luaB_cocreate(L);
  lua_pushcclosure(L, fn: luaB_auxwrap, n: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005930
// Name: luaB_yield
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_yield(lua_State *L)
{
  if ( L->nCcalls > L->baseCcalls )
    luaG_runerror(L, fmt: "attempt to yield across metamethod/C-call boundary");
  L->base = (lua_TValue *)((char *)L->top - (((char *)L->top - (char *)L->base) & 0xFFFFFFF0));
  L->status = 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10005970
// Name: luaB_corunning
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_corunning(lua_State *L)
{
  lua_TValue *top; // ecx
  global_State *l_G; // esi

  top = L->top;
  top->value.b = (int)L;
  top->tt = 8;
  l_G = L->l_G;
  ++L->top;
  if ( l_G->mainthread == L )
  {
    L->top->tt = 0;
    ++L->top;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100059B0
// Name: base_open
// Source: json
//------------------------------------------------------------------------------
void __usercall base_open(lua_State *L@<eax>)
{
  GCObject *gc; // ecx
  lua_TValue *top; // eax
  TString *v4; // eax
  lua_TValue *v5; // ebx
  TString *v6; // eax
  const lua_TValue *v7; // ebx
  TString *v8; // eax
  const lua_TValue *v9; // ebx
  lua_TValue *v10; // eax
  lua_TValue *v11; // ebx
  const lua_TValue *v12; // ebx
  TString *v13; // eax
  TString *v14; // eax
  lua_TValue *v15; // [esp-4h] [ebp-24h]
  lua_TValue *v16; // [esp-4h] [ebp-24h]
  lua_TValue *v17; // [esp-4h] [ebp-24h]
  lua_TValue *v18; // [esp-4h] [ebp-24h]
  lua_TValue *v19; // [esp-4h] [ebp-24h]
  lua_TValue *v20; // [esp-4h] [ebp-24h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  gc = L->l_gt.value.gc;
  top = L->top;
  top->value.b = (int)gc;
  *(&top->value.b + 1) = *(&L->l_gt.value.b + 1);
  top->tt = L->l_gt.tt;
  ++L->top;
  v4 = luaS_newlstr(L, str: "_G", l: 2u);
  v15 = L->top - 1;
  key.value.b = (int)v4;
  key.tt = 4;
  luaV_settable(L, t: &L->l_gt, &key, val: v15);
  --L->top;
  luaL_openlib(L, libname: "_G", l: base_funcs);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  v5 = L->top;
  v5->value.b = (int)luaS_newlstr(L, str: "Lua 5.1", l: 7u);
  v5->tt = 4;
  ++L->top;
  v6 = luaS_newlstr(L, str: "_VERSION", l: 8u);
  v16 = L->top - 1;
  key.value.b = (int)v6;
  key.tt = 4;
  luaV_settable(L, t: &L->l_gt, &key, val: v16);
  --L->top;
  lua_pushcclosure(L, fn: ipairsaux, n: 0);
  lua_pushcclosure(L, fn: luaB_ipairs, n: 1);
  v7 = L->top - 2;
  v8 = luaS_newlstr(L, str: "ipairs", l: 6u);
  v17 = L->top - 1;
  key.value.b = (int)v8;
  key.tt = 4;
  luaV_settable(L, t: v7, &key, val: v17);
  --L->top;
  lua_pushcclosure(L, fn: luaB_next, n: 0);
  lua_pushcclosure(L, fn: luaB_pairs, n: 1);
  v9 = L->top - 2;
  key.value.b = (int)luaS_newlstr(L, str: "pairs", l: 5u);
  v18 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v9, &key, val: v18);
  --L->top;
  lua_createtable(L, narray: 1);
  v10 = L->top;
  v10->value.b = v10[-1].value.b;
  *(&v10->value.b + 1) = *(&v10[-1].value.b + 1);
  v10->tt = v10[-1].tt;
  ++L->top;
  lua_setmetatable(L, objindex: -2);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  v11 = L->top;
  v11->value.b = (int)luaS_newlstr(L, str: "kv", l: 2u);
  v11->tt = 4;
  v12 = ++L->top - 2;
  v13 = luaS_newlstr(L, str: "__mode", l: 6u);
  v19 = L->top - 1;
  key.value.b = (int)v13;
  key.tt = 4;
  luaV_settable(L, t: v12, &key, val: v19);
  --L->top;
  lua_pushcclosure(L, fn: luaB_newproxy, n: 1);
  v14 = luaS_newlstr(L, str: "newproxy", l: 8u);
  v20 = L->top - 1;
  key.value.b = (int)v14;
  key.tt = 4;
  luaV_settable(L, t: &L->l_gt, &key, val: v20);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10005C10
// Name: _luaopen_base
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_base(lua_State *L)
{
  base_open(L);
  luaL_openlib(L, libname: "coroutine", l: co_funcs);
  return 2;
}
