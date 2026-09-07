// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/grefcount.cpp
// Functions: 6
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\grefcount.h"

//------------------------------------------------------------------------------
// Address: 0x10064670
// Name: public: virtual GRefCountImplCore::~GRefCountImplCore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRefCountImplCore::~GRefCountImplCore(IShaderAPI *this)
{
  this->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10064680
// Name: public: void GRefCountNTSImpl::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRefCountNTSImpl::Release(GRefCountNTSImpl *this)
{
  if ( this->RefCount-- == 1 )
    ((void (__thiscall *)(GRefCountNTSImpl *, int))this->dtr_GRefCountImplCore)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100646A0
// Name: public: void GRefCountImpl::Release(void)
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__thiscall GRefCountImpl::Release(IShaderAPI *this)
{
  ShaderAPIOcclusionQuery_t__ *result; // eax

  result = (ShaderAPIOcclusionQuery_t__ *)(InterlockedExchangeAdd(Addend: (volatile LONG *)this + 1, Value: -1) - 1);
  if ( result == nullptr && this != nullptr )
    return ((ShaderAPIOcclusionQuery_t__ *(__thiscall *)(IShaderAPI *, int))this->CurrentTime)(a1: this, a2: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100646D0
// Name: public: virtual GRefCountWeakSupportImpl::~GRefCountWeakSupportImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRefCountWeakSupportImpl::~GRefCountWeakSupportImpl(GRefCountWeakSupportImpl *this)
{
  GWeakPtrProxy *pWeakProxy; // eax
  GWeakPtrProxy *v3; // eax

  pWeakProxy = this->pWeakProxy;
  this->__vftable = (GRefCountWeakSupportImpl_vtbl *)&GRefCountWeakSupportImpl::`vftable';
  if ( pWeakProxy != nullptr )
  {
    pWeakProxy->pObject = nullptr;
    v3 = this->pWeakProxy;
    if ( v3->RefCount-- == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  this->__vftable = (GRefCountWeakSupportImpl_vtbl *)&GRefCountImplCore::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10064710
// Name: public: class GWeakPtrProxy __near * GRefCountWeakSupportImpl::CreateWeakProxy(void)const
// Source: json
//------------------------------------------------------------------------------
struct GWeakPtrProxy *__thiscall GRefCountWeakSupportImpl::CreateWeakProxy(GRefCountWeakSupportImpl *this)
{
  struct GWeakPtrProxy *result; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( this->pWeakProxy != nullptr
    || ((v3 = 2,
         (result = (struct GWeakPtrProxy *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                             this: GMemory::pGlobalHeap,
                                             a2: this,
                                             a3: 8,
                                             a4: &v3)) == nullptr)
      ? (result = nullptr)
      : (struct GWeakPtrProxy *)(result->RefCount = 1, result->pObject = this),
        this->pWeakProxy = result,
        result != nullptr) )
  {
    ++this->pWeakProxy->RefCount;
    return this->pWeakProxy;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AD20
// Name: public: void GRefCountImpl::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRefCountImpl::AddRef(IShaderDevice *this)
{
  InterlockedExchangeAdd(Addend: (volatile LONG *)this + 1, Value: 1);
}
