// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasmath.cpp
// Functions: 21
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasmath.h"

//------------------------------------------------------------------------------
// Address: 0x1010A9A0
// Name: private: static void GASMathCtorFunction::Abs(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Abs(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  double v5; // st7
  int v6; // esi
  _SERVICE_STATUS *v7; // [esp-4h] [ebp-10h]
  double v8; // [esp+4h] [ebp-8h]

  v7 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v5 = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v7);
  v6 = *(_DWORD *)(fna + 4);
  v8 = fabs(v5);
  if ( *(_BYTE *)v6 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v6, a2: a1);
  *(_BYTE *)v6 = 3;
  *(double *)(v6 + 4) = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1010A9E0
// Name: private: static void GASMathCtorFunction::Acos(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Acos(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = acos(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AA30
// Name: private: static void GASMathCtorFunction::Asin(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Asin(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = asin(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AA80
// Name: private: static void GASMathCtorFunction::Atan(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Atan(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = atan(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AAD0
// Name: private: static void GASMathCtorFunction::Ceil(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Ceil(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  double X; // st7
  double v6; // st7
  int v7; // esi
  _SERVICE_STATUS *X_4; // [esp+4h] [ebp-10h]

  X_4 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  X = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: X_4);
  v6 = ceil(X);
  v7 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v7 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
  *(_BYTE *)v7 = 3;
  *(double *)(v7 + 4) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010AB20
// Name: private: static void GASMathCtorFunction::Cos(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Cos(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = cos(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AB70
// Name: private: static void GASMathCtorFunction::Exp(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Exp(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = exp(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010ABC0
// Name: private: static void GASMathCtorFunction::Floor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Floor(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  double X; // st7
  double v6; // st7
  int v7; // esi
  _SERVICE_STATUS *X_4; // [esp+4h] [ebp-10h]

  X_4 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  X = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: X_4);
  v6 = floor(X);
  v7 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v7 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
  *(_BYTE *)v7 = 3;
  *(double *)(v7 + 4) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010AC10
// Name: private: static void GASMathCtorFunction::Log(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Log(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = log(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AC60
// Name: private: static void GASMathCtorFunction::Sin(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Sin(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = sin(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010ACB0
// Name: private: static void GASMathCtorFunction::Sqrt(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Sqrt(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = sqrt(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AD00
// Name: private: static void GASMathCtorFunction::Tan(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Tan(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  int v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-10h]
  double v7; // [esp+4h] [ebp-8h]

  v6 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v7 = tan(GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v6));
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010AD50
// Name: private: static void GASMathCtorFunction::Atan2(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Atan2(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  GASValue *v5; // eax
  int v6; // esi
  _SERVICE_STATUS *v7; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-10h]
  double arg0a; // [esp+4h] [ebp-8h]
  double arg0; // [esp+4h] [ebp-8h]

  v7 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  arg0a = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v7);
  v8 = *(_SERVICE_STATUS **)(fna + 24);
  v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
  arg0 = atan2(arg0a, GASValue::ToNumber(this: v5, a2: a1, a3: arg0a, result: v8));
  v6 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v6 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v6, a2: a1);
  *(_BYTE *)v6 = 3;
  *(double *)(v6 + 4) = arg0;
}

//------------------------------------------------------------------------------
// Address: 0x1010ADB0
// Name: private: static void GASMathCtorFunction::Max(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Max(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  GASValue *v5; // eax
  double v6; // st7
  int v7; // esi
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v9; // [esp-4h] [ebp-10h]
  double arg0; // [esp+4h] [ebp-8h]

  v8 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  arg0 = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v8);
  v9 = *(_SERVICE_STATUS **)(fna + 24);
  v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
  v6 = GASValue::ToNumber(this: v5, a2: a1, a3: arg0, result: v9);
  if ( arg0 > v6 )
    v6 = arg0;
  v7 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v7 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
  *(_BYTE *)v7 = 3;
  *(double *)(v7 + 4) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010AE20
// Name: private: static void GASMathCtorFunction::Min(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Min(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  GASValue *v5; // eax
  double v6; // st7
  int v7; // esi
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v9; // [esp-4h] [ebp-10h]
  double arg0; // [esp+4h] [ebp-8h]

  v8 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  arg0 = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v8);
  v9 = *(_SERVICE_STATUS **)(fna + 24);
  v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
  v6 = GASValue::ToNumber(this: v5, a2: a1, a3: arg0, result: v9);
  if ( arg0 < v6 )
    v6 = arg0;
  v7 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v7 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
  *(_BYTE *)v7 = 3;
  *(double *)(v7 + 4) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010AE90
