// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdcoefct.c
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009EA0
// Name: start_input_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_input_pass(jpeg_common_struct *cinfo)
{
  per_scan_setup(cinfo);
  latch_quant_tables(cinfo);
  cinfo[17].err->error_exit(a1: cinfo);
  cinfo[16].progress->progress_monitor(a1: cinfo);
  **(_DWORD **)&cinfo[16].is_decompressor = cinfo[16].progress->pass_counter;
}

//------------------------------------------------------------------------------
// Address: 0x1000D680
// Name: start_input_pass_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_input_pass_0(jpeg_decompress_struct *cinfo)
{
  jpeg_d_coef_controller *coef; // eax
  bool v2; // cc
  jpeg_component_info *v3; // ecx
  void (__cdecl *last_row_height)(jpeg_decompress_struct *); // ecx

  coef = cinfo->coef;
  v2 = cinfo->comps_in_scan <= 1;
  cinfo->input_iMCU_row = 0;
  if ( v2 )
  {
    v3 = cinfo->cur_comp_info[0];
    if ( cinfo->total_iMCU_rows == 1 )
      last_row_height = (void (__cdecl *)(jpeg_decompress_struct *))v3->last_row_height;
    else
      last_row_height = (void (__cdecl *)(jpeg_decompress_struct *))v3->v_samp_factor;
    coef[1].start_output_pass = last_row_height;
    coef[1].start_input_pass = nullptr;
    coef[1].consume_data = nullptr;
  }
  else
  {
    coef[1].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))1;
    coef[1].start_input_pass = nullptr;
    coef[1].consume_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D6E0
// Name: decompress_onepass
// Source: json
//------------------------------------------------------------------------------
int __cdecl decompress_onepass(jpeg_decompress_struct *cinfo, unsigned __int8 ***output_buf)
{
  jpeg_decompress_struct *v2; // ebx
  jpeg_d_coef_controller *p_pub; // ecx
  int (__cdecl *consume_data)(jpeg_decompress_struct *); // eax
  unsigned int v5; // edx
  void (__cdecl *start_input_pass)(jpeg_decompress_struct *); // edi
  __int16 (**p_decompress_data)[64]; // esi
  int v8; // ecx
  jpeg_component_info *v9; // esi
  int component_index; // eax
  int last_col_width; // edx
  int v12; // edi
  unsigned __int8 **v13; // edx
  int v14; // eax
  __int16 **v15; // ebx
  unsigned int v16; // ecx
  unsigned int total_iMCU_rows; // edx
  jpeg_d_coef_controller *v18; // eax
  bool v20; // cf
  jpeg_component_info *v21; // edx
  void (__cdecl *v_samp_factor)(jpeg_decompress_struct *); // ecx
  unsigned int start_col; // [esp+Ch] [ebp-38h]
  void (__cdecl *inverse_DCT)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+10h] [ebp-34h]
  unsigned int last_iMCU_row; // [esp+14h] [ebp-30h]
  int ci; // [esp+18h] [ebp-2Ch]
  int yindex; // [esp+1Ch] [ebp-28h]
  int i; // [esp+20h] [ebp-24h]
  int useful_width; // [esp+24h] [ebp-20h]
  unsigned int last_MCU_col; // [esp+28h] [ebp-1Ch]
  jpeg_component_info **cur_comp_info; // [esp+2Ch] [ebp-18h]
  unsigned __int8 **output_ptr; // [esp+30h] [ebp-14h]
  int blkn; // [esp+34h] [ebp-10h]
  my_coef_controller *coef; // [esp+38h] [ebp-Ch]
  unsigned int MCU_col_num; // [esp+3Ch] [ebp-8h]
  int yoffset; // [esp+40h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  consume_data = p_pub[1].consume_data;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)consume_data;
  if ( (int)consume_data >= (int)p_pub[1].start_output_pass )
  {
LABEL_23:
    v16 = ++v2->input_iMCU_row;
    total_iMCU_rows = v2->total_iMCU_rows;
    ++v2->output_iMCU_row;
    if ( v16 >= total_iMCU_rows )
    {
      v2->inputctl->finish_input_pass(a1: v2);
      return 4;
    }
    else
    {
      v18 = v2->coef;
      if ( v2->comps_in_scan <= 1 )
      {
        v20 = v16 < total_iMCU_rows - 1;
        v21 = v2->cur_comp_info[0];
        if ( v20 )
          v_samp_factor = (void (__cdecl *)(jpeg_decompress_struct *))v21->v_samp_factor;
        else
          v_samp_factor = (void (__cdecl *)(jpeg_decompress_struct *))v21->last_row_height;
        v18[1].start_output_pass = v_samp_factor;
        v18[1].start_input_pass = nullptr;
        v18[1].consume_data = nullptr;
        return 3;
      }
      else
      {
        v18[1].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))1;
        v18[1].start_input_pass = nullptr;
        v18[1].consume_data = nullptr;
        return 3;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      start_input_pass = p_pub[1].start_input_pass;
      MCU_col_num = (unsigned int)start_input_pass;
      if ( (unsigned int)start_input_pass <= v5 )
        break;
LABEL_22:
      consume_data = (int (__cdecl *)(jpeg_decompress_struct *))((char *)consume_data + 1);
      p_pub[1].start_input_pass = nullptr;
      yoffset = (int)consume_data;
      if ( (int)consume_data >= (int)p_pub[1].start_output_pass )
        goto LABEL_23;
    }
    while ( 1 )
    {
      p_decompress_data = (__int16 (**)[64])&p_pub[1].decompress_data;
      jzero_far(target: p_pub[1].decompress_data, bytestozero: v2->blocks_in_MCU << 7);
      if ( v2->entropy->decode_mcu(a1: v2, a2: p_decompress_data) == 0 )
        break;
      v8 = 0;
      blkn = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        do
        {
          v9 = *cur_comp_info;
          if ( (*cur_comp_info)->component_needed != 0 )
          {
            component_index = v9->component_index;
            inverse_DCT = v2->idct->inverse_DCT[component_index];
            if ( (unsigned int)start_input_pass >= last_MCU_col )
              last_col_width = v9->last_col_width;
            else
              last_col_width = v9->MCU_width;
            v12 = MCU_col_num * v9->MCU_sample_width;
            useful_width = last_col_width;
            v13 = &output_buf[component_index][yoffset * v9->DCT_scaled_size];
            v14 = 0;
            output_ptr = v13;
            start_col = v12;
            for ( yindex = 0; v14 < v9->MCU_height; yindex = v14 )
            {
              if ( (v2->input_iMCU_row < last_iMCU_row || v14 + yoffset < v9->last_row_height) && useful_width > 0 )
              {
                v15 = (__int16 **)&coef->MCU_buffer[v8];
                for ( i = useful_width; i != 0; --i )
                {
                  inverse_DCT(a1: cinfo, a2: v9, a3: *v15, a4: output_ptr, a5: v12);
                  v12 += v9->DCT_scaled_size;
                  ++v15;
                }
                v12 = start_col;
                v8 = blkn;
                v14 = yindex;
              }
              v8 += v9->MCU_width;
              ++v14;
              v2 = cinfo;
              blkn = v8;
              output_ptr += v9->DCT_scaled_size;
            }
          }
          else
          {
            v8 += v9->MCU_blocks;
            blkn = v8;
          }
          ++cur_comp_info;
          start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))MCU_col_num;
          ++ci;
        }
        while ( ci < v2->comps_in_scan );
      }
      p_pub = &coef->pub;
      start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))((char *)start_input_pass + 1);
      MCU_col_num = (unsigned int)start_input_pass;
      if ( (unsigned int)start_input_pass > last_MCU_col )
      {
        consume_data = (int (__cdecl *)(jpeg_decompress_struct *))yoffset;
        v5 = last_MCU_col;
        goto LABEL_22;
      }
    }
    coef->MCU_ctr = (unsigned int)start_input_pass;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D940
