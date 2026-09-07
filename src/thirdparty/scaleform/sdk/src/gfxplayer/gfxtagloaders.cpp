// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxtagloaders.cpp
// Functions: 54
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxtagloaders.h"

//------------------------------------------------------------------------------
// Address: 0x100D5030
// Name: public: virtual unsigned char const __near * GFxConstShapeCharacterDef::GetPathData(void)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxConstShapeCharacterDef::GetPathData(
        CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this@<ecx>,
        CMaterialVar *a2,
        __int128 a3,
        const unsigned int *a4,
        void *const *a5)
{
  (*(void (__thiscall **)(CMemberFuncProxy2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CFuncMemPolicyNone> *, CMaterialVar *))(LODWORD(this->m_Proxy.m_pfnProxied) + 60))(
    a1: &this->m_Proxy,
    a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D5040
// Name: public: virtual unsigned int GFxConstShapeCharacterDef::GetPathDataType(void)const
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall GFxConstShapeCharacterDef::GetPathDataType(old_bf_read *this)
{
  return (*(const unsigned __int8 *(__thiscall **)(bool *))(*(_DWORD *)&this->m_bOverflow + 64))(a1: &this->m_bOverflow);
}

//------------------------------------------------------------------------------
// Address: 0x100D5060
// Name: public: virtual class GFxShapeBase __near * GFxConstShapeCharacterDef::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxConstShapeCharacterDef::GetShape(
        char *this)
{
  return (CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(this + 16);
}

//------------------------------------------------------------------------------
// Address: 0x100DD3D0
// Name: public: unsigned char GFxLoadProcess::ReadU8(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::ReadU8(GFxAmpMsgHandler *this)
{
  GFxAmpMsgHandler *v1; // esi
  int v2; // eax
  _cpinfo *v3; // [esp+0h] [ebp-4h]

  v1 = *((GFxAmpMsgHandler **)this + 201);
  if ( v1 == nullptr )
    v1 = this + 2;
  v2 = v1[2].RecvPort - v1[2].RefCount;
  BYTE1(v1[1].__vftable) = 0;
  if ( v2 < 1 )
    GFxStream::PopulateBuffer1(result: v3);
  ++v1[2].RefCount;
}

//------------------------------------------------------------------------------
// Address: 0x100DD410
// Name: public: class GFxResourcePtr<class GFxImageResource> __near & GFxResourcePtr<class GFxImageResource>::operator=(class GFxResourcePtr<class GFxImageResource> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *__userpurge GFxResourcePtr<GFxImageResource>::operator=@<eax>(
        CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *this@<ecx>,
        int other,
        const CMorph::MorphSegment_t *a3)
{
  IShaderDevice *v4; // ecx
  IShaderDevice *m_nAllocationCount; // ecx

  if ( *(_DWORD *)other == 0 )
  {
    v4 = *(IShaderDevice **)(other + 4);
    if ( v4 != nullptr )
      GRefCountImpl::AddRef(this: v4);
  }
  if ( this->m_Memory.m_pMemory == nullptr )
  {
    m_nAllocationCount = (IShaderDevice *)this->m_Memory.m_nAllocationCount;
    if ( m_nAllocationCount != nullptr )
      GFxResource::Release(this: m_nAllocationCount);
  }
  this->m_Memory.m_pMemory = *(CMorph::MorphSegment_t **)other;
  this->m_Memory.m_nAllocationCount = *(_DWORD *)(other + 4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DD450
// Name: public: void GFxResourcePtr<class GFxImageResource>::SetFromHandle(class GFxResourceHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxResourcePtr<GFxImageResource>::SetFromHandle@<eax>(
        CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *this@<ecx>,
        const GenericThreadLocals::CThreadLocal<int> *src,
        int a3)
{
  IShaderDevice *m_index; // ecx
  IShaderDevice *m_nAllocationCount; // ecx
  unsigned int result; // eax

  if ( src->m_index == 0 )
  {
    m_index = (IShaderDevice *)src[1].m_index;
    if ( m_index != nullptr )
      GRefCountImpl::AddRef(this: m_index);
  }
  if ( this->m_Memory.m_pMemory == nullptr )
  {
    m_nAllocationCount = (IShaderDevice *)this->m_Memory.m_nAllocationCount;
    if ( m_nAllocationCount != nullptr )
      GFxResource::Release(this: m_nAllocationCount);
  }
  result = src->m_index;
  this->m_Memory.m_pMemory = (CMorph::MorphSegment_t *)src->m_index;
  this->m_Memory.m_nAllocationCount = src[1].m_index;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DD490
// Name: public: virtual void GFxPlaceObject2a::Unpack(struct GFxPlaceObjectBase::UnpackedData __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100DD4B0
// Name: public: virtual void GFxPlaceObject2a::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject2a::Execute(
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),CFuncMemPolicyNone> *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a2)
{
  GFxPlaceObject2::ExecuteBase(this, a2, version: 3);
}

//------------------------------------------------------------------------------
// Address: 0x100DD4D0
// Name: public: virtual void GFxPlaceObject2a::Trace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPlaceObject2a::Trace(
        CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),CFuncMemPolicyNone> *this@<ecx>,
        CMatQueuedIndexBuffer *str,
        __int128 a3)
{
  CMatNullRenderContext::OverrideColorWriteEnable(
    (CUtlDict<ITextureInternal *,unsigned short> *)this,
    prenderer: (unsigned __int16)str,
    ptext: (HBITMAP__)3);
}

//------------------------------------------------------------------------------
// Address: 0x100DD4F0
// Name: public: void GFxSpriteDef::SetScale9Grid(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSpriteDef::SetScale9Grid(
        GFxFSCommandHandler *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r)
{
  int v3; // ecx
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 11) == 0 )
  {
    v4 = 265;
    *((_DWORD *)this + 11) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                               this: GMemory::pGlobalHeap,
                               a2: this,
                               a3: 16,
                               a4: &v4);
  }
  v3 = *((_DWORD *)this + 11);
  *(GRefCountBase<GFxState,2> *)v3 = *(GRefCountBase<GFxState,2> *)&r->m_Memory.m_pMemory;
  *(float *)(v3 + 8) = *(float *)&r->m_Memory.m_nGrowSize - *(float *)&r->m_Memory.m_pMemory;
  *(float *)(v3 + 12) = *(float *)&r->m_Size - *(float *)&r->m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x100DD550
// Name: public: void GFxButtonCharacterDef::SetScale9Grid(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacterDef::SetScale9Grid(
        GFxAmpMessageCurrentState *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r)
{
  int v3; // ecx
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 12) == 0 )
  {
    v4 = 265;
    *((_DWORD *)this + 12) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                               this: GMemory::pGlobalHeap,
                               a2: this,
                               a3: 16,
                               a4: &v4);
  }
  v3 = *((_DWORD *)this + 12);
  *(GRefCountBase<GFxAmpCurrentState,2> *)v3 = *(GRefCountBase<GFxAmpCurrentState,2> *)&r->m_Memory.m_pMemory;
  *(float *)(v3 + 8) = *(float *)&r->m_Memory.m_nGrowSize - *(float *)&r->m_Memory.m_pMemory;
  *(float *)(v3 + 12) = *(float *)&r->m_Size - *(float *)&r->m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x100DD5B0
// Name: void GFx_FrameLabelLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_FrameLabelLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  GFxStream *v2; // ecx
  void *v3; // esi
  int v4; // [esp-4h] [ebp-10h]
  GStringDH v5; // [esp+4h] [ebp-8h] BYREF

  GStringDH::GStringDH(this: &v5, a2: *(struct GMemoryHeap **)(*((_DWORD *)p + 8) + 28));
  v2 = *((GFxStream **)p + 201);
  if ( v2 == nullptr )
    v2 = (GFxStream *)((char *)p + 40);
  GFxStream::ReadString(this: v2, a2: &v5);
  v4 = *(_DWORD *)(*((_DWORD *)p + 4) + 12);
  if ( *((_DWORD *)p + 190) == 1 )
    (*(void (__stdcall **)(GStringDH *, int))(**((_DWORD **)p + 191) + 72))(a1: &v5, a2: v4);
  else
    (*(void (__stdcall **)(GStringDH *, int))(**((_DWORD **)p + 8) + 4))(a1: &v5, a2: v4);
  v3 = (void *)(v5.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v5.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100DD640
// Name: void GFx_DebugIDLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DebugIDLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int i; // ebx
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned __int8 v6; // cl
  ConVar *Instance; // eax
  int v8; // eax
  void *v9; // esi
  void *v10; // [esp-8h] [ebp-1Ch]
  unsigned __int8 *v11; // [esp-4h] [ebp-18h]
  _cpinfo *v12; // [esp+0h] [ebp-14h]
  CUtlMemory<CImagePacker,int> var8; // [esp+Ch] [ebp-8h] BYREF

  GString::GString(this: &var8);
  for ( i = 16; i != 0; --i )
  {
    v3 = *((char **)p + 201);
    if ( v3 == nullptr )
      v3 = (char *)p + 40;
    v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
    v3[21] = 0;
    if ( v4 < 1 )
      GFxStream::PopulateBuffer1(result: v12);
    v5 = *((_DWORD *)v3 + 11);
    v6 = *(_BYTE *)(v5 + *((_DWORD *)v3 + 15));
    *((_DWORD *)v3 + 11) = v5 + 1;
    _itoa_s(val: v6, buf: (char *)&var8.m_nAllocationCount, sizeInTChars: 3u, radix: 16);
    GString::AppendString(this: &var8, putf8str: (CImagePacker *)&var8.m_nAllocationCount, utf8StrSz: -1);
  }
  v11 = (unsigned __int8 *)((*(_DWORD *)(*((_DWORD *)p + 8) + 36) & 0xFFFFFFFC) + 8);
  v10 = (void *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8);
  Instance = (ConVar *)GFxAmpServer::GetInstance(this: v10);
  GFxAmpServer::AddSwf(this: Instance, swdId: (void (__cdecl *)(IConVar *, const char *, float))v10, filename: v11);
  *(_DWORD *)(*((_DWORD *)p + 8) + 280) = v8;
  v9 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100DD7E0
// Name: void GFx_JpegTablesLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFx_JpegTablesLoader(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        struct GFxLoadProcess *p,
        const struct GFxTagInfo *tagInfo)
{
  int v3; // ebx
  GFxStream *v4; // esi
  char v5; // [esp+0h] [ebp-8h]

  v3 = *(_DWORD *)(*((_DWORD *)p + 4) + 36);
  if ( v3 != 0 )
  {
    if ( *((int *)tagInfo + 2) > 0 )
    {
      v4 = *((GFxStream **)p + 201);
      if ( v4 == nullptr )
        v4 = (GFxStream *)((char *)p + 40);
      GFxStream::SyncFileStream(this: v4);
      *((_BYTE *)v4 + 56) = 1;
      *((_DWORD *)p + 177) = (*(int (__thiscall **)(int, _LUID_AND_ATTRIBUTES *))(*(_DWORD *)v3 + 4))(
                               a1: v3,
                               a2: (_LUID_AND_ATTRIBUTES *)v4[4]);
    }
  }
  else
  {
    GFxLogBase<GFxLoadProcess>::LogError(
      this,
      pfmt: (unsigned int)p + 20,
      a3: (int)"Error: Jpeg System is not installed - can't load jpeg image data\n",
      a4: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD850
// Name: void GFx_DefineBitsJpegLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineBitsJpegLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  int v8; // ebx
  GRefCountNTSImpl *v9; // esi
  tagBITMAPINFOHEADER *v10; // eax
  GFxStream *v11; // ecx
  int v12; // esi
  GMemoryHeap *v13; // eax
  GFxStream *v14; // esi
  int v15; // eax
  GMemoryHeap *v16; // eax
  unsigned __int16 v17; // [esp+Ch] [ebp-4h]
  GMemoryHeap *pa; // [esp+18h] [ebp+8h]

  v3 = *((char **)p + 201);
  if ( v3 == nullptr )
    v3 = (char *)p + 40;
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v8 = *(_DWORD *)(*((_DWORD *)p + 4) + 36);
  v9 = nullptr;
  v17 = v6 | (v7 << 8);
  if ( v8 != 0 )
  {
    v11 = *((GFxStream **)p + 201);
    if ( v11 == nullptr )
      v11 = (GFxStream *)((char *)p + 40);
    GFxStream::SyncFileStream(this: v11);
    v12 = *((_DWORD *)p + 177);
    if ( v12 != 0 )
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v12 + 4))(a1: *((_DWORD *)p + 177));
      if ( GFxLoadStates::GetLoadTimeImageCreator(this: *((GFxLoadStates **)p + 4), a2: *((_DWORD *)p + 178)) != nullptr )
        v16 = GMemory::pGlobalHeap;
      else
        GFxMovieDataDef::LoadTaskData::GetImageHeap(this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p
                                                          + 8));
      v15 = (*(int (__thiscall **)(int, int, GMemoryHeap *))(*(_DWORD *)v8 + 16))(a1: v8, a2: v12, a3: v16);
    }
    else
    {
      if ( GFxLoadStates::GetLoadTimeImageCreator(this: *((GFxLoadStates **)p + 4), a2: *((_DWORD *)p + 178)) != nullptr )
      {
        pa = GMemory::pGlobalHeap;
      }
      else
      {
        GFxMovieDataDef::LoadTaskData::GetImageHeap(this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p
                                                          + 8));
        pa = v13;
      }
      v14 = *((GFxStream **)p + 201);
      if ( v14 == nullptr )
        v14 = (GFxStream *)((char *)p + 40);
      GFxStream::SyncFileStream(this: v14);
      *((_BYTE *)v14 + 56) = 1;
      v15 = (*(int (__thiscall **)(int, _LUID_AND_ATTRIBUTES *, GMemoryHeap *))(*(_DWORD *)v8 + 8))(
              a1: v8,
              a2: (_LUID_AND_ATTRIBUTES *)v14[4],
              a3: pa);
    }
    v9 = (GRefCountNTSImpl *)v15;
  }
  else
  {
    v10 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v10 == nullptr )
      v10 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogError(
      this: v10,
      a2: (int)"Error: Jpeg System is not installed - can't load jpeg image data\n");
  }
  GFxLoadProcess::AddImageResource(result: (const GFxAmpCurrentState *)v17);
  if ( v9 != nullptr )
    GRefCountNTSImpl::Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100DD9A0
// Name: void GFx_DefineBitsJpeg2Loader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineBitsJpeg2Loader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  int v8; // ecx
  int v9; // ebx
  GRefCountNTSImpl *v10; // edi
  GMemoryHeap *v11; // eax
  GFxStream *v12; // edi
  char v13; // [esp+0h] [ebp-10h]
  GArrayLH<GString,2,GArrayDefaultPolicy> *v14; // [esp+Ch] [ebp-4h]
  HBITMAP__ pa; // [esp+18h] [ebp+8h]

  v3 = *((char **)p + 201);
  if ( v3 == nullptr )
    v3 = (char *)p + 40;
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v14 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)(unsigned __int16)(v6 | (v7 << 8));
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: v14,
    pfmt: (unsigned int)p + 20,
    a3: (int)"  GFx_DefineBitsJpeg2Loader: charid = %d pos = 0x%x\n",
    a4: v6);
  v8 = *((_DWORD *)p + 4);
  v9 = *(_DWORD *)(v8 + 36);
  v10 = nullptr;
  if ( v9 != 0 )
  {
    if ( GFxLoadStates::GetLoadTimeImageCreator(this: (GFxLoadStates *)v8, a2: *((_DWORD *)p + 178)) != nullptr )
      v11 = GMemory::pGlobalHeap;
    else
      GFxMovieDataDef::LoadTaskData::GetImageHeap(this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p
                                                        + 8));
    v12 = *((GFxStream **)p + 201);
    pa.unused = (int)v11;
    if ( v12 == nullptr )
      v12 = (GFxStream *)((char *)p + 40);
    GFxStream::SyncFileStream(this: v12);
    *((_BYTE *)v12 + 56) = 1;
    v10 = (GRefCountNTSImpl *)(*(int (__thiscall **)(int, _LUID_AND_ATTRIBUTES *, HBITMAP__))(*(_DWORD *)v9 + 12))(
                                a1: v9,
                                a2: (_LUID_AND_ATTRIBUTES *)v12[4],
                                a3: pa);
  }
  else
  {
    GFxLogBase<GFxLoadProcess>::LogError(
      this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v8,
      pfmt: (unsigned int)p + 20,
      a3: (int)"Error: Jpeg system is not installed - can't load jpeg image data\n",
      a4: v13);
  }
  GFxLoadProcess::AddImageResource(result: (const GFxAmpCurrentState *)v14);
  if ( v10 != nullptr )
    GRefCountNTSImpl::Release(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100DDB10
// Name: void GFx_DefineShapeMorphLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineShapeMorphLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // esi
  int v8; // ecx
  int (__thiscall *v9)(int, int, HBITMAP__ *); // eax
  GFxMorphCharacterDef *v10; // eax
  GFxMorphCharacterDef *v11; // ebx

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *(unsigned __int16 *)(*((_DWORD *)v3 + 15) + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v7 = v6;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v6,
    pfmt: v2.unused + 20,
    a3: (int)"  ShapeMorphLoader: id = %d\n",
    a4: v6);
  v8 = *(_DWORD *)(*(_DWORD *)(v2.unused + 32) + 28);
  v9 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v8 + 40);
  p.unused = 258;
  v10 = (GFxMorphCharacterDef *)v9(a1: v8, a2: 208, a3: &p);
  if ( v10 != nullptr )
    v11 = GFxMorphCharacterDef::GFxMorphCharacterDef(this: v10);
  else
    v11 = nullptr;
  GFxMorphCharacterDef::Read(this: v11, a2: (struct GFxLoadProcess *)v2.unused, a3: tagInfo, a4: true);
  if ( *(_DWORD *)(v2.unused + 760) == 0 )
    GFxMovieDataDef::LoadTaskData::AddResource(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v2.unused + 32),
      rid: v7,
      pres: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v11);
  if ( v11 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v11);
}

