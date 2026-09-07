// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontresource.cpp
// Functions: 107
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontresource.h"

//------------------------------------------------------------------------------
// Address: 0x10011CC0
// Name: public: virtual char const __near * GFxFontDataCompactedGfx::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
tagELEMDESC *__thiscall GFxFontDataCompactedGfx::GetName(_DWORD *this)
{
  return (tagELEMDESC *)*(this + 17);
}

//------------------------------------------------------------------------------
// Address: 0x1004F990
// Name: public: virtual unsigned int GFxFontResource::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontResource::GetResourceTypeCode(CDummyMaterial *this)
{
  return 512;
}

//------------------------------------------------------------------------------
// Address: 0x100D5860
// Name: public: class GFxFont __near * GFxMovieDataDef::LoadTaskData::GetFontData(class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
struct GFxFont *__thiscall GFxMovieDataDef::LoadTaskData::GetFontData(
        GFxMovieDataDef::LoadTaskData *this,
        struct GFxResourceId a2)
{
  _DWORD *v2; // eax

  v2 = *((_DWORD **)this + 41);
  if ( v2 == nullptr )
    return nullptr;
  while ( *v2 != a2.Id )
  {
    v2 = (_DWORD *)v2[3];
    if ( v2 == nullptr )
      return nullptr;
  }
  return (struct GFxFont *)v2[1];
}

//------------------------------------------------------------------------------
// Address: 0x1014EBE0
// Name: public: float GFxTextureGlyphData::GetTextureGlyphScale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxTextureGlyphData::GetTextureGlyphScale(GFxTextureGlyphData *this)
{
  return (float)(1536.0 / (double)*((int *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x1014EC00
// Name: public: virtual bool GFxFontDataCompactedSwf::HasVectorOrRasterGlyphs(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxFontDataCompactedSwf::HasVectorOrRasterGlyphs(_DWORD *this)
{
  return *(this + 26) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014EC10
// Name: public: unsigned int GFxPathDataDecoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(unsigned int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
        void *this,
        unsigned int pos,
        int *v)
{
  int v3; // edx
  int v4; // eax

  v3 = *(_DWORD *)(*(_DWORD *)this + 12);
  v4 = *(char *)(*(_DWORD *)(v3 + 4 * (pos >> 12)) + (pos & 0xFFF));
  if ( (v4 & 1) != 0 )
  {
    *v = (v4 >> 1) & 0x7F | (*(char *)(*(_DWORD *)(v3 + 4 * ((pos + 1) >> 12)) + ((pos + 1) & 0xFFF)) << 7);
    return 2;
  }
  else
  {
    *v = v4 >> 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EC80
// Name: public: unsigned int GFxPathDataDecoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
        int *this,
        unsigned int a2,
        int *a3)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  unsigned int v6; // edx

  v4 = *(_DWORD *)(*this + 12);
  v5 = *(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * (a2 >> 12)) + (a2 & 0xFFF)) >> 2;
  if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * (a2 >> 12)) + (a2 & 0xFFF)) & 3) != 0 )
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * (a2 >> 12)) + (a2 & 0xFFF)) & 3) == 1 )
    {
      *a3 = v5 | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((a2 + 1) >> 12)) + ((a2 + 1) & 0xFFF)) << 6);
      return 2;
    }
    else
    {
      v6 = a2 + 1;
      if ( (*(_BYTE *)(*(_DWORD *)(v4 + 4 * (a2 >> 12)) + (a2 & 0xFFF)) & 3) == 2 )
      {
        *a3 = v5
            | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * (v6 >> 12)) + (v6 & 0xFFF))
              | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((a2 + 2) >> 12)) + ((a2 + 2) & 0xFFF)) << 8)) << 6);
        return 3;
      }
      else
      {
        v3 = *this;
        *a3 = v5
            | ((*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v3 + 12) + 4 * (v6 >> 12)) + (v6 & 0xFFF))
              | ((*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v3 + 12) + 4 * ((a2 + 2) >> 12)) + ((a2 + 2) & 0xFFF))
                | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v3 + 12) + 4 * ((a2 + 3) >> 12)) + ((a2 + 3) & 0xFFF)) << 8)) << 8)) << 6);
        return 4;
      }
    }
  }
  else
  {
    *a3 = v5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EDA0
// Name: private: void GFxGlyphPathIterator<class GArrayPagedLH_POD<unsigned char,12,256,261>>::readPathHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::readPathHeader(int this)
{
  unsigned int v2; // eax

  if ( *(_DWORD *)(this + 24) != 0 )
  {
    *(_DWORD *)(this + 4) += GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
                               (void *)this,
                               pos: *(_DWORD *)(this + 4),
                               v: (int *)(this + 16));
    *(_DWORD *)(this + 4) += GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
                               (void *)this,
                               pos: *(_DWORD *)(this + 4),
                               v: (int *)(this + 20));
    *(_DWORD *)(this + 4) += GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
                               (int *)this,
                               a2: *(_DWORD *)(this + 4),
                               a3: (int *)(this + 28));
    *(_DWORD *)(this + 32) = *(_DWORD *)(this + 4);
    v2 = *(_DWORD *)(this + 28);
    *(_BYTE *)(this + 36) = 1;
    if ( (v2 & 1) != 0 )
    {
      *(_DWORD *)(this + 32) = v2 >> 1;
      *(_DWORD *)(this + 32) += GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
                                  (int *)this,
                                  a2: v2 >> 1,
                                  a3: (int *)(this + 28));
      *(_BYTE *)(this + 36) = 0;
    }
    *(_DWORD *)(this + 28) >>= 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EE10
// Name: public: unsigned int GFxPathDataDecoder<class GArrayUnsafeLH_POD<unsigned char,261>>::ReadUInt30(unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataDecoder<GArrayUnsafeLH_POD<unsigned char,261>>::ReadUInt30(
        _DWORD **this,
        unsigned int pos,
        unsigned int *v)
{
  unsigned __int8 *v3; // edx
  int v4; // eax

  v3 = (unsigned __int8 *)(**this + pos);
  v4 = *v3 >> 2;
  if ( (*v3 & 3) != 0 )
  {
    if ( (*v3 & 3) == 1 )
    {
      *v = v4 | (v3[1] << 6);
      return 2;
    }
    else if ( (*v3 & 3) == 2 )
    {
      *v = v4 | ((v3[1] | (v3[2] << 8)) << 6);
      return 3;
    }
    else
    {
      *v = v4 | ((v3[1] | ((v3[2] | (v3[3] << 8)) << 8)) << 6);
      return 4;
    }
  }
  else
  {
    *v = v4;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EEA0
// Name: private: void GFxGlyphPathIterator<class GArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(int this)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // eax
  char *v5; // ecx
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax

  if ( *(_DWORD *)(this + 24) != 0 )
  {
    v2 = (char *)(*(_DWORD *)(this + 4) + **(_DWORD **)this);
    v3 = *v2;
    if ( (v3 & 1) != 0 )
    {
      *(_DWORD *)(this + 16) = (v3 >> 1) & 0x7F | (v2[1] << 7);
      v4 = 2;
    }
    else
    {
      *(_DWORD *)(this + 16) = v3 >> 1;
      v4 = 1;
    }
    *(_DWORD *)(this + 4) += v4;
    v5 = (char *)(*(_DWORD *)(this + 4) + **(_DWORD **)this);
    v6 = *v5;
    if ( (v6 & 1) != 0 )
    {
      *(_DWORD *)(this + 20) = (v6 >> 1) & 0x7F | (v5[1] << 7);
      v7 = 2;
    }
    else
    {
      *(_DWORD *)(this + 20) = v6 >> 1;
      v7 = 1;
    }
    *(_DWORD *)(this + 4) += v7;
    *(_DWORD *)(this + 4) += GFxPathDataDecoder<GArrayUnsafeLH_POD<unsigned char,261>>::ReadUInt30(
                               (_DWORD **)this,
                               pos: *(_DWORD *)(this + 4),
                               v: (unsigned int *)(this + 28));
    *(_DWORD *)(this + 32) = *(_DWORD *)(this + 4);
    v8 = *(_DWORD *)(this + 28);
    *(_BYTE *)(this + 36) = 1;
    if ( (v8 & 1) != 0 )
    {
      *(_DWORD *)(this + 32) = v8 >> 1;
      *(_DWORD *)(this + 32) += GFxPathDataDecoder<GArrayUnsafeLH_POD<unsigned char,261>>::ReadUInt30(
                                  (_DWORD **)this,
                                  pos: v8 >> 1,
                                  v: (unsigned int *)(this + 28));
      *(_BYTE *)(this + 36) = 0;
    }
    *(_DWORD *)(this + 28) >>= 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EF50
// Name: public: unsigned int GFxPathDataDecoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(unsigned int,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
        void *this,
        unsigned int a2,
        _BYTE *a3)
{
  char v4; // cl
  int v5; // ecx
  unsigned int v6; // eax
  _BYTE *v7; // edx
  int i; // [esp+10h] [ebp+8h]

  v4 = *(_BYTE *)((a2 & 0xFFF) + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 12) + 4 * (a2 >> 12)));
  *a3 = v4;
  v5 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v4 & 0xF];
  v6 = a2 + 1;
  v7 = a3 + 1;
  if ( v5 == 0 )
    return 1;
  for ( i = v5; i != 0; --i )
  {
    *v7++ = *(_BYTE *)((v6 & 0xFFF) + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 12) + 4 * (v6 >> 12)));
    ++v6;
  }
  return v5 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014EFD0
