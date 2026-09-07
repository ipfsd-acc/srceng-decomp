// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/3dnow.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00412920
// Name: float _3DNow_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_Sqrt(unsigned int x)
{
  __m64 v1; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(x);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v1, v1), _m_pfrsqrt(v1))));
}

//------------------------------------------------------------------------------
// Address: 0x00412950
// Name: float _3DNow_RSqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_RSqrt(unsigned int x)
{
  return 1.0 / _3DNow_Sqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x00412970
// Name: float _3DNow_VectorNormalize(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __fastcall _3DNow_VectorNormalize(Vector *vec)
{
  __m64 v1; // mm3
  __m64 v2; // mm0
  __m64 v3; // mm1
  __m64 v4; // mm0
  float v; // [esp+4h] [ebp-8h]

  v = 0.0;
  if ( 0.0 != vec->x || 0.0 != vec->y || 0.0 != vec->z )
  {
    _m_femms();
    v1 = _mm_cvtsi32_si64(LODWORD(vec->z));
    v2 = _m_pfmul(*(__m64 *)&vec->x, *(__m64 *)&vec->x);
    v3 = _m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2));
    v4 = _m_pfrsqrt(v3);
    *(__m64 *)&vec->x = _m_pfmul(*(__m64 *)&vec->x, v4);
    LODWORD(vec->z) = _mm_cvtsi64_si32(_m_pfmul(v1, v4));
    v = COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v3, v3), v4)));
    _m_femms();
  }
  return v;
}

//------------------------------------------------------------------------------
// Address: 0x004129F0
// Name: void _3DNow_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _3DNow_VectorNormalizeFast(Vector *vec)
{
  _3DNow_VectorNormalize(vec);
}

//------------------------------------------------------------------------------
// Address: 0x00412A00
// Name: float _3DNow_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_InvRSquared(const float *v)
{
  __m64 v1; // mm1
  __m64 v2; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(*((_DWORD *)v + 2));
  v2 = _m_pfmul(*(__m64 *)v, *(__m64 *)v);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfrcp(_m_pfmax(_m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2)), _mm_cvtsi32_si64(0x3F800000u)))));
}

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x00407280
// Name: float _3DNow_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_Sqrt(unsigned int x)
{
  __m64 v1; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(x);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v1, v1), _m_pfrsqrt(v1))));
}

//------------------------------------------------------------------------------
// Address: 0x004072B0
// Name: float _3DNow_RSqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_RSqrt(unsigned int x)
{
  return 1.0 / _3DNow_Sqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x004072D0
// Name: float _3DNow_VectorNormalize(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __fastcall _3DNow_VectorNormalize(Vector *vec)
{
  __m64 v1; // mm3
  __m64 v2; // mm0
  __m64 v3; // mm1
  __m64 v4; // mm0
  float v; // [esp+4h] [ebp-8h]

  v = 0.0;
  if ( 0.0 != vec->x || 0.0 != vec->y || 0.0 != vec->z )
  {
    _m_femms();
    v1 = _mm_cvtsi32_si64(LODWORD(vec->z));
    v2 = _m_pfmul(*(__m64 *)&vec->x, *(__m64 *)&vec->x);
    v3 = _m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2));
    v4 = _m_pfrsqrt(v3);
    *(__m64 *)&vec->x = _m_pfmul(*(__m64 *)&vec->x, v4);
    LODWORD(vec->z) = _mm_cvtsi64_si32(_m_pfmul(v1, v4));
    v = COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v3, v3), v4)));
    _m_femms();
  }
  return v;
}

//------------------------------------------------------------------------------
// Address: 0x00407350
// Name: void _3DNow_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _3DNow_VectorNormalizeFast(Vector *vec)
{
  _3DNow_VectorNormalize(vec);
}

//------------------------------------------------------------------------------
// Address: 0x00407360
// Name: float _3DNow_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_InvRSquared(const float *v)
{
  __m64 v1; // mm1
  __m64 v2; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(*((_DWORD *)v + 2));
  v2 = _m_pfmul(*(__m64 *)v, *(__m64 *)v);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfrcp(_m_pfmax(_m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2)), _mm_cvtsi32_si64(0x3F800000u)))));
}

} // namespace meshutilstest

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00442BA0
// Name: float _3DNow_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_Sqrt(unsigned int x)
{
  __m64 v1; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(x);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v1, v1), _m_pfrsqrt(v1))));
}