// Name: private: static void GASMathCtorFunction::Pow(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Pow(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  GASValue *v5; // eax
  int v6; // esi
  _SERVICE_STATUS *v7; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-10h]
  double arg0a; // [esp+4h] [ebp-8h]
  double arg0; // [esp+4h] [ebp-8h]

  v7 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  arg0a = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v7);
  v8 = *(_SERVICE_STATUS **)(fna + 24);
  v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
  arg0 = pow(arg0a, GASValue::ToNumber(this: v5, a2: a1, a3: arg0a, result: v8));
  v6 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v6 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v6, a2: a1);
  *(_BYTE *)v6 = 3;
  *(double *)(v6 + 4) = arg0;
}

//------------------------------------------------------------------------------
// Address: 0x1010AEF0
// Name: private: static void GASMathCtorFunction::Round(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Round(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // eax
  double v5; // st7
  double v6; // st7
  int v7; // esi
  _SERVICE_STATUS *X_4; // [esp+4h] [ebp-10h]

  X_4 = *(_SERVICE_STATUS **)(fna + 24);
  v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v5 = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: X_4);
  v6 = floor(X: v5 + 0.5);
  v7 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v7 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
  *(_BYTE *)v7 = 3;
  *(double *)(v7 + 4) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010AFE0
// Name: public: static unsigned long GASMath::GetNextRandom(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *__usercall GASMath::GetNextRandom@<eax>(
        const char *const *a1@<edi>,
        GRefCountBase<GFxAmpCurrentState,2> *result)
{
  IShaderAPI *v2; // eax
  _DWORD *v3; // esi
  const char *const *Random; // edi
  void *v6; // esi
  CUtlMemory<CImagePacker,int> v8; // [esp+4h] [ebp-58h] BYREF
  void **v9; // [esp+14h] [ebp-48h]
  int v10; // [esp+20h] [ebp-3Ch]

  v2 = (IShaderAPI *)((int (__thiscall *)(GRefCountBase<GFxAmpCurrentState,2> *, int))result[1].__vftable[3].dtr_GRefCountImplCore)(
                       a1: &result[1],
                       a2: 36);
  v3 = &v2->__vftable;
  if ( v2 == nullptr )
    return GFxRandom::NextRandom();
  GRefCountImpl::Release(this: v2);
  if ( v3[3] == 0 )
  {
    Random = (const char *const *)GFxRandom::NextRandom();
    GLongFormatter::GLongFormatter(a1: (int)&v8.m_nAllocationCount, v: Random, a3: a1);
    GLongFormatter::Convert(this: (GLongFormatter *)&v8.m_nAllocationCount);
    (*(void (__thiscall **)(_DWORD *, const char *, int))(*v3 + 8))(a1: v3, a2: "random", a3: v10);
    v9 = &GString::InitStruct::`vftable';
    GFormatter::~GFormatter(this: (CMeshReader *)&v8.m_nAllocationCount);
    return (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)Random;
  }
  GString::GString(this: &v8);
  (*(void (__thiscall **)(_DWORD *, const char *, CUtlMemory<CImagePacker,int> *))(*v3 + 4))(
    a1: v3,
    a2: "random",
    a3: &v8);
  Random = (const char *const *)strtoul(
                                  nptr: (const char *)(((int)v8.m_pMemory & 0xFFFFFFFC) + 8),
                                  endptr: nullptr,
                                  ibase: 10);
  v6 = (void *)((int)v8.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) != 1 )
    return (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)Random;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  return (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)Random;
}

//------------------------------------------------------------------------------
// Address: 0x1010B0E0
// Name: private: static void GASMathCtorFunction::Random(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMathCtorFunction::Random(const char *const *a1@<edi>, int fna)
{
  GRefCountBase<GFxAmpCurrentState,2> *MovieRoot; // eax
  int v5; // esi
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fnb; // [esp+14h] [ebp+8h]

  MovieRoot = (GRefCountBase<GFxAmpCurrentState,2> *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  fnb = GASMath::GetNextRandom(a1, result: MovieRoot);
  v5 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v5 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v5, a2: (int)a1);
  *(_BYTE *)v5 = 3;
  *(double *)(v5 + 4) = (double)(unsigned int)fnb / 4294967295.0;
}

//------------------------------------------------------------------------------
// Address: 0x1010B140
// Name: public: GASMathCtorFunction::GASMathCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASCFunctionObject *__thiscall GASMathCtorFunction::GASMathCtorFunction(
        GASCFunctionObject *this,
        _REASON_CONTEXT *result)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v2; // edi
  int p_cLineHeight; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  int v6; // eax
  bool v7; // zf
  CTSQueue<CFunctor *,0,1>::Node_t *v8; // eax
  int v9; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v10; // eax
  int v11; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v12; // eax
  int v13; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v14; // eax
  int v15; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v16; // eax
  int v17; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v18; // eax
  int v19; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v20; // eax
  int v21; // eax
  void *v22; // ecx
  GASValue v24; // [esp+Ch] [ebp-18h] BYREF
  double v25; // [esp+10h] [ebp-14h]
  GASCFunctionObject *v26; // [esp+1Ch] [ebp-8h]
  struct GASStringNode *ConstStringNode; // [esp+20h] [ebp-4h] BYREF

  v2 = (CTSQueue<CFunctor *,0,1>::Node_t *)result;
  v26 = this;
  GASCFunctionObject::GASCFunctionObject(
    this,
    func: result,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GlobalCtor);
  this->dwSize = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  v25 = 2.718281828459045;
  p_cLineHeight = (int)&this->cLineHeight;
  *(_DWORD *)p_cLineHeight = &GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
  pNext = v2->pNext;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)pNext[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A45B0,
                      a3: 1u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v6 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v6);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v8 = v2->pNext;
  v25 = 0.6931471805599453;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v8[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A45A0,
                      a3: 3u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v9 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v9);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v10 = v2->pNext;
  v25 = 1.442695040888963;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v10[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4580.m_pElements,
                      a3: 5u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v11 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v11);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v12 = v2->pNext;
  v25 = 2.302585092994046;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v12[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4580,
                      a3: 4u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v13 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v13);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v14 = v2->pNext;
  v25 = 0.4342944819032518;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v14[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"LOG10E",
                      a3: 6u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v15 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v15);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v16 = v2->pNext;
  v25 = 3.141592653589793;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v16[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A4568,
                      a3: 2u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v17 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v17);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v18 = v2->pNext;
  v25 = 0.7071067811865476;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v18[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4548.m_pElements,
                      a3: 7u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v19 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v19);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  v20 = v2->pNext;
  v25 = 1.414213562373095;
  LOBYTE(v24) = 3;
  HIBYTE(result) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v20[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4548,
                      a3: 5u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)p_cLineHeight + 40))(
    a1: p_cLineHeight,
    a2: v2,
    a3: &ConstStringNode,
    a4: &v24,
    a5: (char *)&result + 3);
  v21 = (int)ConstStringNode;
  v7 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v21);
  GASValue::~GASValue(this: &v24, a2: (int)v2);
  GASNameFunction::AddConstMembers(
    pobj: v22,
    psc: p_cLineHeight,
    psca: v2,
    a4: (struct GASObject **)&GASMathCtorFunction::StaticFunctionTable,
    a5: 7);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x1010B4E0
// Name: public: static class GASFunctionRef GASMathCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GASMathCtorFunction::Register(int constructor, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // eax
  unsigned int v7; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v9)(const char *, int, int *); // edx
  int v10; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v12; // eax
  int v13; // edi
  float v15; // [esp+0h] [ebp-2Ch]
  GASValue v16[4]; // [esp+Ch] [ebp-20h] BYREF
  int psc; // [esp+1Ch] [ebp-10h] BYREF
  char v18; // [esp+20h] [ebp-Ch]
  void (__thiscall **v19)(_DWORD *, int *, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(_DWORD *)(a2 + 656);
  psc = a2;
  v18 = 8;
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &a2);
  if ( v5 != nullptr )
    v6 = GASMathCtorFunction::GASMathCtorFunction(this: v5, result: (_REASON_CONTEXT *)&psc);
  else
    v6 = nullptr;
  v7 = constructor;
  *(_DWORD *)constructor = v6;
  *(_BYTE *)(v7 + 8) = 0;
  *(_DWORD *)(v7 + 4) = 0;
  MaxVal = v2[54].MaxVal;
  v9 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  constructor = 323;
  v10 = v9(a1: MaxVal, a2: 84, a3: &constructor);
  if ( v10 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASIme,GASEnvironment>::GASPrototype<GASIme,GASEnvironment>(
      this: (D3DXCOLOR *)v10,
      (struct GASStringContext *)&psc,
      pprototype: Prototype,
      constructor: v7,
      psc_12: v15);
    *(_DWORD *)v10 = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v10 + 16) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v10 + 52) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
  }
  else
  {
    v10 = 0;
  }
  if ( v10 != 0 )
    *(_DWORD *)(v10 + 8) = (*(_DWORD *)(v10 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 25, a4: v10);
  v20 = v2[56].MaxVal + 16;
  HIBYTE(a2) = 0;
  v19 = (void (__thiscall **)(_DWORD *, int *, int, GASValue *, char *))(*v20 + 40);
  v12 = GASValue::GASValue(this: v16, a2: (int)v2, a3: (const struct GASFunctionRef *)v7);
  v13 = (int)&v2[9];
  (*v19)(a1: v20, a2: &psc, a3: v13, a4: v12, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v16, a2: v13);
  if ( v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2: v13);
  return v7;
}
