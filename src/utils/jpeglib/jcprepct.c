// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcprepct.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10256800
// Name: start_pass_prep
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_prep(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_prep_controller *client_data; // esi

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  client_data[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo[1].progress;
  client_data[6].pre_process_data = nullptr;
  client_data[7].start_pass = nullptr;
  client_data[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))(2 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x10256850
// Name: pre_process_data
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_data(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // edi
  unsigned int v9; // esi
  int v10; // eax
  bool v11; // zf
  unsigned __int8 ***p_pre_process_data; // eax
  int v13; // esi
  unsigned __int8 **v14; // eax
  unsigned int *v15; // esi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int max_v_samp_factor; // [esp+8h] [ebp-14h]
  unsigned int v22; // [esp+8h] [ebp-14h]
  int source_row; // [esp+Ch] [ebp-10h]
  int source_rowa; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+14h] [ebp-8h]
  jpeg_c_prep_controller *v27; // [esp+18h] [ebp-4h]
  int ci; // [esp+24h] [ebp+8h]
  int cia; // [esp+24h] [ebp+8h]
  unsigned int *in_row_ctra; // [esp+2Ch] [ebp+10h]
  unsigned __int8 **in_rows_availa; // [esp+30h] [ebp+14h]

  prep = cinfo->prep;
  if ( *in_row_ctr < in_rows_avail )
  {
    while ( *out_row_group_ctr < out_row_groups_avail )
    {
      v9 = cinfo->max_v_samp_factor - (unsigned int)prep[6].pre_process_data;
      if ( v9 >= in_rows_avail - *in_row_ctr )
        v9 = in_rows_avail - *in_row_ctr;
      cinfo->cconvert->color_convert(
        a1: cinfo,
        a2: &input_buf[*in_row_ctr],
        a3: (unsigned __int8 ***)&prep[1],
        a4: (unsigned int)prep[6].pre_process_data,
        a5: v9);
      *in_row_ctr += v9;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v9);
      v10 = (int)prep[6].pre_process_data;
      v11 = prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v9;
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v9);
      if ( v11 && v10 < cinfo->max_v_samp_factor )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          p_pre_process_data = (unsigned __int8 ***)&prep[1];
          v27 = prep + 1;
          do
          {
            v13 = (int)prep[6].pre_process_data;
            v14 = *p_pre_process_data;
            max_v_samp_factor = cinfo->max_v_samp_factor;
            num_cols = cinfo->image_width;
            v26 = v14;
            if ( v13 < max_v_samp_factor )
            {
              source_row = v13 - 1;
              jcopy_sample_rows(
                input_array: v14,
                source_row: v13 - 1,
                output_array: v14,
                dest_row: v13,
                num_rows: 1,
                num_cols);
              while ( ++v13 < max_v_samp_factor )
                jcopy_sample_rows(input_array: v26, source_row, output_array: v26, dest_row: v13, num_rows: 1, num_cols);
            }
            p_pre_process_data = (unsigned __int8 ***)&v27->pre_process_data;
            ++ci;
            v27 = (jpeg_c_prep_controller *)((char *)v27 + 4);
          }
          while ( ci < cinfo->num_components );
        }
        prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor;
      }
      v15 = out_row_group_ctr;
      if ( prep[6].pre_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor )
      {
        cinfo->downsample->downsample(
          a1: cinfo,
          a2: (unsigned __int8 ***)&prep[1],
          a3: 0,
          a4: output_buf,
          a5: *out_row_group_ctr);
        prep[6].pre_process_data = nullptr;
        ++*out_row_group_ctr;
      }
      if ( prep[6].start_pass == nullptr && *out_row_group_ctr < out_row_groups_avail )
      {
        comp_info = cinfo->comp_info;
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          p_v_samp_factor = &comp_info->v_samp_factor;
          in_row_ctra = (unsigned int *)&comp_info->v_samp_factor;
          do
          {
            v18 = *p_v_samp_factor * *v15;
            v19 = out_row_groups_avail * *p_v_samp_factor;
            v22 = 8 * p_v_samp_factor[4];
            in_rows_availa = output_buf[cia];
            v20 = v18;
            if ( v18 < v19 )
            {
              source_rowa = v18 - 1;
              jcopy_sample_rows(
                input_array: output_buf[cia],
                source_row: v18 - 1,
                output_array: output_buf[cia],
                dest_row: v18,
                num_rows: 1,
                num_cols: 8 * p_v_samp_factor[4]);
              while ( ++v20 < v19 )
                jcopy_sample_rows(
                  input_array: in_rows_availa,
                  source_row: source_rowa,
                  output_array: in_rows_availa,
                  dest_row: v20,
                  num_rows: 1,
                  num_cols: v22);
            }
            v15 = out_row_group_ctr;
            p_v_samp_factor = (int *)(in_row_ctra + 21);
            ++cia;
            in_row_ctra += 21;
          }
          while ( cia < cinfo->num_components );
        }
        *v15 = out_row_groups_avail;
        return;
      }
      if ( *in_row_ctr >= in_rows_avail )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256A30
