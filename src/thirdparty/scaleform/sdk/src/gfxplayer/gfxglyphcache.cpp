// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxglyphcache.cpp
// Functions: 62
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxglyphcache.h"

//------------------------------------------------------------------------------
// Address: 0x1017DFE0
// Name: public: GFxGlyphScanlineFilter::GFxGlyphScanlineFilter(float,float,float)
// Source: json
//------------------------------------------------------------------------------
GFxGlyphScanlineFilter *__thiscall GFxGlyphScanlineFilter::GFxGlyphScanlineFilter(
        GFxGlyphScanlineFilter *this,
        float a2,
        float a3,
        float a4)
{
  unsigned int v5; // esi
  double v6; // st5
  double v7; // st4
  float v9; // [esp+10h] [ebp-Ch]
  float v10; // [esp+10h] [ebp-Ch]
  float v11; // [esp+14h] [ebp-8h]
  float v12; // [esp+18h] [ebp-4h]
  float v13; // [esp+24h] [ebp+8h]
  float v14; // [esp+24h] [ebp+8h]
  float v15; // [esp+28h] [ebp+Ch]
  float v16; // [esp+2Ch] [ebp+10h]

  v5 = 0;
  v6 = a2;
  v13 = 1.0 / (2.0 * a4 + a3 * 2.0 + a2);
  v7 = v6 * v13;
  v15 = a3 * v13;
  v16 = v13 * a4;
  do
  {
    v11 = (float)v5;
    v14 = v7;
    v12 = v11 * v14;
    *((_BYTE *)this + v5) = (int)floor(X: v12);
    v9 = v11 * v15;
    *((_BYTE *)this + v5 + 256) = (int)floor(X: v9);
    v10 = v11 * v16;
    *((_BYTE *)this + ++v5 + 511) = (int)floor(X: v10);
  }
  while ( v5 < 0x100 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017E100
// Name: public: bool GFxTextureUpdatePacker::Allocate(unsigned int,unsigned int,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextureUpdatePacker::Allocate(
        GFxTextureUpdatePacker *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4,
        unsigned int *a5)
{
  unsigned int v5; // edx

  v5 = *((_DWORD *)this + 2);
  if ( v5 + a2 > *(_DWORD *)this || a3 + *((_DWORD *)this + 3) > *((_DWORD *)this + 1) )
  {
    *((_DWORD *)this + 3) += *((_DWORD *)this + 4);
    if ( a3 + *((_DWORD *)this + 3) > *((_DWORD *)this + 1) )
    {
      return 0;
    }
    else
    {
      *a4 = 0;
      *a5 = *((_DWORD *)this + 3);
      *((_DWORD *)this + 2) = a2;
      *((_DWORD *)this + 4) = a3;
      return 1;
    }
  }
  else
  {
    *a4 = v5;
    *a5 = *((_DWORD *)this + 3);
    *((_DWORD *)this + 2) += a2;
    if ( a3 > *((_DWORD *)this + 4) )
      *((_DWORD *)this + 4) = a3;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E180
// Name: public: unsigned short GFxFontResource::GetLowerCaseTop(class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontResource::GetLowerCaseTop(GFxFontResource *this, ISequentialStream *log)
{
  int result; // eax

  if ( *((_WORD *)this + 20) == 0 )
    GFxFontResource::calcLowerUpperTop((ISequentialStream *)this, log);
  LOWORD(result) = *((_WORD *)this + 20);
  if ( (__int16)result > 0 )
    return (__int16)result;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017E1B0
// Name: public: unsigned short GFxFontResource::GetUpperCaseTop(class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontResource::GetUpperCaseTop(GFxFontResource *this, ISequentialStream *log)
{
  int result; // eax

  if ( *((_WORD *)this + 21) == 0 )
    GFxFontResource::calcLowerUpperTop((ISequentialStream *)this, log);
  LOWORD(result) = *((_WORD *)this + 21);
  if ( (__int16)result > 0 )
    return (__int16)result;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017E1E0
// Name: private: static struct GFxGlyphNode const __near * GFxGlyphSlotQueue::findFontInSlot(struct GFxGlyphNode __near *,class GFxFontResource const __near *)
// Source: json
//------------------------------------------------------------------------------
static const struct GFxGlyphNode *__cdecl GFxGlyphSlotQueue::findFontInSlot(
        struct GFxGlyphNode *a1,
        const struct GFxFontResource *a2)
{
  struct GFxGlyphNode *v2; // esi
  const struct GFxGlyphNode *result; // eax

  v2 = a1;
  if ( a1 == nullptr )
    return nullptr;
  while ( *(const struct GFxFontResource **)v2 != a2 )
  {
    result = GFxGlyphSlotQueue::findFontInSlot(a1: *((struct GFxGlyphNode **)v2 + 4), a2);
    if ( result != nullptr )
      return result;
    v2 = *((struct GFxGlyphNode **)v2 + 5);
    if ( v2 == nullptr )
      return nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1017E220
// Name: private: void GFxGlyphRasterCache::filterScanline(unsigned char const __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::filterScanline(
        GFxGlyphRasterCache *this,
        const unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned int a4)
{
  const unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // edx

  if ( a4 > 4 )
  {
    v4 = a2 + 2;
    v5 = a3 + 2;
    do
    {
      v6 = *v4;
      *(v5 - 2) += *((_BYTE *)this + v6 + 1440);
      *(v5 - 1) += *((_BYTE *)this + v6 + 1184);
      *v5 += *((_BYTE *)this + v6 + 928);
      v5[1] += *((_BYTE *)this + v6 + 1184);
      v5[2] += *((_BYTE *)this + v6 + 1440);
      ++v5;
      ++v4;
    }
    while ( (unsigned int)&v5[4 - (_DWORD)a3 - 2] < a4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E290
// Name: private: void GFxGlyphRasterCache::strengthenImage(class GImage __near &,unsigned int,unsigned int,unsigned int,unsigned int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::strengthenImage(
        GFxGlyphRasterCache *this,
        struct GImage *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        float a7,
        int a8)
{
  unsigned int i; // ebx
  unsigned int v9; // edi
  unsigned __int8 *j; // esi
  int v11; // eax

  if ( 1.0 != a7 )
  {
    for ( i = 0; i < a6; ++i )
    {
      v9 = a5;
      for ( j = &a2->pData[a3 + a2->Pitch * (i + a4)]; v9 != 0; --v9 )
      {
        v11 = a8 + (int)((double)(*j - a8) * a7 + 0.5);
        if ( v11 >= 0 )
        {
          if ( v11 > 255 )
            LOBYTE(v11) = -1;
        }
        else
        {
          LOBYTE(v11) = 0;
        }
        *j++ = v11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E310
// Name: public: void GFxGlyphRasterCache::CalcGlyphParam(float,unsigned int,float,float,struct GFxGlyphParam const __near &,struct GFxGlyphParam __near *,unsigned short __near *,unsigned short __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::CalcGlyphParam(
        GFxGlyphRasterCache *this,
        float a2,
        unsigned int a3,
        float a4,
        float a5,
        const struct GFxGlyphParam *a6,
        struct GFxGlyphParam *a7,
        unsigned __int16 *a8,
        unsigned __int16 *a9)
{
  double v11; // st7
  double v12; // st6
  double v13; // st6
  unsigned __int8 v14; // bl
  unsigned int v15; // ecx
  float v16; // [esp+20h] [ebp+Ch]
  float v17; // [esp+20h] [ebp+Ch]
  float v18; // [esp+20h] [ebp+Ch]
  float v19; // [esp+20h] [ebp+Ch]
  float v20; // [esp+20h] [ebp+Ch]
  float v21; // [esp+20h] [ebp+Ch]
  float v22; // [esp+20h] [ebp+Ch]
  float v23; // [esp+20h] [ebp+Ch]
  float v24; // [esp+20h] [ebp+Ch]
  float v25; // [esp+2Ch] [ebp+18h]
  float v26; // [esp+2Ch] [ebp+18h]
  float v27; // [esp+30h] [ebp+1Ch]

  *((_BYTE *)a7 + 6) = a3;
  *((_BYTE *)a7 + 7) = *((_BYTE *)a6 + 7);
  *((_BYTE *)a7 + 10) = *((_BYTE *)a6 + 10);
  *a8 = 16 * a3;
  v16 = (float)a3;
  v11 = v16;
  v17 = v16 / a2;
  if ( v17 >= 1.0 )
    v12 = v17;
  else
    v12 = (float)1.0;
  v18 = (double)*((unsigned __int8 *)a6 + 8) * 0.0625;
  v27 = v18 * a4 * v12;
  v19 = (double)*((unsigned __int8 *)a6 + 9) * 0.0625;
  v20 = v12 * (a4 * v19);
  v25 = v11 * 0.0009765625;
  v13 = v20;
  v21 = v25 * a5 + v20 + v20;
  v26 = (float)(unsigned int)(*((_DWORD *)this + 3) - 2 * *((_DWORD *)this + 4) - 2);
  *a9 = 256;
  if ( v26 < (double)v21 )
  {
    v22 = v26 / v21;
    *a8 = (int)((double)*a8 * v22);
    *a9 = (int)(256.0 * v22 + 0.5);
    *((_BYTE *)a7 + 7) &= ~2u;
    v27 = v27 * v22;
    v23 = v13 * v22;
    v13 = v23;
  }
  if ( v27 > 15.75 )
    v27 = 15.75;
  if ( v13 > 15.75 )
    v13 = (float)15.75;
  *((_BYTE *)a7 + 8) = (int)(v27 * 16.0 + 0.5);
  v14 = (int)(16.0 * v13 + 0.5);
  *((_BYTE *)a7 + 9) = v14;
  if ( (*((_BYTE *)a6 + 7) & 0x81) == 0 )
  {
    v24 = 0.0625 * (double)v14;
    v15 = (__int64)(v24 + 0.5);
    if ( v15 == 0 )
      v15 = v14 != 0;
    if ( (double)v15 < v13 )
    {
      *a8 = (int)((double)(v15 * *a8) / v13);
      *a9 = (int)((double)(v15 * *a9) / v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E620
// Name: public: unsigned int GFxGlyphRasterCache::GetNumTextures(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxGlyphRasterCache::GetNumTextures(GFxGlyphRasterCache *this)
{
  int v1; // edx
  unsigned int result; // eax
  _DWORD *v3; // ecx

  v1 = *((_DWORD *)this + 2);
  result = 0;
  if ( v1 != 0 )
  {
    v3 = (_DWORD *)((char *)this + 56);
    do
    {
      if ( *v3 != 0 )
        ++result;
      v3 += 5;
      --v1;
    }
    while ( v1 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E640
// Name: public: void GArrayUnsafeBase<float,struct GAllocatorLH_POD<float,195>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<float,GAllocatorLH_POD<float,195>>::Reserve(int this, unsigned int a2, int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 195;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4 * v5, a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017E750
// Name: public: virtual bool GFxGlyphRasterCache::TextureEventHandler::Recreate(class GRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxGlyphRasterCache::TextureEventHandler::Recreate(
        GFxGlyphRasterCache::TextureEventHandler *this,
        struct GRenderer *a2)
{
  _DWORD *v2; // eax
  int v3; // ecx

  v2 = *((_DWORD **)this + 1);
  v3 = v2[5 * *((_DWORD *)this + 2) + 14];
  return (*(bool (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v3 + 8))(
           a1: v3,
           a2: *v2,
           a3: v2[1],
           a4: 9,
           a5: 0,
           a6: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1017E780
// Name: public: void GFxGlyphSlotQueue::UnlockAllGlyphs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::UnlockAllGlyphs(GFxGlyphSlotQueue *this)
{
  int v1; // eax
  char *i; // ecx

  v1 = *((_DWORD *)this + 13);
  for ( i = (char *)this + 48; (char *)v1 != i; v1 = *(_DWORD *)(v1 + 4) )
    *(_WORD *)(v1 + 32) &= ~0x8000u;
}

//------------------------------------------------------------------------------
// Address: 0x1017E7B0
// Name: private: void GFxGlyphRasterCache::makeKnockOutCopy(class GImage const __near &,unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::makeKnockOutCopy(
        GFxGlyphRasterCache *this,
        const struct GImage *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int count,
        unsigned int a6)
{
  int v7; // eax
  GImage *v8; // eax
  GImage *v9; // esi
  GRefCountNTSImpl *v10; // ecx
  unsigned int i; // esi
  int v12; // [esp+8h] [ebp-4h] BYREF

  v7 = *((_DWORD *)this + 180);
  if ( v7 == 0 || *(_DWORD *)(v7 + 12) < count || *(_DWORD *)(v7 + 16) < a6 )
  {
    v12 = 3;
    v8 = (GImage *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 48, a4: &v12);
    if ( v8 != nullptr )
      v9 = GImage::GImage(this: v8, a2: IMAGE_FORMAT_RGB888_BLUESCREEN, a3: count + 16, a4: a6 + 16);
    else
      v9 = nullptr;
    v10 = *((GRefCountNTSImpl **)this + 180);
    if ( v10 != nullptr )
      GRefCountNTSImpl::Release(this: v10);
    *((_DWORD *)this + 180) = v9;
  }
  for ( i = 0; i < a6; ++i )
    memcpy(
      dst: (unsigned __int8 *)(*(_DWORD *)(*((_DWORD *)this + 180) + 24) + i * *(_DWORD *)(*((_DWORD *)this + 180) + 20)),
      src: &a2->pData[a2->Pitch * (i + a4) + a3],
      count);
}

//------------------------------------------------------------------------------
// Address: 0x1017E870
// Name: private: void GFxGlyphRasterCache::knockOut(class GImage __near &,unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::knockOut(
        GFxGlyphRasterCache *this,
        struct GImage *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  struct GImage *v8; // esi
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // eax
  GFxGlyphRasterCache *v11; // [esp+0h] [ebp-4h]

  v11 = this;
  if ( *((_DWORD *)this + 180) != 0 )
  {
    v6 = 0;
    if ( a6 != 0 )
    {
      v7 = a5;
      v8 = a2;
      do
      {
        v9 = (unsigned __int8 *)(*(_DWORD *)(*((_DWORD *)this + 180) + 24)
                               + v6 * *(_DWORD *)(*((_DWORD *)this + 180) + 20));
        v10 = &v8->pData[a3 + v8->Pitch * (v6 + a4)];
        if ( v7 != 0 )
        {
          do
          {
            *v10 = (unsigned __int16)((255 - *v9++) * *v10 + 255) >> 8;
            ++v10;
            --v7;
          }
          while ( v7 != 0 );
          v7 = a5;
          this = v11;
          v8 = a2;
        }
        ++v6;
      }
      while ( v6 < a6 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E8F0
// Name: public: void GArrayUnsafeBase<struct GFxGlyphBand,struct GAllocatorLH_POD<struct GFxGlyphBand,195>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<GFxGlyphBand,GAllocatorLH_POD<GFxGlyphBand,195>>::Reserve(
        int this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 195;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(
                          this: GMemory::pGlobalHeap,
                          a2: this,
                          a3: 48 * v5,
                          a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017E960
// Name: public: void GArrayUnsafeBase<struct GTexture::UpdateRect,struct GAllocatorLH_POD<struct GTexture::UpdateRect,195>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<GTexture::UpdateRect,GAllocatorLH_POD<GTexture::UpdateRect,195>>::Reserve(
        int this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 195;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(
                          this: GMemory::pGlobalHeap,
                          a2: this,
                          a3: 24 * v5,
                          a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017EA60
// Name: public: unsigned int GFxGlyphRasterCache::GetNumRasterizedGlyphs(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxGlyphRasterCache::GetNumRasterizedGlyphs(GFxGlyphRasterCache *this)
{
  unsigned int result; // eax

  result = *((_DWORD *)this + 485);
  if ( result != 0 )
    return *(_DWORD *)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017F860
// Name: public: void GFxGlyphSlotQueue::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::Clear(GFxGlyphSlotQueue *this)
{
  unsigned int v2; // ecx
  int v3; // edx
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // edi

  GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::~GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>(this: (int *)this + 33);
  *((_DWORD *)this + 12) = (char *)this + 48;
  *((_DWORD *)this + 13) = (char *)this + 48;
  *((_DWORD *)this + 20) = (char *)this + 60;
  *((_DWORD *)this + 21) = (char *)this + 60;
  v2 = 0;
  if ( *((_DWORD *)this + 34) != 0 )
  {
    v3 = 0;
    do
    {
      v4 = *((_DWORD *)this + 30) + v3 + 8;
      ++v2;
      *(_DWORD *)(v4 + 12) = v4;
      *(_DWORD *)(v4 + 16) = v4;
      v3 += 48;
    }
    while ( v2 < *((_DWORD *)this + 34) );
  }
  v5 = *((_DWORD **)this + 7);
  if ( v5 != nullptr )
  {
    do
    {
      v6 = (_DWORD *)v5[1270];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      v5 = v6;
    }
    while ( v6 != nullptr );
  }
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 127;
  *((_DWORD *)this + 10) = 0;
  v7 = *((_DWORD **)this + 25);
  if ( v7 != nullptr )
  {
    do
    {
      v8 = (_DWORD *)v7[1143];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      v7 = v8;
    }
    while ( v8 != nullptr );
  }
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 27) = 127;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 34) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017F920
// Name: private: struct GFxGlyphDynaSlot __near * GFxGlyphSlotQueue::initNewSlot(struct GFxGlyphBand __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphDynaSlot *__thiscall GFxGlyphSlotQueue::initNewSlot(
        GFxGlyphSlotQueue *this,
        struct GFxGlyphBand *a2,
        __int16 a3,
        __int16 a4)
{
  unsigned int *v5; // esi
  unsigned int *v6; // eax
  __int16 v7; // cx
  unsigned int v9; // [esp+8h] [ebp-8h]
  unsigned int v10; // [esp+Ch] [ebp-4h]

  v5 = GListAllocBase<GFxGlyphDynaSlot,127,GAllocatorLH_POD<GFxGlyphDynaSlot,195>>::Alloc(this: (unsigned int *)this + 7);
  v6 = GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(this: (unsigned int *)this + 25);
  v5[2] = (unsigned int)v6;
  v5[7] = (unsigned int)a2;
  *((_WORD *)v5 + 16) = *(_WORD *)a2;
  *((_WORD *)v5 + 17) = a3;
  *((_WORD *)v5 + 18) = a4;
  *((_WORD *)v5 + 19) = 0;
  *v6 = 0;
  v6[4] = 0;
  v6[5] = 0;
  v6[3] = (unsigned int)v5;
  v6[1] = 0;
  v6[2] = 0x100000;
  LOWORD(v9) = *((_WORD *)v5 + 17);
  v7 = *((_WORD *)a2 + 2);
  HIWORD(v9) = *((_WORD *)a2 + 1);
  LOWORD(v10) = *((_WORD *)v5 + 18);
  v6[6] = v9;
  HIWORD(v10) = v7;
  v6[7] = v10;
  v6[8] = 0;
  return (struct GFxGlyphDynaSlot *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1017F9C0
// Name: private: void GFxGlyphRasterCache::releaseAllTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::releaseAllTextures(GFxGlyphRasterCache *this)
{
  GFxGlyphRasterCache *v1; // eax
  unsigned int v2; // ebx
  _DWORD *v3; // esi
  void (__thiscall ***v4)(_DWORD, int); // edi

  v1 = this;
  v2 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v3 = (_DWORD *)((char *)this + 56);
    do
    {
      if ( *v3 != 0 )
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)*v3 + 44))(a1: *v3, a2: v3 + 1);
        v4 = (void (__thiscall ***)(_DWORD, int))*v3;
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(*v3 + 4), Value: -1) == 1 && v4 != nullptr )
          (**v4)(a1: v4, a2: 1);
        v1 = this;
        *v3 = 0;
      }
      v3[4] = 0;
      ++v2;
      v3 += 5;
    }
    while ( v2 < *((_DWORD *)v1 + 2) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FA30
// Name: private: void GFxGlyphRasterCache::stackBlur(class GImage __near &,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::stackBlur(
        void **this,
        struct GImage *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int k,
        unsigned int a8)
{
  struct GImage *v8; // ebx
  unsigned int v9; // edi
  void *v10; // eax
  int v11; // ecx
  unsigned __int8 *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // edx
  int v15; // esi
  _BYTE *v16; // edi
  int v17; // esi
  unsigned __int8 *v18; // esi
  unsigned int j; // edx
  _BYTE *v20; // ebx
  int v21; // ebx
  unsigned __int8 *v22; // edx
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // edx
  unsigned int v25; // ebx
  unsigned __int8 *v26; // esi
  unsigned __int8 *v27; // edx
  unsigned int v28; // ecx
  unsigned int v29; // ecx
  unsigned int v30; // edx
  unsigned __int8 *v31; // ebx
  unsigned __int8 *v32; // ebx
  int v33; // ecx
  bool v34; // zf
  unsigned int v35; // edi
  char *v36; // eax
  void *v37; // eax
  char *v38; // ecx
  unsigned int v39; // ecx
  unsigned __int8 *v40; // ecx
  unsigned __int8 *v41; // eax
  unsigned int v42; // edx
  int v43; // esi
  int v44; // edi
  _BYTE *v45; // esi
  unsigned int v46; // edx
  int v47; // ebx
  int v48; // ebx
  unsigned int v49; // esi
  unsigned int v50; // ecx
  unsigned __int8 *pData; // edx
  unsigned __int8 *v52; // esi
  unsigned __int8 *v53; // edx
  unsigned int v54; // ebx
  unsigned int v55; // ecx
  unsigned int v56; // ecx
  unsigned int v57; // edx
  unsigned __int8 *v58; // ebx
  unsigned __int8 *v59; // ebx
  int v60; // ecx
  int i; // [esp+Ch] [ebp-34h] BYREF
  unsigned int v62; // [esp+10h] [ebp-30h]
  int Pitch; // [esp+14h] [ebp-2Ch]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned __int8 *v66; // [esp+20h] [ebp-20h]
  _BYTE *v67; // [esp+24h] [ebp-1Ch]
  unsigned __int8 *v68; // [esp+28h] [ebp-18h]
  void **v69; // [esp+2Ch] [ebp-14h]
  unsigned int v70; // [esp+30h] [ebp-10h]
  unsigned int v71; // [esp+34h] [ebp-Ch]
  unsigned int v72; // [esp+38h] [ebp-8h]
  unsigned int v73; // [esp+3Ch] [ebp-4h]

  v8 = a2;
  v9 = k;
  v69 = this;
  if ( k != 0 )
  {
    if ( k > 0xFE )
    {
      v9 = 254;
      k = 254;
    }
    v65 = (unsigned __int16)GFx_StackBlurMul[v9];
    v64 = (unsigned __int8)GFx_StackBlurShr[v9];
    if ( 2 * v9 + 1 > (unsigned int)*(this + 183) )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(this + 181));
      v72 = (unsigned int)(v69 + 181);
      v69[183] = (void *)(2 * v9 + 1);
      if ( 2 * v9 == -1 )
      {
        v10 = nullptr;
      }
      else
      {
        i = 195;
        v10 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v72, a3: 2 * v9 + 1, a4: &i);
      }
      this = v69;
      v69[181] = v10;
    }
    *(this + 182) = (void *)(2 * v9 + 1);
    if ( a6 != 0 )
    {
      v72 = a4;
      for ( i = a6; i != 0; --i )
      {
        v11 = (int)&v8->pData[v72 * v8->Pitch];
        v67 = nullptr;
        v12 = (unsigned __int8 *)(a3 + v11);
        v66 = nullptr;
        v13 = *v12;
        v73 = 0;
        v68 = nullptr;
        v71 = 0;
        v14 = 0;
        if ( (int)(v9 + 1) < 2 )
          goto LABEL_15;
        v15 = 2 * v13;
        Pitch = 2 * v13;
        v70 = v13;
        v73 = 2 * v13 * ((v9 + 1) >> 1);
        do
        {
          *((_BYTE *)v69[181] + v14) = v13;
          v67 += v70;
          v16 = v69[181];
          v70 += v15;
          v16[v14 + 1] = v13;
          v66 += Pitch;
          Pitch += v15;
          v9 = k;
          v14 += 2;
        }
        while ( v14 <= k - 1 );
        if ( v14 > k )
        {
          v17 = v71;
        }
        else
        {
LABEL_15:
          *((_BYTE *)v69[181] + v14) = v13;
          v17 = v13 * (v14 + 1);
          v73 += v13;
        }
        v18 = &v67[(_DWORD)v66 + v17];
        for ( j = 1; j <= v9; v18 += v21 )
        {
          if ( j <= a5 - 1 )
            ++v12;
          v13 = *v12;
          v20 = v69[181];
          v68 += v13;
          v20[j + v9] = v13;
          v21 = v13 * (v9 - j++ + 1);
        }
        v8 = a2;
        v70 = v9;
        v71 = v9;
        if ( v9 > a5 - 1 )
          v71 = a5 - 1;
        v22 = &a2->pData[v72 * a2->Pitch];
        v23 = &v22[v71 + a3];
        v24 = &v22[a3];
        Pitch = (int)v23;
        if ( a5 != 0 )
        {
          v62 = a5;
          while ( 1 )
          {
            v25 = v65 * (_DWORD)v18;
            v26 = (int)&v18[-v73];
            v27 = v24 + 1;
            v28 = v70 - v9;
            *(v27 - 1) = v25 >> v64;
            v66 = v27;
            v29 = v28 + 2 * v9 + 1;
            v30 = 2 * v9 + 1;
            if ( v29 >= v30 )
              v29 -= v30;
            v67 = (char *)v69[181] + v29;
            v73 -= (unsigned __int8)*v67;
            if ( v71 < a5 - 1 )
            {
              ++v71;
              v13 = *(unsigned __int8 *)++Pitch;
            }
            v31 = v68;
            *v67 = v13;
            v32 = &v31[v13];
            v18 = &v32[v26];
            if ( ++v70 >= v30 )
              v70 = 0;
            v33 = *((unsigned __int8 *)v69[181] + v70);
            v73 += v33;
            v34 = v62-- == 1;
            v68 = &v32[-v33];
            if ( v34 )
              break;
            v24 = v66;
          }
          v8 = a2;
        }
        ++v72;
      }
      this = v69;
    }
  }
  v35 = a8;
  if ( a8 != 0 )
  {
    if ( a8 > 0xFE )
    {
      v35 = 254;
      a8 = 254;
    }
    v65 = (unsigned __int16)GFx_StackBlurMul[v35];
    v64 = (unsigned __int8)GFx_StackBlurShr[v35];
    v36 = (char *)(this + 181);
    v72 = (unsigned int)(this + 181);
    if ( 2 * v35 + 1 > (unsigned int)*(this + 183) )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v36);
      *(_DWORD *)(v72 + 8) = 2 * v35 + 1;
      if ( 2 * v35 == -1 )
      {
        v37 = nullptr;
      }
      else
      {
        k = 195;
        v37 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v72, a3: 2 * v35 + 1, a4: &k);
      }
      v38 = (char *)v72;
      *(_DWORD *)v72 = v37;
      v36 = v38;
    }
    *((_DWORD *)v36 + 1) = 2 * v35 + 1;
    Pitch = v8->Pitch;
    for ( k = 0; k < a5; ++k )
    {
      v39 = (unsigned int)&v8->pData[a4 * v8->Pitch];
      v67 = nullptr;
      v69 = nullptr;
      v40 = (unsigned __int8 *)(a3 + k + v39);
      v73 = 0;
      v41 = (unsigned __int8 *)*v40;
      v68 = nullptr;
      v71 = 0;
      v42 = 0;
      if ( (int)(v35 + 1) < 2 )
        goto LABEL_49;
      v43 = 2 * (_DWORD)v41;
      i = 2 * (_DWORD)v41;
      v66 = v41;
      v73 = 2 * (_DWORD)v41 * ((v35 + 1) >> 1);
      do
      {
        *(_BYTE *)(v42 + *(_DWORD *)v72) = (_BYTE)v41;
        v67 = &v67[(_DWORD)v66];
        v44 = *(_DWORD *)v72;
        v66 += v43;
        *(_BYTE *)(v44 + v42 + 1) = (_BYTE)v41;
        v69 = (void **)((char *)v69 + i);
        i += v43;
        v35 = a8;
        v42 += 2;
      }
      while ( v42 <= a8 - 1 );
      v8 = a2;
      if ( v42 <= a8 )
      {
LABEL_49:
        *(_BYTE *)(v42 + *(_DWORD *)v72) = (_BYTE)v41;
        v73 += (unsigned int)v41;
        v71 = (_DWORD)v41 * (v42 + 1);
      }
      v45 = &v67[(_DWORD)v69 + v71];
      v46 = 1;
      v71 = (unsigned int)v45;
      if ( v35 != 0 )
      {
        do
        {
          if ( v46 <= a6 - 1 )
            v40 += Pitch;
          v41 = (unsigned __int8 *)*v40;
          v47 = *(_DWORD *)v72;
          v68 = &v68[(_DWORD)v41];
          *(_BYTE *)(v46 + v47 + v35) = (_BYTE)v41;
          v48 = (_DWORD)v41 * (v35 - v46++ + 1);
          v45 += v48;
        }
        while ( v46 <= v35 );
        v8 = a2;
        v71 = (unsigned int)v45;
      }
      v49 = v35;
      v70 = v35;
      v69 = (void **)v35;
      if ( v35 > a6 - 1 )
      {
        v49 = a6 - 1;
        v69 = (void **)(a6 - 1);
      }
      v50 = v8->Pitch;
      pData = v8->pData;
      v52 = &pData[v50 * (a4 + v49) + k + a3];
      v53 = &pData[a4 * v50 + k + a3];
      if ( a6 != 0 )
      {
        i = a6;
        while ( 1 )
        {
          v54 = (v65 * v71) >> v64;
          v71 -= v73;
          v55 = v70;
          *v53 = v54;
          v66 = &v53[Pitch];
          v56 = v55 - v35 + 2 * v35 + 1;
          v57 = 2 * v35 + 1;
          if ( v56 >= v57 )
            v56 -= v57;
          v67 = (_BYTE *)(*(_DWORD *)v72 + v56);
          v73 -= (unsigned __int8)*v67;
          if ( (unsigned int)v69 < a6 - 1 )
          {
            v52 += Pitch;
            v69 = (void **)((char *)v69 + 1);
            v41 = (unsigned __int8 *)*v52;
          }
          v58 = v68;
          *v67 = (_BYTE)v41;
          v59 = &v58[(_DWORD)v41];
          v71 += (unsigned int)v59;
          if ( ++v70 >= v57 )
            v70 = 0;
          v60 = *(unsigned __int8 *)(*(_DWORD *)v72 + v70);
          v73 += v60;
          v34 = i-- == 1;
          v68 = &v59[-v60];
          if ( v34 )
            break;
          v53 = v66;
        }
        v8 = a2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FF40
// Name: public: void GFxGlyphRasterCache::UpdateTextures(class GRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::UpdateTextures(GFxGlyphRasterCache *this, struct GRenderer *a2)
{
  unsigned int v3; // ebx
  GTexture **v4; // edi
  GTexture *v5; // eax
  unsigned int v6; // ebx
  _DWORD *v7; // ecx
  unsigned int v8; // eax
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // edx
  int v12; // ebx
  _DWORD *Instance; // eax
  int v14; // eax
  const GImageBase *v15; // eax
  unsigned int v16; // [esp+8h] [ebp-14h]
  unsigned int v17; // [esp+Ch] [ebp-10h]
  int v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]

  v3 = 0;
  v19 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v4 = (GTexture **)((char *)this + 56);
    do
    {
      if ( v4[4] != nullptr )
      {
        if ( *v4 != nullptr
          || (v5 = a2->CreateTexture(this: a2), *v4 = v5, v5 != nullptr)
          && (v4[3] = (GTexture *)(v3 & 0xFFFF7FFF),
              v4[2] = (GTexture *)this,
              ((void (__stdcall *)(GTexture **))(*v4)->AddChangeHandler)(a1: v4 + 1),
              (*v4)->InitDynamicTexture(
                this: *v4,
                a2: *(_DWORD *)this,
                a3: *((_DWORD *)this + 1),
                a4: Image_A_8,
                a5: 0,
                a6: 16u)) )
        {
          v6 = (unsigned int)v4[4];
          GArrayUnsafeBase<GTexture::UpdateRect,GAllocatorLH_POD<GTexture::UpdateRect,195>>::Reserve(
            this: (int)this + 44,
            a2: v6,
            a3: 32);
          v8 = 0;
          *((_DWORD *)this + 12) = v6;
          v20 = 0;
          v17 = 0;
          if ( *((_DWORD *)this + 7) != 0 )
          {
            v18 = 0;
            do
            {
              v7 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 10) + 4 * (v8 >> 6)) + 28 * (v8 & 0x3F));
              if ( v7[6] == v19 )
              {
                ++v20;
                v9 = (_DWORD *)(v18 + *((_DWORD *)this + 11));
                v18 += 24;
                v10 = v7[1];
                *v9 = *v7;
                v9[1] = v10;
                v11 = v7[5];
                v16 = v7[4];
                v12 = v7[3];
                v9[2] = v7[2];
                v7 = (_DWORD *)v16;
                v9[3] = v12;
                v9[4] = v16;
                v9[5] = v11;
              }
              v8 = v17 + 1;
              v17 = v8;
            }
            while ( v8 < *((_DWORD *)this + 7) );
          }
          Instance = GFxAmpServer::GetInstance(this: v7);
          ++Instance[115];
          v14 = *((_DWORD *)this + 174);
          if ( v14 != 0 )
            v15 = (const GImageBase *)(v14 + 8);
          else
            v15 = nullptr;
          (*v4)->Update(this: *v4, a2: 0, a3: v20, a4: *((const GTexture::UpdateRect **)this + 11), a5: v15);
          v3 = v19;
        }
        v4[4] = nullptr;
      }
      ++v3;
      v4 += 5;
      v19 = v3;
    }
    while ( v3 < *((_DWORD *)this + 2) );
  }
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10180260
// Name: private: void GFxGlyphSlotQueue::splitSlot(struct GFxGlyphDynaSlot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::splitSlot(GFxGlyphSlotQueue *this, struct GFxGlyphBand **a2, __int16 a3)
{
  struct GFxGlyphDynaSlot *inited; // eax
  struct GFxGlyphBand *v5; // ecx
  struct GFxGlyphBand *v6; // ecx

  inited = GFxGlyphSlotQueue::initNewSlot(this, a2: a2[7], a3: a3 + *((_WORD *)a2 + 17), a4: *((_WORD *)a2 + 18) - a3);
  v5 = a2[2];
  *((_WORD *)a2 + 18) = a3;
  *((_WORD *)v5 + 14) = a3;
  *((_DWORD *)inited + 1) = *((_DWORD *)this + 13);
  *(_DWORD *)inited = (char *)this + 48;
  **((_DWORD **)this + 13) = inited;
  *((_DWORD *)this + 13) = inited;
  ++*((_DWORD *)this + 14);
  v6 = a2[4];
  *((_DWORD *)inited + 3) = a2;
  *((_DWORD *)inited + 4) = v6;
  *((_DWORD *)v6 + 3) = inited;
  a2[4] = inited;
  *((_DWORD *)inited + 6) = *((_DWORD *)this + 21);
  *((_DWORD *)inited + 5) = (char *)this + 60;
  *(_DWORD *)(*((_DWORD *)this + 21) + 20) = inited;
  *((_DWORD *)this + 21) = inited;
}

//------------------------------------------------------------------------------
// Address: 0x101802E0
// Name: private: void GFxGlyphSlotQueue::splitGlyph(struct GFxGlyphDynaSlot __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::splitGlyph(
        GFxGlyphSlotQueue *this,
        struct GFxGlyphDynaSlot *a2,
        bool a3,
        __int16 a4)
{
  int v5; // eax
  __int16 v7; // bx
  __int16 v8; // ax
  struct GFxGlyphDynaSlot *inited; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  char *v13; // edi
  struct GFxGlyphDynaSlot *v14; // [esp+14h] [ebp+8h]

  v5 = *((_DWORD *)a2 + 2);
  v7 = *(_WORD *)(v5 + 28) - a4;
  v14 = (struct GFxGlyphDynaSlot *)v5;
  v8 = *(_WORD *)(v5 + 24);
  if ( a3 )
  {
    inited = GFxGlyphSlotQueue::initNewSlot(this, a2: *((struct GFxGlyphBand **)a2 + 7), a3: v8, a4: v7);
    v10 = *((_DWORD *)a2 + 3);
    *((_DWORD *)inited + 4) = a2;
    *((_DWORD *)inited + 3) = v10;
    *(_DWORD *)(v10 + 16) = inited;
    *((_WORD *)a2 + 17) += v7;
    LOWORD(v10) = *((_WORD *)a2 + 17);
    *((_DWORD *)a2 + 3) = inited;
    *((_WORD *)v14 + 12) = v10;
  }
  else
  {
    inited = GFxGlyphSlotQueue::initNewSlot(this, a2: *((struct GFxGlyphBand **)a2 + 7), a3: a4 + v8, a4: v7);
    v11 = *((_DWORD *)a2 + 4);
    *((_DWORD *)inited + 3) = a2;
    *((_DWORD *)inited + 4) = v11;
    *(_DWORD *)(v11 + 12) = inited;
    *((_DWORD *)a2 + 4) = inited;
  }
  *((_WORD *)v14 + 14) = a4;
  *((_WORD *)a2 + 18) -= v7;
  *((_DWORD *)inited + 1) = *((_DWORD *)this + 13);
  *(_DWORD *)inited = (char *)this + 48;
  **((_DWORD **)this + 13) = inited;
  *((_DWORD *)this + 13) = inited;
  ++*((_DWORD *)this + 14);
  v12 = *((_DWORD *)this + 21);
  v13 = (char *)this + 60;
  *((_DWORD *)inited + 5) = v13;
  *((_DWORD *)inited + 6) = v12;
  *(_DWORD *)(*((_DWORD *)v13 + 6) + 20) = inited;
  *((_DWORD *)v13 + 6) = inited;
}

//------------------------------------------------------------------------------
// Address: 0x10180390
// Name: private: void GFxGlyphSlotQueue::releaseGlyphTree(struct GFxGlyphNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::releaseGlyphTree(struct GFxGlyphNode **this, struct GFxGlyphNode **a2)
{
  if ( a2 != nullptr )
  {
    GFxGlyphSlotQueue::releaseGlyphTree((GFxGlyphSlotQueue *)this, a2: a2[4]);
    GFxGlyphSlotQueue::releaseGlyphTree((GFxGlyphSlotQueue *)this, a2: a2[5]);
    if ( *a2 != nullptr )
      GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::RemoveAlt<GFxGlyphParam>(
        this: this + 33,
        (int *)a2);
    *a2 = nullptr;
    *a2 = *(this + 28);
    *(this + 28) = (struct GFxGlyphNode *)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101803E0
// Name: private: void GFxGlyphSlotQueue::releaseSlot(struct GFxGlyphDynaSlot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::releaseSlot(struct GFxGlyphNode **this, struct GFxGlyphDynaSlot *a2)
{
  int v2; // ebx
  int v4; // ebx
  int v5; // eax
  __int16 v6; // cx
  int v7; // eax
  int v8; // eax
  __int16 v9; // ax
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 16);
  if ( v2 != 0 )
  {
    GFxGlyphSlotQueue::releaseGlyphTree(this, a2: *(struct GFxGlyphNode ***)(v2 + 16));
    GFxGlyphSlotQueue::releaseGlyphTree(this, a2: *(struct GFxGlyphNode ***)(v2 + 20));
    if ( *(_DWORD *)v2 != 0 )
      GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::RemoveAlt<GFxGlyphParam>(
        this: this + 33,
        a2: (int *)v2);
    *(_DWORD *)v2 = 0;
    *(_DWORD *)v2 = *(this + 28);
    *(this + 28) = (struct GFxGlyphNode *)v2;
  }
  v4 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 20);
  if ( v4 != 0 )
  {
    GFxGlyphSlotQueue::releaseGlyphTree(this, a2: *(struct GFxGlyphNode ***)(v4 + 16));
    GFxGlyphSlotQueue::releaseGlyphTree(this, a2: *(struct GFxGlyphNode ***)(v4 + 20));
    if ( *(_DWORD *)v4 != 0 )
      GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::RemoveAlt<GFxGlyphParam>(
        this: this + 33,
        a2: (int *)v4);
    *(_DWORD *)v4 = 0;
    *(_DWORD *)v4 = *(this + 28);
    *(this + 28) = (struct GFxGlyphNode *)v4;
  }
  if ( **((_DWORD **)a2 + 2) != 0 )
    GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::RemoveAlt<GFxGlyphParam>(
      this: this + 33,
      a2: *((int **)a2 + 2));
  v5 = *((_DWORD *)a2 + 7);
  v6 = *(_WORD *)(v5 + 6);
  if ( v6 != 0 && a2 == *(struct GFxGlyphDynaSlot **)(v5 + 20) )
  {
    *((_WORD *)a2 + 18) += v6;
    *(_WORD *)(v5 + 6) = 0;
  }
  **((_DWORD **)a2 + 2) = 0;
  v7 = *((_DWORD *)a2 + 7);
  LOWORD(v10) = *((_WORD *)a2 + 17);
  HIWORD(v10) = *(_WORD *)(v7 + 2);
  HIWORD(v11) = *(_WORD *)(v7 + 4);
  v8 = *((_DWORD *)a2 + 2);
  LOWORD(v11) = *((_WORD *)a2 + 18);
  *(_DWORD *)(v8 + 24) = v10;
  *(_DWORD *)(v8 + 28) = v11;
  *(_DWORD *)(*((_DWORD *)a2 + 2) + 16) = 0;
  *(_DWORD *)(*((_DWORD *)a2 + 2) + 20) = 0;
  v9 = *((_WORD *)a2 + 16);
  *((_WORD *)a2 + 19) = 0;
  if ( (v9 & 0x4000) != 0 )
  {
    *((_WORD *)a2 + 16) = v9 & 0xBFFF;
    *((_DWORD *)a2 + 6) = *(this + 21);
    *((_DWORD *)a2 + 5) = this + 15;
    *((_DWORD *)*(this + 21) + 5) = a2;
    *(this + 21) = a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180520
// Name: private: void GFxGlyphSlotQueue::mergeSlots(struct GFxGlyphDynaSlot __near *,struct GFxGlyphDynaSlot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::mergeSlots(
        struct GFxGlyphNode **this,
        struct GFxGlyphDynaSlot *a2,
        struct GFxGlyphDynaSlot *a3,
        __int16 a4)
{
  struct GFxGlyphDynaSlot *i; // esi
  struct GFxGlyphNode *v7; // eax
  int v8; // ecx
  struct GFxGlyphDynaSlot *v9; // [esp+14h] [ebp+8h]

  for ( i = a2; ; i = v9 )
  {
    v9 = *((struct GFxGlyphDynaSlot **)i + 4);
    GFxGlyphSlotQueue::releaseSlot(this, a2: i);
    if ( i != a2 )
    {
      v7 = *((struct GFxGlyphNode **)i + 2);
      *(_DWORD *)v7 = *(this + 28);
      *(this + 28) = v7;
      *(_DWORD *)(*(_DWORD *)i + 4) = *((_DWORD *)i + 1);
      **((_DWORD **)i + 1) = *(_DWORD *)i;
      *(this + 14) = (struct GFxGlyphNode *)((char *)*(this + 14) - 1);
      if ( (*((_WORD *)i + 16) & 0x4000) == 0 )
      {
        *(_DWORD *)(*((_DWORD *)i + 5) + 24) = *((_DWORD *)i + 6);
        *(_DWORD *)(*((_DWORD *)i + 6) + 20) = *((_DWORD *)i + 5);
      }
      *(_DWORD *)(*((_DWORD *)i + 3) + 16) = *((_DWORD *)i + 4);
      *(_DWORD *)(*((_DWORD *)i + 4) + 12) = *((_DWORD *)i + 3);
      *(_DWORD *)i = *(this + 10);
      *(this + 10) = i;
    }
    if ( i == a3 )
      break;
  }
  v8 = *((_DWORD *)a2 + 2);
  *((_WORD *)a2 + 18) = a4;
  *(_WORD *)(v8 + 28) = a4;
  *(_DWORD *)(*(_DWORD *)a2 + 4) = *((_DWORD *)a2 + 1);
  **((_DWORD **)a2 + 1) = *(_DWORD *)a2;
  *((_DWORD *)a2 + 1) = *(this + 13);
  *(_DWORD *)a2 = this + 12;
  *(_DWORD *)*(this + 13) = a2;
  *(this + 13) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x101805E0
// Name: private: struct GFxGlyphDynaSlot __near * GFxGlyphSlotQueue::mergeSlotWithNeighbor(struct GFxGlyphDynaSlot __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphDynaSlot *__thiscall GFxGlyphSlotQueue::mergeSlotWithNeighbor(
        struct GFxGlyphNode **this,
        struct GFxGlyphDynaSlot *a2)
{
  int v3; // edi
  struct GFxGlyphNode *v4; // ebx
  int v5; // edx
  int v6; // esi
  bool v7; // zf
  __int16 v8; // ax
  int v10; // [esp+8h] [ebp-18h]
  int v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+Ch] [ebp-14h]
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+1Ch] [ebp-4h]
  char v16; // [esp+2Bh] [ebp+Bh]

  v3 = *((_DWORD *)a2 + 4);
  v14 = *((_DWORD *)a2 + 7);
  v16 = 1;
  if ( v3 == v14 + 8 )
  {
    v3 = *((_DWORD *)a2 + 3);
    v16 = 0;
    if ( v3 == v14 + 8 )
      return nullptr;
  }
  v4 = *((struct GFxGlyphNode **)a2 + 2);
  v11 = *(_DWORD *)(v3 + 8);
  GFxGlyphSlotQueue::releaseSlot(this, a2);
  v5 = *((unsigned __int16 *)a2 + 18);
  v15 = *((unsigned __int16 *)a2 + 17);
  *(_DWORD *)(*(_DWORD *)a2 + 4) = *((_DWORD *)a2 + 1);
  **((_DWORD **)a2 + 1) = *(_DWORD *)a2;
  *(this + 14) = (struct GFxGlyphNode *)((char *)*(this + 14) - 1);
  if ( (*((_WORD *)a2 + 16) & 0x4000) == 0 )
  {
    *(_DWORD *)(*((_DWORD *)a2 + 5) + 24) = *((_DWORD *)a2 + 6);
    *(_DWORD *)(*((_DWORD *)a2 + 6) + 20) = *((_DWORD *)a2 + 5);
  }
  *(_DWORD *)(*((_DWORD *)a2 + 3) + 16) = *((_DWORD *)a2 + 4);
  *(_DWORD *)(*((_DWORD *)a2 + 4) + 12) = *((_DWORD *)a2 + 3);
  *(_DWORD *)a2 = *(this + 10);
  *(this + 10) = a2;
  if ( *(_DWORD *)v11 != 0
    || *(_DWORD *)(v11 + 20) != 0
    || *(_WORD *)(v11 + 30) != *(_WORD *)(v14 + 4)
    || ((v6 = *(unsigned __int16 *)(v11 + 24), v16 == 0)
      ? (v7 = v6 + *(unsigned __int16 *)(v11 + 28) == v15)
      : (v7 = v15 + v5 == v6),
        !v7) )
  {
    *((_DWORD *)v4 + 4) = v11;
    LOWORD(v10) = v15;
    *((_DWORD *)v4 + 5) = 0;
    *((_DWORD *)v4 + 3) = v3;
    HIWORD(v10) = *(_WORD *)(v14 + 2);
    HIWORD(v12) = *(_WORD *)(v14 + 4);
    *((_DWORD *)v4 + 6) = v10;
    LOWORD(v12) = v5;
    *((_DWORD *)v4 + 7) = v12;
    *(_DWORD *)(v3 + 8) = v4;
  }
  else
  {
    *(_DWORD *)v4 = *(this + 28);
    *(this + 28) = v4;
    if ( v16 != 0 )
      *(_WORD *)(v11 + 24) = v15;
    *(_WORD *)(v11 + 28) += v5;
  }
  if ( v16 != 0 )
    *(_WORD *)(v3 + 34) = v15;
  v8 = *(_WORD *)(v3 + 32);
  *(_WORD *)(v3 + 36) += v5;
  if ( (v8 & 0x4000) != 0 )
  {
    *(_WORD *)(v3 + 32) = v8 & 0xBFFF;
    *(_WORD *)(v3 + 38) = 0;
    *(_DWORD *)(v3 + 24) = *(this + 21);
    *(_DWORD *)(v3 + 20) = this + 15;
    *((_DWORD *)*(this + 21) + 5) = v3;
    *(this + 21) = (struct GFxGlyphNode *)v3;
  }
  return (struct GFxGlyphDynaSlot *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10180770
// Name: public: void GFxGlyphSlotQueue::CleanUpTexture(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::CleanUpTexture(GFxGlyphSlotQueue *this, unsigned int a2)
{
  char *v2; // esi
  char *v3; // edi
  char *v4; // ebx
  GFxGlyphSlotQueue *v5; // [esp+8h] [ebp-4h]

  v2 = *((char **)this + 13);
  v3 = (char *)this + 48;
  v5 = this;
  if ( v2 != (char *)this + 48 )
  {
    do
    {
      v4 = *((char **)v2 + 1);
      if ( (*((_WORD *)v2 + 16) & 0x3FFF) == a2 )
      {
        GFxGlyphSlotQueue::releaseSlot((struct GFxGlyphNode **)this, a2: (struct GFxGlyphDynaSlot *)v2);
        *(_DWORD *)(*(_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
        **((_DWORD **)v2 + 1) = *(_DWORD *)v2;
        this = v5;
        *((_DWORD *)v2 + 1) = *((_DWORD *)v3 + 1);
        *(_DWORD *)v2 = v3;
        **((_DWORD **)v3 + 1) = v2;
        *((_DWORD *)v3 + 1) = v2;
      }
      v2 = v4;
    }
    while ( v4 != v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101807D0
// Name: public: void GFxGlyphSlotQueue::CleanUpFont(class GFxFontResource const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::CleanUpFont(GFxGlyphSlotQueue *this, const struct GFxFontResource *a2)
{
  char *v2; // esi
  char *v3; // edi
  int v4; // ecx
  char *v5; // ebx
  const struct GFxGlyphNode *FontInSlot; // eax
  const struct GFxFontResource *v7; // edx
  int v8; // ecx

  v2 = *((char **)this + 13);
  v3 = (char *)this + 48;
  if ( v2 != (char *)this + 48 )
  {
    do
    {
      v4 = *((_DWORD *)v2 + 2);
      v5 = *((char **)v2 + 1);
      if ( v4 != 0 )
      {
        if ( *(const struct GFxFontResource **)v4 == a2 )
        {
          FontInSlot = *((const struct GFxGlyphNode **)v2 + 2);
        }
        else
        {
          if ( GFxGlyphSlotQueue::findFontInSlot(a1: *(struct GFxGlyphNode **)(v4 + 16), a2) != nullptr )
            goto LABEL_8;
          FontInSlot = GFxGlyphSlotQueue::findFontInSlot(a1: *(struct GFxGlyphNode **)(v8 + 20), a2: v7);
        }
        if ( FontInSlot != nullptr )
        {
LABEL_8:
          GFxGlyphSlotQueue::releaseSlot((struct GFxGlyphNode **)this, a2: (struct GFxGlyphDynaSlot *)v2);
          *(_DWORD *)(*(_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
          **((_DWORD **)v2 + 1) = *(_DWORD *)v2;
          *((_DWORD *)v2 + 1) = *((_DWORD *)v3 + 1);
          *(_DWORD *)v2 = v3;
          **((_DWORD **)v3 + 1) = v2;
          *((_DWORD *)v3 + 1) = v2;
        }
      }
      v2 = v5;
    }
    while ( v5 != v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180860
// Name: public: void GFxGlyphRasterCache::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::Clear(GFxGlyphRasterCache *this)
{
  GFxGlyphRasterCache::releaseAllTextures(this);
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
  GFxGlyphSlotQueue::Clear(this: (GFxGlyphRasterCache *)((char *)this + 1808));
}

//------------------------------------------------------------------------------
// Address: 0x10180890
// Name: public: void GFxGlyphRasterCache::Init(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::Init(
        GFxGlyphRasterCache *this,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8)
{
  char *v9; // edi
  unsigned int v10; // eax
  char v11; // dl
  char v12; // cl
  unsigned int v13; // eax
  unsigned int v14; // ebx
  int v15; // eax
  unsigned int v16; // ecx
  double v17; // st6
  GImage *v18; // eax
  GRefCountNTSImpl *v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // ecx
  unsigned int v22; // eax
  char *v23; // ecx
  int v24; // esi
  char i; // [esp+Ch] [ebp-8h]
  int v26; // [esp+10h] [ebp-4h]

  GFxGlyphRasterCache::releaseAllTextures(this);
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 12) = 0;
  v9 = (char *)this + 1808;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
  GFxGlyphSlotQueue::Clear(this: (GFxGlyphRasterCache *)((char *)this + 1808));
  if ( a2 >= 0x40 )
    v10 = a2 - 1;
  else
    v10 = 63;
  if ( a3 >= 0x40 )
    v26 = a3 - 1;
  else
    v26 = 63;
  v11 = 0;
  v12 = 0;
  for ( i = 0; v10 != 0; v10 >>= 1 )
    ++v12;
  v13 = v26;
  if ( v26 != 0 )
  {
    do
    {
      ++v11;
      v13 >>= 1;
    }
    while ( v13 != 0 );
    i = v11;
  }
  v14 = a4;
  if ( (unsigned int)a4 > 0x20 )
    v14 = 32;
  v15 = 1 << v12;
  *((_DWORD *)this + 3) = a5;
  v16 = a6;
  *(_DWORD *)this = v15;
  *((_DWORD *)this + 1) = 1 << i;
  *((_DWORD *)this + 2) = v14;
  *((_DWORD *)this + 4) = v16;
  a4 = 1 << i;
  *((float *)this + 5) = 1.0 / (double)(unsigned int)v15;
  v17 = (double)a4;
  if ( 1 << i < 0 )
    v17 = v17 + 4294967300.0;
  a4 = 3;
  *((float *)this + 6) = 1.0 / v17;
  v18 = (GImage *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 48, &a4);
  if ( v18 != nullptr )
    a4 = (int)GImage::GImage(this: v18, a2: IMAGE_FORMAT_RGB888_BLUESCREEN, a3: (a7 + 3) & 0xFFFFFFFC, a4: a8);
  else
    a4 = 0;
  v19 = *((GRefCountNTSImpl **)this + 174);
  if ( v19 != nullptr )
    GRefCountNTSImpl::Release(this: v19);
  v20 = a7;
  *((_DWORD *)this + 174) = a4;
  *((_DWORD *)this + 175) = v20;
  *((_DWORD *)this + 176) = a8;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
  GFxGlyphSlotQueue::Clear(this: (GFxGlyphRasterCache *)((char *)this + 1808));
  v21 = a5;
  *((_DWORD *)this + 455) = a2;
  *((_DWORD *)this + 456) = a3;
  v22 = a3 / v21;
  *((_DWORD *)this + 457) = v21;
  v23 = (char *)this + 1928;
  *((_DWORD *)this + 453) = 0;
  *((_DWORD *)this + 454) = v14;
  *((_DWORD *)this + 458) = v22;
  v24 = v14 * v22;
  GArrayUnsafeBase<GFxGlyphBand,GAllocatorLH_POD<GFxGlyphBand,195>>::Reserve(this: (int)v23, a2: v14 * v22, a3: 0);
  *((_DWORD *)v9 + 31) = v24;
}

//------------------------------------------------------------------------------
// Address: 0x10180A40
// Name: public: void GFxGlyphRasterCache::CleanUpFont(class GFxFontResource const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::CleanUpFont(GFxGlyphRasterCache *this, const struct GFxFontResource *a2)
{
  GFxGlyphSlotQueue::CleanUpFont(this: (GFxGlyphRasterCache *)((char *)this + 1808), a2);
}

//------------------------------------------------------------------------------
// Address: 0x10180BB0
// Name: public: GFxGlyphSlotQueue::GFxGlyphSlotQueue(void)
// Source: json
//------------------------------------------------------------------------------
GFxGlyphSlotQueue *__thiscall GFxGlyphSlotQueue::GFxGlyphSlotQueue(GFxGlyphSlotQueue *this)
{
  *(_DWORD *)this = 10;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 127;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = (char *)this + 28;
  *((_DWORD *)this + 12) = (char *)this + 48;
  *((_DWORD *)this + 13) = (char *)this + 48;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 20) = (char *)this + 60;
  *((_DWORD *)this + 21) = (char *)this + 60;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 127;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = (char *)this + 100;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10180C30
// Name: public: GFxGlyphSlotQueue::~GFxGlyphSlotQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphSlotQueue::~GFxGlyphSlotQueue(GFxGlyphSlotQueue *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // esi

  GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::~GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>(this: (int *)this + 33);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 30));
  v2 = *((_DWORD **)this + 25);
  if ( v2 != nullptr )
  {
    do
    {
      v3 = (_DWORD *)v2[1143];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
      v2 = v3;
    }
    while ( v3 != nullptr );
  }
  v4 = *((_DWORD **)this + 7);
  if ( v4 != nullptr )
  {
    do
    {
      v5 = (_DWORD *)v4[1270];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180CA0
// Name: public: GFxGlyphRasterCache::~GFxGlyphRasterCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::~GFxGlyphRasterCache(GFxGlyphRasterCache *this)
{
  GRefCountNTSImpl *v2; // ecx
  GRefCountNTSImpl *v3; // ecx
  int v4; // ecx
  _DWORD *v5; // eax

  GFxGlyphRasterCache::releaseAllTextures(this);
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
  GFxGlyphSlotQueue::Clear(this: (GFxGlyphRasterCache *)((char *)this + 1808));
  GFxGlyphSlotQueue::~GFxGlyphSlotQueue(this: (GFxGlyphRasterCache *)((char *)this + 1808));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 443));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 440));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 436);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 433));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 429);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 425);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 217));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 214));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 210);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 207));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 193);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 189);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 184));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 181));
  v2 = *((GRefCountNTSImpl **)this + 180);
  if ( v2 != nullptr )
    GRefCountNTSImpl::Release(this: v2);
  v3 = *((GRefCountNTSImpl **)this + 174);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  v4 = 31;
  v5 = (_DWORD *)((char *)this + 700);
  do
  {
    v5 -= 5;
    --v4;
    *v5 = &GTexture::ChangeHandler::`vftable';
  }
  while ( v4 >= 0 );
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 11));
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 7);
}

//------------------------------------------------------------------------------
// Address: 0x10180E20
// Name: public: void GFxGlyphRasterCache::CleanUpTexture(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::CleanUpTexture(GFxGlyphRasterCache *this, unsigned int a2, bool a3)
{
  unsigned int v3; // esi
  GFxGlyphRasterCache *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebx
  int v7; // edx
  int v8; // esi
  int v9; // edi
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // edx
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // esi
  char *v16; // ebx
  int v17; // esi
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-8h]
  unsigned int v21; // [esp+18h] [ebp-4h]

  v3 = a2;
  v4 = this;
  GFxGlyphSlotQueue::CleanUpTexture(this: (GFxGlyphRasterCache *)((char *)this + 1808), a2);
  v5 = 0;
  v6 = 0;
  v20 = 0;
  v21 = 0;
  if ( *((_DWORD *)v4 + 7) != 0 )
  {
    do
    {
      v7 = 4 * (v5 >> 6);
      v8 = 28 * (v5 & 0x3F);
      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 10) + v7) + v8 + 24) != a2 )
      {
        v9 = *((_DWORD *)v4 + 10);
        v10 = (_DWORD *)(*(_DWORD *)(v9 + 4 * (v6 >> 6)) + 28 * (v6 & 0x3F));
        v11 = *(_DWORD *)(v9 + v7);
        v12 = *(_DWORD *)(v11 + v8 + 4);
        v6 = v20 + 1;
        v13 = (_DWORD *)(v8 + v11);
        *v10 = *v13;
        v10[1] = v12;
        v14 = v13[5];
        v15 = v13[4];
        v19 = v13[3];
        v10[2] = v13[2];
        v10[3] = v19;
        v4 = this;
        v10[4] = v15;
        v10[5] = v14;
        ++v20;
        v10[6] = v13[6];
      }
      v5 = v21 + 1;
      v21 = v5;
    }
    while ( v5 < *((_DWORD *)v4 + 7) );
    v3 = a2;
  }
  if ( v6 < *((_DWORD *)v4 + 7) )
    *((_DWORD *)v4 + 7) = v6;
  v16 = (char *)v4 + 20 * v3;
  *((_DWORD *)v16 + 18) = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(_DWORD, unsigned int))(**((_DWORD **)v16 + 14) + 44))(
      a1: *((_DWORD *)v16 + 14),
      a2: (unsigned int)v4 + 20 * v3 + 60);
    v17 = *((_DWORD *)v16 + 14);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v17 + 4), Value: -1) == 1 && v17 != 0 )
      (**(void (__thiscall ***)(int, int))v17)(a1: v17, a2: 1);
    *((_DWORD *)v16 + 14) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181180
// Name: public: virtual void GFxGlyphRasterCache::TextureEventHandler::OnChange(class GRenderer __near *,enum GTexture::ChangeHandler::EventType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphRasterCache::TextureEventHandler::OnChange(
        GFxGlyphRasterCache::TextureEventHandler *this,
        struct GRenderer *a2,
        enum GTexture::ChangeHandler::EventType a3)
{
  if ( a3 == Event_DataLost )
  {
    GFxGlyphRasterCache::CleanUpTexture(this: *((GFxGlyphRasterCache **)this + 1), a2: *((_DWORD *)this + 2), a3: false);
  }
  else if ( a3 == 2 )
  {
    GFxGlyphRasterCache::CleanUpTexture(this: *((GFxGlyphRasterCache **)this + 1), a2: *((_DWORD *)this + 2), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101811C0
// Name: private: struct GFxGlyphNode __near * GFxGlyphSlotQueue::packGlyph(unsigned int,unsigned int,struct GFxGlyphNode __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphSlotQueue::packGlyph(
        GFxGlyphSlotQueue *this,
        unsigned int a2,
        unsigned int a3,
        struct GFxGlyphNode *a4)
{
  struct GFxGlyphNode *result; // eax
  struct GFxGlyphNode *v7; // esi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // ebx
  unsigned int *v12; // ecx
  _DWORD *v13; // eax
  __int16 v14; // dx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  __int16 v17; // cx
  _DWORD *v18; // eax
  unsigned int v20; // [esp+Ch] [ebp-4h]
  unsigned int *v21; // [esp+20h] [ebp+10h]

  if ( *(_DWORD *)a4 != 0 )
  {
    result = nullptr;
    if ( *((_DWORD *)a4 + 4) == 0
      || (result = GFxGlyphSlotQueue::packGlyph(this, a2, a3, a4: *((struct GFxGlyphNode **)a4 + 4))) == nullptr )
    {
      v7 = *((struct GFxGlyphNode **)a4 + 5);
      if ( v7 != nullptr )
        return GFxGlyphSlotQueue::packGlyph(this, a2, a3, a4: v7);
    }
  }
  else
  {
    v8 = *((unsigned __int16 *)a4 + 14);
    if ( a2 > v8 )
      return nullptr;
    v9 = *((unsigned __int16 *)a4 + 15);
    if ( a3 > v9 )
    {
      return nullptr;
    }
    else
    {
      v10 = v9 - a3;
      v11 = v8 - a2;
      v20 = v10;
      if ( v11 >= *(_DWORD *)this || v10 >= *(_DWORD *)this )
      {
        v12 = (unsigned int *)((char *)this + 100);
        v21 = (unsigned int *)((char *)this + 100);
        if ( v11 <= v10 )
        {
          v16 = GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(this: v12, a2: (int)a4);
          v17 = a3 + *((_WORD *)a4 + 13);
          *((_DWORD *)a4 + 4) = v16;
          *((_WORD *)v16 + 13) = v17;
          *(_WORD *)(*((_DWORD *)a4 + 4) + 30) = v20;
          if ( v11 >= *(_DWORD *)this )
          {
            v18 = GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(this: v21, a2: (int)a4);
            *((_DWORD *)a4 + 5) = v18;
            v18[4] = 0;
            *(_WORD *)(*((_DWORD *)a4 + 5) + 24) = a2 + *((_WORD *)a4 + 12);
            *(_WORD *)(*((_DWORD *)a4 + 5) + 28) = v11;
            *(_WORD *)(*((_DWORD *)a4 + 5) + 30) = a3;
          }
        }
        else
        {
          v13 = GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(this: v12, a2: (int)a4);
          v14 = a2 + *((_WORD *)a4 + 12);
          *((_DWORD *)a4 + 4) = v13;
          *((_WORD *)v13 + 12) = v14;
          *(_WORD *)(*((_DWORD *)a4 + 4) + 28) = v11;
          if ( v20 >= *(_DWORD *)this )
          {
            v15 = GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(this: v21, a2: (int)a4);
            *((_DWORD *)a4 + 5) = v15;
            v15[4] = 0;
            *(_WORD *)(*((_DWORD *)a4 + 5) + 26) = a3 + *((_WORD *)a4 + 13);
            *(_WORD *)(*((_DWORD *)a4 + 5) + 30) = v20;
            *(_WORD *)(*((_DWORD *)a4 + 5) + 28) = a2;
          }
        }
      }
      *((_WORD *)a4 + 14) = a2;
      *((_WORD *)a4 + 15) = a3;
      return a4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10181330
// Name: private: struct GFxGlyphNode __near * GFxGlyphSlotQueue::packGlyph(unsigned int,unsigned int,struct GFxGlyphDynaSlot __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphSlotQueue::packGlyph(
        GFxGlyphSlotQueue *this,
        unsigned int a2,
        unsigned int a3,
        struct GFxGlyphDynaSlot *a4)
{
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  int v7; // eax
  int v8; // ecx
  struct GFxGlyphNode *result; // eax
  unsigned int v10; // ecx

  v4 = *((_DWORD *)a4 + 2);
  if ( *(_DWORD *)v4 == 0 )
  {
    v5 = *((unsigned __int16 *)a4 + 18);
    if ( v5 > 2 * a2 )
    {
      if ( *(_DWORD *)(v4 + 16) != 0 )
      {
        if ( *(_DWORD *)(v4 + 20) == 0 && *(_WORD *)(v4 + 30) == *(_WORD *)(*((_DWORD *)a4 + 7) + 4) )
        {
          v6 = *(unsigned __int16 *)(v4 + 28);
          if ( v6 > 2 * a2 )
          {
            v7 = *(unsigned __int16 *)(v4 + 24);
            v8 = *((unsigned __int16 *)a4 + 17);
            if ( ((_WORD)v7 == (unsigned __int16)v8) != (v6 + v7 == v5 + v8) )
              GFxGlyphSlotQueue::splitGlyph(this, a2: a4, a3: (_WORD)v7 == (unsigned __int16)v8, a4: a2);
          }
        }
      }
      else if ( *(_DWORD *)(v4 + 20) == 0 )
      {
        GFxGlyphSlotQueue::splitSlot(this, a2: (struct GFxGlyphBand **)a4, a3: a2);
      }
    }
  }
  result = GFxGlyphSlotQueue::packGlyph(this, a2, a3, a4: *((struct GFxGlyphNode **)a4 + 2));
  if ( result == nullptr )
    ++*((_WORD *)a4 + 19);
  v10 = *((unsigned __int16 *)a4 + 19);
  if ( v10 <= 0x10 )
  {
    if ( (_WORD)v10 != 0 && result != nullptr )
      *((_WORD *)a4 + 19) = v10 - 1;
  }
  else
  {
    *(_DWORD *)(*((_DWORD *)a4 + 5) + 24) = *((_DWORD *)a4 + 6);
    *(_DWORD *)(*((_DWORD *)a4 + 6) + 20) = *((_DWORD *)a4 + 5);
    *((_WORD *)a4 + 16) |= 0x4000u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10181420
// Name: private: struct GFxGlyphNode __near * GFxGlyphSlotQueue::findSpaceInSlots(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphSlotQueue::findSpaceInSlots(
        GFxGlyphSlotQueue **this,
        unsigned int a2,
        unsigned int a3)
{
  GFxGlyphSlotQueue *v3; // edi
  GFxGlyphSlotQueue *v4; // esi
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int v8; // eax
  int v9; // ecx
  struct GFxGlyphNode *result; // eax
  unsigned int v11; // ecx
  GFxGlyphSlotQueue *v12; // [esp+Ch] [ebp-Ch]

  v3 = (GFxGlyphSlotQueue *)this;
  v4 = *(this + 21);
  if ( v4 != (GFxGlyphSlotQueue *)(this + 15) )
  {
    while ( 1 )
    {
      v12 = *((GFxGlyphSlotQueue **)v4 + 6);
      v5 = *((_DWORD *)v4 + 2);
      if ( *(_DWORD *)v5 == 0 )
      {
        v6 = *((unsigned __int16 *)v4 + 18);
        if ( v6 > 2 * a2 )
        {
          if ( *(_DWORD *)(v5 + 16) != 0 )
          {
            if ( *(_DWORD *)(v5 + 20) == 0 )
            {
              if ( *(_WORD *)(v5 + 30) == *(_WORD *)(*((_DWORD *)v4 + 7) + 4) )
              {
                v7 = *(unsigned __int16 *)(v5 + 28);
                if ( v7 > 2 * a2 )
                {
                  v8 = *(unsigned __int16 *)(v5 + 24);
                  v9 = *((unsigned __int16 *)v4 + 17);
                  if ( ((_WORD)v8 == (unsigned __int16)v9) != (v7 + v8 == v6 + v9) )
                    GFxGlyphSlotQueue::splitGlyph(
                      (GFxGlyphSlotQueue *)this,
                      a2: v4,
                      a3: (_WORD)v8 == (unsigned __int16)v9,
                      a4: a2);
                }
              }
              v3 = (GFxGlyphSlotQueue *)this;
            }
          }
          else if ( *(_DWORD *)(v5 + 20) == 0 )
          {
            GFxGlyphSlotQueue::splitSlot(this: v3, a2: (struct GFxGlyphBand **)v4, a3: a2);
          }
        }
      }
      result = GFxGlyphSlotQueue::packGlyph(this: v3, a2, a3, a4: *((struct GFxGlyphNode **)v4 + 2));
      if ( result == nullptr )
        ++*((_WORD *)v4 + 19);
      v11 = *((unsigned __int16 *)v4 + 19);
      if ( v11 > 0x10 )
        break;
      if ( (_WORD)v11 == 0 )
        goto LABEL_20;
      if ( result != nullptr )
      {
        *((_WORD *)v4 + 19) = v11 - 1;
LABEL_20:
        if ( result != nullptr )
          return result;
      }
      v4 = v12;
      if ( v12 == (GFxGlyphSlotQueue *)((char *)v3 + 60) )
        return nullptr;
    }
    *(_DWORD *)(*((_DWORD *)v4 + 5) + 24) = *((_DWORD *)v4 + 6);
    *(_DWORD *)(*((_DWORD *)v4 + 6) + 20) = *((_DWORD *)v4 + 5);
    *((_WORD *)v4 + 16) |= 0x4000u;
    goto LABEL_20;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10181530
// Name: private: struct GFxGlyphNode __near * GFxGlyphSlotQueue::allocateNewSlot(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphSlotQueue::allocateNewSlot(
        GFxGlyphSlotQueue *this,
        unsigned int a2,
        unsigned int a3)
{
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  __int16 v8; // ax
  int v9; // eax
  int v10; // edx
  unsigned int v11; // eax
  int v12; // edi
  __int16 v13; // cx
  struct GFxGlyphDynaSlot *inited; // eax
  int v15; // edx
  int v16; // edx

  v4 = *((_DWORD *)this + 34);
  if ( (v4 == 0 || *(unsigned __int16 *)(*((_DWORD *)this + 30) + 48 * v4 - 42) < a2) && v4 < *((_DWORD *)this + 31) )
  {
    v5 = v4 / *((_DWORD *)this + 6);
    v6 = v4 % *((_DWORD *)this + 6);
    v7 = *((_DWORD *)this + 30) + 48 * v4;
    *(_WORD *)v7 = v5 + *((_WORD *)this + 2);
    v8 = v6 * *((_WORD *)this + 10);
    *(_WORD *)(v7 + 2) = v8;
    if ( v6 + 1 == *((_DWORD *)this + 6) )
      LOWORD(v9) = *((_DWORD *)this + 4) - v8;
    else
      v9 = *((_DWORD *)this + 5);
    *(_WORD *)(v7 + 4) = v9;
    *(_WORD *)(v7 + 6) = *((_WORD *)this + 6);
    *(_DWORD *)(v7 + 20) = v7 + 8;
    *(_DWORD *)(v7 + 24) = v7 + 8;
    ++*((_DWORD *)this + 34);
  }
  v10 = *((_DWORD *)this + 30);
  v11 = *(unsigned __int16 *)(v10 + 48 * *((_DWORD *)this + 34) - 42);
  v12 = v10 + 48 * *((_DWORD *)this + 34) - 48;
  if ( a2 > v11 )
    return nullptr;
  v13 = *(_WORD *)(v10 + 48 * *((_DWORD *)this + 34) - 42);
  if ( v11 - a2 >= a2 )
    v13 = a2;
  inited = GFxGlyphSlotQueue::initNewSlot(
             this,
             a2: (struct GFxGlyphBand *)v12,
             a3: *((_DWORD *)this + 3) - v11,
             a4: v13);
  *(_WORD *)(v12 + 6) -= *((_WORD *)inited + 18);
  *(_DWORD *)inited = *((_DWORD *)this + 12);
  *((_DWORD *)inited + 1) = (char *)this + 48;
  *(_DWORD *)(*((_DWORD *)this + 12) + 4) = inited;
  *((_DWORD *)this + 12) = inited;
  ++*((_DWORD *)this + 14);
  v15 = *(_DWORD *)(v12 + 20);
  *((_DWORD *)inited + 4) = v12 + 8;
  *((_DWORD *)inited + 3) = v15;
  *(_DWORD *)(*(_DWORD *)(v12 + 20) + 16) = inited;
  *(_DWORD *)(v12 + 20) = inited;
  v16 = *((_DWORD *)this + 21);
  *((_DWORD *)inited + 5) = (char *)this + 60;
  *((_DWORD *)inited + 6) = v16;
  *(_DWORD *)(*((_DWORD *)this + 21) + 20) = inited;
  *((_DWORD *)this + 21) = inited;
  return GFxGlyphSlotQueue::packGlyph(this, a2, a3, a4: inited);
}

//------------------------------------------------------------------------------
// Address: 0x10181650
// Name: private: struct GFxGlyphNode __near * GFxGlyphSlotQueue::extrudeOldSlot(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphSlotQueue::extrudeOldSlot(
        GFxGlyphSlotQueue *this,
        unsigned int a2,
        unsigned int a3)
{
  int v3; // esi
  unsigned int v4; // edi
  int v5; // ebx
  struct GFxGlyphDynaSlot *v6; // eax
  GFxGlyphSlotQueue *v7; // edi
  int v9; // ebx
  unsigned int v10; // edx
  GFxGlyphSlotQueue *v11; // esi
  GFxGlyphSlotQueue *v12; // eax
  GFxGlyphSlotQueue *v13; // ecx
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  GFxGlyphSlotQueue *v17; // [esp+Ch] [ebp-8h]
  GFxGlyphSlotQueue *v18; // [esp+10h] [ebp-4h]

  v3 = *((_DWORD *)this + 13);
  v4 = *((_DWORD *)this + 14) >> 1;
  v18 = this;
  v5 = 0;
  while ( (GFxGlyphSlotQueue *)v3 != (GFxGlyphSlotQueue *)((char *)this + 48) )
  {
    if ( *(__int16 *)(v3 + 32) >= 0 )
    {
      if ( *(unsigned __int16 *)(v3 + 36) >= a2 )
      {
        GFxGlyphSlotQueue::releaseSlot((struct GFxGlyphNode **)this, a2: (struct GFxGlyphDynaSlot *)v3);
        return GFxGlyphSlotQueue::packGlyph(this: v18, a2, a3, a4: (struct GFxGlyphDynaSlot *)v3);
      }
      v6 = GFxGlyphSlotQueue::mergeSlotWithNeighbor((struct GFxGlyphNode **)this, a2: (struct GFxGlyphDynaSlot *)v3);
      if ( v6 != nullptr )
      {
        if ( *(unsigned __int16 *)(*((_DWORD *)v6 + 2) + 28) >= a2 )
          return GFxGlyphSlotQueue::packGlyph(this: v18, a2, a3, a4: v6);
        break;
      }
    }
    v3 = *(_DWORD *)(v3 + 4);
    if ( ++v5 > v4 )
      break;
    this = v18;
  }
  v7 = *((GFxGlyphSlotQueue **)v18 + 13);
  v17 = v7;
  if ( v7 == (GFxGlyphSlotQueue *)((char *)v18 + 48) )
    return nullptr;
  while ( 1 )
  {
    if ( *((__int16 *)v7 + 16) >= 0 )
    {
      v9 = *((_DWORD *)v7 + 7);
      v10 = 0;
      v11 = v7;
      if ( v7 != (GFxGlyphSlotQueue *)(v9 + 8) )
      {
        while ( *((__int16 *)v11 + 16) >= 0 )
        {
          if ( v11 != v7 )
          {
            v12 = v11;
            v13 = v11;
            if ( v11 != (GFxGlyphSlotQueue *)((char *)v18 + 48) )
            {
              while ( v13 != (GFxGlyphSlotQueue *)((char *)v18 + 48) )
              {
                v12 = *(GFxGlyphSlotQueue **)v12;
                v13 = *((GFxGlyphSlotQueue **)v13 + 1);
                if ( v12 == (GFxGlyphSlotQueue *)((char *)v18 + 48) )
                  goto LABEL_22;
              }
              v7 = v17;
              break;
            }
LABEL_22:
            v7 = v17;
          }
          v14 = *((unsigned __int16 *)v11 + 18);
          if ( v14 >= a2 )
          {
            GFxGlyphSlotQueue::releaseSlot(this: (struct GFxGlyphNode **)v18, a2: v11);
            return GFxGlyphSlotQueue::packGlyph(this: v18, a2, a3, a4: v11);
          }
          v10 += v14;
          v15 = *(unsigned __int16 *)(v9 + 6);
          if ( (_WORD)v15 != 0 && v11 == *(GFxGlyphSlotQueue **)(v9 + 20) )
          {
            v16 = v10 + v15;
            if ( v16 >= a2 )
            {
              v10 = v16;
              *(_WORD *)(v9 + 6) = 0;
            }
          }
          if ( v10 >= a2 )
          {
            GFxGlyphSlotQueue::mergeSlots(this: (struct GFxGlyphNode **)v18, a2: v7, a3: v11, a4: v10);
            return GFxGlyphSlotQueue::packGlyph(this: v18, a2, a3, a4: v7);
          }
          v11 = *((GFxGlyphSlotQueue **)v11 + 4);
          if ( v11 == (GFxGlyphSlotQueue *)(v9 + 8) )
            break;
        }
      }
    }
    v17 = *((GFxGlyphSlotQueue **)v7 + 1);
    if ( v17 == (GFxGlyphSlotQueue *)((char *)v18 + 48) )
      return nullptr;
    v7 = *((GFxGlyphSlotQueue **)v7 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101817F0
// Name: public: GFxGlyphRasterCache::GFxGlyphRasterCache(void)
// Source: json
//------------------------------------------------------------------------------
GFxGlyphRasterCache *__thiscall GFxGlyphRasterCache::GFxGlyphRasterCache(GFxGlyphRasterCache *this)
{
  int v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int i; // ecx

  *((float *)this + 5) = 0.0;
  *(_DWORD *)this = 0;
  *((float *)this + 6) = 0.0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  v2 = 31;
  v3 = (_DWORD *)((char *)this + 68);
  do
  {
    *(v3 - 2) = &GFxGlyphRasterCache::TextureEventHandler::`vftable';
    *(v3 - 1) = 0;
    *v3 = -1;
    v3 += 5;
    --v2;
  }
  while ( v2 >= 0 );
  *((_DWORD *)this + 174) = 0;
  *((_DWORD *)this + 175) = 0;
  *((_DWORD *)this + 176) = 0;
  *((_DWORD *)this + 177) = 0;
  *((_DWORD *)this + 178) = 0;
  *((_DWORD *)this + 179) = 0;
  *((_DWORD *)this + 180) = 0;
  *((_DWORD *)this + 181) = 0;
  *((_DWORD *)this + 182) = 0;
  *((_DWORD *)this + 183) = 0;
  *((_DWORD *)this + 184) = 0;
  *((_DWORD *)this + 185) = 0;
  *((_DWORD *)this + 186) = 0;
  *((float *)this + 187) = 1.0;
  *((float *)this + 188) = 0.0625;
  *((_DWORD *)this + 189) = 0;
  *((_DWORD *)this + 190) = 0;
  *((_DWORD *)this + 191) = 0;
  *((_DWORD *)this + 192) = 0;
  *((_DWORD *)this + 193) = 0;
  *((_DWORD *)this + 194) = 0;
  *((_DWORD *)this + 195) = 0;
  *((_DWORD *)this + 196) = 0;
  *((float *)this + 200) = 1.0;
  *((float *)this + 201) = 1.0;
  *((_DWORD *)this + 197) = 0;
  *((_DWORD *)this + 198) = 0x7FFFFFFF;
  *((float *)this + 202) = 0.0;
  *((_DWORD *)this + 199) = -2147483647;
  *((float *)this + 203) = 0.0;
  *((_BYTE *)this + 816) = 0;
  GRasterizer::GRasterizer(this: (GFxGlyphRasterCache *)((char *)this + 820));
  GFxGlyphScanlineFilter::GFxGlyphScanlineFilter(
    this: (GFxGlyphRasterCache *)((char *)this + 928),
    a2: 0.5,
    a3: 0.22222222,
    a4: 0.052631579);
  *((_DWORD *)this + 424) = 1024;
  *((_DWORD *)this + 425) = 0;
  *((_DWORD *)this + 426) = 0;
  *((_DWORD *)this + 427) = 0;
  *((_DWORD *)this + 428) = 0;
  *((_DWORD *)this + 429) = 0;
  *((_DWORD *)this + 430) = 0;
  *((_DWORD *)this + 431) = 0;
  *((_DWORD *)this + 432) = 0;
  *((_DWORD *)this + 433) = 0;
  *((_DWORD *)this + 434) = 0;
  *((_DWORD *)this + 435) = 0;
  *((_DWORD *)this + 436) = 0;
  *((_DWORD *)this + 437) = 0;
  *((_DWORD *)this + 438) = 0;
  *((_DWORD *)this + 439) = 0;
  *((_DWORD *)this + 440) = 0;
  *((_DWORD *)this + 441) = 0;
  *((_DWORD *)this + 442) = 0;
  *((_DWORD *)this + 443) = 0;
  *((_DWORD *)this + 444) = 0;
  *((_DWORD *)this + 445) = 0;
  GFxGlyphSlotQueue::GFxGlyphSlotQueue(this: (GFxGlyphRasterCache *)((char *)this + 1808));
  v4 = (_DWORD *)((char *)this + 72);
  for ( i = 32; i != 0; --i )
  {
    *(v4 - 4) = 0;
    *v4 = 0;
    v4 += 5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10181A50
// Name: public: struct GFxGlyphNode __near * GFxGlyphSlotQueue::AllocateGlyph(struct GFxGlyphParam const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphSlotQueue::AllocateGlyph(
        GFxGlyphSlotQueue *this,
        const struct GFxGlyphParam *a2,
        unsigned int a3,
        struct GFxGlyphNode *a4)
{
  unsigned int v4; // edi
  struct GFxGlyphNode *result; // eax
  _DWORD *v7; // eax
  int v8; // edx

  v4 = (unsigned int)a4;
  if ( (unsigned int)a4 > *((_DWORD *)this + 5) || a3 == 0 || a4 == nullptr )
    return nullptr;
  if ( (unsigned int)a4 < *(_DWORD *)this )
    *(_DWORD *)this = a4;
  if ( a3 < *(_DWORD *)this )
    *(_DWORD *)this = a3;
  result = GFxGlyphSlotQueue::findSpaceInSlots((GFxGlyphSlotQueue **)this, a2: a3, a3: v4);
  a4 = result;
  if ( result != nullptr
    || (result = GFxGlyphSlotQueue::allocateNewSlot(this, a2: a3, a3: v4), a4 = result, result != nullptr)
    || (result = GFxGlyphSlotQueue::extrudeOldSlot(this, a2: a3, a3: v4), a4 = result, result != nullptr) )
  {
    *(_DWORD *)result = *(_DWORD *)a2;
    *((_DWORD *)a4 + 1) = *((_DWORD *)a2 + 1);
    *((_DWORD *)a4 + 2) = *((_DWORD *)a2 + 2);
    *((_WORD *)a4 + 16) = 0;
    *((_WORD *)a4 + 17) = 0;
    v7 = *((_DWORD **)a4 + 3);
    *(_DWORD *)(*v7 + 4) = v7[1];
    *(_DWORD *)v7[1] = *v7;
    v8 = *((_DWORD *)this + 12);
    v7[1] = (char *)this + 48;
    *v7 = v8;
    *(_DWORD *)(*((_DWORD *)this + 12) + 4) = v7;
    *((_DWORD *)this + 12) = v7;
    if ( GHash<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam,GAllocatorLH<GFxGlyphParam,195>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>,GHashSet<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>>::Get(
           this: (int *)this + 33,
           (int)a2) == 0 )
      GHash<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam,GAllocatorLH<GFxGlyphParam,195>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>,GHashSet<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>>::Add(
        this: (int *)this + 33,
        (int)a2,
        a3: (int *)&a4);
    return a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10181B40
// Name: private: struct GFxGlyphNode __near * GFxGlyphRasterCache::rasterizeAndPack(class GRenderer __near *,struct GFxGlyphParam const __near &,bool,class GFxShapeBase const __near *,unsigned int,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphRasterCache::rasterizeAndPack(
        GFxGlyphRasterCache *this,
        struct GRenderer *a2,
        unsigned int a3,
        signed int a4,
        unsigned int a5,
        float a6,
        ISequentialStream *count)
{
  unsigned int v7; // ebx
  int v8; // eax
  unsigned __int8 v11; // cl
  unsigned int v12; // esi
  unsigned __int8 v13; // al
  bool v14; // zf
  char v15; // al
  unsigned __int16 UpperCaseTop; // ax
  const struct GCompoundShape *v17; // ebx
  void (__stdcall *v18)(char *, unsigned int); // eax
  unsigned int v19; // eax
  double v20; // st7
  double v21; // st7
  int v22; // ecx
  bool v23; // cc
  ISequentialStream *v24; // eax
  ISequentialStream_vtbl *v25; // esi
  unsigned int v26; // esi
  unsigned int v27; // ecx
  double v28; // st7
  double v29; // st7
  int v30; // edx
  int v31; // esi
  __int16 v32; // cx
  int v33; // eax
  __int16 v34; // ax
  __int16 v35; // cx
  int v36; // edx
  volatile unsigned int j; // esi
  __int16 v38; // cx
  int v39; // eax
  __int16 v40; // cx
  int v41; // edx
  double v42; // st7
  int v43; // eax
  int v44; // esi
  int v45; // ebx
  float v46; // edx
  int v47; // ebx
  int v48; // ecx
  int v49; // eax
  struct GFxGlyphNode *v50; // ecx
  struct GFxLog *v51; // edx
  struct GImage *v52; // esi
  struct GFxGlyphNode *v53; // eax
  int v54; // eax
  GTexture *v55; // eax
  float v56; // ecx
  float v57; // edx
  int v58; // eax
  unsigned int v59; // ecx
  float v60; // eax
  __int16 v61; // cx
  __int16 v62; // dx
  unsigned int v63; // ebx
  char *v64; // eax
  unsigned __int8 v65; // dl
  unsigned __int8 v66; // cl
  int v67; // eax
  int v68; // eax
  int v69; // ecx
  _DWORD *v70; // esi
  unsigned int v71; // eax
  unsigned int v72; // ecx
  void *v73; // eax
  void *v74; // eax
  void *v75; // eax
  float *v76; // eax
  float v77; // edx
  float v78; // ecx
  ISequentialStream *v79; // edx
  struct GFxGlyphNode *v80; // ecx
  float v81; // [esp+20h] [ebp-64h]
  float v82; // [esp+24h] [ebp-60h]
  float v83; // [esp+28h] [ebp-5Ch]
  float v84; // [esp+2Ch] [ebp-58h]
  float v85; // [esp+30h] [ebp-54h]
  float v86; // [esp+30h] [ebp-54h]
  int v87; // [esp+40h] [ebp-44h]
  int v88; // [esp+44h] [ebp-40h]
  int v89; // [esp+48h] [ebp-3Ch] BYREF
  unsigned int v90; // [esp+4Ch] [ebp-38h]
  float v91; // [esp+50h] [ebp-34h]
  ISequentialStream *v92; // [esp+54h] [ebp-30h]
  struct GFxGlyphNode *v93; // [esp+58h] [ebp-2Ch]
  unsigned int v94; // [esp+5Ch] [ebp-28h]
  unsigned int v95[2]; // [esp+60h] [ebp-24h] BYREF
  float v96; // [esp+68h] [ebp-1Ch]
  unsigned int v97; // [esp+6Ch] [ebp-18h]
  unsigned int v98; // [esp+70h] [ebp-14h]
  volatile unsigned int i; // [esp+74h] [ebp-10h]
  int LowerCaseTop; // [esp+78h] [ebp-Ch]
  float *v101; // [esp+7Ch] [ebp-8h]
  struct GFxGlyphNode *v102; // [esp+80h] [ebp-4h]

  v7 = a3;
  v8 = 0;
  v101 = nullptr;
  if ( (_BYTE)a4 != 0 )
  {
    v8 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)a3 + 12) + 28))(
           a1: *(_DWORD *)(*(_DWORD *)a3 + 12),
           a2: *(unsigned __int16 *)(a3 + 4),
           a3: *(unsigned __int8 *)(a3 + 6));
    v101 = (float *)v8;
  }
  if ( *(float *)&a5 == 0.0 && v8 == 0 )
    return nullptr;
  v11 = *(_BYTE *)(v7 + 8);
  a4 = v11;
  v12 = (*(_BYTE *)(v7 + 7) & 4 | 2u) >> 1;
  v94 = v12;
  *(float *)&a4 = (double)v11 * 0.0625;
  v95[1] = HIWORD(a4) | 0xC00;
  v13 = *(_BYTE *)(v7 + 9);
  v97 = (__int64)(*(float *)&a4 + 0.5);
  HIBYTE(a4) = v13;
  *(float *)&v95[1] = 0.0625 * (double)v13;
  *(_QWORD *)v95 = (__int64)(*(float *)&v95[1] + 0.5);
  v98 = v95[0];
  if ( v97 == 0 )
    v97 = v11 != 0;
  if ( v95[0] == 0 && HIBYTE(a4) != 0 )
    v98 = 1;
  GRasterizer::Clear(this: (GFxGlyphRasterCache *)((char *)this + 820));
  if ( v101 != nullptr )
    goto LABEL_55;
  if ( *(_BYTE *)(a5 + 37) != 0 )
  {
    v17 = (GFxGlyphRasterCache *)((char *)this + 748);
    (*(void (__stdcall **)(char *, _DWORD))(*(_DWORD *)a5 + 24))(a1: (char *)this + 748, a2: 10.0);
    *(float *)&a4 = (double)LODWORD(a6) / (double)(320 * *(unsigned __int8 *)(a5 + 37));
    v84 = 0.0;
    v83 = 0.0;
    v82 = *(float *)&a4;
    *(float *)&a4 = *(float *)&a4 * (double)v12;
    v42 = *(float *)&a4;
    goto LABEL_54;
  }
  v14 = (*(_BYTE *)(v7 + 11) & 0x1E) == 0;
  LowerCaseTop = 0;
  v96 = 0.0;
  HIBYTE(a4) = 0;
  if ( v14 )
  {
    v15 = *(_BYTE *)(v7 + 7);
    if ( (v15 & 1) != 0
      && (v15 & 2) != 0
      && LODWORD(a6) > 0x60
      && ((*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v7 + 12) + 20) & 0x2000) != 0
       || (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v7 + 12) + 20) & 0x10) != 0) )
    {
      LowerCaseTop = (unsigned __int16)GFxFontResource::GetLowerCaseTop(this: *(GFxFontResource **)v7, log: count);
      UpperCaseTop = GFxFontResource::GetUpperCaseTop(this: *(GFxFontResource **)v7, log: count);
      LODWORD(v96) = UpperCaseTop;
      if ( LowerCaseTop != 0 && UpperCaseTop != 0 )
        HIBYTE(a4) = 1;
    }
  }
  v17 = (GFxGlyphRasterCache *)((char *)this + 748);
  v18 = *(void (__stdcall **)(char *, unsigned int))(*(_DWORD *)a5 + 24);
  *(float *)&a5 = 1536.0 / (double)*((unsigned int *)this + 3) * 0.5;
  v18(a1: (char *)this + 748, a2: a5);
  if ( HIBYTE(a4) == 0 )
  {
    v84 = 0.0;
    v83 = 0.0;
    *(float *)&a4 = (double)LODWORD(a6) * 0.00006103515625;
    v82 = *(float *)&a4;
    *(float *)&a4 = 0.00006103515625 * (double)(LODWORD(a6) * v12);
    v42 = *(float *)&a4;
LABEL_54:
    v81 = v42;
    GRasterizer::AddShapeScaled(
      this: (GFxGlyphRasterCache *)((char *)this + 820),
      a2: v17,
      a3: v81,
      a4: v82,
      a5: v83,
      a6: v84,
      a7: -1);
    goto LABEL_55;
  }
  GFxGlyphFitter::Clear(this: (GFxGlyphRasterCache *)((char *)this + 1696));
  v19 = 4 * LODWORD(a6);
  a4 = 4 * LODWORD(a6);
  if ( 4 * LODWORD(a6) > 2048 )
  {
    v19 = 2048;
    a4 = 2048;
  }
  v14 = *((_DWORD *)this + 193) == 0;
  v20 = (double)a4;
  *((_DWORD *)this + 424) = v19;
  *(float *)&a5 = 0.0;
  *(float *)&a4 = v20 * 0.0009765625;
  v21 = *(float *)&a4;
  if ( !v14 )
  {
    do
    {
      v22 = *(_DWORD *)(*((_DWORD *)this + 196) + 4 * (a5 >> 6));
      v23 = *(_DWORD *)(v22 + 24 * (a5 & 0x3F) + 4) <= 2u;
      v24 = (ISequentialStream *)(v22 + 24 * (a5 & 0x3F));
      count = v24;
      if ( !v23 )
      {
        v25 = v24[2].__vftable;
        v95[1] = (unsigned int)v24->__vftable[1].QueryInterface;
        GFxGlyphFitter::MoveTo(
          this: (GFxGlyphRasterCache *)((char *)this + 1696),
          a2: (__int16)(int)(v21 * *(float *)(*(_DWORD *)(v95[1] + 4 * ((unsigned int)v25 >> 8)) + 8 * (unsigned __int8)v25)),
          a3: -(__int16)(int)(*(float *)(*(_DWORD *)(v95[1] + 4 * ((unsigned int)v25 >> 8)) + 8 * (unsigned __int8)v25 + 4)
                        * v21));
        for ( i = 1; (ISequentialStream_vtbl *)i < count[1].__vftable; ++i )
        {
          v26 = (unsigned int)count[2].__vftable + i;
          v95[1] = (unsigned int)count->__vftable[1].QueryInterface;
          GFxGlyphFitter::LineTo(
            this: (GFxGlyphRasterCache *)((char *)this + 1696),
            a2: (__int16)(int)(*(float *)&a4 * *(float *)(*(_DWORD *)(v95[1] + 4 * (v26 >> 8)) + 8 * (unsigned __int8)v26)),
            a3: -(__int16)(int)(*(float *)(*(_DWORD *)(v95[1] + 4 * (v26 >> 8)) + 8 * (unsigned __int8)v26 + 4)
                          * *(float *)&a4));
        }
        v21 = *(float *)&a4;
      }
      ++a5;
    }
    while ( a5 < *((_DWORD *)this + 193) );
  }
  GFxGlyphFitter::FitGlyph(
    this: (GFxGlyphRasterCache *)((char *)this + 1696),
    a2: LODWORD(a6) >> 4,
    a3: 0,
    a4: (int)(v21 * (double)LowerCaseTop),
    a5: (int)((double)SLODWORD(v96) * v21));
  *(float *)&v27 = 0.0;
  v28 = 1.0 / (double)*((int *)this + 450);
  *(float *)&a5 = 0.0;
  *(float *)&a4 = v28;
  if ( *((_DWORD *)this + 425) != 0 )
  {
    v29 = *(float *)&a4;
    do
    {
      v30 = *(_DWORD *)(*((_DWORD *)this + 428) + 4 * (v27 >> 4));
      v31 = v27 & 0xF;
      v23 = *(_DWORD *)(v30 + 8 * v31 + 4) <= 2u;
      count = (ISequentialStream *)(v30 + 8 * v31);
      if ( !v23 )
      {
        v32 = *((_WORD *)this + 893);
        a6 = *(float *)(*(_DWORD *)(*((_DWORD *)this + 432) + 4 * (*(_DWORD *)(v30 + 8 * v31) >> 6))
                      + 4 * (*(_DWORD *)(v30 + 8 * v31) & 0x3F));
        v33 = SHIWORD(a6) - v32;
        if ( v33 < 0 || v33 >= *((_DWORD *)this + 444) )
          v34 = HIWORD(a6);
        else
          v34 = v32 + *(_WORD *)(*((_DWORD *)this + 443) + 2 * v33);
        v35 = LOWORD(a6);
        v36 = SLOWORD(a6) - *((__int16 *)this + 892);
        if ( v36 >= 0 && v36 < *((_DWORD *)this + 441) )
          v35 = *((_WORD *)this + 892) + *(_WORD *)(*((_DWORD *)this + 440) + 2 * v36);
        v96 = (float)v94;
        a6 = (double)-v34 * v29;
        v85 = a6;
        a6 = v29 * (double)v35 * v96;
        GRasterizer::MoveTo(this: (GFxGlyphRasterCache *)((char *)this + 820), a2: a6, a3: v85);
        for ( j = 1; (ISequentialStream_vtbl *)j < count[1].__vftable; ++j )
        {
          v38 = *((_WORD *)this + 893);
          a6 = *(float *)(*(_DWORD *)(*((_DWORD *)this + 432) + 4 * (((unsigned int)count->__vftable + j) >> 6))
                        + 4 * (((int)count->__vftable + j) & 0x3F));
          v39 = SHIWORD(a6) - v38;
          if ( v39 >= 0 && v39 < *((_DWORD *)this + 444) )
            HIWORD(a6) = v38 + *(_WORD *)(*((_DWORD *)this + 443) + 2 * v39);
          v40 = LOWORD(a6);
          v41 = SLOWORD(a6) - *((__int16 *)this + 892);
          if ( v41 >= 0 && v41 < *((_DWORD *)this + 441) )
            v40 = *((_WORD *)this + 892) + *(_WORD *)(*((_DWORD *)this + 440) + 2 * v41);
          a6 = (double)-SHIWORD(a6) * *(float *)&a4;
          v86 = a6;
          a6 = *(float *)&a4 * (double)v40 * v96;
          GRasterizer::LineTo(this: (GFxGlyphRasterCache *)((char *)this + 820), a2: a6, a3: v86);
        }
        GRasterizer::ClosePolygon(this: (GFxGlyphRasterCache *)((char *)this + 820));
        v29 = *(float *)&a4;
        v27 = a5;
      }
      a5 = ++v27;
    }
    while ( v27 < *((_DWORD *)this + 425) );
  }
