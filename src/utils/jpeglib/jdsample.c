// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdsample.c
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100102F0
// Name: start_pass_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_upsample(jpeg_decompress_struct *cinfo)
{
  jpeg_upsampler *upsample; // ecx

  upsample = cinfo->upsample;
  *(_DWORD *)&upsample[7].need_context_rows = cinfo->max_v_samp_factor;
  upsample[8].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->output_height;
}

//------------------------------------------------------------------------------
// Address: 0x10010310
// Name: sep_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_upsample(
        jpeg_component_info *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_upsampler *dct_table; // eax
  int v9; // ebx
  jpeg_upsampler *v10; // esi
  unsigned int start_pass; // ebx
  my_upsampler *upsample; // [esp+Ch] [ebp-4h]
  jpeg_component_info *compptr; // [esp+18h] [ebp+8h]

  dct_table = (jpeg_upsampler *)cinfo[4].dct_table;
  upsample = (my_upsampler *)dct_table;
  if ( *(_DWORD *)&dct_table[7].need_context_rows >= cinfo[3].ac_tbl_no )
  {
    v9 = 0;
    compptr = (jpeg_component_info *)cinfo[2].width_in_blocks;
    if ( cinfo->DCT_scaled_size > 0 )
    {
      v10 = dct_table + 1;
      do
      {
        ((void (__cdecl *)(jpeg_component_info *, jpeg_component_info *, unsigned __int8 **, jpeg_upsampler *))v10[3].upsample)(
          a1: cinfo,
          a2: compptr++,
          a3: &input_buf[v9++][*in_row_group_ctr * (unsigned int)v10[7].upsample],
          a4: v10);
        v10 = (jpeg_upsampler *)((char *)v10 + 4);
      }
      while ( v9 < cinfo->DCT_scaled_size );
      dct_table = &upsample->pub;
    }
    *(_DWORD *)&dct_table[7].need_context_rows = 0;
  }
  start_pass = cinfo[3].ac_tbl_no - *(_DWORD *)&dct_table[7].need_context_rows;
  if ( (char *)start_pass > (char *)dct_table[8].start_pass )
    start_pass = (unsigned int)dct_table[8].start_pass;
  if ( start_pass > out_rows_avail - *out_row_ctr )
    start_pass = out_rows_avail - *out_row_ctr;
  (*(void (__cdecl **)(jpeg_component_info *, jpeg_upsampler *, _DWORD, unsigned __int8 **, unsigned int))(cinfo[5].component_id + 4))(
    a1: cinfo,
    a2: dct_table + 1,
    a3: *(_DWORD *)&dct_table[7].need_context_rows,
    a4: &output_buf[*out_row_ctr],
    a5: start_pass);
  *out_row_ctr += start_pass;
  upsample[2].pub.start_pass = (void (__cdecl *)(jpeg_decompress_struct *))((char *)upsample[2].pub.start_pass
                                                                          - start_pass);
  upsample[1].rows_to_go += start_pass;
  if ( (signed int)upsample[1].rows_to_go >= cinfo[3].ac_tbl_no )
    ++*in_row_group_ctr;
}

//------------------------------------------------------------------------------
// Address: 0x100103E0
// Name: fullsize_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  *output_data_ptr = input_data;
}

