// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gjpegutil_jpeglib.cpp
// Functions: 36
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gjpegutil_jpeglib.h"

//------------------------------------------------------------------------------
// Address: 0x100FB370
// Name: public: static void GJPEGRwSource::InitSource(struct jpeg_decompress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GJPEGRwSource::InitSource(struct jpeg_decompress_struct *a1)
{
  *(_BYTE *)(*((_DWORD *)a1 + 6) + 32) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FB380
// Name: public: static void GJPEGRwDest::InitDestination(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
static _DWORD *__cdecl GJPEGRwDest::InitDestination(struct jpeg_compress_struct *a1)
{
  _DWORD *result; // eax

  result = *((_DWORD **)a1 + 6);
  *result = result + 6;
  result[1] = 2048;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FB3A0
// Name: private: static int GJPEGInputImpl_jpeglib::JpegCreateDecompress(struct jpeg_decompress_struct __near *,struct GFxJpegErrorHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::JpegCreateDecompress(MaterialMatrixMode_t pcinfo, matrix3x4_t *pjerr, int a3)
{
  if ( _setjmp3(a1: *(_DWORD *)(a3 + 332), a2: 0) != 0 )
    jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)pjerr);
  else
    jpeg_CreateDecompress(dst: (struct jpeg_decompress_struct *)pjerr, a2: 62, a3: 0x1B0u);
}

