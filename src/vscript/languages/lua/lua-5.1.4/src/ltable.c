// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ltable.c
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001CFC0
// Name: l_strkeyeq
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall l_strkeyeq@<eax>(const TString *ls@<ecx>, const TString *rs@<eax>, const Table *t)
{
  unsigned int len; // ebx
  const char *v4; // esi
  const char *v5; // edi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int ll; // [esp+Ch] [ebp-4h]

  len = rs->tsv.len;
  v4 = (const char *)&ls[1];
  ll = ls->tsv.len;
  v5 = (const char *)&rs[1];
  if ( ll == len )
  {
    while ( 1 )
    {
      v6 = (t->flags & 0x40) != 0 ? _stricmp(dst: v4, src: v5) : strcmp(v4, v5);
      if ( v6 != 0 )
        break;
      v7 = strlen(v4);
      if ( v7 == len )
        return v7 == ll;
      if ( v7 == ll )
        return false;
      v8 = v7 + 1;
      ll -= v8;
      v4 += v8;
      v5 += v8;
      len -= v8;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1001D070
// Name: mainposition
// Source: json
//------------------------------------------------------------------------------
Node *__usercall mainposition@<eax>(const Table *t@<esi>, const lua_TValue *key@<edx>)
{
  Node *result; // eax
  unsigned int b; // eax
  int v4; // eax
  int v5; // eax

  switch ( key->tt )
  {
    case 1:
      result = &t->node[key->value.b & ((1 << t->lsizenode) - 1)];
      break;
    case 3:
      if ( key->value.n != 0.0 )
      {
        b = key->value.b + *(&key->value.b + 1);
        goto LABEL_11;
      }
      result = t->node;
      break;
    case 4:
      v4 = (1 << t->lsizenode) - 1;
      if ( (t->flags & 0x40) != 0 )
        v5 = *(_DWORD *)(key->value.b + 12) & v4;
      else
        v5 = *(_DWORD *)(key->value.b + 8) & v4;
      result = &t->node[v5];
      break;
    default:
      b = key->value.b;
LABEL_11:
      result = &t->node[b % (((1 << t->lsizenode) - 1) | 1u)];
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D130
// Name: findindex
// Source: json
//------------------------------------------------------------------------------
int __usercall findindex@<eax>(Table *t@<eax>, lua_State *L, lua_TValue *key)
{
  int tt; // eax
  int n; // ecx
  Node *next; // edi
  int v8; // eax
  const TString *gc; // ecx
  BOOL v10; // eax

  tt = key->tt;
  if ( tt == 0 )
    return -1;
  if ( tt == 3 )
  {
    n = (int)key->value.n;
    if ( (double)n == key->value.n && n > 0 && n <= t->sizearray )
      return n - 1;
  }
  next = mainposition(t, key);
  while ( 1 )
  {
    v8 = next->i_key.nk.tt;
    if ( v8 != 4 || key->tt != 4 )
      break;
    gc = (const TString *)next->i_key.nk.value.gc;
    if ( gc == (const TString *)key->value.gc )
      return t->sizearray + next - t->node;
    v10 = l_strkeyeq(ls: gc, rs: (const TString *)key->value.gc, t);
LABEL_19:
    if ( v10 )
      return t->sizearray + next - t->node;
LABEL_20:
    if ( next->i_key.nk.tt == 11 && key->tt >= 4 && next->i_key.nk.value.b == key->value.b )
      return t->sizearray + next - t->node;
    next = next->i_key.nk.next;
    if ( next == nullptr )
      luaG_runerror(L, fmt: "invalid key to 'next'");
  }
  if ( v8 != key->tt )
    goto LABEL_20;
  switch ( v8 )
  {
    case 0:
      return t->sizearray + next - t->node;
    case 2:
      v10 = next->i_key.nk.value.b == key->value.b;
      goto LABEL_19;
    case 3:
      if ( next->i_key.nk.value.n != key->value.n )
        goto LABEL_20;
      break;
    default:
      v10 = next->i_key.nk.value.b == key->value.b;
      goto LABEL_19;
  }
  return t->sizearray + next - t->node;
}

//------------------------------------------------------------------------------
// Address: 0x1001D260
// Name: _luaH_next
// Source: json
//------------------------------------------------------------------------------
int __usercall luaH_next@<eax>(lua_State *L@<eax>, Table *t@<edi>, TKey *key@<esi>)
{
  int v3; // eax
  int sizearray; // ecx
  int v5; // eax
  int *p_tt; // edx
  int v7; // eax
  int v8; // edx
  Node *node; // ecx
  int *i; // ebx
  int v12; // eax
  Node *v13; // ecx
  int b; // edx
  Node *v15; // ecx
  lua_TValue *v16; // [esp+0h] [ebp-8h]

  v3 = findindex(t, L, key: v16);
  sizearray = t->sizearray;
  v5 = v3 + 1;
  if ( v5 >= sizearray )
  {
LABEL_5:
    v7 = v5 - sizearray;
    v8 = 1 << t->lsizenode;
    if ( v7 >= v8 )
    {
      return 0;
    }
    else
    {
      node = t->node;
      for ( i = &node[v7].i_val.tt; *i == 0; i += 8 )
      {
        if ( ++v7 >= v8 )
          return 0;
      }
      v12 = v7;
      *key = node[v12].i_key;
      v13 = t->node;
      b = v13[v12].i_val.value.b;
      v15 = &v13[v12];
      key[1].nk.value.b = b;
      *(&key[1].tvk.value.b + 1) = *(&v15->i_val.value.b + 1);
      key[1].nk.tt = v15->i_val.tt;
      return 1;
    }
  }
  else
  {
    p_tt = &t->array[v5].tt;
    while ( *p_tt == 0 )
    {
      ++v5;
      p_tt += 4;
      if ( v5 >= sizearray )
        goto LABEL_5;
    }
    key->nk.tt = 3;
    key->nk.value.n = (double)(v5 + 1);
    key[1] = (TKey)t->array[v5];
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D330
// Name: computesizes
// Source: json
//------------------------------------------------------------------------------
int __cdecl computesizes(int *nums, int *narray)
{
  int v2; // esi
  int v3; // ebx
  int v4; // edi
  int v5; // ecx

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 1;
  if ( *narray <= 0 )
  {
    *narray = 0;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      if ( *nums > 0 )
      {
        v2 += *nums;
        if ( v2 > v5 / 2 )
        {
          v4 = v5;
          v3 = v2;
        }
      }
      if ( v2 == *narray )
        break;
      ++nums;
      v5 *= 2;
      if ( v5 / 2 >= *narray )
      {
        *narray = v4;
        return v3;
      }
    }
    *narray = v4;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D3B0
// Name: numusearray
// Source: json
//------------------------------------------------------------------------------
int __cdecl numusearray(const Table *t, int *nums)
{
  int v2; // eax
  int v3; // edi
  int v4; // edx
  int sizearray; // esi
  int v6; // ebx
  int v7; // ecx
  int *p_tt; // esi
  int v9; // ecx
  int i; // [esp+Ch] [ebp-8h]
  int ause; // [esp+10h] [ebp-4h]

  v2 = 1;
  v3 = 0;
  ause = 0;
  i = 1;
  v4 = 1;
  do
  {
    sizearray = t->sizearray;
    v6 = 0;
    v7 = v4;
    if ( v4 <= sizearray )
    {
      if ( v2 > v4 )
        goto LABEL_10;
    }
    else
    {
      v7 = t->sizearray;
      if ( v2 > sizearray )
        return ause;
    }
    p_tt = &t->array[v2 - 1].tt;
    v9 = v7 - i + 1;
    v2 = v9 + i;
    i += v9;
    do
    {
      if ( *p_tt != 0 )
        ++v6;
      p_tt += 4;
      --v9;
    }
    while ( v9 != 0 );
LABEL_10:
    nums[v3] += v6;
    ause += v6;
    ++v3;
    v4 *= 2;
  }
  while ( v3 <= 26 );
  return ause;
}

//------------------------------------------------------------------------------
// Address: 0x1001D430
// Name: numusehash
// Source: json
//------------------------------------------------------------------------------
int __usercall numusehash@<eax>(const Table *t@<edi>, int *nums, int *pnasize)
{
  int v3; // edx
  int result; // eax
  int v5; // ebx
  int v6; // esi
  Node *node; // eax
  long double n; // st7
  int v9; // ecx
  unsigned int v10; // eax
  int i; // ecx
  int v12; // eax
  int totaluse; // [esp+14h] [ebp-4h]

  v3 = 1 << t->lsizenode;
  result = 0;
  v5 = 0;
  totaluse = 0;
  if ( v3 != 0 )
  {
    v6 = v3;
    do
    {
      node = t->node;
      --v6;
      --v3;
      if ( node[v6].i_val.tt != 0 )
      {
        if ( node[v6].i_key.nk.tt == 3
          && (n = node[v6].i_key.nk.value.n, v9 = (int)n, (double)(int)n == n)
          && (unsigned int)(v9 - 1) <= 0x3FFFFFF )
        {
          v10 = v9 - 1;
          for ( i = -1; v10 >= 0x100; i += 8 )
            v10 >>= 8;
          ++nums[i + 1 + (unsigned __int8)byte_10098B20[v10]];
          v12 = 1;
        }
        else
        {
          v12 = 0;
        }
        v5 += v12;
        ++totaluse;
      }
    }
    while ( v3 != 0 );
    *pnasize += v5;
    return totaluse;
  }
  else
  {
    *pnasize = *pnasize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D500
// Name: setarrayvector
// Source: json
//------------------------------------------------------------------------------
void __usercall setarrayvector(lua_State *L@<eax>, Table *t@<esi>, int size@<edi>)
{
  lua_TValue *v3; // eax
  int sizearray; // edx
  int v5; // eax
  int v6; // ecx

  if ( (unsigned int)(size + 1) > 0xFFFFFFF )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v3 = (lua_TValue *)luaM_realloc_(L, block: t->array, osize: 16 * t->sizearray, nsize: 16 * size);
  sizearray = t->sizearray;
  t->array = v3;
  if ( sizearray < size )
  {
    v5 = sizearray;
    v6 = size - sizearray;
    do
    {
      t->array[v5++].tt = 0;
      --v6;
    }
    while ( v6 != 0 );
  }
  t->sizearray = size;
}

//------------------------------------------------------------------------------
// Address: 0x1001D570
// Name: setnodevector
// Source: json
//------------------------------------------------------------------------------
void __usercall setnodevector(Table *t@<edi>, int size@<eax>, lua_State *L)
{
  int v3; // esi
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int i; // edx
  Node *node; // eax
  Node *v10; // esi
  unsigned __int8 lsize; // [esp+Ch] [ebp-4h]

  v3 = size;
  if ( size != 0 )
  {
    v4 = size - 1;
    v5 = -1;
    if ( (unsigned int)(v3 - 1) >= 0x100 )
    {
      do
      {
        v4 >>= 8;
        v5 += 8;
      }
      while ( v4 >= 0x100 );
    }
    v6 = (unsigned __int8)byte_10098B20[v4] + v5 + 1;
    lsize = v6;
    if ( v6 > 26 )
      luaG_runerror(L, fmt: "table overflow");
    v3 = 1 << v6;
    if ( (unsigned int)((1 << v6) + 1) > 0x7FFFFFF )
      luaG_runerror(L, fmt: "memory allocation error: block too big");
    t->node = (Node *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 32 * v3);
    if ( v3 > 0 )
    {
      v7 = 0;
      for ( i = v3; i != 0; --i )
      {
        node = t->node;
        node[v7].i_key.nk.next = nullptr;
        node[v7].i_key.nk.tt = 0;
        node[v7++].i_val.tt = 0;
      }
    }
  }
  else
  {
    t->node = &dummynode_;
    lsize = 0;
  }
  v10 = &t->node[v3];
  t->lsizenode = lsize;
  t->lastfree = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1001D650
// Name: resize
// Source: json
//------------------------------------------------------------------------------
void __usercall resize(Table *t@<eax>, lua_State *L, int nasize, int nhsize)
{
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // edi
  lua_TValue *v8; // ebx
  lua_TValue *v9; // eax
  int v10; // eax
  int v11; // ebx
  const lua_TValue *p_i_key; // edi
  lua_TValue *v13; // eax
  int tt; // eax
  int v15; // [esp+Ch] [ebp-2Ch]
  int oldasize; // [esp+10h] [ebp-28h]
  int v17; // [esp+14h] [ebp-24h]
  Node *nold; // [esp+18h] [ebp-20h]
  unsigned __int8 oldhsize; // [esp+24h] [ebp-14h]
  int oldhsizea; // [esp+24h] [ebp-14h]
  lua_TValue key; // [esp+28h] [ebp-10h] BYREF

  oldasize = t->sizearray;
  oldhsize = t->lsizenode;
  nold = t->node;
  if ( nasize > oldasize )
    setarrayvector(L, t, size: nasize);
  setnodevector(t, size: nhsize, L);
  v5 = oldasize;
  if ( nasize < oldasize )
  {
    v6 = 16 * nasize;
    v7 = nasize + 1;
    t->sizearray = nasize;
    v15 = nasize;
    v17 = oldasize - nasize;
    do
    {
      v8 = &t->array[v15];
      if ( v8->tt != 0 )
      {
        v9 = (lua_TValue *)luaH_getnum(t, key: v7);
        if ( v9 == &luaO_nilobject_ )
        {
          key.value.n = (double)v7;
          key.tt = 3;
          v9 = newkey(L, t, &key);
        }
        v9->value.b = v8->value.b;
        *(&v9->value.b + 1) = *(&v8->value.b + 1);
        v5 = oldasize;
        v9->tt = v8->tt;
        v6 = 16 * nasize;
      }
      ++v15;
      ++v7;
      --v17;
    }
    while ( v17 != 0 );
    if ( (unsigned int)(nasize + 1) > 0xFFFFFFF )
      luaG_runerror(L, fmt: "memory allocation error: block too big");
    t->array = (lua_TValue *)luaM_realloc_(L, block: t->array, osize: 16 * v5, nsize: v6);
  }
  v10 = 1 << oldhsize;
  v11 = (1 << oldhsize) - 1;
  oldhsizea = 1 << oldhsize;
  if ( v11 >= 0 )
  {
    p_i_key = (const lua_TValue *)&nold[v11].i_key;
    do
    {
      if ( p_i_key[-1].tt != 0 )
      {
        v13 = (lua_TValue *)luaH_get(t, key: p_i_key);
        t->flags &= 0x40u;
        if ( v13 == &luaO_nilobject_ )
        {
          tt = p_i_key->tt;
          if ( tt == 0 )
            luaG_runerror(L, fmt: "table index is nil");
          v13 = newkey(L, t, key: p_i_key);
        }
        v13->value.b = p_i_key[-1].value.b;
        *(&v13->value.b + 1) = *(&p_i_key[-1].value.b + 1);
        v13->tt = p_i_key[-1].tt;
        v10 = oldhsizea;
      }
      p_i_key -= 2;
      --v11;
    }
    while ( v11 >= 0 );
  }
  if ( nold != &dummynode_ )
    luaM_realloc_(L, block: nold, osize: 32 * v10, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001D830
// Name: rehash
// Source: json
//------------------------------------------------------------------------------
void __usercall rehash(Table *t@<eax>, lua_State *L, const lua_TValue *ek)
{
  const lua_TValue *v3; // ebx
  const lua_TValue *v5; // esi
  char *v6; // esi
  int v7; // ecx
  unsigned int v8; // eax
  int i; // ecx
  int v10; // eax
  int v11; // eax
  int nums[28]; // [esp+10h] [ebp-80h] BYREF
  long double n; // [esp+80h] [ebp-10h]
  int v14; // [esp+8Ch] [ebp-4h]

  v3 = ek;
  memset(nums, 0, 108);
  ek = (const lua_TValue *)numusearray(t, nums);
  v5 = ek;
  v6 = (char *)v5 + numusehash(t, nums, pnasize: (int *)&ek);
  if ( v3->tt == 3 && (n = v3->value.n, v14 = (int)n, v7 = (int)n, (double)(int)n == n) && v7 > 0 && v7 <= 0x4000000 )
  {
    v8 = v7 - 1;
    for ( i = -1; v8 >= 0x100; i += 8 )
      v8 >>= 8;
    ++nums[i + 1 + (unsigned __int8)byte_10098B20[v8]];
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  ek = (const lua_TValue *)((char *)ek + v10);
  v11 = computesizes(nums, narray: (int *)&ek);
  resize(t, L, nasize: (int)ek, nhsize: (int)&v6[-v11 + 1]);
}

//------------------------------------------------------------------------------
// Address: 0x1001D960
// Name: _luaH_new
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaH_new(lua_State *L, int narray, int nhash)
{
  GCObject *v3; // esi
  global_State *l_G; // eax
  unsigned __int8 currentwhite; // dl

  v3 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x20u);
  l_G = L->l_G;
  v3->ts.dummy.l = (int)l_G->rootgc;
  currentwhite = l_G->currentwhite;
  l_G->rootgc = v3;
  v3->ts.tsv.hash = 0;
  v3->ts.tsv.keyhash = 0;
  v3->h.sizearray = 0;
  v3->gch.marked = currentwhite & 3;
  v3->gch.tt = 5;
  *(_WORD *)(&v3->p.marked + 1) = 255;
  v3->ts.tsv.len = (unsigned int)&dummynode_;
  setarrayvector(L, t: (Table *)v3, size: narray);
  setnodevector(t: (Table *)v3, size: nhash, L);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001D9D0
// Name: _luaH_free
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaH_free(lua_State *L, Table *t)
{
  Node *node; // eax
  global_State *l_G; // edi
  int v4; // esi
  global_State *v5; // edi
  int v6; // esi
  global_State *v7; // esi

  node = t->node;
  if ( node != &dummynode_ )
  {
    l_G = L->l_G;
    v4 = 32 * (1 << t->lsizenode);
    l_G->frealloc(a1: l_G->ud, a2: node, a3: v4, a4: 0);
    l_G->totalbytes -= v4;
  }
  v5 = L->l_G;
  v6 = 16 * t->sizearray;
  v5->frealloc(a1: v5->ud, a2: t->array, a3: v6, a4: 0);
  v5->totalbytes -= v6;
  v7 = L->l_G;
  v7->frealloc(a1: v7->ud, a2: t, a3: 32u, a4: 0);
  v7->totalbytes -= 32;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA50
// Name: newkey
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl newkey(lua_State *L, GCObject *t, const lua_TValue *key)
{
  const lua_TValue *v3; // ebx
  Node *v4; // eax
  Node *v5; // edi
  Node *lastfree; // ebx
  Node *result; // eax
  int tt; // eax
  Node *next; // eax
  unsigned __int8 marked; // al
  global_State *l_G; // ecx

  v3 = key;
  v4 = mainposition((const Table *)t, key);
  v5 = v4;
  if ( v4->i_val.tt != 0 || v4 == &dummynode_ )
  {
    if ( t->cl.l.upvals[0] <= t->uv.u.l.prev )
    {
LABEL_7:
      --t->cl.l.upvals[0];
      goto LABEL_10;
    }
    while ( 1 )
    {
      --t->cl.l.upvals[0];
      lastfree = t->h.lastfree;
      if ( lastfree->i_key.nk.tt == 0 )
        break;
      if ( (unsigned int)lastfree <= t->ts.tsv.len )
      {
        v3 = key;
        goto LABEL_7;
      }
    }
    if ( lastfree == nullptr )
    {
      v3 = key;
LABEL_10:
      rehash((Table *)t, L, ek: v3);
      result = (Node *)luaH_get((Table *)t, key: v3);
      t->ts.tsv.reserved &= 0x40u;
      if ( result == (Node *)&luaO_nilobject_ )
      {
        tt = v3->tt;
        if ( tt == 0 )
          luaG_runerror(L, fmt: "table index is nil");
        return (Node *)newkey(L, (Table *)t, key: v3);
      }
      return result;
    }
    next = mainposition((const Table *)t, key: (const lua_TValue *)&v4->i_key);
    if ( next == v5 )
    {
      lastfree->i_key.nk.next = v5->i_key.nk.next;
      v5->i_key.nk.next = lastfree;
      v5 = lastfree;
    }
    else
    {
      for ( ; next->i_key.nk.next != v5; next = next->i_key.nk.next )
        ;
      next->i_key.nk.next = lastfree;
      lastfree->i_val.value.n = v5->i_val.value.n;
      *(_QWORD *)&lastfree->i_val.tt = *(_QWORD *)&v5->i_val.tt;
      lastfree->i_key.nk.value.n = v5->i_key.nk.value.n;
      *(_QWORD *)&lastfree->i_key.tvk.tt = *(_QWORD *)&v5->i_key.tvk.tt;
      v5->i_key.nk.next = nullptr;
      v5->i_val.tt = 0;
    }
    v3 = key;
  }
  v5->i_key.nk.value.b = v3->value.b;
  *(&v5->i_key.tvk.value.b + 1) = *(&v3->value.b + 1);
  v5->i_key.nk.tt = v3->tt;
  if ( v3->tt >= 4 && (*(_BYTE *)(v3->value.b + 5) & 3) != 0 )
  {
    marked = t->gch.marked;
    if ( (marked & 4) != 0 )
    {
      l_G = L->l_G;
      t->gch.marked = marked & 0xFB;
      t->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
      l_G->grayagain = t;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001DBC0
// Name: _luaH_getnum
// Source: json
//------------------------------------------------------------------------------
Node *__usercall luaH_getnum@<eax>(Table *t@<esi>, int key@<eax>)
{
  Node *node; // edx
  double v4; // [esp+8h] [ebp-8h]

  if ( (unsigned int)(key - 1) < t->sizearray )
    return (Node *)&t->array[key - 1];
  if ( (double)key == 0.0 )
  {
    node = t->node;
  }
  else
  {
    v4 = (double)key;
    node = &t->node[(LODWORD(v4) + HIDWORD(v4)) % (((1 << t->lsizenode) - 1) | 1u)];
  }
  while ( node->i_key.nk.tt != 3 || node->i_key.nk.value.n != (double)key )
  {
    node = node->i_key.nk.next;
    if ( node == nullptr )
      return (Node *)&luaO_nilobject_;
  }
  return node;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC60
// Name: _luaH_getstr
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_getstr(Table *t, TString *key)
{
  unsigned __int8 lsizenode; // cl
  int v3; // edx
  TString *v4; // ecx
  Node *next; // edx
  int v6; // eax
  GCObject *gc; // eax
  unsigned int len; // ebx
  const char *p_savedpc; // esi
  const char *v10; // edi
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v15; // [esp+Ch] [ebp-8h]
  Node *n; // [esp+10h] [ebp-4h]

  lsizenode = t->lsizenode;
  if ( (t->flags & 0x40) != 0 )
  {
    v6 = 1 << lsizenode;
    v4 = key;
    n = &t->node[key->tsv.keyhash & (v6 - 1)];
    next = n;
  }
  else
  {
    v3 = 1 << lsizenode;
    v4 = key;
    next = &t->node[key->tsv.hash & (v3 - 1)];
    n = next;
  }
  do
  {
    if ( next->i_key.nk.tt == 4 )
    {
      gc = next->i_key.nk.value.gc;
      if ( gc == (GCObject *)v4 )
        return next;
      len = v4->tsv.len;
      p_savedpc = (const char *)&gc->th.savedpc;
      v15 = gc->ts.tsv.len;
      v10 = (const char *)&v4[1];
      if ( v15 == len )
      {
        while ( 1 )
        {
          if ( (t->flags & 0x40) != 0 )
            v11 = _stricmp(dst: p_savedpc, src: v10);
          else
            v11 = strcmp(p_savedpc, v10);
          if ( v11 != 0 )
            goto LABEL_15;
          v12 = strlen(p_savedpc);
          if ( v12 == len )
            break;
          if ( v12 == v15 )
            goto LABEL_15;
          v13 = v12 + 1;
          v15 -= v13;
          p_savedpc += v13;
          v10 += v13;
          len -= v13;
        }
        if ( v12 != v15 )
        {
LABEL_15:
          next = n;
          v4 = key;
          goto LABEL_16;
        }
        return n;
      }
    }
LABEL_16:
    next = next->i_key.nk.next;
    n = next;
  }
  while ( next != nullptr );
  return (Node *)&luaO_nilobject_;
}

//------------------------------------------------------------------------------
// Address: 0x1001DD90
// Name: _luaH_get
// Source: json
//------------------------------------------------------------------------------
Node *__usercall luaH_get@<eax>(Table *t@<eax>, const lua_TValue *key@<edi>)
{
  int tt; // eax
  int v4; // eax
  Node *next; // ecx
  int v7; // eax

  tt = key->tt;
  if ( tt == 0 )
    return (Node *)&luaO_nilobject_;
  v4 = tt - 3;
  if ( v4 != 0 )
  {
    if ( v4 == 1 )
      return luaH_getstr(t, key: (TString *)key->value.gc);
  }
  else if ( (double)(int)key->value.n == key->value.n )
  {
    return luaH_getnum(t, key: (int)key->value.n);
  }
  next = mainposition(t, key);
  while ( 1 )
  {
    v7 = next->i_key.nk.tt;
    if ( v7 == key->tt )
      break;
LABEL_13:
    next = next->i_key.nk.next;
    if ( next == nullptr )
      return (Node *)&luaO_nilobject_;
  }
  switch ( v7 )
  {
    case 0:
      return next;
    case 3:
      if ( next->i_key.nk.value.n != key->value.n )
        goto LABEL_13;
      break;
    default:
      if ( next->i_key.nk.value.b != key->value.b )
        goto LABEL_13;
      break;
  }
  return next;
}

//------------------------------------------------------------------------------
// Address: 0x1001DE60
// Name: _luaH_setnum
// Source: json
//------------------------------------------------------------------------------
Node *__usercall luaH_setnum@<eax>(GCObject *t@<eax>, int key@<edi>, lua_State *L)
{
  Node *result; // eax
  lua_TValue k; // [esp+8h] [ebp-10h] BYREF

  result = luaH_getnum((Table *)t, key);
  if ( result == (Node *)&luaO_nilobject_ )
  {
    k.value.n = (double)key;
    k.tt = 3;
    return newkey(L, t, key: &k);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DEB0
// Name: unbound_search
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall unbound_search@<eax>(Table *t@<eax>, unsigned int j)
{
  signed int v3; // ebx
  Node *node; // edx
  int k; // edi
  unsigned int i; // [esp+4h] [ebp-10h]
  double v8; // [esp+Ch] [ebp-8h]

  i = j;
  v3 = j + 1;
  while ( 1 )
  {
    if ( (unsigned int)(v3 - 1) >= t->sizearray )
    {
      if ( (double)v3 == 0.0 )
      {
        node = t->node;
      }
      else
      {
        v8 = (double)v3;
        node = &t->node[(LODWORD(v8) + HIDWORD(v8)) % (((1 << t->lsizenode) - 1) | 1u)];
      }
      while ( node->i_key.nk.tt != 3 || node->i_key.nk.value.n != (double)v3 )
      {
        node = node->i_key.nk.next;
        if ( node == nullptr )
        {
          node = (Node *)&luaO_nilobject_;
          break;
        }
      }
    }
    else
    {
      node = (Node *)&t->array[v3 - 1];
    }
    if ( node->i_val.tt == 0 )
      break;
    i = v3;
    v3 *= 2;
    if ( (unsigned int)v3 > 0x7FFFFFFD )
    {
      for ( k = 1; luaH_getnum(t, key: k)->i_val.tt != 0; ++k )
        ;
      return k - 1;
    }
  }
  while ( v3 - i > 1 )
  {
    if ( luaH_getnum(t, key: (i + v3) >> 1)->i_val.tt != 0 )
      i = (i + v3) >> 1;
    else
      v3 = (i + v3) >> 1;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1001DFD0
// Name: _luaH_getn
// Source: json
//------------------------------------------------------------------------------
int __usercall luaH_getn@<eax>(Table *t@<eax>)
{
  unsigned int sizearray; // edx
  lua_TValue *array; // esi
  int result; // eax

  sizearray = t->sizearray;
  if ( sizearray == 0 || (array = t->array)[sizearray - 1].tt != 0 )
  {
    if ( t->node == &dummynode_ )
      return t->sizearray;
    else
      return unbound_search(t, j: t->sizearray);
  }
  else
  {
    result = 0;
    if ( sizearray > 1 )
    {
      do
      {
        if ( array[((result + sizearray) >> 1) - 1].tt != 0 )
          result = (result + sizearray) >> 1;
        else
          sizearray = (result + sizearray) >> 1;
      }
      while ( sizearray - result > 1 );
    }
  }
  return result;
}
