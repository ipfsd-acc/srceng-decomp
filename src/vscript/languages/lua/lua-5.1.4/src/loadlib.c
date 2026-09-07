// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/loadlib.c
// Functions: 22
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100116C0
// Name: setprogdir
// Source: json
//------------------------------------------------------------------------------
void __usercall setprogdir(GCObject *L@<edi>)
{
  DWORD ModuleFileNameA; // eax
  _BYTE *v2; // eax
  lua_TValue *v3; // esi
  char *v4; // eax
  char buff[264]; // [esp+8h] [ebp-108h] BYREF

  ModuleFileNameA = GetModuleFileNameA(hModule: nullptr, lpFilename: buff, nSize: 0x105u);
  if ( ModuleFileNameA == 0
    || ModuleFileNameA == 261
    || (strrchr(string: (unsigned __int8 *)buff, chr: 0x5Cu), v2 == nullptr) )
  {
    luaL_error((lua_State *)L, fmt: "unable to get ModuleFileName");
  }
  *v2 = 0;
  v3 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v3->tt == 4 )
    goto LABEL_9;
  v4 = (char *)luaV_tostring((lua_State *)L, obj: v3);
  if ( v4 != nullptr )
  {
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v3 = (lua_TValue *)(L->ts.tsv.hash - 16);
LABEL_9:
    v4 = (char *)(v3->value.b + 24);
  }
  luaL_gsub(s: v4, (lua_State *)L, p: "!", r: buff);
  lua_remove((lua_State *)L, idx: -2);
}

//------------------------------------------------------------------------------
// Address: 0x10011780
// Name: ll_load
// Source: json
//------------------------------------------------------------------------------
HMODULE __usercall ll_load@<eax>(lua_State *L@<ecx>, const char *path@<eax>)
{
  HMODULE result; // eax
  DWORD LastError; // ebx
  char Buffer[128]; // [esp+8h] [ebp-80h] BYREF

  result = LoadLibraryA(lpLibFileName: path);
  if ( result == nullptr )
  {
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1200u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0,
           lpBuffer: Buffer,
           nSize: 0x80u,
           Arguments: nullptr) != 0 )
      lua_pushstring(L, s: Buffer);
    else
      lua_pushfstring(L, fmt: "system error %d\n", LastError);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100117F0
