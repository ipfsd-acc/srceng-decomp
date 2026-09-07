// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/tgaloader.cpp
// Functions: 17
// ============================================================

#include "bitmap\tgaloader.h"

//------------------------------------------------------------------------------
// Address: 0x0040B4D0
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B520
// Name: TGALoader::ReadFile
// Source: json
//------------------------------------------------------------------------------
bool __usercall TGALoader::ReadFile@<al>(
        const char *pFileName@<edx>,
        int maxbytes@<eax>,
        CUtlMemory<unsigned char,int> *image)
{
  void *v5; // esi
  int v6; // ebx

  if ( g_pFullFileSystem == nullptr )
    return false;
  v5 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: 0);
  if ( v5 == nullptr )
    return false;
  if ( maxbytes < 0 )
    maxbytes = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  CUtlMemory<unsigned char,int>::EnsureCapacity(this: image, num: maxbytes);
  g_pFullFileSystem->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  v6 = g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: image->m_pMemory, a3: maxbytes, a4: v5);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  return v6 == maxbytes;
}

//------------------------------------------------------------------------------
// Address: 0x0040B5D0
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B670
// Name: bool TGALoader::GetInfo(char const __near *,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(
        const char *pFileName,
        int *width,
        int *height,
        ImageFormat *imageFormat,
        float *sourceGamma)
{
  unsigned __int8 *m_pMemory; // esi
  char Info; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> image; // [esp+34h] [ebp-Ch] BYREF

  memset(&image, 0, sizeof(image));
  if ( TGALoader::ReadFile(pFileName, maxbytes: 18, &image) )
  {
    m_pMemory = image.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: image.m_pMemory, nSize: image.m_nAllocationCount, nFlags: 8);
    Info = TGALoader::GetInfo(&buf, width, height, imageFormat, sourceGamma);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( image.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return Info;
  }
  else
  {
    if ( image.m_nGrowSize >= 0 && image.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: image.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B740
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B8E0
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B950
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BA20
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BB30
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x0040BC60
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040BCD0
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040BD40
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040BDB0
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040BE20
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BED0
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BFD0
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C0F0
// Name: bool TGALoader::Load(unsigned char __near *,char const __near *,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        const char *pFileName,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  char v9; // bl
  CUtlBuffer buf; // [esp+14h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> vec; // [esp+44h] [ebp-Ch] BYREF

  memset(&vec, 0, sizeof(vec));
  if ( TGALoader::ReadFile(pFileName, maxbytes: -1, image: &vec) )
  {
    m_pMemory = vec.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: vec.m_pMemory, nSize: vec.m_nAllocationCount, nFlags: 8);
    v9 = TGALoader::Load(pOutputImage, &buf, width, height, imageFormat, targetGamma, mipmap);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( vec.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v9;
  }
  else
  {
    if ( vec.m_nGrowSize >= 0 && vec.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_pMemory);
    return 0;
  }
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004CFEF0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFF70
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CFFE0
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header.id_length, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0080
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D0120
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D02C0
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0330
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0400
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0510
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x004D0640
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004D06B0
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004D0720
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8u);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004D0790
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8u);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004D0800
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D08B0
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D09B0
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header.id_length, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace elementviewer

// ============================================================
// Overlay from height2normal (Missing functions)
// ============================================================
namespace height2normal {

//------------------------------------------------------------------------------
// Address: 0x00408020
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004080A0
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408140
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004081E0
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408380
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004083F0
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004084C0
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004085D0
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x00408700
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408770
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004087E0
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408850
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004088C0
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408970
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408A70
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace height2normal

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x0040CBF0
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC40
// Name: TGALoader::ReadFile
// Source: json
//------------------------------------------------------------------------------
bool __usercall TGALoader::ReadFile@<al>(
        const char *pFileName@<edx>,
        int maxbytes@<eax>,
        CUtlMemory<unsigned char,int> *image)
{
  void *v5; // esi
  int v6; // ebx

  if ( g_pFullFileSystem == nullptr )
    return false;
  v5 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: 0);
  if ( v5 == nullptr )
    return false;
  if ( maxbytes < 0 )
    maxbytes = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  CUtlMemory<unsigned char,int>::EnsureCapacity(this: image, num: maxbytes);
  g_pFullFileSystem->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  v6 = g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: image->m_pMemory, a3: maxbytes, a4: v5);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  return v6 == maxbytes;
}

//------------------------------------------------------------------------------
// Address: 0x0040CCF0
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CD90
// Name: bool TGALoader::GetInfo(char const __near *,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(
        const char *pFileName,
        int *width,
        int *height,
        ImageFormat *imageFormat,
        float *sourceGamma)
{
  unsigned __int8 *m_pMemory; // esi
  char Info; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> image; // [esp+34h] [ebp-Ch] BYREF

  memset(&image, 0, sizeof(image));
  if ( TGALoader::ReadFile(pFileName, maxbytes: 18, &image) )
  {
    m_pMemory = image.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: image.m_pMemory, nSize: image.m_nAllocationCount, nFlags: 8);
    Info = TGALoader::GetInfo(&buf, width, height, imageFormat, sourceGamma);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( image.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return Info;
  }
  else
  {
    if ( image.m_nGrowSize >= 0 && image.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: image.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CE60
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D000
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D070
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D140
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D250
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x0040D380
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040D3F0
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040D460
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040D4D0
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040D540
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D5F0
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D6F0
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D810
// Name: bool TGALoader::Load(unsigned char __near *,char const __near *,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        const char *pFileName,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  char v9; // bl
  CUtlBuffer buf; // [esp+14h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> vec; // [esp+44h] [ebp-Ch] BYREF

  memset(&vec, 0, sizeof(vec));
  if ( TGALoader::ReadFile(pFileName, maxbytes: -1, image: &vec) )
  {
    m_pMemory = vec.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: vec.m_pMemory, nSize: vec.m_nAllocationCount, nFlags: 8);
    v9 = TGALoader::Load(pOutputImage, &buf, width, height, imageFormat, targetGamma, mipmap);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( vec.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v9;
  }
  else
  {
    if ( vec.m_nGrowSize >= 0 && vec.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E840
// Name: public: void CUtlMemory<class Vector,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Vector,int>::Grow(CUtlMemory<Vector,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Vector *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Vector *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E8E0
// Name: public: void CUtlMemory<struct CacheOptimizedKDNode,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CacheOptimizedKDNode,int>::Grow(CUtlMemory<CacheOptimizedKDNode,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CacheOptimizedKDNode *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CacheOptimizedKDNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CacheOptimizedKDNode *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace height2ssbump

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10174BA0
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header.id_length, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174C40
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174DE0
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174E50
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174F20
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175030
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x10175160
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101751D0
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10175240
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8u);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101752B0
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8u);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10175320
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101753D0
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101754D0
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        unsigned __int8 *height,
        CUtlBuffer *imageFormat,
        float targetGamma,
        bool mipmap)
{
  void *v8; // esi
  float dstGamma; // [esp+10h] [ebp-20h] BYREF
  unsigned __int16 v10; // [esp+15h] [ebp-1Bh]
  unsigned __int8 v11; // [esp+17h] [ebp-19h]
  _BYTE header[20]; // [esp+1Ch] [ebp-14h] OVERLAPPED BYREF

  CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&dstGamma, size: 18);
  if ( LOBYTE(dstGamma) != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: LOBYTE(dstGamma));
  if ( v10 != 0 )
  {
    if ( v10 * (v11 >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: v10 * (v11 >> 3));
  }
  memset(&header[8], 0, 12);
  if ( TGALoader::ReadSourceImage(
         header: (TGALoader::TGAHeader_t *)&dstGamma,
         buf,
         image: (CUtlMemory<unsigned char,int> *)&header[8]) == 0
    || (int)height * width < *(unsigned __int16 *)&header[2] * *(unsigned __int16 *)header )
  {
    if ( *(int *)&header[16] >= 0 && *(_DWORD *)&header[8] != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&header[8]);
    return 0;
  }
  v8 = *(void **)&header[8];
  ImageLoader::GenerateMipmapLevels(
    pSrc: *(unsigned __int8 **)&header[8],
    pDst: pOutputImage,
    width: *(unsigned __int16 *)header,
    height: *(unsigned __int16 *)&header[2],
    depth: 1,
    (ImageFormat)imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( *(int *)&header[16] >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
  return 1;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10034390
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034410
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034460
// Name: TGALoader::ReadFile
// Source: json
//------------------------------------------------------------------------------
bool __usercall TGALoader::ReadFile@<al>(
        const char *pFileName@<edx>,
        int maxbytes@<eax>,
        CUtlMemory<unsigned char,int> *image)
{
  void *v5; // esi
  int v6; // ebx

  if ( g_pFullFileSystem == nullptr )
    return false;
  v5 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: 0);
  if ( v5 == nullptr )
    return false;
  if ( maxbytes < 0 )
    maxbytes = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  CUtlMemory<unsigned char,int>::EnsureCapacity(this: image, num: maxbytes);
  g_pFullFileSystem->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  v6 = g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: image->m_pMemory, a3: maxbytes, a4: v5);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  return v6 == maxbytes;
}

//------------------------------------------------------------------------------
// Address: 0x10034510
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100345B0
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034750
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100347C0
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034890
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100349A0
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x10034AD0
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10034B40
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10034BB0
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10034C20
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10034C90
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034D40
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034E40
// Name: bool TGALoader::LoadRGBA8888(class CUtlBuffer __near &,class CUtlMemory<unsigned char,int> __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::LoadRGBA8888(
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *outputData,
        int *outWidth,
        int *outHeight)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int height; // eax
  TGALoader::TGAHeader_t header; // [esp+4h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  MemRequired = ImageLoader::GetMemRequired(
                  width: header.width,
                  height: header.height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( outputData->m_nAllocationCount < MemRequired && outputData->m_nGrowSize >= 0 )
  {
    m_pMemory = outputData->m_pMemory;
    outputData->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    outputData->m_pMemory = v6;
  }
  if ( TGALoader::ReadSourceImage(&header, buf, image: outputData) == 0 )
    return 0;
  height = header.height;
  *outWidth = header.width;
  *outHeight = height;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034F20
// Name: bool TGALoader::LoadRGBA8888(char const __near *,class CUtlMemory<unsigned char,int> __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::LoadRGBA8888(
        const char *pFileName,
        CUtlMemory<unsigned char,int> *outputData,
        int *outWidth,
        int *outHeight)
{
  unsigned __int8 *m_pMemory; // esi
  char v6; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> vec; // [esp+34h] [ebp-Ch] BYREF

  memset(&vec, 0, sizeof(vec));
  if ( TGALoader::ReadFile(pFileName, maxbytes: -1, image: &vec) )
  {
    m_pMemory = vec.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: vec.m_pMemory, nSize: vec.m_nAllocationCount, nFlags: 8);
    v6 = TGALoader::LoadRGBA8888(&buf, outputData, outWidth, outHeight);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( vec.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v6;
  }
  else
  {
    if ( vec.m_nGrowSize >= 0 && vec.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_pMemory);
    return 0;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00470380
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004703D0
// Name: TGALoader::ReadFile
// Source: json
//------------------------------------------------------------------------------
bool __usercall TGALoader::ReadFile@<al>(
        const char *pFileName@<edx>,
        int maxbytes@<eax>,
        CUtlMemory<unsigned char,int> *image)
{
  void *v5; // esi
  int v6; // ebx

  if ( g_pFullFileSystem == nullptr )
    return false;
  v5 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: 0);
  if ( v5 == nullptr )
    return false;
  if ( maxbytes < 0 )
    maxbytes = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  CUtlMemory<unsigned char,int>::EnsureCapacity(this: image, num: maxbytes);
  g_pFullFileSystem->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  v6 = g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: image->m_pMemory, a3: maxbytes, a4: v5);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  return v6 == maxbytes;
}

//------------------------------------------------------------------------------
// Address: 0x00470480
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header.id_length, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470520
// Name: bool TGALoader::GetInfo(char const __near *,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(
        const char *pFileName,
        int *width,
        int *height,
        ImageFormat *imageFormat,
        float *sourceGamma)
{
  unsigned __int8 *m_pMemory; // esi
  char Info; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> image; // [esp+34h] [ebp-Ch] BYREF

  memset(&image, 0, sizeof(image));
  if ( TGALoader::ReadFile(pFileName, maxbytes: 18, &image) )
  {
    m_pMemory = image.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: image.m_pMemory, nSize: image.m_nAllocationCount, nFlags: 8u);
    Info = TGALoader::GetInfo(&buf, width, height, imageFormat, sourceGamma);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( image.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return Info;
  }
  else
  {
    if ( image.m_nGrowSize >= 0 && image.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: image.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004705F0
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470790
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470800
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004708D0
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004709E0
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x00470B10
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00470B80
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00470BF0
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8u);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00470C60
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8u);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00470CD0
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470D80
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00470E80
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header.id_length, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00470FA0
// Name: bool TGALoader::Load(unsigned char __near *,char const __near *,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        const char *pFileName,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  char v9; // bl
  CUtlBuffer buf; // [esp+14h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> vec; // [esp+44h] [ebp-Ch] BYREF

  memset(&vec, 0, sizeof(vec));
  if ( TGALoader::ReadFile(pFileName, maxbytes: -1, image: &vec) )
  {
    m_pMemory = vec.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: vec.m_pMemory, nSize: vec.m_nAllocationCount, nFlags: 8u);
    v9 = TGALoader::Load(pOutputImage, &buf, width, height, imageFormat, targetGamma, mipmap);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( vec.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v9;
  }
  else
  {
    if ( vec.m_nGrowSize >= 0 && vec.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_pMemory);
    return 0;
  }
}

} // namespace mksheet

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004EAC80
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAD20
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAEC0
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAF30
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EB000
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EB110
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x004EB240
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004EB2B0
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004EB320
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004EB390
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004EB400
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EB4B0
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB5B0
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace sceneviewer

