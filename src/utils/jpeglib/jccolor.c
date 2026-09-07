// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jccolor.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10257710
// Name: rgb_ycc_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_start(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *err; // esi
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int *v7; // eax
  jpeg_compress_struct *v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+20h] [ebp+8h]

  err = (jpeg_color_converter *)cinfo[14].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 0x2000);
  v3 = 0;
  err[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))v2;
  v4 = 0;
  v5 = 0;
  v12 = 0;
  v13 = 0;
  cinfoa = nullptr;
  v14 = 8421375;
  v6 = 0x8000;
  v7 = (int *)(v2 + 2048);
  do
  {
    v8 = cinfoa;
    cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 21709);
    v7[512] = (int)v8;
    v9 = v14;
    v14 += 0x8000;
    v7[768] = v9;
    v10 = v13;
    v13 -= 27439;
    v7[1024] = v10;
    v11 = v12;
    v12 -= 5329;
    *v7 = v6;
    *(v7 - 512) = v3;
    *(v7 - 256) = v5;
    v7[256] = v4;
    v7[1280] = v11;
    v6 += 7471;
    v3 += 19595;
    ++v7;
    v5 += 38470;
    v4 -= 11059;
  }
  while ( v6 <= 1937873 );
}

//------------------------------------------------------------------------------
// Address: 0x102577E0
// Name: rgb_ycc_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // edi
  unsigned int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  int v12; // edi
  bool v13; // zf
  int v14; // [esp+4h] [ebp-14h]
  int g; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  unsigned int num_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 *outptr2; // [esp+14h] [ebp-4h]
  unsigned __int8 *outptr2a; // [esp+14h] [ebp-4h]
  int b; // [esp+20h] [ebp+8h]
  int ba; // [esp+20h] [ebp+8h]
  int num_rowsa; // [esp+30h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = output_row;
    do
    {
      v9 = (int)*input_buf++;
      b = (int)(*v7)[v8];
      v10 = v7[1][v8];
      outptr2 = v7[2][v8++];
      if ( num_cols != 0 )
      {
        v16 = b - (_DWORD)v10;
        v11 = (unsigned __int8 *)(v9 + 2);
        v14 = outptr2 - v10;
        outptr2a = (unsigned __int8 *)num_cols;
        do
        {
          v12 = *(v11 - 2);
          ba = *v11;
          g = *(v11 - 1);
          v10[v16] = (unsigned int)(*((_DWORD *)start_pass + v12)
                                  + *((_DWORD *)start_pass + g + 256)
                                  + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v11 += 3;
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                + *((_DWORD *)start_pass + g + 1024)
                                + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v13 = outptr2a-- == (unsigned __int8 *)1;
          v10[v14 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                      + *((_DWORD *)start_pass + g + 1536)
                                      + *((_DWORD *)start_pass + ba + 1792)) >> 16;
        }
        while ( !v13 );
        v7 = output_buf;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102578F0
// Name: rgb_gray_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_gray_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edx
  void (__cdecl *start_pass)(jpeg_compress_struct *); // esi
  unsigned int v8; // eax
  int v9; // edi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp+4h] [ebp-8h]
  unsigned int num_cols; // [esp+8h] [ebp-4h]
  unsigned __int8 *outptr; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = image_width;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf++;
      outptr = *(unsigned __int8 **)((char *)*output_buf + v8);
      v8 += 4;
      v10 = 0;
      v12 = v8;
      if ( image_width != 0 )
      {
        v11 = (unsigned __int8 *)(v9 + 2);
        do
        {
          outptr[v10] = (unsigned int)(*((_DWORD *)start_pass + *(v11 - 2))
                                     + *((_DWORD *)start_pass + *(v11 - 1) + 256)
                                     + *((_DWORD *)start_pass + *v11 + 512)) >> 16;
          image_width = num_cols;
          ++v10;
          v11 += 3;
        }
        while ( v10 < num_cols );
        v8 = v12;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257980
// Name: cmyk_ycck_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmyk_ycck_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  _BYTE *v10; // edi
  jpeg_compress_struct *v11; // edx
  int v12; // ecx
  int v13; // esi
  bool v14; // zf
  unsigned int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-18h]
  int v17; // [esp+8h] [ebp-14h]
  unsigned __int8 *outptr2; // [esp+Ch] [ebp-10h]
  unsigned __int8 *outptr2a; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 *outptr3; // [esp+14h] [ebp-8h]
  unsigned __int8 *outptr3a; // [esp+14h] [ebp-8h]
  int b; // [esp+18h] [ebp-4h]
  int ba; // [esp+18h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+24h] [ebp+8h]
  int num_rowsa; // [esp+34h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf;
      b = *(int *)((char *)v7[1] + v8);
      outptr2 = *(unsigned __int8 **)((char *)v7[2] + v8);
      ++input_buf;
      v10 = *(unsigned __int8 **)((char *)*v7 + v8);
      outptr3 = *(unsigned __int8 **)((char *)v7[3] + v8);
      v8 += 4;
      v15 = v8;
      if ( num_cols != 0 )
      {
        v17 = outptr3 - v10;
        v16 = b - (_DWORD)v10;
        v11 = (jpeg_compress_struct *)(v9 + 2);
        cinfoa = v11;
        outptr2a = (unsigned __int8 *)(outptr2 - v10);
        outptr3a = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v12 = 255 - BYTE2(v11[-1].script_space_size);
          v13 = 255 - HIBYTE(v11[-1].script_space_size);
          ba = 255 - LOBYTE(v11->err);
          v10[v17] = BYTE1(cinfoa->err);
          cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12)
                                + *((_DWORD *)start_pass + v13 + 256)
                                + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v10[v16 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                      + *((_DWORD *)start_pass + v13 + 1024)
                                      + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v14 = outptr3a-- == (unsigned __int8 *)1;
          v10[(_DWORD)outptr2a - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                                   + *((_DWORD *)start_pass + v13 + 1536)
                                                   + *((_DWORD *)start_pass + ba + 1792)) >> 16;
          if ( v14 )
            break;
          v11 = cinfoa;
        }
        v7 = output_buf;
        v8 = v15;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257AD0
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edi
  unsigned int v8; // ebx
  int v9; // esi
  char *v10; // ecx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // [esp+4h] [ebp-4h]
  int instride; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  instride = cinfo->input_components;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = *(int *)((char *)*output_buf + v8);
      v10 = (char *)*input_buf;
      v8 += 4;
      ++input_buf;
      v11 = 0;
      v13 = v8;
      if ( image_width != 0 )
      {
        do
        {
          v12 = *v10;
          v10 += instride;
          *(_BYTE *)(v11 + v9) = v12;
          ++v11;
        }
        while ( v11 < image_width );
        v8 = v13;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257B30
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  int num_components; // ebx
  unsigned int image_width; // edi
  int i; // edx
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  int nc; // [esp+8h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  num_components = cinfo->num_components;
  image_width = cinfo->image_width;
  nc = num_components;
  if ( !v5 )
  {
    cinfoa = (jpeg_compress_struct *)(4 * output_row);
    do
    {
      for ( i = 0; i < num_components; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)output_buf[i] + (_DWORD)cinfoa);
        v10 = 0;
        if ( image_width != 0 )
        {
          v11 = &(*input_buf)[i];
          do
          {
            v9[v10] = *v11;
            num_components = nc;
            ++v10;
            v11 += nc;
          }
          while ( v10 < image_width );
        }
      }
      ++input_buf;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257BB0
// Name: _jinit_color_converter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_converter(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  J_COLOR_SPACE v5; // eax

  v1 = (jpeg_color_converter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 12);
  cinfo[14].err = (jpeg_error_mgr *)v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))CColorBalanceUIPanel::Init;
  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 1:
      if ( cinfo[1].client_data != (void *)1 )
        goto LABEL_9;
      break;
    case 2:
    case 3:
      if ( cinfo[1].client_data != (void *)3 )
        goto LABEL_9;
      break;
    case 4:
    case 5:
      if ( cinfo[1].client_data != (void *)4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)cinfo[1].client_data < 1 )
      {
LABEL_9:
        cinfo->err->msg_code = 9;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  v2 = *(_DWORD *)&cinfo[2].is_decompressor;
  switch ( v2 )
  {
    case JCS_GRAYSCALE:
      if ( cinfo[2].client_data != (void *)1 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      switch ( v3 )
      {
        case JCS_GRAYSCALE:
          goto LABEL_17;
        case JCS_RGB:
          v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
          v1->color_convert = rgb_gray_convert;
          break;
        case JCS_YCbCr:
LABEL_17:
          v1->color_convert = grayscale_convert;
          break;
        default:
          goto LABEL_37;
      }
      return;
    case JCS_RGB:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor == 2 )
        goto LABEL_41;
      goto LABEL_37;
    case JCS_YCbCr:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v4 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v4 == JCS_RGB )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = rgb_ycc_convert;
        return;
      }
      if ( v4 != JCS_YCbCr )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_CMYK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor != 4 )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_YCCK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v5 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v5 == JCS_CMYK )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = cmyk_ycck_convert;
      }
      else if ( v5 == JCS_YCCK )
      {
LABEL_41:
        v1->color_convert = null_convert;
      }
      else
      {
LABEL_37:
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      return;
    default:
      if ( v2 != *(_DWORD *)&cinfo[1].is_decompressor || cinfo[2].client_data != cinfo[1].client_data )
      {
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      goto LABEL_41;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10257740
// Name: rgb_ycc_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_start(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *err; // esi
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int *v7; // eax
  jpeg_compress_struct *v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+20h] [ebp+8h]

  err = (jpeg_color_converter *)cinfo[14].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 0x2000);
  v3 = 0;
  err[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))v2;
  v4 = 0;
  v5 = 0;
  v12 = 0;
  v13 = 0;
  cinfoa = nullptr;
  v14 = 8421375;
  v6 = 0x8000;
  v7 = (int *)(v2 + 2048);
  do
  {
    v8 = cinfoa;
    cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 21709);
    v7[512] = (int)v8;
    v9 = v14;
    v14 += 0x8000;
    v7[768] = v9;
    v10 = v13;
    v13 -= 27439;
    v7[1024] = v10;
    v11 = v12;
    v12 -= 5329;
    *v7 = v6;
    *(v7 - 512) = v3;
    *(v7 - 256) = v5;
    v7[256] = v4;
    v7[1280] = v11;
    v6 += 7471;
    v3 += 19595;
    ++v7;
    v5 += 38470;
    v4 -= 11059;
  }
  while ( v6 <= 1937873 );
}

