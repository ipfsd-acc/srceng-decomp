// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdmerge.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10011020
// Name: start_pass_merged_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_merged_upsample(jpeg_decompress_struct *cinfo)
{
  jpeg_upsampler *upsample; // eax

  upsample = cinfo->upsample;
  LOBYTE(upsample[3].start_pass) = 0;
  *(_DWORD *)&upsample[3].need_context_rows = cinfo->output_height;
}

//------------------------------------------------------------------------------
// Address: 0x10011040
// Name: merged_2v_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl merged_2v_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_upsampler *upsample; // esi
  unsigned int v8; // edi
  int v9; // eax
  unsigned __int8 *work_ptrs[2]; // [esp+Ch] [ebp-8h] BYREF

  upsample = cinfo->upsample;
  if ( LOBYTE(upsample[3].start_pass) != 0 )
  {
    jcopy_sample_rows(
      input_array: (unsigned __int8 **)&upsample[2].need_context_rows,
      source_row: 0,
      output_array: &output_buf[*out_row_ctr],
      dest_row: 0,
      num_rows: 1,
      num_cols: (unsigned int)upsample[3].upsample);
    v8 = 1;
    LOBYTE(upsample[3].start_pass) = 0;
  }
  else
  {
    v8 = 2;
    if ( *(_DWORD *)&upsample[3].need_context_rows < 2u )
      v8 = *(_DWORD *)&upsample[3].need_context_rows;
    v9 = *out_row_ctr;
    if ( v8 > out_rows_avail - *out_row_ctr )
      v8 = out_rows_avail - *out_row_ctr;
    work_ptrs[0] = output_buf[v9];
    if ( v8 <= 1 )
    {
      work_ptrs[1] = *(unsigned __int8 **)&upsample[2].need_context_rows;
      LOBYTE(upsample[3].start_pass) = 1;
    }
    else
    {
      work_ptrs[1] = output_buf[v9 + 1];
    }
    ((void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, _DWORD, unsigned __int8 **))upsample[1].start_pass)(
      a1: cinfo,
      a2: input_buf,
      a3: *in_row_group_ctr,
      a4: work_ptrs);
  }
  *out_row_ctr += v8;
  *(_DWORD *)&upsample[3].need_context_rows -= v8;
  if ( LOBYTE(upsample[3].start_pass) == 0 )
    ++*in_row_group_ctr;
}

//------------------------------------------------------------------------------
// Address: 0x100110F0
// Name: merged_1v_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl merged_1v_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr)
{
  ((void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, _DWORD, unsigned __int8 **))cinfo->upsample[1].start_pass)(
    a1: cinfo,
    a2: input_buf,
    a3: *in_row_group_ctr,
    a4: &output_buf[*out_row_ctr]);
  ++*out_row_ctr;
  ++*in_row_group_ctr;
}

