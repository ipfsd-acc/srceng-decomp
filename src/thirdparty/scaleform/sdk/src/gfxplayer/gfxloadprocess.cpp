// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxloadprocess.cpp
// Functions: 40
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxloadprocess.h"

//------------------------------------------------------------------------------
// Address: 0x100DB390
// Name: public: void GFxLoadProcess::ReadRgbaTag(class GColor __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::ReadRgbaTag(_DWORD *this, struct GColor *pc, int a3)
{
  GFxStream *v3; // eax

  v3 = (GFxStream *)*(this + 201);
  if ( a3 > 22 )
  {
    if ( v3 == nullptr )
      v3 = (GFxStream *)(this + 10);
    GFxStream::ReadRgba(this: v3, a2: pc);
  }
  else
  {
    if ( v3 == nullptr )
      v3 = (GFxStream *)(this + 10);
    GFxStream::ReadRgb(this: v3, a2: pc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB400
// Name: public: class GFxImageCreator __near * GFxLoadStates::GetLoadTimeImageCreator(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
struct GFxImageCreator *__thiscall GFxLoadStates::GetLoadTimeImageCreator(GFxLoadStates *this, char a2)
{
  struct GFxImageCreator *result; // eax
  int v3; // ecx

  result = nullptr;
  if ( a2 >= 0 )
  {
    v3 = *(_DWORD *)(*((_DWORD *)this + 2) + 16);
    if ( v3 != 0 && *(_BYTE *)(v3 + 12) == 0 )
      return (struct GFxImageCreator *)v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DB420
// Name: public: void GFxLoadStates::SetRelativePathForDataDef(class GFxMovieDataDef __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadStates::SetRelativePathForDataDef(GFxLoadStates *this, struct GFxMovieDataDef *pdef)
{
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v2; // esi
  const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  char v4; // al

  v2 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 64);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 64),
    a2: (unsigned __int8 *)((*(_DWORD *)(*((_DWORD *)pdef + 8) + 36) & 0xFFFFFFFC) + 8));
  GFxURLBuilder::ExtractFilePath(ppath: v3, a2: v2);
  if ( v4 == 0 )
    GString::Clear(this: (GString *)v2);
}

//------------------------------------------------------------------------------
// Address: 0x100DB460
// Name: public: class GFile __near * GFxLoadStates::OpenFile(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFile *__thiscall GFxLoadStates::OpenFile(GFxLoadStates *this, const char *a2, unsigned int loadConstants)
{
  GFxLogBase<GFxLog> *v4; // esi
  IShaderAPI *v6; // edi
  char v7; // bl
  IShaderDevice *v8; // ecx
  int v9; // esi
  IShaderAPI *loadConstantsa; // [esp+14h] [ebp+Ch]

  if ( *(_DWORD *)(*((_DWORD *)this + 2) + 8) != 0 )
  {
    if ( (loadConstants & 0x200000) != 0 )
    {
      loadConstantsa = nullptr;
      v6 = nullptr;
      v7 = 1;
    }
    else
    {
      v8 = *((IShaderDevice **)this + 3);
      v7 = 2;
      if ( v8 != nullptr )
        GRefCountImpl::AddRef(this: v8);
      v6 = *((IShaderAPI **)this + 3);
      loadConstantsa = v6;
    }
    v9 = (*(int (__thiscall **)(_DWORD, const char *, IShaderAPI *, int, int))(**(_DWORD **)(*((_DWORD *)this + 2) + 8)
                                                                             + 12))(
           a1: *(_DWORD *)(*((_DWORD *)this + 2) + 8),
           a2,
           a3: loadConstantsa,
           a4: 33,
           a5: 438);
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      if ( v6 != nullptr )
        GRefCountImpl::Release(this: v6);
    }
    if ( (v7 & 1) != 0 && loadConstantsa != nullptr )
      GRefCountImpl::Release(this: loadConstantsa);
    return (struct GFile *)v9;
  }
  else
  {
    v4 = *((GFxLogBase<GFxLog> **)this + 3);
    if ( v4 != nullptr && (loadConstants & 0x200000) == 0 )
      GFxLogBase<GFxLog>::LogError(
        this: v4 + 3,
        pfmt: "Error: GFxLoader failed to open '%s', GFxFileOpener not installed\n",
        a2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB520
// Name: public: void GFxLoadStates::BuildURL(class GString __near *,struct GFxURLBuilder::LocationInfo const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxLoadStates::BuildURL(
        int a1@<ecx>,
        int a2@<edi>,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result,
        int loc)
{
  int v4; // ecx

  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 12);
  if ( v4 != 0 )
    (*(void (__thiscall **)(int, CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *, int))(*(_DWORD *)v4 + 4))(
      a1: v4,
      a2: result,
      a3: loc);
  else
    GFxURLBuilder::DefaultBuildURL(a1: a2, a2: result, loc);
}

//------------------------------------------------------------------------------
// Address: 0x100DB550
// Name: public: bool GFxLoadStates::SubmitBackgroundTask(class GFxLoaderTask __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadStates::SubmitBackgroundTask(CP4Factory *this, int ptask)
{
  int v2; // ecx

  v2 = *((_DWORD *)this + 6);
  if ( v2 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: ptask);
}

//------------------------------------------------------------------------------
// Address: 0x100DB580
// Name: public: bool GFxLoadProcess::BeginSWFLoading(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxLoadProcess::BeginSWFLoading(GFxAmpMsgHandler *this, IShaderDevice *pfile)
{
  char result; // al

  result = GFxSWFProcessInfo::Initialize(
             this: (GFxStream *)this + 10,
             a2: pfile,
             a3: *(GFxLog **)(this->RecvName.HeapTypeBits + 12),
             a4: *(struct GFxZlibSupportBase **)(this->RecvName.HeapTypeBits + 40),
             a5: *(struct GFxParseControl **)(this->RecvName.HeapTypeBits + 16),
             parseMsg: 1);
  if ( result != 0 )
  {
    GFxMovieDataDef::LoadTaskData::BeginSWFLoading(
      this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)this + 8),
      header: (int)this + 632);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DB6A0
// Name: public: GFxSubImageResource::GFxSubImageResource(class GFxImageResource __near *,class GFxResourceId,class GRect<int> const __near &,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxSubImageResource::GFxSubImageResource(void *this, _DWORD *a2, int a3, int *a4, int a5)
{
  int v6; // ecx
  GRefCountNTSImpl *v7; // edi
  int v8; // ebx
  GRefCountNTSImpl *v9; // ecx
  int v10; // edi
  int v11; // edx
  int v12; // eax

  v6 = a2[3];
  if ( v6 != 0 )
    v7 = (GRefCountNTSImpl *)(*(int (__thiscall **)(int, int *, int))(*(_DWORD *)v6 + 24))(a1: v6, a2: a4, a3: a5);
  else
    v7 = nullptr;
  v8 = (*(int (__thiscall **)(_DWORD *))(*a2 + 20))(a1: a2);
  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *(_DWORD *)this = &GFxImageResource::`vftable';
  *((_DWORD *)this + 3) = 0;
  GFxResourceKey::GFxResourceKey(this: (GFxValue *)this + 1);
  if ( v7 != nullptr )
    ++v7->RefCount;
  v9 = *((GRefCountNTSImpl **)this + 3);
  if ( v9 != nullptr )
    GRefCountNTSImpl::Release(this: v9);
  *((_DWORD *)this + 3) = v7;
  *((_DWORD *)this + 6) = v8;
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  *(_DWORD *)this = &GFxSubImageResource::`vftable';
  v10 = a4[1];
  v11 = a4[2];
  v12 = *a4;
  *((_DWORD *)this + 10) = a4[3];
  *((_DWORD *)this + 8) = v10;
  *((_DWORD *)this + 7) = v12;
  *((_DWORD *)this + 9) = v11;
  *((_DWORD *)this + 11) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DB750
// Name: public: virtual class GFxResourceId GFxSubImageResource::GetBaseImageId(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxResourceId __thiscall GFxSubImageResource::GetBaseImageId(GFxSubImageResource *this, _DWORD *a2)
{
  *a2 = *(this + 11);
  return (struct GFxResourceId)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100DB7B0
// Name: private: virtual bool GFxImageFileResourceCreator::CreateResource(void __near *,struct GFxResourceBindData __near *,class GFxLoadStates __near *,class GMemoryHeap __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxImageFileResourceCreator::CreateResource(
        GFxImageFileResourceCreator *this,
        GRefCountNTSImpl *a2,
        IShaderDevice **a3,
        int a4,
        struct GMemoryHeap *a5)
{
  GFxResourceFileInfo *v5; // eax
  GFxResourceFileInfo *v7; // esi
  GFxResourceFileInfo *v8; // ebx
  unsigned int *HighPart; // eax
  int v10; // esi
  int v11; // ecx
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // eax
  struct GImageInfoBase *v17; // edi
  int (__thiscall *v18)(int, int, int *); // eax
  GFxImageResource *v19; // eax
  struct GFxResource *v20; // eax
  IShaderDevice *v21; // ebx
  unsigned __int8 *Error; // eax
  void *v23; // esi
  void *v24; // esi
  void *v25; // esi
  void *v27; // esi
  void *v28; // esi
  void *v29; // esi
  int v30; // [esp+0h] [ebp-60h]
  int v31; // [esp+Ch] [ebp-54h] BYREF
  enum GFxResource::ResourceUse v32; // [esp+10h] [ebp-50h]
  unsigned int v33; // [esp+14h] [ebp-4Ch]
  int v34; // [esp+18h] [ebp-48h]
  struct GFxFileOpener *v35; // [esp+1Ch] [ebp-44h]
  int v36; // [esp+20h] [ebp-40h]
  int v37; // [esp+24h] [ebp-3Ch]
  int v38; // [esp+28h] [ebp-38h]
  int v39; // [esp+2Ch] [ebp-34h]
  int v40; // [esp+30h] [ebp-30h]
  int v41; // [esp+34h] [ebp-2Ch]
  char v42; // [esp+38h] [ebp-28h]
  int v43; // [esp+3Ch] [ebp-24h] BYREF
  int v44; // [esp+40h] [ebp-20h] BYREF
  int v45; // [esp+44h] [ebp-1Ch] BYREF
  struct GFxResourceKey src; // [esp+48h] [ebp-18h] BYREF
  GFxResourceLib::BindHandle v47; // [esp+50h] [ebp-10h] BYREF
  int v48; // [esp+58h] [ebp-8h] BYREF
  int v49; // [esp+5Ch] [ebp-4h] BYREF
  struct GFxFileOpener *v50; // [esp+68h] [ebp+8h]

  v48 = 2;
  v5 = (GFxResourceFileInfo *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v48);
  v7 = v5;
  if ( v5 != nullptr )
  {
    GFxResourceFileInfo::GFxResourceFileInfo(this: v5, src: (_PROCESS_INFORMATION *)a2);
    v7->dwSize = (unsigned int)&GFxImageFileInfo::`vftable';
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v7[1].___u2);
    *(_WORD *)&v7->ObjectId.Data4[4] = a2[2].RefCount;
    *(_WORD *)&v7->ObjectId.Data4[6] = HIWORD(a2[2].RefCount);
    v8 = v7;
    v7[1].dwSize = (unsigned int)a2[3].__vftable;
    v50 = (struct GFxFileOpener *)v7;
  }
  else
  {
    v50 = nullptr;
    v8 = nullptr;
  }
  if ( v8->FileId.LowPart == 1 )
  {
    HighPart = (unsigned int *)v8->FileId.HighPart;
    if ( HighPart != nullptr )
      v8->FileId.LowPart = *HighPart;
  }
  v43 = 2;
  GString::GString(this: (CCountedStringPoolBase<unsigned int> *)&v44, result: (CImagePacker *)&a2[2]);
  v10 = a4;
  GString::GString(this: (CCountedStringPoolBase<unsigned int> *)&v45, result: (CImagePacker *)(a4 + 64));
  v11 = *(_DWORD *)(*(_DWORD *)(v10 + 8) + 12);
  if ( v11 != 0 )
    (*(void (__thiscall **)(int, unsigned __int8 *, int *))(*(_DWORD *)v11 + 4))(
      a1: v11,
      a2: v8->ObjectId.Data4,
      a3: &v43);
  else
    GFxURLBuilder::DefaultBuildURL(
      a1: (int)a2,
      a2: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v8->ObjectId.Data4,
      loc: (int)&v43);
  v12 = *(_DWORD *)(*(_DWORD *)(v10 + 56) + 40);
  GFxImageResource::CreateImageFileKey(
    a1: &src,
    a2: v50,
    a3: *(struct GFxImageCreator **)(*(_DWORD *)(v10 + 8) + 8),
    a4: *(struct GMemoryHeap **)(*(_DWORD *)(v10 + 8) + 16));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v49);
  v13 = *(_DWORD *)(v10 + 56);
  v47.State = RS_Unbound;
  v47.pResource = nullptr;
  a4 = 0;
  if ( GFxResourceWeakLib::BindResourceKey(this: v13, result: (ShaderDeviceInfo_t *)&v47, a3: (int)&src) == 3 )
  {
    v14 = a2[3].RefCount & 1;
    v32 = (enum GFxResource::ResourceUse)a2[3].__vftable;
    v34 = v14;
    v35 = v50;
    v15 = *(_DWORD *)(v10 + 8);
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    v33 = 0;
    v42 = 0;
    v31 = 2;
    v41 = v12;
    v36 = *(_DWORD *)(v15 + 8);
    v37 = *(_DWORD *)(v10 + 32);
    v38 = *(_DWORD *)(v10 + 12);
    v39 = *(_DWORD *)(v10 + 36);
    v40 = *(_DWORD *)(v10 + 44);
    if ( *(_BYTE *)(v10 + 68) != 0 || (v42 = 0, *(_DWORD *)(v10 + 24) != 0) )
      v42 = 1;
    v33 = ((int)a2[4].__vftable & 0xFFFFFFFC) + 8;
    v16 = *(_DWORD *)(v15 + 16);
    v17 = nullptr;
    if ( v16 != 0
      && (v17 = (struct GImageInfoBase *)(*(int (__thiscall **)(int, int *))(*(_DWORD *)v16 + 4))(a1: v16, a2: &v31)) != nullptr )
    {
      v18 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v41 + 40);
      a4 = 2;
      v19 = (GFxImageResource *)v18(a1: v41, a2: 28, a3: &a4);
      if ( v19 != nullptr )
        v20 = (struct GFxResource *)GFxImageResource::GFxImageResource(
                                      this: v19,
                                      a2: v17,
                                      (IShaderDevice *)&src,
                                      a4: v32);
      else
        v20 = nullptr;
      v21 = (IShaderDevice *)v20;
      if ( v20 != nullptr )
      {
        GFxResourceLib::ResourceSlot::Resolve(this: v47.pSlot, a2: v20);
        goto LABEL_23;
      }
    }
    else
    {
      v21 = (IShaderDevice *)a4;
    }
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v49,
      a2: "Failed to load image '");
    GString::operator+=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v49,
      src: (int *)&v50[1].RefCount,
      srcSize: v30);
    GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&v49, putf8str: (CImagePacker *)"'", utf8StrSz: -1);
    GFxResourceLib::ResourceSlot::CancelResolve(this: v47.pSlot, a2: (const char *)((v49 & 0xFFFFFFFC) + 8));
LABEL_23:
    if ( v17 != nullptr )
      GRefCountNTSImpl::Release(this: v17);
    goto LABEL_30;
  }
  a4 = (int)GFxResourceLib::BindHandle::WaitForResolve(this: &v47);
  if ( a4 != 0 )
  {
    v21 = (IShaderDevice *)a4;
    goto LABEL_45;
  }
  if ( v47.State < RS_WaitingResolve )
    Error = (unsigned __int8 *)&pMem;
  else
    Error = (unsigned __int8 *)GFxResourceLib::ResourceSlot::GetError(this: (CUtlBinaryBlock *)v47.pResource);
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v49, a2: Error);
  v21 = (IShaderDevice *)a4;
LABEL_30:
  if ( v21 == nullptr )
  {
    GFxLogBase<GFxLog>::LogError(
      this: (GFxLogBase<GFxLog> *)(*(_DWORD *)(v10 + 12) + 12),
      pfmt: "Error: %s\n",
      (const char *)((v49 & 0xFFFFFFFC) + 8));
    if ( v47.State == RS_Available )
    {
      GFxResource::Release(this: (IShaderDevice *)v47.pResource);
    }
    else if ( v47.State >= RS_WaitingResolve )
    {
      GRefCountImpl::Release(this: (IShaderAPI *)v47.pResource);
    }
    v23 = (void *)(v49 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v49 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v23);
    if ( src.pKeyInterface != nullptr )
      src.pKeyInterface->Release(this: src.pKeyInterface, a2: src.hKeyData);
    v24 = (void *)(v45 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v45 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v24);
    v25 = (void *)(v44 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v44 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v50);
    return 0;
  }
LABEL_45:
  GRefCountImpl::AddRef(this: v21);
  if ( *a3 != nullptr )
    GFxResource::Release(this: *a3);
  *a3 = v21;
  GFxResource::Release(this: v21);
  if ( v47.State == RS_Available )
  {
    GFxResource::Release(this: (IShaderDevice *)v47.pResource);
  }
  else if ( v47.State >= RS_WaitingResolve )
  {
    GRefCountImpl::Release(this: (IShaderAPI *)v47.pResource);
  }
  v27 = (void *)(v49 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v49 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v27);
  if ( src.pKeyInterface != nullptr )
    src.pKeyInterface->Release(this: src.pKeyInterface, a2: src.hKeyData);
  v28 = (void *)(v45 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v45 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
  v29 = (void *)(v44 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v44 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v29);
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v50);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DBBB0
// Name: public: static class GFxResourceData GFxImageFileResourceCreator::CreateImageFileResourceData(struct GFxImageFileInfo __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl GFxImageFileResourceCreator::CreateImageFileResourceData(_DWORD *a1, int a2)
{
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    dword_1035982C = (int)&GFxImageFileResourceCreator::`vftable';
    atexit(func: (void (__cdecl *)())GFxImageFileResourceCreator::CreateImageFileResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  (*(void (__thiscall **)(int *, int))(dword_1035982C + 4))(a1: &dword_1035982C, a2);
  a1[1] = a2;
  *a1 = &dword_1035982C;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100DBC00
// Name: private: virtual bool GFxImageResourceCreator::CreateResource(void __near *,struct GFxResourceBindData __near *,class GFxLoadStates __near *,class GMemoryHeap __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxImageResourceCreator::CreateResource(
        GFxImageResourceCreator *this,
        int a2,
        IShaderDevice **a3,
        struct GFxLoadStates *a4,
        struct GMemoryHeap *a5)
{
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  struct GMemoryHeap *v9; // esi
  int v10; // edx
  int v11; // ecx
  struct GImageInfoBase *v13; // edi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GFxImageResource *v15; // eax
  IShaderDevice *v16; // eax
  IShaderDevice *v17; // esi
  IShaderDevice **v18; // ebx
  _DWORD v19[11]; // [esp+8h] [ebp-30h] BYREF
  char v20; // [esp+34h] [ebp-4h]

  v19[0] = 1;
  v19[3] = 1;
  v5 = *((_DWORD *)a4 + 8);
  v19[4] = a2;
  v6 = *((_DWORD *)a4 + 3);
  v19[6] = v5;
  v7 = *((_DWORD *)a4 + 9);
  v19[7] = v6;
  v8 = *((_DWORD *)a4 + 11);
  v19[2] = 0;
  v19[1] = 0;
  v19[5] = 0;
  v19[8] = v7;
  v19[9] = v8;
  if ( *((_BYTE *)a4 + 68) != 0 || (v20 = 0, *((_DWORD *)a4 + 6) != 0) )
    v20 = 1;
  v9 = a5;
  v10 = *((_DWORD *)a4 + 2);
  v19[10] = a5;
  v11 = *(_DWORD *)(v10 + 16);
  if ( v11 == 0 )
    return 0;
  v13 = (struct GImageInfoBase *)(*(int (__thiscall **)(int, _DWORD *))(*(_DWORD *)v11 + 4))(a1: v11, a2: v19);
  if ( v13 == nullptr )
    return 0;
  Alloc_2 = v9->Alloc_2;
  a2 = 2;
  v15 = (GFxImageResource *)Alloc_2(this: v9, a2: 28u, a3: (const GAllocDebugInfo *)&a2);
  if ( v15 == nullptr
    || (v16 = (IShaderDevice *)GFxImageResource::GFxImageResource(this: v15, a2: v13, a3: Use_Bitmap),
        v17 = v16,
        v16 == nullptr) )
  {
    GRefCountNTSImpl::Release(this: v13);
    return 0;
  }
  GRefCountImpl::AddRef(this: v16);
  v18 = a3;
  if ( *a3 != nullptr )
    GFxResource::Release(this: *a3);
  *v18 = v17;
  GFxResource::Release(this: v17);
  GRefCountNTSImpl::Release(this: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DBCF0
// Name: public: static class GFxResourceData GFxImageResourceCreator::CreateImageResourceData(class GImage __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl GFxImageResourceCreator::CreateImageResourceData(_DWORD *a1, int a2)
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    dword_10359834 = (int)&GFxImageResourceCreator::`vftable';
    atexit(func: (void (__cdecl *)())GFxImageResourceCreator::CreateImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  if ( a2 != 0 )
  {
    (*(void (__thiscall **)(int *, int))(dword_10359834 + 4))(a1: &dword_10359834, a2);
    a1[1] = a2;
    *a1 = &dword_10359834;
  }
  else
  {
    *a1 = 0;
    a1[1] = 0;
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100DBD60
// Name: private: virtual bool GFxSubImageResourceCreator::CreateResource(void __near *,struct GFxResourceBindData __near *,class GFxLoadStates __near *,class GMemoryHeap __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxSubImageResourceCreator::CreateResource@<al>(
        VertexShaderHandle_t__ *a1@<esi>,
        _DWORD *a2,
        int a3,
        struct GFxLoadStates *a4,
        struct GMemoryHeap *a5)
{
  int v6; // ebx
  _DWORD *v8; // eax
  unsigned int v9; // eax
  unsigned int Resource; // eax
  _DWORD *v11; // esi
  int v12; // esi
  struct GMemoryHeap *v13; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  void *v15; // eax
  void *v16; // esi
  int phandle; // [esp+Ch] [ebp-8h] BYREF
  IShaderDevice *v19; // [esp+10h] [ebp-4h]
  _DWORD *v20; // [esp+1Ch] [ebp+8h]

  v6 = a3;
  v8 = (_DWORD *)a2[3];
  v20 = v8;
  if ( v8 == nullptr )
  {
    v9 = a2[2];
    phandle = 0;
    v19 = nullptr;
    GFxMovieDataDef::LoadTaskData::GetResourceHandle(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 4) + 40) + 28) + 12) + 32),
      &phandle,
      rid: v9);
    Resource = GFxResourceHandle::GetResource(
                 this: (GFxResourceHandle *)&phandle,
                 a2: a1,
                 pbinding: *(struct GFxResourceBinding **)(v6 + 4));
    v11 = (_DWORD *)Resource;
    if ( Resource != 0
      && ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)Resource + 8))(a1: Resource) & 0xFF00) == 0x100 )
    {
      v20 = v11;
    }
    if ( phandle == 0 && v19 != nullptr )
      GFxResource::Release(this: v19);
    if ( v20 == nullptr )
      return 0;
    v8 = v20;
  }
  v12 = v8[3];
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 32))(a1: v12) == 0 )
    GImageInfo::SetTextureUsage(this: v12, result: nullptr);
  v13 = a5;
  Alloc_2 = a5->Alloc_2;
  a3 = 2;
  v15 = Alloc_2(this: a5, a2: 48u, (const GAllocDebugInfo *)&a3);
  if ( v15 != nullptr )
    v16 = GFxSubImageResource::GFxSubImageResource(this: v15, a2: v20, a3: 0, a4: a2 + 4, a5: (int)v13);
  else
    v16 = nullptr;
  if ( *(_DWORD *)v6 != 0 )
    GFxResource::Release(this: *(IShaderDevice **)v6);
  *(_DWORD *)v6 = v16;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DBE60
// Name: public: static class GFxResourceData GFxSubImageResourceCreator::CreateSubImageResourceData(struct GFxSubImageResourceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl GFxSubImageResourceCreator::CreateSubImageResourceData(_DWORD *a1, int a2)
{
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    dword_1035983C = (int)&GFxSubImageResourceCreator::`vftable';
    atexit(func: (void (__cdecl *)())GFxSubImageResourceCreator::CreateSubImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  (*(void (__thiscall **)(int *, int))(dword_1035983C + 4))(a1: &dword_1035983C, a2);
  a1[1] = a2;
  *a1 = &dword_1035983C;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100DC010
// Name: private: virtual bool GFxFontResourceCreator::CreateResource(void __near *,struct GFxResourceBindData __near *,class GFxLoadStates __near *,class GMemoryHeap __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxFontResourceCreator::CreateResource(
        GFxFontResourceCreator *this,
        IShaderDevice *a2,
        struct GFxResourceBindData *a3,
        struct GFxLoadStates *a4,
        struct GMemoryHeap *a5)
{
  struct GFxLoadStates *v5; // edx
  unsigned int v6; // ecx
  _DWORD *v7; // ebx
  _DWORD *v8; // edi
  int v9; // esi
  int v10; // eax
  char *v11; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  GFxFontResource *v13; // eax
  GFxFontResource *v14; // edi
  int v15; // ecx
  char v16; // dl
  unsigned int v17; // ebx
  int v18; // ecx
  int v19; // esi
  char *v21; // [esp-4h] [ebp-1Ch]
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]

  v5 = a4;
  v6 = 0;
  v24 = 0;
  if ( *((_DWORD *)a4 + 19) != 0 )
  {
    while ( 1 )
    {
      v23 = *(_DWORD *)(*((_DWORD *)v5 + 18) + 4 * v6);
      v7 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v23 + 28) + 12) + 32) + 164);
      if ( v7 != nullptr )
        break;
LABEL_8:
      v24 = ++v6;
      if ( v6 >= *((_DWORD *)v5 + 19) )
        goto LABEL_9;
    }
    while ( 1 )
    {
      v8 = (_DWORD *)v7[1];
      if ( (*(int (__thiscall **)(_DWORD *))(*v8 + 56))(a1: v8) != 0 )
      {
        v9 = v8[5] & 0x303;
        v10 = (*(int (__thiscall **)(_DWORD *))(*v8 + 60))(a1: v8);
        if ( ((int)a2[5].__vftable & (v9 & 0x10 | ((v9 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v9 & 0x313) )
        {
          v21 = (char *)v10;
          v11 = (char *)((int (__thiscall *)(IShaderDevice *))a2->SetView)(a1: a2);
          if ( GString::CompareNoCase(a1: v11, a2: v21) == 0 )
            break;
        }
      }
      v7 = (_DWORD *)v7[3];
      if ( v7 == nullptr )
      {
        v6 = v24;
        v5 = a4;
        goto LABEL_8;
      }
    }
    v15 = *(_DWORD *)(v23 + 28);
    v16 = *(_BYTE *)(v15 + 60);
    v17 = v7[2];
    v18 = v15 + 24;
    if ( v16 != 0 && v17 < *(_DWORD *)(v18 + 4) )
    {
      v19 = *(_DWORD *)(v18 + 8) + 8 * v17;
      if ( *(_DWORD *)v19 != 0 )
        GRefCountImpl::AddRef(this: *(IShaderDevice **)v19);
      if ( *(_DWORD *)a3 != 0 )
        GFxResource::Release(this: *(IShaderDevice **)a3);
      *(_DWORD *)a3 = *(_DWORD *)v19;
      *((_DWORD *)a3 + 1) = *(_DWORD *)(v19 + 4);
      return true;
    }
    else
    {
      GFxResourceBinding::GetResourceData_Locked(this: (GFxResourceBinding *)v18, a2: (IShaderDevice **)a3, a3: v17);
      return true;
    }
  }
  else
  {
LABEL_9:
    if ( ((unsigned __int8 (__thiscall *)(IShaderDevice *))a2->CompileShader)(a1: a2) == 0
      && ((int (__thiscall *)(IShaderDevice *))a2->SetView)(a1: a2) != 0 )
    {
      a2[5].__vftable = (IShaderDevice_vtbl *)((int)a2[5].__vftable | 0x40);
    }
    if ( *(_DWORD *)a3 == 0 )
    {
      Alloc_2 = a5->Alloc_2;
      v22 = 2;
      v13 = (GFxFontResource *)Alloc_2(this: a5, a2: 44u, a3: (const GAllocDebugInfo *)&v22);
      if ( v13 != nullptr )
        v14 = GFxFontResource::GFxFontResource(this: v13, a2, pbinding: *((_RATE_QUOTA_LIMIT **)a3 + 1));
      else
        v14 = nullptr;
      if ( *(_DWORD *)a3 != 0 )
        GFxResource::Release(this: *(IShaderDevice **)a3);
      *(_DWORD *)a3 = v14;
    }
    return *(_DWORD *)a3 != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC1B0
// Name: public: virtual GFxLoadProcess::~GFxLoadProcess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::~GFxLoadProcess(GFxLoadProcess *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  int v3; // eax
  int v4; // edi
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx
  GFxLoadProcess *v7; // edi
  int i; // ebx
  void *v9; // edx
  IShaderAPI *v10; // ecx
  IShaderAPI *v11; // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*(this + 177);
  *this = (GFxLoadProcess)&GFxLoadProcess::`vftable'{for `GFxLoaderTask'};
  *(this + 5) = (GFxLoadProcess)&GFxLoadProcess::`vftable'{for `GFxLogBase<GFxLoadProcess>'};
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  v3 = (int)*(this + 8);
  v4 = *(_DWORD *)(v3 + 144);
  if ( v4 != 0 )
    GRefCountImpl::AddRef(this: *(IShaderDevice **)(v3 + 144));
  GFxStream::ShutDown(this: (GFxStream *)this + 10);
  v5 = (IShaderAPI *)*(this + 8);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  *(this + 8) = nullptr;
  v6 = (IShaderAPI *)*(this + 7);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  *(this + 7) = nullptr;
  GMutex::Lock(this: (IMatRenderContextInternal *)(v4 + 8));
  *(_BYTE *)(v4 + 32) = 1;
  GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(v4 + 28));
  GMutex::Unlock(this: (IMatRenderContextInternal *)(v4 + 8));
  GRefCountImpl::Release(this: (IShaderAPI *)v4);
  v7 = this + 198;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(this + 198));
  for ( i = 1; i >= 0; --i )
  {
    v9 = *(v7 - 3);
    v7 -= 3;
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
  }
  GFxExporterInfoImpl::~GFxExporterInfoImpl(this: (void **)this + 167);
  GFxStream::~GFxStream(this: (GFxStream *)this + 10);
  v10 = (IShaderAPI *)*(this + 8);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  v11 = (IShaderAPI *)*(this + 7);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  *(this + 5) = (GFxLoadProcess)&GFxLogBase<GFxLoadProcess>::`vftable';
  GFxLoaderTask::~GFxLoaderTask((CTSQueue<CFunctor *,0,1>::Node_t *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100DC2C0
// Name: public: virtual void GFxLoadProcess::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::Execute(GFxLoadProcess *this)
{
  GFxMovieDataDef::LoadTaskData::Read(
    this: (CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *)*(this + 8),
    a2: (struct GFxLoadProcess *)this,
    a3: (struct GFxMovieBindProcess *)*(this + 7));
}

//------------------------------------------------------------------------------
// Address: 0x100DC2D0
// Name: public: virtual void GFxLoadProcess::OnAbandon(bool)
// Source: json
//------------------------------------------------------------------------------
IMatRenderContextInternal **__thiscall GFxLoadProcess::OnAbandon(GFxAmpMessage *this, GString *result)
{
  IMatRenderContextInternal **v3; // eax

  if ( (_BYTE)result != 0 )
    GFxMovieDataDef::LoadTaskData::OnMovieDataDefRelease(this: *((GFxMovieDataDef::LoadTaskData **)this + 8));
  v3 = *((IMatRenderContextInternal ***)this + 7);
  if ( v3 != nullptr && (_BYTE)result == 0 )
  {
    v3 = (IMatRenderContextInternal **)v3[8];
    if ( v3 != nullptr )
      return (IMatRenderContextInternal **)GFxMovieDefImpl::BindTaskData::SetBindState(this: v3, newState: 3u);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100DC310
// Name: public: struct GFxFrameBindData __near * GFxLoadProcess::CreateFrameBindData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::CreateFrameBindData(GFxAmpCurrentState *this)
{
  GString *Data; // ecx
  unsigned int HeapTypeBits; // edx
  CP4File *v4; // ecx
  CP4File_vtbl *v5; // eax

  Data = this->Locales.Data.Data;
  HeapTypeBits = Data[3].HeapTypeBits;
  v4 = (CP4File *)&Data[2];
  if ( HeapTypeBits < 0x24 )
  {
    v5 = GFxDataAllocator::OverflowAlloc(this: v4, bytes: 0x24u);
  }
  else
  {
    v5 = v4->__vftable;
    v4->__vftable = (CP4File_vtbl *)((char *)v4->__vftable + 36);
    v4->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(HeapTypeBits - 36);
  }
  if ( v5 != nullptr )
  {
    v5->dtr_CP4File = nullptr;
    v5->Edit = nullptr;
    v5->Add = nullptr;
    v5->IsFileInPerforce = nullptr;
    v5[1].dtr_CP4File = nullptr;
    v5[1].Edit = nullptr;
    v5[1].Add = nullptr;
    v5[1].IsFileInPerforce = nullptr;
    v5[2].dtr_CP4File = nullptr;
    v5->IsFileInPerforce = *((bool (__thiscall **)(CP4File *))this + 181);
    v5[1].Edit = *((bool (__thiscall **)(CP4File *))this + 185);
    v5->Add = *((bool (__thiscall **)(CP4File *))this + 183);
    v5[1].Add = *((bool (__thiscall **)(CP4File *))this + 188);
    v5[1].dtr_CP4File = *((void (__thiscall **)(CP4File *))this + 182);
    v5[1].IsFileInPerforce = *((bool (__thiscall **)(CP4File *))this + 186);
    *((_DWORD *)this + 181) = 0;
    *((_DWORD *)this + 182) = 0;
    *((_DWORD *)this + 183) = 0;
    *((_DWORD *)this + 185) = 0;
    *((_DWORD *)this + 186) = 0;
    *((_DWORD *)this + 188) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC450
// Name: public: GFxLoadProcess::GFxLoadProcess(class GFxMovieDataDef __near *,class GFxLoadStates __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxLoadProcess *__thiscall GFxLoadProcess::GFxLoadProcess(
        GFxLoadProcess *this,
        GFxAmpMessage *pstates,
        IShaderDevice *pstates_4,
        GFxAmpMessage *loadFlags)
{
  IShaderDevice_vtbl *v5; // eax
  GFxAmpMessage *GetBackBufferDimensions; // eax
  IShaderDevice *pPrev; // ecx
  IShaderAPI *v8; // ecx

  GFxLoaderTask::GFxLoaderTask((void (__thiscall *)(IShaderDevice *))this, result: pstates_4, a3: 131073);
  *(this + 5) = (GFxLoadProcess)&GFxLogBase<GFxLoadProcess>::`vftable';
  *this = (GFxLoadProcess)&GFxLoadProcess::`vftable'{for `GFxLoaderTask'};
  *(this + 5) = (GFxLoadProcess)&GFxLoadProcess::`vftable'{for `GFxLogBase<GFxLoadProcess>'};
  *(this + 7) = nullptr;
  *(this + 8) = nullptr;
  GFxStream::GFxStream(
    this: (GFxStream *)this + 10,
    a2: nullptr,
    a3: (struct GMemoryHeap *)pstates[1].pPrev[1].RefCount,
    a4: nullptr,
    a5: nullptr);
  GFxMovieHeaderData::GFxMovieHeaderData(this: (GFxMovieHeaderData *)(this + 158));
  *(this + 192) = nullptr;
  *(this + 193) = nullptr;
  *(this + 194) = nullptr;
  *(this + 195) = nullptr;
  *(this + 196) = nullptr;
  *(this + 197) = nullptr;
  *(this + 198) = nullptr;
  *(this + 199) = nullptr;
  *(this + 200) = nullptr;
  v5 = pstates_4[4].__vftable;
  if ( v5 != nullptr )
    GetBackBufferDimensions = (GFxAmpMessage *)v5->GetBackBufferDimensions;
  else
    GetBackBufferDimensions = nullptr;
  *(this + 6) = GetBackBufferDimensions;
  pPrev = (IShaderDevice *)pstates[1].pPrev;
  if ( pPrev != nullptr )
    GRefCountImpl::AddRef(this: pPrev);
  v8 = (IShaderAPI *)*(this + 8);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  *(this + 8) = pstates[1].pPrev;
  *(this + 191) = nullptr;
  *(this + 177) = nullptr;
  *(this + 190) = nullptr;
  *(this + 179) = nullptr;
  *(this + 181) = nullptr;
  *(this + 182) = nullptr;
  *(this + 183) = nullptr;
  *(this + 184) = nullptr;
  *(this + 185) = nullptr;
  *(this + 187) = nullptr;
  *(this + 186) = nullptr;
  *(this + 189) = nullptr;
  *(this + 188) = nullptr;
  *(this + 201) = nullptr;
  *(this + 180) = nullptr;
  *(this + 178) = loadFlags;
  *(this + 9) = pstates;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DC5B0
// Name: public: struct GFxTimelineDef::Frame GFxLoadProcess::TagArrayToFrame(class GArray<class GASExecuteTag __near *,2,struct GArrayConstPolicy<32,16,0>> __near &)
// Source: json
//------------------------------------------------------------------------------
const GFxAmpMessage *__thiscall GFxLoadProcess::TagArrayToFrame(
        _DWORD *this,
        const GFxAmpMessage *result,
        GRefCountBase<GFxAmpMemItem,2> *a3)
{
  GRefCountBase<GFxAmpMemItem,2> *v3; // ebx
  volatile int RefCount; // eax
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // esi
  CP4File *v9; // ecx
  unsigned int v10; // eax
  CP4File_vtbl *v11; // esi
  unsigned __int8 *v12; // edx
  CP4File_vtbl *v13; // eax
  unsigned int memSize; // [esp+10h] [ebp+8h]

  v3 = a3;
  RefCount = a3->RefCount;
  result->__vftable = nullptr;
  result->RefCount = 0;
  if ( RefCount != 0 )
  {
    v6 = *(this + 8);
    v7 = *(_DWORD *)(v6 + 12);
    v8 = 4 * RefCount;
    v9 = (CP4File *)(v6 + 8);
    v10 = (4 * RefCount + 3) & 0xFFFFFFFC;
    memSize = v8;
    if ( v10 > v7 )
    {
      v13 = GFxDataAllocator::OverflowAlloc(this: v9, bytes: v10);
    }
    else
    {
      v11 = v9->__vftable;
      v12 = (unsigned __int8 *)(v7 - v10);
      v9->__vftable = (CP4File_vtbl *)((char *)v9->__vftable + v10);
      v3 = a3;
      v13 = v11;
      v8 = memSize;
      v9->m_sFilename.m_Storage.m_Memory.m_pMemory = v12;
    }
    result->__vftable = (GFxAmpMessage_vtbl *)v13;
    if ( v13 != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)v13, src: (unsigned __int8 *)v3->__vftable, count: v8);
      result->RefCount = v3->RefCount;
    }
    GArrayBase<GArrayData<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>>::Clear(this: v3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DC640
// Name: public: void GFxLoadProcess::CommitFrameTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::CommitFrameTags(GFxLoadProcess *this)
{
  int v2; // eax
  GFxAmpMessage_vtbl *v3; // edi
  const GFxAmpMessage *v4; // eax
  int *v5; // ebx
  int v6; // edi
  const GFxAmpMessage *v7; // eax
  int *v8; // ebx
  int v9; // edi
  const GFxAmpMessage *v10; // eax
  _BYTE v11[8]; // [esp+8h] [ebp-8h] BYREF

  v2 = (int)*(this + 190);
  if ( v2 == 1 )
  {
    v3 = (*(this + 191))->__vftable;
    v4 = GFxLoadProcess::TagArrayToFrame(
           this,
           result: (const GFxAmpMessage *)v11,
           a3: (GRefCountBase<GFxAmpMemItem,2> *)(this + 195));
    v3[2].ToString(this: *(this + 191), result: (GString *)v4);
  }
  else
  {
    v5 = (int *)*(this + 8);
    v6 = *v5;
    v7 = GFxLoadProcess::TagArrayToFrame(
           this,
           result: (const GFxAmpMessage *)v11,
           a3: (GRefCountBase<GFxAmpMemItem,2> *)(this + 3 * v2 + 192));
    (*(void (__thiscall **)(int *, const GFxAmpMessage *))(v6 + 8))(a1: v5, a2: v7);
    v8 = (int *)*(this + 8);
    v9 = *v8;
    v10 = GFxLoadProcess::TagArrayToFrame(
            this,
            result: (const GFxAmpMessage *)v11,
            a3: (GRefCountBase<GFxAmpMemItem,2> *)this + 99);
    (*(void (__thiscall **)(int *, const GFxAmpMessage *))(v9 + 12))(a1: v8, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC6D0
// Name: public: void GFxLoadProcess::CleanupFrameTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::CleanupFrameTags(GFxLoadProcess *this)
{
  unsigned int v2; // edi
  void (__thiscall ***v3)(_DWORD, _DWORD); // ecx
  unsigned int v4; // edi
  void (__thiscall ***v5)(_DWORD, _DWORD); // ecx
  unsigned int v6; // edi
  void (__thiscall ***v7)(_DWORD, _DWORD); // ecx
  void **v8; // edi
  GFxLoadProcess *v9; // edi
  GFxLoadProcess *v10; // esi
  GFxAmpMessage *v11; // eax
  int v12; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  if ( *(this + 196) != nullptr )
  {
    do
    {
      v3 = *((void (__thiscall ****)(_DWORD, _DWORD))&(*(this + 195))->__vftable + v2);
      (**v3)(a1: v3, a2: 0);
      ++v2;
    }
    while ( v2 < (unsigned int)*(this + 196) );
  }
  v4 = 0;
  if ( *(this + 193) != nullptr )
  {
    do
    {
      v5 = *((void (__thiscall ****)(_DWORD, _DWORD))&(*(this + 192))->__vftable + v4);
      (**v5)(a1: v5, a2: 0);
      ++v4;
    }
    while ( v4 < (unsigned int)*(this + 193) );
  }
  v6 = 0;
  if ( *(this + 199) != nullptr )
  {
    do
    {
      v7 = *((void (__thiscall ****)(_DWORD, _DWORD))&(*(this + 198))->__vftable + v6);
      (**v7)(a1: v7, a2: 0);
      ++v6;
    }
    while ( v6 < (unsigned int)*(this + 199) );
  }
  v8 = (void **)(this + 195);
  if ( *(this + 196) != nullptr )
  {
    if ( ((unsigned int)*(this + 197) & 0xFFFFFFFE) != 0 )
    {
      if ( *v8 != nullptr )
      {
        *v8 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *v8, a3: 128);
      }
      else
      {
        v12 = 2;
        *v8 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 128, a3: &v12);
      }
      *(this + 197) = (GFxLoadProcess)32;
    }
  }
  else if ( *(this + 197) == nullptr )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)(this + 195),
      result: (D3DXVECTOR4 *)(this + 195),
      newCapacity: 0);
  }
  *(this + 196) = nullptr;
  v9 = this + 192;
  if ( *(this + 193) != nullptr )
  {
    if ( ((unsigned int)*(this + 194) & 0xFFFFFFFE) != 0 )
    {
      if ( *v9 != nullptr )
      {
        *v9 = (GFxLoadProcess)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *v9, a3: 128);
      }
      else
      {
        v12 = 2;
        *v9 = (GFxLoadProcess)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 128, a3: &v12);
      }
      *(this + 194) = (GFxLoadProcess)32;
    }
  }
  else if ( *(this + 194) == nullptr )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)(this + 192),
      result: (D3DXVECTOR4 *)this + 48,
      newCapacity: 0);
  }
  v10 = this + 198;
  v9[1] = nullptr;
  if ( v10[1] == nullptr )
  {
    if ( v10[2] == nullptr )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v10,
        result: (D3DXVECTOR4 *)v10,
        newCapacity: 0);
    goto LABEL_31;
  }
  if ( ((unsigned int)v10[2] & 0xFFFFFFFE) == 0 )
  {
LABEL_31:
    v10[1] = nullptr;
    return;
  }
  if ( *v10 != nullptr )
  {
    v11 = (GFxAmpMessage *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: *v10, a3: 128);
  }
  else
  {
    v12 = 2;
    v11 = (GFxAmpMessage *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 128, a3: &v12);
  }
  v10[1] = nullptr;
  *v10 = v11;
  v10[2] = (GFxLoadProcess)32;
}