//------------------------------------------------------------------------------
// Address: 0x00442BD0
// Name: float _3DNow_RSqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_RSqrt(unsigned int x)
{
  return 1.0 / _3DNow_Sqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x00442BF0
// Name: float _3DNow_VectorNormalize(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __fastcall _3DNow_VectorNormalize(Vector *vec)
{
  __m64 v1; // mm3
  __m64 v2; // mm0
  __m64 v3; // mm1
  __m64 v4; // mm0
  float v; // [esp+4h] [ebp-8h]

  v = 0.0;
  if ( 0.0 != vec->x || 0.0 != vec->y || 0.0 != vec->z )
  {
    _m_femms();
    v1 = _mm_cvtsi32_si64(LODWORD(vec->z));
    v2 = _m_pfmul(*(__m64 *)&vec->x, *(__m64 *)&vec->x);
    v3 = _m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2));
    v4 = _m_pfrsqrt(v3);
    *(__m64 *)&vec->x = _m_pfmul(*(__m64 *)&vec->x, v4);
    LODWORD(vec->z) = _mm_cvtsi64_si32(_m_pfmul(v1, v4));
    v = COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v3, v3), v4)));
    _m_femms();
  }
  return v;
}

//------------------------------------------------------------------------------
// Address: 0x00442C70
// Name: void _3DNow_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _3DNow_VectorNormalizeFast(Vector *vec)
{
  _3DNow_VectorNormalize(vec);
}

//------------------------------------------------------------------------------
// Address: 0x00442C80
// Name: float _3DNow_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_InvRSquared(const float *v)
{
  __m64 v1; // mm1
  __m64 v2; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(*((_DWORD *)v + 2));
  v2 = _m_pfmul(*(__m64 *)v, *(__m64 *)v);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfrcp(_m_pfmax(_m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2)), _mm_cvtsi32_si64(0x3F800000u)))));
}

} // namespace pcffix

// ============================================================
// Overlay from worldrenderertest (Missing functions)
// ============================================================
namespace worldrenderertest {

//------------------------------------------------------------------------------
// Address: 0x0040F520
// Name: float _3DNow_Sqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_Sqrt(unsigned int x)
{
  __m64 v1; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(x);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v1, v1), _m_pfrsqrt(v1))));
}

//------------------------------------------------------------------------------
// Address: 0x0040F550
// Name: float _3DNow_RSqrt(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_RSqrt(unsigned int x)
{
  return 1.0 / _3DNow_Sqrt(x);
}

//------------------------------------------------------------------------------
// Address: 0x0040F570
// Name: float _3DNow_VectorNormalize(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __fastcall _3DNow_VectorNormalize(Vector *vec)
{
  __m64 v1; // mm3
  __m64 v2; // mm0
  __m64 v3; // mm1
  __m64 v4; // mm0
  float v; // [esp+4h] [ebp-8h]

  v = 0.0;
  if ( 0.0 != vec->x || 0.0 != vec->y || 0.0 != vec->z )
  {
    _m_femms();
    v1 = _mm_cvtsi32_si64(LODWORD(vec->z));
    v2 = _m_pfmul(*(__m64 *)&vec->x, *(__m64 *)&vec->x);
    v3 = _m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2));
    v4 = _m_pfrsqrt(v3);
    *(__m64 *)&vec->x = _m_pfmul(*(__m64 *)&vec->x, v4);
    LODWORD(vec->z) = _mm_cvtsi64_si32(_m_pfmul(v1, v4));
    v = COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfmul(_m_punpckldq(v3, v3), v4)));
    _m_femms();
  }
  return v;
}

//------------------------------------------------------------------------------
// Address: 0x0040F5F0
// Name: void _3DNow_VectorNormalizeFast(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall _3DNow_VectorNormalizeFast(Vector *vec)
{
  _3DNow_VectorNormalize(vec);
}

//------------------------------------------------------------------------------
// Address: 0x0040F600
// Name: float _3DNow_InvRSquared(float const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl _3DNow_InvRSquared(const float *v)
{
  __m64 v1; // mm1
  __m64 v2; // mm0

  _m_femms();
  v1 = _mm_cvtsi32_si64(*((_DWORD *)v + 2));
  v2 = _m_pfmul(*(__m64 *)v, *(__m64 *)v);
  _m_femms();
  return COERCE_FLOAT(_mm_cvtsi64_si32(_m_pfrcp(_m_pfmax(_m_pfadd(_m_pfmul(v1, v1), _m_pfacc(v2, v2)), _mm_cvtsi32_si64(0x3F800000u)))));
}

} // namespace worldrenderertest
