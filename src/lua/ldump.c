// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ldump.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047D220
// Name: DumpString
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpString(const TString *s@<eax>, DumpState *D@<esi>)
{
  const TString *v2; // edi
  bool v3; // zf
  unsigned int size; // [esp+4h] [ebp-4h] BYREF

  if ( s == nullptr || (v2 = s + 1, s == (const TString *)-16) )
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
// Address: 0x0047D2B0
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
  long double n; // [esp+Ch] [ebp-10h] BYREF
  int i; // [esp+14h] [ebp-8h] BYREF
  char n_low; // [esp+1Bh] [ebp-1h] BYREF

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
      n_low = tt;
      if ( v3 )
        D->status = D->writer(a1: D->L, a2: &n_low, a3: 1u, a4: D->data);
      if ( v8->tt == 1 )
      {
        v3 = D->status == 0;
        n_low = LOBYTE(v8->value.n);
        if ( v3 )
        {
          v9 = D->writer(a1: D->L, a2: &n_low, a3: 1u, a4: D->data);
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
// Address: 0x0047D3E0
// Name: DumpDebug
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpDebug(DumpState *D@<eax>, const Proto *f)
{
  int sizelineinfo; // ebx
  bool v4; // zf
  int *lineinfo; // edi
  int v6; // eax
  int sizelocvars; // ebx
  int v8; // edi
  int v9; // ebx
  int v10; // edi
  TString *v11; // eax
  TString *v12; // ebx
  int v13; // eax
  int v14; // eax
  int endpc; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int startpc; // [esp+10h] [ebp-8h] BYREF
  int n; // [esp+14h] [ebp-4h]

  if ( D->strip != 0 )
    sizelineinfo = 0;
  else
    sizelineinfo = f->sizelineinfo;
  v4 = D->status == 0;
  lineinfo = f->lineinfo;
  startpc = sizelineinfo;
  if ( v4 )
  {
    v6 = D->writer(a1: D->L, a2: &startpc, a3: 4u, a4: D->data);
    D->status = v6;
    if ( v6 == 0 )
      D->status = D->writer(a1: D->L, a2: lineinfo, a3: 4 * sizelineinfo, a4: D->data);
  }
  if ( D->strip != 0 )
    sizelocvars = 0;
  else
    sizelocvars = f->sizelocvars;
  v4 = D->status == 0;
  startpc = sizelocvars;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &startpc, a3: 4u, a4: D->data);
  if ( sizelocvars > 0 )
  {
    v8 = 0;
    for ( n = sizelocvars; n != 0; --n )
    {
      DumpString(s: f->locvars[v8].varname, D);
      v4 = D->status == 0;
      startpc = f->locvars[v8].startpc;
      if ( v4 )
        D->status = D->writer(a1: D->L, a2: &startpc, a3: 4u, a4: D->data);
      v4 = D->status == 0;
      endpc = f->locvars[v8].endpc;
      if ( v4 )
        D->status = D->writer(a1: D->L, a2: &endpc, a3: 4u, a4: D->data);
      ++v8;
    }
  }
  if ( D->strip != 0 )
    n = 0;
  else
    n = f->sizeupvalues;
  v4 = D->status == 0;
  v9 = n;
  endpc = n;
  if ( v4 )
    D->status = D->writer(a1: D->L, a2: &endpc, a3: 4u, a4: D->data);
  v10 = 0;
  if ( v9 > 0 )
  {
    while ( 1 )
    {
      v11 = f->upvalues[v10];
      if ( v11 != nullptr )
      {
        v12 = v11 + 1;
        if ( v11 != (TString *)-16 )
          break;
      }
      v4 = D->status == 0;
      endpc = 0;
      if ( v4 )
      {
        v14 = D->writer(a1: D->L, a2: &endpc, a3: 4u, a4: D->data);
LABEL_32:
        D->status = v14;
      }
LABEL_33:
      if ( ++v10 >= n )
        return;
    }
    v4 = D->status == 0;
    startpc = v11->tsv.len + 1;
    if ( !v4 )
      goto LABEL_33;
    v13 = D->writer(a1: D->L, a2: &startpc, a3: 4u, a4: D->data);
    D->status = v13;
    if ( v13 != 0 )
      goto LABEL_33;
    v14 = D->writer(a1: D->L, a2: v12, a3: startpc, a4: D->data);
    goto LABEL_32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D5C0
// Name: DumpFunction
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpFunction(const Proto *f, const TString *p, DumpState *D)
{
  DumpState *v3; // esi
  const Proto *v4; // edi
  TString *source; // eax
  bool v6; // zf
  int sizecode; // ebx
  int v8; // eax

  v3 = D;
  v4 = f;
  source = f->source;
  if ( source == p || D->strip != 0 )
    source = nullptr;
  DumpString(s: source, D);
  v6 = v3->status == 0;
  f = (const Proto *)v4->linedefined;
  if ( v6 )
    v3->status = v3->writer(a1: v3->L, a2: &f, a3: 4u, a4: v3->data);
  v6 = v3->status == 0;
  f = (const Proto *)v4->lastlinedefined;
  if ( v6 )
    v3->status = v3->writer(a1: v3->L, a2: &f, a3: 4u, a4: v3->data);
  v6 = v3->status == 0;
  HIBYTE(f) = v4->nups;
  if ( v6 )
    v3->status = v3->writer(a1: v3->L, a2: (char *)&f + 3, a3: 1u, a4: v3->data);
  v6 = v3->status == 0;
  HIBYTE(f) = v4->numparams;
  if ( v6 )
    v3->status = v3->writer(a1: v3->L, a2: (char *)&f + 3, a3: 1u, a4: v3->data);
  v6 = v3->status == 0;
  HIBYTE(f) = v4->is_vararg;
  if ( v6 )
    v3->status = v3->writer(a1: v3->L, a2: (char *)&f + 3, a3: 1u, a4: v3->data);
  v6 = v3->status == 0;
  HIBYTE(f) = v4->maxstacksize;
  if ( v6 )
    v3->status = v3->writer(a1: v3->L, a2: (char *)&f + 3, a3: 1u, a4: v3->data);
  v6 = v3->status == 0;
  sizecode = v4->sizecode;
  p = (const TString *)v4->code;
  f = (const Proto *)sizecode;
  if ( v6 )
  {
    v8 = v3->writer(a1: v3->L, a2: &f, a3: 4u, a4: v3->data);
    v3->status = v8;
    if ( v8 == 0 )
      v3->status = v3->writer(a1: v3->L, a2: p, a3: 4 * sizecode, a4: v3->data);
  }
  DumpConstants(D: v3, f: v4);
  DumpDebug(D: v3, f: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0047D720
// Name: int luaU_dump(struct lua_State __near *,struct Proto const __near *,int (*)(struct lua_State __near *,void const __near *,unsigned int,void __near *),void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaU_dump(
        lua_State *L,
        const Proto *f,
        int (__cdecl *w)(lua_State *, const void *, unsigned int, void *),
        void *data,
        int strip)
{
  DumpState D; // [esp+0h] [ebp-20h] BYREF
  char h[12]; // [esp+14h] [ebp-Ch] BYREF

  D.writer = w;
  D.L = L;
  D.data = data;
  D.strip = strip;
  D.status = 0;
  luaU_header(h);
  D.status = D.writer(a1: D.L, a2: h, a3: 12u, a4: D.data);
  DumpFunction(f, p: nullptr, &D);
  return D.status;
}