//------------------------------------------------------------------------------
// Address: 0x100DDBE0
// Name: void GFx_DefineFontLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineFontLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  CVertexMorphDict::MorphVertexList_t *unused; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  IShaderDevice *v6; // ecx
  int m_nMorphTargetId; // edx
  bool v8; // bl
  int v9; // eax
  int v10; // ecx
  int (__thiscall *v11)(int, int, HBITMAP__ *); // edx
  float *v12; // eax
  GFxFontDataCompactedGfx *v13; // esi
  int v14; // ecx
  int (__thiscall *v15)(int, int, HBITMAP__ *); // edx
  GFxFontDataCompactedSwf *v16; // eax
  int v17; // ecx
  int (__thiscall *v18)(int, int, HBITMAP__ *); // edx
  CMorph *v19; // eax
  GFxFontData *v20; // eax
  int v21; // [esp+Ch] [ebp-8h] BYREF
  IShaderDevice *v22; // [esp+10h] [ebp-4h]

  unused = (CVertexMorphDict::MorphVertexList_t *)p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = (IShaderDevice *)*(unsigned __int16 *)(*((_DWORD *)v3 + 15) + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v22 = v6;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v6,
    pfmt: (unsigned int)&unused->m_MorphInfo.m_pElements,
    a3: (int)"  Font: id = %d\n",
    a4: (char)v6);
  m_nMorphTargetId = unused[1].m_nMorphTargetId;
  v8 = false;
  if ( (*(_DWORD *)(m_nMorphTargetId + 76) != 0 ? m_nMorphTargetId + 76 : 0) != 0 )
    v8 = (*(_BYTE *)(*(_DWORD *)(m_nMorphTargetId + 76) != 0 ? m_nMorphTargetId + 76 + 0x10 : 16) & 0x10) != 0;
  v9 = *(_DWORD *)tagInfo;
  if ( *(_DWORD *)tagInfo == 1005 )
  {
    v10 = *(_DWORD *)(m_nMorphTargetId + 28);
    v11 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v10 + 40);
    p.unused = 261;
    v12 = (float *)v11(a1: v10, a2: 100, a3: &p);
    if ( v12 != nullptr )
    {
      v13 = (GFxFontDataCompactedGfx *)GFxFontDataCompactedGfx::GFxFontDataCompactedGfx(this: v12);
      GFxFontDataCompactedGfx::Read(this: v13, p: (HBITMAP__)unused, bytes: (int)tagInfo);
    }
    else
    {
      v13 = nullptr;
      GFxFontDataCompactedGfx::Read(this: nullptr, p: (HBITMAP__)unused, bytes: (int)tagInfo);
    }
  }
  else if ( (v9 == 48 || v9 == 75) && !v8 && *(_DWORD *)(*(_DWORD *)(unused->m_MorphInfo.m_Size + 8) + 36) != 0 )
  {
    v14 = *(_DWORD *)(m_nMorphTargetId + 28);
    v15 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v14 + 40);
    p.unused = 261;
    v16 = (GFxFontDataCompactedSwf *)v15(a1: v14, a2: 108, a3: &p);
    if ( v16 != nullptr )
    {
      v13 = GFxFontDataCompactedSwf::GFxFontDataCompactedSwf(this: v16);
      GFxFontDataCompactedSwf::Read(
        this: (CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *)v13,
        p: unused,
        (int *)tagInfo);
    }
    else
    {
      v13 = nullptr;
      GFxFontDataCompactedSwf::Read(this: nullptr, p: unused, (int *)tagInfo);
    }
  }
  else
  {
    v17 = *(_DWORD *)(m_nMorphTargetId + 28);
    v18 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v17 + 40);
    p.unused = 261;
    v19 = (CMorph *)v18(a1: v17, a2: 64, a3: &p);
    if ( v19 != nullptr )
      GFxFontData::GFxFontData(this: v19);
    else
      v20 = nullptr;
    v13 = (GFxFontDataCompactedGfx *)v20;
    GFxFontData::Read(this: v20, a2: (struct GFxLoadProcess *)unused, a3: tagInfo);
  }
  GFxLoadProcess::AddFontDataResource(a1: unused, a2: &v21, a3: v22, a4: v13);
  if ( v21 == 0 && v22 != nullptr )
    GFxResource::Release(this: v22);
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v13);
}

//------------------------------------------------------------------------------
// Address: 0x100DDD90
// Name: void GFx_DefineFontInfoLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100DDE30
// Name: void GFx_SpriteLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_SpriteLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned __int16 v6; // dx
  unsigned int v7; // esi
  int v8; // ecx
  int (__thiscall *v9)(int, int, HBITMAP__ *); // edx
  GFxSpriteDef *v10; // eax
  GFxSpriteDef *v11; // ebx
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v12; // ecx

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *(_WORD *)(*((_DWORD *)v3 + 15) + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v7 = v6;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v6,
    pfmt: v2.unused + 20,
    a3: (int)"  sprite\n  char id = %d\n",
    a4: v6);
  v8 = *(_DWORD *)(*(_DWORD *)(v2.unused + 32) + 28);
  v9 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v8 + 40);
  p.unused = 258;
  v10 = (GFxSpriteDef *)v9(a1: v8, a2: 56, a3: &p);
  if ( v10 != nullptr )
    v11 = GFxSpriteDef::GFxSpriteDef(this: v10, pmd: *(struct GFxMovieDataDef **)(v2.unused + 36));
  else
    v11 = nullptr;
  GFxSpriteDef::Read(this: v11, p: (struct GFxLoadProcess *)v2.unused, a3: (struct GFxResourceId)v7);
  v12 = *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v2.unused + 32);
  *((_DWORD *)v11 + 3) = v7;
  GFxMovieDataDef::LoadTaskData::AddResource(
    this: v12,
    rid: v7,
    pres: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v11);
  if ( v11 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v11);
}

//------------------------------------------------------------------------------
// Address: 0x100DDEF0
// Name: void GFx_ButtonCharacterLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_ButtonCharacterLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // esi
  int v8; // ecx
  int (__thiscall *v9)(int, int, HBITMAP__ *); // eax
  GFxButtonCharacterDef *v10; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // ebx

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *(unsigned __int16 *)(*((_DWORD *)v3 + 15) + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v7 = v6;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v6,
    pfmt: v2.unused + 20,
    a3: (int)"  button GFxCharacter loader: CharId = %d\n",
    a4: v6);
  v8 = *(_DWORD *)(*(_DWORD *)(v2.unused + 32) + 28);
  v9 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v8 + 40);
  p.unused = 258;
  v10 = (GFxButtonCharacterDef *)v9(a1: v8, a2: 52, a3: &p);
  if ( v10 != nullptr )
    v11 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxButtonCharacterDef::GFxButtonCharacterDef(this: v10);
  else
    v11 = nullptr;
  GFxButtonCharacterDef::Read(this: (int)v11, a2: (GFxAmpMsgHandler *)v2.unused, a3: *(_DWORD *)tagInfo);
  if ( *(_DWORD *)(v2.unused + 760) == 0 )
    GFxMovieDataDef::LoadTaskData::AddResource(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v2.unused + 32),
      rid: v7,
      pres: v11);
  if ( v11 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v11);
}

//------------------------------------------------------------------------------
// Address: 0x100DDFC0
// Name: void GFx_DefineVideoStream(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineVideoStream(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  tagBITMAPINFOHEADER *v3; // eax
  GFxStream *v4; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 48);
  if ( v2 != 0 )
  {
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v2 + 28))(
      a1: v2,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v3 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v3 == nullptr )
      v3 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v3, a2: (int)"GFx_DefineVideoStream: Video libarary is not set.\n");
    v4 = *((GFxStream **)p + 201);
    if ( v4 == nullptr )
      v4 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE020
