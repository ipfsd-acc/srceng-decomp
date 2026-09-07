// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lcode.c
// Functions: 33
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10005C40
// Name: _luaK_nil
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_nil(FuncState *fs@<eax>, int from@<ecx>, int n)
{
  int pc; // eax
  unsigned int *v5; // edi
  unsigned int v6; // eax
  int v7; // edx

  pc = fs->pc;
  if ( pc <= fs->lasttarget )
    goto LABEL_4;
  if ( pc == 0 )
  {
    if ( from >= fs->nactvar )
      return;
    goto LABEL_4;
  }
  v5 = &fs->f->code[pc - 1];
  v6 = *v5;
  if ( (*(_BYTE *)v5 & 0x3F) != 3 || (v7 = v6 >> 23, (unsigned __int8)(v6 >> 6) > from) || from > v7 + 1 )
  {
LABEL_4:
    luaK_code(fs, i: ((from | ((from + n - 1) << 17)) << 6) | 3, line: fs->ls->lastline);
    return;
  }
  if ( from + n - 1 > v7 )
    *v5 = v6 & 0x7FFFFF | ((from + n - 1) << 23);
}

//------------------------------------------------------------------------------
// Address: 0x10005CE0
// Name: _luaK_jump
// Source: json
//------------------------------------------------------------------------------
int __usercall luaK_jump@<eax>(FuncState *fs@<eax>)
{
  LexState *ls; // eax
  int jpc; // edi
  int j; // [esp+Ch] [ebp-4h] BYREF

  ls = fs->ls;
  jpc = fs->jpc;
  fs->jpc = -1;
  j = luaK_code(fs, i: 0x7FFF8016u, line: ls->lastline);
  luaK_concat(fs, l1: &j, l2: jpc);
  return j;
}