// Name: public: virtual class GFxShapeBase __near * GFxFontData::GetGlyphShape(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxShapeBase *__thiscall GFxFontData::GetGlyphShape(GFxFontData *this, unsigned int a2, unsigned int a3)
{
  int v3; // ecx
  int v4; // esi

  if ( a2 >= *((_DWORD *)this + 9) )
    return nullptr;
  v3 = *((_DWORD *)this + 8);
  v4 = *(_DWORD *)(v3 + 4 * a2);
  if ( v4 != 0 )
    GFxShapeBase::AddRef(this: *(GFxShapeBase **)(v3 + 4 * a2));
  return (struct GFxShapeBase *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1014F000
// Name: public: virtual float GFxFontData::GetAdvance(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontData::GetAdvance(
        CMorph *this,
        const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *GlyphIndex)
{
  IMesh *m_pMorphBuffer; // eax

  if ( GlyphIndex == (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)-1 )
    return 512.0;
  m_pMorphBuffer = this->m_pMorphBuffer;
  if ( m_pMorphBuffer == nullptr )
  {
    if ( LOBYTE(GFxRectangle_NaNParams.ChildHeaps.Root.pNext) == 0 )
      LOBYTE(GFxRectangle_NaNParams.ChildHeaps.Root.pNext) = 1;
    return 512.0;
  }
  if ( GlyphIndex >= (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)m_pMorphBuffer )
    return 0.0;
  else
    return *(float *)&this->m_pMorphTexture[1][3 * (_DWORD)GlyphIndex].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x1014F050
// Name: public: virtual float GFxFontData::GetGlyphWidth(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontData::GetGlyphWidth(CMorph *this, IMesh *glyphIndex)
{
  double result; // st7
  float w; // [esp+8h] [ebp+8h]

  if ( glyphIndex == (IMesh *)-1 )
    return 512.0;
  if ( glyphIndex >= this->m_pMorphBuffer )
    return ((double (__thiscall *)(CMorph *, IMesh *))this->IMorphInternal::IMorph::__vftable[1].Unlock)(
             a1: this,
             a2: glyphIndex);
  w = (double)LOWORD(this->m_pMorphTexture[1][3 * (_DWORD)glyphIndex + 2].__vftable) / 20.0;
  result = w;
  if ( 0.0 == w )
    return ((double (__thiscall *)(CMorph *, IMesh *))this->IMorphInternal::IMorph::__vftable[1].Unlock)(
             a1: this,
             a2: glyphIndex);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014F0B0
// Name: public: virtual float GFxFontData::GetGlyphHeight(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontData::GetGlyphHeight(
        CMorph *this,
        const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *glyphIndex)
{
  IMesh *m_pMorphBuffer; // edx

  if ( glyphIndex == (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)-1 )
    return 1024.0;
  m_pMorphBuffer = this->m_pMorphBuffer;
  if ( m_pMorphBuffer == nullptr )
    return 1024.0;
  if ( glyphIndex >= (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)m_pMorphBuffer )
    return 0.0;
  return (float)((double)HIWORD(this->m_pMorphTexture[1][3 * (_DWORD)glyphIndex + 2].__vftable) / 20.0);
}

//------------------------------------------------------------------------------
// Address: 0x1014F100
// Name: public: virtual bool GFxFontDataCompactedGfx::HasVectorOrRasterGlyphs(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxFontDataCompactedGfx::HasVectorOrRasterGlyphs(GFxFontDataCompactedGfx *this)
{
  return *((_DWORD *)this + 13) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014F110
// Name: public: virtual GFxFontResource::~GFxFontResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontResource::~GFxFontResource(GFxFontResource *this)
{
  bool v2; // zf
  unsigned int i; // edi
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  GRefCountNTSImpl *v7; // ecx
  IShaderAPI *v8; // ecx

  v2 = *((_BYTE *)this + 32) == 0;
  this->cElems = (unsigned int)&GFxFontResource::`vftable';
  if ( v2 )
  {
    v5 = *((_DWORD *)this + 9);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int, GFxFontResource *))(*(_DWORD *)v5 + 4))(a1: v5, a2: this);
  }
  else
  {
    for ( i = 0; i < *(_DWORD *)(*((_DWORD *)this + 9) + 4); ++i )
    {
      v4 = *(_DWORD *)(**((_DWORD **)this + 9) + 4 * i);
      (*(void (__thiscall **)(int, GFxFontResource *))(*(_DWORD *)v4 + 4))(a1: v4, a2: this);
    }
  }
  v6 = *((_DWORD *)this + 6);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 8))(a1: v6, a2: *((_DWORD *)this + 7));
  v7 = *((GRefCountNTSImpl **)this + 4);
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  v8 = *((IShaderAPI **)this + 3);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  this->cElems = (unsigned int)&GFxResource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1014F190
// Name: public: virtual class GFxResourceKey GFxFontResource::GetKey(void)
// Source: json
//------------------------------------------------------------------------------
GFxResourceKey *__thiscall GFxFontResource::GetKey(GFxFontResource *this, GFxResourceKey *a2)
{
  GFxResourceKey::GFxResourceKey(this: a2, a2: (const struct GFxResourceKey *)this + 3);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1014F1B0
// Name: public: bool GFxSystemFontResourceKey::operator==(class GFxSystemFontResourceKey __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxSystemFontResourceKey::operator==(_DWORD *this, _DWORD *a2)
{
  return strcmp((const char *)((*(this + 3) & 0xFFFFFFFC) + 8), (const char *)((a2[3] & 0xFFFFFFFC) + 8)) == 0
      && *(this + 2) == a2[2]
      && *(this + 4) == a2[4];
}

//------------------------------------------------------------------------------
// Address: 0x1014F220
// Name: public: virtual unsigned int GFxSystemFontResourceKeyInterface::GetHashCode(void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxSystemFontResourceKeyInterface::GetHashCode(
        GFxSystemFontResourceKeyInterface *this,
        _DWORD *a2)
{
  return (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a2[3] & 0xFFFFFFFC) + 8))
       ^ a2[2]
       ^ a2[4]
       ^ (a2[2] >> 7);
}

//------------------------------------------------------------------------------
// Address: 0x1014F260
// Name: public: virtual bool GFxSystemFontResourceKeyInterface::KeyEquals(void __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSystemFontResourceKeyInterface::KeyEquals(
        GFxSystemFontResourceKeyInterface *this,
        _DWORD *a2,
        const struct GFxResourceKey *a3)
{
  return this == (GFxSystemFontResourceKeyInterface *)a3->pKeyInterface
      && GFxSystemFontResourceKey::operator==(this: a2, a2: (_DWORD *)a3->hKeyData);
}

//------------------------------------------------------------------------------
// Address: 0x1014F280
// Name: public: int GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphIndex(
        _DWORD *this,
        unsigned __int16 code)
{
  int v2; // edi
  int v3; // eax
  int result; // eax
  unsigned int v5; // edx
  int v6; // [esp+Ch] [ebp-8h]
  int beg; // [esp+10h] [ebp-4h]

  v2 = *(this + 3) - 1;
  v3 = 0;
  beg = 0;
  if ( v2 < 0 )
    return -1;
  while ( 1 )
  {
    result = (v2 + v3) / 2;
    v6 = *(this + 4);
    v5 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(this + 2) + 12) + 4 * ((unsigned int)(v6 + 8 * result) >> 12))
                            + ((v6 + 8 * result) & 0xFFF))
       | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(this + 2) + 12)
                                         + 4 * ((unsigned int)(v6 + 8 * result + 1) >> 12))
                             + ((v6 + 8 * result + 1) & 0xFFF)) << 8);
    if ( code == v5 )
      break;
    if ( code >= v5 )
    {
      v3 = result + 1;
      beg = v3;
    }
    else
    {
      v2 = result - 1;
      v3 = beg;
    }
    if ( v3 > v2 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014F310
// Name: public: float GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::GetKerningAdjustment(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetKerningAdjustment(
        _DWORD *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  int v3; // eax
  int v4; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // edx
  unsigned int v10; // eax
  bool v11; // cf
  int v13; // [esp+10h] [ebp-14h]
  int end; // [esp+18h] [ebp-Ch]
  int beg; // [esp+1Ch] [ebp-8h]
  int mid; // [esp+20h] [ebp-4h]

  v3 = *(this + 5) - 1;
  v4 = 0;
  end = v3;
  beg = 0;
  if ( v3 < 0 )
    return 0.0;
  v5 = *(this + 6);
  v6 = *(this + 2);
  v7 = *(_DWORD *)(v6 + 12);
  v13 = v5;
  while ( 1 )
  {
    mid = (v4 + v3) / 2;
    v8 = v13 + 6 * mid;
    v9 = *(unsigned __int8 *)(*(_DWORD *)(v7 + 4 * (v8 >> 12)) + (((_WORD)v13 + 6 * (_WORD)mid) & 0xFFF))
       | (*(unsigned __int8 *)(*(_DWORD *)(v7 + 4 * ((v8 + 1) >> 12)) + ((v8 + 1) & 0xFFF)) << 8);
    v10 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v6 + 12) + 4 * ((v8 + 2) >> 12)) + ((v8 + 2) & 0xFFF))
        | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v6 + 12) + 4 * ((v8 + 3) >> 12)) + ((v8 + 3) & 0xFFF)) << 8);
    v11 = lastCode < v9;
    if ( lastCode == v9 )
    {
      v11 = thisCode < v10;
      if ( thisCode == v10 )
        break;
    }
    if ( v11 )
    {
      v4 = beg;
      v3 = mid - 1;
      end = mid - 1;
    }
    else
    {
      v3 = end;
      v4 = mid + 1;
      beg = mid + 1;
    }
    if ( v4 > v3 )
      return 0.0;
    v7 = *(_DWORD *)(v6 + 12);
  }
  return (double)(__int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v6 + 12) + 4 * ((v8 + 4) >> 12))
                                              + ((v8 + 4) & 0xFFF))
                         | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v6 + 12) + 4 * ((v8 + 5) >> 12))
                                               + ((v8 + 5) & 0xFFF)) << 8));
}

//------------------------------------------------------------------------------
// Address: 0x1014F440
// Name: public: int GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphIndex(int this, tagCLIPDATA *result)
{
  char *v2; // edi
  char *v3; // ebx
  int v4; // esi
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // [esp+Ch] [ebp-4h]

  v2 = (char *)(*(_DWORD *)(this + 12) - 1);
  v3 = nullptr;
  if ( (int)v2 < 0 )
    return -1;
  v4 = **(_DWORD **)(this + 8);
  v7 = *(_DWORD *)(this + 16);
  while ( 1 )
  {
    v5 = (int)&v2[(int)v3] / 2;
    v6 = *(unsigned __int16 *)(v4 + v7 + 8 * v5);
    if ( (unsigned __int16)result == v6 )
      break;
    if ( (unsigned __int16)result >= v6 )
      v3 = (char *)(v5 + 1);
    else
      v2 = (char *)(v5 - 1);
    if ( (int)v3 > (int)v2 )
      return -1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014F4A0
// Name: public: float GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::GetKerningAdjustment(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetKerningAdjustment(
        int this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  int v3; // eax
  int v4; // edx
  int v5; // edi
  int v6; // eax
  int v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // esi
  bool v10; // cf
  int v12; // [esp+Ch] [ebp-Ch]
  int end; // [esp+10h] [ebp-8h]
  int beg; // [esp+14h] [ebp-4h]

  v3 = *(_DWORD *)(this + 20) - 1;
  v4 = 0;
  end = v3;
  beg = 0;
  if ( v3 < 0 )
    return 0.0;
  v5 = **(_DWORD **)(this + 8);
  v12 = *(_DWORD *)(this + 24);
  while ( 1 )
  {
    v6 = (v4 + v3) / 2;
    v7 = v12 + 6 * v6;
    v8 = *(unsigned __int16 *)(v5 + v7);
    v9 = *(unsigned __int16 *)(v5 + v7 + 2);
    v10 = lastCode < v8;
    if ( lastCode == v8 )
    {
      v10 = thisCode < v9;
      if ( thisCode == v9 )
        break;
    }
    if ( v10 )
    {
      v4 = beg;
      v3 = v6 - 1;
      end = v3;
    }
    else
    {
      v4 = v6 + 1;
      v3 = end;
      beg = v4;
    }
    if ( v4 > v3 )
      return 0.0;
  }
  return (double)*(__int16 *)(v5 + v7 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1014F550
// Name: public: void GFxGlyphPathIterator<class GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
        _DWORD *this,
        unsigned int a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // eax
  unsigned int v8; // edx
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // eax
  unsigned int v19; // edx
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // esi
  int result; // eax
  unsigned int v25; // edx
  int v26; // esi

  v2 = *this;
  *(this + 1) = a2;
  v3 = *(_DWORD *)(v2 + 12);
  v4 = *(char *)(*(_DWORD *)(v3 + 4 * (a2 >> 12)) + (a2 & 0xFFF));
  if ( (v4 & 1) != 0 )
  {
    v5 = (v4 >> 1) & 0x7F | (*(char *)(*(_DWORD *)(v3 + 4 * ((a2 + 1) >> 12)) + ((a2 + 1) & 0xFFF)) << 7);
    v6 = 2;
  }
  else
  {
    LOWORD(v5) = v4 >> 1;
    v6 = 1;
  }
  v7 = *this;
  v8 = a2 + v6;
  *((_WORD *)this + 4) = v5;
  *(this + 1) = v8;
  v9 = *(_DWORD *)(v7 + 12);
  v10 = *(char *)(*(_DWORD *)(v9 + 4 * (v8 >> 12)) + (v8 & 0xFFF));
  if ( (v10 & 1) != 0 )
  {
    v11 = (v10 >> 1) & 0x7F | (*(char *)(*(_DWORD *)(v9 + 4 * ((v8 + 1) >> 12)) + ((v8 + 1) & 0xFFF)) << 7);
    v12 = 2;
  }
  else
  {
    LOWORD(v11) = v10 >> 1;
    v12 = 1;
  }
  v13 = v12 + v8;
  v14 = *this;
  *((_WORD *)this + 5) = v11;
  *(this + 1) = v13;
  v15 = *(_DWORD *)(v14 + 12);
  v16 = *(char *)(*(_DWORD *)(v15 + 4 * (v13 >> 12)) + (v13 & 0xFFF));
  if ( (v16 & 1) != 0 )
  {
    v17 = (v16 >> 1) & 0x7F | (*(char *)(*(_DWORD *)(v15 + 4 * ((v13 + 1) >> 12)) + ((v13 + 1) & 0xFFF)) << 7);
    v18 = 2;
  }
  else
  {
    LOWORD(v17) = v16 >> 1;
    v18 = 1;
  }
  v19 = v18 + v13;
  v20 = *this;
  *((_WORD *)this + 6) = v17;
  *(this + 1) = v19;
  v21 = *(_DWORD *)(v20 + 12);
  v22 = *(char *)(*(_DWORD *)(v21 + 4 * (v19 >> 12)) + (v19 & 0xFFF));
  if ( (v22 & 1) != 0 )
  {
    v26 = (v22 >> 1) & 0x7F | (*(char *)(*(_DWORD *)(v21 + 4 * ((v19 + 1) >> 12)) + ((v19 + 1) & 0xFFF)) << 7);
    result = 2;
    *((_WORD *)this + 7) = v26;
    v25 = v19 + 2;
  }
  else
  {
    v23 = v22 >> 1;
    result = 1;
    *((_WORD *)this + 7) = v23;
    v25 = v19 + 1;
  }
  *(this + 1) = v25;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014F6D0
// Name: public: void GFxGlyphPathIterator<class GArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  char *v3; // edx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // esi
  char *v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // edx
  int result; // eax
  int v20; // esi

  v2 = (_DWORD *)*this;
  *(this + 1) = a2;
  v3 = (char *)(a2 + *v2);
  v4 = *v3;
  if ( (v4 & 1) != 0 )
  {
    v5 = (v4 >> 1) & 0x7F | (v3[1] << 7);
    v6 = 2;
  }
  else
  {
    LOWORD(v5) = v4 >> 1;
    v6 = 1;
  }
  v7 = v6 + a2;
  *(this + 1) = v6 + a2;
  *((_WORD *)this + 4) = v5;
  v8 = *(char *)(*v2 + v6 + a2);
  if ( (v8 & 1) != 0 )
  {
    v9 = (v8 >> 1) & 0x7F | (*(char *)(*v2 + v7 + 1) << 7);
    v10 = 2;
  }
  else
  {
    LOWORD(v9) = v8 >> 1;
    v10 = 1;
  }
  v11 = v10 + v7;
  *((_WORD *)this + 5) = v9;
  *(this + 1) = v11;
  v12 = (char *)(v11 + *v2);
  v13 = *v12;
  if ( (v13 & 1) != 0 )
  {
    v14 = (v13 >> 1) & 0x7F | (v12[1] << 7);
    v15 = 2;
  }
  else
  {
    LOWORD(v14) = v13 >> 1;
    v15 = 1;
  }
  v16 = v15 + v11;
  *(this + 1) = v16;
  *((_WORD *)this + 6) = v14;
  v17 = *(char *)(*v2 + v16);
  if ( (v17 & 1) != 0 )
  {
    v18 = (v17 >> 1) & 0x7F | (*(char *)(*v2 + v16 + 1) << 7);
    result = 2;
    v20 = v16 + 2;
  }
  else
  {
    v18 = v17 >> 1;
    result = 1;
    v20 = v16 + 1;
  }
  *(this + 1) = v20;
  *((_WORD *)this + 7) = v18;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014F9E0
// Name: public: void GFxGlyphPathIterator<class GArrayPagedLH_POD<unsigned char,12,256,261>>::StartGlyph(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::StartGlyph(
        _DWORD *this,
        unsigned int a2)
{
  int v3; // edx
  unsigned int v4; // eax

  GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(this, a2);
  v3 = *(_DWORD *)(*this + 12);
  v4 = *(unsigned __int8 *)(*(_DWORD *)(v3 + 4 * (*(this + 1) >> 12)) + (*(this + 1) & 0xFFF));
  if ( (v4 & 1) != 0 )
  {
    *(this + 6) = (v4 >> 1)
                | (*(unsigned __int8 *)(*(_DWORD *)(v3 + 4 * ((unsigned int)(*(this + 1) + 1) >> 12))
                                      + ((*(this + 1) + 1) & 0xFFF)) << 7);
    *(this + 1) += 2;
  }
  else
  {
    *(this + 6) = v4 >> 1;
    ++*(this + 1);
  }
  GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::readPathHeader((int)this);
}

//------------------------------------------------------------------------------
// Address: 0x1014FA60
// Name: public: unsigned int GFxPathDataDecoder<class GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(unsigned int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(
        void *this,
        unsigned int pos,
        int *data)
{
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  unsigned __int8 v14; // dl
  int v15; // ecx
  int v16; // ecx
  unsigned __int8 v17; // dl
  char v18; // cl
  int v19; // eax
  char v20; // cl
  unsigned __int8 v21; // dl
  unsigned __int8 v22; // cl
  int v23; // edx
  int v24; // ecx
  unsigned __int8 v25; // dl
  unsigned __int8 v26; // cl
  int v27; // eax
  unsigned __int8 v28; // dl
  int v29; // edx
  unsigned __int8 v30; // dl
  int v31; // ebx
  unsigned __int8 v32; // cl
  int v33; // eax
  unsigned __int8 v34; // dl
  int v35; // edx
  unsigned __int8 v36; // dl
  unsigned __int8 v37; // cl
  int v38; // ebx
  int v39; // eax
  unsigned __int8 v40; // dl
  int v41; // edx
  unsigned __int8 v42; // dl
  int v43; // ebx
  unsigned __int8 v44; // cl
  int v45; // eax
  int v46; // ebx
  int v47; // eax
  unsigned __int8 v48; // dl
  int v49; // edx
  unsigned __int8 v50; // dl
  int v51; // ebx
  unsigned __int8 v52; // cl
  int v53; // eax
  int v54; // ebx
  int v55; // eax
  unsigned __int8 v56; // dl
  int v57; // eax
  int v58; // ecx
  int v59; // eax
  int v60; // edx
  unsigned __int8 v61; // dl
  int v62; // ebx
  unsigned __int8 v63; // cl
  int v64; // eax
  int v65; // ebx
  int v66; // eax
  unsigned __int8 v67; // dl
  int v68; // eax
  int v69; // ecx
  unsigned __int8 v71; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 v72; // [esp+9h] [ebp-Fh]
  unsigned __int8 v73; // [esp+Ah] [ebp-Eh]
  unsigned __int8 v74; // [esp+Bh] [ebp-Dh]
  unsigned __int8 v75; // [esp+Ch] [ebp-Ch]
  unsigned __int8 v76; // [esp+Dh] [ebp-Bh]
  unsigned __int8 v77; // [esp+Eh] [ebp-Ah]
  unsigned __int8 v78; // [esp+Fh] [ebp-9h]
  unsigned __int8 v79; // [esp+10h] [ebp-8h]
  char v80; // [esp+11h] [ebp-7h]

  v3 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(this, a2: pos, a3: &v71);
  switch ( v71 & 0xF )
  {
    case 0:
      v4 = (v71 >> 4) | (16 * (char)v72);
      *data = 0;
      data[1] = v4;
      break;
    case 1:
      v5 = (v71 >> 4) | (16 * (v72 | ((char)v73 << 8)));
      *data = 0;
      data[1] = v5;
      break;
    case 2:
      v6 = (v71 >> 4) | (16 * (char)v72);
      *data = 1;
      data[1] = v6;
      break;
    case 3:
      v7 = (v71 >> 4) | (16 * (v72 | ((char)v73 << 8)));
      *data = 1;
      data[1] = v7;
      break;
    case 4:
      v8 = ((v71 >> 2) | (char)(v72 << 6)) >> 2;
      v9 = (char)v72 >> 2;
      *data = 2;
      data[1] = v8;
      data[2] = v9;
      break;
    case 5:
      v10 = (v71 >> 4) | (4 * (char)(4 * v72));
      v11 = (4 * (char)v73) | (v72 >> 6);
      *data = 2;
      data[1] = v10;
      data[2] = v11;
      break;
    case 6:
      v12 = (v71 >> 4) | (16 * (v72 | (4 * (char)(v73 << 6))));
      v13 = ((char)v74 << 6) | (v73 >> 2);
      *data = 2;
      data[1] = v12;
      data[2] = v13;
      break;
    case 7:
      v14 = v73;
      v15 = (char)v75;
      data[1] = (v71 >> 4) | (16 * (v72 | ((char)(4 * v73) << 6)));
      v16 = (v14 >> 6) | (4 * (v74 | (v15 << 8)));
      *data = 2;
      data[2] = v16;
      break;
    case 8:
      v17 = v72;
      v18 = 2 * v72;
      data[1] = ((v71 >> 1) | (char)(v72 << 7)) >> 3;
      v19 = (char)(2 * v18);
      v20 = v73;
      data[2] = v19 >> 3;
      *data = 3;
      data[3] = ((char)(32 * v20) | (v17 >> 3)) >> 3;
      data[4] = v20 >> 3;
      break;
    case 9:
      v21 = v72;
      v22 = v73;
      data[1] = ((v71 >> 3) | (char)(32 * v72)) >> 1;
      data[2] = ((char)(v22 << 6) | (v21 >> 2)) >> 1;
      v23 = ((char)(v74 << 7) | (v22 >> 1)) >> 1;
      v24 = (char)v74 >> 1;
      *data = 3;
      data[3] = v23;
      data[4] = v24;
      break;
    case 0xA:
      v25 = v72;
      v26 = v73;
      data[1] = (v71 >> 4) | (2 * (char)(8 * v72));
      v27 = (v25 >> 5) | (2 * (char)(4 * v26));
      v28 = v74;
      data[2] = v27;
      data[3] = (v26 >> 6) | (2 * (char)(2 * v28));
      v29 = (2 * (char)v75) | (v28 >> 7);
      *data = 3;
      data[4] = v29;
      break;
    case 0xB:
      v30 = v72;
      v31 = v73;
      v32 = v74;
      data[1] = (v71 >> 4) | (8 * (char)(2 * v72));
      v33 = (v30 >> 7) | (2 * (v31 | (4 * (char)(v32 << 6))));
      v34 = v75;
      data[2] = v33;
      data[3] = (v32 >> 2) | (8 * (char)(8 * v34));
      v35 = (8 * (char)v76) | (v34 >> 5);
      *data = 3;
      data[4] = v35;
      break;
    case 0xC:
      v36 = v73;
      v37 = v74;
      data[1] = (v71 >> 4) | (16 * (v72 | (2 * (char)(v73 << 7))));
      v38 = v75;
      v39 = (v36 >> 1) | (32 * (char)(4 * v37));
      v40 = v76;
      data[2] = v39;
      data[3] = (v37 >> 6) | (4 * (v38 | (8 * (char)(32 * v40))));
      v41 = (32 * (char)v77) | (v40 >> 3);
      *data = 3;
      data[4] = v41;
      break;
    case 0xD:
      v42 = v73;
      v43 = v74;
      v44 = v75;
      data[1] = (v71 >> 4) | (16 * (v72 | (8 * (char)(32 * v73))));
      v45 = v43 | (4 * (char)(v44 << 6));
      v46 = v76;
      v47 = (v42 >> 3) | (32 * v45);
      v48 = v77;
      data[2] = v47;
      data[3] = (v44 >> 2) | ((v46 | (2 * (char)(v48 << 7))) << 6);
      v49 = ((char)v78 << 7) | (v48 >> 1);
      *data = 3;
      data[4] = v49;
      break;
    case 0xE:
      v50 = v73;
      v51 = v74;
      v52 = v75;
      data[1] = (v71 >> 4) | (16 * (v72 | (32 * (char)(8 * v73))));
      v53 = v51 | ((char)(4 * v52) << 6);
      v54 = v76;
      v55 = (v50 >> 5) | (8 * v53);
      v56 = v77;
      data[2] = v55;
      v57 = (v52 >> 6) | (4 * (v54 | ((char)(2 * v56) << 7)));
      v58 = v78;
      data[3] = v57;
      v59 = v58 | ((char)v79 << 8);
      *data = 3;
      v60 = v56 >> 7;
      goto LABEL_18;
    case 0xF:
      v61 = v73;
      v62 = v75;
      v63 = v76;
      data[1] = (v71 >> 4) | (16 * (v72 | ((char)(2 * v73) << 7)));
      v64 = v74 | ((v62 | (4 * (char)(v63 << 6))) << 8);
      v65 = v77;
      v66 = (v61 >> 7) | (2 * v64);
      v67 = v78;
      data[2] = v66;
      v68 = (v63 >> 2) | ((v65 | (32 * (char)(8 * v67))) << 6);
      v69 = v79;
      data[3] = v68;
      v59 = 4 * (v69 | (v80 << 8));
      *data = 3;
      v60 = v67 >> 5;
LABEL_18:
      data[4] = v60 | (2 * v59);
      break;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014FFF0
// Name: public: unsigned int GFxPathDataDecoder<class GArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(unsigned int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxPathDataDecoder<GArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(
        _DWORD **this,
        unsigned int pos,
        int *data)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 v4; // cl
  unsigned int v5; // edi
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  signed __int8 v10; // dl
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  unsigned __int8 v15; // dl
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  unsigned __int8 v19; // dl
  char v20; // cl
  unsigned __int8 v21; // dl
  unsigned __int8 v22; // cl
  int v23; // edx
  int v24; // ecx
  unsigned __int8 v25; // dl
  int v26; // eax
  unsigned __int8 v27; // cl
  int v28; // eax
  unsigned __int8 v29; // dl
  int v30; // edx
  unsigned __int8 v31; // dl
  int v32; // ebx
  int v33; // eax
  unsigned __int8 v34; // cl
  int v35; // eax
  unsigned __int8 v36; // dl
  int v37; // edx
  unsigned __int8 v38; // dl
  int v39; // eax
  unsigned __int8 v40; // cl
  int v41; // ebx
  int v42; // eax
  unsigned __int8 v43; // dl
  int v44; // edx
  unsigned __int8 v45; // dl
  int v46; // ebx
  int v47; // eax
  unsigned __int8 v48; // cl
  int v49; // eax
  int v50; // ebx
  int v51; // eax
  unsigned __int8 v52; // dl
  int v53; // edx
  unsigned __int8 v54; // dl
  int v55; // ebx
  int v56; // eax
  unsigned __int8 v57; // cl
  int v58; // eax
  int v59; // ebx
  int v60; // eax
  unsigned __int8 v61; // dl
  int v62; // eax
  int v63; // ecx
  int v64; // eax
  int v65; // edx
  unsigned __int8 v66; // dl
  int v67; // ebx
  int v68; // eax
  unsigned __int8 v69; // cl
  int v70; // eax
  int v71; // ebx
  int v72; // eax
  unsigned __int8 v73; // dl
  int v74; // eax
  int v75; // ecx
  unsigned __int8 v77; // [esp+8h] [ebp-10h]
  unsigned __int8 dst; // [esp+9h] [ebp-Fh] BYREF
  unsigned __int8 v79; // [esp+Ah] [ebp-Eh]
  unsigned __int8 v80; // [esp+Bh] [ebp-Dh]
  unsigned __int8 v81; // [esp+Ch] [ebp-Ch]
  unsigned __int8 v82; // [esp+Dh] [ebp-Bh]
  unsigned __int8 v83; // [esp+Eh] [ebp-Ah]
  unsigned __int8 v84; // [esp+Fh] [ebp-9h]
  unsigned __int8 v85; // [esp+10h] [ebp-8h]
  char v86; // [esp+11h] [ebp-7h]

  v3 = (unsigned __int8 *)(**this + pos);
  v4 = *v3;
  v5 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[*v3 & 0xF];
  v77 = *v3;
  if ( GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[*v3 & 0xF] != 0 )
  {
    memcpy(&dst, src: v3 + 1, count: v5);
    v4 = v77;
  }
  switch ( v4 & 0xF )
  {
    case 0:
      v6 = 16 * (char)dst;
      *data = 0;
      data[1] = v6 | (v4 >> 4);
      break;
    case 1:
      v7 = (v4 >> 4) | (16 * (dst | ((char)v79 << 8)));
      *data = 0;
      data[1] = v7;
      break;
    case 2:
      v8 = (16 * (char)dst) | (v4 >> 4);
      *data = 1;
      data[1] = v8;
      break;
    case 3:
      v9 = (v4 >> 4) | (16 * (dst | ((char)v79 << 8)));
      *data = 1;
      data[1] = v9;
      break;
    case 4:
      v10 = dst;
      data[1] = ((char)(dst << 6) | (v4 >> 2)) >> 2;
      *data = 2;
      data[2] = v10 >> 2;
      break;
    case 5:
      v11 = (v4 >> 4) | (4 * (char)(4 * dst));
      v12 = (4 * (char)v79) | (dst >> 6);
      *data = 2;
      data[1] = v11;
      data[2] = v12;
      break;
    case 6:
      v13 = (v4 >> 4) | (16 * (dst | (4 * (char)(v79 << 6))));
      v14 = ((char)v80 << 6) | (v79 >> 2);
      *data = 2;
      data[1] = v13;
      data[2] = v14;
      break;
    case 7:
      v15 = v79;
      v16 = (v4 >> 4) | (16 * (dst | ((char)(4 * v79) << 6)));
      v17 = (char)v81;
      data[1] = v16;
      v18 = (v15 >> 6) | (4 * (v80 | (v17 << 8)));
      *data = 2;
      data[2] = v18;
      break;
    case 8:
      v19 = dst;
      data[1] = ((char)(dst << 7) | (v4 >> 1)) >> 3;
      v20 = v79;
      data[2] = (char)(4 * v19) >> 3;
      *data = 3;
      data[3] = ((char)(32 * v20) | (v19 >> 3)) >> 3;
      data[4] = v20 >> 3;
      break;
    case 9:
      v21 = dst;
      data[1] = ((char)(32 * dst) | (v4 >> 3)) >> 1;
      v22 = v79;
      data[2] = ((char)(v79 << 6) | (v21 >> 2)) >> 1;
      v23 = ((char)(v80 << 7) | (v22 >> 1)) >> 1;
      v24 = (char)v80 >> 1;
      *data = 3;
      data[3] = v23;
      data[4] = v24;
      break;
    case 0xA:
      v25 = dst;
      v26 = (v4 >> 4) | (2 * (char)(8 * dst));
      v27 = v79;
      data[1] = v26;
      v28 = (v25 >> 5) | (2 * (char)(4 * v27));
      v29 = v80;
      data[2] = v28;
      data[3] = (v27 >> 6) | (2 * (char)(2 * v29));
      v30 = (2 * (char)v81) | (v29 >> 7);
      *data = 3;
      data[4] = v30;
      break;
    case 0xB:
      v31 = dst;
      v32 = v79;
      v33 = (v4 >> 4) | (8 * (char)(2 * dst));
      v34 = v80;
      data[1] = v33;
      v35 = (v31 >> 7) | (2 * (v32 | (4 * (char)(v34 << 6))));
      v36 = v81;
      data[2] = v35;
      data[3] = (v34 >> 2) | (8 * (char)(8 * v36));
      v37 = (8 * (char)v82) | (v36 >> 5);
      *data = 3;
      data[4] = v37;
      break;
    case 0xC:
      v38 = v79;
      v39 = (v4 >> 4) | (16 * (dst | (2 * (char)(v79 << 7))));
      v40 = v80;
      data[1] = v39;
      v41 = v81;
      v42 = (v38 >> 1) | (32 * (char)(4 * v40));
      v43 = v82;
      data[2] = v42;
      data[3] = (v40 >> 6) | (4 * (v41 | (8 * (char)(32 * v43))));
      v44 = (32 * (char)v83) | (v43 >> 3);
      *data = 3;
      data[4] = v44;
      break;
    case 0xD:
      v45 = v79;
      v46 = v80;
      v47 = (v4 >> 4) | (16 * (dst | (8 * (char)(32 * v79))));
      v48 = v81;
      data[1] = v47;
      v49 = v46 | (4 * (char)(v48 << 6));
      v50 = v82;
      v51 = (v45 >> 3) | (32 * v49);
      v52 = v83;
      data[2] = v51;
      data[3] = (v48 >> 2) | ((v50 | (2 * (char)(v52 << 7))) << 6);
      v53 = ((char)v84 << 7) | (v52 >> 1);
      *data = 3;
      data[4] = v53;
      break;
    case 0xE:
      v54 = v79;
      v55 = v80;
      v56 = (v4 >> 4) | (16 * (dst | (32 * (char)(8 * v79))));
      v57 = v81;
      data[1] = v56;
      v58 = v55 | ((char)(4 * v57) << 6);
      v59 = v82;
      v60 = (v54 >> 5) | (8 * v58);
      v61 = v83;
      data[2] = v60;
      v62 = (v57 >> 6) | (4 * (v59 | ((char)(2 * v61) << 7)));
      v63 = v84;
      data[3] = v62;
      v64 = v63 | ((char)v85 << 8);
      *data = 3;
      v65 = v61 >> 7;
      goto LABEL_20;
    case 0xF:
      v66 = v79;
      v67 = v81;
      v68 = (v4 >> 4) | (16 * (dst | ((char)(2 * v79) << 7)));
      v69 = v82;
      data[1] = v68;
      v70 = v80 | ((v67 | (4 * (char)(v69 << 6))) << 8);
      v71 = v83;
      v72 = (v66 >> 7) | (2 * v70);
      v73 = v84;
      data[2] = v72;
      v74 = (v69 >> 2) | ((v71 | (32 * (char)(8 * v73))) << 6);
      v75 = v85;
      data[3] = v74;
      v64 = 4 * (v75 | (v86 << 8));
      *data = 3;
      v65 = v73 >> 5;
LABEL_20:
      data[4] = v65 | (2 * v64);
      break;
  }
  return v5 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10150600
// Name: public: virtual int GFxFont::GetCharValue(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFont::GetCharValue(GFxFont *this, unsigned int a2)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10150610
// Name: public: virtual class GString GFxFont::GetCharRanges(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxFont::GetCharRanges(GFxFont *this, GString *a2)
{
  GString::GString(this: a2, a2: (const char *)&pMem);
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10150660
// Name: public: class GFxTextureGlyph const __near & GFxTextureGlyph::operator=(class GFxTextureGlyph const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *__thiscall GFxTextureGlyph::operator=(
        int this,
        CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *result)
{
  IShaderDevice *m_Size; // ecx
  IShaderDevice *v5; // ecx
  VertexShaderHandle_t__ *v7; // [esp+0h] [ebp-10h]
  int m_nGrowSize; // [esp+8h] [ebp-8h]
  int m_nAllocationCount; // [esp+Ch] [ebp-4h]
  CMorph::MorphSegment_t *m_pMemory; // [esp+18h] [ebp+8h]
  CMorph::MorphSegment_t *m_pElements; // [esp+18h] [ebp+8h]

  if ( result->m_Memory.m_nGrowSize == 0 )
  {
    m_Size = (IShaderDevice *)result->m_Size;
    if ( m_Size != nullptr )
      GRefCountImpl::AddRef(this: m_Size, a2: v7);
  }
  if ( *(_DWORD *)(this + 8) == 0 )
  {
    v5 = *(IShaderDevice **)(this + 12);
    if ( v5 != nullptr )
      GFxResource::Release(this: v5);
  }
  *(_DWORD *)(this + 8) = result->m_Memory.m_nGrowSize;
  *(_DWORD *)(this + 12) = result->m_Size;
  m_pMemory = result[1].m_Memory.m_pMemory;
  m_nAllocationCount = result[1].m_Memory.m_nAllocationCount;
  m_nGrowSize = result[1].m_Memory.m_nGrowSize;
  *(float *)(this + 16) = *(float *)&result->m_pElements;
  *(float *)(this + 20) = *(float *)&m_pMemory;
  *(float *)(this + 24) = *(float *)&m_nAllocationCount;
  *(float *)(this + 28) = *(float *)&m_nGrowSize;
  m_pElements = result[1].m_pElements;
  *(float *)(this + 32) = *(float *)&result[1].m_Size;
  *(float *)(this + 36) = *(float *)&m_pElements;
  return (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)this;
}

//------------------------------------------------------------------------------
// Address: 0x101506F0
// Name: public: virtual class GRect<float> __near & GFxFontData::GetGlyphBounds(unsigned int,class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
const CMorph *__thiscall GFxFontData::GetGlyphBounds(_DWORD *this, unsigned int result, float *a3)
{
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  double v9; // st6
  int *v11; // eax
  int v12; // edx
  void (__thiscall *v13)(int *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *); // edx
  double v14; // st7
  double v15; // st6
  double v16; // st5
  double v17; // st4
  double v18; // rt1
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> bounds; // [esp+8h] [ebp-18h] BYREF
  float v20; // [esp+14h] [ebp-Ch]
  float h; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]
  float w; // [esp+28h] [ebp+8h]
  float v24; // [esp+2Ch] [ebp+Ch]
  float v25; // [esp+2Ch] [ebp+Ch]
  float v26; // [esp+2Ch] [ebp+Ch]
  float v27; // [esp+2Ch] [ebp+Ch]
  float v28; // [esp+2Ch] [ebp+Ch]

  if ( result == -1 )
  {
    a3[1] = 0.0;
    *a3 = 0.0;
    v24 = ((double (__thiscall *)(_DWORD *, int))*(_DWORD *)(*this + 40))(a1: this, a2: -1);
    a3[2] = *a3 + v24;
    v25 = ((double (__thiscall *)(_DWORD *, int))*(_DWORD *)(*this + 44))(a1: this, a2: -1);
    a3[3] = a3[1] + v25;
    return (const CMorph *)a3;
  }
  else if ( result >= *(this + 13) )
  {
    a3[1] = 0.0;
    *a3 = 0.0;
    v26 = 0.0 + 0.0;
    a3[2] = v26;
    a3[3] = v26;
    if ( result >= *(this + 9) )
      return (const CMorph *)a3;
    v11 = *(int **)(*(this + 8) + 4 * result);
    if ( v11 == nullptr )
      return (const CMorph *)a3;
    v12 = *v11;
    *(float *)&bounds.m_pMemory = 0.0;
    v13 = *(void (__thiscall **)(int *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(v12 + 20);
    *(float *)&bounds.m_nAllocationCount = 0.0;
    *(float *)&bounds.m_nGrowSize = 0.0;
    v20 = 0.0;
    v13(a1: v11, a2: &bounds);
    v14 = *(float *)&bounds.m_nGrowSize;
    v15 = *(float *)&bounds.m_pMemory;
    if ( *(float *)&bounds.m_pMemory > (double)*(float *)&bounds.m_nGrowSize )
      return (const CMorph *)a3;
    v16 = v20;
    v17 = *(float *)&bounds.m_nAllocationCount;
    if ( *(float *)&bounds.m_nAllocationCount <= (double)v20 )
    {
      v18 = *(float *)&bounds.m_nAllocationCount;
      *a3 = *(float *)&bounds.m_pMemory;
      a3[1] = v17;
      v27 = v14 - v15;
      a3[2] = v15 + v27;
      v28 = v16 - v18;
      a3[3] = v18 + v28;
      return (const CMorph *)a3;
    }
    else
    {
      return (const CMorph *)a3;
    }
  }
  else
  {
    v6 = *(this + 12);
    v7 = *(unsigned __int16 *)(v6 + 12 * result + 8);
    v8 = v6 + 12 * result;
    w = (double)v7 / 20.0;
    if ( 0.0 == w )
      w = *(float *)v8;
    v22 = *(unsigned __int16 *)(v8 + 10);
    v9 = (double)v22;
    v22 = *(__int16 *)(v8 + 4);
    h = v9 / 20.0;
    *a3 = (double)v22 / 20.0;
    a3[1] = (double)*(__int16 *)(v8 + 6) / 20.0;
    a3[2] = *a3 + w;
    a3[3] = a3[1] + h;
    return (const CMorph *)a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150870
// Name: public: virtual int GFxFontDataCompactedSwf::GetGlyphIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
CVertexMorphDict::MorphVertexList_t *__thiscall GFxFontDataCompactedSwf::GetGlyphIndex(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this,
        unsigned __int16 code)
{
  return (CVertexMorphDict::MorphVertexList_t *)GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphIndex(
                                                  this: (_DWORD *)this + 11,
                                                  code);
}

//------------------------------------------------------------------------------
// Address: 0x10150880
// Name: public: virtual int GFxFontDataCompactedSwf::GetCharValue(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontDataCompactedSwf::GetCharValue(_DWORD *this, unsigned int result)
{
  int v2; // edx

  if ( result >= *(this + 14) )
    return -1;
  v2 = *(this + 15);
  return *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(this + 13) + 12) + 4 * ((v2 + 8 * result) >> 12))
                            + ((v2 + 8 * result) & 0xFFF))
       | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(this + 13) + 12) + 4 * ((v2 + 8 * result + 1) >> 12))
                             + ((v2 + 8 * result + 1) & 0xFFF)) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x101508D0
// Name: public: virtual float GFxFontDataCompactedSwf::GetAdvance(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedSwf::GetAdvance(GFxFontDataCompactedSwf *this, unsigned int a2)
{
  unsigned int v2; // eax

  if ( a2 == -1 || a2 >= *((_DWORD *)this + 14) )
    return 512.0;
  v2 = *((_DWORD *)this + 15) + 8 * a2 + 2;
  return (float)((double)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13) + 12) + 4 * (v2 >> 12))
                                             + (v2 & 0xFFF))
                        | (unsigned int)(__int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13)
                                                                                             + 12)
                                                                                 + 4 * ((v2 + 1) >> 12))
                                                                     + ((v2 + 1) & 0xFFF)) << 8))
               * 1024.0
               / (double)*((unsigned int *)this + 22));
}

//------------------------------------------------------------------------------
// Address: 0x10150960
// Name: public: virtual float GFxFontDataCompactedSwf::GetKerningAdjustment(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedSwf::GetKerningAdjustment(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  return (float)(GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetKerningAdjustment(
                   this: (_DWORD *)this + 11,
                   lastCode,
                   thisCode)
               * 1024.0
               / (double)*((unsigned int *)this + 22));
}

//------------------------------------------------------------------------------
// Address: 0x101509A0
// Name: public: virtual char const __near * GFxFontDataCompactedSwf::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontDataCompactedSwf::GetName(CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101509B0
// Name: public: virtual void GFxFontDataCompactedSwf::SetTextureGlyphData(class GFxTextureGlyphData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontDataCompactedSwf::SetTextureGlyphData(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        int pdata)
{
  GRefCountNTSImpl *v3; // ecx

  if ( pdata != 0 )
    ++*(_DWORD *)(pdata + 4);
  v3 = *((GRefCountNTSImpl **)this + 6);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  *((_DWORD *)this + 6) = pdata;
}

//------------------------------------------------------------------------------
// Address: 0x101509E0
// Name: public: virtual int GFxFontDataCompactedGfx::GetGlyphIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
tagEXCEPINFO *__thiscall GFxFontDataCompactedGfx::GetGlyphIndex(void *this, tagCLIPDATA *result)
{
  return (tagEXCEPINFO *)GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphIndex(
                           this: (int)this + 40,
                           result);
}

//------------------------------------------------------------------------------
// Address: 0x101509F0
// Name: public: virtual int GFxFontDataCompactedGfx::GetCharValue(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontDataCompactedGfx::GetCharValue(GFxFontDataCompactedGfx *this, unsigned int a2)
{
  if ( a2 >= *((_DWORD *)this + 13) )
    return -1;
  else
    return *(unsigned __int16 *)(*((_DWORD *)this + 14) + 8 * a2 + **((_DWORD **)this + 12));
}

//------------------------------------------------------------------------------
// Address: 0x10150A20
// Name: public: virtual float GFxFontDataCompactedGfx::GetAdvance(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedGfx::GetAdvance(GFxFontDataCompactedGfx *this, unsigned int a2)
{
  unsigned __int8 *v3; // eax

  if ( a2 == -1 )
    return 512.0;
  v3 = (unsigned __int8 *)(**((_DWORD **)this + 12) + *((_DWORD *)this + 14) + 8 * a2 + 2);
  return (float)((double)(*v3 | (unsigned int)(__int16)(v3[1] << 8)) * 1024.0 / (double)*((unsigned int *)this + 21));
}

//------------------------------------------------------------------------------
// Address: 0x10150A90
// Name: public: virtual float GFxFontDataCompactedGfx::GetKerningAdjustment(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedGfx::GetKerningAdjustment(
        GFxFontDataCompactedGfx *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  return (float)(GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetKerningAdjustment(
                   this: (int)this + 40,
                   lastCode,
                   thisCode)
               * 1024.0
               / (double)*((unsigned int *)this + 21));
}

//------------------------------------------------------------------------------
// Address: 0x10150AD0
// Name: public: GFxFontResource::GFxFontResource(class GFxFont __near *,class GFxResourceBinding __near *)
// Source: json
//------------------------------------------------------------------------------
GFxFontResource *__thiscall GFxFontResource::GFxFontResource(
        GFxFontResource *this,
        IShaderDevice *a2,
        _RATE_QUOTA_LIMIT *pbinding)
{
  IShaderAPI *v4; // ecx
  int v5; // edi
  GRefCountNTSImpl *v6; // ecx
  VertexShaderHandle_t__ *v8; // [esp+0h] [ebp-Ch]

  this->cElems = (unsigned int)&GFxResource::`vftable';
  this->pElems = (__int16 *)1;
  *((_DWORD *)this + 2) = 0;
  this->cElems = (unsigned int)&GFxFontResource::`vftable';
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = pbinding;
  GFxResourceKey::GFxResourceKey(this: (GFxValue *)(this + 3));
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v8);
  v4 = *((IShaderAPI **)this + 3);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *((_DWORD *)this + 3) = a2;
  if ( a2 != nullptr )
    v5 = ((int (__thiscall *)(IShaderDevice *))a2->ReacquireResources)(a1: a2);
  else
    v5 = 0;
  if ( v5 != 0 )
    ++*(_DWORD *)(v5 + 4);
  v6 = *((GRefCountNTSImpl **)this + 4);
  if ( v6 != nullptr )
    GRefCountNTSImpl::Release(this: v6);
  *((_DWORD *)this + 4) = v5;
  *((_BYTE *)this + 32) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10150B90
// Name: public: GFxFontResource::GFxFontResource(class GFxFont __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxFontResource *__thiscall GFxFontResource::GFxFontResource(
        GFxFontResource *this,
        IShaderDevice *a2,
        IShaderDevice *src)
{
  IShaderAPI *v4; // ecx
  int v5; // edi
  GRefCountNTSImpl *v6; // ecx
  VertexShaderHandle_t__ *v8; // [esp+0h] [ebp-Ch]

  this->cElems = (unsigned int)&GFxResource::`vftable';
  this->pElems = (__int16 *)1;
  *((_DWORD *)this + 2) = 0;
  this->cElems = (unsigned int)&GFxFontResource::`vftable';
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  GFxResourceKey::GFxResourceKey(this: (GFxValue *)(this + 3));
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v8);
  v4 = *((IShaderAPI **)this + 3);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *((_DWORD *)this + 3) = a2;
  if ( a2 != nullptr )
    v5 = ((int (__thiscall *)(IShaderDevice *))a2->ReacquireResources)(a1: a2);
  else
    v5 = 0;
  if ( v5 != 0 )
    ++*(_DWORD *)(v5 + 4);
  v6 = *((GRefCountNTSImpl **)this + 4);
  if ( v6 != nullptr )
    GRefCountNTSImpl::Release(this: v6);
  *((_DWORD *)this + 4) = v5;
  *((_BYTE *)this + 32) = 0;
  *((_DWORD *)this + 9) = 0;
  GFxResourceKey::operator=(this: (IShaderDevice *)this + 6, src);
  *((_DWORD *)this + 10) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10150C30
// Name: private: unsigned short GFxFontResource::calcTopBound(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge GFxFontResource::calcTopBound@<ax>(GFxFontResource *this@<ecx>, int a2@<esi>, int a3)
{
  int v4; // eax

  v4 = (*(int (__thiscall **)(_DWORD, int, int))(**((_DWORD **)this + 3) + 12))(
         a1: *((_DWORD *)this + 3),
         a2: a3,
         a3: a2);
  if ( v4 == -1 )
    return 0;
  (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 3) + 48))(a1: *((_DWORD *)this + 3), a2: v4);
  return (int)-(float)0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10150CA0
// Name: private: void GFxFontResource::calcLowerUpperTop(class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontResource::calcLowerUpperTop(ISequentialStream *this, const ISequentialStream *log)
{
  const ISequentialStream *v2; // ebx
  unsigned __int8 v4; // al
  float *v5; // edi
  _BYTE *v6; // ecx
  const char *v7; // edx
  const char *v8; // eax
  int v9; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // ecx
  __int16 v11; // dx
  unsigned __int8 v12; // al
  char *v13; // edi
  int v14; // ecx
  int v15; // eax
  __int16 v16; // ax
  unsigned __int16 upperCaseTop; // [esp+Ch] [ebp-2Ch]
  char v18[8]; // [esp+1Ch] [ebp-1Ch] BYREF
  float v19; // [esp+24h] [ebp-14h] BYREF
  float v20[3]; // [esp+28h] [ebp-10h] BYREF

  v2 = log;
  if ( *((_DWORD *)this + 3) == 0 )
    goto LABEL_7;
  if ( *((_WORD *)this + 20) != 0 )
    goto LABEL_7;
  if ( *((_WORD *)this + 21) != 0 )
    goto LABEL_7;
  strcpy((char *)v20, "HEFTUVWXZ");
  strcpy(v18, "zxvwy");
  v4 = aHeft[0];
  v5 = v20;
  if ( aHeft[0] == 0 )
    goto LABEL_7;
  while ( 1 )
  {
    upperCaseTop = GFxFontResource::calcTopBound((GFxFontResource *)this, a2: (int)this, a3: v4);
    if ( upperCaseTop != 0 )
      break;
    v4 = *((_BYTE *)v5 + 1);
    v5 = (float *)((char *)v5 + 1);
    if ( v4 == 0 )
      goto LABEL_7;
  }
  v12 = v18[0];
  v13 = v18;
  if ( v18[0] != 0 )
  {
    while ( 1 )
    {
      v14 = *((_DWORD *)this + 3);
      v19 = 0.0;
      v20[0] = 0.0;
      v20[1] = 0.0;
      v20[2] = 0.0;
      v15 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v14 + 12))(a1: v14, a2: v12);
      if ( v15 != -1 )
      {
        (*(void (__thiscall **)(_DWORD, int, float *))(**((_DWORD **)this + 3) + 48))(
          a1: *((_DWORD *)this + 3),
          a2: v15,
          a3: &v19);
        v16 = (int)-v20[0];
        if ( v16 != 0 )
          break;
      }
      v12 = *++v13;
      if ( v12 == 0 )
      {
        v2 = log;
        goto LABEL_7;
      }
    }
    v11 = upperCaseTop;
    *((_WORD *)this + 20) = v16;
  }
  else
  {
LABEL_7:
    if ( v2 != nullptr )
    {
      v6 = *((_BYTE **)this + 3);
      v7 = " Italic";
      if ( (v6[20] & 1) == 0 )
        v7 = (const char *)&pMem;
      v8 = " Bold";
      if ( (*((_DWORD *)v6 + 5) & 2) == 0 )
        v8 = (const char *)&pMem;
      v9 = (*(int (__thiscall **)(_BYTE *, const char *, const char *))(*(_DWORD *)v6 + 60))(a1: v6, a2: v8, a3: v7);
      GFxLogBase<GFxLog>::LogWarning(
        this: v10,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v2[3],
        this_4: (int)"Warning: Font '%s%s%s': No hinting chars (any of 'HEFTUVWXZ' and 'zxvwy'). Auto-Hinting is disabled\n",
        this_8: v9);
    }
    *((_WORD *)this + 20) = -1;
    v11 = -1;
  }
  *((_WORD *)this + 21) = v11;
}

//------------------------------------------------------------------------------
// Address: 0x10150EE0
// Name: public: unsigned int GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::AcquireFont(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::AcquireFont(
        int this,
        unsigned int startPos)
{
  _DWORD *v3; // eax
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  void *v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // edi
  int v15; // eax
  unsigned int i; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD **)(this + 8);
  if ( *v3 < startPos + 15 )
    return 0;
  v5 = *(_BYTE *)((startPos & 0xFFF) + *(_DWORD *)(v3[3] + 4 * (startPos >> 12))) == 0;
  i = 0;
  if ( !v5 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(this + 8) + 12);
    v7 = startPos;
    do
    {
      ++i;
      ++v7;
    }
    while ( *(_BYTE *)((v7 & 0xFFF) + *(_DWORD *)(v6 + 4 * (v7 >> 12))) != 0 );
  }
  v8 = i + 1;
  if ( i + 1 > *(_DWORD *)(this + 36) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 28));
    *(_DWORD *)(this + 36) = v8;
    if ( v8 != 0 )
    {
      i = 2;
      v9 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v8, a3: &i);
    }
    else
    {
      v9 = nullptr;
    }
    *(_DWORD *)(this + 28) = v9;
  }
  v10 = 0;
  for ( *(_DWORD *)(this + 32) = v8; v10 < *(_DWORD *)(this + 32); ++v10 )
    *(_BYTE *)(v10 + *(_DWORD *)(this + 28)) = *(_BYTE *)(((v10 + startPos) & 0xFFF)
                                                        + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12)
                                                                    + 4 * ((v10 + startPos) >> 12)));
  v11 = startPos + *(_DWORD *)(this + 32);
  *(_DWORD *)(this + 40) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * (v11 >> 12))
                                              + (((_WORD)startPos + *(_WORD *)(this + 32)) & 0xFFF))
                         | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12)
                                                           + 4 * ((v11 + 1) >> 12))
                                               + ((v11 + 1) & 0xFFF)) << 8);
  *(_DWORD *)(this + 44) = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12)
                                                          + 4 * ((v11 + 2) >> 12))
                                              + (((_WORD)v11 + 2) & 0xFFF))
                         | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12)
                                                           + 4 * ((v11 + 3) >> 12))
                                               + ((v11 + 3) & 0xFFF)) << 8);
  i = (__int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 4) >> 12))
                                   + (((_WORD)v11 + 4) & 0xFFF))
              | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 5) >> 12))
                                    + ((v11 + 5) & 0xFFF)) << 8));
  *(float *)(this + 48) = (float)(int)i;
  i = (__int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 6) >> 12))
                                   + (((_WORD)v11 + 6) & 0xFFF))
              | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 7) >> 12))
                                    + ((v11 + 7) & 0xFFF)) << 8));
  *(float *)(this + 52) = (float)(int)i;
  i = (__int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 8) >> 12))
                                   + (((_WORD)v11 + 8) & 0xFFF))
              | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 9) >> 12))
                                    + ((v11 + 9) & 0xFFF)) << 8));
  *(float *)(this + 56) = (float)(int)i;
  i = *(_DWORD *)(*(_DWORD *)(this + 8) + 12);
  *(_DWORD *)(this + 12) = *(unsigned __int8 *)(*(_DWORD *)(i + 4 * ((v11 + 10) >> 12)) + (((_WORD)v11 + 10) & 0xFFF))
                         | ((*(unsigned __int8 *)(*(_DWORD *)(i + 4 * ((v11 + 11) >> 12)) + ((v11 + 11) & 0xFFF))
                           | ((*(unsigned __int8 *)(*(_DWORD *)(i + 4 * ((v11 + 12) >> 12)) + ((v11 + 12) & 0xFFF))
                             | (*(unsigned __int8 *)(*(_DWORD *)(i + 4 * ((v11 + 13) >> 12)) + ((v11 + 13) & 0xFFF)) << 8)) << 8)) << 8);
  i = *(_DWORD *)(*(_DWORD *)(this + 8) + 12);
  v12 = v11
      + (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 14) >> 12))
                            + (((_WORD)v11 + 14) & 0xFFF))
       | ((*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 12) + 4 * ((v11 + 15) >> 12))
                              + ((v11 + 15) & 0xFFF))
         | ((*(unsigned __int8 *)(*(_DWORD *)(i + 4 * ((v11 + 16) >> 12)) + ((v11 + 16) & 0xFFF))
           | (*(unsigned __int8 *)(*(_DWORD *)(i + 4 * ((v11 + 17) >> 12)) + ((v11 + 17) & 0xFFF)) << 8)) << 8)) << 8))
      + 18;
  v13 = v12 + 8 * *(_DWORD *)(this + 12);
  *(_DWORD *)(this + 16) = v12;
  v14 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
          this: (int *)(this + 8),
          a2: v13,
          a3: (int *)(this + 20))
      + v13;
  v15 = 6 * *(_DWORD *)(this + 20) - startPos;
  *(_DWORD *)(this + 24) = v14;
  return v14 + v15;
}

//------------------------------------------------------------------------------
// Address: 0x10151240
// Name: public: float GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphWidth(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphWidth(
        _DWORD *this,
        unsigned int glyphIndex)
{
  int v2; // edx
  int v3; // ecx
  __int16 v4; // si
  __int16 v5; // cx
  int v7; // [esp+Ch] [ebp-2Ch] BYREF
  __int16 v8; // [esp+14h] [ebp-24h]
  __int16 v9; // [esp+16h] [ebp-22h]
  __int16 v10; // [esp+18h] [ebp-20h]
  __int16 v11; // [esp+1Ah] [ebp-1Eh]
  int v12; // [esp+34h] [ebp-4h]
  unsigned int glyphIndexa; // [esp+40h] [ebp+8h]

  v2 = *(this + 4);
  v7 = *(this + 2);
  glyphIndexa = v2 + 8 * glyphIndex;
  v12 = v7;
  v3 = *(_DWORD *)(v7 + 12);
  GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    this: &v7,
    a2: *(unsigned __int8 *)(*(_DWORD *)(v3 + 4 * ((glyphIndexa + 4) >> 12)) + ((glyphIndexa + 4) & 0xFFF))
  | ((*(unsigned __int8 *)(*(_DWORD *)(v3 + 4 * ((glyphIndexa + 5) >> 12)) + ((glyphIndexa + 5) & 0xFFF))
    | ((*(unsigned __int8 *)(*(_DWORD *)(v3 + 4 * ((glyphIndexa + 6) >> 12)) + ((glyphIndexa + 6) & 0xFFF))
      | (*(unsigned __int8 *)(*(_DWORD *)(v3 + 4 * ((glyphIndexa + 7) >> 12)) + ((glyphIndexa + 7) & 0xFFF)) << 8)) << 8)) << 8));
  v4 = v8;
  v5 = v10;
  if ( v8 >= v10 || v9 >= v11 )
  {
    v4 = 0;
    v5 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v12 + 12) + 4 * ((glyphIndexa + 2) >> 12))
                            + ((glyphIndexa + 2) & 0xFFF))
       | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v12 + 12) + 4 * ((glyphIndexa + 3) >> 12))
                             + ((glyphIndexa + 3) & 0xFFF)) << 8);
  }
  return (double)(v5 - v4);
}

//------------------------------------------------------------------------------
// Address: 0x10151340
// Name: public: float GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphHeight(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphHeight(
        _DWORD *this,
        unsigned int glyphIndex)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  __int16 v5; // cx
  __int16 v6; // ax
  int v8; // [esp+Ch] [ebp-28h] BYREF
  __int16 v9; // [esp+14h] [ebp-20h]
  __int16 v10; // [esp+16h] [ebp-1Eh]
  __int16 v11; // [esp+18h] [ebp-1Ch]
  __int16 v12; // [esp+1Ah] [ebp-1Ah]

  v2 = *(this + 2);
  v3 = *(this + 4);
  v4 = *(_DWORD *)(v2 + 12);
  v8 = v2;
  GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    this: &v8,
    a2: *(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v3 + 8 * glyphIndex + 4) >> 12)) + ((v3 + 8 * glyphIndex + 4) & 0xFFF))
  | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v3 + 8 * glyphIndex + 5) >> 12)) + ((v3 + 8 * glyphIndex + 5) & 0xFFF))
    | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v3 + 8 * glyphIndex + 6) >> 12))
                           + ((v3 + 8 * glyphIndex + 6) & 0xFFF))
      | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v3 + 8 * glyphIndex + 7) >> 12))
                            + ((v3 + 8 * glyphIndex + 7) & 0xFFF)) << 8)) << 8)) << 8));
  if ( v9 >= v11 || (v5 = v10, v6 = v12, v10 >= v12) )
  {
    v6 = 0;
    v5 = 0;
  }
  return (double)(v6 - v5);
}

//------------------------------------------------------------------------------
// Address: 0x10151400
// Name: public: unsigned int GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::AcquireFont(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::AcquireFont(int this, int a2)
{
  _DWORD *v3; // eax
  int v5; // ecx
  _BYTE *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  void *v9; // eax
  unsigned int i; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // ebx
  int v17; // eax
  int v18; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v19; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD **)(this + 8);
  if ( v3[1] < (unsigned int)(a2 + 15) )
    return 0;
  v5 = 0;
  if ( *(_BYTE *)(a2 + *v3) != 0 )
  {
    v6 = (_BYTE *)(a2 + *v3);
    do
    {
      ++v6;
      ++v5;
    }
    while ( *v6 != 0 );
  }
  v7 = v5 + 1;
  v19 = v5 + 1;
  if ( (unsigned int)(v5 + 1) > *(_DWORD *)(this + 36) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 28));
    v8 = v19;
    *(_DWORD *)(this + 36) = v19;
    if ( v8 != 0 )
    {
      v18 = 2;
      v9 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v8, a3: &v18);
    }
    else
    {
      v9 = nullptr;
    }
    *(_DWORD *)(this + 28) = v9;
    v7 = v19;
  }
  *(_DWORD *)(this + 32) = v7;
  for ( i = 0; i < *(_DWORD *)(this + 32); ++i )
    *(_BYTE *)(i + *(_DWORD *)(this + 28)) = *(_BYTE *)(i + **(_DWORD **)(this + 8) + a2);
  v11 = a2 + *(_DWORD *)(this + 32);
  *(_DWORD *)(this + 40) = *(unsigned __int16 *)(**(_DWORD **)(this + 8) + v11);
  *(_DWORD *)(this + 44) = *(unsigned __int16 *)(**(_DWORD **)(this + 8) + v11 + 2);
  v18 = *(__int16 *)(**(_DWORD **)(this + 8) + v11 + 4);
  v11 += 10;
  *(float *)(this + 48) = (float)v18;
  v18 = *(__int16 *)(**(_DWORD **)(this + 8) + v11 - 4);
  *(float *)(this + 52) = (float)v18;
  v18 = *(__int16 *)(**(_DWORD **)(this + 8) + v11 - 2);
  *(float *)(this + 56) = (float)v18;
  v12 = **(_DWORD **)(this + 8);
  *(_DWORD *)(this + 12) = *(unsigned __int8 *)(v11 + v12)
                         | ((*(unsigned __int8 *)(v11 + v12 + 1)
                           | ((*(unsigned __int8 *)(v12 + v11 + 2) | (*(unsigned __int8 *)(v12 + v11 + 3) << 8)) << 8)) << 8);
  v13 = **(_DWORD **)(this + 8);
  v11 += 4;
  v14 = v11
      + (*(unsigned __int8 *)(v11 + v13)
       | ((*(unsigned __int8 *)(v11 + v13 + 1)
         | ((*(unsigned __int8 *)(v13 + v11 + 2) | (*(unsigned __int8 *)(v13 + v11 + 3) << 8)) << 8)) << 8))
      + 4;
  v15 = *(_DWORD *)(this + 12);
  *(_DWORD *)(this + 16) = v14;
  v18 = this + 20;
  v16 = GFxPathDataDecoder<GArrayUnsafeLH_POD<unsigned char,261>>::ReadUInt30(
          this: (_DWORD **)(this + 8),
          pos: v14 + 8 * v15,
          v: (unsigned int *)(this + 20))
      + v14
      + 8 * v15;
  v17 = 6 * *(_DWORD *)v18 - a2;
  *(_DWORD *)(this + 24) = v16;
  return v16 + v17;
}

//------------------------------------------------------------------------------
// Address: 0x101515D0
// Name: public: float GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphWidth(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphWidth(
        int **this,
        unsigned int glyphIndex)
{
  int v2; // edx
  int v3; // esi
  int v4; // edi
  __int16 v5; // cx
  __int16 v6; // ax
  int *v8; // [esp+8h] [ebp-28h] BYREF
  __int16 v9; // [esp+10h] [ebp-20h]
  __int16 v10; // [esp+12h] [ebp-1Eh]
  __int16 v11; // [esp+14h] [ebp-1Ch]
  __int16 v12; // [esp+16h] [ebp-1Ah]

  v2 = (int)*(this + 4);
  v8 = *(this + 2);
  v3 = v2 + 8 * glyphIndex;
  v4 = *v8;
  GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    this: &v8,
    a2: *(unsigned __int8 *)(*v8 + v3 + 4)
  | ((*(unsigned __int8 *)(*v8 + v3 + 5) | (*(unsigned __int16 *)(*v8 + v3 + 6) << 8)) << 8));
  v5 = v9;
  v6 = v11;
  if ( v9 >= v11 || v10 >= v12 )
  {
    v5 = 0;
    v6 = *(_WORD *)(v4 + v3 + 2);
  }
  return (double)(v6 - v5);
}

//------------------------------------------------------------------------------
// Address: 0x10151660
// Name: public: float GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphHeight(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphHeight(
        _DWORD *this,
        unsigned int glyphIndex)
{
  int v2; // edx
  unsigned __int8 *v3; // eax
  __int16 v4; // cx
  __int16 v5; // ax
  _DWORD *v7; // [esp+0h] [ebp-28h] BYREF
  __int16 v8; // [esp+8h] [ebp-20h]
  __int16 v9; // [esp+Ah] [ebp-1Eh]
  __int16 v10; // [esp+Ch] [ebp-1Ch]
  __int16 v11; // [esp+Eh] [ebp-1Ah]

  v2 = *(this + 4);
  v7 = (_DWORD *)*(this + 2);
  v3 = (unsigned __int8 *)(*v7 + v2 + 8 * glyphIndex + 4);
  GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    this: &v7,
    a2: *v3 | ((v3[1] | (*((unsigned __int16 *)v3 + 1) << 8)) << 8));
  if ( v8 >= v10 || (v4 = v9, v5 = v11, v9 >= v11) )
  {
    v5 = 0;
    v4 = 0;
  }
  return (double)(v5 - v4);
}

//------------------------------------------------------------------------------
// Address: 0x101516E0
// Name: public: class GRect<float> __near & GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphBounds(unsigned int,class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphBounds(
        _DWORD *this,
        unsigned int glyphIndex,
        float *a3)
{
  int v3; // edx
  int v4; // ecx
  __int16 v5; // si
  __int16 v6; // cx
  __int16 v7; // di
  int v9; // [esp+Ch] [ebp-3Ch] BYREF
  __int16 v10; // [esp+14h] [ebp-34h]
  __int16 v11; // [esp+16h] [ebp-32h]
  __int16 v12; // [esp+18h] [ebp-30h]
  __int16 v13; // [esp+1Ah] [ebp-2Eh]
  float v14; // [esp+34h] [ebp-14h]
  float v15; // [esp+38h] [ebp-10h]
  float v16; // [esp+3Ch] [ebp-Ch]
  float v17; // [esp+40h] [ebp-8h]
  int v18; // [esp+44h] [ebp-4h]
  unsigned int glyphIndexa; // [esp+50h] [ebp+8h]

  v3 = *(this + 4);
  v9 = *(this + 2);
  glyphIndexa = v3 + 8 * glyphIndex;
  v18 = v9;
  v4 = *(_DWORD *)(v9 + 12);
  GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    this: &v9,
    a2: *(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((glyphIndexa + 4) >> 12)) + ((glyphIndexa + 4) & 0xFFF))
  | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((glyphIndexa + 5) >> 12)) + ((glyphIndexa + 5) & 0xFFF))
    | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((glyphIndexa + 6) >> 12)) + ((glyphIndexa + 6) & 0xFFF))
      | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((glyphIndexa + 7) >> 12)) + ((glyphIndexa + 7) & 0xFFF)) << 8)) << 8)) << 8));
  v5 = v10;
  v6 = v12;
  if ( v10 >= v12 || (v7 = v13, v11 >= v13) )
  {
    v11 = 0;
    v7 = 0;
    v5 = 0;
    v6 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v18 + 12) + 4 * ((glyphIndexa + 2) >> 12))
                            + ((glyphIndexa + 2) & 0xFFF))
       | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(v18 + 12) + 4 * ((glyphIndexa + 3) >> 12))
                             + ((glyphIndexa + 3) & 0xFFF)) << 8);
  }
  v14 = (float)v5;
  v15 = (float)v11;
  v16 = (float)v6;
  v17 = (float)v7;
  *a3 = v14;
  a3[1] = v15;
  a3[2] = v16;
  a3[3] = v17;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10151820
// Name: public: void GFxCompactedFont<class GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphShape(unsigned int,class GFxGlyphPathIterator<class GArrayPagedLH_POD<unsigned char,12,256,261>> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphShape(
        _DWORD *this,
        unsigned int result,
        IUnknown *glyph)
{
  int v3; // eax
  int v4; // ecx
  unsigned int v5; // eax

  v3 = *(this + 4);
  v4 = *(_DWORD *)(*(this + 2) + 12);
  v5 = v3 + 8 * result + 4;
  GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::StartGlyph(
    this: glyph,
    a2: *(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * (v5 >> 12)) + (v5 & 0xFFF))
  | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v5 + 1) >> 12)) + ((v5 + 1) & 0xFFF))
    | ((*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v5 + 2) >> 12)) + ((v5 + 2) & 0xFFF))
      | (*(unsigned __int8 *)(*(_DWORD *)(v4 + 4 * ((v5 + 3) >> 12)) + ((v5 + 3) & 0xFFF)) << 8)) << 8)) << 8));
}

//------------------------------------------------------------------------------
// Address: 0x101518B0
// Name: public: void GFxGlyphPathIterator<class GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(int this, int *data)
{
  int v3; // eax
  int result; // eax

  *(_DWORD *)(this + 32) += GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(
                              (void *)this,
                              pos: *(_DWORD *)(this + 32),
                              data);
  switch ( *data )
  {
    case 0:
      *(_DWORD *)(this + 16) += data[1];
      goto LABEL_3;
    case 1:
      *(_DWORD *)(this + 20) += data[1];
LABEL_3:
      *data = 2;
      data[1] = *(_DWORD *)(this + 16);
      data[2] = *(_DWORD *)(this + 20);
      break;
    case 2:
      *(_DWORD *)(this + 16) += data[1];
      *(_DWORD *)(this + 20) += data[2];
      data[1] = *(_DWORD *)(this + 16);
      data[2] = *(_DWORD *)(this + 20);
      break;
    case 3:
      *(_DWORD *)(this + 16) += data[1];
      *(_DWORD *)(this + 20) += data[2];
      v3 = data[3];
      data[1] = *(_DWORD *)(this + 16);
      data[2] = *(_DWORD *)(this + 20);
      *(_DWORD *)(this + 16) += v3;
      *(_DWORD *)(this + 20) += data[4];
      data[3] = *(_DWORD *)(this + 16);
      data[4] = *(_DWORD *)(this + 20);
      break;
    default:
      break;
  }
  result = *(_DWORD *)(this + 28);
  if ( result != 0 )
    *(_DWORD *)(this + 28) = --result;
  if ( *(_DWORD *)(this + 28) == 0 && *(_BYTE *)(this + 36) != 0 )
    *(_DWORD *)(this + 4) = *(_DWORD *)(this + 32);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10151980
// Name: public: class GRect<float> __near & GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphBounds(unsigned int,class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
IStream *__thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphBounds(
        int **this,
        unsigned int result,
        float *a3)
{
  int v3; // edx
  int v4; // esi
  int v5; // edi
  __int16 v6; // cx
  __int16 v7; // ax
  __int16 v8; // bx
  __int16 v9; // dx
  int *v11; // [esp+Ch] [ebp-38h] BYREF
  __int16 v12; // [esp+14h] [ebp-30h]
  __int16 v13; // [esp+16h] [ebp-2Eh]
  __int16 v14; // [esp+18h] [ebp-2Ch]
  __int16 v15; // [esp+1Ah] [ebp-2Ah]
  float v16; // [esp+34h] [ebp-10h]
  float v17; // [esp+38h] [ebp-Ch]
  float v18; // [esp+3Ch] [ebp-8h]
  float v19; // [esp+40h] [ebp-4h]
  signed int glyphIndex; // [esp+4Ch] [ebp+8h]

  v3 = (int)*(this + 4);
  v11 = *(this + 2);
  v4 = v3 + 8 * result;
  v5 = *v11;
  GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    this: &v11,
    a2: *(unsigned __int8 *)(*v11 + v4 + 4)
  | ((*(unsigned __int8 *)(*v11 + v4 + 5) | (*(unsigned __int16 *)(*v11 + v4 + 6) << 8)) << 8));
  v6 = v12;
  v7 = v14;
  if ( v12 >= v14 || (v8 = v13, v9 = v15, v13 >= v15) )
  {
    v9 = 0;
    v8 = 0;
    v6 = 0;
    v7 = *(_WORD *)(v5 + v4 + 2);
  }
  v16 = (float)v6;
  glyphIndex = v7;
  v17 = (float)v8;
  v18 = (float)glyphIndex;
  v19 = (float)v9;
  *a3 = v16;
  a3[1] = v17;
  a3[2] = v18;
  a3[3] = v19;
  return (IStream *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x10151A50
// Name: public: void GFxCompactedFont<class GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphShape(unsigned int,class GFxGlyphPathIterator<class GArrayUnsafeLH_POD<unsigned char,261>> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphShape(
        int this,
        unsigned int glyphIndex,
        IStorage glyph)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // ecx
  unsigned int v5; // eax

  v3 = (unsigned __int8 *)(**(_DWORD **)(this + 8) + *(_DWORD *)(this + 16) + 8 * glyphIndex + 4);
  GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    this: glyph.__vftable,
    a2: *v3 | ((v3[1] | (*((unsigned __int16 *)v3 + 1) << 8)) << 8));
  v4 = (unsigned __int8 *)glyph.AddRef + *(_DWORD *)glyph.QueryInterface;
  v5 = *v4;
  if ( (v5 & 1) != 0 )
  {
    glyph.OpenStorage = (HRESULT (__stdcall *)(IStorage *, const wchar_t *, IStorage *, unsigned int, wchar_t **, unsigned int, IStorage **))((v5 >> 1) | (v4[1] << 7));
    glyph.AddRef = (unsigned int (__stdcall *)(IUnknown *))((char *)glyph.AddRef + 2);
  }
  else
  {
    glyph.OpenStorage = (HRESULT (__stdcall *)(IStorage *, const wchar_t *, IStorage *, unsigned int, wchar_t **, unsigned int, IStorage **))(v5 >> 1);
    ++glyph.AddRef;
  }
  GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(this: (int)glyph.__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x10151AE0
// Name: public: void GFxGlyphPathIterator<class GArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(int this, int *data)
{
  int v3; // eax
  int result; // eax

  *(_DWORD *)(this + 32) += GFxPathDataDecoder<GArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(
                              (_DWORD **)this,
                              pos: *(_DWORD *)(this + 32),
                              data);
  switch ( *data )
  {
    case 0:
      *(_DWORD *)(this + 16) += data[1];
      goto LABEL_3;
    case 1:
      *(_DWORD *)(this + 20) += data[1];
LABEL_3:
      *data = 2;
      data[1] = *(_DWORD *)(this + 16);
      data[2] = *(_DWORD *)(this + 20);
      break;
    case 2:
      *(_DWORD *)(this + 16) += data[1];
      *(_DWORD *)(this + 20) += data[2];
      data[1] = *(_DWORD *)(this + 16);
      data[2] = *(_DWORD *)(this + 20);
      break;
    case 3:
      *(_DWORD *)(this + 16) += data[1];
      *(_DWORD *)(this + 20) += data[2];
      v3 = data[3];
      data[1] = *(_DWORD *)(this + 16);
      data[2] = *(_DWORD *)(this + 20);
      *(_DWORD *)(this + 16) += v3;
      *(_DWORD *)(this + 20) += data[4];
      data[3] = *(_DWORD *)(this + 16);
      data[4] = *(_DWORD *)(this + 20);
      break;
    default:
      break;
  }
  result = *(_DWORD *)(this + 28);
  if ( result != 0 )
    *(_DWORD *)(this + 28) = --result;
  if ( *(_DWORD *)(this + 28) == 0 && *(_BYTE *)(this + 36) != 0 )
    *(_DWORD *)(this + 4) = *(_DWORD *)(this + 32);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10151D90
// Name: public: class GImageInfoBase __near * GFxTextureGlyph::GetImageInfo(class GFxResourceBinding const __near *)const
// Source: json
//------------------------------------------------------------------------------
GFxResource_vtbl *__thiscall GFxTextureGlyph::GetImageInfo(
        CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *this,
        const struct GFxResourceBinding *pbinding)
{
  struct GFxResource *Resource; // eax

  Resource = GFxResourceHandle::GetResource(this: (GFxResourceHandle *)&this->m_Memory.m_nGrowSize, a2: pbinding);
  if ( Resource != nullptr )
    return Resource[1].__vftable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10151DB0
// Name: public: class GFxTextureGlyph const __near & GFxTextureGlyphData::GetTextureGlyph(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
GLock *__thiscall GFxTextureGlyphData::GetTextureGlyph(GFxTextureGlyphData *this, unsigned int a2)
{
  if ( a2 < *((_DWORD *)this + 9) )
    return (GLock *)(*((_DWORD *)this + 8) + 40 * a2);
  if ( (_S3_2 & 1) == 0 )
  {
    _S3_2 |= 1u;
    *(float *)&GFxRectangle_NaNParams.HeapLock.cs.LockSemaphore = 0.0;
    *(float *)&GFxRectangle_NaNParams.HeapLock.cs.SpinCount = 0.0;
    GFxRectangle_NaNParams.HeapLock.cs.LockCount = 1;
    *(float *)&GFxRectangle_NaNParams.UseLocks = 0.0;
    flt_103598D0 = 0.0;
    GFxRectangle_NaNParams.HeapLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&GFxTextureGlyph::`vftable';
    GFxRectangle_NaNParams.HeapLock.cs.RecursionCount = 0;
    GFxRectangle_NaNParams.HeapLock.cs.OwningThread = nullptr;
    atexit(func: (void (__cdecl *)())GFxTextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__);
  }
  return &GFxRectangle_NaNParams.HeapLock;
}

//------------------------------------------------------------------------------
// Address: 0x10151E30
// Name: public: virtual bool GFxFontDataCompactedGfx::IsHintedVectorGlyph(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char __stdcall GFxFontDataCompactedGfx::IsHintedVectorGlyph(
        CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result,
        unsigned int psc)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10151E40
// Name: public: virtual float GFxFontDataCompactedSwf::GetGlyphWidth(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedSwf::GetGlyphWidth(GFxFontDataCompactedSwf *this, unsigned int glyphIndex)
{
  unsigned int v2; // esi

  if ( glyphIndex == -1 || glyphIndex >= *((_DWORD *)this + 14) )
    return 512.0;
  v2 = *((_DWORD *)this + 22);
  return (float)(GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphWidth(
                   this: (_DWORD *)this + 11,
                   glyphIndex)
               * 1024.0
               / (double)v2);
}

//------------------------------------------------------------------------------
// Address: 0x10151E90
// Name: public: virtual float GFxFontDataCompactedSwf::GetGlyphHeight(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedSwf::GetGlyphHeight(GFxFontDataCompactedSwf *this, unsigned int glyphIndex)
{
  unsigned int v2; // esi

  if ( glyphIndex == -1 || glyphIndex >= *((_DWORD *)this + 14) )
    return 1024.0;
  v2 = *((_DWORD *)this + 22);
  return (float)(GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphHeight(
                   this: (_DWORD *)this + 11,
                   glyphIndex)
               * 1024.0
               / (double)v2);
}

//------------------------------------------------------------------------------
// Address: 0x10151EE0
// Name: public: GFxFontDataCompactedGfx::GFxFontDataCompactedGfx(void)
// Source: json
//------------------------------------------------------------------------------
tagARRAYDESC *__thiscall GFxFontDataCompactedGfx::GFxFontDataCompactedGfx(float *this)
{
  *(this + 2) = 0.0;
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *(this + 3) = 0.0;
  *((_DWORD *)this + 1) = 1;
  *(this + 4) = 0.0;
  *(_DWORD *)this = &GFxFontDataCompactedGfx::`vftable';
  *(this + 5) = 0.0;
  *(this + 6) = 0.0;
  *(this + 7) = 0.0;
  *(this + 8) = 0.0;
  *(this + 9) = 0.0;
  *((_DWORD *)this + 10) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 11) = 1;
  *((_DWORD *)this + 10) = &GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::`vftable';
  *((_DWORD *)this + 12) = this + 7;
  *(this + 17) = 0.0;
  *(this + 18) = 0.0;
  *(this + 19) = 0.0;
  return (tagARRAYDESC *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10151FB0
// Name: public: void GFxFontDataCompactedGfx::Read(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontDataCompactedGfx::Read(GFxFontDataCompactedGfx *this, HBITMAP__ p, int bytes)
{
  GFxFontDataCompactedGfx *v3; // ebx
  unsigned int v4; // edi
  char *v5; // esi
  void *v6; // eax
  int v7; // eax
  int i; // edx
  int v9; // edi
  unsigned __int8 *v10; // ecx
  unsigned __int8 v11; // bl
  tagBITMAPINFOHEADER *v12; // esi
  unsigned int v13; // eax
  const char *v14; // eax
  double v15; // st7
  int (__thiscall *v16)(GFxFontDataCompactedGfx *); // eax
  const char *v17; // eax
  unsigned __int8 *pdestBuf; // [esp+8h] [ebp-1Ch]
  int csize; // [esp+18h] [ebp-Ch]
  int v21; // [esp+1Ch] [ebp-8h] BYREF
  int bytesToRead; // [esp+20h] [ebp-4h]
  tagBITMAPINFOHEADER *pa; // [esp+2Ch] [ebp+8h]
  float pb; // [esp+2Ch] [ebp+8h]

  v3 = this;
  if ( *(_DWORD *)(p.unused + 804) != 0 )
    pa = *(tagBITMAPINFOHEADER **)(p.unused + 804);
  else
    pa = (tagBITMAPINFOHEADER *)(p.unused + 40);
  GFxLogBase<GFxStream>::LogParse(this: pa, a2: (int)"reading DefineCompactedFont:\n");
  v4 = *(_DWORD *)(bytes + 8) - 2;
  csize = v4;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: nullptr);
  v21 = 2;
  v5 = (char *)v3 + 28;
  pdestBuf = (unsigned __int8 *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4096, a3: &v21);
  if ( v4 > *((_DWORD *)v3 + 9) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v5);
    *((_DWORD *)v3 + 9) = v4;
    if ( v4 != 0 )
    {
      bytes = 261;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: (char *)v3 + 28, a3: v4, a4: &bytes);
    }
    else
    {
      v6 = nullptr;
    }
    *(_DWORD *)v5 = v6;
  }
  *((_DWORD *)v3 + 8) = 0;
  bytes = 0;
  while ( 1 )
  {
    bytesToRead = 4096;
    if ( (int)(v4 - bytes) <= 4096 )
      bytesToRead = v4 - bytes;
    v7 = GFxStream::ReadToBuffer(this: (GFxStream *)pa, pdestBuf, a3: bytesToRead);
    bytes += v7;
    if ( v7 > 0 )
    {
      for ( i = 0; i < v7; ++i )
      {
        v9 = *((_DWORD *)v5 + 1);
        v10 = (unsigned __int8 *)(v9 + *(_DWORD *)v5);
        *((_DWORD *)v5 + 1) = v9 + 1;
        v11 = pdestBuf[i];
        *v10 = v11;
      }
      v4 = csize;
      v3 = this;
    }
    if ( v7 != bytesToRead )
      break;
    if ( bytes >= (int)v4 )
    {
      v12 = pa;
      goto LABEL_19;
    }
  }
  v12 = pa;
  GFxLogBase<GFxStream>::LogError(this: pa, a2: (int)"Could not read tag DefineCompactedFont. Broken gfx file.\n");
LABEL_19:
  GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::AcquireFont(this: (int)v3 + 40, a2: 0);
  v13 = *((_DWORD *)v3 + 21);
  if ( v13 != 0 )
  {
    v15 = (double)v13;
    v16 = *(int (__thiscall **)(GFxFontDataCompactedGfx *))(*(_DWORD *)v3 + 60);
    pb = 1024.0 / v15;
    *((float *)v3 + 4) = *((float *)v3 + 24) * pb;
    *((float *)v3 + 2) = *((float *)v3 + 22) * pb;
    *((float *)v3 + 3) = pb * *((float *)v3 + 23);
    v17 = (const char *)v16(a1: v3);
    GFxLogBase<GFxStream>::LogParse(this: v12, a2: (int)"read font \"%s\"\n", v17);
    *((_DWORD *)v3 + 5) = *((_DWORD *)v3 + 20);
  }
  else
  {
    v14 = (const char *)(*(int (__thiscall **)(GFxFontDataCompactedGfx *))(*(_DWORD *)v3 + 60))(a1: v3);
    GFxLogBase<GFxStream>::LogError(
      this: v12,
      a2: (int)"Invalid nominal size for DefineCompactedFont, font %s. Broken gfx file.\n",
      v14);
    *((float *)v3 + 4) = 0.0;
    *((float *)v3 + 2) = 960.0;
    *((float *)v3 + 3) = 64.0;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pdestBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10152190
// Name: public: virtual float GFxFontDataCompactedGfx::GetGlyphWidth(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedGfx::GetGlyphWidth(GFxFontDataCompactedGfx *this, unsigned int glyphIndex)
{
  unsigned int v3; // esi

  if ( glyphIndex == -1 )
    return 512.0;
  v3 = *((_DWORD *)this + 21);
  return (float)(GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphWidth(
                   this: (int **)this + 10,
                   glyphIndex)
               * 1024.0
               / (double)v3);
}

//------------------------------------------------------------------------------
// Address: 0x101521E0
// Name: public: virtual float GFxFontDataCompactedGfx::GetGlyphHeight(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontDataCompactedGfx::GetGlyphHeight(GFxFontDataCompactedGfx *this, unsigned int glyphIndex)
{
  unsigned int v3; // esi

  if ( glyphIndex == -1 )
    return 1024.0;
  v3 = *((_DWORD *)this + 21);
  return (float)(GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphHeight(
                   this: (_DWORD *)this + 10,
                   glyphIndex)
               * 1024.0
               / (double)v3);
}

//------------------------------------------------------------------------------
// Address: 0x10152230
// Name: public: GFxSystemFontResourceKey::GFxSystemFontResourceKey(char const __near *,unsigned int,class GFxFontProvider __near *)
// Source: json
//------------------------------------------------------------------------------
GFxSystemFontResourceKey *__thiscall GFxSystemFontResourceKey::GFxSystemFontResourceKey(
        GFxSystemFontResourceKey *this,
        char *a2,
        char a3,
        IShaderDevice *a4)
{
  CUtlMemory<CImagePacker,int> *v5; // eax
  void *v6; // eax
  void *v7; // edi
  void *v8; // edi
  IShaderAPI *v9; // ecx
  int v11; // [esp+0h] [ebp-14h]
  VertexShaderHandle_t__ *v12; // [esp+0h] [ebp-14h]
  GString v13; // [esp+Ch] [ebp-8h] BYREF
  int v14; // [esp+10h] [ebp-4h]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxSystemFontResourceKey::`vftable';
  *((_DWORD *)this + 2) = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)this + 1);
  v5 = (CUtlMemory<CImagePacker,int> *)GString::GString(this: &v13, a2);
  v6 = GString::ToLower(this: v5);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 12),
    src: (int)v6,
    a3: v11);
  v7 = (void *)(v14 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v14 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  v8 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
  *((_DWORD *)this + 4) = a3 & 3;
  if ( a4 != nullptr )
    GRefCountImpl::AddRef(this: a4, a2: v12);
  v9 = *((IShaderAPI **)this + 2);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 2) = a4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10152360
