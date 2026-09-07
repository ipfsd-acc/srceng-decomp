// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/liolib.c
// Functions: 31
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00481080
// Name: fileerror
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn fileerror(lua_State *L@<esi>, int arg, const char *filename)
{
  int *v3; // eax
  const char *v4; // eax
  const char *v5; // eax

  v3 = _errno();
  v4 = strerror(errnum: *v3);
  lua_pushfstring(L, fmt: "%s: %s", filename, v4);
  v5 = lua_tolstring(L, idx: -1, len: nullptr);
  luaL_argerror(L, narg: arg, extramsg: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004810C0
// Name: io_type
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_type(lua_State *L)
{
  _DWORD *v1; // edi

  luaL_checkany(L, narg: 1);
  v1 = (_DWORD *)lua_touserdata(L, idx: 1);
  lua_getfield(L, idx: -10000, k: "FILE*");
  if ( v1 != nullptr && lua_getmetatable(L, objindex: 1) != 0 && lua_rawequal(L, index1: -2, index2: -1) != 0 )
  {
    if ( *v1 != 0 )
      lua_pushlstring(L, s: "file", len: 4u);
    else
      lua_pushlstring(L, s: "closed file", len: 0xBu);
    return 1;
  }
  else
  {
    lua_pushnil(L);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481160
// Name: io_pclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_pclose(lua_State *L)
{
  _iobuf **v1; // esi
  BOOL v2; // ebx
  int v3; // esi
  const char *v5; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  v2 = _pclose(pstream: *v1) != -1;
  *v1 = nullptr;
  v3 = *_errno();
  if ( v2 )
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
  else
  {
    lua_pushnil(L);
    v5 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v5);
    lua_pushinteger(L, n: v3);
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004811E0
// Name: io_fclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_fclose(lua_State *L)
{
  _iobuf **v1; // edi
  int v2; // esi
  int v3; // edi
  const char *v5; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  v2 = -(fclose(stream: *v1) != 0);
  *v1 = nullptr;
  v3 = *_errno();
  if ( v2 == -1 )
  {
    lua_pushnil(L);
    v5 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v5);
    lua_pushinteger(L, n: v3);
    return 3;
  }
  else
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481260
// Name: aux_close
// Source: json
//------------------------------------------------------------------------------
int __usercall aux_close@<eax>(lua_State *L@<esi>)
{
  int (__cdecl *v1)(lua_State *); // eax

  lua_getfenv(L, idx: 1);
  lua_getfield(L, idx: -1, k: "__close");
  v1 = lua_tocfunction(L, idx: -1);
  return v1(a1: L);
}

//------------------------------------------------------------------------------
// Address: 0x00481290
// Name: io_close
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_close(lua_State *L)
{
  int (__cdecl *v1)(lua_State *); // eax

  if ( lua_type(L, idx: 1) == -1 )
    lua_rawgeti(L, idx: -10001, n: 2);
  if ( *(_DWORD *)luaL_checkudata(L, ud: 1, tname: "FILE*") == 0 )
    luaL_error(L, fmt: "attempt to use a closed file");
  lua_getfenv(L, idx: 1);
  lua_getfield(L, idx: -1, k: "__close");
  v1 = lua_tocfunction(L, idx: -1);
  return v1(a1: L);
}

//------------------------------------------------------------------------------
// Address: 0x00481310
// Name: io_gc
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_gc(lua_State *L)
{
  _iobuf *v1; // edi

  v1 = *(_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( v1 != nullptr && v1 != __iob_func() && v1 != &__iob_func()[1] && v1 != &__iob_func()[2] )
    aux_close(L);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00481360
// Name: io_tostring
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_tostring(lua_State *L)
{
  const void *v1; // eax

  v1 = *(const void **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( v1 != nullptr )
    lua_pushfstring(L, fmt: "file (%p)", v1);
  else
    lua_pushstring(L, s: "file (closed)");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004813B0
// Name: io_open
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_open(lua_State *L)
{
  const char *v1; // edi
  Udata *v2; // ebx
  _iobuf *v3; // eax
  int v4; // ebx
  const char *v6; // [esp-8h] [ebp-18h]
  const char *mode; // [esp+Ch] [ebp-4h]

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  mode = luaL_optlstring(L, narg: 2, def: "r", len: nullptr);
  v2 = lua_newuserdata(L, size: 4u);
  v2->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "FILE*");
  lua_setmetatable(L, objindex: -2);
  v3 = fopen(file: v1, mode);
  v2->dummy.l = (int)v3;
  if ( v3 != nullptr )
    return 1;
  v4 = *_errno();
  lua_pushnil(L);
  v6 = strerror(errnum: v4);
  if ( v1 != nullptr )
    lua_pushfstring(L, fmt: "%s: %s", v1, v6);
  else
    lua_pushfstring(L, fmt: "%s", v6);
  lua_pushinteger(L, n: v4);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00481490
// Name: io_popen
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_popen(lua_State *L)
{
  const char *v1; // edi
  Udata *v2; // ebx
  _iobuf *v3; // eax
  int v4; // ebx
  const char *v6; // [esp-8h] [ebp-18h]
  const char *mode; // [esp+Ch] [ebp-4h]

  v1 = luaL_checklstring(L, narg: 1, len: nullptr);
  mode = luaL_optlstring(L, narg: 2, def: "r", len: nullptr);
  v2 = lua_newuserdata(L, size: 4u);
  v2->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "FILE*");
  lua_setmetatable(L, objindex: -2);
  v3 = _popen(cmdstring: v1, type: mode);
  v2->dummy.l = (int)v3;
  if ( v3 != nullptr )
    return 1;
  v4 = *_errno();
  lua_pushnil(L);
  v6 = strerror(errnum: v4);
  if ( v1 != nullptr )
    lua_pushfstring(L, fmt: "%s: %s", v1, v6);
  else
    lua_pushfstring(L, fmt: "%s", v6);
  lua_pushinteger(L, n: v4);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00481570
// Name: io_tmpfile
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_tmpfile(lua_State *L)
{
  Udata *v1; // edi
  _iobuf *v2; // eax
  int v3; // edi
  const char *v4; // eax

  v1 = lua_newuserdata(L, size: 4u);
  v1->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "FILE*");
  lua_setmetatable(L, objindex: -2);
  v2 = tmpfile();
  v1->dummy.l = (int)v2;
  if ( v2 != nullptr )
    return 1;
  v3 = *_errno();
  lua_pushnil(L);
  v4 = strerror(errnum: v3);
  lua_pushfstring(L, fmt: "%s", v4);
  lua_pushinteger(L, n: v3);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004815F0
// Name: g_iofile
// Source: json
//------------------------------------------------------------------------------
int __usercall g_iofile@<eax>(lua_State *L@<eax>, int f, const char *mode)
{
  const char *v4; // ebx
  Udata *v5; // edi
  _iobuf *v6; // eax

  if ( lua_type(L, idx: 1) > 0 )
  {
    v4 = lua_tolstring(L, idx: 1, len: nullptr);
    if ( v4 != nullptr )
    {
      v5 = lua_newuserdata(L, size: 4u);
      v5->dummy.l = 0;
      lua_getfield(L, idx: -10000, k: "FILE*");
      lua_setmetatable(L, objindex: -2);
      v6 = fopen(file: v4, mode);
      v5->dummy.l = (int)v6;
      if ( v6 == nullptr )
        fileerror(L, arg: 1, filename: v4);
    }
    else
    {
      if ( *(_DWORD *)luaL_checkudata(L, ud: 1, tname: "FILE*") == 0 )
        luaL_error(L, fmt: "attempt to use a closed file");
      lua_pushvalue(L, idx: 1);
    }
    lua_rawseti(L, idx: -10001, n: f);
  }
  lua_rawgeti(L, idx: -10001, n: f);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004816C0
// Name: io_input
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_input(lua_State *L)
{
  return g_iofile(L, f: 1, mode: "r");
}

//------------------------------------------------------------------------------
// Address: 0x004816E0
// Name: io_output
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_output(lua_State *L)
{
  return g_iofile(L, f: 2, mode: "w");
}

//------------------------------------------------------------------------------
// Address: 0x00481700
// Name: read_number
// Source: json
//------------------------------------------------------------------------------
int __cdecl read_number(lua_State *L)
{
  _iobuf *f; // ecx
  long double d; // [esp+8h] [ebp-8h] BYREF

  if ( fscanf(stream: f, format: "%lf", &d) != 1 )
    return 0;
  lua_pushnumber(L, n: d);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00481750
// Name: read_line
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall read_line@<eax>(_iobuf *f@<edi>, lua_State *L)
{
  char *v2; // esi
  unsigned int v3; // eax
  luaL_Buffer b; // [esp+4h] [ebp-20Ch] BYREF

  luaL_buffinit(L, B: &b);
  v2 = luaL_prepbuffer(B: &b);
  if ( fgets(string: v2, count: 512, str: f) != nullptr )
  {
    while ( 1 )
    {
      v3 = strlen(v2);
      if ( v3 != 0 && v2[v3 - 1] == 10 )
        break;
      b.p += v3;
      v2 = luaL_prepbuffer(B: &b);
      if ( fgets(string: v2, count: 512, str: f) == nullptr )
        goto LABEL_5;
    }
    b.p = &b.p[v3 - 1];
    luaL_pushresult(B: &b);
    return true;
  }
  else
  {
LABEL_5:
    luaL_pushresult(B: &b);
    return lua_objlen(L, idx: -1) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481820
// Name: read_chars
// Source: json
//------------------------------------------------------------------------------
int __usercall read_chars@<eax>(unsigned int n@<eax>, lua_State *L, _iobuf *f)
{
  unsigned int v4; // esi
  char *v5; // eax
  unsigned int v6; // eax
  int result; // eax
  luaL_Buffer b; // [esp+Ch] [ebp-20Ch] BYREF

  luaL_buffinit(L, B: &b);
  v4 = 512;
  do
  {
    v5 = luaL_prepbuffer(B: &b);
    if ( v4 > n )
      v4 = n;
    v6 = fread(buffer: v5, elementSize: 1u, count: v4, stream: f);
    b.p += v6;
    n -= v6;
  }
  while ( n != 0 && v6 == v4 );
  luaL_pushresult(B: &b);
  if ( n == 0 )
    return 1;
  result = lua_objlen(L, idx: -1);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004818C0
// Name: g_read
// Source: json
//------------------------------------------------------------------------------
int __usercall g_read@<eax>(lua_State *L@<esi>, _iobuf *f, int first)
{
  int v3; // edi
  int chars; // edi
  int v5; // edi
  const char *v6; // eax
  lua_TValue *v8; // eax
  int v9; // edi
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  lua_State *v13; // [esp+0h] [ebp-14h]
  int nargs; // [esp+Ch] [ebp-8h]
  int n; // [esp+10h] [ebp-4h]

  v3 = lua_gettop(L: v13) - 1;
  nargs = v3;
  clearerr(stream: f);
  if ( v3 != 0 )
  {
    luaL_checkstack(L, space: v3 + 20, mes: "too many arguments");
    chars = 1;
    n = first;
    do
    {
      --nargs;
      if ( chars == 0 )
        break;
      if ( lua_type(L, idx: n) == 3 )
      {
        v8 = lua_tointeger(L, idx: n);
        if ( v8 != nullptr )
        {
          chars = read_chars(n: (unsigned int)v8, L, f);
        }
        else
        {
          v9 = getc(stream: f);
          ungetc(ch: v9, stream: f);
          lua_pushlstring(L, s: nullptr, len: 0);
          chars = v9 != -1;
        }
      }
      else
      {
        v10 = lua_tolstring(L, idx: n, len: nullptr);
        if ( v10 == nullptr || *v10 != 42 )
          luaL_argerror(L, narg: n, extramsg: "invalid option");
        v11 = v10[1] - 97;
        if ( v11 != 0 )
        {
          v12 = v11 - 11;
          if ( v12 != 0 )
          {
            if ( v12 != 2 )
              luaL_argerror(L, narg: n, extramsg: "invalid format");
            chars = read_number(L);
          }
          else
          {
            chars = read_line(f, L);
          }
        }
        else
        {
          read_chars(n: 0xFFFFFFFF, L, f);
          chars = 1;
        }
      }
      ++n;
    }
    while ( nargs != 0 );
  }
  else
  {
    chars = read_line(f, L);
    n = first + 1;
  }
  if ( ferror(stream: f) != 0 )
  {
    v5 = *_errno();
    lua_pushnil(L);
    v6 = strerror(errnum: v5);
    lua_pushfstring(L, fmt: "%s", v6);
    lua_pushinteger(L, n: v5);
    return 3;
  }
  else
  {
    if ( chars == 0 )
    {
      lua_settop(L, idx: -2);
      lua_pushnil(L);
    }
    return n - first;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481A70
// Name: io_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_read(lua_State *L)
{
  _iobuf *v1; // edi

  lua_rawgeti(L, idx: -10001, n: 1);
  v1 = *(_iobuf **)lua_touserdata(L, idx: -1);
  if ( v1 == nullptr )
    luaL_error(L, fmt: "standard %s file is closed", "input");
  return g_read(L, f: v1, first: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00481AC0
// Name: f_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_read(lua_State *L)
{
  _iobuf **v1; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  return g_read(L, f: *v1, first: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00481B00
// Name: io_readline
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_readline(lua_State *L)
{
  _iobuf *v1; // edi
  BOOL line; // ebx
  int *v3; // eax
  const char *v4; // eax
  int (__cdecl *v6)(lua_State *); // eax

  v1 = *(_iobuf **)lua_touserdata(L, idx: -10003);
  if ( v1 == nullptr )
    luaL_error(L, fmt: "file is already closed");
  line = read_line(f: v1, L);
  if ( ferror(stream: v1) != 0 )
  {
    v3 = _errno();
    v4 = strerror(errnum: *v3);
    luaL_error(L, fmt: "%s", v4);
  }
  if ( line )
    return 1;
  if ( lua_toboolean(L, idx: -10004) )
  {
    lua_settop(L, idx: 0);
    lua_pushvalue(L, idx: -10003);
    lua_getfenv(L, idx: 1);
    lua_getfield(L, idx: -1, k: "__close");
    v6 = lua_tocfunction(L, idx: -1);
    v6(a1: L);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00481BD0
// Name: g_write
// Source: json
//------------------------------------------------------------------------------
int __usercall g_write@<eax>(lua_State *L@<edi>, _iobuf *f, int arg)
{
  int v4; // eax
  int v5; // esi
  double v6; // st7
  int v7; // ebx
  const char *v9; // eax
  unsigned int v10; // eax
  const char *v11; // eax
  lua_State *v12; // [esp+4h] [ebp-14h]
  int nargs; // [esp+10h] [ebp-8h]
  unsigned int len; // [esp+14h] [ebp-4h] BYREF

  v4 = lua_gettop(L: v12) - 1;
  v5 = 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      nargs = v4 - 1;
      if ( lua_type(L, idx: arg) == 3 )
      {
        if ( v5 == 0 )
          goto LABEL_7;
        v6 = lua_tonumber(L, idx: arg);
        if ( fprintf(str: f, format: "%.14g", v6) <= 0 )
          goto LABEL_7;
      }
      else
      {
        v9 = luaL_checklstring(L, narg: arg, &len);
        if ( v5 == 0 || (v10 = fwrite(buffer: v9, size: 1u, count: len, stream: f)) != len )
        {
LABEL_7:
          v5 = 0;
          goto LABEL_8;
        }
      }
      v5 = 1;
LABEL_8:
      ++arg;
      if ( nargs == 0 )
        break;
      v4 = nargs;
    }
  }
  v7 = *_errno();
  if ( v5 != 0 )
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
  else
  {
    lua_pushnil(L);
    v11 = strerror(errnum: v7);
    lua_pushfstring(L, fmt: "%s", v11);
    lua_pushinteger(L, n: v7);
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481CC0
// Name: io_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_write(lua_State *L)
{
  _iobuf *v1; // esi

  lua_rawgeti(L, idx: -10001, n: 2);
  v1 = *(_iobuf **)lua_touserdata(L, idx: -1);
  if ( v1 == nullptr )
    luaL_error(L, fmt: "standard %s file is closed", "output");
  return g_write(L, f: v1, arg: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00481D10
// Name: f_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_write(lua_State *L)
{
  _iobuf **v1; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  return g_write(L, f: *v1, arg: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00481D50
// Name: f_seek
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_seek(lua_State *L)
{
  _iobuf **v1; // eax
  _iobuf *v2; // edi
  int v3; // ebx
  lua_TValue *v4; // eax
  int v5; // edi
  const char *v6; // eax
  int v8; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  v2 = *v1;
  v3 = luaL_checkoption(L, narg: 2, def: "cur", lst: (const char **)modenames);
  v4 = luaL_optinteger(L, narg: 3, def: 0);
  if ( fseek(stream: v2, offset: (int)v4, whence: mode[v3]) != 0 )
  {
    v5 = *_errno();
    lua_pushnil(L);
    v6 = strerror(errnum: v5);
    lua_pushfstring(L, fmt: "%s", v6);
    lua_pushinteger(L, n: v5);
    return 3;
  }
  else
  {
    v8 = ftell(stream: v2);
    lua_pushinteger(L, n: v8);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481E00
// Name: f_setvbuf
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_setvbuf(lua_State *L)
{
  _iobuf **v1; // eax
  _iobuf *v2; // edi
  int v3; // ebx
  lua_TValue *v4; // eax
  int v5; // edi
  int v6; // ebx
  const char *v8; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  v2 = *v1;
  v3 = luaL_checkoption(L, narg: 2, def: nullptr, lst: (const char **)modenames_0);
  v4 = luaL_optinteger(L, narg: 3, def: 512);
  v5 = setvbuf(str: v2, buffer: nullptr, type: mode_0[v3], size: (unsigned int)v4);
  v6 = *_errno();
  if ( v5 != 0 )
  {
    lua_pushnil(L);
    v8 = strerror(errnum: v6);
    lua_pushfstring(L, fmt: "%s", v8);
    lua_pushinteger(L, n: v6);
    return 3;
  }
  else
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481EB0
// Name: io_flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_flush(lua_State *L)
{
  _iobuf **v1; // eax
  int v2; // esi
  int v3; // ebx
  const char *v5; // eax

  lua_rawgeti(L, idx: -10001, n: 2);
  v1 = (_iobuf **)lua_touserdata(L, idx: -1);
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "standard %s file is closed", "output");
  v2 = -(fflush(stream: *v1) != 0);
  v3 = *_errno();
  if ( v2 == -1 )
  {
    lua_pushnil(L);
    v5 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v5);
    lua_pushinteger(L, n: v3);
    return 3;
  }
  else
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481F50
// Name: f_flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_flush(lua_State *L)
{
  _iobuf **v1; // eax
  int v2; // esi
  int v3; // ebx
  const char *v5; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  v2 = -(fflush(stream: *v1) != 0);
  v3 = *_errno();
  if ( v2 == -1 )
  {
    lua_pushnil(L);
    v5 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v5);
    lua_pushinteger(L, n: v3);
    return 3;
  }
  else
  {
    lua_pushboolean(L, b: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481FF0
// Name: int luaopen_io(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_io(lua_State *L)
{
  _iobuf *v1; // ebx
  Udata *v2; // edi
  _iobuf *v3; // edi
  Udata *v4; // ebx
  _iobuf *v5; // edi
  Udata *v6; // ebx

  luaL_newmetatable(L, tname: "FILE*");
  lua_pushvalue(L, idx: -1);
  lua_setfield(L, idx: -2, k: "__index");
  luaL_register(L, libname: nullptr, l: flib);
  lua_createtable(L, narray: 2, nrec: 1);
  lua_replace(L, idx: -10001);
  luaL_register(L, libname: "io", l: iolib);
  v1 = __iob_func();
  v2 = lua_newuserdata(L, size: 4u);
  v2->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "FILE*");
  lua_setmetatable(L, objindex: -2);
  v2->dummy.l = (int)v1;
  lua_pushvalue(L, idx: -1);
  lua_rawseti(L, idx: -10001, n: 1);
  lua_setfield(L, idx: -2, k: "stdin");
  v3 = __iob_func() + 1;
  v4 = lua_newuserdata(L, size: 4u);
  v4->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "FILE*");
  lua_setmetatable(L, objindex: -2);
  v4->dummy.l = (int)v3;
  lua_pushvalue(L, idx: -1);
  lua_rawseti(L, idx: -10001, n: 2);
  lua_setfield(L, idx: -2, k: "stdout");
  v5 = __iob_func() + 2;
  v6 = lua_newuserdata(L, size: 4u);
  v6->dummy.l = 0;
  lua_getfield(L, idx: -10000, k: "FILE*");
  lua_setmetatable(L, objindex: -2);
  v6->dummy.l = (int)v5;
  lua_setfield(L, idx: -2, k: "stderr");
  lua_getfield(L, idx: -1, k: "popen");
  lua_createtable(L, narray: 0, nrec: 1);
  lua_pushcclosure(L, fn: io_pclose, n: 0);
  lua_setfield(L, idx: -2, k: "__close");
  lua_setfenv(L, idx: -2);
  lua_settop(L, idx: -2);
  lua_pushcclosure(L, fn: io_fclose, n: 0);
  lua_setfield(L, idx: -10001, k: "__close");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004821B0
// Name: f_lines
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_lines(lua_State *L)
{
  if ( *(_DWORD *)luaL_checkudata(L, ud: 1, tname: "FILE*") == 0 )
    luaL_error(L, fmt: "attempt to use a closed file");
  lua_pushvalue(L, idx: 1);
  lua_pushboolean(L, b: 0);
  lua_pushcclosure(L, fn: io_readline, n: 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00482210
// Name: io_lines
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_lines(lua_State *L)
{
  const char *v2; // ebx
  Udata *v3; // edi
  _iobuf *v4; // eax
  int *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax

  if ( lua_type(L, idx: 1) > 0 )
  {
    v2 = luaL_checklstring(L, narg: 1, len: nullptr);
    v3 = lua_newuserdata(L, size: 4u);
    v3->dummy.l = 0;
    lua_getfield(L, idx: -10000, k: "FILE*");
    lua_setmetatable(L, objindex: -2);
    v4 = fopen(file: v2, mode: "r");
    v3->dummy.l = (int)v4;
    if ( v4 == nullptr )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      lua_pushfstring(L, fmt: "%s: %s", v2, v6);
      v7 = lua_tolstring(L, idx: -1, len: nullptr);
      luaL_argerror(L, narg: 1, extramsg: v7);
    }
    v8 = lua_gettop(L);
    lua_pushvalue(L, idx: v8);
    lua_pushboolean(L, b: 1);
    lua_pushcclosure(L, fn: io_readline, n: 2);
    return 1;
  }
  else
  {
    lua_rawgeti(L, idx: -10001, n: 1);
    return f_lines(L);
  }
}
