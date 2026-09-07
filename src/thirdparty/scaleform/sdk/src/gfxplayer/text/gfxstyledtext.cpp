// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxstyledtext.cpp
// Functions: 209
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxstyledtext.h"

//------------------------------------------------------------------------------
// Address: 0x1015E890
// Name: int G_iswalnum(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall G_iswalnum(const CFileSystemPassThru *charCode)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1015E8E0
// Name: public: char const __near * GFxStyledText::NewLineStr(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::NewLineStr(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1015E900
// Name: public: void GFxTextParagraph::TextBuffer::Free(class GFxTextAllocator __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxTextParagraph::TextBuffer::Free(GFxFontMap *this, unsigned int pallocator)
{
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->__vftable);
  this->__vftable = nullptr;
  this->SType = State_None;
  this->RefCount = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015E930
// Name: public: wchar_t __near * GFxTextParagraph::TextBuffer::CreatePosition(class GFxTextAllocator __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxFontMap *__thiscall GFxTextParagraph::TextBuffer::CreatePosition(
        int *this,
        GFxFontMap *result,
        int a3,
        unsigned int length)
{
  unsigned int v4; // ebx
  int v6; // eax
  unsigned int v7; // edx
  struct GFxFontMapImpl *pImpl; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx

  v4 = length;
  v6 = *(this + 1);
  if ( *(this + 2) < v6 + length )
  {
    v7 = 2 * (v6 + length);
    if ( *this != 0 )
    {
      v9 = ((int (__stdcall *)(int, unsigned int))GMemory::pGlobalHeap->Realloc)(a1: *this, a2: v7);
    }
    else
    {
      pImpl = result[1].pImpl;
      length = 324;
      v9 = (*(int (__stdcall **)(unsigned int, unsigned int *))(*(_DWORD *)pImpl + 40))(a1: v7, a2: &length);
    }
    *this = v9;
    v6 = *(this + 1);
    *(this + 2) = v6 + v4;
  }
  v10 = v6 - a3;
  if ( v10 != 0 )
    memmove(dst: (unsigned __int8 *)(*this + 2 * (a3 + v4)), src: (unsigned __int8 *)(*this + 2 * a3), count: 2 * v10);
  v11 = *this;
  *(this + 1) += v4;
  return (GFxFontMap *)(v11 + 2 * a3);
}

//------------------------------------------------------------------------------
// Address: 0x1015E9B0
// Name: private: bool GFxTextParagraph::HasNewLine(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextParagraph::HasNewLine(GFxTextParagraph *this)
{
  unsigned int v1; // eax
  GFxFontMap *pObject; // ecx
  unsigned int v3; // edx
  unsigned __int16 *v4; // eax
  int v5; // eax

  v1 = *((_DWORD *)this + 1);
  if ( v1 == 0 )
    return false;
  pObject = this->pObject;
  v3 = v1 - 1;
  if ( pObject != nullptr && v3 < v1 )
    v4 = (unsigned __int16 *)pObject + v3;
  else
    v4 = nullptr;
  v5 = *v4;
  return v5 == 13 || v5 == 10;
}

//------------------------------------------------------------------------------
// Address: 0x1015E9F0
// Name: public: unsigned int GFxTextParagraph::GetLength(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextParagraph::GetLength(GFxResourceId *this)
{
  unsigned int result; // eax
  unsigned int Id; // ecx
  unsigned int v3; // edx
  _WORD *v4; // ecx

  result = *((_DWORD *)this + 1);
  if ( result != 0 )
  {
    Id = this->Id;
    v3 = result - 1;
    if ( Id != 0 && v3 < result )
      v4 = (_WORD *)(Id + 2 * v3);
    else
      v4 = nullptr;
    if ( *v4 == 0 )
      --result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015EA20
// Name: public: wchar_t const __near * GFxTextParagraph::CharactersIterator::GetRemainingTextPtr(unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::CharactersIterator::GetRemainingTextPtr(GFxImportVisitor *this, unsigned int *plen)
{
  int v2; // eax
  unsigned int v3; // eax
  int v4; // edx

  v2 = *((_DWORD *)this + 6);
  if ( v2 != 0 && (v3 = *(_DWORD *)(v2 + 4), (v4 = *((_DWORD *)this + 7)) < v3) )
  {
    if ( plen != nullptr )
      *plen = v3 - v4;
  }
  else
  {
    *plen = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015EA90
// Name: public: static bool GFxSGMLCharIter<wchar_t>::IsSpace(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSGMLCharIter<wchar_t>::IsSpace(void *c, unsigned __int16 ca)
{
  int v2; // eax
  int v3; // esi
  BOOL v5; // eax

  v2 = HIBYTE(ca);
  v3 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v2);
  if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v2) == 0 )
    return false;
  v5 = true;
  if ( v3 != 1 )
    return (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v3 + ((unsigned __int8)ca >> 4))
          & (1 << (ca & 0xF))) != 0;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1015EAF0
// Name: public: static bool GFxSGMLCharIter<wchar_t>::IsDigit(unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxSGMLCharIter<wchar_t>::IsDigit(void *c, unsigned int ca)
{
  return isdigit(c: ca) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015EB10
// Name: public: static bool GFxSGMLParser<wchar_t>::ParseInt(int __near *,wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFxSGMLParser<wchar_t>::ParseInt(_DWORD *a1, unsigned __int16 *a2, unsigned int a3)
{
  int v3; // ecx
  unsigned __int16 *v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // edx
  unsigned int v9; // ebx
  int v10; // ecx
  int v11; // [esp+0h] [ebp-4h]

  v3 = a3;
  if ( a3 == 0 )
    return 0;
  v5 = a2;
  v6 = *a2;
  v7 = 0;
  v8 = 1;
  v11 = 1;
  if ( v6 == 45 )
  {
    v11 = -1;
    v8 = -1;
  }
  else if ( v6 != 43 )
  {
    goto LABEL_7;
  }
  v5 = a2 + 1;
  v3 = --a3;
LABEL_7:
  v9 = 0;
  if ( v3 != 0 )
  {
    while ( isdigit(c: *v5) != 0 )
    {
      v10 = *v5;
      ++v9;
      ++v5;
      v7 = v10 + 10 * v7 - 48;
      if ( v9 >= a3 )
      {
        v8 = v11;
        goto LABEL_11;
      }
    }
    return 0;
  }
  else
  {
LABEL_11:
    *a1 = v7 * v8;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015EBA0
// Name: public: static bool GFxSGMLParser<wchar_t>::ParseFloat(float __near *,wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFxSGMLParser<wchar_t>::ParseFloat(float *a1, unsigned __int16 *a2, int a3)
{
  double v4; // st7
  unsigned __int16 *v5; // esi
  unsigned __int16 *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  double v10; // st6
  unsigned __int16 *v11; // esi
  double v12; // st7
  double v13; // [esp+0h] [ebp-18h]
  double v14; // [esp+8h] [ebp-10h]
  double v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+28h] [ebp+10h]
  int v17; // [esp+28h] [ebp+10h]

  if ( a3 == 0 )
    return 0;
  v4 = 0.0;
  v5 = a2;
  v15 = 0.0;
  v6 = &a2[a3];
  v13 = 1.0;
  v7 = *a2;
  if ( v7 == 45 )
  {
    v13 = -1.0;
LABEL_6:
    v5 = a2 + 1;
    goto LABEL_7;
  }
  if ( v7 == 43 )
    goto LABEL_6;
LABEL_7:
  if ( v5 < v6 )
  {
    while ( 1 )
    {
      v8 = *v5;
      if ( v8 == 46 || v8 == 44 )
        break;
      if ( isdigit(c: *v5) == 0 )
        return 0;
      v16 = *v5++ - 48;
      v4 = (double)v16 + v15 * 10.0;
      v15 = v4;
      if ( v5 >= v6 )
      {
        *a1 = v4 * v13;
        return 1;
      }
    }
    if ( v5 < v6 )
    {
      v9 = *v5;
      if ( v9 == 46 || v9 == 44 )
      {
        v10 = 0.0;
        v11 = v5 + 1;
        v14 = 0.0;
        if ( v11 >= v6 )
        {
LABEL_20:
          v4 = v4 + v10;
          goto LABEL_21;
        }
        while ( isdigit(c: *v11) != 0 )
        {
          v17 = *v11++ - 48;
          v12 = ((double)v17 + v14) * 0.1;
          v14 = v12;
          if ( v11 >= v6 )
          {
            v10 = v12;
            v4 = v15;
            goto LABEL_20;
          }
        }
        return 0;
      }
    }
  }
LABEL_21:
  *a1 = v4 * v13;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015ECB0
// Name: public: void GFxSGMLParser<wchar_t>::AppendToBuf(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSGMLParser<wchar_t>::AppendToBuf(unsigned int *this, unsigned __int8 *src, int a3)
{
  unsigned int v4; // eax
  int v5; // edi
  void *v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  void *v10; // eax

  v4 = *(this + 8);
  v5 = a3;
  if ( a3 + *(this + 9) > v4 )
  {
    v6 = (void *)*(this + 7);
    v7 = a3 + v4;
    *(this + 8) = v7;
    v8 = 2 * v7;
    if ( v6 != nullptr )
    {
      v10 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v6, a3: v8);
    }
    else
    {
      v9 = *this;
      a3 = 324;
      v10 = (void *)(*(int (__thiscall **)(unsigned int, unsigned int, int *))(*(_DWORD *)v9 + 40))(a1: v9, a2: v8, &a3);
    }
    *(this + 7) = (unsigned int)v10;
  }
  memcpy(dst: (unsigned __int8 *)(*(this + 7) + 2 * *(this + 9)), src, count: 2 * v5);
  *(this + 9) += v5;
}

//------------------------------------------------------------------------------
// Address: 0x1015ED30
// Name: public: static int GFxSGMLCharIter<wchar_t>::StrCompare(wchar_t const __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxValue::DisplayInfo *__cdecl GFxSGMLCharIter<wchar_t>::StrCompare(
        GFxValue::DisplayInfo *result,
        const char *a2,
        int a3)
{
  const CFileSystemPassThru *v3; // ecx
  const char *v4; // esi
  const CFileSystemPassThru *v6; // eax
  const CFileSystemPassThru *v7; // ebx
  const CFileSystemPassThru *v8; // ecx
  const CFileSystemPassThru *v9; // eax
  bool v10; // zf
  int slen; // [esp+0h] [ebp-8h]

  if ( a3 == 0 )
    return (GFxValue::DisplayInfo *)-strlen(a2);
  v4 = a2;
  slen = a3;
  do
  {
    G_towlower(charCode: v3, charCodea: LOWORD(result->X));
    v7 = v6;
    result = (GFxValue::DisplayInfo *)((char *)result + 2);
    G_towlower(charCode: v8, charCodea: *v4++);
    v10 = a3-- == 1;
    v3 = v9;
    if ( v10 || v7 == nullptr )
      break;
    if ( v7 != v9 )
      return (GFxValue::DisplayInfo *)((char *)v7 - (char *)v9);
  }
  while ( *v4 != 0 );
  if ( v7 == v9 && (a3 != 0 || *v4 != 0) )
    return (GFxValue::DisplayInfo *)(slen - strlen(a2));
  return (GFxValue::DisplayInfo *)((char *)v7 - (char *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x1015EE30
// Name: public: GFxStyledText::HTMLImageTagInfo::HTMLImageTagInfo(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::HTMLImageTagInfo::HTMLImageTagInfo(
        ILocalize *this@<ecx>,
        wchar_t *pheap,
        int a3,
        unsigned int a4,
        KeyValues *a5)
{
  this->__vftable = nullptr;
  GStringDH::GStringDH(this: (GStringDH *)(this + 1), a2: (struct GMemoryHeap *)pheap);
  GStringDH::GStringDH(this: (GStringDH *)(this + 3), a2: (struct GMemoryHeap *)pheap);
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 9) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1015EE70
// Name: public: void GFxTextParagraph::SetText(class GFxTextAllocator __near *,wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::SetText(
        GFxTextParagraph *this,
        struct GFxTextAllocator *length,
        wchar_t *src,
        unsigned int a4)
{
  unsigned __int8 *v4; // ebx
  unsigned int v5; // esi
  unsigned int v7; // eax
  int v8; // ecx
  GFxFontMap *v9; // eax

  v4 = (unsigned __int8 *)src;
  v5 = a4;
  if ( a4 == -1 )
    goto LABEL_8;
  v7 = a4 - 1;
  if ( (int)(a4 - 1) >= 0 )
  {
    while ( src[v7] != 0 )
    {
      if ( (--v7 & 0x80000000) != 0 )
        goto LABEL_7;
    }
    v5 = v7;
  }
LABEL_7:
  if ( v5 == -1 )
  {
LABEL_8:
    v5 = 0;
    if ( *src != 0 )
    {
      do
        ++v5;
      while ( src[v5] != 0 );
    }
  }
  if ( *((_DWORD *)this + 2) < v5 )
  {
    if ( this->pObject != nullptr )
    {
      v9 = (GFxFontMap *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: this->pObject, a3: 2 * v5);
      v4 = (unsigned __int8 *)src;
    }
    else
    {
      v8 = *((_DWORD *)length + 7);
      a4 = 324;
      v9 = (GFxFontMap *)(*(int (__thiscall **)(int, unsigned int, unsigned int *))(*(_DWORD *)v8 + 40))(
                           a1: v8,
                           a2: 2 * v5,
                           a3: &a4);
    }
    this->pObject = v9;
    *((_DWORD *)this + 2) = v5;
  }
  if ( v5 != 0 )
    memcpy(dst: (unsigned __int8 *)this->pObject, src: v4, count: 2 * v5);
  ++*((_WORD *)this + 18);
  *((_DWORD *)this + 1) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1015EF90
// Name: public: GFxStyledText::HTMLImageTagInfo::HTMLImageTagInfo(struct GFxStyledText::HTMLImageTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxStyledText::HTMLImageTagInfo *__thiscall GFxStyledText::HTMLImageTagInfo::HTMLImageTagInfo(GFxStyledText::HTMLImageTagInfo *this, const struct GString *a2)
{
  if ( a2->HeapTypeBits != 0 )
    ++*(_DWORD *)(a2->HeapTypeBits + 4);
  *(struct GString *)this = (struct GString)a2->pData;
  GStringDH::CopyConstructHelper(this: (GStringDH *)((char *)this + 4), a2: a2 + 1, pheap: (CUtlBuffer *)a2[2].pData);
  GStringDH::CopyConstructHelper(this: (GStringDH *)((char *)this + 12), a2: a2 + 3, pheap: (CUtlBuffer *)a2[4].pData);
  *((struct GString *)this + 5) = a2[5];
  *((struct GString *)this + 6) = a2[6];
  *((struct GString *)this + 7) = a2[7];
  *((struct GString *)this + 8) = a2[8];
  *((struct GString *)this + 9) = a2[9];
  *((_BYTE *)this + 40) = a2[10].pData;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015F000
// Name: public: static bool GFxSGMLParser<wchar_t>::ParseHexInt(unsigned long __near *,wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFxSGMLParser<wchar_t>::ParseHexInt(_DWORD *a1, wchar_t *a2, unsigned int a3)
{
  int v4; // esi
  unsigned int v5; // ebx
  const CFileSystemPassThru *v7; // ecx
  __int16 v8; // ax
  int v9; // eax

  if ( a3 == 0 )
    return 0;
  v4 = 0;
  v5 = 0;
  while ( isxdigit(c: *a2) != 0 )
  {
    v4 *= 16;
    G_towlower(charCode: v7, charCodea: *a2);
    if ( (unsigned __int16)(v8 - 48) <= 9u )
    {
      v9 = v8 & 0xF;
LABEL_9:
      v4 |= v9;
      goto LABEL_10;
    }
    if ( (unsigned __int16)(v8 - 97) <= 5u )
    {
      v9 = (((_BYTE)v8 - 1) & 0xF) + 10;
      goto LABEL_9;
    }
LABEL_10:
    ++v5;
    ++a2;
    if ( v5 >= a3 )
    {
      *a1 = v4;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015F080
// Name: private: unsigned long GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(unsigned __int16 **this)
{
  _WORD *v2; // eax
  unsigned int v3; // ecx
  GFxValue::DisplayInfo *v4; // eax
  GFxValue::DisplayInfo *v6; // eax
  GFxValue::DisplayInfo *v7; // eax
  _WORD *v8; // eax
  const CFileSystemPassThru *v9; // ecx
  unsigned __int16 *v10; // eax
  int v11; // edi
  void *v12; // ecx
  int v13; // eax
  unsigned __int16 *v14; // eax
  const CFileSystemPassThru *v15; // ecx
  __int16 v16; // ax
  int v17; // eax
  _WORD *v18; // edx
  unsigned __int16 *v19; // eax
  int v20; // edx
  unsigned __int16 *v21; // [esp+4h] [ebp-4h]

  v2 = *this;
  v3 = (unsigned int)*(this + 2);
  if ( (unsigned int)v2 >= v3 )
    return 0;
  *(this + 1) = v2;
  if ( *v2 != 38 )
    return (int)*(this + 3);
  v4 = (GFxValue::DisplayInfo *)(v2 + 1);
  *(this + 3) = (unsigned __int16 *)38;
  *(this + 1) = (unsigned __int16 *)v4;
  if ( (unsigned int)&v4->Y + 2 <= v3 )
  {
    if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v4, a2: "quot;", a3: 5) == nullptr )
    {
      *(this + 1) += 5;
      *(this + 3) = (unsigned __int16 *)34;
      return (int)*(this + 3);
    }
    if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: (GFxValue::DisplayInfo *)*(this + 1), a2: "apos;", a3: 5) == nullptr )
    {
      *(this + 1) += 5;
      *(this + 3) = (unsigned __int16 *)39;
      return (int)*(this + 3);
    }
    if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: (GFxValue::DisplayInfo *)*(this + 1), a2: "nbsp;", a3: 5) == nullptr )
    {
      *(this + 1) += 5;
      *(this + 3) = (unsigned __int16 *)160;
      return (int)*(this + 3);
    }
  }
  v6 = (GFxValue::DisplayInfo *)*(this + 1);
  if ( &v6->Y <= (long double *)*(this + 2)
    && GFxSGMLCharIter<wchar_t>::StrCompare(result: v6, a2: "amp;", a3: 4) == nullptr )
  {
    *(this + 1) += 4;
    *(this + 3) = (unsigned __int16 *)38;
    return 38;
  }
  v7 = (GFxValue::DisplayInfo *)*(this + 1);
  if ( (char *)&v7->X + 6 <= (char *)*(this + 2) )
  {
    if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v7, a2: "lt;", a3: 3) == nullptr )
    {
      *(this + 1) += 3;
      *(this + 3) = (unsigned __int16 *)60;
      return (int)*(this + 3);
    }
    if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: (GFxValue::DisplayInfo *)*(this + 1), a2: "gt;", a3: 3) == nullptr )
    {
      *(this + 1) += 3;
      *(this + 3) = (unsigned __int16 *)62;
      return (int)*(this + 3);
    }
  }
  v8 = *(this + 1);
  v9 = (const CFileSystemPassThru *)(v8 + 2);
  if ( v8 + 2 > *(this + 2) || *v8 != 35 )
    return (int)*(this + 3);
  v21 = *(this + 1);
  v10 = v8 + 1;
  *(this + 1) = v10;
  v11 = 0;
  G_towlower(charCode: v9, charCodea: *v10 == 120);
  if ( v13 == 0 )
  {
    if ( GFxSGMLCharIter<wchar_t>::IsDigit(c: v12, ca: **(this + 1)) )
    {
      if ( *(this + 1) >= *(this + 2) )
        goto LABEL_39;
      do
      {
        v18 = *(this + 1);
        if ( *v18 == 59 )
          break;
        if ( isdigit(c: (unsigned __int16)*v18) == 0 )
          goto LABEL_31;
        v19 = *(this + 1);
        v20 = *v19++;
        *(this + 1) = v19;
        v11 = v20 + 10 * v11 - 48;
      }
      while ( v19 < *(this + 2) );
      if ( v11 != -1 )
      {
LABEL_39:
        v14 = *(this + 1);
        goto LABEL_40;
      }
    }
LABEL_31:
    *(this + 1) = v21;
    return (int)*(this + 3);
  }
  v14 = ++*(this + 1);
  if ( v14 >= *(this + 2) )
    goto LABEL_40;
  while ( *v14 != 59 )
  {
    if ( isxdigit(c: *v14) == 0 )
      goto LABEL_31;
    v11 *= 16;
    G_towlower(charCode: v15, charCodea: **(this + 1));
    if ( (unsigned __int16)(v16 - 48) <= 9u )
    {
      v17 = v16 & 0xF;
LABEL_28:
      v11 |= v17;
      goto LABEL_29;
    }
    if ( (unsigned __int16)(v16 - 97) <= 5u )
    {
      v17 = (((_BYTE)v16 - 1) & 0xF) + 10;
      goto LABEL_28;
    }
LABEL_29:
    v14 = ++*(this + 1);
    if ( v14 >= *(this + 2) )
      break;
  }
  if ( v11 == -1 )
    goto LABEL_31;
LABEL_40:
  if ( *v14 == 59 )
    *(this + 1) = v14 + 1;
  *(this + 3) = (unsigned __int16 *)v11;
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1015F2F0
// Name: public: static int GFxSGMLCharIter<wchar_t>::StrCompare(wchar_t const __near *,unsigned int,wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFxSGMLCharIter<wchar_t>::StrCompare(int a1, int a2, wchar_t *a3, CFileSystemPassThru *charCode)
{
  const CFileSystemPassThru *v4; // ecx
  wchar_t *v5; // esi
  const CFileSystemPassThru *v6; // eax
  const CFileSystemPassThru *v7; // edi
  const CFileSystemPassThru *v8; // ecx
  const CFileSystemPassThru *v9; // eax
  CFileSystemPassThru *v11; // [esp+0h] [ebp-8h]
  int v12; // [esp+4h] [ebp-4h]

  if ( a2 == 0 )
    return -(int)charCode;
  v4 = charCode;
  v5 = a3;
  v11 = charCode;
  v12 = a2;
  do
  {
    G_towlower(charCode: v4, charCodea: *(wchar_t *)((char *)v5 + a1 - (_DWORD)a3));
    v7 = v6;
    G_towlower(charCode: v8, charCodea: *v5);
    v4 = v9;
    ++v5;
    if ( --a2 == 0 || v7 == nullptr )
      break;
    if ( v7 != v9 )
      return (char *)v7 - (char *)v9;
    charCode = (CFileSystemPassThru *)((char *)charCode - 1);
  }
  while ( charCode != nullptr );
  if ( v7 == v9 && (a2 != 0 || charCode != nullptr) )
    return v12 - (_DWORD)v11;
  return (char *)v7 - (char *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x1015F380
// Name: public: static int GFxSGMLElementDesc::Comparator<wchar_t>::Less(struct GFxSGMLElementDesc const __near &,struct GFxSGMLElementDesc::Comparable<wchar_t> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl GFxSGMLElementDesc::Comparator<wchar_t>::Less(const char **a1, int a2)
{
  return -(int)GFxSGMLCharIter<wchar_t>::StrCompare(
                 result: *(GFxValue::DisplayInfo **)a2,
                 a2: *a1,
                 a3: *(_DWORD *)(a2 + 4)) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015F3B0
// Name: public: GFxTextHTMLImageTagDesc::GFxTextHTMLImageTagDesc(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GFxTextHTMLImageTagDesc::GFxTextHTMLImageTagDesc(char *this)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxTextImageDesc::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  GMatrix2D::SetIdentity(this: (float *)this + 8);
  *(_DWORD *)this = &GFxTextHTMLImageTagDesc::`vftable';
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 56));
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 60));
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *(this + 76) = 0;
  *((_DWORD *)this + 18) = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015F410
// Name: public: virtual GFxTextHTMLImageTagDesc::~GFxTextHTMLImageTagDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextHTMLImageTagDesc::~GFxTextHTMLImageTagDesc(IShaderAPI *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi
  GRefCountNTSImpl *v4; // ecx
  GFxShapeBase *v5; // ecx

  v2 = (volatile LONG *)(*(_DWORD *)(this + 15) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 14) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = *((GRefCountNTSImpl **)this + 3);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  v5 = *((GFxShapeBase **)this + 2);
  if ( v5 != nullptr )
    GFxShapeBase::Release(this: v5);
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x1015F4B0
// Name: public: void GFxTextParagraph::SetFormat(class GFxTextAllocator __near *,class GFxTextParagraphFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::SetFormat(
        GFxFontMap::MapEntry *this,
        CMaterial *pallocator,
        GRefCountNTSImpl *pallocator_4)
{
  float GlyphOffsetY; // ecx
  GRefCountNTSImpl *v5; // eax
  GRefCountNTSImpl *ParagraphFormat; // esi
  float v7; // ecx
  int v8; // [esp+0h] [ebp-20h]
  int v9; // [esp+4h] [ebp-1Ch]
  IShaderAPI v10; // [esp+8h] [ebp-18h] BYREF

  GlyphOffsetY = this->GlyphOffsetY;
  if ( GlyphOffsetY == 0.0 )
  {
    ParagraphFormat = (GRefCountNTSImpl *)GFxTextAllocator::AllocateParagraphFormat(
                                            this: pallocator,
                                            srcfmt: pallocator_4,
                                            pfmt: v8,
                                            a4: v9,
                                            a5: (ImageFormat)v10.__vftable);
  }
  else
  {
    GFxTextParagraphFormat::Merge(
      this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)LODWORD(GlyphOffsetY),
      a2: (GFxTextParagraphFormat *)&v10,
      a3: (int)pallocator_4);
    ParagraphFormat = (GRefCountNTSImpl *)GFxTextAllocator::AllocateParagraphFormat(
                                            this: pallocator,
                                            srcfmt: v5,
                                            pfmt: v8,
                                            a4: v9,
                                            a5: (ImageFormat)v10.__vftable);
    v10.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
    GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v10);
    GRefCountImplCore::~GRefCountImplCore(this: &v10);
  }
  if ( ParagraphFormat != nullptr )
    ++ParagraphFormat->RefCount;
  v7 = this->GlyphOffsetY;
  if ( v7 != 0.0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v7));
  LODWORD(this->GlyphOffsetY) = ParagraphFormat;
  ++*((_WORD *)this + 18);
  if ( ParagraphFormat != nullptr )
    GRefCountNTSImpl::Release(this: ParagraphFormat);
}

//------------------------------------------------------------------------------
// Address: 0x1015F530
// Name: protected: class GFxTextParagraph __near * GFxStyledText::GetLastParagraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::GetLastParagraph(SFTextObjectImpl *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1015F6C0
// Name: public: void GFxStyledText::SetParagraphFormat(class GFxTextParagraphFormat const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::SetParagraphFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        GRefCountNTSImpl *fmt,
        unsigned int indexInPara,
        unsigned int runLen)
{
  unsigned int v4; // esi
  GFxValue::ValueType Type; // ebx
  unsigned int v6; // edx
  int *v7; // edi
  CMaterial *v8; // esi
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v9; // ecx
  GRefCountNTSImpl *v10; // eax
  GRefCountNTSImpl *ParagraphFormat; // esi
  GRefCountNTSImpl *v12; // ecx
  unsigned int v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  _WORD *v16; // ecx
  int v17; // [esp+0h] [ebp-34h]
  int v18; // [esp+4h] [ebp-30h]
  ImageFormat v19; // [esp+8h] [ebp-2Ch]
  IShaderAPI v20; // [esp+Ch] [ebp-28h] BYREF
  GFxValue index; // [esp+24h] [ebp-10h] BYREF

  v4 = indexInPara;
  *((_DWORD *)&index.Value.pStringManaged + 1) = this;
  GFxStyledText::GetParagraphByIndex(
    (SFTextObjectImpl *)this,
    &index,
    indexa: indexInPara,
    pindexInParagraph: &indexInPara);
  Type = index.Type;
  v6 = runLen - v4;
  runLen -= v4;
  while ( index.pObjectInterface != nullptr )
  {
    if ( Type < VT_Undefined )
      break;
    index.Value.pString = (const char *)&index.pObjectInterface[1];
    if ( Type >= (int)index.pObjectInterface[1].pMovieRoot )
      break;
    v7 = *((int **)index.pObjectInterface->pMovieRoot + Type);
    if ( indexInPara == 0 )
    {
      v8 = *(CMaterial **)(*((_DWORD *)&index.Value.pStringManaged + 1) + 8);
      v9 = (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v7[3];
      if ( v9 != nullptr )
      {
        GFxTextParagraphFormat::Merge(this: v9, a2: (GFxTextParagraphFormat *)&v20, a3: (int)fmt);
        ParagraphFormat = (GRefCountNTSImpl *)GFxTextAllocator::AllocateParagraphFormat(
                                                this: v8,
                                                srcfmt: v10,
                                                pfmt: v17,
                                                a4: v18,
                                                a5: v19);
        v20.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
        GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v20);
        GRefCountImplCore::~GRefCountImplCore(this: &v20);
      }
      else
      {
        ParagraphFormat = (GRefCountNTSImpl *)GFxTextAllocator::AllocateParagraphFormat(
                                                this: v8,
                                                srcfmt: fmt,
                                                pfmt: v17,
                                                a4: v18,
                                                a5: v19);
      }
      if ( ParagraphFormat != nullptr )
      {
        ++ParagraphFormat->RefCount;
        Type = index.Type;
      }
      v12 = (GRefCountNTSImpl *)v7[3];
      if ( v12 != nullptr )
        GRefCountNTSImpl::Release(this: v12);
      v7[3] = (int)ParagraphFormat;
      ++*((_WORD *)v7 + 18);
      if ( ParagraphFormat != nullptr )
        GRefCountNTSImpl::Release(this: ParagraphFormat);
      v6 = runLen;
    }
    if ( v6 == 0 )
      break;
    v13 = v7[1];
    if ( v13 != 0 )
    {
      v14 = *v7;
      v15 = v13 - 1;
      if ( v14 != 0 && v15 < v13 )
        v16 = (_WORD *)(v14 + 2 * v15);
      else
        v16 = nullptr;
      if ( *v16 == 0 )
        --v13;
    }
    if ( v6 <= v13 )
      v13 = v6 + indexInPara;
    v6 += indexInPara - v13;
    runLen = v6;
    indexInPara = 0;
    if ( Type < (int)*index.Value.pStringManaged )
      index.Type = ++Type;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F7F0
// Name: public: unsigned int GFxStyledText::GetLength(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxStyledText::GetLength(GFxStyledText *this)
{
  unsigned int result; // eax
  _DWORD *v2; // ebx
  int i; // edi
  int *v4; // edx
  unsigned int v5; // ecx
  int v6; // edx
  unsigned int v7; // esi
  _WORD *v8; // edx

  result = 0;
  v2 = (_DWORD *)((char *)this + 12);
  for ( i = 0; v2 != nullptr && i >= 0 && i < v2[1]; ++i )
  {
    v4 = *(int **)(*v2 + 4 * i);
    v5 = v4[1];
    if ( v5 != 0 )
    {
      v6 = *v4;
      v7 = v5 - 1;
      if ( v6 != 0 && v7 < v5 )
        v8 = (_WORD *)(v6 + 2 * v7);
      else
        v8 = nullptr;
      if ( *v8 == 0 )
        --v5;
    }
    result += v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015F840
// Name: public: class GString GFxStyledText::GetText(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxStyledText::GetText(GFxStyledText *this, CUtlMemory<CImagePacker,int> *a2)
{
  _DWORD *v3; // edi
  int v4; // esi
  int v5; // eax
  RGB888_t *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned __int8 *v9; // edx

  GString::GString(this: a2);
  v3 = (_DWORD *)((char *)this + 12);
  v4 = 0;
  while ( v3 != nullptr && v4 >= 0 && v4 < v3[1] )
  {
    v5 = *(_DWORD *)(*v3 + 4 * v4);
    v6 = *(RGB888_t **)v5;
    v7 = *(_DWORD *)(v5 + 4);
    if ( v7 != 0 )
    {
      v8 = v7 - 1;
      if ( v6 != nullptr && v8 < v7 )
        v9 = &v6->r + 2 * v8;
      else
        v9 = nullptr;
      if ( *(_WORD *)v9 == 0 )
        --v7;
    }
    GString::AppendString(this: a2, pstr: v6, a3: v7);
    if ( v4 < v3[1] )
      ++v4;
  }
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1015F8B0
// Name: public: void GFxStyledText::GetText(class GFxWStringBuffer __near *)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxStyledText::GetText(CUtlMemory<GFxValue,int> *this, GFxWStringBuffer *pBuffer)
{
  unsigned int Length; // eax
  int v4; // edi
  CUtlMemory<GFxValue,int> *v5; // ebx
  GFxValue::ObjectInterface *v6; // eax
  struct GFxMovieRoot *pMovieRoot; // esi
  unsigned __int8 *v8; // ecx
  unsigned int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned int oldSz; // [esp+Ch] [ebp-4h]

  Length = GFxStyledText::GetLength((GFxStyledText *)this);
  GFxWStringBuffer::Resize(this: pBuffer, a2: Length + 1);
  v4 = 0;
  v5 = this + 1;
  oldSz = 0;
  while ( v5 != nullptr && v4 >= 0 && v4 < v5->m_nAllocationCount )
  {
    v6 = (&v5->m_pMemory->pObjectInterface)[v4];
    pMovieRoot = v6[1].pMovieRoot;
    v8 = (unsigned __int8 *)v6->pMovieRoot;
    if ( pMovieRoot != nullptr )
    {
      v9 = (unsigned int)pMovieRoot - 1;
      if ( v8 != nullptr && v9 < (unsigned int)pMovieRoot )
        v10 = &v8[2 * v9];
      else
        v10 = nullptr;
      if ( *(_WORD *)v10 == 0 )
        pMovieRoot = (struct GFxMovieRoot *)((char *)pMovieRoot - 1);
    }
    memcpy(dst: (unsigned __int8 *)&pBuffer->pText[oldSz], src: v8, count: 2 * (_DWORD)pMovieRoot);
    oldSz += (unsigned int)pMovieRoot;
    if ( v4 < v5->m_nAllocationCount )
      ++v4;
  }
  pBuffer->pText[oldSz] = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015F990
// Name: public: void GFxSGMLCharIter<wchar_t>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSGMLCharIter<wchar_t>::operator++(GFxValue::ObjectInterface::ObjVisitor *this)
{
  bool v1; // zf
  GFxValue::ObjectInterface::ObjVisitor_vtbl *v2; // eax

  v1 = *((_BYTE *)this + 16) == 0;
  v2 = *((GFxValue::ObjectInterface::ObjVisitor_vtbl **)this + 1);
  this->__vftable = v2;
  if ( v1 || LOWORD(v2->dtr_ObjVisitor) != 38 )
  {
    if ( (unsigned int)v2 < *((_DWORD *)this + 2) )
    {
      *((_DWORD *)this + 3) = LOWORD(v2->dtr_ObjVisitor);
      *((_DWORD *)this + 1) = (char *)&v2->dtr_ObjVisitor + 2;
    }
  }
  else
  {
    GFxSGMLCharIter<wchar_t>::DecodeEscapedChar((unsigned __int16 **)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015FA50
// Name: public: static struct GFxSGMLElementDesc const __near * GFxSGMLElementDesc::FindElem<wchar_t>(wchar_t const __near *,unsigned int,struct GFxSGMLElementDesc const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char **__cdecl GFxSGMLElementDesc::FindElem<wchar_t>(GFxValue::DisplayInfo *a1, int a2, int a3, int a4)
{
  unsigned int v4; // esi
  unsigned int v5; // eax
  const char **v6; // esi
  GFxValue::DisplayInfo *v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h]

  v4 = a4;
  v8 = a1;
  v9 = a2;
  v5 = G_LowerBoundSliced<GFxSGMLElementDesc const *,GFxSGMLElementDesc::Comparable<wchar_t>,int (__cdecl *)(GFxSGMLElementDesc const &,GFxSGMLElementDesc::Comparable<wchar_t> const &)>(
         a1: &a3,
         a2: 0,
         a3: a4,
         a4: (int)&v8,
         a5: (int (__cdecl *)(int, int))GFxSGMLElementDesc::Comparator<wchar_t>::Less);
  if ( v5 >= v4 )
    return nullptr;
  v6 = (const char **)(a3 + 12 * v5);
  if ( GFxSGMLCharIter<wchar_t>::StrCompare(result: v8, a2: *v6, a3: v9) != nullptr )
    return nullptr;
  else
    return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1015FAB0
// Name: protected: void GFxSGMLParser<wchar_t>::SkipName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSGMLParser<wchar_t>::SkipName(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  bool v5; // zf
  _WORD *v6; // eax

  if ( *(_DWORD *)(this + 4) == 2 && *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) )
  {
    do
    {
      v2 = *(_DWORD *)(this + 20);
      if ( v2 == 61 )
        break;
      if ( v2 == 62 )
        break;
      if ( v2 == 60 )
        break;
      if ( v2 == 47 )
        break;
      v3 = BYTE1(v2);
      v4 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v3);
      if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v3) != 0
        && (v4 == 1
         || (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v4 + ((unsigned __int8)v2 >> 4))
           & (1 << (v2 & 0xF))) != 0) )
      {
        break;
      }
      v5 = *(_BYTE *)(this + 24) == 0;
      v6 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v6;
      if ( v5 || *v6 != 38 )
      {
        if ( (unsigned int)v6 < *(_DWORD *)(this + 16) )
        {
          *(_DWORD *)(this + 20) = (unsigned __int16)*v6;
          *(_DWORD *)(this + 12) = v6 + 1;
        }
      }
      else
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
      }
    }
    while ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015FB70
// Name: protected: void GFxSGMLParser<wchar_t>::SkipSpaces(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxSGMLParser<wchar_t>::SkipSpaces(int this)
{
  unsigned int result; // eax
  int v3; // edx
  char v4; // cl
  bool v5; // zf
  int v6; // ecx

  result = *(_DWORD *)(this + 8);
  if ( result < *(_DWORD *)(this + 16) )
  {
    do
    {
      result = *(unsigned __int16 *)(this + 20);
      v3 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + (result >> 8));
      if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + (result >> 8)) == 0 )
        break;
      if ( v3 != 1 )
      {
        v4 = result & 0xF;
        result = v3 + ((unsigned __int8)result >> 4);
        if ( (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + result) & (1 << v4)) == 0 )
          break;
      }
      v5 = *(_BYTE *)(this + 24) == 0;
      result = *(_DWORD *)(this + 12);
      *(_DWORD *)(this + 8) = result;
      if ( v5 || *(_WORD *)result != 38 )
      {
        if ( result < *(_DWORD *)(this + 16) )
        {
          v6 = *(unsigned __int16 *)result;
          result += 2;
          *(_DWORD *)(this + 20) = v6;
          *(_DWORD *)(this + 12) = result;
        }
      }
      else
      {
        result = GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
      }
    }
    while ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015FC00
// Name: protected: void GFxSGMLParser<wchar_t>::SkipComment(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__thiscall GFxSGMLParser<wchar_t>::SkipComment(int this)
{
  int v2; // esi
  bool v3; // zf
  _WORD *v4; // eax
  int v5; // eax
  unsigned __int16 *result; // eax
  unsigned __int16 **v7; // ecx
  int v8; // edx

  v2 = 0;
  if ( *(_DWORD *)(this + 20) != 0 )
  {
    do
    {
      if ( v2 == 3 )
        break;
      v3 = *(_BYTE *)(this + 24) == 0;
      v4 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v4;
      if ( v3 || *v4 != 38 )
      {
        if ( (unsigned int)v4 < *(_DWORD *)(this + 16) )
        {
          *(_DWORD *)(this + 20) = (unsigned __int16)*v4;
          *(_DWORD *)(this + 12) = v4 + 1;
        }
      }
      else
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
      }
      v5 = *(_DWORD *)(this + 20);
      if ( v5 == 45 )
      {
        if ( v2 < 2 )
          ++v2;
      }
      else if ( v5 == 62 )
      {
        if ( v2 == 2 )
          v2 = 3;
      }
      else
      {
        v2 = 0;
      }
    }
    while ( v5 != 0 );
  }
  result = *(unsigned __int16 **)(this + 8);
  v7 = (unsigned __int16 **)(this + 8);
  if ( (unsigned int)result < *(_DWORD *)(this + 16) && v2 == 3 )
  {
    v3 = *(_BYTE *)(this + 24) == 0;
    result = *(unsigned __int16 **)(this + 12);
    *v7 = result;
    if ( v3 || *result != 38 )
    {
      if ( (unsigned int)result < *(_DWORD *)(this + 16) )
      {
        v8 = *result++;
        *(_DWORD *)(this + 20) = v8;
        *(_DWORD *)(this + 12) = result;
      }
    }
    else
    {
      return (unsigned __int16 *)GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: v7);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015FCB0
// Name: protected: void GFxSGMLParser<wchar_t>::SkipAttribute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSGMLParser<wchar_t>::SkipAttribute(int this)
{
  unsigned __int16 v2; // ax
  int v3; // ecx
  int v4; // edx
  bool v5; // zf
  _WORD *v6; // eax
  int v7; // eax
  _WORD *v8; // eax
  int v9; // ebx
  _WORD *v10; // eax
  unsigned int v11; // eax
  _WORD *v12; // eax
  int v13; // eax

  if ( *(_DWORD *)(this + 4) == 7 )
  {
    GFxSGMLParser<wchar_t>::SkipSpaces(this);
    while ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) )
    {
      v2 = *(_WORD *)(this + 20);
      v3 = HIBYTE(v2);
      v4 = (unsigned __int16)word_10299FE0[v3];
      if ( word_10299FE0[v3] == 0
        || v4 != 1 && ((unsigned __int16)word_10299FE0[v4 + ((unsigned __int8)v2 >> 4)] & (1 << (v2 & 0xF))) == 0
        || *(_DWORD *)(this + 20) == 61 )
      {
        break;
      }
      v5 = *(_BYTE *)(this + 24) == 0;
      v6 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v6;
      if ( v5 || *v6 != 38 )
      {
        if ( (unsigned int)v6 < *(_DWORD *)(this + 16) )
        {
          *(_DWORD *)(this + 20) = (unsigned __int16)*v6;
          *(_DWORD *)(this + 12) = v6 + 1;
        }
      }
      else
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
      }
    }
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
    {
LABEL_14:
      *(_DWORD *)(this + 4) = 1;
      return;
    }
    v7 = *(_DWORD *)(this + 20);
    if ( v7 == 61 )
    {
      v5 = *(_BYTE *)(this + 24) == 0;
      v8 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v8;
      if ( v5 || *v8 != 38 )
      {
        if ( (unsigned int)v8 < *(_DWORD *)(this + 16) )
        {
          *(_DWORD *)(this + 20) = (unsigned __int16)*v8;
          *(_DWORD *)(this + 12) = v8 + 1;
        }
        GFxSGMLParser<wchar_t>::SkipSpaces(this);
        *(_DWORD *)(this + 4) = 8;
      }
      else
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        GFxSGMLParser<wchar_t>::SkipSpaces(this);
        *(_DWORD *)(this + 4) = 8;
      }
    }
    else if ( v7 == 47 || v7 == 62 )
    {
      *(_DWORD *)(this + 4) = 9;
    }
    else
    {
      *(_DWORD *)(this + 4) = 1;
    }
  }
  if ( *(_DWORD *)(this + 4) == 8 )
  {
    v9 = *(_DWORD *)(this + 20);
    if ( v9 == 34 || v9 == 39 )
    {
      while ( 1 )
      {
        v5 = *(_BYTE *)(this + 24) == 0;
        v10 = *(_WORD **)(this + 12);
        *(_DWORD *)(this + 8) = v10;
        if ( v5 || *v10 != 38 )
        {
          if ( (unsigned int)v10 < *(_DWORD *)(this + 16) )
          {
            *(_DWORD *)(this + 20) = (unsigned __int16)*v10;
            *(_DWORD *)(this + 12) = v10 + 1;
          }
        }
        else
        {
          GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        }
        v11 = *(_DWORD *)(this + 8);
        if ( v11 >= *(_DWORD *)(this + 16) )
          break;
        if ( *(_DWORD *)(this + 20) == v9 )
        {
          if ( v11 >= *(_DWORD *)(this + 16) )
            goto LABEL_14;
          v5 = *(_BYTE *)(this + 24) == 0;
          v12 = *(_WORD **)(this + 12);
          *(_DWORD *)(this + 8) = v12;
          if ( v5 || *v12 != 38 )
          {
            if ( (unsigned int)v12 < *(_DWORD *)(this + 16) )
            {
              *(_DWORD *)(this + 20) = (unsigned __int16)*v12;
              *(_DWORD *)(this + 12) = v12 + 1;
            }
          }
          else
          {
            GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
          }
          GFxSGMLParser<wchar_t>::SkipSpaces(this);
          v13 = *(_DWORD *)(this + 20);
          if ( v13 == 62 || v13 == 47 )
            *(_DWORD *)(this + 4) = 9;
          else
            *(_DWORD *)(this + 4) = 7;
          return;
        }
      }
    }
    goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015FEA0
// Name: protected: void GFxSGMLParser<wchar_t>::ParseName(wchar_t const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxSGMLParser<wchar_t>::ParseName(char *this, unsigned __int8 **a2, unsigned int *a3)
{
  unsigned int result; // eax
  char *v5; // edi
  unsigned __int8 *v6; // ecx
  int v7; // edx
  char v8; // cl
  unsigned int v9; // edi
  unsigned int v10; // eax
  void *v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  void *v15; // eax
  unsigned int v16; // eax
  int v17; // edi
  void *v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // ecx
  void *v22; // eax
  unsigned __int8 *v23; // edx
  unsigned int v24; // eax
  int v25; // edi
  unsigned int v26; // ecx
  void *v27; // edx
  unsigned int v28; // eax
  unsigned int v29; // eax
  int v30; // ecx
  void *v31; // eax
  bool v32; // zf
  int v33; // ecx
  unsigned __int8 *src; // [esp+8h] [ebp-Ch] BYREF
  unsigned __int8 *v35; // [esp+Ch] [ebp-8h] BYREF
  char v36; // [esp+13h] [ebp-1h]

  result = *((_DWORD *)this + 2);
  v5 = this + 8;
  *a2 = (unsigned __int8 *)result;
  *a3 = 0;
  v6 = *((unsigned __int8 **)this + 2);
  v36 = 0;
  v35 = v6;
  if ( (unsigned int)v6 < *((_DWORD *)this + 4) )
  {
    do
    {
      result = *((_DWORD *)this + 5);
      if ( result == 61 || result == 62 || result == 60 || result == 47 )
        break;
      result = (unsigned __int16)result;
      v7 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + BYTE1(result));
      if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + BYTE1(result)) != 0 )
      {
        if ( v7 == 1 )
          break;
        v8 = result & 0xF;
        result = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable
                 + v7
                 + ((unsigned __int8)result >> 4));
        if ( (result & (1 << v8)) != 0 )
          break;
        v6 = v35;
      }
      if ( v5[16] != 0 && *(_WORD *)v6 == 38 )
      {
        if ( v36 == 0 )
        {
          *((_DWORD *)this + 9) = 0;
          v9 = *a3;
          src = *a2;
          v10 = *((_DWORD *)this + 8);
          if ( v9 > v10 )
          {
            v11 = *((void **)this + 7);
            v12 = v9 + v10;
            *((_DWORD *)this + 8) = v12;
            v13 = 2 * v12;
            if ( v11 != nullptr )
            {
              v15 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v11, a3: v13);
            }
            else
            {
              v14 = *(_DWORD *)this;
              v35 = (unsigned __int8 *)324;
              v15 = (void *)(*(int (__thiscall **)(int, unsigned int, unsigned __int8 **))(*(_DWORD *)v14 + 40))(
                              a1: v14,
                              a2: v13,
                              a3: &v35);
            }
            *((_DWORD *)this + 7) = v15;
          }
          memcpy(dst: (unsigned __int8 *)(*((_DWORD *)this + 7) + 2 * *((_DWORD *)this + 9)), src, count: 2 * v9);
          *((_DWORD *)this + 9) += v9;
          v36 = 1;
        }
        v16 = *((_DWORD *)this + 8);
        v17 = *((_DWORD *)this + 5);
        if ( *((_DWORD *)this + 9) + 6 > v16 )
        {
          v18 = *((void **)this + 7);
          v19 = v16 + 6;
          *((_DWORD *)this + 8) = v19;
          v20 = 2 * v19;
          if ( v18 != nullptr )
          {
            v22 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v18, a3: v20);
          }
          else
          {
            v21 = *(_DWORD *)this;
            src = (unsigned __int8 *)324;
            v22 = (void *)(*(int (__thiscall **)(int, unsigned int, unsigned __int8 **))(*(_DWORD *)v21 + 40))(
                            a1: v21,
                            a2: v20,
                            a3: &src);
          }
          *((_DWORD *)this + 7) = v22;
        }
        *(_WORD *)(*((_DWORD *)this + 7) + 2 * (*((_DWORD *)this + 9))++) = v17;
      }
      else if ( v36 != 0 )
      {
        v23 = *(unsigned __int8 **)v5;
        v24 = *((_DWORD *)this + 8);
        v25 = (*((_DWORD *)v5 + 1) - (int)v6) >> 1;
        v26 = v25 + *((_DWORD *)this + 9);
        v35 = v23;
        if ( v26 > v24 )
        {
          v27 = *((void **)this + 7);
          v28 = v25 + v24;
          *((_DWORD *)this + 8) = v28;
          v29 = 2 * v28;
          if ( v27 != nullptr )
          {
            v31 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v27, a3: v29);
          }
          else
          {
            v30 = *(_DWORD *)this;
            src = (unsigned __int8 *)324;
            v31 = (void *)(*(int (__thiscall **)(int, unsigned int, unsigned __int8 **))(*(_DWORD *)v30 + 40))(
                            a1: v30,
                            a2: v29,
                            a3: &src);
          }
          *((_DWORD *)this + 7) = v31;
        }
        memcpy(dst: (unsigned __int8 *)(*((_DWORD *)this + 7) + 2 * *((_DWORD *)this + 9)), src: v35, count: 2 * v25);
        *((_DWORD *)this + 9) += v25;
      }
      else
      {
        *a3 += (*((_DWORD *)v5 + 1) - (int)v6) >> 1;
      }
      v32 = *(this + 24) == 0;
      result = *((_DWORD *)this + 3);
      v5 = this + 8;
      *((_DWORD *)this + 2) = result;
      if ( v32 || *(_WORD *)result != 38 )
      {
        if ( result < *((_DWORD *)this + 4) )
        {
          v33 = *(unsigned __int16 *)result;
          result += 2;
          *((_DWORD *)this + 5) = v33;
          *((_DWORD *)this + 3) = result;
        }
      }
      else
      {
        result = GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)this + 2);
      }
      v6 = *(unsigned __int8 **)v5;
      v35 = v6;
    }
    while ( (unsigned int)v6 < *((_DWORD *)this + 4) );
    if ( v36 != 0 )
    {
      *a2 = *((unsigned __int8 **)this + 7);
      *a3 = *((_DWORD *)this + 9);
      return (unsigned int)a2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160110
// Name: public: class GFxTextParagraph::FormatRunIterator GFxTextParagraph::GetIterator(void)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxTextParagraph::GetIterator(GFxTextParagraph *this, _DWORD *a2)
{
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = this + 4;
  a2[6] = 0;
  a2[5] = this + 4;
  a2[8] = 0;
  a2[7] = this;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10160140
// Name: public: GFxTextParagraph::FormatRunIterator::FormatRunIterator(class GRangeDataArray<class GPtr<class GFxTextFormat>,class GArrayLH<class GRangeData<class GPtr<class GFxTextFormat>>,2,struct GArrayDefaultPolicy>> const __near &,class GFxTextParagraph::TextBuffer const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GFxTextParagraph::FormatRunIterator::FormatRunIterator(
        int *this,
        GFxZlibSupportBase *a2,
        int a3,
        int a4)
{
  int v5; // eax
  volatile unsigned int RefCount; // edi
  int v7; // eax
  int *v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int *v12; // eax
  int v13; // eax
  int v14; // eax

  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  *(this + 3) = 0;
  *(this + 4) = (int)a2;
  GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(this: a2, index: a4);
  *(this + 5) = (int)a2;
  *(this + 6) = 0;
  if ( v5 >= 0 )
  {
    RefCount = a2->RefCount;
    if ( v5 < RefCount )
      *(this + 6) = v5;
    else
      *(this + 6) = RefCount - 1;
  }
  else
  {
    *(this + 6) = 0;
  }
  *(this + 7) = a3;
  *(this + 8) = 0;
  v7 = *(this + 6);
  if ( v7 >= 0 )
  {
    v8 = (int *)*(this + 5);
    if ( v7 < (unsigned int)v8[1] )
    {
      v9 = 3 * v7;
      v10 = *v8;
      v11 = *(_DWORD *)(*v8 + 4 * v9);
      v12 = (int *)(v10 + 4 * v9);
      if ( a4 >= v11 && a4 <= v12[1] + v11 - 1 )
      {
        *(this + 8) = *v12;
      }
      else
      {
        v13 = *v12;
        if ( a4 > v13 )
        {
          *(this + 8) = v13;
          *(this + 8) = v13 + *(_DWORD *)(*(_DWORD *)*(this + 5) + 12 * *(this + 6) + 4);
          v14 = *(this + 6);
          if ( v14 < *(_DWORD *)(*(this + 5) + 4) )
          {
            *(this + 6) = v14 + 1;
            return this;
          }
        }
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10160200
// Name: public: struct GFxTextParagraph::StyledTextRun const __near & GFxTextParagraph::FormatRunIterator::operator*(void)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GFxTextParagraph::FormatRunIterator::operator*(int *this)
{
  int v2; // eax
  _DWORD *v3; // ecx
  int *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // edx
  IShaderDevice *v8; // edi
  int v9; // edx
  IShaderAPI *v10; // ecx
  _DWORD *v12; // edx
  int v13; // eax
  int v14; // ecx
  IShaderAPI *v15; // ecx

  v2 = *(this + 6);
  if ( v2 < 0 || (v3 = (_DWORD *)*(this + 5), (unsigned int)v2 >= v3[1]) )
  {
    v12 = (_DWORD *)*(this + 7);
    v13 = *(this + 8);
    v14 = v12[1] - v13;
    v7 = *v12 + 2 * v13;
    *(this + 1) = v13;
    *(this + 2) = v14;
    goto LABEL_11;
  }
  v4 = (int *)(*v3 + 12 * v2);
  v5 = *(this + 8);
  v6 = *v4;
  if ( v5 < *v4 )
  {
    v7 = *(_DWORD *)*(this + 7) + 2 * v5;
    *(this + 1) = v5;
    *(this + 2) = v6 - v5;
LABEL_11:
    *this = v7;
    v15 = (IShaderAPI *)*(this + 3);
    if ( v15 != nullptr )
      GRefCountImpl::Release(this: v15);
    *(this + 3) = 0;
    return this;
  }
  v8 = (IShaderDevice *)v4[2];
  v9 = v4[1];
  *this = *(_DWORD *)*(this + 7) + 2 * v6;
  *(this + 1) = v6;
  *(this + 2) = v9;
  if ( v8 != nullptr )
    GRefCountImpl::AddRef(this: v8);
  v10 = (IShaderAPI *)*(this + 3);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  *(this + 3) = (int)v8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101602A0
// Name: public: void GFxTextParagraph::FormatRunIterator::operator++(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::FormatRunIterator::operator++(GRefCountBase<GFxASUserData,2> *this)
{
  int v1; // eax
  _DWORD *v2; // edx
  unsigned int *v3; // eax
  unsigned int v4; // edx
  int v5; // eax

  v1 = *((_DWORD *)this + 6);
  if ( v1 < 0 || (v2 = *((_DWORD **)this + 5), (unsigned int)v1 >= v2[1]) )
  {
    *((_DWORD *)this + 8) = *(_DWORD *)(*((_DWORD *)this + 7) + 4);
  }
  else
  {
    v3 = (unsigned int *)(*v2 + 12 * v1);
    v4 = *((_DWORD *)this + 8);
    if ( v4 >= *v3 )
    {
      *((_DWORD *)this + 8) = v4 + v3[1];
      v5 = *((_DWORD *)this + 6);
      if ( v5 < *(_DWORD *)(*((_DWORD *)this + 5) + 4) )
        *((_DWORD *)this + 6) = v5 + 1;
    }
    else
    {
      *((_DWORD *)this + 8) = *v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101602F0
// Name: public: void GFxTextParagraph::FormatRunIterator::SetTextPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
GRefCountBase<GFxASUserData,2> *__thiscall GFxTextParagraph::FormatRunIterator::SetTextPos(
        GRefCountBase<GFxASUserData,2> *this,
        const GRefCountBase<GFxASUserData,2> *newTextPos)
{
  GRefCountBase<GFxASUserData,2> *result; // eax
  int v4; // eax
  int *v5; // ecx
  int v6; // edx
  int v7; // eax
  GRefCountBase<GFxASUserData,2>_vtbl *v8; // ecx

  result = *((GRefCountBase<GFxASUserData,2> **)this + 7);
  if ( *((_DWORD *)this + 8) < result->RefCount )
  {
    do
    {
      result = (GRefCountBase<GFxASUserData,2> *)GFxTextParagraph::FormatRunIterator::operator*((int *)this);
      if ( result->RefCount >= (int)newTextPos )
        break;
      v4 = *((_DWORD *)this + 6);
      if ( v4 < 0 || (v5 = *((int **)this + 5), v4 >= (unsigned int)v5[1]) )
      {
        result = *(GRefCountBase<GFxASUserData,2> **)(*((_DWORD *)this + 7) + 4);
        *((_DWORD *)this + 8) = result;
      }
      else
      {
        v6 = 3 * v4;
        v7 = *v5;
        v8 = *((GRefCountBase<GFxASUserData,2>_vtbl **)this + 8);
        result = (GRefCountBase<GFxASUserData,2> *)(v7 + 4 * v6);
        if ( v8 >= result->__vftable )
        {
          *((_DWORD *)this + 8) = (char *)v8 + result->RefCount;
          result = *((GRefCountBase<GFxASUserData,2> **)this + 6);
          if ( (int)result < *(_DWORD *)(*((_DWORD *)this + 5) + 4) )
          {
            result = (GRefCountBase<GFxASUserData,2> *)((char *)result + 1);
            *((_DWORD *)this + 6) = result;
          }
        }
        else
        {
          *((_DWORD *)this + 8) = result->__vftable;
        }
      }
    }
    while ( *((_DWORD *)this + 8) < *(_DWORD *)(*((_DWORD *)this + 7) + 4) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160370
// Name: public: GFxTextParagraph::CharactersIterator::CharactersIterator(class GFxTextParagraph const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall GFxTextParagraph::CharactersIterator::CharactersIterator(
        IGameEvent *this,
        IGameEvent *pparagraph,
        signed int index)
{
  int v4; // eax
  IGameEvent_vtbl *v5; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  signed int *v8; // eax
  int v9; // eax

  this->__vftable = nullptr;
  *((_DWORD *)this + 1) = 0;
  *((_WORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = pparagraph + 4;
  GRangeDataArray<void *,GArrayLH<GRangeData<void *>,2,GArrayDefaultPolicy>>::FindNearestRangeIndex(
    this: (GFxZlibSupportBase *)&pparagraph[4],
    index);
  *((_DWORD *)this + 4) = pparagraph + 4;
  *((_DWORD *)this + 5) = 0;
  if ( v4 >= 0 )
  {
    v5 = pparagraph[5].__vftable;
    if ( v4 < (unsigned int)v5 )
      *((_DWORD *)this + 5) = v4;
    else
      *((_DWORD *)this + 5) = (char *)v5 - 1;
  }
  else
  {
    *((_DWORD *)this + 5) = 0;
  }
  *((_DWORD *)this + 6) = pparagraph;
  *((_DWORD *)this + 7) = index;
  v6 = *((_DWORD *)this + 5);
  if ( v6 >= 0 )
  {
    v7 = *((_DWORD **)this + 4);
    if ( (unsigned int)v6 < v7[1] )
    {
      v8 = (signed int *)(*v7 + 12 * v6);
      if ( (index < *v8 || index > v8[1] + *v8 - 1) && index > *v8 )
      {
        v9 = *((_DWORD *)this + 5);
        if ( v9 < *(_DWORD *)(*((_DWORD *)this + 4) + 4) )
          *((_DWORD *)this + 5) = v9 + 1;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10160410
// Name: public: struct GFxTextParagraph::CharacterInfo __near & GFxTextParagraph::CharactersIterator::operator*(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextParagraph::CharactersIterator::operator*(int this)
{
  _DWORD *v2; // eax
  unsigned int v3; // ecx
  int v4; // eax
  _DWORD *v5; // edx
  unsigned int *v6; // edi
  IShaderDevice *v8; // ecx
  int v9; // edx

  v2 = *(_DWORD **)(this + 24);
  if ( v2 != nullptr && (v3 = *(_DWORD *)(this + 28)) < v2[1] )
  {
    *(_WORD *)(this + 8) = *(_WORD *)(*v2 + 2 * v3);
    *(_DWORD *)(this + 4) = v3;
    v4 = *(_DWORD *)(this + 20);
    if ( v4 >= 0 )
    {
      v5 = *(_DWORD **)(this + 16);
      if ( (unsigned int)v4 < v5[1] )
      {
        v6 = (unsigned int *)(*v5 + 12 * v4);
        if ( v3 >= *v6 )
        {
          v8 = (IShaderDevice *)v6[2];
          if ( v8 != nullptr )
            GRefCountImpl::AddRef(this: v8);
          if ( *(_DWORD *)this != 0 )
            GRefCountImpl::Release(this: *(IShaderAPI **)this);
          *(_DWORD *)this = v6[2];
          return this;
        }
        else
        {
          if ( *(_DWORD *)this != 0 )
            GRefCountImpl::Release(this: *(IShaderAPI **)this);
          *(_DWORD *)this = 0;
          return this;
        }
      }
    }
  }
  else
  {
    v9 = *(_DWORD *)(this + 28);
    *(_WORD *)(this + 8) = 0;
    *(_DWORD *)(this + 4) = v9;
  }
  if ( *(_DWORD *)this != 0 )
    GRefCountImpl::Release(this: *(IShaderAPI **)this);
  *(_DWORD *)this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101604B0
// Name: public: void GFxTextParagraph::CharactersIterator::operator+=(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextParagraph::CharactersIterator::operator+=(int *this, int a2)
{
  int result; // eax
  int i; // edi
  int v4; // edx
  int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // esi

  result = a2;
  if ( a2 != 0 )
  {
    for ( i = a2; i != 0; --i )
    {
      v4 = *(this + 6);
      if ( v4 != 0 && (unsigned int)(v5 = *(this + 7)) < *(_DWORD *)(v4 + 4) )
      {
        v6 = v5 + 1;
        *(this + 7) = v5 + 1;
        result = *(this + 5);
        if ( result >= 0 )
        {
          v7 = (_DWORD *)*(this + 4);
          if ( (unsigned int)result < v7[1] )
          {
            result = *v7 + 12 * result;
            if ( v6 >= *(_DWORD *)result + *(_DWORD *)(result + 4) )
            {
              result = *(this + 5);
              if ( result < *(_DWORD *)(*(this + 4) + 4) )
                *(this + 5) = ++result;
            }
          }
        }
      }
      else
      {
        result = *(_DWORD *)(v4 + 4);
        *(this + 7) = result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160520
// Name: public: void GFxStyledText::GetText(class GFxWStringBuffer __near *,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStyledText::GetText(
        CUtlMemory<GFxValue,int> *this,
        GFxWStringBuffer *a2,
        unsigned int indexInPara,
        unsigned int oldSize)
{
  unsigned int Length; // eax
  unsigned int v6; // edi
  const char *v7; // esi
  GFxValue::ValueType Type; // edi
  _DWORD *v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // edx
  _WORD *v12; // ecx
  const char *pString; // ebx
  const char *v14; // esi
  GFxValue index; // [esp+Ch] [ebp-Ch] BYREF

  Length = oldSize;
  if ( oldSize == -1 )
    Length = GFxStyledText::GetLength((GFxStyledText *)this);
  v6 = indexInPara;
  v7 = (const char *)(Length - indexInPara);
  GFxWStringBuffer::Resize(this: a2, a2: Length - indexInPara + 1);
  indexInPara = 0;
  index.Value.pString = v7;
  GFxStyledText::GetParagraphByIndex((SFTextObjectImpl *)this, &index, indexa: v6, pindexInParagraph: &indexInPara);
  Type = index.Type;
  oldSize = 0;
  while ( index.pObjectInterface != nullptr
       && Type >= VT_Undefined
       && Type < (int)index.pObjectInterface[1].pMovieRoot
       && index.Value.pString != nullptr )
  {
    v9 = *((_DWORD **)index.pObjectInterface->pMovieRoot + Type);
    v10 = v9[1];
    if ( v10 != 0 )
    {
      v11 = v10 - 1;
      if ( *v9 != 0 && v11 < v10 )
        v12 = (_WORD *)(*v9 + 2 * v11);
      else
        v12 = nullptr;
      if ( *v12 == 0 )
        --v10;
    }
    pString = index.Value.pString;
    v14 = (const char *)(v10 - indexInPara);
    if ( v14 > index.Value.pString )
      v14 = index.Value.pString;
    memcpy(
      dst: (unsigned __int8 *)&a2->pText[oldSize],
      src: (unsigned __int8 *)(*v9 + 2 * indexInPara),
      count: 2 * (_DWORD)v14);
    oldSize += (unsigned int)v14;
    indexInPara = 0;
    index.Value.pString = (const char *)(pString - v14);
    if ( Type < (int)index.pObjectInterface[1].pMovieRoot )
      ++Type;
  }
  a2->pText[oldSize] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101606F0
// Name: public: void GMsgFormat::FormatD1<bool>(bool const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GMsgFormat::FormatD1<bool>(GMsgFormat *this, bool *a2)
{
  char result; // al
  GMemoryHeap **v4; // esi
  CMemberFuncProxy0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  CMemberFuncProxy0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *v8; // eax

  result = GMsgFormat::NextFormatter(this);
  if ( result != 0 )
  {
    v4 = (GMemoryHeap **)(this + 61);
    do
    {
      if ( (unsigned int)*(this + 191) < 0x18 )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (CMemberFuncProxy0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *)v7->Alloc(this: v7, a2: 24u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = (CMemberFuncProxy0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *)*(this + 190);
        *(this + 190) = (GMsgFormat)((((unsigned int)&v5->m_pObject + 7) & 0xFFFFFFFC) + 4);
        v6 = (((unsigned int)&v5->m_pObject + 7) & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *(this + 191) = nullptr;
        else
          *(this + 191) = (GMsgFormat)(512 - v6);
      }
      if ( v5 != nullptr )
        v8 = GBoolFormatter::GBoolFormatter(this: v5, f: (unsigned int)this, v: *a2);
      else
        v8 = nullptr;
      GMsgFormat::Bind(this, a2: (struct GFormatter *)v8, a3: true);
      result = GMsgFormat::NextFormatter(this);
    }
    while ( result != 0 );
  }
  ++*((_BYTE *)this + 5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160870
// Name: public: int GFxSGMLParser<wchar_t>::GetNext(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSGMLParser<wchar_t>::GetNext(int this)
{
  int result; // eax
  int v3; // eax
  bool v4; // zf
  _WORD *v5; // eax
  _WORD *v6; // eax
  int v7; // edi
  int v8; // eax
  _WORD *v9; // eax
  int v10; // eax
  int v11; // eax
  _WORD *v12; // eax
  _WORD *v13; // eax

  result = *(_DWORD *)(this + 4);
  if ( result != 1 )
  {
    if ( (result & 0x8000) == 0 )
    {
      switch ( result )
      {
        case 2:
          GFxSGMLParser<wchar_t>::SkipName(this);
          goto LABEL_5;
        case 3:
          while ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) )
          {
            if ( *(_DWORD *)(this + 20) == 60 )
              break;
            v4 = *(_BYTE *)(this + 24) == 0;
            v5 = *(_WORD **)(this + 12);
            *(_DWORD *)(this + 8) = v5;
            if ( v4 || *v5 != 38 )
            {
              if ( (unsigned int)v5 < *(_DWORD *)(this + 16) )
              {
                *(_DWORD *)(this + 20) = (unsigned __int16)*v5;
                *(_DWORD *)(this + 12) = v5 + 1;
              }
            }
            else
            {
              GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
            }
          }
          *(_DWORD *)(this + 4) = 32771;
          goto LABEL_30;
        case 4:
          if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
            goto LABEL_27;
          break;
        case 7:
        case 8:
LABEL_5:
          while ( 1 )
          {
            v3 = *(_DWORD *)(this + 4);
            if ( v3 != 7 && v3 != 8 )
              break;
            GFxSGMLParser<wchar_t>::SkipAttribute(this);
          }
          goto LABEL_8;
        case 9:
LABEL_8:
          if ( *(_DWORD *)(this + 20) == 62 )
          {
            GFxSGMLCharIter<wchar_t>::operator++(this: (GFxValue::ObjectInterface::ObjVisitor *)(this + 8));
            *(_DWORD *)(this + 4) = 32770;
          }
          goto LABEL_30;
        default:
          goto LABEL_30;
      }
      do
      {
        if ( *(_DWORD *)(this + 20) == 62 )
          goto LABEL_28;
        v4 = *(_BYTE *)(this + 24) == 0;
        v6 = *(_WORD **)(this + 12);
        *(_DWORD *)(this + 8) = v6;
        if ( v4 || *v6 != 38 )
        {
          if ( (unsigned int)v6 < *(_DWORD *)(this + 16) )
          {
            *(_DWORD *)(this + 20) = (unsigned __int16)*v6;
            *(_DWORD *)(this + 12) = v6 + 1;
          }
        }
        else
        {
          GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        }
      }
      while ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) );
LABEL_27:
      if ( *(_DWORD *)(this + 20) == 62 )
      {
LABEL_28:
        GFxSGMLCharIter<wchar_t>::operator++(this: (GFxValue::ObjectInterface::ObjVisitor *)(this + 8));
        *(_DWORD *)(this + 4) = 32772;
      }
      else
      {
        *(_DWORD *)(this + 4) = 1;
      }
    }
LABEL_30:
    result = 1;
    if ( *(_DWORD *)(this + 4) == 1 )
      return result;
    v7 = 0;
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
    {
LABEL_65:
      *(_DWORD *)(this + 4) = 0x8000;
      return *(_DWORD *)(this + 4);
    }
    while ( 1 )
    {
      if ( v7 != 0 )
      {
LABEL_66:
        *(_DWORD *)(this + 4) = v7;
        return v7;
      }
      v8 = *(_DWORD *)(this + 20);
      if ( v8 == 0 )
        goto LABEL_62;
      if ( v8 != 47 )
      {
        if ( v8 == 60 )
        {
          v4 = *(_BYTE *)(this + 24) == 0;
          v9 = *(_WORD **)(this + 12);
          *(_DWORD *)(this + 8) = v9;
          if ( v4 || *v9 != 38 )
          {
            if ( (unsigned int)v9 < *(_DWORD *)(this + 16) )
            {
              *(_DWORD *)(this + 20) = (unsigned __int16)*v9;
              *(_DWORD *)(this + 12) = v9 + 1;
            }
          }
          else
          {
            GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
          }
          v10 = *(_DWORD *)(this + 20);
          if ( v10 == 33 )
          {
            GFxSGMLParser<wchar_t>::SkipComment(this);
          }
          else if ( v10 == 47 )
          {
            GFxSGMLCharIter<wchar_t>::operator++(this: (GFxValue::ObjectInterface::ObjVisitor *)(this + 8));
            v7 = 4;
          }
          else
          {
            v7 = 2;
          }
        }
        else
        {
          v7 = 3;
        }
        goto LABEL_63;
      }
      v11 = *(_DWORD *)(this + 4);
      if ( v11 == 9 || v11 == 6 )
        break;
      v7 = 3;
LABEL_63:
      if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
      {
        if ( v7 == 0 )
          goto LABEL_65;
        goto LABEL_66;
      }
    }
    v4 = *(_BYTE *)(this + 24) == 0;
    v12 = *(_WORD **)(this + 12);
    *(_DWORD *)(this + 8) = v12;
    if ( v4 || *v12 != 38 )
    {
      if ( (unsigned int)v12 < *(_DWORD *)(this + 16) )
      {
        *(_DWORD *)(this + 20) = (unsigned __int16)*v12;
        *(_DWORD *)(this + 12) = v12 + 1;
      }
    }
    else
    {
      GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
    }
    if ( *(_DWORD *)(this + 20) == 62 )
    {
      v4 = *(_BYTE *)(this + 24) == 0;
      v13 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v13;
      if ( v4 || *v13 != 38 )
      {
        if ( (unsigned int)v13 < *(_DWORD *)(this + 16) )
        {
          *(_DWORD *)(this + 20) = (unsigned __int16)*v13;
          *(_DWORD *)(this + 12) = v13 + 1;
        }
        v7 = 32773;
      }
      else
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        v7 = 32773;
      }
      goto LABEL_63;
    }
LABEL_62:
    v7 = 1;
    goto LABEL_63;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160B00
// Name: public: bool GFxSGMLParser<wchar_t>::GetNextAttribute(wchar_t const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSGMLParser<wchar_t>::GetNextAttribute(int this, unsigned __int8 **a2, unsigned int *a3)
{
  int v4; // eax
  char v6; // bl
  bool v7; // zf
  _WORD *v8; // eax

  v4 = *(_DWORD *)(this + 4);
  if ( v4 == 1 )
    return 0;
  if ( v4 == 8 )
    GFxSGMLParser<wchar_t>::SkipAttribute(this);
  v6 = 0;
  while ( *(_DWORD *)(this + 4) == 7 )
  {
    if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
      break;
    GFxSGMLParser<wchar_t>::ParseName((char *)this, a2, a3);
    GFxSGMLParser<wchar_t>::SkipSpaces(this);
    if ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) )
    {
      if ( *(_DWORD *)(this + 20) == 61 )
      {
        v7 = *(_BYTE *)(this + 24) == 0;
        v8 = *(_WORD **)(this + 12);
        *(_DWORD *)(this + 8) = v8;
        if ( v7 || *v8 != 38 )
        {
          if ( (unsigned int)v8 < *(_DWORD *)(this + 16) )
          {
            *(_DWORD *)(this + 20) = (unsigned __int16)*v8;
            *(_DWORD *)(this + 12) = v8 + 1;
          }
        }
        else
        {
          GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        }
        GFxSGMLParser<wchar_t>::SkipSpaces(this);
        *(_DWORD *)(this + 4) = 8;
        v6 = 1;
      }
      else
      {
        GFxSGMLParser<wchar_t>::SkipAttribute(this);
      }
    }
  }
  if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
    *(_DWORD *)(this + 4) = 1;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10160BC0
// Name: public: bool GFxSGMLParser<wchar_t>::GetNextAttributeValue(wchar_t const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSGMLParser<wchar_t>::GetNextAttributeValue(int this, unsigned __int8 **a2, int *a3)
{
  bool v4; // zf
  int v5; // eax
  _WORD *v6; // eax
  int *v7; // ebx
  char v8; // al
  _WORD *i; // eax
  unsigned int v10; // eax
  void *v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  void *v15; // eax
  _WORD *v16; // eax
  _WORD *v17; // eax
  int v18; // eax
  char result; // al
  int v20; // [esp+4h] [ebp-10h]
  int v21; // [esp+8h] [ebp-Ch] BYREF
  int v22; // [esp+Ch] [ebp-8h]
  char v23; // [esp+12h] [ebp-2h]
  char v24; // [esp+13h] [ebp-1h]

  v4 = *(_DWORD *)(this + 4) == 8;
  v23 = 0;
  if ( v4 )
  {
    v5 = *(_DWORD *)(this + 20);
    v22 = v5;
    if ( v5 == 34 || v5 == 39 )
    {
      v4 = *(_BYTE *)(this + 24) == 0;
      v6 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v6;
      if ( v4 || *v6 != 38 )
      {
        if ( (unsigned int)v6 < *(_DWORD *)(this + 16) )
        {
          *(_DWORD *)(this + 20) = (unsigned __int16)*v6;
          *(_DWORD *)(this + 12) = v6 + 1;
        }
      }
      else
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
      }
      v7 = a3;
      *a2 = *(unsigned __int8 **)(this + 8);
      *a3 = 0;
      v8 = *(_BYTE *)(this + 24);
      v24 = 0;
      *(_BYTE *)(this + 24) = 1;
      if ( v8 == 0 && **(_WORD **)(this + 8) == 38 )
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
      for ( i = *(_WORD **)(this + 8); (unsigned int)i < *(_DWORD *)(this + 16); i = *(_WORD **)(this + 8) )
      {
        if ( *(_DWORD *)(this + 20) == v22 )
          break;
        if ( *(_BYTE *)(this + 24) != 0 && *i == 38 )
        {
          if ( v24 == 0 )
          {
            *(_DWORD *)(this + 36) = 0;
            GFxSGMLParser<wchar_t>::AppendToBuf((unsigned int *)this, src: *a2, a3: *v7);
            v24 = 1;
          }
          v20 = *(_DWORD *)(this + 20);
          v10 = *(_DWORD *)(this + 32);
          if ( *(_DWORD *)(this + 36) + 6 > v10 )
          {
            v11 = *(void **)(this + 28);
            v12 = v10 + 6;
            *(_DWORD *)(this + 32) = v12;
            v13 = 2 * v12;
            if ( v11 != nullptr )
            {
              v15 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v11, a3: v13);
            }
            else
            {
              v14 = *(_DWORD *)this;
              v21 = 324;
              v15 = (void *)(*(int (__thiscall **)(unsigned int, unsigned int, int *))(*(_DWORD *)v14 + 40))(
                              a1: v14,
                              a2: v13,
                              a3: &v21);
            }
            v7 = a3;
            *(_DWORD *)(this + 28) = v15;
          }
          *(_WORD *)(*(_DWORD *)(this + 28) + 2 * (*(_DWORD *)(this + 36))++) = v20;
        }
        else if ( v24 != 0 )
        {
          GFxSGMLParser<wchar_t>::AppendToBuf(
            (unsigned int *)this,
            src: *(unsigned __int8 **)(this + 8),
            a3: (*(_DWORD *)(this + 12) - (int)i) >> 1);
        }
        else
        {
          *v7 += (*(_DWORD *)(this + 12) - (int)i) >> 1;
        }
        v4 = *(_BYTE *)(this + 24) == 0;
        v16 = *(_WORD **)(this + 12);
        *(_DWORD *)(this + 8) = v16;
        if ( v4 || *v16 != 38 )
        {
          if ( (unsigned int)v16 < *(_DWORD *)(this + 16) )
          {
            *(_DWORD *)(this + 20) = (unsigned __int16)*v16;
            *(_DWORD *)(this + 12) = v16 + 1;
          }
        }
        else
        {
          GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        }
      }
      v4 = v24 == 0;
      *(_BYTE *)(this + 24) = 0;
      if ( !v4 )
      {
        *a2 = *(unsigned __int8 **)(this + 28);
        *v7 = *(_DWORD *)(this + 36);
      }
      if ( *(_DWORD *)(this + 8) < *(_DWORD *)(this + 16) )
      {
        v4 = *(_BYTE *)(this + 24) == 0;
        v17 = *(_WORD **)(this + 12);
        v23 = 1;
        *(_DWORD *)(this + 8) = v17;
        if ( v4 || *v17 != 38 )
        {
          if ( (unsigned int)v17 < *(_DWORD *)(this + 16) )
          {
            *(_DWORD *)(this + 20) = (unsigned __int16)*v17;
            *(_DWORD *)(this + 12) = v17 + 1;
          }
        }
        else
        {
          GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        }
        GFxSGMLParser<wchar_t>::SkipSpaces(this);
        v18 = *(_DWORD *)(this + 20);
        if ( v18 == 62 || v18 == 47 )
          *(_DWORD *)(this + 4) = 9;
        else
          *(_DWORD *)(this + 4) = 7;
      }
      else
      {
        *(_DWORD *)(this + 4) = 1;
      }
    }
    else
    {
      *(_DWORD *)(this + 4) = 1;
    }
  }
  result = v23;
  if ( *(_DWORD *)(this + 8) >= *(_DWORD *)(this + 16) )
    *(_DWORD *)(this + 4) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160DF0
// Name: public: bool GFxSGMLParser<wchar_t>::ParseStartElement(wchar_t const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSGMLParser<wchar_t>::ParseStartElement(int this, unsigned __int8 **a2, unsigned int *a3)
{
  char result; // al
  int v5; // eax
  bool v6; // zf
  _WORD *v7; // eax
  int v8; // edx

  result = 0;
  if ( *(_DWORD *)(this + 4) == 2 )
  {
    GFxSGMLParser<wchar_t>::ParseName((char *)this, a2, a3);
    v5 = *(_DWORD *)(this + 20);
    if ( v5 == 62 )
    {
      *(_DWORD *)(this + 4) = 32770;
      v6 = *(_BYTE *)(this + 24) == 0;
      v7 = *(_WORD **)(this + 12);
      *(_DWORD *)(this + 8) = v7;
      if ( !v6 && *v7 == 38 )
      {
        GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
        return 1;
      }
      if ( (unsigned int)v7 < *(_DWORD *)(this + 16) )
      {
        v8 = (unsigned __int16)*v7;
        *(_DWORD *)(this + 12) = v7 + 1;
        *(_DWORD *)(this + 20) = v8;
        return 1;
      }
    }
    else
    {
      if ( v5 == 47 )
      {
        *(_DWORD *)(this + 4) = 6;
        return 1;
      }
      *(_DWORD *)(this + 4) = 7;
      GFxSGMLParser<wchar_t>::SkipSpaces(this);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160E90
// Name: public: bool GFxSGMLParser<wchar_t>::ParseEndElement(wchar_t const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSGMLParser<wchar_t>::ParseEndElement(int this, unsigned __int8 **a2, unsigned int *a3)
{
  _WORD *v4; // eax

  if ( *(_DWORD *)(this + 4) != 4 )
    return 0;
  GFxSGMLParser<wchar_t>::ParseName((char *)this, a2, a3);
  if ( *(_DWORD *)(this + 20) != 62 )
  {
    *(_DWORD *)(this + 4) = 1;
    return 0;
  }
  *(_DWORD *)(this + 4) = 32772;
  v4 = *(_WORD **)(this + 12);
  *(_DWORD *)(this + 8) = v4;
  if ( *(_BYTE *)(this + 24) != 0 && *v4 == 38 )
  {
    GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
    return 1;
  }
  else
  {
    if ( (unsigned int)v4 < *(_DWORD *)(this + 16) )
    {
      *(_DWORD *)(this + 20) = (unsigned __int16)*v4;
      *(_DWORD *)(this + 12) = v4 + 1;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160F10
// Name: public: bool GFxSGMLParser<wchar_t>::ParseContent(wchar_t const __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxSGMLParser<wchar_t>::ParseContent(int this, unsigned __int8 **a2, int *a3)
{
  char v4; // al
  _WORD *v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  unsigned int v9; // eax
  void *v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  void *v14; // eax
  unsigned int v15; // eax
  void *v16; // edx
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ecx
  void *v20; // eax
  bool v21; // zf
  _WORD *v22; // eax
  _WORD *v23; // eax
  int v25; // [esp+4h] [ebp-Ch]
  int v26; // [esp+8h] [ebp-8h] BYREF
  char v27; // [esp+Fh] [ebp-1h]

  if ( *(_DWORD *)(this + 4) == 3 )
  {
    *a2 = *(unsigned __int8 **)(this + 8);
    *a3 = 0;
    v4 = *(_BYTE *)(this + 24);
    v27 = 0;
    *(_BYTE *)(this + 24) = 1;
    if ( v4 == 0 && **(_WORD **)(this + 8) == 38 )
      GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
    v5 = *(_WORD **)(this + 8);
    if ( (unsigned int)v5 < *(_DWORD *)(this + 16) )
    {
      do
      {
        v6 = *(_DWORD *)(this + 20);
        if ( v6 == 60 && (*(_BYTE *)(this + 24) == 0 || *v5 != 38) )
          break;
        if ( (v7 = BYTE1(v6),
              v8 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v7),
              *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v7) != 0)
          && (v8 == 1
           || (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v8
                                                                                        + ((unsigned __int8)v6 >> 4))
             & (1 << (v6 & 0xF))) != 0)
          && *(_BYTE *)(this + 40) != 0 )
        {
          if ( v27 == 0 )
          {
            *(_DWORD *)(this + 36) = 0;
            GFxSGMLParser<wchar_t>::AppendToBuf((unsigned int *)this, src: *a2, a3: *a3);
            v27 = 1;
          }
          v9 = *(_DWORD *)(this + 32);
          if ( *(_DWORD *)(this + 36) + 6 > v9 )
          {
            v10 = *(void **)(this + 28);
            v11 = v9 + 6;
            *(_DWORD *)(this + 32) = v11;
            v12 = 2 * v11;
            if ( v10 != nullptr )
            {
              v14 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v10, a3: v12);
            }
            else
            {
              v13 = *(_DWORD *)this;
              v26 = 324;
              v14 = (void *)(*(int (__thiscall **)(unsigned int, unsigned int, int *))(*(_DWORD *)v13 + 40))(
                              a1: v13,
                              a2: v12,
                              a3: &v26);
            }
            *(_DWORD *)(this + 28) = v14;
          }
          *(_WORD *)(*(_DWORD *)(this + 28) + 2 * (*(_DWORD *)(this + 36))++) = 32;
          GFxSGMLParser<wchar_t>::SkipSpaces(this);
        }
        else
        {
          if ( *(_BYTE *)(this + 24) != 0 && **(_WORD **)(this + 8) == 38 )
          {
            if ( v27 == 0 )
            {
              *(_DWORD *)(this + 36) = 0;
              GFxSGMLParser<wchar_t>::AppendToBuf((unsigned int *)this, src: *a2, a3: *a3);
              v27 = 1;
            }
            v15 = *(_DWORD *)(this + 32);
            v25 = *(_DWORD *)(this + 20);
            if ( *(_DWORD *)(this + 36) + 6 > v15 )
            {
              v16 = *(void **)(this + 28);
              v17 = v15 + 6;
              *(_DWORD *)(this + 32) = v17;
              v18 = 2 * v17;
              if ( v16 != nullptr )
              {
                v20 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v16, a3: v18);
              }
              else
              {
                v19 = *(_DWORD *)this;
                v26 = 324;
                v20 = (void *)(*(int (__thiscall **)(unsigned int, unsigned int, int *))(*(_DWORD *)v19 + 40))(
                                a1: v19,
                                a2: v18,
                                a3: &v26);
              }
              *(_DWORD *)(this + 28) = v20;
            }
            *(_WORD *)(*(_DWORD *)(this + 28) + 2 * (*(_DWORD *)(this + 36))++) = v25;
          }
          else if ( v27 != 0 )
          {
            GFxSGMLParser<wchar_t>::AppendToBuf(
              (unsigned int *)this,
              src: *(unsigned __int8 **)(this + 8),
              a3: (*(_DWORD *)(this + 12) - *(_DWORD *)(this + 8)) >> 1);
          }
          else
          {
            *a3 += (*(_DWORD *)(this + 12) - *(_DWORD *)(this + 8)) >> 1;
          }
          v21 = *(_BYTE *)(this + 24) == 0;
          v22 = *(_WORD **)(this + 12);
          *(_DWORD *)(this + 8) = v22;
          if ( v21 || *v22 != 38 )
          {
            if ( (unsigned int)v22 < *(_DWORD *)(this + 16) )
            {
              *(_DWORD *)(this + 20) = (unsigned __int16)*v22;
              *(_DWORD *)(this + 12) = v22 + 1;
            }
          }
          else
          {
            GFxSGMLCharIter<wchar_t>::DecodeEscapedChar(this: (unsigned __int16 **)(this + 8));
          }
        }
        v5 = *(_WORD **)(this + 8);
      }
      while ( (unsigned int)v5 < *(_DWORD *)(this + 16) );
      if ( v27 != 0 )
      {
        *a2 = *(unsigned __int8 **)(this + 28);
        *a3 = *(_DWORD *)(this + 36);
      }
    }
    v23 = *(_WORD **)(this + 8);
    if ( (unsigned int)v23 < *(_DWORD *)(this + 16)
      && (*(_DWORD *)(this + 20) != 60 || *(_BYTE *)(this + 24) != 0 && *v23 == 38) )
    {
      *(_DWORD *)(this + 4) = 1;
    }
    else
    {
      *(_DWORD *)(this + 4) |= 0x8000u;
    }
    *(_BYTE *)(this + 24) = 0;
  }
  return *(_DWORD *)(this + 4) != 1;
}

//------------------------------------------------------------------------------
// Address: 0x10161230
// Name: public: GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(class GMemoryHeap __near *,wchar_t const __near *,unsigned int,struct GFxSGMLElementDesc const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(
        GStringDH *this,
        struct GMemoryHeap *a2,
        unsigned int a3,
        GMemoryHeap *a4,
        int a5,
        int a6)
{
  this->HeapTypeBits = a3;
  this->pHeap = a4;
  *((_DWORD *)this + 2) = a5;
  *((_DWORD *)this + 3) = a6;
  *((_DWORD *)this + 4) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 5) = 1;
  *((_DWORD *)this + 4) = &GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: this + 3, a2);
  GStringDH::GStringDH(this: this + 4, a2);
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_BYTE *)this + 56) = 0;
  *((_DWORD *)this + 12) = -16777216;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 29) = 0;
  *((_DWORD *)this + 15) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 16) = 1;
  *((_DWORD *)this + 15) = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101612C0
// Name: public: void GArrayDataDH<struct GFxStyledText::HTMLImageTagInfo,struct GAllocatorDH<struct GFxStyledText::HTMLImageTagInfo,2>,struct GArrayDefaultPolicy>::PushBack(struct GFxStyledText::HTMLImageTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxStyledText::HTMLImageTagInfo *__thiscall GArrayDataDH<GFxStyledText::HTMLImageTagInfo,GAllocatorDH<GFxStyledText::HTMLImageTagInfo,2>,GArrayDefaultPolicy>::PushBack(int this, const struct GString *a2)
{
  unsigned int v3; // eax
  int v4; // ebx
  unsigned int v5; // esi
  GFxStyledText::HTMLImageTagInfo *result; // eax
  int v7; // esi

  v3 = *(_DWORD *)(this + 4);
  v4 = *(_DWORD *)(this + 12);
  v5 = v3 + 1;
  if ( v3 + 1 >= v3 )
  {
    if ( v5 >= *(_DWORD *)(this + 8) )
      GArrayDataBase<GFxStyledText::HTMLImageTagInfo,GAllocatorDH<GFxStyledText::HTMLImageTagInfo,2>,GArrayDefaultPolicy>::Reserve(
        (void **)this,
        a2: v4,
        a3: v5 + (v5 >> 2));
  }
  else
  {
    GConstructorMov<GFxStyledText::HTMLImageTagInfo>::DestructArray(a1: *(_DWORD *)this + 44 * v5, a2: -1);
    if ( v5 < *(_DWORD *)(this + 8) >> 1 )
      GArrayDataBase<GFxStyledText::HTMLImageTagInfo,GAllocatorDH<GFxStyledText::HTMLImageTagInfo,2>,GArrayDefaultPolicy>::Reserve(
        (void **)this,
        a2: v4,
        a3: v5);
  }
  result = *(GFxStyledText::HTMLImageTagInfo **)this;
  *(_DWORD *)(this + 4) = v5;
  v7 = 44 * v5;
  if ( (GFxStyledText::HTMLImageTagInfo *)((char *)result + v7) != (GFxStyledText::HTMLImageTagInfo *)44 )
    return GFxStyledText::HTMLImageTagInfo::HTMLImageTagInfo(
             this: (GFxStyledText::HTMLImageTagInfo *)((char *)result + v7 - 44),
             a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10161330
// Name: public: GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(struct GFxSGMLStackElemDesc<wchar_t> const __near &)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(GStringDH *this, int a2)
{
  int v3; // eax
  _DWORD *v4; // eax

  this->HeapTypeBits = *(_DWORD *)a2;
  this->pHeap = *(GMemoryHeap **)(a2 + 4);
  *((_DWORD *)this + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)this + 3) = *(_DWORD *)(a2 + 12);
  *((_DWORD *)this + 4) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 5) = 1;
  *((_DWORD *)this + 4) = &GFxTextFormat::`vftable';
  GStringDH::CopyConstructHelper(
    this: this + 3,
    a2: (const struct GString *)(a2 + 24),
    pheap: *(CUtlBuffer **)(a2 + 28));
  GStringDH::CopyConstructHelper(
    this: this + 4,
    a2: (const struct GString *)(a2 + 32),
    pheap: *(CUtlBuffer **)(a2 + 28));
  v3 = *(_DWORD *)(a2 + 40);
  if ( v3 != 0 )
    ++*(_DWORD *)(v3 + 4);
  *((_DWORD *)this + 10) = *(_DWORD *)(a2 + 40);
  v4 = *(_DWORD **)(a2 + 44);
  if ( v4 != nullptr )
    ++*v4;
  *((_DWORD *)this + 11) = *(_DWORD *)(a2 + 44);
  *((_DWORD *)this + 12) = *(_DWORD *)(a2 + 48);
  *((_WORD *)this + 26) = *(_WORD *)(a2 + 52);
  *((_WORD *)this + 27) = *(_WORD *)(a2 + 54);
  *((_BYTE *)this + 56) = *(_BYTE *)(a2 + 56);
  *((_WORD *)this + 29) = *(_WORD *)(a2 + 58);
  GFxTextParagraphFormat::GFxTextParagraphFormat(
    this: (GFxTextParagraphFormat *)((char *)this + 60),
    a2: (const struct GFxTextParagraphFormat *)(a2 + 60));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101613F0
// Name: public: GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(void)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(GStringDH *this)
{
  struct GMemoryHeap *v2; // edi

  this->HeapTypeBits = 0;
  this->pHeap = nullptr;
  *((_DWORD *)this + 2) = 0;
  v2 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  *((_DWORD *)this + 4) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 5) = 1;
  *((_DWORD *)this + 4) = &GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: this + 3, a2: v2);
  GStringDH::GStringDH(this: this + 4, a2: v2);
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_BYTE *)this + 56) = 0;
  *((_DWORD *)this + 12) = -16777216;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 29) = 0;
  *((_DWORD *)this + 15) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = 1;
  *((_DWORD *)this + 15) = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10161480
// Name: public: class GFxTextFormat GFxTextParagraph::GetTextFormat(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextParagraph::GetTextFormat(int this, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // eax
  int v6; // ebx
  struct GMemoryHeap *v7; // esi
  unsigned int v8; // ecx
  int *v9; // esi
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // edx
  __int16 v16; // cx
  __int16 v17; // ax
  CUtlBuffer *pHeap; // [esp-8h] [ebp-90h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v20; // [esp+8h] [ebp-80h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v21; // [esp+34h] [ebp-54h] BYREF
  GStringDH v22; // [esp+3Ch] [ebp-4Ch] BYREF
  GStringDH v23; // [esp+44h] [ebp-44h] BYREF
  int v24; // [esp+4Ch] [ebp-3Ch]
  _DWORD *v25; // [esp+50h] [ebp-38h]
  int v26; // [esp+54h] [ebp-34h]
  int v27; // [esp+58h] [ebp-30h]
  char v28; // [esp+5Ch] [ebp-2Ch]
  __int16 v29; // [esp+5Eh] [ebp-2Ah]
  int v30[3]; // [esp+60h] [ebp-28h] BYREF
  IShaderAPI *v31; // [esp+6Ch] [ebp-1Ch]
  _DWORD *v32; // [esp+74h] [ebp-14h]
  int v33; // [esp+78h] [ebp-10h]
  int v34; // [esp+7Ch] [ebp-Ch]
  unsigned int v35; // [esp+80h] [ebp-8h]
  int v36; // [esp+84h] [ebp-4h]

  GFxTextParagraph::FormatRunIterator::FormatRunIterator(
    this: v30,
    a2: (GFxZlibSupportBase *)(this + 16),
    a3: this,
    a4: a3);
  v5 = a4;
  if ( a4 < a3 )
    v5 = a3;
  if ( v5 == -1 )
    v6 = 0x7FFFFFFF;
  else
    v6 = v5 - a3;
  v7 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  v21.m_pObject = (IMaterialInternal *)1;
  v21.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: &v22, a2: v7);
  GStringDH::GStringDH(this: &v23, a2: v7);
  v24 = 0;
  v25 = nullptr;
  v26 = -16777216;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v36 = 0;
  if ( v6 > 0 )
  {
    v8 = v35;
    do
    {
      if ( v8 >= *(_DWORD *)(v34 + 4) )
        break;
      v9 = GFxTextParagraph::FormatRunIterator::operator*(this: v30);
      v10 = v9[3];
      if ( v10 != 0 )
      {
        v11 = v36++;
        if ( v11 != 0 )
        {
          v12 = GFxTextFormat::Intersection(this: v10, a2: (int)&v20, fmt: (int)&v21);
          GFxTextFormat::operator=(this: (int)&v21, __that: v12);
          GFxTextFormat::~GFxTextFormat(this: &v20);
        }
        else
        {
          GFxTextFormat::operator=(this: (int)&v21, __that: v10);
        }
      }
      v6 -= v9[2];
      if ( v33 < 0 || (unsigned int)v33 >= v32[1] )
      {
        v8 = *(_DWORD *)(v34 + 4);
      }
      else
      {
        if ( v35 >= *(_DWORD *)(*v32 + 12 * v33) )
        {
          v8 = *(_DWORD *)(*v32 + 12 * v33 + 4) + v35;
          v35 = v8;
          if ( v33 < v32[1] )
            ++v33;
          continue;
        }
        v8 = *(_DWORD *)(*v32 + 12 * v33);
      }
      v35 = v8;
    }
    while ( v6 > 0 );
  }
  pHeap = (CUtlBuffer *)v22.pHeap;
  *(_DWORD *)a2 = &GRefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)a2 = &GFxTextFormat::`vftable';
  GStringDH::CopyConstructHelper(this: (GStringDH *)(a2 + 8), a2: &v22, pheap: pHeap);
  GStringDH::CopyConstructHelper(this: (GStringDH *)(a2 + 16), a2: &v23, pheap: (CUtlBuffer *)v22.pHeap);
  v13 = v24;
  if ( v24 != 0 )
  {
    ++*(_DWORD *)(v24 + 4);
    v13 = v24;
  }
  *(_DWORD *)(a2 + 24) = v13;
  v14 = v25;
  if ( v25 != nullptr )
  {
    ++*v25;
    v14 = v25;
  }
  v15 = v26;
  v16 = HIWORD(v27);
  *(_DWORD *)(a2 + 28) = v14;
  *(_WORD *)(a2 + 36) = v27;
  v17 = v29;
  *(_DWORD *)(a2 + 32) = v15;
  LOBYTE(v15) = v28;
  *(_WORD *)(a2 + 38) = v16;
  *(_BYTE *)(a2 + 40) = v15;
  *(_WORD *)(a2 + 42) = v17;
  GFxTextFormat::~GFxTextFormat(this: &v21);
  if ( v31 != nullptr )
    GRefCountImpl::Release(this: v31);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10161660
// Name: private: class GFxTextFormat __near * GFxTextParagraph::GetTextFormatPtr(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const GFxFontMap::MapEntry *__thiscall GFxTextParagraph::GetTextFormatPtr(int this, const GFxFontMap::MapEntry *result)
{
  int v2; // esi
  int v3; // eax
  GRefCountBase<GFxASUserData,2> it; // [esp+4h] [ebp-24h] BYREF
  IShaderAPI *v6; // [esp+10h] [ebp-18h]
  int v7; // [esp+20h] [ebp-8h]
  unsigned int v8; // [esp+24h] [ebp-4h]

  GFxTextParagraph::FormatRunIterator::FormatRunIterator(
    this: (int *)&it,
    a2: (GFxZlibSupportBase *)(this + 16),
    a3: this,
    a4: (int)result);
  v2 = 0;
  if ( v8 < *(_DWORD *)(v7 + 4) )
  {
    v3 = GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it)[3];
    if ( v3 != 0 )
      v2 = v3;
  }
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  return (const GFxFontMap::MapEntry *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x101616B0
// Name: public: void GFxStyledText::GetTextAndParagraphFormat(class GFxTextFormat __near *,class GFxTextParagraphFormat __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::GetTextAndParagraphFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        const CMaterial *pdestTextFmt,
        int a3,
        int i,
        unsigned int indexInPara)
{
  unsigned int v6; // ebx
  struct GMemoryHeap *v7; // esi
  _DWORD *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edx
  _WORD *v11; // ecx
  unsigned int v12; // edi
  int v13; // edx
  int v14; // eax
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *v15; // ecx
  int TextFormat; // eax
  int v17; // eax
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v18; // ecx
  int v19; // edx
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v20; // eax
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v21; // [esp+Ch] [ebp-ECh] BYREF
  _BYTE v22[44]; // [esp+38h] [ebp-C0h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v23; // [esp+64h] [ebp-94h] BYREF
  IShaderAPI v24; // [esp+90h] [ebp-68h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v25; // [esp+A8h] [ebp-50h] BYREF
  GStringDH v26; // [esp+B0h] [ebp-48h] BYREF
  GStringDH v27; // [esp+B8h] [ebp-40h] BYREF
  int v28; // [esp+C0h] [ebp-38h]
  int v29; // [esp+C4h] [ebp-34h]
  int v30; // [esp+C8h] [ebp-30h]
  int v31; // [esp+CCh] [ebp-2Ch]
  char v32; // [esp+D0h] [ebp-28h]
  __int16 v33; // [esp+D2h] [ebp-26h]
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> finalParaFmt; // [esp+D4h] [ebp-24h] BYREF
  int pi; // [esp+ECh] [ebp-Ch]
  _DWORD *v36; // [esp+F0h] [ebp-8h] BYREF
  int v37; // [esp+F4h] [ebp-4h]
  int ia; // [esp+108h] [ebp+10h]

  v6 = indexInPara - i;
  GFxStyledText::GetParagraphByIndex(
    (SFTextObjectImpl *)this,
    index: (GFxValue *)&v36,
    indexa: i,
    pindexInParagraph: &indexInPara);
  v7 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  v25.m_pObject = (IMaterialInternal *)1;
  v25.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: &v26, a2: v7);
  GStringDH::GStringDH(this: &v27, a2: v7);
  v28 = 0;
  v29 = 0;
  v30 = -16777216;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  *(_QWORD *)((char *)&finalParaFmt.m_pfnProxied + 4) = 1;
  LODWORD(finalParaFmt.m_pfnProxied) = &GFxTextParagraphFormat::`vftable';
  memset((char *)&finalParaFmt.m_pfnProxied + 12, 0, 12);
  ia = 0;
  pi = 0;
  while ( v6 != 0 )
  {
    if ( v36 == nullptr || v37 < 0 || v37 >= v36[1] )
      break;
    v8 = *(_DWORD **)(*v36 + 4 * v37);
    v9 = v8[1];
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( *v8 != 0 && v10 < v9 )
        v11 = (_WORD *)(*v8 + 2 * v10);
      else
        v11 = nullptr;
      if ( *v11 == 0 )
        --v9;
    }
    v12 = v6;
    if ( v6 >= v9 )
      v12 = v9;
    if ( v12 == 0 )
      break;
    v13 = ia++;
    if ( v13 != 0 )
    {
      TextFormat = GFxTextParagraph::GetTextFormat(this: (int)v8, a2: (int)&v21, a3: indexInPara, a4: v12 + indexInPara);
      v17 = GFxTextFormat::Intersection(this: TextFormat, a2: (int)&v23, fmt: (int)&v25);
      GFxTextFormat::operator=(this: (int)&v25, __that: v17);
      GFxTextFormat::~GFxTextFormat(this: &v23);
      v15 = &v21;
    }
    else
    {
      v14 = GFxTextParagraph::GetTextFormat(this: (int)v8, a2: (int)v22, a3: indexInPara, a4: v12 + indexInPara);
      GFxTextFormat::operator=(this: (int)&v25, __that: v14);
      v15 = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v22;
    }
    GFxTextFormat::~GFxTextFormat(this: v15);
    if ( indexInPara == 0 )
    {
      v18 = (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v8[3];
      if ( v18 != nullptr )
      {
        v19 = pi++;
        if ( v19 != 0 )
        {
          GFxTextParagraphFormat::Intersection(this: v18, a2: (GFxTextParagraphFormat *)&v24, a3: (int)&finalParaFmt);
          GFxTextParagraphFormat::operator=(this: (int)&finalParaFmt, result: v20);
          v24.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
          GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v24);
          GRefCountImplCore::~GRefCountImplCore(this: &v24);
        }
        else
        {
          GFxTextParagraphFormat::operator=(this: (int)&finalParaFmt, result: v18);
        }
      }
    }
    v6 -= v12;
    if ( v37 < v36[1] )
      ++v37;
  }
  if ( pdestTextFmt != nullptr )
    GFxTextFormat::operator=(this: (int)pdestTextFmt, __that: (int)&v25);
  if ( a3 != 0 )
    GFxTextParagraphFormat::operator=(
      this: a3,
      result: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&finalParaFmt);
  LODWORD(finalParaFmt.m_pfnProxied) = &GFxTextParagraphFormat::`vftable';
  GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&finalParaFmt);
  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&finalParaFmt);
  GFxTextFormat::~GFxTextFormat(this: &v25);
}

//------------------------------------------------------------------------------
// Address: 0x101618F0
// Name: public: bool GFxStyledText::GetTextAndParagraphFormat(class GFxTextFormat const __near * __near *,class GFxTextParagraphFormat const __near * __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::GetTextAndParagraphFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        int *ppdestTextFmt,
        _DWORD *ppdestParaFmt,
        unsigned int indexInPara)
{
  int v5; // esi
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10[3]; // [esp+8h] [ebp-2Ch] BYREF
  IShaderAPI *v11; // [esp+14h] [ebp-20h]
  int v12; // [esp+24h] [ebp-10h]
  unsigned int v13; // [esp+28h] [ebp-Ch]
  _DWORD *v14; // [esp+2Ch] [ebp-8h] BYREF
  int v15; // [esp+30h] [ebp-4h]

  GFxStyledText::GetParagraphByIndex(
    (SFTextObjectImpl *)this,
    index: (GFxValue *)&v14,
    indexa: indexInPara,
    pindexInParagraph: &indexInPara);
  v5 = 0;
  if ( v14 == nullptr || v15 < 0 || v15 >= v14[1] )
    goto LABEL_10;
  v6 = *(_DWORD *)(*v14 + 4 * v15);
  GFxTextParagraph::FormatRunIterator::FormatRunIterator(
    this: v10,
    a2: (GFxZlibSupportBase *)(v6 + 16),
    a3: v6,
    a4: indexInPara);
  v7 = 0;
  if ( v13 < *(_DWORD *)(v12 + 4) )
  {
    v8 = GFxTextParagraph::FormatRunIterator::operator*(this: v10)[3];
    if ( v8 != 0 )
      v7 = v8;
  }
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  v5 = *(_DWORD *)(v6 + 12);
  v9 = v7;
  if ( v7 == 0 )
LABEL_10:
    v9 = *((_DWORD *)this + 7);
  if ( v5 == 0 )
    v5 = *((_DWORD *)this + 6);
  if ( ppdestTextFmt != nullptr )
    *ppdestTextFmt = v9;
  if ( ppdestParaFmt != nullptr )
    *ppdestParaFmt = v5;
}

//------------------------------------------------------------------------------
// Address: 0x101619A0
// Name: public: class GString GFxStyledText::GetHtml(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxStyledText::GetHtml(
        CRefCountServiceDestruct<CRefST>_vtbl *this,
        VertexShaderHandle_t__ **a2)
{
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *v3; // esi
  CRefCountServiceDestruct<CRefST>_vtbl *v4; // ecx
  int v5; // edi
  int v6; // eax
  int m_SpaceUsed; // edx
  _DWORD *m_pfnProxied; // edi
  unsigned int v9; // eax
  bool v10; // zf
  unsigned int v11; // edx
  _WORD *v12; // ecx
  int v13; // ebx
  char v14; // dl
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edi
  int *v19; // ebx
  int v20; // ecx
  int v21; // eax
  GRefCountNTSImpl *m_nUserID; // edi
  GRefCountNTSImpl *m_iRefs; // ecx
  int *p_m_nUserID; // eax
  int v25; // esi
  int v26; // eax
  struct GString *v27; // edi
  unsigned int v28; // ecx
  unsigned int v29; // ecx
  int v30; // ecx
  int v31; // eax
  IShaderAPI *v32; // edi
  int v33; // ecx
  char **FontList; // esi
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  struct GString *v40; // esi
  IShaderDevice *v41; // ecx
  unsigned int v42; // esi
  CRefCountServiceDestruct<CRefST>_vtbl *v43; // edi
  __int16 v44; // ax
  int v45; // eax
  int v46; // ebx
  unsigned int *v47; // edx
  unsigned int v48; // ecx
  VertexShaderHandle_t__ **v49; // esi
  __int128 v51; // [esp+0h] [ebp-3AA4h] BYREF
  char *v52; // [esp+10h] [ebp-3A94h]
  _DWORD v53[3]; // [esp+18h] [ebp-3A8Ch] BYREF
  _DWORD v54[3]; // [esp+24h] [ebp-3A80h] BYREF
  _DWORD v55[3]; // [esp+30h] [ebp-3A74h] BYREF
  _DWORD v56[3]; // [esp+3Ch] [ebp-3A68h] BYREF
  _DWORD v57[3]; // [esp+48h] [ebp-3A5Ch] BYREF
  _DWORD v58[3]; // [esp+54h] [ebp-3A50h] BYREF
  _DWORD v59[3]; // [esp+60h] [ebp-3A44h] BYREF
  _DWORD v60[3]; // [esp+6Ch] [ebp-3A38h] BYREF
  _DWORD v61[3]; // [esp+78h] [ebp-3A2Ch] BYREF
  _DWORD v62[3]; // [esp+84h] [ebp-3A20h] BYREF
  _DWORD v63[3]; // [esp+90h] [ebp-3A14h] BYREF
  _DWORD v64[3]; // [esp+9Ch] [ebp-3A08h] BYREF
  _DWORD v65[3]; // [esp+A8h] [ebp-39FCh] BYREF
  _DWORD v66[3]; // [esp+B4h] [ebp-39F0h] BYREF
  _DWORD v67[3]; // [esp+C0h] [ebp-39E4h] BYREF
  _DWORD v68[3]; // [esp+CCh] [ebp-39D8h] BYREF
  _DWORD v69[3]; // [esp+D8h] [ebp-39CCh] BYREF
  _DWORD v70[4]; // [esp+E4h] [ebp-39C0h] BYREF
  int v71; // [esp+F4h] [ebp-39B0h]
  CUtlSymbolTable::StringPool_t v72; // [esp+F8h] [ebp-39ACh] BYREF
  int v73; // [esp+104h] [ebp-39A0h] BYREF
  int v74; // [esp+108h] [ebp-399Ch] BYREF
  CUtlSymbolTable::StringPool_t v75; // [esp+10Ch] [ebp-3998h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> v76; // [esp+118h] [ebp-398Ch] BYREF
  VertexShaderHandle_t__ **v77; // [esp+124h] [ebp-3980h]
  CUtlSymbolTable::StringPool_t v78; // [esp+128h] [ebp-397Ch] BYREF
  int v79; // [esp+134h] [ebp-3970h]
  int v80[3]; // [esp+138h] [ebp-396Ch] BYREF
  IShaderAPI *v81; // [esp+144h] [ebp-3960h]
  _DWORD *v82; // [esp+148h] [ebp-395Ch]
  _DWORD *v83; // [esp+14Ch] [ebp-3958h]
  int v84; // [esp+150h] [ebp-3954h]
  _DWORD *v85; // [esp+154h] [ebp-3950h]
  unsigned int v86; // [esp+158h] [ebp-394Ch]
  __int64 v87; // [esp+15Ch] [ebp-3948h] BYREF
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pnum; // [esp+164h] [ebp-3940h] BYREF
  int v89; // [esp+194h] [ebp-3910h]
  int v90; // [esp+198h] [ebp-390Ch] BYREF
  char v91; // [esp+19Fh] [ebp-3905h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v92; // [esp+1A0h] [ebp-3904h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v93; // [esp+4A0h] [ebp-3604h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v94; // [esp+7A0h] [ebp-3304h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v95; // [esp+AA0h] [ebp-3004h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v96; // [esp+DA0h] [ebp-2D04h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v97; // [esp+10A0h] [ebp-2A04h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v98; // [esp+13A0h] [ebp-2704h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v99; // [esp+16A0h] [ebp-2404h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v100; // [esp+19A0h] [ebp-2104h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v101; // [esp+1CA0h] [ebp-1E04h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v102; // [esp+1FA0h] [ebp-1B04h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v103[27]; // [esp+22A0h] [ebp-1804h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v104; // [esp+25A0h] [ebp-1504h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v105; // [esp+28A0h] [ebp-1204h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v106; // [esp+2BA0h] [ebp-F04h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v107; // [esp+2EA0h] [ebp-C04h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v108; // [esp+31A0h] [ebp-904h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v109; // [esp+34A0h] [ebp-604h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v110; // [esp+37A0h] [ebp-304h] BYREF

  v3 = nullptr;
  pnum.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = this;
  v77 = a2;
  v89 = 0;
  GStringBuffer::GStringBuffer(
    this: (_DWORD *)&pnum.m_Proxy.m_pfnProxied + 2,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  v4 = this + 3;
  v5 = *((_DWORD *)this + 4);
  v6 = 0;
  v71 = 0;
  m_SpaceUsed = 0;
  v76.m_nGrowSize = v5;
  while ( v4 != nullptr && v6 >= 0 && v6 < (int)v4[1].dtr_CRefCountServiceDestruct<CRefST> )
  {
    m_pfnProxied = *((_DWORD **)v4->dtr_CRefCountServiceDestruct<CRefST> + v6);
    LODWORD(pnum.m_Proxy.m_pfnProxied) = m_pfnProxied;
    v78.m_SpaceUsed = m_SpaceUsed + 1;
    if ( m_SpaceUsed + 1 != v76.m_nGrowSize )
      goto LABEL_15;
    v9 = m_pfnProxied[1];
    v10 = v9 == 0;
    if ( v9 != 0 )
    {
      v11 = v9 - 1;
      if ( *m_pfnProxied != 0 && v11 < v9 )
        v12 = (_WORD *)(*m_pfnProxied + 2 * v11);
      else
        v12 = nullptr;
      if ( *v12 == 0 )
        --v9;
      v10 = v9 == 0;
    }
    if ( !v10 )
    {
LABEL_15:
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
        putf8str: "<TEXTFORMAT",
        utf8StrSz: -1);
      v13 = m_pfnProxied[3];
      v14 = *(_BYTE *)(v13 + 22) >> 2;
      v79 = v13;
      if ( (v14 & 1) != 0 )
      {
        v15 = *(__int16 *)(v13 + 14);
        v59[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
        *(_DWORD *)v78.m_Data = v15;
        v59[0] = 1;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v109, a2: (const struct GMsgFormat::Sink *)v59);
        GMsgFormat::Parse(
          this: &v109,
          result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" INDENT=\"{0}\"");
        GMsgFormat::FormatD1<int>(this: (int)&v109, result: (CUtlSymbolTable::StringPool_t *)v78.m_Data);
        GMsgFormat::FinishFormatD(this: &v109);
        GMsgFormat::~GMsgFormat(this: &v109);
      }
      if ( (*(_BYTE *)(v13 + 22) & 2) != 0 )
      {
        v75.m_SpaceUsed = *(unsigned __int16 *)(v13 + 12);
        v56[0] = 1;
        v56[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v108, a2: (const struct GMsgFormat::Sink *)v56);
        GMsgFormat::Parse(
          this: &v108,
          result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" BLOCKINDENT=\"{0}\"");
        GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v108, a2: (int)&v75.m_SpaceUsed);
        GMsgFormat::FinishFormatD(this: &v108);
        GMsgFormat::~GMsgFormat(this: &v108);
      }
      if ( (*(_BYTE *)(v13 + 22) & 0x10) != 0 )
      {
        v74 = *(unsigned __int16 *)(v13 + 18);
        v54[0] = 1;
        v54[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v97, a2: (const struct GMsgFormat::Sink *)v54);
        GMsgFormat::Parse(
          this: &v97,
          result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" LEFTMARGIN=\"{0}\"");
        GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v97, a2: (int)&v74);
        GMsgFormat::FinishFormatD(this: &v97);
        GMsgFormat::~GMsgFormat(this: &v97);
      }
      if ( (*(_BYTE *)(v13 + 22) & 0x20) != 0 )
      {
        v16 = *(unsigned __int16 *)(v13 + 20);
        v52 = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
        *(_DWORD *)v72.m_Data = v16;
        HIDWORD(v51) = 1;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v101, a2: (const struct GMsgFormat::Sink *)((char *)&v51 + 12));
        GMsgFormat::Parse(
          this: &v101,
          result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9C58.m_Root);
        GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v101, a2: (int)v72.m_Data);
        GMsgFormat::FinishFormatD(this: &v101);
        GMsgFormat::~GMsgFormat(this: &v101);
      }
      if ( (*(_BYTE *)(v13 + 22) & 8) != 0 )
      {
        v72.m_TotalLen = *(__int16 *)(v13 + 16);
        v53[0] = 1;
        v53[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v93, a2: (const struct GMsgFormat::Sink *)v53);
        GMsgFormat::Parse(
          this: &v93,
          result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9C58);
        GMsgFormat::FormatD1<int>(this: (int)&v93, result: &v72);
        GMsgFormat::FinishFormatD(this: &v93);
        GMsgFormat::~GMsgFormat(this: &v93);
      }
      if ( (*(_BYTE *)(v13 + 22) & 0x40) != 0 )
      {
        GStringBuffer::AppendString(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
          putf8str: (char *)&stru_102A9C3C.m_Root,
          utf8StrSz: -1);
        GFxTextParagraphFormat::GetTabStops(
          this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v13,
          &pnum);
        if ( pnum.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable != nullptr )
        {
          v18 = v17;
          do
          {
            BYTE7(pnum.m_Proxy.m_pfnProxied) = v3 != nullptr;
            v67[0] = 1;
            v67[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v110, a2: (const struct GMsgFormat::Sink *)v67);
            GMsgFormat::Parse(
              this: &v110,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9C3C);
            GMsgFormat::FormatD1<bool>(this: (GMsgFormat *)&v110, a2: (bool *)&pnum.m_Proxy.m_pfnProxied + 7);
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v110, a2: v18);
            GMsgFormat::FinishFormatD(this: &v110);
            GMsgFormat::~GMsgFormat(this: &v110);
            v3 = (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)((char *)v3 + 1);
            v18 += 4;
          }
          while ( v3 < pnum.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable );
        }
        GStringBuffer::AppendString(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
          putf8str: "\"",
          utf8StrSz: -1);
        m_pfnProxied = (_DWORD *)pnum.m_Proxy.m_pfnProxied;
      }
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
        putf8str: "><",
        utf8StrSz: -1);
      if ( (*(_WORD *)(v13 + 22) & 0x80u) != 0 && (*(_WORD *)(v13 + 22) & 0x8000) != 0 )
        GStringBuffer::AppendString(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
          putf8str: "LI",
          utf8StrSz: -1);
      else
        GStringBuffer::AppendString(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
          putf8str: "P",
          utf8StrSz: -1);
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
        putf8str: " ALIGN=\"",
        utf8StrSz: -1);
      switch ( (*(unsigned __int16 *)(v13 + 22) >> 9) & 3 )
      {
        case 0:
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: (char *)&stru_102A3F10.m_Memory.m_nGrowSize,
            utf8StrSz: -1);
          break;
        case 1:
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: (char *)&stru_102A3F10,
            utf8StrSz: -1);
          break;
        case 2:
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: (char *)&stru_102A9C00.m_FirstFree,
            utf8StrSz: -1);
          break;
        case 3:
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "CENTER",
            utf8StrSz: -1);
          break;
      }
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
        putf8str: (char *)&stru_102A9C00.m_Root,
        utf8StrSz: -1);
      memset(v80, 0, sizeof(v80));
      v81 = nullptr;
      v82 = m_pfnProxied + 4;
      v83 = m_pfnProxied + 4;
      v84 = 0;
      v85 = m_pfnProxied;
      v86 = 0;
      LODWORD(pnum.m_Proxy.m_pfnProxied) = 0;
      v91 = 0;
      if ( m_pfnProxied[1] != 0 )
      {
        while ( 1 )
        {
          v19 = GFxTextParagraph::FormatRunIterator::operator*(this: v80);
          v20 = v19[3];
          if ( v20 != 0 )
            break;
LABEL_105:
          v42 = 0;
          if ( v19[2] != 0 )
          {
            v43 = pnum.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
            do
            {
              v44 = *(_WORD *)(*v19 + 2 * v42);
              if ( v44 != (unsigned __int8)(((int)v43[8].dtr_CRefCountServiceDestruct<CRefST> & 2) != 0 ? 13 : 10)
                && v44 != 0 )
              {
                switch ( *(_WORD *)(*v19 + 2 * v42) )
                {
                  case 0x22:
                    GStringBuffer::AppendString(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      putf8str: "&quot;",
                      utf8StrSz: -1);
                    break;
                  case 0x26:
                    GStringBuffer::AppendString(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      putf8str: "&amp;",
                      utf8StrSz: -1);
                    break;
                  case 0x27:
                    GStringBuffer::AppendString(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      putf8str: "&apos;",
                      utf8StrSz: -1);
                    break;
                  case 0x3C:
                    GStringBuffer::AppendString(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      putf8str: "&lt;",
                      utf8StrSz: -1);
                    break;
                  case 0x3E:
                    GStringBuffer::AppendString(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      putf8str: "&gt;",
                      utf8StrSz: -1);
                    break;
                  case 0xA0:
                    GStringBuffer::AppendString(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      putf8str: "&nbsp;",
                      utf8StrSz: -1);
                    break;
                  default:
                    GStringBuffer::AppendChar(
                      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                      ch: (CMatRenderContextBase *)*(unsigned __int16 *)(*v19 + 2 * v42),
                      srcSize: v51);
                    break;
                }
              }
              ++v42;
            }
            while ( v42 < v19[2] );
          }
          v45 = v19[3];
          if ( v45 != 0 )
          {
            if ( (*(_BYTE *)(v45 + 40) & 4) != 0 )
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "</U>",
                utf8StrSz: -1);
            if ( (*(_BYTE *)(v19[3] + 40) & 2) != 0 )
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "</I>",
                utf8StrSz: -1);
            if ( (*(_BYTE *)(v19[3] + 40) & 1) != 0 )
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "</B>",
                utf8StrSz: -1);
            v46 = v19[3];
            if ( (*(_WORD *)(v46 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v46 + 16)) != 0 )
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "</A>",
                utf8StrSz: -1);
          }
LABEL_128:
          if ( v84 < 0 || (unsigned int)v84 >= v83[1] )
          {
            v48 = v85[1];
          }
          else
          {
            v47 = (unsigned int *)(*v83 + 12 * v84);
            if ( v86 >= *v47 )
            {
              v48 = v47[1] + v86;
              v86 = v48;
              if ( v84 < v83[1] )
                ++v84;
              goto LABEL_136;
            }
            v48 = *(_DWORD *)(*v83 + 12 * v84);
          }
          v86 = v48;
LABEL_136:
          if ( v48 >= v85[1] )
          {
            if ( v91 != 0 )
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "</FONT>",
                utf8StrSz: -1);
            goto LABEL_139;
          }
        }
        if ( (*(_WORD *)(v20 + 42) & 0x200) != 0 )
        {
          v21 = *(_DWORD *)(v20 + 24);
          v89 |= 1u;
          if ( v21 != 0 )
            ++*(_DWORD *)(v21 + 4);
          m_nUserID = *(GRefCountNTSImpl **)(v20 + 24);
          m_iRefs = (GRefCountNTSImpl *)pnum.m_iRefs;
          pnum.m_nUserID = (unsigned int)m_nUserID;
          p_m_nUserID = (int *)&pnum.m_nUserID;
        }
        else
        {
          v89 |= 2u;
          m_nUserID = (GRefCountNTSImpl *)pnum.m_nUserID;
          m_iRefs = nullptr;
          pnum.m_iRefs = 0;
          p_m_nUserID = &pnum.m_iRefs;
        }
        v25 = *p_m_nUserID;
        if ( (v89 & 2) != 0 )
        {
          v89 &= ~2u;
          if ( m_iRefs != nullptr )
            GRefCountNTSImpl::Release(this: m_iRefs);
        }
        if ( (v89 & 1) != 0 )
        {
          v89 &= ~1u;
          if ( m_nUserID != nullptr )
            GRefCountNTSImpl::Release(this: m_nUserID);
        }
        if ( v25 != 0 )
        {
          ++*(_DWORD *)(v25 + 4);
          v26 = v19[3];
          if ( (*(_WORD *)(v26 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v26 + 16)) != 0 )
          {
            v27 = (struct GString *)v19[3];
            v70[0] = 1;
            v70[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v99, a2: (const struct GMsgFormat::Sink *)v70);
            GMsgFormat::Parse(
              this: &v99,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9C00);
            GMsgFormat::FormatD1<GStringLH>(this: (GMsgFormat *)&v99, a2: v27 + 4);
            GMsgFormat::FinishFormatD(this: &v99);
            GMsgFormat::~GMsgFormat(this: &v99);
          }
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "<IMG SRC=\"",
            utf8StrSz: -1);
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: (char *)((*(_DWORD *)(v25 + 56) & 0xFFFFFFFC) + 8),
            utf8StrSz: *(_DWORD *)(*(_DWORD *)(v25 + 56) & 0xFFFFFFFC) & 0x7FFFFFFF);
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "\"",
            utf8StrSz: -1);
          v28 = *(_DWORD *)(v25 + 24);
          if ( v28 != 0 )
          {
            v72.m_SpaceUsed = v28 / 0x14;
            v65[0] = 1;
            v65[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v107, a2: (const struct GMsgFormat::Sink *)v65);
            GMsgFormat::Parse(
              this: &v107,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" WIDTH=\"{0}\"");
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v107, a2: (int)&v72.m_SpaceUsed);
            GMsgFormat::FinishFormatD(this: &v107);
            GMsgFormat::~GMsgFormat(this: &v107);
          }
          v29 = *(_DWORD *)(v25 + 28);
          if ( v29 != 0 )
          {
            v73 = v29 / 0x14;
            v55[0] = 1;
            v55[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v105, a2: (const struct GMsgFormat::Sink *)v55);
            GMsgFormat::Parse(
              this: &v105,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" HEIGHT=\"{0}\"");
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v105, a2: (int)&v73);
            GMsgFormat::FinishFormatD(this: &v105);
            GMsgFormat::~GMsgFormat(this: &v105);
          }
          v30 = *(_DWORD *)(v25 + 64);
          if ( v30 != 0 )
          {
            v63[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            v78.m_TotalLen = v30 / 20;
            v63[0] = 1;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v102, a2: (const struct GMsgFormat::Sink *)v63);
            GMsgFormat::Parse(
              this: &v102,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" VSPACE=\"{0}\"");
            GMsgFormat::FormatD1<int>(this: (int)&v102, result: &v78);
            GMsgFormat::FinishFormatD(this: &v102);
            GMsgFormat::~GMsgFormat(this: &v102);
          }
          if ( *(_DWORD *)(v25 + 68) != 0 )
          {
            v75.m_TotalLen = *(_DWORD *)(v25 + 68) / 20;
            v57[0] = 1;
            v57[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v100, a2: (const struct GMsgFormat::Sink *)v57);
            GMsgFormat::Parse(
              this: &v100,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9BA8.m_Elements.m_nGrowSize);
            GMsgFormat::FormatD1<int>(this: (int)&v100, result: &v75);
            GMsgFormat::FinishFormatD(this: &v100);
            GMsgFormat::~GMsgFormat(this: &v100);
          }
          if ( (*(_DWORD *)(*(_DWORD *)(v25 + 60) & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
          {
            v61[0] = 1;
            v61[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v98, a2: (const struct GMsgFormat::Sink *)v61);
            GMsgFormat::Parse(
              this: &v98,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9BA8);
            GMsgFormat::FormatD1<GStringLH>(this: (GMsgFormat *)&v98, a2: (struct GString *)(v25 + 60));
            GMsgFormat::FinishFormatD(this: &v98);
            GMsgFormat::~GMsgFormat(this: &v98);
          }
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: " ALIGN=\"",
            utf8StrSz: -1);
          if ( *(_BYTE *)(v25 + 76) != 0 )
          {
            if ( *(_BYTE *)(v25 + 76) == 1 )
            {
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "right",
                utf8StrSz: -1);
            }
            else if ( *(_BYTE *)(v25 + 76) == 2 )
            {
              GStringBuffer::AppendString(
                this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
                putf8str: "left",
                utf8StrSz: -1);
            }
          }
          else
          {
            GStringBuffer::AppendString(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
              putf8str: "baseline",
              utf8StrSz: -1);
          }
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: (char *)&stru_102A9C00.m_Root,
            utf8StrSz: -1);
          v31 = v19[3];
          if ( (*(_WORD *)(v31 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v31 + 16)) != 0 )
            GStringBuffer::AppendString(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
              putf8str: "</A>",
              utf8StrSz: -1);
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v25);
          goto LABEL_128;
        }
        if ( v91 != 0 )
        {
          v32 = (IShaderAPI *)pnum.m_Proxy.m_pfnProxied;
          if ( LODWORD(pnum.m_Proxy.m_pfnProxied) != 0
            && !GFxTextFormat::IsHTMLFontTagSame(
                  this: (GFxTextFormat *)pnum.m_Proxy.m_pfnProxied,
                  fmt: (const struct GFxTextFormat *)v19[3]) )
          {
            GStringBuffer::AppendString(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
              putf8str: "</FONT>",
              utf8StrSz: -1);
            goto LABEL_80;
          }
        }
        else
        {
LABEL_80:
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "<FONT",
            utf8StrSz: -1);
          v33 = v19[3];
          if ( (*(_BYTE *)(v33 + 42) & 4) != 0 )
          {
            v69[0] = 1;
            v69[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            FontList = GFxTextFormat::GetFontList(this: (char **)v33);
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v96, a2: (const struct GMsgFormat::Sink *)v69);
            GMsgFormat::Parse(
              this: &v96,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" FACE=\"{0}\"");
            GMsgFormat::FormatD1<GStringLH>(this: (GMsgFormat *)&v96, a2: (struct GString *)FontList);
            GMsgFormat::FinishFormatD(this: &v96);
            GMsgFormat::~GMsgFormat(this: &v96);
          }
          v35 = v19[3];
          if ( (*(_BYTE *)(v35 + 42) & 8) != 0 )
          {
            v90 = *(unsigned __int16 *)(v35 + 38);
            v68[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            v68[0] = 1;
            *(float *)&v90 = (double)v90 / 20.0;
            v87 = (__int64)*(float *)&v90;
            HIDWORD(v87) = v87;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v94, a2: (const struct GMsgFormat::Sink *)v68);
            GMsgFormat::Parse(
              this: &v94,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" SIZE=\"{0}\"");
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v94, a2: (int)&v87 + 4);
            GMsgFormat::FinishFormatD(this: &v94);
            GMsgFormat::~GMsgFormat(this: &v94);
          }
          v36 = v19[3];
          if ( (*(_BYTE *)(v36 + 42) & 1) != 0 )
          {
            v76.m_nAllocationCount = *(_DWORD *)(v36 + 32) & 0xFFFFFF;
            v66[0] = 1;
            v66[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v92, a2: (const struct GMsgFormat::Sink *)v66);
            GMsgFormat::Parse(
              this: &v92,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" COLOR=\"#{0:X:.6}\"");
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v92, a2: (int)&v76.m_nAllocationCount);
            GMsgFormat::FinishFormatD(this: &v92);
            GMsgFormat::~GMsgFormat(this: &v92);
          }
          v37 = v19[3];
          if ( (*(_BYTE *)(v37 + 42) & 2) != 0 )
          {
            v90 = *(__int16 *)(v37 + 36);
            v64[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            v64[0] = 1;
            *(float *)&v76.m_pMemory = (double)v90 / 20.0;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)v103, a2: (const struct GMsgFormat::Sink *)v64);
            GMsgFormat::Parse(
              this: v103,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)" LETTERSPACING=\"{0}\"");
            GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v103, v: &v76);
            GMsgFormat::FinishFormatD(this: v103);
            GMsgFormat::~GMsgFormat(this: v103);
          }
          v38 = v19[3];
          if ( (*(_WORD *)(v38 + 42) & 0x400) != 0 )
          {
            *(_DWORD *)v75.m_Data = *(unsigned __int8 *)(v38 + 35);
            v62[0] = 1;
            v62[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
            GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v106, a2: (const struct GMsgFormat::Sink *)v62);
            GMsgFormat::Parse(
              this: &v106,
              result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9B14.m_pElements);
            GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v106, a2: (int)v75.m_Data);
            GMsgFormat::FinishFormatD(this: &v106);
            GMsgFormat::~GMsgFormat(this: &v106);
          }
          HIBYTE(v90) = (*(_BYTE *)(v19[3] + 40) & 8) != 0;
          v60[0] = 1;
          v60[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
          GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v104, a2: (const struct GMsgFormat::Sink *)v60);
          GMsgFormat::Parse(
            this: &v104,
            result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9B14);
          GMsgFormat::FormatD1<bool>(this: (GMsgFormat *)&v104, a2: (bool *)&v90 + 3);
          GMsgFormat::FinishFormatD(this: &v104);
          GMsgFormat::~GMsgFormat(this: &v104);
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: ">",
            utf8StrSz: -1);
          v32 = (IShaderAPI *)pnum.m_Proxy.m_pfnProxied;
          v91 = 1;
        }
        v39 = v19[3];
        if ( (*(_WORD *)(v39 + 42) & 0x100) != 0 && GString::GetLength(this: (GString *)(v39 + 16)) != 0 )
        {
          v40 = (struct GString *)v19[3];
          v58[0] = 1;
          v58[1] = (char *)&pnum.m_Proxy.m_pfnProxied + 8;
          GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v95, a2: (const struct GMsgFormat::Sink *)v58);
          GMsgFormat::Parse(
            this: &v95,
            result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A9C00);
          GMsgFormat::FormatD1<GStringLH>(this: (GMsgFormat *)&v95, a2: v40 + 4);
          GMsgFormat::FinishFormatD(this: &v95);
          GMsgFormat::~GMsgFormat(this: &v95);
        }
        if ( (*(_BYTE *)(v19[3] + 40) & 1) != 0 )
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "<B>",
            utf8StrSz: -1);
        if ( (*(_BYTE *)(v19[3] + 40) & 2) != 0 )
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "<I>",
            utf8StrSz: -1);
        if ( (*(_BYTE *)(v19[3] + 40) & 4) != 0 )
          GStringBuffer::AppendString(
            this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
            putf8str: "<U>",
            utf8StrSz: -1);
        v41 = (IShaderDevice *)v19[3];
        if ( v41 != nullptr )
          GRefCountImpl::AddRef(this: v41);
        if ( v32 != nullptr )
          GRefCountImpl::Release(this: v32);
        LODWORD(pnum.m_Proxy.m_pfnProxied) = v19[3];
        goto LABEL_105;
      }
LABEL_139:
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
        putf8str: "</",
        utf8StrSz: -1);
      if ( (*(_WORD *)(v79 + 22) & 0x80u) != 0 && (*(_WORD *)(v79 + 22) & 0x8000) != 0 )
        GStringBuffer::AppendString(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
          putf8str: "LI",
          utf8StrSz: -1);
      else
        GStringBuffer::AppendString(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
          putf8str: "P",
          utf8StrSz: -1);
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8),
        putf8str: "></TEXTFORMAT>",
        utf8StrSz: -1);
      if ( LODWORD(pnum.m_Proxy.m_pfnProxied) != 0 )
        GRefCountImpl::Release(this: (IShaderAPI *)pnum.m_Proxy.m_pfnProxied);
      if ( v81 != nullptr )
        GRefCountImpl::Release(this: v81);
    }
    v6 = v71;
    v4 = pnum.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable + 3;
    if ( v71 < (int)pnum.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable[4].dtr_CRefCountServiceDestruct<CRefST> )
      v6 = ++v71;
    m_SpaceUsed = v78.m_SpaceUsed;
    v3 = nullptr;
  }
  v49 = v77;
  GString::GString(this: v77, result: (const CImagePacker *)((char *)&pnum.m_Proxy.m_pfnProxied + 8));
  GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&pnum.m_Proxy.m_pfnProxied + 8));
  return (struct GString)v49;
}

//------------------------------------------------------------------------------
// Address: 0x10162C30
// Name: public: GFxTextParagraph::GFxTextParagraph(class GFxTextAllocator __near *)
// Source: json
//------------------------------------------------------------------------------
const GFxResourceId *__thiscall GFxTextParagraph::GFxTextParagraph(int this, const GFxResourceId *result)
{
  const GFxResourceId *v2; // eax
  unsigned int Id; // ecx

  v2 = (const GFxResourceId *)this;
  *(_DWORD *)this = 0;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_WORD *)(this + 36) = 0;
  Id = result[6].Id;
  result[6].Id = Id + 1;
  v2[8].Id = Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10162CD0
// Name: protected: class GFxTextAllocator __near * GFxStyledText::GetAllocator(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::GetAllocator(SFTextObjectImpl *this)
{
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v2; // esi
  int (__thiscall *v3)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  GStringDH *v4; // eax
  GStringDH *v5; // esi
  GRefCountNTSImpl *m_nAllocationCount; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_TextBoxes.m_Memory.m_nAllocationCount == 0 )
  {
    v2 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
    v3 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v2->m_pfnProxied) + 40);
    v7 = 324;
    v4 = (GStringDH *)v3(a1: v2, a2: 80, a3: &v7);
    if ( v4 != nullptr )
      v5 = GFxTextAllocator::GFxTextAllocator(this: v4, result: v2, flags: 0);
    else
      v5 = nullptr;
    m_nAllocationCount = (GRefCountNTSImpl *)this->m_TextBoxes.m_Memory.m_nAllocationCount;
    if ( m_nAllocationCount != nullptr )
      GRefCountNTSImpl::Release(this: m_nAllocationCount);
    this->m_TextBoxes.m_Memory.m_nAllocationCount = (int)v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162D40
// Name: public: class GFxTextParagraph __near * GFxTextAllocator::AllocateParagraph(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *__thiscall GFxTextAllocator::AllocateParagraph(CMaterial *this)
{
  volatile int m_value; // ecx
  int (__thiscall *v3)(volatile int, int, int *); // eax
  IMaterialVar *result; // eax
  IMaterialVar_vtbl *v5; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  m_value = this->m_RefCount.m_value;
  v3 = *(int (__thiscall **)(volatile int, int, int *))(*(_DWORD *)m_value + 40);
  v6 = 324;
  result = (IMaterialVar *)v3(a1: m_value, a2: 40, a3: &v6);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = nullptr;
  result->m_pStringVal = nullptr;
  result->m_intVal = 0;
  result->m_VecVal.x = 0.0;
  result->m_VecVal.y = 0.0;
  result->m_VecVal.z = 0.0;
  result->m_VecVal.w = 0.0;
  *((_DWORD *)result + 7) = 0;
  LOWORD(result[1].m_pStringVal) = 0;
  v5 = *(IMaterialVar_vtbl **)&this->m_Name.m_Id;
  *(_DWORD *)&this->m_Name.m_Id = (char *)&v5->GetTextureValue + 1;
  result[1].__vftable = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10162DA0
// Name: public: void GFxStyledText::SetDefaultTextFormat(class GFxTextFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxStyledText::SetDefaultTextFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        int defaultTextFmt)
{
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // eax
  GRefCountNTSImpl *v6; // ecx
  int v7; // edx
  __int16 v8; // ax
  __int16 v9; // ax
  CMaterial *v10; // eax
  GStringDH *TextFormat; // eax
  IShaderAPI *v12; // ecx
  GStringDH *v13; // esi
  GStringDH *result; // eax
  CMaterial *v15; // eax
  IShaderAPI *v16; // ecx
  const GFxValue *v17; // esi
  CUtlBuffer *v18; // [esp-4h] [ebp-3Ch]
  CUtlBuffer *v19; // [esp-4h] [ebp-3Ch]
  SFTextObjectImpl v20; // [esp+8h] [ebp-30h] BYREF
  GRefCountNTSImpl *v21; // [esp+20h] [ebp-18h]
  int v22; // [esp+24h] [ebp-14h]
  int v23; // [esp+28h] [ebp-10h]
  __int16 v24; // [esp+2Ch] [ebp-Ch]
  __int16 v25; // [esp+2Eh] [ebp-Ah]
  char v26; // [esp+30h] [ebp-8h]
  __int16 v27; // [esp+32h] [ebp-6h]
  char v28; // [esp+37h] [ebp-1h]

  GFxTextFormat::GetImageDesc(this: (CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *)defaultTextFmt);
  if ( v3 != 0 )
  {
    v18 = *(CUtlBuffer **)(defaultTextFmt + 12);
    v20.m_TextBoxes.m_Memory.m_pMemory = (GFxValue *)1;
    v20.__vftable = (SFTextObjectImpl_vtbl *)&GFxTextFormat::`vftable';
    GStringDH::CopyConstructHelper(
      this: (GStringDH *)&v20.m_TextBoxes.m_Memory.m_nAllocationCount,
      a2: (const struct GString *)(defaultTextFmt + 8),
      pheap: v18);
    v19 = *(CUtlBuffer **)(defaultTextFmt + 12);
    v28 = 0;
    GStringDH::CopyConstructHelper(
      this: (GStringDH *)&v20.m_TextBoxes.m_Size,
      a2: (const struct GString *)(defaultTextFmt + 16),
      pheap: v19);
    v4 = *(_DWORD *)(defaultTextFmt + 24);
    if ( v4 != 0 )
      ++*(_DWORD *)(v4 + 4);
    v5 = *(_DWORD **)(defaultTextFmt + 28);
    v6 = *(GRefCountNTSImpl **)(defaultTextFmt + 24);
    v21 = v6;
    if ( v5 != nullptr )
    {
      ++*v5;
      v6 = v21;
    }
    v7 = *(_DWORD *)(defaultTextFmt + 28);
    v23 = *(_DWORD *)(defaultTextFmt + 32);
    v8 = *(_WORD *)(defaultTextFmt + 38);
    v22 = v7;
    LOWORD(v7) = *(_WORD *)(defaultTextFmt + 36);
    v25 = v8;
    v9 = *(_WORD *)(defaultTextFmt + 42);
    v24 = v7;
    v26 = *(_BYTE *)(defaultTextFmt + 40);
    v27 = v9;
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: v6);
    v27 |= 0x200u;
    v21 = nullptr;
    GFxStyledText::GetAllocator((SFTextObjectImpl *)this);
    TextFormat = GFxTextAllocator::AllocateTextFormat(this: v10, srcfmt: (int)&v20);
    v12 = *((IShaderAPI **)this + 7);
    v13 = TextFormat;
    if ( v12 != nullptr )
      GRefCountImpl::Release(this: v12);
    *((_DWORD *)this + 7) = v13;
    return (GStringDH *)GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v20);
  }
  else
  {
    GFxStyledText::GetAllocator((SFTextObjectImpl *)this);
    result = GFxTextAllocator::AllocateTextFormat(this: v15, srcfmt: defaultTextFmt);
    v16 = *((IShaderAPI **)this + 7);
    v17 = (const GFxValue *)result;
    if ( v16 != nullptr )
      result = (GStringDH *)GRefCountImpl::Release(this: v16);
    *((_DWORD *)this + 7) = v17;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10162EC0
// Name: public: void GFxStyledText::SetDefaultParagraphFormat(class GFxTextParagraphFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::SetDefaultParagraphFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        GRefCountNTSImpl *a2)
{
  CMaterial *v3; // eax
  GFxTextParagraphFormat *ParagraphFormat; // eax
  GRefCountNTSImpl *v5; // ecx
  GFxTextParagraphFormat *v6; // edi
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+4h] [ebp-4h]
  ImageFormat savedregs; // [esp+8h] [ebp+0h]

  GFxStyledText::GetAllocator((SFTextObjectImpl *)this);
  ParagraphFormat = GFxTextAllocator::AllocateParagraphFormat(this: v3, srcfmt: a2, pfmt: v7, a4: v8, a5: savedregs);
  v5 = *((GRefCountNTSImpl **)this + 6);
  v6 = ParagraphFormat;
  if ( v5 != nullptr )
    GRefCountNTSImpl::Release(this: v5);
  *((_DWORD *)this + 6) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10162EF0
// Name: public: void GFxStyledText::SetDefaultTextFormat(class GFxTextFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::SetDefaultTextFormat(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        CMemberFuncProxy3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CFuncMemPolicyNone> *a2)
{
  int v3; // eax
  IShaderAPI *v4; // ecx

  GFxTextFormat::GetImageDesc(this: a2);
  if ( v3 != 0 )
  {
    GFxStyledText::SetDefaultTextFormat(this, defaultTextFmt: (int)a2);
  }
  else
  {
    if ( a2 != nullptr )
      GRefCountImpl::AddRef(this: (IShaderDevice *)a2);
    v4 = *((IShaderAPI **)this + 7);
    if ( v4 != nullptr )
      GRefCountImpl::Release(this: v4);
    *((_DWORD *)this + 7) = a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162F40
// Name: public: void GArrayDataDH<struct GFxSGMLStackElemDesc<wchar_t>,struct GAllocatorDH<struct GFxSGMLStackElemDesc<wchar_t>,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayDataDH<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Resize(
        int this,
        MaterialVarFlags_t a2)
{
  void *result; // eax
  unsigned int v4; // edi
  GStringDH *v5; // edi
  unsigned __int32 v6; // esi
  unsigned int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  result = *(void **)(this + 12);
  v4 = *(_DWORD *)(this + 4);
  v7 = v4;
  v8 = (int)result;
  if ( a2 >= v4 )
  {
    if ( (unsigned int)a2 >= *(_DWORD *)(this + 8) )
      result = GArrayDataBase<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
                 (void **)this,
                 a2: (int)result,
                 a3: a2 + ((unsigned int)a2 >> 2));
  }
  else
  {
    result = GConstructorMov<GFxSGMLStackElemDesc<wchar_t>>::DestructArray(
               a1: a2,
               a2: *(_DWORD *)this + 84 * a2,
               a3: v4 - a2);
    if ( (unsigned int)a2 < *(_DWORD *)(this + 8) >> 1 )
      result = GArrayDataBase<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
                 (void **)this,
                 a2: v8,
                 a3: a2);
  }
  *(_DWORD *)(this + 4) = a2;
  if ( a2 > v4 )
  {
    v5 = (GStringDH *)(*(_DWORD *)this + 84 * v4);
    v6 = a2 - v7;
    if ( a2 != v7 )
    {
      do
      {
        if ( v5 != nullptr )
          result = GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(this: v5);
        v5 = (GStringDH *)((char *)v5 + 84);
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10162FD0
// Name: public: void GArrayDataDH<struct GFxSGMLStackElemDesc<wchar_t>,struct GAllocatorDH<struct GFxSGMLStackElemDesc<wchar_t>,2>,struct GArrayDefaultPolicy>::PushBack(struct GFxSGMLStackElemDesc<wchar_t> const __near &)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GArrayDataDH<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::PushBack(
        int this,
        int a2)
{
  unsigned int v3; // eax
  int v4; // ebx
  MaterialVarFlags_t v5; // esi
  GStringDH *result; // eax
  int v7; // esi

  v3 = *(_DWORD *)(this + 4);
  v4 = *(_DWORD *)(this + 12);
  v5 = v3 + 1;
  if ( v3 + 1 >= v3 )
  {
    if ( (unsigned int)v5 >= *(_DWORD *)(this + 8) )
      GArrayDataBase<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
        (void **)this,
        a2: v4,
        a3: v5 + ((unsigned int)v5 >> 2));
  }
  else
  {
    GConstructorMov<GFxSGMLStackElemDesc<wchar_t>>::DestructArray(a1: v5, a2: *(_DWORD *)this + 84 * v5, a3: -1);
    if ( (unsigned int)v5 < *(_DWORD *)(this + 8) >> 1 )
      GArrayDataBase<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
        (void **)this,
        a2: v4,
        a3: v5);
  }
  result = *(GStringDH **)this;
  *(_DWORD *)(this + 4) = v5;
  v7 = 84 * v5;
  if ( (GStringDH *)((char *)result + v7) != (GStringDH *)84 )
    return GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(
             this: (GStringDH *)((char *)result + v7 - 84),
             a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163040
// Name: public: void GFxTextParagraph::Clear(void)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall GFxTextParagraph::Clear(int this)
{
  const wchar_t *result; // eax

  *(_DWORD *)(this + 4) = 0;
  result = GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
             this: this + 16,
             pheapAddr: (const void *)(this + 16),
             newSize: 0);
  ++*(_WORD *)(this + 36);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163770
// Name: private: void GFxTextParagraph::SetTermNullFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::SetTermNullFormat(char *this)
{
  unsigned int v1; // eax
  int v2; // edx
  unsigned int v3; // esi
  _WORD *v4; // esi
  int v5; // edi
  unsigned int v6; // esi
  _WORD *v7; // eax
  GFxZlibSupportBase *v8; // esi

  v1 = *((_DWORD *)this + 1);
  if ( v1 != 0 )
  {
    v2 = *(_DWORD *)this;
    v3 = v1 - 1;
    if ( *(_DWORD *)this != 0 && v3 < v1 )
      v4 = (_WORD *)(v2 + 2 * v3);
    else
      v4 = nullptr;
    if ( *v4 == 0 )
    {
      v5 = *((_DWORD *)this + 1);
      v6 = v1 - 1;
      if ( v2 != 0 && v6 < v1 )
        v7 = (_WORD *)(v2 + 2 * v6);
      else
        v7 = nullptr;
      if ( *v7 == 0 )
        --v5;
      v8 = (GFxZlibSupportBase *)(this + 16);
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
        this: (GFxZlibSupportBase *)(this + 16),
        a2: v5,
        a3: 1);
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
        this: v8,
        index: (GetTriangles_Vertex_t *)(v5 + 1),
        a3: 1u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101637E0
// Name: public: void GFxTextParagraph::Remove(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::Remove(int this, unsigned int startPos, unsigned int endPos)
{
  unsigned int v4; // ebx
  unsigned int v5; // eax

  if ( endPos == -1 )
  {
    v4 = -1;
  }
  else
  {
    v4 = endPos - startPos;
    if ( endPos == startPos )
      return;
  }
  v5 = *(_DWORD *)(this + 4);
  if ( startPos < v5 )
  {
    if ( v4 + startPos < v5 )
    {
      memmove(
        dst: (unsigned __int8 *)(*(_DWORD *)this + 2 * startPos),
        src: (unsigned __int8 *)(*(_DWORD *)this + 2 * (v4 + startPos)),
        count: 2 * (v5 - v4 - startPos));
      *(_DWORD *)(this + 4) -= v4;
    }
    else
    {
      *(_DWORD *)(this + 4) = startPos;
    }
  }
  GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
    this: (GFxZlibSupportBase *)(this + 16),
    index: (GetTriangles_Vertex_t *)startPos,
    a3: v4);
  GFxTextParagraph::SetTermNullFormat((char *)this);
  ++*(_WORD *)(this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x10163850
// Name: public: void GFxTextParagraph::Shrink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::Shrink(GFxFontMap::MapEntry *this, const GFxFontMap::MapEntry *delta)
{
  unsigned int ScaleFactor_low; // eax
  const GFxFontMap::MapEntry *v4; // ecx
  GetTriangles_Vertex_t *v5; // esi
  unsigned int v6; // ebx

  ScaleFactor_low = LODWORD(this->ScaleFactor);
  v4 = delta;
  if ( (unsigned int)delta >= ScaleFactor_low )
    v4 = (const GFxFontMap::MapEntry *)ScaleFactor_low;
  v5 = (GetTriangles_Vertex_t *)(ScaleFactor_low - (_DWORD)v4);
  if ( ScaleFactor_low == -1 )
  {
    v6 = -1;
  }
  else
  {
    v6 = (unsigned int)v4;
    if ( (GetTriangles_Vertex_t *)ScaleFactor_low == v5 )
      return;
  }
  if ( (unsigned int)v5 < ScaleFactor_low )
  {
    if ( (unsigned int)v5 + v6 < ScaleFactor_low )
    {
      memmove(
        dst: (unsigned __int8 *)(this->Name.HeapTypeBits + 2 * (ScaleFactor_low - (_DWORD)v4)),
        src: (unsigned __int8 *)(this->Name.HeapTypeBits + 2 * ((_DWORD)v5 + v6)),
        count: 2 * ((_DWORD)v4 - v6));
      LODWORD(this->ScaleFactor) -= v6;
    }
    else
    {
      LODWORD(this->ScaleFactor) = v5;
    }
  }
  GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
    this: (GFxZlibSupportBase *)&this->Flags,
    index: v5,
    a3: v6);
  GFxTextParagraph::SetTermNullFormat((char *)this);
  ++*((_WORD *)this + 18);
}

//------------------------------------------------------------------------------
// Address: 0x10163910
// Name: public: static void GConstructorMov<class GFxStyledText::ParagraphPtrWrapper>::DestructArray(class GFxStyledText::ParagraphPtrWrapper __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall GConstructorMov<GFxStyledText::ParagraphPtrWrapper>::DestructArray(
        _DWORD *a1@<edi>,
        int count,
        unsigned int counta)
{
  _DWORD *v4; // edi
  int v5; // eax
  IShaderAPI **v6; // esi
  int v7; // ebx
  GRefCountNTSImpl *v8; // ecx
  _DWORD *i; // [esp+8h] [ebp+8h]

  for ( i = (_DWORD *)(count + 4 * counta - 4); counta != 0; --counta )
  {
    v4 = (_DWORD *)*i;
    if ( *i != 0 )
    {
      v5 = v4[5];
      v6 = (IShaderAPI **)(v4[4] + 12 * v5 - 4);
      if ( v5 != 0 )
      {
        v7 = v4[5];
        do
        {
          if ( *v6 != nullptr )
            GRefCountImpl::Release(this: *v6);
          v6 -= 3;
          --v7;
        }
        while ( v7 != 0 );
      }
      ((void (__thiscall *)(GMemoryHeap *, _DWORD, _DWORD *))GMemory::pGlobalHeap->Free)(
        a1: GMemory::pGlobalHeap,
        a2: v4[4],
        a3: a1);
      v8 = (GRefCountNTSImpl *)v4[3];
      if ( v8 != nullptr )
        GRefCountNTSImpl::Release(this: v8);
      a1 = v4;
      ((void (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap);
    }
    --i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101639A0
// Name: public: GFxTextParagraph::GFxTextParagraph(class GFxTextParagraph const __near &,class GFxTextAllocator __near *)
// Source: json
//------------------------------------------------------------------------------
GFxResourceId *__userpurge GFxTextParagraph::GFxTextParagraph@<eax>(
        GFxResourceId *this@<ecx>,
        int result,
        GRect<float> o)
{
  int v3; // esi
  unsigned int v4; // eax
  int v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // ecx
  GFxResourceId *v9; // ebx
  int v10; // eax
  float Left; // ecx
  int v12; // eax
  GFxTextParagraphFormat *ParagraphFormat; // eax
  GRefCountNTSImpl *v14; // ecx
  GFxTextParagraphFormat *v15; // esi
  char *v16; // esi
  IShaderDevice *TextFormat; // eax
  IShaderAPI *v18; // ecx
  int v20; // [esp+0h] [ebp-18h]
  int v21; // [esp+4h] [ebp-14h]
  ImageFormat v22; // [esp+8h] [ebp-10h]
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+10h] [ebp-8h]
  int v25; // [esp+14h] [ebp-4h]
  IShaderDevice *v26; // [esp+14h] [ebp-4h]

  v3 = result;
  v4 = *(_DWORD *)(result + 4);
  v6 = *(_DWORD *)(LODWORD(o.Left) + 28);
  result = 324;
  v7 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)v6 + 40))(
                            a1: v6,
                            a2: 2 * v4,
                            a3: &result);
  this->Id = (unsigned int)v7;
  v8 = *(_DWORD *)(v3 + 4);
  *((_DWORD *)this + 1) = v8;
  *((_DWORD *)this + 2) = v8;
  memcpy(dst: v7, src: *(unsigned __int8 **)v3, count: 2 * *(_DWORD *)(v3 + 4));
  *((_DWORD *)this + 3) = 0;
  v9 = this + 4;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  v10 = *(_DWORD *)(v3 + 20);
  v25 = v10;
  result = *(_DWORD *)(v3 + 16);
  if ( v10 != 0 )
  {
    v23 = *((_DWORD *)this + 5);
    GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (int)(this + 4),
      pheapAddr: this + 4,
      newSize: v10 + v23);
    GConstructorMov<GRangeData<GPtr<GFxTextFormat>>>::ConstructArray(
      a1: (_DWORD *)(v9->Id + 12 * v23),
      a2: v25,
      a3: result);
  }
  Left = o.Left;
  *(this + 7) = *(GFxResourceId *)(v3 + 28);
  *((_WORD *)this + 18) = 0;
  v12 = *(_DWORD *)(LODWORD(Left) + 24);
  *(_DWORD *)(LODWORD(Left) + 24) = v12 + 1;
  *((_DWORD *)this + 8) = v12;
  ParagraphFormat = GFxTextAllocator::AllocateParagraphFormat(
                      this: (CMaterial *)LODWORD(Left),
                      srcfmt: *(GRefCountNTSImpl **)(v3 + 12),
                      pfmt: v20,
                      a4: v21,
                      a5: v22);
  v14 = *((GRefCountNTSImpl **)this + 3);
  v15 = ParagraphFormat;
  if ( v14 != nullptr )
    GRefCountNTSImpl::Release(this: v14);
  *((_DWORD *)this + 3) = v15;
  v24 = 0;
  result = 0;
  while ( v24 >= 0 && (unsigned int)v24 < *((_DWORD *)this + 5) )
  {
    v16 = (char *)(result + v9->Id);
    TextFormat = (IShaderDevice *)GFxTextAllocator::AllocateTextFormat(
                                    this: (CMaterial *)LODWORD(o.Left),
                                    srcfmt: *((_DWORD *)v16 + 2));
    v26 = TextFormat;
    if ( TextFormat != nullptr )
    {
      GRefCountImpl::AddRef(this: TextFormat);
      TextFormat = v26;
    }
    v18 = *((IShaderAPI **)v16 + 2);
    if ( v18 != nullptr )
    {
      GRefCountImpl::Release(this: v18);
      TextFormat = v26;
    }
    *((_DWORD *)v16 + 2) = TextFormat;
    if ( TextFormat != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)TextFormat);
    if ( v24 < *((_DWORD *)this + 5) )
    {
      ++v24;
      result += 12;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10163AE0
// Name: public: void GFxTextParagraph::SetTextFormat(class GFxTextAllocator __near *,class GFxTextFormat const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__thiscall GFxTextParagraph::SetTextFormat(
        int this,
        CMaterial *pallocator,
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *fmt_4,
        unsigned int startPos,
        unsigned int length)
{
  unsigned int v5; // esi
  GJPEGSystem *v6; // edi
  unsigned int v7; // eax
  ShaderAPIOcclusionQuery_t__ *result; // eax
  int *v9; // edi
  unsigned int v10; // ebx
  struct GMemoryHeap *m_value; // esi
  int v12; // ecx
  int v13; // eax
  volatile int v14; // edi
  IShaderDevice *TextFormat; // esi
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *v16; // [esp-8h] [ebp-A4h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v17; // [esp+8h] [ebp-94h] BYREF
  GRefCountBase<GFxASUserData,2> it; // [esp+34h] [ebp-68h] BYREF
  IShaderAPI *v19; // [esp+40h] [ebp-5Ch]
  int v20; // [esp+50h] [ebp-4Ch]
  ShaderAPIOcclusionQuery_t__ *v21; // [esp+54h] [ebp-48h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v22; // [esp+58h] [ebp-44h] BYREF
  GStringDH v23; // [esp+60h] [ebp-3Ch] BYREF
  GStringDH v24; // [esp+68h] [ebp-34h] BYREF
  int v25; // [esp+70h] [ebp-2Ch]
  int v26; // [esp+74h] [ebp-28h]
  int v27; // [esp+78h] [ebp-24h]
  int v28; // [esp+7Ch] [ebp-20h]
  char v29; // [esp+80h] [ebp-1Ch]
  __int16 v30; // [esp+82h] [ebp-1Ah]
  GRefCountBaseStatImpl<GRefCountNTSImpl,326> v31; // [esp+84h] [ebp-18h] BYREF
  IShaderAPI *v32; // [esp+8Ch] [ebp-10h]
  ICommandCompletionCallback runLength; // [esp+90h] [ebp-Ch]
  int curIndex; // [esp+94h] [ebp-8h]
  GJPEGSystem *v35; // [esp+98h] [ebp-4h]
  int lengtha; // [esp+B0h] [ebp+14h]

  v5 = startPos;
  v6 = (GJPEGSystem *)this;
  v35 = (GJPEGSystem *)this;
  GFxTextParagraph::FormatRunIterator::FormatRunIterator(
    this: (int *)&it,
    a2: (GFxZlibSupportBase *)(this + 16),
    a3: this,
    a4: startPos);
  v7 = length;
  if ( length < startPos )
    v7 = startPos;
  if ( v7 == -1 )
  {
    lengtha = 0x7FFFFFFF;
  }
  else
  {
    result = (ShaderAPIOcclusionQuery_t__ *)(v7 - startPos);
    lengtha = (int)result;
    if ( (int)result <= 0 )
      goto LABEL_22;
  }
  while ( 1 )
  {
    result = v21;
    if ( (unsigned int)v21 >= *(_DWORD *)(v20 + 4) )
      break;
    v9 = GFxTextParagraph::FormatRunIterator::operator*(this: (int *)&it);
    v10 = v9[1];
    runLength.__vftable = (ICommandCompletionCallback_vtbl *)v9[2];
    curIndex = v5;
    if ( v5 <= v10 )
      curIndex = v10;
    m_value = (struct GMemoryHeap *)pallocator->m_RefCount.m_value;
    v22.m_pObject = (IMaterialInternal *)1;
    v22.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))&GFxTextFormat::`vftable';
    GStringDH::GStringDH(this: &v23, a2: m_value);
    GStringDH::GStringDH(this: &v24, a2: m_value);
    v25 = 0;
    v26 = 0;
    v27 = -16777216;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    v12 = v9[3];
    v16 = fmt_4;
    if ( v12 != 0 )
    {
      v13 = GFxTextFormat::Merge(a1: v12, a2: v10, a3: (int)&v17, fmt: (int)fmt_4);
      GFxTextFormat::operator=(this: (int)&v22, __that: v13);
      GFxTextFormat::~GFxTextFormat(this: &v17);
      v16 = &v22;
    }
    v14 = lengtha;
    TextFormat = (IShaderDevice *)GFxTextAllocator::AllocateTextFormat(this: pallocator, srcfmt: (int)v16);
    if ( (ICommandCompletionCallback_vtbl *)((char *)runLength.__vftable + v10 - curIndex) < (ICommandCompletionCallback_vtbl *)lengtha )
      v14 = (int)runLength.__vftable + v10 - curIndex;
    v31.__vftable = (GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *)curIndex;
    v31.RefCount = v14;
    if ( TextFormat != nullptr )
      GRefCountImpl::AddRef(this: TextFormat);
    v32 = (IShaderAPI *)TextFormat;
    GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
      this: v35 + 2,
      result: &v31);
    if ( v32 != nullptr )
      GRefCountImpl::Release(this: v32);
    lengtha -= v14;
    GFxTextParagraph::FormatRunIterator::SetTextPos(
      this: &it,
      newTextPos: (const GRefCountBase<GFxASUserData,2> *)((char *)runLength.__vftable + v10));
    if ( TextFormat != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)TextFormat);
    result = (ShaderAPIOcclusionQuery_t__ *)GFxTextFormat::~GFxTextFormat(this: &v22);
    v6 = v35;
    if ( lengtha <= 0 )
      break;
    v5 = startPos;
  }
LABEL_22:
  ++LOWORD(v6[4].RefCount);
  if ( v19 != nullptr )
    return GRefCountImpl::Release(this: v19);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163C70
// Name: public: void GFxTextParagraph::InsertString(class GFxTextAllocator __near *,wchar_t const __near *,unsigned int,unsigned int,class GFxTextFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::InsertString(
        int this,
        GFxFontMap *pos,
        unsigned __int8 *src,
        GRefCountBaseStatImpl<GRefCountNTSImpl,326> *index,
        unsigned int length,
        IShaderDevice *a6)
{
  unsigned int v6; // esi
  unsigned __int8 *Position; // ebx
  unsigned __int8 *v9; // ebx

  v6 = length;
  if ( length != 0 )
  {
    if ( length == -1 )
    {
      v6 = 0;
      if ( *(_WORD *)src != 0 )
      {
        do
          ++v6;
        while ( *(_WORD *)&src[2 * v6] != 0 );
      }
    }
    if ( v6 != 0 )
    {
      Position = (unsigned __int8 *)GFxTextParagraph::TextBuffer::CreatePosition(
                                      (int *)this,
                                      result: pos,
                                      a3: (int)index,
                                      length: v6);
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
        this: (GFxZlibSupportBase *)(this + 16),
        a2: (int)index,
        a3: v6);
      ++*(_WORD *)(this + 36);
      if ( Position != nullptr )
      {
        memcpy(dst: Position, src, count: 2 * v6);
        v9 = (unsigned __int8 *)a6;
        if ( a6 != nullptr )
        {
          GRefCountImpl::AddRef(this: a6);
          src = v9;
          GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
            this: (GRefCountBaseStatImpl<GRefCountNTSImpl,326> *)(this + 16),
            (GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *)index,
            length: v6,
            a4: (IShaderAPI **)&src);
          GRefCountImpl::Release(this: (IShaderAPI *)v9);
        }
        GFxTextParagraph::SetTermNullFormat((char *)this);
        ++*(_WORD *)(this + 36);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163D20
// Name: private: void GFxTextParagraph::AppendTermNull(class GFxTextAllocator __near *,class GFxTextFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::AppendTermNull(
        GFxTextParagraph *this,
        GFxFontMap *result,
        const struct GFxTextFormat *a3)
{
  GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *v4; // eax
  char *v5; // edx
  _WORD *v6; // ecx
  GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *v7; // edi
  char *v8; // edx
  _WORD *v9; // eax
  GRefCountBaseStatImpl<GRefCountNTSImpl,326> *v10; // ebx
  GStringDH *TextFormat; // esi
  GFxFontMap *Position; // [esp+4h] [ebp-4h]

  v4 = *((GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl **)this + 1);
  if ( v4 == nullptr
    || ((v5 = (char *)&v4[-1].dtr_GRefCountImplCore + 3, this->pObject == nullptr) || v5 >= (char *)v4
      ? (v6 = nullptr)
      : (v6 = (_WORD *)this->pObject + (_DWORD)v5),
        *v6 != 0) )
  {
    v7 = v4;
    if ( v4 != nullptr )
    {
      v8 = (char *)&v4[-1].dtr_GRefCountImplCore + 3;
      if ( this->pObject != nullptr && v8 < (char *)v4 )
        v9 = (_WORD *)this->pObject + (_DWORD)v8;
      else
        v9 = nullptr;
      if ( *v9 == 0 )
        v7 = (GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *)((char *)v7 - 1);
    }
    v10 = (GRefCountBaseStatImpl<GRefCountNTSImpl,326> *)(this + 4);
    Position = GFxTextParagraph::TextBuffer::CreatePosition((int *)this, result, a3: (int)v7, length: 1u);
    GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
      this: (GFxZlibSupportBase *)(this + 4),
      a2: (int)v7,
      a3: 1);
    ++*((_WORD *)this + 18);
    if ( Position != nullptr )
    {
      LOWORD(Position->__vftable) = 0;
      if ( *((_DWORD *)this + 5) == 0 && a3 != nullptr )
      {
        TextFormat = GFxTextAllocator::AllocateTextFormat(this: (CMaterial *)result, srcfmt: (int)a3);
        result = (GFxFontMap *)TextFormat;
        GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
          this: v10,
          index: v7,
          length: 1,
          a4: (IShaderAPI **)&result);
        if ( TextFormat != nullptr )
          GRefCountImpl::Release(this: (IShaderAPI *)TextFormat);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163DE0
// Name: public: void GFxStyledText::SetTextFormat(class GFxTextFormat const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *__fastcall GFxStyledText::SetTextFormat(
        char *a1,
        int a2,
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *result,
        unsigned int runLen,
        unsigned int endPos)
{
  const char *pString; // edi
  unsigned int v6; // ebx
  _DWORD *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // edi
  _WORD *v11; // esi
  unsigned int v12; // esi
  unsigned int v13; // edi
  _WORD *v14; // eax
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *Length; // eax
  GFxValue index; // [esp+Ch] [ebp-10h] BYREF
  unsigned int runLena; // [esp+28h] [ebp+Ch]

  pString = a1;
  index.Value.pString = a1;
  GFxStyledText::GetParagraphByIndex(
    this: (SFTextObjectImpl *)a1,
    &index,
    indexa: runLen,
    pindexInParagraph: (unsigned int *)&index.Value.pStringManaged + 1);
  v6 = *((_DWORD *)&index.Value.pStringManaged + 1);
  runLena = endPos - runLen;
  while ( index.pObjectInterface != nullptr
       && index.Type >= VT_Undefined
       && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
  {
    v7 = *((_DWORD **)index.pObjectInterface->pMovieRoot + index.Type);
    v8 = v7[1];
    v9 = v8;
    if ( v8 != 0 )
    {
      v10 = v8 - 1;
      if ( *v7 != 0 && v10 < v8 )
        v11 = (_WORD *)(*v7 + 2 * v10);
      else
        v11 = nullptr;
      if ( *v11 == 0 )
        v9 = v8 - 1;
    }
    v12 = v6 + runLena;
    if ( v6 + runLena <= v9 )
    {
      if ( v6 + runLena != v9 )
        goto LABEL_23;
    }
    else
    {
      v12 = v9;
    }
    if ( v8 != 0 )
    {
      v13 = v8 - 1;
      if ( *v7 != 0 && v13 < v8 )
        v14 = (_WORD *)(*v7 + 2 * v13);
      else
        v14 = nullptr;
      if ( *v14 == 0 )
      {
        ++v12;
        if ( runLena != -1 )
          ++runLena;
      }
    }
LABEL_23:
    pString = index.Value.pString;
    GFxTextParagraph::SetTextFormat(
      this: (int)v7,
      pallocator: *((CMaterial **)index.Value.pString + 2),
      fmt_4: result,
      startPos: v6,
      length: v12);
    runLena += v6 - v12;
    v6 = 0;
    if ( index.Type < (int)index.pObjectInterface[1].pMovieRoot )
      ++index.Type;
  }
  Length = result;
  if ( (HIWORD(result[5].m_pfnProxied) & 0x100) != 0 )
  {
    Length = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)GString::GetLength(this: (GString *)&result[2]);
    if ( Length != nullptr )
      *((_BYTE *)pString + 32) |= 1u;
  }
  return Length;
}

//------------------------------------------------------------------------------
// Address: 0x10163FD0
// Name: public: void GFxTextParagraph::InsertString(class GFxTextAllocator __near *,wchar_t const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::InsertString(
        GFxTextParagraph *this,
        GFxFontMap *result,
        wchar_t *src,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int v5; // edi
  unsigned __int8 *Position; // ebx

  v5 = a5;
  if ( a5 != 0 )
  {
    if ( a5 == -1 )
    {
      v5 = 0;
      if ( *src != 0 )
      {
        do
          ++v5;
        while ( src[v5] != 0 );
      }
    }
    if ( v5 != 0 )
    {
      Position = (unsigned __int8 *)GFxTextParagraph::TextBuffer::CreatePosition(
                                      (int *)this,
                                      result,
                                      a3: a4,
                                      length: v5);
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
        this: (GFxZlibSupportBase *)(this + 4),
        a2: a4,
        a3: v5);
      ++*((_WORD *)this + 18);
      if ( Position != nullptr )
      {
        memcpy(dst: Position, (unsigned __int8 *)src, count: 2 * v5);
        GFxTextParagraph::SetTermNullFormat((char *)this);
        ++*((_WORD *)this + 18);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164050
// Name: public: void GFxTextParagraph::Copy(class GFxTextAllocator __near *,class GFxTextParagraph const __near &,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraph::Copy(
        GFxTextParagraph *this,
        CMaterial *a2,
        const struct GFxTextParagraph *a3,
        unsigned int a4,
        unsigned int a5,
        volatile unsigned int a6)
{
  signed int v6; // edi
  int *v7; // eax
  int v8; // ecx
  volatile unsigned int v9; // esi
  int v10; // ebx
  int v11; // eax
  IShaderDevice *TextFormat; // eax
  IShaderAPI *v13; // edi
  unsigned int v14; // ecx
  GJPEGSystem *v15; // edi
  volatile unsigned int RefCount; // eax
  GJPEGSystem_vtbl *v17; // ecx
  volatile unsigned int v18; // edx
  _WORD *v19; // edx
  int v20; // ebx
  volatile unsigned int v21; // edx
  _WORD *v22; // ecx
  int v23[3]; // [esp+4h] [ebp-34h] BYREF
  IShaderAPI *v24; // [esp+10h] [ebp-28h]
  _DWORD *v25; // [esp+18h] [ebp-20h]
  int v26; // [esp+1Ch] [ebp-1Ch]
  int v27; // [esp+20h] [ebp-18h]
  unsigned int v28; // [esp+24h] [ebp-14h]
  GRefCountBaseStatImpl<GRefCountNTSImpl,326> result; // [esp+28h] [ebp-10h] BYREF
  IShaderAPI *v30; // [esp+30h] [ebp-8h]
  GJPEGSystem *v31; // [esp+34h] [ebp-4h]

  v31 = (GJPEGSystem *)this;
  if ( a6 != 0 )
  {
    v6 = a4;
    GFxTextParagraph::InsertString(this, result: (GFxFontMap *)a2, src: (wchar_t *)a3->pObject + a4, a4: a5, a5: a6);
    GFxTextParagraph::FormatRunIterator::FormatRunIterator(this: v23, a2: (GFxZlibSupportBase *)&a3[4], (int)a3, a4);
    if ( v28 < *(_DWORD *)(v27 + 4) )
    {
      do
      {
        if ( a6 == 0 )
          break;
        v7 = GFxTextParagraph::FormatRunIterator::operator*(this: v23);
        v8 = v7[1];
        v9 = v7[2];
        if ( v8 >= v6 )
        {
          v10 = v8 - v6;
        }
        else
        {
          v10 = 0;
          v9 = v8 + v9 - v6;
        }
        if ( v9 >= a6 )
          v9 = a6;
        v11 = v7[3];
        if ( v11 != 0 )
        {
          TextFormat = (IShaderDevice *)GFxTextAllocator::AllocateTextFormat(this: a2, srcfmt: v11);
          v13 = (IShaderAPI *)TextFormat;
          result.__vftable = (GRefCountBaseStatImpl<GRefCountNTSImpl,326>_vtbl *)(a5 + v10);
          result.RefCount = v9;
          if ( TextFormat != nullptr )
            GRefCountImpl::AddRef(this: TextFormat);
          v30 = v13;
          GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::SetRange(
            this: v31 + 2,
            &result);
          if ( v30 != nullptr )
            GRefCountImpl::Release(this: v30);
          if ( v13 != nullptr )
            GRefCountImpl::Release(this: v13);
          v6 = a4;
        }
        a6 -= v9;
        if ( v26 < 0 || (unsigned int)v26 >= v25[1] )
        {
          v14 = *(_DWORD *)(v27 + 4);
        }
        else
        {
          if ( v28 >= *(_DWORD *)(*v25 + 12 * v26) )
          {
            v14 = *(_DWORD *)(*v25 + 12 * v26 + 4) + v28;
            v28 = v14;
            if ( v26 < v25[1] )
              ++v26;
            continue;
          }
          v14 = *(_DWORD *)(*v25 + 12 * v26);
        }
        v28 = v14;
      }
      while ( v14 < *(_DWORD *)(v27 + 4) );
    }
    v15 = v31;
    RefCount = v31->RefCount;
    if ( RefCount != 0 )
    {
      v17 = v31->__vftable;
      v18 = RefCount - 1;
      if ( v31->__vftable != nullptr && v18 < RefCount )
        v19 = (_WORD *)((char *)v17 + 2 * v18);
      else
        v19 = nullptr;
      if ( *v19 == 0 )
      {
        v20 = v31->RefCount;
        v21 = RefCount - 1;
        if ( v17 != nullptr && v21 < RefCount )
          v22 = (_WORD *)((char *)v17 + 2 * v21);
        else
          v22 = nullptr;
        if ( *v22 == 0 )
          v20 = RefCount - 1;
        GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
          this: (GFxZlibSupportBase *)&v31[2],
          a2: v20,
          a3: 1);
        GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
          this: (GFxZlibSupportBase *)&v15[2],
          index: (GetTriangles_Vertex_t *)(v20 + 1),
          a3: 1u);
      }
    }
    ++LOWORD(v15[4].RefCount);
    if ( v24 != nullptr )
      GRefCountImpl::Release(this: v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164270
// Name: protected: class GFxTextParagraph __near * GFxStyledText::AppendNewParagraph(class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::AppendNewParagraph(int a1@<ecx>, SFTextObjectImpl *this, const char *pdefParaFmt)
{
  int v4; // eax
  int *v5; // eax
  unsigned int v6; // ecx
  int v7; // esi
  int v8; // eax
  unsigned int v9; // edx
  _WORD *v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int (__thiscall *v14)(int, int, int *); // edx
  int v15; // eax
  int v16; // ecx
  _DWORD *v17; // esi
  GRefCountNTSImpl *v18; // ecx
  GRefCountNTSImpl *v19; // eax
  int v20; // esi
  unsigned int nextPos; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h] BYREF

  v4 = *(_DWORD *)(a1 + 16);
  nextPos = 0;
  if ( v4 != 0 )
  {
    v5 = *(int **)(*(_DWORD *)(a1 + 12) + 4 * v4 - 4);
    v6 = v5[1];
    v7 = v5[7];
    if ( v6 != 0 )
    {
      v8 = *v5;
      v9 = v6 - 1;
      if ( v8 != 0 && v9 < v6 )
        v10 = (_WORD *)(v8 + 2 * v9);
      else
        v10 = nullptr;
      if ( *v10 == 0 )
        --v6;
    }
    nextPos = v7 + v6;
  }
  GFxStyledText::GetAllocator(this: (SFTextObjectImpl *)a1);
  v12 = v11;
  v13 = *(_DWORD *)(v11 + 28);
  v14 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v13 + 40);
  v22 = 324;
  v15 = v14(a1: v13, a2: 40, a3: &v22);
  if ( v15 != 0 )
  {
    *(_DWORD *)v15 = 0;
    *(_DWORD *)(v15 + 4) = 0;
    *(_DWORD *)(v15 + 8) = 0;
    *(_DWORD *)(v15 + 12) = 0;
    *(_DWORD *)(v15 + 16) = 0;
    *(_DWORD *)(v15 + 20) = 0;
    *(_DWORD *)(v15 + 24) = 0;
    *(_DWORD *)(v15 + 28) = 0;
    *(_WORD *)(v15 + 36) = 0;
    v16 = *(_DWORD *)(v12 + 24);
    *(_DWORD *)(v12 + 24) = v16 + 1;
    *(_DWORD *)(v15 + 32) = v16;
  }
  else
  {
    v15 = 0;
  }
  v22 = v15;
  GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::PushBack(
    this: (GRenderer::CachedData *)(a1 + 12),
    a2: (GRenderer_vtbl **)&v22);
  v17 = (_DWORD *)v22;
  if ( v22 != 0 )
  {
    GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>(this: (_DWORD *)(v22 + 16));
    v18 = (GRefCountNTSImpl *)v17[3];
    if ( v18 != nullptr )
      GRefCountNTSImpl::Release(this: v18);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v17);
  }
  v19 = (GRefCountNTSImpl *)this;
  v20 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * *(_DWORD *)(a1 + 16) - 4);
  if ( this == nullptr )
    v19 = *(GRefCountNTSImpl **)(a1 + 24);
  GFxTextParagraph::SetFormat(this: (GFxFontMap::MapEntry *)v20, pallocator: *(CMaterial **)(a1 + 8), pallocator_4: v19);
  *(_DWORD *)(v20 + 28) = nextPos;
}

//------------------------------------------------------------------------------
// Address: 0x10164380
// Name: protected: class GFxTextParagraph __near * GFxStyledText::AppendCopyOfParagraph(class GFxTextParagraph const __near &)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextParagraph *__thiscall GFxStyledText::AppendCopyOfParagraph(SFTextObjectImpl *this, GFxResourceId *result)
{
  int m_Size; // eax
  int *v4; // eax
  unsigned int v5; // ecx
  int v6; // esi
  int v7; // eax
  unsigned int v8; // edx
  _WORD *v9; // eax
  float v10; // eax
  float v11; // esi
  int v12; // ecx
  int (__thiscall *v13)(int, int, int *); // edx
  GFxResourceId *v14; // eax
  GFxResourceId *v15; // eax
  GFxResourceId *v16; // esi
  GRefCountNTSImpl *Id; // ecx
  struct GFxTextParagraph *v18; // eax
  GRect<float> v19; // [esp-4h] [ebp-18h]
  int v20; // [esp+Ch] [ebp-8h] BYREF
  GFxFontMap *v21; // [esp+10h] [ebp-4h]

  m_Size = this->m_TextBoxes.m_Size;
  v21 = nullptr;
  if ( m_Size != 0 )
  {
    v4 = *(int **)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * m_Size - 4);
    v5 = v4[1];
    v6 = v4[7];
    if ( v5 != 0 )
    {
      v7 = *v4;
      v8 = v5 - 1;
      if ( v7 != 0 && v8 < v5 )
        v9 = (_WORD *)(v7 + 2 * v8);
      else
        v9 = nullptr;
      if ( *v9 == 0 )
        --v5;
    }
    v21 = (GFxFontMap *)(v6 + v5);
  }
  GFxStyledText::GetAllocator(this);
  v11 = v10;
  v12 = *(_DWORD *)(LODWORD(v10) + 28);
  v13 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v12 + 40);
  v20 = 324;
  v14 = (GFxResourceId *)v13(a1: v12, a2: 40, a3: &v20);
  if ( v14 != nullptr )
  {
    v19.Left = v11;
    v15 = GFxTextParagraph::GFxTextParagraph(this: v14, (int)result, o: v19);
  }
  else
  {
    v15 = nullptr;
  }
  result = v15;
  GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::PushBack(
    this: (GRenderer::CachedData *)&this->m_TextBoxes.m_Memory.m_nGrowSize,
    a2: (GRenderer_vtbl **)&result);
  v16 = result;
  if ( result != nullptr )
  {
    GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>(this: &result[4].Id);
    Id = (GRefCountNTSImpl *)v16[3].Id;
    if ( Id != nullptr )
      GRefCountNTSImpl::Release(this: Id);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
  }
  v18 = *(struct GFxTextParagraph **)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * this->m_TextBoxes.m_Size - 4);
  v18[7].pObject = v21;
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x10164450
// Name: protected: class GFxTextParagraph __near * GFxStyledText::InsertNewParagraph(class GArrayBase<struct GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>>::Iterator __near &,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::InsertNewParagraph(SFTextObjectImpl *this, _DWORD *iter, SFTextObjectImpl *a3)
{
  unsigned int v4; // edi
  int *v5; // ecx
  unsigned int v6; // eax
  int v7; // ebx
  int v8; // ecx
  unsigned int v9; // edx
  _WORD *v10; // ecx
  CMaterial *v11; // eax
  IMaterialVar *Paragraph; // ebx
  int m_Size; // eax
  int v14; // edi
  IMaterialVar **v15; // eax
  GRefCountNTSImpl *x_low; // ecx
  GRefCountNTSImpl *v17; // eax
  int v18; // esi
  const char *v19; // [esp+0h] [ebp-Ch]
  unsigned int nextPos; // [esp+14h] [ebp+8h]

  if ( *iter != 0 && ((v4 = iter[1]) & 0x80000000) == 0 && (signed int)v4 < *(_DWORD *)(*iter + 4) )
  {
    nextPos = 0;
    if ( v4 != 0 )
    {
      v5 = *(int **)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v4 - 4);
      v6 = v5[1];
      v7 = v5[7];
      if ( v6 != 0 )
      {
        v8 = *v5;
        v9 = v6 - 1;
        if ( v8 != 0 && v9 < v6 )
          v10 = (_WORD *)(v8 + 2 * v9);
        else
          v10 = nullptr;
        if ( *v10 == 0 )
          --v6;
      }
      nextPos = v7 + v6;
    }
    GFxStyledText::GetAllocator(this);
    Paragraph = GFxTextAllocator::AllocateParagraph(this: v11);
    GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::Resize(
      pheapAddr: (GRenderer::CachedData *)&this->m_TextBoxes.m_Memory.m_nGrowSize,
      newSize: this->m_TextBoxes.m_Size + 1);
    m_Size = this->m_TextBoxes.m_Size;
    if ( v4 < m_Size - 1 )
      memmove(
        dst: (unsigned __int8 *)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v4 + 4),
        src: (unsigned __int8 *)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v4),
        count: 4 * (m_Size - v4) - 4);
    v14 = 4 * v4;
    v15 = (IMaterialVar **)(v14 + this->m_TextBoxes.m_Memory.m_nGrowSize);
    if ( v15 != nullptr )
    {
      *v15 = Paragraph;
    }
    else if ( Paragraph != nullptr )
    {
      GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>(this: &Paragraph->m_VecVal.y);
      x_low = (GRefCountNTSImpl *)LODWORD(Paragraph->m_VecVal.x);
      if ( x_low != nullptr )
        GRefCountNTSImpl::Release(this: x_low);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: Paragraph);
    }
    v17 = (GRefCountNTSImpl *)a3;
    v18 = *(_DWORD *)(v14 + this->m_TextBoxes.m_Memory.m_nGrowSize);
    if ( a3 == nullptr )
      v17 = *((GRefCountNTSImpl **)this + 6);
    GFxTextParagraph::SetFormat(
      this: (GFxFontMap::MapEntry *)v18,
      pallocator: (CMaterial *)this->m_TextBoxes.m_Memory.m_nAllocationCount,
      pallocator_4: v17);
    *(_DWORD *)(v18 + 28) = nextPos;
  }
  else
  {
    GFxStyledText::AppendNewParagraph(a1: (int)this, this: a3, pdefParaFmt: v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164570
// Name: protected: class GFxTextParagraph __near * GFxStyledText::InsertCopyOfParagraph(class GArrayBase<struct GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>>::Iterator __near &,class GFxTextParagraph const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::InsertCopyOfParagraph(
        SFTextObjectImpl *this@<ecx>,
        float a2@<ebx>,
        _DWORD *iter,
        GFxResourceId *result)
{
  unsigned int v5; // edi
  int *v6; // ecx
  unsigned int v7; // eax
  int v8; // ebx
  int v9; // ecx
  unsigned int v10; // edx
  _WORD *v11; // ecx
  float v12; // eax
  float v13; // esi
  int v14; // ecx
  int (__thiscall *v15)(int, int, int *); // edx
  GFxResourceId *v16; // eax
  GFxResourceId *v17; // ebx
  int m_Size; // eax
  int v19; // edi
  GFxResourceId **v20; // eax
  GRefCountNTSImpl *Id; // ecx
  GRect<float> v22; // [esp-8h] [ebp-18h]
  int v24; // [esp+Ch] [ebp-4h] BYREF
  unsigned int nextPos; // [esp+18h] [ebp+8h]

  if ( *iter != 0 && ((v5 = iter[1]) & 0x80000000) == 0 && (signed int)v5 < *(_DWORD *)(*iter + 4) )
  {
    v22.Top = a2;
    nextPos = 0;
    if ( v5 != 0 )
    {
      v6 = *(int **)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v5 - 4);
      v7 = v6[1];
      v8 = v6[7];
      if ( v7 != 0 )
      {
        v9 = *v6;
        v10 = v7 - 1;
        if ( v9 != 0 && v10 < v7 )
          v11 = (_WORD *)(v9 + 2 * v10);
        else
          v11 = nullptr;
        if ( *v11 == 0 )
          --v7;
      }
      nextPos = v8 + v7;
    }
    GFxStyledText::GetAllocator(this);
    v13 = v12;
    v14 = *(_DWORD *)(LODWORD(v12) + 28);
    v15 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v14 + 40);
    v24 = 324;
    v16 = (GFxResourceId *)v15(a1: v14, a2: 40, a3: &v24);
    if ( v16 != nullptr )
    {
      v22.Left = v13;
      v17 = GFxTextParagraph::GFxTextParagraph(this: v16, (int)result, o: v22);
    }
    else
    {
      v17 = nullptr;
    }
    GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::Resize(
      pheapAddr: (GRenderer::CachedData *)&this->m_TextBoxes.m_Memory.m_nGrowSize,
      newSize: this->m_TextBoxes.m_Size + 1);
    m_Size = this->m_TextBoxes.m_Size;
    if ( v5 < m_Size - 1 )
      memmove(
        dst: (unsigned __int8 *)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v5 + 4),
        src: (unsigned __int8 *)(this->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v5),
        count: 4 * (m_Size - v5) - 4);
    v19 = 4 * v5;
    v20 = (GFxResourceId **)(v19 + this->m_TextBoxes.m_Memory.m_nGrowSize);
    if ( v20 != nullptr )
    {
      *v20 = v17;
    }
    else if ( v17 != nullptr )
    {
      GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>(this: &v17[4].Id);
      Id = (GRefCountNTSImpl *)v17[3].Id;
      if ( Id != nullptr )
        GRefCountNTSImpl::Release(this: Id);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v17);
    }
    *(_DWORD *)(*(_DWORD *)(v19 + this->m_TextBoxes.m_Memory.m_nGrowSize) + 28) = nextPos;
  }
  else
  {
    GFxStyledText::AppendCopyOfParagraph(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101646A0
// Name: public: unsigned int GFxStyledText::AppendString(char const __near *,unsigned int,enum GFxStyledText::NewLinePolicy,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxStyledText::AppendString@<eax>(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this@<ecx>,
        const char *a2@<edi>,
        const char *putf8String,
        unsigned int stringSize,
        int a5,
        struct GFxTextFormat *a6,
        SFTextObjectImpl *a7)
{
  unsigned int v7; // eax
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v8; // ebx
  GFxValue *m_pElements; // edi
  int v10; // esi
  int v11; // ecx
  int v12; // edi
  unsigned int v13; // eax
  GetTriangles_Vertex_t *v14; // eax
  int v15; // ecx
  unsigned int v16; // edx
  _WORD *v17; // edx
  unsigned int v18; // edx
  _WORD *v19; // ecx
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  _WORD *v23; // ecx
  int v24; // eax
  int v25; // ebx
  unsigned int Char; // eax
  GFxFontMap *Position; // esi
  GFxFontMap *v28; // ebx
  unsigned int v29; // eax
  int v30; // eax
  struct GFxTextFormat *v31; // esi
  bool v32; // zf
  int result; // eax
  const char *v34; // [esp-4h] [ebp-28h]
  unsigned int i; // [esp+8h] [ebp-1Ch]
  unsigned int posInPara; // [esp+Ch] [ebp-18h]
  unsigned int totalAppenededLen; // [esp+10h] [ebp-14h]
  unsigned int v38; // [esp+14h] [ebp-10h]
  unsigned int curOffset; // [esp+18h] [ebp-Ch]
  const char *v41; // [esp+20h] [ebp-4h]

  v7 = stringSize;
  v8 = this;
  v41 = putf8String;
  if ( stringSize == -1 )
    v7 = strlen(putf8String);
  v34 = a2;
  m_pElements = v8->m_pElements;
  v38 = (unsigned int)&putf8String[v7];
  v10 = 0;
  v11 = (int)&m_pElements[-1].Value.pData + 7;
  totalAppenededLen = 0;
  if ( (int)&m_pElements[-1].Value.pData + 7 < 0 || v11 >= (int)m_pElements )
  {
    v12 = 0;
    curOffset = 0;
    ((void (__thiscall *)(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *, _DWORD, unsigned int, const char *))v8->m_Memory.m_pMemory->Type)(
      a1: v8,
      a2: 0,
      a3: v7,
      a4: putf8String);
  }
  else
  {
    v12 = *(_DWORD *)(v8->m_Size + 4 * v11);
    if ( v12 != 0 )
    {
      curOffset = *(_DWORD *)(v12 + 28);
      ((void (__thiscall *)(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *, unsigned int, unsigned int, const char *))v8->m_Memory.m_pMemory->Type)(
        a1: v8,
        a2: curOffset,
        a3: v7,
        a4: putf8String);
    }
    else
    {
      curOffset = 0;
      ((void (__thiscall *)(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *, _DWORD, unsigned int, const char *))v8->m_Memory.m_pMemory->Type)(
        a1: v8,
        a2: 0,
        a3: v7,
        a4: putf8String);
    }
  }
  v13 = 0;
  while ( 1 )
  {
    i = v13 + 1;
    if ( v13 != 0 || v12 == 0 )
    {
      GFxStyledText::AppendNewParagraph(a1: (int)v8, this: a7, pdefParaFmt: v34);
      v12 = v24;
      posInPara = 0;
      *(_DWORD *)(v24 + 28) = curOffset;
    }
    else
    {
      v14 = *(GetTriangles_Vertex_t **)(v12 + 4);
      if ( v14 != nullptr )
      {
        v15 = *(_DWORD *)v12;
        v16 = (unsigned int)&v14[-1].m_NumBones + 3;
        if ( *(_DWORD *)v12 != 0 && v16 < (unsigned int)v14 )
          v17 = (_WORD *)(v15 + 2 * v16);
        else
          v17 = nullptr;
        if ( *v17 == 0 )
        {
          v18 = (unsigned int)&v14[-1].m_NumBones + 3;
          if ( v15 != 0 && v18 < (unsigned int)v14 )
            v19 = (_WORD *)(v15 + 2 * v18);
          else
            v19 = nullptr;
          if ( *v19 == 0 )
            v14 = (GetTriangles_Vertex_t *)((char *)v14 - 1);
          GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
            this: (GFxZlibSupportBase *)(v12 + 16),
            index: v14,
            a3: 1u);
          v20 = *(_DWORD *)(v12 + 4);
          if ( v20 != 0 && *(_WORD *)(*(_DWORD *)v12 + 2 * v20 - 2) == 0 )
            *(_DWORD *)(v12 + 4) = v20 - 1;
        }
      }
      v21 = *(_DWORD *)(v12 + 4);
      if ( v21 != 0 )
      {
        v22 = v21 - 1;
        if ( *(_DWORD *)v12 != 0 && v22 < v21 )
          v23 = (_WORD *)(*(_DWORD *)v12 + 2 * v22);
        else
          v23 = nullptr;
        if ( *v23 == 0 )
          --v21;
      }
      posInPara = v21;
    }
    stringSize = v10;
    v25 = 0;
    v10 = -1;
    putf8String = v41;
    if ( (unsigned int)v41 >= v38 )
      break;
    while ( v10 != 0 )
    {
      Char = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8String);
      if ( a5 != 0 || stringSize != 13 || v25 != 0 || (stringSize = -1, Char != 10) )
      {
        v10 = Char;
        if ( Char == 10 )
          goto LABEL_50;
        if ( Char == 13 )
          break;
        ++v25;
      }
      else
      {
        ++v41;
      }
      if ( (unsigned int)putf8String >= v38 )
        break;
    }
    stringSize = v25;
    if ( v10 == 10 || v10 == 13 )
LABEL_50:
      stringSize = ++v25;
    if ( v25 != 0 )
    {
      Position = GFxTextParagraph::TextBuffer::CreatePosition(
                   this: (int *)v12,
                   result: (GFxFontMap *)this->m_Memory.m_nGrowSize,
                   a3: posInPara,
                   length: v25);
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
        this: (GFxZlibSupportBase *)(v12 + 16),
        a2: posInPara,
        a3: v25);
      ++*(_WORD *)(v12 + 36);
      v28 = Position;
      v10 = -1;
      putf8String = v41;
      while ( (unsigned int)putf8String < v38 )
      {
        if ( v10 == 0 )
          break;
        v29 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8String);
        v10 = v29;
        if ( v29 == 13 || v29 == 10 )
          v10 = (*((_BYTE *)this + 32) & 2) != 0 ? 13 : 10;
        LOWORD(v28->__vftable) = v10;
        v28 = (GFxFontMap *)((char *)v28 + 2);
        if ( v10 == ((*((_BYTE *)this + 32) & 2) != 0 ? 13 : 10) )
          break;
      }
      GFxTextParagraph::SetTextFormat(
        this: v12,
        pallocator: (CMaterial *)this->m_Memory.m_nGrowSize,
        fmt_4: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)a6,
        startPos: posInPara,
        length: 0xFFFFFFFF);
      curOffset += stringSize + posInPara;
      totalAppenededLen += stringSize;
      v41 = putf8String;
    }
    if ( (unsigned int)v41 >= v38 || v10 == 0 )
      break;
    v13 = i;
    v8 = this;
  }
  if ( v10 == ((*((_BYTE *)this + 32) & 2) != 0 ? 13 : 10) )
  {
    GFxStyledText::AppendNewParagraph(a1: (int)this, this: a7, pdefParaFmt: v34);
    v12 = v30;
  }
  v31 = a6;
  GFxTextParagraph::AppendTermNull(
    this: (GFxTextParagraph *)v12,
    result: (GFxFontMap *)this->m_Memory.m_nGrowSize,
    a3: a6);
  if ( (*((_WORD *)v31 + 21) & 0x100) == 0 )
    return totalAppenededLen;
  v32 = GString::GetLength(this: (GString *)v31 + 4) == 0;
  result = totalAppenededLen;
  if ( !v32 )
    *((_BYTE *)this + 32) |= 1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10164970
// Name: public: unsigned int GFxStyledText::AppendString(wchar_t const __near *,unsigned int,enum GFxStyledText::NewLinePolicy,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStyledText::AppendString(
        _DWORD *this,
        wchar_t *pwch,
        unsigned int a3,
        int a4,
        struct GFxTextFormat *a5,
        SFTextObjectImpl *a6)
{
  unsigned int v6; // edx
  int v7; // edi
  int v9; // ecx
  int v10; // eax
  int *v11; // esi
  int v12; // eax
  GetTriangles_Vertex_t *v13; // eax
  int v14; // ecx
  unsigned int v15; // edx
  _WORD *v16; // edx
  unsigned int v17; // edx
  _WORD *v18; // ecx
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // edx
  _WORD *v22; // ecx
  unsigned int v23; // ebx
  int *v24; // eax
  int v25; // eax
  unsigned __int8 *v26; // eax
  int v27; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  unsigned int v31; // eax
  int v32; // ecx
  int v33; // edx
  unsigned __int8 *v34; // ebx
  unsigned int v35; // ecx
  unsigned int v36; // ebx
  _WORD *v37; // edx
  unsigned int v38; // ebx
  int v39; // ebx
  int *v40; // eax
  bool v41; // zf
  int result; // eax
  const char *v43; // [esp+0h] [ebp-2Ch]
  wchar_t *v44; // [esp+Ch] [ebp-20h]
  int v45; // [esp+10h] [ebp-1Ch] BYREF
  int v46; // [esp+14h] [ebp-18h]
  int v47; // [esp+18h] [ebp-14h]
  int v48; // [esp+1Ch] [ebp-10h]
  unsigned int v49; // [esp+20h] [ebp-Ch]
  _DWORD *v50; // [esp+24h] [ebp-8h]
  int v51; // [esp+28h] [ebp-4h]

  v6 = a3;
  v7 = 0;
  v50 = this;
  v51 = 0;
  if ( a3 == -1 )
  {
    a3 = G_wcslen(pwch);
    v6 = a3;
  }
  v9 = *(this + 4);
  v44 = &pwch[v6];
  v10 = v9 - 1;
  if ( v9 - 1 < 0 || v10 >= v9 )
  {
    v11 = nullptr;
    v48 = 0;
  }
  else
  {
    v11 = *(int **)(*(this + 3) + 4 * v10);
    if ( v11 != nullptr )
      v48 = v11[7];
    else
      v48 = 0;
  }
  (*(void (__thiscall **)(_DWORD *, int, unsigned int, wchar_t *))(*v50 + 8))(a1: v50, a2: v48, a3: v6, a4: pwch);
  v47 = 0;
  v12 = 0;
  while ( 1 )
  {
    v46 = v12 + 1;
    if ( v12 != 0 || v11 == nullptr )
    {
      GFxStyledText::AppendNewParagraph(a1: (int)v50, this: a6, pdefParaFmt: v43);
      v11 = v24;
      v49 = 0;
      v24[7] = v48;
      v23 = 0;
    }
    else
    {
      v13 = (GetTriangles_Vertex_t *)v11[1];
      if ( v13 != nullptr )
      {
        v14 = *v11;
        v15 = (unsigned int)&v13[-1].m_NumBones + 3;
        if ( *v11 != 0 && v15 < (unsigned int)v13 )
          v16 = (_WORD *)(v14 + 2 * v15);
        else
          v16 = nullptr;
        if ( *v16 == 0 )
        {
          v17 = (unsigned int)&v13[-1].m_NumBones + 3;
          if ( v14 != 0 && v17 < (unsigned int)v13 )
            v18 = (_WORD *)(v14 + 2 * v17);
          else
            v18 = nullptr;
          if ( *v18 == 0 )
            v13 = (GetTriangles_Vertex_t *)((char *)v13 - 1);
          GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
            this: (GFxZlibSupportBase *)(v11 + 4),
            index: v13,
            a3: 1u);
          v19 = v11[1];
          if ( v19 != 0 && *(_WORD *)(*v11 + 2 * v19 - 2) == 0 )
            v11[1] = v19 - 1;
        }
      }
      v20 = v11[1];
      if ( v20 != 0 )
      {
        v21 = v20 - 1;
        if ( *v11 != 0 && v21 < v20 )
          v22 = (_WORD *)(*v11 + 2 * v21);
        else
          v22 = nullptr;
        if ( *v22 == 0 )
          --v20;
      }
      v23 = v20;
      v49 = v20;
      if ( v20 == 0 && a6 != nullptr )
        GFxTextParagraph::SetFormat(
          this: (GFxFontMap::MapEntry *)v11,
          pallocator: (CMaterial *)v50[2],
          pallocator_4: (GRefCountNTSImpl *)a6);
    }
    if ( a4 == 0 && v51 == 13 && *pwch == 10 )
    {
      ++pwch;
      if ( --a3 == 0 )
        break;
    }
    if ( a3 != 0 )
    {
      while ( 1 )
      {
        v25 = pwch[v7];
        v51 = v25;
        if ( v25 == 10 )
          break;
        if ( v25 != 13 && v25 != 0 && ++v7 < a3 )
          continue;
        goto LABEL_48;
      }
LABEL_50:
      ++v7;
      goto LABEL_51;
    }
LABEL_48:
    if ( v51 == 10 || v51 == 13 )
      goto LABEL_50;
LABEL_51:
    if ( v7 != 0 )
    {
      v27 = v11[1];
      if ( v11[2] < (unsigned int)(v27 + v7) )
      {
        v28 = 2 * (v27 + v7);
        if ( *v11 != 0 )
        {
          v30 = ((int (__stdcall *)(int, int))GMemory::pGlobalHeap->Realloc)(a1: *v11, a2: v28);
        }
        else
        {
          v29 = *(_DWORD *)(v50[2] + 28);
          v45 = 324;
          v30 = (*(int (__stdcall **)(int, int *))(*(_DWORD *)v29 + 40))(a1: v28, a2: &v45);
        }
        v23 = v49;
        *v11 = v30;
        v27 = v11[1];
        v11[2] = v27 + v7;
      }
      v31 = v27 - v23;
      if ( v31 != 0 )
        memmove(
          dst: (unsigned __int8 *)(*v11 + 2 * (v7 + v23)),
          src: (unsigned __int8 *)(*v11 + 2 * v23),
          count: 2 * v31);
      v32 = *v11;
      v33 = v49;
      v11[1] += v7;
      v34 = (unsigned __int8 *)(v32 + 2 * v23);
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
        this: (GFxZlibSupportBase *)(v11 + 4),
        a2: v33,
        a3: v7);
      ++*((_WORD *)v11 + 18);
      v26 = v34;
    }
    else
    {
      v26 = nullptr;
    }
    memcpy(dst: v26, src: (unsigned __int8 *)pwch, count: 2 * v7);
    pwch += v7;
    a3 -= v7;
    if ( (v51 == 10 || v51 == 13) && v51 != ((v50[8] & 2) != 0 ? 13 : 10) )
    {
      v35 = v11[1];
      if ( v35 != 0 )
      {
        v36 = v35 - 1;
        if ( *v11 != 0 && v36 < v35 )
          v37 = (_WORD *)(*v11 + 2 * v36);
        else
          v37 = nullptr;
        if ( *v37 == 0 )
          --v35;
        if ( v35 != 0 )
          *(_WORD *)(*v11 + 2 * v35 - 2) = (unsigned __int8)((v50[8] & 2) != 0 ? 13 : 10);
      }
      v51 = (v50[8] & 2) != 0 ? 13 : 10;
    }
    v38 = v49;
    GFxTextParagraph::SetTextFormat(
      this: (int)v11,
      pallocator: (CMaterial *)v50[2],
      fmt_4: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)a5,
      startPos: v49,
      length: 0xFFFFFFFF);
    v47 += v7;
    v48 += v7 + v38;
    if ( pwch >= v44 || v51 == 0 )
      break;
    v12 = v46;
    v7 = 0;
  }
  v39 = (int)v50;
  if ( v51 == ((v50[8] & 2) != 0 ? 13 : 10) )
  {
    GFxStyledText::AppendNewParagraph(a1: (int)v50, this: a6, pdefParaFmt: v43);
    v11 = v40;
  }
  GFxTextParagraph::AppendTermNull(this: (GFxTextParagraph *)v11, result: *(GFxFontMap **)(v39 + 8), a3: a5);
  if ( (*((_WORD *)a5 + 21) & 0x100) == 0 )
    return v47;
  v41 = GString::GetLength(this: (GString *)a5 + 4) == 0;
  result = v47;
  if ( !v41 )
    *(_BYTE *)(v39 + 32) |= 1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10164CD0
// Name: private: void GFxStyledText::EnsureTermNull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::EnsureTermNull(int this)
{
  int v2; // ecx
  int v3; // eax
  GFxTextParagraph *v4; // eax
  GFxFontMap *pObject; // ecx
  char *v6; // esi
  unsigned __int16 *v7; // ecx
  int v8; // ecx
  const char *v9; // [esp+0h] [ebp-4h]

  v2 = *(_DWORD *)(this + 16);
  v3 = v2 - 1;
  if ( v2 - 1 >= 0 && v3 < v2 && (v4 = *(GFxTextParagraph **)(*(_DWORD *)(this + 12) + 4 * v3)) != nullptr
    || (GFxStyledText::AppendNewParagraph(a1: this, this: nullptr, pdefParaFmt: v9), v4 != nullptr) )
  {
    pObject = v4[1].pObject;
    if ( pObject == nullptr
      || ((v6 = (char *)&pObject[-1].pImpl + 3, v4->pObject == nullptr) || v6 >= (char *)pObject
        ? (v7 = nullptr)
        : (v7 = (unsigned __int16 *)v4->pObject + (_DWORD)v6),
          (v8 = *v7) != 13 && v8 != 10) )
    {
      GFxTextParagraph::AppendTermNull(
        this: v4,
        result: *(GFxFontMap **)(this + 8),
        a3: *(const struct GFxTextFormat **)(this + 28));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164D40
// Name: public: unsigned int GFxStyledText::InsertString(wchar_t const __near *,unsigned int,unsigned int,enum GFxStyledText::NewLinePolicy,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__userpurge GFxStyledText::InsertString@<eax>(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this@<ecx>,
        const char *a2@<ebx>,
        GFxValue *pstr,
        unsigned int indexInPara,
        unsigned int insLineLen,
        int a6,
        IShaderDevice *a7,
        SFTextObjectImpl *a8)
{
  unsigned int v8; // esi
  unsigned int Length; // eax
  unsigned int v12; // ebx
  int v13; // eax
  GFxValue::ObjectInterface *pObjectInterface; // eax
  GFxValue::ValueType Type; // ecx
  SFTextObjectImpl *v16; // ebx
  int v17; // esi
  unsigned int v18; // eax
  unsigned int v19; // edx
  _WORD *v20; // ecx
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v21; // ecx
  CMaterial *m_nAllocationCount; // edi
  GRefCountNTSImpl *v23; // eax
  GRefCountNTSImpl *ParagraphFormat; // edi
  GRefCountNTSImpl *v25; // ecx
  int v26; // eax
  unsigned int v27; // ecx
  int v28; // edi
  int v29; // eax
  int v30; // ebx
  int v31; // edi
  GRefCountNTSImpl *v32; // ecx
  unsigned int v33; // eax
  SFTextObjectImpl *v34; // edx
  unsigned int v35; // edi
  unsigned int v36; // eax
  unsigned int v37; // ecx
  GetTriangles_Vertex_t *v38; // edi
  unsigned int v39; // ebx
  unsigned int v40; // eax
  struct GFxTextParagraph v41; // ecx
  unsigned int v42; // edx
  _WORD *v43; // edx
  int v44; // ebx
  unsigned int v45; // edx
  _WORD *v46; // eax
  __int16 v47; // dx
  __int16 v48; // cx
  unsigned int v49; // eax
  const GFxValue *v50; // ecx
  int v51; // eax
  int v52; // edx
  GFxValue::ObjectInterface *v53; // esi
  GFxValue::ValueType v54; // eax
  int v55; // ecx
  SFTextObjectImpl *v56; // edi
  int v57; // eax
  GFxTextParagraph *v58; // eax
  GFxFontMap *pObject; // ecx
  char *v60; // esi
  unsigned __int16 *v61; // ecx
  int v62; // ecx
  const char *v63; // [esp-4h] [ebp-48h]
  const char *v64; // [esp+0h] [ebp-44h]
  ImageFormat v65; // [esp+4h] [ebp-40h]
  IShaderAPI v66; // [esp+8h] [ebp-3Ch] BYREF
  int iter; // [esp+20h] [ebp-24h] BYREF
  GFxValue::ValueType v68; // [esp+24h] [ebp-20h]
  GFxValue index; // [esp+28h] [ebp-1Ch] BYREF
  int uniChar; // [esp+38h] [ebp-Ch]
  unsigned int remainingSrcStrLen; // [esp+3Ch] [ebp-8h]
  SFTextObjectImpl *v72; // [esp+40h] [ebp-4h]

  v8 = insLineLen;
  v72 = (SFTextObjectImpl *)this;
  if ( insLineLen == 0 )
    return nullptr;
  v63 = a2;
  Length = GFxStyledText::GetLength((GFxStyledText *)this);
  v12 = indexInPara;
  if ( indexInPara > Length )
    v12 = GFxStyledText::GetLength((GFxStyledText *)this);
  if ( v8 == -1 )
  {
    v8 = 0;
    if ( LOWORD(pstr->pObjectInterface) != 0 )
    {
      do
        ++v8;
      while ( *((_WORD *)&pstr->pObjectInterface + v8) != 0 );
    }
  }
  ((void (__thiscall *)(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *, unsigned int, unsigned int, GFxValue *))this->m_Memory.m_pMemory->Value.pString)(
    a1: this,
    a2: v12,
    a3: v8,
    a4: pstr);
  indexInPara = 0;
  remainingSrcStrLen = v8;
  GFxStyledText::GetNearestParagraphByIndex(
    (SFTextObjectImpl *)this,
    &index,
    indexa: v12,
    pindexInParagraph: &indexInPara);
  if ( index.pObjectInterface != nullptr
    && index.Type >= VT_Undefined
    && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
  {
    v13 = *(_DWORD *)(*((_DWORD *)index.pObjectInterface->pMovieRoot + index.Type) + 28);
  }
  else
  {
    v13 = 0;
  }
  *((_DWORD *)&index.Value.pStringManaged + 1) = v13;
  uniChar = 0;
  index.Value.pString = nullptr;
  do
  {
    pObjectInterface = index.pObjectInterface;
    if ( index.pObjectInterface != nullptr
      && (Type = index.Type, index.Type >= VT_Undefined)
      && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
    {
      v16 = v72;
    }
    else
    {
      v16 = v72;
      GFxStyledText::AppendNewParagraph(a1: (int)v72, this: a8, pdefParaFmt: v63);
      Type = VT_Undefined;
      pObjectInterface = (GFxValue::ObjectInterface *)&v16->m_TextBoxes.m_Memory.m_nGrowSize;
      index.pObjectInterface = (GFxValue::ObjectInterface *)&v16->m_TextBoxes.m_Memory.m_nGrowSize;
      index.Type = VT_Undefined;
      indexInPara = 0;
    }
    v17 = *((_DWORD *)pObjectInterface->pMovieRoot + Type);
    v18 = *(_DWORD *)(v17 + 4);
    if ( v18 == 0 )
      goto LABEL_27;
    v19 = v18 - 1;
    if ( *(_DWORD *)v17 != 0 && v19 < v18 )
      v20 = (_WORD *)(*(_DWORD *)v17 + 2 * v19);
    else
      v20 = nullptr;
    if ( *v20 == 0 )
      --v18;
    if ( v18 == 0 )
    {
LABEL_27:
      v21 = *(CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v17 + 12);
      m_nAllocationCount = (CMaterial *)v16->m_TextBoxes.m_Memory.m_nAllocationCount;
      if ( v21 != nullptr )
      {
        GFxTextParagraphFormat::Merge(this: v21, a2: (GFxTextParagraphFormat *)&v66, a3: (int)a8);
        ParagraphFormat = (GRefCountNTSImpl *)GFxTextAllocator::AllocateParagraphFormat(
                                                this: m_nAllocationCount,
                                                srcfmt: v23,
                                                pfmt: (int)v63,
                                                a4: (int)v64,
                                                a5: v65);
        v66.__vftable = (IShaderAPI_vtbl *)&GFxTextParagraphFormat::`vftable';
        GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v66);
        GRefCountImplCore::~GRefCountImplCore(this: &v66);
      }
      else
      {
        ParagraphFormat = (GRefCountNTSImpl *)GFxTextAllocator::AllocateParagraphFormat(
                                                this: m_nAllocationCount,
                                                srcfmt: (GRefCountNTSImpl *)a8,
                                                pfmt: (int)v63,
                                                a4: (int)v64,
                                                a5: v65);
      }
      if ( ParagraphFormat != nullptr )
        ++ParagraphFormat->RefCount;
      v25 = *(GRefCountNTSImpl **)(v17 + 12);
      if ( v25 != nullptr )
        GRefCountNTSImpl::Release(this: v25);
      *(_DWORD *)(v17 + 12) = ParagraphFormat;
      ++*(_WORD *)(v17 + 36);
      if ( ParagraphFormat != nullptr )
        GRefCountNTSImpl::Release(this: ParagraphFormat);
    }
    LOWORD(v26) = uniChar;
    v27 = 0;
    v28 = -1;
    insLineLen = 0;
    if ( a6 == 0 && (_WORD)uniChar == 13 && LOWORD(pstr->pObjectInterface) == 10 )
    {
      pstr = (GFxValue *)((char *)pstr + 2);
      if ( --remainingSrcStrLen == 0 )
        break;
      v16 = v72;
    }
    if ( remainingSrcStrLen != 0 )
    {
      while ( 1 )
      {
        v26 = *((unsigned __int16 *)&pstr->pObjectInterface + v27);
        uniChar = v26;
        if ( v26 == 10 || v26 == 13 )
        {
          v28 = v27;
LABEL_48:
          insLineLen = v27;
          goto LABEL_49;
        }
        if ( (_WORD)v26 == 0 )
          break;
        if ( ++v27 >= remainingSrcStrLen )
          goto LABEL_48;
      }
      insLineLen = v27;
LABEL_85:
      GFxTextParagraph::InsertString(
        this: v17,
        pos: (GFxFontMap *)v16->m_TextBoxes.m_Memory.m_nAllocationCount,
        src: (unsigned __int8 *)pstr,
        index: (GRefCountBaseStatImpl<GRefCountNTSImpl,326> *)indexInPara,
        length: v27,
        a6: a7);
      goto LABEL_86;
    }
LABEL_49:
    if ( (_WORD)v26 == 10 || (_WORD)v26 == 13 )
      insLineLen = ++v27;
    if ( v28 == -1 )
      goto LABEL_85;
    iter = (int)index.pObjectInterface;
    v68 = index.Type;
    if ( index.Type < (int)index.pObjectInterface[1].pMovieRoot )
      v68 = index.Type + 1;
    GFxStyledText::InsertNewParagraph(this: v72, &iter, a3: a8);
    v30 = *(_DWORD *)(v17 + 12);
    v31 = v29;
    if ( v30 != 0 )
      ++*(_DWORD *)(v30 + 4);
    v32 = *(GRefCountNTSImpl **)(v29 + 12);
    if ( v32 != nullptr )
      GRefCountNTSImpl::Release(this: v32);
    v33 = indexInPara;
    v34 = v72;
    *(_DWORD *)(v31 + 12) = v30;
    ++*(_WORD *)(v31 + 36);
    GFxTextParagraph::Copy(
      this: (GFxTextParagraph *)v31,
      a2: (CMaterial *)v34->m_TextBoxes.m_Memory.m_nAllocationCount,
      a3: (const struct GFxTextParagraph *)v17,
      a4: v33,
      a5: 0,
      a6: *(_DWORD *)(v17 + 4) - v33);
    v35 = *(_DWORD *)(v17 + 4) - indexInPara;
    GFxTextParagraph::InsertString(
      this: v17,
      pos: (GFxFontMap *)v72->m_TextBoxes.m_Memory.m_nAllocationCount,
      src: (unsigned __int8 *)pstr,
      index: (GRefCountBaseStatImpl<GRefCountNTSImpl,326> *)indexInPara,
      length: insLineLen,
      a6: a7);
    if ( v35 != 0 )
    {
      v36 = *(_DWORD *)(v17 + 4);
      v37 = v35;
      if ( v35 >= v36 )
        v37 = *(_DWORD *)(v17 + 4);
      v38 = (GetTriangles_Vertex_t *)(v36 - v37);
      if ( v36 == -1 )
      {
        v39 = -1;
      }
      else
      {
        v39 = v37;
        if ( (GetTriangles_Vertex_t *)v36 == v38 )
          goto LABEL_86;
      }
      if ( (unsigned int)v38 < v36 )
      {
        if ( (unsigned int)v38 + v39 < v36 )
        {
          memmove(
            dst: (unsigned __int8 *)(*(_DWORD *)v17 + 2 * (v36 - v37)),
            src: (unsigned __int8 *)(*(_DWORD *)v17 + 2 * ((_DWORD)v38 + v39)),
            count: 2 * (v37 - v39));
          *(_DWORD *)(v17 + 4) -= v39;
        }
        else
        {
          *(_DWORD *)(v17 + 4) = v38;
        }
      }
      GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
        this: (GFxZlibSupportBase *)(v17 + 16),
        index: v38,
        a3: v39);
      v40 = *(_DWORD *)(v17 + 4);
      if ( v40 != 0 )
      {
        v41.pObject = *(GFxFontMap **)v17;
        v42 = v40 - 1;
        if ( *(_DWORD *)v17 != 0 && v42 < v40 )
          v43 = (_WORD *)v41.pObject + v42;
        else
          v43 = nullptr;
        if ( *v43 == 0 )
        {
          v44 = *(_DWORD *)(v17 + 4);
          v45 = v40 - 1;
          if ( v41.pObject != nullptr && v45 < v40 )
            v46 = (_WORD *)v41.pObject + v45;
          else
            v46 = nullptr;
          if ( *v46 == 0 )
            --v44;
          GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::ExpandRange(
            this: (GFxZlibSupportBase *)(v17 + 16),
            a2: v44,
            a3: 1);
          GRangeDataArray<GPtr<GFxTextFormat>,GArrayLH<GRangeData<GPtr<GFxTextFormat>>,2,GArrayDefaultPolicy>>::RemoveRange(
            this: (GFxZlibSupportBase *)(v17 + 16),
            index: (GetTriangles_Vertex_t *)(v44 + 1),
            a3: 1u);
        }
      }
      ++*(_WORD *)(v17 + 36);
    }
LABEL_86:
    v47 = uniChar;
    if ( ((_WORD)uniChar == 13 || (_WORD)uniChar == 10)
      && (v48 = (unsigned __int8)((v72[1].m_TextBoxes.m_Memory.m_nAllocationCount & 2) != 0 ? 13 : 10),
          (_WORD)uniChar != v48) )
    {
      v49 = insLineLen;
      *(_WORD *)(*(_DWORD *)v17 + 2 * (insLineLen + indexInPara) - 2) = v48;
    }
    else
    {
      v49 = insLineLen;
    }
    remainingSrcStrLen -= v49;
    index.Value.pString += v49;
    v50 = (GFxValue *)((char *)pstr + 2 * v49);
    v51 = *((_DWORD *)&index.Value.pStringManaged + 1);
    *(_DWORD *)(v17 + 28) = *((_DWORD *)&index.Value.pStringManaged + 1);
    pstr = (GFxValue *)v50;
    *((_DWORD *)&index.Value.pStringManaged + 1) = *(_DWORD *)(v17 + 4) + v51;
    indexInPara = 0;
    if ( index.Type < (int)index.pObjectInterface[1].pMovieRoot )
      ++index.Type;
  }
  while ( remainingSrcStrLen != 0 && v47 != 0 );
  v52 = *((_DWORD *)&index.Value.pStringManaged + 1);
  v53 = index.pObjectInterface;
  v54 = index.Type;
  while ( v54 >= VT_Undefined && v54 < (int)v53[1].pMovieRoot )
  {
    v55 = *((_DWORD *)v53->pMovieRoot + v54);
    *(_DWORD *)(v55 + 28) = v52;
    v52 += *(_DWORD *)(v55 + 4);
    if ( v54 < (int)v53[1].pMovieRoot )
      ++v54;
  }
  v56 = v72;
  v57 = v72->m_TextBoxes.m_Size - 1;
  if ( v72 != (SFTextObjectImpl *)-12
    && v57 >= 0
    && v57 < v72->m_TextBoxes.m_Size
    && (v58 = *(GFxTextParagraph **)(v72->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v57)) != nullptr
    || (GFxStyledText::AppendNewParagraph(a1: (int)v72, this: nullptr, pdefParaFmt: v64), v58 != nullptr) )
  {
    pObject = v58[1].pObject;
    if ( pObject == nullptr
      || ((v60 = (char *)&pObject[-1].pImpl + 3, v58->pObject == nullptr) || v60 >= (char *)pObject
        ? (v61 = nullptr)
        : (v61 = (unsigned __int16 *)v58->pObject + (_DWORD)v60),
          (v62 = *v61) != 13 && v62 != 10) )
    {
      GFxTextParagraph::AppendTermNull(
        this: v58,
        result: (GFxFontMap *)v56->m_TextBoxes.m_Memory.m_nAllocationCount,
        a3: (const struct GFxTextFormat *)v56[1].m_TextBoxes.m_Memory.m_pMemory);
    }
  }
  if ( (HIWORD(a7[10].__vftable) & 0x100) != 0 && GString::GetLength(this: (GString *)&a7[4]) != 0 )
    LOBYTE(v56[1].m_TextBoxes.m_Memory.m_nAllocationCount) |= 1u;
  return index.Value.pString;
}

//------------------------------------------------------------------------------
// Address: 0x101651C0
// Name: public: unsigned int GFxStyledText::InsertStyledText(class GFxStyledText const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxStyledText::InsertStyledText@<eax>(
        SFTextObjectImpl *this@<ecx>,
        const char *a2@<edi>,
        GFxStyledText *a3,
        const char *a4,
        unsigned int a5)
{
  unsigned int Length; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edi
  int *pObjectInterface; // edi
  GFxValue::ValueType Type; // eax
  unsigned int v11; // ebx
  const char *v12; // eax
  bool v13; // zf
  int v14; // ecx
  int v15; // esi
  volatile unsigned int v16; // eax
  volatile unsigned int v17; // edx
  _WORD *v18; // ecx
  struct GFxMovieRoot *pMovieRoot; // eax
  int v20; // esi
  SFTextObjectImpl *v21; // edi
  GFxTextParagraph *v22; // eax
  int *v23; // ecx
  int v24; // edi
  volatile unsigned int v25; // eax
  volatile unsigned int v26; // edx
  _WORD *v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // edx
  _WORD *v30; // ecx
  unsigned int v31; // eax
  GFxTextParagraph v32; // esi
  unsigned int v33; // ecx
  _WORD *v34; // esi
  int v35; // eax
  int v36; // edi
  volatile unsigned int v37; // esi
  unsigned int v38; // ecx
  _WORD *v39; // eax
  SFTextObjectImpl *v40; // ebx
  GFxFontMap::MapEntry *v41; // esi
  int *v42; // ecx
  unsigned int v43; // eax
  int v44; // ecx
  unsigned int v45; // edx
  _WORD *v46; // ecx
  GFxValue::ObjectInterface *v47; // esi
  GFxValue::ValueType v48; // edx
  const char *v49; // ecx
  int v50; // eax
  int v51; // eax
  GFxTextParagraph *v52; // eax
  GFxFontMap *pObject; // ecx
  char *v54; // esi
  unsigned __int16 *v55; // ecx
  int v56; // ecx
  CMaterial *m_nAllocationCount; // [esp-18h] [ebp-44h]
  volatile unsigned int v59; // [esp-8h] [ebp-34h]
  volatile unsigned int v60; // [esp-8h] [ebp-34h]
  const char *v62; // [esp+0h] [ebp-2Ch]
  int v63; // [esp+Ch] [ebp-20h]
  GFxValue index; // [esp+10h] [ebp-1Ch] BYREF
  GFxFontMap::MapEntry *delta; // [esp+20h] [ebp-Ch]
  GFxFontMap::MapEntry *v66; // [esp+24h] [ebp-8h]
  SFTextObjectImpl *v67; // [esp+28h] [ebp-4h]

  v67 = this;
  Length = GFxStyledText::GetLength(this: a3);
  v7 = a5;
  if ( a5 == -1 || a5 > Length )
  {
    v7 = Length;
    a5 = Length;
  }
  if ( v7 == 0 || *((_DWORD *)a3 + 4) == 0 )
    return 0;
  v8 = (unsigned int)a4;
  this->SetText_2(this, a2: a4, v7, &pMem);
  a4 = nullptr;
  GFxStyledText::GetNearestParagraphByIndex(this, &index, indexa: v8, pindexInParagraph: (unsigned int *)&a4);
  pObjectInterface = (int *)index.pObjectInterface;
  if ( index.pObjectInterface != nullptr
    && (Type = index.Type, index.Type >= VT_Undefined)
    && index.Type < (int)index.pObjectInterface[1].pMovieRoot )
  {
    v11 = (unsigned int)a4;
  }
  else
  {
    GFxStyledText::AppendNewParagraph(a1: (int)this, this: nullptr, pdefParaFmt: a2);
    pObjectInterface = &this->m_TextBoxes.m_Memory.m_nGrowSize;
    Type = VT_Undefined;
    index.pObjectInterface = (GFxValue::ObjectInterface *)&this->m_TextBoxes.m_Memory.m_nGrowSize;
    index.Type = VT_Undefined;
    v11 = 0;
  }
  if ( pObjectInterface != nullptr && Type >= VT_Undefined && Type < pObjectInterface[1] )
    v12 = *(const char **)(*(_DWORD *)(*pObjectInterface + 4 * Type) + 28);
  else
    v12 = nullptr;
  v13 = *((_DWORD *)a3 + 4) == 1;
  v14 = *pObjectInterface;
  a4 = v12;
  if ( v13 )
  {
    v15 = **((_DWORD **)a3 + 3);
    v66 = *(GFxFontMap::MapEntry **)(v14 + 4 * index.Type);
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 != 0 )
    {
      v17 = v16 - 1;
      if ( *(_DWORD *)v15 != 0 && v17 < v16 )
        v18 = (_WORD *)(*(_DWORD *)v15 + 2 * v17);
      else
        v18 = nullptr;
      if ( *v18 == 0 )
        --v16;
    }
    GFxTextParagraph::Copy(
      this: (GFxTextParagraph *)v66,
      a2: (CMaterial *)v67->m_TextBoxes.m_Memory.m_nAllocationCount,
      a3: (const struct GFxTextParagraph *)v15,
      a4: 0,
      a5: v11,
      a6: v16);
    if ( v11 == 0 )
      GFxTextParagraph::SetFormat(
        this: v66,
        pallocator: (CMaterial *)v67->m_TextBoxes.m_Memory.m_nAllocationCount,
        pallocator_4: *(GRefCountNTSImpl **)(v15 + 12));
    a4 += LODWORD(v66->ScaleFactor);
    pMovieRoot = (struct GFxMovieRoot *)pObjectInterface[1];
  }
  else
  {
    v20 = *(_DWORD *)(v14 + 4 * index.Type);
    v63 = 0;
    *(_QWORD *)&index.Value.NValue = __PAIR64__(index.Type, (unsigned int)pObjectInterface);
    if ( index.Type < pObjectInterface[1] )
      *((_DWORD *)&index.Value.pStringManaged + 1) = index.Type + 1;
    v21 = v67;
    GFxStyledText::InsertNewParagraph(this: v67, iter: &index.Value, a3: *(SFTextObjectImpl **)(v20 + 12));
    v59 = *(_DWORD *)(v20 + 4) - v11;
    m_nAllocationCount = (CMaterial *)v21->m_TextBoxes.m_Memory.m_nAllocationCount;
    *((_DWORD *)&index.Value.pStringManaged + 1) = v22;
    GFxTextParagraph::Copy(
      this: v22,
      a2: m_nAllocationCount,
      a3: (const struct GFxTextParagraph *)v20,
      a4: v11,
      a5: 0,
      a6: v59);
    delta = (GFxFontMap::MapEntry *)(*(_DWORD *)(v20 + 4) - v11);
    v23 = *((int **)a3 + 3);
    v24 = *v23;
    v25 = *(_DWORD *)(*v23 + 4);
    if ( v25 != 0 )
    {
      v26 = v25 - 1;
      if ( *(_DWORD *)v24 != 0 && v26 < v25 )
        v27 = (_WORD *)(*(_DWORD *)v24 + 2 * v26);
      else
        v27 = nullptr;
      if ( *v27 == 0 )
        --v25;
    }
    GFxTextParagraph::Copy(
      this: (GFxTextParagraph *)v20,
      a2: (CMaterial *)v67->m_TextBoxes.m_Memory.m_nAllocationCount,
      a3: (const struct GFxTextParagraph *)v24,
      a4: 0,
      a5: v11,
      a6: v25);
    v28 = *(_DWORD *)(v24 + 4);
    if ( v28 != 0 )
    {
      v29 = v28 - 1;
      if ( *(_DWORD *)v24 != 0 && v29 < v28 )
        v30 = (_WORD *)(*(_DWORD *)v24 + 2 * v29);
      else
        v30 = nullptr;
      if ( *v30 == 0 )
        --v28;
    }
    v66 = (GFxFontMap::MapEntry *)(a5 - v28);
    if ( v11 == 0 )
      GFxTextParagraph::SetFormat(
        this: (GFxFontMap::MapEntry *)v20,
        pallocator: (CMaterial *)v67->m_TextBoxes.m_Memory.m_nAllocationCount,
        pallocator_4: *(GRefCountNTSImpl **)(v24 + 12));
    if ( delta != nullptr )
      GFxTextParagraph::Shrink(this: (GFxFontMap::MapEntry *)v20, delta);
    v31 = *(_DWORD *)(v20 + 4);
    if ( v31 != 0 )
    {
      v32.pObject = *(GFxFontMap **)v20;
      v33 = v31 - 1;
      if ( v32.pObject != nullptr && v33 < v31 )
        v34 = (_WORD *)v32.pObject + v33;
      else
        v34 = nullptr;
      if ( *v34 == 0 )
        --v31;
    }
    a4 += v31;
    if ( index.Type < (int)index.pObjectInterface[1].pMovieRoot )
      ++index.Type;
    v35 = *((_DWORD *)a3 + 4);
    if ( v35 > 0 )
      v63 = 1;
    while ( v63 >= 0 && v63 < v35 && v66 != nullptr )
    {
      v36 = *(_DWORD *)(*((_DWORD *)a3 + 3) + 4 * v63);
      v37 = *(_DWORD *)(v36 + 4);
      if ( v37 != 0 )
      {
        v38 = v37 - 1;
        if ( *(_DWORD *)v36 != 0 && v38 < v37 )
          v39 = (_WORD *)(*(_DWORD *)v36 + 2 * v38);
        else
          v39 = nullptr;
        if ( *v39 == 0 )
          --v37;
      }
      if ( v37 > (unsigned int)v66
        || (GFxFontMap::MapEntry *)v37 == v66 && !GFxTextParagraph::HasNewLine(this: (GFxTextParagraph *)v36) )
      {
        v40 = v67;
        v60 = v37;
        v41 = *((GFxFontMap::MapEntry **)&index.Value.pStringManaged + 1);
        GFxTextParagraph::Copy(
          this: *((GFxTextParagraph **)&index.Value.pStringManaged + 1),
          a2: (CMaterial *)v67->m_TextBoxes.m_Memory.m_nAllocationCount,
          a3: (const struct GFxTextParagraph *)v36,
          a4: 0,
          a5: 0,
          a6: v60);
        GFxTextParagraph::SetFormat(
          this: v41,
          pallocator: (CMaterial *)v40->m_TextBoxes.m_Memory.m_nAllocationCount,
          pallocator_4: *(GRefCountNTSImpl **)(v36 + 12));
        break;
      }
      GFxStyledText::InsertCopyOfParagraph(this: v67, a2: *(float *)&v11, iter: &index, result: (GFxResourceId *)v36);
      v35 = *((_DWORD *)a3 + 4);
      v66 = (GFxFontMap::MapEntry *)((char *)v66 - v37);
      a4 += v37;
      if ( v63 < v35 )
        ++v63;
      if ( index.Type < (int)index.pObjectInterface[1].pMovieRoot )
        ++index.Type;
    }
    v42 = *((int **)&index.Value.pStringManaged + 1);
    *(_DWORD *)(*((_DWORD *)&index.Value.pStringManaged + 1) + 28) = a4;
    v43 = v42[1];
    if ( v43 != 0 )
    {
      v44 = *v42;
      v45 = v43 - 1;
      if ( v44 != 0 && v45 < v43 )
        v46 = (_WORD *)(v44 + 2 * v45);
      else
        v46 = nullptr;
      if ( *v46 == 0 )
        --v43;
    }
    a4 += v43;
    pMovieRoot = index.pObjectInterface[1].pMovieRoot;
  }
  if ( index.Type < (int)pMovieRoot )
    ++index.Type;
  v47 = index.pObjectInterface;
  v48 = index.Type;
  v49 = a4;
  while ( v48 >= VT_Undefined )
  {
    if ( v48 >= (int)pMovieRoot )
      break;
    v50 = *((_DWORD *)v47->pMovieRoot + v48);
    if ( *(const char **)(v50 + 28) == v49 )
      break;
    *(_DWORD *)(v50 + 28) = v49;
    v49 += *(_DWORD *)(v50 + 4);
    pMovieRoot = v47[1].pMovieRoot;
    if ( v48 < (int)pMovieRoot )
      ++v48;
  }
  v51 = v67->m_TextBoxes.m_Size - 1;
  if ( v67 != (SFTextObjectImpl *)-12
    && v51 >= 0
    && v51 < v67->m_TextBoxes.m_Size
    && (v52 = *(GFxTextParagraph **)(v67->m_TextBoxes.m_Memory.m_nGrowSize + 4 * v51)) != nullptr
    || (GFxStyledText::AppendNewParagraph(a1: (int)v67, this: nullptr, pdefParaFmt: v62), v52 != nullptr) )
  {
    pObject = v52[1].pObject;
    if ( pObject == nullptr
      || ((v54 = (char *)&pObject[-1].pImpl + 3, v52->pObject == nullptr) || v54 >= (char *)pObject
        ? (v55 = nullptr)
        : (v55 = (unsigned __int16 *)v52->pObject + (_DWORD)v54),
          (v56 = *v55) != 13 && v56 != 10) )
    {
      GFxTextParagraph::AppendTermNull(
        this: v52,
        result: (GFxFontMap *)v67->m_TextBoxes.m_Memory.m_nAllocationCount,
        a3: (const struct GFxTextFormat *)v67[1].m_TextBoxes.m_Memory.m_pMemory);
    }
  }
  if ( (*((_BYTE *)a3 + 32) & 1) != 0 )
    LOBYTE(v67[1].m_TextBoxes.m_Memory.m_nAllocationCount) |= 1u;
  return a5;
}

//------------------------------------------------------------------------------
// Address: 0x101655C0
// Name: public: void GFxStyledText::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::Clear(int this)
{
  unsigned int v2; // ebx
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v3; // esi
  int (__thiscall *v4)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  GStringDH *v5; // eax
  GStringDH *v6; // esi
  GRefCountNTSImpl *v7; // ecx
  int v8; // esi
  int *v9; // esi
  unsigned int n; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  n = *(_DWORD *)(this + 16);
  if ( n != 0 )
  {
    do
    {
      if ( *(_DWORD *)(this + 8) == 0 )
      {
        v3 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
        v4 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v3->m_pfnProxied) + 40);
        v11 = 324;
        v5 = (GStringDH *)v4(a1: v3, a2: 80, a3: &v11);
        if ( v5 != nullptr )
          v6 = GFxTextAllocator::GFxTextAllocator(this: v5, result: v3, flags: 0);
        else
          v6 = nullptr;
        v7 = *(GRefCountNTSImpl **)(this + 8);
        if ( v7 != nullptr )
          GRefCountNTSImpl::Release(this: v7);
        *(_DWORD *)(this + 8) = v6;
      }
      v8 = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v8);
      ++v2;
      *(_DWORD *)v8 = 0;
      *(_DWORD *)(v8 + 8) = 0;
      *(_DWORD *)(v8 + 4) = 0;
    }
    while ( v2 < n );
  }
  v9 = (int *)(this + 12);
  if ( *(_DWORD *)(this + 16) == 0 )
  {
    if ( *(_DWORD *)(this + 20) == 0 )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: (GRenderer::CachedData *)(this + 12),
        pheapAddr: (const void *)(this + 12),
        newCapacity: 0);
    goto LABEL_17;
  }
  GConstructorMov<GFxStyledText::ParagraphPtrWrapper>::DestructArray(
    a1: (_DWORD *)this,
    count: *v9,
    counta: *(_DWORD *)(this + 16));
  if ( (*(_DWORD *)(this + 20) & 0xFFFFFFFE) == 0 )
  {
LABEL_17:
    *(_DWORD *)(this + 16) = 0;
    *(_BYTE *)(this + 32) &= ~1u;
    return;
  }
  if ( *v9 != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*v9);
    *v9 = 0;
  }
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_BYTE *)(this + 32) &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x101656C0
// Name: public: GFxStyledText::GFxStyledText(class GFxTextAllocator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::GFxStyledText(
        CUtlMemory<GFxValue,int> *this@<ecx>,
        CMaterial *pallocator,
        int pallocator_4)
{
  GFxTextParagraphFormat *v5; // eax
  GRefCountNTSImpl *v6; // ecx
  GStringDH *TextFormat; // eax
  IShaderAPI *v8; // ecx
  GStringDH *v9; // edi
  int v10; // [esp+0h] [ebp-24h]
  int v11; // [esp+4h] [ebp-20h]
  ImageFormat v12; // [esp+8h] [ebp-1Ch]
  GRefCountNTSImpl srcfmt; // [esp+Ch] [ebp-18h] BYREF
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  int v17; // [esp+20h] [ebp-4h]
  GFxTextParagraphFormat *pallocatora; // [esp+2Ch] [ebp+8h]

  this->m_pMemory = (GFxValue *)&GRefCountImplCore::`vftable';
  this->m_nAllocationCount = 1;
  this->m_pMemory = (GFxValue *)&GFxStyledText::`vftable';
  if ( pallocator != nullptr )
    ++pallocator->m_iEnumerationID;
  this->m_nGrowSize = (int)pallocator;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 32) = 0;
  srcfmt.RefCount = 1;
  v15 = 0;
  v17 = 0;
  srcfmt.__vftable = (GRefCountNTSImpl_vtbl *)&GFxTextParagraphFormat::`vftable';
  v14 = 0;
  v16 = 0;
  v5 = GFxTextAllocator::AllocateParagraphFormat(this: pallocator, &srcfmt, pfmt: v10, a4: v11, a5: v12);
  v6 = *((GRefCountNTSImpl **)this + 6);
  pallocatora = v5;
  if ( v6 != nullptr )
    GRefCountNTSImpl::Release(this: v6);
  *((_DWORD *)this + 6) = pallocatora;
  srcfmt.__vftable = (GRefCountNTSImpl_vtbl *)&GFxTextParagraphFormat::`vftable';
  GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&srcfmt);
  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&srcfmt);
  TextFormat = GFxTextAllocator::AllocateTextFormat(this: pallocator, srcfmt: (int)&pallocator->m_Flags);
  v8 = *((IShaderAPI **)this + 7);
  v9 = TextFormat;
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  *((_DWORD *)this + 7) = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10165790
// Name: public: unsigned int GFxStyledText::AppendString(char const __near *,unsigned int,enum GFxStyledText::NewLinePolicy)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::AppendString(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this@<ecx>,
        const char *a2@<edi>,
        const char *putf8String,
        unsigned int stringSize,
        int a5)
{
  GFxStyledText::AppendString(
    this,
    a2,
    putf8String,
    stringSize,
    a5,
    a6: *((struct GFxTextFormat **)this + 7),
    a7: *((SFTextObjectImpl **)this + 6));
}

//------------------------------------------------------------------------------
// Address: 0x101657B0
// Name: public: void GFxStyledText::SetText(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::SetText(
        CUtlMemory<GFxValue,int> *this@<ecx>,
        const char *a2@<edi>,
        const char *putf8String,
        unsigned int stringSize)
{
  GFxStyledText::Clear((int)this);
  GFxStyledText::AppendString(
    (CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *)this,
    a2,
    putf8String,
    stringSize,
    a5: 1,
    a6: *((struct GFxTextFormat **)this + 7),
    a7: *((SFTextObjectImpl **)this + 6));
}

//------------------------------------------------------------------------------
// Address: 0x101657E0
// Name: public: void GFxStyledText::SetText(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::SetText(CUtlMemory<GFxValue,int> *this, CUtlMemory<GFxValue,int> *pstr, unsigned int a3)
{
  GFxStyledText::Clear((int)this);
  GFxStyledText::AppendString(
    this,
    pwch: (wchar_t *)pstr,
    a3,
    a4: 1,
    a5: *((struct GFxTextFormat **)this + 7),
    a6: *((SFTextObjectImpl **)this + 6));
}

//------------------------------------------------------------------------------
// Address: 0x10165810
// Name: public: void GFxStyledText::CopyStyledText(class GFxStyledText __near *,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStyledText::CopyStyledText(
        GFxStyledText *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        SFTextObjectImpl *a5,
        const char *indexInPara,
        const struct GFxTextParagraph *remainedLen)
{
  unsigned int Length; // eax
  const char *v8; // edi
  unsigned int v9; // esi
  GFxValue::ObjectInterface *pObjectInterface; // ebx
  GFxValue::ValueType Type; // edi
  struct GFxMovieRoot *pMovieRoot; // eax
  const struct GFxTextParagraph *v13; // ebx
  const char *v14; // eax
  GFxFontMap *v15; // eax
  GFxFontMap *v16; // ebx
  unsigned int v17; // ecx
  _WORD *v18; // ecx
  volatile unsigned int v19; // ebx
  CMaterial *v20; // eax
  _DWORD *v21; // eax
  unsigned int v22; // esi
  unsigned int v23; // edx
  _WORD *v24; // ecx
  int v25; // edi
  SFTextObjectImpl *v26; // ebx
  GFxTextParagraph *v27; // eax
  GFxTextParagraph *v28; // esi
  CMaterial *v29; // eax
  int *p_m_nGrowSize; // esi
  int v31; // eax
  int v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // edi
  unsigned __int16 *v35; // ecx
  int v36; // ecx
  int v37; // eax
  GFxTextParagraph *v38; // eax
  GFxFontMap *v39; // ecx
  char *v40; // esi
  unsigned __int16 *v41; // ecx
  int v42; // ecx
  const struct GFxTextParagraph *v43; // [esp-10h] [ebp-20h]
  unsigned int v45; // [esp-Ch] [ebp-1Ch]
  SFTextObjectImpl *pObject; // [esp-4h] [ebp-14h]
  volatile unsigned int v48; // [esp-4h] [ebp-14h]
  GFxValue index; // [esp+0h] [ebp-10h] BYREF

  Length = (unsigned int)remainedLen;
  *((_DWORD *)&index.Value.pStringManaged + 1) = this;
  if ( remainedLen == (const struct GFxTextParagraph *)-1 )
    Length = GFxStyledText::GetLength(this);
  v8 = indexInPara;
  v9 = Length - (_DWORD)indexInPara;
  indexInPara = nullptr;
  remainedLen = (const struct GFxTextParagraph *)v9;
  GFxStyledText::Clear(this: (int)a5);
  a5->SetText_2(this: a5, a2: v8, v9, &pMem, a3, a4, a2);
  GFxStyledText::GetParagraphByIndex(
    this: *((SFTextObjectImpl **)&index.Value.pStringManaged + 1),
    &index,
    indexa: (unsigned int)v8,
    pindexInParagraph: (unsigned int *)&indexInPara);
  pObjectInterface = index.pObjectInterface;
  if ( index.pObjectInterface != nullptr )
  {
    Type = index.Type;
    if ( index.Type >= VT_Undefined )
    {
      pMovieRoot = index.pObjectInterface[1].pMovieRoot;
      if ( index.Type < (int)pMovieRoot )
      {
        if ( indexInPara == nullptr )
          goto LABEL_19;
        v13 = *((const struct GFxTextParagraph **)index.pObjectInterface->pMovieRoot + index.Type);
        pObject = (SFTextObjectImpl *)v13[3].pObject;
        remainedLen = v13;
        GFxStyledText::AppendNewParagraph(a1: (int)a5, this: pObject, pdefParaFmt: (const char *)index.pObjectInterface);
        index.Value.pString = v14;
        v15 = v13[1].pObject;
        if ( v15 != nullptr )
        {
          v16 = v13->pObject;
          v17 = (unsigned int)&v15[-1].pImpl + 3;
          if ( v16 != nullptr && v17 < (unsigned int)v15 )
            v18 = (_WORD *)v16 + v17;
          else
            v18 = nullptr;
          if ( *v18 == 0 )
            v15 = (GFxFontMap *)((char *)v15 - 1);
        }
        v19 = (char *)v15 - indexInPara;
        if ( (char *)v15 - indexInPara >= v9 )
          v19 = v9;
        v45 = (unsigned int)indexInPara;
        v43 = remainedLen;
        GFxStyledText::GetAllocator(this: a5);
        GFxTextParagraph::Copy(this: (GFxTextParagraph *)index.Value.pString, a2: v20, a3: v43, a4: v45, a5: 0, a6: v19);
        pMovieRoot = index.pObjectInterface[1].pMovieRoot;
        remainedLen = (const struct GFxTextParagraph *)(v9 - v19);
        for ( pObjectInterface = index.pObjectInterface; ; pMovieRoot = pObjectInterface[1].pMovieRoot )
        {
          if ( Type < (int)pMovieRoot )
            ++Type;
LABEL_19:
          if ( Type < VT_Undefined || Type >= (int)pMovieRoot || remainedLen == nullptr )
            break;
          v21 = *((_DWORD **)pObjectInterface->pMovieRoot + Type);
          v22 = v21[1];
          if ( v22 != 0 )
          {
            v23 = v22 - 1;
            if ( *v21 != 0 && v23 < v22 )
              v24 = (_WORD *)(*v21 + 2 * v23);
            else
              v24 = nullptr;
            if ( *v24 == 0 )
              --v22;
          }
          if ( v22 > (unsigned int)remainedLen )
          {
            v25 = *((_DWORD *)pObjectInterface->pMovieRoot + Type);
            v26 = a5;
            GFxStyledText::AppendNewParagraph(
              a1: (int)a5,
              this: *(SFTextObjectImpl **)(v25 + 12),
              pdefParaFmt: (const char *)index.pObjectInterface);
            v48 = (volatile unsigned int)remainedLen;
            v28 = v27;
            GFxStyledText::GetAllocator(this: a5);
            GFxTextParagraph::Copy(this: v28, a2: v29, a3: (const struct GFxTextParagraph *)v25, a4: 0, a5: 0, a6: v48);
            goto LABEL_33;
          }
          GFxStyledText::AppendCopyOfParagraph(
            this: a5,
            result: *((GFxResourceId **)pObjectInterface->pMovieRoot + Type));
          remainedLen = (const struct GFxTextParagraph *)((char *)remainedLen - v22);
        }
      }
    }
  }
  v26 = a5;
LABEL_33:
  p_m_nGrowSize = &v26->m_TextBoxes.m_Memory.m_nGrowSize;
  v31 = v26->m_TextBoxes.m_Size - 1;
  if ( v26 != (SFTextObjectImpl *)-12 && v31 >= 0 && v31 < v26->m_TextBoxes.m_Size )
  {
    v32 = *(_DWORD *)(*p_m_nGrowSize + 4 * v31);
    if ( v32 != 0 )
    {
      v33 = *(_DWORD *)(v32 + 4);
      if ( v33 != 0 )
      {
        v34 = v33 - 1;
        if ( *(_DWORD *)v32 != 0 && v34 < v33 )
          v35 = (unsigned __int16 *)(*(_DWORD *)v32 + 2 * v34);
        else
          v35 = nullptr;
        v36 = *v35;
        if ( v36 == 13 || v36 == 10 )
          GFxStyledText::AppendNewParagraph(
            a1: (int)v26,
            this: *(SFTextObjectImpl **)(v32 + 12),
            pdefParaFmt: (const char *)index.pObjectInterface);
      }
    }
  }
  v37 = v26->m_TextBoxes.m_Size - 1;
  if ( v26 != (SFTextObjectImpl *)-12
    && v37 >= 0
    && v37 < v26->m_TextBoxes.m_Size
    && (v38 = *(GFxTextParagraph **)(*p_m_nGrowSize + 4 * v37)) != nullptr
    || (GFxStyledText::AppendNewParagraph(
          a1: (int)v26,
          this: nullptr,
          pdefParaFmt: (const char *)index.pObjectInterface),
        v38 != nullptr) )
  {
    v39 = v38[1].pObject;
    if ( v39 == nullptr
      || ((v40 = (char *)&v39[-1].pImpl + 3, v38->pObject == nullptr) || v40 >= (char *)v39
        ? (v41 = nullptr)
        : (v41 = (unsigned __int16 *)v38->pObject + (_DWORD)v40),
          (v42 = *v41) != 13 && v42 != 10) )
    {
      GFxTextParagraph::AppendTermNull(
        this: v38,
        result: (GFxFontMap *)v26->m_TextBoxes.m_Memory.m_nAllocationCount,
        a3: (const struct GFxTextFormat *)v26[1].m_TextBoxes.m_Memory.m_pMemory);
    }
  }
  if ( (*(_BYTE *)(*((_DWORD *)&index.Value.pStringManaged + 1) + 32) & 1) != 0 )
    LOBYTE(v26[1].m_TextBoxes.m_Memory.m_nAllocationCount) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10165A50
// Name: public: unsigned int GFxStyledText::InsertString(wchar_t const __near *,unsigned int,unsigned int,enum GFxStyledText::NewLinePolicy)
// Source: json
//------------------------------------------------------------------------------
const char *__userpurge GFxStyledText::InsertString@<eax>(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this@<ecx>,
        const char *a2@<ebx>,
        GFxValue *pstr,
        unsigned int a4,
        unsigned int length,
        int a6)
{
  return GFxStyledText::InsertString(
           this,
           a2,
           pstr,
           indexInPara: a4,
           insLineLen: length,
           a6,
           a7: *((IShaderDevice **)this + 7),
           a8: *((SFTextObjectImpl **)this + 6));
}

//------------------------------------------------------------------------------
// Address: 0x10165A80
// Name: protected: void GFxStyledText::RemoveParagraph(class GArrayBase<struct GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>>::Iterator __near &,class GFxTextParagraph __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::RemoveParagraph(void *this, const SFTextObjectImpl *result, int a3)
{
  GRenderer::CachedData *v3; // ecx
  GFxValue *m_pMemory; // eax

  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 20))(a1: this, a2: a3);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)a3);
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 4) = 0;
  v3 = (GRenderer::CachedData *)result->__vftable;
  if ( result->__vftable != nullptr )
  {
    m_pMemory = result->m_TextBoxes.m_Memory.m_pMemory;
    if ( (int)m_pMemory >= 0 && (int)m_pMemory < (int)v3->hData )
      GArrayBase<GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>>::RemoveAt(
        this: v3,
        a2: (int)m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165AD0
// Name: public: void GFxStyledText::Remove(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::Remove(SFTextObjectImpl *this, unsigned int a2, unsigned int Length)
{
  GRenderer::CachedData *v4; // esi
  int m_pMemory; // ebx
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // edi
  const struct GFxTextParagraph *v9; // edi
  unsigned int pObject; // eax
  _DWORD *v11; // edi
  GRefCountNTSImpl *v12; // ecx
  int v13; // edi
  GFxValue *m_pElements; // edi
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  int v16; // eax
  GFxTextParagraph *v17; // eax
  GFxFontMap *v18; // ecx
  char *v19; // esi
  unsigned __int16 *v20; // ecx
  int v21; // ecx
  const char *v22; // [esp+0h] [ebp-24h]
  SFTextObjectImpl index; // [esp+Ch] [ebp-18h] BYREF
  bool v24; // [esp+2Fh] [ebp+Bh]

  index.m_TextBoxes.m_pElements = (GFxValue *)this;
  if ( Length == -1 )
    Length = GFxStyledText::GetLength((GFxStyledText *)this);
  ((void (__thiscall *)(SFTextObjectImpl *, unsigned int, unsigned int))this->SetText_4)(a1: this, a2, a3: Length);
  GFxStyledText::GetParagraphByIndex(
    this,
    (GFxValue *)&index,
    indexa: a2,
    pindexInParagraph: (unsigned int *)&index.m_TextBoxes.m_Memory.m_nGrowSize);
  v4 = (GRenderer::CachedData *)index.__vftable;
  index.m_TextBoxes.m_Size = Length;
  m_pMemory = (int)index.m_TextBoxes.m_Memory.m_pMemory;
  index.m_TextBoxes.m_Memory.m_nAllocationCount = 0;
  v24 = false;
  if ( index.__vftable != nullptr )
  {
    if ( (int)index.m_TextBoxes.m_Memory.m_pMemory >= 0
      && (int)index.m_TextBoxes.m_Memory.m_pMemory < (int)index.SetText_2 )
    {
      v6 = *((_DWORD *)index.SetText + (int)index.m_TextBoxes.m_Memory.m_pMemory);
      v7 = *(_DWORD *)(v6 + 4);
      v8 = Length;
      if ( Length >= v7 - index.m_TextBoxes.m_Memory.m_nGrowSize )
        v8 = *(_DWORD *)(v6 + 4) - index.m_TextBoxes.m_Memory.m_nGrowSize;
      if ( v8 <= v7 )
      {
        v24 = v8 + index.m_TextBoxes.m_Memory.m_nGrowSize >= v7;
        index.m_TextBoxes.m_Memory.m_nAllocationCount = *((_DWORD *)index.SetText
                                                        + (int)index.m_TextBoxes.m_Memory.m_pMemory);
        GFxTextParagraph::Remove(
          this: v6,
          startPos: index.m_TextBoxes.m_Memory.m_nGrowSize,
          endPos: v8 + index.m_TextBoxes.m_Memory.m_nGrowSize);
        index.m_TextBoxes.m_Size = Length - v8;
        if ( m_pMemory < (int)v4->hData )
          index.m_TextBoxes.m_Memory.m_pMemory = (GFxValue *)++m_pMemory;
      }
    }
    while ( v4 != nullptr )
    {
      if ( m_pMemory < 0 || m_pMemory >= (int)v4->hData )
        goto LABEL_28;
      v9 = *((const struct GFxTextParagraph **)&v4->pRenderer->__vftable + m_pMemory);
      pObject = (unsigned int)v9[1].pObject;
      index.m_TextBoxes.m_Memory.m_nGrowSize = pObject;
      if ( index.m_TextBoxes.m_Size < pObject )
      {
        if ( index.m_TextBoxes.m_Memory.m_nAllocationCount != 0 && v24 )
        {
          GFxTextParagraph::Copy(
            this: (GFxTextParagraph *)index.m_TextBoxes.m_Memory.m_nAllocationCount,
            a2: (CMaterial *)index.m_TextBoxes.m_pElements->Value.pString,
            a3: v9,
            a4: index.m_TextBoxes.m_Size,
            a5: *(_DWORD *)(index.m_TextBoxes.m_Memory.m_nAllocationCount + 4),
            a6: pObject - index.m_TextBoxes.m_Size);
          GFxStyledText::RemoveParagraph(this: index.m_TextBoxes.m_pElements, result: &index, a3: (int)v9);
          v24 = false;
        }
LABEL_28:
        if ( m_pMemory >= 0 && m_pMemory < (int)v4->hData )
        {
          v13 = *((_DWORD *)&v4->pRenderer->__vftable + m_pMemory);
          if ( *(_DWORD *)(v13 + 4) != 0 )
          {
            if ( index.m_TextBoxes.m_Memory.m_nAllocationCount != 0 && v24 )
            {
              GFxTextParagraph::Copy(
                this: (GFxTextParagraph *)index.m_TextBoxes.m_Memory.m_nAllocationCount,
                a2: (CMaterial *)index.m_TextBoxes.m_pElements->Value.pString,
                a3: (const struct GFxTextParagraph *)v13,
                a4: 0,
                a5: *(_DWORD *)(index.m_TextBoxes.m_Memory.m_nAllocationCount + 4),
                a6: *(_DWORD *)(v13 + 4));
              GFxStyledText::RemoveParagraph(this: index.m_TextBoxes.m_pElements, result: &index, a3: v13);
            }
          }
          else
          {
            ((void (__thiscall *)(GFxValue *, _DWORD))index.m_TextBoxes.m_pElements->pObjectInterface[5].pMovieRoot)(
              a1: index.m_TextBoxes.m_pElements,
              a2: *((_DWORD *)&v4->pRenderer->__vftable + m_pMemory));
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v13);
            *(_DWORD *)v13 = 0;
            *(_DWORD *)(v13 + 8) = 0;
            *(_DWORD *)(v13 + 4) = 0;
            if ( m_pMemory < (int)v4->hData )
              GArrayBase<GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>>::RemoveAt(
                this: v4,
                a2: m_pMemory);
          }
        }
        while ( m_pMemory >= 0 && m_pMemory < (int)v4->hData )
        {
          *(_DWORD *)(*((_DWORD *)&v4->pRenderer->__vftable + m_pMemory) + 28) -= Length;
          if ( m_pMemory < (int)v4->hData )
            ++m_pMemory;
        }
        break;
      }
      ((void (__thiscall *)(GFxValue *, const struct GFxTextParagraph *))index.m_TextBoxes.m_pElements->pObjectInterface[5].pMovieRoot)(
        a1: index.m_TextBoxes.m_pElements,
        a2: v9);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9->pObject);
      v9->pObject = nullptr;
      v9[2].pObject = nullptr;
      v9[1].pObject = nullptr;
      if ( m_pMemory < (int)v4->hData )
      {
        if ( v4->hData == (void *)1 )
        {
          GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::Resize(
            pheapAddr: v4,
            newSize: 0);
        }
        else
        {
          v11 = *((_DWORD **)&v4->pRenderer->__vftable + m_pMemory);
          if ( v11 != nullptr )
          {
            GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>(this: v11 + 4);
            v12 = (GRefCountNTSImpl *)v11[3];
            if ( v12 != nullptr )
              GRefCountNTSImpl::Release(this: v12);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
          }
          memmove(
            dst: (unsigned __int8 *)&v4->pRenderer->__vftable + 4 * m_pMemory,
            src: (unsigned __int8 *)&v4->pRenderer->RefCount + 4 * m_pMemory,
            count: 4 * ((int)v4->hData - m_pMemory) - 4);
          --v4->hData;
        }
      }
      index.m_TextBoxes.m_Size -= index.m_TextBoxes.m_Memory.m_nGrowSize;
      if ( index.m_TextBoxes.m_Size == 0 )
        goto LABEL_28;
    }
  }
  m_pElements = index.m_TextBoxes.m_pElements;
  pObjectInterface = index.m_TextBoxes.m_pElements[1].pObjectInterface;
  v16 = (int)&pObjectInterface[-1].pMovieRoot + 3;
  if ( (int)&pObjectInterface[-1].pMovieRoot + 3 >= 0
    && v16 < (int)pObjectInterface
    && (v17 = *(GFxTextParagraph **)(*((_DWORD *)&index.m_TextBoxes.m_pElements->Value.pStringManaged + 1) + 4 * v16)) != nullptr
    || (GFxStyledText::AppendNewParagraph(a1: (int)index.m_TextBoxes.m_pElements, this: nullptr, pdefParaFmt: v22),
        v17 != nullptr) )
  {
    v18 = v17[1].pObject;
    if ( v18 == nullptr
      || ((v19 = (char *)&v18[-1].pImpl + 3, v17->pObject == nullptr) || v19 >= (char *)v18
        ? (v20 = nullptr)
        : (v20 = (unsigned __int16 *)v17->pObject + (_DWORD)v19),
          (v21 = *v20) != 13 && v21 != 10) )
    {
      GFxTextParagraph::AppendTermNull(
        this: v17,
        result: (GFxFontMap *)m_pElements->Value.pString,
        a3: *((const struct GFxTextFormat **)&m_pElements[1].Value.pStringManaged + 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165D80
// Name: private: bool GFxStyledText::ParseHtmlImpl<wchar_t>(wchar_t const __near *,unsigned int,class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near *,bool,bool,class GFxTextStyleManager const __near *,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStyledText::ParseHtmlImpl<wchar_t>(
        const struct GFxTextParagraphFormat **this,
        unsigned __int16 *a2,
        GFxResourceId *a3,
        int a4,
        char a5,
        char a6,
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *a7,
        int a8,
        struct GFxTextParagraphFormat *a9)
{
  int v11; // esi
  int v12; // eax
  _DWORD *v13; // eax
  const struct GFxTextParagraphFormat *v14; // eax
  int m_Size; // eax
  void **m_pElements; // eax
  int Next; // eax
  const char *v18; // edi
  int v19; // eax
  unsigned int v20; // ebx
  _DWORD *v21; // edi
  GFxResourceId *v22; // eax
  unsigned int v23; // eax
  int v24; // eax
  int v25; // esi
  GMemoryHeap *v26; // esi
  const char **v27; // eax
  int v28; // ebx
  const struct GString *v29; // eax
  const void *v30; // ebx
  int v31; // esi
  int v32; // eax
  int v33; // edi
  int v34; // eax
  const char **v35; // edi
  const char **v36; // eax
  int v37; // eax
  int v38; // eax
  char *v39; // eax
  char *v40; // edi
  char *v41; // esi
  CMaterial *v42; // ebx
  char v43; // al
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v44; // ebx
  GRefCountNTSImpl *v45; // ecx
  unsigned int Length; // edi
  GStringDH *v47; // eax
  _DWORD *v48; // eax
  int v49; // esi
  int v50; // edi
  int v51; // esi
  int v52; // eax
  int v53; // ebx
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v54; // eax
  int v55; // eax
  int v56; // ebx
  const char **v57; // esi
  int v58; // eax
  int v59; // eax
  char v60; // al
  int v61; // eax
  int v62; // eax
  GFxResourceId *v63; // eax
  GFxFontMap::MapEntry *v64; // ebx
  GFxFontMap::MapEntry *v65; // eax
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v66; // ebx
  const char *v67; // eax
  GFxFontMap::MapEntry *v68; // eax
  CMaterial *v69; // eax
  int Style; // eax
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v71; // eax
  int v72; // eax
  CMaterial *v73; // eax
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v74; // ebx
  GFxResourceId *v75; // eax
  GFxResourceId *v76; // eax
  const char *v77; // eax
  int v78; // eax
  int v79; // ebx
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v80; // eax
  int v81; // eax
  const char **v82; // ebx
  const char *v83; // ebx
  int v84; // ebx
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v85; // eax
  int v86; // eax
  const char **v87; // eax
  __int16 v88; // dx
  CMaterial *v89; // eax
  const char **v90; // esi
  int v91; // eax
  const char **v92; // esi
  void *v93; // ecx
  __int16 v94; // dx
  __int16 v95; // cx
  __int16 v96; // cx
  __int16 v97; // cx
  __int16 v98; // cx
  unsigned int v99; // ebx
  unsigned int v100; // edi
  unsigned int i; // esi
  unsigned int v102; // edx
  unsigned int j; // eax
  int v104; // ecx
  unsigned int v105; // edi
  int v106; // edx
  unsigned int v107; // edi
  const char **v108; // esi
  int v109; // eax
  int v110; // eax
  int v111; // esi
  GFxValue::DisplayInfo *v112; // ebx
  int v113; // edi
  const char **v114; // eax
  const char **v115; // esi
  const char *v116; // eax
  int v117; // ecx
  int v118; // eax
  unsigned int v119; // eax
  int v120; // ebx
  unsigned int v121; // esi
  int v122; // ebx
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v123; // ebx
  const char *v124; // edi
  const char *v125; // eax
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v126; // esi
  const char *v127; // eax
  int v128; // esi
  int v129; // edi
  int v130; // ebx
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v131; // ebx
  int (__thiscall *v132)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  GStringDH *v133; // eax
  GStringDH *v134; // ebx
  GRefCountNTSImpl *v135; // ecx
  GFxTextParagraphFormat *ParagraphFormat; // eax
  GRefCountNTSImpl *v137; // ecx
  GFxTextParagraphFormat *v138; // edi
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v139; // ebx
  int (__thiscall *v140)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  GStringDH *v141; // eax
  GStringDH *v142; // edi
  GRefCountNTSImpl *v143; // ecx
  GFxTextParagraphFormat *v144; // eax
  GRefCountNTSImpl *v145; // ecx
  GFxTextParagraphFormat *v146; // edi
  int v147; // ecx
  int v148; // eax
  GFxTextParagraph *v149; // eax
  GFxFontMap *pObject; // ecx
  char *v151; // edi
  unsigned __int16 *v152; // edx
  int v153; // ecx
  int v154; // ecx
  int v155; // eax
  int *v156; // ecx
  unsigned int v157; // eax
  int v158; // ecx
  unsigned int v159; // edx
  _WORD *v160; // ecx
  int k; // eax
  int v162; // eax
  _DWORD *v163; // edi
  unsigned int v164; // eax
  unsigned int v165; // edx
  _WORD *v166; // ecx
  CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *v167; // ebx
  int (__thiscall *v168)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *); // edx
  GStringDH *v169; // eax
  GStringDH *v170; // ebx
  GRefCountNTSImpl *v171; // ecx
  CMaterial *v172; // esi
  int m; // ebx
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *v174; // [esp+4h] [ebp-3D8h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *v175; // [esp+4h] [ebp-3D8h]
  float y_low; // [esp+4h] [ebp-3D8h]
  const char *v177; // [esp+8h] [ebp-3D4h]
  const char *v178; // [esp+8h] [ebp-3D4h]
  int v179; // [esp+8h] [ebp-3D4h]
  const char *v180; // [esp+8h] [ebp-3D4h]
  unsigned int v181; // [esp+Ch] [ebp-3D0h]
  KeyValues *v182; // [esp+10h] [ebp-3CCh]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v183; // [esp+14h] [ebp-3C8h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v184; // [esp+40h] [ebp-39Ch] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v185; // [esp+6Ch] [ebp-370h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v186; // [esp+98h] [ebp-344h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v187; // [esp+C4h] [ebp-318h] BYREF
  ILocalize v188; // [esp+F0h] [ebp-2ECh] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v189; // [esp+11Ch] [ebp-2C0h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v190; // [esp+148h] [ebp-294h] BYREF
  GStringDH v191; // [esp+174h] [ebp-268h] BYREF
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v192; // [esp+184h] [ebp-258h] BYREF
  CMaterial v193; // [esp+1B0h] [ebp-22Ch] BYREF
  int v194; // [esp+254h] [ebp-188h] BYREF
  int v195; // [esp+258h] [ebp-184h] BYREF
  unsigned int v196; // [esp+25Ch] [ebp-180h] BYREF
  int v197; // [esp+260h] [ebp-17Ch] BYREF
  int v198; // [esp+264h] [ebp-178h] BYREF
  int v199; // [esp+268h] [ebp-174h] BYREF
  IMaterialInternal *purl; // [esp+26Ch] [ebp-170h] BYREF
  unsigned __int8 v201[4]; // [esp+270h] [ebp-16Ch] BYREF
  int v202; // [esp+274h] [ebp-168h] BYREF
  int v203; // [esp+278h] [ebp-164h] BYREF
  int v204; // [esp+27Ch] [ebp-160h] BYREF
  int v205; // [esp+280h] [ebp-15Ch] BYREF
  wchar_t *v206; // [esp+284h] [ebp-158h] BYREF
  int v207; // [esp+288h] [ebp-154h] BYREF
  int v208; // [esp+28Ch] [ebp-150h] BYREF
  float v209; // [esp+290h] [ebp-14Ch] BYREF
  unsigned __int8 *v210; // [esp+294h] [ebp-148h] BYREF
  void (__thiscall *urlSz)(IMaterial *); // [esp+298h] [ebp-144h] BYREF
  int v212; // [esp+29Ch] [ebp-140h] BYREF
  int v213; // [esp+2A0h] [ebp-13Ch] BYREF
  int v214; // [esp+2A4h] [ebp-138h] BYREF
  CMaterial v215; // [esp+2A8h] [ebp-134h] BYREF
  GFxValue::DisplayInfo *v216; // [esp+340h] [ebp-9Ch] BYREF
  int v217; // [esp+344h] [ebp-98h] BYREF
  GFxValue::DisplayInfo *v218; // [esp+348h] [ebp-94h] BYREF
  int v219; // [esp+34Ch] [ebp-90h]
  GFxValue::DisplayInfo *v220; // [esp+350h] [ebp-8Ch] BYREF
  GFxValue::DisplayInfo *v221; // [esp+354h] [ebp-88h] BYREF
  int v222; // [esp+358h] [ebp-84h] BYREF
  _DWORD v223[3]; // [esp+35Ch] [ebp-80h] BYREF
  unsigned __int16 *v224; // [esp+368h] [ebp-74h]
  unsigned __int16 *v225; // [esp+36Ch] [ebp-70h]
  int v226; // [esp+370h] [ebp-6Ch]
  char v227; // [esp+374h] [ebp-68h]
  void *v228; // [esp+378h] [ebp-64h]
  int v229; // [esp+37Ch] [ebp-60h]
  int v230; // [esp+380h] [ebp-5Ch]
  bool v231; // [esp+384h] [ebp-58h]
  int v232; // [esp+38Ch] [ebp-50h] BYREF
  char v233; // [esp+393h] [ebp-49h]
  int v234; // [esp+394h] [ebp-48h] BYREF
  char v235; // [esp+39Bh] [ebp-41h]
  int v236; // [esp+39Ch] [ebp-40h] BYREF
  const char **v237; // [esp+3A0h] [ebp-3Ch]
  int v238; // [esp+3A4h] [ebp-38h] BYREF
  int v239; // [esp+3A8h] [ebp-34h] BYREF
  IMaterialInternal *pfontList; // [esp+3ACh] [ebp-30h] BYREF
  int v241; // [esp+3B0h] [ebp-2Ch]
  void (__thiscall *fontListSz)(IMaterial *); // [esp+3B4h] [ebp-28h] BYREF
  unsigned int v243; // [esp+3B8h] [ebp-24h] BYREF
  int pstr; // [esp+3BCh] [ebp-20h] BYREF
  _DWORD *v245; // [esp+3C0h] [ebp-1Ch] BYREF
  int v246; // [esp+3C4h] [ebp-18h]
  int v247; // [esp+3C8h] [ebp-14h]
  KeyValues *m_pVMTKeyValues; // [esp+3CCh] [ebp-10h]
  unsigned int v249; // [esp+3D0h] [ebp-Ch] BYREF
  unsigned int c; // [esp+3D4h] [ebp-8h] BYREF
  std::_Num_float_base adr[4]; // [esp+3D8h] [ebp-4h]
  GFxResourceId *v252; // [esp+3E8h] [ebp+Ch]
  GFxResourceId *v253; // [esp+3E8h] [ebp+Ch]
  GFxResourceId *v254; // [esp+3E8h] [ebp+Ch]
  GFxResourceId *v255; // [esp+3E8h] [ebp+Ch]
  char v256; // [esp+3EBh] [ebp+Fh]
  struct GFxTextParagraphFormat *v257; // [esp+400h] [ebp+24h]
  struct GFxTextParagraphFormat *v258; // [esp+400h] [ebp+24h]
  struct GFxTextParagraphFormat *v259; // [esp+400h] [ebp+24h]

  *(_DWORD *)&adr[0].std::_Num_base = this;
  if ( a3 == nullptr )
  {
    GFxStyledText::EnsureTermNull((int)this);
    return 0;
  }
  v215.m_pVMTKeyValues = (KeyValues *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: this);
  m_pVMTKeyValues = v215.m_pVMTKeyValues;
  v223[0] = v215.m_pVMTKeyValues;
  v245 = nullptr;
  v246 = 0;
  v247 = 0;
  v223[1] = 0;
  v224 = a2;
  v225 = &a2[(_DWORD)a3];
  v226 = 0;
  v227 = 0;
  v223[2] = a2;
  if ( a2 < v225 )
  {
    v226 = *a2;
    v224 = a2 + 1;
  }
  v228 = nullptr;
  v229 = 0;
  v230 = 0;
  v231 = a6 != 0;
  v11 = a8;
  v237 = nullptr;
  v241 = 0;
  if ( a8 == 0 )
    v11 = (int)*(this + 7);
  v215.m_ShaderRenderState.m_pSnapshots = (RenderPassList_t *)1;
  HIDWORD(v215.m_ShaderRenderState.m_VertexUsage) = &GFxTextFormat::`vftable';
  GStringDH::CopyConstructHelper(
    this: (GStringDH *)(&v215.m_ShaderRenderState.m_pSnapshots + 1),
    a2: (const struct GString *)(v11 + 8),
    pheap: *(CUtlBuffer **)(v11 + 12));
  GStringDH::CopyConstructHelper(
    this: (GStringDH *)&v215.m_VMTIncludes.m_Memory.m_nAllocationCount,
    a2: (const struct GString *)(v11 + 16),
    pheap: *(CUtlBuffer **)(v11 + 12));
  v12 = *(_DWORD *)(v11 + 24);
  if ( v12 != 0 )
    ++*(_DWORD *)(v12 + 4);
  v215.m_VMTIncludes.m_Size = *(_DWORD *)(v11 + 24);
  v13 = *(_DWORD **)(v11 + 28);
  if ( v13 != nullptr )
    ++*v13;
  v215.m_VMTIncludes.m_pElements = *(void ***)(v11 + 28);
  *(_DWORD *)&v215.m_bShouldReloadFromWhitelist = *(_DWORD *)(v11 + 32);
  v215.m_representativeTexture = *(ITextureInternal **)(v11 + 36);
  LOBYTE(v215.m_Reflectivity.x) = *(_BYTE *)(v11 + 40);
  HIWORD(v215.m_Reflectivity.x) = *(_WORD *)(v11 + 42);
  v14 = a9;
  if ( a9 == nullptr )
    v14 = *(this + 6);
  GFxTextParagraphFormat::GFxTextParagraphFormat(this: (GFxTextParagraphFormat *)&v215, a2: v14);
  v215.m_RefCount.m_value = 1;
  *(_DWORD *)&v215.m_Name.m_Id = &GFxTextFormat::`vftable';
  v235 = 0;
  GStringDH::CopyConstructHelper(
    this: (GStringDH *)&v215.m_Flags,
    a2: (const struct GString *)&v215.m_ShaderRenderState.m_pSnapshots + 1,
    pheap: (CUtlBuffer *)v215.m_VMTIncludes.m_Memory.m_pMemory);
  v233 = 0;
  GStringDH::CopyConstructHelper(
    this: (GStringDH *)&v215.m_ppProxies,
    a2: (const struct GString *)&v215.m_VMTIncludes.m_Memory.m_nAllocationCount,
    pheap: (CUtlBuffer *)v215.m_VMTIncludes.m_Memory.m_pMemory);
  m_Size = v215.m_VMTIncludes.m_Size;
  if ( v215.m_VMTIncludes.m_Size != 0 )
  {
    ++*(_DWORD *)(v215.m_VMTIncludes.m_Size + 4);
    m_Size = v215.m_VMTIncludes.m_Size;
  }
  v215.m_ShaderRenderState.m_Flags = m_Size;
  m_pElements = v215.m_VMTIncludes.m_pElements;
  if ( v215.m_VMTIncludes.m_pElements != nullptr )
  {
    ++*v215.m_VMTIncludes.m_pElements;
    m_pElements = v215.m_VMTIncludes.m_pElements;
  }
  *(&v215.m_ShaderRenderState.m_Flags + 1) = (int)m_pElements;
  v215.m_ShaderRenderState.m_VertexFormat = *(_QWORD *)&v215.m_bShouldReloadFromWhitelist;
  LOBYTE(v215.m_ShaderRenderState.m_VertexUsage) = LOBYTE(v215.m_Reflectivity.x);
  WORD1(v215.m_ShaderRenderState.m_VertexUsage) = HIWORD(v215.m_Reflectivity.x);
  GFxTextFormat::SetUrl(
    this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)((char *)&v215.m_ShaderRenderState.m_VertexUsage + 4),
    purl: (char *)&pMem,
    urlSz: 0xFFFFFFFF);
  Next = GFxSGMLParser<wchar_t>::GetNext(this: (int)v223);
  v257 = (struct GFxTextParagraphFormat *)Next;
  if ( Next == 0x8000 )
    goto LABEL_275;
  do
  {
    v18 = (const char *)a4;
    if ( Next == 1 )
      break;
    if ( Next > 4 )
    {
      if ( Next != 32773 )
        goto LABEL_263;
    }
    else if ( Next != 4 )
    {
      v19 = Next - 2;
      if ( v19 != 0 )
      {
        if ( v19 == 1
          && GFxSGMLParser<wchar_t>::ParseContent(this: (int)v223, a2: (unsigned __int8 **)&v206, a3: (int *)&v196) )
        {
          v20 = v196;
          if ( v196 != 0 )
          {
            v21 = *(_DWORD **)&adr[0].std::_Num_base;
            GFxStyledText::GetLastParagraph(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
            v23 = v22 != nullptr ? GFxTextParagraph::GetLength(this: v22) : 0;
            if ( a6 == 0 || v20 > 1 || *v206 != 32 || v23 != 0 )
            {
              if ( v246 != 0 )
              {
                v24 = (int)&v245[21 * v246 - 21];
                v25 = v24 + 16;
                GFxStyledText::AppendString(
                  this: v21,
                  pwch: v206,
                  a3: v20,
                  a4: 1,
                  a5: (struct GFxTextFormat *)(v24 + 16),
                  a6: (SFTextObjectImpl *)(v24 + 60));
                GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v25);
              }
              else
              {
                GFxStyledText::AppendString(
                  this: v21,
                  pwch: v206,
                  a3: v20,
                  a4: 1,
                  a5: (struct GFxTextFormat *)((char *)&v215.m_ShaderRenderState.m_VertexUsage + 4),
                  a6: (SFTextObjectImpl *)&v215);
                GFxTextFormat::operator=(
                  this: (int)&v215.m_Name,
                  __that: (int)&v215.m_ShaderRenderState.m_VertexUsage + 4);
              }
            }
          }
        }
        goto LABEL_263;
      }
      GFxSGMLParser<wchar_t>::ParseStartElement(
        this: (int)v223,
        a2: (unsigned __int8 **)&v239,
        a3: (unsigned int *)&v238);
      v26 = (GMemoryHeap *)v238;
      v27 = GFxSGMLElementDesc::FindElem<wchar_t>(
              a1: (GFxValue::DisplayInfo *)v239,
              a2: v238,
              a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::elementsTable,
              a4: 13);
      v28 = (int)v27;
      v237 = v27;
      v252 = (GFxResourceId *)(v246 - 1);
      if ( v27 == nullptr || *((_BYTE *)v27 + 9) == 0 )
      {
        Length = GFxStyledText::GetLength(this: *(GFxStyledText **)&adr[0].std::_Num_base);
        v47 = GFxSGMLStackElemDesc<wchar_t>::GFxSGMLStackElemDesc<wchar_t>(
                this: &v191,
                a2: (struct GMemoryHeap *)v215.m_pVMTKeyValues,
                a3: v239,
                a4: v26,
                a5: v28,
                a6: 0);
        GArrayDataDH<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::PushBack(
          this: (int)&v245,
          a2: (int)v47);
        v193.__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
        GFxTextParagraphFormat::FreeTabStops(this: &v193);
        GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v193);
        GFxTextFormat::~GFxTextFormat(this: &v192);
        v48 = v245;
        v49 = (int)&v245[21 * v246 - 21];
        *(_DWORD *)(v49 + 12) = Length;
        v50 = v49 + 16;
        v219 = v49 + 16;
        if ( (int)v252 < 0 )
        {
          GFxTextFormat::operator=(this: v49 + 16, __that: (int)&v215.m_ShaderRenderState.m_VertexUsage + 4);
          v175 = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)&v215;
        }
        else
        {
          v258 = (struct GFxTextParagraphFormat *)&v48[21 * (_DWORD)v252];
          GFxTextFormat::operator=(this: v49 + 16, __that: (int)v258 + 16);
          v175 = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)((char *)v258 + 60);
        }
        v51 = v49 + 60;
        v253 = (GFxResourceId *)v51;
        GFxTextParagraphFormat::operator=(
          this: v51,
          result: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v175);
        if ( v28 != 0 )
        {
          v56 = *(_DWORD *)(v28 + 4);
          switch ( v56 )
          {
            case 0:
              if ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                     this: (int)v223,
                     a2: (unsigned __int8 **)&v220,
                     a3: (unsigned int *)&v222) != 0 )
              {
                v56 = *(_DWORD *)&adr[0].std::_Num_base;
                do
                {
                  v57 = GFxSGMLElementDesc::FindElem<wchar_t>(
                          a1: v220,
                          a2: v222,
                          a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                          a4: 27);
                  if ( v57 != nullptr
                    && GFxSGMLParser<wchar_t>::GetNextAttributeValue(
                         this: (int)v223,
                         a2: (unsigned __int8 **)&purl,
                         a3: (int *)&urlSz) != 0
                    && v57[1] == (const char *)20 )
                  {
                    GFxTextFormat::SetUrl(
                      this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)v50,
                      purl,
                      urlSz);
                    *(_BYTE *)(v56 + 32) |= 1u;
                  }
                }
                while ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                          this: (int)v223,
                          a2: (unsigned __int8 **)&v220,
                          a3: (unsigned int *)&v222) != 0 );
              }
              if ( a7 == nullptr )
                goto LABEL_224;
              GFxTextStyleManager::GetStyle(this: a7, type: nullptr, name: (int)&stru_102A0968.m_Size);
              if ( v58 != 0 )
              {
                v59 = GFxTextFormat::Merge(a1: v50, a2: v56, a3: (int)&v190, fmt: v58);
                GFxTextFormat::operator=(this: v50, __that: v59);
                GFxTextFormat::~GFxTextFormat(this: &v190);
              }
              GFxTextFormat::IsUrlSet(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v50);
              if ( v60 == 0 )
                goto LABEL_224;
              GFxTextStyleManager::GetStyle(this: a7, type: nullptr, name: (int)"a:link");
              if ( v61 == 0 )
                goto LABEL_224;
              v62 = GFxTextFormat::Merge(a1: v50, a2: v56, a3: (int)&v184, fmt: v61);
              GFxTextFormat::operator=(this: v50, __that: v62);
              GFxTextFormat::~GFxTextFormat(this: &v184);
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            case 1:
              GFxTextFormat::SetBold(this: (GFxTextFormat *)v50, a2: true);
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            case 3:
              while ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                        this: (int)v223,
                        a2: (unsigned __int8 **)&v215.m_ChangeID,
                        a3: (unsigned int *)&v215.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.y) != 0 )
              {
                v90 = GFxSGMLElementDesc::FindElem<wchar_t>(
                        a1: (GFxValue::DisplayInfo *)v215.m_ChangeID,
                        a2: SLODWORD(v215.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.y),
                        a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                        a4: 27);
                if ( v90 != nullptr
                  && GFxSGMLParser<wchar_t>::GetNextAttributeValue(
                       this: (int)v223,
                       a2: (unsigned __int8 **)&pfontList,
                       a3: (int *)&fontListSz) != 0 )
                {
                  switch ( (unsigned int)v90[1] )
                  {
                    case 0xDu:
                      if ( LOWORD(pfontList->__vftable) == 35
                        && GFxSGMLParser<wchar_t>::ParseHexInt(
                             a1: v201,
                             a2: (wchar_t *)&pfontList->__vftable + 1,
                             a3: (unsigned int)fontListSz - 1) != 0 )
                      {
                        GFxTextFormat::SetAlpha(this: (GFxTextFormat *)v50, alpha: v201[0]);
                      }
                      break;
                    case 0x11u:
                      if ( LOWORD(pfontList->__vftable) == 35
                        && GFxSGMLParser<wchar_t>::ParseHexInt(
                             a1: &v198,
                             a2: (wchar_t *)&pfontList->__vftable + 1,
                             a3: (unsigned int)fontListSz - 1) != 0 )
                      {
                        *(_DWORD *)(v50 + 32) ^= (v198 ^ *(_DWORD *)(v50 + 32)) & 0xFFFFFF;
                        *(_WORD *)(v50 + 42) |= 1u;
                      }
                      break;
                    case 0x12u:
                      GFxTextFormat::SetFontList(
                        this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)v50,
                        pfontList,
                        fontListSz);
                      break;
                    case 0x18u:
                      if ( GFxSGMLParser<wchar_t>::ParseInt(
                             a1: &v195,
                             a2: (unsigned __int16 *)pfontList,
                             a3: (unsigned int)fontListSz) != 0
                        && v195 >= 0 )
                      {
                        if ( v195 != 0 )
                        {
                          GFxTextFormat::SetKerning(this: (GFxTextFormat *)v50, a2: true);
                        }
                        else
                        {
                          *(_BYTE *)(v50 + 40) &= ~8u;
                          *(_WORD *)(v50 + 42) &= ~0x80u;
                        }
                      }
                      break;
                    case 0x1Bu:
                      if ( GFxSGMLParser<wchar_t>::ParseFloat(
                             a1: &v209,
                             a2: (unsigned __int16 *)pfontList,
                             a3: (int)fontListSz) != 0 )
                      {
                        v91 = (int)(v209 * 20.0);
                        *(_WORD *)(v50 + 42) |= 2u;
                        *(_WORD *)(v50 + 36) = v91;
                      }
                      break;
                    case 0x1Eu:
                      if ( GFxSGMLParser<wchar_t>::ParseInt(
                             a1: &v215.m_Reflectivity.y,
                             a2: (unsigned __int16 *)pfontList,
                             a3: (unsigned int)fontListSz) != 0
                        && v215.m_Reflectivity.y >= 0.0 )
                      {
                        y_low = (float)SLODWORD(v215.m_Reflectivity.y);
                        GFxTextFormat::SetFontSize(
                          this: (_WORD *)v50,
                          result: (const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)LODWORD(y_low));
                      }
                      break;
                    default:
                      break;
                  }
                }
              }
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            case 4:
              GFxTextFormat::SetItalic(this: (GFxTextFormat *)v50, a2: true);
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            case 6:
              *(_WORD *)(v51 + 22) |= 0x8080u;
              GFxStyledText::GetLastParagraph(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
              v64 = (GFxFontMap::MapEntry *)v63;
              if ( v63 != nullptr )
              {
                if ( GFxTextParagraph::GetLength(this: v63) != 0 )
                {
                  if ( a5 != 0 )
                  {
                    v66 = *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base;
                    GFxStyledText::NewLineStr(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base);
                    GFxStyledText::AppendString(
                      this: v66,
                      a2: (const char *)v50,
                      putf8String: v67,
                      stringSize: 1u,
                      a5: 1,
                      a6: (struct GFxTextFormat *)&v215.m_Name,
                      a7: (SFTextObjectImpl *)&v215);
                  }
                  GFxStyledText::GetLastParagraph(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
                  v64 = v68;
                }
                GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
                GFxTextParagraph::SetFormat(this: v64, pallocator: v69, pallocator_4: (GRefCountNTSImpl *)v51);
              }
              else
              {
                GFxStyledText::AppendNewParagraph(
                  a1: *(int *)&adr[0].std::_Num_base,
                  this: (SFTextObjectImpl *)v51,
                  pdefParaFmt: v177);
                v64 = v65;
              }
              if ( a7 == nullptr )
                goto LABEL_224;
              Style = GFxTextStyleManager::GetStyle(a1: a7, a2: 0, a3: v239, a4: v238);
              v254 = (GFxResourceId *)Style;
              if ( Style == 0 )
                goto LABEL_224;
              GFxTextParagraphFormat::Merge(
                this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v51,
                a2: (GFxTextParagraphFormat *)((char *)&v193.m_ShaderRenderState.m_VertexUsage + 4),
                a3: Style + 44);
              GFxTextParagraphFormat::operator=(this: v51, result: v71);
              HIDWORD(v193.m_ShaderRenderState.m_VertexUsage) = &GFxTextParagraphFormat::`vftable';
              GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)((char *)&v193.m_ShaderRenderState.m_VertexUsage
                                                                     + 4));
              GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v193.m_ShaderRenderState.m_VertexUsage + 1);
              v72 = GFxTextFormat::Merge(a1: v50, a2: (int)v64, a3: (int)&v186, fmt: (int)v254);
              GFxTextFormat::operator=(this: v50, __that: v72);
              GFxTextFormat::~GFxTextFormat(this: &v186);
              GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
              GFxTextParagraph::SetFormat(this: v64, pallocator: v73, pallocator_4: (GRefCountNTSImpl *)v51);
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            case 7:
              v74 = *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base;
              GFxStyledText::GetLastParagraph(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
              v255 = v75;
              if ( v75 != nullptr )
              {
                if ( v241 == 0 )
                  goto LABEL_123;
                if ( a5 != 0 )
                {
                  GFxStyledText::NewLineStr(this: v74);
                  GFxStyledText::AppendString(
                    this: v74,
                    a2: (const char *)v50,
                    putf8String: v77,
                    stringSize: 1u,
                    a5: 1,
                    a6: (struct GFxTextFormat *)&v215.m_Name,
                    a7: (SFTextObjectImpl *)&v215);
                }
                GFxStyledText::GetLastParagraph(this: (SFTextObjectImpl *)v74);
              }
              else
              {
                GFxStyledText::AppendNewParagraph(a1: (int)v74, this: (SFTextObjectImpl *)&v215, pdefParaFmt: v177);
              }
              v255 = v76;
LABEL_123:
              if ( a7 != nullptr )
              {
                v78 = GFxTextStyleManager::GetStyle(a1: a7, a2: 0, a3: v239, a4: v238);
                v79 = v78;
                if ( v78 != 0 )
                {
                  GFxTextParagraphFormat::Merge(
                    this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v51,
                    a2: (GFxTextParagraphFormat *)&v193.m_VMTIncludes.m_Size,
                    a3: v78 + 44);
                  GFxTextParagraphFormat::operator=(this: v51, result: v80);
                  v193.m_VMTIncludes.m_Size = (int)&GFxTextParagraphFormat::`vftable';
                  GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v193.m_VMTIncludes.m_Size);
                  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v193.m_VMTIncludes.m_Size);
                  v81 = GFxTextFormat::Merge(a1: v50, a2: v79, a3: (int)&v189, fmt: v79);
                  GFxTextFormat::operator=(this: v50, __that: v81);
                  GFxTextFormat::~GFxTextFormat(this: &v189);
                }
              }
              while ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                        this: (int)v223,
                        a2: (unsigned __int8 **)&v216,
                        a3: (unsigned int *)&v215.m_QueueFriendlyVersion) != 0 )
              {
                v82 = GFxSGMLElementDesc::FindElem<wchar_t>(
                        a1: v216,
                        a2: (int)v215.m_QueueFriendlyVersion.__vftable,
                        a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                        a4: 27);
                if ( v82 != nullptr
                  && GFxSGMLParser<wchar_t>::GetNextAttributeValue(
                       this: (int)v223,
                       a2: (unsigned __int8 **)&v218,
                       a3: (int *)&v215.m_Reflectivity.z) != 0 )
                {
                  v83 = v82[1];
                  if ( v83 == (const char *)12 )
                  {
                    v87 = GFxSGMLElementDesc::FindElem<wchar_t>(
                            a1: v218,
                            a2: SLODWORD(v215.m_Reflectivity.z),
                            a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                            a4: 27);
                    if ( v87 != nullptr )
                    {
                      switch ( (unsigned int)v87[1] )
                      {
                        case '#':
                          v88 = *(_WORD *)(v51 + 22) & 0xF9FE | 1;
                          goto LABEL_140;
                        case '$':
                          *(_WORD *)(v51 + 22) = *(_WORD *)(v51 + 22) & 0xF9FE | 0x201;
                          break;
                        case '%':
                          *(_WORD *)(v51 + 22) |= 0x601u;
                          break;
                        case '&':
                          v88 = *(_WORD *)(v51 + 22) & 0xF9FE | 0x401;
LABEL_140:
                          *(_WORD *)(v51 + 22) = v88;
                          break;
                        default:
                          break;
                      }
                    }
                  }
                  else if ( v83 == (const char *)16 && a7 != nullptr )
                  {
                    v84 = GFxTextStyleManager::GetStyle(a1: a7, a2: 1, a3: v218, a4: LODWORD(v215.m_Reflectivity.z));
                    if ( v84 != 0 )
                    {
                      GFxTextParagraphFormat::Merge(
                        this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v51,
                        a2: (GFxTextParagraphFormat *)&v193.m_Reflectivity.z,
                        a3: v84 + 44);
                      GFxTextParagraphFormat::operator=(this: v51, result: v85);
                      LODWORD(v193.m_Reflectivity.z) = &GFxTextParagraphFormat::`vftable';
                      GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v193.m_Reflectivity.z);
                      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v193.m_Reflectivity.z);
                      v86 = GFxTextFormat::Merge(a1: v50, a2: v84, a3: (int)&v187, fmt: v84);
                      GFxTextFormat::operator=(this: v50, __that: v86);
                      GFxTextFormat::~GFxTextFormat(this: &v187);
                    }
                  }
                }
              }
              if ( GFxTextParagraph::GetLength(this: v255) == 0 )
              {
                GFxStyledText::GetAllocator(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
                GFxTextParagraph::SetFormat(
                  this: (GFxFontMap::MapEntry *)v255,
                  pallocator: v89,
                  pallocator_4: (GRefCountNTSImpl *)v51);
              }
              ++v241;
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            case 8:
              while ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                        this: (int)v223,
                        a2: (unsigned __int8 **)&v215.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.z,
                        a3: (unsigned int *)&v217) != 0 )
              {
                v108 = GFxSGMLElementDesc::FindElem<wchar_t>(
                         a1: (GFxValue::DisplayInfo *)LODWORD(v215.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.z),
                         a2: v217,
                         a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                         a4: 27);
                if ( v108 != nullptr
                  && GFxSGMLParser<wchar_t>::GetNextAttributeValue(this: (int)v223, a2: &v210, a3: &v212) != 0
                  && v108[1] == (const char *)16
                  && a7 != nullptr )
                {
                  v109 = GFxTextStyleManager::GetStyle(a1: a7, a2: 1, a3: v210, a4: v212);
                  if ( v109 != 0 )
                  {
                    v110 = GFxTextFormat::Merge(a1: v50, a2: (int)a7, a3: (int)&v185, fmt: v109);
                    GFxTextFormat::operator=(this: v50, __that: v110);
                    GFxTextFormat::~GFxTextFormat(this: &v185);
                    GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
                  }
                }
              }
              goto LABEL_224;
            case 10:
              if ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                     this: (int)v223,
                     a2: (unsigned __int8 **)&v221,
                     a3: (unsigned int *)&v215.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion) == 0 )
                goto LABEL_224;
              break;
            case 11:
              GFxTextFormat::SetUnderline(this: (GFxTextFormat *)v50, a2: true);
              GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
              goto LABEL_263;
            default:
              goto LABEL_224;
          }
          do
          {
            v92 = GFxSGMLElementDesc::FindElem<wchar_t>(
                    a1: v221,
                    a2: SLODWORD(v215.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion),
                    a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                    a4: 27);
            if ( v92 != nullptr
              && GFxSGMLParser<wchar_t>::GetNextAttributeValue(
                   this: (int)v223,
                   a2: (unsigned __int8 **)&c,
                   a3: (int *)&v243) != 0 )
            {
              switch ( (unsigned int)v92[1] )
              {
                case 0xFu:
                  if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v197, a2: (unsigned __int16 *)c, a3: v243) != 0 )
                  {
                    v95 = v197;
                    if ( v197 >= 0 )
                    {
                      HIWORD(v253[5].Id) |= 2u;
                      LOWORD(v253[3].Id) = v95;
                    }
                  }
                  break;
                case 0x17u:
                  if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v207, a2: (unsigned __int16 *)c, a3: v243) != 0 )
                  {
                    v94 = v207;
                    HIWORD(v253[5].Id) |= 4u;
                    HIWORD(v253[3].Id) = v94;
                  }
                  break;
                case 0x19u:
                  if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v205, a2: (unsigned __int16 *)c, a3: v243) != 0 )
                  {
                    v96 = v205;
                    HIWORD(v253[5].Id) |= 8u;
                    LOWORD(v253[4].Id) = v96;
                  }
                  break;
                case 0x1Au:
                  if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v199, a2: (unsigned __int16 *)c, a3: v243) != 0 )
                  {
                    v97 = v199;
                    if ( v199 >= 0 )
                    {
                      HIWORD(v253[5].Id) |= 0x10u;
                      HIWORD(v253[4].Id) = v97;
                    }
                  }
                  break;
                case 0x1Cu:
                  if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v203, a2: (unsigned __int16 *)c, a3: v243) != 0 )
                  {
                    v98 = v203;
                    if ( v203 >= 0 )
                    {
                      HIWORD(v253[5].Id) |= 0x20u;
                      LOWORD(v253[5].Id) = v98;
                    }
                  }
                  break;
                case 0x20u:
                  v99 = v243;
                  v100 = c;
                  for ( i = 0; i < v99; ++i )
                  {
                    if ( !GFxSGMLCharIter<wchar_t>::IsSpace(c: v93, ca: *(_WORD *)(v100 + 2 * i)) )
                      break;
                  }
                  if ( *(_WORD *)(v100 + 2 * i) == 91 )
                    ++i;
                  v102 = 1;
                  for ( j = i; j < v99; ++j )
                  {
                    v104 = *(unsigned __int16 *)(v100 + 2 * j);
                    if ( v104 == 93 )
                      break;
                    if ( v104 == 44 )
                      ++v102;
                  }
                  GFxTextParagraphFormat::AllocTabStops(this: (void **)v253, result: v102);
                  HIWORD(v253[5].Id) |= 0x40u;
                  v259 = nullptr;
                  while ( i < v99 )
                  {
                    if ( *(_WORD *)(c + 2 * i) == 93 )
                      break;
                    v105 = 0;
                    if ( i < v99 )
                    {
                      while ( GFxSGMLCharIter<wchar_t>::IsDigit((void *)c, ca: *(unsigned __int16 *)(c + 2 * i)) )
                      {
                        v106 = *(unsigned __int16 *)(c + 2 * i++);
                        v105 = v106 + 10 * v105 - 48;
                        if ( i >= v99 )
                          goto LABEL_207;
                      }
                      for ( ; i < v99; ++i )
                      {
                        if ( !GFxSGMLCharIter<wchar_t>::IsSpace(
                                c: (void *)*(unsigned __int16 *)(c + 2 * i),
                                ca: *(_WORD *)(c + 2 * i)) )
                          break;
                      }
                    }
LABEL_207:
                    GFxTextParagraphFormat::SetTabStopsElement(
                      this: (GFxTextParagraphFormat *)v253,
                      idx: (unsigned int)v259,
                      val: v105);
                    v259 = (struct GFxTextParagraphFormat *)((char *)v259 + 1);
                    if ( *(_WORD *)(c + 2 * i) == 44 )
                    {
                      if ( ++i >= v99 )
                        goto LABEL_214;
                      v107 = c;
                      while ( GFxSGMLCharIter<wchar_t>::IsSpace(
                                c: (void *)*(unsigned __int16 *)(v107 + 2 * i),
                                ca: *(_WORD *)(v107 + 2 * i)) )
                      {
                        if ( ++i >= v99 )
                          goto LABEL_214;
                      }
                    }
                  }
                  break;
                default:
                  break;
              }
            }
LABEL_214:
            ;
          }
          while ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                    this: (int)v223,
                    a2: (unsigned __int8 **)&v221,
                    a3: (unsigned int *)&v215.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion) != 0 );
          GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v219);
        }
        else if ( a7 != nullptr
               && (v52 = GFxTextStyleManager::GetStyle(a1: a7, a2: 0, a3: v239, a4: v238), v53 = v52, v52 != 0) )
        {
          GFxTextParagraphFormat::Merge(
            this: (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v51,
            a2: (GFxTextParagraphFormat *)&v193.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion,
            a3: v52 + 44);
          GFxTextParagraphFormat::operator=(this: v51, result: v54);
          LODWORD(v193.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.x) = &GFxTextParagraphFormat::`vftable';
          GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v193.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion);
          GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v193.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion);
          v55 = GFxTextFormat::Merge(a1: v50, a2: v53, a3: (int)&v183, fmt: v53);
          GFxTextFormat::operator=(this: v50, __that: v55);
          GFxTextFormat::~GFxTextFormat(this: &v183);
          GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
        }
        else
        {
LABEL_224:
          GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v50);
        }
        goto LABEL_263;
      }
      if ( v27[1] != (const char *)2 )
      {
        if ( v27[1] == (const char *)5 )
        {
          if ( a4 != 0 )
          {
            GFxStyledText::HTMLImageTagInfo::HTMLImageTagInfo(
              this: &v188,
              pheap: (wchar_t *)v215.m_pVMTKeyValues,
              a3: (int)v177,
              a4: v181,
              a5: v182);
            GArrayDataDH<GFxStyledText::HTMLImageTagInfo,GAllocatorDH<GFxStyledText::HTMLImageTagInfo,2>,GArrayDefaultPolicy>::PushBack(
              this: a4,
              a2: v29);
            GFxStyledText::HTMLImageTagInfo::~HTMLImageTagInfo(this: &v188);
            v30 = *(const void **)&adr[0].std::_Num_base;
            v31 = 44 * *(_DWORD *)(a4 + 4) + *(_DWORD *)a4 - 44;
            GFxStyledText::GetLastParagraph(this: *(SFTextObjectImpl **)&adr[0].std::_Num_base);
            v33 = v32;
            if ( v32 == 0 )
            {
              GFxStyledText::AppendNewParagraph(a1: (int)v30, this: (SFTextObjectImpl *)&v215, pdefParaFmt: v178);
              v33 = v34;
            }
            GFxTextFormat::GFxTextFormat(
              this: (GStringDH *)&v193.m_Name,
              result: (const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)((char *)&v215.m_ShaderRenderState.m_VertexUsage + 4),
              srcfmt_4: nullptr);
            *(_DWORD *)(v31 + 36) = *(_DWORD *)(v33 + 32);
            while ( GFxSGMLParser<wchar_t>::GetNextAttribute(
                      this: (int)v223,
                      a2: (unsigned __int8 **)&v215.m_QueueFriendlyVersion.m_pRealTimeVersion,
                      a3: (unsigned int *)&v215.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion) != 0 )
            {
              v35 = GFxSGMLElementDesc::FindElem<wchar_t>(
                      a1: (GFxValue::DisplayInfo *)v215.m_QueueFriendlyVersion.m_pRealTimeVersion,
                      a2: SLODWORD(v215.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.x),
                      a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                      a4: 27);
              if ( v35 != nullptr
                && GFxSGMLParser<wchar_t>::GetNextAttributeValue(
                     this: (int)v223,
                     a2: (unsigned __int8 **)&pstr,
                     a3: (int *)&v249) != 0 )
              {
                switch ( (unsigned int)v35[1] )
                {
                  case 0xCu:
                    v36 = GFxSGMLElementDesc::FindElem<wchar_t>(
                            a1: (GFxValue::DisplayInfo *)pstr,
                            a2: v249,
                            a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::attributesTable,
                            a4: 27);
                    if ( v36 != nullptr )
                    {
                      v37 = (int)(v36[1] - 14);
                      if ( v37 != 0 )
                      {
                        v38 = v37 - 21;
                        if ( v38 != 0 )
                        {
                          if ( v38 == 1 )
                            *(_BYTE *)(v31 + 40) = 1;
                        }
                        else
                        {
                          *(_BYTE *)(v31 + 40) = 2;
                        }
                      }
                      else
                      {
                        *(_BYTE *)(v31 + 40) = 0;
                      }
                    }
                    break;
                  case 0x13u:
                    if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v213, a2: (unsigned __int16 *)pstr, a3: v249) != 0
                      && v213 >= 0 )
                    {
                      *(_DWORD *)(v31 + 24) = 20 * v213;
                    }
                    break;
                  case 0x15u:
                    if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v194, a2: (unsigned __int16 *)pstr, a3: v249) != 0 )
                      *(_DWORD *)(v31 + 32) = 20 * v194;
                    break;
                  case 0x16u:
                    GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)(v31 + 12), (RGB888_t *)pstr, a3: v249);
                    break;
                  case 0x1Du:
                    GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)(v31 + 4), (RGB888_t *)pstr, a3: v249);
                    break;
                  case 0x21u:
                    if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v214, a2: (unsigned __int16 *)pstr, a3: v249) != 0 )
                      *(_DWORD *)(v31 + 28) = 20 * v214;
                    break;
                  case 0x22u:
                    if ( GFxSGMLParser<wchar_t>::ParseInt(a1: &v202, a2: (unsigned __int16 *)pstr, a3: v249) != 0
                      && v202 >= 0 )
                    {
                      *(_DWORD *)(v31 + 20) = 20 * v202;
                    }
                    break;
                  default:
                    break;
                }
              }
            }
            v39 = (char *)GRefCountBaseStatImpl<GRefCountNTSImpl,324>::operator new(sz: 0x50u, adr: v30);
            if ( v39 != nullptr )
              v40 = GFxTextHTMLImageTagDesc::GFxTextHTMLImageTagDesc(this: v39);
            else
              v40 = nullptr;
            GFxTextFormat::SetImageDesc(this: (GFxTextFormat *)&v193.m_Name, a2: (struct GFxTextHTMLImageTagDesc *)v40);
            *((_DWORD *)v40 + 6) = *(_DWORD *)(v31 + 20);
            *((_DWORD *)v40 + 7) = *(_DWORD *)(v31 + 24);
            *((_DWORD *)v40 + 16) = *(_DWORD *)(v31 + 28);
            *((_DWORD *)v40 + 17) = *(_DWORD *)(v31 + 32);
            GString::operator=(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v40 + 56),
              src: (_DWORD *)(v31 + 4),
              a3: (int)v178);
            GString::operator=(
              this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v40 + 3,
              src: (_DWORD *)(v31 + 12),
              a3: v179);
            v40[76] = *(_BYTE *)(v31 + 40);
            ++*((_DWORD *)v40 + 1);
            if ( *(_DWORD *)v31 != 0 )
              GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)v31);
            *(_DWORD *)v31 = v40;
            if ( (int)v252 < 0 )
            {
              v41 = (char *)&v215.m_ShaderRenderState.m_VertexUsage + 4;
              v42 = &v215;
            }
            else
            {
              v41 = (char *)&v245[21 * (_DWORD)v252 + 4];
              v42 = (CMaterial *)&v245[21 * (_DWORD)v252 + 15];
            }
            GFxTextFormat::IsUrlSet(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)v41);
            if ( v43 != 0 )
              GFxTextFormat::SetUrl(this: (GFxTextFormat *)&v193.m_Name, src: (struct GString *)v41 + 4);
            v174 = (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)v42;
            v44 = *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base;
            GFxStyledText::AppendString(
              this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base,
              a2: v40,
              putf8String: " ",
              stringSize: 1u,
              a5: 1,
              a6: (struct GFxTextFormat *)&v193.m_Name,
              a7: (SFTextObjectImpl *)v174);
            v45 = *((GRefCountNTSImpl **)v41 + 6);
            if ( v45 != nullptr )
              GRefCountNTSImpl::Release(this: v45);
            *((_DWORD *)v41 + 6) = 0;
            *((_WORD *)v41 + 21) |= 0x200u;
            if ( v215.m_ShaderRenderState.m_Flags != 0 )
              GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v215.m_ShaderRenderState.m_Flags);
            WORD1(v215.m_ShaderRenderState.m_VertexUsage) |= 0x200u;
            v215.m_ShaderRenderState.m_Flags = 0;
            GFxStyledText::SetDefaultTextFormat(this: v44, defaultTextFmt: (int)v41);
            GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v40);
            GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v193.m_Name);
          }
        }
        else if ( v27[1] == (const char *)9 )
        {
          GFxStyledText::AppendString(
            this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base,
            a2: (const char *)a4,
            putf8String: "\t",
            stringSize: 1u,
            a5: 1,
            a6: *(struct GFxTextFormat **)(*(_DWORD *)&adr[0].std::_Num_base + 28),
            a7: *(SFTextObjectImpl **)(*(_DWORD *)&adr[0].std::_Num_base + 24));
        }
        goto LABEL_263;
      }
      if ( a5 != 0 )
        goto LABEL_262;
      goto LABEL_263;
    }
    v111 = 0;
    v234 = 0;
    v236 = 0;
    if ( Next == 4 )
    {
      if ( v246 != 0 )
        v111 = (int)&v245[21 * v246 - 21];
      GFxSGMLParser<wchar_t>::ParseEndElement(this: (int)v223, a2: (unsigned __int8 **)&v234, a3: (unsigned int *)&v236);
      v112 = (GFxValue::DisplayInfo *)v234;
      v113 = v236;
    }
    else
    {
      if ( v237 != nullptr && *((_BYTE *)v237 + 9) != 0 || v246 == 0 )
        goto LABEL_263;
      v112 = (GFxValue::DisplayInfo *)v245[21 * v246 - 21];
      v113 = v245[21 * v246 - 20];
      v111 = (int)&v245[21 * v246 - 21];
      v234 = (int)v112;
      v236 = v113;
    }
    if ( v111 != 0 )
    {
      if ( GFxSGMLCharIter<wchar_t>::StrCompare(
             a1: (int)v112,
             a2: v113,
             a3: *(wchar_t **)v111,
             charCode: *(CFileSystemPassThru **)(v111 + 4)) != 0 )
      {
        v114 = GFxSGMLElementDesc::FindElem<wchar_t>(
                 a1: v112,
                 a2: v113,
                 a3: (int)&`GFxStyledText::ParseHtmlImpl<wchar_t>'::`2'::elementsTable,
                 a4: 13);
        v115 = v114;
        if ( v114 == nullptr )
          goto LABEL_263;
        if ( v241 == 0 )
          goto LABEL_263;
        v116 = v114[1];
        if ( v116 != (const char *)7 && v116 != (const char *)6 )
          goto LABEL_263;
        if ( v246 == 0 )
          goto LABEL_263;
        v117 = v246;
        while ( 1 )
        {
          v118 = v245[21 * v117 - 19];
          if ( v118 != 0 && v115[1] == *(const char **)(v118 + 4) )
            break;
          GArrayDataDH<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Resize(
            this: (int)&v245,
            a2: (MaterialVarFlags_t)(v117 - 1));
          v117 = v246;
          if ( v246 == 0 )
            goto LABEL_263;
        }
        if ( v117 == 0 )
          goto LABEL_263;
        v111 = (int)&v245[21 * v246 - 21];
      }
      v119 = *(unsigned __int16 *)(v111 + 82);
      v120 = *(_DWORD *)(v111 + 8);
      v121 = *(_DWORD *)(v111 + 12);
      v18 = (const char *)((v119 >> 11) & 3);
      v256 = BYTE1(v119) & 1;
      v237 = (const char **)v120;
      GArrayDataDH<GFxSGMLStackElemDesc<wchar_t>,GAllocatorDH<GFxSGMLStackElemDesc<wchar_t>,2>,GArrayDefaultPolicy>::Resize(
        this: (int)&v245,
        a2: (MaterialVarFlags_t)(v246 - 1));
      if ( v120 != 0 )
      {
        v122 = *(_DWORD *)(v120 + 4) - 6;
        if ( v122 != 0 )
        {
          if ( v122 != 1 )
            goto LABEL_263;
          --v241;
          if ( v257 == (struct GFxTextParagraphFormat *)32773 )
            goto LABEL_263;
        }
        if ( a5 == 0 )
          goto LABEL_263;
LABEL_262:
        v126 = *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base;
        GFxStyledText::NewLineStr(this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base);
        GFxStyledText::AppendString(
          this: v126,
          a2: v18,
          putf8String: v127,
          stringSize: 1u,
          a5: 1,
          a6: (struct GFxTextFormat *)&v215.m_Name,
          a7: (SFTextObjectImpl *)&v215);
        goto LABEL_263;
      }
      if ( a7 != nullptr && v256 != 0 )
      {
        if ( --v18 != nullptr )
        {
          if ( v18 == (const char *)1 )
          {
            v123 = *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base;
            v124 = (const char *)GFxStyledText::GetLength(this: *(GFxStyledText **)&adr[0].std::_Num_base);
            if ( a5 != 0 )
            {
              GFxStyledText::NewLineStr(this: v123);
              GFxStyledText::AppendString(
                this: v123,
                a2: v124,
                putf8String: v125,
                stringSize: 1u,
                a5: 1,
                a6: (struct GFxTextFormat *)&v215.m_Name,
                a7: (SFTextObjectImpl *)&v215);
            }
            GFxStyledText::Remove(this: (SFTextObjectImpl *)v123, a2: v121, Length: (unsigned int)&v124[-v121]);
          }
          goto LABEL_263;
        }
        if ( a5 != 0 )
          goto LABEL_262;
      }
    }
LABEL_263:
    Next = GFxSGMLParser<wchar_t>::GetNext(this: (int)v223);
    v257 = (struct GFxTextParagraphFormat *)Next;
  }
  while ( Next != 0x8000 );
  if ( v246 != 0 )
  {
    v128 = *(_DWORD *)&adr[0].std::_Num_base;
    v129 = (int)&v245[21 * v246 - 21];
    v130 = v129 + 16;
    GFxStyledText::SetDefaultTextFormat(
      this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base,
      defaultTextFmt: v129 + 16);
    if ( *(_DWORD *)(v128 + 8) == 0 )
    {
      v131 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v128);
      v132 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v131->m_pfnProxied) + 40);
      v208 = 324;
      v133 = (GStringDH *)v132(a1: v131, a2: 80, a3: &v208);
      if ( v133 != nullptr )
        v134 = GFxTextAllocator::GFxTextAllocator(this: v133, result: v131, flags: 0);
      else
        v134 = nullptr;
      v135 = *(GRefCountNTSImpl **)(v128 + 8);
      if ( v135 != nullptr )
        GRefCountNTSImpl::Release(this: v135);
      *(_DWORD *)(v128 + 8) = v134;
      v130 = v129 + 16;
    }
    ParagraphFormat = GFxTextAllocator::AllocateParagraphFormat(
                        this: *(CMaterial **)(v128 + 8),
                        srcfmt: (GRefCountNTSImpl *)(v129 + 60),
                        pfmt: (int)v177,
                        a4: v181,
                        a5: (ImageFormat)v182);
    v137 = *(GRefCountNTSImpl **)(v128 + 24);
    v138 = ParagraphFormat;
    if ( v137 != nullptr )
      GRefCountNTSImpl::Release(this: v137);
    *(_DWORD *)(v128 + 24) = v138;
    GFxTextFormat::operator=(this: (int)&v215.m_Name, __that: v130);
    goto LABEL_285;
  }
LABEL_275:
  v128 = *(_DWORD *)&adr[0].std::_Num_base;
  GFxStyledText::SetDefaultTextFormat(
    this: *(CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)&adr[0].std::_Num_base,
    defaultTextFmt: (int)&v215.m_ShaderRenderState.m_VertexUsage + 4);
  if ( *(_DWORD *)(v128 + 8) == 0 )
  {
    v139 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v128);
    v140 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v139->m_pfnProxied) + 40);
    v232 = 324;
    v141 = (GStringDH *)v140(a1: v139, a2: 80, a3: &v232);
    if ( v141 != nullptr )
      v142 = GFxTextAllocator::GFxTextAllocator(this: v141, result: v139, flags: 0);
    else
      v142 = nullptr;
    v143 = *(GRefCountNTSImpl **)(v128 + 8);
    if ( v143 != nullptr )
      GRefCountNTSImpl::Release(this: v143);
    *(_DWORD *)(v128 + 8) = v142;
  }
  v144 = GFxTextAllocator::AllocateParagraphFormat(
           this: *(CMaterial **)(v128 + 8),
           srcfmt: (GRefCountNTSImpl *)&v215,
           pfmt: (int)v177,
           a4: v181,
           a5: (ImageFormat)v182);
  v145 = *(GRefCountNTSImpl **)(v128 + 24);
  v146 = v144;
  if ( v145 != nullptr )
    GRefCountNTSImpl::Release(this: v145);
  *(_DWORD *)(v128 + 24) = v146;
LABEL_285:
  v147 = *(_DWORD *)(v128 + 16);
  v148 = v147 - 1;
  if ( v147 - 1 >= 0 && v148 < v147 && (v149 = *(GFxTextParagraph **)(*(_DWORD *)(v128 + 12) + 4 * v148)) != nullptr
    || (GFxStyledText::AppendNewParagraph(a1: v128, this: nullptr, pdefParaFmt: v180), v149 != nullptr) )
  {
    pObject = v149[1].pObject;
    if ( pObject == nullptr
      || ((v151 = (char *)&pObject[-1].pImpl + 3, v149->pObject == nullptr) || v151 >= (char *)pObject
        ? (v152 = nullptr)
        : (v152 = (unsigned __int16 *)v149->pObject + (_DWORD)v151),
          (v153 = *v152) != 13 && v153 != 10) )
    {
      GFxTextParagraph::AppendTermNull(
        this: v149,
        result: *(GFxFontMap **)(v128 + 8),
        a3: *(const struct GFxTextFormat **)(v128 + 28));
    }
  }
  v154 = *(_DWORD *)(v128 + 16);
  v155 = v154 - 1;
  if ( v154 - 1 >= 0 && v155 < v154 )
  {
    v156 = *(int **)(*(_DWORD *)(v128 + 12) + 4 * v155);
    if ( v156 != nullptr )
    {
      v157 = v156[1];
      if ( v157 == 0 )
        goto LABEL_308;
      v158 = *v156;
      v159 = v157 - 1;
      if ( v158 != 0 && v159 < v157 )
        v160 = (_WORD *)(v158 + 2 * v159);
      else
        v160 = nullptr;
      if ( *v160 == 0 )
        --v157;
      if ( v157 == 0 )
      {
LABEL_308:
        for ( k = *(_DWORD *)(v128 + 16); ; k = v232 )
        {
          v162 = k - 1;
          v232 = v162;
          if ( v162 < 0 || v162 >= *(_DWORD *)(v128 + 16) )
            break;
          v163 = *(_DWORD **)(*(_DWORD *)(v128 + 12) + 4 * v162);
          v164 = v163[1];
          if ( v164 != 0 )
          {
            v165 = v164 - 1;
            if ( *v163 != 0 && v165 < v164 )
              v166 = (_WORD *)(*v163 + 2 * v165);
            else
              v166 = nullptr;
            if ( *v166 == 0 )
              --v164;
          }
          if ( v164 > 1 )
            break;
          if ( *(_DWORD *)(v128 + 8) == 0 )
          {
            v167 = (CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v128);
            v168 = *(int (__thiscall **)(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *, int, int *))(LODWORD(v167->m_pfnProxied) + 40);
            v204 = 324;
            v169 = (GStringDH *)v168(a1: v167, a2: 80, a3: &v204);
            if ( v169 != nullptr )
              v170 = GFxTextAllocator::GFxTextAllocator(this: v169, result: v167, flags: 0);
            else
              v170 = nullptr;
            v171 = *(GRefCountNTSImpl **)(v128 + 8);
            if ( v171 != nullptr )
              GRefCountNTSImpl::Release(this: v171);
            *(_DWORD *)(v128 + 8) = v170;
          }
          GFxTextParagraph::SetTextFormat(
            this: (int)v163,
            pallocator: *(CMaterial **)(v128 + 8),
            fmt_4: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v215.m_Name,
            startPos: 0,
            length: 0xFFFFFFFF);
        }
      }
    }
  }
  GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v215.m_Name);
  v215.__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
  GFxTextParagraphFormat::FreeTabStops(this: &v215);
  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v215);
  GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)((char *)&v215.m_ShaderRenderState.m_VertexUsage + 4));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v228);
  v172 = (CMaterial *)&v245[21 * v246 - 6];
  if ( v246 != 0 )
  {
    for ( m = v246; m != 0; --m )
    {
      v172->__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: v172);
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)v172);
      GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v172[-1].m_Reflectivity);
      v172 = (CMaterial *)((char *)v172 - 84);
    }
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v245);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101677B0
// Name: public: virtual GFxStyledText::~GFxStyledText(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxStyledText::~GFxStyledText(int a1@<ecx>, _DWORD *a2@<edi>)
{
  IShaderAPI *v3; // ecx
  GRefCountNTSImpl *v4; // ecx
  GRefCountNTSImpl *v5; // ecx

  *(_DWORD *)a1 = &GFxStyledText::`vftable';
  GFxStyledText::Clear(this: a1);
  v3 = *(IShaderAPI **)(a1 + 28);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *(GRefCountNTSImpl **)(a1 + 24);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  GConstructorMov<GFxStyledText::ParagraphPtrWrapper>::DestructArray(
    a1: a2,
    count: *(_DWORD *)(a1 + 12),
    counta: *(_DWORD *)(a1 + 16));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(a1 + 12));
  v5 = *(GRefCountNTSImpl **)(a1 + 8);
  if ( v5 != nullptr )
    GRefCountNTSImpl::Release(this: v5);
  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)a1);
}

//------------------------------------------------------------------------------
// Address: 0x10167840
// Name: public: class GFxStyledText __near * GFxStyledText::CopyStyledText(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
SFTextObjectImpl *__userpurge GFxStyledText::CopyStyledText@<eax>(
        SFTextObjectImpl *this@<ecx>,
        int a2@<ebx>,
        const char *startPos,
        const struct GFxTextParagraph *endPos)
{
  CMaterial *v5; // eax
  CMaterial *v6; // esi
  volatile int m_value; // ecx
  int (__thiscall *v8)(volatile int, int, int *); // eax
  CUtlMemory<GFxValue,int> *v9; // eax
  SFTextObjectImpl *v10; // eax
  SFTextObjectImpl *v11; // esi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-4h] BYREF

  GFxStyledText::GetAllocator(this);
  v6 = v5;
  m_value = v5->m_RefCount.m_value;
  v8 = *(int (__thiscall **)(volatile int, int, int *))(*(_DWORD *)m_value + 40);
  v14 = 324;
  v9 = (CUtlMemory<GFxValue,int> *)v8(a1: m_value, a2: 36, a3: &v14);
  if ( v9 != nullptr )
  {
    GFxStyledText::GFxStyledText(this: v9, pallocator: v6, pallocator_4: v13);
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  GFxStyledText::CopyStyledText(
    (GFxStyledText *)this,
    a2,
    a3: (int)this,
    a4: (int)v11,
    a5: v11,
    indexInPara: startPos,
    remainedLen: endPos);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101678A0
// Name: protected: bool GFxStyledText::ParseHtml(char const __near *,unsigned int,class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near *,bool,bool,class GFxTextStyleManager const __near *,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStyledText::ParseHtml(
        const struct GFxTextParagraphFormat **this,
        int a2,
        unsigned int htmlSize,
        int a4,
        char multiline,
        char condenseWhite,
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *a7,
        int a8,
        struct GFxTextParagraphFormat *a9)
{
  wchar_t *v10; // esi
  GFxResourceId *v11; // eax
  char v12; // bl
  int v14; // [esp+Ch] [ebp-4h] BYREF

  v14 = 324;
  v10 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * htmlSize + 2, a3: &v14);
  v11 = (GFxResourceId *)GUTF8Util::DecodeString(
                           pbegin: v10,
                           putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)a2,
                           length: htmlSize);
  v12 = GFxStyledText::ParseHtmlImpl<wchar_t>(this, a2: v10, a3: v11, a4, a5: multiline, a6: condenseWhite, a7, a8, a9);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10167920
// Name: protected: bool GFxStyledText::ParseHtml(wchar_t const __near *,unsigned int,class GArrayDH<struct GFxStyledText::HTMLImageTagInfo,2,struct GArrayDefaultPolicy> __near *,bool,bool,class GFxTextStyleManager const __near *,class GFxTextFormat const __near *,class GFxTextParagraphFormat const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStyledText::ParseHtml(
        const struct GFxTextParagraphFormat **this,
        unsigned __int16 *a2,
        GFxResourceId *a3,
        int a4,
        char a5,
        char a6,
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *a7,
        int a8,
        struct GFxTextParagraphFormat *a9)
{
  return GFxStyledText::ParseHtmlImpl<wchar_t>(this, a2, a3, a4, a5, a6, a7, a8, a9);
}

//------------------------------------------------------------------------------
// Address: 0x101DE36E
// Name: public: static class D3DXShader::CNode __near * D3DXShader::CNode::Copy(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
static struct D3DXShader::CNode *__stdcall D3DXShader::CNode::Copy(struct D3DXShader::CNode *a1)
{
  if ( a1 != nullptr )
    return (*(struct D3DXShader::CNode *(__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a1 + 4))(a1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF098
// Name: public: virtual class D3DXShader::CNode __near * D3DXShader::CNode::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNode::Copy(D3DXShader::CNode *this)
{
  unsigned __int8 *v2; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x10u);
  if ( v2 != nullptr )
    return (struct D3DXShader::CNode *)D3DXShader::CNode::CNode(this: v2, a2: *((_DWORD *)this + 1));
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF0B8
// Name: public: virtual class D3DXShader::CNodeList __near * D3DXShader::CNodeList::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeList *__thiscall D3DXShader::CNodeList::Copy(D3DXShader::CNodeList *this)
{
  int *v2; // edi
  unsigned __int8 *v3; // eax
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 0;
  v2 = &v6;
  while ( this != nullptr )
  {
    if ( *((_DWORD *)this + 1) != 1 )
    {
      *v2 = (*(int (__thiscall **)(D3DXShader::CNodeList *))(*(_DWORD *)this + 4))(a1: this);
      return (struct D3DXShader::CNodeList *)v6;
    }
    v3 = D3DXShader::CNode::operator new(a1: 0x14u);
    if ( v3 != nullptr )
      v4 = D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v3);
    else
      v4 = 0;
    *v2 = v4;
    if ( v4 == 0 )
      return (struct D3DXShader::CNodeList *)v6;
    *(_DWORD *)(v4 + 16) = *((_DWORD *)this + 4);
    if ( *((_DWORD *)this + 2) != 0 )
    {
      *(_DWORD *)(*v2 + 8) = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 4))(a1: *((_DWORD *)this + 2));
      if ( *(_DWORD *)(*v2 + 8) == 0 )
      {
        *v2 = 0;
        return (struct D3DXShader::CNodeList *)v6;
      }
    }
    this = *((D3DXShader::CNodeList **)this + 3);
    v2 = (int *)(*v2 + 12);
  }
  return (struct D3DXShader::CNodeList *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x101DF131
// Name: public: virtual class D3DXShader::CNodeTree __near * D3DXShader::CNodeTree::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeTree *__thiscall D3DXShader::CNodeTree::Copy(D3DXShader::CNodeTree *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeTree::CNodeTree(this: (D3DXShader::CNodeTree *)v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[5] = *((_DWORD *)this + 5), *((_DWORD *)this + 2) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 4))(a1: *((_DWORD *)this + 2)),
         v3[2] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 3) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 3) + 4))(a1: *((_DWORD *)this + 3)),
         v3[3] = v5,
         v5 != 0)) )
  {
    return (struct D3DXShader::CNodeTree *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF18C
// Name: public: virtual class D3DXShader::CNodeToken __near * D3DXShader::CNodeToken::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeToken *__thiscall D3DXShader::CNodeToken::Copy(D3DXShader::CNodeToken *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNodeToken *result; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x30u);
  if ( v2 != nullptr )
    result = (struct D3DXShader::CNodeToken *)D3DXShader::CNodeToken::CNodeToken(this: (D3DXShader::CNodeToken *)v2);
  else
    result = nullptr;
  if ( result != nullptr )
    qmemcpy((char *)result + 16, (char *)this + 16, 0x20u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DF1BC
// Name: public: virtual class D3DXShader::CNodeProgram __near * D3DXShader::CNodeProgram::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeProgram *__thiscall D3DXShader::CNodeProgram::Copy(D3DXShader::CNodeProgram *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x20u);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeProgram::CNodeProgram(this: (D3DXShader::CNodeProgram *)v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[4] = *((_DWORD *)this + 4),
         v3[5] = *((_DWORD *)this + 5),
         v3[6] = *((_DWORD *)this + 6),
         *((_DWORD *)this + 7) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v4,
         v4 != 0)) )
  {
    return (struct D3DXShader::CNodeProgram *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF20E
// Name: public: virtual class D3DXShader::CNodeScope __near * D3DXShader::CNodeScope::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeScope *__thiscall D3DXShader::CNodeScope::Copy(D3DXShader::CNodeScope *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeScope::CNodeScope(this: (D3DXShader::CNodeScope *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[5] = *((_DWORD *)this + 5);
  if ( *((_DWORD *)this + 6) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6));
    v3[6] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 7) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 8) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8)),
         v3[8] = v6,
         v6 != 0)) )
  {
    return (struct D3DXShader::CNodeScope *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF284
// Name: public: virtual class D3DXShader::CNodeDecl __near * D3DXShader::CNodeDecl::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeDecl *__thiscall D3DXShader::CNodeDecl::Copy(D3DXShader::CNodeDecl *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x30u);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeDecl::CNodeDecl(this: (D3DXShader::CNodeDecl *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[8] = *((_DWORD *)this + 8);
  v3[9] = *((_DWORD *)this + 9);
  v3[10] = *((_DWORD *)this + 10);
  v3[11] = *((_DWORD *)this + 11);
  if ( *((_DWORD *)this + 5) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5));
    v3[5] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 6) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 7) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v6,
         v6 != 0)) )
  {
    return (struct D3DXShader::CNodeDecl *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF30C
// Name: public: virtual class D3DXShader::CNodeUsage __near * D3DXShader::CNodeUsage::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeUsage *__thiscall D3DXShader::CNodeUsage::Copy(D3DXShader::CNodeUsage *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x1Cu);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeUsage::CNodeUsage(this: (D3DXShader::CNodeUsage *)v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[4] = *((_DWORD *)this + 4), *((_DWORD *)this + 5) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5)),
         v3[5] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 6) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v5,
         v5 != 0)) )
  {
    return (struct D3DXShader::CNodeUsage *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF367
// Name: public: virtual class D3DXShader::CNodeArray __near * D3DXShader::CNodeArray::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeArray *__thiscall D3DXShader::CNodeArray::Copy(D3DXShader::CNodeArray *this)
{
  unsigned __int8 *v2; // eax
  int v3; // esi
  int v4; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeArray::CNodeArray(this: (D3DXShader::CNodeArray *)v2);
  else
    v3 = 0;
  if ( v3 != 0
    && ((*(_DWORD *)(v3 + 20) = *((_DWORD *)this + 5), *((_DWORD *)this + 4) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4)),
         *(_DWORD *)(v3 + 16) = v4,
         v4 != 0)) )
  {
    return (struct D3DXShader::CNodeArray *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF3AD
// Name: public: virtual class D3DXShader::CNodeType __near * D3DXShader::CNodeType::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeType *__thiscall D3DXShader::CNodeType::Copy(D3DXShader::CNodeType *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNodeType *result; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    result = (struct D3DXShader::CNodeType *)D3DXShader::CNodeType::CNodeType(this: (D3DXShader::CNodeType *)v2);
  else
    result = nullptr;
  if ( result != nullptr )
  {
    *((_DWORD *)result + 4) = *((_DWORD *)this + 4);
    *((_DWORD *)result + 5) = *((_DWORD *)this + 5);
    *((_DWORD *)result + 6) = *((_DWORD *)this + 6);
    *((_DWORD *)result + 7) = *((_DWORD *)this + 7);
    *((_DWORD *)result + 8) = *((_DWORD *)this + 8);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DF3EE
// Name: public: virtual class D3DXShader::CNodeFunction __near * D3DXShader::CNodeFunction::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeFunction *__thiscall D3DXShader::CNodeFunction::Copy(D3DXShader::CNodeFunction *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeFunction::CNodeFunction(this: (D3DXShader::CNodeFunction *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[5] = *((_DWORD *)this + 5);
  v3[6] = *((_DWORD *)this + 6);
  v3[14] = *((_DWORD *)this + 14);
  v3[15] = *((_DWORD *)this + 15);
  if ( *((_DWORD *)this + 7) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7));
    v3[7] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( *((_DWORD *)this + 8) != 0 )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8));
    v3[8] = v5;
    if ( v5 == 0 )
      return nullptr;
  }
  if ( *((_DWORD *)this + 9) != 0 )
  {
    v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 9) + 4))(a1: *((_DWORD *)this + 9));
    v3[9] = v6;
    if ( v6 == 0 )
      return nullptr;
  }
  if ( *((_DWORD *)this + 10) != 0 )
  {
    v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 4))(a1: *((_DWORD *)this + 10));
    v3[10] = v7;
    if ( v7 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 11) == 0
     || (v8 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 4))(a1: *((_DWORD *)this + 11)),
         v3[11] = v8,
         v8 != 0))
    && (*((_DWORD *)this + 12) == 0
     || (v9 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 4))(a1: *((_DWORD *)this + 12)),
         v3[12] = v9,
         v9 != 0))
    && (*((_DWORD *)this + 13) == 0
     || (v10 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 13) + 4))(a1: *((_DWORD *)this + 13)),
         v3[13] = v10,
         v10 != 0)) )
  {
    return (struct D3DXShader::CNodeFunction *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF4CB
// Name: public: virtual class D3DXShader::CNodeVariable __near * D3DXShader::CNodeVariable::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeVariable *__thiscall D3DXShader::CNodeVariable::Copy(D3DXShader::CNodeVariable *this)
{
  unsigned __int8 *v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  int v13; // [esp+Ch] [ebp-4h]

  v2 = D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v2 != nullptr )
  {
    v3 = D3DXShader::CNodeVariable::CNodeVariable(this: (D3DXShader::CNodeVariable *)v2);
    v13 = v3;
  }
  else
  {
    v13 = 0;
    v3 = 0;
  }
  if ( v3 != 0 )
  {
    *(_DWORD *)(v3 + 16) = *((_DWORD *)this + 4);
    *(_DWORD *)(v3 + 20) = *((_DWORD *)this + 5);
    *(_DWORD *)(v3 + 24) = *((_DWORD *)this + 6);
    *(_DWORD *)(v3 + 28) = *((_DWORD *)this + 7);
    *(_DWORD *)(v3 + 52) = *((_DWORD *)this + 13);
    if ( *((_DWORD *)this + 8) == 0
      || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8)),
          *(_DWORD *)(v3 + 32) = v4,
          v4 != 0) )
    {
      if ( *((_DWORD *)this + 9) == 0
        || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 9) + 4))(a1: *((_DWORD *)this + 9)),
            *(_DWORD *)(v3 + 36) = v5,
            v5 != 0) )
      {
        if ( *((_DWORD *)this + 10) == 0
          || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 4))(a1: *((_DWORD *)this + 10)),
              *(_DWORD *)(v3 + 40) = v6,
              v6 != 0) )
        {
          if ( *((_DWORD *)this + 11) == 0
            || (v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 4))(a1: *((_DWORD *)this + 11)),
                *(_DWORD *)(v3 + 44) = v7,
                v7 != 0) )
          {
            if ( *((_DWORD *)this + 12) == 0
              || (v8 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 4))(a1: *((_DWORD *)this + 12)),
                  *(_DWORD *)(v3 + 48) = v8,
                  v8 != 0) )
            {
              v9 = *((_DWORD *)this + 13);
              if ( v9 == 0 )
                return (struct D3DXShader::CNodeVariable *)v3;
              v10 = D3DXCore::CAlloc::Alloc(this: D3DXShader::CNode::s_pAlloc, a2: 4 * v9, dwSize: 0x10u);
              *(_DWORD *)(v3 + 56) = v10;
              if ( v10 != nullptr )
              {
                v11 = D3DXCore::CAlloc::Alloc(
                        this: D3DXShader::CNode::s_pAlloc,
                        a2: 4 * *((_DWORD *)this + 5),
                        dwSize: 0x10u);
                *(_DWORD *)(v3 + 60) = v11;
                if ( v11 != nullptr )
                {
                  qmemcpy(*(void **)(v3 + 56), *((const void **)this + 14), 4 * *((_DWORD *)this + 13));
                  qmemcpy(*(void **)(v13 + 60), *((const void **)this + 15), 4 * *((_DWORD *)this + 5));
                  return (struct D3DXShader::CNodeVariable *)v13;
                }
              }
            }
          }
        }
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF60F
// Name: public: virtual class D3DXShader::CNodeStatement __near * D3DXShader::CNodeStatement::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeStatement *__thiscall D3DXShader::CNodeStatement::Copy(D3DXShader::CNodeStatement *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeStatement::CNodeStatement(this: (D3DXShader::CNodeStatement *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  if ( *((_DWORD *)this + 5) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5));
    v3[5] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 6) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 7) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v6,
         v6 != 0))
    && (*((_DWORD *)this + 8) == 0
     || (v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8)),
         v3[8] = v7,
         v7 != 0)) )
  {
    return (struct D3DXShader::CNodeStatement *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF694
// Name: public: virtual class D3DXShader::CNodeExpression __near * D3DXShader::CNodeExpression::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeExpression *__thiscall D3DXShader::CNodeExpression::Copy(D3DXShader::CNodeExpression *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNodeExpression *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct D3DXShader::CNodeExpression *v7; // [esp+4h] [ebp-4h]

  v2 = D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v2 != nullptr )
  {
    result = (struct D3DXShader::CNodeExpression *)D3DXShader::CNodeExpression::CNodeExpression(this: (D3DXShader::CNodeExpression *)v2);
    v7 = result;
  }
  else
  {
    v7 = nullptr;
    result = nullptr;
  }
  if ( result == nullptr )
    return result;
  *((_DWORD *)result + 5) = *((_DWORD *)this + 5);
  *((_DWORD *)result + 6) = *((_DWORD *)this + 6);
  *((_DWORD *)result + 7) = *((_DWORD *)this + 7);
  *((_DWORD *)result + 10) = *((_DWORD *)this + 10);
  qmemcpy((char *)result + 48, (char *)this + 48, 0x20u);
  if ( *((_DWORD *)this + 4) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4));
    *((_DWORD *)v7 + 4) = v4;
    if ( v4 == 0 )
      return nullptr;
    result = v7;
  }
  if ( *((_DWORD *)this + 8) != 0 )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8));
    *((_DWORD *)v7 + 8) = v5;
    if ( v5 != 0 )
    {
      result = v7;
      goto LABEL_11;
    }
    return nullptr;
  }
LABEL_11:
  if ( *((_DWORD *)this + 9) == 0 )
    return result;
  v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 9) + 4))(a1: *((_DWORD *)this + 9));
  *((_DWORD *)v7 + 9) = v6;
  if ( v6 == 0 )
    return nullptr;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101DF73D
// Name: public: virtual class D3DXShader::CNodeValue __near * D3DXShader::CNodeValue::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeValue *__thiscall D3DXShader::CNodeValue::Copy(D3DXShader::CNodeValue *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNode *v3; // eax
  _DWORD *v5; // [esp+4h] [ebp-4h]

  v2 = D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v2 != nullptr )
    v5 = (_DWORD *)D3DXShader::CNodeValue::CNodeValue(this: (D3DXShader::CNodeValue *)v2);
  else
    v5 = nullptr;
  if ( v5 != nullptr
    && ((v5[4] = *((_DWORD *)this + 4),
         v5[5] = *((_DWORD *)this + 5),
         v5[6] = *((_DWORD *)this + 6),
         v5[7] = *((_DWORD *)this + 7),
         qmemcpy(v5 + 8, (char *)this + 32, 0x20u),
         *((_DWORD *)this + 4) != 4)
     || *((_DWORD *)this + 6) == 0
     || (v3 = D3DXShader::CNode::Copy(a1: *((struct D3DXShader::CNode **)this + 6)),
         *((_DWORD *)this + 6) = v3,
         v3 != nullptr)) )
  {
    return (struct D3DXShader::CNodeValue *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF7A6
// Name: public: virtual class D3DXShader::CNodeState __near * D3DXShader::CNodeState::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeState *__thiscall D3DXShader::CNodeState::Copy(D3DXShader::CNodeState *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x1Cu);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeState::CNodeState(this: (D3DXShader::CNodeState *)v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && (*((_DWORD *)this + 4) == 0
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4)),
         v3[4] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 5) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5)),
         v3[5] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 6) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v6,
         v6 != 0)) )
  {
    return (struct D3DXShader::CNodeState *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF810
// Name: public: virtual class D3DXShader::CNodeBuffer __near * D3DXShader::CNodeBuffer::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeBuffer *__thiscall D3DXShader::CNodeBuffer::Copy(D3DXShader::CNodeBuffer *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNodeBuffer *result; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x38u);
  if ( v2 != nullptr )
    result = (struct D3DXShader::CNodeBuffer *)D3DXShader::CNodeBuffer::CNodeBuffer(this: (D3DXShader::CNodeBuffer *)v2);
  else
    result = nullptr;
  if ( result != nullptr )
    qmemcpy((char *)result + 16, (char *)this + 16, 0x28u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DF84E
// Name: public: virtual class D3DXShader::CNodeRegister __near * D3DXShader::CNodeRegister::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeRegister *__thiscall D3DXShader::CNodeRegister::Copy(D3DXShader::CNodeRegister *this)
{
  unsigned __int8 *v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeRegister::CNodeRegister(this: (D3DXShader::CNodeRegister *)v2);
  else
    v3 = 0;
  if ( v3 != 0
    && (*((_DWORD *)this + 4) == 0
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4)),
         *(_DWORD *)(v3 + 16) = v4,
         v4 != 0))
    && (*((_DWORD *)this + 5) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5)),
         *(_DWORD *)(v3 + 20) = v5,
         v5 != 0)) )
  {
    return (struct D3DXShader::CNodeRegister *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E02FF
// Name: public: virtual class D3DXShader::CNodeAsmInstruction __near * D3DXShader::CNodeAsmInstruction::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeAsmInstruction *__thiscall D3DXShader::CNodeAsmInstruction::Copy(
        D3DXShader::CNodeAsmInstruction *this)
{
  unsigned __int8 *v2; // eax
  struct D3DXShader::CNodeAsmInstruction *result; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // edi
  int v8; // eax
  unsigned int v9; // [esp+4h] [ebp-8h]
  struct D3DXShader::CNodeAsmInstruction *v10; // [esp+8h] [ebp-4h]

  v2 = D3DXShader::CNode::operator new(a1: 0x60u);
  if ( v2 != nullptr )
  {
    result = (struct D3DXShader::CNodeAsmInstruction *)D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(this: (D3DXShader::CNodeAsmInstruction *)v2);
    v10 = result;
  }
  else
  {
    v10 = nullptr;
    result = nullptr;
  }
  if ( result == nullptr )
    return result;
  qmemcpy((char *)result + 16, (char *)this + 16, 0x2Cu);
  *((_DWORD *)result + 21) = *((_DWORD *)this + 21);
  *((_DWORD *)result + 22) = *((_DWORD *)this + 22);
  if ( *((_DWORD *)this + 15) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 15) + 4))(a1: *((_DWORD *)this + 15));
    *((_DWORD *)v10 + 15) = v4;
    if ( v4 == 0 )
      return nullptr;
    result = v10;
  }
  if ( *((_DWORD *)this + 16) != 0 )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 16) + 4))(a1: *((_DWORD *)this + 16));
    *((_DWORD *)v10 + 16) = v5;
    if ( v5 == 0 )
      return nullptr;
    result = v10;
  }
  v9 = 0;
  v6 = (_DWORD *)((char *)this + 68);
  v7 = result - this;
  do
  {
    if ( *v6 != 0 )
    {
      v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v6 + 4))(a1: *v6);
      *(_DWORD *)((char *)v6 + v7) = v8;
      if ( v8 == 0 )
        return nullptr;
      result = v10;
    }
    ++v9;
    ++v6;
  }
  while ( v9 < 4 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E03C3
// Name: public: virtual class D3DXShader::CNodeAsmRegister __near * D3DXShader::CNodeAsmRegister::Copy(void)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNodeAsmRegister *__thiscall D3DXShader::CNodeAsmRegister::Copy(D3DXShader::CNodeAsmRegister *this)
{
  unsigned __int8 *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x2Cu);
  if ( v2 != nullptr )
    v3 = (_DWORD *)D3DXShader::CNodeAsmRegister::CNodeAsmRegister(this: (D3DXShader::CNodeAsmRegister *)v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[5] = *((_DWORD *)this + 5);
  v3[6] = *((_DWORD *)this + 6);
  v3[7] = *((_DWORD *)this + 7);
  v3[8] = *((_DWORD *)this + 8);
  v3[9] = *((_DWORD *)this + 9);
  if ( *((_DWORD *)this + 10) == 0 )
    return (struct D3DXShader::CNodeAsmRegister *)v3;
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 4))(a1: *((_DWORD *)this + 10));
  v3[10] = v4;
  if ( v4 != 0 )
    return (struct D3DXShader::CNodeAsmRegister *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DE387
// Name: public: static class D3DXShader::CNode __near * D3DXShader::CNode::Append(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct D3DXShader::CNode *__stdcall D3DXShader::CNode::Append(
        struct D3DXShader::CNode *a1,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode **v3; // eax

  if ( a1 == nullptr )
    return a2;
  v3 = &a1;
  do
    v3 = (struct D3DXShader::CNode **)((char *)*v3 + 12);
  while ( *v3 != nullptr );
  *v3 = a2;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE3B0
// Name: public: virtual void D3DXShader::CNodeState::Print(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CNodeState::Print(D3DXShader::CNodeState *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101DE3B1
// Name: public: D3DXShader::CNodeList::CNodeList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeList::CNodeList(D3DXShader::CNodeList *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 1);
  v1[4] = 0;
  *v1 = &D3DXShader::CNodeList::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE3C7
// Name: public: D3DXShader::CNodeList::CNodeList(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeList::CNodeList(
        D3DXShader::CNodeList *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        const char *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 1);
  v4[2] = a2;
  v4[3] = a3;
  v4[4] = a4;
  *v4 = &D3DXShader::CNodeList::`vftable';
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101DE3F3
// Name: public: virtual int D3DXShader::CNodeList::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CNodeList::IsEqual(D3DXShader::CNodeList *this, struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *v2; // esi
  int result; // eax
  int v4; // ecx
  int v5; // edi

  v2 = a2;
  result = (int)D3DXShader::CNode::IsEqual(this, a2);
  if ( result != 0 )
  {
    v5 = v4;
    if ( v4 != 0 )
    {
      while ( *(_DWORD *)(v5 + 4) == 1 )
      {
        if ( v2 == nullptr
          || *((_DWORD *)v2 + 1) != 1
          || D3DXShader::CNode::IsEqual(
               a1: *(struct D3DXShader::CNode **)(v5 + 8),
               a2: *((struct D3DXShader::CNode **)v2 + 2)) == 0 )
        {
          return 0;
        }
        v5 = *(_DWORD *)(v5 + 12);
        v2 = *((struct D3DXShader::CNode **)v2 + 3);
        if ( v5 == 0 )
          return 1;
      }
      if ( D3DXShader::CNode::IsEqual(a1: (struct D3DXShader::CNode *)v5, a2: v2) == 0 )
        return 0;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DE450
// Name: public: D3DXShader::CNodeTree::CNodeTree(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeTree::CNodeTree(D3DXShader::CNodeTree *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 2);
  v1[4] = 0;
  v1[5] = 0;
  *v1 = &D3DXShader::CNodeTree::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE46A
// Name: public: D3DXShader::CNodeTree::CNodeTree(char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeTree::CNodeTree(
        D3DXShader::CNodeTree *this,
        const char *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 2);
  v5[4] = a2;
  v5[2] = a3;
  v5[3] = a4;
  v5[5] = a5;
  *v5 = &D3DXShader::CNodeTree::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101DE49C
// Name: public: virtual int D3DXShader::CNodeTree::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeTree::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 5) == a2[5]
      && D3DXShader::CNode::IsEqual(a1: *(this + 2), a2: a2[2]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 3), a2: a2[3]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE4EC
// Name: sub_101DE4EC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101DE4EC@<eax>(_DWORD *a1@<eax>, _DWORD *a2@<ecx>)
{
  int v2; // edx
  _BYTE *v5; // esi
  _BYTE *v6; // eax
  bool v7; // cf
  unsigned __int8 v8; // dl
  int v9; // eax
  int v10; // edx
  _BYTE *v11; // esi
  _BYTE *v12; // ecx
  unsigned __int8 v13; // dl
  _BYTE *v14; // esi
  _BYTE *v15; // ecx
  unsigned __int8 v16; // dl

  v2 = *a2;
  if ( *a2 != *a1 )
    return 0;
  if ( v2 > 8 )
  {
    v10 = v2 - 9;
    if ( v10 != 0 )
    {
      if ( v10 != 1 )
        return 1;
      v11 = (_BYTE *)a1[2];
      v12 = (_BYTE *)a2[2];
      while ( 1 )
      {
        v7 = *v12 < *v11;
        if ( *v12 != *v11 )
          break;
        if ( *v12 == 0 )
          goto LABEL_16;
        v13 = v12[1];
        v7 = v13 < v11[1];
        if ( v13 != v11[1] )
          break;
        v12 += 2;
        v11 += 2;
        if ( v13 == 0 )
          goto LABEL_16;
      }
    }
    else
    {
      v14 = (_BYTE *)a1[2];
      v15 = (_BYTE *)a2[2];
      while ( 1 )
      {
        v7 = *v15 < *v14;
        if ( *v15 != *v14 )
          break;
        if ( *v15 != 0 )
        {
          v16 = v15[1];
          v7 = v16 < v14[1];
          if ( v16 != v14[1] )
            break;
          v15 += 2;
          v14 += 2;
          if ( v16 != 0 )
            continue;
        }
LABEL_16:
        v9 = 0;
        return v9 == 0;
      }
    }
  }
  else
  {
    if ( v2 >= 5 )
      return *((double *)a2 + 1) == *((double *)a1 + 1);
    if ( v2 == 0 )
      return a2[2] == a1[2];
    if ( v2 != 1 )
    {
      if ( v2 <= 1 )
        return 1;
      return a2[2] == a1[2];
    }
    v5 = a1 + 2;
    v6 = a2 + 2;
    while ( 1 )
    {
      v7 = *v6 < *v5;
      if ( *v6 != *v5 )
        break;
      if ( *v6 == 0 )
        goto LABEL_16;
      v8 = v6[1];
      v7 = v8 < v5[1];
      if ( v8 != v5[1] )
        break;
      v6 += 2;
      v5 += 2;
      if ( v8 == 0 )
        goto LABEL_16;
    }
  }
  v9 = -v7 - (v7 - 1);
  return v9 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE5BC
// Name: public: D3DXShader::CNodeToken::CNodeToken(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeToken::CNodeToken(D3DXShader::CNodeToken *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 3);
  *v1 = &D3DXShader::CNodeToken::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE5CE
// Name: public: D3DXShader::CNodeToken::CNodeToken(struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeToken::CNodeToken(
        D3DXShader::CNodeToken *this,
        const struct D3DXShader::D3DXTOKEN *a2)
{
  _DWORD *v2; // edx

  D3DXShader::CNode::CNode(this, a2: 3);
  *v2 = &D3DXShader::CNodeToken::`vftable';
  qmemcpy(v2 + 4, a2, 0x20u);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101DE5F7
// Name: public: virtual int D3DXShader::CNodeToken::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNodeToken::IsEqual(
        D3DXShader::CNodeToken *this,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *result; // eax
  int v3; // edx
  int v4; // ecx

  result = D3DXShader::CNode::IsEqual(this, a2);
  if ( result != nullptr )
    return (struct D3DXShader::CNode *)(sub_101DE4EC(a1: (_DWORD *)(v3 + 16), a2: (_DWORD *)(v4 + 16)) != 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DE61E
// Name: public: D3DXShader::CNodeProgram::CNodeProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeProgram::CNodeProgram(D3DXShader::CNodeProgram *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 4);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  *v1 = &D3DXShader::CNodeProgram::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE63E
// Name: public: D3DXShader::CNodeProgram::CNodeProgram(unsigned int,unsigned int,unsigned int,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeProgram::CNodeProgram(
        D3DXShader::CNodeProgram *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        struct D3DXShader::CNode *a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 4);
  v5[4] = a2;
  v5[5] = a3;
  v5[6] = a4;
  v5[7] = a5;
  *v5 = &D3DXShader::CNodeProgram::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101DE670
// Name: public: virtual int D3DXShader::CNodeProgram::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeProgram::IsEqual(D3DXShader::CNodeProgram *this, struct D3DXShader::CNode *a2)
{
  int v2; // edx
  int v3; // ecx

  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && *(_DWORD *)(v3 + 16) == *(_DWORD *)(v2 + 16)
      && *(_DWORD *)(v3 + 20) == *(_DWORD *)(v2 + 20)
      && *(_DWORD *)(v3 + 24) == *(_DWORD *)(v2 + 24)
      && D3DXShader::CNode::IsEqual(
           a1: *(struct D3DXShader::CNode **)(v3 + 28),
           a2: *(struct D3DXShader::CNode **)(v2 + 28)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE6B3
// Name: public: D3DXShader::CNodeScope::CNodeScope(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeScope::CNodeScope(D3DXShader::CNodeScope *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 5);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  *v1 = &D3DXShader::CNodeScope::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE6D6
// Name: public: D3DXShader::CNodeScope::CNodeScope(enum D3DXShader::_D3DXSCOPE_TYPE,char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNodeTree __near *,class D3DXShader::CNodeScope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeScope::CNodeScope(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edx

  D3DXShader::CNode::CNode(this, a2: 5);
  v6[4] = a2;
  v6[5] = a3;
  v6[6] = a4;
  v6[7] = a5;
  v6[8] = a6;
  *v6 = &D3DXShader::CNodeScope::`vftable';
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101DE70E
// Name: public: virtual int D3DXShader::CNodeScope::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeScope::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 5) == a2[5]
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE76E
// Name: public: D3DXShader::CNodeDecl::CNodeDecl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeDecl::CNodeDecl(D3DXShader::CNodeDecl *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 6);
  v1[9] = -1;
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[10] = 0;
  v1[11] = 0;
  *v1 = &D3DXShader::CNodeDecl::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE79B
// Name: public: D3DXShader::CNodeDecl::CNodeDecl(enum D3DXShader::_D3DXDECL_TYPE,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeDecl::CNodeDecl(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 6);
  v5[4] = a2;
  v5[5] = a3;
  v5[6] = a4;
  v5[7] = a5;
  v5[9] = -1;
  v5[8] = 0;
  v5[10] = 0;
  v5[11] = 0;
  *v5 = &D3DXShader::CNodeDecl::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101DE7DC
// Name: public: virtual int D3DXShader::CNodeDecl::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeDecl::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 8) == a2[8]
      && *(this + 9) == a2[9]
      && *(this + 10) == a2[10]
      && *(this + 11) == a2[11]
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE854
// Name: public: D3DXShader::CNodeUsage::CNodeUsage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeUsage::CNodeUsage(D3DXShader::CNodeUsage *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 7);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  *v1 = &D3DXShader::CNodeUsage::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE871
// Name: public: D3DXShader::CNodeUsage::CNodeUsage(unsigned long,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeUsage::CNodeUsage(
        D3DXShader::CNodeUsage *this,
        unsigned int a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 7);
  v4[4] = a2;
  v4[5] = a3;
  v4[6] = a4;
  *v4 = &D3DXShader::CNodeUsage::`vftable';
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101DE89D
// Name: public: virtual int D3DXShader::CNodeUsage::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeUsage::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE8E6
// Name: public: D3DXShader::CNodeArray::CNodeArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeArray::CNodeArray(D3DXShader::CNodeArray *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 8);
  v1[4] = 0;
  v1[5] = 0;
  *v1 = &D3DXShader::CNodeArray::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE900
// Name: public: D3DXShader::CNodeArray::CNodeArray(class D3DXShader::CNode __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeArray::CNodeArray(
        D3DXShader::CNodeArray *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3)
{
  _DWORD *v3; // edx

  D3DXShader::CNode::CNode(this, a2: 8);
  v3[4] = a2;
  v3[5] = a3;
  *v3 = &D3DXShader::CNodeArray::`vftable';
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DE926
// Name: public: virtual int D3DXShader::CNodeArray::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeArray::IsEqual(D3DXShader::CNodeArray *this, struct D3DXShader::CNode *a2)
{
  int v2; // edx
  int v3; // ecx

  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && *(_DWORD *)(v3 + 20) == *(_DWORD *)(v2 + 20)
      && D3DXShader::CNode::IsEqual(
           a1: *(struct D3DXShader::CNode **)(v3 + 16),
           a2: *(struct D3DXShader::CNode **)(v2 + 16)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE959
// Name: public: D3DXShader::CNodeType::CNodeType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeType::CNodeType(D3DXShader::CNodeType *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 9);
  v1[4] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  *v1 = &D3DXShader::CNodeType::`vftable';
  v1[5] = 9;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE980
// Name: public: D3DXShader::CNodeType::CNodeType(enum D3DXShader::_D3DXTYPE_TEMPLATE,enum D3DXShader::_D3DXCOMPONENT_TYPE,unsigned int,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeType::CNodeType(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edx

  D3DXShader::CNode::CNode(this, a2: 9);
  v6[4] = a2;
  v6[5] = a3;
  v6[6] = a4;
  v6[7] = a5;
  v6[8] = a6;
  *v6 = &D3DXShader::CNodeType::`vftable';
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101DE9B8
// Name: public: virtual int D3DXShader::CNodeType::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeType::IsEqual(D3DXShader::CNodeType *this, struct D3DXShader::CNode *a2)
{
  _DWORD *v2; // edx
  _DWORD *v3; // ecx

  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && v3[4] == v2[4]
      && v3[5] == v2[5]
      && v3[6] == v2[6]
      && v3[7] == v2[7]
      && v3[8] == v2[8];
}

//------------------------------------------------------------------------------
// Address: 0x101DE9FD
// Name: public: D3DXShader::CNodeFunction::CNodeFunction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeFunction::CNodeFunction(D3DXShader::CNodeFunction *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 10);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  v1[15] = 0;
  *v1 = &D3DXShader::CNodeFunction::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEA35
// Name: public: virtual int D3DXShader::CNodeFunction::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeFunction::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 5) == a2[5]
      && *(this + 6) == a2[6]
      && *(this + 14) == a2[14]
      && *(this + 15) == a2[15]
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 9), a2: a2[9]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 10), a2: a2[10]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 11), a2: a2[11]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 12), a2: a2[12]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 13), a2: a2[13]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DEAF5
// Name: public: D3DXShader::CNodeVariable::CNodeVariable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeVariable::CNodeVariable(D3DXShader::CNodeVariable *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 11);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  v1[15] = 0;
  *v1 = &D3DXShader::CNodeVariable::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB2D
// Name: public: virtual int D3DXShader::CNodeVariable::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeVariable::IsEqual(D3DXShader::CNodeVariable *this, struct D3DXShader::CNode *a2)
{
  int v3; // eax
  BOOL result; // eax

  result = false;
  if ( D3DXShader::CNode::IsEqual(this, a2) != nullptr
    && *((_DWORD *)this + 4) == *((_DWORD *)a2 + 4)
    && *((_DWORD *)this + 5) == *((_DWORD *)a2 + 5)
    && *((_DWORD *)this + 6) == *((_DWORD *)a2 + 6)
    && *((_DWORD *)this + 7) == *((_DWORD *)a2 + 7)
    && *((_DWORD *)this + 13) == *((_DWORD *)a2 + 13)
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 8),
         a2: *((struct D3DXShader::CNode **)a2 + 8)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 9),
         a2: *((struct D3DXShader::CNode **)a2 + 9)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 10),
         a2: *((struct D3DXShader::CNode **)a2 + 10)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 11),
         a2: *((struct D3DXShader::CNode **)a2 + 11)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 12),
         a2: *((struct D3DXShader::CNode **)a2 + 12)) != 0 )
  {
    v3 = *((_DWORD *)this + 13);
    if ( v3 == 0 || memcmp(*((const void **)this + 14), *((const void **)a2 + 14), 4 * v3) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DEBE7
// Name: public: D3DXShader::CNodeStatement::CNodeStatement(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeStatement::CNodeStatement(D3DXShader::CNodeStatement *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 12);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  *v1 = &D3DXShader::CNodeStatement::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC0A
// Name: public: virtual int D3DXShader::CNodeStatement::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeStatement::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC71
// Name: public: D3DXShader::CNodeExpression::CNodeExpression(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeExpression::CNodeExpression(D3DXShader::CNodeExpression *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 13);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  *v1 = &D3DXShader::CNodeExpression::`vftable';
  v1[10] = 1;
  memset(v1 + 12, 0, 0x20u);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DECAA
// Name: public: D3DXShader::CNodeExpression::CNodeExpression(class D3DXShader::CNode __near *,enum D3DXShader::_D3DXEXPR_OP,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeExpression::CNodeExpression(
        _DWORD *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        const void *a7)
{
  _DWORD *v7; // edx

  D3DXShader::CNode::CNode(this, a2: 13);
  v7[5] = 0;
  v7[6] = 0;
  v7[4] = a2;
  v7[7] = a3;
  v7[8] = a4;
  v7[9] = a5;
  v7[10] = a6;
  *v7 = &D3DXShader::CNodeExpression::`vftable';
  qmemcpy(v7 + 12, a7, 0x20u);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101DECF9
// Name: public: virtual int D3DXShader::CNodeExpression::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeExpression::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 5) == a2[5]
      && *(this + 6) == a2[6]
      && *(this + 7) == a2[7]
      && *(this + 10) == a2[10]
      && sub_101DE4EC(a1: a2 + 12, a2: this + 12) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 4), a2: a2[4]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 9), a2: a2[9]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DED78
// Name: public: D3DXShader::CNodeValue::CNodeValue(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeValue::CNodeValue(D3DXShader::CNodeValue *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  *v1 = &D3DXShader::CNodeValue::`vftable';
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  memset(v1 + 8, 0, 0x20u);
  v1[4] = 3;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEDAB
// Name: public: D3DXShader::CNodeValue::CNodeValue(struct D3DXShader::_D3DXVALUE const __near *,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeValue *__thiscall D3DXShader::CNodeValue::CNodeValue(
        D3DXShader::CNodeValue *this,
        const struct D3DXShader::_D3DXVALUE *a2,
        const struct D3DXShader::D3DXTOKEN *a3)
{
  bool v4; // zf

  D3DXShader::CNode::CNode(this, a2: 14);
  *(_DWORD *)this = &D3DXShader::CNodeValue::`vftable';
  *((_DWORD *)this + 4) = *(_DWORD *)a2;
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 6) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 3);
  v4 = *((_DWORD *)this + 4) == 4;
  qmemcpy((char *)this + 32, a3, 0x20u);
  if ( v4 && *((_DWORD *)this + 6) != 0 )
    *((_DWORD *)this + 6) = D3DXShader::CNode::Copy(a1: *((struct D3DXShader::CNode **)this + 6));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DEDF7
// Name: public: D3DXShader::CNodeValue::CNodeValue(enum D3DXShader::_D3DXVALUE_TYPE,class D3DXShader::CNode __near *,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeValue::CNodeValue(_DWORD *this, int a2, int a3, const void *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  v4[4] = a2;
  v4[6] = a3;
  *v4 = &D3DXShader::CNodeValue::`vftable';
  qmemcpy(v4 + 8, a4, 0x20u);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE2C
// Name: public: D3DXShader::CNodeValue::CNodeValue(enum D3DXShader::_D3DXVALUE_TYPE,double,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CNodeValue::CNodeValue(_DWORD *this, int a2, double a3, const void *a4)
{
  int v4; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  *(double *)(v4 + 24) = a3;
  *(_DWORD *)(v4 + 16) = a2;
  *(_DWORD *)v4 = &D3DXShader::CNodeValue::`vftable';
  qmemcpy((void *)(v4 + 32), a4, 0x20u);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE61
// Name: public: D3DXShader::CNodeValue::CNodeValue(enum D3DXShader::_D3DXVALUE_TYPE,unsigned int,unsigned int,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeValue::CNodeValue(_DWORD *this, int a2, int a3, int a4, const void *a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  v5[4] = a2;
  v5[6] = a3;
  v5[7] = a4;
  *v5 = &D3DXShader::CNodeValue::`vftable';
  qmemcpy(v5 + 8, a5, 0x20u);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE9C
// Name: public: virtual int D3DXShader::CNodeValue::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNodeValue::IsEqual(
        D3DXShader::CNodeValue *this,
        struct D3DXShader::CNode **a2)
{
  struct D3DXShader::CNode *result; // eax
  int v3; // edx
  struct D3DXShader::CNode *v4; // eax

  result = D3DXShader::CNode::IsEqual(this, (struct D3DXShader::CNode *)a2);
  if ( result != nullptr )
  {
    v4 = *(struct D3DXShader::CNode **)(v3 + 16);
    return (struct D3DXShader::CNode *)(v4 == a2[4]
                                     && (memcmp((const void *)(v3 + 16), a2 + 4, 0x10u) == 0
                                      || v4 == (struct D3DXShader::CNode *)4
                                      && D3DXShader::CNode::IsEqual(
                                           a1: *(struct D3DXShader::CNode **)(v3 + 24),
                                           a2: a2[6]) != 0));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DEEED
// Name: public: D3DXShader::CNodeState::CNodeState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeState::CNodeState(D3DXShader::CNodeState *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 16);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  *v1 = &D3DXShader::CNodeState::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEF0A
// Name: public: D3DXShader::CNodeState::CNodeState(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeState::CNodeState(
        D3DXShader::CNodeState *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 16);
  v4[4] = a2;
  v4[5] = a3;
  v4[6] = a4;
  *v4 = &D3DXShader::CNodeState::`vftable';
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101DEF36
// Name: public: virtual int D3DXShader::CNodeState::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeState::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && D3DXShader::CNode::IsEqual(a1: *(this + 4), a2: a2[4]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DEF86
// Name: public: D3DXShader::CNodeBuffer::CNodeBuffer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeBuffer::CNodeBuffer(D3DXShader::CNodeBuffer *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 15);
  v1[12] = 0;
  v1[13] = 0;
  *v1 = &D3DXShader::CNodeBuffer::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEFA0
// Name: public: D3DXShader::CNodeBuffer::CNodeBuffer(struct D3DXShader::D3DXTOKEN const __near *,unsigned char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeBuffer::CNodeBuffer(
        D3DXShader::CNodeBuffer *this,
        const struct D3DXShader::D3DXTOKEN *a2,
        unsigned __int8 *a3,
        unsigned int a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 15);
  *v4 = &D3DXShader::CNodeBuffer::`vftable';
  qmemcpy(v4 + 4, a2, 0x20u);
  v4[12] = a3;
  v4[13] = a4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101DEFD5
// Name: public: virtual int D3DXShader::CNodeBuffer::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeBuffer::IsEqual(D3DXShader::CNodeBuffer *this, struct D3DXShader::CNode *a2)
{
  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && sub_101DE4EC(a1: (_DWORD *)a2 + 4, a2: (_DWORD *)this + 4) != 0
      && *((_DWORD *)a2 + 12) == *((_DWORD *)this + 12)
      && *((_DWORD *)this + 13) == *((_DWORD *)a2 + 13);
}

//------------------------------------------------------------------------------
// Address: 0x101DF017
// Name: public: D3DXShader::CNodeRegister::CNodeRegister(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeRegister::CNodeRegister(D3DXShader::CNodeRegister *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 17);
  v1[4] = 0;
  v1[5] = 0;
  *v1 = &D3DXShader::CNodeRegister::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101DF031
// Name: public: D3DXShader::CNodeRegister::CNodeRegister(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeRegister::CNodeRegister(
        D3DXShader::CNodeRegister *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  _DWORD *v3; // edx

  D3DXShader::CNode::CNode(this, a2: 17);
  v3[4] = a2;
  v3[5] = a3;
  *v3 = &D3DXShader::CNodeRegister::`vftable';
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DF057
// Name: public: virtual int D3DXShader::CNodeRegister::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeRegister::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && D3DXShader::CNode::IsEqual(a1: *(this + 4), a2: a2[4]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DF8A3
// Name: void D3DXCheckNewDelete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall D3DXCheckNewDelete()
{
  void *v0; // edi
  void *v1; // eax
  void *v2; // ebx
  int v3; // [esp+4h] [ebp-4h]

  if ( dword_1035B1CC == 0 )
  {
    dword_1035B1CC = 1;
    v3 = 0;
    v0 = MemAlloc_Alloc(nSize: 0);
    v1 = MemAlloc_Alloc(nSize: 0);
    v2 = v1;
    if ( v0 == nullptr || v1 == nullptr || v0 == v1 )
      v3 = 1;
    if ( v0 != nullptr )
      free(pMem: v0);
    if ( v2 != nullptr && v2 != v0 )
      free(pMem: v2);
    free(pMem: nullptr);
    if ( v3 != 0 )
    {
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) Overloaded ::new and ::delete operators do not conform to C++ standards:\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) An allocation of zero bytes should return a unique non-null pointer to at\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) least zero bytes. Deletion of a null pointer should quietly do nothing.\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) D3DX relies upon this behavior.\r\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF932
// Name: public: D3DXShader::CCommentBlock::CCommentBlock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CCommentBlock *__thiscall D3DXShader::CCommentBlock::CCommentBlock(
        D3DXShader::CCommentBlock *this,
        unsigned int a2)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = (char *)this + 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DF94F
// Name: public: D3DXShader::CCommentBlock::~CCommentBlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CCommentBlock::~CCommentBlock(D3DXShader::CCommentBlock *this)
{
  int v2; // edi
  int v3; // eax

  while ( *((_DWORD *)this + 2) != 0 )
  {
    v2 = *((_DWORD *)this + 2);
    *((_DWORD *)this + 2) = *(_DWORD *)(v2 + 16);
    v3 = *(_DWORD *)(v2 + 8);
    if ( (v3 & 8) != 0 || (v3 & 1) == 0 )
      free(pMem: *(void **)v2);
    free(pMem: (void *)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF987
// Name: public: long D3DXShader::CCommentBlock::Add(void const __near *,unsigned int,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCommentBlock::Add(
        D3DXShader::CCommentBlock *this,
        char *pMem,
        unsigned int nSize,
        unsigned int a4,
        unsigned int *a5)
{
  unsigned int v5; // edi
  D3DXShader::CCommentBlock *v6; // esi
  int i; // eax
  char **v9; // ebx
  char *v10; // eax
  char *v11; // ecx
  char ***v12; // ecx

  v5 = nSize;
  v6 = this;
  if ( nSize != 0 && pMem == nullptr )
    return -2147467259;
  if ( nSize == -1 )
  {
    nSize = strlen(pMem) + 1;
    v5 = nSize;
  }
  if ( (a4 & 1) == 0 )
    a4 |= 2u;
  if ( (a4 & 2) != 0 )
  {
    for ( i = *((_DWORD *)v6 + 2); i != 0; i = *(_DWORD *)(i + 16) )
    {
      if ( (*(_BYTE *)(i + 8) & 2) != 0 && v5 == *(_DWORD *)(i + 4) )
      {
        if ( memcmp(pMem, *(const void **)i, v5) == 0 )
        {
          if ( a5 != nullptr )
            *a5 = *(_DWORD *)(i + 12);
          if ( (a4 & 1) != 0 && (a4 & 8) != 0 )
            free(pMem);
          return 0;
        }
        v5 = nSize;
        v6 = this;
      }
    }
  }
  v9 = (char **)MemAlloc_Alloc(nSize: 0x14u);
  if ( v9 == nullptr )
    return -2147024882;
  if ( (a4 & 1) != 0 )
  {
    *v9 = pMem;
  }
  else
  {
    v10 = (char *)MemAlloc_Alloc(nSize: v5);
    *v9 = v10;
    if ( v10 == nullptr )
    {
      free(pMem: v9);
      return -2147024882;
    }
    qmemcpy(v10, pMem, v5);
    v5 = nSize;
    v6 = this;
  }
  if ( (a4 & 4) == 0 )
    *((_DWORD *)v6 + 1) = (*((_DWORD *)v6 + 1) + 3) & 0xFFFFFFFC;
  v11 = *((char **)v6 + 1);
  v9[2] = (char *)a4;
  v9[4] = nullptr;
  v9[3] = v11;
  v9[1] = (char *)v5;
  v12 = *((char ****)v6 + 3);
  *((_DWORD *)v6 + 1) += v5;
  *v12 = v9;
  *((_DWORD *)v6 + 3) = v9 + 4;
  if ( a5 != nullptr )
    *a5 = (unsigned int)v9[3];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DFAC0
// Name: public: unsigned int D3DXShader::CCommentBlock::SizeInDwords(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CCommentBlock::SizeInDwords(D3DXShader::CCommentBlock *this)
{
  return ((unsigned int)(*((_DWORD *)this + 1) + 3) >> 2) + 2;
}

//------------------------------------------------------------------------------
// Address: 0x101DFACC
// Name: public: long D3DXShader::CCommentBlock::WriteComment(unsigned long __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCommentBlock::WriteComment(
        D3DXShader::CCommentBlock *this,
        unsigned int *a2,
        unsigned int a3)
{
  unsigned int v3; // ebx
  int v6; // edx
  int v7; // eax
  unsigned int *v8; // [esp+10h] [ebp+8h]
  unsigned int *i; // [esp+14h] [ebp+Ch]

  v3 = a3;
  if ( a3 == -1 )
  {
    v3 = ((unsigned int)(*((_DWORD *)this + 1) + 3) >> 2) + 2;
  }
  else if ( a3 < ((unsigned int)(*((_DWORD *)this + 1) + 3) >> 2) + 2 )
  {
    return -2147467259;
  }
  if ( v3 > 0x8000 )
    return -2147467259;
  v8 = nullptr;
  *a2 = ((((_WORD)v3 - 1) & 0x7FFF) << 16) | 0xFFFE;
  a2[1] = *(_DWORD *)this;
  v6 = *((_DWORD *)this + 2);
  for ( i = a2 + 2; v6 != 0; v8 = (unsigned int *)((char *)v8 + v7) )
  {
    if ( (*(_BYTE *)(v6 + 8) & 4) == 0 )
    {
      memset(i, 0xABu, (((unsigned int)v8 + 3) & 0xFFFFFFFC) - (_DWORD)v8);
      i = (unsigned int *)((char *)i + (((unsigned int)v8 + 3) & 0xFFFFFFFC) - (_DWORD)v8);
      v8 = (unsigned int *)(((unsigned int)v8 + 3) & 0xFFFFFFFC);
    }
    qmemcpy(i, *(const void **)v6, *(_DWORD *)(v6 + 4));
    v7 = *(_DWORD *)(v6 + 4);
    v6 = *(_DWORD *)(v6 + 16);
    i = (unsigned int *)((char *)i + v7);
  }
  memset(i, 0xABu, 4 * v3 - 8 - (_DWORD)v8);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DFBB9
// Name: public: D3DXShader::CFragmentConstants::CFragmentConstants(class D3DXShader::CParse __near *,class D3DXShader::CNodeScope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CFragmentConstants *__thiscall D3DXShader::CFragmentConstants::CFragmentConstants(
        D3DXShader::CFragmentConstants *this,
        struct D3DXShader::CParse *a2,
        struct D3DXShader::CNodeScope *a3)
{
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DFBCF
// Name: long D3DXShader::CalcNumRegisters(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CalcNumRegisters(
        D3DXShader *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  D3DXShader **v4; // edi
  D3DXShader *v5; // esi
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // eax
  int result; // eax
  struct D3DXShader::CNode *v10; // ebx
  struct D3DXShader::CNode *v11; // eax
  unsigned int *v12; // [esp-4h] [ebp-10h]
  unsigned int *v13; // [esp+0h] [ebp-Ch]

  v4 = (D3DXShader **)a3;
  if ( a3 == nullptr )
    v4 = &this;
  v5 = this;
  v6 = *((_DWORD *)this + 1);
  if ( v6 == 9 )
  {
    v7 = *((_DWORD *)this + 4);
    v8 = 1;
    if ( v7 < 2 )
    {
      *(_DWORD *)a2 = 1;
      v8 = *((_DWORD *)v5 + 7);
LABEL_9:
      *v4 = (D3DXShader *)v8;
      return 0;
    }
    if ( v7 == 2 )
    {
      *(_DWORD *)a2 = *((_DWORD *)this + 7);
      v8 = *((_DWORD *)v5 + 6);
      goto LABEL_9;
    }
    if ( v7 == 3 )
    {
      *(_DWORD *)a2 = 1;
      goto LABEL_9;
    }
    return -2147467259;
  }
  if ( v6 == 8 )
  {
    v12 = (unsigned int *)v4;
    v4 = (D3DXShader **)a2;
    result = D3DXShader::CalcNumRegisters(this: *((D3DXShader **)this + 4), a2, a3: v12, a4: v13);
    if ( result < 0 )
      return result;
    v8 = (_DWORD)*v4 * *((_DWORD *)v5 + 5);
    goto LABEL_9;
  }
  if ( v6 != 1 )
    return -2147467259;
  v10 = a2;
  *(_DWORD *)a2 = 0;
  *v4 = nullptr;
  while ( 1 )
  {
    result = D3DXShader::CalcNumRegisters(
               this: *(D3DXShader **)(*(_DWORD *)(*((_DWORD *)v5 + 2) + 24) + 32),
               a2: (struct D3DXShader::CNode *)&a3,
               a3: (unsigned int *)&a2,
               a4: v13);
    if ( result < 0 )
      break;
    *(_DWORD *)v10 += a3;
    v11 = *v4;
    if ( a2 > *v4 )
      v11 = a2;
    *v4 = v11;
    v5 = *((D3DXShader **)v5 + 3);
    if ( v5 == nullptr )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DFC92
// Name: public: long D3DXShader::CFragmentConstants::GetConstantSize(struct D3DXShader::D3DXTOKEN __near *,char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFragmentConstants::GetConstantSize(
        D3DXShader::CFragmentConstants *this,
        struct D3DXShader::D3DXTOKEN *a2,
        const char *a3,
        struct D3DXShader::CNode *a4)
{
  const char *v5; // edi
  D3DXShader::CParse *v6; // ecx
  int result; // eax
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  struct D3DXShader::CNodeScope **v11; // [esp-10h] [ebp-3Ch]
  unsigned int *v12; // [esp+0h] [ebp-2Ch]
  const char *v13[8]; // [esp+Ch] [ebp-20h] BYREF

  qmemcpy(v13, a2, sizeof(v13));
  v5 = a3;
  v6 = *(D3DXShader::CParse **)this;
  v13[2] = a3 + 2;
  v11 = *((struct D3DXShader::CNodeScope ***)this + 1);
  v13[0] = (const char *)10;
  if ( D3DXShader::CParse::FindDecl(
         this: v6,
         a2: 1,
         a3: v13,
         a4: nullptr,
         a5: nullptr,
         a6: v11,
         a7: 2u,
         a8: (int *)&a3,
         a9: nullptr) != 0 )
  {
    *(_DWORD *)a4 = 0;
    return 0;
  }
  result = D3DXShader::CalcNumRegisters(this: *((D3DXShader **)a3 + 8), a2: a4, a3: nullptr, a4: v12);
  if ( result >= 0 )
  {
    if ( *(_WORD *)v5 == *(_WORD *)"b_" )
    {
      if ( *v8 == 1 )
      {
        v9 = *((_DWORD **)a3 + 8);
        if ( v9[1] == 9 && v9[4] == 0 && v9[5] == 0 )
          return 0;
      }
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)this + 4) + 24),
        (const char **)a2,
        a3: 0xB54u,
        format: "boolean constant register '%s' must be defined as a variable of type bool only",
        v5);
    }
    else
    {
      if ( *(_WORD *)v5 != *(_WORD *)"i_" )
        return 0;
      if ( *v8 == 1 )
      {
        v10 = *((_DWORD **)a3 + 8);
        if ( v10[1] == 9 && v10[4] == 1 && v10[5] == 4 && v10[7] >= 3u )
          return 0;
      }
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)this + 4) + 24),
        (const char **)a2,
        a3: 0xB55u,
        format: "integer constant register '%s' must be defined as a variable of type int3 or int4 only",
        v5);
    }
    return -2147467259;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DFD8D
// Name: long D3DXShader::EmitDefaultValue(class D3DXShader::CCommentBlock __near *,unsigned int,unsigned int,class D3DXShader::CNode __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::EmitDefaultValue(
        D3DXShader *this,
        struct D3DXShader::CCommentBlock *a2,
        unsigned int a3,
        unsigned int a4,
        struct D3DXShader::CNode *a5,
        unsigned int *a6)
{
  int v6; // edi
  _DWORD *v7; // esi
  unsigned int v8; // ebx
  char *v9; // edi
  unsigned int v11; // edi
  float *v12; // ecx
  int v13; // eax
  char *pMem; // [esp+4h] [ebp-4h]
  struct D3DXShader::CCommentBlock *v16; // [esp+14h] [ebp+Ch]
  struct D3DXShader::CCommentBlock *v17; // [esp+1Ch] [ebp+14h]

  v6 = 0;
  pMem = nullptr;
  if ( *(_DWORD *)(a4 + 4) != 13 )
    return 0;
  v7 = *(_DWORD **)(a4 + 32);
  if ( v7[1] == 1 )
  {
    v8 = 16 * (_DWORD)a2;
    v9 = (char *)MemAlloc_Alloc(nSize: 16 * (_DWORD)a2);
    pMem = v9;
    if ( v9 != nullptr )
    {
      memset(v9, 0, v8);
      if ( a2 != nullptr )
      {
        v16 = (struct D3DXShader::CCommentBlock *)v9;
        v17 = a2;
        do
        {
          v11 = a3;
          if ( a3 != 0 )
          {
            v12 = (float *)v16;
            do
            {
              v13 = v7[2];
              if ( *(_DWORD *)(v13 + 16) == 3 )
                *v12 = *(double *)(v13 + 24);
              else
                *v12 = *(float *)(v13 + 24);
              v7 = (_DWORD *)v7[3];
              ++v12;
              --v11;
            }
            while ( v11 != 0 );
          }
          v16 = (struct D3DXShader::CCommentBlock *)((char *)v16 + 16);
          v17 = (struct D3DXShader::CCommentBlock *)((char *)v17 - 1);
        }
        while ( v17 != nullptr );
      }
      v6 = D3DXShader::CCommentBlock::Add(this, pMem, nSize: v8, a4: 6u, (unsigned int *)a5);
    }
    else
    {
      v6 = -2147024882;
    }
  }
  free(pMem);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101DFE50
// Name: long D3DXShader::EmitZeroDefaultValue(class D3DXShader::CCommentBlock __near *,unsigned int,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::EmitZeroDefaultValue(
        D3DXShader *this,
        struct D3DXShader::CCommentBlock *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v4; // esi
  void *v5; // ebx
  int v6; // esi

  v4 = 16 * (_DWORD)a2;
  v5 = MemAlloc_Alloc(nSize: 16 * (_DWORD)a2);
  if ( v5 != nullptr )
  {
    memset(v5, 0, v4);
    v6 = D3DXShader::CCommentBlock::Add(this, pMem: (char *)v5, nSize: v4, a4: 6u, a5: a3);
  }
  else
  {
    v6 = -2147024882;
  }
  free(pMem: v5);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101DFEA7
// Name: public: long D3DXShader::CFragmentConstants::AddRegister(class D3DXShader::CCommentBlock __near *,struct _D3DXSHADER_CONSTANTINFO __near *,char const __near *,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFragmentConstants::AddRegister(
        struct D3DXShader::CNodeScope ***this,
        struct D3DXShader::CCommentBlock *a2,
        struct _D3DXSHADER_CONSTANTINFO *a3,
        char *a4,
        __int16 a5,
        unsigned int a6)
{
  struct D3DXShader::CNode *i; // edi
  bool v7; // zf
  struct _D3DXSHADER_CONSTANTINFO *v8; // esi
  int result; // eax
  D3DXShader::CParse *v10; // ecx
  int v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  const char *v14; // ecx
  int v15; // eax
  struct _D3DXSHADER_CONSTANTINFO *v16; // edi
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // eax
  struct D3DXShader::CNodeScope **v21; // [esp-10h] [ebp-78h]
  unsigned int *v22; // [esp+0h] [ebp-68h]
  unsigned int *v23; // [esp+0h] [ebp-68h]
  const char *v24[8]; // [esp+Ch] [ebp-5Ch] BYREF
  _WORD pMem[6]; // [esp+2Ch] [ebp-3Ch] BYREF
  int v26; // [esp+38h] [ebp-30h]
  int v27; // [esp+3Ch] [ebp-2Ch] BYREF
  int v28; // [esp+40h] [ebp-28h]
  unsigned int v29; // [esp+48h] [ebp-20h] BYREF
  D3DXShader::CFragmentConstants *v30; // [esp+4Ch] [ebp-1Ch]
  const char *v31; // [esp+50h] [ebp-18h]
  struct _D3DXSHADER_CONSTANTINFO *v32; // [esp+54h] [ebp-14h]
  struct _D3DXSHADER_CONSTANTINFO *v33; // [esp+58h] [ebp-10h]
  int v34; // [esp+5Ch] [ebp-Ch]
  struct D3DXShader::CCommentBlock *v35; // [esp+60h] [ebp-8h] BYREF
  int v36; // [esp+64h] [ebp-4h] BYREF
  struct _D3DXSHADER_CONSTANTINFO *v37; // [esp+74h] [ebp+Ch]

  HIBYTE(a6) |= 0x80u;
  i = (struct D3DXShader::CNode *)a4;
  v7 = *(_WORD *)"c_" == *(_WORD *)a4;
  v30 = (D3DXShader::CFragmentConstants *)this;
  v36 = 0;
  if ( v7 || *(_WORD *)"b_" == *(_WORD *)a4 || *(_WORD *)"i_" == *(_WORD *)a4 || *(_WORD *)"s_" == *(_WORD *)a4 )
  {
    v31 = a4 + 2;
    v24[2] = a4 + 2;
    v21 = *(this + 1);
    v10 = (D3DXShader::CParse *)*this;
    v24[0] = (const char *)10;
    v24[4] = nullptr;
    v24[5] = nullptr;
    D3DXShader::CParse::FindDecl(
      this: v10,
      a2: 1,
      a3: v24,
      a4: nullptr,
      a5: nullptr,
      a6: v21,
      a7: 2u,
      a8: &v36,
      a9: nullptr);
    result = D3DXShader::CalcNumRegisters(
               this: *(D3DXShader **)(v36 + 32),
               a2: (struct D3DXShader::CNode *)&v35,
               a3: &v29,
               a4: v22);
    if ( result < 0 )
      return result;
    v8 = a3;
    if ( *(_DWORD *)(v36 + 48) != 0 )
    {
      v11 = *(_DWORD *)(v36 + 48);
      v37 = nullptr;
      v33 = nullptr;
      v32 = nullptr;
      v34 = v11;
      if ( v11 != 0 )
      {
        do
        {
          v12 = *(_DWORD **)(v34 + 8);
          if ( v12[1] == 17 )
          {
            v13 = v12[4];
            if ( v13 != 0 )
              v14 = *(const char **)(v13 + 24);
            else
              v14 = nullptr;
            v15 = v12[5];
            if ( v15 != 0 )
              v16 = *(struct _D3DXSHADER_CONSTANTINFO **)(v15 + 24);
            else
              v16 = nullptr;
            if ( v14 != nullptr )
            {
              if ( D3DXGetTargetDescByName(a1: v14, a2: 0, a3: &v27) >= 0
                && v16 != nullptr
                && tolower(c: *(char *)v16) == *a4 )
              {
                if ( a6 == v28 )
                {
                  v37 = v16;
                }
                else if ( ((a6 ^ v28) & 0xFFFF0000) == 0 && (_WORD)v28 == 0 )
                {
                  v33 = v16;
                }
              }
            }
            else if ( v16 != nullptr && tolower(c: *(char *)v16) == *a4 )
            {
              v32 = v16;
            }
          }
          v34 = *(_DWORD *)(v34 + 12);
        }
        while ( v34 != 0 );
        i = (struct D3DXShader::CNode *)a4;
        if ( v37 != nullptr )
          goto LABEL_33;
      }
      v37 = v33;
      if ( v33 != nullptr || (v37 = v32, v32 != nullptr) )
      {
LABEL_33:
        if ( *(char *)i == tolower(c: *(char *)v37) )
        {
          i = v37;
          if ( isdigit(c: *((char *)v37 + 1)) != 0 )
          {
            for ( i = (struct _D3DXSHADER_CONSTANTINFO *)((char *)v37 + 2);
                  isdigit(c: *(char *)i) != 0;
                  i = (struct D3DXShader::CNode *)((char *)i + 1) )
            {
              ;
            }
            if ( *(_BYTE *)i == 0 )
            {
              v17 = atoi(nptr: (const char *)v37 + 1);
              if ( v17 > 0x1FFF )
              {
                D3DXShader::CTErrors::Error(
                  this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)v30 + 4) + 24),
                  a2: nullptr,
                  a3: 0xB56u,
                  format: "Constant variable '%s' bound to register greater than 8191 (%d requested)",
                  v31,
                  v17);
                return -2147467259;
              }
              *((_WORD *)v8 + 5) |= (unsigned __int16)(4 * v17) | 2;
            }
          }
        }
      }
    }
    v18 = v36;
    if ( (*(_BYTE *)(v36 + 28) & 2) != 0 )
      *((_BYTE *)v8 + 10) |= 1u;
    v19 = *(_DWORD *)(v18 + 40);
    if ( v19 == 0 )
    {
      if ( *(_DWORD *)(v18 + 36) == 0 )
      {
        if ( (*((_BYTE *)v8 + 10) & 1) == 0 )
        {
LABEL_50:
          v20 = *(_DWORD *)(v36 + 32);
          if ( *(_DWORD *)(v20 + 4) != 9 || *(_DWORD *)(v20 + 20) != 20 )
          {
            result = D3DXShader::EmitTypeInfo(
                       a1: i,
                       this: a2,
                       a3: *(struct D3DXShader::CCommentBlock **)(v36 + 32),
                       pMem: (struct D3DXShader::CNode *)1,
                       a5: 0,
                       a6: (unsigned int *)v8 + 3,
                       a7: v23);
            if ( result < 0 )
              return result;
            goto LABEL_56;
          }
          D3DXShader::CTErrors::Error(
            this: (D3DXShader::CTErrors *)(*(_DWORD *)(*(_DWORD *)v30 + 4) + 24),
            a2: nullptr,
            a3: 0xB59u,
            format: "Sampler variable '%s' does not specify the sampler type.  Explicit sampler types required for asm fragments.",
            v31);
          return -2147467259;
        }
        result = D3DXShader::EmitZeroDefaultValue(this: a2, a2: v35, a3: (unsigned int *)v8 + 4, a4: v23);
LABEL_49:
        if ( result < 0 )
          return result;
        goto LABEL_50;
      }
      v19 = *(_DWORD *)(v18 + 36);
    }
    result = D3DXShader::EmitDefaultValue(
               this: a2,
               a2: v35,
               a3: v29,
               a4: v19,
               a5: (struct _D3DXSHADER_CONSTANTINFO *)((char *)v8 + 16),
               a6: v23);
    goto LABEL_49;
  }
  v8 = a3;
  pMem[0] = 1;
  pMem[1] = 3;
  pMem[2] = 1;
  pMem[3] = 4;
  pMem[4] = 1;
  pMem[5] = 0;
  v26 = 0;
  result = D3DXShader::CCommentBlock::Add(this: a2, (char *)pMem, nSize: 0x10u, a4: 6u, a5: (unsigned int *)a3 + 3);
  if ( result < 0 )
    return result;
  v35 = (struct D3DXShader::CCommentBlock *)1;
LABEL_56:
  result = D3DXShader::CCommentBlock::Add(this: a2, pMem: a4, nSize: 0xFFFFFFFF, a4: 7u, a5: (unsigned int *)v8);
  if ( result >= 0 )
  {
    if ( *(_WORD *)"b_" == *(_WORD *)a4 )
      *((_WORD *)v8 + 2) = 0;
    else
      *((_WORD *)v8 + 2) = (*(_WORD *)"i_" != *(_WORD *)a4) + 1;
    *((_WORD *)v8 + 3) = a5;
    *((_WORD *)v8 + 4) = (_WORD)v35;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E01F2
// Name: public: D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmInstruction *__thiscall D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(
        D3DXShader::CNodeAsmInstruction *this)
{
  D3DXShader::CNode::CNode(this, a2: 18);
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *(_DWORD *)this = &D3DXShader::CNodeAsmInstruction::`vftable';
  memset((char *)this + 16, 0, 0x20u);
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E0230
// Name: public: D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(struct D3DXShader::D3DXTOKEN const __near *,unsigned long,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmInstruction *__thiscall D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(
        D3DXShader::CNodeAsmInstruction *this,
        const struct D3DXShader::D3DXTOKEN *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  D3DXShader::CNode::CNode(this, a2: 18);
  *(_DWORD *)this = &D3DXShader::CNodeAsmInstruction::`vftable';
  qmemcpy((char *)this + 16, a2, 0x20u);
  *((_DWORD *)this + 12) = a3;
  *((_DWORD *)this + 13) = a4;
  *((_DWORD *)this + 14) = a5;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E0282
// Name: public: D3DXShader::CNodeAsmRegister::CNodeAsmRegister(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmRegister *__thiscall D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
        D3DXShader::CNodeAsmRegister *this)
{
  D3DXShader::CNode::CNode(this, a2: 19);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 10) = 0;
  *(_DWORD *)this = &D3DXShader::CNodeAsmRegister::`vftable';
  *((_DWORD *)this + 8) = 983040;
  *((_DWORD *)this + 9) = 14942208;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E02B7
// Name: public: D3DXShader::CNodeAsmRegister::CNodeAsmRegister(unsigned long,unsigned long,unsigned long,int,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeAsmRegister *__thiscall D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
        D3DXShader::CNodeAsmRegister *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        struct D3DXShader::CNode *a6)
{
  D3DXShader::CNode::CNode(this, a2: 19);
  *((_DWORD *)this + 4) = a2;
  *((_DWORD *)this + 5) = a3;
  *((_DWORD *)this + 6) = a4;
  *((_DWORD *)this + 7) = a5;
  *((_DWORD *)this + 10) = a6;
  *(_DWORD *)this = &D3DXShader::CNodeAsmRegister::`vftable';
  *((_DWORD *)this + 8) = 983040;
  *((_DWORD *)this + 9) = 14942208;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E0427
// Name: public: D3DXShader::CInstruction::CInstruction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CInstruction *__thiscall D3DXShader::CInstruction::CInstruction(D3DXShader::CInstruction *this)
{
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E045D
// Name: public: long D3DXShader::CInstruction::Instance(class D3DXShader::CInstruction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CInstruction::Instance(D3DXShader::CInstruction *this, struct D3DXShader::CInstruction *a2)
{
  if ( a2 == nullptr )
    return -2147467259;
  *((_DWORD *)this + 15) = *((_DWORD *)a2 + 15);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E047C
// Name: public: unsigned int D3DXShader::CInstruction::GetInputs(unsigned int,unsigned int __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CInstruction::GetInputs(D3DXShader::CInstruction *this, unsigned int a2, unsigned int **a3)
{
  int result; // eax

  result = *(_DWORD *)this & 0xFFFFF;
  if ( a2 * result + result <= *((_DWORD *)this + 1) )
  {
    if ( a3 != nullptr )
      *a3 = (unsigned int *)(*((_DWORD *)this + 2) + 4 * a2 * result);
  }
  else
  {
    if ( a3 != nullptr )
      *a3 = nullptr;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E04B9
// Name: public: int D3DXShader::CInstruction::IsSpecial(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsSpecial(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax
  BOOL result; // eax

  result = true;
  if ( (*(_DWORD *)this & 0xF0000000) != 0x60000000 )
  {
    v1 = *(_DWORD *)this & 0xFFF00000;
    if ( v1 != 1343225856 && v1 != 1344274432 && v1 != 1345323008 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E04EC
// Name: public: int D3DXShader::CInstruction::IsScalar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsScalar(D3DXShader::CInstruction *this)
{
  void *v1; // eax

  v1 = (void *)(*(_DWORD *)this & 0xFFF00000);
  return v1 == &unk_10300000 || v1 == (void *)273678336 || v1 == (void *)274726912 || v1 == (void *)275775488;
}

//------------------------------------------------------------------------------
// Address: 0x101E0516
// Name: public: int D3DXShader::CInstruction::IsSymetric(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsSymetric(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 0x20000000 || v1 == 537919488 || v1 == 541065216 || v1 == 542113792 || v1 == 1342177280;
}

//------------------------------------------------------------------------------
// Address: 0x101E0547
// Name: public: int D3DXShader::CInstruction::IsCopy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsCopy(D3DXShader::CInstruction *this)
{
  void *v1; // eax

  v1 = (void *)(*(_DWORD *)this & 0xFFF00000);
  return v1 == (void *)0x10000000
      || v1 == &loc_10100000
      || v1 == (void *)287309824
      || v1 == (void *)544210944
      || v1 == (void *)545259520
      || v1 == (void *)546308096;
}

//------------------------------------------------------------------------------
// Address: 0x101E057F
// Name: public: int D3DXShader::CInstruction::IsMacro(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsMacro(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x70700000 )
  {
    if ( v1 == 1890582528 || v1 == 1891631104 || v1 == 1892679680 )
      return true;
    return v1 == 1895825408;
  }
  else
  {
    if ( v1 == 1886388224 || v1 == 1345323008 || v1 == 1880096768 || v1 == 1881145344 || v1 == 1884291072 )
      return true;
    return v1 == 1885339648;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E05D7
// Name: public: int D3DXShader::CInstruction::IsLoop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsLoop(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x74200000 )
  {
    if ( v1 == 1949302784
      || v1 == 1950351360
      || v1 == 1951399936
      || v1 == 1952448512
      || v1 == 1953497088
      || v1 == 1956642816 )
    {
      return true;
    }
    return v1 == 1957691392;
  }
  else
  {
    if ( v1 == 1948254208 )
      return true;
    if ( v1 > 0x11500000 )
    {
      if ( v1 == 545259520 || v1 == 546308096 )
        return true;
      return v1 == 1947205632;
    }
    else
    {
      if ( v1 == 290455552 || v1 == 286261248 || v1 == 287309824 || v1 == 288358400 )
        return true;
      return v1 == 289406976;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E065D
// Name: public: int D3DXShader::CInstruction::IsElse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsElse(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 1930428416
      || v1 == 1932525568
      || v1 == 1943011328
      || v1 == 1944059904
      || v1 == 1945108480
      || v1 == 1946157056;
}

//------------------------------------------------------------------------------
// Address: 0x101E0695
// Name: public: int D3DXShader::CInstruction::IsEndIf(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsEndIf(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  return v1 == 544210944 || v1 == 1933574144;
}

//------------------------------------------------------------------------------
// Address: 0x101E06B1
// Name: public: int D3DXShader::CInstruction::IsFlowControl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsFlowControl(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x73800000 )
  {
    if ( v1 > 0x74100000 )
    {
      if ( v1 > 0x74600000 )
      {
        if ( v1 == 1953497088 || v1 == 1956642816 )
          return true;
        return v1 == 1957691392;
      }
      else
      {
        if ( v1 == 1952448512 || v1 == 1948254208 || v1 == 1949302784 || v1 == 1950351360 )
          return true;
        return v1 == 1951399936;
      }
    }
    else
    {
      if ( v1 == 1947205632 )
        return true;
      if ( v1 > 0x73D00000 )
      {
        if ( v1 == 1944059904 || v1 == 1945108480 )
          return true;
        return v1 == 1946157056;
      }
      else
      {
        if ( v1 == 1943011328 || v1 == 1938817024 || v1 == 1939865600 || v1 == 1940914176 )
          return true;
        return v1 == 1941962752;
      }
    }
  }
  else
  {
    if ( v1 == 1937768448 )
      return true;
    if ( v1 > 0x20900000 )
    {
      if ( v1 > 0x73400000 )
      {
        if ( v1 == 1934622720 || v1 == 1935671296 )
          return true;
        return v1 == 1936719872;
      }
      else
      {
        if ( v1 == 1933574144 || v1 == 1929379840 || v1 == 1930428416 || v1 == 1931476992 )
          return true;
        return v1 == 1932525568;
      }
    }
    else
    {
      if ( v1 == 546308096 )
        return true;
      if ( v1 > 0x11400000 )
      {
        if ( v1 == 290455552 || v1 == 544210944 )
          return true;
        return v1 == 545259520;
      }
      else
      {
        if ( v1 == 289406976 || v1 == 284164096 || v1 == 286261248 || v1 == 287309824 )
          return true;
        return v1 == 288358400;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0818
// Name: public: int D3DXShader::CInstruction::IsGradient(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CInstruction::IsGradient(D3DXShader::CInstruction *this)
{
  unsigned int v1; // eax

  v1 = *(_DWORD *)this & 0xFFF00000;
  if ( v1 > 0x60800000 )
  {
    if ( v1 == 1621098496 || v1 == 1623195648 || v1 == 1624244224 || v1 == 1626341376 || v1 == 1628438528 )
      return true;
    return v1 == 1629487104;
  }
  else
  {
    if ( v1 == 1619001344
      || v1 == 282066944
      || v1 == 283115520
      || v1 == 1610612736
      || v1 == 1612709888
      || v1 == 1613758464
      || v1 == 1615855616 )
    {
      return true;
    }
    return v1 == 1617952768;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E088C
// Name: public: static void D3DXShader::CInstruction::SetAlloc(class D3DXCore::CAlloc __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall D3DXShader::CInstruction::SetAlloc(struct D3DXCore::CAlloc *a1)
{
  D3DXShader::CInstruction::s_pFree = nullptr;
  D3DXShader::CInstruction::s_pAlloc = a1;
}

//------------------------------------------------------------------------------
// Address: 0x101E08A4
// Name: public: static unsigned int __near * D3DXShader::CInstruction::Alloc(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static unsigned __int8 *__stdcall D3DXShader::CInstruction::Alloc(unsigned int a1)
{
  return D3DXCore::CAlloc::Alloc(this: D3DXShader::CInstruction::s_pAlloc, a2: 4 * a1, dwSize: 0x10u);
}