//------------------------------------------------------------------------------
// Address: 0x100DC8B0
// Name: public: class GFxResourceHandle GFxLoadProcess::AddDataResource(class GFxResourceId,class GFxResourceData const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLoadProcess::AddDataResource(
        int *this,
        _DWORD *a2,
        unsigned int a3,
        void (__thiscall **resData)(CP4File *this))
{
  int v5; // ecx
  unsigned int v6; // eax
  CP4File *v7; // ecx
  CP4File_vtbl *v8; // esi
  volatile LONG *v9; // eax
  int v11; // [esp+Ch] [ebp-4h]

  GFxMovieDataDef::LoadTaskData::AddNewResourceHandle(this: *(this + 8), a2, a3);
  v5 = *(this + 8);
  v6 = *(_DWORD *)(v5 + 12);
  v11 = v5;
  v7 = (CP4File *)(v5 + 8);
  if ( v6 < 0x10 )
  {
    v8 = GFxDataAllocator::OverflowAlloc(this: v7, bytes: 0x10u);
  }
  else
  {
    v8 = v7->__vftable++;
    v7->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v6 - 16);
  }
  if ( v8 == nullptr )
    return a2;
  v8->dtr_CP4File = nullptr;
  v8->Edit = nullptr;
  v8->IsFileInPerforce = nullptr;
  if ( *resData != nullptr )
    (*(void (__thiscall **)(void (__thiscall *)(CP4File *), void (__thiscall *)(CP4File *)))(*(_DWORD *)*resData + 4))(
      a1: *resData,
      a2: resData[1]);
  if ( v8->dtr_CP4File != nullptr )
    (*(void (__thiscall **)(void (__thiscall *)(CP4File *), bool (__thiscall *)(CP4File *)))(*(_DWORD *)v8->dtr_CP4File
                                                                                           + 8))(
      a1: v8->dtr_CP4File,
      a2: v8->Edit);
  v8->dtr_CP4File = *resData;
  v8->Edit = (bool (__thiscall *)(CP4File *))resData[1];
  v8->Add = (bool (__thiscall *)(CP4File *))a2[1];
  if ( *(this + 186) == 0 )
    *(this + 186) = (int)v8;
  v9 = (volatile LONG *)(v11 + 172);
  if ( *(_DWORD *)(v11 + 172) != 0 )
    v9 = (volatile LONG *)(*(_DWORD *)(v11 + 176) + 12);
  InterlockedExchange(Target: v9, Value: (LONG)v8);
  *(_DWORD *)(v11 + 176) = v8;
  ++*(this + 182);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100DC9A0
