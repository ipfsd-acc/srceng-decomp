// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxwwhelper.cpp
// Functions: 6
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxwwhelper.h"

//------------------------------------------------------------------------------
// Address: 0x100E3A40
// Name: public: static bool GFxWWHelper::IsAsianChar(unsigned int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
static bool __stdcall GFxWWHelper::IsAsianChar(char a1, wchar_t a2)
{
  if ( (a1 & 4) != 0
    && (a2 >= 0x1100u && a2 <= 0x11FFu || a2 >= 0x3130u && a2 <= 0x318Fu || (unsigned __int16)(a2 + 21504) <= 0x2BA3u) )
  {
    return false;
  }
  return a2 >= 0x1100u && a2 <= 0x11FFu
      || a2 >= 0x3000u && a2 <= 0xD7AFu
      || a2 >= 0xF900u && a2 <= 0xFAFFu
      || (unsigned __int16)(a2 + 256) <= 0xDCu;
}

//------------------------------------------------------------------------------
// Address: 0x100E3AF0
// Name: public: static unsigned int GFxWWHelper::FindNextNonWhiteSpace(wchar_t const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __stdcall GFxWWHelper::FindNextNonWhiteSpace(
        const wchar_t *pos,
        unsigned int a2,
        unsigned int maxPos)
{
  unsigned int result; // eax
  int v4; // ecx

  for ( result = a2; ; ++result )
  {
    v4 = pos[result];
    if ( v4 != 9 && v4 != 13 && v4 != 32 && (_WORD)v4 != 12288 )
      break;
  }
  if ( pos != nullptr && pos[result] == 10 )
    ++result;
  if ( result > maxPos )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E3B40
// Name: public: static unsigned int GFxWWHelper::FindPrevNonWhiteSpace(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static int __stdcall GFxWWHelper::FindPrevNonWhiteSpace(const wchar_t *pos, int a2)
{
  int result; // eax
  int v3; // ecx

  result = a2;
  if ( a2 < 0 )
    return -1;
  while ( 1 )
  {
    v3 = pos[result];
    if ( v3 != 9 && v3 != 13 && v3 != 32 && (_WORD)v3 != 12288 && pos[result] != 10 )
      break;
    if ( --result < 0 )
      return -1;
  }
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E3B90
// Name: public: static bool GFxWWHelper::FindCharWithFlags(unsigned int,wchar_t,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static bool __stdcall GFxWWHelper::FindCharWithFlags(char a1, wchar_t a2, unsigned __int8 a3)
{
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  wchar_t v7; // dx

  if ( (a1 & 2) == 0 )
    return false;
  v4 = 0;
  v5 = 111;
  while ( 1 )
  {
    v6 = v4 + (v5 - v4) / 2;
    v7 = (wchar_t)(&GFxWWHelper::CharBreakInfoArray)[v6];
    if ( a2 == v7 )
      break;
    if ( a2 >= v7 )
      v4 = v6 + 1;
    else
      v5 = v6 - 1;
    if ( v4 > v5 )
      return false;
  }
  return (a3 & (unsigned __int8)byte_1032FFBA[4 * v6]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E3C00
// Name: public: static bool GFxWWHelper::IsLineBreakOpportunityAt(unsigned int,wchar_t,wchar_t)
// Source: json
//------------------------------------------------------------------------------
static bool __stdcall GFxWWHelper::IsLineBreakOpportunityAt(char wwMode, wchar_t prevChar, wchar_t curChar)
{
  if ( prevChar == 0 )
    return false;
  return (prevChar == 9
       || prevChar == 13
       || prevChar == 32
       || prevChar == 12288
       || GFxWWHelper::IsAsianChar(a1: wwMode, a2: curChar)
       || GFxWWHelper::IsAsianChar(a1: wwMode, a2: prevChar)
       || prevChar == 45)
      && !GFxWWHelper::FindCharWithFlags(a1: wwMode, a2: curChar, a3: 1u)
      && !GFxWWHelper::FindCharWithFlags(a1: wwMode, a2: prevChar, a3: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x100E3C90
// Name: public: static unsigned int GFxWWHelper::FindWordWrapPos(unsigned int,unsigned int,wchar_t const __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxWWHelper::FindWordWrapPos(
        CJob *wwMode,
        char wordWrapPos,
        unsigned int wordWrapPosa,
        unsigned int paraLen,
        int a5,
        unsigned int lineStartPos,
        unsigned int lineLen)
{
  int v7; // ebx
  const wchar_t *v8; // edi
  unsigned int NextNonWhiteSpace; // esi
  int v10; // eax
  int PrevNonWhiteSpace; // eax
  unsigned int result; // eax
  unsigned int lineLena; // [esp+1Ch] [ebp+1Ch]

  if ( (wordWrapPos & 7) == 0 || lineLen == 0 )
    return -1;
  v7 = a5 - lineStartPos;
  v8 = (const wchar_t *)(paraLen + 2 * lineStartPos);
  lineLena = lineLen - 1;
  NextNonWhiteSpace = lineLena;
  if ( lineLena != 0 )
  {
    while ( 1 )
    {
      v10 = v8[NextNonWhiteSpace];
      if ( v10 == 9 || v10 == 13 || v10 == 32 || (_WORD)v10 == 12288 )
        break;
LABEL_10:
      if ( (NextNonWhiteSpace == 0
         || !GFxWWHelper::IsLineBreakOpportunityAt(
               wwMode: wordWrapPos,
               prevChar: v8[NextNonWhiteSpace - 1],
               curChar: v8[NextNonWhiteSpace]))
        && --NextNonWhiteSpace != 0 )
      {
        continue;
      }
      goto LABEL_15;
    }
    PrevNonWhiteSpace = GFxWWHelper::FindPrevNonWhiteSpace(pos: v8, a2: NextNonWhiteSpace);
    if ( PrevNonWhiteSpace != -1 )
    {
      NextNonWhiteSpace = PrevNonWhiteSpace + 1;
      goto LABEL_10;
    }
    NextNonWhiteSpace = GFxWWHelper::FindNextNonWhiteSpace(pos: v8, a2: NextNonWhiteSpace + 1, maxPos: v7 - 1);
  }
LABEL_15:
  if ( NextNonWhiteSpace == 0 )
    return lineLena;
  result = GFxWWHelper::FindNextNonWhiteSpace(pos: v8, a2: NextNonWhiteSpace, maxPos: v7 - 1);
  if ( result == -1 )
    return lineLena;
  return result;
}
