// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/liolib.c
// Functions: 36
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000CEF0
// Name: fileerror
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn fileerror(GCObject *L, const char *arg)
{
  int *v2; // eax
  const char *v3; // eax
  lua_TValue *v4; // esi

  v2 = _errno();
  v3 = strerror(errnum: *v2);
  lua_pushfstring((lua_State *)L, fmt: "%s: %s", arg, v3);
  v4 = (lua_TValue *)(L->ts.tsv.hash - 16);
  if ( v4->tt != 4 )
  {
    if ( luaV_tostring((lua_State *)L, obj: v4) == 0 )
      luaL_argerror((lua_State *)L, extramsg: nullptr, narg: 1);
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    v4 = (lua_TValue *)(L->ts.tsv.hash - 16);
  }
  luaL_argerror((lua_State *)L, extramsg: (const char *)(v4->value.b + 24), narg: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000CF80
// Name: io_type
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_type(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *v2; // ecx
  _DWORD *b; // ebx
  lua_TValue *p_l_registry; // edi
  lua_TValue *v5; // ecx
  lua_TValue *v6; // edx
  Table *v7; // eax
  lua_TValue *top; // [esp-10h] [ebp-30h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
    luaL_argerror(L, extramsg: "value expected", narg: 1);
  v2 = L->base;
  if ( v2 >= L->top )
    v2 = &luaO_nilobject_;
  if ( v2->tt == 2 )
  {
    b = (_DWORD *)v2->value.b;
  }
  else if ( v2->tt == 7 )
  {
    b = (_DWORD *)(v2->value.b + 24);
  }
  else
  {
    b = nullptr;
  }
  p_l_registry = &L->l_G->l_registry;
  key.value.b = (int)luaS_newlstr(L, str: "FILE*", l: 5u);
  top = L->top;
  key.tt = 4;
  luaV_gettable(L, t: p_l_registry, &key, val: top);
  v5 = ++L->top;
  if ( b == nullptr )
    goto LABEL_26;
  v6 = L->base;
  if ( v6 >= v5 )
    v6 = &luaO_nilobject_;
  if ( v6->tt == 5 )
    v7 = *(Table **)(v6->value.b + 8);
  else
    v7 = v6->tt == 7 ? *(Table **)(v6->value.b + 8) : L->l_G->mt[v6->tt];
  if ( v7 != nullptr && (v5->value.b = (int)v7, v5->tt = 5, ++L->top, lua_rawequal(L, index1: -2, index2: -1)) )
  {
    if ( *b != 0 )
      lua_pushlstring(L, s: "file", len: 4u);
    else
      lua_pushlstring(L, s: "closed file", len: 0xBu);
    return 1;
  }
  else
  {
LABEL_26:
    L->top->tt = 0;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D0D0
// Name: newfile
// Source: json
//------------------------------------------------------------------------------
_iobuf **__usercall newfile@<eax>(GCObject *L@<eax>)
{
  CallInfo *ci; // eax
  GCObject *gc; // ebx
  global_State *l_G; // edi
  GCObject *v5; // eax
  unsigned __int8 v6; // dl
  lua_TValue *k; // ecx
  lua_TValue *upvalue; // ebx
  lua_TValue *v9; // edi
  TString *v10; // eax
  lua_TValue *v12; // [esp-10h] [ebp-30h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  ci = L->th.ci;
  if ( ci == L->th.base_ci )
    gc = L->th.l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
  l_G = L->th.l_G;
  v5 = (GCObject *)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 28u);
  if ( v5 == nullptr )
    luaD_throw((lua_State *)L, errcode: 4);
  l_G->totalbytes += 28;
  v6 = *(_BYTE *)(L->ts.tsv.len + 20);
  v5->ts.tsv.keyhash = (unsigned int)gc;
  v5->ts.tsv.len = 4;
  v5->ts.tsv.hash = 0;
  v5->gch.marked = v6 & 3;
  v5->gch.tt = 7;
  v5->ts.dummy.l = **(_DWORD **)(L->ts.tsv.len + 112);
  **(_DWORD **)(L->ts.tsv.len + 112) = v5;
  k = L->p.k;
  k->value.b = (int)v5;
  k->tt = 7;
  L->ts.tsv.hash += 16;
  upvalue = v5->cl.c.upvalue;
  v5->cl.c.upvalue[0].value.b = 0;
  v9 = (lua_TValue *)(L->ts.tsv.len + 96);
  v10 = luaS_newlstr((lua_State *)L, str: "FILE*", l: 5u);
  v12 = L->p.k;
  key.value.b = (int)v10;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v9, &key, val: v12);
  L->ts.tsv.hash += 16;
  lua_setmetatable((lua_State *)L, objindex: -2);
  return (_iobuf **)upvalue;
}

//------------------------------------------------------------------------------
// Address: 0x1000D1D0
// Name: io_noclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_noclose(GCObject *L)
{
  global_State *l_G; // eax
  lua_TValue *k; // edi

  *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  l_G = L->th.l_G;
  L->ts.tsv.hash += 16;
  if ( l_G->totalbytes >= l_G->GCthreshold )
    luaC_step(L);
  k = L->p.k;
  k->value.b = (int)luaS_newlstr((lua_State *)L, str: "cannot close standard file", l: 0x1Au);
  k->tt = 4;
  L->ts.tsv.hash += 16;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1000D230
// Name: io_pclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_pclose(lua_State *L)
{
  _iobuf **v1; // edi
  BOOL v2; // ebx
  int v3; // edi
  lua_TValue *top; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  v2 = _pclose(pstream: *v1) != -1;
  *v1 = nullptr;
  v3 = *_errno();
  if ( v2 )
  {
    top = L->top;
    top->value.b = 1;
    top->tt = 1;
    ++L->top;
    return 1;
  }
  else
  {
    L->top->tt = 0;
    ++L->top;
    v6 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v6);
    v7 = L->top;
    v7->value.n = (double)v3;
    v7->tt = 3;
    ++L->top;
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D2E0
// Name: io_fclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_fclose(lua_State *L)
{
  _iobuf **v1; // ebx
  int v2; // edi
  int v3; // ebx
  lua_TValue *v4; // eax
  const char *v6; // eax
  lua_TValue *top; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  v2 = -(fclose(stream: *v1) != 0);
  *v1 = nullptr;
  v3 = *_errno();
  if ( v2 == -1 )
  {
    L->top->tt = 0;
    ++L->top;
    v6 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v6);
    top = L->top;
    top->value.n = (double)v3;
    top->tt = 3;
    ++L->top;
    return 3;
  }
  else
  {
    v4 = L->top;
    v4->value.b = 1;
    v4->tt = 1;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D380
// Name: aux_close
// Source: json
//------------------------------------------------------------------------------
int __usercall aux_close@<eax>(lua_State *L@<esi>)
{
  lua_TValue *base; // edx
  lua_TValue *top; // eax
  int b; // ecx
  int v4; // ecx
  const lua_TValue *v5; // edi
  TString *v6; // eax
  lua_TValue *v7; // eax
  GCObject *gc; // eax
  lua_TValue *v10; // [esp-10h] [ebp-28h]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  base = L->base;
  top = L->top;
  if ( base >= top )
    base = &luaO_nilobject_;
  if ( base->tt == 6 || base->tt == 7 )
  {
    v4 = *(_DWORD *)(base->value.b + 12);
    top->tt = 5;
    top->value.b = v4;
  }
  else if ( base->tt == 8 )
  {
    b = base->value.b;
    top->value.b = *(_DWORD *)(base->value.b + 72);
    *(&top->value.b + 1) = *(_DWORD *)(b + 76);
    top->tt = *(_DWORD *)(b + 80);
  }
  else
  {
    top->tt = 0;
  }
  v5 = L->top++;
  v6 = luaS_newlstr(L, str: "__close", l: 7u);
  v10 = L->top;
  key.value.b = (int)v6;
  key.tt = 4;
  luaV_gettable(L, t: v5, &key, val: v10);
  v7 = ++L->top;
  if ( v7[-1].tt == 6 && (gc = v7[-1].value.gc)->ts.tsv.reserved != 0 )
    return gc->cl.c.f(a1: L);
  else
    return MEMORY[0](a1: L);
}

//------------------------------------------------------------------------------
// Address: 0x1000D440
// Name: io_close
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_close(lua_State *L)
{
  lua_TValue *base; // eax

  base = L->base;
  if ( base >= L->top || base == &luaO_nilobject_ || base->tt == -1 )
  {
    L->env.value.b = L->ci->func->value.gc->ts.tsv.keyhash;
    L->env.tt = 5;
    *L->top++ = *luaH_getnum(t: (Table *)L->env.value.gc, key: 2);
  }
  if ( *(_DWORD *)luaL_checkudata(L, ud: 1, tname: "FILE*") == 0 )
    luaL_error(L, fmt: "attempt to use a closed file");
  return aux_close(L);
}

//------------------------------------------------------------------------------
// Address: 0x1000D4D0
// Name: io_gc
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_gc(lua_State *L)
{
  if ( *(_DWORD *)luaL_checkudata(L, ud: 1, tname: "FILE*") != 0 )
    aux_close(L);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D500
// Name: io_tostring
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_tostring(GCObject *L)
{
  const void *v1; // eax
  lua_TValue *k; // edi

  v1 = *(const void **)luaL_checkudata((lua_State *)L, ud: 1, tname: "FILE*");
  if ( v1 != nullptr )
  {
    lua_pushfstring((lua_State *)L, fmt: "file (%p)", v1);
    return 1;
  }
  else
  {
    if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
      luaC_step(L);
    k = L->p.k;
    k->value.b = (int)luaS_newlstr((lua_State *)L, str: "file (closed)", l: 0xDu);
    k->tt = 4;
    L->ts.tsv.hash += 16;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D580
// Name: io_open
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_open(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax
  const char *v8; // edi
  _iobuf **v9; // esi
  _iobuf *v10; // eax
  int v11; // esi
  lua_TValue *k; // eax
  const char *v14; // [esp-8h] [ebp-18h]
  char *file; // [esp+Ch] [ebp-4h]

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
  file = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v7 >= L->ts.tsv.hash || v7 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 24) <= 0 )
    v8 = "r";
  else
    v8 = luaL_checklstring((lua_State *)L, len: nullptr, narg: 2);
  v9 = newfile(L);
  v10 = fopen(file, mode: v8);
  *v9 = v10;
  if ( v10 != nullptr )
    return 1;
  v11 = *_errno();
  *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  L->ts.tsv.hash += 16;
  v14 = strerror(errnum: v11);
  if ( file != nullptr )
    lua_pushfstring((lua_State *)L, fmt: "%s: %s", file, v14);
  else
    lua_pushfstring((lua_State *)L, fmt: "%s", v14);
  k = L->p.k;
  k->value.n = (double)v11;
  k->tt = 3;
  L->ts.tsv.hash += 16;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1000D6E0
// Name: io_popen
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_popen(GCObject *L)
{
  lua_TValue *array; // esi
  int b; // esi
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax
  const char *v8; // edi
  _iobuf **v9; // esi
  _iobuf *v10; // eax
  int v11; // esi
  lua_TValue *k; // eax
  const char *v14; // [esp-8h] [ebp-18h]
  char *cmdstring; // [esp+Ch] [ebp-4h]

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
  cmdstring = (char *)(b + 24);
  if ( b == -24 )
    goto LABEL_10;
  v7 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v7 >= L->ts.tsv.hash || v7 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 24) <= 0 )
    v8 = "r";
  else
    v8 = luaL_checklstring((lua_State *)L, len: nullptr, narg: 2);
  v9 = newfile(L);
  v10 = _popen(cmdstring, type: v8);
  *v9 = v10;
  if ( v10 != nullptr )
    return 1;
  v11 = *_errno();
  *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  L->ts.tsv.hash += 16;
  v14 = strerror(errnum: v11);
  if ( cmdstring != nullptr )
    lua_pushfstring((lua_State *)L, fmt: "%s: %s", cmdstring, v14);
  else
    lua_pushfstring((lua_State *)L, fmt: "%s", v14);
  k = L->p.k;
  k->value.n = (double)v11;
  k->tt = 3;
  L->ts.tsv.hash += 16;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1000D840
// Name: io_tmpfile
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_tmpfile(GCObject *L)
{
  _iobuf **v1; // edi
  _iobuf *v2; // eax
  int v3; // edi
  const char *v4; // eax
  lua_TValue *k; // eax

  v1 = newfile(L);
  v2 = tmpfile();
  *v1 = v2;
  if ( v2 != nullptr )
    return 1;
  v3 = *_errno();
  *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
  L->ts.tsv.hash += 16;
  v4 = strerror(errnum: v3);
  lua_pushfstring((lua_State *)L, fmt: "%s", v4);
  k = L->p.k;
  k->value.n = (double)v3;
  k->tt = 3;
  L->ts.tsv.hash += 16;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1000D8C0
// Name: getiofile
// Source: json
//------------------------------------------------------------------------------
_iobuf *__usercall getiofile@<eax>(lua_State *L@<edi>, int findex)
{
  lua_TValue *top; // ecx
  int b; // ecx

  L->env.value.b = L->ci->func->value.gc->ts.tsv.keyhash;
  L->env.tt = 5;
  *L->top++ = *luaH_getnum(t: (Table *)L->env.value.gc, key: findex);
  top = L->top;
  if ( top[-1].tt == 2 )
  {
    b = top[-1].value.b;
  }
  else if ( top[-1].tt == 7 )
  {
    b = top[-1].value.b + 24;
  }
  else
  {
    b = 0;
  }
  if ( *(_DWORD *)b == 0 )
    luaL_error(L, fmt: "standard %s file is closed", (const char *)dword_10098D9C[findex]);
  return *(_iobuf **)b;
}

//------------------------------------------------------------------------------
// Address: 0x1000D940
// Name: g_iofile
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_iofile(GCObject *L, int f, const char *mode)
{
  lua_TValue *array; // eax
  lua_TValue *k; // ecx
  const char *v5; // esi
  _iobuf **v6; // edi
  _iobuf *v7; // eax
  lua_TValue *v8; // eax
  lua_TValue *v9; // ecx
  Table *v10; // esi

  array = L->h.array;
  k = L->p.k;
  if ( array < k && array != &luaO_nilobject_ && array->tt > 0 )
  {
    if ( array >= k )
      array = &luaO_nilobject_;
    if ( array->tt != 4 )
    {
      if ( luaV_tostring((lua_State *)L, obj: array) == 0 )
        goto LABEL_15;
      if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
        luaC_step(L);
      array = L->h.array;
      if ( (unsigned int)array >= L->ts.tsv.hash )
        array = &luaO_nilobject_;
    }
    v5 = (const char *)(array->value.b + 24);
    if ( array->value.b != -24 )
    {
      v6 = newfile(L);
      v7 = fopen(file: v5, mode);
      *v6 = v7;
      if ( v7 == nullptr )
        fileerror(L, arg: v5);
LABEL_20:
      lua_rawseti(idx: -10001, n: f, (lua_TValue *)L);
      goto LABEL_21;
    }
LABEL_15:
    if ( *(_DWORD *)luaL_checkudata((lua_State *)L, ud: 1, tname: "FILE*") == 0 )
      luaL_error((lua_State *)L, fmt: "attempt to use a closed file");
    v8 = L->h.array;
    v9 = L->p.k;
    if ( v8 >= v9 )
      v8 = &luaO_nilobject_;
    v9->value.b = v8->value.b;
    *(&v9->value.b + 1) = *(&v8->value.b + 1);
    v9->tt = v8->tt;
    L->ts.tsv.hash += 16;
    goto LABEL_20;
  }
LABEL_21:
  v10 = *(Table **)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 12);
  L->th.env.value.b = (int)v10;
  L->th.env.tt = 5;
  *L->p.k = *luaH_getnum(t: v10, key: f);
  L->ts.tsv.hash += 16;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DA80
// Name: io_input
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_input(GCObject *L)
{
  return g_iofile(L, f: 1, mode: "r");
}

//------------------------------------------------------------------------------
// Address: 0x1000DAA0
// Name: io_output
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_output(GCObject *L)
{
  return g_iofile(L, f: 2, mode: "w");
}

//------------------------------------------------------------------------------
// Address: 0x1000DAC0
// Name: f_lines
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_lines(lua_State *L)
{
  lua_TValue *base; // ecx
  lua_TValue *top; // eax
  lua_TValue *v3; // eax

  if ( *(_DWORD *)luaL_checkudata(L, ud: 1, tname: "FILE*") == 0 )
    luaL_error(L, fmt: "attempt to use a closed file");
  base = L->base;
  top = L->top;
  if ( base >= top )
    base = &luaO_nilobject_;
  top->value.b = base->value.b;
  *(&top->value.b + 1) = *(&base->value.b + 1);
  top->tt = base->tt;
  v3 = ++L->top;
  v3->value.b = 0;
  v3->tt = 1;
  ++L->top;
  lua_pushcclosure(L, fn: io_readline, n: 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DB40
// Name: io_lines
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_lines(GCObject *L)
{
  lua_TValue *array; // eax
  const char *v3; // esi
  _iobuf **v4; // ebx
  _iobuf *v5; // eax
  lua_TValue *k; // eax

  array = L->h.array;
  if ( (unsigned int)array >= L->ts.tsv.hash || array == &luaO_nilobject_ || array->tt <= 0 )
  {
    L->th.env.value.b = *(_DWORD *)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 12);
    L->th.env.tt = 5;
    *L->p.k = *luaH_getnum(t: (Table *)L->th.env.value.gc, key: 1);
    L->ts.tsv.hash += 16;
    return f_lines((lua_State *)L);
  }
  else
  {
    v3 = luaL_checklstring((lua_State *)L, len: nullptr, narg: 1);
    v4 = newfile(L);
    v5 = fopen(file: v3, mode: "r");
    *v4 = v5;
    if ( v5 == nullptr )
      fileerror(L, arg: v3);
    *L->p.k = *index2adr((lua_State *)L, idx: (signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4);
    L->ts.tsv.hash += 16;
    k = L->p.k;
    k->value.b = 1;
    k->tt = 1;
    L->ts.tsv.hash += 16;
    lua_pushcclosure((lua_State *)L, fn: io_readline, n: 2);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC40
// Name: test_eof
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall test_eof@<eax>(GCObject *L@<esi>, _iobuf *f@<eax>)
{
  int v3; // ebx
  lua_TValue *k; // edi

  v3 = getc(stream: f);
  ungetc(ch: v3, stream: f);
  if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
    luaC_step(L);
  k = L->p.k;
  k->value.b = (int)luaS_newlstr((lua_State *)L, str: nullptr, l: 0);
  k->tt = 4;
  L->ts.tsv.hash += 16;
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DCA0
// Name: read_line
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl read_line(GCObject *L, _iobuf *f)
{
  GCObject *v2; // esi
  char *buffer; // ecx
  unsigned int v4; // ebx
  _DWORD *hash; // edi
  unsigned int v6; // kr00_4
  unsigned int v7; // ebx
  lua_State *v8; // esi
  int *v9; // edi
  lua_TValue *v10; // esi
  BOOL result; // eax
  unsigned int v12; // ebx
  lua_State *v13; // esi
  int *top; // edi
  luaL_Buffer b; // [esp+10h] [ebp-210h] BYREF

  v2 = L;
  b.L = (lua_State *)L;
  buffer = b.buffer;
  b.lvl = 0;
  while ( 1 )
  {
    b.p = buffer;
    v4 = buffer - b.buffer;
    if ( buffer != b.buffer )
    {
      if ( *(_DWORD *)(v2->ts.tsv.len + 68) >= *(_DWORD *)(v2->ts.tsv.len + 64) )
        luaC_step(L: v2);
      hash = (_DWORD *)v2->ts.tsv.hash;
      *hash = luaS_newlstr(L: (lua_State *)v2, str: b.buffer, l: v4);
      hash[2] = 4;
      v2->ts.tsv.hash += 16;
      ++b.lvl;
      b.p = b.buffer;
      adjuststack(B: &b);
    }
    if ( fgets(string: b.buffer, count: 512, str: f) == nullptr )
      break;
    v6 = strlen(b.buffer);
    if ( v6 != 0 && b.buffer[v6 - 1] == 10 )
    {
      b.p = &b.p[v6 - 1];
      v12 = b.p - b.buffer;
      if ( b.p != b.buffer )
      {
        v13 = b.L;
        if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
          luaC_step(L: (GCObject *)b.L);
        top = (int *)v13->top;
        *top = (int)luaS_newlstr(L: v13, str: b.buffer, l: v12);
        top[2] = 4;
        ++v13->top;
        ++b.lvl;
        b.p = b.buffer;
      }
      lua_concat(L: b.L, n: b.lvl);
      return true;
    }
    v2 = (GCObject *)b.L;
    buffer = &b.p[v6];
  }
  v7 = b.p - b.buffer;
  if ( b.p != b.buffer )
  {
    v8 = b.L;
    if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
      luaC_step(L: (GCObject *)b.L);
    v9 = (int *)v8->top;
    *v9 = (int)luaS_newlstr(L: v8, str: b.buffer, l: v7);
    v9[2] = 4;
    ++v8->top;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: b.L, n: b.lvl);
  v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
  b.lvl = 1;
  switch ( v10->tt )
  {
    case 3:
      if ( luaV_tostring((lua_State *)L, obj: v10) == 0 )
        goto LABEL_20;
      result = *(_DWORD *)(v10->value.b + 16) != 0;
      break;
    case 4:
      result = *(_DWORD *)(v10->value.b + 16) != 0;
      break;
    case 5:
      result = luaH_getn(t: (Table *)v10->value.gc) != 0;
      break;
    case 7:
      result = *(_DWORD *)(v10->value.b + 16) != 0;
      break;
    default:
LABEL_20:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF20
// Name: read_chars
// Source: json
//------------------------------------------------------------------------------
int __cdecl read_chars(GCObject *L, _iobuf *f, unsigned int n)
{
  GCObject *v3; // esi
  char *buffer; // ecx
  unsigned int v5; // ebx
  _DWORD *hash; // edi
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ebx
  lua_State *v10; // esi
  int *top; // edi
  lua_TValue *k; // esi
  int tt; // eax
  lua_TValue *v14; // esi
  int v15; // eax
  int result; // eax
  luaL_Buffer b; // [esp+Ch] [ebp-218h] BYREF
  unsigned int l; // [esp+220h] [ebp-4h]

  v3 = L;
  buffer = b.buffer;
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  v5 = 512;
  while ( 1 )
  {
    l = buffer - b.buffer;
    if ( buffer != b.buffer )
    {
      if ( *(_DWORD *)(v3->ts.tsv.len + 68) >= *(_DWORD *)(v3->ts.tsv.len + 64) )
        luaC_step(L: v3);
      hash = (_DWORD *)v3->ts.tsv.hash;
      *hash = luaS_newlstr(L: (lua_State *)v3, str: b.buffer, l);
      hash[2] = 4;
      v3->ts.tsv.hash += 16;
      ++b.lvl;
      b.p = b.buffer;
      adjuststack(B: &b);
    }
    if ( v5 > n )
      v5 = n;
    v7 = fread(buffer: b.buffer, elementSize: 1u, count: v5, stream: f);
    buffer = &b.p[v7];
    v8 = n - v7;
    b.p += v7;
    n = v8;
    if ( v8 == 0 || v7 != v5 )
      break;
    v3 = (GCObject *)b.L;
  }
  v9 = buffer - b.buffer;
  if ( buffer != b.buffer )
  {
    v10 = b.L;
    if ( b.L->l_G->totalbytes >= b.L->l_G->GCthreshold )
      luaC_step(L: (GCObject *)b.L);
    top = (int *)v10->top;
    *top = (int)luaS_newlstr(L: v10, str: b.buffer, l: v9);
    top[2] = 4;
    ++v10->top;
    v8 = n;
    ++b.lvl;
    b.p = b.buffer;
  }
  lua_concat(L: b.L, n: b.lvl);
  b.lvl = 1;
  if ( v8 == 0 )
    return 1;
  k = L->p.k;
  tt = k[-1].tt;
  v14 = k - 1;
  switch ( tt )
  {
    case 3:
      if ( luaV_tostring((lua_State *)L, obj: v14) != 0 )
        v15 = *(_DWORD *)(v14->value.b + 16);
      else
        v15 = 0;
      goto LABEL_23;
    case 4:
      v15 = *(_DWORD *)(v14->value.b + 16);
      goto LABEL_23;
    case 5:
      v15 = luaH_getn(t: (Table *)v14->value.gc);
      goto LABEL_23;
    case 7:
      v15 = *(_DWORD *)(v14->value.b + 16);
LABEL_23:
      if ( v15 == 0 )
        goto LABEL_24;
      return 1;
    default:
LABEL_24:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0F0
// Name: g_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_read(GCObject *L, _iobuf *f, int first)
{
  int v3; // edi
  int v4; // edi
  int line; // esi
  int v6; // esi
  const char *v7; // eax
  lua_TValue *v8; // eax
  int v10; // edi
  lua_TValue *v11; // eax
  lua_TValue *v12; // eax
  int tt; // ecx
  lua_TValue *v14; // eax
  int b; // eax
  bool v16; // zf
  const char *v17; // eax
  int v18; // eax
  int v19; // eax
  lua_TValue *k; // eax
  int n; // [esp+10h] [ebp-38h]
  const char *p; // [esp+14h] [ebp-34h]
  int nargs; // [esp+1Ch] [ebp-2Ch]
  long double v24; // [esp+20h] [ebp-28h] BYREF
  long double v25; // [esp+28h] [ebp-20h]
  long double v26; // [esp+30h] [ebp-18h] BYREF
  long double v27; // [esp+38h] [ebp-10h] BYREF
  int v28; // [esp+40h] [ebp-8h]

  v3 = (signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4;
  clearerr(stream: f);
  v4 = v3 - 1;
  if ( v4 != 0 )
  {
    if ( lua_checkstack((lua_State *)L, size: v4 + 20) == 0 )
      luaL_error((lua_State *)L, fmt: "stack overflow (%s)", "too many arguments");
    line = 1;
    n = first;
    while ( 1 )
    {
      nargs = v4 - 1;
      if ( line == 0 )
        goto LABEL_3;
      v10 = n;
      v11 = index2adr((lua_State *)L, idx: n);
      if ( v11 == &luaO_nilobject_ || v11->tt != 3 )
      {
        v14 = index2adr((lua_State *)L, idx: n);
        if ( v14->tt != 4 )
        {
          if ( luaV_tostring((lua_State *)L, obj: v14) == 0 )
            goto LABEL_25;
          if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
            luaC_step(L);
          v14 = index2adr((lua_State *)L, idx: n);
        }
        b = v14->value.b;
        v16 = b == -24;
        v17 = (const char *)(b + 24);
        p = v17;
        if ( v16 || *v17 != 42 )
LABEL_25:
          luaL_argerror((lua_State *)L, extramsg: "invalid option", narg: n);
        v18 = v17[1] - 97;
        if ( p[1] == 97 )
        {
          read_chars(L, f, n: 0xFFFFFFFF);
          line = 1;
        }
        else
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 2 )
              luaL_argerror((lua_State *)L, extramsg: "invalid format", narg: n);
            if ( fscanf(stream: f, format: "%lf", &v26) == 1 )
            {
              k = L->p.k;
              k->value.n = v26;
              k->tt = 3;
              L->ts.tsv.hash += 16;
              line = 1;
            }
            else
            {
              line = 0;
            }
          }
          else
          {
            line = read_line(L, f);
          }
        }
      }
      else
      {
        v12 = index2adr((lua_State *)L, idx: n);
        tt = v12->tt;
        if ( tt != 3 )
        {
          if ( tt != 4 || (v10 = n, luaO_str2d(s: (const char *)(v12->value.b + 24), result: &v24) == 0) )
          {
LABEL_16:
            line = test_eof(L, f);
            goto LABEL_34;
          }
          v27 = v24;
          v28 = 3;
          v12 = (lua_TValue *)&v27;
        }
        v25 = v12->value.n;
        if ( (int)v25 == 0 )
          goto LABEL_16;
        line = read_chars(L, f, n: (int)v25);
      }
LABEL_34:
      n = v10 + 1;
      if ( nargs == 0 )
        goto LABEL_3;
      v4 = nargs;
    }
  }
  line = read_line(L, f);
  n = first + 1;
LABEL_3:
  if ( ferror(stream: f) != 0 )
  {
    v6 = *_errno();
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
    L->ts.tsv.hash += 16;
    v7 = strerror(errnum: v6);
    lua_pushfstring((lua_State *)L, fmt: "%s", v7);
    v8 = L->p.k;
    v8->value.n = (double)v6;
    v8->tt = 3;
    L->ts.tsv.hash += 16;
    return 3;
  }
  else
  {
    if ( line == 0 )
    {
      L->ts.tsv.hash -= 16;
      *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
      L->ts.tsv.hash += 16;
    }
    return n - first;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E3B0
// Name: io_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_read(GCObject *L)
{
  _iobuf *v1; // eax

  v1 = getiofile((lua_State *)L, findex: 1);
  return g_read(L, f: v1, first: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000E3D0
// Name: f_read
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_read(GCObject *L)
{
  _iobuf **v1; // eax

  v1 = (_iobuf **)luaL_checkudata((lua_State *)L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error((lua_State *)L, fmt: "attempt to use a closed file");
  return g_read(L, f: *v1, first: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E410
// Name: io_readline
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_readline(GCObject *L)
{
  lua_TValue *v1; // ecx
  lua_TValue *v2; // eax
  _iobuf **b; // eax
  _iobuf *v4; // edi
  BOOL line; // ebx
  int *v6; // eax
  const char *v7; // eax
  GCObject *v9; // eax
  lua_TValue *p_base_ci; // ecx
  int tt; // eax
  lua_TValue *array; // eax
  CallInfo *ci; // ecx
  GCObject *gc; // ecx
  lua_TValue *upvalue; // ecx

  v1 = *(lua_TValue **)&L->cl.l.upvals[0]->tt;
  if ( *(_BYTE *)(v1->value.b + 7) != 0 )
    v2 = (lua_TValue *)(v1->value.b + 24);
  else
    v2 = &luaO_nilobject_;
  if ( v2->tt == 2 )
  {
    b = (_iobuf **)v2->value.b;
  }
  else if ( v2->tt == 7 )
  {
    b = (_iobuf **)(v2->value.b + 24);
  }
  else
  {
    b = nullptr;
  }
  v4 = *b;
  if ( *b == nullptr )
    luaL_error((lua_State *)L, fmt: "file is already closed");
  line = read_line(L, f: *b);
  if ( ferror(stream: v4) != 0 )
  {
    v6 = _errno();
    v7 = strerror(errnum: *v6);
    luaL_error((lua_State *)L, fmt: "%s", v7);
  }
  if ( line )
    return 1;
  v9 = **(GCObject ***)&L->cl.l.upvals[0]->tt;
  p_base_ci = (lua_TValue *)&v9->th.base_ci;
  if ( v9->cl.c.nupvalues < 2u )
    p_base_ci = &luaO_nilobject_;
  tt = p_base_ci->tt;
  if ( tt != 0 && (tt != 1 || p_base_ci->value.b != 0) )
  {
    for ( ; L->ts.tsv.hash < L->ts.tsv.keyhash; L->ts.tsv.hash += 16 )
      *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
    array = L->h.array;
    ci = L->th.ci;
    L->ts.tsv.hash = (unsigned int)array;
    gc = ci->func->value.gc;
    if ( gc->cl.c.nupvalues != 0 )
      upvalue = gc->cl.c.upvalue;
    else
      upvalue = &luaO_nilobject_;
    array->value.b = upvalue->value.b;
    *(&array->value.b + 1) = *(&upvalue->value.b + 1);
    array->tt = upvalue->tt;
    L->ts.tsv.hash += 16;
    aux_close((lua_State *)L);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E530
// Name: g_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_write(GCObject *L, _iobuf *f, int arg)
{
  int v3; // eax
  int v4; // edi
  lua_TValue *v5; // eax
  lua_TValue *v6; // eax
  int v7; // ecx
  double n; // xmm0_8
  int v9; // esi
  lua_TValue *k; // eax
  lua_TValue *v12; // eax
  int b; // eax
  lua_TValue *v14; // eax
  int tt; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  lua_TValue *v19; // eax
  int status; // [esp+20h] [ebp-28h]
  unsigned int l; // [esp+24h] [ebp-24h]
  int nargs; // [esp+2Ch] [ebp-1Ch]
  long double v23; // [esp+30h] [ebp-18h] BYREF
  long double v24; // [esp+38h] [ebp-10h] BYREF
  int v25; // [esp+40h] [ebp-8h]

  v3 = ((signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4) - 1;
  status = 1;
  if ( (signed int)(L->ts.tsv.hash - L->ts.tsv.keyhash) >> 4 != 1 )
  {
    while ( 1 )
    {
      v4 = arg;
      nargs = v3 - 1;
      v5 = index2adr((lua_State *)L, idx: arg);
      if ( v5 != &luaO_nilobject_ && v5->tt == 3 )
        break;
      v12 = index2adr((lua_State *)L, idx: arg);
      if ( v12->tt != 4 )
      {
        if ( luaV_tostring((lua_State *)L, obj: v12) == 0 )
          goto LABEL_22;
        if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
          luaC_step(L);
        v12 = index2adr((lua_State *)L, idx: arg);
      }
      b = v12->value.b;
      if ( b == -24 )
      {
LABEL_22:
        v14 = index2adr((lua_State *)L, idx: arg);
        if ( v14 == &luaO_nilobject_ || (tt = v14->tt) == -1 )
          v16 = "no value";
        else
          v16 = luaT_typenames[tt];
        v17 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "string", v16);
        luaL_argerror((lua_State *)L, extramsg: v17, narg: arg);
      }
      if ( status != 0 )
      {
        l = *(_DWORD *)(b + 16);
        if ( fwrite(buffer: (const void *)(b + 24), size: 1u, count: l, stream: f) == l )
        {
LABEL_29:
          status = 1;
          goto LABEL_12;
        }
      }
LABEL_11:
      status = 0;
LABEL_12:
      v3 = nargs;
      arg = v4 + 1;
      if ( nargs == 0 )
        goto LABEL_13;
    }
    if ( status == 0 )
      goto LABEL_11;
    v6 = index2adr((lua_State *)L, idx: arg);
    v7 = v6->tt;
    if ( v7 != 3 )
    {
      if ( v7 != 4 || (v4 = arg, luaO_str2d(s: (const char *)(v6->value.b + 24), result: &v23) == 0) )
      {
        n = 0.0;
LABEL_10:
        if ( fprintf(str: f, format: "%.14g", n) > 0 )
          goto LABEL_29;
        goto LABEL_11;
      }
      v24 = v23;
      v25 = 3;
      v6 = (lua_TValue *)&v24;
    }
    n = v6->value.n;
    goto LABEL_10;
  }
LABEL_13:
  v9 = *_errno();
  if ( status != 0 )
  {
    k = L->p.k;
    k->value.b = 1;
    k->tt = 1;
    L->ts.tsv.hash += 16;
    return 1;
  }
  else
  {
    *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
    L->ts.tsv.hash += 16;
    v18 = strerror(errnum: v9);
    lua_pushfstring((lua_State *)L, fmt: "%s", v18);
    v19 = L->p.k;
    v19->value.n = (double)v9;
    v19->tt = 3;
    L->ts.tsv.hash += 16;
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E770
// Name: io_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_write(GCObject *L)
{
  _iobuf *v1; // eax

  v1 = getiofile((lua_State *)L, findex: 2);
  return g_write(L, f: v1, arg: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000E790
// Name: f_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_write(GCObject *L)
{
  _iobuf **v1; // eax

  v1 = (_iobuf **)luaL_checkudata((lua_State *)L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error((lua_State *)L, fmt: "attempt to use a closed file");
  return g_write(L, f: *v1, arg: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E7D0
// Name: f_seek
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_seek(lua_State *L)
{
  _iobuf **v1; // eax
  _iobuf *v2; // edi
  int v3; // ebx
  lua_TValue *v4; // eax
  int v5; // eax
  int v6; // edi
  const char *v7; // eax
  lua_TValue *top; // eax
  int v10; // eax
  lua_TValue *v11; // ecx

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  v2 = *v1;
  v3 = luaL_checkoption(def: "cur", lst: (const char **)modenames, L, narg: 2);
  v4 = L->base + 2;
  if ( v4 >= L->top || v4 == &luaO_nilobject_ || L->base[2].tt <= 0 )
    v5 = 0;
  else
    v5 = luaL_checkinteger(L, narg: 3);
  if ( fseek(stream: v2, offset: v5, whence: mode[v3]) != 0 )
  {
    v6 = *_errno();
    L->top->tt = 0;
    ++L->top;
    v7 = strerror(errnum: v6);
    lua_pushfstring(L, fmt: "%s", v7);
    top = L->top;
    top->value.n = (double)v6;
    top->tt = 3;
    ++L->top;
    return 3;
  }
  else
  {
    v10 = ftell(stream: v2);
    v11 = L->top;
    v11->value.n = (double)v10;
    v11->tt = 3;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E8D0
// Name: f_setvbuf
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_setvbuf(lua_State *L)
{
  _iobuf **v1; // eax
  _iobuf *v2; // edi
  int v3; // ebx
  lua_TValue *v4; // eax
  unsigned int v5; // eax
  int v6; // ebx
  int v7; // edi
  lua_TValue *v8; // eax
  const char *v10; // eax
  lua_TValue *top; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  v2 = *v1;
  v3 = luaL_checkoption(def: nullptr, lst: (const char **)modenames_0, L, narg: 2);
  v4 = L->base + 2;
  if ( v4 >= L->top || v4 == &luaO_nilobject_ || L->base[2].tt <= 0 )
    v5 = 512;
  else
    v5 = luaL_checkinteger(L, narg: 3);
  v6 = setvbuf(str: v2, buffer: nullptr, type: mode_0[v3], size: v5);
  v7 = *_errno();
  if ( v6 != 0 )
  {
    L->top->tt = 0;
    ++L->top;
    v10 = strerror(errnum: v7);
    lua_pushfstring(L, fmt: "%s", v10);
    top = L->top;
    top->value.n = (double)v7;
    top->tt = 3;
    ++L->top;
    return 3;
  }
  else
  {
    v8 = L->top;
    v8->value.b = 1;
    v8->tt = 1;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E9D0
// Name: io_flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl io_flush(lua_State *L)
{
  _iobuf *v1; // eax
  int v2; // esi
  int v3; // ebx
  lua_TValue *top; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax

  v1 = getiofile(L, findex: 2);
  v2 = -(fflush(stream: v1) != 0);
  v3 = *_errno();
  top = L->top;
  if ( v2 == -1 )
  {
    top->tt = 0;
    ++L->top;
    v6 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v6);
    v7 = L->top;
    v7->value.n = (double)v3;
    v7->tt = 3;
    ++L->top;
    return 3;
  }
  else
  {
    top->value.b = 1;
    top->tt = 1;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EA60
// Name: f_flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl f_flush(lua_State *L)
{
  _iobuf **v1; // eax
  int v2; // edi
  int v3; // ebx
  lua_TValue *top; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax

  v1 = (_iobuf **)luaL_checkudata(L, ud: 1, tname: "FILE*");
  if ( *v1 == nullptr )
    luaL_error(L, fmt: "attempt to use a closed file");
  v2 = -(fflush(stream: *v1) != 0);
  v3 = *_errno();
  top = L->top;
  if ( v2 == -1 )
  {
    top->tt = 0;
    ++L->top;
    v6 = strerror(errnum: v3);
    lua_pushfstring(L, fmt: "%s", v6);
    v7 = L->top;
    v7->value.n = (double)v3;
    v7->tt = 3;
    ++L->top;
    return 3;
  }
  else
  {
    top->value.b = 1;
    top->tt = 1;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EB10
// Name: createmeta
// Source: json
//------------------------------------------------------------------------------
void __usercall createmeta(lua_State *L@<eax>)
{
  const lua_TValue *v2; // edi
  TString *v3; // eax
  lua_TValue *v4; // [esp-14h] [ebp-2Ch]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  luaL_newmetatable(L, tname: "FILE*");
  *L->top = L->top[-1];
  v2 = ++L->top - 2;
  v3 = luaS_newlstr(L, str: "__index", l: 7u);
  v4 = L->top - 1;
  key.value.b = (int)v3;
  key.tt = 4;
  luaV_settable(L, t: v2, &key, val: v4);
  --L->top;
  luaL_openlib(L, libname: nullptr, l: flib);
}

//------------------------------------------------------------------------------
// Address: 0x1000EB90
// Name: createstdfile
// Source: json
//------------------------------------------------------------------------------
void __usercall createstdfile(GCObject *L@<ecx>, int k@<eax>, _iobuf *f, const char *fname)
{
  lua_TValue *v6; // eax
  lua_TValue *v7; // eax
  const lua_TValue *v8; // edi
  TString *v9; // eax
  lua_TValue *v10; // [esp-10h] [ebp-30h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  *newfile(L) = f;
  if ( k > 0 )
  {
    v6 = L->p.k;
    v6->value.b = v6[-1].value.b;
    *(&v6->value.b + 1) = *(&v6[-1].value.b + 1);
    v6->tt = v6[-1].tt;
    L->ts.tsv.hash += 16;
    lua_rawseti(idx: -10001, n: k, (lua_TValue *)L);
  }
  v7 = L->p.k;
  v7->value.b = v7[-2].value.b;
  *(&v7->value.b + 1) = *(&v7[-2].value.b + 1);
  v7->tt = v7[-2].tt;
  L->ts.tsv.hash += 16;
  lua_setfenv((lua_State *)L, idx: -2);
  v8 = (const lua_TValue *)(L->ts.tsv.hash - 48);
  v9 = luaS_newlstr((lua_State *)L, str: fname, l: strlen(fname));
  v10 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v9;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v8, &key, val: v10);
  L->ts.tsv.hash -= 16;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC50
// Name: _luaopen_io
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_io(GCObject *L)
{
  const lua_TValue *v1; // edi
  CallInfo *ci; // edx
  GCObject *v3; // ecx
  lua_TValue *k; // eax
  GCObject *gc; // eax
  const lua_TValue *v6; // edi
  _iobuf *v7; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // edi
  const lua_TValue *v10; // edi
  const lua_TValue *v11; // edi
  TString *v12; // eax
  const lua_TValue *v13; // edi
  TString *v14; // eax
  lua_TValue *v16; // [esp-34h] [ebp-54h]
  lua_TValue *v17; // [esp-28h] [ebp-48h]
  lua_TValue *v18; // [esp-20h] [ebp-40h]
  lua_TValue *v19; // [esp-20h] [ebp-40h]
  lua_TValue *v20; // [esp-18h] [ebp-38h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  createmeta((lua_State *)L);
  lua_createtable((lua_State *)L, narray: 1);
  lua_pushcclosure((lua_State *)L, fn: io_fclose, n: 0);
  v1 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "__close", l: 7u);
  v18 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v1, &key, val: v18);
  ci = L->th.ci;
  L->ts.tsv.hash -= 16;
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
  luaL_openlib((lua_State *)L, libname: "io", l: iolib);
  lua_createtable((lua_State *)L, narray: 1);
  lua_pushcclosure((lua_State *)L, fn: (int (__cdecl *)(lua_State *))io_noclose, n: 0);
  v6 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "__close", l: 7u);
  v17 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v6, &key, val: v17);
  L->ts.tsv.hash -= 16;
  v7 = __iob_func();
  createstdfile(L, k: 1, f: v7, fname: "stdin");
  v8 = __iob_func();
  createstdfile(L, k: 2, f: v8 + 1, fname: "stdout");
  v9 = __iob_func() + 2;
  *newfile(L) = v9;
  *L->p.k = *(lua_TValue *)(L->ts.tsv.hash - 32);
  L->ts.tsv.hash += 16;
  lua_setfenv((lua_State *)L, idx: -2);
  v10 = (const lua_TValue *)(L->ts.tsv.hash - 48);
  key.value.b = (int)luaS_newlstr((lua_State *)L, str: "stderr", l: 6u);
  v20 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v10, &key, val: v20);
  L->ts.tsv.hash -= 32;
  v11 = (const lua_TValue *)(L->ts.tsv.hash - 16);
  v12 = luaS_newlstr((lua_State *)L, str: "popen", l: 5u);
  v16 = L->p.k;
  key.value.b = (int)v12;
  key.tt = 4;
  luaV_gettable((lua_State *)L, t: v11, &key, val: v16);
  L->ts.tsv.hash += 16;
  lua_createtable((lua_State *)L, narray: 1);
  lua_pushcclosure((lua_State *)L, fn: io_pclose, n: 0);
  v13 = (const lua_TValue *)(L->ts.tsv.hash - 32);
  v14 = luaS_newlstr((lua_State *)L, str: "__close", l: 7u);
  v19 = (lua_TValue *)(L->ts.tsv.hash - 16);
  key.value.b = (int)v14;
  key.tt = 4;
  luaV_settable((lua_State *)L, t: v13, &key, val: v19);
  L->ts.tsv.hash -= 16;
  lua_setfenv((lua_State *)L, idx: -2);
  L->ts.tsv.hash -= 16;
  return 1;
}
