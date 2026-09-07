// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxstatictext.cpp
// Functions: 42
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxstatictext.h"

//------------------------------------------------------------------------------
// Address: 0x100844D0
// Name: public: virtual class GRect<float> GFxCharacter::GetBounds(class GMatrix3D const __near &,bool)const
// Source: rtti_class
//------------------------------------------------------------------------------
CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxCharacter::GetBounds(
        void *this,
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result,
        float *a3,
        float bDivideByW)
{
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v4; // eax
  _BYTE v6[16]; // [esp+4h] [ebp-10h] BYREF

  v4 = (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(*(int (__thiscall **)(void *, _BYTE *, GMatrix2D *))(*(_DWORD *)this + 52))(a1: this, a2: v6, a3: &GMatrix2D::Identity);
  *(float *)&result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = 0.0;
  *(float *)&result->m_nUserID = 0.0;
  *(float *)&result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = 0.0;
  *(float *)&result->m_iRefs = 0.0;
  GMatrix3D::EncloseTransform(
    this: a3,
    (const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)result,
    r: v4,
    bDivideByW);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10085280
// Name: public: virtual class GRect<float> GFxGenericCharacter::GetBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
CMatRenderContextBase *__userpurge GFxGenericCharacter::GetBounds@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CMatRenderContextBase *transform,
        __int128 a3,
        Vector4D *const *a4)
{
  float *v4; // eax
  _BYTE v6[16]; // [esp+4h] [ebp-10h] BYREF

  v4 = (float *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)this + 30) + 24))(
                  a1: *((_DWORD *)this + 30),
                  a2: v6);
  *(float *)&transform->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = 0.0;
  *(float *)&transform->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = 0.0;
  *(float *)&transform->m_iRefs = 0.0;
  *(float *)&transform->m_pCurrentMaterial = 0.0;
  GMatrix2D::EncloseTransform(this: (float *)a3, a2: (float *)transform, a3: v4);
  return transform;
}

//------------------------------------------------------------------------------
// Address: 0x100852C0
// Name: public: virtual class GRect<float> GFxGenericCharacter::GetRectBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
CMatRenderContextBase *__userpurge GFxGenericCharacter::GetRectBounds@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CMatRenderContextBase *transform,
        __int128 a3,
        Vector4D *const *a4)
{
  float *v4; // eax
  _BYTE v6[16]; // [esp+4h] [ebp-10h] BYREF

  v4 = (float *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)this + 30) + 28))(
                  a1: *((_DWORD *)this + 30),
                  a2: v6);
  *(float *)&transform->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = 0.0;
  *(float *)&transform->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = 0.0;
  *(float *)&transform->m_iRefs = 0.0;
  *(float *)&transform->m_pCurrentMaterial = 0.0;
  GMatrix2D::EncloseTransform(this: (float *)a3, a2: (float *)transform, a3: v4);
  return transform;
}

//------------------------------------------------------------------------------
// Address: 0x100B0180
// Name: public: virtual class GRect<float> GFxCharacterDef::GetBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall GFxCharacterDef::GetBoundsLocal(GFxAmpMessageCurrentState *this, const GFxAmpMessageCurrentState *a2)
{
  *(float *)&a2->__vftable = 0.0;
  *(float *)&a2->RefCount = 0.0;
  *(float *)&a2->pPrev = 0.0;
  *(float *)&a2->pNext = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10137860
// Name: public: void GFxTextFieldParam::LoadFromTextFilter(struct GFxTextFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextFieldParam::LoadFromTextFilter(int this, const CResourcePreloadMaterial *result)
{
  char v2; // dl
  char v3; // al

  *(_WORD *)(this + 8) = result[2].__vftable;
  *(_BYTE *)(this + 7) = 0x80;
  *(_BYTE *)(this + 10) = BYTE2(result[2].__vftable);
  v2 = HIBYTE(result[2].__vftable);
  if ( (v2 & 1) == 0 )
  {
    *(_BYTE *)(this + 19) = v2 & 0xFE;
    *(_WORD *)(this + 20) = result[3].__vftable;
    *(_BYTE *)(this + 22) = BYTE2(result[3].__vftable);
    *(CResourcePreloadMaterial *)(this + 24) = result[7];
    *(_WORD *)(this + 28) = HIWORD(result[5].__vftable);
    *(_WORD *)(this + 30) = result[6].__vftable;
  }
  *(CResourcePreloadMaterial *)(this + 32) = result[8];
  v3 = (char)result[4].__vftable;
  *(_BYTE *)(this + 36) = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101378D0
// Name: public: void GFxTextLineBuffer::GlyphEntry::SetFontSize(float)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall GFxTextLineBuffer::GlyphEntry::SetFontSize(_WORD *this, const CIndexBufferBase *result)
{
  double v2; // st7
  int v3; // eax
  __int16 v4; // dx
  __int16 v5; // dx
  __int16 v6; // ax

  v2 = *(float *)&result;
  if ( *(float *)&result < 256.0 && ((v3 = (__int64)(16.0 * v2)) & 0xF) != 0 )
  {
    v4 = *(this + 2);
    *(this + 3) |= 0x10u;
    v5 = v3 ^ v4;
    *(this + 2) ^= v5 & 0xFFF;
    return 4095;
  }
  else
  {
    *(this + 3) &= ~0x10u;
    v6 = (*(this + 2) ^ (int)v2) & 0xFFF;
    *(this + 2) ^= v6;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10137970
// Name: public: int GFxTextLineBuffer::Line::GetHeight(void)const
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall GFxTextLineBuffer::Line::GetHeight(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  if ( (int)this->m_pAllocator >= 0 )
    return *((CFunctor **)this + 6);
  else
    return (CFunctor *)*((unsigned __int16 *)this + 11);
}

//------------------------------------------------------------------------------
// Address: 0x10137990
// Name: public: int GFxStaticTextSnapshotData::FindTextA(unsigned int,char const __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStaticTextSnapshotData::FindTextA(
        GFxStaticTextSnapshotData *this,
        signed int a2,
        CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer,
        bool a4)
{
  char *Char; // eax
  bool (__cdecl *v6)(const char *const *, const char *const *); // ecx
  signed int v7; // ebx
  char *i; // esi
  char *v10; // edi
  char *v11; // eax
  int v12; // edi
  unsigned int v13; // esi
  unsigned int v14; // eax
  bool v15; // zf
  unsigned int v16; // edx
  unsigned int v17; // ecx
  CUtlMap<char const *,int,unsigned short>::CKeyLess v18; // [esp+Ch] [ebp-10h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess v19; // [esp+10h] [ebp-Ch] BYREF
  char *c; // [esp+14h] [ebp-8h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess v21; // [esp+18h] [ebp-4h] BYREF

  Char = (char *)GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
  v6 = (bool (__cdecl *)(const char *const *, const char *const *))(((int)*(this + 3) & 0xFFFFFFFC) + 8);
  c = Char;
  v21.m_LessFunc = v6;
  v7 = 0;
  for ( i = (char *)GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&v21);
        i != nullptr;
        i = (char *)GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&v21) )
  {
    if ( v7 >= a2 )
    {
      if ( a4 )
      {
        if ( i == c )
          goto LABEL_12;
      }
      else
      {
        v10 = i - 32;
        if ( (unsigned int)(i - 97) > 0x19 )
          v10 = i;
        G_toupper(c);
        if ( v10 == v11 )
        {
LABEL_12:
          v18.m_LessFunc = v21.m_LessFunc;
          v19.m_LessFunc = putf8Buffer.m_LessFunc;
          do
          {
            v12 = -1;
            v13 = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&v19);
            do
            {
              v14 = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&v18);
              ++v12;
            }
            while ( v14 == 10 );
            if ( v14 == 0 )
              break;
            if ( v13 == 0 )
              return v7;
            if ( a4 )
            {
              v15 = v14 == v13;
            }
            else
            {
              v16 = v14 - 32;
              if ( v14 - 97 > 0x19 )
                v16 = v14;
              v17 = v13 - 32;
              if ( v13 - 97 > 0x19 )
                v17 = v13;
              v15 = v16 == v17;
            }
          }
          while ( v15 );
          if ( v13 == 0 )
            return v7;
          if ( v14 == 0 )
            return -1;
          v7 -= v12;
          goto LABEL_7;
        }
      }
    }
    if ( i == (char *)10 )
      --v7;
LABEL_7:
    ++v7;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10137B30
// Name: public: void GFxTextLineBuffer::GlyphEntry::SetAdvance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::GlyphEntry::SetAdvance(CIndexBufferBase *this, const char *v)
{
  if ( (int)v < 0 )
  {
    HIWORD(this->m_pBudgetGroupName) |= 0x40u;
    HIWORD(this->__vftable) = abs32((int)v);
  }
  else
  {
    HIWORD(this->__vftable) = (_WORD)v;
    HIWORD(this->m_pBudgetGroupName) &= ~0x40u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137B60
// Name: public: float GFxStaticTextRecord::GetCumulativeAdvance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxStaticTextRecord::GetCumulativeAdvance(GFxStaticTextRecord *this)
{
  int v1; // esi
  unsigned int v2; // edi
  int v3; // eax
  unsigned int v4; // edx
  double v5; // st7
  float *v6; // eax
  unsigned int v7; // esi
  double v8; // st7
  float advance; // [esp+4h] [ebp-4h]
  float advancea; // [esp+4h] [ebp-4h]
  float advanceb; // [esp+4h] [ebp-4h]
  float advancec; // [esp+4h] [ebp-4h]

  v1 = *((_DWORD *)this + 1);
  advance = 0.0;
  v2 = 0;
  if ( v1 >= 4 )
  {
    v3 = *(_DWORD *)this + 12;
    v4 = ((unsigned int)(v1 - 4) >> 2) + 1;
    v2 = 4 * v4;
    do
    {
      v5 = *(float *)(v3 - 8);
      v3 += 32;
      --v4;
      advancea = v5 + advance;
      advanceb = advancea + *(float *)(v3 - 32);
      advancec = advanceb + *(float *)(v3 - 24);
      advance = advancec + *(float *)(v3 - 16);
    }
    while ( v4 != 0 );
  }
  if ( v2 < v1 )
  {
    v6 = (float *)(*(_DWORD *)this + 8 * v2 + 4);
    v7 = v1 - v2;
    do
    {
      v8 = *v6;
      v6 += 2;
      --v7;
      advance = v8 + advance;
    }
    while ( v7 != 0 );
  }
  return advance;
}

//------------------------------------------------------------------------------
// Address: 0x10137BE0
// Name: public: virtual bool GFxStaticTextCharacterDef::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxStaticTextCharacterDef::DefPointTestLocal(float *this, float *testShape, int a3, int pinst)
{
  return *(this + 6) >= (double)*testShape
      && *(this + 4) <= (double)*testShape
      && *(this + 7) >= (double)testShape[1]
      && *(this + 5) <= (double)testShape[1];
}

//------------------------------------------------------------------------------
// Address: 0x10137C30
// Name: public: unsigned int GFxStaticTextSnapshotData::GetCharCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxStaticTextSnapshotData::GetCharCount(GFxStaticTextSnapshotData *this)
{
  int v1; // edx
  GFxAmpMessageAppControl *pObject; // ebx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // eax
  GFxStaticTextSnapshotData v6; // eax
  unsigned int v7; // edx
  int v9; // [esp+Ch] [ebp-8h]

  v1 = *((_DWORD *)this + 1);
  pObject = nullptr;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( v1 >= 2 )
  {
    v6 = *this + 3;
    v7 = ((unsigned int)(v1 - 2) >> 1) + 1;
    v9 = 2 * v7;
    do
    {
      v3 += (int)v6[-2].pObject;
      v4 += (int)v6->pObject;
      v6 += 4;
      --v7;
    }
    while ( v7 != 0 );
    pObject = nullptr;
    v5 = v9;
  }
  if ( v5 < *((_DWORD *)this + 1) )
    pObject = (*this)[2 * v5 + 1].pObject;
  return (unsigned int)pObject + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x10137C90
// Name: public: class GString GFxStaticTextSnapshotData::GetSubString(unsigned int,unsigned int,bool)const
// Source: json
//------------------------------------------------------------------------------
const GPtr<GFxAmpViewStats> *__thiscall GFxStaticTextSnapshotData::GetSubString(
        GPtr<GFxAmpViewStats> *this,
        CUtlMemory<CImagePacker,int> *start,
        unsigned int starta,
        unsigned int end,
        bool binclNewLines)
{
  unsigned int *v5; // esi
  int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ebx
  CImagePacker *Char; // eax

  v5 = (unsigned int *)start;
  GString::GString(this: start);
  v7 = *((_DWORD *)this + 3);
  v8 = starta;
  v9 = end;
  start = (CUtlMemory<CImagePacker,int> *)((v7 & 0xFFFFFFFC) + 8);
  while ( v8 < v9 )
  {
    Char = (CImagePacker *)GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&start);
    if ( Char == nullptr )
      break;
    if ( Char == (CImagePacker *)10 )
    {
      if ( binclNewLines )
        GString::AppendChar(this: v5, result: (CImagePacker *)0xA);
    }
    else
    {
      GString::AppendChar(this: v5, result: Char);
      ++v8;
    }
  }
  return (const GPtr<GFxAmpViewStats> *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10137D00
// Name: public: class GString GFxStaticTextSnapshotData::GetSelectedText(bool)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__thiscall GFxStaticTextSnapshotData::GetSelectedText(
        GPtr<GFxAmpViewStats> *this,
        CUtlMemory<CImagePacker,int> *binclNewLines,
        bool binclNewLinesa)
{
  GPtr<GFxAmpViewStats> *v4; // edi
  unsigned int v5; // edx
  unsigned int v6; // esi
  IResourceAccessControl *v7; // ecx
  char v8; // al
  char *v9; // eax
  char *v10; // edi
  CImagePacker *Char; // eax
  char v12; // al
  IVJobs v14; // [esp+Ch] [ebp-6Ch] BYREF
  int (__cdecl *desc)(const char *const *, const char *const *); // [esp+44h] [ebp-34h] BYREF
  int v16; // [esp+48h] [ebp-30h]
  GPtr<GFxAmpViewStats> *v17; // [esp+6Ch] [ebp-Ch]
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+70h] [ebp-8h] BYREF
  unsigned int i; // [esp+74h] [ebp-4h]
  unsigned int baseIdx; // [esp+80h] [ebp+8h]

  v4 = this;
  v17 = this;
  GString::GString(this: binclNewLines);
  v5 = 0;
  v6 = 0;
  baseIdx = 0;
  putf8Buffer.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))(((int)v4[3].pObject & 0xFFFFFFFC)
                                                                                      + 8);
  for ( i = 0; (GFxAmpViewStats *)v5 < v4[1].pObject; i = ++v5 )
  {
    v7 = *(IResourceAccessControl **)(*((_DWORD *)v4->pObject + 2 * v5) + 372);
    if ( v7 != nullptr )
    {
      GFxTextHighlighter::GetRangeIterator(
        this: v7,
        startPos: (struct ResourceList_t__ *)&v14,
        flags: RESOURCE_VGUI_PANEL,
        a4: (const char *)0xFFFFFFFF);
      GFxTextHighlighterRangeIterator::IsFinished(this: &v14);
      if ( v8 == 0 )
      {
        do
        {
          GFxTextHighlighterRangeIterator::operator*(
            this: (IPrecacheHandler *)&v14,
            a2: (const IPrecacheHandler *)&desc);
          v9 = (char *)desc + baseIdx;
          v10 = (char *)desc + baseIdx + v16;
          desc = (int (__cdecl *)(const char *const *, const char *const *))((char *)desc + baseIdx);
          if ( (unsigned int)v10 > v6 )
          {
            if ( v6 < (unsigned int)v9 )
            {
              do
              {
                if ( GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer) == 10 )
                  --v6;
                ++v6;
              }
              while ( v6 < (unsigned int)desc );
            }
            if ( v6 < (unsigned int)v10 )
            {
              while ( 1 )
              {
                Char = (CImagePacker *)GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
                if ( binclNewLinesa )
                {
                  if ( Char == (CImagePacker *)10 )
                  {
                    GString::AppendChar(this: (unsigned int *)binclNewLines, result: (CImagePacker *)0xA);
                  }
                  else
                  {
LABEL_14:
                    GString::AppendChar(this: (unsigned int *)binclNewLines, result: Char);
                    if ( ++v6 >= (unsigned int)v10 )
                      break;
                  }
                }
                else if ( Char != (CImagePacker *)10 )
                {
                  goto LABEL_14;
                }
              }
            }
            v6 = (unsigned int)v10;
          }
          GFxTextHighlighterRangeIterator::operator++(a1: 0);
          GFxTextHighlighterRangeIterator::IsFinished(this: &v14);
        }
        while ( v12 == 0 );
        v4 = v17;
      }
      v5 = i;
      baseIdx += *((_DWORD *)v4->pObject + 2 * i + 1);
    }
  }
  return binclNewLines;
}

