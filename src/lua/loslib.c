// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/loslib.c
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00480930
// Name: os_execute
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_execute(lua_State *L)
{
  const char *v1; // eax
  int v2; // eax

  v1 = luaL_optlstring(L, narg: 1, def: nullptr, len: nullptr);
  v2 = system(command: v1);
  lua_pushinteger(L, n: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480960
// Name: os_remove
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_remove(lua_State *L)
{
  const char *v1; // ebx
  int v2; // esi
  const char *v4; // eax
  int errnum; // [esp+Ch] [ebp-4h]

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = -(remove(path: v1) != 0);
  errnum = *_errno();
  if ( v2 == -1 )
  {
    lua_pushnil(L);
    v4 = strerror(errnum);
    lua_pushfstring(L, fmt: "%s: %s", v1, v4);
    lua_pushinteger(L, n: errnum);
    return 3;
  }
  else
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004809E0
// Name: os_rename
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_rename(lua_State *L)
{
  const char *v1; // ebx
  const char *v2; // eax
  int v3; // esi
  const char *v5; // eax
  int errnum; // [esp+Ch] [ebp-4h]

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = luaL_checklstring(L, narg: 2, len: nullptr);
  v3 = -(rename(oldname: v1, newname: v2) != 0);
  errnum = *_errno();
  if ( v3 == -1 )
  {
    lua_pushnil(L);
    v5 = strerror(errnum);
    lua_pushfstring(L, fmt: "%s: %s", v1, v5);
    lua_pushinteger(L, n: errnum);
    return 3;
  }
  else
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480A70
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
// Address: 0x00480AC0
// Name: os_getenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_getenv(lua_State *L)
{
  const char *v1; // eax
  const char *v2; // eax

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = getenv(option: v1);
  lua_pushstring(L, s: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480AF0
// Name: os_clock
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_clock(lua_State *L)
{
  int v1; // eax

  v1 = clock();
  lua_pushnumber(L, n: (double)v1 * 0.001);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480B30
// Name: os_date
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_date(lua_State *L)
{
  const char *v1; // ebx
  __int64 v2; // rax
  tm *v3; // eax
  const tm *v4; // edi
  int tm_isdst; // edi
  char b[256]; // [esp+Ch] [ebp-108h] BYREF
  __int64 t; // [esp+10Ch] [ebp-8h] BYREF

  v1 = luaL_optlstring(L, narg: 1, def: "%c", len: nullptr);
  if ( lua_type(L, idx: 2) > 0 )
    v2 = (unsigned __int64)luaL_checknumber(L, narg: 2);
  else
    v2 = _time64(timeptr: nullptr);
  t = v2;
  if ( *v1 == 33 )
  {
    v3 = _gmtime64(timp: &t);
    ++v1;
  }
  else
  {
    v3 = _localtime64(ptime: &t);
  }
  v4 = v3;
  if ( v3 == nullptr )
  {
    lua_pushnil(L);
    return 1;
  }
  if ( strcmp(v1, "*t") == 0 )
  {
    lua_createtable(L, narray: 0, nrec: 9);
    lua_pushinteger(L, n: v4->tm_sec);
    lua_setfield(L, idx: -2, k: "sec");
    lua_pushinteger(L, n: v4->tm_min);
    lua_setfield(L, idx: -2, k: "min");
    lua_pushinteger(L, n: v4->tm_hour);
    lua_setfield(L, idx: -2, k: "hour");
    lua_pushinteger(L, n: v4->tm_mday);
    lua_setfield(L, idx: -2, k: "day");
    lua_pushinteger(L, n: v4->tm_mon + 1);
    lua_setfield(L, idx: -2, k: "month");
    lua_pushinteger(L, n: v4->tm_year + 1900);
    lua_setfield(L, idx: -2, k: "year");
    lua_pushinteger(L, n: v4->tm_wday + 1);
    lua_setfield(L, idx: -2, k: "wday");
    lua_pushinteger(L, n: v4->tm_yday + 1);
    lua_setfield(L, idx: -2, k: "yday");
    tm_isdst = v4->tm_isdst;
    if ( tm_isdst >= 0 )
    {
      lua_pushboolean(L, b: tm_isdst);
      lua_setfield(L, idx: -2, k: "isdst");
      return 1;
    }
  }
  else
  {
    if ( strftime(string: b, maxsize: 0x100u, format: v1, timeptr: v4) == 0 )
      luaL_error(L, fmt: "'date' format too long");
    lua_pushstring(L, s: b);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480D40
// Name: os_time
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_time(lua_State *L)
{
  __int64 v1; // rax
  lua_TValue *v2; // edi
  lua_TValue *v3; // edi
  int v4; // edi
  lua_TValue *v5; // edi
  lua_TValue *v6; // edi
  lua_TValue *v7; // edi
  int v8; // edi
  tm ts; // [esp+Ch] [ebp-2Ch] BYREF
  __int64 t; // [esp+30h] [ebp-8h]

  if ( lua_type(L, idx: 1) > 0 )
  {
    luaL_checktype(L, narg: 1, t: 5);
    lua_settop(L, idx: 1);
    lua_getfield(L, idx: -1, k: "sec");
    if ( lua_isnumber(L, idx: -1) != 0 )
      v2 = lua_tointeger(L, idx: -1);
    else
      v2 = nullptr;
    lua_settop(L, idx: -2);
    ts.tm_sec = (int)v2;
    lua_getfield(L, idx: -1, k: "min");
    if ( lua_isnumber(L, idx: -1) != 0 )
      v3 = lua_tointeger(L, idx: -1);
    else
      v3 = nullptr;
    lua_settop(L, idx: -2);
    ts.tm_min = (int)v3;
    lua_getfield(L, idx: -1, k: "hour");
    if ( lua_isnumber(L, idx: -1) != 0 )
      v4 = (int)lua_tointeger(L, idx: -1);
    else
      v4 = 12;
    lua_settop(L, idx: -2);
    ts.tm_hour = v4;
    lua_getfield(L, idx: -1, k: "day");
    if ( lua_isnumber(L, idx: -1) == 0 )
      luaL_error(L, fmt: "field '%s' missing in date table", "day");
    v5 = lua_tointeger(L, idx: -1);
    lua_settop(L, idx: -2);
    ts.tm_mday = (int)v5;
    lua_getfield(L, idx: -1, k: "month");
    if ( lua_isnumber(L, idx: -1) == 0 )
      luaL_error(L, fmt: "field '%s' missing in date table", "month");
    v6 = lua_tointeger(L, idx: -1);
    lua_settop(L, idx: -2);
    ts.tm_mon = (int)&v6[-1].tt + 7;
    lua_getfield(L, idx: -1, k: "year");
    if ( lua_isnumber(L, idx: -1) == 0 )
      luaL_error(L, fmt: "field '%s' missing in date table", "year");
    v7 = lua_tointeger(L, idx: -1);
    lua_settop(L, idx: -2);
    ts.tm_year = (int)(&v7[-119].value.b + 1);
    lua_getfield(L, idx: -1, k: "isdst");
    if ( lua_type(L, idx: -1) != 0 )
      v8 = lua_toboolean(L, idx: -1);
    else
      v8 = -1;
    lua_settop(L, idx: -2);
    ts.tm_isdst = v8;
    v1 = _mktime64(tb: &ts);
  }
  else
  {
    v1 = _time64(timeptr: nullptr);
  }
  t = v1;
  if ( (HIDWORD(v1) & (unsigned int)v1) == 0xFFFFFFFF )
    lua_pushnil(L);
  else
    lua_pushnumber(L, n: (double)t);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480F90
// Name: os_difftime
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_difftime(lua_State *L)
{
  __int64 v1; // kr00_8
  __int64 v2; // rax
  long double v3; // st7

  v1 = (unsigned __int64)luaL_optnumber(L, narg: 2, def: 0.0);
  v2 = (unsigned __int64)luaL_checknumber(L, narg: 1);
  v3 = _difftime64(b: v2, a: v1);
  lua_pushnumber(L, n: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00480FF0
// Name: os_setlocale
// Source: json
//------------------------------------------------------------------------------
int __cdecl os_setlocale(lua_State *L)
{
  const char *v1; // edi
  int v2; // eax
  const char *v3; // eax

  v1 = luaL_optlstring(L, narg: 1, def: nullptr, len: nullptr);
  v2 = luaL_checkoption(L, narg: 2, def: "all", lst: (const char **)catnames);
  v3 = setlocale(_category: cat[v2], _locale: v1);
  lua_pushstring(L, s: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00481040
// Name: os_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn os_exit(lua_State *L)
{
  lua_TValue *v1; // eax

  v1 = luaL_optinteger(L, narg: 1, def: 0);
  exit(code: (int)v1);
}

//------------------------------------------------------------------------------
// Address: 0x00481060
// Name: int luaopen_os(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_os(lua_State *L)
{
  luaL_register(L, libname: "os", l: syslib);
  return 1;
}
