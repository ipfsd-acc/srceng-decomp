// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lstring.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100198A0
// Name: _luaS_resize
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaS_resize(lua_State *L, int newsize)
{
  int v2; // edi
  void *v3; // esi
  global_State *l_G; // ebx
  int v5; // ecx
  int *v6; // eax
  int v7; // edi
  int *v8; // edx
  int v9; // ecx
  int i; // [esp+10h] [ebp-8h]
  stringtable *tb; // [esp+14h] [ebp-4h]

  if ( L->l_G->gcstate != 2 )
  {
    v2 = newsize;
    if ( (unsigned int)(newsize + 1) > 0x3FFFFFFF )
      luaG_runerror(L, fmt: "memory allocation error: block too big");
    v3 = luaM_realloc_(L, block: nullptr, osize: 0, nsize: 4 * newsize);
    l_G = L->l_G;
    tb = &l_G->strt;
    if ( newsize > 0 )
    {
      memset(v3, 0, 4 * newsize);
      v2 = newsize;
    }
    v5 = 0;
    for ( i = 0; v5 < l_G->strt.size; i = v5 )
    {
      v6 = (int *)l_G->strt.hash[v5];
      if ( v6 != nullptr )
      {
        v7 = v2 - 1;
        do
        {
          v8 = (int *)*v6;
          v9 = v7 & v6[2];
          *v6 = *((_DWORD *)v3 + v9);
          *((_DWORD *)v3 + v9) = v6;
          v6 = v8;
        }
        while ( v8 != nullptr );
        l_G = (global_State *)tb;
        v5 = i;
        v2 = newsize;
      }
      ++v5;
    }
    luaM_realloc_(L, block: l_G->strt.hash, osize: 4 * l_G->strt.size, nsize: 0);
    l_G->strt.size = v2;
    l_G->strt.hash = (GCObject **)v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019970
// Name: newlstr
// Source: json
//------------------------------------------------------------------------------
TString *__usercall newlstr@<eax>(unsigned int l@<edi>, lua_State *L, char *str, unsigned int h, unsigned int k)
{
  void *v5; // esi
  global_State *l_G; // eax
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  int size; // eax

  if ( l + 1 > 0xFFFFFFE5 )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v5 = luaM_realloc_(L, block: nullptr, osize: 0, nsize: l + 25);
  *((_DWORD *)v5 + 3) = k;
  *((_DWORD *)v5 + 4) = l;
  *((_DWORD *)v5 + 2) = h;
  *((_BYTE *)v5 + 5) = L->l_G->currentwhite & 3;
  *((_BYTE *)v5 + 4) = 4;
  *((_BYTE *)v5 + 6) = 0;
  memcpy(dst: (unsigned __int8 *)v5 + 24, src: (unsigned __int8 *)str, count: l);
  *((_BYTE *)v5 + l + 24) = 0;
  l_G = L->l_G;
  v7 = (l_G->strt.size - 1) & h;
  *(_DWORD *)v5 = l_G->strt.hash[v7];
  l_G->strt.hash[v7] = (GCObject *)v5;
  v8 = ++l_G->strt.nuse;
  size = l_G->strt.size;
  if ( v8 > size && size <= 1073741822 )
    luaS_resize(L, newsize: 2 * size);
  return (TString *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10019A20
// Name: _luaS_newlstr
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaS_newlstr(lua_State *L, char *str, unsigned int l)
{
  unsigned int v3; // esi
  unsigned int v4; // ecx
  const char *v5; // ebx
  unsigned __int8 v6; // al
  GCObject *result; // eax
  char *v8; // esi
  unsigned int v9; // ecx
  TString *p_savedpc; // edx
  unsigned int h; // [esp+Ch] [ebp-Ch]
  unsigned int k; // [esp+10h] [ebp-8h]

  v3 = (l >> 5) + 1;
  v4 = l;
  h = l;
  k = l;
  if ( l >= v3 )
  {
    v5 = &str[l - 1];
    do
    {
      h ^= *(unsigned __int8 *)v5 + (v4 >> 2) + 32 * v4;
      v6 = tolower(c: *v5);
      v4 = h;
      k ^= (k >> 2) + 32 * k + v6;
      v5 -= v3;
    }
    while ( (unsigned int)&v5[1 - (_DWORD)str] >= v3 );
  }
  result = L->l_G->strt.hash[v4 & (L->l_G->strt.size - 1)];
  if ( result == nullptr )
    return (GCObject *)newlstr(l, L, str, h: v4, k);
  while ( result->ts.tsv.len != l )
  {
LABEL_16:
    result = (GCObject *)result->ts.dummy.l;
    if ( result == nullptr )
      return (GCObject *)newlstr(l, L, str, h: v4, k);
  }
  v8 = str;
  v9 = l;
  p_savedpc = (TString *)&result->th.savedpc;
  if ( l >= 4 )
  {
    while ( *(_DWORD *)v8 == p_savedpc->dummy.l )
    {
      v9 -= 4;
      p_savedpc = (TString *)((char *)p_savedpc + 4);
      v8 += 4;
      if ( v9 < 4 )
        goto LABEL_9;
    }
    goto LABEL_15;
  }
LABEL_9:
  if ( v9 != 0
    && (LOBYTE(p_savedpc->dummy.u) != *v8
     || v9 > 1 && (BYTE1(p_savedpc->dummy.u) != v8[1] || v9 > 2 && BYTE2(p_savedpc->tsv.next) != v8[2])) )
  {
LABEL_15:
    v4 = h;
    goto LABEL_16;
  }
  if ( ((unsigned __int8)~L->l_G->currentwhite & result->gch.marked & 3) != 0 )
    result->gch.marked ^= 3u;
  return result;
}
