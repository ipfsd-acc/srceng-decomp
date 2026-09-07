// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontcachemanager.cpp
// Functions: 50
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontcachemanager.h"

//------------------------------------------------------------------------------
// Address: 0x100B2850
// Name: public: struct GFxTimelineSnapshot::SnapshotElement __near * GListAllocBase<struct GFxTimelineSnapshot::SnapshotElement,50,struct GAllocatorDH<struct GFxTimelineSnapshot::SnapshotElement,2>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GListAllocBase<GFxTimelineSnapshot::SnapshotElement,50,GAllocatorDH<GFxTimelineSnapshot::SnapshotElement,2>>::Alloc(
        int *this)
{
  int result; // eax
  unsigned int v3; // ecx
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  int v6; // ecx
  int v7; // [esp+8h] [ebp-4h] BYREF

  result = *(this + 3);
  if ( result != 0 )
  {
    *(this + 3) = *(_DWORD *)result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x32 )
    {
      v4 = *(this + 4);
      v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
      v7 = 2;
      result = v5(a1: v4, a2: 2804, a3: &v7);
      *(_DWORD *)(result + 2800) = 0;
      v6 = *(this + 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 2800) = result;
      else
        *this = result;
      *(this + 1) = result;
      *(this + 2) = 1;
    }
    else
    {
      result = *(this + 1) + 56 * v3;
      *(this + 2) = v3 + 1;
    }
  }
  if ( result != 0 )
  {
    *(_DWORD *)(result + 8) = -1;
    *(_DWORD *)(result + 16) = 0;
    *(_DWORD *)(result + 20) = 0;
    *(_DWORD *)(result + 24) = 0;
    *(_DWORD *)(result + 28) = 0;
    *(_DWORD *)(result + 32) = 0;
    *(_DWORD *)(result + 36) = 0;
    *(_DWORD *)(result + 40) = 0;
    *(_DWORD *)(result + 44) = 0;
    *(_DWORD *)(result + 48) = 0;
    *(_WORD *)(result + 52) = 255;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E16B0
// Name: public: void GListAllocBase<struct GFxCachedMeshSet,127,struct GAllocatorLH_POD<struct GFxCachedMeshSet,138>>::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GListAllocBase<GFxCachedMeshSet,127,GAllocatorLH_POD<GFxCachedMeshSet,138>>::ClearAndRelease(
        _DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v3; // esi

  result = (_DWORD *)*this;
  if ( *this != 0 )
  {
    do
    {
      v3 = (_DWORD *)result[762];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: result);
      result = v3;
    }
    while ( v3 != nullptr );
  }
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 127;
  *(this + 3) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1700
// Name: public: struct GFxCachedMeshSet __near * GListAllocBase<struct GFxCachedMeshSet,127,struct GAllocatorLH_POD<struct GFxCachedMeshSet,138>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GListAllocBase<GFxCachedMeshSet,127,GAllocatorLH_POD<GFxCachedMeshSet,138>>::Alloc(
        unsigned int *this)
{
  unsigned int *result; // eax
  unsigned int v3; // ecx
  int v4; // eax
  const void *v5; // eax
  int v6; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  result = (unsigned int *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x7F )
    {
      v5 = (const void *)*(this + 4);
      v7 = 138;
      result = (unsigned int *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v5,
                                 a3: 3052,
                                 a4: &v7);
      result[762] = 0;
      v6 = *(this + 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 3048) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      v4 = *(this + 1);
      *(this + 2) = v3 + 1;
      return (unsigned int *)(v4 + 24 * v3);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1790
// Name: public: void GListAllocBase<struct GFxCachedMeshSetBag,127,struct GAllocatorLH<struct GFxCachedMeshSetBag,138>>::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GListAllocBase<GFxCachedMeshSetBag,127,GAllocatorLH<GFxCachedMeshSetBag,138>>::ClearAndRelease(
        _DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v3; // esi

  result = (_DWORD *)*this;
  if ( *this != 0 )
  {
    do
    {
      v3 = (_DWORD *)result[1270];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: result);
      result = v3;
    }
    while ( v3 != nullptr );
  }
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 127;
  *(this + 3) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1960
// Name: public: struct GFxCachedMeshSetBag __near * GListAllocBase<struct GFxCachedMeshSetBag,127,struct GAllocatorLH<struct GFxCachedMeshSetBag,138>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GListAllocBase<GFxCachedMeshSetBag,127,GAllocatorLH<GFxCachedMeshSetBag,138>>::Alloc(
        unsigned int *this)
{
  unsigned int *result; // eax
  unsigned int v3; // ecx
  const void *v4; // eax
  int v5; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (unsigned int *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x7F )
    {
      v4 = (const void *)*(this + 4);
      v6 = 138;
      result = (unsigned int *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v4,
                                 a3: 5084,
                                 a4: &v6);
      result[1270] = 0;
      v5 = *(this + 1);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 5080) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      result = (unsigned int *)(*(this + 1) + 40 * v3);
      *(this + 2) = v3 + 1;
    }
  }
  if ( result != nullptr )
  {
    result[2] = 0;
    result[3] = 0;
    result[6] = (unsigned int)(result + 4);
    result[7] = (unsigned int)(result + 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F46B0
// Name: public: bool GFxGlyphParam::operator==(struct GFxGlyphParam const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxGlyphParam::operator==(_WORD *this, int a2)
{
  return *(_DWORD *)this == *(_DWORD *)a2
      && *(this + 2) == *(_WORD *)(a2 + 4)
      && *((_BYTE *)this + 6) == *(_BYTE *)(a2 + 6)
      && *((_BYTE *)this + 7) == *(_BYTE *)(a2 + 7)
      && *((_BYTE *)this + 8) == *(_BYTE *)(a2 + 8)
      && *((_BYTE *)this + 9) == *(_BYTE *)(a2 + 9)
      && *((_BYTE *)this + 10) == *(_BYTE *)(a2 + 10)
      && *((_BYTE *)this + 11) == *(_BYTE *)(a2 + 11);
}

//------------------------------------------------------------------------------
// Address: 0x100F4710
// Name: public: float GFxTextLineBuffer::GlyphEntry::GetFontSize(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxTextLineBuffer::GlyphEntry::GetFontSize(CIndexBufferBase *this)
{
  int v1; // eax

  v1 = (int)this->m_pBudgetGroupName & 0xFFF;
  if ( (BYTE2(this->m_pBudgetGroupName) & 0x10) == 0 )
    return (double)v1;
  return (float)((double)(unsigned int)v1 * 0.0625);
}

//------------------------------------------------------------------------------
// Address: 0x100F4760
// Name: public: void GFxTextLineBuffer::GlyphIterator::operator++(void)
// Source: json
//------------------------------------------------------------------------------
const VJobInstance *__cdecl GFxTextLineBuffer::GlyphIterator::operator++(const VJobInstance *result)
{
  int v1; // ecx
  int v2; // esi
  const VJobInstance *v3; // eax
  int *p_m_nIncrementalVectorIndex; // eax

  v2 = v1;
  v3 = *(const VJobInstance **)v1;
  if ( *(_DWORD *)v1 != 0 && (unsigned int)v3 < *(_DWORD *)(v1 + 4) )
  {
    if ( *(_DWORD *)(v1 + 88) == 0 )
      *(_DWORD *)(v1 + 88) = LOWORD(v3->m_pRoot) >> 12;
    p_m_nIncrementalVectorIndex = &v3->m_nIncrementalVectorIndex;
    *(_DWORD *)v1 = p_m_nIncrementalVectorIndex;
    if ( (p_m_nIncrementalVectorIndex[1] & 0xF000) != 0
      && *(_DWORD *)(v1 + 88) != 0
      && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)(v1 + 12)) )
    {
      GFxTextHighlighterPosIterator::operator+=(
        this: (CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)(v2 + 12),
        p: *(_DWORD *)(v2 + 88));
      *(_DWORD *)(v2 + 88) = 0;
    }
    return GFxTextLineBuffer::GlyphIterator::UpdateDesc(result);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100F47C0
// Name: public: float GFxTextLineBuffer::Line::GetBaseLineOffset(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxTextLineBuffer::Line::GetBaseLineOffset(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  if ( (int)this->m_pAllocator >= 0 )
    return (float)*((unsigned __int16 *)this + 19);
  else
    return (float)*((unsigned __int16 *)this + 13);
}

//------------------------------------------------------------------------------
// Address: 0x100F4800
// Name: public: unsigned int GFxFontCacheManager::GetNumRasterizedGlyphs(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManager::GetNumRasterizedGlyphs(Vector *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 18);
  if ( v1 != 0 )
    GFxGlyphRasterCache::GetNumRasterizedGlyphs(this: (GFxGlyphRasterCache *)(v1 + 76));
}

//------------------------------------------------------------------------------
// Address: 0x100F4820
// Name: public: unsigned int GFxFontCacheManager::GetNumTextures(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManager::GetNumTextures(Vector *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 18);
  if ( v1 != 0 )
    GFxGlyphRasterCache::GetNumTextures(this: (GFxGlyphRasterCache *)(v1 + 76));
}

//------------------------------------------------------------------------------
// Address: 0x100F4840
// Name: private: unsigned int GFxFontCacheManagerImpl::snapFontSizeToRamp(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontCacheManagerImpl::snapFontSizeToRamp(GFxFontCacheManagerImpl *this, unsigned int a2)
{
  unsigned int v2; // edx

  v2 = (a2 + 3) >> 2;
  if ( v2 + a2 > 0xFF )
    return 255;
  else
    return dword_103301C4[*((unsigned __int8 *)this + v2 + a2 + 2024)];
}

//------------------------------------------------------------------------------
// Address: 0x100F4880
// Name: public: bool GFxFontCacheManagerImpl::GlyphFits(class GRect<float> const __near &,unsigned int,float,struct GFxGlyphParam const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxFontCacheManagerImpl::GlyphFits(_DWORD *this, int a2, int a3, float a4, _BYTE *a5, float a6)
{
  unsigned int v7; // ecx
  unsigned int v8; // eax
  float v10; // [esp+24h] [ebp+Ch]
  float v11; // [esp+24h] [ebp+Ch]
  float v12; // [esp+2Ch] [ebp+14h]
  float v13; // [esp+2Ch] [ebp+14h]
  float v14; // [esp+2Ch] [ebp+14h]

  if ( a5[8] != 0 || a5[9] != 0 )
    return true;
  v7 = (__int64)((double)(unsigned int)a3 * a4 + 0.5);
  if ( (a5[7] & 1) == 0 )
  {
    v8 = v7 + ((v7 + 3) >> 2);
    if ( v8 > 0xFF )
      v7 = 255;
    else
      v7 = dword_103301C4[*((unsigned __int8 *)this + v8 + 2024)];
  }
  v12 = (float)v7;
  v10 = *(float *)(a2 + 12) * v12 * 0.0009765625;
  v11 = ceil(X: v10);
  v13 = *(float *)(a2 + 4) * v12 * 0.0009765625;
  v14 = floor(X: v13);
  return (double)(unsigned int)(*(this + 22) - 2 * *(this + 23)) * a6 > (double)((unsigned int)(__int64)(v11 - v14) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100F4A70
// Name: public: void GFxFontCacheManagerImpl::UnlockAllGlyphs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::UnlockAllGlyphs(GFxFontCacheManagerImpl *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int i; // eax

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 2544);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 106);
  if ( *((_BYTE *)this + 36) != 0 && (*((_DWORD *)this + 11))-- == 1 )
  {
    *((_DWORD *)this + 11) = *((_DWORD *)this + 10);
    for ( i = *((_DWORD *)this + 577);
          (GFxFontCacheManagerImpl *)i != (GFxFontCacheManagerImpl *)((char *)this + 2304);
          i = *(_DWORD *)(i + 4) )
    {
      *(_BYTE *)(i + 15) &= ~0x80u;
    }
    GFxGlyphSlotQueue::UnlockAllGlyphs(this: (GFxFontCacheManagerImpl *)((char *)this + 1884));
  }
  *(_WORD *)((char *)this + 37) = 257;
  LeaveCriticalSection(lpCriticalSection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100F4AD0
// Name: public: virtual void GFxFontCacheManagerImpl::RenEventHandler::OnEvent(class GRenderer __near *,enum GRendererEventHandler::EventType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::RenEventHandler::OnEvent(
        GFxFontCacheManagerImpl **this,
        struct GRenderer *a2,
        enum GRendererEventHandler::EventType a3)
{
  struct GRenderer *v4; // eax

  GFxFontCacheManagerImpl::UnlockAllGlyphs(this: *(this + 4));
  if ( a3 == Event_RendererReleased )
  {
    v4 = *((struct GRenderer **)*(this + 4) + 1);
    if ( v4 != nullptr && v4 == a2 )
    {
      (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)*(this + 4) + 1) + 196))(
        a1: *((_DWORD *)*(this + 4) + 1),
        a2: (int)*(this + 4) + 16);
      *((_DWORD *)*(this + 4) + 1) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4E20
// Name: public: bool GFxGlyphRasterCache::VerifyGlyphAndSendBack(struct GFxGlyphParam const __near &,struct GFxGlyphNode __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxGlyphRasterCache::VerifyGlyphAndSendBack(
        GFxGlyphRasterCache *this,
        const struct GFxGlyphParam *a2,
        struct GFxGlyphNode *a3)
{
  _DWORD *v3; // eax

  if ( *(_DWORD *)a2 != *(_DWORD *)a3
    || *((_WORD *)a2 + 2) != *((_WORD *)a3 + 2)
    || *((_BYTE *)a2 + 6) != *((_BYTE *)a3 + 6)
    || *((_BYTE *)a2 + 7) != *((_BYTE *)a3 + 7)
    || *((_BYTE *)a2 + 8) != *((_BYTE *)a3 + 8)
    || *((_BYTE *)a2 + 9) != *((_BYTE *)a3 + 9)
    || *((_BYTE *)a2 + 10) != *((_BYTE *)a3 + 10)
    || *((_BYTE *)a2 + 11) != *((_BYTE *)a3 + 11) )
  {
    return 0;
  }
  v3 = *((_DWORD **)a3 + 3);
  *(_DWORD *)(*v3 + 4) = v3[1];
  *(_DWORD *)v3[1] = *v3;
  *v3 = *((_DWORD *)this + 464);
  v3[1] = (char *)this + 1856;
  *(_DWORD *)(*((_DWORD *)this + 464) + 4) = v3;
  *((_DWORD *)this + 464) = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F4EA0
// Name: public: void GFxFontCacheManager::SetTextureConfig(struct GFxFontCacheManager::TextureConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
ABGR8888_t __thiscall GFxFontCacheManager::SetTextureConfig(int this, unsigned int *a2)
{
  float *v3; // esi
  ABGR8888_t result; // eax
  ABGR8888_t *v5; // ebx
  float v6; // [esp+10h] [ebp-14h]
  float v7; // [esp+2Ch] [ebp+8h]
  float v8; // [esp+2Ch] [ebp+8h]
  float v9; // [esp+2Ch] [ebp+8h]

  qmemcpy((void *)(this + 12), a2, 0x1Cu);
  GFxGlyphRasterCache::Init(
    this: (GFxGlyphRasterCache *)(*(_DWORD *)(this + 72) + 76),
    a2: *a2,
    a3: a2[1],
    a4: a2[2],
    a5: a2[3],
    a6: a2[4],
    a7: a2[5],
    a8: a2[6]);
  *(_DWORD *)(*(_DWORD *)(this + 72) + 2504) = *(_DWORD *)(this + 52);
  v3 = *(float **)(this + 72);
  v7 = *(float *)(this + 56);
  v3[627] = v7;
  v8 = tan(-v7);
  v6 = v8;
  v9 = tan(0.0);
  v3[630] = 1.0;
  v3[631] = v6;
  v3[632] = 0.0;
  v3[633] = v9;
  v3[634] = 1.0;
  v3[635] = 0.0;
  *(float *)(*(_DWORD *)(this + 72) + 2512) = *(float *)(this + 60);
  result = *(ABGR8888_t *)(this + 68);
  v5 = *(ABGR8888_t **)(this + 72);
  v5[11] = result;
  v5[10] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4F70
// Name: private: bool GFxFontCacheManagerImpl::isOuterContourCW(class GCompoundShape const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFontCacheManagerImpl::isOuterContourCW(
        GFxFontCacheManagerImpl *this,
        const struct GCompoundShape *a2)
{
  unsigned int v2; // ebx
  double v3; // st7
  double v4; // st6
  double v5; // st5
  double v6; // st4
  double v7; // st3
  int v8; // ecx
  int v9; // edi
  _DWORD *v10; // ecx
  int v11; // edx
  double v12; // rt0
  double v13; // st3
  double v14; // st7
  int v15; // esi
  int v16; // ecx
  int v17; // eax
  float v18; // ebx
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // eax
  int v23; // ecx
  double v24; // st2
  float *v25; // ecx
  double v26; // st2
  double v27; // st1
  float *v28; // ecx
  double v29; // st2
  double v30; // st1
  float *v31; // ecx
  double v32; // st2
  double v33; // st1
  float *v34; // ecx
  double v35; // st2
  double v36; // st1
  unsigned int v37; // edx
  unsigned int v38; // edi
  float *v39; // ecx
  double v40; // st2
  double v41; // st1
  double v42; // rt1
  double v43; // st3
  double v44; // st6
  double v45; // rt2
  double v46; // rt1
  double v48; // rt0
  float v49; // [esp+0h] [ebp-40h]
  float v50; // [esp+0h] [ebp-40h]
  float v51; // [esp+0h] [ebp-40h]
  float v52; // [esp+0h] [ebp-40h]
  float v53; // [esp+4h] [ebp-3Ch]
  float v54; // [esp+4h] [ebp-3Ch]
  float v55; // [esp+4h] [ebp-3Ch]
  float v56; // [esp+4h] [ebp-3Ch]
  unsigned int v57; // [esp+8h] [ebp-38h]
  int v58; // [esp+Ch] [ebp-34h]
  int v59; // [esp+10h] [ebp-30h]
  int v60; // [esp+14h] [ebp-2Ch]
  float v61; // [esp+18h] [ebp-28h]
  float v62; // [esp+1Ch] [ebp-24h]
  float v63; // [esp+20h] [ebp-20h]
  float v64; // [esp+24h] [ebp-1Ch]
  int v65; // [esp+28h] [ebp-18h]
  bool v66; // [esp+3Fh] [ebp-1h]
  float v67; // [esp+48h] [ebp+8h]
  float v68; // [esp+48h] [ebp+8h]
  float v69; // [esp+48h] [ebp+8h]
  float v70; // [esp+48h] [ebp+8h]

  v2 = 0;
  v66 = true;
  v62 = -1.0e10;
  v65 = 0;
  v61 = -1.0e10;
  v57 = *((_DWORD *)a2 + 6);
  v64 = 1.0e10;
  v63 = 1.0e10;
  if ( v57 == 0 )
    return 1;
  v3 = 0.0;
  v4 = (float)1.0e10;
  v5 = v4;
  v60 = *((_DWORD *)a2 + 9);
  v6 = (float)-1.0e10;
  v7 = v6;
  do
  {
    v8 = *(_DWORD *)(v60 + 4 * (v2 >> 6));
    v9 = *(_DWORD *)(v8 + 24 * (v2 & 0x3F) + 4);
    v10 = (_DWORD *)(v8 + 24 * (v2 & 0x3F));
    if ( (unsigned int)v9 > 2 )
    {
      v11 = v10[2];
      v12 = v7;
      v13 = v3;
      v14 = v12;
      v67 = v13;
      v15 = *(_DWORD *)(*v10 + 20);
      v16 = *(_DWORD *)(v15 + 4 * ((unsigned int)(v11 + v9 - 1) >> 8));
      v17 = (unsigned __int8)(v11 + v9 - 1);
      v18 = *(float *)(v16 + 8 * v17);
      v53 = *(float *)(v16 + 8 * v17 + 4);
      v19 = 0;
      v58 = v11;
      v49 = v18;
      if ( v9 >= 4 )
      {
        v20 = v11 + 2;
        v21 = ((unsigned int)(v9 - 4) >> 2) + 1;
        v59 = 4 * v21;
        do
        {
          v22 = *(_DWORD *)(v15 + 4 * ((v20 - 2) >> 8));
          v23 = (unsigned __int8)(v20 - 2);
          v24 = *(float *)(v22 + 8 * v23);
          v25 = (float *)(v22 + 8 * v23);
          if ( v24 < v4 )
            v4 = *v25;
          if ( v25[1] < v5 )
            v5 = v25[1];
          if ( *v25 > v6 )
            v6 = *v25;
          if ( v25[1] > v14 )
            v14 = v25[1];
          v26 = v25[1] * v49;
          v50 = *v25;
          v27 = *v25 * v53;
          v54 = v25[1];
          v28 = (float *)(*(_DWORD *)(v15 + 4 * ((v20 - 1) >> 8)) + 8 * (unsigned __int8)(v20 - 1));
          v68 = v26 - v27 + v67;
          if ( *v28 < v4 )
            v4 = *v28;
          if ( v28[1] < v5 )
            v5 = v28[1];
          if ( *v28 > v6 )
            v6 = *v28;
          if ( v28[1] > v14 )
            v14 = v28[1];
          v29 = v28[1] * v50;
          v51 = *v28;
          v30 = *v28 * v54;
          v55 = v28[1];
          v31 = (float *)(*(_DWORD *)(v15 + 4 * (v20 >> 8)) + 8 * (unsigned __int8)v20);
          v69 = v29 - v30 + v68;
          if ( *v31 < v4 )
            v4 = *v31;
          if ( v31[1] < v5 )
            v5 = v31[1];
          if ( *v31 > v6 )
            v6 = *v31;
          if ( v31[1] > v14 )
            v14 = v31[1];
          v32 = v31[1] * v51;
          v52 = *v31;
          v33 = *v31 * v55;
          v56 = v31[1];
          v34 = (float *)(*(_DWORD *)(v15 + 4 * ((v20 + 1) >> 8)) + 8 * (unsigned __int8)(v20 + 1));
          v70 = v32 - v33 + v69;
          if ( *v34 < v4 )
            v4 = *v34;
          if ( v34[1] < v5 )
            v5 = v34[1];
          if ( *v34 > v6 )
            v6 = *v34;
          if ( v34[1] > v14 )
            v14 = v34[1];
          v35 = v34[1] * v52;
          v20 += 4;
          --v21;
          v36 = *v34 * v56;
          v49 = *v34;
          v53 = v34[1];
          v67 = v35 - v36 + v70;
        }
        while ( v21 != 0 );
        v19 = v59;
        v11 = v58;
      }
      v2 = v65;
      if ( v19 < v9 )
      {
        v37 = v19 + v11;
        v38 = v9 - v19;
        do
        {
          v39 = (float *)(*(_DWORD *)(v15 + 4 * (v37 >> 8)) + 8 * (unsigned __int8)v37);
          if ( *v39 < v4 )
            v4 = *v39;
          if ( v39[1] < v5 )
            v5 = v39[1];
          if ( *v39 > v6 )
            v6 = *v39;
          if ( v39[1] > v14 )
            v14 = v39[1];
          v40 = v39[1] * v49;
          ++v37;
          --v38;
          v41 = *v39 * v53;
          v49 = *v39;
          v53 = v39[1];
          v67 = v40 - v41 + v67;
        }
        while ( v38 != 0 );
      }
      if ( v64 <= v4 && v63 <= v5 && v62 >= v6 && v61 >= v14 )
      {
        v48 = v13;
        v7 = v14;
        v3 = v48;
      }
      else
      {
        v42 = v13;
        v43 = v4;
        v44 = v42;
        v64 = v43;
        v45 = v43;
        v63 = v5;
        v62 = v6;
        v61 = v14;
        v46 = v14;
        v66 = v44 < v67;
        v3 = v44;
        v7 = v46;
        v4 = v45;
      }
    }
    v65 = ++v2;
  }
  while ( v2 < v57 );
  return v66;
}

//------------------------------------------------------------------------------
// Address: 0x100F53E0
// Name: public: void GListAllocBase<struct GFxBatchPackage,127,struct GAllocatorLH_POD<struct GFxBatchPackage,194>>::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GListAllocBase<GFxBatchPackage,127,GAllocatorLH_POD<GFxBatchPackage,194>>::ClearAndRelease(
        _DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v3; // esi