// Name: public: static class GFxFontResource __near * GFxFontResource::CreateFontResource(char const __near *,unsigned int,class GFxFontProvider __near *,class GFxResourceWeakLib __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxResource *__stdcall GFxFontResource::CreateFontResource(
        char *pname,
        unsigned int fontFlags,
        unsigned int *pprovider,
        int a4)
{
  GFxSystemFontResourceKey *v4; // eax
  struct GFxResource *v5; // ebx
  IShaderAPI *v6; // esi
  IShaderDevice *v7; // esi
  GFxFontResource *v8; // eax
  struct GFxResource *v9; // eax
  GFxResourceKey v11; // [esp+Ch] [ebp-14h] BYREF
  GFxResourceLib::BindHandle v12; // [esp+14h] [ebp-Ch] BYREF
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  v13 = 261;
  v4 = (GFxSystemFontResourceKey *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &v13);
  v5 = nullptr;
  if ( v4 != nullptr )
    v6 = (IShaderAPI *)GFxSystemFontResourceKey::GFxSystemFontResourceKey(
                         this: v4,
                         a2: pname,
                         a3: fontFlags,
                         a4: (IShaderDevice *)pprovider);
  else
    v6 = nullptr;
  GFxResourceKey::GFxResourceKey(this: &v11, a2: &GFxSystemFontResourceKeyInterface_Instance, a3: v6);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  v12.State = RS_Unbound;
  v12.pResource = nullptr;
  if ( GFxResourceWeakLib::BindResourceKey(this: a4, result: (ShaderDeviceInfo_t *)&v12, a3: (int)&v11) != 3 )
  {
    v5 = GFxResourceLib::BindHandle::WaitForResolve(this: &v12);
    goto LABEL_16;
  }
  v7 = (IShaderDevice *)(*(int (__thiscall **)(unsigned int *, char *, unsigned int))(*pprovider + 4))(
                          a1: pprovider,
                          a2: pname,
                          a3: fontFlags);
  if ( v7 != nullptr )
  {
    v13 = 2;
    v8 = (GFxFontResource *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v13);
    if ( v8 != nullptr )
    {
      v9 = (struct GFxResource *)GFxFontResource::GFxFontResource(this: v8, a2: v7, src: (IShaderDevice *)&v11);
      v5 = v9;
      if ( v9 != nullptr )
      {
        GFxResourceLib::ResourceSlot::Resolve(this: v12.pSlot, a2: v9);
        goto LABEL_13;
      }
    }
    else
    {
      v5 = nullptr;
    }
  }
  GFxResourceLib::ResourceSlot::CancelResolve(this: v12.pSlot, a2: (const char *)&pMem);
LABEL_13:
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v7);
LABEL_16:
  if ( v12.State == RS_Available )
  {
    GFxResource::Release(this: (IShaderDevice *)v12.pResource);
  }
  else if ( v12.State >= RS_WaitingResolve )
  {
    GRefCountImpl::Release(this: (IShaderAPI *)v12.pResource);
  }
  if ( v11.pKeyInterface != nullptr )
    v11.pKeyInterface->Release(this: v11.pKeyInterface, a2: v11.hKeyData);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10152510