// ============================================================
// Overlay from tgadiff (Missing functions)
// ============================================================
namespace tgadiff {

//------------------------------------------------------------------------------
// Address: 0x00407CE0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407D60
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407E00
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407EA0
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408040
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004080B0
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408180
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408290
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x004083C0
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408430
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004084A0
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408510
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408580
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408630
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408730
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408C70
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408C80
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408CD0
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *lpThreadParameter)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*lpThreadParameter + 32))(
         a1: *lpThreadParameter,
         a2: lpThreadParameter[1],
         a3: lpThreadParameter[2],
         a4: lpThreadParameter[3],
         a5: lpThreadParameter[4],
         a6: lpThreadParameter[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004097C0
// Name: void S3TCencode(struct _DDSURFACEDESC __near *,struct tagPALETTEENTRY __near *,struct _DDSURFACEDESC __near *,void __near *,unsigned int,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl S3TCencode(
        struct _DDSURFACEDESC *a1,
        struct tagPALETTEENTRY *a2,
        struct _DDSURFACEDESC *a3,
        void *a4,
        unsigned int a5,
        float *a6)
{
  unsigned int v6; // ebx
  struct _DDSURFACEDESC *v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  int i; // edx
  unsigned int dwRGBAlphaBitMask; // edx
  int v12; // ecx
  unsigned int j; // eax
  signed int dwHeight; // eax
  signed int dwWidth; // edx
  int k; // eax
  int v17; // ebx
  _DWORD *v18; // edi
  int v19; // esi
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  double v23; // st7
  int v24; // esi
  int v25; // edi
  int v26; // eax
  _BYTE *v27; // edi
  int jj; // eax
  unsigned int v29; // edi
  _DWORD *v30; // esi
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  _DWORD *v38; // esi
  char v39; // di
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  __int64 v44; // rax
  int v45; // ecx
  int v46; // edi
  unsigned __int8 *v47; // esi
  int v48; // eax
  struct tagPALETTEENTRY *v49; // eax
  unsigned int v50; // ecx
  double *v51; // ecx
  bool v52; // cc
  int v53; // edi
  int v54; // eax
  int nn; // edx
  int v56; // eax
  struct tagPALETTEENTRY *v57; // ecx
  double *v58; // eax
  int v59; // edi
  int v60; // ecx
  unsigned int *v61; // edx
  int v62; // eax
  unsigned int v63; // esi
  double *v64; // edx
  int v65; // eax
  double v66; // st7
  unsigned int v67; // ebx
  unsigned int v68; // eax
  double *v69; // esi
  int v70; // ebx
  int i1; // edx
  int v72; // ecx
  unsigned int v73; // edi
  char *v74; // esi
  int v75; // eax
  int v76; // edx
  int v77; // ecx
  unsigned int v78; // edi
  double *v79; // esi
  int i2; // edx
  unsigned int v81; // eax
  int v82; // ecx
  _DWORD *v83; // eax
  int i3; // ecx
  int v85; // ecx
  char *v86; // eax
  __int16 v87; // dx
  unsigned __int16 v88; // dx
  unsigned __int16 v89; // cx
  bool v90; // cf
  int v91; // eax
  __int16 v92; // ax
  int v93; // ebx
  _DWORD *v94; // esi
  int *v95; // edx
  int v96; // eax
  int i4; // edi
  int lPitch; // edx
  int v99; // [esp+18h] [ebp-888h]
  int v100; // [esp+18h] [ebp-888h]
  int m; // [esp+18h] [ebp-888h]
  int v102; // [esp+18h] [ebp-888h]
  int v103; // [esp+18h] [ebp-888h]
  int v104; // [esp+18h] [ebp-888h]
  int v105; // [esp+18h] [ebp-888h]
  int v106; // [esp+18h] [ebp-888h]
  int v107; // [esp+1Ch] [ebp-884h]
  int kk; // [esp+1Ch] [ebp-884h]
  int n; // [esp+1Ch] [ebp-884h]
  int mm; // [esp+1Ch] [ebp-884h]
  int v111; // [esp+1Ch] [ebp-884h]
  int v112; // [esp+1Ch] [ebp-884h]
  int v113; // [esp+1Ch] [ebp-884h]
  int *v114; // [esp+1Ch] [ebp-884h]
  int ii; // [esp+20h] [ebp-880h]
  int v116; // [esp+20h] [ebp-880h]
  int v117; // [esp+20h] [ebp-880h]
  int v118; // [esp+20h] [ebp-880h]
  int v119; // [esp+20h] [ebp-880h]
  int v120; // [esp+20h] [ebp-880h]
  int v121; // [esp+20h] [ebp-880h]
  int v122; // [esp+20h] [ebp-880h]
  int v123; // [esp+24h] [ebp-87Ch]
  int v124; // [esp+24h] [ebp-87Ch]
  int v125; // [esp+24h] [ebp-87Ch]
  int v126; // [esp+28h] [ebp-878h]
  unsigned int *v127; // [esp+28h] [ebp-878h]
  unsigned int v128; // [esp+2Ch] [ebp-874h]
  _WORD *v129; // [esp+30h] [ebp-870h]
  int v130; // [esp+34h] [ebp-86Ch]
  int v131; // [esp+38h] [ebp-868h]
  int v132; // [esp+3Ch] [ebp-864h]
  _DWORD *v133; // [esp+40h] [ebp-860h]
  int v134; // [esp+44h] [ebp-85Ch]
  int v135; // [esp+48h] [ebp-858h]
  int v136; // [esp+4Ch] [ebp-854h]
  int v137; // [esp+50h] [ebp-850h]
  char *lpSurface; // [esp+54h] [ebp-84Ch]
  signed int v139; // [esp+58h] [ebp-848h]
  _DWORD v140[3]; // [esp+5Ch] [ebp-844h] BYREF
  int v141; // [esp+68h] [ebp-838h]
  unsigned int v142; // [esp+6Ch] [ebp-834h]
  unsigned int v143; // [esp+70h] [ebp-830h]
  unsigned int v144; // [esp+74h] [ebp-82Ch]
  __int64 v145; // [esp+78h] [ebp-828h]
  __int64 v146; // [esp+80h] [ebp-820h]
  __int64 v147; // [esp+88h] [ebp-818h]
  __int64 v148; // [esp+90h] [ebp-810h]
  __int64 v149; // [esp+98h] [ebp-808h]
  __int64 v150; // [esp+A0h] [ebp-800h]
  __int64 v151; // [esp+A8h] [ebp-7F8h]
  __int64 v152; // [esp+B0h] [ebp-7F0h]
  __int64 v153; // [esp+B8h] [ebp-7E8h]
  __int64 v154; // [esp+C0h] [ebp-7E0h]
  _DWORD v155[48]; // [esp+C8h] [ebp-7D8h] BYREF
  float v156[51]; // [esp+188h] [ebp-718h] BYREF
  int v157; // [esp+254h] [ebp-64Ch]
  int v158; // [esp+258h] [ebp-648h]
  int v159; // [esp+25Ch] [ebp-644h]
  _DWORD v160[48]; // [esp+260h] [ebp-640h]
  double v161[176]; // [esp+320h] [ebp-580h] BYREF

  v6 = a5 & 0xFF00;
  v143 = v6;
  if ( (a5 & 0xFF00) != 0 )
  {
    if ( v6 == 256 || v6 == 512 )
      bS3TCForce4 = true;
  }
  else
  {
    bS3TCForce4 = false;
  }
  v7 = a1;
  a3->dwFlags = 6150;
  a3->dwWidth = a1->dwWidth;
  a3->dwHeight = a1->dwHeight;
  a3->lpSurface = a4;
  a3->ddpfPixelFormat.dwSize = 32;
  a3->ddpfPixelFormat.dwFlags = 4;
  a3->ddpfPixelFormat.dwRGBBitCount = a5;
  a3->ddpfPixelFormat.dwFourCC = 305419896;
  v128 = (a1->ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
  v8 = 0;
  v135 = (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140;
  do
  {
    v9 = *(_DWORD *)((char *)&v140[v8] + (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140);
    for ( i = 0; (v9 & 1) == 0; ++i )
      v9 >>= 1;
    v140[v8++] = i;
  }
  while ( v8 < 3 );
  if ( (a5 & 0xFF00) != 0 )
  {
    dwRGBAlphaBitMask = a1->ddpfPixelFormat.dwRGBAlphaBitMask;
    v12 = 0;
    for ( j = dwRGBAlphaBitMask; (j & 1) == 0; ++v12 )
      j >>= 1;
    v137 = v12;
    v144 = (dword_49CE20 * (dwRGBAlphaBitMask >> v12) / 0xFF) << v12;
  }
  lpSurface = (char *)a1->lpSurface;
  dwHeight = a1->dwHeight;
  v129 = a4;
  v136 = 0;
  if ( dwHeight > 0 )
  {
    while ( 1 )
    {
      v131 = dwHeight - v136;
      if ( (unsigned int)(dwHeight - v136) >= 4 )
        v131 = 4;
      v139 = 0;
      v133 = lpSurface;
      dwWidth = v7->dwWidth;
      if ( dwWidth > 0 )
        break;
LABEL_171:
      lPitch = a1->lPitch;
      dwHeight = a1->dwHeight;
      v52 = v136 + 4 < dwHeight;
      v136 += 4;
      lpSurface += 4 * lPitch;
      if ( !v52 )
        return;
      v7 = a1;
    }
    v141 = (unsigned __int8)a5;
    while ( 1 )
    {
      memset(v161, 0, sizeof(v161));
      memset(v155, 0xFFu, sizeof(v155));
      for ( k = 0; k < 3; v161[k + 144] = a6[k - 1] )
        ++k;
      v130 = dwWidth - v139;
      if ( dwWidth - v139 >= (unsigned int)S3TC_BLOCK_WIDTH )
        v130 = S3TC_BLOCK_WIDTH;
      v17 = 0;
      LODWORD(v161[0]) = 0;
      if ( v143 == 256 )
      {
        v38 = v133;
        v39 = v137;
        v40 = S3TC_BLOCK_WIDTH;
        v41 = 0;
        for ( m = 0; m < 4; v41 = m )
        {
          if ( v41 >= v131 )
          {
            *v129 = 0;
          }
          else
          {
            v42 = 0;
            for ( n = 0; v42 < v40; n = v42 )
            {
              if ( v42 >= v130 )
              {
                LOWORD(v134) = (unsigned __int16)v134 >> 4;
              }
              else
              {
                v43 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v39;
                v152 = (*v38 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v39;
                v148 = v43;
                v44 = (__int64)floor(X: (double)v152 / (double)v43 * 15.0 + 0.5);
                v17 = LODWORD(v161[0]);
                LOWORD(v45) = (unsigned __int16)v134 >> 4;
                LODWORD(v44) = v45 | ((_DWORD)v44 << 12);
                v40 = S3TC_BLOCK_WIDTH;
                v134 = v44;
                v42 = n;
              }
              ++v42;
              v38 = (_DWORD *)((char *)v38 + v128);
            }
            *v129 = v134;
          }
          ++v129;
          v40 = S3TC_BLOCK_WIDTH;
          ++m;
          v38 = (_DWORD *)((char *)v38 + a1->lPitch - v128 * S3TC_BLOCK_WIDTH);
        }
        goto LABEL_82;
      }
      if ( v143 != 512 )
        goto LABEL_82;
      v18 = v133;
      v19 = 0;
      v20 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
      v156[0] = 0.0;
      v99 = 0;
      v107 = v20;
      do
      {
        for ( ii = 0; ii < S3TC_BLOCK_WIDTH; ++ii )
        {
          if ( ii >= v130 || v99 >= v131 )
          {
            v155[v19++] = -1;
          }
          else
          {
            v21 = (*v18 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v137;
            v22 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v137;
            v155[v19++] = LODWORD(v156[0]);
            if ( v21 == v22 )
            {
              v23 = 1.0;
            }
            else
            {
              v150 = v21;
              v151 = v22;
              v23 = (double)v21 / (double)v22;
            }
            v156[++LODWORD(v156[0])] = v23;
          }
          v18 = (_DWORD *)((char *)v18 + v128);
        }
        v18 = (_DWORD *)((char *)v18 + v107);
        ++v99;
      }
      while ( v99 < 4 );
      v24 = 0;
      v156[49] = 0.0;
      v156[50] = 0.0;
      if ( LODWORD(v156[0]) != 0 )
      {
        CodeAlphaBlock(a1: v156);
        v24 = v158;
        v25 = v159;
        v17 = LODWORD(v161[0]);
        if ( v158 != v159 )
          goto LABEL_45;
      }
      else
      {
        v25 = 0;
        v158 = 0;
      }
      ++v25;
      v26 = 0;
      v159 = v25;
      if ( SLODWORD(v156[0]) > 0 )
      {
        do
          v160[v26++] = 0;
        while ( v26 < SLODWORD(v156[0]) );
        v24 = v158;
        v25 = v159;
      }
      v157 = 6;
LABEL_45:
      if ( v24 > v25 == (v157 == 6) )
      {
        v158 = v25;
        v159 = v24;
        v116 = 1;
      }
      else
      {
        v116 = 0;
      }
      v27 = v129;
      for ( jj = 0; jj < 2; ++jj )
        *v27++ = *((_BYTE *)&v158 + 4 * jj);
      v129 = v27;
      v123 = 0;
      v126 = 0;
      memset(v27, 0, 6 * (S3TC_BLOCK_WIDTH / 4));
      v29 = 0;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v30 = v129;
        while ( 1 )
        {
          v31 = v123;
          v100 = 0;
          do
          {
            for ( kk = 4; kk != 0; --kk )
            {
              v32 = v155[v31];
              v29 >>= 3;
              if ( v32 < 0 )
                goto LABEL_66;
              v33 = v160[v32];
              if ( v116 != 0 )
              {
                if ( v157 == 8 )
                {
                  if ( v33 > 1 )
                  {
                    v34 = 9 - v33;
LABEL_64:
                    v33 = v34;
                    goto LABEL_65;
                  }
                }
                else
                {
                  if ( v157 != 6 || v33 > 5 )
                    goto LABEL_65;
                  if ( v33 > 1 )
                  {
                    v34 = 7 - v33;
                    goto LABEL_64;
                  }
                }
                v34 = v33 == 0;
                goto LABEL_64;
              }
LABEL_65:
              v29 |= v33 << 21;
LABEL_66:
              ++v31;
            }
            v35 = v100;
            if ( (v100 & 1) != 0 )
            {
              v36 = *v30;
              v30 = (_DWORD *)((char *)v30 + 3);
              v37 = v29 | v36;
              v29 = 0;
              *(_DWORD *)((char *)v30 - 3) = v37;
            }
            ++v100;
          }
          while ( v35 + 1 < 4 );
          v123 = v31;
          if ( ++v126 >= S3TC_BLOCK_WIDTH / 4 )
          {
            v129 = v30;
            break;
          }
        }
      }
LABEL_82:
      v46 = 0;
      if ( a2 != nullptr )
      {
        v47 = (unsigned __int8 *)v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v102 = 0;
            v117 = a1->lPitch;
            do
            {
              v48 = 0;
              for ( mm = 0; mm < 4; ++mm )
              {
                if ( v48 >= v130
                  || v102 >= v131
                  || (v49 = &a2[*v47], (v50 = *(_DWORD *)v49 & 0xFFFFFF) >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v50 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v46++] = -1;
                }
                else
                {
                  v155[v46++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v51 = &v161[3 * v17 + 2];
                  *(v51 - 1) = (double)v49->peRed * 0.00392156862745098;
                  *v51 = (double)v49->peGreen * 0.00392156862745098;
                  v51[1] = (double)v49->peBlue * 0.00392156862745098;
                  v17 = LODWORD(v161[0]);
                }
                v48 = mm + 1;
                ++v47;
              }
              v52 = ++v102 < 4;
              v47 = &v47[v117 - 4];
            }
            while ( v52 );
          }
        }
        else
        {
          v53 = 0;
          v54 = 0;
          v103 = 0;
          v118 = a1->lPitch;
          do
          {
            for ( nn = 0; nn < 4; ++nn )
            {
              if ( nn >= v130 || v54 >= v131 )
              {
                v155[v53++] = -1;
              }
              else
              {
                v56 = *v47;
                v155[v53++] = v17;
                v57 = &a2[v56];
                LODWORD(v161[0]) = v17 + 1;
                v58 = &v161[3 * v17 + 2];
                *(v58 - 1) = (double)v57->peRed * 0.00392156862745098;
                *v58 = (double)v57->peGreen * 0.00392156862745098;
                v58[1] = (double)v57->peBlue * 0.00392156862745098;
                v17 = LODWORD(v161[0]);
                v54 = v103;
              }
              ++v47;
            }
            v103 = ++v54;
            v47 = &v47[v118 - 4];
          }
          while ( v54 < 4 );
        }
      }
      else
      {
        v127 = v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v124 = 0;
            v105 = 0;
            v112 = a1->lPitch - 4 * v128;
            do
            {
              v120 = 0;
              do
              {
                if ( v120 >= v130
                  || v105 >= v131
                  || (v68 = *v127, v142 = v68, v68 >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v68 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v124++] = -1;
                }
                else
                {
                  v155[v124] = v17;
                  v69 = &v161[3 * v17 + 1];
                  LODWORD(v161[0]) = v17 + 1;
                  v70 = v135;
                  ++v124;
                  for ( i1 = 0; i1 < 3; ++i1 )
                  {
                    v72 = v140[i1];
                    ++v69;
                    v73 = (v142 & *(_DWORD *)((char *)&v140[i1] + v70)) >> v72;
                    v146 = (unsigned int)(*(_DWORD *)((char *)&v140[i1] + v70) >> v72);
                    v153 = v73;
                    *(v69 - 1) = (double)v73 / (double)v146;
                  }
                  v17 = LODWORD(v161[0]);
                }
                v74 = (char *)v127 + v128;
                v52 = ++v120 < 4;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v52 );
              v52 = ++v105 < 4;
              v127 = (unsigned int *)&v74[v112];
            }
            while ( v52 );
          }
          else if ( v141 == 2 )
          {
            v59 = 0;
            v60 = 0;
            v104 = 0;
            v111 = a1->lPitch - 4 * v128;
            do
            {
              v61 = v127;
              v62 = 0;
              v119 = 0;
              do
              {
                if ( v62 >= v130 || v60 >= v131 || (v63 = *v61, (*v61 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) <= v144) )
                {
                  v155[v59++] = -1;
                }
                else
                {
                  v155[v59++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v64 = &v161[3 * v17 + 1];
                  v65 = 0;
                  v154 = *(&a1->ddpfPixelFormat.dwRBitMask + v59) >> v140[v59];
                  v66 = (double)v154;
                  do
                  {
                    ++v64;
                    v67 = (v63 & *(_DWORD *)((char *)&v140[v65] + v135)) >> v140[v65];
                    ++v65;
                    v145 = v67;
                    *(v64 - 1) = (double)v67 / v66;
                  }
                  while ( v65 < 3 );
                  v17 = LODWORD(v161[0]);
                  v62 = v119;
                  v60 = v104;
                }
                ++v62;
                v61 = (unsigned int *)((char *)v127 + v128);
                v119 = v62;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v62 < 4 );
              v104 = ++v60;
              v127 = (unsigned int *)((char *)v61 + v111);
            }
            while ( v60 < 4 );
          }
        }
        else
        {
          v75 = 0;
          v76 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
          v106 = 0;
          v113 = v76;
          do
          {
            v77 = 0;
            v121 = 0;
            if ( S3TC_BLOCK_WIDTH > 0 )
            {
              do
              {
                if ( v77 >= v130 || v46 >= v131 )
                {
                  v155[v75++] = -1;
                }
                else
                {
                  v155[v75] = v17;
                  v78 = *v127;
                  v79 = &v161[3 * v17 + 1];
                  v125 = v75 + 1;
                  LODWORD(v161[0]) = v17 + 1;
                  for ( i2 = 0; i2 < 3; ++i2 )
                  {
                    ++v79;
                    v81 = *(_DWORD *)((char *)&v140[i2] + v135);
                    v82 = v140[i2];
                    v147 = (v81 & v78) >> v82;
                    v149 = v81 >> v82;
                    *(v79 - 1) = (double)v147 / (double)v149;
                  }
                  v17 = LODWORD(v161[0]);
                  v75 = v125;
                  v77 = v121;
                  v46 = v106;
                }
                ++v77;
                v127 = (unsigned int *)((char *)v127 + v128);
                v121 = v77;
              }
              while ( v77 < S3TC_BLOCK_WIDTH );
              v76 = v113;
            }
            v106 = ++v46;
            v127 = (unsigned int *)((char *)v127 + v76);
          }
          while ( v46 < 4 );
        }
      }
      LODWORD(v161[148]) = (v17 >= v131 * v130) + 3;
      if ( v17 != 0 )
      {
        CodeRGBBlock(a1: v161);
      }
      else
      {
        v83 = (_DWORD *)&v161[149] + 1;
        for ( i3 = 2; i3 != 0; --i3 )
        {
          v83[1] = 0;
          *v83 = 0;
          *(v83 - 1) = 0;
          v83 += 3;
        }
      }
      v85 = 0;
      v86 = (char *)&v161[149] + 4;
      do
      {
        v87 = *((_WORD *)v86 - 2);
        v86 += 12;
        *((_WORD *)&v131 + ++v85 + 1) = *((_WORD *)v86 - 4) | (32 * (*((_WORD *)v86 - 6) | (v87 << 6)));
      }
      while ( v85 < 2 );
      v89 = HIWORD(v132);
      v88 = v132;
      v90 = HIWORD(v132) < (unsigned __int16)v132;
      if ( HIWORD(v132) == (_WORD)v132 )
      {
        v89 = HIWORD(v132) + 1;
        v91 = 0;
        ++HIWORD(v132);
        if ( SLODWORD(v161[0]) > 0 )
        {
          do
            *((_DWORD *)&v161[152] + v91++) = 0;
          while ( v91 < SLODWORD(v161[0]) );
        }
        HIDWORD(v161[148]) = 3;
        v90 = v89 < v88;
      }
      if ( v90 == (HIDWORD(v161[148]) == 3) )
      {
        v92 = v132;
        LOWORD(v132) = v89;
        HIWORD(v132) = v92;
        v122 = 1;
      }
      else
      {
        v122 = 0;
      }
      v93 = 0;
      *(_DWORD *)v129 = v132;
      v94 = v129 + 2;
      v129 += 2;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v114 = &v155[15];
        do
        {
          v95 = v114;
          v96 = 0;
          for ( i4 = 16; i4 != 0; --i4 )
          {
            v96 *= 4;
            if ( *v95 >= 0 )
            {
              v96 |= *((_DWORD *)&v161[152] + *v95);
              if ( v122 != 0 )
              {
                if ( HIDWORD(v161[148]) == 4 )
                  v96 ^= 1u;
                else
                  v96 ^= (~v96 & 2) != 0;
              }
            }
            else
            {
              LOBYTE(v96) = v96 | 3;
            }
            --v95;
          }
          *v94 = v96;
          v114 += 16;
          ++v94;
          ++v93;
        }
        while ( v93 < S3TC_BLOCK_WIDTH / 4 );
        v129 = v94;
      }
      v133 += v128;
      v139 += 4;
      dwWidth = a1->dwWidth;
      if ( v139 >= dwWidth )
        goto LABEL_171;
    }
  }
}

} // namespace tgadiff

// ============================================================
// Overlay from tgamse (Missing functions)
// ============================================================
namespace tgamse {

//------------------------------------------------------------------------------
// Address: 0x00407910
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407990
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407A30
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407AD0
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407C70
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407DB0
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407EC0
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x00407FF0
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408060
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004080D0
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004081B0
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408260
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408360
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408480
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl GetProcessorCount()
{
  struct _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x004088A0
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004088B0
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408900
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *lpThreadParameter)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*lpThreadParameter + 32))(
         a1: *lpThreadParameter,
         a2: lpThreadParameter[1],
         a3: lpThreadParameter[2],
         a4: lpThreadParameter[3],
         a5: lpThreadParameter[4],
         a6: lpThreadParameter[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004093F0
// Name: void S3TCencode(struct _DDSURFACEDESC __near *,struct tagPALETTEENTRY __near *,struct _DDSURFACEDESC __near *,void __near *,unsigned int,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl S3TCencode(
        struct _DDSURFACEDESC *a1,
        struct tagPALETTEENTRY *a2,
        struct _DDSURFACEDESC *a3,
        void *a4,
        unsigned int a5,
        float *a6)
{
  unsigned int v6; // ebx
  struct _DDSURFACEDESC *v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  int i; // edx
  unsigned int dwRGBAlphaBitMask; // edx
  int v12; // ecx
  unsigned int j; // eax
  signed int dwHeight; // eax
  signed int dwWidth; // edx
  int k; // eax
  int v17; // ebx
  _DWORD *v18; // edi
  int v19; // esi
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  double v23; // st7
  int v24; // esi
  int v25; // edi
  int v26; // eax
  _BYTE *v27; // edi
  int jj; // eax
  unsigned int v29; // edi
  _DWORD *v30; // esi
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  _DWORD *v38; // esi
  char v39; // di
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  __int64 v44; // rax
  int v45; // ecx
  int v46; // edi
  unsigned __int8 *v47; // esi
  int v48; // eax
  struct tagPALETTEENTRY *v49; // eax
  unsigned int v50; // ecx
  double *v51; // ecx
  bool v52; // cc
  int v53; // edi
  int v54; // eax
  int nn; // edx
  int v56; // eax
  struct tagPALETTEENTRY *v57; // ecx
  double *v58; // eax
  int v59; // edi
  int v60; // ecx
  unsigned int *v61; // edx
  int v62; // eax
  unsigned int v63; // esi
  double *v64; // edx
  int v65; // eax
  double v66; // st7
  unsigned int v67; // ebx
  unsigned int v68; // eax
  double *v69; // esi
  int v70; // ebx
  int i1; // edx
  int v72; // ecx
  unsigned int v73; // edi
  char *v74; // esi
  int v75; // eax
  int v76; // edx
  int v77; // ecx
  unsigned int v78; // edi
  double *v79; // esi
  int i2; // edx
  unsigned int v81; // eax
  int v82; // ecx
  _DWORD *v83; // eax
  int i3; // ecx
  int v85; // ecx
  char *v86; // eax
  __int16 v87; // dx
  unsigned __int16 v88; // dx
  unsigned __int16 v89; // cx
  bool v90; // cf
  int v91; // eax
  __int16 v92; // ax
  int v93; // ebx
  _DWORD *v94; // esi
  int *v95; // edx
  int v96; // eax
  int i4; // edi
  int lPitch; // edx
  int v99; // [esp+18h] [ebp-888h]
  int v100; // [esp+18h] [ebp-888h]
  int m; // [esp+18h] [ebp-888h]
  int v102; // [esp+18h] [ebp-888h]
  int v103; // [esp+18h] [ebp-888h]
  int v104; // [esp+18h] [ebp-888h]
  int v105; // [esp+18h] [ebp-888h]
  int v106; // [esp+18h] [ebp-888h]
  int v107; // [esp+1Ch] [ebp-884h]
  int kk; // [esp+1Ch] [ebp-884h]
  int n; // [esp+1Ch] [ebp-884h]
  int mm; // [esp+1Ch] [ebp-884h]
  int v111; // [esp+1Ch] [ebp-884h]
  int v112; // [esp+1Ch] [ebp-884h]
  int v113; // [esp+1Ch] [ebp-884h]
  int *v114; // [esp+1Ch] [ebp-884h]
  int ii; // [esp+20h] [ebp-880h]
  int v116; // [esp+20h] [ebp-880h]
  int v117; // [esp+20h] [ebp-880h]
  int v118; // [esp+20h] [ebp-880h]
  int v119; // [esp+20h] [ebp-880h]
  int v120; // [esp+20h] [ebp-880h]
  int v121; // [esp+20h] [ebp-880h]
  int v122; // [esp+20h] [ebp-880h]
  int v123; // [esp+24h] [ebp-87Ch]
  int v124; // [esp+24h] [ebp-87Ch]
  int v125; // [esp+24h] [ebp-87Ch]
  int v126; // [esp+28h] [ebp-878h]
  unsigned int *v127; // [esp+28h] [ebp-878h]
  unsigned int v128; // [esp+2Ch] [ebp-874h]
  _WORD *v129; // [esp+30h] [ebp-870h]
  int v130; // [esp+34h] [ebp-86Ch]
  int v131; // [esp+38h] [ebp-868h]
  int v132; // [esp+3Ch] [ebp-864h]
  _DWORD *v133; // [esp+40h] [ebp-860h]
  int v134; // [esp+44h] [ebp-85Ch]
  int v135; // [esp+48h] [ebp-858h]
  int v136; // [esp+4Ch] [ebp-854h]
  int v137; // [esp+50h] [ebp-850h]
  char *lpSurface; // [esp+54h] [ebp-84Ch]
  signed int v139; // [esp+58h] [ebp-848h]
  _DWORD v140[3]; // [esp+5Ch] [ebp-844h] BYREF
  int v141; // [esp+68h] [ebp-838h]
  unsigned int v142; // [esp+6Ch] [ebp-834h]
  unsigned int v143; // [esp+70h] [ebp-830h]
  unsigned int v144; // [esp+74h] [ebp-82Ch]
  __int64 v145; // [esp+78h] [ebp-828h]
  __int64 v146; // [esp+80h] [ebp-820h]
  __int64 v147; // [esp+88h] [ebp-818h]
  __int64 v148; // [esp+90h] [ebp-810h]
  __int64 v149; // [esp+98h] [ebp-808h]
  __int64 v150; // [esp+A0h] [ebp-800h]
  __int64 v151; // [esp+A8h] [ebp-7F8h]
  __int64 v152; // [esp+B0h] [ebp-7F0h]
  __int64 v153; // [esp+B8h] [ebp-7E8h]
  __int64 v154; // [esp+C0h] [ebp-7E0h]
  _DWORD v155[48]; // [esp+C8h] [ebp-7D8h] BYREF
  float v156[51]; // [esp+188h] [ebp-718h] BYREF
  int v157; // [esp+254h] [ebp-64Ch]
  int v158; // [esp+258h] [ebp-648h]
  int v159; // [esp+25Ch] [ebp-644h]
  _DWORD v160[48]; // [esp+260h] [ebp-640h]
  double v161[176]; // [esp+320h] [ebp-580h] BYREF

  v6 = a5 & 0xFF00;
  v143 = v6;
  if ( (a5 & 0xFF00) != 0 )
  {
    if ( v6 == 256 || v6 == 512 )
      bS3TCForce4 = true;
  }
  else
  {
    bS3TCForce4 = false;
  }
  v7 = a1;
  a3->dwFlags = 6150;
  a3->dwWidth = a1->dwWidth;
  a3->dwHeight = a1->dwHeight;
  a3->lpSurface = a4;
  a3->ddpfPixelFormat.dwSize = 32;
  a3->ddpfPixelFormat.dwFlags = 4;
  a3->ddpfPixelFormat.dwRGBBitCount = a5;
  a3->ddpfPixelFormat.dwFourCC = 305419896;
  v128 = (a1->ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
  v8 = 0;
  v135 = (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140;
  do
  {
    v9 = *(_DWORD *)((char *)&v140[v8] + (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140);
    for ( i = 0; (v9 & 1) == 0; ++i )
      v9 >>= 1;
    v140[v8++] = i;
  }
  while ( v8 < 3 );
  if ( (a5 & 0xFF00) != 0 )
  {
    dwRGBAlphaBitMask = a1->ddpfPixelFormat.dwRGBAlphaBitMask;
    v12 = 0;
    for ( j = dwRGBAlphaBitMask; (j & 1) == 0; ++v12 )
      j >>= 1;
    v137 = v12;
    v144 = (dword_49CDD0 * (dwRGBAlphaBitMask >> v12) / 0xFF) << v12;
  }
  lpSurface = (char *)a1->lpSurface;
  dwHeight = a1->dwHeight;
  v129 = a4;
  v136 = 0;
  if ( dwHeight > 0 )
  {
    while ( 1 )
    {
      v131 = dwHeight - v136;
      if ( (unsigned int)(dwHeight - v136) >= 4 )
        v131 = 4;
      v139 = 0;
      v133 = lpSurface;
      dwWidth = v7->dwWidth;
      if ( dwWidth > 0 )
        break;
LABEL_171:
      lPitch = a1->lPitch;
      dwHeight = a1->dwHeight;
      v52 = v136 + 4 < dwHeight;
      v136 += 4;
      lpSurface += 4 * lPitch;
      if ( !v52 )
        return;
      v7 = a1;
    }
    v141 = (unsigned __int8)a5;
    while ( 1 )
    {
      memset(v161, 0, sizeof(v161));
      memset(v155, 0xFFu, sizeof(v155));
      for ( k = 0; k < 3; v161[k + 144] = a6[k - 1] )
        ++k;
      v130 = dwWidth - v139;
      if ( dwWidth - v139 >= (unsigned int)S3TC_BLOCK_WIDTH )
        v130 = S3TC_BLOCK_WIDTH;
      v17 = 0;
      LODWORD(v161[0]) = 0;
      if ( v143 == 256 )
      {
        v38 = v133;
        v39 = v137;
        v40 = S3TC_BLOCK_WIDTH;
        v41 = 0;
        for ( m = 0; m < 4; v41 = m )
        {
          if ( v41 >= v131 )
          {
            *v129 = 0;
          }
          else
          {
            v42 = 0;
            for ( n = 0; v42 < v40; n = v42 )
            {
              if ( v42 >= v130 )
              {
                LOWORD(v134) = (unsigned __int16)v134 >> 4;
              }
              else
              {
                v43 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v39;
                v152 = (*v38 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v39;
                v148 = v43;
                v44 = (__int64)floor(X: (double)v152 / (double)v43 * 15.0 + 0.5);
                v17 = LODWORD(v161[0]);
                LOWORD(v45) = (unsigned __int16)v134 >> 4;
                LODWORD(v44) = v45 | ((_DWORD)v44 << 12);
                v40 = S3TC_BLOCK_WIDTH;
                v134 = v44;
                v42 = n;
              }
              ++v42;
              v38 = (_DWORD *)((char *)v38 + v128);
            }
            *v129 = v134;
          }
          ++v129;
          v40 = S3TC_BLOCK_WIDTH;
          ++m;
          v38 = (_DWORD *)((char *)v38 + a1->lPitch - v128 * S3TC_BLOCK_WIDTH);
        }
        goto LABEL_82;
      }
      if ( v143 != 512 )
        goto LABEL_82;
      v18 = v133;
      v19 = 0;
      v20 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
      v156[0] = 0.0;
      v99 = 0;
      v107 = v20;
      do
      {
        for ( ii = 0; ii < S3TC_BLOCK_WIDTH; ++ii )
        {
          if ( ii >= v130 || v99 >= v131 )
          {
            v155[v19++] = -1;
          }
          else
          {
            v21 = (*v18 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v137;
            v22 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v137;
            v155[v19++] = LODWORD(v156[0]);
            if ( v21 == v22 )
            {
              v23 = 1.0;
            }
            else
            {
              v150 = v21;
              v151 = v22;
              v23 = (double)v21 / (double)v22;
            }
            v156[++LODWORD(v156[0])] = v23;
          }
          v18 = (_DWORD *)((char *)v18 + v128);
        }
        v18 = (_DWORD *)((char *)v18 + v107);
        ++v99;
      }
      while ( v99 < 4 );
      v24 = 0;
      v156[49] = 0.0;
      v156[50] = 0.0;
      if ( LODWORD(v156[0]) != 0 )
      {
        CodeAlphaBlock(a1: v156);
        v24 = v158;
        v25 = v159;
        v17 = LODWORD(v161[0]);
        if ( v158 != v159 )
          goto LABEL_45;
      }
      else
      {
        v25 = 0;
        v158 = 0;
      }
      ++v25;
      v26 = 0;
      v159 = v25;
      if ( SLODWORD(v156[0]) > 0 )
      {
        do
          v160[v26++] = 0;
        while ( v26 < SLODWORD(v156[0]) );
        v24 = v158;
        v25 = v159;
      }
      v157 = 6;
LABEL_45:
      if ( v24 > v25 == (v157 == 6) )
      {
        v158 = v25;
        v159 = v24;
        v116 = 1;
      }
      else
      {
        v116 = 0;
      }
      v27 = v129;
      for ( jj = 0; jj < 2; ++jj )
        *v27++ = *((_BYTE *)&v158 + 4 * jj);
      v129 = v27;
      v123 = 0;
      v126 = 0;
      memset(v27, 0, 6 * (S3TC_BLOCK_WIDTH / 4));
      v29 = 0;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v30 = v129;
        while ( 1 )
        {
          v31 = v123;
          v100 = 0;
          do
          {
            for ( kk = 4; kk != 0; --kk )
            {
              v32 = v155[v31];
              v29 >>= 3;
              if ( v32 < 0 )
                goto LABEL_66;
              v33 = v160[v32];
              if ( v116 != 0 )
              {
                if ( v157 == 8 )
                {
                  if ( v33 > 1 )
                  {
                    v34 = 9 - v33;
LABEL_64:
                    v33 = v34;
                    goto LABEL_65;
                  }
                }
                else
                {
                  if ( v157 != 6 || v33 > 5 )
                    goto LABEL_65;
                  if ( v33 > 1 )
                  {
                    v34 = 7 - v33;
                    goto LABEL_64;
                  }
                }
                v34 = v33 == 0;
                goto LABEL_64;
              }
LABEL_65:
              v29 |= v33 << 21;
LABEL_66:
              ++v31;
            }
            v35 = v100;
            if ( (v100 & 1) != 0 )
            {
              v36 = *v30;
              v30 = (_DWORD *)((char *)v30 + 3);
              v37 = v29 | v36;
              v29 = 0;
              *(_DWORD *)((char *)v30 - 3) = v37;
            }
            ++v100;
          }
          while ( v35 + 1 < 4 );
          v123 = v31;
          if ( ++v126 >= S3TC_BLOCK_WIDTH / 4 )
          {
            v129 = v30;
            break;
          }
        }
      }
LABEL_82:
      v46 = 0;
      if ( a2 != nullptr )
      {
        v47 = (unsigned __int8 *)v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v102 = 0;
            v117 = a1->lPitch;
            do
            {
              v48 = 0;
              for ( mm = 0; mm < 4; ++mm )
              {
                if ( v48 >= v130
                  || v102 >= v131
                  || (v49 = &a2[*v47], (v50 = *(_DWORD *)v49 & 0xFFFFFF) >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v50 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v46++] = -1;
                }
                else
                {
                  v155[v46++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v51 = &v161[3 * v17 + 2];
                  *(v51 - 1) = (double)v49->peRed * 0.00392156862745098;
                  *v51 = (double)v49->peGreen * 0.00392156862745098;
                  v51[1] = (double)v49->peBlue * 0.00392156862745098;
                  v17 = LODWORD(v161[0]);
                }
                v48 = mm + 1;
                ++v47;
              }
              v52 = ++v102 < 4;
              v47 = &v47[v117 - 4];
            }
            while ( v52 );
          }
        }
        else
        {
          v53 = 0;
          v54 = 0;
          v103 = 0;
          v118 = a1->lPitch;
          do
          {
            for ( nn = 0; nn < 4; ++nn )
            {
              if ( nn >= v130 || v54 >= v131 )
              {
                v155[v53++] = -1;
              }
              else
              {
                v56 = *v47;
                v155[v53++] = v17;
                v57 = &a2[v56];
                LODWORD(v161[0]) = v17 + 1;
                v58 = &v161[3 * v17 + 2];
                *(v58 - 1) = (double)v57->peRed * 0.00392156862745098;
                *v58 = (double)v57->peGreen * 0.00392156862745098;
                v58[1] = (double)v57->peBlue * 0.00392156862745098;
                v17 = LODWORD(v161[0]);
                v54 = v103;
              }
              ++v47;
            }
            v103 = ++v54;
            v47 = &v47[v118 - 4];
          }
          while ( v54 < 4 );
        }
      }
      else
      {
        v127 = v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v124 = 0;
            v105 = 0;
            v112 = a1->lPitch - 4 * v128;
            do
            {
              v120 = 0;
              do
              {
                if ( v120 >= v130
                  || v105 >= v131
                  || (v68 = *v127, v142 = v68, v68 >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v68 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v124++] = -1;
                }
                else
                {
                  v155[v124] = v17;
                  v69 = &v161[3 * v17 + 1];
                  LODWORD(v161[0]) = v17 + 1;
                  v70 = v135;
                  ++v124;
                  for ( i1 = 0; i1 < 3; ++i1 )
                  {
                    v72 = v140[i1];
                    ++v69;
                    v73 = (v142 & *(_DWORD *)((char *)&v140[i1] + v70)) >> v72;
                    v146 = (unsigned int)(*(_DWORD *)((char *)&v140[i1] + v70) >> v72);
                    v153 = v73;
                    *(v69 - 1) = (double)v73 / (double)v146;
                  }
                  v17 = LODWORD(v161[0]);
                }
                v74 = (char *)v127 + v128;
                v52 = ++v120 < 4;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v52 );
              v52 = ++v105 < 4;
              v127 = (unsigned int *)&v74[v112];
            }
            while ( v52 );
          }
          else if ( v141 == 2 )
          {
            v59 = 0;
            v60 = 0;
            v104 = 0;
            v111 = a1->lPitch - 4 * v128;
            do
            {
              v61 = v127;
              v62 = 0;
              v119 = 0;
              do
              {
                if ( v62 >= v130 || v60 >= v131 || (v63 = *v61, (*v61 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) <= v144) )
                {
                  v155[v59++] = -1;
                }
                else
                {
                  v155[v59++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v64 = &v161[3 * v17 + 1];
                  v65 = 0;
                  v154 = *(&a1->ddpfPixelFormat.dwRBitMask + v59) >> v140[v59];
                  v66 = (double)v154;
                  do
                  {
                    ++v64;
                    v67 = (v63 & *(_DWORD *)((char *)&v140[v65] + v135)) >> v140[v65];
                    ++v65;
                    v145 = v67;
                    *(v64 - 1) = (double)v67 / v66;
                  }
                  while ( v65 < 3 );
                  v17 = LODWORD(v161[0]);
                  v62 = v119;
                  v60 = v104;
                }
                ++v62;
                v61 = (unsigned int *)((char *)v127 + v128);
                v119 = v62;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v62 < 4 );
              v104 = ++v60;
              v127 = (unsigned int *)((char *)v61 + v111);
            }
            while ( v60 < 4 );
          }
        }
        else
        {
          v75 = 0;
          v76 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
          v106 = 0;
          v113 = v76;
          do
          {
            v77 = 0;
            v121 = 0;
            if ( S3TC_BLOCK_WIDTH > 0 )
            {
              do
              {
                if ( v77 >= v130 || v46 >= v131 )
                {
                  v155[v75++] = -1;
                }
                else
                {
                  v155[v75] = v17;
                  v78 = *v127;
                  v79 = &v161[3 * v17 + 1];
                  v125 = v75 + 1;
                  LODWORD(v161[0]) = v17 + 1;
                  for ( i2 = 0; i2 < 3; ++i2 )
                  {
                    ++v79;
                    v81 = *(_DWORD *)((char *)&v140[i2] + v135);
                    v82 = v140[i2];
                    v147 = (v81 & v78) >> v82;
                    v149 = v81 >> v82;
                    *(v79 - 1) = (double)v147 / (double)v149;
                  }
                  v17 = LODWORD(v161[0]);
                  v75 = v125;
                  v77 = v121;
                  v46 = v106;
                }
                ++v77;
                v127 = (unsigned int *)((char *)v127 + v128);
                v121 = v77;
              }
              while ( v77 < S3TC_BLOCK_WIDTH );
              v76 = v113;
            }
            v106 = ++v46;
            v127 = (unsigned int *)((char *)v127 + v76);
          }
          while ( v46 < 4 );
        }
      }
      LODWORD(v161[148]) = (v17 >= v131 * v130) + 3;
      if ( v17 != 0 )
      {
        CodeRGBBlock(a1: v161);
      }
      else
      {
        v83 = (_DWORD *)&v161[149] + 1;
        for ( i3 = 2; i3 != 0; --i3 )
        {
          v83[1] = 0;
          *v83 = 0;
          *(v83 - 1) = 0;
          v83 += 3;
        }
      }
      v85 = 0;
      v86 = (char *)&v161[149] + 4;
      do
      {
        v87 = *((_WORD *)v86 - 2);
        v86 += 12;
        *((_WORD *)&v131 + ++v85 + 1) = *((_WORD *)v86 - 4) | (32 * (*((_WORD *)v86 - 6) | (v87 << 6)));
      }
      while ( v85 < 2 );
      v89 = HIWORD(v132);
      v88 = v132;
      v90 = HIWORD(v132) < (unsigned __int16)v132;
      if ( HIWORD(v132) == (_WORD)v132 )
      {
        v89 = HIWORD(v132) + 1;
        v91 = 0;
        ++HIWORD(v132);
        if ( SLODWORD(v161[0]) > 0 )
        {
          do
            *((_DWORD *)&v161[152] + v91++) = 0;
          while ( v91 < SLODWORD(v161[0]) );
        }
        HIDWORD(v161[148]) = 3;
        v90 = v89 < v88;
      }
      if ( v90 == (HIDWORD(v161[148]) == 3) )
      {
        v92 = v132;
        LOWORD(v132) = v89;
        HIWORD(v132) = v92;
        v122 = 1;
      }
      else
      {
        v122 = 0;
      }
      v93 = 0;
      *(_DWORD *)v129 = v132;
      v94 = v129 + 2;
      v129 += 2;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v114 = &v155[15];
        do
        {
          v95 = v114;
          v96 = 0;
          for ( i4 = 16; i4 != 0; --i4 )
          {
            v96 *= 4;
            if ( *v95 >= 0 )
            {
              v96 |= *((_DWORD *)&v161[152] + *v95);
              if ( v122 != 0 )
              {
                if ( HIDWORD(v161[148]) == 4 )
                  v96 ^= 1u;
                else
                  v96 ^= (~v96 & 2) != 0;
              }
            }
            else
            {
              LOBYTE(v96) = v96 | 3;
            }
            --v95;
          }
          *v94 = v96;
          v114 += 16;
          ++v94;
          ++v93;
        }
        while ( v93 < S3TC_BLOCK_WIDTH / 4 );
        v129 = v94;
      }
      v133 += v128;
      v139 += 4;
      dwWidth = a1->dwWidth;
      if ( v139 >= dwWidth )
        goto LABEL_171;
    }
  }
}

} // namespace tgamse

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0043CDA0
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax
  bool v3; // zf

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    v3 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = num;
    if ( v3 )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1000BA80
// Name: bool TGALoader::GetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::GetInfo(CUtlBuffer *buf, int *width, int *height, ImageFormat *imageFormat, float *sourceGamma)
{
  int v5; // ecx
  TGALoader::TGAHeader_t header; // [esp+0h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  switch ( header.image_type )
  {
    case 1u:
    case 3u:
    case 9u:
      *imageFormat = IMAGE_FORMAT_I8;
      goto LABEL_7;
    case 2u:
    case 0xAu:
      if ( header.pixel_size == 32 )
      {
        *imageFormat = IMAGE_FORMAT_ABGR8888;
LABEL_7:
        v5 = header.height;
        *width = header.width;
        *height = v5;
        *sourceGamma = 2.2;
        return 1;
      }
      if ( header.pixel_size == 24 )
      {
        *imageFormat = IMAGE_FORMAT_BGR888;
        goto LABEL_7;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB20
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BCC0
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BD30
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BE00
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BF10
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x1000C040
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000C0B0
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000C120
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000C190
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000C200
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C2B0
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3B0
// Name: bool TGALoader::Load(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::Load(
        unsigned __int8 *pOutputImage,
        CUtlBuffer *buf,
        int width,
        int height,
        ImageFormat imageFormat,
        float targetGamma,
        bool mipmap)
{
  unsigned __int8 *m_pMemory; // esi
  TGALoader::TGAHeader_t header; // [esp+10h] [ebp-20h] BYREF
  CUtlMemory<unsigned char,int> tmpImage; // [esp+24h] [ebp-Ch] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  memset(&tmpImage, 0, sizeof(tmpImage));
  if ( TGALoader::ReadSourceImage(&header, buf, image: &tmpImage) == 0 || height * width < header.height * header.width )
  {
    if ( tmpImage.m_nGrowSize >= 0 && tmpImage.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpImage.m_pMemory);
    return 0;
  }
  m_pMemory = tmpImage.m_pMemory;
  ImageLoader::GenerateMipmapLevels(
    pSrc: tmpImage.m_pMemory,
    pDst: pOutputImage,
    width: header.width,
    height: header.height,
    depth: 1,
    imageFormat,
    srcGamma: 2.2,
    dstGamma: targetGamma,
    numLevels: !mipmap);
  if ( tmpImage.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

} // namespace vtex_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027D720
// Name: TGALoader::ReadFile
// Source: json
//------------------------------------------------------------------------------
bool __usercall TGALoader::ReadFile@<al>(
        const char *pFileName@<edx>,
        int maxbytes@<eax>,
        CUtlMemory<unsigned char,int> *image)
{
  void *v5; // esi
  int v6; // ebx

  if ( g_pFullFileSystem == nullptr )
    return false;
  v5 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: 0);
  if ( v5 == nullptr )
    return false;
  if ( maxbytes < 0 )
    maxbytes = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  CUtlMemory<unsigned char,int>::EnsureCapacity(this: image, num: maxbytes);
  g_pFullFileSystem->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  v6 = g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: image->m_pMemory, a3: maxbytes, a4: v5);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  return v6 == maxbytes;
}

//------------------------------------------------------------------------------
// Address: 0x1027D7D0
// Name: void TGALoader::ReadRow8BitUncompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 colormap_size; // cl
  int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // esi
  unsigned __int8 v11; // al
  int v12; // edi
  unsigned __int8 *v13; // esi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 *v15; // eax

  colormap_size = header->colormap_size;
  switch ( colormap_size )
  {
    case 8u:
      v12 = 0;
      if ( header->width != 0 )
      {
        v13 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            UnsignedShort = 0;
          }
          v15 = &g_ColorMap[UnsignedShort];
          *(v13 - 2) = *v15;
          *(v13 - 1) = *v15;
          *v13 = *v15;
          v13[1] = -1;
          ++v12;
          v13 += 4;
        }
        while ( v12 < header->width );
      }
      break;
    case 0x18u:
      v9 = 0;
      if ( header->width != 0 )
      {
        v10 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v11 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v11 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v11 = 0;
          }
          *(v10 - 2) = g_ColorMap[3 * v11 + 2];
          *(v10 - 1) = g_ColorMap[3 * v11 + 1];
          *v10 = g_ColorMap[3 * v11];
          v10[1] = -1;
          ++v9;
          v10 += 4;
        }
        while ( v9 < header->width );
      }
      break;
    case 0x20u:
      v4 = 0;
      if ( header->width != 0 )
      {
        v5 = pDst + 2;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v6 = CUtlBuffer::GetUnsignedShort(this: buf);
          }
          else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
          {
            v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            ++buf->m_Get;
          }
          else
          {
            v6 = 0;
          }
          v7 = g_ColorMap[4 * v6 + 3];
          v8 = &g_ColorMap[4 * v6];
          *(v5 - 2) = v7;
          *(v5 - 1) = v8[2];
          *v5 = v8[1];
          v5[1] = *v8;
          ++v4;
          v5 += 4;
        }
        while ( v4 < header->width );
      }
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D970
// Name: void TGALoader::ReadRow8BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // esi
  unsigned __int8 UnsignedShort; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      *v4 = UnsignedShort;
      *(v4 - 1) = UnsignedShort;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D9E0
