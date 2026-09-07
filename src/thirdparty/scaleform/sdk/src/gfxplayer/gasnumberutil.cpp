// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gasnumberutil.cpp
// Functions: 10
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gasnumberutil.h"

//------------------------------------------------------------------------------
// Address: 0x100AA090
// Name: public: static double GASNumberUtil::NaN(void)
// Source: json
//------------------------------------------------------------------------------
static double __cdecl GASNumberUtil::NaN()
{
  return *(double *)&GFxNaN_Bytes.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0A0
// Name: public: static double GASNumberUtil::POSITIVE_INFINITY(void)
// Source: json
//------------------------------------------------------------------------------
static double __cdecl GASNumberUtil::POSITIVE_INFINITY()
{
  return *(double *)&GFxPOSITIVE_INFINITY_Bytes.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0B0
// Name: public: static double GASNumberUtil::NEGATIVE_INFINITY(void)
// Source: json
//------------------------------------------------------------------------------
static double __cdecl GASNumberUtil::NEGATIVE_INFINITY()
{
  return *(double *)&GFxNEGATIVE_INFINITY_Bytes.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0C0
// Name: public: static double GASNumberUtil::MIN_VALUE(void)
// Source: json
//------------------------------------------------------------------------------
static double __cdecl GASNumberUtil::MIN_VALUE()
{
  return *(double *)&GFxMIN_VALUE_Bytes.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0D0
// Name: public: static double GASNumberUtil::MAX_VALUE(void)
// Source: json
//------------------------------------------------------------------------------
static double __cdecl GASNumberUtil::MAX_VALUE()
{
  return *(double *)&GFxMAX_VALUE_Bytes.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0E0
// Name: public: static bool GASNumberUtil::IsPOSITIVE_ZERO(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberUtil::IsPOSITIVE_ZERO(GViewport *v, long double va)
{
  unsigned int v2; // eax
  const CTier3AppSystem<IScaleformUI,0> *v3; // ecx
  long double *p_va; // edx

  v2 = 8;
  v3 = &GFxPOSITIVE_ZERO_Bytes;
  p_va = &va;
  do
  {
    if ( *(CTier3AppSystem<IScaleformUI,0>_vtbl **)p_va != v3->__vftable )
      break;
    v2 -= 4;
    ++v3;
    p_va = (long double *)((char *)p_va + 4);
  }
  while ( v2 >= 4 );
}

//------------------------------------------------------------------------------
// Address: 0x100AA160
// Name: public: static bool GASNumberUtil::IsNEGATIVE_ZERO(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberUtil::IsNEGATIVE_ZERO(GViewport *v, long double va)
{
  unsigned int v2; // eax
  const CTier3AppSystem<IScaleformUI,0> *v3; // ecx
  long double *p_va; // edx

  v2 = 8;
  v3 = &GFxNEGATIVE_ZERO_Bytes;
  p_va = &va;
  do
  {
    if ( *(CTier3AppSystem<IScaleformUI,0>_vtbl **)p_va != v3->__vftable )
      break;
    v2 -= 4;
    ++v3;
    p_va = (long double *)((char *)p_va + 4);
  }
  while ( v2 >= 4 );
}

//------------------------------------------------------------------------------
// Address: 0x100AA1E0
// Name: public: static char const __near * GASNumberUtil::IntToString(long,char __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static char *__stdcall GASNumberUtil::IntToString(int a1, char *const a2, unsigned int a3)
{
  unsigned int v3; // edi
  char *v4; // esi
  unsigned int v5; // ecx
  unsigned int v7; // [esp+18h] [ebp+10h]

  v3 = a3 - 1;
  v4 = &a2[a3 - 1];
  v5 = abs32(a1);
  *v4 = 0;
  v7 = 0;
  if ( v3 == 0 )
    return v4;
  while ( 1 )
  {
    *--v4 = v5 % 0xA + 48;
    v5 /= 0xAu;
    if ( v5 == 0 )
      break;
    if ( ++v7 >= v3 )
      return v4;
  }
  if ( v7 >= v3 || a1 >= 0 )
    return v4;
  *(v4 - 1) = 45;
  return v4 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AA270
// Name: public: static char const __near * GASNumberUtil::IntToString(long,char __near * const,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
static char *__stdcall GASNumberUtil::IntToString(int value, char *const destStr, unsigned int bufSize, int radix)
{
  unsigned int v5; // edi
  char *result; // eax
  unsigned int v7; // edx
  unsigned int k; // esi
  char v9; // cl
  char v10; // cl
  unsigned int v11; // ecx
  unsigned int j; // esi
  char v13; // dl
  char *v14; // esi
  int v15; // edx
  unsigned int i; // ecx
  unsigned int bufSizea; // [esp+1Ch] [ebp+10h]

  v5 = bufSize - 1;
  result = &destStr[bufSize - 1];
  bufSizea = bufSize - 1;
  *result = 0;
  switch ( radix )
  {
    case 2:
      v14 = nullptr;
      v15 = 1;
      for ( i = 0; i < 0x20; ++i )
      {
        if ( i >= bufSizea )
          break;
        --result;
        if ( (v15 & value) != 0 )
        {
          *result = 49;
          v14 = result;
        }
        else
        {
          *result = 48;
        }
        v15 *= 2;
        if ( v15 == 0 )
          v15 = 1;
      }
      if ( v14 != nullptr )
        return v14;
      else
        return &destStr[bufSize - 2];
    case 8:
      v11 = value;
      for ( j = 0; j < v5; ++j )
      {
        --result;
        v13 = (v11 & 7) + 48;
        v11 >>= 3;
        *result = v13;
        if ( v11 == 0 )
          break;
      }
      break;
    case 16:
      v7 = value;
      for ( k = 0; k < v5; ++k )
      {
        --result;
        v9 = v7 & 0xF;
        if ( (v7 & 0xF) > 9 )
          v10 = v9 + 87;
        else
          v10 = v9 + 48;
        v7 >>= 4;
        *result = v10;
        if ( v7 == 0 )
          break;
      }
      break;
    default:
      return GASNumberUtil::IntToString(a1: value, a2: destStr, a3: bufSize);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA360
// Name: public: static char const __near * GASNumberUtil::ToString(double,char __near * const,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
static char *__stdcall GASNumberUtil::ToString(
        long double value,
        char *const destStr,
        unsigned int destStrSize,
        int ival)
{
  int v4; // ecx
  char *v5; // esi
  int v6; // ecx
  char *v8; // eax

  v4 = ival;
  v5 = "%.14g";
  if ( ival <= 0 )
  {
    if ( ival < -14 )
      v6 = 14;
    else
      v6 = -ival;
    v5 = *(char **)&Src[4 * v6];
    v4 = 10;
  }
  if ( (HIDWORD(value) & 0x7FF00000) == 0x7FF00000 )
  {
    if ( (HIDWORD(value) & 0xFFFFF | LODWORD(value)) != 0 )
    {
      strcpy_s(_Dst: destStr, _SizeInBytes: destStrSize, _Src: "NaN");
      return destStr;
    }
    if ( value == INFINITY )
    {
      strcpy_s(_Dst: destStr, _SizeInBytes: destStrSize, _Src: "Infinity");
      return destStr;
    }
    if ( value == -INFINITY )
    {
      strcpy_s(_Dst: destStr, _SizeInBytes: destStrSize, _Src: "-Infinity");
      return destStr;
    }
    return destStr;
  }
  if ( v4 == 10 )
  {
    if ( value == (double)(int)value )
      return GASNumberUtil::IntToString(a1: (int)value, a2: destStr, a3: destStrSize);
    G_sprintf(dest: (int)value, destsize: destStr, destsizea: destStrSize, format: v5, ap: SLOBYTE(value));
    v8 = destStr;
    if ( *destStr != 0 )
    {
      while ( *v8 != 44 && *v8 != 46 )
      {
        if ( *++v8 == 0 )
          return destStr;
      }
      *v8 = 46;
    }
    return destStr;
  }
  return GASNumberUtil::IntToString((int)value, destStr, bufSize: destStrSize, radix: v4);
}
