// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ldump.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000AD60
// Name: DumpString
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpString(const TString *s@<eax>, DumpState *D@<esi>)
{
  const TString *v2; // edi
  bool v3; // zf
  unsigned int size; // [esp+4h] [ebp-4h] BYREF

  if ( s == nullptr || (v2 = s + 1, s == (const TString *)-24) )
  {
    v3 = D->status == 0;
    size = 0;
    if ( v3 )
      D->status = D->writer(a1: D->L, a2: &size, a3: 4u, a4: D->data);
  }
  else
  {
    v3 = D->status == 0;
    size = s->tsv.len + 1;
    if ( v3 )
    {
      D->status = D->writer(a1: D->L, a2: &size, a3: 4u, a4: D->data);
      if ( D->status == 0 )
        D->status = D->writer(a1: D->L, a2: v2, a3: size, a4: D->data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ADF0
// Name: DumpConstants
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpConstants(DumpState *D@<eax>, const Proto *f)
{
  bool v3; // zf
  int sizek; // edi
  int v5; // ebx
  lua_TValue *k; // edi
  char tt; // al
  lua_TValue *v8; // edi
  int v9; // eax
  int sizep; // ebx
  int j; // edi
  long double n; // [esp+10h] [ebp-14h] BYREF
  int i; // [esp+18h] [ebp-Ch] BYREF
  _BYTE v14[5]; // [esp+1Fh] [ebp-5h] BYREF

  v3 = D->status == 0;
  sizek = f->sizek;
  i = sizek;
  if ( v3 )
    D->status = D->writer(a1: D->L, a2: &i, a3: 4u, a4: D->data);
  if ( sizek > 0 )
  {
    v5 = 0;
    for ( i = sizek; i != 0; --i )
    {
      k = f->k;
      tt = k[v5].tt;
      v8 = &k[v5];
      v3 = D->status == 0;
      v14[0] = tt;
      if ( v3 )
        D->status = D->writer(a1: D->L, a2: v14, a3: 1u, a4: D->data);
      if ( v8->tt == 1 )
      {
        v3 = D->status == 0;
        v14[0] = LOBYTE(v8->value.n);
        if ( v3 )
        {
          v9 = D->writer(a1: D->L, a2: v14, a3: 1u, a4: D->data);
          goto LABEL_15;
        }
      }
      else
      {
        if ( v8->tt != 3 )
        {
          if ( v8->tt == 4 )
            DumpString(s: (const TString *)v8->value.gc, D);
          goto LABEL_16;
        }
        v3 = D->status == 0;
        n = v8->value.n;
        if ( v3 )
        {
          v9 = D->writer(a1: D->L, a2: &n, a3: 8u, a4: D->data);
LABEL_15:
          D->status = v9;
        }
      }
LABEL_16:
      ++v5;
    }
  }
  v3 = D->status == 0;
  sizep = f->sizep;
  i = sizep;
  if ( v3 )
    D->status = D->writer(a1: D->L, a2: &i, a3: 4u, a4: D->data);
  for ( j = 0; j < sizep; ++j )
    DumpFunction(f: f->p[j], p: f->source, D);
}

//------------------------------------------------------------------------------
// Address: 0x1000AF20
// Name: DumpDebug
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpDebug(DumpState *D@<esi>, const Proto *f)
{
  int sizelineinfo; // ebx
  bool v3; // zf
  int *lineinfo; // edi
  int v5; // eax
  int sizelocvars; // ebx
  int v7; // edi
  TString *varname; // eax
  TString *v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // edi
  TString *v14; // eax
  TString *v15; // ebx
  int v16; // eax
  int v17; // eax
  int endpc; // [esp+8h] [ebp-10h] BYREF
  int startpc; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v20; // [esp+10h] [ebp-8h] BYREF
  int n; // [esp+14h] [ebp-4h] BYREF

  if ( D->strip != 0 )
    sizelineinfo = 0;
  else
    sizelineinfo = f->sizelineinfo;
  v3 = D->status == 0;
  lineinfo = f->lineinfo;
  v20 = sizelineinfo;
  if ( v3 )
  {
    v5 = D->writer(a1: D->L, a2: &v20, a3: 4u, a4: D->data);
    D->status = v5;
    if ( v5 == 0 )
      D->status = D->writer(a1: D->L, a2: lineinfo, a3: 4 * sizelineinfo, a4: D->data);
  }
  if ( D->strip != 0 )
    sizelocvars = 0;
  else
    sizelocvars = f->sizelocvars;
  v3 = D->status == 0;
  v20 = sizelocvars;
  if ( v3 )
    D->status = D->writer(a1: D->L, a2: &v20, a3: 4u, a4: D->data);
  if ( sizelocvars > 0 )
  {
    v7 = 0;
    v20 = sizelocvars;
    while ( 1 )
    {
      varname = f->locvars[v7].varname;
      if ( varname != nullptr )
      {
        v9 = varname + 1;
        if ( varname != (TString *)-24 )
          break;
      }
      v3 = D->status == 0;
      n = 0;
      if ( v3 )
      {
        v11 = D->writer(a1: D->L, a2: &n, a3: 4u, a4: D->data);
LABEL_21:
        D->status = v11;
      }
LABEL_22:
      v3 = D->status == 0;
      startpc = f->locvars[v7].startpc;
      if ( v3 )
        D->status = D->writer(a1: D->L, a2: &startpc, a3: 4u, a4: D->data);
      v3 = D->status == 0;
      endpc = f->locvars[v7].endpc;
      if ( v3 )
        D->status = D->writer(a1: D->L, a2: &endpc, a3: 4u, a4: D->data);
      ++v7;
      if ( --v20 == 0 )
        goto LABEL_27;
    }
    v3 = D->status == 0;
    n = varname->tsv.len + 1;
    if ( !v3 )
      goto LABEL_22;
    v10 = D->writer(a1: D->L, a2: &n, a3: 4u, a4: D->data);
    D->status = v10;
    if ( v10 != 0 )
      goto LABEL_22;
    v11 = D->writer(a1: D->L, a2: v9, a3: n, a4: D->data);
    goto LABEL_21;
  }
LABEL_27:
  if ( D->strip != 0 )
    n = 0;
  else
    n = f->sizeupvalues;
  v3 = D->status == 0;
  v12 = n;
  endpc = n;
  if ( v3 )
    D->status = D->writer(a1: D->L, a2: &endpc, a3: 4u, a4: D->data);
  v13 = 0;
  if ( v12 > 0 )
  {
    while ( 1 )
    {
      v14 = f->upvalues[v13];
      if ( v14 != nullptr )
      {
        v15 = v14 + 1;
        if ( v14 != (TString *)-24 )
          break;
      }
      v3 = D->status == 0;
      endpc = 0;
      if ( v3 )
      {
        v17 = D->writer(a1: D->L, a2: &endpc, a3: 4u, a4: D->data);
LABEL_40:
        D->status = v17;
      }
LABEL_41:
      if ( ++v13 >= n )
        return;
    }
    v3 = D->status == 0;
    v20 = v14->tsv.len + 1;
    if ( !v3 )
      goto LABEL_41;
    v16 = D->writer(a1: D->L, a2: &v20, a3: 4u, a4: D->data);
    D->status = v16;
    if ( v16 != 0 )
      goto LABEL_41;
    v17 = D->writer(a1: D->L, a2: v15, a3: v20, a4: D->data);
    goto LABEL_40;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B170
// Name: DumpFunction
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpFunction(const Proto *f, const TString *p, DumpState *D)
{
  TString *source; // eax
  bool v4; // zf
  int sizecode; // ebx
  int v6; // eax
  unsigned __int8 nups; // [esp+Fh] [ebp-9h] BYREF
  int linedefined; // [esp+10h] [ebp-8h] BYREF
  unsigned int *code; // [esp+14h] [ebp-4h]

  source = f->source;
  if ( source == p || D->strip != 0 )
    source = nullptr;
  DumpString(s: source, D);
  v4 = D->status == 0;
  linedefined = f->linedefined;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &linedefined, a3: 4u, a4: D->data);
  v4 = D->status == 0;
  linedefined = f->lastlinedefined;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &linedefined, a3: 4u, a4: D->data);
  v4 = D->status == 0;
  nups = f->nups;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &nups, a3: 1u, a4: D->data);
  v4 = D->status == 0;
  nups = f->numparams;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &nups, a3: 1u, a4: D->data);
  v4 = D->status == 0;
  nups = f->is_vararg;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &nups, a3: 1u, a4: D->data);
  v4 = D->status == 0;
  nups = f->maxstacksize;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &nups, a3: 1u, a4: D->data);
  v4 = D->status == 0;
  sizecode = f->sizecode;
  code = f->code;
  linedefined = sizecode;
  if ( v4 )
  {
    v6 = D->writer(a1: D->L, a2: &linedefined, a3: 4u, a4: D->data);
    D->status = v6;
    if ( v6 == 0 )
      D->status = D->writer(a1: D->L, a2: code, a3: 4 * sizecode, a4: D->data);
  }
  DumpConstants(D, f);
  DumpDebug(D, f);
}

//------------------------------------------------------------------------------
// Address: 0x1000B2F0
// Name: _luaU_dump
// Source: json
//------------------------------------------------------------------------------
int __usercall luaU_dump@<eax>(lua_State *L@<ecx>, void *data@<eax>, const Proto *f)
{
  DumpState D; // [esp+4h] [ebp-20h] BYREF
  _DWORD b[3]; // [esp+18h] [ebp-Ch] BYREF

  D.data = data;
  D.L = L;
  D.writer = writer;
  D.strip = 0;
  b[0] = 1635077147;
  b[1] = 67174481;
  b[2] = 525316;
  D.status = writer(L, b, size: 0xCu, B: data);
  DumpFunction(f, p: nullptr, &D);
  return D.status;
}
