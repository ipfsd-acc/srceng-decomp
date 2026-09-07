// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/llex.c
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000EEA0
// Name: save
// Source: json
//------------------------------------------------------------------------------
void __usercall save(LexState *ls@<eax>, char c)
{
  Mbuffer *buff; // esi
  unsigned int buffsize; // eax
  unsigned int v5; // edx
  int v6; // ebx
  lua_State *v7; // ecx
  global_State *l_G; // edi
  int v9; // eax
  lua_State *L; // [esp+10h] [ebp-8h]
  unsigned int v11; // [esp+14h] [ebp-4h]

  buff = ls->buff;
  buffsize = buff->buffsize;
  if ( buff->n + 1 > buffsize )
  {
    if ( buffsize >= 0x7FFFFFFE )
      luaX_lexerror(ls, msg: "lexical element too long", token: 0);
    v5 = buff->buffsize;
    v6 = 2 * v5;
    v11 = v5;
    if ( 2 * v5 + 1 > 0xFFFFFFFD )
      luaG_runerror(L: ls->L, fmt: "memory allocation error: block too big");
    v7 = ls->L;
    l_G = v7->l_G;
    L = v7;
    v9 = (int)l_G->frealloc(a1: l_G->ud, a2: buff->buffer, a3: v5, a4: 2 * v5);
    if ( v9 == 0 && v6 != 0 )
      luaD_throw(L, errcode: 4);
    l_G->totalbytes += v6 - v11;
    buff->buffer = (char *)v9;
    buff->buffsize = v6;
  }
  buff->buffer[buff->n++] = c;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF50
// Name: _luaX_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaX_init(lua_State *L)
{
  const char *v1; // edx
  unsigned int v2; // edi
  unsigned int v3; // esi
  unsigned int v4; // ecx
  char *v5; // ebx
  unsigned __int8 v6; // al
  GCObject *v7; // ebx
  unsigned int v8; // eax
  lua_TValue *upvalue; // ecx
  const char *v10; // esi
  TString *v11; // eax
  unsigned int v12; // [esp+Ch] [ebp-14h]
  unsigned int k; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  const char *v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  for ( i = 0; i < 21; ++i )
  {
    v1 = luaX_tokens[i];
    v15 = v1;
    v2 = strlen(v1);
    v3 = (v2 >> 5) + 1;
    v4 = v2;
    v12 = v2;
    k = v2;
    if ( v2 >= v3 )
    {
      v5 = (char *)&v1[v2 - 1];
      v16 = 1 - (_DWORD)v1;
      do
      {
        v12 ^= (unsigned __int8)*v5 + (v4 >> 2) + 32 * v4;
        v6 = tolower(c: *v5);
        v4 = v12;
        k ^= (k >> 2) + 32 * k + v6;
        v5 -= v3;
      }
      while ( (unsigned int)&v5[v16] >= v3 );
      v1 = v15;
    }
    v7 = L->l_G->strt.hash[v4 & (L->l_G->strt.size - 1)];
    if ( v7 == nullptr )
    {
LABEL_19:
      v11 = newlstr(L, str: v1, l: v2, h: v4, k);
      goto LABEL_20;
    }
    while ( v7->ts.tsv.len != v2 )
    {
LABEL_18:
      v7 = (GCObject *)v7->ts.dummy.l;
      if ( v7 == nullptr )
        goto LABEL_19;
    }
    v8 = v2;
    upvalue = v7->cl.c.upvalue;
    v10 = v1;
    if ( v2 >= 4 )
    {
      while ( *(_DWORD *)v10 == upvalue->value.b )
      {
        v8 -= 4;
        upvalue = (lua_TValue *)((char *)upvalue + 4);
        v10 += 4;
        if ( v8 < 4 )
          goto LABEL_11;
      }
LABEL_17:
      v1 = v15;
      v4 = v12;
      goto LABEL_18;
    }
LABEL_11:
    if ( v8 != 0
      && (LOBYTE(upvalue->value.n) != *v10
       || v8 > 1 && (BYTE1(upvalue->value.gc) != v10[1] || v8 > 2 && BYTE2(upvalue->value.p) != v10[2])) )
    {
      goto LABEL_17;
    }
    if ( ((unsigned __int8)~L->l_G->currentwhite & v7->gch.marked & 3) != 0 )
      v7->gch.marked ^= 3u;
    v11 = (TString *)v7;
LABEL_20:
    v11->tsv.marked |= 0x20u;
    v11->tsv.reserved = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F0C0
// Name: _luaX_token2str
// Source: json
//------------------------------------------------------------------------------
const char *__usercall luaX_token2str@<eax>(LexState *ls@<edi>, int token@<esi>)
{
  if ( token >= 257 )
    return *((const char **)&strlib[2].func + token);
  if ( iscntrl(c: token) != 0 )
    return luaO_pushfstring(L: ls->L, fmt: "char(%d)", token);
  return luaO_pushfstring(L: ls->L, fmt: "%c", token);
}

//------------------------------------------------------------------------------
// Address: 0x1000F110
// Name: txtToken
// Source: json
//------------------------------------------------------------------------------
char *__usercall txtToken@<eax>(LexState *ls@<edi>, int token@<esi>)
{
  if ( token < 284 || token > 286 )
  {
    if ( token >= 257 )
    {
      return *((char **)&strlib[2].func + token);
    }
    else if ( iscntrl(c: token) != 0 )
    {
      return (char *)luaO_pushfstring(L: ls->L, fmt: "char(%d)", token);
    }
    else
    {
      return (char *)luaO_pushfstring(L: ls->L, fmt: "%c", token);
    }
  }
  else
  {
    save(ls, c: 0);
    return ls->buff->buffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F180
// Name: _luaX_lexerror
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaX_lexerror(LexState *ls, const char *msg, int token)
{
  const char *v3; // ebx
  char *v4; // eax
  char buff[80]; // [esp+10h] [ebp-50h] BYREF

  luaO_chunkid(out: buff, source: (const char *)&ls->source[1], bufflen: 0x50u);
  v3 = luaO_pushfstring(L: ls->L, fmt: "%s:%d: %s", buff, ls->linenumber, msg);
  if ( token != 0 )
  {
    v4 = txtToken(ls, token);
    luaO_pushfstring(L: ls->L, fmt: "%s near '%s'", v3, v4);
  }
  luaD_throw(L: ls->L, errcode: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1000F200
// Name: _luaX_newstring
// Source: json
//------------------------------------------------------------------------------
TString *__usercall luaX_newstring@<eax>(const char *str@<ecx>, unsigned int l@<eax>, LexState *ls)
{
  lua_State *v3; // edi
  TString *v4; // eax
  Table *h; // ebx
  int v6; // esi
  lua_TValue *v7; // eax
  lua_TValue key; // [esp+10h] [ebp-14h] BYREF

  v3 = ls->L;
  v4 = luaS_newlstr(L: v3, str, l);
  h = ls->fs->h;
  v6 = (int)v4;
  v7 = (lua_TValue *)luaH_getstr(t: h, key: v4);
  if ( v7 == &luaO_nilobject_ )
  {
    key.value.b = v6;
    key.tt = 4;
    v7 = newkey(L: v3, t: h, &key);
  }
  if ( v7->tt == 0 )
  {
    v7->value.b = 1;
    v7->tt = 1;
  }
  return (TString *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1000F270
// Name: inclinenumber
// Source: json
//------------------------------------------------------------------------------
void __usercall inclinenumber(LexState *ls@<esi>)
{
  Zio *z; // eax
  unsigned int n; // ecx
  int current; // ebx
  Zio *v4; // eax
  const char *p; // edx
  int v6; // ecx
  Zio *v7; // edi
  const char *v8; // eax
  int v9; // ecx
  Zio *v10; // eax
  unsigned int v11; // ecx
  Zio *v12; // eax
  const char *v13; // edx
  int v14; // ecx
  Zio *v15; // edi
  const char *v16; // eax
  int v17; // ecx
  int v18; // [esp+Ch] [ebp-4h] BYREF

  z = ls->z;
  n = z->n;
  current = ls->current;
  --z->n;
  if ( n != 0 )
  {
    v4 = ls->z;
    p = v4->p;
    v6 = *(unsigned __int8 *)p;
    v4->p = p + 1;
  }
  else
  {
    v7 = ls->z;
    v8 = v7->reader(a1: v7->L, a2: v7->data, a3: (unsigned int *)&v18);
    if ( v8 != nullptr && (v9 = v18, v18 != 0) )
    {
      v7->p = v8;
      v7->n = v9 - 1;
      v6 = *(unsigned __int8 *)v8;
      v7->p = v8 + 1;
    }
    else
    {
      v6 = -1;
    }
  }
  ls->current = v6;
  if ( (v6 == 10 || v6 == 13) && v6 != current )
  {
    v10 = ls->z;
    v11 = v10->n--;
    if ( v11 != 0 )
    {
      v12 = ls->z;
      v13 = v12->p;
      v14 = *(unsigned __int8 *)v13;
      v12->p = v13 + 1;
    }
    else
    {
      v15 = ls->z;
      v16 = v15->reader(a1: v15->L, a2: v15->data, a3: (unsigned int *)&v18);
      if ( v16 != nullptr && (v17 = v18, v18 != 0) )
      {
        v15->p = v16;
        v15->n = v17 - 1;
        v14 = *(unsigned __int8 *)v16;
        v15->p = v16 + 1;
      }
      else
      {
        v14 = -1;
      }
    }
    ls->current = v14;
  }
  if ( ++ls->linenumber >= 2147483645 )
    luaX_lexerror(ls, msg: "chunk has too many lines", token: ls->t.token);
}

//------------------------------------------------------------------------------
// Address: 0x1000F350
// Name: _luaX_setinput
// Source: json
//------------------------------------------------------------------------------
void __usercall luaX_setinput(LexState *ls@<esi>, Zio *z@<eax>, TString *source@<edx>, lua_State *L)
{
  Mbuffer *buff; // eax
  unsigned int buffsize; // ebx
  global_State *l_G; // edi
  char *v7; // eax
  Zio *v8; // eax
  unsigned int v9; // ecx
  Zio *v10; // eax
  const char *p; // ecx
  int v12; // edx
  Zio *v13; // edi
  const char *v14; // eax
  unsigned int v15; // ecx
  int v16; // edx
  int v17; // [esp+Ch] [ebp-4h] BYREF

  ls->z = z;
  ls->linenumber = 1;
  ls->lastline = 1;
  buff = ls->buff;
  ls->decpoint = 46;
  ls->L = L;
  ls->lookahead.token = 287;
  ls->fs = nullptr;
  ls->source = source;
  buffsize = buff->buffsize;
  l_G = L->l_G;
  v7 = (char *)l_G->frealloc(a1: l_G->ud, a2: buff->buffer, a3: buffsize, a4: 32u);
  if ( v7 == nullptr )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 32 - buffsize;
  ls->buff->buffer = v7;
  ls->buff->buffsize = 32;
  v8 = ls->z;
  v9 = v8->n--;
  if ( v9 != 0 )
  {
    v10 = ls->z;
    p = v10->p;
    v12 = *(unsigned __int8 *)p;
    v10->p = p + 1;
    ls->current = v12;
  }
  else
  {
    v13 = ls->z;
    v14 = v13->reader(a1: v13->L, a2: v13->data, a3: (unsigned int *)&v17);
    if ( v14 != nullptr && v17 != 0 )
    {
      v15 = v17 - 1;
      v13->p = v14;
      v13->n = v15;
      v16 = *(unsigned __int8 *)v14;
      v13->p = v14 + 1;
      ls->current = v16;
    }
    else
    {
      ls->current = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F430
// Name: check_next
// Source: json
//------------------------------------------------------------------------------
int __usercall check_next@<eax>(LexState *ls@<edi>)
{
  Zio *z; // eax
  unsigned int v2; // ecx
  Zio *v3; // eax
  const char *p; // ecx
  int v5; // edx
  Zio *v7; // esi
  const char *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // [esp+4h] [ebp-4h] BYREF

  save(ls, c: ls->current);
  z = ls->z;
  v2 = z->n--;
  if ( v2 != 0 )
  {
    v3 = ls->z;
    p = v3->p;
    v5 = *(unsigned __int8 *)p;
    v3->p = p + 1;
    ls->current = v5;
    return 1;
  }
  else
  {
    v7 = ls->z;
    v8 = v7->reader(a1: v7->L, a2: v7->data, a3: (unsigned int *)&v11);
    if ( v8 != nullptr && (v9 = v11, v11 != 0) )
    {
      v7->p = v8;
      v7->n = v9 - 1;
      v10 = *(unsigned __int8 *)v8;
      v7->p = v8 + 1;
      ls->current = v10;
      return 1;
    }
    else
    {
      ls->current = -1;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F4C0
// Name: trydecpoint
// Source: json
//------------------------------------------------------------------------------
void __cdecl trydecpoint(LexState *ls, SemInfo *seminfo)
{
  lconv *v3; // eax
  char v4; // al
  Mbuffer *buff; // ecx
  unsigned int n; // eax
  char *buffer; // ecx
  Mbuffer *v8; // ecx
  unsigned int v9; // eax
  char decpoint; // dl
  char *v11; // ecx
  char v12; // [esp+Ch] [ebp-4h]
  char old_3; // [esp+1Bh] [ebp+Bh]

  v3 = localeconv();
  old_3 = ls->decpoint;
  if ( v3 != nullptr )
    v4 = *v3->decimal_point;
  else
    v4 = 46;
  buff = ls->buff;
  ls->decpoint = v4;
  v12 = v4;
  n = buff->n;
  buffer = buff->buffer;
  while ( n != 0 )
  {
    if ( buffer[--n] == old_3 )
      buffer[n] = v12;
  }
  if ( luaO_str2d(s: ls->buff->buffer, result: &seminfo->r) == 0 )
  {
    v8 = ls->buff;
    v9 = v8->n;
    decpoint = ls->decpoint;
    v11 = v8->buffer;
    while ( v9 != 0 )
    {
      if ( v11[--v9] == decpoint )
        v11[v9] = 46;
    }
    luaX_lexerror(ls, msg: "malformed number", token: 284);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F560
// Name: read_numeral
// Source: json
//------------------------------------------------------------------------------
void __cdecl read_numeral(LexState *ls, SemInfo *seminfo)
{
  LexState *v2; // ebx
  Zio *z; // eax
  unsigned int v4; // ecx
  Zio *v5; // eax
  const char *p; // edx
  int v7; // ecx
  Zio *v8; // esi
  const char *v9; // eax
  LexState *v10; // ecx
  int v11; // eax
  int v12; // eax
  Zio *v13; // eax
  unsigned int v14; // ecx
  Zio *v15; // eax
  const char *v16; // edx
  int v17; // ecx
  Zio *v18; // esi
  const char *v19; // eax
  LexState *v20; // ecx
  int v21; // ecx
  Mbuffer *buff; // ecx
  unsigned int n; // eax
  char decpoint; // dl
  char *buffer; // esi
  SemInfo *v26; // edi

  v2 = ls;
  do
  {
    save(ls: v2, c: v2->current);
    z = v2->z;
    v4 = z->n--;
    if ( v4 != 0 )
    {
      v5 = v2->z;
      p = v5->p;
      v7 = *(unsigned __int8 *)p;
      v5->p = p + 1;
    }
    else
    {
      v8 = v2->z;
      v9 = v8->reader(a1: v8->L, a2: v8->data, a3: (unsigned int *)&ls);
      if ( v9 != nullptr && (v10 = ls, ls != nullptr) )
      {
        v8->p = v9;
        v8->n = (unsigned int)(&v10[-1].decpoint + 3);
        v7 = *(unsigned __int8 *)v9;
        v8->p = v9 + 1;
      }
      else
      {
        v7 = -1;
      }
    }
    v2->current = v7;
  }
  while ( isdigit(c: v7) != 0 || v2->current == 46 );
  strchr(string: "Ee", chr: v2->current);
  if ( v11 != 0 && check_next(ls: v2) != 0 )
  {
    strchr(string: "+-", chr: v2->current);
    if ( v12 != 0 )
      check_next(ls: v2);
  }
  while ( isalnum(c: v2->current) != 0 || v2->current == 95 )
  {
    save(ls: v2, c: v2->current);
    v13 = v2->z;
    v14 = v13->n--;
    if ( v14 != 0 )
    {
      v15 = v2->z;
      v16 = v15->p;
      v17 = *(unsigned __int8 *)v16;
      v15->p = v16 + 1;
      v2->current = v17;
    }
    else
    {
      v18 = v2->z;
      v19 = v18->reader(a1: v18->L, a2: v18->data, a3: (unsigned int *)&ls);
      if ( v19 != nullptr && (v20 = ls, ls != nullptr) )
      {
        v18->p = v19;
        v18->n = (unsigned int)(&v20[-1].decpoint + 3);
        v21 = *(unsigned __int8 *)v19;
        v18->p = v19 + 1;
        v2->current = v21;
      }
      else
      {
        v2->current = -1;
      }
    }
  }
  save(ls: v2, c: 0);
  buff = v2->buff;
  n = buff->n;
  decpoint = v2->decpoint;
  buffer = buff->buffer;
  while ( n != 0 )
  {
    if ( buffer[--n] == 46 )
      buffer[n] = decpoint;
  }
  v26 = seminfo;
  if ( luaO_str2d(s: v2->buff->buffer, result: &seminfo->r) == 0 )
    trydecpoint(ls: v2, seminfo: v26);
}

//------------------------------------------------------------------------------
// Address: 0x1000F6F0
// Name: skip_sep
// Source: json
//------------------------------------------------------------------------------
int __usercall skip_sep@<eax>(LexState *ls@<esi>)
{
  int v1; // ebx
  Zio *z; // eax
  unsigned int v3; // ecx
  Zio *v4; // eax
  const char *p; // edx
  int v6; // ecx
  Zio *v7; // edi
  const char *v8; // eax
  int v9; // ecx
  Zio *v10; // eax
  unsigned int v11; // ecx
  Zio *v12; // eax
  const char *v13; // edx
  int v14; // ecx
  Zio *v15; // edi
  const char *v16; // eax
  int v17; // ecx
  int current; // [esp+8h] [ebp-8h]
  int v20; // [esp+Ch] [ebp-4h] BYREF

  current = ls->current;
  v1 = 0;
  save(ls, c: ls->current);
  z = ls->z;
  v3 = z->n--;
  if ( v3 != 0 )
  {
    v4 = ls->z;
    p = v4->p;
    v6 = *(unsigned __int8 *)p;
    v4->p = p + 1;
  }
  else
  {
    v7 = ls->z;
    v8 = v7->reader(a1: v7->L, a2: v7->data, a3: (unsigned int *)&v20);
    if ( v8 != nullptr && (v9 = v20, v20 != 0) )
    {
      v7->p = v8;
      v7->n = v9 - 1;
      v6 = *(unsigned __int8 *)v8;
      v7->p = v8 + 1;
    }
    else
    {
      v6 = -1;
    }
  }
  ls->current = v6;
  if ( v6 == 61 )
  {
    do
    {
      save(ls, c: ls->current);
      v10 = ls->z;
      v11 = v10->n--;
      if ( v11 != 0 )
      {
        v12 = ls->z;
        v13 = v12->p;
        v14 = *(unsigned __int8 *)v13;
        v12->p = v13 + 1;
      }
      else
      {
        v15 = ls->z;
        v16 = v15->reader(a1: v15->L, a2: v15->data, a3: (unsigned int *)&v20);
        if ( v16 != nullptr && (v17 = v20, v20 != 0) )
        {
          v15->p = v16;
          v15->n = v17 - 1;
          v14 = *(unsigned __int8 *)v16;
          v15->p = v16 + 1;
        }
        else
        {
          v14 = -1;
        }
      }
      ++v1;
      ls->current = v14;
    }
    while ( v14 == 61 );
  }
  if ( ls->current == current )
    return v1;
  else
    return -1 - v1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F7F0
// Name: read_long_string
// Source: json
//------------------------------------------------------------------------------
void __usercall read_long_string(LexState *ls@<edi>, SemInfo *seminfo, int sep)
{
  Zio *z; // eax
  unsigned int v4; // ecx
  Zio *v5; // eax
  const char *p; // edx
  int v7; // ecx
  Zio *v8; // esi
  const char *v9; // eax
  int v10; // ecx
  Zio *v11; // eax
  unsigned int v12; // ecx
  Zio *v13; // eax
  const char *v14; // edx
  int v15; // ecx
  Zio *v16; // esi
  const char *v17; // eax
  int v18; // ecx
  Zio *v19; // eax
  unsigned int v20; // ecx
  Zio *v21; // ecx
  const char *v22; // edx
  int v23; // eax
  Zio *v24; // eax
  unsigned int v25; // ecx
  Zio *v26; // eax
  const char *v27; // edx
  int v28; // ecx
  Zio *v29; // esi
  const char *v30; // eax
  int v31; // ecx
  Zio *v32; // eax
  unsigned int v33; // ecx
  Zio *v34; // eax
  const char *v35; // edx
  int v36; // ecx
  int v37; // ecx
  const char *v38; // eax
  int v39; // [esp+Ch] [ebp-Ch] BYREF
  int v40; // [esp+10h] [ebp-8h] BYREF
  int v41; // [esp+14h] [ebp-4h] BYREF

  save(ls, c: ls->current);
  z = ls->z;
  v4 = z->n--;
  if ( v4 != 0 )
  {
    v5 = ls->z;
    p = v5->p;
    v7 = *(unsigned __int8 *)p;
    v5->p = p + 1;
  }
  else
  {
    v8 = ls->z;
    v9 = v8->reader(a1: v8->L, a2: v8->data, a3: (unsigned int *)&v41);
    if ( v9 != nullptr && (v10 = v41, v41 != 0) )
    {
      v8->p = v9;
      v8->n = v10 - 1;
      v7 = *(unsigned __int8 *)v9;
      v8->p = v9 + 1;
    }
    else
    {
      v7 = -1;
    }
  }
  ls->current = v7;
  if ( v7 == 10 || v7 == 13 )
    inclinenumber(ls);
  while ( 1 )
  {
    switch ( ls->current )
    {
      case 0xFFFFFFFF:
        v38 = "unfinished long string";
        if ( seminfo == nullptr )
          v38 = "unfinished long comment";
        luaX_lexerror(ls, msg: v38, token: 287);
      case 0xA:
      case 0xD:
        save(ls, c: 10);
        inclinenumber(ls);
        if ( seminfo == nullptr )
          ls->buff->n = 0;
        continue;
      case 0x5B:
        if ( skip_sep(ls) == sep )
        {
          save(ls, c: ls->current);
          v11 = ls->z;
          v12 = v11->n--;
          if ( v12 != 0 )
          {
            v13 = ls->z;
            v14 = v13->p;
            v15 = *(unsigned __int8 *)v14;
            v13->p = v14 + 1;
          }
          else
          {
            v16 = ls->z;
            v17 = v16->reader(a1: v16->L, a2: v16->data, a3: (unsigned int *)&v41);
            if ( v17 != nullptr && (v18 = v41, v41 != 0) )
            {
              v16->p = v17;
              v16->n = v18 - 1;
              v15 = *(unsigned __int8 *)v17;
              v16->p = v17 + 1;
            }
            else
            {
              v15 = -1;
            }
          }
          ls->current = v15;
          if ( sep == 0 )
            luaX_lexerror(ls, msg: "nesting of [[...]] is deprecated", token: 91);
        }
        continue;
      case 0x5D:
        if ( skip_sep(ls) != sep )
          continue;
        save(ls, c: ls->current);
        v19 = ls->z;
        v20 = v19->n--;
        if ( v20 != 0 )
        {
          v21 = ls->z;
          v22 = v21->p;
          v23 = *(unsigned __int8 *)v22;
          v21->p = v22 + 1;
        }
        else
        {
          v23 = luaZ_fill(z: ls->z);
        }
        ls->current = v23;
        if ( seminfo != nullptr )
          seminfo->ts = luaX_newstring(str: &ls->buff->buffer[sep + 2], l: ls->buff->n - 2 * sep - 4, ls);
        return;
      default:
        if ( seminfo != nullptr )
        {
          save(ls, c: ls->current);
          v24 = ls->z;
          v25 = v24->n--;
          if ( v25 != 0 )
          {
            v26 = ls->z;
            v27 = v26->p;
            v28 = *(unsigned __int8 *)v27;
            v26->p = v27 + 1;
            ls->current = v28;
            continue;
          }
          v29 = ls->z;
          v30 = v29->reader(a1: v29->L, a2: v29->data, a3: (unsigned int *)&v40);
          if ( v30 == nullptr )
            goto LABEL_36;
          v31 = v40;
        }
        else
        {
          v32 = ls->z;
          v33 = v32->n--;
          if ( v33 != 0 )
          {
            v34 = ls->z;
            v35 = v34->p;
            v36 = *(unsigned __int8 *)v35;
            v34->p = v35 + 1;
            ls->current = v36;
            continue;
          }
          v29 = ls->z;
          v30 = v29->reader(a1: v29->L, a2: v29->data, a3: (unsigned int *)&v39);
          if ( v30 == nullptr )
            goto LABEL_36;
          v31 = v39;
        }
        if ( v31 != 0 )
        {
          v29->n = v31 - 1;
          v29->p = v30;
          v37 = *(unsigned __int8 *)v30;
          v29->p = v30 + 1;
          ls->current = v37;
          continue;
        }
LABEL_36:
        ls->current = -1;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FAF0
// Name: read_string
// Source: json
//------------------------------------------------------------------------------
void __usercall read_string(LexState *ls@<edi>, int del, SemInfo *seminfo)
{
  Zio *z; // eax
  unsigned int v4; // ecx
  Zio *v5; // eax
  const char *p; // edx
  int v7; // ecx
  Zio *v8; // esi
  const char *v9; // eax
  int v10; // ecx
  Zio *v11; // eax
  unsigned int n; // ecx
  int v13; // ebx
  Zio *v14; // eax
  const char *v15; // edx
  int v16; // ecx
  Zio *v17; // esi
  const char *v18; // eax
  int v19; // ecx
  char v20; // al
  Zio *v21; // eax
  unsigned int v22; // ecx
  Zio *v23; // eax
  const char *v24; // edx
  int v25; // ecx
  Zio *v26; // esi
  const char *v27; // eax
  int v28; // ecx
  bool v29; // zf
  Zio *v30; // eax
  unsigned int v31; // ecx
  Zio *v32; // eax
  const char *v33; // edx
  Zio *v34; // eax
  unsigned int v35; // ecx
  Zio *v36; // eax
  const char *v37; // edx
  int v38; // ecx
  Zio *v39; // esi
  const char *v40; // eax
  int v41; // ecx
  int v42; // eax
  Zio *v43; // eax
  unsigned int v44; // ecx
  Zio *v45; // eax
  const char *v46; // edx
  Zio *v47; // eax
  unsigned int v48; // ecx
  Zio *v49; // ecx
  const char *v50; // edx
  int v51; // eax
  Mbuffer *buff; // ecx
  int v53; // [esp+8h] [ebp-18h] BYREF
  int v54; // [esp+Ch] [ebp-14h] BYREF
  int v55; // [esp+10h] [ebp-10h] BYREF
  int v56; // [esp+14h] [ebp-Ch] BYREF
  int v57; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h] BYREF

  save(ls, c: ls->current);
  z = ls->z;
  v4 = z->n--;
  if ( v4 != 0 )
  {
    v5 = ls->z;
    p = v5->p;
    v7 = *(unsigned __int8 *)p;
    v5->p = p + 1;
  }
  else
  {
    v8 = ls->z;
    v9 = v8->reader(a1: v8->L, a2: v8->data, a3: (unsigned int *)&i);
    if ( v9 != nullptr && (v10 = i, i != 0) )
    {
      v8->p = v9;
      v8->n = v10 - 1;
      v7 = *(unsigned __int8 *)v9;
      v8->p = v9 + 1;
    }
    else
    {
      v7 = -1;
    }
  }
  ls->current = v7;
  if ( v7 != del )
  {
    while ( 2 )
    {
      switch ( ls->current )
      {
        case 0xFFFFFFFF:
          luaX_lexerror(ls, msg: "unfinished string", token: 287);
        case 0xA:
        case 0xD:
          luaX_lexerror(ls, msg: "unfinished string", token: 286);
        case 0x5C:
          v11 = ls->z;
          n = v11->n;
          v13 = 0;
          --v11->n;
          if ( n != 0 )
          {
            v14 = ls->z;
            v15 = v14->p;
            v16 = *(unsigned __int8 *)v15;
            v14->p = v15 + 1;
          }
          else
          {
            v17 = ls->z;
            v18 = v17->reader(a1: v17->L, a2: v17->data, a3: (unsigned int *)&v57);
            if ( v18 != nullptr && (v19 = v57, v57 != 0) )
            {
              v17->p = v18;
              v17->n = v19 - 1;
              v16 = *(unsigned __int8 *)v18;
              v17->p = v18 + 1;
            }
            else
            {
              v16 = -1;
            }
          }
          ls->current = v16;
          switch ( v16 )
          {
            case -1:
              goto $LN75;
            case 10:
            case 13:
              save(ls, c: 10);
              inclinenumber(ls);
              goto $LN75;
            case 97:
              v20 = 7;
              goto LABEL_23;
            case 98:
              v20 = 8;
              goto LABEL_23;
            case 102:
              v20 = 12;
              goto LABEL_23;
            case 110:
              v20 = 10;
              goto LABEL_23;
            case 114:
              v20 = 13;
              goto LABEL_23;
            case 116:
              v20 = 9;
              goto LABEL_23;
            case 118:
              v20 = 11;
LABEL_23:
              save(ls, c: v20);
              v21 = ls->z;
              v22 = v21->n--;
              if ( v22 != 0 )
              {
                v23 = ls->z;
                v24 = v23->p;
                v25 = *(unsigned __int8 *)v24;
                v23->p = v24 + 1;
                goto LABEL_51;
              }
              v26 = ls->z;
              v27 = v26->reader(a1: v26->L, a2: v26->data, a3: (unsigned int *)&v56);
              if ( v27 == nullptr )
                goto LABEL_50;
              v28 = v56;
              v29 = v56 == 0;
              goto LABEL_48;
            default:
              if ( isdigit(c: v16) != 0 )
              {
                i = 0;
                do
                {
                  v34 = ls->z;
                  v13 = ls->current + 10 * v13 - 48;
                  v35 = v34->n--;
                  if ( v35 != 0 )
                  {
                    v36 = ls->z;
                    v37 = v36->p;
                    v38 = *(unsigned __int8 *)v37;
                    v36->p = v37 + 1;
                  }
                  else
                  {
                    v39 = ls->z;
                    v40 = v39->reader(a1: v39->L, a2: v39->data, a3: (unsigned int *)&v54);
                    if ( v40 != nullptr && (v41 = v54, v54 != 0) )
                    {
                      v39->p = v40;
                      v39->n = v41 - 1;
                      v38 = *(unsigned __int8 *)v40;
                      v39->p = v40 + 1;
                    }
                    else
                    {
                      v38 = -1;
                    }
                  }
                  v42 = i + 1;
                  ls->current = v38;
                  i = v42;
                }
                while ( v42 < 3 && isdigit(c: v38) != 0 );
                if ( v13 > 255 )
                  luaX_lexerror(ls, msg: "escape sequence too large", token: 286);
                save(ls, c: v13);
                goto $LN75;
              }
              save(ls, c: ls->current);
              v30 = ls->z;
              v31 = v30->n--;
              if ( v31 != 0 )
              {
                v32 = ls->z;
                v33 = v32->p;
                v25 = *(unsigned __int8 *)v33;
                v32->p = v33 + 1;
                goto LABEL_51;
              }
              v26 = ls->z;
              v27 = v26->reader(a1: v26->L, a2: v26->data, a3: (unsigned int *)&v55);
              if ( v27 != nullptr )
              {
                v28 = v55;
                v29 = v55 == 0;
                goto LABEL_48;
              }
              break;
          }
          goto LABEL_50;
        default:
          save(ls, c: ls->current);
          v43 = ls->z;
          v44 = v43->n--;
          if ( v44 != 0 )
          {
            v45 = ls->z;
            v46 = v45->p;
            v25 = *(unsigned __int8 *)v46;
            v45->p = v46 + 1;
          }
          else
          {
            v26 = ls->z;
            v27 = v26->reader(a1: v26->L, a2: v26->data, a3: (unsigned int *)&v53);
            if ( v27 == nullptr )
              goto LABEL_50;
            v28 = v53;
            v29 = v53 == 0;
LABEL_48:
            if ( v29 )
            {
LABEL_50:
              v25 = -1;
            }
            else
            {
              v26->n = v28 - 1;
              v26->p = v27;
              v25 = *(unsigned __int8 *)v27;
              v26->p = v27 + 1;
            }
          }
LABEL_51:
          ls->current = v25;
$LN75:
          if ( ls->current == del )
            break;
          continue;
      }
      break;
    }
  }
  save(ls, c: ls->current);
  v47 = ls->z;
  v48 = v47->n--;
  if ( v48 != 0 )
  {
    v49 = ls->z;
    v50 = v49->p;
    v51 = *(unsigned __int8 *)v50;
    v49->p = v50 + 1;
  }
  else
  {
    v51 = luaZ_fill(z: ls->z);
  }
  buff = ls->buff;
  ls->current = v51;
  seminfo->ts = luaX_newstring(str: (const char *)buff->buffer + 1, l: buff->n - 2, ls);
}

//------------------------------------------------------------------------------
// Address: 0x1000FF80
// Name: llex
// Source: json
//------------------------------------------------------------------------------
int __usercall llex@<eax>(LexState *ls@<eax>, SemInfo *seminfo)
{
  Zio *z; // eax
  unsigned int v4; // ecx
  Zio *v5; // eax
  const char *p; // edx
  int v7; // ecx
  Zio *v8; // esi
  const char *v9; // eax
  int v10; // ecx
  Zio *v11; // eax
  unsigned int v12; // ecx
  Zio *v13; // eax
  const char *v14; // edx
  int v15; // ecx
  Zio *v16; // esi
  const char *v17; // eax
  int v18; // ecx
  int v19; // eax
  Zio *v20; // eax
  unsigned int v21; // ecx
  Zio *v22; // ecx
  const char *v23; // edx
  int v24; // eax
  Zio *v25; // eax
  unsigned int v26; // ecx
  Zio *v27; // eax
  const char *v28; // edx
  int v29; // ecx
  Zio *v30; // esi
  const char *v31; // eax
  int v32; // ecx
  int v33; // ecx
  int v35; // eax
  Zio *v36; // eax
  unsigned int v37; // ecx
  Zio *v38; // eax
  const char *v39; // edx
  int v40; // ecx
  Zio *v41; // esi
  const char *v42; // eax
  int v43; // ecx
  Zio *v44; // eax
  unsigned int v45; // ecx
  Zio *v46; // eax
  const char *v47; // edx
  int v48; // ecx
  Zio *v49; // esi
  const char *v50; // eax
  int v51; // ecx
  int v52; // ecx
  Zio *v53; // eax
  unsigned int v54; // ecx
  Zio *v55; // eax
  const char *v56; // edx
  int v57; // ecx
  Zio *v58; // esi
  const char *v59; // eax
  int v60; // ecx
  Zio *v61; // eax
  unsigned int v62; // ecx
  Zio *v63; // eax
  const char *v64; // edx
  int v65; // ecx
  Zio *v66; // esi
  const char *v67; // eax
  int v68; // ecx
  int v69; // ecx
  Zio *v70; // eax
  unsigned int v71; // ecx
  Zio *v72; // eax
  const char *v73; // edx
  int v74; // ecx
  Zio *v75; // esi
  const char *v76; // eax
  int v77; // ecx
  Zio *v78; // eax
  unsigned int v79; // ecx
  Zio *v80; // eax
  const char *v81; // edx
  int v82; // ecx
  Zio *v83; // esi
  const char *v84; // eax
  int v85; // ecx
  int v86; // ecx
  Zio *v87; // eax
  unsigned int v88; // ecx
  Zio *v89; // eax
  const char *v90; // edx
  int v91; // ecx
  Zio *v92; // esi
  const char *v93; // eax
  int v94; // ecx
  Zio *v95; // eax
  unsigned int v96; // ecx
  Zio *v97; // eax
  const char *v98; // edx
  int v99; // ecx
  Zio *v100; // esi
  const char *v101; // eax
  int v102; // ecx
  int v103; // ecx
  Zio *v104; // eax
  unsigned int v105; // ecx
  Zio *v106; // eax
  const char *v107; // edx
  int v108; // ecx
  Zio *v109; // esi
  const char *v110; // eax
  int v111; // ecx
  int v112; // eax
  int v113; // eax
  int current; // ebx
  Zio *v115; // eax
  unsigned int v116; // ecx
  Zio *v117; // eax
  const char *v118; // edx
  int v119; // ecx
  Zio *v120; // esi
  const char *v121; // eax
  int v122; // ecx
  int v123; // ecx
  Zio *v124; // eax
  unsigned int v125; // ecx
  Zio *v126; // ecx
  const char *v127; // edx
  int v128; // eax
  TString *v129; // eax
  unsigned __int8 reserved; // cl
  int v131; // [esp+10h] [ebp-Ch] BYREF
  int v132; // [esp+14h] [ebp-8h] BYREF
  int v133; // [esp+18h] [ebp-4h] BYREF

  ls->buff->n = 0;
  while ( 2 )
  {
    switch ( ls->current )
    {
      case 0xFFFFFFFF:
        return 287;
      case 0xA:
      case 0xD:
        inclinenumber(ls);
        continue;
      case 0x22:
      case 0x27:
        read_string(ls, del: ls->current, seminfo);
        return 286;
      case 0x2D:
        z = ls->z;
        v4 = z->n--;
        if ( v4 != 0 )
        {
          v5 = ls->z;
          p = v5->p;
          v7 = *(unsigned __int8 *)p;
          v5->p = p + 1;
        }
        else
        {
          v8 = ls->z;
          v9 = v8->reader(a1: v8->L, a2: v8->data, a3: (unsigned int *)&v133);
          if ( v9 != nullptr && (v10 = v133, v133 != 0) )
          {
            v8->p = v9;
            v8->n = v10 - 1;
            v7 = *(unsigned __int8 *)v9;
            v8->p = v9 + 1;
          }
          else
          {
            v7 = -1;
          }
        }
        ls->current = v7;
        if ( v7 != 45 )
          return 45;
        v11 = ls->z;
        v12 = v11->n--;
        if ( v12 != 0 )
        {
          v13 = ls->z;
          v14 = v13->p;
          v15 = *(unsigned __int8 *)v14;
          v13->p = v14 + 1;
        }
        else
        {
          v16 = ls->z;
          v17 = v16->reader(a1: v16->L, a2: v16->data, a3: (unsigned int *)&v132);
          if ( v17 != nullptr && (v18 = v132, v132 != 0) )
          {
            v16->p = v17;
            v16->n = v18 - 1;
            v15 = *(unsigned __int8 *)v17;
            v16->p = v17 + 1;
          }
          else
          {
            v15 = -1;
          }
        }
        ls->current = v15;
        if ( v15 == 91 && (v19 = skip_sep(ls), ls->buff->n = 0, v19 >= 0) )
        {
          read_long_string(ls, seminfo: nullptr, sep: v19);
          ls->buff->n = 0;
        }
        else if ( ls->current != 10 )
        {
          do
          {
            if ( ls->current == 13 || ls->current == -1 )
              break;
            v20 = ls->z;
            v21 = v20->n--;
            if ( v21 != 0 )
            {
              v22 = ls->z;
              v23 = v22->p;
              v24 = *(unsigned __int8 *)v23;
              v22->p = v23 + 1;
            }
            else
            {
              v24 = luaZ_fill(z: ls->z);
            }
            ls->current = v24;
          }
          while ( v24 != 10 );
        }
        continue;
      case 0x2E:
        save(ls, c: ls->current);
        v104 = ls->z;
        v105 = v104->n--;
        if ( v105 != 0 )
        {
          v106 = ls->z;
          v107 = v106->p;
          v108 = *(unsigned __int8 *)v107;
          v106->p = v107 + 1;
        }
        else
        {
          v109 = ls->z;
          v110 = v109->reader(a1: v109->L, a2: v109->data, a3: (unsigned int *)&v131);
          if ( v110 != nullptr && (v111 = v131, v131 != 0) )
          {
            v109->p = v110;
            v109->n = v111 - 1;
            v108 = *(unsigned __int8 *)v110;
            v109->p = v110 + 1;
          }
          else
          {
            v108 = -1;
          }
        }
        ls->current = v108;
        strchr(string: ".", chr: v108);
        if ( v112 != 0 && check_next(ls) != 0 )
        {
          strchr(string: ".", chr: ls->current);
          if ( v113 != 0 && check_next(ls) != 0 )
            return 279;
          else
            return 278;
        }
        else
        {
          if ( isdigit(c: ls->current) != 0 )
            goto LABEL_115;
          return 46;
        }
      case 0x3C:
        v53 = ls->z;
        v54 = v53->n--;
        if ( v54 != 0 )
        {
          v55 = ls->z;
          v56 = v55->p;
          v57 = *(unsigned __int8 *)v56;
          v55->p = v56 + 1;
        }
        else
        {
          v58 = ls->z;
          v59 = v58->reader(a1: v58->L, a2: v58->data, a3: (unsigned int *)&v131);
          if ( v59 != nullptr && (v60 = v131, v131 != 0) )
          {
            v58->p = v59;
            v58->n = v60 - 1;
            v57 = *(unsigned __int8 *)v59;
            v58->p = v59 + 1;
          }
          else
          {
            v57 = -1;
          }
        }
        ls->current = v57;
        if ( v57 != 61 )
          return 60;
        v61 = ls->z;
        v62 = v61->n--;
        if ( v62 != 0 )
        {
          v63 = ls->z;
          v64 = v63->p;
          v65 = *(unsigned __int8 *)v64;
          v63->p = v64 + 1;
          ls->current = v65;
          return 282;
        }
        else
        {
          v66 = ls->z;
          v67 = v66->reader(a1: v66->L, a2: v66->data, a3: (unsigned int *)&v131);
          if ( v67 != nullptr && (v68 = v131, v131 != 0) )
          {
            v66->p = v67;
            v66->n = v68 - 1;
            v69 = *(unsigned __int8 *)v67;
            v66->p = v67 + 1;
            ls->current = v69;
            return 282;
          }
          else
          {
            ls->current = -1;
            return 282;
          }
        }
      case 0x3D:
        v36 = ls->z;
        v37 = v36->n--;
        if ( v37 != 0 )
        {
          v38 = ls->z;
          v39 = v38->p;
          v40 = *(unsigned __int8 *)v39;
          v38->p = v39 + 1;
        }
        else
        {
          v41 = ls->z;
          v42 = v41->reader(a1: v41->L, a2: v41->data, a3: (unsigned int *)&v131);
          if ( v42 != nullptr && (v43 = v131, v131 != 0) )
          {
            v41->p = v42;
            v41->n = v43 - 1;
            v40 = *(unsigned __int8 *)v42;
            v41->p = v42 + 1;
          }
          else
          {
            v40 = -1;
          }
        }
        ls->current = v40;
        if ( v40 != 61 )
          return 61;
        v44 = ls->z;
        v45 = v44->n--;
        if ( v45 != 0 )
        {
          v46 = ls->z;
          v47 = v46->p;
          v48 = *(unsigned __int8 *)v47;
          v46->p = v47 + 1;
          ls->current = v48;
          return 280;
        }
        else
        {
          v49 = ls->z;
          v50 = v49->reader(a1: v49->L, a2: v49->data, a3: (unsigned int *)&v131);
          if ( v50 != nullptr && (v51 = v131, v131 != 0) )
          {
            v49->p = v50;
            v49->n = v51 - 1;
            v52 = *(unsigned __int8 *)v50;
            v49->p = v50 + 1;
            ls->current = v52;
            return 280;
          }
          else
          {
            ls->current = -1;
            return 280;
          }
        }
      case 0x3E:
        v70 = ls->z;
        v71 = v70->n--;
        if ( v71 != 0 )
        {
          v72 = ls->z;
          v73 = v72->p;
          v74 = *(unsigned __int8 *)v73;
          v72->p = v73 + 1;
        }
        else
        {
          v75 = ls->z;
          v76 = v75->reader(a1: v75->L, a2: v75->data, a3: (unsigned int *)&v131);
          if ( v76 != nullptr && (v77 = v131, v131 != 0) )
          {
            v75->p = v76;
            v75->n = v77 - 1;
            v74 = *(unsigned __int8 *)v76;
            v75->p = v76 + 1;
          }
          else
          {
            v74 = -1;
          }
        }
        ls->current = v74;
        if ( v74 != 61 )
          return 62;
        v78 = ls->z;
        v79 = v78->n--;
        if ( v79 != 0 )
        {
          v80 = ls->z;
          v81 = v80->p;
          v82 = *(unsigned __int8 *)v81;
          v80->p = v81 + 1;
          ls->current = v82;
          return 281;
        }
        else
        {
          v83 = ls->z;
          v84 = v83->reader(a1: v83->L, a2: v83->data, a3: (unsigned int *)&v131);
          if ( v84 != nullptr && (v85 = v131, v131 != 0) )
          {
            v83->p = v84;
            v83->n = v85 - 1;
            v86 = *(unsigned __int8 *)v84;
            v83->p = v84 + 1;
            ls->current = v86;
            return 281;
          }
          else
          {
            ls->current = -1;
            return 281;
          }
        }
      case 0x5B:
        v35 = skip_sep(ls);
        if ( v35 < 0 )
        {
          if ( v35 != -1 )
            luaX_lexerror(ls, msg: "invalid long string delimiter", token: 286);
          return 91;
        }
        else
        {
          read_long_string(ls, seminfo, sep: v35);
          return 286;
        }
      case 0x7E:
        v87 = ls->z;
        v88 = v87->n--;
        if ( v88 != 0 )
        {
          v89 = ls->z;
          v90 = v89->p;
          v91 = *(unsigned __int8 *)v90;
          v89->p = v90 + 1;
        }
        else
        {
          v92 = ls->z;
          v93 = v92->reader(a1: v92->L, a2: v92->data, a3: (unsigned int *)&v131);
          if ( v93 != nullptr && (v94 = v131, v131 != 0) )
          {
            v92->p = v93;
            v92->n = v94 - 1;
            v91 = *(unsigned __int8 *)v93;
            v92->p = v93 + 1;
          }
          else
          {
            v91 = -1;
          }
        }
        ls->current = v91;
        if ( v91 != 61 )
          return 126;
        v95 = ls->z;
        v96 = v95->n--;
        if ( v96 != 0 )
        {
          v97 = ls->z;
          v98 = v97->p;
          v99 = *(unsigned __int8 *)v98;
          v97->p = v98 + 1;
          ls->current = v99;
          return 283;
        }
        else
        {
          v100 = ls->z;
          v101 = v100->reader(a1: v100->L, a2: v100->data, a3: (unsigned int *)&v131);
          if ( v101 != nullptr && (v102 = v131, v131 != 0) )
          {
            v100->p = v101;
            v100->n = v102 - 1;
            v103 = *(unsigned __int8 *)v101;
            v100->p = v101 + 1;
            ls->current = v103;
            return 283;
          }
          else
          {
            ls->current = -1;
            return 283;
          }
        }
      default:
        if ( isspace(c: ls->current) != 0 )
        {
          v25 = ls->z;
          v26 = v25->n--;
          if ( v26 != 0 )
          {
            v27 = ls->z;
            v28 = v27->p;
            v29 = *(unsigned __int8 *)v28;
            v27->p = v28 + 1;
            ls->current = v29;
          }
          else
          {
            v30 = ls->z;
            v31 = v30->reader(a1: v30->L, a2: v30->data, a3: (unsigned int *)&v131);
            if ( v31 != nullptr && (v32 = v131, v131 != 0) )
            {
              v30->p = v31;
              v30->n = v32 - 1;
              v33 = *(unsigned __int8 *)v31;
              v30->p = v31 + 1;
              ls->current = v33;
            }
            else
            {
              ls->current = -1;
            }
          }
          continue;
        }
        if ( isdigit(c: ls->current) != 0 )
        {
LABEL_115:
          read_numeral(ls, seminfo);
          return 284;
        }
        else if ( isalpha(c: ls->current) != 0 || (current = ls->current, ls->current == 95) )
        {
          do
          {
            save(ls, c: ls->current);
            v124 = ls->z;
            v125 = v124->n--;
            if ( v125 != 0 )
            {
              v126 = ls->z;
              v127 = v126->p;
              v128 = *(unsigned __int8 *)v127;
              v126->p = v127 + 1;
            }
            else
            {
              v128 = luaZ_fill(z: ls->z);
            }
            ls->current = v128;
          }
          while ( isalnum(c: v128) != 0 || ls->current == 95 );
          v129 = luaX_newstring(str: ls->buff->buffer, l: ls->buff->n, ls);
          reserved = v129->tsv.reserved;
          if ( reserved != 0 )
          {
            return reserved + 256;
          }
          else
          {
            seminfo->ts = v129;
            return 285;
          }
        }
        else
        {
          v115 = ls->z;
          v116 = v115->n--;
          if ( v116 != 0 )
          {
            v117 = ls->z;
            v118 = v117->p;
            v119 = *(unsigned __int8 *)v118;
            v117->p = v118 + 1;
            ls->current = v119;
            return current;
          }
          else
          {
            v120 = ls->z;
            v121 = v120->reader(a1: v120->L, a2: v120->data, a3: (unsigned int *)&v131);
            if ( v121 != nullptr && (v122 = v131, v131 != 0) )
            {
              v120->p = v121;
              v120->n = v122 - 1;
              v123 = *(unsigned __int8 *)v121;
              v120->p = v121 + 1;
              ls->current = v123;
              return current;
            }
            else
            {
              ls->current = -1;
              return current;
            }
          }
        }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010800
// Name: _luaX_next
// Source: json
//------------------------------------------------------------------------------
void __usercall luaX_next(LexState *ls@<esi>)
{
  ls->lastline = ls->linenumber;
  if ( ls->lookahead.token == 287 )
  {
    ls->t.token = llex(ls, seminfo: &ls->t.seminfo);
  }
  else
  {
    ls->t = ls->lookahead;
    ls->lookahead.token = 287;
  }
}
