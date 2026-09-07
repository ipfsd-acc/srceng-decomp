// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jquant1.c
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100129C0
// Name: select_ncolors
// Source: json
//------------------------------------------------------------------------------
int __cdecl select_ncolors(jpeg_common_struct *cinfo, int *Ncolors)
{
  signed int mem; // esi
  int v3; // ebx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  signed int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // esi
  int max_colors; // [esp+Ch] [ebp-10h]
  int nc; // [esp+10h] [ebp-Ch]
  int total_colors; // [esp+14h] [ebp-8h]
  unsigned __int8 changed; // [esp+1Bh] [ebp-1h]

  mem = (signed int)cinfo[4].mem;
  nc = mem;
  max_colors = (int)cinfo[3].client_data;
  v3 = 1;
  do
  {
    v4 = ++v3;
    if ( mem > 1 )
    {
      v5 = mem - 1;
      do
      {
        v4 *= v3;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  while ( v4 <= (int)cinfo[3].client_data );
  v6 = v3 - 1;
  if ( v6 < 2 )
  {
    cinfo->err->msg_code = 56;
    cinfo->err->msg_parm.i[0] = v4;
    cinfo->err->error_exit(a1: cinfo);
  }
  total_colors = 1;
  if ( mem > 0 )
  {
    v7 = mem;
    memset32(Ncolors, v6, mem);
    do
    {
      --v7;
      total_colors *= v6;
    }
    while ( v7 != 0 );
  }
  while ( 2 )
  {
    v8 = 0;
    changed = 0;
    if ( mem > 0 )
    {
      while ( 1 )
      {
        v9 = cinfo[1].global_state == 2 ? RGB_order[v8] : v8;
        v10 = Ncolors[v9];
        if ( (v10 + 1) * (total_colors / v10) > max_colors )
          break;
        ++v8;
        Ncolors[v9] = v10 + 1;
        total_colors = (v10 + 1) * (total_colors / v10);
        changed = 1;
        if ( v8 >= nc )
          goto LABEL_12;
      }
      if ( changed != 0 )
      {
LABEL_12:
        mem = nc;
        continue;
      }
    }
    return total_colors;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012AA0
// Name: create_colormap
// Source: json
//------------------------------------------------------------------------------
void __cdecl create_colormap(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // ebx
  unsigned int v2; // edi
  jpeg_error_mgr *err; // eax
  unsigned __int8 **v4; // ecx
  signed int v5; // eax
  unsigned __int8 **v6; // edi
  int v7; // ecx
  int v8; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int j; // edx
  int k; // ecx
  unsigned __int8 *v14; // ebx
  my_cquantizer *cquantize; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 **colormap; // [esp+10h] [ebp-28h]
  int v17; // [esp+14h] [ebp-24h]
  int v18; // [esp+18h] [ebp-20h]
  int i; // [esp+1Ch] [ebp-1Ch]
  int blkdist; // [esp+20h] [ebp-18h]
  int v21; // [esp+24h] [ebp-14h]
  int total_colors; // [esp+28h] [ebp-10h]
  int *Ncolors; // [esp+2Ch] [ebp-Ch]
  int v24; // [esp+30h] [ebp-8h]
  int v25; // [esp+34h] [ebp-4h]

  v1 = cinfo;
  cquantize = *(my_cquantizer **)&cinfo[17].is_decompressor;
  Ncolors = cquantize->Ncolors;
  v2 = select_ncolors(cinfo, Ncolors: cquantize->Ncolors);
  err = cinfo->err;
  total_colors = v2;
  if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
  {
    err->msg_parm.i[0] = v2;
    err->msg_parm.i[1] = *Ncolors;
    err->msg_parm.i[2] = cquantize->Ncolors[1];
    err->msg_parm.i[3] = cquantize->Ncolors[2];
    cinfo->err->msg_code = 94;
  }
  else
  {
    err->msg_code = 95;
    cinfo->err->msg_parm.i[0] = v2;
  }
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  v4 = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: v2, a4: cinfo[4].mem);
  v5 = v2;
  colormap = v4;
  blkdist = v2;
  i = 0;
  if ( (int)cinfo[4].mem <= 0 )
  {
    cquantize->sv_actual = v2;
    cquantize->sv_colormap = v4;
  }
  else
  {
    v6 = v4;
    do
    {
      v7 = *Ncolors;
      v8 = v5 / *Ncolors;
      if ( *Ncolors > 0 )
      {
        v9 = v7 - 1;
        v10 = (v7 - 1) / 2;
        v18 = v7 - 1;
        v17 = v10;
        v24 = 0;
        v25 = 0;
        v21 = *Ncolors;
        while ( 1 )
        {
          v11 = (v25 + v10) / v9;
          for ( j = v24; j < total_colors; j += blkdist )
          {
            for ( k = 0; k < v8; v14[j] = v11 )
              v14 = &(*v6)[k++];
          }
          v25 += 255;
          v24 += v8;
          if ( --v21 == 0 )
            break;
          v9 = v18;
          v10 = v17;
        }
        v1 = cinfo;
      }
      ++Ncolors;
      ++v6;
      v5 = v8;
      blkdist = v8;
      ++i;
    }
    while ( i < (int)v1[4].mem );
    cquantize->sv_colormap = colormap;
    cquantize->sv_actual = total_colors;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012C10
// Name: create_colorindex
// Source: json
//------------------------------------------------------------------------------
void __cdecl create_colorindex(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *p_pub; // esi
  int v2; // edi
  void (__cdecl *color_quantize)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // eax
  int v4; // ecx
  unsigned __int8 *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  int v11; // eax
  unsigned __int8 *v12; // ecx
  unsigned __int8 *indexptr; // [esp+Ch] [ebp-18h]
  my_cquantizer *cquantize; // [esp+10h] [ebp-14h]
  int blksize; // [esp+14h] [ebp-10h]
  int nci; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int pad; // [esp+20h] [ebp-4h]

  p_pub = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  cquantize = (my_cquantizer *)p_pub;
  if ( cinfo[3].mem == (jpeg_memory_mgr *)1 )
  {
    pad = 510;
    LOBYTE(p_pub[1].new_color_map) = 1;
  }
  else
  {
    pad = 0;
    LOBYTE(p_pub[1].new_color_map) = 0;
  }
  v2 = 0;
  p_pub[1].finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_sarray(
                                                                       a1: cinfo,
                                                                       a2: 1,
                                                                       a3: pad + 256,
                                                                       a4: cinfo[4].mem);
  color_quantize = p_pub[1].color_quantize;
  i = 0;
  if ( (int)cinfo[4].mem > 0 )
  {
    while ( 1 )
    {
      v4 = *((_DWORD *)&p_pub[2].start_pass + v2);
      nci = v4;
      blksize = (int)color_quantize / v4;
      if ( pad != 0 )
        *((_DWORD *)p_pub[1].finish_pass + v2) += 255;
      v5 = *((unsigned __int8 **)p_pub[1].finish_pass + v2);
      v6 = (v4 + 254) / (2 * v4 - 2);
      v7 = 0;
      indexptr = v5;
      v8 = 0;
      v9 = v6;
      do
      {
        if ( v8 > v9 )
        {
          v10 = 510 * v7 + nci + 254;
          do
          {
            v10 += 510;
            ++v7;
            v9 = v10 / (2 * nci - 2);
          }
          while ( v8 > v9 );
          v5 = indexptr;
        }
        v5[v8++] = v7 * blksize;
      }
      while ( v8 <= 255 );
      if ( pad != 0 )
      {
        v11 = 1;
        v12 = v5 - 1;
        do
        {
          *v12 = *v5;
          v5[v11++ + 255] = v5[255];
          --v12;
        }
        while ( v11 <= 255 );
      }
      if ( ++i >= (int)cinfo[4].mem )
        break;
      color_quantize = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))blksize;
      v2 = i;
      p_pub = &cquantize->pub;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012D60
// Name: create_odither_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl create_odither_tables(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // edi
  jpeg_color_quantizer *p_pub; // edx
  int v3; // ecx
  void (__cdecl **p_color_quantize)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // ebx
  void (__cdecl *v5)(jpeg_decompress_struct *, unsigned __int8); // esi
  int v6; // eax
  jpeg_color_quantizer *v7; // edx
  int *v8; // eax
  int v9; // ebx
  const unsigned __int8 *v10; // edi
  int v11; // esi
  int j; // ecx
  int v13; // eax
  int v14; // [esp+4h] [ebp-10h]
  void (__cdecl **v15)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  my_cquantizer *cquantize; // [esp+10h] [ebp-4h]

  v1 = cinfo;
  p_pub = cinfo->cquantize;
  v3 = 0;
  cquantize = (my_cquantizer *)p_pub;
  i = 0;
  if ( cinfo->out_color_components > 0 )
  {
    p_color_quantize = &p_pub[3].color_quantize;
    v15 = &p_pub[3].color_quantize;
    while ( 1 )
    {
      v5 = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))*(p_color_quantize - 5);
      v6 = 0;
      if ( v3 <= 0 )
        goto LABEL_10;
      v7 = p_pub + 2;
      while ( v5 != v7->start_pass )
      {
        ++v6;
        v7 = (jpeg_color_quantizer *)((char *)v7 + 4);
        if ( v6 >= v3 )
          goto LABEL_10;
      }
      v8 = (int *)cquantize->odither[v6];
      if ( v8 == nullptr )
      {
LABEL_10:
        v9 = ((_DWORD)v5 << 9) - 512;
        v14 = v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 1024u);
        v10 = base_dither_matrix[0];
        v11 = v14;
        do
        {
          for ( j = 0; j < 16; ++j )
          {
            v13 = (65025 - 510 * v10[j]) / v9;
            v11 += 4;
            *(_DWORD *)(v11 - 4) = v13;
          }
          v10 += 16;
        }
        while ( (int)v10 < (int)RGB_order );
        v8 = (int *)v14;
        v1 = cinfo;
        v3 = i;
        p_color_quantize = v15;
      }
      *p_color_quantize = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))v8;
      ++v3;
      ++p_color_quantize;
      i = v3;
      v15 = p_color_quantize;
      if ( v3 >= v1->out_color_components )
        break;
      p_pub = &cquantize->pub;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012E50
// Name: color_quantize
// Source: json
//------------------------------------------------------------------------------
void __cdecl color_quantize(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  int out_color_components; // esi
  unsigned int output_width; // edi
  unsigned __int8 **v6; // edx
  int v7; // ebx
  unsigned __int8 *v8; // ecx
  unsigned __int8 v9; // dl
  int i; // eax
  unsigned __int8 v11; // di
  bool v12; // zf
  unsigned int width; // [esp+8h] [ebp-14h]
  unsigned __int8 **colorindex; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  unsigned __int8 **v16; // [esp+18h] [ebp-4h]
  unsigned __int8 *ptrout; // [esp+24h] [ebp+8h]
  unsigned int col; // [esp+30h] [ebp+14h]

  out_color_components = cinfo->out_color_components;
  output_width = cinfo->output_width;
  colorindex = (unsigned __int8 **)cinfo->cquantize[1].finish_pass;
  width = output_width;
  if ( num_rows > 0 )
  {
    v6 = output_buf;
    v7 = (char *)input_buf - (char *)output_buf;
    v16 = output_buf;
    v15 = num_rows;
    do
    {
      v8 = *(unsigned __int8 **)((char *)v6 + v7);
      ptrout = *v6;
      col = output_width;
      if ( output_width != 0 )
      {
        do
        {
          v9 = 0;
          for ( i = 0; i < out_color_components; ++v8 )
          {
            v11 = colorindex[i++][*v8];
            v9 += v11;
          }
          *ptrout = v9;
          v12 = col-- == 1;
          ++ptrout;
        }
        while ( !v12 );
        v7 = (char *)input_buf - (char *)output_buf;
        v6 = v16;
        output_width = width;
      }
      ++v6;
      v12 = v15-- == 1;
      v16 = v6;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012EF0
// Name: color_quantize3
// Source: json
//------------------------------------------------------------------------------
void __cdecl color_quantize3(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  void (__cdecl *finish_pass)(jpeg_decompress_struct *); // eax
  unsigned int output_width; // esi
  unsigned __int8 **v6; // ecx
  int v7; // edi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edx
  bool v10; // zf
  unsigned int width; // [esp+8h] [ebp-10h]
  unsigned __int8 *colorindex2; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *colorindex1; // [esp+10h] [ebp-8h]
  unsigned __int8 *colorindex0; // [esp+14h] [ebp-4h]
  jpeg_decompress_struct *cinfoa; // [esp+20h] [ebp+8h]

  finish_pass = cinfo->cquantize[1].finish_pass;
  colorindex0 = *(unsigned __int8 **)finish_pass;
  colorindex2 = *((unsigned __int8 **)finish_pass + 2);
  output_width = cinfo->output_width;
  colorindex1 = *((unsigned __int8 **)finish_pass + 1);
  width = output_width;
  if ( num_rows > 0 )
  {
    v6 = output_buf;
    v7 = (char *)input_buf - (char *)output_buf;
    cinfoa = (jpeg_decompress_struct *)output_buf;
    do
    {
      v8 = *(unsigned __int8 **)((char *)v6 + v7);
      v9 = *v6;
      if ( output_width != 0 )
      {
        do
        {
          *v9 = colorindex2[v8[2]] + colorindex1[v8[1]] + colorindex0[*v8];
          v8 += 3;
          ++v9;
          --output_width;
        }
        while ( output_width != 0 );
        output_width = width;
        v6 = (unsigned __int8 **)cinfoa;
        v7 = (char *)input_buf - (char *)output_buf;
      }
      ++v6;
      v10 = num_rows-- == 1;
      cinfoa = (jpeg_decompress_struct *)v6;
    }
    while ( !v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012F90
// Name: quantize_ord_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl quantize_ord_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  unsigned int output_width; // ebx
  jpeg_color_quantizer *p_pub; // edi
  void **v7; // esi
  void (__cdecl *start_pass)(jpeg_decompress_struct *, unsigned __int8); // eax
  int v9; // edx
  int v10; // eax
  _BYTE *v11; // ecx
  unsigned __int8 *v12; // esi
  int v13; // edi
  unsigned __int8 *v14; // eax
  int v15; // esi
  int v16; // edx
  bool v17; // zf
  char row_index; // [esp+8h] [ebp-24h]
  unsigned int width; // [esp+Ch] [ebp-20h]
  unsigned __int8 *colorindex_ci; // [esp+10h] [ebp-1Ch]
  int v21; // [esp+14h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-10h]
  int ci; // [esp+20h] [ebp-Ch]
  my_cquantizer *cquantize; // [esp+24h] [ebp-8h]
  unsigned int col; // [esp+28h] [ebp-4h]
  int nc; // [esp+34h] [ebp+8h]
  unsigned __int8 **num_rowsa; // [esp+40h] [ebp+14h]

  output_width = cinfo->output_width;
  p_pub = cinfo->cquantize;
  cquantize = (my_cquantizer *)p_pub;
  nc = cinfo->out_color_components;
  width = output_width;
  if ( num_rows > 0 )
  {
    v7 = (void **)output_buf;
    num_rowsa = output_buf;
    v22 = num_rows;
    do
    {
      jzero_far(target: *v7, bytestozero: output_width);
      start_pass = p_pub[3].start_pass;
      v9 = 0;
      row_index = (char)start_pass;
      ci = 0;
      if ( nc > 0 )
      {
        v21 = (_DWORD)start_pass << 6;
        do
        {
          v10 = *(int *)((char *)v7 + (char *)input_buf - (char *)output_buf);
          v11 = *v7;
          v12 = *((unsigned __int8 **)p_pub[1].finish_pass + v9);
          v13 = v21 + *((_DWORD *)&p_pub[3].color_quantize + v9);
          colorindex_ci = v12;
          v14 = (unsigned __int8 *)(v9 + v10);
          v15 = 0;
          col = output_width;
          if ( output_width != 0 )
          {
            do
            {
              v16 = *v14;
              v14 += nc;
              *v11++ += colorindex_ci[v16 + *(_DWORD *)(v13 + 4 * v15)];
              v15 = ((_BYTE)v15 + 1) & 0xF;
              --col;
            }
            while ( col != 0 );
            output_width = width;
            v9 = ci;
          }
          p_pub = &cquantize->pub;
          v7 = (void **)num_rowsa;
          ci = ++v9;
        }
        while ( v9 < nc );
        LOBYTE(start_pass) = row_index;
      }
      ++v7;
      v17 = v22-- == 1;
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))(((_BYTE)start_pass + 1) & 0xF);
      num_rowsa = (unsigned __int8 **)v7;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013070
// Name: quantize3_ord_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl quantize3_ord_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_color_quantizer *p_pub; // edx
  unsigned __int8 **finish_pass; // eax
  unsigned __int8 **v6; // esi
  int v7; // edi
  unsigned __int8 *v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ecx
  bool v12; // zf
  int row_index; // [esp+4h] [ebp-2Ch]
  my_cquantizer *cquantize; // [esp+8h] [ebp-28h]
  unsigned __int8 *colorindex2; // [esp+Ch] [ebp-24h]
  int *dither2; // [esp+10h] [ebp-20h]
  unsigned __int8 *colorindex1; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *colorindex0; // [esp+18h] [ebp-18h]
  int *dither1; // [esp+1Ch] [ebp-14h]
  unsigned int width; // [esp+20h] [ebp-10h]
  int v21; // [esp+28h] [ebp-8h]
  unsigned __int8 **v22; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *output_ptr; // [esp+38h] [ebp+8h]
  unsigned int col; // [esp+44h] [ebp+14h]

  p_pub = cinfo->cquantize;
  finish_pass = (unsigned __int8 **)p_pub[1].finish_pass;
  colorindex0 = *finish_pass;
  colorindex2 = finish_pass[2];
  cquantize = (my_cquantizer *)p_pub;
  colorindex1 = finish_pass[1];
  width = cinfo->output_width;
  if ( num_rows > 0 )
  {
    v6 = output_buf;
    v7 = (char *)input_buf - (char *)output_buf;
    v22 = output_buf;
    v21 = num_rows;
    while ( 1 )
    {
      v8 = *(unsigned __int8 **)((char *)v6 + v7);
      row_index = (int)p_pub[3].start_pass;
      output_ptr = *v6;
      v9 = (int)p_pub[3].finish_pass + 64 * row_index;
      v10 = (int)p_pub[3].color_quantize + 64 * row_index;
      dither2 = (int *)((char *)p_pub[3].new_color_map + 64 * row_index);
      v11 = 0;
      dither1 = (int *)v9;
      col = width;
      if ( width != 0 )
      {
        while ( 1 )
        {
          *output_ptr = colorindex2[v8[2] + dither2[v11]]
                      + colorindex1[v8[1] + *(_DWORD *)(v9 + 4 * v11)]
                      + colorindex0[*v8 + *(_DWORD *)(v10 + 4 * v11)];
          v8 += 3;
          v11 = ((_BYTE)v11 + 1) & 0xF;
          v12 = col-- == 1;
          ++output_ptr;
          if ( v12 )
            break;
          v9 = (int)dither1;
        }
        p_pub = &cquantize->pub;
      }
      v6 = v22 + 1;
      v12 = v21-- == 1;
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))(((_BYTE)row_index + 1) & 0xF);
      ++v22;
      if ( v12 )
        break;
      v7 = (char *)input_buf - (char *)output_buf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013170
// Name: quantize_fs_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl quantize_fs_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        unsigned __int8 *num_rows)
{
  unsigned int output_width; // edx
  jpeg_color_quantizer *p_pub; // ebx
  void **v6; // esi
  int v7; // eax
  _BYTE *v8; // edi
  unsigned __int8 *v9; // edx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  _WORD *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // edx
  bool v17; // zf
  int bnexterr; // [esp+4h] [ebp-38h]
  unsigned __int8 *colormap_ci; // [esp+8h] [ebp-34h]
  unsigned __int8 *colorindex_ci; // [esp+Ch] [ebp-30h]
  unsigned __int8 *range_limit; // [esp+10h] [ebp-2Ch]
  unsigned __int8 *v22; // [esp+18h] [ebp-24h]
  unsigned int col; // [esp+1Ch] [ebp-20h]
  int dirnc; // [esp+20h] [ebp-1Ch]
  __int16 belowerr; // [esp+24h] [ebp-18h]
  unsigned __int8 **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 bpreverr; // [esp+30h] [ebp-Ch]
  my_cquantizer *cquantize; // [esp+34h] [ebp-8h]
  unsigned int width; // [esp+38h] [ebp-4h]
  int nc; // [esp+44h] [ebp+8h]
  unsigned __int8 *input_ptr; // [esp+50h] [ebp+14h]

  output_width = cinfo->output_width;
  p_pub = cinfo->cquantize;
  range_limit = cinfo->sample_range_limit;
  cquantize = (my_cquantizer *)p_pub;
  nc = cinfo->out_color_components;
  width = output_width;
  if ( (int)num_rows > 0 )
  {
    v6 = (void **)output_buf;
    v26 = output_buf;
    v22 = num_rows;
    do
    {
      jzero_far(target: *v6, bytestozero: width);
      v7 = 0;
      for ( ci = 0; v7 < nc; ci = v7 )
      {
        v8 = *v6;
        v9 = (unsigned __int8 *)(*(char **)((char *)v6 + (char *)input_buf - (char *)output_buf) + v7);
        v10 = 2 * v7;
        input_ptr = v9;
        if ( LOBYTE(p_pub[5].color_quantize) != 0 )
        {
          v8 += width - 1;
          v9 += nc * (width - 1);
          v11 = -1;
          dirnc = -nc;
          v12 = 2 * v10;
          v13 = (_WORD *)(*(char **)((char *)&p_pub[4].color_quantize + v12) + 2 * width + 2);
          p_pub = &cquantize->pub;
          input_ptr = v9;
        }
        else
        {
          v12 = 2 * v10;
          dirnc = nc;
          v13 = *(void (__cdecl **)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))((char *)&p_pub[4].color_quantize + v12);
          v11 = 1;
        }
        colorindex_ci = *(unsigned __int8 **)((char *)p_pub[1].finish_pass + v12);
        colormap_ci = *(unsigned __int8 **)((char *)cquantize->sv_colormap + v12);
        v14 = 0;
        bpreverr = 0;
        belowerr = 0;
        col = width;
        if ( width != 0 )
        {
          do
          {
            v15 = range_limit[(((__int16)v13[v11] + v14 + 8) >> 4) + *v9];
            v16 = colorindex_ci[v15];
            *v8 += v16;
            bnexterr = v15 - colormap_ci[v16];
            *v13 = 3 * bnexterr + bpreverr;
            v14 = 15 * bnexterr;
            v9 = &input_ptr[dirnc];
            bpreverr = 9 * bnexterr + belowerr;
            v8 += v11;
            v17 = col-- == 1;
            belowerr = bnexterr;
            input_ptr += dirnc;
            v13 += v11;
          }
          while ( !v17 );
        }
        p_pub = &cquantize->pub;
        v6 = (void **)v26;
        v7 = ci + 1;
        *v13 = bpreverr;
      }
      ++v6;
      v17 = v22-- == (unsigned __int8 *)1;
      LOBYTE(p_pub[5].color_quantize) = LOBYTE(p_pub[5].color_quantize) == 0;
      v26 = (unsigned __int8 **)v6;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100132F0
// Name: alloc_fs_workspace
// Source: json
//------------------------------------------------------------------------------
void __usercall alloc_fs_workspace(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // edi
  _DWORD *v2; // ebx
  unsigned int arraysize; // [esp+8h] [ebp-4h]

  v1 = 0;
  arraysize = 2 * cinfo[3].global_state + 4;
  if ( (int)cinfo[4].mem > 0 )
  {
    v2 = (_DWORD *)(*(_DWORD *)&cinfo[17].is_decompressor + 68);
    do
    {
      *v2 = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: arraysize);
      ++v1;
      ++v2;
    }
    while ( v1 < (int)cinfo[4].mem );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013340
// Name: start_pass_1_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_1_quant(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *v2; // edi
  J_DITHER_MODE mem; // eax
  __int32 v4; // eax
  bool v5; // zf
  void **p_color_quantize; // ebx
  int v7; // edi
  unsigned int arraysize; // [esp+10h] [ebp+8h]

  v2 = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  cinfo[4].global_state = (int)v2[1].start_pass;
  mem = (J_DITHER_MODE)cinfo[3].mem;
  *(_DWORD *)&cinfo[4].is_decompressor = v2[1].color_quantize;
  if ( mem != JDITHER_NONE )
  {
    v4 = mem - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
      {
        v5 = v2[4].color_quantize == nullptr;
        p_color_quantize = (void **)&v2[4].color_quantize;
        v2->color_quantize = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))quantize_fs_dither;
        LOBYTE(v2[5].color_quantize) = 0;
        if ( v5 )
          alloc_fs_workspace(cinfo);
        v7 = 0;
        for ( arraysize = 2 * cinfo[3].global_state + 4; v7 < (int)cinfo[4].mem; ++p_color_quantize )
        {
          jzero_far(target: *p_color_quantize, bytestozero: arraysize);
          ++v7;
        }
      }
      else
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    else
    {
      if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
        v2->color_quantize = quantize3_ord_dither;
      else
        v2->color_quantize = quantize_ord_dither;
      v5 = LOBYTE(v2[1].new_color_map) == 0;
      v2[3].start_pass = nullptr;
      if ( v5 )
        create_colorindex(cinfo);
      if ( v2[3].color_quantize == nullptr )
        create_odither_tables((jpeg_decompress_struct *)cinfo);
    }
  }
  else if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
  {
    v2->color_quantize = color_quantize3;
  }
  else
  {
    v2->color_quantize = color_quantize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013430
// Name: new_color_map_1_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl new_color_map_1_quant(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 46;
  cinfo->err->error_exit(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10013450
// Name: _jinit_1pass_quantizer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_1pass_quantizer(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *v2; // eax
  int v3; // edi
  _DWORD *v4; // ebx
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]

  v2 = (jpeg_color_quantizer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 88);
  *(_DWORD *)&cinfo[17].is_decompressor = v2;
  v3 = 0;
  v2->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))start_pass_1_quant;
  v2->finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))jpeg_mem_term;
  v2->new_color_map = (void (__cdecl *)(jpeg_decompress_struct *))new_color_map_1_quant;
  v2[4].color_quantize = nullptr;
  v2[3].color_quantize = nullptr;
  if ( (int)cinfo[4].mem > 4 )
  {
    cinfo->err->msg_code = 55;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[3].client_data > 256 )
  {
    cinfo->err->msg_code = 57;
    cinfo->err->msg_parm.i[0] = 256;
    cinfo->err->error_exit(a1: cinfo);
  }
  create_colormap(cinfo);
  create_colorindex(cinfo);
  if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
  {
    cinfoa = (jpeg_decompress_struct *)(2 * cinfo[3].global_state + 4);
    if ( (int)cinfo[4].mem > 0 )
    {
      v4 = (_DWORD *)(*(_DWORD *)&cinfo[17].is_decompressor + 68);
      do
      {
        *v4 = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: cinfoa);
        ++v3;
        ++v4;
      }
      while ( v3 < (int)cinfo[4].mem );
    }
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027B720
// Name: select_ncolors
// Source: json
//------------------------------------------------------------------------------
int __cdecl select_ncolors(jpeg_common_struct *cinfo, int *Ncolors)
{
  signed int mem; // esi
  int v3; // ebx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  signed int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // esi
  int max_colors; // [esp+Ch] [ebp-10h]
  int nc; // [esp+10h] [ebp-Ch]
  int total_colors; // [esp+14h] [ebp-8h]
  unsigned __int8 changed; // [esp+1Bh] [ebp-1h]

  mem = (signed int)cinfo[4].mem;
  nc = mem;
  max_colors = (int)cinfo[3].client_data;
  v3 = 1;
  do
  {
    v4 = ++v3;
    if ( mem > 1 )
    {
      v5 = mem - 1;
      do
      {
        v4 *= v3;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  while ( v4 <= (int)cinfo[3].client_data );
  v6 = v3 - 1;
  if ( v6 < 2 )
  {
    cinfo->err->msg_code = 56;
    cinfo->err->msg_parm.i[0] = v4;
    cinfo->err->error_exit(a1: cinfo);
  }
  total_colors = 1;
  if ( mem > 0 )
  {
    v7 = mem;
    memset32(Ncolors, v6, mem);
    do
    {
      --v7;
      total_colors *= v6;
    }
    while ( v7 != 0 );
  }
  while ( 2 )
  {
    v8 = 0;
    changed = 0;
    if ( mem > 0 )
    {
      while ( 1 )
      {
        v9 = cinfo[1].global_state == 2 ? RGB_order[v8] : v8;
        v10 = Ncolors[v9];
        if ( (v10 + 1) * (total_colors / v10) > max_colors )
          break;
        ++v8;
        Ncolors[v9] = v10 + 1;
        total_colors = (v10 + 1) * (total_colors / v10);
        changed = 1;
        if ( v8 >= nc )
          goto LABEL_12;
      }
      if ( changed != 0 )
      {
LABEL_12:
        mem = nc;
        continue;
      }
    }
    return total_colors;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B800
// Name: create_colormap
// Source: json
//------------------------------------------------------------------------------
void __cdecl create_colormap(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // ebx
  unsigned int v2; // edi
  jpeg_error_mgr *err; // eax
  unsigned __int8 **v4; // ecx
  signed int v5; // eax
  unsigned __int8 **v6; // edi
  int v7; // ecx
  int v8; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int j; // edx
  int k; // ecx
  unsigned __int8 *v14; // ebx
  my_cquantizer *cquantize; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 **colormap; // [esp+10h] [ebp-28h]
  int v17; // [esp+14h] [ebp-24h]
  int v18; // [esp+18h] [ebp-20h]
  int i; // [esp+1Ch] [ebp-1Ch]
  int blkdist; // [esp+20h] [ebp-18h]
  int v21; // [esp+24h] [ebp-14h]
  int total_colors; // [esp+28h] [ebp-10h]
  int *Ncolors; // [esp+2Ch] [ebp-Ch]
  int v24; // [esp+30h] [ebp-8h]
  int v25; // [esp+34h] [ebp-4h]

  v1 = cinfo;
  cquantize = (my_cquantizer *)cinfo->cquantize;
  Ncolors = cquantize->Ncolors;
  v2 = select_ncolors(cinfo, Ncolors: cquantize->Ncolors);
  err = cinfo->err;
  total_colors = v2;
  if ( cinfo->out_color_components == 3 )
  {
    err->msg_parm.i[0] = v2;
    err->msg_parm.i[1] = *Ncolors;
    err->msg_parm.i[2] = cquantize->Ncolors[1];
    err->msg_parm.i[3] = cquantize->Ncolors[2];
    cinfo->err->msg_code = 94;
  }
  else
  {
    err->msg_code = 95;
    cinfo->err->msg_parm.i[0] = v2;
  }
  cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: 1);
  v4 = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: v2, a4: cinfo->out_color_components);
  v5 = v2;
  colormap = v4;
  blkdist = v2;
  i = 0;
  if ( cinfo->out_color_components <= 0 )
  {
    cquantize->sv_actual = v2;
    cquantize->sv_colormap = v4;
  }
  else
  {
    v6 = v4;
    do
    {
      v7 = *Ncolors;
      v8 = v5 / *Ncolors;
      if ( *Ncolors > 0 )
      {
        v9 = v7 - 1;
        v10 = (v7 - 1) / 2;
        v18 = v7 - 1;
        v17 = v10;
        v24 = 0;
        v25 = 0;
        v21 = *Ncolors;
        while ( 1 )
        {
          v11 = (v25 + v10) / v9;
          for ( j = v24; j < total_colors; j += blkdist )
          {
            for ( k = 0; k < v8; v14[j] = v11 )
              v14 = &(*v6)[k++];
          }
          v25 += 255;
          v24 += v8;
          if ( --v21 == 0 )
            break;
          v9 = v18;
          v10 = v17;
        }
        v1 = cinfo;
      }
      ++Ncolors;
      ++v6;
      v5 = v8;
      blkdist = v8;
      ++i;
    }
    while ( i < v1->out_color_components );
    cquantize->sv_colormap = colormap;
    cquantize->sv_actual = total_colors;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B970
// Name: create_colorindex
// Source: json
//------------------------------------------------------------------------------
void __cdecl create_colorindex(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *p_pub; // esi
  int v2; // edi
  void (__cdecl *color_quantize)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // eax
  int v4; // ecx
  unsigned __int8 *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  int v11; // eax
  unsigned __int8 *v12; // ecx
  unsigned __int8 *indexptr; // [esp+Ch] [ebp-18h]
  my_cquantizer *cquantize; // [esp+10h] [ebp-14h]
  int blksize; // [esp+14h] [ebp-10h]
  int nci; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int pad; // [esp+20h] [ebp-4h]

  p_pub = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  cquantize = (my_cquantizer *)p_pub;
  if ( cinfo[3].mem == (jpeg_memory_mgr *)1 )
  {
    pad = 510;
    LOBYTE(p_pub[1].new_color_map) = 1;
  }
  else
  {
    pad = 0;
    LOBYTE(p_pub[1].new_color_map) = 0;
  }
  v2 = 0;
  p_pub[1].finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->mem->alloc_sarray(
                                                                       a1: cinfo,
                                                                       a2: 1,
                                                                       a3: pad + 256,
                                                                       a4: cinfo[4].mem);
  color_quantize = p_pub[1].color_quantize;
  i = 0;
  if ( (int)cinfo[4].mem > 0 )
  {
    while ( 1 )
    {
      v4 = *((_DWORD *)&p_pub[2].start_pass + v2);
      nci = v4;
      blksize = (int)color_quantize / v4;
      if ( pad != 0 )
        *((_DWORD *)p_pub[1].finish_pass + v2) += 255;
      v5 = *((unsigned __int8 **)p_pub[1].finish_pass + v2);
      v6 = (v4 + 254) / (2 * v4 - 2);
      v7 = 0;
      indexptr = v5;
      v8 = 0;
      v9 = v6;
      do
      {
        if ( v8 > v9 )
        {
          v10 = 510 * v7 + nci + 254;
          do
          {
            v10 += 510;
            ++v7;
            v9 = v10 / (2 * nci - 2);
          }
          while ( v8 > v9 );
          v5 = indexptr;
        }
        v5[v8++] = v7 * blksize;
      }
      while ( v8 <= 255 );
      if ( pad != 0 )
      {
        v11 = 1;
        v12 = v5 - 1;
        do
        {
          *v12 = *v5;
          v5[v11++ + 255] = v5[255];
          --v12;
        }
        while ( v11 <= 255 );
      }
      if ( ++i >= (int)cinfo[4].mem )
        break;
      color_quantize = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))blksize;
      v2 = i;
      p_pub = &cquantize->pub;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BAC0
// Name: create_odither_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl create_odither_tables(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // edi
  jpeg_color_quantizer *p_pub; // edx
  int v3; // ecx
  void (__cdecl **p_color_quantize)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // ebx
  void (__cdecl *v5)(jpeg_decompress_struct *, unsigned __int8); // esi
  int v6; // eax
  jpeg_color_quantizer *v7; // edx
  int *v8; // eax
  int v9; // ebx
  const unsigned __int8 *v10; // edi
  int v11; // esi
  int j; // ecx
  int v13; // eax
  int v14; // [esp+4h] [ebp-10h]
  void (__cdecl **v15)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  my_cquantizer *cquantize; // [esp+10h] [ebp-4h]

  v1 = cinfo;
  p_pub = cinfo->cquantize;
  v3 = 0;
  cquantize = (my_cquantizer *)p_pub;
  i = 0;
  if ( cinfo->out_color_components > 0 )
  {
    p_color_quantize = &p_pub[3].color_quantize;
    v15 = &p_pub[3].color_quantize;
    while ( 1 )
    {
      v5 = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))*(p_color_quantize - 5);
      v6 = 0;
      if ( v3 <= 0 )
        goto LABEL_10;
      v7 = p_pub + 2;
      while ( v5 != v7->start_pass )
      {
        ++v6;
        v7 = (jpeg_color_quantizer *)((char *)v7 + 4);
        if ( v6 >= v3 )
          goto LABEL_10;
      }
      v8 = (int *)cquantize->odither[v6];
      if ( v8 == nullptr )
      {
LABEL_10:
        v9 = ((_DWORD)v5 << 9) - 512;
        v14 = v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 1024u);
        v10 = base_dither_matrix[0];
        v11 = v14;
        do
        {
          for ( j = 0; j < 16; ++j )
          {
            v13 = (65025 - 510 * v10[j]) / v9;
            v11 += 4;
            *(_DWORD *)(v11 - 4) = v13;
          }
          v10 += 16;
        }
        while ( (int)v10 < (int)RGB_order );
        v8 = (int *)v14;
        v1 = cinfo;
        v3 = i;
        p_color_quantize = v15;
      }
      *p_color_quantize = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))v8;
      ++v3;
      ++p_color_quantize;
      i = v3;
      v15 = p_color_quantize;
      if ( v3 >= v1->out_color_components )
        break;
      p_pub = &cquantize->pub;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BBB0
// Name: color_quantize
// Source: json
//------------------------------------------------------------------------------
void __cdecl color_quantize(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  int out_color_components; // esi
  unsigned int output_width; // edi
  unsigned __int8 **v6; // edx
  int v7; // ebx
  unsigned __int8 *v8; // ecx
  unsigned __int8 v9; // dl
  int i; // eax
  unsigned __int8 v11; // di
  bool v12; // zf
  unsigned int width; // [esp+8h] [ebp-14h]
  unsigned __int8 **colorindex; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  unsigned __int8 **v16; // [esp+18h] [ebp-4h]
  unsigned __int8 *ptrout; // [esp+24h] [ebp+8h]
  unsigned int col; // [esp+30h] [ebp+14h]

  out_color_components = cinfo->out_color_components;
  output_width = cinfo->output_width;
  colorindex = (unsigned __int8 **)cinfo->cquantize[1].finish_pass;
  width = output_width;
  if ( num_rows > 0 )
  {
    v6 = output_buf;
    v7 = (char *)input_buf - (char *)output_buf;
    v16 = output_buf;
    v15 = num_rows;
    do
    {
      v8 = *(unsigned __int8 **)((char *)v6 + v7);
      ptrout = *v6;
      col = output_width;
      if ( output_width != 0 )
      {
        do
        {
          v9 = 0;
          for ( i = 0; i < out_color_components; ++v8 )
          {
            v11 = colorindex[i++][*v8];
            v9 += v11;
          }
          *ptrout = v9;
          v12 = col-- == 1;
          ++ptrout;
        }
        while ( !v12 );
        v7 = (char *)input_buf - (char *)output_buf;
        v6 = v16;
        output_width = width;
      }
      ++v6;
      v12 = v15-- == 1;
      v16 = v6;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BC50
// Name: color_quantize3
// Source: json
//------------------------------------------------------------------------------
void __cdecl color_quantize3(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  void (__cdecl *finish_pass)(jpeg_decompress_struct *); // eax
  unsigned int output_width; // esi
  unsigned __int8 **v6; // ecx
  int v7; // edi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edx
  bool v10; // zf
  unsigned int width; // [esp+8h] [ebp-10h]
  unsigned __int8 *colorindex2; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *colorindex1; // [esp+10h] [ebp-8h]
  unsigned __int8 *colorindex0; // [esp+14h] [ebp-4h]
  jpeg_decompress_struct *cinfoa; // [esp+20h] [ebp+8h]

  finish_pass = cinfo->cquantize[1].finish_pass;
  colorindex0 = *(unsigned __int8 **)finish_pass;
  colorindex2 = *((unsigned __int8 **)finish_pass + 2);
  output_width = cinfo->output_width;
  colorindex1 = *((unsigned __int8 **)finish_pass + 1);
  width = output_width;
  if ( num_rows > 0 )
  {
    v6 = output_buf;
    v7 = (char *)input_buf - (char *)output_buf;
    cinfoa = (jpeg_decompress_struct *)output_buf;
    do
    {
      v8 = *(unsigned __int8 **)((char *)v6 + v7);
      v9 = *v6;
      if ( output_width != 0 )
      {
        do
        {
          *v9 = colorindex2[v8[2]] + colorindex1[v8[1]] + colorindex0[*v8];
          v8 += 3;
          ++v9;
          --output_width;
        }
        while ( output_width != 0 );
        output_width = width;
        v6 = (unsigned __int8 **)cinfoa;
        v7 = (char *)input_buf - (char *)output_buf;
      }
      ++v6;
      v10 = num_rows-- == 1;
      cinfoa = (jpeg_decompress_struct *)v6;
    }
    while ( !v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BCF0
// Name: quantize_ord_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl quantize_ord_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  unsigned int output_width; // ebx
  jpeg_color_quantizer *p_pub; // edi
  void **v7; // esi
  void (__cdecl *start_pass)(jpeg_decompress_struct *, unsigned __int8); // eax
  int v9; // edx
  int v10; // eax
  _BYTE *v11; // ecx
  unsigned __int8 *v12; // esi
  int v13; // edi
  unsigned __int8 *v14; // eax
  int v15; // esi
  int v16; // edx
  bool v17; // zf
  char row_index; // [esp+8h] [ebp-24h]
  unsigned int width; // [esp+Ch] [ebp-20h]
  unsigned __int8 *colorindex_ci; // [esp+10h] [ebp-1Ch]
  int v21; // [esp+14h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-10h]
  int ci; // [esp+20h] [ebp-Ch]
  my_cquantizer *cquantize; // [esp+24h] [ebp-8h]
  unsigned int col; // [esp+28h] [ebp-4h]
  int nc; // [esp+34h] [ebp+8h]
  unsigned __int8 **num_rowsa; // [esp+40h] [ebp+14h]

  output_width = cinfo->output_width;
  p_pub = cinfo->cquantize;
  cquantize = (my_cquantizer *)p_pub;
  nc = cinfo->out_color_components;
  width = output_width;
  if ( num_rows > 0 )
  {
    v7 = (void **)output_buf;
    num_rowsa = output_buf;
    v22 = num_rows;
    do
    {
      jzero_far(target: *v7, bytestozero: output_width);
      start_pass = p_pub[3].start_pass;
      v9 = 0;
      row_index = (char)start_pass;
      ci = 0;
      if ( nc > 0 )
      {
        v21 = (_DWORD)start_pass << 6;
        do
        {
          v10 = *(int *)((char *)v7 + (char *)input_buf - (char *)output_buf);
          v11 = *v7;
          v12 = *((unsigned __int8 **)p_pub[1].finish_pass + v9);
          v13 = v21 + *((_DWORD *)&p_pub[3].color_quantize + v9);
          colorindex_ci = v12;
          v14 = (unsigned __int8 *)(v9 + v10);
          v15 = 0;
          col = output_width;
          if ( output_width != 0 )
          {
            do
            {
              v16 = *v14;
              v14 += nc;
              *v11++ += colorindex_ci[v16 + *(_DWORD *)(v13 + 4 * v15)];
              v15 = ((_BYTE)v15 + 1) & 0xF;
              --col;
            }
            while ( col != 0 );
            output_width = width;
            v9 = ci;
          }
          p_pub = &cquantize->pub;
          v7 = (void **)num_rowsa;
          ci = ++v9;
        }
        while ( v9 < nc );
        LOBYTE(start_pass) = row_index;
      }
      ++v7;
      v17 = v22-- == 1;
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))(((_BYTE)start_pass + 1) & 0xF);
      num_rowsa = (unsigned __int8 **)v7;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BDD0
// Name: quantize3_ord_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl quantize3_ord_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_color_quantizer *p_pub; // edx
  unsigned __int8 **finish_pass; // eax
  unsigned __int8 **v6; // esi
  int v7; // edi
  unsigned __int8 *v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ecx
  bool v12; // zf
  int row_index; // [esp+4h] [ebp-2Ch]
  my_cquantizer *cquantize; // [esp+8h] [ebp-28h]
  unsigned __int8 *colorindex2; // [esp+Ch] [ebp-24h]
  int *dither2; // [esp+10h] [ebp-20h]
  unsigned __int8 *colorindex1; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *colorindex0; // [esp+18h] [ebp-18h]
  int *dither1; // [esp+1Ch] [ebp-14h]
  unsigned int width; // [esp+20h] [ebp-10h]
  int v21; // [esp+28h] [ebp-8h]
  unsigned __int8 **v22; // [esp+2Ch] [ebp-4h]
  unsigned __int8 *output_ptr; // [esp+38h] [ebp+8h]
  unsigned int col; // [esp+44h] [ebp+14h]

  p_pub = cinfo->cquantize;
  finish_pass = (unsigned __int8 **)p_pub[1].finish_pass;
  colorindex0 = *finish_pass;
  colorindex2 = finish_pass[2];
  cquantize = (my_cquantizer *)p_pub;
  colorindex1 = finish_pass[1];
  width = cinfo->output_width;
  if ( num_rows > 0 )
  {
    v6 = output_buf;
    v7 = (char *)input_buf - (char *)output_buf;
    v22 = output_buf;
    v21 = num_rows;
    while ( 1 )
    {
      v8 = *(unsigned __int8 **)((char *)v6 + v7);
      row_index = (int)p_pub[3].start_pass;
      output_ptr = *v6;
      v9 = (int)p_pub[3].finish_pass + 64 * row_index;
      v10 = (int)p_pub[3].color_quantize + 64 * row_index;
      dither2 = (int *)((char *)p_pub[3].new_color_map + 64 * row_index);
      v11 = 0;
      dither1 = (int *)v9;
      col = width;
      if ( width != 0 )
      {
        while ( 1 )
        {
          *output_ptr = colorindex2[v8[2] + dither2[v11]]
                      + colorindex1[v8[1] + *(_DWORD *)(v9 + 4 * v11)]
                      + colorindex0[*v8 + *(_DWORD *)(v10 + 4 * v11)];
          v8 += 3;
          v11 = ((_BYTE)v11 + 1) & 0xF;
          v12 = col-- == 1;
          ++output_ptr;
          if ( v12 )
            break;
          v9 = (int)dither1;
        }
        p_pub = &cquantize->pub;
      }
      v6 = v22 + 1;
      v12 = v21-- == 1;
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))(((_BYTE)row_index + 1) & 0xF);
      ++v22;
      if ( v12 )
        break;
      v7 = (char *)input_buf - (char *)output_buf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BED0
// Name: quantize_fs_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl quantize_fs_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        unsigned __int8 *num_rows)
{
  unsigned int output_width; // edx
  jpeg_color_quantizer *p_pub; // ebx
  void **v6; // esi
  int v7; // eax
  _BYTE *v8; // edi
  unsigned __int8 *v9; // edx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  _WORD *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // edx
  bool v17; // zf
  int bnexterr; // [esp+4h] [ebp-38h]
  unsigned __int8 *colormap_ci; // [esp+8h] [ebp-34h]
  unsigned __int8 *colorindex_ci; // [esp+Ch] [ebp-30h]
  unsigned __int8 *range_limit; // [esp+10h] [ebp-2Ch]
  unsigned __int8 *v22; // [esp+18h] [ebp-24h]
  unsigned int col; // [esp+1Ch] [ebp-20h]
  int dirnc; // [esp+20h] [ebp-1Ch]
  __int16 belowerr; // [esp+24h] [ebp-18h]
  unsigned __int8 **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 bpreverr; // [esp+30h] [ebp-Ch]
  my_cquantizer *cquantize; // [esp+34h] [ebp-8h]
  unsigned int width; // [esp+38h] [ebp-4h]
  int nc; // [esp+44h] [ebp+8h]
  unsigned __int8 *input_ptr; // [esp+50h] [ebp+14h]

  output_width = cinfo->output_width;
  p_pub = cinfo->cquantize;
  range_limit = cinfo->sample_range_limit;
  cquantize = (my_cquantizer *)p_pub;
  nc = cinfo->out_color_components;
  width = output_width;
  if ( (int)num_rows > 0 )
  {
    v6 = (void **)output_buf;
    v26 = output_buf;
    v22 = num_rows;
    do
    {
      jzero_far(target: *v6, bytestozero: width);
      v7 = 0;
      for ( ci = 0; v7 < nc; ci = v7 )
      {
        v8 = *v6;
        v9 = (unsigned __int8 *)(*(char **)((char *)v6 + (char *)input_buf - (char *)output_buf) + v7);
        v10 = 2 * v7;
        input_ptr = v9;
        if ( LOBYTE(p_pub[5].color_quantize) != 0 )
        {
          v8 += width - 1;
          v9 += nc * (width - 1);
          v11 = -1;
          dirnc = -nc;
          v12 = 2 * v10;
          v13 = (_WORD *)(*(char **)((char *)&p_pub[4].color_quantize + v12) + 2 * width + 2);
          p_pub = &cquantize->pub;
          input_ptr = v9;
        }
        else
        {
          v12 = 2 * v10;
          dirnc = nc;
          v13 = *(void (__cdecl **)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))((char *)&p_pub[4].color_quantize + v12);
          v11 = 1;
        }
        colorindex_ci = *(unsigned __int8 **)((char *)p_pub[1].finish_pass + v12);
        colormap_ci = *(unsigned __int8 **)((char *)cquantize->sv_colormap + v12);
        v14 = 0;
        bpreverr = 0;
        belowerr = 0;
        col = width;
        if ( width != 0 )
        {
          do
          {
            v15 = range_limit[(((__int16)v13[v11] + v14 + 8) >> 4) + *v9];
            v16 = colorindex_ci[v15];
            *v8 += v16;
            bnexterr = v15 - colormap_ci[v16];
            *v13 = 3 * bnexterr + bpreverr;
            v14 = 15 * bnexterr;
            v9 = &input_ptr[dirnc];
            bpreverr = 9 * bnexterr + belowerr;
            v8 += v11;
            v17 = col-- == 1;
            belowerr = bnexterr;
            input_ptr += dirnc;
            v13 += v11;
          }
          while ( !v17 );
        }
        p_pub = &cquantize->pub;
        v6 = (void **)v26;
        v7 = ci + 1;
        *v13 = bpreverr;
      }
      ++v6;
      v17 = v22-- == (unsigned __int8 *)1;
      LOBYTE(p_pub[5].color_quantize) = LOBYTE(p_pub[5].color_quantize) == 0;
      v26 = (unsigned __int8 **)v6;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027C050
// Name: alloc_fs_workspace
// Source: json
//------------------------------------------------------------------------------
void __usercall alloc_fs_workspace(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // edi
  _DWORD *v2; // ebx
  unsigned int arraysize; // [esp+8h] [ebp-4h]

  v1 = 0;
  arraysize = 2 * cinfo[3].global_state + 4;
  if ( (int)cinfo[4].mem > 0 )
  {
    v2 = (_DWORD *)(*(_DWORD *)&cinfo[17].is_decompressor + 68);
    do
    {
      *v2 = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: arraysize);
      ++v1;
      ++v2;
    }
    while ( v1 < (int)cinfo[4].mem );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027C0A0
// Name: start_pass_1_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_1_quant(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *v2; // edi
  J_DITHER_MODE mem; // eax
  __int32 v4; // eax
  bool v5; // zf
  void **p_color_quantize; // ebx
  int v7; // edi
  unsigned int arraysize; // [esp+10h] [ebp+8h]

  v2 = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  cinfo[4].global_state = (int)v2[1].start_pass;
  mem = (J_DITHER_MODE)cinfo[3].mem;
  *(_DWORD *)&cinfo[4].is_decompressor = v2[1].color_quantize;
  if ( mem != JDITHER_NONE )
  {
    v4 = mem - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
      {
        v5 = v2[4].color_quantize == nullptr;
        p_color_quantize = (void **)&v2[4].color_quantize;
        v2->color_quantize = quantize_fs_dither;
        LOBYTE(v2[5].color_quantize) = 0;
        if ( v5 )
          alloc_fs_workspace(cinfo);
        v7 = 0;
        for ( arraysize = 2 * cinfo[3].global_state + 4; v7 < (int)cinfo[4].mem; ++p_color_quantize )
        {
          jzero_far(target: *p_color_quantize, bytestozero: arraysize);
          ++v7;
        }
      }
      else
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    else
    {
      if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
        v2->color_quantize = quantize3_ord_dither;
      else
        v2->color_quantize = quantize_ord_dither;
      v5 = LOBYTE(v2[1].new_color_map) == 0;
      v2[3].start_pass = nullptr;
      if ( v5 )
        create_colorindex(cinfo);
      if ( v2[3].color_quantize == nullptr )
        create_odither_tables((jpeg_decompress_struct *)cinfo);
    }
  }
  else if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
  {
    v2->color_quantize = color_quantize3;
  }
  else
  {
    v2->color_quantize = color_quantize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027C190
// Name: new_color_map_1_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl new_color_map_1_quant(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 46;
  cinfo->err->error_exit(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x1027C1B0
// Name: _jinit_1pass_quantizer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_1pass_quantizer(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *v2; // eax
  int v3; // edi
  _DWORD *v4; // ebx
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]

  v2 = (jpeg_color_quantizer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 88);
  *(_DWORD *)&cinfo[17].is_decompressor = v2;
  v3 = 0;
  v2->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))start_pass_1_quant;
  v2->finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))C_BaseAnimating::ShutdownBoneSetupThreadPool;
  v2->new_color_map = (void (__cdecl *)(jpeg_decompress_struct *))new_color_map_1_quant;
  v2[4].color_quantize = nullptr;
  v2[3].color_quantize = nullptr;
  if ( (int)cinfo[4].mem > 4 )
  {
    cinfo->err->msg_code = 55;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[3].client_data > 256 )
  {
    cinfo->err->msg_code = 57;
    cinfo->err->msg_parm.i[0] = 256;
    cinfo->err->error_exit(a1: cinfo);
  }
  create_colormap((jpeg_decompress_struct *)cinfo);
  create_colorindex(cinfo);
  if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
  {
    cinfoa = (jpeg_decompress_struct *)(2 * cinfo[3].global_state + 4);
    if ( (int)cinfo[4].mem > 0 )
    {
      v4 = (_DWORD *)(*(_DWORD *)&cinfo[17].is_decompressor + 68);
      do
      {
        *v4 = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: cinfoa);
        ++v3;
        ++v4;
      }
      while ( v3 < (int)cinfo[4].mem );
    }
  }
}

} // namespace client