// Name: public: class GFxResourceHandle GFxLoadProcess::AddFontDataResource(class GFxResourceId,class GFxFont __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLoadProcess::AddFontDataResource(int *this, _DWORD *a2, unsigned int a3, IShaderDevice *a4)
{
  int v6; // ecx
  unsigned int v7; // eax
  CP4File *v8; // ecx
  CP4File_vtbl *v9; // esi
  IShaderAPI *Edit; // ecx
  volatile LONG *p_GetBackBufferDimensions; // eax
  _IMAGE_CE_RUNTIME_FUNCTION_ENTRY resData; // [esp+Ch] [ebp-8h] BYREF
  IShaderDevice *v14; // [esp+24h] [ebp+10h]

  ((void (__thiscall *)(void ***, IShaderDevice *))static_inst[1])(a1: &static_inst, a2: a4);
  resData.FuncStart = (unsigned int)&static_inst;
  *((_DWORD *)&resData + 1) = a4;
  GFxLoadProcess::AddDataResource(this, a2, a3, (void (__thiscall **)(CP4File *))&resData);
  v6 = *(this + 8);
  v7 = *(_DWORD *)(v6 + 12);
  v8 = (CP4File *)(v6 + 8);
  if ( v7 < 0x10 )
  {
    v9 = GFxDataAllocator::OverflowAlloc(this: v8, bytes: 0x10u);
  }
  else
  {
    v9 = v8->__vftable++;
    v8->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v7 - 16);
  }
  if ( v9 != nullptr )
  {
    v9->dtr_CP4File = (void (__thiscall *)(CP4File *))0x40000;
    v9->Edit = nullptr;
    v9->Add = nullptr;
    v9->IsFileInPerforce = nullptr;
    v14 = (IShaderDevice *)*(this + 8);
    v9->dtr_CP4File = (void (__thiscall *)(CP4File *))a3;
    if ( a4 != nullptr )
      GRefCountImpl::AddRef(this: a4);
    Edit = (IShaderAPI *)v9->Edit;
    if ( Edit != nullptr )
      GRefCountImpl::Release(this: Edit);
    v9->Edit = (bool (__thiscall *)(CP4File *))a4;
    v9->Add = (bool (__thiscall *)(CP4File *))a2[1];
    if ( *(this + 188) == 0 )
      *(this + 188) = (int)v9;
    p_GetBackBufferDimensions = (volatile LONG *)&v14[41];
    if ( v14[41].__vftable != nullptr )
      p_GetBackBufferDimensions = (volatile LONG *)&v14[42].GetBackBufferDimensions;
    InterlockedExchange(Target: p_GetBackBufferDimensions, Value: (LONG)v9);
    v14[42].__vftable = (IShaderDevice_vtbl *)v9;
    ++*(this + 183);
  }
  ((void (__thiscall *)(void ***, IShaderDevice *))static_inst[2])(a1: &static_inst, a2: a4);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100DCAB0
