// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/llex.c
// Functions: 18
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00484B50
// Name: save
// Source: json
//------------------------------------------------------------------------------
void __cdecl save(LexState *ls, char c)
{
  Mbuffer *buff; // esi
  unsigned int buffsize; // eax
  unsigned int v4; // eax
  int v5; // edi
  char *v6; // eax

  buff = ls->buff;
  buffsize = buff->buffsize;
  if ( buff->n + 1 > buffsize )
  {
    if ( buffsize >= 0x7FFFFFFE )
      luaX_lexerror(ls, msg: "lexical element too long", token: 0);
    v4 = buff->buffsize;
    v5 = 2 * v4;
    if ( 2 * v4 + 1 > 0xFFFFFFFD )
      luaM_toobig(L: ls->L);
    v6 = (char *)luaM_realloc_(L: ls->L, block: buff->buffer, osize: v4, nsize: 2 * v4);
    buff->buffsize = v5;
    buff->buffer = v6;
  }
  buff->buffer[buff->n++] = c;
}

//------------------------------------------------------------------------------
// Address: 0x00484BD0
// Name: void luaX_init(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaX_init(lua_State *L)
{
  int i; // ebx
  GCObject *v2; // eax

  for ( i = 0; i < 21; v2->ts.tsv.reserved = i )
  {
    v2 = luaS_newlstr(L, str: (char *)luaX_tokens[i], l: strlen(luaX_tokens[i]));
    v2->gch.marked |= 0x20u;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484C20
// Name: char const __near * luaX_token2str(struct LexState __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl luaX_token2str(LexState *ls, int token)
{
  if ( token >= 257 )
    return *((const char **)&base_funcs[16].func + token);
  if ( iscntrl(c: token) != 0 )
    return luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "char(%d)", token);
  return luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%c", token);
}

//------------------------------------------------------------------------------
// Address: 0x00484C80
// Name: txtToken
// Source: json
//------------------------------------------------------------------------------
char *__usercall txtToken@<eax>(LexState *ls@<edi>, int token@<esi>)
{
  if ( token < 284 || token > 286 )
  {
    if ( token >= 257 )
    {
      return *((char **)&base_funcs[16].func + token);
    }
    else if ( iscntrl(c: token) != 0 )
    {
      return (char *)luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "char(%d)", token);
    }
    else
    {
      return (char *)luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%c", token);
    }
  }
  else
  {
    save(ls, c: 0);
    return ls->buff->buffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484CF0
// Name: void luaX_lexerror(struct LexState __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaX_lexerror(LexState *ls, const char *msg, int token)
{
  const char *v3; // ebx
  char *v4; // eax
  char buff[80]; // [esp+Ch] [ebp-50h] BYREF

  luaO_chunkid(out: buff, source: (char *)&ls->source[1], bufflen: 0x50u);
  v3 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", buff, ls->linenumber, msg);
  if ( token != 0 )
  {
    v4 = txtToken(ls, token);
    luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v3, v4);
  }
  luaD_throw(L: ls->L, errcode: 3);
}

//------------------------------------------------------------------------------
// Address: 0x00484D70
// Name: void luaX_syntaxerror(struct LexState __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaX_syntaxerror(LexState *ls, const char *msg)
{
  luaX_lexerror(ls, msg, token: ls->t.token);
}

//------------------------------------------------------------------------------
// Address: 0x00484D90
// Name: union TString __near * luaX_newstring(struct LexState __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl luaX_newstring(LexState *ls, char *str, unsigned int l)
{
  lua_State *v3; // esi
  GCObject *v4; // edi
  Node *v5; // eax

  v3 = ls->L;
  v4 = luaS_newlstr(L: v3, str, l);
  v5 = luaH_setstr(L: v3, t: (GCObject *)ls->fs->h, key: (TString *)v4);
  if ( v5->i_val.tt == 0 )
  {
    v5->i_val.value.b = 1;
    v5->i_val.tt = 1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00484DE0
// Name: inclinenumber
// Source: json
//------------------------------------------------------------------------------
void __usercall inclinenumber(LexState *ls@<esi>)
{
  Zio *z; // eax
  unsigned int n; // ecx
  int current; // edi
  Zio *v4; // ecx
  const char *p; // edx
  int v6; // eax
  Zio *v7; // eax
  unsigned int v8; // ecx
  Zio *v9; // ecx
  const char *v10; // edx
  int v11; // eax

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
    v6 = luaZ_fill(z: ls->z);
  }
  ls->current = v6;
  if ( (v6 == 10 || v6 == 13) && v6 != current )
  {
    v7 = ls->z;
    v8 = v7->n--;
    if ( v8 != 0 )
    {
      v9 = ls->z;
      v10 = v9->p;
      v11 = *(unsigned __int8 *)v10;
      v9->p = v10 + 1;
    }
    else
    {
      v11 = luaZ_fill(z: ls->z);
    }
    ls->current = v11;
  }
  if ( ++ls->linenumber >= 2147483645 )
    luaX_lexerror(ls, msg: "chunk has too many lines", token: ls->t.token);
}

//------------------------------------------------------------------------------
// Address: 0x00484E70
// Name: void luaX_setinput(struct lua_State __near *,struct LexState __near *,struct Zio __near *,union TString __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaX_setinput(lua_State *L, LexState *ls, Zio *z, TString *source)
{
  Mbuffer *buff; // eax
  Zio *v5; // eax
  unsigned int v6; // ecx
  Zio *v7; // eax
  const char *p; // ecx
  int v9; // edx

  ls->z = z;
  ls->linenumber = 1;
  ls->lastline = 1;
  buff = ls->buff;
  ls->decpoint = 46;
  ls->L = L;
  ls->lookahead.token = 287;
  ls->fs = nullptr;
  ls->source = source;
  ls->buff->buffer = (char *)luaM_realloc_(L, block: buff->buffer, osize: buff->buffsize, nsize: 0x20u);
  ls->buff->buffsize = 32;
  v5 = ls->z;
  v6 = v5->n--;
  v7 = ls->z;
  if ( v6 != 0 )
  {
    p = v7->p;
    v9 = *(unsigned __int8 *)p;
    v7->p = p + 1;
    ls->current = v9;
  }
  else
  {
    ls->current = luaZ_fill(z: ls->z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484F00
// Name: check_next
// Source: json
//------------------------------------------------------------------------------
void __usercall check_next(LexState *ls@<esi>, char *set@<ecx>)
{
  int v2; // eax
  Zio *z; // eax
  unsigned int v4; // ecx
  Zio *v5; // ecx
  const char *p; // edx
  int v7; // eax

  strchr(string: (unsigned __int8 *)set, chr: ls->current);
  if ( v2 != 0 )
  {
    save(ls, c: ls->current);
    z = ls->z;
    v4 = z->n--;
    if ( v4 != 0 )
    {
      v5 = ls->z;
      p = v5->p;
      v7 = *(unsigned __int8 *)p;
      v5->p = p + 1;
      ls->current = v7;
    }
    else
    {
      ls->current = luaZ_fill(z: ls->z);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484F60
// Name: trydecpoint
// Source: json
//------------------------------------------------------------------------------
void __usercall trydecpoint(LexState *ls@<esi>, SemInfo *seminfo)
{
  lconv *v2; // eax
  char decpoint; // bl
  char v4; // dl
  Mbuffer *buff; // ecx
  unsigned int n; // eax
  char *buffer; // ecx
  Mbuffer *v8; // ecx
  unsigned int v9; // eax
  char v10; // dl
  char *v11; // ecx
  const char *v12; // edi
  char out[80]; // [esp+4h] [ebp-50h] BYREF

  v2 = localeconv();
  decpoint = ls->decpoint;
  if ( v2 != nullptr )
    v4 = *v2->decimal_point;
  else
    v4 = 46;
  buff = ls->buff;
  ls->decpoint = v4;
  n = buff->n;
  buffer = buff->buffer;
  while ( n != 0 )
  {
    if ( buffer[--n] == decpoint )
      buffer[n] = v4;
  }
  if ( !luaO_str2d(s: ls->buff->buffer, result: &seminfo->r) )
  {
    v8 = ls->buff;
    v9 = v8->n;
    v10 = ls->decpoint;
    v11 = v8->buffer;
    while ( v9 != 0 )
    {
      if ( v11[--v9] == v10 )
        v11[v9] = 46;
    }
    luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
    v12 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "malformed number");
    save(ls, c: 0);
    luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v12, ls->buff->buffer);
    luaD_throw(L: ls->L, errcode: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485040
// Name: read_numeral
// Source: json
//------------------------------------------------------------------------------
void __usercall read_numeral(LexState *ls@<eax>, SemInfo *seminfo)
{
  Mbuffer *buff; // edi
  unsigned int n; // ecx
  unsigned int buffsize; // eax
  unsigned int v6; // eax
  int v7; // ebx
  Zio *z; // eax
  unsigned int v9; // ecx
  Zio *v10; // ecx
  const char *p; // edx
  int v12; // eax
  int v13; // eax
  Zio *v14; // eax
  unsigned int v15; // ecx
  Zio *v16; // ecx
  const char *v17; // edx
  int v18; // eax
  Mbuffer *v19; // edi
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // eax
  int v23; // ebx
  Zio *v24; // eax
  unsigned int v25; // ecx
  Zio *v26; // ecx
  const char *v27; // edx
  int v28; // eax
  Mbuffer *v29; // ecx
  unsigned int v30; // eax
  char decpoint; // dl
  char *buffer; // ecx
  char out[80]; // [esp+Ch] [ebp-54h] BYREF
  int current; // [esp+5Ch] [ebp-4h]

  do
  {
    buff = ls->buff;
    n = buff->n;
    current = ls->current;
    buffsize = buff->buffsize;
    if ( n + 1 > buffsize )
    {
      if ( buffsize >= 0x7FFFFFFE )
      {
        luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
        luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "lexical element too long");
        luaD_throw(L: ls->L, errcode: 3);
      }
      v6 = buff->buffsize;
      v7 = 2 * v6;
      if ( 2 * v6 + 1 > 0xFFFFFFFD )
        luaM_toobig(L: ls->L);
      buff->buffer = (char *)luaM_realloc_(L: ls->L, block: buff->buffer, osize: v6, nsize: 2 * v6);
      buff->buffsize = v7;
    }
    buff->buffer[buff->n++] = current;
    z = ls->z;
    v9 = z->n--;
    if ( v9 != 0 )
    {
      v10 = ls->z;
      p = v10->p;
      v12 = *(unsigned __int8 *)p;
      v10->p = p + 1;
    }
    else
    {
      v12 = luaZ_fill(z: ls->z);
    }
    ls->current = v12;
  }
  while ( isdigit(c: v12) != 0 || ls->current == 46 );
  strchr(string: "Ee", chr: ls->current);
  if ( v13 != 0 )
  {
    save(ls, c: ls->current);
    v14 = ls->z;
    v15 = v14->n--;
    if ( v15 != 0 )
    {
      v16 = ls->z;
      v17 = v16->p;
      v18 = *(unsigned __int8 *)v17;
      v16->p = v17 + 1;
    }
    else
    {
      v18 = luaZ_fill(z: ls->z);
    }
    ls->current = v18;
    check_next(ls, set: "+-");
  }
  while ( isalnum(c: ls->current) != 0 || ls->current == 95 )
  {
    v19 = ls->buff;
    v20 = v19->buffsize;
    v21 = v19->n + 1;
    current = ls->current;
    if ( v21 > v20 )
    {
      if ( v20 >= 0x7FFFFFFE )
      {
        luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
        luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "lexical element too long");
        luaD_throw(L: ls->L, errcode: 3);
      }
      v22 = v19->buffsize;
      v23 = 2 * v22;
      if ( 2 * v22 + 1 > 0xFFFFFFFD )
        luaM_toobig(L: ls->L);
      v19->buffer = (char *)luaM_realloc_(L: ls->L, block: v19->buffer, osize: v22, nsize: 2 * v22);
      v19->buffsize = v23;
    }
    v19->buffer[v19->n++] = current;
    v24 = ls->z;
    v25 = v24->n--;
    if ( v25 != 0 )
    {
      v26 = ls->z;
      v27 = v26->p;
      v28 = *(unsigned __int8 *)v27;
      v26->p = v27 + 1;
      ls->current = v28;
    }
    else
    {
      ls->current = luaZ_fill(z: ls->z);
    }
  }
  save(ls, c: 0);
  v29 = ls->buff;
  v30 = v29->n;
  decpoint = ls->decpoint;
  buffer = v29->buffer;
  while ( v30 != 0 )
  {
    if ( buffer[--v30] == 46 )
      buffer[v30] = decpoint;
  }
  if ( !luaO_str2d(s: ls->buff->buffer, result: &seminfo->r) )
    trydecpoint(ls, seminfo);
}

//------------------------------------------------------------------------------
// Address: 0x004852C0
// Name: skip_sep
// Source: json
//------------------------------------------------------------------------------
int __usercall skip_sep@<eax>(LexState *ls@<esi>)
{
  int current; // edi
  Zio *z; // eax
  unsigned int v3; // ecx
  Zio *v4; // ecx
  const char *p; // edx
  int v6; // eax
  Mbuffer *buff; // edi
  unsigned int buffsize; // eax
  unsigned int v9; // edx
  unsigned int v10; // eax
  int v11; // ebx
  Zio *v12; // eax
  unsigned int v13; // ecx
  Zio *v14; // ecx
  const char *v15; // edx
  int v16; // eax
  char v18; // [esp-4h] [ebp-64h]
  char out[80]; // [esp+4h] [ebp-5Ch] BYREF
  int v20; // [esp+54h] [ebp-Ch]
  int v21; // [esp+58h] [ebp-8h]
  int count; // [esp+5Ch] [ebp-4h]

  current = ls->current;
  v18 = ls->current;
  count = 0;
  v20 = current;
  save(ls, c: v18);
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
    v6 = luaZ_fill(z: ls->z);
  }
  ls->current = v6;
  if ( v6 == 61 )
  {
    do
    {
      buff = ls->buff;
      buffsize = buff->buffsize;
      v9 = buff->n + 1;
      v21 = ls->current;
      if ( v9 > buffsize )
      {
        if ( buffsize >= 0x7FFFFFFE )
        {
          luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
          luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "lexical element too long");
          luaD_throw(L: ls->L, errcode: 3);
        }
        v10 = buff->buffsize;
        v11 = 2 * v10;
        if ( 2 * v10 + 1 > 0xFFFFFFFD )
          luaM_toobig(L: ls->L);
        buff->buffer = (char *)luaM_realloc_(L: ls->L, block: buff->buffer, osize: v10, nsize: 2 * v10);
        buff->buffsize = v11;
      }
      buff->buffer[buff->n++] = v21;
      v12 = ls->z;
      v13 = v12->n--;
      if ( v13 != 0 )
      {
        v14 = ls->z;
        v15 = v14->p;
        v16 = *(unsigned __int8 *)v15;
        v14->p = v15 + 1;
      }
      else
      {
        v16 = luaZ_fill(z: ls->z);
      }
      ++count;
      ls->current = v16;
    }
    while ( v16 == 61 );
    current = v20;
  }
  if ( ls->current == current )
    return count;
  else
    return -1 - count;
}

//------------------------------------------------------------------------------
// Address: 0x00485400
// Name: read_long_string
// Source: json
//------------------------------------------------------------------------------
void __usercall read_long_string(LexState *ls@<eax>, SemInfo *seminfo, int sep)
{
  Zio *z; // eax
  unsigned int v5; // ecx
  Zio *v6; // ecx
  const char *p; // edx
  int v8; // eax
  int current; // ecx
  int v10; // eax
  const char *v11; // edi
  const char *v12; // eax
  Zio *v13; // eax
  unsigned int v14; // ecx
  Zio *v15; // ecx
  const char *v16; // edx
  int v17; // eax
  const char *v18; // edi
  const char *v19; // eax
  Zio *v20; // eax
  unsigned int v21; // ecx
  Zio *v22; // ecx
  const char *v23; // edx
  int v24; // eax
  Mbuffer *buff; // edi
  unsigned int buffsize; // eax
  unsigned int v27; // eax
  int v28; // ebx
  char *v29; // eax
  Zio *v30; // eax
  unsigned int v31; // ecx
  Zio *v32; // ecx
  const char *v33; // edx
  int v34; // eax
  lua_State *L; // edi
  GCObject *v36; // ebx
  Node *v37; // eax
  char out[80]; // [esp+Ch] [ebp-54h] BYREF
  int v39; // [esp+5Ch] [ebp-4h]

  save(ls, c: ls->current);
  z = ls->z;
  v5 = z->n--;
  if ( v5 != 0 )
  {
    v6 = ls->z;
    p = v6->p;
    v8 = *(unsigned __int8 *)p;
    v6->p = p + 1;
  }
  else
  {
    v8 = luaZ_fill(z: ls->z);
  }
  ls->current = v8;
  if ( v8 == 10 || v8 == 13 )
    inclinenumber(ls);
  while ( 2 )
  {
    current = ls->current;
    v10 = ls->current + 1;
    v39 = ls->current;
    switch ( v10 )
    {
      case 0:
        v11 = "unfinished long string";
        if ( seminfo == nullptr )
          v11 = "unfinished long comment";
        luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
        v12 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, v11);
        luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v12, "<eof>");
        luaD_throw(L: ls->L, errcode: 3);
      case 11:
      case 14:
        save(ls, c: 10);
        inclinenumber(ls);
        if ( seminfo == nullptr )
          ls->buff->n = 0;
        continue;
      case 92:
        if ( skip_sep(ls) == sep )
        {
          save(ls, c: ls->current);
          v13 = ls->z;
          v14 = v13->n--;
          if ( v14 != 0 )
          {
            v15 = ls->z;
            v16 = v15->p;
            v17 = *(unsigned __int8 *)v16;
            v15->p = v16 + 1;
          }
          else
          {
            v17 = luaZ_fill(z: ls->z);
          }
          ls->current = v17;
          if ( sep == 0 )
          {
            luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
            v18 = luaO_pushfstring(
                    L: (lua_TValue *)ls->L,
                    fmt: "%s:%d: %s",
                    out,
                    ls->linenumber,
                    "nesting of [[...]] is deprecated");
            if ( iscntrl(c: 91) != 0 )
              v19 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "char(%d)", 91);
            else
              v19 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%c", 91);
            luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v18, v19);
            luaD_throw(L: ls->L, errcode: 3);
          }
        }
        continue;
      case 94:
        if ( skip_sep(ls) != sep )
          continue;
        save(ls, c: ls->current);
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
        if ( seminfo != nullptr )
        {
          L = ls->L;
          v36 = luaS_newlstr(L, str: &ls->buff->buffer[sep + 2], l: ls->buff->n - 2 * sep - 4);
          v37 = luaH_setstr(L, t: (GCObject *)ls->fs->h, key: (TString *)v36);
          if ( v37->i_val.tt == 0 )
          {
            v37->i_val.value.b = 1;
            v37->i_val.tt = 1;
          }
          seminfo->ts = (TString *)v36;
        }
        return;
      default:
        if ( seminfo != nullptr )
        {
          buff = ls->buff;
          buffsize = buff->buffsize;
          if ( buff->n + 1 > buffsize )
          {
            if ( buffsize >= 0x7FFFFFFE )
            {
              luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
              luaO_pushfstring(
                L: (lua_TValue *)ls->L,
                fmt: "%s:%d: %s",
                out,
                ls->linenumber,
                "lexical element too long");
              luaD_throw(L: ls->L, errcode: 3);
            }
            v27 = buff->buffsize;
            v28 = 2 * v27;
            if ( 2 * v27 + 1 > 0xFFFFFFFD )
              luaM_toobig(L: ls->L);
            v29 = (char *)luaM_realloc_(L: ls->L, block: buff->buffer, osize: v27, nsize: 2 * v27);
            LOBYTE(current) = v39;
            buff->buffer = v29;
            buff->buffsize = v28;
          }
          buff->buffer[buff->n++] = current;
        }
        v30 = ls->z;
        v31 = v30->n--;
        if ( v31 != 0 )
        {
          v32 = ls->z;
          v33 = v32->p;
          v34 = *(unsigned __int8 *)v33;
          v32->p = v33 + 1;
          ls->current = v34;
        }
        else
        {
          ls->current = luaZ_fill(z: ls->z);
        }
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004857B0
// Name: read_string
// Source: json
//------------------------------------------------------------------------------
void __usercall read_string(LexState *ls@<eax>, int del, SemInfo *seminfo)
{
  Zio *z; // eax
  unsigned int v5; // ecx
  Zio *v6; // ecx
  const char *p; // edx
  int v8; // eax
  int current; // eax
  int v10; // ecx
  const char *v11; // eax
  const char *v12; // edi
  Zio *v13; // eax
  unsigned int v14; // ecx
  Zio *v15; // ecx
  const char *v16; // edx
  int v17; // eax
  int v18; // ebx
  int v19; // edi
  Zio *v20; // eax
  unsigned int v21; // ecx
  Zio *v22; // ecx
  const char *v23; // edx
  int v24; // eax
  Mbuffer *buff; // edi
  unsigned int buffsize; // ecx
  unsigned int v27; // eax
  int v28; // ebx
  Zio *v29; // eax
  unsigned int v30; // ecx
  Zio *v31; // ecx
  const char *v32; // edx
  int v33; // eax
  Zio *v34; // eax
  unsigned int v35; // ecx
  Zio *v36; // ecx
  const char *v37; // edx
  int v38; // eax
  Mbuffer *v39; // ecx
  lua_State *L; // edi
  GCObject *v41; // ebx
  Node *v42; // eax
  char out[80]; // [esp+Ch] [ebp-54h] BYREF
  int v44; // [esp+5Ch] [ebp-4h]

  save(ls, c: ls->current);
  z = ls->z;
  v5 = z->n--;
  if ( v5 != 0 )
  {
    v6 = ls->z;
    p = v6->p;
    v8 = *(unsigned __int8 *)p;
    v6->p = p + 1;
  }
  else
  {
    v8 = luaZ_fill(z: ls->z);
  }
  ls->current = v8;
  while ( ls->current != del )
  {
    current = ls->current;
    v10 = ls->current + 1;
    v44 = ls->current;
    switch ( v10 )
    {
      case 0:
        luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
        v11 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "unfinished string");
        luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v11, "<eof>");
        luaD_throw(L: ls->L, errcode: 3);
      case 11:
      case 14:
        luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
        v12 = luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "unfinished string");
        save(ls, c: 0);
        luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v12, ls->buff->buffer);
        luaD_throw(L: ls->L, errcode: 3);
      case 93:
        v13 = ls->z;
        v14 = v13->n--;
        if ( v14 != 0 )
        {
          v15 = ls->z;
          v16 = v15->p;
          v17 = *(unsigned __int8 *)v16;
          v15->p = v16 + 1;
        }
        else
        {
          v17 = luaZ_fill(z: ls->z);
        }
        ls->current = v17;
        switch ( v17 )
        {
          case -1:
            continue;
          case 10:
          case 13:
            save(ls, c: 10);
            inclinenumber(ls);
            continue;
          case 97:
            save(ls, c: 7);
            goto LABEL_38;
          case 98:
            save(ls, c: 8);
            goto LABEL_38;
          case 102:
            save(ls, c: 12);
            goto LABEL_38;
          case 110:
            save(ls, c: 10);
            goto LABEL_38;
          case 114:
            save(ls, c: 13);
            goto LABEL_38;
          case 116:
            save(ls, c: 9);
            goto LABEL_38;
          case 118:
            save(ls, c: 11);
            goto LABEL_38;
          default:
            if ( isdigit(c: v17) == 0 )
            {
              save(ls, c: ls->current);
              goto LABEL_38;
            }
            v18 = 0;
            v19 = 0;
            do
            {
              v20 = ls->z;
              v19 = ls->current + 10 * v19 - 48;
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
              ++v18;
              ls->current = v24;
            }
            while ( v18 < 3 && isdigit(c: v24) != 0 );
            if ( v19 > 255 )
              luaX_lexerror(ls, msg: "escape sequence too large", token: 286);
            save(ls, c: v19);
            break;
        }
        break;
      default:
        buff = ls->buff;
        buffsize = buff->buffsize;
        if ( buff->n + 1 > buffsize )
        {
          if ( buffsize >= 0x7FFFFFFE )
          {
            luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
            luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s:%d: %s", out, ls->linenumber, "lexical element too long");
            luaD_throw(L: ls->L, errcode: 3);
          }
          v27 = buff->buffsize;
          v28 = 2 * v27;
          if ( 2 * v27 + 1 > 0xFFFFFFFD )
            luaM_toobig(L: ls->L);
          buff->buffer = (char *)luaM_realloc_(L: ls->L, block: buff->buffer, osize: v27, nsize: 2 * v27);
          LOBYTE(current) = v44;
          buff->buffsize = v28;
        }
        buff->buffer[buff->n++] = current;
LABEL_38:
        v29 = ls->z;
        v30 = v29->n--;
        if ( v30 != 0 )
        {
          v31 = ls->z;
          v32 = v31->p;
          v33 = *(unsigned __int8 *)v32;
          v31->p = v32 + 1;
        }
        else
        {
          v33 = luaZ_fill(z: ls->z);
        }
        ls->current = v33;
        break;
    }
  }
  save(ls, c: ls->current);
  v34 = ls->z;
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
    v38 = luaZ_fill(z: ls->z);
  }
  v39 = ls->buff;
  L = ls->L;
  ls->current = v38;
  v41 = luaS_newlstr(L, str: v39->buffer + 1, l: v39->n - 2);
  v42 = luaH_setstr(L, t: (GCObject *)ls->fs->h, key: (TString *)v41);
  if ( v42->i_val.tt == 0 )
  {
    v42->i_val.value.b = 1;
    v42->i_val.tt = 1;
  }
  seminfo->ts = (TString *)v41;
}

