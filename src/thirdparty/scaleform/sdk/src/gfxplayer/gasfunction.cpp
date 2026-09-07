// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gasfunction.cpp
// Functions: 42
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gasfunction.h"

//------------------------------------------------------------------------------
// Address: 0x10068410
// Name: private: void GASPagedStack<class GASValue,32>::PushPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GASValue,32>::PushPage(__vc_attributes::iid_isAttribute *this)
{
  GRenderer_vtbl *v2; // eax
  GRenderer::CachedData *v3; // edi
  unsigned int v4; // esi
  GRenderer *pRenderer; // ecx
  GRenderer *v6; // esi
  int v7; // [esp+4h] [ebp-4h] BYREF

  v2 = *((GRenderer_vtbl **)this + 7);
  if ( v2 != nullptr )
  {
    *(this + 7) = (__vc_attributes::iid_isAttribute)v2[2].ReleaseCachedData;
  }
  else
  {
    v7 = 2;
    v2 = (GRenderer_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 516, a4: &v7);
  }
  v7 = (int)v2;
  if ( v2 == nullptr )
  {
    this->limited_expression -= 16;
    return;
  }
  v3 = (GRenderer::CachedData *)(this + 4);
  v4 = *((_DWORD *)this + 5) + 1;
  if ( v4 >= *((_DWORD *)this + 5) )
  {
    if ( v4 >= *((_DWORD *)this + 6) )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v3,
        pheapAddr: v3,
        newCapacity: v4 + (v4 >> 2));
      goto LABEL_10;
    }
  }
  else if ( v4 < *((_DWORD *)this + 6) >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v3,
      pheapAddr: v3,
      newCapacity: v4);
