// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcsample.c
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10256DF0
// Name: expand_right_edge
// Source: json
//------------------------------------------------------------------------------
void __usercall expand_right_edge(
        unsigned int output_cols@<eax>,
        unsigned __int8 **image_data,
        int num_rows,
        unsigned int input_cols)
{
  unsigned int v4; // edi
  int i; // esi

  v4 = output_cols - input_cols;
  if ( (int)(output_cols - input_cols) > 0 )
  {
    for ( i = 0; i < num_rows; ++i )
      memset(dst: &image_data[i][input_cols], value: image_data[i][input_cols - 1], count: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256E40
// Name: sep_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_downsample(
        jpeg_compress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_index,
        unsigned __int8 ***output_buf,
        unsigned int out_row_group_index)
{
  jpeg_component_info *comp_info; // edi
  unsigned __int8 ***v7; // esi
  int i; // eax
  int ci; // [esp+10h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    cinfoa = (jpeg_compress_struct *)&cinfo->downsample[1];
    v7 = input_buf;
    for ( i = (char *)output_buf - (char *)input_buf; ; i = (char *)output_buf - (char *)input_buf )
    {
      ((void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, unsigned __int8 **))cinfoa->err)(
        a1: cinfo,
        a2: comp_info,
        a3: &(*v7)[in_row_index],
        a4: &(*(unsigned __int8 ***)((char *)v7 + i))[out_row_group_index * comp_info->v_samp_factor]);
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      ++v7;
      ++comp_info;
      if ( ++ci >= cinfo->num_components )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256ED0
// Name: int_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  unsigned int v13; // ecx
  bool v14; // zf
  int numpix; // [esp+Ch] [ebp-30h]
  int numpix2; // [esp+10h] [ebp-2Ch]
  int h_expand; // [esp+14h] [ebp-28h]
  unsigned int output_cols; // [esp+18h] [ebp-24h]
  int outrowa; // [esp+1Ch] [ebp-20h]
  int outrow; // [esp+1Ch] [ebp-20h]
  int v_expand; // [esp+20h] [ebp-1Ch]
  unsigned int v22; // [esp+24h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+28h] [ebp-14h]
  int v24; // [esp+2Ch] [ebp-10h]
  int outvalue; // [esp+30h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+34h] [ebp-8h]
  unsigned int outcol_h; // [esp+38h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+44h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  v4 = cinfo->max_h_samp_factor / compptr->h_samp_factor;
  outrowa = cinfo->max_v_samp_factor;
  h_expand = v4;
  v5 = v4 * (outrowa / compptr->v_samp_factor);
  v_expand = outrowa / compptr->v_samp_factor;
  v6 = v5 / 2;
  numpix = v5;
  numpix2 = v5 / 2;
  expand_right_edge(
    output_cols: output_cols * v4,
    image_data: input_data,
    num_rows: outrowa,
    input_cols: cinfo->image_width);
  v7 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v26 = input_data;
    do
    {
      outptr = output_data[v7];
      outcol_h = 0;
      if ( output_cols != 0 )
      {
        v22 = output_cols;
        do
        {
          v8 = 0;
          outvalue = 0;
          if ( v_expand > 0 )
          {
            cinfoa = (jpeg_compress_struct *)v26;
            v24 = v_expand;
            do
            {
              v9 = (unsigned __int8 *)cinfoa->err + outcol_h;
              v10 = 0;
              v11 = 0;
              v12 = 0;
              if ( v4 >= 2 )
              {
                v13 = ((unsigned int)(v4 - 2) >> 1) + 1;
                v12 = 2 * v13;
                do
                {
                  v10 += *v9;
                  v11 += v9[1];
                  v9 += 2;
                  --v13;
                }
                while ( v13 != 0 );
                v4 = h_expand;
                v8 = outvalue;
              }
              if ( v12 < v4 )
                v8 += *v9;
              cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
              v8 += v10 + v11;
              v14 = v24-- == 1;
              outvalue = v8;
            }
            while ( !v14 );
            v6 = numpix2;
            v5 = numpix;
          }
          outcol_h += v4;
          v14 = v22-- == 1;
          *outptr++ = (v8 + v6) / v5;
        }
        while ( !v14 );
        v7 = outrow;
      }
      v26 += v_expand;
      outrow = ++v7;
    }
    while ( v7 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257020
// Name: fullsize_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  jcopy_sample_rows(
    input_array: input_data,
    source_row: 0,
    output_array: output_data,
    dest_row: 0,
    num_rows: cinfo->max_v_samp_factor,
    num_cols: cinfo->image_width);
  expand_right_edge(
    output_cols: 8 * compptr->width_in_blocks,
    image_data: output_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
}

//------------------------------------------------------------------------------
// Address: 0x10257070
// Name: h2v1_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // edi
  int v5; // ebx
  unsigned __int8 **v6; // edx
  _BYTE *v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // esi
  unsigned int output_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 **v11; // [esp+14h] [ebp-4h]
  int outrow; // [esp+20h] [ebp+8h]

  v4 = 8 * compptr->width_in_blocks;
  output_cols = v4;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = (char *)output_data - (char *)input_data;
    v6 = input_data;
    v11 = input_data;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v6 + v5);
      v8 = *v6;
      v9 = 0;
      if ( v4 != 0 )
      {
        do
        {
          *v7++ = (v9 + v8[1] + *v8) >> 1;
          v9 ^= 1u;
          v8 += 2;
          --v4;
        }
        while ( v4 != 0 );
        v4 = output_cols;
        v6 = v11;
        v5 = (char *)output_data - (char *)input_data;
      }
      ++v6;
      ++outrow;
      v11 = v6;
    }
    while ( outrow < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257110
// Name: h2v2_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // edi
  unsigned __int8 **v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  int v9; // edi
  unsigned int output_cols; // [esp+Ch] [ebp-10h]
  int outrow; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v12; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]
  int bias; // [esp+24h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  v4 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = input_data;
    v12 = input_data;
    do
    {
      v6 = output_data[v4];
      v7 = *v5;
      v8 = v5[1];
      bias = 1;
      if ( output_cols != 0 )
      {
        for ( i = output_cols; i != 0; --i )
        {
          v9 = bias + *v8;
          bias ^= 3u;
          *v6++ = (v7[1] + v8[1] + v9 + *v7) >> 2;
          v7 += 2;
          v8 += 2;
        }
        v4 = outrow;
        v5 = v12;
      }
      ++v4;
      v5 += 2;
      v12 = v5;
      outrow = v4;
    }
    while ( v4 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102571C0
// Name: h2v2_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // esi
  bool v18; // zf
  unsigned int v19; // [esp+Ch] [ebp-2Ch]
  int outrow; // [esp+14h] [ebp-24h]
  unsigned __int8 **v21; // [esp+18h] [ebp-20h]
  unsigned int colctra; // [esp+1Ch] [ebp-1Ch]
  unsigned int colctr; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+20h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+30h] [ebp-8h]
  int memberscale; // [esp+34h] [ebp-4h]
  int neighscale; // [esp+40h] [ebp+8h]
  unsigned __int8 *below_ptr; // [esp+48h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = 0x4000 - 80 * smoothing_factor;
  neighscale = 16 * smoothing_factor;
  v6 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v19 = v4 - 2;
    v7 = input_data - 1;
    v21 = input_data - 1;
    do
    {
      v8 = v7[2];
      v9 = v7[1];
      v10 = output_data[v6];
      v11 = *v7;
      v12 = v7[3];
      colctra = (unsigned int)(v12 + 2);
      v24 = v11 + 2;
      ++v10;
      v13 = neighscale
          * (*v12 + *v11 + v11[2] + 2 * (*v12 + *v11 + *v8 + v11[1] + v12[1] + *v9 + v8[2] + v9[2]) + v12[2])
          + memberscale * (*v8 + *v9 + v8[1] + v9[1])
          + 0x8000;
      v14 = v9 + 2;
      v15 = v8 + 2;
      *(v10 - 1) = BYTE2(v13);
      v16 = (unsigned __int8 *)colctra;
      outptr = v10;
      v17 = v24;
      below_ptr = (unsigned __int8 *)colctra;
      colctr = v19;
      if ( v19 != 0 )
      {
        do
        {
          *outptr = (neighscale
                   * (v16[2]
                    + v17[2]
                    + *(v17 - 1)
                    + *(v16 - 1)
                    + 2 * (v14[2] + *v17 + v15[2] + *v16 + *(v14 - 1) + *(v15 - 1) + v17[1] + v16[1]))
                   + memberscale * (*v14 + *v15 + v14[1] + (unsigned int)v15[1])
                   + 0x8000) >> 16;
          v16 = below_ptr + 2;
          v14 += 2;
          v15 += 2;
          v17 += 2;
          v18 = colctr-- == 1;
          ++outptr;
          below_ptr += 2;
        }
        while ( !v18 );
      }
      *outptr = (neighscale
               * (v16[1]
                + v17[1]
                + *(below_ptr - 1)
                + 2 * (v16[1] + v17[1] + v15[1] + *(v14 - 1) + *(v15 - 1) + v14[1] + *v16 + *v17)
                + *(v17 - 1))
               + memberscale * (v15[1] + v14[1] + *v15 + (unsigned int)*v14)
               + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v21 + 2;
      v21 += 2;
      outrow = v6;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257420
// Name: fullsize_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  _BYTE *v19; // esi
  int v20; // ebx
  int v21; // esi
  bool v22; // zf
  unsigned int v23; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 **v24; // [esp+10h] [ebp-18h]
  int outrow; // [esp+14h] [ebp-14h]
  unsigned int colctr; // [esp+18h] [ebp-10h]
  unsigned __int8 *below_ptr; // [esp+1Ch] [ebp-Ch]
  int memberscale; // [esp+20h] [ebp-8h]
  int neighscale; // [esp+24h] [ebp-4h]
  unsigned __int8 *outptra; // [esp+30h] [ebp+8h]
  unsigned __int8 *outptr; // [esp+30h] [ebp+8h]
  int colsum; // [esp+38h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: v4,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = (128 - smoothing_factor) << 9;
  v6 = 0;
  neighscale = smoothing_factor << 6;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v7 = input_data + 1;
    v23 = v4 - 2;
    v24 = input_data + 1;
    do
    {
      v8 = *(v7 - 2);
      outptra = output_data[v6];
      v9 = *(v7 - 1);
      v10 = *v7;
      v11 = *v9;
      v12 = v11 + *v10 + *v8;
      v13 = v8[1];
      below_ptr = v10 + 1;
      v14 = v8 + 1;
      v15 = v13 + v10[1];
      v16 = v9[1];
      v17 = v9 + 1;
      v18 = v16 + v15;
      *outptra = (unsigned int)(neighscale * (v18 + 2 * v12 - v11) + memberscale * v11 + 0x8000) >> 16;
      v19 = outptra + 1;
      outptr = outptra + 1;
      colsum = v18;
      colctr = v23;
      if ( v23 != 0 )
      {
        do
        {
          v20 = v14[1];
          v21 = *v17;
          ++v14;
          v18 = *++v17 + v20 + *++below_ptr;
          *outptr = (unsigned int)(neighscale * (colsum + v18 + v12 - v21) + memberscale * v21 + 0x8000) >> 16;
          v12 = colsum;
          v19 = outptr + 1;
          v22 = colctr-- == 1;
          ++outptr;
          colsum = v18;
        }
        while ( !v22 );
      }
      *v19 = (neighscale * (v12 + 2 * v18 - *v17) + memberscale * (unsigned int)*v17 + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v24 + 1;
      outrow = v6;
      ++v24;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257590
// Name: _jinit_downsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_downsampler(jpeg_common_struct *cinfo)
{
  jpeg_downsampler *v2; // edi
  int *v3; // ebx
  jpeg_downsampler *v4; // edi
  int v5; // ecx
  int err; // eax
  bool v7; // zf
  int ci; // [esp+8h] [ebp-Ch]
  my_downsampler *downsample; // [esp+Ch] [ebp-8h]
  unsigned __int8 smoothok; // [esp+13h] [ebp-1h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  smoothok = 1;
  v2 = (jpeg_downsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 52);
  cinfo[14].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *))CColorBalanceUIPanel::Init;
  v2->downsample = sep_downsample;
  v2->need_context_rows = 0;
  downsample = (my_downsampler *)v2;
  if ( HIBYTE(cinfo[7].progress) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 12);
    cinfoa = (jpeg_compress_struct *)v3;
    v4 = v2 + 1;
    do
    {
      v5 = *(v3 - 1);
      err = (int)cinfo[9].err;
      if ( v5 == err && (jpeg_memory_mgr *)*v3 == cinfo[9].mem )
      {
        if ( cinfo[7].client_data != nullptr )
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_smooth_downsample;
          downsample->pub.need_context_rows = 1;
        }
        else
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_downsample;
        }
      }
      else
      {
        if ( 2 * v5 != err )
          goto LABEL_18;
        v7 = (jpeg_memory_mgr *)*v3 == cinfo[9].mem;
        v3 = (int *)cinfoa;
        if ( v7 )
        {
          smoothok = 0;
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v1_downsample;
        }
        else
        {
          if ( 2 * v5 != err || (jpeg_memory_mgr *)(2 * (int)cinfoa->err) != cinfo[9].mem )
          {
LABEL_18:
            if ( err % v5 != 0 || (int)cinfo[9].mem % *v3 != 0 )
            {
              cinfo->err->msg_code = 38;
              cinfo->err->error_exit(a1: cinfo);
            }
            else
            {
              smoothok = 0;
              v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))int_downsample;
            }
            goto LABEL_22;
          }
          if ( cinfo[7].client_data != nullptr )
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_smooth_downsample;
            downsample->pub.need_context_rows = 1;
          }
          else
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_downsample;
          }
        }
      }
