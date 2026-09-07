// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdcolor.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10010980
// Name: build_ycc_rgb_table
// Source: json
//------------------------------------------------------------------------------
void __usercall build_ycc_rgb_table(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_color_deconverter *client_data; // esi
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  client_data = (jpeg_color_deconverter *)cinfo[17].client_data;
  client_data[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                            a1: cinfo,
                                                                            a2: 1,
                                                                            a3: 1024);
  client_data[1].color_convert = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int, unsigned __int8 **, int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  client_data[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                            a1: cinfo,
                                                                            a2: 1,
                                                                            a3: 1024);
  client_data[2].color_convert = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int, unsigned __int8 **, int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  v3 = 0;
  v7 = 5990656;
  v8 = -14831872;
  v4 = -11728000;
  v5 = 2919680;
  do
  {
    *(_DWORD *)((char *)client_data[1].start_pass + v3) = v4 >> 16;
    v6 = v8;
    v8 += 116130;
    *(_DWORD *)((char *)client_data[1].color_convert + v3) = v6 >> 16;
    *(_DWORD *)((char *)client_data[2].start_pass + v3) = v7;
    *(_DWORD *)((char *)client_data[2].color_convert + v3) = v5;
    v5 -= 22554;
    v4 += 91881;
    v3 += 4;
    v7 -= 46802;
  }
  while ( v5 >= -2831590 );
}

