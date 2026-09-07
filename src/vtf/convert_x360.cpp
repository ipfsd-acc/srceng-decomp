// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vtf/convert_x360.cpp
// Functions: 14
// ============================================================

#include "vtf\convert_x360.h"

//------------------------------------------------------------------------------
// Address: 0x00533F60
// Name: bool ComputeTargetDimensions(char const __near *,class IVTFTexture __near *,int,int __near &,int __near &,int __near &,int __near &,bool __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ComputeTargetDimensions(
        const char *pDebugName,
        IVTFTexture *pVTFTexture,
        int picmip,
        int *width,
        int *height,
        int *mipCount,
        int *mipSkipCount,
        bool *bNoMip,
        bool bAllow1024Texture)
{
  char *v12; // eax
  char v13; // cl
  char v14; // cl
  char v15; // cl
  char v16; // al
  int *v17; // edx
  int nClampX; // [esp+18h] [ebp+Ch]
  int nClampY; // [esp+20h] [ebp+14h]
  ImageFormat format; // [esp+24h] [ebp+18h]

  *width = pVTFTexture->Width(this: pVTFTexture);
  *height = pVTFTexture->Height(this: pVTFTexture);
  format = pVTFTexture->Format(this: pVTFTexture);
  nClampX = 0x40000000;
  nClampY = 0x40000000;
  v12 = (char *)pVTFTexture->GetResourceData(this: pVTFTexture, a2: 4476748, a3: 0);
  if ( v12 != nullptr )
  {
    v13 = *v12;
    if ( *v12 != 0 && 1 << v13 <= 0x40000000 )
      nClampX = 1 << v13;
    v14 = v12[1];
    if ( v14 != 0 && 1 << v14 <= 0x40000000 )
      nClampY = 1 << v14;
    if ( !bAllow1024Texture )
    {
      v15 = v12[2];
      if ( v15 != 0 && nClampX >= 1 << v15 )
        nClampX = 1 << v15;
      v16 = v12[3];
      if ( v16 != 0 && nClampY >= 1 << v16 )
        nClampY = 1 << v16;
    }
  }
  v17 = mipSkipCount;
  *mipSkipCount = 0;
  while ( *v17 < picmip || *width > nClampX )
  {
LABEL_24:
    if ( *width == 1 && *height == 1 )
      goto LABEL_31;
    *width >>= 1;
    *height >>= 1;
    if ( *width < 1 )
      *width = 1;
    if ( *height < 1 )
      *height = 1;
    ++*v17;
  }
  if ( *height > nClampY
    || ImageLoader::GetMemRequired(
         width: *width,
         height: *height,
         depth: 1,
         imageFormat: format,
         mipmap: false,
         pAdjustedHeight: nullptr) > 0x100000
    || (pVTFTexture->Flags(this: pVTFTexture) & 0x100) == 0
    && !bAllow1024Texture
    && ImageLoader::GetMemRequired(
         width: *width,
         height: *height,
         depth: 1,
         imageFormat: format,
         mipmap: false,
         pAdjustedHeight: nullptr) > 0x40000 )
  {
    v17 = mipSkipCount;
    goto LABEL_24;
  }
LABEL_31:
  *bNoMip = false;
  if ( (pVTFTexture->Flags(this: pVTFTexture) & 0x100) != 0 )
  {
    *bNoMip = true;
    *mipCount = 1;
    return 1;
  }
  else
  {
    if ( *bNoMip )
      *mipCount = 1;
    else
      *mipCount = ImageLoader::GetNumMipMapLevels(width: *width, height: *height, depth: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00534120
// Name: Ps3Helper_LinearToSwizzleAddress
// Source: json
//------------------------------------------------------------------------------
int __usercall Ps3Helper_LinearToSwizzleAddress@<eax>(unsigned __int16 *c@<ecx>, unsigned __int16 *size@<esi>)
{
  int v2; // edi
  int v3; // edx

  v2 = 0;
  v3 = 1;
  do
  {
    *size >>= 1;
    if ( *size != 0 )
    {
      v2 += (*c & 1) != 0 ? v3 : 0;
      v3 *= 2;
      *c >>= 1;
    }
    size[1] >>= 1;
    if ( size[1] != 0 )
    {
      v2 += (c[1] & 1) != 0 ? v3 : 0;
      v3 *= 2;
      c[1] >>= 1;
    }
    size[2] >>= 1;
    if ( size[2] != 0 )
    {
      v2 += (c[2] & 1) != 0 ? v3 : 0;
      v3 *= 2;
      c[2] >>= 1;
    }
  }
  while ( *c + c[1] + c[2] != 0 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005341C0
// Name: void PostConvertSwizzleImageData(unsigned char __near *,int,enum ImageFormat,int,int,enum VtfConsoleFormatType_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall PostConvertSwizzleImageData(
        int a1@<ebx>,
        unsigned __int8 *pTargetImage,
        unsigned int targetImageSize,
        ImageFormat targetFormat,
        int width,
        int height,
        VtfConsoleFormatType_t targetConsole)
{
  int v7; // esi
  int v8; // edi
  unsigned int MemRequired; // eax
  unsigned int v10; // ebx
  int v11; // eax
  unsigned __int16 v12; // di
  int v13; // eax
  unsigned __int8 *v14; // [esp-10h] [ebp-30h]
  unsigned __int16 c[4]; // [esp+0h] [ebp-20h] BYREF
  unsigned __int16 sizeArg[4]; // [esp+8h] [ebp-18h] BYREF
  unsigned __int8 *src; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  unsigned __int8 *pSwizzleData; // [esp+18h] [ebp-8h]
  int x; // [esp+1Ch] [ebp-4h]
  unsigned __int16 y; // [esp+3Ch] [ebp+1Ch]

  if ( targetConsole == VTF_CONSOLE_PS3 )
  {
    v7 = width;
    if ( ((width - 1) & width) == 0 )
    {
      v8 = height;
      if ( ((height - 1) & height) == 0 && (targetFormat < IMAGE_FORMAT_DXT1 || targetFormat > IMAGE_FORMAT_DXT5) )
      {
        MemRequired = ImageLoader::GetMemRequired(
                        width: 1,
                        height: 1,
                        depth: 1,
                        imageFormat: targetFormat,
                        mipmap: false,
                        pAdjustedHeight: nullptr);
        v10 = MemRequired;
        if ( MemRequired > 4 )
        {
          width *= MemRequired >> 2;
          v7 *= MemRequired >> 2;
          v10 = 4;
        }
        pSwizzleData = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, unsigned int, int))_g_pMemAlloc->Alloc_2)(
                                            a1: _g_pMemAlloc,
                                            a2: targetImageSize,
                                            a3: a1);
        v11 = 0;
        x = 0;
        if ( v7 > 0 )
        {
          v19 = 0;
          while ( 1 )
          {
            y = 0;
            if ( v8 > 0 )
            {
              do
              {
                v12 = 0;
                src = &pTargetImage[v10 * (v19 + v7 * v11)];
                do
                {
                  c[1] = y;
                  c[0] = x;
                  sizeArg[0] = v7;
                  sizeArg[1] = height;
                  v14 = src;
                  c[2] = v12;
                  sizeArg[2] = 1;
                  v13 = Ps3Helper_LinearToSwizzleAddress(c, size: sizeArg);
                  memcpy(dst: &pSwizzleData[v10 * v13], src: v14, count: v10);
                  v7 = width;
                  ++v12;
                }
                while ( v12 == 0 );
                v11 = ++y;
              }
              while ( y < height );
              v8 = height;
            }
            v19 = (unsigned __int16)++x;
            if ( (unsigned __int16)x >= v7 )
              break;
            v11 = 0;
          }
        }
        memcpy(dst: pTargetImage, src: pSwizzleData, count: targetImageSize);
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pSwizzleData);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00534320
// Name: bool ConvertImageFormatEx(unsigned char __near *,int,enum ImageFormat,unsigned char __near *,int,enum ImageFormat,int,int,enum VtfConsoleFormatType_t)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConvertImageFormatEx(
        unsigned __int8 *pSourceImage,
        CBaseAppSystem<IDmSerializers> *sourceImageSize,
        ImageFormat sourceFormat,
        unsigned __int8 *pTargetImage,
        int targetImageSize,
        ImageFormat targetFormat,
        int width,
        int height,
        VtfConsoleFormatType_t targetConsole)
{
  bool result; // al

  CSteamApplication::PostShutdown(this: sourceImageSize);
  result = ImageLoader::ConvertImageFormat(
             src: pSourceImage,
             srcImageFormat: sourceFormat,
             dst: pTargetImage,
             dstImageFormat: targetFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    ImageLoader::PostConvertSwapImageData(
      pImageData: pTargetImage,
      nImageSize: targetImageSize,
      imageFormat: targetFormat,
      targetConsole,
      width: 0,
      stride: 0);
    PostConvertSwizzleImageData(
      a1: (int)pTargetImage,
      pTargetImage,
      targetImageSize,
      targetFormat,
      width,
      height,
      targetConsole);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005343A0
// Name: public: struct VTFFileHeaderX360_t __near & VTFFileHeaderX360_t::operator=(struct VTFFileHeaderX360_t const __near &)
// Source: json
//------------------------------------------------------------------------------
VTFFileHeaderX360_t *__thiscall VTFFileHeaderX360_t::operator=(
        VTFFileHeaderX360_t *this,
        const VTFFileHeaderX360_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00534440
// Name: public: struct VTFFileHeaderPS3_t __near & VTFFileHeaderPS3_t::operator=(struct VTFFileHeaderPS3_t const __near &)
// Source: json
//------------------------------------------------------------------------------
VTFFileHeaderPS3_t *__thiscall VTFFileHeaderPS3_t::operator=(
        VTFFileHeaderPS3_t *this,
        const VTFFileHeaderPS3_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00534500
// Name: int AlignBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AlignBuffer(CUtlBuffer *buf, int alignment)
{
  int m_Put; // ebx
  int v3; // esi
  int v4; // ebx
  unsigned __int8 padByte; // [esp+Fh] [ebp-1h] BYREF

  padByte = 0;
  CUtlBuffer::SeekPut(this: buf, type: SEEK_TAIL, offset: 0);
  m_Put = buf->m_Put;
  v3 = ~(alignment - 1) & (m_Put + alignment - 1);
  CUtlBuffer::EnsureCapacity(this: buf, num: v3);
  if ( v3 - m_Put > 0 )
  {
    v4 = v3 - m_Put;
    do
    {
      CUtlBuffer::Put(this: buf, pMem: &padByte, size: 1);
      --v4;
    }
    while ( v4 != 0 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00534680
// Name: bool SerializeImageData(class IVTFTexture __near *,int,int,int,enum ImageFormat,class CUtlBuffer __near &,enum VtfConsoleFormatType_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SerializeImageData(
        IVTFTexture *pSourceVTF,
        int frame,
        int face,
        int mip,
        ImageFormat targetFormat,
        CUtlBuffer *targetBuf,
        VtfConsoleFormatType_t targetConsole)
{
  int v8; // edi
  int v9; // ebx
  ImageFormat v10; // eax
  signed int MemRequired; // eax
  ImageFormat v12; // eax
  unsigned __int8 *targetImage; // [esp+Ch] [ebp-10h]
  unsigned __int8 *pSourceImage; // [esp+18h] [ebp-4h]
  CBaseAppSystem<IDmSerializers> *sourceImageSize; // [esp+24h] [ebp+8h]
  int targetImageSize; // [esp+30h] [ebp+14h]

  targetImage = nullptr;
  v8 = pSourceVTF->Width(this: pSourceVTF) >> mip;
  v9 = pSourceVTF->Height(this: pSourceVTF) >> mip;
  if ( v8 < 1 )
    v8 = 1;
  if ( v9 < 1 )
    v9 = 1;
  v10 = pSourceVTF->Format(this: pSourceVTF);
  sourceImageSize = (CBaseAppSystem<IDmSerializers> *)ImageLoader::GetMemRequired(
                                                        width: v8,
                                                        height: v9,
                                                        depth: 1,
                                                        imageFormat: v10,
                                                        mipmap: false,
                                                        pAdjustedHeight: nullptr);
  pSourceImage = pSourceVTF->ImageData_2(this: pSourceVTF, a2: frame, a3: face, a4: mip);
  MemRequired = ImageLoader::GetMemRequired(
                  width: v8,
                  height: v9,
                  depth: 1,
                  imageFormat: targetFormat,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  targetImageSize = MemRequired;
  if ( MemRequired > 0 )
  {
    targetImage = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    MemRequired = targetImageSize;
  }
  memset(dst: targetImage, value: 0xFFu, count: MemRequired);
  v12 = pSourceVTF->Format(this: pSourceVTF);
  if ( ConvertImageFormatEx(
         pSourceImage,
         sourceImageSize,
         sourceFormat: v12,
         pTargetImage: targetImage,
         targetImageSize,
         targetFormat,
         width: v8,
         height: v9,
         targetConsole) )
  {
    CUtlBuffer::EnsureCapacity(this: targetBuf, num: targetImageSize + targetBuf->m_Memory.m_nAllocationCount);
    CUtlBuffer::Put(this: targetBuf, pMem: targetImage, size: targetImageSize);
    if ( targetBuf->m_Error != 0 )
    {
      if ( targetImage != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetImage);
      return 0;
    }
    else
    {
      if ( targetImage != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetImage);
      return 1;
    }
  }
  else
  {
    if ( targetImage != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetImage);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005347F0
// Name: bool GetVTFPreload360Data(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetVTFPreload360Data(const char *pDebugName, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  VTFFileHeaderX360_t header; // [esp+Ch] [ebp-3Ch] BYREF

  preloadBufferOut->m_Get = 0;
  preloadBufferOut->m_Put = 0;
  preloadBufferOut->m_nOffset = 0;
  preloadBufferOut->m_nMaxPut = 0;
  preloadBufferOut->m_Error = 0;
  if ( preloadBufferOut->m_Memory.m_nGrowSize >= 0 )
  {
    if ( preloadBufferOut->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: preloadBufferOut->m_Memory.m_pMemory);
      preloadBufferOut->m_Memory.m_pMemory = nullptr;
    }
    preloadBufferOut->m_Memory.m_nAllocationCount = 0;
  }
  CUtlBuffer::ActivateByteSwapping(this: fileBufferIn, bActivate: true);
  CUtlBuffer::GetObjects<VTFFileHeaderX360_t>(this: fileBufferIn, dest: &header, count: (VTFFileHeaderX360_t *)1);
  if ( V_strnicmp(s1: header.fileTypeString, s2: "VTFX", n: 4) != 0
    || header.version[0] != 864
    || header.version[1] != 8 )
  {
    return 0;
  }
  CUtlBuffer::EnsureCapacity(this: preloadBufferOut, num: header.preloadDataSize);
  CUtlBuffer::Put(this: preloadBufferOut, pMem: fileBufferIn->m_Memory.m_pMemory, size: header.preloadDataSize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005348A0
// Name: bool GetVTFPreloadPS3Data(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall GetVTFPreloadPS3Data@<al>(
        int a1@<ebp>,
        const char *pDebugName,
        CUtlBuffer *fileBufferIn,
        CUtlBuffer *preloadBufferOut)
{
  _DWORD v5[3]; // [esp-Ch] [ebp-4Ch] BYREF
  VTFFileHeaderPS3_t header; // [esp+0h] [ebp-40h]
  unsigned int retaddr; // [esp+40h] [ebp+0h]

  *(_DWORD *)header.lowResImageSample = a1;
  header.compressedSize = retaddr;
  preloadBufferOut->m_Get = 0;
  preloadBufferOut->m_Put = 0;
  preloadBufferOut->m_nOffset = 0;
  preloadBufferOut->m_nMaxPut = 0;
  preloadBufferOut->m_Error = 0;
  if ( preloadBufferOut->m_Memory.m_nGrowSize >= 0 )
  {
    if ( preloadBufferOut->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: preloadBufferOut->m_Memory.m_pMemory);
      preloadBufferOut->m_Memory.m_pMemory = nullptr;
    }
    preloadBufferOut->m_Memory.m_nAllocationCount = 0;
  }
  CUtlBuffer::ActivateByteSwapping(this: fileBufferIn, bActivate: true);
  CUtlBuffer::GetObjects<VTFFileHeaderPS3_t>(
    this: fileBufferIn,
    dest: (VTFFileHeaderPS3_t *)v5,
    count: (VTFFileHeaderPS3_t *)1);
  if ( V_strnicmp(s1: (const char *)v5, s2: "VTF3", n: 4) != 0 || v5[1] != 819 || v5[2] != 8 )
    return 0;
  CUtlBuffer::EnsureCapacity(this: preloadBufferOut, num: LOWORD(header.flags));
  CUtlBuffer::Put(this: preloadBufferOut, pMem: fileBufferIn->m_Memory.m_pMemory, size: LOWORD(header.flags));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00534A00
// Name: bool ConvertVTFToConsoleFormatHelper<0>(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &,bool (*)(class CUtlBuffer __near &,class CUtlBuffer __near &),bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall ConvertVTFToConsoleFormatHelper<0>@<al>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *pDebugName,
        CUtlBuffer *sourceBuf,
        CUtlBuffer *targetBuf,
        bool (__cdecl *pCompressFunc)(CUtlBuffer *, CUtlBuffer *),
        bool bAllow1024Texture)
{
  CVTFTexture *VTFTexture; // esi
  ImageFormat v9; // eax
  int v10; // ebx
  char *v11; // eax
  char *v12; // eax
  bool v13; // zf
  unsigned __int8 *v14; // edi
  int m_Size; // ebx
  int v16; // edi
  ImageFormat v17; // eax
  int v18; // edi
  ImageFormat (__thiscall *LowResFormat)(struct CVTFTexture *); // eax
  int v20; // eax
  CVTFTexture_vtbl *v21; // edx
  int v22; // eax
  int v23; // ebx
  ImageFormat (__thiscall *v24)(struct CVTFTexture *); // eax
  int v25; // eax
  int MemRequired; // ebx
  unsigned __int8 *v27; // eax
  int v28; // eax
  unsigned __int8 *v29; // ebx
  double v30; // st7
  int v31; // edx
  double v32; // st7
  int v33; // eax
  double v34; // st7
  float v35; // xmm0_4
  double v36; // st7
  ResourceEntryInfo *p_m_EntryInfo; // ebx
  int resData; // eax
  int m_Put; // ebx
  int v40; // ebx
  int v41; // ebx
  unsigned int *p_resData; // ebx
  char v43; // dl
  char v44; // al
  char v45; // cl
  char v46; // dl
  int v47; // ebx
  unsigned __int8 *v48; // ebx
  int v49; // edi
  ResourceCopy_t *v50; // ebx
  ResourceCopy_t *v51; // esi
  CBaseAppSystem<IDmSerializers> *v53; // [esp+18h] [ebp-1C4h]
  ImageFormat v54; // [esp+1Ch] [ebp-1C0h]
  unsigned __int8 *m_pMemory; // [esp+20h] [ebp-1BCh]
  int v56; // [esp+24h] [ebp-1B8h]
  ImageFormat v57; // [esp+2Ch] [ebp-1B0h]
  int v58; // [esp+2Ch] [ebp-1B0h]
  int v60; // [esp+30h] [ebp-1ACh]
  unsigned int resourceTypes[32]; // [esp+38h] [ebp-1A4h] BYREF
  CUtlBuffer headerBuffer; // [esp+B8h] [ebp-124h] BYREF
  CUtlBuffer compressedBuffer; // [esp+E8h] [ebp-F4h] BYREF
  VTFFileHeaderX360_t targetHeader; // [esp+118h] [ebp-C4h] BYREF
  int targetWidth; // [esp+154h] [ebp-88h] BYREF
  int targetMipCount; // [esp+158h] [ebp-84h] BYREF
  int targetHeight; // [esp+15Ch] [ebp-80h] BYREF
  int v68; // [esp+160h] [ebp-7Ch]
  ResourceCopy_t resourceCopy; // [esp+164h] [ebp-78h] BYREF
  int swappedLength; // [esp+174h] [ebp-68h] BYREF
  CUtlMemory<unsigned char,int> targetLowResImage; // [esp+178h] [ebp-64h] BYREF
  int targetFaceCount; // [esp+184h] [ebp-58h]
  CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int> > targetResources; // [esp+188h] [ebp-54h] BYREF
  int mipSkipCount; // [esp+19Ch] [ebp-40h] BYREF
  int targetFrameCount; // [esp+1A0h] [ebp-3Ch]
  Vector linearColor; // [esp+1A4h] [ebp-38h] BYREF
  ImageFormat targetFormat; // [esp+1B0h] [ebp-2Ch]
  CByteswap byteSwapWriter; // [esp+1B4h] [ebp-28h] BYREF
  bool bNoMip; // [esp+1BBh] [ebp-21h] BYREF
  int v80; // [esp+1BCh] [ebp-20h]
  int numTypes; // [esp+1C0h] [ebp-1Ch]
  int frame; // [esp+1C4h] [ebp-18h] BYREF
  int i; // [esp+1C8h] [ebp-14h] BYREF
  int resourceDataLength; // [esp+1CCh] [ebp-10h] BYREF
  unsigned __int8 targetLowResSample[4]; // [esp+1D0h] [ebp-Ch]
  int targetLowResWidth; // [esp+1D4h] [ebp-8h]
  bool bRetVal; // [esp+1DBh] [ebp-1h]

  memset(&targetResources, 0, sizeof(targetResources));
  byteSwapWriter = (CByteswap)(*(_DWORD *)&byteSwapWriter & 0xFFFFFFFC | 3);
  MathLib_Init(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
  bRetVal = false;
  VTFTexture = CreateVTFTexture();
  if ( ((unsigned __int8 (__thiscall *)(CVTFTexture *, CUtlBuffer *, int, _DWORD, int, int, int))VTFTexture->Unserialize)(
         a1: VTFTexture,
         a2: sourceBuf,
         a3: 1,
         a4: 0,
         a5: a2,
         a6: a3,
         a7: a1) != 0
    && VTFTexture->Depth(this: VTFTexture) == 1 )
  {
    v9 = VTFTexture->Format(this: VTFTexture);
    if ( ImageLoader::IsFormatValidForConversion(fmt: v9)
      && ComputeTargetDimensions(
           pDebugName,
           pVTFTexture: VTFTexture,
           picmip: 0,
           width: &targetWidth,
           height: &targetHeight,
           mipCount: &targetMipCount,
           &mipSkipCount,
           &bNoMip,
           bAllow1024Texture) != 0
      && mipSkipCount < sourceBuf->m_Memory.m_pMemory[56] )
    {
      CUtlBuffer::SeekGet(this: sourceBuf, type: SEEK_HEAD, offset: 0);
      if ( !VTFTexture->Unserialize(this: VTFTexture, a2: sourceBuf, a3: false, a4: mipSkipCount) )
      {
        _Msg(a1: "ConvertVTFToConsoleFormatHelper: Error reading in %s\n", pDebugName);
        goto cleanUp_0;
      }
      v10 = 0;
      resourceCopy.m_EntryInfo.eType = 48;
      resourceCopy.m_EntryInfo.resData = 0;
      resourceCopy.m_pData = nullptr;
      resourceCopy.m_DataLength = 0;
      CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int>>::InsertBefore(
        this: &targetResources,
        elem: 0,
        src: &resourceCopy);
      numTypes = VTFTexture->GetResourceTypes(this: VTFTexture, a2: resourceTypes, a3: 32);
      if ( numTypes > 0 )
      {
        do
        {
          v11 = (char *)(resourceTypes[v10] & 0xFFFFFF);
          if ( (unsigned int)v11 > 0x305354 )
          {
            if ( v11 != (char *)&loc_435243 )
            {
              v13 = v11 == (_BYTE *)&loc_444F49 + 3;
              goto LABEL_15;
            }
          }
          else if ( v11 != (char *)3167060 )
          {
            v12 = v11 - 1;
            if ( v12 != nullptr )
            {
              v13 = v12 == (char *)47;
LABEL_15:
              if ( !v13 )
              {
                v14 = (unsigned __int8 *)VTFTexture->GetResourceData(
                                           this: VTFTexture,
                                           a2: resourceTypes[v10],
                                           a3: (unsigned int *)&i);
                if ( v14 != nullptr )
                {
                  resourceCopy.m_EntryInfo.eType = resourceTypes[v10] & 0xFFFFFF;
                  resourceCopy.m_EntryInfo.resData = 0;
                  resourceCopy.m_pData = MemAlloc_Alloc(nSize: i);
                  resourceCopy.m_DataLength = i;
                  _V_memcpy(dest: (unsigned __int8 *)resourceCopy.m_pData, src: v14, count: i);
                  CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int>>::InsertBefore(
                    this: &targetResources,
                    elem: targetResources.m_Size,
                    src: &resourceCopy);
                }
              }
            }
          }
          ++v10;
        }
        while ( v10 < numTypes );
      }
      m_Size = targetResources.m_Size;
      if ( targetResources.m_Size > 4 )
      {
        _Msg(a1: "ConvertVTFToConsoleFormatHelper: More resources than expected in %s\n", pDebugName);
        goto cleanUp_0;
      }
      v16 = VTFTexture->Flags(this: VTFTexture);
      targetFrameCount = VTFTexture->FrameCount(this: VTFTexture);
      targetFaceCount = VTFTexture->FaceCount(this: VTFTexture);
      v17 = VTFTexture->Format(this: VTFTexture);
      switch ( v17 )
      {
        case IMAGE_FORMAT_RGBA8888:
        case IMAGE_FORMAT_ABGR8888:
        case IMAGE_FORMAT_ARGB8888:
        case IMAGE_FORMAT_BGRA8888:
          targetFormat = IMAGE_FORMAT_BGRA8888;
          break;
        case IMAGE_FORMAT_RGB888:
        case IMAGE_FORMAT_BGR888:
        case IMAGE_FORMAT_RGB888_BLUESCREEN:
        case IMAGE_FORMAT_BGR888_BLUESCREEN:
        case IMAGE_FORMAT_BGRX8888:
          targetFormat = IMAGE_FORMAT_BGRX8888;
          break;
        case IMAGE_FORMAT_RGB565:
        case IMAGE_FORMAT_BGR565:
        case IMAGE_FORMAT_BGRX5551:
          targetFormat = IMAGE_FORMAT_BGR565;
          break;
        case IMAGE_FORMAT_RGBA16161616F:
        case IMAGE_FORMAT_RGBA16161616:
          targetFormat = IMAGE_FORMAT_RGBA16161616;
          break;
        default:
          targetFormat = v17;
          break;
      }
      if ( bNoMip )
        v18 = v16 | 0x100;
      else
        v18 = v16 & 0xFFFFFEFF;
      LowResFormat = VTFTexture->LowResFormat;
      numTypes = v18;
      if ( LowResFormat(this: VTFTexture) != IMAGE_FORMAT_UNKNOWN
        && VTFTexture->LowResWidth(this: VTFTexture) != 0
        && VTFTexture->LowResHeight(this: VTFTexture) != 0 )
      {
        v20 = VTFTexture->LowResWidth(this: VTFTexture);
        v21 = VTFTexture->__vftable;
        targetLowResWidth = v20;
        v22 = v21->LowResHeight(this: VTFTexture);
      }
      else
      {
        v22 = 0;
        targetLowResWidth = 0;
      }
      v23 = 8 * m_Size + 60;
      *(_DWORD *)targetLowResSample = v22;
      v68 = v23;
      CUtlBuffer::EnsureCapacity(this: targetBuf, num: v23);
      CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_CURRENT, offset: v23);
      if ( targetLowResWidth != 0 && *(_DWORD *)targetLowResSample != 0 )
      {
        v24 = VTFTexture->LowResFormat;
        memset(&targetLowResImage, 0, sizeof(targetLowResImage));
        v57 = v24(this: VTFTexture);
        v56 = VTFTexture->LowResHeight(this: VTFTexture);
        v25 = VTFTexture->LowResWidth(this: VTFTexture);
        resourceDataLength = ImageLoader::GetMemRequired(
                               width: v25,
                               height: v56,
                               depth: 1,
                               imageFormat: v57,
                               mipmap: false,
                               pAdjustedHeight: nullptr);
        MemRequired = ImageLoader::GetMemRequired(
                        width: targetLowResWidth,
                        height: *(int *)targetLowResSample,
                        depth: 1,
                        imageFormat: IMAGE_FORMAT_RGB888,
                        mipmap: false,
                        pAdjustedHeight: nullptr);
        CUtlMemory<unsigned char,int>::EnsureCapacity(this: &targetLowResImage, num: MemRequired);
        memset(dst: targetLowResImage.m_pMemory, value: 0xFFu, count: MemRequired);
        v60 = *(_DWORD *)targetLowResSample;
        v58 = targetLowResWidth;
        m_pMemory = targetLowResImage.m_pMemory;
        v54 = VTFTexture->LowResFormat(this: VTFTexture);
        v53 = (CBaseAppSystem<IDmSerializers> *)resourceDataLength;
        v27 = VTFTexture->LowResImageData(this: VTFTexture);
        bRetVal = ConvertImageFormatEx(
                    pSourceImage: v27,
                    sourceImageSize: v53,
                    sourceFormat: v54,
                    pTargetImage: m_pMemory,
                    targetImageSize: MemRequired,
                    targetFormat: IMAGE_FORMAT_RGB888,
                    width: v58,
                    height: v60,
                    targetConsole: VTF_CONSOLE_360);
        if ( !bRetVal )
        {
          CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: (CUtlBuffer *)&targetLowResImage);
          goto cleanUp_0;
        }
        v28 = targetLowResWidth * *(_DWORD *)targetLowResSample;
        memset(&linearColor, 0, sizeof(linearColor));
        resourceDataLength = targetLowResWidth * *(_DWORD *)targetLowResSample;
        if ( targetLowResWidth * *(_DWORD *)targetLowResSample > 0 )
        {
          v29 = targetLowResImage.m_pMemory + 2;
          i = targetLowResWidth * *(_DWORD *)targetLowResSample;
          do
          {
            v30 = SrgbGammaToLinear(flSrgbGammaValue: (float)*(v29 - 2) * 0.0039215689);
            v31 = *(v29 - 1);
            linearColor.x = v30 + linearColor.x;
            v32 = SrgbGammaToLinear(flSrgbGammaValue: (float)v31 * 0.0039215689);
            v33 = *v29;
            linearColor.y = v32 + linearColor.y;
            v34 = SrgbGammaToLinear(flSrgbGammaValue: (float)v33 * 0.0039215689);
            v29 += 3;
            v13 = i-- == 1;
            linearColor.z = v34 + linearColor.z;
          }
          while ( !v13 );
          v28 = resourceDataLength;
        }
        v35 = 1.0 / (float)v28;
        linearColor.y = v35 * linearColor.y;
        linearColor.z = v35 * linearColor.z;
        resourceDataLength = (int)(SrgbLinearToGamma(flLinearValue: v35 * linearColor.x) * 255.0);
        targetLowResSample[0] = resourceDataLength;
        v80 = (int)(SrgbLinearToGamma(flLinearValue: linearColor.y) * 255.0);
        targetLowResSample[1] = v80;
        v36 = SrgbLinearToGamma(flLinearValue: linearColor.z);
        targetLowResSample[3] = -1;
        v80 = (int)(v36 * 255.0);
        targetLowResSample[2] = v80;
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: (CUtlBuffer *)&targetLowResImage);
      }
      else
      {
        *(_DWORD *)targetLowResSample = 0;
      }
      i = 0;
      if ( targetResources.m_Size > 0 )
      {
        p_m_EntryInfo = &targetResources.m_Memory.m_pMemory->m_EntryInfo;
        do
        {
          resData = p_m_EntryInfo[-1].resData;
          resourceDataLength = resData;
          if ( resData == 4 )
          {
            p_m_EntryInfo->eType |= 0x2000000u;
            _V_memcpy(
              dest: (unsigned __int8 *)&p_m_EntryInfo->resData,
              src: (unsigned __int8 *)p_m_EntryInfo[-1].eType,
              count: 4u);
          }
          else if ( resData != 0 )
          {
            p_m_EntryInfo->resData = targetBuf->m_Put;
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &byteSwapWriter,
              outputBuffer: &swappedLength,
              inputBuffer: &resourceDataLength,
              count: 1);
            if ( (targetBuf->m_Flags & 1) != 0 )
              CUtlBuffer::Printf(this: targetBuf, pFmt: "%d", swappedLength);
            else
              CUtlBuffer::PutTypeBin<int>(this: targetBuf, src: swappedLength);
            if ( targetBuf->m_Error != 0 )
              goto cleanUp_0;
            CUtlBuffer::Put(this: targetBuf, pMem: (unsigned __int8 *)p_m_EntryInfo[-1].eType, size: resourceDataLength);
            if ( targetBuf->m_Error != 0 )
              goto cleanUp_0;
          }
          p_m_EntryInfo += 2;
          ++i;
        }
        while ( i < targetResources.m_Size );
      }
      m_Put = targetBuf->m_Put;
      targetLowResWidth = m_Put;
      AlignBuffer(buf: targetBuf, alignment: 4);
      resourceDataLength = targetBuf->m_Put;
      if ( resourceDataLength < 0x10000 )
      {
        i = targetMipCount - 1;
        if ( targetMipCount - 1 < 0 )
        {
LABEL_66:
          if ( m_Put < VTFFileHeaderSize(nMajorVersion: 864, nMinorVersion: 8) )
          {
            m_Put = VTFFileHeaderSize(nMajorVersion: 864, nMinorVersion: 8);
            targetLowResWidth = m_Put;
          }
          if ( targetBuf->m_Put <= 2048 )
          {
            m_Put = targetBuf->m_Put;
            targetLowResWidth = m_Put;
          }
          if ( m_Put < 0x10000 )
          {
            _V_memset(dest: (unsigned __int8 *)&targetHeader, fill: 0, count: 0x3Cu);
            _V_memcpy(dest: (unsigned __int8 *)&targetHeader, src: "VTFX", count: 4u);
            targetHeader.headerSize = v68;
            targetHeader.width = targetWidth;
            targetHeader.height = targetHeight;
            targetHeader.flags = numTypes;
            targetHeader.preloadDataSize = m_Put;
            v41 = targetResources.m_Size;
            targetHeader.numFrames = targetFrameCount;
            targetHeader.mipSkipCount = mipSkipCount;
            targetHeader.version[0] = 864;
            targetHeader.version[1] = 8;
            targetHeader.depth = 1;
            targetHeader.numResources = targetResources.m_Size;
            targetHeader.reflectivity = *VTFTexture->Reflectivity(this: VTFTexture);
            targetHeader.bumpScale = VTFTexture->BumpScale(this: VTFTexture);
            targetHeader.imageFormat = targetFormat;
            *(_DWORD *)targetHeader.lowResImageSample = *(_DWORD *)targetLowResSample;
            CByteswap::SwapFieldsToTargetEndian(
              this: &byteSwapWriter,
              pOutputBuffer: targetHeader.fileTypeString,
              pBaseData: targetHeader.fileTypeString,
              pDataMap: &VTFFileHeaderX360_t::m_DataMap);
            CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_HEAD, offset: 0);
            CUtlBuffer::Put(this: targetBuf, pMem: (unsigned __int8 *)&targetHeader, size: 60);
            if ( targetBuf->m_Error == 0 )
            {
              numTypes = 0;
              if ( v41 <= 0 )
              {
LABEL_83:
                CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_TAIL, offset: 0);
                if ( targetLowResWidth < targetBuf->m_Put && pCompressFunc != nullptr )
                {
                  CUtlBuffer::CUtlBuffer(this: &compressedBuffer, growSize: 0, initSize: 0, nFlags: 0);
                  v47 = resourceDataLength;
                  CUtlBuffer::SeekGet(this: targetBuf, type: SEEK_HEAD, offset: resourceDataLength);
                  if ( pCompressFunc(a1: targetBuf, a2: &compressedBuffer) )
                  {
                    CUtlBuffer::CUtlBuffer(this: &headerBuffer, growSize: 0, initSize: 0, nFlags: 0);
                    CUtlBuffer::EnsureCapacity(this: &headerBuffer, num: v47);
                    CUtlBuffer::Put(this: &headerBuffer, pMem: targetBuf->m_Memory.m_pMemory, size: v47);
                    targetBuf->m_Get = 0;
                    targetBuf->m_Put = 0;
                    targetBuf->m_Error = 0;
                    targetBuf->m_nOffset = 0;
                    targetBuf->m_nMaxPut = -1;
                    CUtlBuffer::AddNullTermination(this: targetBuf, nPut: 0);
                    CUtlBuffer::Put(this: targetBuf, pMem: headerBuffer.m_Memory.m_pMemory, size: v47);
                    CUtlBuffer::Put(
                      this: targetBuf,
                      pMem: compressedBuffer.m_Memory.m_pMemory,
                      size: compressedBuffer.m_Put);
                    v48 = targetBuf->m_Memory.m_pMemory;
                    CByteswap::SwapFieldsToTargetEndian(
                      this: &byteSwapWriter,
                      pOutputBuffer: (char *)v48,
                      pBaseData: (char *)v48,
                      pDataMap: &VTFFileHeaderX360_t::m_DataMap);
                    *((_DWORD *)v48 + 14) = compressedBuffer.m_Put;
                    CByteswap::SwapFieldsToTargetEndian(
                      this: &byteSwapWriter,
                      pOutputBuffer: (char *)v48,
                      pBaseData: (char *)v48,
                      pDataMap: &VTFFileHeaderX360_t::m_DataMap);
                    if ( headerBuffer.m_Memory.m_nGrowSize >= 0 && headerBuffer.m_Memory.m_pMemory != nullptr )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: headerBuffer.m_Memory.m_pMemory);
                  }
                  CUtlBuffer::SeekGet(this: targetBuf, type: SEEK_HEAD, offset: 0);
                  if ( compressedBuffer.m_Memory.m_nGrowSize >= 0 && compressedBuffer.m_Memory.m_pMemory != nullptr )
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: compressedBuffer.m_Memory.m_pMemory);
                }
                bRetVal = true;
              }
              else
              {
                p_resData = &targetResources.m_Memory.m_pMemory->m_EntryInfo.resData;
                while ( 1 )
                {
                  if ( (*(p_resData - 1) & 0xFFFFFF) == 0x30 )
                    *p_resData = resourceDataLength;
                  if ( (*(p_resData - 1) & 0x2000000) == 0
                    && p_resData != nullptr
                    && (*(_BYTE *)&byteSwapWriter & 1) != 0 )
                  {
                    v43 = *((_BYTE *)p_resData + 3);
                    v44 = *((_BYTE *)p_resData + 2);
                    frame = *p_resData;
                    v45 = *((_BYTE *)p_resData + 1);
                    BYTE1(frame) = v44;
                    LOBYTE(frame) = v43;
                    v46 = *(_BYTE *)p_resData;
                    BYTE2(frame) = v45;
                    HIBYTE(frame) = v46;
                    _V_memcpy(dest: (unsigned __int8 *)p_resData, src: (unsigned __int8 *)&frame, count: 4u);
                  }
                  CUtlBuffer::Put(this: targetBuf, pMem: (unsigned __int8 *)p_resData - 4, size: 8);
                  if ( targetBuf->m_Error != 0 )
                    break;
                  p_resData += 4;
                  if ( ++numTypes >= targetResources.m_Size )
                    goto LABEL_83;
                }
              }
            }
          }
          else
          {
            _Msg(a1: "ConvertVTFToConsoleFormatHelper: preload portion exceeds 16 bit boundary %s\n", pDebugName);
          }
        }
        else
        {
          while ( 1 )
          {
            frame = 0;
            if ( targetFrameCount > 0 )
              break;
LABEL_64:
            if ( --i < 0 )
            {
              m_Put = targetLowResWidth;
              goto LABEL_66;
            }
          }
          while ( 1 )
          {
            v40 = 0;
            if ( targetFaceCount > 0 )
              break;
LABEL_63:
            if ( ++frame >= targetFrameCount )
              goto LABEL_64;
          }
          while ( SerializeImageData(
                    pSourceVTF: VTFTexture,
                    frame,
                    face: v40,
                    mip: i,
                    targetFormat,
                    targetBuf,
                    targetConsole: VTF_CONSOLE_360) != 0 )
          {
            if ( ++v40 >= targetFaceCount )
              goto LABEL_63;
          }
        }
      }
      else
      {
        _Msg(a1: "ConvertVTFToConsoleFormatHelper: non-image portion exceeds 16 bit boundary %s\n", pDebugName);
      }
    }
  }
cleanUp_0:
  DestroyVTFTexture(pTexture: VTFTexture);
  v49 = targetResources.m_Size;
  v50 = targetResources.m_Memory.m_pMemory;
  if ( targetResources.m_Size > 0 )
  {
    v51 = targetResources.m_Memory.m_pMemory;
    do
    {
      free(pMem: v51->m_pData);
      v51->m_pData = nullptr;
      ++v51;
      --v49;
    }
    while ( v49 != 0 );
  }
  if ( targetResources.m_Memory.m_nGrowSize >= 0 && v50 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50);
  return bRetVal;
}

//------------------------------------------------------------------------------
// Address: 0x00535470
// Name: bool ConvertVTFToConsoleFormatHelper<1>(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &,bool (*)(class CUtlBuffer __near &,class CUtlBuffer __near &),bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
bool __usercall ConvertVTFToConsoleFormatHelper<1>@<al>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        const char *pDebugName,
        CUtlBuffer *sourceBuf,
        CUtlBuffer *targetBuf,
        bool (__cdecl *pCompressFunc)(CUtlBuffer *, CUtlBuffer *),
        bool bAllow1024Texture)
{
  CVTFTexture *VTFTexture; // esi
  ImageFormat v9; // eax
  CByteswap v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  char *v14; // eax
  bool v15; // zf
  unsigned __int8 *v16; // edi
  int v17; // edi
  float v18; // eax
  CVTFTexture_vtbl *v19; // edx
  int v20; // eax
  CVTFTexture_vtbl *v21; // edx
  int v22; // eax
  CByteswap v23; // edi
  ImageFormat (__thiscall *LowResFormat)(struct CVTFTexture *); // eax
  int v25; // eax
  CVTFTexture_vtbl *v26; // edx
  ImageFormat (__thiscall *v27)(struct CVTFTexture *); // eax
  int v28; // eax
  CVTFTexture_vtbl *v29; // edx
  int (__thiscall *LowResHeight)(struct CVTFTexture *); // eax
  unsigned int v31; // eax
  CVTFTexture_vtbl *v32; // edx
  int v33; // eax
  ImageFormat v34; // edx
  unsigned int v35; // ecx
  CVTFTexture_vtbl *v36; // eax
  CByteswap v37; // eax
  CVTFTexture_vtbl *v38; // edx
  unsigned __int8 *v39; // eax
  int v40; // eax
  double v41; // st7
  int v42; // edx
  double v43; // st7
  int v44; // ecx
  double v45; // st7
  float v46; // xmm0_4
  double v47; // st7
  double v48; // st7
  double v49; // st7
  unsigned int v50; // eax
  int v51; // eax
  int m_Put; // edx
  const Vector *v53; // eax
  int *v54; // eax
  char v55; // dl
  char v56; // cl
  char *v57; // eax
  ResourceCopy_t *m_pMemory; // edi
  void **v59; // esi
  _DWORD v62[3]; // [esp+3Ch] [ebp-1ACh] BYREF
  unsigned int resourceTypes[32]; // [esp+48h] [ebp-1A0h] BYREF
  CUtlBuffer headerBuffer; // [esp+C8h] [ebp-120h] BYREF
  CUtlBuffer compressedBuffer; // [esp+F8h] [ebp-F0h] BYREF
  VTFFileHeaderPS3_t targetHeader; // [esp+128h] [ebp-C0h]
  int v67; // [esp+168h] [ebp-80h] BYREF
  int v68; // [esp+16Ch] [ebp-7Ch] BYREF
  int v69; // [esp+170h] [ebp-78h]
  int targetMipCount; // [esp+174h] [ebp-74h]
  int targetWidth; // [esp+178h] [ebp-70h] BYREF
  int v72; // [esp+17Ch] [ebp-6Ch] BYREF
  int targetFaceCount; // [esp+180h] [ebp-68h] BYREF
  VTFFileHeaderPS3_t *pHeader; // [esp+184h] [ebp-64h]
  int mipSkipCount; // [esp+188h] [ebp-60h]
  CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int> > targetResources; // [esp+18Ch] [ebp-5Ch] BYREF
  __int128 targetLowResImage; // [esp+1A0h] [ebp-48h] OVERLAPPED
  Vector linearColor; // [esp+1B0h] [ebp-38h] BYREF
  CByteswap byteSwapWriter; // [esp+1BCh] [ebp-2Ch]
  int face; // [esp+1C0h] [ebp-28h]
  unsigned int resourceLength; // [esp+1C4h] [ebp-24h] BYREF
  int numTypes; // [esp+1C8h] [ebp-20h] BYREF
  int i; // [esp+1CCh] [ebp-1Ch]
  int resourceDataLength; // [esp+1D0h] [ebp-18h] BYREF
  ImageFormat targetFormat; // [esp+1D4h] [ebp-14h]
  int v86; // [esp+1D8h] [ebp-10h] OVERLAPPED BYREF
  int swappedLength; // [esp+1DCh] [ebp-Ch]
  unsigned __int8 targetLowResSample[4]; // [esp+1E0h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+1E8h] [ebp+0h]

  swappedLength = a1;
  *(_DWORD *)targetLowResSample = retaddr;
  targetFaceCount = 0;
  pHeader = nullptr;
  mipSkipCount = 0;
  targetResources.m_Memory.m_pMemory = nullptr;
  targetResources.m_Memory.m_nAllocationCount = 0;
  LODWORD(linearColor.x) = LODWORD(linearColor.x) & 0xFFFFFFFC | 3;
  MathLib_Init(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
  HIBYTE(i) = 0;
  VTFTexture = CreateVTFTexture();
  if ( ((unsigned __int8 (__thiscall *)(CVTFTexture *, CUtlBuffer *, int, _DWORD, int, int))VTFTexture->Unserialize)(
         a1: VTFTexture,
         a2: sourceBuf,
         a3: 1,
         a4: 0,
         a5: a2,
         a6: a3) != 0
    && VTFTexture->Depth(this: VTFTexture) == 1 )
  {
    v9 = VTFTexture->Format(this: VTFTexture);
    if ( ImageLoader::IsFormatValidForConversion(fmt: v9)
      && ComputeTargetDimensions(
           pDebugName,
           pVTFTexture: VTFTexture,
           picmip: 0,
           width: &v68,
           height: &targetWidth,
           mipCount: &v67,
           mipSkipCount: &v72,
           bNoMip: (bool *)&v86 + 3,
           bAllow1024Texture) != 0
      && v72 < sourceBuf->m_Memory.m_pMemory[56] )
    {
      CUtlBuffer::SeekGet(this: sourceBuf, type: SEEK_HEAD, offset: 0);
      if ( !VTFTexture->Unserialize(this: VTFTexture, a2: sourceBuf, a3: false, a4: v72) )
      {
        _Msg(a1: "ConvertVTFToConsoleFormatHelper: Error reading in %s\n", pDebugName);
        goto cleanUp_1;
      }
      targetResources.m_pElements = (ResourceCopy_t *)48;
      LODWORD(targetLowResImage) = 0;
      targetResources.m_Memory.m_nGrowSize = 0;
      targetResources.m_Size = 0;
      CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int>>::InsertBefore(
        this: (CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int> > *)&targetFaceCount,
        elem: 0,
        src: (const ResourceCopy_t *)&targetResources.m_Memory.m_nGrowSize);
      v10 = (CByteswap)VTFTexture->GetResourceTypes(this: VTFTexture, a2: v62, a3: 32);
      v11 = 0;
      byteSwapWriter = v10;
      face = 0;
      while ( v11 < *(_DWORD *)&byteSwapWriter )
      {
        v12 = v62[v11];
        v13 = (char *)(v12 & 0xFFFFFF);
        if ( (v12 & 0xFFFFFF) > 0x305354 )
        {
          if ( v13 != (char *)&loc_435243 )
          {
            v15 = v13 == (_BYTE *)&loc_444F49 + 3;
            goto LABEL_15;
          }
        }
        else if ( (v12 & 0xFFFFFF) != 0x305354 )
        {
          v14 = v13 - 1;
          if ( v14 != nullptr )
          {
            v15 = v14 == (char *)47;
LABEL_15:
            if ( !v15 )
            {
              v16 = (unsigned __int8 *)VTFTexture->GetResourceData(
                                         this: VTFTexture,
                                         a2: v12,
                                         a3: (unsigned int *)&linearColor.z);
              if ( v16 != nullptr )
              {
                targetResources.m_pElements = (ResourceCopy_t *)(v62[face] & 0xFFFFFF);
                LODWORD(targetLowResImage) = 0;
                targetResources.m_Memory.m_nGrowSize = (int)MemAlloc_Alloc(nSize: LODWORD(linearColor.z));
                targetResources.m_Size = LODWORD(linearColor.z);
                _V_memcpy(
                  dest: (unsigned __int8 *)targetResources.m_Memory.m_nGrowSize,
                  src: v16,
                  count: LODWORD(linearColor.z));
                CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int>>::InsertBefore(
                  this: (CUtlVector<ResourceCopy_t,CUtlMemory<ResourceCopy_t,int> > *)&targetFaceCount,
                  elem: (int)targetResources.m_Memory.m_pMemory,
                  src: (const ResourceCopy_t *)&targetResources.m_Memory.m_nGrowSize);
              }
            }
          }
        }
        v11 = face + 1;
        face = v11;
      }
      if ( (int)targetResources.m_Memory.m_pMemory > 4 )
      {
        _Msg(a1: "ConvertVTFToConsoleFormatHelper: More resources than expected in %s\n", pDebugName);
        goto cleanUp_1;
      }
      v17 = VTFTexture->Flags(this: VTFTexture);
      v18 = COERCE_FLOAT(VTFTexture->FrameCount(this: VTFTexture));
      v19 = VTFTexture->__vftable;
      linearColor.z = v18;
      v20 = v19->FaceCount(this: VTFTexture);
      v21 = VTFTexture->__vftable;
      targetMipCount = v20;
      v22 = v21->Format(this: VTFTexture);
      switch ( v22 )
      {
        case 0:
        case 1:
        case 11:
        case 12:
          numTypes = 12;
          break;
        case 2:
        case 3:
        case 9:
        case 10:
        case 16:
          numTypes = 16;
          break;
        case 4:
        case 17:
        case 18:
          numTypes = 17;
          break;
        case 24:
        case 25:
          numTypes = 24;
          break;
        default:
          numTypes = v22;
          break;
      }
      if ( HIBYTE(v86) != 0 )
        v23 = (CByteswap)(v17 | 0x100);
      else
        v23 = (CByteswap)(v17 & 0xFFFFFEFF);
      LowResFormat = VTFTexture->LowResFormat;
      byteSwapWriter = v23;
      if ( LowResFormat(this: VTFTexture) != IMAGE_FORMAT_UNKNOWN
        && VTFTexture->LowResWidth(this: VTFTexture) != 0
        && VTFTexture->LowResHeight(this: VTFTexture) != 0 )
      {
        v25 = VTFTexture->LowResWidth(this: VTFTexture);
        v26 = VTFTexture->__vftable;
        v86 = v25;
        v26->LowResHeight(this: VTFTexture);
      }
      else
      {
        v86 = 0;
      }
      v69 = 8 * (int)targetResources.m_Memory.m_pMemory + 64;
      CUtlBuffer::EnsureCapacity(this: targetBuf, num: v69);
      CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_CURRENT, offset: v69);
      if ( v86 != 0 && targetFormat != IMAGE_FORMAT_RGBA8888 )
      {
        v27 = VTFTexture->LowResFormat;
        targetFormat = IMAGE_FORMAT_RGBA8888;
        targetResources.m_Size = 0;
        targetResources.m_pElements = nullptr;
        LODWORD(targetLowResImage) = 0;
        resourceDataLength = 0;
        v28 = v27(this: VTFTexture);
        v29 = VTFTexture->__vftable;
        i = v28;
        LowResHeight = v29->LowResHeight;
        numTypes = 1;
        v31 = LowResHeight(this: VTFTexture);
        v32 = VTFTexture->__vftable;
        resourceLength = v31;
        v33 = v32->LowResWidth(this: VTFTexture);
        resourceLength = ImageLoader::GetMemRequired(
                           width: v33,
                           height: resourceLength,
                           depth: numTypes,
                           imageFormat: (ImageFormat)i,
                           mipmap: resourceDataLength,
                           pAdjustedHeight: (int *)targetFormat);
        resourceDataLength = ImageLoader::GetMemRequired(
                               width: v86,
                               height: targetFormat,
                               depth: 1,
                               imageFormat: IMAGE_FORMAT_RGB888,
                               mipmap: false,
                               pAdjustedHeight: nullptr);
        CUtlMemory<unsigned char,int>::EnsureCapacity(
          this: (CUtlMemory<unsigned char,int> *)&targetResources.m_Size,
          num: resourceDataLength);
        memset(dst: (unsigned __int8 *)targetResources.m_Size, value: 0xFFu, count: resourceDataLength);
        v34 = targetFormat;
        v35 = resourceDataLength;
        targetFormat = IMAGE_FORMAT_ABGR8888;
        resourceDataLength = v34;
        i = v86;
        v36 = VTFTexture->__vftable;
        numTypes = 2;
        resourceLength = v35;
        face = targetResources.m_Size;
        v37 = (CByteswap)v36->LowResFormat(this: VTFTexture);
        v38 = VTFTexture->__vftable;
        byteSwapWriter = v37;
        LODWORD(linearColor.z) = resourceLength;
        v39 = v38->LowResImageData(this: VTFTexture);
        HIBYTE(i) = ConvertImageFormatEx(
                      pSourceImage: v39,
                      sourceImageSize: (CBaseAppSystem<IDmSerializers> *)LODWORD(linearColor.z),
                      sourceFormat: *(ImageFormat *)&byteSwapWriter,
                      pTargetImage: (unsigned __int8 *)face,
                      targetImageSize: resourceLength,
                      targetFormat: (ImageFormat)numTypes,
                      width: i,
                      height: resourceDataLength,
                      targetConsole: (VtfConsoleFormatType_t)targetFormat);
        if ( HIBYTE(i) == 0 )
        {
          CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: (CUtlBuffer *)&targetResources.m_Size);
          goto cleanUp_1;
        }
        v40 = v86 * targetFormat;
        *((_QWORD *)&targetLowResImage + 1) = 0;
        DWORD1(targetLowResImage) = 0;
        resourceLength = v86 * targetFormat;
        if ( v86 * targetFormat > 0 )
        {
          targetFormat = targetResources.m_Size + 2;
          resourceDataLength = v40;
          do
          {
            v41 = SrgbGammaToLinear(flSrgbGammaValue: (float)*(unsigned __int8 *)(targetFormat - 2) * 0.0039215689);
            v42 = *(unsigned __int8 *)(targetFormat - 1);
            *((float *)&targetLowResImage + 1) = v41 + *((float *)&targetLowResImage + 1);
            v43 = SrgbGammaToLinear(flSrgbGammaValue: (float)v42 * 0.0039215689);
            v44 = *(unsigned __int8 *)targetFormat;
            *((float *)&targetLowResImage + 2) = v43 + *((float *)&targetLowResImage + 2);
            v45 = SrgbGammaToLinear(flSrgbGammaValue: (float)v44 * 0.0039215689);
            targetFormat += 3;
            v15 = resourceDataLength-- == 1;
            *((float *)&targetLowResImage + 3) = v45 + *((float *)&targetLowResImage + 3);
          }
          while ( !v15 );
        }
        v46 = 1.0 / (float)(int)resourceLength;
        *((float *)&targetLowResImage + 2) = v46 * *((float *)&targetLowResImage + 2);
        *((float *)&targetLowResImage + 3) = v46 * *((float *)&targetLowResImage + 3);
        v47 = SrgbLinearToGamma(flLinearValue: v46 * *((float *)&targetLowResImage + 1));
        targetFormat = DWORD2(targetLowResImage);
        LOBYTE(targetFormat) = (int)(v47 * 255.0);
        v48 = SrgbLinearToGamma(flLinearValue: *(float *)&targetFormat);
        targetFormat = HIDWORD(targetLowResImage);
        BYTE1(targetFormat) = (int)(v48 * 255.0);
        v49 = SrgbLinearToGamma(flLinearValue: *(float *)&targetFormat);
        HIBYTE(targetFormat) = -1;
        resourceDataLength = (int)(v49 * 255.0);
        BYTE2(targetFormat) = resourceDataLength;
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: (CUtlBuffer *)&targetResources.m_Size);
      }
      else
      {
        targetFormat = IMAGE_FORMAT_RGBA8888;
      }
      linearColor.y = 0.0;
      if ( (int)targetResources.m_Memory.m_pMemory > 0 )
      {
        v86 = targetFaceCount + 8;
        do
        {
          v50 = *(_DWORD *)(v86 - 4);
          resourceLength = v50;
          if ( v50 == 4 )
          {
            v51 = v86;
            *(_DWORD *)v86 |= 0x2000000u;
            _V_memcpy(dest: (unsigned __int8 *)(v51 + 4), src: *(unsigned __int8 **)(v51 - 8), count: 4u);
          }
          else if ( v50 != 0 )
          {
            m_Put = targetBuf->m_Put;
            targetFormat = IMAGE_FORMAT_ABGR8888;
            *(_DWORD *)(v86 + 4) = m_Put;
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: (CByteswap *)&linearColor,
              outputBuffer: &resourceDataLength,
              inputBuffer: (int *)&resourceLength,
              count: targetFormat);
            if ( (targetBuf->m_Flags & 1) != 0 )
              CUtlBuffer::Printf(this: targetBuf, pFmt: "%d", resourceDataLength);
            else
              CUtlBuffer::PutTypeBin<int>(this: targetBuf, src: resourceDataLength);
            if ( targetBuf->m_Error != 0 )
              goto cleanUp_1;
            CUtlBuffer::Put(this: targetBuf, pMem: *(unsigned __int8 **)(v86 - 8), size: resourceLength);
            if ( targetBuf->m_Error != 0 )
              goto cleanUp_1;
          }
          v86 += 16;
          ++LODWORD(linearColor.y);
        }
        while ( SLODWORD(linearColor.y) < (int)targetResources.m_Memory.m_pMemory );
      }
      v86 = targetBuf->m_Put;
      AlignBuffer(buf: targetBuf, alignment: 4);
      face = targetBuf->m_Put;
      if ( face < 0x10000 )
      {
        resourceDataLength = v67 - 1;
        if ( v67 - 1 < 0 )
        {
LABEL_64:
          if ( v86 < VTFFileHeaderSize(nMajorVersion: 819, nMinorVersion: 8) )
            v86 = VTFFileHeaderSize(nMajorVersion: 819, nMinorVersion: 8);
          if ( targetBuf->m_Put <= 2048 )
            v86 = targetBuf->m_Put;
          if ( v86 < 0x10000 )
          {
            _V_memset(dest: (unsigned __int8 *)&compressedBuffer.m_GetOverflowFunc, fill: 0, count: 0x40u);
            _V_memcpy(dest: (unsigned __int8 *)&compressedBuffer.m_GetOverflowFunc, src: "VTF3", count: 4u);
            LOWORD(targetHeader.version[1]) = v68;
            *(_DWORD *)targetHeader.fileTypeString = v69;
            targetHeader.version[0] = (int)byteSwapWriter;
            LOWORD(targetHeader.headerSize) = 1;
            HIWORD(targetHeader.headerSize) = LOWORD(linearColor.z);
            HIWORD(targetHeader.version[1]) = targetWidth;
            BYTE2(targetHeader.flags) = v72;
            HIBYTE(targetHeader.flags) = targetResources.m_Memory.m_pMemory;
            compressedBuffer.m_PutOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))819;
            compressedBuffer.m_Byteswap = (CByteswap)8;
            LOWORD(targetHeader.flags) = v86;
            v53 = VTFTexture->Reflectivity(this: VTFTexture);
            *(float *)&targetHeader.width = v53->x;
            *(float *)&targetHeader.depth = v53->y;
            *(float *)&targetHeader.preloadDataSize = v53->z;
            targetHeader.reflectivity.x = VTFTexture->BumpScale(this: VTFTexture);
            LODWORD(targetHeader.reflectivity.y) = numTypes;
            BYTE2(targetHeader.reflectivity.z) = BYTE2(targetFormat);
            LOWORD(targetHeader.reflectivity.z) = targetFormat;
            HIBYTE(targetHeader.reflectivity.z) = (unsigned int)&VTFFileHeaderPS3_t::m_DataMap >> 24;
            CByteswap::SwapFieldsToTargetEndian(
              this: (CByteswap *)&linearColor,
              pOutputBuffer: (char *)&compressedBuffer.m_GetOverflowFunc,
              pBaseData: (char *)&compressedBuffer.m_GetOverflowFunc,
              pDataMap: &VTFFileHeaderPS3_t::m_DataMap);
            CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_HEAD, offset: 0);
            CUtlBuffer::Put(this: targetBuf, pMem: (unsigned __int8 *)&compressedBuffer.m_GetOverflowFunc, size: 64);
            if ( targetBuf->m_Error == 0 )
            {
              byteSwapWriter = 0;
              if ( (int)targetResources.m_Memory.m_pMemory <= 0 )
              {
LABEL_81:
                CUtlBuffer::SeekPut(this: targetBuf, type: SEEK_TAIL, offset: 0);
                if ( v86 < targetBuf->m_Put && pCompressFunc != nullptr )
                {
                  CUtlBuffer::CUtlBuffer(
                    this: (CUtlBuffer *)&headerBuffer.m_GetOverflowFunc,
                    growSize: 0,
                    initSize: 0,
                    nFlags: 0);
                  CUtlBuffer::SeekGet(this: targetBuf, type: SEEK_HEAD, offset: face);
                  if ( pCompressFunc(a1: targetBuf, a2: (CUtlBuffer *)&headerBuffer.m_GetOverflowFunc) )
                  {
                    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&resourceTypes[29], growSize: 0, initSize: 0, nFlags: 0);
                    CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)&resourceTypes[29], num: face);
                    CUtlBuffer::Put(
                      this: (CUtlBuffer *)&resourceTypes[29],
                      pMem: targetBuf->m_Memory.m_pMemory,
                      size: face);
                    targetFormat = IMAGE_FORMAT_RGBA8888;
                    targetBuf->m_Get = 0;
                    targetBuf->m_Put = 0;
                    targetBuf->m_Error = 0;
                    targetBuf->m_nOffset = 0;
                    targetBuf->m_nMaxPut = -1;
                    CUtlBuffer::AddNullTermination(this: targetBuf, nPut: targetFormat);
                    CUtlBuffer::Put(this: targetBuf, pMem: (unsigned __int8 *)resourceTypes[29], size: face);
                    CUtlBuffer::Put(
                      this: targetBuf,
                      pMem: (unsigned __int8 *)headerBuffer.m_GetOverflowFunc,
                      size: compressedBuffer.m_Memory.m_nAllocationCount);
                    targetWidth = (int)targetBuf->m_Memory.m_pMemory;
                    CByteswap::SwapFieldsToTargetEndian(
                      this: (CByteswap *)&linearColor,
                      pOutputBuffer: (char *)targetWidth,
                      pBaseData: (char *)targetWidth,
                      pDataMap: &VTFFileHeaderPS3_t::m_DataMap);
                    v57 = (char *)targetWidth;
                    targetFormat = (ImageFormat)&VTFFileHeaderPS3_t::m_DataMap;
                    resourceDataLength = targetWidth;
                    *(_DWORD *)(targetWidth + 56) = compressedBuffer.m_Memory.m_nAllocationCount;
                    CByteswap::SwapFieldsToTargetEndian(
                      this: (CByteswap *)&linearColor,
                      pOutputBuffer: v57,
                      pBaseData: (char *)resourceDataLength,
                      pDataMap: (datamap_t *)targetFormat);
                    if ( (resourceTypes[31] & 0x80000000) == 0 && resourceTypes[29] != 0 )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)resourceTypes[29]);
                  }
                  CUtlBuffer::SeekGet(this: targetBuf, type: SEEK_HEAD, offset: 0);
                  if ( *(_DWORD *)&headerBuffer.m_Byteswap >= 0 && headerBuffer.m_GetOverflowFunc != nullptr )
                    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: headerBuffer.m_GetOverflowFunc);
                }
                HIBYTE(i) = 1;
              }
              else
              {
                v54 = (int *)(targetFaceCount + 12);
                targetFormat = targetFaceCount + 12;
                while ( 1 )
                {
                  if ( (*(v54 - 1) & 0xFFFFFF) == 0x30 )
                    *v54 = face;
                  if ( (*(v54 - 1) & 0x2000000) == 0 && v54 != nullptr && (LOBYTE(linearColor.x) & 1) != 0 )
                  {
                    v55 = *(_BYTE *)(targetFormat + 3);
                    numTypes = *(_DWORD *)targetFormat;
                    v56 = *(_BYTE *)(targetFormat + 2);
                    LOBYTE(numTypes) = v55;
                    BYTE2(numTypes) = *(_BYTE *)(targetFormat + 1);
                    BYTE1(numTypes) = v56;
                    HIBYTE(numTypes) = *(_BYTE *)targetFormat;
                    _V_memcpy(dest: (unsigned __int8 *)targetFormat, src: (unsigned __int8 *)&numTypes, count: 4u);
                  }
                  CUtlBuffer::Put(this: targetBuf, pMem: (unsigned __int8 *)(targetFormat - 4), size: 8);
                  if ( targetBuf->m_Error != 0 )
                    break;
                  v54 = (int *)(targetFormat + 16);
                  ++*(_DWORD *)&byteSwapWriter;
                  targetFormat += 16;
                  if ( *(_DWORD *)&byteSwapWriter >= (int)targetResources.m_Memory.m_pMemory )
                    goto LABEL_81;
                }
              }
            }
          }
          else
          {
            _Msg(a1: "ConvertVTFToConsoleFormatHelper: preload portion exceeds 16 bit boundary %s\n", pDebugName);
          }
        }
        else
        {
          while ( 1 )
          {
            resourceLength = 0;
            if ( SLODWORD(linearColor.z) > 0 )
              break;
LABEL_63:
            if ( --resourceDataLength < 0 )
              goto LABEL_64;
          }
          while ( 1 )
          {
            linearColor.y = 0.0;
            if ( targetMipCount > 0 )
              break;
LABEL_62:
            if ( (int)++resourceLength >= SLODWORD(linearColor.z) )
              goto LABEL_63;
          }
          while ( SerializeImageData(
                    pSourceVTF: VTFTexture,
                    frame: resourceLength,
                    face: SLODWORD(linearColor.y),
                    mip: resourceDataLength,
                    targetFormat: (ImageFormat)numTypes,
                    targetBuf,
                    targetConsole: VTF_CONSOLE_PS3) != 0 )
          {
            ++LODWORD(linearColor.y);
            if ( SLODWORD(linearColor.y) >= targetMipCount )
              goto LABEL_62;
          }
        }
      }
      else
      {
        _Msg(a1: "ConvertVTFToConsoleFormatHelper: non-image portion exceeds 16 bit boundary %s\n", pDebugName);
      }
    }
  }
