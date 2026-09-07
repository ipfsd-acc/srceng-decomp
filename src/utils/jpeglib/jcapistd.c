// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcapistd.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102506C0
// Name: _jpeg_start_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_start_compress(jpeg_common_struct *cinfo, unsigned __int8 write_all_tables)
{
  bool v2; // zf

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( write_all_tables != 0 )
    jpeg_suppress_tables((jpeg_compress_struct *)cinfo, suppress: 0);
  cinfo->err->reset_error_mgr(a1: cinfo);
  cinfo[1].err->output_message(a1: cinfo);
  jinit_compress_master((jpeg_compress_struct *)cinfo);
  ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_small)(a1: cinfo);
  v2 = LOBYTE(cinfo[7].progress) == 0;
  *(_DWORD *)&cinfo[8].is_decompressor = 0;
  cinfo->global_state = !v2 + 101;
}

//------------------------------------------------------------------------------
// Address: 0x10250740
// Name: _jpeg_write_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_write_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int num_lines)
{
  jpeg_compress_struct *v3; // esi
  jpeg_progress_mgr *progress; // eax
  jpeg_comp_master *master; // eax
  int v6; // ecx
  jpeg_c_main_controller *main; // edx
  unsigned int result; // eax

  v3 = (jpeg_compress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 101 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  if ( v3->next_scanline >= v3->image_height )
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
  }
  progress = v3->progress;
  if ( progress != nullptr )
  {
    progress->pass_counter = v3->next_scanline;
    v3->progress->pass_limit = v3->image_height;
    v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
  }
  master = v3->master;
  if ( master->call_pass_startup != 0 )
    master->pass_startup(a1: v3);
  v6 = num_lines;
  main = v3->main;
  if ( num_lines > v3->image_height - v3->next_scanline )
    v6 = v3->image_height - v3->next_scanline;
  cinfo = 0;
  main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: v6);
  result = cinfo;
  v3->next_scanline += cinfo;
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102506E0
// Name: _jpeg_start_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_start_compress(jpeg_common_struct *cinfo, unsigned __int8 write_all_tables)
{
  bool v2; // zf

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( write_all_tables != 0 )
    jpeg_suppress_tables((jpeg_compress_struct *)cinfo, suppress: 0);
  cinfo->err->reset_error_mgr(a1: cinfo);
  cinfo[1].err->output_message(a1: cinfo);
  jinit_compress_master((jpeg_compress_struct *)cinfo);
  ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_small)(a1: cinfo);
  v2 = LOBYTE(cinfo[7].progress) == 0;
  *(_DWORD *)&cinfo[8].is_decompressor = 0;
  cinfo->global_state = !v2 + 101;
}

//------------------------------------------------------------------------------
// Address: 0x10250760
// Name: _jpeg_write_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_write_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int num_lines)
{
  jpeg_compress_struct *v3; // esi
  jpeg_progress_mgr *progress; // eax
  jpeg_comp_master *master; // eax
  int v6; // ecx
  jpeg_c_main_controller *main; // edx
  unsigned int result; // eax

  v3 = (jpeg_compress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 101 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  if ( v3->next_scanline >= v3->image_height )
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
  }
  progress = v3->progress;
  if ( progress != nullptr )
  {
    progress->pass_counter = v3->next_scanline;
    v3->progress->pass_limit = v3->image_height;
    v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
  }
  master = v3->master;
  if ( master->call_pass_startup != 0 )
    master->pass_startup(a1: v3);
  v6 = num_lines;
  main = v3->main;
  if ( num_lines > v3->image_height - v3->next_scanline )
    v6 = v3->image_height - v3->next_scanline;
  cinfo = 0;
  main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: v6);
  result = cinfo;
  v3->next_scanline += cinfo;
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00404BF0
// Name: _jpeg_start_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_start_compress(jpeg_common_struct *cinfo, unsigned __int8 write_all_tables)
{
  bool v2; // zf

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( write_all_tables != 0 )
    jpeg_suppress_tables((jpeg_compress_struct *)cinfo, suppress: 0);
  cinfo->err->reset_error_mgr(a1: cinfo);
  cinfo[1].err->output_message(a1: cinfo);
  jinit_compress_master((jpeg_compress_struct *)cinfo);
  ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_small)(a1: cinfo);
  v2 = LOBYTE(cinfo[7].progress) == 0;
  *(_DWORD *)&cinfo[8].is_decompressor = 0;
  cinfo->global_state = !v2 + 101;
}

