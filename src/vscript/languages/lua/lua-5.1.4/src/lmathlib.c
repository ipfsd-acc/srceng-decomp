// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lmathlib.c
// Functions: 44
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10010840
// Name: math_abs
// Source: json
//------------------------------------------------------------------------------
int __usercall math_abs@<eax>(__int64 a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  *(_QWORD *)&top->value.n = a1 & _mask__AbsDouble_;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010880
// Name: math_sin
// Source: json
//------------------------------------------------------------------------------
int __usercall math_sin@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_sin(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100108C0
// Name: math_sinh
// Source: json
//------------------------------------------------------------------------------
int __usercall math_sinh@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  top->value.n = sinh(a1);
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010910
// Name: math_cos
// Source: json
//------------------------------------------------------------------------------
int __usercall math_cos@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_cos(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010950
// Name: math_cosh
// Source: json
//------------------------------------------------------------------------------
int __usercall math_cosh@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  top->value.n = cosh(a1);
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100109A0
// Name: math_tan
// Source: json
//------------------------------------------------------------------------------
int __usercall math_tan@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_tan(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100109E0
// Name: math_tanh
// Source: json
//------------------------------------------------------------------------------
int __usercall math_tanh@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  top->value.n = tanh(a1);
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010A30
// Name: math_asin
// Source: json
//------------------------------------------------------------------------------
int __usercall math_asin@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_asin(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010A70
// Name: math_acos
// Source: json
//------------------------------------------------------------------------------
int __usercall math_acos@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_acos(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010AB0
// Name: math_atan
// Source: json
//------------------------------------------------------------------------------
int __usercall math_atan@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_atan(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010AF0
// Name: math_atan2
// Source: json
//------------------------------------------------------------------------------
int __usercall math_atan2@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-10h]

  luaL_checknumber(L, narg: 1);
  luaL_checknumber(L, narg: 2);
  __libm_sse2_atan2(y: v4, x: a1);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010B50
// Name: math_ceil
// Source: json
//------------------------------------------------------------------------------
int __usercall math_ceil@<eax>(double X@<xmm0>, lua_State *L)
{
  double v2; // st7
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  v2 = ceil(X);
  top = L->top;
  top->value.n = v2;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010B90
// Name: math_floor
// Source: json
//------------------------------------------------------------------------------
int __usercall math_floor@<eax>(__m128d a1@<xmm0>, lua_State *L)
{
  __m128d v2; // xmm2
  lua_TValue *top; // eax
  __m128d v4; // xmm3
  double v5; // xmm1_8
  double v6; // xmm1_8

  luaL_checknumber(L, narg: 1);
  v2.m128d_f64[0] = 4.503599627370496e15;
  top = L->top;
  v4 = _mm_and_pd((__m128d)0x8000000000000000uLL, a1);
  v5 = _mm_cmplt_sd(_mm_xor_pd(a1, v4), v2).m128d_f64[0];
  v6 = a1.m128d_f64[0]
     + COERCE_DOUBLE(*(_QWORD *)&v5 & 0x4330000000000000LL | *(_QWORD *)&v4.m128d_f64[0])
     - COERCE_DOUBLE(*(_QWORD *)&v5 & 0x4330000000000000LL | *(_QWORD *)&v4.m128d_f64[0]);
  v2.m128d_f64[1] = a1.m128d_f64[1];
  v2.m128d_f64[0] = v6 - a1.m128d_f64[0];
  top->value.n = v6 - COERCE_DOUBLE(*(_QWORD *)&_mm_cmpgt_sd(v2, v4).m128d_f64[0] & 0x3FF0000000000000LL);
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010C20
// Name: math_fmod
// Source: json
//------------------------------------------------------------------------------
int __usercall math_fmod@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  luaL_checknumber(L, narg: 2);
  top = L->top;
  top->value.n = fmod(a1, a1);
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010C80
// Name: math_modf
// Source: json
//------------------------------------------------------------------------------
int __usercall math_modf@<eax>(double X@<xmm0>, lua_State *L)
{
  double v2; // st7
  lua_TValue *top; // eax
  lua_TValue *v4; // eax
  long double Y; // [esp+44h] [ebp-8h] BYREF

  luaL_checknumber(L, narg: 1);
  v2 = modf(X, &Y);
  top = L->top;
  top->value.n = Y;
  top->tt = 3;
  v4 = ++L->top;
  v4->value.n = v2;
  v4->tt = 3;
  ++L->top;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10010CE0
// Name: math_sqrt
// Source: json
//------------------------------------------------------------------------------
int __usercall math_sqrt@<eax>(double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  top->value.n = sqrt(a1);
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010D20
// Name: math_pow
// Source: json
//------------------------------------------------------------------------------
int __usercall math_pow@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-10h]

  luaL_checknumber(L, narg: 1);
  luaL_checknumber(L, narg: 2);
  __libm_sse2_pow(x: v4, y: a1);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010D80
// Name: math_log
// Source: json
//------------------------------------------------------------------------------
int __usercall math_log@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_log(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010DC0
// Name: math_log10
// Source: json
//------------------------------------------------------------------------------
int __usercall math_log10@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_log10(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010E00
// Name: math_exp
// Source: json
//------------------------------------------------------------------------------
int __usercall math_exp@<eax>(long double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax
  long double v4; // [esp+0h] [ebp-8h]

  luaL_checknumber(L, narg: 1);
  __libm_sse2_exp(x: v4);
  top = L->top;
  top->value.n = a1;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010E40
// Name: math_deg
// Source: json
//------------------------------------------------------------------------------
int __usercall math_deg@<eax>(double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  top->value.n = a1 * 57.29577951308232;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010E80
// Name: math_rad
// Source: json
//------------------------------------------------------------------------------
int __usercall math_rad@<eax>(double a1@<xmm0>, lua_State *L)
{
  lua_TValue *top; // eax

  luaL_checknumber(L, narg: 1);
  top = L->top;
  top->value.n = a1 * 0.0174532925199433;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010EC0
// Name: math_frexp
// Source: json
//------------------------------------------------------------------------------
int __usercall math_frexp@<eax>(long double x@<xmm0>, lua_State *L)
{
  long double v2; // st7
  lua_TValue *top; // eax
  __m128i v4; // xmm0
  lua_TValue *v5; // eax
  int e; // [esp+48h] [ebp-4h] BYREF

  luaL_checknumber(L, narg: 1);
  v2 = frexp(x, expptr: &e);
  top = L->top;
  top->value.n = v2;
  top->tt = 3;
  v4 = _mm_cvtsi32_si128(e);
  v5 = ++L->top;
  v5->value.n = _mm_cvtepi32_pd(v4).m128d_f64[0];
  v5->tt = 3;
  ++L->top;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10010F20
// Name: math_ldexp
// Source: json
//------------------------------------------------------------------------------
int __usercall math_ldexp@<eax>(long double x@<xmm0>, lua_State *L)
{
  long double v2; // st7
  lua_TValue *top; // eax
  int v5; // [esp+8h] [ebp-44h]

  v5 = luaL_checkinteger(L, narg: 2);
  luaL_checknumber(L, narg: 1);
  v2 = ldexp(x, exp: v5);
  top = L->top;
  top->value.n = v2;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010F70
// Name: math_min
// Source: json
//------------------------------------------------------------------------------
int __usercall math_min@<eax>(double a1@<xmm0>, lua_State *L)
{
  int v2; // esi
  int v3; // eax
  double v4; // xmm1_8
  lua_TValue *v5; // eax
  int tt; // ecx
  double n; // xmm0_8
  lua_TValue *v8; // eax
  int v9; // ecx
  lua_TValue *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  lua_TValue *top; // eax
  int i; // [esp+10h] [ebp-38h]
  long double v17; // [esp+18h] [ebp-30h]
  double dmin; // [esp+20h] [ebp-28h]
  long double v19; // [esp+28h] [ebp-20h] BYREF
  long double v20; // [esp+30h] [ebp-18h] BYREF
  long double v21; // [esp+38h] [ebp-10h] BYREF
  int v22; // [esp+40h] [ebp-8h]

  v2 = L->top - L->base;
  luaL_checknumber(L, narg: 1);
  v3 = 2;
  v4 = a1;
  dmin = a1;
  for ( i = 2; v3 <= v2; i = v3 )
  {
    v5 = index2adr(L, idx: v3);
    tt = v5->tt;
    if ( tt != 3 )
    {
      if ( tt != 4 || luaO_str2d(s: (const char *)(v5->value.b + 24), result: &v19) == 0 )
      {
        n = 0.0;
        v17 = 0.0;
LABEL_7:
        v8 = index2adr(L, idx: i);
        v9 = v8->tt;
        if ( v9 != 3 )
        {
          if ( v9 != 4 || luaO_str2d(s: (const char *)(v8->value.b + 24), result: &v20) == 0 )
          {
            v10 = index2adr(L, idx: i);
            if ( v10 == &luaO_nilobject_ || (v11 = v10->tt) == -1 )
              v12 = "no value";
            else
              v12 = luaT_typenames[v11];
            v13 = lua_pushfstring(L, fmt: "%s expected, got %s", "number", v12);
            luaL_argerror(L, extramsg: v13, narg: i);
          }
          n = v17;
        }
        goto LABEL_17;
      }
      v21 = v19;
      v22 = 3;
      v5 = (lua_TValue *)&v21;
    }
    n = v5->value.n;
    v17 = v5->value.n;
    if ( v5->value.n == 0.0 )
      goto LABEL_7;
LABEL_17:
    v4 = dmin;
    if ( dmin > n )
    {
      v4 = n;
      dmin = n;
    }
    v3 = i + 1;
  }
  top = L->top;
  top->value.n = v4;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100110E0
// Name: math_max
// Source: json
//------------------------------------------------------------------------------
int __usercall math_max@<eax>(double a1@<xmm0>, lua_State *L)
{
  int v2; // esi
  int v3; // eax
  double v4; // xmm1_8
  lua_TValue *v5; // eax
  int tt; // ecx
  double n; // xmm0_8
  lua_TValue *v8; // eax
  int v9; // ecx
  lua_TValue *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  lua_TValue *top; // eax
  int i; // [esp+10h] [ebp-38h]
  long double v17; // [esp+18h] [ebp-30h]
  double dmax; // [esp+20h] [ebp-28h]
  long double v19; // [esp+28h] [ebp-20h] BYREF
  long double v20; // [esp+30h] [ebp-18h] BYREF
  long double v21; // [esp+38h] [ebp-10h] BYREF
  int v22; // [esp+40h] [ebp-8h]

  v2 = L->top - L->base;
  luaL_checknumber(L, narg: 1);
  v3 = 2;
  v4 = a1;
  dmax = a1;
  for ( i = 2; v3 <= v2; i = v3 )
  {
    v5 = index2adr(L, idx: v3);
    tt = v5->tt;
    if ( tt != 3 )
    {
      if ( tt != 4 || luaO_str2d(s: (const char *)(v5->value.b + 24), result: &v19) == 0 )
      {
        n = 0.0;
        v17 = 0.0;
LABEL_7:
        v8 = index2adr(L, idx: i);
        v9 = v8->tt;
        if ( v9 != 3 )
        {
          if ( v9 != 4 || luaO_str2d(s: (const char *)(v8->value.b + 24), result: &v20) == 0 )
          {
            v10 = index2adr(L, idx: i);
            if ( v10 == &luaO_nilobject_ || (v11 = v10->tt) == -1 )
              v12 = "no value";
            else
              v12 = luaT_typenames[v11];
            v13 = lua_pushfstring(L, fmt: "%s expected, got %s", "number", v12);
            luaL_argerror(L, extramsg: v13, narg: i);
          }
          n = v17;
        }
        goto LABEL_17;
      }
      v21 = v19;
      v22 = 3;
      v5 = (lua_TValue *)&v21;
    }
    n = v5->value.n;
    v17 = v5->value.n;
    if ( v5->value.n == 0.0 )
      goto LABEL_7;
LABEL_17:
    v4 = dmax;
    if ( n > dmax )
    {
      v4 = n;
      dmax = n;
    }
    v3 = i + 1;
  }
  top = L->top;
  top->value.n = v4;
  top->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011250
// Name: math_random
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_random(lua_State *L)
{
  int v1; // edx
  lua_TValue *top; // ecx
  signed int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  __m128d v7; // xmm2
  lua_TValue *v8; // eax
  __m128d v9; // xmm0
  __m128d v10; // xmm3
  double v11; // xmm1_8
  double v12; // xmm1_8
  int v14; // ebx
  __m128d v15; // xmm2
  lua_TValue *v16; // eax
  __m128d v17; // xmm0
  __m128d v18; // xmm3
  double v19; // xmm1_8
  double v20; // xmm1_8
  double r; // [esp+10h] [ebp-8h]

  v1 = rand() % 0x7FFF;
  top = L->top;
  v3 = top - L->base;
  r = (double)v1 * 0.00003051850947599719;
  if ( v3 != 0 )
  {
    v4 = v3 - 1;
    if ( v4 != 0 )
    {
      if ( v4 != 1 )
        luaL_error(L, fmt: "wrong number of arguments");
      v5 = luaL_checkinteger(L, narg: 1);
      v6 = luaL_checkinteger(L, narg: 2);
      if ( v5 > v6 )
        luaL_argerror(L, extramsg: "interval is empty", narg: 2);
      v7.m128d_f64[0] = 4.503599627370496e15;
      v8 = L->top;
      v9 = 0;
      v9.m128d_f64[0] = (double)(v6 - v5 + 1) * r;
      v10 = _mm_and_pd((__m128d)0x8000000000000000uLL, v9);
      v11 = _mm_cmplt_sd(_mm_xor_pd(v9, v10), v7).m128d_f64[0];
      v12 = v9.m128d_f64[0]
          + COERCE_DOUBLE(*(_QWORD *)&v11 & 0x4330000000000000LL | *(_QWORD *)&v10.m128d_f64[0])
          - COERCE_DOUBLE(*(_QWORD *)&v11 & 0x4330000000000000LL | *(_QWORD *)&v10.m128d_f64[0]);
      v8->value.n = v12
                  - COERCE_DOUBLE(
                      *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v12 - v9.m128d_f64[0]), v10).m128d_f64[0]
                    & 0x3FF0000000000000LL)
                  + (double)v5;
      v8->tt = 3;
      ++L->top;
      return 1;
    }
    else
    {
      v14 = luaL_checkinteger(L, narg: 1);
      if ( v14 < 1 )
        luaL_argerror(L, extramsg: "interval is empty", narg: 1);
      v15.m128d_f64[0] = 4.503599627370496e15;
      v16 = L->top;
      v17 = 0;
      v17.m128d_f64[0] = (double)v14 * r;
      v18 = _mm_and_pd((__m128d)0x8000000000000000uLL, v17);
      v19 = _mm_cmplt_sd(_mm_xor_pd(v17, v18), v15).m128d_f64[0];
      v20 = v17.m128d_f64[0]
          + COERCE_DOUBLE(*(_QWORD *)&v19 & 0x4330000000000000LL | *(_QWORD *)&v18.m128d_f64[0])
          - COERCE_DOUBLE(*(_QWORD *)&v19 & 0x4330000000000000LL | *(_QWORD *)&v18.m128d_f64[0]);
      v16->value.n = v20
                   - COERCE_DOUBLE(
                       *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v20 - v17.m128d_f64[0]), v18).m128d_f64[0]
                     & 0x3FF0000000000000LL)
                   + 1.0;
      v16->tt = 3;
      ++L->top;
      return 1;
    }
  }
  else
  {
    top->value.n = (double)v1 * 0.00003051850947599719;
    top->tt = 3;
    ++L->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011440
// Name: math_randomseed
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_randomseed(lua_State *L)
{
  unsigned int v1; // eax

  v1 = luaL_checkinteger(L, narg: 1);
  srand(seed: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011460
// Name: _luaopen_math
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_math(lua_State *L)
{
  lua_TValue *top; // eax
  const lua_TValue *v2; // edi
  lua_TValue *v3; // eax
  const lua_TValue *v4; // edi
  TString *v5; // eax
  const lua_TValue *v6; // edi
  TString *v7; // eax
  const lua_TValue *v8; // edi
  lua_TValue *v10; // [esp-4h] [ebp-24h]
  lua_TValue *v11; // [esp-4h] [ebp-24h]
  lua_TValue *v12; // [esp-4h] [ebp-24h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  luaL_openlib(L, libname: "math", l: mathlib);
  top = L->top;
  top->value.n = 3.141592653589793;
  top->tt = 3;
  v2 = ++L->top - 2;
  key.value.b = (int)luaS_newlstr(L, str: "pi", l: 2u);
  v10 = L->top - 1;
  key.tt = 4;
  luaV_settable(L, t: v2, &key, val: v10);
  v3 = --L->top;
  v3->value.n = _HUGE;
  v3->tt = 3;
  v4 = ++L->top - 2;
  v5 = luaS_newlstr(L, str: "huge", l: 4u);
  v11 = L->top - 1;
  key.value.b = (int)v5;
  key.tt = 4;
  luaV_settable(L, t: v4, &key, val: v11);
  v6 = --L->top - 1;
  v7 = luaS_newlstr(L, str: "fmod", l: 4u);
  v12 = L->top;
  key.value.b = (int)v7;
  key.tt = 4;
  luaV_gettable(L, t: v6, &key, val: v12);
  v8 = ++L->top - 2;
  key.value.b = (int)luaS_newlstr(L, str: "mod", l: 3u);
  key.tt = 4;
  luaV_settable(L, t: v8, &key, val: L->top - 1);
  --L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031B90
// Name: math_abs_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_abs_0(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // esi
  tagSQObjectType type; // edx
  int v4; // eax
  SQVM *v5; // eax
  int top; // edx
  tagSQObjectType v7; // edi
  _DWORD *v8; // ecx

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      v5 = (SQVM *)(int)*(float *)(v4 + 4);
    else
      v5 = *(SQVM **)(v4 + 4);
  }
  else
  {
    v5 = v;
  }
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.nInteger = abs32((int)v5);
  vals[top]._type = OT_INTEGER;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031C10
// Name: math_sqrt_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_sqrt_0(SQVM *v)
{
  SQObjectPtr *vals; // edx
  int stackbase; // eax
  tagSQObjectType type; // esi
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // esi
  _DWORD *v8; // ecx

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = fsqrt(v5);
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031D30
// Name: math_sin_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_sin_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_sin(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031DD0
// Name: math_cos_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_cos_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_cos(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031E70
// Name: math_asin_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_asin_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_asin(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031F10
// Name: math_acos_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_acos_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_acos(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031FB0
// Name: math_log_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_log_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_log(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032050
// Name: math_log10_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_log10_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_log10(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100320F0
// Name: math_tan_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_tan_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_tan(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032190
// Name: math_atan_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_atan_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_atan(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032230
// Name: math_atan2_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_atan2_0(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // esi
  tagSQObjectType type; // ecx
  float nInteger; // xmm0_4
  int top; // eax
  tagSQObjectType v6; // edx
  _DWORD *v7; // ecx
  long double v9; // [esp+0h] [ebp-10h]
  long double v10; // [esp+8h] [ebp-8h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      nInteger = (float)vals[stackbase + 1]._unVal.nInteger;
    else
      nInteger = vals[stackbase + 1]._unVal.fFloat;
  }
  else
  {
    nInteger = *(float *)&v;
  }
  __libm_sse2_atan2(y: v9, x: v10);
  top = v->_top;
  v->_top = top + 1;
  v6 = vals[top]._type;
  v7 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = nInteger;
  vals[top]._type = OT_FLOAT;
  if ( (v6 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100322F0
// Name: math_pow_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_pow_0(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // esi
  tagSQObjectType type; // ecx
  float nInteger; // xmm0_4
  int top; // eax
  tagSQObjectType v6; // edx
  _DWORD *v7; // ecx
  long double v9; // [esp+0h] [ebp-10h]
  long double v10; // [esp+8h] [ebp-8h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      nInteger = (float)vals[stackbase + 1]._unVal.nInteger;
    else
      nInteger = vals[stackbase + 1]._unVal.fFloat;
  }
  else
  {
    nInteger = *(float *)&v;
  }
  __libm_sse2_pow(x: v9, y: v10);
  top = v->_top;
  v->_top = top + 1;
  v6 = vals[top]._type;
  v7 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = nInteger;
  vals[top]._type = OT_FLOAT;
  if ( (v6 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100323B0
// Name: math_floor_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_floor_0(SQVM *v)
{
  SQObjectPtr *vals; // edx
  int stackbase; // eax
  tagSQObjectType type; // esi
  int v4; // eax
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  int top; // eax
  __m128 v8; // xmm3
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  tagSQObjectType v11; // esi
  _DWORD *v12; // ecx

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (__m128)COERCE_UNSIGNED_INT((float)*(int *)(v4 + 4));
    else
      v5 = (__m128)*(unsigned int *)(v4 + 4);
  }
  else
  {
    v5 = (__m128)(unsigned int)v;
  }
  v6.m128_i32[0] = 1258291200;
  top = v->_top;
  v8 = _mm_and_ps((__m128)0x80000000, v5);
  v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v5, v8), v6).m128_f32[0]) & 0x4B000000 | v8.m128_i32[0];
  v9 = v5;
  v9.m128_f32[0] = (float)(v5.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
  v10 = v9;
  v10.m128_f32[0] = v9.m128_f32[0] - v5.m128_f32[0];
  v->_top = top + 1;
  v11 = vals[top]._type;
  v12 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v9.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v8).m128_u32[0] & 0x3F800000);
  vals[top]._type = OT_FLOAT;
  if ( (v11 & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032490
// Name: math_ceil_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_ceil_0(float v)
{
  tagSQObjectType v1; // ecx
  float v2; // xmm0_4
  int v3; // eax
  SQObjectPtr *v4; // ecx
  tagSQObjectType type; // edx
  float *v6; // eax
  _DWORD *v7; // ecx
  float v9; // [esp+10h] [ebp-4h]

  v1 = *(_DWORD *)(*(_DWORD *)(LODWORD(v) + 32) + 8 * *(_DWORD *)(LODWORD(v) + 60) + 8);
  if ( (v1 & 0x4000000) != 0 )
  {
    if ( v1 == OT_INTEGER )
      v2 = (float)*(int *)(*(_DWORD *)(LODWORD(v) + 32) + 8 * *(_DWORD *)(LODWORD(v) + 60) + 12);
    else
      v2 = *(float *)(*(_DWORD *)(LODWORD(v) + 32) + 8 * *(_DWORD *)(LODWORD(v) + 60) + 12);
  }
  else
  {
    v2 = v;
  }
  v9 = ceil(X: v2);
  v3 = *(_DWORD *)(LODWORD(v) + 56);
  v4 = *(SQObjectPtr **)(LODWORD(v) + 32);
  *(_DWORD *)(LODWORD(v) + 56) = v3 + 1;
  type = v4[v3]._type;
  v6 = (float *)&v4[v3];
  v7 = *((_DWORD **)v6 + 1);
  v6[1] = v9;
  *v6 = 6.0185339e-36;
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032530
// Name: math_exp_0
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_exp_0(SQVM *v)
{
  SQObjectPtr *vals; // esi
  int stackbase; // eax
  tagSQObjectType type; // ecx
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // edx
  _DWORD *v8; // ecx
  long double v10; // [esp+0h] [ebp-10h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  __libm_sse2_exp(x: v10);
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.fFloat = v5;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}
