// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lobject.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00476D20
// Name: int luaO_int2fb(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl luaO_int2fb(unsigned int x)
{
  unsigned int v1; // ecx
  int i; // eax

  v1 = x;
  for ( i = 0; v1 >= 0x10; ++i )
    v1 = (v1 + 1) >> 1;
  if ( v1 >= 8 )
    return (v1 - 8) | (8 * i + 8);
  else
    return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00476D50
// Name: int luaO_fb2int(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaO_fb2int(int x)
{
  int result; // eax

  result = x;
  if ( ((x >> 3) & 0x1F) != 0 )
    return ((x & 7) + 8) << (((x >> 3) & 0x1F) - 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476D70
// Name: int luaO_log2(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaO_log2(unsigned int x)
{
  unsigned int v1; // eax
  int i; // ecx

  v1 = x;
  for ( i = -1; v1 >= 0x100; i += 8 )
    v1 >>= 8;
  return i + log_2[v1];
}

//------------------------------------------------------------------------------
// Address: 0x00476DA0
// Name: int luaO_rawequalObj(struct lua_TValue const __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl luaO_rawequalObj(const lua_TValue *t1, const lua_TValue *t2)
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
// Address: 0x00476E00
// Name: int luaO_str2d(char const __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl luaO_str2d(char *s, long double *result)
{
  const char *v2; // esi
  long double v3; // st7
  char *v4; // eax
  double *v5; // edi
  unsigned __int8 v7; // al

  v2 = s;
  v3 = strtod(nptr: s, endptr: &s);
  v4 = s;
  v5 = result;
  *result = v3;
  if ( v4 == v2 )
    return false;
  if ( *v4 == 120 || *v4 == 88 )
  {
    result = (long double *)strtoul(nptr: v2, endptr: &s, ibase: 16);
    v4 = s;
    *v5 = (double)(unsigned int)result;
  }
  v7 = *v4;
  if ( v7 == 0 )
    return true;
  if ( isspace(c: v7) != 0 )
  {
    do
      ++s;
    while ( isspace(c: (unsigned __int8)*s) != 0 );
  }
  return *s == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00476EA0
// Name: char const __near * luaO_pushvfstring(struct lua_State __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl luaO_pushvfstring(lua_TValue *L, char *fmt, char *argp)
{
  lua_State *v3; // esi
  lua_TValue *tt; // edi
  int v5; // ebx
  char *v6; // edi
  const char *v7; // eax
  int *top; // ebx
  int *v9; // edi
  const char *v10; // ecx
  unsigned __int8 v11; // cl
  unsigned int v12; // eax
  char *p_L; // edx
  __m128i v14; // xmm0
  char *v15; // eax
  int v16; // ecx
  bool v17; // cc
  double v18; // st7
  char *v19; // eax
  int v20; // edx
  const char *v21; // eax
  GCObject *v22; // eax
  lua_State *v23; // ecx
  char string[24]; // [esp+Ch] [ebp-2Ch] BYREF
  int n; // [esp+24h] [ebp-14h]
  const char *e; // [esp+28h] [ebp-10h]
  char *v28; // [esp+2Ch] [ebp-Ch]
  char *v29; // [esp+30h] [ebp-8h]
  char v30[4]; // [esp+34h] [ebp-4h] BYREF

  v3 = (lua_State *)L;
  tt = (lua_TValue *)L->tt;
  v5 = 1;
  n = 1;
  tt->value.b = (int)luaS_newlstr((lua_State *)L, str: var, l: 0);
  tt->tt = 4;
  if ( (char *)v3->stack_last - (char *)v3->top <= 16 )
    luaD_growstack(L: v3, n: 1);
  v6 = fmt;
  ++v3->top;
  strchr(string: (unsigned __int8 *)v6, chr: 0x25u);
  e = v7;
  if ( v7 != nullptr )
  {
    v28 = argp - 4;
    v29 = argp - 8;
    while ( 1 )
    {
      top = (int *)v3->top;
      *top = (int)luaS_newlstr(L: v3, str: v6, l: v7 - v6);
      top[2] = 4;
      if ( (char *)v3->stack_last - (char *)v3->top <= 16 )
        luaD_growstack(L: v3, n: 1);
      v9 = (int *)++v3->top;
      switch ( e[1] )
      {
        case '%':
          *v9 = (int)luaS_newlstr(L: v3, str: "%", l: 1u);
          v9[2] = 4;
          v17 = (char *)v3->stack_last - (char *)v3->top <= 16;
          goto LABEL_21;
        case 'c':
          v29 += 4;
          v11 = v28[4];
          v28 += 4;
          LOWORD(L) = v11;
          v12 = strlen((const char *)&L);
          p_L = (char *)&L;
          goto LABEL_20;
        case 'd':
          v14 = _mm_cvtsi32_si128(*((_DWORD *)v28 + 1));
          v29 += 4;
          v15 = v28 + 4;
          *(double *)v9 = _mm_cvtepi32_pd(v14).m128d_f64[0];
          v9[2] = 3;
          v16 = (char *)v3->stack_last - (char *)v3->top;
          v28 = v15;
          v17 = v16 <= 16;
          goto LABEL_21;
        case 'f':
          v18 = *((double *)v29 + 1);
          v28 += 8;
          v19 = v29 + 8;
          *(double *)v9 = v18;
          v9[2] = 3;
          v20 = (char *)v3->stack_last - (char *)v3->top;
          v29 = v19;
          v17 = v20 <= 16;
          goto LABEL_21;
        case 'p':
          v29 += 4;
          v28 += 4;
          sprintf(string, format: "%p", *(const void **)v28);
          v9 = (int *)v3->top;
          v12 = strlen(string);
          p_L = string;
          goto LABEL_20;
        case 's':
          v10 = *((const char **)v28 + 1);
          v29 += 4;
          v28 += 4;
          if ( v10 == nullptr )
            v10 = "(null)";
          *v9 = (int)luaS_newlstr(L: v3, str: v10, l: strlen(v10));
          v9[2] = 4;
          if ( (char *)v3->stack_last - (char *)v3->top <= 16 )
            luaD_growstack(L: v3, n: 1);
          ++v3->top;
          goto LABEL_24;
        default:
          v30[1] = e[1];
          v30[0] = 37;
          v30[2] = 0;
          v12 = strlen(v30);
          p_L = v30;
LABEL_20:
          *v9 = (int)luaS_newlstr(L: v3, str: p_L, l: v12);
          v9[2] = 4;
          v17 = (char *)v3->stack_last - (char *)v3->top <= 16;
LABEL_21:
          if ( v17 )
            luaD_growstack(L: v3, n: 1);
          ++v3->top;
LABEL_24:
          n += 2;
          v6 = (char *)(e + 2);
          strchr(string: (unsigned __int8 *)e + 2, chr: 0x25u);
          e = v21;
          if ( v21 == nullptr )
          {
            v5 = n;
            goto LABEL_26;
          }
          v7 = e;
          break;
      }
    }
  }
LABEL_26:
  L = v3->top;
  v22 = (GCObject *)luaS_newlstr(L: v3, str: v6, l: strlen(v6));
  v23 = (lua_State *)L;
  L->value.b = (int)v22;
  v23->top = (lua_TValue *)4;
  if ( (char *)v3->stack_last - (char *)v3->top <= 16 )
    luaD_growstack(L: v3, n: 1);
  luaV_concat(L: v3, total: v5 + 1, last: ++v3->top - v3->base - 1);
  v3->top -= v5;
  return (const char *)(v3->top[-1].value.b + 16);
}

//------------------------------------------------------------------------------
// Address: 0x00477200
// Name: char const __near * luaO_pushfstring(struct lua_State __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
const char *luaO_pushfstring(lua_TValue *L, char *fmt, ...)
{
  va_list argp; // [esp+10h] [ebp+10h] BYREF

  va_start(argp, fmt);
  return luaO_pushvfstring(L, fmt, argp);
}

//------------------------------------------------------------------------------
// Address: 0x00477220
// Name: void luaO_chunkid(char __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaO_chunkid(char *out, char *source, unsigned int bufflen)
{
  const char *v3; // esi
  unsigned int v4; // eax
  size_t v5; // eax

  if ( *source == 61 )
  {
    strncpy(dest: (unsigned __int8 *)out, source: (unsigned __int8 *)source + 1, count: bufflen);
    out[bufflen - 1] = 0;
  }
  else if ( *source == 64 )
  {
    v3 = source + 1;
    v4 = strlen(source + 1);
    *out = 0;
    if ( v4 > bufflen - 8 )
    {
      v3 += v4 - (bufflen - 8);
      strcat(out, "...");
    }
    strcat(out, v3);
  }
  else
  {
    strcspn(string: (unsigned __int8 *)source, control: "\n\r");
    *(_QWORD *)out = *(_QWORD *)aString_2;
    if ( v5 > bufflen - 17 )
      v5 = bufflen - 17;
    *((_WORD *)out + 4) = 34;
    if ( source[v5] != 0 )
    {
      strncat(Destination: out, Source: source, Count: v5);
      strcat(out, "...");
    }
    else
    {
      strcat(out, source);
    }
    strcat(out, "\"]");
  }
}