// Name: GetGlyphBounds_GFxFontDataCompactedSwf_
// Source: json
//------------------------------------------------------------------------------
float *__usercall GetGlyphBounds_GFxFontDataCompactedSwf_@<eax>(
        unsigned int a1@<eax>,
        _DWORD *a2@<edi>,
        float *a3@<esi>)
{
  float v4; // [esp+0h] [ebp-4h]

  if ( a1 == -1 || a1 >= a2[14] )
  {
    *a3 = 0.0;
    a3[1] = 0.0;
    a3[2] = 512.0;
    a3[3] = 1024.0;
  }
  else
  {
    GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphBounds(this: a2 + 11, glyphIndex: a1, a3);
  }
  v4 = (float)(unsigned int)a2[22];
  *a3 = *a3 * 1024.0 / v4;
  a3[1] = a3[1] * 1024.0 / v4;
  a3[2] = a3[2] * 1024.0 / v4;
  a3[3] = 1024.0 * a3[3] / v4;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10152590
// Name: GetGlyphBounds_GFxFontDataCompactedGfx_
// Source: json
//------------------------------------------------------------------------------
float *__usercall GetGlyphBounds_GFxFontDataCompactedGfx_@<eax>(unsigned int a1@<eax>, int a2@<edi>, float *a3@<esi>)
{
  float v4; // [esp+0h] [ebp-4h]

  if ( a1 == -1 || a1 >= *(_DWORD *)(a2 + 52) )
  {
    *a3 = 0.0;
    a3[1] = 0.0;
    a3[2] = 512.0;
    a3[3] = 1024.0;
  }
  else
  {
    GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphBounds(this: (int **)(a2 + 40), result: a1, a3);
  }
  v4 = (float)*(unsigned int *)(a2 + 84);
  *a3 = *a3 * 1024.0 / v4;
  a3[1] = a3[1] * 1024.0 / v4;
  a3[2] = a3[2] * 1024.0 / v4;
  a3[3] = 1024.0 * a3[3] / v4;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10152610
// Name: public: void GMsgFormat::FormatD1<unsigned short>(unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<unsigned short>(GMsgFormat *this, int a2)
{
  bool result; // al
  GMemoryHeap **v4; // esi
  BGR888_t *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  result = GMsgFormat::NextFormatter(this);
  if ( result )
  {
    v4 = (GMemoryHeap **)(this + 61);
    do
    {
      if ( (unsigned int)*(this + 191) < 0x50 )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (BGR888_t *)v7->Alloc(this: v7, a2: 80u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = (BGR888_t *)*(this + 190);
        *(this + 190) = (GMsgFormat)(((unsigned int)&v5[26].g & 0xFFFFFFFC) + 4);
        v6 = ((unsigned int)&v5[26].g & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *(this + 191) = nullptr;
        else
          *(this + 191) = (GMsgFormat)(512 - v6);
      }
      if ( v5 != nullptr )
        GLongFormatter::GLongFormatter(this: v5, f: (int)this);
      else
        v8 = nullptr;
      GMsgFormat::Bind(this, a2: v8, a3: true);
      result = GMsgFormat::NextFormatter(this);
    }
    while ( result );
  }
  ++*((_BYTE *)this + 5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10152850
// Name: public: GFxFontDataCompactedSwf::GFxFontDataCompactedSwf(void)
// Source: json
//------------------------------------------------------------------------------
GFxFontDataCompactedSwf *__thiscall GFxFontDataCompactedSwf::GFxFontDataCompactedSwf(GFxFontDataCompactedSwf *this)
{
  *((float *)this + 2) = 0.0;
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((float *)this + 3) = 0.0;
  *((_DWORD *)this + 1) = 1;
  *((float *)this + 4) = 0.0;
  *((_DWORD *)this + 5) = 0;
  *(_DWORD *)this = &GFxFontDataCompactedSwf::`vftable';
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 11) = &GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::`vftable';
  *((_DWORD *)this + 13) = (char *)this + 28;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 26) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10152920
// Name: public: virtual class GRect<float> __near & GFxFontDataCompactedSwf::GetGlyphBounds(unsigned int,class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontDataCompactedSwf::GetGlyphBounds(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this,
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *glyphIndex,
        float *a3)
{
  GetGlyphBounds_GFxFontDataCompactedSwf_(a1: (unsigned int)glyphIndex, a2: this, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10152940
// Name: public: virtual class GRect<float> __near & GFxFontDataCompactedGfx::GetGlyphBounds(unsigned int,class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxFontDataCompactedGfx::GetGlyphBounds(void *this, unsigned int glyphIndex, float *a3)
{
  return GetGlyphBounds_GFxFontDataCompactedGfx_(a1: glyphIndex, a2: (int)this, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10152DD0
// Name: public: virtual int GFxFontData::GetCharValue(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontData::GetCharValue(int *this, unsigned int glyphIndex)
{
  int *v2; // esi
  int *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edx
  _DWORD *v6; // ecx
  int *v7; // esi
  int v8; // ecx
  unsigned int v9; // edx
  _DWORD *v10; // ecx

  v2 = this + 11;
  v3 = (int *)*(this + 11);
  if ( v3 != nullptr )
  {
    v5 = v3[1];
    v4 = 0;
    v6 = v3 + 2;
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 2;
    }
    while ( v4 <= v5 );
    v3 = v2;
  }
  else
  {
    v4 = 0;
  }
  v7 = v3;
  while ( v7 != nullptr )
  {
    v8 = *v7;
    if ( *v7 == 0 )
      break;
    v9 = *(_DWORD *)(v8 + 4);
    if ( (int)v4 > (int)v9 )
      break;
    if ( *(unsigned __int16 *)(v8 + 8 * v4 + 14) == glyphIndex )
      return *(unsigned __int16 *)(v8 + 8 * v4 + 12);
    if ( ++v4 <= v9 )
    {
      v10 = (_DWORD *)(v8 + 8 * v4 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v4;
        v10 += 2;
      }
      while ( v4 <= v9 );
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10152E50
// Name: BuildStringFromRanges
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__usercall BuildStringFromRanges@<eax>(
        unsigned __int16 **a1@<edx>,
        CUtlMemory<CImagePacker,int> *a2@<ecx>,
        unsigned __int16 a3@<di>)
{
  unsigned int v4; // ebx
  unsigned __int16 *v5; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // edi
  int v9; // edi
  CUtlMemory<CImagePacker,int> *v10; // esi
  unsigned __int16 v12; // [esp-4h] [ebp-538h]
  unsigned __int16 v13; // [esp-4h] [ebp-538h]
  unsigned __int16 v14; // [esp-4h] [ebp-538h]
  _DWORD v15[3]; // [esp+8h] [ebp-52Ch] BYREF
  int v16; // [esp+14h] [ebp-520h] BYREF
  int *v17; // [esp+18h] [ebp-51Ch]
  int v18; // [esp+1Ch] [ebp-518h]
  int v19; // [esp+20h] [ebp-514h]
  int v20; // [esp+24h] [ebp-510h] BYREF
  CUtlMemory<CImagePacker,int> *v21; // [esp+28h] [ebp-50Ch]
  char v22; // [esp+2Fh] [ebp-505h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v23; // [esp+30h] [ebp-504h] BYREF
  int putf8str[128]; // [esp+330h] [ebp-204h] BYREF

  v21 = a2;
  GString::GString(this: a2);
  v4 = 0;
  v19 = 0;
  v22 = 1;
  v20 = 0;
  if ( a1[1] == nullptr )
    return v21;
  v12 = a3;
  do
  {
    if ( v4 != 0 )
    {
      v5 = &(*a1)[2 * v4];
      v6 = *(v5 - 1);
      v7 = (int)(v5 - 1);
      if ( *v5 <= (unsigned int)(v6 + 1) )
        goto LABEL_14;
      if ( (_WORD)v20 == (_WORD)v6 )
      {
        v15[1] = putf8str;
        v15[0] = 2;
        v15[2] = 512;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v23, a2: (const struct GMsgFormat::Sink *)v15);
        GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A95E8.m_Root);
        GMsgFormat::FormatD1<unsigned short>(this: (GMsgFormat *)&v23, a2: (int)&v20);
      }
      else
      {
        v17 = putf8str;
        v16 = 2;
        v18 = 512;
        GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v23, a2: (const struct GMsgFormat::Sink *)&v16);
        GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A95E8);
        GMsgFormat::FormatD1<unsigned short>(this: (GMsgFormat *)&v23, a2: (int)&v20);
        GMsgFormat::FormatD1<unsigned short>(this: (GMsgFormat *)&v23, a2: v7);
      }
      GMsgFormat::FinishFormatD(this: &v23, a2: v12);
      GMsgFormat::~GMsgFormat(this: &v23, data_size: v13);
      v8 = v19;
      if ( v19 != 0 )
        GString::AppendString(this: v21, putf8str: (int)", ");
      GString::AppendString(this: v21, (int)putf8str);
      v19 = v8 + 1;
      if ( v8 + 1 > 4 )
        goto LABEL_19;
      v20 = (*a1)[2 * v4];
    }
    else
    {
      v20 = **a1;
    }
    v22 = 0;
LABEL_14:
    ++v4;
  }
  while ( v4 < (unsigned int)a1[1] );
  if ( v22 == 0 )
  {
    v9 = (int)&(*a1)[2 * (_DWORD)a1[1] - 1];
    v17 = putf8str;
    v16 = 2;
    v18 = 512;
    GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v23, a2: (const struct GMsgFormat::Sink *)&v16);
    GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A95E8);
    GMsgFormat::FormatD1<unsigned short>(this: (GMsgFormat *)&v23, a2: (int)&v20);
    GMsgFormat::FormatD1<unsigned short>(this: (GMsgFormat *)&v23, a2: v9);
    GMsgFormat::FinishFormatD(this: &v23, a2: v12);
    GMsgFormat::~GMsgFormat(this: &v23, data_size: v14);
    if ( v19 != 0 )
      GString::AppendString(this: v21, putf8str: (int)", ");
    GString::AppendString(this: v21, (int)putf8str);
  }
LABEL_19:
  if ( v4 < (unsigned int)a1[1] )
  {
    v10 = v21;
    GString::AppendString(this: v21, putf8str: (int)" (truncated)");
    return v10;
  }
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x101530E0
// Name: public: virtual class GString GFxFontData::GetCharRanges(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__userpurge GFxFontData::GetCharRanges@<eax>(
        CMorph *this@<ecx>,
        unsigned __int16 a2@<di>,
        CUtlMemory<CImagePacker,int> *ranges)
{
  ITextureInternal *v3; // eax
  unsigned __int16 v4; // bx
  ITextureInternal **m_pMorphTexture; // edx
  ITextureInternal **v6; // eax
  unsigned int v7; // ecx
  ITextureInternal_vtbl *v8; // esi
  _DWORD *v9; // eax
  unsigned int v10; // esi
  bool v11; // dl
  ITextureInternal *v12; // ecx
  unsigned int v13; // edi
  int v14; // eax
  unsigned int v15; // edi
  _DWORD *v16; // eax
  unsigned __int16 v17; // di
  unsigned int v18; // esi
  unsigned __int16 *v19; // esi
  unsigned __int16 *v22; // [esp+8h] [ebp-24h] BYREF
  unsigned int v23; // [esp+Ch] [ebp-20h]
  unsigned int v24; // [esp+10h] [ebp-1Ch]
  ITextureInternal **v25; // [esp+14h] [ebp-18h]
  int prevValue; // [esp+1Ch] [ebp-10h]
  int v27; // [esp+20h] [ebp-Ch]
  int rangeStart; // [esp+24h] [ebp-8h]
  bool rangeStarted; // [esp+2Bh] [ebp-1h]

  v3 = this->m_pMorphTexture[0];
  v4 = 0;
  m_pMorphTexture = this->m_pMorphTexture;
  v22 = nullptr;
  v23 = 0;
  v24 = 0;
  if ( v3 != nullptr )
  {
    v8 = v3[1].__vftable;
    v7 = 0;
    v9 = &v3[2].__vftable;
    do
    {
      if ( *v9 != -2 )
        break;
      ++v7;
      v9 += 2;
    }
    while ( v7 <= (unsigned int)v8 );
    v6 = m_pMorphTexture;
  }
  else
  {
    v6 = nullptr;
    v7 = 0;
  }
  v25 = v6;
  v10 = v7;
  rangeStart = 0;
  prevValue = 0;
LABEL_8:
  v11 = false;
  rangeStarted = false;
  while ( v25 != nullptr )
  {
    v12 = *v25;
    if ( *v25 == nullptr )
      break;
    v13 = (unsigned int)v12[1].__vftable;
    if ( (int)v10 > (int)v13 )
      break;
    v14 = LOWORD(v12[2 * v10 + 3].__vftable);
    if ( v11 )
    {
      if ( v4 != v14 - 1 )
      {
        v4 = prevValue;
        LOWORD(v27) = rangeStart;
        v15 = v23 + 1;
        HIWORD(v27) = prevValue;
        if ( v23 + 1 >= v23 )
        {
          if ( v15 >= v24 )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v22,
              pheapAddr: (ButtonCode_t)&v22,
              newCapacity: v15 + (v15 >> 2));
        }
        else if ( v15 < v24 >> 1 )
        {
          GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
            this: (CVertexBuilder *)&v22,
            pheapAddr: (ButtonCode_t)&v22,
            newCapacity: v23 + 1);
        }
        v23 = v15;
        if ( &v22[2 * v15] != (unsigned __int16 *)4 )
          *(_DWORD *)&v22[2 * v15 - 2] = v27;
        goto LABEL_8;
      }
      v11 = rangeStarted;
    }
    else
    {
      rangeStart = LOWORD(v12[2 * v10 + 3].__vftable);
      v11 = true;
      rangeStarted = true;
    }
    v4 = v14;
    ++v10;
    prevValue = (unsigned __int16)v14;
    if ( v10 <= v13 )
    {
      v16 = &v12[2 * v10 + 2].__vftable;
      do
      {
        if ( *v16 != -2 )
          break;
        ++v10;
        v16 += 2;
      }
      while ( v10 <= v13 );
    }
  }
  v17 = a2;
  if ( v11 )
  {
    v18 = v23 + 1;
    LOWORD(prevValue) = rangeStart;
    HIWORD(prevValue) = v4;
    if ( v23 + 1 >= v23 )
    {
      if ( v18 >= v24 )
        GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
          this: (CVertexBuilder *)&v22,
          pheapAddr: (ButtonCode_t)&v22,
          newCapacity: v18 + (v18 >> 2));
    }
    else if ( v18 < v24 >> 1 )
    {
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: (CVertexBuilder *)&v22,
        pheapAddr: (ButtonCode_t)&v22,
        newCapacity: v23 + 1);
    }
    v23 = v18;
    v19 = &v22[2 * v18 - 2];
    if ( v19 != nullptr )
      *(_DWORD *)v19 = prevValue;
  }
  LOBYTE(prevValue) = 0;
  G_QuickSortSliced<GArray<`anonymous namespace'::Range,2,GArrayDefaultPolicy>,`anonymous namespace'::RangeLess>(
    a1: &v22,
    a2: 0,
    a3: v23);
  BuildStringFromRanges(a1: &v22, a2: ranges, a3: v17);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
  return ranges;
}

