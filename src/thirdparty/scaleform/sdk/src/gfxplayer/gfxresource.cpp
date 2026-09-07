// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxresource.cpp
// Functions: 26
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxresource.h"

//------------------------------------------------------------------------------
// Address: 0x100057E0
// Name: public: GFxResourceKey::GFxResourceKey(void)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall GFxResourceKey::GFxResourceKey(GFxValue *this)
{
  this->pObjectInterface = nullptr;
  this->Type = VT_Undefined;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A4E0
// Name: public: bool GFxResourceWeakLib::ResourceNode::operator==(class GFxResourceKey const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxResourceWeakLib::ResourceNode::operator==(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // eax
  char v3; // bl
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  _DWORD v8[2]; // [esp+4h] [ebp-8h] BYREF

  if ( *this != 0 )
  {
    v5 = *(this + 1);
    v6 = *(_DWORD *)(v5 + 20);
    v7 = v5 + 20;
    if ( v6 != 0 && *a2 != 0 )
      return (*(int (__thiscall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v6 + 20))(
               a1: v6,
               a2: *(_DWORD *)(v7 + 4),
               a3: a2);
    else
      return 0;
  }
  else
  {
    v2 = (_DWORD *)(*(int (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)*(this + 1) + 4))(a1: *(this + 1), a2: v8);
    if ( *v2 != 0 && *a2 != 0 )
      v3 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD *))(*(_DWORD *)*v2 + 20))(a1: *v2, a2: v2[1], a3: a2);
    else
      v3 = 0;
    if ( v8[0] != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v8[0] + 8))(a1: v8[0], a2: v8[1]);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A570
// Name: public: char const __near * GFxResourceLib::ResourceSlot::GetError(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxResourceLib::ResourceSlot::GetError(CUtlBinaryBlock *this)
{
  return (*((_DWORD *)this + 7) & 0xFFFFFFFC) + 8;
}

//------------------------------------------------------------------------------
// Address: 0x1006A580
// Name: public: unsigned int GFxResourceFileInfo::GetHashCode(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxResourceFileInfo::GetHashCode(GFxResourceFileInfo *this)
{
  return (unsigned int)GString::BernsteinHashFunction(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)this->ObjectId.Data4 & 0xFFFFFFFC) + 8))
       ^ this->FileId.LowPart;
}

//------------------------------------------------------------------------------
// Address: 0x1006A5B0
// Name: public: GFxResourceKey::GFxResourceKey(class GFxResourceKey::KeyInterface __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GFxResourceKey *__thiscall GFxResourceKey::GFxResourceKey(
        GFxResourceKey *this,
        struct GFxResourceKey::KeyInterface *a2,
        void *a3)
{
  if ( a2 != nullptr )
    a2->AddRef(this: a2, a2: a3);
  this->pKeyInterface = a2;
  this->hKeyData = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A5E0
// Name: public: GFxResourceKey::GFxResourceKey(class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxResourceKey *__thiscall GFxResourceKey::GFxResourceKey(GFxResourceKey *this, const struct GFxResourceKey *a2)
{
  if ( a2->pKeyInterface != nullptr )
    a2->pKeyInterface->AddRef(this: a2->pKeyInterface, a2: a2->hKeyData);
  *this = *a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A610
// Name: public: class GFxResourceKey __near & GFxResourceKey::operator=(class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceKey::operator=(IShaderDevice *this, IShaderDevice *src)
{
  if ( src->__vftable != nullptr )
    (*((void (__thiscall **)(IShaderDevice_vtbl *, IShaderDevice_vtbl *))src->ReleaseResources + 1))(
      a1: src->__vftable,
      a2: src[1].__vftable);
  if ( this->__vftable != nullptr )
    (*((void (__thiscall **)(IShaderDevice_vtbl *, _DWORD))this->ReleaseResources + 2))(
      a1: this->__vftable,
      a2: *((_DWORD *)this + 1));
  this->__vftable = src->__vftable;
  *(this + 1) = src[1];
}

//------------------------------------------------------------------------------
// Address: 0x1006A7B0
// Name: public: unsigned int GFxResourceWeakLib::ResourceNode::HashOp::operator()(struct GFxResourceWeakLib::ResourceNode const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __stdcall GFxResourceWeakLib::ResourceNode::HashOp::operator()(_DWORD *a1)
{
  char v1; // bl
  int *v2; // esi
  int v3; // esi
  int v4; // ecx
  int v5; // ecx
  int v6; // edi
  int v7; // esi
  int v8; // ebx
  _DWORD v10[2]; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h]

  v12 = 0;
  if ( *a1 != 0 )
  {
    v3 = a1[1];
    v4 = *(_DWORD *)(v3 + 20);
    v1 = 2;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 4))(a1: v4, a2: *(_DWORD *)(v3 + 24));
    v5 = *(_DWORD *)(v3 + 24);
    v11 = *(_DWORD *)(v3 + 20);
    v12 = v5;
    v2 = &v11;
  }
  else
  {
    v1 = 1;
    v2 = (int *)(*(int (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)a1[1] + 4))(a1: a1[1], a2: v10);
  }
  if ( *v2 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)*v2 + 4))(a1: *v2, a2: v2[1]);
  v6 = *v2;
  v7 = v2[1];
  if ( (v1 & 2) != 0 )
  {
    v1 &= ~2u;
    if ( v11 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 8))(a1: v11, a2: v12);
  }
  if ( (v1 & 1) != 0 && v10[0] != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v10[0] + 8))(a1: v10[0], a2: v10[1]);
  if ( v6 == 0 )
    return 0;
  v8 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 16))(a1: v6, a2: v7);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 8))(a1: v6, a2: v7);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1006A890