//------------------------------------------------------------------------------
// Address: 0x10257810
// Name: rgb_ycc_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // edi
  unsigned int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  int v12; // edi
  bool v13; // zf
  int v14; // [esp+4h] [ebp-14h]
  int g; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  unsigned int num_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 *outptr2; // [esp+14h] [ebp-4h]
  unsigned __int8 *outptr2a; // [esp+14h] [ebp-4h]
  int b; // [esp+20h] [ebp+8h]
  int ba; // [esp+20h] [ebp+8h]
  int num_rowsa; // [esp+30h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = output_row;
    do
    {
      v9 = (int)*input_buf++;
      b = (int)(*v7)[v8];
      v10 = v7[1][v8];
      outptr2 = v7[2][v8++];
      if ( num_cols != 0 )
      {
        v16 = b - (_DWORD)v10;
        v11 = (unsigned __int8 *)(v9 + 2);
        v14 = outptr2 - v10;
        outptr2a = (unsigned __int8 *)num_cols;
        do
        {
          v12 = *(v11 - 2);
          ba = *v11;
          g = *(v11 - 1);
          v10[v16] = (unsigned int)(*((_DWORD *)start_pass + v12)
                                  + *((_DWORD *)start_pass + g + 256)
                                  + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v11 += 3;
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                + *((_DWORD *)start_pass + g + 1024)
                                + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v13 = outptr2a-- == (unsigned __int8 *)1;
          v10[v14 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                      + *((_DWORD *)start_pass + g + 1536)
                                      + *((_DWORD *)start_pass + ba + 1792)) >> 16;
        }
        while ( !v13 );
        v7 = output_buf;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257920
// Name: rgb_gray_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_gray_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edx
  void (__cdecl *start_pass)(jpeg_compress_struct *); // esi
  unsigned int v8; // eax
  int v9; // edi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp+4h] [ebp-8h]
  unsigned int num_cols; // [esp+8h] [ebp-4h]
  unsigned __int8 *outptr; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = image_width;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf++;
      outptr = *(unsigned __int8 **)((char *)*output_buf + v8);
      v8 += 4;
      v10 = 0;
      v12 = v8;
      if ( image_width != 0 )
      {
        v11 = (unsigned __int8 *)(v9 + 2);
        do
        {
          outptr[v10] = (unsigned int)(*((_DWORD *)start_pass + *(v11 - 2))
                                     + *((_DWORD *)start_pass + *(v11 - 1) + 256)
                                     + *((_DWORD *)start_pass + *v11 + 512)) >> 16;
          image_width = num_cols;
          ++v10;
          v11 += 3;
        }
        while ( v10 < num_cols );
        v8 = v12;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102579B0
// Name: cmyk_ycck_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmyk_ycck_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  _BYTE *v10; // edi
  jpeg_compress_struct *v11; // edx
  int v12; // ecx
  int v13; // esi
  bool v14; // zf
  unsigned int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-18h]
  int v17; // [esp+8h] [ebp-14h]
  unsigned __int8 *outptr2; // [esp+Ch] [ebp-10h]
  unsigned __int8 *outptr2a; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 *outptr3; // [esp+14h] [ebp-8h]
  unsigned __int8 *outptr3a; // [esp+14h] [ebp-8h]
  int b; // [esp+18h] [ebp-4h]
  int ba; // [esp+18h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+24h] [ebp+8h]
  int num_rowsa; // [esp+34h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf;
      b = *(int *)((char *)v7[1] + v8);
      outptr2 = *(unsigned __int8 **)((char *)v7[2] + v8);
      ++input_buf;
      v10 = *(unsigned __int8 **)((char *)*v7 + v8);
      outptr3 = *(unsigned __int8 **)((char *)v7[3] + v8);
      v8 += 4;
      v15 = v8;
      if ( num_cols != 0 )
      {
        v17 = outptr3 - v10;
        v16 = b - (_DWORD)v10;
        v11 = (jpeg_compress_struct *)(v9 + 2);
        cinfoa = v11;
        outptr2a = (unsigned __int8 *)(outptr2 - v10);
        outptr3a = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v12 = 255 - BYTE2(v11[-1].script_space_size);
          v13 = 255 - HIBYTE(v11[-1].script_space_size);
          ba = 255 - LOBYTE(v11->err);
          v10[v17] = BYTE1(cinfoa->err);
          cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12)
                                + *((_DWORD *)start_pass + v13 + 256)
                                + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v10[v16 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                      + *((_DWORD *)start_pass + v13 + 1024)
                                      + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v14 = outptr3a-- == (unsigned __int8 *)1;
          v10[(_DWORD)outptr2a - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                                   + *((_DWORD *)start_pass + v13 + 1536)
                                                   + *((_DWORD *)start_pass + ba + 1792)) >> 16;
          if ( v14 )
            break;
          v11 = cinfoa;
        }
        v7 = output_buf;
        v8 = v15;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257B00
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edi
  unsigned int v8; // ebx
  int v9; // esi
  char *v10; // ecx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // [esp+4h] [ebp-4h]
  int instride; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  instride = cinfo->input_components;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = *(int *)((char *)*output_buf + v8);
      v10 = (char *)*input_buf;
      v8 += 4;
      ++input_buf;
      v11 = 0;
      v13 = v8;
      if ( image_width != 0 )
      {
        do
        {
          v12 = *v10;
          v10 += instride;
          *(_BYTE *)(v11 + v9) = v12;
          ++v11;
        }
        while ( v11 < image_width );
        v8 = v13;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257B60
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  int num_components; // ebx
  unsigned int image_width; // edi
  int i; // edx
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  int nc; // [esp+8h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  num_components = cinfo->num_components;
  image_width = cinfo->image_width;
  nc = num_components;
  if ( !v5 )
  {
    cinfoa = (jpeg_compress_struct *)(4 * output_row);
    do
    {
      for ( i = 0; i < num_components; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)output_buf[i] + (_DWORD)cinfoa);
        v10 = 0;
        if ( image_width != 0 )
        {
          v11 = &(*input_buf)[i];
          do
          {
            v9[v10] = *v11;
            num_components = nc;
            ++v10;
            v11 += nc;
          }
          while ( v10 < image_width );
        }
      }
      ++input_buf;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257BE0
// Name: _jinit_color_converter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_converter(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  J_COLOR_SPACE v5; // eax

  v1 = (jpeg_color_converter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 12);
  cinfo[14].err = (jpeg_error_mgr *)v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))CColorBalanceUIPanel::Init;
  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 1:
      if ( cinfo[1].client_data != (void *)1 )
        goto LABEL_9;
      break;
    case 2:
    case 3:
      if ( cinfo[1].client_data != (void *)3 )
        goto LABEL_9;
      break;
    case 4:
    case 5:
      if ( cinfo[1].client_data != (void *)4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)cinfo[1].client_data < 1 )
      {
LABEL_9:
        cinfo->err->msg_code = 9;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  v2 = *(_DWORD *)&cinfo[2].is_decompressor;
  switch ( v2 )
  {
    case JCS_GRAYSCALE:
      if ( cinfo[2].client_data != (void *)1 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      switch ( v3 )
      {
        case JCS_GRAYSCALE:
          goto LABEL_17;
        case JCS_RGB:
          v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
          v1->color_convert = rgb_gray_convert;
          break;
        case JCS_YCbCr:
LABEL_17:
          v1->color_convert = grayscale_convert;
          break;
        default:
          goto LABEL_37;
      }
      return;
    case JCS_RGB:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor == 2 )
        goto LABEL_41;
      goto LABEL_37;
    case JCS_YCbCr:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v4 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v4 == JCS_RGB )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = rgb_ycc_convert;
        return;
      }
      if ( v4 != JCS_YCbCr )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_CMYK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor != 4 )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_YCCK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v5 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v5 == JCS_CMYK )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = cmyk_ycck_convert;
      }
      else if ( v5 == JCS_YCCK )
      {
LABEL_41:
        v1->color_convert = null_convert;
      }
      else
      {
LABEL_37:
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      return;
    default:
      if ( v2 != *(_DWORD *)&cinfo[1].is_decompressor || cinfo[2].client_data != cinfo[1].client_data )
      {
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      goto LABEL_41;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040BC60
// Name: rgb_ycc_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_start(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *err; // esi
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int *v7; // eax
  jpeg_compress_struct *v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+20h] [ebp+8h]

  err = (jpeg_color_converter *)cinfo[14].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 0x2000);
  v3 = 0;
  err[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))v2;
  v4 = 0;
  v5 = 0;
  v12 = 0;
  v13 = 0;
  cinfoa = nullptr;
  v14 = 8421375;
  v6 = 0x8000;
  v7 = (int *)(v2 + 2048);
  do
  {
    v8 = cinfoa;
    cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 21709);
    v7[512] = (int)v8;
    v9 = v14;
    v14 += 0x8000;
    v7[768] = v9;
    v10 = v13;
    v13 -= 27439;
    v7[1024] = v10;
    v11 = v12;
    v12 -= 5329;
    *v7 = v6;
    *(v7 - 512) = v3;
    *(v7 - 256) = v5;
    v7[256] = v4;
    v7[1280] = v11;
    v6 += 7471;
    v3 += 19595;
    ++v7;
    v5 += 38470;
    v4 -= 11059;
  }
  while ( v6 <= 1937873 );
}

