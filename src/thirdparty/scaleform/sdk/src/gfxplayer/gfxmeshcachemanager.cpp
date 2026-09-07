// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxmeshcachemanager.cpp
// Functions: 15
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxmeshcachemanager.h"

//------------------------------------------------------------------------------
// Address: 0x100E13A0
// Name: public: unsigned int GFxMeshCacheManager::GetMeshThrashing(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMeshCacheManager::GetMeshThrashing(GFxMeshCacheManager *this)
{
  GFxMeshCache *pMeshCache; // eax

  pMeshCache = this->pMeshCache;
  if ( pMeshCache != nullptr )
    return *((_DWORD *)pMeshCache + 33);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E13C0
// Name: public: unsigned int GFxMeshCacheManager::GetNumStrokes(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMeshCacheManager::GetNumStrokes(GFxMeshCacheManager *this)
{
  GFxMeshCache *pMeshCache; // eax

  pMeshCache = this->pMeshCache;
  if ( pMeshCache != nullptr )
    return *((_DWORD *)pMeshCache + 7);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E13D0
// Name: public: virtual void GFxMeshCacheLimit::OnFreeSegment(class GMemoryHeap __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCacheLimit::OnFreeSegment(GFxMeshCacheLimit *this, struct GMemoryHeap *a2, unsigned int a3)
{
  unsigned int Limit; // eax
  unsigned int v4; // eax

  Limit = a2->Info.Desc.Limit;
  if ( Limit > a3 )
  {
    v4 = Limit - a3;
    if ( v4 >= *(_DWORD *)(*((_DWORD *)this + 1) + 12) )
      a2->SetLimit(this: a2, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1400
// Name: public: void GFxMeshCache::AddShapeToKillList(class GFxShapeBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCache::AddShapeToKillList(_RTL_CRITICAL_SECTION *this, struct GFxShapeBase *a2)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  _DWORD *v4; // eax

  v3 = this + 4;
  EnterCriticalSection(lpCriticalSection: this + 4);
  v4 = *((_DWORD **)a2 + 7);
  if ( v4 != nullptr )
  {
    *((_DWORD *)a2 + 7) = 0;
    *((_DWORD *)a2 + 6) = 0;
    v4[2] = 0;
    *v4 = *((_DWORD *)this + 22);
    v4[1] = (char *)this + 88;
    *(_DWORD *)(*((_DWORD *)this + 22) + 4) = v4;
    *((_DWORD *)this + 22) = v4;
  }
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100E1450
// Name: public: void GFxMeshCache::AcquireFrameQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCache::AcquireFrameQueue(GFxMeshCache *this)
{
  char *v3; // ecx
  _DWORD *v4; // eax
  int v5; // edi

  if ( (*((_DWORD *)this + 31))-- == 1 )
  {
    if ( *((GFxMeshCache **)this + 14) != (GFxMeshCache *)((char *)this + 52) )
    {
      v3 = (char *)this + 60;
      do
      {
        v4 = *((_DWORD **)this + 14);
        *(_DWORD *)(*v4 + 4) = v4[1];
        *(_DWORD *)v4[1] = *v4;
        *v4 = *(_DWORD *)v3;
        v4[1] = v3;
        *(_DWORD *)(*(_DWORD *)v3 + 4) = v4;
        *(_DWORD *)v3 = v4;
      }
      while ( *((GFxMeshCache **)this + 14) != (GFxMeshCache *)((char *)this + 52) );
    }
    *((_DWORD *)this + 31) = *((_DWORD *)this + 30);
  }
  v5 = *((_DWORD *)this + 16);
  *((_DWORD *)this + 6) = 0;
  for ( *((_DWORD *)this + 7) = 0; (GFxMeshCache *)v5 != (GFxMeshCache *)((char *)this + 60); v5 = *(_DWORD *)(v5 + 4) )
  {
    ++*((_DWORD *)this + 6);
    *((_DWORD *)this + 7) += GFxMeshSet::GetNumStrokes(this: *(GFxMeshSet **)(v5 + 16));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E14C0
// Name: private: void GFxMeshCache::deleteMeshSet(struct GFxCachedMeshSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCache::deleteMeshSet(_RTL_CRITICAL_SECTION *this, struct GFxCachedMeshSet *a2)
{
  _DWORD *v2; // ebx
  bool v4; // zf
  int v5; // eax
  void (__thiscall ***v6)(_DWORD, int); // ecx

  v2 = *((_DWORD **)a2 + 5);
  *(_DWORD *)(*((_DWORD *)a2 + 2) + 12) = *((_DWORD *)a2 + 3);
  *(_DWORD *)(*((_DWORD *)a2 + 3) + 8) = *((_DWORD *)a2 + 2);
  v4 = v2[3]-- == 1;
  if ( v4 && v2 != *((_DWORD **)this + 34) )
  {
    EnterCriticalSection(lpCriticalSection: this + 4);
    v5 = v2[2];
    if ( v5 != 0 )
    {
      *(_DWORD *)(v5 + 28) = 0;
      *(_DWORD *)(v5 + 24) = 0;
    }
    else
    {
      *(_DWORD *)(*v2 + 4) = v2[1];
      *(_DWORD *)v2[1] = *v2;
    }
    *v2 = *((_DWORD *)this + 20);
    *((_DWORD *)this + 20) = v2;
    LeaveCriticalSection(lpCriticalSection: this + 4);
  }
  --*((_DWORD *)this + 6);
  *((_DWORD *)this + 7) -= GFxMeshSet::GetNumStrokes(this: *((GFxMeshSet **)a2 + 4));
  *(_DWORD *)(*(_DWORD *)a2 + 4) = *((_DWORD *)a2 + 1);
  **((_DWORD **)a2 + 1) = *(_DWORD *)a2;
  v6 = *((void (__thiscall ****)(_DWORD, int))a2 + 4);
  if ( v6 != nullptr )
    (**v6)(a1: v6, a2: 1);
  *(_DWORD *)a2 = *((_DWORD *)this + 11);
  *((_DWORD *)this + 11) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100E1570
// Name: public: bool GFxMeshCache::RemoveMeshSet(class GFxShapeBase __near *,class GFxMeshSet __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMeshCache::RemoveMeshSet(
        _RTL_CRITICAL_SECTION *this,
        struct GFxShapeBase *a2,
        struct GFxMeshSet *a3)
{
  int v3; // edx
  int v5; // eax
  int v6; // edx

  v3 = *((_DWORD *)a2 + 7);
  if ( v3 == 0 )
    return 0;
  v5 = *(_DWORD *)(v3 + 28);
  v6 = v3 + 16;
  if ( v5 == v6 )
    return 0;
  while ( *(struct GFxMeshSet **)(v5 + 16) != a3 )
  {
    v5 = *(_DWORD *)(v5 + 12);
    if ( v5 == v6 )
      return 0;
  }
  GFxMeshCache::deleteMeshSet(this, a2: (struct GFxCachedMeshSet *)v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E15C0
// Name: public: void GFxMeshCache::ClearKillList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCache::ClearKillList(_RTL_CRITICAL_SECTION *this)
{
  _RTL_CRITICAL_SECTION *v2; // esi
  int i; // ebx
  _RTL_CRITICAL_SECTION *v4; // [esp+8h] [ebp-4h]

  v2 = this + 4;
  v4 = this + 4;
  EnterCriticalSection(lpCriticalSection: this + 4);
  if ( *((_RTL_CRITICAL_SECTION **)this + 23) != (_RTL_CRITICAL_SECTION *)((char *)this + 88) )
  {
    do
    {
      for ( i = *((_DWORD *)this + 23);
            *(_DWORD *)(i + 28) != i + 16;
            GFxMeshCache::deleteMeshSet(this, a2: *(struct GFxCachedMeshSet **)(i + 28)) )
      {
        ;
      }
    }
    while ( *((_RTL_CRITICAL_SECTION **)this + 23) != (_RTL_CRITICAL_SECTION *)((char *)this + 88) );
    v2 = v4;
  }
  LeaveCriticalSection(lpCriticalSection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100E1620
// Name: public: virtual bool GFxMeshCacheLimit::OnExceedLimit(class GMemoryHeap __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMeshCacheLimit::OnExceedLimit(GFxMeshCacheLimit *this, struct GMemoryHeap *a2, unsigned int a3)
{
  unsigned int v4; // ebx
  int v5; // esi
  unsigned int v6; // eax
  struct GMemoryHeap *v9; // [esp+10h] [ebp+8h]

  v9 = (struct GMemoryHeap *)a2->GetUsedSpace(this: a2);
  do
  {
    v4 = a2->GetUsedSpace(this: a2);
    v5 = *((_DWORD *)this + 1);
    if ( *(_DWORD *)(v5 + 64) != v5 + 60 && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v5 + 64) + 16) + 25) == 0 )
    {
      GFxMeshCache::deleteMeshSet(this: (_RTL_CRITICAL_SECTION *)v5, a2: *(struct GFxCachedMeshSet **)(v5 + 64));
      ++*(_DWORD *)(v5 + 132);
    }
    v6 = a2->GetUsedSpace(this: a2);
  }
  while ( v6 < v4 && v6 + a3 > (unsigned int)v9 );
  if ( a3 + v6 > (unsigned int)v9 )
    a2->SetLimit(this: a2, a2: a3 + a2->Info.Desc.Limit);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1850
// Name: public: void GFxMeshCacheManager::EndDisplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCacheManager::EndDisplay(int this)
{
  GFxRenderGen *v2; // esi
  unsigned int v3; // edi

  GFxMeshCache::ClearKillList(this: *(_RTL_CRITICAL_SECTION **)(this + 20));
  GFxMeshCache::AcquireFrameQueue(this: *(GFxMeshCache **)(this + 20));
  v2 = *(GFxRenderGen **)(this + 16);
  if ( v2 != nullptr )
  {
    v3 = *((_DWORD *)v2 + 236);
    if ( v3 != 0 && GFxRenderGen::GetNumBytes(this: v2) > v3 )
      GFxRenderGen::ClearAndRelease(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1890
// Name: public: class GFxMeshSet __near * GFxMeshCache::GetMeshSet(class GFxShapeBase __near *,void const __near *,enum GFxMeshSet::KeyCategoryType,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMeshCache::GetMeshSet(int this, struct GFxShapeBase *a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v8; // esi
  int v9; // edx
  int v10; // [esp+4h] [ebp-4h]

  result = *((_DWORD *)a2 + 7);
  if ( result != 0 )
  {
    v8 = *(_DWORD *)(result + 28);
    v10 = result + 16;
    if ( v8 != result + 16 )
    {
      while ( 1 )
      {
        if ( (unsigned __int8)GFxMeshSet::MeshKeyFits(a1: *(_DWORD *)(v8 + 16), a2: a4, a3: a5, a4: a6) != 0 )
        {
          *(_DWORD *)(*(_DWORD *)v8 + 4) = *(_DWORD *)(v8 + 4);
          **(_DWORD **)(v8 + 4) = *(_DWORD *)v8;
          v9 = *(_DWORD *)(this + 60);
          *(_DWORD *)(v8 + 4) = this + 60;
          *(_DWORD *)v8 = v9;
          *(_DWORD *)(*(_DWORD *)(this + 60) + 4) = v8;
          *(_DWORD *)(this + 60) = v8;
          return *(_DWORD *)(v8 + 16);
        }
        if ( a4 != 0
          && (*(_BYTE *)(this + 128) == 0 && a4 == 2 || *(_BYTE *)(this + 129) == 0 && a4 == 1)
          && a3 == *(_DWORD *)(*(_DWORD *)(v8 + 16) + 100) )
        {
          break;
        }
        v8 = *(_DWORD *)(v8 + 12);
        if ( v8 == v10 )
          return 0;
      }
      GFxMeshCache::RemoveMeshSet((_RTL_CRITICAL_SECTION *)this, a2, a3: *(struct GFxMeshSet **)(v8 + 16));
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E1A00
// Name: public: GFxMeshCache::GFxMeshCache(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GFxMeshCache *__thiscall GFxMeshCache::GFxMeshCache(GFxMeshCache *this, struct GMemoryHeap *a2)
{
  char *v3; // edi
  int v4; // ecx

  *((_DWORD *)this + 2) = a2;
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxMeshCache::`vftable';
  *((_DWORD *)this + 3) = 0x800000;
  *((_DWORD *)this + 4) = &GFxMeshCacheLimit::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = (char *)this + 32;
  v3 = (char *)this + 16;
  *((_DWORD *)this + 10) = 127;
  *((_DWORD *)this + 13) = (char *)this + 52;
  *((_DWORD *)this + 14) = (char *)this + 52;
  *((_DWORD *)this + 15) = (char *)this + 60;
  *((_DWORD *)this + 16) = (char *)this + 60;
  *((_DWORD *)this + 19) = 127;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = (char *)this + 68;
  *((_DWORD *)this + 22) = (char *)this + 88;
  *((_DWORD *)this + 23) = (char *)this + 88;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 4, spinCount: 0);
  v4 = *((_DWORD *)this + 2);
  *((_DWORD *)this + 30) = 1;
  *((_DWORD *)this + 31) = 1;
  *((_WORD *)this + 64) = 1;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 5) = this;
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v4 + 20))(a1: v4, a2: v3);
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 2) + 24))(
    a1: *((_DWORD *)this + 2),
    a2: *((_DWORD *)this + 3));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E1AD0
// Name: public: virtual GFxMeshCache::~GFxMeshCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCache::~GFxMeshCache(GFxMeshCache *this)
{
  int v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // edi

  v2 = *((_DWORD *)this + 2);
  *(_DWORD *)this = &GFxMeshCache::`vftable';
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 24))(a1: v2, a2: 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 2) + 20))(a1: *((_DWORD *)this + 2), a2: 0);
  GFxMeshCache::ClearKillList((_RTL_CRITICAL_SECTION *)this);
  while ( *((GFxMeshCache **)this + 16) != (GFxMeshCache *)((char *)this + 60) )
    GFxMeshCache::deleteMeshSet((_RTL_CRITICAL_SECTION *)this, a2: *((struct GFxCachedMeshSet **)this + 16));
  GListAllocBase<GFxCachedMeshSet,127,GAllocatorLH_POD<GFxCachedMeshSet,138>>::ClearAndRelease(this: (_DWORD *)this + 8);
  GListAllocBase<GFxCachedMeshSetBag,127,GAllocatorLH<GFxCachedMeshSetBag,138>>::ClearAndRelease(this: (_DWORD *)this + 17);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)this + 4);
  v3 = *((_DWORD **)this + 17);
  if ( v3 != nullptr )
  {
    do
    {
      v4 = (_DWORD *)v3[1270];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
      v3 = v4;
    }
    while ( v4 != nullptr );
  }
  v5 = *((_DWORD **)this + 8);
  if ( v5 != nullptr )
  {
    do
    {
      v6 = (_DWORD *)v5[762];
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      v5 = v6;
    }
    while ( v6 != nullptr );
  }
  *((_DWORD *)this + 4) = &GMemoryHeap::LimitHandler::`vftable';
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100E1B90
// Name: public: void GFxMeshCache::AddMeshSet(class GFxShapeBase __near *,class GFxMeshSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshCache::AddMeshSet(GFxMeshCache *this, struct GFxShapeBase *a2, struct GFxMeshSet *a3)
{
  unsigned int *v3; // edi
  unsigned int *v5; // eax
  unsigned int v6; // edx

  v3 = *((unsigned int **)a2 + 7);
  if ( v3 == nullptr )
  {
    v3 = GListAllocBase<GFxCachedMeshSetBag,127,GAllocatorLH<GFxCachedMeshSetBag,138>>::Alloc(this: (unsigned int *)this + 17);
    v3[2] = (unsigned int)a2;
    *((_DWORD *)a2 + 7) = v3;
    *((_DWORD *)a2 + 6) = this;
  }
  *((_DWORD *)this + 34) = v3;
  v5 = GListAllocBase<GFxCachedMeshSet,127,GAllocatorLH_POD<GFxCachedMeshSet,138>>::Alloc(this: (unsigned int *)this + 8);
  v5[4] = (unsigned int)a3;
  v5[5] = (unsigned int)v3;
  *v5 = *((_DWORD *)this + 13);
  v5[1] = (unsigned int)this + 52;
  *(_DWORD *)(*((_DWORD *)this + 13) + 4) = v5;
  *((_DWORD *)this + 13) = v5;
  v6 = v3[6];
  v5[3] = (unsigned int)(v3 + 4);
  v5[2] = v6;
  *(_DWORD *)(v3[6] + 12) = v5;
  v3[6] = (unsigned int)v5;
  ++v3[3];
  ++*((_DWORD *)this + 6);
  *((_DWORD *)this + 7) += GFxMeshSet::GetNumStrokes(this: (GFxMeshSet *)v5[4]);
  *((_DWORD *)this + 34) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E1C20
// Name: public: GFxMeshCacheManager::GFxMeshCacheManager(bool)
// Source: json
//------------------------------------------------------------------------------
GFxMeshCacheManager *__thiscall GFxMeshCacheManager::GFxMeshCacheManager(GFxMeshCacheManager *this, bool debugHeap)
{
  GMemoryHeap *v3; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GFxRenderGen *v5; // eax
  GFxRenderGen *v6; // eax
  GMemoryHeap *pHeap; // ecx
  void *(__thiscall *v8)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GFxMeshCache *v9; // eax
  _DWORD v11[8]; // [esp+8h] [ebp-28h] BYREF
  int v12; // [esp+28h] [ebp-8h] BYREF
  int v13; // [esp+2Ch] [ebp-4h] BYREF

  this->__vftable = (GFxMeshCacheManager_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_MeshCacheManager;
  this->__vftable = (GFxMeshCacheManager_vtbl *)&GFxMeshCacheManager::`vftable';
  this->pHeap = nullptr;
  this->pRenderGen = nullptr;
  this->pMeshCache = nullptr;
  this->pRenEventHandler = nullptr;
  v11[0] = debugHeap ? 0x1000 : 0;
  v11[1] = 32;
  v11[2] = 0x10000;
  v11[3] = 0;
  v11[4] = -1;
  v11[5] = 0;
  v11[7] = 0;
  v11[6] = 5;
  v3 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2: "_Mesh_Cache", a3: v11);
  this->pHeap = v3;
  Alloc_2 = v3->Alloc_2;
  v13 = 2;
  v5 = (GFxRenderGen *)Alloc_2(this: v3, a2: 948u, a3: (const GAllocDebugInfo *)&v13);
  if ( v5 != nullptr )
    v6 = GFxRenderGen::GFxRenderGen(this: v5, a2: this->pHeap);
  else
    v6 = nullptr;
  pHeap = this->pHeap;
  this->pRenderGen = v6;
  v8 = pHeap->Alloc_2;
  v12 = 129;
  v9 = (GFxMeshCache *)v8(this: pHeap, a2: 140u, a3: (const GAllocDebugInfo *)&v12);
  if ( v9 != nullptr )
    this->pMeshCache = GFxMeshCache::GFxMeshCache(this: v9, a2: this->pHeap);
  else
    this->pMeshCache = nullptr;
  return this;
}