LABEL_55:
  v43 = *((_DWORD *)this + 4);
  v44 = v43 + v97;
  a5 = -(v43 + v98);
  v45 = -(v43 + v97);
  i = v43 + v97;
  LowerCaseTop = v43 + v98;
  LODWORD(a6) = v43 + v98;
  HIBYTE(a4) = 0;
  if ( v101 != nullptr )
  {
    v46 = v101[8];
    v47 = v44 + *((_DWORD *)v101 + 7);
    a5 = -(LODWORD(v46) + v43 + v98);
    v48 = *((_DWORD *)v101 + 5) - *((_DWORD *)v101 + 7);
    a6 = v46;
    v45 = -v47;
    v44 = v48 + v44 - 1;
    v49 = *((_DWORD *)v101 + 6) - LODWORD(v46) + LowerCaseTop - 1;
  }
  else
  {
    if ( GRasterizer::SortCells(this: (GFxGlyphRasterCache *)((char *)this + 820)) )
    {
      v45 = *((_DWORD *)this + 224) - i;
      v44 = i + *((_DWORD *)this + 226);
      a5 = *((_DWORD *)this + 225) - LowerCaseTop;
      LODWORD(a6) = LowerCaseTop + *((_DWORD *)this + 227);
      HIBYTE(a4) = 1;
    }
    v49 = LODWORD(a6);
  }
  v50 = *((struct GFxGlyphNode **)this + 3);
  v51 = (struct GFxLog *)(v44 - v45 + 1);
  v52 = *((struct GImage **)this + 174);
  count = (ISequentialStream *)v51;
  v102 = (struct GFxGlyphNode *)(v49 - a5 + 1);
  if ( v102 > v50 )
    v102 = v50;
  if ( (unsigned int)v51 > v52->Width )
    count = (ISequentialStream *)v52->Width;
  *(float *)&v53 = COERCE_FLOAT(
                     GFxGlyphSlotQueue::AllocateGlyph(
                       this: (GFxGlyphRasterCache *)((char *)this + 1808),
                       a2: (const struct GFxGlyphParam *)a3,
                       a3: (unsigned int)count,
                       a4: v102));
  v96 = *(float *)&v53;
  if ( *(float *)&v53 == 0.0 )
    return nullptr;
  v54 = *(_WORD *)(*((_DWORD *)v53 + 3) + 32) & 0x3FFF;
  v14 = *((_DWORD *)this + 5 * v54 + 14) == 0;
  v95[1] = v54;
  LODWORD(a6) = (char *)this + 20 * v54 + 56;
  if ( v14 )
  {
    v55 = a2->CreateTexture(this: a2);
    v56 = a6;
    *(_DWORD *)LODWORD(a6) = v55;
    if ( v55 == nullptr )
      return nullptr;
    v57 = v56;
    v58 = LODWORD(v56) + 4;
    v59 = v95[1] & 0xFFFF7FFF;
    *(_DWORD *)(LODWORD(v57) + 8) = this;
    *(_DWORD *)(LODWORD(v57) + 12) = v59;
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)LODWORD(v57) + 40))(a1: *(_DWORD *)LODWORD(v57), a2: v58);
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, int))(**(_DWORD **)LODWORD(a6) + 8))(
           a1: *(_DWORD *)LODWORD(a6),
           a2: *(_DWORD *)this,
           a3: *((_DWORD *)this + 1),
           a4: 9,
           a5: 0,
           a6: 16) == 0 )
      return nullptr;
  }
  if ( GFxTextureUpdatePacker::Allocate(
         this: (GFxGlyphRasterCache *)((char *)this + 700),
         a2: (unsigned int)count,
         a3: (unsigned int)v102,
         a4: &v95[1],
         a5: (unsigned int *)&a6) == 0 )
  {
    GFxGlyphRasterCache::UpdateTextures(this, a2);
    if ( GFxTextureUpdatePacker::Allocate(
           this: (GFxGlyphRasterCache *)((char *)this + 700),
           a2: (unsigned int)count,
           a3: (unsigned int)v102,
           a4: &v95[1],
           a5: (unsigned int *)&a6) == 0 )
      return nullptr;
  }
  v60 = v96;
  v61 = *(_WORD *)(LODWORD(v96) + 26) - a5;
  v62 = *(_WORD *)(LODWORD(v96) + 24) - v45;
  v14 = v102 == nullptr;
  v63 = v95[1];
  *(_WORD *)(LODWORD(v96) + 32) = v62;
  *(_WORD *)(LODWORD(v60) + 34) = v61;
  *(float *)&a5 = 0.0;
  if ( !v14 )
  {
    do
    {
      memset(dst: &v52->pData[v52->Pitch * (a5 + LODWORD(a6)) + v63], value: 0, (unsigned int)count);
      ++a5;
    }
    while ( a5 < (unsigned int)v102 );
  }
  if ( v101 != nullptr )
  {
    v14 = *((_DWORD *)v101 + 6) == 0;
    *(float *)&a5 = 0.0;
    if ( !v14 )
    {
      a4 = LowerCaseTop + LODWORD(a6);
      do
      {
        memcpy(
          dst: &v52->pData[v52->Pitch * (a5 + a4) + v63 + i],
          src: (unsigned __int8 *)(*((_DWORD *)v101 + 2) + a5 * *((_DWORD *)v101 + 5)),
          count: *((_DWORD *)v101 + 5));
        ++a5;
      }
      while ( a5 < *((_DWORD *)v101 + 6) );
    }
  }
  else if ( HIBYTE(a4) != 0 )
  {
    v14 = *(_BYTE *)(a3 + 8) == 0;
    *(float *)&a4 = 1.0;
    if ( !v14 || *(_BYTE *)(a3 + 9) != 0 )
      *(float *)&a4 = 0.40000001;
    if ( *((float *)this + 206) != *(float *)&a4 )
      GRasterizer::SetGamma(this: (GFxGlyphRasterCache *)((char *)this + 820), a2: *(float *)&a4);
    if ( (unsigned int)count < 5 || v94 < 3 )
    {
      v14 = *((_DWORD *)this + 218) == 0;
      *(float *)&a5 = 0.0;
      if ( !v14 )
      {
        a4 = LowerCaseTop + LODWORD(a6);
        do
        {
          GRasterizer::SweepScanline(
            this: (GFxGlyphRasterCache *)((char *)this + 820),
            a2: a5,
            a3: &v52->pData[v52->Pitch * (a5 + a4) + v63 + i],
            a4: 1u);
          ++a5;
        }
        while ( a5 < *((_DWORD *)this + 218) );
      }
    }
    else
    {
      v14 = *((_DWORD *)this + 218) == 0;
      *(float *)&a5 = 0.0;
      if ( !v14 )
      {
        a4 = LowerCaseTop + LODWORD(a6);
        do
        {
          memset(dst: &v52->pData[LODWORD(a6) * v52->Pitch + v63], value: 0, (unsigned int)count);
          GRasterizer::SweepScanline(
            this: (GFxGlyphRasterCache *)((char *)this + 820),
            a2: a5,
            a3: &v52->pData[LODWORD(a6) * v52->Pitch + v63 + i],
            a4: 1u);
          GFxGlyphRasterCache::filterScanline(
            this,
            a2: &v52->pData[LODWORD(a6) * v52->Pitch + v63],
            a3: &v52->pData[v52->Pitch * (a4 + a5++) + v63],
            a4: (unsigned int)count);
        }
        while ( a5 < *((_DWORD *)this + 218) );
      }
      memset(dst: &v52->pData[LODWORD(a6) * v52->Pitch + v63], value: 0, (unsigned int)count);
    }
    v64 = (char *)a3;
    v14 = (*(_BYTE *)(a3 + 7) & 0x20) == 0;
    *(float *)&a4 = 0.0;
    if ( !v14 )
    {
      GFxGlyphRasterCache::makeKnockOutCopy(
        this,
        a2: v52,
        a3: v63,
        a4: LODWORD(a6),
        (unsigned int)count,
        a6: (unsigned int)v102);
      v64 = (char *)a3;
    }
    v65 = v64[8];
    if ( v65 != 0 || v64[9] != 0 )
    {
      if ( v64[7] >= 0 )
      {
        GFxGlyphRasterCache::stackBlur(
          (void **)this,
          a2: v52,
          a3: v63,
          a4: LODWORD(a6),
          a5: (unsigned int)count,
          a6: (unsigned int)v102,
          k: v97,
          a8: v98);
        a4 = 2;
      }
      else
      {
        a4 = *(unsigned __int8 *)(a3 + 9);
        v91 = a6;
        v93 = v102;
        v92 = count;
        *(float *)&a5 = (double)a4 * 0.0625;
        v89 = (int)v52;
        v90 = v63;
        *(float *)&a4 = 0.0625 * (double)v65;
        GFx_RecursiveBlur<GFxImgBlurWrapperX,GArrayUnsafeLH_POD<float,195>,GArrayUnsafeLH_POD<unsigned char,195>>(
          a1: &v89,
          a2: *(float *)&a4,
          a3: (int)this + 736,
          a4: (_DWORD *)this + 181);
        v91 = a6;
        v89 = (int)v52;
        v90 = v63;
        v92 = count;
        v93 = v102;
        GFx_RecursiveBlur<GFxImgBlurWrapperY,GArrayUnsafeLH_POD<float,195>,GArrayUnsafeLH_POD<unsigned char,195>>(
          a1: (int)&v89,
          a2: *(float *)&a5,
          a3: (int)this + 736,
          a4: (float *)this + 181);
        a4 = 8;
      }
      v64 = (char *)a3;
    }
    v66 = v64[10];
    if ( v66 != 16 )
    {
      *(float *)&a5 = (double)v66 * 0.0625;
      if ( *(float *)&a5 > 1.0 )
        v67 = a4;
      else
        v67 = 0;
      GFxGlyphRasterCache::strengthenImage(
        this,
        a2: v52,
        a3: v63,
        a4: LODWORD(a6),
        a5: (unsigned int)count,
        a6: (unsigned int)v102,
        a7: *(float *)&a5,
        a8: v67);
      v64 = (char *)a3;
    }
    if ( (v64[7] & 0x20) != 0 )
      GFxGlyphRasterCache::knockOut(
        this,
        a2: v52,
        a3: v63,
        a4: LODWORD(a6),
        a5: (unsigned int)count,
        a6: (unsigned int)v102);
  }
  v93 = (struct GFxGlyphNode *)(*(_WORD *)(*(_DWORD *)(LODWORD(v96) + 12) + 32) & 0x3FFF);
  v68 = *(unsigned __int16 *)(LODWORD(v96) + 24);
  v69 = *(unsigned __int16 *)(LODWORD(v96) + 26);
  v70 = (_DWORD *)((char *)this + 28);
  LODWORD(v91) = (char *)count + v63;
  v87 = v68;
  v71 = *((_DWORD *)this + 7) >> 6;
  v92 = (ISequentialStream *)((char *)v102 + LODWORD(a6));
  v88 = v69;
  a4 = v71;
  if ( v71 >= *((_DWORD *)this + 8) )
  {
    v72 = *((_DWORD *)this + 9);
    if ( v71 >= v72 )
    {
      v73 = *((void **)this + 10);
      if ( v73 != nullptr )
      {
        a3 = 4 * v72 + 64;
        v74 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v73, a3);
      }
      else
      {
        a3 = 195;
        v74 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: (char *)this + 28, a3: 64, a4: &a3);
      }
      *((_DWORD *)this + 9) += 16;
      *((_DWORD *)this + 10) = v74;
    }
    a5 = 195;
    v75 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: (char *)this + 28, a3: 1792, a4: &a5);
    *(_DWORD *)(*((_DWORD *)this + 10) + 4 * a4) = v75;
    ++*((_DWORD *)this + 8);
  }
  v76 = (float *)(*(_DWORD *)(*((_DWORD *)this + 10) + 4 * a4) + 28 * (*v70 & 0x3F));
  *(_DWORD *)v76 = v87;
  v77 = a6;
  *((_DWORD *)v76 + 1) = v88;
  v78 = v91;
  v76[3] = v77;
  v79 = v92;
  v76[4] = v78;
  v80 = v93;
  *((_DWORD *)v76 + 2) = v63;
  *((_DWORD *)v76 + 5) = v79;
  *((_DWORD *)v76 + 6) = v80;
  ++*v70;
  ++*((_DWORD *)this + 5 * (_DWORD)v80 + 18);
  return (struct GFxGlyphNode *)LODWORD(v96);
}