//------------------------------------------------------------------------------
// Address: 0x100FB3F0
// Name: private: static int GJPEGInputImpl_jpeglib::JpegReadHeader(struct jpeg_decompress_struct __near *,struct GFxJpegErrorHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GJPEGInputImpl_jpeglib::JpegReadHeader(
        struct jpeg_decompress_struct *a1,
        struct GFxJpegErrorHandler *a2,
        char a3)
{
  if ( _setjmp3(a1: *((_DWORD *)a2 + 83), a2: 0) != 0 )
  {
    jpeg_destroy_compress(a1);
    return 0;
  }
  else
  {
    jpeg_read_header(a1, a2: a3);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB440
// Name: public: static unsigned char GJPEGRwSource::FillInputBuffer(struct jpeg_decompress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGRwSource::FillInputBuffer(void *cinfo, int a2)
{
  int v2; // esi
  _BYTE *v3; // edi
  unsigned int v4; // eax

  v2 = *(_DWORD *)(a2 + 24);
  v3 = (_BYTE *)(v2 + 33);
  v4 = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(v2 + 28) + 40))(
         a1: *(_DWORD *)(v2 + 28),
         a2: v2 + 33,
         a3: 2048);
  if ( v4 == 0 )
  {
    if ( *(_BYTE *)(v2 + 32) != 0 )
      return;
    *v3 = -1;
    *(_BYTE *)(v2 + 34) = -39;
    v4 = 2;
  }
  if ( *(_BYTE *)(v2 + 32) != 0
    && v4 >= 4
    && *v3 == 0xFF
    && *(_BYTE *)(v2 + 34) == 0xD9
    && *(_BYTE *)(v2 + 35) == 0xFF
    && *(_BYTE *)(v2 + 36) == 0xD8 )
  {
    *(_BYTE *)(v2 + 34) = -40;
    *(_BYTE *)(v2 + 36) = -39;
  }
  *(_DWORD *)v2 = v3;
  *(_DWORD *)(v2 + 4) = v4;
  *(_BYTE *)(v2 + 32) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FB4C0
// Name: public: static void GJPEGRwSource::SkipInputData(struct jpeg_decompress_struct __near *,long)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GJPEGRwSource::SkipInputData(struct jpeg_decompress_struct *a1, int a2)
{
  _DWORD *v2; // eax
  int v3; // ebx
  int v4; // esi
  _BYTE *v5; // edi
  unsigned int v6; // eax
  _DWORD *v7; // [esp+4h] [ebp-4h]

  v2 = *((_DWORD **)a1 + 6);
  v3 = a2;
  v7 = v2;
  if ( a2 > 0 )
  {
    if ( a2 > v2[1] )
    {
      while ( 1 )
      {
        v4 = *((_DWORD *)a1 + 6);
        v3 -= v2[1];
        v5 = (_BYTE *)(v4 + 33);
        v6 = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(v4 + 28) + 40))(
               a1: *(_DWORD *)(v4 + 28),
               a2: v4 + 33,
               a3: 2048);
        if ( v6 != 0 )
          goto LABEL_6;
        if ( *(_BYTE *)(v4 + 32) == 0 )
          break;
LABEL_14:
        v2 = v7;
        if ( v3 <= v7[1] )
          goto LABEL_15;
      }
      *v5 = -1;
      *(_BYTE *)(v4 + 34) = -39;
      v6 = 2;
LABEL_6:
      if ( *(_BYTE *)(v4 + 32) != 0
        && v6 >= 4
        && *v5 == 0xFF
        && *(_BYTE *)(v4 + 34) == 0xD9
        && *(_BYTE *)(v4 + 35) == 0xFF
        && *(_BYTE *)(v4 + 36) == 0xD8 )
      {
        *(_BYTE *)(v4 + 34) = -40;
        *(_BYTE *)(v4 + 36) = -39;
      }
      *(_DWORD *)v4 = v5;
      *(_DWORD *)(v4 + 4) = v6;
      *(_BYTE *)(v4 + 32) = 0;
      goto LABEL_14;
    }
LABEL_15:
    *v2 += v3;
    v2[1] -= v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB560
// Name: public: static unsigned char GJPEGRwDest::EmptyOutputBuffer(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
static unsigned __int8 __cdecl GJPEGRwDest::EmptyOutputBuffer(struct jpeg_compress_struct *a1)
{
  int v1; // esi

  v1 = *((_DWORD *)a1 + 6);
  if ( (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(v1 + 20) + 36))(
         a1: *(_DWORD *)(v1 + 20),
         a2: v1 + 24,
         a3: 2048) != 2048 )
    return 0;
  *(_DWORD *)v1 = v1 + 24;
  *(_DWORD *)(v1 + 4) = 2048;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FB5A0
// Name: public: GJPEGRwSource::GJPEGRwSource(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *__thiscall GJPEGRwSource::GJPEGRwSource(
        CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *this,
        IShaderDevice *pin)
{
  IShaderAPI *v3; // ecx

  *((_DWORD *)this + 7) = 0;
  if ( pin != nullptr )
    GRefCountImpl::AddRef(this: pin);
  v3 = *((IShaderAPI **)this + 7);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  *((_DWORD *)this + 7) = pin;
  *((_BYTE *)this + 32) = 1;
  this->m_Memory.m_nGrowSize = (int)GJPEGRwSource::InitSource;
  this->m_Size = (int)GJPEGRwSource::FillInputBuffer;
  this->m_pElements = (CMatRenderContextBase::RenderTargetStackElement_t *)GJPEGRwSource::SkipInputData;
  *((_DWORD *)this + 5) = jpeg_resync_to_restart;
  *((_DWORD *)this + 6) = CDummyMaterialSystem::EndBatch;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_pMemory = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FB610
// Name: public: static void GJPEGRwDest::TermDestination(struct jpeg_compress_struct __near *)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GJPEGRwDest::TermDestination(struct jpeg_compress_struct *a1)
{
  int v1; // edi
  int v2; // esi
  int result; // eax
  IShaderAPI *v4; // ecx

  v1 = *((_DWORD *)a1 + 6);
  v2 = 2048 - *(_DWORD *)(v1 + 4);
  if ( v2 <= 0
    || (result = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(v1 + 20) + 36))(
                   a1: *(_DWORD *)(v1 + 20),
                   a2: v1 + 24,
                   a3: 2048 - *(_DWORD *)(v1 + 4))) == v2 )
  {
    v4 = *(IShaderAPI **)(v1 + 20);
    if ( v4 != nullptr )
      GRefCountImpl::Release(this: v4);
    result = ((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: v1);
    *((_DWORD *)a1 + 6) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FB6A0
// Name: void GJPEGUtil_SetupRwDest(struct jpeg_compress_struct __near *,class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGUtil_SetupRwDest(void *cinfo, int a2, IShaderDevice *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  IShaderAPI *v5; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  v6 = 2;
  v3 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2072, a3: &v6);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3[5] = 0;
    if ( a3 != nullptr )
      GRefCountImpl::AddRef(this: a3);
    v5 = (IShaderAPI *)v4[5];
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
    v4[5] = a3;
    v4[2] = GJPEGRwDest::InitDestination;
    v4[3] = GJPEGRwDest::EmptyOutputBuffer;
    v4[4] = GJPEGRwDest::TermDestination;
    *v4 = v4 + 6;
    v4[1] = 2048;
    *(_DWORD *)(a2 + 24) = v4;
  }
  else
  {
    *(_DWORD *)(a2 + 24) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB730
// Name: JpegErrorExit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn JpegErrorExit(int *a1)
{
  int v1; // esi
  char _Src[200]; // [esp+4h] [ebp-CCh] BYREF

  v1 = *a1;
  (*(void (__cdecl **)(int *, char *))(*a1 + 12))(a1, a2: _Src);
  strcpy_s(_Dst: (char *)(v1 + 132), _SizeInBytes: 0xC8u, _Src);
  longjmp(Buf: *(int **)(v1 + 332), Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100FB780
// Name: public: virtual int GJPEGInputImpl_jpeglib::StartImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::StartImage(CMatRenderContext *this)
{
  if ( *((_BYTE *)this + 777) == 0 )
  {
    if ( _setjmp3(a1: *((_DWORD *)this + 193), a2: 0) != 0 )
    {
      jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)&this->m_iRefs);
      *((_WORD *)this + 388) = 256;
    }
    else
    {
      if ( this->m_pLocalCubemapTexture != (ITexture *)202 )
        jpeg_read_header(a1: (struct jpeg_decompress_struct *)&this->m_iRefs, a2: 1);
      jpeg_start_decompress(a1: (struct jpeg_decompress_struct *)&this->m_iRefs);
      *((_BYTE *)this + 776) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB800
// Name: public: GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(enum GJPEGInputImpl_jpeglib::SWF_DEFINE_BITS_JPEG2_HEADER_ONLY,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContext *__thiscall GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(
        CMatRenderContext *this,
        int e,
        unsigned int a3,
        unsigned int bufSize)
{
  void *v5; // eax
  unsigned int v6; // ecx
  struct jpeg_error_mgr *v7; // eax
  int v8; // eax
  ITexture *v9; // eax
  _DWORD v11[7]; // [esp+Ch] [ebp-20h] BYREF
  int v12; // [esp+28h] [ebp-4h] BYREF

  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContext_vtbl *)&GJPEGInputImpl_jpeglib::`vftable';
  v12 = 2;
  v5 = GMemory::pGlobalHeap->Alloc(this: GMemory::pGlobalHeap, a2: 64, a3: 32, a4: &v12);
  v6 = bufSize;
  *((_DWORD *)this + 193) = v5;
  memset(&v11[2], 0, 20);
  *(_QWORD *)v11 = __PAIR64__(v6, a3);
  *((_WORD *)this + 388) = 0;
  v7 = jpeg_std_error(a1: (struct jpeg_error_mgr *)&this->m_vecViewRight.z);
  LODWORD(this->m_vecViewRight.z) = JpegErrorExit;
  this->m_iRefs = (int)v7;
  GJPEGInputImpl_jpeglib::JpegCreateDecompress(
    pcinfo: (MaterialMatrixMode_t)&this->m_iRefs,
    pjerr: (matrix3x4_t *)&this->m_iRefs,
    a3: (int)&this->m_vecViewRight.z);
  if ( v8 != 0 )
  {
    bufSize = 2;
    v9 = (ITexture *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2084, a3: &bufSize);
    if ( v9 != nullptr )
    {
      v9[7].__vftable = nullptr;
      v9[7].__vftable = nullptr;
      LOBYTE(v9[8].__vftable) = 1;
      qmemcpy(v9, v11, 28);
    }
    else
    {
      v9 = nullptr;
    }
    this->m_pCurrentFrameBufferCopyTexture[0] = v9;
    GJPEGInputImpl_jpeglib::JpegReadHeader(
      a1: (struct jpeg_decompress_struct *)&this->m_iRefs,
      a2: (struct GFxJpegErrorHandler *)&this->m_vecViewRight.z,
      a3: 0);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FB8F0
// Name: public: virtual bool GJPEGInputImpl_jpeglib::IsErrorOccurred(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::IsErrorOccurred(CMatRenderContext *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100FB900
// Name: public: virtual void GJPEGInputImpl_jpeglib::DiscardPartialBuffer(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall GJPEGInputImpl_jpeglib::DiscardPartialBuffer(CMatRenderContext *this)
{
  ITexture *result; // eax

  result = this->m_pCurrentFrameBufferCopyTexture[0];
  if ( result != nullptr )
  {
    result[1].__vftable = nullptr;
    result->__vftable = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FB920
// Name: public: virtual int GJPEGInputImpl_jpeglib::StartRawImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::StartRawImage(CMatRenderContext *this)
{
  if ( *((_BYTE *)this + 777) == 0 )
  {
    if ( _setjmp3(a1: *((_DWORD *)this + 193), a2: 0) != 0 )
    {
      jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)&this->m_iRefs);
      *((_WORD *)this + 388) = 256;
    }
    else
    {
      if ( this->m_pLocalCubemapTexture != (ITexture *)202 )
        jpeg_read_header(a1: (struct jpeg_decompress_struct *)&this->m_iRefs, a2: 1);
      *((_BYTE *)this + 776) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB990
// Name: public: virtual int GJPEGInputImpl_jpeglib::FinishImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::FinishImage(CMatRenderContext *this)
{
  if ( *((_BYTE *)this + 777) == 0 && *((_BYTE *)this + 776) != 0 )
  {
    if ( _setjmp3(a1: *((_DWORD *)this + 193), a2: 0) != 0 )
    {
      jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)&this->m_iRefs);
      *((_WORD *)this + 388) = 256;
    }
    else
    {
      jpeg_finish_decompress(a1: (struct jpeg_decompress_struct *)&this->m_iRefs);
      *((_BYTE *)this + 776) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBA00
// Name: public: virtual unsigned int GJPEGInputImpl_jpeglib::GetHeight(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GJPEGInputImpl_jpeglib::GetHeight(GJPEGInputImpl_jpeglib *this)
{
  return *((_DWORD *)this + 26);
}

//------------------------------------------------------------------------------
// Address: 0x100FBA10
// Name: public: virtual unsigned int GJPEGInputImpl_jpeglib::GetWidth(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GJPEGInputImpl_jpeglib::GetWidth(GJPEGInputImpl_jpeglib *this)
{
  return *((_DWORD *)this + 25);
}

//------------------------------------------------------------------------------
// Address: 0x100FBA20
// Name: public: virtual int GJPEGInputImpl_jpeglib::ReadScanline(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GJPEGInputImpl_jpeglib::ReadScanline(GJPEGInputImpl_jpeglib *this, unsigned __int8 *a2)
{
  if ( *((_BYTE *)this + 777) != 0 )
    return 0;
  if ( _setjmp3(a1: *((_DWORD *)this + 193), a2: 0) != 0 )
  {
    jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)((char *)this + 8));
    *((_WORD *)this + 388) = 256;
    return 0;
  }
  jpeg_read_scanlines(a1: (struct jpeg_decompress_struct *)((char *)this + 8), &a2, a3: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FBA90
// Name: public: virtual int GJPEGInputImpl_jpeglib::ReadRawData(void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GJPEGInputImpl_jpeglib::ReadRawData(
        CMatRenderContext *this@<ecx>,
        _DWORD *pprawData,
        const LightDesc_t *a3)
{
  if ( *((_BYTE *)this + 777) == 0 )
  {
    if ( _setjmp3(a1: *((_DWORD *)this + 193), a2: 0) != 0 )
    {
      jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)&this->m_iRefs);
      *((_WORD *)this + 388) = 256;
    }
    else
    {
      *pprawData = jpeg_read_coefficients(a1: (struct jpeg_decompress_struct *)&this->m_iRefs);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBB00
// Name: public: virtual void __near * GJPEGInputImpl_jpeglib::GetCInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::GetCInfo(CMatRenderContext *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100FBB70
// Name: public: virtual class GJPEGInput __near * GJPEGSystem_jpeglib::CreateSwfJpeg2HeaderOnly(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContext *__thiscall GJPEGSystem_jpeglib::CreateSwfJpeg2HeaderOnly(
        CMatRenderContext *this,
        unsigned int a2,
        unsigned int bufSize)
{
  CMatRenderContext *v3; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  v5 = 2;
  v3 = (CMatRenderContext *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                              this: GMemory::pGlobalHeap,
                              a2: this,
                              a3: 784,
                              a4: &v5);
  if ( v3 != nullptr )
    return GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(this: v3, e: 0, a3: a2, bufSize);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100FBBF0
// Name: public: GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(CMatRenderContext *this, IMaterial *pin)
{
  struct jpeg_error_mgr *v3; // eax
  int v4; // eax
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *v5; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContext_vtbl *)&GJPEGInputImpl_jpeglib::`vftable';
  v6 = 2;
  *((_DWORD *)this + 193) = GMemory::pGlobalHeap->Alloc(this: GMemory::pGlobalHeap, a2: 64, a3: 32, a4: &v6);
  *((_WORD *)this + 388) = 0;
  v3 = jpeg_std_error(a1: (struct jpeg_error_mgr *)&this->m_vecViewRight.z);
  LODWORD(this->m_vecViewRight.z) = JpegErrorExit;
  this->m_iRefs = (int)v3;
  GJPEGInputImpl_jpeglib::JpegCreateDecompress(
    pcinfo: (MaterialMatrixMode_t)&this->m_iRefs,
    pjerr: (matrix3x4_t *)&this->m_iRefs,
    a3: (int)&this->m_vecViewRight.z);
  if ( v4 != 0 )
  {
    v6 = 2;
    v5 = (CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2084, a3: &v6);
    if ( v5 != nullptr )
      this->m_pCurrentFrameBufferCopyTexture[0] = (ITexture *)GJPEGRwSource::GJPEGRwSource(
                                                                this: v5,
                                                                (IShaderDevice *)pin);
    else
      this->m_pCurrentFrameBufferCopyTexture[0] = nullptr;
    GJPEGInputImpl_jpeglib::StartImage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBCB0
// Name: public: GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(enum GJPEGInputImpl_jpeglib::SWF_DEFINE_BITS_JPEG2_HEADER_ONLY,class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(CMatRenderContext *this, bool e, IShaderDevice *pin)
{
  struct jpeg_error_mgr *v4; // eax
  MaterialMatrixMode_t v5; // ecx
  int v6; // eax
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *v7; // eax
  ITexture *v8; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContext_vtbl *)&GJPEGInputImpl_jpeglib::`vftable';
  v9 = 2;
  *((_DWORD *)this + 193) = GMemory::pGlobalHeap->Alloc(this: GMemory::pGlobalHeap, a2: 64, a3: 32, a4: &v9);
  *((_WORD *)this + 388) = 0;
  v4 = jpeg_std_error(a1: (struct jpeg_error_mgr *)&this->m_vecViewRight.z);
  LODWORD(this->m_vecViewRight.z) = JpegErrorExit;
  this->m_iRefs = (int)v4;
  GJPEGInputImpl_jpeglib::JpegCreateDecompress(
    pcinfo: v5,
    pjerr: (matrix3x4_t *)&this->m_iRefs,
    a3: (int)&this->m_vecViewRight.z);
  if ( v6 != 0 )
  {
    v9 = 2;
    v7 = (CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2084, a3: &v9);
    if ( v7 != nullptr )
      v8 = (ITexture *)GJPEGRwSource::GJPEGRwSource(this: v7, pin);
    else
      v8 = nullptr;
    this->m_pCurrentFrameBufferCopyTexture[0] = v8;
    GJPEGInputImpl_jpeglib::JpegReadHeader(
      a1: (struct jpeg_decompress_struct *)&this->m_iRefs,
      a2: (struct GFxJpegErrorHandler *)&this->m_vecViewRight.z,
      a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBD60
// Name: public: virtual class GJPEGInput __near * GJPEGSystem_jpeglib::CreateInput(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GJPEGSystem_jpeglib::CreateInput(CMatRenderContext *this@<ecx>, int pin, MaterialPrimitiveType_t a3)
{
  IMaterial *v3; // edi
  CMatRenderContext *v5; // eax

  v3 = (IMaterial *)pin;
  if ( pin != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)pin + 8))(a1: pin) != 0 )
  {
    pin = 2;
    v5 = (CMatRenderContext *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: this,
                                a3: 784,
                                a4: &pin);
    if ( v5 != nullptr )
      GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(this: v5, pin: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBDC0
// Name: public: virtual class GJPEGInput __near * GJPEGSystem_jpeglib::CreateSwfJpeg2HeaderOnly(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GJPEGSystem_jpeglib::CreateSwfJpeg2HeaderOnly(
        CMatRenderContext *this@<ecx>,
        int pin,
        MaterialPrimitiveType_t a3)
{
  IShaderDevice *v3; // esi
  CMatRenderContext *v5; // eax

  v3 = (IShaderDevice *)pin;
  if ( pin != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)pin + 8))(a1: pin) != 0 )
  {
    pin = 2;
    v5 = (CMatRenderContext *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: this,
                                a3: 784,
                                a4: &pin);
    if ( v5 != nullptr )
      GJPEGInputImpl_jpeglib::GJPEGInputImpl_jpeglib(this: v5, e: false, pin: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBE20
// Name: public: virtual GJPEGInputImpl_jpeglib::~GJPEGInputImpl_jpeglib(void)
// Source: json
//------------------------------------------------------------------------------
const CLoggingSystem::LoggingChannel_t *__thiscall GJPEGInputImpl_jpeglib::~GJPEGInputImpl_jpeglib(
        CMatRenderContext *this,
        const CLoggingSystem::LoggingChannel_t *a2)
{
  ITexture *v3; // edi
  IShaderAPI *v4; // ecx

  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContext_vtbl *)&GJPEGInputImpl_jpeglib::`vftable';
  GJPEGInputImpl_jpeglib::FinishImage(this);
  v3 = this->m_pCurrentFrameBufferCopyTexture[0];
  if ( v3 != nullptr )
  {
    v4 = (IShaderAPI *)v3[7].__vftable;
    if ( v4 != nullptr )
      GRefCountImpl::Release(this: v4);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  this->m_pCurrentFrameBufferCopyTexture[0] = nullptr;
  jpeg_destroy_compress(a1: (struct jpeg_compress_struct *)&this->m_iRefs);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 193));
  return GJPEGInput::~GJPEGInput(result: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100FBEB0
// Name: public: GJPEGOutputImpl_jpeglib::GJPEGOutputImpl_jpeglib(class GFile __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGOutputImpl_jpeglib::GJPEGOutputImpl_jpeglib(
        CMatRenderContext *this,
        IShaderDevice *out,
        ITexture *width,
        ITexture *height,
        int quality)
{
  int *p_m_iRefs; // edi

  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContext_vtbl *)&GJPEGOutputImpl_jpeglib::`vftable';
  p_m_iRefs = &this->m_iRefs;
  this->m_iRefs = (int)jpeg_std_error(a1: (struct jpeg_error_mgr *)&this->m_viewProjMatrix.m[2][1]);
  jpeg_CreateCompress(dst: (struct jpeg_compress_struct *)p_m_iRefs, a2: 62, a3: 0x168u);
  GJPEGUtil_SetupRwDest(cinfo: out, a2: (int)p_m_iRefs, a3: out);
  this->m_pCurrentFrameBufferCopyTexture[1] = width;
  this->m_pCurrentFrameBufferCopyTexture[2] = height;
  this->m_pCurrentFrameBufferCopyTexture[3] = (ITexture *)3;
  this->m_HeightClipMode = MATERIAL_HEIGHTCLIPMODE_RENDER_BELOW_HEIGHT;
  jpeg_set_defaults(a1: (struct jpeg_compress_struct *)p_m_iRefs);
  jpeg_set_quality(a1: (struct jpeg_compress_struct *)p_m_iRefs, a2: quality, a3: 1);
  jpeg_start_compress(a1: (struct jpeg_compress_struct *)p_m_iRefs, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100FBF30
// Name: public: virtual void GJPEGOutputImpl_jpeglib::WriteScanline(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGOutputImpl_jpeglib::WriteScanline(CMatRenderContext *this, IMorph *RgbData)
{
  jpeg_write_scanlines(a1: (struct jpeg_compress_struct *)&this->m_iRefs, a2: (unsigned __int8 **)&RgbData, a3: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x100FBF50
// Name: public: virtual void GJPEGOutputImpl_jpeglib::WriteRawData(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGOutputImpl_jpeglib::WriteRawData(CMatRenderContext *this, struct jvirt_barray_control **prawData)
{
  jpeg_write_coefficients(a1: (struct jpeg_compress_struct *)&this->m_iRefs, a2: prawData);
}

//------------------------------------------------------------------------------
// Address: 0x100FBF70
// Name: public: virtual void GJPEGOutputImpl_jpeglib::CopyCriticalParams(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGOutputImpl_jpeglib::CopyCriticalParams(
        GJPEGOutputImpl_jpeglib *this,
        struct jpeg_decompress_struct *a2)
{
  jpeg_copy_critical_parameters(a1: a2, a2: (struct jpeg_compress_struct *)((char *)this + 8));
}

//------------------------------------------------------------------------------
// Address: 0x100FBFE0
// Name: public: GJPEGOutputImpl_jpeglib::GJPEGOutputImpl_jpeglib(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
GJPEGOutputImpl_jpeglib *__thiscall GJPEGOutputImpl_jpeglib::GJPEGOutputImpl_jpeglib(GJPEGOutputImpl_jpeglib *this, IShaderDevice *cinfo)
{
  struct jpeg_compress_struct *v3; // edi

  *(_DWORD *)this = &GJPEGOutputImpl_jpeglib::`vftable';
  v3 = (struct jpeg_compress_struct *)((char *)this + 8);
  *((_DWORD *)this + 2) = jpeg_std_error(a1: (struct jpeg_error_mgr *)((char *)this + 368));
  jpeg_CreateCompress(dst: v3, a2: 62, a3: 0x168u);
  GJPEGUtil_SetupRwDest(cinfo, a2: (int)v3, a3: cinfo);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FC020
// Name: public: virtual class GJPEGOutput __near * GJPEGSystem_jpeglib::CreateOutput(class GFile __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGSystem_jpeglib::CreateOutput(const void *this, int result, int width, int height, int quality)
{
  IShaderDevice *v5; // edi
  CMatRenderContext *v7; // eax

  v5 = (IShaderDevice *)result;
  if ( result != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)result + 12))(a1: result) != 0 )
  {
    result = 2;
    v7 = (CMatRenderContext *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: this,
                                a3: 504,
                                a4: &result);
    if ( v7 != nullptr )
      GJPEGOutputImpl_jpeglib::GJPEGOutputImpl_jpeglib(
        this: v7,
        out: v5,
        (ITexture *)width,
        (ITexture *)height,
        quality);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC080
// Name: public: virtual class GJPEGOutput __near * GJPEGSystem_jpeglib::CreateOutput(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GJPEGSystem_jpeglib::CreateOutput(
        CMatRenderContext *this@<ecx>,
        int pout,
        int a3,
        const MorphWeight_t *a4)
{
  IShaderDevice *v4; // edi
  GJPEGOutputImpl_jpeglib *v6; // eax

  v4 = (IShaderDevice *)pout;
  if ( pout != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)pout + 12))(a1: pout) != 0 )
  {
    pout = 2;
    v6 = (GJPEGOutputImpl_jpeglib *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                      this: GMemory::pGlobalHeap,
                                      a2: this,
                                      a3: 504,
                                      a4: &pout);
    if ( v6 != nullptr )
      GJPEGOutputImpl_jpeglib::GJPEGOutputImpl_jpeglib(this: v6, cinfo: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC0E0
// Name: public: static class GJPEGSystem __near * GJPEGSystem::CreateDefaultSystem(void)
// Source: json
//------------------------------------------------------------------------------
const LightDesc_t *GJPEGSystem::CreateDefaultSystem()
{
  const LightDesc_t *v0; // eax
  int v1; // [esp+0h] [ebp-4h] BYREF

  v1 = 2;
  v0 = (const LightDesc_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 8, a3: &v1);
  if ( v0 == nullptr )
    return nullptr;
  v0->m_Type = (LightType_t)&GRefCountImplCore::`vftable';
  LODWORD(v0->m_Color.x) = 1;
  v0->m_Type = (LightType_t)&GJPEGSystem_jpeglib::`vftable';
  return v0;
}
