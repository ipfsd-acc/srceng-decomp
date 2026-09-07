// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdmaster.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000C730
// Name: use_merged_upsample
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __fastcall use_merged_upsample(int a1, jpeg_decompress_struct *cinfo)
{
  jpeg_component_info *comp_info; // ecx
  unsigned __int8 result; // al
  int min_DCT_scaled_size; // edx

  if ( cinfo->do_fancy_upsampling != 0 )
    return 0;
  if ( cinfo->CCIR601_sampling != 0 )
    return 0;
  if ( cinfo->jpeg_color_space != JCS_YCbCr )
    return 0;
  if ( cinfo->num_components != 3 )
    return 0;
  if ( cinfo->out_color_space != JCS_RGB )
    return 0;
  if ( cinfo->out_color_components != 3 )
    return 0;
  comp_info = cinfo->comp_info;
  if ( comp_info->h_samp_factor != 2 )
    return 0;
  result = 1;
  if ( comp_info[1].h_samp_factor != 1 )
    return 0;
  if ( comp_info[2].h_samp_factor != 1 )
    return 0;
  if ( comp_info->v_samp_factor > 2 )
    return 0;
  if ( comp_info[1].v_samp_factor != 1 )
    return 0;
  if ( comp_info[2].v_samp_factor != 1 )
    return 0;
  min_DCT_scaled_size = cinfo->min_DCT_scaled_size;
  if ( comp_info->DCT_scaled_size != min_DCT_scaled_size
    || comp_info[1].DCT_scaled_size != min_DCT_scaled_size
    || comp_info[2].DCT_scaled_size != min_DCT_scaled_size )
  {
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C7B0
// Name: _jpeg_calc_output_dimensions
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_calc_output_dimensions(jpeg_common_struct *cinfo)
{
  unsigned int err; // eax
  unsigned int mem; // ecx
  unsigned int v4; // eax
  int progress; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  bool v8; // cc
  jpeg_component_info *v9; // ecx
  int *p_v_samp_factor; // ecx
  int v11; // edx
  int v12; // eax
  int i; // edi
  int v14; // ebx
  int *p_free_pool; // edi
  int v16; // eax
  int v17; // ecx
  J_COLOR_SPACE global_state; // ecx
  int v19; // eax
  bool v20; // zf
  jpeg_component_info *v21; // eax
  int v22; // ecx
  unsigned int v23; // [esp-10h] [ebp-20h]
  unsigned int v24; // [esp-10h] [ebp-20h]
  unsigned int v25; // [esp-10h] [ebp-20h]
  int ci; // [esp+18h] [ebp+8h]

  if ( cinfo->global_state != 202 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (unsigned int)cinfo[2].err;
  mem = (unsigned int)cinfo[2].mem;
  if ( 8 * err > mem )
  {
    if ( 4 * err > mem )
    {
      if ( 2 * err > mem )
      {
        progress = (int)cinfo[1].progress;
        cinfo[3].global_state = (int)cinfo[1].mem;
        *(_DWORD *)&cinfo[11].is_decompressor = 8;
      }
      else
      {
        v7 = jdiv_round_up(a: (int)cinfo[1].mem, b: 2);
        v25 = (unsigned int)cinfo[1].progress;
        cinfo[3].global_state = v7;
        progress = jdiv_round_up(a: v25, b: 2);
        *(_DWORD *)&cinfo[11].is_decompressor = 4;
      }
    }
    else
    {
      v6 = jdiv_round_up(a: (int)cinfo[1].mem, b: 4);
      v24 = (unsigned int)cinfo[1].progress;
      cinfo[3].global_state = v6;
      progress = jdiv_round_up(a: v24, b: 4);
      *(_DWORD *)&cinfo[11].is_decompressor = 2;
    }
  }
  else
  {
    v4 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8);
    v23 = (unsigned int)cinfo[1].progress;
    cinfo[3].global_state = v4;
    progress = jdiv_round_up(a: v23, b: 8);
    *(_DWORD *)&cinfo[11].is_decompressor = 1;
  }
  v8 = (int)cinfo[1].client_data <= 0;
  v9 = (jpeg_component_info *)cinfo[8].mem;
  cinfo[4].err = (jpeg_error_mgr *)progress;
  ci = 0;
  if ( !v8 )
  {
    p_v_samp_factor = &v9->v_samp_factor;
    do
    {
      v11 = *(_DWORD *)&cinfo[11].is_decompressor;
      v12 = v11;
      if ( v11 < 8 )
      {
        for ( i = v11 * (int)cinfo[11].progress; 2 * v12 * *(p_v_samp_factor - 1) <= i; i = v11
                                                                                          * (int)cinfo[11].progress )
        {
          if ( 2 * v12 * *p_v_samp_factor > v11 * (int)cinfo[11].client_data )
            break;
          v12 *= 2;
          if ( v12 >= 8 )
            break;
        }
      }
      p_v_samp_factor[6] = v12;
      p_v_samp_factor += 21;
      ++ci;
    }
    while ( ci < (int)cinfo[1].client_data );
  }
  v14 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (int *)&cinfo[8].mem->free_pool;
    do
    {
      v16 = jdiv_round_up(a: (int)cinfo[1].mem * *p_free_pool * *(p_free_pool - 7), b: 8 * (int)cinfo[11].progress);
      v17 = *p_free_pool * *(p_free_pool - 6);
      p_free_pool[1] = v16;
      p_free_pool[2] = jdiv_round_up(a: (int)cinfo[1].progress * v17, b: 8 * (int)cinfo[11].client_data);
      ++v14;
      p_free_pool += 21;
    }
    while ( v14 < (int)cinfo[1].client_data );
  }
  global_state = cinfo[1].global_state;
  switch ( global_state )
  {
    case JCS_GRAYSCALE:
      cinfo[4].mem = (jpeg_memory_mgr *)1;
      break;
    case JCS_RGB:
    case JCS_YCbCr:
      cinfo[4].mem = (jpeg_memory_mgr *)3;
      break;
    case JCS_CMYK:
    case JCS_YCCK:
      cinfo[4].mem = (jpeg_memory_mgr *)4;
      break;
    default:
      cinfo[4].mem = (jpeg_memory_mgr *)cinfo[1].client_data;
      break;
  }
  v19 = 1;
  if ( BYTE2(cinfo[3].err) == 0 )
    v19 = (int)cinfo[4].mem;
  v20 = LOBYTE(cinfo[3].err) == 0;
  cinfo[4].progress = (jpeg_progress_mgr *)v19;
  if ( v20
    && BYTE2(cinfo[11].err) == 0
    && *(_DWORD *)&cinfo[1].is_decompressor == 3
    && cinfo[1].client_data == (void *)3
    && global_state == JCS_RGB
    && cinfo[4].mem == (jpeg_memory_mgr *)3
    && (v21 = (jpeg_component_info *)cinfo[8].mem)->h_samp_factor == 2
    && v21[1].h_samp_factor == 1
    && v21[2].h_samp_factor == 1
    && v21->v_samp_factor <= 2
    && v21[1].v_samp_factor == 1
    && v21[2].v_samp_factor == 1
    && (v22 = *(_DWORD *)&cinfo[11].is_decompressor, v21->DCT_scaled_size == v22)
    && v21[1].DCT_scaled_size == v22
    && v21[2].DCT_scaled_size == v22 )
  {
    cinfo[4].client_data = cinfo[11].client_data;
  }
  else
  {
    cinfo[4].client_data = (void *)1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CA50
// Name: prepare_range_limit_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_range_limit_table(jpeg_common_struct *cinfo)
{
  int v1; // eax
  int v2; // esi
  int i; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1408);
  v2 = v1 + 256;
  cinfo[12].err = (jpeg_error_mgr *)(v1 + 256);
  memset(dst: v1, value: nullptr, count: 0x100u);
  for ( i = 0; i <= 255; ++i )
    *(_BYTE *)(i + v2) = i;
  memset(dst: v2 + 256, value: (unsigned __int8 *)0xFF, count: 0x180u);
  memset(dst: v2 + 640, value: nullptr, count: 0x180u);
  qmemcpy((void *)(v2 + 1024), cinfo[12].err, 0x80u);
}

//------------------------------------------------------------------------------
// Address: 0x1000CAE0
// Name: master_selection
// Source: json
//------------------------------------------------------------------------------
void __usercall master_selection(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_decomp_master *err; // edi
  int v2; // ecx
  unsigned __int8 v3; // al
  jpeg_progress_mgr *progress; // ecx
  int client_data; // eax
  jpeg_common_struct *v6; // [esp+0h] [ebp-10h]
  unsigned __int8 use_c_buffer; // [esp+Ch] [ebp-4h]

  err = (jpeg_decomp_master *)cinfo[16].err;
  jpeg_calc_output_dimensions(cinfo: v6);
  prepare_range_limit_table(cinfo);
  err[1].prepare_for_output_pass = nullptr;
  LOBYTE(err[1].finish_output_pass) = use_merged_upsample(a1: v2, (jpeg_decompress_struct *)cinfo);
  *(_DWORD *)&err[1].is_dummy_pass = 0;
  err[2].prepare_for_output_pass = nullptr;
  v3 = BYTE2(cinfo[3].err);
  if ( v3 == 0 || cinfo[2].is_decompressor == 0 )
  {
    *(_WORD *)&cinfo[3].is_decompressor = 0;
    *(&cinfo[3].is_decompressor + 2) = 0;
  }
  if ( v3 != 0 )
  {
    if ( *(&cinfo[2].is_decompressor + 1) != 0 )
    {
      cinfo->err->msg_code = 47;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
    {
      if ( cinfo[4].global_state != 0 )
      {
        *(&cinfo[3].is_decompressor + 1) = 1;
      }
      else if ( LOBYTE(cinfo[3].progress) != 0 )
      {
        *(&cinfo[3].is_decompressor + 2) = 1;
      }
      else
      {
        cinfo[3].is_decompressor = 1;
      }
    }
    else
    {
      *(_WORD *)&cinfo[3].is_decompressor = 1;
      *(&cinfo[3].is_decompressor + 2) = 0;
      cinfo[4].global_state = 0;
    }
    if ( cinfo[3].is_decompressor != 0 )
    {
      jinit_1pass_quantizer((jpeg_decompress_struct *)cinfo);
      *(_DWORD *)&err[1].is_dummy_pass = *(_DWORD *)&cinfo[17].is_decompressor;
    }
    if ( *(&cinfo[3].is_decompressor + 2) != 0 || *(&cinfo[3].is_decompressor + 1) != 0 )
    {
      jinit_2pass_quantizer((jpeg_decompress_struct *)cinfo);
      err[2].prepare_for_output_pass = *(void (__cdecl **)(jpeg_decompress_struct *))&cinfo[17].is_decompressor;
    }
  }
  if ( *(&cinfo[2].is_decompressor + 1) == 0 )
  {
    if ( LOBYTE(err[1].finish_output_pass) != 0 )
    {
      jinit_merged_upsampler((jpeg_decompress_struct *)cinfo);
    }
    else
    {
      jinit_color_deconverter((jpeg_decompress_struct *)cinfo);
      jinit_upsampler((jpeg_decompress_struct *)cinfo);
    }
    jinit_d_post_controller((jpeg_decompress_struct *)cinfo, need_full_buffer: *(&cinfo[3].is_decompressor + 2));
  }
  jinit_inverse_dct((jpeg_decompress_struct *)cinfo);
  if ( BYTE1(cinfo[8].progress) != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  else if ( LOBYTE(cinfo[8].progress) != 0 )
  {
    jinit_phuff_decoder((jpeg_decompress_struct *)cinfo);
  }
  else
  {
    jinit_huff_decoder((jpeg_decompress_struct *)cinfo);
  }
  if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) != 0 || (use_c_buffer = 0, cinfo[2].is_decompressor != 0) )
    use_c_buffer = 1;
  jinit_d_coef_controller(cinfo, need_full_buffer: use_c_buffer);
  if ( *(&cinfo[2].is_decompressor + 1) == 0 )
    jinit_d_main_controller((jpeg_decompress_struct *)cinfo, need_full_buffer: 0);
  cinfo->mem->realize_virt_arrays(a1: cinfo);
  (*(void (__cdecl **)(jpeg_common_struct *))(*(_DWORD *)&cinfo[16].is_decompressor + 8))(a1: cinfo);
  progress = cinfo->progress;
  if ( progress != nullptr
    && cinfo[2].is_decompressor == 0
    && *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) != 0 )
  {
    client_data = (int)cinfo[1].client_data;
    if ( LOBYTE(cinfo[8].progress) != 0 )
      client_data = 3 * client_data + 2;
    progress->pass_counter = 0;
    cinfo->progress->pass_limit = client_data * cinfo[11].global_state;
    cinfo->progress->completed_passes = 0;
    cinfo->progress->total_passes = (*(&cinfo[3].is_decompressor + 2) != 0) + 2;
    ++err[1].prepare_for_output_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CCB0
// Name: prepare_for_output_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_output_pass(jpeg_decompress_struct *cinfo)
{
  jpeg_decomp_master *master; // edi
  jpeg_progress_mgr *progress; // eax

  master = cinfo->master;
  if ( master->is_dummy_pass != 0 )
  {
    master->is_dummy_pass = 0;
    cinfo->cquantize->start_pass(a1: cinfo, a2: 0);
    cinfo->post->start_pass(a1: cinfo, a2: JBUF_CRANK_DEST);
    cinfo->main->start_pass(a1: cinfo, a2: JBUF_CRANK_DEST);
  }
  else
  {
    if ( cinfo->quantize_colors != 0 && cinfo->colormap == nullptr )
    {
      if ( cinfo->two_pass_quantize != 0 && cinfo->enable_2pass_quant != 0 )
      {
        cinfo->cquantize = (jpeg_color_quantizer *)master[2].prepare_for_output_pass;
        master->is_dummy_pass = 1;
      }
      else if ( cinfo->enable_1pass_quant != 0 )
      {
        cinfo->cquantize = *(jpeg_color_quantizer **)&master[1].is_dummy_pass;
      }
      else
      {
        cinfo->err->msg_code = 46;
        cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
      }
    }
    cinfo->idct->start_pass(a1: cinfo);
    cinfo->coef->start_output_pass(a1: cinfo);
    if ( cinfo->raw_data_out == 0 )
    {
      if ( LOBYTE(master[1].finish_output_pass) == 0 )
        cinfo->cconvert->start_pass(a1: cinfo);
      cinfo->upsample->start_pass(a1: cinfo);
      if ( cinfo->quantize_colors != 0 )
        cinfo->cquantize->start_pass(a1: cinfo, a2: master->is_dummy_pass);
      cinfo->post->start_pass(a1: cinfo, a2: master->is_dummy_pass != 0 ? 3 : 0);
      cinfo->main->start_pass(a1: cinfo, a2: JBUF_PASS_THRU);
    }
  }
  progress = cinfo->progress;
  if ( progress != nullptr )
  {
    progress->completed_passes = (int)master[1].prepare_for_output_pass;
    cinfo->progress->total_passes = (int)master[1].prepare_for_output_pass + (master->is_dummy_pass != 0) + 1;
    if ( cinfo->buffered_image != 0 && cinfo->inputctl->eoi_reached == 0 )
      cinfo->progress->total_passes += (cinfo->enable_2pass_quant != 0) + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CE10
// Name: finish_output_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_output_pass(jpeg_decompress_struct *cinfo)
{
  jpeg_decomp_master *master; // esi

  master = cinfo->master;
  if ( cinfo->quantize_colors != 0 )
    cinfo->cquantize->finish_pass(a1: cinfo);
  ++master[1].prepare_for_output_pass;
}

//------------------------------------------------------------------------------
// Address: 0x1000CE40
// Name: _jinit_master_decompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_master_decompress(jpeg_common_struct *cinfo)
{
  jpeg_decomp_master *v1; // eax

  v1 = (jpeg_decomp_master *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 28);
  cinfo[16].err = (jpeg_error_mgr *)v1;
  v1->prepare_for_output_pass = prepare_for_output_pass;
  v1->finish_output_pass = finish_output_pass;
  v1->is_dummy_pass = 0;
  master_selection(cinfo);
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102754B0
// Name: use_merged_upsample
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __fastcall use_merged_upsample(int a1, jpeg_decompress_struct *cinfo)
{
  jpeg_component_info *comp_info; // ecx
  unsigned __int8 result; // al
  int min_DCT_scaled_size; // edx

  if ( cinfo->do_fancy_upsampling != 0 )
    return 0;
  if ( cinfo->CCIR601_sampling != 0 )
    return 0;
  if ( cinfo->jpeg_color_space != JCS_YCbCr )
    return 0;
  if ( cinfo->num_components != 3 )
    return 0;
  if ( cinfo->out_color_space != JCS_RGB )
    return 0;
  if ( cinfo->out_color_components != 3 )
    return 0;
  comp_info = cinfo->comp_info;
  if ( comp_info->h_samp_factor != 2 )
    return 0;
  result = 1;
  if ( comp_info[1].h_samp_factor != 1 )
    return 0;
  if ( comp_info[2].h_samp_factor != 1 )
    return 0;
  if ( comp_info->v_samp_factor > 2 )
    return 0;
  if ( comp_info[1].v_samp_factor != 1 )
    return 0;
  if ( comp_info[2].v_samp_factor != 1 )
    return 0;
  min_DCT_scaled_size = cinfo->min_DCT_scaled_size;
  if ( comp_info->DCT_scaled_size != min_DCT_scaled_size
    || comp_info[1].DCT_scaled_size != min_DCT_scaled_size
    || comp_info[2].DCT_scaled_size != min_DCT_scaled_size )
  {
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10275530
// Name: _jpeg_calc_output_dimensions
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_calc_output_dimensions(jpeg_common_struct *cinfo)
{
  unsigned int err; // eax
  unsigned int mem; // ecx
  unsigned int v4; // eax
  int progress; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  bool v8; // cc
  jpeg_component_info *v9; // ecx
  int *p_v_samp_factor; // ecx
  int v11; // edx
  int v12; // eax
  int i; // edi
  int v14; // ebx
  int *p_free_pool; // edi
  int v16; // eax
  int v17; // ecx
  J_COLOR_SPACE global_state; // ecx
  int v19; // eax
  bool v20; // zf
  jpeg_component_info *v21; // eax
  int v22; // ecx
  unsigned int v23; // [esp-10h] [ebp-20h]
  unsigned int v24; // [esp-10h] [ebp-20h]
  unsigned int v25; // [esp-10h] [ebp-20h]
  int ci; // [esp+18h] [ebp+8h]

  if ( cinfo->global_state != 202 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (unsigned int)cinfo[2].err;
  mem = (unsigned int)cinfo[2].mem;
  if ( 8 * err > mem )
  {
    if ( 4 * err > mem )
    {
      if ( 2 * err > mem )
      {
        progress = (int)cinfo[1].progress;
        cinfo[3].global_state = (int)cinfo[1].mem;
        *(_DWORD *)&cinfo[11].is_decompressor = 8;
      }
      else
      {
        v7 = jdiv_round_up(a: (int)cinfo[1].mem, b: 2);
        v25 = (unsigned int)cinfo[1].progress;
        cinfo[3].global_state = v7;
        progress = jdiv_round_up(a: v25, b: 2);
        *(_DWORD *)&cinfo[11].is_decompressor = 4;
      }
    }
    else
    {
      v6 = jdiv_round_up(a: (int)cinfo[1].mem, b: 4);
      v24 = (unsigned int)cinfo[1].progress;
      cinfo[3].global_state = v6;
      progress = jdiv_round_up(a: v24, b: 4);
      *(_DWORD *)&cinfo[11].is_decompressor = 2;
    }
  }
  else
  {
    v4 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8);
    v23 = (unsigned int)cinfo[1].progress;
    cinfo[3].global_state = v4;
    progress = jdiv_round_up(a: v23, b: 8);
    *(_DWORD *)&cinfo[11].is_decompressor = 1;
  }
  v8 = (int)cinfo[1].client_data <= 0;
  v9 = (jpeg_component_info *)cinfo[8].mem;
  cinfo[4].err = (jpeg_error_mgr *)progress;
  ci = 0;
  if ( !v8 )
  {
    p_v_samp_factor = &v9->v_samp_factor;
    do
    {
      v11 = *(_DWORD *)&cinfo[11].is_decompressor;
      v12 = v11;
      if ( v11 < 8 )
      {
        for ( i = v11 * (int)cinfo[11].progress; 2 * v12 * *(p_v_samp_factor - 1) <= i; i = v11
                                                                                          * (int)cinfo[11].progress )
        {
          if ( 2 * v12 * *p_v_samp_factor > v11 * (int)cinfo[11].client_data )
            break;
          v12 *= 2;
          if ( v12 >= 8 )
            break;
        }
      }
      p_v_samp_factor[6] = v12;
      p_v_samp_factor += 21;
      ++ci;
    }
    while ( ci < (int)cinfo[1].client_data );
  }
  v14 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (int *)&cinfo[8].mem->free_pool;
    do
    {
      v16 = jdiv_round_up(a: (int)cinfo[1].mem * *p_free_pool * *(p_free_pool - 7), b: 8 * (int)cinfo[11].progress);
      v17 = *p_free_pool * *(p_free_pool - 6);
      p_free_pool[1] = v16;
      p_free_pool[2] = jdiv_round_up(a: (int)cinfo[1].progress * v17, b: 8 * (int)cinfo[11].client_data);
      ++v14;
      p_free_pool += 21;
    }
    while ( v14 < (int)cinfo[1].client_data );
  }
  global_state = cinfo[1].global_state;
  switch ( global_state )
  {
    case JCS_GRAYSCALE:
      cinfo[4].mem = (jpeg_memory_mgr *)1;
      break;
    case JCS_RGB:
    case JCS_YCbCr:
      cinfo[4].mem = (jpeg_memory_mgr *)3;
      break;
    case JCS_CMYK:
    case JCS_YCCK:
      cinfo[4].mem = (jpeg_memory_mgr *)4;
      break;
    default:
      cinfo[4].mem = (jpeg_memory_mgr *)cinfo[1].client_data;
      break;
  }
  v19 = 1;
  if ( BYTE2(cinfo[3].err) == 0 )
    v19 = (int)cinfo[4].mem;
  v20 = LOBYTE(cinfo[3].err) == 0;
  cinfo[4].progress = (jpeg_progress_mgr *)v19;
  if ( v20
    && BYTE2(cinfo[11].err) == 0
    && *(_DWORD *)&cinfo[1].is_decompressor == 3
    && cinfo[1].client_data == (void *)3
    && global_state == JCS_RGB
    && cinfo[4].mem == (jpeg_memory_mgr *)3
    && (v21 = (jpeg_component_info *)cinfo[8].mem)->h_samp_factor == 2
    && v21[1].h_samp_factor == 1
    && v21[2].h_samp_factor == 1
    && v21->v_samp_factor <= 2
    && v21[1].v_samp_factor == 1
    && v21[2].v_samp_factor == 1
    && (v22 = *(_DWORD *)&cinfo[11].is_decompressor, v21->DCT_scaled_size == v22)
    && v21[1].DCT_scaled_size == v22
    && v21[2].DCT_scaled_size == v22 )
  {
    cinfo[4].client_data = cinfo[11].client_data;
  }
  else
  {
    cinfo[4].client_data = (void *)1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102757D0
// Name: prepare_range_limit_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_range_limit_table(jpeg_common_struct *cinfo)
{
  int v1; // eax
  int v2; // esi
  int i; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1408);
  v2 = v1 + 256;
  cinfo[12].err = (jpeg_error_mgr *)(v1 + 256);
  memset(dst: v1, value: nullptr, count: 0x100u);
  for ( i = 0; i <= 255; ++i )
    *(_BYTE *)(i + v2) = i;
  memset(dst: v2 + 256, value: (unsigned __int8 *)0xFF, count: 0x180u);
  memset(dst: v2 + 640, value: nullptr, count: 0x180u);
  qmemcpy((void *)(v2 + 1024), cinfo[12].err, 0x80u);
}

//------------------------------------------------------------------------------
// Address: 0x10275860
// Name: master_selection
// Source: json
//------------------------------------------------------------------------------
void __usercall master_selection(jpeg_decompress_struct *cinfo@<esi>)
{
  jpeg_decomp_master *master; // edi
  unsigned __int8 quantize_colors; // al
  jpeg_progress_mgr *progress; // ecx
  int num_components; // eax
  jpeg_decompress_struct *v5; // [esp+0h] [ebp-10h]
  unsigned __int8 use_c_buffer; // [esp+Ch] [ebp-4h]

  master = cinfo->master;
  jpeg_calc_output_dimensions(cinfo: v5);
  prepare_range_limit_table(cinfo);
  master[1].prepare_for_output_pass = nullptr;
  LOBYTE(master[1].finish_output_pass) = use_merged_upsample(cinfo);
  *(_DWORD *)&master[1].is_dummy_pass = 0;
  master[2].prepare_for_output_pass = nullptr;
  quantize_colors = cinfo->quantize_colors;
  if ( quantize_colors == 0 || cinfo->buffered_image == 0 )
  {
    *(_WORD *)&cinfo->enable_1pass_quant = 0;
    cinfo->enable_2pass_quant = 0;
  }
  if ( quantize_colors != 0 )
  {
    if ( cinfo->raw_data_out != 0 )
    {
      cinfo->err->msg_code = 47;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
    }
    if ( cinfo->out_color_components == 3 )
    {
      if ( cinfo->colormap != nullptr )
      {
        cinfo->enable_external_quant = 1;
      }
      else if ( cinfo->two_pass_quantize != 0 )
      {
        cinfo->enable_2pass_quant = 1;
      }
      else
      {
        cinfo->enable_1pass_quant = 1;
      }
    }
    else
    {
      *(_WORD *)&cinfo->enable_1pass_quant = 1;
      cinfo->enable_2pass_quant = 0;
      cinfo->colormap = nullptr;
    }
    if ( cinfo->enable_1pass_quant != 0 )
    {
      jinit_1pass_quantizer(cinfo);
      *(_DWORD *)&master[1].is_dummy_pass = cinfo->cquantize;
    }
    if ( cinfo->enable_2pass_quant != 0 || cinfo->enable_external_quant != 0 )
    {
      jinit_2pass_quantizer(cinfo);
      master[2].prepare_for_output_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->cquantize;
    }
  }
  if ( cinfo->raw_data_out == 0 )
  {
    if ( LOBYTE(master[1].finish_output_pass) != 0 )
    {
      jinit_merged_upsampler(cinfo);
    }
    else
    {
      jinit_color_deconverter(cinfo);
      jinit_upsampler(cinfo);
    }
    jinit_d_post_controller(cinfo, need_full_buffer: cinfo->enable_2pass_quant);
  }
  jinit_inverse_dct(cinfo);
  if ( cinfo->arith_code != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  else if ( cinfo->progressive_mode != 0 )
  {
    jinit_phuff_decoder(cinfo);
  }
  else
  {
    jinit_huff_decoder(cinfo);
  }
  if ( cinfo->inputctl->has_multiple_scans != 0 || (use_c_buffer = 0, cinfo->buffered_image != 0) )
    use_c_buffer = 1;
  jinit_d_coef_controller(cinfo, need_full_buffer: use_c_buffer);
  if ( cinfo->raw_data_out == 0 )
    jinit_d_main_controller(cinfo, need_full_buffer: 0);
  cinfo->mem->realize_virt_arrays(a1: (jpeg_common_struct *)cinfo);
  cinfo->inputctl->start_input_pass(a1: cinfo);
  progress = cinfo->progress;
  if ( progress != nullptr && cinfo->buffered_image == 0 && cinfo->inputctl->has_multiple_scans != 0 )
  {
    num_components = cinfo->num_components;
    if ( cinfo->progressive_mode != 0 )
      num_components = 3 * num_components + 2;
    progress->pass_counter = 0;
    cinfo->progress->pass_limit = num_components * cinfo->total_iMCU_rows;
    cinfo->progress->completed_passes = 0;
    cinfo->progress->total_passes = (cinfo->enable_2pass_quant != 0) + 2;
    ++master[1].prepare_for_output_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275A30
// Name: prepare_for_output_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_output_pass(jpeg_decompress_struct *cinfo)
{
  jpeg_decomp_master *master; // edi
  jpeg_progress_mgr *progress; // eax

  master = cinfo->master;
  if ( master->is_dummy_pass != 0 )
  {
    master->is_dummy_pass = 0;
    cinfo->cquantize->start_pass(a1: cinfo, a2: 0);
    cinfo->post->start_pass(a1: cinfo, a2: JBUF_CRANK_DEST);
    cinfo->main->start_pass(a1: cinfo, a2: JBUF_CRANK_DEST);
  }
  else
  {
    if ( cinfo->quantize_colors != 0 && cinfo->colormap == nullptr )
    {
      if ( cinfo->two_pass_quantize != 0 && cinfo->enable_2pass_quant != 0 )
      {
        cinfo->cquantize = (jpeg_color_quantizer *)master[2].prepare_for_output_pass;
        master->is_dummy_pass = 1;
      }
      else if ( cinfo->enable_1pass_quant != 0 )
      {
        cinfo->cquantize = *(jpeg_color_quantizer **)&master[1].is_dummy_pass;
      }
      else
      {
        cinfo->err->msg_code = 46;
        cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
      }
    }
    cinfo->idct->start_pass(a1: cinfo);
    cinfo->coef->start_output_pass(a1: cinfo);
    if ( cinfo->raw_data_out == 0 )
    {
      if ( LOBYTE(master[1].finish_output_pass) == 0 )
        cinfo->cconvert->start_pass(a1: cinfo);
      cinfo->upsample->start_pass(a1: cinfo);
      if ( cinfo->quantize_colors != 0 )
        cinfo->cquantize->start_pass(a1: cinfo, a2: master->is_dummy_pass);
      cinfo->post->start_pass(a1: cinfo, a2: master->is_dummy_pass != 0 ? 3 : 0);
      cinfo->main->start_pass(a1: cinfo, a2: JBUF_PASS_THRU);
    }
  }
  progress = cinfo->progress;
  if ( progress != nullptr )
  {
    progress->completed_passes = (int)master[1].prepare_for_output_pass;
    cinfo->progress->total_passes = (int)master[1].prepare_for_output_pass + (master->is_dummy_pass != 0) + 1;
    if ( cinfo->buffered_image != 0 && cinfo->inputctl->eoi_reached == 0 )
      cinfo->progress->total_passes += (cinfo->enable_2pass_quant != 0) + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275B90
// Name: finish_output_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_output_pass(jpeg_decompress_struct *cinfo)
{
  jpeg_decomp_master *master; // esi

  master = cinfo->master;
  if ( cinfo->quantize_colors != 0 )
    cinfo->cquantize->finish_pass(a1: cinfo);
  ++master[1].prepare_for_output_pass;
}

//------------------------------------------------------------------------------
// Address: 0x10275BC0
// Name: _jinit_master_decompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_master_decompress(jpeg_common_struct *cinfo)
{
  jpeg_decomp_master *v1; // eax

  v1 = (jpeg_decomp_master *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 28);
  cinfo[16].err = (jpeg_error_mgr *)v1;
  v1->prepare_for_output_pass = prepare_for_output_pass;
  v1->finish_output_pass = finish_output_pass;
  v1->is_dummy_pass = 0;
  master_selection((jpeg_decompress_struct *)cinfo);
}

} // namespace client