//------------------------------------------------------------------------------
// Address: 0x0040BD30
// Name: rgb_ycc_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // edi
  unsigned int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  int v12; // edi
  bool v13; // zf
  int v14; // [esp+4h] [ebp-14h]
  int g; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  unsigned int num_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 *outptr2; // [esp+14h] [ebp-4h]
  unsigned __int8 *outptr2a; // [esp+14h] [ebp-4h]
  int b; // [esp+20h] [ebp+8h]
  int ba; // [esp+20h] [ebp+8h]
  int num_rowsa; // [esp+30h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = output_row;
    do
    {
      v9 = (int)*input_buf++;
      b = (int)(*v7)[v8];
      v10 = v7[1][v8];
      outptr2 = v7[2][v8++];
      if ( num_cols != 0 )
      {
        v16 = b - (_DWORD)v10;
        v11 = (unsigned __int8 *)(v9 + 2);
        v14 = outptr2 - v10;
        outptr2a = (unsigned __int8 *)num_cols;
        do
        {
          v12 = *(v11 - 2);
          ba = *v11;
          g = *(v11 - 1);
          v10[v16] = (unsigned int)(*((_DWORD *)start_pass + v12)
                                  + *((_DWORD *)start_pass + g + 256)
                                  + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v11 += 3;
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                + *((_DWORD *)start_pass + g + 1024)
                                + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v13 = outptr2a-- == (unsigned __int8 *)1;
          v10[v14 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                      + *((_DWORD *)start_pass + g + 1536)
                                      + *((_DWORD *)start_pass + ba + 1792)) >> 16;
        }
        while ( !v13 );
        v7 = output_buf;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BE40
// Name: rgb_gray_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_gray_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edx
  void (__cdecl *start_pass)(jpeg_compress_struct *); // esi
  unsigned int v8; // eax
  int v9; // edi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp+4h] [ebp-8h]
  unsigned int num_cols; // [esp+8h] [ebp-4h]
  unsigned __int8 *outptr; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = image_width;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf++;
      outptr = *(unsigned __int8 **)((char *)*output_buf + v8);
      v8 += 4;
      v10 = 0;
      v12 = v8;
      if ( image_width != 0 )
      {
        v11 = (unsigned __int8 *)(v9 + 2);
        do
        {
          outptr[v10] = (unsigned int)(*((_DWORD *)start_pass + *(v11 - 2))
                                     + *((_DWORD *)start_pass + *(v11 - 1) + 256)
                                     + *((_DWORD *)start_pass + *v11 + 512)) >> 16;
          image_width = num_cols;
          ++v10;
          v11 += 3;
        }
        while ( v10 < num_cols );
        v8 = v12;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BED0
// Name: cmyk_ycck_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmyk_ycck_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  _BYTE *v10; // edi
  jpeg_compress_struct *v11; // edx
  int v12; // ecx
  int v13; // esi
  bool v14; // zf
  unsigned int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-18h]
  int v17; // [esp+8h] [ebp-14h]
  unsigned __int8 *outptr2; // [esp+Ch] [ebp-10h]
  unsigned __int8 *outptr2a; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 *outptr3; // [esp+14h] [ebp-8h]
  unsigned __int8 *outptr3a; // [esp+14h] [ebp-8h]
  int b; // [esp+18h] [ebp-4h]
  int ba; // [esp+18h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+24h] [ebp+8h]
  int num_rowsa; // [esp+34h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf;
      b = *(int *)((char *)v7[1] + v8);
      outptr2 = *(unsigned __int8 **)((char *)v7[2] + v8);
      ++input_buf;
      v10 = *(unsigned __int8 **)((char *)*v7 + v8);
      outptr3 = *(unsigned __int8 **)((char *)v7[3] + v8);
      v8 += 4;
      v15 = v8;
      if ( num_cols != 0 )
      {
        v17 = outptr3 - v10;
        v16 = b - (_DWORD)v10;
        v11 = (jpeg_compress_struct *)(v9 + 2);
        cinfoa = v11;
        outptr2a = (unsigned __int8 *)(outptr2 - v10);
        outptr3a = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v12 = 255 - BYTE2(v11[-1].script_space_size);
          v13 = 255 - HIBYTE(v11[-1].script_space_size);
          ba = 255 - LOBYTE(v11->err);
          v10[v17] = BYTE1(cinfoa->err);
          cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12)
                                + *((_DWORD *)start_pass + v13 + 256)
                                + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v10[v16 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                      + *((_DWORD *)start_pass + v13 + 1024)
                                      + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v14 = outptr3a-- == (unsigned __int8 *)1;
          v10[(_DWORD)outptr2a - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                                   + *((_DWORD *)start_pass + v13 + 1536)
                                                   + *((_DWORD *)start_pass + ba + 1792)) >> 16;
          if ( v14 )
            break;
          v11 = cinfoa;
        }
        v7 = output_buf;
        v8 = v15;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C020
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edi
  unsigned int v8; // ebx
  int v9; // esi
  char *v10; // ecx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // [esp+4h] [ebp-4h]
  int instride; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  instride = cinfo->input_components;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = *(int *)((char *)*output_buf + v8);
      v10 = (char *)*input_buf;
      v8 += 4;
      ++input_buf;
      v11 = 0;
      v13 = v8;
      if ( image_width != 0 )
      {
        do
        {
          v12 = *v10;
          v10 += instride;
          *(_BYTE *)(v11 + v9) = v12;
          ++v11;
        }
        while ( v11 < image_width );
        v8 = v13;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C080
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  int num_components; // ebx
  unsigned int image_width; // edi
  int i; // edx
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  int nc; // [esp+8h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  num_components = cinfo->num_components;
  image_width = cinfo->image_width;
  nc = num_components;
  if ( !v5 )
  {
    cinfoa = (jpeg_compress_struct *)(4 * output_row);
    do
    {
      for ( i = 0; i < num_components; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)output_buf[i] + (_DWORD)cinfoa);
        v10 = 0;
        if ( image_width != 0 )
        {
          v11 = &(*input_buf)[i];
          do
          {
            v9[v10] = *v11;
            num_components = nc;
            ++v10;
            v11 += nc;
          }
          while ( v10 < image_width );
        }
      }
      ++input_buf;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C100
// Name: _jinit_color_converter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_converter(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  J_COLOR_SPACE v5; // eax

  v1 = (jpeg_color_converter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 12);
  cinfo[14].err = (jpeg_error_mgr *)v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_mem_term;
  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 1:
      if ( cinfo[1].client_data != (void *)1 )
        goto LABEL_9;
      break;
    case 2:
    case 3:
      if ( cinfo[1].client_data != (void *)3 )
        goto LABEL_9;
      break;
    case 4:
    case 5:
      if ( cinfo[1].client_data != (void *)4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)cinfo[1].client_data < 1 )
      {
LABEL_9:
        cinfo->err->msg_code = 9;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  v2 = *(_DWORD *)&cinfo[2].is_decompressor;
  switch ( v2 )
  {
    case JCS_GRAYSCALE:
      if ( cinfo[2].client_data != (void *)1 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      switch ( v3 )
      {
        case JCS_GRAYSCALE:
          goto LABEL_17;
        case JCS_RGB:
          v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
          v1->color_convert = rgb_gray_convert;
          break;
        case JCS_YCbCr:
LABEL_17:
          v1->color_convert = grayscale_convert;
          break;
        default:
          goto LABEL_37;
      }
      return;
    case JCS_RGB:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor == 2 )
        goto LABEL_41;
      goto LABEL_37;
    case JCS_YCbCr:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v4 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v4 == JCS_RGB )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = rgb_ycc_convert;
        return;
      }
      if ( v4 != JCS_YCbCr )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_CMYK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor != 4 )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_YCCK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v5 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v5 == JCS_CMYK )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = cmyk_ycck_convert;
      }
      else if ( v5 == JCS_YCCK )
      {
LABEL_41:
        v1->color_convert = null_convert;
      }
      else
      {
LABEL_37:
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      return;
    default:
      if ( v2 != *(_DWORD *)&cinfo[1].is_decompressor || cinfo[2].client_data != cinfo[1].client_data )
      {
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      goto LABEL_41;
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00434F70
// Name: rgb_ycc_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_start(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *err; // esi
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int *v7; // eax
  jpeg_compress_struct *v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+20h] [ebp+8h]

  err = (jpeg_color_converter *)cinfo[14].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 0x2000);
  v3 = 0;
  err[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))v2;
  v4 = 0;
  v5 = 0;
  v12 = 0;
  v13 = 0;
  cinfoa = nullptr;
  v14 = 8421375;
  v6 = 0x8000;
  v7 = (int *)(v2 + 2048);
  do
  {
    v8 = cinfoa;
    cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 21709);
    v7[512] = (int)v8;
    v9 = v14;
    v14 += 0x8000;
    v7[768] = v9;
    v10 = v13;
    v13 -= 27439;
    v7[1024] = v10;
    v11 = v12;
    v12 -= 5329;
    *v7 = v6;
    *(v7 - 512) = v3;
    *(v7 - 256) = v5;
    v7[256] = v4;
    v7[1280] = v11;
    v6 += 7471;
    v3 += 19595;
    ++v7;
    v5 += 38470;
    v4 -= 11059;
  }
  while ( v6 <= 1937873 );
}

