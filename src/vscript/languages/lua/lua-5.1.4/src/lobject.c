// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lobject.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10013510
// Name: _luaO_rawequalObj
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall luaO_rawequalObj@<eax>(const lua_TValue *t1@<ecx>, const lua_TValue *t2@<eax>)
{
  int tt; // edx
  BOOL result; // eax

  tt = t1->tt;
  if ( tt != t2->tt )
    return false;
  switch ( tt )
  {
    case 0:
      result = true;
      break;
    case 3:
      if ( t1->value.n != t2->value.n )
        return false;
      result = true;
      break;
    default:
      result = t1->value.b == t2->value.b;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013560
// Name: _luaO_str2d
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall luaO_str2d@<eax>(char *s@<esi>, long double *result@<edi>)
{
  char *v2; // eax
  double v4; // st7
  unsigned __int8 v5; // al
  char *endptr; // [esp+4h] [ebp-4h] BYREF

  *result = strtod(nptr: s, &endptr);
  v2 = endptr;
  if ( endptr == s )
    return false;
  if ( *endptr == 120 || *endptr == 88 )
  {
    v4 = (double)strtoul(nptr: s, &endptr, ibase: 16);
    v2 = endptr;
    *result = v4;
  }
  v5 = *v2;
  if ( v5 == 0 )
    return true;
  if ( isspace(c: v5) != 0 )
  {
    do
      ++endptr;
    while ( isspace(c: (unsigned __int8)*endptr) != 0 );
  }
  return *endptr == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013600
// Name: pushstr
// Source: json
//------------------------------------------------------------------------------
void __usercall pushstr(lua_State *L@<eax>, const char *str@<edx>)
{
  lua_TValue *top; // edi
  int stacksize; // eax

  top = L->top;
  top->value.b = (int)luaS_newlstr(L, str, l: strlen(str));
  top->tt = 4;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    if ( stacksize >= 1 )
    {
      luaD_reallocstack(L, newsize: 2 * stacksize);
      ++L->top;
      return;
    }
    luaD_reallocstack(L, newsize: stacksize + 1);
  }
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10013660
// Name: _luaO_pushvfstring
// Source: json
//------------------------------------------------------------------------------
const char *__usercall luaO_pushvfstring@<eax>(lua_State *L@<ecx>, char *fmt@<eax>, char *argp)
{
  lua_TValue *top; // eax
  int v6; // ebx
  TString *v7; // eax
  const char *v8; // ecx
  int stacksize; // eax
  int v10; // eax
  const char *v11; // eax
  lua_TValue *v12; // ebx
  int v13; // eax
  lua_TValue *stack; // ecx
  int v15; // edi
  int v16; // ebx
  lua_TValue *v17; // eax
  lua_TValue *v18; // edx
  const char *v19; // eax
  char v20; // al
  lua_TValue *v21; // edi
  const char *v22; // edx
  char v23; // dl
  __m128i v24; // xmm0
  int v25; // eax
  long double v26; // st7
  char *v27; // eax
  int v28; // ecx
  int v29; // eax
  lua_TValue *v30; // ecx
  int v31; // edi
  int v32; // ebx
  lua_TValue *v33; // eax
  lua_TValue *v34; // edx
  const char *v35; // eax
  const void *v37; // [esp-4h] [ebp-44h]
  char buff[4]; // [esp+Ch] [ebp-34h] BYREF
  char str[4]; // [esp+10h] [ebp-30h] BYREF
  char *v40; // [esp+14h] [ebp-2Ch]
  char *v41; // [esp+18h] [ebp-28h]
  lua_TValue *oldstack; // [esp+1Ch] [ebp-24h]
  const char *e; // [esp+20h] [ebp-20h]
  int n; // [esp+24h] [ebp-1Ch]
  char string[24]; // [esp+28h] [ebp-18h] BYREF

  top = L->top;
  v6 = 1;
  n = 1;
  e = (const char *)top;
  v7 = luaS_newlstr(L, str: Ptr, l: 0);
  v8 = e;
  *(_DWORD *)e = v7;
  *((_DWORD *)v8 + 2) = 4;
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    if ( stacksize < 1 )
      v10 = stacksize + 1;
    else
      v10 = 2 * stacksize;
    luaD_reallocstack(L, newsize: v10);
  }
  ++L->top;
  strchr(string: (unsigned __int8 *)fmt, chr: 0x25u);
  e = v11;
  if ( v11 != nullptr )
  {
    v41 = argp - 4;
    v40 = argp - 8;
    while ( 1 )
    {
      v12 = L->top;
      v12->value.b = (int)luaS_newlstr(L, str: fmt, l: v11 - fmt);
      v12->tt = 4;
      if ( (char *)L->stack_last - (char *)L->top <= 16 )
      {
        v13 = L->stacksize;
        stack = L->stack;
        oldstack = stack;
        if ( v13 < 1 )
        {
          v15 = v13 + 1;
          v16 = v13 + 7;
          if ( (unsigned int)(v13 + 8) > 0xFFFFFFF )
LABEL_14:
            luaG_runerror(L, fmt: "memory allocation error: block too big");
        }
        else
        {
          v15 = 2 * v13;
          v16 = 2 * v13 + 6;
          if ( (unsigned int)(2 * v13 + 7) > 0xFFFFFFF )
            goto LABEL_14;
        }
        v17 = (lua_TValue *)luaM_realloc_(L, block: stack, osize: 16 * v13, nsize: 16 * v16);
        v18 = oldstack;
        L->stack = v17;
        L->stacksize = v16;
        L->stack_last = &v17[v15];
        correctstack(L, oldstack: v18);
      }
      v19 = e;
      ++L->top;
      v20 = v19[1];
      v21 = L->top;
      switch ( v20 )
      {
        case '%':
          pushstr(L, str: "%");
          goto LABEL_37;
        case 'c':
          v40 += 4;
          v23 = v41[4];
          v41 += 4;
          buff[0] = v23;
          buff[1] = 0;
          pushstr(L, str: buff);
          goto LABEL_37;
        case 'd':
          v24 = _mm_cvtsi32_si128(*((_DWORD *)v41 + 1));
          v40 += 4;
          v41 += 4;
          v21->value.n = _mm_cvtepi32_pd(v24).m128d_f64[0];
          v21->tt = 3;
          if ( (char *)L->stack_last - (char *)L->top > 16 )
            goto LABEL_24;
          v25 = L->stacksize;
          if ( v25 >= 1 )
            goto LABEL_22;
          goto LABEL_23;
        case 'f':
          v26 = *((double *)v40 + 1);
          v41 += 8;
          v27 = v40 + 8;
          v21->value.n = v26;
          v21->tt = 3;
          v28 = (char *)L->stack_last - (char *)L->top;
          v40 = v27;
          if ( v28 > 16 )
            goto LABEL_24;
          v25 = L->stacksize;
          if ( v25 < 1 )
          {
LABEL_23:
            luaD_reallocstack(L, newsize: v25 + 1);
LABEL_24:
            ++L->top;
          }
          else
          {
LABEL_22:
            luaD_reallocstack(L, newsize: 2 * v25);
            ++L->top;
          }
          goto LABEL_37;
        case 'p':
          v40 += 4;
          v37 = *((const void **)v41 + 1);
          v41 += 4;
          sprintf(string, format: "%p", v37);
          pushstr(L, str: string);
          goto LABEL_37;
        case 's':
          v40 += 4;
          v22 = *((const char **)v41 + 1);
          v41 += 4;
          if ( v22 == nullptr )
            v22 = "(null)";
          pushstr(L, str: v22);
          goto LABEL_37;
        default:
          str[1] = v20;
          str[0] = 37;
          str[2] = 0;
          v21->value.b = (int)luaS_newlstr(L, str, l: strlen(str));
          v21->tt = 4;
          if ( (char *)L->stack_last - (char *)L->top > 16 )
            goto LABEL_36;
          v29 = L->stacksize;
          v30 = L->stack;
          oldstack = v30;
          if ( v29 < 1 )
          {
            v31 = v29 + 1;
            v32 = v29 + 7;
            if ( (unsigned int)(v29 + 8) > 0xFFFFFFF )
LABEL_35:
              luaG_runerror(L, fmt: "memory allocation error: block too big");
          }
          else
          {
            v31 = 2 * v29;
            v32 = 2 * v29 + 6;
            if ( (unsigned int)(2 * v29 + 7) > 0xFFFFFFF )
              goto LABEL_35;
          }
          v33 = (lua_TValue *)luaM_realloc_(L, block: v30, osize: 16 * v29, nsize: 16 * v32);
          v34 = oldstack;
          L->stack = v33;
          L->stacksize = v32;
          L->stack_last = &v33[v31];
          correctstack(L, oldstack: v34);
LABEL_36:
          ++L->top;
LABEL_37:
          n += 2;
          fmt = (char *)(e + 2);
          strchr(string: (unsigned __int8 *)e + 2, chr: 0x25u);
          e = v35;
          if ( v35 == nullptr )
          {
            v6 = n;
            goto LABEL_39;
          }
          v11 = e;
          break;
      }
    }
  }
LABEL_39:
  pushstr(L, str: fmt);
  luaV_concat(L, total: v6 + 1, last: L->top - L->base - 1);
  L->top -= v6;
  return (const char *)(L->top[-1].value.b + 24);
}

//------------------------------------------------------------------------------
// Address: 0x10013A90
// Name: _luaO_pushfstring
// Source: json
//------------------------------------------------------------------------------
const char *luaO_pushfstring(lua_State *L, char *fmt, ...)
{
  va_list argp; // [esp+10h] [ebp+10h] BYREF

  va_start(argp, fmt);
  return luaO_pushvfstring(L, fmt, argp);
}

//------------------------------------------------------------------------------
// Address: 0x10013AB0
// Name: _luaO_chunkid
// Source: json
//------------------------------------------------------------------------------
void __usercall luaO_chunkid(char *source@<ecx>, unsigned int bufflen@<eax>, char *out)
{
  const char *v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // eax
  size_t v8; // eax
  size_t v9; // edi

  if ( *source == 61 )
  {
    strncpy(dest: (unsigned __int8 *)out, source: (unsigned __int8 *)source + 1, count: bufflen);
    out[bufflen - 1] = 0;
  }
  else if ( *source == 64 )
  {
    v5 = source + 1;
    v6 = bufflen - 8;
    v7 = strlen(source + 1);
    *out = 0;
    if ( v7 > v6 )
    {
      v5 += v7 - v6;
      strcat(out, "...");
    }
    strcat(out, v5);
  }
  else
  {
    strcspn(string: (unsigned __int8 *)source, control: "\n\r");
    v9 = bufflen - 17;
    *(_QWORD *)out = *(_QWORD *)aString_3;
    if ( v8 > v9 )
      v8 = v9;
    *((_WORD *)out + 4) = 34;
    if ( source[v8] != 0 )
    {
      strncat(Destination: out, Source: source, Count: v8);
      strcat(out, "...");
    }
    else
    {
      strcat(out, source);
    }
    strcat(out, "\"]");
  }
}
