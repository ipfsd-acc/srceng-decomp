// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lfunc.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000B350
// Name: _luaF_findupval
// Source: json
//------------------------------------------------------------------------------
GCObject *__usercall luaF_findupval@<eax>(lua_State *L@<edx>, lua_TValue *level)
{
  GCObject **p_openupval; // esi
  global_State *l_G; // edi
  GCObject *result; // eax
  lua_TValue *k; // ecx
  unsigned __int8 currentwhite; // cl
  UpVal *next; // ecx

  p_openupval = &L->openupval;
  l_G = L->l_G;
  if ( L->openupval != nullptr )
  {
    do
    {
      result = *p_openupval;
      k = (*p_openupval)->p.k;
      if ( k < level )
        break;
      if ( k == level )
      {
        if ( (result->gch.marked & 3 & (unsigned __int8)~l_G->currentwhite) != 0 )
          result->gch.marked ^= 3u;
        return result;
      }
      p_openupval = (GCObject **)*p_openupval;
    }
    while ( result->ts.dummy.l != 0 );
  }
  result = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x20u);
  result->gch.tt = 10;
  currentwhite = l_G->currentwhite;
  result->ts.tsv.hash = (unsigned int)level;
  result->gch.marked = currentwhite & 3;
  result->ts.dummy.l = (int)*p_openupval;
  *p_openupval = result;
  result->ts.tsv.len = (unsigned int)&l_G->uvhead;
  next = l_G->uvhead.u.l.next;
  result->cl.l.upvals[0] = next;
  next->u.value.value.b = (int)result;
  l_G->uvhead.u.l.next = (UpVal *)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B3E0
// Name: _luaF_freeupval
// Source: json
//------------------------------------------------------------------------------
void __usercall luaF_freeupval(UpVal *uv@<eax>, lua_State *L)
{
  $C479701A7A51E6F56A9D470293950FB8 *p_u; // ecx

  p_u = &uv->u;
  if ( ($C479701A7A51E6F56A9D470293950FB8 *)uv->v != &uv->u )
  {
    uv->u.l.next->u.value.value.b = p_u->value.value.b;
    *(_DWORD *)(p_u->value.value.b + 20) = uv->u.l.next;
  }
  luaM_realloc_(L, block: uv, osize: 0x20u, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000B410
// Name: _luaF_close
// Source: json
//------------------------------------------------------------------------------
void __usercall luaF_close(lua_State *L@<edi>, lua_TValue *level)
{
  GCObject *openupval; // ecx
  int *p_b; // eax
  int *hash; // edx
  global_State *l_G; // esi
  unsigned __int8 marked; // al
  unsigned int v7; // edx
  unsigned __int8 v8; // al
  GCObject *v9; // edx
  global_State *g; // [esp+0h] [ebp-4h]

  g = L->l_G;
  while ( L->openupval != nullptr )
  {
    openupval = L->openupval;
    if ( openupval->ts.tsv.hash < (unsigned int)level )
      break;
    L->openupval = (GCObject *)openupval->ts.dummy.l;
    p_b = &openupval->uv.u.value.value.b;
    if ( (openupval->gch.marked & 3 & (unsigned __int8)~g->currentwhite) != 0 )
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
      l_G = L->l_G;
      openupval->ts.dummy.l = (int)l_G->rootgc;
      l_G->rootgc = openupval;
      marked = openupval->gch.marked;
      if ( (marked & 7) == 0 )
      {
        if ( l_G->gcstate == 1 )
        {
          v7 = openupval->ts.tsv.hash;
          v8 = marked | 4;
          openupval->gch.marked = v8;
          if ( *(int *)(v7 + 8) >= 4 )
          {
            v9 = *(GCObject **)v7;
            if ( (v9->gch.marked & 3) != 0 && (v8 & 4) != 0 )
              luaC_barrierf(L, o: openupval, v: v9);
          }
        }
        else
        {
          openupval->gch.marked = marked & 0xF8 | l_G->currentwhite & 3;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B500
// Name: _luaF_freeproto
// Source: json
//------------------------------------------------------------------------------
void __usercall luaF_freeproto(lua_State *L@<eax>, Proto *f@<esi>)
{
  int v3; // ebx
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  global_State *v9; // edi
  global_State *l_G; // [esp+Ch] [ebp-4h]
  global_State *v11; // [esp+Ch] [ebp-4h]
  global_State *v12; // [esp+Ch] [ebp-4h]
  global_State *v13; // [esp+Ch] [ebp-4h]
  global_State *v14; // [esp+Ch] [ebp-4h]
  global_State *v15; // [esp+Ch] [ebp-4h]

  v3 = 4 * f->sizecode;
  l_G = L->l_G;
  l_G->frealloc(a1: l_G->ud, a2: f->code, a3: v3, a4: 0);
  l_G->totalbytes -= v3;
  v4 = 4 * f->sizep;
  v11 = L->l_G;
  v11->frealloc(a1: v11->ud, a2: f->p, a3: v4, a4: 0);
  v11->totalbytes -= v4;
  v5 = 16 * f->sizek;
  v12 = L->l_G;
  v12->frealloc(a1: v12->ud, a2: f->k, a3: v5, a4: 0);
  v12->totalbytes -= v5;
  v6 = 4 * f->sizelineinfo;
  v13 = L->l_G;
  v13->frealloc(a1: v13->ud, a2: f->lineinfo, a3: v6, a4: 0);
  v13->totalbytes -= v6;
  v7 = 12 * f->sizelocvars;
  v14 = L->l_G;
  v14->frealloc(a1: v14->ud, a2: f->locvars, a3: v7, a4: 0);
  v14->totalbytes -= v7;
  v8 = 4 * f->sizeupvalues;
  v15 = L->l_G;
  v15->frealloc(a1: v15->ud, a2: f->upvalues, a3: v8, a4: 0);
  v15->totalbytes -= v8;
  v9 = L->l_G;
  v9->frealloc(a1: v9->ud, a2: f, a3: 76u, a4: 0);
  v9->totalbytes -= 76;
}

//------------------------------------------------------------------------------
// Address: 0x1000B610
// Name: _luaF_getlocalname
// Source: json
//------------------------------------------------------------------------------
TString *__usercall luaF_getlocalname@<eax>(const Proto *f@<ecx>, int pc@<esi>, int local_number)
{
  int sizelocvars; // edx
  int v5; // eax
  LocVar *locvars; // edi
  int *i; // ecx

  sizelocvars = f->sizelocvars;
  v5 = 0;
  if ( sizelocvars > 0 )
  {
    locvars = f->locvars;
    for ( i = &locvars->endpc; *(i - 1) <= pc; i += 3 )
    {
      if ( pc < *i && --local_number == 0 )
        return locvars[v5].varname + 1;
      if ( ++v5 >= sizelocvars )
        return nullptr;
    }
  }
  return nullptr;
}