// Name: consume_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl consume_data(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // esi
  my_coef_controller *progress; // ebx
  int v3; // edi
  __int16 (**v4)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int MCU_ctr; // edi
  int v7; // ebx
  jpeg_progress_mgr *v8; // edi
  int v9; // ecx
  bool v10; // cc
  __int16 *v11; // eax
  int v12; // edx
  __int16 (**v13)[64]; // esi
  unsigned int global_state; // edx
  unsigned int v15; // ecx
  jpeg_progress_mgr *v16; // eax
  int v18; // ecx
  bool v19; // cf
  jpeg_progress_mgr *v20; // edx
  int completed_passes; // ecx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_progress_mgr **p_progress; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  progress = (my_coef_controller *)cinfo[16].progress;
  v3 = 0;
  coef = progress;
  if ( (int)cinfo[12].mem > 0 )
  {
    yoffset = (int)&cinfo[12].progress;
    do
    {
      progress = coef;
      v4 = cinfo->mem->access_virt_barray(
             a1: cinfo,
             a2: coef->whole_image[*(_DWORD *)(*(_DWORD *)yoffset + 4)],
             a3: *(_DWORD *)(*(_DWORD *)yoffset + 12) * (int)cinfo[5].progress,
             a4: *(_DWORD *)(*(_DWORD *)yoffset + 12),
             a5: 1);
      yoffset += 4;
      buffer[v3++] = v4;
    }
    while ( v3 < (int)cinfo[12].mem );
  }
  MCU_vert_offset = progress->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= progress->MCU_rows_per_iMCU_row )
  {
LABEL_21:
    global_state = v1[11].global_state;
    v15 = (unsigned int)++v1[5].progress;
    if ( v15 >= global_state )
    {
      (*(void (__cdecl **)(jpeg_common_struct *))(*(_DWORD *)&v1[16].is_decompressor + 12))(a1: v1);
      return 4;
    }
    else
    {
      v16 = v1[16].progress;
      if ( (int)v1[12].mem <= 1 )
      {
        v19 = v15 < global_state - 1;
        v20 = v1[12].progress;
        if ( v19 )
          completed_passes = v20->completed_passes;
        else
          completed_passes = v20[3].completed_passes;
        v16[1].pass_limit = completed_passes;
        v16[1].progress_monitor = nullptr;
        v16[1].pass_counter = 0;
        return 3;
      }
      else
      {
        v16[1].pass_limit = 1;
        v16[1].progress_monitor = nullptr;
        v16[1].pass_counter = 0;
        return 3;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      MCU_ctr = progress->MCU_ctr;
      MCU_col_num = MCU_ctr;
      if ( (jpeg_error_mgr *)MCU_ctr < v1[13].err )
        break;
LABEL_20:
      ++MCU_vert_offset;
      progress->MCU_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= progress->MCU_rows_per_iMCU_row )
        goto LABEL_21;
    }
    while ( 1 )
    {
      v7 = 0;
      ci = 0;
      if ( (int)v1[12].mem > 0 )
      {
        p_progress = &v1[12].progress;
        do
        {
          v8 = *p_progress;
          v9 = (*p_progress)[2].completed_passes;
          v10 = (*p_progress)[2].total_passes <= 0;
          yindex = 0;
          if ( !v10 )
          {
            v23 = (MCU_col_num * v9) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v11 = (__int16 *)((char *)*v28 + v23);
              v12 = 0;
              if ( v9 > 0 )
              {
                v13 = &coef->MCU_buffer[v7];
                do
                {
                  *v13 = (__int16 (*)[64])v11;
                  v9 = v8[2].completed_passes;
                  ++v12;
                  ++v7;
                  ++v13;
                  v11 += 64;
                }
                while ( v12 < v9 );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v8[2].total_passes );
          }
          ++p_progress;
          ++ci;
        }
        while ( ci < (int)v1[12].mem );
        MCU_ctr = MCU_col_num;
      }
      progress = coef;
      if ( ((unsigned __int8 (__cdecl *)(jpeg_common_struct *, __int16 (**)[64]))v1[17].err->emit_message)(
             a1: v1,
             a2: coef->MCU_buffer) == 0 )
        break;
      MCU_col_num = ++MCU_ctr;
      if ( (jpeg_error_mgr *)MCU_ctr >= v1[13].err )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v18 = yoffset;
    progress->MCU_ctr = MCU_ctr;
    progress->MCU_vert_offset = v18;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DB50
// Name: decompress_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl decompress_data(jpeg_decompress_struct *cinfo, unsigned __int8 ***output_buf)
{
  jpeg_decompress_struct *v2; // edi
  int input_scan_number; // eax
  int output_scan_number; // ecx
  int result; // eax
  int v6; // ebx
  jpeg_component_info *comp_info; // esi
  int v8; // ecx
  unsigned int width_in_blocks; // eax
  __int16 *v10; // ebx
  unsigned int v11; // edi
  void (__cdecl *inverse_DCT)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+4h] [ebp-24h]
  __int16 (**buffer)[64]; // [esp+8h] [ebp-20h]
  unsigned int last_iMCU_row; // [esp+Ch] [ebp-1Ch]
  my_coef_controller *coef; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  int block_row; // [esp+18h] [ebp-10h]
  unsigned int block_num; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **output_ptr; // [esp+20h] [ebp-8h]
  int block_rows; // [esp+24h] [ebp-4h]

  v2 = cinfo;
  coef = (my_coef_controller *)cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  while ( 1 )
  {
    input_scan_number = cinfo->input_scan_number;
    output_scan_number = cinfo->output_scan_number;
    if ( input_scan_number >= output_scan_number
      && (input_scan_number != output_scan_number || cinfo->input_iMCU_row > cinfo->output_iMCU_row) )
    {
      break;
    }
    result = cinfo->inputctl->consume_input(a1: cinfo);
    if ( result == 0 )
      return result;
  }
  v6 = 0;
  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    do
    {
      if ( comp_info->component_needed != 0 )
      {
        buffer = v2->mem->access_virt_barray(
                   a1: (jpeg_common_struct *)v2,
                   a2: coef->whole_image[v6],
                   a3: comp_info->v_samp_factor * v2->output_iMCU_row,
                   a4: comp_info->v_samp_factor,
                   a5: 0);
        if ( v2->output_iMCU_row >= last_iMCU_row )
        {
          block_rows = comp_info->height_in_blocks % comp_info->v_samp_factor;
          if ( block_rows == 0 )
            block_rows = comp_info->v_samp_factor;
        }
        else
        {
          block_rows = comp_info->v_samp_factor;
        }
        inverse_DCT = v2->idct->inverse_DCT[v6];
        v8 = 0;
        output_ptr = output_buf[v6];
        block_row = 0;
        if ( block_rows > 0 )
        {
          width_in_blocks = comp_info->width_in_blocks;
          do
          {
            v10 = (__int16 *)buffer[v8];
            v11 = 0;
            block_num = 0;
            if ( width_in_blocks != 0 )
            {
              do
              {
                inverse_DCT(a1: cinfo, a2: comp_info, a3: v10, a4: output_ptr, a5: v11);
                width_in_blocks = comp_info->width_in_blocks;
                v11 += comp_info->DCT_scaled_size;
                v10 += 64;
                ++block_num;
              }
              while ( block_num < width_in_blocks );
              v8 = block_row;
            }
            ++v8;
            output_ptr += comp_info->DCT_scaled_size;
            block_row = v8;
          }
          while ( v8 < block_rows );
          v6 = ci;
          v2 = cinfo;
        }
      }
      ++v6;
      ++comp_info;
      ci = v6;
    }
    while ( v6 < v2->num_components );
  }
  return 4 - (++v2->output_iMCU_row < v2->total_iMCU_rows);
}

//------------------------------------------------------------------------------
// Address: 0x1000DCD0
// Name: smoothing_ok
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall smoothing_ok@<al>(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_d_coef_controller *progress; // esi
  int (__cdecl *decompress_data)(jpeg_decompress_struct *, unsigned __int8 ***); // edx
  int v3; // esi
  JQUANT_TBL **p_realize_virt_arrays; // eax
  JQUANT_TBL *v5; // eax
  int *v6; // eax
  JQUANT_TBL **i; // [esp+4h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-8h]
  unsigned __int8 smoothing_useful; // [esp+Fh] [ebp-1h]

  progress = (jpeg_d_coef_controller *)cinfo[16].progress;
  smoothing_useful = 0;
  if ( LOBYTE(cinfo[8].progress) == 0 || cinfo[5].global_state == 0 )
    return 0;
  if ( progress[5].decompress_data == nullptr )
    progress[5].decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))cinfo->mem->alloc_small(
                                                                                                    a1: cinfo,
                                                                                                    a2: 1,
                                                                                                    a3: 24 * (int)cinfo[1].client_data);
  decompress_data = progress[5].decompress_data;
  v3 = 0;
  if ( (int)cinfo[1].client_data <= 0 )
    return smoothing_useful;
  p_realize_virt_arrays = (JQUANT_TBL **)&cinfo[8].mem[1].realize_virt_arrays;
  v9 = 0;
  for ( i = p_realize_virt_arrays; ; i += 21 )
  {
    v5 = *p_realize_virt_arrays;
    if ( v5 == nullptr )
      break;
    if ( v5->quantval[0] == 0 )
      break;
    if ( v5->quantval[1] == 0 )
      break;
    if ( v5->quantval[8] == 0 )
      break;
    if ( v5->quantval[16] == 0 )
      break;
    if ( v5->quantval[9] == 0 )
      break;
    if ( v5->quantval[2] == 0 )
      break;
    v6 = (int *)(v9 + cinfo[5].global_state);
    if ( *v6 < 0 )
      break;
    *((_DWORD *)decompress_data + 1) = v6[1];
    if ( v6[1] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 2) = v6[2];
    if ( v6[2] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 3) = v6[3];
    if ( v6[3] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 4) = v6[4];
    if ( v6[4] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 5) = v6[5];
    if ( v6[5] != 0 )
      smoothing_useful = 1;
    v9 += 256;
    ++v3;
    p_realize_virt_arrays = i + 21;
    decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))((char *)decompress_data + 24);
    if ( v3 >= (int)cinfo[1].client_data )
      return smoothing_useful;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE30
