// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lstring.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047C9A0
// Name: void luaS_resize(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaS_resize(lua_State *L, int newsize)
{
  int v2; // edi
  GCObject **v3; // eax
  global_State *l_G; // ebx
  GCObject **v5; // esi
  int v6; // ecx
  int *v7; // eax
  int v8; // edi
  int *v9; // edx
  int v10; // ecx
  stringtable *tb; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( L->l_G->gcstate != 2 )
  {
    v2 = newsize;
    if ( (unsigned int)(newsize + 1) > 0x3FFFFFFF )
      luaM_toobig(L);
    v3 = (GCObject **)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 4 * newsize);
    l_G = L->l_G;
    v5 = v3;
    tb = &l_G->strt;
    if ( newsize > 0 )
    {
      memset(v3, 0, 4 * newsize);
      v2 = newsize;
    }
    v6 = 0;
    for ( i = 0; v6 < l_G->strt.size; i = v6 )
    {
      v7 = (int *)l_G->strt.hash[v6];
      if ( v7 != nullptr )
      {
        v8 = v2 - 1;
        do
        {
          v9 = (int *)*v7;
          v10 = v8 & v7[2];
          *v7 = (int)v5[v10];
          v5[v10] = (GCObject *)v7;
          v7 = v9;
        }
        while ( v9 != nullptr );
        l_G = (global_State *)tb;
        v6 = i;
        v2 = newsize;
      }
      ++v6;
    }
    luaM_realloc_(L, block: l_G->strt.hash, osize: 4 * l_G->strt.size, nsize: 0);
    l_G->strt.size = v2;
    l_G->strt.hash = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CA60
// Name: newlstr
// Source: json
//------------------------------------------------------------------------------
TString *__usercall newlstr@<eax>(unsigned int l@<edi>, lua_State *L, char *str, unsigned int h)
{
  void *v4; // esi
  global_State *l_G; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  int size; // eax

  if ( l + 1 > 0xFFFFFFED )
    luaM_toobig(L);
  v4 = luaM_realloc_(L, block: nullptr, osize: 0, nsize: l + 17);
  *((_DWORD *)v4 + 3) = l;
  *((_DWORD *)v4 + 2) = h;
  *((_BYTE *)v4 + 5) = L->l_G->currentwhite & 3;
  *((_BYTE *)v4 + 4) = 4;
  *((_BYTE *)v4 + 6) = 0;
  memcpy(dst: (unsigned __int8 *)v4 + 16, src: (unsigned __int8 *)str, count: l);
  *((_BYTE *)v4 + l + 16) = 0;
  l_G = L->l_G;
  v6 = (l_G->strt.size - 1) & h;
  *(_DWORD *)v4 = l_G->strt.hash[v6];
  l_G->strt.hash[v6] = (GCObject *)v4;
  v7 = ++l_G->strt.nuse;
  size = l_G->strt.size;
  if ( v7 > size && size <= 1073741822 )
    luaS_resize(L, newsize: 2 * size);
  return (TString *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047CB00
// Name: union TString __near * luaS_newlstr(struct lua_State __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaS_newlstr(lua_State *L, char *str, unsigned int l)
{
  unsigned int v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // esi
  GCObject *result; // eax
  char *v9; // esi
  unsigned int v10; // ecx
  TString *p_l_G; // edx

  v3 = l;
  v4 = (l >> 5) + 1;
  v5 = l;
  v6 = l;
  if ( l >= v4 )
  {
    do
    {
      v7 = (v5 >> 2) + 32 * v5 + (unsigned __int8)str[v6 - 1];
      v6 -= v4;
      v5 ^= v7;
    }
    while ( v6 >= v4 );
    l = v5;
  }
  result = L->l_G->strt.hash[v5 & (L->l_G->strt.size - 1)];
  if ( result == nullptr )
    return (GCObject *)newlstr(l: v3, L, str, h: v5);
  while ( result->ts.tsv.len != v3 )
  {
LABEL_16:
    result = (GCObject *)result->ts.dummy.l;
    if ( result == nullptr )
      return (GCObject *)newlstr(l: v3, L, str, h: v5);
  }
  v9 = str;
  v10 = v3;
  p_l_G = (TString *)&result->th.l_G;
  if ( v3 >= 4 )
  {
    while ( *(_DWORD *)v9 == p_l_G->dummy.l )
    {
      v10 -= 4;
      p_l_G = (TString *)((char *)p_l_G + 4);
      v9 += 4;
      if ( v10 < 4 )
        goto LABEL_9;
    }
    goto LABEL_15;
  }
LABEL_9:
  if ( v10 != 0
    && (LOBYTE(p_l_G->dummy.u) != *v9
     || v10 > 1 && (BYTE1(p_l_G->dummy.u) != v9[1] || v10 > 2 && BYTE2(p_l_G->tsv.next) != v9[2])) )
  {
LABEL_15:
    v5 = l;
    goto LABEL_16;
  }
  if ( ((unsigned __int8)~L->l_G->currentwhite & result->gch.marked & 3) != 0 )
    result->gch.marked ^= 3u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CBF0
// Name: union Udata __near * luaS_newudata(struct lua_State __near *,unsigned int,struct Table __near *)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaS_newudata(lua_State *L, unsigned int s, Table *e)
{
  GCObject *result; // eax
  unsigned __int8 currentwhite; // dl

  if ( s > 0xFFFFFFE5 )
    luaM_toobig(L);
  result = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: s + 24);
  currentwhite = L->l_G->currentwhite;
  result->u.uv.len = s;
  result->gch.marked = currentwhite & 3;
  result->gch.tt = 7;
  result->ts.tsv.hash = 0;
  result->ts.tsv.len = (unsigned int)e;
  result->ts.dummy.l = (int)L->l_G->mainthread->next;
  L->l_G->mainthread->next = result;
  return result;
}