// Name: ll_register
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall ll_register@<eax>(GCObject *L@<eax>, const char *path)
{
  lua_TValue *v3; // eax
  CallInfo *ci; // eax
  GCObject *gc; // ebx
  global_State *l_G; // edi
  GCObject *v8; // eax
  unsigned __int8 v9; // dl
  lua_TValue *k; // ecx
  lua_TValue *upvalue; // ebx
  lua_TValue *v12; // edi
  TString *v13; // eax
  lua_TValue *v14; // eax
  lua_TValue *v15; // [esp-10h] [ebp-30h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  lua_pushfstring((lua_State *)L, fmt: "%s%s", "LOADLIB: ", path);
  luaV_gettable(
    (lua_State *)L,
    t: (const lua_TValue *)(L->ts.tsv.len + 96),
    key: (lua_TValue *)(L->ts.tsv.hash - 16),
    val: (lua_TValue *)(L->ts.tsv.hash - 16));
  v3 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v3 == &luaO_nilobject_ || v3->tt != 0 )
  {
    if ( v3->tt == 2 )
    {
      return (lua_TValue *)v3->value.b;
    }
    else if ( v3->tt == 7 )
    {
      return (lua_TValue *)(v3->value.b + 24);
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    L->ts.tsv.hash = (unsigned int)v3;
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    ci = L->th.ci;
    if ( ci == L->th.base_ci )
      gc = L->th.l_gt.value.gc;
    else
      gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
    l_G = L->th.l_G;
    v8 = (GCObject *)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 28u);
    if ( v8 == nullptr )
      luaD_throw((lua_State *)L, errcode: 4);
    l_G->totalbytes += 28;
    v9 = *(_BYTE *)(L->ts.tsv.len + 20);
    v8->ts.tsv.keyhash = (unsigned int)gc;
    v8->ts.tsv.len = 4;
    v8->ts.tsv.hash = 0;
    v8->gch.marked = v9 & 3;
    v8->gch.tt = 7;
    v8->ts.dummy.l = **(_DWORD **)(L->ts.tsv.len + 112);
    **(_DWORD **)(L->ts.tsv.len + 112) = v8;
    k = L->p.k;
    k->value.b = (int)v8;
    k->tt = 7;
    L->ts.tsv.hash += 16;
    upvalue = v8->cl.c.upvalue;
    v8->cl.c.upvalue[0].value.b = 0;
    v12 = (lua_TValue *)(L->ts.tsv.len + 96);
    v13 = luaS_newlstr((lua_State *)L, str: "_LOADLIB", l: 8u);
    v15 = L->p.k;
    key.value.b = (int)v13;
    key.tt = 4;
    luaV_gettable((lua_State *)L, t: v12, &key, val: v15);
    L->ts.tsv.hash += 16;
    lua_setmetatable((lua_State *)L, objindex: -2);
    lua_pushfstring((lua_State *)L, fmt: "%s%s", "LOADLIB: ", path);
    v14 = L->p.k;
    v14->value.b = v14[-2].value.b;
    *(&v14->value.b + 1) = *(&v14[-2].value.b + 1);
    v14->tt = v14[-2].tt;
    L->ts.tsv.hash += 16;
    luaV_settable(
      (lua_State *)L,
      t: (const lua_TValue *)(L->ts.tsv.len + 96),
      key: (lua_TValue *)(L->ts.tsv.hash - 32),
      val: (lua_TValue *)(L->ts.tsv.hash - 16));
    L->ts.tsv.hash -= 32;
    return upvalue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100119A0
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
// Address: 0x100119D0
// Name: ll_loadfunc
// Source: json
//------------------------------------------------------------------------------
int __usercall ll_loadfunc@<eax>(GCObject *L@<eax>, const char *path, const char *sym)
{
  HMODULE *v4; // edi
  HMODULE v5; // eax
  int (__cdecl *ProcAddress)(lua_State *); // eax
  DWORD LastError; // edi
  char Buffer[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (HMODULE *)ll_register(L, path);
  if ( *v4 == nullptr )
  {
    v5 = ll_load((lua_State *)L, path);
    *v4 = v5;
    if ( v5 == nullptr )
      return 1;
  }
  ProcAddress = (int (__cdecl *)(lua_State *))GetProcAddress(hModule: *v4, lpProcName: sym);
  if ( ProcAddress != nullptr )
  {
    lua_pushcclosure((lua_State *)L, fn: ProcAddress, n: 0);
    return 0;
  }
  else
  {
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1200u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0,
           lpBuffer: Buffer,
           nSize: 0x80u,
           Arguments: nullptr) != 0 )
      lua_pushstring((lua_State *)L, s: Buffer);
    else
      lua_pushfstring((lua_State *)L, fmt: "system error %d\n", LastError);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011A90
// Name: ll_loadlib
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_loadlib(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // esi
  int v8; // esi
  lua_TValue *v9; // eax
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // edi
  const char *v15; // eax
  char *path; // [esp+Ch] [ebp-8h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  path = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v7 >= L->ts.tsv.hash )
    v7 = &luaO_nilobject_;
  if ( v7->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v7) == 0 )
    {
LABEL_25:
      v9 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
      if ( (unsigned int)v9 >= L->ts.tsv.hash
        || v9 == &luaO_nilobject_
        || (v10 = *(_DWORD *)(L->ts.tsv.keyhash + 24)) == -1 )
      {
        v11 = "no value";
      }
      else
      {
        v11 = luaT_typenames[v10];
      }
      v12 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v11);
      luaL_argerror((lua_State *)L, extramsg: v12, narg: 2);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
    if ( (unsigned int)v7 >= L->ts.tsv.hash )
      v7 = &luaO_nilobject_;
  }
  v8 = v7->value.b;
  if ( v8 == -24 )
    goto LABEL_25;
  v13 = ll_loadfunc(L, path, sym: (const char *)(v8 + 24));
  if ( v13 == 0 )
    return 1;
  *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  L->ts.tsv.hash += 16;
  lua_insert((lua_State *)L, idx: -2);
  v15 = "open";
  if ( v13 != 1 )
    v15 = "init";
  lua_pushstring((lua_State *)L, s: v15);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10011C40
// Name: pushnexttemplate
// Source: json
//------------------------------------------------------------------------------
const char *__usercall pushnexttemplate@<eax>(char *path@<eax>, GCObject *L)
{
  unsigned __int8 *v2; // esi
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi
  lua_TValue *k; // ebx

  v2 = (unsigned __int8 *)path;
  if ( *path == 59 )
  {
    do
      ++v2;
    while ( *v2 == 59 );
  }
  if ( *v2 == 0 )
    return nullptr;
  strchr(string: v2, chr: 0x3Bu);
  v5 = v4;
  if ( v4 == nullptr )
    v5 = &v2[strlen((const char *)v2)];
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  k = L->p.k;
  k->value.b = (int)luaS_newlstr((lua_State *)L, str: (const char *)v2, l: v5 - v2);
  k->tt = 4;
  L->ts.tsv.hash += 16;
  return (const char *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10011CD0
// Name: findfile
// Source: json
//------------------------------------------------------------------------------
const char *__usercall findfile@<eax>(GCObject *L@<edi>, char *name, const char *pname)
{
  TString *v3; // eax
  lua_TValue *v4; // esi
  char *v5; // ebx
  lua_TValue *v6; // esi
  char *v7; // ebx
  lua_TValue *v8; // esi
  char *v9; // eax
  const char *v10; // eax
  lua_TValue *v11; // ecx
  const char *v12; // esi
  lua_TValue *v13; // eax
  int *v14; // ecx
  _iobuf *v15; // eax
  lua_TValue *v16; // ecx
  lua_TValue *v17; // eax
  int *v18; // ecx
  global_State *l_G; // eax
  lua_TValue *k; // [esp-10h] [ebp-28h]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF
  const char *namea; // [esp+20h] [ebp+8h]

  namea = luaL_gsub(s: name, (lua_State *)L, p: ".", r: "\\");
  L->th.env.value.b = *(_DWORD *)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 12);
  L->th.env.tt = 5;
  v3 = luaS_newlstr((lua_State *)L, str: pname, l: strlen(pname));
  k = L->p.k;
  key.value.b = (int)v3;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: &L->th.env, &key, val: k);
  L->ts.tsv.hash += 16;
  v4 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v4->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v4) == 0 )
      goto LABEL_7;
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v4 = (lua_TValue *)(L->ts.tsv.hash - 16);
  }
  v5 = (char *)(v4->value.b + 24);
  if ( v4->value.b == -24 )
