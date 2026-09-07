// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxloader.cpp
// Functions: 14
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxloader.h"

//------------------------------------------------------------------------------
// Address: 0x1006E9F0
// Name: public: virtual void GFxStateBag::SetState(enum GFxState::StateType,class GFxState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxStateBag::SetState(IMatRenderContext *this, int a2, int a3)
{
  int v3; // eax

  v3 = this->AddRef(this);
  if ( v3 != 0 )
    LOBYTE(v3) = (*(bool (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 8))(a1: v3, a2, a3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1006EA10
// Name: public: virtual class GFxState __near * GFxStateBag::GetStateAddRef(enum GFxState::StateType)const
// Source: json
//------------------------------------------------------------------------------
IMorph *__userpurge GFxStateBag::GetStateAddRef@<eax>(
        IMatRenderContext *this@<ecx>,
        unsigned int state,
        const char *a3)
{
  int v3; // eax

  v3 = this->AddRef(this);
  if ( v3 != 0 )
    return (*(IMorph *(__thiscall **)(int, unsigned int))(*(_DWORD *)v3 + 12))(a1: v3, a2: state);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006EA30
// Name: public: virtual void GFxStateBag::GetStatesAddRef(class GFxState __near * __near *,enum GFxState::StateType const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStateBag::GetStatesAddRef(
        IMatRenderContext *this,
        void *pstateList,
        void (*pstates)(const char *, ...),
        unsigned int count)
{
  int v4; // eax

  v4 = this->AddRef(this);
  if ( v4 != 0 )
    (*(void (__thiscall **)(int, void *, void (*)(const char *, ...), unsigned int))(*(_DWORD *)v4 + 16))(
      a1: v4,
      a2: pstateList,
      a3: pstates,
      a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x1006EA80
// Name: public: static bool GFxURLBuilder::IsPathAbsolute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFxURLBuilder::IsPathAbsolute(
        const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  unsigned int Char; // eax
  unsigned int v2; // eax

  if ( result == nullptr )
    return 1;
  if ( LOBYTE(result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable) == 0 )
    return 1;
  Char = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&result);
  if ( Char == 47 || Char == 92 )
    return 1;
  for ( ;
        Char != 0;
        Char = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&result) )
  {
    if ( Char == 58 )
    {
      v2 = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&result);
      if ( v2 == 47 || v2 == 92 )
        return 1;
    }
    else if ( Char == 47 || Char == 92 )
    {
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006EAE0
// Name: public: virtual GFxLoader::~GFxLoader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoader::~GFxLoader(CMatRenderContextBase *this)
{
  ConVar *Instance; // eax
  IShaderAPI *v3; // ecx
  IShaderAPI *m_iRefs; // ecx

  this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContextBase_vtbl *)&GFxLoader::`vftable';
  Instance = (ConVar *)GFxAmpServer::GetInstance(a1: (unsigned int)this);
  GFxAmpServer::RemoveLoader(this: Instance);
  v3 = (IShaderAPI *)this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  m_iRefs = (IShaderAPI *)this->m_iRefs;
  if ( m_iRefs != nullptr )
    GRefCountImpl::Release(this: m_iRefs);
  this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContextBase_vtbl *)&GFxStateBag::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1006EB20
// Name: protected: virtual bool GFxLoader::CheckTagLoader(int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoader::CheckTagLoader(CMatRenderContextBase *this, IMaterialInternal *tagType)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1006EB80
// Name: public: class GFxMovieDef __near * GFxLoader::CreateMovie(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoader::CreateMovie(
        CMatRenderContextBase *this,
        ITexture *pfilename,
        unsigned int loadConstants,
        void (__cdecl **memoryArena)(int))
{
  CRefCountServiceBase<1,CRefMT>_vtbl *v4; // eax

  if ( pfilename != nullptr && LOBYTE(pfilename->__vftable) != 0 )
  {
    v4 = this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
    if ( v4 != nullptr )
      GFxLoaderImpl::CreateMovie(
        this: (GFxLoaderImpl *)v4,
        a2: (char *)pfilename,
        loadConstants: loadConstants | (unsigned int)this->m_pCurrentMaterial,
        memoryArena);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EC00
// Name: public: static void GFxURLBuilder::DefaultBuildURL(class GString __near *,struct GFxURLBuilder::LocationInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxURLBuilder::DefaultBuildURL(
        int a1@<edi>,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a2,
        int loc)
{
  int v4; // ebx
  int v5; // eax
  _DWORD *v6; // esi
  int v7; // edi
  int v8; // eax
  const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v9; // [esp-4h] [ebp-Ch]
  int v11; // [esp-4h] [ebp-Ch]
  int v12; // [esp+0h] [ebp-8h]
  int loca; // [esp+14h] [ebp+Ch]

  v4 = loc + 4;
  v9 = (const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((*(_DWORD *)(loc + 4) & 0xFFFFFFFC) + 8);
  loca = loc + 4;
  if ( GFxURLBuilder::IsPathAbsolute(result: v9) != 0 )
  {
    GString::operator=(this: a2, src: v4, a3: v12);
  }
  else
  {
    v5 = *(_DWORD *)(loc + 8);
    v6 = (_DWORD *)(loc + 8);
    v7 = *(_DWORD *)(v5 & 0xFFFFFFFC) & 0x7FFFFFFF;
    if ( v7 != 0 )
    {
      GString::operator=(this: a2, src: (int)v6, a3: a1);
      v8 = *(char *)((*v6 & 0xFFFFFFFC) + v7 + 7);
      if ( v8 != 92 && v8 != 47 )
        GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)a2, putf8str: (int)"/");
      GString::operator+=(this: a2, src: loca, srcSize: v11);
    }
    else
    {
      GString::operator=(this: a2, src: v4, a3: a1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EC90
// Name: public: static bool GFxURLBuilder::ExtractFilePath(class GString __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxURLBuilder::ExtractFilePath(
        const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *ppath,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a2)
{
  signed int v2; // esi
  unsigned int CharAt; // eax
  struct GString v4; // eax
  void *v5; // edi
  int v6; // [esp+0h] [ebp-Ch]
  GString v7; // [esp+8h] [ebp-4h] BYREF

  v2 = GString::GetLength(this: (GString *)a2) - 1;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      CharAt = GString::GetCharAt(this: (GString *)a2, a2: v2);
      if ( CharAt == 47 || CharAt == 92 )
        break;
      if ( --v2 < 0 )
        return;
    }
    v4.pData = GString::Substring(this: (GString *)a2, a2: &v7, a3: 0).pData;
    GString::operator=(this: a2, src: (int)v4.pData, a3: v6);
    v5 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ED10
// Name: public: static class GImage __near * GFxImageCreator::LoadBuiltinImage(class GFile __near *,enum GFxFileConstants::FileFormatType,enum GFxResource::ResourceUse,class GFxLog __near *,class GFxJpegSupportBase __near *,class GFxPNGSupportBase __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxImageCreator::LoadBuiltinImage(
        int a1@<ebx>,
        struct GFile *a2,
        const CBitVecT<CFixedBitVecBase<64> > *format,
        int a4,
        int a5,
        CBitVecT<CFixedBitVecBase<64> > *pjpegState,
        int a7,
        struct GMemoryHeap *a8)
{
  int v9; // eax

  v9 = (int)a2->GetFilePath(this: a2);
  switch ( (unsigned int)format )
  {
    case 0xAu:
      if ( pjpegState != nullptr )
      {
        (*(void (__thiscall **)(CBitVecT<CFixedBitVecBase<64> > *, struct GFile *, struct GMemoryHeap *))(pjpegState->m_Ints[0] + 8))(
          a1: pjpegState,
          a2,
          a3: a8);
      }
      else if ( a5 != 0 )
      {
        GFxLogBase<GFxLog>::LogMessage(
          this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(a5 + 12),
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(a5 + 12),
          this_4: (int)"Unable to load JPEG at URL \"%s\" - libjpeg not included\n",
          this_8: v9);
      }
      break;
    case 0xBu:
      if ( a7 != 0 )
      {
        (*(void (__thiscall **)(int, struct GFile *, struct GMemoryHeap *))(*(_DWORD *)a7 + 4))(a1: a7, a2, a3: a8);
      }
      else if ( a5 != 0 )
      {
        GFxLogBase<GFxLog>::LogMessage(
          this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(a5 + 12),
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(a5 + 12),
          this_4: (int)"Unable to load PNG at URL \"%s\" - GFxPNGState not set\n",
          this_8: v9);
      }
      break;
    case 0xDu:
      GImage::ReadTga(
        pin: a4 != 3 ? nullptr : (const IMesh *)9,
        (int)a2,
        a3: a4 != 3 ? nullptr : (ICachedPerFrameMeshData *)9,
        a4: (int)a8);
      break;
    case 0xEu:
      GImage::ReadDDS(a1, a2, a3: a8);
      break;
    default:
      if ( a5 != 0 )
        GFxLogBase<GFxLog>::LogMessage(
          this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(a5 + 12),
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(a5 + 12),
          this_4: (int)"Default image loader failed to load '%s'",
          this_8: v9);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EE60
// Name: public: void GFxLoader::SetResourceLib(class GFxResourceLib __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxLoader::SetResourceLib(CMatRenderContextBase *this@<ecx>, IShaderDevice *plib, VMatrix *a3)
{
  IShaderAPI *m_iRefs; // ecx
  IShaderDevice *v5; // edi
  CRefCountServiceBase<1,CRefMT>_vtbl *v6; // esi
  IShaderAPI *v7; // ecx

  if ( this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable != nullptr )
  {
    if ( plib != nullptr )
      GRefCountImpl::AddRef(this: plib);
    m_iRefs = (IShaderAPI *)this->m_iRefs;
    if ( m_iRefs != nullptr )
      GRefCountImpl::Release(this: m_iRefs);
    this->m_iRefs = (int)plib;
    v5 = (IShaderDevice *)plib[2].__vftable;
    v6 = this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
    if ( v5 != nullptr )
      GRefCountImpl::AddRef(this: v5);
    v7 = (IShaderAPI *)v6[3].dtr_CRefCountServiceBase<1,CRefMT>;
    if ( v7 != nullptr )
      GRefCountImpl::Release(this: v7);
    v6[3].dtr_CRefCountServiceBase<1,CRefMT> = (void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *))v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EEB0
// Name: private: void GFxLoader::InitLoader(struct GFxLoader::LoaderConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
CRefCountServiceBase<1,CRefMT>_vtbl *__thiscall GFxLoader::InitLoader(
        CMatRenderContextBase *this,
        IMaterialInternal **debugHeap)
{
  IMaterialInternal **v2; // ebx
  bool v4; // cl
  FourVectors *v5; // eax
  int v6; // eax
  char *v7; // eax
  unsigned int v8; // ecx
  CRefCountServiceBase<1,CRefMT>_vtbl *result; // eax
  IShaderAPI *v10; // eax
  IShaderAPI *v11; // edi
  GFxMeshCacheManager *v12; // eax
  IShaderAPI *v13; // edi
  ConVar *Instance; // eax
  int v15; // [esp+Ch] [ebp-10h] BYREF
  int v16; // [esp+10h] [ebp-Ch] BYREF
  int v17; // [esp+14h] [ebp-8h] BYREF
  int v18; // [esp+18h] [ebp-4h] BYREF

  v2 = debugHeap;
  v4 = ((unsigned int)*debugHeap & 0x10000000) != 0;
  this->m_pCurrentMaterial = *debugHeap;
  LOBYTE(debugHeap) = v4;
  v18 = 2;
  v5 = (FourVectors *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &v18);
  if ( v5 != nullptr )
    GFxResourceLib::GFxResourceLib(this: v5, debug: (const FourVectors *)debugHeap);
  else
    v6 = 0;
  this->m_iRefs = v6;
  v17 = 2;
  v7 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 64, a3: &v17);
  if ( v7 != nullptr )
    result = (CRefCountServiceBase<1,CRefMT>_vtbl *)GFxLoaderImpl::GFxLoaderImpl(
                                                      this: v7,
                                                      result: (tagDROPSTRUCT *)this->m_iRefs,
                                                      (bool)debugHeap);
  else
    result = nullptr;
  this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = result;
  if ( result != nullptr )
  {
    ((void (__thiscall *)(CMatRenderContextBase *, int, IMaterialInternal *))this->BeginRender)(
      a1: this,
      a2: 10,
      a3: v2[1]);
    v16 = 2;
    v10 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v16);
    v11 = nullptr;
    if ( v10 != nullptr )
    {
      v10->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
      v10[3].__vftable = nullptr;
      v10[1].__vftable = (IShaderAPI_vtbl *)1;
      v10[2].__vftable = (IShaderAPI_vtbl *)13;
      v10->__vftable = (IShaderAPI_vtbl *)&GFxParseControl::`vftable';
      v11 = v10;
    }
    ((void (__thiscall *)(CMatRenderContextBase *, int, IShaderAPI *))this->BeginRender)(a1: this, a2: 13, a3: v11);
    if ( v11 != nullptr )
      GRefCountImpl::Release(this: v11);
    ((void (__thiscall *)(CMatRenderContextBase *, int, IMaterialInternal *))this->BeginRender)(
      a1: this,
      a2: 30,
      a3: v2[2]);
    ((void (__thiscall *)(CMatRenderContextBase *, int, IMaterialInternal *))this->BeginRender)(
      a1: this,
      a2: 29,
      a3: v2[3]);
    v15 = 2;
    v12 = (GFxMeshCacheManager *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 28, a3: &v15);
    if ( v12 != nullptr )
      v13 = (IShaderAPI *)GFxMeshCacheManager::GFxMeshCacheManager(this: v12, a2: (bool)debugHeap);
    else
      v13 = nullptr;
    result = (CRefCountServiceBase<1,CRefMT>_vtbl *)((int (__thiscall *)(CMatRenderContextBase *, int, IShaderAPI *))this->BeginRender)(
                                                      a1: this,
                                                      a2: 16,
                                                      a3: v13);
    if ( v13 != nullptr )
      result = (CRefCountServiceBase<1,CRefMT>_vtbl *)GRefCountImpl::Release(this: v13);
  }
  if ( (_BYTE)debugHeap == 0 )
  {
    Instance = (ConVar *)GFxAmpServer::GetInstance(a1: v8);
    return (CRefCountServiceBase<1,CRefMT>_vtbl *)GFxAmpServer::AddLoader(this: Instance);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006F020
// Name: public: virtual class GImageInfoBase __near * GFxImageCreator::CreateImage(class GFxImageCreateInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GImageInfo *__userpurge GFxImageCreator::CreateImage@<eax>(
        CBitVecT<CFixedBitVecBase<64> > *this@<ecx>,
        unsigned int result,
        int info)
{
  CBitVecAccessor *v3; // esi
  unsigned int *v4; // ecx
  int (__thiscall *v5)(unsigned int *, int, unsigned int *); // edx
  GImageInfo *v6; // eax
  IShaderAPI *v8; // ebx
  struct GImage *v9; // eax
  struct GImage *v10; // edi
  unsigned int *m_pDWords; // ecx
  unsigned int Width; // eax
  unsigned int Height; // ebx
  unsigned int *v14; // eax
  IShaderAPI **v15; // eax
  GImageInfo *v16; // eax
  GImageInfo *v17; // eax
  GImageInfo *v18; // esi
  unsigned int *v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // eax
  int (__thiscall *v22)(unsigned int *, int, int *); // edx
  GImageInfo *v23; // eax
  int v24; // eax
  struct GTexture *v25; // esi
  int (__thiscall *v26)(unsigned int *, int, int *); // edx
  GImageInfo *v27; // eax
  GImageInfo *v28; // ebx
  int v29; // [esp+Ch] [ebp-18h] BYREF
  int v30; // [esp+10h] [ebp-14h] BYREF
  int v31; // [esp+14h] [ebp-10h] BYREF
  CBitVecT<CFixedBitVecBase<64> > *v32; // [esp+18h] [ebp-Ch]
  IShaderAPI *v33; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int *v34; // [esp+20h] [ebp-4h]

  v3 = (CBitVecAccessor *)result;
  v32 = this;
  v4 = *(unsigned int **)(result + 40);
  if ( v4 != nullptr )
  {
    v34 = *(unsigned int **)(result + 40);
  }
  else
  {
    v34 = (unsigned int *)GMemory::pGlobalHeap;
    v4 = (unsigned int *)GMemory::pGlobalHeap;
  }
  if ( *(_DWORD *)result == 1 )
  {
    v14 = *(unsigned int **)(result + 16);
    if ( v14 != nullptr )
      ++v14[1];
    Height = v14[4];
    v10 = (struct GImage *)v14;
    result = v14[3];
  }
  else
  {
    if ( *(_DWORD *)result != 2 )
    {
      v5 = *(int (__thiscall **)(unsigned int *, int, unsigned int *))(*v4 + 40);
      result = 2;
      v6 = (GImageInfo *)v5(a1: v4, a2: 40, a3: &result);
      if ( v6 != nullptr )
        return GImageInfo::GImageInfo(this: v6, a2: nullptr, a3: false);
      return nullptr;
    }
    v8 = (IShaderAPI *)(*(int (__thiscall **)(int, unsigned int, int, int))(**(_DWORD **)(result + 20) + 4))(
                         a1: *(_DWORD *)(result + 20),
                         a2: (*(_DWORD *)(*(_DWORD *)(result + 16) + 16) & 0xFFFFFFFC) + 8,
                         a3: 33,
                         a4: 438);
    v33 = v8;
    if ( v8 == nullptr )
      return nullptr;
    GFxImageCreator::LoadBuiltinImage(
      a1: (int)v8,
      a2: (struct GFile *)v8,
      format: *((const CBitVecT<CFixedBitVecBase<64> > **)v3[2].m_pDWords + 2),
      a4: v3->m_iBit,
      a5: v3[3].m_iBit,
      pjpegState: (CBitVecT<CFixedBitVecBase<64> > *)v3[4].m_pDWords,
      a7: v3[4].m_iBit,
      a8: (struct GMemoryHeap *)v3[5].m_pDWords);
    v10 = v9;
    if ( v9 == nullptr )
    {
      GRefCountImpl::Release(this: v8);
      return nullptr;
    }
    m_pDWords = v3[2].m_pDWords;
    Width = *((unsigned __int16 *)m_pDWords + 10);
    if ( (_WORD)Width == 0 )
      Width = v10->Width;
    result = Width;
    Height = *((unsigned __int16 *)m_pDWords + 11);
    if ( (_WORD)Height == 0 )
      Height = v10->Height;
    GRefCountImpl::Release(this: v33);
    v4 = v34;
  }
  if ( LOBYTE(v32[1].m_Ints[1]) != 0 )
  {
    v33 = (IShaderAPI *)2;
    v15 = &v33;
    goto LABEL_21;
  }
  v19 = v3[3].m_pDWords;
  if ( v19 == nullptr )
    goto LABEL_43;
  v20 = v19[3];
  if ( v20 == 0 )
    goto LABEL_43;
  v21 = v19[7];
  if ( (v21 & 0x10000) != 0 )
  {
    v31 = 2;
    v15 = (IShaderAPI **)&v31;
LABEL_21:
    v16 = (GImageInfo *)(*(int (__thiscall **)(unsigned int *, int, IShaderAPI **))(*v4 + 40))(a1: v4, a2: 40, a3: v15);
    if ( v16 != nullptr )
    {
      v17 = GImageInfo::GImageInfo(this: v16, a2: v10, a3: result, a4: Height, a5: false);
LABEL_23:
      v18 = v17;
      GRefCountNTSImpl::Release(this: v10);
      return v18;
    }
    goto LABEL_24;
  }
  if ( LOBYTE(v3[5].m_iBit) != 0 && (v21 & 0x100000) == 0 )
  {
    v22 = *(int (__thiscall **)(unsigned int *, int, int *))(*v4 + 40);
    v30 = 2;
    v23 = (GImageInfo *)v22(a1: v4, a2: 40, a3: &v30);
    if ( v23 != nullptr )
    {
      v17 = GImageInfo::GImageInfo(this: v23, a2: v10, a3: result, a4: Height, a5: true);
      goto LABEL_23;
    }
LABEL_24:
    GRefCountNTSImpl::Release(this: v10);
    return nullptr;
  }
  v24 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v20 + 8))(a1: v20);
  v25 = (struct GTexture *)v24;
  if ( v24 == 0 )
  {
LABEL_43:
    GRefCountNTSImpl::Release(this: v10);
    return nullptr;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, GImageBase *, int))(*(_DWORD *)v24 + 4))(
         a1: v24,
         a2: &v10->GImageBase,
         a3: 1) == 0 )
  {
    if ( InterlockedExchangeAdd(Addend: &v25->RefCount.Value, Value: -1) == 1 )
      ((void (__thiscall *)(struct GTexture *, int))v25->dtr_GTexture)(a1: v25, a2: 1);
    goto LABEL_43;
  }
  v26 = *(int (__thiscall **)(unsigned int *, int, int *))(*v34 + 40);
  v29 = 2;
  v27 = (GImageInfo *)v26(a1: v34, a2: 40, a3: &v29);
  if ( v27 != nullptr )
    v28 = GImageInfo::GImageInfo(this: v27, a2: v25, a3: result, a4: Height);
  else
    v28 = nullptr;
  if ( InterlockedExchangeAdd(Addend: &v25->RefCount.Value, Value: -1) == 1 )
    ((void (__thiscall *)(struct GTexture *, int))v25->dtr_GTexture)(a1: v25, a2: 1);
  GRefCountNTSImpl::Release(this: v10);
  return v28;
}

