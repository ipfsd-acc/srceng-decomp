// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lapi.c
// Functions: 65
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00473420
// Name: index2adr
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall index2adr@<eax>(lua_State *L@<ecx>, int idx@<eax>)
{
  lua_TValue *result; // eax
  GCObject *gc; // edx

  if ( idx > 0 )
  {
    result = &L->base[idx - 1];
    if ( result < L->top )
      return result;
    return &luaO_nilobject_;
  }
  if ( idx > -10000 )
    return &L->top[idx];
  switch ( idx )
  {
    case -10002:
      return &L->l_gt;
    case -10001:
      L->env.value.b = L->ci->func->value.gc->ts.tsv.len;
      L->env.tt = 5;
      return &L->env;
    case -10000:
      return &L->l_G->l_registry;
    default:
      gc = L->ci->func->value.gc;
      if ( -10002 - idx > gc->cl.c.nupvalues )
        return &luaO_nilobject_;
      return (lua_TValue *)&(&gc->th.top)[4 * (-10002 - idx)];
  }
}

//------------------------------------------------------------------------------
// Address: 0x004734A0
// Name: void luaA_pushobject(struct lua_State __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaA_pushobject(lua_State *L, const lua_TValue *o)
{
  *L->top++ = *o;
}

//------------------------------------------------------------------------------
// Address: 0x004734D0
// Name: int lua_checkstack(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_checkstack(lua_State *L, int size)
{
  CallInfo *ci; // esi
  lua_TValue *v4; // eax

  if ( size + L->top - L->base > 2048 )
    return 0;
  if ( (char *)L->stack_last - (char *)L->top <= 16 * size )
    luaD_growstack(L, n: size);
  ci = L->ci;
  v4 = &L->top[size];
  if ( ci->top < v4 )
    ci->top = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00473530
// Name: void lua_xmove(struct lua_State __near *,struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_xmove(lua_State *from, lua_State *to, int n)
{
  int v4; // edx
  lua_TValue *top; // ecx
  lua_TValue *v6; // eax
  int tt; // eax
  bool v8; // zf
  lua_State *froma; // [esp+10h] [ebp+8h]

  if ( from != to )
  {
    from->top -= n;
    if ( n > 0 )
    {
      v4 = 0;
      froma = (lua_State *)n;
      do
      {
        top = to->top;
        v6 = from->top;
        to->top = top + 1;
        top->value = v6[v4].value;
        tt = v6[v4++].tt;
        v8 = froma == (lua_State *)1;
        froma = (lua_State *)((char *)froma - 1);
        top->tt = tt;
      }
      while ( !v8 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473590
// Name: int (*lua_atpanic(struct lua_State __near *,int (*)(struct lua_State __near *)))(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int (__cdecl *__cdecl lua_atpanic(lua_State *L, int (__cdecl *panicf)(lua_State *)))(lua_State *)
{
  global_State *l_G; // ecx
  int (__cdecl *result)(lua_State *); // eax

  l_G = L->l_G;
  result = l_G->panic;
  l_G->panic = panicf;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004735B0
// Name: struct lua_State __near * lua_newthread(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
lua_State *__cdecl lua_newthread(lua_State *L)
{
  lua_State *result; // eax
  lua_TValue *top; // ecx

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  result = luaE_newthread(L);
  top = L->top;
  top->value.b = (int)result;
  top->tt = 8;
  ++L->top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004735F0
// Name: int lua_gettop(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_gettop(lua_State *L)
{
  return L->top - L->base;
}

//------------------------------------------------------------------------------
// Address: 0x00473610
// Name: void lua_settop(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_settop(lua_State *L, int idx)
{
  int i; // ecx

  if ( idx < 0 )
  {
    L->top += idx + 1;
  }
  else
  {
    for ( i = idx; L->top < &L->base[i]; ++L->top )
      L->top->tt = 0;
    L->top = &L->base[i];
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473660
// Name: void lua_remove(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_remove(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  int *v3; // ecx

  v2 = index2adr(L, idx) + 1;
  if ( v2 < L->top )
  {
    v3 = (int *)&v2[-1];
    do
    {
      *v3 = v2->value.b;
      v3[1] = *(&v2->value.b + 1);
      v3[2] = v3[6];
      ++v2;
      v3 += 4;
    }
    while ( v2 < L->top );
  }
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x004736B0
// Name: void lua_insert(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_insert(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  lua_TValue *top; // edx
  int *v4; // ecx

  v2 = index2adr(L, idx);
  top = L->top;
  if ( top > v2 )
  {
    v4 = (int *)&top[-1];
    do
    {
      top->value.b = *v4;
      *(&top->value.b + 1) = v4[1];
      v4[6] = v4[2];
      --top;
      v4 -= 4;
    }
    while ( top > v2 );
  }
  *v2 = *L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473710
// Name: void lua_replace(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_replace(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  GCObject *gc; // eax
  lua_TValue *top; // ecx
  GCObject *v5; // ecx
  lua_TValue *v6; // eax

  if ( idx == -10001 && L->ci == L->base_ci )
    luaG_runerror(L, fmt: "no calling environment");
  v2 = index2adr(L, idx);
  if ( idx == -10001 )
  {
    gc = L->ci->func->value.gc;
    gc->ts.tsv.len = (unsigned int)L->top[-1].value.gc;
    top = L->top;
    if ( top[-1].tt < 4 )
      goto LABEL_14;
    v5 = top[-1].value.gc;
    if ( (v5->gch.marked & 3) == 0 )
      goto LABEL_14;
  }
  else
  {
    *v2 = L->top[-1];
    if ( idx >= -10002 )
      goto LABEL_14;
    v6 = L->top;
    if ( v6[-1].tt < 4 )
      goto LABEL_14;
    v5 = v6[-1].value.gc;
    if ( (v5->gch.marked & 3) == 0 )
      goto LABEL_14;
    gc = L->ci->func->value.gc;
  }
  if ( (gc->gch.marked & 4) != 0 )
    luaC_barrierf(L, o: gc, v: v5);
LABEL_14:
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x004737D0
// Name: void lua_pushvalue(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushvalue(lua_State *L, int idx)
{
  *L->top++ = *index2adr(L, idx);
}

//------------------------------------------------------------------------------
// Address: 0x00473800
// Name: int lua_type(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_type(lua_State *L, int idx)
{
  lua_TValue *v2; // eax

  v2 = index2adr(L, idx);
  if ( v2 == &luaO_nilobject_ )
    return -1;
  else
    return v2->tt;
}

//------------------------------------------------------------------------------
// Address: 0x00473820
// Name: char const __near * lua_typename(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_typename(lua_State *L, int t)
{
  if ( t == -1 )
    return "no value";
  else
    return luaT_typenames[t];
}

//------------------------------------------------------------------------------
// Address: 0x00473840
// Name: int lua_iscfunction(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lua_iscfunction(lua_State *L, int idx)
{
  lua_TValue *v2; // eax

  v2 = index2adr(L, idx);
  return v2->tt == 6 && *(_BYTE *)(v2->value.b + 6) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00473870
// Name: int lua_isnumber(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_isnumber(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  int result; // eax
  lua_TValue n; // [esp+0h] [ebp-10h] BYREF

  v2 = index2adr(L, idx);
  if ( v2->tt == 3 )
    return 1;
  result = (int)luaV_tonumber(obj: v2, &n);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004738B0
// Name: int lua_isstring(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lua_isstring(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  int tt; // eax
  BOOL result; // eax

  v2 = index2adr(L, idx);
  result = false;
  if ( v2 != &luaO_nilobject_ )
  {
    tt = v2->tt;
    if ( tt == 4 || tt == 3 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004738E0
// Name: int lua_rawequal(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_rawequal(lua_State *L, int index1, int index2)
{
  lua_TValue *v3; // esi
  lua_TValue *v4; // eax

  v3 = index2adr(L, idx: index1);
  v4 = index2adr(L, idx: index2);
  if ( v3 == &luaO_nilobject_ || v4 == &luaO_nilobject_ )
    return 0;
  else
    return luaO_rawequalObj(t1: v3, t2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00473930
// Name: int lua_lessthan(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_lessthan(lua_State *L, int index1, int index2)
{
  lua_TValue *v3; // edi
  lua_TValue *v4; // eax

  v3 = index2adr(L, idx: index1);
  v4 = index2adr(L, idx: index2);
  if ( v3 == &luaO_nilobject_ || v4 == &luaO_nilobject_ )
    return 0;
  else
    return luaV_lessthan(L, l: v3, r: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00473980
// Name: double lua_tonumber(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl lua_tonumber(lua_State *L, int idx)
{
  const lua_TValue *v2; // eax
  lua_TValue n; // [esp+0h] [ebp-10h] BYREF

  v2 = index2adr(L, idx);
  if ( v2->tt == 3 )
    return v2->value.n;
  v2 = luaV_tonumber(obj: v2, &n);
  if ( v2 != nullptr )
    return v2->value.n;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004739C0
// Name: int lua_tointeger(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__cdecl lua_tointeger(lua_State *L, int idx)
{
  lua_TValue *result; // eax
  lua_TValue n; // [esp+0h] [ebp-1Ch] BYREF

  result = index2adr(L, idx);
  if ( result->tt == 3 )
    return (lua_TValue *)(int)result->value.n;
  result = (lua_TValue *)luaV_tonumber(obj: result, &n);
  if ( result != nullptr )
    return (lua_TValue *)(int)result->value.n;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473A10
// Name: int lua_toboolean(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lua_toboolean(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  int tt; // ecx

  v2 = index2adr(L, idx);
  tt = v2->tt;
  return tt != 0 && (tt != 1 || v2->value.b != 0);
}

//------------------------------------------------------------------------------
// Address: 0x00473A40
// Name: char const __near * lua_tolstring(struct lua_State __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_tolstring(lua_State *L, int idx, unsigned int *len)
{
  lua_TValue *v3; // eax

  v3 = index2adr(L, idx);
  if ( v3->tt != 4 )
  {
    if ( luaV_tostring(L, obj: v3) == 0 )
    {
      if ( len != nullptr )
        *len = 0;
      return nullptr;
    }
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v3 = index2adr(L, idx);
  }
  if ( len != nullptr )
    *len = *(_DWORD *)(v3->value.b + 12);
  return (const char *)(v3->value.b + 16);
}

//------------------------------------------------------------------------------
// Address: 0x00473AB0
// Name: unsigned int lua_objlen(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_objlen(lua_State *L, int idx)
{
  lua_TValue *v2; // esi
  int result; // eax

  v2 = index2adr(L, idx);
  switch ( v2->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v2) != 0 )
        goto $LN5_13;
      goto LABEL_6;
    case 4:
$LN5_13:
      result = *(_DWORD *)(v2->value.b + 12);
      break;
    case 5:
      result = luaH_getn(t: (Table *)v2->value.gc);
      break;
    case 7:
      result = *(_DWORD *)(v2->value.b + 16);
      break;
    default:
LABEL_6:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473B20
// Name: int (*lua_tocfunction(struct lua_State __near *,int))(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int (__cdecl *__cdecl lua_tocfunction(lua_State *L, int idx))(lua_State *)
{
  lua_TValue *v2; // eax
  int b; // eax

  v2 = index2adr(L, idx);
  if ( v2->tt == 6 && *(_BYTE *)((b = v2->value.b) + 6) != 0 )
    return *(int (__cdecl **)(lua_State *))(b + 16);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00473B50
// Name: void __near * lua_touserdata(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_touserdata(lua_State *L, int idx)
{
  lua_TValue *v2; // eax

  v2 = index2adr(L, idx);
  if ( v2->tt == 2 )
    return v2->value.b;
  if ( v2->tt == 7 )
    return v2->value.b + 24;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00473B80
// Name: struct lua_State __near * lua_tothread(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
lua_State *__cdecl lua_tothread(lua_State *L, int idx)
{
  lua_TValue *v2; // eax

  v2 = index2adr(L, idx);
  if ( v2->tt == 8 )
    return (lua_State *)v2->value.b;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00473BA0
// Name: void const __near * lua_topointer(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
const void *__cdecl lua_topointer(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  const void *result; // eax

  v2 = index2adr(L, idx);
  switch ( v2->tt )
  {
    case 2:
    case 7:
      v2 = index2adr(L, idx);
      if ( v2->tt == 2 )
        goto $LN5_14;
      if ( v2->tt != 7 )
        goto LABEL_6;
      result = (const void *)(v2->value.b + 24);
      break;
    case 5:
    case 6:
    case 8:
$LN5_14:
      result = (const void *)v2->value.b;
      break;
    default:
LABEL_6:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473C10
// Name: void lua_pushnil(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushnil(lua_State *L)
{
  L->top->tt = 0;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473C30
// Name: void lua_pushnumber(struct lua_State __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushnumber(lua_State *L, long double n)
{
  lua_TValue *top; // ecx

  top = L->top;
  top->value.n = n;
  top->tt = 3;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473C50
// Name: void lua_pushinteger(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushinteger(lua_State *L, int n)
{
  lua_TValue *top; // ecx

  top = L->top;
  top->value.n = (double)n;
  top->tt = 3;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473C80
// Name: void lua_pushlstring(struct lua_State __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushlstring(lua_State *L, const char *s, unsigned int len)
{
  lua_TValue *top; // edi

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  top = L->top;
  top->value.b = (int)luaS_newlstr(L, str: s, l: len);
  top->tt = 4;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473CD0
// Name: void lua_pushstring(struct lua_State __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushstring(lua_State *L, const char *s)
{
  unsigned int v2; // ebx
  lua_TValue *top; // edi

  if ( s != nullptr )
  {
    v2 = strlen(s);
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    top = L->top;
    top->value.b = (int)luaS_newlstr(L, str: s, l: v2);
    top->tt = 4;
    ++L->top;
  }
  else
  {
    L->top->tt = 0;
    ++L->top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473D40
// Name: char const __near * lua_pushvfstring(struct lua_State __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_pushvfstring(lua_State *L, const char *fmt, char *argp)
{
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  return luaO_pushvfstring(L, fmt, argp);
}

//------------------------------------------------------------------------------
// Address: 0x00473D70
// Name: char const __near * lua_pushfstring(struct lua_State __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
const char *lua_pushfstring(lua_State *L, const char *fmt, ...)
{
  va_list argp; // [esp+14h] [ebp+10h] BYREF

  va_start(argp, fmt);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  return luaO_pushvfstring(L, fmt, argp);
}

//------------------------------------------------------------------------------
// Address: 0x00473DA0
// Name: void lua_pushcclosure(struct lua_State __near *,int (*)(struct lua_State __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushcclosure(lua_State *L, int (__cdecl *fn)(lua_State *), int n)
{
  CallInfo *ci; // eax
  GCObject *gc; // eax
  int v5; // edi
  Closure *v6; // eax
  int *p_b; // edx
  char *v8; // ecx
  lua_TValue *top; // ecx

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  ci = L->ci;
  if ( ci == L->base_ci )
    gc = L->l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.len;
  v5 = n;
  v6 = luaF_newCclosure(L, nelems: n, e: (Table *)gc);
  v6->c.f = fn;
  L->top -= n;
  if ( n != 0 )
  {
    p_b = &v6->c.upvalue[n].value.b;
    do
    {
      p_b -= 4;
      v8 = (char *)L->top - 24 - (_DWORD)v6;
      --v5;
      *p_b = *(int *)((char *)p_b + (_DWORD)v8);
      p_b[1] = *(int *)((char *)p_b + (_DWORD)v8 + 4);
      p_b[2] = *(int *)((char *)p_b + (_DWORD)v8 + 8);
    }
    while ( v5 != 0 );
  }
  top = L->top;
  top->value.b = (int)v6;
  top->tt = 6;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473E40
// Name: void lua_pushboolean(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushboolean(lua_State *L, int b)
{
  lua_TValue *top; // ecx

  top = L->top;
  top->tt = 1;
  top->value.b = b != 0;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473E60
// Name: void lua_pushlightuserdata(struct lua_State __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_pushlightuserdata(lua_State *L, void *p)
{
  lua_TValue *top; // ecx

  top = L->top;
  top->value.b = (int)p;
  top->tt = 2;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473E80
// Name: int lua_pushthread(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lua_pushthread(lua_State *L)
{
  lua_TValue *top; // ecx
  global_State *l_G; // ecx

  top = L->top;
  top->value.b = (int)L;
  top->tt = 8;
  l_G = L->l_G;
  ++L->top;
  return l_G->mainthread == L;
}

//------------------------------------------------------------------------------
// Address: 0x00473EB0
// Name: void lua_gettable(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_gettable(lua_State *L, int idx)
{
  const lua_TValue *v2; // eax

  v2 = index2adr(L, idx);
  luaV_gettable(L, t: v2, key: L->top - 1, val: L->top - 1);
}

//------------------------------------------------------------------------------
// Address: 0x00473EE0
// Name: void lua_getfield(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_getfield(lua_State *L, int idx, const char *k)
{
  const lua_TValue *v3; // edi
  lua_TValue *top; // [esp-10h] [ebp-2Ch]
  lua_TValue key; // [esp+Ch] [ebp-10h] BYREF

  v3 = index2adr(L, idx);
  key.value.b = (int)luaS_newlstr(L, str: k, l: strlen(k));
  top = L->top;
  key.tt = 4;
  luaV_gettable(L, t: v3, &key, val: top);
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00473F40
// Name: void lua_rawget(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_rawget(lua_State *L, int idx)
{
  Table **v2; // eax

  v2 = (Table **)index2adr(L, idx);
  L->top[-1] = *luaH_get(t: *v2, key: (const lua_TValue *)L->top - 1);
}

//------------------------------------------------------------------------------
// Address: 0x00473F80
// Name: void lua_rawgeti(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_rawgeti(lua_State *L, int idx, int n)
{
  Table **v3; // eax

  v3 = (Table **)index2adr(L, idx);
  *L->top++ = *luaH_getnum(t: *v3, key: n);
}

//------------------------------------------------------------------------------
// Address: 0x00473FC0
// Name: void lua_createtable(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_createtable(lua_State *L, int narray, int nrec)
{
  lua_TValue *top; // edi

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  top = L->top;
  top->value.b = (int)luaH_new(L, narray, nhash: nrec);
  top->tt = 5;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00474010
// Name: int lua_getmetatable(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_getmetatable(lua_State *L, int objindex)
{
  lua_TValue *v2; // eax
  Table *v3; // ecx
  lua_TValue *top; // eax

  v2 = index2adr(L, idx: objindex);
  if ( v2->tt == 5 )
  {
    v3 = *(Table **)(v2->value.b + 8);
  }
  else if ( v2->tt == 7 )
  {
    v3 = *(Table **)(v2->value.b + 8);
  }
  else
  {
    v3 = L->l_G->mt[v2->tt];
  }
  if ( v3 == nullptr )
    return 0;
  top = L->top;
  top->value.b = (int)v3;
  top->tt = 5;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474070
// Name: void lua_getfenv(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_getfenv(lua_State *L, int idx)
{
  lua_TValue *v2; // eax
  lua_TValue *top; // ecx
  int v4; // eax

  v2 = index2adr(L, idx);
  if ( v2->tt == 6 || v2->tt == 7 )
  {
    top = L->top;
    v4 = *(_DWORD *)(v2->value.b + 12);
    top->tt = 5;
    top->value.b = v4;
    ++L->top;
  }
  else
  {
    if ( v2->tt == 8 )
      *L->top = *(lua_TValue *)(v2->value.b + 72);
    else
      L->top->tt = 0;
    ++L->top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004740E0
// Name: void lua_settable(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_settable(lua_State *L, int idx)
{
  const lua_TValue *v2; // eax

  v2 = index2adr(L, idx);
  luaV_settable(L, t: v2, key: L->top - 2, val: L->top - 1);
  L->top -= 2;
}

//------------------------------------------------------------------------------
// Address: 0x00474110
// Name: void lua_setfield(struct lua_State __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_setfield(lua_State *L, int idx, const char *k)
{
  const lua_TValue *v3; // edi
  lua_TValue *v4; // [esp-10h] [ebp-2Ch]
  lua_TValue key; // [esp+Ch] [ebp-10h] BYREF

  v3 = index2adr(L, idx);
  key.value.b = (int)luaS_newlstr(L, str: k, l: strlen(k));
  v4 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v3, &key, val: v4);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00474170
// Name: void lua_rawset(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_rawset(lua_State *L, int idx)
{
  Table **v2; // eax
  lua_TValue *top; // edi
  Table **v4; // ebx
  lua_TValue *v5; // eax
  Table *v6; // ebx

  v2 = (Table **)index2adr(L, idx);
  top = L->top;
  v4 = v2;
  *luaH_set(L, t: *v2, key: top - 2) = top[-1];
  v5 = L->top;
  if ( v5[-1].tt >= 4 && (*(_BYTE *)(v5[-1].value.b + 5) & 3) != 0 )
  {
    v6 = *v4;
    if ( (v6->marked & 4) != 0 )
      luaC_barrierback(L, t: v6);
  }
  L->top -= 2;
}

//------------------------------------------------------------------------------
// Address: 0x004741E0
// Name: void lua_rawseti(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_rawseti(lua_State *L, int idx, int n)
{
  Table **v3; // eax
  lua_TValue *top; // esi
  Table **v5; // ebx
  lua_TValue *v6; // eax
  Table *v7; // ebx

  v3 = (Table **)index2adr(L, idx);
  top = L->top;
  v5 = v3;
  *luaH_setnum(L, t: *v3, key: n) = top[-1];
  v6 = L->top;
  if ( v6[-1].tt >= 4 && (*(_BYTE *)(v6[-1].value.b + 5) & 3) != 0 )
  {
    v7 = *v5;
    if ( (v7->marked & 4) != 0 )
      luaC_barrierback(L, t: v7);
  }
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00474250
// Name: int lua_setmetatable(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_setmetatable(lua_State *L, int objindex)
{
  lua_TValue *v2; // eax
  lua_TValue *top; // ecx
  GCObject *gc; // ecx
  GCObject *v6; // eax
  Table *b; // eax

  v2 = index2adr(L, idx: objindex);
  top = L->top;
  if ( top[-1].tt != 0 )
    gc = top[-1].value.gc;
  else
    gc = nullptr;
  if ( v2->tt == 5 )
  {
    *(_DWORD *)(v2->value.b + 8) = gc;
    if ( gc != nullptr && (gc->gch.marked & 3) != 0 )
    {
      b = (Table *)v2->value.b;
      if ( (b->marked & 4) != 0 )
        luaC_barrierback(L, t: b);
    }
  }
  else
  {
    if ( v2->tt != 7 )
    {
      L->l_G->mt[v2->tt] = (Table *)gc;
      --L->top;
      return 1;
    }
    *(_DWORD *)(v2->value.b + 8) = gc;
    if ( gc != nullptr && (gc->gch.marked & 3) != 0 )
    {
      v6 = (GCObject *)v2->value.b;
      if ( (v6->gch.marked & 4) != 0 )
      {
        luaC_barrierf(L, o: v6, v: gc);
        --L->top;
        return 1;
      }
    }
  }
  --L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474300
// Name: int lua_setfenv(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_setfenv(lua_State *L, int idx)
{
  int v2; // edi
  lua_TValue *v3; // eax
  int b; // ecx
  GCObject *v5; // eax

  v2 = 1;
  v3 = index2adr(L, idx);
  switch ( v3->tt )
  {
    case 6:
      *(_DWORD *)(v3->value.b + 12) = L->top[-1].value.gc;
      break;
    case 7:
      *(_DWORD *)(v3->value.b + 12) = L->top[-1].value.gc;
      break;
    case 8:
      b = v3->value.b;
      *(_DWORD *)(b + 72) = L->top[-1].value.gc;
      *(_DWORD *)(b + 80) = 5;
      break;
    default:
      v2 = 0;
      break;
  }
  if ( (*(_BYTE *)(L->top[-1].value.b + 5) & 3) != 0 )
  {
    v5 = (GCObject *)v3->value.b;
    if ( (v5->gch.marked & 4) != 0 )
      luaC_barrierf(L, o: v5, v: L->top[-1].value.gc);
  }
  --L->top;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00474380
// Name: void lua_call(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_call(lua_State *L, int nargs, int nresults)
{
  CallInfo *ci; // eax
  lua_TValue *top; // esi

  luaD_call(L, func: &L->top[-nargs - 1], nResults: nresults);
  if ( nresults == -1 )
  {
    ci = L->ci;
    top = L->top;
    if ( top >= ci->top )
      ci->top = top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004743C0
// Name: f_call
// Source: json
//------------------------------------------------------------------------------
void __cdecl f_call(lua_State *L, void *ud)
{
  luaD_call(L, func: *(lua_TValue **)ud, nResults: *((_DWORD *)ud + 1));
}

//------------------------------------------------------------------------------
// Address: 0x004743E0
// Name: int lua_pcall(struct lua_State __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_pcall(lua_State *L, int nargs, int nresults, int errfunc)
{
  int v4; // ecx
  int result; // eax
  CallInfo *ci; // ecx
  lua_TValue *top; // esi
  int v8; // [esp-Ch] [ebp-18h]
  CallS c; // [esp+4h] [ebp-8h] BYREF

  if ( errfunc != 0 )
    v4 = (char *)index2adr(L, idx: errfunc) - (char *)L->stack;
  else
    v4 = 0;
  c.func = &L->top[-nargs - 1];
  v8 = (char *)c.func - (char *)L->stack;
  c.nresults = nresults;
  result = luaD_pcall(L, func: f_call, u: &c, old_top: v8, ef: v4);
  if ( nresults == -1 )
  {
    ci = L->ci;
    top = L->top;
    if ( top >= ci->top )
      ci->top = top;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474450
// Name: int lua_load(struct lua_State __near *,char const __near * (*)(struct lua_State __near *,void __near *,unsigned int __near *),void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_load(
        lua_State *L,
        const char *(__cdecl *reader)(lua_State *, void *, unsigned int *),
        void *data,
        const char *chunkname)
{
  const char *v4; // edi
  Zio z; // [esp+8h] [ebp-14h] BYREF

  v4 = chunkname;
  if ( chunkname == nullptr )
    v4 = "?";
  luaZ_init(L, &z, reader, data);
  return luaD_protectedparser(L, &z, name: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00474490
// Name: int lua_dump(struct lua_State __near *,int (*)(struct lua_State __near *,void const __near *,unsigned int,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_dump(lua_State *L, int (__cdecl *writer)(lua_State *, const void *, unsigned int, void *), void *data)
{
  lua_TValue *top; // eax
  GCObject *gc; // eax

  top = L->top;
  if ( top[-1].tt != 6 )
    return 1;
  gc = top[-1].value.gc;
  if ( gc->ts.tsv.reserved != 0 )
    return 1;
  else
    return luaU_dump(L, f: gc->cl.l.p, w: writer, data, strip: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004744D0
// Name: int lua_status(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_status(lua_State *L)
{
  return L->status;
}

//------------------------------------------------------------------------------
// Address: 0x004744E0
// Name: int lua_gc(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_gc(lua_State *L, int what, int data)
{
  global_State *l_G; // esi
  int v4; // edi
  int result; // eax
  unsigned int totalbytes; // ecx

  l_G = L->l_G;
  v4 = 0;
  switch ( what )
  {
    case 0:
      l_G->GCthreshold = -3;
      result = 0;
      break;
    case 1:
      l_G->GCthreshold = l_G->totalbytes;
      result = 0;
      break;
    case 2:
      luaC_fullgc(L);
      result = 0;
      break;
    case 3:
      result = l_G->totalbytes >> 10;
      break;
    case 4:
      result = l_G->totalbytes & 0x3FF;
      break;
    case 5:
      totalbytes = l_G->totalbytes;
      if ( data << 10 > totalbytes )
        l_G->GCthreshold = 0;
      else
        l_G->GCthreshold = totalbytes - (data << 10);
      if ( l_G->GCthreshold <= totalbytes )
      {
        do
          luaC_step(L);
        while ( l_G->GCthreshold <= l_G->totalbytes );
      }
      if ( l_G->gcstate != 0 )
        goto LABEL_17;
      result = 1;
      break;
    case 6:
      result = l_G->gcpause;
      l_G->gcpause = data;
      break;
    case 7:
      result = l_G->gcstepmul;
      l_G->gcstepmul = data;
      break;
    default:
      v4 = -1;
LABEL_17:
      result = v4;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004745E0
// Name: int lua_error(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn lua_error(lua_State *L)
{
  luaG_errormsg(L);
}

//------------------------------------------------------------------------------
// Address: 0x00474600
// Name: int lua_next(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_next(lua_State *L, int idx)
{
  Table **v2; // eax
  int result; // eax

  v2 = (Table **)index2adr(L, idx);
  result = luaH_next(L, t: *v2, key: L->top - 1);
  if ( result != 0 )
    ++L->top;
  else
    --L->top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474640
// Name: void lua_concat(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_concat(lua_State *L, int n)
{
  lua_TValue *top; // edi

  if ( n < 2 )
  {
    if ( n == 0 )
    {
      top = L->top;
      top->value.b = (int)luaS_newlstr(L, str: var, l: 0);
      top->tt = 4;
      ++L->top;
    }
  }
  else
  {
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    luaV_concat(L, total: n, last: L->top - L->base - 1);
    L->top = (lua_TValue *)((char *)L->top + 16 - 16 * n);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004746C0
// Name: void __near * lua_newuserdata(struct lua_State __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
Udata *__cdecl lua_newuserdata(lua_State *L, unsigned int size)
{
  CallInfo *ci; // eax
  GCObject *gc; // eax
  Udata *v4; // eax
  lua_TValue *top; // ecx

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  ci = L->ci;
  if ( ci == L->base_ci )
    gc = L->l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.len;
  v4 = luaS_newudata(L, s: size, e: (Table *)gc);
  top = L->top;
  top->value.b = (int)v4;
  top->tt = 7;
  ++L->top;
  return v4 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474720
// Name: char const __near * lua_getupvalue(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_getupvalue(lua_State *L, int funcindex, int n)
{
  lua_TValue *v3; // eax
  const char *result; // eax
  int b; // eax
  lua_TValue *v6; // ecx
  int v7; // esi

  v3 = index2adr(L, idx: funcindex);
  if ( v3->tt != 6 )
    return nullptr;
  b = v3->value.b;
  if ( *(_BYTE *)(b + 6) == 0 )
  {
    v7 = *(_DWORD *)(b + 16);
    if ( n >= 1 && n <= *(_DWORD *)(v7 + 36) )
    {
      v6 = *(lua_TValue **)(*(_DWORD *)(b + 4 * n + 16) + 8);
      result = (const char *)(*(_DWORD *)(*(_DWORD *)(v7 + 28) + 4 * n - 4) + 16);
      if ( *(_DWORD *)(*(_DWORD *)(v7 + 28) + 4 * n - 4) == -16 )
        return result;
      goto LABEL_10;
    }
    return nullptr;
  }
  if ( n < 1 || n > *(unsigned __int8 *)(b + 7) )
    return nullptr;
  v6 = (lua_TValue *)(b + 16 * n + 8);
  result = var;
LABEL_10:
  *L->top++ = *v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004747B0
// Name: char const __near * lua_setupvalue(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_setupvalue(lua_State *L, int funcindex, int n)
{
  lua_TValue *v3; // eax
  int b; // ecx
  lua_TValue *v6; // ecx
  const char *v7; // esi
  int v8; // esi
  lua_TValue *top; // ecx
  GCObject *v10; // ecx
  GCObject *v11; // eax

  v3 = index2adr(L, idx: funcindex);
  if ( v3->tt != 6 )
    return nullptr;
  b = v3->value.b;
  if ( *(_BYTE *)(v3->value.b + 6) != 0 )
  {
    if ( n >= 1 && n <= *(unsigned __int8 *)(b + 7) )
    {
      v6 = (lua_TValue *)(b + 16 * n + 8);
      v7 = var;
      goto LABEL_10;
    }
  }
  else
  {
    v8 = *(_DWORD *)(b + 16);
    if ( n >= 1 && n <= *(_DWORD *)(v8 + 36) )
    {
      v6 = *(lua_TValue **)(*(_DWORD *)(b + 4 * n + 16) + 8);
      v7 = (const char *)(*(_DWORD *)(*(_DWORD *)(v8 + 28) + 4 * n - 4) + 16);
      if ( v7 == nullptr )
        return v7;
LABEL_10:
      *v6 = *--L->top;
      top = L->top;
      if ( top->tt >= 4 )
      {
        v10 = (GCObject *)top->value.b;
        if ( (v10->gch.marked & 3) != 0 )
        {
          v11 = (GCObject *)v3->value.b;
          if ( (v11->gch.marked & 4) != 0 )
            luaC_barrierf(L, o: v11, v: v10);
        }
      }
      return v7;
    }
  }
  return nullptr;
}