LABEL_7:
    luaL_error((lua_State *)L, fmt: "'package.%s' must be a string", pname);
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  v6 = L->p.k;
  v6->value.b = (int)luaS_newlstr((lua_State *)L, str: Ptr, l: 0);
  v6->tt = 4;
  L->ts.tsv.hash += 16;
  v7 = (char *)pushnexttemplate(path: v5, L);
  if ( v7 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v8 = (lua_TValue *)(L->ts.tsv.hash - 16);
    if ( v8->tt != 4 )
    {
      v9 = (char *)luaV_tostring((lua_State *)L, obj: v8);
      if ( v9 == nullptr )
        goto LABEL_17;
      if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
        luaC_step(L);
      v8 = (lua_TValue *)(L->ts.tsv.hash - 16);
    }
    v9 = (char *)(v8->value.b + 24);
LABEL_17:
    v10 = luaL_gsub(s: v9, (lua_State *)L, p: "?", r: namea);
    v11 = L->p.k;
    v12 = v10;
    v13 = v11 - 1;
    if ( (unsigned int)v11 >= 0x10 )
    {
      v14 = (int *)&v11[-2];
      do
      {
        *v14 = v13->value.b;
        v14[1] = *(&v13->value.b + 1);
        v14[2] = v14[6];
        ++v13;
        v14 += 4;
      }
      while ( (unsigned int)v13 < L->ts.tsv.hash );
    }
    L->ts.tsv.hash -= 16;
    v15 = fopen(file: v12, mode: "r");
    if ( v15 != nullptr )
      break;
    lua_pushfstring((lua_State *)L, fmt: "\n\tno file '%s'", v12);
    v16 = L->p.k;
    v17 = v16 - 1;
    if ( (unsigned int)v16 >= 0x10 )
    {
      v18 = (int *)&v16[-2];
      do
      {
        *v18 = v17->value.b;
        v18[1] = *(&v17->value.b + 1);
        v18[2] = v18[6];
        ++v17;
        v18 += 4;
      }
      while ( (unsigned int)v17 < L->ts.tsv.hash );
    }
    l_G = L->th.l_G;
    L->ts.tsv.hash -= 16;
    if ( l_G->totalbytes >= l_G->GCthreshold )
      luaC_step(L);
    luaV_concat((lua_State *)L, total: 2, last: ((signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4) - 1);
    L->ts.tsv.hash -= 16;
    v7 = (char *)pushnexttemplate(path: v7, L);
    if ( v7 == nullptr )
      return nullptr;
  }
  fclose(stream: v15);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10011F10
// Name: loaderror
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn loaderror(GCObject *L@<edi>, const char *filename)
{
  lua_TValue *v2; // esi
  const char *v3; // ebx
  lua_TValue *array; // esi
  const char *v5; // eax

  v2 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v2->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v2) == 0 )
    {
      v3 = nullptr;
      goto LABEL_8;
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v2 = (lua_TValue *)(L->ts.tsv.hash - 16);
  }
  v3 = (const char *)(v2->value.b + 24);
LABEL_8:
  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    v5 = (const char *)luaV_tostring((lua_State *)L, obj: array);
    if ( v5 == nullptr )
      goto LABEL_17;
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v5 = (const char *)(array->value.b + 24);
LABEL_17:
  luaL_error((lua_State *)L, fmt: "error loading module '%s' from file '%s':\n\t%s", v5, filename, v3);
}

