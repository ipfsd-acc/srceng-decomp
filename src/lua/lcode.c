// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lcode.c
// Functions: 46
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00489C10
// Name: fixjump
// Source: json
//------------------------------------------------------------------------------
void __usercall fixjump(int pc@<ecx>, int dest@<eax>, FuncState *fs)
{
  unsigned int *v3; // edi

  if ( (int)abs32(dest - pc - 1) > 0x1FFFF )
    luaX_syntaxerror(ls: fs->ls, msg: "control structure too long");
  v3 = &fs->f->code[pc];
  *v3 = *v3 & 0x3FFF ^ ((dest - pc - 1 + 0x1FFFF) << 14);
}

//------------------------------------------------------------------------------
// Address: 0x00489C60
// Name: int luaK_getlabel(struct FuncState __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_getlabel(FuncState *fs)
{
  int result; // eax

  result = fs->pc;
  fs->lasttarget = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489C70
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
    if ( list < 1 || (v4 = v3 - 1, (luaP_opmodes[*(v3 - 1) & 0x3F] & 0x80u) == 0) )
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
// Address: 0x00489CD0
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
    if ( i < 1 || (v5 = v4 - 1, (luaP_opmodes[*(v4 - 1) & 0x3F] & 0x80u) == 0) )
      v5 = &fs->f->code[i];
    if ( (*(_BYTE *)v5 & 0x3F) == 0x1B )
      *v5 = *v5 & 0x7FC000 | ((*v5 & 0xFF81FFFF | 0x340000) >> 17);
    if ( fs->f->code[v3] >> 14 == 131070 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489D50
// Name: patchlistaux
// Source: json
//------------------------------------------------------------------------------
void __usercall patchlistaux(int list@<edx>, FuncState *fs, int vtarget, int reg, int dtarget)
{
  FuncState *v5; // ebx
  unsigned int *code; // edi
  unsigned int v7; // eax
  unsigned int *v8; // edi
  int v9; // eax
  unsigned int *v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // edi
  int v13; // esi
  int next; // [esp+4h] [ebp-4h]

  v5 = fs;
  if ( list != -1 )
  {
    do
    {
      code = v5->f->code;
      v7 = code[list];
      v8 = &code[list];
      v9 = (v7 >> 14) - 0x1FFFF;
      if ( v9 == -1 )
        next = -1;
      else
        next = v9 + list + 1;
      if ( list < 1 || (v10 = v8 - 1, (luaP_opmodes[*(v8 - 1) & 0x3F] & 0x80u) == 0) )
        v10 = v8;
      v11 = *v10;
      if ( (*(_BYTE *)v10 & 0x3F) == 0x1B )
      {
        if ( reg == 255 || reg == v11 >> 23 )
          v12 = v11 & 0x7FC000 | ((v11 & 0xFF81FFFF | 0x340000) >> 17);
        else
          v12 = v11 ^ ((unsigned __int16)v11 ^ (unsigned __int16)((_WORD)reg << 6)) & 0x3FC0;
        v5 = fs;
        *v10 = v12;
        v8 = &fs->f->code[list];
        if ( (int)abs32(vtarget - list - 1) > 0x1FFFF )
          luaX_syntaxerror(ls: fs->ls, msg: "control structure too long");
        v13 = *v8 & 0x3FFF ^ ((vtarget - list + 131070) << 14);
      }
      else
      {
        v5 = fs;
        if ( (int)abs32(dtarget - list - 1) > 0x1FFFF )
          luaX_syntaxerror(ls: fs->ls, msg: "control structure too long");
        v13 = *v8 & 0x3FFF ^ ((dtarget - list + 131070) << 14);
      }
      list = next;
      *v8 = v13;
    }
    while ( next != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489E90
// Name: void luaK_concat(struct FuncState __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_concat(FuncState *fs, int *l1, int l2)
{
  int v3; // ecx
  unsigned int *i; // esi

  if ( l2 != -1 )
  {
    v3 = *l1;
    if ( *l1 == -1 )
    {
      *l1 = l2;
    }
    else
    {
      for ( i = fs->f->code; i[v3] >> 14 != 131070 && (i[v3] >> 14) - 0x1FFFF + v3 != -2; v3 += (i[v3] >> 14)
                                                                                              - 0x1FFFF
                                                                                              + 1 )
        ;
      fixjump(pc: v3, dest: l2, fs);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489EE0
// Name: void luaK_checkstack(struct FuncState __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_checkstack(FuncState *fs, int n)
{
  int v2; // ebx

  v2 = n + fs->freereg;
  if ( v2 > fs->f->maxstacksize )
  {
    if ( v2 >= 250 )
      luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
    fs->f->maxstacksize = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489F20
// Name: void luaK_reserveregs(struct FuncState __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_reserveregs(FuncState *fs, int n)
{
  int v2; // ebx

  v2 = n + fs->freereg;
  if ( v2 > fs->f->maxstacksize )
  {
    if ( v2 >= 250 )
      luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
    fs->f->maxstacksize = v2;
  }
  fs->freereg += n;
}

//------------------------------------------------------------------------------
// Address: 0x00489F70
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
// Address: 0x00489F90
// Name: addk
// Source: json
//------------------------------------------------------------------------------
int __cdecl addk(FuncState *fs, lua_TValue *v)
{
  lua_TValue *k; // ecx
  Node *v3; // eax
  GCObject *f; // edi
  int sizek; // ebx
  int *p_sizek; // esi
  __m128i v8; // xmm0
  int *p_nk; // edx
  int v10; // eax
  void *v11; // eax
  int v12; // eax
  lua_State *L; // [esp+Ch] [ebp-4h]
  int *v14; // [esp+18h] [ebp+8h]

  L = fs->L;
  v3 = luaH_set(L, t: fs->h, key: k);
  f = (GCObject *)fs->f;
  sizek = fs->f->sizek;
  p_sizek = &fs->f->sizek;
  if ( v3->i_val.tt == 3 )
    return (int)v3->i_val.value.n;
  v8 = _mm_cvtsi32_si128(fs->nk);
  p_nk = &fs->nk;
  v3->i_val.tt = 3;
  v3->i_val.value.n = _mm_cvtepi32_pd(v8).m128d_f64[0];
  v10 = fs->nk + 1;
  v14 = &fs->nk;
  if ( v10 > *p_sizek )
  {
    v11 = luaM_growaux_(
            L,
            block: f->u.uv.metatable,
            size: p_sizek,
            size_elems: 0x10u,
            limit: 0x3FFFF,
            errormsg: "constant table overflow");
    p_nk = v14;
    f->ts.tsv.hash = (unsigned int)v11;
  }
  if ( sizek < *p_sizek )
  {
    v12 = 16 * sizek;
    do
    {
      *(_DWORD *)(v12 + f->ts.tsv.hash + 8) = 0;
      ++sizek;
      v12 += 16;
    }
    while ( sizek < *p_sizek );
  }
  *(lua_TValue *)(f->ts.tsv.hash + 16 * *p_nk) = *v;
  if ( v->tt >= 4 && (*(_BYTE *)(v->value.b + 5) & 3) != 0 && (f->gch.marked & 4) != 0 )
  {
    luaC_barrierf(L, o: f, v: v->value.gc);
    p_nk = v14;
  }
  return (*p_nk)++;
}

//------------------------------------------------------------------------------
// Address: 0x0048A090
// Name: int luaK_stringK(struct FuncState __near *,union TString __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_stringK(FuncState *fs, TString *s)
{
  lua_TValue o; // [esp+0h] [ebp-10h] BYREF

  o.value.b = (int)s;
  o.tt = 4;
  return addk(fs, v: &o);
}

//------------------------------------------------------------------------------
// Address: 0x0048A0C0
// Name: int luaK_numberK(struct FuncState __near *,double)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_numberK(FuncState *fs, long double r)
{
  lua_TValue o; // [esp+0h] [ebp-10h] BYREF

  o.value.n = r;
  o.tt = 3;
  return addk(fs, v: &o);
}

//------------------------------------------------------------------------------
// Address: 0x0048A0F0
// Name: void luaK_setreturns(struct FuncState __near *,struct expdesc __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_setreturns(FuncState *fs, expdesc *e, int nresults)
{
  unsigned int *v3; // eax
  unsigned int *v4; // eax
  int v5; // ebx

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
        luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
      fs->f->maxstacksize = v5;
    }
    ++fs->freereg;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A1A0
// Name: void luaK_setoneret(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_setoneret(FuncState *fs, expdesc *e)
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
// Address: 0x0048A200
// Name: invertjump
// Source: json
//------------------------------------------------------------------------------
void __usercall invertjump(FuncState *fs@<ecx>, expdesc *e@<eax>)
{
  int info; // eax
  unsigned int *v3; // ecx

  info = e->u.s.info;
  v3 = &fs->f->code[info];
  if ( info >= 1 && (luaP_opmodes[*(v3 - 1) & 0x3F] & 0x80u) != 0 )
    --v3;
  *v3 ^= ((unsigned __int16)*v3 ^ (((*v3 & 0x3FC0) == 0) << 6)) & 0x3FC0;
}

//------------------------------------------------------------------------------
// Address: 0x0048A250
// Name: constfolding
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0048A3C0
// Name: void luaK_fixline(struct FuncState __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_fixline(FuncState *fs, int line)
{
  fs->f->lineinfo[fs->pc - 1] = line;
}

//------------------------------------------------------------------------------
// Address: 0x0048A3E0
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
// Address: 0x0048A480
// Name: int luaK_codeABC(struct FuncState __near *,enum OpCode,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_codeABC(FuncState *fs, OpCode o, int a, int b, int c)
{
  return luaK_code(fs, i: o | ((a | ((c | (b << 9)) << 8)) << 6), line: fs->ls->lastline);
}

//------------------------------------------------------------------------------
// Address: 0x0048A4B0
// Name: int luaK_codeABx(struct FuncState __near *,enum OpCode,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_codeABx(FuncState *fs, OpCode o, int a, unsigned int bc)
{
  return luaK_code(fs, i: o | ((a | (bc << 8)) << 6), line: fs->ls->lastline);
}

//------------------------------------------------------------------------------
// Address: 0x0048A4E0
// Name: void luaK_setlist(struct FuncState __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_setlist(FuncState *fs, int base, int nelems, int tostore)
{
  signed int v4; // edi
  int v5; // eax
  LexState *ls; // ecx

  v4 = (nelems - 1) / 50 + 1;
  v5 = tostore != -1 ? tostore : 0;
  ls = fs->ls;
  if ( v4 > 511 )
  {
    luaK_code(fs, i: ((base | (v5 << 17)) << 6) | 0x22, line: ls->lastline);
    luaK_code(fs, i: v4, line: fs->ls->lastline);
  }
  else
  {
    luaK_code(fs, i: ((base | ((v4 | (v5 << 9)) << 8)) << 6) | 0x22, line: ls->lastline);
  }
  fs->freereg = base + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0048A570
// Name: void luaK_nil(struct FuncState __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_nil(FuncState *fs, int from, int n)
{
  int pc; // eax
  unsigned int *v4; // edi
  unsigned int v5; // eax
  int v6; // edx

  pc = fs->pc;
  if ( pc <= fs->lasttarget )
    goto LABEL_8;
  if ( pc == 0 )
    return;
  v4 = &fs->f->code[pc - 1];
  v5 = *v4;
  if ( (*(_BYTE *)v4 & 0x3F) == 3 && (v6 = v5 >> 23, (unsigned __int8)(v5 >> 6) <= from) && from <= v6 + 1 )
  {
    if ( from + n - 1 > v6 )
      *v4 = v5 & 0x7FFFFF | ((from + n - 1) << 23);
  }
  else
  {
LABEL_8:
    luaK_code(fs, i: ((from | ((from + n - 1) << 17)) << 6) | 3, line: fs->ls->lastline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A600
// Name: int luaK_jump(struct FuncState __near *)
// Source: json
//------------------------------------------------------------------------------
FuncState *__cdecl luaK_jump(FuncState *fs)
{
  FuncState *v1; // esi
  LexState *ls; // eax
  int jpc; // edi

  v1 = fs;
  ls = fs->ls;
  jpc = fs->jpc;
  fs->jpc = -1;
  fs = (FuncState *)luaK_code(fs: v1, i: 0x7FFF8016u, line: ls->lastline);
  luaK_concat(fs: v1, l1: (int *)&fs, l2: jpc);
  return fs;
}

//------------------------------------------------------------------------------
// Address: 0x0048A640
// Name: void luaK_ret(struct FuncState __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_ret(FuncState *fs, int first, int nret)
{
  luaK_code(fs, i: (first << 6) | ((nret + 1) << 23) | 0x1E, line: fs->ls->lastline);
}

//------------------------------------------------------------------------------
// Address: 0x0048A670
// Name: void luaK_patchtohere(struct FuncState __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_patchtohere(FuncState *fs, int list)
{
  fs->lasttarget = fs->pc;
  luaK_concat(fs, l1: &fs->jpc, l2: list);
}

//------------------------------------------------------------------------------
// Address: 0x0048A690
// Name: void luaK_dischargevars(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_dischargevars(FuncState *fs, expdesc *e)
{
  int aux; // eax
  int info; // eax

  switch ( e->k )
  {
    case VLOCAL:
      e->k = VNONRELOC;
      break;
    case VUPVAL:
      e->u.s.info = luaK_code(fs, i: (e->u.s.info << 23) | 4, line: fs->ls->lastline);
      e->k = VRELOCABLE;
      break;
    case VGLOBAL:
      e->u.s.info = luaK_code(fs, i: (e->u.s.info << 14) | 5, line: fs->ls->lastline);
      e->k = VRELOCABLE;
      break;
    case VINDEXED:
      aux = e->u.s.aux;
      if ( (aux & 0x100) == 0 && aux >= fs->nactvar )
        --fs->freereg;
      info = e->u.s.info;
      if ( (info & 0x100) == 0 && info >= fs->nactvar )
        --fs->freereg;
      e->u.s.info = luaK_code(fs, i: ((e->u.s.aux | (e->u.s.info << 9)) << 14) | 6, line: fs->ls->lastline);
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
// Address: 0x0048A7A0
// Name: discharge2reg
// Source: json
//------------------------------------------------------------------------------
void __usercall discharge2reg(FuncState *fs@<eax>, int reg@<edi>, expdesc *e)
{
  int v4; // eax
  int info; // eax
  lua_TValue k; // [esp+8h] [ebp-10h] BYREF

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
      v4 = addk(fs, v: &k);
      luaK_code(fs, i: ((reg | (v4 << 8)) << 6) | 1, line: fs->ls->lastline);
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
// Address: 0x0048A900
// Name: discharge2anyreg
// Source: json
//------------------------------------------------------------------------------
void __usercall discharge2anyreg(FuncState *fs@<esi>, expdesc *e)
{
  int v2; // ebx

  if ( e->k != VNONRELOC )
  {
    v2 = fs->freereg + 1;
    if ( v2 > fs->f->maxstacksize )
    {
      if ( v2 >= 250 )
        luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
      fs->f->maxstacksize = v2;
    }
    discharge2reg(fs, reg: fs->freereg++, e);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A960
// Name: exp2reg
// Source: json
//------------------------------------------------------------------------------
void __usercall exp2reg(FuncState *fs@<eax>, int e, int reg)
{
  _DWORD *v3; // ebx
  int v5; // edx
  int v6; // edi
  int jpc; // edi
  LexState *ls; // edx
  int v9; // edi
  LexState *v10; // ecx
  int v11; // eax
  LexState *v12; // edx
  int pc; // edi
  int v14; // edx
  expdesc *v15; // [esp-14h] [ebp-28h]
  int v16; // [esp-8h] [ebp-1Ch]
  int p_t; // [esp+Ch] [ebp-8h]
  int p_f; // [esp+10h] [ebp-4h]

  v3 = (_DWORD *)e;
  discharge2reg(fs, reg, (expdesc *)e);
  if ( *v3 == 10 )
    luaK_concat(fs, l1: v3 + 4, l2: v3[2]);
  v5 = v3[4];
  v6 = v3[5];
  if ( v5 != v6 )
  {
    p_f = -1;
    p_t = -1;
    if ( need_value(fs, list: v5) != 0 || need_value(fs, list: v6) != 0 )
    {
      if ( *v3 == 10 )
      {
        e = -1;
      }
      else
      {
        jpc = fs->jpc;
        ls = fs->ls;
        fs->jpc = -1;
        e = luaK_code(fs, i: 0x7FFF8016u, line: ls->lastline);
        luaK_concat(fs, l1: &e, l2: jpc);
      }
      v9 = reg;
      v10 = fs->ls;
      fs->lasttarget = fs->pc;
      v9 <<= 6;
      v11 = luaK_code(fs, i: v9 | 0x4002, line: v10->lastline);
      v12 = fs->ls;
      p_f = v11;
      fs->lasttarget = fs->pc;
      p_t = luaK_code(fs, i: v9 | 0x800002, line: v12->lastline);
      v15 = (expdesc *)e;
      fs->lasttarget = fs->pc;
      luaK_concat(fs, l1: &fs->jpc, l2: (int)v15);
    }
    pc = fs->pc;
    v16 = reg;
    fs->lasttarget = pc;
    patchlistaux(list: v3[5], fs, vtarget: pc, reg: v16, dtarget: p_f);
    patchlistaux(list: v3[4], fs, vtarget: pc, reg, dtarget: p_t);
  }
  v14 = reg;
  v3[4] = -1;
  v3[5] = -1;
  v3[2] = v14;
  *v3 = 12;
}

//------------------------------------------------------------------------------
// Address: 0x0048AAB0
// Name: void luaK_exp2nextreg(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_exp2nextreg(FuncState *fs, expdesc *e)
{
  int info; // eax
  int v3; // ebx

  luaK_dischargevars(fs, e);
  if ( e->k == VNONRELOC )
  {
    info = e->u.s.info;
    if ( (info & 0x100) == 0 && info >= fs->nactvar )
      --fs->freereg;
  }
  v3 = fs->freereg + 1;
  if ( v3 > fs->f->maxstacksize )
  {
    if ( v3 >= 250 )
      luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
    fs->f->maxstacksize = v3;
  }
  exp2reg(fs, (int)e, reg: fs->freereg++);
}

//------------------------------------------------------------------------------
// Address: 0x0048AB30
// Name: int luaK_exp2anyreg(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_exp2anyreg(FuncState *fs, expdesc *e)
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
    exp2reg(fs, (int)e, reg: e->u.s.info);
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
// Address: 0x0048AB90
// Name: void luaK_exp2val(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_exp2val(FuncState *fs, expdesc *e)
{
  if ( e->t == e->f )
  {
    luaK_dischargevars(fs, e);
    return;
  }
  luaK_dischargevars(fs, e);
  if ( e->k != VNONRELOC )
    goto LABEL_7;
  if ( e->t == e->f )
    return;
  if ( e->u.s.info < fs->nactvar )
  {
LABEL_7:
    luaK_exp2nextreg(fs, e);
    return;
  }
  exp2reg(fs, (int)e, reg: e->u.s.info);
}

//------------------------------------------------------------------------------
// Address: 0x0048AC00
// Name: int luaK_exp2RK(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaK_exp2RK(FuncState *fs, expdesc *e)
{
  expkind v2; // eax
  Table *h; // eax
  int info; // eax
  int v5; // eax
  int result; // eax
  lua_TValue v7; // [esp+10h] [ebp-20h] BYREF
  lua_TValue k; // [esp+20h] [ebp-10h] BYREF

  luaK_exp2val(fs, e);
  v2 = e->k;
  switch ( e->k )
  {
    case VNIL:
    case VTRUE:
    case VFALSE:
    case VKNUM:
      if ( fs->nk > 255 )
        goto LABEL_11;
      if ( v2 == VNIL )
      {
        h = fs->h;
        v7.tt = 0;
        k.value.b = (int)h;
        k.tt = 5;
        info = addk(fs, v: &v7);
LABEL_8:
        e->u.s.info = info;
        e->k = VK;
        return info | 0x100;
      }
      if ( v2 != VKNUM )
      {
        k.tt = 1;
        k.value.b = v2 == VTRUE;
        info = addk(fs, v: &k);
        goto LABEL_8;
      }
      v5 = luaK_numberK(fs, r: e->u.nval);
      e->u.s.info = v5;
      e->k = VK;
      return v5 | 0x100;
    case VK:
      info = e->u.s.info;
      if ( info > 255 )
        goto LABEL_11;
      return info | 0x100;
    default:
LABEL_11:
      luaK_dischargevars(fs, e);
      if ( e->k != VNONRELOC )
        goto LABEL_15;
      result = e->u.s.info;
      if ( e->t != e->f )
      {
        if ( result < fs->nactvar )
        {
LABEL_15:
          luaK_exp2nextreg(fs, e);
          return e->u.s.info;
        }
        else
        {
          exp2reg(fs, (int)e, reg: e->u.s.info);
          return e->u.s.info;
        }
      }
      return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AD30
// Name: void luaK_storevar(struct FuncState __near *,struct expdesc __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_storevar(FuncState *fs, expdesc *var, expdesc *ex)
{
  int info; // ecx
  int v4; // eax
  int lastline; // ecx
  unsigned int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ebx

  switch ( var->k )
  {
    case VLOCAL:
      if ( ex->k == VNONRELOC )
      {
        info = ex->u.s.info;
        if ( (info & 0x100) == 0 && info >= fs->nactvar )
          --fs->freereg;
      }
      exp2reg(fs, e: (int)ex, reg: var->u.s.info);
      return;
    case VUPVAL:
      v4 = luaK_exp2anyreg(fs, e: ex);
      lastline = fs->ls->lastline;
      v6 = ((v4 | (var->u.s.info << 17)) << 6) | 8;
      goto LABEL_10;
    case VGLOBAL:
      v7 = luaK_exp2anyreg(fs, e: ex);
      luaK_code(fs, i: ((v7 | (var->u.s.info << 8)) << 6) | 7, line: fs->ls->lastline);
      goto LABEL_11;
    case VINDEXED:
      v8 = luaK_exp2RK(fs, e: ex);
      lastline = fs->ls->lastline;
      v6 = ((var->u.s.info | ((v8 | (var->u.s.aux << 9)) << 8)) << 6) | 9;
LABEL_10:
      luaK_code(fs, i: v6, line: lastline);
      goto LABEL_11;
    default:
LABEL_11:
      if ( ex->k == VNONRELOC )
      {
        v9 = ex->u.s.info;
        if ( (v9 & 0x100) == 0 && v9 >= fs->nactvar )
          --fs->freereg;
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AE20
// Name: void luaK_self(struct FuncState __near *,struct expdesc __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_self(FuncState *fs, expdesc *e, expdesc *key)
{
  int info; // eax
  int freereg; // ebx
  int v5; // eax
  int v6; // eax

  luaK_dischargevars(fs, e);
  if ( e->k != VNONRELOC )
    goto LABEL_5;
  if ( e->t != e->f )
  {
    if ( e->u.s.info >= fs->nactvar )
    {
      exp2reg(fs, (int)e, reg: e->u.s.info);
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
  if ( freereg + 2 > fs->f->maxstacksize )
  {
    if ( freereg + 2 >= 250 )
      luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
    fs->f->maxstacksize = freereg + 2;
  }
  fs->freereg += 2;
  v5 = luaK_exp2RK(fs, e: key);
  luaK_code(fs, i: ((freereg | ((v5 | (e->u.s.info << 9)) << 8)) << 6) | 0xB, line: fs->ls->lastline);
  if ( key->k == VNONRELOC )
  {
    v6 = key->u.s.info;
    if ( (v6 & 0x100) == 0 && v6 >= fs->nactvar )
      --fs->freereg;
  }
  e->u.s.info = freereg;
  e->k = VNONRELOC;
}

//------------------------------------------------------------------------------
// Address: 0x0048AF10
// Name: jumponcond
// Source: json
//------------------------------------------------------------------------------
expdesc *__usercall jumponcond@<eax>(FuncState *fs@<eax>, expdesc *e, int cond)
{
  expdesc *v3; // ebx
  unsigned int v5; // eax
  LexState *ls; // edx
  int jpc; // edi
  int maxstacksize; // edx
  int v9; // eax
  int info; // eax

  v3 = e;
  if ( e->k == VRELOCABLE && ((v5 = fs->f->code[e->u.s.info]) & 0x3F) == 0x13 )
  {
    ls = fs->ls;
    --fs->pc;
    luaK_code(fs, i: ((cond == 0) << 14) | ((v5 & 0xFF81FFFF | 0x340000) >> 17), line: ls->lastline);
    jpc = fs->jpc;
    fs->jpc = -1;
  }
  else
  {
    if ( e->k == VNONRELOC )
      goto LABEL_10;
    maxstacksize = fs->f->maxstacksize;
    v9 = fs->freereg + 1;
    e = (expdesc *)v9;
    if ( v9 > maxstacksize )
    {
      if ( v9 >= 250 )
        luaX_syntaxerror(ls: fs->ls, msg: "function or expression too complex");
      fs->f->maxstacksize = v9;
    }
    discharge2reg(fs, reg: fs->freereg++, e: v3);
    if ( v3->k == VNONRELOC )
    {
LABEL_10:
      info = v3->u.s.info;
      if ( (info & 0x100) == 0 && info >= fs->nactvar )
        --fs->freereg;
    }
    luaK_code(fs, i: ((cond | (v3->u.s.info << 9)) << 14) | 0x3FDB, line: fs->ls->lastline);
    jpc = fs->jpc;
    fs->jpc = -1;
  }
  e = (expdesc *)luaK_code(fs, i: 0x7FFF8016u, line: fs->ls->lastline);
  luaK_concat(fs, l1: (int *)&e, l2: jpc);
  return e;
}

//------------------------------------------------------------------------------
// Address: 0x0048B030
// Name: void luaK_goiftrue(struct FuncState __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_goiftrue(FuncState *fs, expdesc *e)
{
  int info; // eax
  int t; // [esp-10h] [ebp-18h]

  luaK_dischargevars(fs, e);
  switch ( e->k )
  {
    case VTRUE:
    case VK:
    case VKNUM:
      info = -1;
      break;
    case VFALSE:
      info = (int)luaK_jump(fs);
      break;
    case VJMP:
      invertjump(fs, e);
      info = e->u.s.info;
      break;
    default:
      info = (int)jumponcond(fs, e, cond: 0);
      break;
  }
  luaK_concat(fs, l1: &e->f, l2: info);
  t = e->t;
  fs->lasttarget = fs->pc;
  luaK_concat(fs, l1: &fs->jpc, l2: t);
  e->t = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0048B0E0
// Name: luaK_goiffalse
// Source: json
//------------------------------------------------------------------------------
void __usercall luaK_goiffalse(FuncState *fs@<esi>, expdesc *e@<edi>)
{
  int info; // eax
  int f; // [esp-8h] [ebp-10h]
  FuncState *v4; // [esp+0h] [ebp-8h]
  expdesc *v5; // [esp+4h] [ebp-4h]

  luaK_dischargevars(fs: v4, e: v5);
  switch ( e->k )
  {
    case VNIL:
    case VFALSE:
      info = -1;
      break;
    case VTRUE:
      info = (int)luaK_jump(fs);
      break;
    case VJMP:
      info = e->u.s.info;
      break;
    default:
      info = (int)jumponcond(fs, e, cond: 1);
      break;
  }
  luaK_concat(fs, l1: &e->t, l2: info);
  f = e->f;
  fs->lasttarget = fs->pc;
  luaK_concat(fs, l1: &fs->jpc, l2: f);
  e->f = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0048B170
// Name: codenot
// Source: json
//------------------------------------------------------------------------------
void __usercall codenot(FuncState *fs@<eax>, expdesc *e@<edi>)
{
  int info; // eax
  int t; // edx
  FuncState *v5; // edx

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
  removevalues(fs: v5, list: e->t);
}

//------------------------------------------------------------------------------
// Address: 0x0048B240
// Name: void luaK_indexed(struct FuncState __near *,struct expdesc __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_indexed(FuncState *fs, expdesc *t, expdesc *k)
{
  t->u.s.aux = luaK_exp2RK(fs, e: k);
  t->k = VINDEXED;
}

//------------------------------------------------------------------------------
// Address: 0x0048B270
// Name: codearith
// Source: json
//------------------------------------------------------------------------------
void __usercall codearith(FuncState *fs@<edi>, OpCode op, expdesc *e1, expdesc *e2)
{
  int v4; // eax
  OpCode v5; // edx
  int v6; // esi
  int v7; // eax
  int info; // ecx
  int v9; // ecx
  int o2; // [esp+8h] [ebp-4h]

  if ( constfolding(op, e1, e2) == 0 )
  {
    v4 = luaK_exp2RK(fs, e: e1);
    v5 = op;
    v6 = v4;
    if ( op == OP_UNM || op == OP_LEN )
    {
      o2 = 0;
    }
    else
    {
      v7 = luaK_exp2RK(fs, e: e2);
      v5 = op;
      o2 = v7;
    }
    if ( e2->k == VNONRELOC )
    {
      info = e2->u.s.info;
      if ( (info & 0x100) == 0 && info >= fs->nactvar )
        --fs->freereg;
    }
    if ( e1->k == VNONRELOC )
    {
      v9 = e1->u.s.info;
      if ( (v9 & 0x100) == 0 && v9 >= fs->nactvar )
        --fs->freereg;
    }
    e1->u.s.info = luaK_code(fs, i: v5 | ((o2 | (v6 << 9)) << 14), line: fs->ls->lastline);
    e1->k = VRELOCABLE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B330
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
  luaK_concat(fs, l1: &cond, l2: jpc);
  v10->u.s.info = cond;
  v10->k = VJMP;
}

//------------------------------------------------------------------------------
// Address: 0x0048B400
// Name: void luaK_prefix(struct FuncState __near *,enum UnOpr,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_prefix(FuncState *fs, UnOpr op, expdesc *e)
{
  expdesc e2; // [esp+0h] [ebp-18h] BYREF

  e2.f = -1;
  e2.t = -1;
  e2.k = VKNUM;
  e2.u.nval = 0.0;
  if ( op != OPR_MINUS )
  {
    if ( op == OPR_NOT )
    {
      codenot(fs, e);
    }
    else if ( op == OPR_LEN )
    {
      luaK_exp2anyreg(fs, e);
      codearith(fs, op: OP_LEN, e1: e, &e2);
    }
  }
  else
  {
    if ( e->k == VK )
      luaK_exp2anyreg(fs, e);
    codearith(fs, op: OP_UNM, e1: e, &e2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B490
// Name: void luaK_infix(struct FuncState __near *,enum BinOpr,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_infix(FuncState *fs, BinOpr op, expdesc *v)
{
  switch ( op )
  {
    case OPR_CONCAT:
      luaK_exp2nextreg(fs, e: v);
      break;
    case OPR_AND:
      luaK_goiftrue(fs, e: v);
      break;
    case OPR_OR:
      luaK_goiffalse(fs, e: v);
      break;
    default:
      if ( v->k != VKNUM || v->t != -1 || v->f != -1 )
        luaK_exp2RK(fs, e: v);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B500
// Name: void luaK_posfix(struct FuncState __near *,enum BinOpr,struct expdesc __near *,struct expdesc __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_posfix(FuncState *fs, BinOpr op, expdesc *e1, expdesc *e2)
{
  expdesc *v4; // esi
  expdesc *v5; // edi
  unsigned int *v6; // eax

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
        v6 = &fs->f->code[e2->u.s.info];
        *v6 = *v6 & 0x7FFFFF | (e1->u.s.info << 23);
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
      v4 = e2;
      luaK_dischargevars(fs, e: e2);
      v5 = e1;
      luaK_concat(fs, l1: &e2->f, l2: e1->f);
      goto LABEL_4;
    case OPR_OR:
      v4 = e2;
      luaK_dischargevars(fs, e: e2);
      v5 = e1;
      luaK_concat(fs, l1: &e2->t, l2: e1->t);
LABEL_4:
      *(_QWORD *)&v5->k = *(_QWORD *)&v4->k;
      v5->u.nval = v4->u.nval;
      *(_QWORD *)&v5->t = *(_QWORD *)&v4->t;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B780
// Name: void luaK_patchlist(struct FuncState __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaK_patchlist(FuncState *fs, int list, int target)
{
  int pc; // ecx

  pc = fs->pc;
  if ( target == pc )
  {
    fs->lasttarget = pc;
    luaK_concat(fs, l1: &fs->jpc, l2: list);
  }
  else
  {
    patchlistaux(list, fs, vtarget: target, reg: 255, dtarget: target);
  }
}