//------------------------------------------------------------------------------
// Address: 0x10137E30
// Name: public: bool GFxStaticTextSnapshotData::IsSelected(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStaticTextSnapshotData::IsSelected(_DWORD *this, GPtr<GFxAmpViewStats> *result, unsigned int end)
{
  unsigned int v4; // esi
  int v5; // edi
  GFxTextHighlighter *v6; // ecx
  void *v7; // esi
  void *v9; // esi
  int v10; // [esp+Ch] [ebp-4h] BYREF

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v10);
  v4 = 0;
  v5 = 0;
  if ( *(this + 1) == 0 )
  {
LABEL_10:
    v7 = (void *)(v10 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v10 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
    return 0;
  }
  while ( 1 )
  {
    v6 = *(GFxTextHighlighter **)(*(_DWORD *)(*this + 8 * v5) + 372);
    if ( v6 != nullptr )
      break;
LABEL_9:
    if ( (unsigned int)++v5 >= *(this + 1) )
      goto LABEL_10;
  }
  if ( v4 <= (unsigned int)result )
  {
    if ( (unsigned int)result < v4 + *(_DWORD *)(*this + 8 * v5 + 4) )
      goto LABEL_7;
    if ( v4 < (unsigned int)result )
      goto LABEL_8;
  }
  if ( v4 >= end )
  {
LABEL_8:
    v4 += *(_DWORD *)(*this + 8 * v5 + 4);
    goto LABEL_9;
  }
LABEL_7:
  if ( !GFxTextHighlighter::IsAnyCharSelected(this: v6, selectStart: (unsigned int)result - v4, a3: end - v4) )
    goto LABEL_8;
  v9 = (void *)(v10 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v10 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10137F00
// Name: public: void GFxStaticTextSnapshotData::SetSelectColor(class GColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextSnapshotData::SetSelectColor(GPtr<GFxAmpViewStats> *this, GFxAmpViewStats *color)
{
  unsigned int v3; // edi
  GFxTextHighlighter *v4; // ecx

  v3 = 0;
  for ( *(this + 4) = *(GPtr<GFxAmpViewStats> *)color; v3 < *((_DWORD *)this + 1); ++v3 )
  {
    v4 = *(GFxTextHighlighter **)(*((_DWORD *)this->pObject + 2 * v3) + 372);
    if ( v4 != nullptr )
      GFxTextHighlighter::SetSelectColor(this: v4, a2: (const struct GColor *)this + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138070
// Name: public: virtual void GFxStaticTextCharacter::Display(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *const *__thiscall GFxStaticTextCharacter::Display(GPtr<GFxAmpMemItem> *this, GFxAmpMemItem *context)
{
  float *RefCount; // eax
  double v4; // st7
  int v5; // esi
  float *v6; // ecx
  IMaterialVar *const *result; // eax
  int v8; // esi
  IClientTools *v9; // ecx
  IClientTools_vtbl *v10; // eax
  IClientTools *v11; // ecx
  int v12; // esi
  float v13; // [esp+14h] [ebp-7Ch] BYREF
  float v14; // [esp+18h] [ebp-78h]
  float v15; // [esp+1Ch] [ebp-74h]
  float v16; // [esp+20h] [ebp-70h]
  int v17; // [esp+24h] [ebp-6Ch] BYREF
  int v18; // [esp+28h] [ebp-68h]
  int v19; // [esp+2Ch] [ebp-64h]
  int v20; // [esp+30h] [ebp-60h]
  int v21; // [esp+34h] [ebp-5Ch]
  int v22; // [esp+38h] [ebp-58h]
  int v23; // [esp+3Ch] [ebp-54h]
  int v24; // [esp+40h] [ebp-50h]
  int v25; // [esp+44h] [ebp-4Ch]
  char v26; // [esp+48h] [ebp-48h]
  int v27; // [esp+4Ch] [ebp-44h]
  int v28; // [esp+50h] [ebp-40h]
  GRenderer::Cxform v29; // [esp+54h] [ebp-3Ch] BYREF
  GMatrix2D v30; // [esp+74h] [ebp-1Ch] BYREF

  v27 = *((_DWORD *)this + 30);
  RefCount = (float *)context->RefCount;
  v30.M_[0][0] = *RefCount;
  v30.M_[0][1] = RefCount[1];
  v4 = RefCount[2];
  v28 = (int)context;
  v30.M_[0][2] = v4;
  v30.M_[1][0] = RefCount[3];
  v30.M_[1][1] = RefCount[4];
  v30.M_[1][2] = RefCount[5];
  GMatrix2D::Prepend(this: &v30, a2: (const struct GMatrix2D *)(this + 17));
  v29 = *(GRenderer::Cxform *)&context->dtr_GRefCountImplCore;
  GRenderer::Cxform::Concatenate(this: &v29, a2: (const struct GRenderer::Cxform *)(this + 9));
  v5 = v27;
  if ( context->Name.HeapTypeBits != 0
    || (v13 = 0.0,
        v14 = 0.0,
        v15 = 0.0,
        v16 = 0.0,
        GMatrix2D::EncloseTransform(this: (float *)&v30, a2: &v13, a3: (float *)(v27 + 16)),
        v6 = (float *)((int (__thiscall *)(GPtr<GFxAmpMemItem> *))this->pObject[2].RefCount)(a1: this),
        v14 <= (double)v6[39])
    && v6[37] <= (double)v16
    && v6[36] <= (double)v15
    && v13 <= (double)v6[38]
    || (result = (IMaterialVar *const *)v28, (*(_DWORD *)(*(_DWORD *)(v28 + 72) + 20) & 0x100) != 0) )
  {
    v21 = 0;
    v26 = 0;
    v17 = 0;
    v18 = 0;
    v19 = 0x100000;
    v20 = 0;
    v22 = 0x100000;
    v23 = 0;
    v24 = 0;
    v25 = 0;
    GFxTextFieldParam::LoadFromTextFilter(this: (int)&v17, result: (const CResourcePreloadMaterial *)this + 84);
    if ( (*(_BYTE *)(v5 + 68) & 1) != 0 )
    {
      HIBYTE(v18) |= 3u;
      HIBYTE(v21) |= 3u;
    }
    GMatrix2D::Prepend(this: &v30, a2: (const struct GMatrix2D *)(v5 + 32));
    v8 = *((_DWORD *)this + 93);
    if ( v8 == 0 )
      goto LABEL_16;
    if ( *(_BYTE *)(v8 + 24) == 0 )
    {
      GFxTextHighlighter::DrawBackground(a1: v8, a2: v8 + 28, a3: this + 31, a4: this + 37, a5: 0, a6: 0.0, a7: 0.0);
      *(_BYTE *)(v8 + 24) = 1;
    }
    v9 = *((IClientTools **)this + 93);
    v10 = v9[9].__vftable;
    v11 = v9 + 7;
    if ( v10 != nullptr && (v10->DrawSprite != nullptr || v10->GetLocalPlayerEyePosition != nullptr) )
    {
      v12 = v28;
      GFxDrawingContext::Display(this: v11, context: v28);
    }
    else
    {
LABEL_16:
      v12 = v28;
    }
    *(_DWORD *)(v12 + 80) = this;
    result = GFxTextLineBuffer::Display(this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)(this + 31));
    *((_BYTE *)this + 376) &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101385E0
// Name: public: GFxStaticTextCharacter::GFxStaticTextCharacter(class GFxStaticTextCharacterDef __near *,class GFxMovieDefImpl __near *,class GFxASCharacter __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall GFxStaticTextCharacter::GFxStaticTextCharacter(
        GPtr<GFxAmpMemItem> *this,
        CMatRenderContextBase *pdef,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingDefImpl,
        __int64 pparent)
{
  CMatRenderContextBase *v4; // esi
  IMorphMgrRenderContext *m_pMorphRenderContext; // eax
  IMorphInternal_vtbl *v7; // esi
  _IMAGE_SECTION_HEADER::<unnamed_type_Misc> v8; // ebx
  CExpressionEvaluator *v9; // ecx
  _DWORD *j; // ebx
  bool v11; // zf
  IShaderAPI *v12; // eax
  IShaderAPI *v13; // esi
  char *v14; // ebx
  IShaderDevice *v15; // ecx
  unsigned int AddMorph; // eax
  int inserted; // eax
  int v18; // ebx
  double v19; // st7
  IShaderDevice *v20; // ecx
  IShaderDevice_vtbl *v21; // edx
  double v22; // st7
  int v23; // edx
  double v24; // st6
  double v25; // st7
  double v26; // st6
  double v27; // st6
  bool v28; // c0
  bool v29; // c3
  double v30; // st7
  double v31; // st7
  int v32; // edx
  CFunctor *FormatData; // eax
  int v34; // esi
  _WORD *v35; // esi
  IMorphInternal_vtbl *v36; // ecx
  unsigned int v37; // eax
  IMorphInternal_vtbl *v38; // edx
  int v39; // eax
  double v40; // st7
  struct GFxFontHandle *v41; // ecx
  _DWORD *v42; // eax
  unsigned int (__thiscall *GetMorphFormat)(IMorphInternal *); // ecx
  double v44; // st7
  double v45; // st7
  int v46; // eax
  int v47; // ecx
  int v48; // esi
  int v49; // edx
  int v50; // ecx
  int v51; // ebx
  struct GFxFontHandle *v52; // eax
  GFxFontManager *v53; // ecx
  IShaderDevice *v54; // ecx
  IShaderDevice *v55; // ecx
  IShaderDevice *v56; // eax
  struct GFxFontHandle *v57; // esi
  volatile LONG *v58; // ebx
  IShaderAPI *v59; // eax
  GFxLogBase<GFxLog> *v60; // ebx
  __int128 v61; // [esp+Ch] [ebp-C4h]
  CMatRenderContextBase *v62; // [esp+14h] [ebp-BCh]
  const CMaterialDict::MaterialLookup_t *v63; // [esp+14h] [ebp-BCh]
  Kind v64; // [esp+14h] [ebp-BCh]
  CMatRenderContextBase *v65; // [esp+14h] [ebp-BCh]
  __int128 v66; // [esp+18h] [ebp-B8h]
  IMaterial *const *v67; // [esp+1Ch] [ebp-B4h]
  void (__thiscall *gins)(IMatRenderContext *, bool); // [esp+20h] [ebp-B0h]
  int v69; // [esp+24h] [ebp-ACh] OVERLAPPED
  const ShaderStencilState_t *v70; // [esp+28h] [ebp-A8h]
  const int *v71; // [esp+28h] [ebp-A8h]
  const int *v72; // [esp+2Ch] [ebp-A4h]
  const int *v73; // [esp+30h] [ebp-A0h]
  const int *n; // [esp+34h] [ebp-9Ch]
  int v75; // [esp+38h] [ebp-98h] BYREF
  _ENUM_SERVICE_STATUSA *fontData; // [esp+3Ch] [ebp-94h] BYREF
  int v77; // [esp+44h] [ebp-8Ch]
  float v78; // [esp+48h] [ebp-88h]
  _IMAGE_SECTION_HEADER::<unnamed_type_Misc> v79; // [esp+4Ch] [ebp-84h]
  _DWORD *v80; // [esp+50h] [ebp-80h]
  CMatRenderContextBase *v81; // [esp+54h] [ebp-7Ch]
  int v82; // [esp+58h] [ebp-78h]
  unsigned int glyphAccum; // [esp+5Ch] [ebp-74h]
  unsigned int i; // [esp+60h] [ebp-70h]
  float v85; // [esp+64h] [ebp-6Ch]
  IShaderDevice *v86; // [esp+68h] [ebp-68h]
  float v87; // [esp+6Ch] [ebp-64h]
  void (__thiscall *v88)(struct IMorphInternal *, const MorphVertexInfo_t *); // [esp+70h] [ebp-60h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> r; // [esp+74h] [ebp-5Ch] BYREF
  float v90; // [esp+80h] [ebp-50h]
  struct GFxFontHandle *v91; // [esp+84h] [ebp-4Ch]
  IMorphInternal_vtbl *v92; // [esp+88h] [ebp-48h]
  int baseLine; // [esp+8Ch] [ebp-44h]
  int lineHeight; // [esp+90h] [ebp-40h]
  unsigned int glyphsCount; // [esp+94h] [ebp-3Ch]
  unsigned int v96; // [esp+98h] [ebp-38h]
  CMaterialDict::MaterialLookup_t m; // [esp+9Ch] [ebp-34h] BYREF
  ITexture *v98; // [esp+A4h] [ebp-2Ch]
  ITexture *v99; // [esp+A8h] [ebp-28h]
  MaterialHeightClipMode_t v100; // [esp+ACh] [ebp-24h]
  float v101; // [esp+B0h] [ebp-20h]
  IMaterialInternal *v102; // [esp+B4h] [ebp-1Ch] BYREF
  ITexture *v103; // [esp+B8h] [ebp-18h]
  ITexture *v104; // [esp+BCh] [ebp-14h]
  ITexture *v105; // [esp+C0h] [ebp-10h]
  MaterialHeightClipMode_t m_HeightClipMode; // [esp+C4h] [ebp-Ch]
  float m_HeightClipZ; // [esp+C8h] [ebp-8h]

  v4 = pdef;
  v79.PhysicalAddress = pbindingDefImpl.PhysicalAddress;
  *(_QWORD *)&v61 = pparent;
  v81 = pdef;
  GFxGenericCharacter::GFxGenericCharacter(
    (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this,
    pdef,
    pparent: v61,
    id: v67,
    a5: (void *const *)gins);
  this->pObject = (GFxAmpMemItem *)&GFxStaticTextCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxStaticTextCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  GFxTextLineBuffer::GFxTextLineBuffer(
    this: (CMatCallQueue *)(this + 31),
    a2: v62,
    a3: *(__int128 *)(&v69 - 3),
    a4: v70);
  *((_DWORD *)this + 84) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 85) = 1;
  *((_DWORD *)this + 84) = &GRefCountBaseNTS<GASGlobalContext,323>::`vftable';
  *((_DWORD *)this + 86) = -2146435072;
  *((_DWORD *)this + 87) = -15712192;
  *(GPtr<GFxAmpMemItem> *)((char *)this + 354) = (GPtr<GFxAmpMemItem>)5243330;
  *(GPtr<GFxAmpMemItem> *)((char *)this + 358) = (GPtr<GFxAmpMemItem>)3735609;
  *((_DWORD *)this + 91) = 0;
  *((_DWORD *)this + 92) = 0;
  *((_BYTE *)this + 352) = 0;
  *((_DWORD *)this + 93) = 0;
  *((_BYTE *)this + 376) = 0;
  v102 = (IMaterialInternal *)pdef->m_pCurrentFrameBufferCopyTexture[0];
  v103 = pdef->m_pCurrentFrameBufferCopyTexture[1];
  v104 = pdef->m_pCurrentFrameBufferCopyTexture[2];
  v105 = pdef->m_pCurrentFrameBufferCopyTexture[3];
  m_HeightClipMode = pdef->m_HeightClipMode;
  m_HeightClipZ = pdef->m_HeightClipZ;
  m.m_pMaterial = v102;
  *(float *)&m.m_Name.m_Id = *(float *)&v103;
  v98 = v104;
  v99 = v105;
  v100 = m_HeightClipMode;
  v101 = m_HeightClipZ;
  GMatrix2D::SetInverse(a1: (float *)&v102, &m, a3: v63);
  *(float *)&r.m_pMemory = 0.0;
  *(float *)&r.m_nAllocationCount = 0.0;
  *(float *)&r.m_nGrowSize = 0.0;
  v90 = 0.0;
  GMatrix2D::EncloseTransform(this: (float *)&v102, a2: (float *)&r, a3: (float *)&pdef->m_pCurrentProxyData);
  glyphAccum = 0;
  if ( *(float *)&r.m_pMemory >= 0.0 )
    *(float *)&r.m_pMemory = 0.0;
  if ( *(float *)&r.m_nAllocationCount >= 0.0 )
    *(float *)&r.m_nAllocationCount = 0.0;
  if ( *(float *)&r.m_nGrowSize <= 0.0 )
    *(float *)&r.m_nGrowSize = 0.0;
  if ( v90 <= 0.0 )
    v90 = 0.0;
  m_pMorphRenderContext = pdef->m_pMorphRenderContext;
  i = 0;
  n = (const int *)m_pMorphRenderContext;
  if ( m_pMorphRenderContext != nullptr )
  {
    while ( 1 )
    {
      v8.PhysicalAddress = v79.PhysicalAddress;
      v9 = (CExpressionEvaluator *)(*(_DWORD *)(v79.PhysicalAddress + 28) + 24);
      v92 = v81->m_pBoundMorph[i].__vftable;
      v7 = v92;
      GFxResourceBinding::GetResourceData(
        this: v9,
        h: (ExprNode **)&fontData,
        ha: (const GenericThreadLocals::CThreadLocal<int> *)&v92->Init,
        a4: v64,
        a5: (ExprNode *)v66,
        a6: (ExprNode *)DWORD1(v66));
      v86 = (IShaderDevice *)fontData;
      if ( fontData == nullptr )
        break;
      if ( (v81->m_RenderTargetStack.m_Memory.m_nAllocationCount & 2) == 0 )
      {
        for ( j = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8.PhysicalAddress + 28) + 12) + 32) + 156);
              j != nullptr;
              j = (_DWORD *)j[6] )
        {
          v11 = j[1] == 0;
          *(float *)&baseLine = 0.0;
          if ( !v11 )
          {
            glyphsCount = 0;
            do
            {
              if ( *(bool (__thiscall **)(IMorphInternal *, IMorphMgrRenderContext *))(glyphsCount + *j + 8) == v7->Bind )
              {
                v12 = (IShaderAPI *)(*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(v79.PhysicalAddress + 12) + 12))(
                                      a1: v79.PhysicalAddress + 12,
                                      a2: 4);
                v13 = v12;
                if ( v12 != nullptr )
                {
                  GRefCountImpl::Release(this: v12);
                  GFxLogBase<GFxLog>::LogWarning(
                    this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)LOWORD(v92[1].Init),
                    pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v13[3],
                    this_4: (int)"Warning: static text uses imported font! FontId = %d, import name = %s\n",
                    this_8: LOWORD(v92[1].Init));
                }
                v7 = v92;
              }
              glyphsCount += 12;
              ++baseLine;
            }
            while ( (unsigned int)baseLine < j[1] );
          }
        }
      }
      v75 = 326;
      v14 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 36, a4: &v75);
      if ( v14 != nullptr )
      {
        *(_DWORD *)v14 = 1;
        *((_DWORD *)v14 + 1) = 0;
        *((_DWORD *)v14 + 2) = 0;
        GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v14 + 12));
        v15 = v86;
        *((float *)v14 + 4) = 1.0;
        GRefCountImpl::AddRef(this: v15);
        *((_DWORD *)v14 + 7) = v86;
        *((_DWORD *)v14 + 8) = 0;
        *((float *)v14 + 6) = 0.0;
        *((float *)v14 + 5) = 0.0;
        v91 = (struct GFxFontHandle *)v14;
      }
      else
      {
        v91 = nullptr;
      }
      AddMorph = (unsigned int)v7->AddMorph;
      glyphsCount = AddMorph;
      if ( AddMorph > 0xFF || ((int)v86[3].GetCurrentAdapter & 0x2000) != 0 )
        inserted = GFxTextLineBuffer::InsertNewLine(a1: this + 31, a2: i, a3: AddMorph, a4: 2, a5: 1);
      else
        inserted = GFxTextLineBuffer::InsertNewLine(a1: this + 31, a2: i, a3: AddMorph, a4: 2, a5: 0);
      v18 = inserted;
      if ( *(int *)inserted >= 0 )
        *(_DWORD *)(inserted + 8) = glyphAccum;
      else
        *(_DWORD *)(inserted + 8) ^= (glyphAccum ^ *(_DWORD *)(inserted + 8)) & 0xFFFFFF;
      v19 = *(float *)&v7[1].Lock;
      glyphAccum += glyphsCount;
      v87 = v19;
      v20 = v86;
      v21 = v86[3].__vftable;
      v88 = v7[1].AddMorph;
      if ( ((int)v21->GetCurrentAdapter & 0x2000) != 0 )
      {
        v22 = *(float *)&v7[1].Unlock * 0.0009765625;
        v23 = *(_DWORD *)inserted >> 31;
        *(float *)&v88 = *(float *)&v88 - *(float *)&v7[1].Unlock;
        v87 = v87 - *(float *)&r.m_pMemory;
        *(float *)&v88 = *(float *)&v88 - *(float *)&r.m_nAllocationCount;
        baseLine = (int)v7[1].Unlock;
        v24 = *(float *)&baseLine;
        lineHeight = (int)*(float *)&baseLine;
        if ( (v23 & 1) != 0 )
          *(_WORD *)(inserted + 26) = (int)v24;
        else
          *(_WORD *)(inserted + 38) = (int)v24;
        *(float *)&lineHeight = v22 * *(float *)&v20[3].GetBackBufferDimensions + *(float *)&v7[1].Unlock;
        v25 = 0.0;
      }
      else
      {
        v87 = v87 - *(float *)&r.m_pMemory;
        *(float *)&v88 = *(float *)&v88 - *(float *)&r.m_nAllocationCount;
        v25 = 0.0;
        *(float *)&lineHeight = 0.0;
      }
      v26 = *(float *)&v88;
      if ( *(float *)&v88 <= v25 )
        v27 = v26 - 0.5;
      else
        v27 = v26 + 0.5;
      v28 = v87 < v25;
      v29 = v87 == v25;
      v30 = v87;
      if ( v28 || v29 )
        v31 = v30 - 0.5;
      else
        v31 = v30 + 0.5;
      *(_DWORD *)(inserted + 12) = (int)v31;
      *(_DWORD *)(inserted + 16) = (int)v27;
      v32 = *(_DWORD *)inserted >> 31;
      *(_DWORD *)(inserted + 20) = 0;
      if ( (v32 & 1) == 0 )
        *(_DWORD *)(inserted + 24) = 0;
      if ( *(int *)inserted >= 0 )
        v82 = inserted + 42;
      else
        v82 = inserted + 30;
      FormatData = GFxTextLineBuffer::Line::GetFormatData(
                     this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)inserted,
                     a2: v65,
                     a3: v66,
                     a4: v71,
                     a5: v72,
                     a6: v73,
                     a7: n);
      v34 = 0;
      v71 = nullptr;
      *(float *)&baseLine = 0.0;
      v96 = 0;
      if ( glyphsCount != 0 )
      {
        v80 = &FormatData->__vftable;
        v35 = (_WORD *)(v82 + 6);
        do
        {
          v36 = v92;
          v37 = v96;
          *(_DWORD *)(v35 - 1) = 4096;
          v38 = v92;
          *(v35 - 3) = *((_WORD *)v36->Lock + 4 * v37);
          v39 = (int)*((float *)v38->Lock + 2 * v37 + 1);
          if ( v39 < 0 )
          {
            *(v35 - 2) = abs32(v39);
            *v35 = 64;
          }
          else
          {
            *(v35 - 2) = v39;
            *v35 = 0;
          }
          v40 = *(float *)&v92[1].Unlock;
          baseLine += (int)*((float *)v92->Lock + 2 * v96 + 1);
          v85 = v40 / 20.0;
          GFxTextLineBuffer::GlyphEntry::SetFontSize(this: v35 - 3, result: (const CIndexBufferBase *)LODWORD(v85));
          if ( v96 == 0 )
          {
            v41 = v91;
            *v35 |= 0x4000u;
            *v35 |= 0x2000u;
            v42 = v80;
            *v80 = v41;
            ++*(_DWORD *)v41;
            GetMorphFormat = v92->GetMorphFormat;
            *v35 |= 0x4000u;
            *v35 |= 0x1000u;
            v42[1] = GetMorphFormat;
            v80 = v42 + 2;
          }
          ++v96;
          if ( v82 != 0 && (unsigned int)v71 < glyphsCount )
          {
            v71 = (const int *)((char *)v71 + 1);
            v35 += 4;
          }
        }
        while ( v96 < glyphsCount );
        v34 = baseLine;
      }
      if ( ((int)v86[3].GetCurrentAdapter & 0x2000) != 0 )
      {
        v44 = *(float *)&lineHeight;
        if ( *(float *)&lineHeight <= 0.0 )
          v45 = v44 - 0.5;
        else
          v45 = v44 + 0.5;
        v46 = (int)v45;
        v47 = v34 < 0 ? 0 : v34;
        if ( *(int *)v18 >= 0 )
        {
          *(_DWORD *)(v18 + 20) = v47;
          *(_DWORD *)(v18 + 24) = v46;
        }
        else
        {
          *(_WORD *)(v18 + 20) = v47;
          *(_WORD *)(v18 + 22) = v46;
        }
        if ( *(int *)v18 >= 0 )
          *(_DWORD *)(v18 + 32) = glyphsCount;
        else
          *(_BYTE *)(v18 + 11) = glyphsCount;
        v48 = *(_DWORD *)(v18 + 16);
        if ( *(int *)v18 >= 0 )
          v49 = *(_DWORD *)(v18 + 24);
        else
          v49 = *(unsigned __int16 *)(v18 + 22);
        v50 = *(_DWORD *)(v18 + 12);
        if ( *(int *)v18 >= 0 )
          v51 = *(_DWORD *)(v18 + 20);
        else
          v51 = *(unsigned __int16 *)(v18 + 20);
        LODWORD(v85) = v48 + v49;
        *(float *)&v77 = (float)(v50 + v51);
        v78 = (float)(v48 + v49);
        if ( *(float *)&v77 <= (double)*(float *)&r.m_pMemory )
          r.m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)v77;
        if ( v78 <= (double)*(float *)&r.m_nAllocationCount )
          *(float *)&r.m_nAllocationCount = v78;
        if ( *(float *)&r.m_nGrowSize <= (double)*(float *)&v77 )
          r.m_nGrowSize = v77;
        if ( v90 <= (double)v78 )
          v90 = v78;
      }
      v52 = v91;
      if ( v91 != nullptr )
      {
        v11 = (*(_DWORD *)v91)-- == 1;
        if ( v11 )
        {
          v53 = *((GFxFontManager **)v52 + 1);
          if ( v53 != nullptr )
          {
            GFxFontManager::RemoveFontHandle(this: v53, a2: v52);
            v52 = v91;
          }
          v54 = *((IShaderDevice **)v52 + 7);
          if ( v54 != nullptr )
          {
            GFxResource::Release(this: v54);
            v52 = v91;
          }
          *((_DWORD *)v52 + 7) = 0;
          v55 = *((IShaderDevice **)v52 + 8);
          if ( v55 != nullptr )
          {
            GFxResource::Release(this: v55);
            v52 = v91;
          }
          v56 = *((IShaderDevice **)v52 + 7);
          if ( v56 != nullptr )
            GFxResource::Release(this: v56);
          v57 = v91;
          v58 = (volatile LONG *)(*((_DWORD *)v91 + 3) & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(Addend: v58 + 1, Value: -1) == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v58);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v57);
        }
      }
      if ( fontData != nullptr )
        GFxResource::Release(this: (IShaderDevice *)fontData);
      if ( ++i >= (unsigned int)n )
      {
        v4 = v81;
        goto LABEL_101;
      }
    }
    v59 = (IShaderAPI *)(*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(v8.PhysicalAddress + 12) + 12))(
                          a1: v8.PhysicalAddress + 12,
                          a2: 4);
    v60 = (GFxLogBase<GFxLog> *)v59;
    if ( v59 != nullptr )
    {
      GRefCountImpl::Release(this: v59);
      GFxLogBase<GFxLog>::LogError(
        this: v60 + 3,
        pfmt: "Error: text style with undefined font; FontId = %d\n",
        LOWORD(v7[1].Init));
    }
    if ( fontData != nullptr )
      GFxResource::Release(this: (IShaderDevice *)fontData);
  }
  else
  {
LABEL_101:
    *(CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)(this + 37) = r;
    *((float *)this + 40) = v90;
    *((_BYTE *)this + 240) |= 4u;
    *((_DWORD *)this + 86) = -2146435072;
    *((_DWORD *)this + 87) = -15712192;
    *(GPtr<GFxAmpMemItem> *)((char *)this + 354) = (GPtr<GFxAmpMemItem>)5243330;
    *(GPtr<GFxAmpMemItem> *)((char *)this + 358) = (GPtr<GFxAmpMemItem>)3735609;
    *((_DWORD *)this + 91) = 0;
    *((_DWORD *)this + 92) = 0;
    *((_BYTE *)this + 352) = 0;
    LOBYTE(v4->m_RenderTargetStack.m_Memory.m_nAllocationCount) |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138E00
// Name: public: virtual void GFxStaticTextCharacter::AdvanceFrame(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextCharacter::AdvanceFrame(_BYTE *this, const GPtr<GFxAmpMemItem> *result, int framePos)
{
  if ( (_BYTE)result != 0 )
    *(this + 376) |= 2u;
  else
    *(this + 376) &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10138E30
// Name: public: virtual void GFxStaticTextCharacter::SetFilters(struct GFxTextFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextCharacter::SetFilters(GPtr<GFxAmpMemItem> *this, GFxAmpMemItem *f)
{
  GFxTextFilter::operator=(this: (CDummyTexture *)this + 84);
}

//------------------------------------------------------------------------------
// Address: 0x10138E40
// Name: public: virtual void GFxStaticTextCharacter::SetFilters(class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy>)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStaticTextCharacter::SetFilters(void *this, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // esi
  int v6; // edi
  IShaderAPI v8; // [esp+8h] [ebp-24h] BYREF
  int v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+10h] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-18h]
  char v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ah] [ebp-12h]
  int v14; // [esp+1Eh] [ebp-Eh]
  int v15; // [esp+24h] [ebp-8h]
  int v16; // [esp+28h] [ebp-4h]

  v4 = 0;
  v9 = 1;
  v8.__vftable = (IShaderAPI_vtbl *)&GRefCountBaseNTS<GASGlobalContext,323>::`vftable';
  v10 = -2146435072;
  v11 = -15712192;
  v13 = 5243330;
  v14 = 3735609;
  v15 = 0;
  v16 = 0;
  v12 = 0;
  if ( a3 != 0 )
  {
    v6 = 0;
    do
    {
      GFxTextFilter::LoadFilterDesc(this: (GFxTextFilter *)&v8, a2: (const struct GFxFilterDesc *)(v6 + a2));
      ++v4;
      v6 += 156;
    }
    while ( v4 < a3 );
  }
  (*(void (__thiscall **)(void *, IShaderAPI *))(*(_DWORD *)this + 196))(a1: this, a2: &v8);
  GRefCountImplCore::~GRefCountImplCore(this: &v8);
  return ((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10138F40
// Name: public: void GFxStaticTextRecord::Read(class GFxStream __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextRecord::Read(
        CStudioHdr *this,
        GFxStream *a2,
        const studiohdr_t **glyphCount,
        unsigned int glyphBits,
        const IShaderDeviceMgr *advanceBits)
{
  CStudioHdr *v5; // esi
  int v6; // edi
  const studiohdr_t *m_pStudioHdr; // esi
  int v8; // ebx
  const studiohdr_t *v9; // esi

  v5 = this;
  GArrayData<GFxStaticTextRecord::GlyphEntry,GAllocatorLH<GFxStaticTextRecord::GlyphEntry,2>,GArrayDefaultPolicy>::Resize(
    this,
    a2: glyphCount);
  v6 = 0;
  if ( (int)glyphCount > 0 )
  {
    while ( 1 )
    {
      m_pStudioHdr = v5->m_pStudioHdr;
      v8 = 8 * v6;
      *(&m_pStudioHdr->id + 2 * v6) = GFxStream::ReadUInt(this: a2, a2: glyphBits);
      v9 = this->m_pStudioHdr;
      ++v6;
      *(float *)((char *)&v9->version + v8) = (float)(int)GFxStream::ReadSInt(result: advanceBits);
      if ( v6 >= (int)glyphCount )
        break;
      v5 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138FB0
// Name: public: class GFxStaticTextRecord __near * GFxStaticTextRecordList::AddRecord(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextRecordList::AddRecord(
        GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *this)
{
  float *v2; // ebx
  unsigned int v3; // edi
  GString *Data; // ecx
  unsigned int *v5; // edi
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 258;
  v2 = (float *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v6);
  if ( v2 != nullptr )
  {
    *v2 = 0.0;
    v2[1] = 0.0;
    v2[2] = 0.0;
    v2[3] = 0.0;
    v2[4] = 0.0;
    v2[7] = 0.0;
    v2[6] = 0.0;
    *((_WORD *)v2 + 18) = 0;
    v2[8] = 1.0;
    v3 = this->Size + 1;
    if ( v3 >= this->Size )
    {
      if ( v3 >= this->Policy.Capacity )
        GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
          this: (void **)&this->Data,
          result: this,
          newCapacity: v3 + (v3 >> 2));
    }
    else if ( v3 < this->Policy.Capacity >> 1 )
    {
      GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&this->Data,
        result: this,
        newCapacity: this->Size + 1);
    }
    Data = this->Data;
    this->Size = v3;
    v5 = (unsigned int *)&Data[v3 - 1];
    if ( v5 != nullptr )
      *v5 = (unsigned int)v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139050
// Name: public: void GFxStaticTextCharacterDef::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextCharacterDef::Read(float *this, char *p, int a3)
{
  GFxStream *v3; // esi
  float *v4; // ebx
  int v5; // eax
  _LUID_AND_ATTRIBUTES *v6; // eax
  int v7; // edx
  int v8; // ecx
  _LUID_AND_ATTRIBUTES *v9; // eax
  unsigned __int8 v10; // cl
  int v11; // ecx
  _LUID_AND_ATTRIBUTES *v12; // eax
  unsigned __int8 v13; // cl
  const studiohdr_t **v14; // ebx
  int v15; // eax
  _LUID_AND_ATTRIBUTES *v16; // eax
  unsigned int v17; // ebx
  IShaderDevice *v18; // ecx
  int v19; // edx
  _LUID_AND_ATTRIBUTES *v20; // eax
  __int16 v21; // cx
  int v22; // eax
  _LUID_AND_ATTRIBUTES *v23; // eax
  __int16 v24; // cx
  int v25; // eax
  _LUID_AND_ATTRIBUTES *v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // edi
  bool v30; // zf
  IShaderDevice *v31; // ecx
  _TRIVERTEX *v32; // eax
  double v33; // st7
  const IShaderDeviceMgr *v34; // ecx
  double CumulativeAdvance; // st7
  unsigned int v36; // [esp+18h] [ebp-50h]
  _cpinfo *v37; // [esp+20h] [ebp-48h]
  _TRIVERTEX *hres; // [esp+2Ch] [ebp-3Ch] BYREF
  IShaderDevice *v39; // [esp+30h] [ebp-38h]
  float v40; // [esp+34h] [ebp-34h]
  float v41; // [esp+38h] [ebp-30h]
  _TRIVERTEX *v42; // [esp+3Ch] [ebp-2Ch]
  IShaderDevice *v43; // [esp+40h] [ebp-28h]
  int GlyphBits; // [esp+44h] [ebp-24h]
  int AdvanceBits; // [esp+48h] [ebp-20h]
  int v46; // [esp+4Ch] [ebp-1Ch]
  unsigned int fontId; // [esp+50h] [ebp-18h]
  struct GColor v48; // [esp+54h] [ebp-14h] BYREF
  float textHeight; // [esp+58h] [ebp-10h]
  float *v50; // [esp+5Ch] [ebp-Ch]
  bool hasYOffset; // [esp+63h] [ebp-5h]
  bool hasXOffset; // [esp+64h] [ebp-4h]
  bool hasColor; // [esp+65h] [ebp-3h]
  bool hasFont; // [esp+66h] [ebp-2h]
  bool lastRecordWasStyleChange; // [esp+67h] [ebp-1h]

  v3 = *((GFxStream **)p + 201);
  v50 = this;
  if ( v3 == nullptr )
    v3 = (GFxStream *)(p + 40);
  v4 = this + 4;
  GFxStream::ReadRect(this: v3, a2: (int)(this + 4));
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v3,
    a2: (int)"  TextRect = { l: %f, t: %f, r: %f, b: %f }\n",
    *v4,
    v50[5],
    v50[6],
    v50[7]);
  GFxStream::ReadMatrix(this: v3, a2: (struct GMatrix2D *)(v50 + 8));
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  mat:\n");
  GFxStream::LogParseClass(result: (_MAT2 *)v50 + 2);
  v5 = (char *)v3[12] - (char *)v3[11];
  *((_BYTE *)v3 + 21) = 0;
  if ( v5 < 1 )
    GFxStream::PopulateBuffer1(result: v37);
  v6 = (_LUID_AND_ATTRIBUTES *)v3[11];
  v7 = *((unsigned __int8 *)&(*v3[15])[0].Luid.LowPart + (_DWORD)v6);
  v6 = (_LUID_AND_ATTRIBUTES *)((char *)v6 + 1);
  v8 = (char *)v3[12] - (char *)v6;
  v3[11] = (GFxStream)v6;
  GlyphBits = v7;
  *((_BYTE *)v3 + 21) = 0;
  if ( v8 < 1 )
    GFxStream::PopulateBuffer1(result: v37);
  v9 = (_LUID_AND_ATTRIBUTES *)v3[11];
  v10 = *((_BYTE *)&(*v3[15])[0].Luid.LowPart + (_DWORD)v9);
  v3[11] = (GFxStream)((char *)&v9->Luid.LowPart + 1);
  AdvanceBits = v10;
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"begin text records\n");
  lastRecordWasStyleChange = false;
  textHeight = 0.0;
  fontId = 0;
  v41 = 0.0;
  v42 = nullptr;
  v40 = 0.0;
  v43 = nullptr;
  while ( 1 )
  {
    v11 = (char *)v3[12] - (char *)v3[11];
    *((_BYTE *)v3 + 21) = 0;
    if ( v11 < 1 )
      GFxStream::PopulateBuffer1(result: v37);
    v12 = (_LUID_AND_ATTRIBUTES *)v3[11];
    v13 = *((_BYTE *)&(*v3[15])[0].Luid.LowPart + (_DWORD)v12);
    v14 = (const studiohdr_t **)v13;
    v3[11] = (GFxStream)((char *)&v12->Luid.LowPart + 1);
    if ( v13 == 0 )
      break;
    if ( lastRecordWasStyleChange )
    {
      lastRecordWasStyleChange = false;
      GFxStaticTextRecordList::AddRecord(this: (GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)(v50 + 14));
      v29 = v28;
      if ( v28 != 0 )
      {
        v30 = v42 == nullptr;
        *(float *)(v28 + 24) = v40;
        *(float *)(v28 + 28) = v41;
        if ( v30 && v43 != nullptr )
          GRefCountImpl::AddRef(this: v43);
        if ( *(_DWORD *)(v29 + 12) == 0 )
        {
          v31 = *(IShaderDevice **)(v29 + 16);
          if ( v31 != nullptr )
            GFxResource::Release(this: v31);
        }
        v32 = v42;
        v33 = textHeight;
        *(_DWORD *)(v29 + 16) = v43;
        v34 = (const IShaderDeviceMgr *)AdvanceBits;
        *(_DWORD *)(v29 + 12) = v32;
        *(float *)(v29 + 32) = v33;
        LOWORD(v32) = fontId;
        *(struct GColor *)(v29 + 20) = v48;
        v36 = GlyphBits;
        *(_WORD *)(v29 + 36) = (_WORD)v32;
        GFxStaticTextRecord::Read(this: (CStudioHdr *)v29, a2: v3, glyphCount: v14, glyphBits: v36, advanceBits: v34);
        CumulativeAdvance = GFxStaticTextRecord::GetCumulativeAdvance(this: (GFxStaticTextRecord *)v29);
        v40 = CumulativeAdvance + v40;
      }
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  GlyphRecords: count = %d\n", v14);
    }
    else
    {
      lastRecordWasStyleChange = true;
      hasFont = ((int)v13 >> 3) & 1;
      hasColor = ((int)v13 >> 2) & 1;
      hasYOffset = ((int)v13 >> 1) & 1;
      hasXOffset = v13 & 1;
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  text style change\n");
      if ( hasFont )
      {
        v15 = (char *)v3[12] - (char *)v3[11];
        *((_BYTE *)v3 + 21) = 0;
        if ( v15 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v16 = (_LUID_AND_ATTRIBUTES *)v3[11];
        v17 = *(unsigned __int16 *)((char *)&v16->Luid.LowPart + (_DWORD)v3[15]);
        v3[11] = (GFxStream)((char *)&v16->Luid.LowPart + 2);
        fontId = v17;
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  HasFont: font id = %d\n", v17);
        hres = nullptr;
        v39 = nullptr;
        GFxMovieDataDef::LoadTaskData::GetResourceHandle(
          this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p + 8),
          phandle: &hres,
          rid: v17);
        v18 = v39;
        if ( hres == nullptr && v39 != nullptr )
        {
          GRefCountImpl::AddRef(this: v39);
          v18 = v39;
        }
        if ( v42 == nullptr && v43 != nullptr )
        {
          GFxResource::Release(this: v43);
          v18 = v39;
        }
        v42 = hres;
        v43 = v18;
        if ( hres == nullptr && v18 != nullptr )
          GFxResource::Release(this: v18);
      }
      if ( hasColor )
      {
        if ( a3 == 11 )
          GFxStream::ReadRgb(this: v3, a2: &v48);
        else
          GFxStream::ReadRgba(this: v3, a2: &v48);
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  HasColor\n");
      }
      if ( hasXOffset )
      {
        v19 = (char *)v3[12] - (char *)v3[11];
        *((_BYTE *)v3 + 21) = 0;
        if ( v19 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v20 = (_LUID_AND_ATTRIBUTES *)v3[11];
        v21 = *(_WORD *)((char *)&v20->Luid.LowPart + (_DWORD)v3[15]);
        v46 = v21;
        v3[11] = (GFxStream)((char *)&v20->Luid.LowPart + 2);
        v40 = (float)v21;
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  XOffset = %g\n", v40);
      }
      if ( hasYOffset )
      {
        v22 = (char *)v3[12] - (char *)v3[11];
        *((_BYTE *)v3 + 21) = 0;
        if ( v22 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v23 = (_LUID_AND_ATTRIBUTES *)v3[11];
        v24 = *(_WORD *)((char *)&v23->Luid.LowPart + (_DWORD)v3[15]);
        v46 = v24;
        v3[11] = (GFxStream)((char *)&v23->Luid.LowPart + 2);
        v41 = (float)v24;
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  YOffset = %g\n", v41);
      }
      if ( hasFont )
      {
        v25 = (char *)v3[12] - (char *)v3[11];
        *((_BYTE *)v3 + 21) = 0;
        if ( v25 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v26 = (_LUID_AND_ATTRIBUTES *)v3[11];
        v27 = (unsigned __int16)(*((unsigned __int8 *)&v26->Luid.LowPart + (_DWORD)v3[15])
                               | (*((unsigned __int8 *)&v26->Luid.LowPart + (_DWORD)v3[15] + 1) << 8));
        v46 = v27;
        v3[11] = (GFxStream)((char *)&v26->Luid.LowPart + 2);
        textHeight = (float)v27;
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"  TextHeight = %g\n", textHeight);
      }
    }
  }
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v3, a2: (int)"end text records\n");
  if ( v42 == nullptr && v43 != nullptr )
    GFxResource::Release(this: v43);
}

//------------------------------------------------------------------------------
// Address: 0x10139480
// Name: public: virtual class GFxCharacter __near * GFxStaticTextCharacterDef::CreateCharacterInstance(class GFxASCharacter __near *,class GFxResourceId,class GFxMovieDefImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStaticTextCharacterDef::CreateCharacterInstance(
        CMatRenderContextBase *a1@<ecx>,
        __int64 parent,
        const char *pbindingImpl,
        int a4)
{
  GPtr<GFxAmpMemItem> *v5; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 322;
  v5 = (GPtr<GFxAmpMemItem> *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: parent,
                                a3: 380,
                                a4: &v6);
  if ( v5 != nullptr )
    GFxStaticTextCharacter::GFxStaticTextCharacter(
      this: v5,
      pdef: a1,
      pbindingDefImpl: (_IMAGE_SECTION_HEADER::<unnamed_type_Misc>)pbindingImpl,
      pparent: parent);
}

//------------------------------------------------------------------------------
// Address: 0x101394E0
// Name: public: void GFxStaticTextSnapshotData::Visit(class GFxStaticTextSnapshotData::GlyphVisitor __near *,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge GFxStaticTextSnapshotData::Visit(
        GPtr<GFxAmpViewStats> *this@<ecx>,
        int a2@<ebx>,
        CMatRenderContextBase *a3@<edi>,
        int *a4,
        unsigned int start,
        unsigned int end)
{
  unsigned int v6; // edx
  unsigned int v7; // eax
  int v8; // eax
  int v9; // ecx
  double v10; // st6
  _DWORD *v11; // eax
  double v12; // st5
  double v13; // st7
  int v14; // ecx
  int v15; // ecx
  int v16; // edx
  bool v17; // dl
  int v18; // eax
  int v19; // ebx
  const int *v20; // edi
  CFunctor *FormatData; // eax
  int v22; // edx
  int *v23; // eax
  GPtr<GFxAmpViewStats> *v24; // edi
  ILoaderProgress *v25; // ebx
  int v26; // ecx
  double v27; // st7
  int v28; // eax
  GPtr<GFxAmpViewStats> *v29; // ecx
  char IsSelected; // al
  float v31; // edx
  double v32; // st7
  unsigned int v33; // ecx
  struct GFxFontHandle *v34; // edi
  GFxFontManager *v35; // ecx
  IShaderDevice *v36; // ecx
  IShaderDevice *v37; // ecx
  IShaderDevice *v38; // ecx
  volatile LONG *v39; // ebx
  CMatRenderContextBase *v40; // [esp-8h] [ebp-108h]
  const VJobInstance *v41; // [esp-8h] [ebp-108h]
  _BYTE v42[20]; // [esp-4h] [ebp-104h] OVERLAPPED BYREF
  float v43; // [esp+10h] [ebp-F0h]
  int *v44; // [esp+14h] [ebp-ECh]
  int *v45; // [esp+18h] [ebp-E8h]
  CFunctor *v46; // [esp+1Ch] [ebp-E4h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v47; // [esp+20h] [ebp-E0h] BYREF
  char v48; // [esp+50h] [ebp-B0h]
  int v49; // [esp+54h] [ebp-ACh]
  int v50; // [esp+58h] [ebp-A8h]
  int v51; // [esp+5Ch] [ebp-A4h]
  struct GFxFontHandle *v52; // [esp+60h] [ebp-A0h]
  GRefCountNTSImpl *v53; // [esp+64h] [ebp-9Ch]
  int v54; // [esp+68h] [ebp-98h]
  unsigned int p; // [esp+6Ch] [ebp-94h]
  float charY; // [esp+70h] [ebp-90h]
  GMatrix2D *v57; // [esp+74h] [ebp-8Ch]
  _DWORD *v58; // [esp+78h] [ebp-88h]
  unsigned int v59; // [esp+80h] [ebp-80h]
  float glyphY; // [esp+8Ch] [ebp-74h]
  unsigned int n; // [esp+90h] [ebp-70h]
  ILoaderProgress *glyph; // [esp+94h] [ebp-6Ch]
  float charX; // [esp+98h] [ebp-68h]
  float v64; // [esp+9Ch] [ebp-64h] BYREF
  float v65; // [esp+A0h] [ebp-60h]
  float v66; // [esp+A4h] [ebp-5Ch]
  float v67; // [esp+A8h] [ebp-58h]
  GPtr<GFxAmpViewStats> *v68; // [esp+ACh] [ebp-54h]
  unsigned int i; // [esp+B0h] [ebp-50h]
  unsigned int runIdx; // [esp+B4h] [ebp-4Ch]
  float glyphX; // [esp+B8h] [ebp-48h]
  float v72; // [esp+BCh] [ebp-44h]
  float v73; // [esp+C0h] [ebp-40h]
  float xoff; // [esp+C4h] [ebp-3Ch]
  unsigned int glyphIdx; // [esp+C8h] [ebp-38h]
  struct GMatrix2D v76; // [esp+CCh] [ebp-34h] BYREF
  GMatrix2D v77; // [esp+E4h] [ebp-1Ch] BYREF

  v68 = this;
  if ( a4 != nullptr )
  {
    v6 = *((_DWORD *)this + 1);
    v7 = 0;
    *(float *)&glyphIdx = 0.0;
    i = 0;
    n = v6;
    if ( v6 != 0 )
    {
      *(_DWORD *)v42 = a2;
      v40 = a3;
      while ( 1 )
      {
        v8 = *((_DWORD *)this->pObject + 2 * v7);
        glyphX = 0.0;
        v9 = v8 + 68;
        v10 = *(float *)(v8 + 72);
        v11 = (_DWORD *)(v8 + 124);
        v57 = (GMatrix2D *)v9;
        v12 = *(float *)v9;
        v58 = v11;
        charX = v10 * 0.0 + v12 * 0.0 + *(float *)(v9 + 8);
        v13 = 0.0 * *(float *)(v9 + 12) + *(float *)(v9 + 16) * 0.0 + *(float *)(v9 + 20);
        v14 = 0;
        v59 = 0;
        charY = v13;
        while ( v11 != nullptr && (unsigned int)v14 < v11[1] && v14 >= 0 )
        {
          v15 = *(_DWORD *)(*v11 + 4 * v14);
          v16 = *(_DWORD *)v15;
          xoff = *(float *)(v15 + 12);
          v17 = v16 < 0;
          runIdx = 0;
          xoff = (float)SLODWORD(xoff);
          if ( glyphX > (double)xoff )
            glyphX = xoff;
          if ( v17 )
            v18 = *(char *)(v15 + 29);
          else
            v18 = *(__int16 *)(v15 + 40);
          LODWORD(xoff) = *(_DWORD *)(v15 + 16) + v18;
          glyphY = (float)SLODWORD(xoff);
          if ( v17 )
            v19 = *(unsigned __int8 *)(v15 + 28);
          else
            v19 = *(_DWORD *)(v15 + 4);
          v20 = (const int *)(v15 + 30);
          if ( !v17 )
            v20 = (const int *)(v15 + 42);
          FormatData = GFxTextLineBuffer::Line::GetFormatData(
                         this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v15,
                         a2: v40,
                         a3: *(__int128 *)v42,
                         a4: *(const int **)&v42[16],
                         a5: (const int *)LODWORD(v43),
                         a6: v44,
                         a7: v45);
          LODWORD(v47.m_Proxy.m_pfnProxied) = 0;
          memset((char *)&v47.m_Proxy.m_pfnProxied + 12, 0, 20);
          v48 = 0;
          v47.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
          v47.m_nUserID = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v52 = nullptr;
          v53 = nullptr;
          v54 = 0;
          p = 0;
          v45 = (int *)&v20[2 * v19];
          v47.m_iRefs = -1;
          *(_QWORD *)((char *)&v47.m_Proxy.m_pfnProxied + 4) = 0xFFFFFFFFLL;
          v44 = (int *)v20;
          v46 = FormatData;
          GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v41);
          if ( v52 != nullptr )
            xoff = *((float *)v52 + 7);
          else
            xoff = 0.0;
          v22 = v49;
          a4[12] = *(_DWORD *)(LODWORD(xoff) + 12);
          a4[15] = v22;
LABEL_24:
          v23 = v44;
          while ( v23 != nullptr && v23 < v45 )
          {
            v24 = (GPtr<GFxAmpViewStats> *)glyphIdx;
            v25 = (ILoaderProgress *)v23;
            glyph = (ILoaderProgress *)v23;
            if ( glyphIdx >= start && glyphIdx < end )
            {
              a4[13] = runIdx;
              v26 = v23[1] & 0xFFF;
              if ( (*((_BYTE *)v23 + 6) & 0x10) != 0 )
              {
                LODWORD(v73) = v23[1] & 0xFFF;
                v27 = (double)(unsigned int)v26 * 0.0625;
              }
              else
              {
                LODWORD(v73) = v23[1] & 0xFFF;
                v27 = (double)(unsigned int)v26;
              }
              *(float *)&glyphIdx = v27;
              a4[14] = glyphIdx;
              GMatrix2D::SetIdentity(this: (float *)&v77);
              *(float *)&glyphIdx = GMatrix2D::GetRotation(this: v57);
              v72 = cos(*(float *)&glyphIdx);
              v73 = v72;
              v72 = sin(*(float *)&glyphIdx);
              v76.M_[0][0] = v73;
              v76.M_[0][1] = -v72;
              v76.M_[0][2] = 0.0;
              v76.M_[1][2] = 0.0;
              v76.M_[1][0] = v72;
              v76.M_[1][1] = v73;
              GMatrix2D::Append(this: &v77, a2: &v76);
              v73 = charX + glyphX;
              v77.M_[0][2] = v73 + v77.M_[0][2];
              v73 = charY + glyphY;
              v77.M_[1][2] = v73 + v77.M_[1][2];
              *(GMatrix2D *)(a4 + 1) = v77;
              v28 = LOWORD(v25->__vftable);
              *(float *)&v42[8] = 0.0;
              *(float *)&v42[12] = 0.0;
              *(float *)&v42[16] = 0.0;
              v43 = 0.0;
              if ( (_WORD)v28 == 0xFFFF )
                v28 = -1;
              (*(void (__thiscall **)(_DWORD, int, _BYTE *))(**(_DWORD **)(LODWORD(xoff) + 12) + 48))(
                a1: *(_DWORD *)(LODWORD(xoff) + 12),
                a2: v28,
                a3: &v42[8]);
              v64 = 0.0;
              v65 = 0.0;
              v66 = 0.0;
              v67 = 0.0;
              GMatrix2D::EncloseTransform(this: (float *)&v77, a2: &v64, a3: (float *)&v42[8]);
              v29 = v68;
              *((float *)a4 + 7) = v64;
              *((float *)a4 + 8) = v65;
              *((float *)a4 + 9) = v66;
              *((float *)a4 + 10) = v67;
              IsSelected = GFxStaticTextSnapshotData::IsSelected(
                             this: v29,
                             result: v24,
                             end: (unsigned int)&v24->pObject + 1);
              v31 = *(float *)a4;
              *((_BYTE *)a4 + 64) = IsSelected;
              (*(void (__thiscall **)(int *))(LODWORD(v31) + 4))(a1: a4);
              ++runIdx;
              v23 = v44;
              v25 = glyph;
            }
            glyphIdx = (BYTE2(v25[1].__vftable) & 0x40) != 0 ? -HIWORD(v25->__vftable) : HIWORD(v25->__vftable);
            v32 = (double)(int)glyphIdx;
            glyphIdx = (unsigned int)&v24->pObject + 1;
            glyphX = v32 + glyphX;
            if ( v23 == nullptr )
              break;
            if ( v23 < v45 )
            {
              v33 = p;
              if ( p == 0 )
              {
                v33 = *((unsigned __int16 *)v23 + 2) >> 12;
                p = v33;
              }
              v44 = v23 + 2;
              if ( (v23[3] & 0xF000) != 0
                && v33 != 0
                && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v47) )
              {
                GFxTextHighlighterPosIterator::operator+=(this: &v47, p);
                p = 0;
              }
              GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: (const VJobInstance *)v40);
              goto LABEL_24;
            }
          }
          if ( v53 != nullptr )
            GRefCountNTSImpl::Release(this: v53);
          v34 = v52;
          if ( v52 != nullptr )
          {
            --*(_DWORD *)v52;
            if ( *(_DWORD *)v34 == 0 )
            {
              v35 = *((GFxFontManager **)v34 + 1);
              if ( v35 != nullptr )
                GFxFontManager::RemoveFontHandle(this: v35, a2: v34);
              v36 = *((IShaderDevice **)v34 + 7);
              if ( v36 != nullptr )
                GFxResource::Release(this: v36);
              *((_DWORD *)v34 + 7) = 0;
              v37 = *((IShaderDevice **)v34 + 8);
              if ( v37 != nullptr )
                GFxResource::Release(this: v37);
              v38 = *((IShaderDevice **)v34 + 7);
              if ( v38 != nullptr )
                GFxResource::Release(this: v38);
              v39 = (volatile LONG *)(*((_DWORD *)v34 + 3) & 0xFFFFFFFC);
              if ( InterlockedExchangeAdd(Addend: v39 + 1, Value: -1) == 1 )
                GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v39);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v34);
            }
          }
          v11 = v58;
          if ( v59 < v58[1] )
            ++v59;
          v14 = v59;
        }
        v7 = i + 1;
        i = v7;
        if ( v7 >= n )
          break;
        this = v68;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101399F0
// Name: public: int GFxStaticTextSnapshotData::HitTestTextNearPos(float,float,float)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxStaticTextSnapshotData::HitTestTextNearPos@<eax>(
        GPtr<GFxAmpViewStats> *this@<ecx>,
        CMatRenderContextBase *a2@<edi>,
        const GPtr<GFxAmpViewStats> *x,
        int y,
        float xoffInLine)
{
  unsigned int v5; // edi
  const GFxAmpViewStats *v7; // esi
  double v8; // st6
  int v9; // esi
  double v10; // st7
  double v11; // st6
  const int *v12; // ebx
  CFunctor *FormatData; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // edx
  int v17; // esi
  unsigned int v18; // esi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v19; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v20; // ebx
  CMatRenderContextBase *v22; // [esp-8h] [ebp-ACh]
  const VJobInstance *v23; // [esp-8h] [ebp-ACh]
  const VJobInstance *v24; // [esp-8h] [ebp-ACh]
  __int128 v25; // [esp-4h] [ebp-A8h] BYREF
  int v26; // [esp+Ch] [ebp-98h]
  const int *v27; // [esp+10h] [ebp-94h]
  const int *v28; // [esp+14h] [ebp-90h]
  const int *v29; // [esp+18h] [ebp-8Ch]
  unsigned int v30; // [esp+1Ch] [ebp-88h]
  CFunctor *v31; // [esp+20h] [ebp-84h]
  int v32; // [esp+28h] [ebp-7Ch]
  int v33; // [esp+2Ch] [ebp-78h]
  int v34; // [esp+30h] [ebp-74h]
  int v35; // [esp+34h] [ebp-70h]
  int v36; // [esp+38h] [ebp-6Ch]
  int v37; // [esp+3Ch] [ebp-68h]
  int v38; // [esp+40h] [ebp-64h]
  int v39; // [esp+44h] [ebp-60h]
  int v40; // [esp+48h] [ebp-5Ch]
  int v41; // [esp+4Ch] [ebp-58h]
  int v42; // [esp+50h] [ebp-54h]
  char v43; // [esp+54h] [ebp-50h]
  int v44; // [esp+58h] [ebp-4Ch]
  int v45; // [esp+5Ch] [ebp-48h]
  int v46; // [esp+60h] [ebp-44h]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v47; // [esp+64h] [ebp-40h]
  GRefCountNTSImpl *v48; // [esp+68h] [ebp-3Ch]
  int v49; // [esp+6Ch] [ebp-38h]
  int v50; // [esp+70h] [ebp-34h]
  int p[2]; // [esp+74h] [ebp-30h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v52; // [esp+7Ch] [ebp-28h] BYREF
  float v53; // [esp+88h] [ebp-1Ch] BYREF
  unsigned int v54; // [esp+8Ch] [ebp-18h]
  unsigned int baseIdx; // [esp+90h] [ebp-14h]
  unsigned int fixedY; // [esp+94h] [ebp-10h]
  unsigned int tempBaseIdx; // [esp+98h] [ebp-Ch]
  const GFxAmpViewStats *pclosestChar; // [esp+9Ch] [ebp-8h]
  float fixedX; // [esp+A0h] [ebp-4h]
  float xoffsetc; // [esp+ACh] [ebp+8h]
  float xoffsetd; // [esp+ACh] [ebp+8h]
  float xoffset; // [esp+ACh] [ebp+8h]
  float xoffsete; // [esp+ACh] [ebp+8h]
  int xoffseta; // [esp+ACh] [ebp+8h]
  int xoffsetb; // [esp+ACh] [ebp+8h]
  float yb; // [esp+B0h] [ebp+Ch]
  int ya; // [esp+B0h] [ebp+Ch]
  float xoffInLinea; // [esp+B4h] [ebp+10h]

  *(float *)&v52.nReferenceCount = 3.4028235e38;
  v22 = a2;
  fixedX = 0.0;
  v5 = 0;
  *(float *)&fixedY = 0.0;
  pclosestChar = nullptr;
  p[0] = (int)x;
  tempBaseIdx = 0;
  baseIdx = 0;
  p[1] = y;
  if ( *((_DWORD *)this + 1) == 0 )
    return -1;
  while ( 1 )
  {
    v7 = *((const GFxAmpViewStats **)this->pObject + 2 * v5);
    GMatrix2D::TransformByInverse(
      this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)v7 + 68),
      result: &v52,
      (float *)p,
      p_4: (int)v22);
    v8 = *(float *)&v52.nNextElement;
    if ( *((float *)v7 + 39) >= (double)*(float *)&v52.pString
      && *((float *)v7 + 37) <= (double)*(float *)&v52.pString
      && *((float *)v7 + 40) >= v8
      && *((float *)v7 + 38) <= v8 )
    {
      break;
    }
    ClosestPointOnRectangle(a1: &v53, a2: (char *)v7 + 148, a3: &v52);
    yb = v53 - *(float *)&v52.pString;
    xoffsetc = *(float *)&v54 - *(float *)&v52.nNextElement;
    xoffsetd = xoffsetc * xoffsetc + yb * yb;
    xoffset = sqrt(xoffsetd);
    if ( xoffInLine <= (double)xoffset || *(float *)&v52.nReferenceCount <= (double)xoffset )
    {
      v7 = pclosestChar;
    }
    else
    {
      *(float *)&v52.nReferenceCount = xoffset;
      pclosestChar = v7;
      fixedX = v53;
      baseIdx = tempBaseIdx;
      fixedY = v54;
    }
    tempBaseIdx += *((_DWORD *)this->pObject + 2 * v5++ + 1);
    if ( v5 >= *((_DWORD *)this + 1) )
      goto LABEL_13;
  }
  fixedX = *(float *)&v52.pString;
  pclosestChar = v7;
  baseIdx = tempBaseIdx;
  fixedY = v52.nNextElement;
LABEL_13:
  if ( v7 == nullptr )
    return -1;
  fixedX = fixedX - *((float *)v7 + 37);
  v53 = fixedX;
  *(float *)&v54 = *(float *)&fixedY - *((float *)v7 + 38);
  GFxTextLineBuffer::FindLineAtOffset(a1: (char *)v7 + 124, a2: (char *)&v25 + 8, a3: &v53);
  if ( DWORD2(v25) == 0 )
    return -1;
  if ( (unsigned int)v26 >= *(_DWORD *)(DWORD2(v25) + 4) )
    return -1;
  if ( v26 < 0 )
    return -1;
  v9 = *(_DWORD *)(*(_DWORD *)DWORD2(v25) + 4 * v26);
  xoffsete = (float)*(int *)(v9 + 12);
  v10 = fixedX;
  v11 = xoffsete;
  if ( xoffsete > (double)fixedX )
    return -1;
  xoffseta = *(int *)v9 >= 0 ? *(_DWORD *)(v9 + 20) : *(unsigned __int16 *)(v9 + 20);
  if ( (double)xoffseta + v11 < v10 )
    return -1;
  xoffsetb = 0;
  if ( *(int *)v9 >= 0 )
    ya = *(_DWORD *)(v9 + 4);
  else
    ya = *(unsigned __int8 *)(v9 + 28);
  v12 = (const int *)(v9 + 30);
  if ( *(int *)v9 >= 0 )
    v12 = (const int *)(v9 + 42);
  FormatData = GFxTextLineBuffer::Line::GetFormatData(
                 this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v9,
                 a2: v22,
                 a3: v25,
                 a4: (const int *)v26,
                 a5: v27,
                 a6: v28,
                 a7: v29);
  v34 = -1;
  v36 = -1;
  v35 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v42 = 0;
  v41 = 0;
  v40 = 0;
  v43 = 0;
  v33 = 0;
  v32 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = nullptr;
  v48 = nullptr;
  v49 = 0;
  v50 = 0;
  v29 = v12;
  v30 = (unsigned int)&v12[2 * ya];
  v31 = FormatData;
  GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v23);
  v14 = 0;
  while ( v29 != nullptr && (unsigned int)v29 < v30 )
  {
    v15 = *((unsigned __int16 *)v29 + 1);
    if ( (*((_BYTE *)v29 + 6) & 0x40) != 0 )
      v15 = -v15;
    xoffsetb += v15;
    xoffInLinea = v10 - v11;
    if ( xoffInLinea < (double)xoffsetb )
      break;
    v14 += *((unsigned __int16 *)v29 + 2) >> 12;
    GFxTextLineBuffer::GlyphIterator::operator++(result: v24);
  }
  v16 = *(_DWORD *)v9;
  v17 = *(_DWORD *)(v9 + 8);
  if ( v16 < 0 )
  {
    v17 &= 0xFFFFFFu;
    if ( v17 == 0xFFFFFF )
      v17 = -1;
  }
  v18 = baseIdx + v14 + v17;
  if ( v48 != nullptr )
    GRefCountNTSImpl::Release(this: v48);
  v19 = v47;
  if ( v47 != nullptr )
  {
    --LODWORD(v47->m_pfnProxied);
    v20 = v19;
    if ( LODWORD(v19->m_pfnProxied) == 0 )
    {
      GFxFontHandle::~GFxFontHandle(this: v19);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v20);
    }
  }
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x10139D40
// Name: public: void GFxStaticTextRecordList::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStaticTextRecordList::Clear(
        GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *this)
{
  unsigned int Size; // ecx
  unsigned int v3; // ebx
  GString::DataDesc *pData; // esi
  IShaderDevice *RefCount; // ecx
  unsigned int sza; // [esp+Ch] [ebp-4h]

  Size = this->Size;
  v3 = 0;
  for ( sza = Size; v3 < Size; ++v3 )
  {
    if ( this->Data[v3].HeapTypeBits != 0 )
    {
      pData = this->Data[v3].pData;
      if ( pData[1].Size == 0 )
      {
        RefCount = (IShaderDevice *)pData[1].RefCount;
        if ( RefCount != nullptr )
          GFxResource::Release(this: RefCount);
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)pData->Size);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pData);
      Size = sza;
    }
  }
  if ( this->Size == 0 )
  {
    if ( this->Policy.Capacity == 0 )
      GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&this->Data,
        result: this,
        newCapacity: 0);
    goto LABEL_15;
  }
  if ( (this->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_15:
    this->Size = 0;
    return;
  }
  if ( this->Data != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->Data);
    this->Data = nullptr;
  }
  this->Policy.Capacity = 0;
  this->Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10139E70
