// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/statsmap/bitmapimage.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: init_destination
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_destination(jpeg_common_struct *cinfo)
{
  jpeg_destination_mgr *err; // esi
  int v2; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 4096);
  err[1].free_in_buffer = v2;
  err->next_output_byte = (unsigned __int8 *)v2;
  err->free_in_buffer = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: empty_output_buffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl empty_output_buffer(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // esi

  dest = cinfo->dest;
  CUtlBuffer::Put(this: (CUtlBuffer *)dest[1].next_output_byte, pMem: (const void *)dest[1].free_in_buffer, size: 4096);
  dest->next_output_byte = (unsigned __int8 *)dest[1].free_in_buffer;
  dest->free_in_buffer = 4096;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401060
// Name: term_destination
// Source: json
//------------------------------------------------------------------------------
void __cdecl term_destination(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax

  dest = cinfo->dest;
  if ( dest->free_in_buffer != 4096 )
    CUtlBuffer::Put(
      this: (CUtlBuffer *)dest[1].next_output_byte,
      pMem: (const void *)dest[1].free_in_buffer,
      size: 4096 - dest->free_in_buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00401090
// Name: bool ImageToJPEGBuffer(struct Image_t __near *,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ImageToJPEGBuffer(Image_t *image, CUtlBuffer *buf, int quality)
{
  signed int w; // esi
  int h; // edi
  unsigned __int8 *v6; // ebx
  int v8; // edi
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ecx
  signed int i; // edx
  jpeg_destination_mgr *dest; // eax
  unsigned int j; // eax
  jpeg_error_mgr jerr; // [esp+0h] [ebp-1FCh] BYREF
  jpeg_compress_struct cinfo; // [esp+84h] [ebp-178h] BYREF
  unsigned __int8 *row_pointer[1]; // [esp+1ECh] [ebp-10h] BYREF
  unsigned __int8 *pImage; // [esp+1F0h] [ebp-Ch]
  int imageh; // [esp+1F4h] [ebp-8h]
  unsigned int v19; // [esp+1F8h] [ebp-4h]
  int qualitya; // [esp+20Ch] [ebp+10h]

  if ( quality >= 1 )
  {
    qualitya = 100;
    if ( quality <= 100 )
      qualitya = quality;
  }
  else
  {
    qualitya = 1;
  }
  w = image->w;
  h = image->h;
  imageh = h;
  v19 = 3 * w * h;
  v6 = (unsigned __int8 *)operator new(nSize: v19);
  pImage = v6;
  if ( v6 != nullptr )
  {
    if ( h > 0 )
    {
      v8 = 0;
      v19 = imageh;
      do
      {
        v9 = &image->data[v8];
        v10 = &v6[v8];
        if ( w > 0 )
        {
          for ( i = w; i != 0; --i )
          {
            *v10 = v9[2];
            v10[1] = v9[1];
            v10[2] = *v9;
            v9 += 3;
            v10 += 3;
          }
          v6 = pImage;
        }
        v8 += 3 * w;
        --v19;
      }
      while ( v19 != 0 );
      h = imageh;
    }
    cinfo.err = jpeg_std_error(err: &jerr);
    jpeg_CreateCompress(&cinfo, version: 62, structsize: 0x168u);
    dest = cinfo.dest;
    if ( cinfo.dest == nullptr )
    {
      dest = (jpeg_destination_mgr *)cinfo.mem->alloc_small(a1: (jpeg_common_struct *)&cinfo, a2: 0, a3: 28);
      cinfo.dest = dest;
    }
    dest->init_destination = (void (__cdecl *)(jpeg_compress_struct *))init_destination;
    dest->empty_output_buffer = empty_output_buffer;
    dest->term_destination = term_destination;
    dest[1].next_output_byte = (unsigned __int8 *)buf;
    cinfo.image_width = w;
    cinfo.image_height = h;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality: qualitya, force_baseline: 1u);
    jpeg_start_compress(&cinfo, write_all_tables: 1u);
    for ( j = cinfo.next_scanline; cinfo.next_scanline < cinfo.image_height; j = cinfo.next_scanline )
    {
      row_pointer[0] = &v6[3 * w * j];
      jpeg_write_scanlines(&cinfo, scanlines: row_pointer, num_lines: 1u);
    }
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    free(pMem: v6);
    return 1;
  }
  else
  {
    _Msg(a1: "Unable to allocate %i bytes for image\n", v19);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012B0
// Name: bool WriteJPeg(char const __near *,struct Image_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteJPeg(const char *filename, Image_t *image)
{
  void *v2; // esi
  CUtlBuffer buf; // [esp+4h] [ebp-3Ch] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: "wb", a4: 0);
  if ( v2 == nullptr )
    return 0;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v5 = 0;
  ImageToJPEGBuffer(image, &buf, quality: 90);
  g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v2);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
  v5 = -1;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401390
// Name: bool WriteJPegThumbnail(char const __near *,struct Image_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteJPegThumbnail(const char *filename, Image_t *image, int width, int height)
{
  void *v4; // ebx
  int v6; // esi
  int v7; // edi
  unsigned __int8 *v8; // eax
  int v9; // ecx
  float v10; // xmm6_4
  float v11; // xmm4_4
  int w; // esi
  int h; // eax
  float v14; // xmm4_4
  int v15; // ebx
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // edi
  int v21; // edx
  int v22; // ecx
  unsigned __int8 *v23; // eax
  float v24; // xmm7_4
  unsigned __int8 *v25; // eax
  float v26; // xmm0_4
  CUtlBuffer buf; // [esp+4h] [ebp-68h] BYREF
  Image_t thumb; // [esp+34h] [ebp-38h] BYREF
  int v29; // [esp+40h] [ebp-2Ch]
  void *fh; // [esp+44h] [ebp-28h]
  int v31; // [esp+48h] [ebp-24h]
  unsigned __int8 *v32; // [esp+4Ch] [ebp-20h]
  int y; // [esp+50h] [ebp-1Ch]
  unsigned __int8 *pDest; // [esp+54h] [ebp-18h]
  int x; // [esp+58h] [ebp-14h]
  int sx; // [esp+5Ch] [ebp-10h]
  int v37; // [esp+68h] [ebp-4h]

  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: "wb", a4: 0);
  fh = v4;
  if ( v4 == nullptr )
    return 0;
  v6 = width;
  v7 = height;
  thumb.w = width;
  thumb.h = height;
  v8 = (unsigned __int8 *)operator new(nSize: 3 * height * width);
  v9 = 0;
  thumb.data = v8;
  y = 0;
  if ( height > 0 )
  {
    v29 = 3 * width;
    v32 = v8;
    do
    {
      pDest = v8;
      x = 0;
      if ( v6 > 0 )
      {
        v10 = (float)v9 / (float)v7;
        do
        {
          v11 = (float)v6;
          w = image->w;
          h = image->h;
          v14 = (float)w * (float)((float)x / v11);
          v15 = 0;
          v16 = 0.0;
          v17 = 0.0;
          v18 = 0.0;
          sx = -3;
          v31 = h;
          v19 = (float)h * v10;
          do
          {
            v20 = -3;
            v21 = (int)(float)((float)sx + v14);
            do
            {
              v22 = (int)(float)((float)v20 + v19);
              if ( v21 >= 0 && v21 < w && v22 >= 0 && v22 < h )
              {
                v23 = &image->data[3 * v21 + 3 * v22 * w];
                ++v15;
                v18 = v18 + (float)*v23;
                v17 = v17 + (float)v23[1];
                v24 = (float)v23[2];
                h = v31;
                v16 = v16 + v24;
              }
              ++v20;
            }
            while ( v20 <= 3 );
            ++sx;
          }
          while ( sx <= 3 );
          v25 = pDest;
          v6 = width;
          v26 = 1.0 / (float)v15;
          *pDest = (int)(float)(v26 * v18);
          v25 += 3;
          *(v25 - 2) = (int)(float)(v26 * v17);
          *(v25 - 1) = (int)(float)(v26 * v16);
          pDest = v25;
          ++x;
        }
        while ( x < width );
        v7 = height;
        v4 = fh;
        v9 = y;
      }
      v8 = &v32[v29];
      y = ++v9;
      v32 += v29;
    }
    while ( v9 < v7 );
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v37 = 0;
  ImageToJPEGBuffer(image: &thumb, &buf, quality: 90);
  g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v4);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
  v37 = -1;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401620
// Name: bool ReadBitmapRGB(unsigned char const __near *,unsigned int,struct Image_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadBitmapRGB(const unsigned __int8 *raw, unsigned int rawlen, Image_t *image)
{
  int biHeight; // edx
  unsigned int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 *v8; // eax
  int v9; // edx
  bool v10; // cc
  unsigned __int8 *v11; // ecx
  int v12; // ebx
  unsigned __int8 *v13; // esi
  int v14; // eax
  unsigned int v15; // [esp-10h] [ebp-90h]
  CUtlBuffer buf; // [esp+0h] [ebp-80h] BYREF
  tagBITMAPINFOHEADER bmih; // [esp+30h] [ebp-50h] BYREF
  tagBITMAPFILEHEADER bmfh; // [esp+58h] [ebp-28h] BYREF
  int bitrueWidth; // [esp+68h] [ebp-18h]
  unsigned __int8 *pb; // [esp+6Ch] [ebp-14h]
  int y; // [esp+70h] [ebp-10h]
  int v22; // [esp+7Ch] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v22 = 0;
  CUtlBuffer::Put(this: &buf, pMem: raw, size: rawlen);
  CUtlBuffer::Get(this: &buf, pMem: &bmfh, size: 14);
  CUtlBuffer::Get(this: &buf, pMem: &bmih, size: 40);
  if ( bmih.biSize == 40 && bmih.biPlanes == 1 && bmih.biBitCount == 24 )
  {
    if ( bmih.biCompression != 0 )
      goto LABEL_9;
    biHeight = bmih.biHeight;
    v5 = bmfh.bfSize - buf.m_Get;
    v15 = bmfh.bfSize - buf.m_Get;
    image->w = bmih.biWidth;
    image->h = biHeight;
    v6 = (unsigned __int8 *)operator new(nSize: v15);
    v7 = v6;
    pb = v6;
    if ( v6 == nullptr )
    {
LABEL_9:
      v22 = -1;
      CUtlMemory<CHeatMapPoint,int>::~CUtlMemory<CHeatMapPoint,int>(this: &buf);
      return 0;
    }
    else
    {
      CUtlBuffer::Get(this: &buf, pMem: v6, size: v5);
      v8 = (unsigned __int8 *)operator new(nSize: v5);
      v9 = (bmih.biWidth + 3) & 0xFFFFFFFC;
      v10 = image->h <= 0;
      image->data = v8;
      bitrueWidth = v9;
      v11 = v8;
      y = 0;
      if ( !v10 )
      {
        do
        {
          v12 = 0;
          v13 = &v7[3 * v9 * (image->h - y - 1)];
          if ( image->w > 0 )
          {
            do
            {
              v14 = (unsigned __int64)(1431655766LL * (*v13 + v13[1] + v13[2])) >> 32;
              *v11 = v14;
              v11[1] = v14;
              v11[2] = v14;
              ++v12;
              v11 += 3;
              v13 += 3;
            }
            while ( v12 < image->w );
            v9 = bitrueWidth;
          }
          v7 = pb;
          ++y;
        }
        while ( y < image->h );
      }
      free(pMem: v7);
      v22 = -1;
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 1;
    }
  }
  else
  {
    v22 = -1;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}
