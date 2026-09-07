// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gastransformobject.cpp
// Functions: 15
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gastransformobject.h"

//------------------------------------------------------------------------------
// Address: 0x10123730
// Name: protected: void GASTransformObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(ISteamUserStats *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
  v2 = *((_DWORD *)this + 15);
  if ( v2 != 0 )
  {
    v3 = ++*(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v2 + 8) = v3 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 2);
    }
  }
  v4 = *((_DWORD *)this + 16);
  if ( v4 != 0 )
  {
    v5 = ++*(_DWORD *)(v4 + 8);
    if ( (v5 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v4 + 8) = v5 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v4)(a1: v4, a2: 2);
    }
  }
  v6 = *((_DWORD *)this + 17);
  if ( v6 != 0 )
  {
    v7 = ++*(_DWORD *)(v6 + 8);
    if ( (v7 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v6 + 8) = v7 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v6)(a1: v6, a2: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101237B0
// Name: public: void GASTransformObject::SetTarget(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTransformObject::SetTarget(
        GFxCharacterHandle **this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *result)
{
  const GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> >::Iterator *v4; // eax
  GFxCharacterHandle *v5; // esi
  GFxCharacterHandle *v6; // esi
  const GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> >::Iterator *v7; // [esp+14h] [ebp+8h]

  if ( result != nullptr )
  {
    v4 = (const GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> >::Iterator *)DWORD1(result[6].m_pfnProxied);
    if ( v4 == nullptr )
      GFxASCharacter::CreateCharacterHandle(this: result);
    v7 = v4;
    if ( v4 != nullptr )
      ++v4->pHash;
    v5 = *(this + 14);
    if ( v5 != nullptr )
    {
      *v5 = (GFxCharacterHandle)((char *)*v5 - 1);
      if ( (int)*v5 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v5);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
        v4 = v7;
      }
    }
    *(this + 14) = (GFxCharacterHandle *)v4;
    *(this + 13) = (GFxCharacterHandle *)(*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(result->m_pfnProxied) + 84))(a1: result);
  }
  else
  {
    *(this + 13) = nullptr;
    v6 = *(this + 14);
    if ( v6 != nullptr )
    {
      *v6 = (GFxCharacterHandle)((char *)*v6 - 1);
      if ( (int)*v6 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v6);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      }
    }
    *(this + 14) = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123850
