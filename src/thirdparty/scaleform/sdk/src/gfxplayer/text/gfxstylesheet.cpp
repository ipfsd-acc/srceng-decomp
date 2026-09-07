// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxstylesheet.cpp
// Functions: 32
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxstylesheet.h"

//------------------------------------------------------------------------------
// Address: 0x10172200
// Name: private: int CSSTokenizer<wchar_t>::IsDigit(wchar_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall CSSTokenizer<wchar_t>::IsDigit(unsigned __int16 a1)
{
  int v1; // eax
  int v2; // esi
  BOOL result; // eax

  v1 = HIBYTE(a1);
  v2 = G_UnicodeDigitBits[v1];
  if ( G_UnicodeDigitBits[v1] == 0 )
    return false;
  result = true;
  if ( v2 != 1 )
    return (G_UnicodeDigitBits[v2 + ((unsigned __int8)a1 >> 4)] & (1 << (a1 & 0xF))) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10172250
// Name: private: int CSSTokenizer<wchar_t>::IsXDigit(wchar_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall CSSTokenizer<wchar_t>::IsXDigit(unsigned __int16 a1)
{
  int v1; // eax
  int v2; // esi
  BOOL result; // eax

  v1 = HIBYTE(a1);
  v2 = G_UnicodeXDigitBits[v1];
  if ( G_UnicodeXDigitBits[v1] == 0 )
    return false;
  result = true;
  if ( v2 != 1 )
    return (G_UnicodeXDigitBits[v2 + ((unsigned __int8)a1 >> 4)] & (1 << (a1 & 0xF))) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101722A0
// Name: private: int CSSTokenizer<wchar_t>::IsAlpha(wchar_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall CSSTokenizer<wchar_t>::IsAlpha(unsigned __int16 a1)
{
  int v1; // eax
  int v2; // esi
  BOOL result; // eax

  v1 = HIBYTE(a1);
  v2 = *((unsigned __int16 *)&G_UnicodeAlphaBits + v1);
  if ( *((_WORD *)&G_UnicodeAlphaBits + v1) == 0 )
    return false;
  result = true;
  if ( v2 != 1 )
    return (*((unsigned __int16 *)&G_UnicodeAlphaBits + v2 + ((unsigned __int8)a1 >> 4)) & (1 << (a1 & 0xF))) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10172760
// Name: private: void TextStyleParserHandler<wchar_t>::HandleFontFamily(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __stdcall TextStyleParserHandler<wchar_t>::HandleFontFamily(_DWORD *a1, int *a2)
{
  unsigned int v3; // esi
  unsigned int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  RGB888_t *v8; // edx
  int v9; // eax
  int v10; // edx
  unsigned int i; // esi
  char *v12; // eax
  __int128 v14[2]; // [esp+0h] [ebp-24h] BYREF
  unsigned int v15; // [esp+30h] [ebp+Ch]

  v4 = 0;
  v15 = a2[1];
  v3 = v15;
  GStringBuffer::GStringBuffer(
    this: (_DWORD *)v14 + 3,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  if ( v15 == 0 )
  {
LABEL_17:
    for ( i = 0; i < a1[1]; ++i )
    {
      v12 = (char *)HIDWORD(v14[0]);
      if ( HIDWORD(v14[0]) == 0 )
        v12 = (char *)&pMem;
      GFxTextFormat::SetFontList(
        this: *(CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> **)(*a1 + 4 * i),
        pfontList: v12,
        fontListSz: 0xFFFFFFFF);
    }
    return GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)v14 + 12));
  }
LABEL_4:
  if ( LODWORD(v14[1]) != 0 )
    GStringBuffer::AppendChar(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)v14 + 12),
      ch: (CMatRenderContextBase *)0x2C,
      srcSize: v14[0]);
  v5 = *a2;
  if ( *(_DWORD *)(*a2 + 12 * v4) != 2 || (++v4, v3 >= v4 + 1) )
  {
    v6 = 12 * v4;
    v7 = *(_DWORD *)(v5 + 12 * v4);
    if ( v7 == 0 || v7 == 1 && *(_DWORD *)(v5 + v6 + 8) > 2u )
    {
      v8 = *(RGB888_t **)(v5 + v6 + 4);
      v9 = *(_DWORD *)(v5 + v6 + 8);
      if ( v7 == 1 )
      {
        v8 = (RGB888_t *)((char *)v8 + 2);
        v9 -= 2;
      }
      GStringBuffer::AppendString(this: (GStringBuffer *)((char *)v14 + 12), a2: v8, a3: v9);
      while ( v4 < v15 )
      {
        v10 = *(_DWORD *)(v6 + *a2);
        ++v4;
        v6 += 12;
        if ( v10 == 5 )
        {
          if ( v4 < v15 )
          {
            v3 = v15;
            goto LABEL_4;
          }
          goto LABEL_17;
        }
      }
      goto LABEL_17;
    }
  }
  return GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)v14 + 12));
}

