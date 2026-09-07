// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lmathlib.c
// Functions: 29
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047E460
// Name: math_abs
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_abs(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: fabs(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E490
// Name: math_sin
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_sin(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: sin(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E4C0
// Name: math_sinh
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_sinh(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: sinh(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E4F0
// Name: math_cos
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_cos(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: cos(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E520
// Name: math_cosh
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_cosh(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: cosh(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E550
// Name: math_tan
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_tan(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: tan(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E580
// Name: math_tanh
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_tanh(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: tanh(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E5B0
// Name: math_asin
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_asin(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: asin(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E5E0
// Name: math_acos
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_acos(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: acos(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E610
// Name: math_atan
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_atan(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: atan2(v1, 1.0));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E640
// Name: math_atan2
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_atan2(lua_State *L)
{
  double v1; // st7
  double v3; // [esp+Ch] [ebp-8h]

  v3 = luaL_checknumber(L, narg: 1);
  v1 = luaL_checknumber(L, narg: 2);
  lua_pushnumber(L, n: atan2(v3, v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E680
// Name: math_ceil
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_ceil(lua_State *L)
{
  double X; // st7
  double v2; // st7

  X = luaL_checknumber(L, narg: 1);
  v2 = ceil(X);
  lua_pushnumber(L, n: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E6B0
// Name: math_floor
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_floor(lua_State *L)
{
  double X; // st7
  double v2; // st7

  X = luaL_checknumber(L, narg: 1);
  v2 = floor(X);
  lua_pushnumber(L, n: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E6E0
// Name: math_fmod
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_fmod(lua_State *L)
{
  double v1; // st7
  double v3; // [esp+Ch] [ebp-8h]

  v3 = luaL_checknumber(L, narg: 1);
  v1 = luaL_checknumber(L, narg: 2);
  lua_pushnumber(L, n: fmod(v3, v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E730
// Name: math_modf
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_modf(lua_State *L)
{
  double X; // st7
  double fp; // [esp+10h] [ebp-10h]
  long double Y; // [esp+18h] [ebp-8h] BYREF

  X = luaL_checknumber(L, narg: 1);
  fp = modf(X, &Y);
  lua_pushnumber(L, n: Y);
  lua_pushnumber(L, n: fp);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0047E790
// Name: math_sqrt
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_sqrt(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: sqrt(v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E7C0
// Name: math_pow
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_pow(lua_State *L)
{
  double v1; // st7
  double v3; // [esp+Ch] [ebp-8h]

  v3 = luaL_checknumber(L, narg: 1);
  v1 = luaL_checknumber(L, narg: 2);
  lua_pushnumber(L, n: pow(v3, v1));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E810
// Name: math_log
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_log(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: __FYL2X__(v1, 0.6931471805599453094));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E840
// Name: math_log10
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_log10(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: __FYL2X__(v1, 0.3010299956639811952));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E870
// Name: math_exp
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_exp(lua_State *L)
{
  long double v1; // st7
  long double v2; // rt0

  v1 = luaL_checknumber(L, narg: 1) * 1.442695040888963407;
  v2 = rint(v1);
  lua_pushnumber(L, n: __FSCALE__(__F2XM1__(v1 - v2) + 1.0, v2));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E8B0
// Name: math_deg
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_deg(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: v1 * 57.29577951308232);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E8E0
// Name: math_rad
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_rad(lua_State *L)
{
  double v1; // st7

  v1 = luaL_checknumber(L, narg: 1);
  lua_pushnumber(L, n: v1 * 0.0174532925199433);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E910
// Name: math_frexp
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_frexp(lua_State *L)
{
  double x; // st7
  long double v2; // st7
  int e; // [esp+10h] [ebp-4h] BYREF

  x = luaL_checknumber(L, narg: 1);
  v2 = frexp(x, expptr: &e);
  lua_pushnumber(L, n: v2);
  lua_pushinteger(L, n: e);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0047E950
// Name: math_ldexp
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_ldexp(lua_State *L)
{
  double x; // st7
  long double v2; // st7
  lua_TValue *v4; // [esp+8h] [ebp-8h]

  v4 = luaL_checkinteger(L, narg: 2);
  x = luaL_checknumber(L, narg: 1);
  v2 = ldexp(x, exp: (int)v4);
  lua_pushnumber(L, n: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E990
// Name: math_min
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_min(lua_State *L)
{
  int v1; // edi
  int i; // esi
  double d; // [esp+14h] [ebp-10h]
  long double dmin; // [esp+1Ch] [ebp-8h]

  v1 = lua_gettop(L);
  dmin = luaL_checknumber(L, narg: 1);
  for ( i = 2; i <= v1; ++i )
  {
    d = luaL_checknumber(L, narg: i);
    if ( dmin > d )
      dmin = d;
  }
  lua_pushnumber(L, n: dmin);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EA10
// Name: math_max
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_max(lua_State *L)
{
  int v1; // edi
  int i; // esi
  double d; // [esp+14h] [ebp-10h]
  long double dmax; // [esp+1Ch] [ebp-8h]

  v1 = lua_gettop(L);
  dmax = luaL_checknumber(L, narg: 1);
  for ( i = 2; i <= v1; ++i )
  {
    d = luaL_checknumber(L, narg: i);
    if ( d > dmax )
      dmax = d;
  }
  lua_pushnumber(L, n: dmax);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047EA90
// Name: math_random
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_random(lua_State *L)
{
  int v1; // eax
  int v2; // eax
  lua_TValue *v3; // ebx
  lua_TValue *v4; // eax
  __m128d v5; // xmm2
  __m128d v6; // xmm0
  __m128d v7; // xmm3
  double v8; // xmm1_8
  double v9; // xmm1_8
  lua_TValue *v11; // eax
  __m128d v12; // xmm2
  __m128d v13; // xmm0
  __m128d v14; // xmm3
  double v15; // xmm1_8
  double v16; // xmm1_8
  double r; // [esp+14h] [ebp-8h]

  r = (double)(rand() % 0x7FFF) * 0.00003051850947599719;
  v1 = lua_gettop(L);
  if ( v1 != 0 )
  {
    v2 = v1 - 1;
    if ( v2 != 0 )
    {
      if ( v2 != 1 )
        luaL_error(L, fmt: "wrong number of arguments");
      v3 = luaL_checkinteger(L, narg: 1);
      v4 = luaL_checkinteger(L, narg: 2);
      if ( (int)v3 > (int)v4 )
        luaL_argerror(L, narg: 2, extramsg: "interval is empty");
      v5.m128d_f64[0] = 4.503599627370496e15;
      v6 = 0;
      v6.m128d_f64[0] = (double)((char *)v4 - (char *)v3 + 1) * r;
      v7 = _mm_and_pd((__m128d)0x8000000000000000uLL, v6);
      v8 = _mm_cmplt_sd(_mm_xor_pd(v6, v7), v5).m128d_f64[0];
      v9 = v6.m128d_f64[0]
         + COERCE_DOUBLE(*(_QWORD *)&v8 & 0x4330000000000000LL | *(_QWORD *)&v7.m128d_f64[0])
         - COERCE_DOUBLE(*(_QWORD *)&v8 & 0x4330000000000000LL | *(_QWORD *)&v7.m128d_f64[0]);
      lua_pushnumber(
        L,
        n: v9
      - COERCE_DOUBLE(
          *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v9 - v6.m128d_f64[0]), v7).m128d_f64[0]
        & 0x3FF0000000000000LL)
      + (double)(int)v3);
      return 1;
    }
    else
    {
      v11 = luaL_checkinteger(L, narg: 1);
      if ( (int)v11 < 1 )
        luaL_argerror(L, narg: 1, extramsg: "interval is empty");
      v12.m128d_f64[0] = 4.503599627370496e15;
      v13 = 0;
      v13.m128d_f64[0] = (double)(int)v11 * r;
      v14 = _mm_and_pd((__m128d)0x8000000000000000uLL, v13);
      v15 = _mm_cmplt_sd(_mm_xor_pd(v13, v14), v12).m128d_f64[0];
      v16 = v13.m128d_f64[0]
          + COERCE_DOUBLE(*(_QWORD *)&v15 & 0x4330000000000000LL | *(_QWORD *)&v14.m128d_f64[0])
          - COERCE_DOUBLE(*(_QWORD *)&v15 & 0x4330000000000000LL | *(_QWORD *)&v14.m128d_f64[0]);
      lua_pushnumber(
        L,
        n: v16
      - COERCE_DOUBLE(
          *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v16 - v13.m128d_f64[0]), v14).m128d_f64[0]
        & 0x3FF0000000000000LL)
      + 1.0);
      return 1;
    }
  }
  else
  {
    lua_pushnumber(L, n: r);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EC70
// Name: math_randomseed
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_randomseed(lua_State *L)
{
  lua_TValue *v1; // eax

  v1 = luaL_checkinteger(L, narg: 1);
  srand(seed: (unsigned int)v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047EC90
// Name: int luaopen_math(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_math(lua_State *L)
{
  luaL_register(L, libname: "math", l: mathlib);
  lua_pushnumber(L, n: 3.141592653589793);
  lua_setfield(L, idx: -2, k: "pi");
  lua_pushnumber(L, n: _HUGE);
  lua_setfield(L, idx: -2, k: "huge");
  lua_getfield(L, idx: -1, k: "fmod");
  lua_setfield(L, idx: -2, k: "mod");
  return 1;
}