// Name: public: class GFxStaticTextCharacter::HighlightDesc __near * GFxStaticTextCharacter::CreateTextHighlighter(void)
// Source: json
//------------------------------------------------------------------------------
IClientTools *__usercall GFxStaticTextCharacter::CreateTextHighlighter@<eax>(
        GFxStaticTextCharacter *this@<ecx>,
        Vector *a2@<edi>)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(int, int, int *); // edx
  GFxTextHighlighter *v6; // eax
  IClientTools *v7; // edi
  QAngle *v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 93) != 0 )
    return *((IClientTools **)this + 93);
  v3 = (*(int (__thiscall **)(GFxStaticTextCharacter *))(*(_DWORD *)this + 84))(a1: this);
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 244))(a1: v3);
  v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
  v11 = 324;
  v6 = (GFxTextHighlighter *)v5(a1: v4, a2: 164, a3: &v11);
  v7 = (IClientTools *)v6;
  if ( v6 != nullptr )
  {
    GFxTextHighlighter::GFxTextHighlighter(this: v6);
    GFxDrawingContext::GFxDrawingContext(this: v7 + 7, a2, a3: v10, a4: (float *)v11);
    *((_DWORD *)this + 93) = v7;
    return v7;
  }
  else
  {
    *((_DWORD *)this + 93) = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139EF0
// Name: public: void GFxStaticTextSnapshotData::Add(class GFxStaticTextCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStaticTextSnapshotData::Add(
        GPtr<GFxAmpViewStats> *this@<ecx>,
        CMatRenderContextBase *a2@<ebx>,
        GRefCountNTSImpl *pstChar)
{
  GRefCountNTSImpl *v3; // esi
  int v5; // ecx
  int v6; // esi
  int v7; // ebx
  const int *v8; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v9; // eax
  int v10; // ecx
  int v11; // edi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v12; // esi
  unsigned __int16 *v13; // eax
  int v14; // eax
  CImagePacker *v15; // eax
  unsigned int v16; // ecx
  GFxFontManager *v17; // ecx
  IShaderDevice *v18; // ecx
  IShaderDevice *v19; // ecx
  IShaderDevice *v20; // ecx
  volatile LONG *v21; // edi
  GRefCountNTSImpl **v22; // eax
  GRefCountNTSImpl *v23; // edx
  CMatRenderContextBase *v24; // [esp-4h] [ebp-94h]
  const VJobInstance *v25; // [esp-4h] [ebp-94h]
  __int128 v26; // [esp+0h] [ebp-90h]
  const int *v27; // [esp+10h] [ebp-80h]
  const int *v28; // [esp+14h] [ebp-7Ch]
  const int *v29; // [esp+18h] [ebp-78h]
  const int *v30; // [esp+1Ch] [ebp-74h]
  unsigned int v31; // [esp+20h] [ebp-70h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v32; // [esp+28h] [ebp-68h] BYREF
  char v33; // [esp+58h] [ebp-38h]
  int v34; // [esp+5Ch] [ebp-34h]
  int v35; // [esp+60h] [ebp-30h]
  int v36; // [esp+64h] [ebp-2Ch]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v37; // [esp+68h] [ebp-28h]
  GRefCountNTSImpl *v38; // [esp+6Ch] [ebp-24h]
  int v39; // [esp+70h] [ebp-20h]
  unsigned int p; // [esp+74h] [ebp-1Ch]
  GRefCountNTSImpl *v41; // [esp+7Ch] [ebp-14h]
  float xoffset; // [esp+80h] [ebp-10h]
  GPtr<GFxAmpViewStats> *v43; // [esp+84h] [ebp-Ch]
  float lineXOffset; // [esp+88h] [ebp-8h]
  bool bfirst; // [esp+8Fh] [ebp-1h]

  v3 = pstChar;
  v5 = 0;
  v43 = this;
  if ( pstChar != nullptr )
    ++pstChar->RefCount;
  v24 = a2;
  xoffset = 0.0;
  v41 = nullptr;
  bfirst = true;
  v27 = nullptr;
  while ( v3 != (GRefCountNTSImpl *)-124 && (GRefCountNTSImpl_vtbl *)v5 < v3[16].__vftable && v5 >= 0 )
  {
    v6 = *(_DWORD *)(v3[15].RefCount + 4 * v5);
    lineXOffset = *(float *)(v6 + 12);
    lineXOffset = (float)SLODWORD(lineXOffset);
    if ( bfirst )
    {
      xoffset = lineXOffset;
    }
    else if ( xoffset == lineXOffset )
    {
      GString::AppendChar(this: (unsigned int *)this + 3, result: (CImagePacker *)0xA);
    }
    if ( *(int *)v6 >= 0 )
      v7 = *(_DWORD *)(v6 + 4);
    else
      v7 = *(unsigned __int8 *)(v6 + 28);
    v8 = (const int *)(v6 + 30);
    if ( *(int *)v6 >= 0 )
      v8 = (const int *)(v6 + 42);
    GFxTextLineBuffer::Line::GetFormatData(
      this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v6,
      a2: v24,
      a3: v26,
      a4: v27,
      a5: v28,
      a6: v29,
      a7: v30);
    v32.m_iRefs = -1;
    v31 = (unsigned int)&v8[2 * v7];
    v32.m_Proxy.m_pfnProxied = 0xFFFFFFFF00000000uLL;
    memset(&v32.m_Proxy.m_pObject, 0, 16);
    v33 = 0;
    v32.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
    v32.m_nUserID = 0;
    v34 = 0;
    v35 = 0;
    v36 = 0;
    v37 = nullptr;
    v38 = nullptr;
    v39 = 0;
    p = 0;
    v30 = v8;
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v25);
    v9 = v37;
    if ( v37 != nullptr )
      v10 = DWORD1(v37[1].m_pfnProxied);
    else
      v10 = 0;
    v11 = *(_DWORD *)(v10 + 12);
    if ( v11 != 0 )
    {
LABEL_26:
      v13 = (unsigned __int16 *)v30;
      while ( v13 != nullptr && (unsigned int)v13 < v31 )
      {
        v14 = *v13;
        if ( (_WORD)v14 == 0xFFFF )
          v14 = -1;
        v15 = (CImagePacker *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 52))(a1: v11, a2: v14);
        if ( v15 != (CImagePacker *)-1 )
        {
          v41 = (GRefCountNTSImpl *)((char *)v41 + 1);
          GString::AppendChar(this: (unsigned int *)&v43[3], result: v15);
        }
        v13 = (unsigned __int16 *)v30;
        if ( v30 == nullptr )
          break;
        if ( (unsigned int)v30 < v31 )
        {
          v16 = p;
          if ( p == 0 )
          {
            v16 = *((unsigned __int16 *)v30 + 2) >> 12;
            p = v16;
          }
          v30 += 2;
          if ( (v30[1] & 0xF000) != 0
            && v16 != 0
            && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v32) )
          {
            GFxTextHighlighterPosIterator::operator+=(this: &v32, p);
            p = 0;
          }
          GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: (const VJobInstance *)v24);
          goto LABEL_26;
        }
      }
      bfirst = false;
      if ( v38 != nullptr )
        GRefCountNTSImpl::Release(this: v38);
      v12 = v37;
      if ( v37 != nullptr )
      {
        --LODWORD(v37->m_pfnProxied);
        if ( LODWORD(v12->m_pfnProxied) == 0 )
        {
          v17 = (GFxFontManager *)DWORD1(v12->m_pfnProxied);
          if ( v17 != nullptr )
            GFxFontManager::RemoveFontHandle(this: v17, a2: (struct GFxFontHandle *)v12);
          v18 = (IShaderDevice *)DWORD1(v12[1].m_pfnProxied);
          if ( v18 != nullptr )
            GFxResource::Release(this: v18);
          DWORD1(v12[1].m_pfnProxied) = 0;
          v19 = (IShaderDevice *)DWORD2(v12[1].m_pfnProxied);
          if ( v19 != nullptr )
            GFxResource::Release(this: v19);
          v20 = (IShaderDevice *)DWORD1(v12[1].m_pfnProxied);
          if ( v20 != nullptr )
            GFxResource::Release(this: v20);
          v21 = (volatile LONG *)(HIDWORD(v12->m_pfnProxied) & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(Addend: v21 + 1, Value: -1) == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v21);
          goto LABEL_56;
        }
      }
    }
    else
    {
      if ( v38 != nullptr )
      {
        GRefCountNTSImpl::Release(this: v38);
        v9 = v37;
      }
      if ( v9 != nullptr )
      {
        --LODWORD(v9->m_pfnProxied);
        v12 = v9;
        if ( LODWORD(v9->m_pfnProxied) == 0 )
        {
          GFxFontHandle::~GFxFontHandle(this: v9);
LABEL_56:
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
        }
      }
    }
    this = v43;
    v3 = pstChar;
    if ( (GRefCountNTSImpl_vtbl *)v27 < pstChar[16].__vftable )
      v27 = (const int *)((char *)v27 + 1);
    v5 = (int)v27;
  }
  GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    (GPtr<GFxAmpProfileFrame> *)this,
    pheapAddr: (const CStudioHdr *)this,
    newSize: *((_DWORD *)this + 1) + 1);
  v22 = (GRefCountNTSImpl **)((char *)this->pObject + 8 * *((_DWORD *)this + 1) - 8);
  if ( (GFxAmpViewStats *)((char *)this->pObject + 8 * *((_DWORD *)this + 1)) != (GFxAmpViewStats *)8 )
  {
    if ( v3 != nullptr )
      ++v3->RefCount;
    v23 = v41;
    *v22 = v3;
    v22[1] = v23;
  }
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1013A1D0
// Name: public: void GFxStaticTextSnapshotData::SetSelected(unsigned int,unsigned int,bool)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall GFxStaticTextSnapshotData::SetSelected(
        GPtr<GFxAmpViewStats> *this,
        Vector *start,
        unsigned int end,
        bool bselect)
{
  Vector *v4; // edi
  unsigned int v6; // ecx
  Vector *result; // eax
  GPtr<GFxAmpViewStats> *v8; // esi
  GFxStaticTextCharacter **v9; // edx
  IClientTools *TextHighlighter; // eax
  int v11; // ecx
  int (__cdecl *v12)(const char *const *, const char *const *); // edi
  GFxAmpViewStats *pObject; // edx
  unsigned int v14; // esi
  unsigned int v15; // edx
  int (__cdecl *desc)(const char *const *, const char *const *); // [esp+Ch] [ebp-34h] BYREF
  unsigned int v17; // [esp+10h] [ebp-30h]
  int v18; // [esp+14h] [ebp-2Ch]
  int (__cdecl *v19)(const char *const *, const char *const *); // [esp+18h] [ebp-28h]
  unsigned int v20; // [esp+1Ch] [ebp-24h]
  int v21; // [esp+20h] [ebp-20h]
  int v22; // [esp+24h] [ebp-1Ch]
  int v23; // [esp+28h] [ebp-18h]
  int v24; // [esp+2Ch] [ebp-14h]
  char v25; // [esp+30h] [ebp-10h]
  unsigned int charEndIdx; // [esp+34h] [ebp-Ch]
  unsigned int lenUnprocessed; // [esp+38h] [ebp-8h]
  unsigned int i; // [esp+3Ch] [ebp-4h]

  v4 = start;
  v6 = 0;
  result = (Vector *)(end - (_DWORD)start);
  v8 = nullptr;
  lenUnprocessed = end - (_DWORD)start;
  for ( i = 0; v6 < *((_DWORD *)this + 1); i = v6 )
  {
    v9 = (GFxStaticTextCharacter **)((char *)this->pObject + 8 * v6);
    result = (Vector *)((char *)v9[1] + (_DWORD)v8);
    charEndIdx = (unsigned int)result;
    if ( v4 > (Vector *)v8 )
      goto LABEL_5;
    if ( (unsigned int)v8 < end )
      goto LABEL_6;
    if ( v4 >= (Vector *)v8 )
    {
LABEL_5:
      if ( v4 < result )
      {
LABEL_6:
        TextHighlighter = *((IClientTools **)*v9 + 93);
        if ( TextHighlighter == nullptr )
          TextHighlighter = GFxStaticTextCharacter::CreateTextHighlighter(this: *v9, a2: v4);
        v11 = *((_DWORD *)this + 4);
        v17 = 0;
        v18 = -1;
        v19 = nullptr;
        v20 = 0;
        v21 = 0;
        v24 = 0;
        v23 = 0;
        v25 = 8;
        v22 = v11;
        if ( v8 <= (GPtr<GFxAmpViewStats> *)v4 )
          v12 = (int (__cdecl *)(const char *const *, const char *const *))((char *)v4 - (char *)v8);
        else
          v12 = nullptr;
        pObject = this->pObject;
        v14 = lenUnprocessed;
        desc = v12;
        v15 = *((_DWORD *)pObject + 2 * i + 1) - (_DWORD)v12;
        if ( lenUnprocessed < v15 )
          v15 = lenUnprocessed;
        v17 = v15;
        v20 = v15;
        v19 = v12;
        if ( bselect )
          GFxTextHighlighter::Add(
            this: (IResourceAccessControl *)TextHighlighter,
            merge: (const IResourceAccessControl *)&desc);
        else
          GFxTextHighlighter::Remove(
            this: (CUtlMemory<char const *,int> *)TextHighlighter,
            a2: (const struct GFxTextHighlightDesc *)&desc);
        v4 = start;
        v6 = i;
        result = (Vector *)charEndIdx;
        lenUnprocessed = v14 - v17;
      }
    }
    ++v6;
    v8 = (GPtr<GFxAmpViewStats> *)result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013A2D0
// Name: public: virtual unsigned int GFxStaticTextCharacterDef::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
int GFxStaticTextCharacterDef::GetResourceTypeCode()
{
  return 33280;
}

//------------------------------------------------------------------------------
// Address: 0x1013A2E0
// Name: public: virtual class GRect<float> GFxStaticTextCharacterDef::GetBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxStaticTextCharacterDef::GetBoundsLocal(float *this, float *a2)
{
  *a2 = *(this + 4);
  a2[1] = *(this + 5);
  a2[2] = *(this + 6);
  a2[3] = *(this + 7);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1013A310
// Name: void GFx_DefineTextLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineTextLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  unsigned __int16 v8; // dx
  int v9; // ecx
  unsigned int v10; // ebx
  int (__thiscall *v11)(int, int, HBITMAP__ *); // edx
  int v12; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v13; // ecx
  int v14; // esi

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v8 = v6 | (v7 << 8);
  v9 = *(_DWORD *)(*(_DWORD *)(v2.unused + 32) + 28);
  v10 = v8;
  v11 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v9 + 40);
  p.unused = 258;
  v12 = v11(a1: v9, a2: 72, a3: &p);
  v14 = v12;
  if ( v12 != 0 )
  {
    *(_DWORD *)v12 = &GFxResource::`vftable';
    *(_DWORD *)(v12 + 4) = 1;
    *(_DWORD *)(v12 + 8) = 0;
    *(_DWORD *)(v12 + 12) = 0x40000;
    *(_DWORD *)v12 = &GFxStaticTextCharacterDef::`vftable';
    *(float *)(v12 + 16) = 0.0;
    *(float *)(v12 + 20) = 0.0;
    *(float *)(v12 + 24) = 0.0;
    *(float *)(v12 + 28) = 0.0;
    GMatrix2D::SetIdentity(this: (float *)(v12 + 32));
    *(_DWORD *)(v14 + 56) = 0;
    *(_DWORD *)(v14 + 60) = 0;
    *(_DWORD *)(v14 + 64) = 0;
    *(_BYTE *)(v14 + 68) = 0;
  }
  else
  {
    v14 = 0;
  }
  GFxLogBase<GFxLoadProcess>::LogParse(this: v13, pfmt: v2.unused + 20, a3: (int)"TextCharacter, id = %d\n", a4: v10);
  GFxStaticTextCharacterDef::Read(this: (float *)v14, p: (char *)v2.unused, a3: *(_DWORD *)tagInfo);
  if ( *(_DWORD *)(v2.unused + 760) == 0 )
    GFxMovieDataDef::LoadTaskData::AddResource(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v2.unused + 32),
      rid: v10,
      pres: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v14);
  if ( v14 != 0 )
    GFxResource::Release(this: (IShaderDevice *)v14);
}