//------------------------------------------------------------------------------
// Address: 0x1006F290
// Name: public: GFxLoader::GFxLoader(class GPtr<class GFxFileOpenerBase> const __near &,class GPtr<class GFxZlibSupportBase> const __near &,class GPtr<class GFxJpegSupportBase> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoader::GFxLoader(
        CMatRenderContextBase *this,
        const matrix3x4_t *pfileOpener,
        IShaderDevice **a3,
        IShaderDevice **pjpeg)
{
  IShaderDevice *v5; // ecx
  IShaderDevice *v6; // ecx
  IShaderAPI *v7; // esi
  IShaderDevice *v8; // ecx
  IShaderAPI *v9; // edi
  ShaderParamType_t config; // [esp+8h] [ebp-10h] BYREF
  IShaderAPI *v11; // [esp+Ch] [ebp-Ch]
  IShaderDevice *v12; // [esp+10h] [ebp-8h]
  IShaderAPI *v13; // [esp+14h] [ebp-4h]

  this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContextBase_vtbl *)&GFxLoader::`vftable';
  v5 = (IShaderDevice *)LODWORD(pfileOpener->m_flMatVal[0][0]);
  config = SHADER_PARAM_TYPE_TEXTURE;
  if ( v5 != nullptr )
    GRefCountImpl::AddRef(this: v5);
  v6 = *a3;
  v11 = (IShaderAPI *)LODWORD(pfileOpener->m_flMatVal[0][0]);
  if ( v6 != nullptr )
    GRefCountImpl::AddRef(this: v6);
  v7 = (IShaderAPI *)*a3;
  v8 = *pjpeg;
  v12 = *a3;
  if ( v8 != nullptr )
    GRefCountImpl::AddRef(this: v8);
  v13 = (IShaderAPI *)*pjpeg;
  v9 = v13;
  GFxLoader::InitLoader(this, debugHeap: (IMaterialInternal **)&config);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
}