LABEL_10:
    v2 = (GRenderer_vtbl *)v7;
  }
  pRenderer = v3->pRenderer;
  *((_DWORD *)this + 5) = v4;
  v6 = (GRenderer *)((char *)pRenderer + 4 * v4 - 4);
  if ( v6 != nullptr )
    v6->__vftable = v2;
  *((_DWORD *)this + 3) = *((_DWORD *)this + 2) - 16;
  *((_DWORD *)this + 1) = v2;
  *((_DWORD *)this + 2) = (char *)v2 + 512;
  this->limited_expression = (const char *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10068550
// Name: private: void GASPagedStack<class GASValue,32>::PopPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GASValue,32>::PopPage(__vc_attributes::iid_isAttribute *this)
{
  __vc_attributes::iid_isAttribute *v2; // eax
  __vc_attributes::iid_isAttribute *v3; // edi
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // eax
  unsigned int v7; // eax
  bool v8; // zf

  if ( *((_DWORD *)this + 5) <= 1u )
  {
    v8 = this->limited_expression == (const char *)-16;
    this->limited_expression += 16;
    if ( !v8 )
      *this->limited_expression = 0;
  }
  else
  {
    v2 = *(__vc_attributes::iid_isAttribute **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
    v3 = this + 4;
    v2[128].limited_expression = (const char *)*(this + 7);
    *((_DWORD *)this + 7) = v2;
    v4 = *((_DWORD *)this + 5);
    v5 = v4 - 1;
    if ( v4 != 0 )
    {
      if ( v5 < *((_DWORD *)this + 6) >> 1 )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: (GRenderer::CachedData *)this + 2,
          pheapAddr: this + 4,
          newCapacity: v5);
    }
    else if ( v5 >= *((_DWORD *)this + 6) )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: (GRenderer::CachedData *)this + 2,
        pheapAddr: this + 4,
        newCapacity: v5 + (v5 >> 2));
    }
    *((_DWORD *)this + 5) = v5;
    v6 = *(_DWORD *)&v3->limited_expression[4 * v5 - 4];
    *((_DWORD *)this + 1) = v6;
    v6 += 512;
    *((_DWORD *)this + 2) = v6;
    this->limited_expression = (const char *)(v6 - 16);
    v7 = *((_DWORD *)this + 5);
    if ( v7 <= 1 )
      *(this + 3) = *(this + 1);
    else
      *((_DWORD *)this + 3) = *(_DWORD *)&v3->limited_expression[4 * v7 - 8] + 496;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068DE0
// Name: public: void GASPagedStack<class GASValue,32>::Pop(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GASValue,32>::Pop(int this, __vc_attributes::readonlyAttribute *result)
{
  __vc_attributes::readonlyAttribute *i; // edi

  for ( i = result; i != nullptr; --i )
  {
    GASValue::~GASValue(this: *(GASValue **)this);
    *(_DWORD *)this -= 16;
    if ( *(_DWORD *)this < *(_DWORD *)(this + 4) )
      GASPagedStack<GASValue,32>::PopPage((__vc_attributes::iid_isAttribute *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096160
// Name: private: void GASPagedStack<class GPtr<class GASFunctionObject>,32>::PopPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GPtr<GASFunctionObject>,32>::PopPage(__vc_attributes::atl::aggregatesAttribute *this)
{
  __vc_attributes::atl::aggregatesAttribute *v2; // eax
  __vc_attributes::atl::aggregatesAttribute *v3; // edi
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // eax
  unsigned int v7; // eax
  bool v8; // zf

  if ( *((_DWORD *)this + 5) <= 1u )
  {
    v8 = this->clsid == (const char *)-4;
    this->clsid += 4;
    if ( !v8 )
      *(_DWORD *)this->clsid = 0;
  }
  else
  {
    v2 = *(__vc_attributes::atl::aggregatesAttribute **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
    v3 = this + 4;
    v2[32].clsid = (const char *)*(this + 7);
    *((_DWORD *)this + 7) = v2;
    v4 = *((_DWORD *)this + 5);
    v5 = v4 - 1;
    if ( v4 != 0 )
    {
      if ( v5 < *((_DWORD *)this + 6) >> 1 )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: (GRenderer::CachedData *)this + 2,
          pheapAddr: this + 4,
          newCapacity: v5);
    }
    else if ( v5 >= *((_DWORD *)this + 6) )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: (GRenderer::CachedData *)this + 2,
        pheapAddr: this + 4,
        newCapacity: v5 + (v5 >> 2));
    }
    *((_DWORD *)this + 5) = v5;
    v6 = *(_DWORD *)&v3->clsid[4 * v5 - 4];
    *((_DWORD *)this + 1) = v6;
    v6 += 128;
    *((_DWORD *)this + 2) = v6;
    this->clsid = (const char *)(v6 - 4);
    v7 = *((_DWORD *)this + 5);
    if ( v7 <= 1 )
      *(this + 3) = *(this + 1);
    else
      *((_DWORD *)this + 3) = *(_DWORD *)&v3->clsid[4 * v7 - 8] + 124;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099D30
// Name: public: void GASPagedStack<class GASValue,32>::Pop3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GASValue,32>::Pop3(__vc_attributes::iid_isAttribute *this)
{
  GASValue *limited_expression; // ecx
  int i; // edi

  limited_expression = (GASValue *)this->limited_expression;
  if ( (unsigned int)(limited_expression - 12) >= *((_DWORD *)this + 1) )
  {
    GASValue::~GASValue(this: limited_expression);
    this->limited_expression -= 16;
    GASValue::~GASValue(this: (GASValue *)this->limited_expression);
    this->limited_expression -= 16;
    GASValue::~GASValue(this: (GASValue *)this->limited_expression);
    this->limited_expression -= 16;
  }
  else
  {
    for ( i = 3; i != 0; --i )
    {
      GASValue::~GASValue(this: (GASValue *)this->limited_expression);
      this->limited_expression -= 16;
      if ( this->limited_expression < (const char *)*((_DWORD *)this + 1) )
        GASPagedStack<GASValue,32>::PopPage(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB740
// Name: protected: GASFunctionObject::GASFunctionObject(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASFunctionObject *__thiscall GASFunctionObject::GASFunctionObject(
        GASFunctionObject *this,
        struct GASStringContext *psc)
{
  GASObject::GASObject((GASObject *)this, a2: psc);
  *(_DWORD *)this = &GASFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASFunctionObject::`vftable'{for `GASObjectInterface'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AB770
// Name: public: void GASFunctionObject::SetPrototype(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionObject::SetPrototype(
        _DWORD *this,
        _TRANSACTION_NOTIFICATION *result,
        struct GASObject *psc_4)
{
  int v3; // eax
  void *TransactionKey; // esi
  _DWORD *v6; // edi
  GASValue *v7; // eax
  GASValue v8[4]; // [esp+Ch] [ebp-14h] BYREF
  char v9; // [esp+1Fh] [ebp-1h] BYREF
  int psc; // [esp+28h] [ebp+8h]

  v3 = *(this + 4);
  TransactionKey = result->TransactionKey;
  v6 = this + 4;
  v9 = 0;
  psc = v3;
  v7 = GASValue::GASValue(this: v8, a2: psc_4);
  (*(void (__thiscall **)(_DWORD *, _TRANSACTION_NOTIFICATION *, int, GASValue *, char *))(psc + 40))(
    a1: v6,
    a2: result,
    a3: (int)TransactionKey + 316,
    a4: v7,
    a5: &v9);
  GASValue::~GASValue(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100AB7C0
// Name: protected: GASCFunctionObject::GASCFunctionObject(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASCFunctionObject *__thiscall GASCFunctionObject::GASCFunctionObject(
        GASCFunctionObject *this,
        struct GASStringContext *psc)
{
  GASObject::GASObject((GASObject *)this, a2: psc);
  this->dwSize = (unsigned int)&GASCFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  this->cLineHeight = (unsigned int)&GASFunctionObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AB7F0
// Name: public: virtual GASFunctionObject::~GASFunctionObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionObject::~GASFunctionObject(_DWORD *this, const _COMPATIBILITY_CONTEXT_ELEMENT *result)
{
  *this = &GASFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(this + 4) = &GASFunctionObject::`vftable'{for `GASObjectInterface'};
  JUMPOUT(0x10091A30);
}

//------------------------------------------------------------------------------
// Address: 0x100AB820
// Name: public: virtual bool GASCFunctionObject::IsEqual(class GASFunctionObject const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GASCFunctionObject::IsEqual(_DWORD *this, _DWORD *f)
{
  return (*(unsigned __int8 (__thiscall **)(_DWORD *))(*f + 52))(a1: f) != 0 && *(this + 13) == f[13];
}

//------------------------------------------------------------------------------
// Address: 0x100AB860
// Name: public: static void GASFunctionProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GASFunctionProto::ToString(const struct GASFnCall *fn)
{
  int v1; // esi
  int v2; // edi
  int result; // eax

  v1 = *((_DWORD *)fn + 1);
  v2 = *(_DWORD *)(*((_DWORD *)fn + 6) + 120);
  if ( *(_BYTE *)v1 >= 5u )
    GASValue::DropRefs(this: *((GASValue **)fn + 1));
  *(_BYTE *)v1 = 5;
  result = *(_DWORD *)(v2 + 340);
  *(_DWORD *)(v1 + 4) = result;
  ++*(_DWORD *)(result + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AB890
// Name: public: static void GASFunctionProto::ValueOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASFunctionProto::ValueOf(const struct GASFnCall *fn)
{
  int v1; // eax

  v1 = *((_DWORD *)fn + 2);
  if ( v1 != 0 )
    GASValue::SetAsObject(this: *((GASValue **)fn + 1), a2: (struct GASObject *)(v1 - 16));
  else
    GASValue::SetAsObject(this: *((GASValue **)fn + 1), a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100AB900
// Name: public: virtual class GASEnvironment __near * GASAsFunctionObject::GetEnvironment(class GASFnCall const __near &,class GPtr<class GFxASCharacter> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASAsFunctionObject::GetEnvironment(int this, int a2, GRefCountNTSImpl **a3)
{
  GFxMovieRoot *v3; // eax
  GRefCountNTSImpl *v4; // esi
  GRefCountNTSImpl *v5; // eax
  int v6; // ebx

  v3 = *(GFxMovieRoot **)(this + 52);
  if ( v3 != nullptr )
  {
    GFxCharacterHandle::ResolveCharacter(
      this: *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(this + 56),
      a2: v3);
    v4 = v5;
    if ( v5 != nullptr )
      ++v5->RefCount;
  }
  else
  {
    v4 = nullptr;
  }
  v6 = 0;
  if ( v4 != nullptr )
    v6 = ((int (__thiscall *)(GRefCountNTSImpl *))v4->__vftable[28].dtr_GRefCountImplCore)(a1: v4);
  if ( a3 != nullptr )
  {
    if ( v4 != nullptr )
      ++v4->RefCount;
    if ( *a3 != nullptr )
      GRefCountNTSImpl::Release(this: *a3);
    *a3 = v4;
  }
  if ( v6 == 0 )
    v6 = *(_DWORD *)(a2 + 24);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100AB9B0
// Name: public: void GASFunctionRefBase::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(int *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax

  v2 = *this;
  if ( v2 != 0 )
  {
    v3 = ++*(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v2 + 8) = v3 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 2);
    }
  }
  v4 = *(this + 1);
  if ( v4 != 0 )
  {
    v5 = ++*(_DWORD *)(v4 + 8);
    if ( (v5 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v4 + 8) = v5 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v4)(a1: v4, a2: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABA00
// Name: public: void GASFunctionRefBase::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(int *this)
{
  int v2; // ecx
  int v3; // ecx

  v2 = *this;
  if ( v2 != 0 && (--*(_DWORD *)(v2 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 1);
  }
  v3 = *(this + 1);
  if ( v3 != 0 && (--*(_DWORD *)(v3 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(v3 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v3)(a1: v3, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABA70
// Name: public: void GASFunctionRefBase::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(int *this)
{
  int v2; // ecx
  int v3; // eax
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // [esp-4h] [ebp-8h]

  v2 = *this;
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) == 0x10000000 )
    {
      if ( (v3 & 0xFFFFFFF) != 0 )
      {
        v4 = v3 & 0x8FFFFFFF;
        v7 = 2;
      }
      else
      {
        v4 = v3 & 0x8FFFFFFF | 0x20000000;
        v7 = 4;
      }
      *(_DWORD *)(v2 + 8) = v4;
      (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: v7);
    }
  }
  v5 = *(this + 1);
  if ( v5 != 0 )
  {
    v6 = *(_DWORD *)(v5 + 8);
    if ( (v6 & 0x70000000) == 0x10000000 )
    {
      if ( (v6 & 0xFFFFFFF) != 0 )
      {
        *(_DWORD *)(v5 + 8) = v6 & 0x8FFFFFFF;
        (**(void (__thiscall ***)(int, int))v5)(a1: v5, a2: 2);
      }
      else
      {
        *(_DWORD *)(v5 + 8) = v6 & 0x8FFFFFFF | 0x20000000;
        (**(void (__thiscall ***)(int, int))v5)(a1: v5, a2: 4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABB00
// Name: private: void GASPagedStack<class GPtr<class GASFunctionObject>,32>::PushPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GPtr<GASFunctionObject>,32>::PushPage(__vc_attributes::atl::aggregatesAttribute *this)
{
  GRenderer_vtbl *v2; // eax
  GRenderer::CachedData *v3; // edi
  unsigned int v4; // esi
  GRenderer *pRenderer; // ecx
  GRenderer *v6; // esi
  int v7; // [esp+4h] [ebp-4h] BYREF

  v2 = *((GRenderer_vtbl **)this + 7);
  if ( v2 != nullptr )
  {
    *(this + 7) = (__vc_attributes::atl::aggregatesAttribute)v2->LineStyleColor;
  }
  else
  {
    v7 = 2;
    v2 = (GRenderer_vtbl *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 132, a4: &v7);
  }
  v7 = (int)v2;
  if ( v2 == nullptr )
  {
    this->clsid -= 4;
    return;
  }
  v3 = (GRenderer::CachedData *)(this + 4);
  v4 = *((_DWORD *)this + 5) + 1;
  if ( v4 >= *((_DWORD *)this + 5) )
  {
    if ( v4 >= *((_DWORD *)this + 6) )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v3,
        pheapAddr: v3,
        newCapacity: v4 + (v4 >> 2));
      goto LABEL_10;
    }
  }
  else if ( v4 < *((_DWORD *)this + 6) >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v3,
      pheapAddr: v3,
      newCapacity: v4);
LABEL_10:
    v2 = (GRenderer_vtbl *)v7;
  }
  pRenderer = v3->pRenderer;
  *((_DWORD *)this + 5) = v4;
  v6 = (GRenderer *)((char *)pRenderer + 4 * v4 - 4);
  if ( v6 != nullptr )
    v6->__vftable = v2;
  *((_DWORD *)this + 3) = *((_DWORD *)this + 2) - 4;
  *((_DWORD *)this + 1) = v2;
  *((_DWORD *)this + 2) = &v2->LineStyleColor;
  this->clsid = (const char *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100ABBB0
// Name: public: void GASFunctionRefBase::SetLocalFrame(class GASLocalFrame __near *,bool)
// Source: json
//------------------------------------------------------------------------------
tagIMECHARPOSITION *__userpurge GASFunctionRefBase::SetLocalFrame@<eax>(
        int a1@<ecx>,
        int a2@<edi>,
        tagIMECHARPOSITION *result,
        bool internal)
{
  int v5; // ecx
  tagIMECHARPOSITION *v6; // eax

  v5 = *(_DWORD *)(a1 + 4);
  if ( v5 != 0 && (*(_BYTE *)(a1 + 8) & 1) == 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2);
  v6 = result;
  *(_DWORD *)(a1 + 4) = result;
  if ( internal )
    *(_BYTE *)(a1 + 8) |= 1u;
  else
    *(_BYTE *)(a1 + 8) &= ~1u;
  if ( result != nullptr && (*(_BYTE *)(a1 + 8) & 1) == 0 )
    result->pt.x = (result->pt.x + 1) & 0x8FFFFFFF;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100ABC00
// Name: public: void GASFunctionRefBase::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __usercall GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>@<al>(
        int *a1@<ecx>,
        int a2@<edi>)
{
  int v3; // ecx
  char result; // al
  int v5; // ecx

  v3 = *a1;
  if ( v3 != 0 )
    result = GRefCountBaseGC<323>::Release(a1: v3, a2);
  v5 = a1[1];
  if ( v5 != 0 )
    return GRefCountBaseGC<323>::Release(a1: v5, a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ABC20
// Name: public: void GASFunctionRefBase::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(_DWORD *this)
{
  _DWORD *v2; // ecx
  char result; // al
  _DWORD *v4; // ecx

  v2 = (_DWORD *)*this;
  if ( v2 != nullptr )
    result = GRefCountBaseGC<323>::CollectGarbage(this: v2);
  v4 = (_DWORD *)*(this + 1);
  if ( v4 != nullptr )
    return GRefCountBaseGC<323>::CollectGarbage(this: v4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ABC40
// Name: public: void GASFunctionObject::SetProtoAndCtor(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionObject::SetProtoAndCtor(_DWORD *this, _TRANSACTION_NOTIFICATION *result, int psc_4)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned __int8 (__thiscall *v5)(int, _TRANSACTION_NOTIFICATION *, char *, GASValue *); // eax
  int v6; // ecx
  char *v7; // [esp-8h] [ebp-30h]
  GASValue v8[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v9; // [esp+1Ch] [ebp-Ch] BYREF
  int v10; // [esp+20h] [ebp-8h]
  char v11; // [esp+24h] [ebp-4h]

  v3 = psc_4;
  v4 = this + 4;
  (*(void (__thiscall **)(_DWORD *, _TRANSACTION_NOTIFICATION *, int))(*(this + 4) + 52))(
    a1: this + 4,
    a2: result,
    a3: psc_4);
  v7 = (char *)result->TransactionKey + 324;
  v5 = *(unsigned __int8 (__thiscall **)(int, _TRANSACTION_NOTIFICATION *, char *, GASValue *))(*(_DWORD *)(v3 + 16) + 44);
  LOBYTE(v8[0]) = 0;
  if ( v5(a1: v3 + 16, a2: result, a3: v7, a4: v8) != 0 )
  {
    GASValue::ToFunction(a1: &v9, a2: 0);
  }
  else
  {
    v11 = 0;
    v9 = 0;
    v10 = 0;
  }
  GASValue::~GASValue(this: v8);
  v6 = v9;
  if ( v9 != 0 )
  {
    HIBYTE(psc_4) = 3;
    GASValue::GASValue(this: v8, a2: (const struct GASFunctionRef *)&v9);
    (*(void (__thiscall **)(_DWORD *, _TRANSACTION_NOTIFICATION *, char *, GASValue *, char *))(*v4 + 40))(
      a1: v4,
      a2: result,
      a3: (char *)result->TransactionKey + 324,
      a4: v8,
      a5: (char *)&psc_4 + 3);
    GASValue::~GASValue(this: v8);
    v6 = v9;
  }
  if ( (v11 & 2) == 0 && v6 != 0 )
    GRefCountBaseGC<323>::Release(a1: v6, a2: (int)result);
  v9 = 0;
  if ( (v11 & 1) == 0 && v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2: (int)result);
}

//------------------------------------------------------------------------------
// Address: 0x100ABD10
// Name: public: virtual class GASFunctionRef GASFunctionObject::ToFunction(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASFunctionObject::ToFunction(char *this, int a2)
{
  int result; // eax
  char *v3; // ecx

  result = a2;
  v3 = this - 16;
  *(_BYTE *)(a2 + 8) = 0;
  *(_DWORD *)a2 = v3;
  *(_DWORD *)(a2 + 4) = 0;
  if ( v3 != nullptr )
    *((_DWORD *)v3 + 2) = (*((_DWORD *)v3 + 2) + 1) & 0x8FFFFFFF;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ABD40
// Name: public: GASCFunctionObject::GASCFunctionObject(class GASStringContext __near *,class GASObject __near *,void (*)(class GASFnCall const __near &))
// Source: json
//------------------------------------------------------------------------------
GASCFunctionObject *__thiscall GASCFunctionObject::GASCFunctionObject(
        GASCFunctionObject *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *a3,
        void (__cdecl *a4)(const struct GASFnCall *))
{
  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)psc);
  this->dwSize = (unsigned int)&GASCFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  this->cLineHeight = (unsigned int)&GASFunctionObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = a4;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)&this->cLineHeight, psc, psc_4: a3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100ABD80
// Name: public: GASCFunctionObject::GASCFunctionObject(class GASStringContext __near *,void (*)(class GASFnCall const __near &))
// Source: json
//------------------------------------------------------------------------------
GASCFunctionObject *__thiscall GASCFunctionObject::GASCFunctionObject(
        GASCFunctionObject *this,
        _REASON_CONTEXT *func,
        void (__cdecl *a3)(const struct GASFnCall *))
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)func);
  this->dwSize = (unsigned int)&GASCFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  this->cLineHeight = (unsigned int)&GASFunctionObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = a3;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: (vc_attributes::PreRangeAttribute *)func->Version,
                                                    result: (vc_attributes::InvalidCheckAttribute *)7);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&this->cLineHeight,
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)func,
    psc_4: Prototype);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100ABDC0
// Name: public: virtual void GASCFunctionObject::Invoke(class GASFnCall const __near &,class GASLocalFrame __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASCFunctionObject::Invoke(
        void (__cdecl **this)(tagALTTABINFO **),
        tagALTTABINFO **result,
        int fn_4,
        int fn_8)
{
  tagALTTABINFO *v5; // edi
  unsigned int v6; // eax
  _LARGE_INTEGER v7; // kr00_8
  int cItems; // esi
  void (__cdecl *v9)(tagALTTABINFO **); // ecx
  tagALTTABINFO *fn2; // [esp+4h] [ebp-24h] BYREF
  unsigned int v11; // [esp+8h] [ebp-20h]
  int v12; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+14h] [ebp-14h]
  char v15; // [esp+18h] [ebp-10h]
  _LARGE_INTEGER v16; // [esp+1Ch] [ebp-Ch]
  unsigned int v17; // [esp+24h] [ebp-4h]

  if ( *(this + 13) != nullptr )
  {
    v5 = result[2];
    if ( v5 != nullptr && (*(unsigned __int8 (__thiscall **)(tagALTTABINFO *))(v5->cbSize + 60))(a1: result[2]) != 0 )
    {
      v6 = (unsigned int)result[8];
      v7 = *((_LARGE_INTEGER *)result + 3);
      v11 = (unsigned int)result[1];
      cItems = v5[1].cItems;
      v17 = v6;
      v12 = cItems;
      v9 = *(this + 13);
      fn2 = (tagALTTABINFO *)&GASFnCall::`vftable';
      v15 = 0;
      v13 = 0;
      v14 = 0;
      v16 = v7;
      v9(a1: &fn2);
      GASSuperObject::ResetAltProto(this: (GASSuperObject *)&v5[-1].cxItem, a2: (int)v5);
      GASFnCall::~GASFnCall(this: &fn2);
    }
    else
    {
      (*(this + 13))(a1: result);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABE50
// Name: public: void GASFunctionRefBase::Assign(class GASFunctionRefBase const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionRefBase::Assign(GASFunctionRefBase *this, const struct GASFunctionRefBase *orig)
{
  int v3; // ebx
  bool v4; // zf
  int v5; // eax
  tagIMECHARPOSITION *v6; // eax
  int v7; // ecx

  if ( this != orig )
  {
    v3 = *(_DWORD *)this;
    if ( (*((_BYTE *)this + 8) & 2) == 0 && v3 != 0 && v3 != *(_DWORD *)orig )
      GRefCountBaseGC<323>::Release(a1: *(_DWORD *)this, a2: (int)orig);
    v4 = (*((_BYTE *)this + 8) & 2) == 0;
    *(_DWORD *)this = *(_DWORD *)orig;
    if ( v4 )
    {
      v5 = *(_DWORD *)orig;
      if ( *(_DWORD *)orig != 0 && v3 != v5 )
        *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
    }
    v6 = *((tagIMECHARPOSITION **)orig + 1);
    if ( v6 != nullptr )
    {
      GASFunctionRefBase::SetLocalFrame(a1: (int)this, a2: (int)orig, result: v6, internal: *((_BYTE *)orig + 8) & 1);
    }
    else
    {
      v7 = *((_DWORD *)this + 1);
      if ( v7 != 0 && (*((_BYTE *)this + 8) & 1) == 0 )
        GRefCountBaseGC<323>::Release(a1: v7, a2: (int)orig);
      *((_BYTE *)this + 8) &= ~1u;
      *((_DWORD *)this + 1) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABEE0
// Name: public: static void GASFunctionProto::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASFunctionProto::GlobalCtor(int fn)
{
  const struct GASFnCall *v1; // edi
  char v2; // al
  GASValue *v3; // edi
  GASValue *v4; // eax
  struct GASObject *v5; // eax
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // eax
  GASObject *v8; // eax
  struct GASObject *v9; // esi
  const struct GASEnvironment *v10; // [esp-4h] [ebp-8h]

  v1 = (const struct GASFnCall *)fn;
  if ( *(_DWORD *)(fn + 28) == 1 )
  {
    v2 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    if ( v2 == 8 || v2 == 11 || *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0) == 11 )
    {
      v10 = *((const struct GASEnvironment **)v1 + 6);
      v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0);
      v5 = GASValue::ToObject(this: v4, a2: v10);
      GASValue::SetAsObject(this: *((GASValue **)v1 + 1), a2: v5);
    }
    else
    {
      v3 = *((GASValue **)v1 + 1);
      GASValue::DropRefs(this: v3);
      *(_BYTE *)v3 = 1;
    }
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 120) + 656);
    v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
    fn = 323;
    v8 = (GASObject *)v7(a1: v6, a2: 56, a3: &fn);
    v9 = v8;
    if ( v8 != nullptr )
    {
      GASObject::GASObject(this: v8, a2: *((struct GASEnvironment **)v1 + 6));
      v9->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASCFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
      v9[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASFunctionObject::`vftable'{for `GASObjectInterface'};
      v9[6].sequence = 0;
    }
    else
    {
      v9 = nullptr;
    }
    GASValue::SetAsObject(this: *((GASValue **)v1 + 1), a2: v9);
    if ( v9 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v9, a2: (int)v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABFB0
// Name: public: GASFunctionCtorFunction::GASFunctionCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
IDirect3DCubeTexture9 *__stdcall GASFunctionCtorFunction::GASFunctionCtorFunction(
        IDirect3DCubeTexture9 *this,
        const _GUID *psc)
{
  GASObject *v2; // ecx
  GASObject *v3; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v3 = v2;
  GASObject::GASObject(this: v2, a2: (struct GASStringContext *)this);
  v3->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASCFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v3[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASFunctionObject::`vftable'{for `GASObjectInterface'};
  v3[6].sequence = (int)GASFunctionProto::GlobalCtor;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: (vc_attributes::PreRangeAttribute *)this->__vftable,
                                                    result: (vc_attributes::InvalidCheckAttribute *)7);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v3[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)this,
    psc_4: Prototype);
  v3->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASFunctionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  v3[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASFunctionObject::`vftable'{for `GASObjectInterface'};
  return (IDirect3DCubeTexture9 *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AC0C0
// Name: public: GASFunctionProto::GASFunctionProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFunctionProto::GASFunctionProto(
        CUtlMemory<void *,int> *this,
        struct GASStringContext *psc,
        struct GASObject *a3,
        unsigned int a4,
        int a5)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc, a3);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__(a4, (unsigned int)psc);
  this->m_pMemory = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 52),
    pthis: (CMaterialVar *)this,
    psc: v6);
  this->m_pMemory = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASMouseProto::`vftable';
  if ( (_BYTE)a5 != 0 )
  {
    HIBYTE(a5) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)this + 13,
      a2: (struct GASObject *)this,
      a3: psc,
      a4: (const struct GASNameFunction *)&GAS_FunctionObjectTable,
      a5: (const struct GASPropFlags *)((char *)&a5 + 3));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC160
// Name: public: static void GASFunctionProto::Apply(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASFunctionProto::Apply(const struct GASFnCall *i)
{
  GASValue *v2; // ebx
  bool v3; // cc
  _SERVICE_STATUS *v4; // eax
  GASObjectInterface *v5; // ebx
  GStat::StatValue *v6; // eax
  GASValue *v7; // eax
  struct GASObject *v8; // eax
  struct GASObject *v9; // ebx
  int sequence; // eax
  int v11; // eax
  __vc_attributes::iid_isAttribute *v12; // esi
  struct GASValue *v13; // edx
  const char *limited_expression; // eax
  GASValue *v15; // esi
  _DWORD *v16; // eax
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
  int *v22; // ebx
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // eax
  void (__thiscall *v26)(int *, _DWORD *, _DWORD, _DWORD); // edx
  int v27; // esi
  _SERVICE_STATUS *v28; // [esp-4h] [ebp-80h]
  const struct GASEnvironment *v29; // [esp-4h] [ebp-80h]
  _DWORD v30[3]; // [esp+Ch] [ebp-70h] BYREF
  int v31; // [esp+18h] [ebp-64h]
  int v32; // [esp+1Ch] [ebp-60h]
  char v33; // [esp+20h] [ebp-5Ch]
  _DWORD *v34; // [esp+24h] [ebp-58h]
  int v35; // [esp+28h] [ebp-54h]
  int v36; // [esp+2Ch] [ebp-50h]
  _DWORD v37[3]; // [esp+30h] [ebp-4Ch] BYREF
  int v38; // [esp+3Ch] [ebp-40h]
  int v39; // [esp+40h] [ebp-3Ch]
  char v40; // [esp+44h] [ebp-38h]
  _DWORD *v41; // [esp+48h] [ebp-34h]
  int v42; // [esp+4Ch] [ebp-30h]
  int v43; // [esp+50h] [ebp-2Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *result; // [esp+54h] [ebp-28h] BYREF
  struct GASValue *v45; // [esp+64h] [ebp-18h]
  int v46; // [esp+68h] [ebp-14h]
  GStat::StatValue *charHolder; // [esp+6Ch] [ebp-10h]
  struct GASObject *v48; // [esp+70h] [ebp-Ch]
  _SERVICE_STATUS *v49; // [esp+74h] [ebp-8h]
  int nArgs; // [esp+78h] [ebp-4h]
  int ia; // [esp+84h] [ebp+8h]

  v2 = *((GASValue **)i + 1);
  v46 = 0;
  charHolder = nullptr;
  v49 = nullptr;
  nArgs = 0;
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  v3 = *((_DWORD *)i + 7) < 1;
  v48 = nullptr;
  if ( !v3 )
  {
    v28 = *((_SERVICE_STATUS **)i + 6);
    GASFnCall::Arg(this: (GASFnCall *)i, a2: 0);
    v4 = GASValue::ToObjectInterface(result: v28);
    v49 = v4;
    if ( v4 != nullptr )
    {
      v5 = (GASObjectInterface *)v4;
      if ( (unsigned int)((*(int (__thiscall **)(_SERVICE_STATUS *))(v4->dwServiceType + 8))(a1: v4) - 2) > 3 )
      {
        if ( v5 != (GASObjectInterface *)16 )
          *((_DWORD *)v5 - 2) = (*((_DWORD *)v5 - 2) + 1) & 0x8FFFFFFF;
        v46 = (int)v5 - 16;
      }
      else
      {
        v6 = (GStat::StatValue *)GASObjectInterface::ToASCharacter(this: v5);
        if ( v6 != nullptr )
          ++v6->pName;
        charHolder = v6;
      }
    }
  }
  if ( *((int *)i + 7) >= 2 )
  {
    v29 = *((const struct GASEnvironment **)i + 6);
    v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)i, a2: 1);
    v8 = GASValue::ToObject(this: v7, a2: v29);
    v9 = v8;
    if ( v8 != nullptr && ((int (__thiscall *)(struct GASObject *))v8[2].pNode[1].pNext)(a1: &v8[2]) == 7 )
    {
      v9[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v9[1].pNode->pNext + 1) & 0x8FFFFFFF);
      sequence = v9[7].sequence;
      v48 = v9;
      nArgs = sequence;
      if ( sequence > 0 )
      {
        v11 = sequence - 1;
        for ( ia = v11; ia >= 0; --ia )
        {
          v12 = *((__vc_attributes::iid_isAttribute **)i + 6);
          v13 = *((struct GASValue **)&v9[7].pNode->pNext + v11);
          v12[2].limited_expression += 16;
          limited_expression = v12[2].limited_expression;
          v45 = v13;
          if ( limited_expression >= v12[4].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: v12 + 2);
          v15 = (GASValue *)v12[2].limited_expression;
          if ( v15 != nullptr )
            GASValue::GASValue(this: v15, a2: v45);
          v11 = ia - 1;
        }
      }
    }
  }
  LOBYTE(result) = 0;
  if ( *((_DWORD *)i + 3) != 0 )
  {
    v16 = *((_DWORD **)i + 6);
    v17 = nArgs;
    v18 = ((v16[2] - v16[3]) >> 4) + 32 * v16[7] - 32;
    v37[1] = &result;
    v37[2] = v49;
    v38 = 0;
    v39 = 0;
    v19 = *((_DWORD *)i + 4);
    v43 = v18;
    v20 = *((_DWORD *)i + 3);
    v41 = v16;
    v37[0] = &GASFnCall::`vftable';
    v40 = 0;
    v42 = nArgs;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v20 + 40))(a1: v20, a2: v37, a3: v19, a4: 0);
    v37[0] = &GASFnCall::`vftable';
    if ( (v40 & 2) == 0 && v38 != 0 )
      GRefCountBaseGC<323>::Release(a1: v38, a2: (int)i);
    v38 = 0;
    if ( (v40 & 1) == 0 && v39 != 0 )
      GRefCountBaseGC<323>::Release(a1: v39, a2: (int)i);
  }
  else
  {
    v21 = *((_DWORD *)i + 2);
    if ( v21 != 0 )
    {
      v22 = (int *)(v21 - 16);
      if ( v22 != nullptr )
        v22[2] = (v22[2] + 1) & 0x8FFFFFFF;
    }
    else
    {
      v22 = nullptr;
    }
    v23 = *((_DWORD **)i + 6);
    v24 = ((v23[2] - v23[3]) >> 4) + 32 * v23[7] - 32;
    v30[1] = &result;
    v30[2] = v49;
    v34 = v23;
    v36 = v24;
    v35 = nArgs;
    v25 = *v22;
    v31 = 0;
    v32 = 0;
    v26 = *(void (__thiscall **)(int *, _DWORD *, _DWORD, _DWORD))(v25 + 40);
    v30[0] = &GASFnCall::`vftable';
    v33 = 0;
    v26(a1: v22, a2: v30, a3: 0, a4: 0);
    v30[0] = &GASFnCall::`vftable';
    if ( (v33 & 2) == 0 && v31 != 0 )
      GRefCountBaseGC<323>::Release(a1: v31, a2: (int)i);
    v31 = 0;
    if ( (v33 & 1) == 0 && v32 != 0 )
      GRefCountBaseGC<323>::Release(a1: v32, a2: (int)i);
    GRefCountBaseGC<323>::Release(a1: (int)v22, a2: (int)i);
    v17 = nArgs;
  }
  if ( v17 > 0 )
  {
    v27 = *((_DWORD *)i + 6);
    if ( nArgs != 0 )
    {
      do
      {
        GASValue::~GASValue(this: *(GASValue **)(v27 + 8));
        *(_DWORD *)(v27 + 8) -= 16;
        if ( *(_DWORD *)(v27 + 8) < *(_DWORD *)(v27 + 12) )
          GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v27 + 8));
        --v17;
      }
      while ( v17 != 0 );
    }
  }
  GASValue::operator=(v: (tagWNDCLASSW *)&result);
  GASValue::~GASValue(this: &result);
  if ( v48 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v48, a2: (int)i);
  if ( charHolder != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)charHolder);
  if ( v46 != 0 )
    GRefCountBaseGC<323>::Release(a1: v46, a2: (int)i);
}

//------------------------------------------------------------------------------
// Address: 0x100AC440
// Name: public: static void GASFunctionProto::Call(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASFunctionProto::Call(const struct GASFnCall *fn)
{
  GASValue *v2; // esi
  _SERVICE_STATUS *v3; // eax
  GASObjectInterface *v4; // esi
  GStat::StatValue *v5; // eax
  int v6; // eax
  int v7; // ebx
  struct GASValue *v8; // eax
  __vc_attributes::iid_isAttribute *v9; // esi
  GASValue *limited_expression; // esi
  _DWORD *v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  int *v17; // esi
  _DWORD *v18; // eax
  int v19; // ecx
  int v20; // eax
  void (__thiscall *v21)(int *, _DWORD *, _DWORD, _DWORD); // edx
  int v22; // ebx
  int v23; // esi
  _SERVICE_STATUS *v24; // [esp-4h] [ebp-78h]
  _DWORD v25[3]; // [esp+Ch] [ebp-68h] BYREF
  int v26; // [esp+18h] [ebp-5Ch]
  int v27; // [esp+1Ch] [ebp-58h]
  char v28; // [esp+20h] [ebp-54h]
  _DWORD *v29; // [esp+24h] [ebp-50h]
  int v30; // [esp+28h] [ebp-4Ch]
  int v31; // [esp+2Ch] [ebp-48h]
  _DWORD v32[3]; // [esp+30h] [ebp-44h] BYREF
  int v33; // [esp+3Ch] [ebp-38h]
  int v34; // [esp+40h] [ebp-34h]
  char v35; // [esp+44h] [ebp-30h]
  _DWORD *v36; // [esp+48h] [ebp-2Ch]
  int v37; // [esp+4Ch] [ebp-28h]
  int v38; // [esp+50h] [ebp-24h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *result; // [esp+54h] [ebp-20h] BYREF
  int v40; // [esp+64h] [ebp-10h]
  GStat::StatValue *charHolder; // [esp+68h] [ebp-Ch]
  _SERVICE_STATUS *v42; // [esp+6Ch] [ebp-8h]
  int nArgs; // [esp+70h] [ebp-4h]
  const struct GASValue *fna; // [esp+7Ch] [ebp+8h]

  v2 = *((GASValue **)fn + 1);
  v40 = 0;
  charHolder = nullptr;
  v42 = nullptr;
  nArgs = 0;
  GASValue::DropRefs(this: v2);
  *(_BYTE *)v2 = 0;
  if ( *((int *)fn + 7) >= 1 )
  {
    v24 = *((_SERVICE_STATUS **)fn + 6);
    GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v3 = GASValue::ToObjectInterface(result: v24);
    v42 = v3;
    if ( v3 != nullptr )
    {
      v4 = (GASObjectInterface *)v3;
      if ( (unsigned int)((*(int (__thiscall **)(_SERVICE_STATUS *))(v3->dwServiceType + 8))(a1: v3) - 2) > 3 )
      {
        if ( v4 != (GASObjectInterface *)16 )
          *((_DWORD *)v4 - 2) = (*((_DWORD *)v4 - 2) + 1) & 0x8FFFFFFF;
        v40 = (int)v4 - 16;
      }
      else
      {
        v5 = (GStat::StatValue *)GASObjectInterface::ToASCharacter(this: v4);
        if ( v5 != nullptr )
          ++v5->pName;
        charHolder = v5;
      }
    }
  }
  v6 = *((_DWORD *)fn + 7);
  if ( v6 >= 2 )
  {
    v7 = v6 - 1;
    nArgs = v6 - 1;
    do
    {
      v8 = GASFnCall::Arg(this: (GASFnCall *)fn, a2: v7);
      v9 = *((__vc_attributes::iid_isAttribute **)fn + 6);
      v9[2].limited_expression += 16;
      fna = v8;
      if ( v9[2].limited_expression >= v9[4].limited_expression )
        GASPagedStack<GASValue,32>::PushPage(this: v9 + 2);
      limited_expression = (GASValue *)v9[2].limited_expression;
      if ( limited_expression != nullptr )
        GASValue::GASValue(this: limited_expression, a2: fna);
      --v7;
    }
    while ( v7 >= 1 );
  }
  LOBYTE(result) = 0;
  if ( *((_DWORD *)fn + 3) != 0 )
  {
    v11 = *((_DWORD **)fn + 6);
    v12 = nArgs;
    v13 = ((v11[2] - v11[3]) >> 4) + 32 * v11[7] - 32;
    v32[1] = &result;
    v32[2] = v42;
    v33 = 0;
    v34 = 0;
    v14 = *((_DWORD *)fn + 4);
    v38 = v13;
    v15 = *((_DWORD *)fn + 3);
    v36 = v11;
    v32[0] = &GASFnCall::`vftable';
    v35 = 0;
    v37 = nArgs;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v15 + 40))(a1: v15, a2: v32, a3: v14, a4: 0);
    v32[0] = &GASFnCall::`vftable';
    if ( (v35 & 2) == 0 && v33 != 0 )
      GRefCountBaseGC<323>::Release(a1: v33, a2: (int)fn);
    v33 = 0;
    if ( (v35 & 1) == 0 && v34 != 0 )
      GRefCountBaseGC<323>::Release(a1: v34, a2: (int)fn);
  }
  else
  {
    v16 = *((_DWORD *)fn + 2);
    if ( v16 != 0 )
    {
      v17 = (int *)(v16 - 16);
      if ( v17 != nullptr )
        v17[2] = (v17[2] + 1) & 0x8FFFFFFF;
    }
    else
    {
      v17 = nullptr;
    }
    v18 = *((_DWORD **)fn + 6);
    v19 = ((v18[2] - v18[3]) >> 4) + 32 * v18[7] - 32;
    v25[1] = &result;
    v25[2] = v42;
    v29 = v18;
    v31 = v19;
    v30 = nArgs;
    v20 = *v17;
    v26 = 0;
    v27 = 0;
    v21 = *(void (__thiscall **)(int *, _DWORD *, _DWORD, _DWORD))(v20 + 40);
    v25[0] = &GASFnCall::`vftable';
    v28 = 0;
    v21(a1: v17, a2: v25, a3: 0, a4: 0);
    v25[0] = &GASFnCall::`vftable';
    if ( (v28 & 2) == 0 && v26 != 0 )
      GRefCountBaseGC<323>::Release(a1: v26, a2: (int)fn);
    v26 = 0;
    if ( (v28 & 1) == 0 && v27 != 0 )
      GRefCountBaseGC<323>::Release(a1: v27, a2: (int)fn);
    GRefCountBaseGC<323>::Release(a1: (int)v17, a2: (int)fn);
    v12 = nArgs;
  }
  if ( v12 > 0 )
  {
    v22 = v12;
    v23 = *((_DWORD *)fn + 6);
    if ( nArgs != 0 )
    {
      do
      {
        GASValue::~GASValue(this: *(GASValue **)(v23 + 8));
        *(_DWORD *)(v23 + 8) -= 16;
        if ( *(_DWORD *)(v23 + 8) < *(_DWORD *)(v23 + 12) )
          GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v23 + 8));
        --v22;
      }
      while ( v22 != 0 );
    }
  }
  GASValue::operator=(v: (tagWNDCLASSW *)&result);
  GASValue::~GASValue(this: &result);
  if ( charHolder != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)charHolder);
  if ( v40 != 0 )
    GRefCountBaseGC<323>::Release(a1: v40, a2: (int)fn);
}

//------------------------------------------------------------------------------
// Address: 0x100AC6C0
// Name: public: GASAsFunctionObject::GASAsFunctionObject(class GASEnvironment __near *,class GASActionBuffer __near *,unsigned int,unsigned int,class GArrayLH_POD<class GASWithStackEntry,323,struct GArrayDefaultPolicy> const __near *,enum GASActionBuffer::ExecuteType)
// Source: json
//------------------------------------------------------------------------------
GSize<float> *__thiscall GASAsFunctionObject::GASAsFunctionObject(
        GSize<float> *this,
        GSize<float> *penv,
        unsigned int start,
        int a4,
        unsigned int length,
        GTexture *pwithStack,
        int pwithStack_4)
{
  int v8; // ecx
  bool v9; // zf
  int v10; // eax
  float Height; // ecx
  const GSize<float> *v12; // eax
  GFxCharacterHandle *v13; // edi
  const GSize<float> *penva; // [esp+14h] [ebp+8h]
  float pwithStack_4a; // [esp+28h] [ebp+1Ch]

  GASObject::GASObject((GASObject *)this, a2: (struct GASEnvironment *)penv);
  LODWORD(this->Width) = &GASAsFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASAsFunctionObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  if ( start != 0 )
    ++*(_DWORD *)(start + 4);
  *((_DWORD *)this + 15) = start;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = a4;
  *((_DWORD *)this + 20) = length;
  v8 = *(_DWORD *)(LODWORD(penv[15].Width) + 8);
  ++*(_DWORD *)(v8 + 8);
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = v8;
  v9 = ++*(_DWORD *)(v8 + 8) == 1;
  --*(_DWORD *)(v8 + 8);
  if ( v9 )
    GASStringNode::ReleaseNode();
  v10 = pwithStack_4;
  *((_WORD *)this + 52) = 0;
  *((_WORD *)this + 53) = (unsigned __int8)pwithStack_4;
  if ( pwithStack != nullptr )
  {
    GArrayBase<GArrayData<GASWithStackEntry,GAllocatorLH_POD<GASWithStackEntry,323>,GArrayDefaultPolicy>>::operator=(
      this: (GPtr<GTexture> *)this + 16,
      a: pwithStack);
    v10 = pwithStack_4;
  }
  if ( v10 != 3 && v10 != 4 )
  {
    Height = penv[14].Height;
    v12 = *(const GSize<float> **)(LODWORD(Height) + 148);
    pwithStack_4a = Height;
    if ( v12 == nullptr )
      GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)LODWORD(Height));
    penva = v12;
    if ( v12 != nullptr )
      ++LODWORD(v12->Width);
    v13 = *((GFxCharacterHandle **)this + 14);
    if ( v13 != nullptr )
    {
      *v13 = (GFxCharacterHandle)((char *)*v13 - 1);
      if ( (int)*v13 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v13);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
        v12 = penva;
      }
    }
    *((_DWORD *)this + 14) = v12;
    *((_DWORD *)this + 13) = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(pwithStack_4a) + 84))(a1: COERCE_FLOAT(LODWORD(pwithStack_4a)));
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AC7D0
// Name: public: virtual GASAsFunctionObject::~GASAsFunctionObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASAsFunctionObject::~GASAsFunctionObject(GASObject *this)
{
  int v2; // ecx
  GRefCountNTSImpl *v4; // ecx
  GFxCharacterHandle *v5; // esi

  v2 = *((_DWORD *)this + 25);
  if ( (*(_DWORD *)(v2 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::~GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>(this: (_DWORD *)this + 21);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 16));
  v4 = *((GRefCountNTSImpl **)this + 15);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  v5 = *((GFxCharacterHandle **)this + 14);
  if ( v5 != nullptr )
  {
    *v5 = (GFxCharacterHandle)((char *)*v5 - 1);
    if ( (int)*v5 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v5);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    }
  }
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASFunctionObject::`vftable'{for `GASObjectInterface'};
  GASObject::~GASObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x100AC870
// Name: protected: virtual void GASAsFunctionObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASAsFunctionObject::Finalize_GC(GASObject *this)
{
  int v2; // ecx
  GRefCountNTSImpl *v4; // ecx
  GFxCharacterHandle *v5; // edi

  v2 = *((_DWORD *)this + 25);
  if ( (*(_DWORD *)(v2 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::~GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>(this: (_DWORD *)this + 21);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 16));
  v4 = *((GRefCountNTSImpl **)this + 15);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  *((_DWORD *)this + 15) = 0;
  v5 = *((GFxCharacterHandle **)this + 14);
  if ( v5 != nullptr )
  {
    *v5 = (GFxCharacterHandle)((char *)*v5 - 1);
    if ( (int)*v5 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v5);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    }
  }
  *((_DWORD *)this + 14) = 0;
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x100AC8E0
// Name: public: void InvokeContext::Setup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InvokeContext::Setup(GRect<float> *this)
{
  float Top; // ebx
  int Left_low; // edi
  int *v4; // ebx
  GRenderer::CachedData *Top_low; // ecx
  struct GASObject *sequence; // ebx
  void *hData; // eax
  float Left; // edx
  char v9; // al
  GRenderer::CachedData *v10; // edi
  void *v11; // ecx
  struct GASLocalFrame *NewLocalFrame; // eax
  int v13; // edi
  int v14; // ecx
  float Bottom; // ebx
  int v16; // ecx
  struct GFxASCharacter *v17; // eax
  struct GFxASCharacter *v18; // edi
  GRefCountNTSImpl *v19; // ecx
  PROCESSOR_IDLESTATE_POLICY *v20; // eax
  PROCESSOR_IDLESTATE_POLICY *v21; // edi
  int v22; // ecx
  float v23; // eax
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // edi
  GRefCountNTSImpl *v28; // ecx
  float v29; // ecx
  unsigned int v30; // eax
  float v31; // eax
  int v32; // ecx
  struct GASObject *v33; // eax
  int n; // edi
  _IMAGE_SYMBOL_EX *v35; // ebx
  tagWNDCLASSW *v36; // eax
  int ii; // ebx
  float v38; // eax
  unsigned int v39; // edi
  unsigned int *v40; // ebx
  _BYTE *v41; // eax
  unsigned int i; // edi
  int v43; // eax
  int j; // edi
  int v45; // ecx
  struct GASObject *v46; // eax
  int v47; // ebx
  float Right; // ecx
  tagWNDCLASSW *v49; // eax
  int k; // ebx
  int v51; // ecx
  float v52; // ecx
  __int16 v53; // ax
  int v54; // ebx
  int v55; // edi
  int v56; // eax
  _JOB_SET_ARRAY *Owner; // eax
  int v58; // edi
  bool v59; // zf
  float v60; // ebx
  int (__thiscall *v61)(_DWORD, int, struct GASObject **); // edx
  CBitWrite *v62; // eax
  CBitWrite *v63; // eax
  int v64; // edi
  float v65; // ecx
  GASEnvironment *v66; // eax
  GASEnvironment *v67; // edi
  __int16 v68; // ax
  int (__thiscall *v69)(_DWORD, int, int *); // edx
  struct GASObject *v70; // ebx
  int m; // edi
  const struct GASValue *v72; // eax
  GASEnvironment *v73; // eax
  _IMAGE_SYMBOL_EX *v74; // edi
  tagWNDCLASSW *v75; // eax
  float v76; // ecx
  struct GASObject *v77; // edi
  unsigned int v78; // eax
  float v79; // eax
  int v80; // ecx
  struct GASObject *v81; // ebx
  GASEnvironment *v82; // eax
  float v83; // ecx
  float v84; // esi
  GASEnvironment *v85; // eax
  _IMAGE_SYMBOL_EX *v86; // [esp-8h] [ebp-F0h]
  tagWNDCLASSW *v87; // [esp-4h] [ebp-ECh]
  struct GASObject *v88; // [esp-4h] [ebp-ECh]
  void *v89; // [esp-4h] [ebp-ECh]
  struct GASObject *v90; // [esp-4h] [ebp-ECh]
  struct GASObject *v91; // [esp-4h] [ebp-ECh]
  tagBITMAPCOREHEADER *v92; // [esp-4h] [ebp-ECh]
  struct GASObject *v93; // [esp-4h] [ebp-ECh]
  PROCESSOR_IDLESTATE_POLICY *v94; // [esp+0h] [ebp-E8h]
  const char *v95; // [esp+4h] [ebp-E4h]
  int v96; // [esp+8h] [ebp-E0h]
  GASValue v97[4]; // [esp+Ch] [ebp-DCh] BYREF
  tagWNDCLASSW v98; // [esp+1Ch] [ebp-CCh] BYREF
  GASValue v99[4]; // [esp+4Ch] [ebp-9Ch] BYREF
  GASValue v100[4]; // [esp+5Ch] [ebp-8Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *pthisVal; // [esp+6Ch] [ebp-7Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *superVal; // [esp+7Ch] [ebp-6Ch] BYREF
  GASValue v103[4]; // [esp+8Ch] [ebp-5Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *parent; // [esp+9Ch] [ebp-4Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *thisVal; // [esp+ACh] [ebp-3Ch] BYREF
  int v106; // [esp+BCh] [ebp-2Ch] BYREF
  int v107; // [esp+C0h] [ebp-28h] BYREF
  int v108; // [esp+C4h] [ebp-24h]
  char v109; // [esp+C8h] [ebp-20h]
  int ArgsToPass; // [esp+CCh] [ebp-1Ch]
  float DisplayWidthCm; // [esp+D0h] [ebp-18h]
  int v112; // [esp+D4h] [ebp-14h]
  char v113; // [esp+DAh] [ebp-Eh] BYREF
  char v114; // [esp+DBh] [ebp-Dh] BYREF
  struct GASObject *v115; // [esp+DCh] [ebp-Ch] BYREF
  int CurrentReg; // [esp+E0h] [ebp-8h]
  struct GASObject *v117; // [esp+E4h] [ebp-4h]

  Top = this->Top;
  Left_low = LODWORD(this->Left);
  if ( LODWORD(this->Left) != 0 )
    *(_DWORD *)(Left_low + 8) = (*(_DWORD *)(Left_low + 8) + 1) & 0x8FFFFFFF;
  *(_DWORD *)(LODWORD(Top) + 128) += 4;
  if ( *(_DWORD *)(LODWORD(Top) + 128) >= *(_DWORD *)(LODWORD(Top) + 136) )
    GASPagedStack<GPtr<GASFunctionObject>,32>::PushPage(this: (__vc_attributes::atl::aggregatesAttribute *)(LODWORD(Top) + 128));
  v4 = *(int **)(LODWORD(Top) + 128);
  if ( v4 != nullptr )
  {
    if ( Left_low != 0 )
      *(_DWORD *)(Left_low + 8) = (*(_DWORD *)(Left_low + 8) + 1) & 0x8FFFFFFF;
    *v4 = Left_low;
  }
  if ( Left_low != 0 )
    GRefCountBaseGC<323>::Release(a1: Left_low, a2: Left_low);
  Top_low = (GRenderer::CachedData *)LODWORD(this->Top);
  sequence = *(struct GASObject **)(LODWORD(this->Right) + 8);
  hData = Top_low[25].hData;
  DisplayWidthCm = Top_low[15].pRenderer[16].S3DParams.DisplayWidthCm;
  Left = this->Left;
  *((_DWORD *)this + 10) = hData;
  v9 = *(_BYTE *)(LODWORD(Left) + 106);
  v117 = sequence;
  if ( v9 == 2 || v9 == 1 )
  {
    NewLocalFrame = GASEnvironment::CreateNewLocalFrame(this: Top_low);
    v13 = (int)NewLocalFrame;
    if ( NewLocalFrame != nullptr )
      *(_DWORD *)&NewLocalFrame->rgbReserved[4] = (*(_DWORD *)&NewLocalFrame->rgbReserved[4] + 1) & 0x8FFFFFFF;
    v14 = *((_DWORD *)this + 9);
    if ( v14 != 0 )
      GRefCountBaseGC<323>::Release(a1: v14, a2: (int)NewLocalFrame);
    *((_DWORD *)this + 9) = v13;
    Bottom = this->Bottom;
    if ( Bottom != 0.0 )
      *(_DWORD *)(LODWORD(Bottom) + 8) = (*(_DWORD *)(LODWORD(Bottom) + 8) + 1) & 0x8FFFFFFF;
    v16 = *(_DWORD *)(v13 + 20);
    if ( v16 != 0 )
      GRefCountBaseGC<323>::Release(a1: v16, a2: v13);
    *(float *)(v13 + 20) = Bottom;
    sequence = v117;
  }
  else
  {
    v10 = Top_low + 25;
    GArrayDataBase<GPtr<GASObject>,GAllocatorLH<GPtr<GASObject>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: Top_low + 25,
      pheapAddr: (ButtonCode_t)&Top_low[25],
      newSize: (unsigned int)Top_low[25].hData + 1);
    v11 = v10->hData;
    if ( (GRenderer *)((char *)v10->pRenderer + 4 * (_DWORD)v11) != (GRenderer *)4 )
      *((_DWORD *)v10->pRenderer + (_DWORD)v11 - 1) = 0;
  }
  ArgsToPass = (int)sequence;
  if ( sequence != nullptr )
  {
    v17 = GASObjectInterface::ToASCharacter(this: (GASObjectInterface *)sequence);
    v18 = v17;
    if ( v17 != nullptr )
      ++*((_DWORD *)v17 + 1);
    v19 = *((GRefCountNTSImpl **)this + 7);
    if ( v19 != nullptr )
      GRefCountNTSImpl::Release(this: v19);
    *((_DWORD *)this + 7) = v18;
    v20 = GASObjectInterface::ToASObject(result: v94);
    v21 = v20;
    if ( v20 != nullptr )
      v20->Policy[0].TimeCheck = (v20->Policy[0].TimeCheck + 1) & 0x8FFFFFFF;
    v22 = *((_DWORD *)this + 8);
    if ( v22 != 0 )
      GRefCountBaseGC<323>::Release(a1: v22, a2: (int)v20);
    *((_DWORD *)this + 8) = v21;
    if ( ((unsigned __int8 (__thiscall *)(struct GASObject *))sequence->pNode[7].elem)(a1: sequence) != 0 )
    {
      sequence = (struct GASObject *)sequence[5].sequence;
      v117 = sequence;
    }
  }
  v23 = this->Top;
  if ( *(_BYTE *)(LODWORD(this->Left) + 106) == 2 )
  {
    v39 = *(_DWORD *)(LODWORD(v23) + 108) + *(unsigned __int8 *)(LODWORD(this->Left) + 107);
    v40 = (unsigned int *)(LODWORD(v23) + 104);
    v115 = *(struct GASObject **)(LODWORD(v23) + 108);
    GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v40,
      pheapAddr: (ButtonCode_t)v40,
      newSize: v39);
    if ( v39 > (unsigned int)v115 )
    {
      v41 = (_BYTE *)(*v40 + 16 * (_DWORD)v115);
      for ( i = v39 - (_DWORD)v115; i != 0; --i )
      {
        if ( v41 != nullptr )
          *v41 = 0;
        v41 += 16;
      }
    }
    v43 = *(_DWORD *)(LODWORD(this->Left) + 88);
    CurrentReg = *(_DWORD *)(LODWORD(this->Right) + 28);
    if ( CurrentReg >= v43 )
      CurrentReg = v43;
    for ( j = 0; j < CurrentReg; ++j )
    {
      v45 = *(_DWORD *)(LODWORD(this->Left) + 84);
      v46 = *(struct GASObject **)(v45 + 8 * j);
      v47 = v45 + 8 * j;
      Right = this->Right;
      v115 = v46;
      if ( v46 != nullptr )
      {
        v87 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(Right), a2: j);
        GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(this->Top), reg: (unsigned int)v115);
        GASValue::operator=(v: v87);
      }
      else
      {
        v49 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(Right), a2: j);
        GASEnvironment::AddLocal(
          this: (GASEnvironment *)LODWORD(this->Top),
          a2: j,
          varname: (_IMAGE_SYMBOL_EX *)(v47 + 4),
          val: v49);
      }
    }
    for ( k = *(_DWORD *)(LODWORD(this->Left) + 88); j < k; ++j )
    {
      v51 = *(_DWORD *)(LODWORD(this->Left) + 84);
      if ( *(_DWORD *)(v51 + 8 * j) == 0 )
      {
        v86 = (_IMAGE_SYMBOL_EX *)(v51 + 8 * j + 4);
        v52 = this->Top;
        LOBYTE(v98.lpszMenuName) = 0;
        GASEnvironment::AddLocal(
          this: (GASEnvironment *)LODWORD(v52),
          a2: j,
          varname: v86,
          val: (tagWNDCLASSW *)&v98.lpszMenuName);
        GASValue::~GASValue(this: (GASValue *)&v98.lpszMenuName);
      }
    }
    v53 = *(_WORD *)(LODWORD(this->Left) + 104);
    v115 = nullptr;
    if ( (v53 & 0x10) == 0 && (v53 & 0x20) != 0 )
      goto LABEL_100;
    v54 = *(_DWORD *)(ArgsToPass + 8);
    if ( v54 != 0 )
      *(_DWORD *)(v54 + 8) = (*(_DWORD *)(v54 + 8) + 1) & 0x8FFFFFFF;
    v55 = v54;
    CurrentReg = v54;
    if ( v54 != 0 )
    {
      if ( *((_DWORD *)this + 4) != 0 )
      {
        GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(LODWORD(this->Top) + 120) + 636));
        v112 = v56;
        ++*(_DWORD *)(v56 + 8);
        Owner = GASObjectInterface::FindOwner(result: (_JOB_SET_ARRAY *)(LODWORD(this->Top) + 120));
        v58 = (int)Owner;
        if ( Owner != nullptr )
          Owner->Flags = (Owner->Flags + 1) & 0x8FFFFFFF;
        v59 = (*(_DWORD *)(v112 + 8))-- == 1;
        if ( v59 )
          GASStringNode::ReleaseNode();
        if ( v58 != 0 )
        {
          *(_DWORD *)(v58 + 8) = (*(_DWORD *)(v58 + 8) + 1) & 0x8FFFFFFF;
          GRefCountBaseGC<323>::Release(a1: v54, a2: v58);
          CurrentReg = v58;
          GRefCountBaseGC<323>::Release(a1: v58, a2: v58);
        }
        v55 = CurrentReg;
      }
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)(v55 + 16) + 56))(
        a1: v55 + 16,
        a2: &v107,
        a3: LODWORD(this->Top) + 120);
      v60 = DisplayWidthCm;
      v61 = *(int (__thiscall **)(_DWORD, int, struct GASObject **))(*(_DWORD *)LODWORD(DisplayWidthCm) + 40);
      v115 = (struct GASObject *)323;
      v62 = (CBitWrite *)v61(a1: LODWORD(DisplayWidthCm), a2: 76, a3: &v115);
      if ( v62 != nullptr )
        v63 = GASSuperObject::GASSuperObject(this: v62, a2: *(_DWORD *)(v55 + 24), _this: (int)v117, _this_4: &v107);
      else
        v63 = nullptr;
      v115 = (struct GASObject *)v63;
      if ( (v109 & 2) == 0 && v107 != 0 )
        GRefCountBaseGC<323>::Release(a1: v107, a2: v55);
      v107 = 0;
      if ( (v109 & 1) == 0 && v108 != 0 )
        GRefCountBaseGC<323>::Release(a1: v108, a2: v55);
      v108 = 0;
      GRefCountBaseGC<323>::Release(a1: v55, a2: v55);
    }
    else
    {
LABEL_100:
      v60 = DisplayWidthCm;
    }
    v59 = (*(_BYTE *)(LODWORD(this->Left) + 104) & 1) == 0;
    v64 = 1;
    CurrentReg = 1;
    if ( !v59 )
    {
      v65 = this->Top;
      if ( v117 != nullptr )
      {
        v88 = v117;
        v66 = GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(v65), reg: 1u);
        GASValue::SetAsObjectInterface(this: (GASValue *)v66, a2: (struct GASObjectInterface *)v88);
      }
      else
      {
        v67 = GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(v65), reg: 1u);
        GASValue::DropRefs(this: (GASValue *)v67);
        *(_BYTE *)v67 = 0;
      }
      CurrentReg = 2;
      v64 = 2;
    }
    if ( (*(_BYTE *)(LODWORD(this->Left) + 104) & 2) == 0 )
    {
      LOBYTE(pthisVal) = 0;
      if ( v117 != nullptr )
        GASValue::SetAsObjectInterface(this: &pthisVal, a2: (struct GASObjectInterface *)v117);
      GASEnvironment::AddLocal(
        this: (GASEnvironment *)LODWORD(this->Top),
        a2: v64,
        varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(this->Top) + 120) + 252),
        val: (tagWNDCLASSW *)&pthisVal);
      GASValue::~GASValue(this: &pthisVal);
    }
    v68 = *(_WORD *)(LODWORD(this->Left) + 104);
    v117 = nullptr;
    if ( (v68 & 4) != 0 || (v68 & 8) == 0 )
    {
      v69 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(v60) + 40);
      v106 = 323;
      if ( v69(a1: LODWORD(v60), a2: 76, a3: &v106) != 0 )
        v70 = (struct GASObject *)GASArrayObject::GASArrayObject(
                                    penv: LODWORD(this->Top),
                                    a2: (GMemoryHeap *)v94,
                                    a3: v95,
                                    a4: v96);
      else
        v70 = nullptr;
      v89 = *(void **)(LODWORD(this->Right) + 28);
      v117 = v70;
      GASArrayObject::Resize(size: v89, a2: (GMemoryHeap *)v94);
      for ( m = 0; m < *(_DWORD *)(LODWORD(this->Right) + 28); ++m )
      {
        v72 = GASFnCall::Arg(this: (GASFnCall *)LODWORD(this->Right), a2: m);
        GASArrayObject::SetElement(this: (GASArrayObject *)v70, a2: m, a3: v72);
      }
      v64 = CurrentReg;
    }
    if ( (*(_BYTE *)(LODWORD(this->Left) + 104) & 4) != 0 )
    {
      v90 = v117;
      v73 = GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(this->Top), reg: v64);
      GASValue::SetAsObject(this: (GASValue *)v73, a2: v90);
      CurrentReg = ++v64;
    }
    if ( (*(_BYTE *)(LODWORD(this->Left) + 104) & 8) == 0 )
    {
      v74 = *(_IMAGE_SYMBOL_EX **)(LODWORD(this->Top) + 120);
      v75 = (tagWNDCLASSW *)GASValue::GASValue(this: v97, a2: v117);
      GASEnvironment::AddLocal(
        this: (GASEnvironment *)LODWORD(this->Top),
        a2: (int)&v74[14],
        varname: v74 + 14,
        val: v75);
      GASValue::~GASValue(this: v97);
      v76 = this->Top;
      v77 = v117;
      v113 = 7;
      v78 = 32 * (*(_DWORD *)(LODWORD(v76) + 148) - 1)
          + ((*(_DWORD *)(LODWORD(v76) + 128) - *(_DWORD *)(LODWORD(v76) + 132)) >> 2);
      GASValue::GASValue(
        this: (GASValue *)&v98.hInstance,
        a2: *(struct GASObject **)(*(_DWORD *)(*(_DWORD *)(LODWORD(v76) + 144) + 4 * (v78 >> 5)) + 4 * (v78 & 0x1F)));
      ((void (__thiscall *)(struct GASObject *, int, int, HINSTANCE__ **, char *))v77[2].pNode[5].pNext)(
        a1: &v77[2],
        a2: LODWORD(this->Top) + 120,
        a3: *(_DWORD *)(LODWORD(this->Top) + 120) + 284,
        a4: &v98.hInstance,
        a5: &v113);
      GASValue::~GASValue(this: (GASValue *)&v98.hInstance);
      v79 = this->Top;
      v114 = 7;
      v80 = 32 * (*(_DWORD *)(LODWORD(v79) + 148) - 1)
          + ((*(_DWORD *)(LODWORD(v79) + 128) - *(_DWORD *)(LODWORD(v79) + 132)) >> 2);
      if ( v80 != 0 )
        GASValue::GASValue(
          this: v103,
          a2: *(struct GASObject **)(*(_DWORD *)(*(_DWORD *)(LODWORD(v79) + 144) + 4 * ((unsigned int)(v80 - 1) >> 5))
                               + 4 * ((v80 - 1) & 0x1F)));
      else
        LOBYTE(v103[0]) = 1;
      ((void (__thiscall *)(struct GASObject *, int, int, GASValue *, char *))v77[2].pNode[5].pNext)(
        a1: &v77[2],
        a2: LODWORD(this->Top) + 120,
        a3: *(_DWORD *)(LODWORD(this->Top) + 120) + 288,
        a4: v103,
        a5: &v114);
      GASValue::~GASValue(this: v103);
      v64 = CurrentReg;
    }
    v81 = v115;
    if ( (*(_BYTE *)(LODWORD(this->Left) + 104) & 0x10) != 0 )
    {
      v91 = v115;
      v82 = GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(this->Top), reg: v64);
      GASValue::SetAsObject(this: (GASValue *)v82, a2: v91);
      ++v64;
    }
    if ( (*(_BYTE *)(LODWORD(this->Left) + 104) & 0x20) == 0 )
    {
      LOBYTE(superVal) = 0;
      GASValue::SetAsObject(this: &superVal, a2: v81);
      GASEnvironment::AddLocal(
        this: (GASEnvironment *)LODWORD(this->Top),
        a2: v64,
        varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(this->Top) + 120) + 256),
        val: (tagWNDCLASSW *)&superVal);
      GASValue::~GASValue(this: &superVal);
    }
    if ( (*(_BYTE *)(LODWORD(this->Left) + 104) & 0x40) != 0 )
    {
      v92 = (tagBITMAPCOREHEADER *)(*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(LODWORD(this->Top) + 116) + 104))(
                                     a1: *(_DWORD *)(LODWORD(this->Top) + 116),
                                     a2: 0);
      GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(this->Top), reg: v64);
      GASValue::SetAsCharacter(result: v92);
      ++v64;
    }
    if ( *(char *)(LODWORD(this->Left) + 104) < 0 )
    {
      v83 = this->Top;
      LOBYTE(parent) = 0;
      GASEnvironment::GetVariable(
        this: (__vc_attributes::max_isAttribute *)LODWORD(v83),
        varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(v83) + 120) + 268),
        a3: &parent,
        retVal: 0,
        paschar: nullptr,
        a6: nullptr,
        a7: 0);
      GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(this->Top), reg: v64);
      GASValue::operator=(v: (tagWNDCLASSW *)&parent);
      ++v64;
      GASValue::~GASValue(this: &parent);
    }
    if ( (*(_WORD *)(LODWORD(this->Left) + 104) & 0x100) != 0 )
    {
      v84 = this->Top;
      v93 = *(struct GASObject **)(*(_DWORD *)(LODWORD(v84) + 120) + 680);
      v85 = GASEnvironment::LocalRegisterPtr(this: (GASEnvironment *)LODWORD(v84), reg: v64);
      GASValue::SetAsObject(this: (GASValue *)v85, a2: v93);
    }
    if ( v117 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v117, a2: v64);
    if ( v81 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v81, a2: v64);
  }
  else
  {
    v24 = *(unsigned __int8 *)(LODWORD(v23) + 124);
    if ( sequence != nullptr )
    {
      LOBYTE(thisVal) = 0;
      GASValue::SetAsObjectInterface(this: &thisVal, a2: (struct GASObjectInterface *)sequence);
      GASEnvironment::AddLocal(
        this: (GASEnvironment *)LODWORD(this->Top),
        a2: v24,
        varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(this->Top) + 120) + 252),
        val: (tagWNDCLASSW *)&thisVal);
      GASValue::~GASValue(this: &thisVal);
    }
    if ( v24 >= 6 )
    {
      v25 = *((_DWORD *)this + 9);
      if ( v25 != 0 )
        *(_DWORD *)(v25 + 24) = ArgsToPass;
    }
    if ( *((_DWORD *)this + 9) != 0 )
    {
      v26 = *(_DWORD *)(LODWORD(this->Right) + 24);
      if ( v26 != 0 && v24 >= 5 )
      {
        if ( LODWORD(this->Top) != v26 )
        {
          v27 = *(_DWORD *)(v26 + 116);
          if ( v27 != 0 )
            ++*(_DWORD *)(v27 + 4);
          v28 = *((GRefCountNTSImpl **)this + 6);
          if ( v28 != nullptr )
            GRefCountNTSImpl::Release(this: v28);
          *((_DWORD *)this + 6) = v27;
        }
        *(_DWORD *)(*((_DWORD *)this + 9) + 28) = *(_DWORD *)(LODWORD(this->Right) + 24);
        *(_DWORD *)(*((_DWORD *)this + 9) + 32) = *(_DWORD *)(LODWORD(this->Right) + 28);
        *(_DWORD *)(*((_DWORD *)this + 9) + 36) = *(_DWORD *)(LODWORD(this->Right) + 32);
        v29 = this->Top;
        v30 = 32 * (*(_DWORD *)(LODWORD(v29) + 148) - 1)
            + ((*(_DWORD *)(LODWORD(v29) + 128) - *(_DWORD *)(LODWORD(v29) + 132)) >> 2);
        GASValue::GASValue(
          this: v99,
          a2: *(struct GASObject **)(*(_DWORD *)(*(_DWORD *)(LODWORD(v29) + 144) + 4 * (v30 >> 5)) + 4 * (v30 & 0x1F)));
        GASValue::operator=(v: (tagWNDCLASSW *)v99);
        GASValue::~GASValue(this: v99);
        v31 = this->Top;
        v32 = ((*(_DWORD *)(LODWORD(v31) + 128) - *(_DWORD *)(LODWORD(v31) + 132)) >> 2)
            + 32 * (*(_DWORD *)(LODWORD(v31) + 148) - 1);
        if ( v32 != 0 )
          GASValue::GASValue(
            this: v100,
            a2: *(struct GASObject **)(*(_DWORD *)(*(_DWORD *)(LODWORD(v31) + 144) + 4 * ((unsigned int)(v32 - 1) >> 5))
                                 + 4 * ((v32 - 1) & 0x1F)));
        else
          LOBYTE(v100[0]) = 1;
        GASValue::operator=(v: (tagWNDCLASSW *)v100);
        GASValue::~GASValue(this: v100);
      }
    }
    v33 = *(struct GASObject **)(LODWORD(this->Left) + 88);
    v117 = *(struct GASObject **)(LODWORD(this->Right) + 28);
    if ( (int)v117 >= (int)v33 )
      v117 = v33;
    for ( n = 0; n < (int)v117; ++n )
    {
      v35 = (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(this->Left) + 84) + 8 * n + 4);
      v36 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(this->Right), a2: n);
      GASEnvironment::AddLocal(this: (GASEnvironment *)LODWORD(this->Top), a2: n, varname: v35, val: v36);
    }
    for ( ii = *(_DWORD *)(LODWORD(this->Left) + 88); n < ii; ++n )
    {
      v38 = this->Left;
      LOBYTE(v98.style) = 0;
      GASEnvironment::AddLocal(
        this: (GASEnvironment *)LODWORD(this->Top),
        a2: n,
        varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(v38) + 84) + 8 * n + 4),
        val: &v98);
      GASValue::~GASValue(this: (GASValue *)&v98);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD1D0