//------------------------------------------------------------------------------
// Address: 0x10005D20
// Name: need_value
// Source: json
//------------------------------------------------------------------------------
int __usercall need_value@<eax>(FuncState *fs@<eax>, int list@<edx>)
{
  unsigned int *code; // edi
  unsigned int *v3; // eax
  unsigned int *v4; // esi
  int v5; // eax

  if ( list == -1 )
    return 0;
  code = fs->f->code;
  while ( 1 )
  {
    v3 = &code[list];
    if ( list < 1 || (v4 = v3 - 1, luaP_opmodes[*(v3 - 1) & 0x3F] >= 0) )
      v4 = &code[list];
    if ( (*(_BYTE *)v4 & 0x3F) != 0x1B )
      break;
    v5 = (*v3 >> 14) - 0x1FFFF;
    if ( v5 != -1 )
    {
      list += v5 + 1;
      if ( list != -1 )
        continue;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005D80
// Name: removevalues
// Source: json
//------------------------------------------------------------------------------
void __usercall removevalues(FuncState *fs@<edx>, int list@<eax>)
{
  int i; // esi
  int v3; // edi
  unsigned int *v4; // eax
  unsigned int *v5; // ecx

  for ( i = list; i != -1; i += (fs->f->code[v3] >> 14) - 0x1FFFF + 1 )
  {
    v3 = i;
    v4 = &fs->f->code[i];
    if ( i < 1 || (v5 = v4 - 1, luaP_opmodes[*(v4 - 1) & 0x3F] >= 0) )
      v5 = &fs->f->code[i];
    if ( (*(_BYTE *)v5 & 0x3F) == 0x1B )
      *v5 = *v5 & 0x7FC000 | ((*v5 & 0xFF81FFFF | 0x340000) >> 17);
    if ( fs->f->code[v3] >> 14 == 131070 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E00
// Name: patchlistaux
// Source: json
//------------------------------------------------------------------------------
void __usercall patchlistaux(int list@<eax>, FuncState *fs, int vtarget, int reg, int dtarget)
{
  int v5; // edi
  unsigned int *code; // esi
  unsigned int v7; // eax
  unsigned int *v8; // esi
  int v9; // eax
  unsigned int *v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // esi
  int v13; // ecx
  int next; // [esp+Ch] [ebp-4h]

  v5 = list;
  if ( list != -1 )
  {
    do
    {
      code = fs->f->code;
      v7 = code[v5];
      v8 = &code[v5];
      v9 = (v7 >> 14) - 0x1FFFF;
      if ( v9 == -1 )
        next = -1;
      else
        next = v9 + v5 + 1;
      if ( v5 < 1 || (v10 = v8 - 1, luaP_opmodes[*(v8 - 1) & 0x3F] >= 0) )
        v10 = v8;
      v11 = *v10;
      if ( (*(_BYTE *)v10 & 0x3F) == 0x1B )
      {
        if ( reg == 255 || reg == v11 >> 23 )
          v12 = v11 & 0x7FC000 | ((v11 & 0xFF81FFFF | 0x340000) >> 17);
        else
          v12 = v11 ^ ((unsigned __int16)v11 ^ (unsigned __int16)((_WORD)reg << 6)) & 0x3FC0;
        *v10 = v12;
        v8 = &fs->f->code[v5];
        if ( (int)abs32(vtarget - v5 - 1) > 0x1FFFF )
          luaX_lexerror(ls: fs->ls, msg: "control structure too long", token: fs->ls->t.token);
        v13 = *v8 & 0x3FFF ^ ((vtarget - v5 + 131070) << 14);
      }
      else
      {
        if ( (int)abs32(dtarget - v5 - 1) > 0x1FFFF )
          luaX_lexerror(ls: fs->ls, msg: "control structure too long", token: fs->ls->t.token);
        v13 = *v8 & 0x3FFF ^ ((dtarget - v5 + 131070) << 14);
      }
      v5 = next;
      *v8 = v13;
    }
    while ( next != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F40
// Name: _luaK_concat
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_concat(int *l1@<eax>, int l2@<ecx>, FuncState *fs)
{
  int v4; // ecx
  unsigned int *i; // esi
  int v6; // edi

  if ( l2 != -1 )
  {
    v4 = *l1;
    if ( *l1 == -1 )
    {
      *l1 = l2;
    }
    else
    {
      for ( i = fs->f->code; i[v4] >> 14 != 131070 && (i[v4] >> 14) - 0x1FFFF + v4 != -2; v4 += (i[v4] >> 14)
                                                                                              - 0x1FFFF
                                                                                              + 1 )
        ;
      v6 = l2 - v4;
      if ( (int)abs32(v6 - 1) > 0x1FFFF )
        luaX_lexerror(ls: fs->ls, msg: "control structure too long", token: fs->ls->t.token);
      i[v4] = i[v4] & 0x3FFF ^ ((v6 + 131070) << 14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005FC0
// Name: freeexp
// Source: json
//------------------------------------------------------------------------------
void __usercall freeexp(FuncState *fs@<ecx>, expdesc *e@<eax>)
{
  int info; // eax

  if ( e->k == VNONRELOC )
  {
    info = e->u.s.info;
    if ( (info & 0x100) == 0 && info >= fs->nactvar )
      --fs->freereg;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005FE0
// Name: addk
// Source: json
//------------------------------------------------------------------------------
int __usercall addk@<eax>(lua_TValue *k@<eax>, FuncState *fs, lua_TValue *v)
{
  Table *h; // esi
  lua_TValue *v5; // eax
  int tt; // eax
  GCObject *f; // edi
  int sizek; // ebx
  int *p_sizek; // esi
  __m128i v11; // xmm0
  int *p_nk; // edx
  int v13; // ecx
  void *v14; // eax
  int v15; // eax
  lua_State *L; // [esp+Ch] [ebp-4h]
  int *v17; // [esp+18h] [ebp+8h]

  h = fs->h;
  L = fs->L;
  v5 = (lua_TValue *)luaH_get(t: h, key: k);
  h->flags &= 0x40u;
  if ( v5 == &luaO_nilobject_ )
  {
    tt = k->tt;
    if ( tt == 0 )
      luaG_runerror(L, fmt: "table index is nil");
    v5 = newkey(L, t: h, key: k);
  }
  f = (GCObject *)fs->f;
  sizek = fs->f->sizek;
  p_sizek = &fs->f->sizek;
  if ( v5->tt == 3 )
    return (int)v5->value.n;
  v11 = _mm_cvtsi32_si128(fs->nk);
  p_nk = &fs->nk;
  v5->tt = 3;
  v5->value.n = _mm_cvtepi32_pd(v11).m128d_f64[0];
  v13 = fs->nk + 1;
  v17 = &fs->nk;
  if ( v13 > *p_sizek )
  {
    v14 = luaM_growaux_(
            L,
            block: f->u.uv.metatable,
            size: &f->p.sizek,
            size_elems: 0x10u,
            limit: 0x3FFFF,
            errormsg: "constant table overflow");
    p_nk = v17;
    f->ts.tsv.hash = (unsigned int)v14;
  }
  if ( sizek < *p_sizek )
  {
    v15 = 16 * sizek;
    do
    {
      *(_DWORD *)(f->ts.tsv.hash + v15 + 8) = 0;
      ++sizek;
      v15 += 16;
    }
    while ( sizek < *p_sizek );
  }
  *(lua_TValue *)(f->ts.tsv.hash + 16 * *p_nk) = *v;
  if ( v->tt >= 4 && (*(_BYTE *)(v->value.b + 5) & 3) != 0 && (f->gch.marked & 4) != 0 )
  {
    luaC_barrierf(L, o: f, v: v->value.gc);
    p_nk = v17;
  }
  return (*p_nk)++;
}

//------------------------------------------------------------------------------
// Address: 0x10006120
// Name: _luaK_numberK
// Source: json
//------------------------------------------------------------------------------
int __usercall luaK_numberK@<eax>(FuncState *fs@<ecx>, long double a2@<xmm0>)
{
  lua_TValue o; // [esp+0h] [ebp-10h] BYREF

  o.value.n = a2;
  o.tt = 3;
  return addk(k: &o, fs, v: &o);
}

//------------------------------------------------------------------------------
// Address: 0x10006150
// Name: _luaK_setreturns
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_setreturns(FuncState *fs@<eax>, expdesc *e@<edx>, int nresults)
{
  unsigned int *v3; // ecx
  unsigned int *v4; // ecx
  int v5; // ecx

  if ( e->k == VCALL )
  {
    fs->f->code[e->u.s.info] ^= (fs->f->code[e->u.s.info] ^ ((nresults + 1) << 14)) & 0x7FC000;
  }
  else if ( e->k == VVARARG )
  {
    v3 = &fs->f->code[e->u.s.info];
    *v3 = *v3 & 0x7FFFFF ^ ((nresults + 1) << 23);
    v4 = &fs->f->code[e->u.s.info];
    *v4 ^= (*v4 ^ (fs->freereg << 6)) & 0x3FC0;
    v5 = fs->freereg + 1;
    if ( v5 > fs->f->maxstacksize )
    {
      if ( v5 >= 250 )
        luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
      fs->f->maxstacksize = v5;
    }
    ++fs->freereg;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100061F0
// Name: _luaK_setoneret
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_setoneret(FuncState *fs@<edx>, expdesc *e@<eax>)
{
  int info; // ecx
  unsigned int *v3; // ecx

  if ( e->k == VCALL )
  {
    info = e->u.s.info;
    e->k = VNONRELOC;
    e->u.s.info = (unsigned __int8)(fs->f->code[info] >> 6);
  }
  else if ( e->k == VVARARG )
  {
    v3 = &fs->f->code[e->u.s.info];
    *v3 = *v3 & 0x7FFFFF | 0x1000000;
    e->k = VRELOCABLE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006240
// Name: _luaK_dischargevars
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_dischargevars(FuncState *fs@<eax>, expdesc *e@<edi>)
{
  unsigned int v3; // eax
  int lastline; // edx
  int aux; // eax
  int info; // eax

  switch ( e->k )
  {
    case VLOCAL:
      e->k = VNONRELOC;
      return;
    case VUPVAL:
      v3 = (e->u.s.info << 23) | 4;
      goto LABEL_4;
    case VGLOBAL:
      v3 = (e->u.s.info << 14) | 5;
LABEL_4:
      lastline = fs->ls->lastline;
      goto LABEL_5;
    case VINDEXED:
      aux = e->u.s.aux;
      if ( (aux & 0x100) == 0 && aux >= fs->nactvar )
        --fs->freereg;
      info = e->u.s.info;
      if ( (info & 0x100) == 0 && info >= fs->nactvar )
        --fs->freereg;
      lastline = fs->ls->lastline;
      v3 = ((e->u.s.aux | (e->u.s.info << 9)) << 14) | 6;
LABEL_5:
      e->u.s.info = luaK_code(fs, i: v3, line: lastline);
      e->k = VRELOCABLE;
      break;
    case VCALL:
    case VVARARG:
      luaK_setoneret(fs, e);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006300
// Name: discharge2reg
// Source: json
//------------------------------------------------------------------------------
void __usercall discharge2reg(FuncState *fs@<ecx>, expdesc *e@<eax>, int reg)
{
  int v5; // eax
  int info; // eax
  lua_TValue k; // [esp+10h] [ebp-14h] BYREF

  luaK_dischargevars(fs, e);
  switch ( e->k )
  {
    case VNIL:
      luaK_nil(fs, from: reg, n: 1);
      e->u.s.info = reg;
      e->k = VNONRELOC;
      return;
    case VTRUE:
    case VFALSE:
      luaK_code(fs, i: ((reg | ((e->k == VTRUE) << 17)) << 6) | 2, line: fs->ls->lastline);
      goto LABEL_9;
    case VK:
      luaK_code(fs, i: ((reg | (e->u.s.info << 8)) << 6) | 1, line: fs->ls->lastline);
      goto LABEL_9;
    case VKNUM:
      k.value.n = e->u.nval;
      k.tt = 3;
      v5 = addk(&k, fs, v: &k);
      luaK_code(fs, i: ((reg | (v5 << 8)) << 6) | 1, line: fs->ls->lastline);
      e->u.s.info = reg;
      e->k = VNONRELOC;
      return;
    case VRELOCABLE:
      fs->f->code[e->u.s.info] ^= (fs->f->code[e->u.s.info] ^ (reg << 6)) & 0x3FC0;
      e->u.s.info = reg;
      e->k = VNONRELOC;
      return;
    case VNONRELOC:
      info = e->u.s.info;
      if ( reg != info )
        luaK_code(fs, i: (reg | (info << 17)) << 6, line: fs->ls->lastline);
LABEL_9:
      e->u.s.info = reg;
      e->k = VNONRELOC;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006460
// Name: discharge2anyreg
// Source: json
//------------------------------------------------------------------------------
void __usercall discharge2anyreg(FuncState *fs@<ecx>, expdesc *e@<eax>)
{
  int v2; // edx

  if ( e->k != VNONRELOC )
  {
    v2 = fs->freereg + 1;
    if ( v2 > fs->f->maxstacksize )
    {
      if ( v2 >= 250 )
        luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
      fs->f->maxstacksize = v2;
    }
    discharge2reg(fs, e, reg: fs->freereg++);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100064B0
// Name: exp2reg
// Source: json
//------------------------------------------------------------------------------
void __usercall exp2reg(FuncState *fs@<eax>, expdesc *e@<edi>, int reg)
{
  int t; // edx
  int f; // ebx
  int jpc; // ebx
  LexState *ls; // ecx
  LexState *v8; // edx
  LexState *v9; // eax
  int v10; // eax
  int v11; // ecx
  int pc; // ebx
  int p_t; // [esp+8h] [ebp-Ch]
  int p_f; // [esp+Ch] [ebp-8h]
  int fj; // [esp+10h] [ebp-4h] BYREF

  discharge2reg(fs, e, reg);
  if ( e->k == VJMP )
    luaK_concat(l1: &e->t, l2: e->u.s.info, fs);
  t = e->t;
  f = e->f;
  if ( t != f )
  {
    p_f = -1;
    p_t = -1;
    if ( need_value(fs, list: t) != 0 || need_value(fs, list: f) != 0 )
    {
      if ( e->k == VJMP )
      {
        fj = -1;
      }
      else
      {
        jpc = fs->jpc;
        ls = fs->ls;
        fs->jpc = -1;
        fj = luaK_code(fs, i: 0x7FFF8016u, line: ls->lastline);
        luaK_concat(l1: &fj, l2: jpc, fs);
      }
      v8 = fs->ls;
      fs->lasttarget = fs->pc;
      p_f = luaK_code(fs, i: (reg << 6) | 0x4002, line: v8->lastline);
      v9 = fs->ls;
      fs->lasttarget = fs->pc;
      v10 = luaK_code(fs, i: (reg << 6) | 0x800002, line: v9->lastline);
      v11 = fj;
      p_t = v10;
      fs->lasttarget = fs->pc;
      luaK_concat(l1: &fs->jpc, l2: v11, fs);
    }
    pc = fs->pc;
    fs->lasttarget = pc;
    patchlistaux(list: e->f, fs, vtarget: pc, reg, dtarget: p_f);
    patchlistaux(list: e->t, fs, vtarget: pc, reg, dtarget: p_t);
  }
  e->t = -1;
  e->f = -1;
  e->u.s.info = reg;
  e->k = VNONRELOC;
}

//------------------------------------------------------------------------------
// Address: 0x100065F0
// Name: _luaK_exp2nextreg
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_exp2nextreg(FuncState *fs@<ecx>, expdesc *e@<eax>)
{
  int info; // eax
  int v5; // eax

  luaK_dischargevars(fs, e);
  if ( e->k == VNONRELOC )
  {
    info = e->u.s.info;
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
  exp2reg(fs, e, reg: fs->freereg++);
}

//------------------------------------------------------------------------------
// Address: 0x10006660
// Name: _luaK_exp2anyreg
// Source: json
//------------------------------------------------------------------------------
int __usercall luaK_exp2anyreg@<eax>(FuncState *fs@<esi>, expdesc *e@<eax>)
{
  int result; // eax

  luaK_dischargevars(fs, e);
  if ( e->k != VNONRELOC )
    goto LABEL_5;
  result = e->u.s.info;
  if ( e->t == e->f )
    return result;
  if ( result >= fs->nactvar )
  {
    exp2reg(fs, e, reg: e->u.s.info);
    return e->u.s.info;
  }
  else
  {
LABEL_5:
    luaK_exp2nextreg(fs, e);
    return e->u.s.info;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100066A0
// Name: _luaK_exp2val
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_exp2val(FuncState *fs@<esi>, expdesc *e@<eax>)
{
  if ( e->t == e->f )
  {
    luaK_dischargevars(fs, e);
  }
  else
  {
    luaK_dischargevars(fs, e);
    if ( e->k != VNONRELOC )
      goto LABEL_6;
    if ( e->t == e->f )
      return;
    if ( e->u.s.info >= fs->nactvar )
      exp2reg(fs, e, reg: e->u.s.info);
    else
LABEL_6:
      luaK_exp2nextreg(fs, e);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100066F0
// Name: _luaK_exp2RK
// Source: json
//------------------------------------------------------------------------------
int __usercall luaK_exp2RK@<eax>(FuncState *fs@<esi>, expdesc *e@<eax>)
{
  expkind v3; // eax
  Table *h; // eax
  int info; // eax
  int v6; // eax
  int result; // eax
  lua_TValue v8; // [esp+8h] [ebp-20h] BYREF
  lua_TValue k; // [esp+18h] [ebp-10h] BYREF

  if ( e->t == e->f )
  {
    luaK_dischargevars(fs, e);
    goto LABEL_8;
  }
  luaK_dischargevars(fs, e);
  if ( e->k != VNONRELOC )
    goto LABEL_6;
  if ( e->t != e->f )
  {
    if ( e->u.s.info >= fs->nactvar )
    {
      exp2reg(fs, e, reg: e->u.s.info);
      goto LABEL_8;
    }
LABEL_6:
    luaK_exp2nextreg(fs, e);
  }
LABEL_8:
  v3 = e->k;
  switch ( e->k )
  {
    case VNIL:
    case VTRUE:
    case VFALSE:
    case VKNUM:
      if ( fs->nk > 255 )
        goto LABEL_18;
      if ( v3 == VNIL )
      {
        h = fs->h;
        v8.tt = 0;
        k.value.b = (int)h;
        k.tt = 5;
        info = addk(&k, fs, v: &v8);
LABEL_15:
        e->u.s.info = info;
        e->k = VK;
        return info | 0x100;
      }
      if ( v3 != VKNUM )
      {
        k.tt = 1;
        k.value.b = v3 == VTRUE;
        info = addk(&k, fs, v: &k);
        goto LABEL_15;
      }
      v6 = luaK_numberK(fs, a2: e->u.nval);
      e->u.s.info = v6;
      e->k = VK;
      return v6 | 0x100;
    case VK:
      info = e->u.s.info;
      if ( info > 255 )
        goto LABEL_18;
      return info | 0x100;
    default:
LABEL_18:
      luaK_dischargevars(fs, e);
      if ( e->k != VNONRELOC )
        goto LABEL_22;
      result = e->u.s.info;
      if ( e->t != e->f )
      {
        if ( result < fs->nactvar )
        {
LABEL_22:
          luaK_exp2nextreg(fs, e);
          return e->u.s.info;
        }
        else
        {
          exp2reg(fs, e, reg: e->u.s.info);
          return e->u.s.info;
        }
      }
      return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006840
// Name: _luaK_storevar
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_storevar(FuncState *fs@<ecx>, expdesc *ex@<eax>, expdesc *var)
{
  int info; // eax
  int v6; // eax
  int lastline; // edx
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // edi

  switch ( var->k )
  {
    case VLOCAL:
      if ( ex->k == VNONRELOC )
      {
        info = ex->u.s.info;
        if ( (info & 0x100) == 0 && info >= fs->nactvar )
          --fs->freereg;
      }
      exp2reg(fs, e: ex, reg: var->u.s.info);
      return;
    case VUPVAL:
      v6 = luaK_exp2anyreg(fs, e: ex);
      lastline = fs->ls->lastline;
      v8 = ((v6 | (var->u.s.info << 17)) << 6) | 8;
      goto LABEL_10;
    case VGLOBAL:
      v9 = luaK_exp2anyreg(fs, e: ex);
      luaK_code(fs, i: ((v9 | (var->u.s.info << 8)) << 6) | 7, line: fs->ls->lastline);
      goto LABEL_11;
    case VINDEXED:
      v10 = luaK_exp2RK(fs, e: ex);
      lastline = fs->ls->lastline;
      v8 = ((var->u.s.info | ((v10 | (var->u.s.aux << 9)) << 8)) << 6) | 9;
LABEL_10:
      luaK_code(fs, i: v8, line: lastline);
      goto LABEL_11;
    default:
LABEL_11:
      if ( ex->k == VNONRELOC )
      {
        v11 = ex->u.s.info;
        if ( (v11 & 0x100) == 0 && v11 >= fs->nactvar )
          --fs->freereg;
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: _luaK_self
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_self(FuncState *fs@<ecx>, expdesc *e@<eax>, expdesc *key)
{
  int info; // eax
  int freereg; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax

  luaK_dischargevars(fs, e);
  if ( e->k != VNONRELOC )
    goto LABEL_5;
  if ( e->t != e->f )
  {
    if ( e->u.s.info >= fs->nactvar )
    {
      exp2reg(fs, e, reg: e->u.s.info);
      goto LABEL_6;
    }
LABEL_5:
    luaK_exp2nextreg(fs, e);
  }
LABEL_6:
  if ( e->k == VNONRELOC )
  {
    info = e->u.s.info;
    if ( (info & 0x100) == 0 && info >= fs->nactvar )
      --fs->freereg;
  }
  freereg = fs->freereg;
  v7 = freereg + 2;
  if ( freereg + 2 > fs->f->maxstacksize )
  {
    if ( v7 >= 250 )
      luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
    fs->f->maxstacksize = v7;
  }
  fs->freereg += 2;
  v8 = luaK_exp2RK(fs, e: key);
  luaK_code(fs, i: ((freereg | ((v8 | (e->u.s.info << 9)) << 8)) << 6) | 0xB, line: fs->ls->lastline);
  if ( key->k == VNONRELOC )
  {
    v9 = key->u.s.info;
    if ( (v9 & 0x100) == 0 && v9 >= fs->nactvar )
      --fs->freereg;
  }
  e->u.s.info = freereg;
  e->k = VNONRELOC;
}

//------------------------------------------------------------------------------
// Address: 0x10006A10
// Name: invertjump
// Source: json
//------------------------------------------------------------------------------
void __usercall invertjump(FuncState *fs@<ecx>, expdesc *e@<eax>)
{
  int info; // eax
  unsigned int *v3; // ecx

  info = e->u.s.info;
  v3 = &fs->f->code[info];
  if ( info >= 1 && luaP_opmodes[*(v3 - 1) & 0x3F] < 0 )
    --v3;
  *v3 ^= ((unsigned __int16)*v3 ^ (((*v3 & 0x3FC0) == 0) << 6)) & 0x3FC0;
}

//------------------------------------------------------------------------------
// Address: 0x10006A60
// Name: jumponcond
// Source: json
//------------------------------------------------------------------------------
int __usercall jumponcond@<eax>(FuncState *fs@<ecx>, expdesc *e@<eax>, int cond)
{
  expkind k; // ecx
  unsigned int v6; // eax
  int v7; // eax
  int info; // eax
  int jpc; // edi
  LexState *ls; // edx
  int l1; // [esp+8h] [ebp-4h] BYREF

  k = e->k;
  if ( e->k == VRELOCABLE && (v6 = fs->f->code[e->u.s.info], (fs->f->code[e->u.s.info] & 0x3F) == 0x13) )
  {
    --fs->pc;
    luaK_code(fs, i: ((cond == 0) << 14) | ((v6 & 0xFF81FFFF | 0x340000) >> 17), line: fs->ls->lastline);
  }
  else
  {
    if ( k == VNONRELOC )
      goto LABEL_10;
    v7 = fs->freereg + 1;
    if ( v7 > fs->f->maxstacksize )
    {
      if ( v7 >= 250 )
        luaX_lexerror(ls: fs->ls, msg: "function or expression too complex", token: fs->ls->t.token);
      fs->f->maxstacksize = v7;
    }
    discharge2reg(fs, e, reg: fs->freereg++);
    if ( e->k == VNONRELOC )
    {
LABEL_10:
      info = e->u.s.info;
      if ( (info & 0x100) == 0 && info >= fs->nactvar )
        --fs->freereg;
    }
    luaK_code(fs, i: ((cond | (e->u.s.info << 9)) << 14) | 0x3FDB, line: fs->ls->lastline);
  }
  jpc = fs->jpc;
  ls = fs->ls;
  fs->jpc = -1;
  l1 = luaK_code(fs, i: 0x7FFF8016u, line: ls->lastline);
  luaK_concat(&l1, l2: jpc, fs);
  return l1;
}

//------------------------------------------------------------------------------
// Address: 0x10006B60
// Name: _luaK_goiftrue
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_goiftrue(FuncState *fs@<esi>, expdesc *e@<eax>)
{
  int info; // ecx
  int v4; // eax
  int t; // ecx

  luaK_dischargevars(fs, e);
  switch ( e->k )
  {
    case VTRUE:
    case VK:
    case VKNUM:
      info = -1;
      break;
    case VFALSE:
      v4 = luaK_jump(fs);
      goto LABEL_6;
    case VJMP:
      invertjump(fs, e);
      info = e->u.s.info;
      break;
    default:
      v4 = jumponcond(fs, e, cond: 0);
LABEL_6:
      info = v4;
      break;
  }
  luaK_concat(l1: &e->f, l2: info, fs);
  t = e->t;
  fs->lasttarget = fs->pc;
  luaK_concat(l1: &fs->jpc, l2: t, fs);
  e->t = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10006C00
// Name: luaK_goiffalse
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_goiffalse(FuncState *fs@<esi>, expdesc *e@<eax>)
{
  int info; // ecx
  int v4; // eax
  int f; // ecx

  luaK_dischargevars(fs, e);
  switch ( e->k )
  {
    case VNIL:
    case VFALSE:
      info = -1;
      break;
    case VTRUE:
      v4 = luaK_jump(fs);
      goto LABEL_6;
    case VJMP:
      info = e->u.s.info;
      break;
    default:
      v4 = jumponcond(fs, e, cond: 1);
LABEL_6:
      info = v4;
      break;
  }
  luaK_concat(l1: &e->t, l2: info, fs);
  f = e->f;
  fs->lasttarget = fs->pc;
  luaK_concat(l1: &fs->jpc, l2: f, fs);
  e->f = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10006C90
// Name: codenot
// Source: json
//------------------------------------------------------------------------------
void __usercall codenot(FuncState *fs@<ecx>, expdesc *e@<eax>)
{
  int info; // eax
  int t; // edx
  FuncState *v6; // edx

  luaK_dischargevars(fs, e);
  switch ( e->k )
  {
    case VNIL:
    case VFALSE:
      e->k = VTRUE;
      break;
    case VTRUE:
    case VK:
    case VKNUM:
      e->k = VFALSE;
      break;
    case VJMP:
      invertjump(fs, e);
      break;
    case VRELOCABLE:
    case VNONRELOC:
      discharge2anyreg(fs, e);
      if ( e->k == VNONRELOC )
      {
        info = e->u.s.info;
        if ( (info & 0x100) == 0 && info >= fs->nactvar )
          --fs->freereg;
      }
      e->u.s.info = luaK_code(fs, i: (e->u.s.info << 23) | 0x13, line: fs->ls->lastline);
      e->k = VRELOCABLE;
      break;
    default:
      break;
  }
  t = e->t;
  e->t = e->f;
  e->f = t;
  removevalues(fs, list: t);
  removevalues(fs: v6, list: e->t);
}

//------------------------------------------------------------------------------
// Address: 0x10006D60
// Name: constfolding
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10006ED0
// Name: codearith
// Source: json
//------------------------------------------------------------------------------
void __usercall codearith(FuncState *fs@<edi>, OpCode op, expdesc *e1, expdesc *e2)
{
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  int info; // ecx
  int o2; // [esp+8h] [ebp-4h]

  if ( constfolding(op, e1, e2) == 0 )
  {
    if ( op == OP_UNM || op == OP_LEN )
      o2 = 0;
    else
      o2 = luaK_exp2RK(fs, e: e2);
    v4 = luaK_exp2RK(fs, e: e1);
    if ( v4 <= o2 )
    {
      if ( e2->k == VNONRELOC )
      {
        info = e2->u.s.info;
        if ( (info & 0x100) == 0 && info >= fs->nactvar )
          --fs->freereg;
      }
      if ( e1->k != VNONRELOC )
        goto LABEL_22;
      v6 = e1->u.s.info;
    }
    else
    {
      if ( e1->k == VNONRELOC )
      {
        v5 = e1->u.s.info;
        if ( (v5 & 0x100) == 0 && v5 >= fs->nactvar )
          --fs->freereg;
      }
      if ( e2->k != VNONRELOC )
        goto LABEL_22;
      v6 = e2->u.s.info;
    }
    if ( (v6 & 0x100) == 0 && v6 >= fs->nactvar )
      --fs->freereg;
LABEL_22:
    e1->u.s.info = luaK_code(fs, i: op | ((o2 | (v4 << 9)) << 14), line: fs->ls->lastline);
    e1->k = VRELOCABLE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006FC0
// Name: codecomp
// Source: json
//------------------------------------------------------------------------------
void __usercall codecomp(FuncState *fs@<eax>, OpCode op, int cond, expdesc *e1, expdesc *e2)
{
  expdesc *v5; // ebx
  int v7; // edi
  int v8; // eax
  int info; // ebx
  expdesc *v10; // ebx
  int v11; // ecx
  int v12; // ecx
  int jpc; // edi
  LexState *ls; // eax

  v5 = e2;
  v7 = luaK_exp2RK(fs, e: e1);
  v8 = luaK_exp2RK(fs, e: v5);
  if ( v5->k == VNONRELOC )
  {
    info = v5->u.s.info;
    if ( (info & 0x100) == 0 && info >= fs->nactvar )
      --fs->freereg;
  }
  v10 = e1;
  if ( e1->k == VNONRELOC )
  {
    v11 = e1->u.s.info;
    if ( (v11 & 0x100) == 0 && v11 >= fs->nactvar )
      --fs->freereg;
  }
  if ( cond == 0 && op != OP_EQ )
  {
    v12 = v7;
    v7 = v8;
    v8 = v12;
    cond = 1;
  }
  luaK_code(fs, i: op | ((cond | ((v8 | (v7 << 9)) << 8)) << 6), line: fs->ls->lastline);
  jpc = fs->jpc;
  ls = fs->ls;
  fs->jpc = -1;
  cond = luaK_code(fs, i: 0x7FFF8016u, line: ls->lastline);
  luaK_concat(l1: &cond, l2: jpc, fs);
  v10->u.s.info = cond;
  v10->k = VJMP;
}

//------------------------------------------------------------------------------
// Address: 0x10007090
// Name: _luaK_prefix
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_prefix(UnOpr op@<eax>, expdesc *e@<ecx>, FuncState *fs)
{
  int v4; // eax
  expdesc e2; // [esp+0h] [ebp-1Ch] BYREF

  e2.f = -1;
  e2.t = -1;
  e2.k = VKNUM;
  e2.u.nval = 0.0;
  if ( op != OPR_MINUS )
  {
    v4 = op - 1;
    if ( v4 != 0 )
    {
      if ( v4 != 1 )
        return;
      luaK_dischargevars(fs, e);
      if ( e->k == VNONRELOC )
      {
        if ( e->t == e->f )
        {
LABEL_9:
          codearith(fs, op: OP_LEN, e1: e, &e2);
          return;
        }
        if ( e->u.s.info >= fs->nactvar )
        {
          exp2reg(fs, e, reg: e->u.s.info);
          codearith(fs, op: OP_LEN, e1: e, &e2);
          return;
        }
      }
      luaK_exp2nextreg(fs, e);
      goto LABEL_9;
    }
    codenot(fs, e);
  }
  else
  {
    if ( e->k != VKNUM || e->t != -1 || e->f != -1 )
      luaK_exp2anyreg(fs, e);
    codearith(fs, op: OP_UNM, e1: e, &e2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007170
// Name: _luaK_posfix
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_posfix(BinOpr op@<eax>, expdesc *e2@<ecx>, FuncState *fs, expdesc *e1)
{
  int f; // ecx
  int *p_f; // eax
  unsigned int *v7; // eax

  switch ( op )
  {
    case OPR_ADD:
      codearith(fs, op: OP_ADD, e1, e2);
      break;
    case OPR_SUB:
      codearith(fs, op: OP_SUB, e1, e2);
      break;
    case OPR_MUL:
      codearith(fs, op: OP_MUL, e1, e2);
      break;
    case OPR_DIV:
      codearith(fs, op: OP_DIV, e1, e2);
      break;
    case OPR_MOD:
      codearith(fs, op: OP_MOD, e1, e2);
      break;
    case OPR_POW:
      codearith(fs, op: OP_POW, e1, e2);
      break;
    case OPR_CONCAT:
      luaK_exp2val(fs, e: e2);
      if ( e2->k == VRELOCABLE && (fs->f->code[e2->u.s.info] & 0x3F) == 0x15 )
      {
        freeexp(fs, e: e1);
        v7 = &fs->f->code[e2->u.s.info];
        *v7 = *v7 & 0x7FFFFF | (e1->u.s.info << 23);
        e1->k = VRELOCABLE;
        e1->u.s.info = e2->u.s.info;
      }
      else
      {
        luaK_exp2nextreg(fs, e: e2);
        codearith(fs, op: OP_CONCAT, e1, e2);
      }
      break;
    case OPR_NE:
      codecomp(fs, op: OP_EQ, cond: 0, e1, e2);
      break;
    case OPR_EQ:
      codecomp(fs, op: OP_EQ, cond: 1, e1, e2);
      break;
    case OPR_LT:
      codecomp(fs, op: OP_LT, cond: 1, e1, e2);
      break;
    case OPR_LE:
      codecomp(fs, op: OP_LE, cond: 1, e1, e2);
      break;
    case OPR_GT:
      codecomp(fs, op: OP_LT, cond: 0, e1, e2);
      break;
    case OPR_GE:
      codecomp(fs, op: OP_LE, cond: 0, e1, e2);
      break;
    case OPR_AND:
      luaK_dischargevars(fs, e: e2);
      f = e1->f;
      p_f = &e2->f;
      goto LABEL_3;
    case OPR_OR:
      luaK_dischargevars(fs, e: e2);
      f = e1->t;
      p_f = &e2->t;
LABEL_3:
      luaK_concat(l1: p_f, l2: f, fs);
      *e1 = *e2;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007390
// Name: luaK_code
// Source: json
//------------------------------------------------------------------------------
int __usercall luaK_code@<eax>(FuncState *fs@<esi>, unsigned int i, int line)
{
  Proto *f; // edi
  int v4; // ecx
  int result; // eax

  f = fs->f;
  patchlistaux(list: fs->jpc, fs, vtarget: fs->pc, reg: 255, dtarget: fs->pc);
  v4 = fs->pc + 1;
  fs->jpc = -1;
  if ( v4 > f->sizecode )
    f->code = (unsigned int *)luaM_growaux_(
                                L: fs->L,
                                block: f->code,
                                size: &f->sizecode,
                                size_elems: 4u,
                                limit: 2147483645,
                                errormsg: "code size overflow");
  f->code[fs->pc] = i;
  if ( fs->pc + 1 > f->sizelineinfo )
    f->lineinfo = (int *)luaM_growaux_(
                           L: fs->L,
                           block: f->lineinfo,
                           size: &f->sizelineinfo,
                           size_elems: 4u,
                           limit: 2147483645,
                           errormsg: "code size overflow");
  f->lineinfo[fs->pc] = line;
  result = fs->pc;
  fs->pc = result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007430
// Name: _luaK_setlist
// Source: json
//------------------------------------------------------------------------------
void __fastcall luaK_setlist(int tostore, int nelems, FuncState *fs, int base)
{
  unsigned int v4; // edx
  signed int v5; // edi
  int v6; // eax
  int lastline; // [esp-4h] [ebp-14h]

  v4 = (int)((unsigned __int64)(1374389535LL * (nelems - 1)) >> 32) >> 4;
  v5 = v4 + (v4 >> 31) + 1;
  v6 = tostore != -1 ? tostore : 0;
  lastline = fs->ls->lastline;
  if ( v5 > 511 )
  {
    luaK_code(fs, i: ((base | (v6 << 17)) << 6) | 0x22, line: lastline);
    luaK_code(fs, i: v5, line: fs->ls->lastline);
  }
  else
  {
    luaK_code(fs, i: ((base | ((v5 | (v6 << 9)) << 8)) << 6) | 0x22, line: lastline);
  }
  fs->freereg = base + 1;
}