//------------------------------------------------------------------------------
// Address: 0x00404C70
// Name: _jpeg_write_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_write_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int num_lines)
{
  jpeg_compress_struct *v3; // esi
  jpeg_progress_mgr *progress; // eax
  jpeg_comp_master *master; // eax
  int v6; // ecx
  jpeg_c_main_controller *main; // edx
  unsigned int result; // eax

  v3 = (jpeg_compress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 101 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  if ( v3->next_scanline >= v3->image_height )
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
  }
  progress = v3->progress;
  if ( progress != nullptr )
  {
    progress->pass_counter = v3->next_scanline;
    v3->progress->pass_limit = v3->image_height;
    v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
  }
  master = v3->master;
  if ( master->call_pass_startup != 0 )
    master->pass_startup(a1: v3);
  v6 = num_lines;
  main = v3->main;
  if ( num_lines > v3->image_height - v3->next_scanline )
    v6 = v3->image_height - v3->next_scanline;
  cinfo = 0;
  main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: v6);
  result = cinfo;
  v3->next_scanline += cinfo;
  return result;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042DF00
// Name: _jpeg_start_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_start_compress(jpeg_common_struct *cinfo, unsigned __int8 write_all_tables)
{
  bool v2; // zf

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( write_all_tables != 0 )
    jpeg_suppress_tables((jpeg_compress_struct *)cinfo, suppress: 0);
  cinfo->err->reset_error_mgr(a1: cinfo);
  cinfo[1].err->output_message(a1: cinfo);
  jinit_compress_master((jpeg_compress_struct *)cinfo);
  ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_small)(a1: cinfo);
  v2 = LOBYTE(cinfo[7].progress) == 0;
  *(_DWORD *)&cinfo[8].is_decompressor = 0;
  cinfo->global_state = !v2 + 101;
}

//------------------------------------------------------------------------------
// Address: 0x0042DF80
// Name: _jpeg_write_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_write_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int num_lines)
{
  jpeg_compress_struct *v3; // esi
  jpeg_progress_mgr *progress; // eax
  jpeg_comp_master *master; // eax
  int v6; // ecx
  jpeg_c_main_controller *main; // edx
  unsigned int result; // eax

  v3 = (jpeg_compress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 101 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  if ( v3->next_scanline >= v3->image_height )
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
  }
  progress = v3->progress;
  if ( progress != nullptr )
  {
    progress->pass_counter = v3->next_scanline;
    v3->progress->pass_limit = v3->image_height;
    v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
  }
  master = v3->master;
  if ( master->call_pass_startup != 0 )
    master->pass_startup(a1: v3);
  v6 = num_lines;
  main = v3->main;
  if ( num_lines > v3->image_height - v3->next_scanline )
    v6 = v3->image_height - v3->next_scanline;
  cinfo = 0;
  main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: v6);
  result = cinfo;
  v3->next_scanline += cinfo;
  return result;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041AD00
// Name: _jpeg_start_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_start_compress(jpeg_common_struct *cinfo, unsigned __int8 write_all_tables)
{
  bool v2; // zf

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( write_all_tables != 0 )
    jpeg_suppress_tables((jpeg_compress_struct *)cinfo, suppress: 0);
  cinfo->err->reset_error_mgr(a1: cinfo);
  cinfo[1].err->output_message(a1: cinfo);
  jinit_compress_master((jpeg_compress_struct *)cinfo);
  ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_small)(a1: cinfo);
  v2 = LOBYTE(cinfo[7].progress) == 0;
  *(_DWORD *)&cinfo[8].is_decompressor = 0;
  cinfo->global_state = !v2 + 101;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD80
// Name: _jpeg_write_scanlines
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl jpeg_write_scanlines(unsigned int cinfo, unsigned __int8 **scanlines, unsigned int num_lines)
{
  jpeg_compress_struct *v3; // esi
  jpeg_progress_mgr *progress; // eax
  jpeg_comp_master *master; // eax
  int v6; // ecx
  jpeg_c_main_controller *main; // edx
  unsigned int result; // eax

  v3 = (jpeg_compress_struct *)cinfo;
  if ( *(_DWORD *)(cinfo + 20) != 101 )
  {
    *(_DWORD *)(*(_DWORD *)cinfo + 20) = 20;
    v3->err->msg_parm.i[0] = v3->global_state;
    v3->err->error_exit(a1: (jpeg_common_struct *)v3);
  }
  if ( v3->next_scanline >= v3->image_height )
  {
    v3->err->msg_code = 123;
    v3->err->emit_message(a1: (jpeg_common_struct *)v3, a2: -1);
  }
  progress = v3->progress;
  if ( progress != nullptr )
  {
    progress->pass_counter = v3->next_scanline;
    v3->progress->pass_limit = v3->image_height;
    v3->progress->progress_monitor(a1: (jpeg_common_struct *)v3);
  }
  master = v3->master;
  if ( master->call_pass_startup != 0 )
    master->pass_startup(a1: v3);
  v6 = num_lines;
  main = v3->main;
  if ( num_lines > v3->image_height - v3->next_scanline )
    v6 = v3->image_height - v3->next_scanline;
  cinfo = 0;
  main->process_data(a1: v3, a2: scanlines, a3: &cinfo, a4: v6);
  result = cinfo;
  v3->next_scanline += cinfo;
  return result;
}

} // namespace vxconsole_ps3
