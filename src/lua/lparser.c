// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lparser.c
// Functions: 47
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00486420
// Name: errorlimit
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn errorlimit(FuncState *fs@<esi>, int limit@<edx>, const char *what@<ecx>)
{
  int linedefined; // eax
  const char *v4; // eax
  const char *v5; // eax

  linedefined = fs->f->linedefined;
  if ( linedefined == 0 )
  {
    v4 = luaO_pushfstring(L: (lua_TValue *)fs->L, fmt: "main function has more than %d %s", limit, what);
    luaX_lexerror(ls: fs->ls, msg: v4, token: 0);
  }
  v5 = luaO_pushfstring(
         L: (lua_TValue *)fs->L,
         fmt: "function at line %d has more than %d %s",
         linedefined,
         limit,
         what);
  luaX_lexerror(ls: fs->ls, msg: v5, token: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00486470
// Name: check_match
// Source: json
//------------------------------------------------------------------------------
void __usercall check_match(LexState *ls@<esi>, int what@<edi>, int where@<eax>, int who)
{
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // [esp-8h] [ebp-8h]

  if ( ls->t.token != what )
  {
    if ( where == ls->linenumber )
    {
      v4 = luaX_token2str(ls, token: what);
      v5 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v4);
      luaX_syntaxerror(ls, msg: v5);
    }
    v8 = luaX_token2str(ls, token: who);
    v6 = luaX_token2str(ls, token: what);
    v7 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected (to close '%s' at line %d)", v6, v8, where);
    luaX_syntaxerror(ls, msg: v7);
  }
  luaX_next(ls);
}

//------------------------------------------------------------------------------
// Address: 0x004864E0
// Name: codestring
// Source: json
//------------------------------------------------------------------------------
void __usercall codestring(LexState *ls@<ecx>, expdesc *e@<esi>, TString *s@<eax>)
{
  int v3; // eax

  v3 = luaK_stringK(fs: ls->fs, s);
  e->t = -1;
  e->f = -1;
  e->k = VK;
  e->u.s.info = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00486500
// Name: checkname
// Source: json
//------------------------------------------------------------------------------
void __usercall checkname(LexState *ls@<esi>, expdesc *e@<edi>)
{
  const char *v2; // eax
  const char *v3; // eax
  TString *ts; // ebx
  int v5; // eax

  if ( ls->t.token != 285 )
  {
    v2 = luaX_token2str(ls, token: 285);
    v3 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v2);
    luaX_syntaxerror(ls, msg: v3);
  }
  ts = ls->t.seminfo.ts;
  luaX_next(ls);
  v5 = luaK_stringK(fs: ls->fs, s: ts);
  e->t = -1;
  e->f = -1;
  e->k = VK;
  e->u.s.info = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00486560
// Name: registerlocalvar
// Source: json
//------------------------------------------------------------------------------
int __cdecl registerlocalvar(LexState *ls, GCObject *varname)
{
  FuncState *fs; // ecx
  GCObject *f; // edi
  int sizelocvars; // esi
  int *p_sizelocvars; // ebx
  void *v6; // eax
  int v7; // eax
  __int16 nlocvars; // dx
  FuncState *v10; // [esp+Ch] [ebp-4h]

  fs = ls->fs;
  f = (GCObject *)fs->f;
  sizelocvars = fs->f->sizelocvars;
  p_sizelocvars = &fs->f->sizelocvars;
  v10 = fs;
  if ( fs->nlocvars + 1 > sizelocvars )
  {
    v6 = luaM_growaux_(
           L: ls->L,
           block: f->cl.c.upvalue[0].value.gc,
           size: p_sizelocvars,
           size_elems: 0xCu,
           limit: 0x7FFF,
           errormsg: "too many local variables");
    fs = v10;
    f->cl.c.upvalue[0].value.b = (int)v6;
  }
  if ( sizelocvars < *p_sizelocvars )
  {
    v7 = 12 * sizelocvars;
    do
    {
      *(_DWORD *)(v7 + f->cl.c.upvalue[0].value.b) = 0;
      ++sizelocvars;
      v7 += 12;
    }
    while ( sizelocvars < *p_sizelocvars );
  }
  *(_DWORD *)(f->cl.c.upvalue[0].value.b + 12 * fs->nlocvars) = varname;
  if ( (varname->gch.marked & 3) != 0 && (f->gch.marked & 4) != 0 )
  {
    luaC_barrierf(L: ls->L, o: f, v: varname);
    fs = v10;
  }
  nlocvars = fs->nlocvars;
  fs->nlocvars = nlocvars + 1;
  return nlocvars;
}

//------------------------------------------------------------------------------
// Address: 0x00486610
// Name: new_localvar
// Source: json
//------------------------------------------------------------------------------
void __usercall new_localvar(int n@<edi>, LexState *ls, GCObject *name)
{
  FuncState *fs; // esi
  int linedefined; // eax
  const char *v5; // eax

  fs = ls->fs;
  if ( fs->nactvar + n + 1 > 200 )
  {
    linedefined = fs->f->linedefined;
    if ( linedefined != 0 )
      v5 = luaO_pushfstring(
             L: (lua_TValue *)fs->L,
             fmt: "function at line %d has more than %d %s",
             linedefined,
             200,
             "local variables");
    else
      v5 = luaO_pushfstring(L: (lua_TValue *)fs->L, fmt: "main function has more than %d %s", 200, "local variables");
    luaX_lexerror(ls: fs->ls, msg: v5, token: 0);
  }
  fs->actvar[n + fs->nactvar] = registerlocalvar(ls, varname: name);
}

//------------------------------------------------------------------------------
// Address: 0x004866A0
// Name: removevars
// Source: json
//------------------------------------------------------------------------------
void __usercall removevars(LexState *ls@<eax>, int tolevel@<edx>)
{
  FuncState *i; // eax

  for ( i = ls->fs; i->nactvar > tolevel; i->f->locvars[i->actvar[i->nactvar]].endpc = i->pc )
    --i->nactvar;
}

//------------------------------------------------------------------------------
// Address: 0x004866E0
// Name: indexupvalue
// Source: json
//------------------------------------------------------------------------------
int __usercall indexupvalue@<eax>(FuncState *fs@<edi>, GCObject *name, expdesc *v)
{
  GCObject *f; // esi
  int sizeupvalues; // ebx
  int result; // eax
  unsigned __int8 *p_info; // ecx
  int linedefined; // eax
  const char *v8; // eax
  unsigned __int8 nups; // cl

  f = (GCObject *)fs->f;
  sizeupvalues = fs->f->sizeupvalues;
  result = 0;
  if ( fs->f->nups != 0 )
  {
    p_info = &fs->upvalues[0].info;
    while ( *(p_info - 1) != v->k || *p_info != v->u.s.info )
    {
      ++result;
      p_info += 2;
      if ( result >= f->p.nups )
      {
        sizeupvalues = fs->f->sizeupvalues;
        goto LABEL_7;
      }
    }
  }
  else
  {
LABEL_7:
    if ( (unsigned int)f->p.nups + 1 > 0x3C )
    {
      linedefined = f->p.linedefined;
      if ( linedefined != 0 )
        v8 = luaO_pushfstring(
               L: (lua_TValue *)fs->L,
               fmt: "function at line %d has more than %d %s",
               linedefined,
               60,
               "upvalues");
      else
        v8 = luaO_pushfstring(L: (lua_TValue *)fs->L, fmt: "main function has more than %d %s", 60, "upvalues");
      luaX_lexerror(ls: fs->ls, msg: v8, token: 0);
    }
    if ( f->p.nups + 1 > f->p.sizeupvalues )
      f->h.sizearray = (int)luaM_growaux_(
                              L: fs->L,
                              block: f->p.upvalues,
                              size: &f->p.sizeupvalues,
                              size_elems: 4u,
                              limit: 2147483645,
                              errormsg: var);
    for ( ; sizeupvalues < f->p.sizeupvalues; ++sizeupvalues )
      *(_DWORD *)(f->h.sizearray + 4 * sizeupvalues) = 0;
    *(_DWORD *)(f->h.sizearray + 4 * f->p.nups) = name;
    if ( (name->gch.marked & 3) != 0 && (f->gch.marked & 4) != 0 )
      luaC_barrierf(L: fs->L, o: f, v: name);
    fs->upvalues[f->p.nups].k = v->k;
    fs->upvalues[f->p.nups].info = LOBYTE(v->u.nval);
    nups = f->p.nups;
    f->p.nups = nups + 1;
    return nups;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486820
// Name: singlevaraux
// Source: json
//------------------------------------------------------------------------------
int __cdecl singlevaraux(FuncState *fs, GCObject *n, expdesc *var, int base)
{
  int result; // eax
  int v5; // eax
  unsigned __int16 *v6; // edx
  BlockCnt *bl; // ecx

  if ( fs != nullptr )
  {
    v5 = fs->nactvar - 1;
    if ( fs->nactvar == 0 )
      goto LABEL_7;
    v6 = &fs->actvar[v5];
    while ( n != (GCObject *)fs->f->locvars[*v6].varname )
    {
      --v6;
      if ( --v5 < 0 )
        goto LABEL_7;
    }
    if ( v5 >= 0 )
    {
      var->t = -1;
      var->f = -1;
      var->k = VLOCAL;
      var->u.s.info = v5;
      if ( base == 0 )
      {
        bl = fs->bl;
        if ( bl != nullptr )
        {
          while ( bl->nactvar > v5 )
          {
            bl = bl->previous;
            if ( bl == nullptr )
              return 6;
          }
          bl->upval = 1;
        }
      }
      return 6;
    }
    else
    {
LABEL_7:
      result = singlevaraux(fs: fs->prev, (TString *)n, var, base: 0);
      if ( result != 8 )
      {
        var->u.s.info = indexupvalue(fs, name: n, v: var);
        var->k = VUPVAL;
        return 7;
      }
    }
  }
  else
  {
    var->t = -1;
    var->f = -1;
    var->k = VGLOBAL;
    var->u.s.info = 255;
    return 8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486900
// Name: singlevar
// Source: json
//------------------------------------------------------------------------------
void __usercall singlevar(LexState *ls@<eax>, expdesc *var)
{
  const char *v3; // eax
  const char *v4; // eax
  GCObject *ts; // edi
  FuncState *fs; // esi

  if ( ls->t.token != 285 )
  {
    v3 = luaX_token2str(ls, token: 285);
    v4 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v3);
    luaX_syntaxerror(ls, msg: v4);
  }
  ts = (GCObject *)ls->t.seminfo.ts;
  luaX_next(ls);
  fs = ls->fs;
  if ( singlevaraux(fs, n: ts, var, base: 1) == 8 )
    var->u.s.info = luaK_stringK(fs, s: (TString *)ts);
}

//------------------------------------------------------------------------------
// Address: 0x00486970
// Name: adjust_assign
// Source: json
//------------------------------------------------------------------------------
void __usercall adjust_assign(LexState *ls@<eax>, expdesc *e@<ecx>, int nvars, int nexps)
{
  int v4; // esi
  FuncState *fs; // edi
  expkind k; // eax
  int freereg; // ebx
  int v8; // esi

  v4 = nvars - nexps;
  fs = ls->fs;
  k = e->k;
  if ( e->k == VCALL || k == VVARARG )
  {
    v8 = v4 + 1;
    if ( v8 < 0 )
      v8 = 0;
    luaK_setreturns(fs, e, nresults: v8);
    if ( v8 > 1 )
      luaK_reserveregs(fs, n: v8 - 1);
  }
  else
  {
    if ( k != VVOID )
      luaK_exp2nextreg(fs, e);
    if ( v4 > 0 )
    {
      freereg = fs->freereg;
      luaK_reserveregs(fs, n: v4);
      luaK_nil(fs, from: freereg, n: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004869E0
// Name: pushclosure
// Source: json
//------------------------------------------------------------------------------
void __cdecl pushclosure(LexState *ls, FuncState *func, expdesc *v)
{
  FuncState *fs; // esi
  GCObject *f; // ebx
  int *p_sizep; // eax
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  upvaldesc *upvalues; // edi

  fs = ls->fs;
  f = (GCObject *)fs->f;
  p_sizep = &fs->f->sizep;
  v6 = *p_sizep;
  if ( fs->np + 1 > *p_sizep )
    f->u.uv.len = (unsigned int)luaM_growaux_(
                                  L: ls->L,
                                  block: f->cl.c.f,
                                  size: p_sizep,
                                  size_elems: 4u,
                                  limit: 0x3FFFF,
                                  errormsg: "constant table overflow");
  for ( ; v6 < f->p.sizep; ++v6 )
    *(_DWORD *)(f->u.uv.len + 4 * v6) = 0;
  *(_DWORD *)(f->u.uv.len + 4 * fs->np++) = func->f;
  if ( (func->f->marked & 3) != 0 && (f->gch.marked & 4) != 0 )
    luaC_barrierf(L: ls->L, o: f, v: (GCObject *)func->f);
  v7 = luaK_codeABx(fs, o: OP_CLOSURE, a: 0, bc: fs->np - 1);
  v->t = -1;
  v->f = -1;
  v->k = VRELOCABLE;
  v->u.s.info = v7;
  v8 = 0;
  if ( func->f->nups != 0 )
  {
    upvalues = func->upvalues;
    do
    {
      luaK_codeABC(fs, o: upvalues->k == 6 ? OP_MOVE : OP_GETUPVAL, a: 0, b: upvalues->info, c: 0);
      ++v8;
      ++upvalues;
    }
    while ( v8 < func->f->nups );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486AD0
// Name: open_func
// Source: json
//------------------------------------------------------------------------------
void __usercall open_func(FuncState *fs@<eax>, Proto *ls)
{
  lua_State *sizep; // edi
  GCObject *v5; // eax
  GCObject *v6; // eax
  _DWORD *p_b; // ecx
  _DWORD *v8; // eax
  Proto *f; // [esp+14h] [ebp+8h]

  sizep = (lua_State *)ls->sizep;
  v5 = luaF_newproto(L: sizep);
  fs->f = (Proto *)v5;
  fs->prev = (FuncState *)ls->sizelineinfo;
  fs->ls = (LexState *)ls;
  fs->L = sizep;
  ls->sizelineinfo = (int)fs;
  fs->lasttarget = -1;
  fs->jpc = -1;
  fs->pc = 0;
  fs->freereg = 0;
  fs->nk = 0;
  fs->np = 0;
  fs->nlocvars = 0;
  fs->nactvar = 0;
  fs->bl = nullptr;
  f = (Proto *)v5;
  v5->cl.c.upvalue[0].tt = ls->lastlinedefined;
  v5->p.maxstacksize = 2;
  v6 = luaH_new(L: sizep, narray: 0, nhash: 0);
  fs->h = (Table *)v6;
  p_b = &sizep->top->value.b;
  *p_b = v6;
  p_b[2] = 5;
  if ( (char *)sizep->stack_last - (char *)sizep->top <= 16 )
    luaD_growstack(L: sizep, n: 1);
  ++sizep->top;
  v8 = &sizep->top->value.b;
  *v8 = f;
  v8[2] = 9;
  if ( (char *)sizep->stack_last - (char *)sizep->top <= 16 )
    luaD_growstack(L: sizep, n: 1);
  ++sizep->top;
}

//------------------------------------------------------------------------------
// Address: 0x00486B90
// Name: close_func
// Source: json
//------------------------------------------------------------------------------
void __cdecl close_func(LexState *ls)
{
  lua_State *L; // ebx
  FuncState *fs; // edi
  Proto *f; // esi
  int v4; // edx
  int pc; // eax
  int nk; // eax
  int np; // eax
  int nlocvars; // eax
  int nups; // eax
  TString **v10; // eax
  int v11; // edx
  int token; // ecx

  L = ls->L;
  fs = ls->fs;
  f = fs->f;
  removevars(ls, tolevel: 0);
  luaK_ret(fs, first: v4, nret: v4);
  pc = fs->pc;
  if ( (unsigned int)(pc + 1) > 0x3FFFFFFF )
    luaM_toobig(L);
  f->code = (unsigned int *)luaM_realloc_(L, block: f->code, osize: 4 * f->sizecode, nsize: 4 * pc);
  f->sizecode = fs->pc;
  if ( (unsigned int)(fs->pc + 1) > 0x3FFFFFFF )
    luaM_toobig(L);
  f->lineinfo = (int *)luaM_realloc_(L, block: f->lineinfo, osize: 4 * f->sizelineinfo, nsize: 4 * fs->pc);
  f->sizelineinfo = fs->pc;
  nk = fs->nk;
  if ( (unsigned int)(nk + 1) > 0xFFFFFFF )
    luaM_toobig(L);
  f->k = (lua_TValue *)luaM_realloc_(L, block: f->k, osize: 16 * f->sizek, nsize: 16 * nk);
  f->sizek = fs->nk;
  np = fs->np;
  if ( (unsigned int)(np + 1) > 0x3FFFFFFF )
    luaM_toobig(L);
  f->p = (Proto **)luaM_realloc_(L, block: f->p, osize: 4 * f->sizep, nsize: 4 * np);
  f->sizep = fs->np;
  nlocvars = fs->nlocvars;
  if ( (unsigned int)(nlocvars + 1) > 0x15555555 )
    luaM_toobig(L);
  f->locvars = (LocVar *)luaM_realloc_(L, block: f->locvars, osize: 12 * f->sizelocvars, nsize: 12 * nlocvars);
  nups = f->nups;
  f->sizelocvars = fs->nlocvars;
  if ( (unsigned int)(nups + 1) > 0x3FFFFFFF )
    luaM_toobig(L);
  v10 = (TString **)luaM_realloc_(L, block: f->upvalues, osize: 4 * f->sizeupvalues, nsize: 4 * nups);
  v11 = f->nups;
  f->upvalues = v10;
  f->sizeupvalues = v11;
  ls->fs = fs->prev;
  L->top -= 2;
  token = ls->t.token;
  if ( token == 285 || token == 286 )
    luaX_newstring(ls, str: (char *)&ls->t.seminfo.ts[1], l: ls->t.seminfo.ts->tsv.len);
}

//------------------------------------------------------------------------------
// Address: 0x00486D70
// Name: field
// Source: json
//------------------------------------------------------------------------------
void __usercall field(LexState *ls@<esi>, expdesc *v)
{
  FuncState *fs; // edi
  const char *v3; // eax
  const char *v4; // eax
  TString *ts; // ebx
  expdesc key; // [esp+8h] [ebp-18h] BYREF

  fs = ls->fs;
  luaK_exp2anyreg(fs, e: v);
  luaX_next(ls);
  if ( ls->t.token != 285 )
  {
    v3 = luaX_token2str(ls, token: 285);
    v4 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v3);
    luaX_syntaxerror(ls, msg: v4);
  }
  ts = ls->t.seminfo.ts;
  luaX_next(ls);
  key.u.s.info = luaK_stringK(fs: ls->fs, s: ts);
  key.t = -1;
  key.f = -1;
  key.k = VK;
  luaK_indexed(fs, t: v, k: &key);
}

//------------------------------------------------------------------------------
// Address: 0x00486E00
// Name: recfield
// Source: json
//------------------------------------------------------------------------------
void __cdecl recfield(LexState *ls, ConsControl *cc)
{
  bool v3; // zf
  FuncState *v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // edi
  int v10; // eax
  expdesc val; // [esp+Ch] [ebp-34h] BYREF
  expdesc key; // [esp+24h] [ebp-1Ch] BYREF
  int reg; // [esp+3Ch] [ebp-4h]
  FuncState *lsa; // [esp+48h] [ebp+8h]

  v3 = ls->t.token == 285;
  lsa = ls->fs;
  v4 = lsa;
  reg = lsa->freereg;
  if ( v3 )
  {
    if ( cc->nh > 2147483645 )
      errorlimit(fs: lsa, limit: 2147483645, what: "items in a constructor");
    checkname(ls, e: &key);
    v4 = lsa;
  }
  else
  {
    luaX_next(ls);
    subexpr(ls, v: &key, limit: 0);
    luaK_exp2val(fs: ls->fs, e: &key);
    if ( ls->t.token != 93 )
    {
      v5 = luaX_token2str(ls, token: 93);
      v6 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v5);
      luaX_syntaxerror(ls, msg: v6);
    }
    luaX_next(ls);
  }
  ++cc->nh;
  if ( ls->t.token != 61 )
  {
    v7 = luaX_token2str(ls, token: 61);
    v8 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v7);
    luaX_syntaxerror(ls, msg: v8);
  }
  luaX_next(ls);
  v9 = luaK_exp2RK(fs: v4, e: &key);
  subexpr(ls, v: &val, limit: 0);
  v10 = luaK_exp2RK(fs: v4, e: &val);
  luaK_codeABC(fs: v4, o: OP_SETTABLE, a: cc->t->u.s.info, b: v9, c: v10);
  v4->freereg = reg;
}

//------------------------------------------------------------------------------
// Address: 0x00486F20
// Name: lastlistfield
// Source: json
//------------------------------------------------------------------------------
void __usercall lastlistfield(FuncState *fs@<edi>, ConsControl *cc@<esi>)
{
  expkind k; // eax

  if ( cc->tostore != 0 )
  {
    k = cc->v.k;
    if ( cc->v.k == VCALL || k == VVARARG )
    {
      luaK_setreturns(fs, e: &cc->v, nresults: -1);
      luaK_setlist(fs, base: cc->t->u.s.info, nelems: cc->na, tostore: -1);
      --cc->na;
    }
    else
    {
      if ( k != VVOID )
        luaK_exp2nextreg(fs, e: &cc->v);
      luaK_setlist(fs, base: cc->t->u.s.info, nelems: cc->na, tostore: cc->tostore);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486F80
// Name: listfield
// Source: json
//------------------------------------------------------------------------------
void __usercall listfield(LexState *ls@<eax>, ConsControl *cc@<edi>)
{
  FuncState *fs; // esi
  int linedefined; // eax
  const char *v5; // eax

  subexpr(ls, v: &cc->v, limit: 0);
  if ( cc->na > 0x3FFFF )
  {
    fs = ls->fs;
    linedefined = fs->f->linedefined;
    if ( linedefined != 0 )
      v5 = luaO_pushfstring(
             L: (lua_TValue *)fs->L,
             fmt: "function at line %d has more than %d %s",
             linedefined,
             0x3FFFF,
             "items in a constructor");
    else
      v5 = luaO_pushfstring(
             L: (lua_TValue *)fs->L,
             fmt: "main function has more than %d %s",
             0x3FFFF,
             "items in a constructor");
    luaX_lexerror(ls: fs->ls, msg: v5, token: 0);
  }
  ++cc->na;
  ++cc->tostore;
}

//------------------------------------------------------------------------------
// Address: 0x00486FF0
// Name: constructor
// Source: json
//------------------------------------------------------------------------------
void __usercall constructor(LexState *ls@<ecx>, expdesc *t@<eax>)
{
  FuncState *fs; // ebx
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int token; // eax
  FuncState *v9; // edi
  int linedefined; // eax
  const char *v11; // eax
  int v12; // eax
  int v13; // edi
  unsigned int *v14; // esi
  unsigned int *v15; // esi
  FuncState *v16; // [esp-1Ch] [ebp-58h]
  ConsControl cc; // [esp+Ch] [ebp-30h] BYREF
  int pc; // [esp+34h] [ebp-8h]
  int line; // [esp+38h] [ebp-4h]

  fs = ls->fs;
  line = ls->linenumber;
  v5 = luaK_codeABC(fs, o: OP_NEWTABLE, a: 0, b: 0, c: 0);
  memset(&cc.nh, 0, 12);
  t->t = -1;
  t->f = -1;
  t->k = VRELOCABLE;
  t->u.s.info = v5;
  cc.v.k = VVOID;
  cc.v.u.s.info = 0;
  v16 = ls->fs;
  pc = v5;
  cc.t = t;
  cc.v.t = -1;
  cc.v.f = -1;
  luaK_exp2nextreg(fs: v16, e: t);
  if ( ls->t.token != 123 )
  {
    v6 = luaX_token2str(ls, token: 123);
    v7 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v6);
    luaX_syntaxerror(ls, msg: v7);
  }
  do
  {
    luaX_next(ls);
    if ( ls->t.token == 125 )
      break;
    if ( cc.v.k != VVOID )
    {
      luaK_exp2nextreg(fs, e: &cc.v);
      cc.v.k = VVOID;
      if ( cc.tostore == 50 )
      {
        luaK_setlist(fs, base: cc.t->u.s.info, nelems: cc.na, tostore: 50);
        cc.tostore = 0;
      }
    }
    token = ls->t.token;
    if ( token == 91 )
      goto LABEL_17;
    if ( token != 285 )
    {
      subexpr(ls, v: &cc.v, limit: 0);
      if ( cc.na > 0x3FFFF )
      {
        v9 = ls->fs;
        linedefined = v9->f->linedefined;
        if ( linedefined != 0 )
          v11 = luaO_pushfstring(
                  L: (lua_TValue *)v9->L,
                  fmt: "function at line %d has more than %d %s",
                  linedefined,
                  0x3FFFF,
                  "items in a constructor");
        else
          v11 = luaO_pushfstring(
                  L: (lua_TValue *)v9->L,
                  fmt: "main function has more than %d %s",
                  0x3FFFF,
                  "items in a constructor");
        luaX_lexerror(ls: v9->ls, msg: v11, token: 0);
      }
      ++cc.na;
      ++cc.tostore;
      goto LABEL_18;
    }
    luaX_lookahead(ls);
    if ( ls->lookahead.token == 61 )
LABEL_17:
      recfield(ls, &cc);
    else
      listfield(ls, &cc);
LABEL_18:
    v12 = ls->t.token;
  }
  while ( v12 == 44 || v12 == 59 );
  check_match(ls, what: 125, where: line, who: 123);
  lastlistfield(fs, &cc);
  v13 = pc;
  v14 = &fs->f->code[pc];
  *v14 = *v14 & 0x7FFFFF | (luaO_int2fb(x: cc.na) << 23);
  v15 = &fs->f->code[v13];
  *v15 ^= (*v15 ^ (luaO_int2fb(x: cc.nh) << 14)) & 0x7FC000;
}

//------------------------------------------------------------------------------
// Address: 0x004871F0
// Name: parlist
// Source: json
//------------------------------------------------------------------------------
void __usercall parlist(LexState *ls@<eax>)
{
  FuncState *fs; // eax
  Proto *v3; // edi
  int v4; // ebx
  GCObject *ts; // edi
  GCObject *v6; // eax
  FuncState *v7; // esi
  int v8; // ecx
  FuncState *v9; // [esp+Ch] [ebp-8h]
  Proto *f; // [esp+10h] [ebp-4h]

  fs = ls->fs;
  v3 = fs->f;
  v4 = 0;
  v3->is_vararg = 0;
  v9 = fs;
  f = v3;
  if ( ls->t.token != 41 )
  {
    while ( ls->t.token != 279 )
    {
      if ( ls->t.token != 285 )
        luaX_syntaxerror(ls, msg: "<name> or '...' expected");
      ts = (GCObject *)ls->t.seminfo.ts;
      luaX_next(ls);
      new_localvar(n: v4, ls, name: ts);
      v3 = f;
      ++v4;
      if ( f->is_vararg != 0 || ls->t.token != 44 )
        goto LABEL_9;
      luaX_next(ls);
    }
    luaX_next(ls);
    v6 = luaX_newstring(ls, str: "arg", l: 3u);
    new_localvar(n: v4++, ls, name: v6);
    f->is_vararg = 7;
    v3 = f;
LABEL_9:
    fs = v9;
  }
  v7 = ls->fs;
  v7->nactvar += v4;
  if ( v4 != 0 )
  {
    do
    {
      v8 = v7->nactvar - v4--;
      v7->f->locvars[v7->actvar[v8]].startpc = v7->pc;
    }
    while ( v4 != 0 );
    fs = v9;
  }
  v3->numparams = fs->nactvar - (v3->is_vararg & 1);
  luaK_reserveregs(fs, n: fs->nactvar);
}

//------------------------------------------------------------------------------
// Address: 0x004872E0
// Name: body
// Source: json
//------------------------------------------------------------------------------
void __usercall body(Proto *ls@<eax>, expdesc *e, int needself, int line)
{
  const char *v5; // eax
  const char *v6; // eax
  GCObject *v7; // eax
  FuncState *sizelineinfo; // eax
  const char *v9; // eax
  const char *v10; // eax
  FuncState new_fs; // [esp+Ch] [ebp-23Ch] BYREF

  open_func(fs: &new_fs, ls);
  new_fs.f->linedefined = line;
  if ( ls->p != (Proto **)40 )
  {
    v5 = luaX_token2str((LexState *)ls, token: 40);
    v6 = luaO_pushfstring(L: (lua_TValue *)ls->sizep, fmt: "'%s' expected", v5);
    luaX_syntaxerror((LexState *)ls, msg: v6);
  }
  luaX_next((LexState *)ls);
  if ( needself != 0 )
  {
    v7 = luaX_newstring((LexState *)ls, str: "self", l: 4u);
    new_localvar(n: 0, (LexState *)ls, name: v7);
    sizelineinfo = (FuncState *)ls->sizelineinfo;
    sizelineinfo->f->locvars[*(unsigned __int16 *)&sizelineinfo->upvalues[++sizelineinfo->nactvar + 59].info].startpc = sizelineinfo->pc;
  }
  parlist((LexState *)ls);
  if ( ls->p != (Proto **)41 )
  {
    v9 = luaX_token2str((LexState *)ls, token: 41);
    v10 = luaO_pushfstring(L: (lua_TValue *)ls->sizep, fmt: "'%s' expected", v9);
    luaX_syntaxerror((LexState *)ls, msg: v10);
  }
  luaX_next((LexState *)ls);
  chunk((LexState *)ls);
  new_fs.f->lastlinedefined = *(_DWORD *)&ls->tt;
  check_match((LexState *)ls, what: 262, where: line, who: 265);
  close_func((LexState *)ls);
  pushclosure((LexState *)ls, func: &new_fs, v: e);
}

//------------------------------------------------------------------------------
// Address: 0x00487400
// Name: explist1
// Source: json
//------------------------------------------------------------------------------
int __usercall explist1@<eax>(LexState *ls@<esi>, expdesc *v@<edi>)
{
  int v2; // ebx

  v2 = 1;
  subexpr(ls, v, limit: 0);
  while ( ls->t.token == 44 )
  {
    luaX_next(ls);
    luaK_exp2nextreg(fs: ls->fs, e: v);
    subexpr(ls, v, limit: 0);
    ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00487440
// Name: funcargs
// Source: json
//------------------------------------------------------------------------------
void __usercall funcargs(LexState *ls@<eax>, expdesc *f)
{
  int token; // eax
  FuncState *fs; // ebx
  int linenumber; // edi
  int v6; // eax
  int info; // edi
  int v8; // eax
  int v9; // eax
  int v10; // [esp-18h] [ebp-40h]
  expdesc args; // [esp+Ch] [ebp-1Ch] BYREF
  int line; // [esp+24h] [ebp-4h]

  token = ls->t.token;
  fs = ls->fs;
  linenumber = ls->linenumber;
  line = linenumber;
  switch ( token )
  {
    case 40:
      if ( linenumber != ls->lastline )
        luaX_syntaxerror(ls, msg: "ambiguous syntax (function call x new statement)");
      luaX_next(ls);
      if ( ls->t.token == 41 )
      {
        args.k = VVOID;
      }
      else
      {
        explist1(ls, v: &args);
        luaK_setreturns(fs, e: &args, nresults: -1);
        linenumber = line;
      }
      check_match(ls, what: 41, where: linenumber, who: 40);
      break;
    case 123:
      constructor(ls, t: &args);
      break;
    case 286:
      v6 = luaK_stringK(fs, s: ls->t.seminfo.ts);
      args.t = -1;
      args.f = -1;
      args.k = VK;
      args.u.s.info = v6;
      luaX_next(ls);
      break;
    default:
      luaX_syntaxerror(ls, msg: "function arguments expected");
  }
  info = f->u.s.info;
  if ( args.k == VCALL || args.k == VVARARG )
  {
    v8 = -1;
  }
  else
  {
    if ( args.k != VVOID )
      luaK_exp2nextreg(fs, e: &args);
    v8 = fs->freereg - info - 1;
  }
  v9 = luaK_codeABC(fs, o: OP_CALL, a: info, b: v8 + 1, c: 2);
  v10 = line;
  f->t = -1;
  f->f = -1;
  f->k = VCALL;
  f->u.s.info = v9;
  luaK_fixline(fs, line: v10);
  fs->freereg = info + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00487570
// Name: prefixexp
// Source: json
//------------------------------------------------------------------------------
void __usercall prefixexp(LexState *ls@<eax>, expdesc *v)
{
  int token; // eax
  int linenumber; // edi

  token = ls->t.token;
  if ( token == 40 )
  {
    linenumber = ls->linenumber;
    luaX_next(ls);
    subexpr(ls, v, limit: 0);
    check_match(ls, what: 41, where: linenumber, who: 40);
    luaK_dischargevars(fs: ls->fs, e: v);
  }
  else
  {
    if ( token != 285 )
      luaX_syntaxerror(ls, msg: "unexpected symbol");
    singlevar(ls, var: v);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004875E0
// Name: primaryexp
// Source: json
//------------------------------------------------------------------------------
void __usercall primaryexp(LexState *ls@<eax>, expdesc *v@<edi>)
{
  FuncState *fs; // ebx
  unsigned int v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  TString *ts; // ebx
  expdesc *v10; // [esp+0h] [ebp-28h]
  expdesc key; // [esp+Ch] [ebp-1Ch] BYREF
  FuncState *v12; // [esp+24h] [ebp-4h]

  fs = ls->fs;
  v12 = fs;
  prefixexp(ls, v: v10);
  v4 = ls->t.token - 40;
  while ( 2 )
  {
    switch ( v4 )
    {
      case 0u:
      case 0x53u:
      case 0xF6u:
        luaK_exp2nextreg(fs, e: v);
        funcargs(ls, f: v);
        goto LABEL_11;
      case 6u:
        field(ls, v);
        goto LABEL_11;
      case 0x12u:
        luaX_next(ls);
        if ( ls->t.token != 285 )
        {
          v7 = luaX_token2str(ls, token: 285);
          v8 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v7);
          luaX_syntaxerror(ls, msg: v8);
        }
        ts = ls->t.seminfo.ts;
        luaX_next(ls);
        key.u.s.info = luaK_stringK(fs: ls->fs, s: ts);
        key.t = -1;
        key.f = -1;
        key.k = VK;
        luaK_self(fs: v12, e: v, &key);
        funcargs(ls, f: v);
        fs = v12;
        goto LABEL_11;
      case 0x33u:
        luaK_exp2anyreg(fs, e: v);
        luaX_next(ls);
        subexpr(ls, v: &key, limit: 0);
        luaK_exp2val(fs: ls->fs, e: &key);
        if ( ls->t.token != 93 )
        {
          v5 = luaX_token2str(ls, token: 93);
          v6 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v5);
          luaX_syntaxerror(ls, msg: v6);
        }
        luaX_next(ls);
        luaK_indexed(fs, t: v, k: &key);
LABEL_11:
        v4 = ls->t.token - 40;
        if ( v4 > 0xF6 )
          return;
        continue;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487850
// Name: simpleexp
// Source: json
//------------------------------------------------------------------------------
void __usercall simpleexp(expdesc *v@<eax>, LexState *ls)
{
  FuncState *fs; // edi
  int v4; // eax

  switch ( ls->t.token )
  {
    case 0x7B:
      constructor(ls, t: v);
      return;
    case 0x107:
      v->k = VFALSE;
      v->u.s.info = 0;
      goto LABEL_10;
    case 0x109:
      luaX_next(ls);
      body((Proto *)ls, e: v, needself: 0, line: ls->linenumber);
      return;
    case 0x10D:
      v->k = VNIL;
      v->u.s.info = 0;
      goto LABEL_10;
    case 0x113:
      v->k = VTRUE;
      v->u.s.info = 0;
      goto LABEL_10;
    case 0x117:
      fs = ls->fs;
      if ( fs->f->is_vararg == 0 )
        luaX_syntaxerror(ls, msg: "cannot use '...' outside a vararg function");
      fs->f->is_vararg &= ~4u;
      v4 = luaK_codeABC(fs, o: OP_VARARG, a: 0, b: 1, c: 0);
      v->k = VVARARG;
      v->u.s.info = v4;
LABEL_10:
      v->f = -1;
      v->t = -1;
      luaX_next(ls);
      break;
    case 0x11C:
      v->u.s.info = 0;
      v->t = -1;
      v->f = -1;
      v->k = VKNUM;
      v->u.nval = ls->t.seminfo.r;
      luaX_next(ls);
      break;
    case 0x11E:
      codestring(ls, e: v, s: ls->t.seminfo.ts);
      luaX_next(ls);
      break;
    default:
      primaryexp(ls, v);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487A40
// Name: getbinopr
// Source: json
//------------------------------------------------------------------------------
BinOpr __usercall getbinopr@<eax>(int op@<eax>)
{
  BinOpr result; // eax

  switch ( op )
  {
    case 37:
      result = OPR_MOD;
      break;
    case 42:
      result = OPR_MUL;
      break;
    case 43:
      result = OPR_ADD;
      break;
    case 45:
      result = OPR_SUB;
      break;
    case 47:
      result = OPR_DIV;
      break;
    case 60:
      result = OPR_LT;
      break;
    case 62:
      result = OPR_GT;
      break;
    case 94:
      result = OPR_POW;
      break;
    case 257:
      result = OPR_AND;
      break;
    case 271:
      result = OPR_OR;
      break;
    case 278:
      result = OPR_CONCAT;
      break;
    case 280:
      result = OPR_EQ;
      break;
    case 281:
      result = OPR_GE;
      break;
    case 282:
      result = OPR_LE;
      break;
    case 283:
      result = OPR_NE;
      break;
    default:
      result = OPR_NOBINOPR;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00487BF0
// Name: subexpr
// Source: json
//------------------------------------------------------------------------------
BinOpr __cdecl subexpr(LexState *ls, expdesc *v, unsigned int limit)
{
  lua_State *L; // eax
  UnOpr v4; // edi
  int token; // eax
  BinOpr v6; // edi
  BinOpr v7; // ebx
  expdesc v2; // [esp+Ch] [ebp-18h] BYREF

  L = ls->L;
  v4 = OPR_NOT;
  if ( ++L->nCcalls > 0xC8u )
    luaX_lexerror(ls, msg: "chunk has too many syntax levels", token: 0);
  token = ls->t.token;
  switch ( token )
  {
    case 35:
      v4 = OPR_LEN;
      break;
    case 45:
      v4 = OPR_MINUS;
      break;
    case 270:
      break;
    default:
      simpleexp(v, ls);
      goto LABEL_7;
  }
  luaX_next(ls);
  subexpr(ls, v, limit: 8u);
  luaK_prefix(fs: ls->fs, op: v4, e: v);
LABEL_7:
  v6 = getbinopr(op: ls->t.token);
  if ( v6 != OPR_NOBINOPR )
  {
    do
    {
      if ( priority[v6].left <= limit )
        break;
      luaX_next(ls);
      luaK_infix(fs: ls->fs, op: v6, v);
      v7 = subexpr(ls, v: &v2, limit: priority[v6].right);
      luaK_posfix(fs: ls->fs, op: v6, e1: v, e2: &v2);
      v6 = v7;
    }
    while ( v7 != OPR_NOBINOPR );
  }
  --ls->L->nCcalls;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00487D00
// Name: block
// Source: json
//------------------------------------------------------------------------------
void __usercall block(LexState *ls@<eax>)
{
  FuncState *fs; // esi
  BlockCnt *bl; // edi
  LexState *v3; // eax
  BlockCnt v4; // [esp+8h] [ebp-Ch] BYREF

  fs = ls->fs;
  v4.breaklist = -1;
  v4.isbreakable = 0;
  v4.nactvar = fs->nactvar;
  v4.upval = 0;
  v4.previous = fs->bl;
  fs->bl = &v4;
  chunk(ls);
  bl = fs->bl;
  v3 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v3, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_codeABC(fs, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
  fs->freereg = fs->nactvar;
  luaK_patchtohere(fs, list: bl->breaklist);
}

//------------------------------------------------------------------------------
// Address: 0x00487D80
// Name: check_conflict
// Source: json
//------------------------------------------------------------------------------
void __usercall check_conflict(LexState *ls@<ecx>, LHS_assign *lh@<eax>, expdesc *v@<edi>)
{
  FuncState *fs; // esi
  int freereg; // edx
  int v5; // ecx

  fs = ls->fs;
  freereg = fs->freereg;
  v5 = 0;
  if ( lh != nullptr )
  {
    do
    {
      if ( lh->v.k == VINDEXED )
      {
        if ( lh->v.u.s.info == v->u.s.info )
        {
          v5 = 1;
          lh->v.u.s.info = freereg;
        }
        if ( lh->v.u.s.aux == v->u.s.info )
        {
          v5 = 1;
          lh->v.u.s.aux = freereg;
        }
      }
      lh = lh->prev;
    }
    while ( lh != nullptr );
    if ( v5 != 0 )
    {
      luaK_codeABC(fs, o: OP_MOVE, a: fs->freereg, b: v->u.s.info, c: 0);
      luaK_reserveregs(fs, n: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487DE0
// Name: assignment
// Source: json
//------------------------------------------------------------------------------
void __cdecl assignment(LexState *ls, LHS_assign *lh, int nvars)
{
  int token; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // ebx
  FuncState *fs; // esi
  LHS_assign nv; // [esp+Ch] [ebp-38h] BYREF
  expdesc e; // [esp+2Ch] [ebp-18h] BYREF
  expdesc *lha; // [esp+50h] [ebp+Ch]

  lha = &lh->v;
  if ( lha->k < VLOCAL || lha->k > VINDEXED )
    luaX_syntaxerror(ls, msg: "syntax error");
  token = ls->t.token;
  if ( token == 44 )
  {
    luaX_next(ls);
    nv.prev = lh;
    primaryexp(ls, v: &nv.v);
    if ( nv.v.k == VLOCAL )
      check_conflict(ls, lh, v: &nv.v);
    assignment(ls, lh: &nv, nvars: nvars + 1);
LABEL_13:
    fs = ls->fs;
    e.u.s.info = fs->freereg - 1;
    e.t = -1;
    e.f = -1;
    e.k = VNONRELOC;
    luaK_storevar(fs, var: lha, ex: &e);
    return;
  }
  if ( token != 61 )
  {
    v5 = luaX_token2str(ls, token: 61);
    v6 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v5);
    luaX_syntaxerror(ls, msg: v6);
  }
  luaX_next(ls);
  v7 = explist1(ls, v: &e);
  v8 = v7;
  if ( v7 != nvars )
  {
    adjust_assign(ls, &e, nvars, nexps: v7);
    if ( v8 > nvars )
      ls->fs->freereg += nvars - v8;
    goto LABEL_13;
  }
  luaK_setoneret(fs: ls->fs, &e);
  luaK_storevar(fs: ls->fs, var: lha, ex: &e);
}

//------------------------------------------------------------------------------
// Address: 0x00487F10
// Name: breakstat
// Source: json
//------------------------------------------------------------------------------
void __usercall breakstat(LexState *ls@<eax>)
{
  FuncState *fs; // ebx
  BlockCnt *bl; // esi
  int v3; // edi
  int upval; // ecx
  int v5; // eax

  fs = ls->fs;
  bl = fs->bl;
  v3 = 0;
  if ( bl == nullptr )
LABEL_4:
    luaX_syntaxerror(ls, msg: "no loop to break");
  while ( bl->isbreakable == 0 )
  {
    upval = bl->upval;
    bl = bl->previous;
    v3 |= upval;
    if ( bl == nullptr )
      goto LABEL_4;
  }
  if ( v3 != 0 )
    luaK_codeABC(fs, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
  v5 = luaK_jump(fs);
  luaK_concat(fs, l1: &bl->breaklist, l2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00487F70
// Name: whilestat
// Source: json
//------------------------------------------------------------------------------
void __usercall whilestat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // ebx
  int v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  BlockCnt *bl; // esi
  LexState *v9; // eax
  expdesc v; // [esp+Ch] [ebp-24h] BYREF
  BlockCnt v11; // [esp+24h] [ebp-Ch] BYREF

  fs = ls->fs;
  luaX_next(ls);
  v4 = luaK_getlabel(fs);
  subexpr(ls, &v, limit: 0);
  if ( v.k == VNIL )
    v.k = VFALSE;
  luaK_goiftrue(fs: ls->fs, e: &v);
  v11.breaklist = -1;
  v11.isbreakable = 1;
  v11.nactvar = fs->nactvar;
  v11.upval = 0;
  v11.previous = fs->bl;
  fs->bl = &v11;
  if ( ls->t.token != 259 )
  {
    v5 = luaX_token2str(ls, token: 259);
    v6 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v5);
    luaX_syntaxerror(ls, msg: v6);
  }
  luaX_next(ls);
  block(ls);
  v7 = luaK_jump(fs);
  luaK_patchlist(fs, list: v7, target: v4);
  check_match(ls, what: 262, where: line, who: 277);
  bl = fs->bl;
  v9 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v9, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_codeABC(fs, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
  fs->freereg = fs->nactvar;
  luaK_patchtohere(fs, list: bl->breaklist);
  luaK_patchtohere(fs, list: v.f);
}

//------------------------------------------------------------------------------
// Address: 0x00488090
// Name: repeatstat
// Source: json
//------------------------------------------------------------------------------
void __usercall repeatstat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // ebx
  BlockCnt *v4; // edi
  LexState *v5; // eax
  BlockCnt *bl; // edi
  LexState *v7; // eax
  int v8; // eax
  BlockCnt *v9; // esi
  LexState *v10; // eax
  int v11; // [esp-4h] [ebp-44h]
  expdesc v; // [esp+Ch] [ebp-34h] BYREF
  BlockCnt bl1; // [esp+24h] [ebp-1Ch] BYREF
  BlockCnt bl2; // [esp+30h] [ebp-10h] BYREF
  int repeat_init; // [esp+3Ch] [ebp-4h]

  fs = ls->fs;
  bl1.isbreakable = 1;
  repeat_init = luaK_getlabel(fs);
  bl1.breaklist = -1;
  bl1.nactvar = fs->nactvar;
  bl1.upval = 0;
  bl1.previous = fs->bl;
  fs->bl = &bl1;
  bl2.breaklist = -1;
  bl2.isbreakable = 0;
  bl2.nactvar = fs->nactvar;
  bl2.upval = 0;
  bl2.previous = fs->bl;
  fs->bl = &bl2;
  luaX_next(ls);
  chunk(ls);
  check_match(ls, what: 276, where: line, who: 272);
  subexpr(ls, &v, limit: 0);
  if ( v.k == VNIL )
    v.k = VFALSE;
  luaK_goiftrue(fs: ls->fs, e: &v);
  if ( bl2.upval != 0 )
  {
    breakstat(ls);
    luaK_patchtohere(fs: ls->fs, list: v.f);
    bl = fs->bl;
    v7 = fs->ls;
    fs->bl = bl->previous;
    removevars(ls: v7, tolevel: bl->nactvar);
    if ( bl->upval != 0 )
      luaK_codeABC(fs, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
    fs->freereg = fs->nactvar;
    luaK_patchtohere(fs, list: bl->breaklist);
    v11 = repeat_init;
    v8 = luaK_jump(fs);
    luaK_patchlist(fs: ls->fs, list: v8, target: v11);
  }
  else
  {
    v4 = fs->bl;
    v5 = fs->ls;
    fs->bl = v4->previous;
    removevars(ls: v5, tolevel: v4->nactvar);
    if ( v4->upval != 0 )
      luaK_codeABC(fs, o: OP_CLOSE, a: v4->nactvar, b: 0, c: 0);
    fs->freereg = fs->nactvar;
    luaK_patchtohere(fs, list: v4->breaklist);
    luaK_patchlist(fs: ls->fs, list: v.f, target: repeat_init);
  }
  v9 = fs->bl;
  v10 = fs->ls;
  fs->bl = v9->previous;
  removevars(ls: v10, tolevel: v9->nactvar);
  if ( v9->upval != 0 )
    luaK_codeABC(fs, o: OP_CLOSE, a: v9->nactvar, b: 0, c: 0);
  fs->freereg = fs->nactvar;
  luaK_patchtohere(fs, list: v9->breaklist);
}

//------------------------------------------------------------------------------
// Address: 0x00488250
// Name: forbody
// Source: json
//------------------------------------------------------------------------------
void __cdecl forbody(LexState *ls, int base, int line, int nvars, int isnum)
{
  LexState *v5; // edi
  FuncState *fs; // esi
  int v7; // ecx
  int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int v11; // eax
  int v12; // ebx
  FuncState *v13; // eax
  int v14; // edx
  int v15; // ecx
  BlockCnt *bl; // edi
  LexState *v17; // eax
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  BlockCnt v21; // [esp+Ch] [ebp-10h] BYREF
  int prep; // [esp+18h] [ebp-4h]

  v5 = ls;
  fs = ls->fs;
  v7 = 3;
  fs->nactvar += 3;
  do
  {
    v8 = fs->nactvar - v7--;
    fs->f->locvars[fs->actvar[v8]].startpc = fs->pc;
  }
  while ( v7 != 0 );
  if ( ls->t.token != 259 )
  {
    v9 = luaX_token2str(ls, token: 259);
    v10 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v9);
    luaX_syntaxerror(ls, msg: v10);
  }
  luaX_next(ls);
  if ( isnum != 0 )
    v11 = luaK_codeABx(fs, o: OP_FORPREP, a: base, bc: 0x1FFFEu);
  else
    v11 = luaK_jump(fs);
  v12 = nvars;
  v21.breaklist = -1;
  v21.isbreakable = 0;
  prep = v11;
  v21.nactvar = fs->nactvar;
  v21.upval = 0;
  v21.previous = fs->bl;
  fs->bl = &v21;
  v13 = ls->fs;
  v13->nactvar += nvars;
  v14 = nvars;
  if ( nvars != 0 )
  {
    do
    {
      v15 = v13->nactvar - v14--;
      v13->f->locvars[v13->actvar[v15]].startpc = v13->pc;
    }
    while ( v14 != 0 );
    v12 = nvars;
    v5 = ls;
  }
  luaK_reserveregs(fs, n: v12);
  block(ls: v5);
  bl = fs->bl;
  v17 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v17, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_codeABC(fs, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
  fs->freereg = fs->nactvar;
  luaK_patchtohere(fs, list: bl->breaklist);
  luaK_patchtohere(fs, list: prep);
  if ( isnum != 0 )
    v18 = luaK_codeABx(fs, o: OP_FORLOOP, a: base, bc: 0x1FFFEu);
  else
    v18 = luaK_codeABC(fs, o: OP_TFORLOOP, a: base, b: 0, c: v12);
  v19 = v18;
  luaK_fixline(fs, line);
  if ( isnum != 0 )
    v20 = v19;
  else
    v20 = luaK_jump(fs);
  luaK_patchlist(fs, list: v20, target: prep + 1);
}

//------------------------------------------------------------------------------
// Address: 0x00488400
// Name: fornum
// Source: json
//------------------------------------------------------------------------------
void __usercall fornum(LexState *ls@<esi>, GCObject *varname, int line)
{
  FuncState *fs; // ebx
  GCObject *v4; // eax
  GCObject *v5; // eax
  GCObject *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  unsigned int v11; // eax
  expdesc v; // [esp+10h] [ebp-1Ch] BYREF
  int base; // [esp+28h] [ebp-4h]

  fs = ls->fs;
  base = fs->freereg;
  v4 = luaX_newstring(ls, str: "(for index)", l: 0xBu);
  new_localvar(n: 0, ls, name: v4);
  v5 = luaX_newstring(ls, str: "(for limit)", l: 0xBu);
  new_localvar(n: 1, ls, name: v5);
  v6 = luaX_newstring(ls, str: "(for step)", l: 0xAu);
  new_localvar(n: 2, ls, name: v6);
  new_localvar(n: 3, ls, name: varname);
  if ( ls->t.token != 61 )
  {
    v7 = luaX_token2str(ls, token: 61);
    v8 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v7);
    luaX_syntaxerror(ls, msg: v8);
  }
  luaX_next(ls);
  subexpr(ls, &v, limit: 0);
  luaK_exp2nextreg(fs: ls->fs, e: &v);
  if ( ls->t.token != 44 )
  {
    v9 = luaX_token2str(ls, token: 44);
    v10 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v9);
    luaX_syntaxerror(ls, msg: v10);
  }
  luaX_next(ls);
  subexpr(ls, &v, limit: 0);
  luaK_exp2nextreg(fs: ls->fs, e: &v);
  if ( ls->t.token == 44 )
  {
    luaX_next(ls);
    subexpr(ls, &v, limit: 0);
    luaK_exp2nextreg(fs: ls->fs, e: &v);
  }
  else
  {
    v11 = luaK_numberK(fs, r: 1.0);
    luaK_codeABx(fs, o: OP_LOADK, a: fs->freereg, bc: v11);
    luaK_reserveregs(fs, n: 1);
  }
  forbody(ls, base, line, nvars: 1, isnum: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00488580
// Name: forlist
// Source: json
//------------------------------------------------------------------------------
void __usercall forlist(LexState *ls@<eax>, GCObject *indexname)
{
  GCObject *v3; // eax
  GCObject *v4; // eax
  GCObject *v5; // eax
  int v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  FuncState *v9; // edi
  int linedefined; // eax
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // eax
  const char *v14; // eax
  int linenumber; // ebx
  int v16; // eax
  expdesc e; // [esp+Ch] [ebp-24h] BYREF
  int base; // [esp+24h] [ebp-Ch]
  FuncState *fs; // [esp+28h] [ebp-8h]
  int nvars; // [esp+2Ch] [ebp-4h]

  fs = ls->fs;
  base = fs->freereg;
  v3 = luaX_newstring(ls, str: "(for generator)", l: 0xFu);
  new_localvar(n: 0, ls, name: v3);
  v4 = luaX_newstring(ls, str: "(for state)", l: 0xBu);
  new_localvar(n: 1, ls, name: v4);
  v5 = luaX_newstring(ls, str: "(for control)", l: 0xDu);
  new_localvar(n: 2, ls, name: v5);
  new_localvar(n: 3, ls, name: indexname);
  v6 = 4;
  while ( ls->t.token == 44 )
  {
    luaX_next(ls);
    if ( ls->t.token != 285 )
    {
      v7 = luaX_token2str(ls, token: 285);
      v8 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v7);
      luaX_syntaxerror(ls, msg: v8);
    }
    nvars = (int)ls->t.seminfo.ts;
    luaX_next(ls);
    v9 = ls->fs;
    if ( v9->nactvar + v6 + 1 > 200 )
    {
      linedefined = v9->f->linedefined;
      if ( linedefined != 0 )
        v11 = luaO_pushfstring(
                L: (lua_TValue *)v9->L,
                fmt: "function at line %d has more than %d %s",
                linedefined,
                200,
                "local variables");
      else
        v11 = luaO_pushfstring(L: (lua_TValue *)v9->L, fmt: "main function has more than %d %s", 200, "local variables");
      luaX_lexerror(ls: v9->ls, msg: v11, token: 0);
    }
    v9->actvar[v6 + v9->nactvar] = registerlocalvar(ls, varname: (GCObject *)nvars);
    ++v6;
  }
  v12 = ls->t.token == 267;
  nvars = v6;
  if ( !v12 )
  {
    v13 = luaX_token2str(ls, token: 267);
    v14 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v13);
    luaX_syntaxerror(ls, msg: v14);
  }
  luaX_next(ls);
  linenumber = ls->linenumber;
  v16 = explist1(ls, v: &e);
  adjust_assign(ls, &e, nvars: 3, nexps: v16);
  luaK_checkstack(fs, n: 3);
  forbody(ls, base, line: linenumber, nvars: nvars - 3, isnum: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00488740
// Name: forstat
// Source: json
//------------------------------------------------------------------------------
void __usercall forstat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // ebx
  const char *v4; // eax
  const char *v5; // eax
  GCObject *ts; // edi
  int token; // eax
  BlockCnt *bl; // esi
  LexState *v9; // eax
  BlockCnt v10; // [esp+8h] [ebp-Ch] BYREF

  fs = ls->fs;
  v10.breaklist = -1;
  v10.isbreakable = 1;
  v10.nactvar = fs->nactvar;
  v10.upval = 0;
  v10.previous = fs->bl;
  fs->bl = &v10;
  luaX_next(ls);
  if ( ls->t.token != 285 )
  {
    v4 = luaX_token2str(ls, token: 285);
    v5 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v4);
    luaX_syntaxerror(ls, msg: v5);
  }
  ts = (GCObject *)ls->t.seminfo.ts;
  luaX_next(ls);
  token = ls->t.token;
  if ( token != 44 )
  {
    if ( token == 61 )
    {
      fornum(ls, varname: ts, line);
      goto LABEL_9;
    }
    if ( token != 267 )
      luaX_syntaxerror(ls, msg: "'=' or 'in' expected");
  }
  forlist(ls, indexname: ts);
LABEL_9:
  check_match(ls, what: 262, where: line, who: 264);
  bl = fs->bl;
  v9 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v9, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_codeABC(fs, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
  fs->freereg = fs->nactvar;
  luaK_patchtohere(fs, list: bl->breaklist);
}

//------------------------------------------------------------------------------
// Address: 0x00488850
// Name: test_then_block
// Source: json
//------------------------------------------------------------------------------
int __usercall test_then_block@<eax>(LexState *ls@<esi>)
{
  const char *v1; // eax
  const char *v2; // eax
  LexState *v4; // [esp+0h] [ebp-1Ch]
  expdesc v; // [esp+4h] [ebp-18h] BYREF

  luaX_next(ls: v4);
  subexpr(ls, &v, limit: 0);
  if ( v.k == VNIL )
    v.k = VFALSE;
  luaK_goiftrue(fs: ls->fs, e: &v);
  if ( ls->t.token != 274 )
  {
    v1 = luaX_token2str(ls, token: 274);
    v2 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v1);
    luaX_syntaxerror(ls, msg: v2);
  }
  luaX_next(ls);
  block(ls);
  return v.f;
}

//------------------------------------------------------------------------------
// Address: 0x004888D0
// Name: ifstat
// Source: json
//------------------------------------------------------------------------------
void __usercall ifstat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // edi
  int i; // ebx
  int v5; // eax
  bool v6; // zf
  const char *v7; // eax
  const char *v8; // eax
  FuncState *v9; // edi
  BlockCnt *bl; // ebx
  LexState *v11; // edx
  FuncState *v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edx
  int v15; // eax
  expdesc v; // [esp+Ch] [ebp-38h] BYREF
  _DWORD v17[2]; // [esp+24h] [ebp-20h] BYREF
  unsigned __int8 nactvar; // [esp+2Ch] [ebp-18h]
  char v19; // [esp+2Dh] [ebp-17h]
  char v20; // [esp+2Eh] [ebp-16h]
  int f; // [esp+30h] [ebp-14h]
  BlockCnt *v22; // [esp+34h] [ebp-10h]
  int v23; // [esp+38h] [ebp-Ch]
  FuncState *v24; // [esp+3Ch] [ebp-8h]
  int escapelist; // [esp+40h] [ebp-4h] BYREF

  fs = ls->fs;
  v24 = fs;
  escapelist = -1;
  for ( i = test_then_block(ls); ls->t.token == 261; fs = v24 )
  {
    v5 = luaK_jump(fs);
    luaK_concat(fs, l1: &escapelist, l2: v5);
    luaK_patchtohere(fs, list: i);
    luaX_next(ls);
    subexpr(ls, &v, limit: 0);
    if ( v.k == VNIL )
      v.k = VFALSE;
    luaK_goiftrue(fs: ls->fs, e: &v);
    v6 = ls->t.token == 274;
    f = v.f;
    if ( !v6 )
    {
      v7 = luaX_token2str(ls, token: 274);
      v8 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v7);
      luaX_syntaxerror(ls, msg: v8);
    }
    luaX_next(ls);
    v9 = ls->fs;
    v17[1] = -1;
    v20 = 0;
    nactvar = v9->nactvar;
    v19 = 0;
    v17[0] = v9->bl;
    v9->bl = (BlockCnt *)v17;
    chunk(ls);
    bl = v9->bl;
    v11 = v9->ls;
    v9->bl = bl->previous;
    v12 = v11->fs;
    v13 = bl->nactvar;
    v14 = v12->nactvar;
    v22 = bl;
    v23 = v13;
    if ( v14 > v13 )
    {
      do
        v12->f->locvars[v12->actvar[--v12->nactvar]].endpc = v12->pc;
      while ( v12->nactvar > v23 );
      bl = v22;
    }
    if ( bl->upval != 0 )
      luaK_codeABC(fs: v9, o: OP_CLOSE, a: bl->nactvar, b: 0, c: 0);
    v9->freereg = v9->nactvar;
    luaK_patchtohere(fs: v9, list: bl->breaklist);
    i = f;
  }
  if ( ls->t.token == 260 )
  {
    v15 = luaK_jump(fs);
    luaK_concat(fs, l1: &escapelist, l2: v15);
    luaK_patchtohere(fs, list: i);
    luaX_next(ls);
    block(ls);
  }
  else
  {
    luaK_concat(fs, l1: &escapelist, l2: i);
  }
  luaK_patchtohere(fs, list: escapelist);
  check_match(ls, what: 262, where: line, who: 266);
}

//------------------------------------------------------------------------------
// Address: 0x00488AB0
// Name: localfunc
// Source: json
//------------------------------------------------------------------------------
void __usercall localfunc(LexState *ls@<esi>)
{
  FuncState *fs; // ebx
  const char *v2; // eax
  const char *v3; // eax
  GCObject *ts; // edi
  int freereg; // eax
  FuncState *v6; // eax
  expdesc b; // [esp+8h] [ebp-30h] BYREF
  expdesc v; // [esp+20h] [ebp-18h] BYREF

  fs = ls->fs;
  if ( ls->t.token != 285 )
  {
    v2 = luaX_token2str(ls, token: 285);
    v3 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v2);
    luaX_syntaxerror(ls, msg: v3);
  }
  ts = (GCObject *)ls->t.seminfo.ts;
  luaX_next(ls);
  new_localvar(n: 0, ls, name: ts);
  freereg = fs->freereg;
  v.t = -1;
  v.f = -1;
  v.k = VLOCAL;
  v.u.s.info = freereg;
  luaK_reserveregs(fs, n: 1);
  v6 = ls->fs;
  v6->f->locvars[*(unsigned __int16 *)&v6->upvalues[++v6->nactvar + 59].info].startpc = v6->pc;
  body((Proto *)ls, e: &b, needself: 0, line: ls->linenumber);
  luaK_storevar(fs, var: &v, ex: &b);
  fs->f->locvars[*(unsigned __int16 *)&fs->upvalues[fs->nactvar + 59].info].startpc = fs->pc;
}

//------------------------------------------------------------------------------
// Address: 0x00488B80
// Name: localstat
// Source: json
//------------------------------------------------------------------------------
void __usercall localstat(LexState *ls@<eax>)
{
  int v2; // ebx
  const char *v3; // eax
  const char *v4; // eax
  FuncState *fs; // edi
  int linedefined; // eax
  const char *v7; // eax
  int v8; // eax
  FuncState *v9; // esi
  int v10; // edx
  expdesc e; // [esp+Ch] [ebp-1Ch] BYREF
  TString *varname; // [esp+24h] [ebp-4h]

  v2 = 0;
  while ( 1 )
  {
    if ( ls->t.token != 285 )
    {
      v3 = luaX_token2str(ls, token: 285);
      v4 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v3);
      luaX_syntaxerror(ls, msg: v4);
    }
    varname = ls->t.seminfo.ts;
    luaX_next(ls);
    fs = ls->fs;
    if ( fs->nactvar + v2 + 1 > 200 )
    {
      linedefined = fs->f->linedefined;
      if ( linedefined != 0 )
        v7 = luaO_pushfstring(
               L: (lua_TValue *)fs->L,
               fmt: "function at line %d has more than %d %s",
               linedefined,
               200,
               "local variables");
      else
        v7 = luaO_pushfstring(L: (lua_TValue *)fs->L, fmt: "main function has more than %d %s", 200, "local variables");
      luaX_lexerror(ls: fs->ls, msg: v7, token: 0);
    }
    fs->actvar[v2 + fs->nactvar] = registerlocalvar(ls, (GCObject *)varname);
    ++v2;
    if ( ls->t.token != 44 )
      break;
    luaX_next(ls);
  }
  if ( ls->t.token == 61 )
  {
    luaX_next(ls);
    v8 = explist1(ls, v: &e);
  }
  else
  {
    v8 = 0;
    e.k = VVOID;
  }
  adjust_assign(ls, &e, nvars: v2, nexps: v8);
  v9 = ls->fs;
  for ( v9->nactvar += v2; v2 != 0; v9->f->locvars[v9->actvar[v10]].startpc = v9->pc )
    v10 = v9->nactvar - v2--;
}

//------------------------------------------------------------------------------
// Address: 0x00488CC0
// Name: funcstat
// Source: json
//------------------------------------------------------------------------------
void __usercall funcstat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // ebx
  const char *v4; // eax
  const char *v5; // eax
  TString *ts; // edi
  int v7; // eax
  expdesc b; // [esp+8h] [ebp-4Ch] BYREF
  expdesc v; // [esp+20h] [ebp-34h] BYREF
  expdesc k; // [esp+38h] [ebp-1Ch] BYREF
  int needself; // [esp+50h] [ebp-4h]

  luaX_next(ls);
  needself = 0;
  singlevar(ls, var: &v);
  while ( ls->t.token == 46 )
  {
    fs = ls->fs;
    luaK_exp2anyreg(fs, e: &v);
    luaX_next(ls);
    if ( ls->t.token != 285 )
    {
      v4 = luaX_token2str(ls, token: 285);
      v5 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "'%s' expected", v4);
      luaX_syntaxerror(ls, msg: v5);
    }
    ts = ls->t.seminfo.ts;
    luaX_next(ls);
    v7 = luaK_stringK(fs: ls->fs, s: ts);
    k.t = -1;
    k.f = -1;
    k.k = VK;
    k.u.s.info = v7;
    luaK_indexed(fs, t: &v, &k);
  }
  if ( ls->t.token == 58 )
  {
    needself = 1;
    field(ls, &v);
  }
  body((Proto *)ls, e: &b, needself, line);
  luaK_storevar(fs: ls->fs, var: &v, ex: &b);
  luaK_fixline(fs: ls->fs, line);
}

//------------------------------------------------------------------------------
// Address: 0x00488DD0
// Name: retstat
// Source: json
//------------------------------------------------------------------------------
void __usercall retstat(LexState *ls@<eax>)
{
  FuncState *fs; // ebx
  int token; // ecx
  int v4; // esi
  int v5; // eax
  unsigned int *v6; // eax
  expdesc e; // [esp+8h] [ebp-18h] BYREF

  fs = ls->fs;
  luaX_next(ls);
  token = ls->t.token;
  switch ( token )
  {
    case 260:
    case 261:
    case 262:
    case 276:
    case 287:
      goto $LN8_22;
    default:
      if ( token == 59 )
      {
$LN8_22:
        luaK_ret(fs, first: 0, nret: 0);
      }
      else
      {
        v4 = explist1(ls, v: &e);
        if ( e.k == VCALL || e.k == VVARARG )
        {
          luaK_setreturns(fs, &e, nresults: -1);
          if ( e.k == VCALL && v4 == 1 )
          {
            v6 = &fs->f->code[e.u.s.info];
            *v6 = *v6 & 0xFFFFFFC0 | 0x1D;
          }
          luaK_ret(fs, first: fs->nactvar, nret: -1);
        }
        else if ( v4 == 1 )
        {
          v5 = luaK_exp2anyreg(fs, &e);
          luaK_ret(fs, first: v5, nret: 1);
        }
        else
        {
          luaK_exp2nextreg(fs, &e);
          luaK_ret(fs, first: fs->nactvar, nret: v4);
        }
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488EF0
// Name: statement
// Source: json
//------------------------------------------------------------------------------
int __usercall statement@<eax>(LexState *ls@<eax>)
{
  int linenumber; // edi
  int result; // eax
  FuncState *fs; // ebx
  LHS_assign lh; // [esp+8h] [ebp-20h] BYREF

  linenumber = ls->linenumber;
  switch ( ls->t.token )
  {
    case 0x102:
      luaX_next(ls);
      breakstat(ls);
      result = 1;
      break;
    case 0x103:
      luaX_next(ls);
      block(ls);
      check_match(ls, what: 262, where: linenumber, who: 259);
      result = 0;
      break;
    case 0x108:
      forstat(ls, line: ls->linenumber);
      result = 0;
      break;
    case 0x109:
      funcstat(ls, line: ls->linenumber);
      result = 0;
      break;
    case 0x10A:
      ifstat(ls, line: ls->linenumber);
      result = 0;
      break;
    case 0x10C:
      luaX_next(ls);
      if ( ls->t.token == 265 )
      {
        luaX_next(ls);
        localfunc(ls);
      }
      else
      {
        localstat(ls);
      }
      result = 0;
      break;
    case 0x110:
      repeatstat(ls, line: ls->linenumber);
      result = 0;
      break;
    case 0x111:
      retstat(ls);
      result = 1;
      break;
    case 0x115:
      whilestat(ls, line: ls->linenumber);
      result = 0;
      break;
    default:
      fs = ls->fs;
      primaryexp(ls, v: &lh.v);
      if ( lh.v.k == VCALL )
      {
        fs->f->code[lh.v.u.s.info] = fs->f->code[lh.v.u.s.info] & 0xFF803FFF | 0x4000;
      }
      else
      {
        lh.prev = nullptr;
        assignment(ls, &lh, nvars: 1);
      }
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004890A0
// Name: chunk
// Source: json
//------------------------------------------------------------------------------
void __cdecl chunk(LexState *ls)
{
  lua_State *L; // eax
  int v2; // edi

  L = ls->L;
  if ( ++L->nCcalls > 0xC8u )
    luaX_lexerror(ls, msg: "chunk has too many syntax levels", token: 0);
  while ( 2 )
  {
    switch ( ls->t.token )
    {
      case 0x104:
      case 0x105:
      case 0x106:
      case 0x114:
      case 0x11F:
        break;
      default:
        v2 = statement(ls);
        if ( ls->t.token == 59 )
          luaX_next(ls);
        ls->fs->freereg = ls->fs->nactvar;
        if ( v2 == 0 )
          continue;
        break;
    }
    break;
  }
  --ls->L->nCcalls;
}

//------------------------------------------------------------------------------
// Address: 0x00489150
// Name: struct Proto __near * luaY_parser(struct lua_State __near *,struct Zio __near *,struct Mbuffer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
Proto *__cdecl luaY_parser(lua_State *L, Zio *z, Mbuffer *buff, char *name)
{
  GCObject *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  FuncState funcstate; // [esp+4h] [ebp-284h] BYREF
  LexState lexstate; // [esp+240h] [ebp-48h] BYREF

  lexstate.buff = buff;
  v4 = luaS_newlstr(L, str: name, l: strlen(name));
  luaX_setinput(L, ls: &lexstate, z, source: (TString *)v4);
  open_func(fs: &funcstate, ls: (Proto *)&lexstate);
  funcstate.f->is_vararg = 2;
  luaX_next(ls: &lexstate);
  chunk(ls: &lexstate);
  if ( lexstate.t.token != 287 )
  {
    v5 = luaX_token2str(ls: &lexstate, token: 287);
    v6 = luaO_pushfstring(L: (lua_TValue *)lexstate.L, fmt: "'%s' expected", v5);
    luaX_syntaxerror(ls: &lexstate, msg: v6);
  }
  close_func(ls: &lexstate);
  return funcstate.f;
}