// Name: public: void InvokeContext::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InvokeContext::Cleanup(GRect<float> *this@<ecx>, int a2@<edi>)
{
  GRect<float> *v2; // ebx
  int v3; // eax
  int v4; // esi
  float Top; // ecx
  float v6; // ecx
  float v7; // esi
  unsigned int v8; // eax
  unsigned int Right_low; // edi
  GRenderer::CachedData *v10; // esi
  unsigned int v11; // edi
  GRenderer_vtbl **i; // eax
  float Left; // eax
  float v14; // edi
  unsigned int v15; // ebx
  unsigned int v16; // esi
  unsigned int *v17; // edi
  _BYTE *v18; // eax
  int j; // esi
  __vc_attributes::atl::aggregatesAttribute *Top_low; // ebx
  int v21; // ecx
  GASValue v23[4]; // [esp+8h] [ebp-18h] BYREF
  unsigned int v24; // [esp+18h] [ebp-8h]
  GRect<float> *v25; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v3 = *((_DWORD *)this + 8);
  v25 = this;
  if ( v3 != 0 )
  {
    v4 = v3 + 16;
    if ( v3 != -16 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 60))(a1: v4) != 0 )
      GASSuperObject::ResetAltProto(this: (GASSuperObject *)(v4 - 16), a2);
  }
  if ( *(_BYTE *)(LODWORD(v2->Left) + 106) != 2 || (*(_BYTE *)(LODWORD(v2->Left) + 104) & 2) == 0 )
  {
    Top = v2->Top;
    LOBYTE(v23[0]) = 0;
    GASEnvironment::SetLocal(
      this: (GASEnvironment *)LODWORD(Top),
      varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(Top) + 120) + 252),
      val: (tagWNDCLASSW *)v23);
    GASValue::~GASValue(this: v23);
  }
  if ( *(_BYTE *)(LODWORD(v2->Left) + 106) != 2 || (*(_BYTE *)(LODWORD(v2->Left) + 104) & 0x20) == 0 )
  {
    v6 = v2->Top;
    LOBYTE(v23[0]) = 0;
    GASEnvironment::SetLocal(
      this: (GASEnvironment *)LODWORD(v6),
      varname: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(LODWORD(v6) + 120) + 256),
      val: (tagWNDCLASSW *)v23);
    GASValue::~GASValue(this: v23);
  }
  if ( LODWORD(v2[2].Top) != 0 )
    CDummyMaterialSystem::EndBatch();
  v7 = v2->Top;
  v8 = *(_DWORD *)(LODWORD(v7) + 204);
  Right_low = LODWORD(v2[2].Right);
  v10 = (GRenderer::CachedData *)(LODWORD(v7) + 200);
  v24 = v8;
  GArrayDataBase<GPtr<GASObject>,GAllocatorLH<GPtr<GASObject>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: v10,
    pheapAddr: (ButtonCode_t)v10,
    newSize: Right_low);
  if ( Right_low > v24 )
  {
    v11 = Right_low - v24;
    for ( i = &v10->pRenderer->__vftable + v24; v11 != 0; --v11 )
    {
      if ( i != nullptr )
        *i = nullptr;
      ++i;
    }
  }
  Left = v2->Left;
  if ( *(_BYTE *)(LODWORD(v2->Left) + 106) == 2 )
  {
    v14 = v2->Top;
    v15 = *(_DWORD *)(LODWORD(v14) + 108);
    v16 = v15 - *(unsigned __int8 *)(LODWORD(Left) + 107);
    v17 = (unsigned int *)(LODWORD(v14) + 104);
    GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v17,
      pheapAddr: (ButtonCode_t)v17,
      newSize: v16);
    if ( v16 > v15 )
    {
      v18 = (_BYTE *)(*v17 + 16 * v15);
      for ( j = v16 - v15; j != 0; --j )
      {
        if ( v18 != nullptr )
          *v18 = 0;
        v18 += 16;
      }
    }
    v2 = v25;
  }
  Top_low = (__vc_attributes::atl::aggregatesAttribute *)LODWORD(v2->Top);
  if ( Top_low != nullptr )
  {
    v21 = *(_DWORD *)Top_low[32].clsid;
    if ( v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: v21, a2);
    Top_low[32].clsid -= 4;
    if ( Top_low[32].clsid < Top_low[33].clsid )
      GASPagedStack<GPtr<GASFunctionObject>,32>::PopPage(this: Top_low + 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD340
// Name: public: virtual void GASAsFunctionObject::Invoke(class GASFnCall const __near &,class GASLocalFrame __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASAsFunctionObject::Invoke(GSize<float> *this, GSize<float> *result, float fn, float localFrame)
{
  int (__stdcall *v5)(GSize<float> *, GRefCountNTSImpl **); // edx
  float Width; // eax
  unsigned __int16 v7; // cx
  GRect<float> ctxt; // [esp+8h] [ebp-2Ch] BYREF
  float v9; // [esp+18h] [ebp-1Ch]
  GRefCountNTSImpl *v10; // [esp+1Ch] [ebp-18h] BYREF
  GRefCountNTSImpl *v11; // [esp+20h] [ebp-14h]
  GRefCountNTSImpl *v12; // [esp+24h] [ebp-10h]
  int v13; // [esp+28h] [ebp-Ch]
  int v14; // [esp+2Ch] [ebp-8h]

  ctxt.Bottom = fn;
  v5 = *(int (__stdcall **)(GSize<float> *, GRefCountNTSImpl **))(LODWORD(this->Width) + 36);
  v10 = nullptr;
  v11 = nullptr;
  v12 = nullptr;
  v13 = 0;
  v14 = 0;
  v9 = localFrame;
  LODWORD(ctxt.Left) = this;
  LODWORD(ctxt.Right) = result;
  Width = COERCE_FLOAT(v5(a1: result, a2: &v10));
  ctxt.Top = Width;
  if ( (*(_BYTE *)(*(_DWORD *)(LODWORD(Width) + 116) + 118) & 0x10) != 0 )
  {
    Width = result[3].Width;
    ctxt.Top = Width;
  }
  v7 = *(_WORD *)(LODWORD(Width) + 196);
  *(_WORD *)(LODWORD(Width) + 196) = v7 + 1;
  if ( v7 < 0xFFu )
  {
    InvokeContext::Setup(this: &ctxt);
    GASActionBuffer::Execute(
      this: *((_DWORD *)this + 15),
      result: (tagPOLYTEXTW *)LODWORD(ctxt.Top),
      startPc: *((char **)this + 19),
      execBytes: *((_DWORD *)this + 20),
      a5: (char *)LODWORD(result->Height),
      pinitialWithStack: (int)(this + 8),
      pinitialWithStack_4: *((unsigned __int8 *)this + 106));
    InvokeContext::Cleanup(this: &ctxt, a2: (int)result);
    --*(_WORD *)(LODWORD(ctxt.Top) + 196);
  }
  else
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(ctxt.Top) + 4))(a1: LODWORD(ctxt.Top)) != 0 )
      GASEnvironment::LogScriptError(
        this: (GASEnvironment *)LODWORD(ctxt.Top),
        a2: "Error: Stack overflow, max level of 255 nested calls is reached.\n");
    --*(_WORD *)(LODWORD(ctxt.Top) + 196);
  }
  if ( v14 != 0 )
    GRefCountBaseGC<323>::Release(a1: v14, a2: (int)result);
  if ( v13 != 0 )
    GRefCountBaseGC<323>::Release(a1: v13, a2: (int)result);
  if ( v12 != nullptr )
    GRefCountNTSImpl::Release(this: v12);
  if ( v11 != nullptr )
    GRefCountNTSImpl::Release(this: v11);
  if ( v10 != nullptr )
    GRefCountNTSImpl::Release(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100B70E0
// Name: public: GASPagedStack<class GASValue,32>::GASPagedStack<class GASValue,32>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GASValue,32>::GASPagedStack<GASValue,32>(__vc_attributes::progidAttribute *this)
{
  GRenderer::CachedData *v2; // esi
  const char *v3; // eax
  bool v4; // cf
  GRenderer *v5; // eax
  unsigned int hData; // ecx
  unsigned int v7; // ebx
  GRenderer *pRenderer; // ecx
  const char **v9; // ebx
  int v10; // [esp+Ch] [ebp-8h] BYREF
  int v11; // [esp+10h] [ebp-4h] BYREF

  v2 = (GRenderer::CachedData *)(this + 4);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  v11 = 2;
  v3 = (const char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 516, a4: &v11);
  v4 = v2[1].pRenderer < (GRenderer *)0xF;
  v11 = (int)v3;
  if ( v4 )
  {
    if ( v2->pRenderer != nullptr )
    {
      v5 = (GRenderer *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v2->pRenderer, a3: 64);
    }
    else
    {
      v10 = 2;
      v5 = (GRenderer *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 64, a4: &v10);
    }
    v2->pRenderer = v5;
    v3 = (const char *)v11;
    v2[1].pRenderer = (GRenderer *)16;
  }
  hData = (unsigned int)v2->hData;
  v7 = hData + 1;
  if ( hData + 1 >= hData )
  {
    if ( (GRenderer *)v7 < v2[1].pRenderer )
      goto LABEL_12;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v2,
      pheapAddr: v2,
      newCapacity: v7 + (v7 >> 2));
  }
  else
  {
    if ( v7 >= (unsigned int)v2[1].pRenderer >> 1 )
      goto LABEL_12;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v2,
      pheapAddr: v2,
      newCapacity: v7);
  }
  v3 = (const char *)v11;