// Name: protected: void GASTransformObject::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(ISteamUserStats *this)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
  v2 = *((_DWORD *)this + 15);
  if ( v2 != 0 && (--*(_DWORD *)(v2 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 1);
  }
  v3 = *((_DWORD *)this + 16);
  if ( v3 != 0 && (--*(_DWORD *)(v3 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(v3 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v3)(a1: v3, a2: 1);
  }
  v4 = *((_DWORD *)this + 17);
  if ( v4 != 0 && (--*(_DWORD *)(v4 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v4 + 8) = *(_DWORD *)(v4 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v4)(a1: v4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101238F0
// Name: protected: void GASTransformObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(ISteamUserStats *this)
{
  int v2; // ecx
  int v3; // eax
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // eax
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // [esp-4h] [ebp-8h]
  int v11; // [esp-4h] [ebp-8h]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
  v2 = *((_DWORD *)this + 15);
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) == 0x10000000 )
    {
      if ( (v3 & 0xFFFFFFF) != 0 )
      {
        v4 = v3 & 0x8FFFFFFF;
        v10 = 2;
      }
      else
      {
        v4 = v3 & 0x8FFFFFFF | 0x20000000;
        v10 = 4;
      }
      *(_DWORD *)(v2 + 8) = v4;
      (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: v10);
    }
  }
  v5 = *((_DWORD *)this + 16);
  if ( v5 != 0 )
  {
    v6 = *(_DWORD *)(v5 + 8);
    if ( (v6 & 0x70000000) == 0x10000000 )
    {
      if ( (v6 & 0xFFFFFFF) != 0 )
      {
        v7 = v6 & 0x8FFFFFFF;
        v11 = 2;
      }
      else
      {
        v7 = v6 & 0x8FFFFFFF | 0x20000000;
        v11 = 4;
      }
      *(_DWORD *)(v5 + 8) = v7;
      (**(void (__thiscall ***)(int, int))v5)(a1: v5, a2: v11);
    }
  }
  v8 = *((_DWORD *)this + 17);
  if ( v8 != 0 )
  {
    v9 = *(_DWORD *)(v8 + 8);
    if ( (v9 & 0x70000000) == 0x10000000 )
    {
      if ( (v9 & 0xFFFFFFF) != 0 )
      {
        *(_DWORD *)(v8 + 8) = v9 & 0x8FFFFFFF;
        (**(void (__thiscall ***)(int, int))v8)(a1: v8, a2: 2);
      }
      else
      {
        *(_DWORD *)(v8 + 8) = v9 & 0x8FFFFFFF | 0x20000000;
        (**(void (__thiscall ***)(int, int))v8)(a1: v8, a2: 4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101239C0
// Name: protected: virtual void GASTransformObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTransformObject::Finalize_GC(
        GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *this)
{
  GFxCharacterHandle *v2; // esi

  *((_DWORD *)this + 13) = 0;
  v2 = *((GFxCharacterHandle **)this + 14);
  if ( v2 != nullptr )
  {
    *v2 = (GFxCharacterHandle)((char *)*v2 - 1);
    if ( (int)*v2 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    }
  }
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10123A00
// Name: protected: void GASTransformObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __usercall GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>@<al>(
        ISteamUserStats *a1@<ecx>,
        int a2@<edi>)
{
  char result; // al
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx

  result = GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this: a1);
  v4 = (int)a1[15].__vftable;
  if ( v4 != 0 )
    result = GRefCountBaseGC<323>::Release(a1: v4, a2);
  v5 = (int)a1[16].__vftable;
  if ( v5 != 0 )
    result = GRefCountBaseGC<323>::Release(a1: v5, a2);
  v6 = (int)a1[17].__vftable;
  if ( v6 != 0 )
    return GRefCountBaseGC<323>::Release(a1: v6, a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10123A30
// Name: protected: void GASTransformObject::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(ISteamUserStats *this)
{
  char result; // al
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx
  _DWORD *v5; // ecx

  result = GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
  v3 = *((_DWORD **)this + 15);
  if ( v3 != nullptr )
    result = GRefCountBaseGC<323>::CollectGarbage(this: v3);
  v4 = *((_DWORD **)this + 16);
  if ( v4 != nullptr )
    result = GRefCountBaseGC<323>::CollectGarbage(this: v4);
  v5 = *((_DWORD **)this + 17);
  if ( v5 != nullptr )
    return GRefCountBaseGC<323>::CollectGarbage(this: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10123A80
// Name: public: GASTransformObject::GASTransformObject(class GASEnvironment __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
GASTransformObject *__thiscall GASTransformObject::GASTransformObject(
        GASTransformObject *this,
        struct GASEnvironment *a2,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *result)
{
  int *v5; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  struct GASObject *v7; // eax
  int v8; // ecx
  struct GASObject *v9; // eax
  int v10; // ecx
  struct GASObject *v11; // eax
  int v12; // ecx
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *v13; // edi
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *v15; // [esp+14h] [ebp+8h]
  GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *v16; // [esp+14h] [ebp+8h]

  GASObject::GASObject((GASObject *)this, a2);
  *(this + 13) = nullptr;
  *this = (GASTransformObject)&GASTransformObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(this + 4) = (GASTransformObject)&GASTransformObject::`vftable'{for `GASObjectInterface'};
  *(this + 14) = nullptr;
  *(this + 15) = nullptr;
  *(this + 16) = nullptr;
  *(this + 17) = nullptr;
  GASTransformObject::SetTarget((GFxCharacterHandle **)this, result);
  v5 = (int *)((char *)a2 + 120);
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *((vc_attributes::PreRangeAttribute **)a2 + 30),
                                                    result: (vc_attributes::InvalidCheckAttribute *)0xC);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 4),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)a2 + 15,
    psc_4: Prototype);
  v7 = GASEnvironment::OperatorNew(
         this: (__vc_attributes::idl_quoteAttribute *)a2,
         a2: (int)v5,
         a3: *(struct GASObject **)(*v5 + 660),
         a4: (const struct GASString *)(*v5 + 60),
         nargs: 0,
         argsTopOff: -1);
  v8 = (int)*(this + 15);
  v15 = (GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *)v7;
  if ( v8 != 0 )
    GRefCountBaseGC<323>::Release(a1: v8, a2: (int)v5);
  *(this + 15) = v15;
  v9 = GASEnvironment::OperatorNew(
         this: (__vc_attributes::idl_quoteAttribute *)a2,
         a2: (int)v5,
         a3: *(struct GASObject **)(*v5 + 660),
         a4: (const struct GASString *)(*v5 + 72),
         nargs: 0,
         argsTopOff: -1);
  v10 = (int)*(this + 16);
  v16 = (GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *)v9;
  if ( v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2: (int)v5);
  *(this + 16) = v16;
  v11 = GASEnvironment::OperatorNew(
          this: (__vc_attributes::idl_quoteAttribute *)a2,
          a2: *v5,
          a3: *(struct GASObject **)(*v5 + 660),
          a4: (const struct GASString *)(*v5 + 68),
          nargs: 0,
          argsTopOff: -1);
  v12 = (int)*(this + 17);
  v13 = (GHashSetBase<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *)v11;
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: (int)v11);
  *(this + 17) = v13;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10123B60
// Name: protected: virtual void GASTransformObject::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASTransformObject::ExecuteForEachChild_GC(ISteamUserStats *a1@<ecx>, int a2@<edi>, int operation)
{
  switch ( operation )
  {
    case 0:
      GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1, a2);
      break;
    case 1:
      GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: a1);
      break;
    case 2:
      GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: a1);
      break;
    case 3:
      GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: a1);
      break;
    case 4:
      GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: a1);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123BC0
// Name: public: virtual bool GASTransformObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASTransformObject::GetMember(
        GASTransformObject *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *name,
        struct GASValue *a4)
{
  const char *v4; // edx
  GFxMovieRoot *v6; // eax
  GRefCountNTSImpl *v7; // eax
  GRefCountNTSImpl *v8; // esi
  int v9; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st5
  int v13; // eax
  GFxMovieRoot *v15; // eax
  int v16; // eax
  GFxMovieRoot *v17; // eax
  int v18; // eax
  GRefCountNTSImpl *v19; // esi
  GRefCountNTSImpl *v20; // eax
  GRefCountNTSImpl *v21; // ebx
  GRefCountNTSImpl *i; // esi
  unsigned int v23; // esi
  int v24; // ecx
  int (__thiscall *v25)(int, int, _BYTE *); // edx
  GArrayBase<GArrayData<GFxMovieRoot *,GAllocatorLH<GFxMovieRoot *,2>,GArrayDefaultPolicy> > *v26; // eax
  struct GASObject *v27; // ebx
  tagWNDCLASSW *v28; // eax
  GRefCountNTSImpl *v29; // eax
  GRefCountNTSImpl *v30; // ebx
  GRefCountNTSImpl *j; // esi
  unsigned int v32; // esi
  int v33; // ecx
  int (__thiscall *v34)(int, int, _BYTE *); // edx
  void *v35; // ebx
  struct GASObject *v36; // esi
  tagWNDCLASSW *v37; // eax
  char *v38; // [esp+0h] [ebp-C8h]
  const char *v39; // [esp+4h] [ebp-C4h]
  int v40; // [esp+8h] [ebp-C0h]
  GASValue v41[4]; // [esp+Ch] [ebp-BCh] BYREF
  GASValue v42[4]; // [esp+1Ch] [ebp-ACh] BYREF
  _BYTE r[128]; // [esp+2Ch] [ebp-9Ch] BYREF
  float v44[6]; // [esp+ACh] [ebp-1Ch] BYREF

  v4 = *(const char **)name->N.Name.Short;
  *(_DWORD *)&r[56] = a2;
  *(_DWORD *)&r[60] = a4;
  if ( strcmp(v4, (const char *)&stru_102A69F0) == 0 )
  {
    v6 = (GFxMovieRoot *)*(this + 9);
    r[71] = 1;
    if ( v6 != nullptr )
    {
      GFxCharacterHandle::ResolveCharacter(
        this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
        a2: v6);
      v8 = v7;
      if ( v7 != nullptr )
      {
        ++v7->RefCount;
        ((void (__thiscall *)(GRefCountNTSImpl *, _BYTE *, volatile int *))v7->__vftable[13].dtr_GRefCountImplCore)(
          a1: v7,
          a2: &r[32],
          a3: &v7[8].RefCount);
        *(float *)&r[64] = *(float *)&r[40] - *(float *)&r[32];
        *(float *)&r[64] = *(float *)&r[64] / 20.0;
        *(float *)&r[64] = *(float *)&r[64] + 0.5;
        v9 = (int)*(float *)&r[64];
        *(float *)&r[64] = *(float *)&r[44] - *(float *)&r[36];
        *(float *)&r[64] = *(float *)&r[64] / 20.0;
        *(float *)&r[64] = *(float *)&r[64] + 0.5;
        v10 = (double)(int)*(float *)&r[64];
        *(float *)&r[64] = *(float *)&r[32] / 20.0;
        *(float *)&r[64] = *(float *)&r[64] + 0.5;
        v11 = (double)(int)*(float *)&r[64];
        *(float *)&r[64] = *(float *)&r[36] / 20.0;
        v12 = (double)v9;
        *(float *)&r[64] = *(float *)&r[64] + 0.5;
        v13 = (int)*(float *)&r[64];
        *(_DWORD *)&r[64] = v13;
        *(double *)r = v11;
        *(double *)&r[8] = (double)v13;
        *(double *)&r[16] = v11 + v12;
        *(double *)&r[24] = v10 + *(double *)&r[8];
        GASRectangleObject::SetProperties(penv: *(unsigned int *)&r[56], (GMemoryHeap *)r, a3: (int)v38);
        GASValue::SetAsObject(this: *(GASValue **)&r[60], a2: (struct GASObject *)*(this + 13));
        GRefCountNTSImpl::Release(this: v8);
        return r[71];
      }
    }
    goto LABEL_5;
  }
  if ( strcmp(v4, (const char *)&stru_102A69D8.m_Memory.m_nGrowSize) == 0 )
  {
    v15 = (GFxMovieRoot *)*(this + 9);
    r[71] = 1;
    if ( v15 != nullptr )
    {
      GFxCharacterHandle::ResolveCharacter(
        this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
        a2: v15);
      *(_DWORD *)&r[64] = v16;
      if ( v16 != 0 )
      {
        ++*(_DWORD *)(v16 + 4);
        qmemcpy(&r[96], (const void *)(v16 + 36), 0x20u);
        qmemcpy(&(*(this + 12))[13], &r[96], 32);
        GASValue::SetAsObject(this: *(GASValue **)&r[60], a2: (struct GASObject *)*(this + 12));
        GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)&r[64]);
        return r[71];
      }
    }
LABEL_5:
    r[71] = 0;
    GASValue::DropRefs(this: *(GASValue **)&r[60], a2: (int)name);
    **(_BYTE **)&r[60] = 0;
    return r[71];
  }
  if ( strcmp(v4, (const char *)&stru_102A69D8) == 0 )
  {
    v17 = (GFxMovieRoot *)*(this + 9);
    r[71] = 1;
    if ( v17 != nullptr )
    {
      GFxCharacterHandle::ResolveCharacter(
        this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
        a2: v17);
      v19 = (GRefCountNTSImpl *)v18;
      if ( v18 != 0 )
      {
        ++*(_DWORD *)(v18 + 4);
        v44[0] = *(float *)(v18 + 68);
        v44[1] = *(float *)(v18 + 72);
        v44[2] = *(float *)(v18 + 76);
        v44[3] = *(float *)(v18 + 80);
        v44[4] = *(float *)(v18 + 84);
        v44[5] = *(float *)(v18 + 88);
        GASMatrixObject::SetMatrixTwips(
          psc: (void *)(*(_DWORD *)&r[56] + 120),
          m: (GMemoryHeap *)v44,
          a3: v38,
          a4: (int)v39);
        GASValue::SetAsObject(this: *(GASValue **)&r[60], a2: (struct GASObject *)*(this + 11));
        GRefCountNTSImpl::Release(this: v19);
        return r[71];
      }
    }
    goto LABEL_5;
  }
  if ( GASString::operator==(this: (const char ***)name, a2: (const char *)&stru_102A69BC) )
  {
    GRenderer::Cxform::Cxform(this: (float *)&r[96]);
    if ( *(this + 9) != nullptr )
    {
      GFxCharacterHandle::ResolveCharacter(
        this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
        a2: (GFxMovieRoot *)*(this + 9));
      v21 = v20;
      if ( v20 != nullptr )
      {
        ++v20->RefCount;
        for ( i = v20; i != nullptr; i = (GRefCountNTSImpl *)i[4].__vftable )
          GRenderer::Cxform::Concatenate(
            this: (GRenderer::Cxform *)&r[96],
            a2: (const struct GRenderer::Cxform *)&i[4].RefCount);
        GRefCountNTSImpl::Release(this: v21);
      }
    }
    v23 = *(_DWORD *)&r[56];
    v24 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&r[56] + 120) + 656);
    v25 = *(int (__thiscall **)(int, int, _BYTE *))(*(_DWORD *)v24 + 40);
    *(_DWORD *)&r[52] = 323;
    v26 = (GArrayBase<GArrayData<GFxMovieRoot *,GAllocatorLH<GFxMovieRoot *,2>,GArrayDefaultPolicy> > *)v25(a1: v24, a2: 84, a3: &r[52]);
    if ( v26 != nullptr )
      v27 = (struct GASObject *)GASColorTransformObject::GASColorTransformObject(this: v26, penv: v23);
    else
      v27 = nullptr;
    qmemcpy(&v27[6].sequence, &r[96], 32);
    v28 = (tagWNDCLASSW *)GASValue::GASValue(this: v41, a2: v27);
    GASValue::operator=(this: *(int *)&r[60], v: v28);
    GASValue::~GASValue(this: v41, a2: (int)&v27[10].sequence);
    GRefCountBaseGC<323>::Release(a1: (int)v27, a2: (int)&v27[10].sequence);
    return 1;
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: (const char *)&stru_102A69A8) )
  {
    GMatrix2D::SetIdentity(this: (float *)&r[72]);
    if ( *(this + 9) != nullptr )
    {
      GFxCharacterHandle::ResolveCharacter(
        this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
        a2: (GFxMovieRoot *)*(this + 9));
      v30 = v29;
      if ( v29 != nullptr )
      {
        ++v29->RefCount;
        for ( j = v29; j != nullptr; j = (GRefCountNTSImpl *)j[4].__vftable )
          GMatrix2D::Prepend(this: (GMatrix2D *)&r[72], a2: (const struct GMatrix2D *)&j[8].RefCount);
        GRefCountNTSImpl::Release(this: v30);
      }
    }
    v32 = *(_DWORD *)&r[56];
    v33 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&r[56] + 120) + 656);
    v34 = *(int (__thiscall **)(int, int, _BYTE *))(*(_DWORD *)v33 + 40);
    v35 = (void *)(*(_DWORD *)&r[56] + 120);
    *(_DWORD *)&r[48] = 323;
    if ( v34(a1: v33, a2: 52, a3: &r[48]) != 0 )
      v36 = (struct GASObject *)GASMatrixObject::GASMatrixObject(
                                  penv: v32,
                                  a2: (GMemAddressStub *)v38,
                                  a3: v39,
                                  a4: v40);
    else
      v36 = nullptr;
    GASMatrixObject::SetMatrixTwips(psc: v35, m: (GMemoryHeap *)&r[72], a3: v38, a4: (int)v39);
    v37 = (tagWNDCLASSW *)GASValue::GASValue(this: v42, a2: v36);
    GASValue::operator=(this: *(int *)&r[60], v: v37);
    GASValue::~GASValue(this: v42, a2: (int)name);
    if ( v36 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v36, a2: (int)name);
    return 1;
  }
  else
  {
    return (unsigned __int8)GASObject::GetMember(
                              (D3DXQUATERNION *)this,
                              result: *(ID3DXFont **)&r[56],
                              penv: name,
                              val: *(int **)&r[60]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124080
// Name: public: virtual bool GASTransformObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTransformObject::SetMember(
        GASTransformObject *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        const struct GASPropFlags *flags)
{
  GRefCountNTSImpl *v6; // eax
  GRefCountNTSImpl *v7; // esi
  struct GASObject *v8; // eax
  int v9; // edi
  GRefCountNTSImpl *v10; // eax
  struct GASObject *v11; // eax
  double v12; // st7
  __int128 v13; // [esp+0h] [ebp-8Ch]
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v14; // [esp+18h] [ebp-74h] BYREF
  GMatrix2D penv; // [esp+70h] [ebp-1Ch] BYREF

  HIDWORD(v13) = flags;
  if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A69F0) != 0 )
  {
    if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A69D8.m_Memory.m_nGrowSize) == 0 )
    {
      if ( *(this + 9) != nullptr )
      {
        GFxCharacterHandle::ResolveCharacter(
          this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
          a2: (GFxMovieRoot *)*(this + 9));
        v7 = v6;
        if ( v6 != nullptr )
        {
          ++v6->RefCount;
          v8 = GASValue::ToObject(this: (GASValue *)val, a2: (int)this, a3: a2);
          v9 = (int)v8;
          if ( v8 == nullptr )
          {
LABEL_9:
            GRefCountNTSImpl::Release(this: v7);
            return;
          }
          v8[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v8[1].pNode->pNext + 1) & 0x8FFFFFFF);
          if ( ((int (__thiscall *)(struct GASObject *))v8[2].pNode[1].pNext)(a1: &v8[2]) == 18 )
          {
            GFxCharacter::SetCxform(this: (GFxCharacter *)v7, a2: (const struct GRenderer::Cxform *)(v9 + 52));
            ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v7->__vftable[8].dtr_GRefCountImplCore)(a1: v7, a2: 0);
          }
LABEL_8:
          GRefCountBaseGC<323>::Release(a1: v9, a2: v9);
          goto LABEL_9;
        }
      }
    }
    else
    {
      if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A69D8) != 0 )
      {
        GASObject::SetMember(
          (CTSQueue<CFunctor *,0,1> *)this,
          (GASEnvironment *)a2,
          name,
          pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
          pmember: (char *)flags);
        return;
      }
      if ( *(this + 9) != nullptr )
      {
        GFxCharacterHandle::ResolveCharacter(
          this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 10),
          a2: (GFxMovieRoot *)*(this + 9));
        v7 = v10;
        if ( v10 != nullptr )
        {
          ++v10->RefCount;
          v11 = GASValue::ToObject(this: (GASValue *)val, a2: (int)this, a3: a2);
          v9 = (int)v11;
          if ( v11 == nullptr )
            goto LABEL_9;
          v11[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v11[1].pNode->pNext + 1) & 0x8FFFFFFF);
          if ( ((int (__thiscall *)(struct GASObject *))v11[2].pNode[1].pNext)(a1: &v11[2]) == 15 )
          {
            GASMatrixObject::GetMatrix((void *)&penv, v: (GMemAddressStub *)a2, a3: (const char *)v13, a4: SDWORD1(v13));
            penv.M_[0][2] = penv.M_[0][2] * 20.0;
            v12 = 20.0 * penv.M_[1][2];
            penv.M_[1][2] = v12;
            GFxCharacter::SetMatrix(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v7,
              m: (CMatRenderContextBase *)&penv,
              a3: v13);
            GFxASCharacter::GeomDataType::GeomDataType(this: &v14);
            GFxASCharacter::GetGeomData(
              this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v7,
              a2: v12,
              fX: &v14);
            v14.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)(int)CMaterial_QueueFriendly::GetAlphaModulation(this: (CMaterialDict::MaterialLookup_t *)&penv);
            v14.m_nUserID = (int)GMatrix2D::GetY(this: (CMaterialDict::MaterialLookup_t *)&penv);
            *((double *)&v14.m_Proxy.m_pfnProxied + 1) = GMatrix2D::GetRotation(this: &penv) * 180.0 / 3.141592653589793;
            *(double *)&v14.CRefCountServiceDestruct<CRefST> = GMatrix2D::GetXScale(this: &penv) * 100.0;
            *(double *)&v14.m_Proxy.m_pfnProxied = GMatrix2D::GetYScale(this: &penv) * 100.0;
            GFxASCharacter::SetGeomData(
              this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v7,
              gd: &v14);
          }
          goto LABEL_8;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101242F0