// Name: public: unsigned int GFxResourceId::GenerateIdString(char __near *,unsigned int,char)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceId::GenerateIdString(
        IVirtualMemorySection *this,
        char *pbuffer,
        unsigned int bufferSize,
        char suffixLetter)
{
  int v4; // eax
  void (__thiscall *v5)(_DWORD *); // eax
  const char *const *v6; // [esp+0h] [ebp-58h]
  int v7; // [esp+0h] [ebp-58h]
  _DWORD v8[5]; // [esp+4h] [ebp-54h] BYREF
  char v9; // [esp+1Ah] [ebp-3Eh]
  unsigned int v10; // [esp+20h] [ebp-38h]

  if ( suffixLetter != 0 )
  {
    *pbuffer = suffixLetter;
  }
  else
  {
    v4 = (int)this->__vftable & 0xFFF0000;
    if ( v4 == 327680 )
    {
      *pbuffer = 71;
    }
    else if ( v4 == 393216 || v4 == 589824 )
    {
      *pbuffer = 70;
    }
    else
    {
      *pbuffer = 73;
    }
  }
  GLongFormatter::GLongFormatter(v: (const char *const *)LOWORD(this->__vftable), a2: v6);
  v5 = *(void (__thiscall **)(_DWORD *))(v8[0] + 12);
  v9 |= 1u;
  v10 = v10 & 0xFFFFFFE0 | 0x10;
  v5(a1: v8);
  GDoubleFormatter::InitString(result: (type_info *)(pbuffer + 1));
  GLongFormatter::GetSize(this: (GLongFormatter *)v8);
  v8[3] = &GString::InitStruct::`vftable';
  GFormatter::~GFormatter(this: (CMeshReader *)v8, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD30
// Name: public: bool GFxResource::AddRef_NotZero(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxResource::AddRef_NotZero(IShaderDevice *this)
{
  LONG v1; // esi
  volatile LONG *v2; // edi

  v1 = *((_DWORD *)this + 1);
  v2 = (volatile LONG *)(this + 1);
  if ( v1 == 0 )
    return 0;
  while ( InterlockedCompareExchange(Destination: v2, Exchange: v1 + 1, Comperand: v1) != v1 )
  {
    v1 = *v2;
    if ( *v2 == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006ADF0
// Name: public: GFxResourceFileInfo::GFxResourceFileInfo(void)
// Source: json
//------------------------------------------------------------------------------
GFxResourceFileInfo *__thiscall GFxResourceFileInfo::GFxResourceFileInfo(GFxResourceFileInfo *this)
{
  this->dwSize = (unsigned int)&GRefCountImplCore::`vftable';
  this->Type = ObjectIdType;
  this->dwSize = (unsigned int)&GFxResourceFileInfo::`vftable';
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)this->ObjectId.Data4);
  this->FileId.LowPart = 1;
  this->FileId.HighPart = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006AE70
// Name: public: GFxResourceFileInfo::GFxResourceFileInfo(struct GFxResourceFileInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxResourceFileInfo *__thiscall GFxResourceFileInfo::GFxResourceFileInfo(
        GFxResourceFileInfo *this,
        _PROCESS_INFORMATION *src)
{
  this->dwSize = (unsigned int)&GRefCountImplCore::`vftable';
  this->Type = ObjectIdType;
  this->dwSize = (unsigned int)&GFxResourceFileInfo::`vftable';
  GString::GString(result: (CImagePacker *)&src[1]);
  this->FileId.QuadPart = *(_QWORD *)&src->dwProcessId;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006B130
// Name: public: void GFxResource::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResource::Release(IShaderDevice *this)
{
  int v2; // ecx

  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)this + 1, Value: -1) == 1 )
  {
    v2 = *((_DWORD *)this + 2);
    if ( v2 != 0 )
    {
      (*(void (__thiscall **)(int, IShaderDevice *))(*(_DWORD *)v2 + 4))(a1: v2, a2: this);
      *((_DWORD *)this + 2) = 0;
    }
    this->ReleaseResources(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B170
// Name: public: GFxResourceLib::ResourceSlot::ResourceSlot(class GFxResourceWeakLib __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceLib::ResourceSlot::ResourceSlot(CUtlBinaryBlock *this, IShaderDevice *plib, _DWORD *a3)
{
  IShaderAPI *m_nGrowSize; // ecx
  int v5; // ecx
  VertexShaderHandle_t__ *v6; // [esp+0h] [ebp-Ch]

  this->m_Memory.m_pMemory = (unsigned __int8 *)&GRefCountImplCore::`vftable';
  this->m_Memory.m_nAllocationCount = 1;
  this->m_Memory.m_pMemory = (unsigned __int8 *)&GFxResourceLib::ResourceSlot::`vftable';
  this->m_Memory.m_nGrowSize = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 28));
  GEvent::GEvent(this: nullptr, setInitially: nullptr);
  if ( plib != nullptr )
    GRefCountImpl::AddRef(this: plib, a2: v6);
  m_nGrowSize = (IShaderAPI *)this->m_Memory.m_nGrowSize;
  if ( m_nGrowSize != nullptr )
    GRefCountImpl::Release(this: m_nGrowSize);
  this->m_Memory.m_nGrowSize = (int)plib;
  this->m_nActualLength = 0;
  *((_DWORD *)this + 4) = 0;
  if ( *a3 != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*a3 + 4))(a1: *a3, a2: a3[1]);
  v5 = *((_DWORD *)this + 5);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 8))(a1: v5, a2: *((_DWORD *)this + 6));
  *((_DWORD *)this + 5) = *a3;
  *((_DWORD *)this + 6) = a3[1];
}

//------------------------------------------------------------------------------
// Address: 0x1006B210
// Name: public: virtual GFxResourceLib::ResourceSlot::~ResourceSlot(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall GFxResourceLib::ResourceSlot::~ResourceSlot(IShaderAPI *this)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  int v3; // edi
  int v4; // ecx
  volatile LONG *v5; // edi
  int v6; // ecx
  IShaderAPI *v7; // ecx
  const CDbgFmtMsg *v9; // [esp+0h] [ebp-Ch]

  v2 = (_RTL_CRITICAL_SECTION *)(*((_DWORD *)this + 2) + 12);
  this->__vftable = (IShaderAPI_vtbl *)&GFxResourceLib::ResourceSlot::`vftable';
  EnterCriticalSection(lpCriticalSection: v2);
  if ( *((_DWORD *)this + 3) != 0 )
  {
    if ( *((_DWORD *)this + 4) != 0 )
    {
      v3 = *((_DWORD *)this + 4);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v3 + 4), Value: -1) == 1 )
      {
        v4 = *(_DWORD *)(v3 + 8);
        if ( v4 != 0 )
        {
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 4))(a1: v4, a2: v3);
          *(_DWORD *)(v3 + 8) = 0;
        }
        (**(void (__thiscall ***)(int, int))v3)(a1: v3, a2: 1);
      }
    }
  }
  else
  {
    GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<GFxResourceKey>(a1: this + 5);
  }
  LeaveCriticalSection(lpCriticalSection: v2);
  GEvent::~GEvent(result: v9);
  v5 = (volatile LONG *)(*(_DWORD *)(this + 7) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v5 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  v6 = *((_DWORD *)this + 5);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 8))(a1: v6, a2: *((_DWORD *)this + 6));
  v7 = *((IShaderAPI **)this + 2);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  return GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006B2E0