  result = (_DWORD *)*this;
  if ( *this != 0 )
  {
    do
    {
      v3 = (_DWORD *)result[508];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: result);
      result = v3;
    }
    while ( v3 != nullptr );
  }
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 127;
  *(this + 3) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F5430
// Name: public: struct GFxBatchPackage __near * GListAllocBase<struct GFxBatchPackage,127,struct GAllocatorLH_POD<struct GFxBatchPackage,194>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GListAllocBase<GFxBatchPackage,127,GAllocatorLH_POD<GFxBatchPackage,194>>::Alloc(
        unsigned int *this)
{
  unsigned int *result; // eax
  unsigned int v3; // ecx
  const void *v4; // eax
  int v5; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (unsigned int *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x7F )
    {
      v4 = (const void *)*(this + 4);
      v6 = 194;
      result = (unsigned int *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v4,
                                 a3: 2036,
                                 a4: &v6);
      result[508] = 0;
      v5 = *(this + 1);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 2032) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      result = (unsigned int *)(*(this + 1) + 16 * v3);
      *(this + 2) = v3 + 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F54C0
// Name: public: struct GFxFontCacheManagerImpl::VectorGlyphShape __near * GListAllocBase<struct GFxFontCacheManagerImpl::VectorGlyphShape,127,struct GAllocatorLH<struct GFxFontCacheManagerImpl::VectorGlyphShape,196>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GListAllocBase<GFxFontCacheManagerImpl::VectorGlyphShape,127,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphShape,196>>::Alloc(
        unsigned int *this)
{
  unsigned int *result; // eax
  unsigned int v3; // ecx
  const void *v4; // eax
  int v5; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (unsigned int *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x7F )
    {
      v4 = (const void *)*(this + 4);
      v6 = 196;
      result = (unsigned int *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v4,
                                 a3: 3052,
                                 a4: &v6);
      result[762] = 0;
      v5 = *(this + 1);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 3048) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      result = (unsigned int *)(*(this + 1) + 24 * v3);
      *(this + 2) = v3 + 1;
    }
  }
  if ( result != nullptr )
    result[5] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F5AD0
// Name: public: GFxTextLineBuffer::GlyphIterator::GlyphIterator(void __near *,unsigned int,union GFxTextLineBuffer::GFxFormatDataEntry __near *)
// Source: json
//------------------------------------------------------------------------------
VJobInstance *__thiscall GFxTextLineBuffer::GlyphIterator::GlyphIterator(
        _DWORD *this,
        VJobInstance *result,
        unsigned int glyphsCount,
        VJobInstance *pfmtData)
{
  const VJobInstance *v6; // [esp+0h] [ebp-4h]

  *(this + 7) = 0;
  *(this + 9) = 0;
  *(this + 10) = 0;
  *(this + 11) = 0;
  *(this + 6) = -1;
  *(this + 8) = -1;
  *(this + 14) = 0;
  *(this + 13) = 0;
  *(this + 12) = 0;
  *((_BYTE *)this + 60) = 0;
  *(this + 5) = 0;
  *(this + 4) = 0;
  *(this + 16) = 0;
  *(this + 17) = 0;
  *(this + 18) = 0;
  *(this + 19) = 0;
  *(this + 20) = 0;
  *(this + 21) = 0;
  *(this + 22) = 0;
  *this = result;
  *(this + 1) = (char *)result + 8 * glyphsCount;
  *(this + 2) = pfmtData;
  GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v6);
  return (VJobInstance *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100F5B40
// Name: public: GFxTextLineBuffer::GlyphIterator::GlyphIterator(void __near *,unsigned int,union GFxTextLineBuffer::GFxFormatDataEntry __near *,class GFxTextHighlighter const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxTextLineBuffer::GlyphIterator *__thiscall GFxTextLineBuffer::GlyphIterator::GlyphIterator(GFxTextLineBuffer::GlyphIterator *this, char *pglyphs, unsigned int glyphsCount, VJobInstance *pfmtData, GFxTextHighlighter *a5, unsigned int lineStartPos)
{
  struct GFxTextHighlighterPosIterator *PosIterator; // eax
  const VJobInstance *v9; // [esp+0h] [ebp-38h]
  char v10; // [esp+4h] [ebp-34h] BYREF

  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 6) = -1;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_BYTE *)this + 60) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  PosIterator = GFxTextHighlighter::GetPosIterator(
                  this: a5,
                  retstr: (GFxTextHighlighterPosIterator *)&v10,
                  a3: lineStartPos,
                  a4: 0xFFFFFFFF);
  *((_DWORD *)this + 3) = PosIterator->pVFTable;
  *((_DWORD *)this + 4) = PosIterator->spare;
  qmemcpy((char *)this + 20, PosIterator->name, 41);
  *(_DWORD *)this = pglyphs;
  *((_DWORD *)this + 1) = &pglyphs[8 * glyphsCount];
  *((_DWORD *)this + 2) = pfmtData;
  GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: v9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F5C10