//------------------------------------------------------------------------------
// Address: 0x101827C0
// Name: public: struct GFxGlyphNode __near * GFxGlyphRasterCache::GetGlyph(class GRenderer __near *,struct GFxGlyphParam const __near &,bool,class GFxShapeBase const __near *,unsigned int,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxGlyphNode *__thiscall GFxGlyphRasterCache::GetGlyph(
        GFxGlyphRasterCache *this,
        struct GRenderer *a2,
        const struct GFxGlyphParam *a3,
        signed int a4,
        const struct GFxShapeBase *a5,
        float a6,
        ISequentialStream *count)
{
  int Index; // eax
  int v9; // eax
  struct GFxGlyphNode **v10; // eax
  struct GFxGlyphNode *result; // eax
  _DWORD *v12; // ecx

  Index = GHashSetBase<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeAltHashF,GAllocatorLH<GFxGlyphParam,195>,GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>>::findIndexAlt<GFxGlyphParam>(
            this: (int *)this + 485,
            a2: (int)a3);
  if ( Index < 0 )
    return GFxGlyphRasterCache::rasterizeAndPack(this, a2, (unsigned int)a3, a4, (unsigned int)a5, a6, count);
  v9 = *((_DWORD *)this + 485) + 24 * Index + 16;
  if ( v9 == 0 )
    return GFxGlyphRasterCache::rasterizeAndPack(this, a2, (unsigned int)a3, a4, (unsigned int)a5, a6, count);
  v10 = (struct GFxGlyphNode **)(v9 + 12);
  if ( v10 == nullptr )
    return GFxGlyphRasterCache::rasterizeAndPack(this, a2, (unsigned int)a3, a4, (unsigned int)a5, a6, count);
  result = *v10;
  if ( result == nullptr )
    return GFxGlyphRasterCache::rasterizeAndPack(this, a2, (unsigned int)a3, a4, (unsigned int)a5, a6, count);
  v12 = *((_DWORD **)result + 3);
  *(_DWORD *)(*v12 + 4) = v12[1];
  *(_DWORD *)v12[1] = *v12;
  *v12 = *((_DWORD *)this + 464);
  v12[1] = (char *)this + 1856;
  *(_DWORD *)(*((_DWORD *)this + 464) + 4) = v12;
  *((_DWORD *)this + 464) = v12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10189110
// Name: public: void GArrayUnsafeBase<struct GRasterizer::Cell __near *,struct GAllocatorLH_POD<struct GRasterizer::Cell __near *,134>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<GRasterizer::Cell *,GAllocatorLH_POD<GRasterizer::Cell *,134>>::Reserve(
        int this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 134;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4 * v5, a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10189180
// Name: public: void GArrayUnsafeBase<struct GRasterizer::SortedY,struct GAllocatorLH_POD<struct GRasterizer::SortedY,134>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<GRasterizer::SortedY,GAllocatorLH_POD<GRasterizer::SortedY,134>>::Reserve(
        int this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 134;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 8 * v5, a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018BEB0
// Name: public: void GArrayUnsafeBase<bool,struct GAllocatorLH_POD<bool,133>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<bool,GAllocatorLH_POD<bool,133>>::Reserve(int this, unsigned int a2, int a3)
{
  unsigned int v3; // edi
  unsigned int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 133;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: v5, a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018BF20
// Name: public: void GArrayUnsafeBase<struct GTessellator::ScanChainType,struct GAllocatorLH_POD<struct GTessellator::ScanChainType,133>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<GTessellator::ScanChainType,GAllocatorLH_POD<GTessellator::ScanChainType,133>>::Reserve(
        int this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 133;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(
                          this: GMemory::pGlobalHeap,
                          a2: this,
                          a3: 12 * v5,
                          a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018BF90
// Name: public: void GArrayUnsafeBase<bool,struct GAllocatorGH_POD<bool,133>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<bool,GAllocatorGH_POD<bool,133>>::Reserve(int this, unsigned int a2, int a3)
{
  unsigned int v3; // edi
  unsigned int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 133;
      *(_DWORD *)this = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v5, a3: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018C000
// Name: public: void GArrayUnsafeBase<unsigned int,struct GAllocatorLH_POD<unsigned int,133>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,133>>::Reserve(
        EHExceptionRecord *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  unsigned int v5; // eax

  v3 = cap;
  if ( (_EXCEPTION_RECORD *)cap > this->ExceptionRecord )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->ExceptionCode);
    v5 = v3 + extraTail;
    this->ExceptionRecord = (_EXCEPTION_RECORD *)(v3 + extraTail);
    if ( v5 != 0 )
    {
      cap = 133;
      this->ExceptionCode = (unsigned int)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                            this: GMemory::pGlobalHeap,
                                            a2: this,
                                            a3: 4 * v5,
                                            a4: &cap);
      this->ExceptionFlags = 0;
      return;
    }
    this->ExceptionCode = 0;
  }
  this->ExceptionFlags = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10199BC0
// Name: public: void GArrayUnsafeBase<unsigned int,struct GAllocatorLH_POD<unsigned int,136>>::Reserve(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,136>>::Reserve(
        int this,
        unsigned int a2,
        int a3)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = a2;
  if ( a2 > *(_DWORD *)(this + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)this);
    v5 = v3 + a3;
    *(_DWORD *)(this + 8) = v3 + a3;
    if ( v5 != 0 )
    {
      a2 = 136;
      *(_DWORD *)this = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4 * v5, a4: &a2);
      *(_DWORD *)(this + 4) = 0;
      return;
    }
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E47B8
// Name: private: unsigned int D3DXShader::CProgram::CompactLiterals_Allocate(unsigned int __near *,unsigned int,unsigned int,unsigned int)
// Source: semantic_flat_class
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CProgram::CompactLiterals_Allocate(
        D3DXShader::CProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int *v5; // esi
  unsigned int v6; // ebx
  int v7; // eax
  unsigned int v8; // eax

  v5 = &a2[4 * a3 + a4];
  if ( *v5 == -1 )
  {
    v6 = 4 * a5;
    v7 = *(_DWORD *)(4 * a5 + *((_DWORD *)this + 5));
    if ( *(_DWORD *)(v7 + 12) == -1 )
    {
      *(_DWORD *)(*(_DWORD *)(v6 + *((_DWORD *)this + 5)) + 12) = a3;
      *(_DWORD *)(*(_DWORD *)(v6 + *((_DWORD *)this + 5)) + 16) = a4;
      v8 = a5;
    }
    else
    {
      v8 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3, a4, a5: *(double *)(v7 + 32));
    }
    *v5 = v8;
  }
  return *v5;
}