// Name: public: void GFxResourceLib::ResourceSlot::Resolve(class GFxResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceLib::ResourceSlot::Resolve(GFxResourceLib::ResourceSlot *this, struct GFxResource *a2)
{
  GLock *p_ResourceLock; // ebx
  GFxResourceWeakLib *pObject; // edi
  GFxResourceKey::KeyInterface *pKeyInterface; // ecx
  int v6; // eax
  int Index; // eax
  _DWORD *v8; // eax
  const CDbgFmtMsg *v9; // [esp+0h] [ebp-Ch]

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(lpCriticalSection: &p_ResourceLock->cs);
  InterlockedExchangeAdd(Addend: &a2->RefCount.Value, Value: 1);
  this->pResource = a2;
  pObject = this->pLib.pObject;
  this->State = Resolve_Success;
  if ( pObject->Resources.pTable != nullptr )
  {
    pKeyInterface = this->Key.pKeyInterface;
    if ( pKeyInterface != nullptr )
      v6 = pKeyInterface->GetHashCode(this: pKeyInterface, a2: this->Key.hKeyData);
    else
      v6 = 0;
    Index = GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<GFxResourceKey>(
              a1: &this->Key,
              a2: v6 & *((_DWORD *)pObject->Resources.pTable + 1));
    if ( Index >= 0 )
    {
      v8 = (_DWORD *)((char *)pObject->Resources.pTable + 16 * Index + 16);
      if ( v8 != nullptr )
      {
        v8[1] = a2;
        *v8 = 0;
        a2->pLib = this->pLib.pObject;
        GEvent::SetEvent(result: v9);
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection: &p_ResourceLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x1006B380
// Name: public: void GFxResourceLib::ResourceSlot::CancelResolve(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceLib::ResourceSlot::CancelResolve(GFxResourceLib::ResourceSlot *this, const char *a2)
{
  GLock *p_ResourceLock; // edi
  const CDbgFmtMsg *v4; // [esp+0h] [ebp-8h]

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(lpCriticalSection: &p_ResourceLock->cs);
  this->State = Resolve_Fail;
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&this->ErrorMessage);
  GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<GFxResourceKey>(a1: &this->Key);
  GEvent::SetEvent(result: v4);
  LeaveCriticalSection(lpCriticalSection: &p_ResourceLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x1006B3D0
// Name: public: virtual void GFxResourceWeakLib::UnpinResource(class GFxResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceWeakLib::UnpinResource(
        int this,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pres)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // esi
  CRefCountServiceDestruct<CRefST>_vtbl *v5; // ecx

  v3 = (_RTL_CRITICAL_SECTION *)(this + 12);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 12));
  if ( *(_DWORD *)(this + 8) != 0 )
  {
    GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc>>::RemoveAlt<GFxResource *>(a1: &pres);
    v4 = pres;
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)&pres->m_nUserID, Value: -1) == 1 )
    {
      v5 = v4->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
      if ( v5 != nullptr )
      {
        (*((void (__thiscall **)(CRefCountServiceDestruct<CRefST>_vtbl *, CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))v5->dtr_CRefCountServiceDestruct<CRefST>
         + 1))(
          a1: v5,
          a2: v4);
        v4->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = nullptr;
      }
      ((void (__thiscall *)(CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int))v4->AddRef)(
        a1: v4,
        a2: 1);
    }
  }
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006B440
// Name: public: void GFxResourceWeakLib::UnpinAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceWeakLib::UnpinAll(GFxResourceWeakLib *this)
{
  GLock *p_ResourceLock; // edi
  GFxResourceLib *pStrongLib; // eax
  GHashSetUncached<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2> > *p_PinSet; // edx
  struct GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc> >::TableType *pTable; // eax
  GHashSetUncached<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2> > *v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  struct GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc> >::TableType *v10; // eax
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  GLock *v15; // [esp+8h] [ebp-8h]

  p_ResourceLock = &this->ResourceLock;
  v15 = &this->ResourceLock;
  EnterCriticalSection(lpCriticalSection: &this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib != nullptr )
  {
    p_PinSet = &pStrongLib->PinSet;
    pTable = pStrongLib->PinSet.pTable;
    if ( pTable != nullptr )
    {
      v8 = *((_DWORD *)pTable + 1);
      v7 = 0;
      v9 = (_DWORD *)((char *)pTable + 8);
      do
      {
        if ( *v9 != -2 )
          break;
        ++v7;
        v9 += 2;
      }
      while ( v7 <= v8 );
      v6 = p_PinSet;
    }
    else
    {
      v6 = nullptr;
      v7 = 0;
    }
    while ( v6 != nullptr )
    {
      v10 = v6->pTable;
      if ( v6->pTable == nullptr || (signed int)v7 > *((_DWORD *)v10 + 1) )
        break;
      v11 = *((_DWORD *)v10 + 2 * v7 + 3);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v11 + 4), Value: -1) == 1 )
      {
        v12 = *(_DWORD *)(v11 + 8);
        if ( v12 != 0 )
        {
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 4))(a1: v12, a2: v11);
          *(_DWORD *)(v11 + 8) = 0;
        }
        (**(void (__thiscall ***)(int, int))v11)(a1: v11, a2: 1);
      }
      v13 = *((_DWORD *)v6->pTable + 1);
      if ( (int)v7 <= (int)v13 && ++v7 <= v13 )
      {
        v14 = (_DWORD *)((char *)v6->pTable + 8 * v7 + 8);
        do
        {
          if ( *v14 != -2 )
            break;
          ++v7;
          v14 += 2;
        }
        while ( v7 <= v13 );
      }
    }
    GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc>>::Clear(this: (IMaterialSystem *)&this->pStrongLib->PinSet);
    p_ResourceLock = v15;
  }
  LeaveCriticalSection(lpCriticalSection: &p_ResourceLock->cs);
}