LABEL_22:
      v3 += 21;
      v4 = (jpeg_downsampler *)((char *)v4 + 4);
      ++ci;
      cinfoa = (jpeg_compress_struct *)v3;
    }
    while ( ci < (int)cinfo[2].client_data );
  }
  if ( cinfo[7].client_data != nullptr && smoothok == 0 )
  {
    cinfo->err->msg_code = 99;
    cinfo->err->emit_message(a1: cinfo, a2: 0);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10256E20
// Name: expand_right_edge
// Source: json
//------------------------------------------------------------------------------
void __usercall expand_right_edge(
        unsigned int output_cols@<eax>,
        unsigned __int8 **image_data,
        int num_rows,
        unsigned int input_cols)
{
  unsigned int v4; // edi
  int i; // esi

  v4 = output_cols - input_cols;
  if ( (int)(output_cols - input_cols) > 0 )
  {
    for ( i = 0; i < num_rows; ++i )
      memset(dst: &image_data[i][input_cols], value: image_data[i][input_cols - 1], count: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256E70
// Name: sep_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_downsample(
        jpeg_compress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_index,
        unsigned __int8 ***output_buf,
        unsigned int out_row_group_index)
{
  jpeg_component_info *comp_info; // edi
  unsigned __int8 ***v7; // esi
  int i; // eax
  int ci; // [esp+10h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    cinfoa = (jpeg_compress_struct *)&cinfo->downsample[1];
    v7 = input_buf;
    for ( i = (char *)output_buf - (char *)input_buf; ; i = (char *)output_buf - (char *)input_buf )
    {
      ((void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, unsigned __int8 **))cinfoa->err)(
        a1: cinfo,
        a2: comp_info,
        a3: &(*v7)[in_row_index],
        a4: &(*(unsigned __int8 ***)((char *)v7 + i))[out_row_group_index * comp_info->v_samp_factor]);
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      ++v7;
      ++comp_info;
      if ( ++ci >= cinfo->num_components )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256F00
// Name: int_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  unsigned int v13; // ecx
  bool v14; // zf
  int numpix; // [esp+Ch] [ebp-30h]
  int numpix2; // [esp+10h] [ebp-2Ch]
  int h_expand; // [esp+14h] [ebp-28h]
  unsigned int output_cols; // [esp+18h] [ebp-24h]
  int outrowa; // [esp+1Ch] [ebp-20h]
  int outrow; // [esp+1Ch] [ebp-20h]
  int v_expand; // [esp+20h] [ebp-1Ch]
  unsigned int v22; // [esp+24h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+28h] [ebp-14h]
  int v24; // [esp+2Ch] [ebp-10h]
  int outvalue; // [esp+30h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+34h] [ebp-8h]
  unsigned int outcol_h; // [esp+38h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+44h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  v4 = cinfo->max_h_samp_factor / compptr->h_samp_factor;
  outrowa = cinfo->max_v_samp_factor;
  h_expand = v4;
  v5 = v4 * (outrowa / compptr->v_samp_factor);
  v_expand = outrowa / compptr->v_samp_factor;
  v6 = v5 / 2;
  numpix = v5;
  numpix2 = v5 / 2;
  expand_right_edge(
    output_cols: output_cols * v4,
    image_data: input_data,
    num_rows: outrowa,
    input_cols: cinfo->image_width);
  v7 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v26 = input_data;
    do
    {
      outptr = output_data[v7];
      outcol_h = 0;
      if ( output_cols != 0 )
      {
        v22 = output_cols;
        do
        {
          v8 = 0;
          outvalue = 0;
          if ( v_expand > 0 )
          {
            cinfoa = (jpeg_compress_struct *)v26;
            v24 = v_expand;
            do
            {
              v9 = (unsigned __int8 *)cinfoa->err + outcol_h;
              v10 = 0;
              v11 = 0;
              v12 = 0;
              if ( v4 >= 2 )
              {
                v13 = ((unsigned int)(v4 - 2) >> 1) + 1;
                v12 = 2 * v13;
                do
                {
                  v10 += *v9;
                  v11 += v9[1];
                  v9 += 2;
                  --v13;
                }
                while ( v13 != 0 );
                v4 = h_expand;
                v8 = outvalue;
              }
              if ( v12 < v4 )
                v8 += *v9;
              cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
              v8 += v10 + v11;
              v14 = v24-- == 1;
              outvalue = v8;
            }
            while ( !v14 );
            v6 = numpix2;
            v5 = numpix;
          }
          outcol_h += v4;
          v14 = v22-- == 1;
          *outptr++ = (v8 + v6) / v5;
        }
        while ( !v14 );
        v7 = outrow;
      }
      v26 += v_expand;
      outrow = ++v7;
    }
    while ( v7 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257050
// Name: fullsize_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  jcopy_sample_rows(
    input_array: input_data,
    source_row: 0,
    output_array: output_data,
    dest_row: 0,
    num_rows: cinfo->max_v_samp_factor,
    num_cols: cinfo->image_width);
  expand_right_edge(
    output_cols: 8 * compptr->width_in_blocks,
    image_data: output_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
}

//------------------------------------------------------------------------------
// Address: 0x102570A0
// Name: h2v1_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // edi
  int v5; // ebx
  unsigned __int8 **v6; // edx
  _BYTE *v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // esi
  unsigned int output_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 **v11; // [esp+14h] [ebp-4h]
  int outrow; // [esp+20h] [ebp+8h]

  v4 = 8 * compptr->width_in_blocks;
  output_cols = v4;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = (char *)output_data - (char *)input_data;
    v6 = input_data;
    v11 = input_data;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v6 + v5);
      v8 = *v6;
      v9 = 0;
      if ( v4 != 0 )
      {
        do
        {
          *v7++ = (v9 + v8[1] + *v8) >> 1;
          v9 ^= 1u;
          v8 += 2;
          --v4;
        }
        while ( v4 != 0 );
        v4 = output_cols;
        v6 = v11;
        v5 = (char *)output_data - (char *)input_data;
      }
      ++v6;
      ++outrow;
      v11 = v6;
    }
    while ( outrow < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257140
// Name: h2v2_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // edi
  unsigned __int8 **v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  int v9; // edi
  unsigned int output_cols; // [esp+Ch] [ebp-10h]
  int outrow; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v12; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]
  int bias; // [esp+24h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  v4 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = input_data;
    v12 = input_data;
    do
    {
      v6 = output_data[v4];
      v7 = *v5;
      v8 = v5[1];
      bias = 1;
      if ( output_cols != 0 )
      {
        for ( i = output_cols; i != 0; --i )
        {
          v9 = bias + *v8;
          bias ^= 3u;
          *v6++ = (v7[1] + v8[1] + v9 + *v7) >> 2;
          v7 += 2;
          v8 += 2;
        }
        v4 = outrow;
        v5 = v12;
      }
      ++v4;
      v5 += 2;
      v12 = v5;
      outrow = v4;
    }
    while ( v4 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102571F0
// Name: h2v2_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // esi
  bool v18; // zf
  unsigned int v19; // [esp+Ch] [ebp-2Ch]
  int outrow; // [esp+14h] [ebp-24h]
  unsigned __int8 **v21; // [esp+18h] [ebp-20h]
  unsigned int colctra; // [esp+1Ch] [ebp-1Ch]
  unsigned int colctr; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+20h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+30h] [ebp-8h]
  int memberscale; // [esp+34h] [ebp-4h]
  int neighscale; // [esp+40h] [ebp+8h]
  unsigned __int8 *below_ptr; // [esp+48h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = 0x4000 - 80 * smoothing_factor;
  neighscale = 16 * smoothing_factor;
  v6 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v19 = v4 - 2;
    v7 = input_data - 1;
    v21 = input_data - 1;
    do
    {
      v8 = v7[2];
      v9 = v7[1];
      v10 = output_data[v6];
      v11 = *v7;
      v12 = v7[3];
      colctra = (unsigned int)(v12 + 2);
      v24 = v11 + 2;
      ++v10;
      v13 = neighscale
          * (*v12 + *v11 + v11[2] + 2 * (*v12 + *v11 + *v8 + v11[1] + v12[1] + *v9 + v8[2] + v9[2]) + v12[2])
          + memberscale * (*v8 + *v9 + v8[1] + v9[1])
          + 0x8000;
      v14 = v9 + 2;
      v15 = v8 + 2;
      *(v10 - 1) = BYTE2(v13);
      v16 = (unsigned __int8 *)colctra;
      outptr = v10;
      v17 = v24;
      below_ptr = (unsigned __int8 *)colctra;
      colctr = v19;
      if ( v19 != 0 )
      {
        do
        {
          *outptr = (neighscale
                   * (v16[2]
                    + v17[2]
                    + *(v17 - 1)
                    + *(v16 - 1)
                    + 2 * (v14[2] + *v17 + v15[2] + *v16 + *(v14 - 1) + *(v15 - 1) + v17[1] + v16[1]))
                   + memberscale * (*v14 + *v15 + v14[1] + (unsigned int)v15[1])
                   + 0x8000) >> 16;
          v16 = below_ptr + 2;
          v14 += 2;
          v15 += 2;
          v17 += 2;
          v18 = colctr-- == 1;
          ++outptr;
          below_ptr += 2;
        }
        while ( !v18 );
      }
      *outptr = (neighscale
               * (v16[1]
                + v17[1]
                + *(below_ptr - 1)
                + 2 * (v16[1] + v17[1] + v15[1] + *(v14 - 1) + *(v15 - 1) + v14[1] + *v16 + *v17)
                + *(v17 - 1))
               + memberscale * (v15[1] + v14[1] + *v15 + (unsigned int)*v14)
               + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v21 + 2;
      v21 += 2;
      outrow = v6;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257450
// Name: fullsize_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  _BYTE *v19; // esi
  int v20; // ebx
  int v21; // esi
  bool v22; // zf
  unsigned int v23; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 **v24; // [esp+10h] [ebp-18h]
  int outrow; // [esp+14h] [ebp-14h]
  unsigned int colctr; // [esp+18h] [ebp-10h]
  unsigned __int8 *below_ptr; // [esp+1Ch] [ebp-Ch]
  int memberscale; // [esp+20h] [ebp-8h]
  int neighscale; // [esp+24h] [ebp-4h]
  unsigned __int8 *outptra; // [esp+30h] [ebp+8h]
  unsigned __int8 *outptr; // [esp+30h] [ebp+8h]
  int colsum; // [esp+38h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: v4,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = (128 - smoothing_factor) << 9;
  v6 = 0;
  neighscale = smoothing_factor << 6;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v7 = input_data + 1;
    v23 = v4 - 2;
    v24 = input_data + 1;
    do
    {
      v8 = *(v7 - 2);
      outptra = output_data[v6];
      v9 = *(v7 - 1);
      v10 = *v7;
      v11 = *v9;
      v12 = v11 + *v10 + *v8;
      v13 = v8[1];
      below_ptr = v10 + 1;
      v14 = v8 + 1;
      v15 = v13 + v10[1];
      v16 = v9[1];
      v17 = v9 + 1;
      v18 = v16 + v15;
      *outptra = (unsigned int)(neighscale * (v18 + 2 * v12 - v11) + memberscale * v11 + 0x8000) >> 16;
      v19 = outptra + 1;
      outptr = outptra + 1;
      colsum = v18;
      colctr = v23;
      if ( v23 != 0 )
      {
        do
        {
          v20 = v14[1];
          v21 = *v17;
          ++v14;
          v18 = *++v17 + v20 + *++below_ptr;
          *outptr = (unsigned int)(neighscale * (colsum + v18 + v12 - v21) + memberscale * v21 + 0x8000) >> 16;
          v12 = colsum;
          v19 = outptr + 1;
          v22 = colctr-- == 1;
          ++outptr;
          colsum = v18;
        }
        while ( !v22 );
      }
      *v19 = (neighscale * (v12 + 2 * v18 - *v17) + memberscale * (unsigned int)*v17 + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v24 + 1;
      outrow = v6;
      ++v24;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102575C0
// Name: _jinit_downsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_downsampler(jpeg_common_struct *cinfo)
{
  jpeg_downsampler *v2; // edi
  int *v3; // ebx
  jpeg_downsampler *v4; // edi
  int v5; // ecx
  int err; // eax
  bool v7; // zf
  int ci; // [esp+8h] [ebp-Ch]
  my_downsampler *downsample; // [esp+Ch] [ebp-8h]
  unsigned __int8 smoothok; // [esp+13h] [ebp-1h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  smoothok = 1;
  v2 = (jpeg_downsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 52);
  cinfo[14].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *))CColorBalanceUIPanel::Init;
  v2->downsample = sep_downsample;
  v2->need_context_rows = 0;
  downsample = (my_downsampler *)v2;
  if ( HIBYTE(cinfo[7].progress) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 12);
    cinfoa = (jpeg_compress_struct *)v3;
    v4 = v2 + 1;
    do
    {
      v5 = *(v3 - 1);
      err = (int)cinfo[9].err;
      if ( v5 == err && (jpeg_memory_mgr *)*v3 == cinfo[9].mem )
      {
        if ( cinfo[7].client_data != nullptr )
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_smooth_downsample;
          downsample->pub.need_context_rows = 1;
        }
        else
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_downsample;
        }
      }
      else
      {
        if ( 2 * v5 != err )
          goto LABEL_18;
        v7 = (jpeg_memory_mgr *)*v3 == cinfo[9].mem;
        v3 = (int *)cinfoa;
        if ( v7 )
        {
          smoothok = 0;
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v1_downsample;
        }
        else
        {
          if ( 2 * v5 != err || (jpeg_memory_mgr *)(2 * (int)cinfoa->err) != cinfo[9].mem )
          {
LABEL_18:
            if ( err % v5 != 0 || (int)cinfo[9].mem % *v3 != 0 )
            {
              cinfo->err->msg_code = 38;
              cinfo->err->error_exit(a1: cinfo);
            }
            else
            {
              smoothok = 0;
              v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))int_downsample;
            }
            goto LABEL_22;
          }
          if ( cinfo[7].client_data != nullptr )
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_smooth_downsample;
            downsample->pub.need_context_rows = 1;
          }
          else
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_downsample;
          }
        }
      }