// Name: public: static void GASTransformCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTransformCtorFunction::GlobalCtor(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  struct GASValue *v3; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *TargetByValue; // ebx
  GASValue *v5; // esi
  GASFnCall v6; // eax
  int p_cxItem; // edi
  int v8; // ecx
  int (__thiscall *v9)(int, int, GASFnCall **); // eax
  GASTransformObject *v10; // eax
  GASTransformObject *v11; // eax

  v2 = a2;
  if ( (int)a2[7] >= 1 )
  {
    v3 = GASFnCall::Arg(this: a2, a2: 0);
    TargetByValue = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASEnvironment::FindTargetByValue(this: (GASEnvironment *)v2[6], path: (__vc_attributes::event_receiverAttribute::type_e)v3);
    if ( TargetByValue != nullptr )
    {
      if ( v2[2] != nullptr
        && (*(int (__thiscall **)(GASFnCall))(v2[2]->cbSize + 8))(a1: v2[2]) == 20
        && (*(unsigned __int8 (__thiscall **)(GASFnCall))(v2[2]->cbSize + 64))(a1: v2[2]) == 0 )
      {
        v6 = v2[2];
        if ( v6 != nullptr )
        {
          p_cxItem = (int)&v6[-1].cxItem;
          if ( v6 != (GASFnCall)16 )
            *(_DWORD *)(p_cxItem + 8) = (*(_DWORD *)(p_cxItem + 8) + 1) & 0x8FFFFFFF;
        }
        else
        {
          p_cxItem = 0;
        }
      }
      else
      {
        v8 = *(_DWORD *)(v2[6][3].cbSize + 656);
        v9 = *(int (__thiscall **)(int, int, GASFnCall **))(*(_DWORD *)v8 + 40);
        a2 = (GASFnCall *)323;
        v10 = (GASTransformObject *)v9(a1: v8, a2: 72, a3: &a2);
        if ( v10 != nullptr )
          v11 = GASTransformObject::GASTransformObject(this: v10, a2: (struct GASEnvironment *)v2[6], result: nullptr);
        else
          v11 = nullptr;
        p_cxItem = (int)v11;
      }
      GASTransformObject::SetTarget(this: (GFxCharacterHandle **)p_cxItem, result: TargetByValue);
      GASValue::SetAsObject(this: (GASValue *)v2[1], a2: (struct GASObject *)p_cxItem);
      if ( p_cxItem != 0 )
        GRefCountBaseGC<323>::Release(a1: p_cxItem, a2: a1);
    }
    else
    {
      v5 = (GASValue *)v2[1];
      GASValue::DropRefs(this: v5, a2: a1);
      *(_BYTE *)v5 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101243D0
// Name: public: virtual class GASObject __near * GASTransformCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASTransformObject *__thiscall GASTransformCtorFunction::CreateNewObject(
        GArrayData<GFxMovieRoot *,GAllocatorLH<GFxMovieRoot *,2>,GArrayDefaultPolicy> *this,
        unsigned int penv)
{
  struct GASEnvironment *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, unsigned int *); // edx
  GASTransformObject *v5; // eax

  v2 = (struct GASEnvironment *)penv;
  v3 = *(_DWORD *)(*(_DWORD *)(penv + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v3 + 40);
  penv = 323;
  v5 = (GASTransformObject *)v4(a1: v3, a2: 72, a3: &penv);
  if ( v5 != nullptr )
    return GASTransformObject::GASTransformObject(this: v5, a2: v2, result: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10124900
// Name: public: GASTransformProto::GASTransformProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASTransformProto *__userpurge GASTransformProto::GASTransformProto@<eax>(
        GASTransformProto *this@<ecx>,
        int a2@<edi>,
        struct GASStringContext *a3,
        struct GASObject *ConstStringNode,
        const struct GASFunctionRef *a5)
{
  int v6; // eax
  struct GASObject *v7; // eax
  bool v8; // zf
  int v9; // ecx
  struct GASObject *v10; // eax
  int v11; // edx
  struct GASObject *v12; // eax
  int v13; // eax
  struct GASObject *v14; // eax
  int v15; // ecx
  struct GASObject *v16; // eax
  GASValue v18[4]; // [esp+Ch] [ebp-10h] BYREF

  GASPrototype<GASTransformObject,GASEnvironment>::GASPrototype<GASTransformObject,GASEnvironment>(
    (int)this,
    psc: a3,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)ConstStringNode,
    psc_8: (unsigned int)a5);
  *(_DWORD *)this = &stru_102A69F0.m_pElements;
  *((_DWORD *)this + 4) = &GASTransformProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 18) = &stru_102A69F0.m_Size;
  HIBYTE(a5) = 6;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 18,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)a3,
    flags_4: (const struct GASNameFunction *)&GASTransformProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&a5 + 3));
  v6 = *(_DWORD *)a3;
  LOBYTE(v18[0]) = 0;
  HIBYTE(a5) = 2;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v6 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A69D8,
                                          a3: 6u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: a3,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: v18,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v7 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  v9 = *(_DWORD *)a3;
  HIBYTE(a5) = 6;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v9 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A69A8,
                                          a3: 0x12u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: a3,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: v18,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v10 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v10);
  v11 = *(_DWORD *)a3;
  HIBYTE(a5) = 2;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v11 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A69D8.m_Memory.m_nGrowSize,
                                          a3: 0xEu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: a3,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: v18,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v12 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  v13 = *(_DWORD *)a3;
  HIBYTE(a5) = 6;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v13 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A69BC,
                                          a3: 0x1Au,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: a3,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: v18,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v14 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  v15 = *(_DWORD *)a3;
  HIBYTE(a5) = 2;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v15 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A69F0,
                                          a3: 0xBu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: a3,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: v18,
    a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  v16 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  GASValue::~GASValue(this: v18, a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10124B70
// Name: public: static class GASFunctionRef GASTransformCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASTransformCtorFunction::Register(struct GASFunctionRef *a1, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  GASCFunctionObject *v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASTransformProto *v11; // ebx
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  GASTransformProto *v13; // ebx
  unsigned int Deref; // edx
  GASValue *v15; // eax
  GASValue v17[4]; // [esp+Ch] [ebp-18h] BYREF
  _KCRM_MARSHAL_HEADER *v18; // [esp+1Ch] [ebp-8h] BYREF
  char v19; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v20; // [esp+2Ch] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v18 = pgc;
  v19 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v18,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASTransformCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASTransformCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)a1 = v7;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v11 = (GASTransformProto *)v10(a1: MaxVal, a2: 104, a3: &pgc);
  if ( v11 != nullptr )
  {
    Prototype = GASGlobalContext::GetPrototype(this: v2, result: (vc_attributes::InvalidCheckAttribute *)1);
    v13 = GASTransformProto::GASTransformProto(
            this: v11,
            a2: (int)a1,
            a3: (struct GASStringContext *)&v18,
            ConstStringNode: (struct GASObject *)Prototype,
            a5: a1);
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 != nullptr )
    *((_DWORD *)v13 + 2) = (*((_DWORD *)v13 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)a1, a3: 12, a4: (int)v13);
  Deref = v2[55].Deref;
  HIBYTE(pgc) = 0;
  v20 = *(struct GASFunctionRef **)(Deref + 16);
  v15 = GASValue::GASValue(this: v17, a2: (int)a1, a3: a1);
  (*((void (__thiscall **)(unsigned int, _KCRM_MARSHAL_HEADER **, const char **, GASValue *, char *))v20 + 10))(
    a1: v2[55].Deref + 16,
    a2: &v18,
    a3: &v2[4].MaxVal,
    a4: v15,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v17, a2: (int)a1);
  if ( v13 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v13, a2: (int)a1);
  return a1;
}