//------------------------------------------------------------------------------
// Address: 0x1006B520
// Name: public: virtual void GFxResourceWeakLib::RemoveResourceOnRelease(class GFxResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceWeakLib::RemoveResourceOnRelease(
        int this,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pres)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  int Index; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // [esp+Ch] [ebp-Ch] BYREF
  int v10; // [esp+10h] [ebp-8h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+14h] [ebp-4h]

  lpCriticalSection = (LPCRITICAL_SECTION)(this + 12);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 12));
  v3 = (_DWORD *)((int (__thiscall *)(CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int *))pres->Release)(
                   a1: pres,
                   a2: &v9);
  v4 = v3;
  if ( *(_DWORD *)(this + 36) != 0
    && (*v3 == 0 ? (v5 = 0) : (v5 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v3 + 16))(a1: *v3, a2: v3[1])),
        (Index = GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<GFxResourceKey>(
                   a1: v4,
                   a2: v5 & *(_DWORD *)(*(_DWORD *)(this + 36) + 4))) >= 0) )
  {
    v7 = (_DWORD *)(*(_DWORD *)(this + 36) + 16 * (Index + 1));
  }
  else
  {
    v7 = nullptr;
  }
  if ( v9 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 8))(a1: v9, a2: v10);
  if ( v7 != nullptr
    && *v7 == 0
    && (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v7[1] == pres )
  {
    v8 = ((int (__thiscall *)(CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int *))pres->Release)(
           a1: pres,
           a2: &v9);
    GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<GFxResourceKey>(a1: v8);
    if ( v9 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 8))(a1: v9, a2: v10);
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1006B620
// Name: public: GFxResourceWeakLib::GFxResourceWeakLib(class GFxResourceLib __near *)
// Source: json
//------------------------------------------------------------------------------
GFxResourceWeakLib *__thiscall GFxResourceWeakLib::GFxResourceWeakLib(
        GFxResourceWeakLib *this,
        struct GFxResourceLib *a2)
{
  int v3; // eax
  GMemoryHeap *v4; // eax
  GMemoryHeap *pObject; // ecx
  GMemoryHeap *v6; // edi
  _DWORD v8[8]; // [esp+Ch] [ebp-20h] BYREF

  this->__vftable = (GFxResourceWeakLib_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (GFxResourceWeakLib_vtbl *)&GFxResourceWeakLib::`vftable';
  GLock::GLock(lpCriticalSection: &this->ResourceLock.cs, spinCount: 0);
  this->Resources.pTable = nullptr;
  this->pImageHeap.pObject = nullptr;
  this->pStrongLib = a2;
  if ( a2 != nullptr && a2->DebugFlag )
    v3 = 4096;
  else
    v3 = 0;
  v8[0] = v3 | 4;
  v8[7] = 0;
  v8[1] = 64;
  v8[2] = 4096;
  v8[3] = 0;
  v8[4] = -1;
  v8[5] = 0;
  v8[6] = 7;
  v4 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2: "_ResourceLib_Images", a3: v8);
  pObject = this->pImageHeap.pObject;
  v6 = v4;
  if ( pObject != nullptr )
    pObject->Release(this: pObject);
  this->pImageHeap.pObject = v6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006B6D0
// Name: public: virtual GFxResourceWeakLib::~GFxResourceWeakLib(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceWeakLib::~GFxResourceWeakLib(GFxResourceWeakLib *this)
{
  GFxResourceWeakLib *v1; // ebx
  struct GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp> >::TableType *pTable; // ecx
  void **p_pTable; // edi
  unsigned int v4; // eax
  GHashSet<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp> > *p_Resources; // esi
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  struct GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp> >::TableType *v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // edx
  GMemoryHeap *pObject; // ecx
  int v12; // ecx
  int v13; // edx

  v1 = this;
  this->__vftable = (GFxResourceWeakLib_vtbl *)&GFxResourceWeakLib::`vftable';
  EnterCriticalSection(lpCriticalSection: &this->ResourceLock.cs);
  pTable = v1->Resources.pTable;
  p_pTable = (void **)&v1->Resources.pTable;
  if ( pTable != nullptr )
  {
    v6 = *((_DWORD *)pTable + 1);
    v4 = 0;
    v7 = (_DWORD *)((char *)pTable + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v4;
      v7 += 4;
    }
    while ( v4 <= v6 );
    p_Resources = &v1->Resources;
  }
  else
  {
    v4 = 0;
    p_Resources = nullptr;
  }
  while ( p_Resources != nullptr )
  {
    v8 = p_Resources->pTable;
    if ( p_Resources->pTable == nullptr || (signed int)v4 > *((_DWORD *)v8 + 1) )
      break;
    *(_DWORD *)(*((_DWORD *)v8 + 4 * v4 + 5) + 8) = 0;
    v9 = *((_DWORD *)p_Resources->pTable + 1);
    if ( (int)v4 <= (int)v9 && ++v4 <= v9 )
    {
      v10 = (_DWORD *)((char *)p_Resources->pTable + 16 * v4 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v4;
        v10 += 4;
      }
      while ( v4 <= v9 );
      v1 = this;
    }
  }
  LeaveCriticalSection(lpCriticalSection: &v1->ResourceLock.cs);
  pObject = v1->pImageHeap.pObject;
  if ( pObject != nullptr )
    pObject->Release(this: pObject);
  if ( *p_pTable != nullptr )
  {
    v12 = 0;
    v13 = *((_DWORD *)*p_pTable + 1) + 1;
    do
    {
      if ( *(_DWORD *)((char *)*p_pTable + v12 + 8) != -2 )
        *(_DWORD *)((char *)*p_pTable + v12 + 8) = -2;
      v12 += 16;
      --v13;
    }
    while ( v13 != 0 );
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *p_pTable);
    *p_pTable = nullptr;
  }
  GLock::~GLock(lpCriticalSection: &v1->ResourceLock.cs);
  GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)v1);
}