// Name: pre_process_context
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_context(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // ebx
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int max_v_samp_factor; // eax
  int v13; // edi
  int pre_process_data; // edi
  int buf_height; // [esp+8h] [ebp-18h]
  void (__cdecl *v16)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int); // [esp+Ch] [ebp-14h]
  int source_row; // [esp+10h] [ebp-10h]
  int numrows; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***numrowsa; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***v20; // [esp+18h] [ebp-8h]
  unsigned __int8 **v21; // [esp+18h] [ebp-8h]
  int dest_row; // [esp+1Ch] [ebp-4h]
  int dest_rowa; // [esp+1Ch] [ebp-4h]
  int ci; // [esp+28h] [ebp+8h]
  int cia; // [esp+28h] [ebp+8h]

  prep = cinfo->prep;
  buf_height = 3 * cinfo->max_v_samp_factor;
  while ( *out_row_group_ctr < out_row_groups_avail )
  {
    v9 = *in_row_ctr;
    if ( *in_row_ctr >= in_rows_avail )
    {
      if ( prep[6].start_pass != nullptr )
        return;
      if ( (int)prep[6].pre_process_data < (int)prep[7].pre_process_data )
      {
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          numrowsa = (unsigned __int8 ***)&prep[1];
          do
          {
            pre_process_data = (int)prep[6].pre_process_data;
            v16 = prep[7].pre_process_data;
            dest_rowa = cinfo->image_width;
            v21 = *numrowsa;
            if ( pre_process_data < (int)v16 )
            {
              source_row = pre_process_data - 1;
              jcopy_sample_rows(
                input_array: *numrowsa,
                source_row: pre_process_data - 1,
                output_array: *numrowsa,
                dest_row: pre_process_data,
                num_rows: 1,
                num_cols: dest_rowa);
              while ( ++pre_process_data < (int)v16 )
                jcopy_sample_rows(
                  input_array: v21,
                  source_row,
                  output_array: v21,
                  dest_row: pre_process_data,
                  num_rows: 1,
                  num_cols: dest_rowa);
            }
            ++numrowsa;
            ++cia;
          }
          while ( cia < cinfo->num_components );
        }
        prep[6].pre_process_data = prep[7].pre_process_data;
      }
    }
    else
    {
      v10 = (unsigned int)prep[6].pre_process_data;
      v11 = (unsigned int)prep[7].pre_process_data - v10;
      numrows = v11;
      if ( v11 >= in_rows_avail - v9 )
      {
        numrows = in_rows_avail - v9;
        v11 = in_rows_avail - v9;
      }
      cinfo->cconvert->color_convert(a1: cinfo, a2: &input_buf[v9], a3: (unsigned __int8 ***)&prep[1], a4: v10, a5: v11);
      if ( prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->image_height )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          max_v_samp_factor = cinfo->max_v_samp_factor;
          v20 = (unsigned __int8 ***)&prep[1];
          do
          {
            v13 = 1;
            if ( max_v_samp_factor >= 1 )
            {
              dest_row = -1;
              do
              {
                jcopy_sample_rows(
                  input_array: *v20,
                  source_row: 0,
                  output_array: *v20,
                  dest_row,
                  num_rows: 1,
                  num_cols: cinfo->image_width);
                max_v_samp_factor = cinfo->max_v_samp_factor;
                --dest_row;
                ++v13;
              }
              while ( v13 <= max_v_samp_factor );
            }
            ++v20;
            ++ci;
          }
          while ( ci < cinfo->num_components );
          v11 = numrows;
        }
      }
      *in_row_ctr += v11;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v11);
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v11);
    }
    if ( prep[6].pre_process_data == prep[7].pre_process_data )
    {
      cinfo->downsample->downsample(
        a1: cinfo,
        a2: (unsigned __int8 ***)&prep[1],
        a3: (unsigned int)prep[7].start_pass,
        a4: output_buf,
        a5: *out_row_group_ctr);
      ++*out_row_group_ctr;
      prep[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[7].start_pass
                                                                                + cinfo->max_v_samp_factor);
      if ( (int)prep[7].start_pass >= buf_height )
        prep[7].start_pass = nullptr;
      if ( (int)prep[6].pre_process_data >= buf_height )
        prep[6].pre_process_data = nullptr;
      prep[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + cinfo->max_v_samp_factor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256C10
// Name: create_context_buffer
// Source: json
//------------------------------------------------------------------------------
void __usercall create_context_buffer(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_c_prep_controller *client_data; // ebx
  int mem; // esi
  int *v3; // ecx
  unsigned __int8 **v4; // ebx
  unsigned __int8 **v5; // ecx
  unsigned __int8 **v6; // eax
  int v7; // ebx
  unsigned __int8 *v8; // edx
  jpeg_c_prep_controller *v9; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  unsigned __int8 **true_buffer; // [esp+18h] [ebp-10h]
  unsigned __int8 **true_buffera; // [esp+18h] [ebp-10h]
  int *v13; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **fake_buffer; // [esp+20h] [ebp-8h]
  unsigned __int8 **v15; // [esp+24h] [ebp-4h]

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  mem = (int)cinfo[9].mem;
  fake_buffer = (unsigned __int8 **)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 20 * mem * (int)cinfo[2].client_data);
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 8);
    v13 = v3;
    v9 = client_data + 1;
    while ( 1 )
    {
      v4 = fake_buffer;
      true_buffer = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[9].err * v3[5] / *v3, a4: 3 * mem);
      memcpy(dst: (unsigned __int8 *)&fake_buffer[mem], src: (unsigned __int8 *)true_buffer, count: 12 * mem);
      if ( mem > 0 )
      {
        v5 = true_buffer;
        v6 = &fake_buffer[4 * mem];
        v15 = &true_buffer[2 * mem];
        v7 = (char *)fake_buffer - (char *)true_buffer;
        for ( true_buffera = (unsigned __int8 **)mem;
              true_buffera != nullptr;
              true_buffera = (unsigned __int8 **)((char *)true_buffera - 1) )
        {
          v8 = *v15++;
          *(unsigned __int8 **)((char *)v5 + v7) = v8;
          *v6++ = *v5++;
        }
        v4 = fake_buffer;
      }
      v13 += 21;
      v9->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))&v4[mem];
      fake_buffer = &v4[5 * mem];
      ++ci;
      v9 = (jpeg_c_prep_controller *)((char *)v9 + 4);
      if ( ci >= (int)cinfo[2].client_data )
        break;
      v3 = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256D20
