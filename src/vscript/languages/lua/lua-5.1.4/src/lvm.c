// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lvm.c
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100204E0
// Name: _luaV_tostring
// Source: json
//------------------------------------------------------------------------------
int __usercall luaV_tostring@<eax>(lua_TValue *obj@<esi>, lua_State *L)
{
  char s[32]; // [esp+28h] [ebp-20h] BYREF

  if ( obj->tt != 3 )
    return 0;
  sprintf(string: s, format: "%.14g", (double)obj->value.n);
  obj->value.b = (int)luaS_newlstr(L, str: s, l: strlen(s));
  obj->tt = 4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10020550
// Name: traceexec
// Source: json
//------------------------------------------------------------------------------
void __usercall traceexec(lua_State *L@<esi>, const unsigned int *pc)
{
  unsigned __int8 v2; // al
  const unsigned int *savedpc; // edi
  unsigned int len; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // ebx
  int v8; // ecx
  unsigned __int8 mask; // [esp+Bh] [ebp-1h]

  savedpc = L->savedpc;
  mask = L->hookmask;
  v2 = mask;
  L->savedpc = pc;
  if ( (mask & 8) != 0 && L->hookcount == 0 )
  {
    L->hookcount = L->basehookcount;
    luaD_callhook(L, event: 3, line: -1);
    v2 = mask;
  }
  if ( (v2 & 4) != 0 )
  {
    len = L->ci->func->value.gc->ts.tsv.len;
    v5 = *(_DWORD *)(len + 12);
    v6 = *(_DWORD *)(len + 20);
    v7 = v6 != 0 ? *(_DWORD *)(v6 + 4 * ((((int)pc - v5) >> 2) - 1)) : 0;
    if ( ((int)pc - v5) >> 2 == 1
      || pc <= savedpc
      || (v6 == 0 ? (v8 = 0) : (v8 = *(_DWORD *)(v6 + 4 * (((int)savedpc - v5) >> 2) - 4)), v7 != v8) )
    {
      luaD_callhook(L, event: 2, line: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100205F0
// Name: callTMres
// Source: json
//------------------------------------------------------------------------------
void __cdecl callTMres(lua_State *L, lua_TValue *res, const lua_TValue *f, const lua_TValue *p1, const lua_TValue *p2)
{
  int v5; // edi
  int stacksize; // eax
  int v7; // eax

  v5 = (char *)res - (char *)L->stack;
  *L->top = *f;
  L->top[1] = *p1;
  L->top[2] = *p2;
  if ( (char *)L->stack_last - (char *)L->top <= 48 )
  {
    stacksize = L->stacksize;
    if ( stacksize < 3 )
      v7 = stacksize + 3;
    else
      v7 = 2 * stacksize;
    luaD_reallocstack(L, newsize: v7);
  }
  L->top += 3;
  luaD_call(L, func: L->top - 3, nResults: 1);
  *(lua_TValue *)((char *)L->stack + v5) = *--L->top;
}

//------------------------------------------------------------------------------
// Address: 0x100206A0
// Name: callTM
// Source: json
//------------------------------------------------------------------------------
void __fastcall callTM(
        const lua_TValue *p3,
        const lua_TValue *p2,
        lua_State *L,
        const lua_TValue *f,
        const lua_TValue *p1)
{
  int stacksize; // eax
  int v6; // eax

  *L->top = *f;
  L->top[1] = *p1;
  L->top[2] = *p2;
  L->top[3] = *p3;
  if ( (char *)L->stack_last - (char *)L->top <= 64 )
  {
    stacksize = L->stacksize;
    if ( stacksize < 4 )
      v6 = stacksize + 4;
    else
      v6 = 2 * stacksize;
    luaD_reallocstack(L, newsize: v6);
  }
  L->top += 4;
  luaD_call(L, func: L->top - 4, nResults: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10020740
// Name: _luaV_gettable
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_gettable(lua_State *L, Node *t, lua_TValue *key, lua_TValue *val)
{
  const lua_TValue *p_i_val; // ebx
  int tt; // eax
  int b; // esi
  Node *v7; // ebx
  Table *v8; // edi
  Node *v9; // eax
  Node *v10; // edi
  Table *v11; // eax
  int loop; // [esp+Ch] [ebp-4h]

  loop = 0;
  while ( 1 )
  {
    p_i_val = &t->i_val;
    tt = t->i_val.tt;
    if ( tt != 5 )
    {
      if ( tt == 7 )
        v11 = *(Table **)(t->i_val.value.b + 8);
      else
        v11 = L->l_G->mt[tt];
      if ( v11 != nullptr )
        v10 = luaH_getstr(t: v11, key: L->l_G->tmname[0]);
      else
        v10 = (Node *)&luaO_nilobject_;
      if ( v10->i_val.tt == 0 )
        luaG_typeerror(L, o: &t->i_val, op: "index");
      goto LABEL_19;
    }
    b = t->i_val.value.b;
    v7 = luaH_get(t: (Table *)t->i_val.value.gc, key);
    if ( v7->i_val.tt != 0 || (v8 = *(Table **)(b + 8)) == nullptr )
    {
LABEL_22:
      *val = v7->i_val;
      return;
    }
    if ( (v8->flags & 1) != 0 )
      goto LABEL_8;
    v9 = luaH_getstr(t: v8, key: L->l_G->tmname[0]);
    if ( v9->i_val.tt == 0 )
    {
      v8->flags |= 1u;
LABEL_8:
      v9 = nullptr;
    }
    v10 = v9;
    if ( v9 == nullptr )
      goto LABEL_22;
    p_i_val = &t->i_val;
LABEL_19:
    if ( v10->i_val.tt == 6 )
      break;
    t = v10;
    if ( ++loop >= 100 )
      luaG_runerror(L, fmt: "loop in gettable");
  }
  callTMres(L, res: val, f: &v10->i_val, p1: p_i_val, p2: key);
}

//------------------------------------------------------------------------------
// Address: 0x10020890
// Name: _luaV_settable
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_settable(lua_State *L, Node *t, lua_TValue *key, lua_TValue *val)
{
  const lua_TValue *p_i_val; // ebx
  int tt; // eax
  GCObject *b; // esi
  Node *v7; // eax
  int v8; // eax
  lua_TValue *v9; // ebx
  Table *metatable; // edi
  Node *v11; // eax
  Node *v12; // edi
  Table *v13; // eax
  unsigned __int8 marked; // al
  global_State *l_G; // ecx
  int loop; // [esp+Ch] [ebp-4h]

  loop = 0;
  while ( 1 )
  {
    p_i_val = &t->i_val;
    tt = t->i_val.tt;
    if ( tt != 5 )
    {
      if ( tt == 7 )
        v13 = *(Table **)(t->i_val.value.b + 8);
      else
        v13 = L->l_G->mt[tt];
      if ( v13 != nullptr )
        v12 = luaH_getstr(t: v13, key: L->l_G->tmname[1]);
      else
        v12 = (Node *)&luaO_nilobject_;
      if ( v12->i_val.tt == 0 )
        luaG_typeerror(L, o: &t->i_val, op: "index");
      goto LABEL_23;
    }
    b = (GCObject *)t->i_val.value.b;
    v7 = luaH_get(t: (Table *)t->i_val.value.gc, key);
    b->ts.tsv.reserved &= 0x40u;
    if ( v7 == (Node *)&luaO_nilobject_ )
    {
      v8 = key->tt;
      if ( v8 == 0 )
        luaG_runerror(L, fmt: "table index is nil");
      v7 = newkey(L, t: b, key);
    }
    v9 = &v7->i_val;
    if ( v7->i_val.tt != 0 )
      break;
    metatable = b->u.uv.metatable;
    if ( metatable == nullptr )
      break;
    if ( (metatable->flags & 2) != 0 )
      goto LABEL_12;
    v11 = luaH_getstr(t: metatable, key: L->l_G->tmname[1]);
    if ( v11->i_val.tt == 0 )
    {
      metatable->flags |= 2u;
LABEL_12:
      v11 = nullptr;
    }
    v12 = v11;
    if ( v11 == nullptr )
      break;
    p_i_val = &t->i_val;
LABEL_23:
    if ( v12->i_val.tt == 6 )
    {
      callTM(p3: val, p2: key, L, f: &v12->i_val, p1: p_i_val);
      return;
    }
    t = v12;
    if ( ++loop >= 100 )
      luaG_runerror(L, fmt: "loop in settable");
  }
  *v9 = *val;
  if ( val->tt >= 4 && (*(_BYTE *)(val->value.b + 5) & 3) != 0 )
  {
    marked = b->gch.marked;
    if ( (marked & 4) != 0 )
    {
      l_G = L->l_G;
      b->gch.marked = marked & 0xFB;
      b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
      l_G->grayagain = b;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A50
// Name: call_binTM
// Source: json
//------------------------------------------------------------------------------
int __cdecl call_binTM(lua_State *L, const lua_TValue *p1, const lua_TValue *p2, lua_TValue *res, TMS event)
{
  Table *v5; // eax
  Node *v6; // eax
  Table *v7; // eax

  if ( p1->tt == 5 )
  {
    v5 = *(Table **)(p1->value.b + 8);
  }
  else if ( p1->tt == 7 )
  {
    v5 = *(Table **)(p1->value.b + 8);
  }
  else
  {
    v5 = L->l_G->mt[p1->tt];
  }
  if ( v5 != nullptr )
    v6 = luaH_getstr(t: v5, key: L->l_G->tmname[event]);
  else
    v6 = (Node *)&luaO_nilobject_;
  if ( v6->i_val.tt == 0 )
  {
    if ( p2->tt == 5 )
      v7 = *(Table **)(p2->value.b + 8);
    else
      v7 = p2->tt == 7 ? *(Table **)(p2->value.b + 8) : L->l_G->mt[p2->tt];
    v6 = v7 != nullptr ? luaH_getstr(t: v7, key: L->l_G->tmname[event]) : (Node *)&luaO_nilobject_;
    if ( v6->i_val.tt == 0 )
      return 0;
  }
  callTMres(L, res, f: &v6->i_val, p1, p2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10020B30
// Name: get_compTM
// Source: json
//------------------------------------------------------------------------------
const lua_TValue *__usercall get_compTM@<eax>(Table *mt1@<esi>, Table *mt2@<edi>, lua_State *L)
{
  const lua_TValue *p_i_val; // ebx
  Node *v4; // eax
  Node *v6; // eax

  if ( mt1 == nullptr )
    return nullptr;
  if ( (mt1->flags & 0x10) != 0 )
  {
    p_i_val = nullptr;
  }
  else
  {
    v4 = luaH_getstr(t: mt1, key: L->l_G->tmname[4]);
    if ( v4->i_val.tt != 0 )
    {
      p_i_val = &v4->i_val;
    }
    else
    {
      mt1->flags |= 0x10u;
      p_i_val = nullptr;
    }
  }
  if ( p_i_val == nullptr )
    return nullptr;
  if ( mt1 == mt2 )
    return p_i_val;
  if ( mt2 == nullptr )
    return nullptr;
  if ( (mt2->flags & 0x10) == 0 )
  {
    v6 = luaH_getstr(t: mt2, key: L->l_G->tmname[4]);
    if ( v6->i_val.tt != 0 )
      goto LABEL_16;
    mt2->flags |= 0x10u;
  }
  v6 = nullptr;
LABEL_16:
  if ( v6 == nullptr )
    return nullptr;
  return luaO_rawequalObj(t1: p_i_val, t2: &v6->i_val) ? p_i_val : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10020BC0
// Name: call_orderTM
// Source: json
//------------------------------------------------------------------------------
int __usercall call_orderTM@<eax>(lua_State *L@<edi>, const lua_TValue *p1, const lua_TValue *p2, TMS event)
{
  Table *v4; // ecx
  Node *v5; // esi
  int result; // eax
  const lua_TValue *v7; // edx
  Table *v8; // eax
  Node *v9; // eax
  int tt; // ecx
  lua_TValue *top; // ecx
  int v12; // eax

  if ( p1->tt == 5 )
  {
    v4 = *(Table **)(p1->value.b + 8);
  }
  else if ( p1->tt == 7 )
  {
    v4 = *(Table **)(p1->value.b + 8);
  }
  else
  {
    v4 = L->l_G->mt[p1->tt];
  }
  if ( v4 != nullptr )
    v5 = luaH_getstr(t: v4, key: L->l_G->tmname[event]);
  else
    v5 = (Node *)&luaO_nilobject_;
  if ( v5->i_val.tt == 0 )
    return -1;
  v7 = p2;
  if ( p2->tt == 5 )
    v8 = *(Table **)(p2->value.b + 8);
  else
    v8 = p2->tt == 7 ? *(Table **)(p2->value.b + 8) : L->l_G->mt[p2->tt];
  if ( v8 != nullptr )
  {
    v9 = luaH_getstr(t: v8, key: L->l_G->tmname[event]);
    v7 = p2;
  }
  else
  {
    v9 = (Node *)&luaO_nilobject_;
  }
  tt = v5->i_val.tt;
  if ( tt != v9->i_val.tt )
    return -1;
  switch ( tt )
  {
    case 0:
      goto $LN1_2;
    case 3:
      if ( v5->i_val.value.n == v9->i_val.value.n )
        goto $LN1_2;
      result = -1;
      break;
    default:
      if ( v5->i_val.value.b != v9->i_val.value.b )
        return -1;
$LN1_2:
      callTMres(L, res: L->top, f: &v5->i_val, p1, p2: v7);
      top = L->top;
      v12 = top->tt;
      result = v12 != 0 && (v12 != 1 || top->value.b != 0);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020CF0
// Name: l_strcmp
// Source: json
//------------------------------------------------------------------------------
int __usercall l_strcmp@<eax>(const TString *ls@<ecx>, const TString *rs@<eax>)
{
  unsigned int len; // ebx
  const char *v3; // edi
  const char *v4; // esi
  int result; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int ll; // [esp+Ch] [ebp-4h]

  len = rs->tsv.len;
  v3 = (const char *)&rs[1];
  v4 = (const char *)&ls[1];
  ll = ls->tsv.len;
  result = strcoll(_string1: (const char *)&ls[1], _string2: (const char *)&rs[1]);
  if ( result == 0 )
  {
    while ( 1 )
    {
      v6 = strlen(v4);
      if ( v6 == len )
        return v6 != ll;
      if ( v6 == ll )
        break;
      v7 = v6 + 1;
      ll -= v7;
      v3 += v7;
      v4 += v7;
      len -= v7;
      result = strcoll(_string1: v4, _string2: v3);
      if ( result != 0 )
        return result;
    }
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020D70
// Name: _luaV_lessthan
// Source: json
//------------------------------------------------------------------------------
int __usercall luaV_lessthan@<eax>(lua_State *L@<ecx>, const lua_TValue *l@<eax>, const lua_TValue *r)
{
  int tt; // eax
  int v6; // ecx
  const char *v7; // eax
  const char *v8; // ecx
  int result; // eax

  tt = l->tt;
  v6 = r->tt;
  if ( tt != v6 )
  {
    v7 = luaT_typenames[tt];
    v8 = luaT_typenames[v6];
    if ( v7[2] == v8[2] )
      luaG_runerror(L, fmt: "attempt to compare two %s values", v7);
    luaG_runerror(L, fmt: "attempt to compare %s with %s", v7, v8);
  }
  if ( tt == 3 )
    return r->value.n > l->value.n;
  if ( tt == 4 )
    return l_strcmp(ls: (const TString *)l->value.gc, rs: (const TString *)r->value.gc) < 0;
  result = call_orderTM(L, p1: l, p2: r, event: TM_LT);
  if ( result == -1 )
    luaG_ordererror(L, p1: l, p2: r);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020E20
// Name: lessequal
// Source: json
//------------------------------------------------------------------------------
int __usercall lessequal@<eax>(lua_State *L@<ecx>, const lua_TValue *l@<eax>, const lua_TValue *r)
{
  int tt; // eax
  int v6; // ecx
  const char *v7; // eax
  const char *v8; // ecx
  int result; // eax
  int v10; // eax

  tt = l->tt;
  v6 = r->tt;
  if ( tt != v6 )
  {
    v7 = luaT_typenames[tt];
    v8 = luaT_typenames[v6];
    if ( v7[2] == v8[2] )
      luaG_runerror(L, fmt: "attempt to compare two %s values", v7);
    luaG_runerror(L, fmt: "attempt to compare %s with %s", v7, v8);
  }
  if ( tt == 3 )
    return r->value.n >= l->value.n;
  if ( tt == 4 )
    return l_strcmp(ls: (const TString *)l->value.gc, rs: (const TString *)r->value.gc) <= 0;
  result = call_orderTM(L, p1: l, p2: r, event: TM_LE);
  if ( result == -1 )
  {
    v10 = call_orderTM(L, p1: r, p2: l, event: TM_LT);
    if ( v10 == -1 )
      luaG_ordererror(L, p1: l, p2: r);
    return v10 == 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020EF0
// Name: _luaV_equalval
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaV_equalval(lua_State *L, const lua_TValue *t1, const lua_TValue *t2)
{
  int result; // eax
  int b; // ecx
  const lua_TValue *compTM; // eax
  lua_TValue *top; // ebx

  switch ( t1->tt )
  {
    case 0:
      return 1;
    case 2:
      return t1->value.b == t2->value.b;
    case 3:
      return t1->value.n == t2->value.n;
    case 5:
      b = t2->value.b;
      goto LABEL_8;
    case 7:
      b = t2->value.b;
LABEL_8:
      if ( t1->value.b == b )
        return 1;
      compTM = get_compTM(mt1: *(Table **)(t1->value.b + 8), mt2: *(Table **)(b + 8), L);
      if ( compTM == nullptr )
        return 0;
      callTMres(L, res: L->top, f: compTM, p1: t1, p2: t2);
      top = L->top;
      result = top->tt;
      if ( result == 0 )
        return 0;
      if ( result != 1 )
        return 1;
      if ( top->value.b == 0 )
        return 0;
      return result;
    default:
      return t1->value.b == t2->value.b;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020FE0
// Name: _luaV_concat
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_concat(lua_State *L, int total, int last)
{
  lua_TValue *v3; // ebx
  int tt; // eax
  unsigned int v5; // eax
  lua_TValue *v6; // esi
  const lua_TValue *v7; // ebx
  lua_TValue *v8; // eax
  int v9; // esi
  const char *v10; // ebx
  CallInfo *ci; // edx
  lua_TValue *base; // ecx
  lua_TValue *top; // esi
  const char *v14; // eax
  lua_TValue *v15; // esi
  unsigned int v16; // ecx
  global_State *l_G; // esi
  unsigned int buffsize; // ecx
  char *v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  unsigned int v22; // edi
  int *v23; // eax
  int v24; // eax
  unsigned int v25; // esi
  _DWORD *p_b; // ebx
  int n; // [esp+18h] [ebp-30h]
  unsigned int tl; // [esp+1Ch] [ebp-2Ch] BYREF
  int i; // [esp+20h] [ebp-28h]
  unsigned int l; // [esp+24h] [ebp-24h]
  char string[32]; // [esp+28h] [ebp-20h] BYREF

  do
  {
    v3 = &L->base[last + 1];
    tt = v3[-2].tt;
    n = 2;
    if ( tt == 4 || tt == 3 )
    {
      if ( v3[-1].tt == 4 )
        goto LABEL_6;
      if ( v3[-1].tt == 3 )
      {
        sprintf(string, format: "%.14g", (double)v3[-1].value.n);
        v3[-1].value.b = (int)luaS_newlstr(L, str: string, l: strlen(string));
        v3[-1].tt = 4;
LABEL_6:
        v5 = *(_DWORD *)(v3[-1].value.b + 16);
        if ( v5 != 0 )
        {
          tl = *(_DWORD *)(v3[-1].value.b + 16);
          n = 1;
          if ( total > 1 )
          {
            v15 = v3 - 2;
            do
            {
              if ( v15->tt != 4 )
              {
                if ( v15->tt != 3 )
                  break;
                sprintf(string, format: "%.14g", (double)v15->value.n);
                v15->value.b = (int)luaS_newlstr(L, str: string, l: strlen(string));
                v5 = tl;
                v15->tt = 4;
              }
              v16 = *(_DWORD *)(v15->value.b + 16);
              l = v16;
              if ( v16 >= -3 - v5 )
                luaG_runerror(L, fmt: "string length overflow");
              v5 += v16;
              --v15;
              tl = v5;
              ++n;
            }
            while ( n < total );
          }
          l_G = L->l_G;
          buffsize = l_G->buff.buffsize;
          tl = v5;
          if ( v5 > buffsize )
          {
            if ( v5 < 0x20 )
            {
              tl = 32;
              v5 = 32;
            }
            if ( v5 + 1 > 0xFFFFFFFD )
              luaG_runerror(L, fmt: "memory allocation error: block too big");
            v19 = (char *)luaM_realloc_(L, block: l_G->buff.buffer, osize: buffsize, nsize: v5);
            v20 = tl;
            l_G->buff.buffer = v19;
            l_G->buff.buffsize = v20;
          }
          v21 = n;
          v22 = 0;
          l = (unsigned int)l_G->buff.buffer;
          i = n;
          if ( n > 0 )
          {
            v23 = (int *)&v3[-n];
            for ( tl = (unsigned int)v23; ; v23 = (int *)tl )
            {
              v24 = *v23;
              v25 = *(_DWORD *)(v24 + 16);
              memcpy(dst: (unsigned __int8 *)(v22 + l), src: (unsigned __int8 *)(v24 + 24), count: v25);
              tl += 16;
              v22 += v25;
              if ( --i <= 0 )
                break;
            }
            v21 = n;
          }
          p_b = &v3[-v21].value.b;
          *p_b = luaS_newlstr(L, str: (char *)l, l: v22);
          p_b[2] = 4;
        }
        else if ( v3[-2].tt == 3 )
        {
          sprintf(string, format: "%.14g", (double)v3[-2].value.n);
          v3[-2].value.b = (int)luaS_newlstr(L, str: string, l: strlen(string));
          v3[-2].tt = 4;
        }
        goto LABEL_39;
      }
    }
    v6 = v3 - 2;
    v7 = v3 - 1;
    if ( call_binTM(L, p1: v6, p2: v7, res: v6, event: TM_CONCAT) == 0 )
    {
      v8 = v6;
      v9 = v6->tt;
      if ( v9 == 4 || v9 == 3 )
        v8 = (lua_TValue *)v7;
      v10 = luaT_typenames[v8->tt];
      ci = L->ci;
      tl = 0;
      base = ci->base;
      top = ci->top;
      if ( ci->base < top )
      {
        while ( v8 != base )
        {
          if ( ++base >= top )
            goto LABEL_16;
        }
        v14 = getobjname(L, ci, stackpos: v8 - L->base, name: (const char **)&tl);
        if ( v14 != nullptr )
          luaG_runerror(L, fmt: "attempt to %s %s '%s' (a %s value)", "concatenate", v14, (const char *)tl, v10);
      }
LABEL_16:
      luaG_runerror(L, fmt: "attempt to %s a %s value", "concatenate", v10);
    }
LABEL_39:
    last += 1 - n;
    total += 1 - n;
  }
  while ( total > 1 );
}

//------------------------------------------------------------------------------
// Address: 0x10021340
// Name: Arith
// Source: json
//------------------------------------------------------------------------------
void __cdecl Arith(lua_State *L, lua_TValue *ra, const lua_TValue *rb, lua_TValue *rc, TMS op)
{
  const lua_TValue *v5; // edi
  int tt; // eax
  lua_TValue *p_tempc; // esi
  int v8; // eax
  double v9; // xmm0_8
  double n; // xmm1_8
  __m128d v11; // xmm4
  __m128d v12; // xmm5
  double v13; // xmm3_8
  double v14; // xmm3_8
  int v15; // eax
  long double v16; // [esp+0h] [ebp-34h]
  lua_TValue tempb; // [esp+8h] [ebp-2Ch] BYREF
  lua_TValue tempc; // [esp+18h] [ebp-1Ch] BYREF
  long double result; // [esp+28h] [ebp-Ch] BYREF

  v5 = rb;
  tt = rb->tt;
  if ( tt == 3 )
  {
    HIDWORD(result) = rb;
  }
  else
  {
    if ( tt != 4 )
      goto LABEL_19;
    v5 = rb;
    if ( !luaO_str2d(s: (char *)(rb->value.b + 24), &result) )
      goto LABEL_19;
    tempb.value.n = result;
    tempb.tt = 3;
    HIDWORD(result) = &tempb;
  }
  p_tempc = rc;
  v8 = rc->tt;
  if ( v8 == 3 )
    goto LABEL_10;
  if ( v8 != 4 )
  {
LABEL_20:
    if ( call_binTM(L, p1: v5, p2: p_tempc, res: ra, event: op) != 0 )
      return;
    v15 = v5->tt;
    HIDWORD(result) = p_tempc;
    if ( v15 != 3 )
    {
      if ( v15 == 4 )
      {
        if ( luaO_str2d(s: (char *)(v5->value.b + 24), result: (long double *)&tempc.tt) )
          goto LABEL_26;
        v5 = rb;
      }
      HIDWORD(result) = v5;
    }
LABEL_26:
    luaG_typeerror(L, o: (const lua_TValue *)HIDWORD(result), op: "perform arithmetic on");
  }
  if ( !luaO_str2d(s: (char *)(rc->value.b + 24), result: (long double *)&tempc.tt) )
  {
    v5 = rb;
LABEL_19:
    p_tempc = rc;
    goto LABEL_20;
  }
  tempc.value.n = *(long double *)&tempc.tt;
  tempc.tt = 3;
  p_tempc = &tempc;
LABEL_10:
  v9 = *(double *)HIDWORD(result);
  n = p_tempc->value.n;
  switch ( op )
  {
    case TM_ADD:
      ra->value.n = n + v9;
      ra->tt = 3;
      break;
    case TM_SUB:
      ra->value.n = v9 - n;
      ra->tt = 3;
      break;
    case TM_MUL:
      ra->value.n = n * v9;
      ra->tt = 3;
      break;
    case TM_DIV:
      ra->value.n = v9 / n;
      ra->tt = 3;
      break;
    case TM_MOD:
      v11.m128d_f64[0] = 4.503599627370496e15;
      v12 = _mm_and_pd((__m128d)0x8000000000000000uLL, (__m128d)COERCE_UNSIGNED_INT64(v9 / n));
      v13 = _mm_cmplt_sd(_mm_xor_pd((__m128d)COERCE_UNSIGNED_INT64(v9 / n), v12), v11).m128d_f64[0];
      v14 = v9 / n
          + COERCE_DOUBLE(*(_QWORD *)&v13 & 0x4330000000000000LL | *(_QWORD *)&v12.m128d_f64[0])
          - COERCE_DOUBLE(*(_QWORD *)&v13 & 0x4330000000000000LL | *(_QWORD *)&v12.m128d_f64[0]);
      ra->value.n = v9
                  - (v14
                   - COERCE_DOUBLE(
                       *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v14 - v9 / n), v12).m128d_f64[0]
                     & 0x3FF0000000000000LL))
                  * n;
      ra->tt = 3;
      break;
    case TM_POW:
      __libm_sse2_pow(x: v16, y: tempb.value.n);
      ra->value.n = v9;
      ra->tt = 3;
      break;
    case TM_UNM:
      ra->value.n = -v9;
      ra->tt = 3;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021570
// Name: _luaV_execute
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_execute(GCObject *L, int nexeccalls)
{
  GCObject *v2; // edi
  int *v3; // edx
  unsigned int v4; // ebx
  unsigned __int8 hookmask; // al
  bool v6; // zf
  lua_TValue *v7; // esi
  int *v8; // ebx
  lua_TValue *v9; // ebx
  int *v10; // eax
  lua_TValue *v11; // eax
  int v12; // ebx
  int *v13; // eax
  GCObject *b; // ecx
  char v15; // al
  global_State *l_G; // esi
  lua_TValue *v17; // eax
  unsigned int v18; // ebx
  lua_TValue *v19; // ebx
  unsigned int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // ecx
  int v24; // ecx
  int v25; // edi
  GCObject *v26; // esi
  global_State *v27; // eax
  unsigned __int8 currentwhite; // dl
  int v29; // eax
  GCObject *v30; // edx
  lua_TValue *v31; // eax
  unsigned int v32; // ebx
  lua_TValue *v33; // ebx
  const lua_TValue *v34; // eax
  unsigned int v35; // ebx
  lua_TValue *v36; // ebx
  unsigned int v37; // ebx
  unsigned int v38; // ebx
  unsigned int v39; // ebx
  unsigned int v40; // ebx
  __m128d v41; // xmm2
  __m128d v42; // xmm0
  __m128d v43; // xmm4
  double v44; // xmm1_8
  double v45; // xmm1_8
  long double *v46; // eax
  unsigned int v47; // ebx
  const lua_TValue *v48; // ebx
  long double v49; // xmm0_8
  int v50; // ecx
  int tt; // eax
  long double n; // xmm0_8
  int v53; // eax
  const lua_TValue *v54; // ebx
  int v55; // eax
  int v56; // eax
  int v57; // ebx
  int v58; // eax
  int v59; // ebx
  int v60; // eax
  Table **v61; // ebx
  int v62; // eax
  lua_TValue *array; // eax
  const lua_TValue *v64; // eax
  unsigned int v65; // ebx
  const lua_TValue *v66; // ebx
  int v67; // eax
  const lua_TValue *v68; // eax
  unsigned int v69; // ebx
  const lua_TValue *v70; // ebx
  const lua_TValue *v71; // eax
  unsigned int v72; // ebx
  const lua_TValue *v73; // ebx
  int v74; // eax
  int v75; // eax
  int *v76; // eax
  int v77; // ecx
  int v78; // ecx
  unsigned int v79; // eax
  int v80; // ebx
  int v81; // eax
  unsigned int v82; // ebx
  int v83; // eax
  double v84; // xmm2_8
  double v85; // xmm0_8
  bool v86; // cf
  int v87; // eax
  int v88; // eax
  int v89; // eax
  lua_TValue *v90; // ecx
  int *v91; // eax
  int v92; // eax
  int v93; // ebx
  unsigned int v94; // ecx
  GCObject *v95; // ebx
  int v96; // eax
  Node *v97; // eax
  unsigned __int8 marked; // al
  unsigned int len; // edx
  int v100; // ecx
  int v101; // ebx
  char *v102; // ebx
  unsigned int v103; // eax
  lua_TValue *v104; // ecx
  char *v105; // eax
  unsigned int v106; // eax
  unsigned int v107; // eax
  int v108; // eax
  int v109; // ebx
  int v110; // ebx
  int v111; // eax
  int v112; // ecx
  int sizecode; // eax
  int v114; // eax
  int v115; // edx
  int v116; // ecx
  int *p_tt; // esi
  int v118; // eax
  int *lineinfo; // esi
  _DWORD *v120; // ecx
  int v121; // ebx
  unsigned int v122; // eax
  int v123; // edx
  int v124; // eax
  unsigned int v125; // eax
  GCObject *v126; // edx
  unsigned int v127; // ebx
  int v128; // eax
  TMS v129; // [esp+B14h] [ebp-CCh]
  long double v130; // [esp+B18h] [ebp-C8h]
  long double v131; // [esp+B20h] [ebp-C0h]
  unsigned int *gc; // [esp+B28h] [ebp-B8h]
  int size; // [esp+B2Ch] [ebp-B4h]
  const lua_TValue *sizea; // [esp+B2Ch] [ebp-B4h]
  TKey *sizeb; // [esp+B2Ch] [ebp-B4h]
  int sizec; // [esp+B2Ch] [ebp-B4h]
  int sized; // [esp+B2Ch] [ebp-B4h]
  GCObject **sizee; // [esp+B2Ch] [ebp-B4h]
  lua_TValue *level; // [esp+B30h] [ebp-B0h]
  lua_TValue *levela; // [esp+B30h] [ebp-B0h]
  int v141; // [esp+B34h] [ebp-ACh]
  lua_TValue *res; // [esp+B38h] [ebp-A8h]
  lua_TValue *resa; // [esp+B38h] [ebp-A8h]
  lua_TValue *resb; // [esp+B38h] [ebp-A8h]
  int *v145; // [esp+B3Ch] [ebp-A4h]
  lua_TValue *i; // [esp+B3Ch] [ebp-A4h]
  int v147; // [esp+B3Ch] [ebp-A4h]
  _DWORD *v148; // [esp+B3Ch] [ebp-A4h]
  int v149; // [esp+B40h] [ebp-A0h]
  int v150; // [esp+B40h] [ebp-A0h]
  int v151; // [esp+B40h] [ebp-A0h]
  int v152; // [esp+B40h] [ebp-A0h]
  int v153; // [esp+B44h] [ebp-9Ch]
  long double v154; // [esp+B48h] [ebp-98h] BYREF
  long double v155; // [esp+B50h] [ebp-90h] BYREF
  long double v156; // [esp+B58h] [ebp-88h] BYREF
  long double result; // [esp+B60h] [ebp-80h] BYREF
  long double v158; // [esp+B68h] [ebp-78h] BYREF
  long double v159; // [esp+B70h] [ebp-70h] BYREF
  long double v160; // [esp+B78h] [ebp-68h] BYREF
  Node t; // [esp+B80h] [ebp-60h] BYREF
  Node v162; // [esp+BA0h] [ebp-40h] BYREF
  long double v163; // [esp+BC0h] [ebp-20h] BYREF
  int v164; // [esp+BC8h] [ebp-18h]
  lua_TValue key; // [esp+BD0h] [ebp-10h] BYREF

  v2 = L;
reentry:
  v3 = *(int **)&v2->cl.l.upvals[0]->tt;
  gc = (unsigned int *)v2->cl.c.upvalue[0].value.gc;
  v153 = *v3;
  v141 = *(_DWORD *)(*(_DWORD *)(*v3 + 16) + 8);
LABEL_3:
  level = v2->h.array;
  while ( 1 )
  {
    v4 = *gc++;
    hookmask = v2->th.hookmask;
    if ( (hookmask & 0xC) != 0 )
    {
      v6 = v2->p.lastlinedefined-- == 1;
      if ( !v6 && (hookmask & 4) == 0 )
        goto LABEL_9;
      traceexec(L: (lua_State *)v2, pc: gc);
      if ( v2->ts.tsv.reserved == 1 )
        break;
      level = v2->h.array;
    }
LABEL_9:
    size = (unsigned __int8)(v4 >> 6);
    v7 = &level[size];
    v149 = size;
    res = v7;
    switch ( v4 & 0x3F )
    {
      case 0u:
        v8 = (int *)&level[v4 >> 23];
        goto LABEL_11;
      case 1u:
        v8 = (int *)(v141 + 16 * (v4 >> 14));
LABEL_11:
        v7->value.b = *v8;
        *(&v7->value.b + 1) = v8[1];
        v7->tt = v8[2];
        continue;
      case 2u:
        v7->value.b = v4 >> 23;
        v7->tt = 1;
        if ( (v4 & 0x7FC000) != 0 )
          ++gc;
        continue;
      case 3u:
        v9 = &level[v4 >> 23];
        do
        {
          v9->tt = 0;
          --v9;
        }
        while ( v9 >= v7 );
        continue;
      case 4u:
        v10 = *(int **)(*(_DWORD *)(v153 + 4 * (v4 >> 23) + 20) + 8);
        v7->value.b = *v10;
        *(&v7->value.b + 1) = v10[1];
        v7->tt = v10[2];
        continue;
      case 5u:
        t.i_val.value.b = *(_DWORD *)(v153 + 12);
        t.i_val.tt = 5;
        v2->cl.c.upvalue[0].value.b = (int)gc;
        luaV_gettable(L: (lua_State *)v2, &t, key: (lua_TValue *)(v141 + 16 * (v4 >> 14)), val: &level[size]);
        level = v2->h.array;
        continue;
      case 6u:
        v2->cl.c.upvalue[0].value.b = (int)gc;
        if ( ((v4 >> 14) & 0x100) != 0 )
          v11 = (lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 14));
        else
          v11 = &level[(v4 >> 14) & 0x1FF];
        luaV_gettable(L: (lua_State *)v2, t: (Node *)&level[v4 >> 23], key: v11, val: v7);
        goto LABEL_3;
      case 7u:
        v162.i_val.value.b = *(_DWORD *)(v153 + 12);
        v162.i_val.tt = 5;
        v2->cl.c.upvalue[0].value.b = (int)gc;
        luaV_settable(L: (lua_State *)v2, t: &v162, key: (lua_TValue *)(v141 + 16 * (v4 >> 14)), val: &level[size]);
        level = v2->h.array;
        continue;
      case 8u:
        v12 = *(_DWORD *)(v153 + 4 * (v4 >> 23) + 20);
        v13 = *(int **)(v12 + 8);
        *v13 = v7->value.b;
        v13[1] = *(&v7->value.b + 1);
        v13[2] = v7->tt;
        if ( v7->tt >= 4 )
        {
          b = (GCObject *)v7->value.b;
          if ( (*(_BYTE *)(v7->value.b + 5) & 3) != 0 )
          {
            v15 = *(_BYTE *)(v12 + 5);
            if ( (v15 & 4) != 0 )
            {
              l_G = v2->th.l_G;
              if ( l_G->gcstate == 1 )
                reallymarkobject(g: l_G, o: b);
              else
                *(_BYTE *)(v12 + 5) = v15 & 0xF8 | l_G->currentwhite & 3;
            }
          }
        }
        continue;
      case 9u:
        v2->cl.c.upvalue[0].value.b = (int)gc;
        if ( ((v4 >> 14) & 0x100) != 0 )
          v17 = (lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 14));
        else
          v17 = &level[(v4 >> 14) & 0x1FF];
        v18 = v4 >> 23;
        if ( (v18 & 0x100) != 0 )
          v19 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v18);
        else
          v19 = &level[v18];
        luaV_settable(L: (lua_State *)v2, t: (Node *)v7, key: v19, val: v17);
        level = v2->h.array;
        continue;
      case 0xAu:
        v20 = v4;
        v21 = (v4 >> 14) & 0x1FF;
        v22 = v20 >> 23;
        v23 = (v21 >> 3) & 0x1F;
        if ( v23 != 0 )
          v21 = ((v21 & 7) + 8) << (v23 - 1);
        v24 = (v22 >> 3) & 0x1F;
        if ( v24 != 0 )
          v25 = ((v22 & 7) + 8) << (v24 - 1);
        else
          v25 = v22;
        v26 = (GCObject *)luaM_realloc_((lua_State *)L, block: nullptr, osize: 0, nsize: 0x20u);
        v27 = L->th.l_G;
        v26->ts.dummy.l = (int)v27->rootgc;
        currentwhite = v27->currentwhite;
        v27->rootgc = v26;
        v26->ts.tsv.hash = 0;
        v26->ts.tsv.keyhash = 0;
        v26->h.sizearray = 0;
        v26->gch.marked = currentwhite & 3;
        v26->gch.tt = 5;
        *(_WORD *)(&v26->p.marked + 1) = 255;
        v26->ts.tsv.len = (unsigned int)&dummynode_;
        setarrayvector((lua_State *)L, t: (Table *)v26, size: v25);
        setnodevector(t: (Table *)v26, size: v21, (lua_State *)L);
        res->value.b = (int)v26;
        res->tt = 5;
        L->cl.c.upvalue[0].value.b = (int)gc;
        if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
          luaC_step(L);
        level = L->h.array;
        v2 = L;
        continue;
      case 0xBu:
        v29 = v4 >> 23;
        v30 = level[v29].value.gc;
        v31 = &level[v29];
        v7[1].value.b = (int)v30;
        *(&v7[1].value.b + 1) = *(&v31->value.b + 1);
        v7[1].tt = v31->tt;
        v32 = v4 >> 14;
        v2->cl.c.upvalue[0].value.b = (int)gc;
        if ( (v32 & 0x100) != 0 )
          v33 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v32);
        else
          v33 = &level[v32 & 0x1FF];
        luaV_gettable(L: (lua_State *)v2, t: (Node *)v31, key: v33, val: v7);
        level = v2->h.array;
        continue;
      case 0xCu:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v34 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v34 = &level[v4 >> 23];
        v35 = v4 >> 14;
        if ( (v35 & 0x100) != 0 )
          v36 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v35);
        else
          v36 = &level[v35 & 0x1FF];
        if ( v34->tt == 3 && v36->tt == 3 )
        {
          v7->value.n = v36->value.n + v34->value.n;
          v7->tt = 3;
          continue;
        }
        v129 = TM_ADD;
        goto LABEL_100;
      case 0xDu:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v34 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v34 = &level[v4 >> 23];
        v37 = v4 >> 14;
        if ( (v37 & 0x100) != 0 )
          v36 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v37);
        else
          v36 = &level[v37 & 0x1FF];
        if ( v34->tt == 3 && v36->tt == 3 )
        {
          v7->value.n = v34->value.n - v36->value.n;
          v7->tt = 3;
          continue;
        }
        v129 = TM_SUB;
        goto LABEL_100;
      case 0xEu:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v34 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v34 = &level[v4 >> 23];
        v38 = v4 >> 14;
        if ( (v38 & 0x100) != 0 )
          v36 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v38);
        else
          v36 = &level[v38 & 0x1FF];
        if ( v34->tt == 3 && v36->tt == 3 )
        {
          v7->value.n = v36->value.n * v34->value.n;
          v7->tt = 3;
          continue;
        }
        v129 = TM_MUL;
        goto LABEL_100;
      case 0xFu:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v34 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v34 = &level[v4 >> 23];
        v39 = v4 >> 14;
        if ( (v39 & 0x100) != 0 )
          v36 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v39);
        else
          v36 = &level[v39 & 0x1FF];
        if ( v34->tt == 3 && v36->tt == 3 )
        {
          v7->value.n = v34->value.n / v36->value.n;
          v7->tt = 3;
          continue;
        }
        v129 = TM_DIV;
        goto LABEL_100;
      case 0x10u:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v34 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v34 = &level[v4 >> 23];
        v40 = v4 >> 14;
        if ( (v40 & 0x100) != 0 )
          v36 = (lua_TValue *)(v141 + 16 * (unsigned __int8)v40);
        else
          v36 = &level[v40 & 0x1FF];
        if ( v34->tt == 3 && v36->tt == 3 )
        {
          v41.m128d_f64[0] = 4.503599627370496e15;
          v42 = (__m128d)*(unsigned __int64 *)&v34->value.n;
          v42.m128d_f64[0] = v42.m128d_f64[0] / v36->value.n;
          v43 = _mm_and_pd((__m128d)0x8000000000000000uLL, v42);
          v44 = _mm_cmplt_sd(_mm_xor_pd(v42, v43), v41).m128d_f64[0];
          v45 = v42.m128d_f64[0]
              + COERCE_DOUBLE(*(_QWORD *)&v44 & 0x4330000000000000LL | *(_QWORD *)&v43.m128d_f64[0])
              - COERCE_DOUBLE(*(_QWORD *)&v44 & 0x4330000000000000LL | *(_QWORD *)&v43.m128d_f64[0]);
          v7->value.n = v34->value.n
                      - (v45
                       - COERCE_DOUBLE(
                           *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v45 - v42.m128d_f64[0]), v43).m128d_f64[0]
                         & 0x3FF0000000000000LL))
                      * v36->value.n;
          v7->tt = 3;
        }
        else
        {
          v129 = TM_MOD;
LABEL_100:
          v2->cl.c.upvalue[0].value.b = (int)gc;
          Arith(L: (lua_State *)v2, ra: &level[size], rb: v34, rc: v36, op: v129);
          level = v2->h.array;
        }
        continue;
      case 0x11u:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v46 = (long double *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v46 = (long double *)&level[v4 >> 23];
        v47 = v4 >> 14;
        sizea = (const lua_TValue *)v46;
        if ( (v47 & 0x100) != 0 )
          v48 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)v47);
        else
          v48 = &level[v47 & 0x1FF];
        if ( *((_DWORD *)v46 + 2) == 3 && v48->tt == 3 )
        {
          v49 = *v46;
          __libm_sse2_pow(x: v130, y: v131);
          v7->value.n = v49;
          v7->tt = 3;
          continue;
        }
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v50 = *((_DWORD *)v46 + 2);
        if ( v50 != 3 )
        {
          if ( v50 != 4 || !luaO_str2d(s: (char *)(*(_DWORD *)v46 + 24), &result) )
            goto LABEL_119;
          v2 = L;
          v163 = result;
          v164 = 3;
          v46 = &v163;
        }
        levela = (lua_TValue *)v46;
        tt = v48->tt;
        if ( tt == 3 )
          goto LABEL_118;
        if ( tt == 4 && luaO_str2d(s: (char *)(v48->value.b + 24), result: &v155) )
        {
          v2 = L;
          t.i_key.nk.value.n = v155;
          t.i_key.nk.tt = 3;
LABEL_118:
          n = levela->value.n;
          __libm_sse2_pow(x: v130, y: v131);
          v7->value.n = n;
          v7->tt = 3;
        }
        else
        {
LABEL_119:
          v2 = L;
          if ( call_binTM((lua_State *)L, p1: sizea, p2: v48, res: v7, event: TM_POW) == 0 )
          {
            v53 = sizea->tt;
            if ( v53 != 3 && (v53 != 4 || !luaO_str2d(s: (char *)(sizea->value.b + 24), result: &v154)) )
              v48 = sizea;
            luaG_typeerror((lua_State *)L, o: v48, op: "perform arithmetic on");
          }
        }
        goto LABEL_3;
      case 0x12u:
        v54 = &level[v4 >> 23];
        if ( v54->tt == 3 )
        {
          v7->value.n = -v54->value.n;
          v7->tt = 3;
          continue;
        }
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v55 = v54->tt;
        if ( v55 == 3 )
        {
          sizeb = (TKey *)v54;
        }
        else
        {
          if ( v55 != 4 || !luaO_str2d(s: (char *)(v54->value.b + 24), result: &v159) )
            goto LABEL_136;
          v162.i_key.nk.value.n = v159;
          v162.i_key.nk.tt = 3;
          sizeb = &v162.i_key;
        }
        v56 = v54->tt;
        if ( v56 == 3 || v56 == 4 && luaO_str2d(s: (char *)(v54->value.b + 24), result: &v154) )
        {
          v2 = L;
          v7->value.n = -sizeb->nk.value.n;
          v7->tt = 3;
          level = L->h.array;
          continue;
        }
LABEL_136:
        v2 = L;
        if ( call_binTM((lua_State *)L, p1: v54, p2: v54, res: v7, event: TM_UNM) == 0 )
        {
          if ( v54->tt == 4 )
          {
            luaO_str2d(s: (char *)(v54->value.b + 24), result: &v154);
            v2 = L;
          }
          luaG_typeerror(L: (lua_State *)v2, o: v54, op: "perform arithmetic on");
        }
        level = L->h.array;
        continue;
      case 0x13u:
        v57 = v4 >> 23;
        v58 = level[v57].tt;
        if ( v58 != 0 && (v58 != 1 || level[v57].value.b != 0) )
        {
          v7->value.b = 0;
          v7->tt = 1;
        }
        else
        {
          v7->value.b = 1;
          v7->tt = 1;
        }
        continue;
      case 0x14u:
        v59 = v4 >> 23;
        v60 = level[v59].tt;
        v61 = (Table **)&level[v59];
        v62 = v60 - 4;
        if ( v62 != 0 )
        {
          if ( v62 == 1 )
          {
            v7->value.n = (double)luaH_getn(t: *v61);
            v7->tt = 3;
          }
          else
          {
            v2->cl.c.upvalue[0].value.b = (int)gc;
            if ( call_binTM(
                   L: (lua_State *)v2,
                   p1: (const lua_TValue *)v61,
                   p2: &luaO_nilobject_,
                   res: &level[size],
                   event: TM_LEN) == 0 )
              luaG_typeerror(L: (lua_State *)v2, o: (const lua_TValue *)v61, op: "get length of");
LABEL_272:
            level = v2->h.array;
          }
        }
        else
        {
          v7->value.n = (double)(unsigned int)(*v61)->node;
          v7->tt = 3;
        }
        continue;
      case 0x15u:
        v2->cl.c.upvalue[0].value.b = (int)gc;
        luaV_concat(L: (lua_State *)v2, total: ((v4 >> 14) & 0x1FF) - (v4 >> 23) + 1, last: (v4 >> 14) & 0x1FF);
        if ( *(_DWORD *)(v2->ts.tsv.len + 68) >= *(_DWORD *)(v2->ts.tsv.len + 64) )
          luaC_step(L: v2);
        array = v2->h.array;
        array[v149].value.b = array[v4 >> 23].value.b;
        *(&array[v149].value.b + 1) = *(&array[v4 >> 23].value.b + 1);
        level = array;
        array[v149].tt = array[v4 >> 23].tt;
        continue;
      case 0x16u:
        gc = &gc[(v4 >> 14) - 0x1FFFF];
        continue;
      case 0x17u:
        if ( ((v4 >> 23) & 0x100) != 0 )
          v64 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 23));
        else
          v64 = &level[v4 >> 23];
        v65 = v4 >> 14;
        if ( (v65 & 0x100) != 0 )
          v66 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)v65);
        else
          v66 = &level[v65 & 0x1FF];
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v67 = v64->tt == v66->tt && luaV_equalval(L: (lua_State *)v2, t1: v64, t2: v66) != 0;
        if ( v67 == size )
          gc = &gc[(*gc >> 14) - 0x1FFFF];
        ++gc;
        level = v2->h.array;
        continue;
      case 0x18u:
        v2->cl.c.upvalue[0].value.b = (int)gc;
        if ( ((v4 >> 14) & 0x100) != 0 )
          v68 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 14));
        else
          v68 = &level[(v4 >> 14) & 0x1FF];
        v69 = v4 >> 23;
        if ( (v69 & 0x100) != 0 )
          v70 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)v69);
        else
          v70 = &level[v69];
        if ( luaV_lessthan(L: (lua_State *)v2, l: v70, r: v68) != size )
          goto LABEL_185;
        gc = &gc[(*gc >> 14) - 131070];
        level = v2->h.array;
        continue;
      case 0x19u:
        v2->cl.c.upvalue[0].value.b = (int)gc;
        if ( ((v4 >> 14) & 0x100) != 0 )
          v71 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)(v4 >> 14));
        else
          v71 = &level[(v4 >> 14) & 0x1FF];
        v72 = v4 >> 23;
        if ( (v72 & 0x100) != 0 )
          v73 = (const lua_TValue *)(v141 + 16 * (unsigned __int8)v72);
        else
          v73 = &level[v72];
        if ( lessequal(L: (lua_State *)v2, l: v73, r: v71) == size )
          gc = &gc[(*gc >> 14) - 0x1FFFF];
LABEL_185:
        ++gc;
        level = v2->h.array;
        continue;
      case 0x1Au:
        v74 = v7->tt;
        v75 = v74 == 0 || v74 == 1 && v7->value.b == 0;
        if ( v75 != ((v4 >> 14) & 0x1FF) )
          goto LABEL_200;
        goto LABEL_201;
      case 0x1Bu:
        v76 = (int *)&level[v4 >> 23];
        v77 = v76[2];
        v78 = v77 == 0 || v77 == 1 && *v76 == 0;
        if ( v78 != ((v4 >> 14) & 0x1FF) )
        {
          v7->value.b = *v76;
          *(&v7->value.b + 1) = v76[1];
          v7->tt = v76[2];
LABEL_200:
          gc = &gc[(*gc >> 14) - 0x1FFFF];
        }
LABEL_201:
        ++gc;
        continue;
      case 0x1Cu:
        v79 = v4 >> 23;
        v80 = ((v4 >> 14) & 0x1FF) - 1;
        if ( v79 != 0 )
          v2->ts.tsv.hash = (unsigned int)&v7[v79];
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v81 = luaD_precall(L: (lua_State *)v2, func: v7, nresults: v80);
        if ( v81 == 0 )
        {
          ++nexeccalls;
          goto reentry;
        }
        if ( v81 != 1 )
          return;
        if ( v80 >= 0 )
          v2->ts.tsv.hash = (unsigned int)v2->cl.l.upvals[0]->v;
        level = v2->h.array;
        continue;
      case 0x1Du:
        v82 = v4 >> 23;
        if ( v82 != 0 )
          v2->ts.tsv.hash = (unsigned int)&v7[v82];
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v83 = luaD_precall(L: (lua_State *)v2, func: v7, nresults: -1);
        if ( v83 == 0 )
        {
          lineinfo = v2->p.lineinfo;
          v120 = (_DWORD *)lineinfo[1];
          v121 = *(lineinfo - 5);
          v148 = v120;
          if ( v2->th.openupval != nullptr )
          {
            v2 = L;
            luaF_close((lua_State *)L, level: (lua_TValue *)*(lineinfo - 6));
            v120 = v148;
          }
          v122 = ((*lineinfo - (_DWORD)v120) & 0xFFFFFFF0) + *(lineinfo - 5);
          *(lineinfo - 6) = v122;
          v123 = 0;
          v2->ts.tsv.keyhash = v122;
          v152 = 0;
          if ( (unsigned int)v120 < v2->ts.tsv.hash )
          {
            v124 = 0;
            do
            {
              *(_DWORD *)(v121 + v124 * 4) = *v120;
              *(_DWORD *)(v121 + v124 * 4 + 4) = v120[1];
              *(_DWORD *)(v121 + v124 * 4 + 8) = v120[2];
              v123 = v152 + 1;
              v124 = 4 * (v152 + 1);
              v120 = &v148[v124];
              ++v152;
            }
            while ( (unsigned int)&v148[v124] < v2->ts.tsv.hash );
          }
          v125 = v121 + 16 * v123;
          v2->ts.tsv.hash = v125;
          *(lineinfo - 4) = v125;
          v126 = v2->cl.c.upvalue[0].value.gc;
          ++*(lineinfo - 1);
          *(lineinfo - 3) = (int)v126;
          v2->cl.l.upvals[0] = (UpVal *)((char *)v2->cl.l.upvals[0] - 24);
          goto reentry;
        }
        if ( v83 != 1 )
          return;
        level = v2->h.array;
        break;
      case 0x1Eu:
        v127 = v4 >> 23;
        if ( v127 != 0 )
          v2->ts.tsv.hash = (unsigned int)&v7[v127 - 1];
        if ( v2->th.openupval != nullptr )
        {
          v2 = L;
          luaF_close((lua_State *)L, level);
          v7 = &level[size];
        }
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v128 = luaD_poscall(firstResult: v7, L: (lua_State *)v2);
        if ( --nexeccalls == 0 )
          return;
        if ( v128 != 0 )
          v2->ts.tsv.hash = (unsigned int)v2->cl.l.upvals[0]->v;
        goto reentry;
      case 0x1Fu:
        v84 = v7[1].value.n;
        v85 = v7[2].value.n + v7->value.n;
        if ( v7[2].value.n <= 0.0 )
          v86 = v85 < v84;
        else
          v86 = v84 < v85;
        if ( !v86 )
        {
          v7->value.n = v85;
          v7->tt = 3;
          gc = &gc[(v4 >> 14) - 0x1FFFF];
          v7[3].value.n = v85;
          v7[3].tt = 3;
        }
        continue;
      case 0x20u:
        v2->cl.c.upvalue[0].value.b = (int)gc;
        v87 = v7->tt;
        sizec = (int)&v7[2];
        if ( v87 != 3 )
        {
          if ( v87 != 4 )
            goto LABEL_229;
          if ( !luaO_str2d(s: (char *)(v7->value.b + 24), result: &v156) )
          {
            v2 = L;
LABEL_229:
            luaG_runerror(L: (lua_State *)v2, fmt: "'for' initial value must be a number");
          }
          v7->value.n = v156;
          v7->tt = 3;
        }
        v88 = v7[1].tt;
        if ( v88 != 3 )
        {
          if ( v88 != 4
            || !luaO_str2d(s: (char *)(v7[1].value.b + 24), result: &v158)
            || (v7[1].value.n = v158, v7[1].tt = 3, v7 == (lua_TValue *)-16) )
          {
            luaG_runerror((lua_State *)L, fmt: "'for' limit must be a number");
          }
        }
        v89 = v7[2].tt;
        if ( v89 != 3 )
        {
          if ( v89 != 4
            || !luaO_str2d(s: (char *)(*(_DWORD *)sizec + 24), result: &v160)
            || (*(long double *)sizec = v160, v7[2].tt = 3, v7 == (lua_TValue *)-32) )
          {
            luaG_runerror((lua_State *)L, fmt: "'for' step must be a number");
          }
        }
        v2 = L;
        v7->value.n = v7->value.n - *(double *)sizec;
        v7->tt = 3;
        gc = &gc[(v4 >> 14) - 0x1FFFF];
        continue;
      case 0x21u:
        v7[5].value.b = v7[2].value.b;
        *(&v7[5].value.b + 1) = *(&v7[2].value.b + 1);
        v7[5].tt = v7[2].tt;
        v7[4].value.b = v7[1].value.b;
        *(&v7[4].value.b + 1) = *(&v7[1].value.b + 1);
        v7[4].tt = v7[1].tt;
        v7[3].value.b = v7->value.b;
        *(&v7[3].value.b + 1) = *(&v7->value.b + 1);
        v7[3].tt = v7->tt;
        v2->ts.tsv.hash = (unsigned int)&v7[6];
        v2->cl.c.upvalue[0].value.b = (int)gc;
        luaD_call(L: (lua_State *)v2, func: v7 + 3, nResults: (v4 >> 14) & 0x1FF);
        v90 = v2->h.array;
        v2->ts.tsv.hash = (unsigned int)v2->cl.l.upvals[0]->v;
        v91 = (int *)&v90[size + 3];
        level = v90;
        if ( v91[2] != 0 )
        {
          *(v91 - 4) = *v91;
          *(v91 - 3) = v91[1];
          *(v91 - 2) = v91[2];
          gc = &gc[(*gc >> 14) - 0x1FFFF];
        }
        ++gc;
        continue;
      case 0x22u:
        v92 = v4 >> 23;
        v93 = (v4 >> 14) & 0x1FF;
        resa = (lua_TValue *)v92;
        v94 = v93;
        if ( v92 == 0 )
        {
          v92 = ((signed int)(v2->ts.tsv.hash - (int)v7) >> 4) - 1;
          resa = (lua_TValue *)v92;
          v2->ts.tsv.hash = (unsigned int)v2->cl.l.upvals[0]->v;
        }
        if ( v93 == 0 )
          v94 = *gc++;
        if ( v7->tt == 5 )
        {
          v95 = (GCObject *)v7->value.b;
          sized = 50 * v94 + v92 - 50;
          if ( sized > *(_DWORD *)(v7->value.b + 28) )
          {
            if ( v95->h.node == &dummynode_ )
              v96 = 0;
            else
              v96 = 1 << v95->cl.c.nupvalues;
            resize(t: (Table *)v95, L: (lua_State *)v2, nasize: sized, nhsize: v96);
            v92 = (int)resa;
          }
          if ( v92 > 0 )
          {
            v145 = (int *)&v7[v92];
            do
            {
              v97 = luaH_getnum(t: (Table *)v95, key: sized);
              if ( v97 == (Node *)&luaO_nilobject_ )
              {
                key.value.n = (double)sized;
                key.tt = 3;
                v97 = newkey(L: (lua_State *)v2, t: v95, &key);
              }
              --sized;
              v97->i_val.value.b = *v145;
              *(&v97->i_val.value.b + 1) = v145[1];
              v97->i_val.tt = v145[2];
              if ( v145[2] >= 4 && (*(_BYTE *)(*v145 + 5) & 3) != 0 )
              {
                marked = v95->gch.marked;
                if ( (marked & 4) != 0 )
                {
                  len = v2->ts.tsv.len;
                  v95->gch.marked = marked & 0xFB;
                  v95->cl.c.upvalue[0].value.b = *(_DWORD *)(len + 40);
                  *(_DWORD *)(len + 40) = v95;
                }
              }
              resa = (lua_TValue *)((char *)resa - 1);
              v145 -= 4;
            }
            while ( (int)resa > 0 );
          }
        }
        continue;
      case 0x23u:
        v2 = L;
        luaF_close((lua_State *)L, level: v7);
        continue;
      case 0x24u:
        v100 = *(_DWORD *)(v153 + 12);
        v101 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v153 + 16) + 16) + 4 * (v4 >> 14));
        resb = (lua_TValue *)*(unsigned __int8 *)(v101 + 72);
        LODWORD(v154) = v101;
        v150 = v100;
        v102 = (char *)luaM_realloc_(L: (lua_State *)v2, block: nullptr, osize: 0, nsize: 4 * (_DWORD)resb + 20);
        v103 = v2->ts.tsv.len;
        *(_DWORD *)v102 = *(_DWORD *)(v103 + 28);
        *(_DWORD *)(v103 + 28) = v102;
        v102[5] = *(_BYTE *)(v103 + 20) & 3;
        v102[4] = 6;
        v102[6] = 0;
        *((_DWORD *)v102 + 3) = v150;
        v102[7] = (char)resb;
        if ( resb != nullptr )
        {
          v104 = resb;
          v105 = &v102[4 * (_DWORD)resb + 20];
          do
          {
            v105 -= 4;
            v104 = (lua_TValue *)((char *)v104 - 1);
            *(_DWORD *)v105 = 0;
          }
          while ( v104 != nullptr );
        }
        *((_DWORD *)v102 + 4) = LODWORD(v154);
        if ( (int)resb > 0 )
        {
          sizee = (GCObject **)(v102 + 20);
          for ( i = resb; i != nullptr; i = (lua_TValue *)((char *)i - 1) )
          {
            v106 = *gc >> 23;
            if ( (*gc & 0x3F) == 4 )
              *sizee = *(GCObject **)(v153 + 4 * v106 + 20);
            else
              *sizee = luaF_findupval(L: (lua_State *)v2, level: &level[v106]);
            ++sizee;
            ++gc;
          }
        }
        v7->value.b = (int)v102;
        v7->tt = 6;
        v107 = v2->ts.tsv.len;
        v2->cl.c.upvalue[0].value.b = (int)gc;
        if ( *(_DWORD *)(v107 + 68) >= *(_DWORD *)(v107 + 64) )
          luaC_step(L: v2);
        goto LABEL_272;
      case 0x25u:
        v108 = (v4 >> 23) - 1;
        v109 = *v2->p.lineinfo - *(_DWORD *)&v2->cl.l.upvals[0]->tt;
        LODWORD(v154) = v2->cl.l.upvals[0];
        v110 = (v109 >> 4) - *(unsigned __int8 *)(*(_DWORD *)(v153 + 16) + 73) - 1;
        v147 = v108;
        if ( v108 == -1 )
        {
          v111 = v2->h.sizearray - v2->ts.tsv.hash;
          v112 = v110;
          v2->cl.c.upvalue[0].value.b = (int)gc;
          if ( v111 <= 16 * v110 )
          {
            sizecode = v2->p.sizecode;
            if ( v110 > sizecode )
              v114 = v110 + sizecode;
            else
              v114 = 2 * sizecode;
            luaD_reallocstack(L: (lua_State *)v2, newsize: v114);
            v112 = v110;
          }
          v7 = (lua_TValue *)(v2->ts.tsv.keyhash + v149 * 16);
          level = v2->h.array;
          v108 = v110;
          v147 = v110;
          v2->ts.tsv.hash = (unsigned int)&v7[v112];
        }
        v115 = 0;
        v151 = 0;
        if ( v108 > 0 )
        {
          v116 = -16 * v110;
          p_tt = &v7->tt;
          do
          {
            if ( v115 >= v110 )
            {
              *p_tt = 0;
            }
            else
            {
              v118 = *(_DWORD *)LODWORD(v154);
              *(p_tt - 2) = *(_DWORD *)(*(_DWORD *)LODWORD(v154) + v116);
              *(p_tt - 1) = *(_DWORD *)(v118 + v116 + 4);
              v115 = v151;
              *p_tt = *(_DWORD *)(v118 + v116 + 8);
              v108 = v147;
            }
            ++v115;
            v116 += 16;
            p_tt += 4;
            v151 = v115;
          }
          while ( v115 < v108 );
        }
        continue;
      default:
        continue;
    }
  }
  v2->cl.c.upvalue[0].value.b = (int)(gc - 1);
}
