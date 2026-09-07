// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lstate.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10019280
// Name: stack_init
// Source: json
//------------------------------------------------------------------------------
void __usercall stack_init(lua_State *L1@<esi>, lua_State *L)
{
  global_State *l_G; // edi
  CallInfo *v3; // eax
  global_State *v4; // edi
  lua_TValue *v5; // eax
  CallInfo *ci; // edx
  CallInfo *v7; // eax
  lua_TValue *top; // ecx

  l_G = L->l_G;
  v3 = (CallInfo *)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 192u);
  if ( v3 == nullptr )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 192;
  L1->base_ci = v3;
  L1->ci = v3;
  L1->size_ci = 8;
  L1->end_ci = v3 + 7;
  v4 = L->l_G;
  v5 = (lua_TValue *)v4->frealloc(a1: v4->ud, a2: nullptr, a3: 0, a4: 720u);
  if ( v5 == nullptr )
    luaD_throw(L, errcode: 4);
  v4->totalbytes += 720;
  ci = L1->ci;
  L1->top = v5;
  L1->stack = v5;
  L1->stack_last = v5 + 39;
  L1->stacksize = 45;
  ci->func = v5;
  L1->top->tt = 0;
  L1->ci->base = ++L1->top;
  v7 = L1->ci;
  top = L1->top;
  L1->base = v7->base;
  v7->top = top + 20;
}

//------------------------------------------------------------------------------
// Address: 0x10019350
// Name: f_luaopen
// Source: json
//------------------------------------------------------------------------------
void __cdecl f_luaopen(lua_State *L)
{
  global_State *l_G; // edi
  int v2; // esi
  global_State *v3; // eax
  global_State *v4; // edi
  int v5; // esi
  global_State *v6; // eax
  TString *v7; // eax
  global_State *g; // [esp+14h] [ebp-4h]

  g = L->l_G;
  stack_init(L1: L, L);
  l_G = L->l_G;
  v2 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 32u);
  if ( v2 == 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 32;
  v3 = L->l_G;
  *(_DWORD *)v2 = v3->rootgc;
  v3->rootgc = (GCObject *)v2;
  *(_BYTE *)(v2 + 5) = v3->currentwhite & 3;
  *(_BYTE *)(v2 + 4) = 5;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_WORD *)(v2 + 6) = 255;
  *(_DWORD *)(v2 + 16) = &dummynode_;
  setarrayvector(L, t: (Table *)v2, size: 0);
  setnodevector(L, t: (Table *)v2, size: 2);
  L->l_gt.value.b = v2;
  L->l_gt.tt = 5;
  v4 = L->l_G;
  v5 = (int)v4->frealloc(a1: v4->ud, a2: nullptr, a3: 0, a4: 32u);
  if ( v5 == 0 )
    luaD_throw(L, errcode: 4);
  v4->totalbytes += 32;
  v6 = L->l_G;
  *(_DWORD *)v5 = v6->rootgc;
  v6->rootgc = (GCObject *)v5;
  *(_BYTE *)(v5 + 5) = v6->currentwhite & 3;
  *(_BYTE *)(v5 + 4) = 5;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 28) = 0;
  *(_WORD *)(v5 + 6) = 255;
  *(_DWORD *)(v5 + 16) = &dummynode_;
  setarrayvector(L, t: (Table *)v5, size: 0);
  setnodevector(L, t: (Table *)v5, size: 2);
  v4->l_registry.value.b = v5;
  v4->l_registry.tt = 5;
  *(_BYTE *)(L->l_G->l_registry.value.b + 6) &= ~0x40u;
  luaS_resize(L, newsize: 32);
  luaT_init(L);
  luaX_init(L);
  v7 = luaS_newlstr(L, str: "not enough memory", l: 0x11u);
  v7->tsv.marked |= 0x20u;
  g->GCthreshold = 4 * g->totalbytes;
}