// Name: public: void GFxFontCacheManagerImpl::DisplayBatchPackage(struct GFxBatchPackage __near *,class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::DisplayBatchPackage(
        GFxFontCacheManagerImpl *this,
        struct GFxBatchPackage *a2,
        struct GFxDisplayContext *a3,
        const struct GMatrix2D *a4,
        const struct GRenderer::Cxform *a5)
{
  _DWORD *v5; // edi
  int v6; // eax
  _DWORD *v7; // ebx
  unsigned int v8; // esi
  unsigned int v9; // ecx
  _DWORD *v10; // eax
  int v11; // eax
  bool v12; // zf
  _DWORD *v13; // eax
  int v14; // edx
  unsigned int v15; // eax
  _DWORD *v16; // ecx
  _DWORD *v17; // [esp+0h] [ebp-8h] BYREF
  char v18; // [esp+4h] [ebp-4h]
  struct GFxBatchPackage *v19; // [esp+10h] [ebp+8h]
  struct GFxDisplayContext *i; // [esp+14h] [ebp+Ch]

  if ( a2 != nullptr && *((GFxFontCacheManagerImpl **)a2 + 3) == this )
  {
    v5 = *((_DWORD **)a2 + 2);
    if ( v5 != nullptr && v5[2] != 0 )
    {
      v19 = *(struct GFxBatchPackage **)(*((_DWORD *)a3 + 18) + 12);
      (*(void (__stdcall **)(const struct GRenderer::Cxform *))(*(_DWORD *)v19 + 64))(a1: a5);
      v17 = v5 + 7;
      v18 = 0;
      for ( i = nullptr; (unsigned int)i < 2; i = (struct GFxDisplayContext *)((char *)i + 1) )
      {
        v6 = *v5;
        if ( *v5 != 0 )
        {
          v9 = *(_DWORD *)(v6 + 4);
          v8 = 0;
          v10 = (_DWORD *)(v6 + 8);
          do
          {
            if ( *v10 != -2 )
              break;
            ++v8;
            v10 += 9;
          }
          while ( v8 <= v9 );
          v7 = v5;
        }
        else
        {
          v7 = nullptr;
          v8 = 0;
        }
        while ( v7 != nullptr )
        {
          v11 = *v7;
          if ( *v7 == 0 || (signed int)v8 > *(_DWORD *)(v11 + 4) )
            break;
          v12 = *(_DWORD *)(v11 + 36 * v8 + 20) == (_DWORD)i;
          v13 = (_DWORD *)(v11 + 36 * v8);
          if ( v12 )
          {
            v14 = *(_DWORD *)v19;
            if ( v13[10] != 0 )
              (*(void (__thiscall **)(struct GFxBatchPackage *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const struct GMatrix2D *, _DWORD *, _DWORD **))(v14 + 152))(
                a1: v19,
                a2: v5[1],
                a3: v5[2],
                a4: v13[6],
                a5: v13[8],
                a6: v13[9],
                a7: a4,
                a8: v5 + 9,
                a9: &v17);
            else
              (*(void (__thiscall **)(struct GFxBatchPackage *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const struct GMatrix2D *, _DWORD **))(v14 + 148))(
                a1: v19,
                a2: v5[1],
                a3: v5[2],
                a4: v13[6],
                a5: v13[8],
                a6: v13[9],
                a7: a4,
                a8: &v17);
          }
          v15 = *(_DWORD *)(*v7 + 4);
          if ( (int)v8 <= (int)v15 && ++v8 <= v15 )
          {
            v16 = (_DWORD *)(*v7 + 36 * v8 + 8);
            do
            {
              if ( *v16 != -2 )
                break;
              ++v8;
              v16 += 9;
            }
            while ( v8 <= v15 );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6010
// Name: public: class GFxTextLineBuffer::GlyphIterator GFxTextLineBuffer::Line::Begin(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100F6050
// Name: public: class GFxTextLineBuffer::GlyphIterator GFxTextLineBuffer::Line::Begin(class GFxTextHighlighter const __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100F60F0
// Name: public: GFxBatchPackageData::GFxBatchPackageData(void)
// Source: json
//------------------------------------------------------------------------------
GFxBatchPackageData *__thiscall GFxBatchPackageData::GFxBatchPackageData(GFxBatchPackageData *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((float *)this + 9) = 6.0;
  *((_DWORD *)this + 7) = 0;
  *((float *)this + 10) = 12.0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 11) = 0;
  *((float *)this + 12) = 1.0;
  *((float *)this + 13) = 1.0;
  *((_DWORD *)this + 14) = 0;
  *((_WORD *)this + 38) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F6140
// Name: public: GFxFontCacheManagerImpl::GFxFontCacheManagerImpl(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GFxFontCacheManagerImpl *__thiscall GFxFontCacheManagerImpl::GFxFontCacheManagerImpl(
        GFxFontCacheManagerImpl *this,
        struct GMemoryHeap *a2)
{
  unsigned int v2; // ebx
  int v4; // eax
  float v6; // [esp+10h] [ebp-14h]
  float v7; // [esp+2Ch] [ebp+8h]
  float v8; // [esp+2Ch] [ebp+8h]

  v2 = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = &GFxFontCacheManagerImpl::FontDisposeHandler::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 4) = &GFxFontCacheManagerImpl::RenEventHandler::`vftable';
  *((_WORD *)this + 18) = 256;
  *((_BYTE *)this + 38) = 1;
  *((_DWORD *)this + 10) = 1;
  *((_DWORD *)this + 11) = 1;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = (char *)this + 48;
  *((_DWORD *)this + 14) = 127;
  *((_DWORD *)this + 17) = (char *)this + 68;
  *((_DWORD *)this + 18) = (char *)this + 68;
  GFxGlyphRasterCache::GFxGlyphRasterCache(this: (GFxFontCacheManagerImpl *)((char *)this + 76));
  *((_DWORD *)this + 570) = 0;
  *((_DWORD *)this + 571) = 0;
  *((_DWORD *)this + 572) = 0;
  *((_DWORD *)this + 573) = 127;
  *((_DWORD *)this + 574) = 0;
  *((_DWORD *)this + 575) = (char *)this + 2284;
  *((_DWORD *)this + 576) = (char *)this + 2304;
  *((_DWORD *)this + 577) = (char *)this + 2304;
  *((_DWORD *)this + 578) = 0;
  *((float *)this + 579) = 1.0;
  *((float *)this + 580) = 1.0;
  *((_DWORD *)this + 581) = 3;
  *((float *)this + 584) = 4.0;
  *((_DWORD *)this + 582) = 2;
  *((_DWORD *)this + 583) = 2;
  *((_DWORD *)this + 585) = 0;
  *((_DWORD *)this + 586) = 0;
  *((_DWORD *)this + 587) = 0;
  *((_DWORD *)this + 588) = 0;
  *((_BYTE *)this + 2356) = 0;
  *((float *)this + 590) = 1.0;
  *((float *)this + 591) = 0.0625;
  *((_DWORD *)this + 592) = 0;
  *((_DWORD *)this + 593) = 0;
  *((_DWORD *)this + 594) = 0;
  *((_DWORD *)this + 595) = 0;
  *((_DWORD *)this + 596) = 0;
  *((_DWORD *)this + 597) = 0;
  *((_DWORD *)this + 598) = 0;
  *((_DWORD *)this + 599) = 0;
  *((float *)this + 603) = 1.0;
  *((float *)this + 604) = 1.0;
  *((_DWORD *)this + 600) = 0;
  *((float *)this + 605) = 0.0;
  *((_DWORD *)this + 601) = 0x7FFFFFFF;
  *((float *)this + 606) = 0.0;
  *((_DWORD *)this + 602) = -2147483647;
  *((_BYTE *)this + 2428) = 0;
  *((float *)this + 608) = 1.0;
  *((float *)this + 609) = 0.0625;
  *((_DWORD *)this + 610) = 0;
  *((_DWORD *)this + 611) = 0;
  *((_DWORD *)this + 612) = 0;
  *((_DWORD *)this + 613) = 0;
  *((_DWORD *)this + 614) = 0;
  *((_DWORD *)this + 615) = 0;
  *((_DWORD *)this + 616) = 0;
  *((_DWORD *)this + 617) = 0;
  *((float *)this + 621) = 1.0;
  *((float *)this + 622) = 1.0;
  *((_DWORD *)this + 619) = 0x7FFFFFFF;
  *((_DWORD *)this + 618) = 0;
  *((float *)this + 623) = 0.0;
  *((_DWORD *)this + 620) = -2147483647;
  *((float *)this + 624) = 0.0;
  *((_BYTE *)this + 2500) = 0;
  *((float *)this + 627) = 0.30000001;
  *((_DWORD *)this + 626) = 512;
  *((float *)this + 628) = 0.055;
  *((float *)this + 629) = 0.0099999998;
  GMatrix2D::SetIdentity(this: (float *)this + 630);
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 106, spinCount: 0);
  v7 = tan(-*((float *)this + 627));
  v6 = v7;
  v8 = tan(0.0);
  v4 = 0;
  *((float *)this + 630) = 1.0;
  *((float *)this + 631) = v6;
  *((float *)this + 632) = 0.0;
  *((float *)this + 633) = v8;
  *((float *)this + 634) = 1.0;
  *((float *)this + 635) = 0.0;
  *((_DWORD *)this + 3) = this;
  *((_DWORD *)this + 8) = this;
  do
  {
    if ( v2 > dword_103301C4[v4] )
      ++v4;
    *((_BYTE *)this + v2++ + 2024) = v4;
  }
  while ( v2 < 0x100 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F6460
// Name: public: void GFxFontCacheManagerImpl::CleanUpFont(class GFxFontResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::CleanUpFont(_RTL_CRITICAL_SECTION *this, struct GFxFontResource *a2)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  _RTL_CRITICAL_SECTION_DEBUG *DebugInfo; // esi
  int Index; // eax
  GFxFontResource *v5; // esi
  _RTL_CRITICAL_SECTION *i; // ebx
  int RecursionCount; // esi
  unsigned int v8; // eax
  struct GFxFontResource **v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  int LockCount; // esi
  _RTL_CRITICAL_SECTION *v14; // edi
  char v15; // cl
  char v16; // dl
  __int16 v17; // ax
  GFxShapeBase *v18; // ecx
  int v19; // [esp+Ch] [ebp-14h] BYREF
  __int16 v20; // [esp+10h] [ebp-10h]
  char v21; // [esp+12h] [ebp-Eh]
  char v22; // [esp+13h] [ebp-Dh]
  char v23; // [esp+14h] [ebp-Ch]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+18h] [ebp-8h]
  _RTL_CRITICAL_SECTION *v25; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v25 = this;
  lpCriticalSection = this + 106;
  EnterCriticalSection(lpCriticalSection: this + 106);
  DebugInfo = v2[95].DebugInfo;
  if ( DebugInfo != nullptr )
  {
    Index = GHashSetBase<unsigned int,GFixedSizeHash<unsigned int>,GFixedSizeHash<unsigned int>,GAllocatorLH<unsigned int,2>,GHashsetCachedEntry<unsigned int,GFixedSizeHash<unsigned int>>>::findIndexCore<unsigned int>(
              this: (int *)&v2[95],
              &a2,
              a3: (int)DebugInfo->CriticalSection & ((unsigned int)a2 ^ ((unsigned int)a2 >> 6)));
    if ( Index >= 0
      && (_RTL_CRITICAL_SECTION_DEBUG *)((char *)DebugInfo + 12 * Index) != (_RTL_CRITICAL_SECTION_DEBUG *)-16 )
    {
      v5 = a2;
      GFxGlyphRasterCache::CleanUpFont(this: (GFxGlyphRasterCache *)&v2[3].LockCount, a2);
      GFxFontResource::RemoveDisposeHandler(this: v5, a2: (struct GFxFontResource::DisposeHandler *)&v2->RecursionCount);
      GHashSetBase<GThread *,GThreadList::ThreadHashOp,GThreadList::ThreadHashOp,GAllocatorGH<GThread *,2>,GHashsetCachedEntry<GThread *,GThreadList::ThreadHashOp>>::RemoveAlt<GThread *>(
        this: &v2[95].DebugInfo,
        &a2);
      for ( i = (_RTL_CRITICAL_SECTION *)v2[3].DebugInfo;
            i != (_RTL_CRITICAL_SECTION *)&v25[2].SpinCount;
            i = (_RTL_CRITICAL_SECTION *)i->LockCount )
      {
        RecursionCount = i->RecursionCount;
        if ( RecursionCount != 0 )
        {
          v8 = 0;
          if ( *(_DWORD *)(RecursionCount + 20) != 0 )
          {
            v9 = *(struct GFxFontResource ***)(RecursionCount + 16);
            while ( *v9 != a2 )
            {
              ++v8;
              v9 += 8;
              if ( v8 >= *(_DWORD *)(RecursionCount + 20) )
                goto LABEL_20;
            }
            v10 = *(_DWORD *)(RecursionCount + 28);
            if ( v10 != 0 )
              (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 112))(a1: v10, a2: RecursionCount + 28, a3: 3);
            *(_DWORD *)(RecursionCount + 28) = 0;
            *(_DWORD *)(RecursionCount + 32) = 0;
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(RecursionCount + 16));
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(RecursionCount + 4));
            if ( *(_DWORD *)RecursionCount != 0 )
            {
              v11 = 0;
              v12 = *(_DWORD *)(*(_DWORD *)RecursionCount + 4) + 1;
              do
              {
                if ( *(_DWORD *)(v11 + *(_DWORD *)RecursionCount + 8) != -2 )
                  *(_DWORD *)(v11 + *(_DWORD *)RecursionCount + 8) = -2;
                v11 += 36;
                --v12;
              }
              while ( v12 != 0 );
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)RecursionCount);
              *(_DWORD *)RecursionCount = 0;
            }
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)RecursionCount);
            i->RecursionCount = 0;
          }
        }
LABEL_20:
        ;
      }
      v2 = v25;
    }
  }
  LockCount = v2[96].LockCount;
  if ( (_RTL_CRITICAL_SECTION *)LockCount != &v2[96] )
  {
    do
    {
      v14 = *(_RTL_CRITICAL_SECTION **)(LockCount + 4);
      if ( *(struct GFxFontResource **)(LockCount + 8) == a2 )
      {
        v15 = *(_BYTE *)(LockCount + 14);
        v16 = *(_BYTE *)(LockCount + 15);
        v19 = *(_DWORD *)(LockCount + 8);
        v17 = *(_WORD *)(LockCount + 12);
        v21 = v15;
        v20 = v17;
        LOBYTE(v17) = *(_BYTE *)(LockCount + 16);
        v22 = v16 & 3;
        v23 = v17;
        GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::RemoveAlt<GFxFontCacheManagerImpl::VectorGlyphKey>(
          this: &v2[96].RecursionCount,
          a2: &v19);
        *(_DWORD *)(*(_DWORD *)LockCount + 4) = *(_DWORD *)(LockCount + 4);
        **(_DWORD **)(LockCount + 4) = *(_DWORD *)LockCount;
        v18 = *(GFxShapeBase **)(LockCount + 20);
        if ( v18 != nullptr )
          GFxShapeBase::Release(this: v18);
        *(_DWORD *)LockCount = v2[95].LockSemaphore;
        v2[95].LockSemaphore = (void *)LockCount;
      }
      LockCount = (int)v14;
    }
    while ( v14 != &v2[96] );
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100F6680
// Name: public: void GFxFontCacheManagerImpl::ReleaseBatchPackage(struct GFxBatchPackage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::ReleaseBatchPackage(_RTL_CRITICAL_SECTION *this, struct GFxBatchPackage *a2)
{
  _RTL_CRITICAL_SECTION *v3; // ebx
  GFxBatchPackageData *v4; // ecx

  v3 = this + 106;
  EnterCriticalSection(lpCriticalSection: this + 106);
  if ( a2 == nullptr )
  {
LABEL_9:
    LeaveCriticalSection(lpCriticalSection: v3);
    return;
  }
  v4 = *((GFxBatchPackageData **)a2 + 2);
  if ( *((_RTL_CRITICAL_SECTION **)a2 + 3) == this )
  {
    if ( v4 != nullptr )
      GFxBatchPackageData::`scalar deleting destructor'(this: v4, a2: 1u);
    *(_DWORD *)(*(_DWORD *)a2 + 4) = *((_DWORD *)a2 + 1);
    **((_DWORD **)a2 + 1) = *(_DWORD *)a2;
    *(_DWORD *)a2 = *((_DWORD *)this + 15);
    *((_DWORD *)this + 15) = a2;
    goto LABEL_9;
  }
  if ( v4 != nullptr )
    GFxBatchPackageData::`scalar deleting destructor'(this: v4, a2: 1u);
  *((_DWORD *)a2 + 2) = 0;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100F6700
// Name: GFx_ClipBitmapDesc
// Source: json
//------------------------------------------------------------------------------
char __fastcall GFx_ClipBitmapDesc(float *a1, float *a2)
{
  double v2; // st4
  double v3; // st7
  double v4; // st6
  double v5; // st4
  double v6; // st5
  double v7; // rt1
  double v8; // st4
  double v9; // st6
  double v10; // rt2
  double v11; // st4
  double v12; // st7
  double v14; // st3
  double v15; // st3
  double v16; // st2
  double v17; // st2
  float v18; // [esp+0h] [ebp-24h]
  float v19; // [esp+4h] [ebp-20h]
  float v20; // [esp+8h] [ebp-1Ch]
  float v21; // [esp+Ch] [ebp-18h]
  float v22; // [esp+10h] [ebp-14h]
  float v23; // [esp+10h] [ebp-14h]
  float v24; // [esp+14h] [ebp-10h]
  float v25; // [esp+14h] [ebp-10h]
  float v26; // [esp+18h] [ebp-Ch]
  float v27; // [esp+18h] [ebp-Ch]
  float v28; // [esp+1Ch] [ebp-8h]
  float v29; // [esp+1Ch] [ebp-8h]
  float v30; // [esp+20h] [ebp-4h]
  float v31; // [esp+20h] [ebp-4h]
  float v32; // [esp+20h] [ebp-4h]
  float v33; // [esp+20h] [ebp-4h]
  float v34; // [esp+20h] [ebp-4h]
  float v35; // [esp+20h] [ebp-4h]
  float v36; // [esp+20h] [ebp-4h]
  float v37; // [esp+20h] [ebp-4h]
  float v38; // [esp+20h] [ebp-4h]
  float v39; // [esp+20h] [ebp-4h]

  v22 = *a1;
  v24 = a1[1];
  v26 = a1[2];
  v28 = a1[3];
  v18 = *a2;
  v19 = a2[1];
  v20 = a2[2];
  v21 = a2[3];
  if ( v19 <= (double)v28 && v24 <= (double)v21 && (v2 = v22, v22 <= (double)v20) && v18 <= (double)v26 )
  {
    if ( v18 >= v2 )
      v2 = v18;
    if ( v26 <= (double)v20 )
      v6 = v26;
    else
      v6 = v20;
    v4 = v2;
    if ( v24 > (double)v19 )
      v3 = v24;
    else
      v3 = v19;
    v5 = v28;
    if ( v21 < (double)v28 )
      v5 = v21;
  }
  else
  {
    v30 = 0.0 + 0.0;
    v3 = (float)0.0;
    v4 = v3;
    v5 = v30;
    v6 = v30;
  }
  v7 = v5;
  v8 = v4;
  v9 = v7;
  if ( v8 < v6 && (v10 = v8, v11 = v3, v12 = v10, v11 < v9) )
  {
    if ( *a1 == v12 && a1[2] == v6 && a1[1] == v11 && a1[3] == v9 )
    {
      return 1;
    }
    else
    {
      v23 = a1[4];
      v25 = a1[5];
      v27 = a1[6];
      v29 = a1[7];
      if ( v12 != *a1 )
      {
        v32 = a1[6] - a1[4];
        v14 = v32 * (v12 - *a1);
        v33 = a1[2] - *a1;
        v23 = v14 / v33 + a1[4];
      }
      if ( v11 != a1[1] )
      {
        v34 = a1[7] - a1[5];
        v15 = v34 * (v11 - a1[1]);
        v35 = a1[3] - a1[1];
        v25 = v15 / v35 + a1[5];
      }
      if ( v6 != a1[2] )
      {
        v36 = a1[6] - a1[4];
        v16 = v36 * (a1[2] - v6);
        v37 = a1[2] - *a1;
        v27 = a1[6] - v16 / v37;
      }
      if ( v9 != a1[3] )
      {
        v38 = a1[7] - a1[5];
        v17 = v38 * (a1[3] - v9);
        v39 = a1[3] - a1[1];
        v29 = a1[7] - v17 / v39;
      }
      *a1 = v12;
      a1[1] = v11;
      a1[2] = v6;
      a1[3] = v9;
      a1[4] = v23;
      a1[5] = v25;
      a1[6] = v27;
      a1[7] = v29;
      return 1;
    }
  }
  else
  {
    v31 = a2[1];
    *a1 = *a2;
    a1[1] = v31;
    a1[2] = *a1;
    a1[3] = v31;
    a1[6] = a1[4];
    a1[7] = a1[5];
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F69E0
// Name: private: void GFxFontCacheManagerImpl::copyAndTransformShape(class GFxShapeNoStyles __near *,class GFxShapeBase const __near *,class GRect<float> __near *,bool,bool,float,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::copyAndTransformShape(
        GFxFontCacheManagerImpl *this,
        int a2,
        int a3,
        int a4,
        char a5,
        char a6,
        float a7,
        float a8,
        float a9)
{
  int v9; // esi
  float v10; // ebx
  double v11; // st7
  GFxShapeNoStyles *v12; // eax
  void (__thiscall *v13)(int, int, _DWORD); // eax
  char isOuterContourCW; // al
  double v15; // st7
  double v16; // st7
  float v17; // ecx
  _DWORD *v18; // esi
  float *v19; // edi
  unsigned int v20; // edi
  float *v21; // ebx
  GFxShapeNoStyles *v22; // eax
  int v23; // edx
  double v24; // st7
  float v25; // ecx
  _DWORD *v26; // esi
  float *v27; // edi
  unsigned int v28; // edi
  float *v29; // ebx
  GRefCountNTSImpl *v30; // edi
  double v31; // st7
  double v32; // st6
  long double *v33; // [esp+20h] [ebp-90h]
  int v34; // [esp+20h] [ebp-90h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v35; // [esp+2Ch] [ebp-84h] BYREF
  float v36; // [esp+38h] [ebp-78h]
  CSOAAttributeReference v37; // [esp+3Ch] [ebp-74h] BYREF
  void *v38; // [esp+58h] [ebp-58h]
  int v39; // [esp+64h] [ebp-4Ch]
  int v40; // [esp+74h] [ebp-3Ch] BYREF
  int v41; // [esp+78h] [ebp-38h]
  float v42; // [esp+7Ch] [ebp-34h]
  float v43; // [esp+80h] [ebp-30h]
  float v44; // [esp+84h] [ebp-2Ch]
  char v45; // [esp+88h] [ebp-28h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+8Ch] [ebp-24h] BYREF
  GFxFontCacheManagerImpl *v47; // [esp+98h] [ebp-18h]
  int v48; // [esp+9Ch] [ebp-14h] BYREF
  float v49; // [esp+A0h] [ebp-10h]
  GFxShapeBase *v50; // [esp+A4h] [ebp-Ch]
  int p; // [esp+A8h] [ebp-8h] BYREF
  unsigned int nNextElement; // [esp+ACh] [ebp-4h]

  v9 = a3;
  v10 = *(float *)&this;
  v47 = this;
  if ( *(float *)&a3 == 0.0 )
    return;
  GFxPathPacker::GFxPathPacker(this: (GFxPathPacker *)&v37);
  v11 = *(float *)(LODWORD(v10) + 2512) * 1024.0;
  v50 = nullptr;
  *(float *)&result.nNextElement = v11;
  if ( a5 != 0 )
  {
    a3 = 258;
    v12 = (GFxShapeNoStyles *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 68, &a3);
    if ( v12 != nullptr )
      *(float *)&a3 = COERCE_FLOAT(GFxShapeNoStyles::GFxShapeNoStyles(this: v12, pageSize: 968));
    else
      *(float *)&a3 = 0.0;
    v13 = *(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v9 + 24);
    v50 = (GFxShapeBase *)a3;
    v13(a1: v9, a2: LODWORD(v10) + 2360, a3: 10.0);
    GCompoundShape::ScaleAndTranslate(
      this: (GCompoundShape *)(LODWORD(v10) + 2360),
      a2: 1.0,
      a3: 1000.0,
      a4: 0.0,
      a5: 0.0);
    isOuterContourCW = GFxFontCacheManagerImpl::isOuterContourCW(
                         this: (GFxFontCacheManagerImpl *)LODWORD(v10),
                         a2: (const struct GCompoundShape *)(LODWORD(v10) + 2360));
    v15 = *(float *)&result.nNextElement;
    if ( isOuterContourCW == 0 )
      v15 = -v15;
    a9 = v15;
    a9 = a9 * 0.5;
    v16 = a9;
    *(float *)(LODWORD(v10) + 2316) = a9;
    if ( v16 < 0.0 )
      v16 = -v16;
    a9 = v16;
    *(float *)(LODWORD(v10) + 2320) = a9;
    *(_DWORD *)(LODWORD(v10) + 2324) = 0;
    GCompoundShape::Clear(this: (GCompoundShape *)(LODWORD(v10) + 2432));
    GStroker::generateEquidistant(
      this: (_FPIEEE_RECORD *)(LODWORD(v10) + 2316),
      srcShape: (unsigned int *)(LODWORD(v10) + 2360),
      srcStyle: -1,
      dstShape: LODWORD(v10) + 2432,
      bothSides: nullptr,
      j: v33);
    v17 = 0.0;
    a9 = 0.0;
    if ( *(_DWORD *)(LODWORD(v10) + 2456) != 0 )
    {
      do
      {
        v18 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v10) + 2468) + 4 * (LODWORD(v17) >> 6))
                       + 24 * (LOBYTE(v17) & 0x3F));
        if ( v18[1] > 2u )
        {
          v19 = (float *)(*(_DWORD *)(*(_DWORD *)(*v18 + 20) + 4 * (v18[2] >> 8)) + 8 * (unsigned __int8)v18[2]);
          GFxPathPacker::Reset(this: (GFxPathPacker *)&v37);
          v37.m_pContainer = (CSOAContainer *)1;
          v37.m_nAttributeID = 0;
          GFxPathPacker::SetMoveTo(
            this: (CStridedConstPtr<__m128> *)&v37,
            x: (int)*v19,
            y: (int)(v19[1] * 0.001000000047497451),
            numBits: 0);
          v20 = 1;
          if ( v18[1] > 1u )
          {
            do
            {
              v21 = (float *)(*(_DWORD *)(*(_DWORD *)(*v18 + 20) + 4 * ((v20 + v18[2]) >> 8))
                            + 8 * (unsigned __int8)(v20 + *((_BYTE *)v18 + 8)));
              GFxPathPacker::LineToAbs(this: &v37, x: COERCE_FLOAT((int)*v21), y: (int)(v21[1] * 0.001000000047497451));
              ++v20;
            }
            while ( v20 < v18[1] );
            v10 = *(float *)&v47;
          }
          if ( v39 != 0 )
            GFxPathPacker::Pack(
              this: (CStridedConstPtr<__m128> *)&v37,
              a2: (FloatCubeMap_t *)(a3 + 40),
              ppathsInfo: (CStridedConstPtr<__m128> *)(a3 + 52));
          v17 = a9;
        }
        ++LODWORD(v17);
        a9 = v17;
      }
      while ( LODWORD(v17) < *(_DWORD *)(LODWORD(v10) + 2456) );
    }
LABEL_35:
    v9 = a3;
    goto LABEL_36;
  }
  a9 = (float)LODWORD(a9);
  if ( a9 > 0.0 )
  {
    a3 = 258;
    v22 = (GFxShapeNoStyles *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 68, &a3);
    if ( v22 != nullptr )
      *(float *)&a3 = COERCE_FLOAT(GFxShapeNoStyles::GFxShapeNoStyles(this: v22, pageSize: 968));
    else
      *(float *)&a3 = 0.0;
    v23 = *(_DWORD *)v9;
    v50 = (GFxShapeBase *)a3;
    (*(void (__thiscall **)(int, int, _DWORD))(v23 + 24))(a1: v9, a2: LODWORD(v10) + 2360, a3: 10.0);
    a9 = *(float *)(LODWORD(v10) + 2516) * a9 * 1024.0;
    a9 = a9 * 0.5;
    v24 = a9;
    *(float *)(LODWORD(v10) + 2316) = a9;
    if ( v24 < 0.0 )
      v24 = -v24;
    a9 = v24;
    *(float *)(LODWORD(v10) + 2320) = a9;
    *(_DWORD *)(LODWORD(v10) + 2324) = 0;
    GCompoundShape::Clear(this: (GCompoundShape *)(LODWORD(v10) + 2432));
    GStroker::generateEquidistant(
      this: (_FPIEEE_RECORD *)(LODWORD(v10) + 2316),
      srcShape: (unsigned int *)(LODWORD(v10) + 2360),
      srcStyle: -1,
      dstShape: LODWORD(v10) + 2432,
      bothSides: (long double *)1,
      j: v33);
    v25 = 0.0;
    a9 = 0.0;
    if ( *(_DWORD *)(LODWORD(v10) + 2456) != 0 )
    {
      do
      {
        v26 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v10) + 2468) + 4 * (LODWORD(v25) >> 6))
                       + 24 * (LOBYTE(v25) & 0x3F));
        if ( v26[1] > 2u )
        {
          v27 = (float *)(*(_DWORD *)(*(_DWORD *)(*v26 + 20) + 4 * (v26[2] >> 8)) + 8 * (unsigned __int8)v26[2]);
          GFxPathPacker::Reset(this: (GFxPathPacker *)&v37);
          v37.m_pContainer = (CSOAContainer *)1;
          v37.m_nAttributeID = 0;
          GFxPathPacker::SetMoveTo(this: (CStridedConstPtr<__m128> *)&v37, x: (int)*v27, y: (int)v27[1], numBits: 0);
          v28 = 1;
          if ( v26[1] > 1u )
          {
            do
            {
              v29 = (float *)(*(_DWORD *)(*(_DWORD *)(*v26 + 20) + 4 * ((v28 + v26[2]) >> 8))
                            + 8 * (unsigned __int8)(v28 + *((_BYTE *)v26 + 8)));
              GFxPathPacker::LineToAbs(this: &v37, x: COERCE_FLOAT((int)*v29), y: (int)v29[1]);
              ++v28;
            }
            while ( v28 < v26[1] );
            v10 = *(float *)&v47;
          }
          if ( v39 != 0 )
            GFxPathPacker::Pack(
              this: (CStridedConstPtr<__m128> *)&v37,
              a2: (FloatCubeMap_t *)(a3 + 40),
              ppathsInfo: (CStridedConstPtr<__m128> *)(a3 + 52));
          v25 = a9;
        }
        ++LODWORD(v25);
        a9 = v25;
      }
      while ( LODWORD(v25) < *(_DWORD *)(LODWORD(v10) + 2456) );
    }
    goto LABEL_35;
  }
LABEL_36:
  v30 = (GRefCountNTSImpl *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 72))(a1: v9);
  while ( ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *, int *))v30->__vftable[1].dtr_GRefCountImplCore)(
            a1: v30,
            a2: &v40) != 0 )
  {
    v31 = a8;
    v32 = a7;
    switch ( v40 )
    {
      case 0:
        a3 = v41;
        a9 = v42;
        GFxPathPacker::Reset(this: (GFxPathPacker *)&v37);
        v37.m_pContainer = (CSOAContainer *)1;
        v37.m_nAttributeID = 0;
        *(float *)&p = *(float *)&a3 + a7;
        *(float *)&nNextElement = a9 + a8;
        if ( a6 != 0 )
        {
          GMatrix2D::Transform(
            this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(LODWORD(v10) + 2520),
            result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&result.nReferenceCount,
            (float *)&p,
            p_4: (int)v33);
          p = *(int *)&result.nReferenceCount;
          nNextElement = (unsigned int)v47;
        }
        GFxPathPacker::SetMoveTo(
          this: (CStridedConstPtr<__m128> *)&v37,
          x: (int)*(float *)&p,
          y: (int)*(float *)&nNextElement,
          numBits: 0);
        break;
      case 1:
      case 2:
        if ( v39 != 0 )
          GFxPathPacker::Pack(
            this: (CStridedConstPtr<__m128> *)&v37,
            a2: (FloatCubeMap_t *)(a2 + 40),
            ppathsInfo: (CStridedConstPtr<__m128> *)(a2 + 52));
        break;
      case 3:
        if ( v45 != 0 )
        {
          *(float *)&p = *(float *)&v41 + v32;
          *(float *)&nNextElement = v42 + v31;
          *(float *)&v48 = v32 + v43;
          v49 = v31 + v44;
          if ( a6 != 0 )
          {
            GMatrix2D::Transform(
              this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(LODWORD(v10) + 2520),
              &result,
              (float *)&p,
              p_4: (int)v33);
            p = (int)result.pString;
            nNextElement = result.nNextElement;
            GMatrix2D::Transform(
              this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(LODWORD(v10) + 2520),
              result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v35.nReferenceCount,
              p: (float *)&v48,
              p_4: v34);
            v48 = *(int *)&v35.nReferenceCount;
            v49 = v36;
          }
          GFxPathPacker::CurveToAbs(
            this: (GFxPathPacker *)&v37,
            a2: (int)*(float *)&p,
            a3: (int)*(float *)&nNextElement,
            a4: (int)*(float *)&v48,
            a5: (int)v49);
        }
        else
        {
          *(float *)&p = v32 + v43;
          *(float *)&nNextElement = v31 + v44;
          if ( a6 != 0 )
          {
            GMatrix2D::Transform(
              this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(LODWORD(v10) + 2520),
              result: &v35,
              (float *)&p,
              p_4: (int)v33);
            p = (int)v35.pString;
            nNextElement = v35.nNextElement;
          }
          GFxPathPacker::LineToAbs(this: &v37, x: COERCE_FLOAT((int)*(float *)&p), y: (int)*(float *)&nNextElement);
        }
        break;
      default:
        break;
    }
  }
  if ( a5 != 0 || a6 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 20))(a1: a2, a2: a4);
  GRefCountNTSImpl::Release(this: v30);
  if ( v50 != nullptr )
    GFxShapeBase::Release(this: v50);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v38);
}

//------------------------------------------------------------------------------
// Address: 0x100F7310
// Name: public: virtual void GFxFontCacheManagerImpl::FontDisposeHandler::OnDispose(class GFxFontResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::FontDisposeHandler::OnDispose(
        _RTL_CRITICAL_SECTION **this,
        struct GFxFontResource *a2)
{
  GFxFontCacheManagerImpl::CleanUpFont(this: *(this + 1), a2);
}

//------------------------------------------------------------------------------
// Address: 0x100F7320
// Name: private: void GFxFontCacheManager::InitManager(struct GFxFontCacheManager::TextureConfig const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector2D *__thiscall GFxFontCacheManager::InitManager(Vector *this, unsigned int *a2, int debugHeap)
{
  struct GMemoryHeap *v4; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GFxFontCacheManagerImpl *v6; // eax
  GFxFontCacheManagerImpl *v7; // eax
  _DWORD v9[8]; // [esp+8h] [ebp-20h] BYREF

  v9[0] = (unsigned __int8)debugHeap != 0 ? 0x1000 : 0;
  v9[2] = 0x2000;
  v9[3] = 0x2000;
  v9[1] = 16;
  v9[4] = -1;
  v9[5] = 0;
  v9[7] = 0;
  v9[6] = 6;
  v4 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2: "_Font_Cache", a3: v9);
  Alloc_2 = v4->Alloc_2;
  debugHeap = 193;
  v6 = (GFxFontCacheManagerImpl *)Alloc_2(this: v4, a2: 2568u, a3: (const GAllocDebugInfo *)&debugHeap);
  if ( v6 != nullptr )
    v7 = GFxFontCacheManagerImpl::GFxFontCacheManagerImpl(this: v6, a2: v4);
  else
    v7 = nullptr;
  *((_DWORD *)this + 18) = v7;
  GMemoryHeap::ReleaseOnFree(this: v4, ptr: v7);
  return (Vector2D *)GFxFontCacheManager::SetTextureConfig((int)this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100F73D0
// Name: public: void GFxFontCacheManagerImpl::InvalidateAll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxFontCacheManagerImpl::InvalidateAll(GFxFontCacheManagerImpl *this@<ecx>, void **a2@<esi>)
{
  GFxFontCacheManagerImpl *v2; // edi
  _DWORD *v3; // ebx
  void **v4; // esi
  void *v5; // ecx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx

  v2 = this;
  v3 = *((_DWORD **)this + 18);
  if ( v3 != (_DWORD *)((char *)this + 68) )
  {
    do
    {
      v4 = (void **)v3[2];
      if ( v4 != nullptr )
      {
        v5 = v4[7];
        if ( v5 != nullptr )
          (*(void (__thiscall **)(void *, void **, int))(*(_DWORD *)v5 + 112))(a1: v5, a2: v4 + 7, a3: 3);
        v4[7] = nullptr;
        v4[8] = nullptr;
        ((void (__thiscall *)(GMemoryHeap *, void *, void **))GMemory::pGlobalHeap->Free)(
          a1: GMemory::pGlobalHeap,
          a2: v4[4],
          a3: a2);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4[1]);
        if ( *v4 != nullptr )
        {
          v6 = 0;
          v7 = *((_DWORD *)*v4 + 1) + 1;
          do
          {
            if ( *(_DWORD *)((char *)*v4 + v6 + 8) != -2 )
              *(_DWORD *)((char *)*v4 + v6 + 8) = -2;
            v6 += 36;
            --v7;
          }
          while ( v7 != 0 );
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v4);
          *v4 = nullptr;
        }
        a2 = v4;
        ((void (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap);
        v2 = this;
      }
      v3[2] = 0;
      v3 = (_DWORD *)v3[1];
    }
    while ( v3 != (_DWORD *)((char *)v2 + 68) );
  }
  GFxGlyphRasterCache::Clear(this: (GFxFontCacheManagerImpl *)((char *)v2 + 76));
  v8 = *((_DWORD *)v2 + 1);
  if ( v8 != 0 && *((_BYTE *)v2 + 36) != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 196))(a1: v8, a2: (int)v2 + 16);
    *((_DWORD *)v2 + 1) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F74E0
// Name: public: bool GFxFontCacheManagerImpl::VerifyBatchPackage(struct GFxBatchPackage const __near *,class GFxDisplayContext __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFontCacheManagerImpl::VerifyBatchPackage(
        GFxFontCacheManagerImpl *this,
        GFxFontCacheManagerImpl **a2,
        struct GFxDisplayContext *a3,
        float a4)
{
  void **v5; // eax
  void **v6; // esi
  int v7; // ecx
  GFxFontCacheManagerImpl *v8; // edi
  int v9; // esi
  int v10; // edi
  GFxFontCacheManagerImpl *v12; // [esp+Ch] [ebp-28h]
  unsigned int v13; // [esp+10h] [ebp-24h]
  int v14; // [esp+14h] [ebp-20h]
  int v15; // [esp+20h] [ebp-14h] BYREF
  unsigned int v16[2]; // [esp+28h] [ebp-Ch]

  v5 = *((void ***)this + 1);
  v6 = *(void ***)(*((_DWORD *)a3 + 18) + 12);
  if ( v5 != v6 )
  {
    if ( v5 != nullptr )
      GFxFontCacheManagerImpl::InvalidateAll(this, a2: v6);
    *((_DWORD *)this + 1) = v6;
    *((_BYTE *)this + 36) = 0;
    (*((void (__thiscall **)(void **, int *))*v6 + 1))(a1: v6, a2: &v15);
    if ( (v15 & 0x60000) != 0 )
    {
      v7 = *((_DWORD *)this + 1);
      *((_BYTE *)this + 36) = 1;
      (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 192))(a1: v7, a2: (char *)this + 16);
    }
  }
  if ( a2 == nullptr )
    return 0;
  if ( a2[3] != this )
    return 0;
  v8 = a2[2];
  v12 = v8;
  if ( v8 == nullptr || *((_BYTE *)v8 + 77) != 0 )
    return 0;
  v13 = 0;
  if ( *((_DWORD *)v8 + 5) != 0 )
  {
    v14 = 0;
    do
    {
      v9 = v14 + *((_DWORD *)v8 + 4);
      if ( 0.0 != a4 && *(_DWORD *)(v9 + 12) != 0 )
      {
        v10 = *(unsigned __int8 *)(v9 + 6);
        if ( *(_BYTE *)(v9 + 6) != 0 )
        {
          *(_QWORD *)v16 = (__int64)((double)*(unsigned __int16 *)(v9 + 16) * a4 + 0.5);
          if ( GFxFontCacheManagerImpl::snapFontSizeToRamp(this, a2: v16[0]) != v10 )
            return 0;
        }
        v8 = v12;
      }
      if ( *(_DWORD *)(v9 + 12) != 0
        && GFxGlyphRasterCache::VerifyGlyphAndSendBack(
             this: (GFxFontCacheManagerImpl *)((char *)this + 76),
             a2: (const struct GFxGlyphParam *)v9,
             a3: *(struct GFxGlyphNode **)(v9 + 12)) == 0 )
      {
        return 0;
      }
      if ( *((_BYTE *)this + 36) != 0 )
        *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v9 + 12) + 12) + 32) |= 0x8000u;
      v14 += 32;
      ++v13;
    }
    while ( v13 < *((_DWORD *)v8 + 5) );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7660
// Name: public: void GFxBatchPackageData::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxBatchPackageData::Clear(GFxBatchPackageData *this)
{
  int v2; // ecx
  void **v3; // esi
  void **v4; // esi

  v2 = *((_DWORD *)this + 7);
  if ( v2 != 0 )
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v2 + 112))(a1: v2, a2: (char *)this + 28, a3: 3);
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  GHashSetBase<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeAltHashF,GAllocatorLH<GFxBatchPackageData::BatchInfoKey,194>,GHashsetCachedNodeEntry<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF>>::Clear((int *)this);
  v3 = (void **)((char *)this + 4);
  if ( *((_DWORD *)this + 2) != 0 )
  {
    if ( (*((_DWORD *)this + 3) & 0xFFFFFFFE) != 0 )
    {
      if ( *v3 != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
        *v3 = nullptr;
      }
      *((_DWORD *)this + 3) = 0;
    }
  }
  else if ( *((_DWORD *)this + 3) == 0 )
  {
    GArrayDataBase<GRenderer::BitmapDesc,GAllocatorLH<GRenderer::BitmapDesc,194>,GArrayDefaultPolicy>::Reserve(
      this: (void **)this + 1,
      a2: (char *)this + 4,
      a3: 0);
  }
  *((_DWORD *)this + 2) = 0;
  v4 = (void **)((char *)this + 16);
  if ( *((_DWORD *)this + 5) == 0 )
  {
    if ( *((_DWORD *)this + 6) == 0 )
      GArrayDataBase<GFxBatchPackageData::GlyphVerifier,GAllocatorLH<GFxBatchPackageData::GlyphVerifier,194>,GArrayDefaultPolicy>::Reserve(
        this: (void **)this + 4,
        a2: (char *)this + 16,
        a3: 0);
    goto LABEL_17;
  }
  if ( (*((_DWORD *)this + 6) & 0xFFFFFFFE) == 0 )
  {
LABEL_17:
    *((_DWORD *)this + 5) = 0;
    *((_WORD *)this + 38) = 0;
    return;
  }
  if ( *v4 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v4);
    *v4 = nullptr;
  }
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_WORD *)this + 38) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F7720
// Name: public: GFxFontCacheManager::GFxFontCacheManager(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManager::GFxFontCacheManager(
        IMaterial *this,
        const IMaterial *enableDynamicCache,
        int debugHeap)
{
  unsigned int v3[7]; // [esp+4h] [ebp-1Ch] BYREF

  this->__vftable = (IMaterial_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 2) = 18;
  this->__vftable = (IMaterial_vtbl *)&GFxFontCacheManager::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 5) = 1;
  *((_DWORD *)this + 6) = 48;
  *((_DWORD *)this + 7) = 2;
  *((_DWORD *)this + 8) = 256;
  *((_DWORD *)this + 9) = 512;
  *((_DWORD *)this + 3) = 1024;
  *((_DWORD *)this + 4) = 1024;
  *((float *)this + 11) = 1.0;
  v3[0] = 1024;
  *((float *)this + 14) = 0.28;
  v3[1] = 1024;
  *((_DWORD *)this + 17) = 1;
  *((float *)this + 15) = 0.055;
  v3[2] = 1;
  *((float *)this + 16) = 0.0099999998;
  *((_WORD *)this + 20) = (unsigned __int8)enableDynamicCache;
  *((_DWORD *)this + 13) = 512;
  *((_DWORD *)this + 18) = 0;
  v3[3] = 48;
  v3[4] = 2;
  v3[5] = 256;
  v3[6] = 512;
  GFxFontCacheManager::InitManager((Vector *)this, a2: v3, debugHeap);
}

//------------------------------------------------------------------------------
// Address: 0x100F77F0
// Name: public: void GFxFontCacheManagerImpl::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxFontCacheManagerImpl::Clear(GFxFontCacheManagerImpl *this@<ecx>, void **a2@<esi>)
{
  int v3; // eax
  char *v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // ecx
  _DWORD *v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  bool v15; // zf
  _DWORD *v16; // eax
  _DWORD *v17; // esi
  _DWORD *v18; // ebx
  GFxShapeBase *v19; // ecx
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // esi
  int v23; // ecx
  int v24; // eax
  int v25; // edx
  int v26; // eax
  _DWORD *v27; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]
  _DWORD *v29; // [esp+10h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 2544);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 106);
  GFxFontCacheManagerImpl::InvalidateAll(this, a2);
  *((_DWORD *)this + 17) = (char *)this + 68;
  *((_DWORD *)this + 18) = (char *)this + 68;
  GListAllocBase<GFxBatchPackage,127,GAllocatorLH_POD<GFxBatchPackage,194>>::ClearAndRelease(this: (_DWORD *)this + 12);
  v3 = *((_DWORD *)this + 570);
  if ( v3 != 0 )
  {
    v6 = *(_DWORD *)(v3 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v3 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 3;
    }
    while ( v5 <= v6 );
    v4 = (char *)this + 2280;
  }
  else
  {
    v4 = nullptr;
    v5 = 0;
  }
  while ( v4 != nullptr )
  {
    v8 = *(_DWORD *)v4;
    if ( *(_DWORD *)v4 == 0 || (signed int)v5 > *(_DWORD *)(v8 + 4) )
      break;
    GFxFontResource::RemoveDisposeHandler(
      this: *(GFxFontResource **)(v8 + 12 * v5 + 16),
      a2: (GFxFontCacheManagerImpl *)((char *)this + 8));
    v9 = *(_DWORD *)(*(_DWORD *)v4 + 4);
    if ( (int)v5 <= (int)v9 && ++v5 <= v9 )
    {
      v10 = (_DWORD *)(*(_DWORD *)v4 + 12 * v5 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v5;
        v10 += 3;
      }
      while ( v5 <= v9 );
    }
  }
  v11 = *((_DWORD *)this + 570);
  if ( v11 != 0 )
  {
    v12 = 0;
    v13 = *(_DWORD *)(v11 + 4) + 1;
    do
    {
      v14 = *((_DWORD *)this + 570);
      v15 = *(_DWORD *)(v12 + v14 + 8) == -2;
      v16 = (_DWORD *)(v12 + v14 + 8);
      if ( !v15 )
        *v16 = -2;
      v12 += 12;
      --v13;
    }
    while ( v13 != 0 );
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 570));
    *((_DWORD *)this + 570) = 0;
  }
  v17 = *((_DWORD **)this + 577);
  v18 = (_DWORD *)((char *)this + 2304);
  if ( v17 != (_DWORD *)((char *)this + 2304) )
  {
    do
    {
      v19 = (GFxShapeBase *)v17[5];
      v20 = (_DWORD *)v17[1];
      v29 = v20;
      if ( v19 != nullptr )
      {
        GFxShapeBase::Release(this: v19);
        v20 = v29;
      }
      *v17 = *((_DWORD *)this + 574);
      *((_DWORD *)this + 574) = v17;
      v17 = v20;
    }
    while ( v20 != v18 );
  }
  *v18 = v18;
  *((_DWORD *)this + 577) = (char *)this + 2304;
  v21 = *((_DWORD **)this + 571);
  if ( v21 != nullptr )
  {
    do
    {
      v22 = (_DWORD *)v21[762];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
      v21 = v22;
    }
    while ( v22 != nullptr );
  }
  v23 = 0;
  *((_DWORD *)this + 571) = 0;
  *((_DWORD *)this + 572) = 0;
  *((_DWORD *)this + 573) = 127;
  *((_DWORD *)this + 574) = 0;
  v24 = *((_DWORD *)this + 578);
  if ( v24 != 0 )
  {
    v25 = *(_DWORD *)(v24 + 4) + 1;
    do
    {
      v26 = *((_DWORD *)this + 578);
      v15 = *(_DWORD *)(v23 + v26 + 8) == -2;
      v27 = (_DWORD *)(v23 + v26 + 8);
      if ( !v15 )
        *v27 = -2;
      v23 += 24;
      --v25;
    }
    while ( v25 != 0 );
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 578));
    *((_DWORD *)this + 578) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x100F79E0
// Name: public: GFxFontCacheManagerImpl::~GFxFontCacheManagerImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontCacheManagerImpl::~GFxFontCacheManagerImpl(GFxFontCacheManagerImpl *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // edi

  GFxFontCacheManagerImpl::Clear(this, a2: (void **)this);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 106);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 614);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 610);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 596);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 592);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 585);
  GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::~GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>(this: (int *)this + 578);
  v2 = *((_DWORD **)this + 571);
  if ( v2 != nullptr )
  {
    do
    {
      v3 = (_DWORD *)v2[762];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
      v2 = v3;
    }
    while ( v3 != nullptr );
  }
  GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(this: (CInternalFileSystemPassThru<IBaseFileSystem> *)this + 285);
  GFxGlyphRasterCache::~GFxGlyphRasterCache(this: (GFxFontCacheManagerImpl *)((char *)this + 76));
  v4 = *((_DWORD **)this + 12);
  if ( v4 != nullptr )
  {
    do
    {
      v5 = (_DWORD *)v4[508];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
  *((_DWORD *)this + 2) = &GString::InitStruct::`vftable';
  *((_DWORD *)this + 4) = &GRendererEventHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100F7AB0
// Name: public: class GFxShapeBase __near * GFxFontCacheManagerImpl::GetGlyphShape_NoLock(class GFxFontResource __near *,unsigned int,unsigned int,bool,bool,float,float,unsigned int,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxShapeBase *__thiscall GFxFontCacheManagerImpl::GetGlyphShape_NoLock(
        GFxFontCacheManagerImpl *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10)
{
  int v11; // ecx
  unsigned int v12; // edi
  int Index; // eax
  __int16 *v14; // ecx
  GFxShapeBase *v15; // edx
  int v16; // ebx
  int v17; // eax
  char *v18; // eax
  char *v19; // edx
  int v20; // eax
  GFxShapeBase *v22; // ecx
  _DWORD *v23; // eax
  int v24; // edx
  char v25; // al
  char v26; // cl
  char v27; // dl
  unsigned int v28; // edx
  _DWORD **v29; // ecx
  struct GFxLog *v30; // eax
  GFxShapeBase *v31; // ecx
  char v32; // dl
  int v33; // ecx
  int (__thiscall *v34)(int, int, float *); // eax
  GFxShapeNoStyles *v35; // eax
  unsigned int *v36; // ebx
  GFxShapeBase *v37; // ecx
  GFxShapeBase *v38; // ebx
  float *v39; // eax
  unsigned int *v40; // ecx
  unsigned __int8 v41; // dl
  unsigned int v42; // esi
  int v43; // [esp+2Ch] [ebp-40h]
  int v44; // [esp+38h] [ebp-34h] BYREF
  float v45; // [esp+3Ch] [ebp-30h]
  float v46; // [esp+40h] [ebp-2Ch]
  float v47; // [esp+44h] [ebp-28h]
  unsigned int v48; // [esp+48h] [ebp-24h] BYREF
  __int16 v49; // [esp+4Ch] [ebp-20h]
  unsigned __int8 v50; // [esp+4Eh] [ebp-1Eh]
  char v51; // [esp+4Fh] [ebp-1Dh]
  char v52; // [esp+50h] [ebp-1Ch]
  unsigned int v53; // [esp+54h] [ebp-18h] BYREF
  unsigned int *v54; // [esp+58h] [ebp-14h] BYREF
  unsigned int **v55; // [esp+5Ch] [ebp-10h]
  GFxShapeBase *v56; // [esp+60h] [ebp-Ch]
  unsigned int v57; // [esp+64h] [ebp-8h]
  unsigned int *v58; // [esp+68h] [ebp-4h] BYREF

  v11 = *((_DWORD *)this + 570);
  v12 = a2;
  if ( v11 == 0
    || (v57 = a2 >> 6,
        (Index = GHashSetBase<unsigned int,GFixedSizeHash<unsigned int>,GFixedSizeHash<unsigned int>,GAllocatorLH<unsigned int,2>,GHashsetCachedEntry<unsigned int,GFixedSizeHash<unsigned int>>>::findIndexCore<unsigned int>(
                   this: (int *)this + 570,
                   &a2,
                   a3: *(_DWORD *)(v11 + 4) & (a2 ^ (a2 >> 6)))) < 0)
    || *((_DWORD *)this + 570) + 12 * Index == -16 )
  {
    v57 = v12 >> 6;
    GHashSetBase<GFxFontResource *,GFxFontHashOp,GFxFontHashOp,GAllocatorLH<GFxFontResource *,196>,GHashsetCachedEntry<GFxFontResource *,GFxFontHashOp>>::add<GFxFontResource *>(
      this: (int *)this + 570,
      a2: (int)this + 2280,
      a3: &a2,
      a4: v12 ^ (v12 >> 6));
    GFxFontResource::AddDisposeHandler(this: (GFxFontResource *)v12, a2: (GFxFontCacheManagerImpl *)((char *)this + 8));
  }
  v14 = *(__int16 **)(v12 + 12);
  if ( (*((_DWORD *)v14 + 5) & 0x20) == 0
    || (*(unsigned __int8 (__thiscall **)(__int16 *, unsigned int, unsigned int))(*(_DWORD *)v14 + 16))(
         a1: v14,
         a2: a3,
         a3: a4) == 0 )
  {
    a4 = 0;
  }
  BYTE2(v54) = a4;
  LOWORD(v54) = a3;
  v15 = *((GFxShapeBase **)this + 578);
  v53 = v12;
  v56 = v15;
  v16 = (LOBYTE(a6) != 0) | (LOBYTE(a5) != 0 ? 2 : 0);
  LOBYTE(v55) = LOBYTE(a9);
  HIBYTE(a2) = (LOBYTE(a6) != 0) | (LOBYTE(a5) != 0 ? 2 : 0);
  HIBYTE(v54) = HIBYTE(a2);
  if ( v15 != nullptr )
  {
    v17 = GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::findIndexCore<GFxFontCacheManagerImpl::VectorGlyphKey>(
            this: (int *)this + 578,
            a2: (int)&v53,
            a3: *((_DWORD *)v56 + 1)
          & (v12
           ^ v57
           ^ LOBYTE(a9)
           ^ (unsigned __int16)a3
           ^ (unsigned __int8)a4
           ^ ((LOBYTE(a6) != 0) | (LOBYTE(a5) != 0 ? 2 : 0))));
    if ( v17 >= 0 )
    {
      v18 = (char *)v56 + 24 * v17 + 16;
      if ( v18 != nullptr )
      {
        v19 = v18 + 12;
        v56 = (GFxShapeBase *)(v18 + 12);
        if ( v18 != (char *)-12 )
        {
          v20 = *(_DWORD *)v19;
          *(_DWORD *)(**(_DWORD **)v19 + 4) = *(_DWORD *)(*(_DWORD *)v19 + 4);
          **(_DWORD **)(v20 + 4) = *(_DWORD *)v20;
          *(_DWORD *)v20 = *((_DWORD *)this + 576);
          *(_DWORD *)(v20 + 4) = (char *)this + 2304;
          *(_DWORD *)(*((_DWORD *)this + 576) + 4) = v20;
          *((_DWORD *)this + 576) = v20;
          if ( *((_BYTE *)this + 36) != 0 )
            *(_BYTE *)(*(_DWORD *)v19 + 15) |= 0x80u;
          GFxShapeBase::AddRef(this: *(GFxShapeBase **)(*(_DWORD *)v19 + 20));
          return *(struct GFxShapeBase **)(*(_DWORD *)v56 + 20);
        }
      }
    }
  }
  v22 = (GFxShapeBase *)(*(int (__thiscall **)(__int16 *, unsigned int, unsigned int))(**(_DWORD **)(v12 + 12) + 24))(
                          a1: *(__int16 **)(v12 + 12),
                          a2: a3,
                          a3: a4);
  v56 = v22;
  if ( v22 == nullptr )
    return nullptr;
  v23 = *((_DWORD **)this + 578);
  if ( v23 != nullptr )
    v23 = (_DWORD *)*v23;
  if ( (unsigned int)v23 >= *((_DWORD *)this + 626) )
  {
    v24 = *((_DWORD *)this + 577);
    v58 = (unsigned int *)v24;
    v25 = *(_BYTE *)(v24 + 15);
    if ( v25 < 0 )
    {
      if ( a10 != 0.0 && *((_BYTE *)this + 38) != 0 )
      {
        GFxLogBase<GFxLog>::LogWarning(
          this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v22,
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(LODWORD(a10) + 12),
          this_4: (int)"Warning: Increase vector glyph cache capacity - SetMaxVectorCacheSize().\n",
          this_8: v43);
        v22 = v56;
      }
      *((_BYTE *)this + 38) = 0;
      GFxShapeBase::Release(this: v22);
      return nullptr;
    }
    v53 = *(_DWORD *)(v24 + 8);
    LOWORD(v54) = *(_WORD *)(v24 + 12);
    v26 = *(_BYTE *)(v24 + 14);
    v27 = *(_BYTE *)(v24 + 16);
    HIBYTE(v54) = v25 & 3;
    BYTE2(v54) = v26;
    LOBYTE(v55) = v27;
    GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::RemoveAlt<GFxFontCacheManagerImpl::VectorGlyphKey>(
      this: (_DWORD *)this + 578,
      a2: (int *)&v53);
    v28 = *v58;
    v29 = (_DWORD **)(v58 + 1);
    a10 = *(float *)&v58;
    *(_DWORD *)(v28 + 4) = v58[1];
    **v29 = *(_DWORD *)LODWORD(a10);
    v30 = (struct GFxLog *)v58;
    v31 = (GFxShapeBase *)v58[5];
    a10 = *(float *)&v58;
    if ( v31 != nullptr )
    {
      GFxShapeBase::Release(this: v31);
      v30 = (struct GFxLog *)LODWORD(a10);
    }
    v30->GFxState::GRefCountBase<GFxState,2>::GRefCountBaseStatImpl<GRefCountImpl,2>::GRefCountImpl::GRefCountImplCore::__vftable = *((GFxLog_vtbl **)this + 574);
    *((_DWORD *)this + 574) = v30;
  }
  *(float *)&v58 = COERCE_FLOAT(GListAllocBase<GFxFontCacheManagerImpl::VectorGlyphShape,127,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphShape,196>>::Alloc(this: (unsigned int *)this + 571));
  v58[2] = v12;
  *((_WORD *)v58 + 6) = a3;
  *((_BYTE *)v58 + 14) = a4;
  v32 = LOBYTE(a9);
  *((_BYTE *)v58 + 15) = v16;
  *((_BYTE *)v58 + 16) = v32;
  v33 = *(_DWORD *)this;
  v34 = *(int (__thiscall **)(int, int, float *))(**(_DWORD **)this + 40);
  LODWORD(a10) = 258;
  v35 = (GFxShapeNoStyles *)v34(a1: v33, a2: 68, a3: &a10);
  if ( v35 != nullptr )
    a10 = COERCE_FLOAT(GFxShapeNoStyles::GFxShapeNoStyles(this: v35, pageSize: 242));
  else
    a10 = 0.0;
  v36 = v58;
  v37 = (GFxShapeBase *)v58[5];
  if ( v37 != nullptr )
    GFxShapeBase::Release(this: v37);
  *((float *)v36 + 5) = a10;
  *(float *)&v44 = 0.0;
  v38 = v56;
  v45 = 0.0;
  v46 = 0.0;
  v47 = 0.0;
  if ( *((_BYTE *)v56 + 37) != 0 )
    (*(void (__thiscall **)(GFxShapeBase *, int *))(*(_DWORD *)v56 + 20))(a1: v56, a2: &v44);
  else
    (*(void (__thiscall **)(__int16 *, unsigned int, int *))(**(_DWORD **)(v12 + 12) + 48))(
      a1: *(__int16 **)(v12 + 12),
      a2: a3,
      a3: &v44);
  GFxFontCacheManagerImpl::copyAndTransformShape(
    this,
    a2: v58[5],
    a3: (int)v38,
    a4: (int)&v44,
    a5: SLOBYTE(a5),
    a6: SLOBYTE(a6),
    a7,
    a8,
    a9);
  a6 = v45;
  v39 = (float *)v58[5];
  a5 = v46;
  v48 = v12;
  a10 = v47;
  v39[1] = *(float *)&v44;
  v39[2] = a6;
  v39[3] = a5;
  v39[4] = a10;
  *(_BYTE *)(v58[5] + 36) |= 0x10u;
  *(_BYTE *)(v58[5] + 36) |= 8u;
  *(_BYTE *)(v58[5] + 37) = *((_BYTE *)v38 + 37);
  v40 = v58;
  *v58 = *((_DWORD *)this + 576);
  v40[1] = (unsigned int)this + 2304;
  *(_DWORD *)(*((_DWORD *)this + 576) + 4) = v40;
  v41 = a4;
  *((_DWORD *)this + 576) = v40;
  v49 = a3;
  v51 = HIBYTE(a2);
  v50 = v41;
  v52 = LOBYTE(a9);
  v54 = &v48;
  v55 = &v58;
  GHashSetBase<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeAltHashF,GAllocatorLH<GFxFontCacheManagerImpl::VectorGlyphKey,196>,GHashsetCachedNodeEntry<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>,GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeHashF>>::add<GHashNode<GFxFontCacheManagerImpl::VectorGlyphKey,GFxFontCacheManagerImpl::VectorGlyphShape *,GFxFontCacheManagerImpl::VectorGlyphKey>::NodeRef>(
    this: (void **)this + 578,
    a2: (char *)this + 2312,
    a3: (int **)&v54,
    a4: v12 ^ v57 ^ LOBYTE(a9) ^ (unsigned __int16)a3 ^ v41 ^ HIBYTE(a2));
  if ( *((_BYTE *)this + 36) != 0 )
    *((_BYTE *)v58 + 15) |= 0x80u;
  GFxShapeBase::AddRef(this: (GFxShapeBase *)v58[5]);
  v42 = v58[5];
  GFxShapeBase::Release(this: v56);
  return (struct GFxShapeBase *)v42;
}

//------------------------------------------------------------------------------
// Address: 0x100F7EE0
// Name: private: void GFxFontCacheManagerImpl::fillBatchPackage(struct GFxBatchPackageData __near *,class GFxTextLineBuffer::Iterator const __near &,class GFxDisplayContext __near &,class GPoint<float> const __near &,struct GFxLineBufferGeometry __near *,struct GFxTextFieldParam const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxFontCacheManagerImpl::fillBatchPackage(
        GFxFontCacheManagerImpl *this,
        int *a2,
        int a3,
        int a4,
        float *a5,
        int a6,
        float a7,
        unsigned int a8)
{
  bool v8; // zf
  void **v9; // esi
  double v10; // st7
  unsigned int v11; // eax
  unsigned int v12; // ecx
  double v13; // st7
  unsigned int v14; // edx
  int v15; // ecx
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v16; // ebx
  int v17; // eax
  int v18; // esi
  IMaterialVar *v19; // ecx
  char *m_pStringVal; // ebx
  CUtlSymbol *p_m_Name; // esi
  CFunctor *FormatData; // eax
  unsigned __int16 *v23; // eax
  unsigned __int16 *v24; // edx
  unsigned int v25; // ebx
  int v26; // edi
  int v27; // eax
  int *v28; // esi
  int v29; // edx
  __int16 v30; // ax
  int v31; // eax
  double v32; // st7
  char v33; // al
  struct GFxShapeBase *GlyphShape_NoLock; // eax
  struct GFxShapeBase *v35; // edi
  int v36; // eax
  struct GFxGlyphParam *v37; // ebx
  unsigned int v38; // eax
  int v39; // eax
  float v40; // ecx
  double v41; // st7
  int v42; // ecx
  GFxFontCacheManagerImpl *v43; // esi
  char v44; // cl
  int v45; // eax
  bool v46; // al
  unsigned __int8 v47; // al
  float *cElems; // ebx
  CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *TextureGlyph; // eax
  GFxResource_vtbl *ImageInfo; // eax
  GFxResource_vtbl *v51; // esi
  int v52; // esi
  GFxFontCacheManagerImpl *v53; // ebx
  struct GFxGlyphNode *Glyph; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v55; // ecx
  int v56; // esi
  int *v57; // eax
  char *v58; // ebx
  int *v59; // eax
  unsigned int v60; // ecx
  void **v61; // edi
  unsigned int v62; // esi
  char *v63; // ecx
  int v64; // esi
  int v65; // esi
  unsigned int v66; // edi
  int v67; // eax
  int v68; // eax
  int v69; // eax
  unsigned int v70; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v71; // esi
  GFxFontManager *v72; // ecx
  IShaderDevice *v73; // ecx
  IShaderDevice *v74; // ecx
  IShaderDevice *v75; // ecx
  volatile LONG *v76; // ebx
  float v77; // esi
  int v78; // ecx
  int *v79; // ebx
  double v80; // st6
  float v81; // ecx
  double v82; // st6
  double v83; // st7
  int v84; // edx
  int *v85; // edi
  unsigned int v86; // eax
  int v87; // esi
  _DWORD *v88; // ecx
  int v89; // edx
  unsigned int v90; // ecx
  _DWORD *v91; // edx
  int *v92; // esi
  unsigned int v93; // edi
  unsigned int v94; // ebx
  unsigned int v95; // edi
  float *v96; // ecx
  float *v97; // eax
  unsigned int i; // edx
  unsigned int result; // eax
  float v100; // eax
  double v101; // st6
  double v102; // st7
  double v103; // st7
  double v104; // st6
  unsigned int v105; // edx
  int v106; // ecx
  int v107; // eax
  int v108; // edi
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v109; // ebx
  IMaterialVar *v110; // esi
  int v111; // eax
  double v112; // st6
  unsigned __int16 *v113; // eax
  int v114; // esi
  unsigned __int16 v115; // cx
  float v116; // edx
  int v117; // ebx
  unsigned int v118; // ecx
  int v119; // ebx
  int v120; // esi
  int v121; // eax
  int *v122; // ecx
  int v123; // edx
  int v124; // esi
  float v125; // ecx
  int v126; // eax
  int v127; // ecx
  int v128; // eax
  int v129; // esi
  GFxFontCacheManagerImpl *v130; // ecx
  int v131; // eax
  float v132; // ecx
  int v133; // edx
  double v134; // st7
  double v135; // st7
  int v136; // eax
  double v137; // st7
  signed int v138; // edx
  double v139; // st7
  double v140; // st7
  double v141; // st6
  double v142; // st5
  double v143; // st4
  double v144; // rtt
  double v145; // st4
  double v146; // st7
  double v147; // st4
  float v148; // eax
  int v149; // eax
  double v150; // st7
  GLock *v151; // edi
  int v152; // eax
  double v153; // st7
  double TextureGlyphScale; // st7
  double v155; // st7
  double v156; // st7
  double v157; // st6
  double v158; // st5
  double v159; // st4
  double v160; // st3
  double v161; // st2
  double v162; // rt1
  double v163; // st2
  double v164; // st7
  double v165; // rt2
  double v166; // st3
  double v167; // st4
  double v168; // st3
  double v169; // st2
  double v170; // rt2
  double v171; // rtt
  double v172; // st4
  double v173; // st3
  unsigned int v174; // ecx
  double v175; // st7
  unsigned __int8 *p_nReferenceCount; // eax
  float v177; // eax
  float *v178; // edx
  double v179; // st7
  double v180; // st7
  unsigned int v181; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v182; // eax
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v183; // esi
  _BYTE v184[24]; // [esp+24h] [ebp-1A4h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v185; // [esp+3Ch] [ebp-18Ch] BYREF
  const int *v186; // [esp+48h] [ebp-180h] BYREF
  float *v187; // [esp+4Ch] [ebp-17Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t v188; // [esp+50h] [ebp-178h] BYREF
  unsigned int v189; // [esp+5Ch] [ebp-16Ch]
  CFunctor *v190; // [esp+60h] [ebp-168h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v191; // [esp+64h] [ebp-164h] BYREF
  char v192; // [esp+94h] [ebp-134h]
  const int *v193; // [esp+98h] [ebp-130h]
  int v194; // [esp+9Ch] [ebp-12Ch]
  int v195; // [esp+A0h] [ebp-128h]
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v196; // [esp+A4h] [ebp-124h]
  GRefCountNTSImpl *v197; // [esp+A8h] [ebp-120h]
  int v198; // [esp+ACh] [ebp-11Ch]
  unsigned int v199; // [esp+B0h] [ebp-118h]
  int v200; // [esp+B4h] [ebp-114h]
  float v201; // [esp+B8h] [ebp-110h] BYREF
  float v202[8]; // [esp+BCh] [ebp-10Ch] BYREF
  int p; // [esp+DCh] [ebp-ECh] BYREF
  float v204; // [esp+E0h] [ebp-E8h]
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v205; // [esp+E4h] [ebp-E4h]
  unsigned __int64 v206; // [esp+E8h] [ebp-E0h]
  float v207; // [esp+F0h] [ebp-D8h]
  int v208; // [esp+F4h] [ebp-D4h]
  unsigned int v209; // [esp+F8h] [ebp-D0h]
  unsigned int v210; // [esp+FCh] [ebp-CCh]
  int v211; // [esp+100h] [ebp-C8h]
  unsigned int v212; // [esp+104h] [ebp-C4h]
  float v213; // [esp+108h] [ebp-C0h]
  float v214; // [esp+10Ch] [ebp-BCh]
  float v215; // [esp+110h] [ebp-B8h] BYREF
  float v216; // [esp+114h] [ebp-B4h]
  float v217; // [esp+118h] [ebp-B0h]
  float v218; // [esp+11Ch] [ebp-ACh]
  int v219; // [esp+120h] [ebp-A8h]
  GFxFontCacheManagerImpl *v220; // [esp+124h] [ebp-A4h]
  int v221; // [esp+128h] [ebp-A0h] BYREF
  float v222; // [esp+12Ch] [ebp-9Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t v223; // [esp+130h] [ebp-98h] BYREF
  float v224; // [esp+13Ch] [ebp-8Ch]
  bool v225; // [esp+143h] [ebp-85h]
  GFxFontResource *v226; // [esp+144h] [ebp-84h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v227; // [esp+148h] [ebp-80h] BYREF
  char *pString; // [esp+154h] [ebp-74h]
  bool v229[4]; // [esp+158h] [ebp-70h]
  float v230; // [esp+15Ch] [ebp-6Ch]
  int *v231; // [esp+160h] [ebp-68h]
  struct GFxGlyphParam *v232; // [esp+164h] [ebp-64h]
  unsigned int v233; // [esp+168h] [ebp-60h]
  char v234; // [esp+16Fh] [ebp-59h]
  float v235; // [esp+170h] [ebp-58h]
  float v236; // [esp+174h] [ebp-54h]
  unsigned int x_low; // [esp+178h] [ebp-50h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v238; // [esp+17Ch] [ebp-4Ch] BYREF
  float v239; // [esp+190h] [ebp-38h]
  GMatrix2D v240; // [esp+194h] [ebp-34h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > m; // [esp+1ACh] [ebp-1Ch] BYREF
  float v242; // [esp+1C0h] [ebp-8h]

  v8 = *(_DWORD *)(LODWORD(a7) + 24) == 0;
  v220 = this;
  v231 = a2;
  v200 = a3;
  *(_DWORD *)&v223.nReferenceCount = a4;
  v187 = a5;
  v219 = a6;
  v213 = a7;
  *(float *)&x_low = 0.0;
  if ( !v8 )
    a8 *= 2;
  v9 = (void **)(a2 + 4);
  if ( a2[5] != 0 )
  {
    if ( (a2[6] & 0xFFFFFFFE) != 0 )
    {
      if ( *v9 != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v9);
        *v9 = nullptr;
      }
      a2[6] = 0;
    }
  }
  else if ( a2[6] == 0 )
  {
    GArrayDataBase<GFxBatchPackageData::GlyphVerifier,GAllocatorLH<GFxBatchPackageData::GlyphVerifier,194>,GArrayDefaultPolicy>::Reserve(
      this: v9,
      a2: v9,
      a3: 0);
  }
  a2[5] = 0;
  if ( a8 > a2[6] )
    GArrayDataBase<GFxBatchPackageData::GlyphVerifier,GAllocatorLH<GFxBatchPackageData::GlyphVerifier,194>,GArrayDefaultPolicy>::Reserve(
      this: v9,
      a2: v9,
      a3: a8);
  *((_WORD *)v231 + 38) = 0;
  GMatrix2D::SetIdentity(this: (float *)&v240);
  GMatrix2D::SetIdentity(this: (float *)&v238);
  if ( (*(_BYTE *)(LODWORD(a7) + 7) & 1) != 0 )
  {
    v240.M_[0][0] = *(float *)(a6 + 24);
    v10 = *(float *)(a6 + 28);
    *(_DWORD *)v184 = *(_DWORD *)&v223.nReferenceCount + 120;
    v240.M_[0][1] = v10;
    v240.M_[0][2] = *(float *)(a6 + 32);
    v240.M_[1][0] = *(float *)(a6 + 36);
    v240.M_[1][1] = *(float *)(a6 + 40);
    v240.M_[1][2] = *(float *)(a6 + 44);
    GMatrix2D::Append(this: &v240, a2: (const struct GMatrix2D *)(*(_DWORD *)&v223.nReferenceCount + 120));
    *(float *)&v238.m_Memory.m_pMemory = v240.M_[0][0];
    *(float *)&v238.m_Memory.m_nAllocationCount = v240.M_[0][1];
    *(float *)&v238.m_Memory.m_nGrowSize = v240.M_[0][2];
    *(float *)&v238.m_Size = v240.M_[1][0];
    *(float *)&v238.m_pElements = v240.M_[1][1];
    v239 = v240.M_[1][2];
    v242 = v240.M_[1][2];
    *(float *)&m.m_Memory.m_pMemory = v240.M_[0][0];
    *(float *)&m.m_Memory.m_nAllocationCount = v240.M_[0][1];
    *(float *)&m.m_Memory.m_nGrowSize = v240.M_[0][2];
    *(float *)&m.m_Size = v240.M_[1][0];
    *(float *)&m.m_pElements = v240.M_[1][1];
    GMatrix2D::SetInverse(
      a1: (float *)&v238,
      (const CMaterialDict::MaterialLookup_t *)&m,
      a3: *(const CMaterialDict::MaterialLookup_t **)&v184[4]);
  }
  m.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a6 + 24);
  *(_DWORD *)v184 = &p;
  m.m_Memory.m_nAllocationCount = *(int *)(a6 + 28);
  m.m_Size = *(int *)(a6 + 36);
  m.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a6 + 40);
  *(float *)&m.m_Memory.m_nGrowSize = 0.0;
  v242 = 0.0;
  *(float *)&p = 1.0;
  v204 = 0.0;
  GMatrix2D::Transform(this: &m, result: &v223, (float *)&p, p_4: *(int *)&v184[4]);
  v236 = fabs(*(float *)&v223.pString);
  v225 = v236 > 0.000001 && (v236 = fabs(*(float *)&v223.nNextElement)) > 0.000001;
  v8 = *(_DWORD *)(LODWORD(a7) + 24) == 0;
  v11 = 1;
  v12 = 1;
  v210 = 1;
  v209 = 1;
  if ( !v8 )
  {
    v11 = 0;
    v8 = (*(_BYTE *)(LODWORD(a7) + 19) & 0x60) == 0;
    v210 = 0;
    if ( !v8 )
    {
      v12 = 0;
      v209 = 0;
    }
  }
  v13 = 0.0;
  v233 = v11;
  *(float *)(a6 + 84) = 0.0;
  *(float *)(a6 + 88) = 0.0;
  if ( v11 <= v12 )
  {
    while ( 1 )
    {
      v212 = v210;
      if ( v11 == 1 )
        *(float *)&v232 = v213;
      else
        v232 = (struct GFxGlyphParam *)(LODWORD(v213) + 12);
      if ( *((_DWORD *)v220 + 21) > 1u )
        v212 = v11;
      v14 = *(_DWORD *)(v200 + 4);
      v205 = *(CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **)v200;
      v15 = *(_DWORD *)(v200 + 8);
      v16 = v205;
      v206 = __PAIR64__(v15, v14);
      v17 = *(_DWORD *)(v200 + 16);
      v207 = *(float *)(v200 + 12);
      v208 = v17;
      v18 = v15;
      while ( 2 )
      {
        if ( v16 != nullptr && (unsigned int)v18 < v16->m_Memory.m_nAllocationCount && v18 >= 0 )
        {
          if ( (_BYTE)v208 != 0
            || (*(float *)v184 = v207, (unsigned __int8)GFxTextLineBuffer::IsLineVisible(this: v16) != 0) )
          {
            v19 = v16->m_Memory.m_pMemory[v18];
            if ( (int)v19->__vftable >= 0 )
              m_pStringVal = v19->m_pStringVal;
            else
              m_pStringVal = (char *)*((unsigned __int8 *)v19 + 28);
            p_m_Name = &v19->m_Name;
            if ( (int)v19->__vftable >= 0 )
              p_m_Name = (CUtlSymbol *)&v19[1].m_intVal + 1;
            FormatData = GFxTextLineBuffer::Line::GetFormatData(
                           this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v19,
                           a2: *(CMatRenderContextBase **)&v184[4],
                           a3: *(__int128 *)&v184[8],
                           a4: (const int *)v185.pString,
                           a5: (const int *)v185.nNextElement,
                           a6: *(const int **)&v185.nReferenceCount,
                           a7: v186);
            v191.m_iRefs = -1;
            v191.m_Proxy.m_pfnProxied = 0xFFFFFFFF00000000uLL;
            memset(&v191.m_Proxy.m_pObject, 0, 16);
            v192 = 0;
            v191.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
            v191.m_nUserID = 0;
            v193 = nullptr;
            v194 = 0;
            v195 = 0;
            v196 = nullptr;
            v197 = nullptr;
            v198 = 0;
            v199 = 0;
            *(_DWORD *)&v188.nReferenceCount = p_m_Name;
            v189 = (unsigned int)&p_m_Name[4 * (_DWORD)m_pStringVal];
            v190 = FormatData;
LABEL_41:
            GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: *(const VJobInstance **)&v184[4]);
            v23 = *(unsigned __int16 **)&v188.nReferenceCount;
LABEL_42:
            if ( *(float *)&v23 == 0.0 || (unsigned int)v23 >= v189 )
            {
              if ( v197 != nullptr )
                GRefCountNTSImpl::Release(this: v197);
              v71 = v196;
              if ( v196 != nullptr )
              {
                --LODWORD(v196->m_pfnProxied);
                if ( LODWORD(v71->m_pfnProxied) == 0 )
                {
                  v72 = (GFxFontManager *)DWORD1(v71->m_pfnProxied);
                  if ( v72 != nullptr )
                    GFxFontManager::RemoveFontHandle(this: v72, a2: (struct GFxFontHandle *)v71);
                  v73 = (IShaderDevice *)DWORD1(v71[1].m_pfnProxied);
                  if ( v73 != nullptr )
                    GFxResource::Release(this: v73);
                  DWORD1(v71[1].m_pfnProxied) = 0;
                  v74 = (IShaderDevice *)DWORD2(v71[1].m_pfnProxied);
                  if ( v74 != nullptr )
                    GFxResource::Release(this: v74);
                  v75 = (IShaderDevice *)DWORD1(v71[1].m_pfnProxied);
                  if ( v75 != nullptr )
                    GFxResource::Release(this: v75);
                  v76 = (volatile LONG *)(HIDWORD(v71->m_pfnProxied) & 0xFFFFFFFC);
                  if ( InterlockedExchangeAdd(Addend: v76 + 1, Value: -1) == 1 )
                    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v76);
                  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v71);
                }
              }
              v18 = HIDWORD(v206);
              v13 = 0.0;
              v16 = v205;
              if ( HIDWORD(v206) < v205->m_Memory.m_nAllocationCount )
                v18 = ++HIDWORD(v206);
              continue;
            }
            v24 = v23;
            v230 = *(float *)&v23;
            if ( v233 == 0 )
            {
              v23[3] &= ~0x20u;
              v23 = *(unsigned __int16 **)&v188.nReferenceCount;
            }
            if ( *v24 == 0xFFFF )
            {
              *((_BYTE *)v231 + 76) = 1;
              goto LABEL_158;
            }
            if ( (v24[3] & 0x200) != 0 )
              goto LABEL_158;
            if ( (v24[3] & 0x8000) == 0 && v233 == 1 )
            {
              *((_BYTE *)v231 + 76) = 1;
              goto LABEL_158;
            }
            if ( v196 != nullptr )
              v25 = DWORD1(v196[1].m_pfnProxied);
            else
              *(float *)&v25 = 0.0;
            *(_DWORD *)&v227.nReferenceCount = v25;
            if ( v25 != x_low )
            {
              v26 = *((_DWORD *)v220 + 570);
              x_low = v25;
              if ( v26 == 0 )
                goto LABEL_65;
              v27 = *(_DWORD *)(v26 + 4) & (v25 ^ (v25 >> 6));
              v28 = (int *)(v26 + 12 * v27 + 8);
              v29 = v27;
              if ( *v28 == -2 || *(_DWORD *)(v26 + 12 * v27 + 12) != v27 )
                goto LABEL_65;
              while ( v28[1] != v27 || v28[2] != v25 )
              {
                v29 = *v28;
                if ( *v28 == -1 )
                  goto LABEL_65;
                v28 = (int *)(v26 + 12 * v29 + 8);
              }
              if ( v29 < 0 || v26 + 12 * v29 == -16 )
              {
LABEL_65:
                GHashSetBase<GFxFontResource *,GFxFontHashOp,GFxFontHashOp,GAllocatorLH<GFxFontResource *,196>,GHashsetCachedEntry<GFxFontResource *,GFxFontHashOp>>::add<GFxFontResource *>(
                  this: (int *)v220 + 570,
                  a2: (int)v220 + 2280,
                  a3: &v227.nReferenceCount,
                  a4: v25 ^ (v25 >> 6));
                GFxFontResource::AddDisposeHandler(
                  this: (GFxFontResource *)v25,
                  a2: (GFxFontCacheManagerImpl *)((char *)v220 + 8));
              }
            }
            v227.pString = nullptr;
            v227.nNextElement = 0x100000;
            v226 = (GFxFontResource *)v25;
            v30 = *(_WORD *)LODWORD(v230);
            if ( *(_WORD *)LODWORD(v230) == 0xFFFF )
              v30 = -1;
            LOWORD(v227.pString) = v30;
            v31 = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
            v8 = (*(_BYTE *)(LODWORD(v230) + 6) & 0x10) == 0;
            *(_DWORD *)&v227.nReferenceCount = 0;
            v229[0] = false;
            v211 = v31;
            if ( v8 )
            {
              v224 = (float)(unsigned int)v31;
              v32 = 0.0625;
            }
            else
            {
              v32 = 0.0625;
              v224 = (double)(unsigned int)v31 * 0.0625;
            }
            v224 = v224 * *(float *)(v219 + 72);
            if ( v224 < 1.0 )
              v224 = 1.0;
            v8 = *(_DWORD *)(v25 + 16) == 0;
            LODWORD(v236) = HIWORD(pString) | 0xC00;
            *(_QWORD *)&v188.pString = (__int64)(v224 + 0.5);
            pString = v188.pString;
            if ( !v8 )
              goto LABEL_107;
            v229[0] = (*((_BYTE *)v232 + 7) & 1) != 0
                   && (LODWORD(v236) = *((unsigned __int8 *)v232 + 8), v236 = (double)SLODWORD(v236) * v32, 0.0 == v236)
                   && (v236 = v32 * (double)*((unsigned __int8 *)v232 + 9)) == 0.0
                   && v233 == 1
                   && (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(v25 + 12) + 20))(
                        a1: *(_DWORD *)(v25 + 12),
                        a2: LOWORD(v227.pString),
                        a3: 0) != 0;
            v33 = *((_BYTE *)v232 + 7);
            v236 = *(float *)(*(_DWORD *)(v25 + 12) + 12) + *(float *)(*(_DWORD *)(v25 + 12) + 8);
            v214 = *((float *)&v196->m_pObject + 1) * v236;
            v236 = v236 * *(float *)&v196[1].m_pfnProxied;
            if ( (v33 & 1) != 0 && v233 == 1 )
              *(_DWORD *)&v227.nReferenceCount = pString;
            else
              *(_DWORD *)&v227.nReferenceCount = 0;
            GlyphShape_NoLock = GFxFontCacheManagerImpl::GetGlyphShape_NoLock(
                                  this: v220,
                                  a2: (unsigned int)v226,
                                  a3: LOWORD(v227.pString),
                                  a4: *(unsigned int *)&v227.nReferenceCount,
                                  a5: COERCE_FLOAT((v33 & 8) != 0 || (DWORD2(v196->m_pfnProxied) & 2) != 0),
                                  a6: COERCE_FLOAT(((v33 & 0x10) != 0) | BYTE8(v196->m_pfnProxied) & 1),
                                  a7: v214,
                                  a8: v236,
                                  a9: COERCE_FLOAT((*((unsigned __int8 *)v232 + 11) >> 1) & 0xF),
                                  a10: *(float *)(*(_DWORD *)&v223.nReferenceCount + 100));
            v35 = GlyphShape_NoLock;
            *(_DWORD *)&v227.nReferenceCount = GlyphShape_NoLock;
            if ( GlyphShape_NoLock != nullptr )
            {
              v8 = (*((_BYTE *)GlyphShape_NoLock + 36) & 0x10) == 0;
              v215 = 0.0;
              v216 = 0.0;
              v217 = 0.0;
              v218 = 0.0;
              if ( v8 )
              {
                v36 = (unsigned __int16)*(_WORD *)LODWORD(v230);
                if ( (_WORD)v36 == 0xFFFF )
                  v36 = -1;
                (*(void (__thiscall **)(_DWORD, int, float *))(**(_DWORD **)(v25 + 12) + 48))(
                  a1: *(_DWORD *)(v25 + 12),
                  a2: v36,
                  a3: &v215);
              }
              else
              {
                v215 = *((float *)GlyphShape_NoLock + 1);
                v216 = *((float *)GlyphShape_NoLock + 2);
                v217 = *((float *)GlyphShape_NoLock + 3);
                v218 = *((float *)GlyphShape_NoLock + 4);
              }
              v37 = v232;
              if ( (*((_BYTE *)v232 + 7) & 1) == 0 )
              {
                v38 = (unsigned int)&pString[(unsigned int)(pString + 3) >> 2];
                if ( v38 > 0xFF )
                  v39 = 255;
                else
                  v39 = dword_103301C4[*((unsigned __int8 *)v220 + v38 + 2024)];
                pString = (char *)v39;
              }
              LODWORD(v40) = *((unsigned __int8 *)v232 + 9);
              LODWORD(v236) = *((unsigned __int8 *)v232 + 8);
              v41 = (double)SLODWORD(v236);
              v236 = v40;
              v42 = v219;
              v214 = v41 * 0.0625;
              v236 = 0.0625 * (double)SLODWORD(v236);
              if ( *(float *)(v219 + 84) < (double)v214 )
                *(float *)(v219 + 84) = v214;
              if ( *(float *)(v42 + 88) < (double)v236 )
                *(float *)(v42 + 88) = v236;
              v43 = v220;
              *(_DWORD *)v184 = (char *)&v202[4] + 2;
              v236 = v218 - v216;
              GFxGlyphRasterCache::CalcGlyphParam(
                this: (GFxFontCacheManagerImpl *)((char *)v220 + 76),
                a2: v224,
                a3: (unsigned int)pString,
                a4: *(float *)(v42 + 72),
                a5: v236,
                a6: v37,
                a7: (struct GFxGlyphParam *)&v226,
                a8: (unsigned __int16 *)&v202[4],
                a9: (unsigned __int16 *)&v202[4] + 1);
              v44 = *((_BYTE *)v37 + 7);
              if ( (v44 & 1) != 0
                && (*((_BYTE *)v37 + 11) & 1) == 0
                && *((_BYTE *)v35 + 37) == 0
                && !v229[0]
                && *((_BYTE *)v37 + 8) == 0 )
              {
                v45 = *((_DWORD *)v43 + 23);
                LODWORD(v236) = BYTE2(v227.pString);
                v211 = *((_DWORD *)v43 + 22) - 2 * v45;
                v236 = (v217 - v215) * (double)BYTE2(v227.pString) * 0.0009765625;
                if ( (double)(unsigned int)v211 > v236 * 3.0 )
                  HIBYTE(v227.pString) |= 4u;
              }
            }
            else
            {
LABEL_107:
              v37 = v232;
              v44 = *((_BYTE *)v232 + 7);
              v35 = *(struct GFxShapeBase **)&v227.nReferenceCount;
              BYTE2(v227.pString) = (_BYTE)pString;
              LOWORD(v202[4]) = 16 * (_WORD)pString;
              HIBYTE(v227.pString) = v44;
              HIWORD(v202[4]) = 256;
            }
            if ( v196 != nullptr )
            {
              if ( (DWORD2(v196->m_pfnProxied) & 0x20) != 0 )
                HIBYTE(v227.pString) &= ~2u;
              v46 = (DWORD2(v196->m_pfnProxied) & 2) != 0;
            }
            else
            {
              v46 = false;
            }
            if ( v46 || (v44 & 8) != 0 )
              HIBYTE(v227.pString) |= 8u;
            else
              HIBYTE(v227.pString) &= ~8u;
            if ( v196 != nullptr )
              v47 = BYTE8(v196->m_pfnProxied) & 1;
            else
              v47 = 0;
            if ( (v47 | ((v44 & 0x10) != 0)) != 0 )
              HIBYTE(v227.pString) |= 0x10u;
            else
              HIBYTE(v227.pString) &= ~0x10u;
            HIBYTE(v227.nNextElement) = *((_BYTE *)v37 + 11);
            v202[1] = *(float *)&v227.pString;
            v202[2] = *(float *)&v227.nNextElement;
            LODWORD(v202[0]) = v226;
            v202[3] = 0.0;
            memset(&v202[5], 0, 12);
            cElems = (float *)v226[2].cElems;
            if ( cElems != nullptr )
            {
              v202[4] = 2.3509887e-38;
              TextureGlyph = (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)GFxTextureGlyphData::GetTextureGlyph(this: (GFxTextureGlyphData *)cElems, a2: LOWORD(v227.pString));
              ImageInfo = GFxTextureGlyph::GetImageInfo(
                            this: TextureGlyph,
                            pbinding: (const struct GFxResourceBinding *)v226[2].pElems);
              v51 = ImageInfo;
              if ( ImageInfo != nullptr )
              {
                LODWORD(v202[5]) = (*((int (__thiscall **)(GFxResource_vtbl *, _DWORD))ImageInfo->dtr_GFxResource + 5))(
                                     a1: ImageInfo,
                                     a2: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v223.nReferenceCount + 72) + 12));
                v202[6] = cElems[6];
                LOWORD(v202[7]) = (*((int (__thiscall **)(GFxResource_vtbl *))v51->dtr_GFxResource + 1))(a1: v51);
                HIWORD(v202[7]) = (*((int (__thiscall **)(GFxResource_vtbl *))v51->dtr_GFxResource + 2))(a1: v51);
              }
            }
            else
            {
              v52 = *(_DWORD *)&v223.nReferenceCount;
              v53 = v220;
              Glyph = GFxGlyphRasterCache::GetGlyph(
                        this: (GFxFontCacheManagerImpl *)((char *)v220 + 76),
                        a2: *(struct GRenderer **)(*(_DWORD *)(*(_DWORD *)&v223.nReferenceCount + 72) + 12),
                        a3: (const struct GFxGlyphParam *)&v226,
                        a4: v229[0],
                        a5: v35,
                        a6: LOWORD(v202[4]),
                        count: *(struct GFxLog **)(*(_DWORD *)&v223.nReferenceCount + 100));
              LODWORD(v202[3]) = Glyph;
              if ( Glyph != nullptr )
              {
                v202[5] = *((float *)v53 + 5 * (*(_WORD *)(*((_DWORD *)Glyph + 3) + 32) & 0x3FFF) + 33);
                *(_WORD *)(*((_DWORD *)Glyph + 3) + 32) |= 0x8000u;
              }
              else
              {
                if ( v35 != nullptr )
                {
                  v56 = *(_DWORD *)(v52 + 100);
                  if ( v56 != 0 && *((_BYTE *)v53 + 37) != 0 )
                    GFxLogBase<GFxLog>::LogWarning(
                      this: v55,
                      pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v56 + 12),
                      this_4: (int)"Warning: Increase raster glyph cache capacity - TextureConfig.\n",
                      this_8: *(int *)&v184[4]);
                }
                v57 = v231;
                *((_BYTE *)v53 + 37) = 0;
                *((_BYTE *)v57 + 77) = 1;
              }
            }
            v58 = (char *)LODWORD(v202[5]);
            if ( LODWORD(v202[5]) != 0 )
            {
              if ( (LOBYTE(v202[6]) & 1) == 0 || v233 == 1 )
              {
                if ( v233 == 0 )
                {
                  *(_WORD *)(LODWORD(v230) + 6) |= 0x20u;
                  v58 = (char *)LODWORD(v202[5]);
                }
                v59 = v231;
                v60 = v231[5];
                v61 = (void **)(v231 + 4);
                v62 = v60 + 1;
                if ( v60 + 1 >= v60 )
                {
                  if ( v62 >= v231[6] )
                  {
                    *(_DWORD *)v184 = v62 + (v62 >> 2);
LABEL_142:
                    GArrayDataBase<GFxBatchPackageData::GlyphVerifier,GAllocatorLH<GFxBatchPackageData::GlyphVerifier,194>,GArrayDefaultPolicy>::Reserve(
                      this: v61,
                      a2: v61,
                      a3: *(int *)v184);
                    v59 = v231;
                    v58 = (char *)LODWORD(v202[5]);
                  }
                }
                else if ( v62 < (unsigned int)v231[6] >> 1 )
                {
                  *(_DWORD *)v184 = v60 + 1;
                  goto LABEL_142;
                }
                v63 = (char *)*v61;
                v61[1] = (void *)v62;
                v64 = 32 * v62;
                if ( &v63[v64] != (char *)32 )
                {
                  qmemcpy(&v63[v64 - 32], v202, 32);
                  v58 = (char *)LODWORD(v202[5]);
                }
                v65 = *v59;
                v66 = v212;
                v223.pString = v58;
                v223.nNextElement = v212;
                if ( v65 != 0 )
                {
                  v67 = GHashSetBase<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeAltHashF,GAllocatorLH<GFxBatchPackageData::BatchInfoKey,194>,GHashsetCachedNodeEntry<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF>>::findIndexCore<GFxBatchPackageData::BatchInfoKey>(
                          this: v59,
                          a2: &v223,
                          a3: *(_DWORD *)(v65 + 4) & (v212 ^ (unsigned int)v58 ^ ((unsigned int)v58 >> 6)));
                  if ( v67 < 0 || (v68 = v65 + 36 * v67 + 16) == 0 || (v69 = v68 + 8) == 0 )
                  {
                    v59 = v231;
                    goto LABEL_150;
                  }
                  ++*(_DWORD *)(v69 + 4);
                }
                else
                {
LABEL_150:
                  *(float *)&p = COERCE_FLOAT(&v223);
                  m.m_Memory.m_nAllocationCount = 0;
                  m.m_Size = 0;
                  v242 = v202[6];
                  v204 = COERCE_FLOAT((CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&m.m_Memory.m_nAllocationCount);
                  m.m_pElements = (CCountedStringPoolBase<unsigned int>::hash_item_t *)v58;
                  m.m_Memory.m_nGrowSize = 1;
                  GHashSetBase<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeAltHashF,GAllocatorLH<GFxBatchPackageData::BatchInfoKey,194>,GHashsetCachedNodeEntry<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF>>::add<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeRef>(
                    this: v59,
                    a2: v59,
                    a3: (int **)&p,
                    a4: v66 ^ (unsigned int)v58 ^ ((unsigned int)v58 >> 6));
                }
              }
            }
            else
            {
              if ( v233 == 1 )
                *(_WORD *)(LODWORD(v230) + 6) &= ~0x8000u;
              *((_BYTE *)v231 + 76) = 1;
              *(_BYTE *)(v219 + 96) |= 0x10u;
            }
            if ( *(_DWORD *)&v227.nReferenceCount != 0 )
              GFxShapeBase::Release(this: *(GFxShapeBase **)&v227.nReferenceCount);
            v23 = *(unsigned __int16 **)&v188.nReferenceCount;
LABEL_158:
            if ( *(float *)&v23 != 0.0 && (unsigned int)v23 < v189 )
            {
              v70 = v199;
              if ( v199 == 0 )
              {
                v70 = v23[2] >> 12;
                v199 = v70;
              }
              *(_DWORD *)&v188.nReferenceCount = v23 + 4;
              if ( (v23[6] & 0xF000) != 0
                && v70 != 0
                && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v191) )
              {
                GFxTextHighlighterPosIterator::operator+=(this: &v191, p: v199);
                v199 = 0;
              }
              goto LABEL_41;
            }
            goto LABEL_42;
          }
          v13 = 0.0;
        }
        break;
      }
      if ( ++v233 > v209 )
        break;
      v11 = v233;
    }
  }
  v77 = v213;
  v78 = *(_DWORD *)(LODWORD(v213) + 24);
  v79 = v231;
  v234 = 0;
  v231[11] = v78;
  if ( v78 != 0 )
  {
    LODWORD(v236) = *(unsigned __int8 *)(LODWORD(v77) + 20);
    v234 = 1;
    v236 = (double)SLODWORD(v236) * 0.0625;
    v80 = v236;
    if ( v236 > 3.0 )
      v80 = 3.0;
    *(float *)&x_low = v80;
    *((float *)v79 + 10) = *(float *)&x_low * 6.0;
    LODWORD(v81) = *(__int16 *)(LODWORD(v77) + 30);
    LODWORD(v236) = *(__int16 *)(LODWORD(v77) + 28);
    v82 = (double)SLODWORD(v236);
    v236 = v81;
    *(float *)&v223.pString = v82 * 0.05000000074505806;
    *(float *)&v223.nNextElement = 0.05000000074505806 * (double)SLODWORD(v81);
    v79[12] = (int)v223.pString;
    v79[13] = v223.nNextElement;
    v236 = *((float *)v79 + 13) * *((float *)v79 + 13) + *((float *)v79 + 12) * *((float *)v79 + 12);
    if ( v236 > 4.0 )
    {
      v236 = sqrt(v236);
      v83 = 2.0 / v236;
      *((float *)v79 + 12) = *((float *)v79 + 12) * v83;
      *((float *)v79 + 13) = v83 * *((float *)v79 + 13);
      v13 = 0.0;
    }
  }
  v84 = *(_DWORD *)(LODWORD(v77) + 32);
  v79[14] = v84;
  if ( v84 != 0 )
  {
    *((float *)v79 + 15) = v13;
    LODWORD(v236) = *(unsigned __int8 *)(LODWORD(v77) + 36);
    v234 = 1;
    *((float *)v79 + 16) = (double)SLODWORD(v236) * 0.0625;
  }
  if ( *v79 != 0 )
  {
    v86 = 0;
    v88 = (_DWORD *)(*v79 + 8);
    do
    {
      if ( *v88 != -2 )
        break;
      ++v86;
      v88 += 9;
    }
    while ( v86 <= *(_DWORD *)(*v79 + 4) );
    v85 = v79;
    v87 = 0;
  }
  else
  {
    v85 = nullptr;
    v86 = 0;
    v87 = 0;
  }
  while ( v85 != nullptr )
  {
    v89 = *v85;
    if ( *v85 == 0 || (signed int)v86 > *(_DWORD *)(v89 + 4) )
      break;
    *(_DWORD *)(36 * v86 + v89 + 24) = v87;
    v87 += *(_DWORD *)(36 * v86 + *v85 + 28);
    v90 = *(_DWORD *)(*v85 + 4);
    if ( (int)v86 <= (int)v90 && ++v86 <= v90 )
    {
      v91 = (_DWORD *)(*v85 + 36 * v86 + 8);
      do
      {
        if ( *v91 != -2 )
          break;
        ++v86;
        v91 += 9;
      }
      while ( v86 <= v90 );
      v79 = v231;
    }
  }
  v92 = v79 + 1;
  if ( v79[2] != 0 )
  {
    if ( (v79[3] & 0xFFFFFFFE) != 0 )
    {
      if ( *v92 != 0 )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*v92);
        v13 = 0.0;
        *v92 = 0;
      }
      v79[3] = 0;
    }
  }
  else if ( v79[3] == 0 )
  {
    GArrayDataBase<GRenderer::BitmapDesc,GAllocatorLH<GRenderer::BitmapDesc,194>,GArrayDefaultPolicy>::Reserve(
      this: (void **)v79 + 1,
      a2: v79 + 1,
      a3: 0);
    v13 = 0.0;
  }
  v79[2] = 0;
  v93 = v79[5];
  v94 = v79[2];
  if ( v93 >= v94 )
  {
    if ( v93 >= v92[2] )
    {
      *(_DWORD *)v184 = v93 + (v93 >> 2);
      goto LABEL_220;
    }
  }
  else if ( v93 < (unsigned int)v92[2] >> 1 )
  {
    *(_DWORD *)v184 = v93;
LABEL_220:
    GArrayDataBase<GRenderer::BitmapDesc,GAllocatorLH<GRenderer::BitmapDesc,194>,GArrayDefaultPolicy>::Reserve(
      this: (void **)v92,
      a2: v92,
      a3: *(int *)v184);
    v13 = 0.0;
  }
  v92[1] = v93;
  if ( v93 > v94 )
  {
    v95 = v93 - v94;
    v96 = (float *)(*v92 + 36 * v94);
    if ( v95 != 0 )
    {
      v97 = v96 + 6;
      for ( i = v95; i != 0; --i )
      {
        if ( v96 != nullptr )
        {
          *v96 = v13;
          *(v97 - 5) = v13;
          *(v97 - 4) = v13;
          *(v97 - 3) = v13;
          *(v97 - 2) = v13;
          *(v97 - 1) = v13;
          *v97 = v13;
          v97[1] = v13;
        }
        v96 += 9;
        v97 += 9;
      }
    }
  }
  result = v210;
  *(_DWORD *)&v227.nReferenceCount = 0;
  v233 = v210;
  if ( v210 <= v209 )
  {
    while ( 1 )
    {
      v100 = v213;
      v8 = *(_BYTE *)(LODWORD(v213) + 27) == 0;
      v212 = v210;
      v215 = *(float *)(v219 + 4);
      v216 = *(float *)(v219 + 8);
      v217 = *(float *)(v219 + 12);
      v218 = *(float *)(v219 + 16);
      if ( !v8 )
      {
        if ( v233 == 0 || v234 != 0 )
        {
          v101 = *(float *)(v219 + 84) * 20.0;
          v215 = v215 - v101;
          v102 = 20.0 * *(float *)(v219 + 88);
          v216 = v216 - v102;
          v217 = v101 + v217;
          v218 = v102 + v218;
        }
        if ( v233 == 0 )
          break;
      }
      if ( v233 != 1 )
        goto LABEL_235;
LABEL_236:
      v224 = v100;
      if ( *((_DWORD *)v220 + 21) > 1u )
        v212 = v233;
      v105 = *(_DWORD *)(v200 + 4);
      v205 = *(CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > **)v200;
      v106 = *(_DWORD *)(v200 + 8);
      v206 = __PAIR64__(v106, v105);
      v107 = *(_DWORD *)(v200 + 16);
      v207 = *(float *)(v200 + 12);
      v208 = v107;
      v108 = v106;
      while ( 2 )
      {
        v109 = v205;
        if ( v205 != nullptr && (unsigned int)v108 < v205->m_Memory.m_nAllocationCount && v108 >= 0 )
        {
          if ( (_BYTE)v208 != 0
            || (*(float *)v184 = v207, (unsigned __int8)GFxTextLineBuffer::IsLineVisible(this: v205) != 0) )
          {
            v110 = v109->m_Memory.m_pMemory[v108];
            x_low = LODWORD(v110->m_VecVal.x);
            *(float *)&v221 = (float)(int)x_low;
            x_low = LODWORD(v110->m_VecVal.y);
            v222 = (float)(int)x_low;
            *(float *)&v221 = *(float *)&v221 + *v187;
            v111 = *(_DWORD *)(v219 + 20);
            v222 = v187[1] + v222;
            v112 = (double)*(int *)(v219 + 20);
            if ( v111 < 0 )
              v112 = v112 + 4294967300.0;
            *(float *)&v221 = *(float *)&v221 - v112;
            if ( (int)v110->__vftable >= 0 )
              LODWORD(v236) = HIWORD(v110[1].m_pStringVal);
            else
              LODWORD(v236) = HIWORD(v110->m_VecVal.w);
            *(float *)&x_low = (float)SLODWORD(v236);
            v8 = (*(_BYTE *)(LODWORD(v224) + 7) & 1) == 0;
            v222 = v222 + *(float *)&x_low;
            if ( !v8 )
            {
              GMatrix2D::Transform(
                this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v240,
                result: &v185,
                p: (float *)&v221,
                p_4: *(int *)&v184[4]);
              v236 = *(float *)&v185.pString + 0.5;
              v236 = floor(X: v236);
              *(float *)&v221 = v236;
              v236 = *(float *)&v185.nNextElement + 0.5;
              v236 = floor(X: v236);
              v222 = v236;
              GMatrix2D::Transform(
                this: &v238,
                result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v184[16],
                p: (float *)&v221,
                p_4: *(int *)&v184[4]);
              v221 = *(int *)&v184[16];
              v222 = *(float *)&v184[20];
            }
            *(_DWORD *)v184 = v206;
            GFxTextLineBuffer::Line::Begin(
              this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v110,
              phighlighter: (CMatRenderContextBase *)&v188.nReferenceCount,
              a3: *(__int128 *)v184,
              a4: *(ITexture *const **)&v184[16],
              a5: *(const float **)&v184[20],
              a6: (const float *)v185.pString,
              a7: (const float *)v185.nNextElement);
            v113 = *(unsigned __int16 **)&v188.nReferenceCount;
            v114 = 32 * *(_DWORD *)&v227.nReferenceCount;
LABEL_252:
            if ( *(float *)&v113 == 0.0 || (unsigned int)v113 >= v189 )
            {
              if ( v197 != nullptr )
                GRefCountNTSImpl::Release(this: v197);
              v182 = v196;
              if ( v196 != nullptr )
              {
                --LODWORD(v196->m_pfnProxied);
                v183 = v182;
                if ( LODWORD(v182->m_pfnProxied) == 0 )
                {
                  GFxFontHandle::~GFxFontHandle(this: v182);
                  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v183);
                }
              }
              if ( (unsigned int)v108 < v109->m_Memory.m_nAllocationCount )
                HIDWORD(v206) = ++v108;
              continue;
            }
            *(_DWORD *)v229 = v113 + 3;
            v115 = v113[3];
            LODWORD(v116) = v113[1];
            v230 = *(float *)&v113;
            if ( (v115 & 0x40) != 0 )
              LODWORD(v116) = -LODWORD(v116);
            v236 = v116;
            if ( *v113 == 0xFFFF )
            {
              *((_BYTE *)v231 + 76) = 1;
              goto LABEL_318;
            }
            x_low = *v113;
            if ( (v115 & 0x200) != 0 )
              goto LABEL_318;
            if ( v233 == 0 )
            {
              if ( (v115 & 0x20) != 0 )
                goto LABEL_262;
LABEL_318:
              if ( *(float *)&v113 != 0.0 && (unsigned int)v113 < v189 )
              {
                v181 = v199;
                if ( v199 == 0 )
                {
                  v181 = v113[2] >> 12;
                  v199 = v181;
                }
                *(_DWORD *)&v188.nReferenceCount = v113 + 4;
                if ( (v113[6] & 0xF000) != 0
                  && v181 != 0
                  && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v191) )
                {
                  GFxTextHighlighterPosIterator::operator+=(this: &v191, p: v199);
                  v199 = 0;
                }
                GFxTextLineBuffer::GlyphIterator::UpdateDesc(result: *(const VJobInstance **)&v184[4]);
                v113 = *(unsigned __int16 **)&v188.nReferenceCount;
              }
              v109 = v205;
              *(float *)&v221 = (double)SLODWORD(v236) + *(float *)&v221;
              goto LABEL_252;
            }
            if ( (v115 & 0x8000) == 0 )
            {
              *((_BYTE *)v231 + 76) = 1;
              goto LABEL_318;
            }
LABEL_262:
            v117 = v231[4];
            ++*(_DWORD *)&v227.nReferenceCount;
            v118 = *(_DWORD *)(v117 + v114 + 20);
            v119 = v114 + v117;
            v211 = v114 + 32;
            v120 = *v231;
            if ( *v231 == 0 )
              goto LABEL_275;
            v121 = *(_DWORD *)(v120 + 4) & (v212 ^ v118 ^ (v118 >> 6));
            v122 = (int *)(v120 + 36 * v121 + 8);
            v123 = v121;
            if ( *v122 == -2 || *(_DWORD *)(v120 + 36 * v121 + 12) != v121 )
              goto LABEL_275;
            while ( v122[1] != v121 || v122[2] != *(_DWORD *)(v119 + 20) || v122[3] != v212 )
            {
              v123 = *v122;
              if ( *v122 == -1 )
                goto LABEL_275;
              v122 = (int *)(v120 + 36 * v123 + 8);
            }
            if ( v123 >= 0 && (v124 = v120 + 36 * v123 + 16) != 0 )
              LODWORD(v125) = v124 + 8;
            else
LABEL_275:
              v125 = 0.0;
            v126 = *(_DWORD *)(LODWORD(v125) + 8) + *(_DWORD *)LODWORD(v125);
            v214 = v125;
            v127 = 9 * v126;
            v128 = *(_DWORD *)(v119 + 12);
            v129 = v231[1] + 4 * v127;
            HIBYTE(pString) = 0;
            if ( v128 != 0 )
            {
              v130 = v220;
              if ( *((_BYTE *)v220 + 36) == 0 )
                *(_WORD *)(*(_DWORD *)(v128 + 12) + 32) &= ~0x8000u;
              v131 = *(_DWORD *)(v119 + 12);
              x_low = *(unsigned __int16 *)(v131 + 24) + 1;
              *(float *)(v129 + 16) = (double)(int)x_low * *((float *)v130 + 24);
              x_low = *(unsigned __int16 *)(v131 + 26) + 1;
              *(float *)(v129 + 20) = (double)(int)x_low * *((float *)v130 + 25);
              x_low = *(unsigned __int16 *)(v131 + 28) - 2;
              *(float *)(v129 + 24) = (double)(int)x_low * *((float *)v130 + 24) + *(float *)(v129 + 16);
              x_low = *(unsigned __int16 *)(v131 + 30) - 2;
              *(float *)(v129 + 28) = (double)(int)x_low * *((float *)v130 + 25) + *(float *)(v129 + 20);
              LODWORD(v235) = (*(_BYTE *)(v119 + 7) & 4 | 2u) >> 1;
              v132 = v235;
              v133 = *(__int16 *)(v131 + 32);
              *(float *)&v223.nReferenceCount = (float)SLODWORD(v235);
              x_low = *(unsigned __int16 *)(v131 + 24) - v133 + 1;
              v134 = *(float *)&v223.nReferenceCount;
              *(float *)v129 = (double)(int)x_low * 20.0 / *(float *)&v223.nReferenceCount;
              x_low = *(unsigned __int16 *)(v131 + 26) - *(__int16 *)(v131 + 34) + 1;
              *(float *)(v129 + 4) = (double)(int)x_low * 20.0;
              x_low = *(unsigned __int16 *)(v131 + 28) - 2;
              *(float *)(v129 + 8) = (double)(int)x_low * 20.0 / v134 + *(float *)v129;
              x_low = *(unsigned __int16 *)(v131 + 30) - 2;
              *(float *)(v129 + 12) = 20.0 * (double)(int)x_low + *(float *)(v129 + 4);
              if ( LODWORD(v132) != 1 || v225 || (v8 = *(_BYTE *)(v119 + 8) == 0, HIBYTE(pString) = 1, !v8) )
                HIBYTE(pString) = 0;
              if ( (*(_BYTE *)(v119 + 7) & 1) != 0 )
              {
                x_low = *(unsigned __int16 *)(v119 + 18);
                v135 = 1.0 / (*(float *)(v219 + 72) * (double)(int)x_low * 0.00390625);
              }
              else
              {
                v136 = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                if ( (**(_BYTE **)v229 & 0x10) != 0 )
                {
                  LODWORD(v235) = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                  v137 = (double)(unsigned int)v136 * 0.0625;
                }
                else
                {
                  LODWORD(v235) = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                  v137 = (double)(unsigned int)v136;
                }
                v138 = *(unsigned __int16 *)(v119 + 16);
                *(float *)&x_low = v137;
                HIBYTE(pString) = 0;
                *(float *)&x_low = *(float *)&x_low * 16.0;
                v139 = *(float *)&x_low;
                x_low = v138;
                v135 = v139 / (double)v138;
              }
              v8 = v233 == 0;
              *(float *)&v232 = v135;
              v140 = *(float *)&v232;
              *(float *)&x_low = *(float *)v129 * *(float *)&v232;
              v141 = *(float *)&x_low;
              *(float *)v129 = *(float *)&x_low;
              *(float *)&x_low = v140 * *(float *)(v129 + 4);
              v142 = *(float *)&x_low;
              *(float *)(v129 + 4) = *(float *)&x_low;
              *(float *)&x_low = v140 * *(float *)(v129 + 8);
              v143 = *(float *)&x_low;
              *(float *)(v129 + 8) = *(float *)&x_low;
              v144 = v143;
              v145 = v140 * *(float *)(v129 + 12);
              v146 = v144;
              *(float *)&x_low = v145;
              v147 = *(float *)&x_low;
              *(float *)(v129 + 12) = *(float *)&x_low;
              if ( v8 )
              {
                v148 = v213;
                x_low = *(__int16 *)(LODWORD(v213) + 28);
                *(float *)v129 = v141 + (double)(int)x_low;
                x_low = *(__int16 *)(LODWORD(v148) + 30);
                *(float *)(v129 + 4) = v142 + (double)(int)x_low;
                x_low = *(__int16 *)(LODWORD(v148) + 28);
                *(float *)(v129 + 8) = v146 + (double)(int)x_low;
                x_low = *(__int16 *)(LODWORD(v148) + 30);
                *(float *)(v129 + 12) = v147 + (double)(int)x_low;
              }
              v149 = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
              if ( (**(_BYTE **)v229 & 0x10) != 0 )
              {
                LODWORD(v235) = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                v150 = (double)(unsigned int)v149 * 0.0625;
              }
              else
              {
                LODWORD(v235) = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                v150 = (double)(unsigned int)v149;
              }
              *(float *)&x_low = v150;
              x_low = (int)*(float *)&x_low;
              *(_WORD *)(v119 + 16) = x_low;
            }
            else
            {
              *(_DWORD *)&v223.nReferenceCount = *(_DWORD *)(*(_DWORD *)v119 + 16);
              v151 = GFxTextureGlyphData::GetTextureGlyph(
                       this: *(GFxTextureGlyphData **)&v223.nReferenceCount,
                       a2: x_low);
              v152 = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
              if ( (**(_BYTE **)v229 & 0x10) != 0 )
              {
                LODWORD(v235) = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                v153 = (double)(unsigned int)v152 * 0.0625;
              }
              else
              {
                LODWORD(v235) = *(_WORD *)(LODWORD(v230) + 4) & 0xFFF;
                v153 = (double)(unsigned int)v152;
              }
              *(float *)&x_low = v153;
              *(float *)&x_low = *(float *)&x_low * 20.0;
              *(float *)&v232 = *(float *)&x_low * 0.0009765625;
              TextureGlyphScale = GFxTextureGlyphData::GetTextureGlyphScale(this: *(GFxTextureGlyphData **)&v223.nReferenceCount);
              x_low = *(unsigned __int16 *)(v119 + 28);
              v235 = TextureGlyphScale * *(float *)&v232 * (double)(int)x_low;
              v155 = GFxTextureGlyphData::GetTextureGlyphScale(this: *(GFxTextureGlyphData **)&v223.nReferenceCount);
              x_low = *(unsigned __int16 *)(v119 + 30);
              *(float *)&v232 = v155 * *(float *)&v232 * (double)(int)x_low;
              x_low = v151->cs.SpinCount;
              v230 = *(float *)&v151[1].cs.DebugInfo;
              *(float *)v229 = *(float *)&v151[1].cs.LockCount;
              *(float *)v129 = *(float *)&v151->cs.LockSemaphore;
              *(float *)(v129 + 4) = *(float *)&x_low;
              *(float *)(v129 + 8) = v230;
              *(float *)(v129 + 12) = *(float *)v229;
              x_low = v151->cs.SpinCount;
              v230 = *(float *)&v151[1].cs.DebugInfo;
              *(float *)v229 = *(float *)&v151[1].cs.LockCount;
              *(float *)(v129 + 16) = *(float *)&v151->cs.LockSemaphore;
              *(float *)(v129 + 20) = *(float *)&x_low;
              *(float *)(v129 + 24) = v230;
              *(float *)(v129 + 28) = *(float *)v229;
              *(float *)&p = -*(float *)&v151[1].cs.RecursionCount;
              v204 = -*(float *)&v151[1].cs.OwningThread;
              v156 = *(float *)&p;
              *(float *)&x_low = *(float *)v129 + *(float *)&p;
              v157 = v235;
              v235 = *(float *)&x_low * v235;
              v158 = v235;
              *(float *)v129 = v235;
              v159 = v204;
              v235 = v204 + *(float *)(v129 + 4);
              v160 = *(float *)&v232;
              v235 = v235 * *(float *)&v232;
              v8 = v234 == 0;
              v161 = v235;
              *(float *)(v129 + 4) = v235;
              v162 = v161;
              v163 = v156 + *(float *)(v129 + 8);
              v164 = v162;
              v235 = v163;
              v230 = v235 * v157;
              *(float *)(v129 + 8) = v230;
              v165 = v160;
              v166 = v159 + *(float *)(v129 + 12);
              v167 = v165;
              v235 = v166;
              *(float *)v229 = v235 * v165;
              *(float *)(v129 + 12) = *(float *)v229;
              if ( !v8 && *(_DWORD *)(v119 + 24) != 0 )
              {
                v235 = (double)(unsigned int)(*(_DWORD *)(*(_DWORD *)&v223.nReferenceCount + 28) - 2) * 5.0;
                *(float *)&x_low = *((float *)v231 + 10) * 20.0 / 6.0;
                if ( *(float *)&x_low > (double)v235 )
                  *(float *)&x_low = v235;
                v235 = v235 - *(float *)&x_low;
                v168 = *(float *)&x_low;
                *(float *)&x_low = 20.0 * *((float *)v231 + 12);
                v169 = v235;
                if ( *(float *)&x_low > (double)v235 )
                  *(float *)&x_low = v235;
                v235 = v168 + *(float *)&x_low;
                *(float *)&x_low = *((float *)v231 + 13) * 20.0;
                if ( *(float *)&x_low <= v169 )
                  v169 = *(float *)&x_low;
                *(float *)&x_low = v169;
                *(float *)&x_low = v168 + *(float *)&x_low;
                v170 = v168;
                *(float *)v129 = v158 - v168;
                v171 = v167;
                *(float *)(v129 + 4) = v164 - v168;
                v172 = v235;
                *(float *)(v129 + 8) = v230 + v235;
                v173 = *(float *)&x_low;
                *(float *)(v129 + 12) = *(float *)v229 + *(float *)&x_low;
                *(float *)(v129 + 16) = *(float *)(v129 + 16) - v170 / v157;
                *(float *)(v129 + 20) = *(float *)(v129 + 20) - v170 / v171;
                *(float *)(v129 + 24) = v172 / v157 + *(float *)(v129 + 24);
                *(float *)(v129 + 28) = v173 / v171 + *(float *)(v129 + 28);
              }
            }
            v223.pString = (char *)v221;
            *(float *)&v223.nNextElement = v222;
            if ( HIBYTE(pString) != 0 )
            {
              GMatrix2D::Transform(
                this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v240,
                result: &v227,
                p: (float *)&v223,
                p_4: *(int *)&v184[4]);
              v223.nNextElement = v227.nNextElement;
              v235 = *(float *)&v227.pString + 0.5;
              v235 = floor(X: v235);
              *(float *)&v223.pString = v235;
              GMatrix2D::Transform(this: &v238, result: &v188, p: (float *)&v223, p_4: *(int *)&v184[4]);
              v223.pString = v188.pString;
              v223.nNextElement = v188.nNextElement;
            }
            v174 = v233;
            v235 = *(float *)&v223.pString;
            x_low = v223.nNextElement;
            *(float *)v129 = *(float *)&v223.pString + *(float *)v129;
            *(float *)(v129 + 8) = v235 + *(float *)(v129 + 8);
            v175 = *(float *)&x_low;
            *(float *)(v129 + 4) = *(float *)&x_low + *(float *)(v129 + 4);
            *(float *)(v129 + 12) = v175 + *(float *)(v129 + 12);
            if ( v174 == 1 )
            {
              v186 = v193;
              p_nReferenceCount = (unsigned __int8 *)&v186;
            }
            else
            {
              *(_DWORD *)&v185.nReferenceCount = *(_DWORD *)(LODWORD(v213) + 24);
              p_nReferenceCount = &v185.nReferenceCount;
            }
            v177 = *(float *)p_nReferenceCount;
            *(float *)(v129 + 32) = v177;
            if ( v174 == 1 )
            {
              if ( (*(_BYTE *)(v219 + 96) & 0x20) == 0 )
                goto LABEL_314;
            }
            else
            {
              v201 = *(float *)v129;
              v202[7] = v177;
              v202[0] = *(float *)(v129 + 4);
              v202[1] = *(float *)(v129 + 8);
              v202[2] = *(float *)(v129 + 12);
              v202[3] = *(float *)(v129 + 16);
              v202[4] = *(float *)(v129 + 20);
              v202[5] = *(float *)(v129 + 24);
              v202[6] = *(float *)(v129 + 28);
              GFx_ClipBitmapDesc(a1: &v201, a2: (float *)(v219 + 4));
              v235 = v202[1] - v201;
              v179 = v235 + v235;
              v235 = *(float *)(v129 + 8) - *(float *)v129;
              if ( v235 < v179 )
              {
LABEL_314:
                GFx_ClipBitmapDesc(a1: (float *)v129, a2: &v215);
              }
              else
              {
                v235 = v178[1];
                *(float *)v129 = *v178;
                v180 = v235;
                *(float *)(v129 + 4) = v235;
                *(float *)(v129 + 8) = *(float *)v129;
                *(float *)(v129 + 12) = v180;
                *(float *)(v129 + 24) = *(float *)(v129 + 16);
                *(float *)(v129 + 28) = *(float *)(v129 + 20);
              }
            }
            ++*(_DWORD *)(LODWORD(v214) + 8);
            v113 = *(unsigned __int16 **)&v188.nReferenceCount;
            v108 = HIDWORD(v206);
            v114 = v211;
            goto LABEL_318;
          }
        }
        break;
      }
      result = v233 + 1;
      v233 = result;
      if ( result > v209 )
        return result;
    }
    LODWORD(v236) = *(__int16 *)(LODWORD(v213) + 28);
    v103 = (double)SLODWORD(v236);
    LODWORD(v236) = *(__int16 *)(LODWORD(v213) + 30);
    v215 = v215 + v103;
    v104 = (double)SLODWORD(v236);
    v216 = v216 + v104;
    v217 = v103 + v217;
    v218 = v104 + v218;