// Name: _jinit_c_prep_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_prep_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_prep_controller *v2; // eax
  int *v3; // esi
  jpeg_c_prep_controller *v4; // ebx
  int ci; // [esp+10h] [ebp+Ch]

  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  v2 = (jpeg_c_prep_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_prep;
  if ( LOBYTE(cinfo[14].mem->alloc_sarray) != 0 )
  {
    v2->pre_process_data = pre_process_context;
    create_context_buffer(cinfo);
  }
  else
  {
    v2->pre_process_data = pre_process_data;
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v3 = (int *)(cinfo[2].global_state + 8);
      v4 = v2 + 1;
      do
      {
        v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: 8 * (int)cinfo[9].err * v3[5] / *v3,
                                                                                 a4: cinfo[9].mem);
        v4 = (jpeg_c_prep_controller *)((char *)v4 + 4);
        v3 += 21;
        ++ci;
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10256830
// Name: start_pass_prep
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_prep(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_prep_controller *client_data; // esi

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  client_data[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo[1].progress;
  client_data[6].pre_process_data = nullptr;
  client_data[7].start_pass = nullptr;
  client_data[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))(2 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x10256880
// Name: pre_process_data
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_data(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // edi
  unsigned int v9; // esi
  int v10; // eax
  bool v11; // zf
  unsigned __int8 ***p_pre_process_data; // eax
  int v13; // esi
  unsigned __int8 **v14; // eax
  unsigned int *v15; // esi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int max_v_samp_factor; // [esp+8h] [ebp-14h]
  unsigned int v22; // [esp+8h] [ebp-14h]
  int source_row; // [esp+Ch] [ebp-10h]
  int source_rowa; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+14h] [ebp-8h]
  jpeg_c_prep_controller *v27; // [esp+18h] [ebp-4h]
  int ci; // [esp+24h] [ebp+8h]
  int cia; // [esp+24h] [ebp+8h]
  unsigned int *in_row_ctra; // [esp+2Ch] [ebp+10h]
  unsigned __int8 **in_rows_availa; // [esp+30h] [ebp+14h]

  prep = cinfo->prep;
  if ( *in_row_ctr < in_rows_avail )
  {
    while ( *out_row_group_ctr < out_row_groups_avail )
    {
      v9 = cinfo->max_v_samp_factor - (unsigned int)prep[6].pre_process_data;
      if ( v9 >= in_rows_avail - *in_row_ctr )
        v9 = in_rows_avail - *in_row_ctr;
      cinfo->cconvert->color_convert(
        a1: cinfo,
        a2: &input_buf[*in_row_ctr],
        a3: (unsigned __int8 ***)&prep[1],
        a4: (unsigned int)prep[6].pre_process_data,
        a5: v9);
      *in_row_ctr += v9;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v9);
      v10 = (int)prep[6].pre_process_data;
      v11 = prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v9;
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v9);
      if ( v11 && v10 < cinfo->max_v_samp_factor )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          p_pre_process_data = (unsigned __int8 ***)&prep[1];
          v27 = prep + 1;
          do
          {
            v13 = (int)prep[6].pre_process_data;
            v14 = *p_pre_process_data;
            max_v_samp_factor = cinfo->max_v_samp_factor;
            num_cols = cinfo->image_width;
            v26 = v14;
            if ( v13 < max_v_samp_factor )
            {
              source_row = v13 - 1;
              jcopy_sample_rows(
                input_array: v14,
                source_row: v13 - 1,
                output_array: v14,
                dest_row: v13,
                num_rows: 1,
                num_cols);
              while ( ++v13 < max_v_samp_factor )
                jcopy_sample_rows(input_array: v26, source_row, output_array: v26, dest_row: v13, num_rows: 1, num_cols);
            }
            p_pre_process_data = (unsigned __int8 ***)&v27->pre_process_data;
            ++ci;
            v27 = (jpeg_c_prep_controller *)((char *)v27 + 4);
          }
          while ( ci < cinfo->num_components );
        }
        prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor;
      }
      v15 = out_row_group_ctr;
      if ( prep[6].pre_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor )
      {
        cinfo->downsample->downsample(
          a1: cinfo,
          a2: (unsigned __int8 ***)&prep[1],
          a3: 0,
          a4: output_buf,
          a5: *out_row_group_ctr);
        prep[6].pre_process_data = nullptr;
        ++*out_row_group_ctr;
      }
      if ( prep[6].start_pass == nullptr && *out_row_group_ctr < out_row_groups_avail )
      {
        comp_info = cinfo->comp_info;
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          p_v_samp_factor = &comp_info->v_samp_factor;
          in_row_ctra = (unsigned int *)&comp_info->v_samp_factor;
          do
          {
            v18 = *p_v_samp_factor * *v15;
            v19 = out_row_groups_avail * *p_v_samp_factor;
            v22 = 8 * p_v_samp_factor[4];
            in_rows_availa = output_buf[cia];
            v20 = v18;
            if ( v18 < v19 )
            {
              source_rowa = v18 - 1;
              jcopy_sample_rows(
                input_array: output_buf[cia],
                source_row: v18 - 1,
                output_array: output_buf[cia],
                dest_row: v18,
                num_rows: 1,
                num_cols: 8 * p_v_samp_factor[4]);
              while ( ++v20 < v19 )
                jcopy_sample_rows(
                  input_array: in_rows_availa,
                  source_row: source_rowa,
                  output_array: in_rows_availa,
                  dest_row: v20,
                  num_rows: 1,
                  num_cols: v22);
            }
            v15 = out_row_group_ctr;
            p_v_samp_factor = (int *)(in_row_ctra + 21);
            ++cia;
            in_row_ctra += 21;
          }
          while ( cia < cinfo->num_components );
        }
        *v15 = out_row_groups_avail;
        return;
      }
      if ( *in_row_ctr >= in_rows_avail )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256A60
// Name: pre_process_context
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_context(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // ebx
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int max_v_samp_factor; // eax
  int v13; // edi
  int pre_process_data; // edi
  int buf_height; // [esp+8h] [ebp-18h]
  void (__cdecl *v16)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int); // [esp+Ch] [ebp-14h]
  int source_row; // [esp+10h] [ebp-10h]
  int numrows; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***numrowsa; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***v20; // [esp+18h] [ebp-8h]
  unsigned __int8 **v21; // [esp+18h] [ebp-8h]
  int dest_row; // [esp+1Ch] [ebp-4h]
  int dest_rowa; // [esp+1Ch] [ebp-4h]
  int ci; // [esp+28h] [ebp+8h]
  int cia; // [esp+28h] [ebp+8h]

  prep = cinfo->prep;
  buf_height = 3 * cinfo->max_v_samp_factor;
  while ( *out_row_group_ctr < out_row_groups_avail )
  {
    v9 = *in_row_ctr;
    if ( *in_row_ctr >= in_rows_avail )
    {
      if ( prep[6].start_pass != nullptr )
        return;
      if ( (int)prep[6].pre_process_data < (int)prep[7].pre_process_data )
      {
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          numrowsa = (unsigned __int8 ***)&prep[1];
          do
          {
            pre_process_data = (int)prep[6].pre_process_data;
            v16 = prep[7].pre_process_data;
            dest_rowa = cinfo->image_width;
            v21 = *numrowsa;
            if ( pre_process_data < (int)v16 )
            {
              source_row = pre_process_data - 1;
              jcopy_sample_rows(
                input_array: *numrowsa,
                source_row: pre_process_data - 1,
                output_array: *numrowsa,
                dest_row: pre_process_data,
                num_rows: 1,
                num_cols: dest_rowa);
              while ( ++pre_process_data < (int)v16 )
                jcopy_sample_rows(
                  input_array: v21,
                  source_row,
                  output_array: v21,
                  dest_row: pre_process_data,
                  num_rows: 1,
                  num_cols: dest_rowa);
            }
            ++numrowsa;
            ++cia;
          }
          while ( cia < cinfo->num_components );
        }
        prep[6].pre_process_data = prep[7].pre_process_data;
      }
    }
    else
    {
      v10 = (unsigned int)prep[6].pre_process_data;
      v11 = (unsigned int)prep[7].pre_process_data - v10;
      numrows = v11;
      if ( v11 >= in_rows_avail - v9 )
      {
        numrows = in_rows_avail - v9;
        v11 = in_rows_avail - v9;
      }
      cinfo->cconvert->color_convert(a1: cinfo, a2: &input_buf[v9], a3: (unsigned __int8 ***)&prep[1], a4: v10, a5: v11);
      if ( prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->image_height )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          max_v_samp_factor = cinfo->max_v_samp_factor;
          v20 = (unsigned __int8 ***)&prep[1];
          do
          {
            v13 = 1;
            if ( max_v_samp_factor >= 1 )
            {
              dest_row = -1;
              do
              {
                jcopy_sample_rows(
                  input_array: *v20,
                  source_row: 0,
                  output_array: *v20,
                  dest_row,
                  num_rows: 1,
                  num_cols: cinfo->image_width);
                max_v_samp_factor = cinfo->max_v_samp_factor;
                --dest_row;
                ++v13;
              }
              while ( v13 <= max_v_samp_factor );
            }
            ++v20;
            ++ci;
          }
          while ( ci < cinfo->num_components );
          v11 = numrows;
        }
      }
      *in_row_ctr += v11;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v11);
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v11);
    }
    if ( prep[6].pre_process_data == prep[7].pre_process_data )
    {
      cinfo->downsample->downsample(
        a1: cinfo,
        a2: (unsigned __int8 ***)&prep[1],
        a3: (unsigned int)prep[7].start_pass,
        a4: output_buf,
        a5: *out_row_group_ctr);
      ++*out_row_group_ctr;
      prep[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[7].start_pass
                                                                                + cinfo->max_v_samp_factor);
      if ( (int)prep[7].start_pass >= buf_height )
        prep[7].start_pass = nullptr;
      if ( (int)prep[6].pre_process_data >= buf_height )
        prep[6].pre_process_data = nullptr;
      prep[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + cinfo->max_v_samp_factor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256C40
// Name: create_context_buffer
// Source: json
//------------------------------------------------------------------------------
void __usercall create_context_buffer(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_c_prep_controller *client_data; // ebx
  int mem; // esi
  int *v3; // ecx
  unsigned __int8 **v4; // ebx
  unsigned __int8 **v5; // ecx
  unsigned __int8 **v6; // eax
  int v7; // ebx
  unsigned __int8 *v8; // edx
  jpeg_c_prep_controller *v9; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  unsigned __int8 **true_buffer; // [esp+18h] [ebp-10h]
  unsigned __int8 **true_buffera; // [esp+18h] [ebp-10h]
  int *v13; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **fake_buffer; // [esp+20h] [ebp-8h]
  unsigned __int8 **v15; // [esp+24h] [ebp-4h]

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  mem = (int)cinfo[9].mem;
  fake_buffer = (unsigned __int8 **)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 20 * mem * (int)cinfo[2].client_data);
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 8);
    v13 = v3;
    v9 = client_data + 1;
    while ( 1 )
    {
      v4 = fake_buffer;
      true_buffer = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[9].err * v3[5] / *v3, a4: 3 * mem);
      memcpy(dst: (unsigned __int8 *)&fake_buffer[mem], src: (unsigned __int8 *)true_buffer, count: 12 * mem);
      if ( mem > 0 )
      {
        v5 = true_buffer;
        v6 = &fake_buffer[4 * mem];
        v15 = &true_buffer[2 * mem];
        v7 = (char *)fake_buffer - (char *)true_buffer;
        for ( true_buffera = (unsigned __int8 **)mem;
              true_buffera != nullptr;
              true_buffera = (unsigned __int8 **)((char *)true_buffera - 1) )
        {
          v8 = *v15++;
          *(unsigned __int8 **)((char *)v5 + v7) = v8;
          *v6++ = *v5++;
        }
        v4 = fake_buffer;
      }
      v13 += 21;
      v9->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))&v4[mem];
      fake_buffer = &v4[5 * mem];
      ++ci;
      v9 = (jpeg_c_prep_controller *)((char *)v9 + 4);
      if ( ci >= (int)cinfo[2].client_data )
        break;
      v3 = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256D50
