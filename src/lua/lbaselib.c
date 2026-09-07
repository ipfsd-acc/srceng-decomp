// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lbaselib.c
// Functions: 40
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004837F0
// Name: luaB_print
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_print(lua_State *L)
{
  int i; // edi
  const char *v2; // ebx
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  int n; // [esp+Ch] [ebp-4h]

  n = lua_gettop(L);
  lua_getfield(L, idx: -10002, k: "tostring");
  for ( i = 1; i <= n; ++i )
  {
    lua_pushvalue(L, idx: -1);
    lua_pushvalue(L, idx: i);
    lua_call(L, nargs: 1, nresults: 1);
    v2 = lua_tolstring(L, idx: -1, len: nullptr);
    if ( v2 == nullptr )
      luaL_error(L, fmt: "'tostring' must return a string to 'print'");
    if ( i > 1 )
    {
      v3 = __iob_func();
      fputs(string: "\t", stream: v3 + 1);
    }
    v4 = __iob_func();
    fputs(string: v2, stream: v4 + 1);
    lua_settop(L, idx: -2);
  }
  v5 = __iob_func();
  fputs(string: "\n", stream: v5 + 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004838C0
// Name: luaB_tonumber
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_tonumber(lua_State *L)
{
  int v1; // edi
  double n; // st7
  const char *v4; // ebx
  unsigned int v5; // edi
  char *s2; // [esp+14h] [ebp-4h] BYREF

  v1 = (int)luaL_optinteger(L, narg: 2, def: 10);
  if ( v1 == 10 )
  {
    luaL_checkany(L, narg: 1);
    if ( lua_isnumber(L, idx: 1) != 0 )
    {
      n = lua_tonumber(L, idx: 1);
      lua_pushnumber(L, n);
      return 1;
    }
  }
  else
  {
    v4 = luaL_checklstring(L, narg: 1, len: nullptr);
    if ( v1 < 2 || v1 > 36 )
      luaL_argerror(L, narg: 2, extramsg: "base out of range");
    v5 = strtoul(nptr: v4, endptr: &s2, ibase: v1);
    if ( v4 != s2 )
    {
      for ( ; isspace(c: (unsigned __int8)*s2) != 0; ++s2 )
        ;
      if ( *s2 == 0 )
      {
        lua_pushnumber(L, n: (double)v5);
        return 1;
      }
    }
  }
  lua_pushnil(L);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004839D0
// Name: luaB_error
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaB_error(lua_State *L)
{
  lua_TValue *v1; // edi

  v1 = luaL_optinteger(L, narg: 2, def: 1);
  lua_settop(L, idx: 1);
  if ( lua_isstring(L, idx: 1) && (int)v1 > 0 )
  {
    luaL_where(L, level: (int)v1);
    lua_pushvalue(L, idx: 1);
    lua_concat(L, n: 2);
  }
  lua_error(L);
}

//------------------------------------------------------------------------------
// Address: 0x00483A30
// Name: luaB_getmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_getmetatable(lua_State *L)
{
  luaL_checkany(L, narg: 1);
  if ( lua_getmetatable(L, objindex: 1) != 0 )
    luaL_getmetafield(L, obj: 1, event: "__metatable");
  else
    lua_pushnil(L);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483A80
// Name: luaB_setmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_setmetatable(lua_State *L)
{
  int v1; // edi

  v1 = lua_type(L, idx: 2);
  luaL_checktype(L, narg: 1, t: 5);
  if ( v1 != 0 && v1 != 5 )
    luaL_argerror(L, narg: 2, extramsg: "nil or table expected");
  if ( luaL_getmetafield(L, obj: 1, event: "__metatable") != 0 )
    luaL_error(L, fmt: "cannot change a protected metatable");
  lua_settop(L, idx: 2);
  lua_setmetatable(L, objindex: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483B00
// Name: getfunc
// Source: json
//------------------------------------------------------------------------------
void __usercall getfunc(lua_State *L@<esi>)
{
  lua_TValue *v1; // edi
  lua_Debug ar; // [esp+0h] [ebp-64h] BYREF

  if ( lua_type(L, idx: 1) == 6 )
  {
    lua_pushvalue(L, idx: 1);
  }
  else
  {
    v1 = luaL_optinteger(L, narg: 1, def: 1);
    if ( (int)v1 < 0 )
      luaL_argerror(L, narg: 1, extramsg: "level must be non-negative");
    if ( lua_getstack(L, level: (int)v1, &ar) == 0 )
      luaL_argerror(L, narg: 1, extramsg: "invalid level");
    lua_getinfo(L, what: "f", &ar);
    if ( lua_type(L, idx: -1) == 0 )
      luaL_error(L, fmt: "no function environment for tail call at level %d", v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483BA0
// Name: luaB_getfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_getfenv(lua_State *L)
{
  getfunc(L);
  if ( lua_iscfunction(L, idx: -1) )
    lua_pushvalue(L, idx: -10002);
  else
    lua_getfenv(L, idx: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483BF0
// Name: luaB_setfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_setfenv(lua_State *L)
{
  luaL_checktype(L, narg: 2, t: 5);
  getfunc(L);
  lua_pushvalue(L, idx: 2);
  if ( lua_isnumber(L, idx: 1) != 0 && lua_tonumber(L, idx: 1) == 0.0 )
  {
    lua_pushthread(L);
    lua_insert(L, idx: -2);
    lua_setfenv(L, idx: -2);
    return 0;
  }
  else
  {
    if ( lua_iscfunction(L, idx: -2) || lua_setfenv(L, idx: -2) == 0 )
      luaL_error(L, fmt: "'setfenv' cannot change environment of given object");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483C90
// Name: luaB_rawequal
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_rawequal(lua_State *L)
{
  int v1; // eax

  luaL_checkany(L, narg: 1);
  luaL_checkany(L, narg: 2);
  v1 = lua_rawequal(L, index1: 1, index2: 2);
  lua_pushboolean(L, b: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483CD0
// Name: luaB_rawget
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_rawget(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  luaL_checkany(L, narg: 2);
  lua_settop(L, idx: 2);
  lua_rawget(L, idx: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483D10
// Name: luaB_rawset
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_rawset(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  luaL_checkany(L, narg: 2);
  luaL_checkany(L, narg: 3);
  lua_settop(L, idx: 3);
  lua_rawset(L, idx: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483D50
// Name: luaB_gcinfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_gcinfo(lua_State *L)
{
  int v1; // eax

  v1 = lua_gc(L, what: 3, data: 0);
  lua_pushinteger(L, n: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483D80
// Name: luaB_collectgarbage
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_collectgarbage(lua_State *L)
{
  int v1; // edi
  lua_TValue *v2; // eax
  int v3; // eax
  int v4; // edi
  double n; // xmm0_8

  v1 = luaL_checkoption(L, narg: 1, def: "collect", lst: (const char **)opts);
  v2 = luaL_optinteger(L, narg: 2, def: 0);
  v3 = lua_gc(L, what: optsnum[v1], data: (int)v2);
  v4 = optsnum[v1] - 3;
  if ( v4 != 0 )
  {
    if ( v4 == 2 )
    {
      lua_pushboolean(L, b: v3);
      return 1;
    }
    n = (double)v3;
  }
  else
  {
    n = (double)lua_gc(L, what: 4, data: 0) * 0.0009765625 + (double)v3;
  }
  lua_pushnumber(L, n);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483E30
// Name: luaB_type
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_type(lua_State *L)
{
  int v1; // eax
  const char *v2; // eax

  luaL_checkany(L, narg: 1);
  v1 = lua_type(L, idx: 1);
  v2 = lua_typename(L, t: v1);
  lua_pushstring(L, s: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483E60
// Name: luaB_next
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_next(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  lua_settop(L, idx: 2);
  if ( lua_next(L, idx: 1) != 0 )
    return 2;
  lua_pushnil(L);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483EB0
// Name: luaB_pairs
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_pairs(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  lua_pushvalue(L, idx: -10003);
  lua_pushvalue(L, idx: 1);
  lua_pushnil(L);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00483EF0
// Name: ipairsaux
// Source: json
//------------------------------------------------------------------------------
int __cdecl ipairsaux(lua_State *L)
{
  char *v1; // edi

  v1 = (char *)&luaL_checkinteger(L, narg: 2)->value.gc + 1;
  luaL_checktype(L, narg: 1, t: 5);
  lua_pushinteger(L, n: (int)v1);
  lua_rawgeti(L, idx: 1, n: (int)v1);
  return lua_type(L, idx: -1) != 0 ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x00483F40
// Name: luaB_ipairs
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_ipairs(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  lua_pushvalue(L, idx: -10003);
  lua_pushvalue(L, idx: 1);
  lua_pushinteger(L, n: 0);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00483F80
// Name: luaB_loadstring
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_loadstring(lua_State *L)
{
  const char *v1; // edi
  const char *v2; // eax
  unsigned int l; // [esp+8h] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  v2 = luaL_optlstring(L, narg: 2, def: v1, len: nullptr);
  if ( luaL_loadbuffer(L, buff: v1, size: l, name: v2) == 0 )
    return 1;
  lua_pushnil(L);
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00483FE0
// Name: luaB_loadfile
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_loadfile(lua_State *L)
{
  const char *v1; // eax

  v1 = luaL_optlstring(L, narg: 1, def: nullptr, len: nullptr);
  if ( luaL_loadfile(L, filename: v1) == 0 )
    return 1;
  lua_pushnil(L);
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00484030
// Name: generic_reader
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl generic_reader(lua_State *L, void *ud, unsigned int *size)
{
  luaL_checkstack(L, space: 2, mes: "too many nested functions");
  lua_pushvalue(L, idx: 1);
  lua_call(L, nargs: 0, nresults: 1);
  if ( lua_type(L, idx: -1) != 0 )
  {
    if ( !lua_isstring(L, idx: -1) )
      luaL_error(L, fmt: "reader function must return a string");
    lua_replace(L, idx: 3);
    return lua_tolstring(L, idx: 3, len: size);
  }
  else
  {
    *size = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004840B0
// Name: luaB_load
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_load(lua_State *L)
{
  const char *v1; // edi

  v1 = luaL_optlstring(L, narg: 2, def: "=(load)", len: nullptr);
  luaL_checktype(L, narg: 1, t: 6);
  lua_settop(L, idx: 3);
  if ( lua_load(L, reader: generic_reader, data: nullptr, chunkname: v1) == 0 )
    return 1;
  lua_pushnil(L);
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00484120
// Name: luaB_dofile
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_dofile(lua_State *L)
{
  const char *v1; // edi
  int v2; // ebx

  v1 = luaL_optlstring(L, narg: 1, def: nullptr, len: nullptr);
  v2 = lua_gettop(L);
  if ( luaL_loadfile(L, filename: v1) != 0 )
    lua_error(L);
  lua_call(L, nargs: 0, nresults: -1);
  return lua_gettop(L) - v2;
}

//------------------------------------------------------------------------------
// Address: 0x00484170
// Name: luaB_assert
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_assert(lua_State *L)
{
  const char *v1; // eax

  luaL_checkany(L, narg: 1);
  if ( !lua_toboolean(L, idx: 1) )
  {
    v1 = luaL_optlstring(L, narg: 2, def: "assertion failed!", len: nullptr);
    luaL_error(L, fmt: "%s", v1);
  }
  return lua_gettop(L);
}

//------------------------------------------------------------------------------
// Address: 0x004841C0
// Name: luaB_unpack
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_unpack(lua_State *L)
{
  lua_TValue *v1; // esi
  lua_TValue *v2; // eax
  lua_TValue *v3; // ebx
  int v4; // eax
  int n; // [esp+Ch] [ebp-4h]

  luaL_checktype(L, narg: 1, t: 5);
  v1 = luaL_optinteger(L, narg: 2, def: 1);
  if ( lua_type(L, idx: 3) > 0 )
    v2 = luaL_checkinteger(L, narg: 3);
  else
    v2 = (lua_TValue *)lua_objlen(L, idx: 1);
  v3 = v2;
  v4 = (char *)v2 - (char *)v1 + 1;
  n = v4;
  if ( v4 <= 0 )
    return 0;
  luaL_checkstack(L, space: v4, mes: "table too big to unpack");
  for ( ; (int)v1 <= (int)v3; v1 = (lua_TValue *)((char *)v1 + 1) )
    lua_rawgeti(L, idx: 1, n: (int)v1);
  return n;
}

//------------------------------------------------------------------------------
// Address: 0x00484250
// Name: luaB_select
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_select(lua_State *L)
{
  int v1; // ebx
  lua_TValue *v3; // eax
  int v4; // esi

  v1 = lua_gettop(L);
  if ( lua_type(L, idx: 1) == 4 && *lua_tolstring(L, idx: 1, len: nullptr) == 35 )
  {
    lua_pushinteger(L, n: v1 - 1);
    return 1;
  }
  else
  {
    v3 = luaL_checkinteger(L, narg: 1);
    v4 = (int)v3;
    if ( (int)v3 >= 0 )
    {
      if ( (int)v3 > v1 )
        v4 = v1;
    }
    else
    {
      v4 = (int)v3 + v1;
    }
    if ( v4 < 1 )
      luaL_argerror(L, narg: 1, extramsg: "index out of range");
    return v1 - v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004842D0
// Name: luaB_pcall
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_pcall(lua_State *L)
{
  int v1; // eax
  int v2; // eax

  luaL_checkany(L, narg: 1);
  v1 = lua_gettop(L);
  v2 = lua_pcall(L, nargs: v1 - 1, nresults: -1, errfunc: 0);
  lua_pushboolean(L, b: v2 == 0);
  lua_insert(L, idx: 1);
  return lua_gettop(L);
}

//------------------------------------------------------------------------------
// Address: 0x00484320
// Name: luaB_xpcall
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_xpcall(lua_State *L)
{
  int v1; // eax

  luaL_checkany(L, narg: 2);
  lua_settop(L, idx: 2);
  lua_insert(L, idx: 1);
  v1 = lua_pcall(L, nargs: 0, nresults: -1, errfunc: 1);
  lua_pushboolean(L, b: v1 == 0);
  lua_replace(L, idx: 1);
  return lua_gettop(L);
}

//------------------------------------------------------------------------------
// Address: 0x00484370
// Name: luaB_tostring
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_tostring(lua_State *L)
{
  const char *v1; // eax
  int result; // eax
  bool v3; // zf
  const char *v4; // eax
  int v5; // eax
  const char *v6; // eax
  const void *v7; // [esp-4h] [ebp-8h]

  luaL_checkany(L, narg: 1);
  if ( luaL_callmeta(L, obj: 1u, event: "__tostring") != 0 )
    return 1;
  switch ( lua_type(L, idx: 1) )
  {
    case 0:
      lua_pushlstring(L, s: "nil", len: 3u);
      result = 1;
      break;
    case 1:
      v3 = !lua_toboolean(L, idx: 1);
      v4 = "true";
      if ( v3 )
        v4 = "false";
      lua_pushstring(L, s: v4);
      result = 1;
      break;
    case 3:
      v1 = lua_tolstring(L, idx: 1, len: nullptr);
      lua_pushstring(L, s: v1);
      result = 1;
      break;
    case 4:
      lua_pushvalue(L, idx: 1);
      result = 1;
      break;
    default:
      v7 = lua_topointer(L, idx: 1);
      v5 = lua_type(L, idx: 1);
      v6 = lua_typename(L, t: v5);
      lua_pushfstring(L, fmt: "%s: %p", v6, v7);
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484470
// Name: luaB_newproxy
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_newproxy(lua_State *L)
{
  BOOL v2; // edi

  lua_settop(L, idx: 1);
  lua_newuserdata(L, size: 0);
  if ( lua_toboolean(L, idx: 1) )
  {
    if ( lua_type(L, idx: 1) == 1 )
    {
      lua_createtable(L, narray: 0, nrec: 0);
      lua_pushvalue(L, idx: -1);
      lua_pushboolean(L, b: 1);
      lua_rawset(L, idx: -10003);
      lua_setmetatable(L, objindex: 2);
      return 1;
    }
    if ( lua_getmetatable(L, objindex: 1) == 0
      || (lua_rawget(L, idx: -10003), v2 = lua_toboolean(L, idx: -1), lua_settop(L, idx: -2), !v2) )
    {
      luaL_argerror(L, narg: 1, extramsg: "boolean or proxy expected");
    }
    lua_getmetatable(L, objindex: 1);
    lua_setmetatable(L, objindex: 2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00484550
// Name: auxresume
// Source: json
//------------------------------------------------------------------------------
int __usercall auxresume@<eax>(lua_State *L@<edi>, lua_State *co@<esi>, int narg)
{
  int v4; // ebx

  if ( lua_checkstack(L: co, size: narg) == 0 )
    luaL_error(L, fmt: "too many arguments to resume");
  if ( lua_status(L: co) != 0 || lua_gettop(L: co) != 0 )
  {
    lua_xmove(from: L, to: co, n: narg);
    if ( (unsigned int)lua_resume(L: co, nargs: narg) < 2 )
    {
      v4 = lua_gettop(L: co);
      if ( lua_checkstack(L, size: v4) == 0 )
        luaL_error(L, fmt: "too many results to resume");
      lua_xmove(from: co, to: L, n: v4);
      return v4;
    }
    else
    {
      lua_xmove(from: co, to: L, n: 1);
      return -1;
    }
  }
  else
  {
    lua_pushlstring(L, s: "cannot resume dead coroutine", len: 0x1Cu);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484610
// Name: luaB_coresume
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_coresume(lua_State *L)
{
  lua_State *v1; // esi
  int v2; // eax
  int v3; // esi

  v1 = lua_tothread(L, idx: 1);
  if ( v1 == nullptr )
    luaL_argerror(L, narg: 1, extramsg: "coroutine expected");
  v2 = lua_gettop(L);
  v3 = auxresume(L, co: v1, narg: v2 - 1);
  if ( v3 >= 0 )
  {
    lua_pushboolean(L, b: 1);
    lua_insert(L, idx: -1 - v3);
    return v3 + 1;
  }
  else
  {
    lua_pushboolean(L, b: 0);
    lua_insert(L, idx: -2);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484690
// Name: luaB_auxwrap
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_auxwrap(lua_State *L)
{
  lua_State *v1; // esi
  int v2; // eax
  int result; // eax

  v1 = lua_tothread(L, idx: -10003);
  v2 = lua_gettop(L);
  result = auxresume(L, co: v1, narg: v2);
  if ( result < 0 )
  {
    if ( lua_isstring(L, idx: -1) )
    {
      luaL_where(L, level: 1);
      lua_insert(L, idx: -2);
      lua_concat(L, n: 2);
    }
    lua_error(L);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484700
// Name: luaB_cocreate
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_cocreate(lua_State *L)
{
  lua_State *v1; // edi

  v1 = lua_newthread(L);
  if ( lua_type(L, idx: 1) != 6 || lua_iscfunction(L, idx: 1) )
    luaL_argerror(L, narg: 1, extramsg: "Lua function expected");
  lua_pushvalue(L, idx: 1);
  lua_xmove(from: L, to: v1, n: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00484760
// Name: luaB_cowrap
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_cowrap(lua_State *L)
{
  lua_State *v1; // edi

  v1 = lua_newthread(L);
  if ( lua_type(L, idx: 1) != 6 || lua_iscfunction(L, idx: 1) )
    luaL_argerror(L, narg: 1, extramsg: "Lua function expected");
  lua_pushvalue(L, idx: 1);
  lua_xmove(from: L, to: v1, n: 1);
  lua_pushcclosure(L, fn: luaB_auxwrap, n: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004847D0
// Name: luaB_yield
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_yield(lua_State *L)
{
  int v1; // eax

  v1 = lua_gettop(L);
  return lua_yield(L, nresults: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004847F0
// Name: luaB_costatus
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaB_costatus(lua_State *L)
{
  lua_State *v1; // eax
  lua_State *v2; // edi
  int v4; // eax
  lua_Debug ar; // [esp+8h] [ebp-64h] BYREF

  v1 = lua_tothread(L, idx: 1);
  v2 = v1;
  if ( v1 == nullptr )
    luaL_argerror(L, narg: 1, extramsg: "coroutine expected");
  if ( L == v1 )
  {
    lua_pushlstring(L, s: "running", len: 7u);
    return 1;
  }
  v4 = lua_status(L: v1);
  if ( v4 != 0 )
  {
    if ( v4 != 1 )
    {
LABEL_7:
      lua_pushlstring(L, s: "dead", len: 4u);
      return 1;
    }
  }
  else
  {
    if ( lua_getstack(L: v2, level: 0, &ar) > 0 )
    {
      lua_pushlstring(L, s: "normal", len: 6u);
      return 1;
    }
    if ( lua_gettop(L: v2) == 0 )
      goto LABEL_7;
  }
  lua_pushlstring(L, s: "suspended", len: 9u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004848C0
// Name: luaB_corunning
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl luaB_corunning(lua_State *L)
{
  return !lua_pushthread(L);
}

//------------------------------------------------------------------------------
// Address: 0x004848E0
// Name: base_open
// Source: json
//------------------------------------------------------------------------------
void __usercall base_open(lua_State *L@<esi>)
{
  lua_pushvalue(L, idx: -10002);
  lua_setfield(L, idx: -10002, k: "_G");
  luaL_register(L, libname: "_G", l: base_funcs);
  lua_pushlstring(L, s: "Lua 5.1", len: 7u);
  lua_setfield(L, idx: -10002, k: "_VERSION");
  lua_pushcclosure(L, fn: ipairsaux, n: 0);
  lua_pushcclosure(L, fn: luaB_ipairs, n: 1);
  lua_setfield(L, idx: -2, k: "ipairs");
  lua_pushcclosure(L, fn: luaB_next, n: 0);
  lua_pushcclosure(L, fn: luaB_pairs, n: 1);
  lua_setfield(L, idx: -2, k: "pairs");
  lua_createtable(L, narray: 0, nrec: 1);
  lua_pushvalue(L, idx: -1);
  lua_setmetatable(L, objindex: -2);
  lua_pushlstring(L, s: "kv", len: 2u);
  lua_setfield(L, idx: -2, k: "__mode");
  lua_pushcclosure(L, fn: luaB_newproxy, n: 1);
  lua_setfield(L, idx: -10002, k: "newproxy");
}

//------------------------------------------------------------------------------
// Address: 0x004849E0
// Name: int luaopen_base(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_base(lua_State *L)
{
  base_open(L);
  luaL_register(L, libname: "coroutine", l: co_funcs);
  return 2;
}