//------------------------------------------------------------------------------
// Address: 0x10011130
// Name: h2v1_merged_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_merged_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        int in_row_group_ctr,
        unsigned __int8 **output_buf)
{
  jpeg_upsampler *upsample; // eax
  unsigned __int8 *sample_range_limit; // ecx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // edx
  unsigned __int8 *v8; // esi
  _BYTE *v9; // eax
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edi
  int v17; // esi
  int *Crrtab; // [esp+Ch] [ebp-18h]
  int *Cbbtab; // [esp+10h] [ebp-14h]
  int *Crgtab; // [esp+14h] [ebp-10h]
  int *Cbgtab; // [esp+18h] [ebp-Ch]
  unsigned __int8 *inptr2; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *inptr1; // [esp+20h] [ebp-4h]
  int cr; // [esp+2Ch] [ebp+8h]
  int cred; // [esp+30h] [ebp+Ch]
  int cblue; // [esp+34h] [ebp+10h]
  int cbluea; // [esp+34h] [ebp+10h]
  unsigned int col; // [esp+38h] [ebp+14h]

  upsample = cinfo->upsample;
  sample_range_limit = cinfo->sample_range_limit;
  Crrtab = (int *)upsample[1].upsample;
  Cbbtab = *(int **)&upsample[1].need_context_rows;
  Crgtab = (int *)upsample[2].start_pass;
  Cbgtab = (int *)upsample[2].upsample;
  v6 = (*input_buf)[in_row_group_ctr];
  v7 = input_buf[1][in_row_group_ctr];
  v8 = input_buf[2][in_row_group_ctr];
  v9 = *output_buf;
  for ( col = cinfo->output_width >> 1; col != 0; --col )
  {
    v10 = *v7;
    inptr1 = v7 + 1;
    v11 = *v8;
    inptr2 = v8 + 1;
    cred = Crrtab[v11];
    v12 = Crgtab[v11] + Cbgtab[v10];
    cblue = Cbbtab[v10];
    v13 = *v6;
    *v9 = sample_range_limit[v13 + cred];
    v12 >>= 16;
    v9[1] = sample_range_limit[v13 + v12];
    v9[2] = sample_range_limit[cblue + v13];
    v14 = v6[1];
    v9[3] = sample_range_limit[v14 + cred];
    LOBYTE(v10) = sample_range_limit[v14 + v12];
    v8 = inptr2;
    v9[4] = v10;
    v9[5] = sample_range_limit[cblue + v14];
    v7 = inptr1;
    v6 += 2;
    v9 += 6;
  }
  if ( (cinfo->output_width & 1) != 0 )
  {
    v15 = *v7;
    v16 = *v6;
    cr = *v8;
    cbluea = Cbbtab[v15];
    v17 = (Crgtab[cr] + Cbgtab[v15]) >> 16;
    *v9 = sample_range_limit[v16 + Crrtab[cr]];
    v9[1] = sample_range_limit[v16 + v17];
    v9[2] = sample_range_limit[cbluea + v16];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011280
// Name: h2v2_merged_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_merged_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        int in_row_group_ctr,
        unsigned __int8 **output_buf)
{
  jpeg_upsampler *upsample; // ecx
  unsigned __int8 *sample_range_limit; // eax
  unsigned __int8 **v6; // edx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edi
  _BYTE *v10; // ecx
  unsigned __int8 *v11; // esi
  int v12; // edx
  int v13; // edi
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  unsigned __int8 v18; // bl
  int v19; // ebx
  int v20; // edx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int *Cbbtab; // [esp+Ch] [ebp-20h]
  int *Crgtab; // [esp+10h] [ebp-1Ch]
  int *Cbgtab; // [esp+14h] [ebp-18h]
  int *Crrtab; // [esp+18h] [ebp-14h]
  unsigned __int8 *inptr1; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *inptr2; // [esp+20h] [ebp-Ch]
  unsigned __int8 *inptr01; // [esp+24h] [ebp-8h]
  unsigned __int8 *inptr00; // [esp+28h] [ebp-4h]
  unsigned __int8 *inptr00a; // [esp+28h] [ebp-4h]
  int cred; // [esp+38h] [ebp+Ch]
  int creda; // [esp+38h] [ebp+Ch]
  int cblue; // [esp+3Ch] [ebp+10h]
  int cbluea; // [esp+3Ch] [ebp+10h]
  int cblueb; // [esp+3Ch] [ebp+10h]
  unsigned int col; // [esp+40h] [ebp+14h]

  upsample = cinfo->upsample;
  sample_range_limit = cinfo->sample_range_limit;
  Crrtab = (int *)upsample[1].upsample;
  Cbbtab = *(int **)&upsample[1].need_context_rows;
  Crgtab = (int *)upsample[2].start_pass;
  Cbgtab = (int *)upsample[2].upsample;
  v6 = &(*input_buf)[2 * in_row_group_ctr];
  v7 = *v6;
  inptr01 = v6[1];
  v8 = input_buf[1][in_row_group_ctr];
  inptr00 = v7;
  v9 = input_buf[2][in_row_group_ctr];
  v10 = *output_buf;
  v11 = output_buf[1];
  for ( col = cinfo->output_width >> 1; col != 0; --col )
  {
    cblue = *v8;
    inptr1 = v8 + 1;
    v12 = *v9;
    inptr2 = v9 + 1;
    cred = Crrtab[v12];
    v13 = Crgtab[v12] + Cbgtab[cblue];
    inptr00a = inptr00 + 1;
    cbluea = Cbbtab[cblue];
    v14 = *(inptr00a - 1);
    *v10 = sample_range_limit[v14 + cred];
    v13 >>= 16;
    v10[1] = sample_range_limit[v14 + v13];
    v10[2] = sample_range_limit[cbluea + v14];
    v15 = *inptr00a;
    inptr00 = inptr00a + 1;
    v10[3] = sample_range_limit[v15 + cred];
    v10[4] = sample_range_limit[v15 + v13];
    v10[5] = sample_range_limit[cbluea + v15];
    v16 = *inptr01;
    *v11 = sample_range_limit[v16 + cred];
    v11[1] = sample_range_limit[v16 + v13];
    v11[2] = sample_range_limit[cbluea + v16];
    v17 = inptr01[1];
    inptr01 += 2;
    v11[3] = sample_range_limit[v17 + cred];
    v18 = sample_range_limit[v17 + v13];
    v9 = inptr2;
    v11[4] = v18;
    v11[5] = sample_range_limit[cbluea + v17];
    v8 = inptr1;
    v10 += 6;
    v11 += 6;
  }
  if ( (cinfo->output_width & 1) != 0 )
  {
    v19 = *v8;
    v20 = *v9;
    creda = Crrtab[v20];
    v21 = Crgtab[v20] + Cbgtab[v19];
    cblueb = Cbbtab[v19];
    v22 = *inptr00;
    *v10 = sample_range_limit[v22 + creda];
    v21 >>= 16;
    v10[1] = sample_range_limit[v22 + v21];
    v10[2] = sample_range_limit[cblueb + v22];
    v23 = *inptr01;
    *v11 = sample_range_limit[v23 + creda];
    v11[1] = sample_range_limit[v23 + v21];
    v11[2] = sample_range_limit[cblueb + v23];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011460
// Name: _jinit_merged_upsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_merged_upsampler(jpeg_common_struct *cinfo)
{
  int v1; // esi
  unsigned int v2; // edx

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[17].progress = (jpeg_progress_mgr *)v1;
  *(_DWORD *)v1 = start_pass_merged_upsample;
  *(_BYTE *)(v1 + 8) = 0;
  v2 = cinfo[3].global_state * (int)cinfo[4].mem;
  *(_DWORD *)(v1 + 40) = v2;
  if ( cinfo[11].client_data == (void *)2 )
  {
    *(_DWORD *)(v1 + 4) = merged_2v_upsample;
    *(_DWORD *)(v1 + 12) = h2v2_merged_upsample;
    *(_DWORD *)(v1 + 32) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: v2);
  }
  else
  {
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 4) = merged_1v_upsample;
    *(_DWORD *)(v1 + 12) = h2v1_merged_upsample;
  }
  build_ycc_rgb_table_0(cinfo);
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10279D90
// Name: start_pass_merged_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_merged_upsample(jpeg_decompress_struct *cinfo)
{
  jpeg_upsampler *upsample; // eax

  upsample = cinfo->upsample;
  LOBYTE(upsample[3].start_pass) = 0;
  *(_DWORD *)&upsample[3].need_context_rows = cinfo->output_height;
}

//------------------------------------------------------------------------------
// Address: 0x10279DB0
// Name: merged_2v_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl merged_2v_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_upsampler *upsample; // esi
  unsigned int v8; // edi
  int v9; // eax
  unsigned __int8 *work_ptrs[2]; // [esp+Ch] [ebp-8h] BYREF

  upsample = cinfo->upsample;
  if ( LOBYTE(upsample[3].start_pass) != 0 )
  {
    jcopy_sample_rows(
      input_array: (unsigned __int8 **)&upsample[2].need_context_rows,
      source_row: 0,
      output_array: &output_buf[*out_row_ctr],
      dest_row: 0,
      num_rows: 1,
      num_cols: (unsigned int)upsample[3].upsample);
    v8 = 1;
    LOBYTE(upsample[3].start_pass) = 0;
  }
  else
  {
    v8 = 2;
    if ( *(_DWORD *)&upsample[3].need_context_rows < 2u )
      v8 = *(_DWORD *)&upsample[3].need_context_rows;
    v9 = *out_row_ctr;
    if ( v8 > out_rows_avail - *out_row_ctr )
      v8 = out_rows_avail - *out_row_ctr;
    work_ptrs[0] = output_buf[v9];
    if ( v8 <= 1 )
    {
      work_ptrs[1] = *(unsigned __int8 **)&upsample[2].need_context_rows;
      LOBYTE(upsample[3].start_pass) = 1;
    }
    else
    {
      work_ptrs[1] = output_buf[v9 + 1];
    }
    ((void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, _DWORD, unsigned __int8 **))upsample[1].start_pass)(
      a1: cinfo,
      a2: input_buf,
      a3: *in_row_group_ctr,
      a4: work_ptrs);
  }
  *out_row_ctr += v8;
  *(_DWORD *)&upsample[3].need_context_rows -= v8;
  if ( LOBYTE(upsample[3].start_pass) == 0 )
    ++*in_row_group_ctr;
}