//------------------------------------------------------------------------------
// Address: 0x100103F0
// Name: noop_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl noop_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  *output_data_ptr = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010400
// Name: int_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  jpeg_decompress_struct *v4; // edx
  char *v5; // eax
  signed int v6; // ecx
  int v7; // ebx
  unsigned int v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edi
  char v11; // dl
  unsigned __int8 *inptr; // [esp+4h] [ebp-10h]
  unsigned __int8 *invalue; // [esp+8h] [ebp-Ch]
  int v_expand; // [esp+Ch] [ebp-8h]
  unsigned __int8 **output_data; // [esp+10h] [ebp-4h]
  int h_expand; // [esp+28h] [ebp+14h]

  v4 = cinfo;
  output_data = *output_data_ptr;
  v5 = (char *)cinfo->upsample + compptr->component_index;
  v6 = (unsigned __int8)v5[140];
  v7 = 0;
  h_expand = v6;
  for ( v_expand = (unsigned __int8)v5[150]; v7 < cinfo->max_v_samp_factor; ++input_data )
  {
    v8 = (unsigned int)output_data[v7];
    v9 = *input_data;
    v10 = v8 + v4->output_width;
    if ( v8 < v10 )
    {
      do
      {
        v11 = *v9++;
        LOBYTE(invalue) = v11;
        inptr = v9;
        if ( v6 > 0 )
        {
          memset(dst: v8, value: invalue, count: v6);
          v6 = h_expand;
          v9 = inptr;
          v8 += h_expand;
        }
      }
      while ( v8 < v10 );
      v4 = cinfo;
    }
    if ( v_expand > 1 )
    {
      jcopy_sample_rows(
        input_array: output_data,
        source_row: v7,
        output_array: output_data,
        dest_row: v7 + 1,
        num_rows: v_expand - 1,
        num_cols: v4->output_width);
      v6 = h_expand;
    }
    v7 += v_expand;
    v4 = cinfo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100104D0
// Name: h2v1_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  char *v5; // edi
  jpeg_decompress_struct *v6; // edx
  char *v7; // eax
  char *v8; // esi
  unsigned int v9; // ecx
  char v10; // dl
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int inrow; // [esp+1Ch] [ebp+14h]

  v5 = (char *)*output_data_ptr;
  inrow = 0;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v6 = (jpeg_decompress_struct *)((char *)input_data - v5);
    cinfoa = (jpeg_decompress_struct *)((char *)input_data - v5);
    do
    {
      v7 = *(char **)v5;
      v8 = *(char **)&v5[(_DWORD)v6];
      v9 = *(_DWORD *)v5 + cinfo->output_width;
      if ( *(_DWORD *)v5 < v9 )
      {
        do
        {
          v10 = *v8;
          *v7 = *v8;
          v7[1] = v10;
          v7 += 2;
          ++v8;
        }
        while ( (unsigned int)v7 < v9 );
        v6 = cinfoa;
      }
      v5 += 4;
      ++inrow;
    }
    while ( inrow < cinfo->max_v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010530
// Name: h2v2_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  unsigned __int8 **v4; // ebx
  int i; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *j; // ecx
  unsigned __int8 v9; // dl

  v4 = *output_data_ptr;
  for ( i = 0; i < cinfo->max_v_samp_factor; i += 2 )
  {
    v6 = *input_data;
    v7 = v4[i];
    for ( j = &v7[cinfo->output_width]; v7 < j; ++v6 )
    {
      v9 = *v6;
      *v7 = *v6;
      v7[1] = v9;
      v7 += 2;
    }
    jcopy_sample_rows(
      input_array: v4,
      source_row: i,
      output_array: v4,
      dest_row: i + 1,
      num_rows: 1,
      num_cols: cinfo->output_width);
    ++input_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100105B0
// Name: h2v1_fancy_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_fancy_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  char *v4; // ebx
  int v5; // eax
  unsigned __int8 *v6; // ecx
  int v7; // edx
  _BYTE *v8; // eax
  int v9; // esi
  unsigned __int8 *v10; // ecx
  _BYTE *v11; // eax
  unsigned int v12; // esi
  int v13; // edi
  int v14; // edx
  int v15; // edx
  char *i; // [esp+4h] [ebp-4h]
  int inrow; // [esp+1Ch] [ebp+14h]

  v4 = (char *)*output_data_ptr;
  inrow = 0;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v5 = (char *)input_data - v4;
    for ( i = (char *)((char *)input_data - v4); ; v5 = (int)i )
    {
      v6 = *(unsigned __int8 **)&v4[v5];
      v7 = *v6;
      v8 = *(_BYTE **)v4;
      *v8 = v7;
      v9 = v6[1];
      v10 = v6 + 1;
      v8[1] = (3 * v7 + v9 + 2) >> 2;
      v11 = v8 + 2;
      v12 = compptr->downsampled_width - 2;
      if ( compptr->downsampled_width != 2 )
      {
        do
        {
          v13 = 3 * *v10;
          v14 = *(v10++ - 1);
          *v11 = (v14 + v13 + 1) >> 2;
          v11[1] = (*v10 + v13 + 2) >> 2;
          v11 += 2;
          --v12;
        }
        while ( v12 != 0 );
      }
      v15 = *v10;
      *v11 = (*(v10 - 1) + 3 * v15 + 1) >> 2;
      v11[1] = v15;
      v4 += 4;
      if ( ++inrow >= cinfo->max_v_samp_factor )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010670
// Name: h2v2_fancy_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_fancy_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  int v4; // eax
  unsigned __int8 **v5; // esi
  int v6; // ecx
  unsigned __int8 *v7; // edx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  int v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned __int8 *v13; // edx
  _BYTE *v14; // ecx
  int v15; // ebx
  bool v16; // zf
  unsigned __int8 **output_data; // [esp+0h] [ebp-1Ch]
  int outrow; // [esp+4h] [ebp-18h]
  int v; // [esp+8h] [ebp-14h]
  unsigned int colctr; // [esp+Ch] [ebp-10h]
  int thiscolsum; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v22; // [esp+18h] [ebp-4h]
  int lastcolsum; // [esp+30h] [ebp+14h]

  v4 = 0;
  output_data = *output_data_ptr;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v5 = input_data;
    v22 = input_data;
    do
    {
      v6 = 0;
      v = 0;
      do
      {
        v7 = *v5;
        if ( v6 != 0 )
          v8 = v5[1];
        else
          v8 = *(v5 - 1);
        v9 = output_data[v4];
        outrow = v4 + 1;
        v10 = *v8 + 3 * *v7;
        v11 = v8[1] + 3 * v7[1];
        *v9 = (4 * v10 + 8) >> 4;
        lastcolsum = v10;
        v9[1] = (v10 + v11 + 2 * v10 + 7) >> 4;
        v12 = v8 + 2;
        v13 = v7 + 2;
        v14 = v9 + 2;
        v15 = v11;
        thiscolsum = v11;
        colctr = compptr->downsampled_width - 2;
        if ( compptr->downsampled_width != 2 )
        {
          do
          {
            v11 = *v12 + 3 * *v13;
            *v14 = (3 * v15 + lastcolsum + 8) >> 4;
            v14[1] = (3 * v15 + v11 + 7) >> 4;
            ++v12;
            ++v13;
            v14 += 2;
            v16 = colctr-- == 1;
            v15 = v11;
            lastcolsum = thiscolsum;
            thiscolsum = v11;
          }
          while ( !v16 );
        }
        v5 = v22;
        *v14 = (v11 + lastcolsum + 2 * v11 + 8) >> 4;
        v14[1] = (4 * v11 + 7) >> 4;
        v4 = outrow;
        v6 = v + 1;
        v = v6;
      }
      while ( v6 < 2 );
      v5 = ++v22;
    }
    while ( outrow < cinfo->max_v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100107A0
// Name: _jinit_upsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_upsampler(jpeg_common_struct *cinfo)
{
  jpeg_upsampler *v2; // ebx
  int *p_free_pool; // eax
  void (__cdecl **i)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  int v5; // edi
  int client_data; // edx
  int v7; // ecx
  int progress; // eax
  int v9; // edx
  jpeg_memory_mgr *mem; // edi
  int v11; // eax
  int v12; // [esp-8h] [ebp-24h]
  my_upsampler *upsample; // [esp+8h] [ebp-14h]
  int v_out_group; // [esp+Ch] [ebp-10h]
  int h_in_group; // [esp+10h] [ebp-Ch]
  int h_in_groupa; // [esp+10h] [ebp-Ch]
  int ci; // [esp+14h] [ebp-8h]
  int *v18; // [esp+18h] [ebp-4h]
  char do_fancy_3; // [esp+27h] [ebp+Bh]

  v2 = (jpeg_upsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 160);
  cinfo[17].progress = (jpeg_progress_mgr *)v2;
  v2->start_pass = start_pass_upsample;
  v2->upsample = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))sep_upsample;
  v2->need_context_rows = 0;
  upsample = (my_upsampler *)v2;
  if ( BYTE2(cinfo[11].err) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( LOBYTE(cinfo[3].err) == 0 || (do_fancy_3 = 1, *(int *)&cinfo[11].is_decompressor <= 1) )
    do_fancy_3 = 0;
  ci = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (int *)&cinfo[8].mem->free_pool;
    v18 = p_free_pool;
    for ( i = &v2[4].upsample; ; ++i )
    {
      v5 = *(_DWORD *)&cinfo[11].is_decompressor;
      h_in_group = *p_free_pool * *(p_free_pool - 7) / v5;
      client_data = (int)cinfo[11].client_data;
      v_out_group = client_data;
      v7 = *p_free_pool * *(v18 - 6) / v5;
      progress = (int)cinfo[11].progress;
      i[12] = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))v7;
      if ( *((_BYTE *)v18 + 12) == 0 )
      {
        *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))noop_upsample;
        goto LABEL_31;
      }
      if ( h_in_group == progress && v7 == client_data )
      {
        *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))fullsize_upsample;
        goto LABEL_31;
      }
      if ( 2 * h_in_group != progress )
        break;
      if ( v7 == client_data )
      {
        if ( do_fancy_3 != 0 && (unsigned int)v18[1] > 2 )
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v1_fancy_upsample;
        else
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v1_upsample;
      }
      else
      {
        if ( 2 * h_in_group != progress || 2 * v7 != client_data )
          break;
        if ( do_fancy_3 != 0 && (unsigned int)v18[1] > 2 )
        {
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v2_fancy_upsample;
          upsample->pub.need_context_rows = 1;
        }
        else
        {
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v2_upsample;
        }
      }