//------------------------------------------------------------------------------
// Address: 0x101532A0
// Name: public: void GFxFontDataCompactedSwf::Read(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
const CVertexMorphDict::MorphVertexList_t *__thiscall GFxFontDataCompactedSwf::Read(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this,
        const CVertexMorphDict::MorphVertexList_t *p,
        int *tagInfo)
{
  const CVertexMorphDict::MorphVertexList_t *result; // eax
  MorphVertexInfo_t *m_pMemory; // esi
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // edx
  unsigned int UInt; // eax
  bool v10; // bl
  bool v11; // al
  int v12; // ecx
  int m_nVertexId; // eax
  unsigned __int8 v14; // bl
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  const char *v18; // eax
  int v19; // eax
  const char *v20; // edx
  int v21; // edx
  int m_nMorphTargetId; // eax
  int v23; // edi
  unsigned int v24; // ebx
  int v25; // eax
  unsigned __int8 *v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // edi
  unsigned int v33; // eax
  unsigned int v34; // ebx
  int *v35; // ebx
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // edx
  int v40; // eax
  int v41; // edx
  unsigned int v42; // edi
  _DWORD *v43; // edi
  int v44; // eax
  int v45; // eax
  int v46; // edx
  CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *v47; // ebx
  float v48; // edi
  int v49; // eax
  char v50; // al
  unsigned int v51; // edi
  void *v52; // esi
  LONG v53; // eax
  double v54; // st7
  int v55; // edi
  int v56; // eax
  unsigned int m_nGrowSize; // ebx
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v58; // edi
  int v59; // eax
  int v60; // eax
  double v61; // st7
  int v62; // ecx
  int v63; // ecx
  int v64; // eax
  float *v65; // ebx
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  const CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v70; // edi
  int v71; // ecx
  int v72; // eax
  int v73; // edi
  int v74; // edx
  int v75; // eax
  int v76; // edi
  unsigned int v77; // eax
  int v78; // eax
  unsigned __int16 v79; // bx
  int v80; // edx
  int v81; // eax
  unsigned __int16 v82; // di
  int v83; // eax
  int v84; // eax
  unsigned __int8 v85; // cl
  int v86; // ecx
  int v87; // eax
  unsigned __int8 v88; // cl
  int v89; // ecx
  int v90; // eax
  double v91; // st7
  _cpinfo *v92; // [esp+0h] [ebp-198h]
  int v93; // [esp+0h] [ebp-198h]
  const KMeansSampleDescriptor *v94; // [esp+0h] [ebp-198h]
  const FourVectors *v95; // [esp+4h] [ebp-194h]
  const KMeansQuantizedValue *v96; // [esp+8h] [ebp-190h]
  CFltX4AttributeIterator *pit; // [esp+Ch] [ebp-18Ch] BYREF
  int v98; // [esp+10h] [ebp-188h]
  char v99; // [esp+2Ch] [ebp-16Ch]
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > v100; // [esp+80h] [ebp-118h] BYREF
  CBitRead v101; // [esp+FCh] [ebp-9Ch] BYREF
  int v102; // [esp+124h] [ebp-74h]
  const CVertexMorphDict::MorphVertexList_t *v103; // [esp+128h] [ebp-70h]
  int px; // [esp+12Ch] [ebp-6Ch] BYREF
  int py; // [esp+130h] [ebp-68h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> dummyRect; // [esp+134h] [ebp-64h] BYREF
  float i; // [esp+140h] [ebp-58h]
  int tableBase; // [esp+144h] [ebp-54h]
  unsigned int nominalSize; // [esp+148h] [ebp-50h]
  int fontCodeOffset; // [esp+14Ch] [ebp-4Ch]
  unsigned int k; // [esp+150h] [ebp-48h]
  CUtlMemory<CImagePacker,int> v112; // [esp+154h] [ebp-44h] BYREF
  unsigned int v113; // [esp+160h] [ebp-38h]
  unsigned int v114; // [esp+164h] [ebp-34h]
  wchar_t val[2]; // [esp+168h] [ebp-30h] BYREF
  CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *v116; // [esp+16Ch] [ebp-2Ch]
  bool wideOffsets; // [esp+171h] [ebp-27h]
  bool isLoadingFontShapes; // [esp+172h] [ebp-26h]
  bool hasLayout; // [esp+173h] [ebp-25h]
  float v120; // [esp+174h] [ebp-24h] BYREF
  float sfactor; // [esp+178h] [ebp-20h]
  float v122; // [esp+17Ch] [ebp-1Ch]
  float v123[2]; // [esp+180h] [ebp-18h] BYREF
  float v124; // [esp+188h] [ebp-10h]
  float v125; // [esp+18Ch] [ebp-Ch]
  char v126; // [esp+190h] [ebp-8h]

  result = p;
  m_pMemory = p[25].m_MorphInfo.m_Memory.m_pMemory;
  v116 = this;
  v103 = p;
  v112.m_nAllocationCount = (int)tagInfo;
  if ( m_pMemory == nullptr )
    m_pMemory = (MorphVertexInfo_t *)&p[1].m_MorphInfo.m_Memory.m_nAllocationCount;
  v6 = *tagInfo;
  isLoadingFontShapes = true;
  if ( v6 == 48 || v6 == 75 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(p->m_MorphInfo.m_Size + 8) + 36);
    v8 = *(_DWORD *)(v7 + 12);
    LOBYTE(v7) = *(_BYTE *)(v7 + 16);
    nominalSize = v8;
    LOBYTE(k) = v7;
    GFxFontCompactor::GFxFontCompactor(a1: (char *)this + 28);
    if ( *tagInfo == 48 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)m_pMemory, a2: (int)"reading DefineFont2: ");
    else
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)m_pMemory, a2: (int)"reading DefineFont3: ");
    UInt = GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u);
    hasLayout = UInt != 0;
    if ( UInt != 0 )
      *((_DWORD *)this + 5) |= 0x2000u;
    else
      *((_DWORD *)this + 5) &= ~0x2000u;
    v10 = GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u) != 0;
    GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u);
    v11 = GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u) != 0;
    if ( v10 )
    {
      *((_DWORD *)this + 5) = *((_DWORD *)this + 5) & 0xFFFFFCFF | 0x200;
    }
    else if ( v11 )
    {
      *((_DWORD *)this + 5) = *((_DWORD *)this + 5) & 0xFFFFFCFF | 0x100;
    }
    else
    {
      *((_DWORD *)this + 5) &= 0xFFFFFCFF;
    }
    wideOffsets = GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u) != 0;
    if ( GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u) != 0 )
      *((_DWORD *)this + 5) |= 0x4000u;
    else
      *((_DWORD *)this + 5) &= ~0x4000u;
    if ( GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u) != 0 )
      *((_DWORD *)this + 5) |= 1u;
    else
      *((_DWORD *)this + 5) &= ~1u;
    if ( GFxStream::ReadUInt(this: (GFxStream *)m_pMemory, a2: 1u) != 0 )
      *((_DWORD *)this + 5) |= 2u;
    else
      *((_DWORD *)this + 5) &= ~2u;
    v12 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
    BYTE1(m_pMemory->m_NormalDelta.x) = 0;
    if ( v12 < 1 )
      GFxStream::PopulateBuffer1(result: v92);
    m_nVertexId = m_pMemory[1].m_nVertexId;
    v14 = *(_BYTE *)(m_nVertexId + LODWORD(m_pMemory[1].m_PositionDelta.z));
    m_pMemory[1].m_nVertexId = m_nVertexId + 1;
    GString::GString(this: &v112);
    GFxStream::ReadStringWithLength(this: (GFxStream *)m_pMemory, a2: (struct GString *)&v112);
    v15 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
    BYTE1(m_pMemory->m_NormalDelta.x) = 0;
    if ( v15 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v16 = m_pMemory[1].m_nVertexId;
    v17 = *(unsigned __int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v16);
    m_pMemory[1].m_nVertexId = v16 + 2;
    *((_DWORD *)this + 26) = v17;
    if ( GFxStream::IsVerboseParse(this: (GFxStream *)m_pMemory) )
    {
      if ( ((int)v112.m_pMemory & 0xFFFFFFFC) == 0xFFFFFFF8 )
        v18 = "(none)";
      else
        v18 = (const char *)(((int)v112.m_pMemory & 0xFFFFFFFC) + 8);
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)m_pMemory,
        a2: (int)"  Name = %s, %d glyphs\n",
        v18,
        *((_DWORD *)this + 26));
      v19 = *((_DWORD *)this + 5);
      v20 = "Unicode";
      if ( (v19 & 0x300) == 0x200 )
      {
        v20 = "ShiftJIS";
      }
      else if ( (v19 & 0x300) == 0x100 )
      {
        v20 = "ANSI";
      }
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)m_pMemory,
        a2: (int)"  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n",
        hasLayout,
        v20,
        *((_BYTE *)this + 20) & 1,
        (v19 & 2) != 0);
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)m_pMemory, a2: (int)"  LangCode = %d\n", v14);
    }
    v21 = m_pMemory[1].m_nVertexId;
    m_nMorphTargetId = m_pMemory[1].m_nMorphTargetId;
    v23 = *((_DWORD *)this + 26);
    v24 = 0;
    tableBase = LODWORD(m_pMemory[1].m_PositionDelta.x) + v21 - m_nMorphTargetId;
    v112.m_nGrowSize = 0;
    v113 = 0;
    v114 = 0;
    if ( v23 != 0 )
    {
      v25 = m_nMorphTargetId - v21;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( wideOffsets )
      {
        if ( v25 < 4 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
        v26 = (unsigned __int8 *)(m_pMemory[1].m_nVertexId + LODWORD(m_pMemory[1].m_PositionDelta.z));
        v27 = *v26 | ((v26[1] | (*((unsigned __int16 *)v26 + 1) << 8)) << 8);
        m_pMemory[1].m_nVertexId += 4;
      }
      else
      {
        if ( v25 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v28 = m_pMemory[1].m_nVertexId;
        v29 = *(unsigned __int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v28);
        m_pMemory[1].m_nVertexId = v28 + 2;
        v27 = v29;
      }
      if ( v27 != 0 )
      {
        *(_DWORD *)val = v27;
        GArrayBase<GArrayData<unsigned int,GAllocatorGH<unsigned int,2>,GArrayDefaultPolicy>>::PushBack(
          this: (IScaleformUI *)&v112.m_nGrowSize,
          (GTexture::ChangeHandler *const *)val,
          a3: (int)v92);
        v24 = v113;
      }
      else
      {
        isLoadingFontShapes = false;
        v23 = 0;
      }
    }
    if ( wideOffsets )
    {
      if ( v23 > 1 )
      {
        LODWORD(v120) = v23 - 1;
        do
        {
          v30 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
          BYTE1(m_pMemory->m_NormalDelta.x) = 0;
          if ( v30 < 4 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v31 = m_pMemory[1].m_nVertexId;
          v32 = *(unsigned __int8 *)(v31 + LODWORD(m_pMemory[1].m_PositionDelta.z))
              | ((*(unsigned __int8 *)(v31 + LODWORD(m_pMemory[1].m_PositionDelta.z) + 1)
                | ((*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v31 + 2)
                  | (*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v31 + 3) << 8)) << 8)) << 8);
          v33 = v113;
          v34 = v113 + 1;
          m_pMemory[1].m_nVertexId = v31 + 4;
          if ( v34 >= v33 )
          {
            if ( v34 >= v114 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: (CVertexBuilder *)&v112.m_nGrowSize,
                pheapAddr: (ButtonCode_t)&v112.m_nGrowSize,
                newCapacity: v34 + (v34 >> 2));
          }
          else if ( v34 < v114 >> 1 )
          {
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v112.m_nGrowSize,
              pheapAddr: (ButtonCode_t)&v112.m_nGrowSize,
              newCapacity: v34);
          }
          v113 = v34;
          v35 = (int *)(v112.m_nGrowSize + 4 * v34 - 4);
          if ( v35 != nullptr )
            *v35 = v32;
          --LODWORD(v120);
        }
        while ( v120 != 0.0 );
      }
      v36 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( v36 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v37 = m_pMemory[1].m_nVertexId;
      v38 = *(unsigned __int8 *)(v37 + LODWORD(m_pMemory[1].m_PositionDelta.z))
          | ((*(unsigned __int8 *)(v37 + LODWORD(m_pMemory[1].m_PositionDelta.z) + 1)
            | ((*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v37 + 2)
              | (*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v37 + 3) << 8)) << 8)) << 8);
      m_pMemory[1].m_nVertexId = v37 + 4;
      fontCodeOffset = v38;
    }
    else
    {
      if ( v23 > 1 )
      {
        LODWORD(v120) = v23 - 1;
        do
        {
          v39 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
          BYTE1(m_pMemory->m_NormalDelta.x) = 0;
          if ( v39 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v40 = m_pMemory[1].m_nVertexId;
          v41 = (unsigned __int16)(*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v40)
                                 | (*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v40 + 1) << 8));
          v42 = v24 + 1;
          m_pMemory[1].m_nVertexId = v40 + 2;
          *(_DWORD *)val = v41;
          if ( v24 + 1 >= v24 )
          {
            if ( v42 >= v114 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: (CVertexBuilder *)&v112.m_nGrowSize,
                pheapAddr: (ButtonCode_t)&v112.m_nGrowSize,
                newCapacity: v42 + (v42 >> 2));
          }
          else if ( v42 < v114 >> 1 )
          {
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v112.m_nGrowSize,
              pheapAddr: (ButtonCode_t)&v112.m_nGrowSize,
              newCapacity: v24 + 1);
          }
          ++v24;
          v43 = (_DWORD *)(v112.m_nGrowSize + 4 * v42 - 4);
          v113 = v24;
          if ( v43 != nullptr )
            *v43 = *(_DWORD *)val;
          --LODWORD(v120);
        }
        while ( v120 != 0.0 );
      }
      v44 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( v44 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v45 = m_pMemory[1].m_nVertexId;
      v46 = (unsigned __int16)(*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v45)
                             | (*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v45 + 1) << 8));
      m_pMemory[1].m_nVertexId = v45 + 2;
      fontCodeOffset = v46;
    }
    v47 = v116;
    v48 = 0.0;
    GFxFontCompactor::StartFont(
      this: (GFxFontCompactor *)&v100,
      a2: (const char *)(((int)v112.m_pMemory & 0xFFFFFFFC) + 8),
      a3: v116[1].m_nGrowSize,
      a4: nominalSize,
      a5: 0,
      a6: 0,
      a7: 0);
    if ( isLoadingFontShapes )
    {
      v49 = *(_DWORD *)v112.m_nAllocationCount;
      wcscpy(val, L"\x16");
      if ( v49 != 48 )
        *(_DWORD *)val = v49;
      LODWORD(v120) = 258;
      if ( GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v47, a3: 12, a4: &v120) != nullptr )
        sfactor = COERCE_FLOAT(GFxPathAllocator::GFxPathAllocator(result: (FloatCubeMap_t *)0x1FF8));
      else
        sfactor = 0.0;
      if ( v47[8].m_nGrowSize != 0 )
      {
        do
        {
          GFxStream::SetPosition(
            this: (IShaderDeviceMgr *)m_pMemory,
            pos: tableBase + *(_DWORD *)(v112.m_nGrowSize + 4 * LODWORD(v48)),
            a3: (int)v92);
          LODWORD(v122) = LODWORD(v48) + 1;
          GFxFontCompactor::StartGlyph(this: &v100, a2: v93);
          GFxShapeBase::GFxShapeBase();
          v101.m_pDebugName = (const char *)&GFxConstShapeNoStyles::`vftable';
          v102 = 0;
          GFxConstShapeNoStyles::Read(this: &v101);
          GFxSwfPathData::PathsIterator::PathsIterator(this: &pit, a2: (const struct GFxShapeBase *)&v101);
          v50 = v99;
          if ( v99 != 1 )
          {
            v51 = nominalSize;
            do
            {
              if ( v50 == 2 )
              {
                GFxSwfPathData::PathsIterator::ReadNextEdge(
                  this: (IKMeansErrorMetric *)&pit,
                  a2: v94,
                  a3: v95,
                  a4: v96,
                  a5: (__m128 *)pit);
              }
              else
              {
                GFxSwfPathData::EdgesIterator::EdgesIterator();
                GFxSwfPathData::EdgesIterator::GetMoveXY(
                  this: (CSOAContainer *)&dummyRect.m_nGrowSize,
                  (int)&px,
                  (int)&py,
                  a4: (int)v94,
                  a5: (int)v95,
                  a6: (const CSOAContainer *)v96,
                  a7: (int)pit,
                  a8: v98);
                v120 = (float)v51;
                GFxFontCompactor::MoveTo(
                  this: (GFxFontCompactor *)&v100,
                  a2: (int)(v120 * *(float *)&px * 0.0009765625),
                  a3: (int)(v120 * *(float *)&py * 0.0009765625));
                while ( *(char *)(dummyRect.m_nGrowSize + 32) < 0 )
                {
                  GFxSwfPathData::EdgesIterator::GetEdge(
                    this: (GFxSwfPathData::EdgesIterator *)&dummyRect.m_nGrowSize,
                    a2: (struct GFxSwfPathData::EdgesIterator::Edge *)v123,
                    a3: false);
                  v54 = v120;
                  if ( v126 != 0 )
                    GFxFontCompactor::QuadTo(
                      this: &v100,
                      cx: (unsigned __int16)(int)(v54 * v123[0] * 0.0009765625),
                      cy: (unsigned __int16)(int)(v54 * v123[1] * 0.0009765625),
                      ax: (const CVertexMorphDict::MorphVertexList_t *)(unsigned __int16)(int)(v54 * v124 * 0.0009765625));
                  else
                    GFxFontCompactor::LineTo(
                      this: (GFxFontCompactor *)&v100,
                      a2: (int)(v54 * v124 * 0.0009765625),
                      a3: (int)(v120 * v125 * 0.0009765625));
                }
              }
              v50 = v99;
            }
            while ( v99 != 1 );
          }
          GFxFontCompactor::EndGlyph(this: &v100, mergeContours: k);
          GFxPathAllocator::Clear(this: (FloatCubeMap_t *)LODWORD(sfactor), a2: (const char *)v94);
          GFxShapeBase::~GFxShapeBase(this: (GFxShapeBase *)&v101);
          v48 = v122;
        }
        while ( LODWORD(v122) < v116[8].m_nGrowSize );
      }
      if ( sfactor != 0.0 )
      {
        GFxPathAllocator::~GFxPathAllocator(this: (FloatCubeMap_t *)LODWORD(sfactor), a2: (const char *)v92);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(sfactor));
      }
      if ( tableBase + fontCodeOffset != LODWORD(m_pMemory[1].m_PositionDelta.x)
                                       + m_pMemory[1].m_nVertexId
                                       - m_pMemory[1].m_nMorphTargetId )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v112.m_nGrowSize);
        v52 = (void *)((int)v112.m_pMemory & 0xFFFFFFFC);
        v53 = InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v112.m_pMemory & 0xFFFFFFFC) + 4), Value: -1);
LABEL_156:
        if ( v53 == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v52);
        return (const CVertexMorphDict::MorphVertexList_t *)GFxFontCompactor::~GFxFontCompactor(
                                                              this: &v100,
                                                              a2: (int)v92);
      }
    }
    else
    {
      v55 = tableBase + fontCodeOffset;
      GFxStream::GetTagEndPosition(this: (IShaderDeviceMgr *)m_pMemory, a2: (ShaderDisplayMode_t *)v92, a3: (int)v95);
      if ( v55 >= v56 )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v112.m_nGrowSize);
        v52 = (void *)((int)v112.m_pMemory & 0xFFFFFFFC);
        v53 = InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v112.m_pMemory & 0xFFFFFFFC) + 4), Value: -1);
        goto LABEL_156;
      }
      GFxStream::SetPosition(this: (IShaderDeviceMgr *)m_pMemory, pos: v55, a3: (int)v92);
      v47[1].m_nGrowSize |= 0x1000u;
    }
    GFxLogBase<GFxStream>::LogParse(
      this: (tagBITMAPINFOHEADER *)m_pMemory,
      a2: (int)"reading code table at offset %d\n",
      LODWORD(m_pMemory[1].m_PositionDelta.x) + m_pMemory[1].m_nVertexId - m_pMemory[1].m_nMorphTargetId);
    m_nGrowSize = v116[8].m_nGrowSize;
    v58 = nullptr;
    if ( (v116[1].m_nGrowSize & 0x4000) != 0 )
    {
      if ( m_nGrowSize != 0 )
      {
        do
        {
          v59 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
          BYTE1(m_pMemory->m_NormalDelta.x) = 0;
          if ( v59 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          m_pMemory[1].m_nVertexId += 2;
          GFxFontCompactor::AssignGlyphCode(this: &v100, glyphIndex: v58);
          v58 = (CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *)((char *)v58 + 1);
        }
        while ( (unsigned int)v58 < m_nGrowSize );
      }
    }
    else if ( m_nGrowSize != 0 )
    {
      do
      {
        v60 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
        BYTE1(m_pMemory->m_NormalDelta.x) = 0;
        if ( v60 < 1 )
          GFxStream::PopulateBuffer1(result: v92);
        ++m_pMemory[1].m_nVertexId;
        GFxFontCompactor::AssignGlyphCode(this: &v100, glyphIndex: v58);
        v58 = (CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *)((char *)v58 + 1);
      }
      while ( (unsigned int)v58 < m_nGrowSize );
    }
    if ( hasLayout )
    {
      if ( *(_DWORD *)v112.m_nAllocationCount == 75 )
        v61 = 0.050000001;
      else
        v61 = 1.0;
      v62 = m_pMemory[1].m_nMorphTargetId;
      sfactor = v61;
      v63 = v62 - m_pMemory[1].m_nVertexId;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( v63 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v64 = m_pMemory[1].m_nVertexId;
      v65 = (float *)v116;
      LODWORD(v122) = *(__int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v64);
      m_pMemory[1].m_nVertexId = v64 + 2;
      v112.m_nAllocationCount = (int)(v65 + 2);
      v65[2] = (double)SLODWORD(v122) * sfactor;
      v66 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( v66 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v67 = m_pMemory[1].m_nVertexId;
      LODWORD(v122) = *(__int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v67);
      m_pMemory[1].m_nVertexId = v67 + 2;
      v65[3] = (double)SLODWORD(v122) * sfactor;
      v68 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( v68 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v69 = m_pMemory[1].m_nVertexId;
      LODWORD(v122) = *(__int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v69);
      m_pMemory[1].m_nVertexId = v69 + 2;
      k = (unsigned int)(v65 + 4);
      v122 = (double)SLODWORD(v122) * sfactor;
      v65[4] = v122;
      GFxFontCompactor::UpdateMetrics(
        this: &v100,
        ascent: (const CVertexMorphDict::MorphVertexList_t *)((int)(nominalSize * (int)*(float *)v112.m_nAllocationCount) / 1024));
      if ( GFxStream::IsVerboseParse(this: (GFxStream *)m_pMemory) )
        GFxLogBase<GFxStream>::LogParse(
          this: (tagBITMAPINFOHEADER *)m_pMemory,
          a2: (int)"  Ascent = %d, Descent = %d, Leading = %d\n",
          (int)*(float *)v112.m_nAllocationCount,
          (int)v65[3],
          (int)*(float *)k);
      v70 = nullptr;
      k = v116[8].m_nGrowSize;
      if ( k != 0 )
      {
        do
        {
          v71 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
          BYTE1(m_pMemory->m_NormalDelta.x) = 0;
          if ( v71 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v72 = m_pMemory[1].m_nVertexId;
          LODWORD(v122) = (unsigned __int16)(*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v72)
                                           | (*(unsigned __int8 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v72 + 1) << 8));
          m_pMemory[1].m_nVertexId = v72 + 2;
          GFxFontCompactor::AssignGlyphAdvance(this: &v100, glyphIndex: v70);
          v70 = (const CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *)((char *)v70 + 1);
        }
        while ( (unsigned int)v70 < k );
      }
      v73 = v116[8].m_nGrowSize;
      *(float *)&dummyRect.m_pMemory = 0.0;
      *(float *)&dummyRect.m_nAllocationCount = 0.0;
      *(float *)&dummyRect.m_nGrowSize = 0.0;
      for ( i = 0.0; v73 != 0; --v73 )
        GFxStream::ReadRect(this: (GFxStream *)m_pMemory, a2: (int)&dummyRect);
      v74 = m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId;
      BYTE1(m_pMemory->m_NormalDelta.x) = 0;
      if ( v74 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v75 = m_pMemory[1].m_nVertexId;
      v76 = *(unsigned __int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v75);
      m_pMemory[1].m_nVertexId = v75 + 2;
      if ( GFxStream::IsVerboseParse(this: (GFxStream *)m_pMemory) )
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)m_pMemory, a2: (int)"  KerningCount = %d\n", v76);
      if ( v76 > 0 )
      {
        *(_DWORD *)val = v76;
        do
        {
          v77 = (unsigned int)v116[1].m_nGrowSize >> 14;
          BYTE1(m_pMemory->m_NormalDelta.x) = 0;
          if ( (v77 & 1) != 0 )
          {
            if ( m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId < 2 )
              GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
            v78 = m_pMemory[1].m_nVertexId;
            v79 = *(_WORD *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v78);
            v78 += 2;
            v80 = m_pMemory[1].m_nMorphTargetId - v78;
            m_pMemory[1].m_nVertexId = v78;
            BYTE1(m_pMemory->m_NormalDelta.x) = 0;
            if ( v80 < 2 )
              GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
            v81 = m_pMemory[1].m_nVertexId;
            v82 = *(_WORD *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v81);
            v83 = v81 + 2;
          }
          else
          {
            if ( m_pMemory[1].m_nMorphTargetId - m_pMemory[1].m_nVertexId < 1 )
              GFxStream::PopulateBuffer1(result: v92);
            v84 = m_pMemory[1].m_nVertexId;
            v85 = *(_BYTE *)(v84 + LODWORD(m_pMemory[1].m_PositionDelta.z));
            ++v84;
            v79 = v85;
            v86 = m_pMemory[1].m_nMorphTargetId - v84;
            m_pMemory[1].m_nVertexId = v84;
            BYTE1(m_pMemory->m_NormalDelta.x) = 0;
            if ( v86 < 1 )
              GFxStream::PopulateBuffer1(result: v92);
            v87 = m_pMemory[1].m_nVertexId;
            v88 = *(_BYTE *)(v87 + LODWORD(m_pMemory[1].m_PositionDelta.z));
            v83 = v87 + 1;
            v82 = v88;
          }
          v89 = m_pMemory[1].m_nMorphTargetId - v83;
          m_pMemory[1].m_nVertexId = v83;
          BYTE1(m_pMemory->m_NormalDelta.x) = 0;
          if ( v89 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v90 = m_pMemory[1].m_nVertexId;
          LODWORD(v122) = *(__int16 *)(LODWORD(m_pMemory[1].m_PositionDelta.z) + v90);
          v91 = (double)SLODWORD(v122);
          m_pMemory[1].m_nVertexId = v90 + 2;
          *(float *)&v112.m_nAllocationCount = v91 * sfactor;
          if ( GFxStream::IsVerboseParse(this: (GFxStream *)m_pMemory) )
            GFxLogBase<GFxStream>::LogParse(
              this: (tagBITMAPINFOHEADER *)m_pMemory,
              a2: (int)&stru_102A95E8.m_pElements,
              v79,
              v82,
              (int)*(float *)&v112.m_nAllocationCount);
          GFxFontCompactor::AddKerningPair(
            this: (GFxFontCompactor *)&v100,
            a2: v79,
            a3: v82,
            a4: (int)(nominalSize * (int)*(float *)&v112.m_nAllocationCount) / 1024);
          --*(_DWORD *)val;
        }
        while ( *(_DWORD *)val != 0 );
      }
    }
    GFxFontCompactor::EndFont(this: &v100, i: (int)v92);
    GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::AcquireFont(
      this: (int)&v116[3].m_nGrowSize,
      startPos: 0);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v112.m_nGrowSize);
    v52 = (void *)((int)v112.m_pMemory & 0xFFFFFFFC);
    v53 = InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v112.m_pMemory & 0xFFFFFFFC) + 4), Value: -1);
    goto LABEL_156;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153FC0
// Name: public: void GFxFontResource::AddDisposeHandler(class GFxFontResource::DisposeHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontResource::AddDisposeHandler(GFxFontResource *this, struct GFxFontResource::DisposeHandler *a2)
{
  IScaleformUI *v3; // eax
  CVertexBuilder *v4; // edi
  unsigned int v5; // esi
  _DWORD *v6; // eax
  int v7; // [esp+0h] [ebp-Ch]
  wchar_t val[2]; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 9) == 0 )
  {
    *((_DWORD *)this + 9) = a2;
    return;
  }
  if ( *((_BYTE *)this + 32) == 0 )
  {
    *(_DWORD *)val = *((_DWORD *)this + 9);
    v9 = 2;
    v3 = (IScaleformUI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v9);
    if ( v3 != nullptr )
    {
      v3->__vftable = nullptr;
      v3[1].__vftable = nullptr;
      v3[2].__vftable = nullptr;
    }
    else
    {
      v3 = nullptr;
    }
    *((_DWORD *)this + 9) = v3;
    if ( v3 == nullptr )
      return;
    GArrayBase<GArrayData<unsigned int,GAllocatorGH<unsigned int,2>,GArrayDefaultPolicy>>::PushBack(
      this: v3,
      (GTexture::ChangeHandler *const *)val,
      a3: v7);
    *((_BYTE *)this + 32) = 1;
  }
  v4 = *((CVertexBuilder **)this + 9);
  v5 = v4->m_VertexSize_BoneWeight + 1;
  if ( v5 >= v4->m_VertexSize_BoneWeight )
  {
    if ( v5 >= v4->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        pheapAddr: (ButtonCode_t)v4,
        newCapacity: v5 + (v5 >> 2));
  }
  else if ( v5 < (unsigned int)v4->m_VertexSize_BoneMatrixIndex >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      pheapAddr: (ButtonCode_t)v4,
      newCapacity: v4->m_VertexSize_BoneWeight + 1);
  }
  v6 = (_DWORD *)(v4->m_VertexSize_Position + 4 * v5 - 4);
  v4->m_VertexSize_BoneWeight = v5;
  if ( v6 != nullptr )
    *v6 = a2;
}

//------------------------------------------------------------------------------
// Address: 0x10154080
// Name: GetGlyphShape_GFxFontDataCompactedSwf_
// Source: json
//------------------------------------------------------------------------------
GFxShapeNoStyles *__usercall GetGlyphShape_GFxFontDataCompactedSwf_@<eax>(unsigned int a1@<eax>, int a2@<ecx>, int a3@<edi>)
{
  int v5; // edi
  GFxShapeNoStyles *v6; // eax
  GFxShapeNoStyles *v7; // esi
  unsigned int v8; // esi
  HRESULT (__stdcall *QueryInterface)(IUnknown *, const _GUID *, void **); // edx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int UInt30; // eax
  int v18; // eax
  CStridedConstPtr<__m128> v20; // [esp+4h] [ebp-7Ch] BYREF
  void *v21; // [esp+20h] [ebp-60h]
  int v22; // [esp+2Ch] [ebp-54h]
  IUnknown v23; // [esp+3Ch] [ebp-44h] BYREF
  unsigned int v24; // [esp+40h] [ebp-40h]
  int v25; // [esp+4Ch] [ebp-34h]
  int v26; // [esp+50h] [ebp-30h]
  int v27; // [esp+54h] [ebp-2Ch]
  unsigned int v28; // [esp+58h] [ebp-28h] BYREF
  unsigned int v29; // [esp+5Ch] [ebp-24h]
  char v30; // [esp+60h] [ebp-20h]
  int data; // [esp+64h] [ebp-1Ch] BYREF
  int v32; // [esp+68h] [ebp-18h]
  int v33; // [esp+6Ch] [ebp-14h]
  int v34; // [esp+70h] [ebp-10h]
  int v35; // [esp+74h] [ebp-Ch]
  int v36; // [esp+78h] [ebp-8h] BYREF
  char v37; // [esp+7Fh] [ebp-1h]

  if ( a1 >= *(_DWORD *)(a2 + 56) )
    return nullptr;
  v23.__vftable = (IUnknown_vtbl *)(a2 + 28);
  GFxCompactedFont<GArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphShape(
    this: (_DWORD *)(a2 + 44),
    result: a1,
    glyph: &v23);
  v5 = *(_DWORD *)(a2 + 88);
  v36 = 258;
  v6 = (GFxShapeNoStyles *)((int (__thiscall *)(GMemoryHeap *, int, int, int *, int))GMemory::pGlobalHeap->AllocAutoHeap_2)(
                             a1: GMemory::pGlobalHeap,
                             a2,
                             a3: 68,
                             a4: &v36,
                             a5: a3);
  if ( v6 != nullptr )
  {
    v7 = GFxShapeNoStyles::GFxShapeNoStyles(this: v6, a2: 0xF2u);
    v36 = (int)v7;
  }
  else
  {
    v36 = 0;
    v7 = nullptr;
  }
  GFxPathPacker::GFxPathPacker(this: (GFxPathPacker *)&v20);
  v37 = 0;
  if ( v27 == 0 )
    goto LABEL_29;
  v8 = v24;
  do
  {
    GFxPathPacker::Reset(this: (GFxPathPacker *)&v20);
    v20.m_pData = (const __m128 *)1;
    v20.m_nStride = 0;
    GFxPathPacker::SetMoveTo(this: &v20);
    if ( v28 != 0 )
    {
      do
      {
        GFxGlyphPathIterator<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(this: (int)&v23, &data);
        if ( data == 2 )
          GFxPathPacker::LineToAbs(this: (CSOAAttributeReference *)&v20, x: COERCE_FLOAT((v32 << 10) / v5));
        else
          GFxPathPacker::CurveToAbs(
            this: (GFxPathPacker *)&v20,
            a2: (v32 << 10) / v5,
            a3: (v33 << 10) / v5,
            a4: (v34 << 10) / v5,
            a5: (v35 << 10) / v5);
      }
      while ( v28 != 0 );
      v8 = v24;
    }
    if ( v22 != 0 )
    {
      GFxPathPacker::ClosePath(this: (GFxPathPacker *)&v20);
      if ( v22 != 0 )
        GFxPathPacker::Pack(this: &v20);
      v37 = 1;
    }
    if ( --v27 == 0 )
      break;
    QueryInterface = v23.__vftable[1].QueryInterface;
    v10 = *(char *)(*((_DWORD *)QueryInterface + (v8 >> 12)) + (v8 & 0xFFF));
    if ( (v10 & 1) != 0 )
    {
      v12 = (v10 >> 1) & 0x7F | (*(char *)(*((_DWORD *)QueryInterface + ((v8 + 1) >> 12)) + ((v8 + 1) & 0xFFF)) << 7);
      v11 = 2;
      v25 = v12;
    }
    else
    {
      v25 = v10 >> 1;
      v11 = 1;
    }
    v13 = v11 + v8;
    v14 = *(char *)(*((_DWORD *)QueryInterface + (v13 >> 12)) + (v13 & 0xFFF));
    if ( (v14 & 1) != 0 )
    {
      v16 = (v14 >> 1) & 0x7F | (*(char *)(*((_DWORD *)QueryInterface + ((v13 + 1) >> 12)) + ((v13 + 1) & 0xFFF)) << 7);
      v15 = 2;
      v26 = v16;
    }
    else
    {
      v26 = v14 >> 1;
      v15 = 1;
    }
    v24 = v15 + v13;
    UInt30 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
               this: (int *)&v23,
               a2: v15 + v13,
               a3: (int *)&v28);
    v8 = UInt30 + v24;
    v24 = v8;
    v29 = v8;
    v30 = 1;
    if ( (v28 & 1) != 0 )
    {
      v29 = v28 >> 1;
      v18 = GFxPathDataDecoder<GArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
              this: (int *)&v23,
              a2: v28 >> 1,
              a3: (int *)&v28);
      v29 += v18;
      v8 = v24;
      v30 = 0;
    }
    v28 >>= 1;
  }
  while ( v27 != 0 );
  v7 = (GFxShapeNoStyles *)v36;
  if ( v37 == 0 )
  {
LABEL_29:
    if ( v7 != nullptr )
      (**(void (__thiscall ***)(_DWORD, int))v7)(a1: v7, a2: 1);
    v7 = nullptr;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10154300
// Name: GetCharRanges_GFxFontDataCompactedSwf_
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__usercall GetCharRanges_GFxFontDataCompactedSwf_@<eax>(
        _DWORD *a1@<eax>,
        CUtlMemory<CImagePacker,int> *a2)
{
  int (__thiscall *v3)(_DWORD *); // edx
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned __int16 v6; // bx
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned __int16 *v9; // edi
  unsigned __int16 *v10; // esi
  unsigned __int16 *v12; // [esp+8h] [ebp-20h] BYREF
  unsigned int v13; // [esp+Ch] [ebp-1Ch]
  unsigned int v14; // [esp+10h] [ebp-18h]
  int v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch]
  unsigned int v18; // [esp+20h] [ebp-8h]
  char v19; // [esp+27h] [ebp-1h]

  v3 = *(int (__thiscall **)(_DWORD *))(*a1 + 56);
  v4 = 0;
  v12 = nullptr;
  v13 = 0;
  v14 = 0;
  v17 = 0;
  v15 = 0;
  v19 = 0;
  v18 = 0;
  if ( v3(a1) == 0 )
    goto LABEL_23;
  do
  {
    if ( v19 == 0 )
    {
      v5 = a1[15] + 8 * v4;
      v17 = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1[13] + 12) + 4 * (v5 >> 12)) + (v5 & 0xFFF))
                             | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1[13] + 12) + 4 * ((v5 + 1) >> 12))
                                                   + ((v5 + 1) & 0xFFF)) << 8));
      v19 = 1;
LABEL_4:
      v6 = *(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1[13] + 12) + 4 * (v5 >> 12)) + (v5 & 0xFFF))
         | (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1[13] + 12) + 4 * ((v5 + 1) >> 12)) + ((v5 + 1) & 0xFFF)) << 8);
      v4 = v18 + 1;
      v15 = v6;
      ++v18;
      continue;
    }
    v5 = a1[15] + 8 * v4;
    v6 = v15;
    if ( (unsigned __int16)v15 == (*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1[13] + 12) + 4 * (v5 >> 12))
                                                      + (v5 & 0xFFF))
                                 | (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1[13] + 12)
                                                                                     + 4 * ((v5 + 1) >> 12))
                                                                         + ((v5 + 1) & 0xFFF)) << 8))
                                - 1 )
      goto LABEL_4;
    LOWORD(v16) = v17;
    v8 = v13 + 1;
    HIWORD(v16) = v15;
    if ( v13 + 1 >= v13 )
    {
      if ( v8 >= v14 )
        GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
          this: (CVertexBuilder *)&v12,
          pheapAddr: (ButtonCode_t)&v12,
          newCapacity: v8 + (v8 >> 2));
    }
    else if ( v8 < v14 >> 1 )
    {
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: (CVertexBuilder *)&v12,
        pheapAddr: (ButtonCode_t)&v12,
        newCapacity: v13 + 1);
    }
    v13 = v8;
    v9 = &v12[2 * v8 - 2];
    if ( v9 != nullptr )
      *(_DWORD *)v9 = v16;
    v4 = v18;
    v19 = 0;
  }
  while ( v4 < (*(int (__thiscall **)(_DWORD *))(*a1 + 56))(a1) );
  if ( v19 != 0 )
  {
    v7 = v13 + 1;
    LOWORD(v15) = v17;
    HIWORD(v15) = v6;
    if ( v13 + 1 >= v13 )
    {
      if ( v7 >= v14 )
        GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
          this: (CVertexBuilder *)&v12,
          pheapAddr: (ButtonCode_t)&v12,
          newCapacity: v7 + (v7 >> 2));
    }
    else if ( v7 < v14 >> 1 )
    {
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: (CVertexBuilder *)&v12,
        pheapAddr: (ButtonCode_t)&v12,
        newCapacity: v13 + 1);
    }
    v13 = v7;
    v10 = &v12[2 * v7 - 2];
    if ( v10 != nullptr )
      *(_DWORD *)v10 = v15;
  }
LABEL_23:
  LOBYTE(v15) = 0;
  G_QuickSortSliced<GArray<`anonymous namespace'::Range,2,GArrayDefaultPolicy>,`anonymous namespace'::RangeLess>(
    a1: &v12,
    a2: 0,
    a3: v13);
  BuildStringFromRanges(a1: &v12, a2, a3: 0);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10154530
// Name: GetGlyphShape_GFxFontDataCompactedGfx_
// Source: json
//------------------------------------------------------------------------------
GFxShapeNoStyles *__usercall GetGlyphShape_GFxFontDataCompactedGfx_@<eax>(unsigned int a1@<eax>, int a2@<ecx>, int a3@<edi>)
{
  int v5; // edi
  GFxShapeNoStyles *v6; // eax
  GFxShapeNoStyles *v7; // esi
  char v8; // bl
  CStridedConstPtr<__m128> v10; // [esp+4h] [ebp-78h] BYREF
  void *v11; // [esp+20h] [ebp-5Ch]
  int v12; // [esp+2Ch] [ebp-50h]
  IStorage glyph; // [esp+3Ch] [ebp-40h] BYREF
  int v14; // [esp+54h] [ebp-28h]
  int v15; // [esp+58h] [ebp-24h]
  int data; // [esp+64h] [ebp-18h] BYREF
  int v17; // [esp+68h] [ebp-14h]
  int v18; // [esp+6Ch] [ebp-10h]
  int v19; // [esp+70h] [ebp-Ch]
  int v20; // [esp+74h] [ebp-8h]
  int v21; // [esp+78h] [ebp-4h] BYREF

  if ( a1 >= *(_DWORD *)(a2 + 52) )
    return nullptr;
  glyph.__vftable = (IStorage_vtbl *)(a2 + 28);
  GFxCompactedFont<GArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphShape(
    this: a2 + 40,
    glyphIndex: a1,
    (IStorage)&glyph);
  v5 = *(_DWORD *)(a2 + 84);
  v21 = 258;
  v6 = (GFxShapeNoStyles *)((int (__thiscall *)(GMemoryHeap *, int, int, int *, int))GMemory::pGlobalHeap->AllocAutoHeap_2)(
                             a1: GMemory::pGlobalHeap,
                             a2,
                             a3: 68,
                             a4: &v21,
                             a5: a3);
  if ( v6 != nullptr )
    v7 = GFxShapeNoStyles::GFxShapeNoStyles(this: v6, a2: 0xF2u);
  else
    v7 = nullptr;
  GFxPathPacker::GFxPathPacker(this: (GFxPathPacker *)&v10);
  v8 = 0;
  if ( v14 == 0 )
    goto LABEL_18;
  do
  {
    GFxPathPacker::Reset(this: (GFxPathPacker *)&v10);
    v10.m_pData = (const __m128 *)1;
    v10.m_nStride = 0;
    GFxPathPacker::SetMoveTo(this: &v10);
    while ( v15 != 0 )
    {
      GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(this: (int)&glyph, &data);
      if ( data == 2 )
        GFxPathPacker::LineToAbs(this: (CSOAAttributeReference *)&v10, x: COERCE_FLOAT((v17 << 10) / v5));
      else
        GFxPathPacker::CurveToAbs(
          this: (GFxPathPacker *)&v10,
          a2: (v17 << 10) / v5,
          a3: (v18 << 10) / v5,
          a4: (v19 << 10) / v5,
          a5: (v20 << 10) / v5);
    }
    if ( v12 != 0 )
    {
      GFxPathPacker::ClosePath(this: (GFxPathPacker *)&v10);
      if ( v12 != 0 )
        GFxPathPacker::Pack(this: &v10);
      v8 = 1;
    }
    --v14;
    GFxGlyphPathIterator<GArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(this: (int)&glyph);
  }
  while ( v14 != 0 );
  if ( v8 == 0 )
  {
LABEL_18:
    if ( v7 != nullptr )
      (**(void (__thiscall ***)(_DWORD, int))v7)(a1: v7, a2: 1);
    v7 = nullptr;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101546B0
// Name: GetCharRanges_GFxFontDataCompactedGfx_
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__usercall GetCharRanges_GFxFontDataCompactedGfx_@<eax>(
        int a1@<eax>,
        CUtlMemory<CImagePacker,int> *a2)
{
  int (__thiscall *v3)(int); // edx
  unsigned __int16 *v4; // edi
  unsigned int v5; // ebx
  int v6; // ecx
  int v7; // eax
  __int16 v8; // dx
  int v9; // ecx
  unsigned __int16 v10; // dx
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned __int16 *v13; // esi
  unsigned __int16 *v15; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+10h] [ebp-18h]
  unsigned int v17; // [esp+14h] [ebp-14h]
  int v18; // [esp+18h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-Ch]
  int v20; // [esp+20h] [ebp-8h]
  char v21; // [esp+27h] [ebp-1h]

  v3 = *(int (__thiscall **)(int))(*(_DWORD *)a1 + 56);
  LOWORD(v4) = 0;
  v15 = nullptr;
  v16 = 0;
  v17 = 0;
  v20 = 0;
  v19 = 0;
  v21 = 0;
  v5 = 0;
  if ( v3(a1) == 0 )
    goto LABEL_25;
  while ( 1 )
  {
    v6 = **(_DWORD **)(a1 + 48);
    v7 = *(_DWORD *)(a1 + 56) + 8 * v5;
    v8 = *(unsigned __int8 *)(v6 + v7 + 1);
    v9 = *(unsigned __int8 *)(v6 + v7);
    v10 = v8 << 8;
    if ( v21 == 0 )
    {
      v20 = (unsigned __int16)(v9 | v10);
      v21 = 1;
LABEL_6:
      v19 = *(unsigned __int16 *)(v7 + **(_DWORD **)(a1 + 48));
      ++v5;
      goto LABEL_7;
    }
    if ( (unsigned __int16)v4 == (v9 | v10) - 1 )
      goto LABEL_6;
    HIWORD(v18) = (_WORD)v4;
    v12 = v16 + 1;
    LOWORD(v18) = v20;
    if ( v16 + 1 >= v16 )
    {
      if ( v12 >= v17 )
        GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
          this: (CVertexBuilder *)&v15,
          pheapAddr: (ButtonCode_t)&v15,
          newCapacity: v12 + (v12 >> 2));
    }
    else if ( v12 < v17 >> 1 )
    {
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: (CVertexBuilder *)&v15,
        pheapAddr: (ButtonCode_t)&v15,
        newCapacity: v16 + 1);
    }
    v16 = v12;
    v4 = &v15[2 * v12 - 2];
    if ( v4 != nullptr )
      *(_DWORD *)v4 = v18;
    v21 = 0;
LABEL_7:
    if ( v5 >= (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 56))(a1) )
      break;
    LOWORD(v4) = v19;
  }
  if ( v21 != 0 )
  {
    v11 = v16 + 1;
    LOWORD(v18) = v20;
    HIWORD(v18) = v19;
    if ( v16 + 1 >= v16 )
    {
      if ( v11 >= v17 )
        GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
          this: (CVertexBuilder *)&v15,
          pheapAddr: (ButtonCode_t)&v15,
          newCapacity: v11 + (v11 >> 2));
    }
    else if ( v11 < v17 >> 1 )
    {
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: (CVertexBuilder *)&v15,
        pheapAddr: (ButtonCode_t)&v15,
        newCapacity: v16 + 1);
    }
    v16 = v11;
    v13 = &v15[2 * v11 - 2];
    if ( v13 != nullptr )
      *(_DWORD *)v13 = v18;
  }