//------------------------------------------------------------------------------
// Address: 0x101E481A
// Name: private: long D3DXShader::CProgram::CompactLiterals_Remap(unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactLiterals_Remap(
        D3DXShader::CProgram *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4)
{
  int v6; // ecx
  int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // eax
  unsigned int *v10; // edx
  unsigned int i; // esi
  int v12; // edx
  unsigned int v13; // edi
  unsigned int *v15; // [esp+1Ch] [ebp+Ch]
  unsigned int *v16; // [esp+1Ch] [ebp+Ch]

  v6 = 1;
  if ( a4 <= 1 )
  {
LABEL_4:
    v15 = nullptr;
    while ( 1 )
    {
      v7 = ((_BYTE)v15 - 1) & 3;
      v8 = a2[v7];
      if ( v8 != -1
        && *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a3) + 32) == *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v8)
                                                                                       + 32) )
      {
        break;
      }
      v15 = (unsigned int *)((char *)v15 + 1);
      if ( (unsigned int)v15 >= 4 )
        return 0;
    }
    v9 = 0;
    if ( a4 != 0 )
    {
      v10 = &a2[v7];
      do
        a3[v9++] = *v10;
      while ( v9 < a4 );
    }
  }
  else
  {
    while ( *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3[v6]) + 32) == *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *a3)
                                                                                           + 32) )
    {
      if ( ++v6 >= a4 )
        goto LABEL_4;
    }
    for ( i = 0; i < a4; ++i )
    {
      v16 = nullptr;
      while ( 1 )
      {
        v12 = ((_BYTE)v16 + (_BYTE)i) & 3;
        v13 = a2[v12];
        if ( v13 != -1
          && *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3[i]) + 32) == *(double *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v13)
                                                                                           + 32) )
        {
          break;
        }
        v16 = (unsigned int *)((char *)v16 + 1);
        if ( (unsigned int)v16 >= 4 )
          goto LABEL_20;
      }
      a3[i] = a2[v12];