LABEL_12:
  pRenderer = v2->pRenderer;
  v2->hData = (void *)v7;
  v9 = (const char **)((char *)pRenderer + 4 * v7 - 4);
  if ( v9 != nullptr )
    *v9 = v3;
  *((_DWORD *)this + 1) = v3;
  *((_DWORD *)this + 2) = v3 + 512;
  this->name = v3;
  *((_DWORD *)this + 3) = v3;
  if ( v3 != nullptr )
    *v3 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B71C0
// Name: public: GASPagedStack<class GPtr<class GASFunctionObject>,32>::GASPagedStack<class GPtr<class GASFunctionObject>,32>(void)
// Source: json
//------------------------------------------------------------------------------
GRenderer::CachedData *__thiscall GASPagedStack<GPtr<GASFunctionObject>,32>::GASPagedStack<GPtr<GASFunctionObject>,32>(
        GRenderer::CachedData *this)
{
  GRenderer::CachedData *v2; // esi
  GRenderer *v3; // eax
  bool v4; // cf
  GRenderer *v5; // eax
  unsigned int hData; // ecx
  unsigned int v7; // ebx
  GRenderer *pRenderer; // ecx
  GRenderer *v9; // ebx
  int v11; // [esp+Ch] [ebp-8h] BYREF
  int v12; // [esp+10h] [ebp-4h] BYREF

  v2 = this + 2;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  v12 = 2;
  v3 = (GRenderer *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 132, a4: &v12);
  v4 = v2[1].pRenderer < (GRenderer *)0xF;
  v12 = (int)v3;
  if ( v4 )
  {
    if ( v2->pRenderer != nullptr )
    {
      v5 = (GRenderer *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v2->pRenderer, a3: 64);
    }
    else
    {
      v11 = 2;
      v5 = (GRenderer *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 64, a4: &v11);
    }
    v2->pRenderer = v5;
    v3 = (GRenderer *)v12;
    v2[1].pRenderer = (GRenderer *)16;
  }
  hData = (unsigned int)v2->hData;
  v7 = hData + 1;
  if ( hData + 1 >= hData )
  {
    if ( (GRenderer *)v7 < v2[1].pRenderer )
      goto LABEL_12;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v2,
      pheapAddr: v2,
      newCapacity: v7 + (v7 >> 2));
  }
  else
  {
    if ( v7 >= (unsigned int)v2[1].pRenderer >> 1 )
      goto LABEL_12;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v2,
      pheapAddr: v2,
      newCapacity: v7);
  }
  v3 = (GRenderer *)v12;
