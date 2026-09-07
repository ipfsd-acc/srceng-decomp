// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lstrlib.c
// Functions: 36
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047ED20
// Name: str_len
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_len(lua_State *L)
{
  unsigned int l; // [esp+4h] [ebp-4h] BYREF

  luaL_checklstring(L, narg: 1, len: &l);
  lua_pushinteger(L, n: l);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047ED50
// Name: str_sub
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_sub(lua_State *L)
{
  const char *v1; // eax
  unsigned int v2; // esi
  lua_TValue *v3; // eax
  int v4; // esi
  unsigned int v5; // ebx
  lua_TValue *v6; // eax
  const char *s; // [esp+8h] [ebp-8h]
  unsigned int l; // [esp+Ch] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  v2 = l;
  s = v1;
  v3 = luaL_checkinteger(L, narg: 2);
  if ( (int)v3 < 0 )
    v4 = (int)&v3->value.gc + v2 + 1;
  else
    v4 = (int)v3;
  v5 = l;
  v6 = luaL_optinteger(L, narg: 3, def: -1);
  if ( (int)v6 < 0 )
    v6 = (lua_TValue *)((char *)v6 + v5 + 1);
  if ( v4 < 1 )
    v4 = 1;
  if ( (int)v6 > (int)l )
    v6 = (lua_TValue *)l;
  if ( v4 > (int)v6 )
    lua_pushlstring(L, s: var, len: 0);
  else
    lua_pushlstring(L, s: &s[v4 - 1], len: (unsigned int)&v6->value.gc - v4 + 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EDF0
// Name: str_reverse
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_reverse(lua_State *L)
{
  const char *v1; // edi
  luaL_Buffer b; // [esp+Ch] [ebp-210h] BYREF
  unsigned int l; // [esp+218h] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  luaL_buffinit(L, B: &b);
  for ( ; l != 0; ++b.p )
  {
    --l;
    if ( b.p >= (char *)&l )
      luaL_prepbuffer(B: &b);
    *b.p = v1[l];
  }
  --l;
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EE90
// Name: str_lower
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_lower(lua_State *L)
{
  const char *v1; // edi
  unsigned int i; // esi
  luaL_Buffer b; // [esp+8h] [ebp-210h] BYREF
  unsigned int l; // [esp+214h] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  luaL_buffinit(L, B: &b);
  for ( i = 0; i < l; ++i )
  {
    if ( b.p >= (char *)&l )
      luaL_prepbuffer(B: &b);
    *b.p++ = tolower(c: (unsigned __int8)v1[i]);
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EF20
// Name: str_upper
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_upper(lua_State *L)
{
  const char *v1; // edi
  unsigned int i; // esi
  luaL_Buffer b; // [esp+8h] [ebp-210h] BYREF
  unsigned int l; // [esp+214h] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  luaL_buffinit(L, B: &b);
  for ( i = 0; i < l; ++i )
  {
    if ( b.p >= (char *)&l )
      luaL_prepbuffer(B: &b);
    *b.p++ = toupper(c: (unsigned __int8)v1[i]);
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EFB0
// Name: str_rep
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_rep(lua_State *L)
{
  const char *v1; // ebx
  lua_TValue *v2; // esi
  luaL_Buffer b; // [esp+Ch] [ebp-210h] BYREF
  unsigned int l; // [esp+218h] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  v2 = luaL_checkinteger(L, narg: 2);
  luaL_buffinit(L, B: &b);
  while ( (int)v2 > 0 )
  {
    v2 = (lua_TValue *)((char *)v2 - 1);
    luaL_addlstring(B: &b, s: v1, l);
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F030
// Name: str_byte
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_byte(lua_State *L)
{
  const char *v1; // eax
  unsigned int v2; // esi
  lua_TValue *v3; // eax
  int v4; // ebx
  unsigned int v5; // esi
  lua_TValue *v6; // eax
  int v8; // esi
  int v9; // edi
  int v10; // ebx
  const char *s; // [esp+Ch] [ebp-8h]
  unsigned int l; // [esp+10h] [ebp-4h] BYREF

  v1 = luaL_checklstring(L, narg: 1, len: &l);
  v2 = l;
  s = v1;
  v3 = luaL_optinteger(L, narg: 2, def: 1);
  v4 = (int)v3;
  if ( (int)v3 < 0 )
    v4 = (int)&v3->value.gc + v2 + 1;
  v5 = l;
  v6 = luaL_optinteger(L, narg: 3, def: v4);
  if ( (int)v6 < 0 )
    v6 = (lua_TValue *)((char *)v6 + v5 + 1);
  if ( v4 <= 0 )
    v4 = 1;
  if ( (unsigned int)v6 > l )
    v6 = (lua_TValue *)l;
  if ( v4 > (int)v6 )
    return 0;
  v8 = (int)&v6->value.gc - v4 + 1;
  if ( (int)((char *)&v6->value.gc + 1) <= (int)v6 )
    luaL_error(L, fmt: "string slice too long");
  luaL_checkstack(L, space: (int)&v6->value.gc - v4 + 1, mes: "string slice too long");
  v9 = 0;
  if ( v8 > 0 )
  {
    v10 = (int)&s[v4 - 1];
    do
      lua_pushinteger(L, n: *(unsigned __int8 *)(v10 + v9++));
    while ( v9 < v8 );
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0047F0F0
// Name: str_char
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_char(lua_State *L)
{
  int v1; // ebx
  int v2; // esi
  lua_TValue *v3; // eax
  char v4; // bl
  luaL_Buffer b; // [esp+Ch] [ebp-210h] BYREF
  int n; // [esp+218h] [ebp-4h] BYREF

  v1 = lua_gettop(L);
  n = v1;
  luaL_buffinit(L, B: &b);
  v2 = 1;
  if ( v1 >= 1 )
  {
    do
    {
      v3 = luaL_checkinteger(L, narg: v2);
      v4 = (char)v3;
      if ( (lua_TValue *)(unsigned __int8)v3 != v3 )
        luaL_argerror(L, narg: v2, extramsg: "invalid value");
      if ( b.p >= (char *)&n )
        luaL_prepbuffer(B: &b);
      *b.p++ = v4;
      ++v2;
    }
    while ( v2 <= n );
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F190
// Name: writer
// Source: json
//------------------------------------------------------------------------------
int __cdecl writer(lua_State *L, const char *b, unsigned int size, luaL_Buffer *B)
{
  luaL_addlstring(B, s: b, l: size);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047F1B0
// Name: str_dump
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_dump(lua_State *L)
{
  luaL_Buffer b; // [esp+4h] [ebp-20Ch] BYREF

  luaL_checktype(L, narg: 1, t: 6);
  lua_settop(L, idx: 1);
  luaL_buffinit(L, B: &b);
  if ( lua_dump(L, writer: (int (__cdecl *)(lua_State *, const void *, unsigned int, void *))writer, data: &b) != 0 )
    luaL_error(L, fmt: "unable to dump given function");
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F220
// Name: classend
// Source: json
//------------------------------------------------------------------------------
const char *__usercall classend@<eax>(MatchState *ms@<edi>, const char *p@<eax>)
{
  int v3; // eax
  const char *v4; // esi
  char v6; // cl

  v3 = *p;
  v4 = p + 1;
  if ( v3 == 37 )
  {
    if ( *v4 == 0 )
      luaL_error(L: ms->L, fmt: "malformed pattern (ends with '%%')");
    return v4 + 1;
  }
  else if ( v3 == 91 )
  {
    if ( *v4 == 94 )
      ++v4;
    do
    {
      if ( *v4 == 0 )
        luaL_error(L: ms->L, fmt: "malformed pattern (missing ']')");
      v6 = *v4++;
      if ( v6 == 37 && *v4 != 0 )
        ++v4;
    }
    while ( *v4 != 93 );
    return v4 + 1;
  }
  else
  {
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F290
// Name: match_class
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall match_class@<eax>(int c@<eax>, int cl@<edi>)
{
  int v3; // esi
  BOOL result; // eax
  int v5; // [esp+0h] [ebp-8h]

  switch ( tolower(c: v5) )
  {
    case 'a':
      v3 = isalpha(c);
      goto LABEL_12;
    case 'c':
      v3 = iscntrl(c);
      goto LABEL_12;
    case 'd':
      v3 = isdigit(c);
      goto LABEL_12;
    case 'l':
      v3 = islower(c);
      goto LABEL_12;
    case 'p':
      v3 = ispunct(c);
      goto LABEL_12;
    case 's':
      v3 = isspace(c);
      goto LABEL_12;
    case 'u':
      v3 = isupper(c);
      goto LABEL_12;
    case 'w':
      v3 = isalnum(c);
      goto LABEL_12;
    case 'x':
      v3 = isxdigit(c);
      goto LABEL_12;
    case 'z':
      v3 = c == 0;
LABEL_12:
      if ( islower(c: cl) != 0 )
        result = v3;
      else
        result = v3 == 0;
      break;
    default:
      result = cl == c;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F3A0
// Name: matchbracketclass
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall matchbracketclass@<eax>(const char *p@<eax>, int c, const char *ec)
{
  const char *v3; // esi
  const char *v4; // edx
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // eax
  int v7; // edi
  int v8; // edi
  int v9; // ecx
  unsigned __int8 *v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int sig; // [esp+14h] [ebp-4h]

  v3 = p;
  sig = 1;
  if ( p[1] == 94 )
  {
    sig = 0;
    v3 = p + 1;
  }
  v4 = ec;
  v5 = (unsigned __int8 *)(v3 + 1);
  if ( v5 < (unsigned __int8 *)ec )
  {
    v6 = v5 + 2;
    do
    {
      if ( *v5 == 37 )
      {
        v7 = *++v5;
        v11 = v6 + 1;
        v12 = v7;
        switch ( tolower(c: v7) )
        {
          case 'a':
            v8 = isalpha(c);
            goto LABEL_17;
          case 'c':
            v8 = iscntrl(c);
            goto LABEL_17;
          case 'd':
            v8 = isdigit(c);
            goto LABEL_17;
          case 'l':
            v8 = islower(c);
            goto LABEL_17;
          case 'p':
            v8 = ispunct(c);
            goto LABEL_17;
          case 's':
            v8 = isspace(c);
            goto LABEL_17;
          case 'u':
            v8 = isupper(c);
            goto LABEL_17;
          case 'w':
            v8 = isalnum(c);
            goto LABEL_17;
          case 'x':
            v8 = isxdigit(c);
            goto LABEL_17;
          case 'z':
            v8 = c == 0;
LABEL_17:
            if ( islower(c: v12) == 0 )
              v8 = v8 == 0;
            break;
          default:
            v8 = v7 == c;
            break;
        }
        if ( v8 != 0 )
          return sig;
        v6 = v11;
        v4 = ec;
      }
      else if ( v5[1] == 45 && v6 < (unsigned __int8 *)v4 )
      {
        v9 = *v5;
        v5 += 2;
        v6 += 2;
        if ( v9 <= c && c <= *v5 )
          return sig;
      }
      else if ( *v5 == c )
      {
        return sig;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < (unsigned __int8 *)v4 );
  }
  return sig == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047F550
// Name: matchbalance
// Source: json
//------------------------------------------------------------------------------
const char *__usercall matchbalance@<eax>(const char *s@<ecx>, char *p@<eax>, MatchState *ms)
{
  char v5; // al
  int v6; // edi
  const char *src_end; // ecx
  const char *v8; // esi
  int i; // edx
  int v10; // eax
  int b; // [esp+Ch] [ebp-4h]

  if ( *p == 0 || p[1] == 0 )
    luaL_error(L: ms->L, fmt: "unbalanced pattern");
  v5 = *p;
  if ( *s == *p )
  {
    v6 = p[1];
    b = v5;
    src_end = ms->src_end;
    v8 = s + 1;
    for ( i = 1; v8 < src_end; ++v8 )
    {
      v10 = *v8;
      if ( v10 == v6 )
      {
        if ( --i == 0 )
          return v8 + 1;
      }
      else if ( v10 == b )
      {
        ++i;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047F5C0
// Name: max_expand
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl max_expand(MatchState *ms, const char *s, const char *p, const char *ep)
{
  const char *v4; // esi
  MatchState *v5; // edi
  int v6; // ebx
  unsigned __int8 v7; // cl
  int v8; // eax
  BOOL matched; // eax
  const char *result; // eax

  v4 = s;
  v5 = ms;
  v6 = 0;
  if ( s < ms->src_end )
  {
    while ( 1 )
    {
      v7 = *p;
      v8 = *(unsigned __int8 *)v4;
      if ( *p == 37 )
        break;
      if ( v7 != 46 )
      {
        if ( v7 == 91 )
          matched = matchbracketclass(p, c: v8, ec: ep - 1);
        else
          matched = v7 == v8;
LABEL_8:
        if ( !matched )
          goto LABEL_10;
      }
      ++v4;
      ++v6;
      if ( v4 >= v5->src_end )
      {
LABEL_10:
        if ( v6 >= 0 )
          goto LABEL_11;
        return nullptr;
      }
    }
    matched = match_class(c: v8, cl: *((unsigned __int8 *)p + 1));
    v5 = ms;
    goto LABEL_8;
  }
LABEL_11:
  while ( 1 )
  {
    result = match(ms: v5, s: &s[v6], p: ep + 1);
    if ( result != nullptr )
      break;
    if ( --v6 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F650
// Name: min_expand
// Source: json
//------------------------------------------------------------------------------
const char *__usercall min_expand@<eax>(const char *s@<eax>, MatchState *ms, const char *p, const char *ep)
{
  const char *v4; // edi
  const char *v5; // esi
  const char *result; // eax
  unsigned __int8 v7; // cl
  int v8; // eax
  BOOL matched; // eax

  v4 = ep;
  v5 = s;
  for ( result = match(ms, s, p: ep + 1); result == nullptr; result = match(ms, s: ++v5, p: v4 + 1) )
  {
    if ( v5 >= ms->src_end )
      return nullptr;
    v7 = *p;
    v8 = *(unsigned __int8 *)v5;
    if ( *p == 37 )
    {
      matched = match_class(c: v8, cl: *((unsigned __int8 *)p + 1));
      v4 = ep;
    }
    else
    {
      if ( v7 == 46 )
        continue;
      if ( v7 == 91 )
        matched = matchbracketclass(p, c: v8, ec: v4 - 1);
      else
        matched = v7 == v8;
    }
    if ( !matched )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F6E0
// Name: start_capture
// Source: json
//------------------------------------------------------------------------------
const char *__usercall start_capture@<eax>(MatchState *ms@<esi>, const char *s, const char *p, int what)
{
  int level; // edi
  const char *result; // eax

  level = ms->level;
  if ( level >= 32 )
    luaL_error(L: ms->L, fmt: "too many captures");
  ms->capture[level].init = s;
  ms->capture[level].len = what;
  ms->level = level + 1;
  result = match(ms, s, p);
  if ( result == nullptr )
    --ms->level;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F730
// Name: end_capture
// Source: json
//------------------------------------------------------------------------------
const char *__usercall end_capture@<eax>(MatchState *ms@<esi>, const char *s, const char *p)
{
  int v3; // eax
  int *p_len; // ecx
  int v5; // edi
  const char *result; // eax

  v3 = ms->level - 1;
  if ( v3 < 0 )
LABEL_5:
    luaL_error(L: ms->L, fmt: "invalid pattern capture");
  p_len = &ms->capture[v3].len;
  while ( *p_len != -1 )
  {
    p_len -= 2;
    if ( --v3 < 0 )
      goto LABEL_5;
  }
  v5 = v3;
  ms->capture[v3].len = s - ms->capture[v3].init;
  result = match(ms, s, p);
  if ( result == nullptr )
    ms->capture[v5].len = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F790
// Name: match_capture
// Source: json
//------------------------------------------------------------------------------
const char *__usercall match_capture@<eax>(MatchState *ms@<ecx>, int l@<eax>, const char *s)
{
  int v3; // eax
  unsigned int len; // edi
  const char *init; // esi
  unsigned int v6; // ecx
  const char *v7; // edx

  v3 = l - 49;
  if ( v3 < 0 || v3 >= ms->level || ms->capture[v3].len == -1 )
    luaL_error(L: ms->L, fmt: "invalid capture index");
  len = ms->capture[v3].len;
  if ( ms->src_end - s >= len )
  {
    init = ms->capture[v3].init;
    v6 = ms->capture[v3].len;
    v7 = s;
    if ( len < 4 )
    {
LABEL_9:
      if ( v6 == 0 || *v7 == *init && (v6 <= 1 || v7[1] == init[1] && (v6 <= 2 || v7[2] == init[2])) )
        return &s[len];
    }
    else
    {
      while ( *(_DWORD *)init == *(_DWORD *)v7 )
      {
        v6 -= 4;
        v7 += 4;
        init += 4;
        if ( v6 < 4 )
          goto LABEL_9;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047F820
// Name: match
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl match(MatchState *ms, const char *s, const char *p)
{
  const char *v4; // ebx
  unsigned __int8 v5; // al
  const char *v6; // ebx
  const char *v7; // eax
  unsigned __int8 v8; // cl
  const char *v9; // edi
  const char *result; // eax
  const char *v11; // eax
  MatchState *v12; // edx
  const char *v13; // edi
  unsigned __int8 v14; // cl
  int v15; // eax
  BOOL matched; // eax
  int v17; // ecx
  const char *ep; // [esp+1Ch] [ebp+10h]

LABEL_1:
  v4 = p;
  while ( 2 )
  {
    switch ( *v4 )
    {
      case 0:
        return s;
      case 0x24:
        if ( v4[1] != 0 )
          goto dflt;
        return s != ms->src_end ? nullptr : s;
      case 0x25:
        v5 = v4[1];
        if ( v5 == 98 )
        {
          s = matchbalance(s, p: (char *)v4 + 2, ms);
          if ( s == nullptr )
            return nullptr;
          v4 += 4;
          continue;
        }
        if ( v5 != 102 )
        {
          if ( isdigit(c: v5) == 0 )
          {
dflt:
            v11 = classend(ms, p: v4);
            v12 = ms;
            v13 = v11;
            ep = v11;
            if ( s >= ms->src_end )
              goto LABEL_29;
            v14 = *v4;
            v15 = *(unsigned __int8 *)s;
            if ( *v4 == 37 )
            {
              matched = match_class(c: v15, cl: *((unsigned __int8 *)v4 + 1));
              v13 = ep;
              goto LABEL_27;
            }
            if ( v14 == 46 )
              goto LABEL_28;
            matched = v14 == 91 ? matchbracketclass(p: v4, c: v15, ec: v13 - 1) : v14 == v15;
LABEL_27:
            v12 = ms;
            if ( matched )
LABEL_28:
              v17 = 1;
            else
LABEL_29:
              v17 = 0;
            switch ( *v13 )
            {
              case '*':
                return max_expand(ms: v12, s, p: v4, ep: v13);
              case '+':
                if ( v17 == 0 )
                  return nullptr;
                return max_expand(ms: v12, s: s + 1, p: v4, ep: v13);
              case '-':
                return min_expand(s, ms: v12, p: v4, ep: v13);
              case '?':
                if ( v17 != 0 )
                {
                  result = match(ms: v12, s: s + 1, p: v13 + 1);
                  if ( result != nullptr )
                    return result;
                }
                v4 = v13 + 1;
                continue;
              default:
                if ( v17 == 0 )
                  return nullptr;
                ++s;
                v4 = v13;
                continue;
            }
          }
          s = match_capture(ms, l: *((unsigned __int8 *)v4 + 1), s);
          if ( s == nullptr )
            return nullptr;
          v4 += 2;
          continue;
        }
        v6 = v4 + 2;
        if ( *v6 != 91 )
          luaL_error(L: ms->L, fmt: "missing '[' after '%%f' in pattern");
        v7 = classend(ms, p: v6);
        p = v7;
        if ( s == ms->src_init )
          v8 = 0;
        else
          v8 = *(s - 1);
        v9 = v7 - 1;
        if ( !matchbracketclass(p: v6, c: v8, ec: v7 - 1) && matchbracketclass(p: v6, c: *(unsigned __int8 *)s, ec: v9) )
          goto LABEL_1;
        return nullptr;
      case 0x28:
        if ( v4[1] == 41 )
          return start_capture(ms, s, p: v4 + 2, what: -2);
        else
          return start_capture(ms, s, p: v4 + 1, what: -1);
      case 0x29:
        return end_capture(ms, s, p: v4 + 1);
      default:
        goto dflt;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FAE0
// Name: lmemfind
// Source: json
//------------------------------------------------------------------------------
char *__cdecl lmemfind(char *s1, unsigned int l1, const char *s2, unsigned int l2)
{
  char *result; // eax
  const char *v5; // edi
  const char *v6; // edx
  unsigned int v7; // ecx
  const char *v8; // esi
  bool v9; // zf
  unsigned int l1a; // [esp+10h] [ebp+Ch]

  if ( l2 == 0 )
    return s1;
  if ( l2 > l1 )
    return nullptr;
  l1a = l1 - (l2 - 1);
  if ( l1a != 0 )
  {
    do
    {
      memchr(buf: (unsigned __int8 *)s1, chr: *s2, cnt: l1a);
      if ( result == nullptr )
        break;
      v5 = result + 1;
      v6 = s2 + 1;
      v7 = l2 - 1;
      v8 = result + 1;
      if ( l2 - 1 < 4 )
      {
LABEL_10:
        if ( v7 == 0 || *v6 == *v8 && (v7 <= 1 || v6[1] == v8[1] && (v7 <= 2 || v6[2] == v8[2])) )
          return result;
      }
      else
      {
        while ( *(_DWORD *)v8 == *(_DWORD *)v6 )
        {
          v7 -= 4;
          v6 += 4;
          v8 += 4;
          if ( v7 < 4 )
            goto LABEL_10;
        }
      }
      v9 = s1 - v5 + l1a == 0;
      l1a += s1 - v5;
      s1 = result + 1;
    }
    while ( !v9 );
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047FB90
// Name: push_onecapture
// Source: json
//------------------------------------------------------------------------------
void __usercall push_onecapture(MatchState *ms@<esi>, int i@<edi>, const char *s@<ecx>, const char *e@<eax>)
{
  int len; // ebx

  if ( i < ms->level )
  {
    len = ms->capture[i].len;
    if ( len == -1 )
      luaL_error(L: ms->L, fmt: "unfinished capture");
    if ( len == -2 )
      lua_pushinteger(L: ms->L, n: ms->capture[i].init - ms->src_init + 1);
    else
      lua_pushlstring(L: ms->L, s: ms->capture[i].init, len: ms->capture[i].len);
  }
  else
  {
    if ( i != 0 )
      luaL_error(L: ms->L, fmt: "invalid capture index");
    lua_pushlstring(L: ms->L, s, len: e - s);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FC10
// Name: push_captures
// Source: json
//------------------------------------------------------------------------------
int __usercall push_captures@<eax>(MatchState *ms@<esi>, const char *s, const char *e)
{
  int v3; // ebx
  int i; // edi
  int len; // ebx
  int nlevels; // [esp+8h] [ebp-4h]

  if ( ms->level != 0 || s == nullptr )
  {
    nlevels = ms->level;
    v3 = nlevels;
  }
  else
  {
    v3 = 1;
    nlevels = 1;
  }
  luaL_checkstack(L: ms->L, space: v3, mes: "too many captures");
  for ( i = 0; i < v3; ++i )
  {
    if ( i < ms->level )
    {
      len = ms->capture[i].len;
      if ( len == -1 )
        luaL_error(L: ms->L, fmt: "unfinished capture");
      if ( len == -2 )
        lua_pushinteger(L: ms->L, n: ms->capture[i].init - ms->src_init + 1);
      else
        lua_pushlstring(L: ms->L, s: ms->capture[i].init, len: ms->capture[i].len);
      v3 = nlevels;
    }
    else
    {
      if ( i != 0 )
        luaL_error(L: ms->L, fmt: "invalid capture index");
      lua_pushlstring(L: ms->L, s, len: e - s);
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047FCE0
// Name: str_find_aux
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_find_aux(lua_State *L, int find)
{
  const char *v2; // edi
  const char *v3; // eax
  unsigned int v4; // esi
  lua_TValue *v5; // eax
  signed int v6; // esi
  unsigned int v7; // eax
  int v8; // eax
  char *v9; // eax
  int v10; // esi
  const char *v12; // esi
  const char *v13; // eax
  const char *v14; // edi
  const char *v15; // edx
  MatchState ms; // [esp+Ch] [ebp-124h] BYREF
  int anchor; // [esp+11Ch] [ebp-14h]
  const char *s; // [esp+120h] [ebp-10h]
  unsigned int l2; // [esp+124h] [ebp-Ch] BYREF
  unsigned int l1; // [esp+128h] [ebp-8h] BYREF
  const char *p; // [esp+12Ch] [ebp-4h]

  v2 = luaL_checklstring(L, narg: 1, len: &l1);
  s = v2;
  v3 = luaL_checklstring(L, narg: 2, len: &l2);
  v4 = l1;
  p = v3;
  v5 = luaL_optinteger(L, narg: 3, def: 1);
  if ( (int)v5 < 0 )
    v5 = (lua_TValue *)((char *)v5 + v4 + 1);
  v6 = (signed int)&v5[-1].tt + 7;
  v7 = l1;
  if ( v6 >= 0 )
  {
    if ( v6 > l1 )
      v6 = l1;
  }
  else
  {
    v6 = 0;
  }
  if ( find != 0 )
  {
    if ( lua_toboolean(L, idx: 4) || (strpbrk(string: (unsigned __int8 *)p, control: "^$*+?.([%-"), v8 == 0) )
    {
      v9 = lmemfind(s1: (char *)&v2[v6], l1: l1 - v6, s2: p, l2);
      if ( v9 != nullptr )
      {
        v10 = v9 - v2;
        lua_pushinteger(L, n: v9 - v2 + 1);
        lua_pushinteger(L, n: l2 + v10);
        return 2;
      }
      else
      {
LABEL_20:
        lua_pushnil(L);
        return 1;
      }
    }
    v7 = l1;
  }
  if ( *p == 94 )
  {
    ++p;
    anchor = 1;
  }
  else
  {
    anchor = 0;
  }
  v12 = &v2[v6];
  ms.L = L;
  ms.src_init = v2;
  ms.src_end = &v2[v7];
  while ( 1 )
  {
    ms.level = 0;
    v13 = match(&ms, s: v12, p);
    v14 = v13;
    if ( v13 != nullptr )
      break;
    v15 = v12++;
    if ( v15 >= ms.src_end || anchor != 0 )
      goto LABEL_20;
  }
  if ( find == 0 )
    return push_captures(&ms, s: v12, e: v13);
  lua_pushinteger(L, n: v12 - s + 1);
  lua_pushinteger(L, n: v14 - s);
  return push_captures(&ms, s: nullptr, e: nullptr) + 2;
}

//------------------------------------------------------------------------------
// Address: 0x0047FE80
// Name: str_find
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_find(lua_State *L)
{
  return str_find_aux(L, find: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0047FEA0
// Name: str_match
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_match(lua_State *L)
{
  return str_find_aux(L, find: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0047FEC0
// Name: gmatch_aux
// Source: json
//------------------------------------------------------------------------------
int __cdecl gmatch_aux(lua_State *L)
{
  lua_State *v1; // edi
  const char *v2; // esi
  const char *v3; // eax
  const char *v4; // ebx
  int v6; // eax
  MatchState ms; // [esp+Ch] [ebp-118h] BYREF
  const char *p; // [esp+11Ch] [ebp-8h]
  const char *s; // [esp+120h] [ebp-4h]

  v1 = L;
  s = lua_tolstring(L, idx: -10003, len: (unsigned int *)&L);
  p = lua_tolstring(L: v1, idx: -10004, len: nullptr);
  ms.L = v1;
  ms.src_init = s;
  ms.src_end = (char *)L + (_DWORD)s;
  v2 = (char *)lua_tointeger(L: v1, idx: -10005) + (_DWORD)s;
  if ( v2 > ms.src_end )
    return 0;
  while ( 1 )
  {
    ms.level = 0;
    v3 = match(&ms, s: v2, p);
    v4 = v3;
    if ( v3 != nullptr )
      break;
    if ( ++v2 > ms.src_end )
      return 0;
  }
  v6 = v3 - s;
  if ( v4 == v2 )
    ++v6;
  lua_pushinteger(L: v1, n: v6);
  lua_replace(L: v1, idx: -10005);
  return push_captures(&ms, s: v2, e: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0047FF90
// Name: gmatch
// Source: json
//------------------------------------------------------------------------------
int __cdecl gmatch(lua_State *L)
{
  luaL_checklstring(L, narg: 1, len: nullptr);
  luaL_checklstring(L, narg: 2, len: nullptr);
  lua_settop(L, idx: 2);
  lua_pushinteger(L, n: 0);
  lua_pushcclosure(L, fn: gmatch_aux, n: 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FFE0
// Name: gfind_nodef
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn gfind_nodef(lua_State *L)
{
  luaL_error(L, fmt: "'string.gfind' was renamed to 'string.gmatch'");
}

//------------------------------------------------------------------------------
// Address: 0x00480000
// Name: add_s
// Source: json
//------------------------------------------------------------------------------
void __cdecl add_s(MatchState *ms, luaL_Buffer *b, const char *s, const char *e)
{
  unsigned int v4; // edi
  const char *v5; // esi
  int v6; // eax
  char v7; // al
  const char *news; // [esp+10h] [ebp-8h]
  unsigned int l; // [esp+14h] [ebp-4h] BYREF

  v4 = 0;
  v5 = lua_tolstring(L: ms->L, idx: 3, len: &l);
  for ( news = v5; v4 < l; ++v4 )
  {
    if ( v5[v4] == 37 )
    {
      v6 = (unsigned __int8)v5[++v4];
      if ( isdigit(c: v6) != 0 )
      {
        v7 = v5[v4];
        if ( v7 == 48 )
        {
          luaL_addlstring(B: b, s, l: e - s);
        }
        else
        {
          push_onecapture(ms, i: v7 - 49, s, e);
          luaL_addvalue(B: (unsigned int)b);
          v5 = news;
        }
      }
      else
      {
        if ( b->p >= (char *)&b[1] )
          luaL_prepbuffer(B: b);
        *b->p++ = v5[v4];
      }
    }
    else
    {
      if ( b->p >= (char *)&b[1] )
        luaL_prepbuffer(B: b);
      *b->p++ = v5[v4];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004800E0
// Name: add_value
// Source: json
//------------------------------------------------------------------------------
void __usercall add_value(MatchState *ms@<eax>, luaL_Buffer *b, const char *s, const char *e)
{
  lua_State *L; // ebx
  const char *v6; // edi
  int v7; // eax
  int v8; // eax
  const char *v9; // eax

  L = ms->L;
  switch ( lua_type(L, idx: 3) )
  {
    case 3:
    case 4:
      add_s(ms, b, s, e);
      return;
    case 5:
      push_onecapture(ms, i: 0, s, e);
      lua_gettable(L, idx: 3);
      v6 = e;
      goto LABEL_5;
    case 6:
      lua_pushvalue(L, idx: 3);
      v6 = e;
      v7 = push_captures(ms, s, e);
      lua_call(L, nargs: v7, nresults: 1);
LABEL_5:
      if ( lua_toboolean(L, idx: -1) )
      {
        if ( !lua_isstring(L, idx: -1) )
        {
          v8 = lua_type(L, idx: -1);
          v9 = lua_typename(L, t: v8);
          luaL_error(L, fmt: "invalid replacement value (a %s)", v9);
        }
        luaL_addvalue(B: (unsigned int)b);
      }
      else
      {
        lua_settop(L, idx: -2);
        lua_pushlstring(L, s, len: v6 - s);
        luaL_addvalue(B: (unsigned int)b);
      }
      return;
    default:
      luaL_argerror(L, narg: 3, extramsg: "string/function/table expected");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480200
// Name: str_gsub
// Source: json
//------------------------------------------------------------------------------
int __cdecl str_gsub(lua_State *L)
{
  const char *v2; // esi
  const char *v3; // edi
  lua_TValue *v4; // eax
  bool v5; // zf
  const char *src_end; // eax
  const char *v7; // eax
  const char *v8; // edi
  luaL_Buffer b; // [esp+Ch] [ebp-32Ch] BYREF
  MatchState ms; // [esp+218h] [ebp-120h] BYREF
  unsigned int srcl; // [esp+328h] [ebp-10h] BYREF
  const char *p; // [esp+32Ch] [ebp-Ch]
  int max_s; // [esp+330h] [ebp-8h]
  int anchor; // [esp+334h] [ebp-4h]
  int n; // [esp+340h] [ebp+8h]

  v2 = luaL_checklstring(L, narg: 1, len: &srcl);
  v3 = luaL_checklstring(L, narg: 2, len: nullptr);
  p = v3;
  v4 = luaL_optinteger(L, narg: 4, def: srcl + 1);
  v5 = *v3 == 94;
  max_s = (int)v4;
  if ( v5 )
  {
    p = ++v3;
    anchor = 1;
  }
  else
  {
    anchor = 0;
  }
  n = 0;
  luaL_buffinit(L, B: &b);
  src_end = &v2[srcl];
  ms.L = L;
  ms.src_init = v2;
  ms.src_end = &v2[srcl];
  if ( max_s > 0 )
  {
    while ( 1 )
    {
      ms.level = 0;
      v7 = match(&ms, s: v2, p: v3);
      v8 = v7;
      if ( v7 != nullptr && (++n, add_value(&ms, &b, s: v2, e: v7), v8 > v2) )
      {
        v2 = v8;
      }
      else
      {
        src_end = ms.src_end;
        if ( v2 >= ms.src_end )
          goto LABEL_17;
        if ( b.p >= (char *)&ms )
          luaL_prepbuffer(B: &b);
        *b.p++ = *v2++;
      }
      if ( anchor != 0 || n >= max_s )
        break;
      v3 = p;
    }
    src_end = ms.src_end;
  }
LABEL_17:
  luaL_addlstring(B: &b, s: v2, l: src_end - v2);
  luaL_pushresult(B: &b);
  lua_pushinteger(L, n);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00480360
// Name: addquoted
// Source: json
//------------------------------------------------------------------------------
void __usercall addquoted(lua_State *L@<edx>, luaL_Buffer *b@<esi>, int arg@<ecx>)
{
  char *v3; // ebx
  char *v4; // edi
  unsigned int len; // [esp+8h] [ebp-4h] BYREF

  v3 = (char *)&b[1];
  v4 = (char *)luaL_checklstring(L, narg: arg, &len);
  if ( b->p >= (char *)&b[1] )
    luaL_prepbuffer(B: b);
  for ( *b->p++ = 34; len != 0; ++v4 )
  {
    --len;
    switch ( *v4 )
    {
      case 0:
        luaL_addlstring(B: b, s: "\\000", l: 4u);
        break;
      case 10:
      case 34:
      case 92:
        if ( b->p >= v3 )
          luaL_prepbuffer(B: b);
        *b->p++ = 92;
        if ( b->p >= v3 )
          luaL_prepbuffer(B: b);
        *b->p = *v4;
        goto LABEL_15;
      case 13:
        luaL_addlstring(B: b, s: "\\r", l: 2u);
        break;
      default:
        if ( b->p >= v3 )
          luaL_prepbuffer(B: b);
        *b->p = *v4;
LABEL_15:
        ++b->p;
        break;
    }
  }
  --len;
  if ( b->p >= v3 )
    luaL_prepbuffer(B: b);
  *b->p++ = 34;
}

//------------------------------------------------------------------------------
// Address: 0x004804C0
// Name: scanformat
// Source: json
//------------------------------------------------------------------------------
char *__usercall scanformat@<eax>(lua_State *L@<eax>, char *strfrmt, char *form)
{
  char *v4; // esi
  int v5; // eax
  unsigned __int8 v6; // cl
  int v7; // eax
  int v8; // edx
  char *forma; // [esp+18h] [ebp+Ch]

  v4 = strfrmt;
  strchr(string: "-+ #0", chr: *strfrmt);
  if ( v5 != 0 )
  {
    do
    {
      v6 = *++v4;
      strchr(string: "-+ #0", chr: v6);
    }
    while ( v7 != 0 );
  }
  if ( (unsigned int)(v4 - strfrmt) >= 6 )
    luaL_error(L, fmt: "invalid format (repeated flags)");
  if ( isdigit(c: (unsigned __int8)*v4) != 0 )
    ++v4;
  if ( isdigit(c: (unsigned __int8)*v4) != 0 )
    ++v4;
  if ( *v4 == 46 )
  {
    v8 = (unsigned __int8)*++v4;
    if ( isdigit(c: v8) != 0 )
      ++v4;
    if ( isdigit(c: (unsigned __int8)*v4) != 0 )
      ++v4;
  }
  if ( isdigit(c: (unsigned __int8)*v4) != 0 )
    luaL_error(L, fmt: "invalid format (width or precision too long)");
  *form = 37;
  forma = form + 1;
  strncpy(dest: (unsigned __int8 *)forma, source: (unsigned __int8 *)strfrmt, count: v4 - strfrmt + 1);
  forma[v4 - strfrmt + 1] = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004805B0
// Name: str_format
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl str_format(lua_State *L)
{
  int v1; // esi
  const char *v2; // edi
  char *v3; // edi
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  unsigned int v7; // kr00_4
  char v8; // cl
  double v9; // st7
  unsigned int v10; // kr04_4
  char v11; // cl
  double v12; // st7
  int v13; // eax
  char buff[512]; // [esp+14h] [ebp-438h] BYREF
  luaL_Buffer b; // [esp+214h] [ebp-238h] BYREF
  unsigned int sfl; // [esp+420h] [ebp-2Ch] BYREF
  unsigned int l; // [esp+424h] [ebp-28h] BYREF
  const char *strfrmt_end; // [esp+428h] [ebp-24h]
  char form[20]; // [esp+42Ch] [ebp-20h] BYREF
  __int64 v21; // [esp+440h] [ebp-Ch] OVERLAPPED

  v1 = 1;
  v2 = luaL_checklstring(L, narg: 1, len: &sfl);
  strfrmt_end = &v2[sfl];
  luaL_buffinit(L, B: &b);
  while ( v2 < strfrmt_end )
  {
    if ( *v2 == 37 )
    {
      v3 = (char *)(v2 + 1);
      if ( *v3 == 37 )
      {
        if ( b.p >= (char *)&sfl )
          luaL_prepbuffer(B: &b);
        *b.p++ = *v3;
        v2 = v3 + 1;
      }
      else
      {
        HIDWORD(v21) = ++v1;
        v4 = scanformat(L, strfrmt: v3, form);
        v5 = *v4 - 69;
        v2 = v4 + 1;
        switch ( v5 )
        {
          case 0:
          case 2:
          case 32:
          case 33:
          case 34:
            v12 = luaL_checknumber(L, narg: v1);
            sprintf(string: buff, format: form, v12);
            goto LABEL_21;
          case 19:
          case 42:
          case 48:
          case 51:
            v10 = strlen(form);
            v11 = form[v10 - 1];
            *(_WORD *)&form[v10 - 1] = 108;
            form[v10] = v11;
            form[v10 + 1] = 0;
            v21 = (__int64)luaL_checknumber(L, narg: v1);
            v6 = v21;
            goto LABEL_12;
          case 30:
            v6 = (int)luaL_checknumber(L, narg: v1);
LABEL_12:
            sprintf(string: buff, format: form, v6);
            goto LABEL_21;
          case 31:
          case 36:
            v7 = strlen(form);
            v8 = form[v7 - 1];
            *(_WORD *)&form[v7 - 1] = 108;
            form[v7] = v8;
            form[v7 + 1] = 0;
            v9 = luaL_checknumber(L, narg: v1);
            sprintf(string: buff, format: form, (int)v9);
            goto LABEL_21;
          case 44:
            addquoted(L, &b, arg: v1);
            v1 = HIDWORD(v21);
            break;
          case 46:
            HIDWORD(v21) = luaL_checklstring(L, narg: v1, len: &l);
            strchr(string: (unsigned __int8 *)form, chr: 0x2Eu);
            if ( v13 != 0 || l < 0x64 )
            {
              sprintf(string: buff, format: form, HIDWORD(v21));
LABEL_21:
              luaL_addlstring(B: &b, s: buff, l: strlen(buff));
            }
            else
            {
              lua_pushvalue(L, idx: v1);
              luaL_addvalue(B: (unsigned int)&b);
            }
            break;
          default:
            luaL_error(L, fmt: "invalid option '%%%c' to 'format'", *(v2 - 1));
        }
      }
    }
    else
    {
      if ( b.p >= (char *)&sfl )
        luaL_prepbuffer(B: &b);
      *b.p++ = *v2++;
    }
  }
  luaL_pushresult(B: &b);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004808A0
// Name: int luaopen_string(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_string(lua_State *L)
{
  luaL_register(L, libname: "string", l: strlib);
  lua_getfield(L, idx: -1, k: "gmatch");
  lua_setfield(L, idx: -2, k: "gfind");
  lua_createtable(L, narray: 0, nrec: 1);
  lua_pushlstring(L, s: var, len: 0);
  lua_pushvalue(L, idx: -2);
  lua_setmetatable(L, objindex: -2);
  lua_settop(L, idx: -2);
  lua_pushvalue(L, idx: -2);
  lua_setfield(L, idx: -2, k: "__index");
  lua_settop(L, idx: -2);
  return 1;
}