LABEL_20:
      ;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E490B
// Name: private: long D3DXShader::CProgram::CompactLiterals(unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactLiterals(
        D3DXShader::CProgram *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v4; // edx
  unsigned int i; // eax
  unsigned int *v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edi
  unsigned int v10; // esi
  _DWORD *v11; // eax
  unsigned int v12; // edi
  int v13; // ecx
  unsigned int j; // eax
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // eax
  int v18; // esi
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int k; // ecx
  unsigned int v22; // eax
  unsigned int *v23; // edx
  unsigned int v24; // esi
  int v25; // ecx
  int v26; // eax
  unsigned int n; // ebx
  int v28; // esi
  unsigned int v29; // eax
  _QWORD v30[2]; // [esp+4h] [ebp-28h] BYREF
  unsigned int v31; // [esp+14h] [ebp-18h]
  unsigned int v32; // [esp+18h] [ebp-14h]
  unsigned int *m; // [esp+1Ch] [ebp-10h]
  D3DXShader::CProgram *v34; // [esp+20h] [ebp-Ch]
  unsigned int v35; // [esp+24h] [ebp-8h]
  unsigned int v36; // [esp+28h] [ebp-4h]
  unsigned int *v37; // [esp+3Ch] [ebp+10h]

  v4 = 0;
  v34 = this;
  v36 = 0;
  for ( i = 0; i < 4; ++i )
  {
    if ( a3[i] == -1 )
      break;
    ++v36;
  }
  if ( v36 == 0 )
    return 0;
  v7 = a4;
  if ( (*((_DWORD *)this + 27) & 6) == 0 )
  {
    memset(a4, 0, 4 * v36);
    goto LABEL_8;
  }
  v12 = 1;
  if ( v36 > 1 )
  {
    v13 = *((_DWORD *)this + 5);
    do
    {
      if ( *(double *)(*(_DWORD *)(v13 + 4 * *a3) + 32) != *(double *)(*(_DWORD *)(v13 + 4 * a3[v12]) + 32) )
        break;
      ++v12;
    }
    while ( v12 < v36 );
  }
  if ( v12 == v36 )
  {
    *a4 = 0;
    v36 = 1;
  }
  for ( j = 0; j < v36; ++j )
    v4 += a4[j] == 0;
  if ( (*((_BYTE *)v34 + 108) & 4) != 0 && v4 != 0 )
  {
    if ( v4 <= 1 )
    {
      v15 = 0;
      while ( 1 )
      {
        v16 = a4[v15];
        if ( (v16 & 8) != 0 )
          break;
        if ( v16 == 0 )
          a4[v15] = 8;
        if ( ++v15 >= v36 )
        {
          v4 = 0;
          goto LABEL_31;
        }
      }
    }
    return -2147467259;
  }