LABEL_235:
    LODWORD(v100) = LODWORD(v213) + 12;
    goto LABEL_236;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F9B30
// Name: public: class GFxShapeBase __near * GFxFontCacheManagerImpl::GetGlyphShape(class GFxFontResource __near *,unsigned int,unsigned int,bool,bool,float,float,unsigned int,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxShapeBase *__thiscall GFxFontCacheManagerImpl::GetGlyphShape(
        _RTL_CRITICAL_SECTION *this,
        GFxFontResource *a2,
        unsigned int a3,
        unsigned int a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        struct GFxLog *a10)
{
  _RTL_CRITICAL_SECTION *v11; // edi
  struct GFxShapeBase *GlyphShape_NoLock; // esi

  v11 = this + 106;
  EnterCriticalSection(lpCriticalSection: this + 106);
  GlyphShape_NoLock = GFxFontCacheManagerImpl::GetGlyphShape_NoLock(
                        (GFxFontCacheManagerImpl *)this,
                        (unsigned int)a2,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10: *(float *)&a10);
  LeaveCriticalSection(lpCriticalSection: v11);
  return GlyphShape_NoLock;
}

//------------------------------------------------------------------------------
// Address: 0x100F9BF0
// Name: public: struct GFxBatchPackage __near * GFxFontCacheManagerImpl::CreateBatchPackage(class GMemoryHeap __near *,struct GFxBatchPackage __near *,class GFxTextLineBuffer::Iterator const __near &,class GFxDisplayContext __near &,class GPoint<float> const __near &,struct GFxLineBufferGeometry __near *,struct GFxTextFieldParam const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GFxFontCacheManagerImpl::CreateBatchPackage(
        GFxFontCacheManagerImpl *this,
        int a2,
        int a3,
        int a4,
        int a5,
        float *a6,
        int a7,
        int a8,
        unsigned int a9)
{
  GFxAmpViewStats *v10; // ecx
  int v11; // eax
  unsigned int *v12; // edi
  void *v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  GFxBatchPackageData *v18; // ecx
  int (__thiscall *v19)(int, int, int *); // edx
  GFxBatchPackageData *v20; // eax
  GFxBatchPackageData *v21; // edi
  int (__thiscall *v22)(int, int, int *); // eax
  int v23; // eax
  void *v24; // ecx
  __int64 v25; // rax
  __int64 v27; // [esp+Ch] [ebp-48h]
  int v28; // [esp+14h] [ebp-40h]
  int v29; // [esp+38h] [ebp-1Ch]
  int v30; // [esp+3Ch] [ebp-18h] BYREF
  _DWORD v31[4]; // [esp+40h] [ebp-14h] BYREF

  v29 = a2;
  v10 = *(GFxAmpViewStats **)(a5 + 144);
  v11 = 0;
  v12 = (unsigned int *)a3;
  v28 = (int)v10;
  if ( v10 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v10, swdHandle: 1u, swfOffset: 8u);
    GTimer::GetRawTicks(li: v13);
    HIDWORD(v27) = v14;
  }
  else
  {
    HIDWORD(v27) = 0;
  }
  LODWORD(v27) = v11;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 106);
  if ( a2 == 0 )
    v29 = *(_DWORD *)this;
  v15 = *(_DWORD *)(*(_DWORD *)(a5 + 72) + 12);
  v16 = *((_DWORD *)this + 1);
  v30 = v15;
  if ( v16 != v15 )
  {
    if ( v16 != 0 )
    {
      GFxFontCacheManagerImpl::InvalidateAll(this, a2: (void **)this);
      v15 = v30;
    }
    *((_DWORD *)this + 1) = v15;
    *((_BYTE *)this + 36) = 0;
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v15 + 4))(a1: v15, a2: v31);
    if ( (v31[0] & 0x60000) != 0 )
    {
      v17 = *((_DWORD *)this + 1);
      *((_BYTE *)this + 36) = 1;
      (*(void (__thiscall **)(int, char *))(*(_DWORD *)v17 + 192))(a1: v17, a2: (char *)this + 16);
    }
  }
  if ( a3 == 0 )
    goto LABEL_21;
  if ( *(GFxFontCacheManagerImpl **)(a3 + 12) != this )
  {
    v21 = *(GFxBatchPackageData **)(a3 + 8);
    if ( v21 != nullptr )
      GFxBatchPackageData::`scalar deleting destructor'(this: v21, a2: 1u);
LABEL_21:
    v12 = GListAllocBase<GFxBatchPackage,127,GAllocatorLH_POD<GFxBatchPackage,194>>::Alloc(this: (unsigned int *)this + 12);
    v12[3] = (unsigned int)this;
    v22 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v29 + 40);
    v30 = 194;
    v23 = v22(a1: v29, a2: 80, a3: &v30);
    if ( v23 != 0 )
    {
      *(_DWORD *)v23 = 0;
      *(_DWORD *)(v23 + 4) = 0;
      *(_DWORD *)(v23 + 8) = 0;
      *(_DWORD *)(v23 + 12) = 0;
      *(_DWORD *)(v23 + 16) = 0;
      *(_DWORD *)(v23 + 20) = 0;
      *(_DWORD *)(v23 + 24) = 0;
      *(float *)(v23 + 36) = 6.0;
      *(_DWORD *)(v23 + 28) = 0;
      *(float *)(v23 + 40) = 12.0;
      *(_DWORD *)(v23 + 32) = 0;
      *(_DWORD *)(v23 + 44) = 0;
      *(float *)(v23 + 48) = 1.0;
      *(float *)(v23 + 52) = 1.0;
      *(_DWORD *)(v23 + 56) = 0;
      *(_WORD *)(v23 + 76) = 0;
    }
    else
    {
      v23 = 0;
    }
    v12[2] = v23;
    *v12 = *((_DWORD *)this + 17);
    v12[1] = (unsigned int)this + 68;
    *(_DWORD *)(*((_DWORD *)this + 17) + 4) = v12;
    *((_DWORD *)this + 17) = v12;
    goto LABEL_25;
  }
  v18 = *(GFxBatchPackageData **)(a3 + 8);
  if ( v18 != nullptr )
  {
    if ( a9 != 0 )
      GFxBatchPackageData::Clear(this: v18);
  }
  else
  {
    v19 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v29 + 40);
    v30 = 194;
    v20 = (GFxBatchPackageData *)v19(a1: v29, a2: 80, a3: &v30);
    if ( v20 != nullptr )
      *(_DWORD *)(a3 + 8) = GFxBatchPackageData::GFxBatchPackageData(this: v20);
    else
      *(_DWORD *)(a3 + 8) = 0;
  }
LABEL_25:
  GFxFontCacheManagerImpl::fillBatchPackage(
    this,
    a2: (int *)v12[2],
    a3: a4,
    a4: a5,
    a5: a6,
    a6: a7,
    a7: *(float *)&a8,
    a8: a9);
  GFxGlyphRasterCache::UpdateTextures(
    this: (GFxFontCacheManagerImpl *)((char *)this + 76),
    a2: *(struct GRenderer **)(*(_DWORD *)(a5 + 72) + 12));
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this + 106);
  if ( v28 != 0 )
  {
    GTimer::GetRawTicks(li: v24);
    GFxAmpViewStats::PopCallstack(this: v28, result: (GImageInfo *)1, swfOffset: 8u, funcTime: v25 - v27);
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10174940
// Name: public: union GFxTextLineBuffer::GFxFormatDataEntry __near * GFxTextLineBuffer::Line::GetFormatData(void)const
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall GFxTextLineBuffer::Line::GetFormatData(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  char *v1; // eax
  int v3; // ecx

  v1 = (char *)this + 30;
  if ( (int)this->m_pAllocator < 0 )
  {
    v3 = *((unsigned __int8 *)this + 28);
  }
  else
  {
    v1 = (char *)this + 42;
    v3 = *((_DWORD *)this + 1);
  }
  return (CFunctor *)((unsigned int)&v1[8 * v3 + 3] & 0xFFFFFFFC);
}

//------------------------------------------------------------------------------
// Address: 0x1017EA70
// Name: public: struct GFxGlyphDynaSlot __near * GListAllocBase<struct GFxGlyphDynaSlot,127,struct GAllocatorLH_POD<struct GFxGlyphDynaSlot,195>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GListAllocBase<GFxGlyphDynaSlot,127,GAllocatorLH_POD<GFxGlyphDynaSlot,195>>::Alloc(
        unsigned int *this)
{
  unsigned int *result; // eax
  unsigned int v3; // ecx
  int v4; // eax
  const void *v5; // eax
  int v6; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  result = (unsigned int *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x7F )
    {
      v5 = (const void *)*(this + 4);
      v7 = 195;
      result = (unsigned int *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v5,
                                 a3: 5084,
                                 a4: &v7);
      result[1270] = 0;
      v6 = *(this + 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 5080) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      v4 = *(this + 1);
      *(this + 2) = v3 + 1;
      return (unsigned int *)(v4 + 40 * v3);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017EB00
// Name: public: struct GFxGlyphNode __near * GListAllocBase<struct GFxGlyphNode,127,struct GAllocatorLH_POD<struct GFxGlyphNode,195>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(unsigned int *this)
{
  unsigned int *result; // eax
  unsigned int v3; // ecx
  int v4; // eax
  const void *v5; // eax
  int v6; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  result = (unsigned int *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v3 = *(this + 2);
    if ( v3 >= 0x7F )
    {
      v5 = (const void *)*(this + 4);
      v7 = 195;
      result = (unsigned int *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v5,
                                 a3: 4576,
                                 a4: &v7);
      result[1143] = 0;
      v6 = *(this + 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 4572) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      v4 = *(this + 1);
      *(this + 2) = v3 + 1;
      return (unsigned int *)(v4 + 36 * v3);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10180F50
// Name: public: struct GFxGlyphNode __near * GListAllocBase<struct GFxGlyphNode,127,struct GAllocatorLH_POD<struct GFxGlyphNode,195>>::Alloc(struct GFxGlyphNode const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GListAllocBase<GFxGlyphNode,127,GAllocatorLH_POD<GFxGlyphNode,195>>::Alloc(
        unsigned int *this,
        int a2)
{
  _DWORD *result; // eax
  unsigned int v4; // ecx
  const void *v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  int v8; // [esp+4h] [ebp-4h] BYREF

  result = (_DWORD *)*(this + 3);
  if ( result != nullptr )
  {
    *(this + 3) = *result;
  }
  else
  {
    v4 = *(this + 2);
    if ( v4 >= 0x7F )
    {
      v5 = (const void *)*(this + 4);
      v8 = 195;
      result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v5, a3: 4576, a4: &v8);
      result[1143] = 0;
      v6 = *(this + 1);
      if ( v6 != 0 )
        *(_DWORD *)(v6 + 4572) = result;
      else
        *this = (unsigned int)result;
      *(this + 1) = (unsigned int)result;
      *(this + 2) = 1;
    }
    else
    {
      result = (_DWORD *)(*(this + 1) + 36 * v4);
      *(this + 2) = v4 + 1;
    }
  }
  *result = *(_DWORD *)a2;
  result[1] = *(_DWORD *)(a2 + 4);
  result[2] = *(_DWORD *)(a2 + 8);
  result[3] = *(_DWORD *)(a2 + 12);
  result[4] = *(_DWORD *)(a2 + 16);
  result[5] = *(_DWORD *)(a2 + 20);
  result[6] = *(_DWORD *)(a2 + 24);
  result[7] = *(_DWORD *)(a2 + 28);
  v7 = *(_WORD *)(a2 + 34);
  *((_WORD *)result + 16) = *(_WORD *)(a2 + 32);
  *((_WORD *)result + 17) = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017EB90
// Name: void GFx_RecursiveBlur<class GFxImgBlurWrapperX,class GArrayUnsafeLH_POD<float,195>,class GArrayUnsafeLH_POD<unsigned char,195>>(class GFxImgBlurWrapperX __near &,float,class GArrayUnsafeLH_POD<float,195> __near &,class GArrayUnsafeLH_POD<unsigned char,195> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GFx_RecursiveBlur<GFxImgBlurWrapperX,GArrayUnsafeLH_POD<float,195>,GArrayUnsafeLH_POD<unsigned char,195>>(
        _DWORD *a1,
        float a2,
        int a3,
        _DWORD *a4)
{
  signed int v5; // ebx
  signed int v6; // edi
  double v7; // st6
  double v8; // st7
  double v9; // st6
  double v10; // rt1
  double v11; // rt2
  double v12; // st6
  double v13; // st5
  double v14; // st4
  double v15; // st3
  _DWORD *v16; // ebx
  void *v17; // eax
  float **v18; // ecx
  float *v19; // eax
  int v20; // ebx
  double v21; // st7
  double v22; // st6
  double v23; // st5
  double v24; // st4
  double v25; // st3
  double v26; // st2
  double v27; // st1
  int v28; // ecx
  float *v29; // eax
  unsigned __int8 v30; // dl
  double v31; // st3
  unsigned __int8 v32; // dl
  double v33; // st3
  unsigned __int8 v34; // dl
  double v35; // st3
  unsigned __int8 v36; // dl
  float v37; // edx
  unsigned __int8 v38; // al
  double v39; // st3
  float *v40; // edx
  double v41; // st3
  double v42; // st3
  _DWORD *v43; // eax
  int v44; // ecx
  float *v45; // edx
  _DWORD *v46; // ebx
  double v47; // st2
  double v48; // [esp+14h] [ebp-24h]
  int v49; // [esp+1Ch] [ebp-1Ch]
  float v50; // [esp+20h] [ebp-18h]
  float *v51; // [esp+24h] [ebp-14h]
  float v52; // [esp+28h] [ebp-10h]
  float v53; // [esp+28h] [ebp-10h]
  float v54; // [esp+2Ch] [ebp-Ch]
  float v55; // [esp+2Ch] [ebp-Ch]
  float v56; // [esp+30h] [ebp-8h]
  float v57; // [esp+30h] [ebp-8h]
  signed int count; // [esp+34h] [ebp-4h]
  float v59; // [esp+40h] [ebp+8h]
  int v60; // [esp+40h] [ebp+8h]

  if ( a2 < 0.62 )
    a2 = 0.62;
  v5 = a1[3];
  count = v5;
  v49 = a1[4];
  v59 = ceil(X: a2);
  v6 = v5 + (int)v59;
  if ( v6 >= 3 )
  {
    a2 = a2 * 0.5;
    v7 = a2;
    if ( a2 >= 2.5 )
    {
      v10 = v7 * 0.9871100187301636 - 0.9632999897003174;
      v9 = 1.0;
      v8 = v10;
    }
    else
    {
      a2 = 1.0 - v7 * 0.2689099907875061;
      a2 = sqrt(a2);
      v8 = 3.971560001373291 - a2 * 4.145540237426758;
      v9 = 1.0;
    }
    v11 = v9;
    a2 = v8;
    v12 = a2;
    a2 = a2 * a2;
    v13 = a2;
    a2 = a2 * v12;
    v14 = a2;
    v15 = 0.422205001115799 * a2;
    a2 = v11 / (v13 * 1.428099989891052 + v12 * 2.444129943847656 + 1.578250050544739 + v15);
    v52 = v12 * 2.444129943847656 + v13 * 2.856189966201782 + v14 * 1.266610026359558;
    v54 = v13 * -1.428099989891052 - v14 * 1.266610026359558;
    v56 = v15;
    v50 = v11 - (v54 + v52 + v56) * a2;
    v53 = v52 * a2;
    v55 = v54 * a2;
    v57 = a2 * v56;
    GArrayUnsafeBase<float,GAllocatorLH_POD<float,195>>::Reserve(a1: 2 * v6, a2: 0);
    *(_DWORD *)(a3 + 4) = 2 * v6;
    v16 = a4;
    if ( (unsigned int)v6 > a4[2] )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*a4);
      v16[2] = v6;
      if ( v6 != 0 )
      {
        LODWORD(a2) = 195;
        v17 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v16, a3: v6, a4: &a2);
      }
      else
      {
        v17 = nullptr;
      }
      *v16 = v17;
    }
    v18 = (float **)a3;
    v16[1] = v6;
    v19 = *v18;
    v20 = 0;
    v51 = *v18;
    v60 = 0;
    if ( v49 > 0 )
    {
      v21 = v53;
      v22 = v55;
      v23 = v57;
      v24 = v50;
      while ( 1 )
      {
        LODWORD(a2) = *(unsigned __int8 *)(*(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v20 + a1[2]) + a1[1]);
        a2 = (double)SLODWORD(a2) * v23
           + v24 * (double)SLODWORD(a2)
           + v21 * (double)SLODWORD(a2)
           + v22 * (double)SLODWORD(a2);
        v25 = a2;
        *v19 = a2;
        v48 = v25 * v23;
        LODWORD(a2) = *(unsigned __int8 *)(*(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v20 + a1[2]) + a1[1] + 1);
        a2 = v25 * v21 + (double)SLODWORD(a2) * v24 + v25 * v22 + v48;
        v26 = a2;
        v19[1] = a2;
        LODWORD(a2) = *(unsigned __int8 *)(*(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v20 + a1[2]) + a1[1] + 2);
        v27 = (double)SLODWORD(a2);
        LODWORD(a2) = v19 + 2;
        v19[2] = v25 * v22 + v26 * v21 + v27 * v24 + v48;
        v28 = 3;
        if ( v6 > 3 )
        {
          if ( v6 - 3 >= 4 )
          {
            v29 = (float *)LODWORD(a2);
            do
            {
              if ( v28 >= count )
              {
                v30 = 0;
              }
              else
              {
                LODWORD(a2) = *a1 + 8;
                v30 = *(_BYTE *)(v28
                               + *(_DWORD *)(LODWORD(a2) + 16)
                               + *(_DWORD *)(LODWORD(a2) + 12) * (v20 + a1[2])
                               + a1[1]);
              }
              v31 = *v29 * v21;
              LODWORD(a2) = v30;
              v29[1] = v31 + (double)v30 * v24 + *(v29 - 1) * v22 + *(v29 - 2) * v23;
              if ( v28 + 1 >= count )
                v32 = 0;
              else
                v32 = *(_BYTE *)(v28 + *(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v60 + a1[2]) + a1[1] + 1);
              v33 = v29[1] * v21;
              LODWORD(a2) = v32;
              v29[2] = v33 + (double)v32 * v24 + *v29 * v22 + *(v29 - 1) * v23;
              if ( v28 + 2 >= count )
                v34 = 0;
              else
                v34 = *(_BYTE *)(v28 + *(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v60 + a1[2]) + a1[1] + 2);
              v35 = v29[2] * v21;
              LODWORD(a2) = v34;
              v29[3] = v35 + (double)v34 * v24 + v29[1] * v22 + *v29 * v23;
              if ( v28 + 3 >= count )
                v36 = 0;
              else
                v36 = *(_BYTE *)(v28 + *(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v60 + a1[2]) + a1[1] + 3);
              LODWORD(a2) = v36;
              v20 = v60;
              v28 += 4;
              v29 += 4;
              *v29 = (double)v36 * v24 + v21 * *(v29 - 1) + *(v29 - 2) * v22 + *(v29 - 3) * v23;
            }
            while ( v28 < v6 - 3 );
            v19 = v51;
          }
          if ( v28 < v6 )
          {
            LODWORD(v37) = &v19[v28 - 2];
            a2 = v37;
            do
            {
              if ( v28 >= count )
              {
                v38 = 0;
              }
              else
              {
                v38 = *(_BYTE *)(v28 + *(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v20 + a1[2]) + a1[1]);
                v37 = a2;
              }
              v39 = *(float *)(LODWORD(v37) + 4) * v21;
              ++v28;
              LODWORD(v37) += 4;
              a2 = v37;
              *(float *)(LODWORD(v37) + 4) = v39
                                           + (double)v38 * v24
                                           + *(float *)(LODWORD(v37) - 4) * v22
                                           + *(float *)(LODWORD(v37) - 8) * v23;
            }
            while ( v28 < v6 );
            v19 = v51;
          }
        }
        v40 = &v19[v6];
        a2 = *(v40 - 1) * v24 + *(v40 - 1) * v21 + *(v40 - 1) * v22 + *(v40 - 1) * v23;
        v41 = a2;
        v40[v6 - 1] = a2;
        a2 = v41 * v23 + *(v40 - 2) * v24 + v41 * v21 + v41 * v22;
        v42 = a2;
        v40[v6 - 2] = a2;
        v43 = a4;
        v40[v6 - 3] = v42 * v21 + v24 * *(v40 - 3) + v40[v6 - 1] * v22 + v40[v6 - 1] * v23;
        *(_BYTE *)(*v43 + v6 - 1) = (int)(v40[v6 - 1] + 0.5);
        *(_BYTE *)(*a4 + v6 - 2) = (int)(v40[v6 - 2] + 0.5);
        *(_BYTE *)(*a4 + v6 - 3) = (int)(v40[v6 - 3] + 0.5);
        v44 = v6 - 4;
        if ( v6 - 4 >= 0 )
        {
          v45 = &v40[v44 + 2];
          do
          {
            v46 = a4;
            --v45;
            a2 = v51[v44] * v24 + *v45 * v21 + v45[1] * v22 + v45[2] * v23;
            v47 = a2;
            *(v45 - 1) = a2;
            *(_BYTE *)(--v44 + *v46 + 1) = (int)(v47 + 0.5);
          }
          while ( v44 >= 0 );
          v20 = v60;
        }
        memcpy(
          dst: (unsigned __int8 *)(a1[1] + *(_DWORD *)(*a1 + 24) + *(_DWORD *)(*a1 + 20) * (v20 + a1[2])),
          src: (unsigned __int8 *)*a4,
          count);
        v60 = ++v20;
        if ( v20 >= v49 )
          break;
        v19 = v51;
        v21 = v53;
        v22 = v55;
        v24 = v50;
        v23 = v57;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F170
// Name: void GFx_RecursiveBlur<class GFxImgBlurWrapperY,class GArrayUnsafeLH_POD<float,195>,class GArrayUnsafeLH_POD<unsigned char,195>>(class GFxImgBlurWrapperY __near &,float,class GArrayUnsafeLH_POD<float,195> __near &,class GArrayUnsafeLH_POD<unsigned char,195> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl GFx_RecursiveBlur<GFxImgBlurWrapperY,GArrayUnsafeLH_POD<float,195>,GArrayUnsafeLH_POD<unsigned char,195>>(
        int a1,
        float a2,
        int a3,
        float *a4)
{
  _DWORD *v4; // esi
  float v5; // ebx
  int result; // eax
  signed int v7; // edi
  double v8; // st6
  double v9; // st7
  double v10; // st6
  double v11; // rt1
  double v12; // rt2
  double v13; // st6
  double v14; // st5
  double v15; // st3
  double v16; // rt1
  float *v17; // ebx
  float **v18; // ecx
  float *v19; // ebx
  int v20; // ecx
  double v21; // st7
  double v22; // st6
  double v23; // st5
  double v24; // st4
  double v25; // st3
  double v26; // st2
  int v27; // ecx
  float *v28; // eax
  unsigned __int8 v29; // dl
  double v30; // st3
  unsigned __int8 v31; // dl
  double v32; // st3
  unsigned __int8 v33; // dl
  double v34; // st3
  unsigned __int8 v35; // dl
  float v36; // eax
  unsigned __int8 v37; // dl
  double v38; // st3
  float *v39; // edx
  float *v40; // ecx
  double v41; // st3
  double v42; // st3
  int v43; // ecx
  float *v44; // edx
  double v45; // st2
  float *v46; // ebx
  double v47; // st2
  _BYTE *v48; // edx
  int v49; // ecx
  _BYTE *v50; // eax
  double v51; // [esp+14h] [ebp-1Ch]
  float v52; // [esp+18h] [ebp-18h]
  int v53; // [esp+1Ch] [ebp-14h]
  float *v54; // [esp+20h] [ebp-10h]
  float v55; // [esp+24h] [ebp-Ch]
  float v56; // [esp+24h] [ebp-Ch]
  float v57; // [esp+28h] [ebp-8h]
  float v58; // [esp+28h] [ebp-8h]
  float v59; // [esp+2Ch] [ebp-4h]

  if ( a2 < 0.62 )
    a2 = 0.62;
  v4 = (_DWORD *)a1;
  v5 = *(float *)(a1 + 16);
  v59 = v5;
  v53 = *(_DWORD *)(a1 + 12);
  *(float *)&a1 = ceil(X: a2);
  result = (int)*(float *)&a1;
  v7 = LODWORD(v5) + result;
  if ( LODWORD(v5) + result >= 3 )
  {
    a2 = a2 * 0.5;
    v8 = a2;
    if ( a2 >= 2.5 )
    {
      v11 = v8 * 0.9871100187301636 - 0.9632999897003174;
      v10 = 1.0;
      v9 = v11;
    }
    else
    {
      a2 = 1.0 - v8 * 0.2689099907875061;
      a2 = sqrt(a2);
      v9 = 3.971560001373291 - a2 * 4.145540237426758;
      v10 = 1.0;
    }
    v12 = v10;
    a2 = v9;
    v13 = a2;
    a2 = a2 * a2;
    v14 = a2;
    a2 = a2 * v13;
    v15 = 0.422205001115799 * a2;
    *(float *)&a1 = v12 / (v14 * 1.428099989891052 + v13 * 2.444129943847656 + 1.578250050544739 + v15);
    v16 = a2 * 1.266610026359558;
    a2 = v13 * 2.444129943847656 + v14 * 2.856189966201782 + v16;
    v57 = v14 * -1.428099989891052 - v16;
    v55 = v15;
    v52 = v12 - (v57 + a2 + v55) * *(float *)&a1;
    a2 = a2 * *(float *)&a1;
    v58 = v57 * *(float *)&a1;
    v56 = *(float *)&a1 * v55;
    *(float *)&result = COERCE_FLOAT(GArrayUnsafeBase<float,GAllocatorLH_POD<float,195>>::Reserve(a1: 2 * v7, a2: 0));
    *(_DWORD *)(a3 + 4) = 2 * v7;
    v17 = a4;
    if ( (unsigned int)v7 > *((_DWORD *)a4 + 2) )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)a4);
      *((_DWORD *)v17 + 2) = v7;
      if ( v7 != 0 )
      {
        a1 = 195;
        *(float *)&result = COERCE_FLOAT((int)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                this: GMemory::pGlobalHeap,
                                                a2: v17,
                                                a3: v7,
                                                a4: &a1));
      }
      else
      {
        *(float *)&result = 0.0;
      }
      *v17 = *(float *)&result;
    }
    v18 = (float **)a3;
    *((_DWORD *)v17 + 1) = v7;
    v19 = *v18;
    v20 = 0;
    v54 = v19;
    *(float *)&a1 = 0.0;
    if ( v53 > 0 )
    {
      v21 = a2;
      v22 = v58;
      v23 = v56;
      v24 = v52;
      while ( 1 )
      {
        LODWORD(a2) = *(unsigned __int8 *)(v4[1] + *(_DWORD *)(*v4 + 24) + v4[2] * *(_DWORD *)(*v4 + 20) + v20);
        a2 = (double)SLODWORD(a2) * v23
           + v24 * (double)SLODWORD(a2)
           + v21 * (double)SLODWORD(a2)
           + v22 * (double)SLODWORD(a2);
        v25 = a2;
        *v19 = a2;
        v51 = v25 * v23;
        LODWORD(a2) = *(unsigned __int8 *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v4[2] + 1) + v20);
        a2 = v25 * v21 + (double)SLODWORD(a2) * v24 + v25 * v22 + v51;
        v26 = a2;
        v19[1] = a2;
        LODWORD(a2) = *(unsigned __int8 *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v4[2] + 2) + v20);
        v27 = 3;
        v28 = v19 + 2;
        v19[2] = v25 * v22 + v26 * v21 + (double)SLODWORD(a2) * v24 + v51;
        if ( v7 > 3 )
        {
          if ( v7 - 3 >= 4 )
          {
            do
            {
              if ( v27 >= SLODWORD(v59) )
                v29 = 0;
              else
                v29 = *(_BYTE *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v27 + v4[2]) + a1);
              v30 = *v28 * v21;
              LODWORD(a2) = v29;
              v28[1] = v30 + (double)v29 * v24 + *(v28 - 1) * v22 + *(v28 - 2) * v23;
              if ( v27 + 1 >= SLODWORD(v59) )
                v31 = 0;
              else
                v31 = *(_BYTE *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v4[2] + v27 + 1) + a1);
              v32 = v28[1] * v21;
              LODWORD(a2) = v31;
              v28[2] = v32 + (double)v31 * v24 + *v28 * v22 + *(v28 - 1) * v23;
              if ( v27 + 2 >= SLODWORD(v59) )
                v33 = 0;
              else
                v33 = *(_BYTE *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v4[2] + v27 + 2) + a1);
              v34 = v28[2] * v21;
              LODWORD(a2) = v33;
              v28[3] = v34 + (double)v33 * v24 + v28[1] * v22 + *v28 * v23;
              if ( v27 + 3 >= SLODWORD(v59) )
                v35 = 0;
              else
                v35 = *(_BYTE *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v4[2] + v27 + 3) + a1);
              LODWORD(a2) = v35;
              v27 += 4;
              v28 += 4;
              *v28 = (double)v35 * v24 + v21 * *(v28 - 1) + *(v28 - 2) * v22 + *(v28 - 3) * v23;
            }
            while ( v27 < v7 - 3 );
            v19 = v54;
          }
          if ( v27 < v7 )
          {
            LODWORD(v36) = &v19[v27 - 2];
            a2 = v36;
            do
            {
              if ( v27 >= SLODWORD(v59) )
              {
                v37 = 0;
              }
              else
              {
                v37 = *(_BYTE *)(v4[1] + *(_DWORD *)(*v4 + 24) + *(_DWORD *)(*v4 + 20) * (v27 + v4[2]) + a1);
                v36 = a2;
              }
              v38 = *(float *)(LODWORD(v36) + 4) * v21;
              ++v27;
              LODWORD(v36) += 4;
              a2 = v36;
              *(float *)(LODWORD(v36) + 4) = v38
                                           + (double)v37 * v24
                                           + *(float *)(LODWORD(v36) - 4) * v22
                                           + *(float *)(LODWORD(v36) - 8) * v23;
            }
            while ( v27 < v7 );
          }
        }
        v39 = &v19[v7];
        v40 = a4;
        a2 = v24 * *(v39 - 1) + v21 * *(v39 - 1) + v22 * *(v39 - 1) + v23 * *(v39 - 1);
        v41 = a2;
        v39[v7 - 1] = a2;
        a2 = v41 * v23 + v41 * v21 + *(v39 - 2) * v24 + v41 * v22;
        v42 = a2;
        v39[v7 - 2] = a2;
        v39[v7 - 3] = v42 * v21 + *(v39 - 3) * v24 + v39[v7 - 1] * v22 + v39[v7 - 1] * v23;
        *(_BYTE *)(*(_DWORD *)v40 + v7 - 1) = (int)(v39[v7 - 1] + 0.5);
        *(_BYTE *)(*(_DWORD *)a4 + v7 - 2) = (int)(v39[v7 - 2] + 0.5);
        *(_BYTE *)(*(_DWORD *)a4 + v7 - 3) = (int)(v39[v7 - 3] + 0.5);
        v43 = v7 - 4;
        if ( v7 - 4 >= 0 )
        {
          v44 = &v39[v43 + 2];
          do
          {
            v45 = v19[v43];
            v46 = a4;
            --v44;
            a2 = v45 * v24 + *v44 * v21 + v44[1] * v22 + v44[2] * v23;
            v47 = a2;
            *(v44 - 1) = a2;
            *(_BYTE *)(--v43 + *(_DWORD *)v46 + 1) = (int)(v47 + 0.5);
            v19 = v54;
          }
          while ( v43 >= 0 );
        }
        v48 = *(_BYTE **)a4;
        v49 = *v4;
        a2 = v59;
        v50 = (_BYTE *)(a1 + v4[1] + *(_DWORD *)(v49 + 24) + v4[2] * *(_DWORD *)(v49 + 20));
        do
        {
          *v50 = *v48;
          v50 += *(_DWORD *)(*v4 + 20);
          ++v48;
          --LODWORD(a2);
        }
        while ( a2 != 0.0 );
        result = a1 + 1;
        a1 = result;
        if ( result >= v53 )
          break;
        v20 = a1;
      }
    }
  }
  return result;
}