// Name: public: void GFxLoadProcess::AddImportData(class GFxImportData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::AddImportData(GFxLoadProcess *this, GFxAmpMessage *Value)
{
  int v3; // edi

  Value->Version = (unsigned int)*(this + 179);
  *(this + 179) = (GFxLoadProcess)((char *)*(this + 179) + 1);
  if ( *(this + 185) == nullptr )
    *(this + 185) = Value;
  v3 = (int)*(this + 8);
  if ( *(_DWORD *)(v3 + 156) != 0 )
    InterlockedExchange(Target: (volatile LONG *)(*(_DWORD *)(v3 + 160) + 24), (LONG)Value);
  else
    InterlockedExchange(Target: (volatile LONG *)(v3 + 156), (LONG)Value);
  *(_DWORD *)(v3 + 160) = Value;
  *(this + 181) = (GFxLoadProcess)((char *)*(this + 181) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100DCB20
// Name: public: void GFxLoadProcess::AddImageResource(class GFxResourceId,class GImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::AddImageResource(int this, const GFxAmpCurrentState *result, int a3)
{
  int v4; // eax
  bool v5; // zf
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // esi
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  struct GImageInfoBase *v14; // edi
  int (__thiscall *v15)(int, int, int *); // eax
  GFxImageResource *v16; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v17; // esi
  tagCBT_CREATEWNDW *icreateInfo; // [esp+Ch] [ebp-40h] BYREF
  int v19; // [esp+10h] [ebp-3Ch]
  int v20; // [esp+14h] [ebp-38h]
  int v21; // [esp+18h] [ebp-34h]
  int v22; // [esp+1Ch] [ebp-30h]
  int v23; // [esp+20h] [ebp-2Ch]
  int v24; // [esp+24h] [ebp-28h]
  int v25; // [esp+28h] [ebp-24h]
  int v26; // [esp+2Ch] [ebp-20h]
  int v27; // [esp+30h] [ebp-1Ch]
  int v28; // [esp+34h] [ebp-18h]
  char v29; // [esp+38h] [ebp-14h]
  _IMAGE_CE_RUNTIME_FUNCTION_ENTRY rdata; // [esp+3Ch] [ebp-10h] BYREF
  int v31; // [esp+44h] [ebp-8h] BYREF
  IShaderDevice *v32; // [esp+48h] [ebp-4h]

  v4 = *(_DWORD *)(this + 16);
  v5 = *(_BYTE *)(this + 712) >= 0;
  *((_DWORD *)&rdata + 1) = this;
  if ( v5
    && *(_DWORD *)((v6 = *(_DWORD *)(v4 + 8)) + 16) != 0
    && *(_BYTE *)((v7 = *(_DWORD *)(v6 + 16)) + 12) == 0
    && v7 != 0 )
  {
    v8 = *(_DWORD *)(this + 32);
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    icreateInfo = nullptr;
    v22 = 0;
    v20 = 0;
    v19 = 0;
    v21 = 1;
    v29 = 0;
    v28 = *(_DWORD *)(v8 + 28);
    v9 = *(_DWORD *)(v4 + 44);
    v10 = *(_DWORD *)(v4 + 36);
    v11 = *(_DWORD *)(v4 + 12);
    v12 = *(_DWORD *)(v4 + 32);
    v23 = 0;
    v24 = v12;
    v25 = v11;
    v26 = v10;
    v27 = v9;
    if ( *(_BYTE *)(v4 + 68) != 0 || (v5 = *(_DWORD *)(v4 + 24) == 0, v29 = 0, !v5) )
      v29 = 1;
    if ( a3 != 0 )
    {
      icreateInfo = (tagCBT_CREATEWNDW *)1;
      v22 = a3;
    }
    v13 = *(_DWORD *)(v4 + 8);
    if ( *(_DWORD *)(v13 + 16) != 0 )
      v14 = (struct GImageInfoBase *)(*(int (__thiscall **)(_DWORD, tagCBT_CREATEWNDW **))(**(_DWORD **)(v13 + 16) + 4))(
                                       a1: *(_DWORD *)(v13 + 16),
                                       a2: &icreateInfo);
    else
      v14 = nullptr;
    v15 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v28 + 40);
    a3 = 2;
    v16 = (GFxImageResource *)v15(a1: v28, a2: 28, &a3);
    if ( v16 != nullptr )
      v17 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxImageResource::GFxImageResource(this: v16, a2: v14, a3: Use_Bitmap);
    else
      v17 = nullptr;
    if ( *(_DWORD *)(*((_DWORD *)&rdata + 1) + 760) == 0 )
      GFxMovieDataDef::LoadTaskData::AddResource(
        this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(*((_DWORD *)&rdata + 1) + 32),
        rid: (unsigned int)result,
        pres: v17);
    if ( v17 != nullptr )
      GFxResource::Release(this: (IShaderDevice *)v17);
    if ( v14 != nullptr )
      GRefCountNTSImpl::Release(this: v14);
  }
  else
  {
    GFxImageResourceCreator::CreateImageResourceData(a1: &rdata, a2: a3);
    GFxLoadProcess::AddDataResource(
      (int *)this,
      a2: &v31,
      a3: (unsigned int)result,
      resData: (void (__thiscall **)(CP4File *))&rdata);
    if ( v31 == 0 && v32 != nullptr )
      GFxResource::Release(this: v32);
    if ( rdata.FuncStart != 0 )
      (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)rdata.FuncStart + 8))(
        a1: rdata.FuncStart,
        a2: *((_DWORD *)&rdata + 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCCB0
// Name: public: GFxLoadStates::GFxLoadStates(class GFxLoaderImpl __near *,class GFxStateBag __near *,class GFxMovieDefBindStates __near *)
// Source: json
//------------------------------------------------------------------------------
GFxLoadStates *__thiscall GFxLoadStates::GFxLoadStates(GFxLoadStates *this, IShaderDevice *pimpl, struct GFxStateBag *psharedState, struct GFxMovieDefBindStates *pother)
{
  IShaderAPI *v5; // ecx
  IShaderDevice *v6; // edi
  IShaderAPI *v7; // ecx
  struct GFxStateBag *v8; // edi
  CReferenceToHandleTexture *v9; // eax
  CReferenceToHandleTexture *v10; // eax
  CReferenceToHandleTexture *v11; // eax
  IShaderAPI *v12; // ecx
  IShaderDevice *v13; // eax
  IShaderAPI *v14; // ebx
  IShaderAPI *v15; // ecx
  IShaderDevice *v16; // eax
  IShaderAPI *v17; // ebx
  IShaderAPI *v18; // ecx
  IShaderDevice *v19; // eax
  IShaderAPI *v20; // ebx
  IShaderAPI *v21; // ecx
  IShaderDevice *v22; // eax
  IShaderAPI *v23; // ebx
  IShaderAPI *v24; // ecx
  IShaderDevice *v25; // eax
  IShaderAPI *v26; // ebx
  IShaderAPI *v27; // ecx
  IShaderDevice *v28; // eax
  IShaderAPI *v29; // ebx
  IShaderAPI *v30; // ecx
  IShaderDevice *v31; // eax
  IShaderAPI *v32; // ebx
  IShaderAPI *v33; // ecx
  IShaderDevice *v34; // eax
  IShaderAPI *v35; // ebx
  IShaderAPI *v36; // ecx
  IShaderDevice *v37; // eax
  IShaderAPI *v38; // ebx
  IShaderAPI *v39; // ecx
  IShaderDevice *v40; // eax
  IShaderAPI *v41; // ebx
  IShaderAPI *v42; // ecx
  IShaderDevice *v43; // eax
  IShaderAPI *v44; // edi
  IShaderAPI *v45; // ecx
  TextureBindFlags_t v47; // [esp+0h] [ebp-14h]
  int v48; // [esp+Ch] [ebp-8h] BYREF
  int v49; // [esp+10h] [ebp-4h] BYREF
  CReferenceToHandleTexture *pimpla; // [esp+1Ch] [ebp+8h]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxLoadStates::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 64));
  *((_BYTE *)this + 68) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  if ( pimpl != nullptr )
    GRefCountImpl::AddRef(this: pimpl);
  v5 = *((IShaderAPI **)this + 15);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  *((_DWORD *)this + 15) = pimpl;
  v6 = (IShaderDevice *)pimpl[6].__vftable;
  if ( v6 != nullptr )
    GRefCountImpl::AddRef(this: v6);
  v7 = *((IShaderAPI **)this + 14);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  *((_DWORD *)this + 14) = v6;
  v8 = psharedState;
  if ( psharedState == nullptr )
    v8 = (struct GFxStateBag *)&pimpl[2];
  if ( pother != nullptr )
  {
    v49 = 2;
    v9 = (CReferenceToHandleTexture *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v49);
    if ( v9 != nullptr )
    {
      pimpla = GFxMovieDefBindStates::GFxMovieDefBindStates(this: v9, (int *)pother, a3: v47);
      goto LABEL_17;
    }
  }
  else
  {
    v48 = 2;
    v10 = (CReferenceToHandleTexture *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v48);
    if ( v10 != nullptr )
    {
      GFxMovieDefBindStates::GFxMovieDefBindStates(this: v10, psharedState: (Sampler_t)v8, pstates: v47);
      pimpla = v11;
      goto LABEL_17;
    }
  }
  pimpla = nullptr;
LABEL_17:
  v12 = *((IShaderAPI **)this + 2);
  if ( v12 != nullptr )
    GRefCountImpl::Release(this: v12);
  *((_DWORD *)this + 2) = pimpla;
  v13 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_Log);
  v14 = (IShaderAPI *)v13;
  if ( v13 != nullptr )
    GRefCountImpl::AddRef(this: v13);
  v15 = *((IShaderAPI **)this + 3);
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  *((_DWORD *)this + 3) = v14;
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  v16 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_ParseControl);
  v17 = (IShaderAPI *)v16;
  if ( v16 != nullptr )
    GRefCountImpl::AddRef(this: v16);
  v18 = *((IShaderAPI **)this + 4);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  *((_DWORD *)this + 4) = v17;
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: v17);
  v19 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_ProgressHandler);
  v20 = (IShaderAPI *)v19;
  if ( v19 != nullptr )
    GRefCountImpl::AddRef(this: v19);
  v21 = *((IShaderAPI **)this + 5);
  if ( v21 != nullptr )
    GRefCountImpl::Release(this: v21);
  *((_DWORD *)this + 5) = v20;
  if ( v20 != nullptr )
    GRefCountImpl::Release(this: v20);
  v22 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_FontCacheManager);
  v23 = (IShaderAPI *)v22;
  if ( v22 != nullptr )
    GRefCountImpl::AddRef(this: v22);
  v24 = *((IShaderAPI **)this + 7);
  if ( v24 != nullptr )
    GRefCountImpl::Release(this: v24);
  *((_DWORD *)this + 7) = v23;
  if ( v23 != nullptr )
    GRefCountImpl::Release(this: v23);
  v25 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_TaskManager);
  v26 = (IShaderAPI *)v25;
  if ( v25 != nullptr )
    GRefCountImpl::AddRef(this: v25);
  v27 = *((IShaderAPI **)this + 6);
  if ( v27 != nullptr )
    GRefCountImpl::Release(this: v27);
  *((_DWORD *)this + 6) = v26;
  if ( v26 != nullptr )
    GRefCountImpl::Release(this: v26);
  v28 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_RenderConfig);
  v29 = (IShaderAPI *)v28;
  if ( v28 != nullptr )
    GRefCountImpl::AddRef(this: v28);
  v30 = *((IShaderAPI **)this + 8);
  if ( v30 != nullptr )
    GRefCountImpl::Release(this: v30);
  *((_DWORD *)this + 8) = v29;
  if ( v29 != nullptr )
    GRefCountImpl::Release(this: v29);
  v31 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_JpegSupport);
  v32 = (IShaderAPI *)v31;
  if ( v31 != nullptr )
    GRefCountImpl::AddRef(this: v31);
  v33 = *((IShaderAPI **)this + 9);
  if ( v33 != nullptr )
    GRefCountImpl::Release(this: v33);
  *((_DWORD *)this + 9) = v32;
  if ( v32 != nullptr )
    GRefCountImpl::Release(this: v32);
  v34 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_ZlibSupport);
  v35 = (IShaderAPI *)v34;
  if ( v34 != nullptr )
    GRefCountImpl::AddRef(this: v34);
  v36 = *((IShaderAPI **)this + 10);
  if ( v36 != nullptr )
    GRefCountImpl::Release(this: v36);
  *((_DWORD *)this + 10) = v35;
  if ( v35 != nullptr )
    GRefCountImpl::Release(this: v35);
  v37 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_PNGSupport);
  v38 = (IShaderAPI *)v37;
  if ( v37 != nullptr )
    GRefCountImpl::AddRef(this: v37);
  v39 = *((IShaderAPI **)this + 11);
  if ( v39 != nullptr )
    GRefCountImpl::Release(this: v39);
  *((_DWORD *)this + 11) = v38;
  if ( v38 != nullptr )
    GRefCountImpl::Release(this: v38);
  v40 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_Video);
  v41 = (IShaderAPI *)v40;
  if ( v40 != nullptr )
    GRefCountImpl::AddRef(this: v40);
  v42 = *((IShaderAPI **)this + 12);
  if ( v42 != nullptr )
    GRefCountImpl::Release(this: v42);
  *((_DWORD *)this + 12) = v41;
  if ( v41 != nullptr )
    GRefCountImpl::Release(this: v41);
  v43 = (IShaderDevice *)v8->GetStateAddRef(this: v8, a2: State_Audio);
  v44 = (IShaderAPI *)v43;
  if ( v43 != nullptr )
    GRefCountImpl::AddRef(this: v43);
  v45 = *((IShaderAPI **)this + 13);
  if ( v45 != nullptr )
    GRefCountImpl::Release(this: v45);
  *((_DWORD *)this + 13) = v44;
  if ( v44 != nullptr )
    GRefCountImpl::Release(this: v44);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DD000