LABEL_12:
  pRenderer = v2->pRenderer;
  v2->hData = (void *)v7;
  v9 = (GRenderer *)((char *)pRenderer + 4 * v7 - 4);
  if ( v9 != nullptr )
    v9->__vftable = (GRenderer_vtbl *)v3;
  this->hData = v3;
  *((_DWORD *)this + 2) = (char *)v3 + 128;
  this->pRenderer = v3;
  *((_DWORD *)this + 3) = v3;
  if ( v3 != nullptr )
    v3->__vftable = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B8510
// Name: public: GASPagedStack<class GASValue,32>::~GASPagedStack<class GASValue,32>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GASValue,32>::~GASPagedStack<GASValue,32>(__vc_attributes::iid_isAttribute *this)
{
  int i; // edi
  __vc_attributes::iid_isAttribute *v3; // eax
  int v4; // edi

  for ( i = 32 * (*((_DWORD *)this + 5) - 1) + ((int)&this->limited_expression[-*((_DWORD *)this + 1)] >> 4); i != 0; --i )
  {
    GASValue::~GASValue(this: (GASValue *)this->limited_expression);
    this->limited_expression -= 16;
    if ( this->limited_expression < (const char *)*((_DWORD *)this + 1) )
      GASPagedStack<GASValue,32>::PopPage(this);
  }
  GASValue::~GASValue(this: (GASValue *)this->limited_expression);
  v3 = *(__vc_attributes::iid_isAttribute **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
  v3[128].limited_expression = (const char *)*(this + 7);
  *((_DWORD *)this + 7) = v3;
  do
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 7) + 512);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 7));
    *((_DWORD *)this + 7) = v4;
  }
  while ( v4 != 0 );
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x100B85A0
// Name: public: GASPagedStack<class GPtr<class GASFunctionObject>,32>::~GASPagedStack<class GPtr<class GASFunctionObject>,32>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPagedStack<GPtr<GASFunctionObject>,32>::~GASPagedStack<GPtr<GASFunctionObject>,32>(
        __vc_attributes::atl::aggregatesAttribute *this)
{
  int i; // edi
  int v3; // ecx
  int v4; // ecx
  __vc_attributes::atl::aggregatesAttribute *v5; // eax
  int v6; // edi

  for ( i = 32 * (*((_DWORD *)this + 5) - 1) + ((int)&this->clsid[-*((_DWORD *)this + 1)] >> 2); i != 0; --i )
  {
    v3 = *(_DWORD *)this->clsid;
    if ( v3 != 0 )
      GRefCountBaseGC<323>::Release(a1: v3, a2: i);
    this->clsid -= 4;
    if ( this->clsid < (const char *)*((_DWORD *)this + 1) )
      GASPagedStack<GPtr<GASFunctionObject>,32>::PopPage(this);
  }
  v4 = *(_DWORD *)this->clsid;
  if ( v4 != 0 )
    GRefCountBaseGC<323>::Release(a1: v4, a2: i);
  v5 = *(__vc_attributes::atl::aggregatesAttribute **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
  v5[32].clsid = (const char *)*(this + 7);
  *((_DWORD *)this + 7) = v5;
  do
  {
    v6 = *(_DWORD *)(*((_DWORD *)this + 7) + 128);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 7));
    *((_DWORD *)this + 7) = v6;
  }
  while ( v6 != 0 );
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x10096200
// Name: unsigned int G_Format<class GStringDataPtr,char const __near *>(class GMsgFormat::Sink const __near &,char const __near *,class GStringDataPtr const __near &,char const __near * const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl G_Format<GStringDataPtr,char const *>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        int a3,
        CMatQueuedRenderContext::CCallQueueExternal *v)
{
  int m_nGrowSize; // esi
  unsigned __int16 v6; // [esp+0h] [ebp-310h]
  unsigned __int16 v7; // [esp+0h] [ebp-310h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v8[27]; // [esp+Ch] [ebp-304h] BYREF

  GMsgFormat::GMsgFormat(this: (GMsgFormat *)v8, a2: a1);
  GMsgFormat::Parse(result: a2);
  GMsgFormat::FormatD1<GStringDataPtr>(this: (int)v8, v: a3);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v8, v);
  GMsgFormat::FinishFormatD(this: v8, a2: v6);
  m_nGrowSize = v8[0].m_Elements.m_nGrowSize;
  GMsgFormat::~GMsgFormat(this: v8, data_size: v7);
  return m_nGrowSize;
}
