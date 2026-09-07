// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/grenderercommonimpl.cpp
// Functions: 82
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\grenderercommonimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: public: virtual GTexture::~GTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTexture::~GTexture(GTexture *this)
{
  this->__vftable = (GTexture_vtbl *)&GTexture::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10001960
// Name: public: virtual GRenderTarget::~GRenderTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderTarget::~GRenderTarget(GRenderTarget *this)
{
  this->__vftable = (GRenderTarget_vtbl *)&GRenderTarget::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: bool GTextureImplNode::CallRecreate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GTextureImplNode::CallRecreate(GTextureImplNode *this)
{
  GRenderer *v2; // ebx
  GTexture::ChangeHandler *pHandler; // eax
  int v4; // esi

  v2 = this->GetRenderer(this);
  if ( this->HandlerArrayFlag )
  {
    pHandler = this->pHandler;
    v4 = 0;
    if ( pHandler[1].__vftable != nullptr )
    {
      while ( (*(unsigned __int8 (__thiscall **)(_DWORD, GRenderer *))(**((_DWORD **)&pHandler->dtr_ChangeHandler + v4)
                                                                     + 8))(
                a1: *((_DWORD *)&pHandler->dtr_ChangeHandler + v4),
                a2: v2) == 0 )
      {
        pHandler = this->pHandler;
        if ( (GTexture::ChangeHandler_vtbl *)++v4 >= pHandler[1].__vftable )
          return 0;
      }
      return 1;
    }
  }
  else if ( this->pHandler != nullptr && this->pHandler->Recreate(this: this->pHandler, a2: v2) )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A40
// Name: public: GTextureImplNode::GTextureImplNode(class GRendererNode __near *)
// Source: json
//------------------------------------------------------------------------------
GTextureImplNode *__thiscall GTextureImplNode::GTextureImplNode(GTextureImplNode *this, GRendererNode *plistRoot)
{
  GTextureImplNode *result; // eax
  GRendererNode *v3; // ecx

  result = this;
  this->__vftable = (GTextureImplNode_vtbl *)&GTexture::`vftable';
  this->RefCount.Value = 1;
  v3 = &this->GRendererNode;
  v3->pNext = plistRoot->pNext;
  v3->pPrev = plistRoot;
  plistRoot->pNext->$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = v3;
  plistRoot->pNext = v3;
  result->__vftable = (GTextureImplNode_vtbl *)&GTextureImplNode::`vftable';
  result->UserHandle = nullptr;
  result->HandlerArrayFlag = false;
  result->pHandler = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001A80
// Name: public: virtual void GRenderTargetImplNode::SetUserData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderTargetImplNode::SetUserData(GRenderTargetImplNode *this, void *hdata)
{
  this->UserHandle = hdata;
}

//------------------------------------------------------------------------------
// Address: 0x10001A90
// Name: public: GRenderTargetImplNode::GRenderTargetImplNode(class GRendererNode __near *)
// Source: json
//------------------------------------------------------------------------------
GRenderTargetImplNode *__thiscall GRenderTargetImplNode::GRenderTargetImplNode(
        GRenderTargetImplNode *this,
        GRendererNode *plistRoot)
{
  GRenderTargetImplNode *result; // eax
  GRendererNode *v3; // ecx

  result = this;
  this->__vftable = (GRenderTargetImplNode_vtbl *)&GRenderTarget::`vftable';
  this->RefCount.Value = 1;
  v3 = &this->GRendererNode;
  v3->pNext = plistRoot->pNext;
  v3->pPrev = plistRoot;
  plistRoot->pNext->$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = v3;
  plistRoot->pNext = v3;
  result->__vftable = (GRenderTargetImplNode_vtbl *)&GRenderTargetImplNode::`vftable';
  result->UserHandle = nullptr;
  result->HandlerArrayFlag = false;
  result->pHandler = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001AD0
// Name: public: void GArrayData<class GTexture::ChangeHandler __near *,struct GAllocatorGH<class GTexture::ChangeHandler __near *,2>,struct GArrayDefaultPolicy>::Append(class GTexture::ChangeHandler __near * const __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy>::Append(
        GArrayData<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *this,
        GTexture::ChangeHandler **other,
        unsigned int count)
{
  unsigned int v3; // edx
  unsigned int Size; // ebx
  unsigned int v6; // edi
  GTexture::ChangeHandler **Data; // eax
  GTexture::ChangeHandler **i; // eax

  v3 = count;
  if ( count == 0 )
    return;
  Size = this->Size;
  v6 = Size + count;
  if ( Size + count >= Size )
  {
    if ( v6 < this->Policy.Capacity )
      goto LABEL_7;
  }
  else if ( v6 >= this->Policy.Capacity >> 1 )
  {
    goto LABEL_7;
  }
  GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve((CVertexBuilder *)this);
  v3 = count;
LABEL_7:
  Data = this->Data;
  this->Size = v6;
  for ( i = &Data[Size]; v3 != 0; --v3 )
  {
    if ( i != nullptr )
      *i = *other;
    ++other;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: virtual GRenderTargetImplNode::~GRenderTargetImplNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderTargetImplNode::~GRenderTargetImplNode(GRenderTargetImplNode *this)
{
  GTexture::ChangeHandler *pHandler; // edi

  this->__vftable = (GRenderTargetImplNode_vtbl *)&GRenderTargetImplNode::`vftable';
  pHandler = this->pHandler;
  if ( pHandler != nullptr && this->HandlerArrayFlag )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pHandler->__vftable);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pHandler);
  }
  if ( this->pNext != nullptr )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
    this->pPrev = nullptr;
    this->pNext = nullptr;
  }
  this->__vftable = (GRenderTargetImplNode_vtbl *)&GRenderTarget::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10001C00
// Name: public: virtual void GTextureImplNode::AddChangeHandler(class GTexture::ChangeHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTextureImplNode::AddChangeHandler(GRenderTargetImplNode *this, GTexture::ChangeHandler *phandler)
{
  GTexture::ChangeHandler *v3; // eax
  CVertexBuilder *v4; // edi
  unsigned int v5; // esi
  _DWORD *v6; // eax
  int v7; // [esp+0h] [ebp-Ch]
  GTexture::ChangeHandler *poldHandler; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  if ( this->pHandler == nullptr )
  {
    this->pHandler = phandler;
    return;
  }
  if ( this->HandlerArrayFlag )
  {
LABEL_8:
    v4 = (CVertexBuilder *)this->pHandler;
    v5 = v4->m_VertexSize_BoneWeight + 1;
    if ( v5 >= v4->m_VertexSize_BoneWeight )
    {
      if ( v5 < v4->m_VertexSize_BoneMatrixIndex )
        goto LABEL_13;
    }
    else if ( v5 >= (unsigned int)v4->m_VertexSize_BoneMatrixIndex >> 1 )
    {
      goto LABEL_13;
    }
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(this: v4);
LABEL_13:
    v6 = (_DWORD *)(v4->m_VertexSize_Position + 4 * v5 - 4);
    v4->m_VertexSize_BoneWeight = v5;
    if ( v6 != nullptr )
      *v6 = phandler;
    return;
  }
  poldHandler = this->pHandler;
  v9 = 2;
  v3 = (GTexture::ChangeHandler *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v9);
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
  this->pHandler = v3;
  if ( v3 != nullptr )
  {
    GArrayBase<GArrayData<unsigned int,GAllocatorGH<unsigned int,2>,GArrayDefaultPolicy>>::PushBack(
      this: (IScaleformUI *)v3,
      val: (const wchar_t *)&poldHandler,
      a3: v7);
    this->HandlerArrayFlag = true;
    goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CC0
// Name: public: void GArrayBase<struct GArrayDataDH<struct GFxTimelineSnapshot::SnapshotElement __near *,struct GAllocatorDH_POD<struct GFxTimelineSnapshot::SnapshotElement __near *,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::RemoveAt(
        CThread *this,
        const char *index)
{
  int v3; // eax

  v3 = *(_DWORD *)this->m_Lock.m_CriticalSection;
  if ( v3 == 1 )
  {
    if ( (*(_DWORD *)&this->m_Lock.m_CriticalSection[4] & 0xFFFFFFFE) != 0 )
    {
      if ( this->__vftable != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->__vftable);
        this->__vftable = nullptr;
      }
      *(_DWORD *)&this->m_Lock.m_CriticalSection[4] = 0;
    }
    *(_DWORD *)this->m_Lock.m_CriticalSection = 0;
  }
  else
  {
    memmove(
      dst: (unsigned __int8 *)&this->dtr_CThread + 4 * (_DWORD)index,
      src: (unsigned __int8 *)&this->Start + 4 * (_DWORD)index,
      count: 4 * (v3 - (_DWORD)index) - 4);
    --*(_DWORD *)this->m_Lock.m_CriticalSection;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D70
// Name: public: virtual GTextureImplNode::~GTextureImplNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTextureImplNode::~GTextureImplNode(GTextureImplNode *this)
{
  GTexture::ChangeHandler *pHandler; // edi

  this->__vftable = (GTextureImplNode_vtbl *)&GTextureImplNode::`vftable';
  pHandler = this->pHandler;
  if ( pHandler != nullptr && this->HandlerArrayFlag )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pHandler->__vftable);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pHandler);
  }
  if ( this->pNext != nullptr )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
    this->pPrev = nullptr;
    this->pNext = nullptr;
  }
  this->__vftable = (GTextureImplNode_vtbl *)&GTexture::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10001E10
// Name: public: void GTextureImplNode::CallHandlers(enum GTexture::ChangeHandler::EventType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTextureImplNode::CallHandlers(GTextureImplNode *this, GTexture::ChangeHandler::EventType event)
{
  GRenderer *v3; // eax
  GTexture::ChangeHandler *pHandler; // esi
  unsigned int Size; // edi
  unsigned int v6; // esi
  GTexture::ChangeHandler **Data; // ebx
  void (__thiscall *Free)(GMemoryHeap *, void *); // edx
  GTexture::ChangeHandler **v9; // [esp-Ch] [ebp-30h]
  unsigned int v10; // [esp-8h] [ebp-2Ch]
  GArray<GTexture::ChangeHandler *,2,GArrayDefaultPolicy> aryCopy; // [esp+8h] [ebp-1Ch] BYREF
  GRenderer *prenderer; // [esp+14h] [ebp-10h]
  int i; // [esp+20h] [ebp-4h]

  v3 = this->GetRenderer(this);
  prenderer = v3;
  if ( this->HandlerArrayFlag )
  {
    pHandler = this->pHandler;
    memset(&aryCopy, 0, sizeof(aryCopy));
    v10 = (unsigned int)pHandler[1].__vftable;
    v9 = (GTexture::ChangeHandler **)pHandler->__vftable;
    i = 0;
    GArrayData<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy>::Append(
      this: &aryCopy.Data,
      other: v9,
      count: v10);
    Size = aryCopy.Data.Size;
    v6 = 0;
    Data = aryCopy.Data.Data;
    for ( i = 1; v6 < Size; ++v6 )
      Data[v6]->OnChange(this: Data[v6], a2: prenderer, a3: event);
    Free = GMemory::pGlobalHeap->Free;
    i = -1;
    Free(this: GMemory::pGlobalHeap, a2: Data);
  }
  else if ( this->pHandler != nullptr )
  {
    this->pHandler->OnChange(this: this->pHandler, a2: v3, a3: event);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EE0
// Name: public: virtual void GTextureImplNode::RemoveChangeHandler(class GTexture::ChangeHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTextureImplNode::RemoveChangeHandler(GRenderTargetImplNode *this, GTexture::ChangeHandler *phandler)
{
  GTexture::ChangeHandler *v3; // ecx
  const char *v4; // edi
  GTexture::ChangeHandler *v5; // edi
  GTexture::ChangeHandler *dtr_ChangeHandler; // ebx

  if ( this->HandlerArrayFlag )
  {
    v3 = this->pHandler;
    v4 = nullptr;
    if ( v3[1].__vftable != nullptr )
    {
      while ( 1 )
      {
        if ( *((GTexture::ChangeHandler **)&v3->dtr_ChangeHandler + (_DWORD)v4) == phandler )
        {
          GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::RemoveAt(
            this: (CThread *)v3,
            index: v4);
          v3 = this->pHandler;
          if ( v3[1].__vftable == (GTexture::ChangeHandler_vtbl *)1 )
            break;
        }
        if ( (GTexture::ChangeHandler_vtbl *)++v4 >= this->pHandler[1].__vftable )
          return;
      }
      v5 = this->pHandler;
      dtr_ChangeHandler = (GTexture::ChangeHandler *)v3->dtr_ChangeHandler;
      if ( v5 != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5->__vftable);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      }
      this->pHandler = dtr_ChangeHandler;
      this->HandlerArrayFlag = false;
    }
  }
  else if ( this->pHandler == phandler )
  {
    this->pHandler = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F80
// Name: public: void GRenderTargetImplNode::CallHandlers(enum GTexture::ChangeHandler::EventType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderTargetImplNode::CallHandlers(
        GRenderTargetImplNode *this,
        GTexture::ChangeHandler::EventType event)
{
  GRenderer *v3; // eax
  GTexture::ChangeHandler *pHandler; // esi
  unsigned int Size; // edi
  unsigned int v6; // esi
  GTexture::ChangeHandler **Data; // ebx
  void (__thiscall *Free)(GMemoryHeap *, void *); // edx
  GTexture::ChangeHandler **v9; // [esp-Ch] [ebp-30h]
  unsigned int v10; // [esp-8h] [ebp-2Ch]
  GArray<GTexture::ChangeHandler *,2,GArrayDefaultPolicy> aryCopy; // [esp+8h] [ebp-1Ch] BYREF
  GRenderer *prenderer; // [esp+14h] [ebp-10h]
  int i; // [esp+20h] [ebp-4h]

  v3 = this->GetRenderer(this);
  prenderer = v3;
  if ( this->HandlerArrayFlag )
  {
    pHandler = this->pHandler;
    memset(&aryCopy, 0, sizeof(aryCopy));
    v10 = (unsigned int)pHandler[1].__vftable;
    v9 = (GTexture::ChangeHandler **)pHandler->__vftable;
    i = 0;
    GArrayData<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy>::Append(
      this: &aryCopy.Data,
      other: v9,
      count: v10);
    Size = aryCopy.Data.Size;
    v6 = 0;
    Data = aryCopy.Data.Data;
    for ( i = 1; v6 < Size; ++v6 )
      Data[v6]->OnChange(this: Data[v6], a2: prenderer, a3: event);
    Free = GMemory::pGlobalHeap->Free;
    i = -1;
    Free(this: GMemory::pGlobalHeap, a2: Data);
  }
  else if ( this->pHandler != nullptr )
  {
    this->pHandler->OnChange(this: this->pHandler, a2: v3, a3: event);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011A50
// Name: public: static void GNewOverrideBase<65>::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlDict<int,unsigned short> *__thiscall GNewOverrideBase<65>::operator delete(
        const CUtlDict<int,unsigned short> *p,
        void *pa)
{
  return ((CUtlDict<int,unsigned short> *(__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: pa);
}

//------------------------------------------------------------------------------
// Address: 0x100651F0
// Name: public: void GArrayBase<struct GArrayData<class GColor,struct GAllocatorGH<class GColor,2>,struct GArrayDefaultPolicy>>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GColor,GAllocatorGH<GColor,2>,GArrayDefaultPolicy>>::Resize(
        matrix3x4a_t *this,
        unsigned int newSize)
{
  if ( newSize >= LODWORD(this->m_flMatVal[0][1]) )
  {
    if ( newSize >= LODWORD(this->m_flMatVal[0][2]) )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve((CVertexBuilder *)this);
  }
  else if ( newSize < LODWORD(this->m_flMatVal[0][2]) >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve((CVertexBuilder *)this);
    LODWORD(this->m_flMatVal[0][1]) = newSize;
    return;
  }
  LODWORD(this->m_flMatVal[0][1]) = newSize;
}

//------------------------------------------------------------------------------
// Address: 0x10069F00
// Name: public: void GArrayData<class GFxValue,struct GAllocatorGH_CPP<class GFxValue,2>,struct GArrayDefaultPolicy>::PushBack(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GFxValue,GAllocatorGH_CPP<GFxValue,2>,GArrayDefaultPolicy>::PushBack(
        unsigned int *this,
        GFxValue *src)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // esi
  int v7; // ecx

  v3 = *(this + 1);
  v4 = v3 + 1;
  if ( v3 + 1 >= v3 )
  {
    if ( v4 >= *(this + 2) )
      GArrayDataBase<GFxValue,GAllocatorGH_CPP<GFxValue,2>,GArrayDefaultPolicy>::Reserve(a1: this, a2: v4 + (v4 >> 2));
  }
  else
  {
    GConstructorCPP<GFxValue>::DestructArray(a1: *this + 16 * v4, a2: -1);
    if ( v4 < *(this + 2) >> 1 )
      GArrayDataBase<GFxValue,GAllocatorGH_CPP<GFxValue,2>,GArrayDefaultPolicy>::Reserve(a1: this, a2: v4);
  }
  v5 = *this;
  *(this + 1) = v4;
  v6 = 2 * v4;
  v7 = v5 + 8 * v6 - 16;
  if ( v5 + 8 * v6 != 16 )
  {
    *(_DWORD *)v7 = 0;
    *(_DWORD *)(v7 + 4) = src->Type;
    *(long double *)(v7 + 8) = src->Value.NValue;
    if ( (src->Type & 0x40) != 0 )
      GFxValue::AcquireManagedValue(this: (GFxValue *)v7, src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071090
// Name: public: class GArrayBase<struct GArrayData<unsigned long,struct GAllocatorGH<unsigned long,2>,struct GArrayDefaultPolicy>> const __near & GArrayBase<struct GArrayData<unsigned long,struct GAllocatorGH<unsigned long,2>,struct GArrayDefaultPolicy>>::operator=(class GArrayBase<struct GArrayData<unsigned long,struct GAllocatorGH<unsigned long,2>,struct GArrayDefaultPolicy>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<unsigned long,GAllocatorGH<unsigned long,2>,GArrayDefaultPolicy>>::operator=(
        CThreadSemaphore *this,
        const CThreadSemaphore *a)
{
  unsigned int v2; // edi
  unsigned int v4; // eax

  v2 = *(_DWORD *)&a->m_bCreatedHandle;
  if ( v2 >= *(_DWORD *)&this->m_bCreatedHandle )
  {
    if ( v2 < *((_DWORD *)this + 2) )
      goto LABEL_6;
  }
  else if ( v2 >= *((_DWORD *)this + 2) >> 1 )
  {
    goto LABEL_6;
  }
  GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve((CVertexBuilder *)this);
LABEL_6:
  v4 = 0;
  for ( *(_DWORD *)&this->m_bCreatedHandle = v2; v4 < *(_DWORD *)&this->m_bCreatedHandle; ++v4 )
    *((_DWORD *)this->m_hSyncObject + v4) = *((_DWORD *)a->m_hSyncObject + v4);
}

//------------------------------------------------------------------------------
// Address: 0x10075BB0
// Name: public: void GArrayData<class GString,struct GAllocatorGH<class GString,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GString,GAllocatorGH<GString,2>,GArrayDefaultPolicy>::Resize(
        CVertexBuilder *this,
        unsigned int a2)
{
  unsigned int m_VertexSize_BoneWeight; // ebx
  unsigned int v4; // esi
  CUtlMemory<CImagePacker,int> *v5; // edi

  m_VertexSize_BoneWeight = this->m_VertexSize_BoneWeight;
  if ( a2 >= m_VertexSize_BoneWeight )
  {
    if ( a2 >= this->m_VertexSize_BoneMatrixIndex )
LABEL_5:
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(this);
  }
  else
  {
    GConstructorMov<GString>::DestructArray(a1: this->m_VertexSize_Position + 4 * a2, a2: m_VertexSize_BoneWeight - a2);
    if ( a2 < (unsigned int)this->m_VertexSize_BoneMatrixIndex >> 1 )
      goto LABEL_5;
  }
  this->m_VertexSize_BoneWeight = a2;
  if ( a2 > m_VertexSize_BoneWeight )
  {
    v4 = a2 - m_VertexSize_BoneWeight;
    v5 = (CUtlMemory<CImagePacker,int> *)(this->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight);
    if ( a2 != m_VertexSize_BoneWeight )
    {
      do
      {
        if ( v5 != nullptr )
          GString::GString(this: v5);
        v5 = (CUtlMemory<CImagePacker,int> *)((char *)v5 + 4);
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075D50
// Name: public: class GArrayBase<struct GArrayData<class GPtr<class GFxResource>,struct GAllocatorGH<class GPtr<class GFxResource>,2>,struct GArrayDefaultPolicy>> const __near & GArrayBase<struct GArrayData<class GPtr<class GFxResource>,struct GAllocatorGH<class GPtr<class GFxResource>,2>,struct GArrayDefaultPolicy>>::operator=(class GArrayBase<struct GArrayData<class GPtr<class GFxResource>,struct GAllocatorGH<class GPtr<class GFxResource>,2>,struct GArrayDefaultPolicy>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CVertexBuilder *__thiscall GArrayBase<GArrayData<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>>::operator=(
        CVertexBuilder *this,
        _DWORD *a2)
{
  unsigned int v2; // esi
  unsigned int m_VertexSize_BoneWeight; // edi
  unsigned int v5; // esi
  _DWORD *i; // eax
  unsigned int v7; // eax
  int v8; // eax
  IShaderDevice *v9; // ecx
  IShaderDevice **v10; // esi
  IShaderDevice **v11; // edi
  VertexShaderHandle_t__ *v13; // [esp+0h] [ebp-10h]
  unsigned int j; // [esp+Ch] [ebp-4h]

  v2 = a2[1];
  m_VertexSize_BoneWeight = this->m_VertexSize_BoneWeight;
  GArrayDataBase<GPtr<GFxResource>,GAllocatorGH<GPtr<GFxResource>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    a2: (int)this,
    a3: v2);
  if ( v2 > m_VertexSize_BoneWeight )
  {
    v5 = v2 - m_VertexSize_BoneWeight;
    for ( i = (_DWORD *)(this->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight); v5 != 0; --v5 )
    {
      if ( i != nullptr )
        *i = 0;
      ++i;
    }
  }
  v7 = 0;
  for ( j = 0; v7 < this->m_VertexSize_BoneWeight; j = v7 )
  {
    v8 = 4 * v7;
    v9 = *(IShaderDevice **)(*a2 + v8);
    v10 = (IShaderDevice **)(v8 + *a2);
    v11 = (IShaderDevice **)(v8 + this->m_VertexSize_Position);
    if ( v9 != nullptr )
      GRefCountImpl::AddRef(this: v9, a2: v13);
    if ( *v11 != nullptr )
      GFxResource::Release(this: *v11, a2: v13);
    *v11 = *v10;
    v7 = j + 1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075DE0
// Name: public: void GArrayData<class GString,struct GAllocatorGH<class GString,2>,struct GArrayDefaultPolicy>::Append(class GString const __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CImagePacker *__thiscall GArrayData<GString,GAllocatorGH<GString,2>,GArrayDefaultPolicy>::Append(
        CVertexBuilder *this,
        CImagePacker *a2,
        CImagePacker *result)
{
  CImagePacker *v3; // ebx
  int m_VertexSize_BoneWeight; // edi
  CImagePacker *v6; // eax
  int v7; // esi

  v3 = result;
  if ( result != nullptr )
  {
    m_VertexSize_BoneWeight = this->m_VertexSize_BoneWeight;
    v6 = (CImagePacker *)GArrayDataBase<GString,GAllocatorGH<GString,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
                           this,
                           a2: (int)this,
                           a3: (int)result + m_VertexSize_BoneWeight);
    v7 = this->m_VertexSize_Position + 4 * m_VertexSize_BoneWeight;
    do
    {
      if ( v7 != 0 )
        v6 = GString::GString(result: a2);
      a2 = (CImagePacker *)((char *)a2 + 4);
      v7 += 4;
      v3 = (CImagePacker *)((char *)v3 - 1);
    }
    while ( v3 != nullptr );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10076FC0
// Name: public: GArray<unsigned char,2,struct GArrayDefaultPolicy>::GArray<unsigned char,2,struct GArrayDefaultPolicy>(int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArray<unsigned char,2,GArrayDefaultPolicy>::GArray<unsigned char,2,GArrayDefaultPolicy>(
        _DWORD *this,
        unsigned int size)
{
  *(this + 1) = 0;
  *this = 0;
  *(this + 2) = 0;
  if ( size >= *(this + 1) )
    GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      pheapAddr: (ButtonCode_t)this,
      newCapacity: size + (size >> 2));
  *(this + 1) = size;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084B70
// Name: public: void GArrayData<class GASValue,struct GAllocatorLH<class GASValue,323>,struct GArrayDefaultPolicy>::Append(class GASValue const __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::Append(
        IGameEventManager2 *pheapAddr,
        const UtlRBTreeNode_t<char const *,unsigned short> *other,
        unsigned int count)
{
  unsigned int v3; // ebx
  int v5; // esi
  GASValue *v6; // esi

  v3 = count;
  if ( count != 0 )
  {
    v5 = *((_DWORD *)pheapAddr + 1);
    GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: pheapAddr,
      (IGameEvent *)pheapAddr);
    v6 = (GASValue *)((char *)pheapAddr->__vftable + 16 * v5);
    do
    {
      if ( v6 != nullptr )
        GASValue::GASValue(this: v6, a2: other);
      other = (const UtlRBTreeNode_t<char const *,unsigned short> *)((char *)other + 16);
      v6 += 4;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100858C0
// Name: public: void GArrayBase<struct GArrayData<char,struct GAllocatorGH<char,2>,struct GArrayDefaultPolicy>>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GArrayBase<GArrayData<char,GAllocatorGH<char,2>,GArrayDefaultPolicy>>::Resize(
        _DWORD *this,
        unsigned int newSize)
{
  unsigned int result; // eax

  if ( newSize >= *(this + 1) )
  {
    if ( newSize >= *(this + 2) )
      result = GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
                 pheapAddr: (ButtonCode_t)this,
                 newCapacity: newSize + (newSize >> 2));
  }
  else
  {
    result = *(this + 2) >> 1;
    if ( newSize < result )
    {
      result = GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
                 pheapAddr: (ButtonCode_t)this,
                 newCapacity: newSize);
      *(this + 1) = newSize;
      return result;
    }
  }
  *(this + 1) = newSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10085AC0
// Name: public: class GArrayBase<struct GArrayData<class GASValue,struct GAllocatorLH<class GASValue,323>,struct GArrayDefaultPolicy>> const __near & GArrayBase<struct GArrayData<class GASValue,struct GAllocatorLH<class GASValue,323>,struct GArrayDefaultPolicy>>::operator=(class GArrayBase<struct GArrayData<class GASValue,struct GAllocatorLH<class GASValue,323>,struct GArrayDefaultPolicy>> const __near &)
// Source: json
//------------------------------------------------------------------------------
IGameEventManager2 *__thiscall GArrayBase<GArrayData<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>>::operator=(
        IGameEventManager2 *pheapAddr,
        GWaitable::HandlerStruct *a)
{
  char *pUserData; // edi
  unsigned int v4; // ebx
  _BYTE *v5; // eax
  char *i; // edi
  unsigned int v7; // ebx
  int v8; // edi

  pUserData = (char *)a->pUserData;
  v4 = *((_DWORD *)pheapAddr + 1);
  GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: pheapAddr,
    (IGameEvent *)pheapAddr);
  if ( (unsigned int)pUserData > v4 )
  {
    v5 = (char *)pheapAddr->__vftable + 16 * v4;
    for ( i = &pUserData[-v4]; i != nullptr; --i )
    {
      if ( v5 != nullptr )
        *v5 = 0;
      v5 += 16;
    }
  }
  v7 = 0;
  if ( *((_DWORD *)pheapAddr + 1) != 0 )
  {
    v8 = 0;
    do
    {
      GASValue::operator=(v: (tagWNDCLASSW *)((char *)a->Handler + v8));
      ++v7;
      v8 += 16;
    }
    while ( v7 < *((_DWORD *)pheapAddr + 1) );
  }
  return pheapAddr;
}

//------------------------------------------------------------------------------
// Address: 0x10086D60
// Name: public: GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>::GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>(struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
        CMatQueuedMesh *this@<ecx>,
        int *a,
        VertexDesc_t *a3)
{
  int v4; // eax
  int v5; // ecx
  IIndexBuffer_vtbl *v6; // edi
  IIndexBuffer_vtbl *v7; // ebx
  char *v8; // [esp-14h] [ebp-1Ch]
  unsigned __int64 v9; // [esp-10h] [ebp-18h]
  int v10; // [esp+4h] [ebp-4h]
  int aa; // [esp+10h] [ebp+8h]

  this->IMesh::IVertexBuffer::__vftable = nullptr;
  this->IMesh::IIndexBuffer::__vftable = nullptr;
  this->m_nMSTActualVertexOffsetInBytes = 0;
  v4 = a[1];
  v5 = *a;
  aa = v4;
  v10 = v5;
  if ( v4 != 0 )
  {
    v6 = this->IMesh::IIndexBuffer::__vftable;
    v7 = (IIndexBuffer_vtbl *)((char *)v6 + v4);
    if ( (IIndexBuffer_vtbl *)((char *)v6 + v4) >= v6 )
    {
      HIDWORD(v9) = (char *)v7 + ((unsigned int)v7 >> 2);
      LODWORD(v9) = this;
      GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(this, pheapAddr: v9);
      v4 = aa;
    }
    v8 = (char *)this->IMesh::IVertexBuffer::__vftable + 156 * (_DWORD)v6;
    this->IMesh::IIndexBuffer::__vftable = v7;
    GConstructorMov<GFxFilterDesc>::ConstructArray(a1: v8, a2: v4, a3: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100876D0
// Name: public: void GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Clear(
        ITypeInfo *this)
{
  CMatQueuedMesh *v1; // ecx
  _DWORD *v2; // esi

  v2 = &v1->IMesh::IVertexBuffer::__vftable;
  if ( v1->IMesh::IIndexBuffer::__vftable == nullptr )
  {
    if ( v1->m_nMSTActualVertexOffsetInBytes == 0 )
      GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(
        this: v1,
        pheapAddr: (unsigned int)v1);
    goto LABEL_8;
  }
  if ( (v1->m_nMSTActualVertexOffsetInBytes & 0xFFFFFFFE) == 0 )
  {
LABEL_8:
    v2[1] = 0;
    return;
  }
  if ( v1->IMesh::IVertexBuffer::__vftable != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v1->IMesh::IVertexBuffer::__vftable);
    *v2 = 0;
  }
  v2[2] = 0;
  v2[1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10087720
// Name: public: void GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>>::PushBack(struct GFxFilterDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PushBack(
        CMatQueuedMesh *this,
        IStream *result)
{
  unsigned int v3; // esi
  CMatQueuedMesh_vtbl *v4; // edx
  unsigned __int64 v5; // [esp-8h] [ebp-10h]

  v3 = (unsigned int)&this->IndexCount + 1;
  if ( (IIndexBuffer_vtbl *)v3 >= this->IMesh::IIndexBuffer::__vftable )
  {
    if ( v3 < this->m_nMSTActualVertexOffsetInBytes )
      goto LABEL_7;
    HIDWORD(v5) = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= (unsigned int)this->m_nMSTActualVertexOffsetInBytes >> 1 )
      goto LABEL_7;
    HIDWORD(v5) = (char *)&this->IndexCount + 1;
  }
  LODWORD(v5) = this;
  GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(this, pheapAddr: v5);
LABEL_7:
  v4 = this->IMesh::IVertexBuffer::__vftable;
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)v3;
  if ( (CMatQueuedMesh_vtbl *)((char *)v4 + 156 * v3) != (CMatQueuedMesh_vtbl *)156 )
    GFxFilterDesc::GFxFilterDesc((IStorage *)result);
}

//------------------------------------------------------------------------------
// Address: 0x10087780
// Name: public: void GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>>::PopBack(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PopBack(
        ITypeInfo *this)
{
  CMatQueuedMesh *v1; // ecx
  _DWORD *v2; // ebx
  IIndexBuffer_vtbl *v3; // edi
  unsigned int v4; // esi
  unsigned __int64 v5; // [esp-8h] [ebp-14h]

  v2 = &v1->IMesh::IVertexBuffer::__vftable;
  v3 = v1->IMesh::IIndexBuffer::__vftable;
  v4 = (unsigned int)&v3[-1].GetMesh + 3;
  if ( v3 != nullptr )
  {
    if ( v4 >= (unsigned int)v1->m_nMSTActualVertexOffsetInBytes >> 1 )
      goto LABEL_7;
    HIDWORD(v5) = (char *)v3 - 1;
  }
  else
  {
    if ( v4 < v1->m_nMSTActualVertexOffsetInBytes )
      goto LABEL_7;
    HIDWORD(v5) = v4 + (v4 >> 2);
  }
  LODWORD(v5) = v1;
  GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(this: v1, pheapAddr: v5);
LABEL_7:
  v2[1] = v4;
  if ( v4 > (unsigned int)v3 )
    GConstructorMov<GFxFilterDesc>::ConstructArray(result: (IDirect3DStateBlock9 *)(*v2 + 156 * (_DWORD)v3));
}

//------------------------------------------------------------------------------
// Address: 0x100877D0
// Name: public: class GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>> const __near & GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>>::operator=(class GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__userpurge GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::operator=@<eax>(
        CMatQueuedMesh *a1@<ecx>,
        IStream *this,
        _ULARGE_INTEGER a)
{
  IIndexBuffer_vtbl *v4; // ebx
  unsigned int v5; // edi
  IIndexBuffer_vtbl *v6; // ebx
  int v7; // edi
  unsigned __int64 v9; // [esp-8h] [ebp-14h]

  v4 = a1->IMesh::IIndexBuffer::__vftable;
  v5 = *((_DWORD *)this + 1);
  if ( v5 >= (unsigned int)v4 )
  {
    if ( v5 < a1->m_nMSTActualVertexOffsetInBytes )
      goto LABEL_7;
    HIDWORD(v9) = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= (unsigned int)a1->m_nMSTActualVertexOffsetInBytes >> 1 )
      goto LABEL_7;
    HIDWORD(v9) = *(this + 1);
  }
  LODWORD(v9) = a1;
  GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(this: a1, pheapAddr: v9);
LABEL_7:
  a1->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)v5;
  if ( v5 > (unsigned int)v4 )
    GConstructorMov<GFxFilterDesc>::ConstructArray(result: (IDirect3DStateBlock9 *)a1->IMesh::IVertexBuffer::__vftable + 39 * (_DWORD)v4);
  v6 = nullptr;
  if ( a1->IMesh::IIndexBuffer::__vftable != nullptr )
  {
    v7 = 0;
    do
    {
      GFxFilterDesc::operator=(a1: (char *)this->__vftable + v7);
      v6 = (IIndexBuffer_vtbl *)((char *)v6 + 1);
      v7 += 156;
    }
    while ( v6 < a1->IMesh::IIndexBuffer::__vftable );
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1008B2C0
// Name: public: void GArrayBase<struct GArrayData<class GFxDisplayList::DisplayEntry,struct GAllocatorLH<class GFxDisplayList::DisplayEntry,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::RemoveAt(
        CMatNullRenderContext *this@<ecx>,
        unsigned __int64 index,
        const char *a3,
        IMaterial *a4,
        VertexStreamSpec_t *a5)
{
  GRefCountNTSImpl *v6; // eax
  const MorphWeight_t *v7; // [esp+0h] [ebp-4h]

  if ( this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable == (CRefCountServiceBase<1,CRefMT>_vtbl *)1 )
  {
    GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this,
      pheapAddr: (IMorph *)this,
      newSize: 0,
      a4: v7);
  }
  else
  {
    v6 = *((GRefCountNTSImpl **)&this->AddRef + index);
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: v6);
    memmove(
      dst: (unsigned __int8 *)&this->AddRef + 4 * index,
      src: (unsigned __int8 *)&this->Release + 4 * index,
      count: 4
    * ((int)this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable
     - index)
    - 4);
    --this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B320
// Name: public: void GArrayBase<struct GArrayData<class GFxDisplayList::DisplayEntry,struct GAllocatorLH<class GFxDisplayList::DisplayEntry,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,class GFxDisplayList::DisplayEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayBase<GArrayData<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>>::InsertAt(
        CMatNullRenderContext *this@<ecx>,
        unsigned int index,
        int (__thiscall **val)(struct CMatNullRenderContext *this),
        const int a4,
        const int a5)
{
  CRefCountServiceBase<1,CRefMT>_vtbl *v6; // ebx
  int v7; // esi
  int (__thiscall **v8)(struct CMatNullRenderContext *); // eax
  CRefCountServiceBase<1,CRefMT>_vtbl *v9; // eax
  int (__thiscall **v10)(struct CMatNullRenderContext *); // eax
  int (__thiscall *v11)(struct CMatNullRenderContext *); // ecx
  const MorphWeight_t *v12; // [esp+0h] [ebp-Ch]

  v6 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    pheapAddr: (IMorph *)this,
    newSize: (int)&v6->dtr_CRefCountServiceBase<1,CRefMT> + 1,
    a4: v12);
  if ( (CRefCountServiceBase<1,CRefMT>_vtbl *)((char *)&v6->dtr_CRefCountServiceBase<1,CRefMT> + 1) > v6 )
  {
    v7 = 1;
    v8 = &this->AddRef + (_DWORD)v6;
    do
    {
      if ( v8 != nullptr )
        *v8 = nullptr;
      ++v8;
      --v7;
    }
    while ( v7 != 0 );
  }
  v9 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  if ( index < (unsigned int)&v9[-1].OnFinalRelease + 3 )
    memmove(
      dst: (unsigned __int8 *)&this->Release + 4 * index,
      src: (unsigned __int8 *)&this->AddRef + 4 * index,
      count: 4 * ((_DWORD)v9 - index) - 4);
  v10 = &this->AddRef + index;
  if ( v10 != nullptr )
  {
    *v10 = nullptr;
    v11 = *val;
    *v10 = *val;
    if ( v11 != nullptr )
      ++*((_DWORD *)v11 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100959E0
// Name: public: void GArrayData<struct GASEnvironment::TryDescr,struct GAllocatorLH<struct GASEnvironment::TryDescr,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GASEnvironment::TryDescr,GAllocatorLH<GASEnvironment::TryDescr,2>,GArrayDefaultPolicy>::Resize(
        __vc_attributes::v1_enumAttribute *this,
        unsigned int newSize)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  int v5; // eax

  v3 = *((_DWORD *)this + 1);
  if ( newSize >= v3 )
  {
    if ( newSize >= *((_DWORD *)this + 2) )
LABEL_5:
      GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve();
  }
  else if ( newSize < *((_DWORD *)this + 2) >> 1 )
  {
    goto LABEL_5;
  }
  *((_DWORD *)this + 1) = newSize;
  if ( newSize > v3 )
  {
    v4 = newSize - v3;
    v5 = *(_DWORD *)this + 12 * v3;
    if ( newSize != v3 )
    {
      do
      {
        if ( v5 != 0 )
          *(_DWORD *)(v5 + 8) = 0;
        v5 += 12;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095A40
// Name: public: GArrayData<class GASWithStackEntry,struct GAllocatorLH_POD<class GASWithStackEntry,323>,struct GArrayDefaultPolicy>::GArrayData<class GASWithStackEntry,struct GAllocatorLH_POD<class GASWithStackEntry,323>,struct GArrayDefaultPolicy>(struct GArrayData<class GASWithStackEntry,struct GAllocatorLH_POD<class GASWithStackEntry,323>,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GASWithStackEntry,GAllocatorLH_POD<GASWithStackEntry,323>,GArrayDefaultPolicy>::GArrayData<GASWithStackEntry,GAllocatorLH_POD<GASWithStackEntry,323>,GArrayDefaultPolicy>(
        GRect<float> *this,
        const GPoint<float> *a)
{
  float y; // ebx
  float Top; // eax
  float v5; // edi
  unsigned __int8 *v6; // [esp-10h] [ebp-1Ch]
  unsigned __int8 *src; // [esp+8h] [ebp-4h]
  const GPoint<float> *aa; // [esp+14h] [ebp+8h]

  this->Left = 0.0;
  this->Top = 0.0;
  this->Right = 0.0;
  y = a->y;
  src = (unsigned __int8 *)LODWORD(a->x);
  if ( y != 0.0 )
  {
    Top = this->Top;
    LODWORD(v5) = LODWORD(Top) + LODWORD(y);
    aa = (const GPoint<float> *)LODWORD(Top);
    if ( (unsigned int)(LODWORD(Top) + LODWORD(y)) >= LODWORD(Top) )
    {
      GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve((AvatarImageLoaded_t *)this);
      Top = *(float *)&aa;
    }
    v6 = (unsigned __int8 *)(LODWORD(this->Left) + 8 * LODWORD(Top));
    this->Top = v5;
    memcpy(dst: v6, src, count: 8 * LODWORD(y));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096110
// Name: public: void GArrayBase<struct GArrayDataCC<class GASString,struct GAllocatorLH<class GASString,323>,struct GArrayDefaultPolicy>>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>>::Resize(
        int this,
        unsigned int newSize)
{
  unsigned int v3; // ebx
  int v4; // esi
  _DWORD *v5; // ecx
  int v6; // eax

  v3 = *(_DWORD *)(this + 4);
  GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::ResizeNoConstruct((GStatBag *)this);
  if ( newSize > v3 )
  {
    v4 = newSize - v3;
    v5 = (_DWORD *)(*(_DWORD *)this + 4 * v3);
    if ( newSize != v3 )
    {
      do
      {
        if ( v5 != nullptr )
        {
          v6 = *(_DWORD *)(this + 12);
          *v5 = v6;
          ++*(_DWORD *)(v6 + 8);
        }
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7530
// Name: public: void GArrayBase<struct GArrayData<unsigned int,struct GAllocatorGH<unsigned int,2>,struct GArrayDefaultPolicy>>::PushBack(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__userpurge GArrayBase<GArrayData<unsigned int,GAllocatorGH<unsigned int,2>,GArrayDefaultPolicy>>::PushBack@<eax>(
        IScaleformUI *this@<ecx>,
        GTexture::ChangeHandler *const *val,
        int a3)
{
  unsigned int v4; // esi
  IScaleformUI_vtbl *v5; // edx
  wchar_t *result; // eax

  v4 = *((_DWORD *)this + 1) + 1;
  if ( v4 >= *((_DWORD *)this + 1) )
  {
    if ( v4 < *((_DWORD *)this + 2) )
      goto LABEL_6;
  }
  else if ( v4 >= *((_DWORD *)this + 2) >> 1 )
  {
    goto LABEL_6;
  }
  GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve((CVertexBuilder *)this);
LABEL_6:
  v5 = this->__vftable;
  *((_DWORD *)this + 1) = v4;
  result = (wchar_t *)((char *)v5 + 4 * v4 - 4);
  if ( (IScaleformUI_vtbl *)((char *)v5 + 4 * v4) != (IScaleformUI_vtbl *)4 )
    *(GTexture::ChangeHandler **)result = *val;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AC050
// Name: public: class GArrayBase<struct GArrayData<class GASWithStackEntry,struct GAllocatorLH_POD<class GASWithStackEntry,323>,struct GArrayDefaultPolicy>> const __near & GArrayBase<struct GArrayData<class GASWithStackEntry,struct GAllocatorLH_POD<class GASWithStackEntry,323>,struct GArrayDefaultPolicy>>::operator=(class GArrayBase<struct GArrayData<class GASWithStackEntry,struct GAllocatorLH_POD<class GASWithStackEntry,323>,struct GArrayDefaultPolicy>> const __near &)
// Source: json
//------------------------------------------------------------------------------
GPtr<GTexture> *__thiscall GArrayBase<GArrayData<GASWithStackEntry,GAllocatorLH_POD<GASWithStackEntry,323>,GArrayDefaultPolicy>>::operator=(
        GPtr<GTexture> *this,
        GTexture *a)
{
  volatile unsigned int Value; // edi
  unsigned int v4; // eax
  GTexture_vtbl *v5; // ecx
  GTexture *pObject; // edx

  Value = a->RefCount.Value;
  if ( Value >= *((_DWORD *)this + 1) )
  {
    if ( Value < *((_DWORD *)this + 2) )
      goto LABEL_6;
  }
  else if ( Value >= *((_DWORD *)this + 2) >> 1 )
  {
    goto LABEL_6;
  }
  GArrayDataBase<GASAsFunctionObject::ArgSpec,GAllocatorLH<GASAsFunctionObject::ArgSpec,323>,GArrayDefaultPolicy>::Reserve((AvatarImageLoaded_t *)this);
LABEL_6:
  v4 = 0;
  for ( *((_DWORD *)this + 1) = Value; v4 < *((_DWORD *)this + 1); ++v4 )
  {
    v5 = a->__vftable;
    pObject = this->pObject;
    pObject[v4].__vftable = *((GTexture_vtbl **)&a->dtr_GTexture + 2 * v4);
    pObject[v4].RefCount.Value = *((_DWORD *)&v5->InitTexture + 2 * v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B3DC0
// Name: public: void GArrayData<struct GFxTimelineDef::Frame,struct GAllocatorLH<struct GFxTimelineDef::Frame,265>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Resize(
        INetChannel *this,
        unsigned int a2)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  const char *(__thiscall **v5)(struct INetChannel *); // eax

  v3 = *((_DWORD *)this + 1);
  if ( a2 >= v3 )
  {
    if ( a2 >= *((_DWORD *)this + 2) )
LABEL_5:
      GArrayDataBase<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,265>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr: (unsigned int)this);
  }
  else if ( a2 < *((_DWORD *)this + 2) >> 1 )
  {
    goto LABEL_5;
  }
  *((_DWORD *)this + 1) = a2;
  if ( a2 > v3 )
  {
    v4 = a2 - v3;
    v5 = &this->GetName + 2 * v3;
    if ( a2 != v3 )
    {
      do
      {
        if ( v5 != nullptr )
        {
          *v5 = nullptr;
          v5[1] = nullptr;
        }
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3E50
// Name: public: GArray<class GASValue,2,struct GArrayDefaultPolicy>::~GArray<class GASValue,2,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArray<GASValue,2,GArrayDefaultPolicy>::~GArray<GASValue,2,GArrayDefaultPolicy>(
        GPtr<IDirect3DPixelShader9> *this)
{
  GASValue *v2; // esi
  int v3; // edi

  v2 = (GASValue *)&this->pObject[4 * *((_DWORD *)this + 1) - 4];
  if ( *((_DWORD *)this + 1) != 0 )
  {
    v3 = *((_DWORD *)this + 1);
    do
    {
      GASValue::~GASValue(this: v2);
      v2 -= 4;
      --v3;
    }
    while ( v3 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100B4030
// Name: public: void GArrayBase<struct GArrayData<class GASValue,struct GAllocatorGH<class GASValue,2>,struct GArrayDefaultPolicy>>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IDirect3DPixelShader9 *__thiscall GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::Resize(
        GPtr<IDirect3DPixelShader9> *this,
        unsigned int newSize)
{
  unsigned int v3; // ebx
  IDirect3DPixelShader9 *result; // eax
  int v5; // esi

  v3 = *((_DWORD *)this + 1);
  result = GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(this);
  if ( newSize > v3 )
  {
    result = &this->pObject[4 * v3];
    v5 = newSize - v3;
    if ( newSize != v3 )
    {
      do
      {
        if ( result != nullptr )
          LOBYTE(result->__vftable) = 0;
        result += 4;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B4070
// Name: public: void GArrayBase<struct GArrayData<class GASValue,struct GAllocatorGH<class GASValue,2>,struct GArrayDefaultPolicy>>::PushBack(class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
IDirect3DPixelShader9 *__thiscall GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::PushBack(
        GPtr<IDirect3DPixelShader9> *this,
        const struct GASValue *a2)
{
  IDirect3DPixelShader9 *result; // eax

  result = GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(this);
  if ( &this->pObject[4 * *((_DWORD *)this + 1)] != (IDirect3DPixelShader9 *)16 )
    return (IDirect3DPixelShader9 *)GASValue::GASValue(
                                      this: (GASValue *)&this->pObject[4 * *((_DWORD *)this + 1) - 4],
                                      a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B40A0
// Name: public: void GArrayBase<struct GArrayDataDH<class GPtr<class GFxASCharacter>,struct GAllocatorDH<class GPtr<class GFxASCharacter>,326>,struct GArrayDefaultPolicy>>::PushBack(class GPtr<class GFxASCharacter> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayBase<GArrayDataDH<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>>::PushBack(
        GMatrix2D *this@<ecx>,
        const GMatrix2D *val,
        const GMatrix2D *a3,
        float a4)
{
  float v5; // edx
  float *v6; // ecx

  GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::ResizeNoConstruct((GStatBag::Iterator *)this);
  v5 = this->M_[0][1];
  v6 = (float *)(LODWORD(this->M_[0][0]) + 4 * LODWORD(v5) - 4);
  if ( LODWORD(this->M_[0][0]) + 4 * LODWORD(v5) != 4 )
  {
    if ( LODWORD(val->M_[0][0]) != 0 )
      ++*(_DWORD *)(LODWORD(val->M_[0][0]) + 4);
    *v6 = val->M_[0][0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B40E0
// Name: public: void GArrayBase<struct GArrayDataDH<struct GFxTimelineSnapshot::SnapshotElement __near *,struct GAllocatorDH_POD<struct GFxTimelineSnapshot::SnapshotElement __near *,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,struct GFxTimelineSnapshot::SnapshotElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayBase<GArrayDataDH<GFxTimelineSnapshot::SnapshotElement *,GAllocatorDH_POD<GFxTimelineSnapshot::SnapshotElement *,2>,GArrayDefaultPolicy>>::InsertAt(
        int *this,
        unsigned int a2,
        _DWORD *a3)
{
  int v4; // eax
  unsigned int v5; // esi
  int result; // eax

  v4 = *(this + 3);
  v5 = *(this + 1) + 1;
  if ( v5 >= *(this + 1) )
  {
    if ( v5 >= *(this + 2) )
      GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
        a1: v4,
        a2: v5 + (v5 >> 2));
  }
  else if ( v5 < (unsigned int)*(this + 2) >> 1 )
  {
    GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(a1: v4, a2: v5);
  }
  *(this + 1) = v5;
  if ( a2 < v5 - 1 )
    memmove(
      dst: (unsigned __int8 *)(*this + 4 * a2 + 4),
      src: (unsigned __int8 *)(*this + 4 * a2),
      count: 4 * (v5 - a2) - 4);
  result = *this;
  *(_DWORD *)(*this + 4 * a2) = *a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B4150
// Name: public: class GArrayBase<struct GArrayData<class GASValue,struct GAllocatorGH<class GASValue,2>,struct GArrayDefaultPolicy>> const __near & GArrayBase<struct GArrayData<class GASValue,struct GAllocatorGH<class GASValue,2>,struct GArrayDefaultPolicy>>::operator=(class GArrayBase<struct GArrayData<class GASValue,struct GAllocatorGH<class GASValue,2>,struct GArrayDefaultPolicy>> const __near &)
// Source: json
//------------------------------------------------------------------------------
GPtr<IDirect3DPixelShader9> *__thiscall GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
        GPtr<IDirect3DPixelShader9> *this,
        _DWORD *a2)
{
  unsigned int v2; // edi
  unsigned int v4; // ebx
  IDirect3DPixelShader9 *v5; // eax
  unsigned int i; // edi
  unsigned int v7; // ebx
  int v8; // edi

  v2 = a2[1];
  v4 = *((_DWORD *)this + 1);
  GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(this);
  if ( v2 > v4 )
  {
    v5 = &this->pObject[4 * v4];
    for ( i = v2 - v4; i != 0; --i )
    {
      if ( v5 != nullptr )
        LOBYTE(v5->__vftable) = 0;
      v5 += 4;
    }
  }
  v7 = 0;
  if ( *((_DWORD *)this + 1) != 0 )
  {
    v8 = 0;
    do
    {
      GASValue::operator=(v: (tagWNDCLASSW *)(v8 + *a2));
      ++v7;
      v8 += 16;
    }
    while ( v7 < *((_DWORD *)this + 1) );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B72A0
// Name: public: void GArrayBase<struct GArrayData<class GPtr<class GFxSprite>,struct GAllocatorLH<class GPtr<class GFxSprite>,326>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>>::RemoveAt(
        ScaleformUIImpl *pheapAddr,
        unsigned int index)
{
  GRefCountNTSImpl *v3; // eax
  int v4; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  if ( pheapAddr->m_pSystem == (GFxSystem *)1 )
  {
    GArrayDataBase<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: pheapAddr,
      (int)pheapAddr,
      newSize: 0,
      a4: v4,
      a5: savedregs);
  }
  else
  {
    v3 = *((GRefCountNTSImpl **)&pheapAddr->Connect + index);
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: v3);
    memmove(
      dst: (unsigned __int8 *)&pheapAddr->Connect + 4 * index,
      src: (unsigned __int8 *)&pheapAddr->Disconnect + 4 * index,
      count: 4 * (int)&pheapAddr->m_pSystem[-index] - 4);
    --pheapAddr->m_pSystem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C92A0
// Name: public: void GArrayBase<struct GArrayData<struct GFxMovieRoot::LevelInfo,struct GAllocatorLH<struct GFxMovieRoot::LevelInfo,326>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,struct GFxMovieRoot::LevelInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GRefCountImplCore *__thiscall GArrayBase<GArrayData<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>>::InsertAt(
        GPtr<GFxTextKeyMap> *this,
        GFxTextKeyMap *index,
        GFxTextKeyMap **a3)
{
  unsigned int v4; // ebx
  int v5; // esi
  GRefCountImplCore *v6; // eax
  int v7; // eax
  GRefCountImplCore *result; // eax
  GFxTextKeyMap *v9; // ecx

  v4 = *((_DWORD *)this + 1);
  GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::ResizeNoConstruct(result: (GFxTestStream *)this);
  if ( v4 + 1 > v4 )
  {
    v5 = 1;
    v6 = (GFxTextKeyMap *)((char *)this->pObject + 8 * v4);
    do
    {
      if ( v6 != nullptr )
        v6->RefCount = 0;
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  v7 = *((_DWORD *)this + 1);
  if ( (unsigned int)index < v7 - 1 )
    memmove(
      dst: (unsigned __int8 *)&this->pObject->SType + 8 * (_DWORD)index,
      src: (unsigned __int8 *)&this->pObject->GRefCountImplCore + 8 * (_DWORD)index,
      count: 8 * (v7 - (_DWORD)index) - 8);
  result = (GFxTextKeyMap *)((char *)this->pObject + 8 * (_DWORD)index);
  if ( result != nullptr )
  {
    result->__vftable = (GRefCountImplCore_vtbl *)*a3;
    v9 = a3[1];
    if ( v9 != nullptr )
      ++v9->RefCount;
    result->RefCount = (volatile int)a3[1];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB330
// Name: public: void GArrayBase<struct GArrayData<struct GFxFilterDesc,struct GAllocatorGH<struct GFxFilterDesc,2>,struct GArrayDefaultPolicy>>::Append(struct GFxFilterDesc const __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
tagSTATSTG *__userpurge GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Append@<eax>(
        CMatQueuedMesh *a1@<ecx>,
        IStream *this,
        tagSTATSTG *other,
        unsigned int count)
{
  tagSTATSTG *result; // eax
  IIndexBuffer_vtbl *v6; // esi
  IIndexBuffer_vtbl *v7; // ebx
  int v8; // [esp-14h] [ebp-18h]
  unsigned __int64 v9; // [esp-10h] [ebp-14h]

  result = other;
  if ( other != nullptr )
  {
    v6 = a1->IMesh::IIndexBuffer::__vftable;
    v7 = (IIndexBuffer_vtbl *)((char *)other + (_DWORD)v6);
    if ( (char *)other + (int)v6 >= (char *)v6 )
    {
      if ( (unsigned int)v7 >= a1->m_nMSTActualVertexOffsetInBytes )
      {
        HIDWORD(v9) = (char *)v7 + ((unsigned int)v7 >> 2);
        goto LABEL_7;
      }
    }
    else if ( (unsigned int)v7 < (unsigned int)a1->m_nMSTActualVertexOffsetInBytes >> 1 )
    {
      HIDWORD(v9) = (char *)other + (_DWORD)v6;
LABEL_7:
      LODWORD(v9) = a1;
      GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(this: a1, pheapAddr: v9);
    }
    v8 = (int)a1->IMesh::IVertexBuffer::__vftable + 156 * (_DWORD)v6;
    a1->IMesh::IIndexBuffer::__vftable = v7;
    return (tagSTATSTG *)GConstructorMov<GFxFilterDesc>::ConstructArray(a1: v8, a2: other, a3: this);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D1F50
// Name: public: void GArrayData<class GWaitable::HandlerStruct,struct GAllocatorGH<class GWaitable::HandlerStruct,2>,struct GArrayConstPolicy<0,16,1>>::Append(class GWaitable::HandlerStruct const __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Append(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),CFuncMemPolicyNone> *this,
        _DWORD *other,
        unsigned int count)
{
  unsigned int v3; // edx
  unsigned int v5; // ebx
  unsigned int v6; // edi
  int m_pfnProxied; // eax
  _DWORD *i; // eax

  v3 = count;
  if ( count == 0 )
    return;
  v5 = DWORD1(this->m_pfnProxied);
  v6 = v5 + count;
  if ( v5 + count >= v5 )
  {
    if ( v6 < DWORD2(this->m_pfnProxied) )
      goto LABEL_7;
  }
  else if ( v6 >= DWORD2(this->m_pfnProxied) >> 1 )
  {
    goto LABEL_7;
  }
  GArrayDataBase<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Reserve((CThreadFastMutex *)this);
  v3 = count;
LABEL_7:
  m_pfnProxied = this->m_pfnProxied;
  DWORD1(this->m_pfnProxied) = v6;
  for ( i = (_DWORD *)(m_pfnProxied + 8 * v5); v3 != 0; --v3 )
  {
    if ( i != nullptr )
    {
      *i = *other;
      i[1] = other[1];
    }
    other += 2;
    i += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1FC0
// Name: public: void GArrayData<class GWaitable::HandlerStruct,struct GAllocatorGH<class GWaitable::HandlerStruct,2>,struct GArrayConstPolicy<0,16,1>>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Resize(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),CFuncMemPolicyNone> *this,
        unsigned int newSize)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  _DWORD *v5; // eax

  v3 = DWORD1(this->m_pfnProxied);
  if ( newSize >= v3 )
  {
    if ( newSize >= DWORD2(this->m_pfnProxied) )
LABEL_5:
      GArrayDataBase<GWaitable::HandlerStruct,GAllocatorGH<GWaitable::HandlerStruct,2>,GArrayConstPolicy<0,16,1>>::Reserve((CThreadFastMutex *)this);
  }
  else if ( newSize < DWORD2(this->m_pfnProxied) >> 1 )
  {
    goto LABEL_5;
  }
  DWORD1(this->m_pfnProxied) = newSize;
  if ( newSize > v3 )
  {
    v4 = newSize - v3;
    v5 = (_DWORD *)(LODWORD(this->m_pfnProxied) + 8 * v3);
    if ( newSize != v3 )
    {
      do
      {
        if ( v5 != nullptr )
        {
          *v5 = 0;
          v5[1] = 0;
        }
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5CC0
// Name: public: void GArrayData<struct GFxTimelineDef::Frame,struct GAllocatorLH<struct GFxTimelineDef::Frame,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
        GFxKeyboardState *this,
        GFxKeyboardState::IListener *newSize)
{
  volatile unsigned int RefCount; // ebx
  char *v4; // esi
  GFxKeyboardState_vtbl *v5; // eax

  RefCount = this->RefCount;
  if ( (unsigned int)newSize >= RefCount )
  {
    if ( newSize >= this->pListener )
LABEL_5:
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        (CStudioHdr *)this,
        pheapAddr: (const CStudioHdr *)this);
  }
  else if ( (unsigned int)newSize < (unsigned int)this->pListener >> 1 )
  {
    goto LABEL_5;
  }
  this->RefCount = (volatile int)newSize;
  if ( (unsigned int)newSize > RefCount )
  {
    v4 = (char *)newSize - RefCount;
    v5 = &this->__vftable[2 * RefCount];
    if ( newSize != (GFxKeyboardState::IListener *)RefCount )
    {
      do
      {
        if ( v5 != nullptr )
        {
          v5->dtr_GRefCountImplCore = nullptr;
          v5[1].dtr_GRefCountImplCore = nullptr;
        }
        v5 += 2;
        --v4;
      }
      while ( v4 != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC3C0
// Name: public: void GArrayBase<struct GArrayData<class GASExecuteTag __near *,struct GAllocatorGH<class GASExecuteTag __near *,2>,struct GArrayConstPolicy<32,16,0>>>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>>::Clear(
        GRefCountBase<GFxAmpMemItem,2> *this)
{
  GRefCountBase<GFxAmpMemItem,2>_vtbl *v2; // eax
  int v3; // [esp+8h] [ebp-4h] BYREF

  if ( this->RefCount == 0 )
  {
    if ( *((_DWORD *)this + 2) == 0 )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(result: (D3DXVECTOR4 *)this);
    goto LABEL_9;
  }
  if ( (*(_DWORD *)(this + 1) & 0xFFFFFFFE) == 0 )
  {
LABEL_9:
    this->RefCount = 0;
    return;
  }
  if ( this->__vftable != nullptr )
  {
    v2 = (GRefCountBase<GFxAmpMemItem,2>_vtbl *)GMemory::pGlobalHeap->Realloc(
                                                  this: GMemory::pGlobalHeap,
                                                  a2: this->__vftable,
                                                  a3: 128);
  }
  else
  {
    v3 = 2;
    v2 = (GRefCountBase<GFxAmpMemItem,2>_vtbl *)GMemory::pGlobalHeap->Alloc_2(
                                                  this: GMemory::pGlobalHeap,
                                                  a2: 128,
                                                  a3: &v3);
  }
  this->RefCount = 0;
  this->__vftable = v2;
  *((_DWORD *)this + 2) = 32;
}

//------------------------------------------------------------------------------
// Address: 0x100E6D00
// Name: public: void GArrayData<struct GFxTextKeyMap::KeyMapEntry,struct GAllocatorGH<struct GFxTextKeyMap::KeyMapEntry,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GArrayData<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Resize(
        IMaterialSystem *this@<ecx>,
        ApplicationPerformanceCountersInfo_t *newSize,
        ApplicationInstantCountersInfo_t *a3)
{
  ApplicationPerformanceCountersInfo_t *v4; // ebx
  char *v5; // eax
  char *v6; // esi

  v4 = *((ApplicationPerformanceCountersInfo_t **)this + 1);
  if ( newSize >= v4 )
  {
    if ( (unsigned int)newSize >= *((_DWORD *)this + 2) )
      GArrayDataBase<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr: (int)this,
        newCapacity: (int)newSize + ((unsigned int)newSize >> 2));
  }
  else if ( (unsigned int)newSize < *((_DWORD *)this + 2) >> 1 )
  {
    GArrayDataBase<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy>::Reserve(
      this,
      pheapAddr: (int)this,
      newCapacity: (int)newSize);
  }
  *((_DWORD *)this + 1) = newSize;
  if ( newSize > v4 )
  {
    v5 = (char *)this->__vftable + 16 * (_DWORD)v4;
    v6 = (char *)((char *)newSize - (char *)v4);
    if ( newSize != v4 )
    {
      do
      {
        if ( v5 != nullptr )
          *((_DWORD *)v5 + 1) = -1;
        v5 += 16;
        --v6;
      }
      while ( v6 != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F05A0
// Name: public: void GArrayData<class GRangeData<void __near *>,struct GAllocatorLH<class GRangeData<void __near *>,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  _DWORD *v5; // eax

  v3 = *(this + 1);
  if ( a2 >= v3 )
  {
    if ( a2 >= *(this + 2) )
LABEL_5:
      GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve();
  }
  else if ( a2 < *(this + 2) >> 1 )
  {
    goto LABEL_5;
  }
  *(this + 1) = a2;
  if ( a2 > v3 )
  {
    v4 = a2 - v3;
    v5 = (_DWORD *)(*this + 12 * v3);
    if ( a2 != v3 )
    {
      do
      {
        if ( v5 != nullptr )
        {
          *v5 = 0;
          v5[1] = 0;
        }
        v5 += 3;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F06C0
// Name: public: void GArrayBase<struct GArrayData<class GPoint<float>,struct GAllocatorLH<class GPoint<float>,2>,struct GArrayDefaultPolicy>>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GPoint<float>,GAllocatorLH<GPoint<float>,2>,GArrayDefaultPolicy>>::Clear(
        CStudioHdr *pheapAddr)
{
  if ( pheapAddr->m_pVModel == nullptr )
  {
    if ( pheapAddr->m_pStudioHdrCache.m_Memory.m_pMemory == nullptr )
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        this: pheapAddr,
        pheapAddr);
    goto LABEL_8;
  }
  if ( ((int)pheapAddr->m_pStudioHdrCache.m_Memory.m_pMemory & 0xFFFFFFFE) == 0 )
  {
LABEL_8:
    pheapAddr->m_pVModel = nullptr;
    return;
  }
  if ( pheapAddr->m_pStudioHdr != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)pheapAddr->m_pStudioHdr);
    pheapAddr->m_pStudioHdr = nullptr;
  }
  pheapAddr->m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
  pheapAddr->m_pVModel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F0710
// Name: public: void GArrayBase<struct GArrayData<class GPoint<float>,struct GAllocatorLH<class GPoint<float>,2>,struct GArrayDefaultPolicy>>::PushBack(class GPoint<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GArrayBase<GArrayData<GPoint<float>,GAllocatorLH<GPoint<float>,2>,GArrayDefaultPolicy>>::PushBack(
        CStudioHdr *this,
        float *a2)
{
  unsigned int v3; // esi
  const studiohdr_t *m_pStudioHdr; // edx
  float *result; // eax
  float v7; // [esp+10h] [ebp+8h]

  v3 = (unsigned int)&this->m_pVModel->m_Lock.m_ownerID + 1;
  if ( (virtualmodel_t *)v3 >= this->m_pVModel )
  {
    if ( (const studiohdr_t **)v3 < this->m_pStudioHdrCache.m_Memory.m_pMemory )
      goto LABEL_6;
  }
  else if ( v3 >= (unsigned int)this->m_pStudioHdrCache.m_Memory.m_pMemory >> 1 )
  {
    goto LABEL_6;
  }
  GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
    this,
    pheapAddr: this);
LABEL_6:
  m_pStudioHdr = this->m_pStudioHdr;
  this->m_pVModel = (virtualmodel_t *)v3;
  result = (float *)((char *)m_pStudioHdr + 8 * v3 - 8);
  if ( (const studiohdr_t *)((char *)m_pStudioHdr + 8 * v3) != (const studiohdr_t *)8 )
  {
    v7 = a2[1];
    *result = *a2;
    result[1] = v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F0770
// Name: public: void GArrayBase<struct GArrayData<class GRangeData<void __near *>,struct GAllocatorLH<class GRangeData<void __near *>,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,class GRangeData<void __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::InsertAt(
        unsigned int *this,
        unsigned int a2,
        _DWORD *a3)
{
  int v4; // eax
  _DWORD *result; // eax
  int v6; // edx

  GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(
    this,
    a2: *(this + 1) + 1);
  v4 = *(this + 1);
  if ( a2 < v4 - 1 )
    memmove(
      dst: (unsigned __int8 *)(*this + 12 * a2 + 12),
      src: (unsigned __int8 *)(*this + 12 * a2),
      count: 4 * (3 * (v4 - a2) - 3));
  result = (_DWORD *)(*this + 12 * a2);
  if ( result != nullptr )
  {
    v6 = a3[1];
    *result = *a3;
    result[1] = v6;
    result[2] = a3[2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F0E20
// Name: public: void GArrayBase<struct GArrayData<class GRangeData<void __near *>,struct GAllocatorLH<class GRangeData<void __near *>,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>>::RemoveAt(
        unsigned int *this,
        int a2)
{
  int v3; // eax

  v3 = *(this + 1);
  if ( v3 == 1 )
  {
    GArrayData<GRangeData<void *>,GAllocatorLH<GRangeData<void *>,2>,GArrayDefaultPolicy>::Resize(this, a2: 0);
  }
  else
  {
    memmove(
      dst: (unsigned __int8 *)(*this + 12 * a2),
      src: (unsigned __int8 *)(*this + 12 * a2 + 12),
      count: 4 * (3 * (v3 - a2) - 3));
    --*(this + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1280
// Name: public: void GArrayBase<struct GArrayData<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,struct GAllocatorGH<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::InsertAt(
        unsigned int *pheapAddr,
        unsigned int a2,
        _DWORD *a3)
{
  unsigned int v4; // esi
  int v5; // eax
  _DWORD *result; // eax
  int v7; // edx
  int v8; // edx

  v4 = *(pheapAddr + 1);
  GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    (ButtonCode_t)pheapAddr,
    newCapacity: v4 + 1);
  if ( v4 + 1 > v4 )
    GConstructorMov<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>>::ConstructArray(
      a1: *pheapAddr + 20 * v4,
      a2: 1);
  v5 = *(pheapAddr + 1);
  if ( a2 < v5 - 1 )
    memmove(
      dst: (unsigned __int8 *)(*pheapAddr + 20 * a2 + 20),
      src: (unsigned __int8 *)(*pheapAddr + 20 * a2),
      count: 4 * (5 * (v5 - a2) - 5));
  result = (_DWORD *)(*pheapAddr + 20 * a2);
  if ( result != nullptr )
  {
    v7 = a3[1];
    *result = *a3;
    result[1] = v7;
    v8 = a3[2];
    if ( v8 != 0 )
      ++*(_DWORD *)(v8 + 4);
    result[2] = a3[2];
    result[3] = a3[3];
    result[4] = a3[4];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F1A10
// Name: public: void GArrayBase<struct GArrayData<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,struct GAllocatorGH<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>>::RemoveAt(
        _DWORD *pheapAddr,
        int a2)
{
  GRefCountNTSImpl *v3; // eax

  if ( *(pheapAddr + 1) == 1 )
  {
    GArrayDataBase<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,GAllocatorGH<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      (ButtonCode_t)pheapAddr,
      newCapacity: 0);
  }
  else
  {
    v3 = *(GRefCountNTSImpl **)(*pheapAddr + 20 * a2 + 8);
    if ( v3 != nullptr )
      GRefCountNTSImpl::Release(this: v3);
    memmove(
      dst: (unsigned __int8 *)(20 * a2 + *pheapAddr),
      src: (unsigned __int8 *)(20 * a2 + *pheapAddr + 20),
      count: 4 * (5 * (*(pheapAddr + 1) - a2) - 5));
    --*(pheapAddr + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF5B0
// Name: public: void GArrayData<class GString,struct GAllocatorLH<class GString,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy>::Resize(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        unsigned int newSize)
{
  unsigned int m_nAllocationCount; // ebx
  unsigned int v4; // esi
  CUtlMemory<CImagePacker,int> *v5; // edi

  m_nAllocationCount = this->m_nAllocationCount;
  if ( newSize >= m_nAllocationCount )
  {
    if ( newSize >= this->m_nGrowSize )
LABEL_5:
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::CachedData *)this,
        pheapAddr: (unsigned int)this);
  }
  else
  {
    GConstructorMov<GString>::DestructArray(a1: (char *)this->m_pMemory + 4 * newSize, a2: m_nAllocationCount - newSize);
    if ( newSize < (unsigned int)this->m_nGrowSize >> 1 )
      goto LABEL_5;
  }
  this->m_nAllocationCount = newSize;
  if ( newSize > m_nAllocationCount )
  {
    v4 = newSize - m_nAllocationCount;
    v5 = (CUtlMemory<CImagePacker,int> *)((char *)this->m_pMemory + 4 * m_nAllocationCount);
    if ( newSize != m_nAllocationCount )
    {
      do
      {
        if ( v5 != nullptr )
          GString::GString(this: v5);
        v5 = (CUtlMemory<CImagePacker,int> *)((char *)v5 + 4);
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101384F0
// Name: public: void GArrayData<class GFxStaticTextRecord::GlyphEntry,struct GAllocatorLH<class GFxStaticTextRecord::GlyphEntry,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GFxStaticTextRecord::GlyphEntry,GAllocatorLH<GFxStaticTextRecord::GlyphEntry,2>,GArrayDefaultPolicy>::Resize(
        CStudioHdr *this,
        const studiohdr_t **a2)
{
  const studiohdr_t **m_pVModel; // ebx
  int v4; // esi
  float *v5; // eax

  m_pVModel = (const studiohdr_t **)this->m_pVModel;
  if ( a2 >= m_pVModel )
  {
    if ( a2 >= this->m_pStudioHdrCache.m_Memory.m_pMemory )
LABEL_5:
      GArrayDataBase<GFxStaticTextSnapshotData::CharRef,GAllocatorLH<GFxStaticTextSnapshotData::CharRef,2>,GArrayDefaultPolicy>::Reserve(
        this,
        pheapAddr: this);
  }
  else if ( (unsigned int)a2 < (unsigned int)this->m_pStudioHdrCache.m_Memory.m_pMemory >> 1 )
  {
    goto LABEL_5;
  }
  this->m_pVModel = (virtualmodel_t *)a2;
  if ( a2 > m_pVModel )
  {
    v4 = (char *)a2 - (char *)m_pVModel;
    v5 = (float *)(&this->m_pStudioHdr->id + 2 * (_DWORD)m_pVModel);
    if ( a2 != m_pVModel )
    {
      do
      {
        if ( v5 != nullptr )
        {
          v5[1] = 0.0;
          *v5 = NAN;
        }
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149EA0
// Name: public: void GArrayData<struct GFxPathPacker::Edge,struct GAllocatorGH<struct GFxPathPacker::Edge,2>,struct GArrayDefaultPolicy>::PushBack(struct GFxPathPacker::Edge const __near &)
// Source: json
//------------------------------------------------------------------------------
ModelRenderInfo_t *__thiscall GArrayData<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::PushBack(
        int *this,
        ModelRenderInfo_t *result)
{
  unsigned int v3; // esi
  int v4; // eax
  ModelRenderInfo_t *v5; // eax

  v3 = *(this + 1) + 1;
  if ( v3 >= *(this + 1) )
  {
    if ( v3 >= *(this + 2) )
      GArrayDataBase<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::Reserve(
        pheapAddr: (ButtonCode_t)this,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < (unsigned int)*(this + 2) >> 1 )
  {
    GArrayDataBase<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::Reserve(
      pheapAddr: (ButtonCode_t)this,
      newCapacity: *(this + 1) + 1);
  }
  v4 = *this;
  *(this + 1) = v3;
  v5 = (ModelRenderInfo_t *)(v4 + 20 * v3 - 20);
  if ( v5 != nullptr )
  {
    v5->origin = result->origin;
    v5->angles.x = result->angles.x;
    v5->angles.y = result->angles.y;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014C630
// Name: public: GArray<class GFxFillStyle,259,struct GArrayDefaultPolicy>::~GArray<class GFxFillStyle,259,struct GArrayDefaultPolicy>(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall GArray<GFxFillStyle,259,GArrayDefaultPolicy>::~GArray<GFxFillStyle,259,GArrayDefaultPolicy>@<eax>(
        _DWORD *a1@<ecx>,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *a2@<edi>)
{
  int v3; // eax
  int v4; // esi
  int v5; // edi
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v7; // [esp-4h] [ebp-Ch]

  v3 = a1[1];
  v4 = *a1 + 40 * v3 - 40;
  if ( v3 != 0 )
  {
    v7 = a2;
    v5 = a1[1];
    do
    {
      GFxFillStyle::~GFxFillStyle(result: v7);
      v4 -= 40;
      --v5;
    }
    while ( v5 != 0 );
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: *a1);
}

//------------------------------------------------------------------------------
// Address: 0x10157720
// Name: public: void GArrayBase<struct GArrayData<struct GFxFontGlyphPacker::GlyphInfo,struct GAllocatorGH<struct GFxFontGlyphPacker::GlyphInfo,2>,struct GArrayDefaultPolicy>>::PushBack(struct GFxFontGlyphPacker::GlyphInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayBase<GArrayData<GFxFontGlyphPacker::GlyphInfo,GAllocatorGH<GFxFontGlyphPacker::GlyphInfo,2>,GArrayDefaultPolicy>>::PushBack(
        int *pheapAddr,
        const struct GFxFontGlyphPacker::GlyphInfo *a2)
{
  unsigned int v3; // esi
  int result; // eax

  v3 = *(pheapAddr + 1) + 1;
  if ( v3 >= *(pheapAddr + 1) )
  {
    if ( v3 >= *(pheapAddr + 2) )
      GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
        (ButtonCode_t)pheapAddr,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < (unsigned int)*(pheapAddr + 2) >> 1 )
  {
    GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
      (ButtonCode_t)pheapAddr,
      newCapacity: *(pheapAddr + 1) + 1);
  }
  result = *pheapAddr;
  *(pheapAddr + 1) = v3;
  if ( result + 40 * v3 != 40 )
    return GFxFontGlyphPacker::GlyphInfo::GlyphInfo(this: (GFxFontGlyphPacker::GlyphInfo *)(result + 40 * v3 - 40), a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B460
// Name: public: void GArrayData<struct GFxMeshSet::MeshSubShape,struct GAllocatorLH<struct GFxMeshSet::MeshSubShape,2>,struct GArrayDefaultPolicy>::PushBack(struct GFxMeshSet::MeshSubShape const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GArrayData<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::PushBack(
        int *this,
        _DWORD *a2)
{
  unsigned int v3; // esi
  int v4; // eax
  _DWORD *result; // eax

  v3 = *(this + 1) + 1;
  if ( v3 >= *(this + 1) )
  {
    if ( v3 >= *(this + 2) )
      GArrayDataBase<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::Reserve(
        a1: this,
        a2: v3 + (v3 >> 2));
  }
  else if ( v3 < (unsigned int)*(this + 2) >> 1 )
  {
    GArrayDataBase<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::Reserve(
      a1: this,
      a2: *(this + 1) + 1);
  }
  v4 = *this;
  *(this + 1) = v3;
  result = (_DWORD *)(v4 + 20 * v3 - 20);
  if ( result != nullptr )
  {
    *result = *a2;
    result[1] = a2[1];
    result[2] = a2[2];
    result[3] = a2[3];
    result[4] = a2[4];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B570
// Name: public: void GArrayBase<struct GArrayData<class GFxFillStyle,struct GAllocatorGH<class GFxFillStyle,259>,struct GArrayDefaultPolicy>>::PushBack(class GFxFillStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxFillStyle *__thiscall GArrayBase<GArrayData<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>>::PushBack(_DWORD *this, const struct GFxFillStyle *a2)
{
  GFxFillStyle *result; // eax

  GArrayDataBase<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
    a1: this,
    a2: *(this + 1) + 1);
  result = (GFxFillStyle *)*(this + 1);
  if ( *this + 40 * (_DWORD)result != 40 )
    return GFxFillStyle::GFxFillStyle(this: (GFxFillStyle *)(*this + 40 * (_DWORD)result - 40), a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B5A0
// Name: public: void GArrayData<class GMatrix2D,struct GAllocatorLH<class GMatrix2D,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CMaterialDict::MissingMaterial_t *__thiscall GArrayData<GMatrix2D,GAllocatorLH<GMatrix2D,2>,GArrayDefaultPolicy>::Resize(
        const CMaterialDict::MissingMaterial_t **this,
        unsigned int a2)
{
  unsigned int v3; // ebx
  const CMaterialDict::MissingMaterial_t *result; // eax
  unsigned int v5; // esi
  int v6; // edi
  const CMaterialDict::MissingMaterial_t *v7; // [esp+0h] [ebp-Ch]

  v3 = (unsigned int)*(this + 1);
  if ( a2 >= v3 )
  {
    if ( a2 >= (unsigned int)*(this + 2) )
      result = (const CMaterialDict::MissingMaterial_t *)GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
                                                           a1: this,
                                                           a2: a2 + (a2 >> 2));
  }
  else
  {
    result = (const CMaterialDict::MissingMaterial_t *)((unsigned int)*(this + 2) >> 1);
    if ( a2 < (unsigned int)result )
      result = (const CMaterialDict::MissingMaterial_t *)GArrayDataBase<MovieSourceLineStats::SourceStats,GAllocatorLH<MovieSourceLineStats::SourceStats,2>,GArrayDefaultPolicy>::Reserve(
                                                           a1: this,
                                                           a2);
  }
  *(this + 1) = (const CMaterialDict::MissingMaterial_t *)a2;
  if ( a2 > v3 )
  {
    v5 = a2 - v3;
    result = *this;
    v6 = (int)&(*this)[12 * v3];
    if ( a2 != v3 )
    {
      do
      {
        if ( v6 != 0 )
          result = GMatrix2D::SetIdentity(result: v7);
        v6 += 24;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D4C0
// Name: public: void GArrayData<class GFxMesh,struct GAllocatorLH<class GFxMesh,131>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GArrayData<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Resize(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // ebx
  int result; // eax

  v3 = *(this + 1);
  if ( a2 >= v3 )
  {
    if ( a2 >= *(this + 2) )
      result = GArrayDataBase<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Reserve(
                 a1: this,
                 a2: a2 + (a2 >> 2));
  }
  else
  {
    result = GConstructorMov<GFxMesh>::DestructArray(a1: *this + 40 * a2, a2: v3 - a2);
    if ( a2 < *(this + 2) >> 1 )
      result = GArrayDataBase<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Reserve(a1: this, a2);
  }
  *(this + 1) = a2;
  if ( a2 > v3 )
    return GConstructorMov<GFxMesh>::ConstructArray(a1: *this + 40 * v3, a2: a2 - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015F550
// Name: protected: class GArrayBase<struct GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>>::Iterator GFxStyledText::GetParagraphByIndex(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::GetParagraphByIndex(
        SFTextObjectImpl *this,
        GFxValue *index,
        unsigned int indexa,
        unsigned int *pindexInParagraph)
{
  GFxValue::ObjectInterface *p_m_nGrowSize; // edx
  int m_Size; // esi
  GFxValue::ValueType v8; // ebx
  __int32 v9; // ebx
  int v10; // edi
  unsigned int v11; // edx
  int v12; // esi
  unsigned int v13; // eax
  GFxValue::ValueType v14; // [esp+14h] [ebp-4h]
  unsigned int indexb; // [esp+24h] [ebp+Ch]

  p_m_nGrowSize = (GFxValue::ObjectInterface *)&this->m_TextBoxes.m_Memory.m_nGrowSize;
  m_Size = this->m_TextBoxes.m_Size;
  v8 = VT_Undefined;
  v14 = VT_Undefined;
  if ( m_Size > 0 )
  {
    indexb = (unsigned int)p_m_nGrowSize->pMovieRoot;
    do
    {
      v9 = (m_Size >> 1) + v8;
      v10 = *(_DWORD *)(indexb + 4 * v9);
      v11 = *(_DWORD *)(v10 + 28);
      if ( indexa >= v11 && indexa < v11 + *(_DWORD *)(v10 + 4) || (int)(v11 - indexa) >= 0 )
      {
        v8 = v14;
        m_Size >>= 1;
      }
      else
      {
        v8 = v9 + 1;
        v14 = v8;
        m_Size += -1 - (m_Size >> 1);
      }
    }
    while ( m_Size > 0 );
    p_m_nGrowSize = (GFxValue::ObjectInterface *)&this->m_TextBoxes.m_Memory.m_nGrowSize;
  }
  if ( (unsigned int)v8 < this->m_TextBoxes.m_Size
    && ((v12 = *((_DWORD *)p_m_nGrowSize->pMovieRoot + v8), v13 = *(_DWORD *)(v12 + 28), indexa >= v13)
     && indexa < v13 + *(_DWORD *)(v12 + 4)
     || v13 == indexa) )
  {
    if ( pindexInParagraph != nullptr )
      *pindexInParagraph = indexa - *(_DWORD *)(*((_DWORD *)p_m_nGrowSize->pMovieRoot + v8) + 28);
    index->Type = v8;
    index->pObjectInterface = p_m_nGrowSize;
  }
  else
  {
    index->pObjectInterface = nullptr;
    index->Type = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F610
// Name: protected: class GArrayBase<struct GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>>::Iterator GFxStyledText::GetNearestParagraphByIndex(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStyledText::GetNearestParagraphByIndex(
        SFTextObjectImpl *this,
        GFxValue *index,
        unsigned int indexa,
        unsigned int *pindexInParagraph)
{
  int m_Size; // eax
  int v5; // edx
  GFxValue::ObjectInterface *p_m_nGrowSize; // ecx
  GFxValue::ValueType v8; // edi
  __int32 v9; // edi
  int v10; // esi
  unsigned int v11; // ecx
  GFxValue::ValueType v12; // edx
  GFxValue::ObjectInterface *v13; // [esp+4h] [ebp-Ch]
  GFxValue::ValueType v14; // [esp+Ch] [ebp-4h]
  unsigned int indexb; // [esp+1Ch] [ebp+Ch]

  m_Size = this->m_TextBoxes.m_Size;
  if ( m_Size != 0 )
  {
    v5 = this->m_TextBoxes.m_Size;
    p_m_nGrowSize = (GFxValue::ObjectInterface *)&this->m_TextBoxes.m_Memory.m_nGrowSize;
    v8 = VT_Undefined;
    v13 = p_m_nGrowSize;
    v14 = VT_Undefined;
    if ( v5 > 0 )
    {
      indexb = (unsigned int)p_m_nGrowSize->pMovieRoot;
      do
      {
        v9 = (v5 >> 1) + v8;
        v10 = *(_DWORD *)(indexb + 4 * v9);
        v11 = *(_DWORD *)(v10 + 28);
        if ( indexa >= v11 && indexa < v11 + *(_DWORD *)(v10 + 4) || (int)(v11 - indexa) >= 0 )
        {
          v8 = v14;
          v5 >>= 1;
        }
        else
        {
          v8 = v9 + 1;
          v14 = v8;
          v5 += -1 - (v5 >> 1);
        }
      }
      while ( v5 > 0 );
      p_m_nGrowSize = v13;
    }
    v12 = v8;
    if ( v8 == m_Size )
      v12 = v8 - 1;
    if ( pindexInParagraph != nullptr )
      *pindexInParagraph = indexa - *(_DWORD *)(*((_DWORD *)p_m_nGrowSize->pMovieRoot + v12) + 28);
    index->pObjectInterface = p_m_nGrowSize;
    index->Type = v12;
  }
  else
  {
    index->pObjectInterface = nullptr;
    index->Type = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162B90
// Name: public: void GArrayBase<struct GArrayData<class GRangeData<class GPtr<class GFxTextFormat>>,struct GAllocatorLH<class GRangeData<class GPtr<class GFxTextFormat>>,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,class GRangeData<class GPtr<class GFxTextFormat>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::InsertAt(
        GJPEGSystem *this,
        unsigned int index,
        void (__thiscall **a3)(struct GJPEGSystem *this))
{
  volatile unsigned int RefCount; // esi
  void (__thiscall **v5)(struct GJPEGSystem *); // eax
  int i; // ecx
  volatile int v7; // eax
  void (__thiscall **v8)(struct GJPEGSystem *); // esi
  void (__thiscall *v9)(struct GJPEGSystem *); // eax
  IShaderDevice *v10; // ecx
  VertexShaderHandle_t__ *v11; // [esp+0h] [ebp-Ch]

  RefCount = this->RefCount;
  GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct();
  if ( RefCount + 1 > RefCount )
  {
    v5 = &this->dtr_GRefCountImplCore + 3 * RefCount;
    for ( i = 1; i != 0; --i )
    {
      if ( v5 != nullptr )
      {
        *v5 = nullptr;
        v5[1] = nullptr;
        v5[2] = nullptr;
      }
      v5 += 3;
    }
  }
  v7 = this->RefCount;
  if ( index < v7 - 1 )
    memmove(
      dst: (unsigned __int8 *)&this->CreateSwfJpeg2HeaderOnly_2 + 12 * index,
      src: (unsigned __int8 *)this->__vftable + 12 * index,
      count: 4 * (3 * (v7 - index) - 3));
  v8 = &this->dtr_GRefCountImplCore + 3 * index;
  if ( v8 != nullptr )
  {
    v9 = a3[1];
    *v8 = *a3;
    v8[1] = v9;
    v10 = (IShaderDevice *)a3[2];
    if ( v10 != nullptr )
      GRefCountImpl::AddRef(this: v10, a2: v11);
    v8[2] = a3[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162C70
// Name: public: void GArrayBase<struct GArrayData<class GRangeData<class GPtr<class GFxTextFormat>>,struct GAllocatorLH<class GRangeData<class GPtr<class GFxTextFormat>>,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>>::RemoveAt(
        _DWORD *this,
        unsigned int index)
{
  IShaderAPI *v3; // eax

  if ( *(this + 1) == 1 )
  {
    GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::ResizeNoConstruct();
  }
  else
  {
    v3 = *(IShaderAPI **)(*this + 12 * index + 8);
    if ( v3 != nullptr )
      GRefCountImpl::Release(this: v3);
    memmove(
      dst: (unsigned __int8 *)(12 * index + *this),
      src: (unsigned __int8 *)(12 * index + *this + 12),
      count: 4 * (3 * (*(this + 1) - index) - 3));
    --*(this + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163EF0
// Name: public: void GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::Resize(
        GRenderer::CachedData *pheapAddr,
        unsigned int newSize)
{
  unsigned int hData; // ebx
  int v4; // esi
  GRenderer_vtbl **v5; // eax

  hData = (unsigned int)pheapAddr->hData;
  if ( newSize >= hData )
  {
    if ( newSize >= *((_DWORD *)pheapAddr + 2) )
LABEL_5:
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: pheapAddr,
        (unsigned int)pheapAddr);
  }
  else
  {
    GConstructorMov<GFxStyledText::ParagraphPtrWrapper>::DestructArray(
      p: (bool)pheapAddr->pRenderer,
      count: (int)pheapAddr->pRenderer + 4 * newSize,
      a3: hData - newSize);
    if ( newSize < *((_DWORD *)pheapAddr + 2) >> 1 )
      goto LABEL_5;
  }
  pheapAddr->hData = (void *)newSize;
  if ( newSize > hData )
  {
    v4 = newSize - hData;
    v5 = &pheapAddr->pRenderer->__vftable + hData;
    if ( newSize != hData )
    {
      do
      {
        if ( v5 != nullptr )
          *v5 = nullptr;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163F60
// Name: public: void GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>::PushBack(class GFxStyledText::ParagraphPtrWrapper const __near &)
// Source: json
//------------------------------------------------------------------------------
GRenderer *__thiscall GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::PushBack(
        GRenderer::CachedData *this,
        GRenderer_vtbl **a2)
{
  GRenderer::CachedData *v2; // edi
  char *hData; // eax
  unsigned int v4; // esi
  GRenderer *pRenderer; // ecx
  GRenderer *result; // eax

  v2 = this;
  hData = (char *)this->hData;
  v4 = (unsigned int)(hData + 1);
  if ( hData + 1 >= hData )
  {
    if ( v4 < *((_DWORD *)this + 2) )
      goto LABEL_6;
  }
  else
  {
    GConstructorMov<GFxStyledText::ParagraphPtrWrapper>::DestructArray(
      p: LOBYTE(this->pRenderer) + 4 * v4,
      count: (int)this->pRenderer + 4 * v4,
      a3: -1);
    if ( v4 >= (unsigned int)v2[1].pRenderer >> 1 )
      goto LABEL_6;
    this = v2;
  }
  GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
    this,
    pheapAddr: (unsigned int)v2);
LABEL_6:
  pRenderer = v2->pRenderer;
  v2->hData = (void *)v4;
  result = (GRenderer *)((char *)pRenderer + 4 * v4 - 4);
  if ( (GRenderer *)((char *)pRenderer + 4 * v4) != (GRenderer *)4 )
  {
    result->__vftable = *a2;
    *a2 = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101641F0
// Name: public: void GArrayBase<struct GArrayData<class GFxStyledText::ParagraphPtrWrapper,struct GAllocatorLH<class GFxStyledText::ParagraphPtrWrapper,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>>::RemoveAt(
        GRenderer::CachedData *this,
        int a2)
{
  _DWORD *v3; // edi
  GRefCountNTSImpl *v4; // ecx

  if ( this->hData == (void *)1 )
  {
    GArrayData<GFxStyledText::ParagraphPtrWrapper,GAllocatorLH<GFxStyledText::ParagraphPtrWrapper,2>,GArrayDefaultPolicy>::Resize(
      pheapAddr: this,
      newSize: 0);
  }
  else
  {
    v3 = *((_DWORD **)&this->pRenderer->__vftable + a2);
    if ( v3 != nullptr )
    {
      GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>::~GArrayDataBase<GRangeData<GPtr<GFxTextFormat>>,GAllocatorLH<GRangeData<GPtr<GFxTextFormat>>,2>,GArrayDefaultPolicy>();
      v4 = (GRefCountNTSImpl *)v3[3];
      if ( v4 != nullptr )
        GRefCountNTSImpl::Release(this: v4);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    }
    memmove(
      dst: (unsigned __int8 *)&this->pRenderer->__vftable + 4 * a2,
      src: (unsigned __int8 *)&this->pRenderer->RefCount + 4 * a2,
      count: 4 * ((int)this->hData - a2) - 4);
    --this->hData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169BB0
// Name: public: void GArrayBase<struct GArrayData<struct GFxTextDocView::ImageSubstitutor::Element,struct GAllocatorLH<struct GFxTextDocView::ImageSubstitutor::Element,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,struct GFxTextDocView::ImageSubstitutor::Element const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GArrayBase<GArrayData<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>>::InsertAt(
        GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> > *result,
        unsigned int a2,
        int a3)
{
  GFxAmpServer::SwdInfo *pObject; // esi
  unsigned int v5; // eax
  int i; // edi
  GFxAmpServer::SwdInfo *v7; // eax
  unsigned int v8; // eax
  int v9; // ecx

  pObject = result->Second.pObject;
  GArrayDataBase<GFxTextDocView::ImageSubstitutor::Element,GAllocatorLH<GFxTextDocView::ImageSubstitutor::Element,2>,GArrayDefaultPolicy>::ResizeNoConstruct(result);
  if ( (GFxAmpServer::SwdInfo *)((char *)&pObject->__vftable + 1) > pObject )
  {
    v5 = result->First + 48 * (_DWORD)pObject;
    for ( i = 1; i != 0; --i )
    {
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 40) = 0;
      v5 += 48;
    }
  }
  v7 = result->Second.pObject;
  if ( a2 < (unsigned int)&v7[-1].Filename.HeapTypeBits + 3 )
    memmove(
      dst: (unsigned __int8 *)(48 * a2 + result->First + 48),
      src: (unsigned __int8 *)(48 * a2 + result->First),
      count: 16 * (3 * ((_DWORD)v7 - a2) - 3));
  v8 = result->First + 48 * a2;
  if ( v8 != 0 )
  {
    qmemcpy((void *)v8, (const void *)a3, 0x28u);
    v9 = *(_DWORD *)(a3 + 40);
    if ( v9 != 0 )
      ++*(_DWORD *)(v9 + 4);
    *(_DWORD *)(v8 + 40) = *(_DWORD *)(a3 + 40);
    *(_BYTE *)(v8 + 44) = *(_BYTE *)(a3 + 44);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10173520
// Name: public: void GArrayData<struct CSSToken<wchar_t>,struct GAllocatorGH<struct CSSToken<wchar_t>,2>,struct GArrayDefaultPolicy>::Resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Resize(
        unsigned int *this,
        unsigned int a2)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  _DWORD *v5; // eax

  v3 = *(this + 1);
  if ( a2 >= v3 )
  {
    if ( a2 >= *(this + 2) )
LABEL_5:
      GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve();
  }
  else if ( a2 < *(this + 2) >> 1 )
  {
    goto LABEL_5;
  }
  *(this + 1) = a2;
  if ( a2 > v3 )
  {
    v4 = a2 - v3;
    v5 = (_DWORD *)(*this + 12 * v3);
    if ( a2 != v3 )
    {
      do
      {
        if ( v5 != nullptr )
        {
          *v5 = 11;
          v5[1] = 0;
          v5[2] = 0;
        }
        v5 += 3;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175F70
// Name: public: void GArrayBase<struct GArrayData<class GFxTextLineBuffer::Line __near *,struct GAllocatorLH<class GFxTextLineBuffer::Line __near *,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,class GFxTextLineBuffer::Line __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GFxTextLineBuffer::Line *,GAllocatorLH<GFxTextLineBuffer::Line *,2>,GArrayDefaultPolicy>>::InsertAt(
        CMaterial_QueueFriendly *this,
        MaterialVarFlags_t index,
        const char *(__thiscall **val)(struct CMaterial_QueueFriendly *this))
{
  IMaterialInternal *v4; // esi
  const char *(__thiscall **v5)(struct CMaterial_QueueFriendly *); // eax

  v4 = (IMaterialInternal *)((char *)&this->m_pRealTimeVersion->__vftable + 1);
  if ( v4 >= this->m_pRealTimeVersion )
  {
    if ( (unsigned int)v4 < LODWORD(this->m_fAlphaModulationOnQueueCompletion) )
      goto LABEL_6;
  }
  else if ( (unsigned int)v4 >= LODWORD(this->m_fAlphaModulationOnQueueCompletion) >> 1 )
  {
    goto LABEL_6;
  }
  GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
    (GRenderer::CachedData *)this,
    pheapAddr: (unsigned int)this);
LABEL_6:
  this->m_pRealTimeVersion = v4;
  if ( index < (unsigned int)&v4[-1].__vftable + 3 )
    memmove(
      dst: (unsigned __int8 *)&this->GetTextureGroupName + 4 * index,
      src: (unsigned __int8 *)&this->GetName + 4 * index,
      count: 4 * (_DWORD)((char *)v4 - index) - 4);
  v5 = &this->GetName + index;
  if ( v5 != nullptr )
    *v5 = *val;
}

//------------------------------------------------------------------------------
// Address: 0x1017B480
// Name: public: void GArrayData<struct GFxTextHighlightDesc,struct GAllocatorGH<struct GFxTextHighlightDesc,2>,struct GArrayDefaultPolicy>::PushBack(struct GFxTextHighlightDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GArrayData<GFxTextHighlightDesc,GAllocatorGH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>::PushBack(
        int *pheapAddr,
        int a2)
{
  unsigned int v3; // esi
  int v4; // eax
  unsigned int result; // eax

  v3 = *(pheapAddr + 1) + 1;
  if ( v3 >= *(pheapAddr + 1) )
  {
    if ( v3 >= *(pheapAddr + 2) )
      GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
        (ButtonCode_t)pheapAddr,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < (unsigned int)*(pheapAddr + 2) >> 1 )
  {
    GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
      (ButtonCode_t)pheapAddr,
      newCapacity: *(pheapAddr + 1) + 1);
  }
  v4 = *pheapAddr;
  *(pheapAddr + 1) = v3;
  result = v4 + 40 * v3 - 40;
  if ( result != 0 )
  {
    *(_DWORD *)result = *(_DWORD *)a2;
    *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(result + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(result + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(result + 32) = *(_DWORD *)(a2 + 32);
    *(_BYTE *)(result + 36) = *(_BYTE *)(a2 + 36);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C1A0
// Name: public: void GArrayBase<struct GArrayData<struct GFxTextHighlightDesc,struct GAllocatorLH<struct GFxTextHighlightDesc,2>,struct GArrayDefaultPolicy>>::InsertAt(unsigned int,struct GFxTextHighlightDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall GArrayBase<GArrayData<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>>::InsertAt(
        CUtlMemory<char const *,int> *this,
        unsigned int index,
        int a3)
{
  unsigned int m_nAllocationCount; // ebx
  unsigned int v5; // edi
  int v6; // eax
  const char **result; // eax

  m_nAllocationCount = this->m_nAllocationCount;
  v5 = m_nAllocationCount + 1;
  if ( m_nAllocationCount + 1 >= m_nAllocationCount )
  {
    if ( v5 < this->m_nGrowSize )
      goto LABEL_6;
  }
  else if ( v5 >= (unsigned int)this->m_nGrowSize >> 1 )
  {
    goto LABEL_6;
  }
  GArrayDataBase<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>::Reserve(
    (GRenderer::FillTexture *)this,
    pheapAddr: (const GRenderer::FillTexture *)this);
LABEL_6:
  this->m_nAllocationCount = v5;
  if ( v5 > m_nAllocationCount )
    GConstructorMov<GFxTextHighlightDesc>::ConstructArray(a1: &this->m_pMemory[10 * m_nAllocationCount], a2: 1);
  v6 = this->m_nAllocationCount;
  if ( index < v6 - 1 )
    memmove(
      dst: (unsigned __int8 *)&this->m_pMemory[10 * index + 10],
      src: (unsigned __int8 *)&this->m_pMemory[10 * index],
      count: 8 * (5 * (v6 - index) - 5));
  result = &this->m_pMemory[10 * index];
  if ( result != nullptr )
  {
    *result = *(const char **)a3;
    result[1] = *(const char **)(a3 + 4);
    result[2] = *(const char **)(a3 + 8);
    result[3] = *(const char **)(a3 + 12);
    result[4] = *(const char **)(a3 + 16);
    result[5] = *(const char **)(a3 + 20);
    result[6] = *(const char **)(a3 + 24);
    result[7] = *(const char **)(a3 + 28);
    result[8] = *(const char **)(a3 + 32);
    *((_BYTE *)result + 36) = *(_BYTE *)(a3 + 36);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C480
// Name: public: void GArrayBase<struct GArrayData<struct GFxTextHighlightDesc,struct GAllocatorLH<struct GFxTextHighlightDesc,2>,struct GArrayDefaultPolicy>>::RemoveAt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayBase<GArrayData<GFxTextHighlightDesc,GAllocatorLH<GFxTextHighlightDesc,2>,GArrayDefaultPolicy>>::RemoveAt(
        CUtlMemory<char const *,int> *this,
        unsigned int index)
{
  int m_nAllocationCount; // eax

  m_nAllocationCount = this->m_nAllocationCount;
  if ( m_nAllocationCount == 1 )
  {
    if ( (this->m_nGrowSize & 0xFFFFFFFE) != 0 )
    {
      if ( this->m_pMemory != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->m_pMemory);
        this->m_pMemory = nullptr;
      }
      this->m_nGrowSize = 0;
    }
    this->m_nAllocationCount = 0;
  }
  else
  {
    memmove(
      dst: (unsigned __int8 *)&this->m_pMemory[10 * index],
      src: (unsigned __int8 *)&this->m_pMemory[10 * index + 10],
      count: 8 * (5 * (m_nAllocationCount - index) - 5));
    --this->m_nAllocationCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101847B0
// Name: public: void GArrayData<unsigned char,struct GAllocatorLH<unsigned char,2>,struct GArrayConstPolicy<0,4,1>>::Append(unsigned char const __near * const,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GArrayData<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Append(
        unsigned int *this,
        _BYTE *a2,
        int a3)
{
  int v3; // edx
  unsigned int v5; // ebx
  unsigned int v6; // edi
  unsigned int v7; // eax
  _BYTE *v9; // eax
  int i; // esi

  v3 = a3;
  if ( a3 == 0 )
    return;
  v5 = *(this + 1);
  v6 = v5 + a3;
  if ( v5 + a3 >= v5 )
  {
    if ( v6 < *(this + 2) )
      goto LABEL_8;
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(
      a1: this,
      a2: v6 + (v6 >> 2));
  }
  else
  {
    if ( v6 >= *(this + 2) >> 1 )
      goto LABEL_8;
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(a1: this, a2: v5 + a3);
  }
  v3 = a3;
LABEL_8:
  v7 = *this;
  *(this + 1) = v6;
  v9 = (_BYTE *)(v5 + v7);
  if ( v3 != 0 )
  {
    for ( i = v3; i != 0; --i )
    {
      if ( v9 != nullptr )
        *v9 = *a2;
      ++a2;
      ++v9;
    }
  }
}