//------------------------------------------------------------------------------
// Address: 0x1013A410
// Name: public: GFxStaticTextSnapshotData::GFxStaticTextSnapshotData(void)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxAmpViewStats> *__thiscall GFxStaticTextSnapshotData::GFxStaticTextSnapshotData(GPtr<GFxAmpViewStats> *this)
{
  this->pObject = nullptr;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 3));
  *((_DWORD *)this + 4) = -256;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1028BCB0
// Name: _dynamic_initializer_for__static_inst__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__static_inst__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__static_inst__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BD90
// Name: _dynamic_initializer_for__static_inst_data__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__static_inst_data__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__static_inst_data__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BDA0
// Name: _dynamic_initializer_for__static_inst_key__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__static_inst_key__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__static_inst_key__);
}

//------------------------------------------------------------------------------
// Address: 0x1028CAE0
// Name: _dynamic_atexit_destructor_for__static_inst__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__static_inst__()
{
  static_inst = &GFxResourceData::DataInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CBA0
// Name: _dynamic_atexit_destructor_for__static_inst_data__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__static_inst_data__()
{
  GFxRectangle_DefaultParams.HeapLock.cs.SpinCount = (unsigned int)&GFxResourceData::DataInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CBB0
// Name: _dynamic_atexit_destructor_for__static_inst_key__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__static_inst_key__()
{
  *(_DWORD *)&GFxRectangle_DefaultParams.UseLocks = &GFxResourceKey::KeyInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10138280
// Name: class GPoint<float> ClosestPointOnRectangle(class GRect<float> const __near &,class GPoint<float> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float *__cdecl ClosestPointOnRectangle(float *a1, float *a2, float *a3)
{
  int v3; // edx
  double v4; // st5
  double v5; // st4
  float *result; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st5
  float v10; // [esp+0h] [ebp-28h] BYREF
  float v11; // [esp+4h] [ebp-24h]
  float v12; // [esp+8h] [ebp-20h] BYREF
  float v13; // [esp+Ch] [ebp-1Ch]
  float v14; // [esp+10h] [ebp-18h] BYREF
  float v15; // [esp+14h] [ebp-14h]
  float v16; // [esp+18h] [ebp-10h] BYREF
  float v17; // [esp+1Ch] [ebp-Ch]
  float v18; // [esp+20h] [ebp-8h]
  float v19; // [esp+24h] [ebp-4h]
  float v20; // [esp+34h] [ebp+Ch]
  float v21; // [esp+34h] [ebp+Ch]
  float v22; // [esp+34h] [ebp+Ch]
  float v23; // [esp+34h] [ebp+Ch]

  v16 = *a2;
  v3 = 0;
  v17 = a2[1];
  v12 = a2[2];
  v13 = a2[1];
  v14 = *a2;
  v15 = a2[3];
  v10 = a2[2];
  v11 = a2[3];
  if ( v16 < (double)*a3 )
  {
    v3 = 2;
    if ( *a3 < (double)v12 )
      v3 = 1;
  }
  v4 = v17;
  v5 = v15;
  if ( v17 < (double)a3[1] )
  {
    if ( a3[1] < v5 )
      v3 |= 0x10u;
    else
      v3 |= 0x20u;
  }
  switch ( v3 )
  {
    case 0:
      *a1 = v16;
      a1[1] = v4;
      return a1;
    case 1:
      v21 = GMath2D::CalcPointToSegmentPos<GPoint<float>,GPoint<float>>(a1: &v16, a2: &v12, a3);
      v7 = v21;
      v18 = v16 + (v12 - v16) * v21;
      v8 = v13;
      goto LABEL_11;
    case 2:
      *a1 = v12;
      a1[1] = v13;
      return a1;
    case 16:
      v20 = GMath2D::CalcPointToSegmentPos<GPoint<float>,GPoint<float>>(a1: &v16, a2: &v14, a3);
      v7 = v20;
      v18 = v16 + (v14 - v16) * v20;
      v8 = v15;
LABEL_11:
      v9 = v17;
      goto LABEL_12;
    case 17:
    case 33:
      v22 = GMath2D::CalcPointToSegmentPos<GPoint<float>,GPoint<float>>(a1: &v14, a2: &v10, a3);
      v7 = v22;
      v18 = v14 + (v10 - v14) * v22;
      v8 = v11;
      v9 = v15;
      goto LABEL_12;
    case 18:
      v23 = GMath2D::CalcPointToSegmentPos<GPoint<float>,GPoint<float>>(a1: &v12, a2: &v10, a3);
      v7 = v23;
      v18 = v12 + (v10 - v12) * v23;
      v8 = v11;
      v9 = v13;
LABEL_12:
      v19 = v7 * (v8 - v9) + v9;
      *a1 = v18;
      a1[1] = v19;
      result = a1;
      break;
    case 32:
      *a1 = v14;
      a1[1] = v5;
      result = a1;
      break;
    case 34:
      *a1 = v10;
      a1[1] = v11;
      result = a1;
      break;
    default:
      *a1 = 3.4028235e38;
      a1[1] = 3.4028235e38;
      result = a1;
      break;
  }
  return result;
}