//------------------------------------------------------------------------------
// Address: 0x00435040
// Name: rgb_ycc_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // edi
  unsigned int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  int v12; // edi
  bool v13; // zf
  int v14; // [esp+4h] [ebp-14h]
  int g; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  unsigned int num_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 *outptr2; // [esp+14h] [ebp-4h]
  unsigned __int8 *outptr2a; // [esp+14h] [ebp-4h]
  int b; // [esp+20h] [ebp+8h]
  int ba; // [esp+20h] [ebp+8h]
  int num_rowsa; // [esp+30h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = output_row;
    do
    {
      v9 = (int)*input_buf++;
      b = (int)(*v7)[v8];
      v10 = v7[1][v8];
      outptr2 = v7[2][v8++];
      if ( num_cols != 0 )
      {
        v16 = b - (_DWORD)v10;
        v11 = (unsigned __int8 *)(v9 + 2);
        v14 = outptr2 - v10;
        outptr2a = (unsigned __int8 *)num_cols;
        do
        {
          v12 = *(v11 - 2);
          ba = *v11;
          g = *(v11 - 1);
          v10[v16] = (unsigned int)(*((_DWORD *)start_pass + v12)
                                  + *((_DWORD *)start_pass + g + 256)
                                  + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v11 += 3;
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                + *((_DWORD *)start_pass + g + 1024)
                                + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v13 = outptr2a-- == (unsigned __int8 *)1;
          v10[v14 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                      + *((_DWORD *)start_pass + g + 1536)
                                      + *((_DWORD *)start_pass + ba + 1792)) >> 16;
        }
        while ( !v13 );
        v7 = output_buf;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435150
// Name: rgb_gray_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_gray_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edx
  void (__cdecl *start_pass)(jpeg_compress_struct *); // esi
  unsigned int v8; // eax
  int v9; // edi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp+4h] [ebp-8h]
  unsigned int num_cols; // [esp+8h] [ebp-4h]
  unsigned __int8 *outptr; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = image_width;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf++;
      outptr = *(unsigned __int8 **)((char *)*output_buf + v8);
      v8 += 4;
      v10 = 0;
      v12 = v8;
      if ( image_width != 0 )
      {
        v11 = (unsigned __int8 *)(v9 + 2);
        do
        {
          outptr[v10] = (unsigned int)(*((_DWORD *)start_pass + *(v11 - 2))
                                     + *((_DWORD *)start_pass + *(v11 - 1) + 256)
                                     + *((_DWORD *)start_pass + *v11 + 512)) >> 16;
          image_width = num_cols;
          ++v10;
          v11 += 3;
        }
        while ( v10 < num_cols );
        v8 = v12;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004351E0
// Name: cmyk_ycck_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmyk_ycck_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  _BYTE *v10; // edi
  jpeg_compress_struct *v11; // edx
  int v12; // ecx
  int v13; // esi
  bool v14; // zf
  unsigned int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-18h]
  int v17; // [esp+8h] [ebp-14h]
  unsigned __int8 *outptr2; // [esp+Ch] [ebp-10h]
  unsigned __int8 *outptr2a; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 *outptr3; // [esp+14h] [ebp-8h]
  unsigned __int8 *outptr3a; // [esp+14h] [ebp-8h]
  int b; // [esp+18h] [ebp-4h]
  int ba; // [esp+18h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+24h] [ebp+8h]
  int num_rowsa; // [esp+34h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf;
      b = *(int *)((char *)v7[1] + v8);
      outptr2 = *(unsigned __int8 **)((char *)v7[2] + v8);
      ++input_buf;
      v10 = *(unsigned __int8 **)((char *)*v7 + v8);
      outptr3 = *(unsigned __int8 **)((char *)v7[3] + v8);
      v8 += 4;
      v15 = v8;
      if ( num_cols != 0 )
      {
        v17 = outptr3 - v10;
        v16 = b - (_DWORD)v10;
        v11 = (jpeg_compress_struct *)(v9 + 2);
        cinfoa = v11;
        outptr2a = (unsigned __int8 *)(outptr2 - v10);
        outptr3a = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v12 = 255 - BYTE2(v11[-1].script_space_size);
          v13 = 255 - HIBYTE(v11[-1].script_space_size);
          ba = 255 - LOBYTE(v11->err);
          v10[v17] = BYTE1(cinfoa->err);
          cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12)
                                + *((_DWORD *)start_pass + v13 + 256)
                                + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v10[v16 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                      + *((_DWORD *)start_pass + v13 + 1024)
                                      + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v14 = outptr3a-- == (unsigned __int8 *)1;
          v10[(_DWORD)outptr2a - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                                   + *((_DWORD *)start_pass + v13 + 1536)
                                                   + *((_DWORD *)start_pass + ba + 1792)) >> 16;
          if ( v14 )
            break;
          v11 = cinfoa;
        }
        v7 = output_buf;
        v8 = v15;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435330
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edi
  unsigned int v8; // ebx
  int v9; // esi
  char *v10; // ecx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // [esp+4h] [ebp-4h]
  int instride; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  instride = cinfo->input_components;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = *(int *)((char *)*output_buf + v8);
      v10 = (char *)*input_buf;
      v8 += 4;
      ++input_buf;
      v11 = 0;
      v13 = v8;
      if ( image_width != 0 )
      {
        do
        {
          v12 = *v10;
          v10 += instride;
          *(_BYTE *)(v11 + v9) = v12;
          ++v11;
        }
        while ( v11 < image_width );
        v8 = v13;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435390
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  int num_components; // ebx
  unsigned int image_width; // edi
  int i; // edx
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  int nc; // [esp+8h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  num_components = cinfo->num_components;
  image_width = cinfo->image_width;
  nc = num_components;
  if ( !v5 )
  {
    cinfoa = (jpeg_compress_struct *)(4 * output_row);
    do
    {
      for ( i = 0; i < num_components; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)output_buf[i] + (_DWORD)cinfoa);
        v10 = 0;
        if ( image_width != 0 )
        {
          v11 = &(*input_buf)[i];
          do
          {
            v9[v10] = *v11;
            num_components = nc;
            ++v10;
            v11 += nc;
          }
          while ( v10 < image_width );
        }
      }
      ++input_buf;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435410
// Name: _jinit_color_converter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_converter(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  J_COLOR_SPACE v5; // eax

  v1 = (jpeg_color_converter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 12);
  cinfo[14].err = (jpeg_error_mgr *)v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_mem_term;
  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 1:
      if ( cinfo[1].client_data != (void *)1 )
        goto LABEL_9;
      break;
    case 2:
    case 3:
      if ( cinfo[1].client_data != (void *)3 )
        goto LABEL_9;
      break;
    case 4:
    case 5:
      if ( cinfo[1].client_data != (void *)4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)cinfo[1].client_data < 1 )
      {
LABEL_9:
        cinfo->err->msg_code = 9;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  v2 = *(_DWORD *)&cinfo[2].is_decompressor;
  switch ( v2 )
  {
    case JCS_GRAYSCALE:
      if ( cinfo[2].client_data != (void *)1 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      switch ( v3 )
      {
        case JCS_GRAYSCALE:
          goto LABEL_17;
        case JCS_RGB:
          v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
          v1->color_convert = rgb_gray_convert;
          break;
        case JCS_YCbCr:
LABEL_17:
          v1->color_convert = grayscale_convert;
          break;
        default:
          goto LABEL_37;
      }
      return;
    case JCS_RGB:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor == 2 )
        goto LABEL_41;
      goto LABEL_37;
    case JCS_YCbCr:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v4 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v4 == JCS_RGB )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = rgb_ycc_convert;
        return;
      }
      if ( v4 != JCS_YCbCr )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_CMYK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor != 4 )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_YCCK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v5 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v5 == JCS_CMYK )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = cmyk_ycck_convert;
      }
      else if ( v5 == JCS_YCCK )
      {
LABEL_41:
        v1->color_convert = null_convert;
      }
      else
      {
LABEL_37:
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      return;
    default:
      if ( v2 != *(_DWORD *)&cinfo[1].is_decompressor || cinfo[2].client_data != cinfo[1].client_data )
      {
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      goto LABEL_41;
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00421D80
// Name: rgb_ycc_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_start(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *err; // esi
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int *v7; // eax
  jpeg_compress_struct *v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+20h] [ebp+8h]

  err = (jpeg_color_converter *)cinfo[14].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 0x2000);
  v3 = 0;
  err[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))v2;
  v4 = 0;
  v5 = 0;
  v12 = 0;
  v13 = 0;
  cinfoa = nullptr;
  v14 = 8421375;
  v6 = 0x8000;
  v7 = (int *)(v2 + 2048);
  do
  {
    v8 = cinfoa;
    cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 21709);
    v7[512] = (int)v8;
    v9 = v14;
    v14 += 0x8000;
    v7[768] = v9;
    v10 = v13;
    v13 -= 27439;
    v7[1024] = v10;
    v11 = v12;
    v12 -= 5329;
    *v7 = v6;
    *(v7 - 512) = v3;
    *(v7 - 256) = v5;
    v7[256] = v4;
    v7[1280] = v11;
    v6 += 7471;
    v3 += 19595;
    ++v7;
    v5 += 38470;
    v4 -= 11059;
  }
  while ( v6 <= 1937873 );
}

