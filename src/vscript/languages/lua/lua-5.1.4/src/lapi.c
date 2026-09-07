// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lapi.c
// Functions: 31
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001000
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
      L->env.value.b = L->ci->func->value.gc->ts.tsv.keyhash;
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
// Address: 0x10001080
// Name: _lua_checkstack
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_checkstack@<eax>(lua_State *L@<ecx>, int size@<eax>)
{
  lua_TValue *top; // ecx
  int v4; // edi
  int stacksize; // ecx
  int v6; // eax
  lua_TValue *v7; // eax
  CallInfo *ci; // esi
  lua_TValue *v9; // eax

  if ( size > 8000 )
    return 0;
  top = L->top;
  if ( size + L->top - L->base > 8000 )
    return 0;
  if ( size > 0 )
  {
    v4 = size;
    if ( (char *)L->stack_last - (char *)top <= 16 * size )
    {
      stacksize = L->stacksize;
      if ( size > stacksize )
        v6 = stacksize + size;
      else
        v6 = 2 * stacksize;
      luaD_reallocstack(L, newsize: v6);
    }
    v7 = L->top;
    ci = L->ci;
    v9 = &v7[v4];
    if ( ci->top < v9 )
      ci->top = v9;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: _lua_xmove
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_xmove(lua_State *from@<edi>, lua_State *to@<esi>, int n@<eax>)
{
  int v3; // edx
  lua_TValue *top; // ecx
  lua_TValue *v5; // eax
  int tt; // eax
  bool v7; // zf
  int v8; // [esp+0h] [ebp-4h]

  if ( from != to )
  {
    from->top -= n;
    if ( n > 0 )
    {
      v3 = 0;
      v8 = n;
      do
      {
        top = to->top;
        v5 = from->top;
        to->top = top + 1;
        top->value = v5[v3].value;
        tt = v5[v3++].tt;
        v7 = v8-- == 1;
        top->tt = tt;
      }
      while ( !v7 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: _lua_settop
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_settop(lua_State *L@<eax>, int idx@<ecx>)
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
// Address: 0x10001190
// Name: _lua_remove
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_remove(lua_State *L@<esi>, int idx@<eax>)
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
// Address: 0x100011D0
// Name: _lua_insert
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_insert(lua_State *L@<esi>, int idx@<eax>)
{
  lua_TValue *v2; // eax
  lua_TValue *top; // ecx
  int *v4; // edx

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
// Address: 0x10001220
// Name: _lua_pushvalue
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_pushvalue(lua_State *L@<esi>, int idx@<eax>)
{
  *L->top++ = *index2adr(L, idx);
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: _lua_rawequal
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall lua_rawequal@<eax>(lua_State *L@<edi>, int index1@<eax>, int index2)
{
  lua_TValue *v3; // esi
  lua_TValue *v4; // eax
  int tt; // ecx
  BOOL result; // eax

  v3 = index2adr(L, idx: index1);
  v4 = index2adr(L, idx: index2);
  if ( v3 == &luaO_nilobject_ )
    return false;
  if ( v4 == &luaO_nilobject_ )
    return false;
  tt = v3->tt;
  if ( tt != v4->tt )
    return false;
  switch ( tt )
  {
    case 0:
      result = true;
      break;
    case 3:
      if ( v3->value.n != v4->value.n )
        return false;
      result = true;
      break;
    default:
      result = v3->value.b == v4->value.b;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: _lua_tonumber
// Source: json
//------------------------------------------------------------------------------
__int64 __usercall lua_tonumber@<xmm0>(lua_State *L@<ecx>, int idx@<eax>)
{
  lua_TValue *p_n; // eax
  int tt; // ecx
  lua_TValue n; // [esp+8h] [ebp-10h] BYREF

  p_n = index2adr(L, idx);
  tt = p_n->tt;
  if ( tt == 3 )
    return *(_QWORD *)&p_n->value.n;
  if ( tt == 4 && luaO_str2d(s: (const char *)(p_n->value.b + 24), result: (long double *)&n.tt) != 0 )
  {
    n.value.n = *(long double *)&n.tt;
    n.tt = 3;
    p_n = &n;
    return *(_QWORD *)&p_n->value.n;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: _lua_tolstring
// Source: json
//------------------------------------------------------------------------------
const char *__usercall lua_tolstring@<eax>(lua_State *L@<edi>, int idx, unsigned int *len)
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
    *len = *(_DWORD *)(v3->value.b + 16);
  return (const char *)(v3->value.b + 24);
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: _lua_objlen
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_objlen@<eax>(lua_State *L@<edi>, int idx@<eax>)
{
  lua_TValue *v2; // esi
  int result; // eax

  v2 = index2adr(L, idx);
  switch ( v2->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v2) == 0 )
        goto LABEL_7;
      result = *(_DWORD *)(v2->value.b + 16);
      break;
    case 4:
      result = *(_DWORD *)(v2->value.b + 16);
      break;
    case 5:
      result = luaH_getn(t: (Table *)v2->value.gc);
      break;
    case 7:
      result = *(_DWORD *)(v2->value.b + 16);
      break;
    default:
LABEL_7:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100013F0
// Name: _lua_pushlstring
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_pushlstring(lua_State *L@<esi>, const char *s, unsigned int len)
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
// Address: 0x10001430
// Name: _lua_pushstring
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_pushstring(lua_State *L@<esi>, const char *s)
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
// Address: 0x100014A0
// Name: _lua_pushfstring
// Source: json
//------------------------------------------------------------------------------
const char *lua_pushfstring(lua_State *L, const char *fmt, ...)
{
  va_list argp; // [esp+18h] [ebp+10h] BYREF

  va_start(argp, fmt);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  return luaO_pushvfstring(L, fmt, argp);
}

//------------------------------------------------------------------------------
// Address: 0x100014E0
// Name: _lua_pushcclosure
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_pushcclosure(lua_State *L@<esi>, int (__cdecl *fn)(lua_State *), int n)
{
  int v3; // ebx
  CallInfo *ci; // eax
  GCObject *gc; // edx
  global_State *l_G; // edi
  int v7; // eax
  global_State *v8; // edi
  unsigned __int8 currentwhite; // dl
  int v10; // edi
  _DWORD *v11; // edx
  char *v12; // ecx
  lua_TValue *top; // ecx
  GCObject *v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+14h] [ebp-4h]

  v3 = n;
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  ci = L->ci;
  if ( ci == L->base_ci )
    gc = L->l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
  l_G = L->l_G;
  v15 = 16 * n;
  v14 = gc;
  v7 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 16 * n + 24);
  if ( v7 == 0 && 16 * n != -24 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 16 * n + 24;
  v8 = L->l_G;
  *(_DWORD *)v7 = v8->rootgc;
  currentwhite = v8->currentwhite;
  v8->rootgc = (GCObject *)v7;
  *(_BYTE *)(v7 + 5) = currentwhite & 3;
  *(_DWORD *)(v7 + 16) = fn;
  *(_BYTE *)(v7 + 4) = 6;
  *(_BYTE *)(v7 + 6) = 1;
  *(_DWORD *)(v7 + 12) = v14;
  *(_BYTE *)(v7 + 7) = n;
  L->top = (lua_TValue *)((char *)L->top - v15);
  if ( n != 0 )
  {
    v10 = -24 - v7;
    v11 = (_DWORD *)(v15 + v7 + 24);
    while ( 1 )
    {
      v11 -= 4;
      v12 = (char *)L->top + v10;
      --v3;
      *v11 = *(_DWORD *)((char *)v11 + (_DWORD)v12);
      v11[1] = *(_DWORD *)((char *)v11 + (_DWORD)v12 + 4);
      v11[2] = *(_DWORD *)((char *)v11 + (_DWORD)v12 + 8);
      if ( v3 == 0 )
        break;
      v10 = -24 - v7;
    }
  }
  top = L->top;
  top->value.b = v7;
  top->tt = 6;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: _lua_rawgeti
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_rawgeti(lua_State *L@<edi>, int idx@<eax>, int n)
{
  Table **v3; // eax

  v3 = (Table **)index2adr(L, idx);
  *L->top++ = *luaH_getnum(t: *v3, key: n);
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: _lua_createtable
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_createtable(lua_State *L, int narray)
{
  global_State *l_G; // edi
  int v3; // esi
  global_State *v4; // eax
  lua_TValue *i_o; // [esp+Ch] [ebp-4h]

  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  l_G = L->l_G;
  i_o = L->top;
  v3 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 32u);
  if ( v3 == 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 32;
  v4 = L->l_G;
  *(_DWORD *)v3 = v4->rootgc;
  v4->rootgc = (GCObject *)v3;
  *(_BYTE *)(v3 + 5) = v4->currentwhite & 3;
  *(_BYTE *)(v3 + 4) = 5;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 28) = 0;
  *(_WORD *)(v3 + 6) = 255;
  *(_DWORD *)(v3 + 16) = &dummynode_;
  setarrayvector(L, t: (Table *)v3, size: 0);
  setnodevector(L, t: (Table *)v3, size: narray);
  i_o->value.b = v3;
  i_o->tt = 5;
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x100016C0
// Name: _lua_getmetatable
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_getmetatable@<eax>(lua_State *L@<esi>, int objindex@<eax>)
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
// Address: 0x10001710
// Name: _lua_getfenv
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_getfenv(lua_State *L@<esi>, int idx@<eax>)
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
// Address: 0x10001770
// Name: _lua_setfield
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_setfield(lua_State *L@<esi>, int idx@<eax>, const char *k@<edi>)
{
  const lua_TValue *v3; // ebx
  lua_TValue *v4; // [esp-4h] [ebp-1Ch]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  v3 = index2adr(L, idx);
  key.value.b = (int)luaS_newlstr(L, str: k, l: strlen(k));
  v4 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v3, &key, val: v4);
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: _lua_rawset
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_rawset(lua_State *L@<esi>, int idx@<eax>)
{
  Table **v2; // eax
  Table *v3; // ebx
  lua_TValue *v4; // edi
  lua_TValue *v5; // eax
  int tt; // eax
  lua_TValue *v7; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx
  lua_TValue *t; // [esp+8h] [ebp-8h]
  lua_TValue *top; // [esp+Ch] [ebp-4h]

  v2 = (Table **)index2adr(L, idx);
  v3 = *v2;
  t = (lua_TValue *)v2;
  v4 = L->top - 2;
  top = L->top;
  v5 = (lua_TValue *)luaH_get(t: *v2, key: v4);
  v3->flags &= 0x40u;
  if ( v5 == &luaO_nilobject_ )
  {
    tt = v4->tt;
    if ( tt == 0 )
      luaG_runerror(L, fmt: "table index is nil");
    v5 = newkey(L, t: v3, key: v4);
  }
  v5->value.b = top[-1].value.b;
  *(&v5->value.b + 1) = *(&top[-1].value.b + 1);
  v5->tt = top[-1].tt;
  v7 = L->top;
  if ( v7[-1].tt >= 4 && (*(_BYTE *)(v7[-1].value.b + 5) & 3) != 0 )
  {
    b = (GCObject *)t->value.b;
    if ( (*(_BYTE *)(t->value.b + 5) & 4) != 0 )
    {
      l_G = L->l_G;
      b->gch.marked &= ~4u;
      b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
      l_G->grayagain = b;
    }
  }
  L->top -= 2;
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: _lua_rawseti
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_rawseti(int idx@<eax>, int n@<edi>, lua_TValue *L)
{
  Table **v4; // eax
  lua_TValue *tt; // esi
  lua_TValue *v6; // eax
  GCObject *b; // eax
  global_State *gc; // ecx
  lua_TValue *o; // [esp+10h] [ebp+8h]

  v4 = (Table **)index2adr((lua_State *)L, idx);
  tt = (lua_TValue *)L->tt;
  o = (lua_TValue *)v4;
  *luaH_setnum((lua_State *)L, t: *v4, key: n) = tt[-1];
  v6 = (lua_TValue *)L->tt;
  if ( v6[-1].tt >= 4 && (*(_BYTE *)(v6[-1].value.b + 5) & 3) != 0 )
  {
    b = (GCObject *)o->value.b;
    if ( (*(_BYTE *)(o->value.b + 5) & 4) != 0 )
    {
      gc = (global_State *)L[1].value.gc;
      b->gch.marked &= ~4u;
      b->cl.c.upvalue[0].value.b = (int)gc->grayagain;
      gc->grayagain = b;
    }
  }
  L->tt -= 16;
}

//------------------------------------------------------------------------------
// Address: 0x10001900
// Name: _lua_setmetatable
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_setmetatable@<eax>(lua_State *L@<esi>, int objindex@<eax>)
{
  lua_TValue *v2; // eax
  lua_TValue *top; // ecx
  GCObject *gc; // edx
  int tt; // ecx
  GCObject *v7; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx

  v2 = index2adr(L, idx: objindex);
  top = L->top;
  if ( top[-1].tt != 0 )
    gc = top[-1].value.gc;
  else
    gc = nullptr;
  tt = v2->tt;
  if ( tt == 5 )
  {
    *(_DWORD *)(v2->value.b + 8) = gc;
    if ( gc != nullptr && (gc->gch.marked & 3) != 0 )
    {
      b = (GCObject *)v2->value.b;
      if ( (b->gch.marked & 4) != 0 )
      {
        l_G = L->l_G;
        b->gch.marked &= ~4u;
        b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
        l_G->grayagain = b;
      }
    }
  }
  else
  {
    if ( tt != 7 )
    {
      L->l_G->mt[tt] = (Table *)gc;
      --L->top;
      return 1;
    }
    *(_DWORD *)(v2->value.b + 8) = gc;
    if ( gc != nullptr && (gc->gch.marked & 3) != 0 )
    {
      v7 = (GCObject *)v2->value.b;
      if ( (v7->gch.marked & 4) != 0 )
      {
        luaC_barrierf(L, o: v7, v: gc);
        --L->top;
        return 1;
      }
    }
  }
  --L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100019A0
// Name: _lua_setfenv
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_setfenv@<eax>(lua_State *L@<esi>, int idx@<eax>)
{
  lua_TValue *v2; // eax
  int b; // ecx
  GCObject *gc; // edx
  int v6; // eax
  global_State *l_G; // ecx

  v2 = index2adr(L, idx);
  switch ( v2->tt )
  {
    case 6:
      *(_DWORD *)(v2->value.b + 12) = L->top[-1].value.gc;
      break;
    case 7:
      *(_DWORD *)(v2->value.b + 12) = L->top[-1].value.gc;
      break;
    case 8:
      b = v2->value.b;
      *(_DWORD *)(b + 72) = L->top[-1].value.gc;
      *(_DWORD *)(b + 80) = 5;
      break;
    default:
      --L->top;
      return 0;
  }
  gc = L->top[-1].value.gc;
  if ( (gc->gch.marked & 3) != 0 )
  {
    v6 = v2->value.b;
    if ( (*(_BYTE *)(v6 + 5) & 4) != 0 )
    {
      l_G = L->l_G;
      if ( l_G->gcstate == 1 )
      {
        reallymarkobject(g: l_G, o: gc);
        --L->top;
        return 1;
      }
      *(_BYTE *)(v6 + 5) = *(_BYTE *)(v6 + 5) & 0xF8 | l_G->currentwhite & 3;
    }
  }
  --L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001A40
// Name: _lua_call
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_call(lua_State *L@<ecx>, int nargs@<eax>, int nresults@<edi>)
{
  CallInfo *ci; // eax
  lua_TValue *top; // esi
  int v6; // [esp+0h] [ebp-8h]

  luaD_call(L, func: &L->top[-nargs - 1], nResults: v6);
  if ( nresults == -1 )
  {
    ci = L->ci;
    top = L->top;
    if ( top >= ci->top )
      ci->top = top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: f_call
// Source: json
//------------------------------------------------------------------------------
void __cdecl f_call(lua_State *L, void *ud)
{
  luaD_call(L, func: *(lua_TValue **)ud, nResults: *((_DWORD *)ud + 1));
}

//------------------------------------------------------------------------------
// Address: 0x10001A90
// Name: _lua_load
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_load@<eax>(
        const char *(__cdecl *reader)(lua_State *, void *, unsigned int *)@<edx>,
        const char *chunkname@<eax>,
        lua_State *L,
        void *data)
{
  int v4; // eax
  int errfunc; // edx
  int v6; // eax
  global_State *l_G; // esi
  int v8; // edi
  unsigned int v9; // ebx
  Zio *u; // [esp+10h] [ebp-28h] BYREF
  void *v12; // [esp+14h] [ebp-24h]
  unsigned int v13; // [esp+1Ch] [ebp-1Ch]
  const char *v14; // [esp+20h] [ebp-18h]
  Zio z; // [esp+24h] [ebp-14h] BYREF

  if ( chunkname == nullptr )
    chunkname = "?";
  v14 = chunkname;
  v4 = (char *)L->top - (char *)L->stack;
  z.reader = reader;
  z.data = data;
  z.n = 0;
  z.p = nullptr;
  v12 = nullptr;
  v13 = 0;
  u = &z;
  errfunc = L->errfunc;
  z.L = L;
  v6 = luaD_pcall(L, func: f_parser, &u, old_top: v4, ef: errfunc);
  l_G = L->l_G;
  v8 = v6;
  v9 = v13;
  l_G->frealloc(a1: l_G->ud, a2: v12, a3: v13, a4: 0);
  l_G->totalbytes -= v9;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10001B20
// Name: _lua_gc
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_gc@<eax>(int data@<eax>, int g@<esi>, int a3@<ecx>, lua_State *L, int res)
{
  int result; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int v8; // edi
  int v9; // edi

  switch ( a3 )
  {
    case 0:
      *(_DWORD *)(g + 64) = -3;
      result = res;
      break;
    case 1:
      *(_DWORD *)(g + 64) = *(_DWORD *)(g + 68);
      result = res;
      break;
    case 2:
      luaC_fullgc(L);
      result = res;
      break;
    case 3:
      result = *(_DWORD *)(g + 68) >> 10;
      break;
    case 4:
      result = *(_DWORD *)(g + 68) & 0x3FF;
      break;
    case 5:
      v6 = *(_DWORD *)(g + 68);
      v7 = data << 10;
      if ( v7 > v6 )
        *(_DWORD *)(g + 64) = 0;
      else
        *(_DWORD *)(g + 64) = v6 - v7;
      if ( *(_DWORD *)(g + 64) > v6 )
      {
        result = res;
      }
      else
      {
        while ( 1 )
        {
          luaC_step(L);
          if ( *(_BYTE *)(g + 21) == 0 )
            break;
          if ( *(_DWORD *)(g + 64) > *(_DWORD *)(g + 68) )
            return res;
        }
        result = 1;
      }
      break;
    case 6:
      v8 = *(_DWORD *)(g + 80);
      *(_DWORD *)(g + 80) = data;
      result = v8;
      break;
    case 7:
      v9 = *(_DWORD *)(g + 84);
      *(_DWORD *)(g + 84) = data;
      result = v9;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001C00
// Name: _lua_concat
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_concat(lua_State *L@<esi>, int n@<eax>)
{
  lua_TValue *top; // edi

  if ( n < 2 )
  {
    if ( n == 0 )
    {
      top = L->top;
      top->value.b = (int)luaS_newlstr(L, str: Ptr, l: 0);
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
// Address: 0x10001C70
// Name: _lua_getupvalue
// Source: json
//------------------------------------------------------------------------------
const char *__usercall lua_getupvalue@<eax>(lua_State *L@<edi>, int n@<eax>)
{
  lua_TValue *v3; // eax
  const char *result; // eax
  int b; // eax
  lua_TValue *v6; // ecx
  int v7; // edx
  int v8; // edx

  v3 = index2adr(L, idx: 1);
  if ( v3->tt != 6 )
    return nullptr;
  b = v3->value.b;
  if ( *(_BYTE *)(b + 6) == 0 )
  {
    v7 = *(_DWORD *)(b + 16);
    if ( n >= 1 && n <= *(_DWORD *)(v7 + 36) )
    {
      v6 = *(lua_TValue **)(*(_DWORD *)(b + 4 * n + 16) + 8);
      v8 = *(_DWORD *)(v7 + 28);
      result = (const char *)(*(_DWORD *)(v8 + 4 * n - 4) + 24);
      if ( *(_DWORD *)(v8 + 4 * n - 4) == -24 )
        return result;
      goto LABEL_10;
    }
    return nullptr;
  }
  if ( n < 1 || n > *(unsigned __int8 *)(b + 7) )
    return nullptr;
  v6 = (lua_TValue *)(b + 16 * n + 8);
  result = Ptr;
LABEL_10:
  *L->top++ = *v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: _lua_setupvalue
// Source: json
//------------------------------------------------------------------------------
const char *__usercall lua_setupvalue@<eax>(lua_State *L@<edi>, int n@<eax>)
{
  lua_TValue *v3; // eax
  int b; // ecx
  lua_TValue *v6; // ecx
  const char *v7; // esi
  int v8; // edx
  lua_TValue *top; // ecx
  GCObject *v10; // ecx
  GCObject *v11; // eax

  v3 = index2adr(L, idx: 1);
  if ( v3->tt != 6 )
    return nullptr;
  b = v3->value.b;
  if ( *(_BYTE *)(v3->value.b + 6) != 0 )
  {
    if ( n >= 1 && n <= *(unsigned __int8 *)(b + 7) )
    {
      v6 = (lua_TValue *)(b + 16 * n + 8);
      v7 = Ptr;
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
    return nullptr;
  }
  v8 = *(_DWORD *)(b + 16);
  if ( n < 1 || n > *(_DWORD *)(v8 + 36) )
    return nullptr;
  v6 = *(lua_TValue **)(*(_DWORD *)(b + 4 * n + 16) + 8);
  v7 = (const char *)(*(_DWORD *)(*(_DWORD *)(v8 + 28) + 4 * n - 4) + 24);
  if ( v7 != nullptr )
    goto LABEL_10;
  return v7;
}