LABEL_31:
  v17 = 0;
  v18 = 0;
  if ( v36 != 0 )
  {
    do
    {
      v19 = a4[v17];
      if ( (v19 & v18) != 0 )
        return -2147467259;
      v18 |= v19;
    }
    while ( ++v17 < v36 );
  }
  v20 = 0;
  for ( k = 0; k < 4; ++k )
  {
    if ( ((1 << k) & v18) != 0 )
      ++v20;
  }
  if ( v4 + v20 > 4 )
    return -2147467259;
LABEL_8:
  v31 = 0;
  for ( m = a2; ; m += 4 )
  {
    v35 = 0;
    *(_OWORD *)v30 = *(_OWORD *)m;
    if ( v36 == 0 )
      goto LABEL_59;
    do
    {
      v8 = 0;
      v9 = v35;
      v10 = v7[v35];
      do
      {
        if ( ((1 << v8) & v10) != 0 )
        {
          v11 = (_DWORD *)v30 + v8;
          if ( *v11 == -1 )
          {
            *v11 = a3[v9];
          }
          else
          {
            v7 = a4;
            if ( *(double *)(*(_DWORD *)(*((_DWORD *)v34 + 5) + 4 * *v11) + 32) != *(double *)(*(_DWORD *)(*((_DWORD *)v34 + 5) + 4 * a3[v9])
                                                                                             + 32) )
              break;
          }
        }
        ++v8;
      }
      while ( v8 < 4 );
      if ( v8 < 4 )
        break;
      ++v35;
    }
    while ( v35 < v36 );
    if ( v35 >= v36 )
    {
LABEL_59:
      v22 = 0;
      v32 = 0;
      if ( v36 == 0 )
        break;
      v23 = a3;
      v35 = (char *)v7 - (char *)a3;
      do
      {
        v24 = 0;
        if ( *(unsigned int *)((char *)v23 + v35) == 0 )
        {
          do
          {
            v25 = *((_DWORD *)v30 + v24);
            if ( v25 != -1 )
            {
              v7 = a4;
              if ( *(double *)(*(_DWORD *)(*((_DWORD *)v34 + 5) + 4 * v25) + 32) == *(double *)(*(_DWORD *)(*((_DWORD *)v34 + 5) + 4 * a3[v22])
                                                                                              + 32) )
                break;
            }
            ++v24;
          }
          while ( v24 < 4 );
          if ( v24 >= 4 )
          {
            v26 = 0;
            while ( *((_DWORD *)v30 + v26) != -1 )
            {
              if ( (unsigned int)++v26 >= 4 )
                goto LABEL_57;
            }
            *((_DWORD *)v30 + v26) = *v23;
LABEL_57:
            if ( v26 == 4 )
              break;
          }
        }
        v22 = v32 + 1;
        ++v23;
        ++v32;
      }
      while ( v32 < v36 );
      if ( v32 >= v36 )
        break;
    }
    ++v31;
  }
  v37 = (unsigned int *)((char *)m - (char *)v30);
  for ( n = 0; n < 4; ++n )
  {
    v28 = 4 * n;
    v29 = *((_DWORD *)v30 + n);
    if ( v29 != *(_DWORD *)((char *)v30 + (_DWORD)&v37[n]) )
      v29 = D3DXShader::CProgram::CompactLiterals_Allocate(this: v34, a2, a3: v31, a4: n, a5: *((_DWORD *)v30 + n));
    *(_DWORD *)((char *)v30 + (char *)a3 - (char *)v30 + v28) = v29;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E4BAE
// Name: private: int D3DXShader::CProgram::CanVectorize_CanRead(unsigned int,class D3DXShader::CInstruction __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::CanVectorize_CanRead(
        D3DXShader::CProgram *this,
        unsigned int a2,
        struct D3DXShader::CInstruction *a3,
        unsigned int a4,
        unsigned int a5)
{
  _DWORD *v5; // esi
  unsigned int v6; // eax
  int v7; // eax
  int v8; // edx
  int i; // eax
  int v10; // eax

  v5 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * a2);
  v6 = v5[18];
  if ( v6 == -1 )
    return true;
  if ( v6 < a4 || v6 >= a5 )
    return false;
  v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a3 + 4));
  v8 = *(_DWORD *)(v7 + 24);
  for ( i = *(_DWORD *)(v7 + 20); i != -1; i = *(_DWORD *)(v10 + 20) )
  {
    if ( i == v5[5] )
      break;
    v10 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i);
    v8 = *(_DWORD *)(v10 + 24);
  }
  return i == v5[5] && v8 == v5[6];
}