// Name: decompress_smooth_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl decompress_smooth_data(jpeg_common_struct *cinfo, unsigned __int8 ***output_buf)
{
  int mem; // ecx
  jpeg_input_controller *v3; // eax
  bool v4; // cc
  jpeg_component_info *v5; // ebx
  unsigned int v6; // esi
  unsigned int v_samp_factor; // ecx
  int v8; // eax
  jvirt_barray_control **v10; // esi
  __int16 (**v11)[64]; // eax
  unsigned __int16 *quantval; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  char *v18; // ecx
  void (__cdecl *v19)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // edx
  __int16 *v20; // edi
  __int16 *v21; // ecx
  __int16 *v22; // eax
  int v23; // esi
  int v24; // edi
  unsigned int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ebx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ebx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // edx
  int v40; // eax
  int v41; // ebx
  int v42; // eax
  int v43; // eax
  int v44; // ecx
  int v45; // edx
  int v46; // eax
  int v47; // edi
  int v48; // eax
  int v49; // eax
  int v50; // ecx
  int v51; // edx
  int v52; // eax
  int v53; // edi
  int v54; // eax
  int v55; // eax
  int DCT_scaled_size; // edx
  unsigned int v57; // [esp-14h] [ebp-11Ch]
  __int16 workspace[64]; // [esp+4h] [ebp-104h] BYREF
  int v59; // [esp+84h] [ebp-84h]
  void (__cdecl *inverse_DCT)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+88h] [ebp-80h]
  unsigned int last_iMCU_row; // [esp+8Ch] [ebp-7Ch]
  int Q11; // [esp+90h] [ebp-78h]
  my_coef_controller *coef; // [esp+94h] [ebp-74h]
  int Q10; // [esp+98h] [ebp-70h]
  int Q20; // [esp+9Ch] [ebp-6Ch]
  unsigned int last_block_column; // [esp+A0h] [ebp-68h]
  int Q01; // [esp+A4h] [ebp-64h]
  int DC7; // [esp+A8h] [ebp-60h]
  int Q02; // [esp+ACh] [ebp-5Ch]
  __int16 (**buffer)[64]; // [esp+B0h] [ebp-58h]
  unsigned int v71; // [esp+B4h] [ebp-54h]
  unsigned int output_col; // [esp+B8h] [ebp-50h]
  int ci; // [esp+BCh] [ebp-4Ch]
  __int16 *v74; // [esp+C0h] [ebp-48h]
  int block_row; // [esp+C4h] [ebp-44h]
  __int16 *v76; // [esp+C8h] [ebp-40h]
  unsigned __int8 **output_ptr; // [esp+CCh] [ebp-3Ch]
  int DC4; // [esp+D0h] [ebp-38h]
  int DC3; // [esp+D4h] [ebp-34h]
  unsigned int block_num; // [esp+D8h] [ebp-30h]
  jpeg_component_info *compptr; // [esp+DCh] [ebp-2Ch]
  int DC9; // [esp+E0h] [ebp-28h]
  jvirt_barray_control **whole_image; // [esp+E4h] [ebp-24h]
  int DC2; // [esp+E8h] [ebp-20h]
  int DC8; // [esp+ECh] [ebp-1Ch]
  int DC5; // [esp+F0h] [ebp-18h]
  int *coef_bits; // [esp+F4h] [ebp-14h]
  int Q00; // [esp+F8h] [ebp-10h]
  __int16 (*buffer_ptr)[64]; // [esp+FCh] [ebp-Ch]
  int block_rows; // [esp+100h] [ebp-8h]
  unsigned __int8 last_row; // [esp+106h] [ebp-2h]
  unsigned __int8 first_row; // [esp+107h] [ebp-1h]

  mem = (int)cinfo[5].mem;
  coef = (my_coef_controller *)cinfo[16].progress;
  last_iMCU_row = cinfo[11].global_state - 1;
  if ( mem <= (int)cinfo[5].client_data )
  {
    do
    {
      v3 = *(jpeg_input_controller **)&cinfo[16].is_decompressor;
      if ( v3->eoi_reached != 0
        || cinfo[5].mem == cinfo[5].client_data
        && __PAIR64__(cinfo[5].progress, cinfo[15].mem) >= __PAIR64__(*(_DWORD *)&cinfo[5].is_decompressor, 1)
        && cinfo[5].progress != (jpeg_progress_mgr *)(*(_DWORD *)&cinfo[5].is_decompressor + (cinfo[15].mem == nullptr)) )
      {
        break;
      }
      if ( v3->consume_input(a1: (jpeg_decompress_struct *)cinfo) == 0 )
        return 0;
    }
    while ( (int)cinfo[5].mem <= (int)cinfo[5].client_data );
  }
  v4 = (int)cinfo[1].client_data <= 0;
  v5 = (jpeg_component_info *)cinfo[8].mem;
  ci = 0;
  compptr = v5;
  if ( !v4 )
  {
    v71 = 0;
    whole_image = coef->whole_image;
    v59 = -72 - (_DWORD)coef;
    do
    {
      if ( v5->component_needed != 0 )
      {
        v6 = *(_DWORD *)&cinfo[5].is_decompressor;
        v_samp_factor = v5->v_samp_factor;
        if ( v6 >= last_iMCU_row )
        {
          v8 = v5->height_in_blocks % v_samp_factor;
          block_rows = v8;
          if ( v8 == 0 )
          {
            v8 = v_samp_factor;
            block_rows = v_samp_factor;
          }
          last_row = 1;
        }
        else
        {
          block_rows = v5->v_samp_factor;
          v8 = 2 * v_samp_factor;
          last_row = 0;
        }
        if ( v6 != 0 )
        {
          v57 = v_samp_factor * (v6 - 1);
          v10 = whole_image;
          v11 = &cinfo->mem->access_virt_barray(a1: cinfo, a2: *whole_image, a3: v57, a4: v_samp_factor + v8, a5: 0)[v5->v_samp_factor];
          first_row = 0;
        }
        else
        {
          v10 = whole_image;
          v11 = cinfo->mem->access_virt_barray(a1: cinfo, a2: *whole_image, a3: 0, a4: v8, a5: 0);
          first_row = 1;
        }
        buffer = v11;
        coef_bits = &coef->coef_bits_latch[v71 / 4];
        quantval = v5->quant_table->quantval;
        v13 = quantval[1];
        Q00 = *quantval;
        v14 = quantval[8];
        Q01 = v13;
        v15 = quantval[16];
        Q10 = v14;
        v16 = quantval[9];
        v17 = quantval[2];
        Q20 = v15;
        v18 = (char *)cinfo[17].mem + v59;
        Q11 = v16;
        v19 = *(void (__cdecl **)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int))((char *)v10 + (_DWORD)v18 + 4);
        Q02 = v17;
        inverse_DCT = v19;
        output_ptr = output_buf[ci];
        for ( block_row = 0; block_row < block_rows; ++block_row )
        {
          v20 = (__int16 *)buffer[block_row];
          buffer_ptr = (__int16 (*)[64])v20;
          if ( first_row == 0 || (v21 = v20, block_row != 0) )
            v21 = (__int16 *)buffer[block_row - 1];
          if ( last_row == 0 || (v22 = v20, block_row != block_rows - 1) )
            v22 = (__int16 *)buffer[block_row + 1];
          v23 = *(__int16 *)buffer_ptr;
          v24 = *v21;
          DC9 = *v22;
          DC8 = DC9;
          DC7 = DC9;
          v25 = v5->width_in_blocks - 1;
          DC3 = v24;
          DC2 = v24;
          DC5 = v23;
          DC4 = v23;
          output_col = 0;
          last_block_column = v25;
          block_num = 0;
          v74 = v21 + 64;
          v76 = v22 + 64;
          do
          {
            jcopy_block_row(input_row: buffer_ptr, output_row: (__int16 (*)[64])workspace, num_blocks: 1u);
            if ( block_num < last_block_column )
            {
              v23 = (*buffer_ptr)[64];
              DC3 = *v74;
              DC9 = *v76;
            }
            v26 = coef_bits[1];
            if ( v26 != 0 && workspace[1] == 0 )
            {
              v27 = Q01 << 7;
              v28 = Q01 << 8;
              v29 = 36 * Q00 * (DC4 - v23);
              if ( ((18 * Q00 * (DC4 - v23)) & 0x40000000) != 0 )
              {
                v31 = (v27 - v29) / v28;
                if ( v26 > 0 && v31 >= 1 << v26 )
                  v31 = (1 << v26) - 1;
                v30 = -v31;
              }
              else
              {
                v30 = (v29 + v27) / v28;
                if ( v26 > 0 && v30 >= 1 << v26 )
                  v30 = (1 << v26) - 1;
              }
              v5 = compptr;
              workspace[1] = v30;
            }
            v32 = coef_bits[2];
            if ( v32 != 0 && workspace[8] == 0 )
            {
              v33 = Q10 << 7;
              v34 = Q10 << 8;
              v35 = 36 * Q00 * (DC2 - DC8);
              if ( ((18 * Q00 * (DC2 - DC8)) & 0x40000000) != 0 )
              {
                v37 = (v33 - v35) / v34;
                if ( v32 > 0 && v37 >= 1 << v32 )
                  v37 = (1 << v32) - 1;
                v36 = -v37;
              }
              else
              {
                v36 = (v35 + v33) / v34;
                if ( v32 > 0 && v36 >= 1 << v32 )
                  v36 = (1 << v32) - 1;
              }
              v5 = compptr;
              workspace[8] = v36;
            }
            v38 = coef_bits[3];
            if ( v38 != 0 && workspace[16] == 0 )
            {
              v39 = 9 * Q00 * (DC2 + DC8 - 2 * DC5);
              v40 = Q20 << 7;
              v41 = Q20 << 8;
              if ( v39 < 0 )
              {
                v43 = (v40 - v39) / v41;
                if ( v38 > 0 && v43 >= 1 << v38 )
                  v43 = (1 << v38) - 1;
                v42 = -v43;
              }
              else
              {
                v42 = (v39 + v40) / v41;
                if ( v38 > 0 && v42 >= 1 << v38 )
                  v42 = (1 << v38) - 1;
              }
              v5 = compptr;
              workspace[16] = v42;
            }
            v44 = coef_bits[4];
            if ( v44 != 0 && workspace[9] == 0 )
            {
              v45 = 5 * Q00 * (v24 + DC9 - DC7 - DC3);
              v46 = Q11 << 7;
              v47 = Q11 << 8;
              if ( v45 < 0 )
              {
                v49 = (v46 - v45) / v47;
                if ( v44 > 0 && v49 >= 1 << v44 )
                  v49 = (1 << v44) - 1;
                v48 = -v49;
              }
              else
              {
                v48 = (v45 + v46) / v47;
                if ( v44 > 0 && v48 >= 1 << v44 )
                  v48 = (1 << v44) - 1;
              }
              workspace[9] = v48;
            }
            v50 = coef_bits[5];
            if ( v50 != 0 && workspace[2] == 0 )
            {
              v51 = 9 * Q00 * (DC4 + v23 - 2 * DC5);
              v52 = Q02 << 7;
              v53 = Q02 << 8;
              if ( v51 < 0 )
              {
                v55 = (v52 - v51) / v53;
                if ( v50 > 0 && v55 >= 1 << v50 )
                  v55 = (1 << v50) - 1;
                v54 = -v55;
              }
              else
              {
                v54 = (v51 + v52) / v53;
                if ( v50 > 0 && v54 >= 1 << v50 )
                  v54 = (1 << v50) - 1;
              }
              workspace[2] = v54;
            }
            inverse_DCT(a1: (jpeg_decompress_struct *)cinfo, a2: v5, a3: workspace, a4: output_ptr, a5: output_col);
            v24 = DC2;
            DC7 = DC8;
            ++buffer_ptr;
            v74 += 64;
            v76 += 64;
            DC4 = DC5;
            DCT_scaled_size = v5->DCT_scaled_size;
            output_col += DCT_scaled_size;
            DC2 = DC3;
            DC5 = v23;
            DC8 = DC9;
            ++block_num;
          }
          while ( block_num <= last_block_column );
          output_ptr += DCT_scaled_size;
        }
      }
      v71 += 24;
      ++whole_image;
      ++v5;
      ++ci;
      compptr = v5;
    }
    while ( ci < (int)cinfo[1].client_data );
  }
  return 4 - (++*(_DWORD *)&cinfo[5].is_decompressor < cinfo[11].global_state);
}