// Name: _jinit_c_prep_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_prep_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_prep_controller *v2; // eax
  int *v3; // esi
  jpeg_c_prep_controller *v4; // ebx
  int ci; // [esp+10h] [ebp+Ch]

  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  v2 = (jpeg_c_prep_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_prep;
  if ( LOBYTE(cinfo[14].mem->alloc_sarray) != 0 )
  {
    v2->pre_process_data = pre_process_context;
    create_context_buffer(cinfo);
  }
  else
  {
    v2->pre_process_data = pre_process_data;
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v3 = (int *)(cinfo[2].global_state + 8);
      v4 = v2 + 1;
      do
      {
        v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: 8 * (int)cinfo[9].err * v3[5] / *v3,
                                                                                 a4: cinfo[9].mem);
        v4 = (jpeg_c_prep_controller *)((char *)v4 + 4);
        v3 += 21;
        ++ci;
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040AD50
// Name: start_pass_prep
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_prep(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_prep_controller *client_data; // esi

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  client_data[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo[1].progress;
  client_data[6].pre_process_data = nullptr;
  client_data[7].start_pass = nullptr;
  client_data[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))(2 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x0040ADA0
// Name: pre_process_data
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_data(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // edi
  unsigned int v9; // esi
  int v10; // eax
  bool v11; // zf
  unsigned __int8 ***p_pre_process_data; // eax
  int v13; // esi
  unsigned __int8 **v14; // eax
  unsigned int *v15; // esi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int max_v_samp_factor; // [esp+8h] [ebp-14h]
  unsigned int v22; // [esp+8h] [ebp-14h]
  int source_row; // [esp+Ch] [ebp-10h]
  int source_rowa; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+14h] [ebp-8h]
  jpeg_c_prep_controller *v27; // [esp+18h] [ebp-4h]
  int ci; // [esp+24h] [ebp+8h]
  int cia; // [esp+24h] [ebp+8h]
  unsigned int *in_row_ctra; // [esp+2Ch] [ebp+10h]
  unsigned __int8 **in_rows_availa; // [esp+30h] [ebp+14h]

  prep = cinfo->prep;
  if ( *in_row_ctr < in_rows_avail )
  {
    while ( *out_row_group_ctr < out_row_groups_avail )
    {
      v9 = cinfo->max_v_samp_factor - (unsigned int)prep[6].pre_process_data;
      if ( v9 >= in_rows_avail - *in_row_ctr )
        v9 = in_rows_avail - *in_row_ctr;
      cinfo->cconvert->color_convert(
        a1: cinfo,
        a2: &input_buf[*in_row_ctr],
        a3: (unsigned __int8 ***)&prep[1],
        a4: (unsigned int)prep[6].pre_process_data,
        a5: v9);
      *in_row_ctr += v9;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v9);
      v10 = (int)prep[6].pre_process_data;
      v11 = prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v9;
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v9);
      if ( v11 && v10 < cinfo->max_v_samp_factor )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          p_pre_process_data = (unsigned __int8 ***)&prep[1];
          v27 = prep + 1;
          do
          {
            v13 = (int)prep[6].pre_process_data;
            v14 = *p_pre_process_data;
            max_v_samp_factor = cinfo->max_v_samp_factor;
            num_cols = cinfo->image_width;
            v26 = v14;
            if ( v13 < max_v_samp_factor )
            {
              source_row = v13 - 1;
              jcopy_sample_rows(
                input_array: v14,
                source_row: v13 - 1,
                output_array: v14,
                dest_row: v13,
                num_rows: 1,
                num_cols);
              while ( ++v13 < max_v_samp_factor )
                jcopy_sample_rows(input_array: v26, source_row, output_array: v26, dest_row: v13, num_rows: 1, num_cols);
            }
            p_pre_process_data = (unsigned __int8 ***)&v27->pre_process_data;
            ++ci;
            v27 = (jpeg_c_prep_controller *)((char *)v27 + 4);
          }
          while ( ci < cinfo->num_components );
        }
        prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor;
      }
      v15 = out_row_group_ctr;
      if ( prep[6].pre_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor )
      {
        cinfo->downsample->downsample(
          a1: cinfo,
          a2: (unsigned __int8 ***)&prep[1],
          a3: 0,
          a4: output_buf,
          a5: *out_row_group_ctr);
        prep[6].pre_process_data = nullptr;
        ++*out_row_group_ctr;
      }
      if ( prep[6].start_pass == nullptr && *out_row_group_ctr < out_row_groups_avail )
      {
        comp_info = cinfo->comp_info;
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          p_v_samp_factor = &comp_info->v_samp_factor;
          in_row_ctra = (unsigned int *)&comp_info->v_samp_factor;
          do
          {
            v18 = *p_v_samp_factor * *v15;
            v19 = out_row_groups_avail * *p_v_samp_factor;
            v22 = 8 * p_v_samp_factor[4];
            in_rows_availa = output_buf[cia];
            v20 = v18;
            if ( v18 < v19 )
            {
              source_rowa = v18 - 1;
              jcopy_sample_rows(
                input_array: output_buf[cia],
                source_row: v18 - 1,
                output_array: output_buf[cia],
                dest_row: v18,
                num_rows: 1,
                num_cols: 8 * p_v_samp_factor[4]);
              while ( ++v20 < v19 )
                jcopy_sample_rows(
                  input_array: in_rows_availa,
                  source_row: source_rowa,
                  output_array: in_rows_availa,
                  dest_row: v20,
                  num_rows: 1,
                  num_cols: v22);
            }
            v15 = out_row_group_ctr;
            p_v_samp_factor = (int *)(in_row_ctra + 21);
            ++cia;
            in_row_ctra += 21;
          }
          while ( cia < cinfo->num_components );
        }
        *v15 = out_row_groups_avail;
        return;
      }
      if ( *in_row_ctr >= in_rows_avail )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AF80
// Name: pre_process_context
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_context(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // ebx
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int max_v_samp_factor; // eax
  int v13; // edi
  int pre_process_data; // edi
  int buf_height; // [esp+8h] [ebp-18h]
  void (__cdecl *v16)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int); // [esp+Ch] [ebp-14h]
  int source_row; // [esp+10h] [ebp-10h]
  int numrows; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***numrowsa; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***v20; // [esp+18h] [ebp-8h]
  unsigned __int8 **v21; // [esp+18h] [ebp-8h]
  int dest_row; // [esp+1Ch] [ebp-4h]
  int dest_rowa; // [esp+1Ch] [ebp-4h]
  int ci; // [esp+28h] [ebp+8h]
  int cia; // [esp+28h] [ebp+8h]

  prep = cinfo->prep;
  buf_height = 3 * cinfo->max_v_samp_factor;
  while ( *out_row_group_ctr < out_row_groups_avail )
  {
    v9 = *in_row_ctr;
    if ( *in_row_ctr >= in_rows_avail )
    {
      if ( prep[6].start_pass != nullptr )
        return;
      if ( (int)prep[6].pre_process_data < (int)prep[7].pre_process_data )
      {
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          numrowsa = (unsigned __int8 ***)&prep[1];
          do
          {
            pre_process_data = (int)prep[6].pre_process_data;
            v16 = prep[7].pre_process_data;
            dest_rowa = cinfo->image_width;
            v21 = *numrowsa;
            if ( pre_process_data < (int)v16 )
            {
              source_row = pre_process_data - 1;
              jcopy_sample_rows(
                input_array: *numrowsa,
                source_row: pre_process_data - 1,
                output_array: *numrowsa,
                dest_row: pre_process_data,
                num_rows: 1,
                num_cols: dest_rowa);
              while ( ++pre_process_data < (int)v16 )
                jcopy_sample_rows(
                  input_array: v21,
                  source_row,
                  output_array: v21,
                  dest_row: pre_process_data,
                  num_rows: 1,
                  num_cols: dest_rowa);
            }
            ++numrowsa;
            ++cia;
          }
          while ( cia < cinfo->num_components );
        }
        prep[6].pre_process_data = prep[7].pre_process_data;
      }
    }
    else
    {
      v10 = (unsigned int)prep[6].pre_process_data;
      v11 = (unsigned int)prep[7].pre_process_data - v10;
      numrows = v11;
      if ( v11 >= in_rows_avail - v9 )
      {
        numrows = in_rows_avail - v9;
        v11 = in_rows_avail - v9;
      }
      cinfo->cconvert->color_convert(a1: cinfo, a2: &input_buf[v9], a3: (unsigned __int8 ***)&prep[1], a4: v10, a5: v11);
      if ( prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->image_height )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          max_v_samp_factor = cinfo->max_v_samp_factor;
          v20 = (unsigned __int8 ***)&prep[1];
          do
          {
            v13 = 1;
            if ( max_v_samp_factor >= 1 )
            {
              dest_row = -1;
              do
              {
                jcopy_sample_rows(
                  input_array: *v20,
                  source_row: 0,
                  output_array: *v20,
                  dest_row,
                  num_rows: 1,
                  num_cols: cinfo->image_width);
                max_v_samp_factor = cinfo->max_v_samp_factor;
                --dest_row;
                ++v13;
              }
              while ( v13 <= max_v_samp_factor );
            }
            ++v20;
            ++ci;
          }
          while ( ci < cinfo->num_components );
          v11 = numrows;
        }
      }
      *in_row_ctr += v11;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v11);
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v11);
    }
    if ( prep[6].pre_process_data == prep[7].pre_process_data )
    {
      cinfo->downsample->downsample(
        a1: cinfo,
        a2: (unsigned __int8 ***)&prep[1],
        a3: (unsigned int)prep[7].start_pass,
        a4: output_buf,
        a5: *out_row_group_ctr);
      ++*out_row_group_ctr;
      prep[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[7].start_pass
                                                                                + cinfo->max_v_samp_factor);
      if ( (int)prep[7].start_pass >= buf_height )
        prep[7].start_pass = nullptr;
      if ( (int)prep[6].pre_process_data >= buf_height )
        prep[6].pre_process_data = nullptr;
      prep[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + cinfo->max_v_samp_factor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B160
// Name: create_context_buffer
// Source: json
//------------------------------------------------------------------------------
void __usercall create_context_buffer(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_c_prep_controller *client_data; // ebx
  int mem; // esi
  int *v3; // ecx
  unsigned __int8 **v4; // ebx
  unsigned __int8 **v5; // ecx
  unsigned __int8 **v6; // eax
  int v7; // ebx
  unsigned __int8 *v8; // edx
  jpeg_c_prep_controller *v9; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  unsigned __int8 **true_buffer; // [esp+18h] [ebp-10h]
  unsigned __int8 **true_buffera; // [esp+18h] [ebp-10h]
  int *v13; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **fake_buffer; // [esp+20h] [ebp-8h]
  unsigned __int8 **v15; // [esp+24h] [ebp-4h]

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  mem = (int)cinfo[9].mem;
  fake_buffer = (unsigned __int8 **)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 20 * mem * (int)cinfo[2].client_data);
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 8);
    v13 = v3;
    v9 = client_data + 1;
    while ( 1 )
    {
      v4 = fake_buffer;
      true_buffer = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[9].err * v3[5] / *v3, a4: 3 * mem);
      memcpy(dst: (unsigned __int8 *)&fake_buffer[mem], src: (unsigned __int8 *)true_buffer, count: 12 * mem);
      if ( mem > 0 )
      {
        v5 = true_buffer;
        v6 = &fake_buffer[4 * mem];
        v15 = &true_buffer[2 * mem];
        v7 = (char *)fake_buffer - (char *)true_buffer;
        for ( true_buffera = (unsigned __int8 **)mem;
              true_buffera != nullptr;
              true_buffera = (unsigned __int8 **)((char *)true_buffera - 1) )
        {
          v8 = *v15++;
          *(unsigned __int8 **)((char *)v5 + v7) = v8;
          *v6++ = *v5++;
        }
        v4 = fake_buffer;
      }
      v13 += 21;
      v9->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))&v4[mem];
      fake_buffer = &v4[5 * mem];
      ++ci;
      v9 = (jpeg_c_prep_controller *)((char *)v9 + 4);
      if ( ci >= (int)cinfo[2].client_data )
        break;
      v3 = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B270