//------------------------------------------------------------------------------
// Address: 0x101E4C18
// Name: private: int D3DXShader::CProgram::CanVectorize_IsSameRegister(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::CanVectorize_IsSameRegister(
        D3DXShader::CProgram *this,
        unsigned int a2,
        unsigned int a3)
{
  return *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2) + 4) == *(_DWORD *)(*(_DWORD *)(4 * a3
                                                                                               + *((_DWORD *)this + 5))
                                                                                   + 4)
      && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2) + 8) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                                               + 4 * a3)
                                                                                   + 8)
      && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2) + 12) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                                                + 4 * a3)
                                                                                    + 12);
}

//------------------------------------------------------------------------------
// Address: 0x101E4C6B
// Name: private: unsigned int D3DXShader::CProgram::CanVectorize_TraceMulAdd(unsigned int,double __near *,double __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CanVectorize_TraceMulAdd(
        D3DXShader::CProgram *this,
        unsigned int a2,
        double *a3,
        double *a4)
{
  int v4; // edx
  int v5; // esi
  int result; // eax
  _DWORD *v7; // esi
  void *v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  _DWORD *v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ebx
  _DWORD *v14; // eax
  int v15; // edx
  int v16; // edi
  int *v17; // eax
  int v18; // ecx
  _DWORD *v19; // edi
  int v20; // edx
  double *v21; // eax
  double v22; // st7
  int v23; // [esp+10h] [ebp-1Ch]
  int v24; // [esp+14h] [ebp-18h]
  int v25; // [esp+1Ch] [ebp-10h]
  int v26; // [esp+20h] [ebp-Ch]
  void *v27; // [esp+24h] [ebp-8h]
  _DWORD *v28; // [esp+28h] [ebp-4h]
  unsigned int v29; // [esp+34h] [ebp+8h]

  v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2);
  v5 = *(_DWORD *)(v4 + 72);
  v26 = *((_DWORD *)this + 5);
  result = -1;
  if ( v5 != -1 && *(_DWORD *)(v4 + 8) == -1 )
  {
    v7 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v5);
    v8 = (void *)(*v7 & 0xFFF00000);
    v27 = v8;
    if ( v8 == &loc_10100000 )
    {
      v9 = v7[3];
      v10 = 0;
      if ( v9 != 0 )
      {
        v11 = (_DWORD *)v7[4];
        do
        {
          if ( *v11 == a2 )
            break;
          ++v10;
          ++v11;
        }
        while ( v10 < v9 );
      }
      if ( a3 != nullptr )
        *a3 = -*a3;
      return *(_DWORD *)(v7[2] + 4 * v10);
    }
    else if ( v8 == (void *)542113792 || v8 == (void *)541065216 )
    {
      v12 = v7[3];
      v13 = 0;
      if ( v12 != 0 )
      {
        v14 = (_DWORD *)v7[4];
        do
        {
          if ( *v14 == a2 )
            break;
          ++v13;
          ++v14;
        }
        while ( v13 < v12 );
      }
      v15 = v7[3];
      v16 = v7[2];
      v29 = 0;
      v25 = *((_DWORD *)this + 4);
      v24 = 4 * v15;
      v17 = (int *)(v16 + 4 * v13);
      v18 = -1 * v15;
      v19 = (_DWORD *)(v16 + 4 * (v13 + v15));
      v28 = v19;
      while ( 1 )
      {
        v23 = *v17;
        v20 = *(_DWORD *)(v26 + 4 * *v19);
        if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v20 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v20 + 8) == -1 )
          break;
        ++v29;
        v17 = (int *)((char *)v17 + v24);
        v19 = &v28[v18];
        v28 = (_DWORD *)((char *)v28 + v18 * 4);
        if ( v29 >= 2 )
        {
          if ( v27 != (void *)541065216 || *(_DWORD *)(v7[2] + 4 * v13) != *(_DWORD *)(v7[2] + 4 * (v7[3] + v13)) )
            return -1;
          if ( a3 != nullptr )
            *a3 = *a3 + *a3;
          return *(_DWORD *)(4 * v13 + v7[2]);
        }
      }
      v21 = a3;
      if ( a3 != nullptr )
      {
        v22 = *(double *)(v20 + 32) * *a3;
        if ( v27 != (void *)542113792 )
        {
          v21 = a4;
          v22 = v22 + *a4;
        }
        *v21 = v22;
      }
      return v23;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E4DD8