//------------------------------------------------------------------------------
// Address: 0x1000E370
// Name: start_output_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_output_pass(jpeg_common_struct *cinfo)
{
  jpeg_d_coef_controller *progress; // esi

  progress = (jpeg_d_coef_controller *)cinfo[16].progress;
  if ( progress->coef_arrays != nullptr )
  {
    if ( BYTE1(cinfo[3].err) != 0 && smoothing_ok(cinfo) != 0 )
    {
      progress->decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))decompress_smooth_data;
      *(_DWORD *)&cinfo[5].is_decompressor = 0;
      return;
    }
    progress->decompress_data = decompress_data;
  }
  *(_DWORD *)&cinfo[5].is_decompressor = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E3C0
// Name: _jinit_d_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_d_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_d_coef_controller *p_pub; // ebx
  int *p_alloc_barray; // edi
  int v5; // ecx
  jpeg_memory_mgr *mem; // ebx
  int v7; // eax
  char *v8; // eax
  int v9; // [esp-8h] [ebp-18h]
  unsigned int v10; // [esp-4h] [ebp-14h]
  my_coef_controller *coef; // [esp+Ch] [ebp-4h]
  jpeg_decompress_struct *cinfoa; // [esp+18h] [ebp+8h]
  int ci; // [esp+1Ch] [ebp+Ch]

  p_pub = (jpeg_d_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 116);
  cinfo[16].progress = (jpeg_progress_mgr *)p_pub;
  coef = (my_coef_controller *)p_pub;
  p_pub->start_input_pass = start_input_pass_0;
  p_pub->start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))start_output_pass;
  p_pub[5].decompress_data = nullptr;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[1].client_data > 0 )
    {
      p_alloc_barray = (int *)&cinfo[8].mem->alloc_barray;
      cinfoa = (jpeg_decompress_struct *)&p_pub[3].decompress_data;
      do
      {
        v5 = *p_alloc_barray;
        if ( LOBYTE(cinfo[8].progress) != 0 )
          v5 *= 3;
        mem = cinfo->mem;
        v10 = v5;
        v9 = jround_up(a: p_alloc_barray[5], b: *p_alloc_barray);
        v7 = jround_up(a: p_alloc_barray[4], b: *(p_alloc_barray - 1));
        cinfoa->err = (jpeg_error_mgr *)mem->request_virt_barray(a1: cinfo, a2: 1, a3: 1u, a4: v7, a5: v9, a6: v10);
        p_alloc_barray += 21;
        ++ci;
        cinfoa = (jpeg_decompress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[1].client_data );
      p_pub = &coef->pub;
    }
    p_pub->consume_data = (int (__cdecl *)(jpeg_decompress_struct *))consume_data;
    p_pub->decompress_data = decompress_data;
    p_pub->coef_arrays = (jvirt_barray_control **)&p_pub[3].decompress_data;
  }
  else
  {
    v8 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    p_pub[1].coef_arrays = (jvirt_barray_control **)(v8 + 128);
    p_pub[2].start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 256);
    p_pub[2].consume_data = (int (__cdecl *)(jpeg_decompress_struct *))(v8 + 384);
    p_pub[2].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 512);
    p_pub[2].decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))(v8 + 640);
    p_pub[2].coef_arrays = (jvirt_barray_control **)(v8 + 768);
    p_pub[1].decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))v8;
    p_pub[3].start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 896);
    p_pub[3].consume_data = (int (__cdecl *)(jpeg_decompress_struct *))(v8 + 1024);
    p_pub[3].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 1152);
    p_pub->coef_arrays = nullptr;
    p_pub->consume_data = (int (__cdecl *)(jpeg_decompress_struct *))jpeg_mem_init;
    p_pub->decompress_data = decompress_onepass;
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10272A00
// Name: start_input_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_input_pass(jpeg_decompress_struct *cinfo)
{
  per_scan_setup(cinfo);
  latch_quant_tables(cinfo);
  cinfo->entropy->start_pass(a1: cinfo);
  cinfo->coef->start_input_pass(a1: cinfo);
  cinfo->inputctl->consume_input = cinfo->coef->consume_data;
}