// Name: _jinit_c_prep_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_prep_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_prep_controller *v2; // eax
  int *v3; // esi
  jpeg_c_prep_controller *v4; // ebx
  int ci; // [esp+10h] [ebp+Ch]

  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  v2 = (jpeg_c_prep_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_prep;
  if ( LOBYTE(cinfo[14].mem->alloc_sarray) != 0 )
  {
    v2->pre_process_data = pre_process_context;
    create_context_buffer(cinfo);
  }
  else
  {
    v2->pre_process_data = pre_process_data;
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v3 = (int *)(cinfo[2].global_state + 8);
      v4 = v2 + 1;
      do
      {
        v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: 8 * (int)cinfo[9].err * v3[5] / *v3,
                                                                                 a4: cinfo[9].mem);
        v4 = (jpeg_c_prep_controller *)((char *)v4 + 4);
        v3 += 21;
        ++ci;
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00434060
// Name: start_pass_prep
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_prep(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_prep_controller *client_data; // esi

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  client_data[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo[1].progress;
  client_data[6].pre_process_data = nullptr;
  client_data[7].start_pass = nullptr;
  client_data[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))(2 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x004340B0
// Name: pre_process_data
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_data(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // edi
  unsigned int v9; // esi
  int v10; // eax
  bool v11; // zf
  unsigned __int8 ***p_pre_process_data; // eax
  int v13; // esi
  unsigned __int8 **v14; // eax
  unsigned int *v15; // esi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int max_v_samp_factor; // [esp+8h] [ebp-14h]
  unsigned int v22; // [esp+8h] [ebp-14h]
  int source_row; // [esp+Ch] [ebp-10h]
  int source_rowa; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+14h] [ebp-8h]
  jpeg_c_prep_controller *v27; // [esp+18h] [ebp-4h]
  int ci; // [esp+24h] [ebp+8h]
  int cia; // [esp+24h] [ebp+8h]
  unsigned int *in_row_ctra; // [esp+2Ch] [ebp+10h]
  unsigned __int8 **in_rows_availa; // [esp+30h] [ebp+14h]

  prep = cinfo->prep;
  if ( *in_row_ctr < in_rows_avail )
  {
    while ( *out_row_group_ctr < out_row_groups_avail )
    {
      v9 = cinfo->max_v_samp_factor - (unsigned int)prep[6].pre_process_data;
      if ( v9 >= in_rows_avail - *in_row_ctr )
        v9 = in_rows_avail - *in_row_ctr;
      cinfo->cconvert->color_convert(
        a1: cinfo,
        a2: &input_buf[*in_row_ctr],
        a3: (unsigned __int8 ***)&prep[1],
        a4: (unsigned int)prep[6].pre_process_data,
        a5: v9);
      *in_row_ctr += v9;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v9);
      v10 = (int)prep[6].pre_process_data;
      v11 = prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v9;
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v9);
      if ( v11 && v10 < cinfo->max_v_samp_factor )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          p_pre_process_data = (unsigned __int8 ***)&prep[1];
          v27 = prep + 1;
          do
          {
            v13 = (int)prep[6].pre_process_data;
            v14 = *p_pre_process_data;
            max_v_samp_factor = cinfo->max_v_samp_factor;
            num_cols = cinfo->image_width;
            v26 = v14;
            if ( v13 < max_v_samp_factor )
            {
              source_row = v13 - 1;
              jcopy_sample_rows(
                input_array: v14,
                source_row: v13 - 1,
                output_array: v14,
                dest_row: v13,
                num_rows: 1,
                num_cols);
              while ( ++v13 < max_v_samp_factor )
                jcopy_sample_rows(input_array: v26, source_row, output_array: v26, dest_row: v13, num_rows: 1, num_cols);
            }
            p_pre_process_data = (unsigned __int8 ***)&v27->pre_process_data;
            ++ci;
            v27 = (jpeg_c_prep_controller *)((char *)v27 + 4);
          }
          while ( ci < cinfo->num_components );
        }
        prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor;
      }
      v15 = out_row_group_ctr;
      if ( prep[6].pre_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor )
      {
        cinfo->downsample->downsample(
          a1: cinfo,
          a2: (unsigned __int8 ***)&prep[1],
          a3: 0,
          a4: output_buf,
          a5: *out_row_group_ctr);
        prep[6].pre_process_data = nullptr;
        ++*out_row_group_ctr;
      }
      if ( prep[6].start_pass == nullptr && *out_row_group_ctr < out_row_groups_avail )
      {
        comp_info = cinfo->comp_info;
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          p_v_samp_factor = &comp_info->v_samp_factor;
          in_row_ctra = (unsigned int *)&comp_info->v_samp_factor;
          do
          {
            v18 = *p_v_samp_factor * *v15;
            v19 = out_row_groups_avail * *p_v_samp_factor;
            v22 = 8 * p_v_samp_factor[4];
            in_rows_availa = output_buf[cia];
            v20 = v18;
            if ( v18 < v19 )
            {
              source_rowa = v18 - 1;
              jcopy_sample_rows(
                input_array: output_buf[cia],
                source_row: v18 - 1,
                output_array: output_buf[cia],
                dest_row: v18,
                num_rows: 1,
                num_cols: 8 * p_v_samp_factor[4]);
              while ( ++v20 < v19 )
                jcopy_sample_rows(
                  input_array: in_rows_availa,
                  source_row: source_rowa,
                  output_array: in_rows_availa,
                  dest_row: v20,
                  num_rows: 1,
                  num_cols: v22);
            }
            v15 = out_row_group_ctr;
            p_v_samp_factor = (int *)(in_row_ctra + 21);
            ++cia;
            in_row_ctra += 21;
          }
          while ( cia < cinfo->num_components );
        }
        *v15 = out_row_groups_avail;
        return;
      }
      if ( *in_row_ctr >= in_rows_avail )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434290
// Name: pre_process_context
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_context(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // ebx
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int max_v_samp_factor; // eax
  int v13; // edi
  int pre_process_data; // edi
  int buf_height; // [esp+8h] [ebp-18h]
  void (__cdecl *v16)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int); // [esp+Ch] [ebp-14h]
  int source_row; // [esp+10h] [ebp-10h]
  int numrows; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***numrowsa; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***v20; // [esp+18h] [ebp-8h]
  unsigned __int8 **v21; // [esp+18h] [ebp-8h]
  int dest_row; // [esp+1Ch] [ebp-4h]
  int dest_rowa; // [esp+1Ch] [ebp-4h]
  int ci; // [esp+28h] [ebp+8h]
  int cia; // [esp+28h] [ebp+8h]

  prep = cinfo->prep;
  buf_height = 3 * cinfo->max_v_samp_factor;
  while ( *out_row_group_ctr < out_row_groups_avail )
  {
    v9 = *in_row_ctr;
    if ( *in_row_ctr >= in_rows_avail )
    {
      if ( prep[6].start_pass != nullptr )
        return;
      if ( (int)prep[6].pre_process_data < (int)prep[7].pre_process_data )
      {
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          numrowsa = (unsigned __int8 ***)&prep[1];
          do
          {
            pre_process_data = (int)prep[6].pre_process_data;
            v16 = prep[7].pre_process_data;
            dest_rowa = cinfo->image_width;
            v21 = *numrowsa;
            if ( pre_process_data < (int)v16 )
            {
              source_row = pre_process_data - 1;
              jcopy_sample_rows(
                input_array: *numrowsa,
                source_row: pre_process_data - 1,
                output_array: *numrowsa,
                dest_row: pre_process_data,
                num_rows: 1,
                num_cols: dest_rowa);
              while ( ++pre_process_data < (int)v16 )
                jcopy_sample_rows(
                  input_array: v21,
                  source_row,
                  output_array: v21,
                  dest_row: pre_process_data,
                  num_rows: 1,
                  num_cols: dest_rowa);
            }
            ++numrowsa;
            ++cia;
          }
          while ( cia < cinfo->num_components );
        }
        prep[6].pre_process_data = prep[7].pre_process_data;
      }
    }
    else
    {
      v10 = (unsigned int)prep[6].pre_process_data;
      v11 = (unsigned int)prep[7].pre_process_data - v10;
      numrows = v11;
      if ( v11 >= in_rows_avail - v9 )
      {
        numrows = in_rows_avail - v9;
        v11 = in_rows_avail - v9;
      }
      cinfo->cconvert->color_convert(a1: cinfo, a2: &input_buf[v9], a3: (unsigned __int8 ***)&prep[1], a4: v10, a5: v11);
      if ( prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->image_height )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          max_v_samp_factor = cinfo->max_v_samp_factor;
          v20 = (unsigned __int8 ***)&prep[1];
          do
          {
            v13 = 1;
            if ( max_v_samp_factor >= 1 )
            {
              dest_row = -1;
              do
              {
                jcopy_sample_rows(
                  input_array: *v20,
                  source_row: 0,
                  output_array: *v20,
                  dest_row,
                  num_rows: 1,
                  num_cols: cinfo->image_width);
                max_v_samp_factor = cinfo->max_v_samp_factor;
                --dest_row;
                ++v13;
              }
              while ( v13 <= max_v_samp_factor );
            }
            ++v20;
            ++ci;
          }
          while ( ci < cinfo->num_components );
          v11 = numrows;
        }
      }
      *in_row_ctr += v11;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v11);
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v11);
    }
    if ( prep[6].pre_process_data == prep[7].pre_process_data )
    {
      cinfo->downsample->downsample(
        a1: cinfo,
        a2: (unsigned __int8 ***)&prep[1],
        a3: (unsigned int)prep[7].start_pass,
        a4: output_buf,
        a5: *out_row_group_ctr);
      ++*out_row_group_ctr;
      prep[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[7].start_pass
                                                                                + cinfo->max_v_samp_factor);
      if ( (int)prep[7].start_pass >= buf_height )
        prep[7].start_pass = nullptr;
      if ( (int)prep[6].pre_process_data >= buf_height )
        prep[6].pre_process_data = nullptr;
      prep[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + cinfo->max_v_samp_factor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434470
// Name: create_context_buffer
// Source: json
//------------------------------------------------------------------------------
void __usercall create_context_buffer(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_c_prep_controller *client_data; // ebx
  int mem; // esi
  int *v3; // ecx
  unsigned __int8 **v4; // ebx
  unsigned __int8 **v5; // ecx
  unsigned __int8 **v6; // eax
  int v7; // ebx
  unsigned __int8 *v8; // edx
  jpeg_c_prep_controller *v9; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  unsigned __int8 **true_buffer; // [esp+18h] [ebp-10h]
  unsigned __int8 **true_buffera; // [esp+18h] [ebp-10h]
  int *v13; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **fake_buffer; // [esp+20h] [ebp-8h]
  unsigned __int8 **v15; // [esp+24h] [ebp-4h]

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  mem = (int)cinfo[9].mem;
  fake_buffer = (unsigned __int8 **)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 20 * mem * (int)cinfo[2].client_data);
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 8);
    v13 = v3;
    v9 = client_data + 1;
    while ( 1 )
    {
      v4 = fake_buffer;
      true_buffer = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[9].err * v3[5] / *v3, a4: 3 * mem);
      memcpy(dst: (unsigned __int8 *)&fake_buffer[mem], src: (unsigned __int8 *)true_buffer, count: 12 * mem);
      if ( mem > 0 )
      {
        v5 = true_buffer;
        v6 = &fake_buffer[4 * mem];
        v15 = &true_buffer[2 * mem];
        v7 = (char *)fake_buffer - (char *)true_buffer;
        for ( true_buffera = (unsigned __int8 **)mem;
              true_buffera != nullptr;
              true_buffera = (unsigned __int8 **)((char *)true_buffera - 1) )
        {
          v8 = *v15++;
          *(unsigned __int8 **)((char *)v5 + v7) = v8;
          *v6++ = *v5++;
        }
        v4 = fake_buffer;
      }
      v13 += 21;
      v9->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))&v4[mem];
      fake_buffer = &v4[5 * mem];
      ++ci;
      v9 = (jpeg_c_prep_controller *)((char *)v9 + 4);
      if ( ci >= (int)cinfo[2].client_data )
        break;
      v3 = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434580
