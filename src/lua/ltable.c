// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ltable.c
// Functions: 22
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047BB80
// Name: mainposition
// Source: json
//------------------------------------------------------------------------------
Node *__usercall mainposition@<eax>(const Table *t@<esi>, const lua_TValue *key@<edx>)
{
  unsigned int b; // eax
  Node *result; // eax
  long double v4; // [esp+4h] [ebp-8h]

  switch ( key->tt )
  {
    case 1:
      result = &t->node[key->value.b & ((1 << t->lsizenode) - 1)];
      break;
    case 3:
      v4 = key->value.n + 1.0;
      b = HIDWORD(v4) + LODWORD(v4);
      goto LABEL_6;
    case 4:
      result = &t->node[*(_DWORD *)(key->value.b + 8) & ((1 << t->lsizenode) - 1)];
      break;
    default:
      b = key->value.b;
LABEL_6:
      result = &t->node[b % (((1 << t->lsizenode) - 1) | 1u)];
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047BC20
// Name: findindex
// Source: json
//------------------------------------------------------------------------------
int __cdecl findindex(lua_State *L, Table *t, lua_TValue *key)
{
  int tt; // eax
  long double n; // st7
  int v6; // ecx
  Node *next; // edi

  tt = key->tt;
  if ( tt == 0 )
    return -1;
  if ( tt == 3 )
  {
    n = key->value.n;
    v6 = (int)n;
    if ( (double)(int)n == n && v6 > 0 && v6 <= t->sizearray )
      return v6 - 1;
  }
  next = mainposition(t, key);
  while ( !luaO_rawequalObj(t1: (const lua_TValue *)&next->i_key, t2: key)
       && (next->i_key.nk.tt != 11 || key->tt < 4 || next->i_key.nk.value.b != key->value.b) )
  {
    next = next->i_key.nk.next;
    if ( next == nullptr )
      luaG_runerror(L, fmt: "invalid key to 'next'");
  }
  return t->sizearray + next - t->node;
}

//------------------------------------------------------------------------------
// Address: 0x0047BCE0
// Name: int luaH_next(struct lua_State __near *,struct Table __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaH_next(lua_State *L, Table *t, TKey *key)
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

  v3 = findindex(L, t, (lua_TValue *)key);
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
// Address: 0x0047BDD0
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
// Address: 0x0047BE50
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
// Address: 0x0047BED0
// Name: numusehash
// Source: json
//------------------------------------------------------------------------------
int __cdecl numusehash(const Table *t, int *nums, int *pnasize)
{
  int v4; // esi
  int v5; // edi
  Node *node; // eax
  long double n; // st7
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int totaluse; // [esp+14h] [ebp-4h]
  int ause; // [esp+20h] [ebp+8h]

  v4 = 1 << t->lsizenode;
  totaluse = 0;
  ause = 0;
  if ( v4 != 0 )
  {
    v5 = v4;
    do
    {
      node = t->node;
      --v5;
      --v4;
      if ( node[v5].i_val.tt != 0 )
      {
        if ( node[v5].i_key.nk.tt == 3
          && (n = node[v5].i_key.nk.value.n, v8 = (int)n, (double)(int)n == n)
          && (unsigned int)(v8 - 1) <= 0x3FFFFFF )
        {
          v9 = luaO_log2(x: v8 - 1);
          ++nums[v9 + 1];
          v10 = 1;
        }
        else
        {
          v10 = 0;
        }
        ause += v10;
        ++totaluse;
      }
    }
    while ( v4 != 0 );
    *pnasize += ause;
    return totaluse;
  }
  else
  {
    *pnasize = *pnasize;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BF90
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
    luaM_toobig(L);
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
// Address: 0x0047BFF0
// Name: setnodevector
// Source: json
//------------------------------------------------------------------------------
void __usercall setnodevector(Table *t@<edi>, int size@<eax>, lua_State *L)
{
  int v3; // esi
  int v4; // eax
  int v5; // ecx
  int i; // edx
  Node *node; // eax
  Node *v8; // esi
  unsigned __int8 lsize; // [esp+8h] [ebp-4h]

  v3 = size;
  if ( size != 0 )
  {
    v4 = luaO_log2(x: size - 1) + 1;
    lsize = v4;
    if ( v4 > 26 )
      luaG_runerror(L, fmt: "table overflow");
    v3 = 1 << v4;
    if ( (unsigned int)((1 << v4) + 1) > 0x7FFFFFF )
      luaM_toobig(L);
    t->node = (Node *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 32 * v3);
    if ( v3 > 0 )
    {
      v5 = 0;
      for ( i = v3; i != 0; --i )
      {
        node = t->node;
        node[v5].i_key.nk.next = nullptr;
        node[v5].i_key.nk.tt = 0;
        node[v5++].i_val.tt = 0;
      }
    }
  }
  else
  {
    t->node = &dummynode_;
    lsize = 0;
  }
  v8 = &t->node[v3];
  t->lsizenode = lsize;
  t->lastfree = v8;
}

//------------------------------------------------------------------------------
// Address: 0x0047C0A0
// Name: struct Table __near * luaH_new(struct lua_State __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaH_new(lua_State *L, int narray, int nhash)
{
  GCObject *v3; // esi

  v3 = (GCObject *)luaM_realloc_(L, block: nullptr, osize: 0, nsize: 0x20u);
  luaC_link(L, o: v3, tt: 5u);
  v3->ts.tsv.hash = 0;
  v3->ts.tsv.len = 0;
  v3->h.sizearray = 0;
  *(_WORD *)(&v3->p.marked + 1) = 255;
  v3->u.uv.len = (unsigned int)&dummynode_;
  setarrayvector(L, t: (Table *)v3, size: narray);
  setnodevector(t: (Table *)v3, size: nhash, L);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047C100
// Name: void luaH_free(struct lua_State __near *,struct Table __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaH_free(lua_State *L, Table *t)
{
  Node *node; // eax

  node = t->node;
  if ( node != &dummynode_ )
    luaM_realloc_(L, block: node, osize: 32 * (1 << t->lsizenode), nsize: 0);
  luaM_realloc_(L, block: t->array, osize: 16 * t->sizearray, nsize: 0);
  luaM_realloc_(L, block: t, osize: 0x20u, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047C160
// Name: struct lua_TValue const __near * luaH_getnum(struct Table __near *,int)
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_getnum(Table *t, int key)
{
  Node *next; // edx
  double v4; // [esp+4h] [ebp-8h]

  if ( (unsigned int)(key - 1) < t->sizearray )
    return (Node *)&t->array[key - 1];
  v4 = (double)key + 1.0;
  next = &t->node[(HIDWORD(v4) + LODWORD(v4)) % (((1 << t->lsizenode) - 1) | 1u)];
  while ( next->i_key.nk.tt != 3 || next->i_key.nk.value.n != (double)key )
  {
    next = next->i_key.nk.next;
    if ( next == nullptr )
      return (Node *)&luaO_nilobject_;
  }
  return next;
}

//------------------------------------------------------------------------------
// Address: 0x0047C1F0
// Name: struct lua_TValue const __near * luaH_getstr(struct Table __near *,union TString __near *)
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_getstr(Table *t, TString *key)
{
  Node *result; // eax

  result = &t->node[key->tsv.hash & ((1 << t->lsizenode) - 1)];
  while ( result->i_key.nk.tt != 4 || (TString *)result->i_key.nk.value.gc != key )
  {
    result = result->i_key.nk.next;
    if ( result == nullptr )
      return (Node *)&luaO_nilobject_;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C230
// Name: struct lua_TValue const __near * luaH_get(struct Table __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_get(Table *t, const lua_TValue *key)
{
  int tt; // eax
  int v3; // eax
  Node *next; // esi

  tt = key->tt;
  if ( tt == 0 )
    return (Node *)&luaO_nilobject_;
  v3 = tt - 3;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
      return luaH_getstr(t, key: (TString *)key->value.gc);
  }
  else if ( (double)(int)key->value.n == key->value.n )
  {
    return luaH_getnum(t, key: (int)key->value.n);
  }
  next = mainposition(t, key);
  while ( !luaO_rawequalObj(t1: (const lua_TValue *)&next->i_key, t2: key) )
  {
    next = next->i_key.nk.next;
    if ( next == nullptr )
      return (Node *)&luaO_nilobject_;
  }
  return next;
}

//------------------------------------------------------------------------------
// Address: 0x0047C2E0
// Name: struct lua_TValue __near * luaH_set(struct lua_State __near *,struct Table __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_set(lua_State *L, Table *t, const lua_TValue *key)
{
  Node *result; // eax
  int tt; // eax

  result = luaH_get(t, key);
  t->flags = 0;
  if ( result == (Node *)&luaO_nilobject_ )
  {
    tt = key->tt;
    if ( tt == 0 )
      luaG_runerror(L, fmt: "table index is nil");
    return (Node *)newkey(L, t, key);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C350
// Name: struct lua_TValue __near * luaH_setnum(struct lua_State __near *,struct Table __near *,int)
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_setnum(lua_State *L, Table *t, int key)
{
  Node *result; // eax
  lua_TValue k; // [esp+8h] [ebp-10h] BYREF

  result = luaH_getnum(t, key);
  if ( result == (Node *)&luaO_nilobject_ )
  {
    k.value.n = (double)key;
    k.tt = 3;
    return (Node *)newkey(L, t, key: &k);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C3A0
// Name: unbound_search
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall unbound_search@<eax>(unsigned int j@<eax>, Table *t)
{
  unsigned int sizearray; // edi
  signed int v4; // esi
  Node *next; // edx
  int k; // esi
  double v8; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp+8h]

  sizearray = t->sizearray;
  i = j;
  v4 = j + 1;
  while ( 1 )
  {
    if ( v4 - 1 >= sizearray )
    {
      v8 = (double)v4 + 1.0;
      next = &t->node[(HIDWORD(v8) + LODWORD(v8)) % (((1 << t->lsizenode) - 1) | 1u)];
      while ( next->i_key.nk.tt != 3 || next->i_key.nk.value.n != (double)v4 )
      {
        next = next->i_key.nk.next;
        if ( next == nullptr )
        {
          next = (Node *)&luaO_nilobject_;
          break;
        }
      }
    }
    else
    {
      next = (Node *)&t->array[v4 - 1];
    }
    if ( next->i_val.tt == 0 )
      break;
    i = v4;
    v4 *= 2;
    if ( (unsigned int)v4 > 0x7FFFFFFD )
    {
      for ( k = 1; luaH_getnum(t, key: k)->i_val.tt != 0; ++k )
        ;
      return k - 1;
    }
  }
  while ( v4 - i > 1 )
  {
    if ( luaH_getnum(t, key: (i + v4) >> 1)->i_val.tt != 0 )
      i = (i + v4) >> 1;
    else
      v4 = (i + v4) >> 1;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x0047C4C0
// Name: int luaH_getn(struct Table __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl luaH_getn(Table *t)
{
  unsigned int result; // eax
  lua_TValue *array; // esi
  unsigned int v3; // edx

  result = t->sizearray;
  if ( result == 0 || (array = t->array)[result - 1].tt != 0 )
  {
    if ( t->node != &dummynode_ )
      return unbound_search(j: result, t);
  }
  else
  {
    v3 = 0;
    if ( result > 1 )
    {
      do
      {
        if ( array[((v3 + result) >> 1) - 1].tt != 0 )
          v3 = (v3 + result) >> 1;
        else
          result = (v3 + result) >> 1;
      }
      while ( result - v3 > 1 );
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C520
// Name: resize
// Source: json
//------------------------------------------------------------------------------
void __usercall resize(Table *t@<eax>, lua_State *L, int nasize, int nhsize)
{
  int lsizenode; // ecx
  Node *node; // edx
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // edi
  lua_TValue *v11; // ebx
  Node *v12; // eax
  int v13; // eax
  int v14; // edi
  TKey *p_i_key; // ebx
  Node *v16; // eax
  int tt; // eax
  lua_TValue key; // [esp+Ch] [ebp-28h] BYREF
  int oldhsize; // [esp+1Ch] [ebp-18h]
  unsigned int v20; // [esp+20h] [ebp-14h]
  int v21; // [esp+24h] [ebp-10h]
  Node *nold; // [esp+28h] [ebp-Ch]
  int v23; // [esp+2Ch] [ebp-8h]
  int oldasize; // [esp+30h] [ebp-4h]
  int nasizea; // [esp+40h] [ebp+Ch]
  int nasizeb; // [esp+40h] [ebp+Ch]

  lsizenode = t->lsizenode;
  node = t->node;
  oldasize = t->sizearray;
  oldhsize = lsizenode;
  nold = node;
  if ( nasize > oldasize )
    setarrayvector(L, t, size: nasize);
  setnodevector(t, size: nhsize, L);
  v8 = oldasize;
  if ( nasize < oldasize )
  {
    v9 = 16 * nasize;
    v10 = nasize + 1;
    t->sizearray = nasize;
    v20 = nasize + 1;
    v21 = 16 * nasize;
    nasizea = nasize;
    v23 = v8 - nasize;
    do
    {
      v11 = &t->array[nasizea];
      if ( v11->tt != 0 )
      {
        v12 = luaH_getnum(t, key: v10);
        if ( v12 == (Node *)&luaO_nilobject_ )
        {
          key.value.n = (double)v10;
          key.tt = 3;
          v12 = (Node *)newkey(L, t, &key);
        }
        v12->i_val.value.b = v11->value.b;
        *(&v12->i_val.value.b + 1) = *(&v11->value.b + 1);
        v8 = oldasize;
        v12->i_val.tt = v11->tt;
        v9 = v21;
      }
      ++nasizea;
      ++v10;
      --v23;
    }
    while ( v23 != 0 );
    if ( v20 > 0xFFFFFFF )
      luaM_toobig(L);
    t->array = (lua_TValue *)luaM_realloc_(L, block: t->array, osize: 16 * v8, nsize: v9);
  }
  v13 = 1 << oldhsize;
  v14 = (1 << oldhsize) - 1;
  nasizeb = 1 << oldhsize;
  if ( v14 >= 0 )
  {
    p_i_key = &nold[v14].i_key;
    do
    {
      if ( p_i_key[-1].nk.tt != 0 )
      {
        v16 = luaH_get(t, key: (const lua_TValue *)p_i_key);
        t->flags = 0;
        if ( v16 == (Node *)&luaO_nilobject_ )
        {
          tt = p_i_key->nk.tt;
          if ( tt == 0 )
            luaG_runerror(L, fmt: "table index is nil");
          v16 = (Node *)newkey(L, t, key: (const lua_TValue *)p_i_key);
        }
        v16->i_val.value.b = p_i_key[-1].nk.value.b;
        *(&v16->i_val.value.b + 1) = *(&p_i_key[-1].tvk.value.b + 1);
        v16->i_val.tt = p_i_key[-1].nk.tt;
        v13 = nasizeb;
      }
      p_i_key -= 2;
      --v14;
    }
    while ( v14 >= 0 );
  }
  if ( nold != &dummynode_ )
    luaM_realloc_(L, block: nold, osize: 32 * v13, nsize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047C6E0
// Name: void luaH_resizearray(struct lua_State __near *,struct Table __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaH_resizearray(lua_State *L, Table *t, int nasize)
{
  if ( t->node == &dummynode_ )
    resize(t, L, nasize, nhsize: 0);
  else
    resize(t, L, nasize, nhsize: 1 << t->lsizenode);
}

//------------------------------------------------------------------------------
// Address: 0x0047C730
// Name: rehash
// Source: json
//------------------------------------------------------------------------------
void __usercall rehash(Table *t@<edi>, lua_State *L, const lua_TValue *ek)
{
  const lua_TValue *v3; // ebx
  const lua_TValue *v4; // esi
  char *v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int nums[27]; // [esp+8h] [ebp-78h] BYREF
  long double n; // [esp+74h] [ebp-Ch]
  int v12; // [esp+7Ch] [ebp-4h]

  v3 = ek;
  memset(nums, 0, sizeof(nums));
  ek = (const lua_TValue *)numusearray(t, nums);
  v4 = ek;
  v5 = (char *)v4 + numusehash(t, nums, pnasize: (int *)&ek);
  if ( v3->tt == 3 && (n = v3->value.n, v12 = (int)n, v6 = (int)n, (double)(int)n == n) && v6 > 0 && v6 <= 0x4000000 )
  {
    v7 = luaO_log2(x: v6 - 1);
    ++nums[v7 + 1];
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  ek = (const lua_TValue *)((char *)ek + v8);
  v9 = computesizes(nums, narray: (int *)&ek);
  resize(t, L, nasize: (int)ek, nhsize: (int)&v5[-v9 + 1]);
}

//------------------------------------------------------------------------------
// Address: 0x0047C830
// Name: newkey
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl newkey(lua_State *L, GCObject *t, const lua_TValue *key)
{
  const lua_TValue *v3; // ebx
  Node *v4; // eax
  Node *v5; // edi
  Node *lastfree; // ebx
  Node *next; // eax

  v3 = key;
  v4 = mainposition((const Table *)t, key);
  v5 = v4;
  if ( v4->i_val.tt != 0 || v4 == &dummynode_ )
  {
    if ( t->cl.l.upvals[0] <= t->uv.u.l.prev )
    {
LABEL_7:
      --t->cl.l.upvals[0];
LABEL_10:
      rehash((Table *)t, L, ek: v3);
      return luaH_set(L, (Table *)t, key: v3);
    }
    while ( 1 )
    {
      --t->cl.l.upvals[0];
      lastfree = t->h.lastfree;
      if ( lastfree->i_key.nk.tt == 0 )
        break;
      if ( (unsigned int)lastfree <= t->u.uv.len )
      {
        v3 = key;
        goto LABEL_7;
      }
    }
    if ( lastfree == nullptr )
    {
      v3 = key;
      goto LABEL_10;
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
  if ( v3->tt >= 4 && (*(_BYTE *)(v3->value.b + 5) & 3) != 0 && (t->gch.marked & 4) != 0 )
    luaC_barrierback(L, t);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047C940
// Name: struct lua_TValue __near * luaH_setstr(struct lua_State __near *,struct Table __near *,union TString __near *)
// Source: json
//------------------------------------------------------------------------------
Node *__cdecl luaH_setstr(lua_State *L, GCObject *t, TString *key)
{
  Node *result; // eax
  lua_TValue k; // [esp+0h] [ebp-10h] BYREF

  result = (Node *)(t->u.uv.len + 32 * (key->tsv.hash & ((1 << t->cl.c.nupvalues) - 1)));
  while ( result->i_key.nk.tt != 4 || (TString *)result->i_key.nk.value.gc != key )
  {
    result = result->i_key.nk.next;
    if ( result == nullptr )
      goto LABEL_7;
  }
  if ( result != (Node *)&luaO_nilobject_ )
    return result;
LABEL_7:
  k.value.b = (int)key;
  k.tt = 4;
  return newkey(L, t, key: &k);
}