//------------------------------------------------------------------------------
// Address: 0x10276400
// Name: start_input_pass_0
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_input_pass_0(jpeg_decompress_struct *cinfo)
{
  jpeg_d_coef_controller *coef; // eax
  bool v2; // cc
  jpeg_component_info *v3; // ecx
  void (__cdecl *last_row_height)(jpeg_decompress_struct *); // ecx

  coef = cinfo->coef;
  v2 = cinfo->comps_in_scan <= 1;
  cinfo->input_iMCU_row = 0;
  if ( v2 )
  {
    v3 = cinfo->cur_comp_info[0];
    if ( cinfo->total_iMCU_rows == 1 )
      last_row_height = (void (__cdecl *)(jpeg_decompress_struct *))v3->last_row_height;
    else
      last_row_height = (void (__cdecl *)(jpeg_decompress_struct *))v3->v_samp_factor;
    coef[1].start_output_pass = last_row_height;
    coef[1].start_input_pass = nullptr;
    coef[1].consume_data = nullptr;
  }
  else
  {
    coef[1].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))1;
    coef[1].start_input_pass = nullptr;
    coef[1].consume_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276460
// Name: decompress_onepass
// Source: json
//------------------------------------------------------------------------------
int __cdecl decompress_onepass(jpeg_decompress_struct *cinfo, unsigned __int8 ***output_buf)
{
  jpeg_decompress_struct *v2; // ebx
  jpeg_d_coef_controller *p_pub; // ecx
  int (__cdecl *consume_data)(jpeg_decompress_struct *); // eax
  unsigned int v5; // edx
  void (__cdecl *start_input_pass)(jpeg_decompress_struct *); // edi
  __int16 (**p_decompress_data)[64]; // esi
  int v8; // ecx
  jpeg_component_info *v9; // esi
  int component_index; // eax
  int last_col_width; // edx
  int v12; // edi
  unsigned __int8 **v13; // edx
  int v14; // eax
  __int16 **v15; // ebx
  unsigned int v16; // ecx
  unsigned int total_iMCU_rows; // edx
  jpeg_d_coef_controller *v18; // eax
  bool v20; // cf
  jpeg_component_info *v21; // edx
  void (__cdecl *v_samp_factor)(jpeg_decompress_struct *); // ecx
  unsigned int start_col; // [esp+Ch] [ebp-38h]
  void (__cdecl *inverse_DCT)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+10h] [ebp-34h]
  unsigned int last_iMCU_row; // [esp+14h] [ebp-30h]
  int ci; // [esp+18h] [ebp-2Ch]
  int yindex; // [esp+1Ch] [ebp-28h]
  int i; // [esp+20h] [ebp-24h]
  int useful_width; // [esp+24h] [ebp-20h]
  unsigned int last_MCU_col; // [esp+28h] [ebp-1Ch]
  jpeg_component_info **cur_comp_info; // [esp+2Ch] [ebp-18h]
  unsigned __int8 **output_ptr; // [esp+30h] [ebp-14h]
  int blkn; // [esp+34h] [ebp-10h]
  my_coef_controller *coef; // [esp+38h] [ebp-Ch]
  unsigned int MCU_col_num; // [esp+3Ch] [ebp-8h]
  int yoffset; // [esp+40h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  consume_data = p_pub[1].consume_data;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)consume_data;
  if ( (int)consume_data >= (int)p_pub[1].start_output_pass )
  {
LABEL_23:
    v16 = ++v2->input_iMCU_row;
    total_iMCU_rows = v2->total_iMCU_rows;
    ++v2->output_iMCU_row;
    if ( v16 >= total_iMCU_rows )
    {
      v2->inputctl->finish_input_pass(a1: v2);
      return 4;
    }
    else
    {
      v18 = v2->coef;
      if ( v2->comps_in_scan <= 1 )
      {
        v20 = v16 < total_iMCU_rows - 1;
        v21 = v2->cur_comp_info[0];
        if ( v20 )
          v_samp_factor = (void (__cdecl *)(jpeg_decompress_struct *))v21->v_samp_factor;
        else
          v_samp_factor = (void (__cdecl *)(jpeg_decompress_struct *))v21->last_row_height;
        v18[1].start_output_pass = v_samp_factor;
        v18[1].start_input_pass = nullptr;
        v18[1].consume_data = nullptr;
        return 3;
      }
      else
      {
        v18[1].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))1;
        v18[1].start_input_pass = nullptr;
        v18[1].consume_data = nullptr;
        return 3;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      start_input_pass = p_pub[1].start_input_pass;
      MCU_col_num = (unsigned int)start_input_pass;
      if ( (unsigned int)start_input_pass <= v5 )
        break;
LABEL_22:
      consume_data = (int (__cdecl *)(jpeg_decompress_struct *))((char *)consume_data + 1);
      p_pub[1].start_input_pass = nullptr;
      yoffset = (int)consume_data;
      if ( (int)consume_data >= (int)p_pub[1].start_output_pass )
        goto LABEL_23;
    }
    while ( 1 )
    {
      p_decompress_data = (__int16 (**)[64])&p_pub[1].decompress_data;
      jzero_far(target: p_pub[1].decompress_data, bytestozero: v2->blocks_in_MCU << 7);
      if ( v2->entropy->decode_mcu(a1: v2, a2: p_decompress_data) == 0 )
        break;
      v8 = 0;
      blkn = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        do
        {
          v9 = *cur_comp_info;
          if ( (*cur_comp_info)->component_needed != 0 )
          {
            component_index = v9->component_index;
            inverse_DCT = v2->idct->inverse_DCT[component_index];
            if ( (unsigned int)start_input_pass >= last_MCU_col )
              last_col_width = v9->last_col_width;
            else
              last_col_width = v9->MCU_width;
            v12 = MCU_col_num * v9->MCU_sample_width;
            useful_width = last_col_width;
            v13 = &output_buf[component_index][yoffset * v9->DCT_scaled_size];
            v14 = 0;
            output_ptr = v13;
            start_col = v12;
            for ( yindex = 0; v14 < v9->MCU_height; yindex = v14 )
            {
              if ( (v2->input_iMCU_row < last_iMCU_row || v14 + yoffset < v9->last_row_height) && useful_width > 0 )
              {
                v15 = (__int16 **)&coef->MCU_buffer[v8];
                for ( i = useful_width; i != 0; --i )
                {
                  inverse_DCT(a1: cinfo, a2: v9, a3: *v15, a4: output_ptr, a5: v12);
                  v12 += v9->DCT_scaled_size;
                  ++v15;
                }
                v12 = start_col;
                v8 = blkn;
                v14 = yindex;
              }
              v8 += v9->MCU_width;
              ++v14;
              v2 = cinfo;
              blkn = v8;
              output_ptr += v9->DCT_scaled_size;
            }
          }
          else
          {
            v8 += v9->MCU_blocks;
            blkn = v8;
          }
          ++cur_comp_info;
          start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))MCU_col_num;
          ++ci;
        }
        while ( ci < v2->comps_in_scan );
      }
      p_pub = &coef->pub;
      start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))((char *)start_input_pass + 1);
      MCU_col_num = (unsigned int)start_input_pass;
      if ( (unsigned int)start_input_pass > last_MCU_col )
      {
        consume_data = (int (__cdecl *)(jpeg_decompress_struct *))yoffset;
        v5 = last_MCU_col;
        goto LABEL_22;
      }
    }
    coef->MCU_ctr = (unsigned int)start_input_pass;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102766B0