// Name: _jinit_c_prep_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_prep_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_prep_controller *v2; // eax
  int *v3; // esi
  jpeg_c_prep_controller *v4; // ebx
  int ci; // [esp+10h] [ebp+Ch]

  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  v2 = (jpeg_c_prep_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_prep;
  if ( LOBYTE(cinfo[14].mem->alloc_sarray) != 0 )
  {
    v2->pre_process_data = pre_process_context;
    create_context_buffer(cinfo);
  }
  else
  {
    v2->pre_process_data = pre_process_data;
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v3 = (int *)(cinfo[2].global_state + 8);
      v4 = v2 + 1;
      do
      {
        v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: 8 * (int)cinfo[9].err * v3[5] / *v3,
                                                                                 a4: cinfo[9].mem);
        v4 = (jpeg_c_prep_controller *)((char *)v4 + 4);
        v3 += 21;
        ++ci;
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00420E60
// Name: start_pass_prep
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_prep(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_prep_controller *client_data; // esi

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  client_data[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo[1].progress;
  client_data[6].pre_process_data = nullptr;
  client_data[7].start_pass = nullptr;
  client_data[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))(2 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x00420EB0
// Name: pre_process_data
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_data(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // edi
  unsigned int v9; // esi
  int v10; // eax
  bool v11; // zf
  unsigned __int8 ***p_pre_process_data; // eax
  int v13; // esi
  unsigned __int8 **v14; // eax
  unsigned int *v15; // esi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int max_v_samp_factor; // [esp+8h] [ebp-14h]
  unsigned int v22; // [esp+8h] [ebp-14h]
  int source_row; // [esp+Ch] [ebp-10h]
  int source_rowa; // [esp+Ch] [ebp-10h]
  unsigned int num_cols; // [esp+10h] [ebp-Ch]
  unsigned __int8 **v26; // [esp+14h] [ebp-8h]
  jpeg_c_prep_controller *v27; // [esp+18h] [ebp-4h]
  int ci; // [esp+24h] [ebp+8h]
  int cia; // [esp+24h] [ebp+8h]
  unsigned int *in_row_ctra; // [esp+2Ch] [ebp+10h]
  unsigned __int8 **in_rows_availa; // [esp+30h] [ebp+14h]

  prep = cinfo->prep;
  if ( *in_row_ctr < in_rows_avail )
  {
    while ( *out_row_group_ctr < out_row_groups_avail )
    {
      v9 = cinfo->max_v_samp_factor - (unsigned int)prep[6].pre_process_data;
      if ( v9 >= in_rows_avail - *in_row_ctr )
        v9 = in_rows_avail - *in_row_ctr;
      cinfo->cconvert->color_convert(
        a1: cinfo,
        a2: &input_buf[*in_row_ctr],
        a3: (unsigned __int8 ***)&prep[1],
        a4: (unsigned int)prep[6].pre_process_data,
        a5: v9);
      *in_row_ctr += v9;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v9);
      v10 = (int)prep[6].pre_process_data;
      v11 = prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v9;
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v9);
      if ( v11 && v10 < cinfo->max_v_samp_factor )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          p_pre_process_data = (unsigned __int8 ***)&prep[1];
          v27 = prep + 1;
          do
          {
            v13 = (int)prep[6].pre_process_data;
            v14 = *p_pre_process_data;
            max_v_samp_factor = cinfo->max_v_samp_factor;
            num_cols = cinfo->image_width;
            v26 = v14;
            if ( v13 < max_v_samp_factor )
            {
              source_row = v13 - 1;
              jcopy_sample_rows(
                input_array: v14,
                source_row: v13 - 1,
                output_array: v14,
                dest_row: v13,
                num_rows: 1,
                num_cols);
              while ( ++v13 < max_v_samp_factor )
                jcopy_sample_rows(input_array: v26, source_row, output_array: v26, dest_row: v13, num_rows: 1, num_cols);
            }
            p_pre_process_data = (unsigned __int8 ***)&v27->pre_process_data;
            ++ci;
            v27 = (jpeg_c_prep_controller *)((char *)v27 + 4);
          }
          while ( ci < cinfo->num_components );
        }
        prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor;
      }
      v15 = out_row_group_ctr;
      if ( prep[6].pre_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))cinfo->max_v_samp_factor )
      {
        cinfo->downsample->downsample(
          a1: cinfo,
          a2: (unsigned __int8 ***)&prep[1],
          a3: 0,
          a4: output_buf,
          a5: *out_row_group_ctr);
        prep[6].pre_process_data = nullptr;
        ++*out_row_group_ctr;
      }
      if ( prep[6].start_pass == nullptr && *out_row_group_ctr < out_row_groups_avail )
      {
        comp_info = cinfo->comp_info;
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          p_v_samp_factor = &comp_info->v_samp_factor;
          in_row_ctra = (unsigned int *)&comp_info->v_samp_factor;
          do
          {
            v18 = *p_v_samp_factor * *v15;
            v19 = out_row_groups_avail * *p_v_samp_factor;
            v22 = 8 * p_v_samp_factor[4];
            in_rows_availa = output_buf[cia];
            v20 = v18;
            if ( v18 < v19 )
            {
              source_rowa = v18 - 1;
              jcopy_sample_rows(
                input_array: output_buf[cia],
                source_row: v18 - 1,
                output_array: output_buf[cia],
                dest_row: v18,
                num_rows: 1,
                num_cols: 8 * p_v_samp_factor[4]);
              while ( ++v20 < v19 )
                jcopy_sample_rows(
                  input_array: in_rows_availa,
                  source_row: source_rowa,
                  output_array: in_rows_availa,
                  dest_row: v20,
                  num_rows: 1,
                  num_cols: v22);
            }
            v15 = out_row_group_ctr;
            p_v_samp_factor = (int *)(in_row_ctra + 21);
            ++cia;
            in_row_ctra += 21;
          }
          while ( cia < cinfo->num_components );
        }
        *v15 = out_row_groups_avail;
        return;
      }
      if ( *in_row_ctr >= in_rows_avail )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421090
