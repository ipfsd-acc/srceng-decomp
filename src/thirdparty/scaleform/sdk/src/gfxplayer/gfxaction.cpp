// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxaction.cpp
// Functions: 315
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxaction.h"

//------------------------------------------------------------------------------
// Address: 0x100662C0
// Name: private: bool GArrayPagedBase<class GRefCountBaseGC<323> __near *,10,5,struct GAllocatorPagedLH_POD<class GRefCountBaseGC<323> __near *,2>>::allocatePageSafe(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::allocatePageSafe(
        ISteamMatchmakingPingResponse *this,
        unsigned int nb)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax

  v3 = *((_DWORD *)this + 2);
  v4 = nb;
  if ( nb < v3 )
    goto LABEL_8;
  v5 = *((void **)this + 3);
  if ( v5 != nullptr )
  {
    v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 20);
  }
  else
  {
    nb = 2;
    v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 20, a4: &nb);
  }
  if ( v6 != nullptr )
  {
    *((_DWORD *)this + 2) += 5;
    *((_DWORD *)this + 3) = v6;
LABEL_8:
    nb = 2;
    *(_DWORD *)(*((_DWORD *)this + 3) + 4 * v4) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                    this: GMemory::pGlobalHeap,
                                                    a2: this,
                                                    a3: 4096,
                                                    a4: &nb);
    if ( *(_DWORD *)(*((_DWORD *)this + 3) + 4 * v4) != 0 )
      ++*((_DWORD *)this + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067C70
// Name: public: void GArrayPagedBase<class GRefCountBaseGC<323> __near *,10,5,struct GAllocatorPagedLH_POD<class GRefCountBaseGC<323> __near *,2>>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::Resize@<eax>(
        GAtomicValueBase<long> *this@<ecx>,
        volatile unsigned int newSize,
        int newNumPages)
{
  volatile int result; // eax
  volatile unsigned int Value; // ecx
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  void *v9; // eax
  void *v10; // eax
  int v11; // [esp+4h] [ebp-8h] BYREF
  unsigned int newNumPagesa; // [esp+8h] [ebp-4h]

  result = newSize;
  Value = this->Value;
  if ( newSize <= Value )
  {
    if ( newSize < Value )
      this->Value = newSize;
  }
  else
  {
    v6 = *((_DWORD *)this + 1);
    v7 = (newSize + 1023) >> 10;
    newNumPagesa = v7;
    if ( v6 < v7 )
    {
      do
      {
        v8 = *((_DWORD *)this + 2);
        if ( v6 >= v8 )
        {
          v9 = *((void **)this + 3);
          if ( v9 != nullptr )
          {
            v10 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v9, a3: 4 * v8 + 20);
            v7 = newNumPagesa;
          }
          else
          {
            v11 = 2;
            v10 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 20, a4: &v11);
          }
          *((_DWORD *)this + 2) += 5;
          *((_DWORD *)this + 3) = v10;
        }
        v11 = 2;
        *(_DWORD *)(*((_DWORD *)this + 3) + 4 * v6) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                        this: GMemory::pGlobalHeap,
                                                        a2: this,
                                                        a3: 4096,
                                                        a4: &v11);
        ++*((_DWORD *)this + 1);
        ++v6;
      }
      while ( v6 < v7 );
      result = newSize;
    }
    this->Value = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067EE0
// Name: public: bool GArrayPagedBase<class GRefCountBaseGC<323> __near *,10,5,struct GAllocatorPagedLH_POD<class GRefCountBaseGC<323> __near *,2>>::PushBackSafe(class GRefCountBaseGC<323> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::PushBackSafe(
        GAtomicValueBase<long> *this,
        _DWORD *a2)
{
  unsigned int v3; // edi
  char v4; // al
  _DWORD *v5; // eax

  v3 = (unsigned int)this->Value >> 10;
  if ( v3 >= *((_DWORD *)this + 1) )
  {
    GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::allocatePageSafe(
      (ISteamMatchmakingPingResponse *)this,
      nb: (unsigned int)this->Value >> 10);
    if ( v4 == 0 )
      return 0;
  }
  v5 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 3) + 4 * v3) + 4 * (this->Value & 0x3FF));
  if ( v5 == nullptr )
    return 0;
  *v5 = *a2;
  ++this->Value;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006D1A0
// Name: public: GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>(
        float *this,
        int a2)
{
  *this = *(float *)a2;
  *(this + 1) = *(float *)(a2 + 4);
  GStringLH::CopyConstructHelper(result: (const CFixedBitVecBase<128> *)(a2 + 8));
  GString::GString(result: (CImagePacker *)(a2 + 12));
  *(this + 4) = *(float *)(a2 + 16);
  *(this + 5) = *(float *)(a2 + 20);
  *(this + 6) = *(float *)(a2 + 24);
  *(this + 7) = *(float *)(a2 + 28);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077260
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>(struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>(
        _DWORD *this,
        CImagePacker *result,
        int a3)
{
  _DWORD *v4; // esi
  CVertexBuilder *v5; // esi
  int v6; // ebx
  CImagePacker *m_MaxLightmapHeight; // [esp+14h] [ebp+8h]
  int m_VertexSize_BoneWeight; // [esp+18h] [ebp+Ch]

  v4 = this + 2;
  *this = a3;
  GString::GString(result);
  v5 = (CVertexBuilder *)(v4 + 1);
  v5->m_VertexSize_Position = 0;
  v5->m_VertexSize_BoneWeight = 0;
  v5->m_VertexSize_BoneMatrixIndex = 0;
  v6 = result->m_pLightmapWavefront[0];
  m_MaxLightmapHeight = (CImagePacker *)result->m_MaxLightmapHeight;
  if ( v6 != 0 )
  {
    m_VertexSize_BoneWeight = v5->m_VertexSize_BoneWeight;
    GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v5,
      a2: (int)v5,
      a3: v6 + m_VertexSize_BoneWeight);
    GConstructorMov<GPtr<GFxResource>>::ConstructArray(
      a1: v5->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight,
      a2: v6,
      a3: m_MaxLightmapHeight);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077C40
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>(
        _DWORD *this,
        int a2)
{
  _DWORD *v3; // esi
  CVertexBuilder *v4; // esi
  int v5; // eax
  int m_VertexSize_BoneWeight; // ebx
  int v8; // [esp+Ch] [ebp-4h]
  int v9; // [esp+18h] [ebp+8h]

  *this = *(_DWORD *)a2;
  *(this + 1) = *(_DWORD *)(a2 + 4);
  v3 = this + 2;
  GString::GString(result: (CImagePacker *)(a2 + 8));
  v4 = (CVertexBuilder *)(v3 + 1);
  v4->m_VertexSize_Position = 0;
  v4->m_VertexSize_BoneWeight = 0;
  v4->m_VertexSize_BoneMatrixIndex = 0;
  v5 = *(_DWORD *)(a2 + 16);
  v8 = v5;
  v9 = *(_DWORD *)(a2 + 12);
  if ( v5 != 0 )
  {
    m_VertexSize_BoneWeight = v4->m_VertexSize_BoneWeight;
    GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v4,
      a2: (int)v4,
      a3: m_VertexSize_BoneWeight + v5);
    GConstructorMov<GPtr<GFxResource>>::ConstructArray(
      a1: v4->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight,
      a2: v8,
      a3: v9);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077CB0
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>(struct GHashNode<class GString,class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeRef const __near &,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>(
        _DWORD *this,
        int a2,
        int a3)
{
  _DWORD *v4; // esi
  int *v5; // eax
  CVertexBuilder *v6; // esi
  int v7; // ebx
  int m_VertexSize_BoneWeight; // [esp+14h] [ebp+8h]
  int v10; // [esp+18h] [ebp+Ch]

  *this = a3;
  v4 = this + 2;
  GString::GString(result: *(CImagePacker **)a2);
  v5 = *(int **)(a2 + 4);
  v6 = (CVertexBuilder *)(v4 + 1);
  v6->m_VertexSize_Position = 0;
  v6->m_VertexSize_BoneWeight = 0;
  v6->m_VertexSize_BoneMatrixIndex = 0;
  v7 = v5[1];
  v10 = *v5;
  if ( v7 != 0 )
  {
    m_VertexSize_BoneWeight = v6->m_VertexSize_BoneWeight;
    GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v6,
      a2: (int)v6,
      a3: v7 + m_VertexSize_BoneWeight);
    GConstructorMov<GPtr<GFxResource>>::ConstructArray(
      a1: v6->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight,
      a2: v7,
      a3: v10);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078180
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<class GString,class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,class GArray<class GString,2,struct GArrayDefaultPolicy>,struct GString::NoCaseHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GHashsetCachedNodeEntry<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>,GHashNode<GString,GArray<GString,2,GArrayDefaultPolicy>,GString::NoCaseHashFunctor>::NodeHashF>(
        char *this,
        int a2)
{
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *(_DWORD *)(a2 + 4);
  GString::GString(result: (CImagePacker *)(a2 + 8));
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  GArrayData<GString,GAllocatorGH<GString,2>,GArrayDefaultPolicy>::Append(
    this: (CVertexBuilder *)(this + 12),
    a2: *(CImagePacker **)(a2 + 12),
    result: *(CImagePacker **)(a2 + 16));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086CF0
// Name: public: bool GASStringHashBase<char,class GHashUncachedLH<class GASString,char,struct GASStringHashFunctor,323>>::GetCaseInsensitive(class GASString const __near &,char __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASStringHashBase<char,GHashUncachedLH<GASString,char,GASStringHashFunctor,323>>::GetCaseInsensitive(
        void *this,
        _EXIT_THREAD_DEBUG_INFO *ikey,
        char *pvalue)
{
  _EXIT_THREAD_DEBUG_INFO *v3; // edi
  int v5; // eax
  int v6; // eax

  v3 = ikey;
  if ( *(_DWORD *)(ikey->dwExitCode + 4) == 0 )
    GASStringNode::ResolveLowercase_Impl();
  if ( *(_DWORD *)this == 0 )
    return 0;
  v5 = GHashSetBase<GHashNode<GASString,char,GASStringHashFunctor>,GHashNode<GASString,char,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,char,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,char,GASStringHashFunctor>,GHashNode<GASString,char,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>(
         a1: &ikey,
         a2: *(_DWORD *)(*(_DWORD *)this + 4) & *(_DWORD *)(v3->dwExitCode + 12));
  if ( v5 < 0 )
    return 0;
  v6 = *(_DWORD *)this + 4 * (3 * v5 + 3);
  if ( v6 == 0 )
    return 0;
  if ( pvalue != nullptr )
    *pvalue = *(_BYTE *)(v6 + 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10087670
// Name: public: bool GASStringHashBase<char,class GHashUncachedLH<class GASString,char,struct GASStringHashFunctor,323>>::GetCaseCheck(class GASString const __near &,char __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASStringHashBase<char,GHashUncachedLH<GASString,char,GASStringHashFunctor,323>>::GetCaseCheck(
        int *this,
        _EXIT_THREAD_DEBUG_INFO *ikey,
        char *pvalue,
        char a4)
{
  int v4; // esi
  int Index; // eax
  int v6; // eax

  if ( a4 == 0 )
    return GASStringHashBase<char,GHashUncachedLH<GASString,char,GASStringHashFunctor,323>>::GetCaseInsensitive(
             this,
             ikey,
             pvalue);
  v4 = *this;
  if ( *this == 0 )
    return 0;
  Index = GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
            a1: ikey,
            a2: *(_DWORD *)(v4 + 4) & *(_DWORD *)(ikey->dwExitCode + 12));
  if ( Index < 0 )
    return 0;
  v6 = v4 + 4 * (3 * Index + 3);
  if ( v6 == 0 )
    return 0;
  if ( pvalue != nullptr )
    *pvalue = *(_BYTE *)(v6 + 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10088C00
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GFxEventId,class GArrayLH<class GASValue,323,struct GArrayDefaultPolicy>,struct GFxEventIdHashFunctor>,struct GHashNode<class GFxEventId,class GArrayLH<class GASValue,323,struct GArrayDefaultPolicy>,struct GFxEventIdHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GFxEventId,class GArrayLH<class GASValue,323,struct GArrayDefaultPolicy>,struct GFxEventIdHashFunctor>,struct GHashNode<class GFxEventId,class GArrayLH<class GASValue,323,struct GArrayDefaultPolicy>,struct GFxEventIdHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<class GFxEventId,class GArrayLH<class GASValue,323,struct GArrayDefaultPolicy>,struct GFxEventIdHashFunctor>,struct GHashNode<class GFxEventId,class GArrayLH<class GASValue,323,struct GArrayDefaultPolicy>,struct GFxEventIdHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
IGameEventManager2 *__thiscall GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>(
        IGameEventManager2 *this,
        int a2)
{
  IGameEventManager2 *v3; // ecx

  this->__vftable = *(IGameEventManager2_vtbl **)a2;
  *(this + 1) = *(IGameEventManager2 *)(a2 + 4);
  *(this + 2) = *(IGameEventManager2 *)(a2 + 8);
  *(this + 3) = *(IGameEventManager2 *)(a2 + 12);
  *(this + 4) = *(IGameEventManager2 *)(a2 + 16);
  *(this + 5) = *(IGameEventManager2 *)(a2 + 20);
  v3 = this + 6;
  v3->__vftable = nullptr;
  v3[1].__vftable = nullptr;
  v3[2].__vftable = nullptr;
  GArrayData<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::Append(
    pheapAddr: v3,
    other: *(const UtlRBTreeNode_t<char const *,unsigned short> **)(a2 + 24),
    count: *(_DWORD *)(a2 + 28));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008C290
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<struct GFxAmpViewStats::ParentChildFunctionPair,struct GFxAmpViewStats::AmpFunctionStats,class GFixedSizeHash<struct GFxAmpViewStats::ParentChildFunctionPair>>,struct GHashNode<struct GFxAmpViewStats::ParentChildFunctionPair,struct GFxAmpViewStats::AmpFunctionStats,class GFixedSizeHash<struct GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<struct GFxAmpViewStats::ParentChildFunctionPair,struct GFxAmpViewStats::AmpFunctionStats,class GFixedSizeHash<struct GFxAmpViewStats::ParentChildFunctionPair>>,struct GHashNode<struct GFxAmpViewStats::ParentChildFunctionPair,struct GFxAmpViewStats::AmpFunctionStats,class GFixedSizeHash<struct GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<struct GFxAmpViewStats::ParentChildFunctionPair,struct GFxAmpViewStats::AmpFunctionStats,class GFixedSizeHash<struct GFxAmpViewStats::ParentChildFunctionPair>>,struct GHashNode<struct GFxAmpViewStats::ParentChildFunctionPair,struct GFxAmpViewStats::AmpFunctionStats,class GFixedSizeHash<struct GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>,GHashNode<GFxAmpViewStats::ParentChildFunctionPair,GFxAmpViewStats::AmpFunctionStats,GFixedSizeHash<GFxAmpViewStats::ParentChildFunctionPair>>::NodeHashF>(
        _DWORD *this,
        _DWORD *a2)
{
  *this = *a2;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  *(this + 4) = a2[4];
  *(this + 5) = a2[5];
  *(this + 6) = a2[6];
  *(this + 7) = a2[7];
  *(this + 8) = a2[8];
  *(this + 9) = a2[9];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008F1F0
// Name: public: GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>::NodeHashF>(class GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
const _D3DVIEWPORT9 *__thiscall GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>(
        void *this,
        GRect<int> *result)
{
  unsigned int Top; // eax

  *(_DWORD *)this = result->Left;
  Top = result->Top;
  *((_DWORD *)this + 1) = Top;
  ++*(_DWORD *)(Top + 8);
  GASValue::GASValue(this: (GASValue *)this + 2, a2: (const struct GASValue *)&result->Right);
  *((_BYTE *)this + 9) = BYTE1(result->Right);
  return (const _D3DVIEWPORT9 *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1008F230
// Name: public: void GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASMember,struct GASStringHashFunctor>::NodeHashF>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>::Clear(
        GASValue *this)
{
  int v2; // ecx

  GASValue::~GASValue(this: this + 2);
  v2 = *((_DWORD *)this + 1);
  if ( (*(_DWORD *)(v2 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  *this = (GASValue)-2;
}

//------------------------------------------------------------------------------
// Address: 0x10091180
// Name: public: bool GASStringHashBase<class GASMember,class GHashUncachedLH_GC<class GASString,class GASMember,struct GASStringHashFunctor,323>>::GetCaseInsensitive(class GASString const __near &,class GASMember __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASStringHashBase<GASMember,GHashUncachedLH_GC<GASString,GASMember,GASStringHashFunctor,323>>::GetCaseInsensitive@<al>(
        int a1@<ecx>,
        _EXIT_THREAD_DEBUG_INFO *ikey,
        tagEMRMODIFYWORLDTRANSFORM pvalue)
{
  _EXIT_THREAD_DEBUG_INFO *v3; // edi
  int v5; // eax
  int v6; // eax
  unsigned int iType; // edi
  int v8; // esi

  v3 = ikey;
  if ( *(_DWORD *)(ikey->dwExitCode + 4) == 0 )
    GASStringNode::ResolveLowercase_Impl();
  if ( *(_DWORD *)a1 == 0 )
    return 0;
  v5 = GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>(
         a1: &ikey,
         a2: *(_DWORD *)(*(_DWORD *)a1 + 4) & *(_DWORD *)(v3->dwExitCode + 12));
  if ( v5 < 0 )
    return 0;
  v6 = *(_DWORD *)a1 + 24 * v5 + 12;
  if ( v6 == 0 )
    return 0;
  iType = pvalue.emr.iType;
  if ( pvalue.emr.iType != 0 )
  {
    v8 = v6 + 4;
    GASValue::operator=(v: (tagWNDCLASSW *)(v6 + 4));
    *(_BYTE *)(iType + 1) = *(_BYTE *)(v8 + 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100912D0
// Name: public: void GHashsetNodeEntry_GC<struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>::NodeHashF>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>::Clear(
        int a1@<ecx>,
        int a2@<edi>)
{
  int v3; // ecx
  bool v4; // zf
  int v5; // ecx
  int v6; // ecx

  GASValue::~GASValue(this: (GASValue *)(a1 + 20));
  if ( (*(_BYTE *)(a1 + 16) & 2) == 0 )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( v3 != 0 )
      GRefCountBaseGC<323>::Release(a1: v3, a2);
  }
  v4 = (*(_BYTE *)(a1 + 16) & 1) == 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( v4 )
  {
    v5 = *(_DWORD *)(a1 + 12);
    if ( v5 != 0 )
      GRefCountBaseGC<323>::Release(a1: v5, a2);
  }
  *(_DWORD *)(a1 + 12) = 0;
  v6 = *(_DWORD *)(a1 + 4);
  v4 = (*(_DWORD *)(v6 + 8))-- == 1;
  if ( v4 )
    GASStringNode::ReleaseNode();
  *(_DWORD *)a1 = -2;
}

//------------------------------------------------------------------------------
// Address: 0x10091460
// Name: public: GHashsetNodeEntry_GC<struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>::NodeHashF>(struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>(
        void *this,
        int *a2,
        int a3)
{
  int v4; // eax
  int v5; // eax
  tagIMECHARPOSITION *v6; // eax

  *(_DWORD *)this = a3;
  v4 = *a2;
  *((_DWORD *)this + 1) = *a2;
  ++*(_DWORD *)(v4 + 8);
  *((_BYTE *)this + 16) = 0;
  v5 = a2[1];
  *((_DWORD *)this + 2) = v5;
  if ( v5 != 0 )
    *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 3) = 0;
  v6 = (tagIMECHARPOSITION *)a2[2];
  if ( v6 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v6);
  GASValue::GASValue(this: (GASValue *)this + 5, a2: (const struct GASValue *)(a2 + 4));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100915C0
// Name: public: bool GASStringHashBase<class GASMember,class GHashUncachedLH_GC<class GASString,class GASMember,struct GASStringHashFunctor,323>>::GetCaseCheck(class GASString const __near &,class GASMember __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10091630
// Name: public: struct GASObject::Watchpoint __near * GASStringHashBase<struct GASObject::Watchpoint,class GHashUncachedLH_GC<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor,323>>::GetCaseCheck(class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASStringHashBase<GASObject::Watchpoint,GHashUncachedLH_GC<GASString,GASObject::Watchpoint,GASStringHashFunctor,323>>::GetCaseCheck(
        int *this,
        int a2,
        int a3)
{
  int v4; // edi
  int Index; // eax
  int v6; // eax
  bool v7; // zf
  int v8; // eax

  if ( (_BYTE)a3 != 0 )
  {
    v4 = *this;
    if ( *this == 0 )
      return 0;
    Index = GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
              a1: a2,
              a2: *(_DWORD *)(v4 + 4) & *(_DWORD *)(*(_DWORD *)a2 + 12));
    if ( Index < 0 )
      return 0;
    v6 = v4 + 36 * Index + 12;
  }
  else
  {
    v7 = *(_DWORD *)(*(_DWORD *)a2 + 4) == 0;
    a3 = a2;
    if ( v7 )
      GASStringNode::ResolveLowercase_Impl();
    if ( *this == 0 )
      return 0;
    v8 = GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>(
           a1: &a3,
           a2: *(_DWORD *)(*this + 4) & *(_DWORD *)(*(_DWORD *)a2 + 12));
    if ( v8 < 0 )
      return 0;
    v6 = *this + 36 * v8 + 12;
  }
  if ( v6 != 0 )
    return v6 + 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10091730
// Name: public: GHashsetNodeEntry_GC<struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>::NodeHashF>(class GHashsetNodeEntry_GC<struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>(
        void *this,
        int a2)
{
  int v3; // eax
  int v4; // eax
  tagIMECHARPOSITION *v5; // eax

  *(_DWORD *)this = *(_DWORD *)a2;
  v3 = *(_DWORD *)(a2 + 4);
  *((_DWORD *)this + 1) = v3;
  ++*(_DWORD *)(v3 + 8);
  *((_BYTE *)this + 16) = 0;
  v4 = *(_DWORD *)(a2 + 8);
  *((_DWORD *)this + 2) = v4;
  if ( v4 != 0 )
    *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 3) = 0;
  v5 = *(tagIMECHARPOSITION **)(a2 + 12);
  if ( v5 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v5);
  GASValue::GASValue(this: (GASValue *)this + 5, a2: (const struct GASValue *)(a2 + 20));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092E20
// Name: public: void GASStringHashBase<struct GASObject::Watchpoint,class GHashUncachedLH_GC<class GASString,struct GASObject::Watchpoint,struct GASStringHashFunctor,323>>::SetCaseCheck(class GASString const __near &,struct GASObject::Watchpoint const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASStringHashBase<GASObject::Watchpoint,GHashUncachedLH_GC<GASString,GASObject::Watchpoint,GASStringHashFunctor,323>>::SetCaseCheck(
        void *this,
        int a2,
        struct GASFunctionRefBase *a3,
        char a4)
{
  int v6; // edx
  int v7; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h]

  GASStringHashBase<GASObject::Watchpoint,GHashUncachedLH_GC<GASString,GASObject::Watchpoint,GASStringHashFunctor,323>>::FindCaseCheck(
    a1: &v7,
    a2,
    a3: a4);
  if ( v7 != 0 && *(_DWORD *)v7 != 0 && v8 <= *(_DWORD *)(*(_DWORD *)v7 + 4) )
  {
    GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(*(_DWORD *)v7 + 36 * v8 + 16), a2: a3);
    return GASValue::operator=(v: (tagWNDCLASSW *)((char *)a3 + 12));
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)a2 + 12);
    v8 = (int)a3;
    v7 = a2;
    return GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeRef>(
             a1: this,
             a2: &v7,
             a3: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092F60
// Name: int G_toupper(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall G_toupper(void *c)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10092F80
// Name: public: bool GASString::CompareBuiltIn_CaseInsensitive(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASString::CompareBuiltIn_CaseInsensitive(void *this, _IMAGE_SYMBOL_EX *result)
{
  if ( *(_DWORD *)(result->N.Name.Short + 4) == 0 )
    GASStringNode::ResolveLowercase_Impl();
  return *(_DWORD *)(*(_DWORD *)this + 4) == *(_DWORD *)(result->N.Name.Short + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10092FB0
// Name: public: bool GASValue::TypesMatch(class GASValue const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASValue::TypesMatch(GASValue *this, tagWNDCLASSW *val)
{
  char v2; // al
  char style; // cl

  v2 = *(_BYTE *)this;
  style = val->style;
  if ( v2 == LOBYTE(val->style) )
    return true;
  return (v2 == 3 || v2 == 4) && (style == 3 || style == 4);
}

//------------------------------------------------------------------------------
// Address: 0x10092FF0
// Name: public: void GASValue::Sub(class GASEnvironment __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Sub(GASValue *this, struct GASEnvironment *a2, int v2)
{
  double v4; // [esp+4h] [ebp-8h]

  v4 = GASValue::ToNumber(this, a2) - (double)v2;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs(this);
  *(_BYTE *)this = 3;
  *(double *)(this + 1) = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10093030
// Name: public: void GASValue::Sub(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Sub(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  double v4; // [esp+8h] [ebp-8h]
  double v5; // [esp+8h] [ebp-8h]

  v4 = GASValue::ToNumber((GASValue *)this, a2: penv);
  v5 = v4 - GASValue::ToNumber(this: (GASValue *)v, a2: penv);
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(double *)(this + 4) = v5;
  *(_BYTE *)this = 3;
}

//------------------------------------------------------------------------------
// Address: 0x10093080
// Name: public: void GASValue::Mul(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Mul(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  double v4; // [esp+8h] [ebp-8h]
  double v5; // [esp+8h] [ebp-8h]

  v4 = GASValue::ToNumber(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToNumber((GASValue *)this, a2: penv) * v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(double *)(this + 4) = v5;
  *(_BYTE *)this = 3;
}

//------------------------------------------------------------------------------
// Address: 0x100930D0
// Name: public: void GASValue::And(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::And(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  int v4; // edi
  int v5; // edi

  v4 = GASValue::ToInt32(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToInt32((GASValue *)this, a2: penv) & v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(_DWORD *)(this + 4) = v5;
  *(_BYTE *)this = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10093110
// Name: public: void GASValue::Or(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Or(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  int v4; // edi
  int v5; // edi

  v4 = GASValue::ToInt32(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToInt32((GASValue *)this, a2: penv) | v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(_DWORD *)(this + 4) = v5;
  *(_BYTE *)this = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10093150
// Name: public: void GASValue::Xor(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Xor(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  int v4; // edi
  int v5; // edi

  v4 = GASValue::ToInt32(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToInt32((GASValue *)this, a2: penv) ^ v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(_DWORD *)(this + 4) = v5;
  *(_BYTE *)this = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10093190
// Name: public: void GASValue::Shl(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Shl(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  char v4; // bl
  int v5; // edi

  v4 = GASValue::ToInt32(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToInt32((GASValue *)this, a2: penv) << v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(_DWORD *)(this + 4) = v5;
  *(_BYTE *)this = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100931D0
// Name: public: void GASValue::Asr(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Asr(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  char v4; // bl
  int v5; // edi

  v4 = GASValue::ToInt32(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToInt32((GASValue *)this, a2: penv) >> v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(_DWORD *)(this + 4) = v5;
  *(_BYTE *)this = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10093210
// Name: public: void GASValue::Lsr(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::Lsr(unsigned int this, struct GASEnvironment *penv, tagWNDCLASSW *v)
{
  char v4; // bl
  unsigned int v5; // edi

  v4 = GASValue::ToInt32(this: (GASValue *)v, a2: penv);
  v5 = GASValue::ToUInt32((GASValue *)this, a2: penv) >> v4;
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this);
  *(_DWORD *)(this + 4) = v5;
  *(_BYTE *)this = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10093250
// Name: public: void GFxDisasm::Log(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GFxDisasm::Log(GFxDisasm *this, const char *a2, ...)
{
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  if ( *(_DWORD *)this != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, char *))(**(_DWORD **)this + 4))(
      a1: *(_DWORD *)this,
      a2: *((_DWORD *)this + 1),
      a3: a2,
      a4: va);
}

//------------------------------------------------------------------------------
// Address: 0x10093280
// Name: public: GASEnvironment::GetVarParams::GetVarParams(class GASString const __near &,class GASValue __near *,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *,class GFxASCharacter __near * __near *,class GASValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GASEnvironment::GetVarParams::GetVarParams(
        _DWORD *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  *this = a2;
  *(this + 1) = a3;
  *(this + 2) = a4;
  *(this + 3) = a5;
  *(this + 4) = a6;
  *(this + 5) = a7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100932B0
// Name: public: virtual void GASExecuteTag::ExecuteWithPriority(class GFxSprite __near *,enum GFxActionPriority::Priority)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASExecuteTag::ExecuteWithPriority(CMatQueuedMesh *this@<ecx>, int m, int prio, MeshDesc_t *a4)
{
  ((void (__thiscall *)(CMatQueuedMesh *, int))this->GetVertexFormat)(a1: this, a2: m);
}

//------------------------------------------------------------------------------
// Address: 0x100932D0
// Name: public: class GFxStream __near * GFxLoadProcess::GetStream(void)
// Source: json
//------------------------------------------------------------------------------
GFxLoadProcess *__thiscall GFxLoadProcess::GetStream(GFxLoadProcess **this)
{
  GFxLoadProcess *result; // eax

  result = *(this + 201);
  if ( result == nullptr )
    return (GFxLoadProcess *)(this + 10);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100932E0
// Name: public: int GFxLoadProcess::Tell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxLoadProcess::Tell(GFxLoadProcess *this)
{
  GFxLoadProcess *v2; // ecx

  v2 = (GFxLoadProcess *)*(this + 201);
  if ( v2 == nullptr )
    v2 = this + 10;
  return (int)v2[11] + (char *)v2[13] - (char *)v2[12];
}

//------------------------------------------------------------------------------
// Address: 0x10093300
// Name: GAS_GlobalParseInt
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalParseInt(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  int v2; // ebx
  int v3; // edi
  struct GASValue *v4; // eax
  int *v5; // eax
  int v6; // ebx
  GASValue *v7; // eax
  int v8; // eax
  int v9; // esi
  char v10; // cl
  int v11; // ecx
  int v12; // esi
  struct GASEnvironment *v14; // [esp-Ch] [ebp-20h]
  double v15; // [esp+4h] [ebp-10h]
  int result; // [esp+8h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-8h]
  char *pstop; // [esp+10h] [ebp-4h] BYREF

  cbStructure = fn.cbStructure;
  if ( *(int *)(fn.cbStructure + 28) >= 1 )
  {
    v2 = *(_DWORD *)(fn.cbStructure + 24);
    v3 = 10;
    v4 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
    GASValue::ToStringImpl(a1: v4, a2: &fn, a3: v2, a4: -1, a5: 0);
    v5 = (int *)fn.cbStructure;
    v6 = 0;
    if ( *(int *)(cbStructure + 28) < 2 )
    {
      if ( *(_DWORD *)(fn.cbStructure + 16) > 1u && **(_BYTE **)fn.cbStructure == 48 )
      {
        v10 = *(_BYTE *)(*(_DWORD *)fn.cbStructure + 1);
        v6 = 1;
        v3 = 8;
        if ( v10 == 120 || v10 == 88 )
        {
          v3 = 16;
          v6 = 2;
        }
      }
    }
    else
    {
      v14 = *(struct GASEnvironment **)(cbStructure + 24);
      v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
      v8 = GASValue::ToInt32(this: v7, a2: v14);
      v3 = v8;
      if ( v8 < 2 || v8 > 36 )
      {
        v15 = GASNumberUtil::NaN();
        v9 = *(_DWORD *)(cbStructure + 4);
        if ( *(_BYTE *)v9 >= 5u )
        {
          GASValue::DropRefs(this: (GASValue *)v9);
          *(double *)(v9 + 4) = v15;
          *(_BYTE *)v9 = 3;
          goto LABEL_21;
        }
LABEL_17:
        *(_BYTE *)v9 = 3;
        *(double *)(v9 + 4) = v15;
LABEL_21:
        if ( (*(_DWORD *)(fn.cbStructure + 8))-- == 1 )
          GASStringNode::ReleaseNode();
        return;
      }
      v5 = (int *)fn.cbStructure;
    }
    v11 = *v5;
    pstop = nullptr;
    v17 = v11;
    result = strtol(nptr: (const char *)(v6 + *v5), endptr: &pstop, ibase: v3);
    if ( (char *)(v6 + v17) != pstop || v3 == 8 )
    {
      v12 = *(_DWORD *)(cbStructure + 4);
      if ( *(_BYTE *)v12 >= 5u )
        GASValue::DropRefs(this: (GASValue *)v12);
      *(_BYTE *)v12 = 4;
      *(_DWORD *)(v12 + 4) = result;
      goto LABEL_21;
    }
    v15 = GASNumberUtil::NaN();
    v9 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v9 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v9);
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093440
// Name: GAS_GlobalParseFloat
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalParseFloat(char *pstop)
{
  char *v1; // esi
  int v2; // edi
  struct GASValue *v3; // eax
  char *v4; // edi
  double v5; // st7
  int v6; // esi
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v1 = pstop;
  if ( *((int *)pstop + 7) >= 1 )
  {
    v2 = *((_DWORD *)pstop + 6);
    v3 = GASFnCall::Arg(this: (GASFnCall *)pstop, a2: 0);
    GASValue::ToStringImpl(a1: v3, a2: &v8, a3: v2, a4: -1, a5: 0);
    v4 = *(char **)v8;
    pstop = nullptr;
    v5 = G_strtod(a1: (const char *)*(_DWORD *)v8, a2: &pstop);
    if ( v4 == pstop )
      v5 = GASNumberUtil::NaN();
    v6 = *((_DWORD *)v1 + 1);
    if ( *(_BYTE *)v6 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v6);
    *(_BYTE *)v6 = 3;
    *(double *)(v6 + 4) = v5;
    if ( (*(_DWORD *)(v8 + 8))-- == 1 )
      GASStringNode::ReleaseNode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100934D0
// Name: GAS_GlobalIfFrameLoaded
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_GlobalIfFrameLoaded(const GPtr<GFxZlibSupportBase> *a1@<ebx>, int fn)
{
  int v2; // edi
  int v3; // ecx
  int v4; // edi
  int v5; // eax
  GASValue *v6; // eax
  int v7; // ebx
  int v8; // esi
  struct GASEnvironment *v9; // [esp-Ch] [ebp-10h]

  if ( *(int *)(fn + 28) >= 1 )
  {
    v2 = *(_DWORD *)(fn + 4);
    GASValue::DropRefs(this: (GASValue *)v2);
    *(_BYTE *)v2 = 2;
    *(_BYTE *)(v2 + 4) = 0;
    v3 = *(_DWORD *)(fn + 8);
    if ( v3 != 0 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3) != 2 )
        return;
      v5 = *(_DWORD *)(fn + 8);
      if ( v5 == 0 )
        return;
      v4 = v5 - 120;
    }
    else
    {
      v4 = *(_DWORD *)(*(_DWORD *)(fn + 24) + 116);
    }
    if ( v4 != 0 )
    {
      v9 = *(struct GASEnvironment **)(fn + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v7 = GASValue::ToInt32(this: v6, a2: v9);
      if ( v7 < (int)GFxSprite::GetLoadingFrame(result: a1) )
      {
        v8 = *(_DWORD *)(fn + 4);
        GASValue::DropRefs(this: (GASValue *)v8);
        *(_BYTE *)v8 = 2;
        *(_BYTE *)(v8 + 4) = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093550
// Name: GAS_GlobalIsNaN
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalIsNaN(_CONNECTDLGSTRUCTW fn)
{
  char v1; // bl
  GASValue *v2; // eax
  int v3; // esi
  struct GASEnvironment *v4; // [esp-4h] [ebp-14h]
  double v5; // [esp+8h] [ebp-8h]

  v1 = 1;
  if ( *(int *)(fn.cbStructure + 28) >= 1 )
  {
    v4 = *(struct GASEnvironment **)(fn.cbStructure + 24);
    v2 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
    v5 = GASValue::ToNumber(this: v2, a2: v4);
    if ( (HIDWORD(v5) & 0x7FF00000) != 0x7FF00000 || (HIDWORD(v5) & 0xFFFFF | LODWORD(v5)) == 0 )
      v1 = 0;
  }
  v3 = *(_DWORD *)(fn.cbStructure + 4);
  GASValue::DropRefs(this: (GASValue *)v3);
  *(_BYTE *)(v3 + 4) = v1;
  *(_BYTE *)v3 = 2;
}

//------------------------------------------------------------------------------
// Address: 0x100935C0
// Name: GAS_GlobalIsFinite
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalIsFinite(_CONNECTDLGSTRUCTW fn)
{
  GASValue *v1; // eax
  double v2; // st7
  int v3; // esi
  int v4; // esi
  struct GASEnvironment *v5; // [esp-4h] [ebp-10h]
  double v6; // [esp+4h] [ebp-8h]

  if ( *(int *)(fn.cbStructure + 28) < 1
    || (v5 = *(struct GASEnvironment **)(fn.cbStructure + 24),
        v1 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0),
        v2 = GASValue::ToNumber(this: v1, a2: v5),
        v6 = v2,
        (HIDWORD(v6) & 0x7FF00000) == 0x7FF00000)
    && (HIDWORD(v6) & 0xFFFFF | LODWORD(v6)) != 0
    || v2 == -INFINITY
    || v2 == INFINITY )
  {
    v4 = *(_DWORD *)(fn.cbStructure + 4);
    GASValue::DropRefs(this: (GASValue *)v4);
    *(_BYTE *)(v4 + 4) = 0;
    *(_BYTE *)v4 = 2;
  }
  else
  {
    v3 = *(_DWORD *)(fn.cbStructure + 4);
    GASValue::DropRefs(this: (GASValue *)v3);
    *(_BYTE *)(v3 + 4) = 1;
    *(_BYTE *)v3 = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093690
// Name: public: static void GASGlobalContext::EscapeWithMask(char const __near *,unsigned int,class GString __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static CImagePacker *__cdecl GASGlobalContext::EscapeWithMask(
        const char *a1,
        unsigned int length,
        CUtlMemory<CImagePacker,int> *a3,
        CMaterialSystem *escapeMask)
{
  unsigned int v4; // edi
  int *i; // esi
  int v6; // ebx
  int putf8str[63]; // [esp+10h] [ebp-104h] BYREF
  char v9; // [esp+10Fh] [ebp-5h] BYREF

  v4 = 0;
  for ( i = putf8str; v4 < length; ++v4 )
  {
    v6 = (unsigned __int8)a1[v4];
    if ( i + 1 >= (int *)&v9 )
    {
      *(_BYTE *)i = 0;
      GString::AppendString(this: a3, (int)putf8str);
      i = putf8str;
    }
    if ( v6 < 128
      && ((1 << (v6 & 0x1F))
        & (int)*(&escapeMask->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable
               + v6 / 32)) != 0 )
    {
      *(_BYTE *)i = v6;
      i = (int *)((char *)i + 1);
    }
    else
    {
      *(_BYTE *)i = 37;
      *((_BYTE *)i + 1) = v6 / 16 + (v6 / 16 > 9 ? 55 : 48);
      *((_BYTE *)i + 2) = (v6 & 0xF) + ((v6 & 0xFu) > 9 ? 55 : 48);
      i = (int *)((char *)i + 3);
    }
  }
  *(_BYTE *)i = 0;
  return GString::AppendString(this: a3, (int)putf8str);
}

//------------------------------------------------------------------------------
// Address: 0x100937A0
// Name: public: static void GASGlobalContext::Escape(char const __near *,unsigned int,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASGlobalContext::Escape(const char *a1, unsigned int a2, CUtlMemory<CImagePacker,int> *a3)
{
  GASGlobalContext::EscapeWithMask(a1, length: a2, a3, escapeMask: (CMaterialSystem *)&unk_1029EDF4);
}

//------------------------------------------------------------------------------
// Address: 0x100937C0
// Name: public: static void GASGlobalContext::EscapePath(char const __near *,unsigned int,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASGlobalContext::EscapePath(const char *a1, unsigned int a2, CUtlMemory<CImagePacker,int> *a3)
{
  GASGlobalContext::EscapeWithMask(a1, length: a2, a3, escapeMask: (CMaterialSystem *)&unk_1029EE04);
}

//------------------------------------------------------------------------------
// Address: 0x100937E0
// Name: public: static void GASGlobalContext::Unescape(char const __near *,unsigned int,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASGlobalContext::Unescape(const char *a1, unsigned int a2, CUtlMemory<CImagePacker,int> *a3)
{
  const char *v3; // esi
  int *v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int putf8str[63]; // [esp+10h] [ebp-104h] BYREF
  char v12; // [esp+10Fh] [ebp-5h] BYREF

  v3 = a1;
  v4 = putf8str;
  while ( v3 < &a1[a2] )
  {
    v5 = *(unsigned __int8 *)v3++;
    if ( (char *)v4 + 1 >= &v12 )
    {
      *(_BYTE *)v4 = 0;
      GString::AppendString(this: a3, (int)putf8str);
      v4 = putf8str;
    }
    if ( v5 == 37 )
    {
      v6 = *(unsigned __int8 *)v3;
      if ( (unsigned int)(v6 - 97) <= 0x19 )
        v6 -= 32;
      v7 = *((unsigned __int8 *)v3 + 1);
      v8 = v7 - 32;
      if ( (unsigned int)(v7 - 97) > 0x19 )
        v8 = *((unsigned __int8 *)v3 + 1);
      v3 += 2;
      if ( v6 - 48 <= 9 )
        v9 = v6 - 48;
      else
        v9 = v6 - 55;
      if ( v8 - 48 <= 9 )
        v10 = v8 - 48;
      else
        v10 = v8 - 55;
      if ( v9 >= 16 || v10 >= 16 )
        continue;
      *(_BYTE *)v4 = v10 + 16 * v9;
    }
    else
    {
      *(_BYTE *)v4 = v5;
    }
    v4 = (int *)((char *)v4 + 1);
  }
  *(_BYTE *)v4 = 0;
  GString::AppendString(this: a3, (int)putf8str);
}

//------------------------------------------------------------------------------
// Address: 0x100938E0
// Name: public: GASWithStackEntry::GASWithStackEntry(class GFxASCharacter __near *,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GASWithStackEntry::GASWithStackEntry(_DWORD *this, int a2, int end)
{
  _DWORD *result; // eax

  result = this;
  *this = a2;
  if ( a2 != 0 )
    ++*(_DWORD *)(a2 + 4);
  *(this + 1) = end;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10093910
// Name: public: void GASActionBufferData::Read(struct GFxStreamContext __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASActionBufferData::Read(HWND__ *this, unsigned int psc, unsigned int eventLength)
{
  _DWORD *v3; // esi
  unsigned int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned int v7; // ecx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *Instance; // eax
  int v9; // eax

  v3 = (_DWORD *)psc;
  if ( *(_DWORD *)(psc + 12) != 0 )
    ++*(_DWORD *)(psc + 8);
  v5 = eventLength;
  v3[3] = 0;
  psc = 264;
  v6 = (unsigned __int8 *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: v5, a4: &psc);
  *((_DWORD *)this + 2) = v6;
  memcpy(dst: v6, src: (unsigned __int8 *)(v3[2] + *v3), count: v5);
  *((_DWORD *)this + 3) = v5;
  if ( v3[3] != 0 )
    ++v3[2];
  v3[2] += v5;
  v3[3] = 0;
  if ( *((_DWORD *)this + 4) == 0 )
  {
    Instance = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(a1: v7);
    GFxAmpServer::GetNextSwdHandle(this: Instance);
    *((_DWORD *)this + 4) = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093990
// Name: public: void GASEnvironment::SetTarget(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
__vc_attributes::idl_moduleAttribute *__thiscall GASEnvironment::SetTarget(
        int this,
        __vc_attributes::idl_moduleAttribute *result)
{
  __vc_attributes::idl_moduleAttribute *Version; // eax

  *(_BYTE *)(this + 198) &= ~2u;
  *(_DWORD *)(this + 116) = result;
  Version = (__vc_attributes::idl_moduleAttribute *)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)result);
  *(_BYTE *)(this + 124) = (_BYTE)Version;
  return Version;
}

//------------------------------------------------------------------------------
// Address: 0x100939B0
// Name: public: void GASEnvironment::SetInvalidTarget(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
__vc_attributes::idl_moduleAttribute *__thiscall GASEnvironment::SetInvalidTarget(
        int this,
        __vc_attributes::idl_moduleAttribute *result)
{
  __vc_attributes::idl_moduleAttribute *Version; // eax

  *(_BYTE *)(this + 198) |= 2u;
  *(_DWORD *)(this + 116) = result;
  Version = (__vc_attributes::idl_moduleAttribute *)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)result);
  *(_BYTE *)(this + 124) = (_BYTE)Version;
  return Version;
}

//------------------------------------------------------------------------------
// Address: 0x100939D0
// Name: public: void GASEnvironment::SetTargetOnConstruct(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
__vc_attributes::idl_moduleAttribute *__thiscall GASEnvironment::SetTargetOnConstruct(
        int this,
        __vc_attributes::idl_moduleAttribute *result)
{
  __vc_attributes::idl_moduleAttribute *v3; // eax

  *(_BYTE *)(this + 198) &= ~2u;
  *(_DWORD *)(this + 116) = result;
  *(_BYTE *)(this + 124) = (unsigned __int8)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)result);
  v3 = (__vc_attributes::idl_moduleAttribute *)(*((int (__thiscall **)(__vc_attributes::idl_moduleAttribute *))result->name
                                                + 52))(a1: result);
  *(_DWORD *)(this + 120) = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10093A10
// Name: public: class GFxLog __near * GASEnvironment::GetLog(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxLog *__thiscall GASEnvironment::GetLog(GASEnvironment *this)
{
  return (*(struct GFxLog *(__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 168))(a1: *((_DWORD *)this + 29));
}

//------------------------------------------------------------------------------
// Address: 0x10093A20
// Name: public: class GFxMovieRoot __near * GASEnvironment::GetMovieRoot(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieRoot *__thiscall GASEnvironment::GetMovieRoot(GASEnvironment *this)
{
  return (*(struct GFxMovieRoot *(__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 84))(a1: *((_DWORD *)this + 29));
}

//------------------------------------------------------------------------------
// Address: 0x10093A30
// Name: public: static bool GASEnvironment::IsPath(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
static char __cdecl GASEnvironment::IsPath(_IMAGE_SYMBOL_EX *varPath)
{
  unsigned __int8 **Short; // eax
  unsigned __int8 *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  Short = (unsigned __int8 **)varPath->N.Name.Short;
  if ( (*(_DWORD *)(varPath->N.Name.Short + 12) & 0x4000000) != 0 )
    return 1;
  v3 = *Short;
  strchr(string: *Short, chr: 0x3Au);
  if ( v4 != 0 || (strchr(string: v3, chr: 0x2Fu), v5 != 0) || (strchr(string: v3, chr: 0x2Eu), v6 != 0) )
  {
    *(_DWORD *)(varPath->N.Name.Short + 12) |= 0x4000000u;
    return 1;
  }
  else
  {
    *(_DWORD *)(varPath->N.Name.Short + 12) |= 0x6000000u;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093AA0
// Name: public: enum GASBuiltinType GFxEventId::GetFunctionNameBuiltinType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxEventId::GetFunctionNameBuiltinType(unsigned int *this)
{
  unsigned int v1; // eax
  int v2; // eax

  v1 = *this;
  if ( *this > 0x800000 )
  {
    v2 = v1 - 16777191;
  }
  else if ( v1 >= 0x8000 )
  {
    if ( v1 >= 0x800000 )
    {
      if ( v1 >= 0x8000000 )
      {
        if ( v1 >= 0x20000000 )
        {
          if ( v1 >= 0x40000000 )
            v2 = (unsigned __int8)(32 - (v1 < 0x80000000));
          else
            v2 = 30;
        }
        else
        {
          v2 = (unsigned __int8)(29 - (v1 < 0x10000000));
        }
      }
      else if ( v1 >= 0x2000000 )
      {
        v2 = (unsigned __int8)(27 - (v1 < 0x4000000));
      }
      else
      {
        v2 = (unsigned __int8)(25 - (v1 < 0x1000000));
      }
    }
    else if ( v1 >= 0x80000 )
    {
      if ( v1 >= 0x200000 )
        v2 = (unsigned __int8)(23 - (v1 < 0x400000));
      else
        v2 = (unsigned __int8)(21 - (v1 < 0x100000));
    }
    else if ( v1 >= 0x20000 )
    {
      v2 = (unsigned __int8)(19 - (v1 < 0x40000));
    }
    else
    {
      v2 = (unsigned __int8)(17 - (v1 < 0x10000));
    }
  }
  else if ( v1 >= 0x80 )
  {
    if ( v1 >= 0x800 )
    {
      if ( v1 >= 0x2000 )
        v2 = (unsigned __int8)(15 - (v1 < 0x4000));
      else
        v2 = (unsigned __int8)(13 - (v1 < 0x1000));
    }
    else if ( v1 >= 0x200 )
    {
      v2 = (unsigned __int8)(11 - (v1 < 0x400));
    }
    else
    {
      v2 = (unsigned __int8)(9 - (v1 < 0x100));
    }
  }
  else if ( v1 >= 8 )
  {
    if ( v1 >= 0x20 )
      v2 = (unsigned __int8)(7 - (v1 < 0x40));
    else
      v2 = (unsigned __int8)(5 - (v1 < 0x10));
  }
  else if ( v1 >= 2 )
  {
    v2 = (unsigned __int8)(3 - (v1 < 4));
  }
  else
  {
    v2 = v1 != 0;
  }
  if ( (unsigned int)(v2 - 1) > 0x21 )
    return 46;
  else
    return *((_DWORD *)&functionTypes.pObject + v2);
}

//------------------------------------------------------------------------------
// Address: 0x10093C50
// Name: public: class GASString GFxEventId::GetFunctionName(class GASStringContext __near *)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxEventId::GetFunctionName(unsigned int *this, _DWORD *a2, _DWORD *psc)
{
  int v3; // eax

  v3 = *(_DWORD *)(*psc + 4 * GFxEventId::GetFunctionNameBuiltinType(this) + 8);
  ++*(_DWORD *)(v3 + 8);
  *a2 = v3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10093C70
// Name: public: int GFxEventId::ConvertToButtonKeyCode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxEventId::ConvertToButtonKeyCode(GFxEventId *this)
{
  int result; // eax
  unsigned __int8 v2; // cl

  result = 0;
  switch ( *((_WORD *)this + 4) )
  {
    case 8:
      result = 8;
      break;
    case 9:
      result = 18;
      break;
    case 0xD:
      result = 13;
      break;
    case 0x1B:
      result = 19;
      break;
    case 0x21:
      result = 16;
      break;
    case 0x22:
      result = 17;
      break;
    case 0x23:
      result = 4;
      break;
    case 0x24:
      result = 3;
      break;
    case 0x25:
      result = 1;
      break;
    case 0x26:
      result = 14;
      break;
    case 0x27:
      result = 2;
      break;
    case 0x28:
      result = 15;
      break;
    case 0x2D:
      result = 5;
      break;
    case 0x2E:
      result = 6;
      break;
    default:
      v2 = *((_BYTE *)this + 10);
      if ( v2 >= 0x20u )
        result = v2;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10093D50
// Name: public: void GASRefCountCollector::SetParams(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASRefCountCollector::SetParams(GASRefCountCollector *this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax

  v3 = a3;
  *((_DWORD *)this + 18) = a2 != -1 ? a2 : 0;
  if ( a3 == -1 )
    v3 = 1000;
  *((_DWORD *)this + 17) = v3;
  *((_DWORD *)this + 10) = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10093D80
// Name: public: void GASObjectInterface::Set__constructor__(class GASStringContext __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObjectInterface::Set__constructor__(
        GASObjectInterface *this,
        struct GASStringContext *psc,
        const struct GASFunctionRef *psc_4)
{
  GASValue v4[4]; // [esp+4h] [ebp-14h] BYREF
  char v5; // [esp+17h] [ebp-1h] BYREF

  v5 = 3;
  GASValue::GASValue(this: v4, a2: psc_4);
  (*(void (__thiscall **)(GASObjectInterface *, struct GASStringContext *, int, GASValue *, char *))(*(_DWORD *)this + 40))(
    a1: this,
    a2: psc,
    a3: *(_DWORD *)psc + 328,
    a4: v4,
    a5: &v5);
  GASValue::~GASValue(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10093DD0
// Name: GAS_ASnativeMouseButtonStates
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_ASnativeMouseButtonStates(_CONNECTDLGSTRUCTW fn)
{
  GASValue *v1; // eax
  unsigned int v2; // ebx
  int v3; // eax
  int v4; // esi
  int v5; // edi
  struct GASEnvironment *v6; // [esp-Ch] [ebp-10h]

  if ( *(int *)(fn.cbStructure + 28) >= 1 )
  {
    v6 = *(struct GASEnvironment **)(fn.cbStructure + 24);
    v1 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
    v2 = GASValue::ToUInt32(this: v1, a2: v6);
    v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(fn.cbStructure + 24) + 116) + 84))(a1: *(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 116));
    v4 = *(_DWORD *)(fn.cbStructure + 4);
    v5 = *(_DWORD *)(v3 + 2368);
    GASValue::DropRefs(this: (GASValue *)v4);
    *(_BYTE *)v4 = 2;
    *(_BYTE *)(v4 + 4) = (v2 & v5) == v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093E30
// Name: GAS_GlobalEscape
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalEscape(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // edi
  GASValue *v2; // esi
  int v3; // esi
  struct GASValue *v4; // eax
  struct GASStringNode *StringNode; // esi
  int v6; // edi
  bool v7; // zf
  void *v8; // esi
  int v9; // [esp+8h] [ebp-4h] BYREF

  cbStructure = fn.cbStructure;
  v2 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  if ( *(_DWORD *)(cbStructure + 28) == 1 )
  {
    v3 = *(_DWORD *)(cbStructure + 24);
    v4 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    GASValue::ToStringImpl(a1: v4, a2: &v9, a3: v3, a4: -1, a5: 0);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&fn);
    GASGlobalContext::EscapeWithMask(
      a1: *(const char **)v9,
      length: *(_DWORD *)(v9 + 16),
      a3: (CUtlMemory<CImagePacker,int> *)&fn,
      escapeMask: (CMaterialSystem *)&unk_1029EDF4);
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((fn.cbStructure
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(fn.cbStructure & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    v6 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v6 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v6);
    *(_BYTE *)v6 = 5;
    *(_DWORD *)(v6 + 4) = StringNode;
    v7 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v7 )
      GASStringNode::ReleaseNode();
    v8 = (void *)(fn.cbStructure & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((fn.cbStructure & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    v7 = (*(_DWORD *)(v9 + 8))-- == 1;
    if ( v7 )
      GASStringNode::ReleaseNode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093F20
// Name: GAS_GlobalUnescape
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalUnescape(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // edi
  GASValue *v2; // esi
  int v3; // esi
  struct GASValue *v4; // eax
  struct GASStringNode *StringNode; // esi
  int v6; // edi
  bool v7; // zf
  void *v8; // esi
  int v9; // [esp+8h] [ebp-4h] BYREF

  cbStructure = fn.cbStructure;
  v2 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  if ( *(_DWORD *)(cbStructure + 28) == 1 )
  {
    v3 = *(_DWORD *)(cbStructure + 24);
    v4 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    GASValue::ToStringImpl(a1: v4, a2: &v9, a3: v3, a4: -1, a5: 0);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&fn);
    GASGlobalContext::Unescape(
      a1: *(const char **)v9,
      a2: *(_DWORD *)(v9 + 16),
      a3: (CUtlMemory<CImagePacker,int> *)&fn);
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((fn.cbStructure
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(fn.cbStructure & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    v6 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v6 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v6);
    *(_BYTE *)v6 = 5;
    *(_DWORD *)(v6 + 4) = StringNode;
    v7 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v7 )
      GASStringNode::ReleaseNode();
    v8 = (void *)(fn.cbStructure & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((fn.cbStructure & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    v7 = (*(_DWORD *)(v9 + 8))-- == 1;
    if ( v7 )
      GASStringNode::ReleaseNode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094010
// Name: GAS_GlobalEscapeSpecialHTML
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalEscapeSpecialHTML(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // edi
  GASValue *v2; // esi
  int v3; // esi
  struct GASValue *v4; // eax
  const char *v5; // esi
  unsigned int Length; // eax
  struct GASStringNode *StringNode; // esi
  int v8; // edi
  bool v9; // zf
  void *v10; // esi
  int v11; // [esp+8h] [ebp-4h] BYREF

  cbStructure = fn.cbStructure;
  v2 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  if ( *(_DWORD *)(cbStructure + 28) == 1 )
  {
    v3 = *(_DWORD *)(cbStructure + 24);
    v4 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    GASValue::ToStringImpl(a1: v4, a2: &v11, a3: v3, a4: -1, a5: 0);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&fn);
    v5 = *(const char **)v11;
    Length = GASString::GetLength(this: (GASString *)&v11);
    GString::EscapeSpecialHTML(a1: v5, a2: Length, a3: (struct GString *)&fn);
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((fn.cbStructure
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(fn.cbStructure & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    v8 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v8 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v8);
    *(_BYTE *)v8 = 5;
    *(_DWORD *)(v8 + 4) = StringNode;
    v9 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v9 )
      GASStringNode::ReleaseNode();
    v10 = (void *)(fn.cbStructure & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((fn.cbStructure & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    v9 = (*(_DWORD *)(v11 + 8))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094100
// Name: GAS_GlobalUnescapeSpecialHTML
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalUnescapeSpecialHTML(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // edi
  GASValue *v2; // esi
  int v3; // esi
  struct GASValue *v4; // eax
  const char *v5; // esi
  unsigned int Length; // eax
  struct GASStringNode *StringNode; // esi
  int v8; // edi
  bool v9; // zf
  void *v10; // esi
  int v11; // [esp+8h] [ebp-4h] BYREF

  cbStructure = fn.cbStructure;
  v2 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  if ( *(_DWORD *)(cbStructure + 28) == 1 )
  {
    v3 = *(_DWORD *)(cbStructure + 24);
    v4 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    GASValue::ToStringImpl(a1: v4, a2: &v11, a3: v3, a4: -1, a5: 0);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&fn);
    v5 = *(const char **)v11;
    Length = GASString::GetLength(this: (GASString *)&v11);
    GString::UnescapeSpecialHTML(a1: v5, a2: Length, a3: (struct GString *)&fn);
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((fn.cbStructure
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(fn.cbStructure & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    v8 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v8 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v8);
    *(_BYTE *)v8 = 5;
    *(_DWORD *)(v8 + 4) = StringNode;
    v9 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v9 )
      GASStringNode::ReleaseNode();
    v10 = (void *)(fn.cbStructure & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((fn.cbStructure & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    v9 = (*(_DWORD *)(v11 + 8))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100941F0
// Name: GAS_GlobalIMECommand
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalIMECommand(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  IShaderAPI *v2; // edi
  int v3; // ebx
  struct GASValue *v4; // eax
  int v5; // ebx
  struct GASValue *v6; // eax
  bool v7; // zf
  int v8; // [esp+4h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-8h]
  int *v10; // [esp+Ch] [ebp-4h] BYREF

  cbStructure = fn.cbStructure;
  if ( *(int *)(fn.cbStructure + 28) >= 2 )
  {
    v8 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(fn.cbStructure + 24) + 116) + 84))(a1: *(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 116));
    v2 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v8 + 8) + 12))(a1: v8 + 8, a2: 27);
    if ( v2 != nullptr )
    {
      v3 = *(_DWORD *)(cbStructure + 24);
      v4 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
      GASValue::ToStringImpl(a1: v4, a2: &v10, a3: v3, a4: -1, a5: 0);
      v5 = *v10;
      v9 = *(_DWORD *)(cbStructure + 24);
      v6 = GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      GASValue::ToStringImpl(a1: v6, a2: &fn, a3: v9, a4: -1, a5: 0);
      ((void (__thiscall *)(IShaderAPI *, int, _DWORD, int))v2->SetFloatRenderingParameter)(
        a1: v2,
        a2: v8,
        a3: *(_DWORD *)fn.cbStructure,
        a4: v5);
      v7 = (*(_DWORD *)(fn.cbStructure + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      v7 = v10[2]-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      GRefCountImpl::Release(this: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100942C0
// Name: GAS_GetInputLanguage
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__cdecl GAS_GetInputLanguage(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // ebx
  ShaderAPIOcclusionQuery_t__ *result; // eax
  int v3; // eax
  IShaderAPI *v4; // esi
  _DWORD *v5; // eax
  void *v6; // edi
  int v7; // edi
  int v9; // [esp+4h] [ebp-4h] BYREF
  struct GASStringNode *fna; // [esp+10h] [ebp+8h]

  cbStructure = fn.cbStructure;
  result = *(ShaderAPIOcclusionQuery_t__ **)(fn.cbStructure + 24);
  if ( result != nullptr )
  {
    v3 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)result + 29) + 84))(a1: *((_DWORD *)result + 29));
    v4 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v3 + 8) + 12))(a1: v3 + 8, a2: 27);
    fna = GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 120) + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029EE3C,
            a3: 7u,
            a4: 0);
    ++*((_DWORD *)fna + 2);
    if ( v4 != nullptr )
    {
      v5 = (_DWORD *)((int (__thiscall *)(IShaderAPI *, int *))v4->SetPixelShaderConstant)(a1: v4, a2: &v9);
      GASString::operator=(result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v5 & 0xFFFFFFFC) + 8));
      v6 = (void *)(v9 & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v9 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    }
    v7 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v7 >= 5u )
      GASValue::DropRefs(this: *(GASValue **)(cbStructure + 4));
    *(_BYTE *)v7 = 5;
    *(_DWORD *)(v7 + 4) = fna;
    ++*((_DWORD *)fna + 2);
    result = (ShaderAPIOcclusionQuery_t__ *)fna;
    if ( (*((_DWORD *)fna + 2))-- == 1 )
      result = (ShaderAPIOcclusionQuery_t__ *)GASStringNode::ReleaseNode().Sid;
    if ( v4 != nullptr )
      return GRefCountImpl::Release(this: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100943A0
// Name: _GASGlobalContext::Init_::_4_::MemberVisitor::Visit
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASGlobalContext::Init_::_4_::MemberVisitor::Visit(_DWORD *this, int a2, int a3, unsigned __int8 a4)
{
  return (*(int (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)(*(this + 1) + 16) + 28))(
           a1: *(this + 1) + 16,
           a2: *(this + 2),
           a3: a2,
           a4: a4 | 1);
}

//------------------------------------------------------------------------------
// Address: 0x100943D0
// Name: public: class GASRefCountCollector __near * GASGlobalContext::GetGC(void)
// Source: json
//------------------------------------------------------------------------------
struct GASRefCountCollector *__thiscall GASGlobalContext::GetGC(GASGlobalContext *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 163);
  if ( v1 != 0 )
    return *(struct GASRefCountCollector **)(*(_DWORD *)(v1 + 20) + 12);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100943F0
// Name: public: bool GASEnvironment::IsVerboseAction(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::IsVerboseAction(__vc_attributes::idl_moduleAttribute *this)
{
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 84))(a1: *((_DWORD *)this + 29));
}

//------------------------------------------------------------------------------
// Address: 0x10094410
// Name: public: virtual bool GASEnvironment::IsVerboseActionErrors(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::IsVerboseActionErrors(__vc_attributes::idl_moduleAttribute *this)
{
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 84))(a1: *((_DWORD *)this + 29));
}

//------------------------------------------------------------------------------
// Address: 0x10094430
// Name: public: void GASEnvironment::InvalidateOptAdvanceList(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::InvalidateOptAdvanceList(GASEnvironment *this)
{
  int v1; // eax

  if ( *((_DWORD *)this + 29) != 0 )
  {
    v1 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 84))(a1: *((_DWORD *)this + 29));
    *(_DWORD *)(v1 + 9332) |= 0x80000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094450
// Name: public: class GASRefCountCollector __near * GASEnvironment::GetCollector(void)
// Source: json
//------------------------------------------------------------------------------
__vc_attributes::objectAttribute *__thiscall GASEnvironment::GetCollector(_DWORD **this)
{
  if ( *(this + 29) != nullptr )
    return *(__vc_attributes::objectAttribute **)(*(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(this + 29) + 84))(a1: *(this + 29))
                                                            + 20)
                                                + 12);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10094470
// Name: public: class Bool3W GASEnvironment::CheckGlobalAndLevels(struct GASEnvironment::GetVarParams const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::CheckGlobalAndLevels(__vc_attributes::satypeAttribute *this, _BYTE *a2, GASValue **a3)
{
  GASValue **v4; // edi
  int v5; // eax
  GASValue v6; // ecx
  tagBITMAPCOREHEADER *v7; // eax
  GASValue *v8; // ebx
  GASValue *v9; // ebx
  char ***v10; // eax
  bool v11; // dl
  int v12; // eax
  int v13; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]

  v4 = a3;
  if ( *((_BYTE *)this + 124) <= 6u )
  {
    v8 = *a3;
    v13 = *((_DWORD *)this + 30);
    if ( (**a3)->m_nAllocationCount == 0 )
      GASStringNode::ResolveLowercase_Impl();
    if ( *(_DWORD *)(*(_DWORD *)(v13 + 264) + 4) == (*v8)->m_nAllocationCount )
      goto LABEL_3;
    v9 = *v4;
    v14 = *((_DWORD *)this + 30);
    if ( (**v4)->m_nAllocationCount == 0 )
      GASStringNode::ResolveLowercase_Impl();
    if ( *(_DWORD *)(*(_DWORD *)(v14 + 260) + 4) == (*v9)->m_nAllocationCount )
    {
      v5 = *((_DWORD *)this + 30);
LABEL_6:
      GASValue::SetAsObject(this: v4[1], a2: *(struct GASObject **)(v5 + 680));
      *a2 = 1;
      return;
    }
  }
  else
  {
    v5 = *((_DWORD *)this + 30);
    v6 = **a3;
    if ( *(GASValue *)(v5 + 264) == v6 )
    {
LABEL_3:
      v7 = (tagBITMAPCOREHEADER *)(*(int (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 29) + 104))(
                                    a1: *((_DWORD *)this + 29),
                                    a2: 0);
LABEL_4:
      GASValue::SetAsCharacter(result: v7);
      *a2 = 1;
      return;
    }
    if ( *(GASValue *)(v5 + 260) == v6 )
      goto LABEL_6;
  }
  v10 = (char ***)*v4;
  v11 = *((_BYTE *)this + 124) > 6u;
  a3 = nullptr;
  v12 = GFxMovieRoot::ParseLevelName(
          nptr: **v10,
          ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&a3,
          caseSensitive: v11);
  if ( v12 == -1 || *(_BYTE *)a3 != 0 )
  {
    *a2 = 0;
  }
  else
  {
    v7 = (tagBITMAPCOREHEADER *)(*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 29) + 100))(
                                  a1: *((_DWORD *)this + 29),
                                  a2: v12);
    if ( v7 != nullptr )
      goto LABEL_4;
    *a2 = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100945A0
// Name: public: bool GASEnvironment::FindOwnerOfMember(class GASString const __near &,class GASValue __near *,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASEnvironment::FindOwnerOfMember(tagBITMAPCOREHEADER **this, int a2, GASValue *a3, _DWORD *a4)
{
  _DWORD *v6; // ecx
  int i; // ebx
  int v8; // eax
  int v9; // esi
  tagBITMAPCOREHEADER **v10; // esi
  struct GASObject *v11; // edi

  if ( a3 == nullptr )
    return 0;
  v6 = a4;
  if ( a4 != nullptr )
  {
    for ( i = a4[1] - 1; i >= 0; --i )
    {
      v8 = *(_DWORD *)(*v6 + 8 * i);
      if ( *(int *)(*v6 + 8 * i + 4) >= 0 )
      {
        if ( v8 == 0 )
          continue;
        v9 = v8 + 120;
      }
      else
      {
        if ( v8 == 0 )
          continue;
        v9 = v8 + 16;
      }
      if ( v9 != 0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(int, tagBITMAPCOREHEADER **, int, _DWORD))(*(_DWORD *)v9 + 36))(
               a1: v9,
               a2: this + 30,
               a3: a2,
               a4: 0) != 0 )
        {
          if ( (unsigned int)((*(int (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9) - 2) > 3 )
            GASValue::SetAsObject(this: a3, a2: (struct GASObject *)(v9 - 16));
          else
            GASValue::SetAsCharacter(result: (tagBITMAPCOREHEADER *)(v9 - 120));
          return 1;
        }
        v6 = a4;
      }
    }
  }
  if ( *(this + 29) == nullptr )
    return 0;
  v10 = this + 30;
  if ( (*(unsigned __int8 (__thiscall **)(tagBITMAPCOREHEADER *, tagBITMAPCOREHEADER **, int, _DWORD))((*(this + 29))[10].bcSize + 36))(
         a1: *(this + 29) + 10,
         a2: this + 30,
         a3: a2,
         a4: 0) != 0 )
  {
    GASValue::SetAsCharacter(result: *(this + 29));
    return 1;
  }
  v11 = *(struct GASObject **)&(*v10)[56].bcPlanes;
  if ( v11 == nullptr
    || ((unsigned __int8 (__thiscall *)(struct GASObject *, tagBITMAPCOREHEADER **, int, _DWORD))v11[2].pNode[4].elem)(
         a1: &v11[2],
         a2: v10,
         a3: a2,
         a4: 0) == 0 )
  {
    return 0;
  }
  GASValue::SetAsObject(this: a3, a2: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100946C0
// Name: public: class GASLocalFrame __near * GASEnvironment::GetTopLocalFrame(int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::GetTopLocalFrame(__vc_attributes::propputAttribute *this, int off)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100946F0
// Name: public: static bool GASEnvironment::ParsePath(class GASStringContext __near *,class GASString const __near &,class GASString __near *,class GASString __near *)
// Source: json
//------------------------------------------------------------------------------
static char __cdecl GASEnvironment::ParsePath(
        _IMAGE_SYMBOL_EX *varPath,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***a2,
        _SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode> ppath,
        _SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode> pvar)
{
  unsigned __int8 *v4; // esi
  signed int v5; // edi
  int v6; // eax
  int v7; // eax
  int v9; // eax
  int v10; // esi
  bool v11; // zf
  int v12; // esi
  bool v13; // sf
  struct GASStringNode *StringNode; // esi
  unsigned __int8 **v15; // ebx

  v4 = (unsigned __int8 *)**a2;
  v5 = -1;
  strchr(string: v4, chr: 0x3Au);
  if ( v6 == 0 )
  {
    strrchr(string: v4, chr: 0x2Eu);
    if ( v6 == 0 )
    {
      strrchr(string: v4, chr: 0x2Fu);
      if ( v7 == 0 )
        return 0;
      goto LABEL_10;
    }
  }
  v5 = v6 - (_DWORD)v4;
  if ( v6 - (int)v4 < 0 )
  {
LABEL_10:
    v12 = *(_DWORD *)(varPath->N.Name.Short + 8);
    ++*(_DWORD *)(v12 + 8);
    v11 = (*(_DWORD *)(*(_DWORD *)pvar.NodeNumber + 8))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode();
    *(_DWORD *)pvar.NodeNumber = v12;
    goto LABEL_13;
  }
  GASStringManager::CreateStringNode(this: *(const char **)(varPath->N.Name.Short + 636));
  v10 = v9;
  *(_DWORD *)(v9 + 8) += 2;
  v11 = (*(_DWORD *)(*(_DWORD *)pvar.NodeNumber + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode();
  *(_DWORD *)pvar.NodeNumber = v10;
  v11 = (*(_DWORD *)(v10 + 8))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode();
LABEL_13:
  v13 = v5 < 0;
  if ( v5 > 0 )
  {
    if ( *((_BYTE *)**a2 + v5 - 1) == 47 )
      --v5;
    v13 = v5 < 0;
  }
  if ( v13 )
  {
    v15 = (unsigned __int8 **)*a2;
    (*a2)[2] = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)(*a2)[2] + 1);
    v11 = (*(_DWORD *)(*(_DWORD *)ppath.NodeNumber + 8))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode();
    *(_DWORD *)ppath.NodeNumber = v15;
  }
  else
  {
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(varPath->N.Name.Short + 636),
                   result: **a2,
                   length: v5);
    *((_DWORD *)StringNode + 2) += 2;
    v11 = (*(_DWORD *)(*(_DWORD *)ppath.NodeNumber + 8))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode();
    *(_DWORD *)ppath.NodeNumber = StringNode;
    v11 = (*((_DWORD *)StringNode + 2))-- == 1;
    if ( v11 )
    {
      GASStringNode::ReleaseNode();
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094810
// Name: public: bool GASEnvironment::NeedTermination(enum GASActionBuffer::ExecuteType)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASEnvironment::NeedTermination(_DWORD *this, int a2)
{
  int v2; // eax

  return (a2 == 0 || a2 == 3) && ((*(_WORD *)((v2 = *(this + 29)) + 118) & 0x100) != 0 || *(int *)(v2 + 20) < -1)
      || (*(_BYTE *)(*(this + 29) + 118) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10094850
// Name: public: bool StringTokenizer::NextToken(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StringTokenizer::NextToken(GPtr<ScaleformFileOpener> *this, ScaleformFileOpener *sep)
{
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *pObject; // edi
  int v5; // eax
  ScaleformFileOpener *v6; // eax
  struct GASStringNode *StringNode; // edi
  int v8; // ecx
  bool v9; // zf

  pObject = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)this->pObject;
  if ( this->pObject >= (ScaleformFileOpener *)*((_DWORD *)this + 1) )
    return 0;
  do
  {
    strchr(string: *((unsigned __int8 **)this + 2), chr: (unsigned __int8)this->pObject->__vftable);
    if ( v5 != 0 )
      break;
    ++this->pObject;
  }
  while ( this->pObject < (ScaleformFileOpener *)*((_DWORD *)this + 1) );
  LOBYTE(sep->__vftable) = this->pObject->__vftable;
  v6 = this->pObject;
  if ( pObject == (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)this->pObject
    || (unsigned int)v6 > *((_DWORD *)this + 1) )
  {
    StringNode = *(struct GASStringNode **)(*(_DWORD *)(*(_DWORD *)(this + 3) & 0xFFFFFC00) + 32);
  }
  else
  {
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(this + 3) & 0xFFFFFC00),
                   result: pObject,
                   length: (char *)v6 - (char *)pObject);
  }
  *((_DWORD *)StringNode + 2) += 2;
  v8 = *((_DWORD *)this + 3);
  v9 = (*(_DWORD *)(v8 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode();
  *((_DWORD *)this + 3) = StringNode;
  v9 = (*((_DWORD *)StringNode + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode();
  ++this->pObject;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100948F0
// Name: public: void GASStringContext::InvalidateOptAdvanceList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringContext::InvalidateOptAdvanceList(GASStringContext *this)
{
  if ( *(_DWORD *)this != 0 )
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 652) + 9332) |= 0x80000u;
}

//------------------------------------------------------------------------------
// Address: 0x10094D10
// Name: public: bool GASObjectInterface::SetConstMemberRaw(class GASStringContext __near *,char const __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObjectInterface::SetConstMemberRaw(
        void *this,
        tagWNDCLASSW *result,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a3,
        int a4)
{
  VTFFileHeaderPS3_t *v4; // edi
  unsigned int style; // eax
  GASStringManager *v7; // ecx
  VTFFileHeaderPS3_t *ConstStringNode; // eax
  int v9; // ecx
  char v10; // bl
  char v13; // [esp+Fh] [ebp-1h] BYREF

  v4 = (VTFFileHeaderPS3_t *)result;
  style = result->style;
  v13 = 0;
  v7 = *(GASStringManager **)(style + 636);
  result = (tagWNDCLASSW *)((char *)&a3->m_Memory.m_pMemory + 1);
  ConstStringNode = (VTFFileHeaderPS3_t *)GASStringManager::CreateConstStringNode(
                                            this: v7,
                                            result: a3,
                                            a3: strlen((const char *)a3),
                                            a4: 0);
  v9 = a4;
  result = (tagWNDCLASSW *)ConstStringNode;
  ++ConstStringNode->version[1];
  v10 = (*(int (__thiscall **)(void *, VTFFileHeaderPS3_t *, tagWNDCLASSW **, int, char *))(*(_DWORD *)this + 40))(
          a1: this,
          a2: v4,
          a3: &result,
          a4: v9,
          a5: &v13);
  if ( result->cbClsExtra-- == 1 )
    GASStringNode::ReleaseNode();
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10094D80
// Name: public: GArrayDataCC<class GASString,struct GAllocatorLH<class GASString,323>,struct GArrayDefaultPolicy>::~GArrayDataCC<class GASString,struct GAllocatorLH<class GASString,323>,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
GStatInfo *__thiscall GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::~GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>(
        _DWORD *this)
{
  int v2; // ecx
  bool v3; // zf
  int v4; // eax
  int v5; // esi
  int v6; // edi

  v2 = *(this + 3);
  v3 = (*(_DWORD *)(v2 + 8))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode();
  v4 = *(this + 1);
  v5 = *this + 4 * v4 - 4;
  if ( v4 != 0 )
  {
    v6 = *(this + 1);
    do
    {
      v3 = (*(_DWORD *)(*(_DWORD *)v5 + 8))-- == 1;
      if ( v3 )
        GASStringNode::ReleaseNode();
      v5 -= 4;
      --v6;
    }
    while ( v6 != 0 );
  }
  return ((GStatInfo *(__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: *this);
}

//------------------------------------------------------------------------------
// Address: 0x10094DD0
// Name: public: GFxActionLogger::GFxActionLogger(class GFxCharacter __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxActionLogger *__thiscall GFxActionLogger::GFxActionLogger(
        GFxActionLogger *this,
        struct GFxCharacter *a2,
        const char *a3)
{
  ScaleformRenderer *v4; // edi
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  int v9; // edx
  char v10; // cl

  *(_DWORD *)this = &GFxActionLogger::`vftable';
  v4 = (ScaleformRenderer *)(*(int (__thiscall **)(struct GFxCharacter *))(*(_DWORD *)a2 + 84))(a1: a2);
  *((_BYTE *)this + 8) = (v4[1].m_glyphVertexBuffer[101].color.Raw & 4) != 0;
  *((_BYTE *)this + 9) = (v4[1].m_glyphVertexBuffer[101].color.Raw & 0x40) == 0;
  *((_DWORD *)this + 3) = a3;
  if ( a3 != nullptr )
  {
    v5 = ((int (__thiscall *)(ScaleformRenderer *))v4->GetRenderCaps)(a1: v4);
    if ( strcmp((const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 48))(a1: v5), *((const char **)this + 3)) == 0 )
      *((_BYTE *)this + 10) = (v4[1].m_glyphVertexBuffer[101].color.Raw & 8) != 0;
    else
      *((_BYTE *)this + 10) = (v4[1].m_glyphVertexBuffer[101].color.Raw & 0x10) != 0;
  }
  else
  {
    *((_BYTE *)this + 10) = 0;
  }
  GFxMovieRoot::GetCachedLog(this: v4, a2: (VertexShaderHandle_t__ *)this);
  v6 = *((_BYTE *)this + 10) == 0;
  *((_DWORD *)this + 1) = v7;
  if ( !v6 && (v4[1].m_glyphVertexBuffer[101].color.Raw & 0x20) == 0 )
  {
    v8 = strlen(a3);
    if ( v8 > 0 )
    {
      v9 = *((_DWORD *)this + 3);
      while ( 1 )
      {
        v10 = *(_BYTE *)(v9 + v8);
        if ( v10 == 47 || v10 == 92 )
          break;
        if ( --v8 <= 0 )
          return this;
      }
      *((_DWORD *)this + 3) = v9 + v8 + 1;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10094EE0
// Name: public: virtual bool GFxActionLogger::IsVerboseActionErrors(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxActionLogger::IsVerboseActionErrors(GFxActionLogger *this)
{
  return *((_BYTE *)this + 9);
}

//------------------------------------------------------------------------------
// Address: 0x10094F20
// Name: public: virtual bool GASGlobalObject::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASGlobalObject::GetMemberRaw(
        GRefCountBaseNTS<GImageInfoBase,2> *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        void (__thiscall **a3)(struct GRefCountBaseNTS<GImageInfoBase,2> *this),
        GASValue *a4)
{
  char v4; // al
  bool v5; // bl

  if ( *a3 != (void (__thiscall *)(struct GRefCountBaseNTS<GImageInfoBase,2> *))psc->pNext[36].elem )
    return (unsigned __int8)GASObject::GetMemberRaw((CTSQueue<CFunctor *,0,1> *)this, psc);
  v4 = *(_BYTE *)(*((_DWORD *)this + 9) + 684);
  if ( v4 != 0 )
  {
    v5 = v4 == 1;
    GASValue::DropRefs(this: a4);
    *((_BYTE *)a4 + 4) = v5;
    *(_BYTE *)a4 = 2;
    return 1;
  }
  else
  {
    GASValue::DropRefs(this: a4);
    *(_BYTE *)a4 = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094FA0
// Name: public: void GFxMovieRoot::SetContinueAnimationFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetContinueAnimationFlag(_DWORD *this, const IDirect3DResource9 *result)
{
  if ( (_BYTE)result != 0 )
    *(this + 2333) |= 0x200000u;
  else
    *(this + 2333) &= ~0x200000u;
}

//------------------------------------------------------------------------------
// Address: 0x10095010
// Name: public: virtual bool GASGlobalObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GASGlobalObject::SetMember@<al>(
        GRefCountBaseNTS<GImageInfoBase,2> *this@<ecx>,
        tagPOLYTEXTW *penv,
        const struct GASString *name,
        tagWNDCLASSW *val,
        _MODEMSETTINGS flags)
{
  _DWORD *x; // eax
  int v8; // ecx
  tagWNDCLASSW *v9; // ebx
  int v10; // eax
  GASStringManager *v11; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *ConstStringNode; // esi
  bool v13; // zf
  char v14; // al
  char v15; // bl
  unsigned __int8 v17; // al
  GASValue v18[4]; // [esp+Ch] [ebp-10h] BYREF
  unsigned int penva; // [esp+24h] [ebp+8h]
  _DWORD *penvb; // [esp+24h] [ebp+8h]

  x = (_DWORD *)penv[3].x;
  v8 = *(_DWORD *)name;
  v9 = (tagWNDCLASSW *)&penv[3];
  if ( *(_DWORD *)name == x[73] )
  {
    *(_BYTE *)(*((_DWORD *)this + 9) + 684) = ((unsigned __int8)GASValue::ToBool(result: penv) == 0) + 1;
    v10 = *((_DWORD *)this + 9);
    v11 = *(GASStringManager **)(v10 + 636);
    if ( *(_BYTE *)(v10 + 684) == 1 )
    {
      ConstStringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateConstStringNode(
                                                                                                     this: v11,
                                                                                                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029EEE8.m_Size,
                                                                                                     a3: 6u,
                                                                                                     a4: 0);
      ++ConstStringNode->m_nGrowSize;
      LOBYTE(v18[0]) = 5;
      v18[1] = ConstStringNode;
      ++ConstStringNode->m_nGrowSize;
      GASObjectInterface::SetConstMemberRaw(
        this,
        result: v9,
        a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029EEE8,
        a4: (int)v18);
      GASValue::~GASValue(this: v18);
      v13 = ConstStringNode->m_nGrowSize-- == 1;
      if ( v13 )
        GASStringNode::ReleaseNode();
    }
    else
    {
      val = (tagWNDCLASSW *)GASStringManager::CreateConstStringNode(
                              this: v11,
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029EEE8,
                              a3: 0xAu,
                              a4: 0);
      ++val->cbClsExtra;
      ((void (__thiscall *)(GRefCountBaseNTS<GImageInfoBase,2> *, tagWNDCLASSW *, tagWNDCLASSW **))this->__vftable[6].dtr_GRefCountImplCore)(
        a1: this,
        a2: v9,
        a3: &val);
      v13 = val->cbClsExtra-- == 1;
      if ( v13 )
        GASStringNode::ReleaseNode();
    }
    LOBYTE(v18[0]) = 10;
    GASObject::SetMember((CTSQueue<CFunctor *,0,1> *)this);
    v15 = v14;
    GASValue::~GASValue(this: v18);
    return v15;
  }
  else
  {
    if ( *(_BYTE *)(*((_DWORD *)this + 9) + 684) == 1 )
    {
      if ( v8 == x[74] )
      {
        penva = (*(int (__thiscall **)(int *))(*penv[2].pdx + 84))(a1: penv[2].pdx);
        if ( penva != 0 )
        {
          if ( (unsigned __int8)GASValue::ToBool(result: penv) != 0 )
            *(_DWORD *)(penva + 9332) |= 0x800u;
          else
            *(_DWORD *)(penva + 9332) &= ~0x800u;
        }
      }
      else if ( v8 == x[75] )
      {
        penvb = (_DWORD *)(*(int (__thiscall **)(int *))(*penv[2].pdx + 84))(a1: penv[2].pdx);
        if ( penvb != nullptr )
        {
          v17 = (unsigned __int8)GASValue::ToBool(result: penv);
          GFxMovieRoot::SetContinueAnimationFlag(this: penvb, result: (const IDirect3DResource9 *)v17);
        }
      }
    }
    return GASObject::SetMemberRaw(
             (GASObject *)this,
             a2: (struct GASStringContext *)v9,
             a3: name,
             a4: (GASValue *)val,
             a5: (const struct GASPropFlags *)flags.dwActualSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100951D0
// Name: public: GASWithStackEntry::GASWithStackEntry(class GASObject __near *,int)
// Source: json
//------------------------------------------------------------------------------
GASWithStackEntry *__thiscall GASWithStackEntry::GASWithStackEntry(
        GASWithStackEntry *this,
        struct GASObject *a2,
        int a3)
{
  GASWithStackEntry *result; // eax

  result = this;
  *(_DWORD *)&this->palVersion = a2;
  if ( a2 != nullptr )
    a2[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&a2[1].pNode->pNext + 1) & 0x8FFFFFFF);
  this->palPalEntry[0] = (tagPALETTEENTRY)(a3 | 0x80000000);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10095200
// Name: public: void GASActionBufferData::Read(class GFxStream __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASActionBufferData::Read(GASActionBufferData *this, struct GFxStream *a2, unsigned int a3)
{
  unsigned int v3; // eax
  GASActionBufferData *v4; // esi
  void *(__thiscall *AllocAutoHeap_2)(GMemoryHeap *, const void *, unsigned int, const GAllocDebugInfo *); // eax
  unsigned __int8 *v6; // eax
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // esi
  char v10; // bl
  int v11; // ecx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *Instance; // eax
  int v13; // eax
  unsigned int v14; // [esp-8h] [ebp-1Ch]
  unsigned int v15; // [esp-4h] [ebp-18h]
  _DWORD v16[2]; // [esp+8h] [ebp-Ch] BYREF
  GASActionBufferData *v17; // [esp+10h] [ebp-4h]

  v3 = a3;
  v4 = this;
  *((_DWORD *)this + 3) = a3;
  a3 = 264;
  v14 = v3;
  AllocAutoHeap_2 = GMemory::pGlobalHeap->AllocAutoHeap_2;
  v17 = this;
  v6 = (unsigned __int8 *)AllocAutoHeap_2(
                            this: GMemory::pGlobalHeap,
                            a2: this,
                            a3: v14,
                            a4: (const GAllocDebugInfo *)&a3);
  v15 = *((_DWORD *)v4 + 3);
  *((_DWORD *)v4 + 2) = v6;
  GFxStream::ReadToBuffer(this: (GFxStream *)a2, pdestBuf: v6, a3: v15);
  if ( GFxStream::IsVerboseParseAction(this: (GFxStream *)a2) )
  {
    v8 = *((_DWORD *)v4 + 2);
    v9 = 0;
    v16[1] = 51;
    do
    {
      v10 = *(_BYTE *)(v8 + v9);
      v11 = v9++;
      if ( v10 < 0 )
        v9 += *(unsigned __int16 *)(v8 + v9) + 2;
      GFxLogBase<GFxStream>::LogParseAction(this: (tagBITMAPINFOHEADER *)a2, a2: (int)"%4d\t", v11);
      v16[0] = CMaterialSubRect::GetMaterialPage(this: a2);
      GFxDisasm::Log(this: (GFxDisasm *)v16, a2: "<disasm is disabled>\n");
    }
    while ( v10 != 0 );
    v4 = v17;
  }
  if ( *((_DWORD *)v4 + 4) == 0 )
  {
    Instance = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(a1: v7);
    GFxAmpServer::GetNextSwdHandle(this: Instance);
    *((_DWORD *)v4 + 4) = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100952D0
// Name: public: class GASValue __near * GASEnvironment::LocalRegisterPtr(unsigned int)
// Source: json
//------------------------------------------------------------------------------
GASEnvironment *__thiscall GASEnvironment::LocalRegisterPtr(GASEnvironment *this, unsigned int reg)
{
  unsigned int v3; // eax

  v3 = *((_DWORD *)this + 27);
  if ( reg < v3 )
    return (GASEnvironment *)(*((_DWORD *)this + 26) + 16 * (v3 - reg - 1));
  GFxLogBase<GASEnvironment>::LogError(
    a1: (int)this,
    a2: (int)"Invalid local register %d, stack only has %d entries\n",
    reg,
    v3);
  return this + 10;
}

//------------------------------------------------------------------------------
// Address: 0x10095310
// Name: public: class GFxASCharacter __near * GASEnvironment::FindTarget(class GASString const __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::FindTarget(
        __vc_attributes::event_receiverAttribute *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***path,
        bool excludeFlags)
{
  int v4; // edx
  int v5; // ecx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v6; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v7; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v8; // edi
  GASStringManager *v9; // ecx
  struct GASStringNode *StringNode; // eax
  struct GASStringNode *v11; // esi
  bool v12; // zf
  char first_call; // [esp+4h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-8h]
  struct GASStringNode *v15; // [esp+Ch] [ebp-4h] BYREF

  if ( (*path)[4] == nullptr )
    return;
  v4 = *((_DWORD *)this + 30);
  v5 = *((_DWORD *)this + 29);
  v6 = **path;
  v15 = *(struct GASStringNode **)(v4 + 8);
  ++*((_DWORD *)v15 + 2);
  v14 = v5;
  if ( LOBYTE(v6->m_Memory.m_pMemory) == 47 )
  {
    v14 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 104))(a1: v5, a2: 0);
    v6 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)v6 + 1);
  }
  first_call = 1;
  while ( 2 )
  {
    v7 = v6;
    if ( LOBYTE(v6->m_Memory.m_pMemory) == 0 )
    {
LABEL_11:
      v8 = nullptr;
      goto LABEL_12;
    }
    while ( LOBYTE(v7->m_Memory.m_pMemory) == 46 )
    {
      if ( BYTE1(v7->m_Memory.m_pMemory) != 46 )
        goto LABEL_15;
      v7 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)v7 + 1);
LABEL_10:
      v7 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)v7 + 1);
      if ( LOBYTE(v7->m_Memory.m_pMemory) == 0 )
        goto LABEL_11;
    }
    if ( LOBYTE(v7->m_Memory.m_pMemory) != 47 )
      goto LABEL_10;
LABEL_15:
    v8 = v7;
LABEL_12:
    if ( v8 == v6 )
    {
      if ( (excludeFlags & 4) == 0 )
        GFxLogBase<GASEnvironment>::LogError(a1: (int)this, a2: (int)"Error: invalid path '%s'\n", (const char *)**path);
    }
    else
    {
      v9 = *(GASStringManager **)(*((_DWORD *)this + 30) + 636);
      if ( v8 != nullptr )
        StringNode = GASStringManager::CreateStringNode(this: v9, result: v6, length: (char *)v8 - (char *)v6);
      else
        GASStringManager::CreateStringNode(this: (const char *)v9);
      v11 = StringNode;
      *((_DWORD *)StringNode + 2) += 2;
      v12 = (*((_DWORD *)v15 + 2))-- == 1;
      if ( v12 )
        GASStringNode::ReleaseNode();
      v15 = v11;
      v12 = (*((_DWORD *)v11 + 2))-- == 1;
      if ( v12 )
        GASStringNode::ReleaseNode();
      if ( *((_DWORD *)v15 + 4) != 0 )
        v14 = (*(int (__thiscall **)(int, struct GASStringNode **, char))(*(_DWORD *)v14 + 268))(
                a1: v14,
                a2: &v15,
                a3: first_call);
      if ( v14 != 0 && v8 != nullptr )
      {
        v6 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)&v8->m_Memory.m_pMemory
                                                                                      + 1);
        first_call = 0;
        continue;
      }
    }
    break;
  }
  v12 = (*((_DWORD *)v15 + 2))-- == 1;
  if ( v12 )
    GASStringNode::ReleaseNode();
}

//------------------------------------------------------------------------------
// Address: 0x10095790
// Name: public: void GFxMovieRoot::SetDragState(class GFxMovieRoot::DragState const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxMovieRoot::SetDragState(int this, ScaleformRenderer::VertexShaderType st)
{
  float *result; // eax
  float sta; // [esp+8h] [ebp+8h]
  float stb; // [esp+8h] [ebp+8h]
  float stc; // [esp+8h] [ebp+8h]

  result = (float *)st;
  *(_DWORD *)(this + 9188) = *(_DWORD *)st;
  *(_BYTE *)(this + 9192) = *(_BYTE *)(st + 4);
  *(_BYTE *)(this + 9193) = *(_BYTE *)(st + 5);
  sta = *(float *)(st + 12);
  *(float *)(this + 9196) = result[2];
  *(float *)(this + 9200) = sta;
  stb = result[5];
  *(float *)(this + 9204) = result[4];
  *(float *)(this + 9208) = stb;
  stc = result[7];
  *(float *)(this + 9212) = result[6];
  *(float *)(this + 9216) = stc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10095800
// Name: public: static class GASActionBufferData __near * GASActionBufferData::CreateNew(void)
// Source: json
//------------------------------------------------------------------------------
static struct GASActionBufferData *__thiscall GASActionBufferData::CreateNew(void *this)
{
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  struct GASActionBufferData *result; // eax
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = (int)this;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  v3 = 264;
  result = (struct GASActionBufferData *)Alloc_2(this: GMemory::pGlobalHeap, a2: 24u, a3: (const GAllocDebugInfo *)&v3);
  if ( result == nullptr )
    return nullptr;
  *(_DWORD *)result = &GRefCountImplCore::`vftable';
  *((_DWORD *)result + 1) = 1;
  *(_DWORD *)result = &GASActionBufferData::`vftable';
  *((_DWORD *)result + 2) = 0;
  *((_DWORD *)result + 3) = 0;
  *((_DWORD *)result + 4) = 0;
  *((_DWORD *)result + 5) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10095850
// Name: protected: bool GASActionBuffer::ResolveFrameNumber(class GASEnvironment __near *,class GASValue const __near &,class GFxASCharacter __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASActionBuffer::ResolveFrameNumber(
        GASActionBuffer *this,
        __vc_attributes::event_receiverAttribute *a2,
        GASValue *a3,
        struct GFxASCharacter **a4,
        unsigned int *a5)
{
  __vc_attributes::event_receiverAttribute *v5; // ebx
  char v6; // al
  int Length; // edi
  int v8; // esi
  int v9; // eax
  struct GFxASCharacter *v10; // eax
  bool v11; // zf
  char v12; // bl
  int v14; // eax
  GASValue *v15; // esi
  double v16; // st7
  __int64 v17; // [esp+4h] [ebp-10h] BYREF
  __vc_attributes::event_receiverAttribute::type_e path; // [esp+Ch] [ebp-8h] BYREF
  struct GFxASCharacter *v19; // [esp+10h] [ebp-4h]

  v5 = a2;
  v19 = *(struct GFxASCharacter **)&a2[14].layout_dependent;
  v6 = *(_BYTE *)a3;
  HIBYTE(a2) = 0;
  if ( *(_BYTE *)a3 == 5 )
  {
    GASValue::ToStringImpl(a1: a3, a2: &a3, a3: v5, a4: -1, a5: 0);
    Length = GASString::GetLength(this: (GASString *)&a3);
    v8 = 0;
    if ( Length <= 0 )
      goto LABEL_10;
    while ( 1 )
    {
      LOWORD(v9) = GASString::GetCharAt();
      if ( v9 == 58 )
      {
        GASString::Substring(a1: &a3, a2: &path, a3: 0, a4: v8);
        GASEnvironment::FindTarget(
          this: v5,
          (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)&path,
          excludeFlags: false);
        v19 = v10;
        if ( v10 != nullptr )
        {
          if ( v8 < Length )
          {
            v14 = GASString::Substring(a1: &a3, a2: (char *)&v17 + 4, a3: v8 + 1, a4: Length + 1);
            v15 = *(GASValue **)v14;
            ++*(_DWORD *)(*(_DWORD *)v14 + 8);
            v11 = (*((_DWORD *)a3 + 2))-- == 1;
            if ( v11 )
              GASStringNode::ReleaseNode();
            a3 = v15;
            v11 = (*(_DWORD *)(HIDWORD(v17) + 8))-- == 1;
            if ( v11 )
              GASStringNode::ReleaseNode();
            v11 = (*(_DWORD *)(path + 8))-- == 1;
            if ( v11 )
              GASStringNode::ReleaseNode();
LABEL_10:
            if ( v19 == nullptr
              || (v12 = 1,
                  (*(unsigned __int8 (__thiscall **)(struct GFxASCharacter *, _DWORD, unsigned int *, int))(*(_DWORD *)v19 + 320))(
                    a1: v19,
                    a2: *a3,
                    a3: a5,
                    a4: 1) == 0) )
            {
              v12 = 0;
            }
            v11 = (*((_DWORD *)a3 + 2))-- == 1;
            if ( v11 )
              GASStringNode::ReleaseNode();
            if ( v12 != 0 )
            {
LABEL_16:
              if ( a4 != nullptr )
                *a4 = v19;
            }
            return v12;
          }
          v19 = nullptr;
        }
        v11 = (*(_DWORD *)(path + 8))-- == 1;
        if ( v11 )
          GASStringNode::ReleaseNode();
      }
      if ( ++v8 >= Length )
        goto LABEL_10;
    }
  }
  if ( v6 != 6 && (v6 == 3 || v6 == 4) )
  {
    v16 = GASValue::ToNumber(this: a3, a2: (struct GASEnvironment *)v5);
    a3 = (GASValue *)(HIWORD(a2) | 0xC00);
    *a5 = (__int64)(v16 - 1.0);
    v12 = 1;
    goto LABEL_16;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10095DC0
// Name: public: void GASDoAction::Read(class GFxLoadProcess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDoAction::Read(GPtr<GImageInfoBase> *this, IShaderDeviceMgr *p)
{
  _DWORD *p_Connect; // eax
  _DWORD *v4; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  _DWORD *v7; // eax
  IShaderAPI *v8; // ecx
  IShaderDeviceMgr_vtbl *v9; // ecx
  int v10; // eax
  IShaderDeviceMgr_vtbl *v11; // edx
  IShaderDeviceMgr *v12; // eax
  int v13; // eax
  _DWORD *v14; // ecx
  ShaderDisplayMode_t *v15; // [esp+0h] [ebp-10h]
  int v16; // [esp+4h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-4h] BYREF
  HBITMAP__ pa; // [esp+18h] [ebp+8h]

  p_Connect = &p[201].Connect;
  v4 = nullptr;
  if ( p_Connect == nullptr )
    p_Connect = &p[10].__vftable;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  pa.unused = (int)p_Connect;
  v17 = 264;
  v7 = (_DWORD *)Alloc_2(this: GMemory::pGlobalHeap, a2: 24u, a3: (const GAllocDebugInfo *)&v17);
  if ( v7 != nullptr )
  {
    *v7 = &GRefCountImplCore::`vftable';
    v7[2] = 0;
    v7[3] = 0;
    v7[4] = 0;
    v7[5] = 0;
    v7[1] = 1;
    *v7 = &GASActionBufferData::`vftable';
    v4 = v7;
  }
  v8 = *((IShaderAPI **)this + 1);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  *((_DWORD *)this + 1) = v4;
  v9 = p[166].__vftable;
  v10 = *(_DWORD *)(pa.unused + 44) + *(_DWORD *)(pa.unused + 52) - *(_DWORD *)(pa.unused + 48);
  if ( ((unsigned __int8)v9 & 0x10) != 0 )
  {
    v11 = p[157].__vftable;
    if ( p[175].__vftable > v11 )
    {
      p[157].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v11->Connect + 1);
      v10 = *((_DWORD *)&p[174].Connect + (_DWORD)v11);
    }
  }
  if ( ((unsigned __int8)v9 & 1) != 0 )
    v10 += 8;
  *(_DWORD *)(*((_DWORD *)this + 1) + 20) = v10;
  *(_DWORD *)(*((_DWORD *)this + 1) + 16) = p[8].__vftable[3].Reconnect;
  v12 = (IShaderDeviceMgr *)p[201].__vftable;
  if ( v12 == nullptr )
    v12 = p + 10;
  GFxStream::GetTagEndPosition(this: v12, a2: v15, a3: v16);
  v14 = &p[201].Connect;
  if ( v14 == nullptr )
    v14 = &p[10].__vftable;
  GASActionBufferData::Read(
    this: *((GASActionBufferData **)this + 1),
    a2: (struct GFxStream *)pa.unused,
    a3: v13 + v14[12] - v14[13] - v14[11]);
}

//------------------------------------------------------------------------------
// Address: 0x10095EC0
// Name: public: GASWithStackEntry::~GASWithStackEntry(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASWithStackEntry::~GASWithStackEntry(unsigned __int8 *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  GRefCountNTSImpl *v3; // ecx

  v2 = *((_DWORD *)this + 1);
  v3 = *(GRefCountNTSImpl **)this;
  if ( v2 >= 0 )
  {
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: v3);
  }
  else if ( v3 != nullptr )
  {
    GRefCountBaseGC<323>::Release(a1: (int)v3, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095EE0
// Name: public: GASActionBuffer::GASActionBuffer(class GASStringContext __near *,class GASActionBufferData __near *)
// Source: json
//------------------------------------------------------------------------------
_NETRESOURCEW *__thiscall GASActionBuffer::GASActionBuffer(
        _DWORD *this,
        _NETRESOURCEW *result,
        IShaderDevice *pbufferData_4)
{
  unsigned int dwScope; // eax
  int v5; // eax

  *this = &GRefCountImplCore::`vftable';
  *(this + 1) = 1;
  *this = &GASActionBuffer::`vftable';
  if ( pbufferData_4 != nullptr )
    GRefCountImpl::AddRef(this: pbufferData_4);
  *(this + 2) = pbufferData_4;
  dwScope = result->dwScope;
  *(this + 3) = 0;
  *(this + 4) = 0;
  *(this + 5) = 0;
  v5 = *(_DWORD *)(dwScope + 8);
  *(this + 6) = v5;
  ++*(_DWORD *)(v5 + 8);
  *(this + 7) = -1;
  return (_NETRESOURCEW *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10095F40
// Name: public: void GASRefCountCollector::AdvanceFrame(unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASRefCountCollector::AdvanceFrame(
        IDataCacheSection *this,
        unsigned int *movieFrameCnt,
        unsigned int *movieLastCollectFrame)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  const GPtr<IDirect3DVertexDeclaration9> *stats; // [esp+4h] [ebp-14h] BYREF
  unsigned int v18; // [esp+8h] [ebp-10h]
  __int64 v19; // [esp+Ch] [ebp-Ch]

  v4 = *((_DWORD *)this + 16);
  if ( *movieLastCollectFrame == v4 )
  {
    v5 = *((_DWORD *)this + 9);
    if ( *movieFrameCnt >= v5 )
    {
      ++*((_DWORD *)this + 15);
      v6 = v5 + 1;
      v7 = *((_DWORD *)this + 11);
      v8 = *((_DWORD *)this + 2);
      *((_DWORD *)this + 9) = v6;
      if ( v8 >= v7 )
        v7 = v8;
      v9 = *((_DWORD *)this + 17);
      *((_DWORD *)this + 11) = v7;
      if ( v9 != 0 && v8 > *((_DWORD *)this + 10) || (v10 = *((_DWORD *)this + 18)) != 0 && v6 >= v10 && v8 > v9 )
      {
        v18 = 0;
        stats = nullptr;
        GRefCountCollector<323>::Collect(this, a2: (int)this, a3: (unsigned int *)&stats);
        v11 = *((_DWORD *)this + 17);
        v12 = v18;
        if ( v18 > v11 )
        {
          *((_DWORD *)this + 11) = v8;
          *((_DWORD *)this + 10) = v11;
        }
        v13 = v8 - v12;
        if ( v8 - v12 < *((_DWORD *)this + 10) )
          v13 = *((_DWORD *)this + 10);
        *((_DWORD *)this + 10) = v13;
        v19 = (__int64)((double)v13 * 0.7);
        v14 = *((_DWORD *)this + 11);
        if ( v14 < (unsigned int)v19 )
          *((_DWORD *)this + 10) = v19;
        v15 = v18;
        *(this + 16) = *(this + 15);
        *((_DWORD *)this + 9) = 0;
        *((_DWORD *)this + 14) = v14;
        *((_DWORD *)this + 13) = v15;
      }
      v16 = *((_DWORD *)this + 9);
      *((_DWORD *)this + 12) = v8;
      *movieFrameCnt = v16;
      *movieLastCollectFrame = *((_DWORD *)this + 16);
    }
    else
    {
      ++*movieFrameCnt;
    }
  }
  else
  {
    *movieLastCollectFrame = v4;
    *movieFrameCnt = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096060
// Name: public: void GASRefCountCollector::ForceCollect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASRefCountCollector::ForceCollect(GASRefCountCollector *this)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  unsigned int v4[2]; // [esp+8h] [ebp-8h] BYREF

  v2 = *((_DWORD *)this + 2);
  v4[1] = 0;
  v4[0] = 0;
  GRefCountCollector<323>::Collect(this, a2: (int)this, a3: v4);
  v3 = *((_DWORD *)this + 11);
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 12) = v2;
  if ( v2 >= v3 )
    *((_DWORD *)this + 11) = v2;
  else
    *((_DWORD *)this + 11) = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100960B0
// Name: public: void GASRefCountCollector::ForceEmergencyCollect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASRefCountCollector::ForceEmergencyCollect(GASRefCountCollector *this)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  bool v4; // zf
  int v5; // ecx
  const DName *v6; // [esp+0h] [ebp-14h]
  unsigned int v7[2]; // [esp+Ch] [ebp-8h] BYREF

  v7[1] = 0;
  v7[0] = 0;
  v2 = *((_DWORD *)this + 2);
  GRefCountCollector<323>::Collect(this, a2: (int)this, a3: v7);
  v3 = *((_DWORD *)this + 11);
  *((_DWORD *)this + 9) = 0;
  if ( v2 >= v3 )
    v3 = v2;
  v4 = (*(_BYTE *)(this + 8) & 1) == 0;
  *((_DWORD *)this + 11) = v3;
  *((_DWORD *)this + 12) = v2;
  if ( v4 && *((_DWORD *)this + 2) == 0 )
    GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(result: v6);
  v5 = *((_DWORD *)this + 17);
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10096290
// Name: private: void GASLocalFrame::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
GFxFontPackParams *__usercall GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>@<eax>(
        int a1@<ecx>,
        GFxFontPackParams *a2@<edi>,
        GFxFontPackParams *a3)
{
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // edi
  signed int v9; // esi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  int v12; // ecx
  GFxFontPackParams *v14; // [esp-4h] [ebp-Ch]
  GFxFontPackParams *v15; // [esp+0h] [ebp-8h]

  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 != 0 )
  {
    v6 = *(_DWORD *)(v4 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v4 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 6;
    }
    while ( v5 <= v6 );
    v4 = a1 + 16;
  }
  else
  {
    v5 = 0;
  }
  v14 = a2;
  v8 = v4;
  v9 = v5;
  while ( v8 != 0 && *(_DWORD *)v8 != 0 && v9 <= *(_DWORD *)(*(_DWORD *)v8 + 4) )
  {
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(result: v14);
    v10 = *(_DWORD *)(*(_DWORD *)v8 + 4);
    if ( v9 <= (int)v10 && ++v9 <= v10 )
    {
      v11 = (_DWORD *)(*(_DWORD *)v8 + 24 * v9 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 6;
      }
      while ( v9 <= v10 );
    }
  }
  v12 = *(_DWORD *)(a1 + 20);
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: (int)v14);
  GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(result: v15);
  return GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(result: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10096320
// Name: private: void GASLocalFrame::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
GFxFontPackParams *__usercall GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>@<eax>(
        int a1@<ecx>,
        GFxFontPackParams *a2@<edi>,
        GFxFontPackParams *a3)
{
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // edi
  signed int v9; // esi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  int v12; // ecx
  GFxFontPackParams *v14; // [esp-4h] [ebp-Ch]
  GFxFontPackParams *v15; // [esp+0h] [ebp-8h]

  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 != 0 )
  {
    v6 = *(_DWORD *)(v4 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v4 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 6;
    }
    while ( v5 <= v6 );
    v4 = a1 + 16;
  }
  else
  {
    v5 = 0;
  }
  v14 = a2;
  v8 = v4;
  v9 = v5;
  while ( v8 != 0 && *(_DWORD *)v8 != 0 && v9 <= *(_DWORD *)(*(_DWORD *)v8 + 4) )
  {
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(result: v14);
    v10 = *(_DWORD *)(*(_DWORD *)v8 + 4);
    if ( v9 <= (int)v10 && ++v9 <= v10 )
    {
      v11 = (_DWORD *)(*(_DWORD *)v8 + 24 * v9 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 6;
      }
      while ( v9 <= v10 );
    }
  }
  v12 = *(_DWORD *)(a1 + 20);
  if ( v12 != 0 && (--*(_DWORD *)(v12 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v12 + 8) = *(_DWORD *)(v12 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v12)(a1: v12, a2: 1);
  }
  GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(result: v15);
  return GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(result: a3);
}

//------------------------------------------------------------------------------
// Address: 0x100963E0
// Name: private: void GASLocalFrame::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
GFxFontPackParams *__usercall GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>@<eax>(
        int a1@<ecx>,
        GFxFontPackParams *a2@<edi>,
        GFxFontPackParams *a3)
{
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // edi
  signed int v9; // esi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  int v12; // ecx
  int v13; // eax
  GFxFontPackParams *v15; // [esp-4h] [ebp-Ch]
  GFxFontPackParams *v16; // [esp+0h] [ebp-8h]

  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 != 0 )
  {
    v6 = *(_DWORD *)(v4 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v4 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 6;
    }
    while ( v5 <= v6 );
    v4 = a1 + 16;
  }
  else
  {
    v5 = 0;
  }
  v15 = a2;
  v8 = v4;
  v9 = v5;
  while ( v8 != 0 && *(_DWORD *)v8 != 0 && v9 <= *(_DWORD *)(*(_DWORD *)v8 + 4) )
  {
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(result: v15);
    v10 = *(_DWORD *)(*(_DWORD *)v8 + 4);
    if ( v9 <= (int)v10 && ++v9 <= v10 )
    {
      v11 = (_DWORD *)(*(_DWORD *)v8 + 24 * v9 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 6;
      }
      while ( v9 <= v10 );
    }
  }
  v12 = *(_DWORD *)(a1 + 20);
  if ( v12 != 0 )
  {
    v13 = ++*(_DWORD *)(v12 + 8);
    if ( (v13 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v12 + 8) = v13 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v12)(a1: v12, a2: 2);
    }
  }
  GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(result: v16);
  return GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(result: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10096490
// Name: private: void GASLocalFrame::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
GFxFontPackParams *__usercall GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>@<eax>(
        int a1@<ecx>,
        GFxFontPackParams *a2@<edi>,
        GFxFontPackParams *a3)
{
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // edi
  signed int v9; // esi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // ecx
  GFxFontPackParams *v14; // [esp-4h] [ebp-Ch]
  GFxFontPackParams *v15; // [esp+0h] [ebp-8h]

  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 != 0 )
  {
    v6 = *(_DWORD *)(v4 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v4 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 6;
    }
    while ( v5 <= v6 );
    v4 = a1 + 16;
  }
  else
  {
    v5 = 0;
  }
  v14 = a2;
  v8 = v4;
  v9 = v5;
  while ( v8 != 0 && *(_DWORD *)v8 != 0 && v9 <= *(_DWORD *)(*(_DWORD *)v8 + 4) )
  {
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(result: v14);
    v10 = *(_DWORD *)(*(_DWORD *)v8 + 4);
    if ( v9 <= (int)v10 && ++v9 <= v10 )
    {
      v11 = (_DWORD *)(*(_DWORD *)v8 + 24 * v9 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 6;
      }
      while ( v9 <= v10 );
    }
  }
  v12 = *(_DWORD **)(a1 + 20);
  if ( v12 != nullptr )
    GRefCountBaseGC<323>::CollectGarbage(this: v12);
  GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(result: v15);
  return GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(result: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10096520
// Name: private: void GASLocalFrame::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
GFxFontPackParams *__usercall GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>@<eax>(
        int a1@<ecx>,
        GFxFontPackParams *a2@<edi>,
        GFxFontPackParams *a3)
{
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // edi
  signed int v9; // esi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  GFxFontPackParams *v16; // [esp-4h] [ebp-Ch]
  int v17; // [esp-4h] [ebp-Ch]
  GFxFontPackParams *v18; // [esp+0h] [ebp-8h]

  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 != 0 )
  {
    v6 = *(_DWORD *)(v4 + 4);
    v5 = 0;
    v7 = (_DWORD *)(v4 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 6;
    }
    while ( v5 <= v6 );
    v4 = a1 + 16;
  }
  else
  {
    v5 = 0;
  }
  v16 = a2;
  v8 = v4;
  v9 = v5;
  while ( v8 != 0 && *(_DWORD *)v8 != 0 && v9 <= *(_DWORD *)(*(_DWORD *)v8 + 4) )
  {
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(result: v16);
    v10 = *(_DWORD *)(*(_DWORD *)v8 + 4);
    if ( v9 <= (int)v10 && ++v9 <= v10 )
    {
      v11 = (_DWORD *)(*(_DWORD *)v8 + 24 * v9 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 6;
      }
      while ( v9 <= v10 );
    }
  }
  v12 = *(_DWORD *)(a1 + 20);
  if ( v12 != 0 )
  {
    v13 = *(_DWORD *)(v12 + 8);
    if ( (v13 & 0x70000000) == 0x10000000 )
    {
      if ( (v13 & 0xFFFFFFF) != 0 )
      {
        v14 = v13 & 0x8FFFFFFF;
        v17 = 2;
      }
      else
      {
        v14 = v13 & 0x8FFFFFFF | 0x20000000;
        v17 = 4;
      }
      *(_DWORD *)(v12 + 8) = v14;
      (**(void (__thiscall ***)(int, int))v12)(a1: v12, a2: v17);
    }
  }
  GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(result: v18);
  return GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(result: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10096870
// Name: public: GASSuperObject::GASSuperObject(class GASObject __near *,class GASObjectInterface __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
CBitWrite *__thiscall GASSuperObject::GASSuperObject(CBitWrite *this, int a2, int _this, int *_this_4)
{
  int v5; // eax
  tagIMECHARPOSITION *v6; // eax
  unsigned int *m_pDataOut; // ecx

  GASObject::GASObject(result: *(_EVENTLOGRECORD **)(a2 + 4));
  this->m_pDebugName = (const char *)&GASSuperObject::`vftable'{for `GASRefCountBase<GASObject>'};
  this->m_nOutBufWord = (unsigned int)&GASSuperObject::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(a2 + 8) = (*(_DWORD *)(a2 + 8) + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 13) = a2;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = _this;
  *((_BYTE *)this + 72) = 0;
  v5 = *_this_4;
  *((_DWORD *)this + 16) = *_this_4;
  if ( v5 != 0 )
    *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 17) = 0;
  v6 = (tagIMECHARPOSITION *)_this_4[1];
  if ( v6 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v6);
  *(_DWORD *)(a2 + 8) = (*(_DWORD *)(a2 + 8) + 1) & 0x8FFFFFFF;
  m_pDataOut = this->m_pDataOut;
  if ( m_pDataOut != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)m_pDataOut, a2);
  this->m_pDataOut = (unsigned int *)a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10096920
// Name: public: virtual bool GASSuperObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASSuperObject::SetMember(
        GASSuperObject *this,
        struct GASEnvironment *a2,
        const struct GASString *a3,
        const struct GASValue *a4,
        const struct GASPropFlags *a5)
{
  return (*(bool (__thiscall **)(int, struct GASEnvironment *, const struct GASString *, const struct GASValue *, const struct GASPropFlags *))(*(_DWORD *)(*((_DWORD *)this + 9) + 16) + 12))(
           a1: *((_DWORD *)this + 9) + 16,
           a2,
           a3,
           a4,
           a5);
}

//------------------------------------------------------------------------------
// Address: 0x10096940
// Name: public: virtual bool GASSuperObject::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::SetMemberRaw(CBitWrite *this, _IMAGE_SYMBOL_EX *psc, int name, tagWNDCLASSW *val)
{
  (*(void (__thiscall **)(int, _IMAGE_SYMBOL_EX *, int, tagWNDCLASSW *))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16)
                                                                       + 40))(
    a1: *(_DWORD *)&this->m_bFlushed + 16,
    a2: psc,
    a3: name,
    a4: val);
}

//------------------------------------------------------------------------------
// Address: 0x10096960
// Name: public: virtual bool GASSuperObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::GetMember(CBitWrite *this, int penv, _IMAGE_SYMBOL_EX *name)
{
  (*(void (__thiscall **)(int, int, _IMAGE_SYMBOL_EX *))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 16))(
    a1: *(_DWORD *)&this->m_bFlushed + 16,
    a2: penv,
    a3: name);
}

//------------------------------------------------------------------------------
// Address: 0x10096980
// Name: public: virtual bool GASSuperObject::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::GetMemberRaw(CBitWrite *this, _IMAGE_SYMBOL_EX *psc)
{
  (*(void (__thiscall **)(int, _IMAGE_SYMBOL_EX *))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 44))(
    a1: *(_DWORD *)&this->m_bFlushed + 16,
    a2: psc);
}

//------------------------------------------------------------------------------
// Address: 0x100969A0
// Name: public: virtual bool GASSuperObject::FindMember(class GASStringContext __near *,class GASString const __near &,class GASMember __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::FindMember(CBitWrite *this, float psc)
{
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 20))(
    a1: *(_DWORD *)&this->m_bFlushed + 16,
    a2: LODWORD(psc));
}

//------------------------------------------------------------------------------
// Address: 0x100969C0
// Name: public: virtual bool GASSuperObject::DeleteMember(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASSuperObject::DeleteMember(CBitWrite *this, _IMAGE_SYMBOL_EX *psc, int name)
{
  return (*(bool (__thiscall **)(int, _IMAGE_SYMBOL_EX *, int))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 24))(
           a1: *(_DWORD *)&this->m_bFlushed + 16,
           a2: psc,
           a3: name);
}

//------------------------------------------------------------------------------
// Address: 0x100969E0
// Name: public: virtual bool GASSuperObject::SetMemberFlags(class GASStringContext __near *,class GASString const __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::SetMemberFlags(CBitWrite *this, _IMAGE_SYMBOL_EX *psc, int name)
{
  (*(void (__thiscall **)(int, _IMAGE_SYMBOL_EX *, int))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 28))(
    a1: *(_DWORD *)&this->m_bFlushed + 16,
    a2: psc,
    a3: name);
}

//------------------------------------------------------------------------------
// Address: 0x10096A00
// Name: public: virtual void GASSuperObject::VisitMembers(class GASStringContext __near *,struct GASObjectInterface::MemberVisitor __near *,unsigned int,class GASObjectInterface const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::VisitMembers(CBitWrite *this, int psc)
{
  (*(void (__thiscall **)(int, int))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 32))(
    a1: *(_DWORD *)&this->m_bFlushed + 16,
    a2: psc);
}

//------------------------------------------------------------------------------
// Address: 0x10096A20
// Name: public: virtual bool GASSuperObject::HasMember(class GASStringContext __near *,class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASSuperObject::HasMember(CBitWrite *this, _IMAGE_SYMBOL_EX *psc)
{
  return (*(bool (__thiscall **)(int, _IMAGE_SYMBOL_EX *))(*(_DWORD *)(*(_DWORD *)&this->m_bFlushed + 16) + 36))(
           a1: *(_DWORD *)&this->m_bFlushed + 16,
           a2: psc);
}

//------------------------------------------------------------------------------
// Address: 0x10096A40
// Name: protected: void GASSuperObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10096AA0
// Name: protected: void GASSuperObject::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10096B20
// Name: protected: void GASSuperObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10096BC0
// Name: protected: void GASSuperObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10096BF0
// Name: protected: void GASSuperObject::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10096C20
// Name: protected: virtual void GASSuperObject::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASSuperObject::ExecuteForEachChild_GC(
        CBitWrite *this@<ecx>,
        const char *operation,
        void *operation_4,
        int operation_8,
        int operation_12)
{
  switch ( (unsigned int)operation )
  {
    case 0u:
      GASSuperObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>((GPtr<IDirect3DVertexDeclaration9> *)this);
      break;
    case 1u:
      GASSuperObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>((GPtr<IDirect3DVertexDeclaration9> *)this);
      break;
    case 2u:
      GASSuperObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>((GPtr<IDirect3DVertexDeclaration9> *)this);
      break;
    case 3u:
      GASSuperObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>((GPtr<IDirect3DVertexDeclaration9> *)this);
      break;
    case 4u:
      GASSuperObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>((GPtr<IDirect3DVertexDeclaration9> *)this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096C80
// Name: public: virtual class GASFunctionRef GASSuperObject::Get__constructor__(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSuperObject::Get__constructor__(CBitWrite *this, __int64 psc)
{
  int v2; // eax
  tagIMECHARPOSITION *v3; // eax

  *(_BYTE *)(psc + 8) = 0;
  v2 = *((_DWORD *)this + 12);
  *(_DWORD *)psc = v2;
  if ( v2 != 0 )
    *(_DWORD *)(v2 + 8) = (*(_DWORD *)(v2 + 8) + 1) & 0x8FFFFFFF;
  *(_DWORD *)(psc + 4) = 0;
  v3 = *((tagIMECHARPOSITION **)this + 13);
  if ( v3 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10096CD0
// Name: public: void GASSuperObject::SetAltProto(class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASSuperObject::SetAltProto(CBitWrite *this@<ecx>, int altProto, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned int *m_pDataOut; // ecx

  v4 = *((_DWORD *)this + 13);
  if ( altProto != v4 )
  {
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
    v5 = *((_DWORD *)this + 14);
    if ( v5 != 0 )
      GRefCountBaseGC<323>::Release(a1: v5, a2: altProto);
    *((_DWORD *)this + 14) = *((_DWORD *)this + 13);
    if ( *(float *)&altProto != 0.0 )
      *(_DWORD *)(altProto + 8) = (*(_DWORD *)(altProto + 8) + 1) & 0x8FFFFFFF;
    v6 = *((_DWORD *)this + 13);
    if ( v6 != 0 )
      GRefCountBaseGC<323>::Release(a1: v6, a2: altProto);
    *((float *)this + 13) = *(float *)&altProto;
    if ( *(float *)&altProto != 0.0 )
      *(_DWORD *)(altProto + 8) = (*(_DWORD *)(altProto + 8) + 1) & 0x8FFFFFFF;
    m_pDataOut = this->m_pDataOut;
    if ( m_pDataOut != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)m_pDataOut, a2: altProto);
    this->m_pDataOut = *((unsigned int **)this + 13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096D50
// Name: public: void GFxActionLogger::LogScriptError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GFxActionLogger::LogScriptError(__vc_attributes::uuidAttribute *result, const char *a2, ...)
{
  const char *value; // ecx
  unsigned int v3; // eax
  _DWORD v4[3]; // [esp+4h] [ebp-118h] BYREF
  _DWORD v5[2]; // [esp+10h] [ebp-10Ch] BYREF
  _BYTE v6[256]; // [esp+18h] [ebp-104h] BYREF
  va_list va; // [esp+12Ch] [ebp+10h] BYREF

  va_start(va, a2);
  value = result[1].value;
  if ( value != nullptr )
  {
    if ( BYTE2(result[2].value) != 0 )
    {
      v3 = strlen(a2);
      if ( a2[v3 - 1] == 10 )
        --v3;
      v5[0] = a2;
      v5[1] = v3;
      v4[1] = v6;
      v4[0] = 2;
      v4[2] = 256;
      G_Format<GStringDataPtr,char const *>(a1: v4, a2: "{0} : {1}\n", a3: v5, a4: &result[3]);
      (*(void (__thiscall **)(const char *, int, _BYTE *, char *))(*(_DWORD *)result[1].value + 4))(
        a1: result[1].value,
        a2: 32,
        a3: v6,
        a4: va);
    }
    else
    {
      (*(void (__thiscall **)(const char *, int, const char *, char *))(*(_DWORD *)value + 4))(
        a1: value,
        a2: 32,
        a3: a2,
        a4: va);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096E30
// Name: public: void GFxActionLogger::LogScriptWarning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GFxActionLogger::LogScriptWarning(__vc_attributes::uuidAttribute *result, const char *a2, ...)
{
  const char *value; // ecx
  unsigned int v3; // eax
  _DWORD v4[3]; // [esp+4h] [ebp-118h] BYREF
  _DWORD v5[2]; // [esp+10h] [ebp-10Ch] BYREF
  _BYTE v6[256]; // [esp+18h] [ebp-104h] BYREF
  va_list va; // [esp+12Ch] [ebp+10h] BYREF

  va_start(va, a2);
  value = result[1].value;
  if ( value != nullptr )
  {
    if ( BYTE2(result[2].value) != 0 )
    {
      v3 = strlen(a2);
      if ( a2[v3 - 1] == 10 )
        --v3;
      v5[0] = a2;
      v5[1] = v3;
      v4[1] = v6;
      v4[0] = 2;
      v4[2] = 256;
      G_Format<GStringDataPtr,char const *>(a1: v4, a2: "{0} : {1}\n", a3: v5, a4: &result[3]);
      (*(void (__thiscall **)(const char *, int, _BYTE *, char *))(*(_DWORD *)result[1].value + 4))(
        a1: result[1].value,
        a2: 33,
        a3: v6,
        a4: va);
    }
    else
    {
      (*(void (__thiscall **)(const char *, int, const char *, char *))(*(_DWORD *)value + 4))(
        a1: value,
        a2: 33,
        a3: a2,
        a4: va);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096F10
// Name: GAS_GlobalASSetPropFlags
// Source: json
//------------------------------------------------------------------------------
char __cdecl GAS_GlobalASSetPropFlags(int setTrue)
{
  _SERVICE_STATUS *v2; // eax
  int v3; // ebx
  struct GASValue *v4; // edi
  SFUIMemoryFile *v5; // eax
  bool v6; // zf
  GASValue *v7; // eax
  struct GASObject *v8; // eax
  struct GASObject *v9; // ebx
  int (*pNext)(void); // eax
  GASValue *v11; // eax
  char v12; // al
  SFUIMemoryFile *v13; // eax
  GASValue *v14; // eax
  int v15; // ecx
  unsigned __int8 v16; // al
  int v17; // edi
  int (__thiscall *v18)(int, int, _LARGE_INTEGER *, int, _DWORD); // edx
  int LSeek; // edx
  int v20; // eax
  int v21; // ecx
  unsigned __int8 (__thiscall *v22)(int, int, int *, _LARGE_INTEGER *); // edx
  const struct GASEnvironment *v24; // [esp-8h] [ebp-44h]
  struct GASEnvironment *v25; // [esp-8h] [ebp-44h]
  struct GASEnvironment *v26; // [esp-8h] [ebp-44h]
  int v27; // [esp-4h] [ebp-40h]
  _LARGE_INTEGER member; // [esp+8h] [ebp-34h] BYREF
  int v29; // [esp+10h] [ebp-2Ch]
  unsigned __int8 v30; // [esp+14h] [ebp-28h]
  unsigned __int8 v31; // [esp+15h] [ebp-27h]
  int n; // [esp+18h] [ebp-24h]
  int v33; // [esp+1Ch] [ebp-20h] BYREF
  struct GASObject *v34; // [esp+20h] [ebp-1Ch] BYREF
  int i; // [esp+24h] [ebp-18h]
  int v36; // [esp+28h] [ebp-14h] BYREF
  int v37; // [esp+2Ch] [ebp-10h] BYREF
  int v38; // [esp+30h] [ebp-Ch] BYREF
  SFUIMemoryFile_vtbl *v39; // [esp+34h] [ebp-8h]
  unsigned __int8 setFalse; // [esp+3Bh] [ebp-1h]
  int setTruea; // [esp+44h] [ebp+8h]
  unsigned __int8 setTrue_3; // [esp+47h] [ebp+Bh]

  v27 = *(_DWORD *)(setTrue + 24);
  i = *(unsigned __int8 *)(v27 + 124);
  GASFnCall::Arg(this: (GASFnCall *)setTrue, a2: 0);
  v2 = GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)v27);
  v3 = (int)v2;
  setTruea = (int)v2;
  if ( v2 != nullptr )
  {
    v4 = GASFnCall::Arg(this: (GASFnCall *)setTrue, a2: 1);
    LOBYTE(v2) = *(_BYTE *)v4;
    v39 = nullptr;
    switch ( (_BYTE)v2 )
    {
      case 5:
        GASValue::ToStringImpl(a1: v4, a2: &v37, a3: *(_DWORD *)(setTrue + 24), a4: -1, a5: 0);
        v5 = GASStringProto::StringSplit(
               result: (SFUIMemoryFile *)&v34,
               putf8Buffer: *(CUtlMap<char const *,int,unsigned short>::CKeyLess *)(setTrue + 24),
               count: (int)&v37,
               a4: (bool (__cdecl *)(const char *const *, const char *const *))",",
               limit: 0x3FFFFFFF);
        if ( v5->__vftable != nullptr )
          v5->IsValid = (bool (__thiscall *)(struct SFUIMemoryFile *))(((int)v5->IsValid + 1) & 0x8FFFFFFF);
        v39 = v5->__vftable;
        if ( v34 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v34, a2: (int)v4);
        v6 = (*(_DWORD *)(v37 + 8))-- == 1;
        if ( v6 )
          GASStringNode::ReleaseNode();
        break;
      case 6:
        v24 = *(const struct GASEnvironment **)(setTrue + 24);
        v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)setTrue, a2: 1);
        v8 = GASValue::ToObject(this: v7, a2: v24);
        v9 = v8;
        if ( v8 != nullptr )
        {
          pNext = (int (*)(void))v8[2].pNode[1].pNext;
          v34 = v9 + 2;
          if ( pNext() == 7 )
          {
            v9[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v9[1].pNode->pNext + 1) & 0x8FFFFFFF);
            v39 = (SFUIMemoryFile_vtbl *)v9;
          }
          else
          {
            v2 = (_SERVICE_STATUS *)((int (__thiscall *)(struct GASObject *))v34->pNode[1].pNext)(a1: v34);
            if ( v2 != (_SERVICE_STATUS *)8 )
              return (char)v2;
            GASValue::ToStringImpl(a1: v4, a2: &v36, a3: *(_DWORD *)(setTrue + 24), a4: -1, a5: 0);
            v13 = GASStringProto::StringSplit(
                    result: (SFUIMemoryFile *)&v33,
                    putf8Buffer: *(CUtlMap<char const *,int,unsigned short>::CKeyLess *)(setTrue + 24),
                    count: (int)&v36,
                    a4: (bool (__cdecl *)(const char *const *, const char *const *))",",
                    limit: 0x3FFFFFFF);
            if ( v13->__vftable != nullptr )
              v13->IsValid = (bool (__thiscall *)(struct SFUIMemoryFile *))(((int)v13->IsValid + 1) & 0x8FFFFFFF);
            v39 = v13->__vftable;
            if ( v33 != 0 )
              GRefCountBaseGC<323>::Release(a1: v33, a2: (int)v4);
            v6 = (*(_DWORD *)(v36 + 8))-- == 1;
            if ( v6 )
              GASStringNode::ReleaseNode();
          }
        }
        v3 = setTruea;
        break;
      case 1:
        break;
      default:
        return (char)v2;
    }
    v25 = *(struct GASEnvironment **)(setTrue + 24);
    v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)setTrue, a2: 2);
    setTrue_3 = GASValue::ToInt32(this: v11, a2: v25) & 7;
    if ( *(_DWORD *)(setTrue + 28) == 3 )
    {
      v12 = (i != 5) - 1;
    }
    else
    {
      v26 = *(struct GASEnvironment **)(setTrue + 24);
      v14 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)setTrue, a2: 3);
      v12 = GASValue::ToUInt32(this: v14, a2: v26);
    }
    v15 = (int)v39;
    v16 = v12 & 7;
    v17 = *(_DWORD *)(setTrue + 24) + 120;
    setFalse = v16;
    if ( v39 != nullptr )
    {
      LSeek = (int)v39->LSeek;
      v20 = 0;
      i = 0;
      for ( n = LSeek; v20 < n; i = v20 )
      {
        v21 = *(_DWORD *)(*(_DWORD *)(v15 + 56) + 4 * v20);
        if ( v21 != 0 )
        {
          GASValue::ToStringImpl(a1: v21, a2: &v38, a3: *(_DWORD *)(setTrue + 24), a4: -1, a5: 0);
          v22 = *(unsigned __int8 (__thiscall **)(int, int, int *, _LARGE_INTEGER *))(*(_DWORD *)v3 + 20);
          LOWORD(member.LowPart) = 0;
          if ( v22(a1: v3, a2: v17, a3: &v38, a4: &member) != 0 )
            (*(void (__thiscall **)(int, int, int *, int))(*(_DWORD *)v3 + 28))(
              a1: v3,
              a2: v17,
              a3: &v38,
              a4: setTrue_3 | (unsigned __int8)(BYTE1(member.LowPart) & ~setFalse));
          GASValue::~GASValue(this: (GASValue *)&member);
          v6 = (*(_DWORD *)(v38 + 8))-- == 1;
          if ( v6 )
            GASStringNode::ReleaseNode();
        }
        v15 = (int)v39;
        v20 = i + 1;
      }
      LOBYTE(v2) = GRefCountBaseGC<323>::Release(a1: v15, a2: v17);
    }
    else
    {
      v18 = *(int (__thiscall **)(int, int, _LARGE_INTEGER *, int, _DWORD))(*(_DWORD *)v3 + 32);
      v31 = v16;
      v30 = setTrue_3;
      member.LowPart = (unsigned int)&`GAS_GlobalASSetPropFlags'::`27'::MemberVisitor::`vftable';
      member.HighPart = v3;
      v29 = v17;
      LOBYTE(v2) = v18(a1: v3, a2: v17, a3: &member, a4: 12, a5: 0);
    }
  }
  return (char)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100971C0
// Name: GAS_GlobalASnative
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalASnative(_CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  GASValue *v2; // edi
  GASValue *v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // edi
  GASValue *v6; // eax
  unsigned int v7; // eax
  int v8; // ecx
  int (__thiscall *v9)(int, int, _CONNECTDLGSTRUCTW *); // edx
  GASCFunctionObject *v10; // eax
  GASCFunctionObject *v11; // edi
  GASValue *v12; // ecx
  struct GASEnvironment *v13; // [esp-4h] [ebp-18h]
  struct GASEnvironment *v14; // [esp-4h] [ebp-18h]
  GASCFunctionObject *v15; // [esp+8h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-8h]
  char v17; // [esp+10h] [ebp-4h]

  cbStructure = fn.cbStructure;
  v2 = *(GASValue **)(fn.cbStructure + 4);
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  if ( *(int *)(cbStructure + 28) >= 2 )
  {
    v13 = *(struct GASEnvironment **)(cbStructure + 24);
    v3 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    v4 = GASValue::ToUInt32(this: v3, a2: v13);
    v14 = *(struct GASEnvironment **)(cbStructure + 24);
    v5 = v4;
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
    v7 = GASValue::ToUInt32(this: v6, a2: v14);
    if ( v5 == 800 && v7 == 2 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 656);
      v9 = *(int (__thiscall **)(int, int, _CONNECTDLGSTRUCTW *))(*(_DWORD *)v8 + 40);
      fn.cbStructure = 323;
      v10 = (GASCFunctionObject *)v9(a1: v8, a2: 56, a3: &fn);
      if ( v10 != nullptr )
        v11 = GASCFunctionObject::GASCFunctionObject(
                this: v10,
                func: (_REASON_CONTEXT *)(*(_DWORD *)(cbStructure + 24) + 120),
                a3: (void (__cdecl *)(const struct GASFnCall *))GAS_ASnativeMouseButtonStates);
      else
        v11 = nullptr;
      v17 = 0;
      v15 = v11;
      if ( v11 != nullptr )
        v11->pt.x = (v11->pt.x + 1) & 0x8FFFFFFF;
      v12 = *(GASValue **)(cbStructure + 4);
      v16 = 0;
      GASValue::SetAsFunction(this: v12, a2: (const struct GASFunctionRefBase *)&v15);
      if ( (v17 & 2) == 0 && v15 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v15, a2: (int)v11);
      v15 = nullptr;
      if ( (v17 & 1) == 0 && v16 != 0 )
        GRefCountBaseGC<323>::Release(a1: v16, a2: (int)v11);
      if ( v11 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100972D0
// Name: GAS_GlobalScreenToWorld
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_GlobalScreenToWorld(int a1@<ebx>, int a2@<edi>, int bSet)
{
  int v3; // esi
  GASValue *v4; // eax
  struct GASObject *v5; // eax
  int v6; // ebx
  int v7; // edx
  GASStringManager *v8; // ecx
  bool v9; // zf
  double v10; // st7
  float *v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const struct GASEnvironment *v15; // [esp+24h] [ebp-44h]
  GASValue val[4]; // [esp+30h] [ebp-38h] BYREF
  float v18[3]; // [esp+40h] [ebp-28h] BYREF
  char v19; // [esp+4Ch] [ebp-1Ch] BYREF
  double v20; // [esp+50h] [ebp-18h]
  float v21; // [esp+58h] [ebp-10h]
  struct GASStringNode *ConstStringNode; // [esp+5Ch] [ebp-Ch] BYREF
  float *v23; // [esp+60h] [ebp-8h]
  char v24; // [esp+67h] [ebp-1h]

  v3 = bSet;
  if ( *(_DWORD *)(bSet + 28) == 1 )
  {
    v23 = (float *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(bSet + 24) + 116) + 84))(a1: *(_DWORD *)(*(_DWORD *)(bSet + 24) + 116));
    v15 = *(const struct GASEnvironment **)(v3 + 24);
    v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 0);
    v5 = GASValue::ToObject(this: v4, a2: v15);
    v6 = (int)v5;
    if ( v5 != nullptr )
    {
      v5[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v5[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v7 = *(_DWORD *)(v3 + 24);
      LOBYTE(val[0]) = 0;
      v8 = *(GASStringManager **)(*(_DWORD *)(v7 + 120) + 636);
      HIBYTE(bSet) = 0;
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: v8,
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                          a3: 1u,
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      v24 = (*(int (__thiscall **)(int, _DWORD, struct GASStringNode **, GASValue *, int, int))(*(_DWORD *)(v6 + 16) + 16))(
              a1: v6 + 16,
              a2: *(_DWORD *)(v3 + 24),
              a3: &ConstStringNode,
              a4: val,
              a5: a2,
              a6: a1);
      v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
      if ( v9 )
        GASStringNode::ReleaseNode();
      if ( v24 != 0 )
      {
        *(float *)&bSet = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(v3 + 24));
        v10 = *(float *)&bSet - v23[32];
        HIBYTE(bSet) = 1;
        *((float *)&v20 + 1) = v10 / v23[30];
      }
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(v3 + 24) + 120) + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
                          a3: 1u,
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      v24 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)(v6 + 16) + 16))(a1: v6 + 16, a2: *(_DWORD *)(v3 + 24));
      v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
      if ( v9 )
        GASStringNode::ReleaseNode();
      if ( v24 != 0 )
      {
        *(float *)&bSet = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(v3 + 24));
        v11 = v23;
        v21 = (*(float *)&bSet - v23[33]) / v23[31];
      }
      else
      {
        if ( HIBYTE(bSet) == 0 )
        {
LABEL_21:
          GASValue::~GASValue(this: val);
          GRefCountBaseGC<323>::Release(a1: v6, a2);
          return;
        }
        v11 = v23;
      }
      if ( (*(unsigned __int8 (__thiscall **)(float *, float *, _DWORD, float, _DWORD))(*(_DWORD *)v11 + 196))(
             a1: v11,
             a2: v18,
             a3: HIDWORD(v20),
             a4: COERCE_FLOAT(LODWORD(v21)),
             a5: 0) != 0 )
      {
        v12 = *(_DWORD *)(v3 + 24);
        v20 = v18[0];
        v19 = 3;
        HIBYTE(bSet) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(*(_DWORD *)(v12 + 120) + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nGrowSize,
                            a3: 1u,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        (*(void (__thiscall **)(int, _DWORD, struct GASStringNode **, char *, char *, struct GASStringNode **, GASValue *))(*(_DWORD *)(v6 + 16) + 12))(
          a1: v6 + 16,
          a2: *(_DWORD *)(v3 + 24),
          a3: &ConstStringNode,
          a4: &v19,
          a5: (char *)&bSet + 3,
          a6: &ConstStringNode,
          a7: val);
        v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        GASValue::~GASValue(this: (GASValue *)&v19);
        v13 = *(_DWORD *)(v3 + 24);
        v20 = v18[1];
        v19 = 3;
        HIBYTE(bSet) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(*(_DWORD *)(v13 + 120) + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Memory.m_nAllocationCount,
                            a3: 1u,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        (*(void (__thiscall **)(int, _DWORD, struct GASStringNode **, char *, char *))(*(_DWORD *)(v6 + 16) + 12))(
          a1: v6 + 16,
          a2: *(_DWORD *)(v3 + 24),
          a3: &ConstStringNode,
          a4: &v19,
          a5: (char *)&bSet + 3);
        v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        GASValue::~GASValue(this: (GASValue *)&v19);
        v14 = *(_DWORD *)(v3 + 24);
        v20 = v18[2];
        v19 = 3;
        HIBYTE(bSet) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(*(_DWORD *)(v14 + 120) + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018,
                            a3: 1u,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        (*(void (__thiscall **)(int, _DWORD, struct GASStringNode **))(*(_DWORD *)(v6 + 16) + 12))(
          a1: v6 + 16,
          a2: *(_DWORD *)(v3 + 24),
          a3: &ConstStringNode);
        v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        GASValue::~GASValue(this: (GASValue *)&v19);
      }
      goto LABEL_21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097580
// Name: GAS_SetIMECandidateListStyle
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_SetIMECandidateListStyle(int a1@<edi>, _CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  int v3; // eax
  GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *v4; // edi
  GASValue *v5; // eax
  struct GASObject *v6; // eax
  int v7; // edx
  int v8; // edi
  bool v9; // zf
  GViewport *v10; // ecx
  char v11; // al
  GViewport *v12; // ecx
  char v13; // al
  GViewport *v14; // ecx
  char v15; // al
  GViewport *v16; // ecx
  char v17; // al
  GViewport *v18; // ecx
  char v19; // al
  GViewport *v20; // ecx
  char v21; // al
  GViewport *v22; // ecx
  char v23; // al
  GViewport *v24; // ecx
  char v25; // al
  GViewport *v26; // ecx
  char v27; // al
  GViewport *v28; // ecx
  char v29; // al
  const struct GASEnvironment *v30; // [esp+80h] [ebp-5Ch]
  GAmpRenderer *st[10]; // [esp+90h] [ebp-4Ch] BYREF
  __int16 v33; // [esp+B8h] [ebp-24h]
  GASValue val[4]; // [esp+BCh] [ebp-20h] BYREF
  struct GASObject *v35; // [esp+CCh] [ebp-10h]
  GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *v36; // [esp+D0h] [ebp-Ch]
  __int64 n; // [esp+D4h] [ebp-8h] BYREF
  char fn_3; // [esp+E7h] [ebp+Bh]
  char fn_3a; // [esp+E7h] [ebp+Bh]
  char fn_3b; // [esp+E7h] [ebp+Bh]
  char fn_3c; // [esp+E7h] [ebp+Bh]
  char fn_3d; // [esp+E7h] [ebp+Bh]
  char fn_3e; // [esp+E7h] [ebp+Bh]
  char fn_3f; // [esp+E7h] [ebp+Bh]
  char fn_3g; // [esp+E7h] [ebp+Bh]
  char fn_3h; // [esp+E7h] [ebp+Bh]
  char fn_3i; // [esp+E7h] [ebp+Bh]

  cbStructure = fn.cbStructure;
  if ( *(int *)(fn.cbStructure + 28) >= 1 )
  {
    v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(fn.cbStructure + 24) + 116) + 84))(a1: *(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 116));
    v4 = (GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v3 + 8) + 12))(a1: v3 + 8, a2: 27);
    v36 = v4;
    if ( v4 != nullptr )
    {
      v30 = *(const struct GASEnvironment **)(fn.cbStructure + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
      v6 = GASValue::ToObject(this: v5, a2: v30);
      v35 = v6;
      if ( v6 != nullptr )
      {
        v6[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v6[1].pNode->pNext + 1) & 0x8FFFFFFF);
        v7 = *(_DWORD *)(fn.cbStructure + 24);
        v33 = 0;
        LOBYTE(val[0]) = 0;
        v8 = (int)&v6[2];
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(v7 + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390.m_Memory.m_nGrowSize,
                       a3: 9u,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3 = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *, int))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: *(_DWORD *)(fn.cbStructure + 24),
                 a3: (char *)&n + 4,
                 a4: val,
                 a5: a1);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3 != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v10);
          if ( v11 == 0 )
          {
            v33 |= 1u;
            n = (__int64)*(double *)&n;
            st[0] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"backgroundColor",
                       a3: 0xFu,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3a = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3a != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v12);
          if ( v13 == 0 )
          {
            v33 |= 2u;
            n = (__int64)*(double *)&n;
            st[1] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F0D0,
                       a3: 0x14u,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3b = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3b != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v14);
          if ( v15 == 0 )
          {
            v33 |= 4u;
            n = (__int64)*(double *)&n;
            st[2] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F0BC,
                       a3: 0x11u,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3c = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3c != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v16);
          if ( v17 == 0 )
          {
            v33 |= 8u;
            n = (__int64)*(double *)&n;
            st[3] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F0A0,
                       a3: 0x1Bu,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3d = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3d != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v18);
          if ( v19 == 0 )
          {
            v33 |= 0x10u;
            n = (__int64)*(double *)&n;
            st[4] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F074.m_Size,
                       a3: 0x1Cu,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3e = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3e != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v20);
          if ( v21 == 0 )
          {
            v33 |= 0x20u;
            n = (__int64)*(double *)&n;
            st[5] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F074,
                       a3: 8u,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3f = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3f != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v22);
          if ( v23 == 0 )
          {
            v33 |= 0x40u;
            n = (__int64)*(double *)&n;
            st[8] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F05C,
                       a3: 0x16u,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3g = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3g != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v24);
          if ( v25 == 0 )
          {
            v33 |= 0x80u;
            n = (__int64)*(double *)&n;
            st[6] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F03C,
                       a3: 0x1Cu,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3h = (*(int (__thiscall **)(int, _DWORD, char *, GASValue *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4,
                  a4: val);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3h != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v26);
          if ( v27 == 0 )
          {
            v33 |= 0x100u;
            n = (__int64)*(double *)&n;
            st[7] = (GAmpRenderer *)n;
          }
        }
        HIDWORD(n) = GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Size,
                       a3: 0x15u,
                       a4: 0);
        ++*(_DWORD *)(HIDWORD(n) + 8);
        fn_3i = (*(int (__thiscall **)(int, _DWORD, char *))(*(_DWORD *)v8 + 16))(
                  a1: v8,
                  a2: *(_DWORD *)(cbStructure + 24),
                  a3: (char *)&n + 4);
        v9 = (*(_DWORD *)(HIDWORD(n) + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
        if ( fn_3i != 0 )
        {
          *(double *)&n = GASValue::ToNumber(this: val, a2: (struct GASEnvironment *)*(_DWORD *)(cbStructure + 24));
          GASNumberUtil::IsNaNOrInfinity(v: v28);
          if ( v29 == 0 )
          {
            v33 |= 0x200u;
            n = (__int64)*(double *)&n;
            st[9] = (GAmpRenderer *)n;
          }
        }
        GFxIMEManager::SetCandidateListStyle(this: v36, st, a3: (int)val);
        GASValue::~GASValue(this: val);
        GRefCountBaseGC<323>::Release(a1: (int)v35, a2: v8);
        v4 = v36;
      }
      GRefCountImpl::Release(this: (IShaderAPI *)v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097BE0
// Name: GAS_GetIMECandidateListStyle
// Source: json
//------------------------------------------------------------------------------
GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *__cdecl GAS_GetIMECandidateListStyle(
        _CONNECTDLGSTRUCTW fn)
{
  unsigned int cbStructure; // esi
  int v2; // eax
  GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *result; // eax
  IShaderAPI *v4; // edi
  char v5; // al
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // edx
  GASObject *v8; // eax
  GASObject *v9; // edi
  tagWNDCLASSW *v10; // ecx
  tagWNDCLASSW *v11; // edx
  tagWNDCLASSW *v12; // eax
  tagWNDCLASSW *v13; // ecx
  tagWNDCLASSW *v14; // edx
  tagWNDCLASSW *v15; // eax
  tagWNDCLASSW *v16; // ecx
  tagWNDCLASSW *v17; // edx
  tagWNDCLASSW *v18; // eax
  tagWNDCLASSW *v19; // ecx
  GAmpRenderer *pst; // [esp+8h] [ebp-40h] BYREF
  int v21; // [esp+Ch] [ebp-3Ch]
  int v22; // [esp+10h] [ebp-38h]
  int v23; // [esp+14h] [ebp-34h]
  int v24; // [esp+18h] [ebp-30h]
  int v25; // [esp+1Ch] [ebp-2Ch]
  unsigned int v26; // [esp+20h] [ebp-28h]
  unsigned int v27; // [esp+24h] [ebp-24h]
  unsigned int v28; // [esp+28h] [ebp-20h]
  unsigned int v29; // [esp+2Ch] [ebp-1Ch]
  int v30; // [esp+30h] [ebp-18h]
  GASValue v31; // [esp+34h] [ebp-14h] BYREF
  double v32; // [esp+38h] [ebp-10h]
  int v33; // [esp+44h] [ebp-4h] BYREF
  GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *fna; // [esp+50h] [ebp+8h]

  cbStructure = fn.cbStructure;
  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(fn.cbStructure + 24) + 116) + 84))(a1: *(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 116));
  result = (GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v2 + 8) + 12))(a1: v2 + 8, a2: 27);
  v4 = (IShaderAPI *)result;
  fna = result;
  if ( result != nullptr )
  {
    LOWORD(v30) = 0;
    GFxIMEManager::GetCandidateListStyle(this: result, &pst);
    if ( v5 != 0 )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 656);
      v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
      v33 = 323;
      v8 = (GASObject *)v7(a1: v6, a2: 52, a3: &v33);
      if ( v8 != nullptr )
        v9 = GASObject::GASObject(this: v8, a2: *(struct GASEnvironment **)(cbStructure + 24));
      else
        v9 = nullptr;
      if ( (v30 & 1) != 0 )
      {
        v33 = (unsigned int)pst & 0xFFFFFF;
        LOBYTE(v31) = 3;
        v10 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)((unsigned int)pst & 0xFFFFFF);
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v10 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390.m_Memory.m_nGrowSize,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 2) != 0 )
      {
        v33 = v21 & 0xFFFFFF;
        LOBYTE(v31) = 3;
        v11 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)(v21 & 0xFFFFFF);
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v11 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"backgroundColor",
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 4) != 0 )
      {
        v33 = v22 & 0xFFFFFF;
        LOBYTE(v31) = 3;
        v12 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)(v22 & 0xFFFFFF);
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v12 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F0D0,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 8) != 0 )
      {
        v33 = v23 & 0xFFFFFF;
        LOBYTE(v31) = 3;
        v13 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)(v23 & 0xFFFFFF);
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v13 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F0BC,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 0x10) != 0 )
      {
        v33 = v24 & 0xFFFFFF;
        LOBYTE(v31) = 3;
        v14 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)(v24 & 0xFFFFFF);
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v14 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F0A0,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 0x20) != 0 )
      {
        v33 = v25 & 0xFFFFFF;
        LOBYTE(v31) = 3;
        v15 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)(v25 & 0xFFFFFF);
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v15 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F074.m_Size,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 0x40) != 0 )
      {
        LOBYTE(v31) = 3;
        v16 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)v28;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v16 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F074,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 0x80u) != 0 )
      {
        LOBYTE(v31) = 3;
        v17 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)v26;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v17 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F05C,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 0x100) != 0 )
      {
        LOBYTE(v31) = 3;
        v18 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)v27;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v18 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F03C,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      if ( (v30 & 0x200) != 0 )
      {
        LOBYTE(v31) = 3;
        v19 = *(tagWNDCLASSW **)(cbStructure + 24);
        v32 = (double)v29;
        GASObjectInterface::SetConstMemberRaw(
          this: &v9[2],
          result: v19 + 3,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F018.m_Size,
          a4: (int)&v31);
        GASValue::~GASValue(this: &v31);
      }
      GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: v9);
      if ( v9 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v9, a2: (int)v9);
      v4 = (IShaderAPI *)fna;
    }
    return (GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *)GRefCountImpl::Release(this: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097F40
// Name: public: static class GASObject __near * GASGlobalContext::AddPackage(class GASStringContext __near *,class GASObject __near *,class GASObject __near *,char const __near * const)
// Source: json
//------------------------------------------------------------------------------
static struct GASObject *__cdecl GASGlobalContext::AddPackage(_TIME_DYNAMIC_ZONE_INFORMATION psc)
{
  int v1; // ecx
  struct GASStringContext *Bias; // ebx
  int v3; // esi
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // eax
  unsigned int v6; // esi
  int v7; // ecx
  unsigned __int8 *v8; // eax
  const char *v9; // ecx
  int v10; // esi
  int v11; // eax
  struct GASObject *v12; // eax
  int v13; // ecx
  int (__thiscall *v14)(int, int, int *); // eax
  GASObject *v15; // eax
  struct GASObject *v16; // eax
  GASValue *v17; // eax
  bool v18; // zf
  GASValue v20[4]; // [esp+Ch] [ebp-150h] BYREF
  GASValue pkgObjVal[4]; // [esp+1Ch] [ebp-140h] BYREF
  struct GASObject *v22; // [esp+2Ch] [ebp-130h]
  int v23; // [esp+30h] [ebp-12Ch]
  unsigned int nameSz; // [esp+34h] [ebp-128h]
  unsigned __int8 *v25; // [esp+38h] [ebp-124h]
  int v26; // [esp+3Ch] [ebp-120h]
  char *v27; // [esp+40h] [ebp-11Ch]
  int v28; // [esp+44h] [ebp-118h] BYREF
  unsigned __int8 *v29; // [esp+48h] [ebp-114h]
  int v30; // [esp+4Ch] [ebp-110h] BYREF
  unsigned __int8 *v31; // [esp+50h] [ebp-10Ch]
  char v32; // [esp+57h] [ebp-105h] BYREF
  unsigned __int8 dst[256]; // [esp+58h] [ebp-104h] BYREF

  v1 = *(_DWORD *)psc.StandardName;
  Bias = (struct GASStringContext *)psc.Bias;
  v3 = *(_DWORD *)&psc.StandardName[4];
  v22 = *(struct GASObject **)&psc.StandardName[2];
  v26 = psc.Bias;
  v23 = *(_DWORD *)&psc.StandardName[4];
  nameSz = strlen(*(const char **)&psc.StandardName[4]) + 1;
  v4 = *(unsigned __int8 **)&psc.StandardName[4];
  if ( *(_DWORD *)psc.StandardName != 0 )
    *(_DWORD *)(*(_DWORD *)psc.StandardName + 8) = (*(_DWORD *)(*(_DWORD *)psc.StandardName + 8) + 1) & 0x8FFFFFFF;
  v31 = *(unsigned __int8 **)psc.StandardName;
  if ( *(_DWORD *)&psc.StandardName[4] != 0 )
  {
    v27 = &v32;
    while ( 1 )
    {
      strchr(string: v4, chr: 0x2Eu);
      v29 = v5;
      if ( v5 != nullptr )
      {
        v6 = v5 - v4 + 1;
        v29 = v5 + 1;
      }
      else
      {
        v6 = nameSz + v3 - (_DWORD)v4;
      }
      if ( v6 > 0x100 )
        v6 = 256;
      memcpy(dst, src: v4, count: v6 - 1);
      v7 = *(_DWORD *)Bias;
      v8 = v29;
      v27[v6] = 0;
      LOBYTE(pkgObjVal[0]) = 0;
      v9 = *(const char **)(v7 + 636);
      v25 = v8;
      GASStringManager::CreateStringNode(this: v9);
      v10 = (int)v31;
      v30 = v11;
      ++*(_DWORD *)(v11 + 8);
      if ( (*(unsigned __int8 (__thiscall **)(int, struct GASStringContext *, int *, GASValue *))(*(_DWORD *)(v10 + 16)
                                                                                                + 44))(
             a1: v10 + 16,
             a2: Bias,
             a3: &v30,
             a4: pkgObjVal) != 0 )
      {
        v12 = GASValue::ToObject(this: pkgObjVal, a2: nullptr);
        if ( v12 != nullptr )
          v12[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v12[1].pNode->pNext + 1) & 0x8FFFFFFF);
        v4 = (unsigned __int8 *)v12;
      }
      else
      {
        v13 = *(_DWORD *)(*(_DWORD *)Bias + 656);
        v14 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v13 + 40);
        v28 = 323;
        v15 = (GASObject *)v14(a1: v13, a2: 52, a3: &v28);
        v16 = v15 != nullptr ? GASObject::GASObject(this: v15, a2: Bias, a3: v22) : nullptr;
        v28 = *(_DWORD *)(v10 + 16);
        v4 = (unsigned __int8 *)v16;
        v32 = 0;
        v17 = GASValue::GASValue(this: v20, a2: v16);
        Bias = (struct GASStringContext *)v26;
        (*(void (__thiscall **)(int, int, int *, GASValue *, char *))(v28 + 40))(
          a1: v10 + 16,
          a2: v26,
          a3: &v30,
          a4: v17,
          a5: &v32);
        GASValue::~GASValue(this: v20);
      }
      if ( v4 != nullptr )
        *((_DWORD *)v4 + 2) = (*((_DWORD *)v4 + 2) + 1) & 0x8FFFFFFF;
      GRefCountBaseGC<323>::Release(a1: (int)v31, a2: (int)v4);
      v18 = (*(_DWORD *)(v30 + 8))-- == 1;
      v31 = v4;
      if ( v18 )
        GASStringNode::ReleaseNode();
      if ( v4 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v4, a2: (int)v4);
      GASValue::~GASValue(this: pkgObjVal);
      if ( v29 == nullptr )
        break;
      v3 = v23;
      v4 = v25;
    }
    v1 = (int)v31;
  }
  if ( v1 == 0 )
    return nullptr;
  GRefCountBaseGC<323>::Release(a1: v1, a2: (int)v4);
  return (struct GASObject *)v31;
}

//------------------------------------------------------------------------------
// Address: 0x100981E0
// Name: public: class GASString GASGlobalContext::FindClassName(class GASEnvironment __near *,class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::FindClassName(
        vc_attributes::PostBoundAttribute *this,
        tagEMRALPHABLEND *result,
        struct GASEnvironment *a3,
        int iobj)
{
  vc_attributes::PostBoundAttribute *v4; // edi
  unsigned int v5; // edx
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // esi
  _DWORD *v10; // ecx
  int v11; // edi
  int v12; // eax
  int v13; // eax
  _IMAGE_SYMBOL_EX *v14; // edx
  GASValue *v15; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // eax
  bool v17; // bl
  unsigned int Short; // ecx
  unsigned int v19; // eax
  _DWORD *v20; // ecx
  unsigned int v21; // ecx
  unsigned int Deref; // ecx
  GASValue protoVal[4]; // [esp+Ch] [ebp-3Ch] BYREF
  int v24; // [esp+1Ch] [ebp-2Ch] BYREF
  int v25; // [esp+20h] [ebp-28h]
  char v26; // [esp+24h] [ebp-24h]
  int v27; // [esp+28h] [ebp-20h] BYREF
  int v28; // [esp+2Ch] [ebp-1Ch]
  char v29; // [esp+30h] [ebp-18h]
  int *v30; // [esp+34h] [ebp-14h]
  vc_attributes::PostBoundAttribute *v31; // [esp+3Ch] [ebp-Ch]
  _IMAGE_SYMBOL_EX *nm; // [esp+40h] [ebp-8h]
  int v33; // [esp+44h] [ebp-4h]
  struct GASObject *iobja; // [esp+58h] [ebp+10h]

  v4 = this;
  v31 = this;
  v33 = 0;
  if ( iobj == 0 )
  {
LABEL_59:
    Deref = v4[48].Deref;
    result->emr.iType = Deref;
    ++*(_DWORD *)(Deref + 8);
    return;
  }
  if ( (unsigned int)((*(int (__thiscall **)(int))(*(_DWORD *)iobj + 8))(a1: iobj) - 2) > 3 )
    iobja = (struct GASObject *)(iobj - 16);
  else
    iobja = (struct GASObject *)(*(int (__thiscall **)(int))(*(_DWORD *)(iobj - 120) + 260))(a1: iobj - 120);
  v5 = v4[170].Deref;
  v6 = *(_DWORD *)(v5 + 28);
  v7 = v5 + 28;
  if ( v6 != 0 )
  {
    v9 = *(_DWORD *)(v6 + 4);
    v8 = 0;
    v10 = (_DWORD *)(v6 + 8);
    do
    {
      if ( *v10 != -2 )
        break;
      ++v8;
      v10 += 6;
    }
    while ( v8 <= v9 );
  }
  else
  {
    v7 = 0;
    v8 = 0;
  }
  v30 = (int *)v7;
  v11 = v8;
  while ( 1 )
  {
    if ( v30 == nullptr || (v12 = *v30, *v30 == 0) || v11 > *(_DWORD *)(v12 + 4) )
    {
      v4 = v31;
      goto LABEL_59;
    }
    v13 = v12 + 24 * v11;
    v14 = (_IMAGE_SYMBOL_EX *)(v13 + 12);
    v15 = (GASValue *)(v13 + 16);
    pNode = iobja[2].pNode;
    nm = v14;
    if ( ((int (__thiscall *)(struct GASObject *))pNode[1].pNext)(a1: iobja + 2) == 23 )
    {
      v17 = false;
      if ( *(_BYTE *)v15 == 8 || *(_BYTE *)v15 == 11 )
      {
        v33 |= 1u;
        if ( *(struct GASObject **)GASValue::ToFunction(a1: &v24, a2: a3) == iobja )
          v17 = true;
      }
      if ( (v33 & 1) != 0 )
      {
        v33 &= ~1u;
        if ( (v26 & 2) == 0 && v24 != 0 )
          GRefCountBaseGC<323>::Release(a1: v24, a2: v11);
        v24 = 0;
        if ( (v26 & 1) == 0 && v25 != 0 )
          GRefCountBaseGC<323>::Release(a1: v25, a2: v11);
        v25 = 0;
      }
      if ( v17 )
      {
        Short = nm->N.Name.Short;
        result->emr.iType = nm->N.Name.Short;
        ++*(_DWORD *)(Short + 8);
        return;
      }
      goto LABEL_44;
    }
    if ( *(_BYTE *)v15 == 6 && GASValue::ToObject(this: v15, a2: a3) == iobja )
    {
      v21 = nm->N.Name.Short;
      result->emr.iType = nm->N.Name.Short;
      ++*(_DWORD *)(v21 + 8);
      return;
    }
    if ( *(_BYTE *)v15 == 8 || *(_BYTE *)v15 == 11 )
      break;
LABEL_44:
    v19 = *(_DWORD *)(*v30 + 4);
    if ( v11 <= (int)v19 && ++v11 <= v19 )
    {
      v20 = (_DWORD *)(*v30 + 24 * v11 + 8);
      do
      {
        if ( *v20 != -2 )
          break;
        ++v11;
        v20 += 6;
      }
      while ( v11 <= v19 );
    }
  }
  GASValue::ToFunction(a1: &v27, a2: a3);
  LOBYTE(protoVal[0]) = 0;
  if ( (*(unsigned __int8 (__thiscall **)(int, int, vc_attributes::PostBoundAttribute *, GASValue *))(*(_DWORD *)(v27 + 16) + 44))(
         a1: v27 + 16,
         a2: (int)a3 + 120,
         a3: v31 + 79,
         a4: protoVal) == 0
    || LOBYTE(protoVal[0]) != 6
    || GASValue::ToObject(this: protoVal, a2: a3) != iobja )
  {
    GASValue::~GASValue(this: protoVal);
    if ( (v29 & 2) == 0 && v27 != 0 )
      GRefCountBaseGC<323>::Release(a1: v27, a2: v11);
    v27 = 0;
    if ( (v29 & 1) == 0 && v28 != 0 )
      GRefCountBaseGC<323>::Release(a1: v28, a2: v11);
    v28 = 0;
    goto LABEL_44;
  }
  GASString::operator+(result);
  GASValue::~GASValue(this: protoVal);
  if ( (v29 & 2) == 0 && v27 != 0 )
    GRefCountBaseGC<323>::Release(a1: v27, a2: v11);
  v27 = 0;
  if ( (v29 & 1) == 0 && v28 != 0 )
    GRefCountBaseGC<323>::Release(a1: v28, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10098480
// Name: public: virtual void GASDoAction::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDoAction::Execute(GASDoAction *this, int a2)
{
  int v2; // ebx
  int v4; // eax
  volatile int RefCount; // ecx
  int v6; // ecx
  _NETRESOURCEW *v7; // esi
  int (__thiscall *v8)(int, int, int *); // eax
  _DWORD *v9; // eax
  _NETRESOURCEW *v10; // esi

  v2 = a2;
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 112))(a1: a2);
  RefCount = this->RefCount;
  if ( RefCount != 0 && *(_DWORD *)(RefCount + 12) != 0 && **(_BYTE **)(RefCount + 8) != 0 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(v4 + 120) + 656);
    v7 = (_NETRESOURCEW *)(v4 + 120);
    v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
    a2 = 323;
    v9 = (_DWORD *)v8(a1: v6, a2: 32, a3: &a2);
    if ( v9 != nullptr )
      v10 = GASActionBuffer::GASActionBuffer(this: v9, result: v7, pbufferData_4: (IShaderDevice *)this->RefCount);
    else
      v10 = nullptr;
    GFxSprite::AddActionBuffer(a1: v2, a2: v10, a3: 4);
    if ( v10 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098500
// Name: public: virtual void GASDoAction::ExecuteWithPriority(class GFxSprite __near *,enum GFxActionPriority::Priority)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDoAction::ExecuteWithPriority(IShaderDevice **this, int a2, int a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // edx
  _NETRESOURCEW *v9; // esi
  _DWORD *v10; // eax
  _NETRESOURCEW *v11; // esi

  v4 = (int)*(this + 1);
  if ( v4 != 0 && *(_DWORD *)(v4 + 12) != 0 && **(_BYTE **)(v4 + 8) != 0 )
  {
    v5 = a2;
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 112))(a1: a2);
    v7 = *(_DWORD *)(*(_DWORD *)(v6 + 120) + 656);
    v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
    v9 = (_NETRESOURCEW *)(v6 + 120);
    a2 = 323;
    v10 = (_DWORD *)v8(a1: v7, a2: 32, a3: &a2);
    if ( v10 != nullptr )
      v11 = GASActionBuffer::GASActionBuffer(this: v10, result: v9, pbufferData_4: *(this + 1));
    else
      v11 = nullptr;
    GFxSprite::AddActionBuffer(a1: v5, a2: v11, a3);
    if ( v11 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098580
// Name: public: virtual void GASDoInitAction::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDoInitAction::Execute(GSubImageInfo *this, int result)
{
  volatile int RefCount; // eax
  GRect<int> *v4; // edi
  int v5; // eax
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // edx
  _NETRESOURCEW *v8; // esi
  _DWORD *v9; // eax
  _NETRESOURCEW *v10; // esi

  RefCount = this->RefCount;
  if ( RefCount != 0 && *(_DWORD *)(RefCount + 12) != 0 && **(_BYTE **)(RefCount + 8) != 0 )
  {
    v4 = (GRect<int> *)result;
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)result + 112))(a1: result);
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 120) + 656);
    v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
    v8 = (_NETRESOURCEW *)(v5 + 120);
    result = 323;
    v9 = (_DWORD *)v7(a1: v6, a2: 32, a3: &result);
    if ( v9 != nullptr )
      v10 = GASActionBuffer::GASActionBuffer(this: v9, result: v8, pbufferData_4: (IShaderDevice *)this->RefCount);
    else
      v10 = nullptr;
    GFxSprite::AddActionBuffer(a1: v4, a2: v10, a3: 2);
    if ( v10 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098600
// Name: void GFx_DoActionLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DoActionLoader(IShaderDeviceMgr *p, GArrayLH<GString,2,GArrayDefaultPolicy> **tagInfo)
{
  GArrayLH<GString,2,GArrayDefaultPolicy> *v2; // ecx
  IShaderDeviceMgr_vtbl *v3; // ecx
  unsigned int Init; // edx
  CP4File *p_QueryInterface; // ecx
  CP4File_vtbl *v6; // eax
  GPtr<GImageInfoBase> *v7; // ebx
  IShaderDeviceMgr *v8; // edi
  unsigned int v9; // esi
  GPtr<GImageInfoBase> **v10; // eax

  GFxLogBase<GFxLoadProcess>::LogParse(
    this: *tagInfo,
    pfmt: (unsigned int)&p[5],
    a3: (int)"tag %d: DoActionLoader\n",
    a4: (char)*tagInfo);
  GFxLogBase<GFxLoadProcess>::LogParseAction(
    this: v2,
    pfmt: (unsigned int)&p[5],
    a3: (int)"-- actions in frame %d\n",
    a4: (char)p[8].__vftable[1].GetModeInfo);
  v3 = p[8].__vftable;
  Init = (unsigned int)v3->Init;
  p_QueryInterface = (CP4File *)&v3->QueryInterface;
  if ( Init < 8 )
  {
    v6 = GFxDataAllocator::OverflowAlloc(this: p_QueryInterface, bytes: 8u);
  }
  else
  {
    v6 = p_QueryInterface->__vftable;
    p_QueryInterface->__vftable = (CP4File_vtbl *)((char *)p_QueryInterface->__vftable + 8);
    p_QueryInterface->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(Init - 8);
  }
  v7 = nullptr;
  if ( v6 != nullptr )
  {
    v6->dtr_CP4File = (void (__thiscall *)(CP4File *))&stru_1029EE3C.m_Memory.m_nGrowSize;
    v6->Edit = nullptr;
    v7 = (GPtr<GImageInfoBase> *)v6;
  }
  GASDoAction::Read(this: v7, p);
  v8 = &p[3 * (int)p[190].__vftable + 192];
  v9 = (unsigned int)&v8[1].Connect + 1;
  if ( (IShaderDeviceMgr_vtbl *)v9 >= v8[1].__vftable )
  {
    if ( (IShaderDeviceMgr_vtbl *)v9 >= v8[2].__vftable )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v8,
        result: (D3DXVECTOR4 *)v8,
        newCapacity: v9 + (v9 >> 2));
  }
  else if ( v9 < (unsigned int)v8[2].__vftable >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v8,
      result: (D3DXVECTOR4 *)v8,
      newCapacity: (unsigned int)&v8[1].Connect + 1);
  }
  v10 = (GPtr<GImageInfoBase> **)((char *)v8->__vftable + 4 * v9 - 4);
  v8[1].__vftable = (IShaderDeviceMgr_vtbl *)v9;
  if ( v10 != nullptr )
    *v10 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100986D0
// Name: void GFx_DoInitActionLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DoInitActionLoader(IShaderDeviceMgr *p, const struct GFxTagInfo *tagInfo)
{
  IShaderDeviceMgr_vtbl *v2; // esi
  int v3; // eax
  int (__thiscall *GetModeCount)(IShaderDeviceMgr *, int); // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v5; // ecx
  char v6; // bl
  GArrayLH<GString,2,GArrayDefaultPolicy> *v7; // ecx
  IShaderDeviceMgr_vtbl *v8; // ecx
  unsigned int Init; // eax
  CP4File *p_QueryInterface; // ecx
  CP4File_vtbl *v11; // edx
  int p_Add; // esi
  CP4File_vtbl *v13; // eax
  GPtr<GImageInfoBase> *v14; // ebx
  D3DXVECTOR4 *v15; // edi
  unsigned int v16; // esi
  float x; // eax
  GPtr<GImageInfoBase> **v18; // esi

  v2 = p[201].__vftable;
  if ( v2 == nullptr )
    v2 = (IShaderDeviceMgr_vtbl *)&p[10];
  v3 = (char *)v2->GetModeInfo - (char *)v2->GetModeCount;
  BYTE1(v2->GetDependencies) = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  GetModeCount = v2->GetModeCount;
  v5 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)*((unsigned __int8 *)v2->SetMode + (unsigned int)GetModeCount);
  v6 = *((_BYTE *)v2->SetMode + (unsigned int)GetModeCount);
  v2->GetModeCount = (int (__thiscall *)(IShaderDeviceMgr *, int))((char *)GetModeCount + 2);
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: v5,
    pfmt: (unsigned int)&p[5],
    a3: (int)"  tag %d: DoInitActionLoader\n",
    a4: *(_DWORD *)tagInfo);
  GFxLogBase<GFxLoadProcess>::LogParseAction(
    this: v7,
    pfmt: (unsigned int)&p[5],
    a3: (int)"  -- init actions for sprite %d\n",
    a4: v6);
  v8 = p[8].__vftable;
  Init = (unsigned int)v8->Init;
  p_QueryInterface = (CP4File *)&v8->QueryInterface;
  if ( Init < 8 )
  {
    v13 = GFxDataAllocator::OverflowAlloc(this: p_QueryInterface, bytes: 8u);
  }
  else
  {
    v11 = p_QueryInterface->__vftable;
    p_Add = (int)&p_QueryInterface->Add;
    p_QueryInterface->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(Init - 8);
    p_QueryInterface->__vftable = (CP4File_vtbl *)p_Add;
    v13 = v11;
  }
  v14 = nullptr;
  if ( v13 != nullptr )
  {
    v13->Edit = nullptr;
    v13->dtr_CP4File = (void (__thiscall *)(CP4File *))&off_1029EEFC;
    v14 = (GPtr<GImageInfoBase> *)v13;
  }
  GASDoAction::Read(this: v14, p);
  v15 = (D3DXVECTOR4 *)&p[198];
  v16 = (unsigned int)&p[199].Connect + 1;
  if ( (IShaderDeviceMgr_vtbl *)v16 >= p[199].__vftable )
  {
    if ( (IShaderDeviceMgr_vtbl *)v16 >= p[200].__vftable )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v15,
        result: v15,
        newCapacity: v16 + (v16 >> 2));
  }
  else if ( v16 < (unsigned int)p[200].__vftable >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v15,
      result: v15,
      newCapacity: v16);
  }
  x = v15->x;
  p[199].__vftable = (IShaderDeviceMgr_vtbl *)v16;
  v18 = (GPtr<GImageInfoBase> **)(LODWORD(x) + 4 * v16 - 4);
  if ( v18 != nullptr )
    *v18 = v14;
}

//------------------------------------------------------------------------------
// Address: 0x10098820
// Name: public: void GASActionBuffer::ProcessDeclDict(class GASStringContext __near *,unsigned int,unsigned int,class GFxActionLogger __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASActionBuffer::ProcessDeclDict(
        GASActionBuffer *this,
        struct GASStringContext *startPc,
        unsigned int count,
        unsigned int stopPc,
        __vc_attributes::uuidAttribute *log)
{
  unsigned int dwControlKeyState; // eax
  int v7; // eax
  int v8; // ecx
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // ebx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  bool v16; // zf
  int v17; // eax
  int v18; // esi
  int v19; // edi
  int v20; // [esp+8h] [ebp-Ch]
  unsigned int *p_dwEventFlags; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h]
  unsigned int counta; // [esp+20h] [ebp+Ch]

  dwControlKeyState = this->dwControlKeyState;
  if ( *(_DWORD *)(dwControlKeyState + 12) == 0 || *(_BYTE *)(v7 = *(_DWORD *)(dwControlKeyState + 8)) == 0 )
    v7 = 0;
  v8 = *((_DWORD *)this + 7);
  v22 = v7;
  if ( v8 != count )
  {
    if ( v8 == -1 )
    {
      *((_DWORD *)this + 7) = count;
      v10 = *(unsigned __int16 *)(v7 + count + 3);
      counta = v10;
      v11 = count + 2;
      p_dwEventFlags = &this->dwEventFlags;
      GArrayBase<GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>>::Resize(
        this: (int)&this->dwEventFlags,
        newSize: v10);
      v12 = 0;
      if ( v10 != 0 )
      {
        while ( 1 )
        {
          GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)startPc + 636));
          v14 = v13;
          ++*(_DWORD *)(v13 + 8);
          v15 = *p_dwEventFlags + 4 * v12;
          ++*(_DWORD *)(v13 + 8);
          v16 = (*(_DWORD *)(*(_DWORD *)v15 + 8))-- == 1;
          v20 = v15;
          if ( v16 )
          {
            GASStringNode::ReleaseNode();
            v15 = v20;
          }
          *(_DWORD *)v15 = v14;
          v16 = (*(_DWORD *)(v14 + 8))-- == 1;
          if ( v16 )
            GASStringNode::ReleaseNode();
          if ( *(_BYTE *)(v22 + v11 + 3) != 0 )
            break;
LABEL_16:
          ++v12;
          ++v11;
          if ( v12 >= counta )
            return;
        }
        while ( v11 < stopPc )
        {
          ++v11;
          if ( *(_BYTE *)(v22 + v11 + 3) == 0 )
            goto LABEL_16;
        }
        if ( (*((unsigned __int8 (__thiscall **)(__vc_attributes::uuidAttribute *))log->value + 1))(a1: log) != 0 )
          GFxActionLogger::LogScriptError(result: log, a2: "Error: Action buffer dict length exceeded\n");
        for ( ; v12 < counta; ++v12 )
        {
          GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)startPc + 636));
          v18 = v17;
          ++*(_DWORD *)(v17 + 8);
          v19 = *p_dwEventFlags + 4 * v12;
          ++*(_DWORD *)(v17 + 8);
          v16 = (*(_DWORD *)(*(_DWORD *)v19 + 8))-- == 1;
          if ( v16 )
            GASStringNode::ReleaseNode();
          *(_DWORD *)v19 = v18;
          v16 = (*(_DWORD *)(v18 + 8))-- == 1;
          if ( v16 )
            GASStringNode::ReleaseNode();
        }
      }
    }
    else if ( (*((unsigned __int8 (__thiscall **)(__vc_attributes::uuidAttribute *))log->value + 1))(a1: log) != 0 )
    {
      GFxActionLogger::LogScriptError(
        result: log,
        a2: "Error: ProcessDeclDict(%d, %d) - DeclDict was already processed at %d\n",
        count,
        stopPc,
        *((_DWORD *)this + 7));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100989B0
// Name: public: GASExecutionContext::WithStackHolder::~WithStackHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::WithStackHolder::~WithStackHolder(GPtr<GJPEGSystem> *this)
{
  void **v1; // esi

  v1 = *((void ***)this + 1);
  if ( v1 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v1);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100989E0
// Name: public: void GASExecutionContext::WithStackHolder::PushBack(class GASWithStackEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::WithStackHolder::PushBack(GPtr<GJPEGSystem> *this, _DWORD *a2)
{
  GJPEGOutput *(__thiscall *CreateOutput)(GJPEGSystem *, GFile *); // eax
  _DWORD *v4; // eax
  AvatarImageLoaded_t *v5; // edi
  unsigned int v6; // esi
  int m_comp; // edi
  int v8; // [esp+8h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 1) == 0 )
  {
    CreateOutput = this->pObject->__vftable[1].CreateOutput;
    v8 = 323;
    v4 = (_DWORD *)((int (__stdcall *)(int, int *))CreateOutput)(a1: 12, a2: &v8);
    if ( v4 != nullptr )
    {
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    *((_DWORD *)this + 1) = v4;
  }
  v5 = *((AvatarImageLoaded_t **)this + 1);
  v6 = *((_DWORD *)&v5->m_steamID.m_steamid.m_comp + 1) + 1;
  if ( v6 >= *((_DWORD *)&v5->m_steamID.m_steamid.m_comp + 1) )
  {
    if ( v6 >= v5->m_iImage )
      GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve(
        this: v5,
        pheapAddr: v5,
        newCapacity: v6 + (v6 >> 2));
  }
  else if ( v6 < (unsigned int)v5->m_iImage >> 1 )
  {
    GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve(
      this: v5,
      pheapAddr: v5,
      newCapacity: *((_DWORD *)&v5->m_steamID.m_steamid.m_comp + 1) + 1);
  }
  *((_DWORD *)&v5->m_steamID.m_steamid.m_comp + 1) = v6;
  m_comp = (int)v5->m_steamID.m_steamid.m_comp;
  *(_DWORD *)(m_comp + 8 * v6 - 8) = *a2;
  *(_DWORD *)(m_comp + 8 * v6 - 4) = a2[1];
}

//------------------------------------------------------------------------------
// Address: 0x10098AC0
// Name: public: void GASEnvironment::CheckTryBlocks(int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::CheckTryBlocks(
        __vc_attributes::unhookAttribute *this,
        const char *pc,
        const char *plocalTryBlockCount)
{
  int v5; // ecx
  int v6; // eax
  const char *v7; // ebx
  _DWORD *v8; // eax
  unsigned int v9; // edx
  int localTryBlockCount; // [esp+18h] [ebp+Ch]

  v5 = *(_DWORD *)plocalTryBlockCount;
  localTryBlockCount = v5;
  if ( v5 > 0 )
  {
    v6 = *((_DWORD *)this + 42);
    if ( v6 != 0 )
    {
      v7 = pc;
      do
      {
        if ( v5 < 0 )
          break;
        v8 = (_DWORD *)(*((_DWORD *)this + 41) + 12 * v6 - 12);
        v9 = v8[1];
        if ( (unsigned int)v7 >= v9 )
        {
          v7 = pc;
          if ( (unsigned int)pc < v9 + (*(unsigned __int8 *)(*v8 + 1) | (*(unsigned __int8 *)(*v8 + 2) << 8)) )
            break;
        }
        --*(_DWORD *)plocalTryBlockCount;
        GArrayData<GASEnvironment::TryDescr,GAllocatorLH<GASEnvironment::TryDescr,2>,GArrayDefaultPolicy>::Resize(
          this: (__vc_attributes::v1_enumAttribute *)this + 164,
          newSize: *((_DWORD *)this + 42) - 1);
        v6 = *((_DWORD *)this + 42);
        v5 = --localTryBlockCount;
      }
      while ( v6 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098B50
// Name: public: void GASEnvironment::PushTryBlock(struct GASEnvironment::TryDescr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::PushTryBlock(GASEnvironment *this, const struct GASEnvironment::TryDescr *a2)
{
  GASEnvironment *v2; // edi
  unsigned int v3; // esi
  char *v4; // eax
  char *v5; // eax

  v2 = this + 41;
  v3 = *((_DWORD *)this + 42) + 1;
  if ( v3 >= *((_DWORD *)this + 42) )
  {
    if ( v3 >= *((_DWORD *)this + 43) )
      GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v2,
        pheapAddr: v2,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < *((_DWORD *)this + 43) >> 1 )
  {
    GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)v2,
      pheapAddr: v2,
      newCapacity: *((_DWORD *)this + 42) + 1);
  }
  v4 = (char *)*v2;
  *((_DWORD *)v2 + 1) = v3;
  v5 = &v4[12 * v3 - 12];
  if ( v5 != nullptr )
  {
    *(_DWORD *)v5 = *(_DWORD *)a2;
    *((_DWORD *)v5 + 1) = *(_DWORD *)&a2[4];
    *((_DWORD *)v5 + 2) = *(_DWORD *)&a2[8];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098BC0
// Name: public: void GASEnvironment::LogScriptError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void GASEnvironment::LogScriptError(GASEnvironment *this, const char *a2, ...)
{
  int v2; // esi
  unsigned int v3; // eax
  int v4; // edx
  _DWORD v5[3]; // [esp+8h] [ebp-118h] BYREF
  _DWORD v6[2]; // [esp+14h] [ebp-10Ch] BYREF
  _BYTE v7[256]; // [esp+1Ch] [ebp-104h] BYREF
  va_list va; // [esp+130h] [ebp+10h] BYREF

  va_start(va, a2);
  v2 = *((_DWORD *)this + 40);
  if ( v2 != 0 )
  {
    if ( *(_DWORD *)(v2 + 4) != 0 )
    {
      if ( *(_BYTE *)(v2 + 10) != 0 )
      {
        v3 = strlen(a2);
        if ( a2[v3 - 1] == 10 )
          --v3;
        v6[0] = a2;
        v6[1] = v3;
        v5[1] = v7;
        v5[0] = 2;
        v5[2] = 256;
        G_Format<GStringDataPtr,char const *>(a1: v5, a2: "{0} : {1}\n", a3: v6, a4: v2 + 12);
        (*(void (__stdcall **)(int, _BYTE *, char *))(**(_DWORD **)(v2 + 4) + 4))(a1: 32, a2: v7, a3: va);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, int, const char *, char *))(**(_DWORD **)(v2 + 4) + 4))(
          a1: *(_DWORD *)(v2 + 4),
          a2: 32,
          a3: a2,
          a4: va);
      }
    }
  }
  else if ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 168))(a1: *((_DWORD *)this + 29)) != 0 )
  {
    v4 = *(_DWORD *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 168))(a1: *((_DWORD *)this + 29));
    (*(void (__stdcall **)(int, const char *, char *))(v4 + 4))(a1: 32, a2, a3: va);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098CE0
// Name: public: void GASEnvironment::LogScriptWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void GASEnvironment::LogScriptWarning(GASEnvironment *this, const char *a2, ...)
{
  int v2; // esi
  unsigned int v3; // eax
  int v4; // edx
  _DWORD v5[3]; // [esp+8h] [ebp-118h] BYREF
  _DWORD v6[2]; // [esp+14h] [ebp-10Ch] BYREF
  _BYTE v7[256]; // [esp+1Ch] [ebp-104h] BYREF
  va_list va; // [esp+130h] [ebp+10h] BYREF

  va_start(va, a2);
  v2 = *((_DWORD *)this + 40);
  if ( v2 != 0 )
  {
    if ( *(_DWORD *)(v2 + 4) != 0 )
    {
      if ( *(_BYTE *)(v2 + 10) != 0 )
      {
        v3 = strlen(a2);
        if ( a2[v3 - 1] == 10 )
          --v3;
        v6[0] = a2;
        v6[1] = v3;
        v5[1] = v7;
        v5[0] = 2;
        v5[2] = 256;
        G_Format<GStringDataPtr,char const *>(a1: v5, a2: "{0} : {1}\n", a3: v6, a4: v2 + 12);
        (*(void (__stdcall **)(int, _BYTE *, char *))(**(_DWORD **)(v2 + 4) + 4))(a1: 33, a2: v7, a3: va);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, int, const char *, char *))(**(_DWORD **)(v2 + 4) + 4))(
          a1: *(_DWORD *)(v2 + 4),
          a2: 33,
          a3: a2,
          a4: va);
      }
    }
  }
  else if ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 168))(a1: *((_DWORD *)this + 29)) != 0 )
  {
    v4 = *(_DWORD *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 168))(a1: *((_DWORD *)this + 29));
    (*(void (__stdcall **)(int, const char *, char *))(v4 + 4))(a1: 33, a2, a3: va);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098E00
// Name: public: bool GASEnvironment::FindAndGetVariableRaw(struct GASEnvironment::GetVarParams const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASEnvironment::FindAndGetVariableRaw(GASEnvironment *this, _SYSTEM_AUDIT_CALLBACK_ACE *rv)
{
  unsigned int Mask; // ecx
  unsigned int SidStart; // edx
  _ACE_HEADER Header; // eax
  unsigned int v6; // edx
  bool Variable; // bl
  struct GASEnvironment::GetVarParams v9[4]; // [esp+8h] [ebp-28h] BYREF
  unsigned int v10; // [esp+Ch] [ebp-24h]
  unsigned int v11; // [esp+10h] [ebp-20h]
  _ACE_HEADER v12; // [esp+14h] [ebp-1Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **p_owner; // [esp+18h] [ebp-18h]
  unsigned int v14; // [esp+1Ch] [ebp-14h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *owner; // [esp+20h] [ebp-10h] BYREF

  if ( (*(_DWORD *)(**(_DWORD **)&rv->Header + 12) & 0x2000000) != 0
    || GASEnvironment::IsPath(varPath: *(_IMAGE_SYMBOL_EX **)&rv->Header) == 0 )
  {
    return GASEnvironment::GetVariableRaw(this, rv);
  }
  Mask = rv->Mask;
  SidStart = rv->SidStart;
  *(_ACE_HEADER *)v9 = rv->Header;
  Header = rv[1].Header;
  v10 = Mask;
  v12 = Header;
  v11 = SidStart;
  v6 = rv[1].SidStart;
  p_owner = &owner;
  LOBYTE(owner) = 0;
  v14 = v6;
  Variable = GASEnvironment::FindVariable(this, a2: v9, onlyTargets: false, a4: nullptr);
  if ( (_BYTE)owner != 0 && (_BYTE)owner != 10 )
  {
    if ( rv[1].Mask != 0 )
      GASValue::operator=(v: (tagWNDCLASSW *)&owner);
    GASValue::~GASValue(this: &owner);
    return Variable;
  }
  else
  {
    if ( (rv[1].SidStart & 4) == 0 )
      GASEnvironment::LogScriptError(
        this,
        a2: "Error: GetVariable failed: can't resolve the path \"%s\"\n",
        ***(_DWORD ***)&rv->Header);
    GASValue::~GASValue(this: &owner);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098EE0
// Name: public: class GFxASCharacter __near * GASEnvironment::FindTargetByValue(class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
struct GFxASCharacter *__thiscall GASEnvironment::FindTargetByValue(
        GASEnvironment *this,
        __vc_attributes::event_receiverAttribute::type_e path)
{
  int v4; // eax
  int v5; // esi

  if ( *(_BYTE *)path == 7 )
    return GASValue::ToASCharacter(this: (GASValue *)path, a2: (const struct GASEnvironment *)this);
  if ( *(_BYTE *)path == 5 )
  {
    GASValue::ToStringImpl(a1: path, a2: &path, a3: this, a4: -1, a5: 0);
    GASEnvironment::FindTarget(
      (__vc_attributes::event_receiverAttribute *)this,
      (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)&path,
      excludeFlags: false);
    v5 = v4;
    if ( (*(_DWORD *)(path + 8))-- == 1 )
      GASStringNode::ReleaseNode();
    return (struct GFxASCharacter *)v5;
  }
  else
  {
    GASEnvironment::LogScriptError(this, a2: "Error: Invalid movie clip path; neither string nor object\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098F50
// Name: public: class GASFunctionRef GASEnvironment::GetConstructor(enum GASBuiltinType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::GetConstructor(
        __vc_attributes::async_uuidAttribute *this,
        const char *className,
        int a3)
{
  int v4; // edx
  GASValue ctor[4]; // [esp+Ch] [ebp-10h] BYREF

  v4 = *((_DWORD *)this + 30);
  LOBYTE(ctor[0]) = 0;
  if ( (*(unsigned __int8 (__thiscall **)(int, __vc_attributes::async_uuidAttribute *, int, GASValue *))(*(_DWORD *)(*(_DWORD *)(v4 + 680) + 16) + 44))(
         a1: *(_DWORD *)(v4 + 680) + 16,
         a2: this + 30,
         a3: v4 + 4 * a3 + 8,
         a4: ctor) != 0
    && (LOBYTE(ctor[0]) == 8 || LOBYTE(ctor[0]) == 11) )
  {
    GASValue::ToFunction(a1: className, a2: this);
    GASValue::~GASValue(this: ctor);
  }
  else
  {
    *((_BYTE *)className + 8) = 0;
    *(_DWORD *)className = 0;
    *((_DWORD *)className + 1) = 0;
    GASValue::~GASValue(this: ctor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098FE0
// Name: public: class GASValue GASEnvironment::PrimitiveToTempObject(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::PrimitiveToTempObject(
        __vc_attributes::idl_quoteAttribute *this,
        GASValue *index,
        unsigned int indexa)
{
  int v3; // edx
  int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  char *v7; // ebx
  char v8; // bl
  int v9; // ebx
  struct GASObject *v10; // esi

  v3 = *((_DWORD *)this + 7);
  v4 = (*((_DWORD *)this + 2) - *((_DWORD *)this + 3)) >> 4;
  v5 = indexa;
  v6 = v4 + 32 * (v3 - 1);
  v7 = nullptr;
  if ( indexa <= v6 )
  {
    v5 = indexa;
    v7 = (char *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * ((v6 - indexa) >> 5)) + 16 * ((v6 - indexa) & 0x1F));
  }
  v8 = *v7;
  switch ( v8 )
  {
    case 2:
      v9 = 5;
      break;
    case 5:
      v9 = 3;
      break;
    case 3:
    case 4:
      v9 = 4;
      break;
    default:
      *(_BYTE *)index = 0;
      return;
  }
  v10 = GASEnvironment::OperatorNew(
          (GASEnvironment *)this,
          a2: *(struct GASObject **)(*((_DWORD *)this + 30) + 680),
          a3: (const struct GASString *)(*((_DWORD *)this + 30) + 4 * v9 + 8),
          nargs: 1,
          argsTopOff: 32 * v3 + v4 - 32 - v5);
  GASValue::GASValue(this: index, a2: v10);
  if ( v10 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v10, a2: (int)index);
}

//------------------------------------------------------------------------------
// Address: 0x100990A0
// Name: private: virtual void GASLocalFrame::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
GFxFontPackParams *__userpurge GASLocalFrame::ExecuteForEachChild_GC@<eax>(
        int a1@<ecx>,
        GFxFontPackParams *a2@<edi>,
        GFxFontPackParams *operation)
{
  GFxFontPackParams *result; // eax
  GFxFontPackParams *savedregs; // [esp+0h] [ebp+0h]

  result = operation;
  switch ( (unsigned int)operation )
  {
    case 0u:
      result = GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1, a2, a3: savedregs);
      break;
    case 1u:
      result = GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(a1, a2, a3: savedregs);
      break;
    case 2u:
      result = GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(a1, a2, a3: savedregs);
      break;
    case 3u:
      result = GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(a1, a2, a3: savedregs);
      break;
    case 4u:
      result = GASLocalFrame::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(a1, a2, a3: savedregs);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099100
// Name: public: GASRefCountCollector::GASRefCountCollector(void)
// Source: json
//------------------------------------------------------------------------------
GASRefCountCollector *__thiscall GASRefCountCollector::GASRefCountCollector(GASRefCountCollector *this)
{
  this->__vftable = (IDataCacheSection_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 32) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 6) = -1;
  this->__vftable = (IDataCacheSection_vtbl *)&GASRefCountCollector::`vftable';
  *((_DWORD *)this + 10) = 1000;
  *((_DWORD *)this + 17) = 1000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10099160
// Name: public: GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>(struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
const GPtr<IDirect3DSurface9> *__thiscall GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>(
        GPtr<IDirect3DSurface9> *this,
        const GPtr<IDirect3DSurface9> *result,
        int next)
{
  IDirect3DSurface9 *pObject; // eax
  GPtr<IDirect3DSurface9> *v5; // ecx
  IDirect3DSurface9 *v6; // eax
  tagIMECHARPOSITION *v7; // eax

  this->pObject = (IDirect3DSurface9 *)next;
  pObject = result->pObject;
  *(this + 1) = (GPtr<IDirect3DSurface9>)result->pObject;
  ++pObject[2].__vftable;
  v5 = this + 2;
  LOBYTE(v5[2].pObject) = 0;
  v6 = result[1].pObject;
  v5->pObject = v6;
  if ( v6 != nullptr )
    v6[2].__vftable = (IDirect3DSurface9_vtbl *)(((int)&v6[2].QueryInterface + 1) & 0x8FFFFFFF);
  v5[1].pObject = nullptr;
  v7 = (tagIMECHARPOSITION *)result[2].pObject;
  if ( v7 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10099420
// Name: bool GAS_Invoke(class GASValue const __near &,class GASValue __near *,class GASObjectInterface __near *,class GASEnvironment __near *,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GAS_Invoke(
        tagWNDCLASSW *result,
        GASValue *a2,
        GASObjectInterface *nargs,
        GASEnvironment *a4,
        int a5,
        int firstArgBottomIndex,
        const char *a7)
{
  int v7; // ecx
  const char *v9; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v10; // eax
  int v11; // eax
  const char *v12; // eax
  _DWORD v13[3]; // [esp+Ch] [ebp-30h] BYREF
  int v14; // [esp+18h] [ebp-24h]
  int v15; // [esp+1Ch] [ebp-20h]
  char v16; // [esp+20h] [ebp-1Ch]
  GASEnvironment *v17; // [esp+24h] [ebp-18h]
  int v18; // [esp+28h] [ebp-14h]
  int v19; // [esp+2Ch] [ebp-10h]
  int v20; // [esp+30h] [ebp-Ch] BYREF
  int v21; // [esp+34h] [ebp-8h]
  char v22; // [esp+38h] [ebp-4h]

  GASValue::ToFunction(a1: &v20, a2: a4);
  if ( a2 != nullptr )
  {
    GASValue::DropRefs(this: a2);
    *(_BYTE *)a2 = 0;
  }
  v7 = v20;
  if ( v20 != 0 )
  {
    v13[2] = nargs;
    v19 = firstArgBottomIndex;
    v13[1] = a2;
    v18 = a5;
    v13[0] = &GASFnCall::`vftable';
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v17 = a4;
    (*(void (__thiscall **)(int, _DWORD *, int, const char *))(*(_DWORD *)v20 + 40))(a1: v20, a2: v13, a3: v21, a4: a7);
    v13[0] = &GASFnCall::`vftable';
    if ( (v16 & 2) == 0 && v14 != 0 )
      GRefCountBaseGC<323>::Release(a1: v14, a2: (int)a4);
    v14 = 0;
    if ( (v16 & 1) == 0 && v15 != 0 )
      GRefCountBaseGC<323>::Release(a1: v15, a2: (int)a4);
    if ( (v22 & 2) == 0 && v20 != 0 )
      GRefCountBaseGC<323>::Release(a1: v20, a2: (int)a4);
    v20 = 0;
    if ( (v22 & 1) == 0 && v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: v21, a2: (int)a4);
    return 1;
  }
  else
  {
    if ( a4 != nullptr )
    {
      if ( (*(unsigned __int8 (__thiscall **)(GASEnvironment *))(*a4 + 4))(a1: a4) != 0 )
      {
        if ( nargs != nullptr
          && (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)nargs + 8))(a1: nargs) - 2) <= 3 )
        {
          v9 = a7;
          if ( a7 == nullptr )
            v9 = "<unknown>";
          v10 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: nargs);
          if ( DWORD1(v10[6].m_pfnProxied) != 0 )
            v11 = DWORD1(v10[6].m_pfnProxied);
          else
            GFxASCharacter::CreateCharacterHandle(this: v10);
          GASEnvironment::LogScriptError(
            this: a4,
            a2: "Error: Invoked method %s.%s is not a function\n",
            **(const char ***)(v11 + 12),
            v9);
        }
        else
        {
          v12 = a7;
          if ( a7 == nullptr )
            v12 = "<unknown>";
          GASEnvironment::LogScriptError(this: a4, a2: "Error: Invoked method %s is not a function\n", v12);
        }
      }
      v7 = v20;
    }
    if ( (v22 & 2) == 0 && v7 != 0 )
      GRefCountBaseGC<323>::Release(a1: v7, a2: (int)a4);
    v20 = 0;
    if ( (v22 & 1) == 0 && v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: v21, a2: (int)a4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100995B0
// Name: bool GAS_InvokeParsed(class GASValue const __near &,class GASValue __near *,class GASObjectInterface __near *,class GASEnvironment __near *,char const __near *,char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GAS_InvokeParsed(
        void *method,
        tagWNDCLASSW *methoda,
        GASValue *a3,
        char *args,
        GASEnvironment *a5,
        const char *a6,
        int a7,
        const char *a8)
{
  int v8; // edi
  GASEnvironment *v9; // ecx
  __vc_attributes::iid_isAttribute *v10; // esi
  int v11; // edi
  char v12; // al
  char *v13; // edx
  int *v14; // ebx
  int v15; // edi
  char v16; // al
  char *v17; // edx
  __vc_attributes::iid_isAttribute v18; // eax
  int v19; // ecx
  __vc_attributes::iid_isAttribute v20; // eax
  char *limited_expression; // eax
  bool v22; // cl
  double v23; // st7
  __vc_attributes::iid_isAttribute v24; // eax
  __vc_attributes::iid_isAttribute v25; // eax
  double v26; // st7
  char v27; // al
  double v28; // st7
  __vc_attributes::iid_isAttribute v29; // eax
  __vc_attributes::iid_isAttribute v30; // eax
  double v31; // st7
  const char *v32; // ecx
  struct GASStringNode *StringNode; // eax
  struct GASStringNode *v34; // edi
  __vc_attributes::iid_isAttribute v35; // eax
  char *v37; // edx
  char i; // al
  unsigned int v39; // edx
  unsigned int v40; // ecx
  char v41; // al
  const wchar_t *v42; // eax
  GASStringManager *v43; // ecx
  unsigned int v44; // eax
  tagWNDCLASSW *v45; // ebx
  const struct GASValue *v46; // edi
  GASValue **v47; // esi
  char j; // bl
  const char *v50; // [esp+0h] [ebp-34h]
  GASValue v51[4]; // [esp+Ch] [ebp-28h] BYREF
  double v52; // [esp+1Ch] [ebp-18h]
  int startingIndex; // [esp+24h] [ebp-10h]
  int v54; // [esp+28h] [ebp-Ch]
  int nargs; // [esp+2Ch] [ebp-8h]
  bool v56; // [esp+33h] [ebp-1h]
  int v57; // [esp+4Ch] [ebp+18h]

  v8 = 0;
  if ( a6 == nullptr )
    goto LABEL_70;
  v9 = a5;
  v10 = (__vc_attributes::iid_isAttribute *)(a5 + 2);
  v11 = ((*((_DWORD *)a5 + 2) - *((_DWORD *)a5 + 3)) >> 4) + 32 * *((_DWORD *)a5 + 7) - 32;
  v12 = *a6;
  v13 = (char *)(a6 + 1);
  startingIndex = v11;
  nargs = (int)(a6 + 1);
  if ( v12 == 0 )
    goto LABEL_55;
  v14 = (int *)(a7 - 4);
  v15 = a7 - 8;
  while ( 1 )
  {
    if ( v12 == 37 )
    {
      v16 = *v13;
      v17 = v13 + 1;
      nargs = (int)v17;
      if ( v16 == 100 )
      {
        v10->limited_expression += 16;
        v15 += 4;
        ++v14;
        if ( *((_DWORD *)a5 + 2) >= *((_DWORD *)a5 + 4) )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
        v18.limited_expression = v10->limited_expression;
        if ( v10->limited_expression != nullptr )
        {
          v19 = *v14;
          *v18.limited_expression = 4;
          *((_DWORD *)v18.limited_expression + 1) = v19;
        }
      }
      else if ( v16 == 117 )
      {
        v10->limited_expression += 16;
        v20.limited_expression = v10->limited_expression;
        LOBYTE(v51[0]) = 0;
        if ( (unsigned int)v20.limited_expression >= *((_DWORD *)a5 + 4) )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
        if ( v10->limited_expression != nullptr )
          GASValue::GASValue(this: (GASValue *)v10->limited_expression, a2: (const struct GASValue *)v51);
        GASValue::~GASValue(this: v51);
      }
      else if ( v16 == 110 )
      {
        v10->limited_expression += 16;
        if ( *((_DWORD *)a5 + 2) >= *((_DWORD *)a5 + 4) )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
        if ( v10->limited_expression != nullptr )
          *v10->limited_expression = 1;
      }
      else if ( v16 == 98 )
      {
        ++v14;
        v15 += 4;
        v56 = *v14 != 0;
        v10->limited_expression += 16;
        if ( *((_DWORD *)a5 + 2) >= *((_DWORD *)a5 + 4) )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
        limited_expression = (char *)v10->limited_expression;
        if ( v10->limited_expression != nullptr )
        {
          v22 = v56;
          *limited_expression = 2;
          limited_expression[4] = v22;
        }
      }
      else if ( v16 == 102 )
      {
        v23 = *(double *)(v15 + 8);
        v10->limited_expression += 16;
        v24.limited_expression = v10->limited_expression;
        v52 = v23;
        v15 += 8;
        v14 += 2;
        if ( (unsigned int)v24.limited_expression >= *((_DWORD *)a5 + 4) )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
        v25.limited_expression = v10->limited_expression;
        if ( v10->limited_expression != nullptr )
        {
          v26 = v52;
          *v25.limited_expression = 3;
          *(double *)(v25.limited_expression + 4) = v26;
        }
      }
      else if ( v16 == 104 )
      {
        v27 = *v17;
        nargs = (int)(v17 + 1);
        if ( v27 == 102 )
        {
          v28 = *(double *)(v15 + 8);
          v10->limited_expression += 16;
          v29.limited_expression = v10->limited_expression;
          v52 = v28;
          v15 += 8;
          v14 += 2;
          if ( (unsigned int)v29.limited_expression >= *((_DWORD *)a5 + 4) )
            GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
          v30.limited_expression = v10->limited_expression;
          if ( v10->limited_expression != nullptr )
          {
            v31 = v52;
            *v30.limited_expression = 3;
            *(double *)(v30.limited_expression + 4) = v31;
          }
        }
        else
        {
          GASEnvironment::LogScriptError(
            this: v9,
            a2: "Error: InvokeParsed('%s','%s') - invalid format '%%h%c'\n",
            a8,
            a6,
            v27);
        }
      }
      else
      {
        if ( v16 == 115 )
        {
          v32 = *(const char **)(*((_DWORD *)v9 + 30) + 636);
          ++v14;
          v54 = v15 + 4;
          GASStringManager::CreateStringNode(this: v32);
        }
        else
        {
          if ( v16 != 108 )
          {
            GASEnvironment::LogScriptError(
              this: v9,
              a2: "Error: InvokeParsed('%s','%s') - invalid format '%%%c'\n",
              a8,
              a6,
              v16);
            goto LABEL_48;
          }
          v41 = *v17;
          nargs = (int)(v17 + 1);
          if ( v41 != 115 )
          {
            GASEnvironment::LogScriptError(
              this: v9,
              a2: "Error: InvokeParsed('%s','%s') - invalid format '%%l%c'\n",
              a8,
              a6,
              v41);
            goto LABEL_48;
          }
          v42 = (const wchar_t *)v14[1];
          v43 = *(GASStringManager **)(*((_DWORD *)v9 + 30) + 636);
          ++v14;
          v54 = v15 + 4;
          StringNode = GASStringManager::CreateStringNode(this: v43, a2: v42);
        }
        v34 = StringNode;
        ++*((_DWORD *)StringNode + 2);
        v10->limited_expression += 16;
        if ( *((_DWORD *)a5 + 2) >= *((_DWORD *)a5 + 4) )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v50);
        v35.limited_expression = v10->limited_expression;
        if ( v10->limited_expression != nullptr )
        {
          *v35.limited_expression = 5;
          *((_DWORD *)v35.limited_expression + 1) = v34;
          ++*((_DWORD *)v34 + 2);
        }
        if ( (*((_DWORD *)v34 + 2))-- == 1 )
          GASStringNode::ReleaseNode();
        v15 = v54;
      }
    }
    else
    {
      GASEnvironment::LogScriptError(this: v9, a2: "Error: InvokeParsed('%s','%s') - invalid char '%c'\n", a8, a6, v12);
    }
LABEL_48:
    v37 = (char *)nargs;
    for ( i = *(_BYTE *)nargs; i != 0; i = *++v37 )
    {
      if ( i != 32 && i != 9 && i != 44 )
        break;
    }
    v12 = *v37;
    v13 = v37 + 1;
    nargs = (int)v13;
    if ( v12 == 0 )
      break;
    v9 = a5;
  }
  v11 = startingIndex;
LABEL_55:
  nargs = 32 * *((_DWORD *)a5 + 7) + ((*((_DWORD *)a5 + 2) - *((_DWORD *)a5 + 3)) >> 4) - v11 - 32;
  if ( nargs >> 1 > 0 )
  {
    v39 = v11 + 1;
    v40 = v11 + nargs;
    v57 = v11 + 1;
    v54 = v11 + nargs;
    startingIndex = nargs >> 1;
    while ( 1 )
    {
      v44 = 32 * (*((_DWORD *)a5 + 7) - 1) + ((*((_DWORD *)a5 + 2) - *((_DWORD *)a5 + 3)) >> 4);
      v45 = nullptr;
      if ( v40 <= v44 )
        v45 = (tagWNDCLASSW *)(*(_DWORD *)(*((_DWORD *)a5 + 6) + 4 * (v40 >> 5)) + 16 * (v40 & 0x1F));
      v46 = nullptr;
      if ( v39 <= v44 )
        v46 = (const struct GASValue *)(*(_DWORD *)(*((_DWORD *)a5 + 6) + 4 * (v39 >> 5)) + 16 * (v39 & 0x1F));
      GASValue::GASValue(this: v51, a2: v46);
      GASValue::operator=(v: v45);
      GASValue::operator=(v: (tagWNDCLASSW *)v51);
      GASValue::~GASValue(this: v51);
      ++v57;
      --v54;
      if ( --startingIndex == 0 )
        break;
      v40 = v54;
      v39 = v57;
    }
  }
  v8 = nargs;
LABEL_70:
  v47 = (GASValue **)(a5 + 2);
  for ( j = GAS_Invoke(
              result: methoda,
              a2: a3,
              nargs: (GASObjectInterface *)args,
              a4: a5,
              a5: v8,
              firstArgBottomIndex: ((*((_DWORD *)a5 + 2) - *((_DWORD *)a5 + 3)) >> 4) + 32 * *((_DWORD *)a5 + 7) - 32,
              a7: a8); v8 != 0; --v8 )
  {
    GASValue::~GASValue(this: *v47);
    *v47 -= 4;
    if ( *((_DWORD *)a5 + 2) < *((_DWORD *)a5 + 3) )
      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v47, a2: v50);
  }
  return j;
}

//------------------------------------------------------------------------------
// Address: 0x100999A0
// Name: _GASExecutionContext::EnumerateOpCode_::_15_::EnumerateOpVisitor::Visit
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::EnumerateOpCode_::_15_::EnumerateOpVisitor::Visit(
        GPtr<GFxPNGSupport> *this,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *__formal,
        int flags)
{
  __vc_attributes::iid_isAttribute *v5; // esi
  char *limited_expression; // esi
  GFxPNGSupport_vtbl *Short; // eax
  const char *v8; // [esp+0h] [ebp-8h]

  v5 = *((__vc_attributes::iid_isAttribute **)this + 1);
  v5[2].limited_expression += 16;
  if ( v5[2].limited_expression >= v5[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: v5 + 2, a2: v8);
  limited_expression = (char *)v5[2].limited_expression;
  if ( limited_expression != nullptr )
  {
    *limited_expression = 5;
    Short = (GFxPNGSupport_vtbl *)name->N.Name.Short;
    *((_DWORD *)limited_expression + 1) = name->N.Name.Short;
    ++Short[1].dtr_GRefCountImplCore;
  }
  if ( *((_DWORD *)this + 2) != 0 )
    CDummyMaterialSystem::EndBatch();
}

//------------------------------------------------------------------------------
// Address: 0x10099A00
// Name: public: void GASExecutionContext::WaitForFrameOpCode(class GASActionBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::WaitForFrameOpCode(
        GPtr<GJPEGSystem> *this,
        GASActionBuffer *len,
        unsigned int skipCount)
{
  GJPEGSystem *pObject; // eax
  int v5; // eax
  char v6; // bl
  unsigned int v7; // esi
  char v8; // al
  __vc_attributes::iid_isAttribute *v9; // esi
  unsigned int v10; // eax
  const GPtr<GFxZlibSupportBase> *LoadingFrame; // eax
  unsigned int v12; // eax
  int v13; // ebx
  int v14; // ecx
  char v15; // dl
  _TAPE_WMI_OPERATIONS *v16; // [esp+0h] [ebp-14h]
  _TAPE_WMI_OPERATIONS *v17; // [esp+Ch] [ebp-8h]
  unsigned int frame; // [esp+10h] [ebp-4h] BYREF
  unsigned int lena; // [esp+1Ch] [ebp+8h]
  unsigned int skipCounta; // [esp+20h] [ebp+Ch]

  pObject = this->pObject;
  frame = 0;
  if ( (pObject[24].RefCount & 0x20000) != 0 )
    v17 = nullptr;
  else
    v17 = GASObjectInterface::ToSprite(result: v16);
  if ( skipCount == 138 )
  {
    v5 = *((_DWORD *)this + 2) + *((_DWORD *)this + 6);
    v6 = 1;
    frame = *(unsigned __int16 *)(v5 + 3);
    v7 = *(unsigned __int8 *)(v5 + 5);
  }
  else
  {
    v8 = GASActionBuffer::ResolveFrameNumber(
           this: len,
           a2: (__vc_attributes::event_receiverAttribute *)this->pObject,
           a3: (GASValue *)this->pObject[1].__vftable,
           a4: nullptr,
           a5: &frame);
    v9 = (__vc_attributes::iid_isAttribute *)this->pObject;
    v6 = v8;
    skipCounta = *(unsigned __int8 *)(*((_DWORD *)this + 6) + *((_DWORD *)this + 2) + 3);
    GASValue::~GASValue(this: (GASValue *)this->pObject[1].__vftable);
    v9[2].limited_expression -= 16;
    if ( v9[2].limited_expression < v9[3].limited_expression )
      GASPagedStack<GASValue,32>::PopPage(this: v9 + 2, a2: (const char *)v16);
    v7 = skipCounta;
  }
  if ( v17 != nullptr && v6 != 0 )
  {
    v10 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v17[15].DataBufferSize + 40))(a1: v17[15].DataBufferSize);
    if ( v10 != 0 && frame >= v10 )
      frame = v10 - 1;
    LoadingFrame = GFxSprite::GetLoadingFrame(result: (const GPtr<GFxZlibSupportBase> *)v16);
    if ( frame >= (unsigned int)LoadingFrame )
    {
      v12 = *((_DWORD *)this + 5);
      v13 = 0;
      lena = *(_DWORD *)(len->dwControlKeyState + 12);
      if ( v7 != 0 )
      {
        while ( v12 < lena )
        {
          v14 = *((_DWORD *)this + 2);
          v15 = *(_BYTE *)(v14 + v12++);
          if ( v15 < 0 )
            v12 += *(unsigned __int16 *)(v14 + v12) + 2;
          if ( ++v13 >= v7 )
            goto LABEL_20;
        }
      }
      else
      {
LABEL_20:
        if ( v12 < lena )
        {
          *((_DWORD *)this + 5) = v12;
          return;
        }
      }
      if ( (*((_BYTE *)this + 54) & 1) != 0 )
        GFxActionLogger::LogScriptError(
          result: (__vc_attributes::uuidAttribute *)this + 9,
          a2: "Error: WaitForFrame branch to offset %d - this section only runs to %d\n",
          *((_DWORD *)this + 5),
          *((_DWORD *)this + 4));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099B50
// Name: public: bool GASEnvironment::GetMember(class GASObjectInterface __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASEnvironment::GetMember(
        GASEnvironment *this,
        _IMAGE_SYMBOL_EX *memberName,
        GASValue *a3,
        struct GASValue *a4)
{
  int (__thiscall *v4)(_IMAGE_SYMBOL_EX *, GASEnvironment *, GASValue *, struct GASValue *); // edx
  bool result; // al
  struct GFxASCharacter *v8; // eax
  GRefCountNTSImpl *v9; // esi
  struct GASObjectInterface *v10; // eax
  GASEnvironment *v11; // esi
  GASValue *v12; // ecx
  GASValue v13; // eax
  struct GFxASCharacter *v14; // eax
  GRefCountNTSImpl *v15; // ebx
  _IMAGE_SYMBOL_EX *v16; // ecx
  int v17; // eax
  const char *v18; // [esp+0h] [ebp-40h]
  _DWORD v19[5]; // [esp+Ch] [ebp-34h] BYREF
  char v20; // [esp+20h] [ebp-20h]
  GASEnvironment *v21; // [esp+24h] [ebp-1Ch]
  int v22; // [esp+28h] [ebp-18h]
  int v23; // [esp+2Ch] [ebp-14h]
  int v24; // [esp+30h] [ebp-10h] BYREF
  int v25; // [esp+34h] [ebp-Ch]
  char v26; // [esp+38h] [ebp-8h]
  GASEnvironment *v27; // [esp+3Ch] [ebp-4h]
  bool rv; // [esp+53h] [ebp+13h]

  v4 = *(int (__thiscall **)(_IMAGE_SYMBOL_EX *, GASEnvironment *, GASValue *, struct GASValue *))(memberName->N.Name.Short
                                                                                                 + 16);
  v27 = this;
  result = v4(a1: memberName, a2: this, a3, a4);
  rv = result;
  if ( result && *(_BYTE *)a4 == 9 )
  {
    v8 = GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)memberName);
    v9 = (GRefCountNTSImpl *)v8;
    if ( v8 != nullptr )
    {
      ++*((_DWORD *)v8 + 1);
      v10 = (struct GFxASCharacter *)((char *)v8 + 120);
    }
    else
    {
      v10 = (struct GASObjectInterface *)memberName;
    }
    GASValue::GetPropertyValue(this: (GASValue *)a4, a2: (struct GASEnvironment *)this, a3: v10, a4);
    if ( v9 != nullptr )
    {
      GRefCountNTSImpl::Release(this: v9);
      return rv;
    }
  }
  else
  {
    if ( *(_BYTE *)a4 != 12 )
      return result;
    GASValue::ToResolveHandler(a1: a4, a2: &v24);
    if ( v24 != 0 )
    {
      *((_DWORD *)this + 2) += 16;
      v11 = this + 2;
      if ( *((_DWORD *)this + 2) >= *((_DWORD *)this + 4) )
        GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)this + 2, a2: v18);
      v12 = (GASValue *)*v11;
      if ( *v11 != never )
      {
        *(_BYTE *)v12 = 5;
        v13 = *a3;
        v12[1] = *a3;
        ++v13->m_nGrowSize;
      }
      v14 = GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)memberName);
      v15 = (GRefCountNTSImpl *)v14;
      if ( v14 != nullptr )
        ++*((_DWORD *)v14 + 1);
      GASValue::DropRefs(this: (GASValue *)a4);
      *(_BYTE *)a4 = 0;
      v16 = (_IMAGE_SYMBOL_EX *)&v15[15];
      if ( v15 == nullptr )
        v16 = memberName;
      v17 = ((*v11 - *((_DWORD *)v11 + 1)) >> 4) + 32 * *((_DWORD *)v11 + 5) - 32;
      v19[2] = v16;
      v19[3] = 0;
      v19[4] = 0;
      v21 = v27;
      v23 = v17;
      v19[0] = &GASFnCall::`vftable';
      v19[1] = a4;
      v20 = 0;
      v22 = 1;
      (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v24 + 40))(a1: v24, a2: v19, a3: v25, a4: 0);
      GASFnCall::~GASFnCall(this: v19);
      GASValue::~GASValue(this: *(GASValue **)v11);
      *v11 -= 16;
      if ( *v11 < *((_DWORD *)v11 + 1) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v11, a2: v18);
      rv = true;
      if ( v15 != nullptr )
        GRefCountNTSImpl::Release(this: v15);
    }
    else
    {
      rv = false;
    }
    if ( (v26 & 2) == 0 && v24 != 0 )
      GRefCountBaseGC<323>::Release(a1: v24, a2: (int)a4);
    v24 = 0;
    if ( (v26 & 1) == 0 && v25 != 0 )
      GRefCountBaseGC<323>::Release(a1: v25, a2: (int)a4);
  }
  return rv;
}

//------------------------------------------------------------------------------
// Address: 0x10099EA0
// Name: public: GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>(class GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>(
        GPtr<IDirect3DSurface9> *this,
        const GPtr<IDirect3DSurface9> *e)
{
  IDirect3DSurface9 *pObject; // ecx
  IDirect3DSurface9 *v4; // edx
  tagIMECHARPOSITION *v5; // edx

  this->pObject = e->pObject;
  pObject = e[1].pObject;
  *((_DWORD *)this + 1) = pObject;
  ++pObject[2].__vftable;
  *((_BYTE *)this + 16) = 0;
  v4 = e[2].pObject;
  *((_DWORD *)this + 2) = v4;
  if ( v4 != nullptr )
    v4[2].__vftable = (IDirect3DSurface9_vtbl *)(((int)&v4[2].QueryInterface + 1) & 0x8FFFFFFF);
  *((_DWORD *)this + 3) = 0;
  v5 = (tagIMECHARPOSITION *)e[3].pObject;
  if ( v5 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1009A000
// Name: public: GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>(struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeRef const __near &,int)
// Source: json
//------------------------------------------------------------------------------
IDirect3DSurface9 *__thiscall GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>(
        IDirect3DSurface9 *this,
        GPtr<IDirect3DSurface9> *result,
        int next)
{
  IDirect3DSurface9_vtbl *v4; // eax
  IDirect3DSurface9 *pObject; // edx
  IDirect3DSurface9_vtbl *v6; // eax
  tagIMECHARPOSITION *v7; // eax

  this->__vftable = (IDirect3DSurface9_vtbl *)next;
  v4 = result->pObject->__vftable;
  *((_DWORD *)this + 1) = v4;
  ++v4->Release;
  pObject = result[1].pObject;
  *((_BYTE *)this + 16) = 0;
  v6 = pObject->__vftable;
  *(this + 2) = (IDirect3DSurface9)pObject->__vftable;
  if ( v6 != nullptr )
    v6->Release = (unsigned int (__stdcall *)(IUnknown *))(((int)v6->Release + 1) & 0x8FFFFFFF);
  *((_DWORD *)this + 3) = 0;
  v7 = (tagIMECHARPOSITION *)pObject[1].__vftable;
  if ( v7 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009A060
// Name: public: GHashsetNodeEntry<struct GHashNode<class GASString,struct GASGlobalContext::ClassRegEntry,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASGlobalContext::ClassRegEntry,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<struct GHashNode<class GASString,struct GASGlobalContext::ClassRegEntry,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASGlobalContext::ClassRegEntry,struct GASStringHashFunctor>::NodeHashF>(class GHashsetNodeEntry<struct GHashNode<class GASString,struct GASGlobalContext::ClassRegEntry,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GASGlobalContext::ClassRegEntry,struct GASStringHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
GPtr<IDirect3DSurface9> *__thiscall GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>(
        GPtr<IDirect3DSurface9> *this,
        GPtr<IDirect3DSurface9> *a2)
{
  GPtr<IDirect3DSurface9> *result; // eax
  IDirect3DSurface9 *pObject; // edx
  IDirect3DSurface9 *v4; // edx

  result = this;
  this->pObject = a2->pObject;
  pObject = a2[1].pObject;
  *((_DWORD *)this + 1) = pObject;
  ++pObject[2].__vftable;
  *(this + 2) = a2[2];
  v4 = a2[3].pObject;
  if ( v4 != nullptr )
    v4[2].__vftable = (IDirect3DSurface9_vtbl *)(((int)&v4[2].QueryInterface + 1) & 0x8FFFFFFF);
  *(this + 3) = a2[3];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A100
// Name: GAS_GlobalTrace
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_GlobalTrace(_CONNECTDLGSTRUCTW fn)
{
  GASObjectInterface *v1; // edi
  int v2; // edx
  _DWORD *v3; // eax
  int v4; // eax
  bool v5; // zf
  int v6; // edi
  struct GASValue *v7; // eax
  unsigned int v8; // edi
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t *v9; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t *i; // eax
  _SERVICE_STATUS *v11; // [esp-4h] [ebp-808h]
  GASValue result[4]; // [esp+8h] [ebp-7FCh] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *method; // [esp+18h] [ebp-7ECh] BYREF
  int v14; // [esp+28h] [ebp-7DCh] BYREF
  int v15; // [esp+2Ch] [ebp-7D8h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t _Dst; // [esp+30h] [ebp-7D4h] BYREF

  v11 = *(_SERVICE_STATUS **)(fn.cbStructure + 24);
  GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
  v1 = (GASObjectInterface *)GASValue::ToObjectInterface(result: v11);
  if ( v1 != nullptr )
  {
    v2 = *(_DWORD *)v1;
    v3 = (_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 120);
    LOBYTE(method) = 0;
    if ( (*(unsigned __int8 (__thiscall **)(GASObjectInterface *, _DWORD *, int, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(v2 + 44))(
           a1: v1,
           a2: v3,
           a3: *v3 + 352,
           a4: &method) != 0
      && ((_BYTE)method == 8 || (_BYTE)method == 11) )
    {
      v4 = *(_DWORD *)(fn.cbStructure + 24);
      LOBYTE(result[0]) = 0;
      GAS_Invoke(
        result: (tagWNDCLASSW *)&method,
        a2: result,
        nargs: v1,
        a4: (GASEnvironment *)v4,
        a5: 0,
        firstArgBottomIndex: ((*(_DWORD *)(v4 + 8) - *(_DWORD *)(v4 + 12)) >> 4) + 32 * *(_DWORD *)(v4 + 28) - 31,
        a7: nullptr);
      GASValue::ToStringImpl(a1: result, a2: &v14, a3: *(_DWORD *)(fn.cbStructure + 24), a4: -1, a5: 0);
      GFxLogBase<GASFnCall>::LogScriptMessage(
        this: *(CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t **)v14,
        pfmt: (GASFnCall *)fn.cbStructure,
        a3: (int)"%s\n",
        a4: *(_DWORD *)v14);
      v5 = (*(_DWORD *)(v14 + 8))-- == 1;
      if ( v5 )
        GASStringNode::ReleaseNode();
      GASValue::~GASValue(this: result);
      GASValue::~GASValue(this: &method);
      return;
    }
    GASValue::~GASValue(this: &method);
  }
  v6 = *(_DWORD *)(fn.cbStructure + 24);
  v7 = GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
  GASValue::ToStringImpl(a1: v7, a2: &v15, a3: v6, a4: -1, a5: 0);
  v8 = *(_DWORD *)(v15 + 16);
  if ( v8 >= 0x7D0 )
    v8 = 1999;
  strncpy_s((char *)&_Dst, _SizeInBytes: 0x7D0u, _Src: *(const char **)v15, _Count: v8);
  *((_BYTE *)&_Dst.index + v8) = 0;
  for ( i = &_Dst;
        LOBYTE(i->index) != 0;
        i = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t *)((char *)i + 1) )
  {
    if ( LOBYTE(i->index) == 13 )
      LOBYTE(i->index) = 10;
  }
  if ( *(_DWORD *)(v15 + 16) >= 0x7D0u )
    GFxLogBase<GASFnCall>::LogScriptMessage(
      this: &_Dst,
      pfmt: (GASFnCall *)fn.cbStructure,
      a3: (int)"%s ...<truncated>\n",
      a4: (char)&_Dst);
  else
    GFxLogBase<GASFnCall>::LogScriptMessage(
      this: v9,
      pfmt: (GASFnCall *)fn.cbStructure,
      a3: (int)"%s\n",
      a4: (char)&_Dst);
  v5 = (*(_DWORD *)(v15 + 8))-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode();
}

//------------------------------------------------------------------------------
// Address: 0x1009A300
// Name: public: void GASExecutionContext::StartDragOpCode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASExecutionContext::StartDragOpCode(__vc_attributes::uuidAttribute *this@<ecx>, const char *a2@<ebx>)
{
  tagPOLYTEXTW *value; // eax
  unsigned __int8 v4; // al
  char *v5; // ecx
  unsigned int v7; // eax
  GASValue *v8; // ecx
  __vc_attributes::uuidAttribute v9; // edx
  GASValue *v10; // ecx
  unsigned int v11; // eax
  __vc_attributes::uuidAttribute v12; // edx
  GASValue *v13; // ecx
  unsigned int v14; // eax
  __vc_attributes::uuidAttribute v15; // edx
  GASValue *v16; // ecx
  unsigned int v17; // eax
  __vc_attributes::uuidAttribute v18; // esi
  int v19; // ebx
  int v20; // eax
  const char *v21; // [esp-8h] [ebp-34h]
  const char *v22; // [esp+0h] [ebp-2Ch]
  struct GFxASCharacter *TargetByValue; // [esp+4h] [ebp-28h] BYREF
  __int16 v24; // [esp+8h] [ebp-24h]
  float v25; // [esp+Ch] [ebp-20h]
  float v26; // [esp+10h] [ebp-1Ch]
  float v27; // [esp+14h] [ebp-18h]
  float v28; // [esp+18h] [ebp-14h]
  float v29; // [esp+1Ch] [ebp-10h]
  float v30; // [esp+20h] [ebp-Ch]
  bool v31[4]; // [esp+24h] [ebp-8h]
  float v32; // [esp+28h] [ebp-4h] BYREF

  v26 = 0.0;
  value = (tagPOLYTEXTW *)this->value;
  v25 = 0.0;
  v28 = 0.0;
  TargetByValue = nullptr;
  v27 = 0.0;
  v24 = 0;
  v30 = 0.0;
  v29 = 0.0;
  v4 = (unsigned __int8)GASValue::ToBool(result: value);
  v5 = (char *)this->value;
  v31[0] = v4;
  TargetByValue = GASEnvironment::FindTargetByValue(
                    this: (GASEnvironment *)v5,
                    path: *((__vc_attributes::event_receiverAttribute::type_e *)v5 + 2));
  if ( TargetByValue == nullptr && (*((_BYTE *)this + 54) & 1) != 0 )
  {
    GASValue::ToDebugString(a1: *((_DWORD *)this->value + 2), a2: &v32, a3: this->value);
    GFxActionLogger::LogScriptError(
      result: this + 9,
      a2: "Error: StartDrag of invalid target '%s'.\n",
      *(const char **)LODWORD(v32));
    if ( (*(_DWORD *)(LODWORD(v32) + 8))-- == 1 )
      GASStringNode::ReleaseNode();
  }
  HIBYTE(v24) = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)this->value);
  if ( HIBYTE(v24) != 0 )
  {
    v7 = 32 * (*((_DWORD *)this->value + 7) - 1) + ((*((_DWORD *)this->value + 2) - *((_DWORD *)this->value + 3)) >> 4);
    v8 = nullptr;
    if ( v7 >= 6 )
      v8 = (GASValue *)(*(_DWORD *)(*((_DWORD *)this->value + 6) + 4 * ((v7 - 6) >> 5)) + 16 * ((v7 - 6) & 0x1F));
    v32 = GASValue::ToNumber(this: v8, a2: (struct GASEnvironment *)this->value);
    v9.value = this->value;
    v10 = nullptr;
    v25 = v32 * 20.0;
    v11 = 32 * (*((_DWORD *)v9.value + 7) - 1) + ((*((_DWORD *)v9.value + 2) - *((_DWORD *)v9.value + 3)) >> 4);
    if ( v11 >= 5 )
      v10 = (GASValue *)(*(_DWORD *)(*((_DWORD *)v9.value + 6) + 4 * ((v11 - 5) >> 5)) + 16 * ((v11 - 5) & 0x1F));
    v32 = GASValue::ToNumber(this: v10, a2: (struct GASEnvironment *)v9.value);
    v12.value = this->value;
    v13 = nullptr;
    v26 = v32 * 20.0;
    v14 = 32 * (*((_DWORD *)v12.value + 7) - 1) + ((*((_DWORD *)v12.value + 2) - *((_DWORD *)v12.value + 3)) >> 4);
    if ( v14 >= 4 )
      v13 = (GASValue *)(*(_DWORD *)(*((_DWORD *)v12.value + 6) + 4 * ((v14 - 4) >> 5)) + 16 * ((v14 - 4) & 0x1F));
    v32 = GASValue::ToNumber(this: v13, a2: (struct GASEnvironment *)v12.value);
    v15.value = this->value;
    v16 = nullptr;
    v27 = v32 * 20.0;
    v17 = 32 * (*((_DWORD *)v15.value + 7) - 1) + ((*((_DWORD *)v15.value + 2) - *((_DWORD *)v15.value + 3)) >> 4);
    if ( v17 >= 3 )
      v16 = (GASValue *)(*(_DWORD *)(*((_DWORD *)v15.value + 6) + 4 * ((v17 - 3) >> 5)) + 16 * ((v17 - 3) & 0x1F));
    v21 = a2;
    v32 = GASValue::ToNumber(this: v16, a2: (struct GASEnvironment *)v15.value);
    v18.value = this->value;
    v19 = 4;
    v28 = v32 * 20.0;
    do
    {
      GASValue::~GASValue(this: *((GASValue **)v18.value + 2));
      *((_DWORD *)v18.value + 2) -= 16;
      if ( *((_DWORD *)v18.value + 2) < *((_DWORD *)v18.value + 3) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v18.value + 2, a2: v21);
      --v19;
    }
    while ( v19 != 0 );
  }
  if ( TargetByValue != nullptr )
  {
    GFxMovieRoot::DragState::InitCenterDelta(
      this: (GFxMovieRoot::DragState *)&TargetByValue,
      a2: (const CMaterialDict::MissingMaterial_t *)this,
      a3: v31[0]);
    v20 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->value + 29) + 84))(a1: *((_DWORD *)this->value + 29));
    if ( v20 != 0 )
      GFxMovieRoot::SetDragState(this: v20, st: (ScaleformRenderer::VertexShaderType)&TargetByValue);
  }
  GASPagedStack<GASValue,32>::Pop3(this: (__vc_attributes::iid_isAttribute *)this->value + 2, a2: v22);
}

//------------------------------------------------------------------------------
// Address: 0x1009A560
// Name: public: void GASExecutionContext::CastObjectOpCode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASExecutionContext::CastObjectOpCode(GASExecutionContext *this@<ecx>, const char *a2@<ebx>)
{
  int v3; // eax
  unsigned int v4; // ecx
  _BYTE *v5; // ecx
  _DWORD *v6; // eax
  struct GASObject *v7; // eax
  struct GASObjectInterface *v8; // esi
  _SERVICE_STATUS *v9; // esi
  GASValue *v10; // ecx
  int i; // ebx
  __vc_attributes::iid_isAttribute *v12; // esi
  GASValue *limited_expression; // esi
  const char *v14; // [esp-4h] [ebp-3Ch]
  const char *v15; // [esp+0h] [ebp-38h]
  GASValue v16[4]; // [esp+8h] [ebp-30h] BYREF
  GASValue v17[4]; // [esp+18h] [ebp-20h] BYREF
  int v18; // [esp+28h] [ebp-10h] BYREF
  int v19; // [esp+2Ch] [ebp-Ch]
  char v20; // [esp+30h] [ebp-8h]
  struct GASObjectInterface *v21; // [esp+34h] [ebp-4h]

  v3 = *(_DWORD *)this;
  v4 = *(_DWORD *)(*(_DWORD *)this + 8);
  if ( v4 <= *(_DWORD *)(v3 + 12) )
    v5 = *(_BYTE **)(v3 + 20);
  else
    v5 = (_BYTE *)(v4 - 16);
  LOBYTE(v16[0]) = 1;
  v14 = a2;
  if ( *v5 == 8 || *v5 == 11 )
  {
    GASValue::ToFunction(a1: &v18, a2: v3);
    if ( v18 != 0 )
    {
      v21 = (struct GASObjectInterface *)GASValue::ToObjectInterface(result: *(_SERVICE_STATUS **)this);
      if ( v21 != nullptr )
      {
        v6 = (_DWORD *)(*(_DWORD *)this + 120);
        LOBYTE(v17[0]) = 0;
        if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD *, int, GASValue *))(*(_DWORD *)(v18 + 16) + 44))(
               a1: v18 + 16,
               a2: v6,
               a3: *v6 + 316,
               a4: v17) != 0 )
        {
          v7 = GASValue::ToObject(this: v17, a2: *(const struct GASEnvironment **)this);
          v8 = v21;
          if ( (*(unsigned __int8 (__thiscall **)(struct GASObjectInterface *, _DWORD, struct GASObject *, int))(*(_DWORD *)v21 + 72))(
                 a1: v21,
                 a2: *(_DWORD *)this,
                 a3: v7,
                 a4: 1) != 0 )
            GASValue::SetAsObjectInterface(this: v16, a2: v8);
        }
        else if ( (*((_BYTE *)this + 54) & 1) != 0 )
        {
          GFxActionLogger::LogScriptError(
            result: (__vc_attributes::uuidAttribute *)this + 9,
            a2: "Error: The constructor function in 'cast' should have 'prototype'.\n");
        }
        GASValue::~GASValue(this: v17);
      }
    }
    if ( (v20 & 2) == 0 && v18 != 0 )
      GRefCountBaseGC<323>::Release(a1: v18, a2: (int)this);
    v18 = 0;
    if ( (v20 & 1) == 0 && v19 != 0 )
      GRefCountBaseGC<323>::Release(a1: v19, a2: (int)this);
  }
  else if ( (*((_BYTE *)this + 54) & 1) != 0 )
  {
    GFxActionLogger::LogScriptError(
      result: (__vc_attributes::uuidAttribute *)this + 9,
      a2: "Error: The parameter of 'cast' should be a function.\n");
  }
  v9 = *(_SERVICE_STATUS **)this;
  v10 = *(GASValue **)(*(_DWORD *)this + 8);
  if ( (unsigned int)(v10 - 8) >= *(_DWORD *)(*(_DWORD *)this + 12) )
  {
    GASValue::~GASValue(this: v10);
    v9->dwControlsAccepted -= 16;
    GASValue::~GASValue(this: (GASValue *)v9->dwControlsAccepted);
    v9->dwControlsAccepted -= 16;
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      GASValue::~GASValue(this: (GASValue *)v9->dwControlsAccepted);
      v9->dwControlsAccepted -= 16;
      if ( v9->dwControlsAccepted < v9->dwWin32ExitCode )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)&v9->dwControlsAccepted, a2: v14);
    }
  }
  v12 = *(__vc_attributes::iid_isAttribute **)this;
  v12[2].limited_expression += 16;
  if ( v12[2].limited_expression >= v12[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: v12 + 2, a2: v15);
  limited_expression = (GASValue *)v12[2].limited_expression;
  if ( limited_expression != nullptr )
    GASValue::GASValue(this: limited_expression, a2: (const struct GASValue *)v16);
  GASValue::~GASValue(this: v16);
}

//------------------------------------------------------------------------------
// Address: 0x1009A6F0
// Name: public: void GASExecutionContext::ImplementsOpCode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::ImplementsOpCode(GASExecutionContext *this)
{
  unsigned int v2; // ecx
  GASValue *v3; // ecx
  int v4; // eax
  struct GASEnvironment *v5; // esi
  GASValue *v6; // ecx
  int i; // ebx
  int v8; // ecx
  _DWORD *v9; // eax
  struct GASObject *v10; // eax
  int v11; // ebx
  CFunctor *elem; // edx
  unsigned int v13; // esi
  unsigned int v14; // eax
  _BYTE *v15; // ecx
  int v16; // ecx
  int v17; // ebx
  struct GASEnvironment *j; // esi
  int v19; // [esp-Ch] [ebp-58h]
  const char *v20; // [esp+0h] [ebp-4Ch]
  GASValue v21[4]; // [esp+Ch] [ebp-40h] BYREF
  GASValue v22[4]; // [esp+1Ch] [ebp-30h] BYREF
  int v23; // [esp+2Ch] [ebp-20h] BYREF
  int v24; // [esp+30h] [ebp-1Ch]
  char v25; // [esp+34h] [ebp-18h]
  int v26; // [esp+38h] [ebp-14h] BYREF
  int v27; // [esp+3Ch] [ebp-10h]
  char v28; // [esp+40h] [ebp-Ch]
  struct GASObject *v29; // [esp+44h] [ebp-8h]
  int v30; // [esp+48h] [ebp-4h]

  GASValue::GASValue(this: v21, a2: *(const struct GASValue **)(*(_DWORD *)this + 8));
  v2 = *(_DWORD *)(*(_DWORD *)this + 8);
  if ( v2 <= *(_DWORD *)(*(_DWORD *)this + 12) )
    v3 = *(GASValue **)(*(_DWORD *)this + 20);
  else
    v3 = (GASValue *)(v2 - 16);
  v4 = GASValue::ToInt32(this: v3, a2: *(struct GASEnvironment **)this);
  v5 = *(struct GASEnvironment **)this;
  v6 = *(GASValue **)(*(_DWORD *)this + 8);
  v30 = v4;
  if ( (unsigned int)(v6 - 8) >= *((_DWORD *)v5 + 3) )
  {
    GASValue::~GASValue(this: v6);
    *((_DWORD *)v5 + 2) -= 16;
    GASValue::~GASValue(this: *((GASValue **)v5 + 2));
    *((_DWORD *)v5 + 2) -= 16;
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      GASValue::~GASValue(this: *((GASValue **)v5 + 2));
      *((_DWORD *)v5 + 2) -= 16;
      if ( *((_DWORD *)v5 + 2) < *((_DWORD *)v5 + 3) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v5 + 2, a2: v20);
    }
  }
  if ( LOBYTE(v21[0]) == 8 || LOBYTE(v21[0]) == 11 )
  {
    GASValue::ToFunction(a1: &v23, a2: *(_DWORD *)this);
    v8 = v23;
    if ( v23 != 0 )
    {
      v9 = (_DWORD *)(*(_DWORD *)this + 120);
      LOBYTE(v22[0]) = 0;
      if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD *, int, GASValue *))(*(_DWORD *)(v23 + 16) + 44))(
             a1: v23 + 16,
             a2: v9,
             a3: *v9 + 316,
             a4: v22) != 0 )
      {
        v10 = GASValue::ToObject(this: v22, a2: *(const struct GASEnvironment **)this);
        if ( v10 != nullptr )
        {
          v11 = v30;
          elem = v10[2].pNode[8].elem;
          v19 = *(_DWORD *)this + 120;
          v29 = v10 + 2;
          ((void (__stdcall *)(int, int, _DWORD))elem)(a1: v19, a2: v30, a3: 0);
          v13 = 0;
          if ( v11 > 0 )
          {
            do
            {
              v14 = 32 * (*(_DWORD *)(*(_DWORD *)this + 28) - 1)
                  + ((*(_DWORD *)(*(_DWORD *)this + 8) - *(_DWORD *)(*(_DWORD *)this + 12)) >> 4);
              v15 = nullptr;
              if ( v13 <= v14 )
                v15 = (_BYTE *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)this + 24) + 4 * ((v14 - v13) >> 5))
                              + 16 * ((v14 - v13) & 0x1F));
              if ( *v15 == 8 || *v15 == 11 )
              {
                GASValue::ToFunction(a1: &v26, a2: *(_DWORD *)this);
                v16 = v26;
                if ( v26 != 0 )
                {
                  ((void (__thiscall *)(struct GASObject *, int, unsigned int, int))v29->pNode[8].elem)(
                    a1: v29,
                    a2: *(_DWORD *)this + 120,
                    a3: v13,
                    a4: v26);
                  v16 = v26;
                }
                if ( (v28 & 2) == 0 && v16 != 0 )
                  GRefCountBaseGC<323>::Release(a1: v16, a2: (int)this);
                v26 = 0;
                if ( (v28 & 1) == 0 && v27 != 0 )
                  GRefCountBaseGC<323>::Release(a1: v27, a2: (int)this);
                v27 = 0;
              }
              ++v13;
            }
            while ( (int)v13 < v30 );
          }
        }
      }
      else if ( (*((_BYTE *)this + 54) & 1) != 0 )
      {
        GFxActionLogger::LogScriptError(
          result: (__vc_attributes::uuidAttribute *)this + 9,
          a2: "Error: The constructor function in 'implements' should have 'prototype'.\n");
      }
      GASValue::~GASValue(this: v22);
      v8 = v23;
    }
    if ( (v25 & 2) == 0 && v8 != 0 )
      GRefCountBaseGC<323>::Release(a1: v8, a2: (int)this);
    v23 = 0;
    if ( (v25 & 1) == 0 && v24 != 0 )
      GRefCountBaseGC<323>::Release(a1: v24, a2: (int)this);
  }
  else if ( (*((_BYTE *)this + 54) & 1) != 0 )
  {
    GFxActionLogger::LogScriptError(
      result: (__vc_attributes::uuidAttribute *)this + 9,
      a2: "Error: The parameter of 'implements' should be a function.\n");
  }
  v17 = v30;
  for ( j = *(struct GASEnvironment **)this; v17 != 0; --v17 )
  {
    GASValue::~GASValue(this: *((GASValue **)j + 2));
    *((_DWORD *)j + 2) -= 16;
    if ( *((_DWORD *)j + 2) < *((_DWORD *)j + 3) )
      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)j + 2, a2: v20);
  }
  GASValue::~GASValue(this: v21);
}

//------------------------------------------------------------------------------
// Address: 0x1009A930
// Name: public: void GASExecutionContext::ExtendsOpCode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASExecutionContext::ExtendsOpCode(_TRANSACTION_NOTIFICATION **this@<ecx>, int i@<edi>)
{
  unsigned int LowPart; // ecx
  const struct GASValue *v4; // eax
  _TRANSACTION_NOTIFICATION *v5; // eax
  struct GASObject *v6; // eax
  int v7; // ebx
  int v8; // ecx
  int (__thiscall *v9)(int, int, int *); // edx
  GPtr<GImage> *v10; // eax
  const struct GASEnvironment *v11; // esi
  GASValue *v12; // ecx
  const char *v13; // [esp+0h] [ebp-58h]
  GASValue v14[4]; // [esp+Ch] [ebp-4Ch] BYREF
  GASValue v15[4]; // [esp+1Ch] [ebp-3Ch] BYREF
  GASValue v16[4]; // [esp+2Ch] [ebp-2Ch] BYREF
  int v17; // [esp+3Ch] [ebp-1Ch] BYREF
  int v18; // [esp+40h] [ebp-18h]
  char v19; // [esp+44h] [ebp-14h]
  int v20; // [esp+48h] [ebp-10h] BYREF
  int v21; // [esp+4Ch] [ebp-Ch]
  char v22; // [esp+50h] [ebp-8h]
  int v23; // [esp+54h] [ebp-4h] BYREF

  GASValue::GASValue(this: v14, a2: (const struct GASValue *)(*this)->TmVirtualClock.LowPart);
  LowPart = (*this)->TmVirtualClock.LowPart;
  if ( LowPart <= (*this)->TmVirtualClock.HighPart )
    v4 = (const struct GASValue *)*(&(*this)->ArgumentLength + 1);
  else
    v4 = (const struct GASValue *)(LowPart - 16);
  GASValue::GASValue(this: v15, a2: v4);
  GASValue::ToFunction(a1: &v17, a2: *this);
  GASValue::ToFunction(a1: &v20, a2: *this);
  if ( v17 != 0 && v20 != 0 )
  {
    v5 = *this + 5;
    LOBYTE(v16[0]) = 0;
    i = *(_DWORD *)(v17 + 16);
    if ( (*(unsigned __int8 (__thiscall **)(int, _TRANSACTION_NOTIFICATION *, int, GASValue *))(i + 44))(
           a1: v17 + 16,
           a2: v5,
           a3: (int)v5->TransactionKey + 316,
           a4: v16) != 0
      && LOBYTE(v16[0]) == 6 )
    {
      v6 = GASValue::ToObject(this: v16, a2: (const struct GASEnvironment *)*this);
      v7 = (int)v6;
      if ( v6 != nullptr )
        v6[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v6[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v8 = *((_DWORD *)(*this)[5].TransactionKey + 164);
      v9 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v8 + 40);
      v23 = 323;
      v10 = (GPtr<GImage> *)v9(a1: v8, a2: 84, a3: &v23);
      if ( v10 != nullptr )
        i = (int)GASObjectProto::GASObjectProto(this: v10, psc: (unsigned int)&(*this)[5]);
      else
        i = 0;
      GASFunctionObject::SetPrototype(result: *this + 5);
      GASObjectInterface::Set__constructor__(
        this: (GASObjectInterface *)(i + 16),
        psc: (struct GASStringContext *)&(*this)[5],
        psc_4: (const struct GASFunctionRef *)&v17);
      if ( i != 0 )
        GRefCountBaseGC<323>::Release(a1: i, a2: i);
      if ( v7 != 0 )
      {
        GRefCountBaseGC<323>::Release(a1: v7, a2: i);
        GASValue::~GASValue(this: v16);
        goto LABEL_24;
      }
    }
    else if ( (*((_BYTE *)this + 54) & 1) != 0 )
    {
      GFxActionLogger::LogScriptError(
        result: (__vc_attributes::uuidAttribute *)this + 9,
        a2: "Error: can't extend by the class w/o prototype.\n");
    }
    GASValue::~GASValue(this: v16);
  }
  else if ( (*((_BYTE *)this + 54) & 1) != 0 )
  {
    if ( v17 != 0 )
      GFxActionLogger::LogScriptError(
        result: (__vc_attributes::uuidAttribute *)this + 9,
        a2: "Error: can't extend the unknown class.\n");
    else
      GFxActionLogger::LogScriptError(
        result: (__vc_attributes::uuidAttribute *)this + 9,
        a2: "Error: can't extend with unknown super class.\n");
  }
LABEL_24:
  v11 = (const struct GASEnvironment *)*this;
  v12 = *((GASValue **)v11 + 2);
  if ( (unsigned int)(v12 - 8) >= *((_DWORD *)v11 + 3) )
  {
    GASValue::~GASValue(this: v12);
    *((_DWORD *)v11 + 2) -= 16;
    GASValue::~GASValue(this: *((GASValue **)v11 + 2));
    *((_DWORD *)v11 + 2) -= 16;
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      GASValue::~GASValue(this: *((GASValue **)v11 + 2));
      *((_DWORD *)v11 + 2) -= 16;
      if ( *((_DWORD *)v11 + 2) < *((_DWORD *)v11 + 3) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v11 + 2, a2: v13);
    }
  }
  if ( (v22 & 2) == 0 && v20 != 0 )
    GRefCountBaseGC<323>::Release(a1: v20, a2: i);
  v20 = 0;
  if ( (v22 & 1) == 0 && v21 != 0 )
    GRefCountBaseGC<323>::Release(a1: v21, a2: i);
  v21 = 0;
  if ( (v19 & 2) == 0 && v17 != 0 )
    GRefCountBaseGC<323>::Release(a1: v17, a2: i);
  v17 = 0;
  if ( (v19 & 1) == 0 && v18 != 0 )
    GRefCountBaseGC<323>::Release(a1: v18, a2: i);
  v18 = 0;
  GASValue::~GASValue(this: v15);
  GASValue::~GASValue(this: v14);
}

//------------------------------------------------------------------------------
// Address: 0x1009AB70
// Name: public: void GASExecutionContext::InstanceOfOpCode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASExecutionContext::InstanceOfOpCode(GASExecutionContext *this@<ecx>, const char *a2@<ebx>)
{
  int v3; // eax
  char v4; // dl
  _SERVICE_STATUS *v5; // esi
  _DWORD *v6; // eax
  struct GASObject *v7; // eax
  _SERVICE_STATUS *v8; // esi
  GASValue *v9; // ecx
  int i; // ebx
  __vc_attributes::iid_isAttribute *v11; // esi
  char *limited_expression; // esi
  char v13; // al
  const char *v14; // [esp-4h] [ebp-2Ch]
  const char *v15; // [esp+0h] [ebp-28h]
  GASValue v16[4]; // [esp+8h] [ebp-20h] BYREF
  int v17; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch]
  char v19; // [esp+20h] [ebp-8h]
  char v20; // [esp+27h] [ebp-1h]

  v3 = *(_DWORD *)this;
  v4 = **(_BYTE **)(*(_DWORD *)this + 8);
  v14 = a2;
  v20 = 0;
  if ( v4 == 8 || v4 == 11 )
  {
    GASValue::ToFunction(a1: &v17, a2: v3);
    if ( v17 != 0 )
    {
      v5 = GASValue::ToObjectInterface(result: *(_SERVICE_STATUS **)this);
      if ( v5 != nullptr )
      {
        v6 = (_DWORD *)(*(_DWORD *)this + 120);
        LOBYTE(v16[0]) = 0;
        if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD *, int, GASValue *))(*(_DWORD *)(v17 + 16) + 44))(
               a1: v17 + 16,
               a2: v6,
               a3: *v6 + 316,
               a4: v16) != 0 )
        {
          v7 = GASValue::ToObject(this: v16, a2: *(const struct GASEnvironment **)this);
          v20 = (*(int (__thiscall **)(_SERVICE_STATUS *, _DWORD, struct GASObject *, int))(v5->dwServiceType + 72))(
                  a1: v5,
                  a2: *(_DWORD *)this,
                  a3: v7,
                  a4: 1);
        }
        else if ( (*((_BYTE *)this + 54) & 1) != 0 )
        {
          GFxActionLogger::LogScriptError(
            result: (__vc_attributes::uuidAttribute *)this + 9,
            a2: "Error: The constructor function in InstanceOf should have 'prototype'.\n");
        }
        GASValue::~GASValue(this: v16);
      }
    }
    if ( (v19 & 2) == 0 && v17 != 0 )
      GRefCountBaseGC<323>::Release(a1: v17, a2: (int)this);
    v17 = 0;
    if ( (v19 & 1) == 0 && v18 != 0 )
      GRefCountBaseGC<323>::Release(a1: v18, a2: (int)this);
  }
  else if ( (*((_BYTE *)this + 54) & 1) != 0 )
  {
    GFxActionLogger::LogScriptError(
      result: (__vc_attributes::uuidAttribute *)this + 9,
      a2: "Error: The parameter of InstanceOf should be a function.\n");
  }
  v8 = *(_SERVICE_STATUS **)this;
  v9 = *(GASValue **)(*(_DWORD *)this + 8);
  if ( (unsigned int)(v9 - 8) >= *(_DWORD *)(*(_DWORD *)this + 12) )
  {
    GASValue::~GASValue(this: v9);
    v8->dwControlsAccepted -= 16;
    GASValue::~GASValue(this: (GASValue *)v8->dwControlsAccepted);
    v8->dwControlsAccepted -= 16;
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      GASValue::~GASValue(this: (GASValue *)v8->dwControlsAccepted);
      v8->dwControlsAccepted -= 16;
      if ( v8->dwControlsAccepted < v8->dwWin32ExitCode )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)&v8->dwControlsAccepted, a2: v14);
    }
  }
  v11 = *(__vc_attributes::iid_isAttribute **)this;
  v11[2].limited_expression += 16;
  if ( v11[2].limited_expression >= v11[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: v11 + 2, a2: v15);
  limited_expression = (char *)v11[2].limited_expression;
  if ( limited_expression != nullptr )
  {
    v13 = v20;
    *limited_expression = 2;
    limited_expression[4] = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009ACF0
// Name: private: virtual void GASLocalFrame::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASLocalFrame::Finalize_GC(_QUOTA_LIMITS *result, EMatchMakingServerResponse a2)
{
  ISteamMatchmakingServerListResponse *v2; // ecx

  GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>(
    this: v2 + 4,
    a2: result,
    a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1009AD00
// Name: public: class GASValue __near * GASStringHashBase<class GASValue,class GHashUncachedLH_GC<class GASString,class GASValue,struct GASStringHashFunctor,323>>::GetCaseCheck(class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::GetCaseCheck(
        int *this,
        _IMAGE_SYMBOL_EX *key,
        _IMAGE_SYMBOL_EX *caseSensitive)
{
  int v4; // edi
  int Index; // eax
  int v6; // eax
  bool v7; // zf
  int v8; // eax

  if ( (_BYTE)caseSensitive != 0 )
  {
    v4 = *this;
    if ( *this == 0 )
      return 0;
    Index = GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
              a1: key,
              a2: *(_DWORD *)(v4 + 4) & *(_DWORD *)(key->N.Name.Short + 12));
    if ( Index < 0 )
      return 0;
    v6 = v4 + 24 * Index + 12;
  }
  else
  {
    v7 = *(_DWORD *)(key->N.Name.Short + 4) == 0;
    caseSensitive = key;
    if ( v7 )
      GASStringNode::ResolveLowercase_Impl();
    if ( *this == 0 )
      return 0;
    v8 = GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>(
           a1: &caseSensitive,
           a2: *(_DWORD *)(*this + 4) & *(_DWORD *)(key->N.Name.Short + 12));
    if ( v8 < 0 )
      return 0;
    v6 = *this + 24 * v8 + 12;
  }
  if ( v6 != 0 )
    return v6 + 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009AD90
// Name: public: class GASFunctionRef __near * GASStringHashBase<class GASFunctionRef,class GHashUncachedLH<class GASString,class GASFunctionRef,struct GASStringHashFunctor,323>>::GetCaseCheck(class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringHashBase<GASFunctionRef,GHashUncachedLH<GASString,GASFunctionRef,GASStringHashFunctor,323>>::GetCaseCheck(
        GFxMeshCacheManager *this,
        _IMAGE_SYMBOL_EX *key,
        char caseSensitive)
{
  if ( caseSensitive != 0 )
  {
    if ( this->__vftable != nullptr )
      GHashSetBase<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
        a1: key,
        a2: (int)this->__vftable[1].dtr_GRefCountImplCore & *(_DWORD *)(key->N.Name.Short + 12));
  }
  else
  {
    if ( *(_DWORD *)(key->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl();
    if ( this->__vftable != nullptr )
      GHashSetBase<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AE90
// Name: public: void GHashsetNodeEntry<struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASFunctionRef,struct GASStringHashFunctor>::NodeHashF>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>::Clear@<al>(
        int a1@<ecx>,
        int a2@<edi>)
{
  int v3; // ecx
  char Sid; // al
  bool v5; // zf
  int v6; // ecx
  int v7; // ecx

  if ( (*(_BYTE *)(a1 + 16) & 2) == 0 )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( v3 != 0 )
      Sid = GRefCountBaseGC<323>::Release(a1: v3, a2);
  }
  v5 = (*(_BYTE *)(a1 + 16) & 1) == 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( v5 )
  {
    v6 = *(_DWORD *)(a1 + 12);
    if ( v6 != 0 )
      Sid = GRefCountBaseGC<323>::Release(a1: v6, a2);
  }
  *(_DWORD *)(a1 + 12) = 0;
  v7 = *(_DWORD *)(a1 + 4);
  v5 = (*(_DWORD *)(v7 + 8))-- == 1;
  if ( v5 )
    Sid = (char)GASStringNode::ReleaseNode().Sid;
  *(_DWORD *)a1 = -2;
  return Sid;
}

//------------------------------------------------------------------------------
// Address: 0x1009B270
// Name: public: struct GASGlobalContext::ClassRegEntry __near * GASGlobalContext::GetBuiltinClassRegistrar(class GASString)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::GetBuiltinClassRegistrar(vc_attributes::PreRangeAttribute *this, int a2)
{
  int v2; // esi
  int Index; // eax
  int v4; // eax
  bool v5; // zf

  v2 = *((_DWORD *)this + 162);
  if ( v2 != 0
    && (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) >= 0
    && (v4 = v2 + 16 * Index + 12) != 0
    && v4 != -4 )
  {
    v5 = (*(_DWORD *)(a2 + 8))-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode();
  }
  else
  {
    v5 = (*(_DWORD *)(a2 + 8))-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B2E0
// Name: public: bool GASGlobalContext::FindRegisteredClass(class GASStringContext __near *,class GASString const __near &,class GASFunctionRef __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASGlobalContext::FindRegisteredClass(
        GFxMeshCacheManager *this,
        _IMAGE_SYMBOL_EX *className,
        _IMAGE_SYMBOL_EX *key,
        struct GASFunctionRef *a4)
{
  const struct GASFunctionRefBase *v4; // eax

  GASStringHashBase<GASFunctionRef,GHashUncachedLH<GASString,GASFunctionRef,GASStringHashFunctor,323>>::GetCaseCheck(
    this: this + 23,
    key,
    caseSensitive: className->N.ShortName[4] > 6u);
  if ( v4 == nullptr )
    return 0;
  if ( a4 != nullptr )
    GASFunctionRefBase::Assign(this: a4, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009B320
// Name: public: class GASValue const __near * GASEnvironment::FindLocal(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
const struct GASValue *__thiscall GASEnvironment::FindLocal(GASEnvironment *this, _IMAGE_SYMBOL_EX *key)
{
  int v3; // eax
  int v4; // eax
  _IMAGE_SYMBOL_EX *v5; // edi
  int v6; // esi
  unsigned __int8 v7; // al
  int v8; // edx
  int v9; // esi
  bool v10; // zf
  int v11; // esi
  bool v12; // zf
  int v13; // eax
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v3 = *((_DWORD *)this + 51);
  if ( v3 == 0 )
    return nullptr;
  v4 = *(_DWORD *)(*((_DWORD *)this + 50) + 4 * v3 - 4);
  if ( v4 != 0 )
    *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  v16 = v4;
  if ( v4 == 0 )
    return nullptr;
  v5 = key;
  while ( 1 )
  {
    LOBYTE(key) = *((_BYTE *)this + 124) > 6u;
    v6 = GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::GetCaseCheck(
           this: (int *)(v16 + 16),
           key: v5,
           caseSensitive: key);
    if ( v6 != 0 )
      break;
    v7 = *((_BYTE *)this + 124);
    v8 = v7;
    v15 = v7;
    if ( v7 >= 5u )
    {
      v9 = *((_DWORD *)this + 30);
      if ( v7 <= 6u )
      {
        if ( *(_DWORD *)(v5->N.Name.Short + 4) == 0 )
        {
          GASStringNode::ResolveLowercase_Impl();
          v8 = v15;
        }
        v10 = *(_DWORD *)(*(_DWORD *)(v9 + 280) + 4) == *(_DWORD *)(v5->N.Name.Short + 4);
      }
      else
      {
        v10 = *(_DWORD *)(v9 + 280) == v5->N.Name.Short;
      }
      if ( v10 )
        goto LABEL_28;
    }
    if ( v8 >= 6 )
    {
      v11 = *((_DWORD *)this + 30);
      if ( *((_BYTE *)this + 124) <= 6u )
      {
        if ( *(_DWORD *)(v5->N.Name.Short + 4) == 0 )
          GASStringNode::ResolveLowercase_Impl();
        v12 = *(_DWORD *)(*(_DWORD *)(v11 + 256) + 4) == *(_DWORD *)(v5->N.Name.Short + 4);
      }
      else
      {
        v12 = *(_DWORD *)(v11 + 256) == v5->N.Name.Short;
      }
      if ( v12 )
      {
LABEL_28:
        if ( v16 != 0 )
          GRefCountBaseGC<323>::Release(a1: v16, a2: (int)v5);
        return nullptr;
      }
    }
    v13 = *(_DWORD *)(v16 + 20);
    if ( v13 != 0 )
      *(_DWORD *)(v13 + 8) = (*(_DWORD *)(v13 + 8) + 1) & 0x8FFFFFFF;
    GRefCountBaseGC<323>::Release(a1: v16, a2: (int)v5);
    v16 = *(_DWORD *)(v16 + 20);
    if ( v16 == 0 )
      return nullptr;
  }
  if ( v16 != 0 )
    GRefCountBaseGC<323>::Release(a1: v16, a2: (int)v5);
  return (const struct GASValue *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1009B8D0
// Name: public: class GASFunctionObject __near * GASGlobalContext::ResolveFunctionName(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionObject *__thiscall GASGlobalContext::ResolveFunctionName(
        vc_attributes::PreRangeAttribute *this,
        const struct GASString *a2)
{
  int v3; // esi
  int v4; // edi
  int Index; // eax
  int v6; // eax
  int v7; // esi
  bool v8; // zf
  int v9; // eax
  int *v10; // esi
  int *v11; // eax
  int v12; // ecx
  tagIMECHARPOSITION *v13; // ecx
  int v14; // ecx
  int v15; // edi
  int v16; // eax
  int v18; // [esp-4h] [ebp-2Ch]
  int v19; // [esp+Ch] [ebp-1Ch] BYREF
  int v20; // [esp+10h] [ebp-18h]
  char v21; // [esp+14h] [ebp-14h]
  int v22; // [esp+18h] [ebp-10h]
  int v23; // [esp+1Ch] [ebp-Ch]
  char v24; // [esp+20h] [ebp-8h]
  int v25; // [esp+24h] [ebp-4h]

  v25 = *(_DWORD *)a2;
  ++*(_DWORD *)(v25 + 8);
  v3 = *((_DWORD *)this + 162);
  v4 = v25;
  if ( v3 != 0
    && (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) >= 0
    && (v6 = v3 + 16 * Index + 12) != 0
    && (v7 = v6 + 4, v6 != -4) )
  {
    v8 = (*(_DWORD *)(v25 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v9 = v7;
  }
  else
  {
    v8 = (*(_DWORD *)(v25 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v9 = 0;
  }
  if ( v9 == 0 )
    return nullptr;
  v10 = (int *)(v9 + 4);
  if ( *(_DWORD *)(v9 + 4) == 0 )
  {
    v11 = (int *)(*(int (__cdecl **)(int *, vc_attributes::PreRangeAttribute *))v9)(a1: &v19, a2: this);
    v24 = 0;
    v12 = *v11;
    v22 = v12;
    if ( v12 != 0 )
    {
      ++*(_DWORD *)(v12 + 8);
      *(_DWORD *)(v12 + 8) &= 0x8FFFFFFF;
    }
    v23 = 0;
    v13 = (tagIMECHARPOSITION *)v11[1];
    if ( v13 != nullptr )
      GASFunctionRefBase::SetLocalFrame(result: v13);
    if ( (v21 & 2) == 0 && v19 != 0 )
      GRefCountBaseGC<323>::Release(a1: v19, a2: v4);
    v19 = 0;
    if ( (v21 & 1) == 0 && v20 != 0 )
      GRefCountBaseGC<323>::Release(a1: v20, a2: v4);
    v18 = *(_DWORD *)a2;
    ++*(_DWORD *)(v18 + 8);
    GASGlobalContext::GetBuiltinClassRegistrar(this, a2: v18);
    v14 = v22;
    v15 = v22;
    v10 = (int *)(v16 + 4);
    if ( v22 != 0 )
    {
      ++*(_DWORD *)(v22 + 8);
      *(_DWORD *)(v14 + 8) &= 0x8FFFFFFF;
    }
    if ( *v10 != 0 )
      GRefCountBaseGC<323>::Release(a1: *v10, a2: v15);
    *v10 = v15;
    if ( (v24 & 2) == 0 && v22 != 0 )
      GRefCountBaseGC<323>::Release(a1: v22, a2: v15);
    v22 = 0;
    if ( (v24 & 1) == 0 && v23 != 0 )
      GRefCountBaseGC<323>::Release(a1: v23, a2: v15);
    v23 = 0;
  }
  return (struct GASFunctionObject *)*v10;
}

//------------------------------------------------------------------------------
// Address: 0x1009BA40
// Name: public: class GASObject __near * GASGlobalContext::GetPrototype(enum GASBuiltinType)
// Source: json
//------------------------------------------------------------------------------
vc_attributes::InvalidCheckAttribute *__thiscall GASGlobalContext::GetPrototype(
        vc_attributes::PreRangeAttribute *this,
        vc_attributes::InvalidCheckAttribute *result)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v3 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
         a1: (char *)this + 640,
         a2: &result);
  if ( v3 != 0 )
  {
    v4 = v3 + 4;
    if ( v4 != 0 )
      return *(vc_attributes::InvalidCheckAttribute **)v4;
  }
  GASGlobalContext::ResolveFunctionName(this, a2: (const struct GASString *)(&this->MaxVal + (_DWORD)result));
  v5 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
         a1: (char *)this + 640,
         a2: &result);
  if ( v5 != 0 && (v4 = v5 + 4) != 0 )
    return *(vc_attributes::InvalidCheckAttribute **)v4;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009BAA0
// Name: public: class GASObject __near * GASGlobalContext::GetActualPrototype(class GASEnvironment __near *,enum GASBuiltinType)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASGlobalContext::GetActualPrototype(
        vc_attributes::PreRangeAttribute *this,
        struct GASEnvironment *a2,
        int a3)
{
  int v3; // ebx
  int v5; // eax
  int *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  struct GASObject *v11; // eax
  int v12; // ebx
  struct GASObject *v13; // eax
  int v14; // esi
  int v15; // esi
  GASValue v[4]; // [esp+Ch] [ebp-14h] BYREF
  int v18; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v5 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
         a1: (char *)this + 640,
         a2: &a3);
  if ( v5 != 0 && (v6 = (int *)(v5 + 4)) != nullptr
    || (GASGlobalContext::ResolveFunctionName(this, a2: (const struct GASString *)(&this->MaxVal + v3)),
        (v7 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
                a1: (char *)this + 640,
                a2: &a3)) != 0)
    && (v6 = (int *)(v7 + 4)) != nullptr )
  {
    v8 = *v6;
    a3 = v8;
    if ( v8 != 0 )
      *(_DWORD *)(v8 + 8) = (*(_DWORD *)(v8 + 8) + 1) & 0x8FFFFFFF;
  }
  else
  {
    a3 = 0;
    v8 = 0;
  }
  v9 = *((_DWORD *)this + 170);
  v18 = v8;
  LOBYTE(v[0]) = 0;
  v10 = (int)a2 + 120;
  if ( (*(unsigned __int8 (__thiscall **)(int, int, const char **, GASValue *))(*(_DWORD *)(v9 + 16) + 44))(
         a1: v9 + 16,
         a2: (int)a2 + 120,
         a3: &this->MaxVal + v3,
         a4: v) != 0 )
  {
    v11 = GASValue::ToObject(this: v, a2);
    v12 = (int)v11;
    if ( v11 != nullptr )
    {
      v11[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v11[1].pNode->pNext + 1) & 0x8FFFFFFF);
      if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, int, int, GASValue *))v11[2].pNode[5].elem)(
             a1: &v11[2],
             a2: v10,
             a3: (int)this + 316,
             a4: v) != 0 )
      {
        v13 = GASValue::ToObject(this: v, a2);
        v14 = (int)v13;
        if ( v13 != nullptr )
          v13[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v13[1].pNode->pNext + 1) & 0x8FFFFFFF);
        if ( a3 != 0 )
          GRefCountBaseGC<323>::Release(a1: a3, a2: v10);
        v18 = v14;
      }
      GRefCountBaseGC<323>::Release(a1: v12, a2: v10);
    }
  }
  GASValue::~GASValue(this: v);
  v15 = v18;
  if ( v18 != 0 )
    GRefCountBaseGC<323>::Release(a1: v18, a2: v10);
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x1009BBE0
// Name: public: static void GASNameFunction::AddConstMembers(class GASObjectInterface __near *,class GASStringContext __near *,struct GASNameFunction const __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
struct GASObject **__thiscall GASNameFunction::AddConstMembers(
        void *pobj,
        int psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psca,
        struct GASObject **a4,
        char a5)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v5; // ebx
  vc_attributes::PreRangeAttribute *pNext; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *v7; // ecx
  int v8; // eax
  struct GASObject **result; // eax
  struct GASObject **v10; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *v11; // eax
  GASCFunctionObject *v12; // eax
  GASCFunctionObject *v13; // eax
  GASValue v15[4]; // [esp+Ch] [ebp-2Ch] BYREF
  GASCFunctionObject *v16; // [esp+1Ch] [ebp-1Ch] BYREF
  int v17; // [esp+20h] [ebp-18h]
  char v18; // [esp+24h] [ebp-14h]
  int v19; // [esp+28h] [ebp-10h] BYREF
  CTSQueue<CFunctor *,0,1>::Node_t *v20; // [esp+2Ch] [ebp-Ch]
  struct GASStringNode *ConstStringNode; // [esp+30h] [ebp-8h] BYREF
  struct GASObject *v22; // [esp+34h] [ebp-4h]

  v5 = psca;
  pNext = (vc_attributes::PreRangeAttribute *)psca->pNext;
  v7 = psca->pNext + 80;
  v20 = psca->pNext[82].pNext;
  psca = (CTSQueue<CFunctor *,0,1>::Node_t *)7;
  v8 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
         a1: v7,
         a2: &psca);
  if ( v8 != 0 && (result = (struct GASObject **)(v8 + 4)) != nullptr
    || (GASGlobalContext::ResolveFunctionName(this: pNext, a2: (const struct GASString *)&pNext[3]),
        (result = (struct GASObject **)GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
                                         a1: &pNext[53].MinVal,
                                         a2: &psca)) != nullptr)
    && (++result, result != nullptr) )
  {
    v22 = *result;
  }
  else
  {
    v22 = nullptr;
  }
  v10 = a4;
  if ( *a4 != nullptr )
  {
    while ( 1 )
    {
      v11 = v20->pNext[5].pNext;
      HIBYTE(psca) = a5;
      v19 = 323;
      v12 = (GASCFunctionObject *)((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))v11)(
                                    a1: v20,
                                    a2: 56,
                                    a3: &v19);
      if ( v12 != nullptr )
        v13 = GASCFunctionObject::GASCFunctionObject(
                this: v12,
                psc: v5,
                a3: v22,
                a4: (void (__cdecl *)(const struct GASFnCall *))v10[1]);
      else
        v13 = nullptr;
      v16 = v13;
      v18 = 0;
      v17 = 0;
      GASValue::GASValue(this: v15, a2: (const struct GASFunctionRef *)&v16);
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: (GASStringManager *)v5->pNext[79].elem,
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)*v10,
                          a3: strlen((const char *)*v10),
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      (*(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)psc + 40))(
        a1: psc,
        a2: v5,
        a3: &ConstStringNode,
        a4: v15,
        a5: (char *)&psca + 3);
      if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
        GASStringNode::ReleaseNode();
      GASValue::~GASValue(this: v15);
      if ( (v18 & 2) == 0 && v16 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v16, a2: 0);
      v16 = nullptr;
      if ( (v18 & 1) == 0 && v17 != 0 )
        GRefCountBaseGC<323>::Release(a1: v17, a2: 0);
      result = a4 + 2;
      v17 = 0;
      a4 = result;
      if ( *result == nullptr )
        break;
      v10 = a4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BD50
// Name: public: bool GASEnvironment::IsAvailable(class GASString const __near &,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASEnvironment::IsAvailable@<al>(
        int a1@<ecx>,
        _IMAGE_SYMBOL_EX *varname,
        CUtlInplaceBuffer pwithStack)
{
  bool v3; // zf
  __vc_attributes::event_receiverAttribute::type_e v5; // esi
  _IMAGE_SYMBOL_EX *v6; // edi
  int v7; // eax
  unsigned __int8 *m_pMemory; // edx
  int i; // esi
  int *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  __vc_attributes::event_receiverAttribute *v14; // esi
  unsigned int v15; // ecx
  char **v16; // eax
  unsigned int Short; // ecx
  int v18; // edx
  __vc_attributes::event_receiverAttribute *v19; // esi
  char *v20; // eax
  int v21; // eax
  int v22; // eax
  _SYSTEM_AUDIT_CALLBACK_ACE v23; // [esp+4h] [ebp-34h] BYREF
  int v24; // [esp+10h] [ebp-28h]
  int v25; // [esp+14h] [ebp-24h]
  int v26; // [esp+18h] [ebp-20h]
  GASValue val[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  __vc_attributes::event_receiverAttribute *v28; // [esp+2Ch] [ebp-Ch]
  __vc_attributes::event_receiverAttribute::type_e path; // [esp+30h] [ebp-8h] BYREF
  _SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode> pvar; // [esp+34h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(varname->N.Name.Short + 16) == 0;
  v28 = (__vc_attributes::event_receiverAttribute *)a1;
  if ( v3 )
    return 0;
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 120) + 8);
  v6 = (_IMAGE_SYMBOL_EX *)(a1 + 120);
  ++*(_DWORD *)(v5 + 8);
  pvar.NodeNumber = *(_DWORD *)(*(_DWORD *)(a1 + 120) + 8);
  ++*(_DWORD *)(pvar.NodeNumber + 8);
  v23.Mask = (unsigned int)val;
  v23.SidStart = (unsigned int)pwithStack.m_Memory.m_pMemory;
  path = v5;
  LOBYTE(val[0]) = 0;
  v23.Header = (_ACE_HEADER)varname;
  v24 = 0;
  v25 = 0;
  v26 = 4;
  if ( GASEnvironment::FindAndGetVariableRaw(this: (GASEnvironment *)a1, rv: &v23) )
  {
    GASValue::~GASValue(this: val);
    v3 = (*(_DWORD *)(pvar.NodeNumber + 8))-- == 1;
    if ( v3 )
      GASStringNode::ReleaseNode();
    v3 = (*(_DWORD *)(v5 + 8))-- == 1;
    if ( v3 )
    {
      GASStringNode::ReleaseNode();
      return 1;
    }
    return 1;
  }
  if ( GASEnvironment::ParsePath(
         varPath: v6,
         a2: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)varname,
         ppath: (_SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode>)&path,
         (_SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode>)&pvar) == 0 )
  {
    m_pMemory = pwithStack.m_Memory.m_pMemory;
    if ( pwithStack.m_Memory.m_pMemory != nullptr )
    {
      for ( i = *((_DWORD *)pwithStack.m_Memory.m_pMemory + 1) - 1; i >= 0; --i )
      {
        v10 = (int *)(*(_DWORD *)m_pMemory + 8 * i);
        v11 = v10[1];
        v12 = *v10;
        if ( v11 >= 0 )
        {
          if ( v12 != 0 )
          {
            v13 = v12 + 120;
LABEL_22:
            if ( v13 != 0 )
            {
              if ( (*(unsigned __int8 (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)v13 + 44))(
                     a1: v13,
                     a2: v6,
                     a3: varname,
                     a4: val) != 0 )
                goto LABEL_33;
              m_pMemory = pwithStack.m_Memory.m_pMemory;
            }
          }
        }
        else if ( v12 != 0 )
        {
          v13 = v12 + 16;
          goto LABEL_22;
        }
      }
    }
    v14 = v28;
    if ( GASEnvironment::FindLocal(this: (GASEnvironment *)v28, key: varname) == nullptr
      && (*(_DWORD *)&v14[14].layout_dependent == 0
       || (*(unsigned __int8 (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)(*(_DWORD *)&v14[14].layout_dependent + 120) + 44))(
            a1: *(_DWORD *)&v14[14].layout_dependent + 120,
            a2: v6,
            a3: varname,
            a4: val) == 0) )
    {
      if ( v14[15].layout_dependent <= 6u )
      {
        if ( *(_DWORD *)(varname->N.Name.Short + 4) == 0 )
          GASStringNode::ResolveLowercase_Impl();
        Short = v6->N.Name.Short;
        v16 = (char **)varname->N.Name.Short;
        v18 = *(_DWORD *)(varname->N.Name.Short + 4);
        if ( *(_DWORD *)(*(_DWORD *)(v6->N.Name.Short + 252) + 4) == v18
          || *(_DWORD *)(*(_DWORD *)(Short + 264) + 4) == v18
          || *(_DWORD *)(*(_DWORD *)(Short + 260) + 4) == v18 )
        {
          goto LABEL_33;
        }
      }
      else
      {
        v15 = v6->N.Name.Short;
        v16 = (char **)varname->N.Name.Short;
        if ( *(_DWORD *)(v6->N.Name.Short + 252) == varname->N.Name.Short
          || *(char ***)(v15 + 264) == v16
          || *(char ***)(v15 + 260) == v16 )
        {
          goto LABEL_33;
        }
      }
      if ( **v16 != 95
        || (v19 = v28,
            v20 = *v16,
            LOBYTE(v28) = v28[15].layout_dependent > 6u,
            pwithStack.m_Memory.m_pMemory = nullptr,
            (v21 = GFxMovieRoot::ParseLevelName(
                     nptr: v20,
                     ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&pwithStack,
                     caseSensitive: (bool)v28)) == -1)
        || *pwithStack.m_Memory.m_pMemory != 0
        || (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)&v19[14].layout_dependent + 100))(
             a1: *(_DWORD *)&v19[14].layout_dependent,
             a2: v21) == 0 )
      {
        v22 = *(_DWORD *)(v6->N.Name.Short + 680);
        if ( v22 == 0
          || (*(unsigned __int8 (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)(v22 + 16) + 44))(
               a1: v22 + 16,
               a2: v6,
               a3: varname,
               a4: val) == 0 )
        {
          goto LABEL_50;
        }
      }
    }
LABEL_33:
    GASValue::~GASValue(this: val);
    v3 = (*(_DWORD *)(pvar.NodeNumber + 8))-- == 1;
    if ( v3 )
      GASStringNode::ReleaseNode();
    v3 = (*(_DWORD *)(path + 8))-- == 1;
    if ( v3 )
      GASStringNode::ReleaseNode();
    return 1;
  }
  GASEnvironment::FindTarget(
    this: v28,
    (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)&path,
    excludeFlags: 4);
  if ( v7 != 0 )
  {
    HIBYTE(pwithStack.m_Memory.m_pMemory) = (*(int (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode> *, GASValue *))(*(_DWORD *)(v7 + 120) + 44))(
                                              a1: v7 + 120,
                                              a2: v6,
                                              a3: &pvar,
                                              a4: val);
    GASValue::~GASValue(this: val);
    v3 = (*(_DWORD *)(pvar.NodeNumber + 8))-- == 1;
    if ( v3 )
      GASStringNode::ReleaseNode();
    v3 = (*(_DWORD *)(path + 8))-- == 1;
    if ( v3 )
      GASStringNode::ReleaseNode();
    return HIBYTE(pwithStack.m_Memory.m_pMemory);
  }
LABEL_50:
  GASValue::~GASValue(this: val);
  v3 = (*(_DWORD *)(pvar.NodeNumber + 8))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode();
  v3 = (*(_DWORD *)(path + 8))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009C030
// Name: public: void GASEnvironment::SetVariableRaw(class GASString const __near &,class GASValue const __near &,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASEnvironment::SetVariableRaw(
        int a1@<ecx>,
        _IMAGE_SYMBOL_EX *varname,
        tagWNDCLASSW *val,
        CUtlInplaceBuffer pwithStack)
{
  unsigned __int8 *m_pMemory; // eax
  int v6; // ebx
  _IMAGE_SYMBOL_EX *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  void (__thiscall *v12)(int, int, _IMAGE_SYMBOL_EX *, tagWNDCLASSW *, char *); // edx
  int v13; // ecx
  GASValue dummy[4]; // [esp+Ch] [ebp-10h] BYREF

  m_pMemory = pwithStack.m_Memory.m_pMemory;
  if ( pwithStack.m_Memory.m_pMemory != nullptr )
  {
    v6 = *((_DWORD *)pwithStack.m_Memory.m_pMemory + 1) - 1;
    if ( v6 >= 0 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)m_pMemory;
        v9 = *(_DWORD *)(v8 + 8 * v6 + 4);
        v10 = *(_DWORD *)(v8 + 8 * v6);
        if ( v9 >= 0 )
        {
          if ( v10 == 0 )
          {
LABEL_11:
            v11 = 0;
            goto LABEL_12;
          }
          v11 = v10 + 120;
        }
        else
        {
          if ( v10 == 0 )
            goto LABEL_11;
          v11 = v10 + 16;
        }
LABEL_12:
        LOBYTE(dummy[0]) = 0;
        if ( v11 != 0
          && (*(unsigned __int8 (__thiscall **)(int, int, _IMAGE_SYMBOL_EX *, GASValue *))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: a1,
               a3: varname,
               a4: dummy) != 0 )
        {
          v12 = *(void (__thiscall **)(int, int, _IMAGE_SYMBOL_EX *, tagWNDCLASSW *, char *))(*(_DWORD *)v11 + 12);
          HIBYTE(pwithStack.m_Memory.m_pMemory) = 0;
          v12(a1: v11, a2: a1, a3: varname, a4: val, a5: (char *)&pwithStack.m_Memory.m_pMemory + 3);
          GASValue::~GASValue(this: dummy);
          return;
        }
        GASValue::~GASValue(this: dummy);
        if ( --v6 < 0 )
          break;
        m_pMemory = pwithStack.m_Memory.m_pMemory;
      }
    }
  }
  v7 = varname;
  if ( GASEnvironment::FindLocal(this: (GASEnvironment *)a1, key: varname) != nullptr )
  {
    GASValue::operator=(v: val);
  }
  else
  {
    v13 = *(_DWORD *)(a1 + 116) + 120;
    HIBYTE(varname) = 0;
    (*(void (__thiscall **)(int, int, _IMAGE_SYMBOL_EX *, tagWNDCLASSW *, char *))(*(_DWORD *)v13 + 12))(
      a1: v13,
      a2: a1,
      a3: v7,
      a4: val,
      a5: (char *)&varname + 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C120
// Name: public: class GASLocalFrame __near * GASEnvironment::CreateNewLocalFrame(void)
// Source: json
//------------------------------------------------------------------------------
struct GASLocalFrame *__thiscall GASEnvironment::CreateNewLocalFrame(GRenderer::CachedData *this)
{
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  GRenderer::CachedData *v7; // edi
  void *hData; // edx
  int *v9; // eax
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v2 = *(_DWORD *)(*((_DWORD *)this + 30) + 656);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  v11 = 323;
  v4 = v3(a1: v2, a2: 72, a3: &v11);
  if ( v4 != 0 )
  {
    if ( *((_DWORD *)this + 29) != 0 )
      v5 = *(_DWORD *)(*(_DWORD *)((*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 84))(a1: *((_DWORD *)this + 29))
                                 + 20)
                     + 12);
    else
      v5 = 0;
    *(_DWORD *)(v4 + 4) = v5;
    *(_DWORD *)(v4 + 8) = 1;
    *(_DWORD *)v4 = &GASLocalFrame::`vftable';
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = 0;
    *(_DWORD *)(v4 + 24) = 0;
    *(_DWORD *)(v4 + 28) = 0;
    *(_DWORD *)(v4 + 32) = 0;
    *(_DWORD *)(v4 + 36) = 0;
    *(_BYTE *)(v4 + 40) = 0;
    *(_BYTE *)(v4 + 56) = 0;
  }
  else
  {
    v4 = 0;
  }
  v6 = *((_DWORD *)this + 51);
  v7 = this + 25;
  GArrayDataBase<GPtr<GASObject>,GAllocatorLH<GPtr<GASObject>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: v7,
    pheapAddr: (ButtonCode_t)v7,
    newSize: v6 + 1);
  hData = v7->hData;
  v9 = (int *)((char *)v7->pRenderer + 4 * (_DWORD)hData - 4);
  if ( (GRenderer *)((char *)v7->pRenderer + 4 * (_DWORD)hData) != (GRenderer *)4 )
  {
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
    *v9 = v4;
  }
  if ( v4 != 0 )
    GRefCountBaseGC<323>::Release(a1: v4, a2: (int)v7);
  return (struct GASLocalFrame *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1009C1E0
// Name: public: void GASStringHashBase<class GASValue,class GHashUncachedLH_GC<class GASString,class GASValue,struct GASStringHashFunctor,323>>::SetCaseCheck(class GASString const __near &,class GASValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::SetCaseCheck(
        int a1,
        tagWNDCLASSW *v,
        int a3)
{
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h]

  GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::FindCaseCheck();
  if ( v4 != 0 && *(_DWORD *)v4 != 0 && v5 <= *(_DWORD *)(*(_DWORD *)v4 + 4) )
    return GASValue::operator=(v);
  else
    return GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeRef>();
}

//------------------------------------------------------------------------------
// Address: 0x1009C870
// Name: public: void GASGlobalContext::PreClean(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASGlobalContext::PreClean(
        GASGlobalContext *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int preserveBuiltinProps)
{
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *, int); // eax
  _DWORD *v7; // ebx
  int v8; // eax
  _EVENTLOGRECORD *v9; // eax
  int v10; // ecx
  void (__thiscall *v11)(_DWORD *, GASGlobalContext **, struct GASStringNode **, GASValue *, char *); // eax
  void (__thiscall *v12)(_DWORD *, GASGlobalContext **, struct GASStringNode **, GASValue *, char *); // eax
  void (__thiscall *v13)(_DWORD *, GASGlobalContext **, struct GASStringNode **, GASValue *, char *); // eax
  int v14; // ecx
  bool v15; // zf
  int v16; // ecx
  GFxTextClipboard *v17; // [esp+0h] [ebp-2Ch]
  void (__cdecl *v18)(void *); // [esp+0h] [ebp-2Ch]
  GASValue v[4]; // [esp+4h] [ebp-28h] BYREF
  GASGlobalContext *v20; // [esp+14h] [ebp-18h] BYREF
  char v21; // [esp+18h] [ebp-14h]
  int v22; // [esp+1Ch] [ebp-10h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+20h] [ebp-Ch] BYREF
  struct GASStringNode *v24; // [esp+24h] [ebp-8h] BYREF
  struct GASStringNode *v25; // [esp+28h] [ebp-4h] BYREF

  if ( (_BYTE)preserveBuiltinProps != 0 )
  {
    v5 = *((_DWORD *)this + 164);
    v6 = *(int (__thiscall **)(int, int, int *, int))(*(_DWORD *)v5 + 40);
    v22 = 323;
    v7 = (_DWORD *)v6(a1: v5, a2: 56, a3: &v22, a4: a2);
    if ( v7 != nullptr )
    {
      v8 = *((_DWORD *)this + 163);
      if ( v8 != 0 )
        v9 = *(_EVENTLOGRECORD **)(*(_DWORD *)(v8 + 20) + 12);
      else
        v9 = nullptr;
      GASObject::GASObject(result: v9);
      *v7 = &GASGlobalObject::`vftable'{for `GASRefCountBase<GASObject>'};
      v7[4] = &GASGlobalObject::`vftable'{for `GASObjectInterface'};
      v7[13] = this;
    }
    else
    {
      v7 = nullptr;
    }
    v20 = this;
    v21 = 8;
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: *((GASStringManager **)this + 159),
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"gfxPlayer",
                        a3: 9u,
                        a4: 0);
    ++*((_DWORD *)ConstStringNode + 2);
    v24 = GASStringManager::CreateConstStringNode(
            this: *((GASStringManager **)v20 + 159),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F680.m_Memory.m_nGrowSize,
            a3: 0xBu,
            a4: 0);
    ++*((_DWORD *)v24 + 2);
    v25 = GASStringManager::CreateConstStringNode(
            this: *((GASStringManager **)v20 + 159),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029F680,
            a3: 6u,
            a4: 0);
    ++*((_DWORD *)v25 + 2);
    v10 = *((_DWORD *)this + 170) + 16;
    LOBYTE(v[0]) = 0;
    (*(void (__thiscall **)(int, GASGlobalContext **, struct GASStringNode **))(*(_DWORD *)v10 + 44))(
      a1: v10,
      a2: &v20,
      a3: &ConstStringNode);
    v11 = *(void (__thiscall **)(_DWORD *, GASGlobalContext **, struct GASStringNode **, GASValue *, char *))(v7[4] + 40);
    HIBYTE(preserveBuiltinProps) = 0;
    v11(a1: v7 + 4, a2: &v20, a3: &ConstStringNode, a4: v, a5: (char *)&preserveBuiltinProps + 3);
    (*(void (__thiscall **)(int, GASGlobalContext **, struct GASStringNode **, GASValue *))(*(_DWORD *)(*((_DWORD *)this + 170) + 16)
                                                                                          + 44))(
      a1: *((_DWORD *)this + 170) + 16,
      a2: &v20,
      a3: &v24,
      a4: v);
    v12 = *(void (__thiscall **)(_DWORD *, GASGlobalContext **, struct GASStringNode **, GASValue *, char *))(v7[4] + 40);
    HIBYTE(preserveBuiltinProps) = 0;
    v12(a1: v7 + 4, a2: &v20, a3: &v24, a4: v, a5: (char *)&preserveBuiltinProps + 3);
    (*(void (__thiscall **)(int, GASGlobalContext **, struct GASStringNode **, GASValue *))(*(_DWORD *)(*((_DWORD *)this + 170) + 16)
                                                                                          + 44))(
      a1: *((_DWORD *)this + 170) + 16,
      a2: &v20,
      a3: &v25,
      a4: v);
    v13 = *(void (__thiscall **)(_DWORD *, GASGlobalContext **, struct GASStringNode **, GASValue *, char *))(v7[4] + 40);
    HIBYTE(preserveBuiltinProps) = 0;
    v13(a1: v7 + 4, a2: &v20, a3: &v25, a4: v, a5: (char *)&preserveBuiltinProps + 3);
    v7[2] = (v7[2] + 1) & 0x8FFFFFFF;
    v14 = *((_DWORD *)this + 170);
    if ( v14 != 0 )
      GRefCountBaseGC<323>::Release(a1: v14, a2: 1);
    *((_DWORD *)this + 170) = v7;
    GASValue::~GASValue(this: v);
    v15 = (*((_DWORD *)v25 + 2))-- == 1;
    if ( v15 )
      GASStringNode::ReleaseNode();
    v15 = (*((_DWORD *)v24 + 2))-- == 1;
    if ( v15 )
      GASStringNode::ReleaseNode();
    v15 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
    if ( v15 )
      GASStringNode::ReleaseNode();
    GRefCountBaseGC<323>::Release(a1: (int)v7, a2: (int)v);
  }
  else
  {
    v16 = *((_DWORD *)this + 170);
    if ( v16 != 0 )
      GRefCountBaseGC<323>::Release(a1: v16, a2: a3);
    *((_DWORD *)this + 170) = 0;
  }
  GHashSetBase<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>>::Clear(result: v17);
  GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>(
    this: (GWaitable *)this + 54,
    a2: v18,
    a3: v[0]);
  GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::~GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>(this: (GArrayDefaultPolicy *)this + 160);
  *((_DWORD *)this + 163) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009CAA0
// Name: public: void GASExecutionContext::Function1OpCode(class GASActionBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASExecutionContext::Function1OpCode@<al>(
        GPtr<GJPEGSystem> *this@<ecx>,
        const char *a2@<ebx>,
        unsigned int pActions)
{
  GJPEGInput *(__thiscall *CreateSwfJpeg2HeaderOnly)(GJPEGSystem *, const unsigned __int8 *, unsigned int); // ecx
  int (__thiscall *v5)(_DWORD, int, vc_attributes::PreRangeAttribute **); // edx
  GSize<float> *v6; // eax
  GSize<float> *v7; // esi
  int v8; // ebx
  int v9; // eax
  CUtlMemory<void *,int> *v10; // eax
  int v11; // ecx
  char *p_Height; // ebx
  vc_attributes::PreRangeAttribute *v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // esi
  _DWORD *j; // eax
  int v17; // ecx
  _DWORD *v18; // esi
  vc_attributes::PreRangeAttribute *v19; // eax
  int v20; // ecx
  bool v21; // zf
  int v22; // ecx
  const char *MinVal; // edx
  float v24; // eax
  GJPEGSystem *pObject; // eax
  volatile int RefCount; // ecx
  tagIMECHARPOSITION *v27; // ecx
  GJPEGSystem *v28; // eax
  int v29; // ecx
  GJPEGInput *(__thiscall *v30)(GJPEGSystem *, const unsigned __int8 *, unsigned int); // ecx
  int (__thiscall *v31)(_DWORD, int, vc_attributes::PreRangeAttribute **); // eax
  vc_attributes::PreRangeAttribute *v32; // ecx
  const char *v33; // ebx
  const char **p_MinVal; // esi
  int v35; // ecx
  int k; // eax
  int v37; // edx
  int Index; // eax
  const char *v39; // eax
  vc_attributes::PreRangeAttribute *v40; // eax
  char *v41; // ecx
  int v42; // ebx
  int v43; // ecx
  int m; // eax
  int v45; // edx
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int n; // eax
  int v50; // edx
  unsigned int v51; // ecx
  __vc_attributes::iid_isAttribute *v52; // ebx
  GASValue *limited_expression; // ebx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *Instance; // eax
  char v55; // al
  unsigned int Width_low; // ebx
  const char *v57; // esi
  int v58; // eax
  GJPEGSystem *v59; // edi
  CUtlMemory<void *,int> *v60; // edx
  int *v61; // ecx
  int v62; // eax
  int v63; // eax
  GASValue FunctionValue[4]; // [esp+8h] [ebp-38h] BYREF
  GSize<float> *v67; // [esp+18h] [ebp-28h] BYREF
  int v68; // [esp+1Ch] [ebp-24h]
  char v69; // [esp+20h] [ebp-20h]
  vc_attributes::PreRangeAttribute *v70; // [esp+24h] [ebp-1Ch] BYREF
  vc_attributes::PreRangeAttribute *v71; // [esp+28h] [ebp-18h] BYREF
  CUtlMemory<void *,int> *v72; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h] BYREF
  int v74; // [esp+34h] [ebp-Ch] BYREF
  GSize<float> *v75; // [esp+38h] [ebp-8h]
  char v76; // [esp+3Fh] [ebp-1h] BYREF
  float pActionsa; // [esp+48h] [ebp+8h]

  CreateSwfJpeg2HeaderOnly = this->pObject[15].__vftable[27].CreateSwfJpeg2HeaderOnly;
  v5 = *(int (__thiscall **)(_DWORD, int, vc_attributes::PreRangeAttribute **))(*(_DWORD *)CreateSwfJpeg2HeaderOnly + 40);
  v71 = (vc_attributes::PreRangeAttribute *)323;
  v6 = (GSize<float> *)v5(a1: CreateSwfJpeg2HeaderOnly, a2: 108, a3: &v71);
  if ( v6 != nullptr )
  {
    v7 = GASAsFunctionObject::GASAsFunctionObject(this: v6, penv: (const GSize<float> *)this->pObject);
    v75 = v7;
  }
  else
  {
    v75 = nullptr;
    v7 = nullptr;
  }
  v8 = *((_DWORD *)this + 6) + 3;
  GASStringManager::CreateStringNode(this: (const char *)this->pObject[15].__vftable[26].CreateSwfJpeg2HeaderOnly_2);
  v74 = v9;
  ++*(_DWORD *)(v9 + 8);
  v10 = (CUtlMemory<void *,int> *)*(unsigned __int16 *)(*((_DWORD *)this + 2) + v8 + *(_DWORD *)(v74 + 16) + 1);
  v11 = v8 + *(_DWORD *)(v74 + 16) + 3;
  i = v11;
  if ( v10 != nullptr )
  {
    p_Height = (char *)&v7[10].Height;
    v72 = v10;
    do
    {
      GASStringManager::CreateStringNode(this: (const char *)this->pObject[15].__vftable[26].CreateSwfJpeg2HeaderOnly_2);
      ++v13->MaxVal;
      v14 = LODWORD(v7[11].Width) + 1;
      v71 = v13;
      v70 = *((vc_attributes::PreRangeAttribute **)p_Height + 1);
      GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (AvatarImageLoaded_t *)p_Height,
        pheapAddr: p_Height,
        newSize: v14);
      if ( v14 > (unsigned int)v70 )
      {
        v15 = v14 - (_DWORD)v70;
        for ( j = (_DWORD *)(*(_DWORD *)p_Height + 8 * (_DWORD)v70); v15 != 0; --v15 )
        {
          if ( j != nullptr )
          {
            *j = *((_DWORD *)p_Height + 3);
            v17 = *((_DWORD *)p_Height + 4);
            j[1] = v17;
            ++*(_DWORD *)(v17 + 8);
          }
          j += 2;
        }
      }
      v18 = (_DWORD *)(*(_DWORD *)p_Height + 8 * *((_DWORD *)p_Height + 1) - 8);
      v19 = v71;
      *v18 = 0;
      ++v19->MaxVal;
      v20 = v18[1];
      v21 = (*(_DWORD *)(v20 + 8))-- == 1;
      if ( v21 )
      {
        GASStringNode::ReleaseNode();
        v19 = v71;
      }
      v22 = i;
      v18[1] = v19;
      MinVal = v19[1].MinVal;
      v21 = v19->MaxVal-- == (const char *)1;
      i = (int)&MinVal[v22 + 1];
      if ( v21 )
        GASStringNode::ReleaseNode();
      v21 = v72 == (CUtlMemory<void *,int> *)1;
      v72 = (CUtlMemory<void *,int> *)((char *)v72 - 1);
      v11 = i;
      v7 = v75;
    }
    while ( !v21 );
  }
  LODWORD(v24) = *(unsigned __int16 *)(*((_DWORD *)this + 2) + v11);
  v7[10].Width = v24;
  *((_DWORD *)this + 5) += LODWORD(v24);
  v69 = 0;
  v67 = v7;
  LODWORD(v7[1].Width) = (LODWORD(v7[1].Width) + 1) & 0x8FFFFFFF;
  pObject = this->pObject;
  v68 = 0;
  RefCount = pObject[25].RefCount;
  if ( RefCount != 0 )
  {
    v27 = *((tagIMECHARPOSITION **)pObject[25].__vftable + RefCount - 1);
    if ( v27 != nullptr )
      GASFunctionRefBase::SetLocalFrame(result: v27);
  }
  GASValue::GASValue(this: FunctionValue, a2: (const struct GASFunctionRef *)&v67);
  if ( *(_DWORD *)(v74 + 16) != 0 )
  {
    v28 = this->pObject;
    v29 = this->pObject[14].RefCount + 120;
    v76 = 0;
    (*(void (__thiscall **)(int, GJPEGSystem *, int *, GASValue *, char *))(*(_DWORD *)v29 + 40))(
      a1: v29,
      a2: v28 + 15,
      a3: &v74,
      a4: FunctionValue,
      a5: &v76);
  }
  v30 = this->pObject[15].__vftable[27].CreateSwfJpeg2HeaderOnly;
  v31 = *(int (__thiscall **)(_DWORD, int, vc_attributes::PreRangeAttribute **))(*(_DWORD *)v30 + 40);
  v70 = (vc_attributes::PreRangeAttribute *)323;
  v72 = (CUtlMemory<void *,int> *)v31(a1: v30, a2: 84, a3: &v70);
  if ( v72 != nullptr )
  {
    v32 = (vc_attributes::PreRangeAttribute *)this->pObject[15].__vftable;
    v33 = v32[53].MinVal;
    p_MinVal = &v32[53].MinVal;
    v71 = v32;
    i = 1;
    if ( v33 != nullptr )
    {
      v35 = 5381;
      for ( k = 4; k != 0; --k )
      {
        v37 = *((unsigned __int8 *)&v72 + k + 3);
        v35 = v37 + 65599 * v35;
      }
      Index = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::findIndexCore<enum GASBuiltinType>(
                a1: &i,
                a2: v35 & *((_DWORD *)v33 + 1));
      if ( Index >= 0 )
      {
        v39 = &v33[12 * Index + 12];
        if ( v39 != nullptr && v39 != (const char *)-4 )
          goto LABEL_30;
      }
      v32 = v71;
    }
    GASGlobalContext::ResolveFunctionName(this: v32, a2: (const struct GASString *)&v32[1]);
    GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
      a1: p_MinVal,
      a2: &i);
LABEL_30:
    GASFunctionProto::GASFunctionProto(this: v72, psc: (int)&this->pObject[15]);
    v7 = v75;
    v71 = v40;
    goto LABEL_32;
  }
  v71 = nullptr;
LABEL_32:
  v41 = (char *)this->pObject[15].__vftable;
  v42 = *((_DWORD *)v41 + 160);
  v70 = (vc_attributes::PreRangeAttribute *)v41;
  i = 7;
  v72 = (CUtlMemory<void *,int> *)(v41 + 640);
  if ( v42 != 0 )
  {
    v43 = 5381;
    for ( m = 4; m != 0; --m )
    {
      v45 = *((unsigned __int8 *)&v72 + m + 3);
      v43 = v45 + 65599 * v43;
    }
    v46 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::findIndexCore<enum GASBuiltinType>(
            a1: &i,
            a2: v43 & *(_DWORD *)(v42 + 4));
    if ( v46 >= 0 )
    {
      v47 = v42 + 4 * (3 * v46 + 3);
      if ( v47 != 0 && v47 != -4 )
        goto LABEL_43;
    }
    v41 = (char *)v70;
  }
  GASGlobalContext::ResolveFunctionName(
    this: (vc_attributes::PreRangeAttribute *)v41,
    a2: (const struct GASString *)(v41 + 36));
  if ( v72->m_pMemory != nullptr )
  {
    v48 = 5381;
    for ( n = 4; n != 0; --n )
    {
      v50 = *((unsigned __int8 *)&v72 + n + 3);
      v48 = v50 + 65599 * v48;
    }
    GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::findIndexCore<enum GASBuiltinType>(
      a1: &i,
      a2: v48 & (int)v72->m_pMemory[1]);
  }
LABEL_43:
  GASFunctionObject::SetProtoAndCtor(result: (_TRANSACTION_NOTIFICATION *)&this->pObject[15]);
  GASFunctionObject::SetPrototype(result: (_TRANSACTION_NOTIFICATION *)&this->pObject[15]);
  if ( *(_DWORD *)(v74 + 16) == 0 )
  {
    v52 = (__vc_attributes::iid_isAttribute *)this->pObject;
    v52[2].limited_expression += 16;
    if ( v52[2].limited_expression >= v52[4].limited_expression )
      GASPagedStack<GASValue,32>::PushPage(this: v52 + 2, a2);
    limited_expression = (GASValue *)v52[2].limited_expression;
    if ( limited_expression != nullptr )
      GASValue::GASValue(this: limited_expression, a2: (const struct GASValue *)FunctionValue);
  }
  Instance = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(a1: v51);
  GFxAmpServer::IsState(
    this: Instance,
    state: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)2);
  if ( v55 == 0 && *(_DWORD *)(v74 + 16) != 0 )
  {
    Width_low = LODWORD(v7[10].Width);
    v57 = *(const char **)v74;
    v58 = *(_DWORD *)(pActions + 8);
    v59 = this->pObject;
    v70 = *(vc_attributes::PreRangeAttribute **)(v58 + 20);
    v60 = *(CUtlMemory<void *,int> **)(v58 + 16);
    pActionsa = v75[9].Height;
    v61 = (int *)v59[14].RefCount;
    v62 = *v61;
    v72 = v60;
    v63 = (*(int (__thiscall **)(int *))(v62 + 84))(a1: v61);
    GFxAmpViewStats::RegisterScriptFunction(
      this: *(GFxAmpViewStats **)(v63 + 10308),
      swdHandle: (unsigned int)v72,
      swfOffset: (unsigned int)v70 + LODWORD(pActionsa),
      a4: v57,
      a5: Width_low);
    v7 = v75;
  }
  if ( v71 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v71, a2: 0);
  GASValue::~GASValue(this: FunctionValue);
  if ( (v69 & 2) == 0 && v67 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v67, a2: 0);
  v67 = nullptr;
  if ( (v69 & 1) == 0 && v68 != 0 )
    GRefCountBaseGC<323>::Release(a1: v68, a2: 0);
  v68 = 0;
  v21 = (*(_DWORD *)(v74 + 8))-- == 1;
  if ( v21 )
    GASStringNode::ReleaseNode();
  return GRefCountBaseGC<323>::Release(a1: (int)v7, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1009CF40
// Name: public: void GASExecutionContext::Function2OpCode(class GASActionBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASExecutionContext::Function2OpCode(GPtr<GJPEGSystem> *this, unsigned int pActions)
{
  GJPEGInput *(__thiscall *CreateSwfJpeg2HeaderOnly)(GJPEGSystem *, const unsigned __int8 *, unsigned int); // ecx
  int (__thiscall *v4)(_DWORD, int, int *); // edx
  GSize<float> *v5; // eax
  int v6; // esi
  unsigned int v7; // eax
  int v8; // edi
  int v9; // esi
  vc_attributes::PreRangeAttribute *v10; // eax
  char v11; // cl
  int v12; // edi
  __int16 v13; // dx
  int v14; // esi
  int v15; // eax
  struct GASStringNode *StringNode; // eax
  unsigned int v17; // edi
  unsigned int v18; // edi
  float *j; // eax
  GSize<float> *v20; // ecx
  float Height; // ecx
  int *v22; // edi
  int v23; // eax
  int v24; // ecx
  bool v25; // zf
  int v26; // edx
  int v27; // eax
  GJPEGSystem *pObject; // eax
  volatile int RefCount; // ecx
  tagIMECHARPOSITION *v30; // ecx
  GJPEGSystem *v31; // eax
  int v32; // ecx
  GJPEGInput *(__thiscall *v33)(GJPEGSystem *, const unsigned __int8 *, unsigned int); // ecx
  int (__thiscall *v34)(_DWORD, int, int *); // edx
  vc_attributes::PreRangeAttribute *v35; // ecx
  const char *MinVal; // esi
  const char **p_MinVal; // edi
  int v38; // ecx
  int k; // eax
  int v40; // edx
  int Index; // eax
  const char *v42; // eax
  int v43; // eax
  char *v44; // ecx
  int v45; // esi
  int v46; // ecx
  int m; // eax
  int v48; // edx
  int v49; // eax
  int v50; // eax
  int v51; // ecx
  int n; // eax
  int v53; // edx
  _TRANSACTION_NOTIFICATION *v54; // esi
  unsigned int v55; // ecx
  __vc_attributes::iid_isAttribute *v56; // esi
  GASValue *limited_expression; // esi
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *Instance; // eax
  char v59; // al
  unsigned int v60; // esi
  const char *v61; // edi
  int v62; // eax
  GJPEGSystem *v63; // ebx
  int v64; // edx
  int *v65; // ecx
  int v66; // eax
  int v67; // eax
  const char *v69; // [esp+0h] [ebp-48h]
  GASValue FunctionValue[4]; // [esp+Ch] [ebp-3Ch] BYREF
  int v71; // [esp+1Ch] [ebp-2Ch] BYREF
  int v72; // [esp+20h] [ebp-28h]
  char v73; // [esp+24h] [ebp-24h]
  CUtlMemory<void *,int> *v74; // [esp+28h] [ebp-20h]
  int psc; // [esp+2Ch] [ebp-1Ch] BYREF
  int v76; // [esp+30h] [ebp-18h] BYREF
  vc_attributes::PreRangeAttribute *i; // [esp+34h] [ebp-14h]
  int ArgRegister; // [esp+38h] [ebp-10h] BYREF
  unsigned int v79; // [esp+3Ch] [ebp-Ch] BYREF
  GSize<float> *v80; // [esp+40h] [ebp-8h]
  char v81; // [esp+47h] [ebp-1h] BYREF
  float pActionsa; // [esp+50h] [ebp+8h]

  CreateSwfJpeg2HeaderOnly = this->pObject[15].__vftable[27].CreateSwfJpeg2HeaderOnly;
  v4 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)CreateSwfJpeg2HeaderOnly + 40);
  psc = 323;
  v5 = (GSize<float> *)v4(a1: CreateSwfJpeg2HeaderOnly, a2: 108, a3: &psc);
  if ( v5 != nullptr )
    v80 = GASAsFunctionObject::GASAsFunctionObject(this: v5, penv: (const GSize<float> *)this->pObject);
  else
    v80 = nullptr;
  v6 = *((_DWORD *)this + 6) + 3;
  GASStringManager::CreateStringNode(this: (const char *)this->pObject[15].__vftable[26].CreateSwfJpeg2HeaderOnly_2);
  v79 = v7;
  ++*(_DWORD *)(v7 + 8);
  v8 = *((_DWORD *)this + 2);
  v9 = v6 + *(_DWORD *)(v79 + 16) + 1;
  v10 = (vc_attributes::PreRangeAttribute *)*(unsigned __int16 *)(v8 + v9);
  v11 = *(_BYTE *)(v8 + v9 + 2);
  v12 = (int)v80;
  HIBYTE(v80[13].Width) = v11;
  v13 = *(_WORD *)(v9 + *((_DWORD *)this + 2) + 3);
  v14 = v9 + 5;
  *(_WORD *)(v12 + 104) = v13;
  if ( v10 != nullptr )
  {
    for ( i = v10; i != nullptr; i = (vc_attributes::PreRangeAttribute *)((char *)i - 1) )
    {
      v15 = *((_DWORD *)this + 2);
      ArgRegister = *(unsigned __int8 *)(v15 + v14);
      StringNode = GASStringManager::CreateStringNode(
                     this: (GASStringManager *)this->pObject[15].__vftable[26].CreateSwfJpeg2HeaderOnly_2,
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v15 + v14 + 1),
                     length: strlen((const char *)(v15 + v14 + 1)));
      ++*((_DWORD *)StringNode + 2);
      v76 = (int)StringNode;
      v17 = LODWORD(v80[11].Width) + 1;
      psc = LODWORD(v80[11].Width);
      GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (AvatarImageLoaded_t *)&v80[10].Height,
        pheapAddr: &v80[10].Height,
        newSize: v17);
      if ( v17 > psc )
      {
        v18 = v17 - psc;
        for ( j = (float *)(LODWORD(v80[10].Height) + 8 * psc); v18 != 0; --v18 )
        {
          if ( j != nullptr )
          {
            v20 = v80;
            *j = v80[12].Width;
            Height = v20[12].Height;
            j[1] = Height;
            ++*(_DWORD *)(LODWORD(Height) + 8);
          }
          j += 2;
        }
      }
      v22 = (int *)(LODWORD(v80[10].Height) + 8 * LODWORD(v80[11].Width) - 8);
      *v22 = ArgRegister;
      v23 = v76;
      ++*(_DWORD *)(v76 + 8);
      v24 = v22[1];
      v25 = (*(_DWORD *)(v24 + 8))-- == 1;
      if ( v25 )
      {
        GASStringNode::ReleaseNode();
        v23 = v76;
      }
      v22[1] = v23;
      v26 = *(_DWORD *)(v23 + 16);
      v25 = (*(_DWORD *)(v23 + 8))-- == 1;
      v14 += v26 + 2;
      if ( v25 )
        GASStringNode::ReleaseNode();
    }
    v12 = (int)v80;
  }
  v27 = *(unsigned __int16 *)(*((_DWORD *)this + 2) + v14);
  *(_DWORD *)(v12 + 80) = v27;
  *((_DWORD *)this + 5) += v27;
  v73 = 0;
  v71 = v12;
  *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
  pObject = this->pObject;
  v72 = 0;
  RefCount = pObject[25].RefCount;
  if ( RefCount != 0 )
  {
    v30 = *((tagIMECHARPOSITION **)pObject[25].__vftable + RefCount - 1);
    if ( v30 != nullptr )
      GASFunctionRefBase::SetLocalFrame(result: v30);
  }
  GASValue::GASValue(this: FunctionValue, a2: (const struct GASFunctionRef *)&v71);
  if ( *(_DWORD *)(v79 + 16) != 0 )
  {
    v31 = this->pObject;
    v32 = this->pObject[14].RefCount + 120;
    v81 = 0;
    (*(void (__thiscall **)(int, GJPEGSystem *, unsigned int *, GASValue *, char *))(*(_DWORD *)v32 + 40))(
      a1: v32,
      a2: v31 + 15,
      a3: &v79,
      a4: FunctionValue,
      a5: &v81);
  }
  v33 = this->pObject[15].__vftable[27].CreateSwfJpeg2HeaderOnly;
  v34 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)v33 + 40);
  psc = (int)&this->pObject[15];
  v76 = 323;
  v74 = (CUtlMemory<void *,int> *)v34(a1: v33, a2: 84, a3: &v76);
  if ( v74 != nullptr )
  {
    v35 = (vc_attributes::PreRangeAttribute *)this->pObject[15].__vftable;
    MinVal = v35[53].MinVal;
    p_MinVal = &v35[53].MinVal;
    i = v35;
    ArgRegister = 1;
    if ( MinVal != nullptr )
    {
      v38 = 5381;
      for ( k = 4; k != 0; --k )
      {
        v40 = *((unsigned __int8 *)&i + k + 3);
        v38 = v40 + 65599 * v38;
      }
      Index = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::findIndexCore<enum GASBuiltinType>(
                a1: &ArgRegister,
                a2: v38 & *((_DWORD *)MinVal + 1));
      if ( Index >= 0 )
      {
        v42 = &MinVal[12 * Index + 12];
        if ( v42 != nullptr && v42 != (const char *)-4 )
          goto LABEL_31;
      }
      v35 = i;
    }
    GASGlobalContext::ResolveFunctionName(this: v35, a2: (const struct GASString *)&v35[1]);
    GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
      a1: p_MinVal,
      a2: &ArgRegister);
LABEL_31:
    GASFunctionProto::GASFunctionProto(this: v74, psc);
    v12 = (int)v80;
    v76 = v43;
    goto LABEL_33;
  }
  v76 = 0;
LABEL_33:
  v44 = (char *)this->pObject[15].__vftable;
  v45 = *((_DWORD *)v44 + 160);
  v74 = (CUtlMemory<void *,int> *)v44;
  ArgRegister = 7;
  i = (vc_attributes::PreRangeAttribute *)(v44 + 640);
  if ( v45 != 0 )
  {
    v46 = 5381;
    for ( m = 4; m != 0; --m )
    {
      v48 = *((unsigned __int8 *)&i + m + 3);
      v46 = v48 + 65599 * v46;
    }
    v49 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::findIndexCore<enum GASBuiltinType>(
            a1: &ArgRegister,
            a2: v46 & *(_DWORD *)(v45 + 4));
    if ( v49 >= 0 )
    {
      v50 = v45 + 4 * (3 * v49 + 3);
      if ( v50 != 0 && v50 != -4 )
        goto LABEL_44;
    }
    v44 = (char *)v74;
  }
  GASGlobalContext::ResolveFunctionName(
    this: (vc_attributes::PreRangeAttribute *)v44,
    a2: (const struct GASString *)(v44 + 36));
  if ( i->Deref != 0 )
  {
    v51 = 5381;
    for ( n = 4; n != 0; --n )
    {
      v53 = *((unsigned __int8 *)&i + n + 3);
      v51 = v53 + 65599 * v51;
    }
    GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::findIndexCore<enum GASBuiltinType>(
      a1: &ArgRegister,
      a2: v51 & *(_DWORD *)(i->Deref + 4));
  }
LABEL_44:
  v54 = (_TRANSACTION_NOTIFICATION *)psc;
  GASFunctionObject::SetProtoAndCtor(result: (_TRANSACTION_NOTIFICATION *)psc);
  GASFunctionObject::SetPrototype(result: v54);
  v55 = v79;
  if ( *(_DWORD *)(v79 + 16) == 0 )
  {
    v56 = (__vc_attributes::iid_isAttribute *)this->pObject;
    v56[2].limited_expression += 16;
    if ( v56[2].limited_expression >= v56[4].limited_expression )
      GASPagedStack<GASValue,32>::PushPage(this: v56 + 2, a2: v69);
    limited_expression = (GASValue *)v56[2].limited_expression;
    if ( limited_expression != nullptr )
      GASValue::GASValue(this: limited_expression, a2: (const struct GASValue *)FunctionValue);
  }
  Instance = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(a1: v55);
  GFxAmpServer::IsState(
    this: Instance,
    state: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)2);
  if ( v59 == 0 && *(_DWORD *)(v79 + 16) != 0 )
  {
    v60 = *(_DWORD *)(v12 + 80);
    v61 = *(const char **)v79;
    v62 = *(_DWORD *)(pActions + 8);
    v63 = this->pObject;
    v74 = *(CUtlMemory<void *,int> **)(v62 + 20);
    v64 = *(_DWORD *)(v62 + 16);
    pActionsa = v80[9].Height;
    v65 = (int *)v63[14].RefCount;
    v66 = *v65;
    psc = v64;
    v67 = (*(int (__thiscall **)(int *))(v66 + 84))(a1: v65);
    GFxAmpViewStats::RegisterScriptFunction(
      this: *(GFxAmpViewStats **)(v67 + 10308),
      swdHandle: psc,
      swfOffset: (unsigned int)v74 + LODWORD(pActionsa),
      a4: v61,
      a5: v60);
    v12 = (int)v80;
  }
  if ( v76 != 0 )
    GRefCountBaseGC<323>::Release(a1: v76, a2: v12);
  GASValue::~GASValue(this: FunctionValue);
  if ( (v73 & 2) == 0 && v71 != 0 )
    GRefCountBaseGC<323>::Release(a1: v71, a2: v12);
  v71 = 0;
  if ( (v73 & 1) == 0 && v72 != 0 )
    GRefCountBaseGC<323>::Release(a1: v72, a2: v12);
  v72 = 0;
  v25 = (*(_DWORD *)(v79 + 8))-- == 1;
  if ( v25 )
    GASStringNode::ReleaseNode();
  return GRefCountBaseGC<323>::Release(a1: v12, a2: v12);
}

//------------------------------------------------------------------------------
// Address: 0x1009D410
// Name: public: void GASEnvironment::AddLocal(class GASString const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASEnvironment::AddLocal(
        GASEnvironment *this@<ecx>,
        int a2@<edi>,
        _IMAGE_SYMBOL_EX *varname,
        tagWNDCLASSW *val)
{
  int v4; // eax
  int v5; // esi

  v4 = *((_DWORD *)this + 50) + 4 * *((_DWORD *)this + 51) - 4;
  if ( *(_DWORD *)v4 != 0 )
    *(_DWORD *)(*(_DWORD *)v4 + 8) = (*(_DWORD *)(*(_DWORD *)v4 + 8) + 1) & 0x8FFFFFFF;
  v5 = *(_DWORD *)v4;
  if ( *(_DWORD *)v4 != 0 )
  {
    GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::SetCaseCheck(
      a1: (int)varname,
      v: val,
      a3: *((_BYTE *)this + 124) > 6u);
    GRefCountBaseGC<323>::Release(a1: v5, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D470
// Name: public: void GASEnvironment::DeclareLocal(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::DeclareLocal(int this, _IMAGE_SYMBOL_EX *result)
{
  int v3; // eax
  GASValue v4[4]; // [esp+4h] [ebp-10h] BYREF

  v3 = *(_DWORD *)(this + 204);
  if ( v3 != 0
    && *(_DWORD *)(*(_DWORD *)(this + 200) + 4 * v3 - 4) != 0
    && GASEnvironment::FindLocal((GASEnvironment *)this, key: result) == nullptr )
  {
    LOBYTE(v4[0]) = 0;
    GASEnvironment::AddLocal((GASEnvironment *)this, a2: (int)result, varname: result, val: (tagWNDCLASSW *)v4);
    GASValue::~GASValue(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D4C0
// Name: public: class GASObject __near * GASEnvironment::OperatorNew(class GASFunctionRef const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASEnvironment::OperatorNew(
        __vc_attributes::idl_quoteAttribute *this,
        const struct GASFunctionRef *a2,
        int nargs,
        int argsTopOff)
{
  __vc_attributes::idl_quoteAttribute *v4; // esi
  _DWORD *v5; // eax
  bool v6; // bl
  tagWNDCLASSW *text; // ecx
  char style; // al
  tagWNDCLASSW *v9; // eax
  struct GASObject *v10; // eax
  struct GASObject *v11; // esi
  const char *v13; // eax
  vc_attributes::PostBoundAttribute **v14; // ebx
  int v15; // ecx
  vc_attributes::PostBoundAttribute *v16; // esi
  int v17; // ecx
  int v18; // eax
  struct GASObject **v19; // eax
  int v20; // eax
  struct GASObject *v21; // eax
  struct GASObject *v22; // eax
  const struct GASFunctionRef *v23; // ecx
  struct GASObject *v24; // edi
  int v25; // eax
  tagIMECHARPOSITION *v26; // eax
  bool v27; // zf
  const struct GASFunctionRefBase *v28; // eax
  int v29; // eax
  int v30; // edi
  int v31; // esi
  struct GASObject *v32; // eax
  const struct GASFunctionRef *v33; // edi
  int v34; // eax
  int v35; // ecx
  int v36; // edi
  int v37; // eax
  int v38; // eax
  GASValue index[4]; // [esp+Ch] [ebp-A0h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v40; // [esp+1Ch] [ebp-90h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *newObjVal; // [esp+2Ch] [ebp-80h] BYREF
  GASValue __ctor__Val[4]; // [esp+3Ch] [ebp-70h] BYREF
  GASValue prototypeVal[4]; // [esp+4Ch] [ebp-60h] BYREF
  _DWORD v44[3]; // [esp+5Ch] [ebp-50h] BYREF
  int v45; // [esp+68h] [ebp-44h]
  int v46; // [esp+6Ch] [ebp-40h]
  char v47; // [esp+70h] [ebp-3Ch]
  struct GASEnvironment *v48; // [esp+74h] [ebp-38h]
  int v49; // [esp+78h] [ebp-34h]
  int v50; // [esp+7Ch] [ebp-30h]
  struct GASEnvironment *v51; // [esp+80h] [ebp-2Ch]
  int v52; // [esp+84h] [ebp-28h] BYREF
  int v53; // [esp+88h] [ebp-24h] BYREF
  int v54; // [esp+8Ch] [ebp-20h]
  char v55; // [esp+90h] [ebp-1Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *res; // [esp+94h] [ebp-18h] BYREF
  char className[4]; // [esp+98h] [ebp-14h] BYREF
  int v58; // [esp+9Ch] [ebp-10h]
  char v59; // [esp+A0h] [ebp-Ch]
  int v60; // [esp+A4h] [ebp-8h]
  char v61; // [esp+ABh] [ebp-1h] BYREF

  v4 = this;
  v51 = (struct GASEnvironment *)this;
  v60 = 0;
  LOBYTE(newObjVal) = 0;
  if ( argsTopOff < 0 )
    argsTopOff = ((*((_DWORD *)this + 2) - *((_DWORD *)this + 3)) >> 4) + 32 * *((_DWORD *)this + 7) - 32;
  v6 = false;
  if ( nargs == 1 )
  {
    v60 = 1;
    GASEnvironment::GetConstructor((__vc_attributes::async_uuidAttribute *)this, className, a3: 1);
    if ( *(_DWORD *)a2 == *v5 )
      v6 = true;
  }
  if ( (v60 & 1) != 0 )
  {
    v60 &= ~1u;
    if ( (v59 & 2) == 0 && *(_DWORD *)className != 0 )
      GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: 1);
    *(_DWORD *)className = 0;
    if ( (v59 & 1) == 0 && v58 != 0 )
      GRefCountBaseGC<323>::Release(a1: v58, a2: 1);
  }
  if ( !v6 )
    goto LABEL_29;
  text = (tagWNDCLASSW *)v4[2].text;
  LOBYTE(res) = 0;
  style = text->style;
  if ( LOBYTE(text->style) == 3 || style == 4 || style == 2 || style == 5 )
  {
    GASEnvironment::PrimitiveToTempObject(this: v4, index, indexa: 0);
    GASValue::operator=(v: v9);
    GASValue::~GASValue(this: index);
    goto LABEL_23;
  }
  if ( style == 6 || style == 7 )
  {
    GASValue::operator=(v: text);
LABEL_23:
    if ( (_BYTE)res != 0 && (_BYTE)res != 10 )
    {
      v10 = GASValue::ToObject(this: &res, a2: (const struct GASEnvironment *)v4);
      v11 = v10;
      if ( v10 != nullptr )
        v10[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v10[1].pNode->pNext + 1) & 0x8FFFFFFF);
      GASValue::~GASValue(this: &res);
      GASValue::~GASValue(this: &newObjVal);
      return v11;
    }
  }
  GASValue::~GASValue(this: &res);
LABEL_29:
  v13 = v4[30].text;
  v14 = (vc_attributes::PostBoundAttribute **)&v4[30];
  v15 = *(_DWORD *)a2 + 16;
  LOBYTE(prototypeVal[0]) = 0;
  if ( (*(unsigned __int8 (__thiscall **)(int, __vc_attributes::idl_quoteAttribute *, const char *, GASValue *))(*(_DWORD *)v15 + 44))(
         a1: v15,
         a2: v4 + 30,
         a3: v13 + 316,
         a4: prototypeVal) == 0 )
  {
    v16 = *v14;
    v17 = (int)&(*v14)[160];
    v52 = 1;
    v18 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
            a1: v17,
            a2: &v52);
    if ( v18 != 0 && (v19 = (struct GASObject **)(v18 + 4)) != nullptr
      || (GASGlobalContext::ResolveFunctionName(
            this: (vc_attributes::PreRangeAttribute *)v16,
            a2: (const struct GASString *)&v16[3]),
          (v20 = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::GetAlt<enum GASBuiltinType>(
                   a1: &v16[160],
                   a2: &v52)) != 0)
      && (v19 = (struct GASObject **)(v20 + 4)) != nullptr )
    {
      v21 = *v19;
    }
    else
    {
      v21 = nullptr;
    }
    GASValue::SetAsObject(this: prototypeVal, a2: v21);
    v4 = (__vc_attributes::idl_quoteAttribute *)v51;
  }
  v22 = GASValue::ToObject(this: prototypeVal, a2: (const struct GASEnvironment *)v4);
  v23 = a2;
  v24 = v22;
  v25 = *(_DWORD *)a2;
  v55 = 0;
  v53 = v25;
  if ( v25 != 0 )
  {
    ++*(_DWORD *)(v25 + 8);
    *(_DWORD *)(v25 + 8) &= 0x8FFFFFFF;
  }
  v26 = *((tagIMECHARPOSITION **)v23 + 1);
  v54 = 0;
  if ( v26 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v26);
  LOBYTE(__ctor__Val[0]) = 0;
  if ( v24 != nullptr
    && ((unsigned __int8 (__thiscall *)(struct GASObject *, vc_attributes::PostBoundAttribute **, vc_attributes::PostBoundAttribute *, GASValue *))v24[2].pNode[5].elem)(
         a1: &v24[2],
         a2: v14,
         a3: *v14 + 81,
         a4: __ctor__Val) != 0 )
  {
    if ( LOBYTE(__ctor__Val[0]) != 8 && LOBYTE(__ctor__Val[0]) != 11
      || (v60 |= 2u, v27 = *(_DWORD *)GASValue::ToFunction(a1: className, a2: v4) == 0, v61 = 1, v27) )
    {
      v61 = 0;
    }
    if ( (v60 & 2) != 0 )
    {
      if ( (v59 & 2) == 0 && *(_DWORD *)className != 0 )
        GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: (int)__ctor__Val);
      *(_DWORD *)className = 0;
      if ( (v59 & 1) == 0 && v58 != 0 )
        GRefCountBaseGC<323>::Release(a1: v58, a2: (int)__ctor__Val);
    }
    if ( v61 != 0 )
    {
      v28 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: className, a2: v4);
      GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&v53, a2: v28);
      if ( (v59 & 2) == 0 && *(_DWORD *)className != 0 )
        GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: (int)__ctor__Val);
      *(_DWORD *)className = 0;
      if ( (v59 & 1) == 0 && v58 != 0 )
        GRefCountBaseGC<323>::Release(a1: v58, a2: (int)__ctor__Val);
    }
  }
  v29 = (*(int (__thiscall **)(int, __vc_attributes::idl_quoteAttribute *))(*(_DWORD *)v53 + 60))(a1: v53, a2: v4);
  v52 = v29;
  if ( v29 != 0 )
  {
    v30 = *(_DWORD *)(v29 + 16);
    v31 = v29 + 16;
    v32 = GASValue::ToObject(this: prototypeVal, a2: v51);
    (*(void (__thiscall **)(int, vc_attributes::PostBoundAttribute **, struct GASObject *))(v30 + 52))(
      a1: v31,
      a2: v14,
      a3: v32);
    v33 = a2;
    v61 = 3;
    GASValue::GASValue(this: &res, a2);
    (*(void (__thiscall **)(int, vc_attributes::PostBoundAttribute **, vc_attributes::PostBoundAttribute *, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **, char *))(*(_DWORD *)v31 + 40))(
      a1: v31,
      a2: v14,
      a3: *v14 + 82,
      a4: &res,
      a5: &v61);
    GASValue::~GASValue(this: &res);
    v44[1] = &v40;
    v44[2] = v31;
    v50 = argsTopOff;
    v34 = *((_DWORD *)v33 + 1);
    v48 = v51;
    v35 = *(_DWORD *)v33;
    v49 = nargs;
    LOBYTE(v40) = 0;
    v44[0] = &GASFnCall::`vftable';
    v47 = 0;
    v45 = 0;
    v46 = 0;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v35 + 40))(a1: v35, a2: v44, a3: v34, a4: 0);
    v44[0] = &GASFnCall::`vftable';
    if ( (v47 & 2) == 0 && v45 != 0 )
      GRefCountBaseGC<323>::Release(a1: v45, a2: (int)v33);
    v45 = 0;
    if ( (v47 & 1) == 0 && v46 != 0 )
      GRefCountBaseGC<323>::Release(a1: v46, a2: (int)v33);
    v36 = v52;
    *(_DWORD *)(v52 + 8) = (*(_DWORD *)(v52 + 8) + 1) & 0x8FFFFFFF;
    GASValue::~GASValue(this: &v40);
    GASValue::~GASValue(this: __ctor__Val);
    if ( (v55 & 2) == 0 && v53 != 0 )
      GRefCountBaseGC<323>::Release(a1: v53, a2: v36);
    v53 = 0;
    if ( (v55 & 1) == 0 && v54 != 0 )
      GRefCountBaseGC<323>::Release(a1: v54, a2: v36);
    v54 = 0;
    GASValue::~GASValue(this: prototypeVal);
    GRefCountBaseGC<323>::Release(a1: v36, a2: v36);
    GASValue::~GASValue(this: &newObjVal);
    return (struct GASObject *)v36;
  }
  else
  {
    if ( *(_DWORD *)a2 != 0 )
      v37 = *(_DWORD *)a2 + 16;
    else
      v37 = 0;
    GASGlobalContext::FindClassName(
      this: *v14,
      result: (tagEMRALPHABLEND *)&argsTopOff,
      a3: (struct GASEnvironment *)v4,
      iobj: v37);
    if ( v53 != 0 )
      v38 = v53 + 16;
    else
      v38 = 0;
    GASGlobalContext::FindClassName(
      this: *v14,
      result: (tagEMRALPHABLEND *)&a2,
      a3: (struct GASEnvironment *)v4,
      iobj: v38);
    GASEnvironment::LogScriptError(
      this: (GASEnvironment *)v4,
      a2: "Error: %s::CreateNewObject returned NULL during creation of %s class instance.\n",
      *(const char **)a2,
      *(const char **)argsTopOff);
    v27 = (*((_DWORD *)a2 + 2))-- == 1;
    if ( v27 )
      GASStringNode::ReleaseNode();
    v27 = (*(_DWORD *)(argsTopOff + 8))-- == 1;
    if ( v27 )
      GASStringNode::ReleaseNode();
    GASValue::~GASValue(this: __ctor__Val);
    if ( (v55 & 2) == 0 && v53 != 0 )
      GRefCountBaseGC<323>::Release(a1: v53, a2: 0);
    v53 = 0;
    if ( (v55 & 1) == 0 && v54 != 0 )
      GRefCountBaseGC<323>::Release(a1: v54, a2: 0);
    v54 = 0;
    GASValue::~GASValue(this: prototypeVal);
    GASValue::~GASValue(this: &newObjVal);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D9A0
// Name: public: class GASObject __near * GASEnvironment::OperatorNew(class GASObject __near *,class GASString const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__userpurge GASEnvironment::OperatorNew@<eax>(
        __vc_attributes::idl_quoteAttribute *this@<ecx>,
        int a2@<edi>,
        struct GASObject *a3,
        const struct GASString *a4,
        int nargs,
        int argsTopOff)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  const struct GASFunctionRef *v8; // eax
  struct GASObject *v9; // esi
  GASValue v11[4]; // [esp+4h] [ebp-1Ch] BYREF
  int v12; // [esp+14h] [ebp-Ch] BYREF
  int v13; // [esp+18h] [ebp-8h]
  char v14; // [esp+1Ch] [ebp-4h]

  pNext = a3[2].pNode[2].pNext;
  LOBYTE(v11[0]) = 0;
  if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, __vc_attributes::idl_quoteAttribute *, const struct GASString *, GASValue *))pNext)(
         a1: &a3[2],
         a2: this,
         a3: a4,
         a4: v11) != 0
    && (LOBYTE(v11[0]) == 8 || LOBYTE(v11[0]) == 11) )
  {
    v8 = (const struct GASFunctionRef *)GASValue::ToFunction(a1: &v12, a2: this);
    v9 = GASEnvironment::OperatorNew(this, a2: v8, nargs, argsTopOff);
    if ( (v14 & 2) == 0 && v12 != 0 )
      GRefCountBaseGC<323>::Release(a1: v12, a2);
    v12 = 0;
    if ( (v14 & 1) == 0 && v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2);
    v13 = 0;
    GASValue::~GASValue(this: v11);
    return v9;
  }
  else
  {
    GASValue::~GASValue(this: v11);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DB80
// Name: public: bool GASGlobalContext::UnregisterClassA(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASGlobalContext::UnregisterClassA(
        GFxMeshCacheManager *this,
        struct GASStringContext *a2,
        _IMAGE_SYMBOL_EX *key)
{
  struct GASStringContext *v3; // ebx
  struct GASStringContext *v4; // edi
  CLoggingSystem *v5; // esi
  int v6; // eax
  bool v8; // zf
  LoggingSeverity_t v9; // [esp+0h] [ebp-Ch]

  v3 = a2;
  v4 = (struct GASStringContext *)key;
  v5 = (CLoggingSystem *)(this + 23);
  LOBYTE(a2) = *((_BYTE *)a2 + 4) > 6u;
  GASStringHashBase<GASFunctionRef,GHashUncachedLH<GASString,GASFunctionRef,GASStringHashFunctor,323>>::GetCaseCheck(
    this: this + 23,
    key,
    caseSensitive: (char)a2);
  if ( v6 == 0 )
    return 0;
  if ( *((_BYTE *)v3 + 4) <= 6u )
  {
    v8 = *(_DWORD *)(*(_DWORD *)v4 + 4) == 0;
    a2 = v4;
    if ( v8 )
      GASStringNode::ResolveLowercase_Impl();
    GHashSetBase<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>>::RemoveAlt<GASString::NoCaseKey>(
      this: v5,
      key: (int)&a2,
      naturalIndex: v9);
    return 1;
  }
  else
  {
    GHashSetBase<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>>::RemoveAlt<GASString>(
      a1: v5,
      a2: v4);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DBF0
// Name: public: void GASEnvironment::SetLocal(class GASString const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::SetLocal(GASEnvironment *this, _IMAGE_SYMBOL_EX *varname, tagWNDCLASSW *val)
{
  int v4; // eax

  v4 = *((_DWORD *)this + 51);
  if ( v4 != 0 && *(_DWORD *)(*((_DWORD *)this + 50) + 4 * v4 - 4) != 0 )
  {
    if ( GASEnvironment::FindLocal(this, key: varname) != nullptr )
      GASValue::operator=(v: val);
    else
      GASEnvironment::AddLocal(this, a2: (int)varname, varname, val);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DC40
// Name: public: class GASValue GASEnvironment::PrimitiveToTempObject(class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
__vc_attributes::idl_quoteAttribute *__userpurge GASEnvironment::PrimitiveToTempObject@<eax>(
        int a1@<ecx>,
        const char *a2@<esi>,
        __vc_attributes::idl_quoteAttribute *result,
        const struct GASValue *v)
{
  char v5; // cl
  int v6; // ebx
  int v8; // esi
  struct GASObject *v9; // edi
  const char *v10; // [esp-4h] [ebp-Ch]

  v5 = *(_BYTE *)v;
  if ( *(_BYTE *)v == 2 )
  {
    v6 = 5;
  }
  else if ( *(_BYTE *)v == 5 )
  {
    v6 = 3;
  }
  else
  {
    if ( v5 != 3 && v5 != 4 )
    {
      LOBYTE(result->text) = 0;
      return result;
    }
    v6 = 4;
  }
  *(_DWORD *)(a1 + 8) += 16;
  v10 = a2;
  v8 = a1 + 8;
  if ( *(_DWORD *)(a1 + 8) >= *(_DWORD *)(a1 + 16) )
    GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a1 + 8), a2: v10);
  if ( *(_DWORD *)v8 != 0 )
    GASValue::GASValue(this: *(GASValue **)v8, a2: v);
  v9 = GASEnvironment::OperatorNew(
         this: (__vc_attributes::idl_quoteAttribute *)a1,
         a2: a1,
         a3: *(struct GASObject **)(*(_DWORD *)(a1 + 120) + 680),
         a4: (const struct GASString *)(*(_DWORD *)(a1 + 120) + 4 * v6 + 8),
         nargs: 1,
         argsTopOff: ((*(_DWORD *)(a1 + 8) - *(_DWORD *)(a1 + 12)) >> 4) + 32 * *(_DWORD *)(a1 + 28) - 32);
  GASValue::~GASValue(this: *(GASValue **)v8);
  *(_DWORD *)v8 -= 16;
  if ( *(_DWORD *)v8 < *(_DWORD *)(v8 + 4) )
    GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v8, a2: v10);
  GASValue::GASValue(this: (GASValue *)result, a2: v9);
  if ( v9 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v9, a2: (int)v9);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DD10
// Name: public: bool GASEnvironment::GetVariableRaw(struct GASEnvironment::GetVarParams const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GASEnvironment::GetVariableRaw@<al>(GASEnvironment *this@<ecx>, int a2@<edi>, int rv)
{
  GASValue *v3; // esi
  GASEnvironment *v4; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  int v12; // edi
  tagWNDCLASSW *Local; // eax
  bool v14; // zf
  unsigned __int8 v15; // cl
  GASValue *v16; // edx
  int v17; // edi
  CBitWrite *v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // edi
  int v22; // ecx
  int (__thiscall *v23)(int, int, int *, int); // eax
  bool v24; // cc
  _DWORD *v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // edx
  CBitWrite *v28; // eax
  GASValue *v29; // ebx
  _SYSTEM_AUDIT_CALLBACK_ACE *v30; // eax
  int v31; // ecx
  int v32; // edx
  struct GASObject *v33; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v35; // edx
  unsigned __int8 v36; // al
  GASValue *v37; // edx
  int v38; // eax
  int v39; // eax
  _SYSTEM_AUDIT_CALLBACK_ACE *v40; // eax
  unsigned int v41; // ecx
  int v42; // ecx
  int (__thiscall *v43)(int, int, int *); // edx
  _SERVICE_STATUS *v44; // eax
  GASValue *v45; // eax
  int v46; // edi
  bool v47; // zf
  struct GASObject *v48; // edi
  const char *v49; // [esp-10h] [ebp-60h]
  const char *v50; // [esp-Ch] [ebp-5Ch]
  GMemoryHeap *v52; // [esp+0h] [ebp-50h]
  const char *v53; // [esp+4h] [ebp-4Ch]
  _SYSTEM_AUDIT_CALLBACK_ACE v54; // [esp+8h] [ebp-48h] BYREF
  int v55; // [esp+14h] [ebp-3Ch]
  int v56; // [esp+18h] [ebp-38h]
  int v57; // [esp+1Ch] [ebp-34h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *thisVal; // [esp+20h] [ebp-30h] BYREF
  char v59; // [esp+30h] [ebp-20h] BYREF
  int v60; // [esp+34h] [ebp-1Ch] BYREF
  int v61; // [esp+38h] [ebp-18h]
  char v62; // [esp+3Ch] [ebp-14h]
  int v63; // [esp+40h] [ebp-10h] BYREF
  int v64; // [esp+44h] [ebp-Ch]
  CBitWrite *v65; // [esp+48h] [ebp-8h]
  struct GASObject *v66; // [esp+4Ch] [ebp-4h]

  v3 = (GASValue *)rv;
  v14 = *(_DWORD *)(rv + 4) == 0;
  v4 = this;
  v64 = (int)this;
  if ( v14 )
    return false;
  if ( *(_DWORD *)(rv + 16) != 0 )
  {
    v59 = 4;
    v60 = 0;
    GASValue::operator=(v: (tagWNDCLASSW *)&v59);
    GASValue::~GASValue(this: (GASValue *)&v59);
  }
  v6 = *((_DWORD *)v3 + 2);
  if ( v6 != 0 )
  {
    v7 = *(_DWORD *)(v6 + 4) - 1;
    rv = v7;
    if ( v7 >= 0 )
    {
      while ( 1 )
      {
        v8 = **((_DWORD **)v3 + 2);
        v9 = *(_DWORD *)(v8 + 8 * v7 + 4);
        v10 = *(_DWORD *)(v8 + 8 * v7);
        if ( v9 >= 0 )
        {
          if ( v10 == 0 )
            return false;
          v11 = v10 + 120;
        }
        else
        {
          if ( v10 == 0 )
            return false;
          v11 = v10 + 16;
        }
        if ( v11 == 0 )
          return false;
        if ( (*(unsigned __int8 (__thiscall **)(int, GASEnvironment *, GASValue, _DWORD))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: v4,
               a3: *v3,
               a4: *((_DWORD *)v3 + 1)) != 0 )
        {
          if ( *((_DWORD *)v3 + 4) == 0 )
            return true;
          if ( (unsigned int)((*(int (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11) - 2) > 3 )
            GASValue::SetAsObject(this: *((GASValue **)v3 + 4), a2: (struct GASObject *)(v11 - 16));
          else
            GASValue::SetAsCharacter(result: (tagBITMAPCOREHEADER *)(v11 - 120));
          return true;
        }
        if ( --rv < 0 )
          break;
        v7 = rv;
      }
    }
  }
  if ( ((_BYTE)v3[5] & 1) != 0 )
  {
LABEL_73:
    if ( *((_DWORD *)v4 + 29) != 0 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int, GASEnvironment *, GASValue, _DWORD))(*(_DWORD *)(*((_DWORD *)v4 + 29)
                                                                                                  + 120)
                                                                                      + 44))(
             a1: *((_DWORD *)v4 + 29) + 120,
             a2: v4 + 30,
             a3: *v3,
             a4: *((_DWORD *)v3 + 1)) != 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          GASValue::GASValue(result: *((tagAXISINFOA **)v4 + 29));
          GASValue::operator=(v: (tagWNDCLASSW *)&thisVal);
LABEL_86:
          GASValue::~GASValue(this: &thisVal);
          return true;
        }
        return true;
      }
      v48 = *(struct GASObject **)(*((_DWORD *)v4 + 30) + 680);
      if ( ((_BYTE)v3[5] & 2) == 0 && GASString::GetLength(this: *(GASString **)v3) != 0 && ****(_BYTE ****)v3 == 95 )
      {
        GASEnvironment::CheckGlobalAndLevels(
          this: (__vc_attributes::satypeAttribute *)v4,
          a2: (_BYTE *)&rv + 3,
          a3: (GASValue **)v3);
        if ( HIBYTE(rv) != 0 )
          return HIBYTE(rv) == 1;
      }
      if ( v48 != nullptr
        && ((unsigned __int8 (__thiscall *)(struct GASObject *, GASEnvironment *, GASValue, _DWORD))v48[2].pNode[2].pNext)(
             a1: &v48[2],
             a2: v4,
             a3: *v3,
             a4: *((_DWORD *)v3 + 1)) != 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          GASValue::GASValue(this: &thisVal, a2: v48);
          GASValue::operator=(v: (tagWNDCLASSW *)&thisVal);
          goto LABEL_86;
        }
        return true;
      }
      if ( ((_BYTE)v3[5] & 4) == 0 )
        CDummyMaterialSystem::EndBatch();
    }
    return false;
  }
  v12 = *((_DWORD *)v3 + 1);
  Local = (tagWNDCLASSW *)GASEnvironment::FindLocal(this: v4, key: *(_IMAGE_SYMBOL_EX **)v3);
  v14 = Local == nullptr;
  if ( Local != nullptr )
  {
    if ( v12 != 0 )
    {
      GASValue::operator=(v: Local);
      return true;
    }
    v14 = Local == nullptr;
  }
  if ( !v14 )
    return true;
  v15 = *((_BYTE *)v4 + 124);
  if ( v15 < 5u )
    goto LABEL_66;
  v16 = (GASValue *)*v3;
  v17 = (int)(v4 + 30);
  v18 = (CBitWrite *)(*((_DWORD *)v4 + 30) + 280);
  rv = (int)*v3;
  v65 = v18;
  if ( v15 <= 6u )
  {
    if ( (*v16)->m_nAllocationCount == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      v16 = (GASValue *)rv;
      v18 = v65;
    }
    v19 = *((_DWORD *)v18->m_pDebugName + 1) == (*v16)->m_nAllocationCount;
  }
  else
  {
    v19 = v18->m_pDebugName == (const char *)*v16;
  }
  if ( !v19 )
  {
    v36 = *((_BYTE *)v4 + 124);
    if ( v36 >= 6u )
    {
      v37 = (GASValue *)*v3;
      LOBYTE(rv) = v36 > 6u;
      if ( GASString::CompareBuiltIn_CaseCheck(
             this: (GASString *)(*(_DWORD *)v17 + 256),
             str: (_IMAGE_SYMBOL_EX *)v37,
             a3: v36 > 6u) )
      {
        GASEnvironment::GetTopLocalFrame(this: (__vc_attributes::propputAttribute *)v4, off: 0);
        if ( v38 != 0 )
        {
          v39 = *(_DWORD *)(v38 + 24);
          if ( v39 != 0 )
          {
            v40 = *(_SYSTEM_AUDIT_CALLBACK_ACE **)(v39 + 8);
            rv = (int)v40;
            if ( v40 != nullptr )
            {
              v40->SidStart = (v40->SidStart + 1) & 0x8FFFFFFF;
              v41 = *((_DWORD *)v3 + 2);
              v54.Header = (_ACE_HEADER)(*(_DWORD *)v17 + 252);
              v54.Mask = (unsigned int)&thisVal;
              v54.SidStart = v41;
              LOBYTE(thisVal) = 0;
              v55 = 0;
              v56 = 0;
              v57 = 0;
              GASEnvironment::FindAndGetVariableRaw(this: v4, rv: &v54);
              (*(void (__thiscall **)(int, int *, GASEnvironment *))(*(_DWORD *)(rv + 16) + 56))(
                a1: rv + 16,
                a2: &v60,
                a3: v4 + 30);
              v42 = *(_DWORD *)(*(_DWORD *)v17 + 656);
              v43 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v42 + 40);
              v63 = 323;
              v65 = (CBitWrite *)v43(a1: v42, a2: 76, a3: &v63);
              if ( v65 != nullptr )
              {
                v64 = *(_DWORD *)(rv + 24);
                v44 = GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)v4);
                v66 = (struct GASObject *)GASSuperObject::GASSuperObject(
                                            this: v65,
                                            a2: v64,
                                            _this: (int)v44,
                                            _this_4: &v60);
              }
              else
              {
                v66 = nullptr;
              }
              GASValue::SetAsObject(this: *((GASValue **)v3 + 1), a2: v66);
              GASEnvironment::SetLocal(
                this: v4,
                varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)v17 + 256),
                val: *((tagWNDCLASSW **)v3 + 1));
              if ( (v62 & 2) == 0 && v60 != 0 )
                GRefCountBaseGC<323>::Release(a1: v60, a2: v17);
              v60 = 0;
              if ( (v62 & 1) == 0 && v61 != 0 )
                GRefCountBaseGC<323>::Release(a1: v61, a2: v17);
              v61 = 0;
              GASValue::~GASValue(this: &thisVal);
              GRefCountBaseGC<323>::Release(a1: rv, a2: v17);
              if ( v66 != nullptr )
              {
                GRefCountBaseGC<323>::Release(a1: (int)v66, a2: v17);
                return true;
              }
              return true;
            }
          }
        }
      }
    }
    goto LABEL_66;
  }
  v20 = *((_DWORD *)v4 + 51);
  if ( v20 == 0 || (v21 = *(_DWORD *)(*((_DWORD *)v4 + 50) + 4 * v20 - 4)) == 0 )
  {
LABEL_66:
    v24 = *((_BYTE *)v4 + 124) <= 6u;
    v45 = (GASValue *)*v3;
    v46 = *((_DWORD *)v4 + 30);
    rv = (int)*v3;
    if ( v24 )
    {
      if ( (*v45)->m_nAllocationCount == 0 )
      {
        GASStringNode::ResolveLowercase_Impl();
        v45 = (GASValue *)rv;
      }
      v47 = *(_DWORD *)(*(_DWORD *)(v46 + 252) + 4) == (*v45)->m_nAllocationCount;
    }
    else
    {
      v47 = *(GASValue *)(v46 + 252) == *v45;
    }
    if ( v47 )
    {
      GASValue::SetAsCharacter(result: *((tagBITMAPCOREHEADER **)v4 + 29));
      return true;
    }
    goto LABEL_73;
  }
  v22 = *(_DWORD *)(*((_DWORD *)v4 + 30) + 656);
  v23 = *(int (__thiscall **)(int, int, int *, int))(*(_DWORD *)v22 + 40);
  rv = 323;
  if ( v23(a1: v22, a2: 76, a3: &rv, a4: a2) != 0 )
    v66 = (struct GASObject *)GASArrayObject::GASArrayObject(
                                penv: (unsigned int)v4,
                                a2: v52,
                                a3: v53,
                                a4: *(_DWORD *)&v54.Header);
  else
    v66 = nullptr;
  GASArrayObject::Resize(size: *(void **)(v21 + 32), a2: v52);
  v24 = *(_DWORD *)(v21 + 32) <= 0;
  rv = 0;
  if ( !v24 )
  {
    do
    {
      v25 = *(_DWORD **)(v21 + 28);
      v26 = *(_DWORD *)(v21 + 36) - rv;
      v27 = 32 * (v25[7] - 1) + ((v25[2] - v25[3]) >> 4);
      v65 = nullptr;
      if ( v26 > v27 )
        v28 = v65;
      else
        v28 = (CBitWrite *)(*(_DWORD *)(v25[6] + 4 * (v26 >> 5)) + 16 * (v26 & 0x1F));
      v29 = (GASValue *)rv;
      GASArrayObject::SetElement(this: (GASArrayObject *)v66, a2: rv, a3: (const struct GASValue *)v28);
      rv = (int)v29 + 1;
    }
    while ( (int)v29 + 1 < *(_DWORD *)(v21 + 32) );
    v4 = (GASEnvironment *)v64;
  }
  v65 = (CBitWrite *)(v4 + 30);
  v64 = *((_DWORD *)v4 + 30) + 280;
  v30 = (_SYSTEM_AUDIT_CALLBACK_ACE *)GASValue::GASValue(this: &thisVal, a2: v66);
  v31 = *((_DWORD *)v4 + 50);
  rv = (int)v30;
  v32 = v31 + 4 * *((_DWORD *)v4 + 51) - 4;
  if ( *(_DWORD *)v32 != 0 )
    *(_DWORD *)(*(_DWORD *)v32 + 8) = (*(_DWORD *)(*(_DWORD *)v32 + 8) + 1) & 0x8FFFFFFF;
  v63 = *(_DWORD *)v32;
  if ( v63 != 0 )
  {
    GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::SetCaseCheck(
      a1: v64,
      v: (tagWNDCLASSW *)rv,
      a3: *((_BYTE *)v4 + 124) > 6u);
    GRefCountBaseGC<323>::Release(a1: v63, a2: v21);
  }
  GASValue::~GASValue(this: &thisVal);
  v33 = v66;
  pNext = v66[2].pNode[5].pNext;
  v50 = v65->m_pDebugName + 284;
  HIBYTE(rv) = 7;
  ((void (__thiscall *)(struct GASObject *, CBitWrite *, const char *, int))pNext)(
    a1: &v66[2],
    a2: v65,
    a3: v50,
    a4: v21 + 40);
  v35 = v33[2].pNode[5].pNext;
  v49 = v65->m_pDebugName + 288;
  HIBYTE(rv) = 7;
  ((void (__thiscall *)(struct GASObject *, CBitWrite *, const char *, int, char *))v35)(
    a1: &v33[2],
    a2: v65,
    a3: v49,
    a4: v21 + 56,
    a5: (char *)&rv + 3);
  GASValue::SetAsObject(this: *((GASValue **)v3 + 1), a2: v33);
  GRefCountBaseGC<323>::Release(a1: (int)v33, a2: (int)v33);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1009E300
// Name: public: bool GASEnvironment::FindVariable(struct GASEnvironment::GetVarParams const __near &,bool,class GASString __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASEnvironment::FindVariable(
        tagBITMAPCOREHEADER **this,
        const struct GASEnvironment::GetVarParams *a2,
        bool onlyTargets,
        struct GASString *varName)
{
  int *v4; // eax
  GASValue *v6; // ebx
  int v7; // eax
  ScaleformFileOpener *v8; // esi
  int v9; // edi
  _DWORD *v10; // eax
  tagBITMAPCOREHEADER *v11; // eax
  int v12; // ecx
  int v13; // edi
  tagBITMAPCOREHEADER *v14; // eax
  const struct GASEnvironment::GetVarParams *v15; // ebx
  char *v16; // esi
  int v17; // ecx
  struct GASString *v18; // eax
  char v19; // al
  char VariableRaw; // bl
  bool v21; // zf
  int v22; // ecx
  int *v23; // eax
  int v24; // ecx
  int v25; // eax
  tagBITMAPCOREHEADER *v26; // eax
  struct GFxASCharacter *v27; // eax
  tagBITMAPCOREHEADER *v28; // eax
  unsigned int v29; // eax
  tagWNDCLASSW *v30; // eax
  _SERVICE_STATUS *v31; // eax
  struct GASObjectInterface *v32; // eax
  _BYTE *v33; // esi
  _DWORD *v34; // eax
  int v35; // esi
  char *v36; // esi
  char v37; // al
  _SYSTEM_AUDIT_CALLBACK_ACE rv; // [esp+4h] [ebp-64h] BYREF
  int v39; // [esp+10h] [ebp-58h]
  int v40; // [esp+14h] [ebp-54h]
  int v41; // [esp+18h] [ebp-50h]
  __vc_attributes::idl_quoteAttribute v42; // [esp+1Ch] [ebp-4Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *member; // [esp+2Ch] [ebp-3Ch] BYREF
  GPtr<ScaleformFileOpener> v44; // [esp+3Ch] [ebp-2Ch] BYREF
  char *v45; // [esp+40h] [ebp-28h]
  const char *v46; // [esp+44h] [ebp-24h]
  int v47; // [esp+48h] [ebp-20h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *current; // [esp+4Ch] [ebp-1Ch] BYREF
  tagBITMAPCOREHEADER **first_token; // [esp+5Ch] [ebp-Ch]
  char *v50; // [esp+60h] [ebp-8h]
  char sep; // [esp+66h] [ebp-2h] BYREF
  bool currentFound; // [esp+67h] [ebp-1h]

  v4 = *(int **)a2;
  v21 = *(_DWORD *)(**(_DWORD **)a2 + 16) == 0;
  first_token = this;
  if ( v21 )
  {
    if ( *(_DWORD *)&a2[4] != 0 )
      GASValue::SetAsCharacter(result: *(this + 29));
    return 1;
  }
  v6 = *(GASValue **)&a2[16];
  LOBYTE(current) = 0;
  v7 = *v4;
  v8 = *(ScaleformFileOpener **)v7;
  v9 = *(_DWORD *)(v7 + 16);
  currentFound = false;
  v50 = ":./";
  if ( v6 != nullptr )
  {
    GASValue::DropRefs(this: v6);
    *(_BYTE *)v6 = 0;
  }
  v10 = *(_DWORD **)&a2[12];
  if ( v10 != nullptr )
    *v10 = 0;
  if ( LOBYTE(v8->__vftable) == 47 )
  {
    v11 = (tagBITMAPCOREHEADER *)(*(int (__thiscall **)(tagBITMAPCOREHEADER *, _DWORD))(first_token[29]->bcSize + 104))(
                                   a1: first_token[29],
                                   a2: 0);
    GASValue::SetAsCharacter(result: v11);
    v50 = onlySlashesDelim;
    v12 = *(_DWORD *)&a2[16];
    v8 = (ScaleformFileOpener *)((char *)v8 + 1);
    --v9;
    currentFound = true;
    if ( v12 != 0 )
      GASValue::operator=(v: (tagWNDCLASSW *)&current);
  }
  else if ( LOBYTE(v8->__vftable) == 46 )
  {
    v50 = onlySlashesDelim;
  }
  v45 = (char *)v8 + v9;
  v13 = (int)first_token;
  v14 = first_token[30];
  v44.pObject = v8;
  v46 = v50;
  v47 = *(_DWORD *)&v14->bcPlanes;
  ++*(_DWORD *)(v47 + 8);
  sep = 0;
  LOBYTE(first_token) = 1;
  v15 = a2;
  if ( StringTokenizer::NextToken(this: &v44, (ScaleformFileOpener *)&sep) != 0 )
  {
    v16 = ":./";
    while ( 1 )
    {
      v17 = v47;
      if ( *(_DWORD *)(v47 + 16) == 0 )
        goto LABEL_74;
      v18 = varName;
      if ( varName != nullptr )
      {
        ++*(_DWORD *)(v47 + 8);
        v16 = (char *)v17;
        v21 = (*(_DWORD *)(*(_DWORD *)varName + 8))-- == 1;
        if ( v21 )
        {
          GASStringNode::ReleaseNode();
          v18 = varName;
        }
        v17 = v47;
        *(_DWORD *)v18 = v16;
      }
      v19 = (char)current;
      VariableRaw = 0;
      LOBYTE(member) = 0;
      if ( (_BYTE)current == 7 )
      {
        if ( currentFound )
          goto LABEL_47;
      }
      else
      {
        if ( currentFound )
          goto LABEL_53;
        v16 = *(char **)(v13 + 120);
        if ( *((_DWORD *)v16 + 52) != v17 )
        {
          if ( *(_BYTE *)(v13 + 124) <= 6u )
          {
            if ( *(_DWORD *)(v17 + 4) == 0 )
            {
              GASStringNode::ResolveLowercase_Impl();
              v19 = (char)current;
              v17 = v47;
            }
            v21 = *(_DWORD *)(*((_DWORD *)v16 + 67) + 4) == *(_DWORD *)(v17 + 4);
          }
          else
          {
            v21 = *((_DWORD *)v16 + 67) == v17;
          }
          if ( !v21 )
            goto LABEL_51;
        }
      }
      v22 = *(_DWORD *)&a2[8];
      if ( v22 != 0 && *(_DWORD *)(v22 + 4) != 0 )
        break;
LABEL_43:
      if ( v19 == 0 || v19 == 10 )
        GASValue::SetAsCharacter(result: *(tagBITMAPCOREHEADER **)(v13 + 116));
      currentFound = true;
LABEL_47:
      v27 = GASValue::ToASCharacter(this: &current, a2: (const struct GASEnvironment *)v13);
      if ( v27 == nullptr
        || (v28 = (tagBITMAPCOREHEADER *)(*(int (__thiscall **)(struct GFxASCharacter *, int *, tagBITMAPCOREHEADER **))(*(_DWORD *)v27 + 268))(
                                           a1: v27,
                                           a2: &v47,
                                           a3: first_token)) == nullptr )
      {
        if ( currentFound )
        {
          v19 = (char)current;
LABEL_53:
          if ( v19 == 3 || v19 == 4 || v19 == 2 || v19 == 5 )
          {
            v30 = (tagWNDCLASSW *)GASEnvironment::PrimitiveToTempObject(
                                    a1: v13,
                                    a2: v16,
                                    result: &v42,
                                    v: (const struct GASValue *)&current);
            GASValue::operator=(v: v30);
            GASValue::~GASValue(this: (GASValue *)&v42);
            v19 = (char)current;
          }
          if ( v19 != 6 && v19 != 7 && v19 != 8 && v19 != 11
            || (v31 = GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)v13)) != nullptr
            && (VariableRaw = (*(int (__thiscall **)(_SERVICE_STATUS *, int, int *, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(v31->dwServiceType + 16))(
                                a1: v31,
                                a2: v13,
                                a3: &v47,
                                a4: &member)) == 0 )
          {
            GASValue::DropRefs(this: &member);
            VariableRaw = 0;
            LOBYTE(member) = 0;
          }
          goto LABEL_65;
        }
LABEL_51:
        rv.Header = (_ACE_HEADER)&v47;
        v29 = *(_DWORD *)&a2[8];
        rv.Mask = (unsigned int)&member;
        rv.SidStart = v29;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        VariableRaw = GASEnvironment::GetVariableRaw(this: (GASEnvironment *)v13, a2: v13, (int)&rv);
        goto LABEL_65;
      }
      GASValue::SetAsCharacter(result: v28);
      VariableRaw = 1;
LABEL_65:
      if ( *(_DWORD *)&a2[16] != 0 )
        GASValue::operator=(v: (tagWNDCLASSW *)&current);
      if ( onlyTargets && (_BYTE)member != 7 || VariableRaw == 0 )
      {
        GASValue::DropRefs(this: &current);
        LOBYTE(current) = 0;
        currentFound = false;
        if ( StringTokenizer::NextToken(this: &v44, (ScaleformFileOpener *)&sep) != 0 )
        {
          v33 = *(_BYTE **)&a2[16];
          if ( v33 != nullptr )
          {
            GASValue::DropRefs(this: *(GASValue **)&a2[16]);
            *v33 = 0;
          }
          v34 = *(_DWORD **)&a2[12];
          if ( v34 != nullptr )
            *v34 = 0;
          if ( varName != nullptr )
          {
            v35 = *(_DWORD *)(*(_DWORD *)(v13 + 120) + 8);
            ++*(_DWORD *)(v35 + 8);
            v21 = (*(_DWORD *)(*(_DWORD *)varName + 8))-- == 1;
            if ( v21 )
              GASStringNode::ReleaseNode();
            *(_DWORD *)varName = v35;
          }
        }
        GASValue::~GASValue(this: &member);
        v15 = a2;
        goto LABEL_97;
      }
      if ( (_BYTE)member == 9 )
      {
        v32 = (struct GASObjectInterface *)GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)v13);
        GASValue::GetPropertyValue(
          this: &member,
          a2: (struct GASEnvironment *)v13,
          a3: v32,
          a4: (struct GASValue *)&current);
      }
      else
      {
        GASValue::operator=(v: (tagWNDCLASSW *)&member);
      }
      currentFound = VariableRaw;
      GASValue::~GASValue(this: &member);
      v15 = a2;
      v16 = ":./";
LABEL_74:
      if ( v50 == onlySlashesDelim )
      {
        if ( sep != 58 )
          goto LABEL_83;
        v21 = *(_DWORD *)&v15[12] == 0;
        v46 = ":./";
        v50 = ":./";
        if ( !v21 && (_BYTE)current == 7 )
          goto LABEL_78;
      }
      else
      {
        if ( sep != 46 )
        {
LABEL_83:
          if ( sep == 47 )
          {
            v46 = onlySlashesDelim;
            v50 = onlySlashesDelim;
          }
          goto LABEL_85;
        }
        if ( *(_DWORD *)&v15[12] != 0 && (_BYTE)current == 7 )
LABEL_78:
          **(_DWORD **)&v15[12] = GASValue::ToASCharacter(this: &current, a2: (const struct GASEnvironment *)v13);
      }
LABEL_85:
      LOBYTE(first_token) = 0;
      if ( StringTokenizer::NextToken(this: &v44, (ScaleformFileOpener *)&sep) == 0 )
        goto LABEL_97;
    }
    v23 = (int *)(**(_DWORD **)&a2[8] + 8 * *(_DWORD *)(*(_DWORD *)&a2[8] + 4) - 8);
    v24 = v23[1];
    v25 = *v23;
    if ( v24 >= 0 )
    {
      if ( v25 != 0 )
      {
        v16 = (char *)(v25 + 120);
        goto LABEL_40;
      }
    }
    else if ( v25 != 0 )
    {
      v16 = (char *)(v25 + 16);
LABEL_40:
      if ( (unsigned int)((*(int (__thiscall **)(char *))(*(_DWORD *)v16 + 8))(a1: v16) - 2) <= 3 )
      {
        v26 = (tagBITMAPCOREHEADER *)GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)v16);
        GASValue::SetAsCharacter(result: v26);
      }
      v19 = (char)current;
      goto LABEL_43;
    }
    v16 = nullptr;
    goto LABEL_40;
  }
LABEL_97:
  if ( *(_DWORD *)&v15[12] != 0 && (_BYTE)current == 7 )
    **(_DWORD **)&v15[12] = GASValue::ToASCharacter(this: &current, a2: (const struct GASEnvironment *)v13);
  v36 = *(char **)&v15[16];
  if ( v36 != nullptr )
  {
    v37 = *v36;
    if ( *v36 != 6 && v37 != 7 && v37 != 8 && v37 != 11 )
    {
      GASValue::DropRefs(this: *(GASValue **)&v15[16]);
      *v36 = 0;
    }
  }
  if ( currentFound )
  {
    if ( *(_DWORD *)&v15[4] != 0 )
      GASValue::operator=(v: (tagWNDCLASSW *)&current);
    v21 = (*(_DWORD *)(v47 + 8))-- == 1;
    if ( v21 )
      GASStringNode::ReleaseNode();
    GASValue::~GASValue(this: &current);
    return 1;
  }
  else
  {
    v21 = (*(_DWORD *)(v47 + 8))-- == 1;
    if ( v21 )
      GASStringNode::ReleaseNode();
    GASValue::~GASValue(this: &current);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E7D0
// Name: public: void GASGlobalContext::UnregisterAllClasses(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::UnregisterAllClasses(GASGlobalContext *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1009E7E0
// Name: public: bool GASEnvironment::GetVariable(class GASString const __near &,class GASValue __near *,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *,class GFxASCharacter __near * __near *,class GASValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::GetVariable(
        __vc_attributes::max_isAttribute *this,
        _IMAGE_SYMBOL_EX *varname,
        GASValue *a3,
        unsigned int retVal,
        GStat::StatValue *paschar,
        GRefCountNTSImpl *a6,
        int a7)
{
  struct GASObjectInterface *v8; // ebx
  _ACE_HEADER v9; // edx
  struct GFxASCharacter *v10; // eax
  GRefCountNTSImpl *v11; // esi
  struct GASObject *v12; // eax
  struct GASObjectInterface *v13; // eax
  char v14; // al
  struct GFxASCharacter *v15; // eax
  struct GASObject *v16; // eax
  GRefCountNTSImpl *v17; // eax
  GASValue **v18; // esi
  GASValue *v19; // ecx
  unsigned int Short; // eax
  GStat::StatValue *v21; // ecx
  int v22; // eax
  const char *v23; // [esp-18h] [ebp-A4h]
  const char *v24; // [esp+0h] [ebp-8Ch]
  _DWORD v25[3]; // [esp+Ch] [ebp-80h] BYREF
  int v26; // [esp+18h] [ebp-74h]
  int v27; // [esp+1Ch] [ebp-70h]
  char v28; // [esp+20h] [ebp-6Ch]
  __vc_attributes::max_isAttribute *v29; // [esp+24h] [ebp-68h]
  int v30; // [esp+28h] [ebp-64h]
  int v31; // [esp+2Ch] [ebp-60h]
  _SYSTEM_AUDIT_CALLBACK_ACE rv; // [esp+30h] [ebp-5Ch] BYREF
  int v33; // [esp+3Ch] [ebp-50h]
  int v34; // [esp+40h] [ebp-4Ch]
  int v35; // [esp+44h] [ebp-48h]
  _SYSTEM_AUDIT_CALLBACK_ACE v36; // [esp+48h] [ebp-44h] BYREF
  GStat::StatValue *v37; // [esp+54h] [ebp-38h]
  GRefCountNTSImpl *v38; // [esp+58h] [ebp-34h]
  int v39; // [esp+5Ch] [ebp-30h]
  GASValue v40[4]; // [esp+60h] [ebp-2Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *thisVal; // [esp+70h] [ebp-1Ch] BYREF
  int v42; // [esp+80h] [ebp-Ch] BYREF
  int v43; // [esp+84h] [ebp-8h]
  char v44; // [esp+88h] [ebp-4h]
  GStat::StatValue *paschara; // [esp+A0h] [ebp+14h]
  GRefCountNTSImpl *v46; // [esp+A4h] [ebp+18h]

  v37 = paschar;
  v36.Header = (_ACE_HEADER)varname;
  v36.Mask = (unsigned int)a3;
  v36.SidStart = retVal;
  v38 = a6;
  v39 = a7;
  if ( GASEnvironment::FindAndGetVariableRaw((GASEnvironment *)this, rv: &v36) && *(_BYTE *)a3 == 9 )
  {
    v8 = nullptr;
    v9 = (_ACE_HEADER)(*((_DWORD *)this + 30) + 252);
    LOBYTE(thisVal) = 0;
    rv.Header = v9;
    rv.Mask = (unsigned int)&thisVal;
    rv.SidStart = retVal;
    v33 = 0;
    v34 = 0;
    v35 = 0;
    if ( GASEnvironment::GetVariableRaw((GASEnvironment *)this, a2: (int)this, (int)&rv) )
    {
      v10 = GASValue::ToASCharacter(this: &thisVal, a2: (const struct GASEnvironment *)this);
      if ( v10 != nullptr )
        ++*((_DWORD *)v10 + 1);
      v11 = (GRefCountNTSImpl *)v10;
      if ( v10 != nullptr )
        goto LABEL_13;
      v12 = GASValue::ToObject(this: &thisVal, a2: (const struct GASEnvironment *)this);
      if ( v12 != nullptr )
        v8 = (struct GASObjectInterface *)&v12[2];
      else
        v8 = nullptr;
    }
    else
    {
      v11 = *((GRefCountNTSImpl **)this + 29);
      if ( v11 == nullptr )
        goto LABEL_14;
      ++v11->RefCount;
    }
    if ( v11 != nullptr )
    {
LABEL_13:
      v13 = (struct GASObjectInterface *)&v11[15];
      goto LABEL_15;
    }
LABEL_14:
    v13 = v8;
LABEL_15:
    GASValue::GetPropertyValue(this: a3, a2: (struct GASEnvironment *)this, a3: v13, a4: (struct GASValue *)a3);
    GASValue::~GASValue(this: &thisVal);
    if ( v11 != nullptr )
      GRefCountNTSImpl::Release(this: v11);
    return;
  }
  if ( *(_BYTE *)a3 == 12 )
  {
    v23 = (const char *)(*((_DWORD *)this + 30) + 252);
    paschara = nullptr;
    LOBYTE(v40[0]) = 0;
    GASEnvironment::GetVariable(this, varname: v23);
    if ( v14 != 0 )
    {
      v15 = GASValue::ToASCharacter(this: v40, a2: (const struct GASEnvironment *)this);
      if ( v15 != nullptr )
        ++*((_DWORD *)v15 + 1);
      v46 = (GRefCountNTSImpl *)v15;
      if ( v15 == nullptr )
      {
        v16 = GASValue::ToObject(this: v40, a2: (const struct GASEnvironment *)this);
        if ( v16 != nullptr )
          paschara = (GStat::StatValue *)&v16[2];
        else
          paschara = nullptr;
      }
    }
    else
    {
      v17 = *((GRefCountNTSImpl **)this + 29);
      if ( v17 != nullptr )
        ++v17->RefCount;
      v46 = v17;
    }
    GASValue::ToResolveHandler(a1: a3, a2: &v42);
    *((_DWORD *)this + 2) += 16;
    v18 = (GASValue **)(this + 2);
    if ( *((_DWORD *)this + 2) >= *((_DWORD *)this + 4) )
      GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)this + 2, a2: v24);
    v19 = *v18;
    if ( *v18 != nullptr )
    {
      *(_BYTE *)v19 = 5;
      Short = varname->N.Name.Short;
      v19[1] = (GASValue)varname->N.Name.Short;
      ++*(_DWORD *)(Short + 8);
    }
    GASValue::DropRefs(this: a3);
    *(_BYTE *)a3 = 0;
    if ( v46 != nullptr )
      v21 = (GStat::StatValue *)&v46[15];
    else
      v21 = paschara;
    v22 = ((*((_DWORD *)this + 2) - *((_DWORD *)this + 3)) >> 4) + 32 * *((_DWORD *)this + 7) - 32;
    v25[1] = a3;
    v26 = 0;
    v27 = 0;
    v25[2] = v21;
    v31 = v22;
    v25[0] = &GASFnCall::`vftable';
    v28 = 0;
    v29 = this;
    v30 = 1;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v42 + 40))(a1: v42, a2: v25, a3: v43, a4: 0);
    v25[0] = &GASFnCall::`vftable';
    if ( (v28 & 2) == 0 && v26 != 0 )
      GRefCountBaseGC<323>::Release(a1: v26, a2: 0);
    v26 = 0;
    if ( (v28 & 1) == 0 && v27 != 0 )
      GRefCountBaseGC<323>::Release(a1: v27, a2: 0);
    GASValue::~GASValue(this: *v18);
    *v18 -= 4;
    if ( *((_DWORD *)this + 2) < *((_DWORD *)this + 3) )
      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v18, a2: v24);
    if ( (v44 & 2) == 0 && v42 != 0 )
      GRefCountBaseGC<323>::Release(a1: v42, a2: 0);
    v42 = 0;
    if ( (v44 & 1) == 0 && v43 != 0 )
      GRefCountBaseGC<323>::Release(a1: v43, a2: 0);
    v43 = 0;
    GASValue::~GASValue(this: v40);
    if ( v46 != nullptr )
      GRefCountNTSImpl::Release(this: v46);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EA80
// Name: public: bool GASEnvironment::SetVariable(class GASString const __near &,class GASValue const __near &,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall GASEnvironment::SetVariable(
        __vc_attributes::propgetAttribute *this,
        _IMAGE_SYMBOL_EX *varname,
        tagWNDCLASSW *val,
        unsigned __int8 *doDisplayErrors,
        int a5)
{
  int v6; // eax
  _IMAGE_SYMBOL_EX *v7; // edi
  GASValue *v8; // eax
  bool v9; // zf
  int v10; // eax
  unsigned __int8 *v11; // edx
  _SERVICE_STATUS *v12; // eax
  void (__thiscall *v13)(_SERVICE_STATUS *, __vc_attributes::propgetAttribute *, _IMAGE_SYMBOL_EX **, tagWNDCLASSW *, char *); // edx
  CUtlInplaceBuffer v14; // [esp-4h] [ebp-44h] OVERLAPPED BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *owner; // [esp+30h] [ebp-10h] BYREF

  v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 29) + 84))(a1: *((_DWORD *)this + 29));
  v7 = varname;
  if ( (*(_DWORD *)(v6 + 9332) & 4) != 0 )
  {
    v8 = GASValue::GASValue(this: (GASValue *)&v14.m_GetOverflowFunc, a2: (const struct GASValue *)val);
    GASValue::ToDebugString(a1: v8, a2: &varname, a3: this);
    GASValue::~GASValue(this: (GASValue *)&v14.m_GetOverflowFunc);
    v14.m_Memory.m_pMemory = (unsigned __int8 *)varname->N.Name.Short;
    CDummyMaterialSystem::EndBatch();
    v9 = varname->Value-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
  }
  if ( (*(_DWORD *)(v7->N.Name.Short + 12) & 0x2000000) == 0 && GASEnvironment::IsPath(varPath: v7) != 0 )
  {
    v10 = *((_DWORD *)this + 30);
    v11 = doDisplayErrors;
    v14.m_Put = (int)&v14.m_GetOverflowFunc;
    LOBYTE(owner) = 0;
    varname = *(_IMAGE_SYMBOL_EX **)(v10 + 8);
    ++varname->Value;
    *(_DWORD *)&v14.m_Error = v11;
    LOBYTE(v14.m_GetOverflowFunc) = 0;
    v14.m_Get = (int)v7;
    v14.m_nTab = 0;
    v14.m_nMaxPut = (int)&owner;
    v14.m_nOffset = 0;
    GASEnvironment::FindVariable(
      (tagBITMAPCOREHEADER **)this,
      a2: (const struct GASEnvironment::GetVarParams *)&v14.m_Get,
      onlyTargets: false,
      varName: (struct GASString *)&varname);
    if ( (_BYTE)owner == 0 || (_BYTE)owner == 10 )
    {
      if ( (_BYTE)a5 != 0
        && (*(unsigned __int8 (__thiscall **)(__vc_attributes::propgetAttribute *))(*(_DWORD *)this + 4))(a1: this) != 0 )
      {
        GASEnvironment::LogScriptError(
          (GASEnvironment *)this,
          a2: "Error: SetVariable failed: can't resolve the path \"%s\"\n",
          *(const char **)v7->N.Name.Short);
      }
    }
    else
    {
      v12 = GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)this);
      if ( v12 != nullptr )
      {
        v13 = *(void (__thiscall **)(_SERVICE_STATUS *, __vc_attributes::propgetAttribute *, _IMAGE_SYMBOL_EX **, tagWNDCLASSW *, char *))(v12->dwServiceType + 12);
        HIBYTE(a5) = 0;
        v13(a1: v12, a2: this, a3: &varname, a4: val, a5: (char *)&a5 + 3);
        GASValue::~GASValue(this: (GASValue *)&v14.m_GetOverflowFunc);
        v9 = varname->Value-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
LABEL_11:
        GASValue::~GASValue(this: &owner);
        return;
      }
    }
    GASValue::~GASValue(this: (GASValue *)&v14.m_GetOverflowFunc);
    v9 = varname->Value-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
    goto LABEL_11;
  }
  v14.m_Memory.m_pMemory = doDisplayErrors;
  GASEnvironment::SetVariableRaw(a1: (int)this, varname: v7, val, pwithStack: v14);
}

//------------------------------------------------------------------------------
// Address: 0x1009EC20
// Name: bool GAS_InvokeParsed(char const __near *,class GASValue __near *,class GASObjectInterface __near *,class GASEnvironment __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GAS_InvokeParsed(
        const char *varname,
        struct GASValue *a2,
        struct GASObjectInterface *args,
        __vc_attributes::max_isAttribute *a4,
        const char *a5,
        char *a6)
{
  const char *v6; // edi
  __vc_attributes::max_isAttribute *v7; // esi
  const char *expression; // eax
  int v9; // eax
  char v10; // al
  bool v11; // bl
  GASObjectInterface *v13; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v14; // eax
  int v15; // eax
  GASObjectInterface *v16; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v17; // eax
  int v18; // eax
  char *v20; // eax
  char v21; // bl
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *method; // [esp+4h] [ebp-30h] BYREF
  GASValue owner[4]; // [esp+14h] [ebp-20h] BYREF
  int v24; // [esp+24h] [ebp-10h] BYREF
  int v25; // [esp+28h] [ebp-Ch]
  char v26; // [esp+2Ch] [ebp-8h]
  int v27; // [esp+30h] [ebp-4h] BYREF

  v6 = varname;
  if ( varname == nullptr || *varname == 0 )
    return 0;
  v7 = a4;
  expression = a4[30].expression;
  v27 = 0;
  LOBYTE(method) = 0;
  LOBYTE(owner[0]) = 0;
  GASStringManager::CreateStringNode(this: *((const char **)expression + 159));
  varname = (const char *)v9;
  ++*(_DWORD *)(v9 + 8);
  GASEnvironment::GetVariable(
    this: v7,
    (_IMAGE_SYMBOL_EX *)&varname,
    a3: &method,
    retVal: 0,
    paschar: (GStat::StatValue *)&v27,
    a6: (GRefCountNTSImpl *)owner,
    a7: 0);
  v11 = v10 == 0;
  if ( (*((_DWORD *)varname + 2))-- == 1 )
    GASStringNode::ReleaseNode();
  if ( v11 )
  {
    v13 = args;
    if ( args != nullptr
      && (unsigned int)((*(int (__thiscall **)(struct GASObjectInterface *))(*(_DWORD *)args + 8))(a1: args) - 2) <= 3 )
    {
      v14 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v13);
      if ( DWORD1(v14[6].m_pfnProxied) != 0 )
        v15 = DWORD1(v14[6].m_pfnProxied);
      else
        GFxASCharacter::CreateCharacterHandle(this: v14);
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)v7,
        a2: "Error: Can't find method '%s.%s' to invoke.\n",
        **(const char ***)(v15 + 12),
        v6);
    }
    else
    {
      GASEnvironment::LogScriptError(this: (GASEnvironment *)v7, a2: "Error: Can't find method '%s' to invoke.\n", v6);
    }
LABEL_28:
    GASValue::~GASValue(this: owner);
    GASValue::~GASValue(this: &method);
    return 0;
  }
  GASValue::ToFunction(a1: &v24, a2: v7);
  if ( v24 == 0 )
  {
    v16 = args;
    if ( args != nullptr
      && (unsigned int)((*(int (__thiscall **)(struct GASObjectInterface *))(*(_DWORD *)args + 8))(a1: args) - 2) <= 3 )
    {
      v17 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v16);
      if ( DWORD1(v17[6].m_pfnProxied) != 0 )
        v18 = DWORD1(v17[6].m_pfnProxied);
      else
        GFxASCharacter::CreateCharacterHandle(this: v17);
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)v7,
        a2: "Error: Invoked method '%s.%s' is not a function\n",
        **(const char ***)(v18 + 12),
        v6);
    }
    else
    {
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)v7,
        a2: "Error: Invoked method '%s' is not a function\n",
        v6);
    }
    if ( (v26 & 2) == 0 && v24 != 0 )
      GRefCountBaseGC<323>::Release(a1: v24, a2: (int)v6);
    v24 = 0;
    if ( (v26 & 1) == 0 && v25 != 0 )
      GRefCountBaseGC<323>::Release(a1: v25, a2: (int)v6);
    v25 = 0;
    goto LABEL_28;
  }
  if ( LOBYTE(owner[0]) == 7 || LOBYTE(owner[0]) == 6 )
  {
    v20 = (char *)GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)v7);
  }
  else if ( v27 != 0 )
  {
    v20 = (char *)(v27 + 120);
  }
  else
  {
    v20 = (char *)args;
  }
  v21 = GAS_InvokeParsed(
          &method,
          methoda: (tagWNDCLASSW *)&method,
          a3: (GASValue *)a2,
          args: v20,
          a5: (GASEnvironment *)v7,
          a6: a5,
          a7: (int)a6,
          a8: v6);
  if ( (v26 & 2) == 0 && v24 != 0 )
    GRefCountBaseGC<323>::Release(a1: v24, a2: (int)v6);
  v24 = 0;
  if ( (v26 & 1) == 0 && v25 != 0 )
    GRefCountBaseGC<323>::Release(a1: v25, a2: (int)v6);
  v25 = 0;
  GASValue::~GASValue(this: owner);
  GASValue::~GASValue(this: &method);
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x1009EE40
// Name: bool GAS_Invoke(char const __near *,class GASValue __near *,class GASObjectInterface __near *,class GASEnvironment __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GAS_Invoke(_IMAGE_SYMBOL_EX varname, int a2)
{
  const char *Short; // edi
  __vc_attributes::max_isAttribute *SectionNumber; // esi
  int v4; // eax
  unsigned int v5; // eax
  char v6; // al
  bool v7; // bl
  GASObjectInterface *Value; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v10; // eax
  int v11; // eax
  GASObjectInterface *v12; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v13; // eax
  int v14; // eax
  GASObjectInterface *v16; // eax
  char v17; // bl
  tagWNDCLASSW v18; // [esp+4h] [ebp-30h] BYREF
  char v19; // [esp+2Ch] [ebp-8h]
  int v20; // [esp+30h] [ebp-4h] BYREF

  Short = (const char *)varname.N.Name.Short;
  if ( varname.N.Name.Short == 0 || *(_BYTE *)varname.N.Name.Short == 0 )
    return 0;
  SectionNumber = (__vc_attributes::max_isAttribute *)varname.SectionNumber;
  v4 = *(_DWORD *)(varname.SectionNumber + 120);
  v20 = 0;
  LOBYTE(v18.style) = 0;
  LOBYTE(v18.hInstance) = 0;
  GASStringManager::CreateStringNode(this: *(const char **)(v4 + 636));
  varname.N.Name.Short = v5;
  ++*(_DWORD *)(v5 + 8);
  GASEnvironment::GetVariable(
    this: SectionNumber,
    &varname,
    a3: (GASValue *)&v18,
    retVal: 0,
    paschar: (GStat::StatValue *)&v20,
    a6: (GRefCountNTSImpl *)&v18.hInstance,
    a7: 0);
  v7 = v6 == 0;
  if ( (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  if ( v7 )
  {
    Value = (GASObjectInterface *)varname.Value;
    if ( varname.Value != 0
      && (unsigned int)((*(int (__thiscall **)(unsigned int))(*(_DWORD *)varname.Value + 8))(a1: varname.Value) - 2) <= 3 )
    {
      v10 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: Value);
      if ( DWORD1(v10[6].m_pfnProxied) != 0 )
        v11 = DWORD1(v10[6].m_pfnProxied);
      else
        GFxASCharacter::CreateCharacterHandle(this: v10);
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)SectionNumber,
        a2: "Error: Can't find method '%s.%s' to invoke.\n",
        **(const char ***)(v11 + 12),
        Short);
    }
    else
    {
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)SectionNumber,
        a2: "Error: Can't find method '%s' to invoke.\n",
        Short);
    }
LABEL_28:
    GASValue::~GASValue(this: (GASValue *)&v18.hInstance);
    GASValue::~GASValue(this: (GASValue *)&v18);
    return 0;
  }
  GASValue::ToFunction(a1: &v18.lpszMenuName, a2: SectionNumber);
  if ( v18.lpszMenuName == nullptr )
  {
    v12 = (GASObjectInterface *)varname.Value;
    if ( varname.Value != 0
      && (unsigned int)((*(int (__thiscall **)(unsigned int))(*(_DWORD *)varname.Value + 8))(a1: varname.Value) - 2) <= 3 )
    {
      v13 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v12);
      if ( DWORD1(v13[6].m_pfnProxied) != 0 )
        v14 = DWORD1(v13[6].m_pfnProxied);
      else
        GFxASCharacter::CreateCharacterHandle(this: v13);
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)SectionNumber,
        a2: "Error: Invoked method '%s.%s' is not a function\n",
        **(const char ***)(v14 + 12),
        Short);
    }
    else
    {
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)SectionNumber,
        a2: "Error: Invoked method '%s' is not a function\n",
        Short);
    }
    if ( (v19 & 2) == 0 && v18.lpszMenuName != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v18.lpszMenuName, a2: (int)Short);
    v18.lpszMenuName = nullptr;
    if ( (v19 & 1) == 0 && v18.lpszClassName != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v18.lpszClassName, a2: (int)Short);
    v18.lpszClassName = nullptr;
    goto LABEL_28;
  }
  if ( LOBYTE(v18.hInstance) == 7 || LOBYTE(v18.hInstance) == 6 )
  {
    v16 = (GASObjectInterface *)GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)SectionNumber);
  }
  else if ( v20 != 0 )
  {
    v16 = (GASObjectInterface *)(v20 + 120);
  }
  else
  {
    v16 = (GASObjectInterface *)varname.Value;
  }
  v17 = GAS_Invoke(
          result: &v18,
          a2: (GASValue *)varname.N.Name.Long,
          nargs: v16,
          a4: (GASEnvironment *)SectionNumber,
          a5: *(int *)&varname.Type,
          firstArgBottomIndex: a2,
          a7: Short);
  if ( (v19 & 2) == 0 && v18.lpszMenuName != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v18.lpszMenuName, a2: (int)Short);
  v18.lpszMenuName = nullptr;
  if ( (v19 & 1) == 0 && v18.lpszClassName != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v18.lpszClassName, a2: (int)Short);
  v18.lpszClassName = nullptr;
  GASValue::~GASValue(this: (GASValue *)&v18.hInstance);
  GASValue::~GASValue(this: (GASValue *)&v18);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x1009F060
// Name: public: bool GASGlobalContext::RegisterClassA(class GASStringContext __near *,class GASString const __near &,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::RegisterClassA(
        vc_attributes::PostAttribute *this,
        _IMAGE_SYMBOL_EX *className,
        unsigned int a3,
        struct GASFunctionRefBase *a4)
{
  unsigned int key; // [esp+8h] [ebp-8h] BYREF
  struct GASFunctionRefBase *v5; // [esp+Ch] [ebp-4h]

  GASStringHashBase<GASFunctionRef,GHashUncachedLH<GASString,GASFunctionRef,GASStringHashFunctor,323>>::FindCaseCheck(
    this: (GFxMeshCacheManager *)this + 23,
    (unsigned int)&key);
  if ( key != 0 && *(_DWORD *)key != 0 && (int)v5 <= *(_DWORD *)(*(_DWORD *)key + 4) )
  {
    GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(*(_DWORD *)key + 20 * (_DWORD)v5 + 16), a2: a4);
  }
  else
  {
    v5 = a4;
    key = a3;
    GHashSetBase<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>,GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASFunctionRef,GASStringHashFunctor>::NodeRef>();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F0E0
// Name: public: void GASExecutionContext::SetTargetOpCode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::SetTargetOpCode(__vc_attributes::uuidAttribute *this)
{
  const char *value; // eax
  char v3; // al
  int *v4; // edi
  bool v5; // zf
  bool v6; // bl
  struct GFxASCharacter *v7; // eax
  unsigned int v8; // edi
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v9; // ecx
  __vc_attributes::uuidAttribute v10; // edi
  __vc_attributes::uuidAttribute v11; // esi
  const char *v12; // [esp-Ch] [ebp-40h]
  const char *v13; // [esp+0h] [ebp-34h]
  GASValue v14[4]; // [esp+Ch] [ebp-28h] BYREF
  GASValue v15; // [esp+1Ch] [ebp-18h] BYREF
  int v16; // [esp+20h] [ebp-14h]
  char varname[4]; // [esp+2Ch] [ebp-8h] BYREF
  struct GFxASCharacter *v18; // [esp+30h] [ebp-4h] BYREF

  value = this->value;
  v18 = nullptr;
  GASValue::GASValue(this: &v15, a2: *((const struct GASValue **)value + 2));
  v3 = (char)v15;
  if ( (_BYTE)v15 == 5 )
    goto LABEL_9;
  if ( (_BYTE)v15 != 7 )
  {
    v4 = (int *)GASValue::ToStringVersioned(a1: &v15, a2: varname, a3: this->value, a4: *((unsigned __int8 *)this + 52));
    if ( (unsigned __int8)v15 >= 5u )
      GASValue::DropRefs(this: &v15);
    LOBYTE(v15) = 5;
    v16 = *v4;
    ++*(_DWORD *)(v16 + 8);
    v5 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode();
    v3 = (char)v15;
  }
  if ( v3 == 5 )
  {
LABEL_9:
    GASValue::ToStringImpl(a1: &v15, a2: varname, a3: this->value, a4: -1, a5: 0);
    v6 = *(_DWORD *)(*(_DWORD *)varname + 16) == 0;
    v5 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode();
    if ( v6 )
    {
      v7 = *((struct GFxASCharacter **)this + 1);
      v18 = v7;
      goto LABEL_17;
    }
    v8 = *((_DWORD *)this + 8);
    v12 = this->value;
    LOBYTE(v14[0]) = 0;
    GASValue::ToStringImpl(a1: *((_DWORD *)v12 + 2), a2: varname, a3: v12, a4: -1, a5: 0);
    GASEnvironment::GetVariable(
      this: (__vc_attributes::max_isAttribute *)this->value,
      (_IMAGE_SYMBOL_EX *)varname,
      a3: v14,
      retVal: v8,
      paschar: (GStat::StatValue *)&v18,
      a6: nullptr,
      a7: 0);
    v5 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode();
    GASValue::~GASValue(this: v14);
    goto LABEL_16;
  }
  if ( v3 != 7 )
  {
LABEL_16:
    v7 = v18;
    goto LABEL_17;
  }
  v7 = GASValue::ToASCharacter(this: *((GASValue **)this->value + 2), a2: (const struct GASEnvironment *)this->value);
  v18 = v7;
LABEL_17:
  if ( v7 != nullptr )
  {
    v10.value = this->value;
    *((_BYTE *)v10.value + 198) &= ~2u;
    v9 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v7;
    *((_DWORD *)v10.value + 29) = v7;
  }
  else
  {
    if ( (*((_BYTE *)this + 54) & 1) != 0 )
    {
      GASValue::ToDebugString(a1: &v15, a2: varname, a3: this->value);
      GFxActionLogger::LogScriptError(
        result: this + 9,
        a2: "Error: SetTarget2(tellTarget) with invalid target '%s'.\n",
        **(const char ***)varname);
      v5 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
      if ( v5 )
        GASStringNode::ReleaseNode();
    }
    v9 = *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> **)this
         + 1);
    v10.value = this->value;
    *((_BYTE *)v10.value + 198) |= 2u;
    *((_DWORD *)v10.value + 29) = v9;
  }
  *((_BYTE *)v10.value + 124) = (unsigned __int8)GFxCharacter::GetVersion(this: v9);
  v11.value = this->value;
  GASValue::~GASValue(this: *((GASValue **)v11.value + 2));
  *((_DWORD *)v11.value + 2) -= 16;
  if ( *((_DWORD *)v11.value + 2) < *((_DWORD *)v11.value + 3) )
    GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v11.value + 2, a2: v13);
  GASValue::~GASValue(this: &v15);
}

//------------------------------------------------------------------------------
// Address: 0x1009F280
// Name: public: void GASExecutionContext::EnumerateOpCode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASExecutionContext::EnumerateOpCode(_DWORD *this, int actionId)
{
  __vc_attributes::iid_isAttribute *v3; // edi
  __vc_attributes::iid_isAttribute *v4; // edi
  GASValue *limited_expression; // ecx
  _SERVICE_STATUS *v6; // edi
  _SERVICE_STATUS *v7; // ecx
  char v8; // al
  int v9; // eax
  bool v10; // zf
  unsigned int v11; // [esp-10h] [ebp-54h]
  const char *v12; // [esp+0h] [ebp-44h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *variable; // [esp+8h] [ebp-3Ch] BYREF
  GASValue varName[4]; // [esp+18h] [ebp-2Ch] BYREF
  GASValue nullvalue[4]; // [esp+28h] [ebp-1Ch] BYREF
  void **v16; // [esp+38h] [ebp-Ch] BYREF
  _SERVICE_STATUS *v17; // [esp+3Ch] [ebp-8h]
  _DWORD *v18; // [esp+40h] [ebp-4h]

  GASValue::GASValue(this: varName, a2: *(const struct GASValue **)(*this + 8));
  v3 = (__vc_attributes::iid_isAttribute *)*this;
  GASValue::~GASValue(this: *(GASValue **)(*this + 8));
  v3[2].limited_expression -= 16;
  if ( v3[2].limited_expression < v3[3].limited_expression )
    GASPagedStack<GASValue,32>::PopPage(this: v3 + 2, a2: v12);
  LOBYTE(nullvalue[0]) = 0;
  GASValue::DropRefs(this: nullvalue);
  v4 = (__vc_attributes::iid_isAttribute *)*this;
  LOBYTE(nullvalue[0]) = 1;
  v4[2].limited_expression += 16;
  if ( v4[2].limited_expression >= v4[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: v4 + 2, a2: v12);
  limited_expression = (GASValue *)v4[2].limited_expression;
  if ( limited_expression != nullptr )
    GASValue::GASValue(this: limited_expression, a2: (const struct GASValue *)nullvalue);
  if ( actionId == 85 )
  {
    v6 = GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)*this);
    if ( v6 == nullptr )
      goto LABEL_18;
    goto LABEL_14;
  }
  GASValue::ToStringImpl(a1: varName, a2: &actionId, a3: *this, a4: -1, a5: 0);
  v11 = *(this + 8);
  v7 = (_SERVICE_STATUS *)*this;
  LOBYTE(variable) = 0;
  GASEnvironment::GetVariable(
    this: (__vc_attributes::max_isAttribute *)v7,
    varname: (_IMAGE_SYMBOL_EX *)&actionId,
    a3: &variable,
    retVal: v11,
    paschar: nullptr,
    a6: nullptr,
    a7: 0);
  if ( v8 != 0 )
  {
    v6 = GASValue::ToObjectInterface(result: (_SERVICE_STATUS *)*this);
    GASValue::~GASValue(this: &variable);
    v9 = actionId;
    if ( v6 != nullptr )
    {
      v10 = (*(_DWORD *)(actionId + 8))-- == 1;
      if ( v10 )
        GASStringNode::ReleaseNode();
LABEL_14:
      v17 = (_SERVICE_STATUS *)*this;
      v16 = (void **)&`GASExecutionContext::EnumerateOpCode'::`15'::EnumerateOpVisitor::`vftable';
      v18 = this + 9;
      (*(void (__thiscall **)(_SERVICE_STATUS *, unsigned int *, void ***, int, _DWORD))(v6->dwServiceType + 32))(
        a1: v6,
        a2: &v17[4].dwControlsAccepted,
        a3: &v16,
        a4: 11,
        a5: 0);
      v16 = &GString::InitStruct::`vftable';
      goto LABEL_18;
    }
  }
  else
  {
    GASValue::~GASValue(this: &variable);
    v9 = actionId;
  }
  v10 = (*(_DWORD *)(v9 + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode();
LABEL_18:
  GASValue::~GASValue(this: nullvalue);
  GASValue::~GASValue(this: varName);
}

//------------------------------------------------------------------------------
// Address: 0x1009F3C0
// Name: public: void GASActionBuffer::Execute(class GASEnvironment __near *,int,int,class GASValue __near *,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *,enum GASActionBuffer::ExecuteType)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall GASActionBuffer::Execute(
        int this,
        tagPOLYTEXTW *result,
        char *startPc,
        signed int execBytes,
        char *a5,
        int pinitialWithStack,
        int pinitialWithStack_4)
{
  int i; // ebx
  __vc_attributes::event_receiverAttribute::type_e StringNode; // edi
  int *v9; // eax
  int v10; // eax
  int v11; // eax
  int x; // edx
  GJPEGSystem *v13; // ecx
  GJPEGOutput *(__thiscall *CreateOutput)(GJPEGSystem *, GFile *); // eax
  GRect<float> *v15; // eax
  AvatarImageLoaded_t *v16; // eax
  char v17; // al
  int (__thiscall *v18)(__vc_attributes::uuidAttribute *); // eax
  char v19; // al
  signed int v20; // eax
  unsigned int v21; // ecx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *Instance; // eax
  int *v23; // ecx
  char v24; // al
  int v25; // eax
  GImageInfo *v26; // edx
  unsigned int v27; // eax
  GFxAmpViewStats *v28; // ecx
  float v29; // ecx
  int v30; // eax
  int v31; // edx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v32; // eax
  char v33; // al
  unsigned int m_unAll64Bits_high; // eax
  unsigned int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // edi
  unsigned int v38; // eax
  int v39; // eax
  int v40; // eax
  GFxMovieRoot *v41; // eax
  GFxFontLib *LevelMovie; // eax
  const wchar_t *v43; // eax
  unsigned int v44; // ecx
  const wchar_t *v45; // eax
  unsigned int v46; // ecx
  const wchar_t *v47; // eax
  unsigned int v48; // ecx
  const wchar_t *v49; // eax
  unsigned int v50; // ecx
  const wchar_t *v51; // eax
  const wchar_t *v52; // eax
  int v53; // ecx
  unsigned __int8 v54; // al
  const wchar_t *v55; // eax
  bool v56; // al
  unsigned __int8 v57; // al
  const wchar_t *v58; // eax
  bool v59; // cl
  const wchar_t *v60; // eax
  int v61; // ecx
  int v62; // eax
  unsigned int v63; // ecx
  const wchar_t *v64; // eax
  bool v65; // al
  bool v66; // zf
  GASString *v67; // eax
  tagCOMPAREITEMSTRUCT *Length; // eax
  unsigned int v69; // ecx
  unsigned int v70; // eax
  int v71; // ecx
  const IClientRenderable *v72; // eax
  GASValue *v73; // ecx
  GASValue *v74; // ebx
  int v75; // eax
  int v76; // eax
  GASValue *v77; // ecx
  tagCOMPAREITEMSTRUCT *v78; // eax
  _DWORD *v79; // eax
  double v80; // st7
  double v81; // st7
  double v82; // st7
  const wchar_t *v83; // eax
  int v84; // ecx
  GASValue *v85; // ecx
  const wchar_t *v86; // eax
  GASValue *v87; // ecx
  const wchar_t *v88; // eax
  GASValue *v89; // ecx
  const wchar_t *v90; // eax
  __vc_attributes::event_receiverAttribute::type_e v91; // eax
  struct GFxASCharacter *TargetByValue; // eax
  GASValue *v93; // ecx
  GASValue *v94; // edx
  int v95; // eax
  const wchar_t *v96; // eax
  unsigned int v97; // eax
  __vc_attributes::event_receiverAttribute::type_e v98; // ecx
  struct GFxASCharacter *v99; // eax
  const wchar_t *v100; // ecx
  GASValue *v101; // ecx
  int v102; // eax
  unsigned int v103; // eax
  __vc_attributes::event_receiverAttribute::type_e v104; // ecx
  const wchar_t *v105; // eax
  int v106; // ecx
  unsigned int v107; // eax
  struct GFxASCharacter *v108; // eax
  int v109; // eax
  const wchar_t *v110; // eax
  int v111; // ecx
  const IClientRenderable *v112; // eax
  unsigned int v113; // ecx
  const wchar_t *v114; // eax
  int v115; // eax
  unsigned __int8 v116; // al
  char *v117; // eax
  GRefCountBase<GFxAmpCurrentState,2> *v118; // eax
  unsigned int NextRandom; // eax
  tagCOMPAREITEMSTRUCT *v120; // eax
  unsigned __int8 v121; // al
  int v122; // ecx
  int v123; // eax
  GASValue *v124; // ecx
  int v125; // eax
  double v126; // rax
  unsigned int v127; // eax
  int v128; // ecx
  const IClientRenderable *v129; // eax
  GASValue *v130; // ecx
  GASValue *v131; // ebx
  int v132; // eax
  int v133; // eax
  tagCOMPAREITEMSTRUCT *v134; // eax
  GASValue *v135; // ecx
  const wchar_t *v136; // eax
  _SERVICE_STATUS *v137; // eax
  _SERVICE_STATUS *v138; // eax
  const struct GASEnvironment::GetVarParams *VarParams; // eax
  GASValue *v140; // ecx
  _SERVICE_STATUS *v141; // eax
  const wchar_t *v142; // eax
  int v143; // ecx
  tagWNDCLASSW *v144; // ecx
  struct GASObject *v145; // eax
  GASValue *v146; // ecx
  GViewport *v147; // ecx
  char v148; // al
  struct GASObjectInterface *v149; // eax
  const wchar_t *v150; // eax
  GASValue *v151; // ecx
  long double v152; // st7
  long double v153; // st7
  GASValue *v154; // ecx
  long double v155; // st7
  const wchar_t *v156; // eax
  GASValue *v157; // ecx
  GViewport *v158; // ecx
  char v159; // al
  GASValue *v160; // ecx
  int j; // ebx
  char v162; // al
  unsigned int v163; // eax
  char *v164; // eax
  double v165; // st7
  GASValue *v166; // ecx
  const IMatchEventsSink *v167; // ecx
  const IClientRenderable *v168; // ebx
  const wchar_t *v169; // eax
  const wchar_t *v170; // eax
  const wchar_t *v171; // ecx
  int v172; // ecx
  GASValue *v173; // ecx
  int k; // ebx
  struct GFxASCharacter *v175; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v176; // eax
  int v177; // eax
  const wchar_t *v178; // eax
  const wchar_t *v179; // eax
  GASValue *v180; // ecx
  const wchar_t *v181; // eax
  const struct GASValue *v182; // eax
  const wchar_t *v183; // edi
  GASValue *v184; // eax
  struct GASObject *v185; // eax
  GASValue *v186; // ecx
  int v187; // eax
  int v188; // eax
  tagWNDCLASSW *v189; // eax
  GASValue *v190; // ecx
  struct GASObject *v191; // eax
  char *v192; // eax
  const wchar_t *v193; // eax
  int v194; // eax
  double v195; // st7
  unsigned int v196; // eax
  GASValue *v197; // ecx
  GViewport *v198; // ecx
  char v199; // al
  GASValue *v200; // ecx
  GASValue *v201; // eax
  int v202; // eax
  struct GASObjectInterface *v203; // eax
  _JOB_SET_ARRAY *Owner; // eax
  struct GASObject *v205; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v206; // eax
  int v207; // eax
  const IClientRenderable *v208; // eax
  GASFnCall *v209; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v210; // eax
  int v211; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v212; // eax
  int v213; // eax
  GASValue *v214; // ecx
  struct GASObject *v215; // eax
  const IClientRenderable *v216; // eax
  PPM_IDLE_STATE_ACCOUNTING *v217; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v218; // eax
  int v219; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v220; // eax
  int v221; // eax
  GASValue *v222; // eax
  struct GASObject *v223; // eax
  GASObjectInterface *v224; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v225; // eax
  int v226; // eax
  const IClientRenderable *v227; // eax
  GASFnCall *v228; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v229; // eax
  int v230; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v231; // eax
  int v232; // eax
  const struct GASValue *v233; // eax
  struct GASObject *v234; // eax
  struct GASObject *v235; // edi
  _DWORD *v236; // eax
  PPM_IDLE_STATE_ACCOUNTING *v237; // edi
  char *v238; // eax
  struct GFxASCharacter *v239; // eax
  GASValue *v240; // ebx
  const wchar_t *v241; // eax
  const struct GASValue *v242; // eax
  struct GASObjectInterface *v243; // eax
  int right; // edx
  unsigned int v245; // eax
  GASValue *v246; // ecx
  GViewport *v247; // ecx
  char v248; // al
  GASObjectInterface *v249; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v250; // eax
  int v251; // eax
  const struct GASFunctionRef *v252; // eax
  GASValue *v253; // eax
  const struct GASFunctionRef *v254; // eax
  char *v255; // eax
  const wchar_t *v256; // eax
  unsigned int v257; // ecx
  const wchar_t *v258; // eax
  unsigned int v259; // ecx
  const wchar_t *v260; // eax
  unsigned int v261; // ecx
  const wchar_t *v262; // eax
  unsigned int v263; // ecx
  const wchar_t *v264; // eax
  unsigned int v265; // ecx
  const wchar_t *v266; // eax
  unsigned int v267; // ecx
  const wchar_t *v268; // eax
  GASValue *v269; // ecx
  const wchar_t *v270; // eax
  bool IsEqual; // al
  const wchar_t *v272; // eax
  int v273; // ecx
  const wchar_t *v274; // eax
  int v275; // ecx
  const wchar_t *v276; // eax
  int v277; // eax
  unsigned __int8 v278; // al
  int *v279; // ecx
  int (*v280)(void); // eax
  int v281; // eax
  int *v282; // ecx
  int (__thiscall *v283)(int *, int, _DWORD); // edx
  int v284; // eax
  ScaleformRenderTarget_vtbl **v285; // eax
  unsigned int v286; // eax
  unsigned int v287; // eax
  __vc_attributes::idl_moduleAttribute *v288; // eax
  GPtr<GFxZlibSupportBase> *v289; // eax
  int v290; // ecx
  int v291; // edx
  GASValue *n; // ecx
  struct GFxASCharacter *v293; // eax
  _DWORD *v294; // eax
  struct GASObject *v295; // eax
  GASWithStackEntry *v296; // eax
  int v297; // ecx
  unsigned int v298; // eax
  GASEnvironment *v299; // eax
  unsigned int v300; // ecx
  GASValue *v301; // ecx
  unsigned int v302; // eax
  int v303; // ecx
  int v304; // edx
  unsigned int v305; // eax
  int *v306; // eax
  int v307; // eax
  unsigned int v308; // eax
  unsigned int Short; // ecx
  int v310; // edx
  int v311; // ecx
  unsigned int v312; // eax
  double v313; // st7
  GASValue *v314; // ecx
  bool v315; // cl
  double v316; // rax
  double v317; // st7
  int v318; // edi
  int v319; // ecx
  int v320; // edx
  int v321; // eax
  unsigned int v322; // eax
  unsigned int v323; // eax
  int v324; // edx
  int *v325; // ecx
  int v326; // eax
  unsigned int v327; // eax
  GASValue *v328; // ecx
  int v329; // edx
  const wchar_t *v330; // eax
  int left; // eax
  int *v332; // eax
  int *v333; // ecx
  int v334; // eax
  int (__thiscall *v335)(int *, int, _DWORD); // edx
  int v336; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v337; // ecx
  const void *v338; // eax
  bool v339; // cf
  char *v340; // eax
  int v341; // eax
  struct GFxMovieRoot *v342; // eax
  ScaleformRenderTarget_vtbl **MovieRoot; // eax
  GASValue *v344; // ecx
  unsigned __int8 v345; // al
  GASValue *v346; // ecx
  char *v347; // eax
  _TAPE_WMI_OPERATIONS *v348; // eax
  int v349; // eax
  char v350; // al
  __int64 v351; // rax
  int v352; // eax
  unsigned int v353; // eax
  int y; // edx
  int v355; // ebx
  int v356; // edx
  int v357; // ecx
  tagPALETTEENTRY v358; // edx
  unsigned int v359; // eax
  int v360; // ecx
  int v361; // eax
  int v362; // edx
  __vc_attributes::idl_moduleAttribute *v363; // ecx
  float v364; // ecx
  __int64 v365; // rax
  AvatarImageLoaded_t *v366; // esi
  __vc_attributes::event_receiverAttribute::type_e v367; // [esp-Ch] [ebp-1BCh]
  char *v368; // [esp-8h] [ebp-1B8h]
  _IMAGE_SYMBOL_EX *v369; // [esp-4h] [ebp-1B4h]
  IDirect3DStateBlock9 *v370; // [esp-4h] [ebp-1B4h]
  GASValue *v371; // [esp-4h] [ebp-1B4h]
  GASValue *v372; // [esp-4h] [ebp-1B4h]
  _BYTE v373[24]; // [esp+0h] [ebp-1B0h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> v374; // [esp+2Ch] [ebp-184h] BYREF
  IInputSystem v375; // [esp+44h] [ebp-16Ch] BYREF
  unsigned __int8 v376[8]; // [esp+5Ch] [ebp-154h] BYREF
  char *descr; // [esp+64h] [ebp-14Ch] OVERLAPPED BYREF
  char *v378; // [esp+68h] [ebp-148h]
  int v379; // [esp+6Ch] [ebp-144h]
  double v380; // [esp+70h] [ebp-140h]
  __int64 v381; // [esp+78h] [ebp-138h]
  unsigned __int64 v382; // [esp+80h] [ebp-130h]
  __int64 v383; // [esp+88h] [ebp-128h] BYREF
  GFxAmpViewStats *v384; // [esp+90h] [ebp-120h]
  GImageInfo *v385; // [esp+94h] [ebp-11Ch]
  unsigned int v386; // [esp+98h] [ebp-118h]
  unsigned int v387; // [esp+A0h] [ebp-110h]
  BOOL v388; // [esp+A4h] [ebp-10Ch]
  GImageInfo *v389; // [esp+A8h] [ebp-108h]
  GASWithStackEntry v390; // [esp+B0h] [ebp-100h] BYREF
  int *v391; // [esp+B8h] [ebp-F8h] BYREF
  int retVal; // [esp+BCh] [ebp-F4h]
  int tc; // [esp+C0h] [ebp-F0h] BYREF
  GImageInfo *v394; // [esp+C4h] [ebp-ECh]
  InputCursorHandle_t__ bufferTimes; // [esp+C8h] [ebp-E8h]
  char v396; // [esp+CCh] [ebp-E4h] BYREF
  char v397; // [esp+CDh] [ebp-E3h] BYREF
  char v398; // [esp+CEh] [ebp-E2h] BYREF
  bool isOriginalTargetValid; // [esp+CFh] [ebp-E1h]
  unsigned int samplingPeriod; // [esp+D0h] [ebp-E0h] BYREF
  char *retval; // [esp+D4h] [ebp-DCh]
  int v402; // [esp+D8h] [ebp-D8h] BYREF
  long double phandler; // [esp+DCh] [ebp-D4h] OVERLAPPED
  GPtr<GJPEGSystem> v404; // [esp+E4h] [ebp-CCh] BYREF
  __vc_attributes::idl_moduleAttribute *pdx; // [esp+E8h] [ebp-C8h]
  int v406; // [esp+ECh] [ebp-C4h]
  GJPEGSystem_vtbl *v407; // [esp+F0h] [ebp-C0h]
  char *v408; // [esp+F4h] [ebp-BCh]
  char *nextPc; // [esp+F8h] [ebp-B8h]
  char *pc; // [esp+FCh] [ebp-B4h]
  GPtr<GJPEGSystem> v411; // [esp+100h] [ebp-B0h] BYREF
  AvatarImageLoaded_t *v412; // [esp+104h] [ebp-ACh]
  __vc_attributes::uuidAttribute v413; // [esp+108h] [ebp-A8h] BYREF
  char v414; // [esp+110h] [ebp-A0h]
  unsigned __int8 Version; // [esp+118h] [ebp-98h]
  char v416; // [esp+119h] [ebp-97h]
  char v417; // [esp+11Ah] [ebp-96h]
  char *pactBuf; // [esp+11Ch] [ebp-94h]
  int v419; // [esp+120h] [ebp-90h]
  int tryCount; // [esp+124h] [ebp-8Ch] BYREF
  struct GASObjectInterface *NargsIn; // [esp+128h] [ebp-88h]
  struct GASObject *v422; // [esp+12Ch] [ebp-84h]
  const IClientRenderable *s2; // [esp+130h] [ebp-80h]
  int sceneOffset; // [esp+134h] [ebp-7Ch] BYREF
  bool test; // [esp+138h] [ebp-78h]
  int reg; // [esp+13Ch] [ebp-74h] BYREF
  _IMAGE_SYMBOL_EX varname; // [esp+140h] [ebp-70h] BYREF
  double nargsf; // [esp+154h] [ebp-5Ch] BYREF
  GASFnCall fnCallBuf[9]; // [esp+15Ch] [ebp-54h] BYREF
  GAtomicInt<unsigned long> funcBuf; // [esp+180h] [ebp-30h] BYREF
  GRefCountNTSImpl v431[2]; // [esp+18Ch] [ebp-24h] BYREF
  char index[16]; // [esp+19Ch] [ebp-14h] BYREF

  i = pinitialWithStack_4;
  StringNode = (__vc_attributes::event_receiverAttribute::type_e)startPc;
  pactBuf = (char *)this;
  retval = a5;
  bufferTimes.unused = pinitialWithStack;
  v419 = pinitialWithStack_4;
  if ( (pinitialWithStack_4 != 0 && pinitialWithStack_4 != 3
     || (*((_WORD *)(v9 = result[2].pdx) + 59) & 0x100) == 0 && v9[5] >= -1)
    && (*((_BYTE *)result[2].pdx + 118) & 0x10) == 0 )
  {
    ++result[4].rcl.bottom;
    v10 = *(_DWORD *)(this + 8);
    tryCount = 0;
    if ( *(_DWORD *)(v10 + 12) == 0 || *(_BYTE *)(v11 = *(_DWORD *)(v10 + 8)) == 0 )
      v11 = 0;
    x = result[3].x;
    v404.pObject = (GJPEGSystem *)result;
    pdx = (__vc_attributes::idl_moduleAttribute *)result[2].pdx;
    v406 = v11;
    v13 = *(GJPEGSystem **)(x + 656);
    v411.pObject = v13;
    if ( bufferTimes.unused != 0
      && (CreateOutput = v13->__vftable[1].CreateOutput,
          samplingPeriod = 323,
          v15 = (GRect<float> *)((int (__thiscall *)(GJPEGSystem *, int, unsigned int *))CreateOutput)(
                                  a1: v13,
                                  a2: 12,
                                  a3: &samplingPeriod),
          v394 = (GImageInfo *)v15,
          v15 != nullptr) )
    {
      GArrayData<GASWithStackEntry,GAllocatorLH_POD<GASWithStackEntry,323>,GArrayDefaultPolicy>::GArrayData<GASWithStackEntry,GAllocatorLH_POD<GASWithStackEntry,323>,GArrayDefaultPolicy>(
        this: v15,
        a: (const GPoint<float> *)bufferTimes.unused);
      v16 = (AvatarImageLoaded_t *)v394;
    }
    else
    {
      v16 = nullptr;
    }
    v412 = v16;
    GFxActionLogger::GFxActionLogger(this: (GFxActionLogger *)&v413, a2: (struct GFxCharacter *)pdx, a3: nullptr);
    v407 = v404.pObject[20].__vftable;
    Version = (unsigned __int8)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v404.pObject[14].RefCount);
    v17 = (v417 ^ (4 * (pinitialWithStack_4 == 2))) & 4 ^ v417;
    v417 = (v17 ^ (2 * v414)) & 2 ^ v17;
    v18 = *((int (__thiscall **)(__vc_attributes::uuidAttribute *))v413.value + 1);
    v416 = pinitialWithStack_4;
    v19 = v18(a1: &v413);
    isOriginalTargetValid = (BYTE2(result[4].pdx) & 2) == 0;
    v417 ^= (v19 ^ v417) & 1;
    v20 = *(_DWORD *)(*((_DWORD *)pactBuf + 2) + 12);
    if ( execBytes < v20 )
      v20 = execBytes;
    v408 = &startPc[v20];
    nextPc = startPc;
    pc = startPc;
    v422 = nullptr;
    bufferTimes.unused = 0;
    GFxAmpServer::GetInstance(a1: execBytes);
    LOBYTE(i) = (unsigned __int8)GFxAmpServer::IsProfiling(result: *(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)&v373[8]);
    Instance = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(a1: v21);
    GFxAmpServer::IsState(
      this: Instance,
      state: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x10);
    v23 = result[2].pdx;
    samplingPeriod = v24 != 0 ? 0x32 : 0;
    v394 = *(GImageInfo **)((*(int (__thiscall **)(int *))(*v23 + 84))(a1: v23) + 10308);
    v25 = *((_DWORD *)pactBuf + 2);
    v26 = *(GImageInfo **)(v25 + 16);
    v27 = (unsigned int)&startPc[*(_DWORD *)(v25 + 20)];
    v28 = (unsigned __int8)i != 0 ? (GFxAmpViewStats *)v394 : nullptr;
    v389 = v26;
    v387 = v27;
    v384 = v28;
    v385 = v26;
    v386 = v27;
    if ( v28 != nullptr )
    {
      GFxAmpViewStats::PushCallstack(this: v28, swdHandle: (unsigned int)v26, a3: v27);
      GTimer::GetRawTicks(li: v29, a2: *(float *)&v373[8], a3: *(float **)&v373[12]);
      HIDWORD(v383) = v31;
    }
    else
    {
      v30 = 0;
      HIDWORD(v383) = 0;
    }
    LODWORD(v383) = v30;
    if ( (_BYTE)i != 0 )
    {
      v32 = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(a1: (unsigned int)v28);
      GFxAmpServer::IsState(
        this: v32,
        state: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)4);
      if ( v33 != 0 )
      {
        StringNode = (__vc_attributes::event_receiverAttribute::type_e)v394;
        bufferTimes.unused = GFxAmpViewStats::LockBufferInstructionTimes(
                               this: (int)v394,
                               a2: *(_DWORD *)(*((_DWORD *)pactBuf + 2) + 16),
                               a3: *(_DWORD *)(*((_DWORD *)pactBuf + 2) + 20),
                               a4: *(_DWORD *)(*((_DWORD *)pactBuf + 2) + 12));
        *(_DWORD *)&v373[4] = samplingPeriod;
        GFxAmpViewStats::GetInstructionTime(this: v394);
      }
    }
    if ( (int)pc < (int)v408 )
    {
      while ( 1 )
      {
        if ( v412 == nullptr )
          goto LABEL_35;
        m_unAll64Bits_high = HIDWORD(v412->m_steamID.m_steamid.m_unAll64Bits);
        v35 = 0;
        if ( m_unAll64Bits_high == 0 )
          goto LABEL_35;
        StringNode = (__vc_attributes::event_receiverAttribute::type_e)pc;
        do
        {
          if ( (int)pc < (*(_DWORD *)(*(_DWORD *)&v412->m_steamID.m_steamid.m_comp + 8 * m_unAll64Bits_high - 4)
                        & 0x7FFFFFFF) )
            break;
          ++v35;
        }
        while ( v35 < m_unAll64Bits_high );
        if ( v35 != 0 )
          break;
LABEL_36:
        v38 = *(unsigned __int8 *)(v406 + StringNode);
        if ( (v38 & 0x80u) != 0 )
        {
          sceneOffset = *(unsigned __int16 *)(v406 + StringNode + 1);
          nextPc = (char *)(sceneOffset + StringNode + 3);
          switch ( v38 )
          {
            case 0x81u:
              if ( (BYTE2(result[4].pdx) & 2) == 0 )
              {
                v279 = result[2].pdx;
                if ( v279 != nullptr )
                {
                  StringNode = *v279;
                  i = *(unsigned __int16 *)&pc[v406 + 3];
                  (*(void (__thiscall **)(int *, int))(*v279 + 324))(a1: v279, a2: i);
                }
              }
              goto LABEL_878;
            case 0x83u:
              i = (int)&pc[v406 + 3];
              StringNode = i + strlen((const char *)i) + 1;
              HIDWORD(phandler) = StringNode;
              v66 = strncmp(first: (const char *)i, last: "FSCommand:", count: 0xAu) == 0;
              v280 = *(int (**)(void))(*result[2].pdx + 84);
              if ( v66 )
              {
                v281 = v280();
                ScopeFunctionTimer::ScopeFunctionTimer(
                  this: (ScopeFunctionTimer *)&v375,
                  a2: *(struct GFxAmpViewStats **)(v281 + 10308),
                  swdHandle: 1u,
                  a4: 0x21u);
                StringNode = *(_DWORD *)((*((int (__thiscall **)(__vc_attributes::idl_moduleAttribute *))pdx->name + 21))(a1: pdx)
                                       + 256);
                if ( StringNode != native )
                {
                  v282 = result[2].pdx;
                  *(_DWORD *)&v373[4] = HIDWORD(phandler);
                  v283 = *(int (__thiscall **)(int *, int, _DWORD))(*v282 + 84);
                  i += 10;
                  HIDWORD(phandler) = *(_DWORD *)StringNode;
                  v284 = v283(a1: v282, a2: i, a3: *(_DWORD *)&v373[4]);
                  (*(void (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e, int))(HIDWORD(phandler) + 4))(
                    a1: StringNode,
                    a2: v284);
                }
                ScopeFunctionTimer::~ScopeFunctionTimer(this: &v375, a2: *(InputStandardCursor_t *)&v373[8]);
              }
              else
              {
                v285 = (ScaleformRenderTarget_vtbl **)v280();
                GFxMovieRoot::AddLoadQueueEntry(
                  this: v285,
                  a2: StringNode,
                  a3: (char *)i,
                  a4: (GString)result,
                  a5: nullptr,
                  pmovieClipLoader: 0);
              }
              goto LABEL_880;
            case 0x87u:
              v286 = (unsigned __int8)pc[v406 + 3];
              if ( (v417 & 4) != 0 )
              {
                *(_DWORD *)&v373[4] = result->n;
                GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)result, reg: v286);
                GASValue::operator=(v: *(tagWNDCLASSW **)&v373[4]);
              }
              else if ( v286 > 3 )
              {
                if ( (v417 & 1) != 0 )
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: StoreRegister[%d] - register out of bounds!",
                    (unsigned __int8)pc[v406 + 3]);
              }
              else
              {
                GASValue::operator=(v: (tagWNDCLASSW *)result->n);
              }
              goto LABEL_880;
            case 0x88u:
              GASActionBuffer::ProcessDeclDict(
                this: (GASActionBuffer *)pactBuf,
                startPc: (struct GASStringContext *)&result[3],
                count: (unsigned int)pc,
                stopPc: (unsigned int)nextPc,
                log: &v413);
              goto LABEL_880;
            case 0x8Au:
            case 0x8Du:
              GASExecutionContext::WaitForFrameOpCode(this: &v404, len: (GASActionBuffer *)pactBuf, skipCount: v38);
              goto LABEL_880;
            case 0x8Bu:
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)&pc[v406 + 3];
              if ( *(_BYTE *)StringNode == 0 )
              {
                GASEnvironment::SetTarget(this: (int)result, result: pdx);
                goto LABEL_880;
              }
              *(_DWORD *)&v373[4] = &pc[v406 + 3];
              GASStringManager::CreateStringNode(this: *(const char **)(result[3].x + 636));
              varname.N.Name.Short = v287;
              ++*(_DWORD *)(v287 + 8);
              GASEnvironment::FindTarget(
                this: (__vc_attributes::event_receiverAttribute *)result,
                path: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)&varname,
                excludeFlags: false);
              if ( v288 != nullptr )
              {
                GASEnvironment::SetTarget(this: (int)result, result: v288);
              }
              else
              {
                if ( (v417 & 1) != 0 )
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: SetTarget(tellTarget) with invalid target '%s'.\n",
                    (const char *)StringNode);
                GASEnvironment::SetInvalidTarget(this: (int)result, result: pdx);
              }
              goto LABEL_346;
            case 0x8Cu:
              if ( (BYTE2(result[4].pdx) & 2) == 0 )
              {
                StringNode = (__vc_attributes::event_receiverAttribute::type_e)&pc[v406 + 3];
                v289 = (GPtr<GFxZlibSupportBase> *)GASObjectInterface::ToSprite(result: *(_TAPE_WMI_OPERATIONS **)&v373[8]);
                if ( v289 != nullptr )
                {
                  *(_QWORD *)v373 = (unsigned int)StringNode;
                  GFxSprite::GotoLabeledFrame(this: v289, label: (const GPtr<GFxZlibSupportBase> *)StringNode);
                }
              }
LABEL_665:
              if ( GASEnvironment::NeedTermination(this: result, a2: v419) )
                nextPc = v408;
              goto LABEL_880;
            case 0x8Eu:
              GASExecutionContext::Function2OpCode(this: &v404, pActions: (unsigned int)pactBuf);
              goto LABEL_880;
            case 0x8Fu:
              GASEnvironment::CheckTryBlocks(
                this: (__vc_attributes::unhookAttribute *)result,
                pc,
                plocalTryBlockCount: (const char *)&tryCount);
              ++tryCount;
              v290 = result->n - (unsigned int)result->lpstr;
              descr = &pc[v406 + 3];
              v291 = 32 * (result->rcl.right - 1);
              v378 = nextPc;
              v379 = v291 + (v290 >> 4);
              GASEnvironment::PushTryBlock(
                this: (GASEnvironment *)result,
                a2: (const struct GASEnvironment::TryDescr *)&descr);
              goto LABEL_880;
            case 0x94u:
              if ( v412 == nullptr || *((_DWORD *)&v412->m_steamID.m_steamid.m_comp + 1) < 8u )
              {
                n = (GASValue *)result->n;
                StringNode = (__vc_attributes::event_receiverAttribute::type_e)&nextPc[*(unsigned __int16 *)&pc[v406 + 3]];
                *(_DWORD *)&v373[4] = result;
                if ( *(_BYTE *)n == 7 )
                {
                  v293 = GASValue::ToASCharacter(this: n, a2: *(const struct GASEnvironment **)&v373[4]);
                  v294 = GASWithStackEntry::GASWithStackEntry(this: v376, a2: (int)v293, end: StringNode);
                  GASExecutionContext::WithStackHolder::PushBack(this: &v411, a2: v294);
                  GASWithStackEntry::~GASWithStackEntry(this: v376, a2: StringNode);
                }
                else
                {
                  v295 = GASValue::ToObject(this: n, a2: *(const struct GASEnvironment **)&v373[4]);
                  v296 = GASWithStackEntry::GASWithStackEntry(this: &v390, a2: v295, a3: StringNode);
                  GASExecutionContext::WithStackHolder::PushBack(this: &v411, a2: v296);
                  GASWithStackEntry::~GASWithStackEntry(this: (unsigned __int8 *)&v390, a2: StringNode);
                }
              }
              goto $LN5115;
            case 0x96u:
              i = (int)pc;
              break;
            case 0x99u:
              v329 = *((_DWORD *)pactBuf + 2);
              nextPc += (unsigned __int8)pc[v406 + 3] | (__int16)((unsigned __int8)pc[v406 + 4] << 8);
              if ( (unsigned int)nextPc < *(_DWORD *)(v329 + 12) )
                goto LABEL_880;
              GASEnvironment::SetTarget(this: (int)result, result: pdx);
              if ( (v417 & 1) != 0 )
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: " Error: Branch destination %d is out of action buffer bounds!\n",
                  nextPc);
              ScopeFunctionTimer::~ScopeFunctionTimer(
                this: (IInputSystem *)&v383,
                a2: *(InputStandardCursor_t *)&v373[8]);
              if ( v422 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
              v404.pObject[20].__vftable = v407;
              v413.value = (const char *)&GFxLogBase<GFxLoadProcess>::`vftable';
              GASExecutionContext::WithStackHolder::~WithStackHolder(this: &v411);
              return;
            case 0x9Au:
              LOBYTE(i) = pc[v406 + 3];
              GASValue::ToStringImpl(a1: result->n, a2: &varname, a3: result, a4: -1, a5: 0);
              v330 = (const wchar_t *)result->n;
              if ( v330 <= result->lpstr )
                left = result->rcl.left;
              else
                left = (int)(v330 - 8);
              GASValue::ToStringImpl(a1: left, a2: &v402, a3: result, a4: -1, a5: 0);
              if ( strncmp(first: *(const char **)v402, last: "FSCommand:", count: 0xAu) == 0 )
              {
                v332 = *(int **)((*((int (__thiscall **)(__vc_attributes::idl_moduleAttribute *))pdx->name + 21))(a1: pdx)
                               + 256);
                HIDWORD(phandler) = v332;
                if ( v332 != nullptr )
                {
                  v333 = result[2].pdx;
                  v334 = *v332;
                  *(_DWORD *)&v373[4] = *(_DWORD *)varname.N.Name.Short;
                  v335 = *(int (__thiscall **)(int *, int, _DWORD))(*v333 + 84);
                  i = *(_DWORD *)v402 + 10;
                  sceneOffset = v334;
                  v336 = v335(a1: v333, a2: i, a3: *(_DWORD *)&v373[4]);
                  (*(void (__thiscall **)(_DWORD, int))(sceneOffset + 4))(a1: HIDWORD(phandler), a2: v336);
                }
              }
              else
              {
                reg = 0;
                if ( (i & 3) == 1 )
                {
                  reg = 1;
                }
                else if ( (i & 3) == 2 )
                {
                  reg = 2;
                }
                v337 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)result[2].pdx;
                sceneOffset = (int)&pMem;
                v338 = GFxCharacter::GetVersion(this: v337);
                v339 = (unsigned int)v338 < 6;
                v66 = v338 == (const void *)6;
                v340 = *(char **)varname.N.Name.Short;
                LOBYTE(v388) = !v339 && !v66;
                v341 = GFxMovieRoot::ParseLevelName(
                         nptr: v340,
                         ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&sceneOffset,
                         caseSensitive: v388);
                if ( (i & 0x80u) == 0 )
                {
                  if ( (i & 0x40) != 0 || v341 != -1 && *(_BYTE *)sceneOffset == 0 )
                  {
                    *(_QWORD *)v373 = (unsigned int)reg;
                    v368 = *(char **)v402;
                    v367 = *(_DWORD *)varname.N.Name.Short;
                    MovieRoot = (ScaleformRenderTarget_vtbl **)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result);
                    GFxMovieRoot::AddLoadQueueEntry(
                      this: MovieRoot,
                      a2: v367,
                      a3: v368,
                      a4: (GString)result,
                      a5: *(GRendererNode **)v373,
                      pmovieClipLoader: *(GPtr<IDirect3DVertexDeclaration9> *)&v373[4]);
                  }
                }
                else
                {
                  *(_DWORD *)&v373[4] = reg;
                  *(_DWORD *)v373 = *(_DWORD *)v402;
                  v370 = *(IDirect3DStateBlock9 **)varname.N.Name.Short;
                  v342 = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result);
                  GFxMovieRoot::AddVarLoadQueueEntry(
                    this: (int)v342,
                    result: v370,
                    a3: *(char **)v373,
                    a4: *(GRendererNode **)&v373[4]);
                }
              }
              v344 = (GASValue *)result->n;
              if ( (const wchar_t *)(v344 - 8) >= result->lpstr )
              {
                GASValue::~GASValue(this: v344);
                result->n -= 16;
                GASValue::~GASValue(this: (GASValue *)result->n);
                result->n -= 16;
              }
              else
              {
                for ( i = 2; i != 0; --i )
                {
                  GASValue::~GASValue(this: (GASValue *)result->n);
                  result->n -= 16;
                  if ( (const wchar_t *)result->n < result->lpstr )
                    GASPagedStack<GASValue,32>::PopPage(
                      this: (__vc_attributes::iid_isAttribute *)&result->n,
                      a2: *(const char **)&v373[8]);
                }
              }
              StringNode = -1;
              v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
              if ( v66 )
                GASStringNode::ReleaseNode();
              v66 = (*(_DWORD *)(v402 + 8))-- == 1;
              goto LABEL_348;
            case 0x9Bu:
              GASExecutionContext::Function1OpCode(this: &v404, a2: (const char *)i, pActions: (unsigned int)pactBuf);
              goto LABEL_880;
            case 0x9Du:
              i = *(unsigned __int16 *)&pc[v406 + 3];
              v345 = (unsigned __int8)GASValue::ToBool(result);
              v346 = (GASValue *)result->n;
              test = v345;
              GASValue::~GASValue(this: v346);
              result->n -= 16;
              if ( (const wchar_t *)result->n < result->lpstr )
                GASPagedStack<GASValue,32>::PopPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
              if ( test )
              {
                v347 = &nextPc[(__int16)i];
                nextPc = v347;
                if ( (int)v347 > (int)v408 && (v417 & 1) != 0 )
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: branch to offset %d - this section only runs to %d\n",
                    v347,
                    v408);
              }
              goto LABEL_880;
            case 0x9Eu:
              v66 = (BYTE2(result[4].pdx) & 2) == 0;
              reg = (int)result[2].pdx;
              if ( !v66 )
                goto LABEL_880;
              v371 = (GASValue *)result->n;
              sceneOffset = 0;
              if ( GASActionBuffer::ResolveFrameNumber(
                     this: (GASActionBuffer *)pactBuf,
                     a2: (__vc_attributes::event_receiverAttribute *)result,
                     a3: v371,
                     a4: (struct GFxASCharacter **)&reg,
                     a5: (unsigned int *)&sceneOffset) != 0 )
              {
                v348 = GASObjectInterface::ToSprite(result: *(_TAPE_WMI_OPERATIONS **)&v373[8]);
                if ( v348 != nullptr )
                  (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *, int))(v348->Method + 360))(a1: v348, a2: sceneOffset);
              }
              else if ( (v417 & 1) != 0 )
              {
                GASValue::ToStringImpl(a1: result->n, a2: &v391, a3: result, a4: -1, a5: 0);
                i = *v391;
                v349 = *(_DWORD *)(reg + 148);
                if ( v349 == 0 )
                  GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)reg);
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: "Error: %s, CallFrame('%s') - unknown frame\n",
                  **(const char ***)(v349 + 12),
                  (const char *)i);
                GASString::~GASString(this: (GASString *)&v391);
              }
$LN5115:
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
              if ( (const wchar_t *)result->n < result->lpstr )
LABEL_694:
                GASPagedStack<GASValue,32>::PopPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
              goto LABEL_880;
            case 0x9Fu:
              v350 = pc[v406 + 3];
              StringNode = (v350 & 1) == 0;
              sceneOffset = 0;
              if ( (v350 & 2) != 0 )
                sceneOffset = *(unsigned __int16 *)&pc[v406 + 4];
              reg = (int)result[2].pdx;
              i = (int)&result->n;
              v372 = (GASValue *)result->n;
              tc = 0;
              if ( GASActionBuffer::ResolveFrameNumber(
                     this: (GASActionBuffer *)pactBuf,
                     a2: (__vc_attributes::event_receiverAttribute *)result,
                     a3: v372,
                     a4: (struct GFxASCharacter **)&reg,
                     a5: (unsigned int *)&tc) != 0 )
              {
                (*(void (__thiscall **)(int, int))(*(_DWORD *)reg + 324))(a1: reg, a2: sceneOffset + tc);
                (*(void (__thiscall **)(int, __vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)reg + 328))(
                  a1: reg,
                  a2: StringNode);
              }
              GASValue::~GASValue(this: *(GASValue **)i);
              *(_DWORD *)i -= 16;
              if ( (const wchar_t *)result->n < result->lpstr )
                GASPagedStack<GASValue,32>::PopPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
LABEL_878:
              if ( GASEnvironment::NeedTermination(this: result, a2: v419) )
LABEL_879:
                nextPc = v408;
              goto LABEL_880;
            default:
              goto LABEL_880;
          }
          while ( 1 )
          {
            v297 = *(unsigned __int8 *)(i + v406 + 3);
            ++i;
            switch ( v297 )
            {
              case 4:
                v298 = *(unsigned __int8 *)(i + v406 + 3);
                ++i;
                reg = v298;
                if ( (v417 & 4) != 0 )
                {
                  v299 = GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)result, reg: v298);
                  result->n += 16;
                  HIDWORD(phandler) = v299;
                  if ( result->n >= result->uiFlags )
                    GASPagedStack<GASValue,32>::PushPage(
                      this: (__vc_attributes::iid_isAttribute *)&result->n,
                      a2: *(const char **)&v373[8]);
                  StringNode = result->n;
                  if ( StringNode != native )
                    GASValue::GASValue(this: (GASValue *)StringNode, a2: (const struct GASValue *)HIDWORD(phandler));
                  break;
                }
                result->n += 16;
                v300 = result->n;
                if ( v298 <= 3 )
                {
                  if ( v300 >= result->uiFlags )
                  {
                    GASPagedStack<GASValue,32>::PushPage(
                      this: (__vc_attributes::iid_isAttribute *)&result->n,
                      a2: *(const char **)&v373[8]);
                    v298 = reg;
                  }
                  v301 = (GASValue *)result->n;
                  if ( v301 != nullptr )
                    GASValue::GASValue(this: v301, a2: (const struct GASValue *)((char *)&result[1] + 16 * v298));
                  break;
                }
                index[0] = 0;
                if ( v300 >= result->uiFlags )
                {
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                  v298 = reg;
                }
                StringNode = result->n;
                if ( StringNode != native )
                {
                  GASValue::GASValue(this: (GASValue *)StringNode, a2: (const struct GASValue *)index);
                  v298 = reg;
                }
                if ( (v417 & 1) == 0 )
                  goto LABEL_793;
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: "Error: push register[%d] - register out of bounds\n",
                  v298);
                GASValue::~GASValue(this: (GASValue *)index);
                break;
              case 8:
                v302 = *(unsigned __int8 *)(i + v406 + 3);
                ++i;
                if ( v302 < *((_DWORD *)pactBuf + 4) )
                {
                  v303 = *((_DWORD *)pactBuf + 3);
                  result->n += 16;
                  v304 = v303 + 4 * v302;
                  v305 = result->n;
                  HIDWORD(phandler) = v304;
                  if ( v305 >= result->uiFlags )
                    GASPagedStack<GASValue,32>::PushPage(
                      this: (__vc_attributes::iid_isAttribute *)&result->n,
                      a2: *(const char **)&v373[8]);
                  StringNode = result->n;
                  if ( StringNode != native )
                  {
                    v306 = (int *)HIDWORD(phandler);
                    *(_BYTE *)StringNode = 5;
                    v307 = *v306;
                    *(_DWORD *)(StringNode + 4) = v307;
                    ++*(_DWORD *)(v307 + 8);
                  }
                  break;
                }
                if ( (v417 & 1) != 0 )
                  GFxActionLogger::LogScriptError(result: &v413, a2: "Error: DictLookup(%d) is out of bounds\n", v302);
                index[0] = 0;
                goto LABEL_789;
              case 0:
                *(_DWORD *)&v373[4] = i + v406 + 3;
                GASStringManager::CreateStringNode(this: *(const char **)(result[3].x + 636));
                varname.N.Name.Short = v308;
                ++*(_DWORD *)(v308 + 8);
                Short = varname.N.Name.Short;
                v310 = *(_DWORD *)(varname.N.Name.Short + 16);
                result->n += 16;
                i += v310 + 1;
                if ( result->n >= result->uiFlags )
                {
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                  Short = varname.N.Name.Short;
                }
                StringNode = result->n;
                if ( StringNode != native )
                {
                  *(_BYTE *)StringNode = 5;
                  *(_DWORD *)(StringNode + 4) = varname.N.Name.Short;
                  ++*(_DWORD *)(varname.N.Name.Short + 8);
                  Short = varname.N.Name.Short;
                }
                v66 = (*(_DWORD *)(Short + 8))-- == 1;
                if ( v66 )
                  GASStringNode::ReleaseNode();
                break;
              case 1:
                v311 = *(_DWORD *)(i + v406 + 3);
                result->n += 16;
                v312 = result->n;
                i += 4;
                HIDWORD(phandler) = v311;
                if ( v312 >= result->uiFlags )
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                StringNode = result->n;
                if ( StringNode != native )
                {
                  v313 = *((float *)&phandler + 1);
                  *(_BYTE *)StringNode = 3;
                  *(double *)(StringNode + 4) = v313;
                }
                break;
              case 2:
                index[0] = 0;
                GASValue::DropRefs(this: (GASValue *)index);
                index[0] = 1;
LABEL_789:
                result->n += 16;
                if ( result->n >= result->uiFlags )
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                v314 = (GASValue *)result->n;
                if ( v314 != nullptr )
                  GASValue::GASValue(this: v314, a2: (const struct GASValue *)index);
LABEL_793:
                GASValue::~GASValue(this: (GASValue *)index);
                break;
              case 3:
                goto LABEL_818;
              case 5:
                test = *(_BYTE *)(i + v406 + 3) != 0;
                result->n += 16;
                ++i;
                if ( result->n >= result->uiFlags )
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                StringNode = result->n;
                if ( StringNode != native )
                {
                  v315 = test;
                  *(_BYTE *)StringNode = 2;
                  *(_BYTE *)(StringNode + 4) = v315;
                }
                break;
              case 6:
                HIDWORD(v316) = *(_DWORD *)(i + v406 + 3);
                LODWORD(v316) = *(_DWORD *)(i + v406 + 7);
                result->n += 16;
                v380 = v316;
                i += 8;
                if ( result->n >= result->uiFlags )
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                StringNode = result->n;
                if ( StringNode != native )
                {
                  v317 = v380;
                  *(_BYTE *)StringNode = 3;
                  *(double *)(StringNode + 4) = v317;
                }
                break;
              case 7:
                v318 = *(unsigned __int8 *)(i + v406 + 6);
                v319 = *(unsigned __int8 *)(i + v406 + 5);
                v320 = *(unsigned __int8 *)(i + v406 + 4);
                v321 = *(unsigned __int8 *)(i + v406 + 3);
                result->n += 16;
                StringNode = v321 | ((v320 | ((v319 | (v318 << 8)) << 8)) << 8);
                i += 4;
                if ( result->n >= result->uiFlags )
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                v322 = result->n;
                if ( v322 != 0 )
                {
                  *(_BYTE *)v322 = 4;
                  *(_DWORD *)(v322 + 4) = StringNode;
                }
                break;
              case 9:
                v323 = *(unsigned __int16 *)(i + v406 + 3);
                i += 2;
                if ( v323 >= *((_DWORD *)pactBuf + 4) )
                {
                  if ( (v417 & 1) != 0 )
                    GFxActionLogger::LogScriptError(result: &v413, a2: "Error: DictLookup(%d) is out of bounds\n", v323);
LABEL_818:
                  result->n += 16;
                  v327 = result->n;
                  index[0] = 0;
                  if ( v327 >= result->uiFlags )
                    GASPagedStack<GASValue,32>::PushPage(
                      this: (__vc_attributes::iid_isAttribute *)&result->n,
                      a2: *(const char **)&v373[8]);
                  v328 = (GASValue *)result->n;
                  if ( v328 != nullptr )
                    GASValue::GASValue(this: v328, a2: (const struct GASValue *)index);
                  GASValue::`scalar deleting destructor'(this: (GASValue *)index, a2: 0);
                  break;
                }
                v324 = *((_DWORD *)pactBuf + 3);
                result->n += 16;
                HIDWORD(phandler) = v324 + 4 * v323;
                if ( result->n >= result->uiFlags )
                  GASPagedStack<GASValue,32>::PushPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
                StringNode = result->n;
                if ( StringNode != native )
                {
                  v325 = (int *)HIDWORD(phandler);
                  *(_BYTE *)StringNode = 5;
                  v326 = *v325;
                  *(_DWORD *)(StringNode + 4) = *v325;
                  ++*(_DWORD *)(v326 + 8);
                }
                break;
              default:
                break;
            }
            if ( i - (int)pc >= sceneOffset )
              goto LABEL_880;
          }
        }
        nextPc = (char *)++StringNode;
        switch ( v38 )
        {
          case 0u:
            nextPc = v408;
            tryCount = 0;
            goto LABEL_880;
          case 4u:
            if ( (BYTE2(result[4].pdx) & 2) == 0 )
            {
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)result[2].pdx;
              i = *(_DWORD *)StringNode;
              v39 = (*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 316))(a1: StringNode);
              (*(void (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e, int))(i + 324))(
                a1: StringNode,
                a2: v39 + 1);
            }
            goto LABEL_665;
          case 5u:
            if ( (BYTE2(result[4].pdx) & 2) == 0 )
            {
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)result[2].pdx;
              i = *(_DWORD *)StringNode;
              v40 = (*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 316))(a1: StringNode);
              (*(void (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e, int))(i + 324))(
                a1: StringNode,
                a2: v40 - 1);
            }
            goto LABEL_665;
          case 6u:
            if ( (BYTE2(result[4].pdx) & 2) == 0 )
              (*(void (__thiscall **)(int *, _DWORD))(*result[2].pdx + 328))(a1: result[2].pdx, a2: 0);
            goto LABEL_880;
          case 7u:
            if ( (BYTE2(result[4].pdx) & 2) == 0 )
              (*(void (__thiscall **)(int *, int))(*result[2].pdx + 328))(a1: result[2].pdx, a2: 1);
            goto LABEL_880;
          case 9u:
            v41 = (GFxMovieRoot *)(*(int (__thiscall **)(int *))(*result[2].pdx + 84))(a1: result[2].pdx);
            if ( v41 != nullptr )
            {
              LevelMovie = (GFxFontLib *)GFxMovieRoot::GetLevelMovie(this: v41, level: 0);
              if ( LevelMovie != nullptr )
                GFxSprite::StopActiveSounds(this: LevelMovie, a2: *(unsigned int *)&v373[8]);
            }
            goto LABEL_880;
          case 0xAu:
            v43 = (const wchar_t *)result->n;
            v44 = (unsigned int)(v43 - 8);
            if ( v43 <= result->lpstr )
              v44 = result->rcl.left;
            goto LABEL_52;
          case 0xBu:
            v45 = (const wchar_t *)result->n;
            v46 = (unsigned int)(v45 - 8);
            if ( v45 <= result->lpstr )
              v46 = result->rcl.left;
            GASValue::Sub(this: v46, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0xCu:
            v47 = (const wchar_t *)result->n;
            v48 = (unsigned int)(v47 - 8);
            if ( v47 <= result->lpstr )
              v48 = result->rcl.left;
            GASValue::Mul(this: v48, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0xDu:
            v49 = (const wchar_t *)result->n;
            v50 = (unsigned int)(v49 - 8);
            if ( v49 <= result->lpstr )
              v50 = result->rcl.left;
            GASValue::Div(this: v50, penv: (unsigned int)result, v: (_OVERLAPPED *)result->n);
            goto $LN5115;
          case 0xEu:
            v51 = (const wchar_t *)result->n;
            if ( v51 > result->lpstr )
            {
              i = (int)(v51 - 8);
              test = GASValue::IsEqual(
                       this: (GASValue *)v51 - 4,
                       (tagRID_DEVICE_INFO_KEYBOARD *)result,
                       a3: (const struct GASValue *)result->n);
            }
            else
            {
              i = result->rcl.left;
              test = GASValue::IsEqual(
                       this: (GASValue *)i,
                       (tagRID_DEVICE_INFO_KEYBOARD *)result,
                       a3: (const struct GASValue *)result->n);
            }
            goto LABEL_75;
          case 0xFu:
          case 0x48u:
            v52 = (const wchar_t *)result->n;
            v53 = (int)(v52 - 8);
            if ( v52 <= result->lpstr )
              v53 = result->rcl.left;
            i = GASValue::Compare(a1: v53, a2: index, a3: result, a4: result->n, a5: -1);
            GASValue::operator=(v: (tagWNDCLASSW *)i);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            GASValue::~GASValue(this: (GASValue *)i);
            goto LABEL_880;
          case 0x10u:
            if ( (unsigned __int8)GASValue::ToBool(result) == 0
              || (v54 = (unsigned __int8)GASValue::ToBool(result), test = true, v54 == 0) )
            {
              test = false;
            }
            v55 = (const wchar_t *)result->n;
            i = (int)(v55 - 8);
            if ( v55 <= result->lpstr )
              i = result->rcl.left;
LABEL_75:
            GASValue::DropRefs(this: (GASValue *)i);
            v56 = test;
            *(_BYTE *)i = 2;
            *(_BYTE *)(i + 4) = v56;
            goto $LN5115;
          case 0x11u:
            if ( (unsigned __int8)GASValue::ToBool(result) != 0
              || (v57 = (unsigned __int8)GASValue::ToBool(result), test = false, v57 != 0) )
            {
              test = true;
            }
            v58 = (const wchar_t *)result->n;
            i = (int)(v58 - 8);
            if ( v58 <= result->lpstr )
              i = result->rcl.left;
            GASValue::DropRefs(this: (GASValue *)i);
            v59 = test;
            *(_BYTE *)i = 2;
            *(_BYTE *)(i + 4) = v59;
            goto $LN5115;
          case 0x12u:
            StringNode = result->n;
            if ( *(_BYTE *)StringNode == 2 )
            {
              *(_BYTE *)(StringNode + 4) = *(_BYTE *)(StringNode + 4) == 0;
            }
            else if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
            {
              *(_BYTE *)StringNode = 2;
              *(_BYTE *)(StringNode + 4) = 1;
            }
            else
            {
              LOBYTE(i) = (unsigned __int8)GASValue::ToBool(result) == 0;
              GASValue::DropRefs(this: (GASValue *)StringNode);
              *(_BYTE *)StringNode = 2;
              *(_BYTE *)(StringNode + 4) = i;
            }
            goto LABEL_880;
          case 0x13u:
            v60 = (const wchar_t *)result->n;
            v61 = (int)(v60 - 8);
            if ( v60 <= result->lpstr )
              v61 = result->rcl.left;
            v62 = GASValue::ToStringVersioned(a1: v61, a2: &varname, a3: result, a4: Version);
            v63 = result->n;
            reg = v62;
            s2 = (const IClientRenderable *)GASValue::ToStringVersioned(a1: v63, a2: &v402, a3: result, a4: Version);
            v64 = (const wchar_t *)result->n;
            i = (int)(v64 - 8);
            if ( v64 <= result->lpstr )
              i = result->rcl.left;
            test = *(IClientRenderable_vtbl **)reg == s2->__vftable;
            GASValue::DropRefs(this: (GASValue *)i);
            v65 = test;
            *(_BYTE *)i = 2;
            *(_BYTE *)(i + 4) = v65;
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = -1;
            v66 = (*(_DWORD *)(*(_DWORD *)reg + 8))-- == 1;
            if ( !v66 )
              goto LABEL_181;
            GASStringNode::ReleaseNode();
            v66 = s2->GetRenderAngles-- == (const QAngle *(__thiscall *)(IClientRenderable *))1;
            goto LABEL_348;
          case 0x14u:
            v67 = (GASString *)GASValue::ToStringVersioned(a1: result->n, a2: &varname, a3: result, a4: Version);
            i = result->n;
            StringNode = (__vc_attributes::event_receiverAttribute::type_e)v67;
            Length = (tagCOMPAREITEMSTRUCT *)GASString::GetLength(this: v67);
            GASValue::SetInt(this: i, result: Length);
            v69 = *(_DWORD *)StringNode;
            goto LABEL_347;
          case 0x15u:
            v70 = 32 * (result->rcl.right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
            v71 = 0;
            if ( v70 >= 2 )
              v71 = *(_DWORD *)(result->rcl.top + 4 * ((v70 - 2) >> 5)) + 16 * ((v70 - 2) & 0x1F);
            v72 = (const IClientRenderable *)GASValue::ToStringVersioned(a1: v71, a2: &varname, a3: result, a4: Version);
            v73 = (GASValue *)result->n;
            s2 = v72;
            v74 = v73 - 4;
            if ( (const wchar_t *)v73 <= result->lpstr )
              v74 = (GASValue *)result->rcl.left;
            *(_DWORD *)&v373[4] = GASValue::ToInt32(this: v73, a2: (struct GASEnvironment *)result);
            v75 = GASValue::ToInt32(this: v74, a2: (struct GASEnvironment *)result);
            v76 = GASStringProto::StringSubstring(a1: &v402, a2: s2, a3: v75 - 1, a4: *(_DWORD *)&v373[4]);
            v77 = (GASValue *)result->n;
            i = v76;
            if ( (const wchar_t *)(v77 - 8) >= result->lpstr )
              goto LABEL_205;
            for ( reg = 2; reg != 0; --reg )
            {
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
              if ( (const wchar_t *)result->n < result->lpstr )
                GASPagedStack<GASValue,32>::PopPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
            }
            goto LABEL_206;
          case 0x17u:
            goto $LN5115;
          case 0x18u:
            StringNode = result->n;
            v78 = (tagCOMPAREITEMSTRUCT *)GASValue::ToInt32(
                                            this: (GASValue *)StringNode,
                                            a2: (struct GASEnvironment *)result);
            GASValue::SetInt(this: StringNode, result: v78);
            goto LABEL_880;
          case 0x1Cu:
            StringNode = result->n;
            GASValue::ToStringImpl(a1: StringNode, a2: &varname, a3: result, a4: -1, a5: 0);
            v79 = (_DWORD *)result[3].x;
            if ( LOBYTE(result[3].y) <= 6u )
            {
              if ( GASString::CompareBuiltIn_CaseInsensitive(this: v79 + 76, result: &varname) )
              {
LABEL_109:
                v80 = GASNumberUtil::NaN();
                GASValue::SetNumber(this: (GASValue *)StringNode, a2: v80);
                goto LABEL_346;
              }
              if ( GASString::CompareBuiltIn_CaseInsensitive(this: (void *)(result[3].x + 308), result: &varname) )
              {
LABEL_115:
                v81 = GASNumberUtil::POSITIVE_INFINITY();
                GASValue::SetNumber(this: (GASValue *)StringNode, a2: v81);
                goto LABEL_346;
              }
              if ( !GASString::CompareBuiltIn_CaseInsensitive(this: (void *)(result[3].x + 312), result: &varname) )
              {
LABEL_112:
                GASValue::DropRefs(this: (GASValue *)StringNode);
                *(_BYTE *)StringNode = 0;
                GASEnvironment::GetVariable(
                  this: (__vc_attributes::max_isAttribute *)result,
                  &varname,
                  a3: (GASValue *)StringNode,
                  retVal: (unsigned int)v412,
                  paschar: nullptr,
                  a6: nullptr,
                  a7: 0);
                goto LABEL_346;
              }
            }
            else
            {
              if ( varname.N.Name.Short == v79[76] )
                goto LABEL_109;
              if ( varname.N.Name.Short == v79[77] )
                goto LABEL_115;
              if ( varname.N.Name.Short != v79[78] )
                goto LABEL_112;
            }
            v82 = GASNumberUtil::NEGATIVE_INFINITY();
            GASValue::SetNumber(this: (GASValue *)StringNode, a2: v82);
LABEL_346:
            v69 = varname.N.Name.Short;
LABEL_347:
            v66 = (*(_DWORD *)(v69 + 8))-- == 1;
LABEL_348:
            if ( v66 )
LABEL_349:
              GASStringNode::ReleaseNode();
            goto LABEL_880;
          case 0x1Du:
            v83 = (const wchar_t *)result->n;
            v84 = (int)(v83 - 8);
            if ( v83 <= result->lpstr )
              v84 = result->rcl.left;
            GASValue::ToStringImpl(a1: v84, a2: &varname, a3: result, a4: -1, a5: 0);
            GASEnvironment::SetVariable(
              this: (__vc_attributes::propgetAttribute *)result,
              &varname,
              val: (tagWNDCLASSW *)result->n,
              doDisplayErrors: (unsigned __int8 *)v412,
              a5: 1);
            v85 = (GASValue *)result->n;
            if ( (const wchar_t *)(v85 - 8) >= result->lpstr )
              goto LABEL_252;
            for ( i = 2; i != 0; --i )
            {
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
              if ( (const wchar_t *)result->n < result->lpstr )
                GASPagedStack<GASValue,32>::PopPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
            }
            goto LABEL_346;
          case 0x20u:
            GASExecutionContext::SetTargetOpCode(this: (__vc_attributes::uuidAttribute *)&v404);
            goto LABEL_880;
          case 0x21u:
            v86 = (const wchar_t *)result->n;
            v87 = (GASValue *)(v86 - 8);
            if ( v86 <= result->lpstr )
              v87 = (GASValue *)result->rcl.left;
            GASValue::ConvertToStringVersioned(this: v87, a2: (struct GASEnvironment *)result, a3: Version);
            i = GASValue::ToStringVersioned(a1: result->n, a2: &varname, a3: result, a4: Version);
            v88 = (const wchar_t *)result->n;
            v89 = (GASValue *)(v88 - 8);
            if ( v88 <= result->lpstr )
              v89 = (GASValue *)result->rcl.left;
            GASValue::StringConcat(this: v89, a2: (struct GASEnvironment *)result, str: (_IMAGE_SYMBOL_EX *)i);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            v69 = *(_DWORD *)i;
            goto LABEL_347;
          case 0x22u:
            v90 = (const wchar_t *)result->n;
            if ( v90 <= result->lpstr )
              v91 = result->rcl.left;
            else
              v91 = (__vc_attributes::event_receiverAttribute::type_e)(v90 - 8);
            TargetByValue = GASEnvironment::FindTargetByValue(this: (GASEnvironment *)result, path: v91);
            sceneOffset = (int)TargetByValue;
            if ( TargetByValue != nullptr )
            {
              v93 = (GASValue *)result->n;
              v94 = v93 - 4;
              if ( (const wchar_t *)v93 <= result->lpstr )
                v94 = (GASValue *)result->rcl.left;
              i = *(_DWORD *)TargetByValue;
              *(_DWORD *)v373 = v94;
              v95 = GASValue::ToInt32(this: v93, a2: (struct GASEnvironment *)result);
              (*(void (__thiscall **)(int, int, _DWORD, int))(i + 288))(
                a1: sceneOffset,
                a2: v95,
                a3: *(_DWORD *)v373,
                a4: 1);
            }
            else
            {
              v96 = (const wchar_t *)result->n;
              i = (int)(v96 - 8);
              if ( v96 <= result->lpstr )
                i = result->rcl.left;
              GASValue::DropRefs(this: (GASValue *)i);
              *(_BYTE *)i = 0;
            }
            goto $LN5115;
          case 0x23u:
            v97 = 32 * (result->rcl.right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
            v98 = native;
            if ( v97 >= 2 )
              v98 = *(_DWORD *)(result->rcl.top + 4 * ((v97 - 2) >> 5)) + 16 * ((v97 - 2) & 0x1F);
            v99 = GASEnvironment::FindTargetByValue(this: (GASEnvironment *)result, path: v98);
            sceneOffset = (int)v99;
            if ( v99 != nullptr )
            {
              v100 = (const wchar_t *)result->n;
              if ( v100 <= result->lpstr )
                v101 = (GASValue *)result->rcl.left;
              else
                v101 = (GASValue *)(v100 - 8);
              i = *(_DWORD *)v99;
              *(_DWORD *)v373 = result->n;
              v102 = GASValue::ToInt32(this: v101, a2: (struct GASEnvironment *)result);
              (*(void (__thiscall **)(int, int, _DWORD, int))(i + 284))(
                a1: sceneOffset,
                a2: v102,
                a3: *(_DWORD *)v373,
                a4: 1);
            }
            goto LABEL_151;
          case 0x24u:
            v103 = 32 * (result->rcl.right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
            v104 = native;
            if ( v103 >= 2 )
              v104 = *(_DWORD *)(result->rcl.top + 4 * ((v103 - 2) >> 5)) + 16 * ((v103 - 2) & 0x1F);
            i = (int)GASEnvironment::FindTargetByValue(this: (GASEnvironment *)result, path: v104);
            if ( i != 0 )
            {
              v105 = (const wchar_t *)result->n;
              v106 = (int)(v105 - 8);
              if ( v105 <= result->lpstr )
                v106 = result->rcl.left;
              GASValue::ToStringImpl(a1: v106, a2: &varname, a3: result, a4: -1, a5: 0);
              *(_QWORD *)v373 = (unsigned int)result;
              v107 = GASValue::ToInt32(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result);
              GFxASCharacter::CloneDisplayObject(
                this: (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)i,
                newname: &varname,
                depth: v107,
                a4: 0);
              v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
              if ( v66 )
                GASStringNode::ReleaseNode();
            }
LABEL_151:
            GASPagedStack<GASValue,32>::Pop3(
              this: (__vc_attributes::iid_isAttribute *)&result->n,
              a2: *(const char **)&v373[8]);
            goto LABEL_880;
          case 0x25u:
            v108 = GASEnvironment::FindTargetByValue(
                     this: (GASEnvironment *)result,
                     path: (__vc_attributes::event_receiverAttribute::type_e)result->n);
            i = (int)v108;
            if ( v108 != nullptr )
            {
              if ( *((int *)v108 + 5) >= 0x4000 )
              {
                GFxASCharacter::RemoveDisplayObject(this: (GFxASCharacter *)v108);
              }
              else
              {
                v109 = *((_DWORD *)v108 + 37);
                if ( v109 == 0 )
                {
                  GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)i);
                  if ( v109 == 0 )
                    v109 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)i + 108))(a1: i) + 120);
                }
                GFxActionLogger::LogScriptWarning(
                  result: &v413,
                  a2: "removeMovieClip(\"%s\") failed - depth must be >= 0\n",
                  **(const char ***)(v109 + 8));
              }
            }
            goto $LN5115;
          case 0x26u:
            i = (int)GASFnCall::GASFnCall(
                       this: fnCallBuf,
                       a2: (tagALTTABINFO *)result->n,
                       NargsIn: nullptr,
                       a4: (tagALTTABINFO *)result,
                       a5: (tagALTTABINFO *)1,
                       FirstIn: (tagALTTABINFO *)(((signed int)(result->n - (unsigned int)result->lpstr) >> 4)
                                       + 32 * result->rcl.right
                                       - 32));
            *(_DWORD *)&v373[4] = i;
            GAS_GlobalTrace(fn: *(_CONNECTDLGSTRUCTW *)&v373[4]);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            (**(void (__thiscall ***)(int, _DWORD))i)(a1: i, a2: 0);
            goto LABEL_880;
          case 0x27u:
            GASExecutionContext::StartDragOpCode(this: (__vc_attributes::uuidAttribute *)&v404, a2: (const char *)i);
            goto LABEL_880;
          case 0x28u:
            *(_DWORD *)((*(int (__thiscall **)(int *))(*result[2].pdx + 84))(a1: result[2].pdx) + 9188) = 0;
            goto LABEL_880;
          case 0x29u:
            v110 = (const wchar_t *)result->n;
            v111 = (int)(v110 - 8);
            if ( v110 <= result->lpstr )
              v111 = result->rcl.left;
            v112 = (const IClientRenderable *)GASValue::ToStringVersioned(
                                                a1: v111,
                                                a2: &varname,
                                                a3: result,
                                                a4: Version);
            v113 = result->n;
            s2 = v112;
            i = GASValue::ToStringVersioned(a1: v113, a2: &v402, a3: result, a4: Version);
            v114 = (const wchar_t *)result->n;
            if ( v114 <= result->lpstr )
              v115 = result->rcl.left;
            else
              v115 = (int)(v114 - 8);
            reg = v115;
            v116 = (unsigned __int8)GASString::operator<(result: (const _RECTL *)i);
            GASValue::SetBool(this: (GASValue *)reg, val: v116);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = -1;
            v66 = (*(_DWORD *)(*(_DWORD *)i + 8))-- == 1;
            if ( v66 )
              GASStringNode::ReleaseNode();
LABEL_181:
            v66 = s2->GetRenderAngles-- == (const QAngle *(__thiscall *)(IClientRenderable *))1;
            goto LABEL_348;
          case 0x2Au:
            GASEnvironment::CheckTryBlocks(
              this: (__vc_attributes::unhookAttribute *)result,
              pc,
              plocalTryBlockCount: (const char *)&tryCount);
            GASValue::operator=(v: (tagWNDCLASSW *)result->n);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            *(_DWORD *)&v373[4] = v419;
            GASEnvironment::CheckExceptions(
              this: (__vc_attributes::unhookAttribute *)result,
              pactBuf,
              nextPc,
              plocalTryBlockCount: (const char *)&tryCount,
              retval);
            nextPc = v117;
            goto LABEL_880;
          case 0x2Bu:
            GASExecutionContext::CastObjectOpCode(this: (GASExecutionContext *)&v404, a2: (const char *)i);
            goto LABEL_880;
          case 0x2Cu:
            GASExecutionContext::ImplementsOpCode(this: (GASExecutionContext *)&v404);
            goto LABEL_880;
          case 0x30u:
            i = GASValue::ToInt32(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result);
            if ( i < 1 )
              i = 1;
            v118 = (GRefCountBase<GFxAmpCurrentState,2> *)(*(int (__thiscall **)(int *))(*result[2].pdx + 84))(a1: result[2].pdx);
            StringNode = result->n;
            NextRandom = (unsigned int)GASMath::GetNextRandom(result: v118);
            GASValue::SetInt(this: StringNode, result: (tagCOMPAREITEMSTRUCT *)(NextRandom % i));
            goto LABEL_880;
          case 0x31u:
            StringNode = GASValue::ToStringVersioned(a1: result->n, a2: &varname, a3: result, a4: Version);
            v120 = (tagCOMPAREITEMSTRUCT *)GASString::GetLength(this: (GASString *)StringNode);
            GASValue::SetInt(this: result->n, result: v120);
            v69 = *(_DWORD *)StringNode;
            goto LABEL_347;
          case 0x32u:
            GASValue::ToStringImpl(a1: result->n, a2: &varname, a3: result, a4: -1, a5: 0);
            GASValue::SetInt(this: result->n, result: (tagCOMPAREITEMSTRUCT *)**(char **)varname.N.Name.Short);
            v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
            goto LABEL_348;
          case 0x33u:
            v121 = GASValue::ToInt32(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result);
            v122 = result[3].x;
            LOWORD(nargsf) = v121;
            *(_DWORD *)&v373[4] = &nargsf;
            GASStringManager::CreateStringNode(this: *(const char **)(v122 + 636));
            StringNode = v123;
            ++*(_DWORD *)(v123 + 8);
            v124 = (GASValue *)result->n;
            sceneOffset = v123;
            GASValue::SetString(this: v124, str: (_IMAGE_SYMBOL_EX *)&sceneOffset);
            v66 = (*(_DWORD *)(StringNode + 8))-- == 1;
            if ( v66 )
              goto LABEL_349;
            goto LABEL_880;
          case 0x34u:
            v125 = (*(int (__thiscall **)(int *))(*result[2].pdx + 84))(a1: result[2].pdx);
            LODWORD(v126) = GFxMovieRoot::GetASTimerMs(a1: v125, a2: *(float *)&i);
            *(double *)&v381 = fabs(v126);
            nargsf = v126;
            v382 = *(_QWORD *)&v126 & 0x8000000000000000uLL;
            phandler = (double)*(unsigned __int64 *)&v126;
            goto LABEL_300;
          case 0x35u:
            v127 = 32 * (result->rcl.right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
            v128 = 0;
            if ( v127 >= 2 )
              v128 = *(_DWORD *)(result->rcl.top + 4 * ((v127 - 2) >> 5)) + 16 * ((v127 - 2) & 0x1F);
            v129 = (const IClientRenderable *)GASValue::ToStringVersioned(
                                                a1: v128,
                                                a2: &varname,
                                                a3: result,
                                                a4: Version);
            v130 = (GASValue *)result->n;
            s2 = v129;
            v131 = v130 - 4;
            if ( (const wchar_t *)v130 <= result->lpstr )
              v131 = (GASValue *)result->rcl.left;
            *(_DWORD *)&v373[4] = GASValue::ToInt32(this: v130, a2: (struct GASEnvironment *)result);
            v132 = GASValue::ToInt32(this: v131, a2: (struct GASEnvironment *)result);
            v133 = GASStringProto::StringSubstring(a1: &v402, a2: s2, a3: v132 - 1, a4: *(_DWORD *)&v373[4]);
            v77 = (GASValue *)result->n;
            i = v133;
            if ( (const wchar_t *)(v77 - 8) >= result->lpstr )
            {
LABEL_205:
              GASValue::~GASValue(this: v77);
              result->n -= 16;
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
            }
            else
            {
              for ( reg = 2; reg != 0; --reg )
              {
                GASValue::~GASValue(this: (GASValue *)result->n);
                result->n -= 16;
                if ( (const wchar_t *)result->n < result->lpstr )
                  GASPagedStack<GASValue,32>::PopPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
              }
            }
LABEL_206:
            GASValue::SetString(this: (GASValue *)result->n, str: (_IMAGE_SYMBOL_EX *)i);
            StringNode = -1;
            v66 = s2->GetRenderAngles-- == (const QAngle *(__thiscall *)(IClientRenderable *))1;
            if ( v66 )
              GASStringNode::ReleaseNode();
            v66 = (*(_DWORD *)(*(_DWORD *)i + 8))-- == 1;
            goto LABEL_348;
          case 0x36u:
            StringNode = GASValue::ToStringVersioned(a1: result->n, a2: &varname, a3: result, a4: Version);
            if ( *(_DWORD *)(*(_DWORD *)StringNode + 16) != 0 )
            {
              *(_DWORD *)&v373[4] = 0;
              LOWORD(v134) = GASString::GetCharAt();
              GASValue::SetInt(this: result->n, result: v134);
            }
            else
            {
              GASValue::SetInt(this: result->n, result: nullptr);
            }
            v69 = *(_DWORD *)StringNode;
            goto LABEL_347;
          case 0x37u:
            LODWORD(nargsf) = (unsigned __int16)GASValue::ToUInt32(
                                                  this: (GASValue *)result->n,
                                                  a2: (struct GASEnvironment *)result);
            StringNode = (__vc_attributes::event_receiverAttribute::type_e)GASStringManager::CreateStringNode(
                                                                             this: *(GASStringManager **)(result[3].x + 636),
                                                                             a2: (const wchar_t *)&nargsf);
            ++*(_DWORD *)(StringNode + 8);
            v135 = (GASValue *)result->n;
            sceneOffset = StringNode;
            GASValue::SetString(this: v135, str: (_IMAGE_SYMBOL_EX *)&sceneOffset);
            v66 = (*(_DWORD *)(StringNode + 8))-- == 1;
            if ( v66 )
              goto LABEL_349;
            goto LABEL_880;
          case 0x3Au:
            v136 = (const wchar_t *)result->n;
            LOBYTE(retVal) = 0;
            i = (int)(v136 - 8);
            if ( v136 <= result->lpstr )
              i = result->rcl.left;
            GASValue::ToStringImpl(a1: v136, a2: &varname, a3: result, a4: -1, a5: 0);
            if ( Version <= 6u && (*(_BYTE *)i == 1 || LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0) )
            {
              index[0] = 0;
              if ( GASEnvironment::FindOwnerOfMember(
                     this: (tagBITMAPCOREHEADER **)result,
                     a2: (int)&varname,
                     a3: (GASValue *)index,
                     a4: v412) != 0 )
              {
                v137 = GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
                if ( v137 != nullptr )
                  LOBYTE(retVal) = (*(int (__thiscall **)(_SERVICE_STATUS *, tagPOLYTEXTW *, _IMAGE_SYMBOL_EX *))(v137->dwServiceType + 24))(
                                     a1: v137,
                                     a2: result + 3,
                                     a3: &varname);
              }
              GASValue::~GASValue(this: (GASValue *)index);
            }
            else
            {
              v138 = GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
              if ( v138 != nullptr )
                LOBYTE(retVal) = (*(int (__thiscall **)(_SERVICE_STATUS *, tagPOLYTEXTW *, _IMAGE_SYMBOL_EX *))(v138->dwServiceType + 24))(
                                   a1: v138,
                                   a2: result + 3,
                                   a3: &varname);
            }
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            GASValue::SetBool(this: (GASValue *)result->n, val: retVal);
            v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
            goto LABEL_348;
          case 0x3Bu:
            GASValue::ToStringImpl(a1: result->n, a2: &varname, a3: result, a4: -1, a5: 0);
            index[0] = 0;
            if ( (*(_DWORD *)(varname.N.Name.Short + 12) & 0x2000000) != 0
              || GASEnvironment::IsPath(varPath: &varname) == 0 )
            {
              if ( GASEnvironment::FindOwnerOfMember(
                     this: (tagBITMAPCOREHEADER **)result,
                     a2: (int)&varname,
                     a3: (GASValue *)index,
                     a4: v412) == 0 )
                goto LABEL_233;
            }
            else
            {
              VarParams = (const struct GASEnvironment::GetVarParams *)GASEnvironment::GetVarParams::GetVarParams(
                                                                         this: &v373[20],
                                                                         a2: (int)&varname,
                                                                         a3: 0,
                                                                         a4: (int)v412,
                                                                         a5: 0,
                                                                         a6: (int)index,
                                                                         a7: 0);
              if ( GASEnvironment::FindVariable(
                     this: (tagBITMAPCOREHEADER **)result,
                     a2: VarParams,
                     onlyTargets: false,
                     varName: (struct GASString *)&varname) == 0
                || LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
              {
LABEL_233:
                v140 = (GASValue *)result->n;
                *(_DWORD *)&v373[4] = 0;
                goto LABEL_234;
              }
            }
            v141 = GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
            if ( v141 == nullptr )
              goto LABEL_233;
            StringNode = result->n;
            *(_DWORD *)&v373[4] = (*(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *, tagPOLYTEXTW *, _IMAGE_SYMBOL_EX *))(v141->dwServiceType + 24))(
                                    a1: v141,
                                    a2: result + 3,
                                    a3: &varname);
            v140 = (GASValue *)StringNode;
LABEL_234:
            GASValue::SetBool(this: v140, val: v373[4]);
            v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
            if ( v66 )
              GASStringNode::ReleaseNode();
LABEL_236:
            GASValue::~GASValue(this: (GASValue *)index);
            goto LABEL_880;
          case 0x3Cu:
            v142 = (const wchar_t *)result->n;
            v143 = (int)(v142 - 8);
            if ( v142 <= result->lpstr )
              v143 = result->rcl.left;
            GASValue::ToStringImpl(a1: v143, a2: &varname, a3: result, a4: -1, a5: 0);
            if ( (v417 & 4) != 0 || v419 == 1 )
              GASEnvironment::SetLocal(this: (GASEnvironment *)result, &varname, val: (tagWNDCLASSW *)result->n);
            else
              GASEnvironment::SetVariable(
                this: (__vc_attributes::propgetAttribute *)result,
                &varname,
                val: (tagWNDCLASSW *)result->n,
                doDisplayErrors: (unsigned __int8 *)v412,
                a5: 1);
            v85 = (GASValue *)result->n;
            if ( (const wchar_t *)(v85 - 8) >= result->lpstr )
            {
LABEL_252:
              GASValue::~GASValue(this: v85);
              result->n -= 16;
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
            }
            else
            {
              for ( i = 2; i != 0; --i )
              {
                GASValue::~GASValue(this: (GASValue *)result->n);
                result->n -= 16;
                if ( (const wchar_t *)result->n < result->lpstr )
                  GASPagedStack<GASValue,32>::PopPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
              }
            }
            goto LABEL_346;
          case 0x3Du:
            v144 = (tagWNDCLASSW *)result->n;
            i = (int)&result->n;
            index[0] = 0;
            LOBYTE(v431[0].__vftable) = 0;
            v66 = LOBYTE(v144->style) == 5;
            s2 = (const IClientRenderable *)index;
            test = true;
            if ( v66 )
            {
              GASValue::ToStringImpl(a1: v144, a2: &varname, a3: result, a4: -1, a5: 0);
              GASEnvironment::GetVariable(
                this: (__vc_attributes::max_isAttribute *)result,
                &varname,
                a3: (GASValue *)index,
                retVal: (unsigned int)v412,
                paschar: nullptr,
                a6: v431,
                a7: 0);
              if ( LOBYTE(GASValue::IsFunction().usPreferredNode) == 0 )
              {
                if ( index[0] != 6 )
                  goto LABEL_263;
                v145 = GASValue::ToObject(this: (GASValue *)index, a2: (const struct GASEnvironment *)result);
                StringNode = (__vc_attributes::event_receiverAttribute::type_e)v145;
                if ( v145 != nullptr )
                  v145[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v145[1].pNode->pNext + 1) & 0x8FFFFFFF);
                if ( v422 != nullptr )
                  GRefCountBaseGC<323>::Release(a1: (int)v422, a2: (int)v145);
                v422 = (struct GASObject *)StringNode;
                if ( StringNode != native
                  && (*(unsigned __int8 (__thiscall **)(__int32))(*(_DWORD *)(StringNode + 16) + 60))(a1: StringNode + 16) != 0 )
                {
                  GASValue::~GASValue(this: (GASValue *)index);
                  sceneOffset = (*(int (__thiscall **)(__int32, GAtomicInt<unsigned long> *, tagPOLYTEXTW *))(*(_DWORD *)(StringNode + 16) + 56))(
                                  a1: StringNode + 16,
                                  a2: &funcBuf,
                                  a3: result + 3);
                  s2 = (const IClientRenderable *)GASValue::GASValue(
                                                    this: (GASValue *)index,
                                                    a2: (const struct GASFunctionRef *)sceneOffset);
                  GASFunctionRef::`scalar deleting destructor'();
                  GASValue::SetAsObject(this: (GASValue *)v431, a2: (struct GASObject *)StringNode);
                }
                else
                {
LABEL_263:
                  if ( (v417 & 1) != 0 )
                    GFxActionLogger::LogScriptError(
                      result: &v413,
                      a2: "Error: CallFunction - '%s' is not a function\n",
                      *(const char **)varname.N.Name.Short);
                  test = false;
                }
                if ( v422 != nullptr )
                  GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
                v422 = nullptr;
              }
              v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
              if ( v66 )
                GASStringNode::ReleaseNode();
            }
            else
            {
              GASValue::operator=(v: v144);
            }
            v146 = (GASValue *)(*(_DWORD *)i - 16);
            if ( (const wchar_t *)result->n <= result->lpstr )
              v146 = (GASValue *)result->rcl.left;
            nargsf = GASValue::ToNumber(this: v146, a2: (struct GASEnvironment *)result);
            *(double *)v373 = nargsf;
            GASNumberUtil::IsNaNOrInfinity(v: v147);
            if ( v148 != 0 )
              reg = 0;
            else
              reg = (int)nargsf;
            varname.N.ShortName[4] = 0;
            if ( test )
            {
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
              v149 = (struct GASObjectInterface *)GASValue::ToFunction(a1: &funcBuf, a2: result);
              v66 = *(_DWORD *)v149 == 0;
              NargsIn = v149;
              if ( v66 )
              {
                if ( (*(unsigned __int8 (__thiscall **)(tagPOLYTEXTW *))(result->x + 4))(a1: result) != 0 )
                  GASEnvironment::LogScriptError(
                    this: (GASEnvironment *)result,
                    a2: "Error: CallFunction - attempt to call invalid function\n");
              }
              else
              {
                StringNode = (__vc_attributes::event_receiverAttribute::type_e)GASFnCall::GASFnCall(
                                                                                 this: fnCallBuf,
                                                                                 a2: (tagALTTABINFO *)&varname.N.LongName[1],
                                                                                 NargsIn: (tagALTTABINFO *)StringNode,
                                                                                 a4: (tagALTTABINFO *)result,
                                                                                 a5: (tagALTTABINFO *)reg,
                                                                                 FirstIn: (tagALTTABINFO *)(((signed int)(result->n - (unsigned int)result->lpstr) >> 4)
                                                                                                 + 32
                                                                                                 * result->rcl.right
                                                                                                 - 34));
                (*(void (__thiscall **)(_DWORD, __vc_attributes::event_receiverAttribute::type_e, _DWORD, _DWORD))(**(_DWORD **)NargsIn + 40))(
                  a1: *(_DWORD *)NargsIn,
                  a2: StringNode,
                  a3: *((_DWORD *)NargsIn + 1),
                  a4: 0);
                (**(void (__thiscall ***)(__vc_attributes::event_receiverAttribute::type_e, _DWORD))StringNode)(
                  a1: StringNode,
                  a2: 0);
              }
              *(_DWORD *)&v373[4] = 0;
              GASFunctionRef::`scalar deleting destructor'();
            }
            GASPagedStack<GASValue,32>::Pop(result: (__vc_attributes::readonlyAttribute *)(reg + 1));
            GASValue::operator=(v: (tagWNDCLASSW *)&varname.N.LongName[1]);
            GASValue::~GASValue(this: (GASValue *)v431);
            GASValue::~GASValue(this: (GASValue *)s2);
            GASValue::~GASValue(this: (GASValue *)&varname.N.Name.Long);
            goto LABEL_663;
          case 0x3Eu:
            if ( retval != nullptr )
              GASValue::operator=(v: (tagWNDCLASSW *)result->n);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            goto LABEL_879;
          case 0x3Fu:
            phandler = GASValue::ToNumber(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result);
            v150 = (const wchar_t *)result->n;
            v151 = (GASValue *)(v150 - 8);
            if ( v150 <= result->lpstr )
              v151 = (GASValue *)result->rcl.left;
            v152 = GASValue::ToNumber(this: v151, a2: (struct GASEnvironment *)result);
            if ( 0.0 == phandler )
              v153 = GASNumberUtil::NaN();
            else
              v153 = fmod(v152, phandler);
            v154 = (GASValue *)result->n;
            phandler = v153;
            if ( (const wchar_t *)(v154 - 8) >= result->lpstr )
            {
              GASValue::~GASValue(this: v154);
              result->n -= 16;
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
            }
            else
            {
              for ( i = 2; i != 0; --i )
              {
                GASValue::~GASValue(this: (GASValue *)result->n);
                result->n -= 16;
                if ( (const wchar_t *)result->n < result->lpstr )
                  GASPagedStack<GASValue,32>::PopPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
              }
            }
LABEL_300:
            result->n += 16;
            if ( result->n >= result->uiFlags )
              GASPagedStack<GASValue,32>::PushPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = result->n;
            if ( StringNode != native )
            {
              v155 = phandler;
              *(_BYTE *)StringNode = 3;
              *(long double *)(StringNode + 4) = v155;
            }
            goto LABEL_880;
          case 0x40u:
            GASValue::ToStringImpl(a1: result->n, a2: &varname, a3: result, a4: -1, a5: 0);
            v156 = (const wchar_t *)result->n;
            v157 = (GASValue *)(v156 - 8);
            if ( v156 <= result->lpstr )
              v157 = (GASValue *)result->rcl.left;
            nargsf = GASValue::ToNumber(this: v157, a2: (struct GASEnvironment *)result);
            *(double *)v373 = nargsf;
            GASNumberUtil::IsNaNOrInfinity(v: v158);
            if ( v159 != 0 )
              reg = 0;
            else
              reg = (int)nargsf;
            v160 = (GASValue *)result->n;
            if ( (const wchar_t *)(v160 - 8) >= result->lpstr )
            {
              GASValue::~GASValue(this: v160);
              result->n -= 16;
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
            }
            else
            {
              for ( j = 2; j != 0; --j )
              {
                GASValue::~GASValue(this: (GASValue *)result->n);
                result->n -= 16;
                if ( (const wchar_t *)result->n < result->lpstr )
                  GASPagedStack<GASValue,32>::PopPage(
                    this: (__vc_attributes::iid_isAttribute *)&result->n,
                    a2: *(const char **)&v373[8]);
              }
            }
            if ( v422 != nullptr )
              GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
            i = 0;
            index[0] = 0;
            GASEnvironment::GetVariable(
              this: (__vc_attributes::max_isAttribute *)result,
              &varname,
              a3: (GASValue *)index,
              retVal: (unsigned int)v412,
              paschar: nullptr,
              a6: nullptr,
              a7: 0);
            if ( v162 != 0 && LOBYTE(GASValue::IsFunction().usPreferredNode) != 0 )
            {
              sceneOffset = GASValue::ToFunction(a1: &funcBuf, a2: result);
              i = (int)GASEnvironment::OperatorNew(
                         this: (__vc_attributes::idl_quoteAttribute *)result,
                         a2: (const struct GASFunctionRef *)sceneOffset,
                         nargs: reg,
                         argsTopOff: -1);
              if ( i == 0 && (v417 & 1) != 0 )
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: "Error: can't create object with unknown class '%s'\n",
                  *(const char **)varname.N.Name.Short);
              *(_DWORD *)&v373[4] = 0;
              GASFunctionRef::`scalar deleting destructor'();
            }
            else if ( (v417 & 1) != 0 )
            {
              GFxActionLogger::LogScriptError(
                result: &v413,
                a2: "Error: can't create object with unknown class '%s'\n",
                *(const char **)varname.N.Name.Short);
            }
            GASPagedStack<GASValue,32>::Pop(result: (__vc_attributes::readonlyAttribute *)reg);
            result->n += 16;
            v163 = result->n;
            if ( i != 0 )
            {
              if ( v163 >= result->uiFlags )
                GASPagedStack<GASValue,32>::PushPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
              StringNode = result->n;
              if ( StringNode != native )
                GASValue::GASValue(this: (GASValue *)StringNode, a2: (struct GASObject *)i);
              GRefCountBaseGC<323>::Release(a1: i, a2: StringNode);
            }
            else
            {
              LOBYTE(v431[0].__vftable) = 0;
              if ( v163 >= result->uiFlags )
                GASPagedStack<GASValue,32>::PushPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
              StringNode = result->n;
              if ( StringNode != native )
                GASValue::GASValue(this: (GASValue *)StringNode, a2: (const struct GASValue *)v431);
              GASValue::~GASValue(this: (GASValue *)v431);
            }
            v422 = nullptr;
            GASValue::~GASValue(this: (GASValue *)index);
            v66 = (*(_DWORD *)(varname.N.Name.Short + 8))-- == 1;
            if ( v66 )
              GASStringNode::ReleaseNode();
            if ( LOBYTE(result[4].uiFlags) == 10 )
              goto LABEL_878;
            goto LABEL_335;
          case 0x41u:
            GASValue::ToStringImpl(a1: result->n, a2: &varname, a3: result, a4: -1, a5: 0);
            if ( (v417 & 4) != 0 || v419 == 1 )
              GASEnvironment::DeclareLocal(this: (int)result, result: &varname);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            goto LABEL_346;
          case 0x42u:
            v165 = GASValue::ToNumber(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result);
            v166 = (GASValue *)result->n;
            reg = (int)v165;
            GASValue::~GASValue(this: v166);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            *(_DWORD *)&v373[4] = ((signed int)(result->n - (unsigned int)result->lpstr) >> 4)
                                + 32 * result->rcl.right
                                - 32;
            index[0] = 0;
            i = (int)GASFnCall::GASFnCall(
                       this: fnCallBuf,
                       a2: (tagALTTABINFO *)index,
                       NargsIn: nullptr,
                       a4: (tagALTTABINFO *)result,
                       a5: (tagALTTABINFO *)reg,
                       FirstIn: *(tagALTTABINFO **)&v373[4]);
            *(_DWORD *)&v373[4] = i;
            GASArrayCtorFunction::DeclareArray(fn: v167);
            (**(void (__thiscall ***)(int, _DWORD))i)(a1: i, a2: 0);
            if ( reg > 0 )
              GASPagedStack<GASValue,32>::Pop(result: (__vc_attributes::readonlyAttribute *)reg);
            result->n += 16;
            if ( result->n >= result->uiFlags )
              GASPagedStack<GASValue,32>::PushPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = result->n;
            if ( StringNode != native )
              GASValue::GASValue(this: (GASValue *)StringNode, a2: (const struct GASValue *)index);
            goto LABEL_236;
          case 0x43u:
            v168 = (const IClientRenderable *)(int)GASValue::ToNumber(
                                                     this: (GASValue *)result->n,
                                                     a2: (struct GASEnvironment *)result);
            reg = (int)GASEnvironment::OperatorNew(
                         this: (__vc_attributes::idl_quoteAttribute *)result,
                         a2: StringNode,
                         a3: *(struct GASObject **)(result[3].x + 680),
                         a4: (const struct GASString *)(result[3].x + 12),
                         nargs: 0,
                         argsTopOff: -1);
            if ( v422 != nullptr )
              GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            if ( reg != 0 && (int)v168 > 0 )
            {
              for ( s2 = v168; s2 != nullptr; s2 = (const IClientRenderable *)((char *)s2 - 1) )
              {
                if ( ((signed int)(result->n - (unsigned int)result->lpstr) >> 4) + 32 * result->rcl.right - 32 >= 1 )
                {
                  v169 = (const wchar_t *)result->n;
                  if ( v169 <= result->lpstr )
                    v170 = (const wchar_t *)result->rcl.left;
                  else
                    v170 = v169 - 8;
                  if ( *(_BYTE *)v170 == 5 )
                  {
                    v171 = (const wchar_t *)result->n;
                    if ( v171 <= result->lpstr )
                      v172 = result->rcl.left;
                    else
                      v172 = (int)(v171 - 8);
                    GASValue::ToStringImpl(a1: v172, a2: &varname, a3: result, a4: -1, a5: 0);
                    *(_DWORD *)&v373[4] = &v397;
                    *(_DWORD *)v373 = result->n;
                    v397 = 0;
                    (*(void (__thiscall **)(int, tagPOLYTEXTW *, _IMAGE_SYMBOL_EX *, _DWORD, char *))(*(_DWORD *)(reg + 16) + 12))(
                      a1: reg + 16,
                      a2: result,
                      a3: &varname,
                      a4: *(_DWORD *)v373,
                      a5: &v397);
                    *(_DWORD *)&v373[4] = 0;
                    GASString::`scalar deleting destructor'();
                  }
                  v173 = (GASValue *)result->n;
                  if ( (const wchar_t *)(v173 - 8) >= result->lpstr )
                  {
                    GASValue::~GASValue(this: v173);
                    result->n -= 16;
                    GASValue::~GASValue(this: (GASValue *)result->n);
                    result->n -= 16;
                  }
                  else
                  {
                    for ( k = 2; k != 0; --k )
                    {
                      GASValue::~GASValue(this: (GASValue *)result->n);
                      result->n -= 16;
                      if ( (const wchar_t *)result->n < result->lpstr )
                        GASPagedStack<GASValue,32>::PopPage(
                          this: (__vc_attributes::iid_isAttribute *)&result->n,
                          a2: *(const char **)&v373[8]);
                    }
                  }
                }
              }
            }
            result->n += 16;
            if ( result->n >= result->uiFlags )
              GASPagedStack<GASValue,32>::PushPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = result->n;
            i = reg;
            if ( StringNode != native )
              GASValue::GASValue(this: (GASValue *)StringNode, a2: (struct GASObject *)reg);
            if ( i != 0 )
              GRefCountBaseGC<323>::Release(a1: i, a2: StringNode);
            v66 = LOBYTE(result[4].uiFlags) == 10;
            v422 = nullptr;
            if ( v66 )
              goto LABEL_878;
LABEL_335:
            GASEnvironment::CheckTryBlocks(
              this: (__vc_attributes::unhookAttribute *)result,
              pc,
              plocalTryBlockCount: (const char *)&tryCount);
            *(_DWORD *)&v373[4] = v419;
            GASEnvironment::CheckExceptions(
              this: (__vc_attributes::unhookAttribute *)result,
              pactBuf,
              nextPc,
              plocalTryBlockCount: (const char *)&tryCount,
              retval);
            nextPc = v164;
            goto LABEL_878;
          case 0x44u:
            i = result->n;
            StringNode = 51;
            switch ( *(_BYTE *)i )
            {
              case 0:
              case 0xA:
                break;
              case 1:
                StringNode = 52;
                break;
              case 2:
                StringNode = 57;
                break;
              case 5:
                StringNode = 55;
                break;
              case 6:
                goto $LN262;
              case 7:
                v175 = GASValue::ToASCharacter(this: (GASValue *)i, a2: (const struct GASEnvironment *)result);
                if ( v175 == nullptr
                  || (*(int (__thiscall **)(int))(*((_DWORD *)v175 + 30) + 8))(a1: (int)v175 + 120) == 2 )
                {
                  StringNode = 58;
                }
                else
                {
$LN262:
                  StringNode = 59;
                }
                break;
              case 8:
                StringNode = 60;
                break;
              default:
                if ( LOBYTE(GASValue::IsNumber().usPreferredNode) != 0 )
                {
                  StringNode = 56;
                }
                else if ( (v417 & 1) != 0 )
                {
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: typeof unknown: %02X\n",
                    *(unsigned __int8 *)i);
                }
                break;
            }
            GASValue::SetString(
              this: (GASValue *)result->n,
              str: (_IMAGE_SYMBOL_EX *)(result[3].x + 4 * StringNode + 8));
            goto LABEL_880;
          case 0x45u:
            v176 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASValue::ToASCharacter(this: (GASValue *)result->n, a2: (const struct GASEnvironment *)result);
            if ( v176 != nullptr )
            {
              if ( DWORD1(v176[6].m_pfnProxied) != 0 )
              {
                GASValue::SetString(
                  this: (GASValue *)result->n,
                  str: (_IMAGE_SYMBOL_EX *)(DWORD1(v176[6].m_pfnProxied) + 12));
              }
              else
              {
                GFxASCharacter::CreateCharacterHandle(this: v176);
                GASValue::SetString(this: (GASValue *)result->n, str: (_IMAGE_SYMBOL_EX *)(v177 + 12));
              }
            }
            else
            {
              StringNode = result->n;
              GASValue::DropRefs(this: (GASValue *)StringNode);
              *(_BYTE *)StringNode = 0;
            }
            goto LABEL_880;
          case 0x46u:
          case 0x55u:
            GASExecutionContext::EnumerateOpCode(this: &v404, actionId: v38);
            goto LABEL_880;
          case 0x47u:
            v178 = (const wchar_t *)result->n;
            v44 = (unsigned int)(v178 - 8);
            if ( v178 <= result->lpstr )
              v44 = result->rcl.left;
LABEL_52:
            GASValue::Add(this: v44, penv: (unsigned int)result, v: (_OVERLAPPED *)result->n);
            goto $LN5115;
          case 0x49u:
            v179 = (const wchar_t *)result->n;
            if ( v179 > result->lpstr )
            {
              i = (int)(v179 - 8);
              *(_DWORD *)&v373[4] = GASValue::IsEqual(
                                      this: (GASValue *)v179 - 4,
                                      (tagRID_DEVICE_INFO_KEYBOARD *)result,
                                      a3: (const struct GASValue *)result->n);
            }
            else
            {
              i = result->rcl.left;
              *(_DWORD *)&v373[4] = GASValue::IsEqual(
                                      this: (GASValue *)i,
                                      (tagRID_DEVICE_INFO_KEYBOARD *)result,
                                      a3: (const struct GASValue *)result->n);
            }
            v180 = (GASValue *)i;
            goto LABEL_692;
          case 0x4Au:
            GASValue::ConvertToNumber((_JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION *)result);
            goto LABEL_880;
          case 0x4Bu:
            GASValue::ConvertToStringVersioned(
              this: (GASValue *)result->n,
              a2: (struct GASEnvironment *)result,
              a3: Version);
            goto LABEL_880;
          case 0x4Cu:
            i = result->n;
            result->n = i + 16;
            if ( result->n >= result->uiFlags )
              GASPagedStack<GASValue,32>::PushPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = result->n;
            if ( StringNode != native )
              GASValue::GASValue(this: (GASValue *)StringNode, a2: (const struct GASValue *)i);
            goto LABEL_880;
          case 0x4Du:
            v181 = (const wchar_t *)result->n;
            if ( v181 <= result->lpstr )
              v182 = (const struct GASValue *)result->rcl.left;
            else
              v182 = (const struct GASValue *)(v181 - 8);
            StringNode = (__vc_attributes::event_receiverAttribute::type_e)GASValue::GASValue(
                                                                             this: (GASValue *)index,
                                                                             a2: v182);
            GASValue::operator=(v: (tagWNDCLASSW *)result->n);
            GASValue::operator=(v: (tagWNDCLASSW *)StringNode);
            GASValue::~GASValue(this: (GASValue *)StringNode);
            goto LABEL_880;
          case 0x4Eu:
            v183 = (const wchar_t *)result->n;
            if ( v183 <= result->lpstr )
              StringNode = result->rcl.left;
            else
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)(v183 - 8);
            i = result->n;
            reg = (int)GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
            if ( reg == 0 )
            {
              GASEnvironment::PrimitiveToTempObject(
                this: (__vc_attributes::idl_quoteAttribute *)result,
                (GASValue *)index,
                indexa: 1u);
              sceneOffset = (int)v184;
              v185 = GASValue::ToObject(this: v184, a2: (const struct GASEnvironment *)result);
              if ( v185 == nullptr || (reg = (int)&v185[2], v185 == (struct GASObject *)-16) )
              {
                GASValue::DropRefs(this: (GASValue *)StringNode);
                v186 = (GASValue *)sceneOffset;
                *(_BYTE *)StringNode = 0;
                GASValue::~GASValue(this: v186);
              }
              else
              {
                GASValue::ToStringImpl(a1: i, a2: &varname, a3: result, a4: -1, a5: 0);
                if ( !GASEnvironment::GetMember(
                        this: (GASEnvironment *)result,
                        memberName: (_IMAGE_SYMBOL_EX *)reg,
                        a3: (GASValue *)&varname,
                        a4: (struct GASValue *)StringNode) )
                {
                  GASValue::DropRefs(this: (GASValue *)StringNode);
                  *(_BYTE *)StringNode = 0;
                }
                *(_DWORD *)&v373[4] = 0;
                GASString::`scalar deleting destructor'();
                GASValue::~GASValue(this: (GASValue *)sceneOffset);
              }
              goto LABEL_465;
            }
            if ( LOBYTE(GASValue::IsNumber().usPreferredNode) != 0
              && (*(int (__thiscall **)(int))(*(_DWORD *)reg + 8))(a1: reg) == 7 )
            {
              v66 = reg == 16;
              v187 = reg - 16;
              reg -= 16;
              if ( !v66 )
                *(_DWORD *)(v187 + 8) = (*(_DWORD *)(v187 + 8) + 1) & 0x8FFFFFFF;
              if ( v422 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
              v188 = (int)GASValue::ToNumber(this: (GASValue *)i, a2: (struct GASEnvironment *)result);
              if ( v188 >= 0 )
              {
                i = reg;
                if ( v188 >= *(_DWORD *)(reg + 60) )
                {
                  v190 = (GASValue *)StringNode;
                }
                else
                {
                  v189 = *(tagWNDCLASSW **)(*(_DWORD *)(reg + 56) + 4 * v188);
                  v190 = (GASValue *)StringNode;
                  if ( v189 != nullptr )
                  {
                    GASValue::operator=(v: v189);
                    goto LABEL_462;
                  }
                }
                GASValue::DropRefs(this: v190);
                *(_BYTE *)StringNode = 0;
              }
              else
              {
                GASValue::ToStringImpl(a1: i, a2: &varname, a3: result, a4: -1, a5: 0);
                *(_DWORD *)&v373[4] = StringNode;
                if ( (unsigned __int8)GASObject::GetMember(
                                        this: (D3DXQUATERNION *)(reg + 16),
                                        (D3DXQUATERNION *)result,
                                        penv: (const D3DXQUATERNION *)&varname) == 0 )
                {
                  GASValue::DropRefs(this: (GASValue *)StringNode);
                  *(_BYTE *)StringNode = 0;
                }
                *(_DWORD *)&v373[4] = 0;
                GASString::`scalar deleting destructor'();
                i = reg;
              }
            }
            else
            {
              GASValue::ToStringImpl(a1: i, a2: &varname, a3: result, a4: -1, a5: 0);
              if ( *(_BYTE *)StringNode == 6 || LOBYTE(GASValue::IsFunction().usPreferredNode) != 0 )
              {
                v191 = GASValue::ToObject(this: (GASValue *)StringNode, a2: (const struct GASEnvironment *)result);
                i = (int)v191;
                if ( v191 != nullptr )
                  v191[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v191[1].pNode->pNext + 1) & 0x8FFFFFFF);
                if ( v422 != nullptr )
                  GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
                v422 = (struct GASObject *)i;
              }
              else
              {
                i = (int)v422;
              }
              GASValue::DropRefs(this: (GASValue *)StringNode);
              v369 = (_IMAGE_SYMBOL_EX *)reg;
              *(_BYTE *)StringNode = 0;
              GASEnvironment::GetMember(
                this: (GASEnvironment *)result,
                memberName: v369,
                a3: (GASValue *)&varname,
                a4: (struct GASValue *)StringNode);
              *(_DWORD *)&v373[4] = 0;
              GASString::`scalar deleting destructor'();
            }
LABEL_462:
            if ( i != 0 )
              GRefCountBaseGC<323>::Release(a1: i, a2: StringNode);
            v422 = nullptr;
LABEL_465:
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            if ( LOBYTE(result[4].uiFlags) != 10 )
              goto LABEL_468;
            goto LABEL_880;
          case 0x4Fu:
            i = (int)GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
            if ( i == 0 )
              goto LABEL_480;
            v193 = (const wchar_t *)result->n;
            if ( v193 <= result->lpstr )
              v194 = result->rcl.left;
            else
              v194 = (int)(v193 - 8);
            reg = v194;
            if ( LOBYTE(GASValue::IsNumber().usPreferredNode) != 0
              && (*(int (__thiscall **)(int))(*(_DWORD *)i + 8))(a1: i) == 7 )
            {
              i -= 16;
              v195 = GASValue::ToNumber(this: (GASValue *)reg, a2: (struct GASEnvironment *)result);
              if ( (int)v195 >= 0 )
              {
                GASArrayObject::SetElementSafe(
                  this: (GASArrayObject *)i,
                  a2: (int)v195,
                  a3: (const struct GASValue *)result->n);
                goto LABEL_480;
              }
              GASValue::ToStringImpl(a1: reg, a2: &varname, a3: result, a4: -1, a5: 0);
              *(_DWORD *)&v373[4] = &v396;
              v396 = 0;
              GASObject::SetMember(this: (CTSQueue<CFunctor *,0,1> *)(i + 16));
            }
            else
            {
              GASValue::ToStringImpl(a1: reg, a2: &varname, a3: result, a4: -1, a5: 0);
              *(_DWORD *)&v373[4] = &v398;
              *(_DWORD *)v373 = result->n;
              v398 = 0;
              (*(void (__thiscall **)(int, tagPOLYTEXTW *, _IMAGE_SYMBOL_EX *, _DWORD, char *))(*(_DWORD *)i + 12))(
                a1: i,
                a2: result,
                a3: &varname,
                a4: *(_DWORD *)v373,
                a5: &v398);
            }
            *(_DWORD *)&v373[4] = 0;
            GASString::`scalar deleting destructor'();
LABEL_480:
            GASPagedStack<GASValue,32>::Pop3(
              this: (__vc_attributes::iid_isAttribute *)&result->n,
              a2: *(const char **)&v373[8]);
            if ( LOBYTE(result[4].uiFlags) != 10 )
            {
LABEL_468:
              GASEnvironment::CheckTryBlocks(
                this: (__vc_attributes::unhookAttribute *)result,
                pc,
                plocalTryBlockCount: (const char *)&tryCount);
              *(_DWORD *)&v373[4] = v419;
              GASEnvironment::CheckExceptions(
                this: (__vc_attributes::unhookAttribute *)result,
                pactBuf,
                nextPc,
                plocalTryBlockCount: (const char *)&tryCount,
                retval);
              nextPc = v192;
            }
            goto LABEL_880;
          case 0x50u:
            GASValue::Add(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result, v2: 1);
            goto LABEL_880;
          case 0x51u:
            GASValue::Sub(this: (GASValue *)result->n, a2: (struct GASEnvironment *)result, v2: 1);
            goto LABEL_880;
          case 0x52u:
            i = (int)&result->n;
            v196 = 32 * (result->rcl.right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
            v197 = nullptr;
            if ( v196 >= 2 )
              v197 = (GASValue *)(*(_DWORD *)(result->rcl.top + 4 * ((v196 - 2) >> 5)) + 16 * ((v196 - 2) & 0x1F));
            nargsf = GASValue::ToNumber(this: v197, a2: (struct GASEnvironment *)result);
            *(double *)v373 = nargsf;
            GASNumberUtil::IsNaNOrInfinity(v: v198);
            if ( v199 != 0 )
              reg = 0;
            else
              reg = (int)nargsf;
            v200 = *(GASValue **)i;
            index[0] = 0;
            GASValue::ToStringImpl(a1: v200, a2: &varname, a3: result, a4: -1, a5: 0);
            v201 = *(GASValue **)i;
            StringNode = native;
            NargsIn = nullptr;
            if ( (const wchar_t *)v201 <= result->lpstr )
              v202 = result->rcl.left;
            else
              v202 = (int)(v201 - 4);
            *(_DWORD *)&v373[4] = v202;
            GASValueGuard::GASValueGuard(this: &v374);
            if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 || *(_DWORD *)(varname.N.Name.Short + 16) == 0 )
            {
              if ( (const wchar_t *)result->n <= result->lpstr )
                v233 = (const struct GASValue *)result->rcl.left;
              else
                v233 = (const struct GASValue *)(*(_DWORD *)i - 16);
              s2 = (const IClientRenderable *)GASValue::GASValue(this: (GASValue *)v431, a2: v233);
              if ( v422 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v422, a2: 0);
              varname.N.ShortName[4] = 0;
              v66 = LOBYTE(s2->__vftable) == 6;
              v422 = nullptr;
              if ( v66 )
              {
                v234 = GASValue::ToObject(this: (GASValue *)s2, a2: (const struct GASEnvironment *)result);
                v235 = v234;
                if ( v234 != nullptr )
                  v234[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v234[1].pNode->pNext + 1) & 0x8FFFFFFF);
                v422 = v234;
                if ( v234 != nullptr
                  && ((unsigned __int8 (__thiscall *)(struct GASObject *))v234[2].pNode[7].elem)(a1: &v234[2]) != 0 )
                {
                  GASValue::~GASValue(this: (GASValue *)s2);
                  sceneOffset = ((int (__thiscall *)(struct GASObject *, GAtomicInt<unsigned long> *, tagPOLYTEXTW *))v235[2].pNode[7].pNext)(
                                  a1: &v235[2],
                                  a2: &funcBuf,
                                  a3: &result[3]);
                  s2 = (const IClientRenderable *)GASValue::GASValue(
                                                    this: (GASValue *)v431,
                                                    a2: (const struct GASFunctionRef *)sceneOffset);
                  GASFunctionRef::`scalar deleting destructor'();
                  GASValue::SetAsObject(this: (GASValue *)&varname.N.Name.Long, a2: v235);
                  StringNode = (__vc_attributes::event_receiverAttribute::type_e)NargsIn;
LABEL_609:
                  if ( LOBYTE(GASValue::IsFunction().usPreferredNode) != 0 )
                  {
                    v236 = (_DWORD *)GASValue::ToFunction(a1: &funcBuf, a2: result);
                    v66 = *v236 == 0;
                    sceneOffset = (int)v236;
                    if ( !v66 )
                    {
                      v237 = GASFnCall::GASFnCall(
                               this: fnCallBuf,
                               result: (PPM_IDLE_STATE_ACCOUNTING *)index,
                               ThisIn: (tagWNDCLASSW *)&varname.N.LongName[1],
                               a4: (_SERVICE_STATUS *)result,
                               NargsIn: reg,
                               FirstIn: ((signed int)(result->n - (unsigned int)result->lpstr) >> 4)
                             + 32 * result->rcl.right
                             - 35);
                      (*(void (__thiscall **)(_DWORD, PPM_IDLE_STATE_ACCOUNTING *, _DWORD, _DWORD))(**(_DWORD **)sceneOffset
                                                                                                  + 40))(
                        a1: *(_DWORD *)sceneOffset,
                        a2: v237,
                        a3: *(_DWORD *)(sceneOffset + 4),
                        a4: 0);
                      (*(void (__thiscall **)(PPM_IDLE_STATE_ACCOUNTING *, _DWORD))v237->IdleTransitions)(
                        a1: v237,
                        a2: 0);
                      StringNode = (__vc_attributes::event_receiverAttribute::type_e)NargsIn;
                    }
                    *(_DWORD *)&v373[4] = 0;
                    GASFunctionRef::`scalar deleting destructor'();
                  }
                  else if ( (v417 & 1) != 0 )
                  {
                    GFxActionLogger::LogScriptError(
                      result: &v413,
                      a2: "Error: CallMethod \"as a function\" - pushed object is not a function object\n");
                  }
                  GASValue::~GASValue(this: (GASValue *)&varname.N.Name.Long);
                  GASValue::~GASValue(this: (GASValue *)s2);
                  if ( v422 != nullptr )
                    GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
                  v422 = nullptr;
                  goto LABEL_618;
                }
                StringNode = (__vc_attributes::event_receiverAttribute::type_e)NargsIn;
              }
              GASEnvironment::GetVariable(
                this: (__vc_attributes::max_isAttribute *)result,
                varname: (_IMAGE_SYMBOL_EX *)(result[3].x + 252),
                a3: (GASValue *)&varname.N.Name.Long,
                retVal: (unsigned int)v412,
                paschar: nullptr,
                a6: nullptr,
                a7: 0);
              goto LABEL_609;
            }
            if ( LOBYTE(GASValue::IsFunction().usPreferredNode) != 0
              || (v203 = (struct GASObjectInterface *)GASValue::ToObjectInterface((_SERVICE_STATUS *)result),
                  StringNode = (__vc_attributes::event_receiverAttribute::type_e)v203,
                  NargsIn = v203,
                  v203 == nullptr) )
            {
              if ( LOBYTE(GASValue::IsFunction().usPreferredNode) == 0 )
              {
                GASEnvironment::PrimitiveToTempObject(
                  this: (__vc_attributes::idl_quoteAttribute *)result,
                  index: (GASValue *)v431,
                  indexa: 1u);
                v66 = *(_BYTE *)v222 == 6;
                sceneOffset = (int)v222;
                if ( !v66 )
                {
                  if ( (v417 & 1) != 0 )
                    GFxActionLogger::LogScriptError(
                      result: &v413,
                      a2: "Error: CallMethod - '%s' on invalid object.\n",
                      *(const char **)varname.N.Name.Short);
                  GASValue::~GASValue(this: (GASValue *)sceneOffset);
                  goto LABEL_618;
                }
                v223 = GASValue::ToObject(this: v222, a2: (const struct GASEnvironment *)result);
                if ( v223 != nullptr )
                  v224 = (GASObjectInterface *)&v223[2];
                else
                  v224 = nullptr;
                varname.N.ShortName[4] = 0;
                if ( !GASEnvironment::GetMember(
                        this: (GASEnvironment *)result,
                        memberName: (_IMAGE_SYMBOL_EX *)v224,
                        a3: (GASValue *)&varname,
                        a4: (struct GASValue *)&varname.N.LongName[1]) )
                {
                  if ( v224 != nullptr
                    && (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)v224 + 8))(a1: v224) - 2) <= 3 )
                  {
                    s2 = *(const IClientRenderable **)varname.N.Name.Short;
                    v231 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v224);
                    if ( DWORD1(v231[6].m_pfnProxied) != 0 )
                      v232 = DWORD1(v231[6].m_pfnProxied);
                    else
                      GFxASCharacter::CreateCharacterHandle(this: v231);
                    GFxActionLogger::LogScriptError(
                      result: &v413,
                      a2: "Error: CallMethod - can't find method %s.%s\n",
                      **(const char ***)(v232 + 12),
                      (const char *)s2);
                  }
                  else
                  {
                    GFxActionLogger::LogScriptError(
                      result: &v413,
                      a2: "Error: CallMethod - can't find method %s\n",
                      *(_DWORD *)varname.N.Name.Short);
                  }
                  goto LABEL_592;
                }
                if ( varname.N.ShortName[4] != 8 )
                {
                  if ( (v417 & 1) != 0 )
                  {
                    if ( v224 != nullptr
                      && (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)v224 + 8))(a1: v224) - 2) <= 3 )
                    {
                      s2 = *(const IClientRenderable **)varname.N.Name.Short;
                      v225 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v224);
                      if ( DWORD1(v225[6].m_pfnProxied) != 0 )
                        v226 = DWORD1(v225[6].m_pfnProxied);
                      else
                        GFxASCharacter::CreateCharacterHandle(this: v225);
                      GFxActionLogger::LogScriptError(
                        result: &v413,
                        a2: "Error: CallMethod - '%s.%s' is not a method\n",
                        **(const char ***)(v226 + 12),
                        (const char *)s2);
                    }
                    else
                    {
                      GFxActionLogger::LogScriptError(
                        result: &v413,
                        a2: "Error: CallMethod - '%s' is not a method\n",
                        *(_DWORD *)varname.N.Name.Short);
                    }
                  }
                  goto LABEL_592;
                }
                v227 = (const IClientRenderable *)GASValue::ToFunction(a1: &funcBuf, a2: result);
                v66 = v227->__vftable == nullptr;
                s2 = v227;
                if ( v66 )
                {
                  if ( (v417 & 1) != 0 )
                  {
                    if ( v224 != nullptr
                      && (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)v224 + 8))(a1: v224) - 2) <= 3 )
                    {
                      NargsIn = *(struct GASObjectInterface **)varname.N.Name.Short;
                      v229 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v224);
                      if ( DWORD1(v229[6].m_pfnProxied) != 0 )
                        v230 = DWORD1(v229[6].m_pfnProxied);
                      else
                        GFxASCharacter::CreateCharacterHandle(this: v229);
                      GFxActionLogger::LogScriptError(
                        result: &v413,
                        a2: "Error: Invoked method (%s.%s) is not a function\n",
                        **(const char ***)(v230 + 12),
                        (const char *)NargsIn);
                      *(_DWORD *)&v373[4] = 0;
                      GASFunctionRef::`scalar deleting destructor'();
                      goto LABEL_592;
                    }
                    GFxActionLogger::LogScriptError(
                      result: &v413,
                      a2: "Error: Invoked method (%s) is not a function\n",
                      *(const char **)varname.N.Name.Short);
                  }
                  *(_DWORD *)&v373[4] = 0;
                  GASFunctionRef::`scalar deleting destructor'();
                }
                else
                {
                  v228 = GASFnCall::GASFnCall(
                           this: fnCallBuf,
                           a2: (tagALTTABINFO *)index,
                           NargsIn: (tagALTTABINFO *)v224,
                           a4: (tagALTTABINFO *)result,
                           a5: (tagALTTABINFO *)reg,
                           FirstIn: (tagALTTABINFO *)(((signed int)(result->n - (unsigned int)result->lpstr) >> 4)
                                           + 32 * result->rcl.right
                                           - 35));
                  (*((void (__stdcall **)(GASFnCall *, IClientRenderable_vtbl *, _DWORD))s2->GetIClientUnknown + 10))(
                    a1: v228,
                    a2: s2[1].__vftable,
                    a3: *(_DWORD *)varname.N.Name.Short);
                  ((void (__thiscall *)(GASFnCall *, _DWORD))(*v228)->cbSize)(a1: v228, a2: 0);
                  *(_DWORD *)&v373[4] = 0;
                  GASFunctionRef::`scalar deleting destructor'();
                }
LABEL_592:
                GASValue::~GASValue(this: (GASValue *)&varname.N.Name.Long);
                NargsIn = nullptr;
                StringNode = native;
                GASValue::~GASValue(this: (GASValue *)sceneOffset);
                goto LABEL_618;
              }
              v214 = (GASValue *)(*(_DWORD *)i - 16);
              if ( (const wchar_t *)result->n <= result->lpstr )
                v214 = (GASValue *)result->rcl.left;
              sceneOffset = (int)v214;
              v215 = GASValue::ToObject(this: v214, a2: (const struct GASEnvironment *)result);
              if ( v215 == nullptr )
              {
                StringNode = native;
LABEL_544:
                if ( (v417 & 1) != 0 )
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: Function is not an object for static method '%s'.\n",
                    *(const char **)varname.N.Name.Short);
                goto LABEL_618;
              }
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)&v215[2];
              NargsIn = (struct GASObjectInterface *)&v215[2];
              if ( v215 == (struct GASObject *)-16 )
                goto LABEL_544;
              LOBYTE(v431[0].__vftable) = 0;
              if ( GASEnvironment::GetMember(
                     this: (GASEnvironment *)result,
                     memberName: (_IMAGE_SYMBOL_EX *)StringNode,
                     a3: (GASValue *)&varname,
                     a4: (struct GASValue *)v431) )
              {
                v216 = (const IClientRenderable *)GASValue::ToFunction(a1: &funcBuf, a2: result);
                v66 = v216->__vftable == nullptr;
                s2 = v216;
                if ( v66 )
                {
                  if ( (v417 & 1) != 0 )
                  {
                    if ( (unsigned int)((*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 8))(a1: StringNode)
                                      - 2) > 3 )
                    {
                      GFxActionLogger::LogScriptError(
                        result: &v413,
                        a2: "Error: Invoked method (%s) is not a function\n",
                        *(_DWORD *)varname.N.Name.Short);
                    }
                    else
                    {
                      sceneOffset = *(_DWORD *)varname.N.Name.Short;
                      v218 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)StringNode);
                      if ( DWORD1(v218[6].m_pfnProxied) != 0 )
                        v219 = DWORD1(v218[6].m_pfnProxied);
                      else
                        GFxASCharacter::CreateCharacterHandle(this: v218);
                      GFxActionLogger::LogScriptError(
                        result: &v413,
                        a2: "Error: Invoked method (%s.%s) is not a function\n",
                        **(const char ***)(v219 + 12),
                        (const char *)sceneOffset);
                    }
                  }
                }
                else
                {
                  v217 = GASFnCall::GASFnCall(
                           this: fnCallBuf,
                           result: (PPM_IDLE_STATE_ACCOUNTING *)index,
                           ThisIn: (tagWNDCLASSW *)sceneOffset,
                           a4: (_SERVICE_STATUS *)result,
                           NargsIn: reg,
                           FirstIn: ((signed int)(result->n - (unsigned int)result->lpstr) >> 4) + 32 * result->rcl.right - 35);
                  (*((void (__thiscall **)(IClientRenderable_vtbl *, PPM_IDLE_STATE_ACCOUNTING *, IClientRenderable_vtbl *, _DWORD))s2->GetIClientUnknown
                   + 10))(
                    a1: s2->__vftable,
                    a2: v217,
                    a3: s2[1].__vftable,
                    a4: *(_DWORD *)varname.N.Name.Short);
                  (*(void (__thiscall **)(PPM_IDLE_STATE_ACCOUNTING *, _DWORD))v217->IdleTransitions)(a1: v217, a2: 0);
                  StringNode = (__vc_attributes::event_receiverAttribute::type_e)NargsIn;
                }
                goto LABEL_526;
              }
              if ( (v417 & 1) != 0 )
              {
                if ( (unsigned int)((*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 8))(a1: StringNode)
                                  - 2) <= 3 )
                {
                  sceneOffset = *(_DWORD *)varname.N.Name.Short;
                  v220 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)StringNode);
                  if ( DWORD1(v220[6].m_pfnProxied) != 0 )
                    v221 = DWORD1(v220[6].m_pfnProxied);
                  else
                    GFxASCharacter::CreateCharacterHandle(this: v220);
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: Static method '%s.%s' is not found.\n",
                    **(const char ***)(v221 + 12),
                    (const char *)sceneOffset);
                  GASValue::~GASValue(this: (GASValue *)v431);
                  goto LABEL_618;
                }
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: "Error: Static method '%s' is not found.\n",
                  *(_DWORD *)varname.N.Name.Short);
              }
              goto LABEL_534;
            }
            LOBYTE(v431[0].__vftable) = 0;
            if ( (*(unsigned __int8 (__thiscall **)(struct GASObjectInterface *))(*(_DWORD *)v203 + 60))(a1: v203) != 0 )
            {
              s2 = (const IClientRenderable *)(StringNode - 16);
              if ( StringNode != 16 )
                *(_DWORD *)(StringNode - 16 + 8) = (*(_DWORD *)(StringNode - 16 + 8) + 1) & 0x8FFFFFFF;
              *(_DWORD *)&v373[4] = &varname;
              Owner = GASObjectInterface::FindOwner(result: (_JOB_SET_ARRAY *)&result[3]);
              v205 = (struct GASObject *)Owner;
              if ( Owner != nullptr )
                Owner->Flags = (Owner->Flags + 1) & 0x8FFFFFFF;
              if ( v422 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v422, a2: (int)Owner);
              v422 = v205;
              if ( v205 != nullptr )
              {
                GASSuperObject::SetAltProto(this: (CBitWrite *)s2, altProto: (int)v205, a3: *(int *)&v373[8]);
                GRefCountBaseGC<323>::Release(a1: (int)v205, a2: (int)v205);
                v422 = nullptr;
              }
              else
              {
                NargsIn = nullptr;
              }
              GRefCountBaseGC<323>::Release(a1: (int)s2, a2: (int)v205);
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)NargsIn;
            }
            if ( StringNode == native )
              goto LABEL_534;
            if ( !GASEnvironment::GetMember(
                    this: (GASEnvironment *)result,
                    memberName: (_IMAGE_SYMBOL_EX *)StringNode,
                    a3: (GASValue *)&varname,
                    a4: (struct GASValue *)v431) )
            {
              if ( (v417 & 1) != 0 )
              {
                if ( (unsigned int)((*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 8))(a1: StringNode)
                                  - 2) <= 3 )
                {
                  sceneOffset = *(_DWORD *)varname.N.Name.Short;
                  v212 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)StringNode);
                  if ( DWORD1(v212[6].m_pfnProxied) != 0 )
                    v213 = DWORD1(v212[6].m_pfnProxied);
                  else
                    GFxASCharacter::CreateCharacterHandle(this: v212);
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: CallMethod - can't find method %s.%s\n",
                    **(const char ***)(v213 + 12),
                    (const char *)sceneOffset);
                  GASValue::~GASValue(this: (GASValue *)v431);
                  goto LABEL_618;
                }
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: "Error: CallMethod - can't find method %s\n",
                  *(_DWORD *)varname.N.Name.Short);
              }
LABEL_534:
              GASValue::~GASValue(this: (GASValue *)v431);
              goto LABEL_618;
            }
            if ( LOBYTE(GASValue::IsFunction().usPreferredNode) == 0 )
            {
              if ( (v417 & 1) != 0 )
              {
                if ( (unsigned int)((*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 8))(a1: StringNode)
                                  - 2) <= 3 )
                {
                  sceneOffset = *(_DWORD *)varname.N.Name.Short;
                  v206 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)StringNode);
                  if ( DWORD1(v206[6].m_pfnProxied) != 0 )
                    v207 = DWORD1(v206[6].m_pfnProxied);
                  else
                    GFxASCharacter::CreateCharacterHandle(this: v206);
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: CallMethod - '%s.%s' is not a method\n",
                    **(const char ***)(v207 + 12),
                    (const char *)sceneOffset);
                  GASValue::~GASValue(this: (GASValue *)v431);
                  goto LABEL_618;
                }
                GFxActionLogger::LogScriptError(
                  result: &v413,
                  a2: "Error: CallMethod - '%s' is not a method\n",
                  *(_DWORD *)varname.N.Name.Short);
              }
              goto LABEL_534;
            }
            v208 = (const IClientRenderable *)GASValue::ToFunction(a1: &funcBuf, a2: result);
            v66 = v208->__vftable == nullptr;
            s2 = v208;
            if ( !v66 )
            {
              v209 = GASFnCall::GASFnCall(
                       this: fnCallBuf,
                       a2: (tagALTTABINFO *)index,
                       (tagALTTABINFO *)NargsIn,
                       a4: (tagALTTABINFO *)result,
                       a5: (tagALTTABINFO *)reg,
                       FirstIn: (tagALTTABINFO *)(((signed int)(result->n - (unsigned int)result->lpstr) >> 4)
                                       + 32 * result->rcl.right
                                       - 35));
              (*((void (__stdcall **)(GASFnCall *, IClientRenderable_vtbl *, _DWORD))s2->GetIClientUnknown + 10))(
                a1: v209,
                a2: s2[1].__vftable,
                a3: *(_DWORD *)varname.N.Name.Short);
              ((void (__thiscall *)(GASFnCall *, _DWORD))(*v209)->cbSize)(a1: v209, a2: 0);
              StringNode = (__vc_attributes::event_receiverAttribute::type_e)NargsIn;
              *(_DWORD *)&v373[4] = 0;
              GASFunctionRef::`scalar deleting destructor'();
              GASValue::~GASValue(this: (GASValue *)v431);
              goto LABEL_618;
            }
            if ( (v417 & 1) == 0 )
              goto LABEL_526;
            if ( (unsigned int)((*(int (__thiscall **)(__vc_attributes::event_receiverAttribute::type_e))(*(_DWORD *)StringNode + 8))(a1: StringNode)
                              - 2) > 3 )
            {
              GFxActionLogger::LogScriptError(
                result: &v413,
                a2: "Error: Invoked method (%s) is null\n",
                *(_DWORD *)varname.N.Name.Short);
LABEL_526:
              *(_DWORD *)&v373[4] = 0;
              GASFunctionRef::`scalar deleting destructor'();
              GASValue::~GASValue(this: (GASValue *)v431);
              goto LABEL_618;
            }
            sceneOffset = *(_DWORD *)varname.N.Name.Short;
            v210 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)StringNode);
            if ( DWORD1(v210[6].m_pfnProxied) != 0 )
              v211 = DWORD1(v210[6].m_pfnProxied);
            else
              GFxASCharacter::CreateCharacterHandle(this: v210);
            GFxActionLogger::LogScriptError(
              result: &v413,
              a2: "Error: Invoked method (%s.%s) is null\n",
              **(const char ***)(v211 + 12),
              (const char *)sceneOffset);
            *(_DWORD *)&v373[4] = 0;
            GASFunctionRef::`scalar deleting destructor'();
            GASValue::~GASValue(this: (GASValue *)v431);
LABEL_618:
            GASPagedStack<GASValue,32>::Pop(result: (__vc_attributes::readonlyAttribute *)(reg + 2));
            GASValue::operator=(v: (tagWNDCLASSW *)index);
            if ( LOBYTE(result[4].uiFlags) != 10 )
            {
              GASEnvironment::CheckTryBlocks(
                this: (__vc_attributes::unhookAttribute *)result,
                pc,
                plocalTryBlockCount: (const char *)&tryCount);
              *(_DWORD *)&v373[4] = v419;
              GASEnvironment::CheckExceptions(
                this: (__vc_attributes::unhookAttribute *)result,
                pactBuf,
                nextPc,
                plocalTryBlockCount: (const char *)&tryCount,
                retval);
              nextPc = v238;
            }
            if ( StringNode != native )
            {
              v239 = GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)StringNode);
              if ( (v239 == nullptr || (*((_BYTE *)v239 + 118) & 0x10) == 0)
                && GASEnvironment::NeedTermination(this: result, a2: v419) )
              {
                nextPc = v408;
              }
            }
            GASValue::~GASValue(this: (GASValue *)index);
            *(_DWORD *)&v373[4] = 0;
            GASString::`scalar deleting destructor'();
            GASValueGuard::~GASValueGuard(
              this: &v374,
              a2: *(struct UtlRBTreeNode_t<char const *,unsigned short> **)&v373[8],
              a3: *(int *)&v373[12]);
LABEL_880:
            if ( bufferTimes.unused != 0 )
            {
              *(_DWORD *)&v373[4] = samplingPeriod;
              StringNode = *(_DWORD *)bufferTimes.unused + 8 * (_DWORD)pc;
              LODWORD(v351) = GFxAmpViewStats::GetInstructionTime(this: v394);
              *(_QWORD *)StringNode += v351;
            }
            pc = nextPc;
            if ( (int)nextPc >= (int)v408 )
              goto LABEL_883;
            break;
          case 0x53u:
            v240 = GASValue::GASValue(this: (GASValue *)index, a2: (const struct GASValue *)result->n);
            v241 = (const wchar_t *)result->n;
            HIDWORD(phandler) = v240;
            if ( v241 <= result->lpstr )
              v242 = (const struct GASValue *)result->rcl.left;
            else
              v242 = (const struct GASValue *)(v241 - 8);
            v243 = (struct GASObjectInterface *)GASValue::GASValue(this: (GASValue *)v431, a2: v242);
            right = result->rcl.right;
            NargsIn = v243;
            v245 = 32 * (right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
            v246 = nullptr;
            if ( v245 >= 2 )
              v246 = (GASValue *)(*(_DWORD *)(result->rcl.top + 4 * ((v245 - 2) >> 5)) + 16 * ((v245 - 2) & 0x1F));
            nargsf = GASValue::ToNumber(this: v246, a2: (struct GASEnvironment *)result);
            *(double *)v373 = nargsf;
            GASNumberUtil::IsNaNOrInfinity(v: v247);
            if ( v248 != 0 )
              s2 = nullptr;
            else
              s2 = (const IClientRenderable *)(int)nargsf;
            GASPagedStack<GASValue,32>::Pop3(
              this: (__vc_attributes::iid_isAttribute *)&result->n,
              a2: *(const char **)&v373[8]);
            GASValue::ToStringImpl(a1: v240, a2: &varname, a3: result, a4: -1, a5: 0);
            if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0
              || *(_BYTE *)v240 == 5 && *(_DWORD *)(varname.N.Name.Short + 16) == 0 )
            {
              v252 = (const struct GASFunctionRef *)GASValue::ToFunction(a1: &funcBuf, a2: result);
              v253 = GASValue::GASValue(this: (GASValue *)&varname.N.Name.Long, a2: v252);
              *(_DWORD *)&v373[4] = 0;
              reg = (int)v253;
              GASFunctionRef::`scalar deleting destructor'();
            }
            else
            {
              varname.N.ShortName[4] = 0;
              reg = (int)&varname.N.Name.Long;
              v249 = (GASObjectInterface *)GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
              if ( (v249 == nullptr
                 || !GASEnvironment::GetMember(
                       this: (GASEnvironment *)result,
                       memberName: (_IMAGE_SYMBOL_EX *)v249,
                       a3: (GASValue *)&varname,
                       a4: (struct GASValue *)&varname.N.LongName[1]))
                && (v417 & 1) != 0 )
              {
                if ( v249 != nullptr
                  && (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)v249 + 8))(a1: v249) - 2) <= 3 )
                {
                  sceneOffset = *(_DWORD *)varname.N.Name.Short;
                  v250 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v249);
                  if ( DWORD1(v250[6].m_pfnProxied) != 0 )
                    v251 = DWORD1(v250[6].m_pfnProxied);
                  else
                    GFxASCharacter::CreateCharacterHandle(this: v250);
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: Method '%s.%s' is not found.\n",
                    **(const char ***)(v251 + 12),
                    (const char *)sceneOffset);
                }
                else
                {
                  GFxActionLogger::LogScriptError(
                    result: &v413,
                    a2: "Error: Method '%s' is not found.\n",
                    *(const char **)varname.N.Name.Short);
                }
              }
            }
            if ( LOBYTE(GASValue::IsFunction().usPreferredNode) != 0 )
            {
              v254 = (const struct GASFunctionRef *)GASValue::ToFunction(a1: &funcBuf, a2: result);
              sceneOffset = (int)GASEnvironment::OperatorNew(
                                   this: (__vc_attributes::idl_quoteAttribute *)result,
                                   a2: v254,
                                   nargs: (int)s2,
                                   argsTopOff: -1);
              if ( v422 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
              *(_DWORD *)&v373[4] = 0;
              v422 = (struct GASObject *)sceneOffset;
              GASFunctionRef::`scalar deleting destructor'();
              i = (int)v422;
            }
            else
            {
              if ( v422 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
              i = 0;
              v422 = nullptr;
              if ( (v417 & 1) != 0 )
                GFxActionLogger::LogScriptError(result: &v413, a2: "Error: can't create object with unknown ctor\n");
            }
            GASPagedStack<GASValue,32>::Pop(result: (__vc_attributes::readonlyAttribute *)s2);
            result->n += 16;
            if ( result->n >= result->uiFlags )
              GASPagedStack<GASValue,32>::PushPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            StringNode = result->n;
            if ( StringNode != native )
              GASValue::GASValue(this: (GASValue *)StringNode, a2: (struct GASObject *)i);
            if ( i != 0 )
              GRefCountBaseGC<323>::Release(a1: i, a2: StringNode);
            v422 = nullptr;
            GASValue::~GASValue(this: (GASValue *)HIDWORD(phandler));
            GASValue::~GASValue(this: (GASValue *)NargsIn);
            GASValue::~GASValue(this: (GASValue *)reg);
            *(_DWORD *)&v373[4] = 0;
            GASString::`scalar deleting destructor'();
LABEL_663:
            if ( LOBYTE(result[4].uiFlags) != 10 )
            {
              GASEnvironment::CheckTryBlocks(
                this: (__vc_attributes::unhookAttribute *)result,
                pc,
                plocalTryBlockCount: (const char *)&tryCount);
              *(_DWORD *)&v373[4] = v419;
              GASEnvironment::CheckExceptions(
                this: (__vc_attributes::unhookAttribute *)result,
                pactBuf,
                nextPc,
                plocalTryBlockCount: (const char *)&tryCount,
                retval);
              nextPc = v255;
            }
            goto LABEL_665;
          case 0x54u:
            GASExecutionContext::InstanceOfOpCode(this: (GASExecutionContext *)&v404, a2: (const char *)i);
            goto LABEL_880;
          case 0x60u:
            v256 = (const wchar_t *)result->n;
            v257 = (unsigned int)(v256 - 8);
            if ( v256 <= result->lpstr )
              v257 = result->rcl.left;
            GASValue::And(this: v257, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0x61u:
            v258 = (const wchar_t *)result->n;
            v259 = (unsigned int)(v258 - 8);
            if ( v258 <= result->lpstr )
              v259 = result->rcl.left;
            GASValue::Or(this: v259, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0x62u:
            v260 = (const wchar_t *)result->n;
            v261 = (unsigned int)(v260 - 8);
            if ( v260 <= result->lpstr )
              v261 = result->rcl.left;
            GASValue::Xor(this: v261, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0x63u:
            v262 = (const wchar_t *)result->n;
            v263 = (unsigned int)(v262 - 8);
            if ( v262 <= result->lpstr )
              v263 = result->rcl.left;
            GASValue::Shl(this: v263, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0x64u:
            v264 = (const wchar_t *)result->n;
            v265 = (unsigned int)(v264 - 8);
            if ( v264 <= result->lpstr )
              v265 = result->rcl.left;
            GASValue::Asr(this: v265, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0x65u:
            v266 = (const wchar_t *)result->n;
            v267 = (unsigned int)(v266 - 8);
            if ( v266 <= result->lpstr )
              v267 = result->rcl.left;
            GASValue::Lsr(this: v267, penv: (struct GASEnvironment *)result, v: (tagWNDCLASSW *)result->n);
            goto $LN5115;
          case 0x66u:
            v268 = (const wchar_t *)result->n;
            v269 = (GASValue *)(v268 - 8);
            if ( v268 <= result->lpstr )
              v269 = (GASValue *)result->rcl.left;
            v66 = !GASValue::TypesMatch(this: v269, val: (tagWNDCLASSW *)result->n);
            v270 = (const wchar_t *)result->n;
            v180 = (GASValue *)(v270 - 8);
            if ( v66 )
            {
              if ( v270 <= result->lpstr )
                v180 = (GASValue *)result->rcl.left;
              *(_DWORD *)&v373[4] = 0;
LABEL_692:
              GASValue::SetBool(this: v180, val: v373[4]);
              goto $LN5115;
            }
            if ( v270 > result->lpstr )
            {
              i = (int)(v270 - 8);
            }
            else
            {
              v180 = (GASValue *)result->rcl.left;
              i = (int)v180;
            }
            IsEqual = GASValue::IsEqual(
                        this: v180,
                        (tagRID_DEVICE_INFO_KEYBOARD *)result,
                        a3: (const struct GASValue *)result->n);
            GASValue::SetBool(this: (GASValue *)i, val: IsEqual);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n >= result->lpstr )
              goto LABEL_880;
            goto LABEL_694;
          case 0x67u:
            v272 = (const wchar_t *)result->n;
            v273 = (int)(v272 - 8);
            if ( v272 <= result->lpstr )
              v273 = result->rcl.left;
            i = GASValue::Compare(a1: v273, a2: index, a3: result, a4: result->n, a5: 1);
            GASValue::operator=(v: (tagWNDCLASSW *)i);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            GASValue::`scalar deleting destructor'(this: (GASValue *)i, a2: 0);
            goto LABEL_880;
          case 0x68u:
            v274 = (const wchar_t *)result->n;
            v275 = (int)(v274 - 8);
            if ( v274 <= result->lpstr )
              v275 = result->rcl.left;
            i = GASValue::ToStringVersioned(a1: v275, a2: &varname, a3: result, a4: Version);
            reg = GASValue::ToStringVersioned(a1: result->n, a2: &v402, a3: result, a4: Version);
            v276 = (const wchar_t *)result->n;
            if ( v276 <= result->lpstr )
              v277 = result->rcl.left;
            else
              v277 = (int)(v276 - 8);
            sceneOffset = v277;
            v278 = (unsigned __int8)GASString::operator>(result: (const _RECTL *)reg);
            GASValue::SetBool(this: (GASValue *)sceneOffset, val: v278);
            GASValue::~GASValue(this: (GASValue *)result->n);
            result->n -= 16;
            if ( (const wchar_t *)result->n < result->lpstr )
              GASPagedStack<GASValue,32>::PopPage(
                this: (__vc_attributes::iid_isAttribute *)&result->n,
                a2: *(const char **)&v373[8]);
            GASString::`scalar deleting destructor'();
            *(_DWORD *)&v373[4] = 0;
            GASString::`scalar deleting destructor'();
            goto LABEL_880;
          case 0x69u:
            GASExecutionContext::ExtendsOpCode(this: (_TRANSACTION_NOTIFICATION **)&v404, i: StringNode);
            goto LABEL_880;
          default:
            goto LABEL_880;
        }
      }
      i = (int)v412;
      v36 = m_unAll64Bits_high - v35;
      v37 = v36;
      if ( v36 >= *((_DWORD *)&v412->m_steamID.m_steamid.m_comp + 1) )
      {
        if ( v36 >= v412->m_iImage )
        {
          *(_DWORD *)&v373[4] = v36 + (v36 >> 2);
          goto LABEL_33;
        }
      }
      else if ( v36 < (unsigned int)v412->m_iImage >> 1 )
      {
        *(_DWORD *)&v373[4] = v36;
LABEL_33:
        GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve(
          this: v412,
          pheapAddr: v412,
          newCapacity: *(unsigned int *)&v373[4]);
      }
      *(_DWORD *)(i + 4) = v37;
LABEL_35:
      StringNode = (__vc_attributes::event_receiverAttribute::type_e)pc;
      goto LABEL_36;
    }
LABEL_883:
    if ( bufferTimes.unused != 0 )
    {
      v352 = (*(int (__thiscall **)(int *))(*result[2].pdx + 84))(a1: result[2].pdx);
      GFxAmpViewStats::ReleaseBufferInstructionTimes(
        this: *(GImageInfo **)(v352 + 10308),
        a2: *(const GImageInfo **)&v373[8]);
    }
    if ( tryCount > 0 )
    {
      for ( tc = tryCount; tc > 0; --tc )
      {
        v353 = result[4].n;
        y = result[4].y;
        v355 = *(_DWORD *)(y + 12 * v353 - 12);
        v356 = y + 12 * v353 - 12;
        v357 = *(_DWORD *)(v356 + 4);
        v358 = *(tagPALETTEENTRY *)(v356 + 8);
        *(_DWORD *)&v390.palVersion = v357;
        v390.palPalEntry[0] = v358;
        GArrayData<GASEnvironment::TryDescr,GAllocatorLH<GASEnvironment::TryDescr,2>,GArrayDefaultPolicy>::Resize(
          this: (__vc_attributes::v1_enumAttribute *)&result[4].y,
          newSize: v353 - 1);
        v359 = 32 * (result->rcl.right - 1) + ((signed int)(result->n - (unsigned int)result->lpstr) >> 4);
        if ( v359 > *(_DWORD *)v390.palPalEntry )
        {
          samplingPeriod = v359 - *(_DWORD *)v390.palPalEntry;
          if ( v359 != *(_DWORD *)v390.palPalEntry )
          {
            do
            {
              GASValue::~GASValue(this: (GASValue *)result->n);
              result->n -= 16;
              if ( (const wchar_t *)result->n < result->lpstr )
                GASPagedStack<GASValue,32>::PopPage(
                  this: (__vc_attributes::iid_isAttribute *)&result->n,
                  a2: *(const char **)&v373[8]);
              --samplingPeriod;
            }
            while ( samplingPeriod != 0 );
          }
        }
        if ( (*(_BYTE *)v355 & 2) != 0 )
        {
          v360 = *(unsigned __int8 *)(v355 + 1);
          v361 = *(unsigned __int8 *)(v355 + 2);
          v362 = *(_DWORD *)&v390.palVersion + *(unsigned __int16 *)(v355 + 3);
          BYTE2(result[4].pdx) |= 1u;
          pc = (char *)(v362 + (v360 | (v361 << 8)));
          GASActionBuffer::Execute(
            a1: pactBuf,
            a2: result,
            a3: pc,
            a4: *(unsigned __int16 *)(v355 + 5),
            a5: retval,
            a6: v412,
            a7: v419);
          BYTE2(result[4].pdx) &= ~1u;
        }
      }
    }
    v66 = result[4].rcl.bottom-- == 1;
    if ( v66 && LOBYTE(result[4].uiFlags) != 10 )
    {
      GASValue::DropRefs(this: (GASValue *)&result[4].uiFlags);
      LOBYTE(result[4].uiFlags) = 10;
      BYTE2(result[4].pdx) &= ~1u;
    }
    v66 = !isOriginalTargetValid;
    v363 = pdx;
    result[2].pdx = (int *)pdx;
    if ( v66 )
      BYTE2(result[4].pdx) |= 2u;
    else
      BYTE2(result[4].pdx) &= ~2u;
    LOBYTE(result[3].y) = (unsigned __int8)GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v363);
    if ( v384 != nullptr )
    {
      GTimer::GetRawTicks(li: v364, a2: *(float *)&v373[8], a3: *(float **)&v373[12]);
      *(_QWORD *)v373 = v365 - v383;
      GFxAmpViewStats::PopCallstack(result: v389);
    }
    if ( v422 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v422, a2: StringNode);
    v404.pObject[20].__vftable = v407;
    v413.value = (const char *)&GFxLogBase<GFxLoadProcess>::`vftable';
    if ( v412 != nullptr )
    {
      v366 = v412;
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)&v412->m_steamID.m_steamid.m_comp);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v366);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A36B0
// Name: public: int GASEnvironment::CheckExceptions(class GASActionBuffer __near *,int,int __near *,class GASValue __near *,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *,enum GASActionBuffer::ExecuteType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASEnvironment::CheckExceptions(
        __vc_attributes::unhookAttribute *this,
        const char *pactBuf,
        const char *nextPc,
        const char *plocalTryBlockCount,
        char *retval,
        int pwithStack,
        int pwithStack_4)
{
  bool v8; // zf
  int v9; // ebx
  int v10; // eax
  void **v11; // ecx
  char *v12; // esi
  int v13; // eax
  HICON__ *v14; // edx
  const wchar_t *lpszClassName; // eax
  unsigned int v16; // ebx
  unsigned int v17; // ebx
  int i; // ecx
  HICON__ *v19; // eax
  char v20; // al
  unsigned int v21; // ecx
  int v22; // eax
  int v23; // ebx
  struct GASLocalFrame *NewLocalFrame; // eax
  int crc; // ecx
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  int v29; // ecx
  int v30; // ebx
  HICON__ *hIcon; // ebx
  char v32; // al
  unsigned int v33; // ecx
  const wchar_t *lpszMenuName; // ebx
  int v35; // ebx
  _DWORD *j; // eax
  int v37; // eax
  int v38; // edx
  char *v39; // ecx
  const char *v40; // [esp+0h] [ebp-3Ch]
  tagWNDCLASSW v; // [esp+Ch] [ebp-30h] BYREF
  int v42; // [esp+34h] [ebp-8h] BYREF
  bool needContinueExecution; // [esp+3Bh] [ebp-1h]
  int v44; // [esp+48h] [ebp+Ch]

LABEL_1:
  v8 = *((_BYTE *)this + 176) == 10;
  needContinueExecution = false;
  if ( !v8 )
  {
    v.hbrBackground = *(HBRUSH__ **)plocalTryBlockCount;
    if ( (int)v.hbrBackground > 0 )
    {
      while ( 1 )
      {
        if ( needContinueExecution )
          goto LABEL_1;
        v9 = *((_DWORD *)this + 42);
        v10 = *((_DWORD *)this + 41);
        v11 = (void **)this + 41;
        v12 = *(char **)(v10 + 12 * v9 - 12);
        v13 = v10 + 12 * v9 - 12;
        v14 = *(HICON__ **)(v13 + 4);
        v.hCursor = *(HICON__ **)(v13 + 8);
        lpszClassName = *((const wchar_t **)this + 42);
        v16 = v9 - 1;
        v.hIcon = v14;
        v.lpszClassName = lpszClassName;
        if ( v16 >= (unsigned int)lpszClassName )
        {
          if ( v16 < *((_DWORD *)this + 43) )
            goto LABEL_10;
          GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
            this: v11,
            pheapAddr: v11,
            newCapacity: v16 + (v16 >> 2));
        }
        else
        {
          if ( v16 >= *((_DWORD *)this + 43) >> 1 )
            goto LABEL_10;
          GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
            this: v11,
            pheapAddr: v11,
            newCapacity: v16);
        }
        lpszClassName = v.lpszClassName;
LABEL_10:
        *((_DWORD *)this + 42) = v16;
        if ( v16 > (unsigned int)lpszClassName )
        {
          v17 = v16 - (_DWORD)lpszClassName;
          for ( i = *((_DWORD *)this + 41) + 12 * (_DWORD)lpszClassName; v17 != 0; --v17 )
          {
            if ( i != 0 )
              *(_DWORD *)(i + 8) = 0;
            i += 12;
          }
        }
        --*(_DWORD *)plocalTryBlockCount;
        v19 = (HICON__ *)(32 * (*((_DWORD *)this + 7) - 1) + ((this->handler - this->receiver) >> 4));
        if ( v19 > v.hCursor )
        {
          v.lpszClassName = (const wchar_t *)((char *)v19 - (char *)v.hCursor);
          if ( v19 != v.hCursor )
          {
            do
            {
              GASValue::~GASValue(this: (GASValue *)this->handler);
              this->handler -= 16;
              if ( this->handler < this->receiver )
                GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)&this->handler, a2: v40);
              --v.lpszClassName;
            }
            while ( v.lpszClassName != nullptr );
          }
        }
        v20 = *v12;
        if ( (*v12 & 1) != 0 )
        {
          v.lpszMenuName = nullptr;
          if ( (v20 & 4) != 0 )
          {
            v21 = (unsigned __int8)v12[7];
            if ( v21 >= *((_DWORD *)this + 27) )
              GFxLogBase<GASEnvironment>::LogError(
                a1: (int)this,
                a2: (int)"Invalid local register %d, stack only has %d entries\n",
                v21,
                *((_DWORD *)this + 27));
            GASValue::operator=(v: (tagWNDCLASSW *)(this + 11));
          }
          else
          {
            v.lpszMenuName = *((const wchar_t **)this + 51);
            GASEnvironment::GetTopLocalFrame((__vc_attributes::propputAttribute *)this, off: 0);
            v23 = v22;
            v44 = v22;
            if ( v22 != 0 )
              *(_DWORD *)(v22 + 8) = (*(_DWORD *)(v22 + 8) + 1) & 0x8FFFFFFF;
            NewLocalFrame = GASEnvironment::CreateNewLocalFrame((GRenderer::CachedData *)this);
            v.lpszClassName = (const wchar_t *)NewLocalFrame;
            if ( NewLocalFrame != nullptr )
              *(_DWORD *)&NewLocalFrame->rgbReserved[4] = (*(_DWORD *)&NewLocalFrame->rgbReserved[4] + 1) & 0x8FFFFFFF;
            if ( v23 != 0 )
              *(_DWORD *)(v23 + 8) = (*(_DWORD *)(v23 + 8) + 1) & 0x8FFFFFFF;
            crc = NewLocalFrame[1].crc;
            if ( crc != 0 )
              GRefCountBaseGC<323>::Release(a1: crc, a2: (int)this);
            *((_DWORD *)v.lpszClassName + 5) = v23;
            v42 = *(_DWORD *)(*((_DWORD *)this + 30) + 8);
            ++*(_DWORD *)(v42 + 8);
            if ( (*v12 & 1) != 0 && (*v12 & 4) == 0 )
            {
              GASStringManager::CreateStringNode(this: *(const char **)(*((_DWORD *)this + 30) + 636));
              v27 = v26;
              *(_DWORD *)(v26 + 8) += 2;
              v8 = (*(_DWORD *)(v42 + 8))-- == 1;
              if ( v8 )
                GASStringNode::ReleaseNode();
              v42 = v27;
              v8 = (*(_DWORD *)(v27 + 8))-- == 1;
              if ( v8 )
                GASStringNode::ReleaseNode();
              v23 = v44;
            }
            v28 = *((_DWORD *)this + 51);
            if ( v28 != 0 && *(_DWORD *)(*((_DWORD *)this + 50) + 4 * v28 - 4) != 0 )
            {
              if ( GASEnvironment::FindLocal((GASEnvironment *)this, key: (_IMAGE_SYMBOL_EX *)&v42) != nullptr )
              {
                GASValue::operator=(v: (tagWNDCLASSW *)(this + 11));
              }
              else
              {
                v29 = *((_DWORD *)this + 50) + 4 * *((_DWORD *)this + 51) - 4;
                if ( *(_DWORD *)v29 != 0 )
                  *(_DWORD *)(*(_DWORD *)v29 + 8) = (*(_DWORD *)(*(_DWORD *)v29 + 8) + 1) & 0x8FFFFFFF;
                v30 = *(_DWORD *)v29;
                if ( *(_DWORD *)v29 != 0 )
                {
                  GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::SetCaseCheck(
                    a1: (int)&v42,
                    v: (tagWNDCLASSW *)(this + 11),
                    a3: *((_BYTE *)this + 124) > 6u);
                  GRefCountBaseGC<323>::Release(a1: v30, a2: (int)this);
                }
                v23 = v44;
              }
            }
            v8 = (*(_DWORD *)(v42 + 8))-- == 1;
            if ( v8 )
              GASStringNode::ReleaseNode();
            if ( v.lpszClassName != nullptr )
              GRefCountBaseGC<323>::Release(a1: (int)v.lpszClassName, a2: (int)this);
            if ( v23 != 0 )
              GRefCountBaseGC<323>::Release(a1: v23, a2: (int)this);
          }
          GASValue::DropRefs(this: (GASValue *)this + 44);
          hIcon = v.hIcon;
          *((_BYTE *)this + 176) = 10;
          *((_BYTE *)this + 198) &= ~1u;
          GASActionBuffer::Execute(
            this: (int)pactBuf,
            result: (tagPOLYTEXTW *)this,
            startPc: (char *)hIcon + *(unsigned __int16 *)(v12 + 1),
            execBytes: *(unsigned __int16 *)(v12 + 3),
            a5: retval,
            pinitialWithStack: pwithStack,
            pinitialWithStack_4: pwithStack_4);
          v8 = (*v12 & 4) == 0;
          needContinueExecution = true;
          if ( v8 )
          {
            lpszMenuName = v.lpszMenuName;
            v.lpszClassName = *((const wchar_t **)this + 51);
            GArrayDataBase<GPtr<GASObject>,GAllocatorLH<GPtr<GASObject>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
              this: (GRenderer::CachedData *)this + 25,
              pheapAddr: (ButtonCode_t)((char *)this + 200),
              newSize: (unsigned int)v.lpszMenuName);
            if ( lpszMenuName > v.lpszClassName )
            {
              v35 = (char *)lpszMenuName - (char *)v.lpszClassName;
              for ( j = (_DWORD *)(*((_DWORD *)this + 50) + 4 * (int)v.lpszClassName); v35 != 0; --v35 )
              {
                if ( j != nullptr )
                  *j = 0;
                ++j;
              }
            }
          }
          else
          {
            v32 = *v12;
            LOBYTE(v.style) = 0;
            if ( (v32 & 1) != 0 && (v32 & 4) != 0 )
              v33 = (unsigned __int8)v12[7];
            else
              v33 = -1;
            if ( v33 >= *((_DWORD *)this + 27) )
              GFxLogBase<GASEnvironment>::LogError(
                a1: (int)this,
                a2: (int)"Invalid local register %d, stack only has %d entries\n",
                v33,
                *((_DWORD *)this + 27));
            GASValue::operator=(&v);
            GASValue::~GASValue(this: (GASValue *)&v);
          }
        }
        if ( (*v12 & 2) != 0 )
        {
          v37 = (unsigned __int8)v12[2];
          v38 = (unsigned __int8)v12[1];
          v39 = (char *)v.hIcon + *(unsigned __int16 *)(v12 + 3);
          *((_BYTE *)this + 198) |= 1u;
          GASActionBuffer::Execute(
            this: (int)pactBuf,
            result: (tagPOLYTEXTW *)this,
            startPc: &v39[v38 | (v37 << 8)],
            execBytes: *(unsigned __int16 *)(v12 + 5),
            a5: retval,
            pinitialWithStack: pwithStack,
            pinitialWithStack_4: pwithStack_4);
          *((_BYTE *)this + 198) &= ~1u;
        }
        if ( (int)--v.hbrBackground <= 0 )
        {
          if ( needContinueExecution )
            goto LABEL_1;
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3B20
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<25,class GASMathCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<25,GASMathCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 27);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASMathCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3BE0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<2,class GASArrayCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<2,GASArrayCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 4);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASArrayCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3CA0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<4,class GASNumberCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<4,GASNumberCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 6);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASNumberCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3D60
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<3,class GASStringCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<3,GASStringCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 5);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASStringCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3E20
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<5,class GASBooleanCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<5,GASBooleanCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 7);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASBooleanCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3EE0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<11,class GASColorCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<11,GASColorCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__thiscall *v12)(void *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 13);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASColorCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3FA0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<9,class GASButtonCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<9,GASButtonCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  GString *(__thiscall *v12)(GString *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 11);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASButtonCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4060
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<29,class GASMovieClipLoaderCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<29,GASMovieClipLoaderCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 31);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASMovieClipLoaderCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4120
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<31,class GASLoadVarsLoaderCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<31,GASLoadVarsLoaderCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__cdecl *v12)(const Vector *, float, matrix3x4_t *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 33);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASLoadVarsLoaderCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A41E0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<18,class GASStageCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<18,GASStageCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 20);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASStageCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A42A0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<21,class GASSelectionCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<21,GASSelectionCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  const GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *(__thiscall *v12)(const GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 23);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASSelectionCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4360
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<19,class GASAsBroadcasterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<19,GASAsBroadcasterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 21);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASAsBroadcasterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4420
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<27,class GASMouseCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<27,GASMouseCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__thiscall *v12)(const GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 29);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASMouseCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A44E0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<10,class GASTextFieldCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<10,GASTextFieldCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  int (*v12)(); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 12);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASTextFieldCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A45A0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<32,class GASTextFormatCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<32,GASTextFormatCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 34);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASTextFormatCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4660
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<43,class GASTextSnapshotCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<43,GASTextSnapshotCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__stdcall *v12)(unsigned int, unsigned int, unsigned int, int, unsigned int); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 45);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASTextSnapshotCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4720
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<20,class GASDateCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<20,GASDateCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 22);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASDateCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A47E0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<44,class GASSharedObjectCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<44,GASSharedObjectCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__thiscall *v12)(const ID3D11BlendState *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 46);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASSharedObjectCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A48A0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<155,class GASAmpMarkerCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<155,GASAmpMarkerCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *(*v12)(GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 157);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASAmpMarkerCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4960
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<12,class GASTransformCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<12,GASTransformCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 14);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASTransformCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4A20
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<13,class GASMatrixCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<13,GASMatrixCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__thiscall *v12)(int); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 15);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASMatrixCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4AE0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<14,class GASPointCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<14,GASPointCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 16);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASPointCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4BA0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<15,class GASRectangleCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<15,GASRectangleCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 17);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASRectangleCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4C60
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<16,class GASColorTransformCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<16,GASColorTransformCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 18);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASColorTransformCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4D20
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<17,class GASCapabilitiesCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<17,GASCapabilitiesCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__thiscall *v12)(struct GFxAmpStream *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 19);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASCapabilitiesCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4DE0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<22,class GASImeCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<22,GASImeCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 24);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASImeCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4EA0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<28,class GASExternalInterfaceCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<28,GASExternalInterfaceCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 30);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASExternalInterfaceCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4F60
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<30,class GASBitmapDataCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<30,GASBitmapDataCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  int (*v12)(); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 32);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASBitmapDataCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5020
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<37,class GASBitmapFilterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<37,GASBitmapFilterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 39);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASBitmapFilterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A50E0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<38,class GASDropShadowFilterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<38,GASDropShadowFilterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  unsigned __int16 (__thiscall *v12)(bool); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 40);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASDropShadowFilterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A51A0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<39,class GASGlowFilterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<39,GASGlowFilterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 41);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASGlowFilterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5260
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<40,class GASBlurFilterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<40,GASBlurFilterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  ID3D11DepthStencilView *(*v12)(ID3D11DepthStencilView *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 42);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASBlurFilterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5320
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<41,class GASBevelFilterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<41,GASBevelFilterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void (__thiscall *v12)(const ID3D11Device *); // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 43);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = GASBevelFilterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A53E0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<42,class GASColorMatrixFilterCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<42,GASColorMatrixFilterCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 44);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASColorMatrixFilterCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5520
// Name: public: void GASGlobalContext::Init(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100A5FF0
// Name: public: void GASActionBuffer::Execute(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASActionBuffer::Execute(GASActionBuffer *this, tagPOLYTEXTW *a2)
{
  GASActionBuffer::Execute(
    (int)this,
    result: a2,
    startPc: nullptr,
    execBytes: *(_DWORD *)(this->dwControlKeyState + 12),
    a5: nullptr,
    pinitialWithStack: 0,
    pinitialWithStack_4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A6010
// Name: public: GASGlobalContext::GASGlobalContext(class GFxMovieRoot __near *,class GASStringManager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::GASGlobalContext(
        vc_attributes::PreAttribute *this,
        tagENHMETAHEADER *result,
        IShaderDevice *strMgr)
{
  this->Deref = (unsigned int)&GRefCountImplCore::`vftable';
  this->Valid = 1;
  this->Deref = (unsigned int)&GRefCountBaseNTS<GASGlobalContext,323>::`vftable';
  GASStringBuiltinManager::GASStringBuiltinManager(this: (GASStringBuiltinManager *)&this->Null, a2: strMgr);
  this->Deref = (unsigned int)&GASGlobalContext::`vftable';
  *((_DWORD *)this + 160) = 0;
  *((_DWORD *)this + 161) = 0;
  *((_DWORD *)this + 162) = 0;
  *((_DWORD *)this + 170) = 0;
  *((_BYTE *)this + 684) = 0;
  *((_DWORD *)this + 172) = 0;
  GASGlobalContext::Init(result);
}

//------------------------------------------------------------------------------
// Address: 0x100C05E0
// Name: public: virtual class GRect<float> GFxMovieRoot::TranslateToScreen(class GRect<float> const __near &,class GMatrix2D)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::TranslateToScreen(
        IDirect3DVertexDeclaration9 *this,
        IDirect3DVertexDeclaration9 *r,
        float *ra,
        struct GMatrix2D a4)
{
  unsigned int v5; // ecx
  unsigned int v6; // eax
  _DWORD *v7; // edx
  float v8[4]; // [esp+Ch] [ebp-48h] BYREF
  GFxCharacter *v9; // [esp+1Ch] [ebp-38h]
  struct GMatrix2D v10; // [esp+20h] [ebp-34h] BYREF
  GMatrix2D v11; // [esp+38h] [ebp-1Ch] BYREF

  v5 = *((_DWORD *)this + 10);
  v6 = 0;
  if ( v5 != 0 )
  {
    v7 = *((_DWORD **)this + 9);
    while ( *v7 != 0 )
    {
      ++v6;
      v7 += 2;
      if ( v6 >= v5 )
        goto LABEL_5;
    }
    v9 = *(GFxCharacter **)(*((_DWORD *)this + 9) + 8 * v6 + 4);
  }
  else
  {
LABEL_5:
    v9 = nullptr;
  }
  GMatrix2D::SetIdentity(this: (float *)&v10);
  GFxCharacter::GetWorldMatrix(this: v9, pmat: (CMaterialDict *)&v10);
  v11.M_[0][0] = *((float *)this + 44);
  v11.M_[0][1] = *((float *)this + 45);
  v11.M_[0][2] = *((float *)this + 46);
  v11.M_[1][0] = *((float *)this + 47);
  v11.M_[1][1] = *((float *)this + 48);
  v11.M_[1][2] = *((float *)this + 49);
  GMatrix2D::Prepend(this: &v11, a2: &a4);
  GMatrix2D::Prepend(this: &v11, a2: &v10);
  v8[0] = *ra * 20.0;
  v8[1] = ra[1] * 20.0;
  v8[2] = ra[2] * 20.0;
  v8[3] = 20.0 * ra[3];
  *(float *)&r->__vftable = 0.0;
  *(float *)&r[1].__vftable = 0.0;
  *(float *)&r[2].__vftable = 0.0;
  *(float *)&r[3].__vftable = 0.0;
  GMatrix2D::EncloseTransform(this: (float *)&v11, a2: (float *)r, a3: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100C0930
// Name: public: void GHashsetNodeEntry<struct GHashNode<class GASString,struct GFxMovieRoot::StickyVarNode __near *,struct GASStringHashFunctor>,struct GHashNode<class GASString,struct GFxMovieRoot::StickyVarNode __near *,struct GASStringHashFunctor>::NodeHashF>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
_SID_AND_ATTRIBUTES __thiscall GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>::Clear(
        _DWORD *this)
{
  int v2; // ecx
  _SID_AND_ATTRIBUTES result; // rax

  v2 = *(this + 1);
  if ( (*(_DWORD *)(v2 + 8))-- == 1 )
    result = GASStringNode::ReleaseNode();
  *this = -2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C3180
// Name: public: virtual class GPoint<float> GFxMovieRoot::TranslateToScreen(class GPoint<float> const __near &,class GMatrix2D)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::TranslateToScreen(
        IDirect3DVertexDeclaration9 *this,
        CCountedStringPoolBase<unsigned int>::hash_item_t *result,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > p,
        int a4,
        int a5)
{
  unsigned int v6; // ecx
  unsigned int v7; // eax
  _DWORD *v8; // edx
  GFxCharacter *v9; // edi
  int v10; // [esp+0h] [ebp-50h]
  int v11; // [esp+Ch] [ebp-44h]
  unsigned int v12; // [esp+10h] [ebp-40h]
  int pString; // [esp+14h] [ebp-3Ch] BYREF
  unsigned int nNextElement; // [esp+18h] [ebp-38h]
  struct GMatrix2D v15; // [esp+1Ch] [ebp-34h] BYREF
  GMatrix2D v16; // [esp+34h] [ebp-1Ch] BYREF

  v6 = *((_DWORD *)this + 10);
  v7 = 0;
  if ( v6 != 0 )
  {
    v8 = *((_DWORD **)this + 9);
    while ( *v8 != 0 )
    {
      ++v7;
      v8 += 2;
      if ( v7 >= v6 )
        goto LABEL_5;
    }
    v9 = *(GFxCharacter **)(*((_DWORD *)this + 9) + 8 * v7 + 4);
  }
  else
  {
LABEL_5:
    v9 = nullptr;
  }
  GMatrix2D::SetIdentity(this: (float *)&v15);
  GFxCharacter::GetWorldMatrix(this: v9, pmat: (CMaterialDict *)&v15);
  v16.M_[0][0] = *((float *)this + 44);
  v16.M_[0][1] = *((float *)this + 45);
  v16.M_[0][2] = *((float *)this + 46);
  v16.M_[1][0] = *((float *)this + 47);
  v16.M_[1][1] = *((float *)this + 48);
  v16.M_[1][2] = *((float *)this + 49);
  GMatrix2D::Prepend(this: &v16, a2: (const struct GMatrix2D *)&p.m_Memory.m_nAllocationCount);
  GMatrix2D::Prepend(this: &v16, a2: &v15);
  pString = (int)p.m_Memory.m_pMemory->pString;
  nNextElement = p.m_Memory.m_pMemory->nNextElement;
  *(float *)&v11 = *(float *)&pString * 20.0;
  *(float *)&v12 = 20.0 * *(float *)&nNextElement;
  pString = v11;
  nNextElement = v12;
  GMatrix2D::Transform(
    this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v16,
    result,
    p: (float *)&pString,
    p_4: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100D5690
// Name: public: GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>(
        _DWORD *this,
        int a2)
{
  int v3; // eax
  IShaderDevice *v4; // ecx

  *this = *(_DWORD *)a2;
  *(this + 1) = *(_DWORD *)(a2 + 4);
  GStringLH::CopyConstructHelper(result: (const CFixedBitVecBase<128> *)(a2 + 8));
  v3 = *(_DWORD *)(a2 + 12);
  *(this + 3) = v3;
  v4 = *(IShaderDevice **)(a2 + 16);
  *(this + 4) = v4;
  if ( v3 == 0 && v4 != nullptr )
    GRefCountImpl::AddRef(this: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E6940
// Name: public: virtual bool GASDoAction::IsActionTag(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASDoAction::IsActionTag(CP4File_Dummy *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E6960
// Name: public: GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>(
        _DWORD *this,
        int a2)
{
  int v3; // eax

  *this = *(_DWORD *)a2;
  *(this + 1) = *(_DWORD *)(a2 + 4);
  GStringLH::CopyConstructHelper(result: (const CFixedBitVecBase<128> *)(a2 + 8));
  v3 = *(_DWORD *)(a2 + 12);
  if ( v3 != 0 )
    ++*(_DWORD *)(v3 + 4);
  *(this + 3) = *(_DWORD *)(a2 + 12);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E6DE0
// Name: public: void GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>::NodeHashF>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>::Clear(
        GRefCountNTSImpl **this)
{
  GRefCountNTSImpl *v2; // ecx
  unsigned int v3; // esi
  int result; // eax

  v2 = *(this + 3);
  if ( v2 != nullptr )
    GRefCountNTSImpl::Release(this: v2);
  v3 = (unsigned int)*(this + 2) & 0xFFFFFFFC;
  result = InterlockedExchangeAdd(Addend: (volatile LONG *)(v3 + 4), Value: -1) - 1;
  if ( result == 0 )
    result = ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: v3);
  *this = (GRefCountNTSImpl *)-2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F44B0
// Name: public: void GASGlobalContext::AddBuiltinClassRegistry<33,class GASStyleSheetCtorFunction>(class GASStringContext __near &,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlobalContext::AddBuiltinClassRegistry<33,GASStyleSheetCtorFunction>(
        float *this,
        const GSize<int> *result,
        int a3)
{
  int v3; // ebx
  float *v4; // edi
  int v5; // esi
  int Index; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  GASValue v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int key[2]; // [esp+14h] [ebp-14h] BYREF
  void *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h]
  char v14; // [esp+27h] [ebp-1h] BYREF

  v3 = *((_DWORD *)this + 162);
  v4 = this + 162;
  v5 = (int)(this + 35);
  if ( v3 == 0
    || (Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>()) < 0
    || (v7 = v3 + 16 * Index + 12) == 0
    || v7 == -4 )
  {
    v12 = &GASStyleSheetCtorFunction::Register;
    v13 = 0;
    v8 = *(_DWORD *)(*(_DWORD *)v5 + 12);
    key[1] = (int)&v12;
    key[0] = v5;
    GHashSetBase<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>,GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,GASGlobalContext::ClassRegEntry,GASStringHashFunctor>::NodeRef>(
      this: v4,
      pmemAddr: (unsigned __int16 *)v4,
      (int)key,
      hashValue: v8);
    if ( v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)v4);
    v10 = *(_DWORD *)v5;
    v14 = 0;
    LOBYTE(v9) = 11;
    ++*(_DWORD *)(v10 + 8);
    (*(void (__thiscall **)(int, const GSize<int> *, int, GASValue *, char *))(*(_DWORD *)(a3 + 16) + 40))(
      a1: a3 + 16,
      a2: result,
      a3: v5,
      a4: &v9,
      a5: &v14);
    GASValue::~GASValue(this: &v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4DE0
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<struct GFxBatchPackageData::BatchInfoKey,struct GFxBatchPackageData::BatchInfo,struct GFxBatchPackageData::BatchInfoKey>,struct GHashNode<struct GFxBatchPackageData::BatchInfoKey,struct GFxBatchPackageData::BatchInfo,struct GFxBatchPackageData::BatchInfoKey>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<struct GFxBatchPackageData::BatchInfoKey,struct GFxBatchPackageData::BatchInfo,struct GFxBatchPackageData::BatchInfoKey>,struct GHashNode<struct GFxBatchPackageData::BatchInfoKey,struct GFxBatchPackageData::BatchInfo,struct GFxBatchPackageData::BatchInfoKey>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<struct GFxBatchPackageData::BatchInfoKey,struct GFxBatchPackageData::BatchInfo,struct GFxBatchPackageData::BatchInfoKey>,struct GHashNode<struct GFxBatchPackageData::BatchInfoKey,struct GFxBatchPackageData::BatchInfo,struct GFxBatchPackageData::BatchInfoKey>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>,GHashNode<GFxBatchPackageData::BatchInfoKey,GFxBatchPackageData::BatchInfo,GFxBatchPackageData::BatchInfoKey>::NodeHashF>(
        _DWORD *this,
        _DWORD *a2)
{
  *this = *a2;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  *(this + 4) = a2[4];
  *(this + 5) = a2[5];
  *(this + 6) = a2[6];
  *(this + 7) = a2[7];
  *(this + 8) = a2[8];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FF520
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<unsigned __int64,class GPtr<struct GFxAmpHeapInfo>,class GFixedSizeHash<unsigned __int64>>,struct GHashNode<unsigned __int64,class GPtr<struct GFxAmpHeapInfo>,class GFixedSizeHash<unsigned __int64>>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<unsigned __int64,class GPtr<struct GFxAmpHeapInfo>,class GFixedSizeHash<unsigned __int64>>,struct GHashNode<unsigned __int64,class GPtr<struct GFxAmpHeapInfo>,class GFixedSizeHash<unsigned __int64>>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<unsigned __int64,class GPtr<struct GFxAmpHeapInfo>,class GFixedSizeHash<unsigned __int64>>,struct GHashNode<unsigned __int64,class GPtr<struct GFxAmpHeapInfo>,class GFixedSizeHash<unsigned __int64>>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>>,GHashNode<unsigned __int64,GPtr<GFxAmpHeapInfo>,GFixedSizeHash<unsigned __int64>>::NodeHashF>(
        _DWORD *this,
        _DWORD *a2)
{
  IShaderDevice *v3; // ecx

  *this = *a2;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  v3 = (IShaderDevice *)a2[4];
  if ( v3 != nullptr )
    GRefCountImpl::AddRef(this: v3);
  *(this + 4) = a2[4];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10103310
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GString,struct StatsUpdate::FileStats,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,struct StatsUpdate::FileStats,struct GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GString,struct StatsUpdate::FileStats,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,struct StatsUpdate::FileStats,struct GString::NoCaseHashFunctor>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<class GString,struct StatsUpdate::FileStats,struct GString::NoCaseHashFunctor>,struct GHashNode<class GString,struct StatsUpdate::FileStats,struct GString::NoCaseHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedRenderContext *__thiscall GHashsetCachedNodeEntry<GHashNode<GString,StatsUpdate::FileStats,GString::NoCaseHashFunctor>,GHashNode<GString,StatsUpdate::FileStats,GString::NoCaseHashFunctor>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GString,StatsUpdate::FileStats,GString::NoCaseHashFunctor>,GHashNode<GString,StatsUpdate::FileStats,GString::NoCaseHashFunctor>::NodeHashF>(
        CMatQueuedRenderContext *this,
        int e)
{
  __int128 _0; // [esp+0h] [ebp-Ch]

  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = *(CMatQueuedRenderContext_vtbl **)e;
  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = *(CRefCountServiceBase<1,CRefMT>_vtbl **)(e + 4);
  GString::GString(result: (CImagePacker *)(e + 8));
  GStatBag::GStatBag(
    this: (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&this->m_pCurrentMaterial,
    source: (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(e + 12),
    a3: _0);
  this->m_queue.m_Allocator.m_commitSize = *(_DWORD *)(e + 536);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10117B20
// Name: protected: virtual void GASSuperObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall GASSuperObject::Finalize_GC(
        GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10122200
// Name: public: GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeHashF>(class GHashsetNodeEntry_GC<struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>,struct GHashNode<class GASString,class GASSharedObjectPtr,struct GASStringHashFunctor>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>::GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx
  _DWORD *v4; // edx

  result = this;
  *this = *a2;
  v3 = a2[1];
  *(this + 1) = v3;
  ++*(_DWORD *)(v3 + 8);
  if ( a2 == (_DWORD *)-8 )
    v4 = nullptr;
  else
    v4 = a2 + 3;
  if ( *v4 != 0 )
    *(_DWORD *)(*v4 + 8) = (*(_DWORD *)(*v4 + 8) + 1) & 0x8FFFFFFF;
  *(this + 3) = *v4;
  *(this + 2) = &GASSharedObjectPtr::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013AF30
// Name: public: unsigned short GFxLoadProcess::ReadU16(void)
// Source: json
//------------------------------------------------------------------------------
GFxAmpMsgHandler *__thiscall GFxLoadProcess::ReadU16(GFxAmpMsgHandler *this)
{
  GFxAmpMsgHandler *v1; // esi
  int v2; // eax
  volatile int RefCount; // ecx
  unsigned __int16 v4; // dx

  v1 = *((GFxAmpMsgHandler **)this + 201);
  if ( v1 == nullptr )
    v1 = this + 2;
  v2 = v1[2].RecvPort - v1[2].RefCount;
  BYTE1(v1[1].__vftable) = 0;
  if ( v2 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  RefCount = v1[2].RefCount;
  v4 = *(_WORD *)((char *)&v1[3].dtr_GRefCountImplCore + RefCount);
  v1[2].RefCount = RefCount + 2;
  return (GFxAmpMsgHandler *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101479F0
// Name: private: void GArrayPagedBase<struct GPointType,8,64,struct GAllocatorPagedLH_POD<struct GPointType,138>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 138;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 138;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 2048, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10151C10
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<class GFxResourceId,class GFxResourcePtr<class GFxImageResource>,class GFixedSizeHash<class GFxResourceId>>,struct GHashNode<class GFxResourceId,class GFxResourcePtr<class GFxImageResource>,class GFixedSizeHash<class GFxResourceId>>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<class GFxResourceId,class GFxResourcePtr<class GFxImageResource>,class GFixedSizeHash<class GFxResourceId>>,struct GHashNode<class GFxResourceId,class GFxResourcePtr<class GFxImageResource>,class GFixedSizeHash<class GFxResourceId>>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<class GFxResourceId,class GFxResourcePtr<class GFxImageResource>,class GFixedSizeHash<class GFxResourceId>>,struct GHashNode<class GFxResourceId,class GFxResourcePtr<class GFxImageResource>,class GFixedSizeHash<class GFxResourceId>>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF>(
        _DWORD *this,
        _DWORD *a2)
{
  int v3; // edx
  IShaderDevice *v4; // eax

  *this = *a2;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  v3 = a2[3];
  *(this + 3) = v3;
  v4 = (IShaderDevice *)a2[4];
  *(this + 4) = v4;
  if ( v3 == 0 && v4 != nullptr )
    GRefCountImpl::AddRef(this: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101565F0
// Name: public: void GArrayPagedBase<unsigned int,6,64,struct GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(int *this)
{
  int v2; // eax
  void **v3; // edi

  v2 = *(this + 1);
  if ( v2 != 0 )
  {
    v3 = (void **)(*(this + 3) + 4 * v2 - 4);
    do
    {
      --*(this + 1);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3--);
    }
    while ( *(this + 1) != 0 );
    --*(this + 1);
    v2 = ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: *(this + 3));
  }
  *(this + 2) = 0;
  *(this + 1) = 0;
  *this = 0;
  *(this + 3) = 0;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10156650
// Name: private: void GArrayPagedBase<struct GRectPacker::RectType,8,64,struct GAllocatorPagedLH_POD<struct GRectPacker::RectType,2>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GRectPacker::RectType,8,64,GAllocatorPagedLH_POD<GRectPacker::RectType,2>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 2;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 2;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 3072, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101566D0
// Name: private: void GArrayPagedBase<unsigned int,6,64,struct GAllocatorPagedLH_POD<unsigned int,2>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 2;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 2;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156DE0
// Name: public: void GArrayPagedBase<struct GRectPacker::RectType,8,64,struct GAllocatorPagedLH_POD<struct GRectPacker::RectType,2>>::PushBack(struct GRectPacker::RectType const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayPagedBase<GRectPacker::RectType,8,64,GAllocatorPagedLH_POD<GRectPacker::RectType,2>>::PushBack(
        unsigned int *this,
        _DWORD *a2)
{
  unsigned int v3; // edi
  _DWORD *result; // eax

  v3 = *this >> 8;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GRectPacker::RectType,8,64,GAllocatorPagedLH_POD<GRectPacker::RectType,2>>::allocatePage(
      this,
      a2: *this >> 8);
  result = (_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * v3) + 12 * (unsigned __int8)*this);
  *result = *a2;
  result[1] = a2[1];
  result[2] = a2[2];
  ++*this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173230
// Name: public: void GHashsetNodeEntry<struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>,struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>::NodeHashF>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>::Clear(
        _DWORD *this)
{
  unsigned int v2; // esi
  int result; // eax

  v2 = *(this + 2) & 0xFFFFFFFC;
  result = InterlockedExchangeAdd(Addend: (volatile LONG *)(v2 + 4), Value: -1) - 1;
  if ( result == 0 )
    result = ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: v2);
  *this = -2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173260
// Name: public: GHashsetNodeEntry<struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>,struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>::NodeHashF>::GHashsetNodeEntry<struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>,struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>::NodeHashF>(class GHashsetNodeEntry<struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>,struct GHashNode<struct GFxTextStyleKey,struct GFxTextStyle __near *,class GFxTextStyleHashFunc<struct GFxTextStyleKey>>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>::GHashsetNodeEntry<GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>,GHashNode<GFxTextStyleKey,GFxTextStyle *,GFxTextStyleHashFunc<GFxTextStyleKey>>::NodeHashF>(
        GMemoryHeap *this,
        GMemoryHeap::HeapTracer *e)
{
  this->__vftable = (GMemoryHeap_vtbl *)e->__vftable;
  this->pPrev = (GMemoryHeap *)e[1].__vftable;
  GStringLH::CopyConstructHelper(result: (const CFixedBitVecBase<128> *)&e[2]);
  this->SelfSize = (unsigned int)e[3].__vftable;
  this->RefCount = (volatile unsigned int)e[4].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x1017C6F0
// Name: private: void GArrayPagedBase<struct GStrokeVertexType,6,16,struct GAllocatorPagedLH_POD<struct GStrokeVertexType,135>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
        unsigned int *this,
        unsigned int nb)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = nb;
  if ( nb >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      nb = 135;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &nb);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  nb = 135;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 768, a4: &nb);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E9D0
// Name: public: GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF>::GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF>(class GHashsetCachedNodeEntry<struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>,struct GHashNode<struct GFxGlyphParam,struct GFxGlyphNode __near *,struct GFxGlyphParam>::NodeHashF> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>::GHashsetCachedNodeEntry<GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>,GHashNode<GFxGlyphParam,GFxGlyphNode *,GFxGlyphParam>::NodeHashF>(
        _DWORD *this,
        _DWORD *a2)
{
  *this = *a2;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  *(this + 3) = a2[3];
  *(this + 4) = a2[4];
  *(this + 5) = a2[5];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10182CE0
// Name: private: void GArrayPagedBase<class GCompoundShape::SPath,6,16,struct GAllocatorPagedLH_POD<class GCompoundShape::SPath,138>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GCompoundShape::SPath,6,16,GAllocatorPagedLH_POD<GCompoundShape::SPath,138>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      a2 = 138;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &a2);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 138;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 1536, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10185790
// Name: private: void GArrayPagedBase<struct GFxFontCompactor::VertexType,6,64,struct GAllocatorPagedGH_POD<struct GFxFontCompactor::VertexType,261>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GFxFontCompactor::VertexType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::VertexType,261>>::allocatePage(
        unsigned int *this,
        unsigned int nb)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = nb;
  if ( nb >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      nb = 261;
      v6 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 256, a3: &nb);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  nb = 261;
  result = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 256, a3: &nb);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10185810
// Name: private: void GArrayPagedBase<struct GFxFontCompactor::GlyphInfoType,6,64,struct GAllocatorPagedGH_POD<struct GFxFontCompactor::GlyphInfoType,261>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<wchar_t const *,CUtlMemory<wchar_t const *,int> > *__thiscall GArrayPagedBase<GFxFontCompactor::GlyphInfoType,6,64,GAllocatorPagedGH_POD<GFxFontCompactor::GlyphInfoType,261>>::allocatePage(
        unsigned int *this,
        unsigned int result)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  CUtlVector<wchar_t const *,CUtlMemory<wchar_t const *,int> > *v7; // eax

  v3 = *(this + 2);
  v4 = result;
  if ( result >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      result = 261;
      v6 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 256, a3: &result);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  result = 261;
  v7 = (CUtlVector<wchar_t const *,CUtlMemory<wchar_t const *,int> > *)GMemory::pGlobalHeap->Alloc_2(
                                                                         this: GMemory::pGlobalHeap,
                                                                         a2: 512,
                                                                         a3: &result);
  *(_DWORD *)(*(this + 3) + 4 * v4) = v7;
  ++*(this + 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10185890
// Name: private: void GArrayPagedBase<unsigned char,12,256,struct GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        unsigned int *this,
        unsigned int nb)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = nb;
  if ( nb >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 1024);
    }
    else
    {
      nb = 261;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 1024, a4: &nb);
    }
    *(this + 2) += 256;
    *(this + 3) = (unsigned int)v6;
  }
  nb = 261;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4096, a4: &nb);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10186610
// Name: public: void GArrayPagedBase<unsigned char,12,256,struct GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        unsigned int *this,
        char *val)
{
  unsigned int v3; // edi
  char result; // al

  v3 = *this >> 12;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<unsigned char,12,256,GAllocatorPagedLH_POD<unsigned char,261>>::allocatePage(this, nb: *this >> 12);
  result = *val;
  *(_BYTE *)(((*this)++ & 0xFFF) + *(_DWORD *)(*(this + 3) + 4 * v3)) = *val;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101891F0
// Name: private: void GArrayPagedBase<struct GRasterizer::Cell,8,64,struct GAllocatorPagedLH_POD<struct GRasterizer::Cell,134>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 134;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 134;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4096, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10189650
// Name: public: void GArrayPagedBase<struct GRasterizer::Cell,8,64,struct GAllocatorPagedLH_POD<struct GRasterizer::Cell,134>>::PushBack(struct GRasterizer::Cell const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
        unsigned int *this,
        _DWORD *a2)
{
  unsigned int v3; // edi
  _DWORD *result; // eax

  v3 = *this >> 8;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::allocatePage(
      this,
      a2: *this >> 8);
  result = (_DWORD *)(16 * (unsigned __int8)*this + *(_DWORD *)(*(this + 3) + 4 * v3));
  *result = *a2;
  result[1] = a2[1];
  result[2] = a2[2];
  result[3] = a2[3];
  ++*this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A1C0
// Name: private: void GArrayPagedBase<struct GRectPacker::PackType,4,16,struct GAllocatorPagedLH_POD<struct GRectPacker::PackType,2>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GRectPacker::PackType,4,16,GAllocatorPagedLH_POD<GRectPacker::PackType,2>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      a2 = 2;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &a2);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 2;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 128, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A240
// Name: private: void GArrayPagedBase<struct GRectPacker::NodeType,8,64,struct GAllocatorPagedLH_POD<struct GRectPacker::NodeType,2>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GRectPacker::NodeType,8,64,GAllocatorPagedLH_POD<GRectPacker::NodeType,2>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 2;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 2;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 7168, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C070
// Name: private: void GArrayPagedBase<unsigned int,8,64,struct GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 1024, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C0F0
// Name: private: void GArrayPagedBase<struct GTessellator::EdgeType,10,64,struct GAllocatorPagedLH_POD<struct GTessellator::EdgeType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::EdgeType,10,64,GAllocatorPagedLH_POD<GTessellator::EdgeType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 0x4000, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C170
// Name: private: void GArrayPagedBase<struct GTessellator::MonoChainType,6,64,struct GAllocatorPagedLH_POD<struct GTessellator::MonoChainType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::MonoChainType,6,64,GAllocatorPagedLH_POD<GTessellator::MonoChainType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 3584, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C1F0
// Name: private: void GArrayPagedBase<unsigned int,10,64,struct GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<unsigned int,10,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 4096, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C270
// Name: private: void GArrayPagedBase<struct GTessellator::BaseLineType,4,16,struct GAllocatorPagedLH_POD<struct GTessellator::BaseLineType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::BaseLineType,4,16,GAllocatorPagedLH_POD<GTessellator::BaseLineType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &a2);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 448, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C2F0
// Name: private: void GArrayPagedBase<struct GTessellator::PendingEndType,4,16,struct GAllocatorPagedLH_POD<struct GTessellator::PendingEndType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::PendingEndType,4,16,GAllocatorPagedLH_POD<GTessellator::PendingEndType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &a2);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 128, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C370
// Name: private: void GArrayPagedBase<struct GTessellator::MonotoneType,6,64,struct GAllocatorPagedLH_POD<struct GTessellator::MonotoneType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::MonotoneType,6,64,GAllocatorPagedLH_POD<GTessellator::MonotoneType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 1536, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C3F0
// Name: private: void GArrayPagedBase<struct GTessellator::MonoVertexType,10,64,struct GAllocatorPagedLH_POD<struct GTessellator::MonoVertexType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 0x2000, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018C470
// Name: private: void GArrayPagedBase<struct GTessellator::TriangleType,10,64,struct GAllocatorPagedLH_POD<struct GTessellator::TriangleType,133>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 133;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 133;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 12288, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018DD90
// Name: public: void GArrayPagedBase<struct GPointType,10,64,struct GAllocatorPagedLH_POD<struct GPointType,133>>::PushBack(struct GPointType const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayPagedBase<GPointType,10,64,GAllocatorPagedLH_POD<GPointType,133>>::PushBack(
        unsigned int *this,
        _DWORD *a2)
{
  unsigned int v3; // edi
  int v4; // ecx
  int result; // eax

  v3 = *this >> 10;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GTessellator::MonoVertexType,10,64,GAllocatorPagedLH_POD<GTessellator::MonoVertexType,133>>::allocatePage(
      this,
      a2: *this >> 10);
  v4 = *(_DWORD *)(*(this + 3) + 4 * v3);
  result = *this & 0x3FF;
  *(_DWORD *)(v4 + 8 * result) = *a2;
  *(_DWORD *)(v4 + 8 * result + 4) = a2[1];
  ++*this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018DDD0
// Name: public: void GArrayPagedBase<struct GTessellator::BaseLineType,4,16,struct GAllocatorPagedLH_POD<struct GTessellator::BaseLineType,133>>::PushBack(struct GTessellator::BaseLineType const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayPagedBase<GTessellator::BaseLineType,4,16,GAllocatorPagedLH_POD<GTessellator::BaseLineType,133>>::PushBack(
        unsigned int *this,
        const void *a2)
{
  unsigned int v3; // esi
  int result; // eax

  v3 = *this >> 4;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GTessellator::BaseLineType,4,16,GAllocatorPagedLH_POD<GTessellator::BaseLineType,133>>::allocatePage(
      this,
      a2: *this >> 4);
  result = *(_DWORD *)(*(this + 3) + 4 * v3);
  qmemcpy((void *)(result + 28 * ((*this)++ & 0xF)), a2, 0x1Cu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018DE20
// Name: public: void GArrayPagedBase<unsigned int,8,64,struct GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::PushBack(
        unsigned int *this,
        int *a2)
{
  unsigned int v3; // edi
  int result; // eax

  v3 = *this >> 8;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<unsigned int,8,64,GAllocatorPagedLH_POD<unsigned int,133>>::allocatePage(this, a2: *this >> 8);
  result = *a2;
  *(_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * v3) + 4 * (unsigned __int8)(*this)++) = *a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018DE60
// Name: public: void GArrayPagedBase<struct GTessellator::TriangleType,10,64,struct GAllocatorPagedLH_POD<struct GTessellator::TriangleType,133>>::PushBack(struct GTessellator::TriangleType const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::PushBack(
        unsigned int *this,
        _DWORD *a2)
{
  unsigned int v3; // edi
  _DWORD *result; // eax

  v3 = *this >> 10;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GTessellator::TriangleType,10,64,GAllocatorPagedLH_POD<GTessellator::TriangleType,133>>::allocatePage(
      this,
      a2: *this >> 10);
  result = (_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * v3) + 12 * (*this & 0x3FF));
  *result = *a2;
  result[1] = a2[1];
  result[2] = a2[2];
  ++*this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101950D0
// Name: private: void GArrayPagedBase<struct GStrokerAA::VertexType,8,64,struct GAllocatorPagedLH_POD<struct GStrokerAA::VertexType,137>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
DName *__userpurge GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage@<eax>(
        DName *this@<ecx>,
        unsigned int result,
        char nb)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  void *v6; // edx
  void *v7; // eax
  DName *v8; // eax

  v4 = *((_DWORD *)this + 2);
  v5 = result;
  if ( result >= v4 )
  {
    v6 = *((void **)this + 3);
    if ( v6 != nullptr )
    {
      v7 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v6, a3: 4 * v4 + 256);
    }
    else
    {
      result = 137;
      v7 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &result);
    }
    *((_DWORD *)this + 2) += 64;
    *((_DWORD *)this + 3) = v7;
  }
  result = 137;
  v8 = (DName *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 3072, a4: &result);
  *(_DWORD *)(*((_DWORD *)this + 3) + 4 * v5) = v8;
  ++*((_DWORD *)this + 1);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10199C30
// Name: private: void GArrayPagedBase<struct GEdgeAA::EdgeType,10,64,struct GAllocatorPagedLH_POD<struct GEdgeAA::EdgeType,136>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GEdgeAA::EdgeType,10,64,GAllocatorPagedLH_POD<GEdgeAA::EdgeType,136>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 136;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 136;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 12288, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199CB0
// Name: private: void GArrayPagedBase<struct GEdgeAA::MeshTriType,8,64,struct GAllocatorPagedLH_POD<struct GEdgeAA::MeshTriType,136>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GEdgeAA::MeshTriType,8,64,GAllocatorPagedLH_POD<GEdgeAA::MeshTriType,136>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 136;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 136;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 15360, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199D30
// Name: private: void GArrayPagedBase<unsigned int,6,16,struct GAllocatorPagedLH_POD<unsigned int,136>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<unsigned int,6,16,GAllocatorPagedLH_POD<unsigned int,136>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      a2 = 136;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &a2);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 136;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199DB0
// Name: private: void GArrayPagedBase<struct GEdgeAA::TriangleType,8,64,struct GAllocatorPagedLH_POD<struct GEdgeAA::TriangleType,136>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 256);
    }
    else
    {
      a2 = 136;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
    }
    *(this + 2) += 64;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 136;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 3072, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019AB90
// Name: public: void GArrayPagedBase<struct GEdgeAA::VertexType,8,64,struct GAllocatorPagedLH_POD<struct GEdgeAA::VertexType,136>>::PushBack(struct GEdgeAA::VertexType const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayPagedBase<GEdgeAA::VertexType,8,64,GAllocatorPagedLH_POD<GEdgeAA::VertexType,136>>::PushBack(
        unsigned int *this,
        _DWORD *a2)
{
  unsigned int v3; // edi
  _DWORD *result; // eax

  v3 = *this >> 8;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
      this,
      a2: *this >> 8);
  result = (_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * v3) + 12 * (unsigned __int8)*this);
  *result = *a2;
  result[1] = a2[1];
  result[2] = a2[2];
  ++*this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C0E0
// Name: private: void GArrayPagedBase<struct GFxGlyphFitter::VertexType,6,16,struct GAllocatorPagedLH_POD<struct GFxGlyphFitter::VertexType,2>>::allocatePage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  void *v5; // edx
  void *v6; // eax
  void *result; // eax

  v3 = *(this + 2);
  v4 = a2;
  if ( a2 >= v3 )
  {
    v5 = (void *)*(this + 3);
    if ( v5 != nullptr )
    {
      v6 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v5, a3: 4 * v3 + 64);
    }
    else
    {
      a2 = 2;
      v6 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &a2);
    }
    *(this + 2) += 16;
    *(this + 3) = (unsigned int)v6;
  }
  a2 = 2;
  result = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 256, a4: &a2);
  *(_DWORD *)(*(this + 3) + 4 * v4) = result;
  ++*(this + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C3B0
// Name: public: void GArrayPagedBase<struct GFxGlyphFitter::VertexType,6,16,struct GAllocatorPagedLH_POD<struct GFxGlyphFitter::VertexType,2>>::PushBack(struct GFxGlyphFitter::VertexType const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::PushBack(
        unsigned int *this,
        int *a2)
{
  unsigned int v3; // edi
  int result; // eax

  v3 = *this >> 6;
  if ( v3 >= *(this + 1) )
    GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
      this,
      a2: *this >> 6);
  result = *a2;
  *(_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * v3) + 4 * ((*this)++ & 0x3F)) = *a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1F66
// Name: protected: unsigned int D3DXShader::CPreProcessor::Escape(char const __near *,unsigned int,char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPreProcessor::Escape(
        D3DXShader::CPreProcessor *this,
        const char *a2,
        unsigned int a3,
        char *a4)
{
  unsigned int result; // eax
  int v5; // edi
  BOOL i; // edx

  result = 0;
  v5 = 0;
  for ( i = false; a3 != 0; --a3 )
  {
    if ( *a2 == 34 )
    {
      if ( a4 != nullptr )
        a4[result] = 92;
      ++result;
      if ( v5 == 0 )
        i = !i;
    }
    v5 = 0;
    if ( i && *a2 == 92 )
    {
      if ( a4 != nullptr )
        a4[result] = 92;
      ++result;
      v5 = 1;
    }
    if ( a4 != nullptr )
      a4[result] = *a2;
    ++result;
    ++a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10093660
// Name: _GAS_GlobalASSetPropFlags_::_27_::MemberVisitor::Visit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall GAS_GlobalASSetPropFlags_::_27_::MemberVisitor::Visit(
        int this,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *__formal,
        unsigned __int8 flags)
{
  return (*(int (__thiscall **)(_DWORD, _DWORD, _IMAGE_SYMBOL_EX *, _DWORD))(**(_DWORD **)(this + 4) + 28))(
           a1: *(_DWORD *)(this + 4),
           a2: *(_DWORD *)(this + 8),
           a3: name,
           a4: (unsigned __int8)(*(_BYTE *)(this + 12) | flags & ~*(_BYTE *)(this + 13)));
}

//------------------------------------------------------------------------------
// Address: 0x1018C4F0
// Name: void G_AppendArray<class GArrayUnsafePOD<bool,133>,class GArrayUnsafeLH_POD<bool,133>>(class GArrayUnsafePOD<bool,133> __near &,class GArrayUnsafeLH_POD<bool,133> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl G_AppendArray<GArrayUnsafePOD<bool,133>,GArrayUnsafeLH_POD<bool,133>>(_DWORD *a1, int *a2)
{
  unsigned int i; // edx
  int v3; // esi
  int v4; // eax
  _BYTE *v5; // ecx
  char result; // al

  for ( i = 0; i < a2[1]; *v5 = result )
  {
    v3 = a1[1];
    v4 = *a2;
    v5 = (_BYTE *)(v3 + *a1);
    a1[1] = v3 + 1;
    result = *(_BYTE *)(v4 + i++);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10199E30
// Name: void G_ReverseArray<class GArrayPagedLH_POD<int,6,16,136>>(class GArrayPagedLH_POD<int,6,16,136> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl G_ReverseArray<GArrayPagedLH_POD<int,6,16,136>>(_DWORD *a1)
{
  int result; // eax
  int i; // ecx
  int v3; // edx
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // ebx
  int v7; // edi

  result = *a1 - 1;
  for ( i = 0; i < result; *v4 = v7 )
  {
    v3 = a1[3];
    v4 = (_DWORD *)(*(_DWORD *)(v3 + 4 * ((unsigned int)result >> 6)) + 4 * (result & 0x3F));
    v5 = *(_DWORD *)(v3 + 4 * ((unsigned int)i >> 6));
    v6 = i & 0x3F;
    v7 = *(_DWORD *)(v5 + 4 * v6);
    ++i;
    --result;
    *(_DWORD *)(v5 + 4 * v6) = *v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1FCD
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CPreProcessor::NonNull(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CPreProcessor::NonNull(
        D3DXShader::CPreProcessor *this,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *result; // eax

  result = a2;
  if ( a2 == nullptr )
  {
    if ( *((_DWORD *)this + 17) == 0 )
    {
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CPreProcessor *)((char *)this + 24),
        a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
        a3: 0,
        format: "internal error: production failed");
      *((_DWORD *)this + 17) = 1;
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C2008
// Name: public: D3DXShader::CPPConditional::~CPPConditional(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPConditional::~CPPConditional(D3DXShader::CPPConditional *this)
{
  void *v1; // esi

  v1 = *((void **)this + 3);
  if ( v1 != nullptr )
  {
    D3DXShader::CPPConditional::~CPPConditional(this: *((D3DXShader::CPPConditional **)this + 3));
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2022
// Name: public: void D3DXShader::CPreProcessor::EnterCriticalSection(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPreProcessor::EnterCriticalSection(D3DXShader::CPreProcessor *this)
{
  D3DXCore::CAlloc *v2; // eax
  D3DXShader *v3; // [esp+0h] [ebp-4h]

  D3DXShader::Enter(this: v3);
  *((_DWORD *)this + 169) = 1;
  v2 = D3DXShader::CNode::s_pAlloc;
  D3DXShader::CNode::s_pAlloc = this;
  *((_DWORD *)this + 170) = v2;
}

//------------------------------------------------------------------------------
// Address: 0x101C2049
// Name: public: void D3DXShader::CPreProcessor::LeaveCriticalSection(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPreProcessor::LeaveCriticalSection(D3DXShader::CPreProcessor *this, D3DXShader *a2)
{
  D3DXShader::CNode::s_pAlloc = *((D3DXCore::CAlloc **)this + 170);
  *((_DWORD *)this + 169) = 0;
  D3DXShader::Leave(this: a2);
}

//------------------------------------------------------------------------------
// Address: 0x101C2060
// Name: protected: long D3DXShader::CPreProcessor::DoUndef(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoUndef(D3DXShader::CPreProcessor *this, char *a2)
{
  const char ***v2; // eax
  const char **v3; // ecx
  int v4; // edx
  const char **v5; // ecx

  v2 = (const char ***)((char *)this + 4 * D3DXShader::CPreProcessor::Hash(this, a2) + 108);
  if ( *v2 != nullptr )
  {
    do
    {
      v3 = *v2;
      v4 = strcmp(a2, **v2);
      if ( v4 < 0 )
        break;
      if ( v4 == 0 )
      {
        v5 = *v2;
        *v2 = (const char **)(*v2)[3];
        v5[3] = nullptr;
        D3DXShader::CPPDefine::`scalar deleting destructor'(this: (D3DXShader::CPPDefine *)v5, a2: 1);
        return 0;
      }
      v2 = (const char ***)(v3 + 3);
    }
    while ( v3[3] != nullptr );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C20D4
// Name: protected: long D3DXShader::CPreProcessor::DoPragma(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoPragma(D3DXShader::CPreProcessor *this)
{
  int *v2; // esi
  int result; // eax
  int v4; // [esp+Ch] [ebp-4h]

  v2 = (int *)((char *)this + 632);
  result = D3DXShader::CTokenize::GetToken(
             this: *((D3DXShader::CTokenize **)this + 155),
             a2: *((_DWORD *)this + 166),
             a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( result >= 0 )
  {
    v4 = *v2;
    if ( *v2 == 9 )
    {
      if ( strcmp(*((const char **)this + 160), "pack_matrix") == 0 )
        return D3DXShader::CPreProcessor::DoPragmaPackMatrix(this);
      if ( strcmp(*((const char **)this + 160), "warning") == 0 )
        return D3DXShader::CPreProcessor::DoPragmaWarning(this);
      if ( strcmp(*((const char **)this + 160), "def") == 0 )
        return D3DXShader::CPreProcessor::DoPragmaDef(this);
    }
    if ( v4 != 12 && v4 != 13 )
      D3DXShader::CTokenize::SkipToEOL(this: *((D3DXShader::CTokenize **)this + 155));
    result = 0;
  }
  *((_DWORD *)this + 16) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C217B
// Name: protected: long D3DXShader::CPreProcessor::AddDefine(class D3DXShader::CPPDefine __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::AddDefine(D3DXShader::CPreProcessor *this, const char **a2)
{
  const char **v2; // edi
  const char ***v3; // esi
  const char **v4; // ecx
  int v5; // eax
  const char **v6; // ecx

  v2 = a2;
  v3 = (const char ***)((char *)this + 4 * D3DXShader::CPreProcessor::Hash(this, a2: *a2) + 108);
  if ( *v3 != nullptr )
  {
    do
    {
      v4 = *v3;
      v5 = strcmp(*v2, **v3);
      v2 = a2;
      if ( v5 < 0 )
        break;
      if ( v5 == 0 )
      {
        if ( D3DXShader::CPreProcessor::AreDefinesIdentical(
               this,
               a2: (struct D3DXShader::CPPDefine *)*v3,
               a3: (struct D3DXShader::CPPDefine *)a2) == 0 )
          D3DXShader::CTErrors::Warning(
            this: (D3DXShader::CPreProcessor *)((char *)this + 24),
            a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
            a3: 0x5EFu,
            format: "'%s' : macro redefinition",
            *a2);
        v6 = *v3;
        *v3 = (const char **)(*v3)[3];
        v6[3] = nullptr;
        D3DXShader::CPPDefine::`scalar deleting destructor'(this: (D3DXShader::CPPDefine *)v6, a2: 1);
        break;
      }
      v3 = (const char ***)(v4 + 3);
    }
    while ( v4[3] != nullptr );
  }
  v2[3] = (const char *)*v3;
  *v3 = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C2232
// Name: protected: unsigned int D3DXShader::CPreProcessor::UintDefine(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPreProcessor::UintDefine(
        D3DXShader::CPreProcessor *this,
        struct D3DXShader::CNode *a2)
{
  int v4; // ecx
  struct D3DXShader::CNode *v5; // [esp+Ch] [ebp-4h] BYREF

  if ( strcmp("__LINE__", (const char *)a2) == 0 )
    return *((_DWORD *)this + 163);
  if ( D3DXShader::CPreProcessor::FindDefine(this, (const char *)a2, a3: &a2, a4: &v5) != 0 )
  {
    if ( a2 != nullptr )
    {
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CPreProcessor *)((char *)this + 24),
        a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
        a3: 0x5EDu,
        format: "functional defines in preprocessor expressions not yet implemented");
      return 1;
    }
    if ( v5 != nullptr && *((_DWORD *)v5 + 3) == 0 )
    {
      v4 = *((_DWORD *)v5 + 4);
      if ( v4 >= 2 && v4 <= 4 )
        return *((_DWORD *)v5 + 6);
    }
    D3DXShader::CTErrors::Error(
      this: (D3DXShader::CPreProcessor *)((char *)this + 24),
      a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
      a3: 0x5EEu,
      format: "invalid or unsupported integer constant expression");
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C22D9
// Name: protected: int D3DXShader::CPreProcessor::CallDefine(struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::CallDefine(
        D3DXShader::CTokenize **this,
        struct D3DXShader::D3DXTOKEN *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  D3DXShader::CPreProcessor *v4; // eax
  struct D3DXShader::CNode *v5; // esi
  int *v6; // edi
  unsigned __int8 *v7; // eax
  int v8; // eax
  int v10; // edx
  bool v11; // zf
  D3DXShader::CPreProcessor *v12; // ebx
  D3DXShader::CTokenize *v13; // esi
  char *v14; // edx
  unsigned int v15; // edi
  char v16; // cl
  _DWORD *v17; // edi
  int v18; // eax
  struct D3DXShader::D3DXTOKEN *v19; // edi
  _DWORD *v20; // esi
  unsigned __int8 *v21; // eax
  int v22; // eax
  unsigned __int8 *v23; // eax
  int v24; // eax
  struct D3DXShader::CNode *v25; // ecx
  struct D3DXShader::CNode *v26; // eax
  struct D3DXShader::CNode *v27; // eax
  const char **v28; // ebx
  struct D3DXShader::CNode *v29; // eax
  int v30; // esi
  unsigned __int8 *v31; // eax
  int v32; // eax
  unsigned __int8 *v33; // eax
  int v34; // eax
  int v35; // esi
  int v36; // eax
  int v37; // edi
  unsigned __int8 *v38; // edi
  struct D3DXShader::D3DXTOKEN *v39; // ecx
  int v40; // eax
  char v41; // bl
  int i; // esi
  int v43; // eax
  D3DXShader::CPreProcessor *v44; // ebx
  unsigned __int8 *v45; // eax
  int v46; // eax
  int v47; // ecx
  int v48; // eax
  int v49; // ebx
  struct D3DXShader::CNode *v50; // eax
  unsigned int v51; // [esp-8h] [ebp-8Ch]
  _BYTE v52[56]; // [esp+Ch] [ebp-78h] BYREF
  _BYTE v53[32]; // [esp+44h] [ebp-40h] BYREF
  unsigned int v54; // [esp+64h] [ebp-20h]
  struct D3DXShader::CNode *v55; // [esp+68h] [ebp-1Ch] BYREF
  char *v56; // [esp+6Ch] [ebp-18h]
  struct D3DXShader::D3DXTOKEN *v57; // [esp+70h] [ebp-14h]
  struct D3DXShader::D3DXTOKEN *v58; // [esp+74h] [ebp-10h]
  int v59; // [esp+78h] [ebp-Ch] BYREF
  int v60; // [esp+7Ch] [ebp-8h]
  D3DXShader::CPreProcessor *v61; // [esp+80h] [ebp-4h]
  struct D3DXShader::D3DXTOKEN *v62; // [esp+8Ch] [ebp+8h]
  struct D3DXShader::D3DXTOKEN *v63; // [esp+8Ch] [ebp+8h]
  struct D3DXShader::CNode *v64; // [esp+90h] [ebp+Ch]
  struct D3DXShader::CNode *v65; // [esp+94h] [ebp+10h]
  int v66; // [esp+94h] [ebp+10h]
  struct D3DXShader::CNode *v67; // [esp+94h] [ebp+10h]

  v55 = nullptr;
  v59 = 0;
  v4 = (D3DXShader::CPreProcessor *)this;
  v61 = (D3DXShader::CPreProcessor *)this;
  if ( a3 == nullptr )
  {
    v5 = a4;
    v6 = &v59;
    if ( a4 != nullptr )
    {
      while ( 1 )
      {
        v7 = D3DXShader::CNode::operator new(a1: 0x30u);
        v8 = v7 != nullptr
           ? D3DXShader::CNodeToken::CNodeToken(
               this: (D3DXShader::CNodeToken *)v7,
               a2: (struct D3DXShader::CNode *)((char *)v5 + 16))
           : 0;
        *v6 = v8;
        if ( v8 == 0 )
          return 0;
        v5 = *((struct D3DXShader::CNode **)v5 + 3);
        v6 = (int *)(v8 + 12);
        if ( v5 == nullptr )
        {
          v4 = v61;
          break;
        }
      }
    }
    *v6 = *((_DWORD *)v4 + 25);
    *((_DWORD *)v4 + 25) = v59;
    return 1;
  }
  v10 = (int)*(this + 25);
  if ( v10 != 0 )
  {
    qmemcpy(this + 158, (const void *)(v10 + 16), 0x20u);
    v11 = *(this + 158) == (D3DXShader::CTokenize *)1;
    v58 = (struct D3DXShader::D3DXTOKEN *)(this + 158);
    if ( !v11 )
      return 0;
    v56 = (char *)v61 + 640;
    if ( strcmp((const char *)v61 + 640, "(") != 0 )
      return 0;
    v12 = v61;
    *((_DWORD *)v61 + 25) = *(_DWORD *)(v10 + 12);
    *(_DWORD *)(v10 + 12) = 0;
  }
  else
  {
    v13 = *(this + 155);
    v14 = *(char **)v13;
    v15 = *((_DWORD *)v13 + 1);
    if ( *(_DWORD *)v13 < v15 )
    {
      do
      {
        v16 = *v14;
        if ( *v14 != 32 && (v16 < 9 || v16 > 13) )
          break;
        ++v14;
      }
      while ( (unsigned int)v14 < *(_DWORD *)(*((_DWORD *)v4 + 155) + 4) );
      if ( (unsigned int)v14 < v15 )
      {
        if ( *v14 != 40 )
          return 0;
        v4 = v61;
      }
    }
    v17 = (_DWORD *)((char *)v4 + 632);
    v51 = *((_DWORD *)v4 + 166);
    v58 = (D3DXShader::CPreProcessor *)((char *)v4 + 632);
    if ( D3DXShader::CTokenize::GetToken(this: v13, a2: v51, a3: (D3DXShader::CPreProcessor *)((char *)v4 + 632)) < 0 )
      return 0;
    if ( *v17 != 1 )
      return 0;
    v56 = (char *)v61 + 640;
    if ( strcmp((const char *)v61 + 640, "(") != 0 )
      return 0;
    v12 = v61;
  }
  v57 = nullptr;
  v60 = 1;
  v54 = (unsigned int)&v55;
  do
  {
    v18 = *((_DWORD *)v12 + 25);
    v19 = v58;
    if ( v18 != 0 )
    {
      qmemcpy(v58, (const void *)(v18 + 16), 0x20u);
      v19 = v58;
      *((_DWORD *)v12 + 25) = *(_DWORD *)(v18 + 12);
      *(_DWORD *)(v18 + 12) = 0;
    }
    else
    {
      if ( D3DXShader::CTokenize::GetToken(
             this: *((D3DXShader::CTokenize **)v12 + 155),
             a2: *((_DWORD *)v12 + 166),
             a3: v58) < 0 )
        return 0;
      v12 = v61;
    }
    if ( *(_DWORD *)v19 == 13 )
    {
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CPreProcessor *)((char *)v12 + 24),
        a2,
        a3: 0x5EBu,
        format: "unexpected end of file in macro expansion");
      return 0;
    }
    v20 = (_DWORD *)v54;
    if ( *(_DWORD *)v54 == 0 )
    {
      v21 = D3DXShader::CNode::operator new(a1: 0x14u);
      if ( v21 != nullptr )
        v22 = D3DXShader::CNodeList::CNodeList(this: (D3DXShader::CNodeList *)v21, a2: nullptr, a3: nullptr, a4: "Arg");
      else
        v22 = 0;
      *(_DWORD *)v54 = v22;
      if ( v22 == 0 )
        return 0;
      v12 = v61;
      v57 = (struct D3DXShader::D3DXTOKEN *)(v22 + 8);
    }
    if ( v60 == 1 && *(_DWORD *)v19 == 1 && (*v56 == 44 || *v56 == 41) && *((_BYTE *)v12 + 641) == 0 )
    {
      v54 = *v20 + 12;
    }
    else
    {
      v23 = D3DXShader::CNode::operator new(a1: 0x30u);
      if ( v23 != nullptr )
        v24 = D3DXShader::CNodeToken::CNodeToken(this: (D3DXShader::CNodeToken *)v23, a2: v19);
      else
        v24 = 0;
      *(_DWORD *)v57 = v24;
      if ( v24 == 0 )
        return 0;
      v12 = v61;
      v57 = (struct D3DXShader::D3DXTOKEN *)(v24 + 12);
    }
    if ( *(_DWORD *)v19 == 1 && *((_BYTE *)v12 + 641) == 0 )
    {
      if ( *v56 != 40 )
      {
        if ( *v56 == 41 )
          goto LABEL_58;
        if ( *v56 != 91 )
        {
          if ( *v56 == 93 )
            goto LABEL_58;
          if ( *v56 != 123 )
          {
            if ( *v56 != 125 )
              continue;
LABEL_58:
            --v60;
            continue;
          }
        }
      }
      ++v60;
    }
  }
  while ( v60 != 0 );
  v25 = a3;
  v26 = v55;
  do
  {
    if ( v26 == nullptr )
      break;
    if ( *((_DWORD *)v26 + 2) == 0 )
      break;
    v25 = *((struct D3DXShader::CNode **)v25 + 3);
    v26 = *((struct D3DXShader::CNode **)v26 + 3);
  }
  while ( v25 != nullptr );
  if ( v25 == nullptr && v26 == nullptr )
  {
    v62 = (struct D3DXShader::D3DXTOKEN *)&v59;
    v27 = a4;
    v60 = 0;
    v58 = nullptr;
    v56 = nullptr;
    v54 = (unsigned int)a4;
    if ( a4 == nullptr )
    {
LABEL_118:
      v63 = (struct D3DXShader::D3DXTOKEN *)&v59;
      if ( v59 != 0 )
      {
        do
        {
          v47 = *(_DWORD *)(*(_DWORD *)v63 + 12);
          v64 = *(struct D3DXShader::CNode **)v63;
          if ( v47 != 0 )
            v55 = *(struct D3DXShader::CNode **)(v47 + 12);
          else
            v55 = nullptr;
          v48 = v47 != 0 ? v47 + 16 : 0;
          v49 = v55 != nullptr ? (unsigned int)v55 + 16 : 0;
          if ( v47 != 0 && v55 != nullptr && *(_DWORD *)v48 == 1 && strcmp((const char *)(v48 + 8), "##") == 0 )
          {
            v54 = *(_DWORD *)(v55 != nullptr ? (unsigned int)v55 + 16 + 0x1C : 28) + *((_DWORD *)v64 + 11);
            v67 = (struct D3DXShader::CNode *)D3DXCore::CAlloc::Alloc(this: v61, a2: v54, a3: 1u);
            if ( v67 == nullptr )
              return 0;
            qmemcpy(v67, *((const void **)v64 + 10), *((_DWORD *)v64 + 11));
            qmemcpy((char *)v67 + *((_DWORD *)v64 + 11), *(const void **)(v49 + 24), *(_DWORD *)(v49 + 28));
            D3DXShader::CTokenize::CTokenize(this: (D3DXShader::CTokenize *)v52);
            if ( D3DXShader::CTokenize::Initialize(
                   this: (D3DXShader::CTokenize *)v52,
                   a2: v67,
                   a3: v54,
                   a4: *((const char **)v64 + 8),
                   a5: *((_DWORD *)v64 + 9),
                   a6: v61,
                   a7: (D3DXShader::CPreProcessor *)((char *)v61 + 24)) < 0
              || D3DXShader::CTokenize::GetToken(
                   this: (D3DXShader::CTokenize *)v52,
                   a2: *((_DWORD *)v61 + 166),
                   a3: (struct D3DXShader::CNode *)((char *)v64 + 16)) < 0 )
            {
              goto LABEL_133;
            }
            v50 = v55;
            *((_DWORD *)v64 + 3) = *((_DWORD *)v55 + 3);
            *((_DWORD *)v50 + 3) = 0;
            D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v52);
          }
          v63 = (struct D3DXShader::D3DXTOKEN *)(*(_DWORD *)v63 + 12);
        }
        while ( *(_DWORD *)v63 != 0 );
        v12 = v61;
      }
      *(_DWORD *)v63 = *((_DWORD *)v12 + 25);
      *((_DWORD *)v12 + 25) = v59;
      return 1;
    }
    while ( 2 )
    {
      v28 = (const char **)((char *)v27 + 16);
      v57 = v62;
      if ( v60 == 0 && v58 == nullptr )
      {
        if ( *v28 == (const char *)1 && strcmp((const char *)v27 + 24, "#") == 0 )
        {
          v56 = (char *)v27 + 16;
          v60 = 1;
          goto LABEL_116;
        }
        if ( *v28 == (const char *)1 && strcmp((const char *)v27 + 24, "#@") == 0 )
        {
          v56 = (char *)v27 + 16;
          v58 = (struct D3DXShader::D3DXTOKEN *)1;
LABEL_116:
          v54 = *(_DWORD *)(v54 + 12);
          v27 = (struct D3DXShader::CNode *)v54;
          if ( v54 == 0 )
          {
            v12 = v61;
            goto LABEL_118;
          }
          continue;
        }
      }
      break;
    }
    if ( *v28 != (const char *)9 )
      goto LABEL_90;
    v29 = a3;
    v65 = v55;
    do
    {
      if ( strcmp(*((const char **)v29 + 6), v28[2]) == 0 )
        break;
      v29 = *((struct D3DXShader::CNode **)v29 + 3);
      v65 = *((struct D3DXShader::CNode **)v65 + 3);
    }
    while ( v29 != nullptr );
    if ( v29 != nullptr )
    {
      v30 = *((_DWORD *)v65 + 2);
      while ( v30 != 0 )
      {
        v31 = D3DXShader::CNode::operator new(a1: 0x30u);
        if ( v31 != nullptr )
          v32 = D3DXShader::CNodeToken::CNodeToken(
                  this: (D3DXShader::CNodeToken *)v31,
                  a2: (const struct D3DXShader::D3DXTOKEN *)(v30 + 16));
        else
          v32 = 0;
        *(_DWORD *)v62 = v32;
        if ( v32 == 0 )
          return 0;
        v30 = *(_DWORD *)(v30 + 12);
        v62 = (struct D3DXShader::D3DXTOKEN *)(v32 + 12);
      }
    }
    else
    {
LABEL_90:
      v33 = D3DXShader::CNode::operator new(a1: 0x30u);
      if ( v33 != nullptr )
        v34 = D3DXShader::CNodeToken::CNodeToken(
                this: (D3DXShader::CNodeToken *)v33,
                a2: (const struct D3DXShader::D3DXTOKEN *)v28);
      else
        v34 = 0;
      *(_DWORD *)v62 = v34;
      if ( v34 == 0 )
        return 0;
      v62 = (struct D3DXShader::D3DXTOKEN *)(v34 + 12);
    }
    if ( v60 != 0 || v58 != nullptr )
    {
      v35 = *(_DWORD *)v57;
      v36 = 0;
      v37 = 1;
      while ( v35 != 0 )
      {
        if ( v36 != 0 && v36 != *(_DWORD *)(v35 + 40) )
          ++v37;
        v37 += D3DXShader::CPreProcessor::Escape(
                 this: v61,
                 a2: *(const char **)(v35 + 40),
                 a3: *(_DWORD *)(v35 + 44),
                 a4: nullptr);
        v36 = *(_DWORD *)(v35 + 44) + *(_DWORD *)(v35 + 40);
        v35 = *(_DWORD *)(v35 + 12);
      }
      v38 = D3DXCore::CAlloc::Alloc(this: v61, a2: v37 + 1, a3: 1u);
      if ( v38 == nullptr )
        return 0;
      v39 = v57;
      v40 = 0;
      v66 = 1;
      v41 = v60 == 0 ? 39 : 34;
      *v38 = v41;
      for ( i = *(_DWORD *)v39; i != 0; i = *(_DWORD *)(i + 12) )
      {
        if ( v40 != 0 && v40 != *(_DWORD *)(i + 40) )
        {
          v43 = v66++;
          v38[v43] = 32;
        }
        v66 += D3DXShader::CPreProcessor::Escape(
                 this: v61,
                 a2: *(const char **)(i + 40),
                 a3: *(_DWORD *)(i + 44),
                 a4: (char *)&v38[v66]);
        v40 = *(_DWORD *)(i + 40) + *(_DWORD *)(i + 44);
      }
      v38[v66] = v41;
      D3DXShader::CTokenize::CTokenize(this: (D3DXShader::CTokenize *)v52);
      v44 = v61;
      if ( D3DXShader::CTokenize::Initialize(
             this: (D3DXShader::CTokenize *)v52,
             a2: v38,
             a3: v66 + 1,
             a4: *((const char **)v56 + 4),
             a5: *((_DWORD *)v56 + 5),
             a6: v61,
             a7: (D3DXShader::CPreProcessor *)((char *)v61 + 24)) < 0
        || D3DXShader::CTokenize::GetToken(
             this: (D3DXShader::CTokenize *)v52,
             a2: *((_DWORD *)v44 + 166),
             a3: (struct D3DXShader::D3DXTOKEN *)v53) < 0
        || ((v45 = D3DXShader::CNode::operator new(a1: 0x30u)) == nullptr
          ? (v46 = 0)
          : (v46 = D3DXShader::CNodeToken::CNodeToken(
                     this: (D3DXShader::CNodeToken *)v45,
                     a2: (const struct D3DXShader::D3DXTOKEN *)v53)),
            *(_DWORD *)v57 = v46,
            v46 == 0) )
      {
LABEL_133:
        D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v52);
        return 0;
      }
      v58 = nullptr;
      v60 = 0;
      v62 = (struct D3DXShader::D3DXTOKEN *)(v46 + 12);
      D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v52);
    }
    goto LABEL_116;
  }
  D3DXShader::CTErrors::Error(
    this: (D3DXShader::CPreProcessor *)((char *)v12 + 24),
    a2,
    a3: 0x5ECu,
    format: "not enough actual parameters for macro '%s'",
    *((const char **)a2 + 2));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C299E
// Name: public: D3DXShader::CPreProcessor::CPreProcessor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPreProcessor *__thiscall D3DXShader::CPreProcessor::CPreProcessor(D3DXShader::CPreProcessor *this)
{
  char *v2; // eax
  char *v3; // eax

  D3DXCore::CAlloc::CAlloc(this, a2: 0x100000u, a3: 0x10000u);
  D3DXShader::CTErrors::CTErrors(this: (D3DXShader::CPreProcessor *)((char *)this + 24));
  *((_DWORD *)this + 169) = 0;
  D3DXShader::CPreProcessor::EnterCriticalSection(this);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 1;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 1;
  *((_DWORD *)this + 20) = 1;
  *((_DWORD *)this + 21) = 1;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 154) = 0;
  *((_DWORD *)this + 155) = 0;
  memset((char *)this + 108, 0, 0x1FCu);
  memset((char *)this + 632, 0, 0x20u);
  *((_DWORD *)this + 166) = 1;
  v2 = setlocale(_category: 4, _locale: nullptr);
  v3 = _strdup(string: v2);
  *((_DWORD *)this + 167) = v3;
  if ( v3 == nullptr || strcmp(v3, "C") != 0 )
    setlocale(_category: 4, _locale: "C");
  *((_DWORD *)this + 168) = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0xFFFFFFFF, mask: 0x8001Fu);
  _controlfp(newctrl: 0, mask: 0x30000u);
  D3DXCheckNewDelete();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C2A8B
// Name: public: D3DXShader::CPreProcessor::~CPreProcessor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPreProcessor::~CPreProcessor(D3DXShader::CPreProcessor *this)
{
  D3DXShader::CPPPragmaDef *v2; // ecx
  D3DXShader::CPPBlock *v3; // ecx
  D3DXShader::CPPInclude *v4; // ecx
  D3DXShader::CPPDefine **v5; // esi
  int i; // edi
  D3DXShader *v7; // [esp+0h] [ebp-4h]

  v2 = *((D3DXShader::CPPPragmaDef **)this + 15);
  if ( v2 != nullptr )
    D3DXShader::CPPPragmaDef::`scalar deleting destructor'(this: v2, a2: 1);
  v3 = *((D3DXShader::CPPBlock **)this + 26);
  if ( v3 != nullptr )
    D3DXShader::CPPBlock::`scalar deleting destructor'(this: v3, a2: 1);
  v4 = *((D3DXShader::CPPInclude **)this + 154);
  if ( v4 != nullptr )
    D3DXShader::CPPInclude::`scalar deleting destructor'(this: v4, a2: 1);
  v5 = (D3DXShader::CPPDefine **)((char *)this + 108);
  for ( i = 127; i != 0; --i )
  {
    if ( *v5 != nullptr )
      D3DXShader::CPPDefine::`scalar deleting destructor'(this: *v5, a2: 1);
    ++v5;
  }
  if ( *((_DWORD *)this + 167) != 0 && strcmp(*((const char **)this + 167), "C") != 0 )
    setlocale(_category: 4, _locale: *((const char **)this + 167));
  if ( *((_DWORD *)this + 167) != 0 )
    free(pMem: *((void **)this + 167));
  _controlfp(newctrl: *((_DWORD *)this + 168), mask: 0xB001Fu);
  if ( *((_DWORD *)this + 169) != 0 )
    D3DXShader::CPreProcessor::LeaveCriticalSection(this, a2: v7);
  D3DXShader::CTErrors::~CTErrors(this: (D3DXShader::CPreProcessor *)((char *)this + 24));
  D3DXCore::CAlloc::~CAlloc(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C2B41
// Name: protected: int D3DXShader::CPreProcessor::Token(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::Token(D3DXShader::CPreProcessor *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax
  bool v5; // zf
  _BYTE *v6; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  BOOL v9; // eax
  BOOL v10; // ecx
  char v11; // al
  char v12; // bl
  _BYTE v13[32]; // [esp+Ch] [ebp-28h] BYREF
  struct D3DXShader::CNode *v14; // [esp+2Ch] [ebp-8h] BYREF
  struct D3DXShader::CNode *v15; // [esp+30h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 16) != 0 || *((_DWORD *)this + 18) != 0 )
  {
    *((_DWORD *)this + 158) = 12;
    return -1;
  }
  v2 = *((_DWORD *)this + 25);
  if ( v2 != 0 )
  {
    qmemcpy((char *)this + 632, (const void *)(v2 + 16), 0x20u);
    *((_DWORD *)this + 25) = *(_DWORD *)(v2 + 12);
    *(_DWORD *)(v2 + 12) = 0;
  }
  else if ( D3DXShader::CTokenize::GetToken(
              this: *((D3DXShader::CTokenize **)this + 155),
              a2: *((_DWORD *)this + 166) | 4,
              a3: (D3DXShader::CPreProcessor *)((char *)this + 632)) < 0 )
  {
    return -1;
  }
  v3 = *((_DWORD *)this + 158);
  if ( v3 == 1 )
  {
    v11 = *((_BYTE *)this + 641);
    if ( v11 == 0 )
      return *((char *)this + 640);
    if ( *((_BYTE *)this + 642) == 0 )
    {
      if ( v11 == 61 )
      {
        switch ( *((_BYTE *)this + 640) )
        {
          case '!':
            return 275;
          case '<':
            return 272;
          case '=':
            return 274;
          case '>':
            return 273;
          default:
            break;
        }
      }
      else
      {
        v12 = *((_BYTE *)this + 640);
        if ( v12 == v11 )
        {
          if ( v12 == 38 )
            return 276;
          if ( v12 == 124 )
            return 277;
        }
      }
    }
    return 281;
  }
  if ( v3 <= 1 )
    return 281;
  if ( v3 <= 4 )
    return 279;
  if ( v3 != 9 )
  {
    if ( v3 == 10 )
      return 280;
    if ( v3 == 12 || v3 == 13 )
    {
      *((_DWORD *)this + 16) = 1;
      return -1;
    }
    return 281;
  }
  if ( *((_DWORD *)this + 19) != 0 )
  {
    v5 = *((_DWORD *)this + 20) == 0;
    *((_DWORD *)this + 19) = 0;
    *((_DWORD *)this + 22) = 0;
    v6 = *((_BYTE **)this + 160);
    if ( !v5 )
    {
      if ( *v6 == 100 )
      {
        if ( strcmp(*((const char **)this + 160), "define") == 0 )
          return 257;
        goto LABEL_63;
      }
      if ( *v6 != 101 )
      {
        if ( *v6 != 105 )
        {
          if ( *v6 == 108 )
          {
            if ( strcmp(*((const char **)this + 160), "line") == 0 )
              return 259;
          }
          else if ( *v6 == 112 )
          {
            if ( strcmp(*((const char **)this + 160), "pragma") == 0 )
              return 270;
          }
          else if ( *v6 == 117 && strcmp(*((const char **)this + 160), "undef") == 0 )
          {
            return 258;
          }
          goto LABEL_63;
        }
        if ( strcmp(*((const char **)this + 160), "if") != 0 )
        {
          if ( strcmp(*((const char **)this + 160), "ifdef") == 0 )
            return 263;
          if ( strcmp(*((const char **)this + 160), "ifndef") == 0 )
            return 264;
          if ( strcmp(*((const char **)this + 160), "include") == 0 )
            return 260;
          goto LABEL_63;
        }
        result = 262;
LABEL_58:
        *((_DWORD *)this + 22) = 1;
        return result;
      }
      if ( strcmp(*((const char **)this + 160), "elif") != 0 )
      {
        if ( strcmp(*((const char **)this + 160), "else") != 0 )
        {
          if ( strcmp(*((const char **)this + 160), "endif") != 0 )
          {
            if ( strcmp(*((const char **)this + 160), "error") == 0 )
              return 261;
            goto LABEL_63;
          }
          return 267;
        }
        return 266;
      }
LABEL_57:
      result = 265;
      goto LABEL_58;
    }
    if ( *v6 != 101 )
    {
      if ( *v6 == 105
        && (strcmp(*((const char **)this + 160), "if") == 0
         || strcmp(*((const char **)this + 160), "ifdef") == 0
         || strcmp(*((const char **)this + 160), "ifndef") == 0) )
      {
        return 268;
      }
      goto LABEL_63;
    }
    if ( strcmp(*((const char **)this + 160), "else") == 0 )
      return 266;
    if ( strcmp(*((const char **)this + 160), "endif") == 0 )
      return 267;
    if ( strcmp(*((const char **)this + 160), "elif") != 0 )
    {
LABEL_63:
      *((_DWORD *)this + 19) = 1;
      return 278;
    }
    v7 = *(_DWORD **)(*((_DWORD *)this + 154) + 56);
    if ( v7 == nullptr )
    {
      *((_DWORD *)this + 20) = 1;
      goto LABEL_57;
    }
    v8 = v7[1];
    if ( v8 == 0 || *v7 != 0 )
    {
      return 269;
    }
    else
    {
      *((_DWORD *)this + 20) = v8;
      *((_DWORD *)this + 22) = 1;
      return 265;
    }
  }
  else
  {
    if ( strcmp(*((const char **)this + 160), "defined") == 0 )
    {
      *((_DWORD *)this + 22) = 0;
      return 271;
    }
    if ( *((_DWORD *)this + 22) == 0
      || D3DXShader::CPreProcessor::FindDefine(this, a2: *((const char **)this + 160), a3: &v14, a4: &v15) == 0 )
    {
      return 278;
    }
    v5 = *((_DWORD *)this + 17) == 0;
    qmemcpy(v13, (char *)this + 632, sizeof(v13));
    v9 = !v5
      || D3DXShader::CPreProcessor::CallDefine(
           (D3DXShader::CTokenize **)this,
           a2: (struct D3DXShader::D3DXTOKEN *)v13,
           a3: v14,
           a4: v15) == 0;
    *((_DWORD *)this + 17) = v9;
    if ( v9 )
    {
      result = (int)v14;
      v10 = true;
    }
    else
    {
      result = D3DXShader::CPreProcessor::Token(this);
      v10 = result == -1;
    }
    *((_DWORD *)this + 17) = v10;
    if ( v10 )
    {
      *((_DWORD *)this + 18) = 1;
      qmemcpy((char *)this + 632, v13, 32);
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CPreProcessor *)((char *)this + 24),
        a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
        a3: 0x5EEu,
        format: "invalid or unsupported integer constant expression");
      return 278;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C2FD6
// Name: protected: long D3DXShader::CPreProcessor::DoDefine(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoDefine(D3DXShader::CPreProcessor *this, D3DXShader::CPPDefine *a2, int a3)
{
  D3DXShader::CPPDefine *v4; // eax
  D3DXShader::CTokenize *v5; // ecx
  int Token; // esi
  int i; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  int v10; // ecx
  _DWORD *j; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // eax
  D3DXShader::CPPDefine *v18; // [esp+14h] [ebp+8h]
  _DWORD *v19; // [esp+18h] [ebp+Ch]
  _DWORD *v20; // [esp+18h] [ebp+Ch]

  v4 = (D3DXShader::CPPDefine *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v4 != nullptr )
    v18 = (D3DXShader::CPPDefine *)D3DXShader::CPPDefine::CPPDefine(
                                     this: v4,
                                     (const char *)a2,
                                     a3: nullptr,
                                     a4: nullptr);
  else
    v18 = nullptr;
  if ( v18 != nullptr )
  {
    if ( a3 != 0
      && *(_DWORD *)(v5 = *((D3DXShader::CTokenize **)this + 155)) < *((_DWORD *)v5 + 1)
      && **(_BYTE **)v5 == 40 )
    {
      v19 = (_DWORD *)((char *)v18 + 4);
      Token = D3DXShader::CTokenize::GetToken(
                this: v5,
                a2: *((_DWORD *)this + 166),
                a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
      if ( Token >= 0 )
      {
        while ( 1 )
        {
          Token = D3DXShader::CTokenize::GetToken(
                    this: *((D3DXShader::CTokenize **)this + 155),
                    a2: *((_DWORD *)this + 166),
                    a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
          if ( Token < 0 )
            break;
          if ( *((_DWORD *)this + 158) != 9 )
            goto LABEL_25;
          for ( i = *((_DWORD *)v18 + 1); i != 0; i = *(_DWORD *)(i + 12) )
          {
            if ( strcmp(*((const char **)this + 160), *(const char **)(i + 24)) == 0 )
            {
              D3DXShader::CTErrors::Error(
                this: (D3DXShader::CPreProcessor *)((char *)this + 24),
                a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
                a3: 0x5E7u,
                format: "duplicate macro parameter '%s'",
                *((const char **)this + 160));
              break;
            }
          }
          v8 = D3DXShader::CNode::operator new(a1: 0x30u);
          if ( v8 != nullptr )
            v9 = D3DXShader::CNodeToken::CNodeToken(
                   this: (D3DXShader::CNodeToken *)v8,
                   a2: (D3DXShader::CPreProcessor *)((char *)this + 632));
          else
            v9 = 0;
          *v19 = v9;
          if ( v9 == 0 )
            goto LABEL_40;
          v19 = (_DWORD *)(v9 + 12);
          Token = D3DXShader::CTokenize::GetToken(
                    this: *((D3DXShader::CTokenize **)this + 155),
                    a2: *((_DWORD *)this + 166),
                    a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
          if ( Token < 0 )
            break;
          if ( *((_DWORD *)this + 158) != 1 )
            goto LABEL_25;
          if ( strcmp(",", (const char *)this + 640) != 0 )
          {
            if ( strcmp(")", (const char *)this + 640) == 0 )
              goto LABEL_29;
LABEL_25:
            v10 = *((_DWORD *)this + 158);
            if ( v10 == 12 || v10 == 13 )
              *((_DWORD *)this + 16) = 1;
            D3DXShader::CTErrors::SyntaxError(
              this: (D3DXShader::CPreProcessor *)((char *)this + 24),
              a2: 0x5DCu,
              a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
            *((_DWORD *)this + 17) = 1;
            Token = -2147467259;
            break;
          }
        }
      }
    }
    else
    {
LABEL_29:
      for ( j = (_DWORD *)((char *)v18 + 8); ; j = (_DWORD *)(v16 + 12) )
      {
        v20 = j;
        v12 = *((_DWORD *)this + 25);
        if ( v12 != 0 )
        {
          qmemcpy((char *)this + 632, (const void *)(v12 + 16), 0x20u);
          *((_DWORD *)this + 25) = *(_DWORD *)(v12 + 12);
          *(_DWORD *)(v12 + 12) = 0;
          v13 = *((_DWORD *)this + 155);
          *((_DWORD *)this + 162) = *(_DWORD *)(v13 + 24);
          *((_DWORD *)this + 163) = *(_DWORD *)(v13 + 28);
        }
        else
        {
          Token = D3DXShader::CTokenize::GetToken(
                    this: *((D3DXShader::CTokenize **)this + 155),
                    a2: *((_DWORD *)this + 166),
                    a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
          if ( Token < 0 )
            goto LABEL_43;
        }
        v14 = *((_DWORD *)this + 158);
        if ( v14 == 12 || v14 == 13 )
          break;
        v15 = D3DXShader::CNode::operator new(a1: 0x30u);
        if ( v15 != nullptr )
          v16 = D3DXShader::CNodeToken::CNodeToken(
                  this: (D3DXShader::CNodeToken *)v15,
                  a2: (D3DXShader::CPreProcessor *)((char *)this + 632));
        else
          v16 = 0;
        *v20 = v16;
        if ( v16 == 0 )
          goto LABEL_40;
      }
      *((_DWORD *)this + 16) = 1;
      Token = D3DXShader::CPreProcessor::AddDefine(this, a2: (const char **)v18);
      if ( Token >= 0 )
      {
        v18 = nullptr;
        Token = 0;
      }
    }
  }
  else
  {
LABEL_40:
    Token = -2147024882;
  }
LABEL_43:
  if ( v18 != nullptr )
    D3DXShader::CPPDefine::`scalar deleting destructor'(this: v18, a2: 1);
  return Token;
}

//------------------------------------------------------------------------------
// Address: 0x101C327B
// Name: protected: long D3DXShader::CPreProcessor::InitializeDefines(struct _D3DXMACRO const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::InitializeDefines(
        D3DXShader::CPreProcessor *this,
        const struct _D3DXMACRO *a2)
{
  D3DXShader::CPPDefine *v3; // eax
  int v4; // edi
  D3DXShader::CPPDefine *v5; // eax
  D3DXShader::CPPDefine *v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // eax
  const char **v9; // ecx
  D3DXShader::CPPDefine *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // eax
  const struct _D3DXMACRO *v13; // esi
  struct D3DXCore::CAlloc *v14; // edi
  const char *Definition; // edx
  unsigned int v17; // eax
  _BYTE v18[56]; // [esp+Ch] [ebp-64h] BYREF
  _DWORD v19[8]; // [esp+44h] [ebp-2Ch] BYREF
  int v20; // [esp+64h] [ebp-Ch]
  struct D3DXCore::CAlloc *v21; // [esp+68h] [ebp-8h]
  D3DXShader::CPPDefine *v22; // [esp+6Ch] [ebp-4h]

  v20 = *((_DWORD *)this + 155);
  v21 = this;
  memset(v19, 0, sizeof(v19));
  v3 = (D3DXShader::CPPDefine *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3 = "DIRECT3D";
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    v22 = v3;
  }
  else
  {
    v22 = nullptr;
  }
  if ( v22 != nullptr )
  {
    v4 = D3DXShader::CPreProcessor::AddDefine(this, a2: (const char **)v22);
    if ( v4 < 0 )
      goto LABEL_34;
    v5 = (D3DXShader::CPPDefine *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v5 != nullptr )
    {
      *(_DWORD *)v5 = "D3DX";
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = 0;
      v22 = v5;
    }
    else
    {
      v22 = nullptr;
    }
    if ( v22 != nullptr )
    {
      v4 = D3DXShader::CPreProcessor::AddDefine(this, a2: (const char **)v22);
      if ( v4 < 0 )
        goto LABEL_34;
      v19[0] = 2;
      v19[2] = 2304;
      v6 = (D3DXShader::CPPDefine *)MemAlloc_Alloc(nSize: 0x14u);
      if ( v6 != nullptr )
      {
        *(_DWORD *)v6 = "DIRECT3D_VERSION";
        *((_DWORD *)v6 + 1) = 0;
        *((_DWORD *)v6 + 2) = 0;
        *((_DWORD *)v6 + 3) = 0;
        *((_DWORD *)v6 + 4) = 0;
        v22 = v6;
      }
      else
      {
        v22 = nullptr;
      }
      if ( v22 != nullptr )
      {
        v7 = D3DXShader::CNode::operator new(a1: 0x30u);
        v8 = v7 != nullptr
           ? D3DXShader::CNodeToken::CNodeToken(
               this: (D3DXShader::CNodeToken *)v7,
               a2: (const struct D3DXShader::D3DXTOKEN *)v19)
           : 0;
        v9 = (const char **)v22;
        *((_DWORD *)v22 + 2) = v8;
        if ( v8 != 0 )
        {
          v4 = D3DXShader::CPreProcessor::AddDefine(this: v21, a2: v9);
          if ( v4 < 0 )
            goto LABEL_34;
          v19[0] = 2;
          v19[2] = 2306;
          v10 = (D3DXShader::CPPDefine *)MemAlloc_Alloc(nSize: 0x14u);
          if ( v10 != nullptr )
          {
            *(_DWORD *)v10 = "D3DX_VERSION";
            *((_DWORD *)v10 + 1) = 0;
            *((_DWORD *)v10 + 2) = 0;
            *((_DWORD *)v10 + 3) = 0;
            *((_DWORD *)v10 + 4) = 0;
            v22 = v10;
          }
          else
          {
            v22 = nullptr;
          }
          if ( v22 != nullptr )
          {
            v11 = D3DXShader::CNode::operator new(a1: 0x30u);
            v12 = v11 != nullptr
                ? D3DXShader::CNodeToken::CNodeToken(
                    this: (D3DXShader::CNodeToken *)v11,
                    a2: (const struct D3DXShader::D3DXTOKEN *)v19)
                : 0;
            *((_DWORD *)v22 + 2) = v12;
            if ( v12 != 0 )
            {
              v4 = D3DXShader::CPreProcessor::AddDefine(this: v21, a2: (const char **)v22);
              if ( v4 >= 0 )
              {
                v13 = a2;
                v22 = nullptr;
                if ( a2 == nullptr )
                {
LABEL_33:
                  v4 = 0;
                  goto LABEL_34;
                }
                D3DXShader::CTokenize::CTokenize(this: (D3DXShader::CTokenize *)v18);
                v14 = v21;
                *((_DWORD *)v21 + 155) = v18;
                if ( a2->Name == nullptr )
                {
LABEL_32:
                  D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v18);
                  goto LABEL_33;
                }
                while ( 1 )
                {
                  Definition = v13->Definition;
                  v17 = Definition != nullptr ? strlen(v13->Definition) : 0;
                  v4 = D3DXShader::CTokenize::Initialize(
                         this: (D3DXShader::CTokenize *)v18,
                         a2: Definition,
                         a3: v17,
                         a4: nullptr,
                         a5: 0,
                         a6: v14,
                         a7: (struct D3DXCore::CAlloc *)((char *)v14 + 24));
                  if ( v4 < 0 )
                    break;
                  v4 = D3DXShader::CPreProcessor::DoDefine(this: v21, a2: (D3DXShader::CPPDefine *)v13->Name, a3: 0);
                  if ( v4 < 0 )
                    break;
                  ++v13;
                  if ( v13->Name == nullptr )
                    goto LABEL_32;
                  v14 = v21;
                }
                D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v18);
              }
LABEL_34:
              *((_DWORD *)v21 + 155) = v20;
              if ( v22 != nullptr )
                D3DXShader::CPPDefine::`scalar deleting destructor'(this: v22, a2: 1);
              return v4;
            }
          }
        }
      }
    }
  }
  v4 = -2147024882;
  goto LABEL_34;
}

//------------------------------------------------------------------------------
// Address: 0x101C34B4
// Name: protected: void D3DXShader::CPreProcessor::Production(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPreProcessor::Production(
        D3DXShader::CPreProcessor *this,
        unsigned int a2,
        unsigned int a3)
{
  struct D3DXShader::CNode *v4; // edi
  int v6; // eax
  int Define; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  bool v11; // cf
  bool v12; // cf
  int v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // eax
  const char *v18; // [esp-Ch] [ebp-58h]
  struct D3DXShader::CNode *v19; // [esp-4h] [ebp-50h]
  int v20; // [esp+Ch] [ebp-40h]
  int v21; // [esp+10h] [ebp-3Ch]
  int v22; // [esp+14h] [ebp-38h]

  v4 = nullptr;
  if ( *((_DWORD *)this + 17) == 0 )
  {
    while ( a3 != 0 )
    {
      v6 = *((_DWORD *)this + 23);
      --a3;
      if ( v6 == 0 )
      {
        D3DXShader::CTErrors::Error(
          this: (D3DXShader::CPreProcessor *)((char *)this + 24),
          a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
          a3: 0,
          format: "internal error: stack underflow");
        goto LABEL_72;
      }
      *(&v20 + a3) = *(_DWORD *)(v6 + 8);
      *((_DWORD *)this + 23) = *(_DWORD *)(v6 + 12);
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 12) = *((_DWORD *)this + 24);
      *((_DWORD *)this + 24) = v6;
    }
    switch ( a2 )
    {
      case 0u:
        D3DXShader::CPreProcessor::DoDefine(this, a2: *(D3DXShader::CPPDefine **)(v20 + 24), a3: 1);
        goto LABEL_62;
      case 1u:
        D3DXShader::CPreProcessor::DoUndef(this, a2: *(char **)(v20 + 24));
        goto LABEL_62;
      case 2u:
        D3DXShader::CPreProcessor::DoLine(this, a2: *(_DWORD *)(v20 + 24), a3: nullptr);
        goto LABEL_62;
      case 3u:
        D3DXShader::CPreProcessor::DoLine(this, a2: *(_DWORD *)(v20 + 24), a3: *(const char **)(v21 + 24));
        goto LABEL_62;
      case 4u:
        D3DXShader::CPreProcessor::DoInclude(this);
        goto LABEL_62;
      case 5u:
        D3DXShader::CPreProcessor::DoError(this);
        goto LABEL_62;
      case 6u:
        D3DXShader::CPreProcessor::DoIf(this, a2: *(_DWORD *)(v20 + 24));
        goto LABEL_62;
      case 7u:
        Define = D3DXShader::CPreProcessor::FindDefine(this, a2: *(const char **)(v20 + 24), a3: nullptr, a4: nullptr);
        goto LABEL_18;
      case 8u:
        Define = D3DXShader::CPreProcessor::FindDefine(this, a2: *(const char **)(v20 + 24), a3: nullptr, a4: nullptr) == 0;
LABEL_18:
        D3DXShader::CPreProcessor::DoIf(this, a2: Define);
        goto LABEL_62;
      case 9u:
        D3DXShader::CPreProcessor::DoElif(this, a2: *(_DWORD *)(v20 + 24));
        goto LABEL_62;
      case 0xAu:
        D3DXShader::CPreProcessor::DoElse(this);
        goto LABEL_62;
      case 0xBu:
        D3DXShader::CPreProcessor::DoEndif(this);
        goto LABEL_62;
      case 0xCu:
        D3DXShader::CPreProcessor::DoIf(this, a2: 1);
        goto LABEL_23;
      case 0xDu:
        D3DXShader::CPreProcessor::DoElif(this, a2: 1);
LABEL_23:
        D3DXShader::CTokenize::SkipToEOL(this: *((D3DXShader::CTokenize **)this + 155));
        goto LABEL_62;
      case 0xEu:
        D3DXShader::CPreProcessor::DoPragma(this);
        goto LABEL_62;
      case 0xFu:
      case 0x10u:
      case 0x13u:
      case 0x16u:
      case 0x17u:
      case 0x1Au:
      case 0x1Du:
      case 0x22u:
      case 0x25u:
      case 0x27u:
      case 0x29u:
      case 0x2Bu:
        v4 = (struct D3DXShader::CNode *)v20;
        goto LABEL_62;
      case 0x11u:
        v4 = (struct D3DXShader::CNode *)v20;
        v19 = *(struct D3DXShader::CNode **)(v20 + 24);
        *(_DWORD *)(v20 + 16) = 2;
        v8 = D3DXShader::CPreProcessor::UintDefine(this, a2: v19);
        goto LABEL_35;
      case 0x12u:
        v4 = (struct D3DXShader::CNode *)v20;
        v18 = *(const char **)(v20 + 24);
        *(_DWORD *)(v20 + 16) = 2;
        *((_DWORD *)v4 + 6) = D3DXShader::CPreProcessor::FindDefine(this, a2: v18, a3: nullptr, a4: nullptr);
        *((_DWORD *)this + 22) = 1;
        goto LABEL_62;
      case 0x14u:
        v4 = (struct D3DXShader::CNode *)v20;
        v9 = *(_DWORD *)(v20 + 24) == 0;
        goto LABEL_30;
      case 0x15u:
        v4 = (struct D3DXShader::CNode *)v20;
        *(_DWORD *)(v20 + 24) = -*(_DWORD *)(v20 + 24);
        goto LABEL_62;
      case 0x18u:
        v4 = (struct D3DXShader::CNode *)v20;
        v9 = *(_DWORD *)(v20 + 24) * *(_DWORD *)(v21 + 24);
        goto LABEL_30;
      case 0x19u:
        v10 = *(_DWORD *)(v21 + 24);
        v4 = (struct D3DXShader::CNode *)v20;
        if ( v10 != 0 )
        {
          v8 = *(_DWORD *)(v20 + 24) / v10;
LABEL_35:
          *((_DWORD *)v4 + 6) = v8;
        }
        else
        {
          D3DXShader::CTErrors::Error(
            this: (D3DXShader::CPreProcessor *)((char *)this + 24),
            a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
            a3: 0x5DFu,
            format: "division by zero in preprocessor expression");
          *((_DWORD *)this + 17) = 1;
        }
        goto LABEL_62;
      case 0x1Bu:
        v4 = (struct D3DXShader::CNode *)v20;
        *(_DWORD *)(v20 + 24) += *(_DWORD *)(v21 + 24);
        goto LABEL_62;
      case 0x1Cu:
        v4 = (struct D3DXShader::CNode *)v20;
        *(_DWORD *)(v20 + 24) -= *(_DWORD *)(v21 + 24);
        goto LABEL_62;
      case 0x1Eu:
        v4 = (struct D3DXShader::CNode *)v20;
        v11 = *(_DWORD *)(v20 + 24) < *(_DWORD *)(v21 + 24);
        goto LABEL_42;
      case 0x1Fu:
        v4 = (struct D3DXShader::CNode *)v20;
        v11 = *(_DWORD *)(v21 + 24) < *(_DWORD *)(v20 + 24);
LABEL_42:
        v9 = v11;
        goto LABEL_30;
      case 0x20u:
        v4 = (struct D3DXShader::CNode *)v20;
        v12 = *(_DWORD *)(v21 + 24) < *(_DWORD *)(v20 + 24);
        goto LABEL_44;
      case 0x21u:
        v4 = (struct D3DXShader::CNode *)v20;
        v12 = *(_DWORD *)(v20 + 24) < *(_DWORD *)(v21 + 24);
LABEL_44:
        v13 = -v12;
        goto LABEL_47;
      case 0x23u:
        v4 = (struct D3DXShader::CNode *)v20;
        v13 = -(*(_DWORD *)(v21 + 24) != *(_DWORD *)(v20 + 24));
LABEL_47:
        v9 = v13 + 1;
        goto LABEL_30;
      case 0x24u:
        v4 = (struct D3DXShader::CNode *)v20;
        *(_DWORD *)(v20 + 24) = *(_DWORD *)(v20 + 24) != *(_DWORD *)(v21 + 24);
        goto LABEL_62;
      case 0x26u:
        v4 = (struct D3DXShader::CNode *)v20;
        if ( *(_DWORD *)(v20 + 24) != 0 )
          goto LABEL_50;
        goto LABEL_54;
      case 0x28u:
        v4 = (struct D3DXShader::CNode *)v20;
        if ( *(_DWORD *)(v20 + 24) != 0 )
          goto LABEL_51;
LABEL_50:
        if ( *(_DWORD *)(v21 + 24) != 0 )
LABEL_51:
          v9 = 1;
        else
LABEL_54:
          v9 = 0;
LABEL_30:
        *((_DWORD *)v4 + 6) = v9;
LABEL_62:
        if ( *((_DWORD *)this + 17) != 0 )
          return;
        v16 = *((_DWORD *)this + 24);
        if ( v16 != 0 )
        {
          *((_DWORD *)this + 24) = *(_DWORD *)(v16 + 12);
          *(_DWORD *)(v16 + 8) = v4;
          *(_DWORD *)(v16 + 12) = *((_DWORD *)this + 23);
LABEL_65:
          *((_DWORD *)this + 23) = v16;
          return;
        }
        v17 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v17 != nullptr )
          v16 = D3DXShader::CNodeList::CNodeList(
                  this: (D3DXShader::CNodeList *)v17,
                  a2: v4,
                  a3: *((struct D3DXShader::CNode **)this + 23),
                  a4: "Stack");
        else
          v16 = 0;
        if ( v16 != 0 )
          goto LABEL_65;
        D3DXShader::CTErrors::Error(
          this: (D3DXShader::CPreProcessor *)((char *)this + 24),
          a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
          a3: 0,
          format: "internal error: out of memory");
LABEL_72:
        *((_DWORD *)this + 17) = 1;
        break;
      case 0x2Au:
        v4 = (struct D3DXShader::CNode *)v20;
        v14 = v21;
        if ( *(_DWORD *)(v20 + 24) == 0 )
          v14 = v22;
        v9 = *(_DWORD *)(v14 + 24);
        goto LABEL_30;
      case 0x2Cu:
      case 0x2Du:
      case 0x2Eu:
        v15 = D3DXShader::CNode::operator new(a1: 0x30u);
        if ( v15 != nullptr )
          v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeToken::CNodeToken(
                                             this: (D3DXShader::CNodeToken *)v15,
                                             a2: (D3DXShader::CPreProcessor *)((char *)this + 632));
        else
          v4 = nullptr;
        D3DXShader::CPreProcessor::NonNull(this, a2: v4);
        goto LABEL_62;
      default:
        goto LABEL_62;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C38D4
// Name: int D3DXShader::d3dxtok_parse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::d3dxtok_parse()
{
  int v0; // esi
  int v1; // eax
  int v2; // ecx
  unsigned int v3; // ecx
  int v4; // ecx
  __int16 *v5; // eax
  unsigned int v6; // ecx
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  __int16 *v11; // eax
  int v12; // edx
  bool v13; // zf
  int v15; // esi
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // eax
  __int16 *i; // ecx
  unsigned int v21; // eax

  v0 = 0;
  D3DXShader::d3dxtok_nerrs = 0;
  D3DXShader::d3dxtok_errflag = 0;
  D3DXShader::d3dxtok_ssp = (__int16 *)&D3DXShader::d3dxtok_ss;
  D3DXShader::d3dxtok_vsp = (int *)&D3DXShader::d3dxtok_vs;
  LOWORD(D3DXShader::d3dxtok_ss) = 0;
  while ( 2 )
  {
    v1 = -1;
    D3DXShader::d3dxtok_char = -1;
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *((__int16 *)&D3DXShader::d3dxtok_defred + v0);
        if ( *((_WORD *)&D3DXShader::d3dxtok_defred + v0) == 0 )
          break;
LABEL_17:
        v8 = 2 * v2;
        v9 = *((__int16 *)&D3DXShader::d3dxtok_len + v2);
        D3DXShader::d3dxtok_val = D3DXShader::d3dxtok_vsp[-v9 + 1];
        switch ( v2 )
        {
          case 1:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0, a3: 1u);
            break;
          case 2:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 1u, a3: 1u);
            break;
          case 3:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 2u, a3: 1u);
            break;
          case 4:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 3u, a3: 2u);
            break;
          case 5:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 4u, a3: 0);
            break;
          case 6:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 5u, a3: 0);
            break;
          case 7:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 6u, a3: 1u);
            break;
          case 8:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 7u, a3: 1u);
            break;
          case 9:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 8u, a3: 1u);
            break;
          case 10:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 9u, a3: 1u);
            break;
          case 11:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0xAu, a3: 0);
            break;
          case 12:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0xBu, a3: 0);
            break;
          case 13:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0xCu, a3: 0);
            break;
          case 14:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0xDu, a3: 0);
            break;
          case 15:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0xEu, a3: 0);
            break;
          case 16:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0xFu, a3: 1u);
            break;
          case 17:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x10u, a3: 1u);
            break;
          case 18:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x11u, a3: 1u);
            break;
          case 19:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x12u, a3: 1u);
            break;
          case 20:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x13u, a3: 1u);
            break;
          case 21:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x14u, a3: 1u);
            break;
          case 22:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x15u, a3: 1u);
            break;
          case 23:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x16u, a3: 1u);
            break;
          case 24:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x17u, a3: 1u);
            break;
          case 25:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x18u, a3: 2u);
            break;
          case 26:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x19u, a3: 2u);
            break;
          case 27:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x1Au, a3: 1u);
            break;
          case 28:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x1Bu, a3: 2u);
            break;
          case 29:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x1Cu, a3: 2u);
            break;
          case 30:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x1Du, a3: 1u);
            break;
          case 31:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x1Eu, a3: 2u);
            break;
          case 32:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x1Fu, a3: 2u);
            break;
          case 33:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x20u, a3: 2u);
            break;
          case 34:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x21u, a3: 2u);
            break;
          case 35:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x22u, a3: 1u);
            break;
          case 36:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x23u, a3: 2u);
            break;
          case 37:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x24u, a3: 2u);
            break;
          case 38:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x25u, a3: 1u);
            break;
          case 39:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x26u, a3: 2u);
            break;
          case 40:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x27u, a3: 1u);
            break;
          case 41:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x28u, a3: 2u);
            break;
          case 42:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x29u, a3: 1u);
            break;
          case 43:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x2Au, a3: 3u);
            break;
          case 44:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x2Bu, a3: 1u);
            break;
          case 45:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x2Cu, a3: 0);
            break;
          case 46:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x2Du, a3: 0);
            break;
          case 47:
            D3DXShader::CPreProcessor::Production(this: D3DXShader::CPreProcessor::s_pPP, a2: 0x2Eu, a3: 0);
            break;
          default:
            break;
        }
        v10 = *(__int16 *)((char *)&D3DXShader::d3dxtok_lhs + v8);
        v11 = &D3DXShader::d3dxtok_ssp[-v9];
        D3DXShader::d3dxtok_ssp = v11;
        v12 = *v11;
        D3DXShader::d3dxtok_vsp -= v9;
        if ( v12 != 0 || v10 != 0 )
        {
          v15 = 2 * v10;
          v16 = *((__int16 *)&D3DXShader::d3dxtok_gindex + v10);
          if ( v16 != 0
            && (unsigned int)(v17 = v12 + v16) <= 0x171
            && (v18 = 2 * v17, *(__int16 *)((char *)&D3DXShader::d3dxtok_check + v18) == v12) )
          {
            v0 = *(__int16 *)((char *)&D3DXShader::d3dxtok_table + v18);
          }
          else
          {
            v0 = *(__int16 *)((char *)&D3DXShader::d3dxtok_dgoto + v15);
          }
          if ( v11 >= &word_1035A59E )
            goto LABEL_93;
          D3DXShader::d3dxtok_ssp = v11 + 1;
          v11[1] = v0;
          v19 = D3DXShader::d3dxtok_val;
LABEL_90:
          *++D3DXShader::d3dxtok_vsp = v19;
          v1 = D3DXShader::d3dxtok_char;
        }
        else
        {
          D3DXShader::d3dxtok_ssp = v11 + 1;
          v0 = 15;
          v11[1] = 15;
          *++D3DXShader::d3dxtok_vsp = D3DXShader::d3dxtok_val;
          v1 = D3DXShader::d3dxtok_char;
          v13 = D3DXShader::d3dxtok_char == 0;
          if ( D3DXShader::d3dxtok_char < 0 )
          {
            v1 = D3DXShader::CPreProcessor::Token(this: D3DXShader::CPreProcessor::s_pPP);
            v13 = v1 == 0;
            D3DXShader::d3dxtok_char = v1;
            if ( v1 < 0 )
            {
              v1 = 0;
              D3DXShader::d3dxtok_char = 0;
              v13 = true;
            }
          }
          if ( v13 )
            return 0;
        }
      }
      if ( v1 < 0 )
      {
        v1 = D3DXShader::CPreProcessor::Token(this: D3DXShader::CPreProcessor::s_pPP);
        D3DXShader::d3dxtok_char = v1;
        if ( v1 < 0 )
        {
          v1 = 0;
          D3DXShader::d3dxtok_char = 0;
        }
      }
      if ( *((_WORD *)&D3DXShader::d3dxtok_sindex + v0) == 0 )
        break;
      v3 = v1 + *((__int16 *)&D3DXShader::d3dxtok_sindex + v0);
      if ( v3 > 0x171 )
        break;
      v4 = 2 * v3;
      if ( *(__int16 *)((char *)&D3DXShader::d3dxtok_check + v4) != v1 )
        break;
      v5 = D3DXShader::d3dxtok_ssp;
      if ( D3DXShader::d3dxtok_ssp >= &word_1035A59E )
        goto LABEL_93;
      v0 = *(__int16 *)((char *)&D3DXShader::d3dxtok_table + v4);
      ++D3DXShader::d3dxtok_ssp;
      v5[1] = v0;
      *++D3DXShader::d3dxtok_vsp = D3DXShader::d3dxtok_lval;
      v1 = -1;
      D3DXShader::d3dxtok_char = -1;
      if ( D3DXShader::d3dxtok_errflag > 0 )
        --D3DXShader::d3dxtok_errflag;
    }
    if ( *((_WORD *)&D3DXShader::d3dxtok_rindex + v0) != 0 )
    {
      v6 = v1 + *((__int16 *)&D3DXShader::d3dxtok_rindex + v0);
      if ( v6 <= 0x171 )
      {
        v7 = 2 * v6;
        if ( *(__int16 *)((char *)&D3DXShader::d3dxtok_check + v7) == v1 )
        {
          v2 = *(__int16 *)((char *)&D3DXShader::d3dxtok_table + v7);
          goto LABEL_17;
        }
      }
    }
    if ( D3DXShader::d3dxtok_errflag == 0 )
    {
      D3DXShader::CPreProcessor::Error(this: D3DXShader::CPreProcessor::s_pPP, format: "syntax error");
      ++D3DXShader::d3dxtok_nerrs;
      v1 = D3DXShader::d3dxtok_char;
    }
    if ( D3DXShader::d3dxtok_errflag >= 3 )
    {
      if ( v1 == 0 )
        return 1;
      continue;
    }
    break;
  }
  D3DXShader::d3dxtok_errflag = 3;
  for ( i = D3DXShader::d3dxtok_ssp; ; D3DXShader::d3dxtok_ssp = i )
  {
    if ( *((_WORD *)&D3DXShader::d3dxtok_sindex + *i) != 0 )
    {
      v21 = *((__int16 *)&D3DXShader::d3dxtok_sindex + *i) + 256;
      if ( v21 <= 0x171 && *((_WORD *)&D3DXShader::d3dxtok_check + v21) == 256 )
        break;
    }
    if ( i <= (__int16 *)&D3DXShader::d3dxtok_ss )
      return 1;
    --i;
    --D3DXShader::d3dxtok_vsp;
  }
  if ( i < &word_1035A59E )
  {
    v0 = *((__int16 *)&D3DXShader::d3dxtok_table + v21);
    D3DXShader::d3dxtok_ssp = i + 1;
    i[1] = v0;
    v19 = D3DXShader::d3dxtok_lval;
    goto LABEL_90;
  }
LABEL_93:
  D3DXShader::CPreProcessor::Error(this: D3DXShader::CPreProcessor::s_pPP, format: "yacc stack overflow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C3DF8
// Name: public: long D3DXShader::CPreProcessor::InitializeFromMemory(void const __near *,unsigned int,struct _D3DXMACRO const __near *,struct ID3DXInclude __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::InitializeFromMemory(
        D3DXShader::CPreProcessor *this,
        void *a2,
        unsigned int a3,
        const struct _D3DXMACRO *a4,
        struct ID3DXInclude *a5)
{
  D3DXShader::CPPInclude *v6; // eax
  D3DXShader::CPPInclude *v7; // eax
  int result; // eax

  v6 = (D3DXShader::CPPInclude *)MemAlloc_Alloc(nSize: 0x70u);
  if ( v6 != nullptr )
    v7 = (D3DXShader::CPPInclude *)D3DXShader::CPPInclude::CPPInclude(this: v6);
  else
    v7 = nullptr;
  *((_DWORD *)this + 154) = v7;
  if ( v7 == nullptr )
    return -2147024882;
  result = D3DXShader::CPPInclude::InitializeFromMemory(
             this: v7,
             a2,
             a3,
             a4: this,
             a5: (D3DXShader::CPreProcessor *)((char *)this + 24));
  if ( result >= 0 )
  {
    result = D3DXShader::CPreProcessor::InitializeDefines(this, a2: a4);
    if ( result >= 0 )
    {
      *((_DWORD *)this + 155) = *((_DWORD *)this + 154);
      *((_DWORD *)this + 156) = a5;
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C3E68
// Name: public: long D3DXShader::CPreProcessor::GetToken(struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::GetToken(D3DXShader::CPreProcessor *this, struct D3DXShader::D3DXTOKEN *a2)
{
  int v3; // eax
  int v4; // edx
  struct D3DXShader::D3DXTOKEN *v5; // eax
  int result; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // esi
  D3DXShader::CTokenize *v10; // ecx
  int v11; // eax
  int v12; // ecx
  char *v13; // ebx
  D3DXShader::CPPInclude *v14; // ecx
  int v15; // ecx
  int v16; // ecx
  struct D3DXShader::CNode *v17; // [esp+Ch] [ebp-8h] BYREF
  struct D3DXShader::CNode *v18; // [esp+10h] [ebp-4h] BYREF

  do
  {
    while ( 1 )
    {
      if ( *((_DWORD *)this + 18) != 0 )
      {
        result = -2147467259;
LABEL_44:
        v13 = (char *)this + 620;
        *((_DWORD *)a2 + 4) = *(_DWORD *)(*(_DWORD *)v13 + 24);
        *((_DWORD *)a2 + 5) = *(_DWORD *)(*(_DWORD *)v13 + 28);
        *(_DWORD *)a2 = 13;
        return result;
      }
      v3 = *((_DWORD *)this + 26);
      if ( v3 != 0 && *(_DWORD *)(v3 + 8) == 0 )
      {
        result = 0;
        goto LABEL_44;
      }
      v4 = *((_DWORD *)this + 25);
      if ( v4 != 0 )
      {
        v5 = a2;
        qmemcpy(a2, (const void *)(v4 + 16), 0x20u);
        *((_DWORD *)this + 25) = *(_DWORD *)(*((_DWORD *)this + 25) + 12);
        *(_DWORD *)(v4 + 12) = 0;
        *((_DWORD *)a2 + 4) = *(_DWORD *)(*((_DWORD *)this + 155) + 24);
        *((_DWORD *)a2 + 5) = *(_DWORD *)(*((_DWORD *)this + 155) + 28);
        *((_DWORD *)this + 16) = 0;
      }
      else
      {
        result = D3DXShader::CTokenize::GetToken(
                   this: *((D3DXShader::CTokenize **)this + 155),
                   a2: *((_DWORD *)this + 166),
                   a3: a2);
        if ( result < 0 )
          return result;
        v5 = a2;
      }
      if ( *(_DWORD *)v5 == 1 && strcmp("#", (const char *)v5 + 8) == 0 && *((_DWORD *)this + 16) != 0 )
        break;
      if ( *(_DWORD *)v5 == 13 )
      {
        if ( *(_DWORD *)(*((_DWORD *)this + 154) + 56) != 0 )
          D3DXShader::CTErrors::Error(
            this: (D3DXShader::CPreProcessor *)((char *)this + 24),
            a2: v5,
            a3: 0x5DEu,
            format: "unexpected end of file");
        v14 = *((D3DXShader::CPPInclude **)this + 154);
        if ( *((_DWORD *)v14 + 27) != 0 )
        {
          *((_DWORD *)this + 154) = *((_DWORD *)v14 + 27);
          *((_DWORD *)v14 + 27) = 0;
          D3DXShader::CPPInclude::`scalar deleting destructor'(this: v14, a2: 1);
          *((_DWORD *)this + 155) = *((_DWORD *)this + 154);
          *(_DWORD *)a2 = 12;
          *((_DWORD *)this + 16) = 1;
        }
        return 0;
      }
      if ( *(_DWORD *)v5 == 9 )
      {
        if ( D3DXShader::CPreProcessor::FindDefine(this, a2: *((const char **)v5 + 2), a3: &v17, a4: &v18) == 0
          || D3DXShader::CPreProcessor::CallDefine((D3DXShader::CTokenize **)this, a2, a3: v17, a4: v18) == 0 )
        {
          v5 = a2;
          goto LABEL_34;
        }
      }
      else
      {
LABEL_34:
        if ( *(_DWORD *)v5 == 9 )
        {
          if ( strcmp(*((const char **)v5 + 2), "__FILE__") == 0 )
          {
            *(_DWORD *)v5 = 10;
            v12 = *(_DWORD *)(*((_DWORD *)this + 155) + 24);
            *((_DWORD *)v5 + 2) = v12;
            if ( v12 == 0 )
              *((_DWORD *)v5 + 2) = &pMem;
          }
          else if ( strcmp(*((const char **)v5 + 2), "__LINE__") == 0 )
          {
            *(_DWORD *)v5 = 2;
            *((_DWORD *)v5 + 2) = *(_DWORD *)(*((_DWORD *)this + 155) + 28);
          }
        }
        v8 = *((_DWORD *)this + 20) == 0;
        *((_DWORD *)this + 16) = *(_DWORD *)v5 == 12;
        if ( !v8 )
        {
          v15 = *((_DWORD *)this + 26);
          if ( v15 != 0 && *(_DWORD *)(v15 + 4) != 0 )
          {
            if ( *(_DWORD *)v5 == 1 && *((_BYTE *)v5 + 9) == 0 )
            {
              if ( *((_BYTE *)v5 + 8) == 123 )
                ++*(_DWORD *)(v15 + 8);
              if ( *((_BYTE *)v5 + 8) == 125 )
              {
                v16 = *((_DWORD *)this + 26);
                if ( *(_DWORD *)(v16 + 8) != 0 )
                  --*(_DWORD *)(v16 + 8);
              }
            }
            if ( *(_DWORD *)(*((_DWORD *)this + 26) + 8) == 0 )
              *(_DWORD *)v5 = 13;
          }
          return 0;
        }
      }
    }
    D3DXShader::CPreProcessor::s_pPP = this;
    v7 = *((_DWORD *)this + 20);
    *((_DWORD *)this + 16) = 0;
    *((_DWORD *)this + 17) = 0;
    *((_DWORD *)this + 19) = 1;
    *((_DWORD *)this + 21) = v7;
    if ( D3DXShader::d3dxtok_parse() != 0 )
      *((_DWORD *)this + 17) = 1;
    v8 = *((_DWORD *)this + 16) == 0;
    *((_DWORD *)this + 23) = 0;
    if ( v8 && *((_DWORD *)this + 17) == 0 )
    {
      result = D3DXShader::CTokenize::GetToken(
                 this: *((D3DXShader::CTokenize **)this + 155),
                 a2: *((_DWORD *)this + 166),
                 a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
      if ( result < 0 )
        return result;
      v9 = *((_DWORD *)this + 158);
      if ( v9 == 12 || v9 == 13 )
      {
        *((_DWORD *)this + 16) = 1;
      }
      else
      {
        if ( *((_DWORD *)this + 20) != 0 )
          D3DXShader::CTErrors::Error(
            this: (D3DXShader::CPreProcessor *)((char *)this + 24),
            a2,
            a3: 0x5DDu,
            format: "unexpected tokens following preprocessor directive");
        *((_DWORD *)this + 17) = 1;
      }
    }
    if ( *((_DWORD *)this + 16) == 0 )
    {
      D3DXShader::CTokenize::SkipToEOL(this: *((D3DXShader::CTokenize **)this + 155));
      v10 = *((D3DXShader::CTokenize **)this + 155);
      *((_DWORD *)this + 25) = 0;
      result = D3DXShader::CTokenize::GetToken(
                 this: v10,
                 a2: *((_DWORD *)this + 166),
                 a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
      if ( result < 0 )
        return result;
      *((_DWORD *)this + 16) = 1;
    }
    *((_DWORD *)this + 155) = *((_DWORD *)this + 154);
    v11 = *((_DWORD *)this + 21);
    *((_DWORD *)this + 20) = v11;
  }
  while ( v11 == 0 );
  qmemcpy(a2, (char *)this + 632, 0x20u);
  if ( *(_DWORD *)(*((_DWORD *)this + 154) + 108) != 0 )
    *(_DWORD *)a2 = 12;
  return *((_DWORD *)this + 18) != 0 ? 0x80004005 : 0;
}