// Name: consume_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl consume_data(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // esi
  my_coef_controller *progress; // ebx
  int v3; // edi
  __int16 (**v4)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int MCU_ctr; // edi
  int v7; // ebx
  jpeg_progress_mgr *v8; // edi
  int v9; // ecx
  bool v10; // cc
  __int16 *v11; // eax
  int v12; // edx
  __int16 (**v13)[64]; // esi
  unsigned int global_state; // edx
  unsigned int v15; // ecx
  jpeg_progress_mgr *v16; // eax
  int v18; // ecx
  bool v19; // cf
  jpeg_progress_mgr *v20; // edx
  int completed_passes; // ecx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_progress_mgr **p_progress; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  progress = (my_coef_controller *)cinfo[16].progress;
  v3 = 0;
  coef = progress;
  if ( (int)cinfo[12].mem > 0 )
  {
    yoffset = (int)&cinfo[12].progress;
    do
    {
      progress = coef;
      v4 = cinfo->mem->access_virt_barray(
             a1: cinfo,
             a2: coef->whole_image[*(_DWORD *)(*(_DWORD *)yoffset + 4)],
             a3: *(_DWORD *)(*(_DWORD *)yoffset + 12) * (int)cinfo[5].progress,
             a4: *(_DWORD *)(*(_DWORD *)yoffset + 12),
             a5: 1);
      yoffset += 4;
      buffer[v3++] = v4;
    }
    while ( v3 < (int)cinfo[12].mem );
  }
  MCU_vert_offset = progress->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= progress->MCU_rows_per_iMCU_row )
  {
LABEL_21:
    global_state = v1[11].global_state;
    v15 = (unsigned int)++v1[5].progress;
    if ( v15 >= global_state )
    {
      (*(void (__cdecl **)(jpeg_common_struct *))(*(_DWORD *)&v1[16].is_decompressor + 12))(a1: v1);
      return 4;
    }
    else
    {
      v16 = v1[16].progress;
      if ( (int)v1[12].mem <= 1 )
      {
        v19 = v15 < global_state - 1;
        v20 = v1[12].progress;
        if ( v19 )
          completed_passes = v20->completed_passes;
        else
          completed_passes = v20[3].completed_passes;
        v16[1].pass_limit = completed_passes;
        v16[1].progress_monitor = nullptr;
        v16[1].pass_counter = 0;
        return 3;
      }
      else
      {
        v16[1].pass_limit = 1;
        v16[1].progress_monitor = nullptr;
        v16[1].pass_counter = 0;
        return 3;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      MCU_ctr = progress->MCU_ctr;
      MCU_col_num = MCU_ctr;
      if ( (jpeg_error_mgr *)MCU_ctr < v1[13].err )
        break;
LABEL_20:
      ++MCU_vert_offset;
      progress->MCU_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= progress->MCU_rows_per_iMCU_row )
        goto LABEL_21;
    }
    while ( 1 )
    {
      v7 = 0;
      ci = 0;
      if ( (int)v1[12].mem > 0 )
      {
        p_progress = &v1[12].progress;
        do
        {
          v8 = *p_progress;
          v9 = (*p_progress)[2].completed_passes;
          v10 = (*p_progress)[2].total_passes <= 0;
          yindex = 0;
          if ( !v10 )
          {
            v23 = (MCU_col_num * v9) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v11 = (__int16 *)((char *)*v28 + v23);
              v12 = 0;
              if ( v9 > 0 )
              {
                v13 = &coef->MCU_buffer[v7];
                do
                {
                  *v13 = (__int16 (*)[64])v11;
                  v9 = v8[2].completed_passes;
                  ++v12;
                  ++v7;
                  ++v13;
                  v11 += 64;
                }
                while ( v12 < v9 );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v8[2].total_passes );
          }
          ++p_progress;
          ++ci;
        }
        while ( ci < (int)v1[12].mem );
        MCU_ctr = MCU_col_num;
      }
      progress = coef;
      if ( ((unsigned __int8 (__cdecl *)(jpeg_common_struct *, __int16 (**)[64]))v1[17].err->emit_message)(
             a1: v1,
             a2: coef->MCU_buffer) == 0 )
        break;
      MCU_col_num = ++MCU_ctr;
      if ( (jpeg_error_mgr *)MCU_ctr >= v1[13].err )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v18 = yoffset;
    progress->MCU_ctr = MCU_ctr;
    progress->MCU_vert_offset = v18;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102768C0
// Name: decompress_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl decompress_data(jpeg_decompress_struct *cinfo, unsigned __int8 ***output_buf)
{
  jpeg_decompress_struct *v2; // edi
  int input_scan_number; // eax
  int output_scan_number; // ecx
  int result; // eax
  int v6; // ebx
  jpeg_component_info *comp_info; // esi
  int v8; // ecx
  unsigned int width_in_blocks; // eax
  __int16 *v10; // ebx
  unsigned int v11; // edi
  void (__cdecl *inverse_DCT)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+4h] [ebp-24h]
  __int16 (**buffer)[64]; // [esp+8h] [ebp-20h]
  unsigned int last_iMCU_row; // [esp+Ch] [ebp-1Ch]
  my_coef_controller *coef; // [esp+10h] [ebp-18h]
  int ci; // [esp+14h] [ebp-14h]
  int block_row; // [esp+18h] [ebp-10h]
  unsigned int block_num; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 **output_ptr; // [esp+20h] [ebp-8h]
  int block_rows; // [esp+24h] [ebp-4h]

  v2 = cinfo;
  coef = (my_coef_controller *)cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  while ( 1 )
  {
    input_scan_number = cinfo->input_scan_number;
    output_scan_number = cinfo->output_scan_number;
    if ( input_scan_number >= output_scan_number
      && (input_scan_number != output_scan_number || cinfo->input_iMCU_row > cinfo->output_iMCU_row) )
    {
      break;
    }
    result = cinfo->inputctl->consume_input(a1: cinfo);
    if ( result == 0 )
      return result;
  }
  v6 = 0;
  comp_info = cinfo->comp_info;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    do
    {
      if ( comp_info->component_needed != 0 )
      {
        buffer = v2->mem->access_virt_barray(
                   a1: (jpeg_common_struct *)v2,
                   a2: coef->whole_image[v6],
                   a3: comp_info->v_samp_factor * v2->output_iMCU_row,
                   a4: comp_info->v_samp_factor,
                   a5: 0);
        if ( v2->output_iMCU_row >= last_iMCU_row )
        {
          block_rows = comp_info->height_in_blocks % comp_info->v_samp_factor;
          if ( block_rows == 0 )
            block_rows = comp_info->v_samp_factor;
        }
        else
        {
          block_rows = comp_info->v_samp_factor;
        }
        inverse_DCT = v2->idct->inverse_DCT[v6];
        v8 = 0;
        output_ptr = output_buf[v6];
        block_row = 0;
        if ( block_rows > 0 )
        {
          width_in_blocks = comp_info->width_in_blocks;
          do
          {
            v10 = (__int16 *)buffer[v8];
            v11 = 0;
            block_num = 0;
            if ( width_in_blocks != 0 )
            {
              do
              {
                inverse_DCT(a1: cinfo, a2: comp_info, a3: v10, a4: output_ptr, a5: v11);
                width_in_blocks = comp_info->width_in_blocks;
                v11 += comp_info->DCT_scaled_size;
                v10 += 64;
                ++block_num;
              }
              while ( block_num < width_in_blocks );
              v8 = block_row;
            }
            ++v8;
            output_ptr += comp_info->DCT_scaled_size;
            block_row = v8;
          }
          while ( v8 < block_rows );
          v6 = ci;
          v2 = cinfo;
        }
      }
      ++v6;
      ++comp_info;
      ci = v6;
    }
    while ( v6 < v2->num_components );
  }
  return 4 - (++v2->output_iMCU_row < v2->total_iMCU_rows);
}

//------------------------------------------------------------------------------
// Address: 0x10276A40
// Name: smoothing_ok
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall smoothing_ok@<al>(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_d_coef_controller *progress; // esi
  int (__cdecl *decompress_data)(jpeg_decompress_struct *, unsigned __int8 ***); // edx
  int v3; // esi
  JQUANT_TBL **p_realize_virt_arrays; // eax
  JQUANT_TBL *v5; // eax
  int *v6; // eax
  JQUANT_TBL **i; // [esp+4h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-8h]
  unsigned __int8 smoothing_useful; // [esp+Fh] [ebp-1h]

  progress = (jpeg_d_coef_controller *)cinfo[16].progress;
  smoothing_useful = 0;
  if ( LOBYTE(cinfo[8].progress) == 0 || cinfo[5].global_state == 0 )
    return 0;
  if ( progress[5].decompress_data == nullptr )
    progress[5].decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))cinfo->mem->alloc_small(
                                                                                                    a1: cinfo,
                                                                                                    a2: 1,
                                                                                                    a3: 24 * (int)cinfo[1].client_data);
  decompress_data = progress[5].decompress_data;
  v3 = 0;
  if ( (int)cinfo[1].client_data <= 0 )
    return smoothing_useful;
  p_realize_virt_arrays = (JQUANT_TBL **)&cinfo[8].mem[1].realize_virt_arrays;
  v9 = 0;
  for ( i = p_realize_virt_arrays; ; i += 21 )
  {
    v5 = *p_realize_virt_arrays;
    if ( v5 == nullptr )
      break;
    if ( v5->quantval[0] == 0 )
      break;
    if ( v5->quantval[1] == 0 )
      break;
    if ( v5->quantval[8] == 0 )
      break;
    if ( v5->quantval[16] == 0 )
      break;
    if ( v5->quantval[9] == 0 )
      break;
    if ( v5->quantval[2] == 0 )
      break;
    v6 = (int *)(v9 + cinfo[5].global_state);
    if ( *v6 < 0 )
      break;
    *((_DWORD *)decompress_data + 1) = v6[1];
    if ( v6[1] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 2) = v6[2];
    if ( v6[2] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 3) = v6[3];
    if ( v6[3] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 4) = v6[4];
    if ( v6[4] != 0 )
      smoothing_useful = 1;
    *((_DWORD *)decompress_data + 5) = v6[5];
    if ( v6[5] != 0 )
      smoothing_useful = 1;
    v9 += 256;
    ++v3;
    p_realize_virt_arrays = i + 21;
    decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))((char *)decompress_data + 24);
    if ( v3 >= (int)cinfo[1].client_data )
      return smoothing_useful;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276BA0
