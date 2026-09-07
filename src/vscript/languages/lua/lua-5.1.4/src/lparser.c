// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lparser.c
// Functions: 52
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10014B70
// Name: anchor_token
// Source: json
//------------------------------------------------------------------------------
void __usercall anchor_token(LexState *ls@<eax>)
{
  int token; // eax
  lua_State *L; // edi
  TString *v4; // ebx
  Table *h; // esi
  lua_TValue *v6; // eax
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  token = ls->t.token;
  if ( token == 285 || token == 286 )
  {
    L = ls->L;
    v4 = luaS_newlstr(L, str: (const char *)&ls->t.seminfo.ts[1], l: ls->t.seminfo.ts->tsv.len);
    h = ls->fs->h;
    v6 = (lua_TValue *)luaH_getstr(t: h, key: v4);
    if ( v6 == &luaO_nilobject_ )
    {
      key.value.b = (int)v4;
      key.tt = 4;
      v6 = newkey(L, t: h, &key);
    }
    if ( v6->tt == 0 )
    {
      v6->value.b = 1;
      v6->tt = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014BF0
// Name: error_expected
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn error_expected(LexState *ls@<esi>, int token@<edi>)
{
  const char *v2; // eax
  const char *v3; // eax

  if ( token >= 257 )
  {
    v2 = *((const char **)&strlib[2].func + token);
  }
  else if ( iscntrl(c: token) != 0 )
  {
    v2 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", token);
  }
  else
  {
    v2 = luaO_pushfstring(L: ls->L, fmt: "%c", token);
  }
  v3 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", v2);
  luaX_lexerror(ls, msg: v3, token: ls->t.token);
}

//------------------------------------------------------------------------------
// Address: 0x10014C60
// Name: errorlimit
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn errorlimit(FuncState *fs@<esi>, int limit@<edx>, const char *what@<ecx>)
{
  int linedefined; // eax
  const char *v4; // eax

  linedefined = fs->f->linedefined;
  if ( linedefined != 0 )
    v4 = luaO_pushfstring(L: fs->L, fmt: "function at line %d has more than %d %s", linedefined, limit, what);
  else
    v4 = luaO_pushfstring(L: fs->L, fmt: "main function has more than %d %s", limit, what);
  luaX_lexerror(ls: fs->ls, msg: v4, token: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10014CA0
// Name: testnext
// Source: json
//------------------------------------------------------------------------------
int __usercall testnext@<eax>(LexState *ls@<esi>)
{
  long double r; // xmm0_8

  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
    ls->t.seminfo.r = r;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014CF0
// Name: checknext
// Source: json
//------------------------------------------------------------------------------
void __usercall checknext(LexState *ls@<ecx>, int c@<eax>)
{
  if ( ls->t.token != c )
    error_expected(ls, token: c);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014D50
// Name: check_match
// Source: json
//------------------------------------------------------------------------------
void __usercall check_match(int where@<eax>, LexState *ls, int what, int who)
{
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // [esp-8h] [ebp-14h]

  if ( ls->t.token != what )
  {
    if ( where == ls->linenumber )
      error_expected(ls, token: what);
    v6 = luaX_token2str(ls, token: who);
    v4 = luaX_token2str(ls, token: what);
    v5 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", v4, v6, where);
    luaX_lexerror(ls, msg: v5, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014DF0
// Name: str_checkname
// Source: json
//------------------------------------------------------------------------------
TString *__usercall str_checkname@<eax>(LexState *ls@<esi>)
{
  const char *v1; // eax
  TString *ts; // edi

  if ( ls->t.token != 285 )
  {
    v1 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "<name>");
    luaX_lexerror(ls, msg: v1, token: ls->t.token);
  }
  ts = ls->t.seminfo.ts;
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  return ts;
}

//------------------------------------------------------------------------------
// Address: 0x10014E60
// Name: codestring
// Source: json
//------------------------------------------------------------------------------
void __usercall codestring(LexState *ls@<eax>, expdesc *e@<esi>, TString *s@<ecx>)
{
  int v3; // eax
  FuncState *fs; // [esp-8h] [ebp-18h]
  lua_TValue k; // [esp+0h] [ebp-10h] BYREF

  fs = ls->fs;
  k.value.b = (int)s;
  k.tt = 4;
  v3 = addk(&k, fs, v: &k);
  e->t = -1;
  e->f = -1;
  e->k = VK;
  e->u.s.info = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10014EA0
// Name: registerlocalvar
// Source: json
//------------------------------------------------------------------------------
int __cdecl registerlocalvar(LexState *ls, GCObject *varname)
{
  FuncState *fs; // ecx
  Proto *f; // edi
  int sizelocvars; // esi
  int *p_sizelocvars; // ebx
  LocVar *v6; // eax
  int v7; // eax
  unsigned __int8 marked; // al
  global_State *l_G; // esi
  __int16 nlocvars; // dx
  FuncState *v12; // [esp+Ch] [ebp-4h]

  fs = ls->fs;
  f = fs->f;
  sizelocvars = fs->f->sizelocvars;
  p_sizelocvars = &fs->f->sizelocvars;
  v12 = fs;
  if ( fs->nlocvars + 1 > sizelocvars )
  {
    v6 = (LocVar *)luaM_growaux_(
                     limit: 0x7FFF,
                     L: ls->L,
                     block: f->locvars,
                     size: p_sizelocvars,
                     size_elems: 0xCu,
                     errormsg: "too many local variables");
    fs = v12;
    f->locvars = v6;
  }
  if ( sizelocvars < *p_sizelocvars )
  {
    v7 = sizelocvars;
    do
    {
      f->locvars[v7].varname = nullptr;
      ++sizelocvars;
      ++v7;
    }
    while ( sizelocvars < *p_sizelocvars );
  }
  f->locvars[fs->nlocvars].varname = (TString *)varname;
  if ( (varname->gch.marked & 3) != 0 )
  {
    marked = f->marked;
    if ( (marked & 4) != 0 )
    {
      l_G = ls->L->l_G;
      if ( l_G->gcstate == 1 )
      {
        reallymarkobject(g: l_G, o: varname);
        fs = v12;
      }
      else
      {
        f->marked = marked & 0xF8 | l_G->currentwhite & 3;
      }
    }
  }
  nlocvars = fs->nlocvars;
  fs->nlocvars = nlocvars + 1;
  return nlocvars;
}

//------------------------------------------------------------------------------
// Address: 0x10014F60
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
// Address: 0x10014FA0
// Name: indexupvalue
// Source: json
//------------------------------------------------------------------------------
int __cdecl indexupvalue(FuncState *fs, GCObject *name, expdesc *v)
{
  FuncState *v3; // esi
  Proto *f; // edi
  int sizeupvalues; // ebx
  int result; // eax
  unsigned __int8 *p_info; // ecx
  int v8; // eax
  unsigned __int8 marked; // al
  global_State *l_G; // ecx

  v3 = fs;
  f = fs->f;
  sizeupvalues = fs->f->sizeupvalues;
  result = 0;
  if ( fs->f->nups != 0 )
  {
    p_info = &fs->upvalues[0].info;
    while ( *(p_info - 1) != v->k || *p_info != v->u.s.info )
    {
      ++result;
      p_info += 2;
      if ( result >= f->nups )
      {
        v3 = fs;
        goto LABEL_7;
      }
    }
  }
  else
  {
LABEL_7:
    v8 = f->nups + 1;
    if ( (unsigned int)v8 > 0x3C )
      errorlimit(fs: v3, limit: 60, what: "upvalues");
    if ( v8 > sizeupvalues )
      f->upvalues = (TString **)luaM_growaux_(
                                  limit: 2147483645,
                                  L: v3->L,
                                  block: f->upvalues,
                                  size: &f->sizeupvalues,
                                  size_elems: 4u,
                                  errormsg: Ptr);
    for ( ; sizeupvalues < f->sizeupvalues; ++sizeupvalues )
      f->upvalues[sizeupvalues] = nullptr;
    f->upvalues[f->nups] = (TString *)name;
    if ( (name->gch.marked & 3) != 0 )
    {
      marked = f->marked;
      if ( (marked & 4) != 0 )
      {
        l_G = v3->L->l_G;
        if ( l_G->gcstate == 1 )
          reallymarkobject(g: l_G, o: name);
        else
          f->marked = marked & 0xF8 | l_G->currentwhite & 3;
      }
    }
    v3->upvalues[f->nups].k = v->k;
    v3->upvalues[f->nups].info = LOBYTE(v->u.nval);
    LOBYTE(result) = f->nups;
    f->nups = result + 1;
    return (unsigned __int8)result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100150B0
// Name: searchvar
// Source: json
//------------------------------------------------------------------------------
int __cdecl searchvar(FuncState *fs, TString *n)
{
  FuncState *v2; // ecx
  int v3; // esi
  unsigned __int16 *i; // edi
  TString *varname; // eax

  v2 = fs;
  v3 = fs->nactvar - 1;
  if ( fs->nactvar == 0 )
    return -1;
  for ( i = &fs->actvar[v3]; ; --i )
  {
    varname = v2->f->locvars[*i].varname;
    if ( varname == n )
      break;
    if ( varname->tsv.keyhash == n->tsv.keyhash )
    {
      if ( _stricmp(dst: (const char *)&varname[1], src: (const char *)&n[1]) == 0 )
        return v3;
      v2 = fs;
    }
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10015120
// Name: singlevaraux
// Source: json
//------------------------------------------------------------------------------
int __cdecl singlevaraux(FuncState *fs, GCObject *n, expdesc *var, int base)
{
  int v5; // eax
  BlockCnt *bl; // ecx

  if ( fs == nullptr )
  {
    var->t = -1;
    var->f = -1;
    var->k = VGLOBAL;
    var->u.s.info = 255;
    return 8;
  }
  v5 = searchvar(fs, (TString *)n);
  if ( v5 < 0 )
  {
    if ( singlevaraux(fs: fs->prev, (TString *)n, var, base: 0) == 8 )
      return 8;
    var->u.s.info = indexupvalue(fs, name: n, v: var);
    var->k = VUPVAL;
    return 7;
  }
  else
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
}

//------------------------------------------------------------------------------
// Address: 0x100151F0
// Name: adjust_assign
// Source: json
//------------------------------------------------------------------------------
void __usercall adjust_assign(LexState *ls@<ecx>, expdesc *e@<eax>, int nvars, int nexps)
{
  FuncState *fs; // esi
  expkind k; // ecx
  int v6; // edi
  int freereg; // ecx
  int v8; // eax
  int v9; // edi
  int v10; // eax

  fs = ls->fs;
  k = e->k;
  v6 = nvars - nexps;
  if ( e->k == VCALL || k == VVARARG )
  {
    v9 = v6 + 1;
    if ( v9 < 0 )
      v9 = 0;
    luaK_setreturns(fs, e, nresults: v9);
    if ( v9 > 1 )
    {
      v10 = v9 - 1 + fs->freereg;
      if ( v10 > fs->f->maxstacksize )
      {
        if ( v10 >= 250 )
          luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
        fs->f->maxstacksize = v10;
      }
      fs->freereg += v9 - 1;
    }
  }
  else
  {
    if ( k != VVOID )
      luaK_exp2nextreg(fs, e);
    if ( v6 > 0 )
    {
      freereg = fs->freereg;
      v8 = freereg + v6;
      if ( freereg + v6 > fs->f->maxstacksize )
      {
        if ( v8 >= 250 )
          luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
        fs->f->maxstacksize = v8;
      }
      fs->freereg += v6;
      luaK_nil(fs, from: freereg, n: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100152B0
// Name: leaveblock
// Source: json
//------------------------------------------------------------------------------
void __usercall leaveblock(FuncState *fs@<eax>)
{
  BlockCnt *bl; // edi
  int pc; // edx
  int breaklist; // ecx

  bl = fs->bl;
  fs->bl = bl->previous;
  removevars(ls: fs->ls, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  pc = fs->pc;
  fs->freereg = fs->nactvar;
  breaklist = bl->breaklist;
  fs->lasttarget = pc;
  luaK_concat(l1: &fs->jpc, l2: breaklist, fs);
}

//------------------------------------------------------------------------------
// Address: 0x10015310
// Name: pushclosure
// Source: json
//------------------------------------------------------------------------------
void __cdecl pushclosure(LexState *ls, FuncState *func, expdesc *v)
{
  FuncState *fs; // esi
  Proto *f; // ebx
  int *p_sizep; // eax
  int v6; // edi
  unsigned __int8 marked; // al
  global_State *l_G; // ecx
  int v9; // eax
  int v10; // ebx
  upvaldesc *upvalues; // edi

  fs = ls->fs;
  f = fs->f;
  p_sizep = &fs->f->sizep;
  v6 = *p_sizep;
  if ( fs->np + 1 > *p_sizep )
    f->p = (Proto **)luaM_growaux_(
                       limit: 0x3FFFF,
                       L: ls->L,
                       block: f->p,
                       size: p_sizep,
                       size_elems: 4u,
                       errormsg: "constant table overflow");
  for ( ; v6 < f->sizep; ++v6 )
    f->p[v6] = nullptr;
  f->p[fs->np++] = func->f;
  if ( (func->f->marked & 3) != 0 )
  {
    marked = f->marked;
    if ( (marked & 4) != 0 )
    {
      l_G = ls->L->l_G;
      if ( l_G->gcstate == 1 )
        reallymarkobject(g: l_G, o: (GCObject *)func->f);
      else
        f->marked = marked & 0xF8 | l_G->currentwhite & 3;
    }
  }
  v9 = luaK_code(fs, i: ((fs->np - 1) << 14) | 0x24, line: fs->ls->lastline);
  v->t = -1;
  v->f = -1;
  v->k = VRELOCABLE;
  v->u.s.info = v9;
  v10 = 0;
  if ( func->f->nups != 0 )
  {
    upvalues = func->upvalues;
    do
    {
      luaK_code(fs, i: (upvalues->k == 6 ? 0 : 4) | (upvalues->info << 23), line: fs->ls->lastline);
      ++v10;
      ++upvalues;
    }
    while ( v10 < func->f->nups );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015420
// Name: open_func
// Source: json
//------------------------------------------------------------------------------
void __usercall open_func(LexState *ls@<eax>, FuncState *fs)
{
  int v3; // ebx
  global_State *v4; // eax
  int v5; // esi
  global_State *v6; // eax
  _DWORD *p_b; // eax
  int stacksize; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // eax
  lua_State *L; // [esp+10h] [ebp-8h]
  global_State *l_G; // [esp+14h] [ebp-4h]
  global_State *v14; // [esp+14h] [ebp-4h]

  L = ls->L;
  l_G = L->l_G;
  v3 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 76u);
  if ( v3 == 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 76;
  v4 = L->l_G;
  *(_DWORD *)v3 = v4->rootgc;
  v4->rootgc = (GCObject *)v3;
  LOBYTE(v4) = v4->currentwhite;
  *(_DWORD *)(v3 + 72) = 0;
  *(_DWORD *)(v3 + 32) = 0;
  *(_BYTE *)(v3 + 4) = 9;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 40) = 0;
  *(_DWORD *)(v3 + 16) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 44) = 0;
  *(_DWORD *)(v3 + 48) = 0;
  *(_DWORD *)(v3 + 36) = 0;
  *(_DWORD *)(v3 + 28) = 0;
  *(_DWORD *)(v3 + 20) = 0;
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 24) = 0;
  *(_DWORD *)(v3 + 60) = 0;
  *(_DWORD *)(v3 + 64) = 0;
  *(_BYTE *)(v3 + 5) = (unsigned __int8)v4 & 3;
  fs->f = (Proto *)v3;
  fs->prev = ls->fs;
  fs->ls = ls;
  fs->L = L;
  ls->fs = fs;
  fs->lasttarget = -1;
  fs->jpc = -1;
  fs->pc = 0;
  fs->freereg = 0;
  fs->nk = 0;
  fs->np = 0;
  fs->bl = nullptr;
  fs->nlocvars = 0;
  fs->nactvar = 0;
  *(_DWORD *)(v3 + 32) = ls->source;
  *(_BYTE *)(v3 + 75) = 2;
  v14 = L->l_G;
  v5 = (int)v14->frealloc(a1: v14->ud, a2: nullptr, a3: 0, a4: 32u);
  if ( v5 == 0 )
    luaD_throw(L, errcode: 4);
  v14->totalbytes += 32;
  v6 = L->l_G;
  *(_DWORD *)v5 = v6->rootgc;
  v6->rootgc = (GCObject *)v5;
  *(_BYTE *)(v5 + 5) = v6->currentwhite & 3;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 28) = 0;
  *(_BYTE *)(v5 + 4) = 5;
  *(_WORD *)(v5 + 6) = 255;
  *(_DWORD *)(v5 + 16) = &dummynode_;
  setarrayvector(L, t: (Table *)v5, size: 0);
  *(_BYTE *)(v5 + 7) = 0;
  *(_DWORD *)(v5 + 16) = &dummynode_;
  *(_DWORD *)(v5 + 20) = &dummynode_;
  fs->h = (Table *)v5;
  *(_BYTE *)(v5 + 6) &= ~0x40u;
  p_b = &L->top->value.b;
  *p_b = fs->h;
  p_b[2] = 5;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    if ( stacksize < 1 )
      v9 = stacksize + 1;
    else
      v9 = 2 * stacksize;
    luaD_reallocstack(L, newsize: v9);
  }
  v10 = (int *)++L->top;
  *v10 = v3;
  v10[2] = 9;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    v11 = L->stacksize;
    if ( v11 >= 1 )
    {
      luaD_reallocstack(L, newsize: 2 * v11);
      ++L->top;
      return;
    }
    luaD_reallocstack(L, newsize: v11 + 1);
  }
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x100155F0
// Name: close_func
// Source: json
//------------------------------------------------------------------------------
void __cdecl close_func(LexState *ls)
{
  lua_State *L; // ebx
  FuncState *fs; // esi
  Proto *f; // edi
  int pc; // eax
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int nk; // eax
  int v10; // esi
  int v11; // eax
  int np; // eax
  int v13; // esi
  int v14; // eax
  int nlocvars; // eax
  int v16; // esi
  int v17; // eax
  int nups; // eax
  int v19; // esi
  int v20; // eax
  int v21; // ecx
  FuncState *v22; // [esp+Ch] [ebp-Ch]
  int v23; // [esp+10h] [ebp-8h]
  global_State *v24; // [esp+10h] [ebp-8h]
  int v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+10h] [ebp-8h]
  global_State *v27; // [esp+10h] [ebp-8h]
  int v28; // [esp+10h] [ebp-8h]
  global_State *l_G; // [esp+14h] [ebp-4h]
  int v30; // [esp+14h] [ebp-4h]
  global_State *v31; // [esp+14h] [ebp-4h]
  global_State *v32; // [esp+14h] [ebp-4h]
  int v33; // [esp+14h] [ebp-4h]
  global_State *v34; // [esp+14h] [ebp-4h]

  L = ls->L;
  fs = ls->fs;
  f = fs->f;
  v22 = fs;
  removevars(ls, tolevel: 0);
  luaK_code(fs, i: 0x80001Eu, line: fs->ls->lastline);
  pc = fs->pc;
  if ( (unsigned int)(pc + 1) > 0x3FFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v5 = 4 * f->sizecode;
  v23 = 4 * pc;
  l_G = L->l_G;
  v6 = (int)l_G->frealloc(a1: l_G->ud, a2: f->code, a3: v5, a4: 4 * pc);
  if ( v6 == 0 && v23 != 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += v23 - v5;
  f->code = (unsigned int *)v6;
  f->sizecode = v22->pc;
  if ( (unsigned int)(v22->pc + 1) > 0x3FFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v7 = 4 * v22->pc;
  v30 = 4 * f->sizelineinfo;
  v24 = L->l_G;
  v8 = (int)v24->frealloc(a1: v24->ud, a2: f->lineinfo, a3: v30, a4: v7);
  if ( v8 == 0 && v7 != 0 )
    luaD_throw(L, errcode: 4);
  v24->totalbytes += v7 - v30;
  f->lineinfo = (int *)v8;
  f->sizelineinfo = v22->pc;
  nk = v22->nk;
  if ( (unsigned int)(nk + 1) > 0xFFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v10 = 16 * f->sizek;
  v25 = 16 * nk;
  v31 = L->l_G;
  v11 = (int)v31->frealloc(a1: v31->ud, a2: f->k, a3: v10, a4: 16 * nk);
  if ( v11 == 0 && v25 != 0 )
    luaD_throw(L, errcode: 4);
  v31->totalbytes += v25 - v10;
  f->k = (lua_TValue *)v11;
  f->sizek = v22->nk;
  np = v22->np;
  if ( (unsigned int)(np + 1) > 0x3FFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v13 = 4 * f->sizep;
  v32 = L->l_G;
  v26 = 4 * np;
  v14 = (int)v32->frealloc(a1: v32->ud, a2: f->p, a3: v13, a4: 4 * np);
  if ( v14 == 0 && v26 != 0 )
    luaD_throw(L, errcode: 4);
  v32->totalbytes += v26 - v13;
  f->p = (Proto **)v14;
  f->sizep = v22->np;
  nlocvars = v22->nlocvars;
  if ( (unsigned int)(nlocvars + 1) > 0x15555555 )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v16 = 12 * nlocvars;
  v33 = 12 * f->sizelocvars;
  v27 = L->l_G;
  v17 = (int)v27->frealloc(a1: v27->ud, a2: f->locvars, a3: v33, a4: 12 * nlocvars);
  if ( v17 == 0 && v16 != 0 )
    luaD_throw(L, errcode: 4);
  v27->totalbytes += v16 - v33;
  f->locvars = (LocVar *)v17;
  nups = f->nups;
  f->sizelocvars = v22->nlocvars;
  if ( (unsigned int)(nups + 1) > 0x3FFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v19 = 4 * f->sizeupvalues;
  v34 = L->l_G;
  v28 = 4 * nups;
  v20 = (int)v34->frealloc(a1: v34->ud, a2: f->upvalues, a3: v19, a4: 4 * nups);
  if ( v20 == 0 && v28 != 0 )
    luaD_throw(L, errcode: 4);
  v34->totalbytes += v28 - v19;
  v21 = f->nups;
  f->upvalues = (TString **)v20;
  f->sizeupvalues = v21;
  ls->fs = v22->prev;
  L->top -= 2;
  anchor_token(ls);
}

//------------------------------------------------------------------------------
// Address: 0x10015900
// Name: _luaY_parser
// Source: json
//------------------------------------------------------------------------------
Proto *__cdecl luaY_parser(lua_State *L, Zio *z, Mbuffer *buff, const char *name)
{
  TString *v4; // eax
  const char *v5; // eax
  LexState lexstate; // [esp+8h] [ebp-288h] BYREF
  FuncState funcstate; // [esp+50h] [ebp-240h] BYREF

  lexstate.buff = buff;
  v4 = luaS_newlstr(L, str: name, l: strlen(name));
  luaX_setinput(ls: &lexstate, z, source: v4, L);
  open_func(ls: &lexstate, fs: &funcstate);
  funcstate.f->is_vararg = 2;
  lexstate.lastline = lexstate.linenumber;
  if ( lexstate.lookahead.token == 287 )
  {
    lexstate.t.token = llex(ls: &lexstate, seminfo: &lexstate.t.seminfo);
  }
  else
  {
    lexstate.t = lexstate.lookahead;
    lexstate.lookahead.token = 287;
  }
  chunk(ls: &lexstate);
  if ( lexstate.t.token != 287 )
  {
    v5 = luaO_pushfstring(L: lexstate.L, fmt: "'%s' expected", "<eof>");
    luaX_lexerror(ls: &lexstate, msg: v5, token: lexstate.t.token);
  }
  close_func(ls: &lexstate);
  return funcstate.f;
}

//------------------------------------------------------------------------------
// Address: 0x10015A00
// Name: field
// Source: json
//------------------------------------------------------------------------------
void __usercall field(LexState *ls@<ecx>, expdesc *v@<eax>)
{
  FuncState *fs; // ebx
  TString *v5; // eax
  FuncState *v6; // esi
  expdesc key; // [esp+10h] [ebp-28h] BYREF
  lua_TValue k; // [esp+28h] [ebp-10h] BYREF

  fs = ls->fs;
  luaK_dischargevars(fs, e: v);
  if ( v->k != VNONRELOC )
    goto LABEL_5;
  if ( v->t != v->f )
  {
    if ( v->u.s.info >= fs->nactvar )
      exp2reg(fs, e: v, reg: v->u.s.info);
    else
LABEL_5:
      luaK_exp2nextreg(fs, e: v);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
  v5 = str_checkname(ls);
  v6 = ls->fs;
  k.value.b = (int)v5;
  k.tt = 4;
  key.k = VK;
  key.t = -1;
  key.f = -1;
  key.u.s.info = addk(&k, fs: v6, v: &k);
  v->u.s.aux = luaK_exp2RK(fs, e: &key);
  v->k = VINDEXED;
}

//------------------------------------------------------------------------------
// Address: 0x10015AD0
// Name: yindex
// Source: json
//------------------------------------------------------------------------------
void __usercall yindex(LexState *ls@<ecx>, expdesc *v@<eax>)
{
  FuncState *fs; // ebx

  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  subexpr(ls, v, limit: 0);
  fs = ls->fs;
  if ( v->t == v->f )
  {
    luaK_dischargevars(fs, e: v);
  }
  else
  {
    luaK_dischargevars(fs, e: v);
    if ( v->k != VNONRELOC )
      goto LABEL_9;
    if ( v->t == v->f )
      goto LABEL_11;
    if ( v->u.s.info >= fs->nactvar )
      exp2reg(fs, e: v, reg: v->u.s.info);
    else
LABEL_9:
      luaK_exp2nextreg(fs, e: v);
  }
LABEL_11:
  if ( ls->t.token != 93 )
    error_expected(ls, token: 93);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015BC0
// Name: recfield
// Source: json
//------------------------------------------------------------------------------
void __cdecl recfield(LexState *ls, ConsControl *cc)
{
  FuncState *fs; // esi
  ConsControl *v3; // edi
  TString *v4; // eax
  FuncState *v5; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int reg; // [esp+14h] [ebp-44h]
  lua_TValue k; // [esp+18h] [ebp-40h] BYREF
  expdesc key; // [esp+28h] [ebp-30h] BYREF
  expdesc val; // [esp+40h] [ebp-18h] BYREF

  fs = ls->fs;
  reg = fs->freereg;
  if ( ls->t.token == 285 )
  {
    v3 = cc;
    if ( cc->nh > 2147483645 )
      errorlimit(fs, limit: 2147483645, what: "items in a constructor");
    v4 = str_checkname(ls);
    v5 = ls->fs;
    k.value.b = (int)v4;
    k.tt = 4;
    v6 = addk(&k, fs: v5, v: &k);
    key.k = VK;
    key.t = -1;
    key.f = -1;
    key.u.s.info = v6;
  }
  else
  {
    yindex(ls, v: &key);
    v3 = cc;
  }
  ++v3->nh;
  if ( ls->t.token != 61 )
    error_expected(ls, token: 61);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  v7 = luaK_exp2RK(fs, e: &key);
  subexpr(ls, v: &val, limit: 0);
  v8 = luaK_exp2RK(fs, e: &val);
  luaK_code(fs, i: ((cc->t->u.s.info | ((v8 | (v7 << 9)) << 8)) << 6) | 9, line: fs->ls->lastline);
  fs->freereg = reg;
}

//------------------------------------------------------------------------------
// Address: 0x10015D00
// Name: lastlistfield
// Source: json
//------------------------------------------------------------------------------
void __usercall lastlistfield(FuncState *fs@<eax>, ConsControl *cc@<edi>)
{
  expkind k; // eax
  int info; // ecx
  signed int v5; // ebx
  int lastline; // [esp-4h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-4h]

  if ( cc->tostore != 0 )
  {
    k = cc->v.k;
    if ( cc->v.k == VCALL || k == VVARARG )
    {
      luaK_setreturns(fs, e: &cc->v, nresults: -1);
      info = cc->t->u.s.info;
      v5 = (cc->na - 1) / 50 + 1;
      v7 = info;
      lastline = fs->ls->lastline;
      if ( v5 > 511 )
      {
        luaK_code(fs, i: (info << 6) | 0x22, line: lastline);
        luaK_code(fs, i: v5, line: fs->ls->lastline);
      }
      else
      {
        luaK_code(fs, i: ((info | (v5 << 8)) << 6) | 0x22, line: lastline);
      }
      fs->freereg = v7 + 1;
      --cc->na;
    }
    else
    {
      if ( k != VVOID )
        luaK_exp2nextreg(fs, e: &cc->v);
      luaK_setlist(tostore: cc->tostore, nelems: cc->na, fs, base: cc->t->u.s.info);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015DE0
// Name: constructor
// Source: json
//------------------------------------------------------------------------------
void __usercall constructor(expdesc *t@<eax>, LexState *ls)
{
  FuncState *fs; // esi
  int v4; // eax
  FuncState *v5; // ecx
  long double r; // xmm0_8
  int v7; // eax
  int info; // ecx
  signed int v9; // edi
  int token; // eax
  int v11; // eax
  int v12; // eax
  unsigned int na; // ecx
  int i; // eax
  int v15; // eax
  const char *v16; // eax
  const char *v17; // esi
  const char *v18; // eax
  const char *v19; // eax
  unsigned int nh; // eax
  int j; // ecx
  int v22; // ecx
  int lastline; // [esp-4h] [ebp-44h]
  int v24; // [esp+Ch] [ebp-34h]
  int line; // [esp+10h] [ebp-30h]
  int pc; // [esp+14h] [ebp-2Ch]
  ConsControl cc; // [esp+18h] [ebp-28h] BYREF

  fs = ls->fs;
  line = ls->linenumber;
  v4 = luaK_code(fs, i: 0xAu, line: fs->ls->lastline);
  t->u.s.info = v4;
  pc = v4;
  memset(&cc.nh, 0, 12);
  t->t = -1;
  t->f = -1;
  t->k = VRELOCABLE;
  cc.v.k = VVOID;
  cc.v.u.s.info = 0;
  v5 = ls->fs;
  cc.t = t;
  cc.v.t = -1;
  cc.v.f = -1;
  luaK_exp2nextreg(fs: v5, e: t);
  if ( ls->t.token != 123 )
    error_expected(ls, token: 123);
LABEL_3:
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token != 287 )
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
    ls->t.seminfo.r = r;
    goto LABEL_6;
  }
LABEL_5:
  ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
LABEL_6:
  while ( ls->t.token != 125 )
  {
    if ( cc.v.k != VVOID )
    {
      luaK_dischargevars(fs, e: &cc.v);
      if ( cc.v.k == VNONRELOC && (LOWORD(cc.v.u.nval) & 0x100) == 0 && cc.v.u.s.info >= fs->nactvar )
        --fs->freereg;
      v7 = fs->freereg + 1;
      if ( v7 > fs->f->maxstacksize )
      {
        if ( v7 >= 250 )
          luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
        fs->f->maxstacksize = v7;
      }
      exp2reg(fs, e: &cc.v, reg: fs->freereg++);
      cc.v.k = VVOID;
      if ( cc.tostore == 50 )
      {
        info = cc.t->u.s.info;
        v9 = (cc.na - 1) / 50 + 1;
        v24 = info;
        lastline = fs->ls->lastline;
        if ( v9 > 511 )
        {
          luaK_code(fs, i: (info << 6) | 0x19000022, line: lastline);
          luaK_code(fs, i: v9, line: fs->ls->lastline);
        }
        else
        {
          luaK_code(fs, i: ((info | (v9 << 8)) << 6) | 0x19000022, line: lastline);
        }
        fs->freereg = v24 + 1;
        cc.tostore = 0;
      }
    }
    token = ls->t.token;
    if ( token == 91
      || token == 285 && (v11 = llex(ls, seminfo: &ls->lookahead.seminfo), ls->lookahead.token = v11, v11 == 61) )
    {
      recfield(ls, &cc);
    }
    else
    {
      subexpr(ls, v: &cc.v, limit: 0);
      if ( cc.na > 2147483645 )
        errorlimit(fs: ls->fs, limit: 2147483645, what: "items in a constructor");
      ++cc.na;
      ++cc.tostore;
    }
    v12 = ls->t.token;
    if ( v12 == 44 )
      goto LABEL_3;
    if ( v12 != 59 )
    {
      if ( ls->t.token != 125 )
      {
        if ( line == ls->linenumber )
          error_expected(ls, token: 125);
        if ( iscntrl(c: 123) != 0 )
          v16 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", 123);
        else
          v16 = luaO_pushfstring(L: ls->L, fmt: "%c", 123);
        v17 = v16;
        if ( iscntrl(c: 125) != 0 )
          v18 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", 125);
        else
          v18 = luaO_pushfstring(L: ls->L, fmt: "%c", 125);
        v19 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", v18, v17, line);
        luaX_lexerror(ls, msg: v19, token: ls->t.token);
      }
      break;
    }
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
      goto LABEL_5;
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  lastlistfield(fs, &cc);
  na = cc.na;
  for ( i = 0; na >= 0x10; ++i )
    na = (na + 1) >> 1;
  if ( na >= 8 )
    v15 = (na - 8) | (8 * i + 8);
  else
    v15 = na;
  fs->f->code[pc] = (v15 << 23) | fs->f->code[pc] & 0x7FFFFF;
  nh = cc.nh;
  for ( j = 0; nh >= 0x10; ++j )
    nh = (nh + 1) >> 1;
  if ( nh >= 8 )
    v22 = (nh - 8) | (8 * j + 8);
  else
    v22 = nh;
  fs->f->code[pc] ^= (fs->f->code[pc] ^ (v22 << 14)) & 0x7FC000;
}

//------------------------------------------------------------------------------
// Address: 0x100161E0
// Name: parlist
// Source: json
//------------------------------------------------------------------------------
void __usercall parlist(LexState *ls@<eax>)
{
  FuncState *fs; // ecx
  Proto *v3; // esi
  int v4; // ebx
  bool v5; // zf
  int linenumber; // edx
  FuncState *v7; // esi
  unsigned __int16 v8; // ax
  Proto *v9; // edx
  lua_State *L; // esi
  TString *v11; // eax
  lua_TValue *v12; // eax
  FuncState *v13; // edi
  int v14; // edx
  int nactvar; // esi
  int v16; // eax
  Table *h; // [esp-8h] [ebp-38h]
  lua_TValue key; // [esp+10h] [ebp-20h] BYREF
  FuncState *v19; // [esp+20h] [ebp-10h]
  Table *t; // [esp+24h] [ebp-Ch]
  TString *varname; // [esp+28h] [ebp-8h]
  Proto *f; // [esp+2Ch] [ebp-4h]

  fs = ls->fs;
  v3 = fs->f;
  v4 = 0;
  v3->is_vararg = 0;
  v5 = ls->t.token == 41;
  v19 = fs;
  f = v3;
  if ( !v5 )
  {
    while ( ls->t.token != 279 )
    {
      if ( ls->t.token != 285 )
        luaX_lexerror(ls, msg: "<name> or '...' expected", token: ls->t.token);
      linenumber = ls->linenumber;
      varname = ls->t.seminfo.ts;
      ls->lastline = linenumber;
      if ( ls->lookahead.token == 287 )
      {
        ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      }
      else
      {
        *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
        ls->t.seminfo.r = ls->lookahead.seminfo.r;
        ls->lookahead.token = 287;
      }
      v7 = ls->fs;
      if ( v7->nactvar + v4 + 1 > 200 )
        goto $LN91;
      v8 = registerlocalvar(ls, (GCObject *)varname);
      v9 = f;
      v7->actvar[v4 + v7->nactvar] = v8;
      ++v4;
      if ( v9->is_vararg != 0 || ls->t.token != 44 )
        goto LABEL_22;
      ls->lastline = ls->linenumber;
      if ( ls->lookahead.token == 287 )
      {
        ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      }
      else
      {
        *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
        ls->t.seminfo.r = ls->lookahead.seminfo.r;
        ls->lookahead.token = 287;
      }
    }
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
      ls->t.seminfo.r = ls->lookahead.seminfo.r;
      ls->lookahead.token = 287;
    }
    L = ls->L;
    v11 = luaS_newlstr(L, str: "arg", l: 3u);
    h = ls->fs->h;
    varname = v11;
    t = h;
    v12 = (lua_TValue *)luaH_getstr(t: h, key: v11);
    if ( v12 == &luaO_nilobject_ )
    {
      key.value.b = (int)varname;
      key.tt = 4;
      v12 = newkey(L, t, &key);
    }
    if ( v12->tt == 0 )
    {
      v12->value.b = 1;
      v12->tt = 1;
    }
    v7 = ls->fs;
    if ( v7->nactvar + v4 + 1 > 200 )
$LN91:
      errorlimit(fs: v7, limit: 200, what: "local variables");
    v7->actvar[v4 + v7->nactvar] = registerlocalvar(ls, (GCObject *)varname);
    ++v4;
    f->is_vararg = 7;
LABEL_22:
    v3 = f;
    fs = v19;
  }
  v13 = ls->fs;
  v13->nactvar += v4;
  if ( v4 != 0 )
  {
    do
    {
      v14 = v13->nactvar - v4--;
      v13->f->locvars[v13->actvar[v14]].startpc = v13->pc;
    }
    while ( v4 != 0 );
    v3 = f;
  }
  v3->numparams = fs->nactvar - (v3->is_vararg & 1);
  nactvar = fs->nactvar;
  v16 = nactvar + fs->freereg;
  if ( v16 > fs->f->maxstacksize )
  {
    if ( v16 >= 250 )
      luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
    fs->f->maxstacksize = v16;
  }
  fs->freereg += nactvar;
}

//------------------------------------------------------------------------------
// Address: 0x10016460
// Name: body
// Source: json
//------------------------------------------------------------------------------
void __usercall body(LexState *ls@<eax>, expdesc *e, int needself, int line)
{
  int v5; // ebx
  lua_State *L; // edi
  GCObject *v7; // ebx
  lua_TValue *v8; // eax
  FuncState *fs; // edi
  unsigned __int16 v10; // ax
  FuncState *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  FuncState new_fs; // [esp+10h] [ebp-25Ch] BYREF
  lua_TValue key; // [esp+250h] [ebp-1Ch] BYREF
  Table *t; // [esp+264h] [ebp-8h]

  open_func(ls, fs: &new_fs);
  v5 = line;
  new_fs.f->linedefined = line;
  if ( ls->t.token != 40 )
    error_expected(ls, token: 40);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
  if ( needself != 0 )
  {
    L = ls->L;
    v7 = (GCObject *)luaS_newlstr(L, str: "self", l: 4u);
    t = ls->fs->h;
    v8 = (lua_TValue *)luaH_getstr(t, key: (TString *)v7);
    if ( v8 == &luaO_nilobject_ )
    {
      key.value.b = (int)v7;
      key.tt = 4;
      v8 = newkey(L, t, &key);
    }
    if ( v8->tt == 0 )
    {
      v8->value.b = 1;
      v8->tt = 1;
    }
    fs = ls->fs;
    if ( (unsigned int)fs->nactvar + 1 > 0xC8 )
      errorlimit(fs: ls->fs, limit: 200, what: "local variables");
    v10 = registerlocalvar(ls, varname: v7);
    v5 = line;
    fs->actvar[fs->nactvar] = v10;
    v11 = ls->fs;
    v11->f->locvars[*(unsigned __int16 *)&v11->upvalues[++v11->nactvar + 59].info].startpc = v11->pc;
  }
  parlist(ls);
  if ( ls->t.token != 41 )
    error_expected(ls, token: 41);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
  chunk(ls);
  new_fs.f->lastlinedefined = ls->linenumber;
  if ( ls->t.token != 262 )
  {
    if ( v5 == ls->linenumber )
    {
      v12 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "end");
      luaX_lexerror(ls, msg: v12, token: ls->t.token);
    }
    v13 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", "end", "function", v5);
    luaX_lexerror(ls, msg: v13, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
  close_func(ls);
  pushclosure(ls, func: &new_fs, v: e);
}

//------------------------------------------------------------------------------
// Address: 0x100166C0
// Name: explist1
// Source: json
//------------------------------------------------------------------------------
int __usercall explist1@<eax>(expdesc *v@<eax>, LexState *ls)
{
  FuncState *fs; // esi
  int info; // eax
  int v5; // eax
  int n; // [esp+Ch] [ebp-4h]

  n = 1;
  subexpr(ls, v, limit: 0);
  while ( ls->t.token == 44 )
  {
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      ls->t = ls->lookahead;
      ls->lookahead.token = 287;
    }
    fs = ls->fs;
    luaK_dischargevars(fs, e: v);
    if ( v->k == VNONRELOC )
    {
      info = v->u.s.info;
      if ( (info & 0x100) == 0 && info >= fs->nactvar )
        --fs->freereg;
    }
    v5 = fs->freereg + 1;
    if ( v5 > fs->f->maxstacksize )
    {
      if ( v5 >= 250 )
        luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
      fs->f->maxstacksize = v5;
    }
    exp2reg(fs, e: v, reg: fs->freereg++);
    subexpr(ls, v, limit: 0);
    ++n;
  }
  return n;
}

//------------------------------------------------------------------------------
// Address: 0x100167B0
// Name: funcargs
// Source: json
//------------------------------------------------------------------------------
void __usercall funcargs(LexState *ls@<eax>, expdesc *f)
{
  int token; // eax
  FuncState *fs; // ebx
  int linenumber; // edi
  int info; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // ebx
  const char *v10; // eax
  const char *v11; // eax
  expdesc args; // [esp+10h] [ebp-34h] BYREF
  lua_TValue k; // [esp+28h] [ebp-1Ch] BYREF
  int v14; // [esp+3Ch] [ebp-8h]

  token = ls->t.token;
  fs = ls->fs;
  linenumber = ls->linenumber;
  v14 = linenumber;
  switch ( token )
  {
    case 40:
      if ( linenumber != ls->lastline )
        luaX_lexerror(ls, msg: "ambiguous syntax (function call x new statement)", token: 40);
      ls->lastline = linenumber;
      if ( ls->lookahead.token == 287 )
      {
        ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      }
      else
      {
        *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
        ls->t.seminfo.r = ls->lookahead.seminfo.r;
        ls->lookahead.token = 287;
      }
      if ( ls->t.token == 41 )
      {
        args.k = VVOID;
      }
      else
      {
        explist1(v: &args, ls);
        luaK_setreturns(fs, e: &args, nresults: -1);
      }
      if ( ls->t.token != 41 )
      {
        if ( linenumber == ls->linenumber )
          error_expected(ls, token: 41);
        if ( iscntrl(c: 40) != 0 )
          v8 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", 40);
        else
          v8 = luaO_pushfstring(L: ls->L, fmt: "%c", 40);
        v9 = v8;
        if ( iscntrl(c: 41) != 0 )
          v10 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", 41);
        else
          v10 = luaO_pushfstring(L: ls->L, fmt: "%c", 41);
        v11 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", v10, v9, linenumber);
        luaX_lexerror(ls, msg: v11, token: ls->t.token);
      }
      ls->lastline = ls->linenumber;
      if ( ls->lookahead.token == 287 )
      {
        ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      }
      else
      {
        *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
        ls->t.seminfo.r = ls->lookahead.seminfo.r;
        ls->lookahead.token = 287;
      }
      break;
    case 123:
      constructor(t: &args, ls);
      break;
    case 286:
      k.value.b = (int)ls->t.seminfo.ts;
      k.tt = 4;
      args.t = -1;
      args.f = -1;
      args.k = VK;
      args.u.s.info = addk(&k, fs, v: &k);
      luaX_next(ls);
      break;
    default:
      luaX_lexerror(ls, msg: "function arguments expected", token);
  }
  info = f->u.s.info;
  if ( args.k == VCALL || args.k == VVARARG )
  {
    v7 = -1;
  }
  else
  {
    if ( args.k != VVOID )
      luaK_exp2nextreg(fs, e: &args);
    v7 = fs->freereg - info - 1;
  }
  f->u.s.info = luaK_code(fs, i: (info << 6) | ((v7 + 1) << 23) | 0x801C, line: fs->ls->lastline);
  f->t = -1;
  f->f = -1;
  f->k = VCALL;
  fs->f->lineinfo[fs->pc - 1] = v14;
  fs->freereg = info + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10016A00
// Name: prefixexp
// Source: json
//------------------------------------------------------------------------------
void __usercall prefixexp(LexState *ls@<ecx>, expdesc *v@<eax>)
{
  int token; // eax
  GCObject *v5; // eax
  FuncState *v6; // esi
  int v7; // ebx
  FuncState *fs; // eax
  const char *v9; // eax
  const char *v10; // edi
  const char *v11; // eax
  const char *v12; // eax
  int linenumber; // [esp+Ch] [ebp-14h]
  lua_TValue k; // [esp+10h] [ebp-10h] BYREF

  token = ls->t.token;
  if ( token == 40 )
  {
    linenumber = ls->linenumber;
    ls->lastline = linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      ls->t = ls->lookahead;
      ls->lookahead.token = 287;
    }
    subexpr(ls, v, limit: 0);
    if ( ls->t.token != 41 )
    {
      if ( linenumber == ls->linenumber )
        error_expected(ls, token: 41);
      if ( iscntrl(c: 40) != 0 )
        v9 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", 40);
      else
        v9 = luaO_pushfstring(L: ls->L, fmt: "%c", 40);
      v10 = v9;
      if ( iscntrl(c: 41) != 0 )
        v11 = luaO_pushfstring(L: ls->L, fmt: "char(%d)", 41);
      else
        v11 = luaO_pushfstring(L: ls->L, fmt: "%c", 41);
      v12 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", v11, v10, linenumber);
      luaX_lexerror(ls, msg: v12, token: ls->t.token);
    }
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      luaK_dischargevars(fs: ls->fs, e: v);
    }
    else
    {
      fs = ls->fs;
      *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
      ls->t.seminfo.r = ls->lookahead.seminfo.r;
      ls->lookahead.token = 287;
      luaK_dischargevars(fs, e: v);
    }
  }
  else
  {
    if ( token != 285 )
      luaX_lexerror(ls, msg: "unexpected symbol", token: ls->t.token);
    v5 = (GCObject *)str_checkname(ls);
    v6 = ls->fs;
    v7 = (int)v5;
    if ( singlevaraux(fs: v6, n: v5, var: v, base: 1) == 8 )
    {
      k.value.b = v7;
      k.tt = 4;
      v->u.s.info = addk(&k, fs: v6, v: &k);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016BA0
// Name: primaryexp
// Source: json
//------------------------------------------------------------------------------
void __usercall primaryexp(expdesc *v@<eax>, LexState *ls)
{
  LexState *v2; // esi
  FuncState *fs; // ebx
  unsigned int v5; // eax
  TString *v6; // eax
  FuncState *v7; // ecx
  int info; // eax
  int v9; // eax
  expdesc key; // [esp+10h] [ebp-2Ch] BYREF
  lua_TValue k; // [esp+28h] [ebp-14h] BYREF

  v2 = ls;
  fs = ls->fs;
  prefixexp(ls, v);
  v5 = ls->t.token - 40;
  while ( 2 )
  {
    switch ( v5 )
    {
      case 0u:
      case 0x53u:
      case 0xF6u:
        luaK_dischargevars(fs, e: v);
        if ( v->k == VNONRELOC )
        {
          info = v->u.s.info;
          if ( (info & 0x100) == 0 && info >= fs->nactvar )
            --fs->freereg;
        }
        v9 = fs->freereg + 1;
        if ( v9 > fs->f->maxstacksize )
        {
          if ( v9 >= 250 )
            luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
          fs->f->maxstacksize = v9;
        }
        exp2reg(fs, e: v, reg: fs->freereg++);
        goto LABEL_22;
      case 6u:
        field(ls: v2, v);
        goto LABEL_23;
      case 0x12u:
        v2->lastline = v2->linenumber;
        if ( v2->lookahead.token == 287 )
        {
          v2->t.token = llex(ls: v2, seminfo: &v2->t.seminfo);
        }
        else
        {
          *(_QWORD *)&v2->t.token = *(_QWORD *)&v2->lookahead.token;
          v2->t.seminfo.r = v2->lookahead.seminfo.r;
          v2->lookahead.token = 287;
        }
        v6 = str_checkname(ls: v2);
        v2 = ls;
        v7 = ls->fs;
        k.value.b = (int)v6;
        key.t = -1;
        key.f = -1;
        k.tt = 4;
        key.k = VK;
        key.u.s.info = addk(&k, fs: v7, v: &k);
        luaK_self(fs, e: v, &key);
LABEL_22:
        funcargs(ls: v2, f: v);
        goto LABEL_23;
      case 0x33u:
        luaK_dischargevars(fs, e: v);
        if ( v->k != VNONRELOC )
          goto LABEL_8;
        if ( v->t != v->f )
        {
          if ( v->u.s.info < fs->nactvar )
LABEL_8:
            luaK_exp2nextreg(fs, e: v);
          else
            exp2reg(fs, e: v, reg: v->u.s.info);
        }
        yindex(ls: v2, v: &key);
        v2 = ls;
        v->u.s.aux = luaK_exp2RK(fs, e: &key);
        v->k = VINDEXED;
LABEL_23:
        v5 = v2->t.token - 40;
        if ( v5 <= 0xF6 )
          continue;
        return;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016E50
// Name: simpleexp
// Source: json
//------------------------------------------------------------------------------
void __usercall simpleexp(expdesc *v@<edi>, LexState *ls)
{
  FuncState *fs; // esi
  int v3; // eax

  switch ( ls->t.token )
  {
    case 0x7B:
      constructor(t: v, ls);
      return;
    case 0x107:
      v->k = VFALSE;
      v->u.s.info = 0;
      goto LABEL_10;
    case 0x109:
      luaX_next(ls);
      body(ls, e: v, needself: 0, line: ls->linenumber);
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
        luaX_lexerror(ls, msg: "cannot use '...' outside a vararg function", token: ls->t.token);
      fs->f->is_vararg &= ~4u;
      v3 = luaK_code(fs, i: 0x800025u, line: fs->ls->lastline);
      v->k = VVARARG;
      v->u.s.info = v3;
LABEL_10:
      v->f = -1;
      v->t = -1;
      goto LABEL_11;
    case 0x11C:
      v->u.s.info = 0;
      v->t = -1;
      v->f = -1;
      v->k = VKNUM;
      v->u.nval = ls->t.seminfo.r;
      goto LABEL_11;
    case 0x11E:
      codestring(ls, e: v, s: ls->t.seminfo.ts);
LABEL_11:
      ls->lastline = ls->linenumber;
      if ( ls->lookahead.token == 287 )
      {
        ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      }
      else
      {
        ls->t = ls->lookahead;
        ls->lookahead.token = 287;
      }
      break;
    default:
      primaryexp(v, ls);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017060
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
// Address: 0x10017210
// Name: subexpr
// Source: json
//------------------------------------------------------------------------------
BinOpr __cdecl subexpr(LexState *ls, expdesc *v, unsigned int limit)
{
  lua_State *L; // eax
  UnOpr v5; // esi
  int token; // eax
  expdesc *v7; // edi
  BinOpr result; // eax
  FuncState *fs; // esi
  BinOpr v10; // esi
  expdesc v2; // [esp+10h] [ebp-1Ch] BYREF
  BinOpr op; // [esp+34h] [ebp+8h]

  L = ls->L;
  v5 = OPR_NOT;
  if ( ++L->nCcalls > 0xC8u )
    luaX_lexerror(ls, msg: "chunk has too many syntax levels", token: 0);
  token = ls->t.token;
  switch ( token )
  {
    case 35:
      v5 = OPR_LEN;
      break;
    case 45:
      v5 = OPR_MINUS;
      break;
    case 270:
      break;
    default:
      v7 = v;
      simpleexp(v, ls);
      goto LABEL_7;
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  v7 = v;
  subexpr(ls, v, limit: 8u);
  luaK_prefix(op: v5, e: v, fs: ls->fs);
LABEL_7:
  result = getbinopr(op: ls->t.token);
  op = result;
  if ( result != OPR_NOBINOPR )
  {
    do
    {
      if ( priority[result].left <= limit )
        break;
      ls->lastline = ls->linenumber;
      if ( ls->lookahead.token == 287 )
      {
        ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
      }
      else
      {
        *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
        ls->t.seminfo.r = ls->lookahead.seminfo.r;
        ls->lookahead.token = 287;
      }
      fs = ls->fs;
      switch ( op )
      {
        case OPR_ADD:
        case OPR_SUB:
        case OPR_MUL:
        case OPR_DIV:
        case OPR_MOD:
        case OPR_POW:
          if ( v7->k != VKNUM || v7->t != -1 || v7->f != -1 )
            goto LABEL_25;
          break;
        case OPR_CONCAT:
          luaK_exp2nextreg(fs: ls->fs, e: v7);
          break;
        case OPR_AND:
          luaK_goiftrue(fs, e: v7);
          break;
        case OPR_OR:
          luaK_goiffalse(fs, e: v7);
          break;
        default:
LABEL_25:
          luaK_exp2RK(fs, e: v7);
          break;
      }
      v10 = subexpr(ls, v: &v2, limit: priority[op].right);
      luaK_posfix(op, e2: &v2, fs: ls->fs, e1: v7);
      op = v10;
      result = v10;
    }
    while ( v10 != OPR_NOBINOPR );
  }
  --ls->L->nCcalls;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017400
// Name: block
// Source: json
//------------------------------------------------------------------------------
void __usercall block(LexState *ls@<eax>)
{
  FuncState *fs; // esi
  BlockCnt *bl; // edi
  LexState *v3; // eax
  int pc; // edx
  int breaklist; // ecx
  BlockCnt v6; // [esp+Ch] [ebp-Ch] BYREF

  fs = ls->fs;
  v6.breaklist = -1;
  v6.isbreakable = 0;
  v6.nactvar = fs->nactvar;
  v6.upval = 0;
  v6.previous = fs->bl;
  fs->bl = &v6;
  chunk(ls);
  bl = fs->bl;
  v3 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v3, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  pc = fs->pc;
  fs->freereg = fs->nactvar;
  breaklist = bl->breaklist;
  fs->lasttarget = pc;
  luaK_concat(l1: &fs->jpc, l2: breaklist, fs);
}

//------------------------------------------------------------------------------
// Address: 0x10017490
// Name: check_conflict
// Source: json
//------------------------------------------------------------------------------
void __usercall check_conflict(LexState *ls@<ecx>, LHS_assign *lh@<eax>, expdesc *v@<edi>)
{
  FuncState *fs; // esi
  int freereg; // edx
  int v5; // ecx
  int v6; // eax

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
      luaK_code(fs, i: (fs->freereg | (v->u.s.info << 17)) << 6, line: fs->ls->lastline);
      v6 = fs->freereg + 1;
      if ( v6 > fs->f->maxstacksize )
      {
        if ( v6 >= 250 )
          luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
        fs->f->maxstacksize = v6;
      }
      ++fs->freereg;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017520
// Name: assignment
// Source: json
//------------------------------------------------------------------------------
void __cdecl assignment(LexState *ls, LHS_assign *lh, int nvars)
{
  int v4; // edx
  int v5; // ebx
  FuncState *fs; // esi
  LHS_assign nv; // [esp+10h] [ebp-3Ch] BYREF
  expdesc e; // [esp+30h] [ebp-1Ch] BYREF
  expdesc *lha; // [esp+58h] [ebp+Ch]

  lha = &lh->v;
  if ( lha->k < VLOCAL || lha->k > VINDEXED )
    luaX_lexerror(ls, msg: "syntax error", token: ls->t.token);
  if ( ls->t.token == 44 && testnext(ls) != 0 )
  {
    nv.prev = lh;
    primaryexp(v: &nv.v, ls);
    if ( nv.v.k == VLOCAL )
      check_conflict(ls, lh, v: &nv.v);
    v4 = 200 - ls->L->nCcalls;
    if ( nvars > v4 )
      errorlimit(fs: ls->fs, limit: v4, what: "variables in assignment");
    assignment(ls, lh: &nv, nvars: nvars + 1);
LABEL_13:
    fs = ls->fs;
    e.u.s.info = fs->freereg - 1;
    e.t = -1;
    e.f = -1;
    e.k = VNONRELOC;
    luaK_storevar(fs, ex: &e, var: lha);
    return;
  }
  checknext(ls, c: 61);
  v5 = explist1(v: &e, ls);
  if ( v5 != nvars )
  {
    adjust_assign(ls, &e, nvars, nexps: v5);
    if ( v5 > nvars )
      ls->fs->freereg += nvars - v5;
    goto LABEL_13;
  }
  luaK_setoneret(fs: ls->fs, &e);
  luaK_storevar(fs: ls->fs, ex: &e, var: lha);
}

//------------------------------------------------------------------------------
// Address: 0x10017650
// Name: breakstat
// Source: json
//------------------------------------------------------------------------------
void __thiscall breakstat(LexState *ls)
{
  FuncState *fs; // esi
  BlockCnt *bl; // edi
  int v3; // eax
  int upval; // edx
  int jpc; // ebx
  LexState *v6; // ecx
  int l1; // [esp+Ch] [ebp-4h] BYREF

  fs = ls->fs;
  bl = fs->bl;
  v3 = 0;
  if ( bl == nullptr )
LABEL_4:
    luaX_lexerror(ls, msg: "no loop to break", token: ls->t.token);
  while ( bl->isbreakable == 0 )
  {
    upval = bl->upval;
    bl = bl->previous;
    v3 |= upval;
    if ( bl == nullptr )
      goto LABEL_4;
  }
  if ( v3 != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  jpc = fs->jpc;
  v6 = fs->ls;
  fs->jpc = -1;
  l1 = luaK_code(fs, i: 0x7FFF8016u, line: v6->lastline);
  luaK_concat(&l1, l2: jpc, fs);
  luaK_concat(l1: &bl->breaklist, l2: l1, fs);
}

//------------------------------------------------------------------------------
// Address: 0x100176F0
// Name: whilestat
// Source: json
//------------------------------------------------------------------------------
void __cdecl whilestat(LexState *ls, int line)
{
  FuncState *fs; // edi
  int pc; // eax
  const char *v4; // eax
  int jpc; // edx
  LexState *v6; // eax
  int v7; // eax
  int v8; // ecx
  BlockCnt *bl; // ebx
  int v10; // edx
  int breaklist; // ecx
  int f; // ecx
  const char *v13; // eax
  const char *v14; // eax
  int lastline; // [esp-4h] [ebp-44h]
  int l1; // [esp+10h] [ebp-30h] BYREF
  int l2; // [esp+14h] [ebp-2Ch]
  int whileinit; // [esp+18h] [ebp-28h]
  BlockCnt v19; // [esp+1Ch] [ebp-24h] BYREF
  expdesc v; // [esp+28h] [ebp-18h] BYREF

  ls->lastline = ls->linenumber;
  fs = ls->fs;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  pc = fs->pc;
  fs->lasttarget = pc;
  whileinit = pc;
  subexpr(ls, &v, limit: 0);
  if ( v.k == VNIL )
    v.k = VFALSE;
  luaK_goiftrue(fs: ls->fs, e: &v);
  v19.breaklist = -1;
  v19.isbreakable = 1;
  v19.nactvar = fs->nactvar;
  v19.upval = 0;
  v19.previous = fs->bl;
  fs->bl = &v19;
  if ( ls->t.token != 259 )
  {
    v4 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "do");
    luaX_lexerror(ls, msg: v4, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  block(ls);
  jpc = fs->jpc;
  v6 = fs->ls;
  fs->jpc = -1;
  lastline = v6->lastline;
  l2 = jpc;
  l1 = luaK_code(fs, i: 0x7FFF8016u, line: lastline);
  luaK_concat(&l1, l2, fs);
  v7 = fs->pc;
  if ( whileinit == v7 )
  {
    v8 = l1;
    fs->lasttarget = v7;
    luaK_concat(l1: &fs->jpc, l2: v8, fs);
  }
  else
  {
    patchlistaux(list: l1, fs, vtarget: whileinit, reg: 255, dtarget: whileinit);
  }
  if ( ls->t.token != 262 )
  {
    if ( line == ls->linenumber )
    {
      v13 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "end");
      luaX_lexerror(ls, msg: v13, token: ls->t.token);
    }
    v14 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", "end", "while", line);
    luaX_lexerror(ls, msg: v14, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  bl = fs->bl;
  fs->bl = bl->previous;
  removevars(ls: fs->ls, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  v10 = fs->pc;
  fs->freereg = fs->nactvar;
  breaklist = bl->breaklist;
  fs->lasttarget = v10;
  luaK_concat(l1: &fs->jpc, l2: breaklist, fs);
  f = v.f;
  fs->lasttarget = fs->pc;
  luaK_concat(l1: &fs->jpc, l2: f, fs);
}

//------------------------------------------------------------------------------
// Address: 0x10017980
// Name: repeatstat
// Source: json
//------------------------------------------------------------------------------
void __cdecl repeatstat(LexState *ls, int line)
{
  FuncState *fs; // edi
  int pc; // eax
  FuncState *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int f; // ecx
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  FuncState *v11; // ecx
  int jpc; // ecx
  LexState *v13; // edx
  int v14; // eax
  int v15; // ecx
  BlockCnt *bl; // ebx
  LexState *v17; // eax
  int v18; // eax
  int breaklist; // ecx
  int lastline; // [esp-4h] [ebp-4Ch]
  int l1; // [esp+Ch] [ebp-3Ch] BYREF
  int vtarget; // [esp+10h] [ebp-38h]
  int l2; // [esp+14h] [ebp-34h]
  BlockCnt bl2; // [esp+18h] [ebp-30h] BYREF
  BlockCnt bl1; // [esp+24h] [ebp-24h] BYREF
  expdesc v; // [esp+30h] [ebp-18h] BYREF

  fs = ls->fs;
  pc = fs->pc;
  fs->lasttarget = pc;
  bl1.isbreakable = 1;
  vtarget = pc;
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
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  chunk(ls);
  if ( ls->t.token != 276 )
  {
    if ( line == ls->linenumber )
    {
      v8 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "until");
      luaX_lexerror(ls, msg: v8, token: ls->t.token);
    }
    v9 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", "until", "repeat", line);
    luaX_lexerror(ls, msg: v9, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  subexpr(ls, &v, limit: 0);
  if ( v.k == VNIL )
    v.k = VFALSE;
  luaK_goiftrue(fs: ls->fs, e: &v);
  if ( bl2.upval != 0 )
  {
    breakstat(ls);
    v11 = ls->fs;
    v11->lasttarget = v11->pc;
    luaK_concat(l1: &v11->jpc, l2: v.f, fs: v11);
    leaveblock(fs);
    jpc = fs->jpc;
    v13 = fs->ls;
    fs->jpc = -1;
    lastline = v13->lastline;
    l2 = jpc;
    l1 = luaK_code(fs, i: 0x7FFF8016u, line: lastline);
    luaK_concat(&l1, l2, fs);
    v4 = ls->fs;
    v14 = v4->pc;
    v6 = vtarget;
    if ( vtarget == v14 )
    {
      v15 = l1;
      v4->lasttarget = v14;
      luaK_concat(l1: &v4->jpc, l2: v15, fs: v4);
      goto LABEL_21;
    }
    v10 = l1;
  }
  else
  {
    leaveblock(fs);
    v4 = ls->fs;
    v5 = v4->pc;
    v6 = vtarget;
    if ( vtarget == v5 )
    {
      f = v.f;
      v4->lasttarget = v5;
      luaK_concat(l1: &v4->jpc, l2: f, fs: v4);
      goto LABEL_21;
    }
    v10 = v.f;
  }
  patchlistaux(list: v10, fs: v4, vtarget: v6, reg: 255, dtarget: v6);
LABEL_21:
  bl = fs->bl;
  v17 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v17, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  v18 = fs->pc;
  fs->freereg = fs->nactvar;
  breaklist = bl->breaklist;
  fs->lasttarget = v18;
  luaK_concat(l1: &fs->jpc, l2: breaklist, fs);
}

//------------------------------------------------------------------------------
// Address: 0x10017C20
// Name: forbody
// Source: json
//------------------------------------------------------------------------------
void __cdecl forbody(LexState *ls, int base, int line, int nvars, int isnum)
{
  int v5; // ebx
  LexState *v6; // edi
  FuncState *fs; // esi
  int v8; // eax
  bool v9; // zf
  const char *v10; // eax
  int jpc; // edx
  LexState *v12; // eax
  FuncState *v13; // eax
  int v14; // ecx
  int v15; // eax
  BlockCnt *bl; // edi
  LexState *v17; // eax
  int pc; // eax
  int breaklist; // ecx
  LexState *v20; // eax
  int v21; // ebx
  LexState *v22; // edx
  int v23; // ecx
  int lastline; // [esp-4h] [ebp-28h]
  BlockCnt v25; // [esp+10h] [ebp-14h] BYREF
  int prep; // [esp+1Ch] [ebp-8h] BYREF
  int l2; // [esp+20h] [ebp-4h]

  v5 = nvars;
  v6 = ls;
  fs = ls->fs;
  fs->nactvar += 3;
  l2 = 3;
  do
  {
    v8 = fs->nactvar - l2;
    v9 = l2-- == 1;
    fs->f->locvars[fs->actvar[v8]].startpc = fs->pc;
  }
  while ( !v9 );
  if ( v6->t.token != 259 )
  {
    v10 = luaO_pushfstring(L: v6->L, fmt: "'%s' expected", "do");
    luaX_lexerror(ls: v6, msg: v10, token: v6->t.token);
  }
  v6->lastline = v6->linenumber;
  if ( v6->lookahead.token == 287 )
  {
    v6->t.token = llex(ls: v6, seminfo: &v6->t.seminfo);
  }
  else
  {
    *(_QWORD *)&v6->t.token = *(_QWORD *)&v6->lookahead.token;
    v6->t.seminfo.r = v6->lookahead.seminfo.r;
    v6->lookahead.token = 287;
  }
  if ( isnum != 0 )
  {
    prep = luaK_code(fs, i: (base << 6) | 0x7FFF8020, line: fs->ls->lastline);
  }
  else
  {
    jpc = fs->jpc;
    v12 = fs->ls;
    fs->jpc = -1;
    lastline = v12->lastline;
    l2 = jpc;
    prep = luaK_code(fs, i: 0x7FFF8016u, line: lastline);
    luaK_concat(l1: &prep, l2, fs);
  }
  v25.breaklist = -1;
  v25.isbreakable = 0;
  v25.nactvar = fs->nactvar;
  v25.upval = 0;
  v25.previous = fs->bl;
  fs->bl = &v25;
  v13 = v6->fs;
  v13->nactvar += v5;
  l2 = v5;
  if ( v5 != 0 )
  {
    do
    {
      v14 = v13->nactvar - l2;
      v9 = l2-- == 1;
      v13->f->locvars[v13->actvar[v14]].startpc = v13->pc;
    }
    while ( !v9 );
    v6 = ls;
  }
  v15 = v5 + fs->freereg;
  if ( v15 > fs->f->maxstacksize )
  {
    if ( v15 >= 250 )
      luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
    fs->f->maxstacksize = v15;
  }
  fs->freereg += v5;
  block(ls: v6);
  bl = fs->bl;
  v17 = fs->ls;
  fs->bl = bl->previous;
  removevars(ls: v17, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  pc = fs->pc;
  fs->freereg = fs->nactvar;
  breaklist = bl->breaklist;
  fs->lasttarget = pc;
  luaK_concat(l1: &fs->jpc, l2: breaklist, fs);
  fs->lasttarget = fs->pc;
  luaK_concat(l1: &fs->jpc, l2: prep, fs);
  if ( isnum != 0 )
    v20 = (LexState *)luaK_code(fs, i: (base << 6) | 0x7FFF801F, line: fs->ls->lastline);
  else
    v20 = (LexState *)luaK_code(fs, i: ((base | (v5 << 8)) << 6) | 0x21, line: fs->ls->lastline);
  v9 = isnum == 0;
  fs->f->lineinfo[fs->pc - 1] = line;
  if ( v9 )
  {
    v21 = fs->jpc;
    v22 = fs->ls;
    fs->jpc = -1;
    ls = (LexState *)luaK_code(fs, i: 0x7FFF8016u, line: v22->lastline);
    luaK_concat(l1: (int *)&ls, l2: v21, fs);
    v20 = ls;
  }
  v23 = fs->pc;
  if ( prep + 1 == v23 )
  {
    fs->lasttarget = v23;
    luaK_concat(l1: &fs->jpc, l2: (int)v20, fs);
  }
  else
  {
    patchlistaux(list: (int)v20, fs, vtarget: prep + 1, reg: 255, dtarget: prep + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017ED0
// Name: fornum
// Source: json
//------------------------------------------------------------------------------
void __cdecl fornum(LexState *ls, GCObject *varname, int line)
{
  lua_State *L; // edi
  GCObject *v4; // esi
  lua_TValue *v5; // eax
  FuncState *v6; // edi
  lua_State *v7; // edi
  GCObject *v8; // esi
  lua_TValue *v9; // eax
  FuncState *v10; // edi
  lua_State *v11; // esi
  GCObject *v12; // edi
  lua_TValue *v13; // eax
  FuncState *v14; // esi
  FuncState *v15; // esi
  int v16; // eax
  int v17; // eax
  Table *t; // [esp+Ch] [ebp-24h]
  Table *ta; // [esp+Ch] [ebp-24h]
  Table *tb; // [esp+Ch] [ebp-24h]
  FuncState *fs; // [esp+10h] [ebp-20h]
  int base; // [esp+14h] [ebp-1Ch]
  expdesc key; // [esp+18h] [ebp-18h] BYREF

  L = ls->L;
  fs = ls->fs;
  base = fs->freereg;
  v4 = (GCObject *)luaS_newlstr(L, str: "(for index)", l: 0xBu);
  t = ls->fs->h;
  v5 = (lua_TValue *)luaH_getstr(t, key: (TString *)v4);
  if ( v5 == &luaO_nilobject_ )
  {
    key.k = (expkind)v4;
    key.u.s.info = 4;
    v5 = newkey(L, t, (const lua_TValue *)&key);
  }
  if ( v5->tt == 0 )
  {
    v5->value.b = 1;
    v5->tt = 1;
  }
  v6 = ls->fs;
  if ( (unsigned int)v6->nactvar + 1 > 0xC8 )
    errorlimit(fs: ls->fs, limit: 200, what: "local variables");
  v6->actvar[v6->nactvar] = registerlocalvar(ls, varname: v4);
  v7 = ls->L;
  v8 = (GCObject *)luaS_newlstr(L: v7, str: "(for limit)", l: 0xBu);
  ta = ls->fs->h;
  v9 = (lua_TValue *)luaH_getstr(t: ta, key: (TString *)v8);
  if ( v9 == &luaO_nilobject_ )
  {
    key.k = (expkind)v8;
    key.u.s.info = 4;
    v9 = newkey(L: v7, t: ta, (const lua_TValue *)&key);
  }
  if ( v9->tt == 0 )
  {
    v9->value.b = 1;
    v9->tt = 1;
  }
  v10 = ls->fs;
  if ( (unsigned int)v10->nactvar + 2 > 0xC8 )
    errorlimit(fs: ls->fs, limit: 200, what: "local variables");
  v10->actvar[v10->nactvar + 1] = registerlocalvar(ls, varname: v8);
  v11 = ls->L;
  v12 = (GCObject *)luaS_newlstr(L: v11, str: "(for step)", l: 0xAu);
  tb = ls->fs->h;
  v13 = (lua_TValue *)luaH_getstr(t: tb, key: (TString *)v12);
  if ( v13 == &luaO_nilobject_ )
  {
    key.k = (expkind)v12;
    key.u.s.info = 4;
    v13 = newkey(L: v11, t: tb, (const lua_TValue *)&key);
  }
  if ( v13->tt == 0 )
  {
    v13->value.b = 1;
    v13->tt = 1;
  }
  v14 = ls->fs;
  if ( (unsigned int)v14->nactvar + 3 > 0xC8 )
    errorlimit(fs: v14, limit: 200, what: "local variables");
  v14->actvar[v14->nactvar + 2] = registerlocalvar(ls, varname: v12);
  v15 = ls->fs;
  if ( (unsigned int)v15->nactvar + 4 > 0xC8 )
    errorlimit(fs: v15, limit: 200, what: "local variables");
  v15->actvar[v15->nactvar + 3] = registerlocalvar(ls, varname);
  if ( ls->t.token != 61 )
    error_expected(ls, token: 61);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  subexpr(ls, v: &key, limit: 0);
  luaK_exp2nextreg(fs: ls->fs, e: &key);
  if ( ls->t.token != 44 )
    error_expected(ls, token: 44);
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  subexpr(ls, v: &key, limit: 0);
  luaK_exp2nextreg(fs: ls->fs, e: &key);
  if ( ls->t.token == 44 )
  {
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      ls->t = ls->lookahead;
      ls->lookahead.token = 287;
    }
    subexpr(ls, v: &key, limit: 0);
    luaK_exp2nextreg(fs: ls->fs, e: &key);
  }
  else
  {
    *(_QWORD *)&key.k = 0x3FF0000000000000LL;
    key.u.s.info = 3;
    v16 = addk(k: (lua_TValue *)&key, fs, v: (lua_TValue *)&key);
    luaK_code(fs, i: ((fs->freereg | (v16 << 8)) << 6) | 1, line: fs->ls->lastline);
    v17 = fs->freereg + 1;
    if ( v17 > fs->f->maxstacksize )
    {
      if ( v17 >= 250 )
        luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
      fs->f->maxstacksize = v17;
    }
    ++fs->freereg;
  }
  forbody(ls, base, line, nvars: 1, isnum: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100182A0
// Name: forlist
// Source: json
//------------------------------------------------------------------------------
void __usercall forlist(LexState *ls@<edi>, GCObject *indexname)
{
  lua_State *L; // ebx
  GCObject *v3; // esi
  lua_TValue *v4; // eax
  FuncState *v5; // ebx
  lua_State *v6; // esi
  GCObject *v7; // ebx
  lua_TValue *v8; // eax
  FuncState *v9; // esi
  lua_State *v10; // esi
  GCObject *v11; // ebx
  lua_TValue *v12; // eax
  FuncState *v13; // esi
  FuncState *v14; // esi
  int v15; // ebx
  int linenumber; // edx
  const char *v17; // edx
  const char *v18; // eax
  int v19; // eax
  int v20; // eax
  expdesc e; // [esp+8h] [ebp-3Ch] BYREF
  lua_TValue key; // [esp+20h] [ebp-24h] BYREF
  int base; // [esp+34h] [ebp-10h]
  FuncState *fs; // [esp+38h] [ebp-Ch]
  int line; // [esp+3Ch] [ebp-8h]

  L = ls->L;
  fs = ls->fs;
  base = fs->freereg;
  v3 = (GCObject *)luaS_newlstr(L, str: "(for generator)", l: 0xFu);
  line = (int)ls->fs->h;
  v4 = (lua_TValue *)luaH_getstr(t: (Table *)line, key: (TString *)v3);
  if ( v4 == &luaO_nilobject_ )
  {
    key.value.b = (int)v3;
    key.tt = 4;
    v4 = newkey(L, t: (Table *)line, &key);
  }
  if ( v4->tt == 0 )
  {
    v4->value.b = 1;
    v4->tt = 1;
  }
  v5 = ls->fs;
  if ( (unsigned int)v5->nactvar + 1 > 0xC8 )
    errorlimit(fs: ls->fs, limit: 200, what: "local variables");
  v5->actvar[v5->nactvar] = registerlocalvar(ls, varname: v3);
  v6 = ls->L;
  v7 = (GCObject *)luaS_newlstr(L: v6, str: "(for state)", l: 0xBu);
  line = (int)ls->fs->h;
  v8 = (lua_TValue *)luaH_getstr(t: (Table *)line, key: (TString *)v7);
  if ( v8 == &luaO_nilobject_ )
  {
    key.value.b = (int)v7;
    key.tt = 4;
    v8 = newkey(L: v6, t: (Table *)line, &key);
  }
  if ( v8->tt == 0 )
  {
    v8->value.b = 1;
    v8->tt = 1;
  }
  v9 = ls->fs;
  if ( (unsigned int)v9->nactvar + 2 > 0xC8 )
LABEL_12:
    errorlimit(fs: v9, limit: 200, what: "local variables");
  v9->actvar[v9->nactvar + 1] = registerlocalvar(ls, varname: v7);
  v10 = ls->L;
  v11 = (GCObject *)luaS_newlstr(L: v10, str: "(for control)", l: 0xDu);
  line = (int)ls->fs->h;
  v12 = (lua_TValue *)luaH_getstr(t: (Table *)line, key: (TString *)v11);
  if ( v12 == &luaO_nilobject_ )
  {
    key.value.b = (int)v11;
    key.tt = 4;
    v12 = newkey(L: v10, t: (Table *)line, &key);
  }
  if ( v12->tt == 0 )
  {
    v12->value.b = 1;
    v12->tt = 1;
  }
  v13 = ls->fs;
  if ( (unsigned int)v13->nactvar + 3 > 0xC8 )
    errorlimit(fs: v13, limit: 200, what: "local variables");
  v13->actvar[v13->nactvar + 2] = registerlocalvar(ls, varname: v11);
  v14 = ls->fs;
  if ( (unsigned int)v14->nactvar + 4 > 0xC8 )
    errorlimit(fs: v14, limit: 200, what: "local variables");
  v14->actvar[v14->nactvar + 3] = registerlocalvar(ls, varname: indexname);
  v15 = 4;
  while ( ls->t.token == 44 )
  {
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      ls->t = ls->lookahead;
      ls->lookahead.token = 287;
    }
    if ( ls->t.token != 285 )
    {
      v17 = "<name>";
      goto LABEL_33;
    }
    linenumber = ls->linenumber;
    line = (int)ls->t.seminfo.ts;
    ls->lastline = linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      ls->t = ls->lookahead;
      ls->lookahead.token = 287;
    }
    v9 = ls->fs;
    if ( v9->nactvar + v15 + 1 > 200 )
      goto LABEL_12;
    v9->actvar[v15 + v9->nactvar] = registerlocalvar(ls, varname: (GCObject *)line);
    ++v15;
  }
  if ( ls->t.token != 267 )
  {
    v17 = "in";
LABEL_33:
    v18 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", v17);
    luaX_lexerror(ls, msg: v18, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  line = ls->linenumber;
  v19 = explist1(v: &e, ls);
  adjust_assign(ls, &e, nvars: 3, nexps: v19);
  v20 = fs->freereg + 3;
  if ( v20 > fs->f->maxstacksize )
  {
    if ( v20 >= 250 )
      luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
    fs->f->maxstacksize = v20;
  }
  forbody(ls, base, line, nvars: v15 - 3, isnum: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10018650
// Name: forstat
// Source: json
//------------------------------------------------------------------------------
void __usercall forstat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // ebx
  GCObject *v4; // eax
  int token; // ecx
  int v6; // edi
  BlockCnt *bl; // edi
  int pc; // edx
  int breaklist; // ecx
  const char *v10; // eax
  const char *v11; // eax
  BlockCnt v12; // [esp+10h] [ebp-Ch] BYREF

  fs = ls->fs;
  v12.breaklist = -1;
  v12.isbreakable = 1;
  v12.nactvar = fs->nactvar;
  v12.upval = 0;
  v12.previous = fs->bl;
  fs->bl = &v12;
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  v4 = (GCObject *)str_checkname(ls);
  token = ls->t.token;
  if ( token != 44 )
  {
    if ( token == 61 )
    {
      v6 = line;
      fornum(ls, varname: v4, line);
      goto LABEL_10;
    }
    if ( token != 267 )
      luaX_lexerror(ls, msg: "'=' or 'in' expected", token: ls->t.token);
  }
  forlist(ls, indexname: v4);
  v6 = line;
LABEL_10:
  if ( ls->t.token != 262 )
  {
    if ( v6 == ls->linenumber )
    {
      v10 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "end");
      luaX_lexerror(ls, msg: v10, token: ls->t.token);
    }
    v11 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", "end", "for", v6);
    luaX_lexerror(ls, msg: v11, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
  bl = fs->bl;
  fs->bl = bl->previous;
  removevars(ls: fs->ls, tolevel: bl->nactvar);
  if ( bl->upval != 0 )
    luaK_code(fs, i: (bl->nactvar << 6) | 0x23, line: fs->ls->lastline);
  pc = fs->pc;
  fs->freereg = fs->nactvar;
  breaklist = bl->breaklist;
  fs->lasttarget = pc;
  luaK_concat(l1: &fs->jpc, l2: breaklist, fs);
}

//------------------------------------------------------------------------------
// Address: 0x100187F0
// Name: test_then_block
// Source: json
//------------------------------------------------------------------------------
int __usercall test_then_block@<eax>(LexState *ls@<edi>)
{
  const char *v1; // eax
  expdesc v; // [esp+8h] [ebp-18h] BYREF

  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  subexpr(ls, &v, limit: 0);
  if ( v.k == VNIL )
    v.k = VFALSE;
  luaK_goiftrue(fs: ls->fs, e: &v);
  if ( ls->t.token != 274 )
  {
    v1 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "then");
    luaX_lexerror(ls, msg: v1, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  block(ls);
  return v.f;
}

//------------------------------------------------------------------------------
// Address: 0x100188E0
// Name: ifstat
// Source: json
//------------------------------------------------------------------------------
void __usercall ifstat(LexState *ls@<eax>, int line)
{
  FuncState *fs; // esi
  int v4; // eax
  bool v5; // zf
  int jpc; // eax
  LexState *v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  LexState *v11; // edx
  const char *v12; // eax
  const char *v13; // eax
  int l2; // [esp+Ch] [ebp-10h]
  int l2a; // [esp+Ch] [ebp-10h]
  int l1; // [esp+10h] [ebp-Ch] BYREF
  int escapelist; // [esp+14h] [ebp-8h] BYREF
  int flist; // [esp+18h] [ebp-4h]

  fs = ls->fs;
  escapelist = -1;
  v4 = test_then_block(ls);
  v5 = ls->t.token == 261;
  for ( flist = v4; v5; flist = v9 )
  {
    jpc = fs->jpc;
    v7 = fs->ls;
    fs->jpc = -1;
    l2 = jpc;
    l1 = luaK_code(fs, i: 0x7FFF8016u, line: v7->lastline);
    luaK_concat(&l1, l2, fs);
    luaK_concat(l1: &escapelist, l2: l1, fs);
    v8 = flist;
    fs->lasttarget = fs->pc;
    luaK_concat(l1: &fs->jpc, l2: v8, fs);
    v9 = test_then_block(ls);
    v5 = ls->t.token == 261;
  }
  if ( ls->t.token == 260 )
  {
    v10 = fs->jpc;
    v11 = fs->ls;
    fs->jpc = -1;
    l2a = v10;
    l1 = luaK_code(fs, i: 0x7FFF8016u, line: v11->lastline);
    luaK_concat(&l1, l2: l2a, fs);
    luaK_concat(l1: &escapelist, l2: l1, fs);
    fs->lasttarget = fs->pc;
    luaK_concat(l1: &fs->jpc, l2: flist, fs);
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
      ls->t.seminfo.r = ls->lookahead.seminfo.r;
      ls->lookahead.token = 287;
    }
    block(ls);
  }
  else
  {
    luaK_concat(l1: &escapelist, l2: flist, fs);
  }
  fs->lasttarget = fs->pc;
  luaK_concat(l1: &fs->jpc, l2: escapelist, fs);
  if ( ls->t.token != 262 )
  {
    if ( line == ls->linenumber )
    {
      v12 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "end");
      luaX_lexerror(ls, msg: v12, token: ls->t.token);
    }
    v13 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected (to close '%s' at line %d)", "end", "if", line);
    luaX_lexerror(ls, msg: v13, token: ls->t.token);
  }
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
    ls->t.seminfo.r = ls->lookahead.seminfo.r;
    ls->lookahead.token = 287;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018AF0
// Name: localfunc
// Source: json
//------------------------------------------------------------------------------
void __usercall localfunc(LexState *ls@<eax>)
{
  FuncState *fs; // edi
  GCObject *v3; // eax
  FuncState *v4; // ebx
  Proto *f; // ecx
  int maxstacksize; // edx
  int v7; // eax
  FuncState *v8; // eax
  expdesc b; // [esp+10h] [ebp-30h] BYREF
  expdesc v; // [esp+28h] [ebp-18h] BYREF

  fs = ls->fs;
  v3 = (GCObject *)str_checkname(ls);
  v4 = ls->fs;
  if ( (unsigned int)v4->nactvar + 1 > 0xC8 )
    errorlimit(fs: ls->fs, limit: 200, what: "local variables");
  v4->actvar[v4->nactvar] = registerlocalvar(ls, varname: v3);
  f = fs->f;
  maxstacksize = fs->f->maxstacksize;
  v.t = -1;
  v.f = -1;
  v.u.s.info = fs->freereg;
  v7 = v.u.s.info + 1;
  v.k = VLOCAL;
  if ( v.u.s.info + 1 > maxstacksize )
  {
    if ( v7 >= 250 )
      luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
    f->maxstacksize = v7;
  }
  ++fs->freereg;
  v8 = ls->fs;
  v8->f->locvars[*(unsigned __int16 *)&v8->upvalues[++v8->nactvar + 59].info].startpc = v8->pc;
  body(ls, e: &b, needself: 0, line: ls->linenumber);
  luaK_storevar(fs, ex: &b, var: &v);
  fs->f->locvars[*(unsigned __int16 *)&fs->upvalues[fs->nactvar + 59].info].startpc = fs->pc;
}

//------------------------------------------------------------------------------
// Address: 0x10018BF0
// Name: localstat
// Source: json
//------------------------------------------------------------------------------
void __usercall localstat(LexState *ls@<eax>)
{
  int v2; // ebx
  int linenumber; // edx
  FuncState *fs; // esi
  const char *v5; // eax
  long double r; // xmm0_8
  int v7; // eax
  FuncState *v8; // edi
  int v9; // edx
  expdesc e; // [esp+10h] [ebp-20h] BYREF
  TString *varname; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  while ( 1 )
  {
    if ( ls->t.token != 285 )
    {
      v5 = luaO_pushfstring(L: ls->L, fmt: "'%s' expected", "<name>");
      luaX_lexerror(ls, msg: v5, token: ls->t.token);
    }
    linenumber = ls->linenumber;
    varname = ls->t.seminfo.ts;
    ls->lastline = linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
      ls->t.seminfo.r = ls->lookahead.seminfo.r;
      ls->lookahead.token = 287;
    }
    fs = ls->fs;
    if ( fs->nactvar + v2 + 1 > 200 )
      errorlimit(fs, limit: 200, what: "local variables");
    fs->actvar[v2 + fs->nactvar] = registerlocalvar(ls, (GCObject *)varname);
    ++v2;
    if ( ls->t.token != 44 )
      break;
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
      ls->t.seminfo.r = ls->lookahead.seminfo.r;
      ls->lookahead.token = 287;
    }
  }
  if ( ls->t.token == 61 )
  {
    ls->lastline = ls->linenumber;
    if ( ls->lookahead.token == 287 )
    {
      ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
    }
    else
    {
      *(_QWORD *)&ls->t.token = *(_QWORD *)&ls->lookahead.token;
      r = ls->lookahead.seminfo.r;
      ls->lookahead.token = 287;
      ls->t.seminfo.r = r;
    }
    v7 = explist1(v: &e, ls);
  }
  else
  {
    v7 = 0;
    e.k = VVOID;
  }
  adjust_assign(ls, &e, nvars: v2, nexps: v7);
  v8 = ls->fs;
  for ( v8->nactvar += v2; v2 != 0; v8->f->locvars[v8->actvar[v9]].startpc = v8->pc )
    v9 = v8->nactvar - v2--;
}

//------------------------------------------------------------------------------
// Address: 0x10018DA0
// Name: funcname
// Source: json
//------------------------------------------------------------------------------
int __usercall funcname@<eax>(LexState *ls@<eax>, expdesc *v@<edi>)
{
  GCObject *v3; // ebx
  lua_TValue k; // [esp+8h] [ebp-18h] BYREF
  FuncState *fs; // [esp+1Ch] [ebp-4h]

  v3 = (GCObject *)str_checkname(ls);
  fs = ls->fs;
  if ( singlevaraux(fs, n: v3, var: v, base: 1) == 8 )
  {
    k.value.b = (int)v3;
    k.tt = 4;
    v->u.s.info = addk(&k, fs, v: &k);
  }
  while ( ls->t.token == 46 )
    field(ls, v);
  if ( ls->t.token != 58 )
    return 0;
  field(ls, v);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018E30
// Name: funcstat
// Source: json
//------------------------------------------------------------------------------
void __usercall funcstat(LexState *ls@<eax>, int line)
{
  int v3; // eax
  expdesc b; // [esp+10h] [ebp-34h] BYREF
  expdesc v; // [esp+28h] [ebp-1Ch] BYREF

  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  v3 = funcname(ls, &v);
  body(ls, e: &b, needself: v3, line);
  luaK_storevar(fs: ls->fs, ex: &b, var: &v);
  ls->fs->f->lineinfo[ls->fs->pc - 1] = line;
}

//------------------------------------------------------------------------------
// Address: 0x10018EC0
// Name: retstat
// Source: json
//------------------------------------------------------------------------------
void __usercall retstat(LexState *ls@<eax>)
{
  FuncState *fs; // esi
  int token; // ecx
  int v4; // edi
  int nactvar; // eax
  unsigned int *v6; // eax
  expdesc e; // [esp+8h] [ebp-18h] BYREF

  fs = ls->fs;
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
  token = ls->t.token;
  switch ( token )
  {
    case 260:
    case 261:
    case 262:
    case 276:
    case 287:
      goto $LN8_10;
    default:
      if ( token == 59 )
      {
$LN8_10:
        v4 = 0;
        nactvar = 0;
      }
      else
      {
        v4 = explist1(v: &e, ls);
        if ( e.k == VCALL || e.k == VVARARG )
        {
          luaK_setreturns(fs, &e, nresults: -1);
          if ( e.k == VCALL && v4 == 1 )
          {
            v6 = &fs->f->code[e.u.s.info];
            *v6 = *v6 & 0xFFFFFFC0 | 0x1D;
          }
          nactvar = fs->nactvar;
          v4 = -1;
        }
        else if ( v4 == 1 )
        {
          nactvar = luaK_exp2anyreg(fs, &e);
        }
        else
        {
          luaK_exp2nextreg(fs, &e);
          nactvar = fs->nactvar;
        }
      }
      luaK_code(fs, i: (nactvar << 6) | ((v4 + 1) << 23) | 0x1E, line: fs->ls->lastline);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018FF0
// Name: statement
// Source: json
//------------------------------------------------------------------------------
int __usercall statement@<eax>(LexState *ls@<eax>)
{
  int linenumber; // edi
  int result; // eax
  FuncState *fs; // edi
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
      check_match(where: linenumber, ls, what: 262, who: 259);
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
      if ( ls->t.token == 265 && testnext(ls) != 0 )
      {
        localfunc(ls);
        result = 0;
      }
      else
      {
        localstat(ls);
        result = 0;
      }
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
      primaryexp(v: &lh.v, ls);
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
// Address: 0x100191A0
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
        {
          ls->lastline = ls->linenumber;
          if ( ls->lookahead.token == 287 )
          {
            ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
          }
          else
          {
            ls->t = ls->lookahead;
            ls->lookahead.token = 287;
          }
        }
        ls->fs->freereg = ls->fs->nactvar;
        if ( v2 == 0 )
          continue;
        break;
    }
    break;
  }
  --ls->L->nCcalls;
}
