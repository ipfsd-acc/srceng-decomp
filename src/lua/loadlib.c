// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/loadlib.c
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00482BB0
// Name: setprogdir
// Source: json
//------------------------------------------------------------------------------
void __usercall setprogdir(lua_State *L@<esi>)
{
  DWORD ModuleFileNameA; // eax
  _BYTE *v2; // eax
  char *v3; // eax
  char buff[264]; // [esp+0h] [ebp-108h] BYREF

  ModuleFileNameA = GetModuleFileNameA(hModule: nullptr, lpFilename: buff, nSize: 0x105u);
  if ( ModuleFileNameA == 0
    || ModuleFileNameA == 261
    || (strrchr(string: (unsigned __int8 *)buff, chr: 0x5Cu), v2 == nullptr) )
  {
    luaL_error(L, fmt: "unable to get ModuleFileName");
  }
  *v2 = 0;
  v3 = (char *)lua_tolstring(L, idx: -1, len: nullptr);
  luaL_gsub(L, s: v3, p: "!", r: buff);
  lua_remove(L, idx: -2);
}

//------------------------------------------------------------------------------
// Address: 0x00482C40
// Name: pusherror
// Source: json
//------------------------------------------------------------------------------
void __usercall pusherror(lua_State *L@<edi>)
{
  DWORD LastError; // esi
  char buffer[128]; // [esp+4h] [ebp-80h] BYREF

  LastError = GetLastError();
  if ( FormatMessageA(
         dwFlags: 0x1200u,
         lpSource: nullptr,
         dwMessageId: LastError,
         dwLanguageId: 0,
         lpBuffer: buffer,
         nSize: 0x80u,
         Arguments: nullptr) != 0 )
    lua_pushstring(L, s: buffer);
  else
    lua_pushfstring(L, fmt: "system error %d\n", LastError);
}

//------------------------------------------------------------------------------
// Address: 0x00482CA0
// Name: ll_register
// Source: json
//------------------------------------------------------------------------------
Udata *__usercall ll_register@<eax>(lua_State *L@<esi>, const char *path)
{
  Udata *v3; // edi

  lua_pushfstring(L, fmt: "%s%s", "LOADLIB: ", path);
  lua_gettable(L, idx: -10000);
  if ( lua_type(L, idx: -1) != 0 )
    return (Udata *)lua_touserdata(L, idx: -1);
  lua_settop(L, idx: -2);
  v3 = lua_newuserdata(L, size: 4u);
  v3->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "_LOADLIB");
  lua_setmetatable(L, objindex: -2);
  lua_pushfstring(L, fmt: "%s%s", "LOADLIB: ", path);
  lua_pushvalue(L, idx: -2);
  lua_settable(L, idx: -10000);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00482D40