// Name: decompress_smooth_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl decompress_smooth_data(jpeg_common_struct *cinfo, unsigned __int8 ***output_buf)
{
  int mem; // ecx
  jpeg_input_controller *v3; // eax
  bool v4; // cc
  jpeg_component_info *v5; // ebx
  unsigned int v6; // esi
  unsigned int v_samp_factor; // ecx
  int v8; // eax
  jvirt_barray_control **v10; // esi
  __int16 (**v11)[64]; // eax
  unsigned __int16 *quantval; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  char *v18; // ecx
  void (__cdecl *v19)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // edx
  __int16 *v20; // edi
  __int16 *v21; // ecx
  __int16 *v22; // eax
  int v23; // esi
  int v24; // edi
  unsigned int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ebx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ebx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // edx
  int v40; // eax
  int v41; // ebx
  int v42; // eax
  int v43; // eax
  int v44; // ecx
  int v45; // edx
  int v46; // eax
  int v47; // edi
  int v48; // eax
  int v49; // eax
  int v50; // ecx
  int v51; // edx
  int v52; // eax
  int v53; // edi
  int v54; // eax
  int v55; // eax
  int DCT_scaled_size; // edx
  unsigned int v57; // [esp-14h] [ebp-11Ch]
  __int16 workspace[64]; // [esp+4h] [ebp-104h] BYREF
  int v59; // [esp+84h] [ebp-84h]
  void (__cdecl *inverse_DCT)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+88h] [ebp-80h]
  unsigned int last_iMCU_row; // [esp+8Ch] [ebp-7Ch]
  int Q11; // [esp+90h] [ebp-78h]
  my_coef_controller *coef; // [esp+94h] [ebp-74h]
  int Q10; // [esp+98h] [ebp-70h]
  int Q20; // [esp+9Ch] [ebp-6Ch]
  unsigned int last_block_column; // [esp+A0h] [ebp-68h]
  int Q01; // [esp+A4h] [ebp-64h]
  int DC7; // [esp+A8h] [ebp-60h]
  int Q02; // [esp+ACh] [ebp-5Ch]
  __int16 (**buffer)[64]; // [esp+B0h] [ebp-58h]
  unsigned int v71; // [esp+B4h] [ebp-54h]
  unsigned int output_col; // [esp+B8h] [ebp-50h]
  int ci; // [esp+BCh] [ebp-4Ch]
  __int16 *v74; // [esp+C0h] [ebp-48h]
  int block_row; // [esp+C4h] [ebp-44h]
  __int16 *v76; // [esp+C8h] [ebp-40h]
  unsigned __int8 **output_ptr; // [esp+CCh] [ebp-3Ch]
  int DC4; // [esp+D0h] [ebp-38h]
  int DC3; // [esp+D4h] [ebp-34h]
  unsigned int block_num; // [esp+D8h] [ebp-30h]
  jpeg_component_info *compptr; // [esp+DCh] [ebp-2Ch]
  int DC9; // [esp+E0h] [ebp-28h]
  jvirt_barray_control **whole_image; // [esp+E4h] [ebp-24h]
  int DC2; // [esp+E8h] [ebp-20h]
  int DC8; // [esp+ECh] [ebp-1Ch]
  int DC5; // [esp+F0h] [ebp-18h]
  int *coef_bits; // [esp+F4h] [ebp-14h]
  int Q00; // [esp+F8h] [ebp-10h]
  __int16 (*buffer_ptr)[64]; // [esp+FCh] [ebp-Ch]
  int block_rows; // [esp+100h] [ebp-8h]
  unsigned __int8 last_row; // [esp+106h] [ebp-2h]
  unsigned __int8 first_row; // [esp+107h] [ebp-1h]

  mem = (int)cinfo[5].mem;
  coef = (my_coef_controller *)cinfo[16].progress;
  last_iMCU_row = cinfo[11].global_state - 1;
  if ( mem <= (int)cinfo[5].client_data )
  {
    do
    {
      v3 = *(jpeg_input_controller **)&cinfo[16].is_decompressor;
      if ( v3->eoi_reached != 0
        || cinfo[5].mem == cinfo[5].client_data
        && __PAIR64__(cinfo[5].progress, cinfo[15].mem) >= __PAIR64__(*(_DWORD *)&cinfo[5].is_decompressor, 1)
        && cinfo[5].progress != (jpeg_progress_mgr *)(*(_DWORD *)&cinfo[5].is_decompressor + (cinfo[15].mem == nullptr)) )
      {
        break;
      }
      if ( v3->consume_input(a1: (jpeg_decompress_struct *)cinfo) == 0 )
        return 0;
    }
    while ( (int)cinfo[5].mem <= (int)cinfo[5].client_data );
  }
  v4 = (int)cinfo[1].client_data <= 0;
  v5 = (jpeg_component_info *)cinfo[8].mem;
  ci = 0;
  compptr = v5;
  if ( !v4 )
  {
    v71 = 0;
    whole_image = coef->whole_image;
    v59 = -72 - (_DWORD)coef;
    do
    {
      if ( v5->component_needed != 0 )
      {
        v6 = *(_DWORD *)&cinfo[5].is_decompressor;
        v_samp_factor = v5->v_samp_factor;
        if ( v6 >= last_iMCU_row )
        {
          v8 = v5->height_in_blocks % v_samp_factor;
          block_rows = v8;
          if ( v8 == 0 )
          {
            v8 = v_samp_factor;
            block_rows = v_samp_factor;
          }
          last_row = 1;
        }
        else
        {
          block_rows = v5->v_samp_factor;
          v8 = 2 * v_samp_factor;
          last_row = 0;
        }
        if ( v6 != 0 )
        {
          v57 = v_samp_factor * (v6 - 1);
          v10 = whole_image;
          v11 = &cinfo->mem->access_virt_barray(a1: cinfo, a2: *whole_image, a3: v57, a4: v_samp_factor + v8, a5: 0)[v5->v_samp_factor];
          first_row = 0;
        }
        else
        {
          v10 = whole_image;
          v11 = cinfo->mem->access_virt_barray(a1: cinfo, a2: *whole_image, a3: 0, a4: v8, a5: 0);
          first_row = 1;
        }
        buffer = v11;
        coef_bits = &coef->coef_bits_latch[v71 / 4];
        quantval = v5->quant_table->quantval;
        v13 = quantval[1];
        Q00 = *quantval;
        v14 = quantval[8];
        Q01 = v13;
        v15 = quantval[16];
        Q10 = v14;
        v16 = quantval[9];
        v17 = quantval[2];
        Q20 = v15;
        v18 = (char *)cinfo[17].mem + v59;
        Q11 = v16;
        v19 = *(void (__cdecl **)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int))((char *)v10 + (_DWORD)v18 + 4);
        Q02 = v17;
        inverse_DCT = v19;
        output_ptr = output_buf[ci];
        for ( block_row = 0; block_row < block_rows; ++block_row )
        {
          v20 = (__int16 *)buffer[block_row];
          buffer_ptr = (__int16 (*)[64])v20;
          if ( first_row == 0 || (v21 = v20, block_row != 0) )
            v21 = (__int16 *)buffer[block_row - 1];
          if ( last_row == 0 || (v22 = v20, block_row != block_rows - 1) )
            v22 = (__int16 *)buffer[block_row + 1];
          v23 = *(__int16 *)buffer_ptr;
          v24 = *v21;
          DC9 = *v22;
          DC8 = DC9;
          DC7 = DC9;
          v25 = v5->width_in_blocks - 1;
          DC3 = v24;
          DC2 = v24;
          DC5 = v23;
          DC4 = v23;
          output_col = 0;
          last_block_column = v25;
          block_num = 0;
          v74 = v21 + 64;
          v76 = v22 + 64;
          do
          {
            jcopy_block_row(input_row: buffer_ptr, output_row: (__int16 (*)[64])workspace, num_blocks: 1u);
            if ( block_num < last_block_column )
            {
              v23 = (*buffer_ptr)[64];
              DC3 = *v74;
              DC9 = *v76;
            }
            v26 = coef_bits[1];
            if ( v26 != 0 && workspace[1] == 0 )
            {
              v27 = Q01 << 7;
              v28 = Q01 << 8;
              v29 = 36 * Q00 * (DC4 - v23);
              if ( ((18 * Q00 * (DC4 - v23)) & 0x40000000) != 0 )
              {
                v31 = (v27 - v29) / v28;
                if ( v26 > 0 && v31 >= 1 << v26 )
                  v31 = (1 << v26) - 1;
                v30 = -v31;
              }
              else
              {
                v30 = (v29 + v27) / v28;
                if ( v26 > 0 && v30 >= 1 << v26 )
                  v30 = (1 << v26) - 1;
              }
              v5 = compptr;
              workspace[1] = v30;
            }
            v32 = coef_bits[2];
            if ( v32 != 0 && workspace[8] == 0 )
            {
              v33 = Q10 << 7;
              v34 = Q10 << 8;
              v35 = 36 * Q00 * (DC2 - DC8);
              if ( ((18 * Q00 * (DC2 - DC8)) & 0x40000000) != 0 )
              {
                v37 = (v33 - v35) / v34;
                if ( v32 > 0 && v37 >= 1 << v32 )
                  v37 = (1 << v32) - 1;
                v36 = -v37;
              }
              else
              {
                v36 = (v35 + v33) / v34;
                if ( v32 > 0 && v36 >= 1 << v32 )
                  v36 = (1 << v32) - 1;
              }
              v5 = compptr;
              workspace[8] = v36;
            }
            v38 = coef_bits[3];
            if ( v38 != 0 && workspace[16] == 0 )
            {
              v39 = 9 * Q00 * (DC2 + DC8 - 2 * DC5);
              v40 = Q20 << 7;
              v41 = Q20 << 8;
              if ( v39 < 0 )
              {
                v43 = (v40 - v39) / v41;
                if ( v38 > 0 && v43 >= 1 << v38 )
                  v43 = (1 << v38) - 1;
                v42 = -v43;
              }
              else
              {
                v42 = (v39 + v40) / v41;
                if ( v38 > 0 && v42 >= 1 << v38 )
                  v42 = (1 << v38) - 1;
              }
              v5 = compptr;
              workspace[16] = v42;
            }
            v44 = coef_bits[4];
            if ( v44 != 0 && workspace[9] == 0 )
            {
              v45 = 5 * Q00 * (v24 + DC9 - DC7 - DC3);
              v46 = Q11 << 7;
              v47 = Q11 << 8;
              if ( v45 < 0 )
              {
                v49 = (v46 - v45) / v47;
                if ( v44 > 0 && v49 >= 1 << v44 )
                  v49 = (1 << v44) - 1;
                v48 = -v49;
              }
              else
              {
                v48 = (v45 + v46) / v47;
                if ( v44 > 0 && v48 >= 1 << v44 )
                  v48 = (1 << v44) - 1;
              }
              workspace[9] = v48;
            }
            v50 = coef_bits[5];
            if ( v50 != 0 && workspace[2] == 0 )
            {
              v51 = 9 * Q00 * (DC4 + v23 - 2 * DC5);
              v52 = Q02 << 7;
              v53 = Q02 << 8;
              if ( v51 < 0 )
              {
                v55 = (v52 - v51) / v53;
                if ( v50 > 0 && v55 >= 1 << v50 )
                  v55 = (1 << v50) - 1;
                v54 = -v55;
              }
              else
              {
                v54 = (v51 + v52) / v53;
                if ( v50 > 0 && v54 >= 1 << v50 )
                  v54 = (1 << v50) - 1;
              }
              workspace[2] = v54;
            }
            inverse_DCT(a1: (jpeg_decompress_struct *)cinfo, a2: v5, a3: workspace, a4: output_ptr, a5: output_col);
            v24 = DC2;
            DC7 = DC8;
            ++buffer_ptr;
            v74 += 64;
            v76 += 64;
            DC4 = DC5;
            DCT_scaled_size = v5->DCT_scaled_size;
            output_col += DCT_scaled_size;
            DC2 = DC3;
            DC5 = v23;
            DC8 = DC9;
            ++block_num;
          }
          while ( block_num <= last_block_column );
          output_ptr += DCT_scaled_size;
        }
      }
      v71 += 24;
      ++whole_image;
      ++v5;
      ++ci;
      compptr = v5;
    }
    while ( ci < (int)cinfo[1].client_data );
  }
  return 4 - (++*(_DWORD *)&cinfo[5].is_decompressor < cinfo[11].global_state);
}

