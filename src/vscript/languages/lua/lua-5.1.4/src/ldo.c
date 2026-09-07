// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ldo.c
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009AA0
// Name: _luaD_seterrorobj
// Source: json
//------------------------------------------------------------------------------
void __usercall luaD_seterrorobj(lua_State *L@<edi>, int errcode@<eax>, lua_TValue *oldtop@<ecx>)
{
  TString *v4; // eax

  switch ( errcode )
  {
    case 2:
    case 3:
      *oldtop = L->top[-1];
      goto LABEL_6;
    case 4:
      v4 = luaS_newlstr(L, str: "not enough memory", l: 0x11u);
      goto LABEL_3;
    case 5:
      v4 = luaS_newlstr(L, str: "error in error handling", l: 0x17u);
LABEL_3:
      oldtop->value.b = (int)v4;
      oldtop->tt = 4;
      L->top = oldtop + 1;
      break;
    default:
LABEL_6:
      L->top = oldtop + 1;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009B10
// Name: resetstack
// Source: json
//------------------------------------------------------------------------------
void __usercall resetstack(lua_State *L@<eax>, int status)
{
  CallInfo *base_ci; // eax
  lua_TValue *v4; // esi
  TString *v5; // eax
  lua_TValue *top; // eax
  unsigned __int16 baseCcalls; // cx
  bool v8; // cc
  lua_TValue *base; // [esp-4h] [ebp-10h]

  base_ci = L->base_ci;
  L->ci = base_ci;
  base = base_ci->base;
  L->base = base_ci->base;
  luaF_close(L, level: base);
  v4 = L->base;
  switch ( status )
  {
    case 2:
    case 3:
      top = L->top;
      v4->value.b = top[-1].value.b;
      *(&v4->value.b + 1) = *(&top[-1].value.b + 1);
      v4->tt = top[-1].tt;
      break;
    case 4:
      v5 = luaS_newlstr(L, str: "not enough memory", l: 0x11u);
      goto LABEL_3;
    case 5:
      v5 = luaS_newlstr(L, str: "error in error handling", l: 0x17u);
LABEL_3:
      v4->value.b = (int)v5;
      v4->tt = 4;
      break;
    default:
      break;
  }
  baseCcalls = L->baseCcalls;
  v8 = L->size_ci <= 20000;
  L->top = v4 + 1;
  L->nCcalls = baseCcalls;
  L->allowhook = 1;
  if ( !v8 && L->ci - L->base_ci + 1 < 20000 )
    luaD_reallocCI(L, newsize: 20000);
  L->errfunc = 0;
  L->errorJmp = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009BE0
// Name: _luaD_throw
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaD_throw(lua_State *L, int errcode)
{
  lua_longjmp *errorJmp; // eax
  global_State *l_G; // ecx

  errorJmp = L->errorJmp;
  if ( errorJmp != nullptr )
  {
    errorJmp->status = errcode;
    longjmp(Buf: L->errorJmp->b, Value: 1);
  }
  l_G = L->l_G;
  L->status = errcode;
  if ( l_G->panic != nullptr )
  {
    resetstack(L, status: errcode);
    L->l_G->panic(a1: L);
  }
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10009C40
// Name: _luaD_rawrunprotected
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaD_rawrunprotected(lua_State *L, void (__cdecl *f)(lua_State *, void *), void *ud)
{
  lua_longjmp *errorJmp; // ecx
  int result; // eax
  lua_longjmp lj; // [esp+8h] [ebp-4Ch] BYREF

  errorJmp = L->errorJmp;
  L->errorJmp = &lj;
  lj.status = 0;
  lj.previous = errorJmp;
  if ( _setjmp3(a1: lj.b, a2: 0) != 0 )
  {
    L->errorJmp = lj.previous;
    return lj.status;
  }
  else
  {
    f(a1: L, a2: ud);
    result = lj.status;
    L->errorJmp = lj.previous;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009CA0
// Name: correctstack
// Source: json
//------------------------------------------------------------------------------
void __fastcall correctstack(lua_State *L, lua_TValue *oldstack)
{
  GCObject *i; // eax
  CallInfo *j; // eax
  lua_TValue *v4; // esi

  L->top = (lua_TValue *)((char *)L->stack + (((char *)L->top - (char *)oldstack) & 0xFFFFFFF0));
  for ( i = L->openupval; i != nullptr; i = (GCObject *)i->ts.dummy.l )
    i->ts.tsv.hash = (unsigned int)L->stack + ((i->ts.tsv.hash - (_DWORD)oldstack) & 0xFFFFFFF0);
  for ( j = L->base_ci;
        j <= L->ci;
        j[-1].func = (lua_TValue *)((char *)L->stack + (((char *)j[-1].func - (char *)oldstack) & 0xFFFFFFF0)) )
  {
    v4 = (lua_TValue *)((char *)L->stack + (((char *)j->top - (char *)oldstack) & 0xFFFFFFF0));
    ++j;
    j[-1].top = v4;
    j[-1].base = (lua_TValue *)((char *)L->stack + (((char *)j[-1].base - (char *)oldstack) & 0xFFFFFFF0));
  }
  L->base = (lua_TValue *)((char *)L->stack + (((char *)L->base - (char *)oldstack) & 0xFFFFFFF0));
}

//------------------------------------------------------------------------------
// Address: 0x10009D20
// Name: _luaD_reallocstack
// Source: json
//------------------------------------------------------------------------------
void __usercall luaD_reallocstack(lua_State *L@<esi>, int newsize@<eax>)
{
  int v3; // ebx
  lua_TValue *v4; // eax
  lua_TValue *oldstack; // [esp+Ch] [ebp-4h]

  v3 = newsize + 6;
  oldstack = L->stack;
  if ( (unsigned int)(newsize + 7) > 0xFFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v4 = (lua_TValue *)luaM_realloc_(L, block: L->stack, osize: 16 * L->stacksize, nsize: 16 * v3);
  L->stack = v4;
  L->stacksize = v3;
  L->stack_last = &v4[newsize];
  correctstack(L, oldstack);
}

//------------------------------------------------------------------------------
// Address: 0x10009D90
// Name: _luaD_reallocCI
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_reallocCI(lua_State *L, int newsize)
{
  int v2; // edi
  int v3; // ebx
  CallInfo *v4; // eax
  CallInfo *v5; // ecx
  global_State *l_G; // [esp+10h] [ebp-8h]
  CallInfo *base_ci; // [esp+14h] [ebp-4h]

  base_ci = L->base_ci;
  if ( (unsigned int)(newsize + 1) > 0xAAAAAAA )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v2 = 24 * newsize;
  v3 = 24 * L->size_ci;
  l_G = L->l_G;
  v4 = (CallInfo *)l_G->frealloc(a1: l_G->ud, a2: L->base_ci, a3: v3, a4: 24 * newsize);
  if ( v4 == nullptr && v2 != 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += v2 - v3;
  v5 = &v4[L->ci - base_ci];
  L->size_ci = newsize;
  L->base_ci = v4;
  L->ci = v5;
  L->end_ci = &v4[newsize - 1];
}

//------------------------------------------------------------------------------
// Address: 0x10009E50
// Name: growCI
// Source: json
//------------------------------------------------------------------------------
CallInfo *__usercall growCI@<eax>(lua_State *L@<esi>)
{
  int size_ci; // eax
  CallInfo *result; // eax

  size_ci = L->size_ci;
  if ( size_ci > 20000 )
    luaD_throw(L, errcode: 5);
  luaD_reallocCI(L, newsize: 2 * size_ci);
  if ( L->size_ci > 20000 )
    luaG_runerror(L, fmt: "stack overflow");
  result = L->ci + 1;
  L->ci = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009EA0
// Name: _luaD_callhook
// Source: json
//------------------------------------------------------------------------------
void __usercall luaD_callhook(lua_State *L@<eax>, int event@<edx>, int line)
{
  lua_TValue *stack; // ecx
  CallInfo *ci; // eax
  char *v6; // edi
  int v7; // ebx
  int stacksize; // eax
  int v9; // eax
  CallInfo *v10; // eax
  lua_TValue *v11; // edx
  lua_Debug ar; // [esp+4h] [ebp-68h] BYREF
  void (__cdecl *hook)(lua_State *, lua_Debug *); // [esp+68h] [ebp-4h]

  hook = L->hook;
  if ( hook != nullptr && L->allowhook != 0 )
  {
    stack = L->stack;
    ci = L->ci;
    v6 = (char *)((char *)L->top - (char *)stack);
    v7 = (char *)ci->top - (char *)stack;
    ar.event = event;
    ar.currentline = line;
    if ( event == 4 )
      ar.i_ci = 0;
    else
      ar.i_ci = ci - L->base_ci;
    if ( (char *)L->stack_last - (char *)L->top <= 320 )
    {
      stacksize = L->stacksize;
      if ( stacksize < 20 )
        v9 = stacksize + 20;
      else
        v9 = 2 * stacksize;
      luaD_reallocstack(L, newsize: v9);
    }
    L->ci->top = L->top + 20;
    L->allowhook = 0;
    hook(a1: L, a2: &ar);
    v10 = L->ci;
    v11 = (lua_TValue *)((char *)L->stack + v7);
    L->allowhook = 1;
    v10->top = v11;
    L->top = (lua_TValue *)&v6[(unsigned int)L->stack];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009F70
// Name: adjust_varargs
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall adjust_varargs@<eax>(lua_State *L@<esi>, Proto *p@<ecx>, int actual)
{
  int numparams; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  GCObject *v7; // edi
  global_State *l_G; // eax
  void *v9; // eax
  int sizearray; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int *v15; // ebx
  unsigned int len; // edx
  lua_TValue *v17; // eax
  double v18; // xmm0_8
  bool v19; // zf
  lua_TValue *v20; // eax
  long double v21; // xmm0_8
  lua_TValue *result; // eax
  int *p_tt; // ecx
  int i; // ebx
  lua_TValue *top; // edx
  lua_TValue *v26; // ecx
  int v27; // [esp+8h] [ebp-38h]
  int v28; // [esp+Ch] [ebp-34h]
  int v29; // [esp+10h] [ebp-30h]
  int v30; // [esp+14h] [ebp-2Ch]
  Table *htab; // [esp+18h] [ebp-28h]
  int nvar; // [esp+20h] [ebp-20h]
  TString *nvara; // [esp+20h] [ebp-20h]
  int nfixargs; // [esp+24h] [ebp-1Ch]
  double v35; // [esp+28h] [ebp-18h]
  lua_TValue key; // [esp+30h] [ebp-10h] BYREF

  numparams = p->numparams;
  v4 = actual;
  nfixargs = numparams;
  htab = nullptr;
  if ( actual < numparams )
  {
    v5 = numparams - actual;
    v4 = p->numparams;
    actual = v4;
    do
    {
      L->top->tt = 0;
      ++L->top;
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( (p->is_vararg & 4) != 0 )
  {
    v6 = v4 - numparams;
    nvar = v6;
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    v7 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x20u);
    l_G = L->l_G;
    v7->ts.dummy.l = (int)l_G->rootgc;
    l_G->rootgc = v7;
    v7->gch.marked = l_G->currentwhite & 3;
    v7->gch.tt = 5;
    v7->ts.tsv.hash = 0;
    v7->ts.tsv.keyhash = 0;
    v7->h.sizearray = 0;
    *(_WORD *)(&v7->p.marked + 1) = 255;
    v7->ts.tsv.len = (unsigned int)&dummynode_;
    if ( (unsigned int)(v6 + 1) > 0xFFFFFFF )
      luaG_runerror(L, fmt: "memory allocation error: block too big");
    v9 = luaM_realloc_(L, block: nullptr, osize: 0, nsize: 16 * v6);
    sizearray = v7->h.sizearray;
    v7->ts.tsv.keyhash = (unsigned int)v9;
    if ( sizearray < v6 )
    {
      v11 = 16 * sizearray;
      v12 = v6 - sizearray;
      do
      {
        *(_DWORD *)(v11 + v7->ts.tsv.keyhash + 8) = 0;
        v11 += 16;
        --v12;
      }
      while ( v12 != 0 );
    }
    v7->h.sizearray = v6;
    setnodevector(L, t: (Table *)v7, size: 1);
    htab = (Table *)v7;
    if ( v6 > 0 )
    {
      v13 = 1;
      v14 = -16 * v6;
      v29 = 1;
      v28 = 16;
      v27 = -16 * v6;
      v30 = v6;
      while ( 1 )
      {
        v15 = (int *)((char *)L->top + v14);
        if ( (unsigned int)(v13 - 1) >= v7->h.sizearray )
        {
          v18 = (double)v13;
          v35 = (double)v13;
          if ( (double)v13 == 0.0 )
          {
            len = v7->ts.tsv.len;
          }
          else
          {
            v13 = v29;
            len = v7->ts.tsv.len + 32 * ((LODWORD(v35) + HIDWORD(v35)) % (((1 << v7->cl.c.nupvalues) - 1) | 1u));
          }
          while ( *(_DWORD *)(len + 24) != 3 || *(double *)(len + 16) != v18 )
          {
            len = *(_DWORD *)(len + 28);
            if ( len == 0 )
              goto LABEL_26;
          }
        }
        else
        {
          len = v28 + v7->ts.tsv.keyhash - 16;
        }
        if ( (lua_TValue *)len == &luaO_nilobject_ )
        {
LABEL_26:
          key.value.n = (double)v13;
          key.tt = 3;
          v17 = newkey(L, t: (Table *)v7, &key);
          v13 = v29;
        }
        else
        {
          v17 = (lua_TValue *)len;
        }
        v17->value.b = *v15;
        *(&v17->value.b + 1) = v15[1];
        v17->tt = v15[2];
        v27 += 16;
        v28 += 16;
        ++v13;
        v19 = v30-- == 1;
        v29 = v13;
        if ( v19 )
          break;
        v14 = v27;
      }
      v6 = nvar;
    }
    nvara = luaS_newlstr(L, str: "n", l: 1u);
    v20 = (lua_TValue *)luaH_getstr(t: (Table *)v7, key: nvara);
    if ( v20 == &luaO_nilobject_ )
    {
      key.value.b = (int)nvara;
      key.tt = 4;
      v20 = newkey(L, t: (Table *)v7, &key);
    }
    numparams = nfixargs;
    v21 = (double)v6;
    v4 = actual;
    v20->value.n = v21;
    v20->tt = 3;
  }
  result = L->top;
  if ( numparams > 0 )
  {
    p_tt = &L->top[-v4].tt;
    for ( i = numparams; i != 0; --i )
    {
      top = L->top;
      L->top = top + 1;
      *top = *(lua_TValue *)(p_tt - 2);
      *p_tt = 0;
      p_tt += 4;
    }
  }
  if ( htab != nullptr )
  {
    v26 = L->top;
    L->top = v26 + 1;
    v26->value.b = (int)htab;
    v26->tt = 5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A260
// Name: tryfuncTM
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall tryfuncTM@<eax>(lua_State *L@<ecx>, lua_TValue *func@<eax>)
{
  int tt; // eax
  Table *v5; // eax
  int *v6; // ebx
  lua_TValue *top; // eax
  int *v8; // ecx
  int stacksize; // eax
  int v10; // edi
  int v11; // ebx
  lua_TValue *v12; // eax
  lua_TValue *result; // eax
  const lua_TValue *tm; // [esp+Ch] [ebp-Ch]
  lua_TValue *oldstack; // [esp+10h] [ebp-8h]
  int funcr; // [esp+14h] [ebp-4h]

  tt = func->tt;
  if ( tt == 5 )
  {
    v5 = *(Table **)(func->value.b + 8);
  }
  else if ( tt == 7 )
  {
    v5 = *(Table **)(func->value.b + 8);
  }
  else
  {
    v5 = L->l_G->mt[tt];
  }
  if ( v5 != nullptr )
  {
    v6 = (int *)luaH_getstr(t: v5, key: L->l_G->tmname[16]);
    tm = (const lua_TValue *)v6;
  }
  else
  {
    tm = &luaO_nilobject_;
    v6 = (int *)&luaO_nilobject_;
  }
  funcr = (char *)func - (char *)L->stack;
  if ( v6[2] != 6 )
    luaG_typeerror(L, o: func, op: "call");
  top = L->top;
  if ( top > func )
  {
    v8 = (int *)&top[-1];
    do
    {
      top->value.b = *v8;
      *(&top->value.b + 1) = v8[1];
      v8[6] = v8[2];
      --top;
      v8 -= 4;
    }
    while ( top > func );
  }
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    oldstack = L->stack;
    if ( stacksize < 1 )
    {
      v10 = stacksize + 1;
      v11 = stacksize + 7;
      if ( (unsigned int)(stacksize + 8) <= 0xFFFFFFF )
        goto LABEL_17;
    }
    else
    {
      v10 = 2 * stacksize;
      v11 = 2 * stacksize + 6;
      if ( (unsigned int)(2 * stacksize + 7) <= 0xFFFFFFF )
      {
LABEL_17:
        v12 = (lua_TValue *)luaM_realloc_(L, block: L->stack, osize: 16 * stacksize, nsize: 16 * v11);
        L->stack = v12;
        L->stacksize = v11;
        L->stack_last = &v12[v10];
        correctstack(L, oldstack);
        v6 = (int *)tm;
        goto LABEL_20;
      }
    }
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  }
LABEL_20:
  ++L->top;
  result = (lua_TValue *)((char *)L->stack + funcr);
  result->value.b = *v6;
  *(&result->value.b + 1) = v6[1];
  result->tt = v6[2];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3D0
// Name: _luaD_precall
// Source: json
//------------------------------------------------------------------------------
int __usercall luaD_precall@<eax>(lua_State *L@<ecx>, lua_TValue *func@<eax>, int nresults)
{
  int v4; // ebx
  int b; // eax
  Proto *v6; // ecx
  int maxstacksize; // eax
  int v8; // ecx
  int v9; // eax
  lua_TValue *v10; // edi
  lua_TValue *v11; // ebx
  lua_TValue *v12; // eax
  lua_TValue *v13; // eax
  CallInfo *v14; // eax
  CallInfo *v15; // eax
  lua_TValue *i; // ecx
  bool v17; // zf
  int stacksize; // eax
  int v20; // eax
  CallInfo *ci; // eax
  CallInfo *v22; // eax
  lua_TValue *v23; // ecx
  lua_TValue *top; // edx
  int v25; // eax
  Proto *p; // [esp+10h] [ebp-8h]

  if ( func->tt != 6 )
    func = tryfuncTM(L, func);
  v4 = (char *)func - (char *)L->stack;
  b = func->value.b;
  L->ci->savedpc = L->savedpc;
  if ( *(_BYTE *)(b + 6) != 0 )
  {
    if ( (char *)L->stack_last - (char *)L->top <= 320 )
    {
      stacksize = L->stacksize;
      if ( stacksize < 20 )
        v20 = stacksize + 20;
      else
        v20 = 2 * stacksize;
      luaD_reallocstack(L, newsize: v20);
    }
    ci = L->ci;
    if ( ci == L->end_ci )
    {
      v22 = growCI(L);
    }
    else
    {
      v22 = ci + 1;
      L->ci = v22;
    }
    v23 = (lua_TValue *)((char *)L->stack + v4);
    v22->func = v23++;
    v22->base = v23;
    top = L->top;
    L->base = v23;
    v22->top = top + 20;
    v22->nresults = nresults;
    if ( (L->hookmask & 1) != 0 )
      luaD_callhook(L, event: 0, line: -1);
    v25 = ((int (__cdecl *)(lua_State *))L->ci->func->value.gc->ts.tsv.len)(a1: L);
    if ( v25 >= 0 )
    {
      luaD_poscall(L, firstResult: &L->top[-v25]);
      return 1;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    v6 = *(Proto **)(b + 16);
    maxstacksize = v6->maxstacksize;
    p = v6;
    if ( (char *)L->stack_last - (char *)L->top <= 16 * maxstacksize )
    {
      v8 = L->stacksize;
      if ( maxstacksize > v8 )
        v9 = v8 + maxstacksize;
      else
        v9 = 2 * v8;
      luaD_reallocstack(L, newsize: v9);
      v6 = p;
    }
    v10 = (lua_TValue *)((char *)L->stack + v4);
    if ( v6->is_vararg != 0 )
    {
      v13 = adjust_varargs(L, p: v6, actual: L->top - v10 - 1);
      v6 = p;
      v10 = (lua_TValue *)((char *)L->stack + v4);
      v11 = v13;
    }
    else
    {
      v11 = v10 + 1;
      v12 = &v10[v6->numparams + 1];
      if ( L->top > v12 )
        L->top = v12;
    }
    v14 = L->ci;
    if ( v14 == L->end_ci )
    {
      v15 = growCI(L);
      v6 = p;
    }
    else
    {
      v15 = v14 + 1;
      L->ci = v15;
    }
    v15->func = v10;
    v15->base = v11;
    L->base = v11;
    v15->top = &v11[v6->maxstacksize];
    L->savedpc = v6->code;
    v15->tailcalls = 0;
    v15->nresults = nresults;
    for ( i = L->top; i < v15->top; ++i )
      i->tt = 0;
    v17 = (L->hookmask & 1) == 0;
    L->top = v15->top;
    if ( !v17 )
    {
      ++L->savedpc;
      luaD_callhook(L, event: 0, line: -1);
      --L->savedpc;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A5B0
// Name: callrethooks
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall callrethooks@<eax>(lua_State *L@<ecx>, lua_TValue *firstResult@<eax>)
{
  CallInfo *ci; // eax
  int tailcalls; // ecx
  lua_TValue *stack; // ecx
  char *v6; // edi
  char *v7; // ebx
  int v8; // ecx
  int stacksize; // eax
  int v10; // eax
  CallInfo *v11; // eax
  lua_TValue *v12; // edx
  _DWORD v14[25]; // [esp+4h] [ebp-6Ch] BYREF
  int fr; // [esp+68h] [ebp-8h]
  void (__cdecl *hook)(lua_State *, lua_Debug *); // [esp+6Ch] [ebp-4h]

  fr = (char *)firstResult - (char *)L->stack;
  luaD_callhook(L, event: 1, line: -1);
  if ( L->ci->func->value.gc->ts.tsv.reserved == 0 && (L->hookmask & 2) != 0 )
  {
    do
    {
      ci = L->ci;
      tailcalls = ci->tailcalls;
      ci->tailcalls = tailcalls - 1;
      if ( tailcalls == 0 )
        break;
      hook = L->hook;
      if ( hook != nullptr && L->allowhook != 0 )
      {
        stack = L->stack;
        v6 = (char *)((char *)L->top - (char *)stack);
        v7 = (char *)((char *)L->ci->top - (char *)stack);
        v8 = (char *)L->stack_last - (char *)L->top;
        v14[0] = 4;
        v14[5] = -1;
        v14[24] = 0;
        if ( v8 <= 320 )
        {
          stacksize = L->stacksize;
          if ( stacksize < 20 )
            v10 = stacksize + 20;
          else
            v10 = 2 * stacksize;
          luaD_reallocstack(L, newsize: v10);
        }
        L->ci->top = L->top + 20;
        L->allowhook = 0;
        hook(a1: L, a2: (lua_Debug *)v14);
        v11 = L->ci;
        v12 = (lua_TValue *)&v7[(unsigned int)L->stack];
        L->allowhook = 1;
        v11->top = v12;
        L->top = (lua_TValue *)&v6[(unsigned int)L->stack];
      }
    }
    while ( (L->hookmask & 2) != 0 );
  }
  return (lua_TValue *)((char *)L->stack + fr);
}

//------------------------------------------------------------------------------
// Address: 0x1000A6B0
// Name: _luaD_poscall
// Source: json
//------------------------------------------------------------------------------
int __usercall luaD_poscall@<eax>(lua_TValue *firstResult@<eax>, lua_State *L)
{
  lua_State *v2; // ebx
  CallInfo *ci; // edx
  int nresults; // edi
  lua_TValue *func; // ecx
  int v6; // esi
  lua_TValue *v7; // edi
  lua_TValue *v8; // edx
  int tt; // eax
  int wanted; // [esp+Ch] [ebp-4h]

  v2 = L;
  if ( (L->hookmask & 2) != 0 )
    firstResult = callrethooks(L, firstResult);
  ci = L->ci;
  L->ci = ci - 1;
  nresults = ci->nresults;
  func = ci->func;
  L->base = ci[-1].base;
  wanted = nresults;
  L->savedpc = ci[-1].savedpc;
  v6 = nresults;
  if ( nresults != 0 )
  {
    v7 = firstResult;
    do
    {
      if ( v7 >= v2->top )
        break;
      v8 = func;
      func->value.b = v7->value.b;
      *(&func->value.b + 1) = *(&v7->value.b + 1);
      tt = v7->tt;
      v2 = L;
      ++func;
      ++v7;
      --v6;
      v8->tt = tt;
    }
    while ( v6 != 0 );
    nresults = wanted;
  }
  for ( ; v6 > 0; ++func )
  {
    --v6;
    func->tt = 0;
  }
  v2->top = func;
  return nresults + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A740
// Name: _luaD_call
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_call(lua_State *L, lua_TValue *func, int nResults)
{
  unsigned __int16 v3; // ax

  v3 = ++L->nCcalls;
  if ( v3 >= 0xC8u )
  {
    if ( v3 == 200 )
      luaG_runerror(L, fmt: "C stack overflow");
    if ( v3 >= 0xE1u )
      luaD_throw(L, errcode: 5);
  }
  if ( luaD_precall(L, func, nresults: nResults) == 0 )
    luaV_execute(L, nexeccalls: 1);
  --L->nCcalls;
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
}

//------------------------------------------------------------------------------
// Address: 0x1000A7D0
// Name: resume
// Source: json
//------------------------------------------------------------------------------
void __cdecl resume(lua_State *L, lua_TValue *ud)
{
  CallInfo *ci; // eax

  ci = L->ci;
  if ( L->status != 0 )
  {
    L->status = 0;
    if ( ci->func->value.gc->ts.tsv.reserved != 0 )
    {
      if ( luaD_poscall(firstResult: ud, L) != 0 )
        L->top = L->ci->top;
    }
    else
    {
      L->base = ci->base;
    }
  }
  else if ( luaD_precall(L, func: ud - 1, nresults: -1) != 0 )
  {
    return;
  }
  luaV_execute(L, nexeccalls: L->ci - L->base_ci);
}

//------------------------------------------------------------------------------
// Address: 0x1000A850
// Name: resume_error
// Source: json
//------------------------------------------------------------------------------
int __usercall resume_error@<eax>(lua_State *L@<eax>, const char *msg@<edx>)
{
  lua_TValue *base; // edi
  int stacksize; // eax

  base = L->ci->base;
  L->top = base;
  base->value.b = (int)luaS_newlstr(L, str: msg, l: strlen(msg));
  base->tt = 4;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    if ( stacksize >= 1 )
    {
      luaD_reallocstack(L, newsize: 2 * stacksize);
      ++L->top;
      return 2;
    }
    luaD_reallocstack(L, newsize: stacksize + 1);
  }
  ++L->top;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8D0
// Name: _lua_resume
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_resume@<eax>(lua_State *L@<eax>, int nargs@<ecx>)
{
  unsigned __int8 status; // al
  unsigned __int16 nCcalls; // ax
  unsigned __int16 v6; // ax
  int v7; // eax
  int v8; // ebx
  lua_TValue *top; // ecx

  status = L->status;
  if ( status != 1 && (status != 0 || L->ci != L->base_ci) )
    return resume_error(L, msg: "cannot resume non-suspended coroutine");
  nCcalls = L->nCcalls;
  if ( nCcalls >= 0xC8u )
    return resume_error(L, msg: "C stack overflow");
  v6 = nCcalls + 1;
  L->nCcalls = v6;
  L->baseCcalls = v6;
  v7 = luaD_rawrunprotected(L, f: (void (__cdecl *)(lua_State *, void *))resume, ud: &L->top[-nargs]);
  v8 = v7;
  if ( v7 != 0 )
  {
    top = L->top;
    L->status = v7;
    luaD_seterrorobj(L, errcode: v7, oldtop: top);
    L->ci->top = L->top;
  }
  else
  {
    v8 = L->status;
  }
  --L->nCcalls;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1000A970
// Name: _luaD_pcall
// Source: json
//------------------------------------------------------------------------------
int __usercall luaD_pcall@<eax>(
        lua_State *L@<eax>,
        int ef@<edx>,
        void (__cdecl *func)(lua_State *, void *),
        void *u,
        int old_top)
{
  int errfunc; // esi
  int v7; // ebx
  int result; // eax
  lua_TValue *v9; // esi
  TString *v10; // eax
  lua_TValue *top; // eax
  CallInfo *base_ci; // ecx
  bool v13; // cc
  unsigned __int16 oldnCcalls; // [esp+Ch] [ebp-10h]
  int old_errfunc; // [esp+10h] [ebp-Ch]
  int status; // [esp+14h] [ebp-8h]
  unsigned __int8 old_allowhooks; // [esp+1Bh] [ebp-1h]

  errfunc = L->errfunc;
  v7 = (char *)L->ci - (char *)L->base_ci;
  oldnCcalls = L->nCcalls;
  old_allowhooks = L->allowhook;
  old_errfunc = errfunc;
  L->errfunc = ef;
  result = luaD_rawrunprotected(L, f: func, ud: u);
  status = result;
  if ( result != 0 )
  {
    v9 = (lua_TValue *)((char *)L->stack + old_top);
    luaF_close(L, level: v9);
    switch ( status )
    {
      case 2:
      case 3:
        top = L->top;
        v9->value.b = top[-1].value.b;
        *(&v9->value.b + 1) = *(&top[-1].value.b + 1);
        v9->tt = top[-1].tt;
        break;
      case 4:
        v10 = luaS_newlstr(L, str: "not enough memory", l: 0x11u);
        goto LABEL_4;
      case 5:
        v10 = luaS_newlstr(L, str: "error in error handling", l: 0x17u);
LABEL_4:
        v9->value.b = (int)v10;
        v9->tt = 4;
        break;
      default:
        break;
    }
    base_ci = L->base_ci;
    L->nCcalls = oldnCcalls;
    v13 = L->size_ci <= 20000;
    L->top = v9 + 1;
    L->ci = (CallInfo *)((char *)base_ci + v7);
    L->base = *(lua_TValue **)((char *)&base_ci->base + v7);
    L->savedpc = *(const unsigned int **)((char *)&base_ci->savedpc + v7);
    L->allowhook = old_allowhooks;
    if ( v13 )
    {
      L->errfunc = old_errfunc;
      return status;
    }
    else
    {
      if ( v7 / 24 + 1 < 20000 )
        luaD_reallocCI(L, newsize: 20000);
      L->errfunc = old_errfunc;
      return status;
    }
  }
  else
  {
    L->errfunc = errfunc;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AAC0
// Name: f_parser
// Source: json
//------------------------------------------------------------------------------
void __cdecl f_parser(lua_State *L, const char **ud)
{
  char *v2; // esi
  int v3; // eax
  unsigned __int8 *p_maxstacksize; // ecx
  int v5; // eax
  int v6; // ebx
  Proto *(__cdecl *v7)(lua_State *, Zio *, Mbuffer *, const char *); // eax
  Proto *v8; // eax
  int nups; // ebx
  GCObject *gc; // edx
  int v11; // edi
  int v12; // ecx
  global_State *v13; // eax
  _DWORD *v14; // eax
  Proto *v15; // eax
  global_State *v16; // ebx
  int v17; // eax
  global_State *v18; // ecx
  Proto *v19; // edx
  lua_TValue *top; // eax
  int stacksize; // eax
  lua_TValue *stack; // ecx
  global_State *v23; // ebx
  int v24; // edi
  lua_TValue *v25; // eax
  int i; // [esp+Ch] [ebp-Ch]
  int ia; // [esp+Ch] [ebp-Ch]
  lua_TValue *ib; // [esp+Ch] [ebp-Ch]
  global_State *l_G; // [esp+10h] [ebp-8h]
  int *v30; // [esp+10h] [ebp-8h]
  int v31; // [esp+10h] [ebp-8h]
  Proto *v32; // [esp+14h] [ebp-4h] BYREF

  v2 = (char *)*ud;
  if ( *(_DWORD *)*ud == 0 )
  {
    v3 = (*((int (__cdecl **)(_DWORD, _DWORD, Proto **))v2 + 2))(
           a1: *((_DWORD *)v2 + 4),
           a2: *((_DWORD *)v2 + 3),
           a3: &v32);
    if ( v3 == 0 || v32 == nullptr )
    {
      v6 = -1;
      goto LABEL_8;
    }
    p_maxstacksize = &v32[-1].maxstacksize;
    *((_DWORD *)v2 + 1) = v3;
    *(_DWORD *)v2 = p_maxstacksize;
    v5 = v3 + 1;
    *((_DWORD *)v2 + 1) = v5;
    *(_DWORD *)v2 = p_maxstacksize + 1;
    *((_DWORD *)v2 + 1) = v5 - 1;
  }
  v6 = **((unsigned __int8 **)v2 + 1);
LABEL_8:
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  v7 = luaU_undump;
  if ( v6 != 27 )
    v7 = luaY_parser;
  v8 = v7(L, Z: (Zio *)*ud, buff: (Mbuffer *)(ud + 1), name: ud[4]);
  nups = v8->nups;
  gc = L->l_gt.value.gc;
  v32 = v8;
  i = (int)gc;
  l_G = L->l_G;
  v11 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 4 * nups + 20);
  if ( v11 == 0 && 4 * nups != -20 )
    goto LABEL_14;
  v12 = 4 * nups + 20;
  l_G->totalbytes += v12;
  v13 = L->l_G;
  *(_DWORD *)v11 = v13->rootgc;
  v13->rootgc = (GCObject *)v11;
  *(_BYTE *)(v11 + 5) = v13->currentwhite & 3;
  *(_BYTE *)(v11 + 4) = 6;
  *(_BYTE *)(v11 + 6) = 0;
  *(_DWORD *)(v11 + 12) = i;
  *(_BYTE *)(v11 + 7) = nups;
  if ( nups != 0 )
  {
    v14 = (_DWORD *)(v12 + v11);
    do
    {
      --v14;
      --nups;
      *v14 = 0;
    }
    while ( nups != 0 );
  }
  v15 = v32;
  *(_DWORD *)(v11 + 16) = v32;
  ia = 0;
  if ( v15->nups != 0 )
  {
    v30 = (int *)(v11 + 20);
    while ( 1 )
    {
      v16 = L->l_G;
      v17 = (int)v16->frealloc(a1: v16->ud, a2: nullptr, a3: 0, a4: 32u);
      if ( v17 == 0 )
        break;
      v16->totalbytes += 32;
      v18 = L->l_G;
      *(_DWORD *)v17 = v18->rootgc;
      v19 = v32;
      v18->rootgc = (GCObject *)v17;
      *(_BYTE *)(v17 + 5) = v18->currentwhite & 3;
      *(_DWORD *)(v17 + 8) = v17 + 16;
      *(_BYTE *)(v17 + 4) = 10;
      *(_DWORD *)(v17 + 24) = 0;
      *v30++ = v17;
      if ( ++ia >= v19->nups )
        goto LABEL_22;
    }
LABEL_14:
    luaD_throw(L, errcode: 4);
  }
LABEL_22:
  top = L->top;
  top->value.b = v11;
  top->tt = 6;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    stack = L->stack;
    ib = stack;
    if ( stacksize < 1 )
    {
      v31 = stacksize + 1;
      if ( (unsigned int)(stacksize + 8) <= 0xFFFFFFF )
      {
        v23 = L->l_G;
        v24 = 16 * (stacksize + 7);
        v32 = (Proto *)(16 * stacksize);
        v25 = (lua_TValue *)v23->frealloc(a1: v23->ud, a2: stack, a3: 16 * stacksize, a4: v24);
        if ( v25 == nullptr && v24 != 0 )
          luaD_throw(L, errcode: 4);
        goto $LN74;
      }
    }
    else
    {
      v31 = 2 * stacksize;
      if ( (unsigned int)(2 * stacksize + 7) <= 0xFFFFFFF )
      {
        v23 = L->l_G;
        v24 = 16 * (2 * stacksize + 6);
        v32 = (Proto *)(16 * stacksize);
        v25 = (lua_TValue *)v23->frealloc(a1: v23->ud, a2: stack, a3: 16 * stacksize, a4: v24);
        if ( v25 == nullptr && v24 != 0 )
          luaD_throw(L, errcode: 4);
$LN74:
        v23->totalbytes += v24 - (_DWORD)v32;
        L->stacksize = v31 + 6;
        L->stack = v25;
        L->stack_last = &v25[v31];
        correctstack(L, oldstack: ib);
        goto LABEL_34;
      }
    }
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  }
LABEL_34:
  ++L->top;
}
