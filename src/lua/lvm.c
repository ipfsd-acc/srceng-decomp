// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lvm.c
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004799A0
// Name: struct lua_TValue const __near * luaV_tonumber(struct lua_TValue const __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
const lua_TValue *__cdecl luaV_tonumber(const lua_TValue *obj, lua_TValue *n)
{
  const lua_TValue *result; // eax
  int tt; // ecx
  long double num; // [esp+0h] [ebp-8h] BYREF

  result = obj;
  tt = obj->tt;
  if ( tt != 3 )
  {
    if ( tt == 4 && luaO_str2d(s: (char *)(obj->value.b + 16), result: &num) )
    {
      n->value.n = num;
      n->tt = 3;
      return n;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004799F0
// Name: int luaV_tostring(struct lua_State __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaV_tostring(lua_State *L, lua_TValue *obj)
{
  char s[32]; // [esp+Ch] [ebp-20h] BYREF

  if ( obj->tt != 3 )
    return 0;
  sprintf(string: s, format: "%.14g", (double)obj->value.n);
  obj->value.b = (int)luaS_newlstr(L, str: s, l: strlen(s));
  obj->tt = 4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00479A60
// Name: callTMres
// Source: json
//------------------------------------------------------------------------------
void __fastcall callTMres(
        const lua_TValue *p2,
        const lua_TValue *p1,
        lua_State *L,
        lua_TValue *res,
        const lua_TValue *f)
{
  int b; // ebx
  lua_TValue *top; // eax
  int result; // [esp+1Ch] [ebp+10h]

  b = f->value.b;
  result = (char *)res - (char *)L->stack;
  top = L->top;
  top->value.b = b;
  *(&top->value.b + 1) = *(&f->value.b + 1);
  top->tt = f->tt;
  L->top[1] = *p1;
  L->top[2] = *p2;
  if ( (char *)L->stack_last - (char *)L->top <= 48 )
    luaD_growstack(L, n: 3);
  L->top += 3;
  luaD_call(L, func: L->top - 3, nResults: 1);
  *(lua_TValue *)((char *)L->stack + result) = *--L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00479B00
// Name: callTM
// Source: json
//------------------------------------------------------------------------------
void __usercall callTM(
        lua_State *L@<esi>,
        const lua_TValue *p2@<edx>,
        const lua_TValue *p3@<ecx>,
        const lua_TValue *f,
        const lua_TValue *p1)
{
  *L->top = *f;
  L->top[1] = *p1;
  L->top[2] = *p2;
  L->top[3] = *p3;
  if ( (char *)L->stack_last - (char *)L->top <= 64 )
    luaD_growstack(L, n: 4);
  L->top += 4;
  luaD_call(L, func: L->top - 4, nResults: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00479B90
// Name: void luaV_gettable(struct lua_State __near *,struct lua_TValue const __near *,struct lua_TValue __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_gettable(lua_State *L, const lua_TValue *t, lua_TValue *key, lua_TValue *val)
{
  int b; // edi
  const lua_TValue *v6; // eax
  Table *v7; // edi
  const lua_TValue *v8; // edi
  const lua_TValue *res; // [esp+Ch] [ebp-8h]
  const lua_TValue *resa; // [esp+Ch] [ebp-8h]
  int loop; // [esp+10h] [ebp-4h]

  loop = 0;
  while ( 1 )
  {
    if ( t->tt == 5 )
    {
      b = t->value.b;
      v6 = luaH_get(t: (Table *)t->value.gc, key);
      res = v6;
      if ( v6->tt != 0 )
        goto LABEL_8;
      v7 = *(Table **)(b + 8);
      if ( v7 == nullptr || (v7->flags & 1) != 0 )
        goto LABEL_8;
      v8 = luaT_gettm(events: v7, event: TM_INDEX, ename: L->l_G->tmname[0]);
      if ( v8 == nullptr )
      {
        v6 = res;
LABEL_8:
        *val = *v6;
        return;
      }
    }
    else
    {
      v8 = luaT_gettmbyobj(L, o: t, event: TM_INDEX);
      if ( v8->tt == 0 )
        luaG_typeerror(L, o: t, op: "index");
    }
    if ( v8->tt == 6 )
      break;
    t = v8;
    if ( ++loop >= 100 )
      luaG_runerror(L, fmt: "loop in gettable");
  }
  resa = (const lua_TValue *)((char *)val - (char *)L->stack);
  *L->top = *v8;
  L->top[1] = *t;
  L->top[2] = *key;
  if ( (char *)L->stack_last - (char *)L->top <= 48 )
    luaD_growstack(L, n: 3);
  L->top += 3;
  luaD_call(L, func: L->top - 3, nResults: 1);
  *(const lua_TValue *)((char *)resa + (unsigned int)L->stack) = *--L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00479CF0
// Name: void luaV_settable(struct lua_State __near *,struct lua_TValue const __near *,struct lua_TValue __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_settable(lua_State *L, const lua_TValue *t, lua_TValue *key, lua_TValue *val)
{
  GCObject *b; // edi
  lua_TValue *v6; // eax
  Table *metatable; // ecx
  const lua_TValue *v8; // edi
  lua_TValue *oldval; // [esp+Ch] [ebp-Ch]
  Table *h; // [esp+10h] [ebp-8h]
  int loop; // [esp+14h] [ebp-4h]

  loop = 0;
  while ( 1 )
  {
    if ( t->tt != 5 )
    {
      v8 = luaT_gettmbyobj(L, o: t, event: TM_NEWINDEX);
      if ( v8->tt == 0 )
        luaG_typeerror(L, o: t, op: "index");
      goto LABEL_14;
    }
    h = (Table *)t->value.b;
    b = (GCObject *)t->value.b;
    v6 = luaH_set(L, t: (Table *)t->value.gc, key);
    oldval = v6;
    if ( v6->tt != 0 )
      goto LABEL_8;
    metatable = b->u.uv.metatable;
    if ( metatable == nullptr || (metatable->flags & 2) != 0 )
      goto LABEL_8;
    v8 = luaT_gettm(events: metatable, event: TM_NEWINDEX, ename: L->l_G->tmname[1]);
    if ( v8 == nullptr )
      break;
LABEL_14:
    if ( v8->tt == 6 )
    {
      callTM(L, p2: key, p3: val, f: v8, p1: t);
      return;
    }
    t = v8;
    if ( ++loop >= 100 )
      luaG_runerror(L, fmt: "loop in settable");
  }
  b = (GCObject *)h;
  v6 = oldval;
LABEL_8:
  *v6 = *val;
  if ( val->tt >= 4 && (*(_BYTE *)(val->value.b + 5) & 3) != 0 && (b->gch.marked & 4) != 0 )
    luaC_barrierback(L, t: b);
}

//------------------------------------------------------------------------------
// Address: 0x00479E00
// Name: get_compTM
// Source: json
//------------------------------------------------------------------------------
const lua_TValue *__usercall get_compTM@<eax>(Table *mt1@<edi>, TMS event@<esi>, lua_State *L, Table *mt2)
{
  const lua_TValue *v4; // ebx
  const lua_TValue *v6; // eax

  if ( mt1 == nullptr )
    return nullptr;
  if ( ((unsigned __int8)(1 << event) & mt1->flags) != 0 )
    return nullptr;
  v4 = luaT_gettm(events: mt1, event, ename: L->l_G->tmname[event]);
  if ( v4 == nullptr )
    return nullptr;
  if ( mt1 == mt2 )
    return v4;
  if ( mt2 == nullptr )
    return nullptr;
  if ( ((unsigned __int8)(1 << event) & mt2->flags) != 0 )
    return nullptr;
  v6 = luaT_gettm(events: mt2, event, ename: L->l_G->tmname[event]);
  if ( v6 == nullptr )
    return nullptr;
  return luaO_rawequalObj(t1: v4, t2: v6) ? v4 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00479E90
// Name: call_orderTM
// Source: json
//------------------------------------------------------------------------------
int __usercall call_orderTM@<eax>(lua_State *L@<eax>, const lua_TValue *p1, const lua_TValue *p2, TMS event)
{
  const lua_TValue *v5; // edi
  const lua_TValue *v7; // eax
  lua_TValue *top; // esi
  int tt; // eax

  v5 = luaT_gettmbyobj(L, o: p1, event);
  if ( v5->tt == 0 )
    return -1;
  v7 = luaT_gettmbyobj(L, o: p2, event);
  if ( !luaO_rawequalObj(t1: v5, t2: v7) )
    return -1;
  callTMres(p2, p1, L, res: L->top, f: v5);
  top = L->top;
  tt = top->tt;
  return tt != 0 && (tt != 1 || top->value.b != 0);
}

//------------------------------------------------------------------------------
// Address: 0x00479F10
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
// Address: 0x00479F90
// Name: int luaV_lessthan(struct lua_State __near *,struct lua_TValue const __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaV_lessthan(lua_State *L, const lua_TValue *l, const lua_TValue *r)
{
  int tt; // eax
  int result; // eax

  tt = l->tt;
  if ( tt != r->tt )
    luaG_ordererror(L, p1: l, p2: r);
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
// Address: 0x0047A020
// Name: lessequal
// Source: json
//------------------------------------------------------------------------------
int __usercall lessequal@<eax>(const lua_TValue *l@<edi>, const lua_TValue *r@<esi>, lua_State *L)
{
  int tt; // eax
  int result; // eax
  int v5; // eax

  tt = l->tt;
  if ( tt != r->tt )
    goto LABEL_9;
  if ( tt == 3 )
    return r->value.n >= l->value.n;
  if ( tt == 4 )
    return l_strcmp(ls: (const TString *)l->value.gc, rs: (const TString *)r->value.gc) <= 0;
  result = call_orderTM(L, p1: l, p2: r, event: TM_LE);
  if ( result == -1 )
  {
    v5 = call_orderTM(L, p1: r, p2: l, event: TM_LT);
    if ( v5 != -1 )
      return v5 == 0;
LABEL_9:
    luaG_ordererror(L, p1: l, p2: r);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047A0B0
// Name: int luaV_equalval(struct lua_State __near *,struct lua_TValue const __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaV_equalval(lua_State *L, const lua_TValue *t1, const lua_TValue *t2)
{
  int result; // eax
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
    case 7:
      if ( t1->value.b == t2->value.b )
        return 1;
      compTM = get_compTM(mt1: *(Table **)(t1->value.b + 8), event: TM_EQ, L, mt2: *(Table **)(t2->value.b + 8));
      if ( compTM == nullptr )
        return 0;
      callTMres(p2: t2, p1: t1, L, res: L->top, f: compTM);
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
// Address: 0x0047A1A0
// Name: void luaV_concat(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_concat(lua_State *L, int total, int last)
{
  lua_State *v3; // ebx
  lua_TValue *v4; // esi
  GCObject *gc; // ecx
  lua_TValue *v6; // edi
  unsigned int v7; // ebx
  int v8; // eax
  unsigned int v9; // ebx
  int *v10; // eax
  lua_TValue *v11; // edi
  lua_TValue *v12; // esi
  const lua_TValue *v13; // eax
  int v14; // eax
  unsigned int v15; // edi
  int *v16; // esi
  char string[32]; // [esp+14h] [ebp-30h] BYREF
  char *buffer; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  unsigned int tl; // [esp+3Ch] [ebp-8h]
  int n; // [esp+40h] [ebp-4h]

  do
  {
    v3 = L;
    v4 = &L->base[last + 1];
    n = 2;
    if ( v4[-2].tt != 4 )
    {
      if ( v4[-2].tt != 3 )
        goto LABEL_18;
      sprintf(string, format: "%.14g", (double)v4[-2].value.n);
      v4[-2].value.b = (int)luaS_newlstr(L, str: string, l: strlen(string));
      v4[-2].tt = 4;
    }
    if ( v4[-1].tt != 4 )
    {
      if ( v4[-1].tt != 3 )
      {
LABEL_18:
        v11 = v4 - 1;
        v12 = v4 - 2;
        v13 = luaT_gettmbyobj(L, o: v12, event: TM_CONCAT);
        if ( v13->tt == 0 )
          v13 = luaT_gettmbyobj(L, o: v11, event: TM_CONCAT);
        if ( v13->tt != 6 )
          luaG_concaterror(L, p1: v12, p2: v11);
        callTMres(p2: v11, p1: v12, L, res: v12, f: v13);
        goto LABEL_27;
      }
      sprintf(string, format: "%.14g", (double)v4[-1].value.n);
      v4[-1].value.b = (int)luaS_newlstr(L, str: string, l: strlen(string));
      v4[-1].tt = 4;
    }
    gc = v4[-1].value.gc;
    if ( gc->ts.tsv.len != 0 )
    {
      tl = gc->ts.tsv.len;
      n = 1;
      if ( total > 1 )
      {
        v6 = v4 - 2;
        do
        {
          if ( v6->tt != 4 )
          {
            if ( v6->tt != 3 )
              break;
            sprintf(string, format: "%.14g", (double)v6->value.n);
            v6->value.b = (int)luaS_newlstr(L: v3, str: string, l: strlen(string));
            v6->tt = 4;
          }
          v7 = *(_DWORD *)(v6->value.b + 12);
          if ( v7 >= -3 - tl )
            luaG_runerror(L, fmt: "string length overflow");
          tl += v7;
          v3 = L;
          --v6;
          ++n;
        }
        while ( n < total );
      }
      buffer = luaZ_openspace(L: v3, buff: &v3->l_G->buff, n: tl);
      v8 = n;
      v9 = 0;
      i = n;
      if ( n > 0 )
      {
        v10 = (int *)&v4[-n];
        for ( tl = (unsigned int)v10; ; v10 = (int *)tl )
        {
          v14 = *v10;
          v15 = *(_DWORD *)(v14 + 12);
          memcpy(dst: (unsigned __int8 *)&buffer[v9], src: (unsigned __int8 *)(v14 + 16), count: v15);
          tl += 16;
          v9 += v15;
          if ( --i <= 0 )
            break;
        }
        v8 = n;
      }
      v16 = (int *)&v4[-v8];
      *v16 = (int)luaS_newlstr(L, str: buffer, l: v9);
      v16[2] = 4;
    }
LABEL_27:
    last += 1 - n;
    total += 1 - n;
  }
  while ( total > 1 );
}

//------------------------------------------------------------------------------
// Address: 0x0047A410
// Name: Arith
// Source: json
//------------------------------------------------------------------------------
void __usercall Arith(lua_TValue *ra@<edi>, const lua_TValue *rb@<esi>, lua_State *L, lua_TValue *rc, TMS op)
{
  int tt; // eax
  long double v6; // xmm0_8
  lua_TValue *p_tempc; // eax
  int v8; // ecx
  double n; // xmm1_8
  double v10; // xmm0_8
  __m128d v11; // xmm4
  __m128d v12; // xmm5
  double v13; // xmm3_8
  double v14; // xmm3_8
  const lua_TValue *v15; // eax
  lua_TValue tempb; // [esp+0h] [ebp-28h] BYREF
  lua_TValue tempc; // [esp+10h] [ebp-18h] BYREF
  long double result; // [esp+20h] [ebp-8h] BYREF

  tt = rb->tt;
  if ( tt == 3 )
  {
    HIDWORD(result) = rb;
  }
  else
  {
    if ( tt != 4 || !luaO_str2d(s: (char *)(rb->value.b + 16), &result) )
      goto LABEL_18;
    v6 = result;
    HIDWORD(result) = &tempb;
    tempb.value.n = v6;
    tempb.tt = 3;
  }
  p_tempc = rc;
  v8 = rc->tt;
  if ( v8 == 3 )
    goto LABEL_10;
  if ( v8 == 4 && luaO_str2d(s: (char *)(rc->value.b + 16), result: (long double *)&tempc.tt) )
  {
    tempc.value.n = *(long double *)&tempc.tt;
    tempc.tt = 3;
    p_tempc = &tempc;
LABEL_10:
    n = p_tempc->value.n;
    v10 = *(double *)HIDWORD(result);
    switch ( op )
    {
      case TM_ADD:
        ra->value.n = n + v10;
        ra->tt = 3;
        break;
      case TM_SUB:
        ra->value.n = v10 - n;
        ra->tt = 3;
        break;
      case TM_MUL:
        ra->value.n = n * v10;
        ra->tt = 3;
        break;
      case TM_DIV:
        ra->value.n = v10 / n;
        ra->tt = 3;
        break;
      case TM_MOD:
        v11.m128d_f64[0] = 4.503599627370496e15;
        v12 = _mm_and_pd((__m128d)0x8000000000000000uLL, (__m128d)COERCE_UNSIGNED_INT64(v10 / n));
        v13 = _mm_cmplt_sd(_mm_xor_pd((__m128d)COERCE_UNSIGNED_INT64(v10 / n), v12), v11).m128d_f64[0];
        v14 = v10 / n
            + COERCE_DOUBLE(*(_QWORD *)&v13 & 0x4330000000000000LL | *(_QWORD *)&v12.m128d_f64[0])
            - COERCE_DOUBLE(*(_QWORD *)&v13 & 0x4330000000000000LL | *(_QWORD *)&v12.m128d_f64[0]);
        ra->value.n = v10
                    - (v14
                     - COERCE_DOUBLE(
                         *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v14 - v10 / n), v12).m128d_f64[0]
                       & 0x3FF0000000000000LL))
                    * n;
        ra->tt = 3;
        break;
      case TM_POW:
        __libm_sse2_pow(x: tempb.value.n, y: *(long double *)&tempb.tt);
        ra->value.n = v10;
        ra->tt = 3;
        break;
      case TM_UNM:
        ra->value.n = -v10;
        ra->tt = 3;
        break;
      default:
        return;
    }
    return;
  }
LABEL_18:
  v15 = luaT_gettmbyobj(L, o: rb, event: op);
  if ( v15->tt == 0 )
    v15 = luaT_gettmbyobj(L, o: rc, event: op);
  if ( v15->tt != 6 )
    luaG_aritherror(L, p1: rb, p2: rc);
  callTMres(p2: rc, p1: rb, L, res: ra, f: v15);
}

//------------------------------------------------------------------------------
// Address: 0x0047A630
// Name: void luaV_execute(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaV_execute(GCObject *L, int nexeccalls)
{
  CallInfo *v2; // edx
  LClosure *gc; // ecx
  lua_TValue *array; // edx
  Proto *p; // eax
  unsigned int v6; // esi
  unsigned __int8 hookmask; // al
  bool v8; // zf
  int linedefined; // ecx
  unsigned int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  lua_TValue *v14; // edi
  lua_TValue *v15; // esi
  lua_TValue *v16; // esi
  lua_TValue *v; // eax
  lua_TValue *v18; // eax
  GCObject *v19; // esi
  _DWORD *hash; // eax
  GCObject *v21; // edi
  lua_TValue *v22; // eax
  unsigned int v23; // esi
  lua_TValue *v24; // esi
  int v25; // eax
  Table *v26; // eax
  const unsigned int *v27; // ecx
  global_State *l_G; // eax
  lua_TValue *v29; // eax
  unsigned int v30; // esi
  const unsigned int *v31; // edx
  lua_TValue *v32; // esi
  lua_TValue *v33; // eax
  unsigned int v34; // esi
  lua_TValue *v35; // esi
  unsigned int v36; // esi
  unsigned int v37; // esi
  unsigned int v38; // esi
  lua_TValue *v39; // eax
  unsigned int v40; // esi
  const lua_TValue *v41; // esi
  __m128d v42; // xmm2
  __m128d v43; // xmm0
  __m128d v44; // xmm4
  double v45; // xmm1_8
  double v46; // xmm1_8
  int tt; // ecx
  int v48; // eax
  __m128d v49; // xmm2
  __m128d v50; // xmm0
  __m128d v51; // xmm4
  double v52; // xmm1_8
  double v53; // xmm1_8
  const lua_TValue *v54; // eax
  lua_TValue *v55; // eax
  unsigned int v56; // esi
  lua_TValue *v57; // esi
  long double v58; // xmm0_8
  int v59; // ecx
  int v60; // eax
  long double v61; // xmm0_8
  const lua_TValue *v62; // eax
  const lua_TValue *v63; // esi
  int v64; // eax
  int v65; // eax
  const lua_TValue *v66; // eax
  lua_TValue *v67; // ecx
  int v68; // eax
  lua_TValue *v69; // esi
  const lua_TValue *v70; // eax
  lua_TValue *v71; // eax
  int v72; // ecx
  int v73; // edx
  lua_TValue *v74; // eax
  unsigned int v75; // esi
  lua_TValue *v76; // esi
  int v77; // eax
  lua_TValue *v78; // ecx
  const lua_TValue *v79; // eax
  unsigned int v80; // esi
  const lua_TValue *v81; // esi
  int v82; // eax
  lua_TValue *v83; // eax
  const lua_TValue *v84; // eax
  unsigned int v85; // esi
  const lua_TValue *v86; // esi
  int v87; // eax
  int v88; // eax
  int v89; // eax
  lua_TValue *v90; // eax
  int v91; // ecx
  int v92; // ecx
  unsigned int v93; // eax
  int v94; // esi
  int v95; // eax
  unsigned int v96; // esi
  int v97; // eax
  double v98; // xmm2_8
  double v99; // xmm0_8
  bool v100; // cf
  const unsigned int *v101; // edx
  int v102; // eax
  int v103; // eax
  int v104; // eax
  int v105; // eax
  const unsigned int *v106; // edx
  lua_TValue *v107; // ecx
  int *v108; // eax
  int v109; // eax
  int v110; // esi
  int v111; // esi
  Table *v112; // ecx
  int *v113; // esi
  int v114; // edi
  Table *env; // edx
  int v116; // esi
  Closure *v117; // eax
  GCObject *v118; // esi
  unsigned int v119; // eax
  UpVal *v120; // eax
  const unsigned int *v121; // ecx
  unsigned int len; // eax
  GCObject *v123; // eax
  int v124; // edx
  int v125; // esi
  int v126; // esi
  int v127; // edx
  int v128; // eax
  int v129; // ecx
  int *p_tt; // edi
  lua_TValue *v131; // eax
  CallInfo *v132; // edi
  int func; // ecx
  CallInfo *v134; // edi
  unsigned int v135; // ecx
  lua_TValue *v136; // eax
  int v137; // edx
  int v138; // eax
  int v139; // edx
  lua_TValue *v140; // edx
  const unsigned int *savedpc; // ecx
  unsigned int v142; // esi
  int v143; // eax
  lua_TValue *v144; // [esp-8h] [ebp-ECh]
  lua_TValue *v145; // [esp-8h] [ebp-ECh]
  lua_TValue *v146; // [esp-4h] [ebp-E8h]
  lua_TValue *v147; // [esp-4h] [ebp-E8h]
  int v148; // [esp-4h] [ebp-E8h]
  TMS v149; // [esp-4h] [ebp-E8h]
  long double v150; // [esp+0h] [ebp-E4h]
  long double v151[2]; // [esp+8h] [ebp-DCh] BYREF
  int v152; // [esp+18h] [ebp-CCh]
  long double v153; // [esp+20h] [ebp-C4h] BYREF
  int v154; // [esp+28h] [ebp-BCh]
  long double v155; // [esp+30h] [ebp-B4h] BYREF
  int v156; // [esp+38h] [ebp-ACh]
  lua_TValue t; // [esp+40h] [ebp-A4h] BYREF
  long double v158; // [esp+50h] [ebp-94h] BYREF
  int v159; // [esp+58h] [ebp-8Ch]
  long double v160; // [esp+60h] [ebp-84h] BYREF
  int v161; // [esp+68h] [ebp-7Ch]
  lua_TValue g; // [esp+70h] [ebp-74h] BYREF
  long double result; // [esp+80h] [ebp-64h] BYREF
  long double v164; // [esp+88h] [ebp-5Ch] BYREF
  long double v165; // [esp+90h] [ebp-54h] BYREF
  long double v166; // [esp+98h] [ebp-4Ch] BYREF
  long double v167; // [esp+A0h] [ebp-44h] BYREF
  long double v168; // [esp+A8h] [ebp-3Ch] BYREF
  long double v169; // [esp+B0h] [ebp-34h] BYREF
  long double v170; // [esp+B8h] [ebp-2Ch] BYREF
  CallInfo *ci; // [esp+C0h] [ebp-24h]
  unsigned __int8 v172; // [esp+C7h] [ebp-1Dh]
  LClosure *v173; // [esp+C8h] [ebp-1Ch]
  int b; // [esp+CCh] [ebp-18h]
  int j; // [esp+D0h] [ebp-14h]
  lua_TValue *k; // [esp+D4h] [ebp-10h]
  int n; // [esp+D8h] [ebp-Ch]
  lua_TValue *base; // [esp+DCh] [ebp-8h]
  const unsigned int *pc; // [esp+E0h] [ebp-4h]

reentry:
  v2 = L->th.ci;
  pc = L->th.savedpc;
  gc = (LClosure *)v2->func->value.gc;
  array = L->h.array;
  p = gc->p;
  v173 = gc;
  k = p->k;
LABEL_2:
  base = array;
  while ( 1 )
  {
    v6 = *pc++;
    hookmask = L->th.hookmask;
    v172 = hookmask;
    if ( (hookmask & 0xC) == 0 )
      goto LABEL_22;
    v8 = L->p.linedefined-- == 1;
    linedefined = L->p.linedefined;
    if ( !v8 && (hookmask & 4) == 0 )
      goto LABEL_22;
    j = L->cl.c.upvalue[0].value.b;
    L->cl.c.upvalue[0].value.b = (int)pc;
    if ( hookmask > 4u && linedefined == 0 )
    {
      L->p.linedefined = L->p.sizelocvars;
      luaD_callhook((lua_State *)L, event: 3, line: -1);
      hookmask = v172;
    }
    if ( (hookmask & 4) != 0 )
    {
      v10 = *(_DWORD *)(**(_DWORD **)&L->cl.l.upvals[0]->tt + 16);
      v11 = *(_DWORD *)(v10 + 12);
      v12 = *(_DWORD *)(v10 + 20);
      b = v11;
      n = v12 != 0 ? *(_DWORD *)(v12 + 4 * ((((int)pc - v11) >> 2) - 1)) : 0;
      if ( ((int)pc - v11) >> 2 == 1
        || (unsigned int)pc <= j
        || (v12 == 0 ? (v13 = 0) : (v13 = *(_DWORD *)(v12 + 4 * ((j - b) >> 2) - 4)), n != v13) )
      {
        luaD_callhook((lua_State *)L, event: 2, line: n);
      }
    }
    if ( L->ts.tsv.reserved == 1 )
      break;
    base = L->h.array;
LABEL_22:
    n = (unsigned __int8)(v6 >> 6);
    j = 16 * n;
    v14 = &base[n];
    switch ( v6 & 0x3F )
    {
      case 0u:
        v15 = &base[v6 >> 23];
        goto LABEL_24;
      case 1u:
        v15 = &k[v6 >> 14];
LABEL_24:
        v14->value.b = v15->value.b;
        *(&v14->value.b + 1) = *(&v15->value.b + 1);
        v14->tt = v15->tt;
        continue;
      case 2u:
        v14->value.b = v6 >> 23;
        v14->tt = 1;
        if ( (v6 & 0x7FC000) != 0 )
          ++pc;
        continue;
      case 3u:
        v16 = &base[v6 >> 23];
        do
        {
          v16->tt = 0;
          --v16;
        }
        while ( v16 >= v14 );
        continue;
      case 4u:
        v = v173->upvals[v6 >> 23]->v;
        v14->value.b = v->value.b;
        *(&v14->value.b + 1) = *(&v->value.b + 1);
        v14->tt = v->tt;
        continue;
      case 5u:
        v146 = &base[n];
        g.value.b = (int)v173->env;
        v144 = &k[v6 >> 14];
        g.tt = 5;
        L->cl.c.upvalue[0].value.b = (int)pc;
        luaV_gettable((lua_State *)L, t: &g, key: v144, val: v146);
        base = L->h.array;
        continue;
      case 6u:
        L->cl.c.upvalue[0].value.b = (int)pc;
        if ( ((v6 >> 14) & 0x100) != 0 )
          v18 = &k[(unsigned __int8)(v6 >> 14)];
        else
          v18 = &base[(v6 >> 14) & 0x1FF];
        luaV_gettable((lua_State *)L, t: &base[v6 >> 23], key: v18, val: v14);
        base = L->h.array;
        continue;
      case 7u:
        v147 = &base[n];
        t.value.b = (int)v173->env;
        v145 = &k[v6 >> 14];
        t.tt = 5;
        L->cl.c.upvalue[0].value.b = (int)pc;
        luaV_settable((lua_State *)L, &t, key: v145, val: v147);
        base = L->h.array;
        continue;
      case 8u:
        v19 = (GCObject *)v173->upvals[v6 >> 23];
        hash = (_DWORD *)v19->ts.tsv.hash;
        *hash = v14->value.b;
        hash[1] = *(&v14->value.b + 1);
        hash[2] = v14->tt;
        if ( v14->tt >= 4 )
        {
          v21 = (GCObject *)v14->value.b;
          if ( (v21->gch.marked & 3) != 0 && (v19->gch.marked & 4) != 0 )
            luaC_barrierf((lua_State *)L, o: v19, v: v21);
        }
        continue;
      case 9u:
        L->cl.c.upvalue[0].value.b = (int)pc;
        if ( ((v6 >> 14) & 0x100) != 0 )
          v22 = &k[(unsigned __int8)(v6 >> 14)];
        else
          v22 = &base[(v6 >> 14) & 0x1FF];
        v23 = v6 >> 23;
        if ( (v23 & 0x100) != 0 )
          v24 = &k[(unsigned __int8)v23];
        else
          v24 = &base[v23];
        luaV_settable((lua_State *)L, t: v14, key: v24, val: v22);
        array = L->h.array;
        goto LABEL_2;
      case 0xAu:
        v148 = luaO_fb2int(x: (v6 >> 14) & 0x1FF);
        v25 = luaO_fb2int(x: v6 >> 23);
        v26 = luaH_new((lua_State *)L, narray: v25, nhash: v148);
        v27 = pc;
        v14->value.b = (int)v26;
        v14->tt = 5;
        l_G = L->th.l_G;
        L->cl.c.upvalue[0].value.b = (int)v27;
        if ( l_G->totalbytes >= l_G->GCthreshold )
          luaC_step(L);
        array = L->h.array;
        goto LABEL_2;
      case 0xBu:
        v29 = &base[v6 >> 23];
        v30 = v6 >> 14;
        v14[1].value.b = v29->value.b;
        *(&v14[1].value.b + 1) = *(&v29->value.b + 1);
        v31 = pc;
        v14[1].tt = v29->tt;
        L->cl.c.upvalue[0].value.b = (int)v31;
        if ( (v30 & 0x100) != 0 )
          v32 = &k[(unsigned __int8)v30];
        else
          v32 = &base[v30 & 0x1FF];
        luaV_gettable((lua_State *)L, t: v29, key: v32, val: v14);
        array = L->h.array;
        goto LABEL_2;
      case 0xCu:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v33 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v33 = &base[v6 >> 23];
        v34 = v6 >> 14;
        if ( (v34 & 0x100) != 0 )
          v35 = &k[(unsigned __int8)v34];
        else
          v35 = &base[v34 & 0x1FF];
        if ( v33->tt == 3 && v35->tt == 3 )
        {
          v14->value.n = v35->value.n + v33->value.n;
          v14->tt = 3;
          continue;
        }
        v149 = TM_ADD;
        goto LABEL_96;
      case 0xDu:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v33 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v33 = &base[v6 >> 23];
        v36 = v6 >> 14;
        if ( (v36 & 0x100) != 0 )
          v35 = &k[(unsigned __int8)v36];
        else
          v35 = &base[v36 & 0x1FF];
        if ( v33->tt == 3 && v35->tt == 3 )
        {
          v14->value.n = v33->value.n - v35->value.n;
          v14->tt = 3;
          continue;
        }
        v149 = TM_SUB;
        goto LABEL_96;
      case 0xEu:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v33 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v33 = &base[v6 >> 23];
        v37 = v6 >> 14;
        if ( (v37 & 0x100) != 0 )
          v35 = &k[(unsigned __int8)v37];
        else
          v35 = &base[v37 & 0x1FF];
        if ( v33->tt == 3 && v35->tt == 3 )
        {
          v14->value.n = v35->value.n * v33->value.n;
          v14->tt = 3;
          continue;
        }
        v149 = TM_MUL;
        goto LABEL_96;
      case 0xFu:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v33 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v33 = &base[v6 >> 23];
        v38 = v6 >> 14;
        if ( (v38 & 0x100) != 0 )
          v35 = &k[(unsigned __int8)v38];
        else
          v35 = &base[v38 & 0x1FF];
        if ( v33->tt == 3 && v35->tt == 3 )
        {
          v14->value.n = v33->value.n / v35->value.n;
          v14->tt = 3;
        }
        else
        {
          v149 = TM_DIV;
LABEL_96:
          L->cl.c.upvalue[0].value.b = (int)pc;
          Arith(ra: v14, rb: v33, (lua_State *)L, rc: v35, op: v149);
          base = L->h.array;
        }
        continue;
      case 0x10u:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v39 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v39 = &base[v6 >> 23];
        v40 = v6 >> 14;
        n = (int)v39;
        if ( (v40 & 0x100) != 0 )
          v41 = &k[(unsigned __int8)v40];
        else
          v41 = &base[v40 & 0x1FF];
        if ( v39->tt == 3 && v41->tt == 3 )
        {
          v42.m128d_f64[0] = 4.503599627370496e15;
          v43 = (__m128d)*(unsigned __int64 *)&v39->value.n;
          v43.m128d_f64[0] = v43.m128d_f64[0] / v41->value.n;
          v44 = _mm_and_pd((__m128d)0x8000000000000000uLL, v43);
          v45 = _mm_cmplt_sd(_mm_xor_pd(v43, v44), v42).m128d_f64[0];
          v46 = v43.m128d_f64[0]
              + COERCE_DOUBLE(*(_QWORD *)&v45 & 0x4330000000000000LL | *(_QWORD *)&v44.m128d_f64[0])
              - COERCE_DOUBLE(*(_QWORD *)&v45 & 0x4330000000000000LL | *(_QWORD *)&v44.m128d_f64[0]);
          v14->value.n = v39->value.n
                       - (v46
                        - COERCE_DOUBLE(
                            *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v46 - v43.m128d_f64[0]), v44).m128d_f64[0]
                          & 0x3FF0000000000000LL))
                       * v41->value.n;
          v14->tt = 3;
          continue;
        }
        L->cl.c.upvalue[0].value.b = (int)pc;
        tt = v39->tt;
        if ( tt == 3 )
        {
          base = v39;
        }
        else
        {
          if ( tt != 4 || !luaO_str2d(s: (char *)(*(_DWORD *)n + 16), &result) )
            goto LABEL_116;
          v160 = result;
          v161 = 3;
          base = (lua_TValue *)&v160;
        }
        v48 = v41->tt;
        if ( v48 == 3 )
          goto LABEL_115;
        if ( v48 == 4 && luaO_str2d(s: (char *)(v41->value.b + 16), result: &v168) )
        {
          v158 = v168;
          v159 = 3;
          v41 = (const lua_TValue *)&v158;
LABEL_115:
          v49.m128d_f64[0] = 4.503599627370496e15;
          v50 = (__m128d)*(unsigned __int64 *)&base->value.n;
          v50.m128d_f64[0] = v50.m128d_f64[0] / v41->value.n;
          v51 = _mm_and_pd((__m128d)0x8000000000000000uLL, v50);
          v52 = _mm_cmplt_sd(_mm_xor_pd(v50, v51), v49).m128d_f64[0];
          v53 = v50.m128d_f64[0]
              + COERCE_DOUBLE(*(_QWORD *)&v52 & 0x4330000000000000LL | *(_QWORD *)&v51.m128d_f64[0])
              - COERCE_DOUBLE(*(_QWORD *)&v52 & 0x4330000000000000LL | *(_QWORD *)&v51.m128d_f64[0]);
          v14->value.n = base->value.n
                       - (v53
                        - COERCE_DOUBLE(
                            *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v53 - v50.m128d_f64[0]), v51).m128d_f64[0]
                          & 0x3FF0000000000000LL))
                       * v41->value.n;
          v14->tt = 3;
          base = L->h.array;
          continue;
        }
LABEL_116:
        v54 = luaT_gettmbyobj((lua_State *)L, o: (const lua_TValue *)n, event: TM_MOD);
        if ( v54->tt == 0 )
          v54 = luaT_gettmbyobj((lua_State *)L, o: v41, event: TM_MOD);
        if ( v54->tt != 6 )
          luaG_aritherror((lua_State *)L, p1: (const lua_TValue *)n, p2: v41);
        callTMres(p2: v41, p1: (const lua_TValue *)n, (lua_State *)L, res: v14, f: v54);
        base = L->h.array;
        continue;
      case 0x11u:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v55 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v55 = &base[v6 >> 23];
        v56 = v6 >> 14;
        n = (int)v55;
        if ( (v56 & 0x100) != 0 )
          v57 = &k[(unsigned __int8)v56];
        else
          v57 = &base[v56 & 0x1FF];
        if ( v55->tt == 3 && v57->tt == 3 )
        {
          v58 = *(double *)n;
          __libm_sse2_pow(x: v150, y: v151[0]);
          v14->value.n = v58;
          v14->tt = 3;
          continue;
        }
        L->cl.c.upvalue[0].value.b = (int)pc;
        v59 = v55->tt;
        if ( v59 != 3 )
        {
          if ( v59 != 4 || !luaO_str2d(s: (char *)(*(_DWORD *)n + 16), result: &v167) )
            goto LABEL_139;
          v155 = v167;
          v156 = 3;
          v55 = (lua_TValue *)&v155;
        }
        base = v55;
        v60 = v57->tt;
        if ( v60 == 3 )
          goto LABEL_138;
        if ( v60 == 4 && luaO_str2d(s: (char *)(v57->value.b + 16), result: &v170) )
        {
          v151[1] = v170;
          v152 = 3;
LABEL_138:
          v61 = base->value.n;
          __libm_sse2_pow(x: v150, y: v151[0]);
          v14->value.n = v61;
          v14->tt = 3;
          array = L->h.array;
        }
        else
        {
LABEL_139:
          v62 = luaT_gettmbyobj((lua_State *)L, o: (const lua_TValue *)n, event: TM_POW);
          if ( v62->tt == 0 )
            v62 = luaT_gettmbyobj((lua_State *)L, o: v57, event: TM_POW);
          if ( v62->tt != 6 )
            luaG_aritherror((lua_State *)L, p1: (const lua_TValue *)n, p2: v57);
          callTMres(p2: v57, p1: (const lua_TValue *)n, (lua_State *)L, res: v14, f: v62);
          array = L->h.array;
        }
        goto LABEL_2;
      case 0x12u:
        v63 = &base[v6 >> 23];
        if ( v63->tt == 3 )
        {
          v14->value.n = -v63->value.n;
          v14->tt = 3;
          continue;
        }
        L->cl.c.upvalue[0].value.b = (int)pc;
        v64 = v63->tt;
        if ( v64 == 3 )
        {
          n = (int)v63;
        }
        else
        {
          if ( v64 != 4 || !luaO_str2d(s: (char *)(v63->value.b + 16), result: &v164) )
            goto LABEL_155;
          v153 = v164;
          v154 = 3;
          n = (int)&v153;
        }
        v65 = v63->tt;
        if ( v65 == 3 || v65 == 4 && luaO_str2d(s: (char *)(v63->value.b + 16), result: v151) )
        {
          v14->value.n = -*(double *)n;
          v14->tt = 3;
          array = L->h.array;
          goto LABEL_2;
        }
LABEL_155:
        v66 = luaT_gettmbyobj((lua_State *)L, o: v63, event: TM_UNM);
        if ( v66->tt == 0 )
          v66 = luaT_gettmbyobj((lua_State *)L, o: v63, event: TM_UNM);
        if ( v66->tt != 6 )
          luaG_aritherror((lua_State *)L, p1: v63, p2: v63);
        callTMres(p2: v63, p1: v63, (lua_State *)L, res: v14, f: v66);
        array = L->h.array;
        goto LABEL_2;
      case 0x13u:
        v67 = &base[v6 >> 23];
        v68 = v67->tt;
        if ( v68 != 0 && (v68 != 1 || v67->value.b != 0) )
        {
          v14->value.b = 0;
          v14->tt = 1;
        }
        else
        {
          v14->value.b = 1;
          v14->tt = 1;
        }
        continue;
      case 0x14u:
        v69 = &base[v6 >> 23];
        if ( v69->tt == 4 )
        {
          v14->value.n = (double)*(unsigned int *)(v69->value.b + 12);
          v14->tt = 3;
        }
        else if ( v69->tt == 5 )
        {
          v14->value.n = (double)luaH_getn(t: (Table *)v69->value.gc);
          v14->tt = 3;
        }
        else
        {
          L->cl.c.upvalue[0].value.b = (int)pc;
          v70 = luaT_gettmbyobj((lua_State *)L, o: v69, event: TM_LEN);
          if ( v70->tt == 0 )
            v70 = luaT_gettmbyobj((lua_State *)L, o: &luaO_nilobject_, event: TM_LEN);
          if ( v70->tt != 6 )
            luaG_typeerror((lua_State *)L, o: v69, op: "get length of");
          callTMres(p2: &luaO_nilobject_, p1: v69, (lua_State *)L, res: v14, f: v70);
          base = L->h.array;
        }
        continue;
      case 0x15u:
        L->cl.c.upvalue[0].value.b = (int)pc;
        luaV_concat((lua_State *)L, total: ((v6 >> 14) & 0x1FF) - (v6 >> 23) + 1, last: (v6 >> 14) & 0x1FF);
        if ( *(_DWORD *)(L->u.uv.len + 68) >= *(_DWORD *)(L->u.uv.len + 64) )
          luaC_step(L);
        v71 = L->h.array;
        v72 = j;
        *(Value *)((char *)&v71->value + j) = v71[v6 >> 23].value;
        v73 = v71[v6 >> 23].tt;
        base = v71;
        *(int *)((char *)&v71->tt + v72) = v73;
        continue;
      case 0x16u:
        pc = &pc[(v6 >> 14) - 0x1FFFF];
        continue;
      case 0x17u:
        if ( ((v6 >> 23) & 0x100) != 0 )
          v74 = &k[(unsigned __int8)(v6 >> 23)];
        else
          v74 = &base[v6 >> 23];
        v75 = v6 >> 14;
        if ( (v75 & 0x100) != 0 )
          v76 = &k[(unsigned __int8)v75];
        else
          v76 = &base[v75 & 0x1FF];
        L->cl.c.upvalue[0].value.b = (int)pc;
        v77 = v74->tt == v76->tt && luaV_equalval((lua_State *)L, t1: v74, t2: v76) != 0;
        if ( v77 == n )
          pc = &pc[(*pc >> 14) - 0x1FFFF];
        v78 = L->h.array;
        ++pc;
        base = v78;
        continue;
      case 0x18u:
        L->cl.c.upvalue[0].value.b = (int)pc;
        if ( ((v6 >> 14) & 0x100) != 0 )
          v79 = &k[(unsigned __int8)(v6 >> 14)];
        else
          v79 = &base[(v6 >> 14) & 0x1FF];
        v80 = v6 >> 23;
        if ( (v80 & 0x100) != 0 )
          v81 = &k[(unsigned __int8)v80];
        else
          v81 = &base[v80];
        v82 = luaV_lessthan((lua_State *)L, l: v81, r: v79);
        if ( v82 == n )
          pc = &pc[(*pc >> 14) - 0x1FFFF];
        v83 = L->h.array;
        ++pc;
        base = v83;
        continue;
      case 0x19u:
        L->cl.c.upvalue[0].value.b = (int)pc;
        if ( ((v6 >> 14) & 0x100) != 0 )
          v84 = &k[(unsigned __int8)(v6 >> 14)];
        else
          v84 = &base[(v6 >> 14) & 0x1FF];
        v85 = v6 >> 23;
        if ( (v85 & 0x100) != 0 )
          v86 = &k[(unsigned __int8)v85];
        else
          v86 = &base[v85];
        v87 = lessequal(l: v86, r: v84, (lua_State *)L);
        if ( v87 == n )
          pc = &pc[(*pc >> 14) - 0x1FFFF];
        array = L->h.array;
        ++pc;
        goto LABEL_2;
      case 0x1Au:
        v88 = v14->tt;
        v89 = v88 == 0 || v88 == 1 && v14->value.b == 0;
        if ( v89 != ((v6 >> 14) & 0x1FF) )
          goto LABEL_223;
        goto LABEL_224;
      case 0x1Bu:
        v90 = &base[v6 >> 23];
        v91 = v90->tt;
        v92 = v91 == 0 || v91 == 1 && v90->value.b == 0;
        if ( v92 != ((v6 >> 14) & 0x1FF) )
        {
          v14->value.b = v90->value.b;
          *(&v14->value.b + 1) = *(&v90->value.b + 1);
          v14->tt = v90->tt;
LABEL_223:
          pc = &pc[(*pc >> 14) - 0x1FFFF];
        }
LABEL_224:
        ++pc;
        continue;
      case 0x1Cu:
        v93 = v6 >> 23;
        v94 = ((v6 >> 14) & 0x1FF) - 1;
        if ( v93 != 0 )
          L->ts.tsv.hash = (unsigned int)&v14[v93];
        L->cl.c.upvalue[0].value.b = (int)pc;
        v95 = luaD_precall((lua_State *)L, func: v14, nresults: v94);
        if ( v95 == 0 )
        {
          ++nexeccalls;
          goto reentry;
        }
        if ( v95 != 1 )
          return;
        if ( v94 >= 0 )
          L->ts.tsv.hash = (unsigned int)L->cl.l.upvals[0]->v;
        base = L->h.array;
        continue;
      case 0x1Du:
        v96 = v6 >> 23;
        if ( v96 != 0 )
          L->ts.tsv.hash = (unsigned int)&v14[v96];
        L->cl.c.upvalue[0].value.b = (int)pc;
        v97 = luaD_precall((lua_State *)L, func: v14, nresults: -1);
        if ( v97 == 0 )
        {
          v132 = L->th.ci;
          func = (int)v132[-1].func;
          v134 = v132 - 1;
          v8 = L->th.openupval == nullptr;
          n = func;
          v135 = (unsigned int)v134[1].func;
          ci = v134;
          b = v135;
          if ( !v8 )
          {
            luaF_close((lua_State *)L, level: v134->base);
            v135 = b;
          }
          v136 = (lua_TValue *)((char *)v134->func + (((int)v134[1].base - v135) & 0xFFFFFFF0));
          v137 = 0;
          v134->base = v136;
          L->ts.tsv.len = (unsigned int)v136;
          j = 0;
          if ( v135 < L->ts.tsv.hash )
          {
            v138 = 0;
            do
            {
              v139 = n;
              *(_DWORD *)(n + v138) = *(_DWORD *)v135;
              *(_DWORD *)(v139 + v138 + 4) = *(_DWORD *)(v135 + 4);
              *(_DWORD *)(v139 + v138 + 8) = *(_DWORD *)(v135 + 8);
              v137 = j + 1;
              v138 = 16 * (j + 1);
              v135 = v138 + b;
              ++j;
            }
            while ( v138 + b < L->ts.tsv.hash );
            v134 = ci;
          }
          v140 = (lua_TValue *)(n + 16 * v137);
          L->ts.tsv.hash = (unsigned int)v140;
          v134->top = v140;
          savedpc = L->th.savedpc;
          ++v134->tailcalls;
          v134->savedpc = savedpc;
          L->cl.l.upvals[0] = (UpVal *)((char *)L->cl.l.upvals[0] - 24);
          goto reentry;
        }
        if ( v97 != 1 )
          return;
        base = L->h.array;
        continue;
      case 0x1Eu:
        v142 = v6 >> 23;
        if ( v142 != 0 )
          L->ts.tsv.hash = (unsigned int)&v14[v142 - 1];
        if ( L->th.openupval != nullptr )
          luaF_close((lua_State *)L, level: base);
        L->cl.c.upvalue[0].value.b = (int)pc;
        v143 = luaD_poscall((lua_State *)L, firstResult: v14);
        if ( --nexeccalls == 0 )
          return;
        if ( v143 != 0 )
          L->ts.tsv.hash = (unsigned int)L->cl.l.upvals[0]->v;
        goto reentry;
      case 0x1Fu:
        v98 = v14[1].value.n;
        v99 = v14[2].value.n + v14->value.n;
        if ( v14[2].value.n <= 0.0 )
          v100 = v99 < v98;
        else
          v100 = v98 < v99;
        if ( !v100 )
        {
          v101 = &pc[(v6 >> 14) - 0x1FFFF];
          v14->value.n = v99;
          v14->tt = 3;
          pc = v101;
          v14[3].value.n = v99;
          v14[3].tt = 3;
        }
        continue;
      case 0x20u:
        n = (int)&v14[2];
        L->cl.c.upvalue[0].value.b = (int)pc;
        v102 = v14->tt;
        if ( v102 != 3 )
        {
          if ( v102 != 4 || !luaO_str2d(s: (char *)(v14->value.b + 16), result: &v166) )
            luaG_runerror((lua_State *)L, fmt: "'for' initial value must be a number");
          v14->value.n = v166;
          v14->tt = 3;
        }
        v103 = v14[1].tt;
        if ( v103 != 3 )
        {
          if ( v103 != 4
            || !luaO_str2d(s: (char *)(v14[1].value.b + 16), result: &v165)
            || (v14[1].value.n = v165, v14[1].tt = 3, v14 == (lua_TValue *)-16) )
          {
            luaG_runerror((lua_State *)L, fmt: "'for' limit must be a number");
          }
        }
        v104 = *(_DWORD *)(n + 8);
        if ( v104 != 3 )
        {
          if ( v104 != 4 || !luaO_str2d(s: (char *)(*(_DWORD *)n + 16), result: &v169) )
          {
            n = 0;
LABEL_256:
            luaG_runerror((lua_State *)L, fmt: "'for' step must be a number");
          }
          v105 = n;
          *(long double *)n = v169;
          *(_DWORD *)(v105 + 8) = 3;
          n = v105;
          if ( v105 == 0 )
            goto LABEL_256;
        }
        v106 = &pc[(v6 >> 14) - 0x1FFFF];
        v14->value.n = v14->value.n - *(double *)n;
        v14->tt = 3;
        pc = v106;
        break;
      case 0x21u:
        v14[5].value.b = v14[2].value.b;
        *(&v14[5].value.b + 1) = *(&v14[2].value.b + 1);
        v14[5].tt = v14[2].tt;
        v14[4].value.b = v14[1].value.b;
        *(&v14[4].value.b + 1) = *(&v14[1].value.b + 1);
        v14[4].tt = v14[1].tt;
        v14[3].value.b = v14->value.b;
        *(&v14[3].value.b + 1) = *(&v14->value.b + 1);
        v14[3].tt = v14->tt;
        L->ts.tsv.hash = (unsigned int)&v14[6];
        L->cl.c.upvalue[0].value.b = (int)pc;
        luaD_call((lua_State *)L, func: v14 + 3, nResults: (v6 >> 14) & 0x1FF);
        v107 = L->h.array;
        L->ts.tsv.hash = (unsigned int)L->cl.l.upvals[0]->v;
        v108 = (int *)&v107[n + 3];
        v8 = v108[2] == 0;
        base = v107;
        if ( !v8 )
        {
          *(v108 - 4) = *v108;
          *(v108 - 3) = v108[1];
          *(v108 - 2) = v108[2];
          pc = &pc[(*pc >> 14) - 0x1FFFF];
        }
        ++pc;
        continue;
      case 0x22u:
        v109 = v6 >> 23;
        v110 = (v6 >> 14) & 0x1FF;
        n = v109;
        if ( v109 == 0 )
        {
          n = ((signed int)(L->ts.tsv.hash - (int)v14) >> 4) - 1;
          L->ts.tsv.hash = (unsigned int)L->cl.l.upvals[0]->v;
        }
        if ( v110 == 0 )
          v110 = *pc++;
        if ( v14->tt == 5 )
        {
          v111 = 50 * v110;
          v112 = (Table *)v14->value.b;
          j = (int)v112;
          b = v111 + n - 50;
          if ( b > v112->sizearray )
            luaH_resizearray((lua_State *)L, t: v112, nasize: v111 + n - 50);
          if ( n > 0 )
          {
            v113 = (int *)&v14[n];
            do
            {
              v114 = b;
              *luaH_setnum((lua_State *)L, t: (Table *)j, key: b) = *(lua_TValue *)v113;
              b = v114 - 1;
              if ( v113[2] >= 4 && (*(_BYTE *)(*v113 + 5) & 3) != 0 && (*(_BYTE *)(j + 5) & 4) != 0 )
                luaC_barrierback((lua_State *)L, t: (GCObject *)j);
              v113 -= 4;
              --n;
            }
            while ( n > 0 );
          }
        }
        continue;
      case 0x23u:
        luaF_close((lua_State *)L, level: &base[n]);
        continue;
      case 0x24u:
        env = v173->env;
        j = (int)v173->p->p[v6 >> 14];
        v116 = *(unsigned __int8 *)(j + 72);
        v117 = luaF_newLclosure((lua_State *)L, nelems: v116, e: env);
        b = (int)v117;
        v117->c.f = (int (__cdecl *)(lua_State *))j;
        if ( v116 <= 0 )
        {
          v118 = L;
        }
        else
        {
          j = v116;
          v118 = L;
          n = (int)v117->l.upvals;
          do
          {
            v119 = *pc >> 23;
            if ( (*pc & 0x3F) == 4 )
            {
              *(_DWORD *)n = v173->upvals[v119];
            }
            else
            {
              v120 = luaF_findupval((lua_State *)L, level: &base[v119]);
              *(_DWORD *)n = v120;
            }
            n += 4;
            ++pc;
            --j;
          }
          while ( j != 0 );
        }
        v121 = pc;
        v14->value.b = b;
        v14->tt = 6;
        len = v118->u.uv.len;
        v118->cl.c.upvalue[0].value.b = (int)v121;
        if ( *(_DWORD *)(len + 68) >= *(_DWORD *)(len + 64) )
          luaC_step(L: v118);
        base = v118->h.array;
        continue;
      case 0x25u:
        v123 = L;
        v124 = (v6 >> 23) - 1;
        v125 = *L->p.lineinfo - *(_DWORD *)&L->cl.l.upvals[0]->tt;
        ci = L->th.ci;
        v126 = (v125 >> 4) - v173->p->numparams - 1;
        b = v124;
        if ( v124 == -1 )
        {
          L->cl.c.upvalue[0].value.b = (int)pc;
          v127 = L->h.sizearray - L->ts.tsv.hash;
          n = 16 * v126;
          if ( v127 <= 16 * v126 )
          {
            luaD_growstack((lua_State *)L, n: v126);
            v123 = L;
          }
          base = v123->h.array;
          v14 = (lua_TValue *)((char *)base + j);
          v124 = v126;
          b = v126;
          v123->ts.tsv.hash = (unsigned int)base + j + n;
        }
        v128 = 0;
        j = 0;
        if ( v124 > 0 )
        {
          v129 = -1 * v126;
          p_tt = &v14->tt;
          do
          {
            if ( v128 >= v126 )
            {
              *p_tt = 0;
            }
            else
            {
              v131 = ci->base;
              *(p_tt - 2) = ci->base[v129].value.b;
              *(p_tt - 1) = *(&v131[v129].value.b + 1);
              v124 = b;
              *p_tt = v131[v129].tt;
              v128 = j;
            }
            ++v128;
            ++v129;
            p_tt += 4;
            j = v128;
          }
          while ( v128 < v124 );
        }
        continue;
      default:
        continue;
    }
  }
  L->cl.c.upvalue[0].value.b = (int)(pc - 1);
}