//------------------------------------------------------------------------------
// Address: 0x102770E0
// Name: start_output_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_output_pass(jpeg_common_struct *cinfo)
{
  jpeg_d_coef_controller *progress; // esi

  progress = (jpeg_d_coef_controller *)cinfo[16].progress;
  if ( progress->coef_arrays != nullptr )
  {
    if ( BYTE1(cinfo[3].err) != 0 && smoothing_ok(cinfo) != 0 )
    {
      progress->decompress_data = decompress_smooth_data;
      *(_DWORD *)&cinfo[5].is_decompressor = 0;
      return;
    }
    progress->decompress_data = decompress_data;
  }
  *(_DWORD *)&cinfo[5].is_decompressor = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10277130
// Name: _jinit_d_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_d_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_d_coef_controller *p_pub; // ebx
  int *p_alloc_barray; // edi
  int v5; // ecx
  jpeg_memory_mgr *mem; // ebx
  int v7; // eax
  char *v8; // eax
  int v9; // [esp-8h] [ebp-18h]
  unsigned int v10; // [esp-4h] [ebp-14h]
  my_coef_controller *coef; // [esp+Ch] [ebp-4h]
  jpeg_decompress_struct *cinfoa; // [esp+18h] [ebp+8h]
  int ci; // [esp+1Ch] [ebp+Ch]

  p_pub = (jpeg_d_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 116);
  cinfo[16].progress = (jpeg_progress_mgr *)p_pub;
  coef = (my_coef_controller *)p_pub;
  p_pub->start_input_pass = start_input_pass_0;
  p_pub->start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))start_output_pass;
  p_pub[5].decompress_data = nullptr;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[1].client_data > 0 )
    {
      p_alloc_barray = (int *)&cinfo[8].mem->alloc_barray;
      cinfoa = (jpeg_decompress_struct *)&p_pub[3].decompress_data;
      do
      {
        v5 = *p_alloc_barray;
        if ( LOBYTE(cinfo[8].progress) != 0 )
          v5 *= 3;
        mem = cinfo->mem;
        v10 = v5;
        v9 = jround_up(a: p_alloc_barray[5], b: *p_alloc_barray);
        v7 = jround_up(a: p_alloc_barray[4], b: *(p_alloc_barray - 1));
        cinfoa->err = (jpeg_error_mgr *)mem->request_virt_barray(a1: cinfo, a2: 1, a3: 1u, a4: v7, a5: v9, a6: v10);
        p_alloc_barray += 21;
        ++ci;
        cinfoa = (jpeg_decompress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[1].client_data );
      p_pub = &coef->pub;
    }
    p_pub->consume_data = (int (__cdecl *)(jpeg_decompress_struct *))consume_data;
    p_pub->decompress_data = decompress_data;
    p_pub->coef_arrays = (jvirt_barray_control **)&p_pub[3].decompress_data;
  }
  else
  {
    v8 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    p_pub[1].coef_arrays = (jvirt_barray_control **)(v8 + 128);
    p_pub[2].start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 256);
    p_pub[2].consume_data = (int (__cdecl *)(jpeg_decompress_struct *))(v8 + 384);
    p_pub[2].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 512);
    p_pub[2].decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))(v8 + 640);
    p_pub[2].coef_arrays = (jvirt_barray_control **)(v8 + 768);
    p_pub[1].decompress_data = (int (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***))v8;
    p_pub[3].start_input_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 896);
    p_pub[3].consume_data = (int (__cdecl *)(jpeg_decompress_struct *))(v8 + 1024);
    p_pub[3].start_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))(v8 + 1152);
    p_pub->coef_arrays = nullptr;
    p_pub->consume_data = (int (__cdecl *)(jpeg_decompress_struct *))C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass;
    p_pub->decompress_data = decompress_onepass;
  }
}

} // namespace client
