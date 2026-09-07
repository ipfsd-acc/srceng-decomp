// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ldblib.c
// Functions: 18
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047D790
// Name: db_getregistry
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getregistry(lua_State *L)
{
  lua_pushvalue(L, idx: -10000);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D7B0
// Name: db_getmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getmetatable(lua_State *L)
{
  luaL_checkany(L, narg: 1);
  if ( lua_getmetatable(L, objindex: 1) == 0 )
    lua_pushnil(L);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D7E0
// Name: db_setmetatable
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setmetatable(lua_State *L)
{
  int v1; // eax
  int v2; // eax

  v1 = lua_type(L, idx: 2);
  if ( v1 != 0 && v1 != 5 )
    luaL_argerror(L, narg: 2, extramsg: "nil or table expected");
  lua_settop(L, idx: 2);
  v2 = lua_setmetatable(L, objindex: 1);
  lua_pushboolean(L, b: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D830
// Name: db_getfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getfenv(lua_State *L)
{
  lua_getfenv(L, idx: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D850
// Name: db_setfenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setfenv(lua_State *L)
{
  luaL_checktype(L, narg: 2, t: 5);
  lua_settop(L, idx: 2);
  if ( lua_setfenv(L, idx: 1) == 0 )
    luaL_error(L, fmt: "'setfenv' cannot change environment of given object");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D890
// Name: treatstackoption
// Source: json
//------------------------------------------------------------------------------
void __usercall treatstackoption(lua_State *L@<esi>, lua_State *L1@<eax>, const char *fname)
{
  if ( L == L1 )
  {
    lua_pushvalue(L, idx: -2);
    lua_remove(L, idx: -3);
  }
  else
  {
    lua_xmove(from: L1, to: L, n: 1);
  }
  lua_setfield(L, idx: -2, k: fname);
}

//------------------------------------------------------------------------------
// Address: 0x0047D8E0
// Name: db_getinfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getinfo(lua_State *L)
{
  int v1; // edi
  const char *v2; // eax
  int v3; // edi
  char *v4; // ebx
  lua_TValue *v5; // eax
  lua_State *v6; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  lua_Debug ar; // [esp+Ch] [ebp-6Ch] BYREF
  int narg; // [esp+70h] [ebp-8h]
  lua_State *L1; // [esp+74h] [ebp-4h]

  if ( lua_type(L, idx: 1) == 8 )
  {
    v1 = 1;
    L1 = lua_tothread(L, idx: 1);
  }
  else
  {
    v1 = 0;
    L1 = L;
  }
  narg = v1 + 2;
  v2 = luaL_optlstring(L, narg: v1 + 2, def: "flnSu", len: nullptr);
  v3 = v1 + 1;
  v4 = (char *)v2;
  if ( lua_isnumber(L, idx: v3) != 0 )
  {
    v5 = lua_tointeger(L, idx: v3);
    v6 = L1;
    if ( lua_getstack(L: L1, level: (int)v5, &ar) == 0 )
    {
      lua_pushnil(L);
      return 1;
    }
  }
  else
  {
    if ( lua_type(L, idx: v3) != 6 )
      luaL_argerror(L, narg: v3, extramsg: "function or level expected");
    lua_pushfstring(L, fmt: ">%s", v4);
    v4 = (char *)lua_tolstring(L, idx: -1, len: nullptr);
    lua_pushvalue(L, idx: v3);
    lua_xmove(from: L, to: L1, n: 1);
    v6 = L1;
  }
  if ( lua_getinfo(L: v6, what: v4, &ar) == 0 )
    luaL_argerror(L, narg, extramsg: "invalid option");
  lua_createtable(L, narray: 0, nrec: 2);
  strchr(string: (unsigned __int8 *)v4, chr: 0x53u);
  if ( v8 != 0 )
  {
    lua_pushstring(L, s: ar.source);
    lua_setfield(L, idx: -2, k: "source");
    lua_pushstring(L, s: ar.short_src);
    lua_setfield(L, idx: -2, k: "short_src");
    lua_pushinteger(L, n: ar.linedefined);
    lua_setfield(L, idx: -2, k: "linedefined");
    lua_pushinteger(L, n: ar.lastlinedefined);
    lua_setfield(L, idx: -2, k: "lastlinedefined");
    lua_pushstring(L, s: ar.what);
    lua_setfield(L, idx: -2, k: "what");
  }
  strchr(string: (unsigned __int8 *)v4, chr: 0x6Cu);
  if ( v9 != 0 )
  {
    lua_pushinteger(L, n: ar.currentline);
    lua_setfield(L, idx: -2, k: "currentline");
  }
  strchr(string: (unsigned __int8 *)v4, chr: 0x75u);
  if ( v10 != 0 )
  {
    lua_pushinteger(L, n: ar.nups);
    lua_setfield(L, idx: -2, k: "nups");
  }
  strchr(string: (unsigned __int8 *)v4, chr: 0x6Eu);
  if ( v11 != 0 )
  {
    lua_pushstring(L, s: ar.name);
    lua_setfield(L, idx: -2, k: "name");
    lua_pushstring(L, s: ar.namewhat);
    lua_setfield(L, idx: -2, k: "namewhat");
  }
  strchr(string: (unsigned __int8 *)v4, chr: 0x4Cu);
  if ( v12 != 0 )
    treatstackoption(L, L1: v6, fname: "activelines");
  strchr(string: (unsigned __int8 *)v4, chr: 0x66u);
  if ( v13 != 0 )
    treatstackoption(L, L1: v6, fname: "func");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047DB60
// Name: db_getlocal
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getlocal(lua_State *L)
{
  int v1; // ebx
  lua_State *v2; // edi
  lua_TValue *v3; // eax
  lua_TValue *v4; // eax
  const char *v5; // ebx
  lua_Debug ar; // [esp+Ch] [ebp-68h] BYREF
  int narg; // [esp+70h] [ebp-4h]

  if ( lua_type(L, idx: 1) == 8 )
  {
    v1 = 1;
    v2 = lua_tothread(L, idx: 1);
  }
  else
  {
    v1 = 0;
    v2 = L;
  }
  narg = v1 + 1;
  v3 = luaL_checkinteger(L, narg: v1 + 1);
  if ( lua_getstack(L: v2, level: (int)v3, &ar) == 0 )
    luaL_argerror(L, narg, extramsg: "level out of range");
  v4 = luaL_checkinteger(L, narg: v1 + 2);
  v5 = lua_getlocal(L: v2, (CallInfo *)&ar, n: (int)v4);
  if ( v5 != nullptr )
  {
    lua_xmove(from: v2, to: L, n: 1);
    lua_pushstring(L, s: v5);
    lua_pushvalue(L, idx: -2);
    return 2;
  }
  else
  {
    lua_pushnil(L);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DC30
// Name: db_setlocal
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setlocal(lua_State *L)
{
  int v1; // edi
  lua_State *v2; // ebx
  lua_TValue *v3; // eax
  lua_TValue *v4; // eax
  const char *v5; // eax
  lua_Debug ar; // [esp+Ch] [ebp-68h] BYREF
  int narg; // [esp+70h] [ebp-4h]

  if ( lua_type(L, idx: 1) == 8 )
  {
    v1 = 1;
    v2 = lua_tothread(L, idx: 1);
  }
  else
  {
    v1 = 0;
    v2 = L;
  }
  narg = v1 + 1;
  v3 = luaL_checkinteger(L, narg: v1 + 1);
  if ( lua_getstack(L: v2, level: (int)v3, &ar) == 0 )
    luaL_argerror(L, narg, extramsg: "level out of range");
  luaL_checkany(L, narg: v1 + 3);
  lua_settop(L, idx: v1 + 3);
  lua_xmove(from: L, to: v2, n: 1);
  v4 = luaL_checkinteger(L, narg: v1 + 2);
  v5 = lua_setlocal(L: v2, &ar, n: (int)v4);
  lua_pushstring(L, s: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047DCF0
// Name: db_getupvalue
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_getupvalue(lua_State *L)
{
  lua_TValue *v1; // edi
  const char *v3; // eax

  v1 = luaL_checkinteger(L, narg: 2);
  luaL_checktype(L, narg: 1, t: 6);
  if ( lua_iscfunction(L, idx: 1) )
    return 0;
  v3 = lua_getupvalue(L, funcindex: 1, n: (int)v1);
  if ( v3 == nullptr )
    return 0;
  lua_pushstring(L, s: v3);
  lua_insert(L, idx: -2);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0047DD50
// Name: db_setupvalue
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_setupvalue(lua_State *L)
{
  lua_TValue *v1; // edi
  const char *v3; // eax

  luaL_checkany(L, narg: 3);
  v1 = luaL_checkinteger(L, narg: 2);
  luaL_checktype(L, narg: 1, t: 6);
  if ( lua_iscfunction(L, idx: 1) )
    return 0;
  v3 = lua_setupvalue(L, funcindex: 1, n: (int)v1);
  if ( v3 == nullptr )
    return 0;
  lua_pushstring(L, s: v3);
  lua_insert(L, idx: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047DDC0
// Name: hookf
// Source: json
//------------------------------------------------------------------------------
void __cdecl hookf(lua_State *L, lua_Debug *ar)
{
  int currentline; // eax

  lua_pushlightuserdata(L, p: (void *)&KEY_HOOK);
  lua_rawget(L, idx: -10000);
  lua_pushlightuserdata(L, p: L);
  lua_rawget(L, idx: -2);
  if ( lua_type(L, idx: -1) == 6 )
  {
    lua_pushstring(L, s: hooknames[ar->event]);
    currentline = ar->currentline;
    if ( currentline < 0 )
      lua_pushnil(L);
    else
      lua_pushinteger(L, n: currentline);
    lua_call(L, nargs: 2, nresults: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DE50
// Name: gethooktable
// Source: json
//------------------------------------------------------------------------------
void __usercall gethooktable(lua_State *L@<esi>)
{
  lua_pushlightuserdata(L, p: (void *)&KEY_HOOK);
  lua_rawget(L, idx: -10000);
  if ( lua_type(L, idx: -1) != 5 )
  {
    lua_settop(L, idx: -2);
    lua_createtable(L, narray: 0, nrec: 1);
    lua_pushlightuserdata(L, p: (void *)&KEY_HOOK);
    lua_pushvalue(L, idx: -2);
    lua_rawset(L, idx: -10000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DEB0
// Name: db_sethook
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_sethook(lua_State *L)
{
  int v1; // ebx
  lua_State *v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  lua_TValue *count; // [esp+Ch] [ebp-Ch]
  int idx; // [esp+10h] [ebp-8h]
  char *smask; // [esp+14h] [ebp-4h]

  if ( lua_type(L, idx: 1) == 8 )
  {
    v1 = 1;
    v2 = lua_tothread(L, idx: 1);
  }
  else
  {
    v1 = 0;
    v2 = L;
  }
  idx = v1 + 1;
  if ( lua_type(L, idx: v1 + 1) > 0 )
  {
    smask = (char *)luaL_checklstring(L, narg: v1 + 2, len: nullptr);
    count = luaL_optinteger(L, narg: v1 + 3, def: 0);
    luaL_checktype(L, narg: idx, t: 6);
    strchr(string: (unsigned __int8 *)smask, chr: 0x63u);
    v4 = v3 != 0;
    strchr(string: (unsigned __int8 *)smask, chr: 0x72u);
    if ( v5 != 0 )
      v4 |= 2u;
    strchr(string: (unsigned __int8 *)smask, chr: 0x6Cu);
    if ( v6 != 0 )
      v4 |= 4u;
    if ( (int)count > 0 )
      v4 |= 8u;
    lua_sethook(L: v2, func: hookf, mask: v4, (int)count);
  }
  else
  {
    lua_settop(L, idx);
    lua_sethook(L: v2, func: nullptr, mask: 0, count: 0);
  }
  gethooktable(L: v2);
  lua_pushlightuserdata(L: v2, p: v2);
  lua_pushvalue(L, idx);
  lua_xmove(from: L, to: v2, n: 1);
  lua_rawset(L: v2, idx: -3);
  lua_settop(L: v2, idx: -2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047DFE0
// Name: db_gethook
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_gethook(lua_State *L)
{
  lua_State *v1; // esi
  char v2; // bl
  void (__cdecl *v3)(lua_State *, lua_Debug *); // eax
  int v4; // eax
  int v5; // eax
  char buff[8]; // [esp+8h] [ebp-8h] BYREF

  if ( lua_type(L, idx: 1) == 8 )
    v1 = lua_tothread(L, idx: 1);
  else
    v1 = L;
  v2 = lua_gethookmask(L: v1);
  v3 = lua_gethook(L: v1);
  if ( v3 == nullptr || v3 == hookf )
  {
    gethooktable(L: v1);
    lua_pushlightuserdata(L: v1, p: v1);
    lua_rawget(L: v1, idx: -2);
    lua_remove(L: v1, idx: -2);
    lua_xmove(from: v1, to: L, n: 1);
  }
  else
  {
    lua_pushlstring(L, s: "external hook", len: 0xDu);
  }
  v4 = 0;
  if ( (v2 & 1) != 0 )
  {
    buff[0] = 99;
    v4 = 1;
  }
  if ( (v2 & 2) != 0 )
    buff[v4++] = 114;
  if ( (v2 & 4) != 0 )
    buff[v4++] = 108;
  buff[v4] = 0;
  lua_pushstring(L, s: buff);
  v5 = lua_gethookcount(L: v1);
  lua_pushinteger(L, n: v5);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0047E0C0
// Name: db_debug
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_debug(lua_State *L)
{
  _iobuf *v1; // eax
  _iobuf *v2; // eax
  const char *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v8; // [esp-8h] [ebp-104h]
  char buffer[252]; // [esp+0h] [ebp-FCh] BYREF

  v1 = __iob_func();
  fputs(string: "lua_debug> ", stream: v1 + 2);
  v2 = __iob_func();
  if ( fgets(string: buffer, count: 250, str: v2) == nullptr )
    return 0;
  do
  {
    if ( strcmp(buffer, "cont\n") == 0 )
      break;
    if ( luaL_loadbuffer(L, buff: buffer, size: strlen(buffer), name: "=(debug command)") != 0
      || lua_pcall(L, nargs: 0, nresults: 0, errfunc: 0) != 0 )
    {
      v8 = __iob_func() + 2;
      v3 = lua_tolstring(L, idx: -1, len: nullptr);
      fputs(string: v3, stream: v8);
      v4 = __iob_func();
      fputs(string: "\n", stream: v4 + 2);
    }
    lua_settop(L, idx: 0);
    v5 = __iob_func();
    fputs(string: "lua_debug> ", stream: v5 + 2);
    v6 = __iob_func();
  }
  while ( fgets(string: buffer, count: 250, str: v6) != nullptr );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047E200
// Name: db_errorfb
// Source: json
//------------------------------------------------------------------------------
int __cdecl db_errorfb(lua_State *L)
{
  lua_State *v1; // ebx
  lua_TValue *v2; // edi
  int v3; // edi
  char v4; // al
  int v5; // eax
  int v6; // eax
  lua_Debug ar; // [esp+Ch] [ebp-70h] BYREF
  int firstpart; // [esp+70h] [ebp-Ch]
  int arg; // [esp+74h] [ebp-8h]
  int level; // [esp+78h] [ebp-4h]

  firstpart = 1;
  if ( lua_type(L, idx: 1) == 8 )
  {
    arg = 1;
    v1 = lua_tothread(L, idx: 1);
  }
  else
  {
    arg = 0;
    v1 = L;
  }
  if ( lua_isnumber(L, idx: arg + 2) != 0 )
  {
    v2 = lua_tointeger(L, idx: arg + 2);
    lua_settop(L, idx: -2);
  }
  else
  {
    level = L == v1;
    v2 = (lua_TValue *)level;
  }
  if ( lua_gettop(L) == arg )
  {
    lua_pushlstring(L, s: var, len: 0);
  }
  else
  {
    if ( !lua_isstring(L, idx: arg + 1) )
      return 1;
    lua_pushlstring(L, s: "\n", len: 1u);
  }
  lua_pushlstring(L, s: "stack traceback:", len: 0x10u);
  while ( lua_getstack(L: v1, level: (int)v2, &ar) != 0 )
  {
    v2 = (lua_TValue *)((char *)v2 + 1);
    level = (int)v2;
    if ( (int)v2 > 12 && firstpart != 0 )
    {
      v3 = (int)&v2->tt + 2;
      if ( lua_getstack(L: v1, level: v3, &ar) != 0 )
      {
        lua_pushlstring(L, s: "\n\t...", len: 5u);
        if ( lua_getstack(L: v1, level: v3, &ar) != 0 )
        {
          do
            ++level;
          while ( lua_getstack(L: v1, level: level + 10, &ar) != 0 );
        }
        v2 = (lua_TValue *)level;
        firstpart = 0;
      }
      else
      {
        v2 = (lua_TValue *)--level;
        firstpart = 0;
      }
    }
    else
    {
      lua_pushlstring(L, s: "\n\t", len: 2u);
      lua_getinfo(L: v1, what: "Snl", &ar);
      lua_pushfstring(L, fmt: "%s:", ar.short_src);
      if ( ar.currentline > 0 )
        lua_pushfstring(L, fmt: "%d:", ar.currentline);
      if ( *ar.namewhat != 0 )
      {
        lua_pushfstring(L, fmt: " in function '%s'", ar.name);
      }
      else
      {
        v4 = *ar.what;
        if ( *ar.what == 109 )
        {
          lua_pushfstring(L, fmt: " in main chunk");
        }
        else if ( v4 == 67 || v4 == 116 )
        {
          lua_pushlstring(L, s: " ?", len: 2u);
        }
        else
        {
          lua_pushfstring(L, fmt: " in function <%s:%d>", ar.short_src, ar.linedefined);
        }
      }
      v5 = lua_gettop(L);
      lua_concat(L, n: v5 - arg);
    }
  }
  v6 = lua_gettop(L);
  lua_concat(L, n: v6 - arg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E440
// Name: int luaopen_debug(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_debug(lua_State *L)
{
  luaL_register(L, libname: "debug", l: dblib);
  return 1;
}