LABEL_30:
      mem = cinfo->mem;
      v12 = (int)cinfo[11].client_data;
      v11 = jround_up(a: cinfo[3].global_state, b: (int)cinfo[11].progress);
      *(i - 10) = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))mem->alloc_sarray(a1: cinfo, a2: 1, a3: v11, a4: v12);
LABEL_31:
      v18 += 21;
      if ( ++ci >= (int)cinfo[1].client_data )
        return;
      p_free_pool = v18;
    }
    v9 = progress % h_in_group;
    h_in_groupa = progress / h_in_group;
    if ( v9 != 0 || v_out_group % v7 != 0 )
    {
      cinfo->err->msg_code = 38;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))int_upsample;
      *((_BYTE *)&upsample[2].rows_to_go + ci) = h_in_groupa;
      *((_BYTE *)&upsample[3].pub.upsample + ci + 2) = v_out_group / v7;
    }
    goto LABEL_30;
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10279060
// Name: start_pass_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_upsample(jpeg_decompress_struct *cinfo)
{
  jpeg_upsampler *upsample; // ecx

  upsample = cinfo->upsample;
  *(_DWORD *)&upsample[7].need_context_rows = cinfo->max_v_samp_factor;
  upsample[8].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->output_height;
}

//------------------------------------------------------------------------------
// Address: 0x10279080
// Name: sep_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_upsample(
        jpeg_component_info *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_upsampler *dct_table; // eax
  int v9; // ebx
  jpeg_upsampler *v10; // esi
  unsigned int start_pass; // ebx
  my_upsampler *upsample; // [esp+Ch] [ebp-4h]
  jpeg_component_info *compptr; // [esp+18h] [ebp+8h]

  dct_table = (jpeg_upsampler *)cinfo[4].dct_table;
  upsample = (my_upsampler *)dct_table;
  if ( *(_DWORD *)&dct_table[7].need_context_rows >= cinfo[3].ac_tbl_no )
  {
    v9 = 0;
    compptr = (jpeg_component_info *)cinfo[2].width_in_blocks;
    if ( cinfo->DCT_scaled_size > 0 )
    {
      v10 = dct_table + 1;
      do
      {
        ((void (__cdecl *)(jpeg_component_info *, jpeg_component_info *, unsigned __int8 **, jpeg_upsampler *))v10[3].upsample)(
          a1: cinfo,
          a2: compptr++,
          a3: &input_buf[v9++][*in_row_group_ctr * (unsigned int)v10[7].upsample],
          a4: v10);
        v10 = (jpeg_upsampler *)((char *)v10 + 4);
      }
      while ( v9 < cinfo->DCT_scaled_size );
      dct_table = &upsample->pub;
    }
    *(_DWORD *)&dct_table[7].need_context_rows = 0;
  }
  start_pass = cinfo[3].ac_tbl_no - *(_DWORD *)&dct_table[7].need_context_rows;
  if ( (char *)start_pass > (char *)dct_table[8].start_pass )
    start_pass = (unsigned int)dct_table[8].start_pass;
  if ( start_pass > out_rows_avail - *out_row_ctr )
    start_pass = out_rows_avail - *out_row_ctr;
  (*(void (__cdecl **)(jpeg_component_info *, jpeg_upsampler *, _DWORD, unsigned __int8 **, unsigned int))(cinfo[5].component_id + 4))(
    a1: cinfo,
    a2: dct_table + 1,
    a3: *(_DWORD *)&dct_table[7].need_context_rows,
    a4: &output_buf[*out_row_ctr],
    a5: start_pass);
  *out_row_ctr += start_pass;
  upsample[2].pub.start_pass = (void (__cdecl *)(jpeg_decompress_struct *))((char *)upsample[2].pub.start_pass
                                                                          - start_pass);
  upsample[1].rows_to_go += start_pass;
  if ( (signed int)upsample[1].rows_to_go >= cinfo[3].ac_tbl_no )
    ++*in_row_group_ctr;
}