// Name: void GFx_SetTabIndexLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_SetTabIndexLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v2; // esi
  int v3; // eax
  char *v4; // esi
  int v5; // ecx
  char v6; // [esp+0h] [ebp-8h]

  v2 = *((char **)p + 201);
  if ( v2 == nullptr )
    v2 = (char *)p + 40;
  v3 = *((_DWORD *)v2 + 12) - *((_DWORD *)v2 + 11);
  v2[21] = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  *((_DWORD *)v2 + 11) += 2;
  v4 = *((char **)p + 201);
  if ( v4 == nullptr )
    v4 = (char *)p + 40;
  v5 = *((_DWORD *)v4 + 12) - *((_DWORD *)v4 + 11);
  v4[21] = 0;
  if ( v5 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  *((_DWORD *)v4 + 11) += 2;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v5,
    pfmt: (unsigned int)p + 20,
    a3: (int)"SetTabIndex (unused) \n",
    a4: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100DE0A0
// Name: void GFx_ExportLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_ExportLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned __int16 v6; // dx
  int v7; // esi
  char *v8; // esi
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  __int16 v12; // dx
  struct GFxResourceId v13; // ebx
  GFxStream *Stream; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v15; // ecx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v16; // ecx
  void *v17; // esi
  GStringDH v18; // [esp+Ch] [ebp-10h] BYREF
  _TRIVERTEX *hres; // [esp+14h] [ebp-8h] BYREF
  IShaderDevice *v20; // [esp+18h] [ebp-4h]
  HBITMAP__ pa; // [esp+24h] [ebp+8h]

  v3 = *((char **)p + 201);
  if ( v3 == nullptr )
    v3 = (char *)p + 40;
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *(_WORD *)(*((_DWORD *)v3 + 15) + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v7 = v6;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v6,
    pfmt: (unsigned int)p + 20,
    a3: (int)"  export: count = %d\n",
    a4: v6);
  if ( v7 != 0 )
  {
    for ( pa.unused = v7; pa.unused != 0; --pa.unused )
    {
      v8 = *((char **)p + 201);
      if ( v8 == nullptr )
        v8 = (char *)p + 40;
      v9 = *((_DWORD *)v8 + 12) - *((_DWORD *)v8 + 11);
      v8[21] = 0;
      if ( v9 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v10 = *((_DWORD *)v8 + 11);
      v11 = *((_DWORD *)v8 + 15);
      v12 = *(unsigned __int8 *)(v11 + v10 + 1);
      LOWORD(v11) = *(unsigned __int8 *)(v11 + v10);
      *((_DWORD *)v8 + 11) = v10 + 2;
      v13.Id = (unsigned __int16)(v11 | (v12 << 8));
      GStringDH::GStringDH(this: &v18, a2: *(struct GMemoryHeap **)(*((_DWORD *)p + 8) + 28));
      Stream = (GFxStream *)GFxLoadProcess::GetStream(this: (GFxLoadProcess **)p);
      GFxStream::ReadString(this: Stream, a2: &v18);
      GFxLogBase<GFxLoadProcess>::LogParse(
        this: v15,
        pfmt: (unsigned int)p + 20,
        a3: (int)"  export: id = %d, name = %s\n",
        a4: v13.Id);
      hres = nullptr;
      v20 = nullptr;
      if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
             this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p + 8),
             phandle: &hres,
             rid: v13.Id) != 0 )
        GFxMovieDataDef::LoadTaskData::ExportResource(
          this: *((GFxMovieDataDef::LoadTaskData **)p + 8),
          result: (GPtr<GFxParseControl> *)&v18,
          a3: v13,
          a4: (const struct GFxResourceHandle *)&hres);
      else
        GFxLogBase<GFxLoadProcess>::LogError(
          this: v16,
          pfmt: (unsigned int)p + 20,
          a3: (int)"Export error: don't know how to export GFxResource '%s'\n",
          a4: ((int)v18.pData & 0xFC) + 8);
      if ( hres == nullptr && v20 != nullptr )
        GFxResource::Release(this: v20);
      v17 = (void *)(v18.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v18.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v17);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE230
// Name: void GFx_FileAttributesLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_FileAttributesLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  __int16 v6; // dx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v7; // ecx
  int v8; // ebx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v9; // ecx
  char v10; // al
  char v11; // [esp+0h] [ebp-Ch]
  char v12; // [esp+0h] [ebp-Ch]

  v2 = *((char **)p + 201);
  if ( v2 == nullptr )
    v2 = (char *)p + 40;
  v3 = *((_DWORD *)v2 + 12) - *((_DWORD *)v2 + 11);
  v2[21] = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v4 = *((_DWORD *)v2 + 11);
  v5 = *((_DWORD *)v2 + 15);
  v6 = *(unsigned __int8 *)(v5 + v4 + 1);
  v7 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)*(unsigned __int8 *)(v5 + v4);
  v8 = (unsigned __int16)((unsigned __int16)v7 | (v6 << 8));
  *((_DWORD *)v2 + 11) = v4 + 2;
  *(_DWORD *)(*((_DWORD *)p + 8) + 116) = v8;
  if ( (_WORD)v8 != 0 )
  {
    GFxLogBase<GFxLoadProcess>::LogParse(this: v7, pfmt: (unsigned int)p + 20, a3: (int)"  fileAttr:", a4: v11);
    v10 = 32;
    if ( (v8 & 1) != 0 )
    {
      GFxLogBase<GFxLoadProcess>::LogParse(this: v9, pfmt: (unsigned int)p + 20, a3: (int)"%cUseNetwork", a4: 32);
      v10 = 44;
    }
    if ( (v8 & 0x10) != 0 )
      GFxLogBase<GFxLoadProcess>::LogParse(
        this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v10,
        pfmt: (unsigned int)p + 20,
        a3: (int)"%cHasMetadata",
        a4: v10);
    GFxLogBase<GFxLoadProcess>::LogParse(this: v9, pfmt: (unsigned int)p + 20, a3: (int)"\n", a4: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE2E0
// Name: void GFx_MetadataLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFx_MetadataLoader(_cpinfo *a1@<ebx>, struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  IShaderDeviceMgr *v3; // ecx
  int v4; // eax
  _DWORD *v5; // ecx
  signed int v6; // edi
  TextureLodOverride::OverrideInfo *v7; // esi
  signed int v8; // ebx
  char *v9; // esi
  int v10; // ecx
  int v11; // eax
  unsigned __int8 v12; // cl
  unsigned __int8 *v13; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v14; // ecx
  _cpinfo *v15; // [esp-4h] [ebp-14h]
  ShaderDisplayMode_t *v16; // [esp+0h] [ebp-10h]
  int v17; // [esp+4h] [ebp-Ch]
  int v18; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 *pbuff; // [esp+Ch] [ebp-4h]

  v3 = *((IShaderDeviceMgr **)p + 201);
  if ( v3 == nullptr )
    v3 = (IShaderDeviceMgr *)((char *)p + 40);
  GFxStream::GetTagEndPosition(this: v3, a2: v16, a3: v17);
  v5 = *((_DWORD **)p + 201);
  if ( v5 == nullptr )
    v5 = (_DWORD *)((char *)p + 40);
  v6 = v4 + v5[12] - v5[13] - v5[11];
  v18 = 2;
  v7 = (TextureLodOverride::OverrideInfo *)GMemory::pGlobalHeap->Alloc_2(
                                             this: GMemory::pGlobalHeap,
                                             a2: v6 + 1,
                                             a3: &v18);
  pbuff = (unsigned __int8 *)v7;
  if ( v7 != nullptr )
  {
    v15 = a1;
    v8 = 0;
    if ( v6 > 0 )
    {
      do
      {
        if ( *((_DWORD *)p + 201) != 0 )
          v9 = *((char **)p + 201);
        else
          v9 = (char *)p + 40;
        v10 = *((_DWORD *)v9 + 12) - *((_DWORD *)v9 + 11);
        v9[21] = 0;
        if ( v10 < 1 )
          GFxStream::PopulateBuffer1(result: v15);
        v11 = *((_DWORD *)v9 + 11);
        v12 = *(_BYTE *)(v11 + *((_DWORD *)v9 + 15));
        *((_DWORD *)v9 + 11) = v11 + 1;
        v13 = pbuff;
        pbuff[v8++] = v12;
      }
      while ( v8 < v6 );
      v7 = (TextureLodOverride::OverrideInfo *)v13;
    }
    GFxMovieDataDef::LoadTaskData::SetMetadata(
      this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p + 8),
      pdata: v7,
      size: v6);
    if ( v6 >= 255 )
      v6 = 255;
    *(&v7->x + v6) = 0;
    GFxLogBase<GFxLoadProcess>::LogParse(
      this: v14,
      pfmt: (unsigned int)p + 20,
      a3: (int)"  metadata: %s\n",
      a4: (char)v7);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE3D0
// Name: GFx_CreateImageFileResourceHandle
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall GFx_CreateImageFileResourceHandle@<eax>(
        _DWORD *a1@<ebx>,
        int a2,
        int a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        unsigned __int16 a6,
        __int16 a7,
        __int16 a8,
        char a9)
{
  GMemoryHeap *v9; // ecx
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  GFxResourceFileInfo *v11; // eax
  GFxResourceFileInfo *v12; // esi
  _DWORD *v13; // eax
  _DWORD *v14; // edi
  IShaderDevice *v15; // ecx
  IShaderDevice *v16; // ecx
  bool v17; // zf
  int v18; // edx
  _DWORD v20[3]; // [esp+8h] [ebp-14h] BYREF
  IShaderDevice *v21; // [esp+14h] [ebp-8h]
  int v22; // [esp+18h] [ebp-4h] BYREF

  v9 = GMemory::pGlobalHeap;
  v22 = 2;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  *a1 = 0;
  a1[1] = 0;
  v11 = (GFxResourceFileInfo *)Alloc_2(this: v9, a2: 36u, a3: (const GAllocDebugInfo *)&v22);
  v12 = v11;
  if ( v11 != nullptr )
  {
    GFxResourceFileInfo::GFxResourceFileInfo(this: v11);
    v12->dwSize = (unsigned int)&GFxImageFileInfo::`vftable';
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v12[1].___u2);
    *(_WORD *)&v12->ObjectId.Data4[6] = 0;
    v12[1].dwSize = 1;
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v12->ObjectId.Data4,
      a2: a4);
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v12[1].___u2,
      a2: a5);
    v12->FileId.HighPart = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 76) != 0 ? *(_DWORD *)(a2 + 32) + 76 : 0;
    v12->FileId.LowPart = a6;
    *(_WORD *)&v12->ObjectId.Data4[4] = a7;
    *(_WORD *)&v12->ObjectId.Data4[6] = a8;
    LOBYTE(v12[1].Type) = a9;
    if ( (a3 & 0xFFF0000) == 0x60000 )
      v12[1].dwSize = 3;
    GFxImageFileResourceCreator::CreateImageFileResourceData(a1: v20, a2: v12);
    LOBYTE(v13) = GFxLoadProcess::AddDataResource();
    v14 = v13;
    if ( *v13 == 0 )
    {
      v15 = (IShaderDevice *)v13[1];
      if ( v15 != nullptr )
        GRefCountImpl::AddRef(this: v15);
    }
    if ( *a1 == 0 )
    {
      v16 = (IShaderDevice *)a1[1];
      if ( v16 != nullptr )
        GFxResource::Release(this: v16);
    }
    v17 = v20[2] == 0;
    v18 = v14[1];
    *a1 = *v14;
    a1[1] = v18;
    if ( v17 && v21 != nullptr )
      GFxResource::Release(this: v21);
    if ( v20[0] != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v20[0] + 8))(a1: v20[0], a2: v20[1]);
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v12);
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100DE510
// Name: void GFx_DefineExternalImageLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineExternalImageLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v2; // esi
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  __int16 v6; // dx
  char *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  __int16 v11; // dx
  char *v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  __int16 v16; // dx
  char *v17; // esi
  int v18; // ebx
  int v19; // edx
  int v20; // eax
  int v21; // edi
  void *v22; // esi
  void *v23; // esi
  int v24; // [esp+Ch] [ebp-18h] BYREF
  unsigned int bitmapResourceId; // [esp+10h] [ebp-14h]
  int v26; // [esp+14h] [ebp-10h]
  GFxStream *v27; // [esp+18h] [ebp-Ch]
  CUtlMemory<CImagePacker,int> var8; // [esp+1Ch] [ebp-8h] BYREF

  v2 = *((char **)p + 201);
  if ( v2 != nullptr )
    v27 = *((GFxStream **)p + 201);
  else
    v27 = (GFxStream *)((char *)p + 40);
  if ( v2 == nullptr )
    v2 = (char *)p + 40;
  v3 = *((_DWORD *)v2 + 12) - *((_DWORD *)v2 + 11);
  v2[21] = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v4 = *((_DWORD *)v2 + 11);
  v5 = *((_DWORD *)v2 + 15);
  v6 = *(unsigned __int8 *)(v5 + v4 + 1);
  LOWORD(v5) = *(unsigned __int8 *)(v5 + v4);
  *((_DWORD *)v2 + 11) = v4 + 2;
  v7 = *((char **)p + 201);
  bitmapResourceId = (unsigned __int16)(v5 | (v6 << 8));
  if ( v7 == nullptr )
    v7 = (char *)p + 40;
  v8 = *((_DWORD *)v7 + 12) - *((_DWORD *)v7 + 11);
  v7[21] = 0;
  if ( v8 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v9 = *((_DWORD *)v7 + 11);
  v10 = *((_DWORD *)v7 + 15);
  v11 = *(unsigned __int8 *)(v10 + v9 + 1);
  LOWORD(v10) = *(unsigned __int8 *)(v10 + v9);
  *((_DWORD *)v7 + 11) = v9 + 2;
  v12 = *((char **)p + 201);
  v26 = (unsigned __int16)(v10 | (v11 << 8));
  if ( v12 == nullptr )
    v12 = (char *)p + 40;
  v13 = *((_DWORD *)v12 + 12) - *((_DWORD *)v12 + 11);
  v12[21] = 0;
  if ( v13 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v14 = *((_DWORD *)v12 + 11);
  v15 = *((_DWORD *)v12 + 15);
  v16 = *(unsigned __int8 *)(v15 + v14 + 1);
  LOWORD(v15) = *(unsigned __int8 *)(v15 + v14);
  *((_DWORD *)v12 + 11) = v14 + 2;
  v17 = *((char **)p + 201);
  v18 = (unsigned __int16)(v15 | (v16 << 8));
  if ( v17 == nullptr )
    v17 = (char *)p + 40;
  v19 = *((_DWORD *)v17 + 12) - *((_DWORD *)v17 + 11);
  v17[21] = 0;
  if ( v19 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v20 = *((_DWORD *)v17 + 11);
  v21 = *(unsigned __int16 *)(*((_DWORD *)v17 + 15) + v20);
  *((_DWORD *)v17 + 11) = v20 + 2;
  GString::GString(this: &var8);
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&var8.m_nAllocationCount);
  GFxStream::ReadStringWithLength(this: v27, a2: (struct GString *)&var8);
  GFxStream::ReadStringWithLength(this: v27, a2: (struct GString *)&var8.m_nAllocationCount);
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v27,
    a2: (int)"  DefineExternalImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', exp = '%s', w = %d, h = %d\n",
    *(_DWORD *)tagInfo,
    bitmapResourceId,
    (unsigned __int16)v26,
    (const char *)((var8.m_nAllocationCount & 0xFFFFFFFC) + 8),
    (const char *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8),
    v18,
    v21);
  GFx_CreateImageFileResourceHandle(
    a1: &v24,
    a2: (int)p,
    a3: bitmapResourceId,
    a4: (unsigned __int8 *)((var8.m_nAllocationCount & 0xFFFFFFFC) + 8),
    a5: (unsigned __int8 *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8),
    a6: v26,
    a7: v18,
    a8: v21,
    a9: 1);
  if ( v24 == 0 && bitmapResourceId != 0 )
    GFxResource::Release(this: (IShaderDevice *)bitmapResourceId);
  v22 = (void *)(var8.m_nAllocationCount & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((var8.m_nAllocationCount & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
  v23 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v23);
}

//------------------------------------------------------------------------------
// Address: 0x100DE730
// Name: void GFx_DefineExternalImageLoader2(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineExternalImageLoader2(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  struct GFxLoadProcess *unused; // edi
  GFxStream *v3; // ebx
  int v4; // ecx
  _LUID_AND_ATTRIBUTES *v5; // ecx
  _LUID_AND_ATTRIBUTES *v6; // eax
  int v7; // esi
  int v8; // edx
  unsigned __int8 *v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // eax
  char *v13; // ebx
  int v14; // esi
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  __int16 v18; // dx
  char *v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  __int16 v23; // dx
  char *v24; // ebx
  int v25; // eax
  int v26; // eax
  char *v27; // ebx
  int v28; // eax
  int v29; // eax
  void *v30; // esi
  void *v31; // esi
  _cpinfo *v32; // [esp+0h] [ebp-28h]
  int v33; // [esp+Ch] [ebp-1Ch] BYREF
  IShaderDevice *v34; // [esp+10h] [ebp-18h]
  int v35; // [esp+14h] [ebp-14h]
  int v36; // [esp+18h] [ebp-10h]
  int flags; // [esp+1Ch] [ebp-Ch]
  GFxStream *v38; // [esp+20h] [ebp-8h]
  struct GString v39; // [esp+24h] [ebp-4h] BYREF

  unused = (struct GFxLoadProcess *)p.unused;
  v3 = *(GFxStream **)(p.unused + 804);
  flags = *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(p.unused + 32) + 76) != 0
                              ? *(_DWORD *)(p.unused + 32) + 76 + 0xC
                              : 12);
  if ( v3 != nullptr )
    v38 = v3;
  else
    v38 = (GFxStream *)(p.unused + 40);
  if ( v3 == nullptr )
    v3 = (GFxStream *)(p.unused + 40);
  v4 = (char *)v3[12] - (char *)v3[11];
  *((_BYTE *)v3 + 21) = 0;
  if ( v4 < 4 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
  v5 = (_LUID_AND_ATTRIBUTES *)v3[11];
  v6 = (_LUID_AND_ATTRIBUTES *)v3[15];
  v7 = *((unsigned __int8 *)&v5->Luid.LowPart + (_DWORD)v6 + 3);
  v8 = *((unsigned __int8 *)&v5->Luid.LowPart + (_DWORD)v6 + 2);
  v9 = (unsigned __int8 *)v6 + (_DWORD)v5;
  v10 = v8 | (v7 << 8);
  v11 = v9[1];
  v12 = *v9;
  v3[11] = (GFxStream)&v5->Luid.HighPart;
  v13 = *((char **)unused + 201);
  v14 = v12 | ((v11 | (v10 << 8)) << 8);
  if ( v13 == nullptr )
    v13 = (char *)unused + 40;
  v15 = *((_DWORD *)v13 + 12) - *((_DWORD *)v13 + 11);
  v13[21] = 0;
  if ( v15 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v16 = *((_DWORD *)v13 + 11);
  v17 = *((_DWORD *)v13 + 15);
  v18 = *(unsigned __int8 *)(v17 + v16 + 1);
  LOWORD(v17) = *(unsigned __int8 *)(v17 + v16);
  *((_DWORD *)v13 + 11) = v16 + 2;
  v19 = *((char **)unused + 201);
  v35 = (unsigned __int16)(v17 | (v18 << 8));
  if ( v19 == nullptr )
    v19 = (char *)unused + 40;
  v20 = *((_DWORD *)v19 + 12) - *((_DWORD *)v19 + 11);
  v19[21] = 0;
  if ( v20 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v21 = *((_DWORD *)v19 + 11);
  v22 = *((_DWORD *)v19 + 15);
  v23 = *(unsigned __int8 *)(v22 + v21 + 1);
  LOWORD(v22) = *(unsigned __int8 *)(v22 + v21);
  *((_DWORD *)v19 + 11) = v21 + 2;
  v24 = *((char **)unused + 201);
  v36 = (unsigned __int16)(v22 | (v23 << 8));
  if ( v24 == nullptr )
    v24 = (char *)unused + 40;
  v25 = *((_DWORD *)v24 + 12) - *((_DWORD *)v24 + 11);
  v24[21] = 0;
  if ( v25 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v26 = *((_DWORD *)v24 + 11);
  v34 = (IShaderDevice *)*(unsigned __int16 *)(*((_DWORD *)v24 + 15) + v26);
  *((_DWORD *)v24 + 11) = v26 + 2;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v39);
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&p);
  GFxStream::ReadStringWithLength(this: v38, a2: &v39);
  GFxStream::ReadStringWithLength(this: v38, a2: (struct GString *)&p);
  if ( (unsigned __int16)flags < 0x36Eu )
  {
    LOBYTE(flags) = 1;
  }
  else
  {
    v27 = *((char **)unused + 201);
    if ( v27 == nullptr )
      v27 = (char *)unused + 40;
    v28 = *((_DWORD *)v27 + 12) - *((_DWORD *)v27 + 11);
    v27[21] = 0;
    if ( v28 < 1 )
      GFxStream::PopulateBuffer1(result: v32);
    v29 = *((_DWORD *)v27 + 11);
    LOBYTE(flags) = *(_BYTE *)(v29 + *((_DWORD *)v27 + 15));
    *((_DWORD *)v27 + 11) = v29 + 1;
  }
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v38,
    a2: (int)"  DefineExternalImage2: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', exp = '%s', w = %d, h = %d\n",
    *(_DWORD *)tagInfo,
    v14,
    (unsigned __int16)v35,
    (const char *)((p.unused & 0xFFFFFFFC) + 8),
    (const char *)((v39.HeapTypeBits & 0xFFFFFFFC) + 8),
    (unsigned __int16)v36,
    (unsigned __int16)v34);
  GFx_CreateImageFileResourceHandle(
    a1: &v33,
    a2: (int)unused,
    a3: v14 & 0x9FFFF,
    a4: (unsigned __int8 *)((p.unused & 0xFFFFFFFC) + 8),
    a5: (unsigned __int8 *)((v39.HeapTypeBits & 0xFFFFFFFC) + 8),
    a6: v35,
    a7: v36,
    a8: (__int16)v34,
    a9: flags);
  if ( v33 == 0 && v34 != nullptr )
    GFxResource::Release(this: v34);
  v30 = (void *)(p.unused & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((p.unused & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v30);
  v31 = (void *)(v39.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v39.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v31);
}

//------------------------------------------------------------------------------
// Address: 0x100DEA10
// Name: void GFx_StartSoundLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_StartSoundLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 12))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v4, a2: (int)"GFx_StartSoundLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEA70
// Name: void GFx_DefineSoundLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineSoundLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 8))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v4, a2: (int)"GFx_DefineSoundLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEAD0
// Name: void GFx_ButtonSoundLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_ButtonSoundLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 16))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v4, a2: (int)"GFx_ButtonSoundLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEB30
// Name: void GFx_SoundStreamHeadLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_SoundStreamHeadLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 28))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v4, a2: (int)"GFx_SoundStreamHeadLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEB90
// Name: void GFx_SoundStreamBlockLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_SoundStreamBlockLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 32))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v4, a2: (int)"GFx_SoundStreamBlockLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEBF0
// Name: void GFx_DefineExternalSoundLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineExternalSoundLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 20))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(this: v4, a2: (int)"GFx_DefineExternalSoundLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEC50
// Name: void GFx_DefineExternalStreamSoundLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineExternalStreamSoundLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  int v3; // eax
  tagBITMAPINFOHEADER *v4; // eax
  GFxStream *v5; // eax

  v2 = *(_DWORD *)(*((_DWORD *)p + 4) + 52);
  if ( v2 != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int, struct GFxLoadProcess *, const struct GFxTagInfo *))(*(_DWORD *)v3 + 24))(
      a1: v3,
      a2: p,
      a3: tagInfo);
  }
  else
  {
    v4 = *((tagBITMAPINFOHEADER **)p + 201);
    if ( v4 == nullptr )
      v4 = (tagBITMAPINFOHEADER *)((char *)p + 40);
    GFxLogBase<GFxStream>::LogParse(
      this: v4,
      a2: (int)"GFx_DefineExternalStreamSoundLoader: Audio library is not set.\n");
    v5 = *((GFxStream **)p + 201);
    if ( v5 == nullptr )
      v5 = (GFxStream *)((char *)p + 40);
    GFxStream::LogTagBytes(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DECB0
// Name: void GFx_DefineExternalGradientImageLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineExternalGradientImageLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  tagBITMAPINFOHEADER *v2; // esi
  int v3; // eax
  int biWidth; // eax
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // eax
  void *v11; // esi
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  IShaderDevice *v13; // [esp+10h] [ebp-8h]
  struct GString v14; // [esp+14h] [ebp-4h] BYREF

  if ( *((_DWORD *)p + 201) != 0 )
    v2 = *((tagBITMAPINFOHEADER **)p + 201);
  else
    v2 = (tagBITMAPINFOHEADER *)((char *)p + 40);
  v3 = v2[1].biHeight - v2[1].biWidth;
  BYTE1(v2->biSizeImage) = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  biWidth = v2[1].biWidth;
  v5 = v2[1].biHeight - (biWidth + 2);
  v6 = *(unsigned __int16 *)(v2[1].biSizeImage + biWidth) | 0x50000;
  v2[1].biWidth = biWidth + 2;
  BYTE1(v2->biSizeImage) = 0;
  if ( v5 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v7 = v2[1].biWidth;
  v8 = (unsigned __int16)(*(unsigned __int8 *)(v2[1].biSizeImage + v7)
                        | (*(unsigned __int8 *)(v2[1].biSizeImage + v7 + 1) << 8));
  v7 += 2;
  v9 = v2[1].biHeight - v7;
  v2[1].biWidth = v7;
  BYTE1(v2->biSizeImage) = 0;
  if ( v9 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v10 = v2[1].biWidth;
  v13 = (IShaderDevice *)*(unsigned __int16 *)(v2[1].biSizeImage + v10);
  v2[1].biWidth = v10 + 2;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v14);
  GFxStream::ReadStringWithLength(this: (GFxStream *)v2, a2: &v14);
  GFxLogBase<GFxStream>::LogParse(
    this: v2,
    a2: (int)"  DefineExternalGradientImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', size = %d\n",
    *(_DWORD *)tagInfo,
    v6,
    v8,
    (const char *)((v14.HeapTypeBits & 0xFFFFFFFC) + 8),
    (unsigned __int16)v13);
  GFx_CreateImageFileResourceHandle(
    a1: &v12,
    a2: (int)p,
    a3: v6,
    a4: (unsigned __int8 *)((v14.HeapTypeBits & 0xFFFFFFFC) + 8),
    a5: (unsigned __int8 *)&pMem,
    a6: v8,
    a7: 0,
    a8: 0,
    a9: 1);
  if ( v12 == 0 && v13 != nullptr )
    GFxResource::Release(this: v13);
  v11 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x100DEE20
// Name: void GFx_DefineGradientMapLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFx_DefineGradientMapLoader(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        struct GFxLoadProcess *p,
        const struct GFxTagInfo *tagInfo)
{
  char savedregs; // [esp+0h] [ebp+0h]

  GFxLogBase<GFxLoadProcess>::LogWarning(
    this,
    pfmt: (unsigned int)p + 20,
    a3: (int)"Deprecated tag 1004 - DefineGradientMapLoader encountered, ignored\n",
    a4: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x100DEE40
// Name: void GFx_Scale9GridLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_Scale9GridLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v2; // esi
  int v3; // eax
  int v4; // eax
  unsigned int v5; // edi
  GArrayLH<GString,2,GArrayDefaultPolicy> *v6; // ecx
  GFxFSCommandHandler *v7; // edi
  double v8; // [esp+0h] [ebp-2Ch]
  double v9; // [esp+0h] [ebp-2Ch]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> r; // [esp+14h] [ebp-18h] BYREF
  float v11; // [esp+20h] [ebp-Ch]
  _TRIVERTEX *handle; // [esp+24h] [ebp-8h] BYREF
  GFxFSCommandHandler *v13; // [esp+28h] [ebp-4h]

  v2 = *((char **)p + 201);
  if ( v2 == nullptr )
    v2 = (char *)p + 40;
  *(float *)&r.m_pMemory = 0.0;
  *(float *)&r.m_nAllocationCount = 0.0;
  *(float *)&r.m_nGrowSize = 0.0;
  v11 = 0.0;
  v3 = *((_DWORD *)v2 + 12) - *((_DWORD *)v2 + 11);
  v2[21] = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v4 = *((_DWORD *)v2 + 11);
  v5 = *(unsigned __int16 *)(*((_DWORD *)v2 + 15) + v4);
  *((_DWORD *)v2 + 11) = v4 + 2;
  GFxStream::ReadRect(this: (GFxStream *)v2, a2: (int)&r);
  if ( GFxStream::IsVerboseParse(this: (GFxStream *)v2) )
    GFxLogBase<GFxLoadProcess>::LogParse(
      this: v6,
      pfmt: (unsigned int)p + 20,
      a3: (int)"Scale9GridLoader, id=%d, x=%d, y=%d, w=%d, h=%d\n",
      a4: v5);
  if ( *(float *)&r.m_nGrowSize <= (double)*(float *)&r.m_pMemory )
  {
    v8 = (*(float *)&r.m_nGrowSize - *(float *)&r.m_pMemory) / 20.0;
    GFxLogBase<GFxLoadProcess>::LogWarning(
      this: v6,
      pfmt: (unsigned int)p + 20,
      a3: (int)"Scale9Grid has negative width %f\n",
      a4: SLOBYTE(v8));
    return;
  }
  if ( v11 <= (double)*(float *)&r.m_nAllocationCount )
  {
    v9 = (v11 - *(float *)&r.m_nAllocationCount) / 20.0;
    GFxLogBase<GFxLoadProcess>::LogWarning(
      this: v6,
      pfmt: (unsigned int)p + 20,
      a3: (int)"Scale9Grid has negative height %f\n",
      a4: SLOBYTE(v9));
    return;
  }
  handle = nullptr;
  v13 = nullptr;
  if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
         this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p + 8),
         phandle: &handle,
         rid: v5) != 0 )
  {
    if ( handle != nullptr )
      return;
    v7 = v13;
    if ( v13 == nullptr )
      return;
    if ( (((int (__thiscall *)(GFxFSCommandHandler *))v13->__vftable[1].dtr_GRefCountImplCore)(a1: v13) & 0xFF00) == 0x8400 )
    {
      GFxSpriteDef::SetScale9Grid(
        this: v7,
        (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&r);
    }
    else if ( (((int (__thiscall *)(GFxFSCommandHandler *))v7->__vftable[1].dtr_GRefCountImplCore)(a1: v7) & 0xFF00) == 0x8100 )
    {
      GFxButtonCharacterDef::SetScale9Grid(
        this: (GFxAmpMessageCurrentState *)v7,
        (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&r);
    }
  }
  if ( handle == nullptr && v13 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v13);
}

//------------------------------------------------------------------------------
// Address: 0x100DEFF0
// Name: void GFx_DefineShapeLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineShapeLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // esi
  char *v3; // edi
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // ebx
  int v5; // eax
  int v6; // eax
  unsigned __int16 v7; // dx
  int v8; // ecx
  int (__thiscall *v9)(int, int, HBITMAP__ *); // edx
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // edi
  _DWORD *v12; // ecx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v13; // ecx
  int v14; // edi
  void (__thiscall *v15)(struct CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *); // edx
  char v16; // [esp+10h] [ebp-34h]
  _AUDIT_EVENT_TYPE cfg; // [esp+1Ch] [ebp-28h] BYREF
  IShaderAPI *v18; // [esp+28h] [ebp-1Ch]
  unsigned int v19; // [esp+40h] [ebp-4h]

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  v4 = nullptr;
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v5 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v5 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v6 = *((_DWORD *)v3 + 11);
  v7 = *(_WORD *)(*((_DWORD *)v3 + 15) + v6);
  *((_DWORD *)v3 + 11) = v6 + 2;
  v19 = v7;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)(v2.unused + 20),
    pfmt: v2.unused + 20,
    a3: (int)"  ShapeLoader: id = %d\n",
    a4: v7);
  v8 = *(_DWORD *)(*(_DWORD *)(v2.unused + 32) + 28);
  v9 = *(int (__thiscall **)(int, int, HBITMAP__ *))(*(_DWORD *)v8 + 40);
  p.unused = 258;
  v10 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v9(a1: v8, a2: 96, a3: &p);
  v11 = v10;
  if ( v10 != nullptr )
  {
    v10->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&GFxResource::`vftable';
    v10->m_nUserID = 1;
    v10->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = nullptr;
    v10->m_iRefs = 0x40000;
    v10->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&GFxConstShapeCharacterDef::`vftable';
    GFxConstShapeWithStyles::GFxConstShapeWithStyles(this: (GFxConstShapeWithStyles *)&v10->m_Proxy);
    v4 = v11;
  }
  v12 = *(_DWORD **)(v2.unused + 804);
  if ( v12 == nullptr )
    v12 = (_DWORD *)(v2.unused + 40);
  GFxConstShapeWithStyles::Read(
    this: (CBitRead *)&v4->m_Proxy,
    p: (GFxAmpMsgHandler *)v2.unused,
    a3: *(_DWORD *)tagInfo,
    lenInBytes: *((_DWORD *)tagInfo + 2) + *((_DWORD *)tagInfo + 3) - (v12[11] + v12[13] - v12[12]),
    i: 1u);
  v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2.unused + 16) + 8) + 32);
  if ( v14 != 0 )
  {
    GFxRenderConfig::GFxRenderConfig(
      this: (GFxRenderConfig *)&cfg,
      a2: *(_BYTE *)(v14 + 16) != 0 ? 0x10 : 0,
      a3: 0xFFFFFFFF,
      a4: 0xFFFFFFFF);
    v15 = v4->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[2].operator();
    tagInfo = *(const struct GFxTagInfo **)(v14 + 12);
    ((void (__thiscall *)(CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, const struct GFxTagInfo *, _AUDIT_EVENT_TYPE *))v15)(
      a1: v4,
      a2: tagInfo,
      a3: &cfg);
    if ( v18 != nullptr )
      GRefCountImpl::Release(this: v18);
    cfg = (_AUDIT_EVENT_TYPE)&GFxState::`vftable';
    GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&cfg);
  }
  GFxLogBase<GFxLoadProcess>::LogParse(this: v13, pfmt: v2.unused + 20, a3: (int)"  bound rect:", a4: v16);
  GFxStream::LogParseClass(result: (tagEMRANGLEARC *)((char *)&v4->m_Proxy.m_pfnProxied + 4));
  if ( *(_DWORD *)(v2.unused + 760) == 0 )
    GFxMovieDataDef::LoadTaskData::AddResource(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v2.unused + 32),
      rid: v19,
      pres: v4);
  if ( v4 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v4);
}