//------------------------------------------------------------------------------
// Address: 0x10011FB0
// Name: loader_Lua
// Source: json
//------------------------------------------------------------------------------
int __cdecl loader_Lua(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // esi

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  if ( b == -24 )
    goto LABEL_10;
  v7 = findfile(L, name: (char *)(b + 24), pname: "path");
  v8 = v7;
  if ( v7 != nullptr && luaL_loadfile((lua_State *)L, filename: v7) != 0 )
    loaderror(L, filename: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012090
// Name: mkfuncname
// Source: json
//------------------------------------------------------------------------------
const char *__usercall mkfuncname@<eax>(lua_State *L@<esi>, char *modname@<eax>)
{
  char *v2; // edi
  int v3; // eax
  const char *v4; // eax
  const char *result; // eax
  lua_TValue *top; // edx
  lua_TValue *v7; // ecx
  int *v8; // edx

  v2 = modname;
  strchr(string: (unsigned __int8 *)modname, chr: 0x2Du);
  if ( v3 != 0 )
    v2 = (char *)(v3 + 1);
  v4 = luaL_gsub(s: v2, L, p: ".", r: "_");
  result = lua_pushfstring(L, fmt: "luaopen_%s", v4);
  top = L->top;
  v7 = top - 1;
  if ( (unsigned int)top >= 0x10 )
  {
    v8 = (int *)&top[-2];
    do
    {
      *v8 = v7->value.b;
      v8[1] = *(&v7->value.b + 1);
      v8[2] = v8[6];
      ++v7;
      v8 += 4;
    }
    while ( v7 < L->top );
  }
  --L->top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012100
// Name: loader_C
// Source: json
//------------------------------------------------------------------------------
int __cdecl loader_C(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // edi
  const char *v8; // eax
  char *name; // [esp+Ch] [ebp-4h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  name = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = findfile(L, name, pname: "cpath");
  if ( v7 != nullptr )
  {
    v8 = mkfuncname((lua_State *)L, modname: name);
    if ( ll_loadfunc(L, path: v7, sym: v8) != 0 )
      loaderror(L, filename: v7);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100121F0
// Name: loader_Croot
// Source: json
//------------------------------------------------------------------------------
void __cdecl loader_Croot(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // esi
  lua_TValue *k; // edi
  lua_TValue *v10; // esi
  char *v11; // esi
  const char *v12; // edi
  const char *v13; // eax
  int v14; // eax
  unsigned __int8 *string; // [esp+10h] [ebp-4h]

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  string = (unsigned __int8 *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  strchr(string, chr: 0x2Eu);
  v8 = v7;
  if ( v7 != 0 )
  {
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    k = L->p.k;
    k->value.b = (int)luaS_newlstr((lua_State *)L, str: (const char *)string, l: v8 - (_DWORD)string);
    k->tt = 4;
    L->ts.tsv.hash += 16;
    v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
    if ( v10->tt != 4 )
    {
      if ( luaV_tostring((lua_State *)L, obj: v10) == 0 )
      {
        v11 = nullptr;
LABEL_26:
        v12 = findfile(L, name: v11, pname: "cpath");
        if ( v12 != nullptr )
        {
          v13 = mkfuncname((lua_State *)L, modname: (char *)string);
          v14 = ll_loadfunc(L, path: v12, sym: v13);
          if ( v14 != 0 )
          {
            if ( v14 != 2 )
              loaderror(L, filename: v12);
            lua_pushfstring((lua_State *)L, fmt: "\n\tno module '%s' in file '%s'", (const char *)string, v12);
          }
        }
        return;
      }
      if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
        luaC_step(L);
      v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
    }
    v11 = (char *)(v10->value.b + 24);
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012390
// Name: loader_preload
// Source: json
//------------------------------------------------------------------------------
int __cdecl loader_preload(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  TString *v7; // eax
  lua_TValue *v8; // eax
  const lua_TValue *v9; // esi
  lua_TValue *v10; // eax
  lua_TValue *k; // [esp-4h] [ebp-24h]
  lua_TValue *v13; // [esp-4h] [ebp-24h]
  char *str; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  str = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  L->th.env.value.b = *(_DWORD *)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 12);
  L->th.env.tt = 5;
  v7 = luaS_newlstr((lua_State *)L, str: "preload", l: 7u);
  k = L->p.k;
  key.value.b = (int)v7;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: &L->th.env, &key, val: k);
  L->ts.tsv.hash += 16;
  v8 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v8 == &luaO_nilobject_ || v8->tt != 5 )
    luaL_error((lua_State *)L, fmt: "'package.preload' must be a table");
  v9 = (const lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str, l: strlen(str));
  v13 = L->p.k;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v9, &key, val: v13);
  L->ts.tsv.hash += 16;
  v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v10 != &luaO_nilobject_ && v10->tt == 0 )
    lua_pushfstring((lua_State *)L, fmt: "\n\tno field package.preload['%s']", str);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012520
// Name: ll_require
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_require(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  global_State *l_G; // esi
  TString *v8; // eax
  lua_TValue *v9; // eax
  lua_TValue *v10; // eax
  const lua_TValue *v11; // esi
  TString *v12; // eax
  lua_TValue *v13; // eax
  int v14; // ecx
  int v15; // ecx
  const int *gc; // eax
  TString *v17; // eax
  lua_TValue *v18; // eax
  lua_TValue *v19; // esi
  lua_TValue *v20; // edi
  lua_TValue *v21; // esi
  lua_TValue *v22; // esi
  const char *v23; // esi
  lua_TValue *v24; // esi
  lua_TValue *v25; // eax
  int v26; // ecx
  lua_TValue *v27; // eax
  lua_TValue *v28; // eax
  lua_TValue *v29; // eax
  const lua_TValue *v30; // esi
  lua_TValue *v31; // esi
  lua_TValue *v32; // ecx
  const lua_TValue *v33; // esi
  TString *v34; // eax
  const lua_TValue *v35; // esi
  lua_TValue *v36; // eax
  const int *v37; // ecx
  lua_TValue *v38; // eax
  lua_TValue *v39; // eax
  const lua_TValue *v40; // esi
  TString *v41; // eax
  lua_TValue *k; // [esp-4h] [ebp-2Ch]
  lua_TValue *v44; // [esp-4h] [ebp-2Ch]
  lua_TValue *v45; // [esp-4h] [ebp-2Ch]
  lua_TValue *v46; // [esp-4h] [ebp-2Ch]
  lua_TValue *v47; // [esp-4h] [ebp-2Ch]
  lua_TValue *v48; // [esp-4h] [ebp-2Ch]
  lua_TValue *v49; // [esp-4h] [ebp-2Ch]
  char *str; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  unsigned int l; // [esp+14h] [ebp-14h]
  unsigned int la; // [esp+14h] [ebp-14h]
  lua_TValue key; // [esp+18h] [ebp-10h] BYREF

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  str = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  for ( ; L->ts.tsv.hash < L->ts.tsv.keyhash + 16; L->ts.tsv.hash += 16 )
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  l_G = L->th.l_G;
  L->ts.tsv.hash = L->ts.tsv.keyhash + 16;
  v8 = luaS_newlstr((lua_State *)L, str: "_LOADED", l: 7u);
  k = L->p.k;
  key.value.b = (int)v8;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: &l_G->l_registry, &key, val: k);
  v9 = L->h.array;
  L->ts.tsv.hash += 16;
  v10 = v9 + 1;
  v11 = &luaO_nilobject_;
  if ( (unsigned int)v10 < L->ts.tsv.hash )
    v11 = v10;
  v12 = luaS_newlstr((lua_State *)L, str, l: strlen(str));
  v44 = L->p.k;
  key.value.b = (int)v12;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v11, &key, val: v44);
  L->ts.tsv.hash += 16;
  v13 = L->p.k;
  v14 = v13[-1].tt;
  if ( v14 != 0 && (v14 != 1 || v13[-1].value.b != 0) )
  {
    v15 = v14 - 2;
    if ( v15 != 0 )
    {
      if ( v15 == 5 )
        gc = (const int *)(v13[-1].value.b + 24);
      else
        gc = nullptr;
    }
    else
    {
      gc = (const int *)v13[-1].value.gc;
    }
    if ( gc == &sentinel_ )
      luaL_error((lua_State *)L, fmt: "loop or previous error loading module '%s'", str);
    return 1;
  }
  L->th.env.value.b = *(_DWORD *)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 12);
  L->th.env.tt = 5;
  v17 = luaS_newlstr((lua_State *)L, str: "loaders", l: 7u);
  v45 = L->p.k;
  key.value.b = (int)v17;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: &L->th.env, &key, val: v45);
  L->ts.tsv.hash += 16;
  v18 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v18 == &luaO_nilobject_ || v18->tt != 5 )
    luaL_error((lua_State *)L, fmt: "'package.loaders' must be a table");
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  v19 = L->p.k;
  v19->value.b = (int)luaS_newlstr((lua_State *)L, str: Ptr, l: 0);
  v19->tt = 4;
  L->ts.tsv.hash += 16;
  for ( i = 1; ; ++i )
  {
    while ( 1 )
    {
      v20 = L->p.k;
      *v20 = *luaH_getnum(t: (Table *)v20[-2].value.gc, key: i);
      L->ts.tsv.hash += 16;
      v21 = L->p.k;
      if ( &v21[-1] != &luaO_nilobject_ && v21[-1].tt == 0 )
      {
        v22 = v21 - 2;
        if ( v22->tt != 4 )
        {
          if ( luaV_tostring((lua_State *)L, obj: v22) == 0 )
          {
            v23 = nullptr;
            goto LABEL_45;
          }
          if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
            luaC_step(L);
          v22 = (lua_TValue *)(L->ts.tsv.hash - 32);
        }
        v23 = (const char *)(v22->value.b + 24);
LABEL_45:
        luaL_error((lua_State *)L, fmt: "module '%s' not found:%s", str, v23);
      }
      if ( str != nullptr )
      {
        l = strlen(str);
        if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
          luaC_step(L);
        v24 = L->p.k;
        v24->value.b = (int)luaS_newlstr((lua_State *)L, str, l);
        v24->tt = 4;
      }
      else
      {
        *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
      }
      L->ts.tsv.hash += 16;
      luaD_call((lua_State *)L, func: (lua_TValue *)(L->ts.tsv.hash - 32), nResults: 1);
      v25 = (lua_TValue *)(L->ts.tsv.hash - 16);
      if ( v25 != &luaO_nilobject_ )
        break;
LABEL_59:
      ++i;
      L->ts.tsv.hash = (unsigned int)v25;
    }
    if ( v25->tt == 6 )
      break;
    if ( v25 == &luaO_nilobject_ )
      goto LABEL_59;
    v26 = v25->tt;
    if ( v26 != 4 && v26 != 3 )
      goto LABEL_59;
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    luaV_concat((lua_State *)L, total: 2, last: ((signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4) - 1);
    L->ts.tsv.hash -= 16;
  }
  v27 = L->p.k;
  v27->value.b = (int)&sentinel_;
  v27->tt = 2;
  v28 = L->h.array;
  L->ts.tsv.hash += 16;
  v29 = v28 + 1;
  v30 = &luaO_nilobject_;
  if ( (unsigned int)v29 < L->ts.tsv.hash )
    v30 = v29;
  key.value.b = (int)luaS_newlstr((lua_State *)L, str, l: strlen(str));
  v46 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v30, &key, val: v46);
  L->ts.tsv.hash -= 16;
  if ( str != nullptr )
  {
    la = strlen(str);
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v31 = L->p.k;
    v31->value.b = (int)luaS_newlstr((lua_State *)L, str, l: la);
    v31->tt = 4;
  }
  else
  {
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  }
  L->ts.tsv.hash += 16;
  luaD_call((lua_State *)L, func: (lua_TValue *)(L->ts.tsv.hash - 32), nResults: 1);
  v32 = L->p.k;
  if ( &v32[-1] == &luaO_nilobject_ || v32[-1].tt != 0 )
  {
    v33 = &luaO_nilobject_;
    if ( L->ts.tsv.keyhash + 16 < (unsigned int)v32 )
      v33 = (const lua_TValue *)(L->ts.tsv.keyhash + 16);
    v34 = luaS_newlstr((lua_State *)L, str, l: strlen(str));
    v47 = (lua_TValue *)(L->ts.tsv.hash - 16);
    key.value.b = (int)v34;
    key.tt = 4;
    luaV_settable((lua_State *)L, t: v33, &key, val: v47);
    L->ts.tsv.hash -= 16;
  }
  v35 = &luaO_nilobject_;
  if ( L->ts.tsv.keyhash + 16 < L->ts.tsv.hash )
    v35 = (const lua_TValue *)(L->ts.tsv.keyhash + 16);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str, l: strlen(str));
  v48 = L->p.k;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v35, &key, val: v48);
  L->ts.tsv.hash += 16;
  v36 = L->p.k;
  if ( v36[-1].tt == 2 )
  {
    v37 = (const int *)v36[-1].value.gc;
  }
  else if ( v36[-1].tt == 7 )
  {
    v37 = (const int *)(v36[-1].value.b + 24);
  }
  else
  {
    v37 = nullptr;
  }
  if ( v37 == &sentinel_ )
  {
    v36->value.b = 1;
    v36->tt = 1;
    L->ts.tsv.hash += 16;
    *L->p.k = *(lua_TValue *)(L->ts.tsv.hash - 16);
    v38 = L->h.array;
    L->ts.tsv.hash += 16;
    v39 = v38 + 1;
    v40 = &luaO_nilobject_;
    if ( (unsigned int)v39 < L->ts.tsv.hash )
      v40 = v39;
    v41 = luaS_newlstr((lua_State *)L, str, l: strlen(str));
    v49 = (lua_TValue *)(L->ts.tsv.hash - 16);
    key.value.b = (int)v41;
    key.tt = 4;
    luaV_settable((lua_State *)L, t: v40, &key, val: v49);
    L->ts.tsv.hash -= 16;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012B20
// Name: setfenv
// Source: json
//------------------------------------------------------------------------------
void __usercall setfenv(lua_State *L@<eax>)
{
  lua_TValue *top; // eax
  lua_TValue *v3; // eax
  lua_Debug ar; // [esp+8h] [ebp-68h] BYREF

  if ( lua_getstack(L, level: 1, &ar) == 0
    || lua_getinfo(L, &ar, what: "f") == 0
    || (top = L->top)[-1].tt == 6 && *(_BYTE *)(top[-1].value.b + 6) != 0 )
  {
    luaL_error(L, fmt: "'module' not called from a Lua function");
  }
  v3 = L->top;
  v3->value.b = v3[-2].value.b;
  *(&v3->value.b + 1) = *(&v3[-2].value.b + 1);
  v3->tt = v3[-2].tt;
  ++L->top;
  lua_setfenv(L, idx: -2);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10012BA0
// Name: dooptions
// Source: json
//------------------------------------------------------------------------------
void __usercall dooptions(lua_State *L@<esi>, int n)
{
  int i; // edi

  for ( i = 2; i <= n; ++i )
  {
    *L->top++ = *index2adr(L, idx: i);
    *L->top = L->top[-2];
    luaD_call(L, func: ++L->top - 2, nResults: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012C10
// Name: modinit
// Source: json
//------------------------------------------------------------------------------
void __usercall modinit(GCObject *L@<esi>, char *modname)
{
  const lua_TValue *v2; // edi
  TString *v3; // eax
  lua_TValue *k; // edi
  const lua_TValue *v5; // edi
  int v6; // eax
  char *v7; // edi
  const lua_TValue *v8; // edi
  TString *v9; // eax
  lua_TValue *v10; // [esp-4h] [ebp-24h]
  lua_TValue *v11; // [esp-4h] [ebp-24h]
  lua_TValue *v12; // [esp-4h] [ebp-24h]
  unsigned int v13; // [esp+Ch] [ebp-14h]
  lua_TValue *v14; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  *L->p.k = *(lua_TValue *)(L->ts.tsv.hash - 16);
  L->ts.tsv.hash += 16;
  v2 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v3 = luaS_newlstr((lua_State *)L, str: "_M", l: 2u);
  v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v3;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v2, &key, val: v10);
  L->ts.tsv.hash -= 16;
  if ( modname != nullptr )
  {
    v13 = strlen(modname);
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    k = L->p.k;
    k->value.b = (int)luaS_newlstr((lua_State *)L, str: modname, l: v13);
    k->tt = 4;
  }
  else
  {
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  }
  L->ts.tsv.hash += 16;
  v5 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "_NAME", l: 5u);
  v11 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v5, &key, val: v11);
  L->ts.tsv.hash -= 16;
  strrchr(string: (unsigned __int8 *)modname, chr: 0x2Eu);
  if ( v6 != 0 )
    v7 = (char *)(v6 + 1);
  else
    v7 = modname;
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  v14 = L->p.k;
  v14->value.b = (int)luaS_newlstr((lua_State *)L, str: modname, l: v7 - modname);
  v14->tt = 4;
  L->ts.tsv.hash += 16;
  v8 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v9 = luaS_newlstr((lua_State *)L, str: "_PACKAGE", l: 8u);
  v12 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v9;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v8, &key, val: v12);
  L->ts.tsv.hash -= 16;
}

//------------------------------------------------------------------------------
// Address: 0x10012D90
// Name: ll_module
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_module(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // edi
  lua_TValue *v8; // esi
  const lua_TValue *v9; // esi
  lua_TValue *v10; // eax
  const lua_TValue *v11; // esi
  TString *v12; // eax
  lua_TValue *v13; // eax
  lua_TValue *k; // [esp-4h] [ebp-2Ch]
  lua_TValue *v16; // [esp-4h] [ebp-2Ch]
  lua_TValue *v17; // [esp-4h] [ebp-2Ch]
  char *str; // [esp+10h] [ebp-18h]
  lua_TValue key; // [esp+18h] [ebp-10h] BYREF

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
    {
LABEL_10:
      v3 = L->h.array;
      if ( (unsigned int)v3 >= L->ts.tsv.hash || v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
        v5 = "no value";
      else
        v5 = luaT_typenames[tt];
      v6 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror((lua_State *)L, extramsg: v6, narg: 1);
    }
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    array = L->h.array;
    if ( (unsigned int)array >= L->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  b = array->value.b;
  str = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = ((signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4) + 1;
  v8 = (lua_TValue *)(L->ts.tsv.len + 96);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "_LOADED", l: 7u);
  k = L->p.k;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v8, &key, val: k);
  L->ts.tsv.hash += 16;
  v9 = index2adr((lua_State *)L, idx: v7);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str, l: strlen(str));
  v16 = L->p.k;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v9, &key, val: v16);
  L->ts.tsv.hash += 16;
  v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v10 == &luaO_nilobject_ || v10->tt != 5 )
  {
    L->ts.tsv.hash = (unsigned int)v10;
    if ( luaL_findtable((lua_State *)L, idx: -10002, fname: str, szhint: 1) != nullptr )
      luaL_error((lua_State *)L, fmt: "name conflict for module '%s'", str);
    *L->p.k = *(lua_TValue *)(L->ts.tsv.hash - 16);
    L->ts.tsv.hash += 16;
    lua_setfield((lua_State *)L, idx: v7, k: str);
  }
  v11 = (const lua_TValue *)(L->ts.tsv.hash - 16);
  v12 = luaS_newlstr((lua_State *)L, str: "_NAME", l: 5u);
  v17 = L->p.k;
  key.value.b = (int)v12;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v11, &key, val: v17);
  L->ts.tsv.hash += 16;
  v13 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v13 == &luaO_nilobject_ || v13->tt != 0 )
  {
    L->ts.tsv.hash = (unsigned int)v13;
  }
  else
  {
    L->ts.tsv.hash = (unsigned int)v13;
    modinit(L, modname: str);
  }
  *L->p.k = *(lua_TValue *)(L->ts.tsv.hash - 16);
  L->ts.tsv.hash += 16;
  setfenv((lua_State *)L);
  dooptions((lua_State *)L, n: v7 - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012FE0
// Name: ll_seeall
// Source: json
//------------------------------------------------------------------------------
int __cdecl ll_seeall(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  lua_TValue *v7; // edi
  Table *v8; // eax
  const lua_TValue *v9; // edi
  TString *v10; // eax
  lua_TValue *v12; // [esp-10h] [ebp-28h]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

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
  v6 = L->base;
  v7 = L->top;
  if ( v6 >= v7 )
    v6 = &luaO_nilobject_;
  if ( v6->tt == 5 )
  {
    v8 = *(Table **)(v6->value.b + 8);
  }
  else if ( v6->tt == 7 )
  {
    v8 = *(Table **)(v6->value.b + 8);
  }
  else
  {
    v8 = L->l_G->mt[v6->tt];
  }
  if ( v8 != nullptr )
  {
    v7->value.b = (int)v8;
    v7->tt = 5;
    ++L->top;
  }
  else
  {
    lua_createtable(L, narray: 1);
    *L->top = L->top[-1];
    ++L->top;
    lua_setmetatable(L, objindex: 1);
  }
  *L->top++ = L->l_gt;
  v9 = L->top - 2;
  v10 = luaS_newlstr(L, str: "__index", l: 7u);
  v12 = L->top - 1;
  key.value.b = (int)v10;
  key.tt = 4;
  luaV_settable(L, t: v9, &key, val: v12);
  --L->top;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013120
// Name: setpath
// Source: json
//------------------------------------------------------------------------------
void __usercall setpath(const char *envname@<eax>, const char *def@<ecx>, GCObject *L, const char *fieldname)
{
  char *v5; // eax
  char *v6; // eax
  lua_TValue *k; // ecx
  lua_TValue *v8; // eax
  int *v9; // ecx
  const lua_TValue *v10; // edi
  lua_TValue *v11; // [esp-4h] [ebp-24h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  v5 = getenv(option: envname);
  if ( v5 != nullptr )
  {
    v6 = (char *)luaL_gsub(s: v5, (lua_State *)L, p: ";;", r: asc_1009A1D4);
    luaL_gsub(s: v6, (lua_State *)L, p: (char *)&byte_1009A1DC, r: def);
    k = L->p.k;
    v8 = k - 1;
    if ( (unsigned int)k >= 0x10 )
    {
      v9 = (int *)&k[-2];
      do
      {
        *v9 = v8->value.b;
        v9[1] = *(&v8->value.b + 1);
        v9[2] = v9[6];
        ++v8;
        v9 += 4;
      }
      while ( (unsigned int)v8 < L->ts.tsv.hash );
    }
    L->ts.tsv.hash -= 16;
  }
  else
  {
    lua_pushstring((lua_State *)L, s: def);
  }
  setprogdir(L);
  v10 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: fieldname, l: strlen(fieldname));
  v11 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v10, &key, val: v11);
  L->ts.tsv.hash -= 16;
}

