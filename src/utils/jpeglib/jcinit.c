// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcinit.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102531B0
// Name: _jinit_compress_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_compress_master(jpeg_compress_struct *cinfo)
{
  unsigned __int8 v1; // al

  jinit_c_master_control(cinfo, transcode_only: 0);
  if ( cinfo->raw_data_in == 0 )
  {
    jinit_color_converter(cinfo);
    jinit_downsampler(cinfo);
    jinit_c_prep_controller(cinfo, need_full_buffer: 0);
  }
  jinit_forward_dct(cinfo);
  if ( cinfo->arith_code != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  else if ( cinfo->progressive_mode != 0 )
  {
    jinit_phuff_encoder(cinfo);
  }
  else
  {
    jinit_huff_encoder(cinfo);
  }
  v1 = cinfo->num_scans > 1 || cinfo->optimize_coding != 0;
  jinit_c_coef_controller(cinfo, need_full_buffer: v1);
  jinit_c_main_controller(cinfo, need_full_buffer: 0);
  jinit_marker_writer((jpeg_common_struct *)cinfo);
  cinfo->mem->realize_virt_arrays(a1: (jpeg_common_struct *)cinfo);
  cinfo->marker->write_file_header(a1: cinfo);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102531D0
// Name: _jinit_compress_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_compress_master(jpeg_compress_struct *cinfo)
{
  unsigned __int8 v1; // al

  jinit_c_master_control(cinfo, transcode_only: 0);
  if ( cinfo->raw_data_in == 0 )
  {
    jinit_color_converter(cinfo);
    jinit_downsampler(cinfo);
    jinit_c_prep_controller(cinfo, need_full_buffer: 0);
  }
  jinit_forward_dct(cinfo);
  if ( cinfo->arith_code != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  else if ( cinfo->progressive_mode != 0 )
  {
    jinit_phuff_encoder(cinfo);
  }
  else
  {
    jinit_huff_encoder(cinfo);
  }
  v1 = cinfo->num_scans > 1 || cinfo->optimize_coding != 0;
  jinit_c_coef_controller(cinfo, need_full_buffer: v1);
  jinit_c_main_controller(cinfo, need_full_buffer: 0);
  jinit_marker_writer((jpeg_common_struct *)cinfo);
  cinfo->mem->realize_virt_arrays(a1: (jpeg_common_struct *)cinfo);
  cinfo->marker->write_file_header(a1: cinfo);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x004076E0
// Name: _jinit_compress_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_compress_master(jpeg_compress_struct *cinfo)
{
  unsigned __int8 v1; // al

  jinit_c_master_control(cinfo, transcode_only: 0);
  if ( cinfo->raw_data_in == 0 )
  {
    jinit_color_converter(cinfo);
    jinit_downsampler(cinfo);
    jinit_c_prep_controller(cinfo, need_full_buffer: 0);
  }
  jinit_forward_dct(cinfo);
  if ( cinfo->arith_code != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  else if ( cinfo->progressive_mode != 0 )
  {
    jinit_phuff_encoder(cinfo);
  }
  else
  {
    jinit_huff_encoder(cinfo);
  }
  v1 = cinfo->num_scans > 1 || cinfo->optimize_coding != 0;
  jinit_c_coef_controller(cinfo, need_full_buffer: v1);
  jinit_c_main_controller(cinfo, need_full_buffer: 0);
  jinit_marker_writer((jpeg_common_struct *)cinfo);
  cinfo->mem->realize_virt_arrays(a1: (jpeg_common_struct *)cinfo);
  cinfo->marker->write_file_header(a1: cinfo);
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x004309F0
// Name: _jinit_compress_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_compress_master(jpeg_compress_struct *cinfo)
{
  unsigned __int8 v1; // al

  jinit_c_master_control(cinfo, transcode_only: 0);
  if ( cinfo->raw_data_in == 0 )
  {
    jinit_color_converter(cinfo);
    jinit_downsampler(cinfo);
    jinit_c_prep_controller(cinfo, need_full_buffer: 0);
  }
  jinit_forward_dct(cinfo);
  if ( cinfo->arith_code != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  else if ( cinfo->progressive_mode != 0 )
  {
    jinit_phuff_encoder(cinfo);
  }
  else
  {
    jinit_huff_encoder(cinfo);
  }
  v1 = cinfo->num_scans > 1 || cinfo->optimize_coding != 0;
  jinit_c_coef_controller(cinfo, need_full_buffer: v1);
  jinit_c_main_controller(cinfo, need_full_buffer: 0);
  jinit_marker_writer((jpeg_common_struct *)cinfo);
  cinfo->mem->realize_virt_arrays(a1: (jpeg_common_struct *)cinfo);
  cinfo->marker->write_file_header(a1: cinfo);
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041D7F0
// Name: _jinit_compress_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_compress_master(jpeg_compress_struct *cinfo)
{
  unsigned __int8 v1; // al

  jinit_c_master_control(cinfo, transcode_only: 0);
  if ( cinfo->raw_data_in == 0 )
  {
    jinit_color_converter(cinfo);
    jinit_downsampler(cinfo);
    jinit_c_prep_controller(cinfo, need_full_buffer: 0);
  }
  jinit_forward_dct(cinfo);
  if ( cinfo->arith_code != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  else if ( cinfo->progressive_mode != 0 )
  {
    jinit_phuff_encoder(cinfo);
  }
  else
  {
    jinit_huff_encoder(cinfo);
  }
  v1 = cinfo->num_scans > 1 || cinfo->optimize_coding != 0;
  jinit_c_coef_controller(cinfo, need_full_buffer: v1);
  jinit_c_main_controller(cinfo, need_full_buffer: 0);
  jinit_marker_writer((jpeg_common_struct *)cinfo);
  cinfo->mem->realize_virt_arrays(a1: (jpeg_common_struct *)cinfo);
  cinfo->marker->write_file_header(a1: cinfo);
}

} // namespace vxconsole_ps3