// Name: void TGALoader::ReadRow24BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al

  v3 = 0;
  if ( header->width != 0 )
  {
    v4 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v4[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v6 = 0;
      }
      *v4 = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        v7 = 0;
      }
      *(v4 - 1) = v7;
      v4[2] = -1;
      ++v3;
      v4 += 4;
    }
    while ( v3 < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027DAB0
// Name: void TGALoader::ReadRow32BitUncompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitUncompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 UnsignedShort; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int i; // [esp+0h] [ebp-4h]

  i = 0;
  if ( header->width != 0 )
  {
    v3 = pDst + 1;
    do
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v3[1] = UnsignedShort;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v5 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v5 = 0;
      }
      *v3 = v5;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v6 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v6 = 0;
      }
      *(v3 - 1) = v6;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        v7 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        ++buf->m_Get;
      }
      else
      {
        v7 = 0;
      }
      v3[2] = v7;
      v3 += 4;
      ++i;
    }
    while ( i < header->width );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027DBC0
// Name: TGALoader::DecompressRow
// Source: json
//------------------------------------------------------------------------------
void __usercall TGALoader::DecompressRow(
        CUtlBuffer *buf@<edi>,
        const TGALoader::TGAHeader_t *header@<ecx>,
        unsigned __int8 *pDst)
{
  int v3; // ebx
  char UnsignedShort; // al
  int v5; // esi
  unsigned __int8 v6; // al
  int i; // esi
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  unsigned __int8 repeat[4]; // [esp+8h] [ebp-10h] BYREF
  int pixelsLeftInRow; // [esp+Ch] [ebp-Ch]
  int numPixelsToProcess; // [esp+10h] [ebp-8h]
  int bytesPerPixel; // [esp+14h] [ebp-4h]

  bytesPerPixel = header->pixel_size >> 3;
  v3 = g_PixelsLeftInPacket;
  pixelsLeftInRow = header->width;
  do
  {
    if ( v3 == 0 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
      {
        UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      v3 = (UnsignedShort & 0x7F) + 1;
      g_PixelsLeftInPacket = v3;
      if ( UnsignedShort >= 0 )
      {
        g_IsRunLengthPacket = false;
      }
      else
      {
        v5 = 0;
        g_IsRunLengthPacket = true;
        if ( bytesPerPixel > 0 )
        {
          do
          {
            if ( (buf->m_Flags & 1) != 0 )
            {
              v6 = CUtlBuffer::GetUnsignedShort(this: buf);
            }
            else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
            {
              v6 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
            }
            else
            {
              v6 = 0;
            }
            repeat[v5++] = v6;
          }
          while ( v5 < bytesPerPixel );
          v3 = g_PixelsLeftInPacket;
        }
      }
    }
    numPixelsToProcess = v3;
    if ( v3 > pixelsLeftInRow )
      numPixelsToProcess = pixelsLeftInRow;
    if ( g_IsRunLengthPacket )
    {
      for ( i = numPixelsToProcess - 1; i >= 0; --i )
      {
        v8 = bytesPerPixel;
        if ( bytesPerPixel > 0 )
        {
          memcpy(dst: pDst, src: repeat, count: bytesPerPixel);
          v8 = bytesPerPixel;
        }
        pDst += v8;
      }
    }
    else
    {
      v9 = bytesPerPixel * numPixelsToProcess;
      CUtlBuffer::Get(this: buf, pMem: pDst, size: bytesPerPixel * numPixelsToProcess);
      pDst += v9;
      v3 = g_PixelsLeftInPacket;
    }
    v3 -= numPixelsToProcess;
    v10 = pixelsLeftInRow == numPixelsToProcess;
    pixelsLeftInRow -= numPixelsToProcess;
    g_PixelsLeftInPacket = v3;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x1027DCF0
// Name: void TGALoader::ReadRow8BitCompressedWithColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1027DD60
// Name: void TGALoader::ReadRow8BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow8BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 rowI_8[2048]; // [esp+8h] [ebp-830h] BYREF
  CUtlBuffer uncompressedBuf; // [esp+808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: rowI_8);
  CUtlBuffer::CUtlBuffer(this: &uncompressedBuf, pBuffer: rowI_8, nSize: 2048, nFlags: 8u);
  TGALoader::ReadRow8BitUncompressedWithoutColormap(buf: &uncompressedBuf, header, pDst);
  if ( uncompressedBuf.m_Memory.m_nGrowSize >= 0 && uncompressedBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uncompressedBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1027DDD0
// Name: void TGALoader::ReadRow24BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow24BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[6144]; // [esp+8h] [ebp-1830h] BYREF
  CUtlBuffer v4; // [esp+1808h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 6144, nFlags: 8u);
  TGALoader::ReadRow24BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1027DE40
// Name: void TGALoader::ReadRow32BitCompressedWithoutColormap(class CUtlBuffer __near &,struct TGALoader::TGAHeader_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TGALoader::ReadRow32BitCompressedWithoutColormap(
        CUtlBuffer *buf,
        const TGALoader::TGAHeader_t *header,
        unsigned __int8 *pDst)
{
  unsigned __int8 pDsta[8192]; // [esp+8h] [ebp-2030h] BYREF
  CUtlBuffer v4; // [esp+2008h] [ebp-30h] BYREF

  TGALoader::DecompressRow(buf, header, pDst: pDsta);
  CUtlBuffer::CUtlBuffer(this: &v4, pBuffer: pDsta, nSize: 0x2000, nFlags: 8u);
  TGALoader::ReadRow32BitUncompressedWithoutColormap(buf: &v4, header, pDst);
  if ( v4.m_Memory.m_nGrowSize >= 0 && v4.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1027DEB0
// Name: TGALoader::GetReadRowFunc
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__usercall TGALoader::GetReadRowFunc@<eax>(
        const TGALoader::TGAHeader_t *header@<eax>))(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *)
{
  void (__cdecl *result)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // eax
  unsigned __int8 pixel_size; // al
  unsigned __int8 v3; // al

  switch ( header->image_type )
  {
    case 1u:
    case 3u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitUncompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitUncompressedWithoutColormap;
      break;
    case 2u:
      pixel_size = header->pixel_size;
      if ( pixel_size == 24 )
        result = TGALoader::ReadRow24BitUncompressedWithoutColormap;
      else
        result = pixel_size != 32 ? nullptr : TGALoader::ReadRow32BitUncompressedWithoutColormap;
      break;
    case 9u:
      if ( header->colormap_length != 0 )
        result = TGALoader::ReadRow8BitCompressedWithColormap;
      else
        result = TGALoader::ReadRow8BitCompressedWithoutColormap;
      break;
    case 0xAu:
      if ( header->colormap_length != 0 )
        goto LABEL_15;
      v3 = header->pixel_size;
      if ( v3 == 24 )
        result = TGALoader::ReadRow24BitCompressedWithoutColormap;
      else
        result = v3 != 32 ? nullptr : TGALoader::ReadRow32BitCompressedWithoutColormap;
      break;
    default:
LABEL_15:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027DF60
// Name: TGALoader::ReadSourceImage
// Source: json
//------------------------------------------------------------------------------
char __usercall TGALoader::ReadSourceImage@<al>(
        TGALoader::TGAHeader_t *header@<esi>,
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *image)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int v7; // edi
  const ImageFormatInfo_t *v8; // eax
  int v9; // edi
  const ImageFormatInfo_t *v10; // eax
  int width; // [esp-1Ch] [ebp-28h]
  int height; // [esp-18h] [ebp-24h]
  unsigned __int8 *v13; // [esp+4h] [ebp-8h]
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  void (__cdecl *ReadRowFunc)(CUtlBuffer *, const TGALoader::TGAHeader_t *, unsigned __int8 *); // [esp+8h] [ebp-4h]

  ReadRowFunc = TGALoader::GetReadRowFunc(header);
  if ( ReadRowFunc == nullptr )
    return 0;
  height = header->height;
  width = header->width;
  g_PixelsLeftInPacket = 0;
  MemRequired = ImageLoader::GetMemRequired(
                  width,
                  height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( image->m_nAllocationCount < MemRequired && image->m_nGrowSize >= 0 )
  {
    m_pMemory = image->m_pMemory;
    image->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    image->m_pMemory = v6;
  }
  if ( (header->attributes & 0x20) == 0 )
  {
    v9 = header->height - 1;
    if ( header->height != 0 )
    {
      do
      {
        v14 = image->m_pMemory;
        v10 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
        ReadRowFunc(a1: buf, a2: header, a3: &v14[v9 * v10->m_nNumBytes * header->width]);
        --v9;
      }
      while ( v9 >= 0 );
    }
    return 1;
  }
  v7 = 0;
  if ( header->height == 0 )
    return 1;
  do
  {
    v13 = image->m_pMemory;
    v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    ReadRowFunc(a1: buf, a2: header, a3: &v13[v7 * v8->m_nNumBytes * header->width]);
    ++v7;
  }
  while ( v7 < header->height );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027E060
// Name: bool TGALoader::LoadRGBA8888(class CUtlBuffer __near &,class CUtlMemory<unsigned char,int> __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::LoadRGBA8888(
        CUtlBuffer *buf,
        CUtlMemory<unsigned char,int> *outputData,
        int *outWidth,
        int *outHeight)
{
  int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  int height; // eax
  TGALoader::TGAHeader_t header; // [esp+4h] [ebp-14h] BYREF

  CUtlBuffer::Get(this: buf, pMem: &header.id_length, size: 18);
  if ( header.id_length != 0 )
    CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: header.id_length);
  if ( header.colormap_length != 0 )
  {
    if ( header.colormap_length * (header.colormap_size >> 3) > 0x400u )
      return 0;
    CUtlBuffer::Get(this: buf, pMem: g_ColorMap, size: header.colormap_length * (header.colormap_size >> 3));
  }
  MemRequired = ImageLoader::GetMemRequired(
                  width: header.width,
                  height: header.height,
                  depth: 1,
                  imageFormat: IMAGE_FORMAT_RGBA8888,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( outputData->m_nAllocationCount < MemRequired && outputData->m_nGrowSize >= 0 )
  {
    m_pMemory = outputData->m_pMemory;
    outputData->m_nAllocationCount = MemRequired;
    if ( m_pMemory != nullptr )
      v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: MemRequired);
    else
      v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: MemRequired);
    outputData->m_pMemory = v6;
  }
  if ( TGALoader::ReadSourceImage(&header, buf, image: outputData) == 0 )
    return 0;
  height = header.height;
  *outWidth = header.width;
  *outHeight = height;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027E140
// Name: bool TGALoader::LoadRGBA8888(char const __near *,class CUtlMemory<unsigned char,int> __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TGALoader::LoadRGBA8888(
        const char *pFileName,
        CUtlMemory<unsigned char,int> *outputData,
        int *outWidth,
        int *outHeight)
{
  unsigned __int8 *m_pMemory; // esi
  char v6; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> vec; // [esp+34h] [ebp-Ch] BYREF

  memset(&vec, 0, sizeof(vec));
  if ( TGALoader::ReadFile(pFileName, maxbytes: -1, image: &vec) )
  {
    m_pMemory = vec.m_pMemory;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: vec.m_pMemory, nSize: vec.m_nAllocationCount, nFlags: 8u);
    v6 = TGALoader::LoadRGBA8888(&buf, outputData, outWidth, outHeight);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( vec.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v6;
  }
  else
  {
    if ( vec.m_nGrowSize >= 0 && vec.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vec.m_pMemory);
    return 0;
  }
}

} // namespace client