//------------------------------------------------------------------------------
// Address: 0x10013200
// Name: _luaopen_package
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_package(GCObject *L)
{
  const lua_TValue *v1; // edi
  CallInfo *ci; // eax
  GCObject *v3; // ecx
  lua_TValue *k; // eax
  GCObject *gc; // eax
  int v6; // edi
  int (__cdecl **v7)(lua_State *); // eax
  lua_TValue *v8; // ebx
  lua_TValue *v9; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx
  const lua_TValue *v12; // edi
  lua_TValue *v13; // edi
  const lua_TValue *v14; // edi
  const lua_TValue *v15; // edi
  TString *v16; // eax
  const lua_TValue *v17; // edi
  TString *v18; // eax
  lua_TValue *v20; // [esp-4h] [ebp-24h]
  lua_TValue *v21; // [esp-4h] [ebp-24h]
  lua_TValue *v22; // [esp-4h] [ebp-24h]
  lua_TValue *v23; // [esp-4h] [ebp-24h]
  lua_TValue *v24; // [esp-4h] [ebp-24h]
  lua_TValue *v25; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  luaL_newmetatable((lua_State *)L, tname: "_LOADLIB");
  lua_pushcclosure((lua_State *)L, fn: gctm, n: 0);
  v1 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "__gc", l: 4u);
  v20 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v1, &key, val: v20);
  L->ts.tsv.hash -= 16;
  luaL_openlib((lua_State *)L, libname: "package", l: pk_funcs);
  *L->p.k = *(lua_TValue *)(L->ts.tsv.hash - 16);
  ci = L->th.ci;
  L->ts.tsv.hash += 16;
  if ( ci == L->th.base_ci )
    luaG_runerror((lua_State *)L, fmt: "no calling environment");
  L->th.env.value.b = *(_DWORD *)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 12);
  L->th.env.tt = 5;
  v3 = **(GCObject ***)&L->cl.l.upvals[0]->tt;
  v3->ts.tsv.keyhash = *(_DWORD *)(L->ts.tsv.hash - 16);
  k = L->p.k;
  if ( k[-1].tt >= 4 )
  {
    gc = k[-1].value.gc;
    if ( (gc->gch.marked & 3) != 0 && (v3->gch.marked & 4) != 0 )
      luaC_barrierf((lua_State *)L, o: v3, v: gc);
  }
  L->ts.tsv.hash -= 16;
  lua_createtable((lua_State *)L, narray: 4);
  v6 = 0;
  if ( loader_preload != nullptr )
  {
    v7 = (int (__cdecl **)(lua_State *))loaders;
    do
    {
      lua_pushcclosure((lua_State *)L, fn: *v7, n: 0);
      v8 = L->p.k;
      v25 = v8 - 2;
      *luaH_setnum((lua_State *)L, t: (Table *)v8[-2].value.gc, key: ++v6) = v8[-1];
      v9 = L->p.k;
      if ( v9[-1].tt >= 4 && (*(_BYTE *)(v9[-1].value.b + 5) & 3) != 0 )
      {
        b = (GCObject *)v25->value.b;
        if ( (*(_BYTE *)(v25->value.b + 5) & 4) != 0 )
        {
          l_G = L->th.l_G;
          b->gch.marked &= ~4u;
          b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
          l_G->grayagain = b;
        }
      }
      L->ts.tsv.hash -= 16;
      v7 = (int (__cdecl **)(lua_State *))&loaders[v6];
    }
    while ( *v7 != nullptr );
  }
  v12 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "loaders", l: 7u);
  v21 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v12, &key, val: v21);
  L->ts.tsv.hash -= 16;
  setpath(
    envname: "LUA_PATH",
    def: ".\\?.lua;!\\lua\\?.lua;!\\lua\\?\\init.lua;!\\?.lua;!\\?\\init.lua",
    L,
    fieldname: "path");
  setpath(envname: "LUA_CPATH", def: ".\\?.dll;!\\?.dll;!\\loadall.dll", L, fieldname: "cpath");
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  v13 = L->p.k;
  v13->value.b = (int)luaS_newlstr((lua_State *)L, str: "\\\n;\n?\n!\n-", l: 9u);
  v13->tt = 4;
  L->ts.tsv.hash += 16;
  v14 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "config", l: 6u);
  v22 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v14, &key, val: v22);
  L->ts.tsv.hash -= 16;
  luaL_findtable((lua_State *)L, idx: -10000, fname: "_LOADED", szhint: 2);
  v15 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v16 = luaS_newlstr((lua_State *)L, str: "loaded", l: 6u);
  v23 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v16;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v15, &key, val: v23);
  L->ts.tsv.hash -= 16;
  lua_createtable((lua_State *)L, narray: 0);
  v17 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v18 = luaS_newlstr((lua_State *)L, str: "preload", l: 7u);
  v24 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v18;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v17, &key, val: v24);
  L->ts.tsv.hash -= 16;
  *L->p.k = L->th.l_gt;
  L->ts.tsv.hash += 16;
  luaL_openlib((lua_State *)L, libname: nullptr, l: ll_funcs);
  L->ts.tsv.hash -= 16;
  return 1;
}