//------------------------------------------------------------------------------
// Address: 0x00421E50
// Name: rgb_ycc_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_ycc_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // edi
  unsigned int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  int v12; // edi
  bool v13; // zf
  int v14; // [esp+4h] [ebp-14h]
  int g; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  unsigned int num_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 *outptr2; // [esp+14h] [ebp-4h]
  unsigned __int8 *outptr2a; // [esp+14h] [ebp-4h]
  int b; // [esp+20h] [ebp+8h]
  int ba; // [esp+20h] [ebp+8h]
  int num_rowsa; // [esp+30h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = output_row;
    do
    {
      v9 = (int)*input_buf++;
      b = (int)(*v7)[v8];
      v10 = v7[1][v8];
      outptr2 = v7[2][v8++];
      if ( num_cols != 0 )
      {
        v16 = b - (_DWORD)v10;
        v11 = (unsigned __int8 *)(v9 + 2);
        v14 = outptr2 - v10;
        outptr2a = (unsigned __int8 *)num_cols;
        do
        {
          v12 = *(v11 - 2);
          ba = *v11;
          g = *(v11 - 1);
          v10[v16] = (unsigned int)(*((_DWORD *)start_pass + v12)
                                  + *((_DWORD *)start_pass + g + 256)
                                  + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v11 += 3;
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                + *((_DWORD *)start_pass + g + 1024)
                                + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v13 = outptr2a-- == (unsigned __int8 *)1;
          v10[v14 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                      + *((_DWORD *)start_pass + g + 1536)
                                      + *((_DWORD *)start_pass + ba + 1792)) >> 16;
        }
        while ( !v13 );
        v7 = output_buf;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421F60
// Name: rgb_gray_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl rgb_gray_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edx
  void (__cdecl *start_pass)(jpeg_compress_struct *); // esi
  unsigned int v8; // eax
  int v9; // edi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned int v12; // [esp+4h] [ebp-8h]
  unsigned int num_cols; // [esp+8h] [ebp-4h]
  unsigned __int8 *outptr; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = image_width;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf++;
      outptr = *(unsigned __int8 **)((char *)*output_buf + v8);
      v8 += 4;
      v10 = 0;
      v12 = v8;
      if ( image_width != 0 )
      {
        v11 = (unsigned __int8 *)(v9 + 2);
        do
        {
          outptr[v10] = (unsigned int)(*((_DWORD *)start_pass + *(v11 - 2))
                                     + *((_DWORD *)start_pass + *(v11 - 1) + 256)
                                     + *((_DWORD *)start_pass + *v11 + 512)) >> 16;
          image_width = num_cols;
          ++v10;
          v11 += 3;
        }
        while ( v10 < num_cols );
        v8 = v12;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421FF0
// Name: cmyk_ycck_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmyk_ycck_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  void (__cdecl *start_pass)(jpeg_compress_struct *); // eax
  unsigned __int8 ***v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  _BYTE *v10; // edi
  jpeg_compress_struct *v11; // edx
  int v12; // ecx
  int v13; // esi
  bool v14; // zf
  unsigned int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-18h]
  int v17; // [esp+8h] [ebp-14h]
  unsigned __int8 *outptr2; // [esp+Ch] [ebp-10h]
  unsigned __int8 *outptr2a; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 *outptr3; // [esp+14h] [ebp-8h]
  unsigned __int8 *outptr3a; // [esp+14h] [ebp-8h]
  int b; // [esp+18h] [ebp-4h]
  int ba; // [esp+18h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+24h] [ebp+8h]
  int num_rowsa; // [esp+34h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  start_pass = cinfo->cconvert[1].start_pass;
  num_cols = cinfo->image_width;
  if ( !v5 )
  {
    v7 = output_buf;
    v8 = 4 * output_row;
    do
    {
      v9 = (int)*input_buf;
      b = *(int *)((char *)v7[1] + v8);
      outptr2 = *(unsigned __int8 **)((char *)v7[2] + v8);
      ++input_buf;
      v10 = *(unsigned __int8 **)((char *)*v7 + v8);
      outptr3 = *(unsigned __int8 **)((char *)v7[3] + v8);
      v8 += 4;
      v15 = v8;
      if ( num_cols != 0 )
      {
        v17 = outptr3 - v10;
        v16 = b - (_DWORD)v10;
        v11 = (jpeg_compress_struct *)(v9 + 2);
        cinfoa = v11;
        outptr2a = (unsigned __int8 *)(outptr2 - v10);
        outptr3a = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v12 = 255 - BYTE2(v11[-1].script_space_size);
          v13 = 255 - HIBYTE(v11[-1].script_space_size);
          ba = 255 - LOBYTE(v11->err);
          v10[v17] = BYTE1(cinfoa->err);
          cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
          *v10++ = (unsigned int)(*((_DWORD *)start_pass + v12)
                                + *((_DWORD *)start_pass + v13 + 256)
                                + *((_DWORD *)start_pass + ba + 512)) >> 16;
          v10[v16 - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 768)
                                      + *((_DWORD *)start_pass + v13 + 1024)
                                      + *((_DWORD *)start_pass + ba + 1280)) >> 16;
          v14 = outptr3a-- == (unsigned __int8 *)1;
          v10[(_DWORD)outptr2a - 1] = (unsigned int)(*((_DWORD *)start_pass + v12 + 1280)
                                                   + *((_DWORD *)start_pass + v13 + 1536)
                                                   + *((_DWORD *)start_pass + ba + 1792)) >> 16;
          if ( v14 )
            break;
          v11 = cinfoa;
        }
        v7 = output_buf;
        v8 = v15;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422140
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  unsigned int image_width; // edi
  unsigned int v8; // ebx
  int v9; // esi
  char *v10; // ecx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // [esp+4h] [ebp-4h]
  int instride; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  image_width = cinfo->image_width;
  instride = cinfo->input_components;
  if ( !v5 )
  {
    v8 = 4 * output_row;
    do
    {
      v9 = *(int *)((char *)*output_buf + v8);
      v10 = (char *)*input_buf;
      v8 += 4;
      ++input_buf;
      v11 = 0;
      v13 = v8;
      if ( image_width != 0 )
      {
        do
        {
          v12 = *v10;
          v10 += instride;
          *(_BYTE *)(v11 + v9) = v12;
          ++v11;
        }
        while ( v11 < image_width );
        v8 = v13;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004221A0
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 ***output_buf,
        unsigned int output_row,
        int num_rows)
{
  bool v5; // sf
  int num_components; // ebx
  unsigned int image_width; // edi
  int i; // edx
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  int nc; // [esp+8h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+14h] [ebp+8h]
  int num_rowsa; // [esp+24h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  num_components = cinfo->num_components;
  image_width = cinfo->image_width;
  nc = num_components;
  if ( !v5 )
  {
    cinfoa = (jpeg_compress_struct *)(4 * output_row);
    do
    {
      for ( i = 0; i < num_components; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)output_buf[i] + (_DWORD)cinfoa);
        v10 = 0;
        if ( image_width != 0 )
        {
          v11 = &(*input_buf)[i];
          do
          {
            v9[v10] = *v11;
            num_components = nc;
            ++v10;
            v11 += nc;
          }
          while ( v10 < image_width );
        }
      }
      ++input_buf;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422220
// Name: _jinit_color_converter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_converter(jpeg_common_struct *cinfo)
{
  jpeg_color_converter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  J_COLOR_SPACE v5; // eax

  v1 = (jpeg_color_converter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 12);
  cinfo[14].err = (jpeg_error_mgr *)v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_mem_term;
  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 1:
      if ( cinfo[1].client_data != (void *)1 )
        goto LABEL_9;
      break;
    case 2:
    case 3:
      if ( cinfo[1].client_data != (void *)3 )
        goto LABEL_9;
      break;
    case 4:
    case 5:
      if ( cinfo[1].client_data != (void *)4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)cinfo[1].client_data < 1 )
      {
LABEL_9:
        cinfo->err->msg_code = 9;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  v2 = *(_DWORD *)&cinfo[2].is_decompressor;
  switch ( v2 )
  {
    case JCS_GRAYSCALE:
      if ( cinfo[2].client_data != (void *)1 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      switch ( v3 )
      {
        case JCS_GRAYSCALE:
          goto LABEL_17;
        case JCS_RGB:
          v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
          v1->color_convert = rgb_gray_convert;
          break;
        case JCS_YCbCr:
LABEL_17:
          v1->color_convert = grayscale_convert;
          break;
        default:
          goto LABEL_37;
      }
      return;
    case JCS_RGB:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor == 2 )
        goto LABEL_41;
      goto LABEL_37;
    case JCS_YCbCr:
      if ( cinfo[2].client_data != (void *)3 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v4 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v4 == JCS_RGB )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = rgb_ycc_convert;
        return;
      }
      if ( v4 != JCS_YCbCr )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_CMYK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *(_DWORD *)&cinfo[1].is_decompressor != 4 )
        goto LABEL_37;
      goto LABEL_41;
    case JCS_YCCK:
      if ( cinfo[2].client_data != (void *)4 )
      {
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v5 = *(_DWORD *)&cinfo[1].is_decompressor;
      if ( v5 == JCS_CMYK )
      {
        v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *))rgb_ycc_start;
        v1->color_convert = cmyk_ycck_convert;
      }
      else if ( v5 == JCS_YCCK )
      {
LABEL_41:
        v1->color_convert = null_convert;
      }
      else
      {
LABEL_37:
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      return;
    default:
      if ( v2 != *(_DWORD *)&cinfo[1].is_decompressor || cinfo[2].client_data != cinfo[1].client_data )
      {
        cinfo->err->msg_code = 27;
        cinfo->err->error_exit(a1: cinfo);
      }
      goto LABEL_41;
  }
}

} // namespace vxconsole_ps3