// Name: public: virtual GFxLoadStates::~GFxLoadStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadStates::~GFxLoadStates(P4Client_t *this)
{
  int v2; // eax
  IShaderDevice **v3; // edi
  int v4; // ebx
  volatile LONG *v5; // edi
  IShaderAPI *v6; // ecx
  IShaderAPI *v7; // ecx
  IShaderAPI *v8; // ecx
  IShaderAPI *v9; // ecx
  IShaderAPI *v10; // ecx
  IShaderAPI *v11; // ecx
  IShaderAPI *v12; // ecx
  IShaderAPI *v13; // ecx
  IShaderAPI *v14; // ecx
  IShaderAPI *v15; // ecx
  IShaderAPI *v16; // ecx
  IShaderAPI *v17; // ecx
  IShaderAPI *v18; // ecx
  IShaderAPI *v19; // ecx

  *(_DWORD *)&this->m_sName.m_Id = &GFxLoadStates::`vftable';
  v2 = *((_DWORD *)this + 19);
  v3 = (IShaderDevice **)(*((_DWORD *)this + 18) + 4 * v2 - 4);
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 19);
    do
    {
      if ( *v3 != nullptr )
        GFxResource::Release(this: *v3);
      --v3;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 18));
  v5 = (volatile LONG *)(*(_DWORD *)(this + 8) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v5 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  v6 = *((IShaderAPI **)this + 15);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  v7 = *((IShaderAPI **)this + 14);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  v8 = *((IShaderAPI **)this + 13);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  v9 = *((IShaderAPI **)this + 12);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  v10 = *((IShaderAPI **)this + 11);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  v11 = *((IShaderAPI **)this + 10);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  v12 = *((IShaderAPI **)this + 9);
  if ( v12 != nullptr )
    GRefCountImpl::Release(this: v12);
  v13 = *((IShaderAPI **)this + 8);
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
  v14 = *((IShaderAPI **)this + 7);
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  v15 = *((IShaderAPI **)this + 6);
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  v16 = *((IShaderAPI **)this + 5);
  if ( v16 != nullptr )
    GRefCountImpl::Release(this: v16);
  v17 = *((IShaderAPI **)this + 4);
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: v17);
  v18 = *((IShaderAPI **)this + 3);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  v19 = *((IShaderAPI **)this + 2);
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100DD120
// Name: public: GFxLoadStates::GFxLoadStates(void)
// Source: json
//------------------------------------------------------------------------------
const P4Client_t *__thiscall GFxLoadStates::GFxLoadStates(char *this)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxLoadStates::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)(this + 64));
  *(this + 68) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return (const P4Client_t *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100DD1B0
// Name: public: class GFxLoadStates __near * GFxLoadStates::CloneForImport(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadStates::CloneForImport(P4Client_t *this)
{
  CReferenceToHandleTexture *v2; // eax
  IShaderDevice *v3; // ebx
  char *v4; // eax
  const P4Client_t *States; // esi
  IShaderAPI *v6; // ecx
  IShaderDevice *v7; // ecx
  IShaderAPI *v8; // ecx
  IShaderDevice *v9; // ecx
  IShaderAPI *v10; // ecx
  IShaderDevice *v11; // ecx
  IShaderAPI *v12; // ecx
  IShaderDevice *v13; // ecx
  IShaderAPI *v14; // ecx
  IShaderDevice *v15; // ecx
  IShaderAPI *v16; // ecx
  IShaderDevice *v17; // ecx
  IShaderAPI *v18; // ecx
  IShaderDevice *v19; // ecx
  IShaderAPI *v20; // ecx
  IShaderDevice *v21; // ecx
  IShaderAPI *v22; // ecx
  IShaderDevice *v23; // ecx
  IShaderAPI *v24; // ecx
  IShaderDevice *v25; // ecx
  IShaderAPI *v26; // ecx
  IShaderDevice *v27; // ecx
  IShaderAPI *v28; // ecx
  IShaderDevice *v29; // ecx
  IShaderAPI *v30; // ecx
  IShaderDevice *v31; // ecx
  IShaderAPI *v32; // ecx
  int v33; // [esp+0h] [ebp-10h]
  int v34; // [esp+Ch] [ebp-4h] BYREF

  v34 = 2;
  v2 = (CReferenceToHandleTexture *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v34);
  if ( v2 != nullptr )
    v3 = (IShaderDevice *)GFxMovieDefBindStates::GFxMovieDefBindStates(this: v2, pother: *((int **)this + 2), a3: v33);
  else
    v3 = nullptr;
  v34 = 2;
  v4 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v34);
  if ( v4 != nullptr )
  {
    States = GFxLoadStates::GFxLoadStates(this: v4);
    if ( States != nullptr )
    {
      if ( v3 != nullptr )
        GRefCountImpl::AddRef(this: v3);
      v6 = *(IShaderAPI **)&States[1].m_sName.m_Id;
      if ( v6 != nullptr )
        GRefCountImpl::Release(this: v6);
      *(_DWORD *)&States[1].m_sName.m_Id = v3;
      v7 = *((IShaderDevice **)this + 15);
      if ( v7 != nullptr )
        GRefCountImpl::AddRef(this: v7);
      v8 = *(IShaderAPI **)&States[7].m_sHost.m_Id;
      if ( v8 != nullptr )
        GRefCountImpl::Release(this: v8);
      *(_DWORD *)&States[7].m_sHost.m_Id = *((_DWORD *)this + 15);
      v9 = *((IShaderDevice **)this + 3);
      if ( v9 != nullptr )
        GRefCountImpl::AddRef(this: v9);
      v10 = *(IShaderAPI **)&States[1].m_sHost.m_Id;
      if ( v10 != nullptr )
        GRefCountImpl::Release(this: v10);
      *(_DWORD *)&States[1].m_sHost.m_Id = *((_DWORD *)this + 3);
      v11 = *((IShaderDevice **)this + 5);
      if ( v11 != nullptr )
        GRefCountImpl::AddRef(this: v11);
      v12 = *(IShaderAPI **)&States[2].m_sHost.m_Id;
      if ( v12 != nullptr )
        GRefCountImpl::Release(this: v12);
      *(_DWORD *)&States[2].m_sHost.m_Id = *((_DWORD *)this + 5);
      v13 = *((IShaderDevice **)this + 6);
      if ( v13 != nullptr )
        GRefCountImpl::AddRef(this: v13);
      v14 = *(IShaderAPI **)&States[3].m_sName.m_Id;
      if ( v14 != nullptr )
        GRefCountImpl::Release(this: v14);
      *(_DWORD *)&States[3].m_sName.m_Id = *((_DWORD *)this + 6);
      v15 = *((IShaderDevice **)this + 7);
      if ( v15 != nullptr )
        GRefCountImpl::AddRef(this: v15);
      v16 = *(IShaderAPI **)&States[3].m_sHost.m_Id;
      if ( v16 != nullptr )
        GRefCountImpl::Release(this: v16);
      *(_DWORD *)&States[3].m_sHost.m_Id = *((_DWORD *)this + 7);
      v17 = *((IShaderDevice **)this + 4);
      if ( v17 != nullptr )
        GRefCountImpl::AddRef(this: v17);
      v18 = *(IShaderAPI **)&States[2].m_sName.m_Id;
      if ( v18 != nullptr )
        GRefCountImpl::Release(this: v18);
      *(_DWORD *)&States[2].m_sName.m_Id = *((_DWORD *)this + 4);
      v19 = *((IShaderDevice **)this + 14);
      if ( v19 != nullptr )
        GRefCountImpl::AddRef(this: v19);
      v20 = *(IShaderAPI **)&States[7].m_sName.m_Id;
      if ( v20 != nullptr )
        GRefCountImpl::Release(this: v20);
      *(_DWORD *)&States[7].m_sName.m_Id = *((_DWORD *)this + 14);
      v21 = *((IShaderDevice **)this + 9);
      if ( v21 != nullptr )
        GRefCountImpl::AddRef(this: v21);
      v22 = *(IShaderAPI **)&States[4].m_sHost.m_Id;
      if ( v22 != nullptr )
        GRefCountImpl::Release(this: v22);
      *(_DWORD *)&States[4].m_sHost.m_Id = *((_DWORD *)this + 9);
      v23 = *((IShaderDevice **)this + 10);
      if ( v23 != nullptr )
        GRefCountImpl::AddRef(this: v23);
      v24 = *(IShaderAPI **)&States[5].m_sName.m_Id;
      if ( v24 != nullptr )
        GRefCountImpl::Release(this: v24);
      *(_DWORD *)&States[5].m_sName.m_Id = *((_DWORD *)this + 10);
      v25 = *((IShaderDevice **)this + 11);
      if ( v25 != nullptr )
        GRefCountImpl::AddRef(this: v25);
      v26 = *(IShaderAPI **)&States[5].m_sHost.m_Id;
      if ( v26 != nullptr )
        GRefCountImpl::Release(this: v26);
      *(_DWORD *)&States[5].m_sHost.m_Id = *((_DWORD *)this + 11);
      v27 = *((IShaderDevice **)this + 8);
      if ( v27 != nullptr )
        GRefCountImpl::AddRef(this: v27);
      v28 = *(IShaderAPI **)&States[4].m_sName.m_Id;
      if ( v28 != nullptr )
        GRefCountImpl::Release(this: v28);
      *(_DWORD *)&States[4].m_sName.m_Id = *((_DWORD *)this + 8);
      v29 = *((IShaderDevice **)this + 13);
      if ( v29 != nullptr )
        GRefCountImpl::AddRef(this: v29);
      v30 = *(IShaderAPI **)&States[6].m_sHost.m_Id;
      if ( v30 != nullptr )
        GRefCountImpl::Release(this: v30);
      *(_DWORD *)&States[6].m_sHost.m_Id = *((_DWORD *)this + 13);
      v31 = *((IShaderDevice **)this + 12);
      if ( v31 != nullptr )
        GRefCountImpl::AddRef(this: v31);
      v32 = *(IShaderAPI **)&States[6].m_sName.m_Id;
      if ( v32 != nullptr )
        GRefCountImpl::Release(this: v32);
      *(_DWORD *)&States[6].m_sName.m_Id = *((_DWORD *)this + 12);
    }
  }
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x10157D80
// Name: public: virtual void GFxResourceData::DataInterface::Release(void __near *)
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__stdcall GFxResourceData::DataInterface::Release(IShaderAPI *hdata)
{
  return GRefCountImpl::Release(this: hdata);
}

//------------------------------------------------------------------------------
// Address: 0x1028CAF0
// Name: _GFxImageFileResourceCreator::CreateImageFileResourceData_::_2_::_dynamic_atexit_destructor_for__inst__
// Source: json
//------------------------------------------------------------------------------
void GFxImageFileResourceCreator::CreateImageFileResourceData_::_2_::_dynamic_atexit_destructor_for__inst__()
{
  dword_1035982C = (int)&GFxResourceData::DataInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CB00
// Name: _GFxImageResourceCreator::CreateImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__
// Source: json
//------------------------------------------------------------------------------
void GFxImageResourceCreator::CreateImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__()
{
  dword_10359834 = (int)&GFxResourceData::DataInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CB10
// Name: _GFxSubImageResourceCreator::CreateSubImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__
// Source: json
//------------------------------------------------------------------------------
void GFxSubImageResourceCreator::CreateSubImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__()
{
  dword_1035983C = (int)&GFxResourceData::DataInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CB20
// Name: _dynamic_atexit_destructor_for__GFxPoint_DefaultParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxPoint_DefaultParams__()
{
  GASValue *v0; // esi
  int i; // edi

  v0 = (GASValue *)&GFxRectangle_DefaultParams;
  for ( i = 1; i >= 0; --i )
  {
    v0 -= 4;
    GASValue::~GASValue(this: v0, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028CB40
// Name: _dynamic_atexit_destructor_for__GFxPoint_NanParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxPoint_NanParams__()
{
  GASValue *v0; // esi
  int i; // edi

  v0 = (GASValue *)&unk_10359864;
  for ( i = 1; i >= 0; --i )
  {
    v0 -= 4;
    GASValue::~GASValue(this: v0, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028CB60
// Name: _dynamic_atexit_destructor_for__GFxRectangle_DefaultParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxRectangle_DefaultParams__()
{
  char **p_pName; // esi
  int i; // edi

  p_pName = &GFxRectangle_DefaultParams.Info.pName;
  for ( i = 3; i >= 0; --i )
  {
    p_pName -= 4;
    GASValue::~GASValue(this: (GASValue *)p_pName, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028CB80
// Name: _dynamic_atexit_destructor_for__GFxRectangle_NaNParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxRectangle_NaNParams__()
{
  char **p_pName; // esi
  int i; // edi

  p_pName = &GFxRectangle_NaNParams.Info.pName;
  for ( i = 3; i >= 0; --i )
  {
    p_pName -= 4;
    GASValue::~GASValue(this: (GASValue *)p_pName, a2: i);
  }
}
