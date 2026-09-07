// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lfunc.c
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047CC50
// Name: union Closure __near * luaF_newCclosure(struct lua_State __near *,int,struct Table __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaF_newCclosure(lua_State *L, int nelems, Table *e)
{
  GCObject *v3; // esi

  v3 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 16 * nelems + 24);
  luaC_link(L, o: v3, tt: 6u);
  v3->cl.c.nupvalues = nelems;
  v3->ts.tsv.reserved = 1;
  v3->ts.tsv.len = (unsigned int)e;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047CCA0
// Name: union Closure __near * luaF_newLclosure(struct lua_State __near *,int,struct Table __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaF_newLclosure(lua_State *L, int nelems, Table *e)
{
  int v3; // ebx
  GCObject *v4; // esi
  UpVal **v5; // eax

  v3 = nelems;
  v4 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 4 * nelems + 20);
  luaC_link(L, o: v4, tt: 6u);
  v4->ts.tsv.reserved = 0;
  v4->ts.tsv.len = (unsigned int)e;
  v4->cl.c.nupvalues = nelems;
  if ( nelems != 0 )
  {
    v5 = &v4->cl.l.upvals[nelems];
    do
    {
      --v5;
      --v3;
      *v5 = nullptr;
    }
    while ( v3 != 0 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047CD00
// Name: struct UpVal __near * luaF_newupval(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaF_newupval(lua_State *L)
{
  GCObject *v1; // esi

  v1 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x20u);
  luaC_link(L, o: v1, tt: 0xAu);
  v1->ts.tsv.hash = (unsigned int)&v1->u.uv.len;
  v1->cl.c.upvalue[0].value.b = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CD40
// Name: struct UpVal __near * luaF_findupval(struct lua_State __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaF_findupval(lua_State *L, lua_TValue *level)
{
  GCObject *result; // eax
  global_State *l_G; // esi
  UpVal *i; // edi
  lua_TValue *k; // ecx
  unsigned __int8 currentwhite; // cl
  UpVal *next; // ecx

  result = L->openupval;
  l_G = L->l_G;
  for ( i = (UpVal *)&L->openupval; result != nullptr; result = (GCObject *)result->ts.dummy.l )
  {
    k = result->p.k;
    if ( k < level )
      break;
    if ( k == level )
    {
      if ( (result->gch.marked & 3 & (unsigned __int8)~l_G->currentwhite) != 0 )
        result->gch.marked ^= 3u;
      return result;
    }
    i = (UpVal *)result;
  }
  result = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x20u);
  result->gch.tt = 10;
  currentwhite = l_G->currentwhite;
  result->ts.tsv.hash = (unsigned int)level;
  result->gch.marked = currentwhite & 3;
  result->ts.dummy.l = (int)i->next;
  i->next = result;
  result->u.uv.len = (unsigned int)&l_G->uvhead;
  next = l_G->uvhead.u.l.next;
  result->cl.l.upvals[0] = next;
  next->u.value.value.b = (int)result;
  l_G->uvhead.u.l.next = (UpVal *)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CDE0
// Name: void luaF_freeupval(struct lua_State __near *,struct UpVal __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaF_freeupval(lua_State *L, UpVal *uv)
{
  UpVal::<unnamed_type_u> *p_u; // ecx

  p_u = &uv->u;
  if ( (UpVal::<unnamed_type_u> *)uv->v != &uv->u )
  {
    uv->u.l.next->u.value.value.b = p_u->value.value.b;
    *(_DWORD *)(p_u->value.value.b + 20) = uv->u.l.next;
  }
  luaM_realloc_(L, block: uv, osize: 0x20u, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047CE20
// Name: void luaF_close(struct lua_State __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaF_close(lua_State *L, lua_TValue *level)
{
  GCObject *openupval; // eax
  global_State *i; // edi
  int *p_b; // ecx
  int *hash; // edx

  openupval = L->openupval;
  for ( i = L->l_G; openupval != nullptr; openupval = L->openupval )
  {
    if ( openupval->ts.tsv.hash < (unsigned int)level )
      break;
    L->openupval = (GCObject *)openupval->ts.dummy.l;
    p_b = &openupval->uv.u.value.value.b;
    if ( (openupval->gch.marked & 3 & (unsigned __int8)~i->currentwhite) != 0 )
    {
      if ( (int *)openupval->ts.tsv.hash != p_b )
      {
        openupval->cl.l.upvals[0]->u.value.value.b = *p_b;
        *(_DWORD *)(*p_b + 20) = openupval->cl.l.upvals[0];
      }
      luaM_realloc_(L, block: openupval, osize: 0x20u, nsize: 0);
    }
    else
    {
      openupval->cl.l.upvals[0]->u.value.value.b = *p_b;
      *(_DWORD *)(*p_b + 20) = openupval->cl.l.upvals[0];
      hash = (int *)openupval->ts.tsv.hash;
      *p_b = *hash;
      openupval->cl.l.upvals[0] = (UpVal *)hash[1];
      openupval->cl.c.upvalue[0].value.b = hash[2];
      openupval->ts.tsv.hash = (unsigned int)p_b;
      luaC_linkupval(L, uv: openupval);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CEC0
// Name: struct Proto __near * luaF_newproto(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaF_newproto(lua_State *L)
{
  GCObject *v1; // esi

  v1 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x4Cu);
  luaC_link(L, o: v1, tt: 9u);
  v1->ts.tsv.hash = 0;
  v1->p.sizek = 0;
  v1->u.uv.len = 0;
  v1->p.sizep = 0;
  v1->ts.tsv.len = 0;
  v1->p.sizecode = 0;
  v1->p.sizelineinfo = 0;
  v1->p.sizeupvalues = 0;
  v1->h.sizearray = 0;
  v1->th.l_gt.value.b = 0;
  v1->cl.l.upvals[0] = nullptr;
  v1->p.sizelocvars = 0;
  v1->cl.c.upvalue[0].value.b = 0;
  v1->p.linedefined = 0;
  v1->p.lastlinedefined = 0;
  v1->cl.c.upvalue[0].tt = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CF20
// Name: void luaF_freeproto(struct lua_State __near *,struct Proto __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaF_freeproto(lua_State *L, Proto *f)
{
  luaM_realloc_(L, block: f->code, osize: 4 * f->sizecode, nsize: 0);
  luaM_realloc_(L, block: f->p, osize: 4 * f->sizep, nsize: 0);
  luaM_realloc_(L, block: f->k, osize: 16 * f->sizek, nsize: 0);
  luaM_realloc_(L, block: f->lineinfo, osize: 4 * f->sizelineinfo, nsize: 0);
  luaM_realloc_(L, block: f->locvars, osize: 12 * f->sizelocvars, nsize: 0);
  luaM_realloc_(L, block: f->upvalues, osize: 4 * f->sizeupvalues, nsize: 0);
  luaM_realloc_(L, block: f, osize: 0x4Cu, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047CFC0
// Name: void luaF_freeclosure(struct lua_State __near *,union Closure __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaF_freeclosure(lua_State *L, Closure *c)
{
  int nupvalues; // eax

  nupvalues = c->c.nupvalues;
  if ( c->c.isC != 0 )
    luaM_realloc_(L, block: c, osize: 16 * nupvalues + 24, nsize: 0);
  else
    luaM_realloc_(L, block: c, osize: 4 * nupvalues + 20, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047D010
// Name: char const __near * luaF_getlocalname(struct Proto const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
TString *__cdecl luaF_getlocalname(const Proto *f, int local_number, int pc)
{
  int sizelocvars; // edx
  int v4; // eax
  LocVar *locvars; // ebx
  int *i; // ecx

  sizelocvars = f->sizelocvars;
  v4 = 0;
  if ( sizelocvars > 0 )
  {
    locvars = f->locvars;
    for ( i = &locvars->endpc; *(i - 1) <= pc; i += 3 )
    {
      if ( pc < *i && --local_number == 0 )
        return locvars[v4].varname + 1;
      if ( ++v4 >= sizelocvars )
        return nullptr;
    }
  }
  return nullptr;
}