LABEL_22:
      v3 += 21;
      v4 = (jpeg_downsampler *)((char *)v4 + 4);
      ++ci;
      cinfoa = (jpeg_compress_struct *)v3;
    }
    while ( ci < (int)cinfo[2].client_data );
  }
  if ( cinfo[7].client_data != nullptr && smoothok == 0 )
  {
    cinfo->err->msg_code = 99;
    cinfo->err->emit_message(a1: cinfo, a2: 0);
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040B340
// Name: expand_right_edge
// Source: json
//------------------------------------------------------------------------------
void __usercall expand_right_edge(
        unsigned int output_cols@<eax>,
        unsigned __int8 **image_data,
        int num_rows,
        unsigned int input_cols)
{
  unsigned int v4; // edi
  int i; // esi

  v4 = output_cols - input_cols;
  if ( (int)(output_cols - input_cols) > 0 )
  {
    for ( i = 0; i < num_rows; ++i )
      memset(dst: &image_data[i][input_cols], value: image_data[i][input_cols - 1], count: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B390
// Name: sep_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_downsample(
        jpeg_compress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_index,
        unsigned __int8 ***output_buf,
        unsigned int out_row_group_index)
{
  jpeg_component_info *comp_info; // edi
  unsigned __int8 ***v7; // esi
  int i; // eax
  int ci; // [esp+10h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    cinfoa = (jpeg_compress_struct *)&cinfo->downsample[1];
    v7 = input_buf;
    for ( i = (char *)output_buf - (char *)input_buf; ; i = (char *)output_buf - (char *)input_buf )
    {
      ((void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, unsigned __int8 **))cinfoa->err)(
        a1: cinfo,
        a2: comp_info,
        a3: &(*v7)[in_row_index],
        a4: &(*(unsigned __int8 ***)((char *)v7 + i))[out_row_group_index * comp_info->v_samp_factor]);
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      ++v7;
      ++comp_info;
      if ( ++ci >= cinfo->num_components )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B420
// Name: int_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  unsigned int v13; // ecx
  bool v14; // zf
  int numpix; // [esp+Ch] [ebp-30h]
  int numpix2; // [esp+10h] [ebp-2Ch]
  int h_expand; // [esp+14h] [ebp-28h]
  unsigned int output_cols; // [esp+18h] [ebp-24h]
  int outrowa; // [esp+1Ch] [ebp-20h]
  int outrow; // [esp+1Ch] [ebp-20h]
  int v_expand; // [esp+20h] [ebp-1Ch]
  unsigned int v22; // [esp+24h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+28h] [ebp-14h]
  int v24; // [esp+2Ch] [ebp-10h]
  int outvalue; // [esp+30h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+34h] [ebp-8h]
  unsigned int outcol_h; // [esp+38h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+44h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  v4 = cinfo->max_h_samp_factor / compptr->h_samp_factor;
  outrowa = cinfo->max_v_samp_factor;
  h_expand = v4;
  v5 = v4 * (outrowa / compptr->v_samp_factor);
  v_expand = outrowa / compptr->v_samp_factor;
  v6 = v5 / 2;
  numpix = v5;
  numpix2 = v5 / 2;
  expand_right_edge(
    output_cols: output_cols * v4,
    image_data: input_data,
    num_rows: outrowa,
    input_cols: cinfo->image_width);
  v7 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v26 = input_data;
    do
    {
      outptr = output_data[v7];
      outcol_h = 0;
      if ( output_cols != 0 )
      {
        v22 = output_cols;
        do
        {
          v8 = 0;
          outvalue = 0;
          if ( v_expand > 0 )
          {
            cinfoa = (jpeg_compress_struct *)v26;
            v24 = v_expand;
            do
            {
              v9 = (unsigned __int8 *)cinfoa->err + outcol_h;
              v10 = 0;
              v11 = 0;
              v12 = 0;
              if ( v4 >= 2 )
              {
                v13 = ((unsigned int)(v4 - 2) >> 1) + 1;
                v12 = 2 * v13;
                do
                {
                  v10 += *v9;
                  v11 += v9[1];
                  v9 += 2;
                  --v13;
                }
                while ( v13 != 0 );
                v4 = h_expand;
                v8 = outvalue;
              }
              if ( v12 < v4 )
                v8 += *v9;
              cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
              v8 += v10 + v11;
              v14 = v24-- == 1;
              outvalue = v8;
            }
            while ( !v14 );
            v6 = numpix2;
            v5 = numpix;
          }
          outcol_h += v4;
          v14 = v22-- == 1;
          *outptr++ = (v8 + v6) / v5;
        }
        while ( !v14 );
        v7 = outrow;
      }
      v26 += v_expand;
      outrow = ++v7;
    }
    while ( v7 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B570
// Name: fullsize_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  jcopy_sample_rows(
    input_array: input_data,
    source_row: 0,
    output_array: output_data,
    dest_row: 0,
    num_rows: cinfo->max_v_samp_factor,
    num_cols: cinfo->image_width);
  expand_right_edge(
    output_cols: 8 * compptr->width_in_blocks,
    image_data: output_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
}

//------------------------------------------------------------------------------
// Address: 0x0040B5C0
// Name: h2v1_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // edi
  int v5; // ebx
  unsigned __int8 **v6; // edx
  _BYTE *v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // esi
  unsigned int output_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 **v11; // [esp+14h] [ebp-4h]
  int outrow; // [esp+20h] [ebp+8h]

  v4 = 8 * compptr->width_in_blocks;
  output_cols = v4;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = (char *)output_data - (char *)input_data;
    v6 = input_data;
    v11 = input_data;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v6 + v5);
      v8 = *v6;
      v9 = 0;
      if ( v4 != 0 )
      {
        do
        {
          *v7++ = (v9 + v8[1] + *v8) >> 1;
          v9 ^= 1u;
          v8 += 2;
          --v4;
        }
        while ( v4 != 0 );
        v4 = output_cols;
        v6 = v11;
        v5 = (char *)output_data - (char *)input_data;
      }
      ++v6;
      ++outrow;
      v11 = v6;
    }
    while ( outrow < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B660
// Name: h2v2_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // edi
  unsigned __int8 **v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  int v9; // edi
  unsigned int output_cols; // [esp+Ch] [ebp-10h]
  int outrow; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v12; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]
  int bias; // [esp+24h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  v4 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = input_data;
    v12 = input_data;
    do
    {
      v6 = output_data[v4];
      v7 = *v5;
      v8 = v5[1];
      bias = 1;
      if ( output_cols != 0 )
      {
        for ( i = output_cols; i != 0; --i )
        {
          v9 = bias + *v8;
          bias ^= 3u;
          *v6++ = (v7[1] + v8[1] + v9 + *v7) >> 2;
          v7 += 2;
          v8 += 2;
        }
        v4 = outrow;
        v5 = v12;
      }
      ++v4;
      v5 += 2;
      v12 = v5;
      outrow = v4;
    }
    while ( v4 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B710
// Name: h2v2_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // esi
  bool v18; // zf
  unsigned int v19; // [esp+Ch] [ebp-2Ch]
  int outrow; // [esp+14h] [ebp-24h]
  unsigned __int8 **v21; // [esp+18h] [ebp-20h]
  unsigned int colctra; // [esp+1Ch] [ebp-1Ch]
  unsigned int colctr; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+20h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+30h] [ebp-8h]
  int memberscale; // [esp+34h] [ebp-4h]
  int neighscale; // [esp+40h] [ebp+8h]
  unsigned __int8 *below_ptr; // [esp+48h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = 0x4000 - 80 * smoothing_factor;
  neighscale = 16 * smoothing_factor;
  v6 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v19 = v4 - 2;
    v7 = input_data - 1;
    v21 = input_data - 1;
    do
    {
      v8 = v7[2];
      v9 = v7[1];
      v10 = output_data[v6];
      v11 = *v7;
      v12 = v7[3];
      colctra = (unsigned int)(v12 + 2);
      v24 = v11 + 2;
      ++v10;
      v13 = neighscale
          * (*v12 + *v11 + v11[2] + 2 * (*v12 + *v11 + *v8 + v11[1] + v12[1] + *v9 + v8[2] + v9[2]) + v12[2])
          + memberscale * (*v8 + *v9 + v8[1] + v9[1])
          + 0x8000;
      v14 = v9 + 2;
      v15 = v8 + 2;
      *(v10 - 1) = BYTE2(v13);
      v16 = (unsigned __int8 *)colctra;
      outptr = v10;
      v17 = v24;
      below_ptr = (unsigned __int8 *)colctra;
      colctr = v19;
      if ( v19 != 0 )
      {
        do
        {
          *outptr = (neighscale
                   * (v16[2]
                    + v17[2]
                    + *(v17 - 1)
                    + *(v16 - 1)
                    + 2 * (v14[2] + *v17 + v15[2] + *v16 + *(v14 - 1) + *(v15 - 1) + v17[1] + v16[1]))
                   + memberscale * (*v14 + *v15 + v14[1] + (unsigned int)v15[1])
                   + 0x8000) >> 16;
          v16 = below_ptr + 2;
          v14 += 2;
          v15 += 2;
          v17 += 2;
          v18 = colctr-- == 1;
          ++outptr;
          below_ptr += 2;
        }
        while ( !v18 );
      }
      *outptr = (neighscale
               * (v16[1]
                + v17[1]
                + *(below_ptr - 1)
                + 2 * (v16[1] + v17[1] + v15[1] + *(v14 - 1) + *(v15 - 1) + v14[1] + *v16 + *v17)
                + *(v17 - 1))
               + memberscale * (v15[1] + v14[1] + *v15 + (unsigned int)*v14)
               + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v21 + 2;
      v21 += 2;
      outrow = v6;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B970
// Name: fullsize_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  _BYTE *v19; // esi
  int v20; // ebx
  int v21; // esi
  bool v22; // zf
  unsigned int v23; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 **v24; // [esp+10h] [ebp-18h]
  int outrow; // [esp+14h] [ebp-14h]
  unsigned int colctr; // [esp+18h] [ebp-10h]
  unsigned __int8 *below_ptr; // [esp+1Ch] [ebp-Ch]
  int memberscale; // [esp+20h] [ebp-8h]
  int neighscale; // [esp+24h] [ebp-4h]
  unsigned __int8 *outptra; // [esp+30h] [ebp+8h]
  unsigned __int8 *outptr; // [esp+30h] [ebp+8h]
  int colsum; // [esp+38h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: v4,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = (128 - smoothing_factor) << 9;
  v6 = 0;
  neighscale = smoothing_factor << 6;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v7 = input_data + 1;
    v23 = v4 - 2;
    v24 = input_data + 1;
    do
    {
      v8 = *(v7 - 2);
      outptra = output_data[v6];
      v9 = *(v7 - 1);
      v10 = *v7;
      v11 = *v9;
      v12 = v11 + *v10 + *v8;
      v13 = v8[1];
      below_ptr = v10 + 1;
      v14 = v8 + 1;
      v15 = v13 + v10[1];
      v16 = v9[1];
      v17 = v9 + 1;
      v18 = v16 + v15;
      *outptra = (unsigned int)(neighscale * (v18 + 2 * v12 - v11) + memberscale * v11 + 0x8000) >> 16;
      v19 = outptra + 1;
      outptr = outptra + 1;
      colsum = v18;
      colctr = v23;
      if ( v23 != 0 )
      {
        do
        {
          v20 = v14[1];
          v21 = *v17;
          ++v14;
          v18 = *++v17 + v20 + *++below_ptr;
          *outptr = (unsigned int)(neighscale * (colsum + v18 + v12 - v21) + memberscale * v21 + 0x8000) >> 16;
          v12 = colsum;
          v19 = outptr + 1;
          v22 = colctr-- == 1;
          ++outptr;
          colsum = v18;
        }
        while ( !v22 );
      }
      *v19 = (neighscale * (v12 + 2 * v18 - *v17) + memberscale * (unsigned int)*v17 + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v24 + 1;
      outrow = v6;
      ++v24;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BAE0
// Name: _jinit_downsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_downsampler(jpeg_common_struct *cinfo)
{
  jpeg_downsampler *v2; // edi
  int *v3; // ebx
  jpeg_downsampler *v4; // edi
  int v5; // ecx
  int err; // eax
  bool v7; // zf
  int ci; // [esp+8h] [ebp-Ch]
  my_downsampler *downsample; // [esp+Ch] [ebp-8h]
  unsigned __int8 smoothok; // [esp+13h] [ebp-1h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  smoothok = 1;
  v2 = (jpeg_downsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 52);
  cinfo[14].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_mem_term;
  v2->downsample = sep_downsample;
  v2->need_context_rows = 0;
  downsample = (my_downsampler *)v2;
  if ( HIBYTE(cinfo[7].progress) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 12);
    cinfoa = (jpeg_compress_struct *)v3;
    v4 = v2 + 1;
    do
    {
      v5 = *(v3 - 1);
      err = (int)cinfo[9].err;
      if ( v5 == err && (jpeg_memory_mgr *)*v3 == cinfo[9].mem )
      {
        if ( cinfo[7].client_data != nullptr )
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_smooth_downsample;
          downsample->pub.need_context_rows = 1;
        }
        else
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_downsample;
        }
      }
      else
      {
        if ( 2 * v5 != err )
          goto LABEL_18;
        v7 = (jpeg_memory_mgr *)*v3 == cinfo[9].mem;
        v3 = (int *)cinfoa;
        if ( v7 )
        {
          smoothok = 0;
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v1_downsample;
        }
        else
        {
          if ( 2 * v5 != err || (jpeg_memory_mgr *)(2 * (int)cinfoa->err) != cinfo[9].mem )
          {
LABEL_18:
            if ( err % v5 != 0 || (int)cinfo[9].mem % *v3 != 0 )
            {
              cinfo->err->msg_code = 38;
              cinfo->err->error_exit(a1: cinfo);
            }
            else
            {
              smoothok = 0;
              v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))int_downsample;
            }
            goto LABEL_22;
          }
          if ( cinfo[7].client_data != nullptr )
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_smooth_downsample;
            downsample->pub.need_context_rows = 1;
          }
          else
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_downsample;
          }
        }
      }
LABEL_22:
      v3 += 21;
      v4 = (jpeg_downsampler *)((char *)v4 + 4);
      ++ci;
      cinfoa = (jpeg_compress_struct *)v3;
    }
    while ( ci < (int)cinfo[2].client_data );
  }
  if ( cinfo[7].client_data != nullptr && smoothok == 0 )
  {
    cinfo->err->msg_code = 99;
    cinfo->err->emit_message(a1: cinfo, a2: 0);
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00434650
// Name: expand_right_edge
// Source: json
//------------------------------------------------------------------------------
void __usercall expand_right_edge(
        unsigned int output_cols@<eax>,
        unsigned __int8 **image_data,
        int num_rows,
        unsigned int input_cols)
{
  unsigned int v4; // edi
  int i; // esi

  v4 = output_cols - input_cols;
  if ( (int)(output_cols - input_cols) > 0 )
  {
    for ( i = 0; i < num_rows; ++i )
      memset(dst: &image_data[i][input_cols], value: image_data[i][input_cols - 1], count: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004346A0
// Name: sep_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_downsample(
        jpeg_compress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_index,
        unsigned __int8 ***output_buf,
        unsigned int out_row_group_index)
{
  jpeg_component_info *comp_info; // edi
  unsigned __int8 ***v7; // esi
  int i; // eax
  int ci; // [esp+10h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    cinfoa = (jpeg_compress_struct *)&cinfo->downsample[1];
    v7 = input_buf;
    for ( i = (char *)output_buf - (char *)input_buf; ; i = (char *)output_buf - (char *)input_buf )
    {
      ((void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, unsigned __int8 **))cinfoa->err)(
        a1: cinfo,
        a2: comp_info,
        a3: &(*v7)[in_row_index],
        a4: &(*(unsigned __int8 ***)((char *)v7 + i))[out_row_group_index * comp_info->v_samp_factor]);
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      ++v7;
      ++comp_info;
      if ( ++ci >= cinfo->num_components )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434730
// Name: int_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  unsigned int v13; // ecx
  bool v14; // zf
  int numpix; // [esp+Ch] [ebp-30h]
  int numpix2; // [esp+10h] [ebp-2Ch]
  int h_expand; // [esp+14h] [ebp-28h]
  unsigned int output_cols; // [esp+18h] [ebp-24h]
  int outrowa; // [esp+1Ch] [ebp-20h]
  int outrow; // [esp+1Ch] [ebp-20h]
  int v_expand; // [esp+20h] [ebp-1Ch]
  unsigned int v22; // [esp+24h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+28h] [ebp-14h]
  int v24; // [esp+2Ch] [ebp-10h]
  int outvalue; // [esp+30h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+34h] [ebp-8h]
  unsigned int outcol_h; // [esp+38h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+44h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  v4 = cinfo->max_h_samp_factor / compptr->h_samp_factor;
  outrowa = cinfo->max_v_samp_factor;
  h_expand = v4;
  v5 = v4 * (outrowa / compptr->v_samp_factor);
  v_expand = outrowa / compptr->v_samp_factor;
  v6 = v5 / 2;
  numpix = v5;
  numpix2 = v5 / 2;
  expand_right_edge(
    output_cols: output_cols * v4,
    image_data: input_data,
    num_rows: outrowa,
    input_cols: cinfo->image_width);
  v7 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v26 = input_data;
    do
    {
      outptr = output_data[v7];
      outcol_h = 0;
      if ( output_cols != 0 )
      {
        v22 = output_cols;
        do
        {
          v8 = 0;
          outvalue = 0;
          if ( v_expand > 0 )
          {
            cinfoa = (jpeg_compress_struct *)v26;
            v24 = v_expand;
            do
            {
              v9 = (unsigned __int8 *)cinfoa->err + outcol_h;
              v10 = 0;
              v11 = 0;
              v12 = 0;
              if ( v4 >= 2 )
              {
                v13 = ((unsigned int)(v4 - 2) >> 1) + 1;
                v12 = 2 * v13;
                do
                {
                  v10 += *v9;
                  v11 += v9[1];
                  v9 += 2;
                  --v13;
                }
                while ( v13 != 0 );
                v4 = h_expand;
                v8 = outvalue;
              }
              if ( v12 < v4 )
                v8 += *v9;
              cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
              v8 += v10 + v11;
              v14 = v24-- == 1;
              outvalue = v8;
            }
            while ( !v14 );
            v6 = numpix2;
            v5 = numpix;
          }
          outcol_h += v4;
          v14 = v22-- == 1;
          *outptr++ = (v8 + v6) / v5;
        }
        while ( !v14 );
        v7 = outrow;
      }
      v26 += v_expand;
      outrow = ++v7;
    }
    while ( v7 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434880
// Name: fullsize_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  jcopy_sample_rows(
    input_array: input_data,
    source_row: 0,
    output_array: output_data,
    dest_row: 0,
    num_rows: cinfo->max_v_samp_factor,
    num_cols: cinfo->image_width);
  expand_right_edge(
    output_cols: 8 * compptr->width_in_blocks,
    image_data: output_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
}

//------------------------------------------------------------------------------
// Address: 0x004348D0
// Name: h2v1_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // edi
  int v5; // ebx
  unsigned __int8 **v6; // edx
  _BYTE *v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // esi
  unsigned int output_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 **v11; // [esp+14h] [ebp-4h]
  int outrow; // [esp+20h] [ebp+8h]

  v4 = 8 * compptr->width_in_blocks;
  output_cols = v4;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = (char *)output_data - (char *)input_data;
    v6 = input_data;
    v11 = input_data;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v6 + v5);
      v8 = *v6;
      v9 = 0;
      if ( v4 != 0 )
      {
        do
        {
          *v7++ = (v9 + v8[1] + *v8) >> 1;
          v9 ^= 1u;
          v8 += 2;
          --v4;
        }
        while ( v4 != 0 );
        v4 = output_cols;
        v6 = v11;
        v5 = (char *)output_data - (char *)input_data;
      }
      ++v6;
      ++outrow;
      v11 = v6;
    }
    while ( outrow < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434970
// Name: h2v2_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // edi
  unsigned __int8 **v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  int v9; // edi
  unsigned int output_cols; // [esp+Ch] [ebp-10h]
  int outrow; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v12; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]
  int bias; // [esp+24h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  v4 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = input_data;
    v12 = input_data;
    do
    {
      v6 = output_data[v4];
      v7 = *v5;
      v8 = v5[1];
      bias = 1;
      if ( output_cols != 0 )
      {
        for ( i = output_cols; i != 0; --i )
        {
          v9 = bias + *v8;
          bias ^= 3u;
          *v6++ = (v7[1] + v8[1] + v9 + *v7) >> 2;
          v7 += 2;
          v8 += 2;
        }
        v4 = outrow;
        v5 = v12;
      }
      ++v4;
      v5 += 2;
      v12 = v5;
      outrow = v4;
    }
    while ( v4 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434A20
// Name: h2v2_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // esi
  bool v18; // zf
  unsigned int v19; // [esp+Ch] [ebp-2Ch]
  int outrow; // [esp+14h] [ebp-24h]
  unsigned __int8 **v21; // [esp+18h] [ebp-20h]
  unsigned int colctra; // [esp+1Ch] [ebp-1Ch]
  unsigned int colctr; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+20h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+30h] [ebp-8h]
  int memberscale; // [esp+34h] [ebp-4h]
  int neighscale; // [esp+40h] [ebp+8h]
  unsigned __int8 *below_ptr; // [esp+48h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = 0x4000 - 80 * smoothing_factor;
  neighscale = 16 * smoothing_factor;
  v6 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v19 = v4 - 2;
    v7 = input_data - 1;
    v21 = input_data - 1;
    do
    {
      v8 = v7[2];
      v9 = v7[1];
      v10 = output_data[v6];
      v11 = *v7;
      v12 = v7[3];
      colctra = (unsigned int)(v12 + 2);
      v24 = v11 + 2;
      ++v10;
      v13 = neighscale
          * (*v12 + *v11 + v11[2] + 2 * (*v12 + *v11 + *v8 + v11[1] + v12[1] + *v9 + v8[2] + v9[2]) + v12[2])
          + memberscale * (*v8 + *v9 + v8[1] + v9[1])
          + 0x8000;
      v14 = v9 + 2;
      v15 = v8 + 2;
      *(v10 - 1) = BYTE2(v13);
      v16 = (unsigned __int8 *)colctra;
      outptr = v10;
      v17 = v24;
      below_ptr = (unsigned __int8 *)colctra;
      colctr = v19;
      if ( v19 != 0 )
      {
        do
        {
          *outptr = (neighscale
                   * (v16[2]
                    + v17[2]
                    + *(v17 - 1)
                    + *(v16 - 1)
                    + 2 * (v14[2] + *v17 + v15[2] + *v16 + *(v14 - 1) + *(v15 - 1) + v17[1] + v16[1]))
                   + memberscale * (*v14 + *v15 + v14[1] + (unsigned int)v15[1])
                   + 0x8000) >> 16;
          v16 = below_ptr + 2;
          v14 += 2;
          v15 += 2;
          v17 += 2;
          v18 = colctr-- == 1;
          ++outptr;
          below_ptr += 2;
        }
        while ( !v18 );
      }
      *outptr = (neighscale
               * (v16[1]
                + v17[1]
                + *(below_ptr - 1)
                + 2 * (v16[1] + v17[1] + v15[1] + *(v14 - 1) + *(v15 - 1) + v14[1] + *v16 + *v17)
                + *(v17 - 1))
               + memberscale * (v15[1] + v14[1] + *v15 + (unsigned int)*v14)
               + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v21 + 2;
      v21 += 2;
      outrow = v6;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434C80
// Name: fullsize_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  _BYTE *v19; // esi
  int v20; // ebx
  int v21; // esi
  bool v22; // zf
  unsigned int v23; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 **v24; // [esp+10h] [ebp-18h]
  int outrow; // [esp+14h] [ebp-14h]
  unsigned int colctr; // [esp+18h] [ebp-10h]
  unsigned __int8 *below_ptr; // [esp+1Ch] [ebp-Ch]
  int memberscale; // [esp+20h] [ebp-8h]
  int neighscale; // [esp+24h] [ebp-4h]
  unsigned __int8 *outptra; // [esp+30h] [ebp+8h]
  unsigned __int8 *outptr; // [esp+30h] [ebp+8h]
  int colsum; // [esp+38h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: v4,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = (128 - smoothing_factor) << 9;
  v6 = 0;
  neighscale = smoothing_factor << 6;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v7 = input_data + 1;
    v23 = v4 - 2;
    v24 = input_data + 1;
    do
    {
      v8 = *(v7 - 2);
      outptra = output_data[v6];
      v9 = *(v7 - 1);
      v10 = *v7;
      v11 = *v9;
      v12 = v11 + *v10 + *v8;
      v13 = v8[1];
      below_ptr = v10 + 1;
      v14 = v8 + 1;
      v15 = v13 + v10[1];
      v16 = v9[1];
      v17 = v9 + 1;
      v18 = v16 + v15;
      *outptra = (unsigned int)(neighscale * (v18 + 2 * v12 - v11) + memberscale * v11 + 0x8000) >> 16;
      v19 = outptra + 1;
      outptr = outptra + 1;
      colsum = v18;
      colctr = v23;
      if ( v23 != 0 )
      {
        do
        {
          v20 = v14[1];
          v21 = *v17;
          ++v14;
          v18 = *++v17 + v20 + *++below_ptr;
          *outptr = (unsigned int)(neighscale * (colsum + v18 + v12 - v21) + memberscale * v21 + 0x8000) >> 16;
          v12 = colsum;
          v19 = outptr + 1;
          v22 = colctr-- == 1;
          ++outptr;
          colsum = v18;
        }
        while ( !v22 );
      }
      *v19 = (neighscale * (v12 + 2 * v18 - *v17) + memberscale * (unsigned int)*v17 + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v24 + 1;
      outrow = v6;
      ++v24;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434DF0
// Name: _jinit_downsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_downsampler(jpeg_common_struct *cinfo)
{
  jpeg_downsampler *v2; // edi
  int *v3; // ebx
  jpeg_downsampler *v4; // edi
  int v5; // ecx
  int err; // eax
  bool v7; // zf
  int ci; // [esp+8h] [ebp-Ch]
  my_downsampler *downsample; // [esp+Ch] [ebp-8h]
  unsigned __int8 smoothok; // [esp+13h] [ebp-1h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  smoothok = 1;
  v2 = (jpeg_downsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 52);
  cinfo[14].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_mem_term;
  v2->downsample = sep_downsample;
  v2->need_context_rows = 0;
  downsample = (my_downsampler *)v2;
  if ( HIBYTE(cinfo[7].progress) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 12);
    cinfoa = (jpeg_compress_struct *)v3;
    v4 = v2 + 1;
    do
    {
      v5 = *(v3 - 1);
      err = (int)cinfo[9].err;
      if ( v5 == err && (jpeg_memory_mgr *)*v3 == cinfo[9].mem )
      {
        if ( cinfo[7].client_data != nullptr )
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_smooth_downsample;
          downsample->pub.need_context_rows = 1;
        }
        else
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_downsample;
        }
      }
      else
      {
        if ( 2 * v5 != err )
          goto LABEL_18;
        v7 = (jpeg_memory_mgr *)*v3 == cinfo[9].mem;
        v3 = (int *)cinfoa;
        if ( v7 )
        {
          smoothok = 0;
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v1_downsample;
        }
        else
        {
          if ( 2 * v5 != err || (jpeg_memory_mgr *)(2 * (int)cinfoa->err) != cinfo[9].mem )
          {
LABEL_18:
            if ( err % v5 != 0 || (int)cinfo[9].mem % *v3 != 0 )
            {
              cinfo->err->msg_code = 38;
              cinfo->err->error_exit(a1: cinfo);
            }
            else
            {
              smoothok = 0;
              v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))int_downsample;
            }
            goto LABEL_22;
          }
          if ( cinfo[7].client_data != nullptr )
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_smooth_downsample;
            downsample->pub.need_context_rows = 1;
          }
          else
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_downsample;
          }
        }
      }
LABEL_22:
      v3 += 21;
      v4 = (jpeg_downsampler *)((char *)v4 + 4);
      ++ci;
      cinfoa = (jpeg_compress_struct *)v3;
    }
    while ( ci < (int)cinfo[2].client_data );
  }
  if ( cinfo[7].client_data != nullptr && smoothok == 0 )
  {
    cinfo->err->msg_code = 99;
    cinfo->err->emit_message(a1: cinfo, a2: 0);
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00421460
// Name: expand_right_edge
// Source: json
//------------------------------------------------------------------------------
void __usercall expand_right_edge(
        unsigned int output_cols@<eax>,
        unsigned __int8 **image_data,
        int num_rows,
        unsigned int input_cols)
{
  unsigned int v4; // edi
  int i; // esi

  v4 = output_cols - input_cols;
  if ( (int)(output_cols - input_cols) > 0 )
  {
    for ( i = 0; i < num_rows; ++i )
      memset(dst: &image_data[i][input_cols], value: image_data[i][input_cols - 1], count: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004214B0
// Name: sep_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl sep_downsample(
        jpeg_compress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_index,
        unsigned __int8 ***output_buf,
        unsigned int out_row_group_index)
{
  jpeg_component_info *comp_info; // edi
  unsigned __int8 ***v7; // esi
  int i; // eax
  int ci; // [esp+10h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    cinfoa = (jpeg_compress_struct *)&cinfo->downsample[1];
    v7 = input_buf;
    for ( i = (char *)output_buf - (char *)input_buf; ; i = (char *)output_buf - (char *)input_buf )
    {
      ((void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, unsigned __int8 **))cinfoa->err)(
        a1: cinfo,
        a2: comp_info,
        a3: &(*v7)[in_row_index],
        a4: &(*(unsigned __int8 ***)((char *)v7 + i))[out_row_group_index * comp_info->v_samp_factor]);
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      ++v7;
      ++comp_info;
      if ( ++ci >= cinfo->num_components )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421540
// Name: int_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl int_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  unsigned int v13; // ecx
  bool v14; // zf
  int numpix; // [esp+Ch] [ebp-30h]
  int numpix2; // [esp+10h] [ebp-2Ch]
  int h_expand; // [esp+14h] [ebp-28h]
  unsigned int output_cols; // [esp+18h] [ebp-24h]
  int outrowa; // [esp+1Ch] [ebp-20h]
  int outrow; // [esp+1Ch] [ebp-20h]
  int v_expand; // [esp+20h] [ebp-1Ch]
  unsigned int v22; // [esp+24h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+28h] [ebp-14h]
  int v24; // [esp+2Ch] [ebp-10h]
  int outvalue; // [esp+30h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+34h] [ebp-8h]
  unsigned int outcol_h; // [esp+38h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+44h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  v4 = cinfo->max_h_samp_factor / compptr->h_samp_factor;
  outrowa = cinfo->max_v_samp_factor;
  h_expand = v4;
  v5 = v4 * (outrowa / compptr->v_samp_factor);
  v_expand = outrowa / compptr->v_samp_factor;
  v6 = v5 / 2;
  numpix = v5;
  numpix2 = v5 / 2;
  expand_right_edge(
    output_cols: output_cols * v4,
    image_data: input_data,
    num_rows: outrowa,
    input_cols: cinfo->image_width);
  v7 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v26 = input_data;
    do
    {
      outptr = output_data[v7];
      outcol_h = 0;
      if ( output_cols != 0 )
      {
        v22 = output_cols;
        do
        {
          v8 = 0;
          outvalue = 0;
          if ( v_expand > 0 )
          {
            cinfoa = (jpeg_compress_struct *)v26;
            v24 = v_expand;
            do
            {
              v9 = (unsigned __int8 *)cinfoa->err + outcol_h;
              v10 = 0;
              v11 = 0;
              v12 = 0;
              if ( v4 >= 2 )
              {
                v13 = ((unsigned int)(v4 - 2) >> 1) + 1;
                v12 = 2 * v13;
                do
                {
                  v10 += *v9;
                  v11 += v9[1];
                  v9 += 2;
                  --v13;
                }
                while ( v13 != 0 );
                v4 = h_expand;
                v8 = outvalue;
              }
              if ( v12 < v4 )
                v8 += *v9;
              cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
              v8 += v10 + v11;
              v14 = v24-- == 1;
              outvalue = v8;
            }
            while ( !v14 );
            v6 = numpix2;
            v5 = numpix;
          }
          outcol_h += v4;
          v14 = v22-- == 1;
          *outptr++ = (v8 + v6) / v5;
        }
        while ( !v14 );
        v7 = outrow;
      }
      v26 += v_expand;
      outrow = ++v7;
    }
    while ( v7 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421690
// Name: fullsize_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  jcopy_sample_rows(
    input_array: input_data,
    source_row: 0,
    output_array: output_data,
    dest_row: 0,
    num_rows: cinfo->max_v_samp_factor,
    num_cols: cinfo->image_width);
  expand_right_edge(
    output_cols: 8 * compptr->width_in_blocks,
    image_data: output_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
}

//------------------------------------------------------------------------------
// Address: 0x004216E0
// Name: h2v1_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // edi
  int v5; // ebx
  unsigned __int8 **v6; // edx
  _BYTE *v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // esi
  unsigned int output_cols; // [esp+10h] [ebp-8h]
  unsigned __int8 **v11; // [esp+14h] [ebp-4h]
  int outrow; // [esp+20h] [ebp+8h]

  v4 = 8 * compptr->width_in_blocks;
  output_cols = v4;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = (char *)output_data - (char *)input_data;
    v6 = input_data;
    v11 = input_data;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v6 + v5);
      v8 = *v6;
      v9 = 0;
      if ( v4 != 0 )
      {
        do
        {
          *v7++ = (v9 + v8[1] + *v8) >> 1;
          v9 ^= 1u;
          v8 += 2;
          --v4;
        }
        while ( v4 != 0 );
        v4 = output_cols;
        v6 = v11;
        v5 = (char *)output_data - (char *)input_data;
      }
      ++v6;
      ++outrow;
      v11 = v6;
    }
    while ( outrow < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421780
// Name: h2v2_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  int v4; // edi
  unsigned __int8 **v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  int v9; // edi
  unsigned int output_cols; // [esp+Ch] [ebp-10h]
  int outrow; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v12; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]
  int bias; // [esp+24h] [ebp+8h]

  output_cols = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data,
    num_rows: cinfo->max_v_samp_factor,
    input_cols: cinfo->image_width);
  v4 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v5 = input_data;
    v12 = input_data;
    do
    {
      v6 = output_data[v4];
      v7 = *v5;
      v8 = v5[1];
      bias = 1;
      if ( output_cols != 0 )
      {
        for ( i = output_cols; i != 0; --i )
        {
          v9 = bias + *v8;
          bias ^= 3u;
          *v6++ = (v7[1] + v8[1] + v9 + *v7) >> 2;
          v7 += 2;
          v8 += 2;
        }
        v4 = outrow;
        v5 = v12;
      }
      ++v4;
      v5 += 2;
      v12 = v5;
      outrow = v4;
    }
    while ( v4 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421830
// Name: h2v2_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // esi
  bool v18; // zf
  unsigned int v19; // [esp+Ch] [ebp-2Ch]
  int outrow; // [esp+14h] [ebp-24h]
  unsigned __int8 **v21; // [esp+18h] [ebp-20h]
  unsigned int colctra; // [esp+1Ch] [ebp-1Ch]
  unsigned int colctr; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+20h] [ebp-18h]
  unsigned __int8 *outptr; // [esp+30h] [ebp-8h]
  int memberscale; // [esp+34h] [ebp-4h]
  int neighscale; // [esp+40h] [ebp+8h]
  unsigned __int8 *below_ptr; // [esp+48h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: 16 * compptr->width_in_blocks,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = 0x4000 - 80 * smoothing_factor;
  neighscale = 16 * smoothing_factor;
  v6 = 0;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v19 = v4 - 2;
    v7 = input_data - 1;
    v21 = input_data - 1;
    do
    {
      v8 = v7[2];
      v9 = v7[1];
      v10 = output_data[v6];
      v11 = *v7;
      v12 = v7[3];
      colctra = (unsigned int)(v12 + 2);
      v24 = v11 + 2;
      ++v10;
      v13 = neighscale
          * (*v12 + *v11 + v11[2] + 2 * (*v12 + *v11 + *v8 + v11[1] + v12[1] + *v9 + v8[2] + v9[2]) + v12[2])
          + memberscale * (*v8 + *v9 + v8[1] + v9[1])
          + 0x8000;
      v14 = v9 + 2;
      v15 = v8 + 2;
      *(v10 - 1) = BYTE2(v13);
      v16 = (unsigned __int8 *)colctra;
      outptr = v10;
      v17 = v24;
      below_ptr = (unsigned __int8 *)colctra;
      colctr = v19;
      if ( v19 != 0 )
      {
        do
        {
          *outptr = (neighscale
                   * (v16[2]
                    + v17[2]
                    + *(v17 - 1)
                    + *(v16 - 1)
                    + 2 * (v14[2] + *v17 + v15[2] + *v16 + *(v14 - 1) + *(v15 - 1) + v17[1] + v16[1]))
                   + memberscale * (*v14 + *v15 + v14[1] + (unsigned int)v15[1])
                   + 0x8000) >> 16;
          v16 = below_ptr + 2;
          v14 += 2;
          v15 += 2;
          v17 += 2;
          v18 = colctr-- == 1;
          ++outptr;
          below_ptr += 2;
        }
        while ( !v18 );
      }
      *outptr = (neighscale
               * (v16[1]
                + v17[1]
                + *(below_ptr - 1)
                + 2 * (v16[1] + v17[1] + v15[1] + *(v14 - 1) + *(v15 - 1) + v14[1] + *v16 + *v17)
                + *(v17 - 1))
               + memberscale * (v15[1] + v14[1] + *v15 + (unsigned int)*v14)
               + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v21 + 2;
      v21 += 2;
      outrow = v6;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421A90
// Name: fullsize_smooth_downsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl fullsize_smooth_downsample(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 **output_data)
{
  unsigned int v4; // esi
  int smoothing_factor; // eax
  int v6; // ecx
  unsigned __int8 **v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  _BYTE *v19; // esi
  int v20; // ebx
  int v21; // esi
  bool v22; // zf
  unsigned int v23; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 **v24; // [esp+10h] [ebp-18h]
  int outrow; // [esp+14h] [ebp-14h]
  unsigned int colctr; // [esp+18h] [ebp-10h]
  unsigned __int8 *below_ptr; // [esp+1Ch] [ebp-Ch]
  int memberscale; // [esp+20h] [ebp-8h]
  int neighscale; // [esp+24h] [ebp-4h]
  unsigned __int8 *outptra; // [esp+30h] [ebp+8h]
  unsigned __int8 *outptr; // [esp+30h] [ebp+8h]
  int colsum; // [esp+38h] [ebp+10h]

  v4 = 8 * compptr->width_in_blocks;
  expand_right_edge(
    output_cols: v4,
    image_data: input_data - 1,
    num_rows: cinfo->max_v_samp_factor + 2,
    input_cols: cinfo->image_width);
  smoothing_factor = cinfo->smoothing_factor;
  memberscale = (128 - smoothing_factor) << 9;
  v6 = 0;
  neighscale = smoothing_factor << 6;
  outrow = 0;
  if ( compptr->v_samp_factor > 0 )
  {
    v7 = input_data + 1;
    v23 = v4 - 2;
    v24 = input_data + 1;
    do
    {
      v8 = *(v7 - 2);
      outptra = output_data[v6];
      v9 = *(v7 - 1);
      v10 = *v7;
      v11 = *v9;
      v12 = v11 + *v10 + *v8;
      v13 = v8[1];
      below_ptr = v10 + 1;
      v14 = v8 + 1;
      v15 = v13 + v10[1];
      v16 = v9[1];
      v17 = v9 + 1;
      v18 = v16 + v15;
      *outptra = (unsigned int)(neighscale * (v18 + 2 * v12 - v11) + memberscale * v11 + 0x8000) >> 16;
      v19 = outptra + 1;
      outptr = outptra + 1;
      colsum = v18;
      colctr = v23;
      if ( v23 != 0 )
      {
        do
        {
          v20 = v14[1];
          v21 = *v17;
          ++v14;
          v18 = *++v17 + v20 + *++below_ptr;
          *outptr = (unsigned int)(neighscale * (colsum + v18 + v12 - v21) + memberscale * v21 + 0x8000) >> 16;
          v12 = colsum;
          v19 = outptr + 1;
          v22 = colctr-- == 1;
          ++outptr;
          colsum = v18;
        }
        while ( !v22 );
      }
      *v19 = (neighscale * (v12 + 2 * v18 - *v17) + memberscale * (unsigned int)*v17 + 0x8000) >> 16;
      v6 = outrow + 1;
      v7 = v24 + 1;
      outrow = v6;
      ++v24;
    }
    while ( v6 < compptr->v_samp_factor );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C00
// Name: _jinit_downsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_downsampler(jpeg_common_struct *cinfo)
{
  jpeg_downsampler *v2; // edi
  int *v3; // ebx
  jpeg_downsampler *v4; // edi
  int v5; // ecx
  int err; // eax
  bool v7; // zf
  int ci; // [esp+8h] [ebp-Ch]
  my_downsampler *downsample; // [esp+Ch] [ebp-8h]
  unsigned __int8 smoothok; // [esp+13h] [ebp-1h]
  jpeg_compress_struct *cinfoa; // [esp+1Ch] [ebp+8h]

  smoothok = 1;
  v2 = (jpeg_downsampler *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 52);
  cinfo[14].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_mem_term;
  v2->downsample = sep_downsample;
  v2->need_context_rows = 0;
  downsample = (my_downsampler *)v2;
  if ( HIBYTE(cinfo[7].progress) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 12);
    cinfoa = (jpeg_compress_struct *)v3;
    v4 = v2 + 1;
    do
    {
      v5 = *(v3 - 1);
      err = (int)cinfo[9].err;
      if ( v5 == err && (jpeg_memory_mgr *)*v3 == cinfo[9].mem )
      {
        if ( cinfo[7].client_data != nullptr )
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_smooth_downsample;
          downsample->pub.need_context_rows = 1;
        }
        else
        {
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))fullsize_downsample;
        }
      }
      else
      {
        if ( 2 * v5 != err )
          goto LABEL_18;
        v7 = (jpeg_memory_mgr *)*v3 == cinfo[9].mem;
        v3 = (int *)cinfoa;
        if ( v7 )
        {
          smoothok = 0;
          v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v1_downsample;
        }
        else
        {
          if ( 2 * v5 != err || (jpeg_memory_mgr *)(2 * (int)cinfoa->err) != cinfo[9].mem )
          {
LABEL_18:
            if ( err % v5 != 0 || (int)cinfo[9].mem % *v3 != 0 )
            {
              cinfo->err->msg_code = 38;
              cinfo->err->error_exit(a1: cinfo);
            }
            else
            {
              smoothok = 0;
              v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))int_downsample;
            }
            goto LABEL_22;
          }
          if ( cinfo[7].client_data != nullptr )
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_smooth_downsample;
            downsample->pub.need_context_rows = 1;
          }
          else
          {
            v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *))h2v2_downsample;
          }
        }
      }
LABEL_22:
      v3 += 21;
      v4 = (jpeg_downsampler *)((char *)v4 + 4);
      ++ci;
      cinfoa = (jpeg_compress_struct *)v3;
    }
    while ( ci < (int)cinfo[2].client_data );
  }
  if ( cinfo[7].client_data != nullptr && smoothok == 0 )
  {
    cinfo->err->msg_code = 99;
    cinfo->err->emit_message(a1: cinfo, a2: 0);
  }
}

} // namespace vxconsole_ps3