//------------------------------------------------------------------------------
// Address: 0x1006B7E0
// Name: public: enum GFxResourceLib::ResolveState GFxResourceWeakLib::BindResourceKey(class GFxResourceLib::BindHandle __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxResourceWeakLib::BindResourceKey(int this, ShaderDeviceInfo_t *result, int a3)
{
  IShaderDevice *v3; // esi
  _DWORD *v4; // ebx
  CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int> *v5; // edi
  int v6; // eax
  int Index; // eax
  CMatRenderContextBase::ScissorRectStackElement_t *v8; // esi
  IShaderDevice *nTop; // ecx
  CUtlBinaryBlock *v11; // eax
  int v12; // eax
  int v13; // esi
  int m_nVersion; // edi
  int v15; // eax
  _RTL_CRITICAL_SECTION *v16; // [esp-4h] [ebp-1Ch]
  VertexShaderHandle_t__ *v17; // [esp+0h] [ebp-18h]
  int v18; // [esp+Ch] [ebp-Ch] BYREF
  IShaderDevice *v19; // [esp+10h] [ebp-8h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+14h] [ebp-4h]

  v3 = (IShaderDevice *)this;
  v19 = (IShaderDevice *)this;
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 12);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 12));
  v4 = (_DWORD *)a3;
  v5 = (CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int> *)&v3[9];
  if ( v3[9].__vftable != nullptr )
  {
    v6 = *(_DWORD *)a3 != 0
       ? (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)a3 + 16))(a1: *(_DWORD *)a3, a2: *(_DWORD *)(a3 + 4))
       : 0;
    Index = GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<GFxResourceKey>(
              a1: v4,
              a2: v6 & v5->m_pMemory->nTop);
    if ( Index >= 0 )
    {
      v8 = &v5->m_pMemory[Index + 1];
      if ( v8 != nullptr )
      {
        nTop = (IShaderDevice *)v8->nTop;
        if ( v8->nLeft != 0 )
        {
          result->m_DisplayMode.m_nVersion = (int)nTop;
          result->m_nVersion = 2;
          GRefCountImpl::AddRef(this: nTop, a2: v17);
          m_nVersion = result->m_nVersion;
          LeaveCriticalSection(lpCriticalSection);
          return m_nVersion;
        }
        if ( GFxResource::AddRef_NotZero(this: nTop) != 0 )
        {
          result->m_DisplayMode.m_nVersion = v8->nTop;
          result->m_nVersion = 1;
          LeaveCriticalSection(lpCriticalSection);
          return 1;
        }
        GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<GFxResourceKey>(a1: v4);
      }
      v3 = v19;
    }
  }
  a3 = 2;
  v11 = (CUtlBinaryBlock *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 76, &a3);
  if ( v11 != nullptr && (GFxResourceLib::ResourceSlot::ResourceSlot(this: v11, plib: v3, a3: v4), v13 = v12, v12 != 0) )
  {
    v18 = 1;
    v19 = (IShaderDevice *)v12;
    v15 = GFxResourceWeakLib::ResourceNode::HashOp::operator()(a1: &v18);
    GHashSetBase<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp,GFxResourceWeakLib::ResourceNode::HashOp,GAllocatorGH<GFxResourceWeakLib::ResourceNode,2>,GHashsetCachedEntry<GFxResourceWeakLib::ResourceNode,GFxResourceWeakLib::ResourceNode::HashOp>>::add<GFxResourceWeakLib::ResourceNode>(
      this: v5,
      pheapAddr: (int)v5,
      a3: (int)&v18,
      a4: v15);
    v16 = lpCriticalSection;
    result->m_DisplayMode.m_nVersion = v13;
    result->m_nVersion = 3;
    LeaveCriticalSection(lpCriticalSection: v16);
    return 3;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection);
    return 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B940
