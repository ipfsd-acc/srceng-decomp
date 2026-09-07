// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ltablib.c
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004822F0
// Name: foreachi
// Source: json
//------------------------------------------------------------------------------
int __cdecl foreachi(lua_State *L)
{
  int v1; // ebx
  int v2; // edi

  luaL_checktype(L, narg: 1, t: 5);
  v1 = lua_objlen(L, idx: 1);
  luaL_checktype(L, narg: 2, t: 6);
  v2 = 1;
  if ( v1 < 1 )
    return 0;
  while ( 1 )
  {
    lua_pushvalue(L, idx: 2);
    lua_pushinteger(L, n: v2);
    lua_rawgeti(L, idx: 1, n: v2);
    lua_call(L, nargs: 2, nresults: 1);
    if ( lua_type(L, idx: -1) != 0 )
      break;
    lua_settop(L, idx: -2);
    if ( ++v2 > v1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00482380
// Name: foreach
// Source: json
//------------------------------------------------------------------------------
int __cdecl foreach(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  luaL_checktype(L, narg: 2, t: 6);
  lua_pushnil(L);
  if ( lua_next(L, idx: 1) == 0 )
    return 0;
  while ( 1 )
  {
    lua_pushvalue(L, idx: 2);
    lua_pushvalue(L, idx: -3);
    lua_pushvalue(L, idx: -3);
    lua_call(L, nargs: 2, nresults: 1);
    if ( lua_type(L, idx: -1) != 0 )
      break;
    lua_settop(L, idx: -3);
    if ( lua_next(L, idx: 1) == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00482410
// Name: maxn
// Source: json
//------------------------------------------------------------------------------
int __cdecl maxn(lua_State *L)
{
  double v; // [esp+Ch] [ebp-10h]
  double max; // [esp+14h] [ebp-8h]

  max = 0.0;
  luaL_checktype(L, narg: 1, t: 5);
  lua_pushnil(L);
  while ( lua_next(L, idx: 1) != 0 )
  {
    lua_settop(L, idx: -2);
    if ( lua_type(L, idx: -1) == 3 )
    {
      v = lua_tonumber(L, idx: -1);
      if ( v > max )
        max = v;
    }
  }
  lua_pushnumber(L, n: max);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004824B0
// Name: getn
// Source: json
//------------------------------------------------------------------------------
int __cdecl getn(lua_State *L)
{
  int v1; // eax

  luaL_checktype(L, narg: 1, t: 5);
  v1 = lua_objlen(L, idx: 1);
  lua_pushinteger(L, n: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004824E0
// Name: setn
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn setn(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  luaL_error(L, fmt: "'setn' is obsolete");
}

//------------------------------------------------------------------------------
// Address: 0x00482510
// Name: tinsert
// Source: json
//------------------------------------------------------------------------------
int __cdecl tinsert(lua_State *L)
{
  int v1; // esi
  int v2; // eax
  lua_TValue *v3; // eax
  int pos; // [esp+8h] [ebp-4h]

  luaL_checktype(L, narg: 1, t: 5);
  v1 = lua_objlen(L, idx: 1) + 1;
  v2 = lua_gettop(L) - 2;
  if ( v2 == 0 )
  {
    v3 = (lua_TValue *)v1;
LABEL_10:
    lua_rawseti(L, idx: 1, n: (int)v3);
    return 0;
  }
  if ( v2 != 1 )
    luaL_error(L, fmt: "wrong number of arguments to 'insert'");
  v3 = luaL_checkinteger(L, narg: 2);
  if ( (int)v3 > v1 )
    v1 = (int)v3;
  pos = (int)v3;
  if ( v1 <= (int)v3 )
    goto LABEL_10;
  do
  {
    lua_rawgeti(L, idx: 1, n: v1 - 1);
    lua_rawseti(L, idx: 1, n: v1--);
  }
  while ( v1 > pos );
  lua_rawseti(L, idx: 1, n: pos);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004825C0
// Name: tremove
// Source: json
//------------------------------------------------------------------------------
int __cdecl tremove(lua_State *L)
{
  int v1; // ebx
  lua_TValue *v2; // eax
  int v3; // esi

  luaL_checktype(L, narg: 1, t: 5);
  v1 = lua_objlen(L, idx: 1);
  v2 = luaL_optinteger(L, narg: 2, def: v1);
  v3 = (int)v2;
  if ( v1 == 0 )
    return 0;
  lua_rawgeti(L, idx: 1, n: (int)v2);
  for ( ; v3 < v1; ++v3 )
  {
    lua_rawgeti(L, idx: 1, n: v3 + 1);
    lua_rawseti(L, idx: 1, n: v3);
  }
  lua_pushnil(L);
  lua_rawseti(L, idx: 1, n: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00482650
// Name: tconcat
// Source: json
//------------------------------------------------------------------------------
int __cdecl tconcat(lua_State *L)
{
  lua_TValue *v1; // edi
  lua_TValue *v2; // eax
  lua_TValue *v3; // ebx
  luaL_Buffer b; // [esp+Ch] [ebp-214h] BYREF
  unsigned int lsep; // [esp+218h] [ebp-8h] BYREF
  const char *sep; // [esp+21Ch] [ebp-4h]

  sep = luaL_optlstring(L, narg: 2, def: var, len: &lsep);
  luaL_checktype(L, narg: 1, t: 5);
  v1 = luaL_optinteger(L, narg: 3, def: 1);
  if ( lua_type(L, idx: 4) > 0 )
    v2 = luaL_checkinteger(L, narg: 4);
  else
    v2 = (lua_TValue *)lua_objlen(L, idx: 1);
  v3 = v2;
  luaL_buffinit(L, B: &b);
  for ( ; (int)v1 <= (int)v3; v1 = (lua_TValue *)((char *)v1 + 1) )
  {
    lua_rawgeti(L, idx: 1, n: (int)v1);
    if ( !lua_isstring(L, idx: -1) )
      luaL_argerror(L, narg: 1, extramsg: "table contains non-strings");
    luaL_addvalue(B: (unsigned int)&b);
    if ( v1 != v3 )
      luaL_addlstring(B: &b, s: sep, l: lsep);
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00482740
// Name: auxsort
// Source: json
//------------------------------------------------------------------------------
void __cdecl auxsort(lua_State *L, int l, int u)
{
  int v3; // ebx
  int v4; // edi
  BOOL v5; // edi
  int v6; // eax
  int v7; // edi
  int v8; // eax
  BOOL v9; // ebx
  int v10; // eax
  int v11; // ebx
  int v12; // ebx
  int v13; // edi
  BOOL v14; // edi
  int v15; // eax
  BOOL v16; // edi
  int v17; // eax
  int v18; // edi
  int v19; // ebx
  int v20; // eax
  int v21; // edx
  int v22; // [esp+8h] [ebp-8h]
  BOOL ja; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]

  v3 = u;
  v4 = l;
  if ( l < u )
  {
    while ( 1 )
    {
      lua_rawgeti(L, idx: 1, n: v4);
      lua_rawgeti(L, idx: 1, n: v3);
      if ( lua_type(L, idx: 2) != 0 )
      {
        lua_pushvalue(L, idx: 2);
        lua_pushvalue(L, idx: -2);
        lua_pushvalue(L, idx: -4);
        lua_call(L, nargs: 2, nresults: 1);
        v5 = lua_toboolean(L, idx: -1);
        lua_settop(L, idx: -2);
        v6 = v5;
        v4 = l;
      }
      else
      {
        v6 = lua_lessthan(L, index1: -1, index2: -2);
      }
      if ( v6 != 0 )
      {
        lua_rawseti(L, idx: 1, n: v4);
        lua_rawseti(L, idx: 1, n: v3);
      }
      else
      {
        lua_settop(L, idx: -3);
      }
      v22 = v3 - v4;
      if ( v3 - v4 == 1 )
        break;
      v7 = (v4 + v3) / 2;
      lua_rawgeti(L, idx: 1, n: v7);
      lua_rawgeti(L, idx: 1, n: l);
      if ( lua_type(L, idx: 2) != 0 )
      {
        lua_pushvalue(L, idx: 2);
        lua_pushvalue(L, idx: -3);
        lua_pushvalue(L, idx: -3);
        lua_call(L, nargs: 2, nresults: 1);
        ja = lua_toboolean(L, idx: -1);
        lua_settop(L, idx: -2);
        v8 = ja;
      }
      else
      {
        v8 = lua_lessthan(L, index1: -2, index2: -1);
      }
      if ( v8 != 0 )
      {
        lua_rawseti(L, idx: 1, n: v7);
        lua_rawseti(L, idx: 1, n: l);
      }
      else
      {
        lua_settop(L, idx: -2);
        lua_rawgeti(L, idx: 1, n: v3);
        if ( lua_type(L, idx: 2) != 0 )
        {
          lua_pushvalue(L, idx: 2);
          lua_pushvalue(L, idx: -2);
          lua_pushvalue(L, idx: -4);
          lua_call(L, nargs: 2, nresults: 1);
          v9 = lua_toboolean(L, idx: -1);
          lua_settop(L, idx: -2);
          v10 = v9;
          v3 = u;
        }
        else
        {
          v10 = lua_lessthan(L, index1: -1, index2: -2);
        }
        if ( v10 != 0 )
        {
          lua_rawseti(L, idx: 1, n: v7);
          lua_rawseti(L, idx: 1, n: v3);
        }
        else
        {
          lua_settop(L, idx: -3);
        }
      }
      if ( v22 == 2 )
        break;
      lua_rawgeti(L, idx: 1, n: v7);
      lua_pushvalue(L, idx: -1);
      v11 = v3 - 1;
      lua_rawgeti(L, idx: 1, n: v11);
      lua_rawseti(L, idx: 1, n: v7);
      lua_rawseti(L, idx: 1, n: v11);
      v12 = l;
      v13 = u - 1;
      j = u - 1;
      while ( 1 )
      {
        while ( 1 )
        {
          lua_rawgeti(L, idx: 1, n: ++v12);
          if ( lua_type(L, idx: 2) != 0 )
          {
            lua_pushvalue(L, idx: 2);
            lua_pushvalue(L, idx: -2);
            lua_pushvalue(L, idx: -4);
            lua_call(L, nargs: 2, nresults: 1);
            v14 = lua_toboolean(L, idx: -1);
            lua_settop(L, idx: -2);
            v15 = v14;
            v13 = j;
          }
          else
          {
            v15 = lua_lessthan(L, index1: -1, index2: -2);
          }
          if ( v15 == 0 )
            break;
          if ( v12 > u )
            luaL_error(L, fmt: "invalid order function for sorting");
          lua_settop(L, idx: -2);
        }
        while ( 1 )
        {
          j = --v13;
          lua_rawgeti(L, idx: 1, n: v13);
          if ( lua_type(L, idx: 2) != 0 )
          {
            lua_pushvalue(L, idx: 2);
            lua_pushvalue(L, idx: -4);
            lua_pushvalue(L, idx: -3);
            lua_call(L, nargs: 2, nresults: 1);
            v16 = lua_toboolean(L, idx: -1);
            lua_settop(L, idx: -2);
            v17 = v16;
            v13 = j;
          }
          else
          {
            v17 = lua_lessthan(L, index1: -3, index2: -1);
          }
          if ( v17 == 0 )
            break;
          if ( v13 < l )
            luaL_error(L, fmt: "invalid order function for sorting");
          lua_settop(L, idx: -2);
        }
        if ( v13 < v12 )
          break;
        lua_rawseti(L, idx: 1, n: v12);
        lua_rawseti(L, idx: 1, n: v13);
      }
      lua_settop(L, idx: -4);
      lua_rawgeti(L, idx: 1, n: u - 1);
      lua_rawgeti(L, idx: 1, n: v12);
      lua_rawseti(L, idx: 1, n: u - 1);
      lua_rawseti(L, idx: 1, n: v12);
      v18 = l;
      if ( v12 - l >= u - v12 )
      {
        v20 = v12 + 1;
        v21 = v12 - 1;
        v19 = u;
        u = v21;
      }
      else
      {
        v19 = v12 - 1;
        v20 = l;
        l = v19 + 2;
        v18 = v19 + 2;
      }
      auxsort(L, l: v20, u: v19);
      if ( v18 >= u )
        break;
      v3 = u;
      v4 = l;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482B30
// Name: sort
// Source: json
//------------------------------------------------------------------------------
int __cdecl sort(lua_State *L)
{
  int v1; // edi

  luaL_checktype(L, narg: 1, t: 5);
  v1 = lua_objlen(L, idx: 1);
  luaL_checkstack(L, space: 40, mes: var);
  if ( lua_type(L, idx: 2) > 0 )
    luaL_checktype(L, narg: 2, t: 6);
  lua_settop(L, idx: 2);
  auxsort(L, l: 1, u: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00482B90
// Name: int luaopen_table(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_table(lua_State *L)
{
  luaL_register(L, libname: "table", l: tab_funcs);
  return 1;
}