//------------------------------------------------------------------------------
// Address: 0x00485CC0
// Name: llex
// Source: json
//------------------------------------------------------------------------------
int __usercall llex@<eax>(LexState *ls@<eax>, SemInfo *seminfo)
{
  Zio *z; // eax
  unsigned int v4; // ecx
  Zio *v5; // ecx
  const char *p; // edx
  int v7; // eax
  Zio *v8; // eax
  unsigned int v9; // ecx
  Zio *v10; // ecx
  const char *v11; // edx
  int v12; // eax
  int v13; // eax
  Zio *v14; // eax
  unsigned int v15; // ecx
  Zio *v16; // ecx
  const char *v17; // edx
  int v18; // eax
  Zio *v19; // eax
  unsigned int v20; // ecx
  Zio *v21; // ecx
  const char *v22; // edx
  int v23; // eax
  int v25; // eax
  const char *v26; // edi
  Zio *v27; // eax
  unsigned int v28; // ecx
  Zio *v29; // ecx
  const char *v30; // edx
  int v31; // eax
  Zio *v32; // eax
  unsigned int v33; // ecx
  Zio *v34; // ecx
  const char *v35; // edx
  int v36; // eax
  Zio *v37; // eax
  unsigned int v38; // ecx
  Zio *v39; // ecx
  const char *v40; // edx
  int v41; // eax
  Zio *v42; // eax
  unsigned int v43; // ecx
  Zio *v44; // ecx
  const char *v45; // edx
  int v46; // eax
  Zio *v47; // eax
  unsigned int v48; // ecx
  Zio *v49; // ecx
  const char *v50; // edx
  int v51; // eax
  Zio *v52; // eax
  unsigned int v53; // ecx
  Zio *v54; // ecx
  const char *v55; // edx
  int v56; // eax
  Zio *v57; // eax
  unsigned int v58; // ecx
  Zio *v59; // ecx
  const char *v60; // edx
  int v61; // eax
  Zio *v62; // eax
  unsigned int v63; // ecx
  Zio *v64; // ecx
  const char *v65; // edx
  int v66; // eax
  Zio *v67; // eax
  unsigned int v68; // ecx
  Zio *v69; // ecx
  const char *v70; // edx
  int v71; // eax
  int v72; // eax
  Zio *v73; // eax
  unsigned int v74; // ecx
  Zio *v75; // ecx
  const char *v76; // edx
  int v77; // eax
  int v78; // eax
  Zio *v79; // eax
  unsigned int v80; // ecx
  Zio *v81; // ecx
  const char *v82; // edx
  int v83; // eax
  int v84; // edi
  Zio *v85; // eax
  unsigned int v86; // ecx
  Zio *v87; // ecx
  const char *v88; // edx
  int v89; // eax
  Zio *v90; // eax
  unsigned int v91; // ecx
  Zio *v92; // ecx
  const char *v93; // edx
  int v94; // eax
  GCObject *v95; // eax
  unsigned __int8 reserved; // cl
  int current; // [esp-4h] [ebp-60h]
  char out[80]; // [esp+Ch] [ebp-50h] BYREF

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
          v7 = luaZ_fill(z: ls->z);
        }
        ls->current = v7;
        if ( v7 != 45 )
          return 45;
        v8 = ls->z;
        v9 = v8->n--;
        if ( v9 != 0 )
        {
          v10 = ls->z;
          v11 = v10->p;
          v12 = *(unsigned __int8 *)v11;
          v10->p = v11 + 1;
        }
        else
        {
          v12 = luaZ_fill(z: ls->z);
        }
        ls->current = v12;
        if ( v12 == 91 && (v13 = skip_sep(ls), ls->buff->n = 0, v13 >= 0) )
        {
          read_long_string(ls, seminfo: nullptr, sep: v13);
          ls->buff->n = 0;
        }
        else if ( ls->current != 10 )
        {
          do
          {
            if ( ls->current == 13 || ls->current == -1 )
              break;
            v14 = ls->z;
            v15 = v14->n--;
            if ( v15 != 0 )
            {
              v16 = ls->z;
              v17 = v16->p;
              v18 = *(unsigned __int8 *)v17;
              v16->p = v17 + 1;
            }
            else
            {
              v18 = luaZ_fill(z: ls->z);
            }
            ls->current = v18;
          }
          while ( v18 != 10 );
        }
        continue;
      case 0x2E:
        save(ls, c: ls->current);
        v67 = ls->z;
        v68 = v67->n--;
        if ( v68 != 0 )
        {
          v69 = ls->z;
          v70 = v69->p;
          v71 = *(unsigned __int8 *)v70;
          v69->p = v70 + 1;
        }
        else
        {
          v71 = luaZ_fill(z: ls->z);
        }
        ls->current = v71;
        strchr(string: ".", chr: v71);
        current = ls->current;
        if ( v72 != 0 )
        {
          save(ls, c: current);
          v73 = ls->z;
          v74 = v73->n--;
          if ( v74 != 0 )
          {
            v75 = ls->z;
            v76 = v75->p;
            v77 = *(unsigned __int8 *)v76;
            v75->p = v76 + 1;
          }
          else
          {
            v77 = luaZ_fill(z: ls->z);
          }
          ls->current = v77;
          strchr(string: ".", chr: v77);
          if ( v78 != 0 )
          {
            save(ls, c: ls->current);
            v79 = ls->z;
            v80 = v79->n--;
            if ( v80 != 0 )
            {
              v81 = ls->z;
              v82 = v81->p;
              v83 = *(unsigned __int8 *)v82;
              v81->p = v82 + 1;
              ls->current = v83;
            }
            else
            {
              ls->current = luaZ_fill(z: ls->z);
            }
            return 279;
          }
          else
          {
            return 278;
          }
        }
        else
        {
          if ( isdigit(c: current) != 0 )
            goto LABEL_87;
          return 46;
        }
      case 0x3C:
        v37 = ls->z;
        v38 = v37->n--;
        if ( v38 != 0 )
        {
          v39 = ls->z;
          v40 = v39->p;
          v41 = *(unsigned __int8 *)v40;
          v39->p = v40 + 1;
        }
        else
        {
          v41 = luaZ_fill(z: ls->z);
        }
        ls->current = v41;
        if ( v41 != 61 )
          return 60;
        v42 = ls->z;
        v43 = v42->n--;
        if ( v43 != 0 )
        {
          v44 = ls->z;
          v45 = v44->p;
          v46 = *(unsigned __int8 *)v45;
          v44->p = v45 + 1;
          ls->current = v46;
        }
        else
        {
          ls->current = luaZ_fill(z: ls->z);
        }
        return 282;
      case 0x3D:
        v27 = ls->z;
        v28 = v27->n--;
        if ( v28 != 0 )
        {
          v29 = ls->z;
          v30 = v29->p;
          v31 = *(unsigned __int8 *)v30;
          v29->p = v30 + 1;
        }
        else
        {
          v31 = luaZ_fill(z: ls->z);
        }
        ls->current = v31;
        if ( v31 != 61 )
          return 61;
        v32 = ls->z;
        v33 = v32->n--;
        if ( v33 != 0 )
        {
          v34 = ls->z;
          v35 = v34->p;
          v36 = *(unsigned __int8 *)v35;
          v34->p = v35 + 1;
          ls->current = v36;
        }
        else
        {
          ls->current = luaZ_fill(z: ls->z);
        }
        return 280;
      case 0x3E:
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
        ls->current = v51;
        if ( v51 != 61 )
          return 62;
        v52 = ls->z;
        v53 = v52->n--;
        if ( v53 != 0 )
        {
          v54 = ls->z;
          v55 = v54->p;
          v56 = *(unsigned __int8 *)v55;
          v54->p = v55 + 1;
          ls->current = v56;
        }
        else
        {
          ls->current = luaZ_fill(z: ls->z);
        }
        return 281;
      case 0x5B:
        v25 = skip_sep(ls);
        if ( v25 < 0 )
        {
          if ( v25 != -1 )
          {
            luaO_chunkid(out, source: (char *)&ls->source[1], bufflen: 0x50u);
            v26 = luaO_pushfstring(
                    L: (lua_TValue *)ls->L,
                    fmt: "%s:%d: %s",
                    out,
                    ls->linenumber,
                    "invalid long string delimiter");
            save(ls, c: 0);
            luaO_pushfstring(L: (lua_TValue *)ls->L, fmt: "%s near '%s'", v26, ls->buff->buffer);
            luaD_throw(L: ls->L, errcode: 3);
          }
          return 91;
        }
        else
        {
          read_long_string(ls, seminfo, sep: v25);
          return 286;
        }
      case 0x7E:
        v57 = ls->z;
        v58 = v57->n--;
        if ( v58 != 0 )
        {
          v59 = ls->z;
          v60 = v59->p;
          v61 = *(unsigned __int8 *)v60;
          v59->p = v60 + 1;
        }
        else
        {
          v61 = luaZ_fill(z: ls->z);
        }
        ls->current = v61;
        if ( v61 != 61 )
          return 126;
        v62 = ls->z;
        v63 = v62->n--;
        if ( v63 != 0 )
        {
          v64 = ls->z;
          v65 = v64->p;
          v66 = *(unsigned __int8 *)v65;
          v64->p = v65 + 1;
          ls->current = v66;
        }
        else
        {
          ls->current = luaZ_fill(z: ls->z);
        }
        return 283;
      default:
        if ( isspace(c: ls->current) != 0 )
        {
          v19 = ls->z;
          v20 = v19->n--;
          if ( v20 != 0 )
          {
            v21 = ls->z;
            v22 = v21->p;
            v23 = *(unsigned __int8 *)v22;
            v21->p = v22 + 1;
            ls->current = v23;
          }
          else
          {
            ls->current = luaZ_fill(z: ls->z);
          }
          continue;
        }
        if ( isdigit(c: ls->current) != 0 )
        {
LABEL_87:
          read_numeral(ls, seminfo);
          return 284;
        }
        else if ( isalpha(c: ls->current) != 0 || (v84 = ls->current, ls->current == 95) )
        {
          do
          {
            save(ls, c: ls->current);
            v90 = ls->z;
            v91 = v90->n--;
            if ( v91 != 0 )
            {
              v92 = ls->z;
              v93 = v92->p;
              v94 = *(unsigned __int8 *)v93;
              v92->p = v93 + 1;
            }
            else
            {
              v94 = luaZ_fill(z: ls->z);
            }
            ls->current = v94;
          }
          while ( isalnum(c: v94) != 0 || ls->current == 95 );
          v95 = luaX_newstring(ls, str: ls->buff->buffer, l: ls->buff->n);
          reserved = v95->ts.tsv.reserved;
          if ( reserved != 0 )
          {
            return reserved + 256;
          }
          else
          {
            seminfo->ts = (TString *)v95;
            return 285;
          }
        }
        else
        {
          v85 = ls->z;
          v86 = v85->n--;
          if ( v86 != 0 )
          {
            v87 = ls->z;
            v88 = v87->p;
            v89 = *(unsigned __int8 *)v88;
            v87->p = v88 + 1;
            ls->current = v89;
          }
          else
          {
            ls->current = luaZ_fill(z: ls->z);
          }
          return v84;
        }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004863B0
// Name: void luaX_next(struct LexState __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaX_next(LexState *ls)
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

//------------------------------------------------------------------------------
// Address: 0x00486400
// Name: void luaX_lookahead(struct LexState __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaX_lookahead(LexState *ls)
{
  ls->lookahead.token = llex(ls, seminfo: &ls->lookahead.seminfo);
}
