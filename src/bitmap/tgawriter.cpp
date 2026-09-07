// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/tgawriter.cpp
// Functions: 3
// ============================================================

#include "bitmap\tgawriter.h"

//------------------------------------------------------------------------------
// Address: 0x10219010
// Name: bool TGAWriter::WriteTGAFile(char const __near *,int,int,enum ImageFormat,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteTGAFile(
        const char *fileName,
        int width,
        int height,
        ImageFormat srcFormat,
        float16 *srcData,
        int nStride)
{
  void *v6; // ebx
  int v7; // edi
  unsigned __int8 v8; // al
  unsigned __int8 v9; // cl
  int v10; // esi
  float *v11; // edi
  int v12; // eax
  float16 *v13; // edi
  bool result; // al
  TGAWriter::TGAHeader_t tgaHeader; // [esp+8h] [ebp-20h] BYREF
  ImageFormat dstFormat; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  bool bMustConvert; // [esp+27h] [ebp-1h]

  v6 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: fileName, a3: "wb", a4: 0);
  bMustConvert = false;
  dstFormat = srcFormat;
  switch ( srcFormat )
  {
    case IMAGE_FORMAT_RGBA8888:
      bMustConvert = true;
      dstFormat = IMAGE_FORMAT_BGRA8888;
      goto $LN10_33;
    case IMAGE_FORMAT_BGR888:
      v7 = 3;
      v8 = 24;
      v9 = 2;
      goto LABEL_6;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      v8 = 8;
      v9 = 1;
      goto LABEL_6;
    case IMAGE_FORMAT_BGRA8888:
$LN10_33:
      v7 = 4;
      v8 = 32;
      v9 = 2;
LABEL_6:
      memset(&tgaHeader, 0, 12);
      v10 = height;
      tgaHeader.image_type = v9;
      tgaHeader.width = width;
      tgaHeader.pixel_size = v8;
      tgaHeader.height = height;
      tgaHeader.attributes = 32;
      g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tgaHeader, a3: 18, a4: v6);
      if ( bMustConvert )
      {
        i = width * v7;
        v11 = (float *)MemAlloc_Alloc(nSize: width * v7);
        if ( height != 0 )
        {
          do
          {
            ImageLoader::ConvertImageFormat(
              a1: (int)v11,
              src: srcData,
              srcImageFormat: srcFormat,
              dst: v11,
              dstImageFormat: dstFormat,
              width,
              height: 1,
              srcStride: 0,
              dstStride: 0);
            g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11, a3: i, a4: v6);
            srcData = (float16 *)((char *)srcData + nStride);
            --v10;
          }
          while ( v10 != 0 );
        }
        free(pMem: v11);
      }
      else if ( height != 0 )
      {
        v12 = width * v7;
        v13 = srcData;
        for ( i = v12; ; v12 = i )
        {
          g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: v13, a3: v12, a4: v6);
          v13 = (float16 *)((char *)v13 + nStride);
          if ( --v10 == 0 )
            break;
        }
      }
      if ( v6 != nullptr )
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
      result = true;
      break;
    default:
      if ( v6 != nullptr )
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102191D0
// Name: TGAWriter::fputLittleShort
// Source: json
//------------------------------------------------------------------------------
void __usercall TGAWriter::fputLittleShort(CUtlBuffer *buffer@<esi>, __int16 s)
{
  int m_Put; // eax
  int v3; // eax

  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = s;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v3 = buffer->m_Put;
    if ( v3 != 0 && buffer->m_Memory.m_pMemory[v3 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = HIBYTE(s);
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219280
// Name: bool TGAWriter::WriteToBuffer(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteToBuffer(
        unsigned __int8 *pImageData,
        CUtlBuffer *buffer,
        int width,
        int height,
        ImageFormat srcFormat,
        ImageFormat dstFormat)
{
  bool result; // al
  unsigned __int8 v7; // bl
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned __int8 header_16; // [esp+10h] [ebp-4h]

  if ( dstFormat != IMAGE_FORMAT_RGBA8888 )
  {
    if ( dstFormat == IMAGE_FORMAT_RGB888 )
      dstFormat = IMAGE_FORMAT_BGR888;
  }
  else
  {
    dstFormat = IMAGE_FORMAT_BGRA8888;
  }
  switch ( dstFormat )
  {
    case IMAGE_FORMAT_BGR888:
      header_16 = 24;
      break;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      header_16 = 8;
      goto LABEL_13;
    case IMAGE_FORMAT_BGRA8888:
      header_16 = 32;
      break;
    default:
      return false;
  }
  v7 = 2;
LABEL_13:
  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v9 = buffer->m_Put;
    if ( v9 != 0 && buffer->m_Memory.m_pMemory[v9 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v10 = buffer->m_Put;
    if ( v10 != 0 && buffer->m_Memory.m_pMemory[v10 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = v7;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v11 = buffer->m_Put;
    if ( v11 != 0 && buffer->m_Memory.m_pMemory[v11 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: width);
  TGAWriter::fputLittleShort(buffer, s: height);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v12 = buffer->m_Put;
    if ( v12 != 0 && buffer->m_Memory.m_pMemory[v12 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = header_16;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v13 = buffer->m_Put;
    if ( v13 != 0 && buffer->m_Memory.m_pMemory[v13 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 32;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  v14 = height * width * ImageLoader::ImageFormatInfo(fmt: dstFormat)->m_nNumBytes;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v14 + buffer->m_Put);
  result = ImageLoader::ConvertImageFormat(
             a1: v14,
             src: (float16 *)pImageData,
             srcImageFormat: srcFormat,
             dst: (float *)&buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset],
             dstImageFormat: dstFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v14);
    return true;
  }
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102191E0
// Name: bool TGAWriter::WriteTGAFile(char const __near *,int,int,enum ImageFormat,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteTGAFile(
        const char *fileName,
        int width,
        int height,
        ImageFormat srcFormat,
        const unsigned __int8 *srcData,
        int nStride)
{
  void *v6; // ebx
  int v7; // edi
  unsigned __int8 v8; // al
  unsigned __int8 v9; // cl
  int v10; // esi
  unsigned __int8 *v11; // edi
  int v12; // eax
  const unsigned __int8 *v13; // edi
  bool result; // al
  TGAWriter::TGAHeader_t tgaHeader; // [esp+8h] [ebp-20h] BYREF
  ImageFormat dstFormat; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  bool bMustConvert; // [esp+27h] [ebp-1h]

  v6 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: fileName, a3: "wb", a4: 0);
  bMustConvert = false;
  dstFormat = srcFormat;
  switch ( srcFormat )
  {
    case IMAGE_FORMAT_RGBA8888:
      bMustConvert = true;
      dstFormat = IMAGE_FORMAT_BGRA8888;
      goto $LN10_33;
    case IMAGE_FORMAT_BGR888:
      v7 = 3;
      v8 = 24;
      v9 = 2;
      goto LABEL_6;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      v8 = 8;
      v9 = 1;
      goto LABEL_6;
    case IMAGE_FORMAT_BGRA8888:
$LN10_33:
      v7 = 4;
      v8 = 32;
      v9 = 2;
LABEL_6:
      memset(&tgaHeader, 0, 12);
      v10 = height;
      tgaHeader.image_type = v9;
      tgaHeader.width = width;
      tgaHeader.pixel_size = v8;
      tgaHeader.height = height;
      tgaHeader.attributes = 32;
      g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tgaHeader, a3: 18, a4: v6);
      if ( bMustConvert )
      {
        i = width * v7;
        v11 = (unsigned __int8 *)MemAlloc_Alloc(nSize: width * v7);
        if ( height != 0 )
        {
          do
          {
            ImageLoader::ConvertImageFormat(
              src: srcData,
              srcImageFormat: srcFormat,
              dst: v11,
              dstImageFormat: dstFormat,
              width,
              height: 1,
              srcStride: 0,
              dstStride: 0);
            g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11, a3: i, a4: v6);
            srcData += nStride;
            --v10;
          }
          while ( v10 != 0 );
        }
        free(pMem: v11);
      }
      else if ( height != 0 )
      {
        v12 = width * v7;
        v13 = srcData;
        for ( i = v12; ; v12 = i )
        {
          g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: v13, a3: v12, a4: v6);
          v13 += nStride;
          if ( --v10 == 0 )
            break;
        }
      }
      if ( v6 != nullptr )
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
      result = true;
      break;
    default:
      if ( v6 != nullptr )
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102193A0
// Name: TGAWriter::fputLittleShort
// Source: json
//------------------------------------------------------------------------------
void __usercall TGAWriter::fputLittleShort(CUtlBuffer *buffer@<esi>, __int16 s)
{
  int m_Put; // eax
  int v3; // eax

  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = s;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v3 = buffer->m_Put;
    if ( v3 != 0 && buffer->m_Memory.m_pMemory[v3 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = HIBYTE(s);
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219450
// Name: bool TGAWriter::WriteToBuffer(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteToBuffer(
        unsigned __int8 *pImageData,
        CUtlBuffer *buffer,
        int width,
        int height,
        ImageFormat srcFormat,
        ImageFormat dstFormat)
{
  bool result; // al
  unsigned __int8 v7; // bl
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned __int8 header_16; // [esp+10h] [ebp-4h]

  if ( dstFormat != IMAGE_FORMAT_RGBA8888 )
  {
    if ( dstFormat == IMAGE_FORMAT_RGB888 )
      dstFormat = IMAGE_FORMAT_BGR888;
  }
  else
  {
    dstFormat = IMAGE_FORMAT_BGRA8888;
  }
  switch ( dstFormat )
  {
    case IMAGE_FORMAT_BGR888:
      header_16 = 24;
      break;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      header_16 = 8;
      goto LABEL_13;
    case IMAGE_FORMAT_BGRA8888:
      header_16 = 32;
      break;
    default:
      return false;
  }
  v7 = 2;
LABEL_13:
  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v9 = buffer->m_Put;
    if ( v9 != 0 && buffer->m_Memory.m_pMemory[v9 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v10 = buffer->m_Put;
    if ( v10 != 0 && buffer->m_Memory.m_pMemory[v10 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = v7;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v11 = buffer->m_Put;
    if ( v11 != 0 && buffer->m_Memory.m_pMemory[v11 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: width);
  TGAWriter::fputLittleShort(buffer, s: height);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v12 = buffer->m_Put;
    if ( v12 != 0 && buffer->m_Memory.m_pMemory[v12 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = header_16;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v13 = buffer->m_Put;
    if ( v13 != 0 && buffer->m_Memory.m_pMemory[v13 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 32;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  v14 = height * width * ImageLoader::ImageFormatInfo(fmt: dstFormat)->m_nNumBytes;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v14 + buffer->m_Put);
  result = ImageLoader::ConvertImageFormat(
             src: pImageData,
             srcImageFormat: srcFormat,
             dst: &buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset],
             dstImageFormat: dstFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v14);
    return true;
  }
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from height2normal (Missing functions)
// ============================================================
namespace height2normal {

//------------------------------------------------------------------------------
// Address: 0x004018B0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: TGAWriter::fputLittleShort
// Source: json
//------------------------------------------------------------------------------
void __usercall TGAWriter::fputLittleShort(CUtlBuffer *buffer@<esi>, __int16 s)
{
  int m_Put; // eax
  int v3; // eax

  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = s;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v3 = buffer->m_Put;
    if ( v3 != 0 && buffer->m_Memory.m_pMemory[v3 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = HIBYTE(s);
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019B0
// Name: bool TGAWriter::WriteToBuffer(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteToBuffer(
        unsigned __int8 *pImageData,
        CUtlBuffer *buffer,
        int width,
        int height,
        ImageFormat srcFormat,
        ImageFormat dstFormat)
{
  bool result; // al
  unsigned __int8 v7; // bl
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned __int8 header_16; // [esp+10h] [ebp-4h]

  if ( dstFormat != IMAGE_FORMAT_RGBA8888 )
  {
    if ( dstFormat == IMAGE_FORMAT_RGB888 )
      dstFormat = IMAGE_FORMAT_BGR888;
  }
  else
  {
    dstFormat = IMAGE_FORMAT_BGRA8888;
  }
  switch ( dstFormat )
  {
    case IMAGE_FORMAT_BGR888:
      header_16 = 24;
      break;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      header_16 = 8;
      goto LABEL_13;
    case IMAGE_FORMAT_BGRA8888:
      header_16 = 32;
      break;
    default:
      return false;
  }
  v7 = 2;
LABEL_13:
  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v9 = buffer->m_Put;
    if ( v9 != 0 && buffer->m_Memory.m_pMemory[v9 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v10 = buffer->m_Put;
    if ( v10 != 0 && buffer->m_Memory.m_pMemory[v10 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = v7;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v11 = buffer->m_Put;
    if ( v11 != 0 && buffer->m_Memory.m_pMemory[v11 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: width);
  TGAWriter::fputLittleShort(buffer, s: height);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v12 = buffer->m_Put;
    if ( v12 != 0 && buffer->m_Memory.m_pMemory[v12 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = header_16;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v13 = buffer->m_Put;
    if ( v13 != 0 && buffer->m_Memory.m_pMemory[v13 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 32;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  v14 = height * width * ImageLoader::ImageFormatInfo(fmt: dstFormat)->m_nNumBytes;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v14 + buffer->m_Put);
  result = ImageLoader::ConvertImageFormat(
             src: pImageData,
             srcImageFormat: srcFormat,
             dst: &buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset],
             dstImageFormat: dstFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v14);
    return true;
  }
  return result;
}

} // namespace height2normal

// ============================================================
// Overlay from tgadiff (Missing functions)
// ============================================================
namespace tgadiff {

//------------------------------------------------------------------------------
// Address: 0x00401840
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401890
// Name: TGAWriter::fputLittleShort
// Source: json
//------------------------------------------------------------------------------
void __usercall TGAWriter::fputLittleShort(CUtlBuffer *buffer@<esi>, __int16 s)
{
  int m_Put; // eax
  int v3; // eax

  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = s;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v3 = buffer->m_Put;
    if ( v3 != 0 && buffer->m_Memory.m_pMemory[v3 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = HIBYTE(s);
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401940
// Name: bool TGAWriter::WriteToBuffer(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteToBuffer(
        unsigned __int8 *pImageData,
        CUtlBuffer *buffer,
        int width,
        int height,
        ImageFormat srcFormat,
        ImageFormat dstFormat)
{
  bool result; // al
  unsigned __int8 v7; // bl
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned __int8 header_16; // [esp+10h] [ebp-4h]

  if ( dstFormat != IMAGE_FORMAT_RGBA8888 )
  {
    if ( dstFormat == IMAGE_FORMAT_RGB888 )
      dstFormat = IMAGE_FORMAT_BGR888;
  }
  else
  {
    dstFormat = IMAGE_FORMAT_BGRA8888;
  }
  switch ( dstFormat )
  {
    case IMAGE_FORMAT_BGR888:
      header_16 = 24;
      break;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      header_16 = 8;
      goto LABEL_13;
    case IMAGE_FORMAT_BGRA8888:
      header_16 = 32;
      break;
    default:
      return false;
  }
  v7 = 2;
LABEL_13:
  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v9 = buffer->m_Put;
    if ( v9 != 0 && buffer->m_Memory.m_pMemory[v9 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v10 = buffer->m_Put;
    if ( v10 != 0 && buffer->m_Memory.m_pMemory[v10 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = v7;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v11 = buffer->m_Put;
    if ( v11 != 0 && buffer->m_Memory.m_pMemory[v11 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: width);
  TGAWriter::fputLittleShort(buffer, s: height);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v12 = buffer->m_Put;
    if ( v12 != 0 && buffer->m_Memory.m_pMemory[v12 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = header_16;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v13 = buffer->m_Put;
    if ( v13 != 0 && buffer->m_Memory.m_pMemory[v13 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 32;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  v14 = height * width * ImageLoader::ImageFormatInfo(fmt: dstFormat)->m_nNumBytes;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v14 + buffer->m_Put);
  result = ImageLoader::ConvertImageFormat(
             src: pImageData,
             srcImageFormat: srcFormat,
             dst: &buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset],
             dstImageFormat: dstFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v14);
    return true;
  }
  return result;
}

} // namespace tgadiff

// ============================================================
// Overlay from vtf2tga (Missing functions)
// ============================================================
namespace vtf2tga {

//------------------------------------------------------------------------------
// Address: 0x00401E70
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: TGAWriter::fputLittleShort
// Source: json
//------------------------------------------------------------------------------
void __usercall TGAWriter::fputLittleShort(CUtlBuffer *buffer@<esi>, __int16 s)
{
  int m_Put; // eax
  int v3; // eax

  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = s;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v3 = buffer->m_Put;
    if ( v3 != 0 && buffer->m_Memory.m_pMemory[v3 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = HIBYTE(s);
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F70
// Name: bool TGAWriter::WriteToBuffer(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteToBuffer(
        unsigned __int8 *pImageData,
        CUtlBuffer *buffer,
        int width,
        int height,
        ImageFormat srcFormat,
        ImageFormat dstFormat)
{
  bool result; // al
  unsigned __int8 v7; // bl
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned __int8 header_16; // [esp+10h] [ebp-4h]

  if ( dstFormat != IMAGE_FORMAT_RGBA8888 )
  {
    if ( dstFormat == IMAGE_FORMAT_RGB888 )
      dstFormat = IMAGE_FORMAT_BGR888;
  }
  else
  {
    dstFormat = IMAGE_FORMAT_BGRA8888;
  }
  switch ( dstFormat )
  {
    case IMAGE_FORMAT_BGR888:
      header_16 = 24;
      break;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      header_16 = 8;
      goto LABEL_13;
    case IMAGE_FORMAT_BGRA8888:
      header_16 = 32;
      break;
    default:
      return false;
  }
  v7 = 2;
LABEL_13:
  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v9 = buffer->m_Put;
    if ( v9 != 0 && buffer->m_Memory.m_pMemory[v9 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v10 = buffer->m_Put;
    if ( v10 != 0 && buffer->m_Memory.m_pMemory[v10 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = v7;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v11 = buffer->m_Put;
    if ( v11 != 0 && buffer->m_Memory.m_pMemory[v11 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: width);
  TGAWriter::fputLittleShort(buffer, s: height);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v12 = buffer->m_Put;
    if ( v12 != 0 && buffer->m_Memory.m_pMemory[v12 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = header_16;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v13 = buffer->m_Put;
    if ( v13 != 0 && buffer->m_Memory.m_pMemory[v13 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 32;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  v14 = height * width * ImageLoader::ImageFormatInfo(fmt: dstFormat)->m_nNumBytes;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v14 + buffer->m_Put);
  result = ImageLoader::ConvertImageFormat(
             src: pImageData,
             srcImageFormat: srcFormat,
             dst: &buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset],
             dstImageFormat: dstFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v14);
    return true;
  }
  return result;
}

} // namespace vtf2tga

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027E3C0
// Name: TGAWriter::fputLittleShort
// Source: json
//------------------------------------------------------------------------------
void __usercall TGAWriter::fputLittleShort(CUtlBuffer *buffer@<esi>, __int16 s)
{
  int m_Put; // eax
  int v3; // eax

  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = s;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v3 = buffer->m_Put;
    if ( v3 != 0 && buffer->m_Memory.m_pMemory[v3 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = HIBYTE(s);
    CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E470
// Name: bool TGAWriter::WriteToBuffer(unsigned char __near *,class CUtlBuffer __near &,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAWriter::WriteToBuffer(
        unsigned __int8 *pImageData,
        CUtlBuffer *buffer,
        int width,
        int height,
        ImageFormat srcFormat,
        ImageFormat dstFormat)
{
  bool result; // al
  unsigned __int8 v7; // bl
  int m_Put; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned __int8 header_16; // [esp+10h] [ebp-4h]

  if ( dstFormat != IMAGE_FORMAT_RGBA8888 )
  {
    if ( dstFormat == IMAGE_FORMAT_RGB888 )
      dstFormat = IMAGE_FORMAT_BGR888;
  }
  else
  {
    dstFormat = IMAGE_FORMAT_BGRA8888;
  }
  switch ( dstFormat )
  {
    case IMAGE_FORMAT_BGR888:
      header_16 = 24;
      break;
    case IMAGE_FORMAT_I8:
      v7 = 1;
      header_16 = 8;
      goto LABEL_13;
    case IMAGE_FORMAT_BGRA8888:
      header_16 = 32;
      break;
    default:
      return false;
  }
  v7 = 2;
LABEL_13:
  if ( (buffer->m_Flags & 1) != 0 )
  {
    m_Put = buffer->m_Put;
    if ( m_Put != 0 && buffer->m_Memory.m_pMemory[m_Put - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v9 = buffer->m_Put;
    if ( v9 != 0 && buffer->m_Memory.m_pMemory[v9 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v10 = buffer->m_Put;
    if ( v10 != 0 && buffer->m_Memory.m_pMemory[v10 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = v7;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v11 = buffer->m_Put;
    if ( v11 != 0 && buffer->m_Memory.m_pMemory[v11 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: 0);
  TGAWriter::fputLittleShort(buffer, s: width);
  TGAWriter::fputLittleShort(buffer, s: height);
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v12 = buffer->m_Put;
    if ( v12 != 0 && buffer->m_Memory.m_pMemory[v12 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = header_16;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  if ( (buffer->m_Flags & 1) != 0 )
  {
    v13 = buffer->m_Put;
    if ( v13 != 0 && buffer->m_Memory.m_pMemory[v13 - buffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buffer);
  }
  if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) != 0 )
  {
    buffer->m_Memory.m_pMemory[buffer->m_Put++ - buffer->m_nOffset] = 32;
    CUtlBuffer::AddNullTermination(this: buffer, nPut: buffer->m_Put);
  }
  v14 = height * width * ImageLoader::ImageFormatInfo(fmt: dstFormat)->m_nNumBytes;
  CUtlBuffer::EnsureCapacity(this: buffer, num: v14 + buffer->m_Put);
  result = ImageLoader::ConvertImageFormat(
             a1: v14,
             src: (float16 *)pImageData,
             srcImageFormat: srcFormat,
             dst: (float *)&buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset],
             dstImageFormat: dstFormat,
             width,
             height,
             srcStride: 0,
             dstStride: 0);
  if ( result )
  {
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v14);
    return true;
  }
  return result;
}

} // namespace client