//------------------------------------------------------------------------------
// Address: 0x10279150
// Name: fullsize_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  *output_data_ptr = input_data;
}

//------------------------------------------------------------------------------
// Address: 0x10279160
// Name: noop_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl noop_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  *output_data_ptr = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10279170
// Name: int_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  jpeg_decompress_struct *v4; // edx
  char *v5; // eax
  signed int v6; // ecx
  int v7; // ebx
  unsigned int v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edi
  char v11; // dl
  unsigned __int8 *inptr; // [esp+4h] [ebp-10h]
  unsigned __int8 *invalue; // [esp+8h] [ebp-Ch]
  int v_expand; // [esp+Ch] [ebp-8h]
  unsigned __int8 **output_data; // [esp+10h] [ebp-4h]
  int h_expand; // [esp+28h] [ebp+14h]

  v4 = cinfo;
  output_data = *output_data_ptr;
  v5 = (char *)cinfo->upsample + compptr->component_index;
  v6 = (unsigned __int8)v5[140];
  v7 = 0;
  h_expand = v6;
  for ( v_expand = (unsigned __int8)v5[150]; v7 < cinfo->max_v_samp_factor; ++input_data )
  {
    v8 = (unsigned int)output_data[v7];
    v9 = *input_data;
    v10 = v8 + v4->output_width;
    if ( v8 < v10 )
    {
      do
      {
        v11 = *v9++;
        LOBYTE(invalue) = v11;
        inptr = v9;
        if ( v6 > 0 )
        {
          memset(dst: v8, value: invalue, count: v6);
          v6 = h_expand;
          v9 = inptr;
          v8 += h_expand;
        }
      }
      while ( v8 < v10 );
      v4 = cinfo;
    }
    if ( v_expand > 1 )
    {
      jcopy_sample_rows(
        input_array: output_data,
        source_row: v7,
        output_array: output_data,
        dest_row: v7 + 1,
        num_rows: v_expand - 1,
        num_cols: v4->output_width);
      v6 = h_expand;
    }
    v7 += v_expand;
    v4 = cinfo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279240
// Name: h2v1_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  char *v5; // edi
  jpeg_decompress_struct *v6; // edx
  char *v7; // eax
  char *v8; // esi
  unsigned int v9; // ecx
  char v10; // dl
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int inrow; // [esp+1Ch] [ebp+14h]

  v5 = (char *)*output_data_ptr;
  inrow = 0;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v6 = (jpeg_decompress_struct *)((char *)input_data - v5);
    cinfoa = (jpeg_decompress_struct *)((char *)input_data - v5);
    do
    {
      v7 = *(char **)v5;
      v8 = *(char **)&v5[(_DWORD)v6];
      v9 = *(_DWORD *)v5 + cinfo->output_width;
      if ( *(_DWORD *)v5 < v9 )
      {
        do
        {
          v10 = *v8;
          *v7 = *v8;
          v7[1] = v10;
          v7 += 2;
          ++v8;
        }
        while ( (unsigned int)v7 < v9 );
        v6 = cinfoa;
      }
      v5 += 4;
      ++inrow;
    }
    while ( inrow < cinfo->max_v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102792A0
// Name: h2v2_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  unsigned __int8 **v4; // ebx
  int i; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *j; // ecx
  unsigned __int8 v9; // dl

  v4 = *output_data_ptr;
  for ( i = 0; i < cinfo->max_v_samp_factor; i += 2 )
  {
    v6 = *input_data;
    v7 = v4[i];
    for ( j = &v7[cinfo->output_width]; v7 < j; ++v6 )
    {
      v9 = *v6;
      *v7 = *v6;
      v7[1] = v9;
      v7 += 2;
    }
    jcopy_sample_rows(
      input_array: v4,
      source_row: i,
      output_array: v4,
      dest_row: i + 1,
      num_rows: 1,
      num_cols: cinfo->output_width);
    ++input_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279320
// Name: h2v1_fancy_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_fancy_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  char *v4; // ebx
  int v5; // eax
  unsigned __int8 *v6; // ecx
  int v7; // edx
  _BYTE *v8; // eax
  int v9; // esi
  unsigned __int8 *v10; // ecx
  _BYTE *v11; // eax
  unsigned int v12; // esi
  int v13; // edi
  int v14; // edx
  int v15; // edx
  char *i; // [esp+4h] [ebp-4h]
  int inrow; // [esp+1Ch] [ebp+14h]

  v4 = (char *)*output_data_ptr;
  inrow = 0;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v5 = (char *)input_data - v4;
    for ( i = (char *)((char *)input_data - v4); ; v5 = (int)i )
    {
      v6 = *(unsigned __int8 **)&v4[v5];
      v7 = *v6;
      v8 = *(_BYTE **)v4;
      *v8 = v7;
      v9 = v6[1];
      v10 = v6 + 1;
      v8[1] = (3 * v7 + v9 + 2) >> 2;
      v11 = v8 + 2;
      v12 = compptr->downsampled_width - 2;
      if ( compptr->downsampled_width != 2 )
      {
        do
        {
          v13 = 3 * *v10;
          v14 = *(v10++ - 1);
          *v11 = (v14 + v13 + 1) >> 2;
          v11[1] = (*v10 + v13 + 2) >> 2;
          v11 += 2;
          --v12;
        }
        while ( v12 != 0 );
      }
      v15 = *v10;
      *v11 = (*(v10 - 1) + 3 * v15 + 1) >> 2;
      v11[1] = v15;
      v4 += 4;
      if ( ++inrow >= cinfo->max_v_samp_factor )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102793E0
// Name: h2v2_fancy_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_fancy_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  int v4; // eax
  unsigned __int8 **v5; // esi
  int v6; // ecx
  unsigned __int8 *v7; // edx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  int v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned __int8 *v13; // edx
  _BYTE *v14; // ecx
  int v15; // ebx
  bool v16; // zf
  unsigned __int8 **output_data; // [esp+0h] [ebp-1Ch]
  int outrow; // [esp+4h] [ebp-18h]
  int v; // [esp+8h] [ebp-14h]
  unsigned int colctr; // [esp+Ch] [ebp-10h]
  int thiscolsum; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v22; // [esp+18h] [ebp-4h]
  int lastcolsum; // [esp+30h] [ebp+14h]

  v4 = 0;
  output_data = *output_data_ptr;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v5 = input_data;
    v22 = input_data;
    do
    {
      v6 = 0;
      v = 0;
      do
      {
        v7 = *v5;
        if ( v6 != 0 )
          v8 = v5[1];
        else
          v8 = *(v5 - 1);
        v9 = output_data[v4];
        outrow = v4 + 1;
        v10 = *v8 + 3 * *v7;
        v11 = v8[1] + 3 * v7[1];
        *v9 = (4 * v10 + 8) >> 4;
        lastcolsum = v10;
        v9[1] = (v10 + v11 + 2 * v10 + 7) >> 4;
        v12 = v8 + 2;
        v13 = v7 + 2;
        v14 = v9 + 2;
        v15 = v11;
        thiscolsum = v11;
        colctr = compptr->downsampled_width - 2;
        if ( compptr->downsampled_width != 2 )
        {
          do
          {
            v11 = *v12 + 3 * *v13;
            *v14 = (3 * v15 + lastcolsum + 8) >> 4;
            v14[1] = (3 * v15 + v11 + 7) >> 4;
            ++v12;
            ++v13;
            v14 += 2;
            v16 = colctr-- == 1;
            v15 = v11;
            lastcolsum = thiscolsum;
            thiscolsum = v11;
          }
          while ( !v16 );
        }
        v5 = v22;
        *v14 = (v11 + lastcolsum + 2 * v11 + 8) >> 4;
        v14[1] = (4 * v11 + 7) >> 4;
        v4 = outrow;
        v6 = v + 1;
        v = v6;
      }
      while ( v6 < 2 );
      v5 = ++v22;
    }
    while ( outrow < cinfo->max_v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279510
// Name: _jinit_upsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_upsampler(jpeg_common_struct *cinfo)
{
  jpeg_upsampler *v2; // ebx
  int *p_free_pool; // eax
  void (__cdecl **i)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  int v5; // edi
  int client_data; // edx
  int v7; // ecx
  int progress; // eax
  int v9; // edx
  jpeg_memory_mgr *mem; // edi
  int v11; // eax
  int v12; // [esp-8h] [ebp-24h]
  my_upsampler *upsample; // [esp+8h] [ebp-14h]
  int v_out_group; // [esp+Ch] [ebp-10h]
  int h_in_group; // [esp+10h] [ebp-Ch]
  int h_in_groupa; // [esp+10h] [ebp-Ch]
  int ci; // [esp+14h] [ebp-8h]
  int *v18; // [esp+18h] [ebp-4h]
  char do_fancy_3; // [esp+27h] [ebp+Bh]

  v2 = (jpeg_upsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 160);
  cinfo[17].progress = (jpeg_progress_mgr *)v2;
  v2->start_pass = start_pass_upsample;
  v2->upsample = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))sep_upsample;
  v2->need_context_rows = 0;
  upsample = (my_upsampler *)v2;
  if ( BYTE2(cinfo[11].err) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( LOBYTE(cinfo[3].err) == 0 || (do_fancy_3 = 1, *(int *)&cinfo[11].is_decompressor <= 1) )
    do_fancy_3 = 0;
  ci = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (int *)&cinfo[8].mem->free_pool;
    v18 = p_free_pool;
    for ( i = &v2[4].upsample; ; ++i )
    {
      v5 = *(_DWORD *)&cinfo[11].is_decompressor;
      h_in_group = *p_free_pool * *(p_free_pool - 7) / v5;
      client_data = (int)cinfo[11].client_data;
      v_out_group = client_data;
      v7 = *p_free_pool * *(v18 - 6) / v5;
      progress = (int)cinfo[11].progress;
      i[12] = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))v7;
      if ( *((_BYTE *)v18 + 12) == 0 )
      {
        *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))noop_upsample;
        goto LABEL_31;
      }
      if ( h_in_group == progress && v7 == client_data )
      {
        *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))fullsize_upsample;
        goto LABEL_31;
      }
      if ( 2 * h_in_group != progress )
        break;
      if ( v7 == client_data )
      {
        if ( do_fancy_3 != 0 && (unsigned int)v18[1] > 2 )
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v1_fancy_upsample;
        else
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v1_upsample;
      }
      else
      {
        if ( 2 * h_in_group != progress || 2 * v7 != client_data )
          break;
        if ( do_fancy_3 != 0 && (unsigned int)v18[1] > 2 )
        {
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v2_fancy_upsample;
          upsample->pub.need_context_rows = 1;
        }
        else
        {
          *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))h2v2_upsample;
        }
      }
LABEL_30:
      mem = cinfo->mem;
      v12 = (int)cinfo[11].client_data;
      v11 = jround_up(a: cinfo[3].global_state, b: (int)cinfo[11].progress);
      *(i - 10) = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))mem->alloc_sarray(a1: cinfo, a2: 1, a3: v11, a4: v12);
LABEL_31:
      v18 += 21;
      if ( ++ci >= (int)cinfo[1].client_data )
        return;
      p_free_pool = v18;
    }
    v9 = progress % h_in_group;
    h_in_groupa = progress / h_in_group;
    if ( v9 != 0 || v_out_group % v7 != 0 )
    {
      cinfo->err->msg_code = 38;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      *i = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))int_upsample;
      *((_BYTE *)&upsample[2].rows_to_go + ci) = h_in_groupa;
      *((_BYTE *)&upsample[3].pub.upsample + ci + 2) = v_out_group / v7;
    }
    goto LABEL_30;
  }
}

} // namespace client
