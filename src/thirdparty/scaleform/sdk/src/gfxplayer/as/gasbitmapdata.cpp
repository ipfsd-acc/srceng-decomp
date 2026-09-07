// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasbitmapdata.cpp
// Functions: 13
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasbitmapdata.h"

//------------------------------------------------------------------------------
// Address: 0x1012EAB0
// Name: public: virtual bool GASBitmapData::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapData::SetMember(
        CTSQueue<CFunctor *,0,1> *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *a3,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **a4,
        const struct GASPropFlags *a5)
{
  if ( strcmp(*(const char **)a3->N.Name.Short, (const char *)&stru_102A2E68.m_pElements) != 0
    && strcmp(*(const char **)a3->N.Name.Short, (const char *)&stru_102A2E68.m_Memory.m_nGrowSize) != 0 )
  {
    GASObject::SetMember(this, (GASEnvironment *)a2, name: a3, pval: a4, pmember: (char *)a5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EB40
// Name: public: virtual enum GASObjectInterface::ObjectType GASBitmapData::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASBitmapData::GetObjectType()
{
  return 26;
}

//------------------------------------------------------------------------------
// Address: 0x1012EB60
// Name: protected: virtual void GASBitmapData::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapData::Finalize_GC(GFxAmpConnStatusInterface *this)
{
  IShaderDevice *v2; // ecx
  IShaderDevice *v3; // ecx

  v2 = *((IShaderDevice **)this + 13);
  if ( v2 != nullptr )
    GFxResource::Release(this: v2);
  *((_DWORD *)this + 13) = 0;
  v3 = *((IShaderDevice **)this + 14);
  if ( v3 != nullptr )
    GFxResource::Release(this: v3);
  *((_DWORD *)this + 14) = 0;
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1012EBF0
// Name: private: void GASBitmapData::commonInit(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapData::commonInit(GFxAmpConnStatusInterface *this, const GFxAmpConnStatusInterface *penv)
{
  const GFxAmpConnStatusInterface *v3; // esi
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  int v5; // edx
  GFxAmpConnStatusInterface *v6; // edi
  GFxAmpConnStatusInterface_vtbl *v7; // ecx
  int v8; // eax
  bool v9; // zf
  GFxAmpConnStatusInterface_vtbl *v10; // eax
  int v11; // eax
  GASValue v12[4]; // [esp+8h] [ebp-14h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+18h] [ebp-4h] BYREF

  v3 = penv + 30;
  Prototype = GASGlobalContext::GetPrototype(
                this: (vc_attributes::PreRangeAttribute *)penv[30].__vftable,
                result: (vc_attributes::InvalidCheckAttribute *)0x1E);
  v5 = *((_DWORD *)this + 4);
  v6 = this + 4;
  (*(void (__thiscall **)(GFxAmpConnStatusInterface *, const GFxAmpConnStatusInterface *, vc_attributes::InvalidCheckAttribute *))(v5 + 52))(
    a1: v6,
    a2: v3,
    a3: Prototype);
  v7 = v3->__vftable;
  HIBYTE(penv) = 4;
  LOBYTE(v12[0]) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v7[79].OnStatusChanged,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
                      a3: 5u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  ((void (__thiscall *)(GFxAmpConnStatusInterface *, const GFxAmpConnStatusInterface *, struct GASStringNode **, GASValue *, char *))v6->__vftable[5].dtr_GFxAmpConnStatusInterface)(
    a1: v6,
    a2: v3,
    a3: &ConstStringNode,
    a4: v12,
    a5: (char *)&penv + 3);
  v8 = (int)ConstStringNode;
  v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v8);
  GASValue::~GASValue(this: v12, a2: (int)v6);
  v10 = v3->__vftable;
  HIBYTE(penv) = 4;
  LOBYTE(v12[0]) = 10;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)v10[79].OnStatusChanged,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
                      a3: 6u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  ((void (__thiscall *)(GFxAmpConnStatusInterface *, const GFxAmpConnStatusInterface *, struct GASStringNode **))v6->__vftable[5].dtr_GFxAmpConnStatusInterface)(
    a1: v6,
    a2: v3,
    a3: &ConstStringNode);
  v11 = (int)ConstStringNode;
  v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v11);
  GASValue::~GASValue(this: v12, a2: (int)v12);
}

//------------------------------------------------------------------------------
// Address: 0x1012ECD0
// Name: public: virtual bool GASBitmapData::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapData::GetMember(
        GPtr<GFxAmpSendThreadCallback> *this,
        ID3DXFont *penv,
        const char ***name,
        GASValue *a4)
{
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  GASValue *v7; // esi
  double v8; // st7
  int v9; // ecx

  v4 = *((_DWORD *)this + 9);
  if ( v4 == 0 )
    goto LABEL_19;
  if ( strcmp(**name, (const char *)&stru_102A2E68.m_pElements) != 0 )
  {
    if ( strcmp(**name, (const char *)&stru_102A2E68.m_Memory.m_nGrowSize) == 0 )
    {
      v9 = *(_DWORD *)(v4 + 12);
      if ( v9 != 0 )
        v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
      else
        v6 = 0;
      v7 = a4;
      if ( *(_BYTE *)a4 >= 5u )
        GASValue::DropRefs(this: a4, a2: v6);
      v8 = (double)v6;
      goto LABEL_9;
    }
LABEL_19:
    GASObject::GetMember((D3DXQUATERNION *)this, result: penv, penv: (_IMAGE_SYMBOL_EX *)name, val: (int *)a4);
    return;
  }
  v5 = *(_DWORD *)(v4 + 12);
  if ( v5 != 0 )
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  else
    v6 = 0;
  v7 = a4;
  if ( *(_BYTE *)a4 >= 5u )
    GASValue::DropRefs(this: a4, a2: v6);
  v8 = (double)v6;
LABEL_9:
  *(_BYTE *)v7 = 3;
  if ( v6 < 0 )
    v8 = v8 + 4294967296.0;
  *(double *)(v7 + 1) = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1012EF00
// Name: public: GASBitmapData::GASBitmapData(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GFxAmpConnStatusInterface *__thiscall GASBitmapData::GASBitmapData(
        GFxAmpConnStatusInterface *this,
        GFxAmpConnStatusInterface *penv)
{
  GASObject::GASObject((GASObject *)this, a2: (struct GASEnvironment *)penv);
  this->__vftable = (GFxAmpConnStatusInterface_vtbl *)&GASBitmapData::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBitmapData::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  GASBitmapData::commonInit(this, penv);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012F090
// Name: public: void GASBitmapData::SetImage(class GASEnvironment __near *,class GFxImageResource __near *,class GFxMovieDef __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapData::SetImage(
        HINSTANCE__ *this,
        struct GASEnvironment *a2,
        IShaderDevice *pimg,
        HICON__ *pimg_4)
{
  IShaderDevice *v4; // ecx
  IShaderDevice *hCursor; // ecx
  IShaderDevice *v6; // ecx
  char *v7; // edi
  int v8; // ecx
  int v9; // ebx
  GASValue *v10; // eax
  HICON__ *v11; // eax
  GASValue *v13; // esi
  int i; // edi
  int v15; // [esp+Ch] [ebp-70h] BYREF
  int v16; // [esp+10h] [ebp-6Ch]
  int v17; // [esp+14h] [ebp-68h]
  int v18; // [esp+18h] [ebp-64h]
  tagWNDCLASSW v19; // [esp+1Ch] [ebp-60h] BYREF
  _BYTE v20[16]; // [esp+48h] [ebp-34h] BYREF
  _BYTE v21[16]; // [esp+58h] [ebp-24h] BYREF
  _BYTE v22[16]; // [esp+68h] [ebp-14h] BYREF
  int v23; // [esp+78h] [ebp-4h] BYREF

  v19.hInstance = this;
  v19.hCursor = pimg_4;
  if ( pimg != nullptr )
    GRefCountImpl::AddRef(this: pimg);
  v4 = *((IShaderDevice **)v19.hInstance + 13);
  if ( v4 != nullptr )
    GFxResource::Release(this: v4);
  hCursor = (IShaderDevice *)v19.hCursor;
  *((_DWORD *)v19.hInstance + 13) = pimg;
  if ( hCursor != nullptr )
    GRefCountImpl::AddRef(this: hCursor);
  v6 = *((IShaderDevice **)v19.hInstance + 14);
  if ( v6 != nullptr )
    GFxResource::Release(this: v6);
  *((_DWORD *)v19.hInstance + 14) = v19.hCursor;
  (*((void (__thiscall **)(IShaderDevice_vtbl *, int *))pimg[3].ReleaseResources + 7))(a1: pimg[3].__vftable, a2: &v15);
  LOBYTE(v19.hbrBackground) = 0;
  v20[0] = 0;
  v21[0] = 0;
  v22[0] = 0;
  LOBYTE(v19.style) = 4;
  v19.lpfnWndProc = nullptr;
  GASValue::operator=(this: (int)&v19.hbrBackground, v: &v19);
  GASValue::~GASValue(this: (GASValue *)&v19, (int)a2);
  LOBYTE(v19.style) = 4;
  v19.lpfnWndProc = nullptr;
  GASValue::operator=(this: (int)v20, v: &v19);
  GASValue::~GASValue(this: (GASValue *)&v19, (int)a2);
  v19.hCursor = (HICON__ *)(v17 - v15);
  *(double *)&v19.lpfnWndProc = (double)(v17 - v15);
  LOBYTE(v19.style) = 3;
  GASValue::operator=(this: (int)v21, v: &v19);
  GASValue::~GASValue(this: (GASValue *)&v19, (int)a2);
  v19.hCursor = (HICON__ *)(v18 - v16);
  *(double *)&v19.lpfnWndProc = (double)(v18 - v16);
  LOBYTE(v19.style) = 3;
  GASValue::operator=(this: (int)v22, v: &v19);
  GASValue::~GASValue(this: (GASValue *)&v19, (int)a2);
  v7 = (char *)GASEnvironment::OperatorNew(
                 this: (__vc_attributes::idl_quoteAttribute *)a2,
                 (int)a2,
                 a3: *(struct GASObject **)(*((_DWORD *)a2 + 30) + 660),
                 a4: (const struct GASString *)(*((_DWORD *)a2 + 30) + 68),
                 nargs: 0,
                 argsTopOff: -1);
  GASRectangleObject::SetProperties(
    this: v7,
    psc: (struct GASEnvironment *)((char *)a2 + 120),
    a3: (GMemoryHeap *)&v19.hbrBackground);
  v8 = *((_DWORD *)a2 + 30);
  HIBYTE(v19.hIcon) = 4;
  v19.hCursor = (HICON__ *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(v8 + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7AB4,
                             a3: 9u,
                             a4: 0);
  ++*((_DWORD *)v19.hCursor + 2);
  v19.hInstance += 4;
  v9 = *(_DWORD *)v19.hInstance;
  v10 = GASValue::GASValue(this: (GASValue *)&v19, a2: (struct GASObject *)v7);
  (*(void (__thiscall **)(HINSTANCE__ *, char *, HICON__ **, GASValue *, char *))(v9 + 40))(
    a1: v19.hInstance,
    a2: (char *)a2 + 120,
    a3: &v19.hCursor,
    a4: v10,
    a5: (char *)&v19.hIcon + 3);
  v11 = v19.hCursor;
  if ( (*((_DWORD *)v19.hCursor + 2))-- == 1 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  GASValue::~GASValue(this: (GASValue *)&v19, a2: (int)v7);
  if ( v7 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v7, a2: (int)v7);
  v13 = (GASValue *)&v23;
  for ( i = 3; i >= 0; --i )
  {
    v13 -= 4;
    GASValue::~GASValue(this: v13, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F250
// Name: public: static void GASBitmapDataCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASBitmapDataCtorFunction::GlobalCtor(int a1@<edi>, int a2)
{
  int v2; // ebx
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASObject *v5; // eax
  GFxAmpConnStatusInterface *v6; // esi
  struct GASEnvironment *v7; // edi
  int v8; // [esp-4h] [ebp-Ch]

  v2 = a2;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 24) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASObject *)v4(a1: v3, a2: 60, a3: &a2);
  v6 = (GFxAmpConnStatusInterface *)v5;
  if ( v5 != nullptr )
  {
    v8 = a1;
    v7 = *(struct GASEnvironment **)(v2 + 24);
    GASObject::GASObject(this: v5, a2: v7);
    v6->__vftable = (GFxAmpConnStatusInterface_vtbl *)&GASBitmapData::`vftable'{for `GASRefCountBase<GASObject>'};
    v6[4].__vftable = (GFxAmpConnStatusInterface_vtbl *)&GASBitmapData::`vftable'{for `GASObjectInterface'};
    v6[13].__vftable = nullptr;
    v6[14].__vftable = nullptr;
    GASBitmapData::commonInit(this: v6, penv: (const GFxAmpConnStatusInterface *)v7);
    a1 = v8;
  }
  else
  {
    v6 = nullptr;
  }
  GASValue::SetAsObject(this: *(GASValue **)(v2 + 4), a2: (struct GASObject *)v6);
  if ( v6 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v6, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1012F350
// Name: class GASBitmapData __near * GFx_LoadBitmap<class GString>(class GASEnvironment __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_LoadBitmap<GString>(GASEnvironment *a1, CUtlMemory<CImagePacker,int> *a2)
{
  int v2; // ecx
  int (__thiscall *v3)(int); // eax
  IShaderDevice *v4; // eax
  struct GFxMovieDefImpl *m_nAllocationCount; // esi
  CUtlMemory<CImagePacker,int> *v6; // ecx
  char Size; // al
  bool v8; // bl
  void *v9; // esi
  bool v10; // bl
  void *v11; // esi
  void *v12; // esi
  GASEnvironment *v13; // edi
  int v14; // eax
  int v15; // esi
  struct GMemoryHeap *v16; // edi
  struct GFxLog *v17; // ebx
  IShaderAPI *v18; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GFxAmpConnStatusInterface *v20; // eax
  CImagePacker *m_pMemory; // esi
  IShaderDevice *v22; // ecx
  GFxMovieRoot *MovieRoot; // eax
  bool v25; // bl
  void *v26; // esi
  IShaderDevice *v27; // esi
  GFxAmpConnStatusInterface *v28; // edi
  int v29; // ecx
  int (__thiscall *v30)(int, int, GASEnvironment **); // edx
  GFxAmpConnStatusInterface *v31; // eax
  int v32; // [esp-4h] [ebp-2Ch]
  IShaderDevice *v33; // [esp+Ch] [ebp-1Ch] BYREF
  GString v34; // [esp+10h] [ebp-18h] BYREF
  GString v35; // [esp+14h] [ebp-14h] BYREF
  CUtlMemory<CImagePacker,int> v36; // [esp+18h] [ebp-10h] BYREF
  char v37; // [esp+27h] [ebp-1h]

  v2 = *((_DWORD *)a1 + 29);
  v3 = *(int (__thiscall **)(int))(*(_DWORD *)v2 + 92);
  v36.m_nGrowSize = 0;
  v4 = (IShaderDevice *)v3(a1: v2);
  m_nAllocationCount = (struct GFxMovieDefImpl *)v4;
  v36.m_nAllocationCount = (int)v4;
  if ( v4 == nullptr )
    return v36.m_nGrowSize;
  GRefCountImpl::AddRef(this: v4);
  v6 = a2;
  v35.pData = (GString::DataDesc *)(((int)a2->m_pMemory & 0xFFFFFFFC) + 8);
  Size = v35.pData->Size;
  v37 = 0;
  if ( Size != 105 && Size != 73 )
  {
LABEL_28:
    v32 = ((int)v6->m_pMemory & 0xFFFFFFFC) + 8;
    v33 = nullptr;
    v34.pData = nullptr;
    GString::GString(this: &v35, src: v32);
    MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: a1);
    v25 = GFxMovieRoot::FindExportedResource(
            this: MovieRoot,
            a2: m_nAllocationCount,
            result: (CMatQueuedIndexBuffer *)&v33,
            a4: &v35) == 0;
    v26 = (void *)(v35.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v35.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v26);
    if ( v25 )
    {
      if ( v33 != nullptr )
        GFxResource::Release(this: v33);
    }
    else
    {
      if ( (v33->GetBackBufferFormat(this: v33) & 0xFF00) == 0x100 )
      {
        v27 = v33;
        if ( v33 == nullptr )
          goto LABEL_44;
        v28 = (GFxAmpConnStatusInterface *)a1;
        v29 = *(_DWORD *)(*((_DWORD *)a1 + 30) + 656);
        v30 = *(int (__thiscall **)(int, int, GASEnvironment **))(*(_DWORD *)v29 + 40);
        a1 = (GASEnvironment *)323;
        v31 = (GFxAmpConnStatusInterface *)v30(a1: v29, a2: 60, a3: &a1);
        v36.m_nGrowSize = v31 != nullptr ? (int)GASBitmapData::GASBitmapData(this: v31, penv: v28) : 0;
        GASBitmapData::SetImage(
          this: (HINSTANCE__ *)v36.m_nGrowSize,
          a2: (struct GASEnvironment *)v28,
          pimg: v27,
          pimg_4: (HICON__ *)v36.m_nAllocationCount);
        v22 = v33;
        if ( v33 == nullptr )
          goto LABEL_44;
        goto LABEL_43;
      }
      if ( v33 != nullptr )
        GFxResource::Release(this: v33);
    }
    GFxResource::Release(this: (IShaderDevice *)v36.m_nAllocationCount);
    return 0;
  }
  GString::ToLower(this: a2, a2: &v36);
  v8 = strcmp(
         (const char *)((*(_DWORD *)GString::Substring(this: (GString *)&v36, a2: &v34, a3: 0, a4: 6u).HeapTypeBits
                       & 0xFFFFFFFC)
                      + 8),
         (const char *)&stru_102A119C.m_pElements) == 0;
  v9 = (void *)(v34.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v34.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
  if ( v8 )
    goto LABEL_10;
  v10 = strcmp(
          (const char *)((*(_DWORD *)GString::Substring(this: (GString *)&v36, a2: &v34, a3: 0, a4: 8u).HeapTypeBits
                        & 0xFFFFFFFC)
                       + 8),
          (const char *)&stru_102A119C.m_Elements.m_nGrowSize) == 0;
  v11 = (void *)(v34.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v34.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  if ( v10 )
LABEL_10:
    v37 = 1;
  v12 = (void *)((int)v36.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v36.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
  if ( v37 == 0 )
  {
    v6 = a2;
    m_nAllocationCount = (struct GFxMovieDefImpl *)v36.m_nAllocationCount;
    goto LABEL_28;
  }
  v13 = a1;
  v14 = *((_DWORD *)GASEnvironment::GetMovieRoot(this: a1) + 60);
  if ( v14 != 0 )
    v15 = v14 + 8;
  else
    v15 = 0;
  v16 = *(struct GMemoryHeap **)(*((_DWORD *)v13 + 30) + 656);
  v17 = (struct GFxLog *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v15 + 12))(a1: v15, a2: 4);
  v18 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v15 + 12))(a1: v15, a2: 5);
  v36.m_pMemory = (CImagePacker *)GFxLoaderImpl::LoadMovieImage(
                                    a1: (const char *)v35.pData,
                                    a2: (int)v18,
                                    a3: v17,
                                    a4: v16);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v17);
  if ( v36.m_pMemory == nullptr )
  {
    GASEnvironment::LogScriptWarning(this: a1, a2: (const char *)&stru_102A7AB4.m_Size, v35.pData);
    GFxResource::Release(this: (IShaderDevice *)v36.m_nAllocationCount);
    return v36.m_nGrowSize;
  }
  Alloc_2 = v16->Alloc_2;
  v34.pData = (GString::DataDesc *)323;
  v20 = (GFxAmpConnStatusInterface *)Alloc_2(this: v16, a2: 60u, a3: (const GAllocDebugInfo *)&v34);
  if ( v20 != nullptr )
    v36.m_nGrowSize = (int)GASBitmapData::GASBitmapData(this: v20, penv: (GFxAmpConnStatusInterface *)a1);
  else
    v36.m_nGrowSize = 0;
  m_pMemory = v36.m_pMemory;
  GASBitmapData::SetImage(
    this: (HINSTANCE__ *)v36.m_nGrowSize,
    a2: (struct GASEnvironment *)a1,
    pimg: (IShaderDevice *)v36.m_pMemory,
    pimg_4: nullptr);
  v22 = (IShaderDevice *)m_pMemory;
LABEL_43:
  GFxResource::Release(this: v22);
LABEL_44:
  GFxResource::Release(this: (IShaderDevice *)v36.m_nAllocationCount);
  return v36.m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x1012F6B0
// Name: class GASBitmapData __near * GFx_LoadBitmap<class GASString>(class GASEnvironment __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
GASBitmapData *__cdecl GFx_LoadBitmap<GASString>(GString a1, int **a2)
{
  GString::DataDesc *pData; // edi
  int v3; // ecx
  int (__thiscall *v4)(int); // edx
  IShaderDevice *v5; // eax
  IShaderDevice *v6; // esi
  int **v7; // ecx
  char v8; // al
  bool v9; // zf
  struct GASStringNode *v10; // eax
  bool v11; // bl
  struct GASStringNode *v12; // eax
  bool v13; // bl
  struct GFxImageResource *v14; // eax
  int v15; // eax
  int v16; // esi
  struct GMemoryHeap *v17; // edi
  struct GFxLog *v18; // ebx
  IShaderAPI *v19; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GFxAmpConnStatusInterface *v21; // eax
  struct GFxImageResource *v22; // esi
  IShaderDevice *v23; // ecx
  int *v25; // edx
  GFxMovieRoot *MovieRoot; // eax
  bool v27; // bl
  void *v28; // esi
  IShaderDevice *v29; // esi
  int v30; // ecx
  int (__thiscall *v31)(int, int, GString *); // edx
  GFxAmpConnStatusInterface *v32; // eax
  IShaderDevice *v33; // [esp+Ch] [ebp-1Ch] BYREF
  int v34; // [esp+10h] [ebp-18h] BYREF
  char *v35; // [esp+14h] [ebp-14h]
  struct GFxImageResource *MovieImage; // [esp+18h] [ebp-10h] BYREF
  IShaderDevice *v37; // [esp+1Ch] [ebp-Ch]
  GASBitmapData *v38; // [esp+20h] [ebp-8h]
  char v39; // [esp+27h] [ebp-1h]

  pData = a1.pData;
  v3 = *(_DWORD *)a1.pData[9].Data;
  v4 = *(int (__thiscall **)(int))(*(_DWORD *)v3 + 92);
  v38 = nullptr;
  v5 = (IShaderDevice *)v4(a1: v3);
  v6 = v5;
  v37 = v5;
  if ( v5 == nullptr )
    return v38;
  GRefCountImpl::AddRef(this: v5);
  v7 = a2;
  v35 = (char *)**a2;
  v8 = *v35;
  v39 = 0;
  if ( v8 != 105 && v8 != 73 )
  {
LABEL_28:
    v25 = *v7;
    v33 = nullptr;
    v34 = 0;
    GString::GString(this: &a1, src: *v25);
    MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)pData);
    v27 = GFxMovieRoot::FindExportedResource(
            this: MovieRoot,
            a2: (struct GFxMovieDefImpl *)v6,
            result: (CMatQueuedIndexBuffer *)&v33,
            a4: &a1) == 0;
    v28 = (void *)(a1.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a1.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
    if ( v27 )
    {
      if ( v33 != nullptr )
        GFxResource::Release(this: v33);
    }
    else
    {
      if ( (v33->GetBackBufferFormat(this: v33) & 0xFF00) == 0x100 )
      {
        v29 = v33;
        if ( v33 == nullptr )
          goto LABEL_44;
        v30 = *(_DWORD *)(pData[10].Size + 656);
        v31 = *(int (__thiscall **)(int, int, GString *))(*(_DWORD *)v30 + 40);
        a1.pData = (GString::DataDesc *)323;
        v32 = (GFxAmpConnStatusInterface *)v31(a1: v30, a2: 60, a3: &a1);
        v38 = v32 != nullptr
            ? (GASBitmapData *)GASBitmapData::GASBitmapData(this: v32, penv: (GFxAmpConnStatusInterface *)pData)
            : nullptr;
        GASBitmapData::SetImage(
          this: (HINSTANCE__ *)v38,
          a2: (struct GASEnvironment *)pData,
          pimg: v29,
          pimg_4: (HICON__ *)v37);
        v23 = v33;
        if ( v33 == nullptr )
          goto LABEL_44;
        goto LABEL_43;
      }
      if ( v33 != nullptr )
        GFxResource::Release(this: v33);
    }
    GFxResource::Release(this: v37);
    return nullptr;
  }
  GASString::ToLower(this: a2, a2: (int *)&MovieImage);
  v9 = strcmp(
         *(const char **)*GASString::Substring(
                            this: (_DWORD **)&MovieImage,
                            a2: (struct GASStringNode **)&v34,
                            start: 0,
                            end: 6),
         (const char *)&stru_102A119C.m_pElements) == 0;
  v10 = (struct GASStringNode *)v34;
  v11 = v9;
  v9 = (*(_DWORD *)(v34 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v10);
  if ( v11 )
    goto LABEL_10;
  v9 = strcmp(
         *(const char **)*GASString::Substring(
                            this: (_DWORD **)&MovieImage,
                            a2: (struct GASStringNode **)&v34,
                            start: 0,
                            end: 8),
         (const char *)&stru_102A119C.m_Elements.m_nGrowSize) == 0;
  v12 = (struct GASStringNode *)v34;
  v13 = v9;
  v9 = (*(_DWORD *)(v34 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  if ( v13 )
LABEL_10:
    v39 = 1;
  v14 = MovieImage;
  v9 = (*((_DWORD *)MovieImage + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  if ( v39 == 0 )
  {
    v7 = a2;
    v6 = v37;
    goto LABEL_28;
  }
  v15 = *((_DWORD *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)pData) + 60);
  if ( v15 != 0 )
    v16 = v15 + 8;
  else
    v16 = 0;
  v17 = *(struct GMemoryHeap **)(pData[10].Size + 656);
  v18 = (struct GFxLog *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v16 + 12))(a1: v16, a2: 4);
  v19 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v16 + 12))(a1: v16, a2: 5);
  MovieImage = (struct GFxImageResource *)GFxLoaderImpl::LoadMovieImage(a1: v35, a2: (int)v19, a3: v18, a4: v17);
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v18);
  if ( MovieImage == nullptr )
  {
    GASEnvironment::LogScriptWarning(this: (GASEnvironment *)a1.pData, a2: (const char *)&stru_102A7AB4.m_Size, v35);
    GFxResource::Release(this: v37);
    return v38;
  }
  Alloc_2 = v17->Alloc_2;
  v34 = 323;
  v21 = (GFxAmpConnStatusInterface *)Alloc_2(this: v17, a2: 60u, a3: (const GAllocDebugInfo *)&v34);
  if ( v21 != nullptr )
    v38 = (GASBitmapData *)GASBitmapData::GASBitmapData(this: v21, penv: (GFxAmpConnStatusInterface *)a1.pData);
  else
    v38 = nullptr;
  v22 = MovieImage;
  GASBitmapData::SetImage(
    this: (HINSTANCE__ *)v38,
    a2: (struct GASEnvironment *)a1.pData,
    pimg: (IShaderDevice *)MovieImage,
    pimg_4: nullptr);
  v23 = (IShaderDevice *)v22;
LABEL_43:
  GFxResource::Release(this: v23);
LABEL_44:
  GFxResource::Release(this: v37);
  return v38;
}

//------------------------------------------------------------------------------
// Address: 0x1012F9D0
// Name: public: static class GASBitmapData __near * GASBitmapData::LoadBitmapA(class GASEnvironment __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GASBitmapData::LoadBitmapA(struct GASEnvironment *a1, CUtlMemory<CImagePacker,int> *a2)
{
  return GFx_LoadBitmap<GString>((GASEnvironment *)a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1012FA60
// Name: public: static void GASBitmapDataCtorFunction::LoadBitmapA(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASBitmapDataCtorFunction::LoadBitmapA(GASFnCall *a1)
{
  GASFnCall *v1; // esi
  GASValue *v2; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  struct GASObject *v5; // eax
  int v6; // edi
  GASFnCall *v7; // eax
  bool v8; // zf

  v1 = a1;
  v2 = (GASValue *)a1[1];
  GASValue::DropRefs(this: v2, a2: (int)v2);
  *(_BYTE *)v2 = 1;
  if ( (int)v1[7] >= 1 )
  {
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)v1[6];
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: v1, a2: 0);
    GASValue::ToStringImpl(this: v4, a2: (int *)&a1, a3: v3, precision: -1, debug: false);
    v5 = (struct GASObject *)GFx_LoadBitmap<GASString>(a1: (GString)v1[6], a2: (int **)&a1);
    v6 = (int)v5;
    if ( v5 != nullptr )
    {
      GASValue::SetAsObject(this: (GASValue *)v1[1], a2: v5);
      GRefCountBaseGC<323>::Release(a1: v6, a2: v6);
    }
    v7 = a1;
    v8 = a1[2] == (GASFnCall)1;
    a1[2] = (GASFnCall)((char *)a1[2] - 1);
    if ( v8 )
      GASStringNode::ReleaseNode(a1: (int)v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FAE0
// Name: public: static class GASFunctionRef GASBitmapDataCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASBitmapDataCtorFunction::Register(
        struct GASFunctionRef *a1,
        _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  void *v7; // ecx
  GASCFunctionObject *v8; // eax
  struct GASFunctionRef *v9; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, struct GASFunctionRef **); // eax
  GASPrototypeBase *v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  unsigned int Deref; // edx
  GASValue *v15; // eax
  GASValue v17[4]; // [esp+Ch] [ebp-1Ch] BYREF
  CTSQueue<CFunctor *,0,1>::Node_t v18; // [esp+1Ch] [ebp-Ch] BYREF
  int v19; // [esp+24h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v18.pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)pgc;
  LOBYTE(v18.elem) = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v18,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASBitmapDataCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: &v18,
      a4: (struct GASObject **)GASBitmapDataCtorFunction::StaticFunctionTable,
      a5: 7);
    v8 = v6;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = a1;
  *(_DWORD *)a1 = v8;
  *((_BYTE *)v9 + 8) = 0;
  *((_DWORD *)v9 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v12 = (GASPrototypeBase *)v11(a1: MaxVal, a2: 92, a3: &a1);
  if ( v12 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASBitmapData,GASEnvironment>::GASPrototype<GASBitmapData,GASEnvironment>(
      this: (int)v12,
      psc: (struct GASStringContext *)&v18,
      psc_4: Prototype,
      psc_8: (unsigned int)v9);
    v12->__vftable = (IUnknown_vtbl *)&GASBitmapDataProto::`vftable'{for `GASRefCountBase<GASObject>'};
    v12[4].__vftable = (IUnknown_vtbl *)&GASBitmapDataProto::`vftable'{for `GASObjectInterface'};
    v12[15].__vftable = (IUnknown_vtbl *)&GASBitmapDataProto::`vftable';
    HIBYTE(pgc) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: v12 + 15,
      a2: (int)v12,
      flags: (vc_attributes::PreRangeAttribute **)&v18,
      flags_4: (const struct GASNameFunction *)GFx_BitmapDataFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgc + 3));
  }
  else
  {
    v12 = nullptr;
  }
  if ( v12 != nullptr )
    v12[2].__vftable = (IUnknown_vtbl *)(((int)&v12[2].QueryInterface + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 30, a4: (int)v12);
  Deref = v2[56].Deref;
  HIBYTE(pgc) = 0;
  v19 = *(_DWORD *)(Deref + 16);
  v15 = GASValue::GASValue(this: v17, a2: (int)v2, a3: v9);
  (*(void (__thiscall **)(unsigned int, CTSQueue<CFunctor *,0,1>::Node_t *, const char **, GASValue *, char *))(v19 + 40))(
    a1: v2[56].Deref + 16,
    a2: &v18,
    a3: &v2[10].MaxVal,
    a4: v15,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v17, a2: (int)v2);
  if ( v12 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v12, a2: (int)v2);
  return v9;
}
