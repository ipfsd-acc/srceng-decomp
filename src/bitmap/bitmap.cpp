// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/bitmap.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000C4D0
// Name: bool IsPFMFile(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsPFMFile(CUtlBuffer *buf)
{
  int m_Get; // edi
  unsigned __int8 v3; // bl
  unsigned __int8 v5; // [esp+Fh] [ebp-1h]
  unsigned __int8 buf_3; // [esp+1Bh] [ebp+Bh]

  m_Get = buf->m_Get;
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    buf_3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    buf_3 = 0;
  }
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v5 = 0;
  }
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v3 = 0;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  return buf_3 == 80 && (v5 == 70 || v5 == 102) && v3 == 10;
}

//------------------------------------------------------------------------------
// Address: 0x1000C590
// Name: ReadIntFromUtlBuffer
// Source: json
//------------------------------------------------------------------------------
int __usercall ReadIntFromUtlBuffer@<eax>(CUtlBuffer *buf@<esi>)
{
  int v1; // edi
  signed __int8 v2; // cl

  v1 = 0;
  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v2 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v2 = 0;
      }
      if ( (unsigned int)(v2 - 48) > 9 )
        break;
      v1 = v2 + 10 * v1 - 48;
      if ( buf->m_Error != 0 )
        return v1;
    }
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: -1);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C5F0
// Name: EatWhiteSpace
// Source: json
//------------------------------------------------------------------------------
void __usercall EatWhiteSpace(CUtlBuffer *buf@<esi>)
{
  unsigned __int8 v1; // cl

  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v1 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v1 = 0;
      }
      if ( v1 != 32 && v1 != 9 && v1 != 10 )
        break;
      if ( buf->m_Error != 0 )
        return;
    }
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C640
// Name: bool PFMGetInfo_AndAdvanceToTextureBits(class CUtlBuffer __near &,int __near &,int __near &,enum ImageFormat __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PFMGetInfo_AndAdvanceToTextureBits(
        CUtlBuffer *pfmBuffer,
        int *nWidth,
        int *nHeight,
        ImageFormat *imageFormat)
{
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl
  int IntFromUtlBuffer; // edi
  unsigned __int8 v9; // cl

  CUtlBuffer::SeekGet(this: pfmBuffer, type: SEEK_HEAD, offset: 0);
  if ( !CUtlBuffer::CheckGet(this: pfmBuffer, nSize: 1) )
    return 0;
  v4 = pfmBuffer->m_Memory.m_pMemory[pfmBuffer->m_Get++ - pfmBuffer->m_nOffset];
  if ( v4 != 80 || !CUtlBuffer::CheckGet(this: pfmBuffer, nSize: 1) )
    return 0;
  v5 = pfmBuffer->m_Memory.m_pMemory[pfmBuffer->m_Get++ - pfmBuffer->m_nOffset];
  if ( v5 == 70 )
  {
    *imageFormat = IMAGE_FORMAT_RGB323232F;
  }
  else
  {
    if ( v5 != 102 )
      return 0;
    *imageFormat = IMAGE_FORMAT_R32F;
  }
  if ( !CUtlBuffer::CheckGet(this: pfmBuffer, nSize: 1) )
    return 0;
  v6 = pfmBuffer->m_Memory.m_pMemory[pfmBuffer->m_Get++ - pfmBuffer->m_nOffset];
  if ( v6 != 10 )
    return 0;
  *nWidth = ReadIntFromUtlBuffer(buf: pfmBuffer);
  EatWhiteSpace(buf: pfmBuffer);
  *nHeight = ReadIntFromUtlBuffer(buf: pfmBuffer);
  while ( pfmBuffer->m_Error == 0 )
  {
    if ( CUtlBuffer::CheckGet(this: pfmBuffer, nSize: 1) )
    {
      v7 = pfmBuffer->m_Memory.m_pMemory[pfmBuffer->m_Get++ - pfmBuffer->m_nOffset];
      if ( v7 == 10 )
        break;
    }
  }
  IntFromUtlBuffer = ReadIntFromUtlBuffer(buf: pfmBuffer);
  while ( pfmBuffer->m_Error == 0 )
  {
    if ( CUtlBuffer::CheckGet(this: pfmBuffer, nSize: 1) )
    {
      v9 = pfmBuffer->m_Memory.m_pMemory[pfmBuffer->m_Get++ - pfmBuffer->m_nOffset];
      if ( v9 == 10 )
        break;
    }
  }
  if ( IntFromUtlBuffer > 0 )
    CUtlBuffer::SetBigEndian(this: pfmBuffer, bigEndian: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C780
// Name: bool PFMReadFileRGBA32323232F(class CUtlBuffer __near &,struct Bitmap_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PFMReadFileRGBA32323232F(CUtlBuffer *fileBuffer, Bitmap_t *bitmap, float pfmScale)
{
  int v4; // esi
  const ImageFormatInfo_t *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // ecx
  int v8; // eax
  ImageFormat v9; // edx
  float *v10; // esi
  float *v11; // esi
  ImageFormat imageFormat; // [esp+Ch] [ebp-10h] BYREF
  int v14; // [esp+10h] [ebp-Ch]
  int y; // [esp+14h] [ebp-8h] BYREF
  int nWidth; // [esp+18h] [ebp-4h] BYREF
  Bitmap_t *bitmapa; // [esp+28h] [ebp+Ch]

  nWidth = 0;
  y = 0;
  PFMGetInfo_AndAdvanceToTextureBits(pfmBuffer: fileBuffer, &nWidth, nHeight: &y, &imageFormat);
  if ( bitmap->m_pBits != nullptr )
  {
    free(pMem: bitmap->m_pBits);
    bitmap->m_pBits = nullptr;
  }
  v4 = y;
  bitmap->m_nWidth = nWidth;
  bitmap->m_nHeight = v4;
  bitmap->m_ImageFormat = IMAGE_FORMAT_RGBA32323232F;
  v5 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA32323232F);
  v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: nWidth * v4 * v5->m_nNumBytes);
  v7 = v4 - 1;
  bitmap->m_pBits = v6;
  y = v4 - 1;
  if ( v4 - 1 < 0 )
    return 1;
  v8 = 16 * nWidth * v7;
  v9 = -16 * nWidth;
  v14 = v8;
  imageFormat = -16 * nWidth;
  while ( fileBuffer->m_Error == 0 )
  {
    v10 = (float *)&bitmap->m_pBits[v8];
    if ( nWidth > 0 )
    {
      for ( bitmapa = (Bitmap_t *)nWidth; bitmapa != nullptr; bitmapa = (Bitmap_t *)((char *)bitmapa - 1) )
      {
        CUtlBuffer::Get(this: fileBuffer, pMem: v10, size: 4);
        *v10 = pfmScale * *v10;
        v11 = v10 + 1;
        CUtlBuffer::Get(this: fileBuffer, pMem: v11, size: 4);
        *v11 = pfmScale * *v11;
        CUtlBuffer::Get(this: fileBuffer, pMem: ++v11, size: 4);
        *v11 = pfmScale * *v11;
        v11[1] = 1.0;
        v10 = v11 + 2;
      }
      v7 = y;
      v8 = v14;
      v9 = imageFormat;
    }
    --v7;
    v8 += v9;
    y = v7;
    v14 = v8;
    if ( v7 < 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000C8C0
// Name: bool PFMReadFileRGB323232F(class CUtlBuffer __near &,struct Bitmap_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PFMReadFileRGB323232F(CUtlBuffer *fileBuffer, Bitmap_t *bitmap, float pfmScale)
{
  Bitmap_t *v3; // esi
  int v4; // edi
  int v5; // ebx
  const ImageFormatInfo_t *v6; // eax
  int v7; // eax
  float *v8; // esi
  int v9; // ebx
  int v10; // ecx
  unsigned int v11; // edx
  float *v12; // eax
  ImageFormat imageFormat; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int nWidth; // [esp+14h] [ebp-4h] BYREF

  nWidth = 0;
  y = 0;
  PFMGetInfo_AndAdvanceToTextureBits(pfmBuffer: fileBuffer, &nWidth, nHeight: &y, &imageFormat);
  v3 = bitmap;
  if ( bitmap->m_pBits != nullptr )
  {
    free(pMem: bitmap->m_pBits);
    bitmap->m_pBits = nullptr;
  }
  v4 = nWidth;
  v5 = y;
  bitmap->m_nWidth = nWidth;
  bitmap->m_nHeight = v5;
  bitmap->m_ImageFormat = IMAGE_FORMAT_RGB323232F;
  v6 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGB323232F);
  bitmap->m_pBits = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 * v5 * v6->m_nNumBytes);
  y = v5 - 1;
  if ( v5 - 1 < 0 )
    return 1;
  v7 = 12 * v4 * (v5 - 1);
  nWidth = v7;
  imageFormat = -12 * v4;
  while ( fileBuffer->m_Error == 0 )
  {
    v8 = (float *)&v3->m_pBits[v7];
    CUtlBuffer::Get(this: fileBuffer, pMem: v8, size: 12 * v4);
    v9 = 3 * v4;
    v10 = 0;
    if ( 3 * v4 >= 4 )
    {
      v11 = ((unsigned int)(v9 - 4) >> 2) + 1;
      v12 = v8 + 2;
      v10 = 4 * v11;
      do
      {
        *(v12 - 2) = *(v12 - 2) * pfmScale;
        *(v12 - 1) = *(v12 - 1) * pfmScale;
        *v12 = *v12 * pfmScale;
        v12[1] = v12[1] * pfmScale;
        v12 += 4;
        --v11;
      }
      while ( v11 != 0 );
    }
    for ( ; v10 < v9; ++v10 )
      v8[v10] = v8[v10] * pfmScale;
    nWidth += imageFormat;
    if ( --y < 0 )
      return 1;
    v3 = bitmap;
    v7 = nWidth;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CA30
// Name: bool PFMReadFileR32F(class CUtlBuffer __near &,struct Bitmap_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PFMReadFileR32F(CUtlBuffer *fileBuffer, Bitmap_t *bitmap, float pfmScale)
{
  Bitmap_t *v3; // edi
  int v4; // esi
  const ImageFormatInfo_t *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // ecx
  int v8; // eax
  ImageFormat v9; // edx
  float *v10; // esi
  int i; // edi
  float v12; // xmm0_4
  bool v13; // cc
  char szOutputMessage[80]; // [esp+1Ch] [ebp-70h] BYREF
  float flDummy[2]; // [esp+6Ch] [ebp-20h] BYREF
  ImageFormat fileImageFormat; // [esp+74h] [ebp-18h] BYREF
  int nHeight; // [esp+78h] [ebp-14h] BYREF
  int y; // [esp+7Ch] [ebp-10h]
  float flMin; // [esp+80h] [ebp-Ch]
  float flMax; // [esp+84h] [ebp-8h]
  int nWidth; // [esp+88h] [ebp-4h] BYREF

  PFMGetInfo_AndAdvanceToTextureBits(pfmBuffer: fileBuffer, &nWidth, &nHeight, imageFormat: &fileImageFormat);
  v3 = bitmap;
  if ( bitmap->m_pBits != nullptr )
  {
    free(pMem: bitmap->m_pBits);
    bitmap->m_pBits = nullptr;
  }
  v4 = nHeight;
  bitmap->m_nWidth = nWidth;
  bitmap->m_nHeight = v4;
  bitmap->m_ImageFormat = IMAGE_FORMAT_R32F;
  v5 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_R32F);
  v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 * nWidth * v5->m_nNumBytes);
  v7 = v4 - 1;
  flMin = 3.4028235e38;
  bitmap->m_pBits = v6;
  flMax = 1.1754944e-38;
  y = v4 - 1;
  if ( v4 - 1 < 0 )
  {
LABEL_15:
    V_snprintf(pDest: szOutputMessage, maxLen: 80, pFormat: "Displacement Range: (%g, %g)\n", flMin, flMax);
    printf(format: szOutputMessage);
    return 1;
  }
  else
  {
    v8 = 4 * nWidth * v7;
    v9 = -4 * nWidth;
    nHeight = v8;
    fileImageFormat = -4 * nWidth;
    while ( fileBuffer->m_Error == 0 )
    {
      v10 = (float *)&v3->m_pBits[v8];
      if ( nWidth > 0 )
      {
        for ( i = nWidth; i != 0; --i )
        {
          CUtlBuffer::Get(this: fileBuffer, pMem: v10, size: 4);
          v12 = *v10 * pfmScale;
          v13 = flMin <= v12;
          *v10 = v12;
          if ( !v13 )
            flMin = v12;
          if ( v12 > flMax )
            flMax = v12;
          CUtlBuffer::Get(this: fileBuffer, pMem: flDummy, size: 8);
          ++v10;
        }
        v9 = fileImageFormat;
        v8 = nHeight;
        v7 = y;
        v3 = bitmap;
      }
      --v7;
      v8 += v9;
      y = v7;
      nHeight = v8;
      if ( v7 < 0 )
        goto LABEL_15;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CBB0
// Name: bool PFMReadFile(class CUtlBuffer __near &,struct Bitmap_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PFMReadFile(CUtlBuffer *buf, Bitmap_t *pBitmap)
{
  ImageFormat v3; // eax
  int v4; // edi
  int v5; // ebx
  const ImageFormatInfo_t *v6; // eax
  unsigned __int8 *v7; // eax
  int MemRequired; // eax
  int v9; // edi
  int v10; // ebx
  ImageFormat v12; // [esp-10h] [ebp-28h]
  ImageFormat v13; // [esp-4h] [ebp-1Ch]
  int nHeight; // [esp+Ch] [ebp-Ch] BYREF
  int nWidth; // [esp+10h] [ebp-8h] BYREF
  ImageFormat fmt; // [esp+14h] [ebp-4h] BYREF
  int nRowBytes; // [esp+24h] [ebp+Ch]

  nWidth = 0;
  nHeight = 0;
  fmt = IMAGE_FORMAT_UNKNOWN;
  PFMGetInfo_AndAdvanceToTextureBits(pfmBuffer: buf, &nWidth, &nHeight, imageFormat: &fmt);
  if ( pBitmap->m_pBits != nullptr )
  {
    free(pMem: pBitmap->m_pBits);
    pBitmap->m_pBits = nullptr;
  }
  v3 = fmt;
  v4 = nWidth;
  v5 = nHeight;
  v13 = fmt;
  pBitmap->m_nWidth = nWidth;
  pBitmap->m_nHeight = v5;
  pBitmap->m_ImageFormat = v3;
  v6 = ImageLoader::ImageFormatInfo(fmt: v13);
  v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 * v5 * v6->m_nNumBytes);
  v12 = fmt;
  pBitmap->m_pBits = v7;
  MemRequired = ImageLoader::GetMemRequired(
                  width: v4,
                  height: 1,
                  depth: 1,
                  nMipmapCount: 1,
                  imageFormat: v12,
                  pAdjustedHeight: nullptr);
  v9 = v5 - 1;
  nRowBytes = MemRequired;
  if ( v5 - 1 < 0 )
    return 1;
  v10 = MemRequired * v9;
  nHeight = -MemRequired;
  while ( buf->m_Error == 0 )
  {
    CUtlBuffer::Get(this: buf, pMem: &pBitmap->m_pBits[v10], size: MemRequired);
    v10 += nHeight;
    if ( --v9 < 0 )
      return 1;
    MemRequired = nRowBytes;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CC80
// Name: enum BitmapFileType_t LoadBitmapFile(class CUtlBuffer __near &,struct Bitmap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadBitmapFile(CUtlBuffer *buf, Bitmap_t *pBitmap)
{
  int m_Get; // edi
  char Info; // bl
  float flGamma; // [esp+14h] [ebp-10h] BYREF
  int nWidth; // [esp+18h] [ebp-Ch] BYREF
  int nHeight; // [esp+1Ch] [ebp-8h] BYREF
  ImageFormat fmt; // [esp+20h] [ebp-4h] BYREF

  if ( IsPSDFile(buf) )
    return PSDReadFileRGBA8888(buf, bitmap: pBitmap) - 1;
  if ( IsPFMFile(buf) )
    return PFMReadFile(buf, pBitmap) != 0 ? 2 : -1;
  m_Get = buf->m_Get;
  Info = TGALoader::GetInfo(buf, width: &nWidth, height: &nHeight, imageFormat: &fmt, sourceGamma: &flGamma);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( Info == 0 )
    return -1;
  Bitmap_t::Init(this: pBitmap, nWidth, nHeight, imageFormat: fmt);
  return 2
       * (TGALoader::Load(
            pOutputImage: pBitmap->m_pBits,
            buf,
            width: nWidth,
            height: nHeight,
            imageFormat: fmt,
            targetGamma: flGamma,
            mipmap: false) != 0)
       - 1;
}
