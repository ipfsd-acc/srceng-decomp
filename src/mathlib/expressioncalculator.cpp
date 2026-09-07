// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/expressioncalculator.cpp
// Functions: 18
// ============================================================

#include "mathlib\expressioncalculator.h"

//------------------------------------------------------------------------------
// Address: 0x10261900
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10261960
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102619C0
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10261A50
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  const char *v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double X; // [esp+8h] [ebp-4Ch]
  char *pOps[2]; // [esp+10h] [ebp-44h] BYREF
  const char *pFuncs[16]; // [esp+18h] [ebp-3Ch] BYREF

  v2 = (const char **)LODWORD(expr);
  pOps[0] = "abs";
  pOps[1] = "sqr";
  pFuncs[0] = "sqrt";
  pFuncs[1] = "sin";
  pFuncs[2] = "asin";
  pFuncs[3] = "cos";
  pFuncs[4] = "acos";
  pFuncs[5] = "tan";
  pFuncs[6] = "exp";
  pFuncs[7] = "log";
  pFuncs[8] = "dtor";
  pFuncs[9] = "rtod";
  pFuncs[10] = "floor";
  pFuncs[11] = "ceiling";
  pFuncs[12] = "round";
  pFuncs[13] = "sign";
  pFuncs[14] = (const char *)16;
  if ( !ParseStringList(expr: (const char **)LODWORD(expr), (const char **)pOps, nOp: (int *)&pFuncs[14])
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = pFuncs[14];
  --this->m_stack.m_Size;
  switch ( (unsigned int)v5 )
  {
    case 0u:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1u:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2u:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3u:
      __libm_sse2_sin(x: X);
      goto LABEL_25;
    case 4u:
      __libm_sse2_asin(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5u:
      __libm_sse2_cos(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6u:
      __libm_sse2_acos(x: X);
      goto LABEL_25;
    case 7u:
      __libm_sse2_tan(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8u:
      __libm_sse2_exp(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9u:
      __libm_sse2_log(x: X);
      goto LABEL_25;
    case 0xAu:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xBu:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xCu:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 0xDu:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xEu:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xFu:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10261E30
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  const float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( !ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc)
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10261FC0
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( !ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc)
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10262300
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( !ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc)
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262530
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_varValues; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<S3RGBA,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262600
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  const char **v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int v11; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *m_startingExpr; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  int m_Size; // [esp+10h] [ebp-Ch]
  ParseState_t ps; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  m_Size = this->m_stack.m_Size;
  *(float *)&ps.m_startingExpr = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v3;
    ps.m_startingExpr = (const char *)this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&ps.m_startingExpr) )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[(int)ps.m_startingExpr];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v11 = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[v11 - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *v2 = v3;
      if ( !ParseString(expr: v2, str: "(")
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || !ParseString(expr: v2, str: ")") )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          ps.m_startingExpr = (const char *)v17;
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          m_startingExpr = ps.m_startingExpr;
          ps.m_startingExpr[v14] = 0;
          CExpressionCalculator::SetVariable(this, var: m_startingExpr, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (const float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = (const char **)&v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = ps.m_startingExpr;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262820
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( !ParseStringList(expr: v12, pOps, nOp: &expr)
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262970
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262AC0
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262BC0
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (const float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262D20
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( !ParseStringList(expr: v2, pOps, nOp: &expr) || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262E80
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262F90
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102630A0
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  const float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?")
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":")
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (const float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (const float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102631C0
// Name: float EvaluateExpression(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl EvaluateExpression(char *pExpr, char *flValueToReturnIfFailure)
{
  char *v2; // xmm0_4
  CExpressionCalculator myEvaluator; // [esp+4h] [ebp-54h] BYREF
  char *expr; // [esp+54h] [ebp-4h] BYREF

  CUtlString::CUtlString(this: &myEvaluator.m_expr, pString: pExpr);
  memset(&myEvaluator.m_varNames, 0, 61);
  *(float *)&expr = COERCE_FLOAT(CUtlString::Get(this: &myEvaluator.m_expr));
  if ( *(float *)&expr != 0.0
    && CExpressionCalculator::ParseConditional(this: &myEvaluator, (const char **)&expr) != 0
    && myEvaluator.m_stack.m_Size == 1 )
  {
    v2 = *(char **)myEvaluator.m_stack.m_Memory.m_pMemory;
  }
  else
  {
    v2 = flValueToReturnIfFailure;
  }
  expr = v2;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&myEvaluator.m_stack);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&myEvaluator.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&myEvaluator.m_varNames);
  myEvaluator.m_expr.m_Storage.m_nActualLength = 0;
  if ( myEvaluator.m_expr.m_Storage.m_Memory.m_nGrowSize >= 0
    && myEvaluator.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: myEvaluator.m_expr.m_Storage.m_Memory.m_pMemory);
  }
  return *(float *)&expr;
}

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10029FB0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A000
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A060
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x1002A0B0
// Name: float clamp<float,int,int>(float const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,int>(float *val, const int *minVal, const int *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= (float)*maxVal )
    return vala;
  return (float)*maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x1002A100
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A160
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002A1B0
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A1F0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double v15; // [esp+8h] [ebp-4Ch]
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(x: v15);
      goto LABEL_25;
    case 4:
      __libm_sse2_asin(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos(x: v15);
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(x: v15);
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A5D0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A760
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AAA0
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002ACD0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_varValues; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPackedStore *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ADA0
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<CPackedStore *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (const char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<CPackedStore *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AFC0
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B110
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B260
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B360
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B4C0
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B620
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<CPackedStore *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B730
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<CPackedStore *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B840
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B960
// Name: float EvaluateExpression(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl EvaluateExpression(const char *pExpr, char *flValueToReturnIfFailure)
{
  char *v2; // xmm0_4
  CExpressionCalculator myEvaluator; // [esp+4h] [ebp-54h] BYREF
  char *expr; // [esp+54h] [ebp-4h] BYREF

  CUtlString::CUtlString(this: &myEvaluator.m_expr, pString: pExpr);
  memset(&myEvaluator.m_varNames, 0, 61);
  *(float *)&expr = COERCE_FLOAT(CUtlString::Get(this: &myEvaluator.m_expr));
  if ( *(float *)&expr != 0.0
    && CExpressionCalculator::ParseConditional(this: &myEvaluator, (const char **)&expr) != 0
    && myEvaluator.m_stack.m_Size == 1 )
  {
    v2 = *(char **)myEvaluator.m_stack.m_Memory.m_pMemory;
  }
  else
  {
    v2 = flValueToReturnIfFailure;
  }
  expr = v2;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&myEvaluator.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&myEvaluator.m_varValues);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &myEvaluator.m_varNames);
  myEvaluator.m_expr.m_Storage.m_nActualLength = 0;
  if ( myEvaluator.m_expr.m_Storage.m_Memory.m_nGrowSize >= 0
    && myEvaluator.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: myEvaluator.m_expr.m_Storage.m_Memory.m_pMemory);
  }
  return *(float *)&expr;
}

} // namespace dedicated

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00419C70
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005A6670
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005A66C0
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A6720
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A6780
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005A67D0
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x005A67F0
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x005A6850
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double v15; // [esp+8h] [ebp-4Ch]
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(x: v15);
      goto LABEL_25;
    case 4:
      __libm_sse2_asin(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos(x: v15);
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(x: v15);
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6C30
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6DC0
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A7100
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7330
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A7400
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (const char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7620
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7770
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A78C0
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A79C0
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A7B20
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7C80
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7D90
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7EA0
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A7FC0
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A8020
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_varNames);
  return 0;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00676720
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00676770
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006767D0
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00676830
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00676880
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x006768A0
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x00676900
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00676CE0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00676E70
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006771B0
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006773E0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_varValues; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006774B0
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  _BYTE v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: (__m128i *)v17, src: (const __m128i *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006776D0
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00677820
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00677970
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00677A70
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00677BD0
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00677D30
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00677E40
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00677F50
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00678070
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006780D0
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10261930
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10261990
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102619F0
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10261A80
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  const char *v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  char *pOps[2]; // [esp+10h] [ebp-44h] BYREF
  const char *pFuncs[16]; // [esp+18h] [ebp-3Ch] BYREF

  v2 = (const char **)LODWORD(expr);
  pOps[0] = "abs";
  pOps[1] = "sqr";
  pFuncs[0] = "sqrt";
  pFuncs[1] = "sin";
  pFuncs[2] = "asin";
  pFuncs[3] = "cos";
  pFuncs[4] = "acos";
  pFuncs[5] = "tan";
  pFuncs[6] = "exp";
  pFuncs[7] = "log";
  pFuncs[8] = "dtor";
  pFuncs[9] = "rtod";
  pFuncs[10] = "floor";
  pFuncs[11] = "ceiling";
  pFuncs[12] = "round";
  pFuncs[13] = "sign";
  pFuncs[14] = (const char *)16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), (const char **)pOps, nOp: (int *)&pFuncs[14]) == 0
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = pFuncs[14];
  --this->m_stack.m_Size;
  switch ( (unsigned int)v5 )
  {
    case 0u:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1u:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2u:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3u:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4u:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5u:
      __libm_sse2_cos(a1: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6u:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7u:
      __libm_sse2_tan(a1: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8u:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9u:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 0xAu:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xBu:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xCu:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 0xDu:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xEu:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xFu:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10261E60
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10261FF0
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10262330
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || !ParseString(expr: v2, str: "(")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ",")
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || !ParseString(expr: v2, str: ")") )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262560
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_varValues; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<S3RGBA,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262630
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  const char **v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int v11; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *m_startingExpr; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  int m_Size; // [esp+10h] [ebp-Ch]
  ParseState_t ps; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  m_Size = this->m_stack.m_Size;
  *(float *)&ps.m_startingExpr = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v3;
    ps.m_startingExpr = (const char *)this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&ps.m_startingExpr) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[(int)ps.m_startingExpr];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v11 = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[v11 - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *v2 = v3;
      if ( !ParseString(expr: v2, str: "(")
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || !ParseString(expr: v2, str: ")") )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          ps.m_startingExpr = (const char *)v17;
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          m_startingExpr = ps.m_startingExpr;
          ps.m_startingExpr[v14] = 0;
          CExpressionCalculator::SetVariable(this, var: m_startingExpr, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = (const char **)&v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = ps.m_startingExpr;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262850
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102629A0
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262AF0
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262BF0
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262D50
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262EB0
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10262FC0
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102630D0
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?")
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":")
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102631F0
// Name: float EvaluateExpression(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl EvaluateExpression(const char *pExpr, char *flValueToReturnIfFailure)
{
  char *v2; // xmm0_4
  CExpressionCalculator myEvaluator; // [esp+4h] [ebp-54h] BYREF
  char *expr; // [esp+54h] [ebp-4h] BYREF

  CUtlString::CUtlString(this: &myEvaluator.m_expr, pString: pExpr);
  memset(&myEvaluator.m_varNames, 0, 61);
  *(float *)&expr = COERCE_FLOAT(CUtlString::Get(this: &myEvaluator.m_expr));
  if ( *(float *)&expr != 0.0
    && CExpressionCalculator::ParseConditional(this: &myEvaluator, (const char **)&expr) != 0
    && myEvaluator.m_stack.m_Size == 1 )
  {
    v2 = *(char **)myEvaluator.m_stack.m_Memory.m_pMemory;
  }
  else
  {
    v2 = flValueToReturnIfFailure;
  }
  expr = v2;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&myEvaluator.m_stack);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&myEvaluator.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&myEvaluator.m_varNames);
  myEvaluator.m_expr.m_Storage.m_nActualLength = 0;
  if ( myEvaluator.m_expr.m_Storage.m_Memory.m_nGrowSize >= 0
    && myEvaluator.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: myEvaluator.m_expr.m_Storage.m_Memory.m_pMemory);
  }
  return *(float *)&expr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1059DD10
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1059DD60
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059DDD0
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059DE30
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1059DE80
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x1059DEA0
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x1059DF00
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  const char *v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double X; // [esp+8h] [ebp-4Ch]
  char *pOps[2]; // [esp+10h] [ebp-44h] BYREF
  const char *pFuncs[16]; // [esp+18h] [ebp-3Ch] BYREF

  v2 = (const char **)LODWORD(expr);
  pOps[0] = "abs";
  pOps[1] = "sqr";
  pFuncs[0] = "sqrt";
  pFuncs[1] = "sin";
  pFuncs[2] = "asin";
  pFuncs[3] = "cos";
  pFuncs[4] = "acos";
  pFuncs[5] = "tan";
  pFuncs[6] = "exp";
  pFuncs[7] = "log";
  pFuncs[8] = "dtor";
  pFuncs[9] = "rtod";
  pFuncs[10] = "floor";
  pFuncs[11] = "ceiling";
  pFuncs[12] = "round";
  pFuncs[13] = "sign";
  pFuncs[14] = (const char *)16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), (const char **)pOps, nOp: (int *)&pFuncs[14]) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = pFuncs[14];
  --this->m_stack.m_Size;
  switch ( (unsigned int)v5 )
  {
    case 0u:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1u:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2u:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3u:
      __libm_sse2_sin(x: X);
      goto LABEL_25;
    case 4u:
      __libm_sse2_asin(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5u:
      __libm_sse2_cos(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6u:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7u:
      __libm_sse2_tan(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8u:
      __libm_sse2_exp(x: X);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9u:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 0xAu:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xBu:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xCu:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 0xDu:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xEu:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 0xFu:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059E2E0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059E470
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059E7B0
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059E9E0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_varValues; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059EAB0
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  const char **v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int v11; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *m_startingExpr; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  int m_Size; // [esp+10h] [ebp-Ch]
  ParseState_t ps; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  m_Size = this->m_stack.m_Size;
  *(float *)&ps.m_startingExpr = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v3;
    ps.m_startingExpr = (const char *)this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&ps.m_startingExpr) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[(int)ps.m_startingExpr];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v11 = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[v11 - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          ps.m_startingExpr = (const char *)v17;
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          m_startingExpr = (char *)ps.m_startingExpr;
          ps.m_startingExpr[v14] = 0;
          CExpressionCalculator::SetVariable(this, var: m_startingExpr, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = (const char **)&v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = ps.m_startingExpr;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059ECD0
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059EE20
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059EF70
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059F070
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059F1D0
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059F330
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059F440
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059F550
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059F670
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059F6D0
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace hammer_dll

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005E8BA0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E8BF0
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E8C50
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005E8C60
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E8CC0
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005E8D10
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x005E8D30
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x005E8DA0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9180
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9310
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E9650
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9880
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E9950
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9B70
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9CC0
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9E10
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9F10
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA070
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005EA1D0
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005EA2E0
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005EA3F0
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA510
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EA570
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_varNames);
  return 0;
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00565160
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005651B0
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565210
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00565220
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565280
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005652D0
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x005652F0
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x00565350
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00565730
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005658C0
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00565C00
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00565E30
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565F00
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  _BYTE v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: (__m128i *)v17, src: (const __m128i *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00566120
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00566270
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005663C0
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005664C0
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566620
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00566780
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00566890
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005669A0
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566AC0
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00566B20
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0040A050
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005759F0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00575A40
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00575AA0
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00575B00
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00575B50
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x00575B70
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x00575BD0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double v15; // [esp+8h] [ebp-4Ch]
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(x: v15);
      goto LABEL_25;
    case 4:
      __libm_sse2_asin(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos(x: v15);
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(x: v15);
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00575FB0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  const float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576140
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00576480
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005766B0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576780
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (const char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (const float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005769A0
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576AF0
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576C40
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576D40
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (const float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576EA0
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00577000
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00577110
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00577220
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  const float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (const float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (const float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577340
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005773A0
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A55C0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006A5610
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A5680
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A56E0
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x006A5730
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x006A5750
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x006A57B0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A5B90
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A5D20
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A6060
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6290
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_varValues; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A6360
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  _BYTE v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: (__m128i *)v17, src: (const __m128i *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6580
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A66D0
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6820
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6920
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A6A80
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6BE0
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6CF0
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A6E00
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A6F20
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A6F80
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005779D0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00577A20
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577A80
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00577A90
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577AF0
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00577B40
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x00577B60
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x00577BC0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00577FA0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00578130
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00578470
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005786A0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578770
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00578990
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00578AE0
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00578C30
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00578D30
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578E90
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00578FF0
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00579100
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00579210
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579330
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00579390
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00483520
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005E1A50
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E1AA0
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1B00
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1B60
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005E1BB0
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x005E1BD0
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x005E1C30
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double v15; // [esp+8h] [ebp-4Ch]
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(x: v15);
      goto LABEL_25;
    case 4:
      __libm_sse2_asin(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos(x: v15);
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(x: v15);
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2010
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  const float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E21A0
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E24E0
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2710
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E27E0
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (const char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (const float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2A00
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2B50
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2CA0
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2DA0
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (const float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E2F00
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (const float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3060
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3170
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3280
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  const float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (const float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (const float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E33A0
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E3400
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_varNames);
  return 0;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00575320
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00575370
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005753D0
// Name: public: int CExpressionCalculator::VariableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpressionCalculator::VariableCount(CExpressionCalculator *this)
{
  return this->m_varNames.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005753E0
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00575440
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00575490
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x005754B0
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x00575510
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  __m128 v10; // xmm1
  float v11; // xmm2_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  float v15; // xmm2_4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 4:
      __libm_sse2_asin();
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos();
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
      *(float *)&v9 = v9;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(a1: _mm_cvtps_pd(v4));
      v4.m128_f32[0] = *(double *)v4.m128_u64;
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v10.m128_i32[0] = 1258291200;
      v11 = v4.m128_f32[0];
      v12 = _mm_and_ps((__m128)0x80000000, v4);
      v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v12), v10).m128_f32[0]) & 0x4B000000
                      | v12.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
      v13 = v4;
      v13.m128_f32[0] = v4.m128_f32[0] - v11;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v12).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v14.m128_i32[0] = 1258291200;
      v15 = v4.m128_f32[0];
      v16 = _mm_and_ps((__m128)0x80000000, v4);
      v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v16), v14).m128_f32[0]) & 0x4B000000
                      | v16.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
      v17 = v4;
      v17.m128_f32[0] = v4.m128_f32[0] - v15;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v16).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005758F0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2();
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow();
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00575A80
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00575DC0
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00575FF0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005760C0
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005762E0
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576430
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576580
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576680
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005767E0
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576940
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576A50
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00576B60
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576C80
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00576CE0
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &this->m_varNames);
  return 0;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006B1DE0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006B1E30
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B1E90
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B1EF0
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x006B1F40
// Name: public: void CExpressionCalculator::SetVariable(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, int nVariableIndex, float value)
{
  this->m_varValues.m_Memory.m_pMemory[nVariableIndex] = value;
}

//------------------------------------------------------------------------------
// Address: 0x006B1F60
// Name: public: char const __near * CExpressionCalculator::VariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CExpressionCalculator::VariableName(CExpressionCalculator *this, int nIndex)
{
  return CUtlString::operator char const *(this: &this->m_varNames.m_Memory.m_pMemory[nIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x006B1FC0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  double v7; // xmm0_8
  double v8; // xmm0_8
  __m128 v9; // xmm1
  float v10; // xmm2_4
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  float v14; // xmm2_4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  long double v17; // [esp+8h] [ebp-4Ch]
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(x: v17);
      goto LABEL_25;
    case 4:
      __libm_sse2_asin(x: v17);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v7 = v7;
      expr = *(float *)&v7;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos(x: v17);
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(v4));
      *(float *)&v8 = v8;
      expr = *(float *)&v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(x: v17);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(x: v17);
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v9.m128_i32[0] = 1258291200;
      v10 = v4.m128_f32[0];
      v11 = _mm_and_ps((__m128)0x80000000, v4);
      v9.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v11), v9).m128_f32[0]) & 0x4B000000
                     | v11.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v9.m128_f32[0]) - v9.m128_f32[0];
      v12 = v4;
      v12.m128_f32[0] = v4.m128_f32[0] - v10;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v12, v11).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v13.m128_i32[0] = 1258291200;
      v14 = v4.m128_f32[0];
      v15 = _mm_and_ps((__m128)0x80000000, v4);
      v13.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v15), v13).m128_f32[0]) & 0x4B000000
                      | v15.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v13.m128_f32[0]) - v13.m128_f32[0];
      v16 = v4;
      v16.m128_f32[0] = v4.m128_f32[0] - v14;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v16, v15).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B23A0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B2530
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B2870
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B2AA0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_varValues; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<S3RGBA,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B2B70
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  char *v16; // [esp-4h] [ebp-20h]
  _BYTE v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: (__m128i *)v17, src: (const __m128i *)expr, count: v13 - (const char *)expr);
          v16 = (char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B2D90
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B2EE0
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B3030
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B3130
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B3290
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B33F0
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B3500
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_stack, num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B3610
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B3730
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B3790
// Name: public: bool CExpressionCalculator::BuildVariableListFromExpression(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::BuildVariableListFromExpression(CExpressionCalculator *this)
{
  int m_Size; // eax
  bool v3; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = true;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  v3 = pExpr != nullptr && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0;
  this->m_bIsBuildingArgumentList = false;
  if ( v3 && this->m_stack.m_Size == 1 )
    return 1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_varNames);
  return 0;
}

} // namespace vmap

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10031A50
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031AA0
// Name: bool ParseStringList(char const __near * __near &,char const __near * __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(const char **expr, const char **pOps, int *nOp)
{
  const char *v3; // edx
  const char *v4; // ebx
  const char *v5; // ecx
  char v6; // al
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = pOps[--*nOp];
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B00
// Name: bool ParseStringList(char const __near * __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseStringList(
        const char **expr,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings,
        int *nOp)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // edx
  char v6; // cl
  const char *v7; // eax

  if ( *nOp != 0 )
  {
    while ( 1 )
    {
      v3 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[--*nOp]);
      v4 = *expr;
      while ( 1 )
      {
        v5 = *expr;
        v6 = **expr;
        if ( v6 != 32 && v6 != 9 )
          break;
        *expr = v5 + 1;
      }
      v7 = StringAfterPrefix(str: v5, prefix: v3);
      *expr = v7;
      if ( v7 != nullptr )
        return 1;
      *expr = v4;
      if ( *nOp == 0 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    --*nOp;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B60
// Name: int FindString(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindString(const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *strings, const char *str)
{
  unsigned int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  m_Size = strings->m_Size;
  v3 = 0;
  if ( m_Size == 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &strings->m_Memory.m_pMemory[i]);
    if ( _V_strcmp(s1: str, s2: v5) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10031BF0
// Name: private: bool CExpressionCalculator::Parse1ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse1ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  __m128 v4; // xmm0
  int v5; // eax
  __m128 v7; // xmm1
  float v8; // xmm2_4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  long double v15; // [esp+8h] [ebp-4Ch]
  const char *pFuncs[16]; // [esp+10h] [ebp-44h] BYREF
  int nFunc; // [esp+50h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "abs";
  pFuncs[1] = "sqr";
  pFuncs[2] = "sqrt";
  pFuncs[3] = "sin";
  pFuncs[4] = "asin";
  pFuncs[5] = "cos";
  pFuncs[6] = "acos";
  pFuncs[7] = "tan";
  pFuncs[8] = "exp";
  pFuncs[9] = "log";
  pFuncs[10] = "dtor";
  pFuncs[11] = "rtod";
  pFuncs[12] = "floor";
  pFuncs[13] = "ceiling";
  pFuncs[14] = "round";
  pFuncs[15] = "sign";
  nFunc = 16;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = (__m128)LODWORD(this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1]);
  v5 = nFunc;
  --this->m_stack.m_Size;
  switch ( v5 )
  {
    case 0:
      v4.m128_i32[0] &= _mask__AbsFloat_;
      goto LABEL_25;
    case 1:
      expr = v4.m128_f32[0] * v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 2:
      expr = fsqrt(v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 3:
      __libm_sse2_sin(x: v15);
      goto LABEL_25;
    case 4:
      __libm_sse2_asin(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 5:
      __libm_sse2_cos(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 6:
      __libm_sse2_acos(x: v15);
      goto LABEL_25;
    case 7:
      __libm_sse2_tan(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 8:
      __libm_sse2_exp(x: v15);
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 9:
      __libm_sse2_log(x: v15);
      goto LABEL_25;
    case 10:
      expr = v4.m128_f32[0] * 0.017453292;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 11:
      expr = v4.m128_f32[0] * 57.29578;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 12:
      v7.m128_i32[0] = 1258291200;
      v8 = v4.m128_f32[0];
      v9 = _mm_and_ps((__m128)0x80000000, v4);
      v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v9), v7).m128_f32[0]) & 0x4B000000
                     | v9.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
      v10 = v4;
      v10.m128_f32[0] = v4.m128_f32[0] - v8;
      v4.m128_f32[0] = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & 0x3F800000);
      goto LABEL_25;
    case 13:
      expr = ceil(X: v4.m128_f32[0]);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 14:
      v4.m128_f32[0] = v4.m128_f32[0] + 0.5;
      v11.m128_i32[0] = 1258291200;
      v12 = v4.m128_f32[0];
      v13 = _mm_and_ps((__m128)0x80000000, v4);
      v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v13), v11).m128_f32[0]) & 0x4B000000
                      | v13.m128_i32[0];
      v4.m128_f32[0] = (float)(v4.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
      v14 = v4;
      v14.m128_f32[0] = v4.m128_f32[0] - v12;
      expr = v4.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v13).m128_u32[0] & 0x3F800000);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return 1;
    case 15:
      if ( v4.m128_f32[0] < 0.0 )
        v4.m128_i32[0] = -1082130432;
      else
        v4.m128_i32[0] = 1065353216;
LABEL_25:
      expr = v4.m128_f32[0];
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031FE0
// Name: private: bool CExpressionCalculator::Parse2ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse2ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *p_expr; // eax
  double v8; // xmm0_8
  const char **v9; // xmm0_4
  long double v10; // [esp+0h] [ebp-20h]
  const char *pFuncs[4]; // [esp+8h] [ebp-18h] BYREF
  float f2; // [esp+18h] [ebp-8h] BYREF
  int nFunc; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "min";
  pFuncs[1] = "max";
  pFuncs[2] = "atan2";
  pFuncs[3] = "pow";
  nFunc = 4;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  f2 = v4;
  expr = v5;
  switch ( nFunc )
  {
    case 0:
      p_expr = &expr;
      if ( v4 <= v5 )
        p_expr = &f2;
      goto LABEL_12;
    case 1:
      p_expr = &expr;
      if ( v5 > v4 )
      {
LABEL_12:
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: p_expr);
        return 1;
      }
      else
      {
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &f2);
        return 1;
      }
    case 2:
      v8 = v5;
      __libm_sse2_atan2(y: v10, x: *(long double *)pFuncs);
      goto LABEL_17;
    case 3:
      v8 = v5;
      __libm_sse2_pow(x: v10, y: *(long double *)pFuncs);
LABEL_17:
      *(float *)&v9 = v8;
      expr = *(float *)&v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      break;
    default:
      return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032170
// Name: private: bool CExpressionCalculator::Parse3ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Parse3ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  bool result; // al
  double v8; // st7
  const char *pFuncs[8]; // [esp+8h] [ebp-38h] BYREF
  Vector pnt; // [esp+28h] [ebp-18h] BYREF
  float f1; // [esp+34h] [ebp-Ch] BYREF
  float f2; // [esp+38h] [ebp-8h] BYREF
  int nFunc; // [esp+3Ch] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  pFuncs[0] = "inrange";
  pFuncs[1] = "clamp";
  pFuncs[2] = "ramp";
  pFuncs[3] = "lerp";
  pFuncs[4] = "cramp";
  pFuncs[5] = "clerp";
  pFuncs[6] = "elerp";
  pFuncs[7] = "noise";
  nFunc = 8;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: pFuncs, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return false;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  f2 = v5;
  f1 = v6;
  switch ( nFunc )
  {
    case 0:
      if ( v6 < v5 || v4 < v6 )
      {
        expr = 0.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
      else
      {
        expr = 1.0;
        CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
        return true;
      }
    case 1:
      expr = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 2:
      expr = (float)(v6 - v5) / (float)(v4 - v5);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 3:
      expr = (float)((float)(v4 - v5) * v6) + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 4:
      LODWORD(expr) = 1;
      f1 = 0.0;
      f2 = (float)(v6 - v5) / (float)(v4 - v5);
      expr = clamp<float,int,int>(val: &f2, minVal: (const int *)&f1, maxVal: (const int *)&expr);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 5:
      f1 = (float)((float)(v4 - v5) * v6) + v5;
      v8 = clamp<float,float,float>(val: &f1, minVal: &f2, maxVal: &expr);
      goto LABEL_24;
    case 6:
      expr = (float)((float)((float)((float)(v6 * 3.0) * v6) - (float)((float)((float)(v6 * 2.0) * v6) * v6))
                   * (float)(v4 - v5))
           + v5;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      return true;
    case 7:
      pnt.x = v6;
      pnt.y = v5;
      pnt.z = v4;
      v8 = ImprovedPerlinNoise(&pnt);
LABEL_24:
      expr = v8;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
      goto LABEL_25;
    default:
LABEL_25:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100324B0
// Name: private: bool CExpressionCalculator::Parse5ArgFunc(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::Parse5ArgFunc(CExpressionCalculator *this, float expr)
{
  const char **v2; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  const char *f4; // [esp+8h] [ebp-Ch] BYREF
  const char *minVal; // [esp+Ch] [ebp-8h] BYREF
  int nFunc; // [esp+10h] [ebp-4h] BYREF

  v2 = (const char **)LODWORD(expr);
  f4 = "rescale";
  minVal = "crescale";
  nFunc = 2;
  if ( ParseStringList(expr: (const char **)LODWORD(expr), pOps: &f4, nOp: &nFunc) == 0
    || ParseString(expr: v2, str: "(") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ",") == 0
    || *v2 == nullptr
    || !CExpressionCalculator::ParseConditional(this, expr: v2)
    || ParseString(expr: v2, str: ")") == 0 )
  {
    return 0;
  }
  v4 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v5 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  v8 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  expr = v4;
  minVal = (const char *)LODWORD(v5);
  if ( *(float *)&nFunc == 0.0 )
  {
    expr = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
  }
  else if ( nFunc == 1 )
  {
    *(float *)&nFunc = (float)((float)((float)(v8 - v7) / (float)(v6 - v7)) * (float)(v4 - v5)) + v5;
    expr = clamp<float,float,float>(val: (const float *)&nFunc, (const float *)&minVal, maxVal: &expr);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: &expr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100326E0
// Name: public: void CExpressionCalculator::SetVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::SetVariable(CExpressionCalculator *this, const char *var, float value)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_varNames; // esi
  int String; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_varValues; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v10; // eax
  float *v11; // eax
  CUtlString src; // [esp+Ch] [ebp-10h] BYREF

  p_m_varNames = &this->m_varNames;
  String = FindString(strings: &this->m_varNames, str: var);
  if ( String < 0 )
  {
    CUtlString::CUtlString(this: &src, pString: var);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: p_m_varNames,
      elem: p_m_varNames->m_Size,
      &src);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    m_nAllocationCount = this->m_varValues.m_Memory.m_nAllocationCount;
    p_m_varValues = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_varValues;
    m_Size = this->m_varValues.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_varValues, num: m_Size - m_nAllocationCount + 1);
    ++p_m_varValues[1].m_pMemory;
    m_pMemory = p_m_varValues->m_pMemory;
    v10 = (int)p_m_varValues[1].m_pMemory - m_Size - 1;
    p_m_varValues[1].m_nAllocationCount = (int)p_m_varValues->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = (float *)&p_m_varValues->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = value;
  }
  else
  {
    this->m_varValues.m_Memory.m_pMemory[String] = value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100327B0
// Name: private: bool CExpressionCalculator::ParsePrimary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParsePrimary(CExpressionCalculator *this, char **expr)
{
  const char **v2; // esi
  const char *v3; // edi
  float *v5; // eax
  int v6; // ecx
  float *v7; // eax
  float *v9; // esi
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v12; // eax
  const char *v13; // ecx
  int v14; // esi
  void *v15; // esp
  const char *v16; // [esp-4h] [ebp-20h]
  unsigned __int8 v17[12]; // [esp+4h] [ebp-18h] BYREF
  ParseState_t ps; // [esp+10h] [ebp-Ch]
  float value; // [esp+18h] [ebp-4h] BYREF

  v2 = (const char **)expr;
  v3 = *expr;
  ps.m_stacksize = this->m_stack.m_Size;
  value = strtod(nptr: v3, endptr: expr);
  if ( v3 == *v2 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
    *v2 = v3;
    value = *(float *)&this->m_varNames.m_Size;
    if ( ParseStringList(expr: v2, strings: &this->m_varNames, nOp: (int *)&value) != 0 )
    {
      v9 = &this->m_varValues.m_Memory.m_pMemory[LODWORD(value)];
      if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
          num: 1);
      ++this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      m_Size = this->m_stack.m_Size;
      this->m_stack.m_pElements = m_pMemory;
      v12 = &m_pMemory[m_Size - 1];
      if ( v12 != nullptr )
      {
        *v12 = *v9;
        return 1;
      }
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
      *v2 = v3;
      if ( ParseString(expr: v2, str: "(") == 0
        || *v2 == nullptr
        || !CExpressionCalculator::ParseConditional(this, expr: v2)
        || ParseString(expr: v2, str: ")") == 0 )
      {
        this->m_stack.m_Size -= this->m_stack.m_Size - ps.m_stacksize;
        *v2 = v3;
        if ( CExpressionCalculator::Parse1ArgFunc(this, expr: *(float *)&v2) == 0
          && CExpressionCalculator::Parse2ArgFunc(this, expr: *(float *)&v2) == 0
          && !CExpressionCalculator::Parse3ArgFunc(this, expr: *(float *)&v2)
          && CExpressionCalculator::Parse5ArgFunc(this, expr: *(float *)&v2) == 0 )
        {
          if ( !this->m_bIsBuildingArgumentList || isdigit(c: **v2) != 0 )
            return 0;
          expr = (char **)*v2;
          while ( 1 )
          {
            if ( isalnum(c: **v2) == 0 )
            {
              v13 = *v2;
              if ( **v2 != 95 )
                break;
            }
            ++*v2;
          }
          v14 = v13 - (const char *)expr;
          v15 = alloca(v13 - (const char *)expr + 1);
          value = COERCE_FLOAT(v17);
          memcpy(dst: v17, src: (unsigned __int8 *)expr, count: v13 - (const char *)expr);
          v16 = (const char *)LODWORD(value);
          *(_BYTE *)(LODWORD(value) + v14) = 0;
          CExpressionCalculator::SetVariable(this, var: v16, value: 0.0);
          expr = nullptr;
          CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
        }
      }
    }
  }
  else
  {
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    v5 = this->m_stack.m_Memory.m_pMemory;
    v6 = this->m_stack.m_Size;
    this->m_stack.m_pElements = v5;
    v7 = &v5[v6 - 1];
    if ( v7 != nullptr )
    {
      *v7 = value;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100329D0
// Name: private: bool CExpressionCalculator::ParseUnary(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseUnary(CExpressionCalculator *this, int expr)
{
  char **v2; // edi
  int m_Size; // ebx
  float v5; // xmm0_4
  int v6; // eax
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v8; // eax
  float v10; // ecx
  float v11; // edx
  const char **v12; // [esp-Ch] [ebp-2Ch]
  const char *pOps[3]; // [esp+Ch] [ebp-14h] BYREF
  float src; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (char **)expr;
  m_Size = this->m_stack.m_Size;
  v12 = (const char **)expr;
  src = *(float *)expr;
  pOps[0] = "+";
  pOps[1] = "-";
  pOps[2] = "!";
  expr = 3;
  if ( ParseStringList(expr: v12, pOps, nOp: &expr) == 0
    || !CExpressionCalculator::ParseUnary(this, expr: (const char **)v2) )
  {
    v10 = src;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v10;
    if ( CExpressionCalculator::ParsePrimary(this, expr: v2) == 0 )
    {
      v11 = src;
      this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
      *(float *)v2 = v11;
      return 0;
    }
    return 1;
  }
  v5 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  v6 = expr;
  --this->m_stack.m_Size;
  p_m_stack = &this->m_stack;
  src = v5;
  if ( v6 == 0 )
  {
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, &src);
    return 1;
  }
  v8 = v6 - 1;
  if ( v8 == 0 )
  {
    expr = LODWORD(v5) ^ _mask__NegFloat_;
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( v8 != 1 )
    return 1;
  *(float *)&expr = v5 == 0.0;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032B20
// Name: private: bool CExpressionCalculator::ParseDivMul(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseDivMul(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  float v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // esi
  float v11; // xmm0_4
  const char *pOps[3]; // [esp+Ch] [ebp-18h] BYREF
  float v13; // [esp+1Ch] [ebp-8h]
  float f1; // [esp+20h] [ebp-4h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  v13 = *(float *)expr;
  if ( CExpressionCalculator::ParseUnary(this, expr) == 0 )
  {
    v5 = v13;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *(float *)v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "*";
  pOps[1] = "/";
  pOps[2] = "%";
  expr = 3;
  v13 = *(float *)&v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseDivMul(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --p_m_stack->m_Size;
    v11 = p_m_stack->m_Memory.m_pMemory[--p_m_stack->m_Size];
    v13 = v9;
    f1 = v11;
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 * v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 / v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 2 )
    {
      *(float *)&expr = fmod(f1, v13);
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *(float *)v2 = v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032C70
// Name: private: bool CExpressionCalculator::ParseAddSub(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAddSub(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm1_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm0_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseDivMul(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "+";
  pOps[1] = "-";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseAddSub(this, expr: v2) )
  {
    v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
    p_m_stack = &this->m_stack;
    --this->m_stack.m_Size;
    v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    if ( *(float *)&expr == 0.0 )
    {
      *(float *)&expr = v11 + v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
    if ( expr == 1 )
    {
      *(float *)&expr = v11 - v9;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032D70
// Name: private: bool CExpressionCalculator::ParseLessGreater(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseLessGreater(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *m_startingExpr; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  const char *pOps[4]; // [esp+Ch] [ebp-18h] BYREF
  ParseState_t ps0; // [esp+1Ch] [ebp-8h]

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  ps0.m_startingExpr = *(const char **)expr;
  if ( CExpressionCalculator::ParseAddSub(this, expr) != 0 )
  {
    v7 = *v2;
    v8 = this->m_stack.m_Size;
    pOps[0] = "<";
    pOps[1] = ">";
    pOps[2] = "<=";
    pOps[3] = ">=";
    expr = 4;
    ps0.m_startingExpr = v7;
    if ( ParseStringList(expr: v2, pOps, nOp: &expr) != 0 && CExpressionCalculator::ParseLessGreater(this, expr: v2) )
    {
      v9 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      v10 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
      switch ( expr )
      {
        case 0:
          if ( v9 <= v10 )
            goto LABEL_7;
          goto LABEL_12;
        case 1:
          if ( v10 > v9 )
            goto LABEL_10;
          goto LABEL_14;
        case 2:
          if ( v9 < v10 )
LABEL_7:
            v11 = 0;
          else
LABEL_12:
            v11 = 1;
          break;
        case 3:
          if ( v10 >= v9 )
LABEL_10:
            v11 = 1;
          else
LABEL_14:
            v11 = 0;
          break;
        default:
          return 1;
      }
      *(float *)&expr = (float)v11;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: &this->m_stack, src: (float *)&expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v8;
      *v2 = ps0.m_startingExpr;
      return 1;
    }
  }
  else
  {
    m_startingExpr = ps0.m_startingExpr;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = m_startingExpr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032ED0
// Name: private: bool CExpressionCalculator::ParseEquality(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseEquality(CExpressionCalculator *this, int expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  const char *v7; // edx
  int v8; // ebx
  float v9; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  float v11; // xmm1_4
  const char *ps1_4; // [esp+10h] [ebp-Ch]
  const char *pOps[2]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char **)expr;
  m_Size = this->m_stack.m_Size;
  pOps[1] = *(const char **)expr;
  if ( CExpressionCalculator::ParseLessGreater(this, expr) == 0 )
  {
    v5 = pOps[1];
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
  v7 = *v2;
  v8 = this->m_stack.m_Size;
  pOps[0] = "==";
  pOps[1] = "!=";
  expr = 2;
  ps1_4 = v7;
  if ( ParseStringList(expr: v2, pOps, nOp: &expr) == 0 || !CExpressionCalculator::ParseEquality(this, expr: v2) )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v8;
    *v2 = ps1_4;
    return 1;
  }
  v9 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  p_m_stack = &this->m_stack;
  --this->m_stack.m_Size;
  v11 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
  if ( *(float *)&expr == 0.0 )
  {
    *(float *)&expr = (float)(v11 == v9);
    CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
    return 1;
  }
  if ( expr != 1 )
    return 1;
  *(float *)&expr = v11 != v9;
  CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: (float *)&expr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10033030
// Name: private: bool CExpressionCalculator::ParseAnd(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseAnd(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseEquality(this, (int)expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "&&") != 0 && CExpressionCalculator::ParseAnd(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 && v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10033140
// Name: private: bool CExpressionCalculator::ParseOr(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseOr(CExpressionCalculator *this, const char **expr)
{
  int m_Size; // ebx
  int v5; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  BOOL v8; // eax
  float *m_pMemory; // eax
  int v10; // ecx
  float *v11; // eax
  const char *ps0_4; // [esp+10h] [ebp-4h]
  const char *ps0_4a; // [esp+10h] [ebp-4h]
  float expra; // [esp+1Ch] [ebp+8h]

  m_Size = this->m_stack.m_Size;
  ps0_4 = *expr;
  if ( CExpressionCalculator::ParseAnd(this, expr) == 0 )
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *expr = ps0_4;
    return 0;
  }
  v5 = this->m_stack.m_Size;
  ps0_4a = *expr;
  if ( ParseString(expr, str: "||") != 0 && CExpressionCalculator::ParseOr(this, expr) )
  {
    v6 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v7 = this->m_stack.m_Memory.m_pMemory[--this->m_stack.m_Size];
    v8 = v7 != 0.0 || v6 != 0.0;
    expra = (float)v8;
    if ( this->m_stack.m_Size >= this->m_stack.m_Memory.m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_stack,
        num: 1);
    ++this->m_stack.m_Size;
    m_pMemory = this->m_stack.m_Memory.m_pMemory;
    v10 = this->m_stack.m_Size;
    this->m_stack.m_pElements = m_pMemory;
    v11 = &m_pMemory[v10 - 1];
    if ( v11 != nullptr )
    {
      *v11 = expra;
      return 1;
    }
  }
  else
  {
    this->m_stack.m_Size -= this->m_stack.m_Size - v5;
    *expr = ps0_4a;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10033250
// Name: private: bool CExpressionCalculator::ParseConditional(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionCalculator::ParseConditional(CExpressionCalculator *this, const char **expr)
{
  const char **v2; // edi
  int m_Size; // ebx
  const char *v5; // ecx
  int v7; // ebx
  float v8; // xmm0_4
  CUtlStack<float,CUtlMemory<float,int> > *p_m_stack; // ecx
  int v10; // edx
  float *m_pMemory; // esi
  const char **v12; // xmm0_4
  int v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float *p_expr; // eax
  const char *v17; // [esp+10h] [ebp-4h] BYREF

  v2 = expr;
  m_Size = this->m_stack.m_Size;
  v17 = *expr;
  if ( CExpressionCalculator::ParseOr(this, expr) != 0 )
  {
    v7 = this->m_stack.m_Size;
    v17 = *v2;
    if ( ParseString(expr: v2, str: "?") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2)
      && ParseString(expr: v2, str: ":") != 0
      && *v2 != nullptr
      && CExpressionCalculator::ParseConditional(this, expr: v2) )
    {
      v8 = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
      p_m_stack = &this->m_stack;
      v10 = --this->m_stack.m_Size;
      m_pMemory = this->m_stack.m_Memory.m_pMemory;
      v17 = (const char *)LODWORD(v8);
      v12 = (const char **)LODWORD(m_pMemory[v10 - 1]);
      v13 = --p_m_stack->m_Size;
      v14 = p_m_stack->m_Memory.m_pMemory;
      expr = v12;
      v15 = v14[v13 - 1];
      --p_m_stack->m_Size;
      p_expr = (float *)&expr;
      if ( v15 == 0.0 )
        p_expr = (float *)&v17;
      CUtlStack<float,CUtlMemory<float,int>>::Push(this: p_m_stack, src: p_expr);
      return 1;
    }
    else
    {
      this->m_stack.m_Size -= this->m_stack.m_Size - v7;
      *v2 = v17;
      return 1;
    }
  }
  else
  {
    v5 = v17;
    this->m_stack.m_Size -= this->m_stack.m_Size - m_Size;
    *v2 = v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033370
// Name: public: bool CExpressionCalculator::Evaluate(float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpressionCalculator::Evaluate(CExpressionCalculator *this, float *value)
{
  int m_Size; // eax
  bool result; // al
  const char *pExpr; // [esp+4h] [ebp-4h] BYREF

  m_Size = this->m_stack.m_Size;
  this->m_bIsBuildingArgumentList = false;
  this->m_stack.m_Size -= m_Size;
  pExpr = CUtlString::Get(this: &this->m_expr);
  if ( pExpr != nullptr
    && CExpressionCalculator::ParseConditional(this, expr: &pExpr) != 0
    && (result = true, this->m_stack.m_Size == 1) )
  {
    *value = this->m_stack.m_Memory.m_pMemory[this->m_stack.m_Size - 1];
  }
  else
  {
    *value = 0.0;
    return false;
  }
  return result;
}

} // namespace matchmaking