// Name: public: virtual void GFxResourceWeakLib::PinResource(class GFxResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceWeakLib::PinResource(
        int this,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pres)
{
  IMaterialSystem *v3; // edi
  IMaterialSystem_vtbl *v4; // esi
  IMaterialSystem *v5; // edi
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v6; // ebx
  int Index; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+8h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 12);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 12));
  v3 = *(IMaterialSystem **)(this + 8);
  if ( v3 != nullptr )
  {
    v4 = v3[3].__vftable;
    v5 = v3 + 3;
    v6 = pres;
    if ( v4 == nullptr
      || (Index = GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc>>::findIndexCore<GFxResource *>(
                    a1: &pres,
                    a2: (int)v4->Disconnect & ((unsigned int)pres ^ ((unsigned int)pres >> 6)))) < 0
      || (IMaterialSystem_vtbl *)((char *)v4 + 8 * Index) == (IMaterialSystem_vtbl *)-12 )
    {
      GHashSetBase<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc,GFxResourceLib::GFxResourcePtrHashFunc,GAllocatorGH<GFxResource *,2>,GHashsetEntry<GFxResource *,GFxResourceLib::GFxResourcePtrHashFunc>>::add<GFxResource *>(
        this: v5,
        pheapAddr: (MaterialThreadMode_t)v5,
        a3: (int)&pres,
        a4: (unsigned int)v6 ^ ((unsigned int)v6 >> 6));
      InterlockedExchangeAdd(Addend: (volatile LONG *)&v6->m_nUserID, Value: 1);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1006BA20
// Name: public: GFxResourceLib::GFxResourceLib(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceLib::GFxResourceLib(FourVectors *this, const FourVectors *debug)
{
  GFxResourceWeakLib *v3; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  this->x.m128_i32[0] = (int)&GRefCountImplCore::`vftable';
  this->x.m128_i32[1] = 1;
  this->x.m128_i32[0] = (int)&GFxResourceLib::`vftable';
  this->x.m128_i32[3] = 0;
  this->y.m128_i8[0] = (char)debug;
  v4 = 2;
  v3 = (GFxResourceWeakLib *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v4);
  if ( v3 != nullptr )
    this->x.m128_i32[2] = (int)GFxResourceWeakLib::GFxResourceWeakLib(this: v3, a2: (struct GFxResourceLib *)this);
  else
    this->x.m128_i32[2] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006BB80
// Name: public: void GFxResourceWeakLib::GetResourceArray(class GArray<class GPtr<class GFxResource>,2,struct GArrayDefaultPolicy> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceWeakLib::GetResourceArray(int this, CVertexBuilder *a2)
{
  int v3; // ecx
  int *v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  int v8; // ecx
  _DWORD *v9; // edi
  int v10; // ebx
  LONG v11; // esi
  volatile LONG *v12; // ebx
  unsigned int m_VertexSize_BoneWeight; // eax
  int v14; // edi
  unsigned int v15; // esi
  int m_VertexSize_Position; // edx
  _DWORD *v17; // esi
  int v18; // ecx
  unsigned int v19; // ecx
  _DWORD *v20; // edx
  int *v21; // [esp+Ch] [ebp-Ch]
  int v22; // [esp+10h] [ebp-8h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+14h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(this + 12);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 12));
  v3 = *(_DWORD *)(this + 36);
  v4 = (int *)(this + 36);
  v5 = 0;
  if ( v3 != 0 )
  {
    v6 = *(_DWORD *)(v3 + 4);
    v7 = (_DWORD *)(v3 + 8);
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 4;
    }
    while ( v5 <= v6 );
    v21 = v4;
    v22 = v5;
  }
  else
  {
    v21 = nullptr;
    v22 = 0;
  }
  while ( v21 != nullptr )
  {
    v8 = *v21;
    if ( *v21 == 0 || (signed int)v5 > *(_DWORD *)(v8 + 4) )
      break;
    v9 = (_DWORD *)(v8 + 16 * (v5 + 1));
    if ( *v9 == 0 )
    {
      v10 = v9[1];
      v11 = *(_DWORD *)(v10 + 4);
      v12 = (volatile LONG *)(v10 + 4);
      if ( v11 != 0 )
      {
        while ( InterlockedCompareExchange(Destination: v12, Exchange: v11 + 1, Comperand: v11) != v11 )
        {
          v11 = *v12;
          if ( *v12 == 0 )
            goto LABEL_29;
        }
        m_VertexSize_BoneWeight = a2->m_VertexSize_BoneWeight;
        v14 = v9[1];
        v15 = m_VertexSize_BoneWeight + 1;
        if ( m_VertexSize_BoneWeight + 1 >= m_VertexSize_BoneWeight )
        {
          if ( v15 >= a2->m_VertexSize_BoneMatrixIndex )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: a2,
              pheapAddr: (ButtonCode_t)a2,
              newCapacity: v15 + (v15 >> 2));
        }
        else
        {
          GConstructorMov<GPtr<GFxResource>>::DestructArray(a1: a2->m_VertexSize_Position + 4 * v15, a2: -1);
          if ( v15 < (unsigned int)a2->m_VertexSize_BoneMatrixIndex >> 1 )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: a2,
              pheapAddr: (ButtonCode_t)a2,
              newCapacity: v15);
        }
        m_VertexSize_Position = a2->m_VertexSize_Position;
        a2->m_VertexSize_BoneWeight = v15;
        v17 = (_DWORD *)(m_VertexSize_Position + 4 * v15 - 4);
        if ( v17 != nullptr )
        {
          if ( v14 != 0 )
            InterlockedExchangeAdd(Addend: (volatile LONG *)(v14 + 4), Value: 1);
          *v17 = v14;
        }
        if ( v14 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v14 + 4), Value: -1) == 1 )
        {
          v18 = *(_DWORD *)(v14 + 8);
          if ( v18 != 0 )
          {
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 4))(a1: v18, a2: v14);
            *(_DWORD *)(v14 + 8) = 0;
          }
          (**(void (__thiscall ***)(int, int))v14)(a1: v14, a2: 1);
        }
LABEL_29:
        v5 = v22;
      }
    }
    v19 = *(_DWORD *)(*v21 + 4);
    if ( (int)v5 <= (int)v19 )
    {
      v22 = ++v5;
      if ( v5 <= v19 )
      {
        v20 = (_DWORD *)(*v21 + 16 * v5 + 8);
        do
        {
          if ( *v20 != -2 )
            break;
          ++v5;
          v20 += 4;
          v22 = v5;
        }
        while ( v5 <= v19 );
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
}
