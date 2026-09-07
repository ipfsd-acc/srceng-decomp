// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxjpegsupport.cpp
// Functions: 6
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxjpegsupport.h"

//------------------------------------------------------------------------------
// Address: 0x10072470
// Name: public: virtual class GImage __near * GFxJpegSupport::ReadSwfJpeg2WithTables(class GJPEGInput __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
struct GImage *__thiscall GFxJpegSupport::ReadSwfJpeg2WithTables(
        GFxJpegSupport *this,
        struct GJPEGInput *a2,
        struct GMemoryHeap *a3)
{
  unsigned int v3; // eax
  GImage *Image; // edi
  int v5; // ebx
  unsigned int v7; // [esp-Ch] [ebp-10h]

  if ( a2 == nullptr || a2->IsErrorOccurred(this: a2) )
    return nullptr;
  a2->StartImage(this: a2);
  v7 = a2->GetHeight(this: a2);
  v3 = a2->GetWidth(this: a2);
  Image = GImage::CreateImage(result: (ICachedPerFrameMeshData *)2, width: v3, height: v7, a4: (int)a3);
  if ( Image != nullptr )
  {
    v5 = 0;
    if ( a2->GetHeight(this: a2) != 0 )
    {
      while ( a2->ReadScanline(this: a2, a2: &Image->pData[v5 * Image->Pitch]) != 0 )
      {
        if ( ++v5 >= a2->GetHeight(this: a2) )
          goto LABEL_7;
      }
      GRefCountNTSImpl::Release(this: Image);
      Image = nullptr;
    }
  }
LABEL_7:
  a2->FinishImage(this: a2);
  return Image;
}

//------------------------------------------------------------------------------
// Address: 0x10072530
// Name: public: virtual class GImage __near * GFxJpegSupport::ReadJpeg(class GFile __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
struct GJPEGSystem *__userpurge GFxJpegSupport::ReadJpeg@<eax>(
        GFxJpegSupport *this@<ecx>,
        int a2@<esi>,
        struct GFile *a3,
        struct GMemoryHeap *a4)
{
  struct GJPEGSystem *result; // eax