//------------------------------------------------------------------------------
// Address: 0x10279E60
// Name: merged_1v_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl merged_1v_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr)
{
  ((void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, _DWORD, unsigned __int8 **))cinfo->upsample[1].start_pass)(
    a1: cinfo,
    a2: input_buf,
    a3: *in_row_group_ctr,
    a4: &output_buf[*out_row_ctr]);
  ++*out_row_ctr;
  ++*in_row_group_ctr;
}

//------------------------------------------------------------------------------
// Address: 0x10279EA0
// Name: h2v1_merged_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v1_merged_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        int in_row_group_ctr,
        unsigned __int8 **output_buf)
{
  jpeg_upsampler *upsample; // eax
  unsigned __int8 *sample_range_limit; // ecx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // edx
  unsigned __int8 *v8; // esi
  _BYTE *v9; // eax
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edi
  int v17; // esi
  int *Crrtab; // [esp+Ch] [ebp-18h]
  int *Cbbtab; // [esp+10h] [ebp-14h]
  int *Crgtab; // [esp+14h] [ebp-10h]
  int *Cbgtab; // [esp+18h] [ebp-Ch]
  unsigned __int8 *inptr2; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *inptr1; // [esp+20h] [ebp-4h]
  int cr; // [esp+2Ch] [ebp+8h]
  int cred; // [esp+30h] [ebp+Ch]
  int cblue; // [esp+34h] [ebp+10h]
  int cbluea; // [esp+34h] [ebp+10h]
  unsigned int col; // [esp+38h] [ebp+14h]

  upsample = cinfo->upsample;
  sample_range_limit = cinfo->sample_range_limit;
  Crrtab = (int *)upsample[1].upsample;
  Cbbtab = *(int **)&upsample[1].need_context_rows;
  Crgtab = (int *)upsample[2].start_pass;
  Cbgtab = (int *)upsample[2].upsample;
  v6 = (*input_buf)[in_row_group_ctr];
  v7 = input_buf[1][in_row_group_ctr];
  v8 = input_buf[2][in_row_group_ctr];
  v9 = *output_buf;
  for ( col = cinfo->output_width >> 1; col != 0; --col )
  {
    v10 = *v7;
    inptr1 = v7 + 1;
    v11 = *v8;
    inptr2 = v8 + 1;
    cred = Crrtab[v11];
    v12 = Crgtab[v11] + Cbgtab[v10];
    cblue = Cbbtab[v10];
    v13 = *v6;
    *v9 = sample_range_limit[v13 + cred];
    v12 >>= 16;
    v9[1] = sample_range_limit[v13 + v12];
    v9[2] = sample_range_limit[cblue + v13];
    v14 = v6[1];
    v9[3] = sample_range_limit[v14 + cred];
    LOBYTE(v10) = sample_range_limit[v14 + v12];
    v8 = inptr2;
    v9[4] = v10;
    v9[5] = sample_range_limit[cblue + v14];
    v7 = inptr1;
    v6 += 2;
    v9 += 6;
  }
  if ( (cinfo->output_width & 1) != 0 )
  {
    v15 = *v7;
    v16 = *v6;
    cr = *v8;
    cbluea = Cbbtab[v15];
    v17 = (Crgtab[cr] + Cbgtab[v15]) >> 16;
    *v9 = sample_range_limit[v16 + Crrtab[cr]];
    v9[1] = sample_range_limit[v16 + v17];
    v9[2] = sample_range_limit[cbluea + v16];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279FF0
// Name: h2v2_merged_upsample
// Source: json
//------------------------------------------------------------------------------
void __cdecl h2v2_merged_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        int in_row_group_ctr,
        unsigned __int8 **output_buf)
{
  jpeg_upsampler *upsample; // ecx
  unsigned __int8 *sample_range_limit; // eax
  unsigned __int8 **v6; // edx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edi
  _BYTE *v10; // ecx
  unsigned __int8 *v11; // esi
  int v12; // edx
  int v13; // edi
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  unsigned __int8 v18; // bl
  int v19; // ebx
  int v20; // edx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int *Cbbtab; // [esp+Ch] [ebp-20h]
  int *Crgtab; // [esp+10h] [ebp-1Ch]
  int *Cbgtab; // [esp+14h] [ebp-18h]
  int *Crrtab; // [esp+18h] [ebp-14h]
  unsigned __int8 *inptr1; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *inptr2; // [esp+20h] [ebp-Ch]
  unsigned __int8 *inptr01; // [esp+24h] [ebp-8h]
  unsigned __int8 *inptr00; // [esp+28h] [ebp-4h]
  unsigned __int8 *inptr00a; // [esp+28h] [ebp-4h]
  int cred; // [esp+38h] [ebp+Ch]
  int creda; // [esp+38h] [ebp+Ch]
  int cblue; // [esp+3Ch] [ebp+10h]
  int cbluea; // [esp+3Ch] [ebp+10h]
  int cblueb; // [esp+3Ch] [ebp+10h]
  unsigned int col; // [esp+40h] [ebp+14h]

  upsample = cinfo->upsample;
  sample_range_limit = cinfo->sample_range_limit;
  Crrtab = (int *)upsample[1].upsample;
  Cbbtab = *(int **)&upsample[1].need_context_rows;
  Crgtab = (int *)upsample[2].start_pass;
  Cbgtab = (int *)upsample[2].upsample;
  v6 = &(*input_buf)[2 * in_row_group_ctr];
  v7 = *v6;
  inptr01 = v6[1];
  v8 = input_buf[1][in_row_group_ctr];
  inptr00 = v7;
  v9 = input_buf[2][in_row_group_ctr];
  v10 = *output_buf;
  v11 = output_buf[1];
  for ( col = cinfo->output_width >> 1; col != 0; --col )
  {
    cblue = *v8;
    inptr1 = v8 + 1;
    v12 = *v9;
    inptr2 = v9 + 1;
    cred = Crrtab[v12];
    v13 = Crgtab[v12] + Cbgtab[cblue];
    inptr00a = inptr00 + 1;
    cbluea = Cbbtab[cblue];
    v14 = *(inptr00a - 1);
    *v10 = sample_range_limit[v14 + cred];
    v13 >>= 16;
    v10[1] = sample_range_limit[v14 + v13];
    v10[2] = sample_range_limit[cbluea + v14];
    v15 = *inptr00a;
    inptr00 = inptr00a + 1;
    v10[3] = sample_range_limit[v15 + cred];
    v10[4] = sample_range_limit[v15 + v13];
    v10[5] = sample_range_limit[cbluea + v15];
    v16 = *inptr01;
    *v11 = sample_range_limit[v16 + cred];
    v11[1] = sample_range_limit[v16 + v13];
    v11[2] = sample_range_limit[cbluea + v16];
    v17 = inptr01[1];
    inptr01 += 2;
    v11[3] = sample_range_limit[v17 + cred];
    v18 = sample_range_limit[v17 + v13];
    v9 = inptr2;
    v11[4] = v18;
    v11[5] = sample_range_limit[cbluea + v17];
    v8 = inptr1;
    v10 += 6;
    v11 += 6;
  }
  if ( (cinfo->output_width & 1) != 0 )
  {
    v19 = *v8;
    v20 = *v9;
    creda = Crrtab[v20];
    v21 = Crgtab[v20] + Cbgtab[v19];
    cblueb = Cbbtab[v19];
    v22 = *inptr00;
    *v10 = sample_range_limit[v22 + creda];
    v21 >>= 16;
    v10[1] = sample_range_limit[v22 + v21];
    v10[2] = sample_range_limit[cblueb + v22];
    v23 = *inptr01;
    *v11 = sample_range_limit[v23 + creda];
    v11[1] = sample_range_limit[v23 + v21];
    v11[2] = sample_range_limit[cblueb + v23];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A1D0
// Name: _jinit_merged_upsampler
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_merged_upsampler(jpeg_common_struct *cinfo)
{
  int v1; // esi
  unsigned int v2; // edx

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[17].progress = (jpeg_progress_mgr *)v1;
  *(_DWORD *)v1 = start_pass_merged_upsample;
  *(_BYTE *)(v1 + 8) = 0;
  v2 = cinfo[3].global_state * (int)cinfo[4].mem;
  *(_DWORD *)(v1 + 40) = v2;
  if ( cinfo[11].client_data == (void *)2 )
  {
    *(_DWORD *)(v1 + 4) = merged_2v_upsample;
    *(_DWORD *)(v1 + 12) = h2v2_merged_upsample;
    *(_DWORD *)(v1 + 32) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: v2);
  }
  else
  {
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 4) = merged_1v_upsample;
    *(_DWORD *)(v1 + 12) = h2v1_merged_upsample;
  }
  build_ycc_rgb_table_0(cinfo);
}

} // namespace client
