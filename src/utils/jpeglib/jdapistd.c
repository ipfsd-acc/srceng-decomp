// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdapistd.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009640
// Name: output_pass_setup
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall output_pass_setup@<al>(jpeg_decompress_struct *cinfo@<esi>)
{
  unsigned int *p_output_scanline; // edi
  unsigned int v2; // eax
  jpeg_progress_mgr *progress; // ecx
  unsigned int v4; // ebx

  if ( cinfo->global_state != 204 )
  {
    cinfo->master->prepare_for_output_pass(a1: cinfo);
    cinfo->output_scanline = 0;
    cinfo->global_state = 204;
  }
  if ( cinfo->master->is_dummy_pass != 0 )
  {
    p_output_scanline = &cinfo->output_scanline;
    while ( 1 )
    {
      v2 = *p_output_scanline;
      if ( *p_output_scanline < cinfo->output_height )
        break;
LABEL_10:
      cinfo->master->finish_output_pass(a1: cinfo);
      cinfo->master->prepare_for_output_pass(a1: cinfo);
      *p_output_scanline = 0;
      if ( cinfo->master->is_dummy_pass == 0 )
        goto LABEL_11;
    }
    while ( 1 )
    {
      progress = cinfo->progress;
      if ( progress != nullptr )
      {
        progress->pass_counter = v2;
        cinfo->progress->pass_limit = cinfo->output_height;
        cinfo->progress->progress_monitor(a1: (jpeg_common_struct *)cinfo);
      }
      v4 = *p_output_scanline;
      cinfo->main->process_data(a1: cinfo, a2: nullptr, a3: &cinfo->output_scanline, a4: 0);
      v2 = *p_output_scanline;
      if ( *p_output_scanline == v4 )
        return 0;
      if ( v2 >= cinfo->output_height )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_11:
    cinfo->global_state = (cinfo->raw_data_out != 0) + 205;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009710
// Name: _jpeg_read_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_read_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int max_lines)
{
  jpeg_decompress_struct *v3; // esi
  unsigned int output_scanline; // ecx
  unsigned int result; // eax
  jpeg_progress_mgr *progress; // eax
  jpeg_d_main_controller *main; // eax

  v3 = (jpeg_decompress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 205 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  output_scanline = v3->output_scanline;
  if ( output_scanline < v3->output_height )
  {
    progress = v3->progress;
    if ( progress != nullptr )
    {
      progress->pass_counter = output_scanline;
      v3->progress->pass_limit = v3->output_height;
      v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
    }
    main = v3->main;
    cinfo = 0;
    main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: max_lines);
    result = cinfo;
    v3->output_scanline += cinfo;
  }
  else
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100097B0
// Name: _jpeg_start_decompress
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_start_decompress(jpeg_decompress_struct *cinfo)
{
  int global_state; // eax
  jpeg_progress_mgr *progress; // eax
  int v4; // eax
  jpeg_progress_mgr *v5; // ecx
  jpeg_progress_mgr *v6; // eax

  if ( cinfo->global_state == 202 )
  {
    jinit_master_decompress(cinfo);
    if ( cinfo->buffered_image != 0 )
    {
      cinfo->global_state = 207;
      return 1;
    }
    cinfo->global_state = 203;
  }
  global_state = cinfo->global_state;
  if ( global_state == 203 )
  {
    if ( cinfo->inputctl->has_multiple_scans != 0 )
    {
      while ( 1 )
      {
        progress = cinfo->progress;
        if ( progress != nullptr )
          progress->progress_monitor(a1: (jpeg_common_struct *)cinfo);
        v4 = cinfo->inputctl->consume_input(a1: cinfo);
        if ( v4 == 0 )
          return 0;
        if ( v4 == 2 )
          goto LABEL_17;
        v5 = cinfo->progress;
        if ( v5 != nullptr && (v4 == 3 || v4 == 1) )
        {
          ++v5->pass_counter;
          v6 = cinfo->progress;
          if ( v5->pass_counter >= v6->pass_limit )
            v6->pass_limit += cinfo->total_iMCU_rows;
        }
      }
    }
    else
    {
LABEL_17:
      cinfo->output_scan_number = cinfo->input_scan_number;
      return output_pass_setup(cinfo);
    }
  }
  else
  {
    if ( global_state != 204 )
    {
      cinfo->err->msg_code = 20;
      cinfo->err->msg_parm.i[0] = cinfo->global_state;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
    }
    return output_pass_setup(cinfo);
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10271FE0
// Name: output_pass_setup
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall output_pass_setup@<al>(jpeg_decompress_struct *cinfo@<esi>)
{
  unsigned int *p_output_scanline; // edi
  unsigned int v2; // eax
  jpeg_progress_mgr *progress; // ecx
  unsigned int v4; // ebx

  if ( cinfo->global_state != 204 )
  {
    cinfo->master->prepare_for_output_pass(a1: cinfo);
    cinfo->output_scanline = 0;
    cinfo->global_state = 204;
  }
  if ( cinfo->master->is_dummy_pass != 0 )
  {
    p_output_scanline = &cinfo->output_scanline;
    while ( 1 )
    {
      v2 = *p_output_scanline;
      if ( *p_output_scanline < cinfo->output_height )
        break;
LABEL_10:
      cinfo->master->finish_output_pass(a1: cinfo);
      cinfo->master->prepare_for_output_pass(a1: cinfo);
      *p_output_scanline = 0;
      if ( cinfo->master->is_dummy_pass == 0 )
        goto LABEL_11;
    }
    while ( 1 )
    {
      progress = cinfo->progress;
      if ( progress != nullptr )
      {
        progress->pass_counter = v2;
        cinfo->progress->pass_limit = cinfo->output_height;
        cinfo->progress->progress_monitor(a1: (jpeg_common_struct *)cinfo);
      }
      v4 = *p_output_scanline;
      cinfo->main->process_data(a1: cinfo, a2: nullptr, a3: &cinfo->output_scanline, a4: 0);
      v2 = *p_output_scanline;
      if ( *p_output_scanline == v4 )
        return 0;
      if ( v2 >= cinfo->output_height )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_11:
    cinfo->global_state = (cinfo->raw_data_out != 0) + 205;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102720B0
// Name: _jpeg_read_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_read_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int max_lines)
{
  jpeg_decompress_struct *v3; // esi
  unsigned int output_scanline; // ecx
  unsigned int result; // eax
  jpeg_progress_mgr *progress; // eax
  jpeg_d_main_controller *main; // eax

  v3 = (jpeg_decompress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 205 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  output_scanline = v3->output_scanline;
  if ( output_scanline < v3->output_height )
  {
    progress = v3->progress;
    if ( progress != nullptr )
    {
      progress->pass_counter = output_scanline;
      v3->progress->pass_limit = v3->output_height;
      v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
    }
    main = v3->main;
    cinfo = 0;
    main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: max_lines);
    result = cinfo;
    v3->output_scanline += cinfo;
  }
  else
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10272150
// Name: _jpeg_start_decompress
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_start_decompress(jpeg_decompress_struct *cinfo)
{
  int global_state; // eax
  jpeg_progress_mgr *progress; // eax
  int v4; // eax
  jpeg_progress_mgr *v5; // ecx
  jpeg_progress_mgr *v6; // eax

  if ( cinfo->global_state == 202 )
  {
    jinit_master_decompress(cinfo);
    if ( cinfo->buffered_image != 0 )
    {
      cinfo->global_state = 207;
      return 1;
    }
    cinfo->global_state = 203;
  }
  global_state = cinfo->global_state;
  if ( global_state == 203 )
  {
    if ( cinfo->inputctl->has_multiple_scans != 0 )
    {
      while ( 1 )
      {
        progress = cinfo->progress;
        if ( progress != nullptr )
          progress->progress_monitor(a1: (jpeg_common_struct *)cinfo);
        v4 = cinfo->inputctl->consume_input(a1: cinfo);
        if ( v4 == 0 )
          return 0;
        if ( v4 == 2 )
          goto LABEL_17;
        v5 = cinfo->progress;
        if ( v5 != nullptr && (v4 == 3 || v4 == 1) )
        {
          ++v5->pass_counter;
          v6 = cinfo->progress;
          if ( v5->pass_counter >= v6->pass_limit )
            v6->pass_limit += cinfo->total_iMCU_rows;
        }
      }
    }
    else
    {
LABEL_17:
      cinfo->output_scan_number = cinfo->input_scan_number;
      return output_pass_setup(cinfo);
    }
  }
  else
  {
    if ( global_state != 204 )
    {
      cinfo->err->msg_code = 20;
      cinfo->err->msg_parm.i[0] = cinfo->global_state;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
    }
    return output_pass_setup(cinfo);
  }
}

} // namespace client