//------------------------------------------------------------------------------
// Address: 0x100194B0
// Name: close_state
// Source: json
//------------------------------------------------------------------------------
void __usercall close_state(lua_State *L@<eax>)
{
  global_State *l_G; // esi
  global_State *v3; // ebx
  global_State *v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // ebx
  int v8; // [esp+Ch] [ebp-4h]
  unsigned int buffsize; // [esp+Ch] [ebp-4h]
  global_State *v10; // [esp+Ch] [ebp-4h]
  global_State *v11; // [esp+Ch] [ebp-4h]

  l_G = L->l_G;
  luaF_close(L, level: L->stack);
  luaC_freeall(L);
  v3 = L->l_G;
  v8 = 4 * v3->strt.size;
  v3->frealloc(a1: v3->ud, a2: v3->strt.hash, a3: v8, a4: 0);
  v3->totalbytes -= v8;
  v4 = L->l_G;
  buffsize = l_G->buff.buffsize;
  v5 = (int)v4->frealloc(a1: v4->ud, a2: l_G->buff.buffer, a3: buffsize, a4: 0);
  v4->totalbytes -= buffsize;
  l_G->buff.buffer = (char *)v5;
  l_G->buff.buffsize = 0;
  v6 = 24 * L->size_ci;
  v10 = L->l_G;
  v10->frealloc(a1: v10->ud, a2: L->base_ci, a3: v6, a4: 0);
  v10->totalbytes -= v6;
  v7 = 16 * L->stacksize;
  v11 = L->l_G;
  v11->frealloc(a1: v11->ud, a2: L->stack, a3: v7, a4: 0);
  v11->totalbytes -= v7;
  l_G->frealloc(a1: l_G->ud, a2: L, a3: 376u, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10019590
// Name: _luaE_newthread
// Source: json
//------------------------------------------------------------------------------
lua_State *__usercall luaE_newthread@<eax>(lua_State *L@<edi>)
{
  int v1; // esi
  global_State *v2; // eax
  unsigned __int8 currentwhite; // dl
  int basehookcount; // ecx
  void (__cdecl *hook)(lua_State *, lua_Debug *); // edx
  global_State *l_G; // [esp+Ch] [ebp-4h]

  l_G = L->l_G;
  v1 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 120u);
  if ( v1 == 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 120;
  v2 = L->l_G;
  *(_DWORD *)v1 = v2->rootgc;
  currentwhite = v2->currentwhite;
  v2->rootgc = (GCObject *)v1;
  *(_BYTE *)(v1 + 5) = currentwhite & 3;
  *(_BYTE *)(v1 + 4) = 8;
  *(_DWORD *)(v1 + 16) = L->l_G;
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 44) = 0;
  *(_DWORD *)(v1 + 112) = 0;
  *(_DWORD *)(v1 + 68) = 0;
  *(_DWORD *)(v1 + 60) = 0;
  *(_DWORD *)(v1 + 64) = 0;
  *(_DWORD *)(v1 + 104) = 0;
  *(_DWORD *)(v1 + 48) = 0;
  *(_DWORD *)(v1 + 54) = 0x1000000;
  *(_WORD *)(v1 + 52) = 0;
  *(_BYTE *)(v1 + 6) = 0;
  *(_DWORD *)(v1 + 20) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  *(_DWORD *)(v1 + 24) = 0;
  *(_DWORD *)(v1 + 116) = 0;
  *(_DWORD *)(v1 + 80) = 0;
  stack_init(L1: (lua_State *)v1, L);
  *(lua_TValue *)(v1 + 72) = L->l_gt;
  *(_BYTE *)(v1 + 56) = L->hookmask;
  basehookcount = L->basehookcount;
  *(_DWORD *)(v1 + 60) = basehookcount;
  hook = L->hook;
  *(_DWORD *)(v1 + 64) = basehookcount;
  *(_DWORD *)(v1 + 68) = hook;
  return (lua_State *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10019660
// Name: _luaE_freethread
// Source: json
//------------------------------------------------------------------------------
void __usercall luaE_freethread(lua_State *L1@<eax>, lua_State *L)
{
  global_State *l_G; // ebx
  int v4; // esi
  global_State *v5; // ebx
  int v6; // esi
  global_State *v7; // esi

  luaF_close(L: L1, level: L1->stack);
  l_G = L->l_G;
  v4 = 24 * L1->size_ci;
  l_G->frealloc(a1: l_G->ud, a2: L1->base_ci, a3: v4, a4: 0);
  l_G->totalbytes -= v4;
  v5 = L->l_G;
  v6 = 16 * L1->stacksize;
  v5->frealloc(a1: v5->ud, a2: L1->stack, a3: v6, a4: 0);
  v5->totalbytes -= v6;
  v7 = L->l_G;
  v7->frealloc(a1: v7->ud, a2: L1, a3: 120u, a4: 0);
  v7->totalbytes -= 120;
}

//------------------------------------------------------------------------------
// Address: 0x100196E0
// Name: _lua_newstate
// Source: json
//------------------------------------------------------------------------------
lua_State *__cdecl lua_newstate()
{
  char *v0; // esi

  v0 = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: 0, a3: 376);
  if ( v0 == nullptr )
    return nullptr;
  *(_DWORD *)v0 = 0;
  v0[4] = 8;
  v0[140] = 33;
  *((_DWORD *)v0 + 4) = v0 + 120;
  *((_DWORD *)v0 + 8) = 0;
  *((_DWORD *)v0 + 11) = 0;
  *((_DWORD *)v0 + 28) = 0;
  *((_DWORD *)v0 + 17) = 0;
  *((_DWORD *)v0 + 15) = 0;
  *((_DWORD *)v0 + 16) = 0;
  *((_DWORD *)v0 + 26) = 0;
  *((_DWORD *)v0 + 12) = 0;
  *(_DWORD *)(v0 + 54) = 0x1000000;
  *(_WORD *)(v0 + 5) = 97;
  *((_DWORD *)v0 + 5) = 0;
  *((_DWORD *)v0 + 10) = 0;
  *((_DWORD *)v0 + 6) = 0;
  *((_DWORD *)v0 + 29) = 0;
  *((_DWORD *)v0 + 20) = 0;
  *((_WORD *)v0 + 26) = 0;
  *((_DWORD *)v0 + 64) = v0 + 240;
  *((_DWORD *)v0 + 65) = v0 + 240;
  *((_DWORD *)v0 + 33) = l_alloc;
  *((_DWORD *)v0 + 34) = 0;
  *((_DWORD *)v0 + 58) = v0;
  *((_DWORD *)v0 + 46) = 0;
  *((_DWORD *)v0 + 32) = 0;
  *((_DWORD *)v0 + 31) = 0;
  *((_DWORD *)v0 + 30) = 0;
  *(_DWORD *)(*((_DWORD *)v0 + 4) + 104) = 0;
  *((_DWORD *)v0 + 37) = v0;
  *((_DWORD *)v0 + 43) = 0;
  *((_DWORD *)v0 + 45) = 0;
  *((_DWORD *)v0 + 52) = 0;
  v0[141] = 0;
  *((_DWORD *)v0 + 36) = 0;
  *((_DWORD *)v0 + 39) = 0;
  *((_DWORD *)v0 + 40) = 0;
  *((_DWORD *)v0 + 41) = 0;
  *((_DWORD *)v0 + 42) = 0;
  *((_DWORD *)v0 + 47) = 376;
  *((_DWORD *)v0 + 49) = 0;
  *((_DWORD *)v0 + 38) = v0 + 148;
  *((_DWORD *)v0 + 50) = 200;
  *((_DWORD *)v0 + 51) = 200;
  *((_DWORD *)v0 + 68) = 0;
  *((_DWORD *)v0 + 69) = 0;
  *((_DWORD *)v0 + 70) = 0;
  *((_DWORD *)v0 + 71) = 0;
  *((_DWORD *)v0 + 72) = 0;
  *((_DWORD *)v0 + 73) = 0;
  *((_DWORD *)v0 + 74) = 0;
  *((_DWORD *)v0 + 75) = 0;
  *((_DWORD *)v0 + 76) = 0;
  if ( luaD_rawrunprotected(L: (lua_State *)v0, f: (void (__cdecl *)(lua_State *, void *))f_luaopen, ud: nullptr) != 0 )
  {
    close_state(L: (lua_State *)v0);
    return nullptr;
  }
  return (lua_State *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x10019810
// Name: callallgcTM
// Source: json
//------------------------------------------------------------------------------
void __cdecl callallgcTM(lua_State *L)
{
  luaC_callGCTM(L);
}

//------------------------------------------------------------------------------
// Address: 0x10019830
// Name: _lua_close
// Source: json
//------------------------------------------------------------------------------
void __usercall lua_close(lua_State *L@<eax>)
{
  lua_State *mainthread; // edi
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
    *(_DWORD *)&mainthread->nCcalls = 0;
  }
  while ( luaD_rawrunprotected(L: mainthread, f: (void (__cdecl *)(lua_State *, void *))callallgcTM, ud: nullptr) != 0 );
  close_state(L: mainthread);
}