//------------------------------------------------------------------------------
// Address: 0x100DF180
// Name: void GFx_DefineSubImageLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineSubImageLoader(HBITMAP__ p, const struct GFxTagInfo *tagInfo)
{
  HBITMAP__ v2; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  __int16 v12; // dx
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  __int16 v17; // dx
  int v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  __int16 v22; // dx
  int v23; // esi
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  __int16 v27; // dx
  int v28; // esi
  int v29; // eax
  int v30; // eax
  unsigned __int16 v31; // dx
  volatile int v32; // ebx
  GRefCountNTSImpl *v33; // eax
  GRefCountNTSImpl *v34; // esi
  volatile int v35; // ecx
  GRefCountNTSImpl_vtbl *v36; // edx
  int v37; // [esp+Ch] [ebp-24h]
  IShaderDevice *v38; // [esp+10h] [ebp-20h]
  _IMAGE_CE_RUNTIME_FUNCTION_ENTRY rdata; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int bitmapResourceId; // [esp+1Ch] [ebp-14h]
  int v41; // [esp+20h] [ebp-10h]
  int v42; // [esp+24h] [ebp-Ch]
  int v43; // [esp+28h] [ebp-8h]
  unsigned int baseImageId; // [esp+2Ch] [ebp-4h]

  v2.unused = p.unused;
  v3 = *(char **)(p.unused + 804);
  if ( v3 == nullptr )
    v3 = (char *)(p.unused + 40);
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v8 = *(_DWORD *)(v2.unused + 804);
  bitmapResourceId = (unsigned __int16)(v6 | (v7 << 8));
  if ( v8 == 0 )
    v8 = v2.unused + 40;
  v9 = *(_DWORD *)(v8 + 48) - *(_DWORD *)(v8 + 44);
  *(_BYTE *)(v8 + 21) = 0;
  if ( v9 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v10 = *(_DWORD *)(v8 + 44);
  v11 = *(_DWORD *)(v8 + 60);
  v12 = *(unsigned __int8 *)(v11 + v10 + 1);
  LOWORD(v11) = *(unsigned __int8 *)(v11 + v10);
  *(_DWORD *)(v8 + 44) = v10 + 2;
  v13 = *(_DWORD *)(v2.unused + 804);
  baseImageId = (unsigned __int16)(v11 | (v12 << 8));
  if ( v13 == 0 )
    v13 = v2.unused + 40;
  v14 = *(_DWORD *)(v13 + 48) - *(_DWORD *)(v13 + 44);
  *(_BYTE *)(v13 + 21) = 0;
  if ( v14 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v15 = *(_DWORD *)(v13 + 44);
  v16 = *(_DWORD *)(v13 + 60);
  v17 = *(unsigned __int8 *)(v16 + v15 + 1);
  LOWORD(v16) = *(unsigned __int8 *)(v16 + v15);
  *(_DWORD *)(v13 + 44) = v15 + 2;
  v18 = *(_DWORD *)(v2.unused + 804);
  v43 = (unsigned __int16)(v16 | (v17 << 8));
  if ( v18 == 0 )
    v18 = v2.unused + 40;
  v19 = *(_DWORD *)(v18 + 48) - *(_DWORD *)(v18 + 44);
  *(_BYTE *)(v18 + 21) = 0;
  if ( v19 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v20 = *(_DWORD *)(v18 + 44);
  v21 = *(_DWORD *)(v18 + 60);
  v22 = *(unsigned __int8 *)(v21 + v20 + 1);
  LOWORD(v21) = *(unsigned __int8 *)(v21 + v20);
  *(_DWORD *)(v18 + 44) = v20 + 2;
  v23 = *(_DWORD *)(v2.unused + 804);
  v42 = (unsigned __int16)(v21 | (v22 << 8));
  if ( v23 == 0 )
    v23 = v2.unused + 40;
  v24 = *(_DWORD *)(v23 + 48) - *(_DWORD *)(v23 + 44);
  *(_BYTE *)(v23 + 21) = 0;
  if ( v24 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v25 = *(_DWORD *)(v23 + 44);
  v26 = *(_DWORD *)(v23 + 60);
  v27 = *(unsigned __int8 *)(v26 + v25 + 1);
  LOWORD(v26) = *(unsigned __int8 *)(v26 + v25);
  *(_DWORD *)(v23 + 44) = v25 + 2;
  v28 = *(_DWORD *)(v2.unused + 804);
  v41 = (unsigned __int16)(v26 | (v27 << 8));
  if ( v28 == 0 )
    v28 = v2.unused + 40;
  v29 = *(_DWORD *)(v28 + 48) - *(_DWORD *)(v28 + 44);
  *(_BYTE *)(v28 + 21) = 0;
  if ( v29 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v30 = *(_DWORD *)(v28 + 44);
  v31 = *(_WORD *)(*(_DWORD *)(v28 + 60) + v30);
  *(_DWORD *)(v28 + 44) = v30 + 2;
  v32 = v31;
  p.unused = 2;
  v33 = (GRefCountNTSImpl *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &p);
  v34 = nullptr;
  if ( v33 != nullptr )
  {
    v33->__vftable = (GRefCountNTSImpl_vtbl *)&GRefCountImplCore::`vftable';
    v33->RefCount = 1;
    v33->__vftable = (GRefCountNTSImpl_vtbl *)&GFxSubImageResourceInfo::`vftable';
    v33[1].__vftable = (GRefCountNTSImpl_vtbl *)0x40000;
    v33[1].RefCount = 0;
    v33[2].__vftable = nullptr;
    v33[2].RefCount = 0;
    v33[3].__vftable = nullptr;
    v33[3].RefCount = 0;
    v34 = v33;
  }
  v35 = (unsigned __int16)v42;
  v36 = (GRefCountNTSImpl_vtbl *)(unsigned __int16)v41;
  v34[1].__vftable = (GRefCountNTSImpl_vtbl *)(baseImageId | 0x90000);
  v34[2].__vftable = (GRefCountNTSImpl_vtbl *)(unsigned __int16)v43;
  v34[2].RefCount = v35;
  v34[3].__vftable = v36;
  v34[3].RefCount = v32;
  GFxSubImageResourceCreator::CreateSubImageResourceData(a1: &rdata, a2: v34);
  GFxLoadProcess::AddDataResource();
  if ( v37 == 0 && v38 != nullptr )
    GFxResource::Release(this: v38);
  if ( rdata.FuncStart != 0 )
    (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)rdata.FuncStart + 8))(
      a1: rdata.FuncStart,
      a2: *((_DWORD *)&rdata + 1));
  if ( v34 != nullptr )
    GRefCountNTSImpl::Release(this: v34);
}

//------------------------------------------------------------------------------
// Address: 0x100DF540
// Name: void GFx_SetBackgroundColorLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_SetBackgroundColorLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  unsigned int v3; // edx
  CP4File *v4; // ecx
  CP4File_vtbl *v5; // eax
  GFxSetBackgroundColor *v6; // ebx
  char *v7; // edi
  unsigned int v8; // esi
  GFxSetBackgroundColor **v9; // eax

  v2 = *((_DWORD *)p + 8);
  v3 = *(_DWORD *)(v2 + 12);
  v4 = (CP4File *)(v2 + 8);
  if ( v3 < 8 )
  {
    v5 = GFxDataAllocator::OverflowAlloc(this: v4, bytes: 8u);
  }
  else
  {
    v5 = v4->__vftable;
    v4->__vftable = (CP4File_vtbl *)((char *)v4->__vftable + 8);
    v4->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v3 - 8);
  }
  if ( v5 != nullptr )
  {
    v5->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxSetBackgroundColor::`vftable';
    v6 = (GFxSetBackgroundColor *)v5;
  }
  else
  {
    v6 = nullptr;
  }
  GFxSetBackgroundColor::Read(this: v6, a2: p);
  v7 = (char *)p + 12 * *((_DWORD *)p + 190) + 768;
  v8 = *((_DWORD *)v7 + 1) + 1;
  if ( v8 >= *((_DWORD *)v7 + 1) )
  {
    if ( v8 >= *((_DWORD *)v7 + 2) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v7,
        result: (D3DXVECTOR4 *)v7,
        newCapacity: v8 + (v8 >> 2));
  }
  else if ( v8 < *((_DWORD *)v7 + 2) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v7,
      result: (D3DXVECTOR4 *)v7,
      newCapacity: *((_DWORD *)v7 + 1) + 1);
  }
  v9 = (GFxSetBackgroundColor **)(*(_DWORD *)v7 + 4 * v8 - 4);
  *((_DWORD *)v7 + 1) = v8;
  if ( v9 != nullptr )
    *v9 = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100DF5E0
// Name: void UndoAndFilterPremultiplied(class GImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UndoAndFilterPremultiplied(struct GImage *a1)
{
  struct GImage *v1; // ebx
  unsigned int v2; // esi
  unsigned int v3; // edi
  unsigned __int8 *v4; // edi
  bool v5; // zf
  unsigned int v6; // eax
  unsigned __int8 *v7; // edi
  int v8; // eax
  unsigned int v9; // edx
  unsigned __int8 *v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // edx
  char *v15; // edx
  unsigned __int8 v16; // al
  unsigned __int8 *v17; // edi
  unsigned int v18; // ebx
  int v19; // edx
  unsigned int v20; // eax
  int v21; // edx
  unsigned int v22; // edi
  char v23; // al
  char v24; // al
  unsigned int v25; // eax
  unsigned __int8 v26; // bl
  int v27; // edi
  unsigned __int8 v28; // bl
  unsigned __int8 *dst[3]; // [esp+4h] [ebp-2Ch] BYREF
  unsigned int v30; // [esp+10h] [ebp-20h]
  unsigned int v31; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *v32; // [esp+18h] [ebp-18h]
  char *v33; // [esp+1Ch] [ebp-14h]
  unsigned int v34; // [esp+20h] [ebp-10h]
  int v35; // [esp+24h] [ebp-Ch]
  unsigned int v36; // [esp+28h] [ebp-8h]
  unsigned __int8 *v37; // [esp+2Ch] [ebp-4h]

  v1 = a1;
  if ( a1->Format == Image_ARGB_8888 )
  {
    v2 = 4 * a1->Width + 8;
    v3 = v2 * (a1->Height + 2);
    memset(dst, 0, sizeof(dst));
    GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)dst,
      pheapAddr: (ButtonCode_t)dst,
      newCapacity: v3 + (v3 >> 2));
    if ( v3 == 0 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: dst[0]);
      return;
    }
    v4 = dst[0];
    memset(dst: dst[0], value: 0, count: v2);
    memset(dst: &v4[v2 * (a1->Height + 1)], value: 0, count: v2);
    v5 = a1->Height == 0;
    v36 = 0;
    if ( !v5 )
    {
      v33 = (char *)(5 - v2);
      v34 = 4 - v2;
      v35 = 3 - v2;
      v6 = 6 - v2;
      v7 = &v4[2 * v2 - 4];
      v32 = (unsigned __int8 *)(6 - v2);
      v37 = (unsigned __int8 *)(2 - v2);
      while ( 1 )
      {
        memcpy(dst: &v7[v6 + 2], src: &a1->pData[v36 * a1->Pitch], count: 4 * a1->Width);
        v8 = v35;
        v9 = v34;
        v7[(_DWORD)v33 + 2] = 0;
        v10 = v37;
        v7[v8 + 2] = 0;
        v11 = v36;
        v7[v9 + 2] = 0;
        v7[(_DWORD)v10 + 2] = 0;
        *(_DWORD *)v7 = 0;
        v7 += v2;
        v36 = v11 + 1;
        if ( v11 + 1 >= a1->Height )
          break;
        v6 = (unsigned int)v32;
      }
      v4 = dst[0];
    }
    v12 = 0;
    v36 = 0;
    if ( a1->Height == 0 )
      goto LABEL_32;
    v13 = v4 + 3;
    v32 = v4 + 3;
    v35 = (int)&v4[2 * v2 + 5];
    while ( 1 )
    {
      v14 = (int)&v1->pData[v12 * v1->Pitch];
      v5 = v1->Width == 0;
      v34 = 0;
      if ( v5 )
        goto LABEL_31;
      v15 = (char *)(v14 + 1);
      v33 = v15;
      v37 = (unsigned __int8 *)v35;
      do
      {
        v16 = v15[2];
        if ( v16 >= 0x10u )
        {
          v26 = *(v15 - 1);
          v27 = *((unsigned __int16 *)GFx_UndoPremultiplyTable + v16);
          if ( v26 > v16 )
            v26 = v15[2];
          *(v15 - 1) = (unsigned __int16)(v27 * v26) >> 8;
          v28 = *v15;
          if ( (unsigned __int8)*v15 > v16 )
            v28 = v16;
          *v15 = (unsigned __int16)(v27 * v28) >> 8;
          if ( (unsigned __int8)v15[1] <= v16 )
            v16 = v15[1];
          v25 = (v27 * (unsigned int)v16) >> 8;
        }
        else
        {
          v17 = &v13[v2 + 1];
          v18 = *v13 + v13[v2 + v2] + v17[v2 + 7] + v37[2] + v13[4] + v13[8] + v13[v2 + 8] + v13[v2 + 4] + v13[v2];
          if ( v18 == 0 )
            goto LABEL_29;
          v19 = v13[v2 - 2];
          v31 = ((v17[v2 - 4]
                + v17[v2 + 4]
                + *v17
                + *(v37 - 1)
                + v13[1]
                + *(v13 - 3)
                + v13[5]
                + v13[v2 - 3]
                + (unsigned int)v13[v2 + 5]) << 8)
              / v18;
          v20 = ((*v37
                + v17[v2 - 3]
                + v17[v2 + 5]
                + v13[2]
                + *(v13 - 2)
                + v13[6]
                + v13[v2 + 6]
                + v19
                + (unsigned int)v13[v2 + 2]) << 8)
              / v18;
          v21 = v13[v2 + 7];
          v30 = v20;
          v22 = ((v17[v2 - 2]
                + v17[v2 + 6]
                + v37[1]
                + *(v13 - 1)
                + v13[3]
                + v13[7]
                + v13[v2 + 3]
                + v21
                + (unsigned int)v13[v2 - 1]) << 8)
              / v18;
          v23 = v31;
          if ( v31 > 0xFF )
            v23 = -1;
          v15 = v33;
          *(v33 - 1) = v23;
          v24 = v30;
          if ( v30 > 0xFF )
            v24 = -1;
          *v15 = v24;
          LOBYTE(v25) = v22;
          if ( v22 > 0xFF )
            LOBYTE(v25) = -1;
        }
        v15[1] = v25;
LABEL_29:
        v1 = a1;
        v37 += 4;
        v15 += 4;
        v13 += 4;
        ++v34;
        v33 = v15;
      }
      while ( v34 < a1->Width );
      v4 = dst[0];
      v12 = v36;
LABEL_31:
      v35 += v2;
      ++v12;
      v13 = &v32[v2];
      v36 = v12;
      v32 += v2;
      if ( v12 >= v1->Height )
      {
LABEL_32:
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF950
// Name: void GFx_DefineBitsJpeg3Loader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineBitsJpeg3Loader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  char *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  char *v8; // edi
  int v9; // edx
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // ecx
  struct GImage *v13; // ebx
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  GMemoryHeap *v17; // eax
  GFxStream *v18; // ebx
  unsigned __int8 *v19; // ecx
  IShaderDeviceMgr *v20; // eax
  signed int v21; // edi
  unsigned __int8 *v22; // eax
  char *v23; // ecx
  signed int i; // eax
  int v25; // [esp+0h] [ebp-1Ch]
  GArrayLH<GString,2,GArrayDefaultPolicy> *v26; // [esp+Ch] [ebp-10h]
  int v27; // [esp+10h] [ebp-Ch]
  int v28; // [esp+14h] [ebp-8h] BYREF
  unsigned __int8 *buffer; // [esp+18h] [ebp-4h]
  HBITMAP__ pa; // [esp+24h] [ebp+8h]

  v3 = *((char **)p + 201);
  if ( v3 == nullptr )
    v3 = (char *)p + 40;
  v4 = *((_DWORD *)v3 + 12) - *((_DWORD *)v3 + 11);
  v3[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v3 + 11);
  v6 = *((_DWORD *)v3 + 15);
  v7 = *(unsigned __int8 *)(v6 + v5 + 1);
  LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
  *((_DWORD *)v3 + 11) = v5 + 2;
  v26 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)(unsigned __int16)(v6 | (v7 << 8));
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: v26,
    pfmt: (unsigned int)p + 20,
    a3: (int)"  GFx_DefineBitsJpeg3Loader: charid = %d pos = %d\n",
    a4: v6);
  v8 = *((char **)p + 201);
  if ( v8 == nullptr )
    v8 = (char *)p + 40;
  v9 = *((_DWORD *)v8 + 12) - *((_DWORD *)v8 + 11);
  v8[21] = 0;
  if ( v9 < 4 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
  v10 = *((_DWORD *)v8 + 11);
  v11 = *(unsigned __int8 *)(v10 + *((_DWORD *)v8 + 15))
      | ((*(unsigned __int8 *)(v10 + *((_DWORD *)v8 + 15) + 1)
        | ((*(unsigned __int8 *)(*((_DWORD *)v8 + 15) + v10 + 2)
          | (*(unsigned __int8 *)(*((_DWORD *)v8 + 15) + v10 + 3) << 8)) << 8)) << 8);
  *((_DWORD *)v8 + 11) = v10 + 4;
  v12 = *((_DWORD **)p + 201);
  if ( v12 == nullptr )
    v12 = (_DWORD *)((char *)p + 40);
  v13 = nullptr;
  v14 = v12[11] + v12[13] - v12[12];
  v15 = *((_DWORD *)p + 4);
  v16 = v11 + v14;
  v27 = *(_DWORD *)(v15 + 40);
  if ( v27 != 0 )
  {
    buffer = *(unsigned __int8 **)(v15 + 36);
    if ( buffer != nullptr )
    {
      if ( GFxLoadStates::GetLoadTimeImageCreator(this: (GFxLoadStates *)v15, a2: *((_DWORD *)p + 178)) != nullptr )
        v17 = GMemory::pGlobalHeap;
      else
        GFxMovieDataDef::LoadTaskData::GetImageHeap(this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)p
                                                          + 8));
      v18 = *((GFxStream **)p + 201);
      pa.unused = (int)v17;
      if ( v18 == nullptr )
        v18 = (GFxStream *)((char *)p + 40);
      GFxStream::SyncFileStream(this: v18);
      v19 = buffer;
      *((_BYTE *)v18 + 56) = 1;
      v13 = (struct GImage *)(*(int (__thiscall **)(unsigned __int8 *, _LUID_AND_ATTRIBUTES *, HBITMAP__))(*(_DWORD *)v19 + 20))(
                               a1: v19,
                               a2: (_LUID_AND_ATTRIBUTES *)v18[4],
                               a3: pa);
      v20 = *((IShaderDeviceMgr **)p + 201);
      if ( v20 == nullptr )
        v20 = (IShaderDeviceMgr *)((char *)p + 40);
      GFxStream::SetPosition(this: v20, pos: v16, a3: v25);
      v21 = v13->Width * v13->Height;
      v28 = 2;
      v22 = (unsigned __int8 *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v21, a3: &v28);
      v23 = *((char **)p + 201);
      buffer = v22;
      if ( v23 == nullptr )
        v23 = (char *)p + 40;
      (*(void (__thiscall **)(int, char *, unsigned __int8 *, signed int))(*(_DWORD *)v27 + 8))(
        a1: v27,
        a2: v23,
        a3: v22,
        a4: v21);
      for ( i = 0; i < v21; ++i )
        v13->pData[4 * i + 3] = buffer[i];
      UndoAndFilterPremultiplied(a1: v13);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: buffer);
    }
    else
    {
      GFxLogBase<GFxLoadProcess>::LogError(
        this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v15,
        pfmt: (unsigned int)p + 20,
        a3: (int)"Error: Jpeg System is not installed - can't load jpeg image data\n",
        a4: v25);
    }
  }
  else
  {
    GFxLogBase<GFxLoadProcess>::LogError(
      this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)v15,
      pfmt: (unsigned int)p + 20,
      a3: (int)"Error: GFxZlibState is not set - can't load zipped image data\n",
      a4: v25);
  }
  GFxLoadProcess::AddImageResource(result: (const GFxAmpCurrentState *)v26);
  if ( v13 != nullptr )
    GRefCountNTSImpl::Release(this: v13);
}

//------------------------------------------------------------------------------
// Address: 0x100DFB80
// Name: void GFx_DefineBitsLossless2Loader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_DefineBitsLossless2Loader(struct GFxLoadProcess *r, const struct GFxTagInfo *g)
{
  char *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  __int16 v6; // dx
  char *v7; // esi
  int v8; // eax
  int v9; // eax
  unsigned __int8 v10; // dl
  char *v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  __int16 v15; // dx
  char *v16; // esi
  int v17; // eax
  int v18; // eax
  signed int v19; // ebx
  int v20; // esi
  GArrayLH<GString,2,GArrayDefaultPolicy> *v21; // ecx
  unsigned int Size; // eax
  GMemoryHeap *v23; // eax
  unsigned __int8 v24; // al
  int v25; // eax
  unsigned int v26; // edi
  char *v27; // eax
  int v28; // ecx
  int v29; // edi
  _BYTE *v30; // eax
  char *v31; // ecx
  GMemoryHeap_vtbl *v32; // eax
  int v33; // eax
  char *v34; // ecx
  int v35; // edx
  int v36; // eax
  int v37; // ecx
  _BYTE *v38; // edi
  unsigned int v39; // eax
  char v40; // dl
  char *v41; // eax
  int v42; // edi
  int v43; // eax
  int v44; // edi
  char *v45; // ecx
  char *v46; // eax
  _BYTE *v47; // ecx
  int i; // edi
  char v49; // bl
  unsigned __int8 v50; // al
  int v51; // eax
  unsigned int v52; // edi
  char *v53; // eax
  int v54; // ecx
  int v55; // edi
  char *v56; // eax
  char *v57; // ecx
  GMemoryHeap_vtbl *v58; // eax
  int v59; // eax
  char *v60; // ecx
  signed int v61; // ecx
  int v62; // edx
  int v63; // edi
  char *v64; // ecx
  unsigned int v65; // eax
  char *v66; // eax
  unsigned __int8 *v67; // eax
  char v68; // cl
  CDefaultLoggingResponsePolicy_vtbl *v69; // esi
  int v70; // [esp-14h] [ebp-44h]
  _cpinfo *v71; // [esp+0h] [ebp-30h]
  const GFxAmpCurrentState *v72; // [esp+Ch] [ebp-24h]
  unsigned int v73; // [esp+10h] [ebp-20h] BYREF
  int m; // [esp+14h] [ebp-1Ch] BYREF
  int BufferBytes; // [esp+18h] [ebp-18h]
  int pitch; // [esp+1Ch] [ebp-14h]
  int j; // [esp+20h] [ebp-10h]
  signed int k; // [esp+24h] [ebp-Ch]
  CDefaultLoggingResponsePolicy pimage; // [esp+28h] [ebp-8h]
  unsigned __int8 b; // [esp+2Fh] [ebp-1h]
  char r_3; // [esp+3Bh] [ebp+Bh]
  char *ga; // [esp+3Ch] [ebp+Ch]
  char *gb; // [esp+3Ch] [ebp+Ch]
  int gc; // [esp+3Ch] [ebp+Ch]
  unsigned int gd; // [esp+3Ch] [ebp+Ch]
  char *ge; // [esp+3Ch] [ebp+Ch]
  char *gf; // [esp+3Ch] [ebp+Ch]
  signed int gg; // [esp+3Ch] [ebp+Ch]
  char g_3; // [esp+3Fh] [ebp+Fh]
  char g_3a; // [esp+3Fh] [ebp+Fh]

  v2 = *((char **)r + 201);
  if ( v2 == nullptr )
    v2 = (char *)r + 40;
  v3 = *((_DWORD *)v2 + 12) - *((_DWORD *)v2 + 11);
  v2[21] = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v4 = *((_DWORD *)v2 + 11);
  v5 = *((_DWORD *)v2 + 15);
  v6 = *(unsigned __int8 *)(v5 + v4 + 1);
  LOWORD(v5) = *(unsigned __int8 *)(v5 + v4);
  *((_DWORD *)v2 + 11) = v4 + 2;
  v7 = *((char **)r + 201);
  pitch = (unsigned __int16)(v5 | (v6 << 8));
  if ( v7 == nullptr )
    v7 = (char *)r + 40;
  v8 = *((_DWORD *)v7 + 12) - *((_DWORD *)v7 + 11);
  v7[21] = 0;
  if ( v8 < 1 )
    GFxStream::PopulateBuffer1(result: v71);
  v9 = *((_DWORD *)v7 + 11);
  v10 = *(_BYTE *)(v9 + *((_DWORD *)v7 + 15));
  *((_DWORD *)v7 + 11) = v9 + 1;
  v11 = *((char **)r + 201);
  b = v10;
  if ( v11 == nullptr )
    v11 = (char *)r + 40;
  v12 = *((_DWORD *)v11 + 12) - *((_DWORD *)v11 + 11);
  v11[21] = 0;
  if ( v12 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v13 = *((_DWORD *)v11 + 11);
  v14 = *((_DWORD *)v11 + 15);
  v15 = *(unsigned __int8 *)(v14 + v13 + 1);
  LOWORD(v14) = *(unsigned __int8 *)(v14 + v13);
  *((_DWORD *)v11 + 11) = v13 + 2;
  v16 = *((char **)r + 201);
  BufferBytes = (unsigned __int16)(v14 | (v15 << 8));
  if ( v16 == nullptr )
    v16 = (char *)r + 40;
  v17 = *((_DWORD *)v16 + 12) - *((_DWORD *)v16 + 11);
  v16[21] = 0;
  if ( v17 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v18 = *((_DWORD *)v16 + 11);
  v19 = *(unsigned __int16 *)(*((_DWORD *)v16 + 15) + v18);
  *((_DWORD *)v16 + 11) = v18 + 2;
  v20 = (unsigned __int16)BufferBytes;
  v72 = (const GFxAmpCurrentState *)(unsigned __int16)pitch;
  v70 = *(_DWORD *)g;
  m = v19;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)((char *)r + 20),
    pfmt: (unsigned int)r + 20,
    a3: (int)"  DefBitsLossless2: tagInfo.TagType = %d, id = %d, fmt = %d, w = %d, h = %d\n",
    a4: v70);
  v21 = *((GArrayLH<GString,2,GArrayDefaultPolicy> **)r + 4);
  Size = v21[3].Data.Size;
  pimage.__vftable = nullptr;
  k = Size;
  if ( Size == 0 )
  {
    GFxLogBase<GFxLoadProcess>::LogError(
      this: v21,
      pfmt: (unsigned int)r + 20,
      a3: (int)"Error: GFxZlibState is not set - can't load zipped image data\n",
      a4: (char)v71);
    goto LABEL_89;
  }
  if ( GFxLoadStates::GetLoadTimeImageCreator(this: (GFxLoadStates *)v21, a2: *((_DWORD *)r + 178)) != nullptr )
    v23 = GMemory::pGlobalHeap;
  else
    GFxMovieDataDef::LoadTaskData::GetImageHeap(this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)r
                                                      + 8));
  if ( *(_DWORD *)g == 20 )
  {
    pimage.__vftable = (CDefaultLoggingResponsePolicy_vtbl *)GImage::CreateImage(
                                                               result: (ICachedPerFrameMeshData *)2,
                                                               width: (unsigned __int16)BufferBytes,
                                                               height: v19,
                                                               a4: (int)v23);
    if ( b == 3 )
    {
      GFxLoadProcess::ReadU8(this: (GFxAmpMsgHandler *)r);
      v25 = 3 * v24 + 3;
      v26 = v25 + (((unsigned __int16)BufferBytes + 3) & 0xFFFFFFFC) * v19;
      pitch = ((unsigned __int16)BufferBytes + 3) & 0xFFFFFFFC;
      BufferBytes = v25;
      m = 2;
      ga = (char *)GMemory::pGlobalHeap->Alloc_2(
                     this: GMemory::pGlobalHeap,
                     a2: v25 + ((v20 + 3) & 0xFFFFFFFC) * v19,
                     a3: &m);
      v27 = *((char **)r + 201);
      if ( v27 == nullptr )
        v27 = (char *)r + 40;
      (*(void (__thiscall **)(signed int, char *, char *, unsigned int))(*(_DWORD *)k + 8))(
        a1: k,
        a2: v27,
        a3: ga,
        a4: v26);
      v28 = 0;
      j = 0;
      if ( v19 > 0 )
      {
        k = (signed int)&ga[BufferBytes];
        do
        {
          v29 = 0;
          if ( v20 > 0 )
          {
            v30 = (char *)pimage.__vftable[6].OnLog + v28 * (int)pimage.__vftable[5].OnLog + 2;
            do
            {
              v31 = &ga[2 * *(unsigned __int8 *)(k + v29) + *(unsigned __int8 *)(k + v29)];
              *(v30 - 2) = *v31;
              *(v30 - 1) = v31[1];
              *v30 = v31[2];
              ++v29;
              v30 += 3;
            }
            while ( v29 < v20 );
            v28 = j;
          }
          k += pitch;
          j = ++v28;
        }
        while ( v28 < v19 );
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: ga);
      goto LABEL_89;
    }
    if ( b == 4 )
    {
      v73 = (2 * (unsigned __int16)BufferBytes + 3) & 0xFFFFFFFC;
      m = 2;
      v32 = GMemory::pGlobalHeap->__vftable;
      BufferBytes = v73 * v19;
      v33 = (int)v32->Alloc_2(
                   this: GMemory::pGlobalHeap,
                   a2: ((2 * v20 + 3) & 0xFFFFFFFC) * v19,
                   a3: (const GAllocDebugInfo *)&m);
      v34 = *((char **)r + 201);
      pitch = v33;
      if ( v34 != nullptr )
        gb = v34;
      else
        gb = (char *)r + 40;
      (*(void (__thiscall **)(signed int, char *, int, int))(*(_DWORD *)k + 8))(a1: k, a2: gb, a3: v33, a4: BufferBytes);
      v35 = 0;
      j = 0;
      if ( v19 > 0 )
      {
        v36 = pitch;
        gc = pitch;
        do
        {
          v37 = 0;
          if ( v20 > 0 )
          {
            v38 = (char *)pimage.__vftable[6].OnLog + v35 * (int)pimage.__vftable[5].OnLog + 2;
            do
            {
              v39 = *(unsigned __int16 *)(v36 + 2 * v37);
              *(v38 - 2) = (v39 >> 7) & 0xF8;
              v40 = (v39 >> 2) & 0xF8;
              *v38 = 8 * v39;
              v36 = gc;
              *(v38 - 1) = v40;
              ++v37;
              v38 += 3;
            }
            while ( v37 < v20 );
            v35 = j;
          }
          v36 += v73;
          j = ++v35;
          gc = v36;
        }
        while ( v35 < v19 );
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)pitch);
      goto LABEL_89;
    }
    if ( b != 5 )
      goto LABEL_89;
    v73 = 2;
    gd = 4 * (unsigned __int16)BufferBytes * v19;
    BufferBytes = (int)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: gd, a3: &v73);
    v41 = *((char **)r + 201);
    if ( v41 == nullptr )
      v41 = (char *)r + 40;
    v42 = BufferBytes;
    (*(void (__thiscall **)(signed int, char *, int, unsigned int))(*(_DWORD *)k + 8))(
      a1: k,
      a2: v41,
      a3: BufferBytes,
      a4: gd);
    v43 = 0;
    pitch = 0;
    if ( v19 > 0 )
    {
      v44 = v42 + 2;
      j = v44;
      do
      {
        v45 = (char *)pimage.__vftable[6].OnLog + v43 * (int)pimage.__vftable[5].OnLog;
        if ( v20 > 0 )
        {
          v46 = (char *)v44;
          v47 = v45 + 2;
          for ( i = v20; i != 0; --i )
          {
            g_3 = *v46;
            v49 = v46[1];
            *(v47 - 2) = *(v46 - 1);
            *(v47 - 1) = g_3;
            *v47 = v49;
            v46 += 4;
            v47 += 3;
          }
          v19 = m;
          v43 = pitch;
        }
        ++v43;
        v44 = 4 * v20 + j;
        pitch = v43;
        j = v44;
      }
      while ( v43 < v19 );
    }
LABEL_56:
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)BufferBytes);
    goto LABEL_89;
  }
  pimage.__vftable = (CDefaultLoggingResponsePolicy_vtbl *)GImage::CreateImage(
                                                             result: (ICachedPerFrameMeshData *)1,
                                                             width: (unsigned __int16)BufferBytes,
                                                             height: v19,
                                                             a4: (int)v23);
  switch ( b )
  {
    case 3u:
      GFxLoadProcess::ReadU8(this: (GFxAmpMsgHandler *)r);
      v51 = 4 * (v50 + 1);
      v52 = v51 + (((unsigned __int16)BufferBytes + 3) & 0xFFFFFFFC) * v19;
      pitch = ((unsigned __int16)BufferBytes + 3) & 0xFFFFFFFC;
      m = v51;
      v73 = 2;
      ge = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v52, a3: &v73);
      v53 = *((char **)r + 201);
      if ( v53 == nullptr )
        v53 = (char *)r + 40;
      (*(void (__thiscall **)(signed int, char *, char *, unsigned int))(*(_DWORD *)k + 8))(
        a1: k,
        a2: v53,
        a3: ge,
        a4: v52);
      v54 = 0;
      BufferBytes = 0;
      if ( v19 > 0 )
      {
        k = (signed int)&ge[m];
        do
        {
          v55 = 0;
          if ( v20 > 0 )
          {
            v56 = (char *)pimage.__vftable[6].OnLog + v54 * (int)pimage.__vftable[5].OnLog + 2;
            do
            {
              v57 = &ge[4 * *(unsigned __int8 *)(k + v55)];
              *(v56 - 2) = *v57;
              *(v56 - 1) = v57[1];
              *v56 = v57[2];
              v56[1] = v57[3];
              ++v55;
              v56 += 4;
            }
            while ( v55 < v20 );
            v54 = BufferBytes;
          }
          k += pitch;
          BufferBytes = ++v54;
        }
        while ( v54 < v19 );
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: ge);
      break;
    case 4u:
      j = (2 * (unsigned __int16)BufferBytes + 3) & 0xFFFFFFFC;
      v73 = 2;
      v58 = GMemory::pGlobalHeap->__vftable;
      pitch = j * v19;
      v59 = (int)v58->Alloc_2(this: GMemory::pGlobalHeap, a2: j * v19, a3: (const GAllocDebugInfo *)&v73);
      v60 = *((char **)r + 201);
      BufferBytes = v59;
      if ( v60 != nullptr )
        gf = v60;
      else
        gf = (char *)r + 40;
      (*(void (__thiscall **)(signed int, char *, int, int))(*(_DWORD *)k + 8))(a1: k, a2: gf, a3: v59, a4: pitch);
      v61 = 0;
      gg = 0;
      if ( v19 > 0 )
      {
        v62 = BufferBytes;
        do
        {
          v63 = 0;
          if ( v20 > 0 )
          {
            v64 = (char *)pimage.__vftable[6].OnLog + v61 * (int)pimage.__vftable[5].OnLog + 2;
            do
            {
              v65 = *(unsigned __int16 *)(v62 + 2 * v63);
              *(v64 - 1) = (v65 >> 7) & 0xF8;
              *(v64 - 2) = -1;
              *v64 = (v65 >> 2) & 0xF8;
              v64[1] = 8 * v65;
              ++v63;
              v64 += 4;
            }
            while ( v63 < v20 );
            v19 = m;
            v61 = gg;
          }
          v62 += j;
          gg = ++v61;
        }
        while ( v61 < v19 );
      }
      goto LABEL_56;
    case 5u:
      v66 = *((char **)r + 201);
      if ( v66 == nullptr )
        v66 = (char *)r + 40;
      (*(void (__thiscall **)(signed int, char *, LoggingResponse_t (__thiscall *)(struct CDefaultLoggingResponsePolicy *, const LoggingContext_t *), int))(*(_DWORD *)k + 8))(
        a1: k,
        a2: v66,
        a3: pimage.__vftable[6].OnLog,
        a4: 4 * v19 * (unsigned __int16)BufferBytes);
      for ( k = 0; k < v19; ++k )
      {
        if ( v20 > 0 )
        {
          v67 = (unsigned __int8 *)pimage.__vftable[6].OnLog + k * (int)pimage.__vftable[5].OnLog + 2;
          for ( m = v20; m != 0; --m )
          {
            v68 = *(v67 - 2);
            r_3 = *(v67 - 1);
            g_3a = *v67;
            b = v67[1];
            *(v67 - 2) = r_3;
            *(v67 - 1) = g_3a;
            *v67 = b;
            v67[1] = v68;
            v67 += 4;
          }
        }
      }
      UndoAndFilterPremultiplied(a1: (struct GImage *)pimage.__vftable);
      break;
    default:
      break;
  }
LABEL_89:
  v69 = pimage.__vftable;
  GFxLoadProcess::AddImageResource(result: v72);
  if ( v69 != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v69);
}

//------------------------------------------------------------------------------
// Address: 0x100E02A0
// Name: void GFx_PlaceObjectLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFx_PlaceObjectLoader(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        struct GFxLoadProcess *p,
        const struct GFxTagInfo *tagInfo)
{
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  CP4File *v8; // ecx
  unsigned int v9; // eax
  CP4File_vtbl *v10; // ebx
  unsigned __int8 *v11; // edx
  CP4File_vtbl *v12; // eax
  unsigned __int8 *v13; // ebx
  char *v14; // edi
  unsigned int v15; // esi
  int v16; // ecx
  unsigned __int8 **v17; // esi
  char v18; // [esp+0h] [ebp-10h]
  IShaderDeviceMgr *pa; // [esp+18h] [ebp+8h]

  GFxLogBase<GFxLoadProcess>::LogParse(this, pfmt: (unsigned int)p + 20, a3: (int)"  PlaceObject\n", a4: v18);
  if ( *((_DWORD *)p + 201) != 0 )
    pa = *((IShaderDeviceMgr **)p + 201);
  else
    pa = (IShaderDeviceMgr *)((char *)p + 40);
  v4 = GFxPlaceObject::ComputeDataSize(a1: pa);
  v5 = *((_DWORD *)p + 8);
  v6 = *(_DWORD *)(v5 + 12);
  v7 = v4;
  v8 = (CP4File *)(v5 + 8);
  v9 = (v4 + 10) & 0xFFFFFFFC;
  if ( v9 > v6 )
  {
    v12 = GFxDataAllocator::OverflowAlloc(this: v8, bytes: v9);
  }
  else
  {
    v10 = (CP4File_vtbl *)((char *)v8->__vftable + v9);
    v11 = (unsigned __int8 *)(v6 - v9);
    v12 = v8->__vftable;
    v8->__vftable = v10;
    v8->m_sFilename.m_Storage.m_Memory.m_pMemory = v11;
  }
  if ( v12 != nullptr )
    v13 = (unsigned __int8 *)GFxPlaceObject::GFxPlaceObject(this: (GFxPlaceObject *)v12);
  else
    v13 = nullptr;
  GFxStream::ReadToBuffer(this: (GFxStream *)pa, pdestBuf: v13 + 5, a3: v7);
  GFxPlaceObject::CheckForCxForm(this: (GFxPlaceObject *)v13, a2: v7);
  v14 = (char *)p + 12 * *((_DWORD *)p + 190) + 768;
  v15 = *((_DWORD *)v14 + 1) + 1;
  if ( v15 >= *((_DWORD *)v14 + 1) )
  {
    if ( v15 >= *((_DWORD *)v14 + 2) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v14,
        result: (D3DXVECTOR4 *)v14,
        newCapacity: v15 + (v15 >> 2));
  }
  else if ( v15 < *((_DWORD *)v14 + 2) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v14,
      result: (D3DXVECTOR4 *)v14,
      newCapacity: *((_DWORD *)v14 + 1) + 1);
  }
  v16 = *(_DWORD *)v14;
  *((_DWORD *)v14 + 1) = v15;
  v17 = (unsigned __int8 **)(v16 + 4 * v15 - 4);
  if ( v17 != nullptr )
    *v17 = v13;
}

//------------------------------------------------------------------------------
// Address: 0x100E0380
// Name: void GFx_PlaceObject2Loader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFx_PlaceObject2Loader(
        GArrayLH<GString,2,GArrayDefaultPolicy> *a1@<ecx>,
        int a2@<edi>,
        struct GFxLoadProcess *p,
        const struct GFxTagInfo *tagInfo)
{
  struct GFxLoadProcess *v4; // esi
  IShaderDeviceMgr *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  const CMemberFuncProxyBase<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),CFuncMemPolicyNone> *v8; // ecx
  int v9; // eax
  bool v10; // cf
  unsigned int v11; // edx
  CP4File *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  CP4File_vtbl *v15; // ebx
  unsigned __int8 *v16; // edx
  CP4File_vtbl *v17; // eax
  CP4File_vtbl *v18; // ebx
  unsigned int v19; // eax
  CP4File_vtbl *v20; // ebx
  unsigned __int8 *v21; // edx
  CP4File_vtbl *v22; // eax
  int v23; // edi
  unsigned int v24; // esi
  CP4File_vtbl **v25; // eax
  __int128 v26; // [esp-Ch] [ebp-1Ch]
  char v27; // [esp+0h] [ebp-10h]
  GFxStream *v28; // [esp+8h] [ebp-8h]
  char hasEventHandlers; // [esp+Fh] [ebp-1h]

  v4 = p;
  GFxLogBase<GFxLoadProcess>::LogParse(this: a1, pfmt: (unsigned int)p + 20, a3: (int)"  PlaceObject2\n", a4: v27);
  if ( *((_DWORD *)p + 201) != 0 )
  {
    v28 = *((GFxStream **)p + 201);
    v5 = (IShaderDeviceMgr *)v28;
  }
  else
  {
    v5 = (IShaderDeviceMgr *)((char *)p + 40);
    v28 = (GFxStream *)((char *)p + 40);
  }
  DWORD2(v26) = a2;
  DWORD1(v26) = *(_DWORD *)(*((_DWORD *)p + 8) + 44);
  LODWORD(v26) = v5;
  GFxPlaceObject2::ComputeDataSize(movieVersion: v26);
  v7 = v6;
  hasEventHandlers = GFxPlaceObject2::HasEventHandlers(pin: v8, a2: v5);
  if ( hasEventHandlers != 0 )
    v7 += 4;
  v9 = *((_DWORD *)p + 8);
  v10 = *(_DWORD *)(v9 + 44) < 6u;
  v11 = *(_DWORD *)(v9 + 12);
  v12 = (CP4File *)(v9 + 8);
  v13 = v7 + 10;
  if ( v10 )
  {
    v19 = v13 & 0xFFFFFFFC;
    if ( v19 > v11 )
    {
      v22 = GFxDataAllocator::OverflowAlloc(this: v12, bytes: v19);
    }
    else
    {
      v20 = (CP4File_vtbl *)((char *)v12->__vftable + v19);
      v21 = (unsigned __int8 *)(v11 - v19);
      v22 = v12->__vftable;
      v4 = p;
      v12->__vftable = v20;
      v12->m_sFilename.m_Storage.m_Memory.m_pMemory = v21;
    }
    if ( v22 != nullptr )
    {
      v22->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxPlaceObject2a::`vftable';
      v18 = v22;
      goto LABEL_18;
    }
  }
  else
  {
    v14 = v13 & 0xFFFFFFFC;
    if ( v14 > v11 )
    {
      v17 = GFxDataAllocator::OverflowAlloc(this: v12, bytes: v14);
    }
    else
    {
      v15 = (CP4File_vtbl *)((char *)v12->__vftable + v14);
      v16 = (unsigned __int8 *)(v11 - v14);
      v17 = v12->__vftable;
      v4 = p;
      v12->__vftable = v15;
      v12->m_sFilename.m_Storage.m_Memory.m_pMemory = v16;
    }
    if ( v17 != nullptr )
    {
      v17->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxPlaceObject2::`vftable';
      v18 = v17;
      goto LABEL_18;
    }
  }
  v18 = nullptr;
LABEL_18:
  if ( hasEventHandlers != 0 )
  {
    GFxStream::ReadToBuffer(this: v28, pdestBuf: (unsigned __int8 *)&v18->Add, a3: v7 - 4);
    GFxPlaceObject2::RestructureForEventHandlers(pdata: (unsigned __int8 *)&v18->Edit);
  }
  else
  {
    GFxStream::ReadToBuffer(this: v28, pdestBuf: (unsigned __int8 *)&v18->Edit, a3: v7);
  }
  v23 = (int)v4 + 12 * *((_DWORD *)v4 + 190) + 768;
  v24 = *(_DWORD *)(v23 + 4) + 1;
  if ( v24 >= *(_DWORD *)(v23 + 4) )
  {
    if ( v24 >= *(_DWORD *)(v23 + 8) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: v23,
        result: (D3DXVECTOR4 *)v23,
        newCapacity: v24 + (v24 >> 2));
  }
  else if ( v24 < *(_DWORD *)(v23 + 8) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: v23,
      result: (D3DXVECTOR4 *)v23,
      newCapacity: *(_DWORD *)(v23 + 4) + 1);
  }
  v25 = (CP4File_vtbl **)(*(_DWORD *)v23 + 4 * v24 - 4);
  *(_DWORD *)(v23 + 4) = v24;
  if ( v25 != nullptr )
    *v25 = v18;
}

//------------------------------------------------------------------------------
// Address: 0x100E04D0
// Name: void GFx_PlaceObject3Loader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFx_PlaceObject3Loader(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        struct GFxLoadProcess *hasEventHandlers,
        const struct GFxTagInfo *tagInfo)
{
  IShaderDeviceMgr *v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // esi
  const CMemberFuncProxyBase<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),CFuncMemPolicyNone> *v7; // ecx
  int v8; // ecx
  unsigned int v9; // edx
  CP4File *v10; // ecx
  unsigned int v11; // eax
  CP4File_vtbl *v12; // esi
  unsigned __int8 *v13; // edx
  CP4File_vtbl *v14; // eax
  int v15; // edx
  int v16; // esi
  D3DXVECTOR4 *v17; // edi
  unsigned int v18; // esi
  float x; // edx
  char v20; // [esp+0h] [ebp-14h]
  void *const *v21; // [esp+0h] [ebp-14h]
  const bool *v22; // [esp+4h] [ebp-10h]
  unsigned int dataSz; // [esp+Ch] [ebp-8h]
  GFxStream *v24; // [esp+10h] [ebp-4h]
  char hasEventHandlers_3; // [esp+1Fh] [ebp+Bh]

  GFxLogBase<GFxLoadProcess>::LogParse(
    this,
    pfmt: (unsigned int)hasEventHandlers + 20,
    a3: (int)"  PlaceObject3\n",
    a4: v20);
  v4 = *((IShaderDeviceMgr **)hasEventHandlers + 201);
  if ( v4 == nullptr )
    v4 = (IShaderDeviceMgr *)((char *)hasEventHandlers + 40);
  GFxPlaceObject3::ComputeDataSize(len: v4, tagStart: v21, pos: v22);
  v6 = v5;
  dataSz = v5;
  hasEventHandlers_3 = GFxPlaceObject2::HasEventHandlers(pin: v7, a2: v4);
  if ( hasEventHandlers_3 != 0 )
  {
    v6 += 4;
    dataSz = v6;
  }
  v8 = *((_DWORD *)hasEventHandlers + 8);
  v9 = *(_DWORD *)(v8 + 12);
  v10 = (CP4File *)(v8 + 8);
  v11 = (v6 + 10) & 0xFFFFFFFC;
  if ( v11 > v9 )
  {
    v14 = GFxDataAllocator::OverflowAlloc(this: v10, bytes: (v6 + 10) & 0xFFFFFFFC);
  }
  else
  {
    v12 = v10->__vftable;
    v13 = (unsigned __int8 *)(v9 - v11);
    v10->__vftable = (CP4File_vtbl *)((char *)v10->__vftable + v11);
    v14 = v12;
    v6 = dataSz;
    v10->m_sFilename.m_Storage.m_Memory.m_pMemory = v13;
  }
  if ( v14 != nullptr )
  {
    v14->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxPlaceObject3::`vftable';
    v24 = (GFxStream *)v14;
  }
  else
  {
    v24 = nullptr;
    v14 = nullptr;
  }
  if ( hasEventHandlers_3 != 0 )
  {
    GFxStream::ReadToBuffer(this: (GFxStream *)v4, pdestBuf: (unsigned __int8 *)&v14->Add, a3: v6 - 4);
    GFxPlaceObject2::RestructureForEventHandlers(pdata: (unsigned __int8 *)v24 + 4);
  }
  else
  {
    GFxStream::ReadToBuffer(this: (GFxStream *)v4, pdestBuf: (unsigned __int8 *)&v14->Edit, a3: v6);
  }
  v15 = 3 * *((_DWORD *)hasEventHandlers + 190) + 192;
  v16 = *((_DWORD *)hasEventHandlers + v15 + 1);
  v17 = (D3DXVECTOR4 *)((char *)hasEventHandlers + 4 * v15);
  v18 = v16 + 1;
  if ( v18 >= LODWORD(v17->y) )
  {
    if ( v18 >= LODWORD(v17->z) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v17,
        result: v17,
        newCapacity: v18 + (v18 >> 2));
  }
  else if ( v18 < LODWORD(v17->z) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v17,
      result: v17,
      newCapacity: v18);
  }
  x = v17->x;
  LODWORD(v17->y) = v18;
  if ( LODWORD(x) + 4 * v18 != 4 )
    *(_DWORD *)(LODWORD(x) + 4 * v18 - 4) = v24;
}