LABEL_25:
  LOBYTE(v18) = 0;
  G_QuickSortSliced<GArray<`anonymous namespace'::Range,2,GArrayDefaultPolicy>,`anonymous namespace'::RangeLess>(
    a1: &v15,
    a2: 0,
    a3: v16);
  BuildStringFromRanges(a1: &v15, a2, a3: (unsigned __int16)v4);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10154AF0
// Name: public: virtual float GFxFontData::GetKerningAdjustment(unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxFontData::GetKerningAdjustment(
        GFxFontData *this,
        const CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>::Iterator_t *k,
        __int16 code)
{
  int v3; // eax

  HIWORD(k) = code;
  v3 = GHashSetBase<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeHashF,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeAltHashF,GAllocatorLH<GFxFontData::KerningPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeHashF>>::GetAlt<GFxFontData::KerningPair>(a1: &k);
  if ( v3 == 0 )
    return 0.0;
  k = *(const CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>::Iterator_t **)(v3 + 4);
  return *(float *)&k;
}

//------------------------------------------------------------------------------
// Address: 0x10154B30
// Name: public: virtual class GFxShapeBase __near * GFxFontDataCompactedSwf::GetGlyphShape(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxFontDataCompactedSwf::GetGlyphShape(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this@<ecx>,
        int a2@<edi>,
        const CVertexMorphDict::MorphVertexList_t *glyphIndex,
        unsigned int __formal)
{
  GetGlyphShape_GFxFontDataCompactedSwf_(a1: (unsigned int)glyphIndex, a2: (int)this, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10154B40
// Name: public: virtual class GString GFxFontDataCompactedSwf::GetCharRanges(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__thiscall GFxFontDataCompactedSwf::GetCharRanges(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  GetCharRanges_GFxFontDataCompactedSwf_(a1: this, a2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10154B60
// Name: public: virtual class GFxShapeBase __near * GFxFontDataCompactedGfx::GetGlyphShape(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxShapeNoStyles *__userpurge GFxFontDataCompactedGfx::GetGlyphShape@<eax>(tagEXCEPINFO *this@<ecx>, int a2@<edi>, unsigned int glyphIndex, unsigned int __formal)
{
  return GetGlyphShape_GFxFontDataCompactedGfx_(a1: glyphIndex, a2: (int)this, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10154B70
// Name: public: virtual class GString GFxFontDataCompactedGfx::GetCharRanges(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxFontDataCompactedGfx::GetCharRanges(
        GFxFontDataCompactedGfx *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  GetCharRanges_GFxFontDataCompactedGfx_(a1: (int)this, a2);
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10154B90
// Name: public: void GFxFontResource::RemoveDisposeHandler(class GFxFontResource::DisposeHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontResource::RemoveDisposeHandler(
        GFxFontResource *this,
        struct GFxFontResource::DisposeHandler *a2)
{
  CThread *v3; // ecx
  const char *v4; // edi
  void **v5; // edi
  void (__thiscall *dtr_CThread)(CThread *); // ebx

  if ( *((_BYTE *)this + 32) != 0 )
  {
    v3 = *((CThread **)this + 9);
    v4 = nullptr;
    if ( *(_DWORD *)v3->m_Lock.m_CriticalSection != 0 )
    {
      while ( 1 )
      {
        if ( *((struct GFxFontResource::DisposeHandler **)&v3->dtr_CThread + (_DWORD)v4) == a2 )
        {
          GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::RemoveAt(
            this: v3,
            index: v4);
          v3 = *((CThread **)this + 9);
          if ( *(_DWORD *)v3->m_Lock.m_CriticalSection == 1 )
            break;
        }
        if ( (unsigned int)++v4 >= *(_DWORD *)(*((_DWORD *)this + 9) + 4) )
          return;
      }
      v5 = *((void ***)this + 9);
      dtr_CThread = v3->dtr_CThread;
      if ( v5 != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v5);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      }
      *((_DWORD *)this + 9) = dtr_CThread;
      *((_BYTE *)this + 32) = 0;
    }
  }
  else if ( *((struct GFxFontResource::DisposeHandler **)this + 9) == a2 )
  {
    *((_DWORD *)this + 9) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154EE0
// Name: public: void GFxTextureGlyphData::AddTextureGlyph(unsigned int,class GFxTextureGlyph const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextureGlyphData::AddTextureGlyph(
        GFxTextureGlyphData *this,
        unsigned int a2,
        CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *result)
{
  unsigned int v3; // esi
  unsigned int v4; // ebx
  _DWORD *v5; // edi
  GFxTextureGlyphData *v6; // [esp+4h] [ebp-4h]

  v3 = a2;
  v6 = this;
  if ( *((_DWORD *)this + 9) > a2 )
    goto LABEL_6;
  v4 = *((_DWORD *)this + 9);
  v5 = (_DWORD *)((char *)this + 32);
  GArrayDataBase<GFxTextureGlyph,GAllocatorLH<GFxTextureGlyph,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (CMorph *)((char *)this + 32),
    pheapAddr: (const GRenderer::FillTexture *)((char *)this + 32),
    newSize: a2 + 1);
  if ( a2 + 1 > v4 )
    GConstructorMov<GFxTextureGlyph>::ConstructArray(a1: *v5 + 40 * v4, a2: a2 + 1 - v4);
  this = v6;
  if ( *((_DWORD *)v6 + 9) > a2 )
  {
    v3 = a2;
LABEL_6:
    GFxTextureGlyph::operator=(this: *((_DWORD *)this + 8) + 40 * v3, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154F50
// Name: public: virtual int GFxFontData::GetGlyphIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontData::GetGlyphIndex(CMorph *this, unsigned __int16 code)
{
  ITextureInternal *v2; // esi
  int Index; // eax
  int v4; // eax

  v2 = this->m_pMorphTexture[0];
  if ( v2 != nullptr
    && (Index = GHashSetBase<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeHashF,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeAltHashF,GAllocatorLH<unsigned short,2>,GHashsetNodeEntry<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeHashF>>::findIndexCore<unsigned short>(
                  a1: &code,
                  a2: code & (int)v2[1].__vftable)) >= 0
    && (v4 = (int)&v2[2 * Index + 3]) != 0 )
  {
    return *(unsigned __int16 *)(v4 + 2);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155040
// Name: public: GFxFontData::GFxFontData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontData::GFxFontData(CMorph *this)
{
  *(float *)&this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory = 0.0;
  this->IMorphInternal::IMorph::__vftable = (CMorph_vtbl *)&GRefCountImplCore::`vftable';
  *(float *)&this->m_MorphDict.m_MorphLists.m_Memory.m_nAllocationCount = 0.0;
  *(float *)&this->m_MorphDict.m_MorphLists.m_Memory.m_nGrowSize = 0.0;
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)1;
  this->m_MorphDict.m_MorphLists.m_Size = 0;
  this->IMorphInternal::IMorph::__vftable = (CMorph_vtbl *)&GFxFontData::`vftable';
  this->m_MorphDict.m_MorphLists.m_pElements = nullptr;
  this->m_MorphDict.m_MorphLists.m_pLessContext = nullptr;
  *(_DWORD *)&this->m_MorphDict.m_MorphLists.m_bNeedsSort = 0;
  *(_DWORD *)&this->m_bLocked = 0;
  this->m_Format = 0;
  this->m_pMorphTexture[0] = nullptr;
  this->m_pMorphTexture[1] = nullptr;
  this->m_pMorphBuffer = nullptr;
  this->m_MorphQuads.m_Memory.m_pMemory = nullptr;
  this->m_MorphQuads.m_Memory.m_nAllocationCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10155090
// Name: public: virtual void GFxFontData::SetTextureGlyphData(class GFxTextureGlyphData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontData::SetTextureGlyphData(GFxFontData *this, struct GFxTextureGlyphData *a2)
{
  GRefCountNTSImpl *v3; // ecx

  if ( a2 != nullptr )
    ++*((_DWORD *)a2 + 1);
  v3 = *((GRefCountNTSImpl **)this + 7);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  *((_DWORD *)this + 7) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x101550C0
// Name: public: virtual bool GFxFontData::HasVectorOrRasterGlyphs(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxFontData::HasVectorOrRasterGlyphs(CMorph *this)
{
  ITextureInternal *v1; // eax

  v1 = this->m_pMorphTexture[0];
  return v1 != nullptr && v1->__vftable != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101550E0
// Name: public: GFxFontData::GFxFontData(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxFontData *__thiscall GFxFontData::GFxFontData(GFxFontData *this, char *_Src, unsigned int a3)
{
  char *v4; // edi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  *((float *)this + 2) = 0.0;
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((float *)this + 3) = 0.0;
  *((_DWORD *)this + 5) = a3;
  *((float *)this + 4) = 0.0;
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxFontData::`vftable';
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  v6 = 261;
  v4 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: strlen(_Src) + 1, a3: &v6);
  *((_DWORD *)this + 6) = v4;
  if ( v4 != nullptr )
    strcpy_s(_Dst: v4, _SizeInBytes: strlen(_Src) + 1, _Src);
  *((_DWORD *)this + 5) |= 0x2000u;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101551A0
// Name: public: virtual GFxFontData::~GFxFontData(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall GFxFontData::~GFxFontData(CMorph *this)
{
  bool *p_m_bNeedsSort; // ebx
  int v3; // eax
  GFxShapeBase **v4; // edi
  GRefCountNTSImpl *m_pLessContext; // ecx
  const GFxExternalInterface *v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-4h]

  p_m_bNeedsSort = &this->m_MorphDict.m_MorphLists.m_bNeedsSort;
  this->IMorphInternal::IMorph::__vftable = (CMorph_vtbl *)&GFxFontData::`vftable';
  GArrayDataBase<GPtr<GFxShapeBase>,GAllocatorLH<GPtr<GFxShapeBase>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GStatInfo *)&this->m_MorphDict.m_MorphLists.m_bNeedsSort,
    pheapAddr: &this->m_MorphDict.m_MorphLists.m_bNeedsSort,
    newSize: 0);
  if ( this->m_MorphDict.m_MorphLists.m_pElements != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->m_MorphDict.m_MorphLists.m_pElements);
    this->m_MorphDict.m_MorphLists.m_pElements = nullptr;
  }
  GHashSetBase<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeHashF,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeAltHashF,GAllocatorLH<GFxFontData::KerningPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeHashF>>::Clear(
    this: (GFxExternalInterface *)&this->m_MorphQuads.m_Memory.m_nAllocationCount,
    a2: v7);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->m_pMorphTexture[1]);
  GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc>>::Clear(this: (IMaterialSystem *)this->m_pMorphTexture);
  v3 = *((_DWORD *)p_m_bNeedsSort + 1);
  v4 = (GFxShapeBase **)(*(_DWORD *)p_m_bNeedsSort + 4 * v3 - 4);
  if ( v3 != 0 )
  {
    v8 = *((_DWORD *)p_m_bNeedsSort + 1);
    do
    {
      if ( *v4 != nullptr )
        GFxShapeBase::Release(this: *v4);
      --v4;
      --v8;
    }
    while ( v8 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)p_m_bNeedsSort);
  m_pLessContext = (GRefCountNTSImpl *)this->m_MorphDict.m_MorphLists.m_pLessContext;
  if ( m_pLessContext != nullptr )
    GRefCountNTSImpl::Release(this: m_pLessContext);
  this->IMorphInternal::IMorph::__vftable = (CMorph_vtbl *)&GFxFont::`vftable';
  return GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10155260
// Name: private: void GFxFontData::ReadCodeTable(class GFxStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontData::ReadCodeTable(GFxFontData *this, tagBITMAPINFOHEADER *a2)
{
  tagBITMAPINFOHEADER *v2; // esi
  int v4; // eax
  unsigned int v5; // edi
  GColor *v6; // ebx
  int v7; // edx
  int biWidth; // eax
  int v9; // edx
  GColor *v10; // ebx
  int v11; // edx
  int v12; // eax
  unsigned __int8 v13; // cl
  _cpinfo *v14; // [esp+0h] [ebp-1Ch]
  int v15; // [esp+Ch] [ebp-10h] BYREF
  tagBITMAPINFOHEADER **v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int v18; // [esp+18h] [ebp-4h] BYREF

  v2 = a2;
  GFxLogBase<GFxStream>::LogParse(
    this: a2,
    a2: (int)"reading code table at offset %d\n",
    a2[1].biWidth + *(_DWORD *)&a2[1].biPlanes - a2[1].biHeight);
  v4 = *((_DWORD *)this + 9);
  v5 = 0;
  if ( (*((_DWORD *)this + 5) & 0x4000) != 0 )
  {
    v17 = *((_DWORD *)this + 9);
    if ( v4 != 0 )
    {
      v6 = (GColor *)((char *)this + 44);
      v15 = (int)&v18;
      v16 = &a2;
      do
      {
        v7 = v2[1].biHeight - v2[1].biWidth;
        a2 = (tagBITMAPINFOHEADER *)(unsigned __int16)v5;
        BYTE1(v2->biSizeImage) = 0;
        if ( v7 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        biWidth = v2[1].biWidth;
        v9 = *(unsigned __int16 *)(v2[1].biSizeImage + biWidth);
        v2[1].biWidth = biWidth + 2;
        v18 = v9;
        GHashSetBase<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeHashF,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeAltHashF,GAllocatorLH<unsigned short,2>,GHashsetNodeEntry<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeHashF>>::add<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeRef>(
          this: v6,
          a2: (int)v6,
          a3: (int)&v15,
          a4: v9);
        ++v5;
      }
      while ( v5 < v17 );
    }
  }
  else
  {
    v18 = *((_DWORD *)this + 9);
    if ( v4 != 0 )
    {
      v10 = (GColor *)((char *)this + 44);
      v15 = (int)&v17;
      v16 = &a2;
      do
      {
        v11 = v2[1].biHeight - v2[1].biWidth;
        a2 = (tagBITMAPINFOHEADER *)(unsigned __int16)v5;
        BYTE1(v2->biSizeImage) = 0;
        if ( v11 < 1 )
          GFxStream::PopulateBuffer1(result: v14);
        v12 = v2[1].biWidth;
        v13 = *(_BYTE *)(v12 + v2[1].biSizeImage);
        v2[1].biWidth = v12 + 1;
        v17 = v13;
        GHashSetBase<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeHashF,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeAltHashF,GAllocatorLH<unsigned short,2>,GHashsetNodeEntry<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>,GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeHashF>>::add<GHashNode<unsigned short,unsigned short,GIdentityHash<unsigned short>>::NodeRef>(
          this: v10,
          a2: (int)v10,
          a3: (int)&v15,
          a4: v13);
        ++v5;
      }
      while ( v5 < v18 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101553B0
// Name: public: void GFxFontData::ReadFontInfo(class GFxStream __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxFontData::ReadFontInfo(
        CMorph *this@<ecx>,
        IShaderDeviceMgr *in,
        int tagType,
        int langCode,
        int a5,
        int *a6,
        const MorphWeight_t *a7)
{
  CVertexMorphDict::MorphVertexList_t *m_pElements; // eax
  CVertexMorphDict::MorphVertexList_t *v10; // eax
  int v11; // ecx
  IMatRenderContext_vtbl *v12; // eax
  char v13; // bl
  IMatRenderContext_vtbl *v14; // eax
  int v15; // ecx
  IMatRenderContext_vtbl *v16; // eax
  const char *v17; // eax
  int m_Size; // eax
  const char *v19; // edx
  _cpinfo *v20; // [esp+0h] [ebp-Ch]
  unsigned __int8 langCodea; // [esp+17h] [ebp+Bh]

  m_pElements = this->m_MorphDict.m_MorphLists.m_pElements;
  if ( m_pElements != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: m_pElements);
    this->m_MorphDict.m_MorphLists.m_pElements = nullptr;
  }
  GFxStream::ReadStringWithLength(this: in);
  this->m_MorphDict.m_MorphLists.m_pElements = v10;
  v11 = (char *)in[12].__vftable - (char *)in[11].__vftable;
  BYTE1(in[5].__vftable) = 0;
  if ( v11 < 1 )
    GFxStream::PopulateBuffer1(result: v20);
  v12 = (IMatRenderContext_vtbl *)in[11].__vftable;
  v13 = *((_BYTE *)&v12->AddRef + (unsigned int)in[15].__vftable);
  v14 = (IMatRenderContext_vtbl *)((char *)&v12->AddRef + 1);
  in[11].__vftable = (IShaderDeviceMgr_vtbl *)v14;
  langCodea = 0;
  if ( tagType == 62 )
  {
    v15 = (char *)in[12].__vftable - (char *)v14;
    BYTE1(in[5].__vftable) = 0;
    if ( v15 < 1 )
      GFxStream::PopulateBuffer1(result: v20);
    v16 = (IMatRenderContext_vtbl *)in[11].__vftable;
    langCodea = *((_BYTE *)&v16->AddRef + (unsigned int)in[15].__vftable);
    in[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v16->AddRef + 1);
  }
  if ( (v13 & 0x10) != 0 )
  {
    this->m_MorphDict.m_MorphLists.m_Size = this->m_MorphDict.m_MorphLists.m_Size & 0xFFFFFCFF | 0x200;
  }
  else if ( (v13 & 8) != 0 )
  {
    this->m_MorphDict.m_MorphLists.m_Size = this->m_MorphDict.m_MorphLists.m_Size & 0xFFFFFCFF | 0x100;
  }
  else
  {
    this->m_MorphDict.m_MorphLists.m_Size &= 0xFFFFFCFF;
  }
  if ( (v13 & 4) != 0 )
    this->m_MorphDict.m_MorphLists.m_Size |= 1u;
  else
    this->m_MorphDict.m_MorphLists.m_Size &= ~1u;
  if ( (v13 & 2) != 0 )
    this->m_MorphDict.m_MorphLists.m_Size |= 2u;
  else
    this->m_MorphDict.m_MorphLists.m_Size &= ~2u;
  if ( (v13 & 1) != 0 )
    this->m_MorphDict.m_MorphLists.m_Size |= 0x4000u;
  else
    this->m_MorphDict.m_MorphLists.m_Size &= ~0x4000u;
  if ( GFxStream::IsVerboseParse(this: (GFxStream *)in) )
  {
    if ( tagType == 13 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)in, a2: (int)"reading DefineFontInfo\n");
    else
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)in, a2: (int)"reading DefineFontInfo2\n");
    v17 = (const char *)this->m_MorphDict.m_MorphLists.m_pElements;
    if ( v17 == nullptr )
      v17 = "(none)";
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)in, a2: (int)"  Name = %s\n", v17);
    m_Size = this->m_MorphDict.m_MorphLists.m_Size;
    v19 = "Unicode";
    if ( (m_Size & 0x300) == 0x200 )
    {
      v19 = "ShiftJIS";
    }
    else if ( (m_Size & 0x300) == 0x100 )
    {
      v19 = "ANSI";
    }
    GFxLogBase<GFxStream>::LogParse(
      this: (tagBITMAPINFOHEADER *)in,
      a2: (int)"  CodePage = %s, Italic = %d, Bold = %d\n",
      v19,
      this->m_MorphDict.m_MorphLists.m_Size & 1,
      (m_Size & 2) != 0);
    if ( tagType == 62 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)in, a2: (int)"  LangCode = %d\n", langCodea);
  }
  GFxFontData::ReadCodeTable((GFxFontData *)this, a2: (tagBITMAPINFOHEADER *)in);
}

//------------------------------------------------------------------------------
// Address: 0x10155560
// Name: public: void GFxTextureGlyphData::AddTexture(class GFxResourceId,class GFxImageResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextureGlyphData::AddTexture(
        CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int> *this@<ecx>,
        int textureId,
        CCallQueueT<CTSQueue<CFunctor *,0,1> > pimageRes)
{
  VertexShaderHandle_t__ *v4; // [esp+0h] [ebp-14h]
  _DWORD v5[2]; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  IShaderDevice *pNode; // [esp+10h] [ebp-4h]

  v6 = 0;
  pNode = (IShaderDevice *)pimageRes.m_queue.m_Head.value.pNode;
  if ( pimageRes.m_queue.m_Head.value.pNode != nullptr )
    GRefCountImpl::AddRef(this: (IShaderDevice *)pimageRes.m_queue.m_Head.value.pNode, a2: v4);
  v5[0] = &textureId;
  v5[1] = &v6;
  GHashSetBase<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF>>::Set<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeRef>(
    a1: (char *)this + 44,
    a2: v5);
  if ( v6 == 0 && pNode != nullptr )
    GFxResource::Release(this: pNode);
}

//------------------------------------------------------------------------------
// Address: 0x101555C0
// Name: public: void GFxTextureGlyphData::AddTexture(class GFxResourceId,class GFxResourceHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextureGlyphData::AddTexture(
        CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int> *this,
        const CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int>::Iterator_t *textureId,
        const GenericThreadLocals::CThreadLocal<int> *rh)
{
  const GenericThreadLocals::CThreadLocal<int> *v3; // esi
  bool v4; // zf
  IShaderDevice *m_index; // ecx
  IShaderDevice *v7; // ecx
  unsigned int v8; // eax
  VertexShaderHandle_t__ *v9; // [esp+0h] [ebp-18h]
  _DWORD v10[2]; // [esp+8h] [ebp-10h] BYREF
  unsigned int v11; // [esp+10h] [ebp-8h] BYREF
  IShaderDevice *v12; // [esp+14h] [ebp-4h]

  v3 = rh;
  v4 = rh->m_index == 0;
  v11 = 0;
  v12 = nullptr;
  if ( v4 )
  {
    m_index = (IShaderDevice *)rh[1].m_index;
    if ( m_index != nullptr )
      GRefCountImpl::AddRef(this: m_index, a2: v9);
  }
  v7 = (IShaderDevice *)v3[1].m_index;
  v8 = v3->m_index;
  v10[0] = &textureId;
  v12 = v7;
  v11 = v8;
  v10[1] = &v11;
  GHashSetBase<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF>>::Set<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeRef>(
    a1: (char *)this + 44,
    a2: v10);
  if ( v11 == 0 && v12 != nullptr )
    GFxResource::Release(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10155640
// Name: public: void GFxFontData::Read(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontData::Read(GFxFontData *this, struct GFxLoadProcess *a2, const struct GFxTagInfo *a3)
{
  tagBITMAPINFOHEADER *v3; // esi
  int v5; // ecx
  float v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  bool (__thiscall *v10)(IAppSystem *, void *(__cdecl *)(const char *, int *)); // edi
  IScaleformUI_vtbl *v11; // ebx
  signed int v12; // edi
  int v13; // ecx
  int v14; // eax
  float v15; // ecx
  unsigned int v16; // edi
  float *v17; // edi
  unsigned int v18; // edi
  bool v19; // cc
  unsigned int v20; // eax
  _DWORD *v21; // ebx
  unsigned int v22; // edi
  _DWORD *j; // eax
  GFxFontData *v24; // ebx
  int v25; // edi
  int v26; // eax
  int (__thiscall *v27)(int, int, wchar_t *); // edx
  int v28; // ebx
  GFxShapeBase **v29; // edi
  unsigned int UInt; // eax
  bool v31; // bl
  bool v32; // al
  int v33; // eax
  int biWidth; // eax
  char v35; // dl
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // edi
  const char *v40; // eax
  int v41; // eax
  const char *v42; // edx
  int v43; // edx
  int biHeight; // eax
  unsigned int v45; // ebx
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  float v49; // eax
  int v50; // eax
  float v51; // ecx
  int v52; // eax
  int v53; // ecx
  int v54; // edi
  unsigned int v55; // eax
  unsigned int v56; // ebx
  int *v57; // ebx
  int v58; // eax
  int v59; // edx
  int v60; // eax
  int v61; // edx
  int v62; // eax
  float v63; // edx
  unsigned int v64; // edi
  float *v65; // edi
  int v66; // eax
  int v67; // eax
  int v68; // edx
  unsigned int v69; // ebx
  _DWORD *v70; // edi
  _DWORD *v71; // eax
  unsigned int v72; // ecx
  float v73; // eax
  char *v74; // edi
  int v75; // edi
  int (__thiscall *v76)(int, int, int *); // eax
  int v77; // edi
  GFxShapeBase **v78; // ebx
  bool v79; // zf
  void (__thiscall *v80)(int, int *); // edx
  double v81; // st6
  unsigned int v82; // ebx
  int v83; // eax
  double v84; // st6
  int v85; // eax
  double v86; // st6
  int v87; // edi
  int v88; // eax
  GFxFontData *v89; // edi
  double v90; // st7
  int v91; // ecx
  int v92; // eax
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // eax
  float v97; // eax
  int v98; // ebx
  int v99; // ecx
  int v100; // edi
  int v101; // eax
  int v102; // edi
  int v103; // ecx
  int v104; // eax
  float v105; // edi
  int v106; // eax
  int v107; // edx
  int v108; // eax
  int v109; // eax
  unsigned __int16 v110; // bx
  int v111; // edx
  int v112; // eax
  unsigned __int16 v113; // di
  int v114; // eax
  int v115; // eax
  unsigned __int8 v116; // cl
  int v117; // edx
  int v118; // eax
  unsigned __int8 v119; // cl
  int v120; // eax
  int v121; // eax
  double v122; // st7
  int v123; // eax
  int v124; // edx
  int v125; // edi
  const char *v126; // eax
  _cpinfo *v127; // [esp+0h] [ebp-60h]
  int v128; // [esp+0h] [ebp-60h]
  int v129; // [esp+4h] [ebp-5Ch]
  int v130; // [esp+Ch] [ebp-54h] BYREF
  int v131; // [esp+10h] [ebp-50h]
  float v132; // [esp+14h] [ebp-4Ch]
  float i; // [esp+18h] [ebp-48h]
  IScaleformUI v134; // [esp+1Ch] [ebp-44h] BYREF
  unsigned int v135; // [esp+20h] [ebp-40h]
  unsigned int v136; // [esp+24h] [ebp-3Ch]
  int v137; // [esp+28h] [ebp-38h]
  int v138; // [esp+2Ch] [ebp-34h]
  int v139; // [esp+30h] [ebp-30h] BYREF
  int v140; // [esp+34h] [ebp-2Ch]
  int v141; // [esp+38h] [ebp-28h] BYREF
  wchar_t val[2]; // [esp+3Ch] [ebp-24h] BYREF
  int v143; // [esp+40h] [ebp-20h]
  unsigned int v144; // [esp+44h] [ebp-1Ch] BYREF
  unsigned int v145; // [esp+48h] [ebp-18h]
  int v146; // [esp+4Ch] [ebp-14h]
  _DWORD *v147; // [esp+50h] [ebp-10h]
  GFxFontData *v148; // [esp+54h] [ebp-Ch]
  int v149; // [esp+58h] [ebp-8h]
  bool v150; // [esp+5Dh] [ebp-3h]
  bool v151; // [esp+5Eh] [ebp-2h]
  char v152; // [esp+5Fh] [ebp-1h]
  float v153; // [esp+68h] [ebp+8h]

  v3 = *((tagBITMAPINFOHEADER **)a2 + 201);
  v148 = this;
  if ( v3 == nullptr )
    v3 = (tagBITMAPINFOHEADER *)((char *)a2 + 40);
  v5 = *(_DWORD *)(*((_DWORD *)a2 + 8) + 28);
  v6 = *(float *)a3;
  v152 = 1;
  v143 = v5;
  if ( LODWORD(v6) != 10 )
  {
    if ( LODWORD(v6) == 48 )
    {
      GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"reading DefineFont2: ");
    }
    else
    {
      if ( LODWORD(v6) != 75 )
        return;
      GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"reading DefineFont3: ");
    }
    UInt = GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u);
    v151 = UInt != 0;
    if ( UInt != 0 )
      *((_DWORD *)this + 5) |= 0x2000u;
    else
      *((_DWORD *)this + 5) &= ~0x2000u;
    v31 = GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0;
    v150 = GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0;
    v32 = GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0;
    if ( v31 )
    {
      *((_DWORD *)this + 5) = *((_DWORD *)this + 5) & 0xFFFFFCFF | 0x200;
    }
    else if ( v32 )
    {
      *((_DWORD *)this + 5) = *((_DWORD *)this + 5) & 0xFFFFFCFF | 0x100;
    }
    else
    {
      *((_DWORD *)this + 5) &= 0xFFFFFCFF;
    }
    if ( v150 )
      *((_DWORD *)this + 5) |= 0x8000u;
    else
      *((_DWORD *)this + 5) &= ~0x8000u;
    v150 = GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0;
    if ( GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0 )
      *((_DWORD *)this + 5) |= 0x4000u;
    else
      *((_DWORD *)this + 5) &= ~0x4000u;
    if ( GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0 )
      *((_DWORD *)this + 5) |= 1u;
    else
      *((_DWORD *)this + 5) &= ~1u;
    if ( GFxStream::ReadUInt(this: (GFxStream *)v3, a2: 1u) != 0 )
      *((_DWORD *)this + 5) |= 2u;
    else
      *((_DWORD *)this + 5) &= ~2u;
    v33 = v3[1].biHeight - v3[1].biWidth;
    BYTE1(v3->biSizeImage) = 0;
    if ( v33 < 1 )
      GFxStream::PopulateBuffer1(result: v127);
    biWidth = v3[1].biWidth;
    v35 = *(_BYTE *)(biWidth + v3[1].biSizeImage);
    v3[1].biWidth = biWidth + 1;
    HIBYTE(v149) = v35;
    GFxStream::ReadStringWithLength(this: (IShaderDeviceMgr *)v3);
    *((_DWORD *)this + 6) = v36;
    v37 = v3[1].biHeight - v3[1].biWidth;
    BYTE1(v3->biSizeImage) = 0;
    if ( v37 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v38 = v3[1].biWidth;
    v39 = *(unsigned __int16 *)(v3[1].biSizeImage + v38);
    v3[1].biWidth = v38 + 2;
    v147 = (_DWORD *)v39;
    if ( GFxStream::IsVerboseParse(this: (GFxStream *)v3) )
    {
      v40 = *((const char **)v148 + 6);
      if ( v40 == nullptr )
        v40 = "(none)";
      GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"  Name = %s, %d glyphs\n", v40, v39);
      v41 = *((_DWORD *)v148 + 5);
      v42 = "Unicode";
      if ( (v41 & 0x300) == 0x200 )
      {
        v42 = "ShiftJIS";
      }
      else if ( (v41 & 0x300) == 0x100 )
      {
        v42 = "ANSI";
      }
      GFxLogBase<GFxStream>::LogParse(
        this: v3,
        a2: (int)"  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n",
        v151,
        v42,
        *((_BYTE *)v148 + 20) & 1,
        (v41 & 2) != 0);
      GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"  LangCode = %d\n", HIBYTE(v149));
    }
    v43 = v3[1].biWidth;
    biHeight = v3[1].biHeight;
    v45 = 0;
    v144 = *(_DWORD *)&v3[1].biPlanes + v43 - biHeight;
    v46 = v39;
    v134.__vftable = nullptr;
    v135 = 0;
    v136 = 0;
    v146 = v39;
    if ( v39 > 0 )
    {
      v47 = biHeight - v43;
      BYTE1(v3->biSizeImage) = 0;
      if ( v150 )
      {
        if ( v47 < 4 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
        v48 = v3[1].biWidth;
        LODWORD(v49) = *(unsigned __int8 *)(v48 + v3[1].biSizeImage)
                     | ((*(unsigned __int8 *)(v48 + v3[1].biSizeImage + 1)
                       | (*(unsigned __int16 *)(v48 + v3[1].biSizeImage + 2) << 8)) << 8);
        v3[1].biWidth = v48 + 4;
      }
      else
      {
        if ( v47 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v50 = v3[1].biWidth;
        LODWORD(v51) = *(unsigned __int16 *)(v50 + v3[1].biSizeImage);
        v3[1].biWidth = v50 + 2;
        v49 = v51;
      }
      if ( v49 == 0.0 )
      {
        v152 = 0;
        v46 = 0;
      }
      else
      {
        *(float *)val = v49;
        GArrayBase<GArrayData<unsigned int,GAllocatorGH<unsigned int,2>,GArrayDefaultPolicy>>::PushBack(
          this: &v134,
          (GTexture::ChangeHandler *const *)val,
          a3: (int)v127);
        v45 = v135;
        v46 = v146;
      }
    }
    if ( v150 )
    {
      if ( v46 > 1 )
      {
        v145 = v46 - 1;
        do
        {
          v52 = v3[1].biHeight - v3[1].biWidth;
          BYTE1(v3->biSizeImage) = 0;
          if ( v52 < 4 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v53 = v3[1].biWidth;
          v54 = *(unsigned __int8 *)(v53 + v3[1].biSizeImage)
              | ((*(unsigned __int8 *)(v53 + v3[1].biSizeImage + 1)
                | (*(unsigned __int16 *)(v53 + v3[1].biSizeImage + 2) << 8)) << 8);
          v55 = v135;
          v56 = v135 + 1;
          v3[1].biWidth = v53 + 4;
          if ( v56 >= v55 )
          {
            if ( v56 >= v136 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: (CVertexBuilder *)&v134,
                pheapAddr: (ButtonCode_t)&v134,
                newCapacity: v56 + (v56 >> 2));
          }
          else if ( v56 < v136 >> 1 )
          {
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v134,
              pheapAddr: (ButtonCode_t)&v134,
              newCapacity: v56);
          }
          v135 = v56;
          v57 = (int *)((char *)v134.__vftable + 4 * v56 - 4);
          if ( v57 != nullptr )
            *v57 = v54;
          --v145;
        }
        while ( v145 != 0 );
      }
      v58 = v3[1].biHeight - v3[1].biWidth;
      BYTE1(v3->biSizeImage) = 0;
      if ( v58 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v59 = v3[1].biWidth;
      v60 = *(unsigned __int8 *)(v59 + v3[1].biSizeImage)
          | ((*(unsigned __int8 *)(v59 + v3[1].biSizeImage + 1)
            | ((*(unsigned __int8 *)(v3[1].biSizeImage + v59 + 2)
              | (*(unsigned __int8 *)(v3[1].biSizeImage + v59 + 3) << 8)) << 8)) << 8);
      v3[1].biWidth = v59 + 4;
      v146 = v60;
    }
    else
    {
      if ( v46 > 1 )
      {
        v145 = v46 - 1;
        do
        {
          v61 = v3[1].biHeight - v3[1].biWidth;
          BYTE1(v3->biSizeImage) = 0;
          if ( v61 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v62 = v3[1].biWidth;
          LODWORD(v63) = (unsigned __int16)(*(unsigned __int8 *)(v3[1].biSizeImage + v62)
                                          | (*(unsigned __int8 *)(v3[1].biSizeImage + v62 + 1) << 8));
          v64 = v45 + 1;
          v3[1].biWidth = v62 + 2;
          *(float *)val = v63;
          if ( v45 + 1 >= v45 )
          {
            if ( v64 >= v136 )
              GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                this: (CVertexBuilder *)&v134,
                pheapAddr: (ButtonCode_t)&v134,
                newCapacity: v64 + (v64 >> 2));
          }
          else if ( v64 < v136 >> 1 )
          {
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v134,
              pheapAddr: (ButtonCode_t)&v134,
              newCapacity: v45 + 1);
          }
          ++v45;
          v65 = (float *)((char *)v134.__vftable + 4 * v64 - 4);
          v135 = v45;
          if ( v65 != nullptr )
            *v65 = *(float *)val;
          --v145;
        }
        while ( v145 != 0 );
      }
      v66 = v3[1].biHeight - v3[1].biWidth;
      BYTE1(v3->biSizeImage) = 0;
      if ( v66 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v67 = v3[1].biWidth;
      v68 = (unsigned __int16)(*(unsigned __int8 *)(v3[1].biSizeImage + v67)
                             | (*(unsigned __int8 *)(v3[1].biSizeImage + v67 + 1) << 8));
      v3[1].biWidth = v67 + 2;
      v146 = v68;
    }
    v69 = (unsigned int)v147;
    v70 = (_DWORD *)((char *)v148 + 32);
    v145 = *((_DWORD *)v148 + 9);
    GArrayDataBase<GPtr<GFxShapeBase>,GAllocatorLH<GPtr<GFxShapeBase>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GStatInfo *)((char *)v148 + 32),
      pheapAddr: (char *)v148 + 32,
      newSize: (unsigned int)v147);
    if ( v69 > v145 )
    {
      v71 = (_DWORD *)(*v70 + 4 * v145);
      v72 = v69 - v145;
      if ( v69 != v145 )
      {
        do
        {
          if ( v71 != nullptr )
            *v71 = 0;
          ++v71;
          --v72;
        }
        while ( v72 != 0 );
      }
    }
    if ( v152 != 0 )
    {
      v73 = *(float *)a3;
      wcscpy(val, L"\x16");
      if ( LODWORD(v73) != 48 )
        *(float *)val = v73;
      if ( v151 )
      {
        v74 = (char *)v148 + 48;
        if ( v69 >= *((_DWORD *)v148 + 13) )
        {
          if ( v69 >= *((_DWORD *)v148 + 14) )
            GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
              this: (void **)v148 + 12,
              pheapAddr: (char *)v148 + 48,
              newCapacity: v69 + (v69 >> 2));
        }
        else if ( v69 < *((_DWORD *)v148 + 14) >> 1 )
        {
          GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v148 + 12,
            pheapAddr: (char *)v148 + 48,
            newCapacity: v69);
        }
        *((_DWORD *)v74 + 1) = v69;
      }
      v75 = 0;
      if ( (int)v69 > 0 )
      {
        v145 = 0;
        do
        {
          v149 = 4 * v75;
          GFxStream::SetPosition(
            this: (IShaderDeviceMgr *)v3,
            pos: v144 + *((_DWORD *)&v134.Connect + v75),
            a3: (int)v127);
          v137 = v75 + 1;
          v76 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v143 + 40);
          v141 = 258;
          v77 = v76(a1: v143, a2: 44, a3: &v141);
          if ( v77 != 0 )
          {
            GFxShapeBase::GFxShapeBase();
            *(_DWORD *)v77 = &GFxConstShapeNoStyles::`vftable';
            *(_DWORD *)(v77 + 40) = 0;
          }
          else
          {
            v77 = 0;
          }
          GFxConstShapeNoStyles::Read(this: (CBitRead *)v77);
          v78 = (GFxShapeBase **)(v149 + *((_DWORD *)v148 + 8));
          if ( v77 != 0 )
            GFxShapeBase::AddRef(this: (GFxShapeBase *)v77);
          if ( *v78 != nullptr )
            GFxShapeBase::Release(this: *v78);
          v79 = !v151;
          *v78 = (GFxShapeBase *)v77;
          if ( !v79 )
          {
            v80 = *(void (__thiscall **)(int, int *))(*(_DWORD *)v77 + 20);
            *(float *)&v130 = 0.0;
            *(float *)&v131 = 0.0;
            v132 = 0.0;
            i = 0.0;
            v80(a1: v77, a2: &v130);
            v81 = *(float *)&v130;
            v82 = v145 + *((_DWORD *)v148 + 12);
            if ( *(float *)&v130 > (double)v132 || *(float *)&v131 > (double)i )
            {
              *(_DWORD *)(v82 + 4) = 0;
              *(_DWORD *)(v82 + 8) = 0;
            }
            else
            {
              v149 = v131;
              *(float *)&v140 = v132 - v81;
              *(float *)&v138 = i - *(float *)&v131;
              v83 = (int)(v81 * 20.0);
              v84 = *(float *)&v131 * 20.0;
              *(_WORD *)(v82 + 4) = v83;
              v85 = (int)v84;
              v86 = *(float *)&v140;
              *(_WORD *)(v82 + 6) = v85;
              v140 = (int)(v86 * 20.0);
              *(_WORD *)(v82 + 8) = v140;
              v138 = (int)(20.0 * *(float *)&v138);
              *(_WORD *)(v82 + 10) = v138;
            }
          }
          if ( v77 != 0 )
            GFxShapeBase::Release(this: (GFxShapeBase *)v77);
          v75 = v137;
          v145 += 12;
        }
        while ( v137 < (int)v147 );
      }
      if ( v144 + v146 != v3[1].biWidth + *(_DWORD *)&v3[1].biPlanes - v3[1].biHeight )
        goto LABEL_216;
    }
    else
    {
      v87 = v144 + v146;
      GFxStream::GetTagEndPosition(this: (IShaderDeviceMgr *)v3, a2: (ShaderDisplayMode_t *)v127, a3: v129);
      if ( v87 >= v88 )
        goto LABEL_216;
      GFxStream::SetPosition(this: (IShaderDeviceMgr *)v3, pos: v87, a3: v128);
      *((_DWORD *)v148 + 5) |= 0x1000u;
    }
    v89 = v148;
    GFxFontData::ReadCodeTable(this: v148, a2: v3);
    if ( v151 )
    {
      if ( *(_DWORD *)a3 == 75 )
        v90 = 0.050000001;
      else
        v90 = 1.0;
      v153 = v90;
      v91 = v3[1].biHeight - v3[1].biWidth;
      BYTE1(v3->biSizeImage) = 0;
      if ( v91 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v92 = v3[1].biWidth;
      v137 = *(__int16 *)(v92 + v3[1].biSizeImage);
      v3[1].biWidth = v92 + 2;
      *((float *)v89 + 2) = (double)v137 * v153;
      v93 = v3[1].biHeight - v3[1].biWidth;
      BYTE1(v3->biSizeImage) = 0;
      if ( v93 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v94 = v3[1].biWidth;
      v137 = *(__int16 *)(v3[1].biSizeImage + v94);
      v3[1].biWidth = v94 + 2;
      *((float *)v89 + 3) = (double)v137 * v153;
      v95 = v3[1].biHeight - v3[1].biWidth;
      BYTE1(v3->biSizeImage) = 0;
      if ( v95 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v96 = v3[1].biWidth;
      v137 = *(__int16 *)(v3[1].biSizeImage + v96);
      v3[1].biWidth = v96 + 2;
      *((float *)v89 + 4) = (double)v137 * v153;
      if ( GFxStream::IsVerboseParse(this: (GFxStream *)v3) )
        GFxLogBase<GFxStream>::LogParse(
          this: v3,
          a2: (int)"  Ascent = %d, Descent = %d, Leading = %d\n",
          (int)*((float *)v89 + 2),
          (int)*((float *)v89 + 3),
          (int)*((float *)v89 + 4));
      v97 = *((float *)v89 + 9);
      *(float *)val = v97;
      if ( *((_DWORD *)v89 + 13) == LODWORD(v97) )
      {
LABEL_180:
        if ( *((_DWORD *)v89 + 13) != 0 )
        {
          v98 = 0;
          *(float *)val = *((float *)v89 + 13);
          do
          {
            v99 = v3[1].biHeight - v3[1].biWidth;
            v100 = *((_DWORD *)v148 + 12);
            BYTE1(v3->biSizeImage) = 0;
            if ( v99 < 2 )
              GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
            v101 = v3[1].biWidth;
            v137 = (unsigned __int16)(*(unsigned __int8 *)(v101 + v3[1].biSizeImage)
                                    | (*(unsigned __int8 *)(v101 + v3[1].biSizeImage + 1) << 8));
            v3[1].biWidth = v101 + 2;
            v98 += 12;
            v79 = (*(_DWORD *)val)-- == 1;
            *(float *)(v100 + v98 - 12) = (double)v137 * v153;
          }
          while ( !v79 );
          v89 = v148;
        }
        v102 = *((_DWORD *)v89 + 9);
        *(float *)&v130 = 0.0;
        *(float *)&v131 = 0.0;
        v132 = 0.0;
        for ( i = 0.0; v102 != 0; --v102 )
          GFxStream::ReadRect(this: (GFxStream *)v3, a2: (int)&v130);
        v103 = v3[1].biHeight - v3[1].biWidth;
        BYTE1(v3->biSizeImage) = 0;
        if ( v103 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v104 = v3[1].biWidth;
        LODWORD(v105) = *(unsigned __int16 *)(v104 + v3[1].biSizeImage);
        v3[1].biWidth = v104 + 2;
        *(float *)&v138 = v105;
        if ( GFxStream::IsVerboseParse(this: (GFxStream *)v3) )
          GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"  KerningCount = %d\n", v105);
        v143 = 0;
        if ( SLODWORD(v105) > 0 )
        {
          while ( 1 )
          {
            v106 = v3[1].biHeight;
            if ( *(_DWORD *)&v3[1].biPlanes + v3[1].biWidth - v106 >= *((_DWORD *)a3 + 3) + *((_DWORD *)a3 + 2) )
              break;
            v107 = *((_DWORD *)v148 + 5) >> 14;
            v108 = v106 - v3[1].biWidth;
            BYTE1(v3->biSizeImage) = 0;
            if ( (v107 & 1) != 0 )
            {
              if ( v108 < 2 )
                GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
              v109 = v3[1].biWidth;
              v110 = *(_WORD *)(v3[1].biSizeImage + v109);
              v109 += 2;
              v111 = v3[1].biHeight - v109;
              v3[1].biWidth = v109;
              BYTE1(v3->biSizeImage) = 0;
              if ( v111 < 2 )
                GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
              v112 = v3[1].biWidth;
              v113 = *(_WORD *)(v3[1].biSizeImage + v112);
              v114 = v112 + 2;
            }
            else
            {
              if ( v108 < 1 )
                GFxStream::PopulateBuffer1(result: v127);
              v115 = v3[1].biWidth;
              v116 = *(_BYTE *)(v115 + v3[1].biSizeImage);
              ++v115;
              v117 = v3[1].biHeight - v115;
              v3[1].biWidth = v115;
              v110 = v116;
              BYTE1(v3->biSizeImage) = 0;
              if ( v117 < 1 )
                GFxStream::PopulateBuffer1(result: v127);
              v118 = v3[1].biWidth;
              v119 = *(_BYTE *)(v118 + v3[1].biSizeImage);
              v114 = v118 + 1;
              v113 = v119;
            }
            v3[1].biWidth = v114;
            v120 = v3[1].biHeight - v3[1].biWidth;
            BYTE1(v3->biSizeImage) = 0;
            if ( v120 < 2 )
              GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
            v121 = v3[1].biWidth;
            v137 = *(__int16 *)(v3[1].biSizeImage + v121);
            v122 = (double)v137;
            v3[1].biWidth = v121 + 2;
            LOWORD(v144) = v110;
            HIWORD(v144) = v113;
            *(float *)val = v122 * v153;
            if ( GFxStream::IsVerboseParse(this: (GFxStream *)v3) )
              GFxLogBase<GFxStream>::LogParse(
                this: v3,
                a2: (int)&stru_102A95E8.m_pElements,
                v110,
                v113,
                (int)*(float *)val);
            v139 = (int)&v144;
            *(float *)&v140 = COERCE_FLOAT(val);
            v123 = 4;
            v124 = 5381;
            do
            {
              v125 = *((unsigned __int8 *)&v143 + v123-- + 3);
              v124 = v125 + 65599 * v124;
            }
            while ( v123 != 0 );
            GHashSetBase<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeHashF,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeAltHashF,GAllocatorLH<GFxFontData::KerningPair,2>,GHashsetCachedNodeEntry<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>,GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeHashF>>::add<GHashNode<GFxFontData::KerningPair,float,GFixedSizeHash<GFxFontData::KerningPair>>::NodeRef>(
              this: (GFxExternalInterface *)v148 + 5,
              pheapAddr: (GFxExternalInterface *)v148 + 5,
              a3: (int)&v139,
              a4: v124);
            if ( ++v143 >= v138 )
              goto LABEL_216;
          }
          v126 = *((const char **)v148 + 6);
          if ( v126 == nullptr )
            v126 = "<noname>";
          GFxLogBase<GFxStream>::LogError(
            this: v3,
            a2: (int)"Error: Corrupted file %s, kerning table of the font '%s' is longer than tagLength.\n",
            (const char *)((v3->biXPelsPerMeter & 0xFFFFFFFC) + 8),
            v126);
        }
        goto LABEL_216;
      }
      if ( LODWORD(v97) >= *((_DWORD *)v89 + 13) )
      {
        if ( LODWORD(v97) >= *((_DWORD *)v89 + 14) )
        {
          GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v89 + 12,
            pheapAddr: (char *)v89 + 48,
            newCapacity: LODWORD(v97) + (LODWORD(v97) >> 2));
          goto LABEL_178;
        }
      }
      else if ( LODWORD(v97) < *((_DWORD *)v89 + 14) >> 1 )
      {
        GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)v89 + 12,
          pheapAddr: (char *)v89 + 48,
          newCapacity: LODWORD(v97));
LABEL_178:
        v97 = *(float *)val;
      }
      *((float *)v89 + 13) = v97;
      goto LABEL_180;
    }
LABEL_216:
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v134.__vftable);
    return;
  }
  GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"reading DefineFont\n");
  v7 = v3[1].biHeight;
  v8 = v3[1].biWidth;
  v146 = v8 + *(_DWORD *)&v3[1].biPlanes - v7;
  v134.__vftable = nullptr;
  v135 = 0;
  v136 = 0;
  BYTE1(v3->biSizeImage) = 0;
  if ( v7 - v8 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v9 = v3[1].biWidth;
  v10 = (bool (__thiscall *)(IAppSystem *, void *(__cdecl *)(const char *, int *)))*(unsigned __int16 *)(v3[1].biSizeImage + v9);
  v3[1].biWidth = v9 + 2;
  GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
    this: (CVertexBuilder *)&v134,
    pheapAddr: (ButtonCode_t)&v134,
    newCapacity: 1u);
  v11 = v134.__vftable;
  v135 = 1;
  if ( v134.__vftable != nullptr )
    v134.Connect = v10;
  GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"offset[0] = %d\n", v11->Connect);
  v12 = (int)v11->Connect >> 1;
  v149 = v12;
  v144 = 1;
  if ( v12 > 1 )
  {
    do
    {
      v13 = v3[1].biHeight - v3[1].biWidth;
      BYTE1(v3->biSizeImage) = 0;
      if ( v13 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v14 = v3[1].biWidth;
      LODWORD(v15) = *(unsigned __int16 *)(v14 + v3[1].biSizeImage);
      v3[1].biWidth = v14 + 2;
      if ( LOWORD(v15) == 0 )
      {
        v152 = 0;
        break;
      }
      v16 = v135 + 1;
      *(float *)val = v15;
      if ( v135 + 1 >= v135 )
      {
        if ( v16 >= v136 )
        {
          GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
            this: (CVertexBuilder *)&v134,
            pheapAddr: (ButtonCode_t)&v134,
            newCapacity: v16 + (v16 >> 2));
          goto LABEL_17;
        }
      }
      else if ( v16 < v136 >> 1 )
      {
        GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
          this: (CVertexBuilder *)&v134,
          pheapAddr: (ButtonCode_t)&v134,
          newCapacity: v135 + 1);
LABEL_17:
        v11 = v134.__vftable;
      }
      v135 = v16;
      v17 = (float *)((char *)v11 + 4 * v16 - 4);
      if ( v17 != nullptr )
        *v17 = *(float *)val;
      v18 = v144;
      GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"offset[%d] = %d\n", v144, *((_DWORD *)&v11->Connect + v144));
      v19 = (int)++v18 < v149;
      v144 = v18;
      v12 = v149;
    }
    while ( v19 );
  }
  v20 = *((_DWORD *)v148 + 9);
  v21 = (_DWORD *)((char *)v148 + 32);
  v147 = (_DWORD *)((char *)v148 + 32);
  v144 = v20;
  GArrayDataBase<GPtr<GFxShapeBase>,GAllocatorLH<GPtr<GFxShapeBase>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GStatInfo *)((char *)v148 + 32),
    pheapAddr: (char *)v148 + 32,
    newSize: v12);
  if ( v12 > v144 )
  {
    v22 = v12 - v144;
    for ( j = (_DWORD *)(*v21 + 4 * v144); v22 != 0; --v22 )
    {
      if ( j != nullptr )
        *j = 0;
      ++j;
    }
  }
  if ( v152 != 0 )
  {
    v24 = nullptr;
    if ( v149 > 0 )
    {
      do
      {
        v25 = v146 + *((_DWORD *)&v134.Connect + (_DWORD)v24);
        v145 = 4 * (_DWORD)v24;
        GFxStream::SetPosition(this: (IShaderDeviceMgr *)v3, pos: v25, a3: (int)v127);
        v148 = (GFxFontData *)((char *)v24 + 1);
        if ( (int)v24 + 1 >= v149 )
          v26 = *((_DWORD *)a3 + 2) + *((_DWORD *)a3 + 3) - v25;
        else
          v26 = (char *)*(void (__thiscall **)(IAppSystem *))((char *)&v134.Disconnect + v145)
              - (char *)*(void (__thiscall **)(IAppSystem *))((char *)&v134.Connect + v145);
        v27 = *(int (__thiscall **)(int, int, wchar_t *))(*(_DWORD *)v143 + 40);
        v144 = v26;
        wcscpy(val, L"Ă");
        v28 = v27(a1: v143, a2: 44, a3: val);
        if ( v28 != 0 )
        {
          GFxShapeBase::GFxShapeBase();
          *(_DWORD *)v28 = &GFxConstShapeNoStyles::`vftable';
          *(_DWORD *)(v28 + 40) = 0;
        }
        else
        {
          v28 = 0;
        }
        GFxConstShapeNoStyles::Read(this: (CBitRead *)v28);
        v29 = (GFxShapeBase **)(v145 + *v147);
        if ( v28 != 0 )
          GFxShapeBase::AddRef(this: (GFxShapeBase *)v28);
        if ( *v29 != nullptr )
          GFxShapeBase::Release(this: *v29);
        *v29 = (GFxShapeBase *)v28;
        if ( v28 != 0 )
          GFxShapeBase::Release(this: (GFxShapeBase *)v28);
        v24 = v148;
      }
      while ( (int)v148 < v149 );
    }
  }
  else
  {
    *((_DWORD *)v148 + 5) |= 0x1000u;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v134.__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x1028BDB0
// Name: _dynamic_initializer_for__GFxSystemFontResourceKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxSystemFontResourceKeyInterface_Instance__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GFxSystemFontResourceKeyInterface_Instance__);
}

//------------------------------------------------------------------------------
// Address: 0x1028CBF0
// Name: _dynamic_atexit_destructor_for__GFxSystemFontResourceKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxSystemFontResourceKeyInterface_Instance__()
{
  GFxSystemFontResourceKeyInterface_Instance.__vftable = (GFxResourceKey::KeyInterface_vtbl *)&GFxResourceKey::KeyInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CC00
// Name: _GFxTextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__
// Source: json
//------------------------------------------------------------------------------
__int16 GFxTextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__()
{
  GFxRectangle_NaNParams.HeapLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&GFxTextureGlyph::`vftable';
  if ( GFxRectangle_NaNParams.HeapLock.cs.RecursionCount == 0
    && GFxRectangle_NaNParams.HeapLock.cs.OwningThread != nullptr )
  {
    GFxResource::Release(this: (IShaderDevice *)GFxRectangle_NaNParams.HeapLock.cs.OwningThread);
  }
  return GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&GFxRectangle_NaNParams.HeapLock);
}