//------------------------------------------------------------------------------
// Address: 0x10172840
// Name: private: void TextStyleParserHandler<wchar_t>::HandleColor(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __stdcall TextStyleParserHandler<wchar_t>::HandleColor(_DWORD *a1, unsigned int a2)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  unsigned int v6; // ecx
  int v7; // esi
  int v8; // ebx
  wchar_t *v10; // [esp-8h] [ebp-8h]

  v2 = *(_DWORD **)a2;
  v3 = 0;
  if ( **(_DWORD **)a2 != 2 || (v3 = 1, *(_DWORD *)(a2 + 4) >= 2u) )
  {
    v4 = 3 * v3;
    v5 = v2[v4] == 4;
    v3 = (int)&v2[v4];
    if ( v5 && *(_DWORD *)(v3 + 8) == 7 )
    {
      v10 = (wchar_t *)(*(_DWORD *)(v3 + 4) + 2);
      a2 = 0;
      LOBYTE(v3) = GFxSGMLParser<wchar_t>::ParseHexInt(a1: &a2, a2: v10, a3: 6u);
      v6 = 0;
      if ( a1[1] != 0 )
      {
        v7 = a2 & 0xFFFFFF;
        do
        {
          v3 = *(_DWORD *)(*a1 + 4 * v6);
          v8 = *(_DWORD *)(v3 + 32);
          *(_WORD *)(v3 + 42) |= 1u;
          ++v6;
          *(_DWORD *)(v3 + 32) = v7 | v8 & 0xFF000000;
        }
        while ( v6 < a1[1] );
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101728D0
// Name: private: void TextStyleParserHandler<wchar_t>::HandleDisplay(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __stdcall TextStyleParserHandler<wchar_t>::HandleDisplay(_DWORD *a1, _DWORD *a2)
{
  int result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  GFxValue::DisplayInfo *v5; // edi
  char v6; // bl
  int v7; // eax
  int v8; // eax
  unsigned int i; // ecx

  result = 0;
  if ( *(_DWORD *)*a2 != 2 || (result = 1, a2[1] >= 2u) )
  {
    result = *a2 + 12 * result;
    v3 = *(_DWORD *)result;
    if ( *(_DWORD *)result == 0 || v3 == 1 && *(_DWORD *)(result + 8) > 2u )
    {
      v4 = *(_DWORD *)(result + 8);
      v5 = *(GFxValue::DisplayInfo **)(result + 4);
      if ( v3 == 1 )
      {
        v5 = (GFxValue::DisplayInfo *)((char *)v5 + 2);
        v4 -= 2;
      }
      v6 = 0;
      v7 = v4;
      if ( v4 >= 6 )
        v7 = 6;
      result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: "inline", a3: v7);
      if ( result != 0 )
      {
        v8 = v4;
        if ( v4 >= 5 )
          v8 = 5;
        result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: "block", a3: v8);
        if ( result != 0 )
        {
          if ( v4 >= 4 )
            v4 = 4;
          result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: (const char *)&stru_102A09D0, a3: v4);
          if ( result == 0 )
            v6 = 2;
        }
        else
        {
          v6 = 1;
        }
      }
      else
      {
        v6 = 0;
      }
      for ( i = 0; i < a1[1]; *(_WORD *)(result + 66) = ((v6 & 3) << 11) | *(_WORD *)(result + 66) & 0xE7FF | 0x100 )
        result = *(_DWORD *)(*a1 + 4 * i++);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101729D0
// Name: private: void TextStyleParserHandler<wchar_t>::HandleFontSize(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleFontSize(_DWORD *a1, float a2)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // ecx
  unsigned __int16 *v8; // edx
  double v9; // st7
  unsigned int v10; // edx
  double v11; // st5
  double v12; // rt0
  double v13; // rt1
  double v14; // st5
  double v15; // st7
  int v16; // ecx
  __int16 v17; // ax

  v2 = *(_DWORD **)LODWORD(a2);
  v3 = 0;
  if ( **(_DWORD **)LODWORD(a2) != 2 || (v3 = 1, *(_DWORD *)(LODWORD(a2) + 4) >= 2u) )
  {
    v4 = 3 * v3;
    v5 = v2[v4] == 3;
    v6 = &v2[v4];
    if ( v5 )
    {
      v7 = v6[2];
      v8 = (unsigned __int16 *)v6[1];
      a2 = 0.0;
      GFxSGMLParser<wchar_t>::ParseFloat(a1: &a2, a2: v8, a3: v7);
      v9 = a2;
      if ( 0.0 != a2 )
      {
        v10 = 0;
        if ( a1[1] != 0 )
        {
          v11 = 20.0;
          while ( 1 )
          {
            v13 = v11;
            v14 = v9;
            v15 = v13;
            v16 = *(_DWORD *)(*a1 + 4 * v10);
            v17 = v14 >= 3276.8 ? -1 : (int)(v14 * v15);
            *(_WORD *)(v16 + 42) |= 8u;
            ++v10;
            *(_WORD *)(v16 + 38) = v17;
            if ( v10 >= a1[1] )
              break;
            v12 = v14;
            v11 = v15;
            v9 = v12;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172AA0
// Name: private: void TextStyleParserHandler<wchar_t>::HandleFontStyle(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleFontStyle(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // esi
  GFxValue::DisplayInfo *v6; // edi
  int v7; // eax
  unsigned int j; // esi
  unsigned int i; // esi

  v2 = 0;
  if ( *(_DWORD *)*a2 != 2 || (v2 = 1, a2[1] >= 2u) )
  {
    v3 = (int *)(*a2 + 12 * v2);
    v4 = *v3;
    if ( *v3 == 0 || v4 == 1 && (unsigned int)v3[2] > 2 )
    {
      v5 = v3[2];
      v6 = (GFxValue::DisplayInfo *)v3[1];
      if ( v4 == 1 )
      {
        v6 = (GFxValue::DisplayInfo *)((char *)v6 + 2);
        v5 -= 2;
      }
      v7 = v5;
      if ( v5 >= 6 )
        v7 = 6;
      if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: (const char *)&stru_1029DFB4, a3: v7) != nullptr )
      {
        if ( v5 >= 6 )
          v5 = 6;
        if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: (const char *)&stru_102904EC, a3: v5) == nullptr )
        {
          for ( i = 0; i < a1[1]; ++i )
            GFxTextFormat::SetItalic(this: *(GFxTextFormat **)(*a1 + 4 * i), a2: true);
        }
      }
      else
      {
        for ( j = 0; j < a1[1]; ++j )
          GFxTextFormat::SetItalic(this: *(GFxTextFormat **)(*a1 + 4 * j), a2: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172B80
// Name: private: void TextStyleParserHandler<wchar_t>::HandleFontWeight(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleFontWeight(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // esi
  GFxValue::DisplayInfo *v6; // edi
  int v7; // eax
  unsigned int j; // esi
  unsigned int i; // esi

  v2 = 0;
  if ( *(_DWORD *)*a2 != 2 || (v2 = 1, a2[1] >= 2u) )
  {
    v3 = (int *)(*a2 + 12 * v2);
    v4 = *v3;
    if ( *v3 == 0 || v4 == 1 && (unsigned int)v3[2] > 2 )
    {
      v5 = v3[2];
      v6 = (GFxValue::DisplayInfo *)v3[1];
      if ( v4 == 1 )
      {
        v6 = (GFxValue::DisplayInfo *)((char *)v6 + 2);
        v5 -= 2;
      }
      v7 = v5;
      if ( v5 >= 6 )
        v7 = 6;
      if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: (const char *)&stru_1029DFB4, a3: v7) != nullptr )
      {
        if ( v5 >= 4 )
          v5 = 4;
        if ( GFxSGMLCharIter<wchar_t>::StrCompare(
               result: v6,
               a2: (const char *)&stru_102904EC.m_Memory.m_nGrowSize,
               a3: v5) == nullptr )
        {
          for ( i = 0; i < a1[1]; ++i )
            GFxTextFormat::SetBold(this: *(GFxTextFormat **)(*a1 + 4 * i), a2: true);
        }
      }
      else
      {
        for ( j = 0; j < a1[1]; ++j )
          GFxTextFormat::SetBold(this: *(GFxTextFormat **)(*a1 + 4 * j), a2: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172C60
// Name: private: void TextStyleParserHandler<wchar_t>::HandleKerning(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleKerning(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // esi
  GFxValue::DisplayInfo *v6; // edi
  int v7; // eax
  unsigned int j; // esi
  unsigned int i; // esi

  v2 = 0;
  if ( *(_DWORD *)*a2 != 2 || (v2 = 1, a2[1] >= 2u) )
  {
    v3 = (int *)(*a2 + 12 * v2);
    v4 = *v3;
    if ( *v3 == 0 || v4 == 1 && (unsigned int)v3[2] > 2 )
    {
      v5 = v3[2];
      v6 = (GFxValue::DisplayInfo *)v3[1];
      if ( v4 == 1 )
      {
        v6 = (GFxValue::DisplayInfo *)((char *)v6 + 2);
        v5 -= 2;
      }
      v7 = v5;
      if ( v5 >= 4 )
        v7 = 4;
      if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: "true", a3: v7) != nullptr )
      {
        if ( v5 >= 5 )
          v5 = 5;
        if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: "false", a3: v5) == nullptr )
        {
          for ( i = 0; i < a1[1]; ++i )
            GFxTextFormat::SetKerning(this: *(GFxTextFormat **)(*a1 + 4 * i), a2: false);
        }
      }
      else
      {
        for ( j = 0; j < a1[1]; ++j )
          GFxTextFormat::SetKerning(this: *(GFxTextFormat **)(*a1 + 4 * j), a2: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172D40
// Name: private: void TextStyleParserHandler<wchar_t>::HandleLetterSpacing(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleLetterSpacing(_DWORD *a1, float a2)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // ecx
  unsigned __int16 *v8; // edx
  unsigned int v9; // esi
  int v10; // eax
  int v11; // ecx

  v2 = *(_DWORD **)LODWORD(a2);
  v3 = 0;
  if ( **(_DWORD **)LODWORD(a2) != 2 || (v3 = 1, *(_DWORD *)(LODWORD(a2) + 4) >= 2u) )
  {
    v4 = 3 * v3;
    v5 = v2[v4] == 3;
    v6 = &v2[v4];
    if ( v5 )
    {
      v7 = v6[2];
      v8 = (unsigned __int16 *)v6[1];
      a2 = 0.0;
      GFxSGMLParser<wchar_t>::ParseFloat(a1: &a2, a2: v8, a3: v7);
      if ( 0.0 != a2 )
      {
        v9 = 0;
        if ( a1[1] != 0 )
        {
          v10 = (int)(a2 * 20.0);
          do
          {
            v11 = *(_DWORD *)(*a1 + 4 * v9);
            *(_WORD *)(v11 + 42) |= 2u;
            ++v9;
            *(_WORD *)(v11 + 36) = v10;
          }
          while ( v9 < a1[1] );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172DD0
// Name: private: void TextStyleParserHandler<wchar_t>::HandleMarginLeft(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall TextStyleParserHandler<wchar_t>::HandleMarginLeft(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  bool v7; // zf
  _DWORD *v8; // eax
  int v9; // ecx
  unsigned __int16 *v10; // edx
  double v11; // st7
  unsigned int i; // ecx
  int v13; // eax
  int v14; // [esp+0h] [ebp-4h] BYREF

  v14 = a1;
  v4 = (_DWORD *)*a4;
  v5 = 0;
  if ( *(_DWORD *)*a4 != 2 || (v5 = 1, a4[1] >= 2u) )
  {
    v6 = 3 * v5;
    v7 = v4[v6] == 3;
    v8 = &v4[v6];
    if ( v7 )
    {
      v9 = v8[2];
      v10 = (unsigned __int16 *)v8[1];
      *(float *)&v14 = 0.0;
      GFxSGMLParser<wchar_t>::ParseFloat(a1: (float *)&v14, a2: v10, a3: v9);
      v11 = *(float *)&v14;
      if ( 0.0 != *(float *)&v14 )
      {
        for ( i = 0; i < a3[1]; *(_WORD *)(v13 + 62) = (int)v11 )
        {
          v13 = *(_DWORD *)(*a3 + 4 * i);
          *(_WORD *)(v13 + 66) |= 0x10u;
          ++i;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172E80
// Name: private: void TextStyleParserHandler<wchar_t>::HandleMarginRight(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall TextStyleParserHandler<wchar_t>::HandleMarginRight(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  bool v7; // zf
  _DWORD *v8; // eax
  int v9; // ecx
  unsigned __int16 *v10; // edx
  double v11; // st7
  unsigned int i; // ecx
  int v13; // eax
  int v14; // [esp+0h] [ebp-4h] BYREF

  v14 = a1;
  v4 = (_DWORD *)*a4;
  v5 = 0;
  if ( *(_DWORD *)*a4 != 2 || (v5 = 1, a4[1] >= 2u) )
  {
    v6 = 3 * v5;
    v7 = v4[v6] == 3;
    v8 = &v4[v6];
    if ( v7 )
    {
      v9 = v8[2];
      v10 = (unsigned __int16 *)v8[1];
      *(float *)&v14 = 0.0;
      GFxSGMLParser<wchar_t>::ParseFloat(a1: (float *)&v14, a2: v10, a3: v9);
      v11 = *(float *)&v14;
      if ( 0.0 != *(float *)&v14 )
      {
        for ( i = 0; i < a3[1]; *(_WORD *)(v13 + 64) = (int)v11 )
        {
          v13 = *(_DWORD *)(*a3 + 4 * i);
          *(_WORD *)(v13 + 66) |= 0x20u;
          ++i;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172F30
// Name: private: void TextStyleParserHandler<wchar_t>::HandleTextAlign(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __stdcall TextStyleParserHandler<wchar_t>::HandleTextAlign(_DWORD *a1, _DWORD *a2)
{
  int result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  GFxValue::DisplayInfo *v5; // edi
  int v6; // eax
  unsigned int m; // ecx
  int v8; // eax
  unsigned int k; // ecx
  int v10; // eax
  unsigned int j; // ecx
  unsigned int i; // ecx

  result = 0;
  if ( *(_DWORD *)*a2 != 2 || (result = 1, a2[1] >= 2u) )
  {
    result = *a2 + 12 * result;
    v3 = *(_DWORD *)result;
    if ( *(_DWORD *)result == 0 || v3 == 1 && *(_DWORD *)(result + 8) > 2u )
    {
      v4 = *(_DWORD *)(result + 8);
      v5 = *(GFxValue::DisplayInfo **)(result + 4);
      if ( v3 == 1 )
      {
        v5 = (GFxValue::DisplayInfo *)((char *)v5 + 2);
        v4 -= 2;
      }
      v6 = v4;
      if ( v4 >= 4 )
        v6 = 4;
      result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: "left", a3: v6);
      if ( result != 0 )
      {
        v8 = v4;
        if ( v4 >= 6 )
          v8 = 6;
        result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: "center", a3: v8);
        if ( result != 0 )
        {
          v10 = v4;
          if ( v4 >= 5 )
            v10 = 5;
          result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: "right", a3: v10);
          if ( result != 0 )
          {
            if ( v4 >= 7 )
              v4 = 7;
            result = (int)GFxSGMLCharIter<wchar_t>::StrCompare(result: v5, a2: "justify", a3: v4);
            if ( result == 0 )
            {
              for ( i = 0; i < a1[1]; *(_WORD *)(result + 66) = *(_WORD *)(result + 66) & 0xF9FE | 0x401 )
                result = *(_DWORD *)(*a1 + 4 * i++);
            }
          }
          else
          {
            for ( j = 0; j < a1[1]; *(_WORD *)(result + 66) = *(_WORD *)(result + 66) & 0xF9FE | 0x201 )
              result = *(_DWORD *)(*a1 + 4 * j++);
          }
        }
        else
        {
          for ( k = 0; k < a1[1]; ++k )
          {
            result = *(_DWORD *)(*a1 + 4 * k);
            *(_WORD *)(result + 66) |= 0x601u;
          }
        }
      }
      else
      {
        for ( m = 0; m < a1[1]; *(_WORD *)(result + 66) = *(_WORD *)(result + 66) & 0xF9FE | 1 )
          result = *(_DWORD *)(*a1 + 4 * m++);
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101730C0
// Name: private: void TextStyleParserHandler<wchar_t>::HandleTextDecoration(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleTextDecoration(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // esi
  GFxValue::DisplayInfo *v6; // edi
  int v7; // eax
  unsigned int j; // esi
  unsigned int i; // esi

  v2 = 0;
  if ( *(_DWORD *)*a2 != 2 || (v2 = 1, a2[1] >= 2u) )
  {
    v3 = (int *)(*a2 + 12 * v2);
    v4 = *v3;
    if ( *v3 == 0 || v4 == 1 && (unsigned int)v3[2] > 2 )
    {
      v5 = v3[2];
      v6 = (GFxValue::DisplayInfo *)v3[1];
      if ( v4 == 1 )
      {
        v6 = (GFxValue::DisplayInfo *)((char *)v6 + 2);
        v5 -= 2;
      }
      v7 = v5;
      if ( v5 >= 4 )
        v7 = 4;
      if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: (const char *)&stru_102A09D0, a3: v7) != nullptr )
      {
        if ( v5 >= 9 )
          v5 = 9;
        if ( GFxSGMLCharIter<wchar_t>::StrCompare(
               result: v6,
               a2: (const char *)&stru_102A5CE0.m_Memory.m_nAllocationCount,
               a3: v5) == nullptr )
        {
          for ( i = 0; i < a1[1]; ++i )
            GFxTextFormat::SetUnderline(this: *(GFxTextFormat **)(*a1 + 4 * i), a2: true);
        }
      }
      else
      {
        for ( j = 0; j < a1[1]; ++j )
          GFxTextFormat::SetUnderline(this: *(GFxTextFormat **)(*a1 + 4 * j), a2: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101731A0
// Name: private: void TextStyleParserHandler<wchar_t>::HandleTextIndent(class GArray<struct GFxTextStyle __near *,2,struct GArrayDefaultPolicy> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TextStyleParserHandler<wchar_t>::HandleTextIndent(_DWORD *a1, float a2)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // ecx
  unsigned __int16 *v8; // edx
  unsigned int v9; // esi
  int v10; // eax
  int v11; // ecx

  v2 = *(_DWORD **)LODWORD(a2);
  v3 = 0;
  if ( **(_DWORD **)LODWORD(a2) != 2 || (v3 = 1, *(_DWORD *)(LODWORD(a2) + 4) >= 2u) )
  {
    v4 = 3 * v3;
    v5 = v2[v4] == 3;
    v6 = &v2[v4];
    if ( v5 )
    {
      v7 = v6[2];
      v8 = (unsigned __int16 *)v6[1];
      a2 = 0.0;
      GFxSGMLParser<wchar_t>::ParseFloat(a1: &a2, a2: v8, a3: v7);
      if ( 0.0 != a2 )
      {
        v9 = 0;
        if ( a1[1] != 0 )
        {
          v10 = (int)a2;
          do
          {
            v11 = *(_DWORD *)(*a1 + 4 * v9);
            *(_WORD *)(v11 + 66) |= 4u;
            ++v9;
            *(_WORD *)(v11 + 58) = v10;
          }
          while ( v9 < a1[1] );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101732A0
// Name: public: virtual void TextStyleParserHandler<wchar_t>::PushCSSSelectorProperty(struct CSSToken<wchar_t> const __near &,class GArray<struct CSSToken<wchar_t>,2,struct GArrayDefaultPolicy> const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TextStyleParserHandler<wchar_t>::PushCSSSelectorProperty(void *this, int a2, int *a3, _DWORD *a4)
{
  unsigned int v5; // esi
  int result; // eax
  int v7; // edx
  int v8; // edx
  int v9; // [esp+8h] [ebp-4h] BYREF

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v9);
  GString::AppendString(
    this: (CUtlMemory<CImagePacker,int> *)&v9,
    pstr: *(RGB888_t **)(a2 + 4),
    a3: *(_DWORD *)(a2 + 8));
  if ( a3[1] == 0 )
  {
    v5 = v9 & 0xFFFFFFFC;
    result = InterlockedExchangeAdd(Addend: (volatile LONG *)((v9 & 0xFFFFFFFC) + 4), Value: -1) - 1;
    if ( result != 0 )
      return result;
    return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v5);
  }
  if ( strcmp((const char *)((v9 & 0xFFFFFFFC) + 8), "color") == 0 )
  {
    TextStyleParserHandler<wchar_t>::HandleColor(a1: a4, a2: (unsigned int)a3);
  }
  else if ( strcmp((const char *)((v9 & 0xFFFFFFFC) + 8), "display") == 0 )
  {
    TextStyleParserHandler<wchar_t>::HandleDisplay(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "font-family") )
  {
    TextStyleParserHandler<wchar_t>::HandleFontFamily(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "font-size") )
  {
    TextStyleParserHandler<wchar_t>::HandleFontSize(a1: a4, a2: *(float *)&a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "font-style") )
  {
    TextStyleParserHandler<wchar_t>::HandleFontStyle(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "font-weight") )
  {
    TextStyleParserHandler<wchar_t>::HandleFontWeight(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: (const char *)&stru_102A5CC8) )
  {
    TextStyleParserHandler<wchar_t>::HandleKerning(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "letter-spacing") )
  {
    TextStyleParserHandler<wchar_t>::HandleLetterSpacing(a1: a4, a2: *(float *)&a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "margin-left") )
  {
    TextStyleParserHandler<wchar_t>::HandleMarginLeft(a1: (int)this, a2: v7, a3: a4, a4: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "margin-right") )
  {
    TextStyleParserHandler<wchar_t>::HandleMarginRight(a1: (int)this, a2: v8, a3: a4, a4: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "text-align") )
  {
    TextStyleParserHandler<wchar_t>::HandleTextAlign(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "text-decoration") )
  {
    TextStyleParserHandler<wchar_t>::HandleTextDecoration(a1: a4, a2: a3);
  }
  else if ( GString::operator==(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v9,
              a2: "text-indent") )
  {
    TextStyleParserHandler<wchar_t>::HandleTextIndent(a1: a4, a2: *(float *)&a3);
  }
  v5 = v9 & 0xFFFFFFFC;
  result = InterlockedExchangeAdd(Addend: (volatile LONG *)((v9 & 0xFFFFFFFC) + 4), Value: -1) - 1;
  if ( result == 0 )
    return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173630
// Name: public: GFxTextStyle::GFxTextStyle(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxTextStyle::GFxTextStyle(
        GStringDH *this,
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *result)
{
  this->HeapTypeBits = (unsigned int)&GRefCountImplCore::`vftable';
  this->pHeap = (GMemoryHeap *)1;
  this->HeapTypeBits = (unsigned int)&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: this + 1, a2: (struct GMemoryHeap *)result);
  GStringDH::GStringDH(this: this + 2, a2: (struct GMemoryHeap *)result);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 8) = -16777216;
  *((_DWORD *)this + 9) = 0;
  *((_WORD *)this + 21) = 0;
  *((_DWORD *)this + 11) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 11) = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10173960
// Name: public: void GFxTextStyle::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextStyle::Reset(struct GMemoryHeap **this)
{
  struct GMemoryHeap *v2; // edi
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v3; // [esp+Ch] [ebp-44h] BYREF
  GStringDH v4; // [esp+14h] [ebp-3Ch] BYREF
  GStringDH v5; // [esp+1Ch] [ebp-34h] BYREF
  int v6; // [esp+24h] [ebp-2Ch]
  int v7; // [esp+28h] [ebp-28h]
  int v8; // [esp+2Ch] [ebp-24h]
  int v9; // [esp+30h] [ebp-20h]
  char v10; // [esp+34h] [ebp-1Ch]
  __int16 v11; // [esp+36h] [ebp-1Ah]
  IShaderAPI v12; // [esp+38h] [ebp-18h] BYREF
  int v13; // [esp+3Ch] [ebp-14h]
  int v14; // [esp+40h] [ebp-10h]
  int v15; // [esp+44h] [ebp-Ch]
  int v16; // [esp+48h] [ebp-8h]
  int v17; // [esp+4Ch] [ebp-4h]

  v2 = *(this + 3);
  v3.m_pObject = (IMaterialInternal *)1;
  v3.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: &v4, a2: v2);
  GStringDH::GStringDH(this: &v5, a2: v2);
  v9 = 0;
  v6 = 0;
  v7 = 0;
  v8 = -16777216;
  v10 = 0;
  v11 = 0;
  GFxTextFormat::operator=((int)this, __that: (int)&v3);
  GFxTextFormat::~GFxTextFormat(this: &v3);
  v15 = 0;
  v13 = 1;
  v12.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
  v14 = 0;
  v16 = 0;
  v17 = 0;
  GFxTextParagraphFormat::operator=(
    this: (int)(this + 11),
    result: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v12);
  v12.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
  GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v12);
  GRefCountImplCore::~GRefCountImplCore(this: &v12);
}

//------------------------------------------------------------------------------
// Address: 0x10173A20
// Name: public: bool CSSParser<wchar_t>::Parse(wchar_t const __near *,unsigned int,class CSSHandler<wchar_t> __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSSParser<wchar_t>::Parse(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int *NextToken; // eax
  int v7; // edi
  int v8; // edx
  int v9; // eax
  int *v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // edx
  unsigned int v14; // eax
  void **v15; // ecx
  unsigned int v16; // ebx
  int v17; // ecx
  _DWORD *v18; // eax
  int v19; // edx
  int v20; // ecx
  int *v21; // eax
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int *v25; // eax
  int v26; // edx
  int v27; // eax
  int *v28; // eax
  int v29; // ecx
  int v30; // eax
  int *v31; // eax
  int v32; // edx
  int *v33; // eax
  int v34; // edx
  int v35; // edi
  int v37[3]; // [esp+Ch] [ebp-84h] BYREF
  int v38[3]; // [esp+18h] [ebp-78h] BYREF
  int v39[3]; // [esp+24h] [ebp-6Ch] BYREF
  int v40[3]; // [esp+30h] [ebp-60h] BYREF
  int v41[3]; // [esp+3Ch] [ebp-54h] BYREF
  int v42[3]; // [esp+48h] [ebp-48h] BYREF
  int v43[3]; // [esp+54h] [ebp-3Ch] BYREF
  _DWORD v44[5]; // [esp+60h] [ebp-30h] BYREF
  int v45; // [esp+74h] [ebp-1Ch]
  int v46; // [esp+78h] [ebp-18h]
  int v47; // [esp+7Ch] [ebp-14h]
  int v48; // [esp+80h] [ebp-10h]
  int v49; // [esp+88h] [ebp-8h]
  int v50; // [esp+8Ch] [ebp-4h]
  char v51; // [esp+9Bh] [ebp+Bh]
  int v52; // [esp+9Ch] [ebp+Ch]

  v44[0] = a2;
  v44[1] = a2 + 2 * a3;
  v44[2] = 11;
  v44[3] = 0;
  v44[4] = 0;
  v45 = 1;
  v46 = 1;
  v47 = 0;
  v48 = 0;
  v52 = 0;
  v51 = 0;
  while ( v52 != 4 )
  {
    NextToken = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v40);
    v7 = *NextToken;
    v8 = NextToken[1];
    v9 = NextToken[2];
    v49 = v8;
    v50 = v9;
    if ( v7 == 10 )
      v52 = 3;
    if ( v52 != 0 )
    {
      if ( v52 == 1 )
      {
        if ( v7 != 0 )
        {
          if ( v7 != 2 )
          {
            if ( v7 == 7 )
            {
              (*(void (__thiscall **)(int, int))(*(_DWORD *)a4 + 8))(a1: a4, a2: a5);
              v52 = 0;
            }
            else
            {
              v52 = 4;
            }
          }
        }
        else
        {
          *(this + 3) = 0;
          *(this + 4) = v8;
          *(this + 5) = v9;
          v21 = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v38);
          v22 = *v21;
          v23 = v21[1];
          v24 = v21[2];
          v49 = v23;
          v50 = v24;
          if ( v22 == 2 )
          {
            v25 = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v43);
            v26 = v25[1];
            v22 = *v25;
            v27 = v25[2];
            v49 = v26;
            v50 = v27;
          }
          v52 = 2 * (v22 != 9) + 2;
        }
      }
      else
      {
        if ( v52 != 2 )
          return v52 == 3;
        if ( v7 == 7 )
        {
          (*(void (__thiscall **)(int, _DWORD *, _DWORD *, int))(*(_DWORD *)a4 + 12))(
            a1: a4,
            a2: this + 3,
            a3: this + 6,
            a4: a5);
          (*(void (__thiscall **)(int, int))(*(_DWORD *)a4 + 8))(a1: a4, a2: a5);
          *((_BYTE *)this + 37) = 0;
          v52 = 0;
        }
        else if ( v7 == 8 )
        {
          (*(void (__thiscall **)(int, _DWORD *, _DWORD *, int))(*(_DWORD *)a4 + 12))(
            a1: a4,
            a2: this + 3,
            a3: this + 6,
            a4: a5);
          *((_BYTE *)this + 37) = 0;
          v52 = 1;
        }
        else
        {
          if ( *((_BYTE *)this + 37) == 0 )
          {
            GArrayData<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Resize(
              this: this + 6,
              a2: 0);
            *((_BYTE *)this + 37) = 1;
            if ( v7 == 2 )
            {
              v10 = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v37);
              v11 = v10[1];
              v7 = *v10;
              v12 = v10[2];
              v49 = v11;
              v50 = v12;
            }
            v13 = v46;
            *(this + 10) = v45;
            *(this + 11) = v13;
          }
          v14 = *(this + 7);
          v15 = (void **)(this + 6);
          v16 = v14 + 1;
          if ( v14 + 1 >= v14 )
          {
            if ( v16 >= *(this + 8) )
              GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
                this: v15,
                pheapAddr: (ButtonCode_t)v15,
                newCapacity: v16 + (v16 >> 2));
          }
          else if ( v16 < *(this + 8) >> 1 )
          {
            GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
              this: v15,
              pheapAddr: (ButtonCode_t)v15,
              newCapacity: v16);
          }
          v17 = *(this + 6);
          v18 = (_DWORD *)(v17 + 12 * v16 - 12);
          *(this + 7) = v16;
          if ( v17 + 12 * v16 != 12 )
          {
            v19 = v49;
            v20 = v50;
            *v18 = v7;
            v18[1] = v19;
            v18[2] = v20;
          }
        }
      }
    }
    else if ( v7 != 0 )
    {
      if ( v7 == 2 )
      {
        if ( *((_BYTE *)this + 36) != 0 )
          v52 = 4;
      }
      else
      {
        v52 = 4;
      }
    }
    else if ( *((_BYTE *)this + 36) != 0 )
    {
      *(this + 2) += v9;
LABEL_41:
      (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)a4 + 4))(a1: a4, a2: this, a3: a5);
      if ( v51 != 0 )
      {
        v51 = 0;
      }
      else
      {
        v31 = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v41);
        v32 = v31[2];
        v7 = *v31;
        v49 = v31[1];
        v50 = v32;
      }
      if ( v7 == 2 )
      {
        v33 = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v39);
        v34 = v33[2];
        v7 = *v33;
        v49 = v33[1];
        v50 = v34;
      }
      v35 = v7 - 5;
      if ( v35 != 0 )
      {
        if ( v35 == 1 )
        {
          v52 = 1;
          *((_BYTE *)this + 36) = 0;
        }
        else
        {
          v52 = 4;
        }
      }
      else
      {
        v52 = 0;
        *((_BYTE *)this + 36) = 0;
      }
    }
    else
    {
      *this = 0;
      *(this + 1) = v8;
      *(this + 2) = v9;
      v28 = CSSTokenizer<wchar_t>::GetNextToken(this: v44, a2: v42);
      v7 = *v28;
      v29 = v28[1];
      v30 = v28[2];
      v49 = v29;
      if ( v7 != 9 )
      {
        v51 = 1;
        goto LABEL_41;
      }
      *(this + 2) += v30;
      *((_BYTE *)this + 36) = 1;
    }
  }
  return v52 == 3;
}

//------------------------------------------------------------------------------
// Address: 0x10173D50
// Name: public: virtual void TextStyleParserHandler<wchar_t>::CloseCSSSelectorBlock(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__stdcall TextStyleParserHandler<wchar_t>::CloseCSSSelectorBlock(CVertexBuilder *a1)
{
  void *result; // eax

  if ( a1->m_VertexSize_BoneWeight == 0 )
  {
    if ( a1->m_VertexSize_BoneMatrixIndex == 0 )
      result = GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                 this: a1,
                 pheapAddr: (ButtonCode_t)a1,
                 newCapacity: 0);
  }
  else if ( (a1->m_VertexSize_BoneMatrixIndex & 0xFFFFFFFE) != 0 )
  {
    result = (void *)a1->m_VertexSize_Position;
    if ( a1->m_VertexSize_Position != 0 )
    {
      result = (void *)((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                         a1: GMemory::pGlobalHeap,
                         a2: a1->m_VertexSize_Position);
      a1->m_VertexSize_Position = 0;
    }
    a1->m_VertexSize_BoneMatrixIndex = 0;
    a1->m_VertexSize_BoneWeight = 0;
    return result;
  }
  a1->m_VertexSize_BoneWeight = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173F20
// Name: public: void GFxTextStyleManager::ClearStyles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextStyleManager::ClearStyles(void **this)
{
  void **v1; // ebx
  _DWORD *v2; // eax
  void **v3; // edx
  unsigned int v4; // esi
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int v8; // edi
  unsigned int v9; // eax
  _DWORD *v10; // ecx
  void **v11; // [esp+Ch] [ebp-Ch]

  v1 = this;
  v2 = *this;
  if ( *this != nullptr )
  {
    v5 = v2[1];
    v4 = 0;
    v6 = v2 + 2;
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 5;
    }
    while ( v4 <= v5 );
    v11 = v1;
    v3 = v1;
  }
  else
  {
    v3 = nullptr;
    v11 = nullptr;
    v4 = 0;
  }
  while ( v3 != nullptr )
  {
    v7 = *v3;
    if ( *v3 == nullptr || (signed int)v4 > v7[1] )
      break;
    v8 = v7[5 * v4 + 6];
    if ( v8 != 0 )
    {
      *(_DWORD *)(v8 + 44) = &GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)(v8 + 44));
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)(v8 + 44));
      GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v8);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v8);
      v1 = this;
      v3 = v11;
    }
    v9 = *((_DWORD *)*v3 + 1);
    if ( (int)v4 <= (int)v9 && ++v4 <= v9 )
    {
      v10 = (char *)*v3 + 20 * v4 + 8;
      do
      {
        if ( *v10 != -2 )
          break;
        ++v4;
        v10 += 5;
      }
      while ( v4 <= v9 );
    }
  }
  GHashSetBase<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GASMovieClipLoader::ProgressDesc,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10173FE0
// Name: private: bool GFxTextStyleManager::ParseCSSImpl<wchar_t>(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextStyleManager::ParseCSSImpl<wchar_t>(void *this, int a2, int a3)
{
  bool v3; // bl
  _DWORD v5[6]; // [esp+4h] [ebp-44h] BYREF
  void *v6; // [esp+1Ch] [ebp-2Ch]
  int v7; // [esp+20h] [ebp-28h]
  int v8; // [esp+24h] [ebp-24h]
  __int16 v9; // [esp+28h] [ebp-20h]
  _DWORD v10[3]; // [esp+34h] [ebp-14h] BYREF
  _DWORD v11[2]; // [esp+40h] [ebp-8h] BYREF

  v5[1] = 0;
  v5[2] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v6 = nullptr;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  memset(v10, 0, sizeof(v10));
  v11[1] = this;
  v5[0] = 11;
  v5[3] = 11;
  v11[0] = &TextStyleParserHandler<wchar_t>::`vftable';
  v3 = CSSParser<wchar_t>::Parse(this: v5, a2, a3, a4: (int)v11, a5: (int)v10);
  v11[0] = &GFxKeyboardState::IListener::`vftable';
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v10[0]);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10174200
// Name: public: bool GFxTextStyleManager::ParseCSS(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextStyleManager::ParseCSS(
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *this,
        int buffer,
        ColorCorrectionLookup_t *const *len)
{
  wchar_t *v4; // esi
  int v5; // eax
  bool v6; // bl
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 324;
  v4 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * (_DWORD)len + 2, a3: &v8);
  v5 = GUTF8Util::DecodeString(
         pbegin: v4,
         putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)buffer,
         length: (int)len);
  v6 = GFxTextStyleManager::ParseCSSImpl<wchar_t>(this, a2: (int)v4, a3: v5);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10174260
// Name: public: bool GFxTextStyleManager::ParseCSS(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextStyleManager::ParseCSS(void *this, int a2, int a3)
{
  return GFxTextStyleManager::ParseCSSImpl<wchar_t>(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10174270
// Name: public: struct GFxTextStyle const __near * GFxTextStyleManager::GetStyle(enum GFxTextStyleKey::KeyType,class GString const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextStyleManager::GetStyle(int this, int a2, _DWORD *src)
{
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // ebx
  int Index; // eax
  int v8; // eax
  int v9; // eax
  int v11; // [esp+0h] [ebp-Ch]

  v4 = (_DWORD *)(this + 4);
  *(_DWORD *)(this + 4) = a2;
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 8),
    src,
    a3: v11);
  v5 = GString::BernsteinHashFunction(
         result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*src & 0xFFFFFFFC) + 8),
         size: *(_DWORD *)(*src & 0xFFFFFFFC) & 0x7FFFFFFF,
         seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505)
     + *v4;
  v4[2] = v5;
  v6 = *(_DWORD *)this;
  if ( *(_DWORD *)this != 0
    && (Index = GHashSetBase<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeAltHashF,GAllocatorLH<GFxTextStyleKey,324>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>>::findIndexCore<GFxTextStyleKey>(
                  (int *)this,
                  a2: v4,
                  a3: v5 & *(_DWORD *)(v6 + 4))) >= 0
    && (v8 = v6 + 20 * Index + 12) != 0
    && (v9 = v8 + 12) != 0 )
  {
    return *(_DWORD *)v9;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101742F0
// Name: public: struct GFxTextStyle const __near * GFxTextStyleManager::GetStyle(enum GFxTextStyleKey::KeyType,char const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextStyleManager::GetStyle(
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *this,
        ColorCorrectionLookup_t *const *type,
        char *name,
        unsigned int len)
{
  unsigned int v4; // eax
  void *v6; // esi

  v4 = len;
  if ( len == -1 )
    v4 = strlen(name);
  GString::GString(this: (GString *)&len, src: name, count: v4);
  GFxTextStyleManager::GetStyle((int)this, a2: (int)type, src: &len);
  v6 = (void *)(len & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((len & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10174360
// Name: public: struct GFxTextStyle const __near * GFxTextStyleManager::GetStyle(enum GFxTextStyleKey::KeyType,wchar_t const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxTextStyleManager::GetStyle@<eax>(
        int a1@<ecx>,
        int a2,
        wchar_t *pwch,
        CUtlMemory<CImagePacker,int> a4)
{
  CImagePacker *m_pMemory; // esi
  int Style; // eax
  void *v7; // esi
  int v8; // edi

  m_pMemory = a4.m_pMemory;
  if ( a4.m_pMemory == (CImagePacker *)-1 )
    m_pMemory = (CImagePacker *)G_wcslen(pwch);
  GString::GString(this: &a4);
  GString::AppendString(this: &a4, pstr: (RGB888_t *)pwch, a3: (int)m_pMemory);
  Style = GFxTextStyleManager::GetStyle(this: a1, a2, src: &a4);
  v7 = (void *)((int)a4.m_pMemory & 0xFFFFFFFC);
  v8 = Style;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a4.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101743D0
// Name: public: void GFxTextStyleManager::ClearStyle(enum GFxTextStyleKey::KeyType,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextStyleManager::ClearStyle(
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *this,
        ColorCorrectionLookup_t *const *type,
        _DWORD *src)
{
  int *p_m_nAllocationCount; // esi
  int v5; // edx
  ColorCorrectionLookup_t **m_pMemory; // ebx
  int Index; // eax
  int v8; // ebx
  int *v9; // eax
  int v10; // ebx
  int v11; // [esp+0h] [ebp-Ch]

  p_m_nAllocationCount = &this->m_Memory.m_nAllocationCount;
  this->m_Memory.m_nAllocationCount = (int)type;
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&this->m_Memory.m_nGrowSize,
    src,
    a3: v11);
  v5 = GString::BernsteinHashFunction(
         result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*src & 0xFFFFFFFC) + 8),
         size: *(_DWORD *)(*src & 0xFFFFFFFC) & 0x7FFFFFFF,
         seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505)
     + *p_m_nAllocationCount;
  p_m_nAllocationCount[2] = v5;
  m_pMemory = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    Index = GHashSetBase<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeAltHashF,GAllocatorLH<GFxTextStyleKey,324>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>>::findIndexCore<GFxTextStyleKey>(
              (int *)this,
              a2: p_m_nAllocationCount,
              a3: v5 & (unsigned int)m_pMemory[1]);
    if ( Index >= 0 )
    {
      v8 = (int)&m_pMemory[5 * Index + 3];
      if ( v8 != 0 )
      {
        v9 = (int *)(v8 + 12);
        if ( v8 != -12 )
        {
          v10 = *v9;
          if ( *v9 != 0 )
          {
            *(_DWORD *)(v10 + 44) = &GFxTextParagraphFormat::`vftable';
            GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)(v10 + 44));
            GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)(v10 + 44));
            GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v10);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v10);
          }
          GHashSetBase<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeAltHashF,GAllocatorLH<GFxTextStyleKey,324>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>>::RemoveAlt<GFxTextStyleKey>(
            this,
            a2: p_m_nAllocationCount);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174480
// Name: public: void GFxTextStyleManager::ClearStyle(enum GFxTextStyleKey::KeyType,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextStyleManager::ClearStyle(
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *this,
        ColorCorrectionLookup_t *const *type,
        char *src,
        unsigned int len)
{
  unsigned int v4; // eax
  unsigned int v6; // esi
  int v7; // eax

  v4 = len;
  if ( len == -1 )
    v4 = strlen(src);
  GString::GString(this: (GString *)&len, src, count: v4);
  GFxTextStyleManager::ClearStyle(this, type, src: &len);
  v6 = len & 0xFFFFFFFC;
  v7 = InterlockedExchangeAdd(Addend: (volatile LONG *)((len & 0xFFFFFFFC) + 4), Value: -1) - 1;
  if ( v7 == 0 )
    LOBYTE(v7) = ((bool (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                   a1: GMemory::pGlobalHeap,
                   a2: v6);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101744F0
// Name: public: GFxTextStyleManager::~GFxTextStyleManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextStyleManager::~GFxTextStyleManager(void **this)
{
  volatile LONG *v2; // esi

  GFxTextStyleManager::ClearStyles(this);
  v2 = (volatile LONG *)((unsigned int)*(this + 2) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  GHashSetBase<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GASMovieClipLoader::ProgressDesc,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10174530
// Name: public: virtual void TextStyleParserHandler<wchar_t>::OpenCSSSelectorBlock(struct CSSToken<wchar_t> const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TextStyleParserHandler<wchar_t>::OpenCSSSelectorBlock(int *this, int a2, CVertexBuilder *a3)
{
  int v4; // eax
  int v5; // ebx
  int v6; // edx
  int *v7; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v8; // ecx
  int v9; // ecx
  int *v10; // ebx
  int v11; // edi
  int Index; // eax
  int v13; // eax
  struct GMemoryHeap ***v14; // eax
  struct GMemoryHeap **v15; // edi
  CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *v16; // edi
  int (__thiscall *v17)(CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *, int, int *); // edx
  GStringDH *v18; // eax
  void **v19; // ecx
  int v20; // eax
  CVertexBuilder *v21; // ebx
  unsigned int m_VertexSize_BoneWeight; // eax
  unsigned int v23; // esi
  struct GMemoryHeap ***v24; // eax
  unsigned int v25; // esi
  int result; // eax
  int v27; // [esp+0h] [ebp-18h]
  int *v28; // [esp+Ch] [ebp-Ch] BYREF
  int *v29; // [esp+10h] [ebp-8h]
  int src; // [esp+14h] [ebp-4h] BYREF

  v29 = this;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&src);
  v4 = *(_DWORD *)(a2 + 8);
  v5 = 0;
  if ( v4 != 0 && *(_WORD *)(v6 = *(_DWORD *)(a2 + 4)) == 46 )
  {
    v5 = 1;
    GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&src, pstr: (RGB888_t *)(v6 + 2), a3: v4 - 1);
  }
  else
  {
    GString::AppendString(
      this: (CUtlMemory<CImagePacker,int> *)&src,
      pstr: *(RGB888_t **)(a2 + 4),
      a3: *(_DWORD *)(a2 + 8));
  }
  v7 = (int *)(*(this + 1) + 4);
  v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*(this + 1) + 8);
  *v7 = v5;
  GString::operator=(this: v8, &src, a3: v27);
  v9 = GString::BernsteinHashFunction(
         result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((src & 0xFFFFFFFC) + 8),
         size: *(_DWORD *)(src & 0xFFFFFFFC) & 0x7FFFFFFF,
         seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505)
     + *v7;
  v7[2] = v9;
  v10 = (int *)*(this + 1);
  v11 = *v10;
  if ( *v10 != 0
    && (Index = GHashSetBase<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeAltHashF,GAllocatorLH<GFxTextStyleKey,324>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>>::findIndexCore<GFxTextStyleKey>(
                  this: v10,
                  a2: v7,
                  a3: v9 & *(_DWORD *)(v11 + 4))) >= 0
    && (v13 = v11 + 20 * Index + 12) != 0
    && (v14 = (struct GMemoryHeap ***)(v13 + 12)) != nullptr
    && (v15 = *v14, *v14 != nullptr) )
  {
    GFxTextStyle::Reset(this: *v14);
  }
  else
  {
    v16 = (CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *)GMemory::pGlobalHeap->GetAllocHeap(
                                                                                                this: GMemory::pGlobalHeap,
                                                                                                a2: v10);
    v17 = *((int (__thiscall **)(CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *, int, int *))v16->m_Memory.m_pMemory
          + 10);
    a2 = 324;
    v18 = (GStringDH *)v17(a1: v16, a2: 68, a3: &a2);
    if ( v18 != nullptr )
      v15 = (struct GMemoryHeap **)GFxTextStyle::GFxTextStyle(this: v18, result: v16);
    else
      v15 = nullptr;
    v19 = (void **)v29[1];
    a2 = (int)v15;
    v20 = v7[2];
    v29 = &a2;
    v28 = v7;
    GHashSetBase<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeAltHashF,GAllocatorLH<GFxTextStyleKey,324>,GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>>::add<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeRef>(
      this: v19,
      pheapAddr: v19,
      a3: (int)&v28,
      a4: v20);
  }
  v21 = a3;
  m_VertexSize_BoneWeight = a3->m_VertexSize_BoneWeight;
  v23 = m_VertexSize_BoneWeight + 1;
  if ( m_VertexSize_BoneWeight + 1 >= m_VertexSize_BoneWeight )
  {
    if ( v23 >= a3->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: a3,
        pheapAddr: (ButtonCode_t)a3,
        newCapacity: v23 + (v23 >> 2));
  }
  else if ( v23 < (unsigned int)a3->m_VertexSize_BoneMatrixIndex >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: a3,
      pheapAddr: (ButtonCode_t)a3,
      newCapacity: v23);
  }
  v24 = (struct GMemoryHeap ***)(v21->m_VertexSize_Position + 4 * v23 - 4);
  v21->m_VertexSize_BoneWeight = v23;
  if ( v24 != nullptr )
    *v24 = v15;
  v25 = src & 0xFFFFFFFC;
  result = InterlockedExchangeAdd(Addend: (volatile LONG *)((src & 0xFFFFFFFC) + 4), Value: -1) - 1;
  if ( result == 0 )
    return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v25);
  return result;
}