// Name: private: long D3DXShader::CProgram::CombinePools(unsigned int,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CombinePools(
        D3DXShader::CProgram *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int i; // edx
  int v5; // eax
  unsigned int j; // edi
  int v7; // edx
  int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // edi
  int v11; // esi
  _DWORD *v12; // eax
  int v13; // edx
  int v14; // eax
  _DWORD *v15; // edx
  int k; // [esp+Ch] [ebp-8h]
  unsigned int m; // [esp+10h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * i);
    if ( (a3 & *(_DWORD *)(v5 + 4)) == a3 && (*(_DWORD *)(v5 + 4) & a4) == 0 )
      *(_DWORD *)(v5 + 8) = 0;
  }
  for ( j = 0; j < *((_DWORD *)this + 2); ++j )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * j);
    v8 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v7 + 4));
    if ( (a3 & *(_DWORD *)(v8 + 4)) == a3 && (*(_DWORD *)(v8 + 4) & a4) == 0 )
    {
      v9 = *(_DWORD *)(v7 + 12) + 1;
      if ( *(_DWORD *)(v8 + 8) <= v9 )
        *(_DWORD *)(v8 + 8) = v9;
    }
  }
  v10 = 0;
  v11 = 0;
  for ( k = 0; v10 < *((_DWORD *)this + 1); ++v10 )
  {
    v12 = *(_DWORD **)(*((_DWORD *)this + 4) + 4 * v10);
    v13 = v12[1];
    if ( (a3 & v13) == a3 && (v13 & a4) == 0 )
    {
      v12[4] = v11;
      v12[6] = a2;
      if ( (v13 & 0x400) != 0 )
        k = 1;
      v11 += v12[2];
      v12[2] = 0;
    }
  }
  for ( m = 0; m < *((_DWORD *)this + 2); ++m )
  {
    v14 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * m);
    v15 = *(_DWORD **)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v14 + 4));
    if ( (a3 & v15[1]) == a3 && (v15[1] & a4) == 0 )
    {
      *(_DWORD *)(v14 + 4) = v15[6];
      *(_DWORD *)(v14 + 12) += v15[4];
    }
  }
  *(_DWORD *)(*(_DWORD *)(4 * a2 + *((_DWORD *)this + 4)) + 8) = v11;
  if ( k != 0 )
    *(_BYTE *)(*(_DWORD *)(4 * a2 + *((_DWORD *)this + 4)) + 5) |= 4u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E4EFD
// Name: private: int D3DXShader::CProgram::MutuallyExclusive(unsigned int,int,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::MutuallyExclusive(
        D3DXShader::CProgram *this,
        unsigned int a2,
        int a3,
        unsigned int a4,
        int a5)
{
  unsigned int v5; // eax
  D3DXShader::CProgram *v6; // edx
  unsigned int v7; // esi
  unsigned int i; // ecx
  unsigned int v9; // ecx
  unsigned int j; // edi
  bool v11; // cc
  int v12; // edi
  unsigned int v13; // edx
  int v14; // eax
  int v15; // ebx
  unsigned int v16; // esi
  int v17; // ecx
  int v18; // edi
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // esi
  unsigned int v25; // [esp+Ch] [ebp-4h]

  v5 = a2;
  v6 = this;
  v7 = 0;
  v25 = 0;
  for ( i = a2; i != -1; ++v25 )
    i = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v6 + 5) + 4 * i) + 20);
  v9 = a4;
  for ( j = a4; j != -1; ++v7 )
    j = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v6 + 5) + 4 * j) + 20);
  v11 = v7 <= v25;
  if ( v7 < v25 )
  {
    v12 = *((_DWORD *)v6 + 5);
    v13 = v25 - v7;
    do
    {
      v14 = *(_DWORD *)(v12 + 4 * v5);
      v15 = *(_DWORD *)(v14 + 24);
      --v25;
      --v13;
      v5 = *(_DWORD *)(v14 + 20);
      a3 = v15;
    }
    while ( v13 != 0 );
    v6 = this;
    v11 = v7 <= v25;
  }
  if ( v11 )
  {
    v18 = a5;
  }
  else
  {
    v16 = v7 - v25;
    do
    {
      --v16;
      v17 = *(_DWORD *)(*((_DWORD *)v6 + 5) + 4 * v9);
      v18 = *(_DWORD *)(v17 + 24);
      v9 = *(_DWORD *)(v17 + 20);
    }
    while ( v16 != 0 );
  }
  if ( v5 != v9 )
  {
    v19 = *((_DWORD *)v6 + 5);
    do
    {
      v20 = *(_DWORD *)(v19 + 4 * v5);
      v21 = *(_DWORD *)(v19 + 4 * v9);
      v22 = *(_DWORD *)(v20 + 24);
      v18 = *(_DWORD *)(v21 + 24);
      v5 = *(_DWORD *)(v20 + 20);
      v9 = *(_DWORD *)(v21 + 20);
      a3 = v22;
    }
    while ( v5 != v9 );
  }
  return a3 != v18;
}