  result = this->pSystem.pObject;
  if ( result != nullptr )
    return (struct GJPEGSystem *)GImage::ReadJpeg(a1: a2, a2: a3, a3: result, a4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072550
// Name: public: virtual class GJPEGInput __near * GFxJpegSupport::CreateSwfJpeg2HeaderOnly(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
struct GJPEGInput *__thiscall GFxJpegSupport::CreateSwfJpeg2HeaderOnly(GFxJpegSupport *this, struct GFile *a2)
{
  GJPEGSystem *pObject; // ecx

  pObject = this->pSystem.pObject;
  if ( pObject != nullptr )
    return pObject->CreateSwfJpeg2HeaderOnly_2(this: pObject, a2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10072570
// Name: public: virtual class GImage __near * GFxJpegSupport::ReadSwfJpeg2(class GFile __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GJPEGInput *__thiscall GFxJpegSupport::ReadSwfJpeg2(GFxJpegSupport *this, struct GFile *a2, struct GMemoryHeap *a3)
{
  GJPEGInput *result; // eax
  GJPEGInput *v5; // edi
  GImage *v6; // esi

  result = this->CreateSwfJpeg2HeaderOnly(this, a2);
  v5 = result;
  if ( result != nullptr )
  {
    if ( result->IsErrorOccurred(this: result) )
    {
      ((void (__thiscall *)(GJPEGInput *, int))v5->dtr_GJPEGInput)(a1: v5, a2: 1);
      return nullptr;
    }
    else
    {
      v6 = this->ReadSwfJpeg2WithTables(this, a2: v5, a3);
      ((void (__thiscall *)(GJPEGInput *, int))v5->dtr_GJPEGInput)(a1: v5, a2: 1);
      return (GJPEGInput *)v6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100725E0
// Name: public: virtual class GImage __near * GFxJpegSupport::ReadSwfJpeg3(class GFile __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GJPEGInput *__userpurge GFxJpegSupport::ReadSwfJpeg3@<eax>(
        GFxJpegSupport *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        struct GFile *a4,
        struct GMemoryHeap *a5)
{
  GJPEGInput *result; // eax
  struct GImage *v6; // esi
  GImage *v7; // edi
  unsigned int v8; // eax
  GImage *Image; // eax
  GRefCountNTSImpl *v10; // edi
  unsigned int Width; // ebx
  _BYTE *v12; // eax
  _BYTE *v13; // ecx
  unsigned int i; // edi
  unsigned int v15; // [esp-8h] [ebp-14h]
  int v18; // [esp+4h] [ebp-8h] BYREF
  GImage *v19; // [esp+8h] [ebp-4h]
  struct GFile *v20; // [esp+14h] [ebp+8h]
  struct GMemoryHeap *v21; // [esp+18h] [ebp+Ch]

  result = this->CreateSwfJpeg2HeaderOnly(this, a2: a4);
  v6 = (struct GImage *)result;
  if ( result != nullptr )
  {
    v7 = nullptr;
    if ( ((unsigned __int8 (__thiscall *)(GJPEGInput *, int))result->IsErrorOccurred)(a1: result, a2: a3) == 0
      && ((int (__thiscall *)(struct GImage *))v6->__vftable[2].dtr_GRefCountImplCore)(a1: v6) != 0 )
    {
      v15 = ((int (__thiscall *)(struct GImage *))v6->__vftable[5].dtr_GRefCountImplCore)(a1: v6);
      v8 = ((int (__thiscall *)(struct GImage *))v6->__vftable[6].dtr_GRefCountImplCore)(a1: v6);
      Image = GImage::CreateImage(result: (ICachedPerFrameMeshData *)1, width: v8, height: v15, a4: (int)a5);
      v10 = Image;
      v19 = Image;
      if ( Image != nullptr )
      {
        Width = Image->Width;
        v18 = 2;
        v21 = (struct GMemoryHeap *)((int (__thiscall *)(GMemoryHeap *, unsigned int, int *, int))GMemory::pGlobalHeap->Alloc_2)(
                                      a1: GMemory::pGlobalHeap,
                                      a2: 3 * Width,
                                      a3: &v18,
                                      a4: a2);
        v20 = nullptr;
        if ( ((int (__thiscall *)(struct GImage *))v6->__vftable[5].dtr_GRefCountImplCore)(a1: v6) != 0 )
        {
          while ( ((int (__thiscall *)(struct GImage *, struct GMemoryHeap *))v6->__vftable[7].dtr_GRefCountImplCore)(
                    a1: v6,
                    a2: v21) != 0 )
          {
            if ( Width != 0 )
            {
              v12 = (char *)&v10[3].dtr_GRefCountImplCore + (_DWORD)v20 * v10[2].RefCount + 2;
              v13 = (char *)&v21->__vftable + 2;
              for ( i = Width; i != 0; --i )
              {
                *(v12 - 2) = *(v13 - 2);
                *(v12 - 1) = *(v13 - 1);
                *v12 = *v13;
                v12[1] = -1;
                v13 += 3;
                v12 += 4;
              }
              v10 = v19;
            }
            v20 = (struct GFile *)((char *)v20 + 1);
            if ( (unsigned int)v20 >= ((int (__thiscall *)(struct GImage *))v6->__vftable[5].dtr_GRefCountImplCore)(a1: v6) )
              goto LABEL_14;
          }
          GRefCountNTSImpl::Release(this: v10);
          v19 = nullptr;
        }
LABEL_14:
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
      }
      v6->__vftable[4].dtr_GRefCountImplCore(this: v6);
      v7 = v19;
    }
    ((void (__thiscall *)(struct GImage *, int))v6->dtr_GRefCountImplCore)(a1: v6, a2: 1);
    return (GJPEGInput *)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072730
// Name: public: GFxJpegSupport::GFxJpegSupport(void)
// Source: json
//------------------------------------------------------------------------------
GFxJpegSupport *__thiscall GFxJpegSupport::GFxJpegSupport(GFxJpegSupport *this)
{
  const LightDesc_t *DefaultSystem; // eax
  IShaderAPI *pObject; // ecx
  GJPEGSystem *v4; // edi
  const LightDesc_t *v6; // [esp+0h] [ebp-8h]

  this->__vftable = (GFxJpegSupport_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_JpegSupport;
  this->__vftable = (GFxJpegSupport_vtbl *)&GFxJpegSupport::`vftable';
  this->pSystem.pObject = nullptr;
  DefaultSystem = GJPEGSystem::CreateDefaultSystem(result: v6);
  pObject = (IShaderAPI *)this->pSystem.pObject;
  v4 = (GJPEGSystem *)DefaultSystem;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->pSystem.pObject = v4;
  return this;
}
