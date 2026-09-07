// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lauxlib.c
// Functions: 36
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00475790
// Name: void luaL_where(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_where(lua_State *L, int level)
{
  lua_Debug ar; // [esp+4h] [ebp-64h] BYREF

  if ( lua_getstack(L, level, &ar) != 0 && (lua_getinfo(L, what: "Sl", &ar), ar.currentline > 0) )
    lua_pushfstring(L, fmt: "%s:%d: ", ar.short_src, ar.currentline);
  else
    lua_pushlstring(L, s: var, len: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00475800
// Name: int luaL_error(struct lua_State __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __noreturn luaL_error(lua_State *L, const char *fmt, ...)
{
  lua_Debug ar; // [esp+4h] [ebp-64h] BYREF
  va_list argp; // [esp+78h] [ebp+10h] BYREF

  va_start(argp, fmt);
  if ( lua_getstack(L, level: 1, &ar) != 0 && (lua_getinfo(L, what: "Sl", &ar), ar.currentline > 0) )
    lua_pushfstring(L, fmt: "%s:%d: ", ar.short_src, ar.currentline);
  else
    lua_pushlstring(L, s: var, len: 0);
  lua_pushvfstring(L, fmt, argp);
  lua_concat(L, n: 2);
  lua_error(L);
}

//------------------------------------------------------------------------------
// Address: 0x00475880
// Name: int luaL_newmetatable(struct lua_State __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_newmetatable(lua_State *L, const char *tname)
{
  lua_getfield(L, idx: -10000, k: tname);
  if ( lua_type(L, idx: -1) != 0 )
    return 0;
  lua_settop(L, idx: -2);
  lua_createtable(L, narray: 0, nrec: 0);
  lua_pushvalue(L, idx: -1);
  lua_setfield(L, idx: -10000, k: tname);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004758E0
// Name: void luaL_checkstack(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_checkstack(lua_State *L, int space, const char *mes)
{
  if ( lua_checkstack(L, size: space) == 0 )
    luaL_error(L, fmt: "stack overflow (%s)", mes);
}

//------------------------------------------------------------------------------
// Address: 0x00475910
// Name: int luaL_getmetafield(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_getmetafield(lua_State *L, int obj, const char *event)
{
  if ( lua_getmetatable(L, objindex: obj) == 0 )
    return 0;
  lua_pushstring(L, s: event);
  lua_rawget(L, idx: -2);
  if ( lua_type(L, idx: -1) == 0 )
  {
    lua_settop(L, idx: -3);
    return 0;
  }
  lua_remove(L, idx: -2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475970
// Name: int luaL_callmeta(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_callmeta(lua_State *L, unsigned int obj, const char *event)
{
  int v3; // edi

  v3 = obj;
  if ( obj >= 0xFFFFD8F1 || obj == 0 )
    v3 = obj + lua_gettop(L) + 1;
  if ( lua_getmetatable(L, objindex: v3) == 0 )
    return 0;
  lua_pushstring(L, s: event);
  lua_rawget(L, idx: -2);
  if ( lua_type(L, idx: -1) == 0 )
  {
    lua_settop(L, idx: -3);
    return 0;
  }
  lua_remove(L, idx: -2);
  lua_pushvalue(L, idx: v3);
  lua_call(L, nargs: 1, nresults: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475A00
// Name: char const __near * luaL_findtable(struct lua_State __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl luaL_findtable(lua_State *L, int idx, char *fname, int szhint)
{
  const char *v5; // eax
  const char *v6; // ebx
  int v7; // eax

  lua_pushvalue(L, idx);
  while ( 1 )
  {
    strchr(string: (unsigned __int8 *)fname, chr: 0x2Eu);
    v6 = v5;
    if ( v5 == nullptr )
      v6 = &fname[strlen(fname)];
    lua_pushlstring(L, s: fname, len: v6 - fname);
    lua_rawget(L, idx: -2);
    if ( lua_type(L, idx: -1) == 0 )
    {
      lua_settop(L, idx: -2);
      v7 = 1;
      if ( *v6 != 46 )
        v7 = szhint;
      lua_createtable(L, narray: 0, nrec: v7);
      lua_pushlstring(L, s: fname, len: v6 - fname);
      lua_pushvalue(L, idx: -2);
      lua_settable(L, idx: -4);
      goto LABEL_9;
    }
    if ( lua_type(L, idx: -1) != 5 )
      break;
LABEL_9:
    lua_remove(L, idx: -2);
    fname = (char *)(v6 + 1);
    if ( *v6 != 46 )
      return nullptr;
  }
  lua_settop(L, idx: -3);
  return fname;
}

//------------------------------------------------------------------------------
// Address: 0x00475AF0
// Name: adjuststack
// Source: json
//------------------------------------------------------------------------------
void __cdecl adjuststack(luaL_Buffer *B)
{
  int v1; // esi
  lua_State *L; // ebx
  int v3; // edi
  unsigned int v4; // eax
  unsigned int toplen; // [esp+4h] [ebp-4h]

  v1 = 1;
  if ( B->lvl > 1 )
  {
    L = B->L;
    toplen = lua_objlen(L, idx: -1);
    v3 = -2;
    do
    {
      v4 = lua_objlen(L, idx: v3);
      if ( B->lvl - v1 + 1 < 10 && toplen <= v4 )
        break;
      toplen += v4;
      ++v1;
      --v3;
    }
    while ( v1 < B->lvl );
    lua_concat(L, n: v1);
    B->lvl += 1 - v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475B70
// Name: char __near * luaL_prepbuffer(struct luaL_Buffer __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl luaL_prepbuffer(luaL_Buffer *B)
{
  if ( B->p - (char *)B != 12 )
  {
    lua_pushlstring(L: B->L, s: B->buffer, len: B->p - (char *)B - 12);
    ++B->lvl;
    B->p = B->buffer;
    adjuststack(B);
  }
  return B->buffer;
}

//------------------------------------------------------------------------------
// Address: 0x00475BB0
// Name: void luaL_addlstring(struct luaL_Buffer __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_addlstring(luaL_Buffer *B, const char *s, unsigned int l)
{
  unsigned int i; // ebx

  for ( i = l; i != 0; ++s )
  {
    --i;
    if ( B->p >= (char *)&B[1] && B->p - (char *)B != 12 )
    {
      lua_pushlstring(L: B->L, s: B->buffer, len: B->p - (char *)B - 12);
      ++B->lvl;
      B->p = B->buffer;
      adjuststack(B);
    }
    *B->p++ = *s;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475C10
// Name: void luaL_pushresult(struct luaL_Buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_pushresult(luaL_Buffer *B)
{
  if ( B->p - (char *)B != 12 )
  {
    lua_pushlstring(L: B->L, s: B->buffer, len: B->p - (char *)B - 12);
    ++B->lvl;
    B->p = B->buffer;
  }
  lua_concat(L: B->L, n: B->lvl);
  B->lvl = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475C60
// Name: void luaL_addvalue(struct luaL_Buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_addvalue(unsigned int B)
{
  luaL_Buffer *v1; // esi
  lua_State *v2; // edi
  unsigned __int8 *v3; // eax
  unsigned __int8 *p; // ecx
  unsigned int v5; // ecx

  v1 = (luaL_Buffer *)B;
  v2 = *(lua_State **)(B + 8);
  v3 = (unsigned __int8 *)lua_tolstring(L: v2, idx: -1, len: &B);
  p = (unsigned __int8 *)v1->p;
  if ( B > (char *)v1 - v1->p + 524 )
  {
    v5 = p - (unsigned __int8 *)v1 - 12;
    if ( v5 != 0 )
    {
      lua_pushlstring(L: v1->L, s: v1->buffer, len: v5);
      ++v1->lvl;
      v1->p = v1->buffer;
      lua_insert(L: v2, idx: -2);
    }
    ++v1->lvl;
    adjuststack(B: v1);
  }
  else
  {
    memcpy(dst: p, src: v3, count: B);
    v1->p += B;
    lua_settop(L: v2, idx: -2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475CF0
// Name: void luaL_buffinit(struct lua_State __near *,struct luaL_Buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_buffinit(lua_State *L, luaL_Buffer *B)
{
  B->L = L;
  B->p = B->buffer;
  B->lvl = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00475D10
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
// Address: 0x00475D80
// Name: errfile
// Source: json
//------------------------------------------------------------------------------
int __usercall errfile@<eax>(lua_State *L@<esi>, int fnameindex@<edi>, const char *what)
{
  int *v3; // eax
  const char *v4; // ebx
  const char *v5; // eax

  v3 = _errno();
  v4 = strerror(errnum: *v3);
  v5 = lua_tolstring(L, idx: fnameindex, len: nullptr);
  lua_pushfstring(L, fmt: "cannot %s %s: %s", what, v5 + 1, v4);
  lua_remove(L, idx: fnameindex);
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x00475DC0
// Name: int luaL_loadfile(struct lua_State __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_loadfile(lua_State *L, const char *filename)
{
  int v2; // edi
  _iobuf *v3; // eax
  int v4; // ebx
  int v5; // eax
  _iobuf *f; // eax
  int *v8; // eax
  const char *v9; // ebx
  const char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  int v13; // ebx
  int *v14; // eax
  const char *v15; // ebx
  const char *v16; // eax
  LoadF lf; // [esp+Ch] [ebp-208h] BYREF
  int readstatus; // [esp+220h] [ebp+Ch]

  v2 = lua_gettop(L) + 1;
  lf.extraline = 0;
  if ( filename != nullptr )
  {
    lua_pushfstring(L, fmt: "@%s", filename);
    v3 = fopen(file: filename, mode: "r");
    lf.f = v3;
    if ( v3 == nullptr )
    {
      v8 = _errno();
      v9 = strerror(errnum: *v8);
      v10 = lua_tolstring(L, idx: v2, len: nullptr);
      lua_pushfstring(L, fmt: "cannot %s %s: %s", "open", v10 + 1, v9);
      lua_remove(L, idx: v2);
      return 6;
    }
  }
  else
  {
    lua_pushlstring(L, s: "=stdin", len: 6u);
    v3 = __iob_func();
    lf.f = v3;
  }
  v4 = getc(stream: v3);
  if ( v4 == 35 )
  {
    lf.extraline = 1;
    while ( 1 )
    {
      v5 = getc(stream: lf.f);
      v4 = v5;
      if ( v5 == -1 )
        break;
      if ( v5 == 10 )
      {
        v4 = getc(stream: lf.f);
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    if ( v4 == 27 && lf.f != __iob_func() )
    {
      fclose(stream: lf.f);
      f = fopen(file: filename, mode: "rb");
      lf.f = f;
      if ( f == nullptr )
        return errfile(L, fnameindex: v2, what: "reopen");
      while ( 1 )
      {
        v11 = getc(stream: f);
        v4 = v11;
        if ( v11 == -1 || v11 == 27 )
          break;
        f = lf.f;
      }
      lf.extraline = 0;
    }
  }
  ungetc(ch: v4, stream: lf.f);
  v12 = lua_tolstring(L, idx: -1, len: nullptr);
  v13 = lua_load(
          L,
          reader: (const char *(__cdecl *)(lua_State *, void *, unsigned int *))getF,
          data: &lf,
          chunkname: v12);
  readstatus = ferror(stream: lf.f);
  if ( lf.f != __iob_func() )
    fclose(stream: lf.f);
  if ( readstatus != 0 )
  {
    lua_settop(L, idx: v2);
    v14 = _errno();
    v15 = strerror(errnum: *v14);
    v16 = lua_tolstring(L, idx: v2, len: nullptr);
    lua_pushfstring(L, fmt: "cannot %s %s: %s", "read", v16 + 1, v15);
    lua_remove(L, idx: v2);
    return 6;
  }
  else
  {
    lua_remove(L, idx: v2);
    return v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476000
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
// Address: 0x00476030
// Name: int luaL_loadbuffer(struct lua_State __near *,char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_loadbuffer(lua_State *L, const char *buff, unsigned int size, const char *name)
{
  LoadS ls; // [esp+0h] [ebp-8h] BYREF

  ls.s = buff;
  ls.size = size;
  return lua_load(
           L,
           reader: (const char *(__cdecl *)(lua_State *, void *, unsigned int *))getS,
           data: &ls,
           chunkname: name);
}

//------------------------------------------------------------------------------
// Address: 0x00476060
// Name: int luaL_loadstring(struct lua_State __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_loadstring(lua_State *L, const char *s)
{
  _DWORD data[2]; // [esp+4h] [ebp-8h] BYREF

  data[1] = strlen(s);
  data[0] = s;
  return lua_load(L, reader: (const char *(__cdecl *)(lua_State *, void *, unsigned int *))getS, data, chunkname: s);
}

//------------------------------------------------------------------------------
// Address: 0x004760A0
// Name: l_alloc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl l_alloc(void *ud, void *ptr, unsigned int osize, unsigned int nsize)
{
  if ( nsize != 0 )
    return _realloc_crt(ptr, size: nsize);
  free(pMem: ptr);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004760D0
// Name: panic
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn panic(lua_State *L)
{
  _iobuf *v1; // eax
  const char *v2; // [esp-4h] [ebp-4h]

  v2 = lua_tolstring(L, idx: -1, len: nullptr);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "PANIC: unprotected error in call to Lua API (%s)\n", v2);
}

//------------------------------------------------------------------------------
// Address: 0x00476100
// Name: struct lua_State __near * luaL_newstate(void)
// Source: json
//------------------------------------------------------------------------------
lua_State *__cdecl luaL_newstate()
{
  lua_State *result; // eax
  lua_State *v1; // esi

  result = lua_newstate(f: l_alloc, ud: nullptr);
  v1 = result;
  if ( result != nullptr )
  {
    lua_atpanic(L: result, panicf: (int (__cdecl *)(lua_State *))panic);
    return v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476130
// Name: int luaL_argerror(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaL_argerror(lua_State *L, int narg, const char *extramsg)
{
  const char *name; // eax
  lua_Debug ar; // [esp+4h] [ebp-64h] BYREF

  if ( lua_getstack(L, level: 0, &ar) == 0 )
    luaL_error(L, fmt: "bad argument #%d (%s)", narg, extramsg);
  lua_getinfo(L, what: "n", &ar);
  if ( strcmp(ar.namewhat, "method") == 0 && --narg == 0 )
    luaL_error(L, fmt: "calling '%s' on bad self (%s)", ar.name, extramsg);
  name = ar.name;
  if ( ar.name == nullptr )
  {
    name = "?";
    ar.name = "?";
  }
  luaL_error(L, fmt: "bad argument #%d to '%s' (%s)", narg, name, extramsg);
}

//------------------------------------------------------------------------------
// Address: 0x00476200
// Name: void __near * luaL_checkudata(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_checkudata(lua_State *L, int ud, const char *tname)
{
  int v3; // ebx
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax

  v3 = lua_touserdata(L, idx: ud);
  if ( v3 == 0
    || lua_getmetatable(L, objindex: ud) == 0
    || (lua_getfield(L, idx: -10000, k: tname), lua_rawequal(L, index1: -1, index2: -2) == 0) )
  {
    v5 = lua_type(L, idx: ud);
    v6 = lua_typename(L, t: v5);
    v7 = lua_pushfstring(L, fmt: "%s expected, got %s", tname, v6);
    luaL_argerror(L, narg: ud, extramsg: v7);
  }
  lua_settop(L, idx: -3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00476290
// Name: void luaL_checktype(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_checktype(lua_State *L, int narg, int t)
{
  const char *v3; // ebx
  int v4; // eax
  const char *v5; // eax
  const char *v6; // eax

  if ( lua_type(L, idx: narg) != t )
  {
    v3 = lua_typename(L, t);
    v4 = lua_type(L, idx: narg);
    v5 = lua_typename(L, t: v4);
    v6 = lua_pushfstring(L, fmt: "%s expected, got %s", v3, v5);
    luaL_argerror(L, narg, extramsg: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004762F0
// Name: void luaL_checkany(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_checkany(lua_State *L, int narg)
{
  if ( lua_type(L, idx: narg) == -1 )
    luaL_argerror(L, narg, extramsg: "value expected");
}

//------------------------------------------------------------------------------
// Address: 0x00476320
// Name: char const __near * luaL_checklstring(struct lua_State __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl luaL_checklstring(lua_State *L, int narg, unsigned int *len)
{
  const char *result; // eax
  int v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // [esp+Ch] [ebp-4h]

  result = lua_tolstring(L, idx: narg, len);
  if ( result == nullptr )
  {
    v7 = lua_typename(L, t: 4);
    v4 = lua_type(L, idx: narg);
    v5 = lua_typename(L, t: v4);
    v6 = lua_pushfstring(L, fmt: "%s expected, got %s", v7, v5);
    luaL_argerror(L, narg, extramsg: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476380
// Name: char const __near * luaL_optlstring(struct lua_State __near *,int,char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl luaL_optlstring(lua_State *L, int narg, const char *def, unsigned int *len)
{
  const char *result; // eax

  if ( lua_type(L, idx: narg) > 0 )
    return luaL_checklstring(L, narg, len);
  result = def;
  if ( len != nullptr )
  {
    if ( def != nullptr )
      *len = strlen(def);
    else
      *len = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004763E0
// Name: double luaL_checknumber(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl luaL_checknumber(lua_State *L, int narg)
{
  double result; // st7
  const char *v3; // ebx
  int v4; // eax
  const char *v5; // eax
  const char *v6; // eax

  result = lua_tonumber(L, idx: narg);
  if ( result == 0.0 && lua_isnumber(L, idx: narg) == 0 )
  {
    v3 = lua_typename(L, t: 3);
    v4 = lua_type(L, idx: narg);
    v5 = lua_typename(L, t: v4);
    v6 = lua_pushfstring(L, fmt: "%s expected, got %s", v3, v5);
    luaL_argerror(L, narg, extramsg: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476460
// Name: double luaL_optnumber(struct lua_State __near *,int,double)
// Source: json
//------------------------------------------------------------------------------
double __cdecl luaL_optnumber(lua_State *L, int narg, long double def)
{
  if ( lua_type(L, idx: narg) > 0 )
    return luaL_checknumber(L, narg);
  else
    return def;
}

//------------------------------------------------------------------------------
// Address: 0x004764A0
// Name: int luaL_checkinteger(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__cdecl luaL_checkinteger(lua_State *L, int narg)
{
  lua_TValue *result; // eax
  int v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // [esp+Ch] [ebp-4h]

  result = lua_tointeger(L, idx: narg);
  if ( result == nullptr )
  {
    if ( lua_isnumber(L, idx: narg) == 0 )
    {
      v6 = lua_typename(L, t: 3);
      v3 = lua_type(L, idx: narg);
      v4 = lua_typename(L, t: v3);
      v5 = lua_pushfstring(L, fmt: "%s expected, got %s", v6, v4);
      luaL_argerror(L, narg, extramsg: v5);
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476510
// Name: int luaL_optinteger(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__cdecl luaL_optinteger(lua_State *L, int narg, int def)
{
  if ( lua_type(L, idx: narg) > 0 )
    return luaL_checkinteger(L, narg);
  else
    return (lua_TValue *)def;
}

//------------------------------------------------------------------------------
// Address: 0x00476540
// Name: void luaL_openlib(struct lua_State __near *,char const __near *,struct luaL_Reg const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_openlib(lua_State *L, char *libname, const luaL_Reg *l, const char *nup)
{
  const luaL_Reg *v4; // edi
  int v5; // ebx
  const luaL_Reg *i; // eax
  int v7; // ebx
  int v8; // ebx
  const char *libnamea; // [esp+18h] [ebp+Ch]
  const luaL_Reg *la; // [esp+1Ch] [ebp+10h]

  v4 = l;
  if ( libname != nullptr )
  {
    v5 = 0;
    for ( i = l; i->name != nullptr; ++v5 )
      ++i;
    luaL_findtable(L, idx: -10000, fname: "_LOADED", szhint: v5);
    lua_getfield(L, idx: -1, k: libname);
    if ( lua_type(L, idx: -1) != 5 )
    {
      lua_settop(L, idx: -2);
      if ( luaL_findtable(L, idx: -10002, fname: libname, szhint: v5) != nullptr )
        luaL_error(L, fmt: "name conflict for module '%s'", libname);
      lua_pushvalue(L, idx: -1);
      lua_setfield(L, idx: -3, k: libname);
    }
    lua_remove(L, idx: -2);
    v7 = (int)nup;
    lua_insert(L, idx: -1 - (_DWORD)nup);
  }
  else
  {
    v7 = (int)nup;
  }
  if ( l->name != nullptr )
  {
    la = (const luaL_Reg *)(-2 - v7);
    do
    {
      if ( v7 > 0 )
      {
        v8 = -v7;
        libnamea = nup;
        do
        {
          lua_pushvalue(L, idx: v8);
          --libnamea;
        }
        while ( libnamea != nullptr );
        v7 = (int)nup;
      }
      lua_pushcclosure(L, fn: v4->func, n: v7);
      lua_setfield(L, idx: (int)la, k: v4->name);
      ++v4;
    }
    while ( v4->name != nullptr );
  }
  lua_settop(L, idx: -1 - v7);
}

//------------------------------------------------------------------------------
// Address: 0x00476660
// Name: char const __near * luaL_gsub(struct lua_State __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl luaL_gsub(lua_State *L, char *s, char *p, const char *r)
{
  const char *v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  luaL_Buffer b; // [esp+4h] [ebp-210h] BYREF
  unsigned int l; // [esp+210h] [ebp-4h]

  l = strlen(p);
  v4 = s;
  b.L = L;
  b.p = b.buffer;
  b.lvl = 0;
  strstr(str1: (unsigned __int8 *)s, str2: (unsigned __int8 *)p);
  v6 = v5;
  if ( v5 != 0 )
  {
    do
    {
      luaL_addlstring(B: &b, s: v4, l: v6 - (_DWORD)v4);
      luaL_addlstring(B: &b, s: r, l: strlen(r));
      v4 = (const char *)(v6 + l);
      strstr(str1: (unsigned __int8 *)(v6 + l), str2: (unsigned __int8 *)p);
      v6 = v7;
    }
    while ( v7 != 0 );
  }
  luaL_addlstring(B: &b, s: v4, l: strlen(v4));
  if ( b.p != b.buffer )
  {
    lua_pushlstring(L: b.L, s: b.buffer, len: b.p - b.buffer);
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: b.L, n: b.lvl);
  b.lvl = 1;
  return lua_tolstring(L, idx: -1, len: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00476790
// Name: int luaL_checkoption(struct lua_State __near *,int,char const __near *,char const __near * const __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaL_checkoption(lua_State *L, int narg, const char *def, const char **lst)
{
  const char *v4; // esi
  const char *v5; // eax
  const char *v6; // esi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // ecx
  int result; // eax
  const char *v12; // eax

  v4 = def;
  if ( def != nullptr )
  {
    if ( lua_type(L, idx: narg) > 0 )
      v4 = luaL_checklstring(L, narg, len: nullptr);
  }
  else
  {
    v5 = lua_tolstring(L, idx: narg, len: nullptr);
    if ( v5 == nullptr )
    {
      v6 = lua_typename(L, t: 4);
      v7 = lua_type(L, idx: narg);
      v8 = lua_typename(L, t: v7);
      v9 = lua_pushfstring(L, fmt: "%s expected, got %s", v6, v8);
      luaL_argerror(L, narg, extramsg: v9);
    }
    v4 = v5;
  }
  v10 = *lst;
  result = 0;
  if ( *lst == nullptr )
  {
LABEL_10:
    v12 = lua_pushfstring(L, fmt: "invalid option '%s'", v4);
    luaL_argerror(L, narg, extramsg: v12);
  }
  while ( strcmp(v10, v4) != 0 )
  {
    v10 = lst[++result];
    if ( v10 == nullptr )
      goto LABEL_10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476880
// Name: void luaL_register(struct lua_State __near *,char const __near *,struct luaL_Reg const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_register(lua_State *L, char *libname, const luaL_Reg *l)
{
  luaL_openlib(L, libname, l, nup: nullptr);
}
