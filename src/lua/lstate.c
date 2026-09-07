// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lstate.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004768F0
// Name: stack_init
// Source: json
//------------------------------------------------------------------------------
void __usercall stack_init(lua_State *L1@<esi>, lua_State *L@<edi>)
{
  CallInfo *v2; // eax
  lua_TValue *v3; // eax
  CallInfo *ci; // edx
  CallInfo *v5; // eax
  lua_TValue *v6; // ecx

  v2 = (CallInfo *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0xC0u);
  L1->base_ci = v2;
  L1->ci = v2;
  L1->size_ci = 8;
  L1->end_ci = v2 + 7;
  v3 = (lua_TValue *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x2D0u);
  ci = L1->ci;
  L1->top = v3;
  L1->stack = v3;
  L1->stack_last = v3 + 39;
  L1->stacksize = 45;
  ci->func = v3;
  L1->top->tt = 0;
  L1->ci->base = ++L1->top;
  v5 = L1->ci;
  v6 = L1->top + 20;
  L1->base = v5->base;
  v5->top = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00476970
// Name: f_luaopen
// Source: json
//------------------------------------------------------------------------------
void __cdecl f_luaopen(lua_State *L)
{
  global_State *l_G; // ebx
  global_State *v2; // edi
  TString *v3; // eax

  l_G = L->l_G;
  stack_init(L1: L, L);
  L->l_gt.value.b = (int)luaH_new(L, narray: 0, nhash: 2);
  L->l_gt.tt = 5;
  v2 = L->l_G;
  v2->l_registry.value.b = (int)luaH_new(L, narray: 0, nhash: 2);
  v2->l_registry.tt = 5;
  luaS_resize(L, newsize: 32);
  luaT_init(L);
  luaX_init(L);
  v3 = luaS_newlstr(L, str: "not enough memory", l: 0x11u);
  v3->tsv.marked |= 0x20u;
  l_G->GCthreshold = 4 * l_G->totalbytes;
}

//------------------------------------------------------------------------------
// Address: 0x004769F0
// Name: close_state
// Source: json
//------------------------------------------------------------------------------
void __usercall close_state(lua_State *L@<esi>)
{
  global_State *l_G; // edi

  l_G = L->l_G;
  luaF_close(L, level: L->stack);
  luaC_freeall(L);
  luaM_realloc_(L, block: L->l_G->strt.hash, osize: 4 * L->l_G->strt.size, nsize: 0);
  l_G->buff.buffer = (char *)luaM_realloc_(L, block: l_G->buff.buffer, osize: l_G->buff.buffsize, nsize: 0);
  l_G->buff.buffsize = 0;
  luaM_realloc_(L, block: L->base_ci, osize: 24 * L->size_ci, nsize: 0);
  luaM_realloc_(L, block: L->stack, osize: 16 * L->stacksize, nsize: 0);
  l_G->frealloc(a1: l_G->ud, a2: L, a3: 376u, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00476A80
// Name: struct lua_State __near * luaE_newthread(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaE_newthread(lua_State *L)
{
  GCObject *v1; // esi
  int basehookcount; // eax

  v1 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x78u);
  luaC_link(L, o: v1, tt: 8u);
  v1->u.uv.len = (unsigned int)L->l_G;
  v1->cl.c.upvalue[0].tt = 0;
  v1->p.sizecode = 0;
  v1->th.errorJmp = nullptr;
  v1->p.lastlinedefined = 0;
  v1->p.sizelocvars = 0;
  v1->p.linedefined = 0;
  v1->th.openupval = nullptr;
  v1->p.sizelineinfo = 0;
  v1->p.sizep = 0x1000000;
  v1->ts.tsv.reserved = 0;
  v1->cl.l.upvals[0] = nullptr;
  v1->p.sizek = 0;
  v1->cl.c.upvalue[0].value.b = 0;
  v1->th.errfunc = 0;
  v1->th.l_gt.tt = 0;
  stack_init(L1: (lua_State *)v1, L);
  v1->th.l_gt = L->l_gt;
  v1->th.hookmask = L->hookmask;
  basehookcount = L->basehookcount;
  v1->p.sizelocvars = basehookcount;
  v1->p.lastlinedefined = (int)L->hook;
  v1->p.linedefined = basehookcount;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00476B10
// Name: void luaE_freethread(struct lua_State __near *,struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaE_freethread(lua_State *L, lua_State *L1)
{
  luaF_close(L: L1, level: L1->stack);
  luaM_realloc_(L, block: L1->base_ci, osize: 24 * L1->size_ci, nsize: 0);
  luaM_realloc_(L, block: L1->stack, osize: 16 * L1->stacksize, nsize: 0);
  luaM_realloc_(L, block: L1, osize: 0x78u, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00476B70
// Name: struct lua_State __near * lua_newstate(void __near * (*)(void __near *,void __near *,unsigned int,unsigned int),void __near *)
// Source: json
//------------------------------------------------------------------------------
lua_State *__cdecl lua_newstate(void *(__cdecl *f)(void *, void *, unsigned int, unsigned int), void *ud)
{
  char *v2; // esi

  v2 = (char *)f(a1: ud, a2: nullptr, a3: 0, a4: 376u);
  if ( v2 == nullptr )
    return nullptr;
  *(_DWORD *)v2 = 0;
  v2[4] = 8;
  v2[140] = 33;
  *((_DWORD *)v2 + 4) = v2 + 120;
  *((_DWORD *)v2 + 8) = 0;
  *((_DWORD *)v2 + 11) = 0;
  *((_DWORD *)v2 + 28) = 0;
  *((_DWORD *)v2 + 16) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 12) = 0;
  *((_DWORD *)v2 + 13) = 0x1000000;
  *(_WORD *)(v2 + 5) = 97;
  *((_DWORD *)v2 + 5) = 0;
  *((_DWORD *)v2 + 10) = 0;
  *((_DWORD *)v2 + 6) = 0;
  *((_DWORD *)v2 + 29) = 0;
  *((_DWORD *)v2 + 20) = 0;
  *((_DWORD *)v2 + 33) = f;
  *((_DWORD *)v2 + 34) = ud;
  *((_DWORD *)v2 + 58) = v2;
  *((_DWORD *)v2 + 46) = 0;
  *((_DWORD *)v2 + 32) = 0;
  *((_DWORD *)v2 + 31) = 0;
  *((_DWORD *)v2 + 30) = 0;
  *((_DWORD *)v2 + 64) = v2 + 240;
  *((_DWORD *)v2 + 65) = v2 + 240;
  *(_DWORD *)(*((_DWORD *)v2 + 4) + 104) = 0;
  *((_DWORD *)v2 + 37) = v2;
  *((_DWORD *)v2 + 43) = 0;
  *((_DWORD *)v2 + 45) = 0;
  *((_DWORD *)v2 + 52) = 0;
  v2[141] = 0;
  *((_DWORD *)v2 + 36) = 0;
  *((_DWORD *)v2 + 39) = 0;
  *((_DWORD *)v2 + 40) = 0;
  *((_DWORD *)v2 + 41) = 0;
  *((_DWORD *)v2 + 42) = 0;
  *((_DWORD *)v2 + 47) = 376;
  *((_DWORD *)v2 + 49) = 0;
  *((_DWORD *)v2 + 38) = v2 + 148;
  *((_DWORD *)v2 + 50) = 200;
  *((_DWORD *)v2 + 51) = 200;
  *((_DWORD *)v2 + 68) = 0;
  *((_DWORD *)v2 + 69) = 0;
  *((_DWORD *)v2 + 70) = 0;
  *((_DWORD *)v2 + 71) = 0;
  *((_DWORD *)v2 + 72) = 0;
  *((_DWORD *)v2 + 73) = 0;
  *((_DWORD *)v2 + 74) = 0;
  *((_DWORD *)v2 + 75) = 0;
  *((_DWORD *)v2 + 76) = 0;
  if ( luaD_rawrunprotected(L: (lua_State *)v2, f: (void (__cdecl *)(lua_State *, void *))f_luaopen, ud: nullptr) != 0 )
  {
    close_state(L: (lua_State *)v2);
    return nullptr;
  }
  return (lua_State *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x00476CA0
// Name: callallgcTM
// Source: json
//------------------------------------------------------------------------------
void __cdecl callallgcTM(lua_State *L)
{
  luaC_callGCTM(L);
}

//------------------------------------------------------------------------------
// Address: 0x00476CC0
// Name: void lua_close(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl lua_close(lua_State *L)
{
  lua_State *mainthread; // esi
  CallInfo *base_ci; // eax
  lua_TValue *base; // eax

  mainthread = L->l_G->mainthread;
  luaF_close(L: mainthread, level: mainthread->stack);
  luaC_separateudata(L: mainthread, all: 1);
  mainthread->errfunc = 0;
  do
  {
    base_ci = mainthread->base_ci;
    mainthread->ci = base_ci;
    base = base_ci->base;
    mainthread->top = base;
    mainthread->base = base;
    mainthread->nCcalls = 0;
  }
  while ( luaD_rawrunprotected(L: mainthread, f: (void (__cdecl *)(lua_State *, void *))callallgcTM, ud: nullptr) != 0 );
  close_state(L: mainthread);
}