//------------------------------------------------------------------------------
// Address: 0x100E05F0
// Name: void GFx_RemoveObjectLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_RemoveObjectLoader(const CPrimList *p, const struct GFxTagInfo *tagInfo)
{
  int m_FirstIndex; // ecx
  unsigned int v3; // edx
  CP4File *v4; // ecx
  CP4File_vtbl *v5; // eax
  CP4File_vtbl *v6; // ebx
  char *v7; // edi
  unsigned int v8; // esi
  CP4File_vtbl **v9; // eax

  m_FirstIndex = p[4].m_FirstIndex;
  v3 = *(_DWORD *)(m_FirstIndex + 12);
  v4 = (CP4File *)(m_FirstIndex + 8);
  if ( v3 < 8 )
  {
    v5 = GFxDataAllocator::OverflowAlloc(this: v4, bytes: 8u);
  }
  else
  {
    v5 = v4->__vftable;
    v4->__vftable = (CP4File_vtbl *)((char *)v4->__vftable + 8);
    v4->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v3 - 8);
  }
  if ( v5 != nullptr )
  {
    v5->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxRemoveObject::`vftable';
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  GFxRemoveObject::Read(this: v6, result: p);
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)LOWORD(v6->Edit),
    pfmt: (unsigned int)&p[2].m_NumIndices,
    a3: (int)"  RemoveObject(%d, %d)\n",
    a4: (char)v6->Edit);
  v7 = (char *)&p[96] + 12 * p[95].m_FirstIndex;
  v8 = *((_DWORD *)v7 + 1) + 1;
  if ( v8 >= *((_DWORD *)v7 + 1) )
  {
    if ( v8 >= *((_DWORD *)v7 + 2) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v7,
        result: (D3DXVECTOR4 *)v7,
        newCapacity: v8 + (v8 >> 2));
  }
  else if ( v8 < *((_DWORD *)v7 + 2) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v7,
      result: (D3DXVECTOR4 *)v7,
      newCapacity: *((_DWORD *)v7 + 1) + 1);
  }
  v9 = (CP4File_vtbl **)(*(_DWORD *)v7 + 4 * v8 - 4);
  *((_DWORD *)v7 + 1) = v8;
  if ( v9 != nullptr )
    *v9 = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E06A0
// Name: void GFx_RemoveObject2Loader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_RemoveObject2Loader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  int v2; // ecx
  unsigned int v3; // edx
  CP4File *v4; // ecx
  CP4File_vtbl *v5; // eax
  CP4File_vtbl *v6; // ebx
  char *v7; // edi
  unsigned int v8; // esi
  CP4File_vtbl **v9; // eax

  v2 = *((_DWORD *)p + 8);
  v3 = *(_DWORD *)(v2 + 12);
  v4 = (CP4File *)(v2 + 8);
  if ( v3 < 8 )
  {
    v5 = GFxDataAllocator::OverflowAlloc(this: v4, bytes: 8u);
  }
  else
  {
    v5 = v4->__vftable;
    v4->__vftable = (CP4File_vtbl *)((char *)v4->__vftable + 8);
    v4->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v3 - 8);
  }
  if ( v5 != nullptr )
  {
    v5->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxRemoveObject2::`vftable';
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  GFxRemoveObject2::Read(this: (GFxRemoveObject2 *)v6, a2: p);
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)((char *)p + 20),
    pfmt: (unsigned int)p + 20,
    a3: (int)"  RemoveObject2(%d)\n",
    a4: (char)v6->Edit);
  v7 = (char *)p + 12 * *((_DWORD *)p + 190) + 768;
  v8 = *((_DWORD *)v7 + 1) + 1;
  if ( v8 >= *((_DWORD *)v7 + 1) )
  {
    if ( v8 >= *((_DWORD *)v7 + 2) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: (int)v7,
        result: (D3DXVECTOR4 *)v7,
        newCapacity: v8 + (v8 >> 2));
  }
  else if ( v8 < *((_DWORD *)v7 + 2) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: (int)v7,
      result: (D3DXVECTOR4 *)v7,
      newCapacity: *((_DWORD *)v7 + 1) + 1);
  }
  v9 = (CP4File_vtbl **)(*(_DWORD *)v7 + 4 * v8 - 4);
  *((_DWORD *)v7 + 1) = v8;
  if ( v9 != nullptr )
    *v9 = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E0750