cleanUp_1:
  DestroyVTFTexture(pTexture: VTFTexture);
  m_pMemory = targetResources.m_Memory.m_pMemory;
  if ( (int)targetResources.m_Memory.m_pMemory > 0 )
  {
    v59 = (void **)targetFaceCount;
    do
    {
      free(pMem: *v59);
      *v59 = nullptr;
      v59 += 4;
      m_pMemory = (ResourceCopy_t *)((char *)m_pMemory - 1);
    }
    while ( m_pMemory != nullptr );
  }
  if ( mipSkipCount >= 0 && targetFaceCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)targetFaceCount);
  return HIBYTE(i);
}

//------------------------------------------------------------------------------
// Address: 0x00535F40
// Name: bool ConvertVTFTo360Format(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &,bool (*)(class CUtlBuffer __near &,class CUtlBuffer __near &),bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall ConvertVTFTo360Format@<al>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *pDebugName,
        CUtlBuffer *sourceBuf,
        CUtlBuffer *targetBuf,
        bool (__cdecl *pCompressFunc)(CUtlBuffer *, CUtlBuffer *),
        bool bAllow1024Texture)
{
  return ConvertVTFToConsoleFormatHelper<0>(
           a1,
           a2,
           a3,
           pDebugName,
           sourceBuf,
           targetBuf,
           pCompressFunc,
           bAllow1024Texture);
}

//------------------------------------------------------------------------------
// Address: 0x00535F50
// Name: bool ConvertVTFToPS3Format(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &,bool (*)(class CUtlBuffer __near &,class CUtlBuffer __near &),bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __usercall ConvertVTFToPS3Format@<al>(
        int a1@<edi>,
        int a2@<esi>,
        const char *pDebugName,
        CUtlBuffer *sourceBuf,
        CUtlBuffer *targetBuf,
        bool (__cdecl *pCompressFunc)(CUtlBuffer *, CUtlBuffer *),
        bool bAllow1024Texture)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  return ConvertVTFToConsoleFormatHelper<1>(
           a1: (int)&savedregs,
           a2: a1,
           a3: a2,
           pDebugName,
           sourceBuf,
           targetBuf,
           pCompressFunc,
           bAllow1024Texture);
}
