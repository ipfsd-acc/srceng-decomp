// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdinput.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009A50
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *p_alloc_barray; // edi
  int v3; // eax
  int progress; // eax
  int client_data; // eax
  jpeg_component_info *mem; // eax
  int v7; // ebx
  unsigned int *p_width_in_blocks; // edi
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ecx

  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[8].err != (jpeg_error_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[8].err;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[1].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[11].progress = (jpeg_progress_mgr *)1;
  cinfo[11].client_data = (void *)1;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_alloc_barray = (int *)&cinfo[8].mem->alloc_barray;
    do
    {
      v3 = *(p_alloc_barray - 1);
      if ( v3 <= 0 || v3 > 4 || *p_alloc_barray <= 0 || *p_alloc_barray > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      progress = (int)cinfo[11].progress;
      if ( progress <= *(p_alloc_barray - 1) )
        progress = *(p_alloc_barray - 1);
      cinfo[11].progress = (jpeg_progress_mgr *)progress;
      client_data = (int)cinfo[11].client_data;
      if ( client_data <= *p_alloc_barray )
        client_data = *p_alloc_barray;
      ++v1;
      cinfo[11].client_data = (void *)client_data;
      p_alloc_barray += 21;
    }
    while ( v1 < (int)cinfo[1].client_data );
  }
  mem = (jpeg_component_info *)cinfo[8].mem;
  v7 = 0;
  *(_DWORD *)&cinfo[11].is_decompressor = 8;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_width_in_blocks = &mem->width_in_blocks;
    do
    {
      v9 = *(p_width_in_blocks - 5);
      p_width_in_blocks[2] = 8;
      v10 = jdiv_round_up(a: (int)cinfo[1].mem * v9, b: 8 * (int)cinfo[11].progress);
      v11 = *(p_width_in_blocks - 4);
      *p_width_in_blocks = v10;
      v12 = jdiv_round_up(a: (int)cinfo[1].progress * v11, b: 8 * (int)cinfo[11].client_data);
      v13 = *(p_width_in_blocks - 5);
      p_width_in_blocks[1] = v12;
      p_width_in_blocks[3] = jdiv_round_up(a: (int)cinfo[1].mem * v13, b: (int)cinfo[11].progress);
      p_width_in_blocks[4] = jdiv_round_up(
                               a: (int)cinfo[1].progress * *(p_width_in_blocks - 4),
                               b: (int)cinfo[11].client_data);
      *((_BYTE *)p_width_in_blocks + 20) = 1;
      p_width_in_blocks[12] = 0;
      ++v7;
      p_width_in_blocks += 21;
    }
    while ( v7 < (int)cinfo[1].client_data );
  }
  cinfo[11].global_state = jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[11].client_data);
  *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) = (int)cinfo[12].mem < (int)cinfo[1].client_data
                                                        || LOBYTE(cinfo[8].progress) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009C50
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int mem; // eax
  jpeg_component_info *progress; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  unsigned int width_in_blocks; // eax
  int v10; // edx
  int v11; // ebx
  unsigned int height_in_blocks; // eax
  int v13; // ebx
  unsigned int v14; // edi
  int v15; // edx
  int v16; // edi
  jpeg_component_info **p_progress; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  mem = (int)cinfo[12].mem;
  if ( mem == 1 )
  {
    progress = (jpeg_component_info *)cinfo[12].progress;
    cinfo[13].err = (jpeg_error_mgr *)progress->width_in_blocks;
    cinfo[13].mem = (jpeg_memory_mgr *)progress->height_in_blocks;
    v_samp_factor = progress->v_samp_factor;
    progress->MCU_sample_width = progress->DCT_scaled_size;
    v4 = progress->height_in_blocks % v_samp_factor;
    progress->MCU_width = 1;
    progress->MCU_height = 1;
    progress->MCU_blocks = 1;
    progress->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    progress->last_row_height = v4;
    cinfo[13].progress = (jpeg_progress_mgr *)1;
    cinfo[13].client_data = nullptr;
  }
  else
  {
    if ( mem <= 0 || mem > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[12].mem;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[11].progress);
    v6 = (unsigned int)cinfo[1].progress;
    cinfo[13].err = (jpeg_error_mgr *)v5;
    cinfo[13].mem = (jpeg_memory_mgr *)jdiv_round_up(a: v6, b: 8 * (int)cinfo[11].client_data);
    cinfo[13].progress = nullptr;
    ci = 0;
    if ( (int)cinfo[12].mem > 0 )
    {
      p_progress = (jpeg_component_info **)&cinfo[12].progress;
      do
      {
        v7 = *p_progress;
        h_samp_factor = (*p_progress)->h_samp_factor;
        width_in_blocks = (*p_progress)->width_in_blocks;
        v7->MCU_sample_width = h_samp_factor * (*p_progress)->DCT_scaled_size;
        v10 = width_in_blocks % h_samp_factor;
        v11 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v11;
        v13 = h_samp_factor * v11;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v13;
        if ( v10 == 0 )
          v10 = h_samp_factor;
        v14 = v7->v_samp_factor;
        v7->last_col_width = v10;
        v15 = height_in_blocks % v14;
        if ( height_in_blocks % v14 == 0 )
          v15 = v14;
        v7->last_row_height = v15;
        v16 = v13;
        if ( (int)cinfo[13].progress + v13 > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v13 > 0 )
        {
          do
          {
            --v16;
            *((_DWORD *)&cinfo[13].client_data + (int)cinfo[13].progress++) = ci;
          }
          while ( v16 > 0 );
        }
        ++p_progress;
        ++ci;
      }
      while ( ci < (int)cinfo[12].mem );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009DF0
// Name: latch_quant_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl latch_quant_tables(jpeg_common_struct *cinfo)
{
  unsigned int quant_tbl_no; // esi
  JQUANT_TBL *v3; // eax
  jpeg_component_info *compptr; // [esp+4h] [ebp-8h]
  int ci; // [esp+8h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+14h] [ebp+8h]

  ci = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    cinfoa = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      compptr = *cinfoa;
      if ( (*cinfoa)->quant_table == nullptr )
      {
        quant_tbl_no = (*cinfoa)->quant_tbl_no;
        if ( quant_tbl_no > 3 || *((_DWORD *)&cinfo[6].err + quant_tbl_no) == 0 )
        {
          cinfo->err->msg_code = 52;
          cinfo->err->msg_parm.i[0] = quant_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        v3 = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 130);
        qmemcpy(v3, *((const void **)&cinfo[6].err + quant_tbl_no), sizeof(JQUANT_TBL));
        compptr->quant_table = v3;
      }
      ++cinfoa;
      ++ci;
    }
    while ( ci < (int)cinfo[12].mem );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009EE0
// Name: consume_markers
// Source: json
//------------------------------------------------------------------------------
int __cdecl consume_markers(jpeg_decompress_struct *cinfo)
{
  jpeg_input_controller *inputctl; // edi
  int v3; // ebx
  int input_scan_number; // eax

  inputctl = cinfo->inputctl;
  if ( inputctl->eoi_reached != 0 )
    return 2;
  v3 = cinfo->marker->read_markers(a1: cinfo);
  if ( v3 == 1 )
  {
    if ( LOBYTE(inputctl[1].consume_input) != 0 )
    {
      initial_setup((jpeg_common_struct *)cinfo);
      LOBYTE(inputctl[1].consume_input) = 0;
      return 1;
    }
    if ( inputctl->has_multiple_scans == 0 )
    {
      cinfo->err->msg_code = 35;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
    }
    start_input_pass(cinfo);
  }
  else if ( v3 == 2 )
  {
    inputctl->eoi_reached = 1;
    if ( LOBYTE(inputctl[1].consume_input) != 0 )
    {
      if ( cinfo->marker->saw_SOF != 0 )
      {
        cinfo->err->msg_code = 59;
        cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
        return v3;
      }
    }
    else
    {
      input_scan_number = cinfo->input_scan_number;
      if ( cinfo->output_scan_number > input_scan_number )
      {
        cinfo->output_scan_number = input_scan_number;
        return v3;
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10009FA0
// Name: reset_input_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_input_controller(jpeg_common_struct *cinfo)
{
  jpeg_input_controller *v1; // eax

  v1 = *(jpeg_input_controller **)&cinfo[16].is_decompressor;
  v1->consume_input = consume_markers;
  *(_WORD *)&v1->has_multiple_scans = 0;
  LOBYTE(v1[1].consume_input) = 1;
  cinfo->err->reset_error_mgr(a1: cinfo);
  (*(void (__cdecl **)(jpeg_common_struct *))cinfo[16].global_state)(a1: cinfo);
  cinfo[5].global_state = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009FE0
// Name: finish_input_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_input_pass(jpeg_decompress_struct *cinfo)
{
  cinfo->inputctl->consume_input = consume_markers;
}

//------------------------------------------------------------------------------
// Address: 0x1000A000
// Name: _jinit_input_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_input_controller(jpeg_common_struct *cinfo)
{
  int v1; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 24);
  *(_DWORD *)&cinfo[16].is_decompressor = v1;
  *(_DWORD *)v1 = consume_markers;
  *(_DWORD *)(v1 + 4) = reset_input_controller;
  *(_DWORD *)(v1 + 8) = start_input_pass;
  *(_DWORD *)(v1 + 12) = finish_input_pass;
  *(_WORD *)(v1 + 16) = 0;
  *(_BYTE *)(v1 + 20) = 1;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102725B0
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *p_alloc_barray; // edi
  int v3; // eax
  int progress; // eax
  int client_data; // eax
  jpeg_component_info *mem; // eax
  int v7; // ebx
  unsigned int *p_width_in_blocks; // edi
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ecx

  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[8].err != (jpeg_error_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[8].err;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[1].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[11].progress = (jpeg_progress_mgr *)1;
  cinfo[11].client_data = (void *)1;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_alloc_barray = (int *)&cinfo[8].mem->alloc_barray;
    do
    {
      v3 = *(p_alloc_barray - 1);
      if ( v3 <= 0 || v3 > 4 || *p_alloc_barray <= 0 || *p_alloc_barray > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      progress = (int)cinfo[11].progress;
      if ( progress <= *(p_alloc_barray - 1) )
        progress = *(p_alloc_barray - 1);
      cinfo[11].progress = (jpeg_progress_mgr *)progress;
      client_data = (int)cinfo[11].client_data;
      if ( client_data <= *p_alloc_barray )
        client_data = *p_alloc_barray;
      ++v1;
      cinfo[11].client_data = (void *)client_data;
      p_alloc_barray += 21;
    }
    while ( v1 < (int)cinfo[1].client_data );
  }
  mem = (jpeg_component_info *)cinfo[8].mem;
  v7 = 0;
  *(_DWORD *)&cinfo[11].is_decompressor = 8;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_width_in_blocks = &mem->width_in_blocks;
    do
    {
      v9 = *(p_width_in_blocks - 5);
      p_width_in_blocks[2] = 8;
      v10 = jdiv_round_up(a: (int)cinfo[1].mem * v9, b: 8 * (int)cinfo[11].progress);
      v11 = *(p_width_in_blocks - 4);
      *p_width_in_blocks = v10;
      v12 = jdiv_round_up(a: (int)cinfo[1].progress * v11, b: 8 * (int)cinfo[11].client_data);
      v13 = *(p_width_in_blocks - 5);
      p_width_in_blocks[1] = v12;
      p_width_in_blocks[3] = jdiv_round_up(a: (int)cinfo[1].mem * v13, b: (int)cinfo[11].progress);
      p_width_in_blocks[4] = jdiv_round_up(
                               a: (int)cinfo[1].progress * *(p_width_in_blocks - 4),
                               b: (int)cinfo[11].client_data);
      *((_BYTE *)p_width_in_blocks + 20) = 1;
      p_width_in_blocks[12] = 0;
      ++v7;
      p_width_in_blocks += 21;
    }
    while ( v7 < (int)cinfo[1].client_data );
  }
  cinfo[11].global_state = jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[11].client_data);
  *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) = (int)cinfo[12].mem < (int)cinfo[1].client_data
                                                        || LOBYTE(cinfo[8].progress) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102727B0
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int mem; // eax
  jpeg_component_info *progress; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  unsigned int width_in_blocks; // eax
  int v10; // edx
  int v11; // ebx
  unsigned int height_in_blocks; // eax
  int v13; // ebx
  unsigned int v14; // edi
  int v15; // edx
  int v16; // edi
  jpeg_component_info **p_progress; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  mem = (int)cinfo[12].mem;
  if ( mem == 1 )
  {
    progress = (jpeg_component_info *)cinfo[12].progress;
    cinfo[13].err = (jpeg_error_mgr *)progress->width_in_blocks;
    cinfo[13].mem = (jpeg_memory_mgr *)progress->height_in_blocks;
    v_samp_factor = progress->v_samp_factor;
    progress->MCU_sample_width = progress->DCT_scaled_size;
    v4 = progress->height_in_blocks % v_samp_factor;
    progress->MCU_width = 1;
    progress->MCU_height = 1;
    progress->MCU_blocks = 1;
    progress->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    progress->last_row_height = v4;
    cinfo[13].progress = (jpeg_progress_mgr *)1;
    cinfo[13].client_data = nullptr;
  }
  else
  {
    if ( mem <= 0 || mem > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[12].mem;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[11].progress);
    v6 = (unsigned int)cinfo[1].progress;
    cinfo[13].err = (jpeg_error_mgr *)v5;
    cinfo[13].mem = (jpeg_memory_mgr *)jdiv_round_up(a: v6, b: 8 * (int)cinfo[11].client_data);
    cinfo[13].progress = nullptr;
    ci = 0;
    if ( (int)cinfo[12].mem > 0 )
    {
      p_progress = (jpeg_component_info **)&cinfo[12].progress;
      do
      {
        v7 = *p_progress;
        h_samp_factor = (*p_progress)->h_samp_factor;
        width_in_blocks = (*p_progress)->width_in_blocks;
        v7->MCU_sample_width = h_samp_factor * (*p_progress)->DCT_scaled_size;
        v10 = width_in_blocks % h_samp_factor;
        v11 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v11;
        v13 = h_samp_factor * v11;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v13;
        if ( v10 == 0 )
          v10 = h_samp_factor;
        v14 = v7->v_samp_factor;
        v7->last_col_width = v10;
        v15 = height_in_blocks % v14;
        if ( height_in_blocks % v14 == 0 )
          v15 = v14;
        v7->last_row_height = v15;
        v16 = v13;
        if ( (int)cinfo[13].progress + v13 > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v13 > 0 )
        {
          do
          {
            --v16;
            *((_DWORD *)&cinfo[13].client_data + (int)cinfo[13].progress++) = ci;
          }
          while ( v16 > 0 );
        }
        ++p_progress;
        ++ci;
      }
      while ( ci < (int)cinfo[12].mem );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272950
// Name: latch_quant_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl latch_quant_tables(jpeg_common_struct *cinfo)
{
  unsigned int quant_tbl_no; // esi
  JQUANT_TBL *v3; // eax
  jpeg_component_info *compptr; // [esp+4h] [ebp-8h]
  int ci; // [esp+8h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+14h] [ebp+8h]

  ci = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    cinfoa = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      compptr = *cinfoa;
      if ( (*cinfoa)->quant_table == nullptr )
      {
        quant_tbl_no = (*cinfoa)->quant_tbl_no;
        if ( quant_tbl_no > 3 || *((_DWORD *)&cinfo[6].err + quant_tbl_no) == 0 )
        {
          cinfo->err->msg_code = 52;
          cinfo->err->msg_parm.i[0] = quant_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        v3 = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 130);
        qmemcpy(v3, *((const void **)&cinfo[6].err + quant_tbl_no), sizeof(JQUANT_TBL));
        compptr->quant_table = v3;
      }
      ++cinfoa;
      ++ci;
    }
    while ( ci < (int)cinfo[12].mem );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272A40
// Name: consume_markers
// Source: json
//------------------------------------------------------------------------------
int __cdecl consume_markers(jpeg_decompress_struct *cinfo)
{
  jpeg_input_controller *inputctl; // edi
  int v3; // ebx
  int input_scan_number; // eax

  inputctl = cinfo->inputctl;
  if ( inputctl->eoi_reached != 0 )
    return 2;
  v3 = cinfo->marker->read_markers(a1: cinfo);
  if ( v3 == 1 )
  {
    if ( LOBYTE(inputctl[1].consume_input) != 0 )
    {
      initial_setup(cinfo);
      LOBYTE(inputctl[1].consume_input) = 0;
      return 1;
    }
    if ( inputctl->has_multiple_scans == 0 )
    {
      cinfo->err->msg_code = 35;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
    }
    start_input_pass(cinfo);
  }
  else if ( v3 == 2 )
  {
    inputctl->eoi_reached = 1;
    if ( LOBYTE(inputctl[1].consume_input) != 0 )
    {
      if ( cinfo->marker->saw_SOF != 0 )
      {
        cinfo->err->msg_code = 59;
        cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
        return v3;
      }
    }
    else
    {
      input_scan_number = cinfo->input_scan_number;
      if ( cinfo->output_scan_number > input_scan_number )
      {
        cinfo->output_scan_number = input_scan_number;
        return v3;
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10272B00
// Name: reset_input_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_input_controller(jpeg_common_struct *cinfo)
{
  jpeg_input_controller *v1; // eax

  v1 = *(jpeg_input_controller **)&cinfo[16].is_decompressor;
  v1->consume_input = consume_markers;
  *(_WORD *)&v1->has_multiple_scans = 0;
  LOBYTE(v1[1].consume_input) = 1;
  cinfo->err->reset_error_mgr(a1: cinfo);
  (*(void (__cdecl **)(jpeg_common_struct *))cinfo[16].global_state)(a1: cinfo);
  cinfo[5].global_state = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10272B40
// Name: finish_input_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_input_pass(jpeg_decompress_struct *cinfo)
{
  cinfo->inputctl->consume_input = consume_markers;
}

//------------------------------------------------------------------------------
// Address: 0x10272B60
// Name: _jinit_input_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_input_controller(jpeg_common_struct *cinfo)
{
  int v1; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 24);
  *(_DWORD *)&cinfo[16].is_decompressor = v1;
  *(_DWORD *)v1 = consume_markers;
  *(_DWORD *)(v1 + 4) = reset_input_controller;
  *(_DWORD *)(v1 + 8) = start_input_pass;
  *(_DWORD *)(v1 + 12) = finish_input_pass;
  *(_WORD *)(v1 + 16) = 0;
  *(_BYTE *)(v1 + 20) = 1;
}

} // namespace client