// Name: public: GFxTextureGlyphData::GFxTextureGlyphData(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
GFxTextureGlyphData *__thiscall GFxTextureGlyphData::GFxTextureGlyphData(
        GFxTextureGlyphData *this,
        unsigned int a2,
        bool a3)
{
  _DWORD *v4; // edi
  unsigned int v5; // ebx

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxTextureGlyphData::`vftable';
  *((_DWORD *)this + 2) = 48;
  *((_DWORD *)this + 3) = 3;
  *((_DWORD *)this + 4) = 1024;
  *((_DWORD *)this + 5) = 1024;
  v4 = (_DWORD *)((char *)this + 32);
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_BYTE *)this + 48) = a3;
  v5 = *((_DWORD *)this + 9);
  GArrayDataBase<GFxTextureGlyph,GAllocatorLH<GFxTextureGlyph,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (CMorph *)((char *)this + 32),
    pheapAddr: (const GRenderer::FillTexture *)((char *)this + 32),
    newSize: a2);
  if ( a2 > v5 )
    GConstructorMov<GFxTextureGlyph>::ConstructArray(a1: *v4 + 40 * v5, a2: a2 - v5);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E07E0
// Name: public: virtual GFxTextureGlyphData::~GFxTextureGlyphData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextureGlyphData::~GFxTextureGlyphData(IShaderAPI *this)
{
  int v2; // eax
  void (__thiscall ***v3)(_DWORD, _DWORD); // esi
  int v4; // ebx
  IDirect3DDevice9 *v5; // [esp+0h] [ebp-8h]

  GHashSetBase<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF>>::~GHashSetBase<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GFxResourcePtr<GFxImageResource>,GFixedSizeHash<GFxResourceId>>::NodeHashF>>(this: v5);
  v2 = *((_DWORD *)this + 9);
  v3 = (void (__thiscall ***)(_DWORD, _DWORD))(*((_DWORD *)this + 8) + 40 * v2 - 40);
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 9);
    do
    {
      (**v3)(a1: v3, a2: 0);
      v3 -= 10;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 8));
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E0830
// Name: void GFx_FontTextureInfoLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_FontTextureInfoLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  tagBITMAPINFOHEADER *v2; // esi
  int v3; // ecx
  int biWidth; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  unsigned __int16 v10; // dx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // eax
  unsigned __int8 *v19; // ecx
  __int16 v20; // dx
  int v21; // ecx
  unsigned int v22; // edi
  int v23; // eax
  unsigned int v24; // ebx
  int v25; // ecx
  int v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  int v34; // ecx
  int v35; // edx
  int v36; // eax
  int v37; // ecx
  int v38; // ecx
  int v39; // edx
  int v40; // eax
  int v41; // ecx
  int v42; // ecx
  int v43; // edx
  int v44; // eax
  int v45; // ecx
  int v46; // ecx
  int (__thiscall *v47)(int, int, int *); // edx
  int v48; // eax
  int v49; // ebx
  IShaderDevice *v50; // ecx
  int v51; // edx
  int *v52; // eax
  int v53; // eax
  int v54; // eax
  float v55; // ebx
  int v56; // edx
  int v57; // eax
  unsigned int v58; // ecx
  unsigned int v59; // eax
  GFxMovieDataDef::LoadTaskData *v60; // ecx
  struct GFxFont *FontData; // ebx
  int v62; // eax
  CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int> *v63; // edi
  int (__thiscall *v64)(int, int, int *); // eax
  GFxTextureGlyphData *v65; // edi
  unsigned int v66; // eax
  GFxTextureGlyphData *v67; // eax
  int v68; // eax
  int v69; // eax
  unsigned __int16 v70; // dx
  int v71; // edx
  int v72; // eax
  unsigned int v73; // ebx
  int v74; // edx
  int v75; // eax
  unsigned __int16 v76; // dx
  int v77; // edi
  GRefCountNTSImpl **i; // esi
  void *v79; // esi
  double v80; // [esp+8h] [ebp-78h]
  double v81; // [esp+10h] [ebp-70h]
  double v82; // [esp+18h] [ebp-68h]
  struct GFxResourceId v83; // [esp+1Ch] [ebp-64h]
  _cpinfo *v84; // [esp+20h] [ebp-60h]
  int v85; // [esp+2Ch] [ebp-54h]
  int v86; // [esp+30h] [ebp-50h]
  int v87; // [esp+34h] [ebp-4Ch]
  int v88; // [esp+38h] [ebp-48h]
  int v89; // [esp+3Ch] [ebp-44h] BYREF
  int v90; // [esp+40h] [ebp-40h]
  int v91; // [esp+44h] [ebp-3Ch]
  _TRIVERTEX *rh; // [esp+48h] [ebp-38h] BYREF
  IShaderDevice *v93; // [esp+4Ch] [ebp-34h]
  unsigned int v94; // [esp+50h] [ebp-30h]
  int v95; // [esp+54h] [ebp-2Ch] BYREF
  unsigned int numTexGlyphs; // [esp+58h] [ebp-28h]
  int v97; // [esp+5Ch] [ebp-24h] BYREF
  int v98; // [esp+60h] [ebp-20h]
  float v99; // [esp+64h] [ebp-1Ch]
  float v100; // [esp+68h] [ebp-18h]
  float v101; // [esp+6Ch] [ebp-14h]
  float v102; // [esp+70h] [ebp-10h]
  float v103; // [esp+74h] [ebp-Ch]
  const CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int>::Iterator_t *v104; // [esp+78h] [ebp-8h]
  struct GString v105; // [esp+7Ch] [ebp-4h] BYREF
  float tagInfoa; // [esp+8Ch] [ebp+Ch]
  int tagInfob; // [esp+8Ch] [ebp+Ch]

  v2 = *((tagBITMAPINFOHEADER **)p + 201);
  if ( v2 == nullptr )
    v2 = (tagBITMAPINFOHEADER *)((char *)p + 40);
  v3 = v2[1].biHeight - v2[1].biWidth;
  v98 = *(_DWORD *)(*((_DWORD *)p + 8) + 28);
  BYTE1(v2->biSizeImage) = 0;
  if ( v3 < 4 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
  biWidth = v2[1].biWidth;
  v104 = (const CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int>::Iterator_t *)(*(unsigned __int8 *)(biWidth + v2[1].biSizeImage) | ((*(unsigned __int8 *)(biWidth + v2[1].biSizeImage + 1) | ((*(unsigned __int8 *)(v2[1].biSizeImage + biWidth + 2) | (*(unsigned __int8 *)(v2[1].biSizeImage + biWidth + 3) << 8)) << 8)) << 8));
  v5 = v2[1].biHeight - (biWidth + 4);
  v2[1].biWidth = biWidth + 4;
  BYTE1(v2->biSizeImage) = 0;
  if ( v5 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v6 = v2[1].biWidth;
  v7 = *(unsigned __int16 *)(v6 + v2[1].biSizeImage);
  v2[1].biWidth = v6 + 2;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v105);
  GFxStream::ReadStringWithLength(this: (GFxStream *)v2, a2: &v105);
  v8 = v2[1].biHeight - v2[1].biWidth;
  BYTE1(v2->biSizeImage) = 0;
  if ( v8 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v9 = v2[1].biWidth;
  v10 = *(_WORD *)(v2[1].biSizeImage + v9);
  v9 += 2;
  v11 = v2[1].biHeight - v9;
  v2[1].biWidth = v9;
  v87 = v10;
  BYTE1(v2->biSizeImage) = 0;
  if ( v11 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v12 = v2[1].biWidth;
  v13 = (unsigned __int16)(*(unsigned __int8 *)(v12 + v2[1].biSizeImage)
                         | (*(unsigned __int8 *)(v12 + v2[1].biSizeImage + 1) << 8));
  v12 += 2;
  v14 = v2[1].biHeight - v12;
  v2[1].biWidth = v12;
  v88 = v13;
  BYTE1(v2->biSizeImage) = 0;
  if ( v14 < 1 )
    GFxStream::PopulateBuffer1(result: v84);
  v15 = v2[1].biWidth;
  v16 = *(unsigned __int8 *)(v15 + v2[1].biSizeImage);
  ++v15;
  v17 = v2[1].biHeight - v15;
  v2[1].biWidth = v15;
  v86 = v16;
  BYTE1(v2->biSizeImage) = 0;
  if ( v17 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v18 = v2[1].biWidth;
  v19 = (unsigned __int8 *)(v18 + v2[1].biSizeImage);
  v20 = v19[1];
  LOWORD(v19) = *v19;
  v2[1].biWidth = v18 + 2;
  v85 = (unsigned __int16)((unsigned __int16)v19 | (v20 << 8));
  GFxLogBase<GFxStream>::LogParse(
    this: v2,
    a2: (int)"  FontTextureInfo: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', w = %d, h = %d\n",
    *(_DWORD *)tagInfo,
    v104,
    v7,
    (const char *)((v105.HeapTypeBits & 0xFFFFFFFC) + 8),
    v87,
    v13);
  GFx_CreateImageFileResourceHandle(
    a1: &rh,
    a2: (int)p,
    a3: (int)v104,
    a4: (unsigned __int8 *)((v105.HeapTypeBits & 0xFFFFFFFC) + 8),
    a5: (unsigned __int8 *)&pMem,
    a6: v7,
    a7: v87,
    a8: v13,
    a9: 1);
  v21 = v2[1].biHeight - v2[1].biWidth;
  v22 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  BYTE1(v2->biSizeImage) = 0;
  if ( v21 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v23 = v2[1].biWidth;
  v24 = (unsigned __int16)(*(unsigned __int8 *)(v23 + v2[1].biSizeImage)
                         | (*(unsigned __int8 *)(v23 + v2[1].biSizeImage + 1) << 8));
  v2[1].biWidth = v23 + 2;
  numTexGlyphs = v24;
  GFxLogBase<GFxStream>::LogParse(
    this: v2,
    a2: (int)"  PadPixels = %d, nominal glyph size = %d, numTexGlyphs = %d\n",
    v86,
    v85,
    v24);
  if ( v24 != 0 )
  {
    do
    {
      v25 = v2[1].biHeight - v2[1].biWidth;
      BYTE1(v2->biSizeImage) = 0;
      if ( v25 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v26 = v2[1].biWidth;
      v27 = *(unsigned __int8 *)(v26 + v2[1].biSizeImage)
          | ((*(unsigned __int8 *)(v26 + v2[1].biSizeImage + 1)
            | (*(unsigned __int16 *)(v26 + v2[1].biSizeImage + 2) << 8)) << 8);
      v28 = v26 + 4;
      v29 = v2[1].biHeight - (v26 + 4);
      tagInfoa = *(float *)&v27;
      v2[1].biWidth = v28;
      BYTE1(v2->biSizeImage) = 0;
      if ( v29 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v30 = v2[1].biWidth;
      v31 = *(unsigned __int8 *)(v30 + v2[1].biSizeImage)
          | ((*(unsigned __int8 *)(v30 + v2[1].biSizeImage + 1)
            | (*(unsigned __int16 *)(v30 + v2[1].biSizeImage + 2) << 8)) << 8);
      v32 = v30 + 4;
      v33 = v2[1].biHeight - (v30 + 4);
      v103 = *(float *)&v31;
      v2[1].biWidth = v32;
      BYTE1(v2->biSizeImage) = 0;
      if ( v33 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v34 = v2[1].biWidth;
      v35 = *(unsigned __int8 *)(v34 + v2[1].biSizeImage)
          | ((*(unsigned __int8 *)(v34 + v2[1].biSizeImage + 1)
            | (*(unsigned __int16 *)(v34 + v2[1].biSizeImage + 2) << 8)) << 8);
      v36 = v34 + 4;
      v37 = v2[1].biHeight - (v34 + 4);
      v102 = *(float *)&v35;
      v2[1].biWidth = v36;
      BYTE1(v2->biSizeImage) = 0;
      if ( v37 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v38 = v2[1].biWidth;
      v39 = *(unsigned __int8 *)(v38 + v2[1].biSizeImage)
          | ((*(unsigned __int8 *)(v38 + v2[1].biSizeImage + 1)
            | (*(unsigned __int16 *)(v38 + v2[1].biSizeImage + 2) << 8)) << 8);
      v40 = v38 + 4;
      v41 = v2[1].biHeight - (v38 + 4);
      v101 = *(float *)&v39;
      v2[1].biWidth = v40;
      BYTE1(v2->biSizeImage) = 0;
      if ( v41 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v42 = v2[1].biWidth;
      v43 = *(unsigned __int8 *)(v42 + v2[1].biSizeImage)
          | ((*(unsigned __int8 *)(v42 + v2[1].biSizeImage + 1)
            | (*(unsigned __int16 *)(v42 + v2[1].biSizeImage + 2) << 8)) << 8);
      v44 = v42 + 4;
      v45 = v2[1].biHeight - (v42 + 4);
      v100 = *(float *)&v43;
      v2[1].biWidth = v44;
      BYTE1(v2->biSizeImage) = 0;
      if ( v45 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v46 = v2[1].biWidth;
      v82 = v101;
      v81 = v102;
      v80 = v103;
      LODWORD(v99) = *(unsigned __int8 *)(v46 + v2[1].biSizeImage)
                   | ((*(unsigned __int8 *)(v46 + v2[1].biSizeImage + 1)
                     | (*(unsigned __int16 *)(v46 + v2[1].biSizeImage + 2) << 8)) << 8);
      v2[1].biWidth = v46 + 4;
      GFxLogBase<GFxStream>::LogParse(
        this: v2,
        a2: (int)"  TEXGLYPH[%d]: uvBnd.Left = %f, uvBnd.Top = %f, uvBnd.Right = %f, uvBnd.Bottom = %f\n",
        v22,
        tagInfoa,
        v80,
        v81,
        v82);
      GFxLogBase<GFxStream>::LogParse(
        this: v2,
        a2: (int)"                uvOrigin.x = %f, uvOrigin.y = %f\n",
        v100,
        v99);
      v47 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v98 + 40);
      v97 = 261;
      v48 = v47(a1: v98, a2: 40, a3: &v97);
      if ( v48 != 0 )
      {
        *(_DWORD *)v48 = &GRefCountImplCore::`vftable';
        *(_DWORD *)(v48 + 4) = 1;
        *(_DWORD *)v48 = &GFxTextureGlyph::`vftable';
        *(_DWORD *)(v48 + 8) = 0;
        *(_DWORD *)(v48 + 12) = 0;
        *(float *)(v48 + 16) = 0.0;
        *(float *)(v48 + 20) = 0.0;
        v49 = v48;
        *(float *)(v48 + 24) = 0.0;
        *(float *)(v48 + 28) = 0.0;
      }
      else
      {
        v49 = 0;
      }
      if ( rh == nullptr && v93 != nullptr )
        GRefCountImpl::AddRef(this: v93);
      if ( *(_DWORD *)(v49 + 8) == 0 )
      {
        v50 = *(IShaderDevice **)(v49 + 12);
        if ( v50 != nullptr )
          GFxResource::Release(this: v50);
      }
      v51 = v90;
      *(_DWORD *)(v49 + 8) = rh;
      *(_DWORD *)(v49 + 12) = v93;
      *(float *)(v49 + 16) = tagInfoa;
      *(float *)(v49 + 20) = v103;
      *(float *)(v49 + 24) = v102;
      *(float *)(v49 + 28) = v101;
      *(float *)(v49 + 32) = v100;
      *(float *)(v49 + 36) = v99;
      GArrayDataBase<GPtr<GFxSprite::ActiveSoundItem>,GAllocatorGH<GPtr<GFxSprite::ActiveSoundItem>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (CVertexBuilder *)&v89,
        a2: (ButtonCode_t)&v89,
        a3: v51 + 1);
      v52 = (int *)(v89 + 4 * v90 - 4);
      if ( v89 + 4 * v90 != 4 )
      {
        if ( v49 != 0 )
          ++*(_DWORD *)(v49 + 4);
        *v52 = v49;
      }
      if ( v49 != 0 )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v49);
      ++v22;
    }
    while ( v22 < numTexGlyphs );
  }
  v53 = v2[1].biHeight - v2[1].biWidth;
  BYTE1(v2->biSizeImage) = 0;
  if ( v53 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v54 = v2[1].biWidth;
  LODWORD(v55) = *(unsigned __int16 *)(v2[1].biSizeImage + v54);
  v2[1].biWidth = v54 + 2;
  GFxLogBase<GFxStream>::LogParse(this: v2, a2: (int)"  NumFonts = %d\n", v55);
  if ( v55 != 0.0 )
  {
    v99 = v55;
    do
    {
      v56 = v2[1].biHeight - v2[1].biWidth;
      BYTE1(v2->biSizeImage) = 0;
      if ( v56 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v57 = v2[1].biWidth;
      v58 = *(unsigned __int16 *)(v2[1].biSizeImage + v57);
      v2[1].biWidth = v57 + 2;
      v59 = v58;
      v83.Id = v58;
      v60 = *((GFxMovieDataDef::LoadTaskData **)p + 8);
      v94 = v59;
      FontData = GFxMovieDataDef::LoadTaskData::GetFontData(this: v60, a2: v83);
      if ( FontData == nullptr )
        goto LABEL_75;
      v62 = ((int (__thiscall *)(struct GFxFont *))FontData->AllocateScratchTextures)(a1: FontData);
      if ( v62 != 0 )
        ++*(_DWORD *)(v62 + 4);
      v63 = (CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int> *)v62;
      if ( v62 == 0 )
      {
        v64 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v98 + 40);
        v95 = 261;
        v65 = (GFxTextureGlyphData *)v64(a1: v98, a2: 52, a3: &v95);
        if ( v65 != nullptr )
        {
          v66 = ((int (__thiscall *)(struct GFxFont *))FontData->GetMorphAccumulatorTexCoord)(a1: FontData);
          v67 = GFxTextureGlyphData::GFxTextureGlyphData(this: v65, a2: v66, a3: true);
        }
        else
        {
          v67 = nullptr;
        }
        v63 = (CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> >,int> *)v67;
        if ( v67 == nullptr )
          goto LABEL_62;
        *((_DWORD *)v67 + 2) = v85;
        *((_DWORD *)v67 + 3) = v86;
        *((_DWORD *)v67 + 4) = v87;
        *((_DWORD *)v67 + 5) = v88;
        ((void (__thiscall *)(struct GFxFont *, GFxTextureGlyphData *))FontData->FreeScratchTextures)(
          a1: FontData,
          a2: v67);
      }
      GFxTextureGlyphData::AddTexture(this: v63, textureId: v104, (const GenericThreadLocals::CThreadLocal<int> *)&rh);
LABEL_62:
      v68 = v2[1].biHeight - v2[1].biWidth;
      BYTE1(v2->biSizeImage) = 0;
      if ( v68 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v69 = v2[1].biWidth;
      v70 = *(_WORD *)(v2[1].biSizeImage + v69);
      v2[1].biWidth = v69 + 2;
      if ( v70 != 0 )
      {
        for ( tagInfob = v70; tagInfob != 0; --tagInfob )
        {
          v71 = v2[1].biHeight - v2[1].biWidth;
          BYTE1(v2->biSizeImage) = 0;
          if ( v71 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v72 = v2[1].biWidth;
          v73 = (unsigned __int16)(*(unsigned __int8 *)(v2[1].biSizeImage + v72)
                                 | (*(unsigned __int8 *)(v2[1].biSizeImage + v72 + 1) << 8));
          v72 += 2;
          v74 = v2[1].biHeight - v72;
          v2[1].biWidth = v72;
          BYTE1(v2->biSizeImage) = 0;
          if ( v74 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v75 = v2[1].biWidth;
          v76 = *(_WORD *)(v2[1].biSizeImage + v75);
          v2[1].biWidth = v75 + 2;
          if ( v63 != nullptr )
            GFxTextureGlyphData::AddTextureGlyph(
              this: (GFxTextureGlyphData *)v63,
              a2: v73,
              result: *(CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > **)(v89 + 4 * v76));
        }
      }
      if ( v63 != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v63);
LABEL_75:
      --LODWORD(v99);
    }
    while ( v99 != 0.0 );
  }
  GFxLogBase<GFxStream>::LogParse(this: v2, a2: (int)"\n");
  v77 = v90;
  for ( i = (GRefCountNTSImpl **)(v89 + 4 * v90 - 4); v77 != 0; --v77 )
  {
    if ( *i != nullptr )
      GRefCountNTSImpl::Release(this: *i);
    --i;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v89);
  if ( rh == nullptr && v93 != nullptr )
    GFxResource::Release(this: v93);
  v79 = (void *)(v105.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v105.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v79);
}

//------------------------------------------------------------------------------
// Address: 0x100E1010
// Name: void GFx_ImportLoader(class GFxLoadProcess __near *,struct GFxTagInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFx_ImportLoader(struct GFxLoadProcess *p, const struct GFxTagInfo *tagInfo)
{
  struct GFxLoadProcess *v2; // edi
  GFxStream *v3; // ebx
  int v4; // ecx
  _LUID_AND_ATTRIBUTES *v5; // eax
  int v6; // ecx
  bool v7; // zf
  const char *v8; // edx
  char *v9; // esi
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // eax
  CP4File *v13; // ecx
  CP4File_vtbl *v14; // esi
  int v15; // eax
  _LUID_AND_ATTRIBUTES *v16; // eax
  unsigned int v17; // esi
  GArrayLH<GString,2,GArrayDefaultPolicy> *v18; // ecx
  unsigned int v19; // edi
  CP4File_vtbl *v20; // edi
  unsigned int Edit; // eax
  unsigned int v22; // esi
  IShaderDevice *v23; // eax
  volatile LONG *v24; // edi
  void (__thiscall *dtr_CP4File)(CP4File *); // ecx
  CCountedStringPoolBase<unsigned int> *v26; // esi
  void *v27; // esi
  void *v28; // esi
  int v29; // ecx
  unsigned int v30; // edx
  CP4File *v31; // ecx
  CP4File_vtbl *v32; // eax
  int v33; // edi
  unsigned int v34; // ebx
  int v35; // edx
  int *v36; // ebx
  void *v37; // esi
  int v38; // [esp+0h] [ebp-34h]
  int v39; // [esp+Ch] [ebp-28h] BYREF
  unsigned int *v40; // [esp+10h] [ebp-24h]
  IShaderDevice *v41; // [esp+14h] [ebp-20h]
  _TRIVERTEX *rh; // [esp+18h] [ebp-1Ch] BYREF
  IShaderDevice *v43; // [esp+1Ch] [ebp-18h]
  int count; // [esp+20h] [ebp-14h]
  IShaderDevice *i; // [esp+24h] [ebp-10h]
  _DWORD *v46; // [esp+28h] [ebp-Ch]
  CUtlMemory<CImagePacker,int> var8; // [esp+2Ch] [ebp-8h] BYREF
  HBITMAP__ pa; // [esp+3Ch] [ebp+8h]
  CP4File_vtbl *tagInfoa; // [esp+40h] [ebp+Ch]

  v2 = p;
  v3 = *((GFxStream **)p + 201);
  if ( v3 == nullptr )
    v3 = (GFxStream *)((char *)p + 40);
  GString::GString(this: &var8);
  GFxStream::ReadString(this: v3, a2: (struct GString *)&var8);
  v4 = (char *)v3[12] - (char *)v3[11];
  *((_BYTE *)v3 + 21) = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = (_LUID_AND_ATTRIBUTES *)v3[11];
  v6 = *(unsigned __int16 *)((char *)&v5->Luid.LowPart + (_DWORD)v3[15]);
  v3[11] = (GFxStream)((char *)&v5->Luid.LowPart + 2);
  v7 = *(_DWORD *)tagInfo == 71;
  count = v6;
  v8 = "  importAssets: SourceUrl = %s, count = %d\n";
  if ( v7 )
    v8 = "  importAssets2: SourceUrl = %s, count = %d\n";
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8),
    pfmt: (unsigned int)p + 20,
    a3: (int)v8,
    a4: ((int)var8.m_pMemory & 0xFC) + 8);
  if ( *(_DWORD *)tagInfo == 71 )
  {
    v9 = *((char **)p + 201);
    if ( v9 == nullptr )
      v9 = (char *)p + 40;
    v10 = *((_DWORD *)v9 + 12) - *((_DWORD *)v9 + 11);
    v9[21] = 0;
    if ( v10 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    *((_DWORD *)v9 + 11) += 2;
  }
  v11 = *((_DWORD *)p + 8);
  v12 = *(_DWORD *)(v11 + 12);
  v13 = (CP4File *)(v11 + 8);
  if ( v12 < 0x1C )
  {
    v14 = GFxDataAllocator::OverflowAlloc(this: v13, bytes: 0x1Cu);
  }
  else
  {
    v14 = v13->__vftable;
    v13->__vftable = (CP4File_vtbl *)((char *)v13->__vftable + 28);
    v13->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v12 - 28);
  }
  if ( v14 != nullptr )
  {
    v14->dtr_CP4File = nullptr;
    v14->Edit = nullptr;
    v14->Add = nullptr;
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&v14->IsFileInPerforce);
    v14[1].dtr_CP4File = nullptr;
    v14[1].Edit = nullptr;
    v14[1].Add = nullptr;
    tagInfoa = v14;
  }
  else
  {
    tagInfoa = nullptr;
    v14 = nullptr;
  }
  v14[1].dtr_CP4File = *(void (__thiscall **)(CP4File *))(*((_DWORD *)p + 8) + 132);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v14->IsFileInPerforce,
    src: &var8,
    a3: v38);
  if ( count > 0 )
  {
    do
    {
      GString::GString(this: (CUtlMemory<CImagePacker,int> *)&var8.m_nAllocationCount);
      v15 = (char *)v3[12] - (char *)v3[11];
      *((_BYTE *)v3 + 21) = 0;
      if ( v15 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v16 = (_LUID_AND_ATTRIBUTES *)v3[11];
      v17 = *(unsigned __int16 *)((char *)&v16->Luid.LowPart + (_DWORD)v3[15]);
      v3[11] = (GFxStream)((char *)&v16->Luid.LowPart + 2);
      GFxStream::ReadString(this: v3, a2: (struct GString *)&var8.m_nAllocationCount);
      GFxLogBase<GFxLoadProcess>::LogParse(
        this: v18,
        pfmt: (unsigned int)v2 + 20,
        a3: (int)"  import: id = %d, name = %s\n",
        a4: v17);
      GFxMovieDataDef::LoadTaskData::AddNewResourceHandle(this: *((_DWORD *)v2 + 8), a2: &rh, a3: v17);
      i = v43;
      v19 = var8.m_nAllocationCount & 0xFFFFFFFC;
      GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v39);
      GString::operator=(
        this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v39,
        a2: (unsigned __int8 *)(v19 + 8));
      v20 = tagInfoa;
      Edit = (unsigned int)tagInfoa->Edit;
      v40 = (unsigned int *)v17;
      v22 = (unsigned int)tagInfoa->Edit + 1;
      v41 = i;
      if ( v22 >= Edit )
      {
        if ( (char *)v22 >= (char *)tagInfoa->Add )
          GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)&tagInfoa->dtr_CP4File,
            pheapAddr: tagInfoa,
            newCapacity: v22 + (v22 >> 2));
      }
      else
      {
        v23 = (IShaderDevice *)(Edit - v22);
        v46 = (_DWORD *)((char *)tagInfoa->dtr_CP4File + 12 * ((_DWORD)v23 + v22) - 12);
        if ( v23 != nullptr )
        {
          for ( i = v23; i != nullptr; i = (IShaderDevice *)((char *)i - 1) )
          {
            v24 = (volatile LONG *)(*v46 & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: v24 + 1, Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v24);
            v46 -= 3;
          }
          v20 = tagInfoa;
        }
        if ( v22 < (unsigned int)v20->Add >> 1 )
          GArrayDataBase<GFxFontData::AdvanceEntry,GAllocatorLH<GFxFontData::AdvanceEntry,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)&v20->dtr_CP4File,
            pheapAddr: v20,
            newCapacity: v22);
      }
      dtr_CP4File = v20->dtr_CP4File;
      v20->Edit = (bool (__thiscall *)(CP4File *))v22;
      v26 = (CCountedStringPoolBase<unsigned int> *)((char *)dtr_CP4File + 12 * v22 - 12);
      if ( v26 != nullptr )
      {
        GString::GString(this: v26, result: (CImagePacker *)&v39);
        v26->m_HashTable.m_Memory.m_pMemory = v40;
        v26->m_HashTable.m_Memory.m_nAllocationCount = (int)v41;
      }
      v27 = (void *)(v39 & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v39 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v27);
      if ( rh == nullptr && v43 != nullptr )
        GFxResource::Release(this: v43);
      v28 = (void *)(var8.m_nAllocationCount & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((var8.m_nAllocationCount & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
      v7 = count-- == 1;
      v2 = p;
    }
    while ( !v7 );
    v14 = tagInfoa;
  }
  GFxLoadProcess::AddImportData(this: (GFxLoadProcess *)v2, a2: (struct GFxImportData *)v14);
  v29 = *((_DWORD *)v2 + 8);
  v30 = *(_DWORD *)(v29 + 12);
  v31 = (CP4File *)(v29 + 8);
  if ( v30 < 8 )
  {
    v32 = GFxDataAllocator::OverflowAlloc(this: v31, bytes: 8u);
  }
  else
  {
    v32 = v31->__vftable;
    v31->__vftable = (CP4File_vtbl *)((char *)v31->__vftable + 8);
    v31->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(v30 - 8);
  }
  if ( v32 != nullptr )
  {
    v32->dtr_CP4File = (void (__thiscall *)(CP4File *))&GFxInitImportActions::`vftable';
    v32->Edit = nullptr;
    pa.unused = (int)v32;
  }
  else
  {
    pa.unused = 0;
  }
  v33 = (int)v2 + 792;
  *(_DWORD *)(pa.unused + 4) = v14[1].Edit;
  v34 = *(_DWORD *)(v33 + 4) + 1;
  if ( v34 >= *(_DWORD *)(v33 + 4) )
  {
    if ( v34 >= *(_DWORD *)(v33 + 8) )
      GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
        this: v33,
        result: (D3DXVECTOR4 *)v33,
        newCapacity: v34 + (v34 >> 2));
  }
  else if ( v34 < *(_DWORD *)(v33 + 8) >> 1 )
  {
    GArrayDataBase<GASExecuteTag *,GAllocatorGH<GASExecuteTag *,2>,GArrayConstPolicy<32,16,0>>::Reserve(
      this: v33,
      result: (D3DXVECTOR4 *)v33,
      newCapacity: *(_DWORD *)(v33 + 4) + 1);
  }
  v35 = *(_DWORD *)v33;
  *(_DWORD *)(v33 + 4) = v34;
  v36 = (int *)(v35 + 4 * v34 - 4);
  if ( v36 != nullptr )
    *v36 = pa.unused;
  v37 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v37);
}
