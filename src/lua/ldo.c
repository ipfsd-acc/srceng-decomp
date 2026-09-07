// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ldo.c
// Functions: 23
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00477360
// Name: void luaD_seterrorobj(struct lua_State __near *,int,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_seterrorobj(lua_State *L, int errcode, lua_TValue *oldtop)
{
  TString *v3; // eax

  switch ( errcode )
  {
    case 2:
    case 3:
      *oldtop = L->top[-1];
      goto LABEL_6;
    case 4:
      v3 = luaS_newlstr(L, str: "not enough memory", l: 0x11u);
      goto LABEL_3;
    case 5:
      v3 = luaS_newlstr(L, str: "error in error handling", l: 0x17u);
LABEL_3:
      oldtop->value.b = (int)v3;
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
// Address: 0x004773E0
// Name: int luaD_rawrunprotected(struct lua_State __near *,void (*)(struct lua_State __near *,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaD_rawrunprotected(lua_State *L, void (__cdecl *f)(lua_State *, void *), void *ud)
{
  lua_longjmp *errorJmp; // ecx
  volatile int result; // eax
  int v5; // [esp+0h] [ebp-28h] BYREF
  lua_longjmp lj; // [esp+Ch] [ebp-1Ch] BYREF
  int *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  errorJmp = L->errorJmp;
  lj.status = 0;
  v8 = 0;
  v7 = &v5;
  lj.previous = errorJmp;
  L->errorJmp = &lj;
  f(a1: L, a2: ud);
  result = lj.status;
  L->errorJmp = lj.previous;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00477460
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
// Address: 0x004774E0
// Name: void luaD_reallocstack(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_reallocstack(lua_State *L, int newsize)
{
  lua_TValue *stack; // eax
  int v4; // ebx
  lua_TValue *v5; // eax
  lua_TValue *La; // [esp+14h] [ebp+8h]

  stack = L->stack;
  v4 = newsize + 6;
  La = stack;
  if ( (unsigned int)(newsize + 7) > 0xFFFFFFF )
    luaM_toobig(L);
  v5 = (lua_TValue *)luaM_realloc_(L, block: stack, osize: 16 * L->stacksize, nsize: 16 * v4);
  L->stack_last = &v5[newsize];
  L->stacksize = v4;
  L->stack = v5;
  correctstack(L, oldstack: La);
}

//------------------------------------------------------------------------------
// Address: 0x00477540
// Name: void luaD_reallocCI(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_reallocCI(lua_State *L, int newsize)
{
  CallInfo *base_ci; // ecx
  CallInfo *v4; // ebx
  CallInfo *v5; // edx
  lua_State *La; // [esp+14h] [ebp+8h]

  base_ci = L->base_ci;
  La = (lua_State *)base_ci;
  if ( (unsigned int)(newsize + 1) > 0xAAAAAAA )
    luaM_toobig(L);
  v4 = (CallInfo *)luaM_realloc_(L, block: base_ci, osize: 24 * L->size_ci, nsize: 24 * newsize);
  v5 = &v4[((char *)L->ci - (char *)La) / 24];
  L->size_ci = newsize;
  L->base_ci = v4;
  L->ci = v5;
  L->end_ci = &v4[newsize - 1];
}

//------------------------------------------------------------------------------
// Address: 0x004775C0
// Name: void luaD_growstack(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_growstack(lua_State *L, int n)
{
  int stacksize; // eax

  stacksize = L->stacksize;
  if ( n > stacksize )
    luaD_reallocstack(L, newsize: n + stacksize);
  else
    luaD_reallocstack(L, newsize: 2 * stacksize);
}

//------------------------------------------------------------------------------
// Address: 0x004775F0
// Name: void luaD_callhook(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_callhook(lua_State *L, int event, int line)
{
  lua_TValue *stack; // ecx
  CallInfo *ci; // eax
  char *v6; // edi
  int v7; // ebx
  int stacksize; // eax
  CallInfo *v9; // ecx
  lua_TValue *v10; // eax
  lua_Debug ar; // [esp+4h] [ebp-64h] BYREF
  void (__cdecl *hook)(lua_State *, lua_Debug *); // [esp+70h] [ebp+8h]

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
        luaD_reallocstack(L, newsize: stacksize + 20);
      else
        luaD_reallocstack(L, newsize: 2 * stacksize);
    }
    L->ci->top = L->top + 20;
    L->allowhook = 0;
    hook(a1: L, a2: &ar);
    v9 = L->ci;
    v10 = (lua_TValue *)((char *)L->stack + v7);
    L->allowhook = 1;
    v9->top = v10;
    L->top = (lua_TValue *)&v6[(unsigned int)L->stack];
  }
}

//------------------------------------------------------------------------------
// Address: 0x004776C0
// Name: adjust_varargs
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall adjust_varargs@<eax>(lua_State *L@<esi>, Proto *p@<ecx>, int actual)
{
  int numparams; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  lua_TValue *v10; // edi
  TString *v11; // eax
  lua_TValue *v12; // eax
  lua_TValue *result; // eax
  int *p_tt; // ecx
  int j; // ebx
  lua_TValue *top; // edx
  lua_TValue *v17; // ecx
  int nfixargs; // [esp+8h] [ebp-10h]
  int nvar; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  Table *htab; // [esp+14h] [ebp-4h]

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
    nvar = v4 - numparams;
    if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
      luaC_step(L);
    htab = luaH_new(L, narray: v6, nhash: 1);
    v7 = 0;
    if ( v6 > 0 )
    {
      v8 = -16 * v6;
      for ( i = -16 * v6; ; v8 = i )
      {
        v9 = v7 + 1;
        v10 = (lua_TValue *)((char *)L->top + v8);
        i += 16;
        *luaH_setnum(L, t: htab, key: v7 + 1) = *v10;
        v7 = v9;
        if ( v9 >= nvar )
          break;
      }
      v4 = actual;
      v6 = nvar;
    }
    v11 = luaS_newlstr(L, str: "n", l: 1u);
    v12 = luaH_setstr(L, t: htab, key: v11);
    numparams = nfixargs;
    v12->value.n = (double)v6;
    v12->tt = 3;
  }
  result = L->top;
  if ( numparams > 0 )
  {
    p_tt = &L->top[-v4].tt;
    for ( j = numparams; j != 0; --j )
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
    v17 = L->top;
    L->top = v17 + 1;
    v17->value.b = (int)htab;
    v17->tt = 5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00477810
// Name: tryfuncTM
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall tryfuncTM@<eax>(lua_State *L@<esi>, lua_TValue *func@<eax>)
{
  int *v3; // ebx
  lua_TValue *top; // ecx
  int *v5; // eax
  int stacksize; // eax
  int v7; // edi
  int v8; // ebx
  lua_TValue *v9; // eax
  lua_TValue *result; // eax
  int funcr; // [esp+8h] [ebp-Ch]
  const lua_TValue *tm; // [esp+Ch] [ebp-8h]
  lua_TValue *oldstack; // [esp+10h] [ebp-4h]

  v3 = (int *)luaT_gettmbyobj(L, o: func, event: TM_CALL);
  tm = (const lua_TValue *)v3;
  funcr = (char *)func - (char *)L->stack;
  if ( v3[2] != 6 )
    luaG_typeerror(L, o: func, op: "call");
  top = L->top;
  if ( top > func )
  {
    v5 = (int *)&top[-1];
    do
    {
      top->value.b = *v5;
      *(&top->value.b + 1) = v5[1];
      v5[6] = v5[2];
      --top;
      v5 -= 4;
    }
    while ( top > func );
  }
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    oldstack = L->stack;
    if ( stacksize < 1 )
    {
      v7 = stacksize + 1;
      v8 = stacksize + 7;
      if ( (unsigned int)(stacksize + 8) <= 0xFFFFFFF )
        goto LABEL_9;
    }
    else
    {
      v7 = 2 * stacksize;
      v8 = 2 * stacksize + 6;
      if ( (unsigned int)(2 * stacksize + 7) <= 0xFFFFFFF )
      {
LABEL_9:
        v9 = (lua_TValue *)luaM_realloc_(L, block: L->stack, osize: 16 * stacksize, nsize: 16 * v8);
        L->stack = v9;
        L->stacksize = v8;
        L->stack_last = &v9[v7];
        correctstack(L, oldstack);
        v3 = (int *)tm;
        goto LABEL_12;
      }
    }
    luaM_toobig(L);
  }
LABEL_12:
  ++L->top;
  result = (lua_TValue *)((char *)L->stack + funcr);
  result->value.b = *v3;
  *(&result->value.b + 1) = v3[1];
  result->tt = v3[2];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00477920
// Name: callrethooks
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall callrethooks@<eax>(lua_State *L@<esi>, lua_TValue *firstResult@<eax>)
{
  CallInfo *ci; // eax
  lua_TValue *stack; // ecx
  char *v4; // edi
  char *v5; // ebx
  int v6; // ecx
  int stacksize; // eax
  CallInfo *v8; // ecx
  lua_TValue *v9; // eax
  _DWORD v11[25]; // [esp+0h] [ebp-6Ch] BYREF
  int fr; // [esp+64h] [ebp-8h]
  void (__cdecl *hook)(lua_State *, lua_Debug *); // [esp+68h] [ebp-4h]

  fr = (char *)firstResult - (char *)L->stack;
  luaD_callhook(L, event: 1, line: -1);
  ci = L->ci;
  if ( ci->func->value.gc->ts.tsv.reserved == 0 )
  {
    if ( ci->tailcalls != 0 )
    {
      do
      {
        --L->ci->tailcalls;
        hook = L->hook;
        if ( hook != nullptr && L->allowhook != 0 )
        {
          stack = L->stack;
          v4 = (char *)((char *)L->top - (char *)stack);
          v5 = (char *)((char *)L->ci->top - (char *)stack);
          v6 = (char *)L->stack_last - (char *)L->top;
          v11[0] = 4;
          v11[5] = -1;
          v11[24] = 0;
          if ( v6 <= 320 )
          {
            stacksize = L->stacksize;
            if ( stacksize < 20 )
              luaD_reallocstack(L, newsize: stacksize + 20);
            else
              luaD_reallocstack(L, newsize: 2 * stacksize);
          }
          L->ci->top = L->top + 20;
          L->allowhook = 0;
          hook(a1: L, a2: (lua_Debug *)v11);
          v8 = L->ci;
          v9 = (lua_TValue *)&v5[(unsigned int)L->stack];
          L->allowhook = 1;
          v8->top = v9;
          L->top = (lua_TValue *)&v4[(unsigned int)L->stack];
        }
      }
      while ( L->ci->tailcalls != 0 );
    }
    --L->ci->tailcalls;
  }
  return (lua_TValue *)((char *)L->stack + fr);
}

//------------------------------------------------------------------------------
// Address: 0x00477A20
// Name: int luaD_poscall(struct lua_State __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaD_poscall(lua_State *L, lua_TValue *firstResult)
{
  lua_TValue *v2; // eax
  lua_State *v3; // esi
  CallInfo *ci; // edx
  int nresults; // ebx
  lua_TValue *func; // ecx
  int v7; // edi
  lua_TValue *v8; // ebx
  lua_TValue *v9; // edx
  int tt; // eax
  int wanted; // [esp+Ch] [ebp-4h]

  v2 = firstResult;
  v3 = L;
  if ( (L->hookmask & 2) != 0 )
    v2 = callrethooks(L, firstResult);
  ci = L->ci;
  L->ci = ci - 1;
  nresults = ci->nresults;
  func = ci->func;
  L->base = ci[-1].base;
  wanted = nresults;
  L->savedpc = ci[-1].savedpc;
  v7 = nresults;
  if ( nresults != 0 )
  {
    v8 = v2;
    do
    {
      if ( v8 >= v3->top )
        break;
      v9 = func;
      func->value.b = v8->value.b;
      *(&func->value.b + 1) = *(&v8->value.b + 1);
      tt = v8->tt;
      v3 = L;
      ++func;
      ++v8;
      --v7;
      v9->tt = tt;
    }
    while ( v7 != 0 );
    nresults = wanted;
  }
  for ( ; v7 > 0; ++func )
  {
    --v7;
    func->tt = 0;
  }
  v3->top = func;
  return nresults + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00477AB0
// Name: resume_error
// Source: json
//------------------------------------------------------------------------------
int __usercall resume_error@<eax>(lua_State *L@<esi>, const char *msg@<edx>)
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
// Address: 0x00477B30
// Name: int lua_yield(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_yield(lua_State *L, int nresults)
{
  if ( L->nCcalls != 0 )
    luaG_runerror(L, fmt: "attempt to yield across metamethod/C-call boundary");
  L->base = &L->top[-nresults];
  L->status = 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477B70
// Name: f_parser
// Source: json
//------------------------------------------------------------------------------
void __cdecl f_parser(lua_State *L, Zio **ud)
{
  int v3; // ebx
  Proto *(__cdecl *v4)(lua_State *, Zio *, Mbuffer *, const char *); // eax
  Proto *v5; // edi
  Closure *v6; // eax
  int v7; // ebx
  lua_TValue *top; // ecx
  int stacksize; // eax
  int v10; // edi
  int v11; // ebx
  lua_TValue *v12; // eax
  lua_State *La; // [esp+14h] [ebp+8h]
  UpVal **uda; // [esp+18h] [ebp+Ch]
  lua_TValue *udb; // [esp+18h] [ebp+Ch]

  v3 = luaZ_lookahead(z: *ud);
  if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
    luaC_step(L);
  v4 = luaU_undump;
  if ( v3 != 27 )
    v4 = luaY_parser;
  v5 = v4(L, Z: *ud, buff: (Mbuffer *)(ud + 1), name: (const char *)ud[4]);
  v6 = luaF_newLclosure(L, nelems: v5->nups, e: (Table *)L->l_gt.value.gc);
  v7 = 0;
  v6->c.f = (int (__cdecl *)(lua_State *))v5;
  La = (lua_State *)v6;
  if ( v5->nups != 0 )
  {
    uda = v6->l.upvals;
    do
    {
      *uda = luaF_newupval(L);
      ++v7;
      ++uda;
    }
    while ( v7 < v5->nups );
    v6 = (Closure *)La;
  }
  top = L->top;
  top->value.b = (int)v6;
  top->tt = 6;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    udb = L->stack;
    if ( stacksize < 1 )
    {
      v10 = stacksize + 1;
      v11 = stacksize + 7;
      if ( (unsigned int)(stacksize + 8) <= 0xFFFFFFF )
        goto LABEL_12;
    }
    else
    {
      v10 = 2 * stacksize;
      v11 = 2 * stacksize + 6;
      if ( (unsigned int)(2 * stacksize + 7) <= 0xFFFFFFF )
      {
LABEL_12:
        v12 = (lua_TValue *)luaM_realloc_(L, block: L->stack, osize: 16 * stacksize, nsize: 16 * v11);
        L->stack = v12;
        L->stacksize = v11;
        L->stack_last = &v12[v10];
        correctstack(L, oldstack: udb);
        goto LABEL_15;
      }
    }
    luaM_toobig(L);
  }
LABEL_15:
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00477CA0
// Name: resetstack
// Source: json
//------------------------------------------------------------------------------
void __usercall resetstack(lua_State *L@<esi>, int status)
{
  CallInfo *base_ci; // eax
  bool v3; // cc
  lua_TValue *base; // [esp-4h] [ebp-4h]

  base_ci = L->base_ci;
  L->ci = base_ci;
  base = base_ci->base;
  L->base = base_ci->base;
  luaF_close(L, level: base);
  luaD_seterrorobj(L, errcode: status, oldtop: L->base);
  v3 = L->size_ci <= 20000;
  L->nCcalls = 0;
  L->allowhook = 1;
  if ( !v3 && L->ci - L->base_ci + 1 < 20000 )
    luaD_reallocCI(L, newsize: 20000);
  L->errfunc = 0;
  L->errorJmp = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00477D20
// Name: void luaD_throw(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaD_throw(lua_State *L, int errcode)
{
  lua_State *v2; // esi
  lua_longjmp *errorJmp; // eax
  int v4; // eax
  global_State *l_G; // ecx

  v2 = L;
  errorJmp = L->errorJmp;
  if ( errorJmp != nullptr )
  {
    errorJmp->status = errcode;
    L = (lua_State *)v2->errorJmp;
    _CxxThrowException(pExceptionObject: &L, pThrowInfo: &_TI2PAUlua_longjmp__);
  }
  v4 = errcode;
  l_G = L->l_G;
  L->status = errcode;
  if ( l_G->panic != nullptr )
  {
    resetstack(L: v2, status: v4);
    v2->l_G->panic(a1: v2);
  }
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00477D80
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
// Address: 0x00477DC0
// Name: int luaD_precall(struct lua_State __near *,struct lua_TValue __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaD_precall(lua_State *L, lua_TValue *func, int nresults)
{
  lua_TValue *v3; // eax
  int v4; // ebx
  int b; // eax
  Proto *v6; // ecx
  int maxstacksize; // eax
  int v8; // ecx
  lua_TValue *v9; // edi
  lua_TValue *v10; // ebx
  lua_TValue *v11; // eax
  lua_TValue *v12; // eax
  CallInfo *v13; // eax
  CallInfo *v14; // eax
  lua_TValue *i; // ecx
  bool v16; // zf
  int stacksize; // eax
  CallInfo *ci; // eax
  CallInfo *v20; // eax
  lua_TValue *v21; // ecx
  lua_TValue *top; // edx
  int v23; // eax
  Proto *p; // [esp+14h] [ebp+Ch]

  v3 = func;
  if ( func->tt != 6 )
    v3 = tryfuncTM(L, func);
  v4 = (char *)v3 - (char *)L->stack;
  b = v3->value.b;
  L->ci->savedpc = L->savedpc;
  if ( *(_BYTE *)(b + 6) != 0 )
  {
    if ( (char *)L->stack_last - (char *)L->top <= 320 )
    {
      stacksize = L->stacksize;
      if ( stacksize < 20 )
        luaD_reallocstack(L, newsize: stacksize + 20);
      else
        luaD_reallocstack(L, newsize: 2 * stacksize);
    }
    ci = L->ci;
    if ( ci == L->end_ci )
    {
      v20 = growCI(L);
    }
    else
    {
      v20 = ci + 1;
      L->ci = v20;
    }
    v21 = (lua_TValue *)((char *)L->stack + v4);
    v20->func = v21++;
    v20->base = v21;
    top = L->top;
    L->base = v21;
    v20->top = top + 20;
    v20->nresults = nresults;
    if ( (L->hookmask & 1) != 0 )
      luaD_callhook(L, event: 0, line: -1);
    v23 = ((int (__cdecl *)(lua_State *))L->ci->func->value.gc->u.uv.len)(a1: L);
    if ( v23 >= 0 )
    {
      luaD_poscall(L, firstResult: &L->top[-v23]);
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
        luaD_reallocstack(L, newsize: maxstacksize + v8);
      else
        luaD_reallocstack(L, newsize: 2 * v8);
      v6 = p;
    }
    v9 = (lua_TValue *)((char *)L->stack + v4);
    if ( v6->is_vararg != 0 )
    {
      v12 = adjust_varargs(L, p: v6, actual: L->top - v9 - 1);
      v6 = p;
      v9 = (lua_TValue *)((char *)L->stack + v4);
      v10 = v12;
    }
    else
    {
      v10 = v9 + 1;
      v11 = &v9[v6->numparams + 1];
      if ( L->top > v11 )
        L->top = v11;
    }
    v13 = L->ci;
    if ( v13 == L->end_ci )
    {
      v14 = growCI(L);
      v6 = p;
    }
    else
    {
      v14 = v13 + 1;
      L->ci = v14;
    }
    v14->func = v9;
    v14->base = v10;
    L->base = v10;
    v14->top = &v10[v6->maxstacksize];
    L->savedpc = v6->code;
    v14->tailcalls = 0;
    v14->nresults = nresults;
    for ( i = L->top; i < v14->top; ++i )
      i->tt = 0;
    v16 = (L->hookmask & 1) == 0;
    L->top = v14->top;
    if ( !v16 )
    {
      ++L->savedpc;
      luaD_callhook(L, event: 0, line: -1);
      --L->savedpc;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477F90
// Name: void luaD_call(struct lua_State __near *,struct lua_TValue __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaD_call(lua_State *L, lua_TValue *func, int nResults)
{
  unsigned __int16 v3; // ax
  global_State *l_G; // eax

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
  l_G = L->l_G;
  --L->nCcalls;
  if ( l_G->totalbytes >= l_G->GCthreshold )
    luaC_step(L);
}

//------------------------------------------------------------------------------
// Address: 0x00478020
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
      if ( luaD_poscall(L, firstResult: ud) != 0 )
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
// Address: 0x004780A0
// Name: int lua_resume(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_resume(lua_State *L, int nargs)
{
  unsigned __int8 status; // al
  int v4; // ebx
  lua_TValue *top; // [esp-8h] [ebp-Ch]

  status = L->status;
  if ( status != 1 )
  {
    if ( status != 0 )
      return resume_error(L, msg: "cannot resume dead coroutine");
    if ( L->ci != L->base_ci )
      return resume_error(L, msg: "cannot resume non-suspended coroutine");
  }
  v4 = luaD_rawrunprotected(L, f: (void (__cdecl *)(lua_State *, void *))resume, ud: &L->top[-nargs]);
  if ( v4 == 0 )
    return L->status;
  top = L->top;
  L->status = v4;
  luaD_seterrorobj(L, errcode: v4, oldtop: top);
  L->ci->top = L->top;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00478120
// Name: int luaD_pcall(struct lua_State __near *,void (*)(struct lua_State __near *,void __near *),void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaD_pcall(lua_State *L, void (__cdecl *func)(lua_State *, void *), void *u, int old_top, int ef)
{
  int errfunc; // edi
  int result; // eax
  int v8; // ebx
  lua_TValue *v9; // edi
  CallInfo *base_ci; // edi
  bool v11; // cc
  int old_ci; // [esp+Ch] [ebp-Ch]
  unsigned __int16 oldnCcalls; // [esp+10h] [ebp-8h]
  int old_errfunc; // [esp+14h] [ebp-4h]
  unsigned __int8 old_allowhooks_3; // [esp+23h] [ebp+Bh]

  oldnCcalls = L->nCcalls;
  errfunc = L->errfunc;
  old_ci = (char *)L->ci - (char *)L->base_ci;
  old_allowhooks_3 = L->allowhook;
  old_errfunc = errfunc;
  L->errfunc = ef;
  result = luaD_rawrunprotected(L, f: func, ud: u);
  v8 = result;
  if ( result != 0 )
  {
    v9 = (lua_TValue *)((char *)L->stack + old_top);
    luaF_close(L, level: v9);
    luaD_seterrorobj(L, errcode: v8, oldtop: v9);
    base_ci = L->base_ci;
    L->nCcalls = oldnCcalls;
    L->ci = (CallInfo *)((char *)base_ci + old_ci);
    L->base = *(lua_TValue **)((char *)&base_ci->base + old_ci);
    v11 = L->size_ci <= 20000;
    L->savedpc = *(const unsigned int **)((char *)&base_ci->savedpc + old_ci);
    L->allowhook = old_allowhooks_3;
    if ( v11 )
    {
      L->errfunc = old_errfunc;
      return v8;
    }
    else
    {
      if ( old_ci / 24 + 1 < 20000 )
        luaD_reallocCI(L, newsize: 20000);
      L->errfunc = old_errfunc;
      return v8;
    }
  }
  else
  {
    L->errfunc = errfunc;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00478220
// Name: int luaD_protectedparser(struct lua_State __near *,struct Zio __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaD_protectedparser(lua_State *L, Zio *z, const char *name)
{
  int errfunc; // edx
  int v4; // edi
  int v6; // [esp-8h] [ebp-24h]
  SParser p; // [esp+8h] [ebp-14h] BYREF

  errfunc = L->errfunc;
  p.z = z;
  v6 = (char *)L->top - (char *)L->stack;
  p.name = name;
  p.buff.buffer = nullptr;
  p.buff.buffsize = 0;
  v4 = luaD_pcall(L, func: (void (__cdecl *)(lua_State *, void *))f_parser, u: &p, old_top: v6, ef: errfunc);
  luaM_realloc_(L, block: p.buff.buffer, osize: p.buff.buffsize, nsize: 0);
  return v4;
}