// Name: gctm
// Source: json
//------------------------------------------------------------------------------
int __cdecl gctm(lua_State *L)
{
  HMODULE *v1; // esi

  v1 = (HMODULE *)luaL_checkudata(L, ud: 1, tname: "_LOADLIB");
  if ( *v1 != nullptr )
    FreeLibrary(hLibModule: *v1);
  *v1 = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00482D70
// Name: ll_loadfunc
// Source: json
//------------------------------------------------------------------------------
int __usercall ll_loadfunc@<eax>(const char *path@<eax>, lua_State *L, const char *sym)
{
  HMODULE *v4; // ebx
  HMODULE LibraryA; // esi
  int (__cdecl *ProcAddress)(lua_State *); // eax

  v4 = (HMODULE *)ll_register(L, path);
  if ( *v4 == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: path);
    if ( LibraryA == nullptr )
      pusherror(L);
    *v4 = LibraryA;
    if ( LibraryA == nullptr )
      return 1;
  }
  ProcAddress = (int (__cdecl *)(lua_State *))GetProcAddress(hModule: *v4, lpProcName: sym);
  if ( ProcAddress != nullptr )
  {
    lua_pushcclosure(L, fn: ProcAddress, n: 0);
    return 0;
  }
  else
  {
    pusherror(L);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482DF0
// Name: ll_loadlib
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_loadlib(lua_State *L)
{
  const char *v1; // edi
  const char *v2; // eax
  int v3; // edi
  const char *v5; // eax

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = luaL_checklstring(L, narg: 2, len: nullptr);
  v3 = ll_loadfunc(path: v1, L, sym: v2);
  if ( v3 == 0 )
    return 1;
  lua_pushnil(L);
  lua_insert(L, idx: -2);
  v5 = "open";
  if ( v3 != 1 )
    v5 = "init";
  lua_pushstring(L, s: v5);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00482E60
// Name: findfile
// Source: json
//------------------------------------------------------------------------------
const char *__usercall findfile@<eax>(lua_State *L@<edi>, const char *pname@<eax>, char *name)
{
  const char *v4; // ebx
  unsigned __int8 *i; // esi
  const char *v6; // eax
  char *v7; // eax
  const char *v8; // esi
  _iobuf *v9; // eax
  const char *namea; // [esp+10h] [ebp+8h]

  namea = luaL_gsub(L, s: name, p: ".", r: "\\");
  lua_getfield(L, idx: -10001, k: pname);
  v4 = lua_tolstring(L, idx: -1, len: nullptr);
  if ( v4 == nullptr )
    luaL_error(L, fmt: "'package.%s' must be a string", pname);
  lua_pushstring(L, s: var);
  while ( 1 )
  {
    for ( i = (unsigned __int8 *)v4; *i == 59; ++i )
      ;
    if ( *i == 0 )
      break;
    strchr(string: i, chr: 0x3Bu);
    v4 = v6;
    if ( v6 == nullptr )
      v4 = (const char *)&i[strlen((const char *)i)];
    lua_pushlstring(L, s: (const char *)i, len: v4 - (const char *)i);
    if ( v4 == nullptr )
      break;
    v7 = (char *)lua_tolstring(L, idx: -1, len: nullptr);
    v8 = luaL_gsub(L, s: v7, p: "?", r: namea);
    v9 = fopen(file: v8, mode: "r");
    if ( v9 != nullptr )
    {
      fclose(stream: v9);
      return v8;
    }
    lua_settop(L, idx: -3);
    luaO_pushfstring((lua_TValue *)L, fmt: "\n\tno file '%s'", v8);
    lua_concat(L, n: 2);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00482F80
// Name: loaderror
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn loaderror(lua_State *L@<esi>, const char *filename)
{
  const char *v2; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  v3 = lua_tolstring(L, idx: -1, len: nullptr);
  v2 = lua_tolstring(L, idx: 1, len: nullptr);
  luaL_error(L, fmt: "error loading module '%s' from file '%s':\n\t%s", v2, filename, v3);
}

//------------------------------------------------------------------------------
// Address: 0x00482FC0
// Name: loader_Lua
// Source: json
//------------------------------------------------------------------------------
int __cdecl loader_Lua(lua_State *L)
{
  char *v1; // eax
  const char *v2; // eax
  const char *v3; // esi
  const char *v4; // eax
  const char *v6; // [esp-4h] [ebp-Ch]

  v1 = (char *)luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = findfile(L, pname: "path", name: v1);
  v3 = v2;
  if ( v2 != nullptr && luaL_loadfile(L, filename: v2) != 0 )
  {
    v6 = lua_tolstring(L, idx: -1, len: nullptr);
    v4 = lua_tolstring(L, idx: 1, len: nullptr);
    luaL_error(L, fmt: "error loading module '%s' from file '%s':\n\t%s", v4, v3, v6);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483030
// Name: mkfuncname
// Source: json
//------------------------------------------------------------------------------
const char *__usercall mkfuncname@<eax>(lua_State *L@<esi>, char *modname@<eax>)
{
  char *v2; // edi
  int v3; // eax
  const char *v4; // eax
  const char *v5; // edi

  v2 = modname;
  strchr(string: (unsigned __int8 *)modname, chr: 0x2Du);
  if ( v3 != 0 )
    v2 = (char *)(v3 + 1);
  v4 = luaL_gsub(L, s: v2, p: ".", r: "_");
  v5 = lua_pushfstring(L, fmt: "luaopen_%s", v4);
  lua_remove(L, idx: -2);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00483080
// Name: loader_C
// Source: json
//------------------------------------------------------------------------------
int __cdecl loader_C(lua_State *L)
{
  char *v1; // esi
  const char *v2; // ebx
  int v3; // eax
  const char *v4; // eax
  const char *v5; // esi
  const char *v6; // eax
  const char *v8; // [esp-4h] [ebp-10h]

  v1 = (char *)luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = findfile(L, pname: "cpath", name: v1);
  if ( v2 != nullptr )
  {
    strchr(string: (unsigned __int8 *)v1, chr: 0x2Du);
    if ( v3 != 0 )
      v1 = (char *)(v3 + 1);
    v4 = luaL_gsub(L, s: v1, p: ".", r: "_");
    v5 = lua_pushfstring(L, fmt: "luaopen_%s", v4);
    lua_remove(L, idx: -2);
    if ( ll_loadfunc(path: v2, L, sym: v5) != 0 )
    {
      v8 = lua_tolstring(L, idx: -1, len: nullptr);
      v6 = lua_tolstring(L, idx: 1, len: nullptr);
      luaL_error(L, fmt: "error loading module '%s' from file '%s':\n\t%s", v6, v2, v8);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483130
// Name: loader_Croot
// Source: json
//------------------------------------------------------------------------------
void __cdecl loader_Croot(lua_State *L)
{
  unsigned __int8 *v1; // ebx
  int v2; // eax
  char *v3; // eax
  const char *v4; // edi
  const char *v5; // eax
  int v6; // eax

  v1 = (unsigned __int8 *)luaL_checklstring(L, narg: 1, len: nullptr);
  strchr(string: v1, chr: 0x2Eu);
  if ( v2 != 0 )
  {
    lua_pushlstring(L, s: (const char *)v1, len: v2 - (_DWORD)v1);
    v3 = (char *)lua_tolstring(L, idx: -1, len: nullptr);
    v4 = findfile(L, pname: "cpath", name: v3);
    if ( v4 != nullptr )
    {
      v5 = mkfuncname(L, modname: (char *)v1);
      v6 = ll_loadfunc(path: v4, L, sym: v5);
      if ( v6 != 0 )
      {
        if ( v6 != 2 )
          loaderror(L, filename: v4);
        luaO_pushfstring((lua_TValue *)L, fmt: "\n\tno module '%s' in file '%s'", (const char *)v1, v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004831D0
// Name: loader_preload
// Source: json
//------------------------------------------------------------------------------
int __cdecl loader_preload(lua_State *L)
{
  const char *v1; // edi

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  lua_getfield(L, idx: -10001, k: "preload");
  if ( lua_type(L, idx: -1) != 5 )
    luaL_error(L, fmt: "'package.preload' must be a table");
  lua_getfield(L, idx: -1, k: v1);
  if ( lua_type(L, idx: -1) == 0 )
    luaO_pushfstring((lua_TValue *)L, fmt: "\n\tno field package.preload['%s']", v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483250
// Name: ll_require
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_require(lua_State *L)
{
  const char *v1; // edi
  int i; // ebx
  const char *v3; // eax

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  lua_settop(L, idx: 1);
  lua_getfield(L, idx: -10000, k: "_LOADED");
  lua_getfield(L, idx: 2, k: v1);
  if ( lua_toboolean(L, idx: -1) )
  {
    if ( (const int *)lua_touserdata(L, idx: -1) == &sentinel_ )
      luaL_error(L, fmt: "loop or previous error loading module '%s'", v1);
  }
  else
  {
    lua_getfield(L, idx: -10001, k: "loaders");
    if ( lua_type(L, idx: -1) != 5 )
      luaL_error(L, fmt: "'package.loaders' must be a table");
    lua_pushstring(L, s: var);
    for ( i = 1; ; ++i )
    {
      lua_rawgeti(L, idx: -2, n: i);
      if ( lua_type(L, idx: -1) == 0 )
      {
        v3 = lua_tolstring(L, idx: -2, len: nullptr);
        luaL_error(L, fmt: "module '%s' not found:%s", v1, v3);
      }
      lua_pushstring(L, s: v1);
      lua_call(L, nargs: 1, nresults: 1);
      if ( lua_type(L, idx: -1) == 6 )
        break;
      if ( lua_isstring(L, idx: -1) )
        lua_concat(L, n: 2);
      else
        lua_settop(L, idx: -2);
    }
    lua_pushlightuserdata(L, p: (void *)&sentinel_);
    lua_setfield(L, idx: 2, k: v1);
    lua_pushstring(L, s: v1);
    lua_call(L, nargs: 1, nresults: 1);
    if ( lua_type(L, idx: -1) != 0 )
      lua_setfield(L, idx: 2, k: v1);
    lua_getfield(L, idx: 2, k: v1);
    if ( (const int *)lua_touserdata(L, idx: -1) == &sentinel_ )
    {
      lua_pushboolean(L, b: 1);
      lua_pushvalue(L, idx: -1);
      lua_setfield(L, idx: 2, k: v1);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00483410
// Name: modinit
// Source: json
//------------------------------------------------------------------------------
void __usercall modinit(lua_State *L@<esi>, char *modname@<edi>)
{
  int v2; // eax
  char *v3; // eax

  lua_pushvalue(L, idx: -1);
  lua_setfield(L, idx: -2, k: "_M");
  lua_pushstring(L, s: modname);
  lua_setfield(L, idx: -2, k: "_NAME");
  strrchr(string: (unsigned __int8 *)modname, chr: 0x2Eu);
  if ( v2 != 0 )
    v3 = (char *)(v2 + 1);
  else
    v3 = modname;
  lua_pushlstring(L, s: modname, len: v3 - modname);
  lua_setfield(L, idx: -2, k: "_PACKAGE");
}

//------------------------------------------------------------------------------
// Address: 0x00483470
// Name: ll_module
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_module(lua_State *L)
{
  char *v1; // edi
  int v2; // ebx
  int v3; // edi
  int v4; // ebx
  lua_Debug ar; // [esp+Ch] [ebp-64h] BYREF

  v1 = (char *)luaL_checklstring(L, narg: 1, len: nullptr);
  v2 = lua_gettop(L) + 1;
  lua_getfield(L, idx: -10000, k: "_LOADED");
  lua_getfield(L, idx: v2, k: v1);
  if ( lua_type(L, idx: -1) != 5 )
  {
    lua_settop(L, idx: -2);
    if ( luaL_findtable(L, idx: -10002, fname: v1, szhint: 1) != nullptr )
      luaL_error(L, fmt: "name conflict for module '%s'", v1);
    lua_pushvalue(L, idx: -1);
    lua_setfield(L, idx: v2, k: v1);
  }
  lua_getfield(L, idx: -1, k: "_NAME");
  if ( lua_type(L, idx: -1) != 0 )
  {
    lua_settop(L, idx: -2);
  }
  else
  {
    lua_settop(L, idx: -2);
    modinit(L, modname: v1);
  }
  lua_pushvalue(L, idx: -1);
  lua_getstack(L, level: 1, &ar);
  lua_getinfo(L, what: "f", &ar);
  lua_pushvalue(L, idx: -2);
  lua_setfenv(L, idx: -2);
  lua_settop(L, idx: -2);
  v3 = 2;
  v4 = v2 - 1;
  if ( v4 >= 2 )
  {
    do
    {
      lua_pushvalue(L, idx: v3);
      lua_pushvalue(L, idx: -2);
      lua_call(L, nargs: 1, nresults: 0);
      ++v3;
    }
    while ( v3 <= v4 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004835B0
// Name: ll_seeall
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_seeall(lua_State *L)
{
  luaL_checktype(L, narg: 1, t: 5);
  if ( lua_getmetatable(L, objindex: 1) == 0 )
  {
    lua_createtable(L, narray: 0, nrec: 1);
    lua_pushvalue(L, idx: -1);
    lua_setmetatable(L, objindex: 1);
  }
  lua_pushvalue(L, idx: -10002);
  lua_setfield(L, idx: -2, k: "__index");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00483610
// Name: int luaopen_package(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_package(lua_State *L)
{
  int (__cdecl *v1)(lua_State *); // eax
  int i; // edi
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax

  luaL_newmetatable(L, tname: "_LOADLIB");
  lua_pushcclosure(L, fn: gctm, n: 0);
  lua_setfield(L, idx: -2, k: "__gc");
  luaL_register(L, libname: "package", l: pk_funcs);
  lua_pushvalue(L, idx: -1);
  lua_replace(L, idx: -10001);
  lua_createtable(L, narray: 0, nrec: 4);
  v1 = loader_preload;
  for ( i = 0; v1 != nullptr; v1 = loaders[i] )
  {
    lua_pushcclosure(L, fn: v1, n: 0);
    lua_rawseti(L, idx: -2, n: ++i);
  }
  lua_setfield(L, idx: -2, k: "loaders");
  v3 = getenv(option: "LUA_PATH");
  if ( v3 != nullptr )
  {
    v4 = (char *)luaL_gsub(L, s: v3, p: ";;", r: asc_5C0554);
    luaL_gsub(
      L,
      s: v4,
      p: (char *)&byte_5C054C,
      r: ".\\?.lua;!\\lua\\?.lua;!\\lua\\?\\init.lua;!\\?.lua;!\\?\\init.lua");
    lua_remove(L, idx: -2);
  }
  else
  {
    lua_pushstring(L, s: ".\\?.lua;!\\lua\\?.lua;!\\lua\\?\\init.lua;!\\?.lua;!\\?\\init.lua");
  }
  setprogdir(L);
  lua_setfield(L, idx: -2, k: "path");
  v5 = getenv(option: "LUA_CPATH");
  if ( v5 != nullptr )
  {
    v6 = (char *)luaL_gsub(L, s: v5, p: ";;", r: asc_5C0554);
    luaL_gsub(L, s: v6, p: (char *)&byte_5C054C, r: ".\\?.dll;!\\?.dll;!\\loadall.dll");
    lua_remove(L, idx: -2);
  }
  else
  {
    lua_pushstring(L, s: ".\\?.dll;!\\?.dll;!\\loadall.dll");
  }
  setprogdir(L);
  lua_setfield(L, idx: -2, k: "cpath");
  lua_pushstring(L, s: "\\\n;\n?\n!\n-");
  lua_setfield(L, idx: -2, k: "config");
  luaL_findtable(L, idx: -10000, fname: "_LOADED", szhint: 2);
  lua_setfield(L, idx: -2, k: "loaded");
  lua_createtable(L, narray: 0, nrec: 0);
  lua_setfield(L, idx: -2, k: "preload");
  lua_pushvalue(L, idx: -10002);
  luaL_register(L, libname: nullptr, l: ll_funcs);
  lua_settop(L, idx: -2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A9BF0
// Name: _dynamic_initializer_for__Load_LuaFunc_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Load_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Load_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Load_LuaFunc_s;
  return result;
}