// Name: pre_process_context
// Source: json
//------------------------------------------------------------------------------
void __cdecl pre_process_context(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail,
        unsigned __int8 ***output_buf,
        unsigned int *out_row_group_ctr,
        unsigned int out_row_groups_avail)
{
  jpeg_c_prep_controller *prep; // ebx
  int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  int max_v_samp_factor; // eax
  int v13; // edi
  int pre_process_data; // edi
  int buf_height; // [esp+8h] [ebp-18h]
  void (__cdecl *v16)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int); // [esp+Ch] [ebp-14h]
  int source_row; // [esp+10h] [ebp-10h]
  int numrows; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***numrowsa; // [esp+14h] [ebp-Ch]
  unsigned __int8 ***v20; // [esp+18h] [ebp-8h]
  unsigned __int8 **v21; // [esp+18h] [ebp-8h]
  int dest_row; // [esp+1Ch] [ebp-4h]
  int dest_rowa; // [esp+1Ch] [ebp-4h]
  int ci; // [esp+28h] [ebp+8h]
  int cia; // [esp+28h] [ebp+8h]

  prep = cinfo->prep;
  buf_height = 3 * cinfo->max_v_samp_factor;
  while ( *out_row_group_ctr < out_row_groups_avail )
  {
    v9 = *in_row_ctr;
    if ( *in_row_ctr >= in_rows_avail )
    {
      if ( prep[6].start_pass != nullptr )
        return;
      if ( (int)prep[6].pre_process_data < (int)prep[7].pre_process_data )
      {
        cia = 0;
        if ( cinfo->num_components > 0 )
        {
          numrowsa = (unsigned __int8 ***)&prep[1];
          do
          {
            pre_process_data = (int)prep[6].pre_process_data;
            v16 = prep[7].pre_process_data;
            dest_rowa = cinfo->image_width;
            v21 = *numrowsa;
            if ( pre_process_data < (int)v16 )
            {
              source_row = pre_process_data - 1;
              jcopy_sample_rows(
                input_array: *numrowsa,
                source_row: pre_process_data - 1,
                output_array: *numrowsa,
                dest_row: pre_process_data,
                num_rows: 1,
                num_cols: dest_rowa);
              while ( ++pre_process_data < (int)v16 )
                jcopy_sample_rows(
                  input_array: v21,
                  source_row,
                  output_array: v21,
                  dest_row: pre_process_data,
                  num_rows: 1,
                  num_cols: dest_rowa);
            }
            ++numrowsa;
            ++cia;
          }
          while ( cia < cinfo->num_components );
        }
        prep[6].pre_process_data = prep[7].pre_process_data;
      }
    }
    else
    {
      v10 = (unsigned int)prep[6].pre_process_data;
      v11 = (unsigned int)prep[7].pre_process_data - v10;
      numrows = v11;
      if ( v11 >= in_rows_avail - v9 )
      {
        numrows = in_rows_avail - v9;
        v11 = in_rows_avail - v9;
      }
      cinfo->cconvert->color_convert(a1: cinfo, a2: &input_buf[v9], a3: (unsigned __int8 ***)&prep[1], a4: v10, a5: v11);
      if ( prep[6].start_pass == (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->image_height )
      {
        ci = 0;
        if ( cinfo->num_components > 0 )
        {
          max_v_samp_factor = cinfo->max_v_samp_factor;
          v20 = (unsigned __int8 ***)&prep[1];
          do
          {
            v13 = 1;
            if ( max_v_samp_factor >= 1 )
            {
              dest_row = -1;
              do
              {
                jcopy_sample_rows(
                  input_array: *v20,
                  source_row: 0,
                  output_array: *v20,
                  dest_row,
                  num_rows: 1,
                  num_cols: cinfo->image_width);
                max_v_samp_factor = cinfo->max_v_samp_factor;
                --dest_row;
                ++v13;
              }
              while ( v13 <= max_v_samp_factor );
            }
            ++v20;
            ++ci;
          }
          while ( ci < cinfo->num_components );
          v11 = numrows;
        }
      }
      *in_row_ctr += v11;
      prep[6].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + v11);
      prep[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[6].start_pass - v11);
    }
    if ( prep[6].pre_process_data == prep[7].pre_process_data )
    {
      cinfo->downsample->downsample(
        a1: cinfo,
        a2: (unsigned __int8 ***)&prep[1],
        a3: (unsigned int)prep[7].start_pass,
        a4: output_buf,
        a5: *out_row_group_ctr);
      ++*out_row_group_ctr;
      prep[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)prep[7].start_pass
                                                                                + cinfo->max_v_samp_factor);
      if ( (int)prep[7].start_pass >= buf_height )
        prep[7].start_pass = nullptr;
      if ( (int)prep[6].pre_process_data >= buf_height )
        prep[6].pre_process_data = nullptr;
      prep[7].pre_process_data = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int, unsigned __int8 ***, unsigned int *, unsigned int))((char *)prep[6].pre_process_data + cinfo->max_v_samp_factor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421270
// Name: create_context_buffer
// Source: json
//------------------------------------------------------------------------------
void __usercall create_context_buffer(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_c_prep_controller *client_data; // ebx
  int mem; // esi
  int *v3; // ecx
  unsigned __int8 **v4; // ebx
  unsigned __int8 **v5; // ecx
  unsigned __int8 **v6; // eax
  int v7; // ebx
  unsigned __int8 *v8; // edx
  jpeg_c_prep_controller *v9; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  unsigned __int8 **true_buffer; // [esp+18h] [ebp-10h]
  unsigned __int8 **true_buffera; // [esp+18h] [ebp-10h]
  int *v13; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **fake_buffer; // [esp+20h] [ebp-8h]
  unsigned __int8 **v15; // [esp+24h] [ebp-4h]

  client_data = (jpeg_c_prep_controller *)cinfo[13].client_data;
  mem = (int)cinfo[9].mem;
  fake_buffer = (unsigned __int8 **)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 20 * mem * (int)cinfo[2].client_data);
  ci = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v3 = (int *)(cinfo[2].global_state + 8);
    v13 = v3;
    v9 = client_data + 1;
    while ( 1 )
    {
      v4 = fake_buffer;
      true_buffer = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[9].err * v3[5] / *v3, a4: 3 * mem);
      memcpy(dst: (unsigned __int8 *)&fake_buffer[mem], src: (unsigned __int8 *)true_buffer, count: 12 * mem);
      if ( mem > 0 )
      {
        v5 = true_buffer;
        v6 = &fake_buffer[4 * mem];
        v15 = &true_buffer[2 * mem];
        v7 = (char *)fake_buffer - (char *)true_buffer;
        for ( true_buffera = (unsigned __int8 **)mem;
              true_buffera != nullptr;
              true_buffera = (unsigned __int8 **)((char *)true_buffera - 1) )
        {
          v8 = *v15++;
          *(unsigned __int8 **)((char *)v5 + v7) = v8;
          *v6++ = *v5++;
        }
        v4 = fake_buffer;
      }
      v13 += 21;
      v9->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))&v4[mem];
      fake_buffer = &v4[5 * mem];
      ++ci;
      v9 = (jpeg_c_prep_controller *)((char *)v9 + 4);
      if ( ci >= (int)cinfo[2].client_data )
        break;
      v3 = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421380
// Name: _jinit_c_prep_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_prep_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_prep_controller *v2; // eax
  int *v3; // esi
  jpeg_c_prep_controller *v4; // ebx
  int ci; // [esp+10h] [ebp+Ch]

  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  v2 = (jpeg_c_prep_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_prep;
  if ( LOBYTE(cinfo[14].mem->alloc_sarray) != 0 )
  {
    v2->pre_process_data = pre_process_context;
    create_context_buffer(cinfo);
  }
  else
  {
    v2->pre_process_data = pre_process_data;
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v3 = (int *)(cinfo[2].global_state + 8);
      v4 = v2 + 1;
      do
      {
        v4->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: 8 * (int)cinfo[9].err * v3[5] / *v3,
                                                                                 a4: cinfo[9].mem);
        v4 = (jpeg_c_prep_controller *)((char *)v4 + 4);
        v3 += 21;
        ++ci;
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
}

} // namespace vxconsole_ps3
