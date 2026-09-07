// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontmap.cpp
// Functions: 12
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontmap.h"

//------------------------------------------------------------------------------
// Address: 0x1006D020
// Name: public: bool GString::operator==(class GString const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GString::operator==(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this,
        _DWORD *str)
{
  return strcmp(
           (const char *)(((int)this->m_Memory.m_pMemory & 0xFFFFFFFC) + 8),
           (const char *)((*str & 0xFFFFFFFC) + 8)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006D1F0
// Name: public: class GFxFontMap::MapEntry __near * GStringHashLH<class GFxFontMap::MapEntry,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxFontMap::MapEntry,struct GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<struct GString::NoCaseKey>(struct GString::NoCaseKey const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStringHashLH<GFxFontMap::MapEntry,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
        _DWORD *this,
        _DWORD **a2)
{
  unsigned int v3; // eax
  int v4; // eax
  int v5; // eax

  if ( *this != 0
    && (v3 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((**a2 & 0xFFFFFFFC) + 8)),
        (v4 = GHashSetBase<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxFontMap::MapEntry,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                this,
                a2,
                a3: v3 & *(_DWORD *)(*this + 4))) >= 0)
    && (v5 = 32 * v4 + *this + 16) != 0 )
  {
    return v5 + 4;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D310
// Name: public: bool GFxFontMap::GetFontMapping(class GFxFontMap::MapEntry __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxFontMap::GetFontMapping@<al>(
        GFxFontMap *this@<ecx>,
        int a2@<edi>,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *pentry,
        GString a4)
{
  struct GFxFontMapImpl *pImpl; // ecx
  int v7; // eax
  void *v8; // esi
  int v9; // edi
  GString *v11; // [esp+4h] [ebp-4h] BYREF

  if ( this->pImpl == nullptr )
    return 0;
  GString::GString(this: &a4, a2: (const char *)a4.pData);
  pImpl = this->pImpl;
  v11 = &a4;
  v7 = GStringHashLH<GFxFontMap::MapEntry,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
         this: pImpl,
         a2: (_DWORD **)&v11);
  v8 = (void *)(a4.HeapTypeBits & 0xFFFFFFFC);
  v9 = v7;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a4.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
  if ( v9 == 0 )
    return 0;
  GString::operator=(this: pentry, src: v9, a3: a2);
  pentry->m_Memory.m_nAllocationCount = *(int *)(v9 + 4);
  pentry->m_pElements = *(void (__cdecl ***)(int))(v9 + 16);
  pentry->m_Memory.m_nGrowSize = *(int *)(v9 + 8);
  pentry->m_Size = *(int *)(v9 + 12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006D940
// Name: public: GFxFontMap::GFxFontMap(void)
// Source: json
//------------------------------------------------------------------------------
GFxFontMap *__thiscall GFxFontMap::GFxFontMap(GFxFontMap *this)
{
  struct GFxFontMapImpl *v2; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (GFxFontMap_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_FontMap;
  this->__vftable = (GFxFontMap_vtbl *)&GFxFontMap::`vftable';
  v4 = 2;
  v2 = (struct GFxFontMapImpl *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4, a3: &v4);
  if ( v2 != nullptr )
  {
    *(_DWORD *)v2 = 0;
    this->pImpl = v2;
  }
  else
  {
    this->pImpl = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006D9A0
// Name: public: bool GFxFontMap::MapFont(char const __near *,char const __near *,enum GFxFontMap::MapFontFlags,float,float,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxFontMap::MapFont@<al>(float16 *this@<ecx>, GString a2, CImagePacker a3)
{
  _DWORD *v4; // ecx
  void *v5; // esi
  void *v7; // esi
  int *v8; // ecx
  void *v9; // esi
  void *v10; // esi
  float v11[5]; // [esp+4h] [ebp-1Ch] BYREF
  GString *v12; // [esp+18h] [ebp-8h] BYREF
  GString *v13; // [esp+1Ch] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 3) == 0 || a2.pData == nullptr )
    return 0;
  GString::GString(this: &a2, a2: (const char *)a2.pData);
  v4 = *((_DWORD **)this + 3);
  v13 = &a2;
  if ( GStringHashLH<GFxFontMap::MapEntry,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
         this: v4,
         a2: (_DWORD **)&v13) != 0 )
  {
    v5 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    return 0;
  }
  else
  {
    GString::GString(this: (GString *)&a3, a2: (const char *)a3.m_MaxLightmapWidth);
    GString::GString(result: &a3);
    v11[1] = *(float *)a3.m_pLightmapWavefront;
    v11[2] = *(float *)&a3.m_pLightmapWavefront[1];
    v7 = (void *)(a3.m_MaxLightmapWidth & 0xFFFFFFFC);
    v11[3] = *(float *)&a3.m_pLightmapWavefront[2];
    v11[4] = *(float *)&a3.m_MaxLightmapHeight;
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.m_MaxLightmapWidth & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
    v8 = *((int **)this + 3);
    v12 = &a2;
    v13 = (GString *)v11;
    GHashSetBase<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxFontMap::MapEntry,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeHashF>>::Set<GStringLH_HashNode<GFxFontMap::MapEntry,GString::NoCaseHashFunctor>::NodeRef>(
      this: v8,
      a2: v8,
      a3: (int)&v12);
    v9 = (void *)(LODWORD(v11[0]) & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((LODWORD(v11[0]) & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
    v10 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074F00
// Name: public: bool GString::operator==(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GString::operator==(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *this,
        const char *a2)
{
  return strcmp((const char *)(((int)this->m_Memory.m_pMemory & 0xFFFFFFFC) + 8), a2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B41C0
// Name: public: bool GStringHashLH<unsigned int,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<class GString>(class GString const __near &,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringHashLH<unsigned int,2,GString::NoCaseHashFunctor,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString>(
        IVEngineClient *this,
        const struct AudioState_t *key,
        unsigned int *pvalue)
{
  unsigned int v4; // eax
  IVEngineClient_vtbl *v5; // esi
  int Index; // eax
  bool (__thiscall **v7)(IVEngineClient *, const char *, const char *); // eax

  if ( this->__vftable != nullptr )
  {
    v4 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)key & 0xFFFFFFFC) + 8));
    v5 = this->__vftable;
    Index = GHashSetBase<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString>(
              (int *)this,
              a2: key,
              a3: v4 & (unsigned int)this->GetLightForPoint);
    if ( Index >= 0 )
    {
      v7 = &v5->CopyFileA + 4 * Index;
      if ( v7 != nullptr && pvalue != nullptr )
        *pvalue = (unsigned int)v7[1];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6060
// Name: public: bool GStringHashLH<class GFxResourceHandle,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<struct GString::NoCaseKey>(struct GString::NoCaseKey const __near &,class GFxResourceHandle __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GStringHashLH<GFxResourceHandle,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
        _DWORD *this,
        _DWORD **a2,
        _DWORD *a3)
{
  unsigned int v4; // eax
  int v5; // eax
  int v6; // esi
  IShaderDevice *v7; // ecx
  IShaderDevice *v8; // ecx

  if ( *this == 0 )
    return 0;
  v4 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((**a2 & 0xFFFFFFFC) + 8));
  v5 = GHashSetBase<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxResourceHandle,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
         this,
         a2,
         a3: v4 & *(_DWORD *)(*this + 4));
  if ( v5 < 0 )
    return 0;
  v6 = *this + 20 * v5 + 16;
  if ( v6 == 0 )
    return 0;
  if ( a3 != nullptr )
  {
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      v7 = *(IShaderDevice **)(v6 + 8);
      if ( v7 != nullptr )
        GRefCountImpl::AddRef(this: v7);
    }
    if ( *a3 == 0 )
    {
      v8 = (IShaderDevice *)a3[1];
      if ( v8 != nullptr )
        GFxResource::Release(this: v8);
    }
    *a3 = *(_DWORD *)(v6 + 4);
    a3[1] = *(_DWORD *)(v6 + 8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D6160
// Name: public: bool GStringHashLH<unsigned int,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<struct GString::NoCaseKey>(struct GString::NoCaseKey const __near &,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GStringHashLH<unsigned int,2,GString::NoCaseHashFunctor,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
        _DWORD *this,
        _DWORD **a2,
        _DWORD *a3)
{
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( *this == 0 )
    return 0;
  v4 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((**a2 & 0xFFFFFFFC) + 8));
  v5 = GHashSetBase<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned int,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
         this,
         a2,
         a3: v4 & *(_DWORD *)(*this + 4));
  if ( v5 < 0 )
    return 0;
  v6 = *this + 16 * (v5 + 1);
  if ( v6 == 0 )
    return 0;
  if ( a3 != nullptr )
    *a3 = *(_DWORD *)(v6 + 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAB90
// Name: public: void GStringHashLH<class GFxResourceHandle,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GFxResourceHandle,struct GString::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(class GString const __near &,class GFxResourceHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringHashLH<GFxResourceHandle,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
        GFxKeyboardState::IListener *this,
        GPtr<GFxParseControl> *result,
        const GenericThreadLocals::CThreadLocal<int> *value)
{
  GPtr<GFxParseControl> *v3; // edi
  const GenericThreadLocals::CThreadLocal<int> *v5; // edi
  unsigned int *v6; // esi
  IShaderDevice *m_index; // ecx
  IShaderDevice *v8; // ecx
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v9; // eax
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v10; // [esp-Ch] [ebp-1Ch]
  int v11; // [esp+8h] [ebp-8h] BYREF
  const GenericThreadLocals::CThreadLocal<int> *v12; // [esp+Ch] [ebp-4h]

  v3 = result;
  GHashSetBase<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxResourceHandle,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::FindAlt<GString::NoCaseKey>(
    this,
    a2: &v11,
    a3: (_DWORD **)&result);
  if ( v11 != 0 && *(_DWORD *)v11 != 0 && (int)v12 <= *(_DWORD *)(*(_DWORD *)v11 + 4) )
  {
    v5 = value;
    v6 = (unsigned int *)(*(_DWORD *)v11 + 4 * (5 * (_DWORD)v12 + 5));
    if ( value->m_index == 0 )
    {
      m_index = (IShaderDevice *)value[1].m_index;
      if ( m_index != nullptr )
        GRefCountImpl::AddRef(this: m_index);
    }
    if ( *v6 == 0 )
    {
      v8 = (IShaderDevice *)v6[1];
      if ( v8 != nullptr )
        GFxResource::Release(this: v8);
    }
    *v6 = v5->m_index;
    v6[1] = v5[1].m_index;
  }
  else
  {
    v10 = (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)v3->pObject & 0xFFFFFFFC)
                                                                                         + 8);
    v11 = (int)v3;
    v12 = value;
    v9 = GString::BernsteinHashFunctionCIS(result: v10);
    GHashSetBase<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxResourceHandle,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::add<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeRef>(
      this,
      a2: this,
      a3: (int)&v11,
      a4: (int)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAC50
// Name: public: void GStringHashLH<unsigned int,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(class GString const __near &,unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GStringHashLH<unsigned int,2,GString::NoCaseHashFunctor,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
        IVEngineClient *this,
        Frustum_t **key,
        _DWORD *value)
{
  Frustum_t **v3; // edi
  int *result; // eax
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v6; // eax
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v7; // [esp-Ch] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  v3 = key;
  GHashSetBase<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned int,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::FindAlt<GString::NoCaseKey>(
    this,
    a2: &v8,
    a3: &key);
  if ( v8 != 0 && *(_DWORD *)v8 != 0 && v9 <= *(_DWORD *)(*(_DWORD *)v8 + 4) )
  {
    result = (int *)(2 * v9);
    *(_DWORD *)(*(_DWORD *)v8 + 16 * v9 + 20) = *value;
  }
  else
  {
    v9 = (int)value;
    v7 = (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((unsigned int)*v3 & 0xFFFFFFFC)
                                                                                        + 8);
    v8 = (int)v3;
    v6 = GString::BernsteinHashFunctionCIS(result: v7);
    return GHashSetBase<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF>>::add<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeRef>(
             (CUtlHash<int,CKeyValuesGrowableStringTable::CLookupFunctor &,CKeyValuesGrowableStringTable::CLookupFunctor &> *)this,
             a2: (int)this,
             a3: (int)&v8,
             a4: (int)v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10111C70
// Name: public: struct GASMovieClipLoader::ProgressDesc __near * GStringHashLH<struct GASMovieClipLoader::ProgressDesc,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<struct GASMovieClipLoader::ProgressDesc,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<struct GASMovieClipLoader::ProgressDesc,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<struct GASMovieClipLoader::ProgressDesc,struct GString::NoCaseHashFunctor>::NodeHashF>>::Get(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall GStringHashLH<GASMovieClipLoader::ProgressDesc,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Get(
        IClientRenderable *this,
        _DWORD *a2)
{
  unsigned int v3; // eax
  IClientRenderable_vtbl *v4; // esi
  int Index; // eax
  int v6; // eax

  if ( this->__vftable != nullptr
    && (v3 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*a2 & 0xFFFFFFFC) + 8)),
        v4 = this->__vftable,
        (Index = GHashSetBase<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GASMovieClipLoader::ProgressDesc,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString>(
                   (int *)this,
                   a2,
                   a3: v3 & (unsigned int)this->GetRenderOrigin)) >= 0)
    && (v6 = (int)(&v4->GetRenderFlags + 5 * Index)) != 0 )
  {
    return (const QAngle *)(v6 + 4);
  }
  else
  {
    return nullptr;
  }
}