//------------------------------------------------------------------------------
// Address: 0x10010A50
// Name: ycc_rgb_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl ycc_rgb_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  jpeg_color_deconverter *cconvert; // eax
  unsigned __int8 *sample_range_limit; // edx
  unsigned int output_width; // ebx
  unsigned __int8 ***v9; // esi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // esi
  unsigned __int8 *v14; // ecx
  _BYTE *v15; // eax
  unsigned __int8 *v16; // edi
  int v17; // edi
  int v18; // esi
  unsigned int v19; // [esp+4h] [ebp-2Ch]
  unsigned int num_cols; // [esp+8h] [ebp-28h]
  int *Cbbtab; // [esp+Ch] [ebp-24h]
  unsigned __int8 *range_limit; // [esp+10h] [ebp-20h]
  int *Crrtab; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v25; // [esp+20h] [ebp-10h]
  unsigned __int8 *inptr1; // [esp+24h] [ebp-Ch]
  unsigned __int8 *inptr2; // [esp+28h] [ebp-8h]
  unsigned __int8 *inptr0; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *inptr0a; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *outptr; // [esp+38h] [ebp+8h]
  int num_rowsa; // [esp+48h] [ebp+18h]
  jpeg_color_deconverter Crgtab; // 0:^1C.8

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  cconvert = cinfo->cconvert;
  sample_range_limit = cinfo->sample_range_limit;
  output_width = cinfo->output_width;
  Crrtab = (int *)cconvert[1].start_pass;
  Cbbtab = (int *)cconvert[1].color_convert;
  num_cols = output_width;
  range_limit = sample_range_limit;
  Crgtab = cconvert[2];
  if ( !v5 )
  {
    v9 = input_buf;
    v10 = 4 * input_row;
    do
    {
      inptr0 = *(unsigned __int8 **)((char *)*v9 + v10);
      v11 = *(unsigned __int8 **)((char *)v9[1] + v10);
      inptr2 = *(unsigned __int8 **)((char *)v9[2] + v10);
      v12 = (int)*output_buf++;
      v10 += 4;
      v19 = v10;
      if ( output_width != 0 )
      {
        v13 = (unsigned __int8 *)(inptr0 - v11);
        v14 = v11;
        v15 = (_BYTE *)(v12 + 2);
        v16 = (unsigned __int8 *)(inptr2 - v11);
        v25 = v13;
        inptr1 = v16;
        inptr0a = (unsigned __int8 *)output_width;
        while ( 1 )
        {
          v17 = v14[(_DWORD)v16];
          v18 = v14[(_DWORD)v13];
          outptr = (unsigned __int8 *)*v14;
          *(v15 - 2) = sample_range_limit[v18 + Crrtab[v17]];
          sample_range_limit = range_limit;
          *(v15 - 1) = range_limit[v18
                                 + ((*((_DWORD *)Crgtab.start_pass + v17)
                                   + *((_DWORD *)Crgtab.color_convert + (_DWORD)outptr)) >> 16)];
          *v15 = range_limit[v18 + Cbbtab[(_DWORD)outptr]];
          v15 += 3;
          ++v14;
          if ( --inptr0a == nullptr )
            break;
          v13 = v25;
          v16 = inptr1;
        }
        output_width = num_cols;
        v9 = input_buf;
        v10 = v19;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010B70
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  unsigned int output_width; // edx
  int v7; // ebx
  int i; // esi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned int j; // edi
  int num_components; // [esp+4h] [ebp-4h]
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  output_width = cinfo->output_width;
  v7 = cinfo->num_components;
  num_components = v7;
  if ( !v5 )
  {
    cinfoa = (jpeg_decompress_struct *)(4 * input_row);
    do
    {
      for ( i = 0; i < v7; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)input_buf[i] + (_DWORD)cinfoa);
        v10 = &(*output_buf)[i];
        for ( j = output_width; j != 0; --j )
        {
          *v10 = *v9;
          v7 = num_components;
          ++v9;
          v10 += num_components;
        }
      }
      cinfoa = (jpeg_decompress_struct *)((char *)cinfoa + 4);
      ++output_buf;
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010BF0
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jcopy_sample_rows(
    input_array: *input_buf,
    source_row: input_row,
    output_array: output_buf,
    dest_row: 0,
    num_rows,
    num_cols: cinfo->output_width);
}

//------------------------------------------------------------------------------
// Address: 0x10010C20
// Name: gray_rgb_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl gray_rgb_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  unsigned int output_width; // edi
  unsigned int v8; // ecx
  int v9; // esi
  int v10; // eax
  unsigned int v11; // edx
  _BYTE *v12; // eax
  char v13; // cl
  jpeg_decompress_struct *cinfoa; // [esp+Ch] [ebp+8h]
  int num_rowsa; // [esp+1Ch] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  output_width = cinfo->output_width;
  if ( !v5 )
  {
    v8 = 4 * input_row;
    do
    {
      v9 = *(int *)((char *)*input_buf + v8);
      v10 = (int)*output_buf;
      v8 += 4;
      ++output_buf;
      v11 = 0;
      cinfoa = (jpeg_decompress_struct *)v8;
      if ( output_width != 0 )
      {
        v12 = (_BYTE *)(v10 + 1);
        do
        {
          v13 = *(_BYTE *)(v11 + v9);
          v12[1] = v13;
          *v12 = v13;
          *(v12 - 1) = v13;
          ++v11;
          v12 += 3;
        }
        while ( v11 < output_width );
        v8 = (unsigned int)cinfoa;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010C80
// Name: ycck_cmyk_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl ycck_cmyk_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  jpeg_color_deconverter *cconvert; // eax
  unsigned __int8 *sample_range_limit; // ecx
  unsigned __int8 ***v8; // esi
  unsigned int v9; // edx
  int v10; // edi
  unsigned __int8 *v11; // ecx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  unsigned int v20; // [esp+0h] [ebp-2Ch]
  int v21; // [esp+4h] [ebp-28h]
  int *Cbbtab; // [esp+8h] [ebp-24h]
  int *Crrtab; // [esp+14h] [ebp-18h]
  int v25; // [esp+18h] [ebp-14h]
  int v26; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *outptr; // [esp+20h] [ebp-Ch]
  unsigned __int8 *inptr3; // [esp+24h] [ebp-8h]
  unsigned __int8 *range_limit; // [esp+28h] [ebp-4h]
  unsigned int num_cols; // [esp+34h] [ebp+8h]
  int num_rowsa; // [esp+44h] [ebp+18h]
  jpeg_color_deconverter Crgtab; // 0:^18.8

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  cconvert = cinfo->cconvert;
  sample_range_limit = cinfo->sample_range_limit;
  num_cols = cinfo->output_width;
  range_limit = sample_range_limit;
  Crrtab = (int *)cconvert[1].start_pass;
  Cbbtab = (int *)cconvert[1].color_convert;
  Crgtab = cconvert[2];
  if ( !v5 )
  {
    v8 = input_buf;
    v9 = 4 * input_row;
    do
    {
      v10 = *(int *)((char *)*v8 + v9);
      v11 = *(unsigned __int8 **)((char *)v8[1] + v9);
      v12 = *(int *)((char *)v8[2] + v9);
      inptr3 = *(unsigned __int8 **)((char *)v8[3] + v9);
      v13 = (int)*output_buf++;
      v9 += 4;
      v20 = v9;
      if ( num_cols != 0 )
      {
        v14 = v10 - (_DWORD)v11;
        v15 = v12 - (_DWORD)v11;
        v16 = v13 + 2;
        v21 = inptr3 - v11;
        v26 = v14;
        v25 = v12 - (_DWORD)v11;
        outptr = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v17 = v11[v14];
          v18 = v11[v15];
          v19 = *v11;
          *(_BYTE *)(v16 - 2) = range_limit[-Crrtab[v18] - v17 + 255];
          *(_BYTE *)(v16 - 1) = range_limit[-((*((_DWORD *)Crgtab.start_pass + v18)
                                             + *((_DWORD *)Crgtab.color_convert + v19)) >> 16)
                                          - v17
                                          + 255];
          v16 += 4;
          *(_BYTE *)(v16 - 4) = range_limit[-Cbbtab[v19] - v17 + 255];
          *(_BYTE *)(v16 - 3) = (v11++)[v21];
          if ( --outptr == nullptr )
            break;
          v14 = v26;
          v15 = v25;
        }
        v8 = input_buf;
        v9 = v20;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010DC0
// Name: _jinit_color_deconverter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_deconverter(jpeg_common_struct *cinfo)
{
  jpeg_color_deconverter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  int v5; // eax
  int v6; // ecx

  v1 = (jpeg_color_deconverter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 24);
  cinfo[17].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_decompress_struct *))jpeg_mem_term;
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
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  if ( cinfo[1].global_state != 1 )
  {
    if ( cinfo[1].global_state == 2 )
    {
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      cinfo[4].mem = (jpeg_memory_mgr *)3;
      switch ( v3 )
      {
        case JCS_YCbCr:
          v1->color_convert = ycc_rgb_convert;
          build_ycc_rgb_table(cinfo);
          goto LABEL_31;
        case JCS_GRAYSCALE:
          v1->color_convert = gray_rgb_convert;
          goto LABEL_31;
        case JCS_RGB:
          v1->color_convert = null_convert;
          goto LABEL_31;
        default:
          break;
      }
    }
    else if ( cinfo[1].global_state == 4 )
    {
      v2 = *(_DWORD *)&cinfo[1].is_decompressor;
      cinfo[4].mem = (jpeg_memory_mgr *)4;
      if ( v2 == JCS_YCCK )
      {
        v1->color_convert = ycck_cmyk_convert;
        build_ycc_rgb_table(cinfo);
        goto LABEL_31;
      }
      if ( v2 == JCS_CMYK )
      {
        v1->color_convert = null_convert;
        goto LABEL_31;
      }
    }
    else if ( cinfo[1].global_state == *(_DWORD *)&cinfo[1].is_decompressor )
    {
      cinfo[4].mem = (jpeg_memory_mgr *)cinfo[1].client_data;
      v1->color_convert = null_convert;
      goto LABEL_31;
    }
    goto LABEL_27;
  }
  v4 = *(_DWORD *)&cinfo[1].is_decompressor;
  cinfo[4].mem = (jpeg_memory_mgr *)1;
  if ( v4 != JCS_GRAYSCALE && v4 != JCS_YCbCr )
  {
LABEL_27:
    cinfo->err->msg_code = 27;
    cinfo->err->error_exit(a1: cinfo);
    goto LABEL_31;
  }
  v1->color_convert = grayscale_convert;
  v5 = 1;
  if ( (int)cinfo[1].client_data > 1 )
  {
    v6 = 84;
    do
    {
      *((_BYTE *)&cinfo[8].mem->max_alloc_chunk + v6) = 0;
      ++v5;
      v6 += 84;
    }
    while ( v5 < (int)cinfo[1].client_data );
  }
LABEL_31:
  if ( BYTE2(cinfo[3].err) != 0 )
    cinfo[4].progress = (jpeg_progress_mgr *)1;
  else
    cinfo[4].progress = (jpeg_progress_mgr *)cinfo[4].mem;
}

//------------------------------------------------------------------------------
// Address: 0x10010F50
// Name: build_ycc_rgb_table_0
// Source: json
//------------------------------------------------------------------------------
void __usercall build_ycc_rgb_table_0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_upsampler *progress; // esi
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  progress = (jpeg_upsampler *)cinfo[17].progress;
  progress[1].upsample = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  *(_DWORD *)&progress[1].need_context_rows = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  progress[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                         a1: cinfo,
                                                                         a2: 1,
                                                                         a3: 1024);
  progress[2].upsample = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  v3 = 0;
  v7 = 5990656;
  v8 = -14831872;
  v4 = -11728000;
  v5 = 2919680;
  do
  {
    *(_DWORD *)((char *)progress[1].upsample + v3) = v4 >> 16;
    v6 = v8;
    v8 += 116130;
    *(_DWORD *)(v3 + *(_DWORD *)&progress[1].need_context_rows) = v6 >> 16;
    *(_DWORD *)((char *)progress[2].start_pass + v3) = v7;
    *(_DWORD *)((char *)progress[2].upsample + v3) = v5;
    v5 -= 22554;
    v4 += 91881;
    v3 += 4;
    v7 -= 46802;
  }
  while ( v5 >= -2831590 );
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102796F0
// Name: build_ycc_rgb_table
// Source: json
//------------------------------------------------------------------------------
void __usercall build_ycc_rgb_table(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_color_deconverter *client_data; // esi
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  client_data = (jpeg_color_deconverter *)cinfo[17].client_data;
  client_data[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                            a1: cinfo,
                                                                            a2: 1,
                                                                            a3: 1024);
  client_data[1].color_convert = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int, unsigned __int8 **, int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  client_data[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                            a1: cinfo,
                                                                            a2: 1,
                                                                            a3: 1024);
  client_data[2].color_convert = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int, unsigned __int8 **, int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  v3 = 0;
  v7 = 5990656;
  v8 = -14831872;
  v4 = -11728000;
  v5 = 2919680;
  do
  {
    *(_DWORD *)((char *)client_data[1].start_pass + v3) = v4 >> 16;
    v6 = v8;
    v8 += 116130;
    *(_DWORD *)((char *)client_data[1].color_convert + v3) = v6 >> 16;
    *(_DWORD *)((char *)client_data[2].start_pass + v3) = v7;
    *(_DWORD *)((char *)client_data[2].color_convert + v3) = v5;
    v5 -= 22554;
    v4 += 91881;
    v3 += 4;
    v7 -= 46802;
  }
  while ( v5 >= -2831590 );
}

//------------------------------------------------------------------------------
// Address: 0x102797C0
// Name: ycc_rgb_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl ycc_rgb_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  jpeg_color_deconverter *cconvert; // eax
  unsigned __int8 *sample_range_limit; // edx
  unsigned int output_width; // ebx
  unsigned __int8 ***v9; // esi
  unsigned int v10; // ecx
  unsigned __int8 *v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // esi
  unsigned __int8 *v14; // ecx
  _BYTE *v15; // eax
  unsigned __int8 *v16; // edi
  int v17; // edi
  int v18; // esi
  unsigned int v19; // [esp+4h] [ebp-2Ch]
  unsigned int num_cols; // [esp+8h] [ebp-28h]
  int *Cbbtab; // [esp+Ch] [ebp-24h]
  unsigned __int8 *range_limit; // [esp+10h] [ebp-20h]
  int *Crrtab; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v25; // [esp+20h] [ebp-10h]
  unsigned __int8 *inptr1; // [esp+24h] [ebp-Ch]
  unsigned __int8 *inptr2; // [esp+28h] [ebp-8h]
  unsigned __int8 *inptr0; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *inptr0a; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *outptr; // [esp+38h] [ebp+8h]
  int num_rowsa; // [esp+48h] [ebp+18h]
  jpeg_color_deconverter Crgtab; // 0:^1C.8

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  cconvert = cinfo->cconvert;
  sample_range_limit = cinfo->sample_range_limit;
  output_width = cinfo->output_width;
  Crrtab = (int *)cconvert[1].start_pass;
  Cbbtab = (int *)cconvert[1].color_convert;
  num_cols = output_width;
  range_limit = sample_range_limit;
  Crgtab = cconvert[2];
  if ( !v5 )
  {
    v9 = input_buf;
    v10 = 4 * input_row;
    do
    {
      inptr0 = *(unsigned __int8 **)((char *)*v9 + v10);
      v11 = *(unsigned __int8 **)((char *)v9[1] + v10);
      inptr2 = *(unsigned __int8 **)((char *)v9[2] + v10);
      v12 = (int)*output_buf++;
      v10 += 4;
      v19 = v10;
      if ( output_width != 0 )
      {
        v13 = (unsigned __int8 *)(inptr0 - v11);
        v14 = v11;
        v15 = (_BYTE *)(v12 + 2);
        v16 = (unsigned __int8 *)(inptr2 - v11);
        v25 = v13;
        inptr1 = v16;
        inptr0a = (unsigned __int8 *)output_width;
        while ( 1 )
        {
          v17 = v14[(_DWORD)v16];
          v18 = v14[(_DWORD)v13];
          outptr = (unsigned __int8 *)*v14;
          *(v15 - 2) = sample_range_limit[v18 + Crrtab[v17]];
          sample_range_limit = range_limit;
          *(v15 - 1) = range_limit[v18
                                 + ((*((_DWORD *)Crgtab.start_pass + v17)
                                   + *((_DWORD *)Crgtab.color_convert + (_DWORD)outptr)) >> 16)];
          *v15 = range_limit[v18 + Cbbtab[(_DWORD)outptr]];
          v15 += 3;
          ++v14;
          if ( --inptr0a == nullptr )
            break;
          v13 = v25;
          v16 = inptr1;
        }
        output_width = num_cols;
        v9 = input_buf;
        v10 = v19;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102798E0
// Name: null_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl null_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  unsigned int output_width; // edx
  int v7; // ebx
  int i; // esi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned int j; // edi
  int num_components; // [esp+4h] [ebp-4h]
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int num_rowsa; // [esp+20h] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  output_width = cinfo->output_width;
  v7 = cinfo->num_components;
  num_components = v7;
  if ( !v5 )
  {
    cinfoa = (jpeg_decompress_struct *)(4 * input_row);
    do
    {
      for ( i = 0; i < v7; ++i )
      {
        v9 = *(unsigned __int8 **)((char *)input_buf[i] + (_DWORD)cinfoa);
        v10 = &(*output_buf)[i];
        for ( j = output_width; j != 0; --j )
        {
          *v10 = *v9;
          v7 = num_components;
          ++v9;
          v10 += num_components;
        }
      }
      cinfoa = (jpeg_decompress_struct *)((char *)cinfoa + 4);
      ++output_buf;
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279960
// Name: grayscale_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl grayscale_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jcopy_sample_rows(
    input_array: *input_buf,
    source_row: input_row,
    output_array: output_buf,
    dest_row: 0,
    num_rows,
    num_cols: cinfo->output_width);
}

//------------------------------------------------------------------------------
// Address: 0x10279990
// Name: gray_rgb_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl gray_rgb_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  unsigned int output_width; // edi
  unsigned int v8; // ecx
  int v9; // esi
  int v10; // eax
  unsigned int v11; // edx
  _BYTE *v12; // eax
  char v13; // cl
  jpeg_decompress_struct *cinfoa; // [esp+Ch] [ebp+8h]
  int num_rowsa; // [esp+1Ch] [ebp+18h]

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  output_width = cinfo->output_width;
  if ( !v5 )
  {
    v8 = 4 * input_row;
    do
    {
      v9 = *(int *)((char *)*input_buf + v8);
      v10 = (int)*output_buf;
      v8 += 4;
      ++output_buf;
      v11 = 0;
      cinfoa = (jpeg_decompress_struct *)v8;
      if ( output_width != 0 )
      {
        v12 = (_BYTE *)(v10 + 1);
        do
        {
          v13 = *(_BYTE *)(v11 + v9);
          v12[1] = v13;
          *v12 = v13;
          *(v12 - 1) = v13;
          ++v11;
          v12 += 3;
        }
        while ( v11 < output_width );
        v8 = (unsigned int)cinfoa;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102799F0
// Name: ycck_cmyk_convert
// Source: json
//------------------------------------------------------------------------------
void __cdecl ycck_cmyk_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  bool v5; // sf
  jpeg_color_deconverter *cconvert; // eax
  unsigned __int8 *sample_range_limit; // ecx
  unsigned __int8 ***v8; // esi
  unsigned int v9; // edx
  int v10; // edi
  unsigned __int8 *v11; // ecx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // ebx
  unsigned int v20; // [esp+0h] [ebp-2Ch]
  int v21; // [esp+4h] [ebp-28h]
  int *Cbbtab; // [esp+8h] [ebp-24h]
  int *Crrtab; // [esp+14h] [ebp-18h]
  int v25; // [esp+18h] [ebp-14h]
  int v26; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *outptr; // [esp+20h] [ebp-Ch]
  unsigned __int8 *inptr3; // [esp+24h] [ebp-8h]
  unsigned __int8 *range_limit; // [esp+28h] [ebp-4h]
  unsigned int num_cols; // [esp+34h] [ebp+8h]
  int num_rowsa; // [esp+44h] [ebp+18h]
  jpeg_color_deconverter Crgtab; // 0:^18.8

  v5 = num_rows - 1 < 0;
  num_rowsa = num_rows - 1;
  cconvert = cinfo->cconvert;
  sample_range_limit = cinfo->sample_range_limit;
  num_cols = cinfo->output_width;
  range_limit = sample_range_limit;
  Crrtab = (int *)cconvert[1].start_pass;
  Cbbtab = (int *)cconvert[1].color_convert;
  Crgtab = cconvert[2];
  if ( !v5 )
  {
    v8 = input_buf;
    v9 = 4 * input_row;
    do
    {
      v10 = *(int *)((char *)*v8 + v9);
      v11 = *(unsigned __int8 **)((char *)v8[1] + v9);
      v12 = *(int *)((char *)v8[2] + v9);
      inptr3 = *(unsigned __int8 **)((char *)v8[3] + v9);
      v13 = (int)*output_buf++;
      v9 += 4;
      v20 = v9;
      if ( num_cols != 0 )
      {
        v14 = v10 - (_DWORD)v11;
        v15 = v12 - (_DWORD)v11;
        v16 = v13 + 2;
        v21 = inptr3 - v11;
        v26 = v14;
        v25 = v12 - (_DWORD)v11;
        outptr = (unsigned __int8 *)num_cols;
        while ( 1 )
        {
          v17 = v11[v14];
          v18 = v11[v15];
          v19 = *v11;
          *(_BYTE *)(v16 - 2) = range_limit[-Crrtab[v18] - v17 + 255];
          *(_BYTE *)(v16 - 1) = range_limit[-((*((_DWORD *)Crgtab.start_pass + v18)
                                             + *((_DWORD *)Crgtab.color_convert + v19)) >> 16)
                                          - v17
                                          + 255];
          v16 += 4;
          *(_BYTE *)(v16 - 4) = range_limit[-Cbbtab[v19] - v17 + 255];
          *(_BYTE *)(v16 - 3) = (v11++)[v21];
          if ( --outptr == nullptr )
            break;
          v14 = v26;
          v15 = v25;
        }
        v8 = input_buf;
        v9 = v20;
      }
      --num_rowsa;
    }
    while ( num_rowsa >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279B30
// Name: _jinit_color_deconverter
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_color_deconverter(jpeg_common_struct *cinfo)
{
  jpeg_color_deconverter *v1; // edi
  J_COLOR_SPACE v2; // eax
  J_COLOR_SPACE v3; // eax
  J_COLOR_SPACE v4; // eax
  int v5; // eax
  int v6; // ecx

  v1 = (jpeg_color_deconverter *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 24);
  cinfo[17].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_decompress_struct *))C_BaseAnimating::ShutdownBoneSetupThreadPool;
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
        cinfo->err->msg_code = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      break;
  }
  if ( cinfo[1].global_state != 1 )
  {
    if ( cinfo[1].global_state == 2 )
    {
      v3 = *(_DWORD *)&cinfo[1].is_decompressor;
      cinfo[4].mem = (jpeg_memory_mgr *)3;
      switch ( v3 )
      {
        case JCS_YCbCr:
          v1->color_convert = ycc_rgb_convert;
          build_ycc_rgb_table(cinfo);
          goto LABEL_31;
        case JCS_GRAYSCALE:
          v1->color_convert = gray_rgb_convert;
          goto LABEL_31;
        case JCS_RGB:
          v1->color_convert = null_convert;
          goto LABEL_31;
        default:
          break;
      }
    }
    else if ( cinfo[1].global_state == 4 )
    {
      v2 = *(_DWORD *)&cinfo[1].is_decompressor;
      cinfo[4].mem = (jpeg_memory_mgr *)4;
      if ( v2 == JCS_YCCK )
      {
        v1->color_convert = ycck_cmyk_convert;
        build_ycc_rgb_table(cinfo);
        goto LABEL_31;
      }
      if ( v2 == JCS_CMYK )
      {
        v1->color_convert = null_convert;
        goto LABEL_31;
      }
    }
    else if ( cinfo[1].global_state == *(_DWORD *)&cinfo[1].is_decompressor )
    {
      cinfo[4].mem = (jpeg_memory_mgr *)cinfo[1].client_data;
      v1->color_convert = null_convert;
      goto LABEL_31;
    }
    goto LABEL_27;
  }
  v4 = *(_DWORD *)&cinfo[1].is_decompressor;
  cinfo[4].mem = (jpeg_memory_mgr *)1;
  if ( v4 != JCS_GRAYSCALE && v4 != JCS_YCbCr )
  {
LABEL_27:
    cinfo->err->msg_code = 27;
    cinfo->err->error_exit(a1: cinfo);
    goto LABEL_31;
  }
  v1->color_convert = grayscale_convert;
  v5 = 1;
  if ( (int)cinfo[1].client_data > 1 )
  {
    v6 = 84;
    do
    {
      *((_BYTE *)&cinfo[8].mem->max_alloc_chunk + v6) = 0;
      ++v5;
      v6 += 84;
    }
    while ( v5 < (int)cinfo[1].client_data );
  }
LABEL_31:
  if ( BYTE2(cinfo[3].err) != 0 )
    cinfo[4].progress = (jpeg_progress_mgr *)1;
  else
    cinfo[4].progress = (jpeg_progress_mgr *)cinfo[4].mem;
}

//------------------------------------------------------------------------------
// Address: 0x10279CC0
// Name: build_ycc_rgb_table_0
// Source: json
//------------------------------------------------------------------------------
void __usercall build_ycc_rgb_table_0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_upsampler *progress; // esi
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  progress = (jpeg_upsampler *)cinfo[17].progress;
  progress[1].upsample = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  *(_DWORD *)&progress[1].need_context_rows = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  progress[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                         a1: cinfo,
                                                                         a2: 1,
                                                                         a3: 1024);
  progress[2].upsample = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  v3 = 0;
  v7 = 5990656;
  v8 = -14831872;
  v4 = -11728000;
  v5 = 2919680;
  do
  {
    *(_DWORD *)((char *)progress[1].upsample + v3) = v4 >> 16;
    v6 = v8;
    v8 += 116130;
    *(_DWORD *)(v3 + *(_DWORD *)&progress[1].need_context_rows) = v6 >> 16;
    *(_DWORD *)((char *)progress[2].start_pass + v3) = v7;
    *(_DWORD *)((char *)progress[2].upsample + v3) = v5;
    v5 -= 22554;
    v4 += 91881;
    v3 += 4;
    v7 -= 46802;
  }
  while ( v5 >= -2831590 );
}

} // namespace client
